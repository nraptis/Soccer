//
//  LaneCombinations.hpp
//  Scramble
//
//  Precomputed lane-count combinations for encryption plans.
//

#ifndef LaneCombinations_hpp
#define LaneCombinations_hpp

#include <cstddef>
#include <cstdint>

// Lane counts are distributed from the beginning in round-robin stage order:
// L3A, L2A, L1A, L3B, L2B, L1B, L3C, then back to L3A.
struct WeakLaneCombination {
    std::uint8_t mL3A[1];
    std::uint8_t mL2A[1];
    std::uint8_t mL1A[1];
    std::uint8_t mL3B[1];
};

struct NormalLaneCombination {
    std::uint8_t mL3A[1];
    std::uint8_t mL2A[1];
    std::uint8_t mL1A[1];
    std::uint8_t mL3B[1];
    std::uint8_t mL2B[1];
    std::uint8_t mL1B[1];
    std::uint8_t mL3C[1];
};

struct StrongLaneCombination {
    std::uint8_t mL3A[2];
    std::uint8_t mL2A[2];
    std::uint8_t mL1A[2];
    std::uint8_t mL3B[2];
    std::uint8_t mL2B[2];
    std::uint8_t mL1B[2];
    std::uint8_t mL3C[2];
};

static_assert(sizeof(WeakLaneCombination) == 4U);
static_assert(sizeof(NormalLaneCombination) == 7U);
static_assert(sizeof(StrongLaneCombination) == 14U);

class LaneCombinations {
public:
    static constexpr std::size_t                mWeakCount = 12U;
    static const WeakLaneCombination            mWeak[mWeakCount];

    static constexpr std::size_t                mNormalCount = 236U;
    static const NormalLaneCombination          mNormal[mNormalCount];
    
    static constexpr std::size_t                mStrongCount = 16624U;
    static const StrongLaneCombination          mStrong[mStrongCount];
    
    static WeakLaneCombination                  PickWeak(std::uint64_t pSelect);
    static NormalLaneCombination                PickNormal(std::uint64_t pSelect);
    static StrongLaneCombination                PickStrong(std::uint64_t pSelect);
    
};

#endif /* LaneCombinations_hpp */
