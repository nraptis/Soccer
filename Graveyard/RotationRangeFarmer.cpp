//
//  RotationRangeFarmer.cpp
//  Scramble
//
//  Created by nick on 8/8/26.
//

#include "RotationRangeFarmer.hpp"
#include "SoccerRotationBank.hpp"

#include <algorithm>
#include <array>
#include <limits>
#include <random>
#include <unordered_set>

namespace {

constexpr std::int64_t kRotationSizeL1 = 262144;
constexpr std::int64_t kRotationSizeL3 = 1048576;
constexpr std::uint32_t kRotationDistanceWeight = 3U;

static_assert(
    static_cast<std::uint64_t>(SOCCER_ROTATION_RANGE_BLOCK_HIGH) *
    static_cast<std::uint64_t>(SOCCER_ROTATION_RANGE_BLOCK_HIGH) *
    static_cast<std::uint64_t>(SOCCER_ROTATION_RANGE_BLOCK_HIGH) *
    static_cast<std::uint64_t>(SOCCER_ROTATION_RANGE_BLOCK_HIGH) ==
    SOCCER_ROTATION_RANGE_POSSIBILITY_COUNT);

std::int64_t FloorDivide(std::int64_t pValue, std::int64_t pDivisor) {
    std::int64_t aResult = pValue / pDivisor;
    if ((pValue < 0) && ((pValue % pDivisor) != 0)) {
        aResult--;
    }
    return aResult;
}

std::uint32_t IntervalDistance(std::int64_t pLowA,
                               std::int64_t pHighA,
                               std::int64_t pLowB,
                               std::int64_t pHighB) {
    if (pHighA < pLowB) {
        return static_cast<std::uint32_t>(pLowB - pHighA);
    }
    if (pHighB < pLowA) {
        return static_cast<std::uint32_t>(pLowA - pHighB);
    }
    return 0U;
}

std::uint32_t ExpressionDistance(
    const RotationRangeFamily &pFamily,
    const std::array<std::int8_t, SOCCER_ROTATION_RANGE_FAMILY_COUNT> &pCoefficient,
    const RotationRangeFarmerConfig &pConfig) {
    std::int64_t aLow = 0;
    std::int64_t aHigh = 0;
    const std::int64_t aRangeWidth =
        static_cast<std::int64_t>(pConfig.mRandomSpanSize) - 1;

    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndex++) {
        const std::int64_t aCoefficient = pCoefficient[aIndex];
        const std::int64_t aRangeLow =
            static_cast<std::int64_t>(pFamily.mBlock[aIndex]) *
            static_cast<std::int64_t>(pConfig.mRandomSpanSize);
        const std::int64_t aRangeHigh = aRangeLow + aRangeWidth;

        if (aCoefficient > 0) {
            aLow += aRangeLow;
            aHigh += aRangeHigh;
        } else if (aCoefficient < 0) {
            aLow -= aRangeHigh;
            aHigh -= aRangeLow;
        }
    }

    std::uint32_t aResult = std::numeric_limits<std::uint32_t>::max();
    const std::int64_t aFirstMultiple = FloorDivide(aLow, kRotationSizeL1) - 1;
    const std::int64_t aLastMultiple = FloorDivide(aHigh, kRotationSizeL1) + 1;
    for (std::int64_t aMultipleIndex=aFirstMultiple;
         aMultipleIndex<=aLastMultiple;
         aMultipleIndex++) {
        const std::int64_t aBoundary = aMultipleIndex * kRotationSizeL1;
        aResult = std::min(aResult,
                           IntervalDistance(aLow, aHigh, aBoundary, aBoundary));
    }

    return aResult;
}

RotationRangeFamily MakeRandomFamily(std::mt19937_64 &pGenerator,
                                     const RotationRangeFarmerConfig &pConfig) {
    std::uniform_int_distribution<std::uint16_t> aDistribution(
        SOCCER_ROTATION_RANGE_BLOCK_LOW,
        pConfig.mLandingZoneCount);

    RotationRangeFamily aResult;
    do {
        for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndex++) {
            aResult.mBlock[aIndex] = aDistribution(pGenerator);
        }
    } while (!RotationRangeFarmer::IsValid(aResult, pConfig));

    return aResult;
}

