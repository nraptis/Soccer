#include "EncryptionLayer.hpp"
#include "Jelly.hpp"

#include <cstdint>
#include <cstring>

namespace {

bool ValidateNonEmptyInputs(const std::uint8_t* pSource,
                            const std::uint8_t* pScratch,
                            const std::uint8_t* pDestination) {
  if (pSource == nullptr || pScratch == nullptr || pDestination == nullptr) {
    return false;
  }
  if (pSource == pDestination || pSource == pScratch || pDestination == pScratch) {
    return false;
  }
  return true;
}

}  // namespace

void EncryptionLayer::AddCipher(std::unique_ptr<Crypt> pCipher) {
  if (pCipher) {
    mCiphers.push_back(std::move(pCipher));
  }
}

void EncryptionLayer::ClearCiphers() { mCiphers.clear(); }

std::size_t EncryptionLayer::CipherCount() const { return mCiphers.size(); }

bool EncryptionLayer::SealData(const std::uint8_t* pSource,
                               std::uint8_t* pScratch,
                               std::uint8_t* pDestination,
                               std::size_t pLength,
                               CipherErrorCode *pErrorCode) const {
    if (pLength == 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }
    if ((pLength % SOCCER_BLOCK_GRANULARITY) != 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kInvalidLength);
        return false;
    }
    if (pSource == nullptr || pScratch == nullptr || pDestination == nullptr) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNullBuffer);
        return false;
    }
    
    if (mCiphers.empty()) {
        if (pSource != pDestination) {
            std::memcpy(pDestination, pSource, pLength);
        }
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }
    
    if (!ValidateNonEmptyInputs(pSource, pScratch, pDestination)) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kAliasedBuffer);
        return false;
    }
    
    const std::uint8_t* aInput = pSource;
    std::uint8_t* aOutput =
    ((mCiphers.size() & 1u) == 0u) ? pScratch : pDestination;
    
    for (const std::unique_ptr<Crypt>& aCipher : mCiphers) {
        if (!aCipher) {
            SetCipherErrorCode(pErrorCode, CipherErrorCode::kNullCipher);
            return false;
        }
        if (!aCipher->SealData(aInput, pScratch, aOutput, pLength, pErrorCode)) {
            return false;
        }
        aInput = aOutput;
        aOutput = (aOutput == pDestination) ? pScratch : pDestination;
    }
    
    SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
    return true;
}

bool EncryptionLayer::UnsealData(const std::uint8_t* pSource,
                                 std::uint8_t* pScratch,
                                 std::uint8_t* pDestination,
                                 std::size_t pLength,
                                 CipherErrorCode *pErrorCode) const {
    if (pLength == 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }
    if ((pLength % SOCCER_BLOCK_GRANULARITY) != 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kInvalidLength);
        return false;
    }
    if (pSource == nullptr || pScratch == nullptr || pDestination == nullptr) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNullBuffer);
        return false;
    }
    
    if (mCiphers.empty()) {
        if (pSource != pDestination) {
            std::memcpy(pDestination, pSource, pLength);
        }
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }
    
    if (!ValidateNonEmptyInputs(pSource, pScratch, pDestination)) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kAliasedBuffer);
        return false;
    }
    
    const std::uint8_t* aInput = pSource;
    std::uint8_t* aOutput =
    ((mCiphers.size() & 1u) == 0u) ? pScratch : pDestination;
    
    for (auto aIt = mCiphers.rbegin(); aIt != mCiphers.rend(); ++aIt) {
        const std::unique_ptr<Crypt>& aCipher = *aIt;
        if (!aCipher) {
            SetCipherErrorCode(pErrorCode, CipherErrorCode::kNullCipher);
            return false;
        }
        if (!aCipher->UnsealData(aInput, pScratch, aOutput, pLength,
                                 pErrorCode)) {
            return false;
        }
        aInput = aOutput;
        aOutput = (aOutput == pDestination) ? pScratch : pDestination;
    }
    
    SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
    return true;
}

