//
//  Cryptex.cpp
//  Scramble
//
//  Created by nick on 8/6/26.
//

#include "Cryptex.hpp"
#include "Jelly.hpp"

void Cryptex::AddCipherL3(Crypt *pCipher) {
    mLayerL3.AddCipher(pCipher);
}

void Cryptex::AddCipherL2(Crypt *pCipher) {
    mLayerL2.AddCipher(pCipher);
}

void Cryptex::AddCipherL1(Crypt *pCipher) {
    mLayerL1.AddCipher(pCipher);
}

void Cryptex::AddCipherF3(Crypt *pCipher) {
    mLayerF3.AddCipher(pCipher);
}

void Cryptex::Free() {
    mLayerL3.Free();
    mLayerL2.Free();
    mLayerL1.Free();
    mLayerF3.Free();
}

bool Cryptex::SealData(const std::uint8_t *pSource,
                       std::uint8_t *pWorkerA,
                       std::uint8_t *pWorkerB,
                       std::uint8_t *pDestination,
                       std::size_t pLength,
                       CipherErrorCode *pErrorCode) const {
    if (pLength == 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }
    if ((pLength % (SOCCER_BLOCK_GRANULARITY * 4U)) != 0U) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kInvalidLength);
        return false;
    }
    if ((pSource == nullptr) ||
        (pWorkerA == nullptr) ||
        (pWorkerB == nullptr) ||
        (pDestination == nullptr)) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNullBuffer);
        return false;
    }
    if ((pSource == pWorkerA) ||
        (pSource == pWorkerB) ||
        (pSource == pDestination) ||
        (pWorkerA == pWorkerB) ||
        (pWorkerA == pDestination) ||
        (pWorkerB == pDestination)) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kAliasedBuffer);
        return false;
    }

    // L3: one full-width lane.
    if (!mLayerL3.SealData(pSource,
                           pWorkerB,
                           pWorkerA,
                           pLength,
                           pErrorCode)) {
        return false;
    }

    // L2: two half-width lanes.
    const std::size_t aLengthL2 = pLength >> 1U;
    for (std::size_t aLaneIndex=0; aLaneIndex<2; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL2;
        if (!mLayerL2.SealData(pWorkerA + aOffset,
                               pDestination + aOffset,
                               pWorkerB + aOffset,
                               aLengthL2,
                               pErrorCode)) {
            return false;
        }
    }

    // L1: four quarter-width lanes.
    const std::size_t aLengthL1 = pLength >> 2U;
    for (std::size_t aLaneIndex=0; aLaneIndex<4; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL1;
        if (!mLayerL1.SealData(pWorkerB + aOffset,
                               pDestination + aOffset,
                               pWorkerA + aOffset,
                               aLengthL1,
                               pErrorCode)) {
            return false;
        }
    }

    // F3: one final full-width lane.
    if (!mLayerF3.SealData(pSource,
                           pWorkerB,
                           pWorkerA,
                           pLength,
                           pErrorCode)) {
        return false;
    }

    return true;
}

bool Cryptex::UnsealData(const std::uint8_t *pSource,
                         std::uint8_t *pWorkerA,
                         std::uint8_t *pWorkerB,
                         std::uint8_t *pDestination,
                         std::size_t pLength,
                         CipherErrorCode *pErrorCode) const {
    if (pLength == 0) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNone);
        return true;
    }
    if ((pLength % (SOCCER_BLOCK_GRANULARITY * 4U)) != 0U) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kInvalidLength);
        return false;
    }
    if ((pSource == nullptr) ||
        (pWorkerA == nullptr) ||
        (pWorkerB == nullptr) ||
        (pDestination == nullptr)) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kNullBuffer);
        return false;
    }
    if ((pSource == pWorkerA) ||
        (pSource == pWorkerB) ||
        (pSource == pDestination) ||
        (pWorkerA == pWorkerB) ||
        (pWorkerA == pDestination) ||
        (pWorkerB == pDestination)) {
        SetCipherErrorCode(pErrorCode, CipherErrorCode::kAliasedBuffer);
        return false;
    }

    // F3: undo the final full-width lane first.
    if (!mLayerF3.UnsealData(pSource,
                             pWorkerB,
                             pWorkerA,
                             pLength,
                             pErrorCode)) {
        return false;
    }

    // L1: undo the four quarter-width lanes.
    const std::size_t aLengthL1 = pLength >> 2U;
    for (std::size_t aLaneIndex=0; aLaneIndex<4; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL1;
        if (!mLayerL1.UnsealData(pWorkerA + aOffset,
                                 pDestination + aOffset,
                                 pWorkerB + aOffset,
                                 aLengthL1,
                                 pErrorCode)) {
            return false;
        }
    }

    // L2: undo the two half-width lanes.
    const std::size_t aLengthL2 = pLength >> 1U;
    for (std::size_t aLaneIndex=0; aLaneIndex<2; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL2;
        if (!mLayerL2.UnsealData(pWorkerB + aOffset,
                                 pDestination + aOffset,
                                 pWorkerA + aOffset,
                                 aLengthL2,
                                 pErrorCode)) {
            return false;
        }
    }

    // L3: undo the initial full-width lane last.
    if (!mLayerL3.UnsealData(pSource,
                             pWorkerB,
                             pWorkerA,
                             pLength,
                             pErrorCode)) {
        return false;
    }

    return true;
}
