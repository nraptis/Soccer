//
//  SoccerRotationBankIITests.mm
//  ScrambleTests
//
//  Created by Codex on 8/7/26.
//

#import <XCTest/XCTest.h>
#include "Soccer2.hpp"
#include "SoccerRotationBank.hpp"
#include <cstdint>

namespace {

constexpr std::int32_t kRotationLowS1 = 257;
constexpr std::int32_t kRotationHighS1 = 261888;

constexpr std::int32_t kRotationLowS2 = 262401;
constexpr std::int32_t kRotationHighS2 = 524032;

constexpr std::int32_t kRotationLowS3 = 524545;
constexpr std::int32_t kRotationHighS3 = 1048320;

bool IsRotationS1(std::int32_t pRotation) {
    return (pRotation >= kRotationLowS1) && (pRotation < kRotationHighS1);
}

bool IsRotationS2(std::int32_t pRotation) {
    return (pRotation >= kRotationLowS2) && (pRotation < kRotationHighS2);
}

bool IsRotationS3(std::int32_t pRotation) {
    return (pRotation >= kRotationLowS3) && (pRotation < kRotationHighS3);
}

void PrepareRotationSeeds() {
    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = static_cast<std::uint64_t>(aIndex * 512U);
    }
    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = static_cast<std::uint64_t>(aIndex * 512U);
    }
    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = static_cast<std::uint64_t>(aIndex * 512U);
    }
}

} // namespace

@interface SoccerRotationBankIITests : XCTestCase

@end

@implementation SoccerRotationBankIITests

- (void)test_OneRotationPerSize {
    PrepareRotationSeeds();

    SoccerRotationBankRequest aRequest;
    aRequest.mL3A = SoccerRotationCount::kOne;
    aRequest.mL2A = SoccerRotationCount::kOne;
    aRequest.mL1A = SoccerRotationCount::kOne;

    const SoccerRotationBankResponse aResponse = SoccerRotationBank::Withdraw(aRequest);

    if ((SoccerRotationBank::mCacheCountS3 != 1U) ||
        (SoccerRotationBank::mCacheCountS2 != 1U) ||
        (SoccerRotationBank::mCacheCountS1 != 1U)) {
        XCTFail("test_OneRotationPerSize: expected S3(1), S2(1), S1(1), got S3(%zu), S2(%zu), S1(%zu).",
                SoccerRotationBank::mCacheCountS3,
                SoccerRotationBank::mCacheCountS2,
                SoccerRotationBank::mCacheCountS1);
        return;
    }

    if (!IsRotationS3(aResponse.mAmountL3A[0])) {
        XCTFail("test_OneRotationPerSize: L3A rotation was outside the S3 range (amount = %d).", aResponse.mAmountL3A[0]);
        return;
    }
    if (!IsRotationS2(aResponse.mAmountL2A[0])) {
        XCTFail("test_OneRotationPerSize: L2A rotation was outside the S2 range (amount = %d).", aResponse.mAmountL2A[0]);
        return;
    }
    if (!IsRotationS1(aResponse.mAmountL1A[0])) {
        XCTFail("test_OneRotationPerSize: L1A rotation was outside the S1 range (amount = %d).", aResponse.mAmountL1A[0]);
        return;
    }

    if ((aResponse.mAmountL3A[1] != 0) ||
        (aResponse.mAmountL2A[1] != 0) ||
        (aResponse.mAmountL1A[1] != 0)) {
        XCTFail("test_OneRotationPerSize: expected unused response entries to remain zero.");
        return;
    }
}

- (void)test_TwoRotationsPerSize {
    PrepareRotationSeeds();

    SoccerRotationBankRequest aRequest;
    aRequest.mL3A = SoccerRotationCount::kTwo;
    aRequest.mL2B = SoccerRotationCount::kTwo;
    aRequest.mL1B = SoccerRotationCount::kTwo;

    const SoccerRotationBankResponse aResponse = SoccerRotationBank::Withdraw(aRequest);

    if ((SoccerRotationBank::mCacheCountS3 != 2U) ||
        (SoccerRotationBank::mCacheCountS2 != 2U) ||
        (SoccerRotationBank::mCacheCountS1 != 2U)) {
        XCTFail("test_TwoRotationsPerSize: expected S3(2), S2(2), S1(2), got S3(%zu), S2(%zu), S1(%zu).",
                SoccerRotationBank::mCacheCountS3,
                SoccerRotationBank::mCacheCountS2,
                SoccerRotationBank::mCacheCountS1);
        return;
    }

    for (std::size_t aIndex=0U; aIndex<2U; aIndex++) {
        if (!IsRotationS3(aResponse.mAmountL3A[aIndex])) {
            XCTFail("test_TwoRotationsPerSize: L3A[%zu] was outside the S3 range (amount = %d).", aIndex, aResponse.mAmountL3A[aIndex]);
            return;
        }
        if (!IsRotationS2(aResponse.mAmountL2B[aIndex])) {
            XCTFail("test_TwoRotationsPerSize: L2B[%zu] was outside the S2 range (amount = %d).", aIndex, aResponse.mAmountL2B[aIndex]);
            return;
        }
        if (!IsRotationS1(aResponse.mAmountL1B[aIndex])) {
            XCTFail("test_TwoRotationsPerSize: L1B[%zu] was outside the S1 range (amount = %d).", aIndex, aResponse.mAmountL1B[aIndex]);
            return;
        }
    }

    if ((aResponse.mAmountL3A[2] != 0) ||
        (aResponse.mAmountL2B[2] != 0) ||
        (aResponse.mAmountL1B[2] != 0)) {
        XCTFail("test_TwoRotationsPerSize: expected unused response entries to remain zero.");
        return;
    }
}

