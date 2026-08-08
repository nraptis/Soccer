//
//  SoccerRotationBank.cpp
//  Scramble
//
//  Created by nick on 8/7/26.
//

#include "SoccerRotationBank.hpp"
#include "Soccer2.hpp"
#include "TwistMix64.hpp"

#include <cstdio>
#include <cstdlib>

namespace {

constexpr std::int32_t kRotationSizeL1 = 262144;
constexpr std::int32_t kRotationSizeL2 = 524288;
constexpr std::int32_t kRotationSizeL3 = 1048576;

constexpr std::int32_t kRotationBoundaryA = 0;
constexpr std::int32_t kRotationBoundaryB = 262144;
constexpr std::int32_t kRotationBoundaryC = 524288;
constexpr std::int32_t kRotationBoundaryD = 786432;
constexpr std::int32_t kRotationBoundaryE = 1048576;



#define TEST_CONTEND(A, B)                                      \
    if (std::abs((A) - (B)) <= SOCCER_ROTATION_LEEWAY) {        \
        return true;                                            \
    }

} // namespace

std::int32_t                            SoccerRotationBank::mCacheDataS3[SOCCER_ROTATION_CACHE_COUNT_S3];
std::size_t                             SoccerRotationBank::mCacheCountS3 = 0;

std::int32_t                            SoccerRotationBank::mCacheDataS2[SOCCER_ROTATION_CACHE_COUNT_S2];
std::size_t                             SoccerRotationBank::mCacheCountS2 = 0;

std::int32_t                            SoccerRotationBank::mCacheDataS1[SOCCER_ROTATION_CACHE_COUNT_S1];
std::size_t                             SoccerRotationBank::mCacheCountS1 = 0;

std::size_t                             SoccerRotationBank::mCursorS3 = 0U;
std::size_t                             SoccerRotationBank::mCursorS2 = 0U;
std::size_t                             SoccerRotationBank::mCursorS1 = 0U;

SoccerRotationBankResponse              SoccerRotationBank::mResponse;

std::int32_t                            SoccerRotationBank::mRotationList[SOCCER_ROTATION_CACHE_COUNT_TOTAL];
bool                                    SoccerRotationBank::mRotationConsidered[SOCCER_ROTATION_CACHE_COUNT_TOTAL];
std::size_t                             SoccerRotationBank::mRotationListCount = 0;

std::size_t                             SoccerRotationBank::mLoopCount = 0;


bool SoccerRotationBank::RotationsContend(std::int32_t pRotationA, std::int32_t pRotationB) {
    std::int32_t aRotationA_A = pRotationA;
    if (aRotationA_A >= kRotationSizeL3) {
        aRotationA_A -= kRotationSizeL3;
    } else if (aRotationA_A < 0) {
        aRotationA_A += kRotationSizeL3;
    }

    std::int32_t aRotationB_A = pRotationB;
    if (aRotationB_A >= kRotationSizeL3) {
        aRotationB_A -= kRotationSizeL3;
    } else if (aRotationB_A < 0) {
        aRotationB_A += kRotationSizeL3;
    }

    TEST_CONTEND(aRotationA_A, aRotationB_A);

    std::int32_t aRotationA_B = aRotationA_A + kRotationSizeL1;
    if (aRotationA_B >= kRotationSizeL3) { aRotationA_B -= kRotationSizeL3; }
    std::int32_t aRotationB_B = aRotationB_A + kRotationSizeL1;
    if (aRotationB_B >= kRotationSizeL3) { aRotationB_B -= kRotationSizeL3; }
    TEST_CONTEND(aRotationA_A, aRotationB_B);
    TEST_CONTEND(aRotationA_B, aRotationB_A);
    TEST_CONTEND(aRotationA_B, aRotationB_B);

    std::int32_t aRotationA_C = aRotationA_B + kRotationSizeL1;
    if (aRotationA_C >= kRotationSizeL3) { aRotationA_C -= kRotationSizeL3; }
    std::int32_t aRotationB_C = aRotationB_B + kRotationSizeL1;
    if (aRotationB_C >= kRotationSizeL3) { aRotationB_C -= kRotationSizeL3; }
    TEST_CONTEND(aRotationA_A, aRotationB_C);
    TEST_CONTEND(aRotationA_B, aRotationB_C);
    TEST_CONTEND(aRotationA_C, aRotationB_A);
    TEST_CONTEND(aRotationA_C, aRotationB_B);
    TEST_CONTEND(aRotationA_C, aRotationB_C);

    std::int32_t aRotationA_D = aRotationA_C + kRotationSizeL1;
    if (aRotationA_D >= kRotationSizeL3) { aRotationA_D -= kRotationSizeL3; }
    std::int32_t aRotationB_D = aRotationB_C + kRotationSizeL1;
    if (aRotationB_D >= kRotationSizeL3) { aRotationB_D -= kRotationSizeL3; }
    TEST_CONTEND(aRotationA_A, aRotationB_D);
    TEST_CONTEND(aRotationA_B, aRotationB_D);
    TEST_CONTEND(aRotationA_C, aRotationB_D);
    TEST_CONTEND(aRotationA_D, aRotationB_A);
    TEST_CONTEND(aRotationA_D, aRotationB_B);
    TEST_CONTEND(aRotationA_D, aRotationB_C);
    TEST_CONTEND(aRotationA_D, aRotationB_D);

    return false;
}

