//
//  GutCheckValidator.cpp
//  ScrambleTests
//
//  Created by nick on 8/9/26.
//

#include "GutCheckValidator.hpp"
#include <cmath>
#include <vector>
#include <unordered_set>

namespace {

std::size_t CountOnes(std::uint8_t aByte) {
    const std::size_t aResult = static_cast<std::size_t>(__builtin_popcount(static_cast<unsigned int>(aByte)));
    return aResult;
}

std::size_t BitDifference(std::uint8_t aByteA, std::uint8_t aByteB) {
    const std::uint8_t aDifferenceMap = aByteA ^ aByteB;
    const std::size_t aDifference = CountOnes(aDifferenceMap);
    return aDifference;
}

}

bool GutCheckValidator::Validate(const char *pTestName,
                                 EncryptionStrength pStrength,
                                 std::uint8_t *pPassword,
                                 std::size_t pPasswordByteLength,
                                 std::uint64_t pNonce) {
    
    static std::uint8_t aOriginal[SOCCER_BLOCK_SIZE];
    static std::uint8_t aEncryptedA[SOCCER_BLOCK_SIZE];
    static std::uint8_t aEncryptedB[SOCCER_BLOCK_SIZE];
    static std::uint8_t aDecrypted[SOCCER_BLOCK_SIZE];
    
    for (std::size_t aIndex=0; aIndex<SOCCER_BLOCK_SIZE; aIndex++) {
        aOriginal[aIndex] = Random::GetByte();
    }
    
    std::uint32_t aAckWordA = 0U;
    std::uint32_t aAckWordB = 0U;
    
    Soccer2::Zero();
    if (!Soccer2::AttemptSeed_Encrypt(pStrength,
                                      pPassword,
                                      pPasswordByteLength,
                                      pNonce,
                                      &aAckWordA)) {
        
        printf("%s: encryption seed failed.\n", pTestName);
        return false;
    }
    
    if (!ValidatePostSeed(pTestName, pStrength)) {
        return false;
    }

    if (!Soccer2::EncryptBlock(aOriginal, aEncryptedA)) {
        printf("%s: encryption failed.\n", pTestName);
        return false;
    }
    if (std::memcmp(aOriginal, aEncryptedA, SOCCER_BLOCK_SIZE) == 0) {
        printf("%s: encryption left the source data unchanged.\n", pTestName);
        return false;
    }

    Soccer2::Zero();
    if (!Soccer2::AttemptSeed_Decrypt(pStrength,
                                       pPassword,
                                       pPasswordByteLength,
                                       pNonce,
                                      aAckWordA)) {
        printf("%s: decryption seed failed.\n", pTestName);
        return false;
    }
    
    if (!ValidatePostSeed(pTestName, pStrength)) {
        return false;
    }

    if (!Soccer2::DecryptBlock(aEncryptedA, aDecrypted)) {
        printf("%s: decryption failed.\n", pTestName);
        return false;
    }
    if (std::memcmp(aOriginal, aDecrypted, SOCCER_BLOCK_SIZE) != 0) {
        printf("%s: decrypted data did not match the original source.\n", pTestName);
        return false;
    }
    
    
    Soccer2::Zero();
    if (!Soccer2::AttemptSeed_Encrypt(pStrength,
                                      pPassword,
                                      pPasswordByteLength,
                                      pNonce,
                                      &aAckWordB)) {
        
        printf("%s: repeat encryption seed failed.\n", pTestName);
        return false;
    }
    
    if (!Soccer2::EncryptBlock(aOriginal, aEncryptedB)) {
        printf("%s: repeat encryption failed.\n", pTestName);
        return false;
    }
    if (std::memcmp(aEncryptedA, aEncryptedB, SOCCER_BLOCK_SIZE) != 0) {
        printf("%s: repeat encryption did not reproduce the first ciphertext.\n", pTestName);
        return false;
    }
    
    if (aAckWordA != aAckWordB) {
        printf("%s: repeat encryption did not reproduce the same ack words {%ux and %ux}.\n", pTestName, aAckWordA, aAckWordB);
        return false;
    }
    
    return true;
}

