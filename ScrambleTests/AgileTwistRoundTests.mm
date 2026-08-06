//
//  TwistBlockTests.m
//  ScrambleTests
//
//  Created by nick on 8/6/26.
//

#import <XCTest/XCTest.h>
#include "Soccer2.hpp"
#include "WorkSpaceTools.hpp"
#include "LaneTool.hpp"
#include "Soccer2.hpp"
#include "Random.hpp"
#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_set>

@interface AgileTwistRoundTests : XCTestCase

@end

@implementation AgileTwistRoundTests

- (void)test_TwistRound_Weak {

    std::size_t aLaneCount = 4;
    EncryptionStrength aEncryptionStrength = EncryptionStrength::kWeak;
    
    
    std::uint8_t aSources_A[16][S_BLOCK];
    std::uint8_t aCrosses_A_A[16][S_BLOCK];
    std::uint8_t aCrosses_B_A[16][S_BLOCK];
    std::uint8_t aCrosses_C_A[16][S_BLOCK];
    std::uint8_t aCrosses_D_A[16][S_BLOCK];
    
    std::uint8_t aSources_B[16][S_BLOCK];
    std::uint8_t aCrosses_A_B[16][S_BLOCK];
    std::uint8_t aCrosses_B_B[16][S_BLOCK];
    std::uint8_t aCrosses_C_B[16][S_BLOCK];
    std::uint8_t aCrosses_D_B[16][S_BLOCK];
    
    std::uint8_t aExpectation_A[16][S_BLOCK];
    std::uint8_t aExpectation_B[16][S_BLOCK];
    
    std::size_t aBlockIndexList[6];
    aBlockIndexList[0] = 0;
    aBlockIndexList[1] = 1;
    aBlockIndexList[2] = 14;
    aBlockIndexList[3] = 15;
    aBlockIndexList[4] = 30;
    aBlockIndexList[5] = 31;
    
    for (std::size_t aTrial=0; aTrial<16; aTrial++) {
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            std::memset(aSources_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_A_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_B_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_C_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_D_A[aLaneIndex], 0, S_BLOCK);
            
            WorkSpaceTools::FillBytes(aSources_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_A_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_B_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_C_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_D_B[aLaneIndex], S_BLOCK);
            
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = aEncryptionStrength;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            Soccer2::mSources[aLaneIndex] = aSources_A[aLaneIndex];
            Soccer2::mCross[0][aLaneIndex] = aCrosses_A_A[aLaneIndex];
            Soccer2::mCross[1][aLaneIndex] = aCrosses_B_A[aLaneIndex];
            Soccer2::mCross[2][aLaneIndex] = aCrosses_C_A[aLaneIndex];
            Soccer2::mCross[3][aLaneIndex] = aCrosses_D_A[aLaneIndex];
        }
        
        Soccer2::TwistRound(0);
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            const std::size_t aByteRichness = LaneTool::ByteRichness(Soccer2::mMaterials[aLaneIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_TwistRound_Weak: for zeros, at lane %zu, expected byte richess 512+, got %zu", aLaneIndex, aByteRichness);
                return;
            }
            std::memcpy(aExpectation_A[aLaneIndex], Soccer2::mMaterials[aLaneIndex], S_BLOCK);
        }
        
        for (std::size_t aFirstIndex=1; aFirstIndex<aLaneCount; aFirstIndex++) {
            for (std::size_t aSecondIndex=0; aSecondIndex<aFirstIndex; aSecondIndex++) {
                if (std::memcmp(Soccer2::mMaterials[aFirstIndex], Soccer2::mMaterials[aSecondIndex], S_BLOCK) == 0) {
                    XCTFail("test_TwistRound_Weak: lanes at %zu and %zu were identical for zeros, should not happen", aFirstIndex, aSecondIndex);
                    return;
                }
            }
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = aEncryptionStrength;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            Soccer2::mSources[aLaneIndex] = aSources_B[aLaneIndex];
            Soccer2::mCross[0][aLaneIndex] = aCrosses_A_B[aLaneIndex];
            Soccer2::mCross[1][aLaneIndex] = aCrosses_B_B[aLaneIndex];
            Soccer2::mCross[2][aLaneIndex] = aCrosses_C_B[aLaneIndex];
            Soccer2::mCross[3][aLaneIndex] = aCrosses_D_B[aLaneIndex];
        }
        
        Soccer2::TwistRound(0);
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            const std::size_t aByteRichness = LaneTool::ByteRichness(Soccer2::mMaterials[aLaneIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_TwistRound_Weak: for randoms, at lane %zu, expected byte richess 512+, got %zu", aLaneIndex, aByteRichness);
                return;
            }
            std::memcpy(aExpectation_B[aLaneIndex], Soccer2::mMaterials[aLaneIndex], S_BLOCK);
        }
        
        for (std::size_t aFirstIndex=1; aFirstIndex<aLaneCount; aFirstIndex++) {
            for (std::size_t aSecondIndex=0; aSecondIndex<aFirstIndex; aSecondIndex++) {
                if (std::memcmp(Soccer2::mMaterials[aFirstIndex], Soccer2::mMaterials[aSecondIndex], S_BLOCK) == 0) {
                    XCTFail("test_TwistRound_Weak: lanes at %zu and %zu were identical for randoms, should not happen", aFirstIndex, aSecondIndex);
                    return;
                }
            }
        }
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            if (std::memcmp(aExpectation_A[aLaneIndex], aExpectation_B[aLaneIndex], S_BLOCK) == 0) {
                XCTFail("test_TwistRound_Weak: for compare zeros and randoms, at lane %zu, we had identical output. impossible.", aLaneIndex);
                return;
            }
        }
        
        
        for (std::size_t aBlockIndexIndex=0; aBlockIndexIndex<6; aBlockIndexIndex++) {
            
            std::size_t aBlockIndex = aBlockIndexList[aBlockIndexIndex];
            
            Soccer2::Zero();
            Soccer2::mStrength = aEncryptionStrength;
            Soccer2::InitializeExpanders();
            Soccer2::InitializeWorkSpaces();
            Soccer2::InitializeMaterials();
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                Soccer2::mSources[aLaneIndex] = aSources_A[aLaneIndex];
                Soccer2::mCross[0][aLaneIndex] = aCrosses_A_A[aLaneIndex];
                Soccer2::mCross[1][aLaneIndex] = aCrosses_B_A[aLaneIndex];
                Soccer2::mCross[2][aLaneIndex] = aCrosses_C_A[aLaneIndex];
                Soccer2::mCross[3][aLaneIndex] = aCrosses_D_A[aLaneIndex];
            }
            
            Soccer2::TwistRound(aBlockIndex);
            
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                
                if (std::memcmp(&Soccer2::mMaterials[aLaneIndex][aBlockIndex * S_BLOCK],
                                aExpectation_A[aLaneIndex], S_BLOCK) != 0) {
                    XCTFail("test_TwistRound_Weak: at block %zu lane %zu, we did not get equal to expectation", aBlockIndex, aLaneIndex);
                    return;
                }
            }
            
            printf("test_TwistRound_Weak trial %zu finished block %zu (zero)\n", aTrial, aBlockIndex);
        }
        
        for (std::size_t aBlockIndexIndex=0; aBlockIndexIndex<6; aBlockIndexIndex++) {
            
            std::size_t aBlockIndex = aBlockIndexList[aBlockIndexIndex];
            
            Soccer2::Zero();
            Soccer2::mStrength = aEncryptionStrength;
            Soccer2::InitializeExpanders();
            Soccer2::InitializeWorkSpaces();
            Soccer2::InitializeMaterials();
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                Soccer2::mSources[aLaneIndex] = aSources_B[aLaneIndex];
                Soccer2::mCross[0][aLaneIndex] = aCrosses_A_B[aLaneIndex];
                Soccer2::mCross[1][aLaneIndex] = aCrosses_B_B[aLaneIndex];
                Soccer2::mCross[2][aLaneIndex] = aCrosses_C_B[aLaneIndex];
                Soccer2::mCross[3][aLaneIndex] = aCrosses_D_B[aLaneIndex];
            }
            
            Soccer2::TwistRound(aBlockIndex);
            
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                
                if (std::memcmp(&Soccer2::mMaterials[aLaneIndex][aBlockIndex * S_BLOCK],
                                aExpectation_B[aLaneIndex], S_BLOCK) != 0) {
                    XCTFail("test_TwistRound_Weak: at block %zu lane %zu, we did not get equal to expectation", aBlockIndex, aLaneIndex);
                    return;
                }
            }
            
            printf("test_TwistRound_Weak trial %zu finished block %zu (randoms)\n", aTrial, aBlockIndex);
        }
        
    }
}

