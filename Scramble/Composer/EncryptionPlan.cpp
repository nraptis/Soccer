//
//  EncryptionPlan.cpp
//  Scramble
//
//  Created by nick on 8/4/26.
//

#include "EncryptionPlan.hpp"
#include "LaneCombinations.hpp"

namespace {

template <typename Predicate>
CipherType RingFetch(CipherType *pShuffledCiphers,
                     std::size_t *pIndex,
                     CipherType pDefault,
                     Predicate pPredicate) {
    std::size_t aIndex = *pIndex % SHUFFLED_CIPHERS_LENGTH;

    for (std::size_t aCount=0U; aCount<SHUFFLED_CIPHERS_LENGTH; aCount++) {
        const CipherType aType = pShuffledCiphers[aIndex];
        if (pPredicate(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            return aType;
        }

        aIndex++;
        if (aIndex == SHUFFLED_CIPHERS_LENGTH) {
            aIndex = 0U;
        }
    }

    return pDefault;
}

template <typename Predicate>
CipherType RingFetchLane(CipherType *pShuffledCiphers,
                         std::uint32_t pLaneMask,
                         std::size_t *pIndex,
                         CipherType pDefault,
                         Predicate pPredicate) {
    std::size_t aIndex = *pIndex % SHUFFLED_CIPHERS_LENGTH;

    for (std::size_t aCount=0U; aCount<SHUFFLED_CIPHERS_LENGTH; aCount++) {
        const CipherType aType = pShuffledCiphers[aIndex];
        if (((static_cast<std::uint32_t>(aType) & pLaneMask) != 0U) &&
            pPredicate(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            return aType;
        }

        aIndex++;
        if (aIndex == SHUFFLED_CIPHERS_LENGTH) {
            aIndex = 0U;
        }
    }

    return pDefault;
}

} // namespace

EncryptionPlan EncryptionPlanTool::MakePlanWeak(std::uint64_t pLaneSelect,
                                                CipherType *pShuffledCiphers) {
    EncryptionPlan aResult{};
    const WeakLaneCombination aLaneCombination = LaneCombinations::PickWeak(pLaneSelect);
    std::size_t aCursor = 0U;

    aResult.mL3A.mCount = 4U;
    aResult.mL2A.mCount = 4U;
    aResult.mL1A.mCount = 4U;
    aResult.mL3B.mCount = 2U;
    aResult.mL2B.mCount = 1U;
    aResult.mL1B.mCount = 0U;
    aResult.mL3C.mCount = 1U;

    aResult.mL3A.mType[0] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[1] = RingFetchMuon(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[2] = RingFetchFermion(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[3] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3A[0], &aCursor);

    aResult.mL2A.mType[0] = RingFetchFermion(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[1] = RingFetchQuasiparticle(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[2] = RingFetchFermion(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[3] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL2A[0], &aCursor);

    aResult.mL1A.mType[0] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[1] = RingFetchNeutrino(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[2] = RingFetchFermion(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[3] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL1A[0], &aCursor);

    aResult.mL3B.mType[0] = RingFetchFermion(pShuffledCiphers, &aCursor);
    aResult.mL3B.mType[1] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3B[0], &aCursor);

    aResult.mL2B.mType[0] = RingFetchMuon(pShuffledCiphers, &aCursor);

    aResult.mL3C.mType[0] = RingFetchFermion(pShuffledCiphers, &aCursor);

    return aResult;
}

EncryptionPlan EncryptionPlanTool::MakePlanNormal(std::uint64_t pLaneSelect,
                                                  CipherType *pShuffledCiphers) {
    EncryptionPlan aResult{};
    const NormalLaneCombination aLaneCombination = LaneCombinations::PickNormal(pLaneSelect);
    std::size_t aCursor = 0U;

    aResult.mL3A.mCount = 3U;
    aResult.mL2A.mCount = 3U;
    aResult.mL1A.mCount = 2U;
    aResult.mL3B.mCount = 3U;
    aResult.mL2B.mCount = 2U;
    aResult.mL1B.mCount = 3U;
    aResult.mL3C.mCount = 2U;

    aResult.mL3A.mType[0] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[1] = RingFetchBoson(pShuffledCiphers, aLaneCombination.mL3A[0], &aCursor);
    aResult.mL3A.mType[2] = RingFetchFermion(pShuffledCiphers, &aCursor);

    aResult.mL2A.mType[0] = RingFetchMuon(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[1] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL2A[0], &aCursor);
    aResult.mL2A.mType[2] = RingFetchBaryon(pShuffledCiphers, &aCursor);

    aResult.mL1A.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL1A[0], &aCursor);
    aResult.mL1A.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);

    aResult.mL3B.mType[0] = RingFetchQuasiparticle(pShuffledCiphers, &aCursor);
    aResult.mL3B.mType[1] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3B[0], &aCursor);
    aResult.mL3B.mType[2] = RingFetchFermion(pShuffledCiphers, &aCursor);

    aResult.mL2B.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL2B[0], &aCursor);
    aResult.mL2B.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);

