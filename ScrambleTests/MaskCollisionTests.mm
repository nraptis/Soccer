//
//  MaskCollisionTests.m
//  ScrambleTests
//
//  Created by nick on 8/6/26.
//

#import <XCTest/XCTest.h>
#include "Soccer2.hpp"
#include "Random.hpp"
#include <cstdint>

@interface MaskCollisionTests : XCTestCase

@end

@implementation MaskCollisionTests

- (void)test_MaskBalance {

    Soccer2::Zero();
    Soccer2::InitializeMasks();
    
    std::size_t aMinDifference = 256;
    std::size_t aMaxDifference = 0;
    
    for (std::size_t aIndexA = 1; aIndexA < 32; aIndexA++) {
        for (std::size_t aIndexB = 0U; aIndexB < aIndexA; aIndexB++) {
            
            const std::uint8_t aDifferenceMap = (Soccer2::mMasks[aIndexA] ^ Soccer2::mMasks[aIndexB]);
            
            const std::size_t aDifference = static_cast<std::size_t>(__builtin_popcount(static_cast<unsigned int>(aDifferenceMap)));
            
            if (aDifference < aMinDifference) {
                aMinDifference = aDifference;
            }
            if (aDifference > aMaxDifference) {
                aMaxDifference = aDifference;
            }
        }
    }
    
    if (aMinDifference != 2) {
        XCTFail("test_MaskBalance: expected min difference to be 2, got %zu", aMinDifference);
        return;
    }
    if (aMaxDifference != 8) {
        XCTFail("test_MaskBalance: expected max difference to be 2, got %zu", aMaxDifference);
        return;
    }

    aMinDifference = 100000;
    aMaxDifference = 4;
    
    for (std::size_t aIndexA = 0; aIndexA < 32; aIndexA++) {
        
        bool aBitA[8];
        for (std::size_t aShift=0; aShift<8; aShift++) {
            if (((Soccer2::mMasks[aIndexA] >> aShift) & 1) == 0) {
                aBitA[aShift] = false;
            } else {
                aBitA[aShift] = true;
            }
        }
        
        for (std::size_t aIndexB = 0U; aIndexB < 32; aIndexB++) {
            if (aIndexA != aIndexB) {
                
                bool aBitB[8];
                for (std::size_t aShift=0; aShift<8; aShift++) {
                    if (((Soccer2::mMasks[aIndexB] >> aShift) & 1) == 0) {
                        aBitB[aShift] = false;
                    } else {
                        aBitB[aShift] = true;
                    }
                }
                
                std::size_t aDifference = 0;
                for (std::size_t aIndex=0; aIndex<8; aIndex++) {
                
                    if (aBitA[aIndex] != aBitB[aIndex]) {
                        aDifference++;
                    }
                }
                
                if (aDifference < aMinDifference) {
                    aMinDifference = aDifference;
                }
                if (aDifference > aMaxDifference) {
                    aMaxDifference = aDifference;
                }
            }
        }
    }
    
    if (aMinDifference != 2) {
        XCTFail("test_MaskBalance: expected min difference to be 2, got %zu", aMinDifference);
        return;
    }
    if (aMaxDifference != 8) {
        XCTFail("test_MaskBalance: expected max difference to be 2, got %zu", aMaxDifference);
        return;
    }
    
    printf("*** test_MaskBalance: min difference %zu\n", aMinDifference);
    printf("*** test_MaskBalance: max difference %zu\n", aMaxDifference);
    printf("*** test_MaskBalance: [%zu - %zu] mask popcount range\n", aMinDifference, aMaxDifference);
    
}



@end