bool SoccerRotationBank::BoundariesContend(std::int32_t pRotation) {
    std::int32_t aRotation = pRotation;
    if (aRotation >= kRotationSizeL3) {
        aRotation -= kRotationSizeL3;
    } else if (aRotation < 0) {
        aRotation += kRotationSizeL3;
    }

    TEST_CONTEND(aRotation, kRotationBoundaryA);
    TEST_CONTEND(aRotation, kRotationBoundaryB);
    TEST_CONTEND(aRotation, kRotationBoundaryC);
    TEST_CONTEND(aRotation, kRotationBoundaryD);
    TEST_CONTEND(aRotation, kRotationBoundaryE);

    return false;
}

SoccerRotationBankResponse SoccerRotationBank::Withdraw(SoccerRotationBankRequest pRequest) {
    auto CountRotations = [](SoccerRotationCount pCount) -> std::size_t {
        if (pCount == SoccerRotationCount::kFour) { return 4U; }
        if (pCount == SoccerRotationCount::kThree) { return 3U; }
        if (pCount == SoccerRotationCount::kTwo) { return 2U; }
        if (pCount == SoccerRotationCount::kOne) { return 1U; }
        return 0U;
    };

    const std::size_t aCountS3 =
        CountRotations(pRequest.mL3A) +
        CountRotations(pRequest.mL3B) +
        CountRotations(pRequest.mL3C);
    const std::size_t aCountS2 =
        CountRotations(pRequest.mL2A) +
        CountRotations(pRequest.mL2B);
    const std::size_t aCountS1 =
        CountRotations(pRequest.mL1A) +
        CountRotations(pRequest.mL1B);

    mResponse = {};
    mLoopCount = 0;

    mCacheCountS3 = 0U;
    mCacheCountS2 = 0U;
    mCacheCountS1 = 0U;

    if ((aCountS3 > SOCCER_ROTATION_CACHE_COUNT_S3) ||
        (aCountS2 > SOCCER_ROTATION_CACHE_COUNT_S2) ||
        (aCountS1 > SOCCER_ROTATION_CACHE_COUNT_S1) ||
        ((aCountS3 + aCountS2 + aCountS1) > SOCCER_ROTATION_CACHE_COUNT_TOTAL)) {
        return {};
    }

    mCursorS3 = 0U; mCursorS2 = 0U; mCursorS1 = 0U;
    if (!Withdraw_PassA(aCountS3, aCountS2, aCountS1)) {
        mCursorS3 = 0U; mCursorS2 = 0U; mCursorS1 = 0U;
        if (!Withdraw_PassB(aCountS3, aCountS2, aCountS1)) {
            mCursorS3 = 0U; mCursorS2 = 0U; mCursorS1 = 0U;
            if (!Withdraw_PassC(aCountS3, aCountS2, aCountS1)) {
                mCursorS3 = 0U; mCursorS2 = 0U; mCursorS1 = 0U;
                if (!Withdraw_PassD(aCountS3, aCountS2, aCountS1)) {
                    mCursorS3 = 0U; mCursorS2 = 0U; mCursorS1 = 0U;
                    Withdraw_PassE(aCountS3, aCountS2, aCountS1);
                }
            }
        }
    }

    std::size_t aCacheIndexS3 = 0U;
    for (std::size_t aIndex=0U; aIndex<CountRotations(pRequest.mL3A); aIndex++) {
        mResponse.mAmountL3A[aIndex] = mCacheDataS3[aCacheIndexS3++];
    }
    for (std::size_t aIndex=0U; aIndex<CountRotations(pRequest.mL3B); aIndex++) {
        mResponse.mAmountL3B[aIndex] = mCacheDataS3[aCacheIndexS3++];
    }
    for (std::size_t aIndex=0U; aIndex<CountRotations(pRequest.mL3C); aIndex++) {
        mResponse.mAmountL3C[aIndex] = mCacheDataS3[aCacheIndexS3++];
    }

    std::size_t aCacheIndexS2 = 0U;
    for (std::size_t aIndex=0U; aIndex<CountRotations(pRequest.mL2A); aIndex++) {
        mResponse.mAmountL2A[aIndex] = mCacheDataS2[aCacheIndexS2++];
    }
    for (std::size_t aIndex=0U; aIndex<CountRotations(pRequest.mL2B); aIndex++) {
        mResponse.mAmountL2B[aIndex] = mCacheDataS2[aCacheIndexS2++];
    }

    std::size_t aCacheIndexS1 = 0U;
    for (std::size_t aIndex=0U; aIndex<CountRotations(pRequest.mL1A); aIndex++) {
        mResponse.mAmountL1A[aIndex] = mCacheDataS1[aCacheIndexS1++];
    }
    for (std::size_t aIndex=0U; aIndex<CountRotations(pRequest.mL1B); aIndex++) {
        mResponse.mAmountL1B[aIndex] = mCacheDataS1[aCacheIndexS1++];
    }

    {
        // TODO: Print block.

        const std::int32_t aLowS1 = SOCCER_ROTATION_LEEWAY + 1;
        const std::int32_t aHighS1 = kRotationSizeL1 - SOCCER_ROTATION_LEEWAY;

        const std::int32_t aLowS2 = kRotationSizeL1 + SOCCER_ROTATION_LEEWAY + 1;
        const std::int32_t aHighS2 = kRotationSizeL2 - SOCCER_ROTATION_LEEWAY;

        const std::int32_t aLowS3 = kRotationSizeL2 + SOCCER_ROTATION_LEEWAY + 1;
        const std::int32_t aHighS3 = kRotationSizeL3 - SOCCER_ROTATION_LEEWAY;

        auto ContendsWithAnother = [&](const std::int32_t *pOwner, std::size_t pIndex) -> bool {
            const std::int32_t aRotation = pOwner[pIndex];
            bool aContends = BoundariesContend(aRotation);

            for (std::size_t aIndex=0U; aIndex<mCacheCountS1; aIndex++) {
                if ((pOwner != mCacheDataS1) || (pIndex != aIndex)) {
                    aContends |= RotationsContend(aRotation, mCacheDataS1[aIndex]);
                }
            }
            for (std::size_t aIndex=0U; aIndex<mCacheCountS2; aIndex++) {
                if ((pOwner != mCacheDataS2) || (pIndex != aIndex)) {
                    aContends |= RotationsContend(aRotation, mCacheDataS2[aIndex]);
                }
            }
            for (std::size_t aIndex=0U; aIndex<mCacheCountS3; aIndex++) {
                if ((pOwner != mCacheDataS3) || (pIndex != aIndex)) {
                    aContends |= RotationsContend(aRotation, mCacheDataS3[aIndex]);
                }
            }

            return aContends;
        };

        auto PrintRow = [&](const char *pName,
                            const std::int32_t *pRotations,
                            std::size_t pCount,
                            std::int32_t pLow,
                            std::int32_t pHigh) {
            printf("%s = [", pName);
            for (std::size_t aIndex=0U; aIndex<pCount; aIndex++) {
                printf("%s%d", (aIndex == 0U) ? "" : ", ", pRotations[aIndex]);
            }

            printf("], In Range = [");
            for (std::size_t aIndex=0U; aIndex<pCount; aIndex++) {
                const bool aInRange = (pRotations[aIndex] >= pLow) && (pRotations[aIndex] < pHigh);
                printf("%s%c", (aIndex == 0U) ? "" : ", ", aInRange ? 'T' : 'F');
            }

            printf("], Contends = [");
            for (std::size_t aIndex=0U; aIndex<pCount; aIndex++) {
                const bool aContends = ContendsWithAnother(pRotations, aIndex);
                printf("%s%c", (aIndex == 0U) ? "" : ", ", aContends ? 'T' : 'F');
            }
            printf("]\n");
        };

        printf("\nRotation Result, Loop Count = %zu\n", mLoopCount);
        PrintRow("S1", mCacheDataS1, mCacheCountS1, aLowS1, aHighS1);
        PrintRow("S2", mCacheDataS2, mCacheCountS2, aLowS2, aHighS2);
        PrintRow("S3", mCacheDataS3, mCacheCountS3, aLowS3, aHighS3);
    }

    return mResponse;
}

