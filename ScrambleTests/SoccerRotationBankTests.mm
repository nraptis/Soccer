//
//  SoccerRotationBankTests.m
//  ScrambleTests
//
//  Created by nick on 8/7/26.
//

#import <XCTest/XCTest.h>
#include "Soccer2.hpp"
#include "SoccerRotationBank.hpp"
#include "LaneTool.hpp"
#include "Random.hpp"
#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_set>


@interface SoccerRotationBankTests : XCTestCase

@end

@implementation SoccerRotationBankTests

- (void)test_RotationEWithZero {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    memset(Soccer2::mRotationSeedS3, 0, sizeof(Soccer2::mRotationSeedS3));
    memset(Soccer2::mRotationSeedS2, 0, sizeof(Soccer2::mRotationSeedS2));
    memset(Soccer2::mRotationSeedS1, 0, sizeof(Soccer2::mRotationSeedS1));

    SoccerRotationBank::Withdraw_PassE(SOCCER_ROTATION_CACHE_COUNT_S3, SOCCER_ROTATION_CACHE_COUNT_S2, SOCCER_ROTATION_CACHE_COUNT_S1);

    if ((SoccerRotationBank::mCacheCountS3 != 4U) ||
        (SoccerRotationBank::mCacheCountS2 != 4U) ||
        (SoccerRotationBank::mCacheCountS1 != 4U)) {
        XCTFail("test_RotationEWithZero: expected S3(4), S2(4), S1(4), got S3(%zu), S2(%zu), S1(%zu).",
                SoccerRotationBank::mCacheCountS3,
                SoccerRotationBank::mCacheCountS2,
                SoccerRotationBank::mCacheCountS1);
        return;
    }

    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[E Zeros] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[E Zeros] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[E Zeros] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_RotationFailAWithZero {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    memset(Soccer2::mRotationSeedS3, 0, sizeof(Soccer2::mRotationSeedS3));
    memset(Soccer2::mRotationSeedS2, 0, sizeof(Soccer2::mRotationSeedS2));
    memset(Soccer2::mRotationSeedS1, 0, sizeof(Soccer2::mRotationSeedS1));
    
    if (SoccerRotationBank::Withdraw_PassA(4, 4, 4)) {
        XCTFail("test_RotationFailAWithZero: Withdraw_PassA unexpectedly passed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S2),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S1));
        return;
    }
}

- (void)test_RotationFailBWithZero {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    memset(Soccer2::mRotationSeedS3, 0, sizeof(Soccer2::mRotationSeedS3));
    memset(Soccer2::mRotationSeedS2, 0, sizeof(Soccer2::mRotationSeedS2));
    memset(Soccer2::mRotationSeedS1, 0, sizeof(Soccer2::mRotationSeedS1));
    
    if (SoccerRotationBank::Withdraw_PassB(4, 4, 4)) {
        XCTFail("test_RotationFailBWithZero: Withdraw_PassB unexpectedly passed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S2),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S1));
        return;
    }
}

- (void)test_RotationFailCWithZero {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    memset(Soccer2::mRotationSeedS3, 0, sizeof(Soccer2::mRotationSeedS3));
    memset(Soccer2::mRotationSeedS2, 0, sizeof(Soccer2::mRotationSeedS2));
    memset(Soccer2::mRotationSeedS1, 0, sizeof(Soccer2::mRotationSeedS1));
    
    if (SoccerRotationBank::Withdraw_PassC(4, 4, 4)) {
        XCTFail("test_RotationFailCWithZero: Withdraw_PassC unexpectedly passed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S2),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S1));
        return;
    }

}

- (void)test_RotationFailDWithZero {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    memset(Soccer2::mRotationSeedS3, 0, sizeof(Soccer2::mRotationSeedS3));
    memset(Soccer2::mRotationSeedS2, 0, sizeof(Soccer2::mRotationSeedS2));
    memset(Soccer2::mRotationSeedS1, 0, sizeof(Soccer2::mRotationSeedS1));
    
    if (SoccerRotationBank::Withdraw_PassD(4, 4, 4)) {
        XCTFail("test_RotationFailDWithZero: Withdraw_PassD unexpectedly passed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S2),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S1));
        return;
    }
    
}

- (void)test_RotationFailAWithTinyStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex;
    }
    
    if (SoccerRotationBank::Withdraw_PassA(4, 4, 4)) {
        XCTFail("test_RotationFailAWithTinyStairs: Withdraw_PassA unexpectedly passed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S2),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S1));
        return;
    }
}

- (void)test_RotationPassBWithTinyStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex;
    }
    
    if (!SoccerRotationBank::Withdraw_PassB(4, 2, 2)) {
        XCTFail("test_RotationPassBWithTinyStairs: Withdraw_PassB unexpectedly failed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(2U),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(2U));
        return;
    }

    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[B Tiny Stairs] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[B Tiny Stairs] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[B Tiny Stairs] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_RotationPassCWithTinyStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex;
    }
    
    if (!SoccerRotationBank::Withdraw_PassC(4, 2, 2)) {
        XCTFail("test_RotationPassCWithTinyStairs: Withdraw_PassC unexpectedly failed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(2U),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(2U));
        return;
    }

    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[C Tiny Stairs] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[C Tiny Stairs] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[C Tiny Stairs] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_RotationPassDWithTinyStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex;
    }

    if (!SoccerRotationBank::Withdraw_PassD(4, 2, 2)) {
        XCTFail("test_RotationPassDWithTinyStairs: Withdraw_PassD unexpectedly failed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(2U),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(2U));
        return;
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[D Tiny Stairs] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[D Tiny Stairs] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[D Tiny Stairs] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_RotationPassAWithMediumStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex * 512;
    }
    
    if (!SoccerRotationBank::Withdraw_PassA(4, 4, 4)) {
        XCTFail("test_RotationPassAWithMediumStairs: Withdraw_PassA unexpectedly passed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S2),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S1));
        return;
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[A Medium Stairs] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[A Medium Stairs] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[A Medium Stairs] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_RotationPassBWithMediumStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex * 512;
    }
    
    if (!SoccerRotationBank::Withdraw_PassB(4, 2, 2)) {
        XCTFail("test_RotationPassBWithMediumStairs: Withdraw_PassB unexpectedly failed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(2U),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(2U));
        return;
    }


    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[B Medium Stairs] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[B Medium Stairs] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[B Medium Stairs] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_RotationPassCWithMediumStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex * 512;
    }
    
    if (!SoccerRotationBank::Withdraw_PassC(4, 2, 2)) {
        XCTFail("test_RotationPassCWithMediumStairs: Withdraw_PassC unexpectedly failed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(2U),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(2U));
        return;
    }

    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[C Medium Stairs] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[C Medium Stairs] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[C Medium Stairs] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_RotationPassDWithMediumStairs {
    
    SoccerRotationBank::mCursorS3 = 0;
    SoccerRotationBank::mCursorS2 = 0;
    SoccerRotationBank::mCursorS1 = 0;
    
    SoccerRotationBank::mCacheCountS1 = 0;
    SoccerRotationBank::mCacheCountS2 = 0;
    SoccerRotationBank::mCacheCountS3 = 0;
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        Soccer2::mRotationSeedS3[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        Soccer2::mRotationSeedS2[aIndex] = aIndex * 512;
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        Soccer2::mRotationSeedS1[aIndex] = aIndex * 512;
    }

    if (!SoccerRotationBank::Withdraw_PassD(4, 2, 2)) {
        XCTFail("test_RotationPassDWithMediumStairs: Withdraw_PassD unexpectedly failed; filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu).",
                SoccerRotationBank::mCacheCountS3, static_cast<std::size_t>(SOCCER_ROTATION_CACHE_COUNT_S3),
                SoccerRotationBank::mCacheCountS2, static_cast<std::size_t>(2U),
                SoccerRotationBank::mCacheCountS1, static_cast<std::size_t>(2U));
        return;
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        printf("[D Medium Stairs] Rotation S3: %d\n", SoccerRotationBank::mCacheDataS3[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        printf("[D Medium Stairs] Rotation S2: %d\n", SoccerRotationBank::mCacheDataS2[aIndex]);
    }
    
    for (std::size_t aIndex=0; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        printf("[D Medium Stairs] Rotation S1: %d\n", SoccerRotationBank::mCacheDataS1[aIndex]);
    }
}

- (void)test_TwelveRotationCombinationsWithZeroSeeds {

    memset(Soccer2::mRotationSeedS3, 0, sizeof(Soccer2::mRotationSeedS3));
    memset(Soccer2::mRotationSeedS2, 0, sizeof(Soccer2::mRotationSeedS2));
    memset(Soccer2::mRotationSeedS1, 0, sizeof(Soccer2::mRotationSeedS1));

    SoccerRotationBankRequest aRequest;
    aRequest.mL3A = SoccerRotationCount::kFour;
    aRequest.mL2A = SoccerRotationCount::kFour;
    aRequest.mL1A = SoccerRotationCount::kFour;

    const SoccerRotationBankResponse aResponse = SoccerRotationBank::Withdraw(aRequest);

    if ((SoccerRotationBank::mCacheCountS3 != 4U) ||
        (SoccerRotationBank::mCacheCountS2 != 4U) ||
        (SoccerRotationBank::mCacheCountS1 != 4U)) {
        XCTFail("test_TwelveRotationCombinationsWithZeroSeeds: expected S3(4), S2(4), S1(4), got S3(%zu), S2(%zu), S1(%zu).",
                SoccerRotationBank::mCacheCountS3,
                SoccerRotationBank::mCacheCountS2,
                SoccerRotationBank::mCacheCountS1);
        return;
    }

    for (std::size_t aIndex=0U; aIndex<4U; aIndex++) {
        if ((aResponse.mAmountL3A[aIndex] != SoccerRotationBank::mCacheDataS3[aIndex]) ||
            (aResponse.mAmountL2A[aIndex] != SoccerRotationBank::mCacheDataS2[aIndex]) ||
            (aResponse.mAmountL1A[aIndex] != SoccerRotationBank::mCacheDataS1[aIndex])) {
            XCTFail("test_TwelveRotationCombinationsWithZeroSeeds: response did not contain cached rotation %zu.", aIndex);
            return;
        }
    }

    std::int32_t aRotations[SOCCER_ROTATION_CACHE_COUNT_TOTAL];
    std::size_t aRotationIndex = 0U;
    for (std::size_t aIndex=0U; aIndex<SoccerRotationBank::mCacheCountS3; aIndex++) {
        aRotations[aRotationIndex++] = SoccerRotationBank::mCacheDataS3[aIndex];
    }
    for (std::size_t aIndex=0U; aIndex<SoccerRotationBank::mCacheCountS2; aIndex++) {
        aRotations[aRotationIndex++] = SoccerRotationBank::mCacheDataS2[aIndex];
    }
    for (std::size_t aIndex=0U; aIndex<SoccerRotationBank::mCacheCountS1; aIndex++) {
        aRotations[aRotationIndex++] = SoccerRotationBank::mCacheDataS1[aIndex];
    }

    for (std::size_t aIndex=0U; aIndex<aRotationIndex; aIndex++) {
        if (SoccerRotationBank::BoundariesContend(aRotations[aIndex])) {
            XCTFail("test_TwelveRotationCombinationsWithZeroSeeds: rotation %zu contends with a boundary (amount = %d).",
                    aIndex,
                    aRotations[aIndex]);
            return;
        }

        for (std::size_t aOtherIndex=0U; aOtherIndex<aIndex; aOtherIndex++) {
            if (SoccerRotationBank::RotationsContend(aRotations[aIndex], aRotations[aOtherIndex])) {
                XCTFail("test_TwelveRotationCombinationsWithZeroSeeds: rotations %zu and %zu contend (amounts = %d, %d).",
                        aIndex,
                        aOtherIndex,
                        aRotations[aIndex],
                        aRotations[aOtherIndex]);
                return;
            }
        }
    }

    SoccerRotationBank::mCacheCountS3 = 0U;
    SoccerRotationBank::mCacheCountS2 = 0U;
    SoccerRotationBank::mCacheCountS1 = 0U;

    for (std::size_t aIndex=0U; aIndex<aRotationIndex; aIndex++) {
        if (SoccerRotationBank::ContendWithAnything(aRotations[aIndex])) {
            XCTFail("test_TwelveRotationCombinationsWithZeroSeeds: dynamic combination scan rejected rotation %zu (amount = %d).",
                    aIndex,
                    aRotations[aIndex]);
            return;
        }

        if (aIndex < 4U) {
            SoccerRotationBank::CacheRotation(SoccerRotationBank::RotationSize::kS3, aRotations[aIndex]);
        } else if (aIndex < 8U) {
            SoccerRotationBank::CacheRotation(SoccerRotationBank::RotationSize::kS2, aRotations[aIndex]);
        } else {
            SoccerRotationBank::CacheRotation(SoccerRotationBank::RotationSize::kS1, aRotations[aIndex]);
        }
    }
}

@end