bool IsEarlier(const RotationRangeFamily &pFamilyA,
               const RotationRangeFamily &pFamilyB) {
    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndex++) {
        if (pFamilyA.mBlock[aIndex] < pFamilyB.mBlock[aIndex]) { return true; }
        if (pFamilyA.mBlock[aIndex] > pFamilyB.mBlock[aIndex]) { return false; }
    }
    return false;
}

std::uint64_t FamilyKey(const RotationRangeFamily &pFamily) {
    return static_cast<std::uint64_t>(pFamily.mBlock[0]) |
           (static_cast<std::uint64_t>(pFamily.mBlock[1]) << 16U) |
           (static_cast<std::uint64_t>(pFamily.mBlock[2]) << 32U) |
           (static_cast<std::uint64_t>(pFamily.mBlock[3]) << 48U);
}

std::uint32_t RangeStartDistance(std::uint16_t pBlockA,
                                 std::uint16_t pBlockB,
                                 const RotationRangeFarmerConfig &pConfig) {
    const std::int64_t aStartA =
        static_cast<std::int64_t>(pBlockA) *
        static_cast<std::int64_t>(pConfig.mRandomSpanSize);
    const std::int64_t aStartB =
        static_cast<std::int64_t>(pBlockB) *
        static_cast<std::int64_t>(pConfig.mRandomSpanSize);
    const std::int64_t aDifference = std::abs(aStartA - aStartB) % kRotationSizeL1;
    return static_cast<std::uint32_t>(
        std::min(aDifference, kRotationSizeL1 - aDifference));
}

} // namespace

bool RotationRangeFarmer::IsValid(const RotationRangeFamily &pFamily) {
    return IsValid(pFamily, RotationRangeFarmerConfig());
}

bool RotationRangeFarmer::IsValid(const RotationRangeFamily &pFamily,
                                  const RotationRangeFarmerConfig &pConfig) {
    if ((pConfig.mRandomSpanSize == 0U) ||
        (pConfig.mLandingZoneCount == 0U)) {
        return false;
    }

    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndex++) {
        if ((pFamily.mBlock[aIndex] < SOCCER_ROTATION_RANGE_BLOCK_LOW) ||
            (pFamily.mBlock[aIndex] > pConfig.mLandingZoneCount)) {
            return false;
        }

        for (std::size_t aOtherIndex=0U; aOtherIndex<aIndex; aOtherIndex++) {
            if (RangeStartDistance(pFamily.mBlock[aIndex],
                                   pFamily.mBlock[aOtherIndex],
                                   pConfig) <
                static_cast<std::uint32_t>(std::max(pConfig.mDistanceThreshold, 0))) {
                return false;
            }
        }

        std::array<std::int8_t, SOCCER_ROTATION_RANGE_FAMILY_COUNT> aCoefficient = {};
        aCoefficient[aIndex] = 1;

        const std::size_t aCombinationCount = static_cast<std::size_t>(1U) << aIndex;
        for (std::size_t aCombination=0U; aCombination<aCombinationCount; aCombination++) {
            for (std::size_t aPreviousIndex=0U; aPreviousIndex<aIndex; aPreviousIndex++) {
                aCoefficient[aPreviousIndex] =
                    ((aCombination & (static_cast<std::size_t>(1U) << aPreviousIndex)) != 0U) ? 1 : 0;
            }

            if (ExpressionDistance(pFamily, aCoefficient, pConfig) <= SOCCER_ROTATION_LEEWAY) {
                return false;
            }

            for (std::size_t aPreviousIndex=0U; aPreviousIndex<aIndex; aPreviousIndex++) {
                aCoefficient[aPreviousIndex]--;
                if (ExpressionDistance(pFamily, aCoefficient, pConfig) <= SOCCER_ROTATION_LEEWAY) {
                    return false;
                }
                aCoefficient[aPreviousIndex]++;
            }
        }
    }

    return true;
}

std::uint32_t RotationRangeFarmer::RangeDistance(std::uint16_t pBlockA,
                                                 std::uint16_t pBlockB) {
    return RangeDistance(pBlockA, pBlockB, RotationRangeFarmerConfig());
}