bool SoccerRotationBank::RotationsContend(std::int32_t pRotation) {
    if ((mCacheCountS3 > 0U) && RotationsContend(pRotation, mCacheDataS3[0])) { return true; }
    if ((mCacheCountS3 > 1U) && RotationsContend(pRotation, mCacheDataS3[1])) { return true; }
    if ((mCacheCountS3 > 2U) && RotationsContend(pRotation, mCacheDataS3[2])) { return true; }
    if ((mCacheCountS3 > 3U) && RotationsContend(pRotation, mCacheDataS3[3])) { return true; }

    if ((mCacheCountS2 > 0U) && RotationsContend(pRotation, mCacheDataS2[0])) { return true; }
    if ((mCacheCountS2 > 1U) && RotationsContend(pRotation, mCacheDataS2[1])) { return true; }
    if ((mCacheCountS2 > 2U) && RotationsContend(pRotation, mCacheDataS2[2])) { return true; }
    if ((mCacheCountS2 > 3U) && RotationsContend(pRotation, mCacheDataS2[3])) { return true; }

    if ((mCacheCountS1 > 0U) && RotationsContend(pRotation, mCacheDataS1[0])) { return true; }
    if ((mCacheCountS1 > 1U) && RotationsContend(pRotation, mCacheDataS1[1])) { return true; }
    if ((mCacheCountS1 > 2U) && RotationsContend(pRotation, mCacheDataS1[2])) { return true; }
    if ((mCacheCountS1 > 3U) && RotationsContend(pRotation, mCacheDataS1[3])) { return true; }

    return false;
}


