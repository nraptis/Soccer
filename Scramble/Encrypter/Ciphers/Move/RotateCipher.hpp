#ifndef JELLY_ROTATE_CIPHER_HPP_
#define JELLY_ROTATE_CIPHER_HPP_

#include <cstddef>
#include <cstdint>
#include <cstring>

#include "Jelly.hpp"
#include "Crypt.hpp"

// Input shape: pLength must be 0 or a multiple of 16.

class RotateCipher final : public Crypt {
 public:
  explicit RotateCipher(std::int32_t pShift) : mShift(pShift) {}

  bool SealData(const std::uint8_t *pSource,
                std::uint8_t *pWorker,
                std::uint8_t *pDestination,
                std::size_t pLength,
                CipherErrorCode *pErrorCode) const override {
    (void)pWorker;
    return Apply(pSource, pDestination, pLength,
                 InverseShift(mShift, pLength), pErrorCode);
  }

  bool UnsealData(const std::uint8_t *pSource,
                  std::uint8_t *pWorker,
                  std::uint8_t *pDestination,
                  std::size_t pLength,
                  CipherErrorCode *pErrorCode) const override {
    (void)pWorker;
    return Apply(pSource, pDestination, pLength,
                 NormalizeShift(mShift, pLength), pErrorCode);
  }

 private:
  static constexpr std::size_t kLengthMultiple = 16u;

  static std::int32_t NormalizeShift(std::int32_t pShift,
                                     std::size_t pLength) {
    if (pLength == 0u || pShift == 0) {
      return 0;
    }

    std::int32_t aShift = pShift;
    const std::int32_t aLength = static_cast<std::int32_t>(pLength);
    if (aShift < 0) {
      aShift += aLength;
    }
    if (aShift >= aLength) {
      aShift -= aLength;
    }
    return aShift;
  }

  static std::int32_t InverseShift(std::int32_t pShift,
                                   std::size_t pLength) {
    const std::int32_t aRotation = NormalizeShift(pShift, pLength);
    if (aRotation == 0) {
      return 0;
    }
    return static_cast<std::int32_t>(pLength) - aRotation;
  }

  static bool Apply(const std::uint8_t *pSource,
                    std::uint8_t *pDestination,
                    std::size_t pLength,
                    std::int32_t pRotation,
                    CipherErrorCode *pErrorCode) {
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
    const std::size_t aRotation = static_cast<std::size_t>(pRotation);
    const std::size_t aFirstSpan = pLength - aRotation;
    std::memcpy(pDestination, pSource + aRotation, aFirstSpan);
    std::memcpy(pDestination + aFirstSpan, pSource, aRotation);
    return true;
  }

  std::int32_t mShift;
};

#endif  // JELLY_ROTATE_CIPHER_HPP_
