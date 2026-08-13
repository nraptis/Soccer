//
//  RotateKeyBoxTests.m
//  ScrambleTests
//
//  Created by nick on 8/1/26.
//

#import <XCTest/XCTest.h>

#include "Soccer2.hpp"
#include "TwistShiftBox.hpp"
#include "LaneTool.hpp"
#include "ExpanderFactory.hpp"
#include "WorkSpaceTools.hpp"

#include <cstdint>
#include <cstring>
#include <vector>
#include <unordered_set>

@interface RotateKeyBoxTests : XCTestCase

@end

@implementation RotateKeyBoxTests

- (void)test_ShiftKeyBoxLoopin {
    
    TwistWorkSpace aWorkSpace;
    memset(aWorkSpace.mKeyBoxA[0], 'a', W_KEY);
    memset(aWorkSpace.mKeyBoxA[1], 'b', W_KEY);
    memset(aWorkSpace.mKeyBoxA[2], 'c', W_KEY);
    memset(aWorkSpace.mKeyBoxA[3], 'd', W_KEY);
    memset(aWorkSpace.mKeyBoxA[4], 'e', W_KEY);
    memset(aWorkSpace.mKeyBoxA[5], 'f', W_KEY);
    memset(aWorkSpace.mKeyBoxA[6], 'g', W_KEY);
    memset(aWorkSpace.mKeyBoxA[7], 'h', W_KEY);
    
    for (std::size_t aBlockIndex=0;aBlockIndex<32;aBlockIndex++) {
        const bool aStifleKey = (aBlockIndex >= (32 - H_KEY));
        
        if (aStifleKey) {
            aWorkSpace.ShiftKeyBoxA(&aWorkSpace.mKeyBoxA[0][0]);
            
            printf("on block %zu, we shifted\n", aBlockIndex);
            
            for (std::size_t aIndex=0; aIndex<H_KEY; aIndex++) {
                printf("key[%zu] = %c\n", aIndex, aWorkSpace.mKeyBoxA[aIndex][0]);
            }
        }
    }
}

- (void)test_ShiftKeyBoxA {
    
    uint8_t aRow_00[W_KEY];
    uint8_t aRow_01[W_KEY];
    uint8_t aRow_02[W_KEY];
    uint8_t aRow_03[W_KEY];
    uint8_t aRow_04[W_KEY];
    uint8_t aRow_05[W_KEY];
    uint8_t aRow_06[W_KEY];
    uint8_t aRow_07[W_KEY];
    
    for (int i=0; i<W_KEY; i++) {
        aRow_00[i] = 0xA1;
        aRow_01[i] = 0xB2;
        aRow_02[i] = 0xC3;
        aRow_03[i] = 0xD4;
        aRow_04[i] = 0xE5;
        aRow_05[i] = 0xF6;
        aRow_06[i] = 0x1A;
        aRow_07[i] = 0x2B;
    }
    
    TwistWorkSpace aWorkSpace;
    std::memcpy(aWorkSpace.mKeyBoxA[0], aRow_00, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxA[1], aRow_01, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxA[2], aRow_02, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxA[3], aRow_03, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxA[4], aRow_04, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxA[5], aRow_05, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxA[6], aRow_06, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxA[7], aRow_07, W_KEY);
    
    for (int i=0; i<W_KEY; i++) {
        if (aWorkSpace.mKeyBoxA[0][i] != 0xA1) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[0][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[1][i] != 0xB2) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[1][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[2][i] != 0xC3) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[2][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[3][i] != 0xD4) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[3][%d]", i);
            return;
        }
        
        if (aWorkSpace.mKeyBoxA[4][i] != 0xE5) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[4][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[5][i] != 0xF6) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[5][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[6][i] != 0x1A) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[6][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[7][i] != 0x2B) {
            XCTFail("test_ShiftKeyBoxA: failed on control test, key_box_a[7][%d]", i);
            return;
        }
    }
    
    TwistShiftBox::ShiftKeyBoxA(&aWorkSpace);
    
    for (int i=0; i<W_KEY; i++) {
        if (aWorkSpace.mKeyBoxA[0][i] != 0xA1) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[0][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[1][i] != 0xA1) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[1][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[2][i] != 0xB2) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[2][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[3][i] != 0xC3) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[3][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[4][i] != 0xD4) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[4][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[5][i] != 0xE5) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[5][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[6][i] != 0xF6) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[6][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxA[7][i] != 0x1A) {
            XCTFail("test_ShiftKeyBoxA: failed on post-shift test, key_box_a[7][%d]", i);
            return;
        }
    }
}

