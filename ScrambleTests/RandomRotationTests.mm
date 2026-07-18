//
//  RandomRotationTests.m
//  ScrambleTests
//
//  Created by icarus black on 7/8/26.
//

#import <XCTest/XCTest.h>

#include "Random.hpp"
#include "Soccer.hpp"

#include "TwistMix64.hpp"

#include <cstdint>
#include <cstring>
#include <vector>

@interface RandomRotationTests : XCTestCase

@end

@implementation RandomRotationTests

std::uint64_t Read64(const std::uint8_t *pSource) {
    return static_cast<std::uint64_t>(pSource[0]) |
    (static_cast<std::uint64_t>(pSource[1]) << 8) |
    (static_cast<std::uint64_t>(pSource[2]) << 16) |
    (static_cast<std::uint64_t>(pSource[3]) << 24) |
    (static_cast<std::uint64_t>(pSource[4]) << 32) |
    (static_cast<std::uint64_t>(pSource[5]) << 40) |
    (static_cast<std::uint64_t>(pSource[6]) << 48) |
    (static_cast<std::uint64_t>(pSource[7]) << 56);
}

- (void)testRandomRotations {
    
    std::uint8_t mRandom[S_BLOCK];
    
    
    for (int aTestIndex=0; aTestIndex<10000000; aTestIndex++) {
        
        if ((aTestIndex % 10000) == 0) {
            printf("test %d\n", aTestIndex);
        }
        
        for (std::size_t aRandIndex=8192; aRandIndex<(8192 + 256); aRandIndex++) {
            mRandom[aRandIndex] = Random::GetByte();
        }
        
        std::size_t aRotStartIndex = 8192;
        
        std::uint64_t aRandL1AA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +   0]));
        std::uint64_t aRandL1AB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +   8]));
        std::uint64_t aRandL1AC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  16]));
        std::uint64_t aRandL1AD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  24]));
        
        std::uint64_t aRandL1BA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  32]));
        std::uint64_t aRandL1BB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  40]));
        std::uint64_t aRandL1BC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  48]));
        std::uint64_t aRandL1BD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  56]));
        
        std::uint64_t aRandL2AA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  64]));
        std::uint64_t aRandL2AB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  72]));
        std::uint64_t aRandL2AC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  80]));
        std::uint64_t aRandL2AD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  88]));
        
        std::uint64_t aRandL2BA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex +  96]));
        std::uint64_t aRandL2BB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 104]));
        std::uint64_t aRandL2BC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 112]));
        std::uint64_t aRandL2BD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 120]));
        
        std::uint64_t aRandL3AA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 128]));
        std::uint64_t aRandL3AB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 136]));
        std::uint64_t aRandL3AC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 144]));
        std::uint64_t aRandL3AD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 152]));
        
        std::uint64_t aRandL3BA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 160]));
        std::uint64_t aRandL3BB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 168]));
        std::uint64_t aRandL3BC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 176]));
        std::uint64_t aRandL3BD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 184]));
        
        std::uint64_t aRandFinalAA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 192]));
        std::uint64_t aRandFinalAB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 200]));
        std::uint64_t aRandFinalAC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 208]));
        std::uint64_t aRandFinalAD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 216]));
        
        std::uint64_t aRandFinalBA = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 224]));
        std::uint64_t aRandFinalBB = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 232]));
        std::uint64_t aRandFinalBC = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 240]));
        std::uint64_t aRandFinalBD = TwistMix64::DiffuseA(Read64(&mRandom[aRotStartIndex + 248]));
        
        
        std::uint64_t aRotWordL1AA = ((aRandL1AA >> 16) & (  8192ULL - 1ULL));
        std::uint64_t aRotWordL1AB = ((aRandL1AB >> 16) & ( 16384ULL - 1ULL));
        std::uint64_t aRotWordL1AC = ((aRandL1AC >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordL1AD = ((aRandL1AD >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotSpanL1A = (aRotWordL1AA + aRotWordL1AB + aRotWordL1AC + aRotWordL1AD);
        
        std::uint64_t aRotWordL1BA = ((aRandL1BA >> 16) & (  8192ULL - 1ULL));
        std::uint64_t aRotWordL1BB = ((aRandL1BB >> 16) & ( 16384ULL - 1ULL));
        std::uint64_t aRotWordL1BC = ((aRandL1BC >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordL1BD = ((aRandL1BD >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotSpanL1B = (aRotWordL1BA + aRotWordL1BB + aRotWordL1BC + aRotWordL1BD);
        
        
        std::uint64_t aRotWordL2AA = ((aRandL2AA >> 16) & ( 16384ULL - 1ULL));
        std::uint64_t aRotWordL2AB = ((aRandL2AB >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordL2AC = ((aRandL2AC >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotWordL2AD = ((aRandL2AD >> 16) & (131072ULL - 1ULL));
        std::uint64_t aRotSpanL2A = (aRotWordL2AA + aRotWordL2AB + aRotWordL2AC + aRotWordL2AD);
        
        std::uint64_t aRotWordL2BA = ((aRandL2BA >> 16) & ( 16384ULL - 1ULL));
        std::uint64_t aRotWordL2BB = ((aRandL2BB >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordL2BC = ((aRandL2BC >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotWordL2BD = ((aRandL2BD >> 16) & (131072ULL - 1ULL));
        std::uint64_t aRotSpanL2B = (aRotWordL2BA + aRotWordL2BB + aRotWordL2BC + aRotWordL2BD);
        
        std::uint64_t aRotWordL3AA = ((aRandL3AA >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordL3AB = ((aRandL3AB >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotWordL3AC = ((aRandL3AC >> 16) & (131072ULL - 1ULL));
        std::uint64_t aRotWordL3AD = ((aRandL3AD >> 16) & (262144ULL - 1ULL));
        std::uint64_t aRotSpanL3A = (aRotWordL3AA + aRotWordL3AB + aRotWordL3AC + aRotWordL3AD);
        
        std::uint64_t aRotWordL3BA = ((aRandL3BA >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordL3BB = ((aRandL3BB >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotWordL3BC = ((aRandL3BC >> 16) & (131072ULL - 1ULL));
        std::uint64_t aRotWordL3BD = ((aRandL3BD >> 16) & (262144ULL - 1ULL));
        std::uint64_t aRotSpanL3B = (aRotWordL3BA + aRotWordL3BB + aRotWordL3BC + aRotWordL3BD);
        
        std::uint64_t aRotWordFinalAA = ((aRandFinalAA >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordFinalAB = ((aRandFinalAB >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotWordFinalAC = ((aRandFinalAC >> 16) & (131072ULL - 1ULL));
        std::uint64_t aRotWordFinalAD = ((aRandFinalAD >> 16) & (262144ULL - 1ULL));
        std::uint64_t aRotSpanFinalA = (aRotWordFinalAA + aRotWordFinalAB + aRotWordFinalAC + aRotWordFinalAD);
        
        std::uint64_t aRotWordFinalBA = ((aRandFinalBA >> 16) & ( 32768ULL - 1ULL));
        std::uint64_t aRotWordFinalBB = ((aRandFinalBB >> 16) & ( 65536ULL - 1ULL));
        std::uint64_t aRotWordFinalBC = ((aRandFinalBC >> 16) & (131072ULL - 1ULL));
        std::uint64_t aRotWordFinalBD = ((aRandFinalBD >> 16) & (262144ULL - 1ULL));
        std::uint64_t aRotSpanFinalB = (aRotWordFinalBA + aRotWordFinalBB + aRotWordFinalBC + aRotWordFinalBD);
        
        std::uint64_t                 mRotationAmountsL3[2];
        std::uint64_t                 mRotationAmountsL2[2];
        std::uint64_t                 mRotationAmountsL1[2];
        std::uint64_t                 mRotationAmountsFinal[2];
        
        mRotationAmountsL1[0] = (8192ULL / 2ULL) + aRotSpanL1A;
        mRotationAmountsL1[1] = 131072ULL + (8192ULL / 2ULL) + aRotSpanL1B;
        
        mRotationAmountsL2[0] = (16384ULL / 2ULL) + aRotSpanL2A;
        mRotationAmountsL2[1] = 262144ULL + (16384ULL / 2ULL) + aRotSpanL2B;
        
        mRotationAmountsL3[0] = (32768ULL / 2ULL) + aRotSpanL3A;
        mRotationAmountsL3[1] = 524288ULL + (32768ULL / 2ULL) + aRotSpanL3B;
        
        mRotationAmountsFinal[0] = (32768ULL / 2ULL) + aRotSpanFinalA;
        mRotationAmountsFinal[1] = 524288ULL + (32768ULL / 2ULL) + aRotSpanFinalB;
        

        std::uint64_t aPivotPointL1A = SOCCER_BLOCK_SIZE_L1 / 4ULL;
        std::uint64_t aPivotPointL1B = (SOCCER_BLOCK_SIZE_L1 / 4ULL) + (SOCCER_BLOCK_SIZE_L1 / 2ULL);
        
        std::uint64_t aPivotPointL2A = SOCCER_BLOCK_SIZE_L2 / 4ULL;
        std::uint64_t aPivotPointL2B = (SOCCER_BLOCK_SIZE_L2 / 4ULL) + (SOCCER_BLOCK_SIZE_L2 / 2ULL);
        
        std::uint64_t aPivotPointL3A = SOCCER_BLOCK_SIZE / 4ULL;
        std::uint64_t aPivotPointL3B = (SOCCER_BLOCK_SIZE / 4ULL) + (SOCCER_BLOCK_SIZE / 2ULL);
        
        
        std::uint64_t aSpanL1 =   8192ULL +  16384ULL +  32768ULL +  65536ULL;
        std::uint64_t aSpanL2 =  16384ULL +  32768ULL +  65536ULL + 131072ULL;
        std::uint64_t aSpanL3 =  32768ULL +  65536ULL + 131072ULL + 262144ULL;
        
        std::uint64_t aLowL1A = aPivotPointL1A - (aSpanL1 / 2);
        std::uint64_t aHighL1A = aPivotPointL1A + (aSpanL1 / 2);
        
        std::uint64_t aLowL1B = aPivotPointL1B - (aSpanL1 / 2);
        std::uint64_t aHighL1B = aPivotPointL1B + (aSpanL1 / 2);
        
        std::uint64_t aLowL2A = aPivotPointL2A - (aSpanL2 / 2);
        std::uint64_t aHighL2A = aPivotPointL2A + (aSpanL2 / 2);
        
        std::uint64_t aLowL2B = aPivotPointL2B - (aSpanL2 / 2);
        std::uint64_t aHighL2B = aPivotPointL2B + (aSpanL2 / 2);
        
        
        std::uint64_t aLowL3A = aPivotPointL3A - (aSpanL3 / 2);
        std::uint64_t aHighL3A = aPivotPointL3A + (aSpanL3 / 2);
        
        std::uint64_t aLowL3B = aPivotPointL3B - (aSpanL3 / 2);
        std::uint64_t aHighL3B = aPivotPointL3B + (aSpanL3 / 2);
        
        if (mRotationAmountsL1[0] < aLowL1A || mRotationAmountsL1[0] > aHighL1A) {
            XCTFail(@"mRotationAmountsL1[0] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsL1[0],
                    (unsigned long long)aLowL1A,
                    (unsigned long long)aHighL1A);
            return;
        }
        
        if (mRotationAmountsL1[1] < aLowL1B || mRotationAmountsL1[1] > aHighL1B) {
            XCTFail(@"mRotationAmountsL1[1] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsL1[1],
                    (unsigned long long)aLowL1B,
                    (unsigned long long)aHighL1B);
            return;
        }
        
        
        if (mRotationAmountsL2[0] < aLowL2A || mRotationAmountsL2[0] > aHighL2A) {
            XCTFail(@"mRotationAmountsL2[0] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsL2[0],
                    (unsigned long long)aLowL2A,
                    (unsigned long long)aHighL2A);
            return;
        }
        
        if (mRotationAmountsL2[1] < aLowL2B || mRotationAmountsL2[1] > aHighL2B) {
            XCTFail(@"mRotationAmountsL2[1] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsL2[1],
                    (unsigned long long)aLowL2B,
                    (unsigned long long)aHighL2B);
            return;
        }
        
        
        if (mRotationAmountsL3[0] < aLowL3A || mRotationAmountsL3[0] > aHighL3A) {
            XCTFail(@"mRotationAmountsL3[0] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsL3[0],
                    (unsigned long long)aLowL3A,
                    (unsigned long long)aHighL3A);
            return;
        }
        
        if (mRotationAmountsL3[1] < aLowL3B || mRotationAmountsL3[1] > aHighL3B) {
            XCTFail(@"mRotationAmountsL3[1] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsL3[1],
                    (unsigned long long)aLowL3B,
                    (unsigned long long)aHighL3B);
            return;
        }
        
        
        if (mRotationAmountsFinal[0] < aLowL3A || mRotationAmountsFinal[0] > aHighL3A) {
            XCTFail(@"mRotationAmountsFinal[0] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsFinal[0],
                    (unsigned long long)aLowL3A,
                    (unsigned long long)aHighL3A);
            return;
        }
        
        if (mRotationAmountsFinal[1] < aLowL3B || mRotationAmountsFinal[1] > aHighL3B) {
            XCTFail(@"mRotationAmountsFinal[1] was not in range: value=%llu range=[%llu, %llu]",
                    (unsigned long long)mRotationAmountsFinal[1],
                    (unsigned long long)aLowL3B,
                    (unsigned long long)aHighL3B);
            return;
        }
        
        
        
    }
    
}



@end