std::uint32_t RotationRangeFarmer::RangeDistance(
    std::uint16_t pBlockA,
    std::uint16_t pBlockB,
    const RotationRangeFarmerConfig &pConfig) {
    // With the default 1024-byte span, +0/+256/+512/+768 partitions the range
    // into four 256-byte chunks. Repeating them at the four L1 aliases produces
    // the requested 16 pieces. Measuring the complete configured intervals in
    // one folded quarter-cycle is exact for any span and avoids sampling gaps.
    if (pConfig.mRandomSpanSize == 0U) {
        return 0U;
    }

    const std::uint32_t aStartDistance =
        RangeStartDistance(pBlockA, pBlockB, pConfig);
    if (aStartDistance < pConfig.mRandomSpanSize) {
        return 0U;
    }
    return aStartDistance -
           static_cast<std::uint32_t>(pConfig.mRandomSpanSize - 1U);
}

std::uint32_t RotationRangeFarmer::BoundaryDistance(std::uint16_t pBlock) {
    return BoundaryDistance(pBlock, RotationRangeFarmerConfig());
}

std::uint32_t RotationRangeFarmer::BoundaryDistance(
    std::uint16_t pBlock,
    const RotationRangeFarmerConfig &pConfig) {
    if (pConfig.mRandomSpanSize == 0U) {
        return 0U;
    }

    const std::int64_t aRangeLow =
        static_cast<std::int64_t>(pBlock) *
        static_cast<std::int64_t>(pConfig.mRandomSpanSize);
    const std::int64_t aRangeWidth =
        static_cast<std::int64_t>(pConfig.mRandomSpanSize) - 1;
    std::uint32_t aResult = std::numeric_limits<std::uint32_t>::max();

    for (std::int64_t aAlias=0; aAlias<4; aAlias++) {
        const std::int64_t aLow = aRangeLow + (aAlias * kRotationSizeL1);
        const std::int64_t aHigh = aLow + aRangeWidth;

        for (std::int64_t aBoundary=0; aBoundary<=kRotationSizeL3; aBoundary+=kRotationSizeL1) {
            aResult = std::min(aResult, IntervalDistance(aLow, aHigh, aBoundary, aBoundary));
        }
    }

    return aResult;
}

std::uint32_t RotationRangeFarmer::FamilyDistance(const RotationRangeFamily &pFamilyA,
                                                  const RotationRangeFamily &pFamilyB) {
    return FamilyDistance(pFamilyA, pFamilyB, RotationRangeFarmerConfig());
}

std::uint32_t RotationRangeFarmer::FamilyDistance(
    const RotationRangeFamily &pFamilyA,
    const RotationRangeFamily &pFamilyB,
    const RotationRangeFarmerConfig &pConfig) {
    std::uint32_t aResult = std::numeric_limits<std::uint32_t>::max();

    for (std::size_t aIndexA=0U; aIndexA<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndexA++) {
        for (std::size_t aIndexB=0U; aIndexB<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndexB++) {
            aResult = std::min(aResult,
                               RangeDistance(pFamilyA.mBlock[aIndexA],
                                             pFamilyB.mBlock[aIndexB],
                                             pConfig));
        }
    }

    return aResult;
}

RotationRangeScore RotationRangeFarmer::Score(const RotationRangeFamily &pFamily) {
    return Score(pFamily, RotationRangeFarmerConfig());
}

RotationRangeScore RotationRangeFarmer::Score(
    const RotationRangeFamily &pFamily,
    const RotationRangeFarmerConfig &pConfig) {
    RotationRangeScore aResult;
    aResult.mMinimumRotationDistance = std::numeric_limits<std::uint32_t>::max();
    aResult.mMinimumBoundaryDistance = std::numeric_limits<std::uint32_t>::max();

    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndex++) {
        aResult.mMinimumBoundaryDistance =
            std::min(aResult.mMinimumBoundaryDistance,
                     BoundaryDistance(pFamily.mBlock[aIndex], pConfig));

        for (std::size_t aOtherIndex=aIndex + 1U;
             aOtherIndex<SOCCER_ROTATION_RANGE_FAMILY_COUNT;
             aOtherIndex++) {
            aResult.mMinimumRotationDistance =
                std::min(aResult.mMinimumRotationDistance,
                         RangeDistance(pFamily.mBlock[aIndex],
                                       pFamily.mBlock[aOtherIndex],
                                       pConfig));
        }
    }

    aResult.mTotal =
        (aResult.mMinimumRotationDistance * kRotationDistanceWeight) +
        aResult.mMinimumBoundaryDistance;
    return aResult;
}

