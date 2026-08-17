//
//  EncryptionPlan.hpp
//  Scramble
//
//  Created by nick on 8/4/26.
//

#ifndef EncryptionPlan_hpp
#define EncryptionPlan_hpp

#include "SoccerTypes.hpp"
#include <cstddef>
#include <cstdint>

#define SHUFFLED_CIPHERS_LENGTH 256


struct EncryptionPlanStage {
    CipherType      mType[12];
    std::size_t     mCount = 0;
};

struct EncryptionPlan {
    
    EncryptionPlanStage             mL3A;
    EncryptionPlanStage             mL2A;
    EncryptionPlanStage             mL1A;
    
    EncryptionPlanStage             mL3B;
    EncryptionPlanStage             mL2B;
    EncryptionPlanStage             mL1B;
    
    EncryptionPlanStage             mL3C;
    EncryptionPlanStage             mL2C;
    EncryptionPlanStage             mL1C;

    EncryptionPlanStage             mL3D;
    EncryptionPlanStage             mL2D;
    EncryptionPlanStage             mL1D;
};

class EncryptionPlanTool {
    
public:

    /*
     Weak uses groups A and B: 6 rotations, 4 simple mutations, 5 primary
     movers, and 1 secondary mover. Three rotations are masked, for 9 masks
     total.

     Normal uses groups A and B: 6 rotations, 7 simple mutations, 6 primary
     movers, and 2 secondary movers. Three rotations are masked, for 11 masks
     total.

     Strong uses groups A through C: 9 rotations, 10 simple mutations,
     4 complex mutations, 8 primary movers, and 1 secondary mover. Four
     rotations are masked, for 13 masks total.

     Unlisted stages remain empty.
     */
    
    /*
     Strong:

     L3A: [rotate masked] [mutate complex] [primary mover] [mutate simple]
     L2A: [rotate masked] [mutate simple] [primary mover] [mutate simple]
     L1A: [rotate masked] [mutate simple] [primary mover] [mutate simple]

     L3B: [rotate masked] [mutate simple] [primary mover] [mutate simple]
     L2B: [rotate] [mutate complex] [primary mover]
     L1B: [rotate] [mutate simple] [primary mover]

     L3C: [rotate] [mutate simple] [primary mover] [mutate complex]
     L2C: [rotate] [mutate simple] [primary mover]
     L1C: [rotate] [mutate complex] [secondary mover]

     Rotate: 9
     Mask: 13 / 13
     Lane, L3: 6/6
     Lane, L2: 4/4
     Lane, L1: 4/4


     Normal:

     L3A: [rotate masked] [mutate simple] [primary mover] [mutate simple]
     L2A: [rotate masked] [mutate simple] [primary mover] [secondary mover]
     L1A: [rotate masked] [mutate simple] [primary mover] [primary mover]

     L3B: [rotate] [mutate simple] [primary mover]
     L2B: [rotate] [mutate simple] [primary mover]
     L1B: [rotate] [mutate simple] [secondary mover]

     Rotate: 6
     Mask: 11 / 11
     Lane, L3: 3/3
     Lane, L2: 2/2
     Lane, L1: 2/2



     Weak:

     L3A: [rotate masked] [mutate simple] [primary mover]
     L2A: [rotate masked] [mutate simple] [primary mover]
     L1A: [rotate masked] [mutate simple] [primary mover]
     
     L3B: [rotate] [mutate simple] [primary mover]
     L2B: [rotate] [primary mover]
     L1B: [rotate] [secondary mover]

     Rotate: 6
     Mask: 9 / 9
     Lane, L3: 2/2
     Lane, L2: 1/1
     Lane, L1: 1/1
     */

    static EncryptionPlan               MakePlanWeak(std::uint64_t pLaneSelect,
                                                     CipherType *pShuffledCiphers);
    static EncryptionPlan               MakePlanNormal(std::uint64_t pLaneSelect,
                                                       CipherType *pShuffledCiphers);
    static EncryptionPlan               MakePlanStrong(std::uint64_t pLaneSelect,
                                                       CipherType *pShuffledCiphers);

private:
    // pIndex can be [0...255]. If a category is absent from the shuffled
    // ring, the category's deterministic default is returned.
    static CipherType                   RingFetchMutateSimple(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex);
    static CipherType                   RingFetchMutateComplex(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex);
    static CipherType                   RingFetchMutateAny(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex);

    static CipherType                   RingFetchRotation(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchRotationMasked(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchRotationAny(CipherType *pShuffledCiphers, std::size_t *pIndex);

    static CipherType                   RingFetchPrimaryMover(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchSecondaryMover(CipherType *pShuffledCiphers, std::size_t *pIndex);
    static CipherType                   RingFetchMoverAny(CipherType *pShuffledCiphers, std::size_t *pIndex);
    
};

#endif /* EncryptionPlan_hpp */