- (void)test_TwistRound_Normal {

    std::size_t aLaneCount = 8;
    EncryptionStrength aEncryptionStrength = EncryptionStrength::kNormal;
    
    std::uint8_t aSources_A[16][S_BLOCK];
    std::uint8_t aCrosses_A_A[16][S_BLOCK];
    std::uint8_t aCrosses_B_A[16][S_BLOCK];
    std::uint8_t aCrosses_C_A[16][S_BLOCK];
    std::uint8_t aCrosses_D_A[16][S_BLOCK];
    
    std::uint8_t aSources_B[16][S_BLOCK];
    std::uint8_t aCrosses_A_B[16][S_BLOCK];
    std::uint8_t aCrosses_B_B[16][S_BLOCK];
    std::uint8_t aCrosses_C_B[16][S_BLOCK];
    std::uint8_t aCrosses_D_B[16][S_BLOCK];
    
    std::uint8_t aExpectation_A[16][S_BLOCK];
    std::uint8_t aExpectation_B[16][S_BLOCK];
    
    std::size_t aBlockIndexList[6];
    aBlockIndexList[0] = 0;
    aBlockIndexList[1] = 1;
    aBlockIndexList[2] = 14;
    aBlockIndexList[3] = 15;
    aBlockIndexList[4] = 30;
    aBlockIndexList[5] = 31;
    
    for (std::size_t aTrial=0; aTrial<12; aTrial++) {
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            std::memset(aSources_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_A_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_B_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_C_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_D_A[aLaneIndex], 0, S_BLOCK);
            
            WorkSpaceTools::FillBytes(aSources_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_A_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_B_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_C_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_D_B[aLaneIndex], S_BLOCK);
            
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = aEncryptionStrength;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            Soccer2::mSources[aLaneIndex] = aSources_A[aLaneIndex];
            Soccer2::mCross[0][aLaneIndex] = aCrosses_A_A[aLaneIndex];
            Soccer2::mCross[1][aLaneIndex] = aCrosses_B_A[aLaneIndex];
            Soccer2::mCross[2][aLaneIndex] = aCrosses_C_A[aLaneIndex];
            Soccer2::mCross[3][aLaneIndex] = aCrosses_D_A[aLaneIndex];
        }
        
        Soccer2::TwistRound(0);
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            const std::size_t aByteRichness = LaneTool::ByteRichness(Soccer2::mMaterials[aLaneIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_TwistRound_Normal: for zeros, at lane %zu, expected byte richess 512+, got %zu", aLaneIndex, aByteRichness);
                return;
            }
            std::memcpy(aExpectation_A[aLaneIndex], Soccer2::mMaterials[aLaneIndex], S_BLOCK);
        }
        
        for (std::size_t aFirstIndex=1; aFirstIndex<aLaneCount; aFirstIndex++) {
            for (std::size_t aSecondIndex=0; aSecondIndex<aFirstIndex; aSecondIndex++) {
                if (std::memcmp(Soccer2::mMaterials[aFirstIndex], Soccer2::mMaterials[aSecondIndex], S_BLOCK) == 0) {
                    XCTFail("test_TwistRound_Normal: lanes at %zu and %zu were identical for zeros, should not happen", aFirstIndex, aSecondIndex);
                    return;
                }
            }
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = aEncryptionStrength;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            Soccer2::mSources[aLaneIndex] = aSources_B[aLaneIndex];
            Soccer2::mCross[0][aLaneIndex] = aCrosses_A_B[aLaneIndex];
            Soccer2::mCross[1][aLaneIndex] = aCrosses_B_B[aLaneIndex];
            Soccer2::mCross[2][aLaneIndex] = aCrosses_C_B[aLaneIndex];
            Soccer2::mCross[3][aLaneIndex] = aCrosses_D_B[aLaneIndex];
        }
        
        Soccer2::TwistRound(0);
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            const std::size_t aByteRichness = LaneTool::ByteRichness(Soccer2::mMaterials[aLaneIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_TwistRound_Normal: for randoms, at lane %zu, expected byte richess 512+, got %zu", aLaneIndex, aByteRichness);
                return;
            }
            std::memcpy(aExpectation_B[aLaneIndex], Soccer2::mMaterials[aLaneIndex], S_BLOCK);
        }
        
        for (std::size_t aFirstIndex=1; aFirstIndex<aLaneCount; aFirstIndex++) {
            for (std::size_t aSecondIndex=0; aSecondIndex<aFirstIndex; aSecondIndex++) {
                if (std::memcmp(Soccer2::mMaterials[aFirstIndex], Soccer2::mMaterials[aSecondIndex], S_BLOCK) == 0) {
                    XCTFail("test_TwistRound_Normal: lanes at %zu and %zu were identical for randoms, should not happen", aFirstIndex, aSecondIndex);
                    return;
                }
            }
        }
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            if (std::memcmp(aExpectation_A[aLaneIndex], aExpectation_B[aLaneIndex], S_BLOCK) == 0) {
                XCTFail("test_TwistRound_Normal: for compare zeros and randoms, at lane %zu, we had identical output. impossible.", aLaneIndex);
                return;
            }
        }
        
        
        for (std::size_t aBlockIndexIndex=0; aBlockIndexIndex<6; aBlockIndexIndex++) {
            
            std::size_t aBlockIndex = aBlockIndexList[aBlockIndexIndex];
            
            Soccer2::Zero();
            Soccer2::mStrength = aEncryptionStrength;
            Soccer2::InitializeExpanders();
            Soccer2::InitializeWorkSpaces();
            Soccer2::InitializeMaterials();
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                Soccer2::mSources[aLaneIndex] = aSources_A[aLaneIndex];
                Soccer2::mCross[0][aLaneIndex] = aCrosses_A_A[aLaneIndex];
                Soccer2::mCross[1][aLaneIndex] = aCrosses_B_A[aLaneIndex];
                Soccer2::mCross[2][aLaneIndex] = aCrosses_C_A[aLaneIndex];
                Soccer2::mCross[3][aLaneIndex] = aCrosses_D_A[aLaneIndex];
            }
            
            Soccer2::TwistRound(aBlockIndex);
            
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                
                if (std::memcmp(&Soccer2::mMaterials[aLaneIndex][aBlockIndex * S_BLOCK],
                                aExpectation_A[aLaneIndex], S_BLOCK) != 0) {
                    XCTFail("test_TwistRound_Normal: at block %zu lane %zu, we did not get equal to expectation", aBlockIndex, aLaneIndex);
                    return;
                }
            }
            
            printf("test_TwistRound_Normal trial %zu finished block %zu (zero)\n", aTrial, aBlockIndex);
        }
        
        for (std::size_t aBlockIndexIndex=0; aBlockIndexIndex<6; aBlockIndexIndex++) {
            
            std::size_t aBlockIndex = aBlockIndexList[aBlockIndexIndex];
            
            Soccer2::Zero();
            Soccer2::mStrength = aEncryptionStrength;
            Soccer2::InitializeExpanders();
            Soccer2::InitializeWorkSpaces();
            Soccer2::InitializeMaterials();
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                Soccer2::mSources[aLaneIndex] = aSources_B[aLaneIndex];
                Soccer2::mCross[0][aLaneIndex] = aCrosses_A_B[aLaneIndex];
                Soccer2::mCross[1][aLaneIndex] = aCrosses_B_B[aLaneIndex];
                Soccer2::mCross[2][aLaneIndex] = aCrosses_C_B[aLaneIndex];
                Soccer2::mCross[3][aLaneIndex] = aCrosses_D_B[aLaneIndex];
            }
            
            Soccer2::TwistRound(aBlockIndex);
            
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                
                if (std::memcmp(&Soccer2::mMaterials[aLaneIndex][aBlockIndex * S_BLOCK],
                                aExpectation_B[aLaneIndex], S_BLOCK) != 0) {
                    XCTFail("test_TwistRound_Normal: at block %zu lane %zu, we did not get equal to expectation", aBlockIndex, aLaneIndex);
                    return;
                }
            }
            
            printf("test_TwistRound_Normal trial %zu finished block %zu (randoms)\n", aTrial, aBlockIndex);
        }
    }
}