std::uint32_t RotationRangeFarmer::AccumulatedDistance(const RotationRangeFamily &pFamily) {
    return AccumulatedDistance(pFamily, RotationRangeFarmerConfig());
}

std::uint32_t RotationRangeFarmer::AccumulatedDistance(
    const RotationRangeFamily &pFamily,
    const RotationRangeFarmerConfig &pConfig) {
    std::uint32_t aResult = std::numeric_limits<std::uint32_t>::max();

    for (std::size_t aIndex=0U; aIndex<SOCCER_ROTATION_RANGE_FAMILY_COUNT; aIndex++) {
        std::array<std::int8_t, SOCCER_ROTATION_RANGE_FAMILY_COUNT> aCoefficient = {};
        aCoefficient[aIndex] = 1;

        const std::size_t aCombinationCount = static_cast<std::size_t>(1U) << aIndex;
        for (std::size_t aCombination=0U; aCombination<aCombinationCount; aCombination++) {
            for (std::size_t aPreviousIndex=0U; aPreviousIndex<aIndex; aPreviousIndex++) {
                aCoefficient[aPreviousIndex] =
                    ((aCombination & (static_cast<std::size_t>(1U) << aPreviousIndex)) != 0U) ? 1 : 0;
            }

            aResult = std::min(aResult,
                               ExpressionDistance(pFamily, aCoefficient, pConfig));

            for (std::size_t aPreviousIndex=0U; aPreviousIndex<aIndex; aPreviousIndex++) {
                aCoefficient[aPreviousIndex]--;
                aResult = std::min(aResult,
                                   ExpressionDistance(pFamily, aCoefficient, pConfig));
                aCoefficient[aPreviousIndex]++;
            }
        }
    }

    return aResult;
}

std::size_t RotationRangeFarmer::LandingZoneCount(std::size_t pRandomSpanSize) {
    if (pRandomSpanSize == 0U) {
        return 0U;
    }

    const std::size_t aQuotient =
        static_cast<std::size_t>(kRotationSizeL1 - SOCCER_ROTATION_LEEWAY) /
        pRandomSpanSize;
    if (aQuotient <= 1U) {
        return 0U;
    }

    return std::min(aQuotient - 1U,
                    static_cast<std::size_t>(std::numeric_limits<std::uint16_t>::max()));
}

std::uint64_t RotationRangeFarmer::RawFamilyCount(
    const RotationRangeFarmerConfig &pConfig) {
    const std::uint64_t aCount = pConfig.mLandingZoneCount;
    return aCount * aCount * aCount * aCount;
}

std::vector<RotationRangeFamily> RotationRangeFarmer::EnumerateValid(
    const RotationRangeFarmerConfig &pConfig) {
    std::vector<RotationRangeFamily> aResult;
    if ((pConfig.mRandomSpanSize == 0U) ||
        (pConfig.mLandingZoneCount == 0U)) {
        return aResult;
    }

    for (std::size_t aBlockA=1U; aBlockA<=pConfig.mLandingZoneCount; aBlockA++) {
        for (std::size_t aBlockB=1U; aBlockB<=pConfig.mLandingZoneCount; aBlockB++) {
            for (std::size_t aBlockC=1U; aBlockC<=pConfig.mLandingZoneCount; aBlockC++) {
                for (std::size_t aBlockD=1U; aBlockD<=pConfig.mLandingZoneCount; aBlockD++) {
                    RotationRangeFamily aFamily;
                    aFamily.mBlock[0] = static_cast<std::uint16_t>(aBlockA);
                    aFamily.mBlock[1] = static_cast<std::uint16_t>(aBlockB);
                    aFamily.mBlock[2] = static_cast<std::uint16_t>(aBlockC);
                    aFamily.mBlock[3] = static_cast<std::uint16_t>(aBlockD);
                    if (IsValid(aFamily, pConfig)) {
                        aResult.push_back(aFamily);
                    }
                }
            }
        }
    }

    return aResult;
}

