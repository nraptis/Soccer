//
//  LaneCountTool.cpp
//  Soccer
//
//  Emits the seven-stage LaneCombinations.cpp table.
//

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <vector>

namespace {

constexpr std::size_t kStageCount = 7U;

enum class LaneStage : std::size_t {
    kL3A = 0U,
    kL2A = 1U,
    kL1A = 2U,
    kL3B = 3U,
    kL2B = 4U,
    kL1B = 5U,
    kL3C = 6U,
};

constexpr std::array<std::size_t, kStageCount> kQuarterLaneMultiplier{
    4U,
    2U,
    1U,
    4U,
    2U,
    1U,
    4U,
};

constexpr std::array<std::uint8_t, 2U> kSimpleOptions{1U, 2U};
constexpr std::array<std::uint8_t, 4U> kAnyOptions{1U, 2U, 3U, 4U};

struct LaneSlot {
    std::size_t mStage;
    std::size_t mRound;
    bool mSimple;
};

struct GeneratedLaneCombination {
    std::uint8_t mCount[kStageCount][2] = {};
};

struct LaneGeneratorSpecification {
    std::size_t mMinimumQuarterLaneCount;
    std::size_t mMaximumQuarterLaneCount;
    std::size_t mMinimumCount3;
    std::size_t mMaximumCount3;
    std::size_t mMinimumCount4;
    std::size_t mMaximumCount4;
    std::vector<LaneSlot> mSlots;
};

std::size_t CountQuarterLanes(const GeneratedLaneCombination &pCombination) {
    std::size_t aResult = 0U;
    for (std::size_t aStage=0U; aStage<kStageCount; aStage++) {
        for (std::size_t aRound=0U; aRound<2U; aRound++) {
            aResult += static_cast<std::size_t>(pCombination.mCount[aStage][aRound]) *
                       kQuarterLaneMultiplier[aStage];
        }
    }
    return aResult;
}

bool CanReachTarget(const LaneGeneratorSpecification &pSpecification,
                    std::size_t pSlotIndex,
                    std::size_t pConsumedQuarterLaneCount) {
    std::size_t aMinimumRemaining = 0U;
    std::size_t aMaximumRemaining = 0U;

    for (std::size_t aIndex=pSlotIndex; aIndex<pSpecification.mSlots.size(); aIndex++) {
        const LaneSlot &aSlot = pSpecification.mSlots[aIndex];
        aMinimumRemaining += kQuarterLaneMultiplier[aSlot.mStage];
        aMaximumRemaining +=
            (aSlot.mSimple ? 2U : 4U) * kQuarterLaneMultiplier[aSlot.mStage];
    }

    return ((pConsumedQuarterLaneCount + aMinimumRemaining) <=
            pSpecification.mMaximumQuarterLaneCount) &&
           ((pConsumedQuarterLaneCount + aMaximumRemaining) >=
            pSpecification.mMinimumQuarterLaneCount);
}

void GenerateLaneCombinations(const LaneGeneratorSpecification &pSpecification,
                              std::size_t pSlotIndex,
                              std::size_t pConsumedQuarterLaneCount,
                              std::size_t pCount3,
                              std::size_t pCount4,
                              GeneratedLaneCombination &pCombination,
                              std::vector<GeneratedLaneCombination> &pResults) {
    if (!CanReachTarget(pSpecification,
                        pSlotIndex,
                        pConsumedQuarterLaneCount)) {
        return;
    }

    if (pSlotIndex == pSpecification.mSlots.size()) {
        if ((pCount3 < pSpecification.mMinimumCount3) ||
            (pCount4 < pSpecification.mMinimumCount4)) {
            return;
        }
        pResults.push_back(pCombination);
        return;
    }

    const LaneSlot &aSlot = pSpecification.mSlots[pSlotIndex];
    const std::uint8_t *aOptions = aSlot.mSimple ?
        kSimpleOptions.data() : kAnyOptions.data();
    const std::size_t aOptionCount = aSlot.mSimple ?
        kSimpleOptions.size() : kAnyOptions.size();

    for (std::size_t aOptionIndex=0U; aOptionIndex<aOptionCount; aOptionIndex++) {
        const std::uint8_t aLaneCount = aOptions[aOptionIndex];
        const std::size_t aCount3 = pCount3 + ((aLaneCount == 3U) ? 1U : 0U);
        const std::size_t aCount4 = pCount4 + ((aLaneCount == 4U) ? 1U : 0U);

        if ((aCount3 > pSpecification.mMaximumCount3) ||
            (aCount4 > pSpecification.mMaximumCount4)) {
            continue;
        }

        const std::size_t aConsumedQuarterLaneCount =
            pConsumedQuarterLaneCount +
            (static_cast<std::size_t>(aLaneCount) *
             kQuarterLaneMultiplier[aSlot.mStage]);
        if (aConsumedQuarterLaneCount > pSpecification.mMaximumQuarterLaneCount) {
            continue;
        }

        pCombination.mCount[aSlot.mStage][aSlot.mRound] = aLaneCount;
        GenerateLaneCombinations(pSpecification,
                                 pSlotIndex + 1U,
                                 aConsumedQuarterLaneCount,
                                 aCount3,
                                 aCount4,
                                 pCombination,
                                 pResults);
    }
}

LaneGeneratorSpecification MakeWeakSpecification() {
    return LaneGeneratorSpecification{
        13U,
        16U,
        0U,
        1U,
        0U,
        1U,
        {
            {static_cast<std::size_t>(LaneStage::kL3A), 0U, true},
            {static_cast<std::size_t>(LaneStage::kL2A), 0U, false},
            {static_cast<std::size_t>(LaneStage::kL1A), 0U, false},
            {static_cast<std::size_t>(LaneStage::kL3B), 0U, true},
        },
    };
}

LaneGeneratorSpecification MakeNormalSpecification() {
    return LaneGeneratorSpecification{
        29U,
        32U,
        0U,
        1U,
        0U,
        1U,
        {
            {static_cast<std::size_t>(LaneStage::kL3A), 0U, false},
            {static_cast<std::size_t>(LaneStage::kL2A), 0U, true},
            {static_cast<std::size_t>(LaneStage::kL1A), 0U, false},
            {static_cast<std::size_t>(LaneStage::kL3B), 0U, true},
            {static_cast<std::size_t>(LaneStage::kL2B), 0U, true},
            {static_cast<std::size_t>(LaneStage::kL1B), 0U, false},
            {static_cast<std::size_t>(LaneStage::kL3C), 0U, false},
        },
    };
}

LaneGeneratorSpecification MakeStrongSpecification() {
    // Preserve the previous generator's five Simple and nine Any/Complex
    // option sets, but deal them from the beginning across all seven stages.
    constexpr std::array<bool, 14U> aSimpleByRoundRobinSlot{
        true,  false, false, false, true,  false, false,
        false, true,  false, true,  true,  false, false,
    };

    LaneGeneratorSpecification aResult{
        61U,
        64U,
        1U,
        1U,
        1U,
        1U,
        {},
    };

    for (std::size_t aRound=0U; aRound<2U; aRound++) {
        for (std::size_t aStage=0U; aStage<kStageCount; aStage++) {
            const std::size_t aSlotIndex = (aRound * kStageCount) + aStage;
            aResult.mSlots.push_back(LaneSlot{
                aStage,
                aRound,
                aSimpleByRoundRobinSlot[aSlotIndex],
            });
        }
    }

    return aResult;
}

std::vector<GeneratedLaneCombination> Generate(const LaneGeneratorSpecification &pSpecification) {
    GeneratedLaneCombination aCombination;
    std::vector<GeneratedLaneCombination> aResults;
    GenerateLaneCombinations(pSpecification,
                             0U,
                             0U,
                             0U,
                             0U,
                             aCombination,
                             aResults);
    return aResults;
}

std::vector<GeneratedLaneCombination> SelectStrongCombinations(
    const std::vector<GeneratedLaneCombination> &pCandidates) {
    // Keep the previous table's total size and its exact lane-budget spread.
    constexpr std::array<std::size_t, 4U> aDesiredCountByTotal{
        2742U,
        3622U,
        4592U,
        5668U,
    };

    std::array<std::vector<std::size_t>, 4U> aCandidateIndexByTotal;
    for (std::size_t aIndex=0U; aIndex<pCandidates.size(); aIndex++) {
        const std::size_t aQuarterLaneCount = CountQuarterLanes(pCandidates[aIndex]);
        aCandidateIndexByTotal[aQuarterLaneCount - 61U].push_back(aIndex);
    }

    std::vector<bool> aSelected(pCandidates.size(), false);
    for (std::size_t aTotalIndex=0U; aTotalIndex<4U; aTotalIndex++) {
        const std::vector<std::size_t> &aPool = aCandidateIndexByTotal[aTotalIndex];
        const std::size_t aDesiredCount = aDesiredCountByTotal[aTotalIndex];
        if (aPool.size() < aDesiredCount) {
            return {};
        }

        for (std::size_t aIndex=0U; aIndex<aDesiredCount; aIndex++) {
            const std::size_t aPoolIndex = (aIndex * aPool.size()) / aDesiredCount;
            aSelected[aPool[aPoolIndex]] = true;
        }
    }

    std::vector<GeneratedLaneCombination> aResult;
    for (std::size_t aIndex=0U; aIndex<pCandidates.size(); aIndex++) {
        if (aSelected[aIndex]) {
            aResult.push_back(pCandidates[aIndex]);
        }
    }
    return aResult;
}

void PrintList(const GeneratedLaneCombination &pCombination,
               std::size_t pStage,
               std::size_t pCount) {
    std::printf("{");
    for (std::size_t aIndex=0U; aIndex<pCount; aIndex++) {
        std::printf("%uU%s",
                    static_cast<unsigned int>(pCombination.mCount[pStage][aIndex]),
                    ((aIndex + 1U) < pCount) ? ", " : "");
    }
    std::printf("}");
}

void PrintCombination(const GeneratedLaneCombination &pCombination,
                      std::size_t pStageCount,
                      std::size_t pCountPerStage) {
    std::printf("    {");
    for (std::size_t aStage=0U; aStage<pStageCount; aStage++) {
        PrintList(pCombination, aStage, pCountPerStage);
        std::printf(((aStage + 1U) < pStageCount) ? ", " : "");
    }
    std::printf("},\n");
}

void PrintTable(const char *pTypeName,
                const char *pMemberName,
                const std::vector<GeneratedLaneCombination> &pCombinations,
                std::size_t pStageCount,
                std::size_t pCountPerStage) {
    std::printf("const %s LaneCombinations::%s[] = {\n", pTypeName, pMemberName);
    for (const GeneratedLaneCombination &aCombination : pCombinations) {
        PrintCombination(aCombination, pStageCount, pCountPerStage);
    }
    std::printf("};\n\n");
}

} // namespace