bool GutCheckValidator::ValidatePostSeed(const char *pTestName,
                                         EncryptionStrength pStrength) {
    
    if (!ValidateMaterials(pTestName, pStrength)) {
        return false;
    }
    
    if (!ValidateIndex2048(pTestName)) {
        return false;
    }
    
    if (!ValidateMask(pTestName)) {
        return false;
    }
    
    if (!ValidateRotation(pTestName)) {
        return false;
    }
    
    return true;
}

bool GutCheckValidator::ValidateMaterials(const char *pTestName,
                                          EncryptionStrength pStrength) {
    
    std::size_t aExpectedCount = 8;
    if (pStrength == EncryptionStrength::kWeak) {
        aExpectedCount = 4;
    } else if (pStrength == EncryptionStrength::kStrong) {
        aExpectedCount = 16;
    }
    
    std::uint8_t *aMaterialsBase[16];
    aMaterialsBase[ 0] = Soccer2::mMaterialA;
    aMaterialsBase[ 1] = Soccer2::mMaterialB;
    aMaterialsBase[ 2] = Soccer2::mMaterialC;
    aMaterialsBase[ 3] = Soccer2::mMaterialD;
    aMaterialsBase[ 4] = Soccer2::mMaterialE;
    aMaterialsBase[ 5] = Soccer2::mMaterialF;
    aMaterialsBase[ 6] = Soccer2::mMaterialG;
    aMaterialsBase[ 7] = Soccer2::mMaterialH;
    aMaterialsBase[ 8] = Soccer2::mMaterialI;
    aMaterialsBase[ 9] = Soccer2::mMaterialJ;
    aMaterialsBase[10] = Soccer2::mMaterialK;
    aMaterialsBase[11] = Soccer2::mMaterialL;
    aMaterialsBase[12] = Soccer2::mMaterialM;
    aMaterialsBase[13] = Soccer2::mMaterialN;
    aMaterialsBase[14] = Soccer2::mMaterialO;
    aMaterialsBase[15] = Soccer2::mMaterialP;
    
    std::uint8_t *aMaterials[16];
    std::size_t aMaterialCount = 0;
    
    for (std::size_t aMaterialIndex=0; aMaterialIndex<16; aMaterialIndex++) {
        bool aIsAllZero = true;
        for (std::size_t aByteIndex=0; aByteIndex<SOCCER_BLOCK_SIZE; aByteIndex++) {
            if (aMaterialsBase[aMaterialIndex][aByteIndex] != 0) {
                aIsAllZero = false;
                break;
            }
        }
        if (aIsAllZero == false) {
            aMaterials[aMaterialCount++] = aMaterialsBase[aMaterialIndex];
        }
    }
    
    if (aMaterialCount != aExpectedCount) {
        printf("%s: non-zero material count mismatch: expected %zu, got %zu.\n",
               pTestName,
               aExpectedCount,
               aMaterialCount);
        return false;
    }
    
    const std::size_t aTotalBitCount = SOCCER_BLOCK_SIZE * 8U;
    const std::size_t aTotalByteCount = SOCCER_BLOCK_SIZE;
    
    for (std::size_t aIndexA=1; aIndexA<aMaterialCount; aIndexA++) {
        
        for (std::size_t aIndexB=0; aIndexB<aIndexA; aIndexB++) {
            
            GutCheckAvalancheScore aAvalanche = ScoreBuffers(aMaterials[aIndexA], aMaterials[aIndexB]);
            
            float aBitAvalanche = (float)aAvalanche.mDifferentBits / (float)aTotalBitCount;
            float aByteAvalanche = (float)aAvalanche.mDifferentBytes / (float)aTotalByteCount;
            
            if (std::fabs(aBitAvalanche - 0.5) > 0.1) {
                printf("%s: material lanes %zu and %zu failed bit diversity: "
                       "%zu/%zu bits differ (%.6f; expected 0.500000 +/- 0.100000), "
                       "%zu/%zu bytes differ (%.6f).\n",
                       pTestName,
                       aIndexA,
                       aIndexB,
                       aAvalanche.mDifferentBits,
                       aTotalBitCount,
                       aBitAvalanche,
                       aAvalanche.mDifferentBytes,
                       aTotalByteCount,
                       aByteAvalanche);
                return false;
            }
            
            if (std::fabs(aByteAvalanche - 0.95) > 0.05) {
                printf("%s: material lanes %zu and %zu failed byte diversity: "
                       "%zu/%zu bytes differ (%.6f; expected 0.950000 +/- 0.050000), "
                       "%zu/%zu bits differ (%.6f).\n",
                       pTestName,
                       aIndexA,
                       aIndexB,
                       aAvalanche.mDifferentBytes,
                       aTotalByteCount,
                       aByteAvalanche,
                       aAvalanche.mDifferentBits,
                       aTotalBitCount,
                       aBitAvalanche);
                return false;
            }
        }
    }
    
    return true;
}

