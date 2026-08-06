//
//  SoccerFoldingTool.cpp
//  Scramble
//

#include "SoccerFoldingTool.hpp"
#include "FileIO.hpp"
#include "Jelly.hpp"
#include "TwistWorkSpace.hpp"

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <filesystem>
#include <iterator>
#include <limits>
#include <random>
#include <set>
#include <string>
#include <utility>

namespace {

struct SoccerFoldingItem {
    std::size_t mSourceLaneIndex;
    std::size_t mSourceBlockIndex;
};

using SoccerFoldingRoll = std::vector<SoccerFoldingItem>;

struct SoccerFoldingScore {
    std::size_t mMinimumDistance;
    std::size_t mTotalDistance;
};

struct SoccerFoldingFinalScore {
    bool mCoveragePassed;
    bool mSlotBalancePassed;
    std::size_t mExpectedSourceBlockCount;
    std::size_t mUsedSourceBlockCount;
    std::size_t mUniqueSourceBlockCount;
    std::size_t mDuplicateSourceBlockCount;
    std::size_t mOutOfRangeItemCount;
    std::size_t mMinimumDistance;
    double mAverageDistance;
    double mCoverageScore;
    double mBalanceScore;
    double mSpacingScore;
    double mFinalScore;
};

struct SoccerFoldingAnalysis {
    SoccerFoldingFinalScore mScore;
    std::vector<std::vector<std::size_t>> mDestinationSourceUseCounts;
    std::vector<std::vector<std::vector<std::size_t>>>
        mDestinationSlotSourceUseCounts;
    std::vector<std::set<std::size_t>> mUniqueSourceBlocks;
};

struct SoccerFoldingDimensions {
    std::size_t mInputLaneCount;
    std::size_t mOutputLaneCount;
    std::size_t mBlockByteCount;
    std::size_t mRollCount;
    std::size_t mRollCountPerOutputLane;
    std::size_t mSourceLaneUseCountPerOutputLane;
    std::size_t mSourceLaneSlotUseCountPerOutputLane;
};

static bool ValidateSpecification(const SoccerFoldingToolSpecification &pSpecification,
                                  SoccerFoldingDimensions &pDimensions) {
    if (pSpecification.mFunctionDeclaration.empty() ||
        pSpecification.mInputLaneNames.empty() ||
        pSpecification.mOutputLaneNames.empty()) {
        std::fprintf(stderr, "SoccerFoldingTool: function and lane names are required.\n");
        return false;
    }

    if ((pSpecification.mFoldItemCount != 2U) &&
        (pSpecification.mFoldItemCount != 4U) &&
        (pSpecification.mFoldItemCount != 8U)) {
        std::fprintf(stderr, "SoccerFoldingTool: fold item count must be 2, 4, or 8.\n");
        return false;
    }

    if ((pSpecification.mInputBlockCount == 0U) ||
        (pSpecification.mRandomTrialCount == 0U) ||
        ((pSpecification.mInputLaneByteCount % pSpecification.mInputBlockCount) != 0U)) {
        std::fprintf(stderr, "SoccerFoldingTool: invalid input block or trial count.\n");
        return false;
    }

    if (pSpecification.mInputBlockCount >
        static_cast<std::size_t>(std::numeric_limits<std::uint16_t>::max())) {
        std::fprintf(stderr, "SoccerFoldingTool: input block indexes must fit in uint16_t.\n");
        return false;
    }

    if (pSpecification.mInputLaneNames.size() >
        static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max())) {
        std::fprintf(stderr, "SoccerFoldingTool: input lane indexes must fit in uint8_t.\n");
        return false;
    }

    if (pSpecification.mInputBlockCount < pSpecification.mFoldItemCount) {
        std::fprintf(stderr, "SoccerFoldingTool: not enough block indexes for a distinct roll.\n");
        return false;
    }

    const std::size_t aInputLaneCount = pSpecification.mInputLaneNames.size();
    const std::size_t aOutputLaneCount = pSpecification.mOutputLaneNames.size();
    if (aOutputLaneCount != 4U) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: destination lane count must be exactly 4.\n");
        return false;
    }

    const std::size_t aTotalSourceBlockCount =
        aInputLaneCount * pSpecification.mInputBlockCount;

    if ((aTotalSourceBlockCount % pSpecification.mFoldItemCount) != 0U) {
        std::fprintf(stderr, "SoccerFoldingTool: source blocks do not divide by the fold count.\n");
        return false;
    }

    const std::size_t aRollCount =
        aTotalSourceBlockCount / pSpecification.mFoldItemCount;
    if ((aRollCount % aOutputLaneCount) != 0U) {
        std::fprintf(stderr, "SoccerFoldingTool: rolls do not divide across output lanes.\n");
        return false;
    }

    const std::size_t aRollCountPerOutputLane = aRollCount / aOutputLaneCount;
    if (aRollCountPerOutputLane >
        (static_cast<std::size_t>(
             std::numeric_limits<std::uint16_t>::max()) + 1U)) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: destination block indexes must fit in uint16_t.\n");
        return false;
    }
    const std::size_t aSourceUseCountPerOutputLane =
        aRollCountPerOutputLane * pSpecification.mFoldItemCount;
    if ((aSourceUseCountPerOutputLane % aInputLaneCount) != 0U) {
        std::fprintf(stderr, "SoccerFoldingTool: source lanes cannot be balanced per output lane.\n");
        return false;
    }

    const std::size_t aSourceLaneUseCountPerOutputLane =
        aSourceUseCountPerOutputLane / aInputLaneCount;
    if ((aSourceLaneUseCountPerOutputLane %
         pSpecification.mFoldItemCount) != 0U) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: source lanes cannot be balanced across fold slots.\n");
        return false;
    }

    const std::size_t aBlockByteCount =
        pSpecification.mInputLaneByteCount / pSpecification.mInputBlockCount;
    const std::size_t aGeneratedOutputLaneByteCount =
        aRollCountPerOutputLane * aBlockByteCount;
    if (aGeneratedOutputLaneByteCount != pSpecification.mOutputLaneByteCount) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: generated output lane size is %zu, expected %zu.\n",
                     aGeneratedOutputLaneByteCount,
                     pSpecification.mOutputLaneByteCount);
        return false;
    }

    pDimensions = SoccerFoldingDimensions{
        aInputLaneCount,
        aOutputLaneCount,
        aBlockByteCount,
        aRollCount,
        aRollCountPerOutputLane,
        aSourceLaneUseCountPerOutputLane,
        aSourceLaneUseCountPerOutputLane /
            pSpecification.mFoldItemCount,
    };
    return true;
}

static bool ContainsBlockIndex(const SoccerFoldingRoll &pRoll,
                               std::size_t pBlockIndex) {
    for (const SoccerFoldingItem &aItem : pRoll) {
        if (aItem.mSourceBlockIndex == pBlockIndex) {
            return true;
        }
    }
    return false;
}

static bool HasAvailableBlock(const std::vector<std::size_t> &pUnusedBlocks,
                              const SoccerFoldingRoll &pRoll) {
    for (const std::size_t aBlockIndex : pUnusedBlocks) {
        if (!ContainsBlockIndex(pRoll, aBlockIndex)) {
            return true;
        }
    }
    return false;
}