int main() {
    const std::vector<GeneratedLaneCombination> aWeak =
        Generate(MakeWeakSpecification());
    const std::vector<GeneratedLaneCombination> aNormal =
        Generate(MakeNormalSpecification());
    const std::vector<GeneratedLaneCombination> aStrongCandidates =
        Generate(MakeStrongSpecification());
    const std::vector<GeneratedLaneCombination> aStrong =
        SelectStrongCombinations(aStrongCandidates);

    if ((aWeak.size() != 12U) ||
        (aNormal.size() != 236U) ||
        (aStrong.size() != 16624U)) {
        std::fprintf(stderr,
                     "Unexpected combination counts: Weak(%zu), Normal(%zu), Strong(%zu).\n",
                     aWeak.size(),
                     aNormal.size(),
                     aStrong.size());
        return 1;
    }

    std::printf("//\n");
    std::printf("//  LaneCombinations.cpp\n");
    std::printf("//  Scramble\n");
    std::printf("//\n\n");
    std::printf("#include \"LaneCombinations.hpp\"\n\n");

    PrintTable("WeakLaneCombination", "mWeak", aWeak, 4U, 1U);
    PrintTable("NormalLaneCombination", "mNormal", aNormal, 7U, 1U);
    PrintTable("StrongLaneCombination", "mStrong", aStrong, 7U, 2U);

    std::printf("WeakLaneCombination LaneCombinations::PickWeak(std::uint64_t pSelect) {\n");
    std::printf("    return mWeak[pSelect %% mWeakCount];\n");
    std::printf("}\n\n");
    std::printf("NormalLaneCombination LaneCombinations::PickNormal(std::uint64_t pSelect) {\n");
    std::printf("    return mNormal[pSelect %% mNormalCount];\n");
    std::printf("}\n\n");
    std::printf("StrongLaneCombination LaneCombinations::PickStrong(std::uint64_t pSelect) {\n");
    std::printf("    return mStrong[pSelect %% mStrongCount];\n");
    std::printf("}\n");

    return 0;
}