- (void)test_TwistRound_Strong {

    std::size_t aLaneCount = 16;
    EncryptionStrength aEncryptionStrength = EncryptionStrength::kStrong;
    
    std::uint8_t aSources_A[16][S_BLOCK];
    std::uint8_t aCrosses_A_A[16][S_BLOCK];
    std::uint8_t aCrosses_B_A[16][S_BLOCK];
    std::uint8_t aCrosses_C_A[16][S_BLOCK];
    std::uint8_t aCrosses_D_A[16][S_BLOCK];
    
    std::uint8_t aSources_B[16][S_BLOCK];
    std::uint8_t aCrosses_A_B[16][S_BLOCK];
    std::uint8_t aCrosses_B_B[16][S_BLOCK];
    std::uint8_t aCrosses_C_B[16][S_BLOCK];
    std::uint8_t aCrosses_D_B[16][S_BLOCK];
    
    std::uint8_t aExpectation_A[16][S_BLOCK];
    std::uint8_t aExpectation_B[16][S_BLOCK];
    
    std::size_t aBlockIndexList[6];
    aBlockIndexList[0] = 0;
    aBlockIndexList[1] = 1;
    aBlockIndexList[2] = 14;
    aBlockIndexList[3] = 15;
    aBlockIndexList[4] = 30;
    aBlockIndexList[5] = 31;
    
    for (std::size_t aTrial=0; aTrial<8; aTrial++) {
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            std::memset(aSources_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_A_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_B_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_C_A[aLaneIndex], 0, S_BLOCK);
            std::memset(aCrosses_D_A[aLaneIndex], 0, S_BLOCK);
            
            WorkSpaceTools::FillBytes(aSources_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_A_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_B_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_C_B[aLaneIndex], S_BLOCK);
            WorkSpaceTools::FillBytes(aCrosses_D_B[aLaneIndex], S_BLOCK);
            
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = aEncryptionStrength;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            Soccer2::mSources[aLaneIndex] = aSources_A[aLaneIndex];
            Soccer2::mCross[0][aLaneIndex] = aCrosses_A_A[aLaneIndex];
            Soccer2::mCross[1][aLaneIndex] = aCrosses_B_A[aLaneIndex];
            Soccer2::mCross[2][aLaneIndex] = aCrosses_C_A[aLaneIndex];
            Soccer2::mCross[3][aLaneIndex] = aCrosses_D_A[aLaneIndex];
        }
        
        Soccer2::TwistRound(0);
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            const std::size_t aByteRichness = LaneTool::ByteRichness(Soccer2::mMaterials[aLaneIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_TwistRound_Strong: for zeros, at lane %zu, expected byte richess 512+, got %zu", aLaneIndex, aByteRichness);
                return;
            }
            std::memcpy(aExpectation_A[aLaneIndex], Soccer2::mMaterials[aLaneIndex], S_BLOCK);
        }
        
        for (std::size_t aFirstIndex=1; aFirstIndex<aLaneCount; aFirstIndex++) {
            for (std::size_t aSecondIndex=0; aSecondIndex<aFirstIndex; aSecondIndex++) {
                if (std::memcmp(Soccer2::mMaterials[aFirstIndex], Soccer2::mMaterials[aSecondIndex], S_BLOCK) == 0) {
                    XCTFail("test_TwistRound_Strong: lanes at %zu and %zu were identical for zeros, should not happen", aFirstIndex, aSecondIndex);
                    return;
                }
            }
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = aEncryptionStrength;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            Soccer2::mSources[aLaneIndex] = aSources_B[aLaneIndex];
            Soccer2::mCross[0][aLaneIndex] = aCrosses_A_B[aLaneIndex];
            Soccer2::mCross[1][aLaneIndex] = aCrosses_B_B[aLaneIndex];
            Soccer2::mCross[2][aLaneIndex] = aCrosses_C_B[aLaneIndex];
            Soccer2::mCross[3][aLaneIndex] = aCrosses_D_B[aLaneIndex];
        }
        
        Soccer2::TwistRound(0);
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            const std::size_t aByteRichness = LaneTool::ByteRichness(Soccer2::mMaterials[aLaneIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_TwistRound_Strong: for randoms, at lane %zu, expected byte richess 512+, got %zu", aLaneIndex, aByteRichness);
                return;
            }
            std::memcpy(aExpectation_B[aLaneIndex], Soccer2::mMaterials[aLaneIndex], S_BLOCK);
        }
        
        for (std::size_t aFirstIndex=1; aFirstIndex<aLaneCount; aFirstIndex++) {
            for (std::size_t aSecondIndex=0; aSecondIndex<aFirstIndex; aSecondIndex++) {
                if (std::memcmp(Soccer2::mMaterials[aFirstIndex], Soccer2::mMaterials[aSecondIndex], S_BLOCK) == 0) {
                    XCTFail("test_TwistRound_Strong: lanes at %zu and %zu were identical for randoms, should not happen", aFirstIndex, aSecondIndex);
                    return;
                }
            }
        }
        
        for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
            if (std::memcmp(aExpectation_A[aLaneIndex], aExpectation_B[aLaneIndex], S_BLOCK) == 0) {
                XCTFail("test_TwistRound_Strong: for compare zeros and randoms, at lane %zu, we had identical output. impossible.", aLaneIndex);
                return;
            }
        }
        
        
        for (std::size_t aBlockIndexIndex=0; aBlockIndexIndex<6; aBlockIndexIndex++) {
            
            std::size_t aBlockIndex = aBlockIndexList[aBlockIndexIndex];
            
            Soccer2::Zero();
            Soccer2::mStrength = aEncryptionStrength;
            Soccer2::InitializeExpanders();
            Soccer2::InitializeWorkSpaces();
            Soccer2::InitializeMaterials();
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                Soccer2::mSources[aLaneIndex] = aSources_A[aLaneIndex];
                Soccer2::mCross[0][aLaneIndex] = aCrosses_A_A[aLaneIndex];
                Soccer2::mCross[1][aLaneIndex] = aCrosses_B_A[aLaneIndex];
                Soccer2::mCross[2][aLaneIndex] = aCrosses_C_A[aLaneIndex];
                Soccer2::mCross[3][aLaneIndex] = aCrosses_D_A[aLaneIndex];
            }
            
            Soccer2::TwistRound(aBlockIndex);
            
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                
                if (std::memcmp(&Soccer2::mMaterials[aLaneIndex][aBlockIndex * S_BLOCK],
                                aExpectation_A[aLaneIndex], S_BLOCK) != 0) {
                    XCTFail("test_TwistRound_Strong: at block %zu lane %zu, we did not get equal to expectation", aBlockIndex, aLaneIndex);
                    return;
                }
            }
            
            printf("test_TwistRound_Strong trial %zu finished block %zu (zero)\n", aTrial, aBlockIndex);
        }
        
        for (std::size_t aBlockIndexIndex=0; aBlockIndexIndex<6; aBlockIndexIndex++) {
            
            std::size_t aBlockIndex = aBlockIndexList[aBlockIndexIndex];
            
            Soccer2::Zero();
            Soccer2::mStrength = aEncryptionStrength;
            Soccer2::InitializeExpanders();
            Soccer2::InitializeWorkSpaces();
            Soccer2::InitializeMaterials();
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                Soccer2::mSources[aLaneIndex] = aSources_B[aLaneIndex];
                Soccer2::mCross[0][aLaneIndex] = aCrosses_A_B[aLaneIndex];
                Soccer2::mCross[1][aLaneIndex] = aCrosses_B_B[aLaneIndex];
                Soccer2::mCross[2][aLaneIndex] = aCrosses_C_B[aLaneIndex];
                Soccer2::mCross[3][aLaneIndex] = aCrosses_D_B[aLaneIndex];
            }
            
            Soccer2::TwistRound(aBlockIndex);
            
            for (std::size_t aLaneIndex=0; aLaneIndex<aLaneCount; aLaneIndex++) {
                
                if (std::memcmp(&Soccer2::mMaterials[aLaneIndex][aBlockIndex * S_BLOCK],
                                aExpectation_B[aLaneIndex], S_BLOCK) != 0) {
                    XCTFail("test_TwistRound_Strong: at block %zu lane %zu, we did not get equal to expectation", aBlockIndex, aLaneIndex);
                    return;
                }
            }
            
            printf("test_TwistRound_Strong trial %zu finished block %zu (randoms)\n", aTrial, aBlockIndex);
        }
        
    }
}

@end