- (void)test_ThreeRotationsPerSizeAcrossStages {
    PrepareRotationSeeds();

    SoccerRotationBankRequest aRequest;
    aRequest.mL3A = SoccerRotationCount::kOne;
    aRequest.mL3B = SoccerRotationCount::kOne;
    aRequest.mL3C = SoccerRotationCount::kOne;

    aRequest.mL2A = SoccerRotationCount::kOne;
    aRequest.mL2B = SoccerRotationCount::kTwo;

    aRequest.mL1A = SoccerRotationCount::kTwo;
    aRequest.mL1B = SoccerRotationCount::kOne;

    const SoccerRotationBankResponse aResponse = SoccerRotationBank::Withdraw(aRequest);

    if ((SoccerRotationBank::mCacheCountS3 != 3U) ||
        (SoccerRotationBank::mCacheCountS2 != 3U) ||
        (SoccerRotationBank::mCacheCountS1 != 3U)) {
        XCTFail("test_ThreeRotationsPerSizeAcrossStages: expected S3(3), S2(3), S1(3), got S3(%zu), S2(%zu), S1(%zu).",
                SoccerRotationBank::mCacheCountS3,
                SoccerRotationBank::mCacheCountS2,
                SoccerRotationBank::mCacheCountS1);
        return;
    }

    if (!IsRotationS3(aResponse.mAmountL3A[0]) ||
        !IsRotationS3(aResponse.mAmountL3B[0]) ||
        !IsRotationS3(aResponse.mAmountL3C[0])) {
        XCTFail("test_ThreeRotationsPerSizeAcrossStages: one of the L3 stage rotations was outside the S3 range.");
        return;
    }

    if (!IsRotationS2(aResponse.mAmountL2A[0]) ||
        !IsRotationS2(aResponse.mAmountL2B[0]) ||
        !IsRotationS2(aResponse.mAmountL2B[1])) {
        XCTFail("test_ThreeRotationsPerSizeAcrossStages: one of the L2 stage rotations was outside the S2 range.");
        return;
    }

    if (!IsRotationS1(aResponse.mAmountL1A[0]) ||
        !IsRotationS1(aResponse.mAmountL1A[1]) ||
        !IsRotationS1(aResponse.mAmountL1B[0])) {
        XCTFail("test_ThreeRotationsPerSizeAcrossStages: one of the L1 stage rotations was outside the S1 range.");
        return;
    }

    if ((aResponse.mAmountL3A[0] != SoccerRotationBank::mCacheDataS3[0]) ||
        (aResponse.mAmountL3B[0] != SoccerRotationBank::mCacheDataS3[1]) ||
        (aResponse.mAmountL3C[0] != SoccerRotationBank::mCacheDataS3[2])) {
        XCTFail("test_ThreeRotationsPerSizeAcrossStages: S3 response ordering did not match the cache ordering.");
        return;
    }

    if ((aResponse.mAmountL2A[0] != SoccerRotationBank::mCacheDataS2[0]) ||
        (aResponse.mAmountL2B[0] != SoccerRotationBank::mCacheDataS2[1]) ||
        (aResponse.mAmountL2B[1] != SoccerRotationBank::mCacheDataS2[2])) {
        XCTFail("test_ThreeRotationsPerSizeAcrossStages: S2 response ordering did not match the cache ordering.");
        return;
    }

    if ((aResponse.mAmountL1A[0] != SoccerRotationBank::mCacheDataS1[0]) ||
        (aResponse.mAmountL1A[1] != SoccerRotationBank::mCacheDataS1[1]) ||
        (aResponse.mAmountL1B[0] != SoccerRotationBank::mCacheDataS1[2])) {
        XCTFail("test_ThreeRotationsPerSizeAcrossStages: S1 response ordering did not match the cache ordering.");
        return;
    }
}

@end