- (void)test_ShiftKeyBoxB {
    
    uint8_t aRow_00[W_KEY];
    uint8_t aRow_01[W_KEY];
    uint8_t aRow_02[W_KEY];
    uint8_t aRow_03[W_KEY];
    uint8_t aRow_04[W_KEY];
    uint8_t aRow_05[W_KEY];
    uint8_t aRow_06[W_KEY];
    uint8_t aRow_07[W_KEY];
    
    for (int i=0; i<W_KEY; i++) {
        aRow_00[i] = 0xA1;
        aRow_01[i] = 0xB2;
        aRow_02[i] = 0xC3;
        aRow_03[i] = 0xD4;
        aRow_04[i] = 0xE5;
        aRow_05[i] = 0xF6;
        aRow_06[i] = 0x1A;
        aRow_07[i] = 0x2B;
    }
    
    TwistWorkSpace aWorkSpace;
    std::memcpy(aWorkSpace.mKeyBoxB[0], aRow_00, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxB[1], aRow_01, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxB[2], aRow_02, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxB[3], aRow_03, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxB[4], aRow_04, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxB[5], aRow_05, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxB[6], aRow_06, W_KEY);
    std::memcpy(aWorkSpace.mKeyBoxB[7], aRow_07, W_KEY);
    
    for (int i=0; i<W_KEY; i++) {
        if (aWorkSpace.mKeyBoxB[0][i] != 0xA1) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[0][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[1][i] != 0xB2) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[1][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[2][i] != 0xC3) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[2][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[3][i] != 0xD4) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[3][%d]", i);
            return;
        }
        
        if (aWorkSpace.mKeyBoxB[4][i] != 0xE5) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[4][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[5][i] != 0xF6) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[5][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[6][i] != 0x1A) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[6][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[7][i] != 0x2B) {
            XCTFail("test_ShiftKeyBoxB: failed on control test, key_box_b[7][%d]", i);
            return;
        }
    }
    
    TwistShiftBox::ShiftKeyBoxB(&aWorkSpace);
    
    for (int i=0; i<W_KEY; i++) {
        if (aWorkSpace.mKeyBoxB[0][i] != 0xA1) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[0][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[1][i] != 0xA1) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[1][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[2][i] != 0xB2) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[2][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[3][i] != 0xC3) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[3][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[4][i] != 0xD4) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[4][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[5][i] != 0xE5) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[5][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[6][i] != 0xF6) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[6][%d]", i);
            return;
        }
        if (aWorkSpace.mKeyBoxB[7][i] != 0x1A) {
            XCTFail("test_ShiftKeyBoxB: failed on post-shift test, key_box_b[7][%d]", i);
            return;
        }
    }
}

