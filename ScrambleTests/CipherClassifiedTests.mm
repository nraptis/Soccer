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

- (void)test_Classifications {
    struct ClassificationExpectation {
        CipherType mType;
        const char *mName;
        bool mLepton;
        bool mBoson;
        bool mHadron;
        bool mBaryon;
        bool mFermion;
        bool mMeson;
        bool mMuon;
        bool mQuasiparticle;
        bool mNeutrino;
    };

    const ClassificationExpectation aExpectations[] = {
        { CipherType::kNone,                         "kNone",                         false, false, false, false, false, false, false, false, false },

        { CipherType::kPasswordXORCipher,            "kPasswordXORCipher",            true,  false, true,  false, false, false, false, false, false },
        { CipherType::kPasswordAddCipher,            "kPasswordAddCipher",            true,  false, true,  false, false, false, false, false, false },
        { CipherType::kPasswordSubtractCipher,       "kPasswordSubtractCipher",       true,  false, true,  false, false, false, false, false, false },

        { CipherType::kPasswordJumpXORCipher,        "kPasswordJumpXORCipher",        true,  true,  true,  false, false, false, false, false, false },
        { CipherType::kPasswordJumpAddCipher,        "kPasswordJumpAddCipher",        true,  true,  true,  false, false, false, false, false, false },
        { CipherType::kPasswordJumpSubtractCipher,   "kPasswordJumpSubtractCipher",   true,  true,  true,  false, false, false, false, false, false },

        { CipherType::kPepperNoiseXORCipher,         "kPepperNoiseXORCipher",         true,  true,  true,  false, false, false, false, false, false },
        { CipherType::kPepperJumpNoiseXORCipher,     "kPepperJumpNoiseXORCipher",     true,  true,  true,  false, false, false, false, false, false },
        { CipherType::kPepperDualJumpNoiseXORCipher, "kPepperDualJumpNoiseXORCipher", true,  true,  true,  false, false, false, false, false, false },

        { CipherType::kCascadeCipher,                "kCascadeCipher",                false, true,  true,  false, false, false, false, false, false },
        { CipherType::kCascadeJumpCipher,            "kCascadeJumpCipher",            false, true,  true,  false, false, false, false, false, false },

        { CipherType::kRotateMaskCipher,             "kRotateMaskCipher",             false, false, false, true,  false, true,  false, false, false },
        { CipherType::kRotateCipher,                 "kRotateCipher",                 false, false, false, false, true,  true,  false, false, false },

        { CipherType::kInvertMaskCipher,             "kInvertMaskCipher",             false, false, false, false, false, false, true,  false, true  },
        { CipherType::kReverseMaskCipher,            "kReverseMaskCipher",            false, false, false, false, false, false, true,  false, true  },
        { CipherType::kSplintMaskBlockCipher32,      "kSplintMaskBlockCipher32",      false, false, false, false, false, false, true,  false, true  },
        { CipherType::kSplintMaskBlockCipher64,      "kSplintMaskBlockCipher64",      false, false, false, false, false, false, true,  false, true  },

        { CipherType::kReverseMaskByteBlockCipher32, "kReverseMaskByteBlockCipher32", false, false, false, false, false, false, false, true,  true  },
        { CipherType::kReverseMaskByteBlockCipher64, "kReverseMaskByteBlockCipher64", false, false, false, false, false, false, false, true,  true  },
        { CipherType::kRippleMaskBlockCipher32,      "kRippleMaskBlockCipher32",      false, false, false, false, false, false, false, true,  true  },
        { CipherType::kRippleMaskBlockCipher64,      "kRippleMaskBlockCipher64",      false, false, false, false, false, false, false, true,  true  },
    };

    for (const ClassificationExpectation &aExpectation : aExpectations) {
        if (IS_LEPTON(aExpectation.mType) != aExpectation.mLepton) {
            XCTFail("test_Classifications: %s failed IS_LEPTON.", aExpectation.mName);
            return;
        }
        if (IS_BOSON(aExpectation.mType) != aExpectation.mBoson) {
            XCTFail("test_Classifications: %s failed IS_BOSON.", aExpectation.mName);
            return;
        }
        if (IS_HADRON(aExpectation.mType) != aExpectation.mHadron) {
            XCTFail("test_Classifications: %s failed IS_HADRON.", aExpectation.mName);
            return;
        }
        if (IS_BARYON(aExpectation.mType) != aExpectation.mBaryon) {
            XCTFail("test_Classifications: %s failed IS_BARYON.", aExpectation.mName);
            return;
        }
        if (IS_FERMION(aExpectation.mType) != aExpectation.mFermion) {
            XCTFail("test_Classifications: %s failed IS_FERMION.", aExpectation.mName);
            return;
        }
        if (IS_MESON(aExpectation.mType) != aExpectation.mMeson) {
            XCTFail("test_Classifications: %s failed IS_MESON.", aExpectation.mName);
            return;
        }
        if (IS_MUON(aExpectation.mType) != aExpectation.mMuon) {
            XCTFail("test_Classifications: %s failed IS_MUON.", aExpectation.mName);
            return;
        }
        if (IS_QUASIPARTICLE(aExpectation.mType) != aExpectation.mQuasiparticle) {
            XCTFail("test_Classifications: %s failed IS_QUASIPARTICLE.", aExpectation.mName);
            return;
        }
        if (IS_NEUTRINO(aExpectation.mType) != aExpectation.mNeutrino) {
            XCTFail("test_Classifications: %s failed IS_NEUTRINO.", aExpectation.mName);
            return;
        }
    }
}

@end