bool SoccerRotationBank::ContendWithAnything(std::int32_t pRotation) {
    mRotationListCount = 0U;

    if (mCacheCountS3 > 0U) { mRotationList[mRotationListCount++] = mCacheDataS3[0]; }
    if (mCacheCountS3 > 1U) { mRotationList[mRotationListCount++] = mCacheDataS3[1]; }
    if (mCacheCountS3 > 2U) { mRotationList[mRotationListCount++] = mCacheDataS3[2]; }
    if (mCacheCountS3 > 3U) { mRotationList[mRotationListCount++] = mCacheDataS3[3]; }

    if (mCacheCountS2 > 0U) { mRotationList[mRotationListCount++] = mCacheDataS2[0]; }
    if (mCacheCountS2 > 1U) { mRotationList[mRotationListCount++] = mCacheDataS2[1]; }
    if (mCacheCountS2 > 2U) { mRotationList[mRotationListCount++] = mCacheDataS2[2]; }
    if (mCacheCountS2 > 3U) { mRotationList[mRotationListCount++] = mCacheDataS2[3]; }

    if (mCacheCountS1 > 0U) { mRotationList[mRotationListCount++] = mCacheDataS1[0]; }
    if (mCacheCountS1 > 1U) { mRotationList[mRotationListCount++] = mCacheDataS1[1]; }
    if (mCacheCountS1 > 2U) { mRotationList[mRotationListCount++] = mCacheDataS1[2]; }
    if (mCacheCountS1 > 3U) { mRotationList[mRotationListCount++] = mCacheDataS1[3]; }

    mRotationConsidered[0] = false;
    mRotationConsidered[1] = false;
    mRotationConsidered[2] = false;
    mRotationConsidered[3] = false;
    mRotationConsidered[4] = false;
    mRotationConsidered[5] = false;
    mRotationConsidered[6] = false;
    mRotationConsidered[7] = false;
    mRotationConsidered[8] = false;
    mRotationConsidered[9] = false;
    mRotationConsidered[10] = false;
    mRotationConsidered[11] = false;

    std::int32_t aRotationSum = pRotation;
    if (aRotationSum >= kRotationSizeL3) {
        aRotationSum -= kRotationSizeL3;
    } else if (aRotationSum < 0) {
        aRotationSum += kRotationSizeL3;
    }

    bool aFinished = false;
    while (!aFinished) {

        //
        // At this point:
        //
        // mRotationConsidered[] = one unique combination
        // aRotationSum          = sum of all considered rotations
        //

        if (BoundariesContend(aRotationSum)) {
            return true;
        }

        if (RotationsContend(aRotationSum)) { return true; }

        //
        // Advance to next combination.
        //

        std::size_t aIndex = 0;

        while (aIndex < mRotationListCount) {

            mLoopCount++;
            if (mRotationConsidered[aIndex] == false) {

                //
                // false -> true
                //

                mRotationConsidered[aIndex] = true;
                aRotationSum += mRotationList[aIndex];
                if (aRotationSum >= kRotationSizeL3) {
                    aRotationSum -= kRotationSizeL3;
                }

                break;

            } else {

                //
                // true -> false
                //
                // Carry to next position.
                //

                mRotationConsidered[aIndex] = false;
                aRotationSum -= mRotationList[aIndex];
                if (aRotationSum < 0) {
                    aRotationSum += kRotationSizeL3;
                }

                aIndex++;
            }
        }

        if (aIndex == mRotationListCount) {
            aFinished = true;
        }
    }
    return false;
}

