#ifndef JELLY_WEAVE_MASK_CIPHER_HPP_
#define JELLY_WEAVE_MASK_CIPHER_HPP_

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

#include "Jelly.hpp"
#include "Crypt.hpp"

// Input shape: pLength must be 0 or a multiple of 16; mask is a single byte.

class WeaveMaskCipher final : public Crypt {
 public:
  WeaveMaskCipher(std::uint8_t pMask,
                  std::size_t pCount,
                  std::size_t pFrontStride,
                  std::size_t pBackStride)
      : mMask(pMask),
        mCount(pCount),
        mFrontStride(pFrontStride),
        mBackStride(pBackStride) {}

  bool SealData(const std::uint8_t *pSource,
                std::uint8_t *pWorker,
                std::uint8_t *pDestination,
                std::size_t pLength,
                CipherErrorCode *pErrorCode) const override {
    (void)pWorker;
    return Apply(pSource, pDestination, pLength, pErrorCode);
  }

  bool UnsealData(const std::uint8_t *pSource,
                  std::uint8_t *pWorker,
                  std::uint8_t *pDestination,
                  std::size_t pLength,
                  CipherErrorCode *pErrorCode) const override {
    (void)pWorker;
    return Apply(pSource, pDestination, pLength, pErrorCode);
  }

 private:
  static constexpr std::size_t kLengthMultiple = 16u;

  bool Apply(const std::uint8_t *pSource,
             std::uint8_t *pDestination,
             std::size_t pLength,
             CipherErrorCode *pErrorCode) const {
    if (pLength == 0u) {
      SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
      return true;
    }
    if ((pLength % kLengthMultiple) != 0u) {
      SetCipherErrorCode(pErrorCode, CipherErrorCode::kInvalidLength);
      return false;
    }
    if (pSource == nullptr || pDestination == nullptr) {
      SetCipherErrorCode(pErrorCode, CipherErrorCode::kNullBuffer);
      return false;
    }
    if (pSource == pDestination) {
      SetCipherErrorCode(pErrorCode, CipherErrorCode::kAliasedBuffer);
      return false;
    }

    SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
    const std::uint8_t aAntimask = static_cast<std::uint8_t>(~mMask);
    const std::vector<std::size_t> &aMap = GetMap(pLength);

    for (std::size_t aIndex = 0u; aIndex < pLength; ++aIndex) {
      pDestination[aIndex] = static_cast<std::uint8_t>(
          (pSource[aIndex] & aAntimask) |
          (pSource[aMap[aIndex]] & mMask));
    }

    return true;
  }

  const std::vector<std::size_t> &GetMap(std::size_t pLength) const {
    if (mCachedMapLength != pLength) {
      mCachedMap = BuildMap(pLength, mCount, mFrontStride, mBackStride);
      mCachedMapLength = pLength;
    }
    return mCachedMap;
  }

  static std::size_t ClampPositiveCount(std::size_t pValue) {
    return pValue == 0u ? 1u : pValue;
  }

  static std::vector<std::size_t> BuildMap(std::size_t pLength,
                                           std::size_t pCount,
                                           std::size_t pFrontStride,
                                           std::size_t pBackStride) {
    std::vector<std::size_t> aMap(pLength);
    for (std::size_t aIndex = 0u; aIndex < pLength; ++aIndex) {
      aMap[aIndex] = aIndex;
    }
    if (pLength < 2u) {
      return aMap;
    }

    const std::size_t aCount = ClampPositiveCount(pCount);
    std::size_t aFront = 0u;
    std::size_t aBack = pLength - 1u;

    while (aFront < aBack) {
      std::size_t aSwaps = aCount;
      while (aSwaps > 0u && aFront < aBack) {
        std::swap(aMap[aFront], aMap[aBack]);
        --aSwaps;
        ++aFront;
        --aBack;
      }
      if (aFront >= aBack) {
        break;
      }
      std::size_t aSkips = pFrontStride;
      while (aSkips > 0u && aFront < aBack) {
        --aSkips;
        ++aFront;
      }
      if (aFront >= aBack) {
        break;
      }
      aSkips = pBackStride;
      while (aSkips > 0u && aFront < aBack) {
        --aSkips;
        --aBack;
      }
    }

    return aMap;
  }

  std::uint8_t mMask;
  std::size_t mCount;
  std::size_t mFrontStride;
  std::size_t mBackStride;
  mutable std::size_t mCachedMapLength = static_cast<std::size_t>(-1);
  mutable std::vector<std::size_t> mCachedMap;
};

#endif  // JELLY_WEAVE_MASK_CIPHER_HPP_