static bool PickAvailableBlock(const std::vector<std::size_t> &pUnusedBlocks,
                               const SoccerFoldingRoll &pRoll,
                               std::mt19937_64 &pGenerator,
                               std::size_t &pBlockIndex) {
    if (pUnusedBlocks.empty()) {
        return false;
    }

    std::uniform_int_distribution<std::size_t> aDistribution(
        0U, pUnusedBlocks.size() - 1U);
    for (std::size_t aTry=0U; aTry<32U; aTry++) {
        const std::size_t aCandidate =
            pUnusedBlocks[aDistribution(pGenerator)];
        if (!ContainsBlockIndex(pRoll, aCandidate)) {
            pBlockIndex = aCandidate;
            return true;
        }
    }

    for (const std::size_t aCandidate : pUnusedBlocks) {
        if (!ContainsBlockIndex(pRoll, aCandidate)) {
            pBlockIndex = aCandidate;
            return true;
        }
    }

    return false;
}

static bool MakeRandomRoll(
    const SoccerFoldingToolSpecification &pSpecification,
    const SoccerFoldingDimensions &pDimensions,
    const std::vector<std::vector<std::size_t>> &pUnusedBlocks,
    const std::vector<std::size_t> &pDestinationSourceLaneUseCounts,
    const std::vector<std::vector<std::size_t>>
        &pDestinationSlotSourceLaneUseCounts,
    std::mt19937_64 &pGenerator,
    SoccerFoldingRoll &pRoll) {
    pRoll.clear();
    pRoll.reserve(pSpecification.mFoldItemCount);

    std::vector<std::size_t> aTemporaryUseCounts =
        pDestinationSourceLaneUseCounts;
    std::vector<std::size_t> aTemporaryRemainingBlockCounts(
        pDimensions.mInputLaneCount);
    for (std::size_t aSourceLaneIndex=0U;
         aSourceLaneIndex<pDimensions.mInputLaneCount;
         aSourceLaneIndex++) {
        aTemporaryRemainingBlockCounts[aSourceLaneIndex] =
            pUnusedBlocks[aSourceLaneIndex].size();
    }

    for (std::size_t aSlotIndex=0U;
         aSlotIndex<pSpecification.mFoldItemCount;
         aSlotIndex++) {
        std::size_t aMinimumSlotUseCount =
            std::numeric_limits<std::size_t>::max();
        for (std::size_t aSourceLaneIndex=0U;
             aSourceLaneIndex<pDimensions.mInputLaneCount;
             aSourceLaneIndex++) {
            if (HasAvailableBlock(pUnusedBlocks[aSourceLaneIndex], pRoll)) {
                aMinimumSlotUseCount = std::min(
                    aMinimumSlotUseCount,
                    pDestinationSlotSourceLaneUseCounts[aSlotIndex]
                                                        [aSourceLaneIndex]);
            }
        }
        if (aMinimumSlotUseCount ==
            std::numeric_limits<std::size_t>::max()) {
            return false;
        }

        std::size_t aMinimumUseCount =
            std::numeric_limits<std::size_t>::max();
        for (std::size_t aSourceLaneIndex=0U;
             aSourceLaneIndex<pDimensions.mInputLaneCount;
             aSourceLaneIndex++) {
            if ((pDestinationSlotSourceLaneUseCounts[aSlotIndex]
                                                    [aSourceLaneIndex] ==
                 aMinimumSlotUseCount) &&
                HasAvailableBlock(pUnusedBlocks[aSourceLaneIndex], pRoll)) {
                aMinimumUseCount = std::min(
                    aMinimumUseCount,
                    aTemporaryUseCounts[aSourceLaneIndex]);
            }
        }

        // Exact slot balance implies exact destination balance. Therefore the
        // current slot is authoritative, destination use breaks that tie, and
        // remaining blocks break the final tie.
        std::size_t aMaximumRemainingBlockCount = 0U;
        for (std::size_t aSourceLaneIndex=0U;
             aSourceLaneIndex<pDimensions.mInputLaneCount;
             aSourceLaneIndex++) {
            if ((aTemporaryUseCounts[aSourceLaneIndex] ==
                 aMinimumUseCount) &&
                (pDestinationSlotSourceLaneUseCounts[aSlotIndex]
                                                    [aSourceLaneIndex] ==
                 aMinimumSlotUseCount) &&
                HasAvailableBlock(pUnusedBlocks[aSourceLaneIndex],
                                  pRoll)) {
                aMaximumRemainingBlockCount = std::max(
                    aMaximumRemainingBlockCount,
                    aTemporaryRemainingBlockCounts[aSourceLaneIndex]);
            }
        }

        std::vector<std::size_t> aEligibleSourceLanes;
        aEligibleSourceLanes.reserve(pDimensions.mInputLaneCount);
        for (std::size_t aSourceLaneIndex=0U;
             aSourceLaneIndex<pDimensions.mInputLaneCount;
             aSourceLaneIndex++) {
            if ((aTemporaryUseCounts[aSourceLaneIndex] ==
                 aMinimumUseCount) &&
                (pDestinationSlotSourceLaneUseCounts[aSlotIndex]
                                                    [aSourceLaneIndex] ==
                 aMinimumSlotUseCount) &&
                (aTemporaryRemainingBlockCounts[aSourceLaneIndex] ==
                 aMaximumRemainingBlockCount) &&
                HasAvailableBlock(pUnusedBlocks[aSourceLaneIndex],
                                  pRoll)) {
                aEligibleSourceLanes.push_back(aSourceLaneIndex);
            }
        }

        if (aEligibleSourceLanes.empty()) {
            return false;
        }

        std::uniform_int_distribution<std::size_t> aLaneDistribution(
            0U, aEligibleSourceLanes.size() - 1U);
        const std::size_t aSourceLaneIndex =
            aEligibleSourceLanes[aLaneDistribution(pGenerator)];

        std::size_t aSourceBlockIndex = 0U;
        if (!PickAvailableBlock(pUnusedBlocks[aSourceLaneIndex],
                                pRoll,
                                pGenerator,
                                aSourceBlockIndex)) {
            return false;
        }

        pRoll.push_back(SoccerFoldingItem{
            aSourceLaneIndex,
            aSourceBlockIndex,
        });
        aTemporaryUseCounts[aSourceLaneIndex] += 1U;
        aTemporaryRemainingBlockCounts[aSourceLaneIndex] -= 1U;
    }

    return true;
}

static std::size_t NearestDistance(const std::set<std::size_t> &pHistory,
                                   std::size_t pBlockIndex,
                                   std::size_t pMaximumDistance) {
    std::size_t aDistance = pMaximumDistance;
    const auto aNext = pHistory.lower_bound(pBlockIndex);
    if (aNext != pHistory.end()) {
        aDistance = std::min(aDistance, *aNext - pBlockIndex);
    }
    if (aNext != pHistory.begin()) {
        const auto aPrevious = std::prev(aNext);
        aDistance = std::min(aDistance,
                             pBlockIndex - *aPrevious);
    }
    return aDistance;
}

static SoccerFoldingScore ScoreRoll(
    const SoccerFoldingRoll &pRoll,
    const std::vector<std::vector<std::set<std::size_t>>> &pDestinationHistory,
    std::size_t pInputBlockCount) {
    SoccerFoldingScore aScore{
        std::numeric_limits<std::size_t>::max(),
        0U,
    };

    for (std::size_t aSlotIndex=0U;
         aSlotIndex<pRoll.size();
         aSlotIndex++) {
        const SoccerFoldingItem &aItem = pRoll[aSlotIndex];
        const std::size_t aDistance = NearestDistance(
            pDestinationHistory[aSlotIndex][aItem.mSourceLaneIndex],
            aItem.mSourceBlockIndex,
            pInputBlockCount);
        aScore.mMinimumDistance = std::min(aScore.mMinimumDistance,
                                           aDistance);
        aScore.mTotalDistance += aDistance;
    }

    return aScore;
}

