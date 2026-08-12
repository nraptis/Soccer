//
//  TenRunsDifferentMask_Tests.m
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

@interface TenRunsDifferentMask_Tests : XCTestCase

@end

@implementation TenRunsDifferentMask_Tests

- (void)test_30_runs_masks {
    
    constexpr char kPasswordCharacters[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789"
    "$#*()[]{}";
    constexpr std::size_t kPasswordCharacterCount = sizeof(kPasswordCharacters) - 1U;
    constexpr std::size_t kTrialCount = 10U;
    
    std::vector<EncryptionStrength> aStrengthList = { EncryptionStrength::kWeak, EncryptionStrength::kNormal, EncryptionStrength::kStrong};
    
    std::unordered_set<std::vector<std::uint8_t>, ByteListHash> aWeakSet;
    std::unordered_set<std::vector<std::uint8_t>, ByteListHash> aNormalSet;
    std::unordered_set<std::vector<std::uint8_t>, ByteListHash> aStrongSet;
    
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
            
            for (std::size_t aMaskIndex = 0; aMaskIndex < SoccerMaskBank::mMaskGridWidth; aMaskIndex++) {
                std::uint8_t aMask = Soccer2::mMasks[aMaskIndex];
                std::size_t aOnes = CountOnes(aMask);
                if (aOnes < 3) {
                    XCTFail("masks: expected min ones to be 3, got %zu", aOnes);
                    return;
                }
                if (aOnes > 5) {
                    XCTFail("masks: expected max ones to be 5, got %zu", aOnes);
                    return;
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
                XCTFail("masks: expected min difference to be 4, got %zu", aMinDifference);
                return;
            }
            
            if (aMaxDifference < 8) {
                XCTFail("masks: expected min difference to be 8, got %zu", aMaxDifference);
                return;
            }
            
            std::vector<std::uint8_t> aMaskList;
            for (std::size_t aMaskIndex = 0; aMaskIndex < SoccerMaskBank::mMaskGridWidth; aMaskIndex++) {
                std::uint8_t aMask = Soccer2::mMasks[aMaskIndex];
                aMaskList.push_back(aMask);
            }
            
            if (aStrength == EncryptionStrength::kWeak) {
                aWeakSet.insert(aMaskList);
            } else if (aStrength == EncryptionStrength::kStrong) {
                aStrongSet.insert(aMaskList);
            } else {
                aNormalSet.insert(aMaskList);
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
        XCTFail("%s: mask weak cross-list count %zu was below cutoff %zu (maximum %zu).\n",
                __func__, aWeakSet.size(), kWeakCutoff, kWeakMaximum);
        return;
    }
    if (aNormalSet.size() < kNormalCutoff) {
        XCTFail("%s: mask normal cross-list count %zu was below cutoff %zu (maximum %zu).\n",
                __func__, aNormalSet.size(), kNormalCutoff, kNormalMaximum);
        return;
    }
    if (aStrongSet.size() < kStrongCutoff) {
        XCTFail("%s: mask strong cross-list count %zu was below cutoff %zu (maximum %zu).\n",
                __func__, aStrongSet.size(), kStrongCutoff, kStrongMaximum);
        return;
    }
    
}

@end