std::int32_t SoccerRotationBank::MakeRandomRotationS3(std::uint64_t pSeed) {
    constexpr std::int32_t aFloor = kRotationSizeL2;
    constexpr std::int32_t aCeiling = kRotationSizeL3;
    constexpr std::int32_t aLow = aFloor + SOCCER_ROTATION_LEEWAY + 1;
    constexpr std::int32_t aHigh = aCeiling - SOCCER_ROTATION_LEEWAY;
    constexpr std::int32_t aSpan = aHigh - aLow;
    return aLow + static_cast<std::int32_t>(pSeed % static_cast<std::uint64_t>(aSpan));
}

std::int32_t SoccerRotationBank::MakeRandomRotationS2(std::uint64_t pSeed) {
    constexpr std::int32_t aFloor = kRotationSizeL1;
    constexpr std::int32_t aCeiling = kRotationSizeL2;
    constexpr std::int32_t aLow = aFloor + SOCCER_ROTATION_LEEWAY + 1;
    constexpr std::int32_t aHigh = aCeiling - SOCCER_ROTATION_LEEWAY;
    constexpr std::int32_t aSpan = aHigh - aLow;
    return aLow + static_cast<std::int32_t>(pSeed % static_cast<std::uint64_t>(aSpan));
}

std::int32_t SoccerRotationBank::MakeRandomRotationS1(std::uint64_t pSeed) {
    constexpr std::int32_t aFloor = 0;
    constexpr std::int32_t aCeiling = kRotationSizeL1;
    constexpr std::int32_t aLow = aFloor + SOCCER_ROTATION_LEEWAY + 1;
    constexpr std::int32_t aHigh = aCeiling - SOCCER_ROTATION_LEEWAY;
    constexpr std::int32_t aSpan = aHigh - aLow;
    return aLow + static_cast<std::int32_t>(pSeed % static_cast<std::uint64_t>(aSpan));
}


