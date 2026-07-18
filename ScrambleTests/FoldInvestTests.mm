//
//  FoldInvestTests.m
//  ScrambleTests
//
//  Created by nicholas raptis on 7/17/26.
//

#import <XCTest/XCTest.h>

#include "WorkSpaceTools.hpp"
#include "LaneTool.hpp"
#include "ExpanderFactory.hpp"

@interface FoldInvestTests : XCTestCase

@end

@implementation FoldInvestTests

namespace {

    std::size_t CountDifferentRows(const std::uint8_t *pKeyBoxA,
                                   const std::uint8_t *pKeyBoxB) {
        std::size_t aDifferentRowCount = 0U;

        for (std::size_t aRowIndex=0U; aRowIndex<H_KEY; aRowIndex++) {
            const std::size_t aRowStart = aRowIndex * W_KEY;

            for (std::size_t aByteIndex=0U; aByteIndex<W_KEY; aByteIndex++) {
                const std::size_t aIndex = aRowStart + aByteIndex;
                if (pKeyBoxA[aIndex] != pKeyBoxB[aIndex]) {
                    aDifferentRowCount++;
                    break;
                }
            }
        }

        return aDifferentRowCount;
    }
    
    void SeedWorkSpace(TwistWorkSpace *pWorkSpace) {
        WorkSpaceTools::FillWorkSpace(pWorkSpace);
    }
    
    void CopyWorkSpace(TwistWorkSpace *pSource, TwistWorkSpace *pDestination) {
        memcpy(pDestination->mInvestLaneA, pSource->mInvestLaneA, S_BLOCK);
        memcpy(pDestination->mInvestLaneB, pSource->mInvestLaneB, S_BLOCK);
        memcpy(pDestination->mInvestLaneC, pSource->mInvestLaneC, S_BLOCK);
        memcpy(pDestination->mInvestLaneD, pSource->mInvestLaneD, S_BLOCK);
        memcpy(pDestination->mInvestLaneE, pSource->mInvestLaneE, S_BLOCK);
        memcpy(pDestination->mInvestLaneF, pSource->mInvestLaneF, S_BLOCK);
        memcpy(pDestination->mInvestLaneG, pSource->mInvestLaneG, S_BLOCK);
        memcpy(pDestination->mInvestLaneH, pSource->mInvestLaneH, S_BLOCK);
        
        memcpy(&pDestination->mKeyBoxA[0][0], &pSource->mKeyBoxA[0][0], S_KEY);
        memcpy(&pDestination->mKeyBoxB[0][0], &pSource->mKeyBoxB[0][0], S_KEY);
    }
    
    bool ValidateKeyASame(TwistWorkSpace *pWorkSpaceA, TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyBoxA_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyBoxUnrolledA);
        std::uint8_t *aKeyBoxA_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyBoxUnrolledA);
        
        for (std::size_t aIndex=0; aIndex<S_KEY; aIndex++) {
            if (aKeyBoxA_A[aIndex] != aKeyBoxA_B[aIndex]) {
                printf("Key Box A expected to match, but did not at index %d\n", (int)aIndex);
                LaneTool::PrintMismatch("key_a", aKeyBoxA_A, aKeyBoxA_B, aIndex + 20, S_KEY);
                return false;
            }
        }
        return true;
    }
    
    bool ValidateKeyAExactlyOneRowDifferent(TwistWorkSpace *pWorkSpaceA,
                                            TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyBoxA_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyBoxUnrolledA);
        std::uint8_t *aKeyBoxA_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyBoxUnrolledA);
        
        return CountDifferentRows(aKeyBoxA_A, aKeyBoxA_B) == 1U;
    }
    
    bool ValidateKeyBSame(TwistWorkSpace *pWorkSpaceA, TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyBoxB_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyBoxUnrolledB);
        std::uint8_t *aKeyBoxB_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyBoxUnrolledB);
        
        for (std::size_t aIndex=0; aIndex<S_KEY; aIndex++) {
            if (aKeyBoxB_A[aIndex] != aKeyBoxB_B[aIndex]) {
                printf("Key Box B expected to match, but did not at index %d\n", (int)aIndex);
                LaneTool::PrintMismatch("key_b", aKeyBoxB_A, aKeyBoxB_B, aIndex + 20, S_KEY);
                return false;
            }
        }
        return true;
    }
    
    bool ValidateKeyBExactlyOneRowDifferent(TwistWorkSpace *pWorkSpaceA,
                                            TwistWorkSpace *pWorkSpaceB) {
        
        std::uint8_t *aKeyBoxB_A = pWorkSpaceA->GetBuffer(pWorkSpaceA, TwistWorkSpaceSlot::kKeyBoxUnrolledB);
        std::uint8_t *aKeyBoxB_B = pWorkSpaceB->GetBuffer(pWorkSpaceB, TwistWorkSpaceSlot::kKeyBoxUnrolledB);
        
        return CountDifferentRows(aKeyBoxB_A, aKeyBoxB_B) == 1U;
    }
    
};

