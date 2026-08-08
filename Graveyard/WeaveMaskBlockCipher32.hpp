#ifndef JELLY_WEAVE_MASK_BLOCK_CIPHER_32_HPP_
#define JELLY_WEAVE_MASK_BLOCK_CIPHER_32_HPP_

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

#include "Jelly.hpp"
#include "Crypt.hpp"

class WeaveMaskBlockCipher32 final : public Crypt {
 public:
  WeaveMaskBlockCipher32(std::uint8_t pMask,
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
  static constexpr std::size_t kBlockSize = 32u;
  static constexpr std::size_t kLengthMultiple = 32u;

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
    const std::size_t aBlockCount = pLength / kBlockSize;
    const std::vector<std::size_t> &aMap = GetMap(aBlockCount);

    for (std::size_t aBlock = 0u; aBlock < aBlockCount; ++aBlock) {
      const std::uint8_t *aBase = pSource + (aBlock * kBlockSize);
      const std::uint8_t *aMasked = pSource + (aMap[aBlock] * kBlockSize);
      std::uint8_t *aDestination = pDestination + (aBlock * kBlockSize);
#if JELLY_USE_NEON
      BlendMaskedNeon(aBase, aMasked, aDestination);
#elif JELLY_USE_SIMD
      BlendMaskedSimd(aBase, aMasked, aDestination);
#else
      BlendMaskedScalar(aBase, aMasked, aDestination);
#endif
    }

    return true;
  }

  const std::vector<std::size_t> &GetMap(std::size_t pBlockCount) const {
    if (mCachedMapBlockCount != pBlockCount) {
      mCachedMap = BuildMap(pBlockCount, mCount, mFrontStride, mBackStride);
      mCachedMapBlockCount = pBlockCount;
    }
    return mCachedMap;
  }

  void BlendMaskedScalar(const std::uint8_t *pBaseSource,
                         const std::uint8_t *pMaskedSource,
                         std::uint8_t *pDestination) const {
    const std::uint8_t aAntimask = static_cast<std::uint8_t>(~mMask);
    for (std::size_t aIndex = 0u; aIndex < kBlockSize; ++aIndex) {
      pDestination[aIndex] = static_cast<std::uint8_t>(
          (pBaseSource[aIndex] & aAntimask) |
          (pMaskedSource[aIndex] & mMask));
    }
  }

#if JELLY_USE_SIMD
  void BlendMaskedSimd(const std::uint8_t *pBaseSource,
                       const std::uint8_t *pMaskedSource,
                       std::uint8_t *pDestination) const {
#if defined(__AVX2__)
    const __m256i aMask = _mm256_set1_epi8(static_cast<char>(mMask));
    const __m256i aAntimask = _mm256_set1_epi8(
        static_cast<char>(static_cast<std::uint8_t>(~mMask)));
    const __m256i aBase =
        _mm256_loadu_si256(reinterpret_cast<const __m256i *>(pBaseSource));
    const __m256i aMasked =
        _mm256_loadu_si256(reinterpret_cast<const __m256i *>(pMaskedSource));
    const __m256i aResult =
        _mm256_or_si256(_mm256_and_si256(aBase, aAntimask),
                        _mm256_and_si256(aMasked, aMask));
    _mm256_storeu_si256(reinterpret_cast<__m256i *>(pDestination), aResult);
#else
    const __m128i aMask = _mm_set1_epi8(static_cast<char>(mMask));
    const __m128i aAntimask =
        _mm_set1_epi8(static_cast<char>(static_cast<std::uint8_t>(~mMask)));
    for (std::size_t aOffset = 0u; aOffset < kBlockSize; aOffset += 16u) {
      const __m128i aBase = _mm_loadu_si128(
          reinterpret_cast<const __m128i *>(pBaseSource + aOffset));
      const __m128i aMasked = _mm_loadu_si128(
          reinterpret_cast<const __m128i *>(pMaskedSource + aOffset));
      const __m128i aResult =
          _mm_or_si128(_mm_and_si128(aBase, aAntimask),
                       _mm_and_si128(aMasked, aMask));
      _mm_storeu_si128(reinterpret_cast<__m128i *>(pDestination + aOffset),
                       aResult);
    }
#endif
  }
#endif

#if JELLY_USE_NEON
  void BlendMaskedNeon(const std::uint8_t *pBaseSource,
                       const std::uint8_t *pMaskedSource,
                       std::uint8_t *pDestination) const {
    const uint8x16_t aMask = vdupq_n_u8(mMask);
    const uint8x16_t aAntimask = vmvnq_u8(aMask);
    for (std::size_t aOffset = 0u; aOffset < kBlockSize; aOffset += 16u) {
      const uint8x16_t aBase = vld1q_u8(pBaseSource + aOffset);
      const uint8x16_t aMasked = vld1q_u8(pMaskedSource + aOffset);
      const uint8x16_t aResult =
          vorrq_u8(vandq_u8(aBase, aAntimask), vandq_u8(aMasked, aMask));
      vst1q_u8(pDestination + aOffset, aResult);
    }
  }
#endif

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
  mutable std::size_t mCachedMapBlockCount = static_cast<std::size_t>(-1);
  mutable std::vector<std::size_t> mCachedMap;
};

#endif  // JELLY_WEAVE_MASK_BLOCK_CIPHER_32_HPP_
