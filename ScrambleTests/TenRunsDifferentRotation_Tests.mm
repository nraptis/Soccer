//
//  TenRunsDifferentRotation_Tests.m
//  ScrambleTests
//
//  Created by nick on 8/10/26.
//

#import <XCTest/XCTest.h>

#include "Random.hpp"
#include "Soccer2.hpp"
#include "WorkSpaceTools.hpp"
#include "GutCheckValidator.hpp"

#include <cstdint>
#include <cstring>
#include <vector>
#include <unordered_set>

@interface TenRunsDifferentRotation_Tests : XCTestCase

@end

@implementation TenRunsDifferentRotation_Tests

- (void)test_30_runs_rotations {
    
    constexpr char kPasswordCharacters[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789"
    "$#*()[]{}";
    constexpr std::size_t kPasswordCharacterCount = sizeof(kPasswordCharacters) - 1U;
    constexpr std::size_t kTrialCount = 10U;
    
    std::vector<EncryptionStrength> aStrengthList = { EncryptionStrength::kWeak, EncryptionStrength::kNormal, EncryptionStrength::kStrong};
    
    std::unordered_set<std::vector<std::uint64_t>, LongLongHash> aWeakSet;
    std::unordered_set<std::vector<std::uint64_t>, LongLongHash> aNormalSet;
    std::unordered_set<std::vector<std::uint64_t>, LongLongHash> aStrongSet;
    
    for (std::size_t aTrial=0U; aTrial<kTrialCount; aTrial++) {
        std::uint8_t aPassword[32U];
        std::size_t aPasswordByteLength = 1 + Random::Get(4);
        for (std::size_t aIndex=0; aIndex<aPasswordByteLength; aIndex++) {
            const std::size_t aCharacterIndex = static_cast<std::size_t>(Random::Get(static_cast<int>(kPasswordCharacterCount)));
            aPassword[aIndex] = static_cast<std::uint8_t>(kPasswordCharacters[aCharacterIndex]);
        }
        std::uint64_t aNonce = Random::Get64();
        
        for (auto &aStrength : aStrengthList) {
            
            printf("Trial[%zu], Strength {%d}, Password {%.*s}, Nonce {0x%016llX}, Passed!!!\n",
                   aTrial,
                   (int)aStrength,
                   static_cast<int>(aPasswordByteLength),
                   reinterpret_cast<const char *>(aPassword),
                   static_cast<unsigned long long>(aNonce));
            
            static std::uint8_t aOriginal[SOCCER_BLOCK_SIZE];
            static std::uint8_t aEncrypted[SOCCER_BLOCK_SIZE];
            static std::uint8_t aDecrypted[SOCCER_BLOCK_SIZE];
            
            WorkSpaceTools::FillBytes(aOriginal, SOCCER_BLOCK_SIZE);
            
            std::uint32_t aAckWord = 0U;
            
            Soccer2::Zero();
            if (!Soccer2::AttemptSeed_Encrypt(aStrength,
                                              aPassword,
                                              aPasswordByteLength,
                                              aNonce,
                                              &aAckWord)) {
                XCTFail("%s: encryption seed failed.\n", __func__);
                return;
            }
            
            if (!Soccer2::EncryptBlock(aOriginal, aEncrypted)) {
                XCTFail("%s: encryption failed.\n", __func__);
                return;
            }
            if (std::memcmp(aOriginal, aEncrypted, SOCCER_BLOCK_SIZE) == 0) {
                XCTFail("%s: encryption left the source data unchanged.\n", __func__);
                return;
            }
            
            Soccer2::Zero();
            if (!Soccer2::AttemptSeed_Decrypt(aStrength,
                                              aPassword,
                                              aPasswordByteLength,
                                              aNonce,
                                              aAckWord)) {
                XCTFail("%s: decryption seed failed.\n", __func__);
                return;
            }
            
            if (!Soccer2::DecryptBlock(aEncrypted, aDecrypted)) {
                XCTFail("%s: decryption failed.\n", __func__);
                return;
            }
            if (std::memcmp(aOriginal, aDecrypted, SOCCER_BLOCK_SIZE) != 0) {
                XCTFail("%s: decrypted data did not match the original source.\n", __func__);
                return;
            }
            
            std::vector<std::uint64_t> aRotationList;
            aRotationList.push_back(Soccer2::mRotationsL1[0]);
            aRotationList.push_back(Soccer2::mRotationsL1[1]);
            aRotationList.push_back(Soccer2::mRotationsL1[2]);
            aRotationList.push_back(Soccer2::mRotationsL2[0]);
            aRotationList.push_back(Soccer2::mRotationsL2[1]);
            aRotationList.push_back(Soccer2::mRotationsL2[2]);
            aRotationList.push_back(Soccer2::mRotationsL3[0]);
            aRotationList.push_back(Soccer2::mRotationsL3[1]);
            aRotationList.push_back(Soccer2::mRotationsL3[2]);
            
            if (aStrength == EncryptionStrength::kWeak) {
                aWeakSet.insert(aRotationList);
            } else if (aStrength == EncryptionStrength::kStrong) {
                aStrongSet.insert(aRotationList);
            } else {
                aNormalSet.insert(aRotationList);
            }
            
            std::unordered_set<std::uint64_t> aRotationSet;
            aRotationSet.insert(Soccer2::mRotationsL1[0]);
            aRotationSet.insert(Soccer2::mRotationsL1[1]);
            aRotationSet.insert(Soccer2::mRotationsL1[2]);
            aRotationSet.insert(Soccer2::mRotationsL2[0]);
            aRotationSet.insert(Soccer2::mRotationsL2[1]);
            aRotationSet.insert(Soccer2::mRotationsL2[2]);
            aRotationSet.insert(Soccer2::mRotationsL3[0]);
            aRotationSet.insert(Soccer2::mRotationsL3[1]);
            aRotationSet.insert(Soccer2::mRotationsL3[2]);
            
            if (aRotationSet.size() < 6) {
                XCTFail("rotations: expected 9 nearly different rotations, got %zu", aRotationSet.size());
                return;
            }

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
                    XCTFail("rotations: l1 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL1[aIndex], aRangeMinL1, aRangeMaxL1);
                    return;
                }
                if (Soccer2::mRotationsL1[aIndex] > aRangeMaxL1) {
                    XCTFail("rotations: l1 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL1[aIndex], aRangeMinL1, aRangeMaxL1);
                    return;
                }
            }
            
            for (std::size_t aIndex=0; aIndex<3; aIndex++) {
                if (Soccer2::mRotationsL2[aIndex] < aRangeMinL2) {
                    XCTFail("rotations: l2 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL2[aIndex], aRangeMinL2, aRangeMaxL2);
                    return;
                }
                if (Soccer2::mRotationsL2[aIndex] > aRangeMaxL2) {
                    XCTFail("rotations: l2 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL2[aIndex], aRangeMinL2, aRangeMaxL2);
                    return;
                }
            }
            
            for (std::size_t aIndex=0; aIndex<3; aIndex++) {
                if (Soccer2::mRotationsL3[aIndex] < aRangeMinL3) {
                    XCTFail("rotations: l3 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL3[aIndex], aRangeMinL3, aRangeMaxL3);
                    return;
                }
                if (Soccer2::mRotationsL3[aIndex] > aRangeMaxL3) {
                    XCTFail("rotations: l3 rotation %d out of range [%d to %d]\n", Soccer2::mRotationsL3[aIndex], aRangeMinL3, aRangeMaxL3);
                    return;
                }
            }
        }
    }

    constexpr std::size_t kWeakMaximum = kTrialCount;
    constexpr std::size_t kNormalMaximum = kTrialCount;
    constexpr std::size_t kStrongMaximum = kTrialCount;

    constexpr std::size_t kWeakCutoff = (kWeakMaximum * 3U) / 4U;
    constexpr std::size_t kNormalCutoff = (kNormalMaximum * 3U) / 4U;
    constexpr std::size_t kStrongCutoff = (kStrongMaximum * 3U) / 4U;

    if (aWeakSet.size() < kWeakCutoff) {
        XCTFail("%s: rotation weak cross-list count %zu was below cutoff %zu (maximum %zu).\n",
                __func__, aWeakSet.size(), kWeakCutoff, kWeakMaximum);
        return;
    }
    if (aNormalSet.size() < kNormalCutoff) {
        XCTFail("%s: rotation normal cross-list count %zu was below cutoff %zu (maximum %zu).\n",
                __func__, aNormalSet.size(), kNormalCutoff, kNormalMaximum);
        return;
    }
    if (aStrongSet.size() < kStrongCutoff) {
        XCTFail("%s: rotation strong cross-list count %zu was below cutoff %zu (maximum %zu).\n",
                __func__, aStrongSet.size(), kStrongCutoff, kStrongMaximum);
        return;
    }
    
}

@end
