//
//  LaneCountTool.cpp
//  Soccer
//
//  Brute-force generator for encryption-plan lane-count schemes.
//

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <vector>

struct LaneCountScheme {
    std::uint8_t mL3;
    std::uint8_t mL2;
    std::uint8_t mL1;
    std::uint8_t mF3;
};

class LaneCountTool {
public:
    static std::vector<LaneCountScheme> FindLowSchemes() {
        std::vector<LaneCountScheme> aResults;

        // Low:
        // L3/F3 use kKeyConsumeSimple, whose available counts are 1 and 2.
        // L2/L1 use kKeyConsumeAny, whose available counts are 1 through 4.
        for (std::uint8_t aL3 = 1U; aL3 <= 2U; ++aL3) {
            for (std::uint8_t aL2 = 1U; aL2 <= 4U; ++aL2) {
                for (std::uint8_t aL1 = 1U; aL1 <= 4U; ++aL1) {
                    for (std::uint8_t aF3 = 1U; aF3 <= 2U; ++aF3) {
                        const LaneCountScheme aCandidate{
                            aL3,
                            aL2,
                            aL1,
                            aF3,
                        };

                        if (UsesEveryLaneInOrder(aCandidate)) {
                            aResults.push_back(aCandidate);
                        }
                    }
                }
            }
        }

        return aResults;
    }

    static void PrintLowSchemesAsCode() {
        const std::vector<LaneCountScheme> aSchemes = FindLowSchemes();

        std::printf("static constexpr LaneCountScheme cLowLaneCountSchemes[] = {\n");

        for (const LaneCountScheme &aScheme : aSchemes) {
            std::printf("    {%uU, %uU, %uU, %uU},\n",
                        static_cast<unsigned int>(aScheme.mL3),
                        static_cast<unsigned int>(aScheme.mL2),
                        static_cast<unsigned int>(aScheme.mL1),
                        static_cast<unsigned int>(aScheme.mF3));
        }

        std::printf("};\n");
    }

private:
    // One real lane is four quarter-lane units:
    //   L3 consumes 4 units per count.
    //   L2 consumes 2 units per count.
    //   L1 consumes 1 unit per count.
    //   F3 consumes 4 units per count.
    static constexpr std::array<std::size_t, 4U> cUnitsPerCount{
        4U,
        2U,
        1U,
        4U,
    };

    static constexpr std::size_t cLowRealLaneCount = 4U;
    static constexpr std::size_t cUnitsPerRealLane = 4U;
    static constexpr std::size_t cLowUnitCount =
        cLowRealLaneCount * cUnitsPerRealLane;

    static bool UsesEveryLaneInOrder(const LaneCountScheme &pScheme) {
        const std::array<std::size_t, 4U> aCounts{
            pScheme.mL3,
            pScheme.mL2,
            pScheme.mL1,
            pScheme.mF3,
        };

        std::size_t aOrderedCursor = 0U;

        for (std::size_t aStage = 0U; aStage < aCounts.size(); ++aStage) {
            aOrderedCursor += aCounts[aStage] * cUnitsPerCount[aStage];

            if (aOrderedCursor > cLowUnitCount) {
                return false;
            }
        }

        return aOrderedCursor == cLowUnitCount;
    }
};

int main() {
    LaneCountTool::PrintLowSchemesAsCode();
    return 0;
}

