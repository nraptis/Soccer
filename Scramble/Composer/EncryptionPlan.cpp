//
//  EncryptionPlan.cpp
//  Scramble
//
//  Created by nick on 8/4/26.
//

#include "EncryptionPlan.hpp"
#include "LaneCombinations.hpp"

EncryptionPlan EncryptionPlanTool::MakePlanWeak(std::uint64_t pLaneSelect,
                                                EncryptionPlanBudget pBudget,
                                                EncryptionStrength pStrength,
                                                CipherType *pShuffledCiphers,
                                                EncryptionPlanError *pError) {
    
    EncryptionPlan aResult;
    
    /*
    EncryptionStrength.kLow (Lane Budget = 3.25 through 4)
    L3: [kKeyConsumeSimple,    kMoverPrimary, kMoverAny]
    L2: [kKeyConsumeAny,       kMoverPrimary, kMoverAny]
    L1: [kKeyConsumeAny,       kMoverPrimary, kMoverAny]
    F3: [kKeyConsumeSimple,    kMoverPrimary, kMoverAny]
    */
    WeakLaneCombination aLaneCombinations = LaneCombinations::PickWeak(pLaneSelect);
    
    
    
    CipherType aMixTypeA = CipherType::kNone;
    CipherType aMixTypeB = CipherType::kNone;
    CipherType aMixTypeC = CipherType::kNone;
    CipherType aMixTypeD = CipherType::kNone;
    
    std::size_t aCursor = 0;
    
    while (aCursor < 256) {
        
        if (CipherTool::CountLanes(pShuffledCiphers[aCursor]) == 1) {
            
        }
        
        aCursor++;
    }
    
    
    
    
    return aResult;
};

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
        if ((static_cast<std::uint32_t>(aType) & aMask) != 0U) {
            if (IS_KEY_SIMPLE(aType)) {
                *pIndex = aIndex;
                *pError = EncryptionPlanError::kNone;
                return aType;
            }
        }
        aIndex += 1U;
    }
    aIndex = 0;
    while (aIndex < aStartIndex) {
        CipherType aType = pShuffledCiphers[aIndex];
        if ((static_cast<std::uint32_t>(aType) & aMask) != 0U) {
            if (IS_KEY_SIMPLE(aType)) {
                *pIndex = aIndex;
                *pError = EncryptionPlanError::kNone;
                return aType;
            }
        }
        aIndex += 1U;
    }
    
    *pError = EncryptionPlanError::kKeySimpleNotFound;
    return CipherType::kNone;
}


//static CipherType                   RingFetchKeyComplex(std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError);
//static CipherType                   RingFetchKeyAny(std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError);
