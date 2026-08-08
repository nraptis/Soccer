//
//  Cryptex.cpp
//  Scramble
//
//  Created by nick on 8/6/26.
//

#include "Cryptex.hpp"
#include "Jelly.hpp"

void Cryptex::AddCipherL3A(Crypt *pCipher) {
    mLayerL3A.AddCipher(pCipher);
}

void Cryptex::AddCipherL2A(Crypt *pCipher) {
    mLayerL2A.AddCipher(pCipher);
}

void Cryptex::AddCipherL1A(Crypt *pCipher) {
    mLayerL1A.AddCipher(pCipher);
}

void Cryptex::AddCipherL3B(Crypt *pCipher) {
    mLayerL3B.AddCipher(pCipher);
}

void Cryptex::AddCipherL2B(Crypt *pCipher) {
    mLayerL2B.AddCipher(pCipher);
}

void Cryptex::AddCipherL1B(Crypt *pCipher) {
    mLayerL1B.AddCipher(pCipher);
}

void Cryptex::AddCipherL3C(Crypt *pCipher) {
    mLayerL3C.AddCipher(pCipher);
}

void Cryptex::Free() {
    mLayerL3A.Free();
    mLayerL2A.Free();
    mLayerL1A.Free();
    mLayerL3B.Free();
    mLayerL2B.Free();
    mLayerL1B.Free();
    mLayerL3C.Free();
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

    const std::size_t aLengthL2 = pLength >> 1U;
    const std::size_t aLengthL1 = pLength >> 2U;

    // L3A: one full-width lane.
    if (!mLayerL3A.SealData(pSource,
                            pWorkerB,
                            pWorkerA,
                            pLength,
                            pErrorCode)) {
        return false;
    }

    // L2A: two half-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<2; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL2;
        if (!mLayerL2A.SealData(pWorkerA + aOffset,
                                pDestination + aOffset,
                                pWorkerB + aOffset,
                                aLengthL2,
                                pErrorCode)) {
            return false;
        }
    }

    // L1A: four quarter-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<4; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL1;
        if (!mLayerL1A.SealData(pWorkerB + aOffset,
                                pDestination + aOffset,
                                pWorkerA + aOffset,
                                aLengthL1,
                                pErrorCode)) {
            return false;
        }
    }

    // L3B: one full-width lane.
    if (!mLayerL3B.SealData(pWorkerA,
                            pDestination,
                            pWorkerB,
                            pLength,
                            pErrorCode)) {
        return false;
    }

    // L2B: two half-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<2; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL2;
        if (!mLayerL2B.SealData(pWorkerB + aOffset,
                                pDestination + aOffset,
                                pWorkerA + aOffset,
                                aLengthL2,
                                pErrorCode)) {
            return false;
        }
    }

    // L1B: four quarter-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<4; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL1;
        if (!mLayerL1B.SealData(pWorkerA + aOffset,
                                pDestination + aOffset,
                                pWorkerB + aOffset,
                                aLengthL1,
                                pErrorCode)) {
            return false;
        }
    }

    // L3C: one final full-width lane.
    if (!mLayerL3C.SealData(pWorkerB,
                            pWorkerA,
                            pDestination,
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

    const std::size_t aLengthL2 = pLength >> 1U;
    const std::size_t aLengthL1 = pLength >> 2U;

    // L3C: undo the final full-width lane first.
    if (!mLayerL3C.UnsealData(pSource,
                              pWorkerA,
                              pWorkerB,
                              pLength,
                              pErrorCode)) {
        return false;
    }

    // L1B: undo the four quarter-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<4; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL1;
        if (!mLayerL1B.UnsealData(pWorkerB + aOffset,
                                  pDestination + aOffset,
                                  pWorkerA + aOffset,
                                  aLengthL1,
                                  pErrorCode)) {
            return false;
        }
    }

    // L2B: undo the two half-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<2; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL2;
        if (!mLayerL2B.UnsealData(pWorkerA + aOffset,
                                  pDestination + aOffset,
                                  pWorkerB + aOffset,
                                  aLengthL2,
                                  pErrorCode)) {
            return false;
        }
    }

    // L3B: undo the middle full-width lane.
    if (!mLayerL3B.UnsealData(pWorkerB,
                              pDestination,
                              pWorkerA,
                              pLength,
                              pErrorCode)) {
        return false;
    }

    // L1A: undo the first four quarter-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<4; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL1;
        if (!mLayerL1A.UnsealData(pWorkerA + aOffset,
                                  pDestination + aOffset,
                                  pWorkerB + aOffset,
                                  aLengthL1,
                                  pErrorCode)) {
            return false;
        }
    }

    // L2A: undo the first two half-width lanes.
    for (std::size_t aLaneIndex=0; aLaneIndex<2; aLaneIndex++) {
        const std::size_t aOffset = aLaneIndex * aLengthL2;
        if (!mLayerL2A.UnsealData(pWorkerB + aOffset,
                                  pDestination + aOffset,
                                  pWorkerA + aOffset,
                                  aLengthL2,
                                  pErrorCode)) {
            return false;
        }
    }

    // L3A: undo the initial full-width lane last.
    if (!mLayerL3A.UnsealData(pWorkerA,
                              pWorkerB,
                              pDestination,
                              pLength,
                              pErrorCode)) {
        return false;
    }

    return true;
}
