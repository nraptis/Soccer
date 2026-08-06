//
//  ShuffleMEWBlockZeroTests.m
//  ScrambleTests
//
//  Created by nick on 8/5/26.
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

@interface ShuffleMEWBlockZeroTests : XCTestCase

@end

@implementation ShuffleMEWBlockZeroTests

- (void)test_MEWBlockZero_Expanders {
    
    static std::uint8_t aRandom[S_BLOCK];
    TwistExpander *aExpanders[32];
    
    for (std::size_t aTrial=0; aTrial<42; aTrial++) {
        
        WorkSpaceTools::FillBytes(aRandom, S_BLOCK);
        for (std::size_t aClaimCount=0; aClaimCount<16; aClaimCount++) {
            
            Soccer2::Zero();
            
            Soccer2::InitializeExpanders();
            for (int i=0; i<32; i++) {
                aExpanders[i] = Soccer2::mExpanders[i];
            }
            Random::Shuffle(aExpanders, 32);
            
            std::unordered_set<TwistExpander *> aClaimed;
            for (std::size_t aClaimIndex=0;aClaimIndex<aClaimCount;aClaimIndex++) {
                Soccer2::mClaimedExpanders[aClaimIndex] = aExpanders[aClaimIndex];
                aClaimed.insert(aExpanders[aClaimIndex]);
            }
            Soccer2::mClaimedExpanderCount = aClaimCount;
            
            Random::Shuffle(Soccer2::mExpanders, 32);
            
            Soccer2::ShuffleMEWBlockZero(aRandom);
            
            std::unordered_set<TwistExpander *> aSet;
            
            std::size_t aShelf = 32 - aClaimCount;
            for (std::size_t aIndex=0; aIndex<aShelf; aIndex++) {
                if (aClaimed.contains(Soccer2::mExpanders[aIndex])) {
                    XCTFail("test_MEWBlockZero_Expanders: claimed expander existed at head (index = %zu, claim count = %zu).", aIndex, aClaimCount);
                    return;
                }
                aSet.insert(Soccer2::mExpanders[aIndex]);
            }
            
            for (std::size_t aIndex=aShelf; aIndex<32; aIndex++) {
                if (!aClaimed.contains(Soccer2::mExpanders[aIndex])) {
                    XCTFail("test_MEWBlockZero_Expanders: claimed expander didn't exist at tail (index = %zu, claim count = %zu).", aIndex, aClaimCount);
                    return;
                }
                aSet.insert(Soccer2::mExpanders[aIndex]);
            }
            
            if (aSet.size() != 32) {
                XCTFail("test_MEWBlockZero_Expanders: expected 32 unique expanders");
                return;
            }
        }
    }
}

- (void)test_MEWBlockZero_WorkSpaces {
    
    static std::uint8_t aRandom[S_BLOCK];
    TwistWorkSpace *aWorkSpaces[16];
    
    for (std::size_t aTrial=0; aTrial<42; aTrial++) {
        
        WorkSpaceTools::FillBytes(aRandom, S_BLOCK);
        for (std::size_t aClaimCount=0; aClaimCount<16; aClaimCount++) {
            
            Soccer2::Zero();
            
            Soccer2::InitializeWorkSpaces();
            for (int i=0; i<16; i++) {
                aWorkSpaces[i] = Soccer2::mWorkSpaces[i];
            }
            Random::Shuffle(aWorkSpaces, 16);
            
            std::unordered_set<TwistWorkSpace *> aClaimed;
            for (std::size_t aClaimIndex=0;aClaimIndex<aClaimCount;aClaimIndex++) {
                Soccer2::mClaimedWorkSpaces[aClaimIndex] = aWorkSpaces[aClaimIndex];
                aClaimed.insert(aWorkSpaces[aClaimIndex]);
            }
            Soccer2::mClaimedWorkSpaceCount = aClaimCount;
            
            Random::Shuffle(Soccer2::mWorkSpaces, 16);
            
            Soccer2::ShuffleMEWBlockZero(aRandom);
            
            std::unordered_set<TwistWorkSpace *> aSet;
            
            std::size_t aShelf = 16 - aClaimCount;
            for (std::size_t aIndex=0; aIndex<aShelf; aIndex++) {
                if (aClaimed.contains(Soccer2::mWorkSpaces[aIndex])) {
                    XCTFail("test_MEWBlockZero_WorkSpaces: claimed workspace existed at head (index = %zu, claim count = %zu).", aIndex, aClaimCount);
                    return;
                }
                aSet.insert(Soccer2::mWorkSpaces[aIndex]);
            }
            
            for (std::size_t aIndex=aShelf; aIndex<16; aIndex++) {
                if (!aClaimed.contains(Soccer2::mWorkSpaces[aIndex])) {
                    XCTFail("test_MEWBlockZero_WorkSpaces: claimed workspace didn't exist at tail (index = %zu, claim count = %zu).", aIndex, aClaimCount);
                    return;
                }
                aSet.insert(Soccer2::mWorkSpaces[aIndex]);
            }
            
            if (aSet.size() != 16) {
                XCTFail("test_MEWBlockZero_WorkSpaces: expected 32 unique workspaces");
                return;
            }
        }
    }
}

- (void)test_MEWBlockZero_Materials {
    
    static std::uint8_t aRandom[S_BLOCK];
    std::uint8_t *aMaterials[16];
    
    for (std::size_t aTrial=0; aTrial<42; aTrial++) {
        
        WorkSpaceTools::FillBytes(aRandom, S_BLOCK);
        for (std::size_t aClaimCount=0; aClaimCount<16; aClaimCount++) {
            
            Soccer2::Zero();
            
            Soccer2::InitializeMaterials();
            for (int i=0; i<16; i++) {
                aMaterials[i] = Soccer2::mMaterials[i];
            }
            Random::Shuffle(aMaterials, 16);
            
            std::unordered_set<std::uint8_t *> aClaimed;
            for (std::size_t aClaimIndex=0;aClaimIndex<aClaimCount;aClaimIndex++) {
                Soccer2::mClaimedMaterials[aClaimIndex] = aMaterials[aClaimIndex];
                aClaimed.insert(aMaterials[aClaimIndex]);
            }
            Soccer2::mClaimedMaterialCount = aClaimCount;
            
            Random::Shuffle(Soccer2::mMaterials, 16);
            
            Soccer2::ShuffleMEWBlockZero(aRandom);
            
            std::unordered_set<std::uint8_t *> aSet;
            
            std::size_t aShelf = 16 - aClaimCount;
            for (std::size_t aIndex=0; aIndex<aShelf; aIndex++) {
                if (aClaimed.contains(Soccer2::mMaterials[aIndex])) {
                    XCTFail("test_MEWBlockZero_Materials: claimed material existed at head (index = %zu, claim count = %zu).", aIndex, aClaimCount);
                    return;
                }
                aSet.insert(Soccer2::mMaterials[aIndex]);
            }
            
            for (std::size_t aIndex=aShelf; aIndex<16; aIndex++) {
                if (!aClaimed.contains(Soccer2::mMaterials[aIndex])) {
                    XCTFail("test_MEWBlockZero_Materials: claimed material didn't exist at tail (index = %zu, claim count = %zu).", aIndex, aClaimCount);
                    return;
                }
                aSet.insert(Soccer2::mMaterials[aIndex]);
            }
            
            if (aSet.size() != 16) {
                XCTFail("test_MEWBlockZero_Materials: expected 32 unique Materials");
                return;
            }
        }
    }
}

@end