static bool IsBetterScore(const SoccerFoldingScore &pCandidate,
                          const SoccerFoldingScore &pBest) {
    if (pCandidate.mMinimumDistance != pBest.mMinimumDistance) {
        return pCandidate.mMinimumDistance > pBest.mMinimumDistance;
    }
    return pCandidate.mTotalDistance > pBest.mTotalDistance;
}

static bool RemoveUnusedBlock(std::vector<std::size_t> &pUnusedBlocks,
                              std::size_t pBlockIndex) {
    const auto aFound = std::find(pUnusedBlocks.begin(),
                                  pUnusedBlocks.end(),
                                  pBlockIndex);
    if (aFound == pUnusedBlocks.end()) {
        return false;
    }

    *aFound = pUnusedBlocks.back();
    pUnusedBlocks.pop_back();
    return true;
}

static bool GenerateRolls(const SoccerFoldingToolSpecification &pSpecification,
                          const SoccerFoldingDimensions &pDimensions,
                          std::uint64_t pSeed,
                          std::vector<SoccerFoldingRoll> &pRolls) {
    std::mt19937_64 aGenerator(pSeed);

    std::vector<std::vector<std::size_t>> aUnusedBlocks(
        pDimensions.mInputLaneCount,
        std::vector<std::size_t>(pSpecification.mInputBlockCount));
    for (std::size_t aSourceLaneIndex=0U;
         aSourceLaneIndex<pDimensions.mInputLaneCount;
         aSourceLaneIndex++) {
        for (std::size_t aBlockIndex=0U;
             aBlockIndex<pSpecification.mInputBlockCount;
             aBlockIndex++) {
            aUnusedBlocks[aSourceLaneIndex][aBlockIndex] = aBlockIndex;
        }
    }

    std::vector<std::vector<std::size_t>> aSourceLaneUseCounts(
        pDimensions.mOutputLaneCount,
        std::vector<std::size_t>(pDimensions.mInputLaneCount, 0U));

    std::vector<std::vector<std::vector<std::size_t>>>
        aSourceLaneSlotUseCounts(
            pDimensions.mOutputLaneCount,
            std::vector<std::vector<std::size_t>>(
                pSpecification.mFoldItemCount,
                std::vector<std::size_t>(pDimensions.mInputLaneCount, 0U)));

    std::vector<std::vector<std::vector<std::set<std::size_t>>>> aHistory(
        pDimensions.mOutputLaneCount,
        std::vector<std::vector<std::set<std::size_t>>>(
            pSpecification.mFoldItemCount,
            std::vector<std::set<std::size_t>>(
                pDimensions.mInputLaneCount)));

    // The initial [0, 0, ...] row does not identify source lanes. Therefore it
    // cannot create a same-source/same-destination-slot distance comparison.

    pRolls.clear();
    pRolls.reserve(pDimensions.mRollCount);

    for (std::size_t aRollIndex=0U;
         aRollIndex<pDimensions.mRollCount;
         aRollIndex++) {
        // Destinations are emitted as 0, 1, 2, 3, 0, 1, 2, 3, ...
        const std::size_t aDestinationLaneIndex =
            aRollIndex % pDimensions.mOutputLaneCount;

        bool aFoundCandidate = false;
        SoccerFoldingRoll aBestRoll;
        SoccerFoldingScore aBestScore{0U, 0U};
        std::size_t aBestScoreMatchCount = 0U;

        for (std::size_t aTrialIndex=0U;
             aTrialIndex<pSpecification.mRandomTrialCount;
             aTrialIndex++) {
            SoccerFoldingRoll aCandidate;
            if (!MakeRandomRoll(
                    pSpecification,
                    pDimensions,
                    aUnusedBlocks,
                    aSourceLaneUseCounts[aDestinationLaneIndex],
                    aSourceLaneSlotUseCounts[aDestinationLaneIndex],
                    aGenerator,
                    aCandidate)) {
                continue;
            }

            const SoccerFoldingScore aScore = ScoreRoll(
                aCandidate,
                aHistory[aDestinationLaneIndex],
                pSpecification.mInputBlockCount);
            if (!aFoundCandidate ||
                IsBetterScore(aScore, aBestScore)) {
                aFoundCandidate = true;
                aBestRoll = std::move(aCandidate);
                aBestScore = aScore;
                aBestScoreMatchCount = 1U;
            } else if ((aScore.mMinimumDistance ==
                        aBestScore.mMinimumDistance) &&
                       (aScore.mTotalDistance ==
                        aBestScore.mTotalDistance)) {
                aBestScoreMatchCount++;
                std::uniform_int_distribution<std::size_t> aTieDistribution(
                    1U, aBestScoreMatchCount);
                if (aTieDistribution(aGenerator) == 1U) {
                    aBestRoll = std::move(aCandidate);
                    aBestScore = aScore;
                }
            }
        }

        if (!aFoundCandidate) {
            std::fprintf(stderr,
                         "SoccerFoldingTool: attempt stopped at roll %zu, destination %zu.\n",
                         aRollIndex,
                         aDestinationLaneIndex);
            return false;
        }

        for (std::size_t aSlotIndex=0U;
             aSlotIndex<aBestRoll.size();
             aSlotIndex++) {
            const SoccerFoldingItem &aItem = aBestRoll[aSlotIndex];
            if (!RemoveUnusedBlock(
                    aUnusedBlocks[aItem.mSourceLaneIndex],
                    aItem.mSourceBlockIndex)) {
                return false;
            }

            aSourceLaneUseCounts[aDestinationLaneIndex]
                                [aItem.mSourceLaneIndex] += 1U;
            aSourceLaneSlotUseCounts[aDestinationLaneIndex]
                                    [aSlotIndex]
                                    [aItem.mSourceLaneIndex] += 1U;
            aHistory[aDestinationLaneIndex]
                    [aSlotIndex]
                    [aItem.mSourceLaneIndex].insert(
                        aItem.mSourceBlockIndex);
        }

        pRolls.push_back(std::move(aBestRoll));
    }

    if (pRolls.size() != pDimensions.mRollCount) {
        return false;
    }

    for (const std::vector<std::size_t> &aLaneBlocks : aUnusedBlocks) {
        if (!aLaneBlocks.empty()) {
            return false;
        }
    }

    for (const std::vector<std::size_t> &aDestinationCounts :
         aSourceLaneUseCounts) {
        for (const std::size_t aUseCount : aDestinationCounts) {
            if (aUseCount !=
                pDimensions.mSourceLaneUseCountPerOutputLane) {
                return false;
            }
        }
    }

    for (const auto &aDestinationSlotCounts : aSourceLaneSlotUseCounts) {
        for (const auto &aSlotCounts : aDestinationSlotCounts) {
            for (const std::size_t aUseCount : aSlotCounts) {
                if (aUseCount !=
                    pDimensions.mSourceLaneSlotUseCountPerOutputLane) {
                    return false;
                }
            }
        }
    }

    return true;
}

