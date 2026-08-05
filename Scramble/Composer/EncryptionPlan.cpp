//
//  EncryptionPlan.cpp
//  Scramble
//
//  Created by nick on 8/4/26.
//

#include "EncryptionPlan.hpp"
#include "LaneCombinations.hpp"

EncryptionPlan EncryptionPlanTool::MakePlanWeak(std::uint64_t pLaneSelect,
                                                CipherType *pShuffledCiphers,
                                                EncryptionPlanError *pError) {
    EncryptionPlan aResult{};
    WeakLaneCombination aLaneCombination = LaneCombinations::PickWeak(pLaneSelect);
    std::size_t aCursor = 0;

    aResult.mCountL3 = 3;
    aResult.mCountL2 = 3;
    aResult.mCountL1 = 3;
    aResult.mCountF3 = 3;

    // Every non-Cascade key is currently classified as Simple. Using the Simple
    // fetcher for all four layers preserves the Weak rule that Cascades are excluded.
    aResult.mTypeL3[0] = RingFetchKeySimple(pShuffledCiphers, aLaneCombination.mL3[0], &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL2[0] = RingFetchKeySimple(pShuffledCiphers, aLaneCombination.mL2[0], &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL1[0] = RingFetchKeySimple(pShuffledCiphers, aLaneCombination.mL1[0], &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeF3[0] = RingFetchKeySimple(pShuffledCiphers, aLaneCombination.mF3[0], &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL3[1] = RingFetchMoverPrimaryRotation(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL2[1] = RingFetchMoverPrimaryRotation(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL1[1] = RingFetchMoverPrimaryRotation(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeF3[1] = RingFetchMoverPrimaryRotation(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL3[2] = RingFetchMoverNonRotationAny(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL2[2] = RingFetchMoverNonRotationAny(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeL1[2] = RingFetchMoverNonRotationAny(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    aResult.mTypeF3[2] = RingFetchMoverNonRotationAny(pShuffledCiphers, &aCursor, pError);
    if (*pError != EncryptionPlanError::kNone) { return aResult; }

    return aResult;
}

CipherType EncryptionPlanTool::RingFetchKeySimple(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError) {
    
    std::size_t aIndex = *pIndex;
    std::size_t aStartIndex = aIndex;
    
    std::uint32_t aMask = 0U;
    if (pLaneCount == 1) {
        aMask = CIPHER_MASK_LANE_COUNT_1;
    } else if (pLaneCount == 2) {
        aMask = CIPHER_MASK_LANE_COUNT_2;
    } else if (pLaneCount == 3) {
        aMask = CIPHER_MASK_LANE_COUNT_3;
    } else if (pLaneCount == 4) {
        aMask = CIPHER_MASK_LANE_COUNT_4;
    } else {
        *pError = EncryptionPlanError::kKeyInvalidLaneCount;
        return CipherType::kNone;
    }
    
    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (static_cast<std::uint32_t>(aType) & aMask) {
            if (IS_KEY_SIMPLE(aType)) {
                *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
                *pError = EncryptionPlanError::kNone;
                return aType;
            }
        }
        aIndex += 1U;
    }
    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (static_cast<std::uint32_t>(aType) & aMask) {
            if (IS_KEY_SIMPLE(aType)) {
                *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
                *pError = EncryptionPlanError::kNone;
                return aType;
            }
        }
        aIndex += 1U;
    }
    
    *pError = EncryptionPlanError::kKeySimpleNotFound;
    return CipherType::kNone;
}

CipherType EncryptionPlanTool::RingFetchKeyComplex(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError) {
    std::size_t aIndex = *pIndex;
    std::size_t aStartIndex = aIndex;

    std::uint32_t aMask = 0U;
    if (pLaneCount == 1) {
        aMask = CIPHER_MASK_LANE_COUNT_1;
    } else if (pLaneCount == 2) {
        aMask = CIPHER_MASK_LANE_COUNT_2;
    } else if (pLaneCount == 3) {
        aMask = CIPHER_MASK_LANE_COUNT_3;
    } else if (pLaneCount == 4) {
        aMask = CIPHER_MASK_LANE_COUNT_4;
    } else {
        *pError = EncryptionPlanError::kKeyInvalidLaneCount;
        return CipherType::kNone;
    }

    // Pass 1: Complex, cursor through the end.
    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((static_cast<std::uint32_t>(aType) & aMask) && IS_KEY_COMPLEX(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    // Pass 2: Complex, beginning through the cursor.
    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((static_cast<std::uint32_t>(aType) & aMask) && IS_KEY_COMPLEX(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    // Pass 3: Any key, cursor through the end.
    aIndex = aStartIndex;
    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((static_cast<std::uint32_t>(aType) & aMask) && IS_KEY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    // Pass 4: Any key, beginning through the cursor.
    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((static_cast<std::uint32_t>(aType) & aMask) && IS_KEY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    *pError = EncryptionPlanError::kKeyComplexNotFound;
    return CipherType::kNone;
}

CipherType EncryptionPlanTool::RingFetchKeyAny(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError) {
    std::size_t aIndex = *pIndex;
    std::size_t aStartIndex = aIndex;

    std::uint32_t aMask = 0U;
    if (pLaneCount == 1) {
        aMask = CIPHER_MASK_LANE_COUNT_1;
    } else if (pLaneCount == 2) {
        aMask = CIPHER_MASK_LANE_COUNT_2;
    } else if (pLaneCount == 3) {
        aMask = CIPHER_MASK_LANE_COUNT_3;
    } else if (pLaneCount == 4) {
        aMask = CIPHER_MASK_LANE_COUNT_4;
    } else {
        *pError = EncryptionPlanError::kKeyInvalidLaneCount;
        return CipherType::kNone;
    }

    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((static_cast<std::uint32_t>(aType) & aMask) && IS_KEY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((static_cast<std::uint32_t>(aType) & aMask) && IS_KEY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    *pError = EncryptionPlanError::kKeyAnyNotFound;
    return CipherType::kNone;
}


CipherType EncryptionPlanTool::RingFetchMoverPrimaryRotation(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError) {
    
    std::size_t aIndex = *pIndex;
    std::size_t aStartIndex = aIndex;
    
    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((aType == CipherType::kRotateMaskCipher) ||
            (aType == CipherType::kRotateCipher)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }
    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((aType == CipherType::kRotateMaskCipher) ||
            (aType == CipherType::kRotateCipher)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }
    
    *pError = EncryptionPlanError::kMoverPrimaryRotationNotFound;
    return CipherType::kNone;
}

CipherType EncryptionPlanTool::RingFetchMoverNonRotationAny(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError) {
    std::size_t aIndex = *pIndex;
    std::size_t aStartIndex = aIndex;

    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (IS_MOVER_NON_ROTATION(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (IS_MOVER_NON_ROTATION(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }

    *pError = EncryptionPlanError::kMoverNonRotationAnyNotFound;
    return CipherType::kNone;
}

CipherType EncryptionPlanTool::RingFetchMoverSecondaryOrPrimary(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError) {
    
    std::size_t aIndex = *pIndex;
    std::size_t aStartIndex = aIndex;
    
    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (IS_MOVER_ANY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }
    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (IS_MOVER_ANY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }
    
    *pError = EncryptionPlanError::kMoverSecondaryOrPrimaryNotFound;
    return CipherType::kNone;
}

CipherType EncryptionPlanTool::RingFetchMoverSecondaryOnly(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError) {
    
    std::size_t aIndex = *pIndex;
    std::size_t aStartIndex = aIndex;
    
    while (aIndex < SHUFFLED_CIPHERS_LENGTH) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (IS_MOVER_SECONDARY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }
    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if (IS_MOVER_SECONDARY(aType)) {
            *pIndex = (aIndex + 1U) % SHUFFLED_CIPHERS_LENGTH;
            *pError = EncryptionPlanError::kNone;
            return aType;
        }
        aIndex += 1U;
    }
    
    *pError = EncryptionPlanError::kMoverSecondaryOnlyNotFound;
    return CipherType::kNone;
}
