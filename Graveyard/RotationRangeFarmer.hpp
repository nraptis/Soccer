//
//  RotationRangeFarmer.hpp
//  Scramble
//
//  Created by nick on 8/8/26.
//

#ifndef RotationRangeFarmer_hpp
#define RotationRangeFarmer_hpp

#include <cstddef>
#include <cstdint>
#include <vector>

#define SOCCER_ROTATION_RANGE_BLOCK_SIZE 1024
#define SOCCER_ROTATION_RANGE_BLOCK_LOW 1
#define SOCCER_ROTATION_RANGE_BLOCK_HIGH 253
#define SOCCER_ROTATION_RANGE_FAMILY_COUNT 4
#define SOCCER_ROTATION_RANGE_POSSIBILITY_COUNT 4097152081ULL

struct RotationRangeFarmerConfig {
    std::size_t mRandomSpanSize = SOCCER_ROTATION_RANGE_BLOCK_SIZE;
    std::int32_t mDistanceThreshold = SOCCER_ROTATION_RANGE_BLOCK_SIZE + 256;
    std::uint16_t mLandingZoneCount = SOCCER_ROTATION_RANGE_BLOCK_HIGH;
};

struct RotationRangeFamily {
    std::uint16_t mBlock[SOCCER_ROTATION_RANGE_FAMILY_COUNT] = {};
};

struct RotationRangeScore {
    std::uint32_t mMinimumRotationDistance = 0U;
    std::uint32_t mMinimumBoundaryDistance = 0U;
    std::uint32_t mTotal = 0U;
};

struct RotationRangeFarmEntry {
    RotationRangeFamily mFamily;
    RotationRangeScore mScore;
    std::uint32_t mAccumulatedDistance = 0U;
    std::uint32_t mDistanceFromPrevious = 0U;
};

class RotationRangeFarmer {
public:
    // pFamilyCount includes the first random family. Every later family is the
    // highest-scoring of pCandidateCount new random valid families.
    static std::vector<RotationRangeFarmEntry>       Farm(std::size_t pFamilyCount,
                                                          std::size_t pCandidateCount,
                                                          std::uint64_t pSeed);

    static std::vector<RotationRangeFarmEntry>       Farm(std::size_t pFamilyCount,
                                                          std::size_t pCandidateCount,
                                                          const RotationRangeFarmerConfig &pConfig,
                                                          std::uint64_t pSeed);

    static std::vector<RotationRangeFarmEntry>       Select(
        const std::vector<RotationRangeFamily> &pAvailable,
        std::size_t pFamilyCount,
        std::size_t pCandidateCount,
        const RotationRangeFarmerConfig &pConfig,
        std::uint64_t pSeed);

    static std::size_t                              LandingZoneCount(std::size_t pRandomSpanSize);
    static std::uint64_t                            RawFamilyCount(const RotationRangeFarmerConfig &pConfig);
    static std::vector<RotationRangeFamily>          EnumerateValid(
        const RotationRangeFarmerConfig &pConfig);

    // A family is valid when every offset in its configured random span remains
    // safe under the bank's boundary, alias, and accumulated-rotation checks.
    static bool                                     IsValid(const RotationRangeFamily &pFamily);
    static bool                                     IsValid(const RotationRangeFamily &pFamily,
                                                            const RotationRangeFarmerConfig &pConfig);

    // Minimum byte distance between the two complete configured ranges at any
    // of their four quarter-cycle aliases.
    static std::uint32_t                            RangeDistance(std::uint16_t pBlockA,
                                                                 std::uint16_t pBlockB);
    static std::uint32_t                            RangeDistance(std::uint16_t pBlockA,
                                                                 std::uint16_t pBlockB,
                                                                 const RotationRangeFarmerConfig &pConfig);

    // Minimum distance from the complete range and its aliases to any of the
    // five L1 boundaries: 0, 262144, 524288, 786432, and 1048576.
    static std::uint32_t                            BoundaryDistance(std::uint16_t pBlock);
    static std::uint32_t                            BoundaryDistance(
        std::uint16_t pBlock,
        const RotationRangeFarmerConfig &pConfig);

    // Minimum distance between any range in A and any range in B.
    static std::uint32_t                            FamilyDistance(const RotationRangeFamily &pFamilyA,
                                                                  const RotationRangeFamily &pFamilyB);
    static std::uint32_t                            FamilyDistance(
        const RotationRangeFamily &pFamilyA,
        const RotationRangeFamily &pFamilyB,
        const RotationRangeFarmerConfig &pConfig);

    // Scores the four ranges themselves:
    // (minimum internal rotation distance * 3) + minimum boundary distance.
    static RotationRangeScore                       Score(const RotationRangeFamily &pFamily);
    static RotationRangeScore                       Score(const RotationRangeFamily &pFamily,
                                                         const RotationRangeFarmerConfig &pConfig);

    // Weakest accumulated-rotation or boundary margin checked by IsValid.
    static std::uint32_t                            AccumulatedDistance(const RotationRangeFamily &pFamily);
    static std::uint32_t                            AccumulatedDistance(
        const RotationRangeFamily &pFamily,
        const RotationRangeFarmerConfig &pConfig);
};

#endif /* RotationRangeFarmer_hpp */