static SoccerFoldingAnalysis AnalyzeFinalRolls(
    const SoccerFoldingToolSpecification &pSpecification,
    const SoccerFoldingDimensions &pDimensions,
    const std::vector<SoccerFoldingRoll> &pRolls) {
    SoccerFoldingAnalysis aAnalysis{};
    aAnalysis.mDestinationSourceUseCounts.assign(
        pDimensions.mOutputLaneCount,
        std::vector<std::size_t>(pDimensions.mInputLaneCount, 0U));
    aAnalysis.mDestinationSlotSourceUseCounts.assign(
        pDimensions.mOutputLaneCount,
        std::vector<std::vector<std::size_t>>(
            pSpecification.mFoldItemCount,
            std::vector<std::size_t>(pDimensions.mInputLaneCount, 0U)));
    aAnalysis.mUniqueSourceBlocks.resize(pDimensions.mInputLaneCount);

    std::vector<std::vector<std::vector<std::set<std::size_t>>>> aHistory(
        pDimensions.mOutputLaneCount,
        std::vector<std::vector<std::set<std::size_t>>>(
            pSpecification.mFoldItemCount,
            std::vector<std::set<std::size_t>>(
                pDimensions.mInputLaneCount)));

    std::size_t aUsedSourceBlockCount = 0U;
    std::size_t aDuplicateSourceBlockCount = 0U;
    std::size_t aOutOfRangeItemCount = 0U;

    for (std::size_t aRollIndex=0U; aRollIndex<pRolls.size(); aRollIndex++) {
        const std::size_t aDestinationLaneIndex =
            aRollIndex % pDimensions.mOutputLaneCount;
        const SoccerFoldingRoll &aRoll = pRolls[aRollIndex];

        for (std::size_t aSlotIndex=0U; aSlotIndex<aRoll.size(); aSlotIndex++) {
            aUsedSourceBlockCount++;
            const SoccerFoldingItem &aItem = aRoll[aSlotIndex];
            if ((aItem.mSourceLaneIndex >= pDimensions.mInputLaneCount) ||
                (aItem.mSourceBlockIndex >= pSpecification.mInputBlockCount)) {
                aOutOfRangeItemCount++;
                continue;
            }

            aAnalysis.mDestinationSourceUseCounts[aDestinationLaneIndex]
                                                       [aItem.mSourceLaneIndex]++;
            aAnalysis.mDestinationSlotSourceUseCounts[aDestinationLaneIndex]
                                                         [aSlotIndex]
                                                         [aItem.mSourceLaneIndex]++;
            if (!aAnalysis.mUniqueSourceBlocks[aItem.mSourceLaneIndex]
                          .insert(aItem.mSourceBlockIndex).second) {
                aDuplicateSourceBlockCount++;
            }
            aHistory[aDestinationLaneIndex]
                    [aSlotIndex]
                    [aItem.mSourceLaneIndex].insert(aItem.mSourceBlockIndex);
        }
    }

    const std::size_t aExpectedSourceBlockCount =
        pDimensions.mInputLaneCount * pSpecification.mInputBlockCount;
    std::size_t aUniqueSourceBlockCount = 0U;
    bool aCoveragePassed =
        (aUsedSourceBlockCount == aExpectedSourceBlockCount) &&
        (aDuplicateSourceBlockCount == 0U) &&
        (aOutOfRangeItemCount == 0U);
    for (const std::set<std::size_t> &aSourceBlocks :
         aAnalysis.mUniqueSourceBlocks) {
        aUniqueSourceBlockCount += aSourceBlocks.size();
        if (aSourceBlocks.size() != pSpecification.mInputBlockCount) {
            aCoveragePassed = false;
        }
    }

    const double aCoverageScore = (aExpectedSourceBlockCount == 0U)
        ? 0.0
        : (100.0 * static_cast<double>(aUniqueSourceBlockCount) /
           static_cast<double>(aExpectedSourceBlockCount));

    std::size_t aTotalBalanceDeviation = 0U;
    for (const std::vector<std::size_t> &aDestinationCounts :
         aAnalysis.mDestinationSourceUseCounts) {
        for (const std::size_t aUseCount : aDestinationCounts) {
            const std::size_t aExpectedUseCount =
                pDimensions.mSourceLaneUseCountPerOutputLane;
            aTotalBalanceDeviation += (aUseCount >= aExpectedUseCount)
                ? (aUseCount - aExpectedUseCount)
                : (aExpectedUseCount - aUseCount);
        }
    }
    bool aSlotBalancePassed = true;
    for (const auto &aDestinationSlotCounts :
         aAnalysis.mDestinationSlotSourceUseCounts) {
        for (const auto &aSlotCounts : aDestinationSlotCounts) {
            for (const std::size_t aUseCount : aSlotCounts) {
                const std::size_t aExpectedUseCount =
                    pDimensions.mSourceLaneSlotUseCountPerOutputLane;
                aTotalBalanceDeviation += (aUseCount >= aExpectedUseCount)
                    ? (aUseCount - aExpectedUseCount)
                    : (aExpectedUseCount - aUseCount);
                if (aUseCount != aExpectedUseCount) {
                    aSlotBalancePassed = false;
                }
            }
        }
    }
    const double aBalanceDenominator =
        4.0 * static_cast<double>(aExpectedSourceBlockCount);
    const double aBalanceScore = (aBalanceDenominator == 0.0)
        ? 0.0
        : std::max(0.0,
                   100.0 *
                   (1.0 - (static_cast<double>(aTotalBalanceDeviation) /
                           aBalanceDenominator)));

    std::size_t aMinimumDistance =
        std::numeric_limits<std::size_t>::max();
    std::size_t aTotalDistance = 0U;
    std::size_t aDistanceCount = 0U;
    double aTotalSpacingEfficiency = 0.0;
    std::size_t aSpacingGroupCount = 0U;

    for (const auto &aDestinationHistory : aHistory) {
        for (const auto &aSlotHistory : aDestinationHistory) {
            for (const std::set<std::size_t> &aSourceHistory : aSlotHistory) {
                if (aSourceHistory.size() < 2U) {
                    continue;
                }

                std::size_t aGroupMinimumDistance =
                    std::numeric_limits<std::size_t>::max();
                auto aPrevious = aSourceHistory.begin();
                for (auto aCurrent=std::next(aPrevious);
                     aCurrent!=aSourceHistory.end();
                     aCurrent++) {
                    const std::size_t aDistance = *aCurrent - *aPrevious;
                    aGroupMinimumDistance = std::min(aGroupMinimumDistance,
                                                     aDistance);
                    aMinimumDistance = std::min(aMinimumDistance, aDistance);
                    aTotalDistance += aDistance;
                    aDistanceCount++;
                    aPrevious = aCurrent;
                }

                // This is the best possible linear minimum spacing for this
                // group's item count if the first and last blocks are used.
                const std::size_t aIdealMinimumDistance = std::max<std::size_t>(
                    1U,
                    (pSpecification.mInputBlockCount - 1U) /
                    (aSourceHistory.size() - 1U));
                aTotalSpacingEfficiency += std::min(
                    1.0,
                    static_cast<double>(aGroupMinimumDistance) /
                    static_cast<double>(aIdealMinimumDistance));
                aSpacingGroupCount++;
            }
        }
    }

    if (aMinimumDistance == std::numeric_limits<std::size_t>::max()) {
        aMinimumDistance = 0U;
    }
    const double aAverageDistance = (aDistanceCount == 0U)
        ? 0.0
        : (static_cast<double>(aTotalDistance) /
           static_cast<double>(aDistanceCount));
    const double aSpacingScore = (aSpacingGroupCount == 0U)
        ? 100.0
        : (100.0 * aTotalSpacingEfficiency /
           static_cast<double>(aSpacingGroupCount));

    // Coverage and balance are correctness. Spacing is the quality term that
    // differentiates otherwise valid generated tables.
    aAnalysis.mScore = SoccerFoldingFinalScore{
        aCoveragePassed,
        aSlotBalancePassed,
        aExpectedSourceBlockCount,
        aUsedSourceBlockCount,
        aUniqueSourceBlockCount,
        aDuplicateSourceBlockCount,
        aOutOfRangeItemCount,
        aMinimumDistance,
        aAverageDistance,
        aCoverageScore,
        aBalanceScore,
        aSpacingScore,
        (aCoverageScore * 0.40) +
        (aBalanceScore * 0.30) +
        (aSpacingScore * 0.30),
    };
    return aAnalysis;
}