void SoccerRotationBank::CacheRotation(RotationSize pSize,
                                       std::int32_t pAmount) {
    if (pSize == RotationSize::kS3) {
        if (mCacheCountS3 >= SOCCER_ROTATION_CACHE_COUNT_S3) { return; }
    } else if (pSize == RotationSize::kS2) {
        if (mCacheCountS2 >= SOCCER_ROTATION_CACHE_COUNT_S2) { return; }
    } else {
        if (mCacheCountS1 >= SOCCER_ROTATION_CACHE_COUNT_S1) { return; }
    }

    if (pSize == RotationSize::kS3) {
        mCacheDataS3[mCacheCountS3++] = pAmount;
    } else if (pSize == RotationSize::kS2) {
        mCacheDataS2[mCacheCountS2++] = pAmount;
    } else {
        mCacheDataS1[mCacheCountS1++] = pAmount;
    }
}


bool SoccerRotationBank::Withdraw_PassA(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1) {
    while ((mCacheCountS3 < pCountS3) && (mCursorS3 < SOCCER_ROTATION_WORD_COUNT_S3)) {
        const std::uint64_t aWord = Soccer2::mRotationSeedS3[mCursorS3];
        const std::int32_t aRotation = MakeRandomRotationS3(aWord);
        mCursorS3++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS3, aRotation);
        }
    }

    while ((mCacheCountS2 < pCountS2) && (mCursorS2 < SOCCER_ROTATION_WORD_COUNT_S2)) {
        const std::uint64_t aWord = Soccer2::mRotationSeedS2[mCursorS2];
        const std::int32_t aRotation = MakeRandomRotationS2(aWord);
        mCursorS2++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS2, aRotation);
        }
    }

    while ((mCacheCountS1 < pCountS1) && (mCursorS1 < SOCCER_ROTATION_WORD_COUNT_S1)) {
        const std::uint64_t aWord = Soccer2::mRotationSeedS1[mCursorS1];
        const std::int32_t aRotation = MakeRandomRotationS1(aWord);
        mCursorS1++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS1, aRotation);
        }
    }

    printf("Withdraw_PassA, filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu)", mCacheCountS3, pCountS3, mCacheCountS2, pCountS2, mCacheCountS1, pCountS1);

    if (mCacheCountS1 != pCountS1) { return false; }
    if (mCacheCountS2 != pCountS2) { return false; }
    if (mCacheCountS3 != pCountS3) { return false; }
    return true;
}