std::vector<RotationRangeFarmEntry> RotationRangeFarmer::Select(
    const std::vector<RotationRangeFamily> &pAvailable,
    std::size_t pFamilyCount,
    std::size_t pCandidateCount,
    const RotationRangeFarmerConfig &pConfig,
    std::uint64_t pSeed) {
    std::vector<RotationRangeFarmEntry> aResult;
    if ((pFamilyCount == 0U) || pAvailable.empty()) {
        return aResult;
    }

    std::unordered_set<std::uint64_t> aAvailableFamily;
    aAvailableFamily.reserve(pAvailable.size());
    for (const RotationRangeFamily &aFamily: pAvailable) {
        aAvailableFamily.insert(FamilyKey(aFamily));
    }

    const std::size_t aTargetCount =
        std::min(pFamilyCount, aAvailableFamily.size());
    aResult.reserve(aTargetCount);
    std::mt19937_64 aGenerator(pSeed);
    std::uniform_int_distribution<std::size_t> aDistribution(0U, pAvailable.size() - 1U);
    std::unordered_set<std::uint64_t> aSavedFamily;
    aSavedFamily.reserve(aTargetCount);

    RotationRangeFarmEntry aFirst;
    aFirst.mFamily = pAvailable[aDistribution(aGenerator)];
    aFirst.mScore = Score(aFirst.mFamily, pConfig);
    aFirst.mAccumulatedDistance = AccumulatedDistance(aFirst.mFamily, pConfig);
    aResult.push_back(aFirst);
    aSavedFamily.insert(FamilyKey(aFirst.mFamily));

    while ((aResult.size() < aTargetCount) && (pCandidateCount > 0U)) {
        const RotationRangeFamily &aPrevious = aResult.back().mFamily;
        RotationRangeFamily aBest = {};
        RotationRangeScore aBestScore;
        std::uint32_t aBestAccumulatedDistance = 0U;
        std::uint32_t aBestDistanceFromPrevious = 0U;
        bool aHasBest = false;

        std::size_t aCandidateIndex = 0U;
        while (aCandidateIndex < pCandidateCount) {
            const RotationRangeFamily aCandidate = pAvailable[aDistribution(aGenerator)];
            if (aSavedFamily.contains(FamilyKey(aCandidate))) {
                continue;
            }

            const RotationRangeScore aScore = Score(aCandidate, pConfig);
            const std::uint32_t aAccumulatedDistance =
                AccumulatedDistance(aCandidate, pConfig);
            const std::uint32_t aDistanceFromPrevious =
                FamilyDistance(aPrevious, aCandidate, pConfig);
            if ((!aHasBest) ||
                (aScore.mTotal > aBestScore.mTotal) ||
                ((aScore.mTotal == aBestScore.mTotal) &&
                 (aAccumulatedDistance > aBestAccumulatedDistance)) ||
                ((aScore.mTotal == aBestScore.mTotal) &&
                 (aAccumulatedDistance == aBestAccumulatedDistance) &&
                 (aDistanceFromPrevious > aBestDistanceFromPrevious)) ||
                ((aScore.mTotal == aBestScore.mTotal) &&
                 (aAccumulatedDistance == aBestAccumulatedDistance) &&
                 (aDistanceFromPrevious == aBestDistanceFromPrevious) &&
                 IsEarlier(aCandidate, aBest))) {
                aBest = aCandidate;
                aBestScore = aScore;
                aBestAccumulatedDistance = aAccumulatedDistance;
                aBestDistanceFromPrevious = aDistanceFromPrevious;
                aHasBest = true;
            }
            aCandidateIndex++;
        }

        if (!aHasBest) {
            break;
        }

        RotationRangeFarmEntry aEntry;
        aEntry.mFamily = aBest;
        aEntry.mScore = aBestScore;
        aEntry.mAccumulatedDistance = aBestAccumulatedDistance;
        aEntry.mDistanceFromPrevious = aBestDistanceFromPrevious;
        aResult.push_back(aEntry);
        aSavedFamily.insert(FamilyKey(aBest));
    }

    return aResult;
}