- (void)test_FoldKeyRowA {
    
    /*
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0;
    
    std::uint64_t aWandererA = 0;
    std::uint64_t aWandererB = 0;
    std::uint64_t aWandererC = 0;
    std::uint64_t aWandererD = 0;
    
    std::uint64_t aWandererE = 0;
    std::uint64_t aWandererF = 0;
    std::uint64_t aWandererG = 0;
    std::uint64_t aWandererH = 0;
    
    std::uint64_t aWandererI = 0;
    std::uint64_t aWandererJ = 0;
    std::uint64_t aWandererK = 0;
    */
    
    uint8_t aRow_00[W_KEY];
    uint8_t aRow_01[W_KEY];
    uint8_t aRow_02[W_KEY];
    uint8_t aRow_03[W_KEY];
    uint8_t aRow_04[W_KEY];
    uint8_t aRow_05[W_KEY];
    uint8_t aRow_06[W_KEY];
    uint8_t aRow_07[W_KEY];
    
    for (int i=0; i<W_KEY; i++) {
        aRow_00[i] = 0xA1;
        aRow_01[i] = 0xB2;
        aRow_02[i] = 0xC3;
        aRow_03[i] = 0xD4;
        aRow_04[i] = 0xE5;
        aRow_05[i] = 0xF6;
        aRow_06[i] = 0x1A;
        aRow_07[i] = 0x2B;
    }
    
    uint8_t aSource[S_BLOCK];
    for (int i=0; i<W_KEY; i++) {
        aSource[i] = 0x00;
    }
    
    std::vector<ExpanderItem> aExpanderItems = ExpanderFactory::Get();
    for (auto &aExpanderItem : aExpanderItems) {
        
        TwistWorkSpace aWorkSpace;
        
        WorkSpaceTools::FillWorkSpace(&aWorkSpace);
        
        std::memcpy(aWorkSpace.mKeyBoxA[0], aRow_00, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxA[1], aRow_01, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxA[2], aRow_02, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxA[3], aRow_03, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxA[4], aRow_04, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxA[5], aRow_05, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxA[6], aRow_06, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxA[7], aRow_07, W_KEY);
        
        aExpanderItem.mExpander->TwistBlock(&aWorkSpace,
                                            aSource,
                                            aSource,
                                            aSource,
                                            aSource,
                                            aSource,
                                            aSource,
                                            false);
        
        std::unordered_set<std::uint8_t> aCharBag;
    
        for (int i=0; i<W_KEY; i++) {
            
            aCharBag.insert(aWorkSpace.mKeyBoxA[0][i]);
            
            if (aWorkSpace.mKeyBoxA[1][i] != 0xA1) {
                XCTFail("test_FoldKeyRowA: failed on twist block + fold key a test, key_box_a[1][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxA[2][i] != 0xB2) {
                XCTFail("test_FoldKeyRowA: failed on twist block + fold key a test, key_box_a[2][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxA[3][i] != 0xC3) {
                XCTFail("test_FoldKeyRowA: failed on twist block + fold key a test, key_box_a[3][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxA[4][i] != 0xD4) {
                XCTFail("test_FoldKeyRowA: failed on twist block + fold key a test, key_box_a[4][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxA[5][i] != 0xE5) {
                XCTFail("test_FoldKeyRowA: failed on twist block + fold key a test, key_box_a[5][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxA[6][i] != 0xF6) {
                XCTFail("test_FoldKeyRowA: failed on twist block + fold key a test, key_box_a[6][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxA[7][i] != 0x1A) {
                XCTFail("test_FoldKeyRowA: failed on twist block + fold key a test, key_box_a[7][%d]", i);
                return;
            }
        }
        
        if (aCharBag.size() < 128) {
            XCTFail("test_FoldKeyRowA: failed on twist block, expected semi-random bytes in key row write [a]");
            return;
        }
        
    }
    
}

- (void)test_FoldKeyRowB {
    
    /*
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0;
    
    std::uint64_t aWandererA = 0;
    std::uint64_t aWandererB = 0;
    std::uint64_t aWandererC = 0;
    std::uint64_t aWandererD = 0;
    
    std::uint64_t aWandererE = 0;
    std::uint64_t aWandererF = 0;
    std::uint64_t aWandererG = 0;
    std::uint64_t aWandererH = 0;
    
    std::uint64_t aWandererI = 0;
    std::uint64_t aWandererJ = 0;
    std::uint64_t aWandererK = 0;
    */
    
    uint8_t aRow_00[W_KEY];
    uint8_t aRow_01[W_KEY];
    uint8_t aRow_02[W_KEY];
    uint8_t aRow_03[W_KEY];
    uint8_t aRow_04[W_KEY];
    uint8_t aRow_05[W_KEY];
    uint8_t aRow_06[W_KEY];
    uint8_t aRow_07[W_KEY];
    
    for (int i=0; i<W_KEY; i++) {
        aRow_00[i] = 0xA1;
        aRow_01[i] = 0xB2;
        aRow_02[i] = 0xC3;
        aRow_03[i] = 0xD4;
        aRow_04[i] = 0xE5;
        aRow_05[i] = 0xF6;
        aRow_06[i] = 0x1A;
        aRow_07[i] = 0x2B;
    }
    
    uint8_t aSource[S_BLOCK];
    for (int i=0; i<W_KEY; i++) {
        aSource[i] = 0x00;
    }
    
    std::vector<ExpanderItem> aExpanderItems = ExpanderFactory::Get();
    for (auto &aExpanderItem : aExpanderItems) {
        
        TwistWorkSpace aWorkSpace;
        
        WorkSpaceTools::FillWorkSpace(&aWorkSpace);
        
        std::memcpy(aWorkSpace.mKeyBoxB[0], aRow_00, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxB[1], aRow_01, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxB[2], aRow_02, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxB[3], aRow_03, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxB[4], aRow_04, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxB[5], aRow_05, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxB[6], aRow_06, W_KEY);
        std::memcpy(aWorkSpace.mKeyBoxB[7], aRow_07, W_KEY);
        
        aExpanderItem.mExpander->TwistBlock(&aWorkSpace,
                                            aSource,
                                            aSource,
                                            aSource,
                                            aSource,
                                            aSource,
                                            aSource,
                                            false);
        
        std::unordered_set<std::uint8_t> aCharBag;
    
        for (int i=0; i<W_KEY; i++) {
            
            aCharBag.insert(aWorkSpace.mKeyBoxB[0][i]);
            
            if (aWorkSpace.mKeyBoxB[1][i] != 0xA1) {
                XCTFail("test_FoldKeyRowB: failed on twist block + fold key b test, key_box_b[1][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxB[2][i] != 0xB2) {
                XCTFail("test_FoldKeyRowB: failed on twist block + fold key b test, key_box_b[2][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxB[3][i] != 0xC3) {
                XCTFail("test_FoldKeyRowB: failed on twist block + fold key b test, key_box_b[3][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxB[4][i] != 0xD4) {
                XCTFail("test_FoldKeyRowB: failed on twist block + fold key b test, key_box_b[4][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxB[5][i] != 0xE5) {
                XCTFail("test_FoldKeyRowB: failed on twist block + fold key b test, key_box_b[5][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxB[6][i] != 0xF6) {
                XCTFail("test_FoldKeyRowB: failed on twist block + fold key b test, key_box_b[6][%d]", i);
                return;
            }
            if (aWorkSpace.mKeyBoxB[7][i] != 0x1A) {
                XCTFail("test_FoldKeyRowB: failed on twist block + fold key b test, key_box_b[7][%d]", i);
                return;
            }
        }
        
        if (aCharBag.size() < 128) {
            XCTFail("test_FoldKeyRowB: failed on twist block, expected semi-random bytes in key row write [b]");
            return;
        }
        
    }
    
}

@end
