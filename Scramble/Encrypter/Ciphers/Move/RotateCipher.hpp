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
  explicit RotateCipher(std::size_t pShift) : mShift(pShift) {}

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

  static std::size_t NormalizeShift(std::size_t pShift,
                                    std::size_t pLength) {
    return pLength == 0u ? 0u : pShift % pLength;
  }

  static std::size_t InverseShift(std::size_t pShift,
                                  std::size_t pLength) {
    const std::size_t aRotation = NormalizeShift(pShift, pLength);
    if (aRotation == 0u) {
      return 0u;
    }
    return pLength - aRotation;
  }

  static bool Apply(const std::uint8_t *pSource,
                    std::uint8_t *pDestination,
                    std::size_t pLength,
                    std::size_t pRotation,
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
    const std::size_t aFirstSpan = pLength - pRotation;
    std::memcpy(pDestination, pSource + pRotation, aFirstSpan);
    std::memcpy(pDestination + aFirstSpan, pSource, pRotation);
    return true;
  }

  std::size_t mShift;
};

#endif  // JELLY_ROTATE_CIPHER_HPP_
