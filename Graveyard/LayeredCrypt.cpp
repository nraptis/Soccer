#include "LayeredCrypt.hpp"

#include <cstdint>

#include "Jelly.hpp"

bool LayeredCrypt::SealData(const std::uint8_t* pSource,
                            std::uint8_t* pWorkerA,
                            std::uint8_t* pWorkerB,
                            std::uint8_t* pDestination,
                            std::size_t pLength,
                            CipherErrorCode *pErrorCode) const {
    if (pLength == 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }

    if (!mLayer3.SealData(pSource, pWorkerB, pWorkerA,
                          SOCCER_BLOCK_SIZE, pErrorCode)) {
        return false;
    }

    for (std::size_t aIndex = 0; aIndex < 2; ++aIndex) {
        const std::size_t aOffset = SOCCER_BLOCK_SIZE_L2 * aIndex;
        if (!mLayer2.SealData(pWorkerA + aOffset, pDestination + aOffset,
                              pWorkerB + aOffset, SOCCER_BLOCK_SIZE_L2,
                              pErrorCode)) {
            return false;
        }
    }

    for (std::size_t aIndex = 0; aIndex < 4; ++aIndex) {
        const std::size_t aOffset = SOCCER_BLOCK_SIZE_L1 * aIndex;
        if (!mLayer1.SealData(pWorkerB + aOffset,
                              pWorkerA + aOffset,
                              pDestination + aOffset, SOCCER_BLOCK_SIZE_L1,
                              pErrorCode)) {
            return false;
        }
    }

    SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
    return true;
}

bool LayeredCrypt::UnsealData(const std::uint8_t* pSource,
                              std::uint8_t* pWorkerA,
                              std::uint8_t* pWorkerB,
                              std::uint8_t* pDestination,
                              std::size_t pLength,
                              CipherErrorCode *pErrorCode) const {
    if (pLength == 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }

    for (std::size_t aIndex = 0; aIndex < 4; ++aIndex) {
        const std::size_t aOffset = SOCCER_BLOCK_SIZE_L1 * aIndex;
        if (!mLayer1.UnsealData(pSource + aOffset,
                                pWorkerB + aOffset,
                                pWorkerA + aOffset, SOCCER_BLOCK_SIZE_L1,
                                pErrorCode)) {
            return false;
        }
    }

    for (std::size_t aIndex = 0; aIndex < 2; ++aIndex) {
        const std::size_t aOffset = SOCCER_BLOCK_SIZE_L2 * aIndex;
        if (!mLayer2.UnsealData(pWorkerA + aOffset, pDestination + aOffset,
                                pWorkerB + aOffset, SOCCER_BLOCK_SIZE_L2,
                                pErrorCode)) {
            return false;
        }
    }

    if (!mLayer3.UnsealData(pWorkerB, pWorkerA, pDestination,
                            SOCCER_BLOCK_SIZE, pErrorCode)) {
        return false;
    }

    SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
    return true;
}