    aResult.mL1B.mType[0] = RingFetchNeutrino(pShuffledCiphers, &aCursor);
    aResult.mL1B.mType[1] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL1B[0], &aCursor);
    aResult.mL1B.mType[2] = RingFetchFermion(pShuffledCiphers, &aCursor);

    aResult.mL3C.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3C[0], &aCursor);
    aResult.mL3C.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);

    return aResult;
}

EncryptionPlan EncryptionPlanTool::MakePlanStrong(std::uint64_t pLaneSelect,
                                                  CipherType *pShuffledCiphers) {
    EncryptionPlan aResult{};
    const StrongLaneCombination aLaneCombination = LaneCombinations::PickStrong(pLaneSelect);
    std::size_t aCursor = 0U;

    aResult.mL3A.mCount = 4U;
    aResult.mL2A.mCount = 4U;
    aResult.mL1A.mCount = 4U;
    aResult.mL3B.mCount = 4U;
    aResult.mL2B.mCount = 4U;
    aResult.mL1B.mCount = 4U;
    aResult.mL3C.mCount = 3U;

    aResult.mL3A.mType[0] = RingFetchBoson(pShuffledCiphers, aLaneCombination.mL3A[0], &aCursor);
    aResult.mL3A.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[2] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3A[1], &aCursor);
    aResult.mL3A.mType[3] = RingFetchMuon(pShuffledCiphers, &aCursor);

    aResult.mL2A.mType[0] = RingFetchBoson(pShuffledCiphers, aLaneCombination.mL2A[0], &aCursor);
    aResult.mL2A.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[2] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL2A[1], &aCursor);
    aResult.mL2A.mType[3] = RingFetchQuasiparticle(pShuffledCiphers, &aCursor);

    aResult.mL1A.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL1A[0], &aCursor);
    aResult.mL1A.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[2] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL1A[1], &aCursor);
    aResult.mL1A.mType[3] = RingFetchNeutrino(pShuffledCiphers, &aCursor);

    aResult.mL3B.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3B[0], &aCursor);
    aResult.mL3B.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL3B.mType[2] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3B[1], &aCursor);
    aResult.mL3B.mType[3] = RingFetchMuon(pShuffledCiphers, &aCursor);

    aResult.mL2B.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL2B[0], &aCursor);
    aResult.mL2B.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL2B.mType[2] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL2B[1], &aCursor);
    aResult.mL2B.mType[3] = RingFetchBaryon(pShuffledCiphers, &aCursor);

    aResult.mL1B.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL1B[0], &aCursor);
    aResult.mL1B.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL1B.mType[2] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL1B[1], &aCursor);
    aResult.mL1B.mType[3] = RingFetchMuon(pShuffledCiphers, &aCursor);

    aResult.mL3C.mType[0] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3C[0], &aCursor);
    aResult.mL3C.mType[1] = RingFetchBaryon(pShuffledCiphers, &aCursor);
    aResult.mL3C.mType[2] = RingFetchLepton(pShuffledCiphers, aLaneCombination.mL3C[1], &aCursor);

    return aResult;
}

