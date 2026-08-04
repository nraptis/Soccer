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

// Members are stored in packing order: full lanes, half lanes, quarter lanes.
// Withdraw them in the reverse order so no smaller piece wraps a larger piece.
struct WeakLaneCombination {
    std::uint8_t mL3[1];
    std::uint8_t mF3[1];
    std::uint8_t mL2[1];
    std::uint8_t mL1[1];
};

struct NormalLaneCombination {
    std::uint8_t mL3[1];
    std::uint8_t mF3[2];
    std::uint8_t mL2[2];
    std::uint8_t mL1[2];
};

struct StrongLaneCombination {
    std::uint8_t mL3[4];
    std::uint8_t mF3[4];
    std::uint8_t mL2[3];
    std::uint8_t mL1[3];
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