static void PrintFinalAnalysis(
    const SoccerFoldingToolSpecification &pSpecification,
    const SoccerFoldingDimensions &pDimensions,
    std::uint64_t pGeneratedSeed,
    const SoccerFoldingAnalysis &pAnalysis) {
    std::fprintf(stderr,
                 "\nSoccerFoldingTool: %s\n",
                 pSpecification.mFunctionDeclaration.c_str());
    std::fprintf(stderr,
                 "  generated seed: %llu\n",
                 static_cast<unsigned long long>(pGeneratedSeed));

    for (std::size_t aSourceLaneIndex=0U;
         aSourceLaneIndex<pDimensions.mInputLaneCount;
         aSourceLaneIndex++) {
        std::size_t aSourceUseCount = 0U;
        std::fprintf(stderr,
                     "  source [%2zu] %-32s",
                     aSourceLaneIndex,
                     pSpecification.mInputLaneNames[aSourceLaneIndex].c_str());
        for (std::size_t aDestinationLaneIndex=0U;
             aDestinationLaneIndex<pDimensions.mOutputLaneCount;
             aDestinationLaneIndex++) {
            const std::size_t aUseCount =
                pAnalysis.mDestinationSourceUseCounts[aDestinationLaneIndex]
                                                     [aSourceLaneIndex];
            aSourceUseCount += aUseCount;
            const double aUsePercent =
                100.0 * static_cast<double>(aUseCount) /
                static_cast<double>(pSpecification.mInputBlockCount);
            std::fprintf(stderr,
                         " D%zu=%zu/%zu (%6.2f%%)",
                         aDestinationLaneIndex,
                         aUseCount,
                         pSpecification.mInputBlockCount,
                         aUsePercent);
        }

        const std::size_t aUniqueCount =
            pAnalysis.mUniqueSourceBlocks[aSourceLaneIndex].size();
        const bool aSourcePassed =
            (aSourceUseCount == pSpecification.mInputBlockCount) &&
            (aUniqueCount == pSpecification.mInputBlockCount);
        std::fprintf(stderr,
                     " | total=%zu/%zu unique=%zu/%zu [%s]\n",
                     aSourceUseCount,
                     pSpecification.mInputBlockCount,
                     aUniqueCount,
                     pSpecification.mInputBlockCount,
                     aSourcePassed ? "PASS" : "FAIL");
    }

    const SoccerFoldingFinalScore &aScore = pAnalysis.mScore;
    std::fprintf(stderr,
                 "  coverage: %.2f/100 (%zu used, %zu unique, %zu duplicate, %zu out-of-range) [%s]\n",
                 aScore.mCoverageScore,
                 aScore.mUsedSourceBlockCount,
                 aScore.mUniqueSourceBlockCount,
                 aScore.mDuplicateSourceBlockCount,
                 aScore.mOutOfRangeItemCount,
                 aScore.mCoveragePassed ? "PASS" : "FAIL");
    std::fprintf(stderr,
                 "  destination balance: %.2f/100\n",
                 aScore.mBalanceScore);
    std::fprintf(stderr,
                 "  source-slot balance: expected %zu per destination/slot/source [%s]\n",
                 pDimensions.mSourceLaneSlotUseCountPerOutputLane,
                 aScore.mSlotBalancePassed ? "PASS" : "FAIL");
    std::fprintf(stderr,
                 "  block spacing: %.2f/100 (minimum %zu blocks, average %.2f blocks)\n",
                 aScore.mSpacingScore,
                 aScore.mMinimumDistance,
                 aScore.mAverageDistance);
    std::fprintf(stderr,
                 "  FINAL SCORE: %.2f/100 (40%% coverage + 30%% balance + 30%% spacing)\n",
                 aScore.mFinalScore);
}

static void PrintStringList(FILE *pOutput,
                            const std::vector<std::string> &pNames) {
    for (std::size_t aIndex=0U; aIndex<pNames.size(); aIndex++) {
        std::fprintf(pOutput,
                     "        %s%s\n",
                     pNames[aIndex].c_str(),
                     (aIndex + 1U < pNames.size()) ? "," : "");
    }
}

static void PrintRollPieces(FILE *pOutput,
                            const SoccerFoldingRoll &pRoll) {
    std::fprintf(pOutput, "{");
    for (std::size_t aIndex=0U; aIndex<pRoll.size(); aIndex++) {
        std::fprintf(pOutput,
                     "{%zuU, %zuU}%s",
                     pRoll[aIndex].mSourceLaneIndex,
                     pRoll[aIndex].mSourceBlockIndex,
                     (aIndex + 1U < pRoll.size()) ? ", " : "");
    }
    std::fprintf(pOutput, "}");
}