CipherType EncryptionPlanTool::RingFetchLepton(CipherType *pShuffledCiphers,
                                               std::uint8_t pLaneCount,
                                               std::size_t *pIndex) {
    std::uint32_t aLaneMask = CIPHER_MASK_LANE_COUNT_1;
    CipherType aDefault = CipherType::kPasswordXORCipher;

    if (pLaneCount == 2U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_2;
        aDefault = CipherType::kPasswordJumpXORCipher;
    } else if (pLaneCount == 3U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_3;
        aDefault = CipherType::kPepperJumpNoiseXORCipher;
    } else if (pLaneCount == 4U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_4;
        aDefault = CipherType::kPepperDualJumpNoiseXORCipher;
    }

    return RingFetchLane(pShuffledCiphers,
                         aLaneMask,
                         pIndex,
                         aDefault,
                         [](CipherType pType) { return IS_LEPTON(pType); });
}

CipherType EncryptionPlanTool::RingFetchBoson(CipherType *pShuffledCiphers,
                                              std::uint8_t pLaneCount,
                                              std::size_t *pIndex) {
    std::uint32_t aLaneMask = CIPHER_MASK_LANE_COUNT_1;
    CipherType aDefault = CipherType::kCascadeCipher;

    if (pLaneCount == 2U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_2;
        aDefault = CipherType::kCascadeJumpCipher;
    } else if (pLaneCount == 3U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_3;
        aDefault = CipherType::kPepperJumpNoiseXORCipher;
    } else if (pLaneCount == 4U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_4;
        aDefault = CipherType::kPepperDualJumpNoiseXORCipher;
    }

    return RingFetchLane(pShuffledCiphers,
                         aLaneMask,
                         pIndex,
                         aDefault,
                         [](CipherType pType) { return IS_BOSON(pType); });
}

CipherType EncryptionPlanTool::RingFetchHadron(CipherType *pShuffledCiphers,
                                               std::uint8_t pLaneCount,
                                               std::size_t *pIndex) {
    std::uint32_t aLaneMask = CIPHER_MASK_LANE_COUNT_1;
    CipherType aDefault = CipherType::kPasswordXORCipher;

    if (pLaneCount == 2U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_2;
        aDefault = CipherType::kPasswordJumpXORCipher;
    } else if (pLaneCount == 3U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_3;
        aDefault = CipherType::kPepperJumpNoiseXORCipher;
    } else if (pLaneCount == 4U) {
        aLaneMask = CIPHER_MASK_LANE_COUNT_4;
        aDefault = CipherType::kPepperDualJumpNoiseXORCipher;
    }

    return RingFetchLane(pShuffledCiphers,
                         aLaneMask,
                         pIndex,
                         aDefault,
                         [](CipherType pType) { return IS_HADRON(pType); });
}

CipherType EncryptionPlanTool::RingFetchBaryon(CipherType *pShuffledCiphers,
                                               std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRotateMaskCipher,
                     [](CipherType pType) { return IS_BARYON(pType); });
}

CipherType EncryptionPlanTool::RingFetchFermion(CipherType *pShuffledCiphers,
                                                std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRotateCipher,
                     [](CipherType pType) { return IS_FERMION(pType); });
}

CipherType EncryptionPlanTool::RingFetchMeson(CipherType *pShuffledCiphers,
                                              std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRotateCipher,
                     [](CipherType pType) { return IS_MESON(pType); });
}

CipherType EncryptionPlanTool::RingFetchMuon(CipherType *pShuffledCiphers,
                                             std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kReverseMaskCipher,
                     [](CipherType pType) { return IS_MUON(pType); });
}

CipherType EncryptionPlanTool::RingFetchQuasiparticle(CipherType *pShuffledCiphers,
                                                      std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRippleMaskBlockCipher64,
                     [](CipherType pType) { return IS_QUASIPARTICLE(pType); });
}

CipherType EncryptionPlanTool::RingFetchNeutrino(CipherType *pShuffledCiphers,
                                                 std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kReverseMaskCipher,
                     [](CipherType pType) { return IS_NEUTRINO(pType); });
}
