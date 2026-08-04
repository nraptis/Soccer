//
//  FoldGrowBTests.m
//  ScrambleTests
//
//  Created by nicholas raptis on 7/17/26.
//

#import <XCTest/XCTest.h>

#include "WorkSpaceTools.hpp"
#include "LaneTool.hpp"
#include "ExpanderFactory.hpp"

@interface FoldGrowBTests : XCTestCase

@end

@implementation FoldGrowBTests

namespace {
    void SeedWorkSpace(TwistWorkSpace *pWorkSpace) {
        WorkSpaceTools::FillWorkSpace(pWorkSpace);
    }
    
    void CopyWorkSpace(TwistWorkSpace *pSource, TwistWorkSpace *pDestination) {
        memcpy(pDestination->mSpiritLaneA, pSource->mSpiritLaneA, S_BLOCK);
        memcpy(pDestination->mSpiritLaneB, pSource->mSpiritLaneB, S_BLOCK);
        memcpy(pDestination->mSpiritLaneC, pSource->mSpiritLaneC, S_BLOCK);
        memcpy(pDestination->mSpiritLaneD, pSource->mSpiritLaneD, S_BLOCK);
        
        memcpy(&pDestination->mKeyBoxB[0][0], &pSource->mKeyBoxB[0][0], S_KEY);
    }
    
    bool ValidateKeyBWriteSame(TwistWorkSpace *pWorkSpaceA, TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyRowB_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyRowWriteB);
        std::uint8_t *aKeyRowB_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyRowWriteB);
        
        for (std::size_t aIndex=0; aIndex<W_KEY; aIndex++) {
            if (aKeyRowB_A[aIndex] != aKeyRowB_B[aIndex]) {
                printf("Read Key Row B expected to match, but did not at index %d\n", (int)aIndex);
                LaneTool::PrintMismatch("key_b", aKeyRowB_A, aKeyRowB_B, aIndex + 20, W_KEY);
                return false;
            }
        }
        
        return true;
    }
    
    bool ValidateKeyBDifferent(TwistWorkSpace *pWorkSpaceA, TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyRowB_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyRowWriteB);
        std::uint8_t *aKeyRowB_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyRowWriteB);
        
        for (std::size_t aIndex=0; aIndex<W_KEY; aIndex++) {
            if (aKeyRowB_A[aIndex] != aKeyRowB_B[aIndex]) {
                return true;
            }
        }
        
        return false;
    }
};

- (void)testAll {
    
    /*
    std::vector<ExpanderItem> aExpanderItems = ExpanderFactory::Get();
    
    for (auto &aExpanderItem : aExpanderItems) {
        
        TwistWorkSpace *aOriginalWorkSpace = new TwistWorkSpace();
        SeedWorkSpace(aOriginalWorkSpace);
        
        TwistWorkSpace *aOriginalWorkSpaceMutated = new TwistWorkSpace();
        SeedWorkSpace(aOriginalWorkSpaceMutated);
        
        TwistWorkSpace *aTestWorkSpaceA = new TwistWorkSpace();
        SeedWorkSpace(aTestWorkSpaceA);
        
        TwistWorkSpace *aTestWorkSpaceB = new TwistWorkSpace();
        SeedWorkSpace(aTestWorkSpaceB);
        
        CopyWorkSpace(aOriginalWorkSpace, aOriginalWorkSpaceMutated);
        aExpanderItem.mExpander->GrowKeyB(aOriginalWorkSpaceMutated);
        
        for (std::size_t aSpiritLaneIndex=0; aSpiritLaneIndex<4; aSpiritLaneIndex++) {
            
            printf("Checking %s, lane %zu!\n", aExpanderItem.mName.c_str(), aSpiritLaneIndex);
            
            for (std::size_t aByteIndex=0; aByteIndex<S_BLOCK; aByteIndex++) {
                
                CopyWorkSpace(aOriginalWorkSpace, aTestWorkSpaceA);
                CopyWorkSpace(aOriginalWorkSpace, aTestWorkSpaceB);
                
                aExpanderItem.mExpander->GrowKeyB(aTestWorkSpaceA);
                
                if (!ValidateKeyBWriteSame(aOriginalWorkSpaceMutated, aTestWorkSpaceA)) {
                    delete aOriginalWorkSpace;
                    delete aOriginalWorkSpaceMutated;
                    delete aTestWorkSpaceA;
                    delete aTestWorkSpaceB;
                    XCTFail("expected these key rows to be the same, they weren't.");
                    return;
                }
                
                
                // Now we want to make sure changing the byte influences the key...
                std::uint8_t *aLane = aTestWorkSpaceB->mSpiritLaneA;
                if (aSpiritLaneIndex == 1) { aLane = aTestWorkSpaceB->mSpiritLaneB; }
                if (aSpiritLaneIndex == 2) { aLane = aTestWorkSpaceB->mSpiritLaneC; }
                if (aSpiritLaneIndex == 3) { aLane = aTestWorkSpaceB->mSpiritLaneD; }
                
                bool aFoundSolution = false;
                
                for (std::size_t aByteValue=0; aByteValue<256; aByteValue++) {
                    
                    memcpy(&aTestWorkSpaceB->mKeyBoxB[H_KEY - 1][0], &aOriginalWorkSpaceMutated->mKeyBoxB[H_KEY - 1][0], W_KEY);
                    
                    
                    aLane[aByteIndex] = aByteValue;
                    aExpanderItem.mExpander->GrowKeyB(aTestWorkSpaceB);
                    
                    if (ValidateKeyBDifferent(aOriginalWorkSpaceMutated, aTestWorkSpaceB)) {
                        aFoundSolution = true;
                        break;
                    }
                }
                
                if (aFoundSolution == false) {
                    printf("The key scheme did not work at byte %zu\n", aByteIndex);
                    delete aOriginalWorkSpace;
                    delete aOriginalWorkSpaceMutated;
                    delete aTestWorkSpaceA;
                    delete aTestWorkSpaceB;
                    XCTFail("expected these key rows to be the same, they weren't.");
                    return;
                }
            }
        }
        
        delete aOriginalWorkSpace;
        delete aOriginalWorkSpaceMutated;
        delete aTestWorkSpaceA;
        delete aTestWorkSpaceB;
    }
    */
}

@end