static void EmitFoldBody(FILE *pOutput,
                         std::size_t pFoldItemCount) {
    static constexpr char aSourceNames[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for (std::size_t aSourceIndex=0U; aSourceIndex<pFoldItemCount; aSourceIndex++) {
        std::fprintf(pOutput,
                     "        const FoldingPiece &aSourcePiece%c = aRoll.mSources[%zuU];\n"
                     "        const std::uint8_t *const aSource%c = &aSourceLanes[aSourcePiece%c.mLane][aSourcePiece%c.mBlock * aBlockByteCount];\n",
                     aSourceNames[aSourceIndex],
                     aSourceIndex,
                     aSourceNames[aSourceIndex],
                     aSourceNames[aSourceIndex],
                     aSourceNames[aSourceIndex]);
    }

    std::fprintf(pOutput, "\n");
    std::fprintf(pOutput, "        for (std::size_t aIndex=0U; aIndex<aBlockByteCount; aIndex++) {\n");
    std::fprintf(pOutput, "            const std::size_t aIndexForward = aIndex;\n");
    std::fprintf(pOutput, "            const std::size_t aIndexBackward = aBlockByteCount - 1U - aIndex;\n\n");

    if (pFoldItemCount == 2U) {
        std::fprintf(pOutput, "            std::uint16_t aFoldValue = 0U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint16_t>(aSourceA[aIndexForward]) << 0U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint16_t>(aSourceB[aIndexBackward]) << 8U;\n");
        std::fprintf(pOutput, "            aFoldValue = TwistMix16::DiffuseA(aFoldValue);\n");
        std::fprintf(pOutput, "            aDestination[aIndex] = static_cast<std::uint8_t>(aFoldValue);\n");
    } else if (pFoldItemCount == 4U) {
        std::fprintf(pOutput, "            std::uint32_t aFoldValue = 0U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint32_t>(aSourceA[aIndexForward]) <<  0U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint32_t>(aSourceB[aIndexBackward]) <<  8U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint32_t>(aSourceC[aIndexForward]) << 16U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint32_t>(aSourceD[aIndexBackward]) << 24U;\n");
        std::fprintf(pOutput, "            aFoldValue = TwistMix32::DiffuseA(aFoldValue);\n");
        std::fprintf(pOutput, "            aDestination[aIndex] = static_cast<std::uint8_t>(aFoldValue);\n");
    } else {
        std::fprintf(pOutput, "            std::uint32_t aFoldValueA = 0U;\n");
        std::fprintf(pOutput, "            aFoldValueA |= static_cast<std::uint32_t>(aSourceA[aIndexForward]) <<  0U;\n");
        std::fprintf(pOutput, "            aFoldValueA |= static_cast<std::uint32_t>(aSourceB[aIndexBackward]) <<  8U;\n");
        std::fprintf(pOutput, "            aFoldValueA |= static_cast<std::uint32_t>(aSourceC[aIndexForward]) << 16U;\n");
        std::fprintf(pOutput, "            aFoldValueA |= static_cast<std::uint32_t>(aSourceD[aIndexBackward]) << 24U;\n");
        std::fprintf(pOutput, "            aFoldValueA = TwistMix32::DiffuseA(aFoldValueA);\n\n");
        std::fprintf(pOutput, "            std::uint32_t aFoldValueB = 0U;\n");
        std::fprintf(pOutput, "            aFoldValueB |= static_cast<std::uint32_t>(aSourceE[aIndexForward]) <<  0U;\n");
        std::fprintf(pOutput, "            aFoldValueB |= static_cast<std::uint32_t>(aSourceF[aIndexBackward]) <<  8U;\n");
        std::fprintf(pOutput, "            aFoldValueB |= static_cast<std::uint32_t>(aSourceG[aIndexForward]) << 16U;\n");
        std::fprintf(pOutput, "            aFoldValueB |= static_cast<std::uint32_t>(aSourceH[aIndexBackward]) << 24U;\n");
        std::fprintf(pOutput, "            aFoldValueB = TwistMix32::DiffuseA(aFoldValueB);\n\n");
        std::fprintf(pOutput, "            std::uint16_t aFoldValue = 0U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint16_t>(static_cast<std::uint8_t>(aFoldValueA)) << 0U;\n");
        std::fprintf(pOutput, "            aFoldValue |= static_cast<std::uint16_t>(static_cast<std::uint8_t>(aFoldValueB)) << 8U;\n");
        std::fprintf(pOutput, "            aFoldValue = TwistMix16::DiffuseA(aFoldValue);\n");
        std::fprintf(pOutput, "            aDestination[aIndex] = static_cast<std::uint8_t>(aFoldValue);\n");
    }

    std::fprintf(pOutput, "        }\n");
}

static void EmitCode(FILE *pOutput,
                     const SoccerFoldingToolSpecification &pSpecification,
                     const SoccerFoldingDimensions &pDimensions,
                     const std::vector<SoccerFoldingRoll> &pRolls,
                     std::uint64_t pGeneratedSeed,
                     const SoccerFoldingFinalScore &pScore) {
    std::fprintf(pOutput,
                 "\n// Final score %.2f/100: coverage %.2f, balance %.2f, spacing %.2f.\n",
                 pScore.mFinalScore,
                 pScore.mCoverageScore,
                 pScore.mBalanceScore,
                 pScore.mSpacingScore);
    std::fprintf(pOutput,
                 "// Spacing: minimum %zu blocks, average %.2f blocks.\n",
                 pScore.mMinimumDistance,
                 pScore.mAverageDistance);
    std::fprintf(pOutput,
                 "%s {\n",
                 pSpecification.mFunctionDeclaration.c_str());
    std::fprintf(pOutput,
                 "    // Generated by SoccerFoldingTool: %zu random trials per roll, seed %llu.\n",
                 pSpecification.mRandomTrialCount,
                 static_cast<unsigned long long>(pGeneratedSeed));
    std::fprintf(pOutput,
                 "    constexpr std::size_t aBlockByteCount = %zuU;\n",
                 pDimensions.mBlockByteCount);
    std::fprintf(pOutput, "\n");

    std::fprintf(pOutput, "    struct FoldingPiece {\n");
    std::fprintf(pOutput, "        std::uint8_t mLane;\n");
    std::fprintf(pOutput, "        std::uint16_t mBlock;\n");
    std::fprintf(pOutput, "    };\n\n");
    std::fprintf(pOutput, "    struct FoldingRoll {\n");
    std::fprintf(pOutput,
                 "        FoldingPiece mSources[%zu];\n",
                 pSpecification.mFoldItemCount);
    std::fprintf(pOutput, "        FoldingPiece mDestination;\n");
    std::fprintf(pOutput, "    };\n\n");

    std::fprintf(pOutput,
                 "    // Static storage: the generated table does not consume thread stack space.\n");
    std::fprintf(pOutput,
                 "    static constexpr FoldingRoll aRolls[%zu] = {\n",
                 pRolls.size());
    for (std::size_t aRollIndex=0U;
         aRollIndex<pRolls.size();
         aRollIndex++) {
        const SoccerFoldingRoll &aRoll = pRolls[aRollIndex];
        const std::size_t aDestinationLaneIndex =
            aRollIndex % pDimensions.mOutputLaneCount;
        const std::size_t aDestinationBlockIndex =
            aRollIndex / pDimensions.mOutputLaneCount;
        std::fprintf(pOutput, "        {");
        PrintRollPieces(pOutput, aRoll);
        std::fprintf(pOutput,
                     ", {%zuU, %zuU}},\n",
                     aDestinationLaneIndex,
                     aDestinationBlockIndex);
    }
    std::fprintf(pOutput, "    };\n\n");

    std::fprintf(pOutput,
                 "    const std::uint8_t *const aSourceLanes[%zu] = {\n",
                 pDimensions.mInputLaneCount);
    PrintStringList(pOutput, pSpecification.mInputLaneNames);
    std::fprintf(pOutput, "    };\n\n");

    std::fprintf(pOutput,
                 "    std::uint8_t *const aDestinationLanes[%zu] = {\n",
                 pDimensions.mOutputLaneCount);
    PrintStringList(pOutput, pSpecification.mOutputLaneNames);
    std::fprintf(pOutput, "    };\n\n");

    std::fprintf(pOutput,
                 "    for (std::size_t aRollIndex=0U; aRollIndex<%zuU; aRollIndex++) {\n",
                 pRolls.size());
    std::fprintf(pOutput, "        const FoldingRoll &aRoll = aRolls[aRollIndex];\n");
    std::fprintf(pOutput, "        const FoldingPiece &aDestinationPiece = aRoll.mDestination;\n");
    std::fprintf(pOutput, "        std::uint8_t *const aDestination = &aDestinationLanes[aDestinationPiece.mLane][aDestinationPiece.mBlock * aBlockByteCount];\n\n");

    EmitFoldBody(pOutput, pSpecification.mFoldItemCount);

    std::fprintf(pOutput, "    }\n");
    std::fprintf(pOutput, "}\n\n");
}

static bool EmitToOutput(
    const SoccerFoldingToolSpecification &pSpecification,
    FILE *pOutput,
    double *pFinalScore) {
    SoccerFoldingDimensions aDimensions{};
    if ((pOutput == nullptr) ||
        !ValidateSpecification(pSpecification, aDimensions)) {
        return false;
    }

    std::vector<SoccerFoldingRoll> aRolls;
    constexpr std::size_t aMaximumGenerationAttempts = 8U;
    for (std::size_t aAttempt=0U;
         aAttempt<aMaximumGenerationAttempts;
         aAttempt++) {
        const std::uint64_t aSeed =
            pSpecification.mRandomSeed +
            (static_cast<std::uint64_t>(aAttempt) *
             0x9E3779B97F4A7C15ULL);
        if (!GenerateRolls(pSpecification, aDimensions, aSeed, aRolls)) {
            continue;
        }

        const SoccerFoldingAnalysis aAnalysis = AnalyzeFinalRolls(
            pSpecification,
            aDimensions,
            aRolls);
        PrintFinalAnalysis(pSpecification,
                           aDimensions,
                           aSeed,
                           aAnalysis);
        if (!aAnalysis.mScore.mCoveragePassed ||
            !aAnalysis.mScore.mSlotBalancePassed ||
            (aAnalysis.mScore.mBalanceScore < 99.999)) {
            std::fprintf(stderr,
                         "SoccerFoldingTool: rejecting a roll that failed final verification.\n");
            continue;
        }
        EmitCode(pOutput,
                 pSpecification,
                 aDimensions,
                 aRolls,
                 aSeed,
                 aAnalysis.mScore);
        if (pFinalScore != nullptr) {
            *pFinalScore = aAnalysis.mScore.mFinalScore;
        }
        return true;
    }

    std::fprintf(stderr,
                 "SoccerFoldingTool: failed to complete a valid fold after %zu attempts.\n",
                 aMaximumGenerationAttempts);
    return false;
}

static bool EmitFinalHeader(FILE *pOutput,
                            std::size_t pRandomTrialCount,
                            std::uint64_t pRunSeed,
                            double pOverallFinalScore) {
    if (pOutput == nullptr) {
        return false;
    }

    std::fprintf(pOutput,
                 "//\n"
                 "//  SoccerFolding_%zu.hpp\n"
                 "//  Generated by SoccerFoldingTool\n"
                 "//\n"
                 "// Trials per roll: %zu. Run seed: %llu. Overall score: %.2f/100.\n"
                 "// Compile this header with only its matching generated .cpp file.\n"
                 "//\n\n",
                 pRandomTrialCount,
                 pRandomTrialCount,
                 static_cast<unsigned long long>(pRunSeed),
                 pOverallFinalScore);
    std::fprintf(pOutput,
                 "#ifndef SoccerFolding_%zu_hpp\n"
                 "#define SoccerFolding_%zu_hpp\n\n",
                 pRandomTrialCount,
                 pRandomTrialCount);
    std::fprintf(pOutput,
                 "#include <cstdint>\n\n"
                 "class SoccerFolding {\n"
                 "public:\n"
                 "    static void CollapseFold_Outer_16(const std::uint8_t *pSourceA,\n"
                 "                                            const std::uint8_t *pSourceB,\n"
                 "                                            const std::uint8_t *pSourceC,\n"
                 "                                            const std::uint8_t *pSourceD,\n"
                 "                                            const std::uint8_t *pSourceE,\n"
                 "                                            const std::uint8_t *pSourceF,\n"
                 "                                            const std::uint8_t *pSourceG,\n"
                 "                                            const std::uint8_t *pSourceH,\n"
                 "                                            const std::uint8_t *pSourceI,\n"
                 "                                            const std::uint8_t *pSourceJ,\n"
                 "                                            const std::uint8_t *pSourceK,\n"
                 "                                            const std::uint8_t *pSourceL,\n"
                 "                                            const std::uint8_t *pSourceM,\n"
                 "                                            const std::uint8_t *pSourceN,\n"
                 "                                            const std::uint8_t *pSourceO,\n"
                 "                                            const std::uint8_t *pSourceP,\n"
                 "                                            std::uint8_t *pDestinationA,\n"
                 "                                            std::uint8_t *pDestinationB,\n"
                 "                                            std::uint8_t *pDestinationC,\n"
                 "                                            std::uint8_t *pDestinationD);\n\n"
                 "    static void CollapseFold_Outer_8(const std::uint8_t *pSourceA,\n"
                 "                                           const std::uint8_t *pSourceB,\n"
                 "                                           const std::uint8_t *pSourceC,\n"
                 "                                           const std::uint8_t *pSourceD,\n"
                 "                                           const std::uint8_t *pSourceE,\n"
                 "                                           const std::uint8_t *pSourceF,\n"
                 "                                           const std::uint8_t *pSourceG,\n"
                 "                                           const std::uint8_t *pSourceH,\n"
                 "                                           std::uint8_t *pDestinationA,\n"
                 "                                           std::uint8_t *pDestinationB,\n"
                 "                                           std::uint8_t *pDestinationC,\n"
                 "                                           std::uint8_t *pDestinationD);\n\n"
                 "    static void ShrinkFold_4(const std::uint8_t *pSourceA,\n"
                 "                             const std::uint8_t *pSourceB,\n"
                 "                             const std::uint8_t *pSourceC,\n"
                 "                             const std::uint8_t *pSourceD,\n"
                 "                             std::uint8_t *pDestinationA,\n"
                 "                             std::uint8_t *pDestinationB,\n"
                 "                             std::uint8_t *pDestinationC,\n"
                 "                             std::uint8_t *pDestinationD);\n\n"
                 "    static void CrushFold(const std::uint8_t *pSourceA,\n"
                 "                          const std::uint8_t *pSourceB,\n"
                 "                          const std::uint8_t *pSourceC,\n"
                 "                          const std::uint8_t *pSourceD,\n"
                 "                          std::uint8_t *pDestinationA,\n"
                 "                          std::uint8_t *pDestinationB,\n"
                 "                          std::uint8_t *pDestinationC,\n"
                 "                          std::uint8_t *pDestinationD);\n"
                 "};\n\n");
    std::fprintf(pOutput,
                 "#endif /* SoccerFolding_%zu_hpp */\n",
                 pRandomTrialCount);
    return std::ferror(pOutput) == 0;
}

static bool MakeOutputPaths(std::size_t pRandomTrialCount,
                            std::filesystem::path &pHeaderPath,
                            std::filesystem::path &pSourcePath) {
    const std::filesystem::path aDirectory =
        std::filesystem::path(FileIO::ProjectRoot()) /
        "Assets" /
        "foldgen";
    std::error_code aError;
    std::filesystem::create_directories(aDirectory, aError);
    if (aError) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: could not create %s: %s.\n",
                     aDirectory.string().c_str(),
                     aError.message().c_str());
        return false;
    }

    char aHeaderFileName[96]{};
    std::snprintf(aHeaderFileName,
                  sizeof(aHeaderFileName),
                  "SoccerFolding_%zu.hpp",
                  pRandomTrialCount);
    char aSourceFileName[96]{};
    std::snprintf(aSourceFileName,
                  sizeof(aSourceFileName),
                  "SoccerFolding_%zu.cpp",
                  pRandomTrialCount);
    pHeaderPath = aDirectory / aHeaderFileName;
    pSourcePath = aDirectory / aSourceFileName;
    return true;
}

} // namespace