bool SoccerRotationBank::Withdraw_PassB(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1) {
    while ((mCacheCountS3 < pCountS3) && (mCursorS3 < SOCCER_ROTATION_WORD_COUNT_S3)) {
        const std::uint64_t aWord = TwistMix64::DiffuseA(Soccer2::mRotationSeedS3[mCursorS3]);
        const std::int32_t aRotation = MakeRandomRotationS3(aWord);
        mCursorS3++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS3, aRotation);
        }
    }

    while ((mCacheCountS2 < pCountS2) && (mCursorS2 < SOCCER_ROTATION_WORD_COUNT_S2)) {
        const std::uint64_t aWord = TwistMix64::DiffuseA(Soccer2::mRotationSeedS2[mCursorS2]);
        const std::int32_t aRotation = MakeRandomRotationS2(aWord);
        mCursorS2++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS2, aRotation);
        }
    }

    while ((mCacheCountS1 < pCountS1) && (mCursorS1 < SOCCER_ROTATION_WORD_COUNT_S1)) {
        const std::uint64_t aWord = TwistMix64::DiffuseA(Soccer2::mRotationSeedS1[mCursorS1]);
        const std::int32_t aRotation = MakeRandomRotationS1(aWord);
        mCursorS1++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS1, aRotation);
        }
    }

    printf("Withdraw_PassB, filled S3(%zu of %zu), S2(%zu of %zu), S1(%zu of %zu)", mCacheCountS3, pCountS3, mCacheCountS2, pCountS2, mCacheCountS1, pCountS1);

    if (mCacheCountS1 != pCountS1) { return false; }
    if (mCacheCountS2 != pCountS2) { return false; }
    if (mCacheCountS3 != pCountS3) { return false; }
    return true;
}

bool SoccerRotationBank::Withdraw_PassC(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1) {
    while ((mCacheCountS3 < pCountS3) && (mCursorS3 < SOCCER_ROTATION_WORD_COUNT_S3)) {
        const std::uint64_t aWord = TwistMix64::DiffuseB(Soccer2::mRotationSeedS3[mCursorS3]);
        const std::int32_t aRotation = MakeRandomRotationS3(aWord);
        mCursorS3++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS3, aRotation);
        }
    }

    while ((mCacheCountS2 < pCountS2) && (mCursorS2 < SOCCER_ROTATION_WORD_COUNT_S2)) {
        const std::uint64_t aWord = TwistMix64::DiffuseB(Soccer2::mRotationSeedS2[mCursorS2]);
        const std::int32_t aRotation = MakeRandomRotationS2(aWord);
        mCursorS2++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS2, aRotation);
        }
    }

    while ((mCacheCountS1 < pCountS1) && (mCursorS1 < SOCCER_ROTATION_WORD_COUNT_S1)) {
        const std::uint64_t aWord = TwistMix64::DiffuseB(Soccer2::mRotationSeedS1[mCursorS1]);
        const std::int32_t aRotation = MakeRandomRotationS1(aWord);
        mCursorS1++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS1, aRotation);
        }
    }

    if (mCacheCountS1 != pCountS1) { return false; }
    if (mCacheCountS2 != pCountS2) { return false; }
    if (mCacheCountS3 != pCountS3) { return false; }
    return true;
}

bool SoccerRotationBank::Withdraw_PassD(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1) {
    while ((mCacheCountS3 < pCountS3) && (mCursorS3 < SOCCER_ROTATION_WORD_COUNT_S3)) {
        const std::uint64_t aWord = TwistMix64::DiffuseC(Soccer2::mRotationSeedS3[mCursorS3]);
        const std::int32_t aRotation = MakeRandomRotationS3(aWord);
        mCursorS3++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS3, aRotation);
        }
    }

    while ((mCacheCountS2 < pCountS2) && (mCursorS2 < SOCCER_ROTATION_WORD_COUNT_S2)) {
        const std::uint64_t aWord = TwistMix64::DiffuseC(Soccer2::mRotationSeedS2[mCursorS2]);
        const std::int32_t aRotation = MakeRandomRotationS2(aWord);
        mCursorS2++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS2, aRotation);
        }
    }

    while ((mCacheCountS1 < pCountS1) && (mCursorS1 < SOCCER_ROTATION_WORD_COUNT_S1)) {
        const std::uint64_t aWord = TwistMix64::DiffuseC(Soccer2::mRotationSeedS1[mCursorS1]);
        const std::int32_t aRotation = MakeRandomRotationS1(aWord);
        mCursorS1++;
        if (!ContendWithAnything(aRotation)) {
            CacheRotation(RotationSize::kS1, aRotation);
        }
    }

    if (mCacheCountS1 != pCountS1) { return false; }
    if (mCacheCountS2 != pCountS2) { return false; }
    if (mCacheCountS3 != pCountS3) { return false; }
    return true;
}