- (void)testAll {
    
    std::vector<ExpanderItem> aExpanderItems = ExpanderFactory::Get();
    
    for (auto &aExpanderItem : aExpanderItems) {
        
        TwistWorkSpace *aOriginalWorkSpace = new TwistWorkSpace();
        SeedWorkSpace(aOriginalWorkSpace);
        
        TwistWorkSpace *aTestWorkSpace = new TwistWorkSpace();
        SeedWorkSpace(aTestWorkSpace);
        
        aExpanderItem.mExpander->mWorkspace = aOriginalWorkSpace;
        aExpanderItem.mExpander->SquashInvestToKeyBoxes();
        
        for (std::size_t aInvestLaneIndex=0; aInvestLaneIndex<8; aInvestLaneIndex++) {
            
            printf("Checking %s, lane %zu!\n", aExpanderItem.mName.c_str(), aInvestLaneIndex);
            
            for (std::size_t aByteIndex=0; aByteIndex<S_BLOCK; aByteIndex++) {
                
                CopyWorkSpace(aOriginalWorkSpace, aTestWorkSpace);
                
                aExpanderItem.mExpander->mWorkspace = aTestWorkSpace;
                aExpanderItem.mExpander->SquashInvestToKeyBoxes();
                
                if (!ValidateKeyASame(aOriginalWorkSpace, aTestWorkSpace)) {
                    delete aOriginalWorkSpace;
                    delete aTestWorkSpace;
                    
                    XCTFail("expected these key rows to be the same, they weren't.");
                    return;
                }
                
                if (!ValidateKeyBSame(aOriginalWorkSpace, aTestWorkSpace)) {
                    delete aOriginalWorkSpace;
                    delete aTestWorkSpace;
                    
                    XCTFail("expected these key rows to be the same, they weren't.");
                    return;
                }
                
                
                // Now we want to make sure changing the byte influences the key...
                std::uint8_t *aLane = aTestWorkSpace->mInvestLaneA;
                if (aInvestLaneIndex == 1) { aLane = aTestWorkSpace->mInvestLaneB; }
                if (aInvestLaneIndex == 2) { aLane = aTestWorkSpace->mInvestLaneC; }
                if (aInvestLaneIndex == 3) { aLane = aTestWorkSpace->mInvestLaneD; }
                if (aInvestLaneIndex == 4) { aLane = aTestWorkSpace->mInvestLaneE; }
                if (aInvestLaneIndex == 5) { aLane = aTestWorkSpace->mInvestLaneF; }
                if (aInvestLaneIndex == 6) { aLane = aTestWorkSpace->mInvestLaneG; }
                if (aInvestLaneIndex == 7) { aLane = aTestWorkSpace->mInvestLaneH; }
                
                bool aFoundSolution = false;
                
                for (std::size_t aByteValue=0; aByteValue<256; aByteValue++) {
                    
                    memcpy(&aTestWorkSpace->mKeyBoxA[0][0], &aOriginalWorkSpace->mKeyBoxA[0][0], S_KEY);
                    memcpy(&aTestWorkSpace->mKeyBoxB[0][0], &aOriginalWorkSpace->mKeyBoxB[0][0], S_KEY);
                    
                    aLane[aByteIndex] = aByteValue;
                    aExpanderItem.mExpander->SquashInvestToKeyBoxes();
                    
                    bool aExactlyOneRowChangedA = ValidateKeyAExactlyOneRowDifferent(aOriginalWorkSpace, aTestWorkSpace);
                    bool aExactlyOneRowChangedB = ValidateKeyBExactlyOneRowDifferent(aOriginalWorkSpace, aTestWorkSpace);
                    
                    if ((aExactlyOneRowChangedA == true) && ValidateKeyBSame(aOriginalWorkSpace, aTestWorkSpace)) {
                        aFoundSolution = true;
                        break;
                    }
                    if ((aExactlyOneRowChangedB == true) && ValidateKeyASame(aOriginalWorkSpace, aTestWorkSpace)) {
                        aFoundSolution = true;
                        break;
                    }
                }
                
            if (aFoundSolution == false) {
                printf("The destination scheme did not work at byte %zu\n", aByteIndex);
                delete aOriginalWorkSpace;
                delete aTestWorkSpace;
                
                XCTFail("expected these destination rows to be the same, they weren't.");
                return;
            }
                
                
            }
        }
        
        delete aOriginalWorkSpace;
        delete aTestWorkSpace;
    }
}

@end