bool SoccerFoldingTool::Emit(const SoccerFoldingToolSpecification &pSpecification) {
    return EmitToOutput(pSpecification, stdout, nullptr);
}


bool SoccerFoldingTool::Run() {
    std::random_device aRandomDevice;
    const std::uint64_t aRunSeed =
        static_cast<std::uint64_t>(
            std::chrono::high_resolution_clock::now()
                .time_since_epoch()
                .count()) ^
        (static_cast<std::uint64_t>(aRandomDevice()) << 32U) ^
        static_cast<std::uint64_t>(aRandomDevice());

    return Run(4096U, aRunSeed);
}

bool SoccerFoldingTool::Run(std::size_t pRandomTrialCount,
                            std::uint64_t pRunSeed) {
    if (pRandomTrialCount == 0U) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: random trial count must be non-zero.\n");
        return false;
    }

    constexpr std::size_t aOuterInputBlockCount = 1024U;
    constexpr std::size_t aShrinkInputBlockCount = 256U;
    constexpr std::size_t aCrushInputBlockCount = 64U;
    const std::size_t aRandomTrialCount = pRandomTrialCount;
    const std::uint64_t aRunSeed = pRunSeed;

    const SoccerFoldingToolSpecification aSpecifications[] = {
        {
            "void SoccerFolding::CollapseFold_Outer_16("
            "const std::uint8_t *pSourceA, const std::uint8_t *pSourceB, "
            "const std::uint8_t *pSourceC, const std::uint8_t *pSourceD, "
            "const std::uint8_t *pSourceE, const std::uint8_t *pSourceF, "
            "const std::uint8_t *pSourceG, const std::uint8_t *pSourceH, "
            "const std::uint8_t *pSourceI, const std::uint8_t *pSourceJ, "
            "const std::uint8_t *pSourceK, const std::uint8_t *pSourceL, "
            "const std::uint8_t *pSourceM, const std::uint8_t *pSourceN, "
            "const std::uint8_t *pSourceO, const std::uint8_t *pSourceP, "
            "std::uint8_t *pDestinationA, std::uint8_t *pDestinationB, "
            "std::uint8_t *pDestinationC, std::uint8_t *pDestinationD)",
            SOCCER_BLOCK_SIZE,
            {
                "pSourceA", "pSourceB", "pSourceC", "pSourceD",
                "pSourceE", "pSourceF", "pSourceG", "pSourceH",
                "pSourceI", "pSourceJ", "pSourceK", "pSourceL",
                "pSourceM", "pSourceN", "pSourceO", "pSourceP",
            },
            SOCCER_BLOCK_SIZE,
            {
                "pDestinationA", "pDestinationB",
                "pDestinationC", "pDestinationD",
            },
            aOuterInputBlockCount,
            4U,
            aRandomTrialCount,
            aRunSeed ^ 0xA0761D6478BD642FULL,
        },
        {
            "void SoccerFolding::CollapseFold_Outer_8("
            "const std::uint8_t *pSourceA, const std::uint8_t *pSourceB, "
            "const std::uint8_t *pSourceC, const std::uint8_t *pSourceD, "
            "const std::uint8_t *pSourceE, const std::uint8_t *pSourceF, "
            "const std::uint8_t *pSourceG, const std::uint8_t *pSourceH, "
            "std::uint8_t *pDestinationA, std::uint8_t *pDestinationB, "
            "std::uint8_t *pDestinationC, std::uint8_t *pDestinationD)",
            SOCCER_BLOCK_SIZE,
            {
                "pSourceA", "pSourceB", "pSourceC", "pSourceD",
                "pSourceE", "pSourceF", "pSourceG", "pSourceH",
            },
            SOCCER_BLOCK_SIZE,
            {
                "pDestinationA", "pDestinationB",
                "pDestinationC", "pDestinationD",
            },
            aOuterInputBlockCount,
            2U,
            aRandomTrialCount,
            aRunSeed ^ 0xE7037ED1A0B428DBULL,
        },
        {
            "void SoccerFolding::ShrinkFold_4("
            "const std::uint8_t *pSourceA, const std::uint8_t *pSourceB, "
            "const std::uint8_t *pSourceC, const std::uint8_t *pSourceD, "
            "std::uint8_t *pDestinationA, std::uint8_t *pDestinationB, "
            "std::uint8_t *pDestinationC, std::uint8_t *pDestinationD)",
            SOCCER_BLOCK_SIZE,
            {
                "pSourceA", "pSourceB", "pSourceC", "pSourceD",
            },
            SOCCER_BLOCK_SIZE_L1,
            {
                "pDestinationA", "pDestinationB",
                "pDestinationC", "pDestinationD",
            },
            aShrinkInputBlockCount,
            4U,
            aRandomTrialCount,
            aRunSeed ^ 0x8EBC6AF09C88C6E3ULL,
        },
        {
            "void SoccerFolding::CrushFold("
            "const std::uint8_t *pSourceA, const std::uint8_t *pSourceB, "
            "const std::uint8_t *pSourceC, const std::uint8_t *pSourceD, "
            "std::uint8_t *pDestinationA, std::uint8_t *pDestinationB, "
            "std::uint8_t *pDestinationC, std::uint8_t *pDestinationD)",
            SOCCER_BLOCK_SIZE_L1,
            {
                "pSourceA", "pSourceB", "pSourceC", "pSourceD",
            },
            S_BLOCK,
            {
                "pDestinationA", "pDestinationB",
                "pDestinationC", "pDestinationD",
            },
            aCrushInputBlockCount,
            8U,
            aRandomTrialCount,
            aRunSeed ^ 0x589965CC75374CC3ULL,
        },
    };

    std::filesystem::path aArchivePath;
    if (!MakeArchivePath(pRandomTrialCount, aArchivePath)) {
        return false;
    }

    FILE *aOutput = std::fopen(aArchivePath.string().c_str(), "wb");
    if (aOutput == nullptr) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: could not open %s for writing.\n",
                     aArchivePath.string().c_str());
        return false;
    }

    std::fprintf(aOutput,
                 "// Generated Soccer folding roll archive.\n"
                 "// Do not edit; compare the embedded scores before promoting a roll.\n"
                 "// Run seed: %llu.\n\n"
                 "#pragma once\n\n"
                 "#include \"../../Scramble/Composer/SoccerFolding.hpp\"\n"
                 "#include \"../../Scramble/Expander/Core/TwistMix16.hpp\"\n"
                 "#include \"../../Scramble/Expander/Core/TwistMix32.hpp\"\n\n"
                 "#include <cstddef>\n"
                 "#include <cstdint>\n",
                 static_cast<unsigned long long>(aRunSeed));

    constexpr std::size_t aSpecificationCount =
        sizeof(aSpecifications) / sizeof(aSpecifications[0]);
    double aTotalFinalScore = 0.0;
    for (const SoccerFoldingToolSpecification &aSpecification :
         aSpecifications) {
        double aFinalScore = 0.0;
        if (!EmitToOutput(aSpecification, aOutput, &aFinalScore)) {
            std::fclose(aOutput);
            std::error_code aError;
            std::filesystem::remove(aArchivePath, aError);
            return false;
        }
        aTotalFinalScore += aFinalScore;
    }

    const double aOverallFinalScore =
        aTotalFinalScore / static_cast<double>(aSpecificationCount);
    std::fprintf(aOutput,
                 "// Overall final score: %.2f/100 across %zu folding methods.\n",
                 aOverallFinalScore,
                 aSpecificationCount);

    if (std::fclose(aOutput) != 0) {
        std::fprintf(stderr,
                     "SoccerFoldingTool: could not finish writing %s.\n",
                     aArchivePath.string().c_str());
        std::error_code aError;
        std::filesystem::remove(aArchivePath, aError);
        return false;
    }

    std::printf("\nSoccerFoldingTool: overall score %.2f/100.\n",
                aOverallFinalScore);
    std::printf("SoccerFoldingTool: run seed %llu.\n",
                static_cast<unsigned long long>(aRunSeed));
    std::printf("SoccerFoldingTool: exported %s\n",
                aArchivePath.string().c_str());

    return true;
}
