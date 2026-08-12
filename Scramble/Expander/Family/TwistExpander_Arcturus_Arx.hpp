#pragma once

#include "TwistExpander.hpp"

class TwistExpander_Arcturus_Arx {
public:
    static void KDF_A_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_A_C_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_B_C_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_A_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_B_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void KDF_C_C_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     MUTABLE_PARAMS);
    static void SEED_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_G(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_H(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_I(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void SEED_J(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_D_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_E_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_F_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_G_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_H_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_C_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_D_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_E_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_F_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_G_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_H_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_D_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_E_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_F_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_G_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_H_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_C_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_D_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_E_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_F_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_G_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_H_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_D_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_E_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_F_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_G_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_A_H_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_B_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_C_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_D_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_E_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_F_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_G_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void KEY_B_H_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS);
    static void TWIST_A(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_B(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void TWIST_C(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS);
    static void GROW_A_A(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_A_B(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_B_A(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
    static void GROW_B_B(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS);
};

//
// Key-lane assignments
//

// KEY_A_A
#define ARCTURUS_KEY_A_A_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_A_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_A_A_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_A_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_A_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_A_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_A_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_A_A_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_A_A_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_A_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_A_A_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_A_A_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_A_A_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_A_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_A_A_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_A_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_A_A_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_A_A_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_A_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_A_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_A_A_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_A_A_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_A_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_A_A_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_A_A_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_A_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_A_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_A_A_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_A_A_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_A_A_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_A_A_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_A_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_A_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_A_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_A_A_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_A_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_A_A_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_A_A_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_A_A_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_A_A_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_A_A_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_A_A_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_A_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_A_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_A_A_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_A_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_A_A_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_A_A_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_A_A_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_A_A_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_A_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_A_A_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 14U))

// KEY_A_B
#define ARCTURUS_KEY_A_B_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_A_B_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_A_B_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_A_B_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_A_B_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_B_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_A_B_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_B_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_B_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_B_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_B_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_B_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_A_B_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_A_B_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_B_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_A_B_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_B_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_A_B_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_B_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_A_B_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_B_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_B_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_A_B_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_B_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_A_B_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_A_B_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_A_B_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_B_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_B_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_A_B_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_A_B_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_B_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_A_B_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_A_B_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_B_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_B_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_A_B_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_A_B_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_B_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_B_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_A_B_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_A_B_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_A_B_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_A_B_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_A_B_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_B_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_A_B_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_A_B_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_B_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_B_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_B_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_A_B_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 6U))

// KEY_A_C
#define ARCTURUS_KEY_A_C_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_A_C_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_C_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_A_C_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_A_C_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_A_C_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_A_C_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_A_C_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_A_C_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_A_C_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_A_C_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_C_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_C_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_A_C_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_A_C_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_A_C_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_C_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_C_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_A_C_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_C_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_A_C_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_C_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_A_C_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_C_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_C_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_A_C_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_A_C_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_A_C_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_C_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_A_C_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_A_C_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_A_C_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_A_C_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_C_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_A_C_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_A_C_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_C_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_A_C_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_A_C_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_C_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_A_C_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_C_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_C_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_A_C_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_A_C_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_A_C_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_A_C_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_A_C_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_A_C_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_A_C_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_C_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_C_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 9U))

// KEY_A_D
#define ARCTURUS_KEY_A_D_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_A_D_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_D_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_A_D_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_D_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_A_D_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_A_D_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_A_D_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_A_D_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_A_D_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_D_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_D_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_A_D_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_D_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_D_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_D_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_D_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_A_D_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_A_D_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_A_D_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_D_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_D_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_D_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_A_D_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_A_D_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_A_D_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_D_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_D_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_A_D_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_A_D_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_D_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_D_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_A_D_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_A_D_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_D_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_D_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_A_D_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_D_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_D_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_A_D_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_A_D_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_A_D_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_A_D_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_D_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_D_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_D_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_A_D_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_D_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_D_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_D_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_A_D_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_D_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 1U))

// KEY_A_E
#define ARCTURUS_KEY_A_E_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_A_E_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_A_E_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_E_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_A_E_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_A_E_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_A_E_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_A_E_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_E_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_A_E_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_E_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_A_E_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_E_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_A_E_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_A_E_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_E_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_A_E_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_A_E_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_A_E_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_E_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_A_E_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_A_E_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_A_E_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_A_E_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_E_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_A_E_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_E_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_E_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_A_E_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_A_E_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_E_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_E_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_A_E_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_A_E_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_E_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_A_E_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_A_E_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_E_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_A_E_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_A_E_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_A_E_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_A_E_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_E_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_A_E_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_E_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_E_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_E_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_E_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_A_E_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_A_E_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_A_E_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_E_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 10U))

// KEY_A_F
#define ARCTURUS_KEY_A_F_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_F_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_A_F_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_A_F_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_A_F_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_A_F_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_A_F_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_F_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_F_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_F_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_A_F_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_A_F_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_A_F_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_A_F_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_A_F_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_F_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_A_F_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_A_F_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_F_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_F_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_A_F_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_A_F_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_A_F_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_F_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_A_F_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_A_F_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_A_F_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_F_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_A_F_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_F_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_F_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_A_F_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_A_F_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_A_F_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_F_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_A_F_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_A_F_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_A_F_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_A_F_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_F_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_A_F_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_A_F_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_F_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_F_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_A_F_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_A_F_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_A_F_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_A_F_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_A_F_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_F_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_A_F_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_F_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 15U))

// KEY_A_G
#define ARCTURUS_KEY_A_G_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_A_G_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_A_G_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_A_G_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_A_G_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_A_G_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_G_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_G_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_A_G_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_A_G_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_A_G_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_G_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_A_G_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_A_G_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_A_G_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_G_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_A_G_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_A_G_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_A_G_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_A_G_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_A_G_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_A_G_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_A_G_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_A_G_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_A_G_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_A_G_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_A_G_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_G_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_A_G_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_G_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_A_G_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_G_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_A_G_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_A_G_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_A_G_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_G_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_A_G_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_A_G_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_A_G_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_A_G_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_A_G_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_A_G_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_A_G_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_G_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_A_G_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_A_G_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_A_G_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_G_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_A_G_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_A_G_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_A_G_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_A_G_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 0U))

// KEY_A_H
#define ARCTURUS_KEY_A_H_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_H_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_H_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_H_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_A_H_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_A_H_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_A_H_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_A_H_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_A_H_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_A_H_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_A_H_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_A_H_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_A_H_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_A_H_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_A_H_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_H_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_A_H_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_A_H_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_A_H_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_H_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_H_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_A_H_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_H_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_A_H_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_A_H_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_A_H_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_A_H_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_A_H_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_A_H_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_A_H_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_A_H_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_A_H_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_A_H_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_A_H_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_A_H_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_A_H_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_A_H_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_A_H_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_A_H_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_H_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_A_H_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_A_H_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_A_H_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_A_H_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_A_H_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_A_H_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_A_H_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_A_H_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_A_H_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_A_H_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_A_H_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_A_H_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 4U))

// KEY_B_A
#define ARCTURUS_KEY_B_A_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_A_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_A_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_A_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_A_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_B_A_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_B_A_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_B_A_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_A_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_B_A_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_B_A_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_A_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_A_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_B_A_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_B_A_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_A_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_A_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_B_A_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_A_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_B_A_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_B_A_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_B_A_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_B_A_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_A_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_B_A_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_A_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_A_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_B_A_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_B_A_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_A_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_B_A_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_B_A_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_B_A_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_B_A_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_B_A_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_A_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_B_A_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_A_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_B_A_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_A_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_B_A_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_B_A_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_A_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_B_A_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_A_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_A_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_B_A_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_A_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_B_A_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_A_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_B_A_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_A_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 12U))

// KEY_B_B
#define ARCTURUS_KEY_B_B_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_B_B_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_B_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_B_B_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_B_B_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_B_B_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_B_B_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_B_B_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_B_B_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_B_B_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_B_B_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_B_B_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_B_B_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_B_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_B_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_B_B_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_B_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_B_B_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_B_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_B_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_B_B_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_B_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_B_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_B_B_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_B_B_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_B_B_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_B_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_B_B_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_B_B_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_B_B_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_B_B_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_B_B_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_B_B_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_B_B_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_B_B_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_B_B_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_B_B_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_B_B_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_B_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_B_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_B_B_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_B_B_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_B_B_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_B_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_B_B_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_B_B_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_B_B_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_B_B_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_B_B_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_B_B_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_B_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_B_B_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 3U))

// KEY_B_C
#define ARCTURUS_KEY_B_C_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_B_C_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_B_C_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_B_C_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_B_C_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_B_C_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_B_C_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_B_C_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_B_C_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_C_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_C_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_B_C_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_B_C_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_B_C_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_B_C_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_B_C_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_C_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_C_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_B_C_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_B_C_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_C_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_B_C_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_C_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_C_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_B_C_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_B_C_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_B_C_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_C_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_C_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_B_C_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_B_C_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_B_C_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_C_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_B_C_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_B_C_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_B_C_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_B_C_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_B_C_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_B_C_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_B_C_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_B_C_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_B_C_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_C_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_C_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_C_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_B_C_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_C_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_C_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_C_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_C_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_B_C_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_C_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 11U))

// KEY_B_D
#define ARCTURUS_KEY_B_D_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_D_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_D_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_B_D_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_B_D_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_D_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_B_D_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_B_D_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_B_D_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_D_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_B_D_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_B_D_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_D_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_D_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_B_D_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_D_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_B_D_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_D_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_B_D_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_B_D_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_B_D_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_B_D_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_B_D_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 3U))
#define ARCTURUS_KEY_B_D_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_B_D_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_D_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_B_D_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_B_D_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_B_D_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_B_D_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_D_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_D_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_B_D_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_D_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_B_D_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_B_D_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_B_D_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_B_D_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_B_D_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 13U))
#define ARCTURUS_KEY_B_D_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_B_D_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_D_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_D_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_D_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_D_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_D_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_B_D_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_B_D_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_B_D_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_B_D_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_D_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_D_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 8U))

// KEY_B_E
#define ARCTURUS_KEY_B_E_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_B_E_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_B_E_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_E_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_B_E_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_B_E_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_E_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_B_E_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_B_E_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_B_E_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_B_E_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_E_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_B_E_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_E_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_B_E_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_E_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_B_E_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_B_E_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_B_E_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_E_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_E_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_E_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_B_E_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_E_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_E_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_B_E_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_E_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_E_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_B_E_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_B_E_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_B_E_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_E_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_B_E_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_B_E_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_E_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_E_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_E_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_E_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_B_E_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_B_E_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_B_E_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_B_E_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 13U))
#define ARCTURUS_KEY_B_E_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_B_E_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_B_E_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_E_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 5U))
#define ARCTURUS_KEY_B_E_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_B_E_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_B_E_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_B_E_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 8U))
#define ARCTURUS_KEY_B_E_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_B_E_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 13U))

// KEY_B_F
#define ARCTURUS_KEY_B_F_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_B_F_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_B_F_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_B_F_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_B_F_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_B_F_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_B_F_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_B_F_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_F_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_B_F_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 6U))
#define ARCTURUS_KEY_B_F_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_B_F_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_F_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_B_F_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_F_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_B_F_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_F_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_F_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_B_F_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 6U))
#define ARCTURUS_KEY_B_F_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_B_F_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_B_F_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_B_F_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_B_F_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_B_F_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_B_F_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_B_F_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_B_F_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_F_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_B_F_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_B_F_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 10U))
#define ARCTURUS_KEY_B_F_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_F_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_B_F_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_F_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_B_F_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_F_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_B_F_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_B_F_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_B_F_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_B_F_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_F_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_B_F_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_B_F_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_B_F_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 7U))

// KEY_B_G
#define ARCTURUS_KEY_B_G_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_B_G_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_B_G_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_B_G_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 11U))
#define ARCTURUS_KEY_B_G_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_G_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_B_G_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_G_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_B_G_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_G_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 4U))
#define ARCTURUS_KEY_B_G_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_B_G_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_B_G_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_G_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_G_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_B_G_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 15U))
#define ARCTURUS_KEY_B_G_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 10U))
#define ARCTURUS_KEY_B_G_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_B_G_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_G_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_B_G_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_B_G_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_B_G_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 8U))
#define ARCTURUS_KEY_B_G_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_G_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 4U))
#define ARCTURUS_KEY_B_G_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 2U))
#define ARCTURUS_KEY_B_G_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_G_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 9U))
#define ARCTURUS_KEY_B_G_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 8U))
#define ARCTURUS_KEY_B_G_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_G_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_G_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 5U))
#define ARCTURUS_KEY_B_G_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 7U))
#define ARCTURUS_KEY_B_G_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 11U))
#define ARCTURUS_KEY_B_G_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 5U))
#define ARCTURUS_KEY_B_G_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_B_G_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_B_G_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_B_G_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_G_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 13U))
#define ARCTURUS_KEY_B_G_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 3U))
#define ARCTURUS_KEY_B_G_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 14U))
#define ARCTURUS_KEY_B_G_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 7U))
#define ARCTURUS_KEY_B_G_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 10U))
#define ARCTURUS_KEY_B_G_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_G_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_G_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_G_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 14U))
#define ARCTURUS_KEY_B_G_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 15U))
#define ARCTURUS_KEY_B_G_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 3U))
#define ARCTURUS_KEY_B_G_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 1U))
#define ARCTURUS_KEY_B_G_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 5U))

// KEY_B_H
#define ARCTURUS_KEY_B_H_EarthLaneA (pWorkSpace->mEarthLaneA + (W_KEY * 2U))
#define ARCTURUS_KEY_B_H_EarthLaneB (pWorkSpace->mEarthLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_H_EarthLaneC (pWorkSpace->mEarthLaneC + (W_KEY * 11U))
#define ARCTURUS_KEY_B_H_EarthLaneD (pWorkSpace->mEarthLaneD + (W_KEY * 8U))
#define ARCTURUS_KEY_B_H_FireLaneA (pWorkSpace->mFireLaneA + (W_KEY * 12U))
#define ARCTURUS_KEY_B_H_FireLaneB (pWorkSpace->mFireLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_B_H_FireLaneC (pWorkSpace->mFireLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_H_FireLaneD (pWorkSpace->mFireLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_B_H_WindLaneA (pWorkSpace->mWindLaneA + (W_KEY * 0U))
#define ARCTURUS_KEY_B_H_WindLaneB (pWorkSpace->mWindLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_B_H_WindLaneC (pWorkSpace->mWindLaneC + (W_KEY * 9U))
#define ARCTURUS_KEY_B_H_WindLaneD (pWorkSpace->mWindLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_B_H_WaterLaneA (pWorkSpace->mWaterLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_B_H_WaterLaneB (pWorkSpace->mWaterLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_B_H_WaterLaneC (pWorkSpace->mWaterLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_H_WaterLaneD (pWorkSpace->mWaterLaneD + (W_KEY * 12U))
#define ARCTURUS_KEY_B_H_LightningLaneA (pWorkSpace->mLightningLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_H_LightningLaneB (pWorkSpace->mLightningLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_B_H_LightningLaneC (pWorkSpace->mLightningLaneC + (W_KEY * 15U))
#define ARCTURUS_KEY_B_H_LightningLaneD (pWorkSpace->mLightningLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_B_H_IceLaneA (pWorkSpace->mIceLaneA + (W_KEY * 9U))
#define ARCTURUS_KEY_B_H_IceLaneB (pWorkSpace->mIceLaneB + (W_KEY * 12U))
#define ARCTURUS_KEY_B_H_IceLaneC (pWorkSpace->mIceLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_H_IceLaneD (pWorkSpace->mIceLaneD + (W_KEY * 1U))
#define ARCTURUS_KEY_B_H_PlasmaLaneA (pWorkSpace->mPlasmaLaneA + (W_KEY * 14U))
#define ARCTURUS_KEY_B_H_PlasmaLaneB (pWorkSpace->mPlasmaLaneB + (W_KEY * 9U))
#define ARCTURUS_KEY_B_H_PlasmaLaneC (pWorkSpace->mPlasmaLaneC + (W_KEY * 4U))
#define ARCTURUS_KEY_B_H_PlasmaLaneD (pWorkSpace->mPlasmaLaneD + (W_KEY * 2U))
#define ARCTURUS_KEY_B_H_ShadowLaneA (pWorkSpace->mShadowLaneA + (W_KEY * 11U))
#define ARCTURUS_KEY_B_H_ShadowLaneB (pWorkSpace->mShadowLaneB + (W_KEY * 7U))
#define ARCTURUS_KEY_B_H_ShadowLaneC (pWorkSpace->mShadowLaneC + (W_KEY * 14U))
#define ARCTURUS_KEY_B_H_ShadowLaneD (pWorkSpace->mShadowLaneD + (W_KEY * 0U))
#define ARCTURUS_KEY_B_H_CrystalLaneA (pWorkSpace->mCrystalLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_H_CrystalLaneB (pWorkSpace->mCrystalLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_H_CrystalLaneC (pWorkSpace->mCrystalLaneC + (W_KEY * 2U))
#define ARCTURUS_KEY_B_H_CrystalLaneD (pWorkSpace->mCrystalLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_H_AetherLaneA (pWorkSpace->mAetherLaneA + (W_KEY * 5U))
#define ARCTURUS_KEY_B_H_AetherLaneB (pWorkSpace->mAetherLaneB + (W_KEY * 0U))
#define ARCTURUS_KEY_B_H_AetherLaneC (pWorkSpace->mAetherLaneC + (W_KEY * 12U))
#define ARCTURUS_KEY_B_H_AetherLaneD (pWorkSpace->mAetherLaneD + (W_KEY * 7U))
#define ARCTURUS_KEY_B_H_CelestialLaneA (pWorkSpace->mCelestialLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_H_CelestialLaneB (pWorkSpace->mCelestialLaneB + (W_KEY * 1U))
#define ARCTURUS_KEY_B_H_CelestialLaneC (pWorkSpace->mCelestialLaneC + (W_KEY * 6U))
#define ARCTURUS_KEY_B_H_CelestialLaneD (pWorkSpace->mCelestialLaneD + (W_KEY * 4U))
#define ARCTURUS_KEY_B_H_VaporLaneA (pWorkSpace->mVaporLaneA + (W_KEY * 1U))
#define ARCTURUS_KEY_B_H_VaporLaneB (pWorkSpace->mVaporLaneB + (W_KEY * 15U))
#define ARCTURUS_KEY_B_H_VaporLaneC (pWorkSpace->mVaporLaneC + (W_KEY * 10U))
#define ARCTURUS_KEY_B_H_VaporLaneD (pWorkSpace->mVaporLaneD + (W_KEY * 3U))
#define ARCTURUS_KEY_B_H_SpiritLaneA (pWorkSpace->mSpiritLaneA + (W_KEY * 13U))
#define ARCTURUS_KEY_B_H_SpiritLaneB (pWorkSpace->mSpiritLaneB + (W_KEY * 6U))
#define ARCTURUS_KEY_B_H_SpiritLaneC (pWorkSpace->mSpiritLaneC + (W_KEY * 0U))
#define ARCTURUS_KEY_B_H_SpiritLaneD (pWorkSpace->mSpiritLaneD + (W_KEY * 2U))
