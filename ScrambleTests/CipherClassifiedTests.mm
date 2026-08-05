//
//  CipherClassifiedTests.m
//  ScrambleTests
//
//  Created by nick on 8/4/26.
//

#import <XCTest/XCTest.h>

#include "Soccer2.hpp"
#include "LaneCombinations.hpp"

#include <cstdint>
#include <cstring>

@interface CipherClassifiedTests : XCTestCase

@end

@implementation CipherClassifiedTests

- (void)test_LaneCount {
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPasswordXORCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordXORCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordXORCipher) & CIPHER_MASK_LANE_COUNT_1) == 0U) {
        XCTFail("test_LaneCount: failed on kPasswordXORCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordXORCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordXORCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordXORCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordXORCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordXORCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordXORCipher, 4");
        return;
    }
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPasswordAddCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordAddCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordAddCipher) & CIPHER_MASK_LANE_COUNT_1) == 0U) {
        XCTFail("test_LaneCount: failed on kPasswordAddCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordAddCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordAddCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordAddCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordAddCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordAddCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordAddCipher, 4");
        return;
    }
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPasswordSubtractCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordSubtractCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordSubtractCipher) & CIPHER_MASK_LANE_COUNT_1) == 0U) {
        XCTFail("test_LaneCount: failed on kPasswordSubtractCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordSubtractCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordSubtractCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordSubtractCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordSubtractCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordSubtractCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordSubtractCipher, 4");
        return;
    }
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpXORCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpXORCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpXORCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpXORCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpXORCipher) & CIPHER_MASK_LANE_COUNT_2) == 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpXORCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpXORCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpXORCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpXORCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpXORCipher, 4");
        return;
    }
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpAddCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpAddCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpAddCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpAddCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpAddCipher) & CIPHER_MASK_LANE_COUNT_2) == 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpAddCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpAddCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpAddCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpAddCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpAddCipher, 4");
        return;
    }
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpSubtractCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpSubtractCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpSubtractCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpSubtractCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpSubtractCipher) & CIPHER_MASK_LANE_COUNT_2) == 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpSubtractCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpSubtractCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpSubtractCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPasswordJumpSubtractCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPasswordJumpSubtractCipher, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPepperNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperNoiseXORCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperNoiseXORCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_2) == 0U) {
        XCTFail("test_LaneCount: failed on kPepperNoiseXORCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperNoiseXORCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperNoiseXORCipher, 4");
        return;
    }
    
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPepperJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperJumpNoiseXORCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperJumpNoiseXORCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperJumpNoiseXORCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_3) == 0U) {
        XCTFail("test_LaneCount: failed on kPepperJumpNoiseXORCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperJumpNoiseXORCipher, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kPepperDualJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperDualJumpNoiseXORCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperDualJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperDualJumpNoiseXORCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperDualJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperDualJumpNoiseXORCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperDualJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kPepperDualJumpNoiseXORCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kPepperDualJumpNoiseXORCipher) & CIPHER_MASK_LANE_COUNT_4) == 0U) {
        XCTFail("test_LaneCount: failed on kPepperDualJumpNoiseXORCipher, 4");
        return;
    }
    
    
    
    
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kCascadeCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeCipher) & CIPHER_MASK_LANE_COUNT_1) == 0U) {
        XCTFail("test_LaneCount: failed on kCascadeCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeCipher, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kCascadeJumpCipher) & CIPHER_MASK_LANE_COUNT_0) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeJumpCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeJumpCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeJumpCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeJumpCipher) & CIPHER_MASK_LANE_COUNT_2) == 0U) {
        XCTFail("test_LaneCount: failed on kCascadeJumpCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeJumpCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeJumpCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kCascadeJumpCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kCascadeJumpCipher, 4");
        return;
    }
    
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kRotateMaskCipher) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kRotateMaskCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateMaskCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateMaskCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateMaskCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateMaskCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateMaskCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateMaskCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateMaskCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateMaskCipher, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskCipher) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskCipher, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kInvertMaskCipher) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kInvertMaskCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kInvertMaskCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kInvertMaskCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kInvertMaskCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kInvertMaskCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kInvertMaskCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kInvertMaskCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kInvertMaskCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kInvertMaskCipher, 4");
        return;
    }
    
    
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher32) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher32, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher32) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher32, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher32) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher32, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher32) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher32, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher32) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher32, 4");
        return;
    }
    
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher64) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher64, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher64) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher64, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher64) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher64, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher64) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher64, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kReverseMaskByteBlockCipher64) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kReverseMaskByteBlockCipher64, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kRotateCipher) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kRotateCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRotateCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kRotateCipher, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher32, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher32, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher32, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher32, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher32, 4");
        return;
    }
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher64, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher64, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher64, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher64, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kSplintMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kSplintMaskBlockCipher64, 4");
        return;
    }
    
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskCipher) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskCipher, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskCipher) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskCipher, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskCipher) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskCipher, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskCipher) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskCipher, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskCipher) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskCipher, 4");
        return;
    }
    
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher32, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher32, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher32, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher32, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher32, 4");
        return;
    }
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher64, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher64, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher64, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher64, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kWeaveMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kWeaveMaskBlockCipher64, 4");
        return;
    }
    
    
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher32, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher32, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher32, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher32, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher32) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher32, 4");
        return;
    }
    
    
    
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_0) == 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher64, 0");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_1) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher64, 1");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_2) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher64, 2");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_3) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher64, 3");
        return;
    }
    if ((static_cast<std::uint32_t>(CipherType::kRippleMaskBlockCipher64) & CIPHER_MASK_LANE_COUNT_4) != 0U) {
        XCTFail("test_LaneCount: failed on kRippleMaskBlockCipher64, 4");
        return;
    }
}

