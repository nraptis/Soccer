//
//  FoldGrowATests.m
//  ScrambleTests
//
//  Created by nicholas raptis on 7/17/26.
//

#import <XCTest/XCTest.h>

#include "WorkSpaceTools.hpp"
#include "LaneTool.hpp"
#include "ExpanderFactory.hpp"

@interface FoldGrowATests : XCTestCase

@end

@implementation FoldGrowATests

namespace {
    
    void SeedWorkSpace(TwistWorkSpace *pWorkSpace) {
        WorkSpaceTools::FillWorkSpace(pWorkSpace);
    }
    
    void CopyWorkSpace(TwistWorkSpace *pSource, TwistWorkSpace *pDestination) {
        memcpy(pDestination->mExpansionLaneA, pSource->mExpansionLaneA, S_BLOCK);
        memcpy(pDestination->mExpansionLaneB, pSource->mExpansionLaneB, S_BLOCK);
        memcpy(pDestination->mExpansionLaneC, pSource->mExpansionLaneC, S_BLOCK);
        memcpy(pDestination->mExpansionLaneD, pSource->mExpansionLaneD, S_BLOCK);
        
        memcpy(&pDestination->mKeyBoxA[0][0], &pSource->mKeyBoxA[0][0], S_KEY);
    }
    
    bool ValidateKeyAWriteSame(TwistWorkSpace *pWorkSpaceA, TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyRowA_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyRowWriteA);
        std::uint8_t *aKeyRowA_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyRowWriteA);
        
        for (std::size_t aIndex=0; aIndex<W_KEY; aIndex++) {
            if (aKeyRowA_A[aIndex] != aKeyRowA_B[aIndex]) {
                printf("Read Key Row A expected to match, but did not at index %d\n", (int)aIndex);
                LaneTool::PrintMismatch("key_a", aKeyRowA_A, aKeyRowA_B, aIndex + 20, W_KEY);
                return false;
            }
        }
        
        return true;
    }
    
    bool ValidateKeyADifferent(TwistWorkSpace *pWorkSpaceA, TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyRowA_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyRowWriteA);
        std::uint8_t *aKeyRowA_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyRowWriteA);
        
        for (std::size_t aIndex=0; aIndex<W_KEY; aIndex++) {
            if (aKeyRowA_A[aIndex] != aKeyRowA_B[aIndex]) {
                return true;
            }
        }
        
        return false;
    }
};

- (void)testAll {
    
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
        
        aExpanderItem.mExpander->GrowKeyA(aOriginalWorkSpaceMutated);
        
        for (std::size_t aExpansionLaneIndex=0; aExpansionLaneIndex<4; aExpansionLaneIndex++) {
            
            printf("Checking %s, lane %zu!\n", aExpanderItem.mName.c_str(), aExpansionLaneIndex);
            
            for (std::size_t aByteIndex=0; aByteIndex<S_BLOCK; aByteIndex++) {
                
                CopyWorkSpace(aOriginalWorkSpace, aTestWorkSpaceA);
                CopyWorkSpace(aOriginalWorkSpace, aTestWorkSpaceB);
                
                aExpanderItem.mExpander->GrowKeyA(aTestWorkSpaceA);
                
                if (!ValidateKeyAWriteSame(aOriginalWorkSpaceMutated, aTestWorkSpaceA)) {
                    delete aOriginalWorkSpace;
                    delete aOriginalWorkSpaceMutated;
                    delete aTestWorkSpaceA;
                    delete aTestWorkSpaceB;
                    XCTFail("expected these key rows to be the same, they weren't.");
                    return;
                }
                
                // Now we want to make sure changing the byte influences the key...
                std::uint8_t *aLane = aTestWorkSpaceB->mExpansionLaneA;
                if (aExpansionLaneIndex == 1) { aLane = aTestWorkSpaceB->mExpansionLaneB; }
                if (aExpansionLaneIndex == 2) { aLane = aTestWorkSpaceB->mExpansionLaneC; }
                if (aExpansionLaneIndex == 3) { aLane = aTestWorkSpaceB->mExpansionLaneD; }
                
                bool aFoundSolution = false;
                
                for (std::size_t aByteValue=0; aByteValue<256; aByteValue++) {
                    
                    memcpy(&aTestWorkSpaceB->mKeyBoxA[H_KEY - 1][0], &aOriginalWorkSpaceMutated->mKeyBoxA[H_KEY - 1][0], W_KEY);
                    
                    aLane[aByteIndex] = aByteValue;
                    aExpanderItem.mExpander->GrowKeyA(aTestWorkSpaceB);
                    
                    if (ValidateKeyADifferent(aOriginalWorkSpaceMutated, aTestWorkSpaceB)) {
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
}

@end