bool GutCheckValidator::ValidateIndex2048(const char *pTestName) {
    
    std::unordered_set<std::size_t> aIndexSetA;
    std::unordered_set<std::size_t> aIndexSetB;
    
    for (std::size_t aIndex=0; aIndex<2048; aIndex++) {
        
        if (aIndexSetA.contains(Soccer2::mIndexListA[aIndex])) {
            printf("index list contained duplicate %zu (index list a)\n", Soccer2::mIndexListA[aIndex]);
            return false;
        }
        
        if (aIndexSetB.contains(Soccer2::mIndexListB[aIndex])) {
            printf("index list contained duplicate %zu (index list b)\n", Soccer2::mIndexListB[aIndex]);
            return false;
        }
        
        aIndexSetA.insert(Soccer2::mIndexListA[aIndex]);
        aIndexSetB.insert(Soccer2::mIndexListB[aIndex]);
    }
    
    bool aAllNormalA = true;
    bool aAllNormalB = true;
    for (std::size_t aIndex=0; aIndex<2048; aIndex++) {
        if (Soccer2::mIndexListA[aIndex] != aIndex) { aAllNormalA = false; }
        if (Soccer2::mIndexListB[aIndex] != aIndex) { aAllNormalB = false; }
    }
    
    if (aAllNormalA) {
        printf("index list was not shuffled (index list a)\n");
        return false;
    }
    
    if (aAllNormalB) {
        printf("index list was not shuffled (index list b)\n");
        return false;
    }
    
    for (std::size_t aIndex=0; aIndex<2048; aIndex++) {
        if (aIndexSetA.contains(aIndex) == false) {
            printf("index list missing item %zu (index list b)\n", aIndex);
            return false;
        }
    }
    
    for (std::size_t aIndex=0; aIndex<2048; aIndex++) {
        if (aIndexSetB.contains(aIndex) == false) {
            printf("index list missing item %zu (index list b)\n", aIndex);
            return false;
        }
    }
    
    return true;
}

bool GutCheckValidator::ValidateMask(const char *pTestName) {
    
    for (std::size_t aMaskIndex = 0; aMaskIndex < SoccerMaskBank::mMaskGridWidth; aMaskIndex++) {
        std::uint8_t aMask = Soccer2::mMasks[aMaskIndex];
        std::size_t aOnes = CountOnes(aMask);
        if (aOnes < 3) {
            printf("masks: expected min ones to be 3, got %zu", aOnes);
            return false;
        }
        if (aOnes > 5) {
            printf("masks: expected max ones to be 5, got %zu", aOnes);
            return false;
        }
    }
    
    
    std::size_t aMinDifference = 256;
    std::size_t aMaxDifference = 0;
    for (std::size_t aIndexA = 1; aIndexA < SoccerMaskBank::mMaskGridWidth; aIndexA++) {
        
        std::uint8_t aMaskA = Soccer2::mMasks[aIndexA];
        for (std::size_t aIndexB = 0U; aIndexB < aIndexA; aIndexB++) {
            
            std::uint8_t aMaskB = Soccer2::mMasks[aIndexB];
            const std::size_t aDifference = BitDifference(aMaskA, aMaskB);
            
            if (aDifference < aMinDifference) {
                aMinDifference = aDifference;
            }
            if (aDifference > aMaxDifference) {
                aMaxDifference = aDifference;
            }
        }
    }
    
    if (aMinDifference < 4) {
        printf("masks: expected min difference to be 4, got %zu", aMinDifference);
        return false;
    }
    
    if (aMaxDifference < 8) {
        printf("masks: expected min difference to be 8, got %zu", aMaxDifference);
        return false;
    }
    
    return true;
}