- (void)test_kPasswordXORCipher {
    
    if (!IS_KEY(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPasswordXORCipher)) {
        XCTFail("test_kPasswordXORCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kPasswordAddCipher {
    
    if (!IS_KEY(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPasswordAddCipher)) {
        XCTFail("test_kPasswordAddCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kPasswordSubtractCipher {
    
    if (!IS_KEY(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPasswordSubtractCipher)) {
        XCTFail("test_kPasswordSubtractCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}


- (void)test_kPasswordJumpXORCipher {
    
    if (!IS_KEY(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPasswordJumpXORCipher)) {
        XCTFail("test_kPasswordJumpXORCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kPasswordJumpAddCipher {
    
    if (!IS_KEY(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPasswordJumpAddCipher)) {
        XCTFail("test_kPasswordJumpAddCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kPasswordJumpSubtractCipher {
    
    if (!IS_KEY(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPasswordJumpSubtractCipher)) {
        XCTFail("test_kPasswordJumpSubtractCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kPepperNoiseXORCipher {
    
    if (!IS_KEY(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (!IS_KEY_COMPLEX(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPepperNoiseXORCipher)) {
        XCTFail("test_kPepperNoiseXORCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kPepperJumpNoiseXORCipher {
    
    if (!IS_KEY(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (!IS_KEY_COMPLEX(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPepperJumpNoiseXORCipher)) {
        XCTFail("test_kPepperJumpNoiseXORCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kPepperDualJumpNoiseXORCipher {
    
    if (!IS_KEY(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_KEY");
        return;
    }
    
    if (!IS_KEY_SIMPLE(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (!IS_KEY_COMPLEX(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kPepperDualJumpNoiseXORCipher)) {
        XCTFail("test_kPepperDualJumpNoiseXORCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kCascadeCipher {
    
    if (!IS_KEY(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (!IS_KEY_COMPLEX(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kCascadeCipher)) {
        XCTFail("test_kCascadeCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kCascadeJumpCipher {
    
    if (!IS_KEY(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (!IS_KEY_COMPLEX(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (IS_MOVER_ANY(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kCascadeJumpCipher)) {
        XCTFail("test_kCascadeJumpCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kRippleMaskBlockCipher32 {
    
    if (IS_KEY(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_MOVER_ANY");
        return;
    }
    
    if (!IS_MOVER_SECONDARY(CipherType::kRippleMaskBlockCipher32)) {
        XCTFail("test_kRippleMaskBlockCipher32: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kRippleMaskBlockCipher64 {
    
    if (IS_KEY(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_MOVER_ANY");
        return;
    }
    
    if (!IS_MOVER_SECONDARY(CipherType::kRippleMaskBlockCipher64)) {
        XCTFail("test_kRippleMaskBlockCipher64: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kInvertMaskCipher {
    
    if (IS_KEY(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kInvertMaskCipher)) {
        XCTFail("test_kInvertMaskCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kReverseMaskCipher {
    
    if (IS_KEY(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kReverseMaskCipher)) {
        XCTFail("test_kReverseMaskCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kReverseMaskByteBlockCipher32 {
    
    if (IS_KEY(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_MOVER_ANY");
        return;
    }
    
    if (!IS_MOVER_SECONDARY(CipherType::kReverseMaskByteBlockCipher32)) {
        XCTFail("test_kReverseMaskByteBlockCipher32: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kReverseMaskByteBlockCipher64 {
    
    if (IS_KEY(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_MOVER_ANY");
        return;
    }
    
    if (!IS_MOVER_SECONDARY(CipherType::kReverseMaskByteBlockCipher64)) {
        XCTFail("test_kReverseMaskByteBlockCipher64: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kSplintMaskBlockCipher32 {
    
    if (IS_KEY(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_MOVER_ANY");
        return;
    }
    
    if (!IS_MOVER_SECONDARY(CipherType::kSplintMaskBlockCipher32)) {
        XCTFail("test_kSplintMaskBlockCipher32: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kSplintMaskBlockCipher64 {
    
    if (IS_KEY(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_MOVER_ANY");
        return;
    }
    
    if (!IS_MOVER_SECONDARY(CipherType::kSplintMaskBlockCipher64)) {
        XCTFail("test_kSplintMaskBlockCipher64: failed on IS_MOVER_SECONDARY");
        return;
    }
}


- (void)test_kRotateMaskCipher {
    
    if (IS_KEY(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kRotateMaskCipher)) {
        XCTFail("test_kRotateMaskCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kRotateCipher {
    
    if (IS_KEY(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_WANDERER(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kRotateCipher)) {
        XCTFail("test_kRotateCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}


- (void)test_kWeaveMaskCipher {
    
    if (IS_KEY(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kWeaveMaskCipher)) {
        XCTFail("test_kWeaveMaskCipher: failed on IS_MOVER_SECONDARY");
        return;
    }
}

- (void)test_kWeaveMaskBlockCipher32 {
    
    if (IS_KEY(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kWeaveMaskBlockCipher32)) {
        XCTFail("test_kWeaveMaskBlockCipher32: failed on IS_MOVER_SECONDARY");
        return;
    }
    
}

- (void)test_kWeaveMaskBlockCipher64 {
    
    if (IS_KEY(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_KEY");
        return;
    }
    
    if (IS_KEY_SIMPLE(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_KEY_SIMPLE");
        return;
    }
    
    if (IS_KEY_COMPLEX(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_KEY_COMPLEX");
        return;
    }
    
    if (IS_MOVER_NON_ROTATION_NON_WANDERER(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_MOVER_NON_ROTATION_NON_WANDERER");
        return;
    }
    
    if (IS_MOVER_NON_WANDERER(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_MOVER_NON_WANDERER");
        return;
    }
    
    if (!IS_MOVER_NON_ROTATION(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_MOVER_NON_ROTATION");
        return;
    }
    
    if (!IS_MOVER_ANY(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_MOVER_ANY");
        return;
    }
    
    if (IS_MOVER_SECONDARY(CipherType::kWeaveMaskBlockCipher64)) {
        XCTFail("test_kWeaveMaskBlockCipher64: failed on IS_MOVER_SECONDARY");
        return;
    }
    
}

@end