void SoccerRotationBank::Withdraw_PassE(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1) {
    constexpr std::int32_t aLowS3 = kRotationSizeL2 + SOCCER_ROTATION_LEEWAY + 1;
    constexpr std::int32_t aHighS3 = kRotationSizeL3 - SOCCER_ROTATION_LEEWAY;
    constexpr std::int32_t aSpanS3 = aHighS3 - aLowS3;

    constexpr std::int32_t aLowS2 = kRotationSizeL1 + SOCCER_ROTATION_LEEWAY + 1;
    constexpr std::int32_t aHighS2 = kRotationSizeL2 - SOCCER_ROTATION_LEEWAY;
    constexpr std::int32_t aSpanS2 = aHighS2 - aLowS2;

    constexpr std::int32_t aLowS1 = SOCCER_ROTATION_LEEWAY + 1;
    constexpr std::int32_t aHighS1 = kRotationSizeL1 - SOCCER_ROTATION_LEEWAY;
    constexpr std::int32_t aSpanS1 = aHighS1 - aLowS1;

    constexpr std::int32_t aAdvance = SOCCER_ROTATION_LEEWAY + 1;
    constexpr std::size_t aAttemptLimit = 2048U;

    while ((mCacheCountS3 < pCountS3) && (mCursorS3 < SOCCER_ROTATION_WORD_COUNT_S3)) {
        const std::uint64_t aWord = Soccer2::mRotationSeedS3[mCursorS3];
        std::int32_t aRotation = MakeRandomRotationS3(aWord);
        std::size_t aAttempt = 0U;
        bool aAccepted = false;
        while (aAttempt < aAttemptLimit) {
            if (!ContendWithAnything(aRotation)) {
                aAccepted = true;
                break;
            }
            aRotation += aAdvance;
            if (aRotation >= aHighS3) {
                aRotation -= aSpanS3;
            }
            aAttempt++;
        }
        mCursorS3++;
        if (aAccepted) {
            CacheRotation(RotationSize::kS3, aRotation);
        }
    }

    while ((mCacheCountS2 < pCountS2) && (mCursorS2 < SOCCER_ROTATION_WORD_COUNT_S2)) {
        const std::uint64_t aWord = Soccer2::mRotationSeedS2[mCursorS2];
        std::int32_t aRotation = MakeRandomRotationS2(aWord);
        std::size_t aAttempt = 0U;
        bool aAccepted = false;
        while (aAttempt < aAttemptLimit) {
            if (!ContendWithAnything(aRotation)) {
                aAccepted = true;
                break;
            }
            aRotation += aAdvance;
            if (aRotation >= aHighS2) {
                aRotation -= aSpanS2;
            }
            aAttempt++;
        }
        mCursorS2++;
        if (aAccepted) {
            CacheRotation(RotationSize::kS2, aRotation);
        }
    }

    while ((mCacheCountS1 < pCountS1) && (mCursorS1 < SOCCER_ROTATION_WORD_COUNT_S1)) {
        const std::uint64_t aWord = Soccer2::mRotationSeedS1[mCursorS1];
        std::int32_t aRotation = MakeRandomRotationS1(aWord);
        std::size_t aAttempt = 0U;
        bool aAccepted = false;
        while (aAttempt < aAttemptLimit) {
            if (!ContendWithAnything(aRotation)) {
                aAccepted = true;
                break;
            }
            aRotation += aAdvance;
            if (aRotation >= aHighS1) {
                aRotation -= aSpanS1;
            }
            aAttempt++;
        }
        mCursorS1++;
        if (aAccepted) {
            CacheRotation(RotationSize::kS1, aRotation);
        }
    }
}