bool GutCheckValidator::ValidateRotation(const char *pTestName) {
    
    constexpr std::uint64_t kRotationFloorL1 = 1ULL;
    constexpr std::uint64_t kRotationFloorL2 = SOCCER_BLOCK_SIZE_L1 + 1ULL;
    constexpr std::uint64_t kRotationFloorL3 = SOCCER_BLOCK_SIZE_L2 + 1ULL;
    
    constexpr std::uint64_t kRotationRangeL1 = SOCCER_BLOCK_SIZE_L1 - 1ULL;
    constexpr std::uint64_t kRotationRangeL2 = SOCCER_BLOCK_SIZE_L1 - 1ULL;
    constexpr std::uint64_t kRotationRangeL3 = SOCCER_BLOCK_SIZE_L2 - 1ULL;
    
    std::int32_t aRangeMinL1 = (std::int32_t)kRotationFloorL1;
    std::int32_t aRangeMaxL1 = aRangeMinL1 + (std::int32_t)(kRotationRangeL1 - 1);
    
    std::int32_t aRangeMinL2 = (std::int32_t)kRotationFloorL2;
    std::int32_t aRangeMaxL2 = aRangeMinL2 + (std::int32_t)(kRotationRangeL2 - 1);
    
    std::int32_t aRangeMinL3 = (std::int32_t)kRotationFloorL3;
    std::int32_t aRangeMaxL3 = aRangeMinL3 + (std::int32_t)(kRotationRangeL3 - 1);
    
    for (std::size_t aIndex=0; aIndex<3; aIndex++) {
        if (Soccer2::mRotationsL1[aIndex] < aRangeMinL1) {
            printf("rotations: l1 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL1[aIndex], aRangeMinL1, aRangeMaxL1);
            return false;
        }
        if (Soccer2::mRotationsL1[aIndex] > aRangeMaxL1) {
            printf("rotations: l1 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL1[aIndex], aRangeMinL1, aRangeMaxL1);
            return false;
        }
    }
    
    for (std::size_t aIndex=0; aIndex<3; aIndex++) {
        if (Soccer2::mRotationsL2[aIndex] < aRangeMinL2) {
            printf("rotations: l2 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL2[aIndex], aRangeMinL2, aRangeMaxL2);
            return false;
        }
        if (Soccer2::mRotationsL2[aIndex] > aRangeMaxL2) {
            printf("rotations: l2 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL2[aIndex], aRangeMinL2, aRangeMaxL2);
            return false;
        }
    }
    
    for (std::size_t aIndex=0; aIndex<3; aIndex++) {
        if (Soccer2::mRotationsL3[aIndex] < aRangeMinL3) {
            printf("rotations: l3 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL3[aIndex], aRangeMinL3, aRangeMaxL3);
            return false;
        }
        if (Soccer2::mRotationsL3[aIndex] > aRangeMaxL3) {
            printf("rotations: l3 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL3[aIndex], aRangeMinL3, aRangeMaxL3);
            return false;
        }
    }
    
    return true;
}

GutCheckAvalancheScore GutCheckValidator::ScoreBuffers(const std::uint8_t *pBufferA,
                                                       const std::uint8_t *pBufferB) {
    
    GutCheckAvalancheScore aScore;
    for (std::size_t aIndex=0U; aIndex<SOCCER_BLOCK_SIZE; aIndex++) {
        const std::uint8_t aDifference =
        static_cast<std::uint8_t>(pBufferA[aIndex] ^ pBufferB[aIndex]);
        if (aDifference != 0U) {
            aScore.mDifferentBytes++;
            aScore.mDifferentBits += static_cast<std::size_t>(__builtin_popcount(static_cast<unsigned int>(aDifference)));
        }
    }
    
    return aScore;
}
