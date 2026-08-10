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

    aResult.mL3A.mCount = 3U;
    aResult.mL3A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[0], &aCursor);
    aResult.mL3A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL2A.mCount = 3U;
    aResult.mL2A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL2[0], &aCursor);
    aResult.mL2A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL1A.mCount = 3U;
    aResult.mL1A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL1[0], &aCursor);
    aResult.mL1A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL3B.mCount = 3U;
    aResult.mL3B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL3B.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[1], &aCursor);
    aResult.mL3B.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL2B.mCount = 2U;
    aResult.mL2B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL2B.mType[1] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL1B.mCount = 2U;
    aResult.mL1B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL1B.mType[1] = RingFetchSecondaryMover(pShuffledCiphers, &aCursor);

    return aResult;
}

EncryptionPlan EncryptionPlanTool::MakePlanNormal(std::uint64_t pLaneSelect,
                                                  CipherType *pShuffledCiphers) {
    EncryptionPlan aResult{};
    const NormalLaneCombination aLaneCombination = LaneCombinations::PickNormal(pLaneSelect);
    std::size_t aCursor = 0U;

    aResult.mL3A.mCount = 4U;
    aResult.mL3A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[0], &aCursor);
    aResult.mL3A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[3] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[1], &aCursor);

    aResult.mL2A.mCount = 4U;
    aResult.mL2A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL2[0], &aCursor);
    aResult.mL2A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[3] = RingFetchSecondaryMover(pShuffledCiphers, &aCursor);

    aResult.mL1A.mCount = 4U;
    aResult.mL1A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL1[0], &aCursor);
    aResult.mL1A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[3] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL3B.mCount = 3U;
    aResult.mL3B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL3B.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[2], &aCursor);
    aResult.mL3B.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL2B.mCount = 3U;
    aResult.mL2B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL2B.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL2[1], &aCursor);
    aResult.mL2B.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL1B.mCount = 3U;
    aResult.mL1B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL1B.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL1[1], &aCursor);
    aResult.mL1B.mType[2] = RingFetchSecondaryMover(pShuffledCiphers, &aCursor);

    return aResult;
}

EncryptionPlan EncryptionPlanTool::MakePlanStrong(std::uint64_t pLaneSelect,
                                                  CipherType *pShuffledCiphers) {
    EncryptionPlan aResult{};
    const StrongLaneCombination aLaneCombination = LaneCombinations::PickStrong(pLaneSelect);
    std::size_t aCursor = 0U;

    aResult.mL3A.mCount = 4U;
    aResult.mL3A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[1] = RingFetchMutateComplex(pShuffledCiphers, aLaneCombination.mL3[0], &aCursor);
    aResult.mL3A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL3A.mType[3] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[1], &aCursor);

    aResult.mL2A.mCount = 4U;
    aResult.mL2A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL2[0], &aCursor);
    aResult.mL2A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL2A.mType[3] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL2[1], &aCursor);

    aResult.mL1A.mCount = 4U;
    aResult.mL1A.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL1[0], &aCursor);
    aResult.mL1A.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL1A.mType[3] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL1[1], &aCursor);

    aResult.mL3B.mCount = 4U;
    aResult.mL3B.mType[0] = RingFetchRotationMasked(pShuffledCiphers, &aCursor);
    aResult.mL3B.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[2], &aCursor);
    aResult.mL3B.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL3B.mType[3] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[3], &aCursor);

    aResult.mL2B.mCount = 3U;
    aResult.mL2B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL2B.mType[1] = RingFetchMutateComplex(pShuffledCiphers, aLaneCombination.mL2[2], &aCursor);
    aResult.mL2B.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL1B.mCount = 3U;
    aResult.mL1B.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL1B.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL1[2], &aCursor);
    aResult.mL1B.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL3C.mCount = 4U;
    aResult.mL3C.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL3C.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL3[4], &aCursor);
    aResult.mL3C.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);
    aResult.mL3C.mType[3] = RingFetchMutateComplex(pShuffledCiphers, aLaneCombination.mL3[5], &aCursor);

    aResult.mL2C.mCount = 3U;
    aResult.mL2C.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL2C.mType[1] = RingFetchMutateSimple(pShuffledCiphers, aLaneCombination.mL2[3], &aCursor);
    aResult.mL2C.mType[2] = RingFetchPrimaryMover(pShuffledCiphers, &aCursor);

    aResult.mL1C.mCount = 3U;
    aResult.mL1C.mType[0] = RingFetchRotation(pShuffledCiphers, &aCursor);
    aResult.mL1C.mType[1] = RingFetchMutateComplex(pShuffledCiphers, aLaneCombination.mL1[3], &aCursor);
    aResult.mL1C.mType[2] = RingFetchSecondaryMover(pShuffledCiphers, &aCursor);

    return aResult;
}

CipherType EncryptionPlanTool::RingFetchMutateSimple(CipherType *pShuffledCiphers,
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
                         [](CipherType pType) { return IS_MUTATE_SIMPLE(pType); });
}

CipherType EncryptionPlanTool::RingFetchMutateComplex(CipherType *pShuffledCiphers,
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
                         [](CipherType pType) { return IS_MUTATE_COMPLEX(pType); });
}

CipherType EncryptionPlanTool::RingFetchMutateAny(CipherType *pShuffledCiphers,
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
                         [](CipherType pType) { return IS_MUTATE_ANY(pType); });
}

CipherType EncryptionPlanTool::RingFetchRotationMasked(CipherType *pShuffledCiphers,
                                                       std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRotateMaskCipher,
                     [](CipherType pType) { return IS_ROTATION_MASKED(pType); });
}

CipherType EncryptionPlanTool::RingFetchRotation(CipherType *pShuffledCiphers,
                                                 std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRotateCipher,
                     [](CipherType pType) { return IS_ROTATION(pType); });
}

CipherType EncryptionPlanTool::RingFetchRotationAny(CipherType *pShuffledCiphers,
                                                    std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRotateCipher,
                     [](CipherType pType) { return IS_ROTATION_ANY(pType); });
}

CipherType EncryptionPlanTool::RingFetchPrimaryMover(CipherType *pShuffledCiphers,
                                                     std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kReverseMaskCipher,
                     [](CipherType pType) { return IS_PRIMARY_MOVER(pType); });
}

CipherType EncryptionPlanTool::RingFetchSecondaryMover(CipherType *pShuffledCiphers,
                                                       std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kRippleMaskBlockCipher64,
                     [](CipherType pType) { return IS_SECONDARY_MOVER(pType); });
}

CipherType EncryptionPlanTool::RingFetchMoverAny(CipherType *pShuffledCiphers,
                                                 std::size_t *pIndex) {
    return RingFetch(pShuffledCiphers,
                     pIndex,
                     CipherType::kReverseMaskCipher,
                     [](CipherType pType) { return IS_MOVER_ANY(pType); });
}