std::vector<RotationRangeFarmEntry> RotationRangeFarmer::Farm(
    std::size_t pFamilyCount,
    std::size_t pCandidateCount,
    std::uint64_t pSeed) {
    return Farm(pFamilyCount,
                pCandidateCount,
                RotationRangeFarmerConfig(),
                pSeed);
}

std::vector<RotationRangeFarmEntry> RotationRangeFarmer::Farm(
    std::size_t pFamilyCount,
    std::size_t pCandidateCount,
    const RotationRangeFarmerConfig &pConfig,
    std::uint64_t pSeed) {
    if ((pFamilyCount == 0U) ||
        (pCandidateCount == 0U) ||
        (pConfig.mRandomSpanSize == 0U) ||
        (pConfig.mLandingZoneCount == 0U)) {
        return {};
    }

    constexpr std::uint64_t kEnumerationLimit = 1000000ULL;
    if (RawFamilyCount(pConfig) <= kEnumerationLimit) {
        const std::vector<RotationRangeFamily> aAvailable = EnumerateValid(pConfig);
        return Select(aAvailable,
                      pFamilyCount,
                      pCandidateCount,
                      pConfig,
                      pSeed);
    }

    std::vector<RotationRangeFarmEntry> aResult;
    aResult.reserve(pFamilyCount);
    std::mt19937_64 aGenerator(pSeed);
    std::unordered_set<std::uint64_t> aSavedFamily;
    aSavedFamily.reserve(pFamilyCount);

    RotationRangeFarmEntry aFirst;
    aFirst.mFamily = MakeRandomFamily(aGenerator, pConfig);
    aFirst.mScore = Score(aFirst.mFamily, pConfig);
    aFirst.mAccumulatedDistance = AccumulatedDistance(aFirst.mFamily, pConfig);
    aResult.push_back(aFirst);
    aSavedFamily.insert(FamilyKey(aFirst.mFamily));

    while (aResult.size() < pFamilyCount) {
        const RotationRangeFamily &aPrevious = aResult.back().mFamily;
        RotationRangeFamily aBest = {};
        RotationRangeScore aBestScore;
        std::uint32_t aBestAccumulatedDistance = 0U;
        std::uint32_t aBestDistanceFromPrevious = 0U;
        bool aHasBest = false;

        std::size_t aCandidateIndex = 0U;
        while (aCandidateIndex < pCandidateCount) {
            const RotationRangeFamily aCandidate = MakeRandomFamily(aGenerator, pConfig);
            if (aSavedFamily.contains(FamilyKey(aCandidate))) {
                continue;
            }

            const RotationRangeScore aScore = Score(aCandidate, pConfig);
            const std::uint32_t aAccumulatedDistance =
                AccumulatedDistance(aCandidate, pConfig);
            const std::uint32_t aDistanceFromPrevious =
                FamilyDistance(aPrevious, aCandidate, pConfig);
            if ((!aHasBest) ||
                (aScore.mTotal > aBestScore.mTotal) ||
                ((aScore.mTotal == aBestScore.mTotal) &&
                 (aAccumulatedDistance > aBestAccumulatedDistance)) ||
                ((aScore.mTotal == aBestScore.mTotal) &&
                 (aAccumulatedDistance == aBestAccumulatedDistance) &&
                 (aDistanceFromPrevious > aBestDistanceFromPrevious)) ||
                ((aScore.mTotal == aBestScore.mTotal) &&
                 (aAccumulatedDistance == aBestAccumulatedDistance) &&
                 (aDistanceFromPrevious == aBestDistanceFromPrevious) &&
                 IsEarlier(aCandidate, aBest))) {
                aBest = aCandidate;
                aBestScore = aScore;
                aBestAccumulatedDistance = aAccumulatedDistance;
                aBestDistanceFromPrevious = aDistanceFromPrevious;
                aHasBest = true;
            }
            aCandidateIndex++;
        }

        if (!aHasBest) {
            break;
        }

        RotationRangeFarmEntry aEntry;
        aEntry.mFamily = aBest;
        aEntry.mScore = aBestScore;
        aEntry.mAccumulatedDistance = aBestAccumulatedDistance;
        aEntry.mDistanceFromPrevious = aBestDistanceFromPrevious;
        aResult.push_back(aEntry);
        aSavedFamily.insert(FamilyKey(aBest));
    }

    return aResult;
}
