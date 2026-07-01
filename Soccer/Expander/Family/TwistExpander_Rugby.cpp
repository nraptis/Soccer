#include "TwistExpander_Rugby.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistMemory.hpp"
#include "TwistShiftBox.hpp"
#include "TwistSnow.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Rugby::TwistExpander_Rugby()
: TwistExpander() {
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    mDomainBundleInbuilt.mPhaseESalts = kPhaseESalts;
    mDomainBundleInbuilt.mPhaseEConstants = kPhaseEConstants;
    mDomainBundleInbuilt.mPhaseFSalts = kPhaseFSalts;
    mDomainBundleInbuilt.mPhaseFConstants = kPhaseFConstants;
    mDomainBundleInbuilt.mPhaseGSalts = kPhaseGSalts;
    mDomainBundleInbuilt.mPhaseGConstants = kPhaseGConstants;
    mDomainBundleInbuilt.mPhaseHSalts = kPhaseHSalts;
    mDomainBundleInbuilt.mPhaseHConstants = kPhaseHConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Rugby::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    [[maybe_unused]] std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    [[maybe_unused]] std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    [[maybe_unused]] std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x8372AD65641FF574ULL; std::uint64_t aIngress = 0x9CFCD2630E31E3E3ULL; std::uint64_t aCarry = 0xCBFA34FDFB6FA488ULL;

    std::uint64_t aWandererA = 0xFD852518DF360208ULL; std::uint64_t aWandererB = 0xA7E3444A0106D2D6ULL; std::uint64_t aWandererC = 0x96F1C3D589BE3038ULL; std::uint64_t aWandererD = 0xE243F726CE993CD8ULL;
    std::uint64_t aWandererE = 0xB881C8AB34F0C498ULL; std::uint64_t aWandererF = 0xBA5610D0C4AC6B16ULL; std::uint64_t aWandererG = 0xAF2FE04F7E26736EULL; std::uint64_t aWandererH = 0x8F1E96415B92DAC4ULL;
    std::uint64_t aWandererI = 0x9975233D7747A71AULL; std::uint64_t aWandererJ = 0x881F34D0E7C371C5ULL; std::uint64_t aWandererK = 0xDC67096551495F31ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 12959271694627278550U;
        aCarry = 16033290421972731043U;
        aWandererA = 9892271779438248418U;
        aWandererB = 12742290423478027487U;
        aWandererC = 13579056081503005735U;
        aWandererD = 12769743642550360142U;
        aWandererE = 11929524067570244343U;
        aWandererF = 13639871235303878848U;
        aWandererG = 15829562294456603188U;
        aWandererH = 13713467563898783347U;
        aWandererI = 10972738815871940799U;
        aWandererJ = 13849103337949621236U;
        aWandererK = 10004617871268487745U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_A_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_A_B kdf_a_loop_b:
    // ---------------------------------------------------
    // read from: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_A_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_A_C kdf_a_loop_c:
    // ---------------------------------------------------
    // read from: fire_a, fire_b, fire_c, fire_d
    // temp storage: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_A_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_A_D kdf_a_loop_d:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: earth_b, earth_c, earth_d, source, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_A_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // KDF_A_E kdf_a_loop_e:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: earth_a, earth_b, earth_c, earth_d, source, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: water_a, water_b, water_c, water_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_A_E(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

}

void TwistExpander_Rugby::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x9DAF7E7F4CA3DF3DULL; std::uint64_t aIngress = 0xC6AE163135012D5CULL; std::uint64_t aCarry = 0xF1BBE53C42D409B9ULL;

    std::uint64_t aWandererA = 0x98DCD1456C76487DULL; std::uint64_t aWandererB = 0x9A3AA540F7489255ULL; std::uint64_t aWandererC = 0xA9C9CC4F66E7FA95ULL; std::uint64_t aWandererD = 0x8558B20A24234F9AULL;
    std::uint64_t aWandererE = 0xCC8A57F168E05CF5ULL; std::uint64_t aWandererF = 0xB7136469DD934FE6ULL; std::uint64_t aWandererG = 0xA62EE649B76BA3D2ULL; std::uint64_t aWandererH = 0xD17C355C1B85A8B8ULL;
    std::uint64_t aWandererI = 0xD5D007F27D71757AULL; std::uint64_t aWandererJ = 0xA76EEE0CAE8959E2ULL; std::uint64_t aWandererK = 0xED92664AB3AD0F53ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 16804369903959093658U;
        aCarry = 12600378716026051127U;
        aWandererA = 16452203690087604638U;
        aWandererB = 11443404270021627890U;
        aWandererC = 15923241184038816599U;
        aWandererD = 17880607014296591576U;
        aWandererE = 10266836012264026161U;
        aWandererF = 9838468049495573216U;
        aWandererG = 16051137993179601976U;
        aWandererH = 10179739078446958893U;
        aWandererI = 12686960970935828287U;
        aWandererJ = 12538645855713796099U;
        aWandererK = 9374575445053656161U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: water_a, water_b, water_c, water_d
    // temp storage: wind_a, wind_b, wind_c, wind_d, fire_a, fire_b, fire_c, source
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_B_B kdf_b_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: water_a, water_b, water_c, water_d, source, wind_a, wind_b, wind_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // KDF_B_C kdf_b_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: expand_a, expand_b, expand_c, expand_d, earth_d, fire_d, water_d, source
    // ---------------------------------------------------
    // write to: fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWorkLaneA, aWorkLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWorkLaneC, aWorkLaneD, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // KDF_B_D kdf_b_loop_d:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: water_a, water_b, water_c, water_d, fire_a, fire_b, fire_c, wind_c
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::KDF_B_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

}

void TwistExpander_Rugby::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr)) { return; }
    std::uint8_t *aSource = pWorkSpace->mSource;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    [[maybe_unused]] std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    [[maybe_unused]] std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    [[maybe_unused]] std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    [[maybe_unused]] std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    [[maybe_unused]] std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    [[maybe_unused]] std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    [[maybe_unused]] std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneE = pWorkSpace->mInvestLaneE;
    [[maybe_unused]] std::uint8_t *aInvestLaneF = pWorkSpace->mInvestLaneF;
    [[maybe_unused]] std::uint8_t *aInvestLaneG = pWorkSpace->mInvestLaneG;
    [[maybe_unused]] std::uint8_t *aInvestLaneH = pWorkSpace->mInvestLaneH;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x93C065A302C3B2E0ULL;
    std::uint64_t aIngress = 0xA22AEB4FDECA7F17ULL;
    std::uint64_t aCarry = 0xDE2233A8ADCCC601ULL;

    std::uint64_t aWandererA = 0xC9C701F082CE2A4AULL;
    std::uint64_t aWandererB = 0x98AE99E4235AF300ULL;
    std::uint64_t aWandererC = 0xFB93481BAC58EBA2ULL;
    std::uint64_t aWandererD = 0x8CF477163EC4C680ULL;
    std::uint64_t aWandererE = 0xCE16AF6AA2A7D4DDULL;
    std::uint64_t aWandererF = 0xAD5785FD25DB7B40ULL;
    std::uint64_t aWandererG = 0xF396160EBDFA9070ULL;
    std::uint64_t aWandererH = 0xE14C786BFC062103ULL;
    std::uint64_t aWandererI = 0xCEB1CB6B52E43BC5ULL;
    std::uint64_t aWandererJ = 0xAE705DB12A6553C9ULL;
    std::uint64_t aWandererK = 0xB0ABFD84BA09479AULL;

    // [seed]
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneA);
        TwistSnow::AES256Counter(aSource, aSnowLaneB);
        TwistSnow::Aria256Counter(aSource, aSnowLaneC);
        TwistSnow::Sha256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    // GSquashInvestToKeyBoxes (start)
    SquashInvestToKeyBoxes();
    // GSquashInvestToKeyBoxes (end)
    //
    //
    // ---------------------------------------------------
    // GSeedRunSeed_A seed_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: water_a, water_b
    // ---------------------------------------------------
    // write to: water_a, water_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_A(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GSeedRunSeed_B seed_loop_a:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, earth_a, earth_b
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_B(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GSeedRunSeed_C seed_loop_b:
    // ---------------------------------------------------
    // read from: work_c, work_d, earth_a, earth_b
    // temp storage: work_a, work_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: earth_c, earth_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_C(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GSeedRunSeed_D seed_loop_b:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: work_a, work_b, work_c, work_d, earth_a, earth_b, expand_a, expand_b
    // ---------------------------------------------------
    // write to: snow_a, snow_b, fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_D(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aFireLaneA, aFireLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aFireLaneC, aFireLaneD, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // GSeedRunSeed_E seed_loop_c:
    // ---------------------------------------------------
    // read from: fire_a, fire_b, fire_c, fire_d
    // temp storage: key_row_read_a, key_row_read_b, snow_a, snow_b, expand_a, expand_b, expand_c, expand_d, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: water_c, water_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_E(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GSeedRunSeed_F seed_loop_c:
    // ---------------------------------------------------
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: snow_a, snow_b, water_c, water_d, earth_a, earth_b, earth_c, earth_d, fire_a, fire_b, source, key_row_read_a
    // ---------------------------------------------------
    // write to: snow_c, snow_d, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_F(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GSeedRunSeed_G seed_loop_d:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: snow_c, snow_d, source, key_row_read_b, invest_a, invest_b, invest_c, invest_d, snow_a, snow_b, water_c, water_d
    // ---------------------------------------------------
    // write to: water_a, water_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_G(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GSeedRunSeed_H seed_loop_e:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_c, fire_d, source, key_row_read_a, snow_c, snow_d, expand_c, expand_d, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_H(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aInvestLaneE, aInvestLaneF, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aInvestLaneG, aInvestLaneH, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // GSeedRunSeed_I seed_loop_f:
    // ---------------------------------------------------
    // read from: invest_e, invest_f, invest_g, invest_h
    // temp storage: key_row_read_a, key_row_read_b, fire_a, fire_b, expand_a, expand_b, snow_a, snow_b, water_a, water_b, water_c, water_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Seed_I(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: scrap_a, scrap_b, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    GrowKeyA(pWorkSpace);
    //
    // ---------------------------------------------------
    // GROW_B grow_key_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    GrowKeyB(pWorkSpace);
    Zero_PostSeed();
}

void TwistExpander_Rugby::SquashInvestToKeyBoxes() {
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneE = pWorkSpace->mInvestLaneE;
    [[maybe_unused]] std::uint8_t *aInvestLaneF = pWorkSpace->mInvestLaneF;
    [[maybe_unused]] std::uint8_t *aInvestLaneG = pWorkSpace->mInvestLaneG;
    [[maybe_unused]] std::uint8_t *aInvestLaneH = pWorkSpace->mInvestLaneH;

    // key_box_a row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Rugby::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSource,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSource, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    std::uint64_t aPrevious = 0xB7972A47C45DF0A4ULL; std::uint64_t aIngress = 0xDD54561C4A5A972DULL; std::uint64_t aCarry = 0xFD8A9AC0FF93C515ULL;

    std::uint64_t aWandererA = 0x9EA44C0820DEFFD1ULL; std::uint64_t aWandererB = 0xA451382F1FE97107ULL; std::uint64_t aWandererC = 0xD2D98ADA1D571AF0ULL; std::uint64_t aWandererD = 0xF36AB21D05786B32ULL;
    std::uint64_t aWandererE = 0xD1F73FBB9942D687ULL; std::uint64_t aWandererF = 0xD877D3FD3B983376ULL; std::uint64_t aWandererG = 0xD925EB909BDA5B0AULL; std::uint64_t aWandererH = 0xB109B4402F61D925ULL;
    std::uint64_t aWandererI = 0xD0566F35D7AA7473ULL; std::uint64_t aWandererJ = 0xFB2713BFAA19B753ULL; std::uint64_t aWandererK = 0xF567276485F95457ULL;

    // [seed]
    {
        aPrevious = 12724404686548920397U;
        aCarry = 12164205966325903696U;
        aWandererA = 17155298807035250129U;
        aWandererB = 9602741977288178986U;
        aWandererC = 14657573570394513406U;
        aWandererD = 10230873844184252616U;
        aWandererE = 13406940561169831253U;
        aWandererF = 10648215878621017422U;
        aWandererG = 12977460476129137797U;
        aWandererH = 18245244402536200948U;
        aWandererI = 17515781930049412705U;
        aWandererJ = 14853228720783523871U;
        aWandererK = 11016529452445082690U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Twist_A(pWorkSpace,
                 pSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GTwistRunTwist_B twist_loop_b:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: water_c, water_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Twist_B(pWorkSpace,
                 pSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GTwistRunTwist_C twist_loop_c:
    // ---------------------------------------------------
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    // write to: water_a, water_b, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Twist_C(pWorkSpace,
                 pSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: water_a, water_b, water_c, water_d
    // temp storage: wind_a, wind_b, wind_c, wind_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, invest_c, invest_d, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Twist_D(pWorkSpace,
                 pSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // ---------------------------------------------------
    // GTwistRunTwist_E twist_loop_e:
    // ---------------------------------------------------
    // read from: earth_a, earth_b, earth_c, earth_d
    // temp storage: invest_a, invest_b, invest_c, invest_d, water_a, water_b, water_c, water_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    // write to: invest_e, invest_f, invest_g, invest_h, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Rugby_Arx::Twist_E(pWorkSpace,
                 pSource,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        //
        // ---------------------------------------------------
        // GROW_A grow_key_a:
        // ---------------------------------------------------
        // read from: work_a, work_b, work_c, work_d
        // temp storage: scrap_a, scrap_b, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_a, scrap_b, expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_Rugby_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
                     &aWandererC,
                     &aWandererD,
                     &aWandererE,
                     &aWandererF,
                     &aWandererG,
                     &aWandererH,
                     &aWandererI,
                     &aWandererJ,
                     &aWandererK);
    
        GrowKeyA(pWorkSpace);
    } else {
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    }
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        //
        // ---------------------------------------------------
        // GROW_B grow_key_b:
        // ---------------------------------------------------
        // read from: expand_a, expand_b, expand_c, expand_d
        // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        //
        TwistExpander_Rugby_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
                     &aWandererC,
                     &aWandererD,
                     &aWandererE,
                     &aWandererF,
                     &aWandererG,
                     &aWandererH,
                     &aWandererI,
                     &aWandererJ,
                     &aWandererK);
    
        GrowKeyB(pWorkSpace);
    } else {
        TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    }
}

void TwistExpander_Rugby::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyA(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aScrapLaneA = pWorkSpace->mScrapLaneA;
    [[maybe_unused]] std::uint8_t *aScrapLaneB = pWorkSpace->mScrapLaneB;
    [[maybe_unused]] std::uint8_t *aScrapLaneC = pWorkSpace->mScrapLaneC;
    [[maybe_unused]] std::uint8_t *aScrapLaneD = pWorkSpace->mScrapLaneD;
    [[maybe_unused]] std::uint8_t *aMergeLaneA = pWorkSpace->mMergeLaneA;
    [[maybe_unused]] std::uint8_t *aMergeLaneB = pWorkSpace->mMergeLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneC = pWorkSpace->mMergeLaneC;
    [[maybe_unused]] std::uint8_t *aMergeLaneD = pWorkSpace->mMergeLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);

    // [grow key a]
    // GKeyFoldA grow_key_a_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldA expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 3, 2, 3 with offsets 2185U, 2713U, 1713U, 2670U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2185U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2713U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2670U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 0, 0, 1 with offsets 4243U, 5689U, 4334U, 7300U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4243U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5689U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4334U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7300U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 2, 3, 2 with offsets 7877U, 3236U, 1251U, 7735U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7877U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3236U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1251U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7735U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 1, 1, 0 with offsets 3364U, 3711U, 4465U, 6893U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3364U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3711U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4465U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6893U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 2, 0, 3, 1 with offsets 1922U, 1704U, 1955U, 1713U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1922U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1704U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1955U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 2, 1, 0, 3 with offsets 1231U, 1956U, 1969U, 1154U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1231U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1956U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1969U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1154U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 1, 2, 0, 3 with offsets 583U, 633U, 1486U, 972U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 583U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1486U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 972U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 3, 1, 0, 2 with offsets 1789U, 1706U, 670U, 15U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1789U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1706U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 670U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 15U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1897U, 1075U, 1642U, 1761U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1897U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1075U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1642U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1761U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Rugby::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aScrapLaneA = pWorkSpace->mScrapLaneA;
    [[maybe_unused]] std::uint8_t *aScrapLaneB = pWorkSpace->mScrapLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneA = pWorkSpace->mMergeLaneA;
    [[maybe_unused]] std::uint8_t *aMergeLaneB = pWorkSpace->mMergeLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneC = pWorkSpace->mMergeLaneC;
    [[maybe_unused]] std::uint8_t *aMergeLaneD = pWorkSpace->mMergeLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);

    // [grow key b]
    // GKeyFoldB grow_key_b_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldB expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 1 with offsets 4108U, 3841U, 1326U, 5960U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3841U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1326U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5960U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 0 with offsets 5032U, 5373U, 3404U, 3632U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5032U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5373U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3404U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3632U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 3 with offsets 3533U, 6046U, 4834U, 5666U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3533U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6046U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4834U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5666U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 4609U, 8129U, 5716U, 5391U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8129U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5716U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5391U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 7440U, 6014U, 3990U, 1561U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7440U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 6014U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 3990U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 1561U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 367U, 1814U, 439U, 744U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 367U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1814U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 744U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1648U, 1352U, 1983U, 1506U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1648U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1352U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1506U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1608U, 653U, 1072U, 194U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1608U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 653U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1072U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 194U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1086U, 1157U, 1655U, 258U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1086U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1157U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1655U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 258U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 2, 3, 1, 0 [0..<W_KEY]
        // offsets: 368U, 1063U, 1991U, 202U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 368U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1063U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1991U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 202U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseASalts = {
    {
        {
            0x79A42D0D352A0CCFULL, 0x3E0A59ADCDB56BDFULL, 0xE1420F6FFD76BBECULL, 0x50716BBB9515DB07ULL, 
            0x53B55EE62CAEF908ULL, 0xA3BA96AB83B53B46ULL, 0x59C7F0EEDCAF5D97ULL, 0xDDCD3C19859ED222ULL, 
            0xA7FA02D578EF74A6ULL, 0x95B2596C608D3907ULL, 0x6F35E58A23B45F95ULL, 0xD1E7A6899D146F69ULL, 
            0x4EC1D3DD848DB5E9ULL, 0x4BFDB3EF70264517ULL, 0x23364A7D0367403DULL, 0xF38B5D61D29A5E3EULL, 
            0xE6C0ABA483BA72C8ULL, 0xD99E41B73D021610ULL, 0x095F85DCC7488B46ULL, 0x86F9996F97053767ULL, 
            0xD9F5FF303C4D1FD5ULL, 0x2D25B8CDDF23EB5FULL, 0x793A68C0835F0374ULL, 0x2CB6FA1F5C05C25DULL, 
            0xB7E1055995496AB4ULL, 0x2EF7B8AD49D10DC6ULL, 0x0992C90EF9A01DCAULL, 0xF6C2EBE79EEF3F6BULL, 
            0x13F86F534FCCF2ABULL, 0x9AAA79200119438DULL, 0x9F131BEC29A01255ULL, 0xC830A4B1F2483518ULL
        },
        {
            0x9783B9FD51E2B218ULL, 0x91CF0A43288CC476ULL, 0xB0715F9AF15C1CC4ULL, 0x353E61B409D31F60ULL, 
            0x67AB1A9E34F57C40ULL, 0x7FE7F885EABC7DF6ULL, 0xADBFA94B749BEA3AULL, 0x2DBFB0100D8F7337ULL, 
            0xE91C8CC75D49F50BULL, 0x2AB7028FC17CCDE1ULL, 0x73350C3E76F09EF2ULL, 0x4312CEED89033FD8ULL, 
            0xD033A232DC8A077DULL, 0x1E18868E051ED825ULL, 0xFC19594988020DC0ULL, 0x379AC238393E8BEEULL, 
            0x7700974925D38A33ULL, 0x742543909EAD9971ULL, 0xD7FD4B7693A1799EULL, 0xEEF32EC60C560F3CULL, 
            0xF29BF08DCAC78071ULL, 0x82CFD510C3EE5E31ULL, 0x13BB87F52E5E7098ULL, 0xCEBC60EBB3F9B8F0ULL, 
            0x41B58C382E28100AULL, 0x5094B8A00FB0F03EULL, 0x98406C91B5CF36B8ULL, 0xC7F79AC50D208FF3ULL, 
            0xD4878BAF0453BEABULL, 0xBBF84AD1C05C1485ULL, 0x302937F3D3C76C1DULL, 0x750ACEFE82804090ULL
        },
        {
            0xBD809AA7B3B21056ULL, 0x1F9BC8309221956FULL, 0x00D6F0815B9BB57BULL, 0x3AA442B2568C81ECULL, 
            0xB173EB87377BD32DULL, 0x3C2FCA19DE2F7A16ULL, 0xC60975869594717FULL, 0xDF228871C9AE1B47ULL, 
            0xC86CFDB1D0BF3ED5ULL, 0xB01820164D9D65BCULL, 0x3866FD0B9914C95AULL, 0x4666B6B4A6BDB3F2ULL, 
            0x2C8264E2B935DE0EULL, 0x6FE77E77742D7C67ULL, 0x054ADA9738F40349ULL, 0x393E74B63041961CULL, 
            0x6AE109E612D609B8ULL, 0x8DA9427B7E21890CULL, 0x3AD513DA11BBD7A7ULL, 0xD5316B805B5F7B84ULL, 
            0x728D047498508D02ULL, 0x1B5B9E2B9AA54F6AULL, 0xB2E9CDC42674F480ULL, 0x1D29120BA21678E1ULL, 
            0x0B0DBB41808314FCULL, 0x2421259BE13E092BULL, 0x630BF12E4119A0A0ULL, 0xF7D00DFD1FA57D69ULL, 
            0x9C77EBA82A8B7422ULL, 0xB4491DC7499129B2ULL, 0x9C0083D02A1432F9ULL, 0x90880DA031243E3AULL
        },
        {
            0x921671DC0F50FCEAULL, 0x69B7BFF902BF2908ULL, 0x7CEC40A589AB5868ULL, 0xCCDF992619E67ABCULL, 
            0xB9D21EC9FE2C7DEDULL, 0x96625EB38B37BB2BULL, 0x94598A2DEA97CB75ULL, 0xB56EF593D1035923ULL, 
            0xE6EB5502B3375094ULL, 0x0E3FA55A1FE24E94ULL, 0x9A2B0ED948ACFB41ULL, 0x794EEFBE40DEAB71ULL, 
            0x7B0454F7B61C59D1ULL, 0xA93A38288544654AULL, 0xF9C232E3C895E626ULL, 0xB1384DD05EA7C14DULL, 
            0x3EE6F3CDEBAD21BDULL, 0xC5042F2BCF2BCFB1ULL, 0x0DD103AF9F8E2AB4ULL, 0xCA6AC8B53C325AF1ULL, 
            0xC248A2F8C3770703ULL, 0xC9E172D4EA297A0FULL, 0x39DA3B2700ED8EF7ULL, 0xF6C207D385A18EDEULL, 
            0xE2D7D69B7C976C90ULL, 0xA6FB0CA2C633A5A9ULL, 0x583FA95E30788DF9ULL, 0xB423BE9232B54C3EULL, 
            0x4BD2FFCE1D74B5D8ULL, 0x848E7A547D5E154DULL, 0x496B8CB6E08D2877ULL, 0xCF1D81BD77CA593EULL
        },
        {
            0x34E7E5620CC23CBBULL, 0x72E7BD3FB91A758CULL, 0x1FB32C79E3D1AA70ULL, 0x8686003A7E463FF0ULL, 
            0x3190D153D0EA8047ULL, 0x55301F8C295CAC67ULL, 0x7E802A3F856CCF2FULL, 0x52988349AED09663ULL, 
            0x8490BCEEF7B8E9FAULL, 0xE45765B7430158B3ULL, 0xCF23AF9D03192046ULL, 0xE18AF51B46C76C5BULL, 
            0x88CE5A9DC596B936ULL, 0x829F742B34CC9030ULL, 0x15138F0168CD3530ULL, 0x874C94EF2B71F1DDULL, 
            0x5F9B9F0CEBDAE3C4ULL, 0x775A7C3F9CF81AF4ULL, 0x6FCED09C8705BE70ULL, 0x7D8A4D787DAC40A5ULL, 
            0x3ACDD76CA94F268BULL, 0xA47E40CF87C8D9AAULL, 0x1286215350A6054DULL, 0x73CCA023F4AF7A26ULL, 
            0x17A3073AFDEC7AABULL, 0x2AB089772697C8C0ULL, 0xCA6D683B0394DBDAULL, 0x2E099DB15A784C2BULL, 
            0x7B5F67BE740C78F9ULL, 0x107ADE583927B983ULL, 0xD2DA746E14941A77ULL, 0xA25AC161F7124C42ULL
        },
        {
            0x322B9DF2E9CE5F7CULL, 0xD2738D231EB0CDEBULL, 0xC3442543425EF3EAULL, 0xDA34D3266C114B70ULL, 
            0xD5B06B38C679E9FEULL, 0x8ACDA888A756FA4BULL, 0x54EEC55CD8025604ULL, 0x2DDAF4516BDCED5FULL, 
            0x81E1FBDE47E30FE5ULL, 0x32D041D276F84A81ULL, 0xA15B83360E2CFCD9ULL, 0x4E0A71F448456950ULL, 
            0xA65FAF7D2C843597ULL, 0xED350AD2F7B8C75AULL, 0x1F871722CA6E6E8FULL, 0x6A1B114B4E3A896BULL, 
            0xB193A6EDA0EF860AULL, 0xFBEDDF65BA177E20ULL, 0x980651B1AAB46601ULL, 0xCFDF5F39F9989051ULL, 
            0xF757130B035E113AULL, 0xD6559F1DF7A68DC8ULL, 0xBC444EA8157815F3ULL, 0x15F556A00033D0BAULL, 
            0x5BEE43D1EBE92D64ULL, 0xADF41878D6A53FABULL, 0xCC5E7E8832A04D47ULL, 0x99D969E1AC32AF52ULL, 
            0x5D410C549F17D35DULL, 0xAD9E19525FFD0C7DULL, 0xF3F2229F00BE8E99ULL, 0xA95EE2CFB814C7E4ULL
        }
    },
    {
        {
            0x5780AC2CAA30B517ULL, 0x009EDB7D9C40A939ULL, 0x85D9DEB779DA97D0ULL, 0x1709064008AF7E34ULL, 
            0x1FEEADDBA13B7DA2ULL, 0x1FCC9254793CA082ULL, 0x0238BDE3815ED1A1ULL, 0x978284F2EC194C1EULL, 
            0x17476B70311A7217ULL, 0x249EA28107EA2833ULL, 0x3363411D7960F593ULL, 0x131CAF227B860E0BULL, 
            0xAFB5D655D3FBBC35ULL, 0x8AE42899199B983DULL, 0xDDE8189B96EDBB7FULL, 0xB3F6EFF4F896A202ULL, 
            0x7293B3B6576C533BULL, 0xAE5A60BB9827B784ULL, 0x6A219D871473B71FULL, 0xA19E1ACC306FC898ULL, 
            0xA75235A795E92003ULL, 0x9AFB1F9ABF316F32ULL, 0x019C9D2F4ADC4BE2ULL, 0xC2E86115716B5EE9ULL, 
            0x439167955D1FBBE5ULL, 0x00E1E071DAC44AC6ULL, 0xEC92236F0F13C7BBULL, 0x84367D96FAF50888ULL, 
            0x67471CCA82CC8ECAULL, 0x6B855CA160FF059CULL, 0x8D9C10BE6A9C0138ULL, 0x05ECA3821A596AE2ULL
        },
        {
            0x2F0D5C08A67AF72AULL, 0xBDEB8F8C2EB16E08ULL, 0x55C0AC6CD1DA19D1ULL, 0x4C00CE0D7F06D343ULL, 
            0xF0426685BC36A55CULL, 0x11CB55D8B9ED056EULL, 0x8538B48E6642A6F1ULL, 0x310C8AC38ED37D71ULL, 
            0xF0EA8420ECD3026DULL, 0xF8DBF2BC086A87C7ULL, 0xF565A796505C057FULL, 0x4E28915EDD3D4476ULL, 
            0x40E500C60E72ECE3ULL, 0x12E023FEDC4D77DCULL, 0xDA5F0F3CB090DF01ULL, 0xD68BB0E238FE762AULL, 
            0xB41DCD3CF94F038DULL, 0xD3C1949AEA6DF975ULL, 0xAC3E3CC566D9961DULL, 0xA5D6133E9C3F6359ULL, 
            0x34EEA183E289ACB3ULL, 0x7D9905F3DCAFFD5FULL, 0xCDD6884A763483D7ULL, 0xB80CC36C8C615A51ULL, 
            0xBE13A763E0BAC2DCULL, 0x4CBD04E74B9831F3ULL, 0x1EDF413FB19445BEULL, 0x8A953085B69B2FC9ULL, 
            0xE6343EFE6EDC4860ULL, 0xA47A4B80BA6A18BBULL, 0x61E46D9FBB5AAAB5ULL, 0x770DBE066C382E04ULL
        },
        {
            0xCF6F9DF3642FDF57ULL, 0xF583B6EA133DCAA4ULL, 0x0988FA7906D20627ULL, 0xFC37D49A0483300DULL, 
            0xDEDA17833EC88980ULL, 0x8754E16385F37564ULL, 0xBBD2751F3651F676ULL, 0x8EA5FC8A68F38819ULL, 
            0x8977AA7277755AFDULL, 0xC30AF1689C1FC2D5ULL, 0x14191BD8AD2B17BBULL, 0xEA241C26B907DF58ULL, 
            0x960F2491C7BD44B7ULL, 0x4E1802DBFF841FC4ULL, 0x5D17A0CDD15A0B3BULL, 0xCC2A33FDD1762523ULL, 
            0x80D603E10BA76273ULL, 0x6FCB00A3642E0503ULL, 0x9D83930AC53102F0ULL, 0xB31A01727949C5A5ULL, 
            0x58182AA4EC902D7EULL, 0x364C71CD1EDE981DULL, 0xF35D5117FF227EBBULL, 0x753AF0A6931B75F4ULL, 
            0x2C2B63DA8A2EEC6FULL, 0xB8F1F4E1957039C1ULL, 0xBCFD01B2E8216014ULL, 0xA840EF6A521FA8E8ULL, 
            0x71D4DB59B04009E1ULL, 0x9D7BBEB6F5F730FAULL, 0xCC8DAD80A02B069AULL, 0x9A1C4F6CF90B9450ULL
        },
        {
            0x6649099D1C5672ADULL, 0x0C296ADE939DB400ULL, 0xF49B5A1252130C48ULL, 0x1726460901E83B35ULL, 
            0x38E64E9A1F67DCECULL, 0x109309243EDCE980ULL, 0x055474ACF5A015D7ULL, 0xD45B7F4FBFA8AD66ULL, 
            0xF0D828A8BC7F6961ULL, 0x7887EDDE53AE859AULL, 0x15E9038C0A46D394ULL, 0x1F5A62D11A831F3BULL, 
            0x657FDEA8F399F80EULL, 0x47CE368C76E64418ULL, 0x185495964BD59705ULL, 0x08C36EF5FF0E9BF8ULL, 
            0x131A3CA194B5D945ULL, 0x6541807C8508B0C1ULL, 0x635B891B42B118A7ULL, 0xF9D2EF4CEC4EEE85ULL, 
            0xBCE08B3B1676F71AULL, 0x7D648F61ED224769ULL, 0x7C39A19560D261F8ULL, 0x0F47BEFE4E99D318ULL, 
            0x77A7E8F127458048ULL, 0x1488752A8BD3B620ULL, 0xFA3F4E061751B606ULL, 0x47A2060FF725A8ABULL, 
            0x8C672C640D17A79DULL, 0x815CC19690CA01CEULL, 0xF828E79B50B5C25FULL, 0x63A923E917065538ULL
        },
        {
            0xF839DAFA56D8539CULL, 0x21F743D31850813DULL, 0x3A744CFDC45BD82FULL, 0x5B455229225AB110ULL, 
            0xBEB5FC2041469CDCULL, 0x9D54B1855CBB58D3ULL, 0xAF9129A054938DE8ULL, 0xD5458229BC96B320ULL, 
            0x4CC8A52C17BA33B8ULL, 0xAC3EA0A6605AD099ULL, 0x7834A79AF3A451BEULL, 0x6D161520D1797719ULL, 
            0xCD1AAC002E43386BULL, 0x86F3F97D429B0B8BULL, 0x09028771A6C706CEULL, 0x5BF71580640711B4ULL, 
            0x0356C3E788D91CBEULL, 0x3526EAD536C62779ULL, 0x29A0FE3004E09C4CULL, 0x95977CDC483949DDULL, 
            0xC77734F1F8041002ULL, 0x7BC1430B9F1138C5ULL, 0xBB51B0F3C47B0DE0ULL, 0x25179092024B9457ULL, 
            0x6635AD35CBFEB0E6ULL, 0x520327CD868C5060ULL, 0x58EDAD348E4DB5A9ULL, 0x32B9859F64334EFFULL, 
            0xC537962B0F88A5ABULL, 0x3698FD0C8E5828E3ULL, 0x1AEAFAC0FC3D5F25ULL, 0xCE43D40F4EA7D391ULL
        },
        {
            0xE4D769E4FEBD2357ULL, 0x29D2FFFE34D63C23ULL, 0xA303CAEB191EFD13ULL, 0x37C4233A2582E01BULL, 
            0x1049953BE6735A21ULL, 0x37D87DF08332C337ULL, 0x7D9EE088EC657B29ULL, 0xCDCCE394D7F7633AULL, 
            0xF13E7CF58E86FC2EULL, 0xC48AC3F8195F5FD5ULL, 0x28D56E1B7DFE51E3ULL, 0x52541727A549C26AULL, 
            0x712AAFA59B988883ULL, 0x4B34ED1B0B0FBDA6ULL, 0xE06CC81BEFD7D8FCULL, 0x2477B0D70D6961A6ULL, 
            0xDD6742CC5F58B340ULL, 0x8EB3B6B80153B88CULL, 0x9C53BA83ED4A3A1DULL, 0x93712997CBA769ABULL, 
            0x6A8E4B94524B050DULL, 0xC0C97A095CE91534ULL, 0xA9A01D8FD877212BULL, 0xD28403342B238BAFULL, 
            0xD7B23C174E93FF0DULL, 0x7C61596DA3491B3CULL, 0x302F67C3F85443EDULL, 0x6603B465BA3D96E3ULL, 
            0x256704825B3DEFAFULL, 0xBF821AAB8A5E6F01ULL, 0xC22DE3DEC2960FC5ULL, 0xD99D058DC8A381BCULL
        }
    },
    {
        {
            0x4B0D8364F428A519ULL, 0x3DFC053D70B10F55ULL, 0x76409C58F60C4E3BULL, 0x04DE16C2E2E84EFDULL, 
            0x288889A191212469ULL, 0x3C51B19D41853E1CULL, 0x281E2AC8BDBA5EB1ULL, 0x1A82F03F169323A4ULL, 
            0x7849FA9A69BDA8E2ULL, 0x9777D8D45A7E3AB8ULL, 0x47AD16451B8BF78FULL, 0xD0676325CDE50466ULL, 
            0xDE3AECCC005004BCULL, 0x3FC55C9AE9E0FBF3ULL, 0x73CD3B7636F5A4CAULL, 0x5243D15C2B8AF2EBULL, 
            0x0D462EAC81022B1AULL, 0x4861B1A6BE098343ULL, 0x7925ED706A1EFEECULL, 0x63E37EED957A078AULL, 
            0x3E80BEF1FB8EC488ULL, 0xD9BB070553E1F3C9ULL, 0x50F07AED22B567C2ULL, 0xCF183C5FBB8FECA6ULL, 
            0x1FFDFF933F2906CBULL, 0x35F86DFEAC7F279DULL, 0xA3E4A39E51E0BC2CULL, 0xDA5FC332F313F3D4ULL, 
            0xB3DAEBC10A7C5D15ULL, 0x0A45C131E3B1382FULL, 0x435810553B0E57BCULL, 0xF6D579EE25ACB984ULL
        },
        {
            0x8462237BF6B43929ULL, 0xDBE95B0196B2CD09ULL, 0x70311B6F753D36A4ULL, 0x127DB07AA6724007ULL, 
            0x4CE63318E86099A4ULL, 0xF6931221D22D3D63ULL, 0x7C5B6CBBFD8934F4ULL, 0x73FA26394F7DAB88ULL, 
            0xDCFBC67F71C41F73ULL, 0x73B6BC01824CC2F8ULL, 0x133B954DC266D154ULL, 0xCC5CC4DE71199FBEULL, 
            0xFCC6F62B42C4B6C1ULL, 0x6C89CF6C6852A6F5ULL, 0x06067BFA65ACC47AULL, 0xF8101A67A064EBF2ULL, 
            0x077ECB8E25A0AF6BULL, 0xBDCC89F7C24D0BBDULL, 0x4E2FEC950E1B79ABULL, 0x13645D303C078178ULL, 
            0x9BF0C0E6F1E2F619ULL, 0xF95BDAA75D945E9AULL, 0xD329230528516E72ULL, 0xA962D55759DC9608ULL, 
            0x45ED0AB99481B092ULL, 0x14D80C1680ADDDE9ULL, 0x94DB46701918F98FULL, 0xDEEA9778F65E36ABULL, 
            0x7A18A1BEA99A0BE3ULL, 0x5D23A0488C243400ULL, 0x94F74097DF4ABAC1ULL, 0x8F16B1EC4E4D700FULL
        },
        {
            0x3EDF0E7D985D8D40ULL, 0x8A40C29928619846ULL, 0x777C4214FE7292F4ULL, 0xEEAAF825BC530C32ULL, 
            0x862D197D23A2D46CULL, 0xFE0A35424A1F4E4BULL, 0x96B1F4DA302AEA7BULL, 0x04155B974C6569E7ULL, 
            0xB7FDEC6D5C48C10FULL, 0x0CC6F59F21E71949ULL, 0x94C32A186860AC6BULL, 0x697CD2CF4C73F067ULL, 
            0xC570DC053D3E816AULL, 0xAC8AD8A8FA2F5031ULL, 0xC4AAFF7B6607D9B9ULL, 0x46BDB1F0802FC37AULL, 
            0x2C899DF8ADF06941ULL, 0xD870EA4128C1DDE6ULL, 0x53D1E114E6802D03ULL, 0x769CC52190D02F66ULL, 
            0x9892E3055CABEB7CULL, 0xFBED51CCDB8C0E16ULL, 0x6EFAFFDCE0DF8986ULL, 0xF1FBF2F554BD0401ULL, 
            0x029CA2D2E45C33D0ULL, 0x2C0A69B4DF5FC07DULL, 0x72AA2F289DDBB5BFULL, 0x5FE68C297AB3C108ULL, 
            0x2220A1A072222EC8ULL, 0x4C9F4C28F33DF8A8ULL, 0x24567B47A3B66FF5ULL, 0x6739506AD3C8B270ULL
        },
        {
            0xCFEFC0635D135DFBULL, 0xEA47B7AE48FF1905ULL, 0x607FC7EB9BBB5898ULL, 0x61648B874585F052ULL, 
            0xBEB90AF6821D0D0FULL, 0x0A979AEDDB9AAFFAULL, 0xE97956CCAE36F4C6ULL, 0x52AFBC6EE99845B6ULL, 
            0x74F8281496FE79B0ULL, 0xA68F2599E339C78CULL, 0xA7C6D273B138F8AAULL, 0xA3EBA435247F8DA0ULL, 
            0x45806A6D6556358FULL, 0x2152E4D0D5E9B4D4ULL, 0xC96144D5B8140879ULL, 0x15ADBDDDBF7743D7ULL, 
            0xC23EB5445C32FF26ULL, 0xF4A4C24952297D50ULL, 0x1836F17119ECEA4AULL, 0xC8E701298CC9FAB3ULL, 
            0x7CEEC97A2680D16CULL, 0xF463E29E32770E1CULL, 0xCD07E2B1A744BDF5ULL, 0x29C080F6C6810582ULL, 
            0x6A3156B2A45CA89EULL, 0x2CBDAF7451339370ULL, 0xA0AFE820C57B4FCBULL, 0x77DE3D01DD3CB20BULL, 
            0x813B7E9FC533262BULL, 0x5C0D88E2E133A907ULL, 0xD095D897B3F8277DULL, 0x65A39C8A17EB9425ULL
        },
        {
            0x6A5417F8B22C267AULL, 0x0B64BBA2E892AE4CULL, 0xE182A67FDC23709FULL, 0xB43C6298771A4EDDULL, 
            0xDB17981A3B392B2BULL, 0x82E9F94C32BFB3ACULL, 0x28EAB8BAD77D4B94ULL, 0xDB8615BF61F6EABAULL, 
            0x19255952B7F5AC46ULL, 0x4478782B245324BEULL, 0x26E4A93936B70B63ULL, 0x9AFC631D169BE87EULL, 
            0x0B0297647BF38624ULL, 0xC53294E7AC2410CDULL, 0x6BC11CE38324421AULL, 0xD9469E61B9BB647BULL, 
            0xD5C7EF73F1D10236ULL, 0x5735800F1BCC513CULL, 0xCF4A818C64C7EEBBULL, 0x10804DEB58811E94ULL, 
            0xBD876D1122CB0F1EULL, 0x6367490AE7EB669AULL, 0x19226C55CD07EBE5ULL, 0xA0F529357900007CULL, 
            0xB244B06C30BD90E1ULL, 0x35C9E1C127F715C4ULL, 0x4588A898229A89A5ULL, 0x94C813C6C3FD65D6ULL, 
            0x241CB260D332FFC1ULL, 0x615343D02FCA9F69ULL, 0x3E29CAFC66508260ULL, 0x588E9D65A3ECAFDAULL
        },
        {
            0xA28C8A10914757EDULL, 0x1B424E926A43D7D9ULL, 0x8051C557A071A58DULL, 0x1BADA41BD484308BULL, 
            0xACFC3E28613AC047ULL, 0x876583472B7A23DCULL, 0x8B2135866C187DC9ULL, 0x94FD357D0570B8DDULL, 
            0x9ACB124725086E9FULL, 0x317597BBE73546DDULL, 0x3258FF008738DBBBULL, 0x561AE7C160DC2798ULL, 
            0xF7FC048FDCD2660FULL, 0x8A463B8DD63C12A7ULL, 0xF50418429691798EULL, 0xDB8BDC505B16A3CAULL, 
            0x268EE204860C6803ULL, 0x01ACCEE86E43AD57ULL, 0xD10FA5E73F96516BULL, 0x9796229A1C507486ULL, 
            0x6BA214B83A0B12BBULL, 0x98DE55CDCEB0692CULL, 0xD63ECBC602469923ULL, 0x055B84BA973666B3ULL, 
            0x543A02B26CF30B85ULL, 0x2E624B45F9389146ULL, 0x8967EB5D7468A038ULL, 0xD34DE6C422D64930ULL, 
            0xBDB229A1FDACDD53ULL, 0x5B8BD194F49E3A1EULL, 0x636DF9C316E13F10ULL, 0xA3AC145507D69745ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseAConstants = {
    0xF6ECBB000A9E664EULL,
    0x877303730E40AAF4ULL,
    0xB6DC8299834354A2ULL,
    0xF6ECBB000A9E664EULL,
    0x877303730E40AAF4ULL,
    0xB6DC8299834354A2ULL,
    0x7AE6A627ABEF2324ULL,
    0x5B6585F63DDF9971ULL,
    0xA3,
    0x0D,
    0x13,
    0x25,
    0x4F,
    0x78,
    0x0C,
    0x36
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseBSalts = {
    {
        {
            0x72E07B5672A2AA31ULL, 0xA083B95F567B33F0ULL, 0xADDC8B74059758E3ULL, 0x1B719FA0B6DD8BA0ULL, 
            0xADD0330B9193A2B3ULL, 0x5CA876EC1B33E05AULL, 0xFCFE19BDD1A3F590ULL, 0x88F8BE37CE9E5F42ULL, 
            0x9A2139E48A08516BULL, 0x6E0281C519637B44ULL, 0xBB6126B81C6E2312ULL, 0x4AD2E3C0C396CA0EULL, 
            0xB9C70B75A715F7F1ULL, 0x0E3D958138DE4198ULL, 0xED88FCB29EDCF43EULL, 0xA9B6E96B43B02786ULL, 
            0x3D216DA58D0C1B93ULL, 0x19D5E4A04052D7C6ULL, 0xB56E7C9F7FBE3A6DULL, 0x5E412CD4DF1A2C87ULL, 
            0x907CA3DD2AC88AEDULL, 0xC24985EE4243EBE8ULL, 0xA26C9362CBB720C3ULL, 0x0AA9507C3C4E4A7FULL, 
            0x6B582DB73E85723EULL, 0x68F93BDA8CA29522ULL, 0x9FB3D8223E6ED7B6ULL, 0x1C79174AF49145DAULL, 
            0xA14C158A9E67D1E5ULL, 0x7200FF5BD2BDBBE1ULL, 0x59A62487BD5ED502ULL, 0xA678EAD255F08140ULL
        },
        {
            0x40031CAB5B6B91D7ULL, 0xCBFAF9B39E957A5BULL, 0x258290B8FD292A92ULL, 0x042B822115CB362DULL, 
            0x7B6C739D8C9912D7ULL, 0x3913E8E5A7B643BFULL, 0x33F605A5A9CB9F6EULL, 0x9BCF2FA07D0D31D2ULL, 
            0x26E514E905ACFAE6ULL, 0xFC4CED5180EC409BULL, 0x26063DB3918F006DULL, 0x8158D722E6235F8FULL, 
            0x6CD2D399979DC325ULL, 0x5503B398DF27D3F1ULL, 0x16B58B74EEFB9DA6ULL, 0x55E3A1F2EFB8DDEEULL, 
            0x6BFD23CC20B49B01ULL, 0x2A64893EC43D02B0ULL, 0x2C60AF884916E9A0ULL, 0x226640E7B315BEE4ULL, 
            0x554C6CB26FEDF742ULL, 0x3567B1E811AC0F78ULL, 0xE6F3E769862EB25FULL, 0x2E4C9AACE65B2898ULL, 
            0x649EF75043E13054ULL, 0xAD09D928741B5613ULL, 0x52D71C17947C4DDAULL, 0x157BDA1E9D131275ULL, 
            0xCF305BC4558621CAULL, 0xEEFB98F0E565D783ULL, 0x455CEA27E99406FBULL, 0x63BE3CE17F29EF48ULL
        },
        {
            0x7663F46C5C1CFD9FULL, 0x92ADFAD72623E9BBULL, 0x7565348242F11B25ULL, 0xD740FE9AFD9C06DFULL, 
            0x4393BD741F4411DDULL, 0x33CCEC28EA19579DULL, 0xEE254DCE162175EAULL, 0x52C6C4281FF533B0ULL, 
            0x768FFDC70DEFD7F6ULL, 0x37C600FDB131BFE9ULL, 0xDF68FDCBB42491CBULL, 0xA1F9EABF7074CE26ULL, 
            0x0353449A7FC45866ULL, 0xD21E63549FC732CDULL, 0xBC04219FA7892421ULL, 0x4DBE2F5ACA2C8476ULL, 
            0x6A3241BFC19B09AFULL, 0xAEA4151829993521ULL, 0xD6171640F7CBB5ADULL, 0x9D0D9C5085AFE33CULL, 
            0x14C28C05082F067CULL, 0x61FC943E7CEE14DBULL, 0xF17DAF308F02A51BULL, 0x5064F75C8176316CULL, 
            0x1D824FC9C525FB00ULL, 0xDDD8903F416616F2ULL, 0x9D2C125743DFA45CULL, 0x818C6DA9ADDF25B6ULL, 
            0xDCBB05DE1F79BA0DULL, 0x5F3C75419EF0F2F7ULL, 0x64C7715F19CF2E9EULL, 0x68A4CEB53380D7B0ULL
        },
        {
            0xDCD89CFDE5660F27ULL, 0x262C715EF9C98726ULL, 0xEF6EBDD6A5337761ULL, 0x9A8956279EA39DC1ULL, 
            0x1372B265623C199EULL, 0x5A3BCB6DAB1E489EULL, 0x2B95D1F24C95BDA6ULL, 0x8372A3B5015C6790ULL, 
            0xA75864820B107EB0ULL, 0xB5ACE4BCEBC0C638ULL, 0x1C963E6FAA0D1230ULL, 0xF6495CF954D88D0CULL, 
            0xF650A72134002376ULL, 0xD04ED6668C429FACULL, 0xD407E31950F8B0FCULL, 0xEA0F8C6D6D9D4464ULL, 
            0x3690EF3B60D0C91BULL, 0x72D2AD198B6EDA4EULL, 0xB1754900E6187127ULL, 0x12AB2EA486E2F384ULL, 
            0x3336ED3FA99970C6ULL, 0x845F94E7E77985EAULL, 0x91C29483DF24A44FULL, 0x268F094EFE9E0E4FULL, 
            0x48FCA1DD881C56C4ULL, 0x7303FF7CF55C5738ULL, 0xEC90F8975F701CC5ULL, 0x744F44E97334A424ULL, 
            0x823D15930DC206D4ULL, 0xC076F0BC33405936ULL, 0xD4D747389C6955C9ULL, 0x8840150980263471ULL
        },
        {
            0xB5B85D8535D4415BULL, 0x8BBD884BD302AFB4ULL, 0xF5B8F7047D6D2599ULL, 0xE79E29976FEE8F0CULL, 
            0xEF20332DC1723B3AULL, 0x7E14232ABFFA0934ULL, 0x0EDA0EAEFB897B9BULL, 0xA60A6D9601390F88ULL, 
            0x6D92030613356C24ULL, 0xC1F6D9DEDADD9961ULL, 0xBA59947B5F248373ULL, 0x4CA74C8B0155D19AULL, 
            0x4148238B75C5CC28ULL, 0x6278130F2FCC005FULL, 0x25A2C3BB9C8C603CULL, 0x52359FE740CE3FD6ULL, 
            0x31382C346B7862F5ULL, 0xBE15AFADC905C197ULL, 0xC0DE3D15B394D63FULL, 0x06DB4509866590F2ULL, 
            0x71E82078A28CB0BBULL, 0x6F7A2223755DEF89ULL, 0xF274627066546158ULL, 0x615DCE79DF013967ULL, 
            0x84A982A6D4EA85F7ULL, 0x72F5B373E173E91BULL, 0x60ECC7EA27DB44B0ULL, 0x1EC69559A10FB8DDULL, 
            0xC349AF049B2C6792ULL, 0x059BB1BAB2448870ULL, 0xD8627F4D501F9901ULL, 0x6FC5DD14424A30E9ULL
        },
        {
            0x30F41BF92251011CULL, 0x716642F94106D3CEULL, 0xE928B5ED9938F375ULL, 0xC509A7BF8EE34E69ULL, 
            0xCD4A0101EAC47AA9ULL, 0xB6007AF4AA6EBFF8ULL, 0x951248AC06790D5BULL, 0x0D77EA7CE152DE98ULL, 
            0x29A20E2073AB50A5ULL, 0x969027E2A64C81F1ULL, 0xAC7D9C8AEA245E5FULL, 0x203BD8912710F0F6ULL, 
            0x3044FDFD1CC9D914ULL, 0x6DE8AC3E909F60A0ULL, 0x8243A01E9F705EB6ULL, 0xBDB7909CF5C337B2ULL, 
            0x61D52C79E0083656ULL, 0xEA104CBC1D60AD71ULL, 0xE0AAD88532D0C1DAULL, 0x1D961720AA93C7C9ULL, 
            0xB02FA86D709EE41CULL, 0x836F6EE3D79997D8ULL, 0x6093ADCC2B5AF217ULL, 0xC1724EFBB5937A9BULL, 
            0x17D6708085804EE6ULL, 0x55D02AB9FD85B809ULL, 0x563E4C9340E9FD98ULL, 0x8CA28BCCDC4D9874ULL, 
            0x52D9B57D46947318ULL, 0x2C62B51A531ACDE7ULL, 0xFB556C1188A0C93EULL, 0x8000ACCF9E7235D5ULL
        }
    },
    {
        {
            0x15B1A79707036A88ULL, 0xDFC2C9E1E153DABAULL, 0x46FE8AACE1A0D2E9ULL, 0x2B69B1561E8CA822ULL, 
            0x7E923901EF334B62ULL, 0x5F2BCB1D8A03ACBDULL, 0x041B8EA51A691172ULL, 0x6DAC285DEFE29D04ULL, 
            0x36C468A6644B81C7ULL, 0x14BE7197DE1AD737ULL, 0x53CD37A0813D7C81ULL, 0xC0FE44F509F9771CULL, 
            0x554746589B13255CULL, 0xA46CFF31E9848161ULL, 0x01BBE13CCDD97471ULL, 0x882F65F96A413BD3ULL, 
            0xDDF221921C205A1FULL, 0xB7E9F815F5CF7619ULL, 0x9986D152235AB269ULL, 0x967C242FFCA5E297ULL, 
            0x7BA7C641B75A9B16ULL, 0x459C52DC1610A4CDULL, 0x7672A927DEC9B527ULL, 0x3A578DECA5445C37ULL, 
            0x38B496F1127F431FULL, 0xD6A6D736355F95B0ULL, 0x8D0701DBCC69743BULL, 0x7C0238EA60558B25ULL, 
            0x186BB582FF718723ULL, 0x0774983A34AAB81DULL, 0xE4F359DC82C60F03ULL, 0xB780622AA525E90DULL
        },
        {
            0x366C932389FA6A22ULL, 0x95AD4706B79B7918ULL, 0xED71E397522C9C3CULL, 0x1D04FF64D2A49FF5ULL, 
            0xF58403067B86AFC0ULL, 0x44A85C68B9080516ULL, 0xFC82369A9F449141ULL, 0xC1FD2A57DCE25EB4ULL, 
            0x7DCED632FC46AEAFULL, 0x7A7059946BBFB74FULL, 0x19BACE13BC273CC8ULL, 0x9F304ABE05E7005CULL, 
            0x3E0BCE9126D41122ULL, 0x4775B5EAF2ACFBEBULL, 0x6A5FE38B508B7CFCULL, 0x0C87C22681F5EE23ULL, 
            0xCFBE07A9FD11F3A8ULL, 0xC4487A71C58812BDULL, 0x18837FAD583D3DD1ULL, 0xA8F2735E37E3DFB8ULL, 
            0x87BF126F12B9ED69ULL, 0x92B45FBF7C25A00AULL, 0x66C88158F04C2BAAULL, 0xB1CBEEEA6D81021AULL, 
            0x77D5AF7B619D5E3AULL, 0x0FE8A5CF0B3A9F75ULL, 0x80B1BDE537C29547ULL, 0x0C529142C8612CB8ULL, 
            0x8C17C0E500694625ULL, 0xE2858D331EDA9A11ULL, 0x4102824209E930C4ULL, 0x9647CF68FDE82692ULL
        },
        {
            0x55D47C62BB1014FDULL, 0x84D06C2524081D53ULL, 0x99A18A44BA02FD55ULL, 0xF58A3BADD1B3D035ULL, 
            0xFF8F3474D91A5282ULL, 0x1875242A59AAA655ULL, 0xB08A9FB2D8BC0240ULL, 0x6A47ABFBB3ABE927ULL, 
            0x2B40CAF4E7EBA448ULL, 0xC8C9977BB917F449ULL, 0x61C4F2F4CF4D98D6ULL, 0x11662BECC3291C4DULL, 
            0x81FE27AD7A6B3786ULL, 0x5BE93D43060D2EFBULL, 0xC189718116FE6EF2ULL, 0x446D66F4880DB13AULL, 
            0x1443AA9C73B0CDE7ULL, 0x8EAB0BDD9A4D20FBULL, 0xD64684E8C687D412ULL, 0x60DAA885F8923CA4ULL, 
            0xEB772E8593038382ULL, 0xA87514B5A0B3ACDDULL, 0xC53BB2D56B2D4D8DULL, 0x41F78E15DE67B3A4ULL, 
            0x4744EDF07160AEF1ULL, 0x0DD8DF608A37B01CULL, 0x0357CD2DBB000557ULL, 0xDD809BC0FCF61107ULL, 
            0xAF60C735AAA4E09AULL, 0x897EB9925F4D512AULL, 0x1E8E9463EB73D676ULL, 0x6256EAEC11138C0AULL
        },
        {
            0x96DC3A8575147AFDULL, 0x57DE1FC9F2280794ULL, 0x348FC30FA8B44A61ULL, 0x4F03AF86C8430CFAULL, 
            0x8E561399192BA216ULL, 0xB6E191AF2AC2F419ULL, 0xC8A3C9F233329B07ULL, 0x5EA9CEB56B523EC5ULL, 
            0x5B2142AC054160FDULL, 0x814190B9B7D0A903ULL, 0xDC76499882BE3732ULL, 0x546CD6043145B05CULL, 
            0xACE4A646FC755FC2ULL, 0x2E36C2237E321545ULL, 0xBA65456A11C18DA8ULL, 0xE08D084E82837F6EULL, 
            0x60C81DD444175E1CULL, 0x7BB2AE3D3112B409ULL, 0x60A01CFDBF7739C7ULL, 0xC5271A84EC507CCDULL, 
            0x5B019EEFB914B7D1ULL, 0xC9095DEDDECD7933ULL, 0xA31DCC88A3D8A7F5ULL, 0x994F8580CCCD24EBULL, 
            0xB1F691F94F4F761FULL, 0x77A479F56586E56EULL, 0xA30CF2E2C88F6220ULL, 0xE10A27BC19E7EADBULL, 
            0xEC96C54360139EFAULL, 0x41CCD3FB50EF2331ULL, 0xB34F20567AF7C413ULL, 0x38EF21381C80ADC4ULL
        },
        {
            0xB972832D4D5D0815ULL, 0xAECC2F3890F97103ULL, 0xF1FA8379300DF6BBULL, 0xAE26C7A3869093F4ULL, 
            0x119BDBF46FA346ECULL, 0x54F91C1638FB8841ULL, 0x775C5F50EC68AECCULL, 0xC968DDED39EE9C88ULL, 
            0x042FD730009F2407ULL, 0x2912D6ECDDEB548CULL, 0x7893E28B5B48607CULL, 0x5669E32083C58668ULL, 
            0x95B9E929B8E8177DULL, 0xC8C3B4017AC1A16EULL, 0xD5237E8C9AD4C209ULL, 0x7B1C5ED0C1900FA0ULL, 
            0x7C4382A756372753ULL, 0x58A2414180A81F62ULL, 0xF2AF53DC479A8878ULL, 0xEF3EC929DFB0FF8CULL, 
            0xC8D48F09524348D1ULL, 0xC62848865D88FCC3ULL, 0x322249D0AC712442ULL, 0x6739EDE009CDAE6EULL, 
            0x5630FD05961A1647ULL, 0xDB1302AF8E060FBBULL, 0x56759BBD482B0B0FULL, 0x6B1742281134DD38ULL, 
            0x4A81820BDF136DB9ULL, 0x112F330F72D7488CULL, 0x682869D2D7E54660ULL, 0xDE69598FD947C4D3ULL
        },
        {
            0x5D8DCDF315032B01ULL, 0x9B80A4FE03B33B36ULL, 0x383BFCF8FA5C6C2BULL, 0x8868717936C3103BULL, 
            0xAAF3AEE654189AC6ULL, 0xF250DB95EAF3B711ULL, 0xC071BED5EA6DC6B9ULL, 0x6E5CF7826869C9C0ULL, 
            0xF61709ABB02BB3F5ULL, 0x823DF2A7A3B09EC5ULL, 0x62677E4D0DA824B4ULL, 0xDFFE9B4A43B5F0C3ULL, 
            0x525B47D780103594ULL, 0xFE3ED6B8E1437066ULL, 0x732EF3BAAFCF43C2ULL, 0xAD39B0BA3FCB13E6ULL, 
            0x8ACDA9D5D5D71EA7ULL, 0x8DD31C973F9C67D0ULL, 0x2AC87F6468548C10ULL, 0x018E438089B2F35EULL, 
            0x770D942EA1F5F5A4ULL, 0x78ACAD5026F8AC6DULL, 0x7BD41807E6607137ULL, 0x7B2C04E5885463F4ULL, 
            0x97D07490C428E62BULL, 0xD61B23F3C957A07AULL, 0x36D5BD3A2CC10A17ULL, 0x7160A931A1817789ULL, 
            0x29BEBFFF828DDFD9ULL, 0xEC6EEA7DADB58978ULL, 0xFADA679C44C57C8CULL, 0xF96DEAFFB15140B6ULL
        }
    },
    {
        {
            0xD221E2D39395CEBBULL, 0xD136CF0DF4774D92ULL, 0xA6C4859EFF1CAD7EULL, 0x4B642111DA33BF4CULL, 
            0xDAADE5A96D61DEEAULL, 0x0E35868094B0FCB4ULL, 0x8C611278D713F105ULL, 0xD5E572139BBA3074ULL, 
            0xA93972FE74E5985CULL, 0x6E9ADA23B99EB9D1ULL, 0xFA8210AD5D9D1794ULL, 0x5D0BB390F15191B3ULL, 
            0x8CEBD9E5CFA21AD9ULL, 0xCB5287BB45514922ULL, 0x940F3839E47D302AULL, 0xFF3A4D41BFF1DB2CULL, 
            0x83C20529FCC28711ULL, 0x25EC2DE024160442ULL, 0xBB8A3D9046961736ULL, 0xC83E6ECE9A570828ULL, 
            0xD9319FE35FF62389ULL, 0xB4506DEC4B1C382FULL, 0xBB81BBBE54F1DB9BULL, 0xAD4723395E823F79ULL, 
            0x377EA87D53E4CD32ULL, 0x0278DC25B24ACC31ULL, 0x841B8B30DF72079BULL, 0xA4342A10266ABA0FULL, 
            0xBE81BDB11A07C103ULL, 0xC707DB9D49F341EEULL, 0x586D70EB0225E8A8ULL, 0xF0952019A731C633ULL
        },
        {
            0xCC00B3661024EE7BULL, 0xF505264309980CE2ULL, 0xDF414E1DC0AE0285ULL, 0x209A63A39492871FULL, 
            0xD092B2AD8EFC26D2ULL, 0x5DB535FB27C24DA3ULL, 0x9A711348B1D41A4FULL, 0x51180BC433DBABDBULL, 
            0x7B3D19FF911DD20CULL, 0x34CC3E59DDD1E920ULL, 0x85D31DA89CC6CF52ULL, 0x91F66EBC9230513EULL, 
            0xB125D4C846959ED0ULL, 0x0E3467332EA96C67ULL, 0x538EA9E6099E5D0BULL, 0xE9963340027FF92AULL, 
            0xF62E3EC3B381B3DAULL, 0x00DAE84C0D05CDCEULL, 0xF2DB653B7D777B7BULL, 0x253859BBBD42FB74ULL, 
            0xF27F243B515642DBULL, 0x2C77BC6470EFBC64ULL, 0xF7614DD3F0F9C938ULL, 0x2E51DC5DED677BBBULL, 
            0xEF33627F06925487ULL, 0xC2A92B165FBF88BEULL, 0xD747466CF13BEB38ULL, 0x392F01340E15530BULL, 
            0xBDB4ACA176506D4AULL, 0x1986B5957CD91C3EULL, 0x0ED5291E21857F29ULL, 0xBAEFB36BADD7CCCBULL
        },
        {
            0x3F3053C0AA7C2AFFULL, 0x991D1D43CBEB5F6FULL, 0x38FBE4FA361FC7A1ULL, 0xA4B0B4D58D1FB22CULL, 
            0x58D0692B824DA3C5ULL, 0xB10BF2CD3EBB17ABULL, 0x4FAA5DDE82505A33ULL, 0x1CD27578606D0186ULL, 
            0x31C8F2A62F62E873ULL, 0x90A3F37DCEB45C28ULL, 0xD3280997EB7376C1ULL, 0x594AD4ACE36FA482ULL, 
            0xFFBCE3248C037DB1ULL, 0xF872276F76D0F3A0ULL, 0x9224958AEE30FB13ULL, 0xD49F76A41DC20F78ULL, 
            0xD50BC9006D4E1D25ULL, 0x772E910DB99B5B16ULL, 0x280B980B3155037AULL, 0xC2FA0AB5A6536FF6ULL, 
            0x0AA449FDEA4D636EULL, 0x50F20C80F27F0D44ULL, 0x5CD32C51C4FB5B15ULL, 0xC7E11A0C9585DF82ULL, 
            0x694AF2A15A2F4E30ULL, 0x7A66C753389D5F41ULL, 0xEB95F56452BD723EULL, 0x6EE3CFF8287533CDULL, 
            0x1A6AAA6E4BF411D3ULL, 0x667CDF24120C5F15ULL, 0x7C0A62B2E33F5E21ULL, 0x46D73BA68495909DULL
        },
        {
            0xD1561FD7031EA598ULL, 0xE2897FF31579BB07ULL, 0x48AE1BD234999FA8ULL, 0xB5FDF4BB3FA47B58ULL, 
            0xE60433446E324BA0ULL, 0xE8B788C6F134858EULL, 0x26E1E95FB191EFC8ULL, 0x6B0F7C06BC12BBF8ULL, 
            0x8D26ECCC4FAD2297ULL, 0x6B06B054F252B5AEULL, 0xE434496383774E73ULL, 0xBF56F74D29D50C86ULL, 
            0x7F8BC3146FB34DB4ULL, 0x0AD9B234D5B11CD9ULL, 0xB0EA06D3CBD5FFBEULL, 0xBC15E2C4F15E4D20ULL, 
            0x10F30CB0E815E74AULL, 0x2A8E400FFBAF91A0ULL, 0x3909D3603CC292EAULL, 0x84B7C4EE9DDA6C4CULL, 
            0x44EA11C6EA72E123ULL, 0x609987FDC665F6CFULL, 0xD70D7A7229DC12D7ULL, 0x57614DD692EE0910ULL, 
            0x1A879795C690BD0CULL, 0x87DBADDC9335F178ULL, 0x0864E6194E8E23B8ULL, 0xE1F0512C6081BB7FULL, 
            0x69D3213BF6D07F79ULL, 0xE1C627C4003DEB9EULL, 0xFF561DE759D0675CULL, 0xA28A01B64EE2C26EULL
        },
        {
            0xDD8498E915C32DF7ULL, 0xD0F8CA1A406099B3ULL, 0x1C40AC6A75E44161ULL, 0xD883D8444E11015EULL, 
            0x6654C70DB111716FULL, 0x893EAE9DCEB74356ULL, 0xB75E304DB23DE7C6ULL, 0xA4D997AF5187D538ULL, 
            0xE373D67D88B1FBA2ULL, 0x01108CA081438126ULL, 0x6384DC7F284ADAD9ULL, 0x91600228ECF23F54ULL, 
            0x74A08598CEE101C2ULL, 0xDBE1093A1745C4D6ULL, 0xD40924AB160F6A20ULL, 0x5FBF0C8584EB2CECULL, 
            0x71FEC7E7710B6F0BULL, 0xEBA96B4B43D8585EULL, 0xC50B1EED12D597B6ULL, 0xF29229004E41A4C1ULL, 
            0x5AFF8FAD744BC839ULL, 0xF0648878C957FB8CULL, 0x98389BA2DE7B72EBULL, 0xA230CEF53FBBA08BULL, 
            0xD9A9B46B7321A63EULL, 0x2DCCD679EBC7E387ULL, 0xC6131203D5AA9AEEULL, 0xBA331170F1BE7E0EULL, 
            0xB3B2E3F14AEB8A3FULL, 0xA55AB730BC9149FFULL, 0x5F7296D1CD8BEDEDULL, 0x00519A4BE3AF0104ULL
        },
        {
            0x68A1D5E7B5CF6860ULL, 0x88293A51B43A3B37ULL, 0x356AFD3303DE1511ULL, 0x7DAA77E58F4AFEA0ULL, 
            0x518BCA166EF0D44BULL, 0xE67808EC625C6B32ULL, 0x22AF90D20962B4F0ULL, 0x28E6063DDEA30549ULL, 
            0x826C0E4FB2EC8C38ULL, 0xE076395F43657B98ULL, 0x7304AD96C78A28DCULL, 0x11FEADA0A0F6CA4FULL, 
            0x35698A0E69DC0AF3ULL, 0xA456CC9CC38FBFB3ULL, 0x1E3F45EE05F26D28ULL, 0xC7C7385D6C760B61ULL, 
            0x88E2AD2B1D028937ULL, 0x220F096D77DC4F56ULL, 0xC5B13A55719CF553ULL, 0x8F3F9DCC4EDCDDCEULL, 
            0x2BFEF998E46CD4C0ULL, 0x741B04ED435E0408ULL, 0x9E72F785D5B16B12ULL, 0x80075620F5E1EBDCULL, 
            0xB3C63230831F9CC3ULL, 0x8A8173571440939AULL, 0x969E6FB7CEEE3D49ULL, 0x465919EFA9D1F64BULL, 
            0x1E77B537BDDB7C44ULL, 0x99F5417024B7D96BULL, 0xAA982001CAF2818BULL, 0x819A88D93493832EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseBConstants = {
    0x28CDD735B3E234C2ULL,
    0x326025E771EC1C77ULL,
    0xD201D4F39AEF40A4ULL,
    0x28CDD735B3E234C2ULL,
    0x326025E771EC1C77ULL,
    0xD201D4F39AEF40A4ULL,
    0xC87D0D0B3822B5A3ULL,
    0x43AFB818E2159BD6ULL,
    0xD8,
    0xDE,
    0xA9,
    0xE1,
    0x90,
    0xCB,
    0xFE,
    0x28
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseCSalts = {
    {
        {
            0xCBA6446CE01485B0ULL, 0xF563B9A79F6BE545ULL, 0x0503F73ED3FE070BULL, 0x6DDA3CDEA2DD3413ULL, 
            0xBE796AC889F3DA89ULL, 0x7C6E7AB5CD0DE4F0ULL, 0x78AD162F960573A1ULL, 0xBF78C31247CA3DA0ULL, 
            0xD350C390D19DD9CAULL, 0x00AFD866702AE280ULL, 0x23775D325D26A78EULL, 0x187F580E8D51F622ULL, 
            0xB1F57C7BFE2DC6E4ULL, 0x504E5AE02BB2C50DULL, 0x5F429CD1F5539A50ULL, 0xF9FC83C6ACA0BDD6ULL, 
            0x4259CD57F0F733BBULL, 0x6C29AFFF809B3F7FULL, 0x6A3EA0CEA778FDF3ULL, 0x6DD0A4FC44A9B5C0ULL, 
            0x9CA99804A7C4B761ULL, 0x5295302C91C4CF5EULL, 0xF06584BF9CF9FF40ULL, 0xF5E1E725FC068B48ULL, 
            0x5FDB11F8AA398271ULL, 0x31AEF3F986817ABBULL, 0xC1BF80184D48FD0FULL, 0x74E2D2DA4B856FDCULL, 
            0xA9F5515C35229B86ULL, 0x582773EA234A2A02ULL, 0x0167FD8AA3DB7C72ULL, 0xCBAEE3372EDE939BULL
        },
        {
            0x162153DA9ABB0E1BULL, 0x4224769C7E3390EEULL, 0xDFE4D3F26BCBCF72ULL, 0xBDA576788430970DULL, 
            0xDD0008710878065AULL, 0x20D5884887EB6497ULL, 0xCFEFE45BCF5BCD26ULL, 0xF0BEBAA8A48EEDC3ULL, 
            0xFCD64232BE7626A9ULL, 0x2EBD84A66B72CFB6ULL, 0x55E4980BCCAA866DULL, 0x4AAB0B39B66AC615ULL, 
            0x052C7F44E8C2F149ULL, 0xB356390B13B73DBBULL, 0xBBECA1EBEE7083F4ULL, 0x65A1D80034480EEFULL, 
            0xF2D075542E114F3CULL, 0x8936633174E90260ULL, 0xAFE5C69A15F92A17ULL, 0x9961D3EC167E904CULL, 
            0xB7D28AF98898E1A5ULL, 0xC71ADCE57D7686E8ULL, 0xE2C90C698914F4ABULL, 0x0FF0BA3F1570C029ULL, 
            0xFF64075635D4948CULL, 0xF3F82F1FBC0E81CBULL, 0x54BAB66BB177F687ULL, 0x8B2B754B61A471C4ULL, 
            0x770EB7483B031193ULL, 0xE8E622698E72B3E9ULL, 0x4882387A6724BF47ULL, 0x763E29E3A13B1A5AULL
        },
        {
            0x10E02E96BA93730EULL, 0xAAE30E6B46A19B00ULL, 0xCFEB50E76ADF7FD8ULL, 0x17BDA39E697197C3ULL, 
            0xE3CB46F65F037BD2ULL, 0xA46CC80C8BD79134ULL, 0x44DF9666EC9FBFDDULL, 0x4EB33BCAC86CF734ULL, 
            0x6AF78FB790AEF75BULL, 0x49154EC78F7F2F54ULL, 0x22C501C5AED313B9ULL, 0xAAEC755EE7BFA004ULL, 
            0x841BC380FF47DE22ULL, 0xD7DFC7AD75FEE18CULL, 0xE13A010006872E63ULL, 0xE7B57195521A6A87ULL, 
            0xF11A67B8B981303BULL, 0x971FAD9254F285F1ULL, 0x40C21BD609A9A882ULL, 0x00A84935E400ADB9ULL, 
            0x6CD3765D3BEE8476ULL, 0xF727FA741C57C44DULL, 0x2B14C018FCF00F40ULL, 0xC80F25BCB36B348EULL, 
            0x2E04F832E6B79E30ULL, 0x7A5ED5007A2DB9ABULL, 0x3783E2096FC770BDULL, 0x4E8F2C105A9B02D2ULL, 
            0x6E887DA236179958ULL, 0xE9E7A64C9D51095FULL, 0x17CCC4F0AB91950EULL, 0xE76EE2906E9C20DDULL
        },
        {
            0x12FBE84BCC9480A0ULL, 0x9F60017CA91C83ABULL, 0x1C03095AAC772249ULL, 0x5FB6A5086B79FA5DULL, 
            0x4404027C9567A0D4ULL, 0xBC3EA58472830B73ULL, 0x55CF49C8541C6251ULL, 0x7622C99B5C1CAABFULL, 
            0x6F5D0722322541EDULL, 0x7E477F574479B447ULL, 0xF4B9D8585582C927ULL, 0xCAD87107691E534AULL, 
            0xF1279AD8CF820CBCULL, 0xB2E8147888746381ULL, 0x40ACCBE743C2EBEAULL, 0x80947F60020C3970ULL, 
            0x0F3C896D194C3361ULL, 0x7B41D1B5DDD0E0B0ULL, 0x9763AEA1B442CA1AULL, 0xD805169D0E9D38BFULL, 
            0x689A0EB1E6358C84ULL, 0x97D60B25E830B271ULL, 0x5EC4FA77A77D4B5FULL, 0xFFA3F6CF5FC4FE4BULL, 
            0xFAC27E1929C85748ULL, 0x23AA6FE5CFD303F0ULL, 0x330B5CD35E7B0147ULL, 0x69F95CF4DD60C13EULL, 
            0xE555E6DFA6F3797FULL, 0xFD3274EC46401839ULL, 0x30FE80D036FE0B6CULL, 0x7E3A3E506BA3F5A1ULL
        },
        {
            0x264C240E04177629ULL, 0xC5AA479778D208F2ULL, 0xF195E59F32DEE6FDULL, 0x0633EC897A552AA6ULL, 
            0xC8BB9E526547214EULL, 0x54441FB0DDC13148ULL, 0x96AD21A4958C34C1ULL, 0x07070ACE27A44920ULL, 
            0xD850078F54E6FEE8ULL, 0x2630C7E51FBC3E06ULL, 0xF1E265A49A285D71ULL, 0x784876772A021953ULL, 
            0x2805478CF6E3098AULL, 0x1C52CC1123BE77A8ULL, 0x47087BD8EAE1A75EULL, 0xB030C0DA29B652F6ULL, 
            0x50C7F123D9EEE1E9ULL, 0xCAED5FC687068A41ULL, 0xC4DAB6E99AA7F7E2ULL, 0xCCAC6520D524D275ULL, 
            0x62A582A0EFA34414ULL, 0xB53491970E41329AULL, 0x9015FC5B20D231D1ULL, 0xFA40F148CB4C326FULL, 
            0x5696EEDEC53E660BULL, 0x8EAEE2FCD56D06FAULL, 0x58600C2609C9D283ULL, 0x9FB1F08670F1747DULL, 
            0x81A70B939FA8855BULL, 0x019D00430DDE2B93ULL, 0x3DB2EA9F2CD0B410ULL, 0x9B20F1F3C8867ECBULL
        },
        {
            0x9C75504F025AA333ULL, 0xEC2DACBA4512AE9AULL, 0x27E26518FA0184BDULL, 0xF1859C8628DEFDF8ULL, 
            0x8304BC2F11BAE5C1ULL, 0xF4B6CBD98E63024BULL, 0xCB71F4A896C9750EULL, 0x75DAC39F081CA59CULL, 
            0x2BD4C60FD3AD9A9BULL, 0xDACC47BF806016DEULL, 0x98C94198B6718439ULL, 0xAB817EBA49116884ULL, 
            0xA940DBF0E9FB3C29ULL, 0x8B174B64BCE2F3DAULL, 0xA33F78221974BC15ULL, 0x967BC6DD7E782C36ULL, 
            0x7BB3805FD384017FULL, 0x7AD4E3DCEF3803DBULL, 0x3E18CF83F67FC42AULL, 0x652409C30E07225CULL, 
            0x9892BED06E0CC6EDULL, 0xD657920EDBF08B06ULL, 0x826EA45EDFA3D6E8ULL, 0xCB6A2BE68BCAF5C5ULL, 
            0x5A26D588B84465BAULL, 0xA447619AD2A5B2F5ULL, 0xD3087E8610ECA749ULL, 0xC262A2E0D8676CFFULL, 
            0xA06585C6CB86F169ULL, 0xA630CFBF28F9D9D0ULL, 0x1DF9CBEAD096F141ULL, 0x8AC9187F55B180CAULL
        }
    },
    {
        {
            0x2B84E643B50D0BFBULL, 0xABC568043D32DDF7ULL, 0x7EC6094167C0A0B3ULL, 0xDE18B00C484F94D2ULL, 
            0xDA7D823D5A505B63ULL, 0xC1A2C23C1A0B2071ULL, 0x6510BEF0F34006A9ULL, 0xDA7EC5DE91AB1B2DULL, 
            0x527144D07DA1F6C2ULL, 0xE60452CB26810C54ULL, 0xBA5BC4476F524EC9ULL, 0x6302BA072FE8F10CULL, 
            0xDD33424901DFB3A2ULL, 0x68C7A47A10947A47ULL, 0xA4399B03FD5869A8ULL, 0x7ED6F799567FBABAULL, 
            0x2C8F203E799D8A83ULL, 0x21E116E0D1C68BC8ULL, 0xB96B77F4649DDCA7ULL, 0xB724E69297657A93ULL, 
            0xF850C5DA358779C0ULL, 0xCE4ECCC807F6B7F3ULL, 0x12419CE3F4FBE03DULL, 0xEE46DFBDDFAE01BDULL, 
            0x26EB1224304C9B24ULL, 0x86066BDF51CAC6C6ULL, 0xD0E07CAF4C24402DULL, 0xCCEC3FAB14052FFDULL, 
            0x88E684BDAE92067FULL, 0x1C31FC8A2D534E91ULL, 0x487EC6A7533B79B5ULL, 0x351A48BA14680DBCULL
        },
        {
            0x13F8649799AE4AC2ULL, 0x1981331B4DD5D91EULL, 0x61B7717C3F5E9A08ULL, 0x23DCFBA1D0E668B5ULL, 
            0x7736E8B9115D20C9ULL, 0xFA67410E60E43EE3ULL, 0xEE9715E36FCE88F7ULL, 0xB72D236EAD936DCCULL, 
            0x37796B51AF42A977ULL, 0xDB3C279C69305070ULL, 0xD48DF93AC6238843ULL, 0x01DE3139F84191DBULL, 
            0x28DD68F2FE11AA8DULL, 0x5AC4080FD30FBD20ULL, 0xA941C08B8B72F596ULL, 0x2165F5651078C33CULL, 
            0x78CD5976D790C926ULL, 0x89B5D03AFC838F31ULL, 0x759C93AE76668D9DULL, 0x879A0EF1B0CDD858ULL, 
            0x91CF57E2BACB2A54ULL, 0xB128846E1557446AULL, 0x041C19D2FF9F9EFEULL, 0x50A1CEB874C91720ULL, 
            0x459438927E133DFBULL, 0xEA356AAD1FDD9DB0ULL, 0xC0277AA9F1A32DF0ULL, 0x4C9BBC66A077AA95ULL, 
            0x603B99FD2AAD9E9DULL, 0xC791D1C7869EEAC3ULL, 0x7F2CDEA8C78DB0B8ULL, 0x9088BDCB71BE24BFULL
        },
        {
            0x37683452050F1E7FULL, 0xAC1ABF7AF49B09E7ULL, 0xCEEFACC989622DBCULL, 0xF80B7D7123EC65EDULL, 
            0xFBBF31019808171EULL, 0x0029A23F4CF9CAE7ULL, 0x1CA7E3DBE2D67FDCULL, 0x55BA9AA9B39DF9DEULL, 
            0x02B7B1C964D5000EULL, 0xA4D1ED99BDA27854ULL, 0xBF771AC99071C6BBULL, 0xA09342AAF4162CF7ULL, 
            0xB1974B58804635A9ULL, 0x07EF0BBA4F4A0186ULL, 0x0729B79BCAFCA608ULL, 0x515A222C688B8BDBULL, 
            0xC453EE6B775B9358ULL, 0x43BE51145A487C10ULL, 0x0BD30F029BECA8C5ULL, 0x1CE92DA2CACB9380ULL, 
            0x4EC45A7F0BAA21BEULL, 0xD86262D764EC18A3ULL, 0xF51EAC64E068EB23ULL, 0x35B3F02F9C44EBD8ULL, 
            0x8680287C10962883ULL, 0xF024F01BEB5C63EEULL, 0xE761E25808E9C10CULL, 0xD994CF4197145E9EULL, 
            0xDB5EE488B66014E9ULL, 0xBD163574731D3778ULL, 0x044FF2BE9EF54FE8ULL, 0xB0B927C6168DC791ULL
        },
        {
            0xC0B6C703A8B5EAFEULL, 0x465486C49C8EC419ULL, 0xD11B252596DB3F6AULL, 0xB7E86FB66F7EC3EBULL, 
            0x1CFC1AA33C222229ULL, 0xFDD5A435E058B0FEULL, 0xB81A1BE0A97305C8ULL, 0xB8AA37F25295A68FULL, 
            0x1836B625951B4CAFULL, 0xEF1C4722BA29D101ULL, 0x5CB60495E04788A1ULL, 0x4253EA648C2BC333ULL, 
            0xE3626501EAD12CE1ULL, 0x4FAE1B6D8856A202ULL, 0x5EE9BB4B414307A3ULL, 0x5CDAABEDA86E8C9CULL, 
            0x3C2EA1B16F2E455CULL, 0xE017181D12523873ULL, 0x9BBA6251274B369CULL, 0xD1983F090DEF131BULL, 
            0x754BCF99BC0E022DULL, 0x680B16FF5CFFE99BULL, 0x7AD2C242D91E27F9ULL, 0xD3628C4A2A0B4B17ULL, 
            0x686621000DA61E79ULL, 0x3B6986365A863284ULL, 0xF5E6F0806A0F1A80ULL, 0x2C9D5A465B0F2497ULL, 
            0x1F65D71E2E3B48EDULL, 0xCEFA2583ACC12F4FULL, 0x8268D101A1E88153ULL, 0xBA1A6F6B161FF491ULL
        },
        {
            0xD3A23AFF5E662C3BULL, 0xDDAA95B0E501F7B2ULL, 0xFD030A3D478BF44CULL, 0x9CB197A031FD556CULL, 
            0x10BB4C4A6A2A1C13ULL, 0xDE7B1E89D889F414ULL, 0x257315D4BD2E98FAULL, 0x1C418C4931CAE44AULL, 
            0x21FF6DBE8B1AAB93ULL, 0xA2A3E7E8ED0EFC5BULL, 0x360F221CDFE8BA60ULL, 0xA3928C166BE2D387ULL, 
            0xD3384BA15EACEB5BULL, 0x03F34D95ADD8CF4FULL, 0x569CD3D352ED9F32ULL, 0x09D39030BC21E53EULL, 
            0xDD2FCD6A568C3A06ULL, 0xB8693C925A8F2B5FULL, 0x6EC4D5A504F3C5A0ULL, 0xBC4D69D58B801CDFULL, 
            0xF83B1A0C4746F38AULL, 0x9674D5E466FB886EULL, 0x135DBB86043B23DAULL, 0x990EFC6D0DECB448ULL, 
            0xF195C0697DB1D1AAULL, 0xA4B37A9D6F959774ULL, 0xBE1B40534581FF3AULL, 0x924C413EBF26B53EULL, 
            0xC6D2EA85889C92AEULL, 0x6B67922A5F7F6E80ULL, 0xB57017F85E2B2E86ULL, 0xD0608FB311B24FDFULL
        },
        {
            0x0D8BDDDBE0074577ULL, 0x0B522BF3A8B9497CULL, 0x27225238FA120FE6ULL, 0xAA5EB3F7052E2494ULL, 
            0x4F89EDE75E58D6DCULL, 0x7E70BC959B0D498CULL, 0xAEB3B8F63E6A75C5ULL, 0xDFA5649533F0A8C5ULL, 
            0xE7252872DFAB6898ULL, 0xFA0ABCBF2A8EB365ULL, 0x61D84948F7CB1EB6ULL, 0x057098E0B4D2433FULL, 
            0x07EBBA610EFB6725ULL, 0x730DB1FBA7B3C6FBULL, 0x7782F001275A0B73ULL, 0x79C4AC5A5804C82EULL, 
            0x3000B15490BDF968ULL, 0xD657BC0B8DD80B69ULL, 0xBE40528DD9CF0279ULL, 0x0EF47B78057D1E99ULL, 
            0x4ADCBBC093714CA7ULL, 0x7B0F58E6BD3C3207ULL, 0x5DE7264271286C1AULL, 0xE969706BCEC73191ULL, 
            0x18307C9B2060D458ULL, 0x2B7EDE2E4CEB3368ULL, 0x73934F8B42FA188EULL, 0xFAF78148A0E12BF4ULL, 
            0x0B1FA9AF39E4EA62ULL, 0x46D6B046F1A2863CULL, 0x61642ECB2F9987F2ULL, 0xE3D9EF17B13816B1ULL
        }
    },
    {
        {
            0xE9A3A5037BF227F6ULL, 0x985422CF739B97B9ULL, 0x82ABEFE24FDBA36AULL, 0x85FA7C2A4C838280ULL, 
            0x62C56A12600F088DULL, 0xE1977D71F58FB27AULL, 0xD57C5D46B0E6AD8FULL, 0x30B73BC9473B11C9ULL, 
            0x499BB993D642A117ULL, 0x37B7251DDA372078ULL, 0x0CEA0568B88EE76EULL, 0x5084F0E892C70369ULL, 
            0x64B20004CCE20F0FULL, 0xC98F330064EFC41DULL, 0x863311A80EA7ACA9ULL, 0x8899A6BEE6257FEBULL, 
            0x65CC1DD2F0223760ULL, 0xA846807545BE9709ULL, 0x87FEE1315AA8572CULL, 0xEBA55B74FF2984AAULL, 
            0x89401B689D5CD75BULL, 0xBA9DE1F1D4F9384FULL, 0xD37F4E33D4B73B56ULL, 0x757BD6F12202CAB1ULL, 
            0x55DD00E3F9769003ULL, 0x6301C98328FDF92EULL, 0x12891622084D3584ULL, 0xE1C41255E3AC5149ULL, 
            0x815A331462FDFB83ULL, 0x6559423401FA11CEULL, 0xA573D57FBFDF019CULL, 0x12051A89BD09D9B8ULL
        },
        {
            0xD6C8B2FB146D8308ULL, 0x0EAA1A58506DD2A5ULL, 0xF7FAA7A239E11745ULL, 0xFF0DAE34F33B3753ULL, 
            0xA051E49059C9DB56ULL, 0x5ED85C1E68B18FF8ULL, 0xAC9227CCA8D89D92ULL, 0xAD6F17E077D948F8ULL, 
            0x990A68170D98A12CULL, 0x6E463C52ADA7B3CBULL, 0xC0E3B05B28CA260DULL, 0x63727B9D5F374A9FULL, 
            0xE4A478AE4CCD7799ULL, 0xA463FED82B4123AFULL, 0xEB791E2208D02FE6ULL, 0x793D0D88C0E95BD9ULL, 
            0x001CA7CBA6102E8DULL, 0x99F888B1FADDA0A1ULL, 0x2B51B9D43AFE09DAULL, 0x8C16489A6E028BEDULL, 
            0xC634642E94A3BE39ULL, 0x962CC3D5F631F506ULL, 0x9F03268A5632C424ULL, 0x3B6DC0162864DBFBULL, 
            0x611BAC3C8CF5D9FAULL, 0x8F65464EF76A3FA0ULL, 0xCDE47B620CCDBE5AULL, 0xF8E83D42C003087CULL, 
            0x9B437855572DE9E8ULL, 0xE80170D2A88FD7A4ULL, 0x740D1622DD1C32E1ULL, 0x90EA275939BAD26BULL
        },
        {
            0x0649EE1A959F267DULL, 0xAC5AD103E973B5BFULL, 0x0F76B88923F1AD00ULL, 0x1278CAD6E7EA79D5ULL, 
            0x5915FE80F7D7DFE9ULL, 0x9A8F320F3213D056ULL, 0xF7E40B8666FDA844ULL, 0x81663B09164A737CULL, 
            0x1C338A08793E5555ULL, 0xC759C4F5462894CFULL, 0x18E4E3B504E72FBCULL, 0x6F606878606E0814ULL, 
            0xCFDD0780C2E2CCBEULL, 0x0BB597960793509AULL, 0x827FDF1CF1FA0507ULL, 0xD16B91078A2B0A4DULL, 
            0x00861FCBA5194FB5ULL, 0xEAF89E5804D6DE0EULL, 0x4CB8CB9D0FD8D067ULL, 0x5116FD9114F0CDA6ULL, 
            0x6705DBC8A07C5C65ULL, 0x1091C80F8B935538ULL, 0x29EE5AF8749CF4B6ULL, 0x74FFFFFB6DFAA0E1ULL, 
            0x2D3C9B2F9CDA4848ULL, 0x1684CE5B3EF755B4ULL, 0xC935F0AEDD5AE7D7ULL, 0x6877668647B4D628ULL, 
            0x61F0FC3B4D6718E0ULL, 0x37D213401A151692ULL, 0xB17E194C9D1060B5ULL, 0x1A083A2087118060ULL
        },
        {
            0x4E2B50C7D1131EC3ULL, 0x60B0A2F0CDE2D73DULL, 0xD69CCCFAE08BBB4CULL, 0xBC4D336C27F9F03EULL, 
            0x6994D6296A98085AULL, 0x4B86EAC344DE9063ULL, 0x764CAF9418B1B762ULL, 0xE3915B5799119637ULL, 
            0x558094348F188C5AULL, 0x2D60239B629BDD13ULL, 0x33FAE1EBE3FCBBCAULL, 0x14DBD234DE569EF6ULL, 
            0xD4AC955254EB011BULL, 0x2ABDCCA4F6F99785ULL, 0xD941454578CD92D3ULL, 0x045D361115303C19ULL, 
            0x1D98CE72F0B9550BULL, 0xC18FC984EB774F40ULL, 0xBF3119395072A94DULL, 0x7752C9C525BD62D2ULL, 
            0x9DE17A5EE19C9C32ULL, 0xCFB8E9D6DACE4E96ULL, 0x2E12F090D28F7905ULL, 0xB9523BB14DA4DC07ULL, 
            0x668348DC11EBFD0CULL, 0xEE7C028F0FE17D31ULL, 0x4926C5312D5548F6ULL, 0xA1B2D0765E8385E6ULL, 
            0x8246BBF7C2443B66ULL, 0xC006A3B7FF7B2F2FULL, 0x77099A8556376EF5ULL, 0x8B2906E62565DA02ULL
        },
        {
            0xE17661DF88B675C5ULL, 0xECB71F2A0E233574ULL, 0xD73237C0AC98A909ULL, 0x80B7FBA0E86D73CAULL, 
            0x9FB27ACC8F1C32B9ULL, 0x3BE0AE45D5F7B5DEULL, 0xB4575A35F63BC7E4ULL, 0xDB545422DA3C8C6FULL, 
            0x6958D7D120F835A1ULL, 0x02BC92EADDA6B9D3ULL, 0x612ED011B19AC3BBULL, 0x118553A0642AC6C4ULL, 
            0xDA627CA29F208154ULL, 0x17D5FEB63EEB98ECULL, 0x5C3C97CC7601E117ULL, 0x6342BF61D7D953E8ULL, 
            0x3A420BC804FFACCCULL, 0x3628559C0DFE826DULL, 0x6221B35F58619172ULL, 0x14D34D6F0B267550ULL, 
            0xD7BB23411ECBC1A6ULL, 0xEC6135FFAE1B2FBCULL, 0x4B8722BEDA4D18C2ULL, 0x10AA1804A1E527C1ULL, 
            0xABB2B910AB29ADD8ULL, 0x258013DD67C01705ULL, 0x14E6A1A1AAA699B8ULL, 0x1D28AC86390892F9ULL, 
            0x6A572EEE7B52B85DULL, 0x07CAC41AA96B2949ULL, 0x5A88DE7CAC840DF9ULL, 0x05617B4B74B030DBULL
        },
        {
            0x6D1A249A3A462B30ULL, 0x3F724505A9138209ULL, 0x2439BB4EF89EAEC1ULL, 0xF109DBFFF59AEAACULL, 
            0x96C16526DC3EA9BCULL, 0xAA526B30DA1A9E13ULL, 0xE950756973CAC9B6ULL, 0x7FE4ED91DD205C0DULL, 
            0xFB4844A696FF7FDEULL, 0x456E48CBA3781C45ULL, 0x18313BAD53A1EB81ULL, 0xD60963BC7B6E12B2ULL, 
            0xBBC4FF49110F3126ULL, 0xF5A9546A70A3AAADULL, 0x72493B5C2D976614ULL, 0xE0E63EF83FAA807DULL, 
            0xAD06017958D96EA4ULL, 0xBBB3D692B7855FDAULL, 0x431426697F891D4DULL, 0x1664A24D05598EBDULL, 
            0x468A7345FD69147FULL, 0x671B3DFF21F38CA3ULL, 0x3AD2E81F86062CFFULL, 0xF542DFB021BAD304ULL, 
            0x3AA5DAA7B283AB58ULL, 0xA9A855F5438057CDULL, 0xA6A9BA2E47464B5FULL, 0x7F661145CD93BB4EULL, 
            0x6BB4D5A6DB81D5C3ULL, 0x55FECB7C9269AC1EULL, 0xAA0EEAC8694E79CDULL, 0x4DEF4C1B28494F5EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseCConstants = {
    0xA300F3B427D20B8BULL,
    0x5F29005883503F63ULL,
    0x1A4439B02F209774ULL,
    0xA300F3B427D20B8BULL,
    0x5F29005883503F63ULL,
    0x1A4439B02F209774ULL,
    0x8AF1860A83F49737ULL,
    0x32BB45F028B07151ULL,
    0xBC,
    0x7B,
    0xAD,
    0x87,
    0x18,
    0x3D,
    0x38,
    0x0D
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseDSalts = {
    {
        {
            0xC59A818FA48BB5FFULL, 0x80758DA8A69AC8A7ULL, 0x82476C596CD5497EULL, 0x7A61FDD168232AF6ULL, 
            0xA2A29A3009F760E3ULL, 0xB500B399E8961013ULL, 0x4CE43AAB98CE2822ULL, 0x76C2A90F7BAA509AULL, 
            0x93EE1026665DA773ULL, 0x9A85D1AD3597509CULL, 0x22F8505DFA8EBE23ULL, 0xA66AD073FF0D001EULL, 
            0x7F901CA63D106DDAULL, 0x35960DBC8F8105BCULL, 0xB7352F72126980BCULL, 0x280C1DBC4C7C8CCEULL, 
            0x413A146870942458ULL, 0x48EFB3A2D136362AULL, 0xA4BAB513BE6FD3E2ULL, 0x1DE12562F7C477F1ULL, 
            0x83F451CA4A5639BCULL, 0x467854AD9F71C16AULL, 0x00B07D9B4C99593EULL, 0x4F3CCA932796D4D4ULL, 
            0xB57C161D717561F0ULL, 0x0E7741142D09D0A9ULL, 0x780F70B8B3387E6CULL, 0x5C0D8939352C5A71ULL, 
            0x687D792E4E47CDD0ULL, 0xC776B4A9DDCB46E6ULL, 0x871C6D435C670C79ULL, 0xACBB054C269E7185ULL
        },
        {
            0x9060649FAD629015ULL, 0xC323AD5C76F3A1D9ULL, 0x6F1D10F297FBFAD6ULL, 0x1DF09EEFB4DCC7E7ULL, 
            0x1323B615D3137AB6ULL, 0x35C81B355489E5A0ULL, 0x539BFB653FD89793ULL, 0x031193A6EBFC8B6AULL, 
            0xBA7AEB2DCD4E28CFULL, 0xDCA44B80FEF2889CULL, 0x2EC0939D713B8F0DULL, 0xABAE4F0172D6D55AULL, 
            0xDA6397C566E8ED63ULL, 0xEA29879885B439F3ULL, 0xBA1D23FEA54C05CCULL, 0x18C0B97BFB7BE1A9ULL, 
            0x8A74ED76C46C3F2CULL, 0xC913CC926AEF03D7ULL, 0xF7F54D8416F93245ULL, 0xE5A2B55FBB80A04EULL, 
            0x7122AC07381C7084ULL, 0xDA4C9709CBB1F6EBULL, 0xE260923539A756C3ULL, 0x77670887B1CFA87AULL, 
            0x010834299550B0C9ULL, 0x177AB9C39A66D145ULL, 0x19C6EC7C59CB37A7ULL, 0x0A01140E9481E656ULL, 
            0x376F9C328AD85407ULL, 0x5B56BF5F775C05F1ULL, 0xFBCBD2C8499F5ACAULL, 0xE4C255DB1057AF76ULL
        },
        {
            0xCFFCB2EEE08D39EFULL, 0x741A8FCE52FE75DDULL, 0xECE9957316037447ULL, 0x26ADAF5A50321334ULL, 
            0x50ED45DEE478C6CBULL, 0x1F3F5B949AC6CBE0ULL, 0xD8DFCF7CB6E932ABULL, 0xE242A6530F81129AULL, 
            0x988AC8BF74F04BC6ULL, 0xDC760CB2FCB87F00ULL, 0xA5E33194580A25C5ULL, 0x73AA84A9997CE136ULL, 
            0x329A0C68E10D7554ULL, 0x8FCCFDCDD237B586ULL, 0x01341D7694D90E16ULL, 0x8C9E2F8FD9B234B4ULL, 
            0x4EA9D385C1504A8BULL, 0xD6986E3B3925A635ULL, 0x1D6E753F787B092FULL, 0x3E16B2AA24733FE4ULL, 
            0x2145C4E06F7F8CE5ULL, 0x2EF8371F2C562D07ULL, 0x022C6312F6D425C5ULL, 0xD6885421457B9F05ULL, 
            0xC03CBA731DCD6018ULL, 0x6246889DE1182A94ULL, 0x2A1ADA71F1A1222EULL, 0x6E102470819D8063ULL, 
            0xCA7A14C083189329ULL, 0xEA67728365DE7CB5ULL, 0x95225D644862C989ULL, 0xA608705B09DE6142ULL
        },
        {
            0x1A4D5732E26E162DULL, 0xC821042CAF5C1A49ULL, 0xA503C6C4D46A6D0BULL, 0x7A850475173C272AULL, 
            0x2544B996DD8C1A12ULL, 0x66DBA5C246C9E678ULL, 0x2750F4AFC6F904C8ULL, 0xC100AD779F5545D8ULL, 
            0xDB2D04062D7B83D9ULL, 0x608982FB91D59618ULL, 0x2E0853DE482CB4AAULL, 0xA5A2EFDD5FF993A5ULL, 
            0xBBCF9422BA75F253ULL, 0xF86C212E12F21EF6ULL, 0x5F7D6F60870C806BULL, 0x41C71E1BF1417C55ULL, 
            0xA30B15662838BD2EULL, 0x61128374B62CE163ULL, 0x6CA677BECB940407ULL, 0xC816766D0A542387ULL, 
            0x24FD2C9117A5B4C1ULL, 0x7DBDAF936B7C423CULL, 0xA0392795EAD394D5ULL, 0xF00858FD7D3D4FE5ULL, 
            0x2D9AE1AEFE803459ULL, 0x8B8E3018324F9324ULL, 0xB7B5D99534CB32CFULL, 0xC33739EB3191BFF0ULL, 
            0x16D6D2A36847A0AEULL, 0xD5F1BCBDC01D23E5ULL, 0x0F416330CD974137ULL, 0x73A1B13B24D90599ULL
        },
        {
            0xC3726871E7E68683ULL, 0xB0A8B95C3B50084BULL, 0x13269F605FFD6139ULL, 0x26740896C888C8C8ULL, 
            0x404FEF4775025119ULL, 0x9E7E08E6CA943706ULL, 0x2DCFF8183D277A24ULL, 0xC5B74FBF1D21FE4DULL, 
            0x3577C178054B123BULL, 0xEBC34AA017B04296ULL, 0x27D00AC6D1DE184CULL, 0x51F77FF1D486B971ULL, 
            0xCF037C4DD26B4B64ULL, 0xCDE4864049A90D64ULL, 0xE8FB66F231B6358BULL, 0x3DF1490F9A33E8A9ULL, 
            0x7DDAA740281D9A4CULL, 0xADB4D60FA1589B14ULL, 0xC83A5B09B7784195ULL, 0xF5FCFE1B82ED633FULL, 
            0xFBBB7B044245B117ULL, 0x2CE9187AE472D5EBULL, 0x4A74240A3D6066B6ULL, 0x1CC737D7591454F3ULL, 
            0xD01658F77C3CFD89ULL, 0x9466EE203D729329ULL, 0xA5B6719A2ADA453EULL, 0x92A3CC56336D238DULL, 
            0xF443A56DDBC452D1ULL, 0x1AEFD77D54266214ULL, 0x93089885AC0BDC26ULL, 0x3BABD31F078B2770ULL
        },
        {
            0xFA5E3F27148FC0C0ULL, 0xA8B152FCD7430B3FULL, 0x3B045A9B1DD4F6E2ULL, 0x34FBDDF7E8D37568ULL, 
            0xF17217B98694DE7BULL, 0xD90CF28D795BCACBULL, 0xDBBE89775E365ED8ULL, 0x2D9AE27DDC174D39ULL, 
            0x00CD42FA62C3888DULL, 0xD0372435E56380EDULL, 0xF7F806A57925D989ULL, 0x274AC928CC8BBD6FULL, 
            0xD8A4DCE74B2E3E9DULL, 0x439155AB0D8262EAULL, 0x4381755CB1D901A1ULL, 0xD242795DA2C0F91DULL, 
            0x6B829E2AD4A099AAULL, 0xB75CFE2112AC1055ULL, 0xABEF31BA1A5F2191ULL, 0x38FAE83F63D6A04DULL, 
            0xA3F2CCDC846254D3ULL, 0x006229279DC23E7FULL, 0x2C4AA10B900A59A4ULL, 0x27DC1540D42B1D22ULL, 
            0xAD92F860F904AD43ULL, 0x533B65E9E4101C50ULL, 0xFB58EA226DDD8F65ULL, 0x345C50E37BD9D354ULL, 
            0x57EE22D4B376678AULL, 0x5C33FE49CFB17A31ULL, 0xB4456CFD6CB4A20FULL, 0x88AB7B6D3597A31FULL
        }
    },
    {
        {
            0x4D382E28973FCEF7ULL, 0x139F14FC1A8FF144ULL, 0x75C82D74DAC4ECEEULL, 0x058DDDCBEDF9A58AULL, 
            0xBF32476100F0FDA9ULL, 0x654E33125A1A0689ULL, 0x082546FD1B3F232BULL, 0xC391DD2891CA1EC8ULL, 
            0x3AD213639C9F9345ULL, 0xBAC4DC3468248EAFULL, 0x812011AE53567FF1ULL, 0x88C7B27F0E150E60ULL, 
            0xE841BB27904B618FULL, 0xC5222378F58EEDEEULL, 0xB62D6CA2237ECCADULL, 0x776183113AB3C388ULL, 
            0x35219431EB6BEA74ULL, 0xD7BF00996A12B66CULL, 0x2ECB24058CAB7F15ULL, 0xDEB56614704D2128ULL, 
            0xCC706FA400ECAE2BULL, 0x134158FC1AEA8FC6ULL, 0xFC93D8F1F370AB26ULL, 0x6F32EB7A59C6FA57ULL, 
            0x921D7141A6E1B95FULL, 0xC4922C2BAC923A22ULL, 0x57140BE4ED7844CDULL, 0x7B84B286C901CBFFULL, 
            0xCB8518F7A1CFF230ULL, 0x7A53328335D2994AULL, 0x6773C0530C942615ULL, 0x28F1F5D3D2DB0B7FULL
        },
        {
            0x5DAF12C531EB1BF7ULL, 0x68D82733FD5F1F3FULL, 0x5D7EEB825ED984FFULL, 0x36C16BFE4CECCB99ULL, 
            0x9850C46576C16381ULL, 0xEFAD4BFBF6F50150ULL, 0xD1918937FEA82963ULL, 0xDE1119B65933924EULL, 
            0xFE169A24927EA490ULL, 0xA5FA18748B9F9F94ULL, 0xA819FC7E5F026077ULL, 0x0DB806E03EB3747AULL, 
            0xF5BD8A631C0E60D7ULL, 0x6672E5C334843524ULL, 0xEBE60B8DF78A54DFULL, 0xA3F4B68CEBC51A11ULL, 
            0xF9170B8488F59ECFULL, 0x2755277C98296976ULL, 0xFA85F6BADA241C02ULL, 0x48AF82E722BD833AULL, 
            0xE66A77EFBD04ED1CULL, 0x27A1E64A62A9D2A4ULL, 0xA2E7E1BB533BBC36ULL, 0x775133459AB91823ULL, 
            0xAADD965E1CD86B0DULL, 0x2753B828A0BED110ULL, 0xC43D999D52D6C6FBULL, 0x577261E559FC76CEULL, 
            0x93104DF5FC0EBDB8ULL, 0x020354365F43062FULL, 0x9EAAF859A23D616BULL, 0x1776CA20E367038BULL
        },
        {
            0x7EC63EB0C2A062CDULL, 0x3AF4F378E7E80460ULL, 0x644962ACD5DCAA21ULL, 0xA16A3427820E77FDULL, 
            0x911FBB384748DFC5ULL, 0xA2DD4F3131F583BFULL, 0x11C203542EF3144FULL, 0xF99FB38A2D345AF8ULL, 
            0x681367957841C054ULL, 0xEF0F7ED645FFAC64ULL, 0x3544D73C87B37AFBULL, 0x492AD3F66FDAAB0DULL, 
            0x1B95C723A5A0C8BFULL, 0xF66E6E11F0FDEA75ULL, 0x155E109D84DB1DD5ULL, 0x967E58D315AE6695ULL, 
            0x63154554056F7843ULL, 0xEF825A6A678E9665ULL, 0x27ABCD7B0EB5BC1FULL, 0xA0791673F1A31F36ULL, 
            0x19C543FDC6ACCB31ULL, 0xA2F62CFC54C95883ULL, 0x48CABEE672F52E64ULL, 0x39784E7E85A2491DULL, 
            0xC4A4B7C7BEE9785DULL, 0x0FAC31E21D403209ULL, 0x715892BCC390112CULL, 0xBA7B996A71A18AFAULL, 
            0xEA9DF23B53B7B305ULL, 0x3992CDC36E387EFEULL, 0x7CDA777506B814D2ULL, 0x7CF2E962F3C734CEULL
        },
        {
            0x2745E8B8A239A058ULL, 0x7585FBB5846B4CCBULL, 0x7B04ACEA1C542176ULL, 0x64110903849BFB18ULL, 
            0xBCCECEC83C19891DULL, 0x3945B2A719056226ULL, 0x9531934BAC3C09A4ULL, 0xFADD1267CD4F9DAFULL, 
            0x393F42FF3F91C782ULL, 0xBA215AD770137A58ULL, 0x58C76127DF69FF34ULL, 0xE5DABDE758FA4F19ULL, 
            0x05E7D2E891989875ULL, 0x46AFF7A7B1DC95F3ULL, 0xD23D65851FA1BE10ULL, 0xCE3BE3BCBE826187ULL, 
            0x2326F8D58476227CULL, 0x424C40CF2E785AE8ULL, 0x0801397DEACD5D9DULL, 0xBFA2AA175D1F0D3CULL, 
            0x2594397536D5B7A4ULL, 0xB5D93240B632E756ULL, 0xF00E374ED94D91D1ULL, 0x8C2F7DDB4D132680ULL, 
            0xC93C8A49AA0B1A5FULL, 0x91DB66AABAFE5675ULL, 0x9A75B5CFBFE2D68AULL, 0x4133203A72B9650BULL, 
            0xD2BB02CD723B22EAULL, 0x3C45869BE63F2298ULL, 0xAA6B2632D143ED72ULL, 0xE60B2FDF2CAB9031ULL
        },
        {
            0x5E632E1F644F3394ULL, 0x35A7D1DAA75D602DULL, 0x00324464280C9CE4ULL, 0x5201DC4281EE3EA3ULL, 
            0x5E45EA722C3A367FULL, 0xD121680869342992ULL, 0x90E032834620CBF2ULL, 0x421D809725A36640ULL, 
            0xADEF549116AA1AA6ULL, 0x56605BB6DADFF064ULL, 0x7647CDB34117B5EAULL, 0x242425613E0FD9ECULL, 
            0x6FA2FBF2B9D80494ULL, 0xC9F7EA6A45DE6189ULL, 0x7EDA73F95BE9A5FBULL, 0x83D4E40509458CBDULL, 
            0xE2BC4AA9DF2463CFULL, 0x9F652A34994414A9ULL, 0xAFF06501DEC8410EULL, 0x2AF0A56801379298ULL, 
            0x41BF6ECF24475F61ULL, 0xD114962FF5177A7BULL, 0x8A9667255544ED6FULL, 0x4325F02FCC2E7184ULL, 
            0x8E4EAD4E9B63643BULL, 0xE1499A1E08B930B2ULL, 0x870734A6EF01D2B0ULL, 0x56CC483721A2C873ULL, 
            0xD22B9507E4F98207ULL, 0x0EBAE19E1BA831BEULL, 0xD0D7EE98AAEAF1FEULL, 0xB322764660B1C8F0ULL
        },
        {
            0x4CA732981E846A72ULL, 0x37EB4898E35A2AB7ULL, 0xCB09CD7C2A466194ULL, 0xF6C946EEA7971B71ULL, 
            0xAEA685CA59A295DAULL, 0xBEDF461938A9DA91ULL, 0xBE1393B7188B8F87ULL, 0x630208F1273910F9ULL, 
            0xF7B818C3D07ABC6FULL, 0x6AF2BECFBEC98A1CULL, 0xA2E204BE0C452D05ULL, 0xC5DB857C71AE23EAULL, 
            0x240EB95109909A00ULL, 0xE9DC15AB224952FFULL, 0xF18D3FA0E21ACD8EULL, 0xBA525E6F0F8E5D4CULL, 
            0x1E957F526F594E58ULL, 0x079B5F43F7F53C02ULL, 0x16D34D162F395DC7ULL, 0xA451CA8590A2C79DULL, 
            0xFE30788E32D9F1AEULL, 0x2BEEB507056E3722ULL, 0x26538D5F684DFE5CULL, 0xA6B08F57BB366406ULL, 
            0x31CF742C85C8885FULL, 0xF53892B472B7957AULL, 0x6A4C8E500FF20169ULL, 0x77ADC75A6E9DB9AAULL, 
            0x89C706374AD2B296ULL, 0x67FC27E0C05FE7EFULL, 0x58A654200ACBB1E7ULL, 0x266E2AE67C489A82ULL
        }
    },
    {
        {
            0x039B4FBB6808610CULL, 0x6D4D462D28CBA189ULL, 0x842FF80A7840DAA7ULL, 0x913EF6186DA12B31ULL, 
            0x2FB1CF4D0744278AULL, 0xCC0226F5C568CB79ULL, 0x6397A852F6A43E46ULL, 0x37BBA552A277869AULL, 
            0xF7F5DB6E7BE29D9EULL, 0x32F6C8E03615CA74ULL, 0xFE4364EEBBA24717ULL, 0xC32643B342526B38ULL, 
            0x0A25D1711BD93AE9ULL, 0xFF5D26AE079CE606ULL, 0x860CD523F01A59CAULL, 0x0BBACF85E04C3D7FULL, 
            0x4E56BFD53692FE04ULL, 0x50A219BE03C23054ULL, 0x6B369AD357A9D8B5ULL, 0x1056E864F036C771ULL, 
            0x6A9B2D726C3B06EFULL, 0x46C8ED9D098F366EULL, 0x00BBCC0F5C0BD52EULL, 0xF17C7F49E4B56F00ULL, 
            0x6373110173F675BDULL, 0xB99F3D6A499CF76FULL, 0x3B96DF860E5F3B2FULL, 0xB2DAD269B051582CULL, 
            0xEC2A96DEEAF5C039ULL, 0x10FE9FFA23C881B6ULL, 0xA704E3E0A1A4566AULL, 0x272AABE9B7F9CFFEULL
        },
        {
            0x215B40C6E29D0193ULL, 0x86836627DDA84D20ULL, 0xC409EA1D3C7DD72DULL, 0x9AF9212626461C28ULL, 
            0xDB63FE1E7B35ACA7ULL, 0xCF8BAD13F6D8C4C2ULL, 0xD0B6255809D426FDULL, 0x0A4321F8A6FD335AULL, 
            0xCF2D8108EC884A69ULL, 0xE5DF30B78AE64643ULL, 0xD7684E46F6449BA9ULL, 0x3A889DA02A848860ULL, 
            0x84654C4E9DD9692FULL, 0x063BD914789E8FE4ULL, 0x341F1486BC60B943ULL, 0xF15A1B34EF9F4A8CULL, 
            0xE8538A37A2F3265BULL, 0x5875BEACE7C5C9E9ULL, 0x405087F6663F567CULL, 0x4CC3759B663E44ABULL, 
            0xB6D9C25216EE645DULL, 0xBC6EF62005D7B941ULL, 0x486FE9D461744AD6ULL, 0x70C5A57293205B60ULL, 
            0x67E2E2772B5FE217ULL, 0x90CA9A8938DBDFBFULL, 0x0A61D4F1C4210F97ULL, 0x90A91BBEA7891039ULL, 
            0x64CE6CBE66DB2C56ULL, 0x2934C261530F5CE5ULL, 0x736114471A298A3EULL, 0x92F6CF8214A89381ULL
        },
        {
            0xB84E3D998EAE1107ULL, 0xDF5367E550E027EAULL, 0x62E18613EE37B85AULL, 0x45CF39FE5661A84EULL, 
            0x0CF63E2BAA62966DULL, 0x0879F06DAA7CE06AULL, 0x15AD756687977B9BULL, 0x7E0EBE735262070EULL, 
            0xE900F618D66C206EULL, 0xB7DFDB39AE87E74CULL, 0xA2ECAACCE1ED2D58ULL, 0xFA109E9597111E1AULL, 
            0x9194E1943171C368ULL, 0x047D1E44E99ADA33ULL, 0xE466325505AC450EULL, 0xE353982CEB81D736ULL, 
            0x036CDF4743F3EA14ULL, 0xEFE27857D37CE0D1ULL, 0x488354A64183B235ULL, 0x4CB52F2663148246ULL, 
            0x91A8D575C9E0B326ULL, 0x7132DC41250E1B66ULL, 0x62AD40DE37512FD1ULL, 0x554CCA1841FE1231ULL, 
            0xBAD84B3860E2D421ULL, 0x575FF3A3A310BF30ULL, 0x64AF0AEC889478B9ULL, 0xBE8CA6D92AE6871BULL, 
            0x37AEFAD32FFDE85EULL, 0xD57F8CF3435ED53BULL, 0x5CED5E4C5F8FD4F3ULL, 0x023DF65C9E337A87ULL
        },
        {
            0x6AAAFD324BDF4A32ULL, 0xEEA6CBD4405B7082ULL, 0x290F3ACA88996FE0ULL, 0xF67BD7B959BF38D2ULL, 
            0x5C3E4FF061756864ULL, 0xC27EBB7233EA87BFULL, 0x332BFEF0623AD940ULL, 0xD5FE90F4D43E288FULL, 
            0xA2768672DDA3A2EEULL, 0xC67E874A4EE43D13ULL, 0x7115B343201D3F3BULL, 0xE382E6593AA5BE84ULL, 
            0xA13BD4EC1C0664CEULL, 0xB74CB15446D141B7ULL, 0x4EAA93DCED211710ULL, 0xECBE0239B441E143ULL, 
            0x05F2C1EFB0CB7509ULL, 0xF3FAB452372D4DFFULL, 0x5656D788E619E706ULL, 0xF791282434908C87ULL, 
            0x10D9277AD060AD78ULL, 0xEDF3FEE8A61C8A6EULL, 0xF0ABCCC1AF5A98A2ULL, 0xB20C30C07A62AC9EULL, 
            0xC1834D018F88A94AULL, 0xE830B5CDDA04AF23ULL, 0xD52A4BE10A608C6DULL, 0x8CF46F945BEA8715ULL, 
            0x5E1B177A4AD495D2ULL, 0x92547DFE0F9BCDA1ULL, 0x72A4E918B54B7B88ULL, 0x4A223AF4636E8EEFULL
        },
        {
            0x739A0868A4770A04ULL, 0xBA3950F7A4EBA160ULL, 0x17CEF16ECC007F73ULL, 0xB58B217E33D3B343ULL, 
            0x3083139153B83B1BULL, 0x4E502F924690DB64ULL, 0x9A63883C2E6E6D2BULL, 0xC7C7B6F56E34FF27ULL, 
            0x8D4464E0E6CF1399ULL, 0x0A43B371319B76ECULL, 0x6A431017327B8352ULL, 0xE5777A7192E93824ULL, 
            0x0DCF484E238E3674ULL, 0x979EE370B2BC0FB5ULL, 0x37A5E0546A5BA5FAULL, 0xA29B30A38C0D5E2AULL, 
            0x283C8468959369B9ULL, 0xD4E46A1CDEBBD9C9ULL, 0x0158F68D7FF4EE6BULL, 0xB9AC1C24AB49A50BULL, 
            0x54A7124FFA8ED816ULL, 0xFD3610B03F0E6099ULL, 0x1D49AD2DB047D021ULL, 0x7D67B6910E43BBC8ULL, 
            0x4952A2C5107BF5C5ULL, 0xEA72CB2401DEB776ULL, 0x9CDBA934AE1E662FULL, 0x38275B565F4F17F1ULL, 
            0xFBC336799D270AC9ULL, 0xC18AEE33540D18C8ULL, 0xEE1CED7AD2B0EB25ULL, 0x5CB3CD00E273C971ULL
        },
        {
            0xEA241A21984682C6ULL, 0x899BAD032E0C43CCULL, 0xDD6EF9CBE3E8E820ULL, 0x099E0D4298FC99A4ULL, 
            0xA38B5B21148D1C90ULL, 0xAE1A35298B99178EULL, 0xC970D5BC4566AFC6ULL, 0xA3F7D5AA3E270BEFULL, 
            0x917794067D7331ADULL, 0xFF535B975AF7AD38ULL, 0x0E5A3BF25044CD30ULL, 0x38AE5943E3BFB97BULL, 
            0x18583C6AF9B6E645ULL, 0xA4A2A8DF191059C4ULL, 0x91A3F4EFB8C8A4D8ULL, 0x9F6023FB570598CEULL, 
            0x92A47650141849A7ULL, 0xC278119BB0E96D73ULL, 0x9AEBEBFBB5FF06EFULL, 0x6E1760169A794933ULL, 
            0x7C844420DDD9E678ULL, 0xC6C1B4EF40EE46F0ULL, 0x0261577784E70EB9ULL, 0xB3BAD3885EEED0FAULL, 
            0x328CA6590A898F6FULL, 0x94CF60BD20DBC32EULL, 0xAB4FA3A95FFE6F08ULL, 0x65D265526233DEB4ULL, 
            0xD727B5DDEBF4F122ULL, 0x556F10A5F681B4C4ULL, 0xCB4C9EC3C5ECB228ULL, 0x373A7279C8AF32E3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseDConstants = {
    0x50160AFD3FFF4782ULL,
    0x7907C34D9C112786ULL,
    0xD7855BD208612861ULL,
    0x50160AFD3FFF4782ULL,
    0x7907C34D9C112786ULL,
    0xD7855BD208612861ULL,
    0xB1F06D08A7A3C470ULL,
    0xE39ED016011A2CDDULL,
    0xB8,
    0xE5,
    0xA8,
    0x5C,
    0xE5,
    0x01,
    0x88,
    0x39
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseESalts = {
    {
        {
            0x92B1DEB1F90268EAULL, 0x6FD188B661A4E731ULL, 0xF3DB78A724DB1316ULL, 0x53D798D254230481ULL, 
            0x11F2CF07A2F2BF59ULL, 0xF75022960D699847ULL, 0xC7B1E882F4CAF277ULL, 0xCB0EF6B367C29C48ULL, 
            0x03FAB29E12085A2DULL, 0x7F102C223BEABA92ULL, 0xC5D9CEF5A8852A96ULL, 0xDF0A064C54118516ULL, 
            0x23746E5650D69339ULL, 0xE7F5884B320E5511ULL, 0x9A34B8FDFF0C64D7ULL, 0x0360B9957EED6831ULL, 
            0x0215251C5DE802D3ULL, 0xA588D3AD5D1CD4A2ULL, 0x83F8BC8E662F7E66ULL, 0xF002A0E3AB5A4A92ULL, 
            0x5065BC4F6C7A757BULL, 0x7ED8983C1EC78F8EULL, 0x072302AFEF5A1B3EULL, 0xD1AFFC4F68EA840AULL, 
            0x8A4FD0D61469D708ULL, 0xAA8868A54A70E177ULL, 0x996DBB066D13F11DULL, 0x023DBCE86BA2E557ULL, 
            0xB139CBEF750804D0ULL, 0xDD9A43D87EB12FE9ULL, 0xBD6878CBF78410DAULL, 0xD3AEE39382880BA8ULL
        },
        {
            0xF8D1C541181FD2E6ULL, 0x749B3B5666D3E405ULL, 0x6AD04E32C6BF83F2ULL, 0xBC435228F160869DULL, 
            0xECDF4372A1DDA53DULL, 0x86872396ACA11722ULL, 0x82A7E06CC903AC83ULL, 0x7F955C06D1BFD967ULL, 
            0xAF32D5C4CEB88987ULL, 0x726B2CC69A9FFA76ULL, 0xA0A39D4B79258D99ULL, 0x7A454AF729404896ULL, 
            0xA826BF1C22045919ULL, 0xCB04F16054516060ULL, 0xD060E86AB5B66960ULL, 0x94CCDFFE9A7E3488ULL, 
            0x74D1D5CEC124D193ULL, 0x4064E44870BCC4CBULL, 0x7C076D81EB2DEA8DULL, 0x1098863839A9F9E7ULL, 
            0xBB02A974F9FD24B5ULL, 0xE309048ECBD7D865ULL, 0x91553262CC2157A4ULL, 0x8F929021A8C3DE0AULL, 
            0x3584422E9BED4750ULL, 0x814168276BE5DD73ULL, 0x45972E849E4D9B6DULL, 0x3360893B0A4989C1ULL, 
            0x1A6A5A1722AA4E04ULL, 0xDC7687465C2792EFULL, 0x7659E7F8F2B1DB2BULL, 0xDB0A1D51D02CC25DULL
        },
        {
            0x451106E2F4BCAB5BULL, 0xBD6D1BA6DB394286ULL, 0x5D77B1CC305E74EAULL, 0x56F88CF5EABC28F3ULL, 
            0xD53560EADD75A214ULL, 0xAC9523ECA50F283AULL, 0x3D0EA33F45C9CF77ULL, 0x5435154BC1B03096ULL, 
            0xDB6AE744BF80D539ULL, 0x3B66797202CF4111ULL, 0x49DAD81AA2C00935ULL, 0x7BEAB286F6C2CF0CULL, 
            0xB2CE148EE6F60ED4ULL, 0xF383B2E65754D043ULL, 0x4FAB41995AB60AC9ULL, 0x2D5874A788387E55ULL, 
            0xC6115AC929FA577FULL, 0x970E62D620EDC495ULL, 0x7D4D5542E91B9BABULL, 0x21FF1B6866415A29ULL, 
            0xC487278FB71C62CCULL, 0x69CE28EBF767AA75ULL, 0x8F83297175523C3FULL, 0xF5119F766A6CCB9EULL, 
            0xB042EFDF01AA0A85ULL, 0x773610ED9756CC70ULL, 0x28021285235CA4F5ULL, 0xC711A8166532350AULL, 
            0x6D8114898C910DD1ULL, 0xAAD85506537B6FC5ULL, 0xA85C230EDE49890BULL, 0x560EDAA11339A149ULL
        },
        {
            0xD13C030A6F1D333AULL, 0x89623845A032876AULL, 0x79F191015F7D2A65ULL, 0x22073F14432FF1E5ULL, 
            0x3D0AFD1A1187BEB7ULL, 0x5CF3B8098B52FA9BULL, 0xBB1733042F3E2F79ULL, 0xF84D77338CA13208ULL, 
            0x81F33028F8DA17EAULL, 0x77ABB692FF07519CULL, 0xDD04EB3AFC7D17CEULL, 0x298E3FDCAE658164ULL, 
            0xC4C882C1C98E892CULL, 0x774E76F3A97060D1ULL, 0xE4C32FEE591569CAULL, 0x246BB3022A856A67ULL, 
            0xDE7E663C8D9F08E7ULL, 0x9E82469290E83B97ULL, 0x7A2F838A92C2859EULL, 0xE1C94650EDEAD58BULL, 
            0xADA00E826A58E5A9ULL, 0x2708D3831827417FULL, 0x9B5BF71E873F69E0ULL, 0xDB5A0D56ECF3C75BULL, 
            0x1261C8A6AE466222ULL, 0x12EBC2495CEC3394ULL, 0x1300A583907319B1ULL, 0xFF5922457E88B037ULL, 
            0x6AD5B9AE3CBB08D9ULL, 0xAA2D33ED1E408DD0ULL, 0x1D2E42EE161B9B99ULL, 0xE8583400018BFE84ULL
        },
        {
            0xF67AE09D78D85068ULL, 0x86001CCD54AC5CDCULL, 0xBE925A2DD6295E25ULL, 0xAFC92BF661B71F13ULL, 
            0x8367ADD4DB76CE12ULL, 0x4B19E8558156DEC8ULL, 0x42DE661935F3894FULL, 0xB45D4C4C2605D0AAULL, 
            0x65782B6CEBB82446ULL, 0x976217BF63069A31ULL, 0x298F18FA9B41EAD7ULL, 0xA65B168E3CEDAD20ULL, 
            0x91BFF40000415264ULL, 0x5147F9BF7365A6A5ULL, 0xEEC40FF6623521C8ULL, 0xAE8A10906261D694ULL, 
            0xB0B7675B4398DE30ULL, 0x8C82A69CC7376BF8ULL, 0xD59060245745FCE0ULL, 0x0AB18609B8462EDBULL, 
            0x3D651C6609C00D2CULL, 0xCA09D780D8E694ADULL, 0x55735DAFE7F44A7DULL, 0x8D354233B0D77231ULL, 
            0x1B2E89EAD9E4FD79ULL, 0x75809DA73660682BULL, 0x6361BB025C3D0FA3ULL, 0xA4897B747D59E2D4ULL, 
            0x5183356963BEA19EULL, 0xBDF622E1ABE0943DULL, 0x6D80533D211F7EF6ULL, 0x9528E8508A343543ULL
        },
        {
            0x14E82F2D850D5A3AULL, 0x638D059456820F6DULL, 0xA485A2D1CA080556ULL, 0x3B9715FBAA6FB9C5ULL, 
            0xF22A7D05D984F72CULL, 0x172D31FA123A66ABULL, 0xE8712927AE7D5CF1ULL, 0x9DA1624B52478A11ULL, 
            0xB66906E60844AF27ULL, 0x7D2A3A9487668B47ULL, 0x455A2AAF7C38601FULL, 0xE03E2E61A2BCCB95ULL, 
            0xFCBA6DB0A0A29334ULL, 0xD404DE9F02D3BE6DULL, 0xB7E71D204BAAB699ULL, 0xEE9153094EE0336AULL, 
            0x0039DC3F6FEA8DFCULL, 0x0D022A783BA69E4DULL, 0x016BDD19127B1AADULL, 0x600A935FD16B36C6ULL, 
            0x6569569319391B07ULL, 0xFD5E358101BED9C1ULL, 0x1C74A13954A20FB8ULL, 0xEFCE134A95617159ULL, 
            0x58A84AD2EB2D1D0FULL, 0xA4DBC87B26B8D536ULL, 0xE0A2E88664FDEE16ULL, 0xE2BCDBE2EE8211D6ULL, 
            0xDE1B7BF0F9BB6B0BULL, 0x8DC56A550A729D0AULL, 0x822BDDD8F46ADCE7ULL, 0xBA634BD2107A790FULL
        }
    },
    {
        {
            0x1FE8F19FB1BA8FA5ULL, 0xBBA583E93D260C93ULL, 0x720F746350CA0FD2ULL, 0xE81A7D71379FCA19ULL, 
            0x2E2EAD542EA20344ULL, 0x5A87F567D5DCD79CULL, 0xF8E50ADA3B545884ULL, 0x9B62FA3BFE9BEF1AULL, 
            0xA4874540A86F9CF7ULL, 0xB2353C1D9B124C1EULL, 0x0F6F2C9E17745ADDULL, 0xF8DF9763E9DC4F2CULL, 
            0x81AE4AB86FBBAA02ULL, 0x40E872E8421FB2BCULL, 0x49431DED857AC0A0ULL, 0x7104E2BF3DED1C7CULL, 
            0x1EA2E3AA45D877B4ULL, 0x7707A2DE5B8630B9ULL, 0xCC87E56BF36CD1DAULL, 0x16AD1C78085E4458ULL, 
            0x4F43501B52F6D8CAULL, 0x4C1574903B1A071FULL, 0x1195766D44772A73ULL, 0x55BA99BCDFD32BFAULL, 
            0x7249009BBBDF3AC3ULL, 0x68B5B415736AB8D9ULL, 0x8AA0F0A2EA44B566ULL, 0x774A3DF63D45C623ULL, 
            0x483D91BF12AC65E4ULL, 0xF1202D0F98AFE796ULL, 0x1B095E7A7BBAB638ULL, 0x7812CB49C1849FB8ULL
        },
        {
            0x3D104DDEA55219E3ULL, 0xCE87ABDD5CACA381ULL, 0xB4C0981575205D4BULL, 0xB92E8955AE1841F8ULL, 
            0x8EE8A0070CDFB21DULL, 0xB170A9193624FB8BULL, 0x892C7C418E2DFF10ULL, 0xE478DD31C319FCF2ULL, 
            0x6C9892322AC3D1D2ULL, 0xBD11CFB98A254317ULL, 0xC9C0CBF8D555D555ULL, 0x55308F1F0385C617ULL, 
            0xAEE16587BF7661F9ULL, 0x175038C94D196C10ULL, 0x2609B708835F163DULL, 0x87F6D0EAB2FE02C0ULL, 
            0x0E14D798C1243D79ULL, 0xF64A91F3671A6DD1ULL, 0xC39700A0973B0807ULL, 0xC286CB73FD51C2A6ULL, 
            0x41C7E31A95BDFE9BULL, 0x396F624CD1096C3AULL, 0x04EEED6C0737405EULL, 0xE80EC5D384AE129FULL, 
            0x047B53B3DB7BF1E4ULL, 0x6E4DCCB762A8940DULL, 0x5B1D8EBA3C474BF1ULL, 0x86D56A7651F18F48ULL, 
            0x4C16B13511903108ULL, 0xA4208A308DE2ECCBULL, 0xD14EE9EB29135888ULL, 0x25C1641AD7968389ULL
        },
        {
            0x2FC4FA926A419175ULL, 0x7A93838FE4127F37ULL, 0x9190B96011A506A6ULL, 0xA6F302D4B8F295D4ULL, 
            0x7D80E04F60075EDEULL, 0x79D263C5E91D7291ULL, 0x9BC100ACC327A0D0ULL, 0x7E37B77E68B4BEB6ULL, 
            0x1CC300BAC6D5307AULL, 0xF90C4482316AC738ULL, 0xEF54CE69C3E14057ULL, 0xA6DB826D3A7EBB92ULL, 
            0x547663E0E44DFD7BULL, 0x109B70CE9FE21026ULL, 0x9954C035B16B9A67ULL, 0xE72D7F6C13BB6A75ULL, 
            0x7E00ADBA84688D0DULL, 0x846E7929732A2A64ULL, 0x1A7D7E978601F1BEULL, 0x6F6C6BB47B1DA254ULL, 
            0xCD9C61F5AF0CE646ULL, 0x5F5FA69973F3BEFEULL, 0x362875C817D6BA7BULL, 0xE038B08932E611C6ULL, 
            0x1AEA816414D15451ULL, 0x99AE0B3DCEE49A70ULL, 0x3B2CD7A1744D4D95ULL, 0x90B59212E8FF1D47ULL, 
            0x4F51DCA34278BD2DULL, 0x47761F38DEAB5818ULL, 0x7C9CD4D98D36C7CBULL, 0xBE0342F5AA8259A4ULL
        },
        {
            0x464D3C4C3981A719ULL, 0x9773A70BB151F07AULL, 0xC347C517FB224AE3ULL, 0x2B8E35EE15301DCCULL, 
            0x8E3F4BA31723858BULL, 0xE54EFA9850D448E1ULL, 0xC4D7C2140CDAF1A7ULL, 0xE8C5478F0153ABD8ULL, 
            0x1FE3CFB5B6102B31ULL, 0x07EE79DC5B209CD4ULL, 0xF03C5FD8F952A388ULL, 0xA608F3377ACAC158ULL, 
            0xE3FCF203F4B0457DULL, 0xB9460C53F05FF49AULL, 0xA9CC075CE7899A54ULL, 0xC89B97759C80156EULL, 
            0xD5E3C547C1AA1D02ULL, 0x9041866F828B4952ULL, 0xF56A6167EE2B0BD3ULL, 0xA2F7359C70A90EA6ULL, 
            0xEA65932BEFDBA74DULL, 0xE535C0AF9809D3B8ULL, 0xF056E2FAEF53274AULL, 0x141A8EA5F53A1570ULL, 
            0x5284616C0F485815ULL, 0x9C5C3C0FBA057593ULL, 0xDFEB0BC124E3DA23ULL, 0x45C708261A2A91C7ULL, 
            0x8B1AEB5333BED076ULL, 0x4860EFF505B64803ULL, 0xA271E56CB179219FULL, 0xA15FFEAD7D804D31ULL
        },
        {
            0x27D6B3386757A138ULL, 0x0263E6E27D9EBC21ULL, 0xE22038508C0E736AULL, 0x5EF8724F08730DEFULL, 
            0xD5329A827D416B66ULL, 0x3F5E29C0A69C2332ULL, 0x4AD06922EEC32602ULL, 0x2F1AF0FD19ECF4EFULL, 
            0x641CC3ABCEBCDB1EULL, 0x0DF05FB69970E736ULL, 0x02A3BB0345E97170ULL, 0x5F4A442B581A53A7ULL, 
            0x0816054BDB4B7AB6ULL, 0x6B37DEE40B44EF2DULL, 0x282931A71B29B02FULL, 0xFC8BA502E0BF1100ULL, 
            0x9723DAE8CC069EC8ULL, 0x2DDDBFF8D4396C37ULL, 0x7ADF0A4725078875ULL, 0x4B9EDE5406F5064DULL, 
            0xFC83D1DD5D08F2E3ULL, 0xC18A6530FFCC9EE9ULL, 0xD2F3D6F15A0AEDECULL, 0xC4355650CA88F715ULL, 
            0x8609F70B02C31FBBULL, 0x4C9400110F4BD7ECULL, 0xF5CDCD6F7E45FD8CULL, 0x7965C9C85676082BULL, 
            0xD59E51B07AAA5E6EULL, 0x110DD02EFD9BC2C7ULL, 0x768F5AFC39BB1C0EULL, 0xC4479B2AADE96341ULL
        },
        {
            0xA9B6EA2E852FBFB2ULL, 0x5F42123633B38CDCULL, 0xBF34EC96B8FC451BULL, 0xA4341DF9FAFA5DF9ULL, 
            0x3FDEF5C819A8EE74ULL, 0x2C66DA6B5131700BULL, 0x3BAC5A6F1F68A0F3ULL, 0xC9FF0C14D56617CAULL, 
            0x8E848D270AD2A567ULL, 0x5FF7B1D15FCB8025ULL, 0x302A24D127C81D06ULL, 0x6FA1E1111AA247CBULL, 
            0x4547C89F746932BAULL, 0xAB69DD54E530F525ULL, 0xA2B3757CE00D85BCULL, 0x928AE29AD751FAC1ULL, 
            0x10AF634D56E660CFULL, 0x9EA554FF2C1E803AULL, 0x8930E68E173AAD6EULL, 0xD30D7890142AFEBAULL, 
            0x0081150C6A1AC102ULL, 0x820E3E7536BD9D0EULL, 0x48F9F1E744D3DB3FULL, 0x1FB3ACF1E2194F2EULL, 
            0xF38944554DA0C7B6ULL, 0x0334CD086FABBC19ULL, 0x3499393D82ED847FULL, 0xBE5E19FB91BF86F6ULL, 
            0x6539B2DFE8133F4FULL, 0xE9AB43BF41E5329AULL, 0xB13D61BB52F50E95ULL, 0xE728557AA11001ADULL
        }
    },
    {
        {
            0xD69ECED421CCB9D5ULL, 0x7E187086D7193726ULL, 0x132996BD39B4B225ULL, 0x27C09B3DB8D60F24ULL, 
            0x46F826495E361B0BULL, 0x62B3B8C30EE57F1BULL, 0x959AE1AC3ACEDFA6ULL, 0xA94154D1E366AE26ULL, 
            0x84C94872D382B3EBULL, 0x983ACE08BF3FC272ULL, 0xE93F14FEAA0A575AULL, 0x07F2B1CC42A870D4ULL, 
            0x42BC44EDFC2097FCULL, 0xD311758906959506ULL, 0x7D3CAB1A358C179EULL, 0x0E8E727897074A87ULL, 
            0x1CA1EAF5A423796EULL, 0x8D7DCB3FA37FC56BULL, 0xC881F12CCC65FF18ULL, 0x02E8136B0693BE1FULL, 
            0xF4FD2C51D0F13A6FULL, 0x5A4B6E68648D5D33ULL, 0x4D8FD4EB37201D36ULL, 0x9140FD2E93EA9244ULL, 
            0xF3A69268F740B431ULL, 0x5DD2F1C357970D7FULL, 0xCBFA19BD787E1006ULL, 0x2287A45AC9D5DE3DULL, 
            0xE47BB84F8CC52C2AULL, 0x536975E01E4D379AULL, 0x130879C9CC2705C6ULL, 0xB18F57A65CD09F66ULL
        },
        {
            0x1EB77A37CC623F25ULL, 0x94BD6529ACFEB231ULL, 0x29E6E3C47E2EFBDEULL, 0x134A2EB755B99F0EULL, 
            0xA66FDB37B9880A4DULL, 0xAD38D39E78BB6DCCULL, 0x13D0C1E0805C1E61ULL, 0xD078032EA27E2065ULL, 
            0x1711A441A09EC796ULL, 0xD07D202E30CC8758ULL, 0xA9C987B12897EB62ULL, 0xE68BECC12417B8D9ULL, 
            0xB9EF1681624C23D5ULL, 0x6027CACE90BD6005ULL, 0x34359E968EDFD032ULL, 0x504D973139737F1DULL, 
            0x160CA6B1F92D556FULL, 0x5E97BFC1004D005BULL, 0xE71BA99D480A70E4ULL, 0x5C21742F12F75644ULL, 
            0xE715F009BD1117F0ULL, 0xB4FF10EE30C4A1D2ULL, 0xF9C8223787F8535DULL, 0xEDDCFF4F71EF5108ULL, 
            0xFEE87D8ED9E1F1DDULL, 0x7E9939D296340D7FULL, 0x3F0C6B1AC0AEA8D0ULL, 0xEF399890D748FB96ULL, 
            0xE7E6D8CF26306651ULL, 0x39577C8586AE47A9ULL, 0x42F73B52A4F02A46ULL, 0xCD08E126415A8E0AULL
        },
        {
            0xF06E33E7E7FC45F3ULL, 0xA4C2CF55E7D8472EULL, 0x096B6E7790F9DA30ULL, 0x77D78B06AEA47A9CULL, 
            0xA5A5F3BA7691CDF1ULL, 0xCD003AA1498BE2A9ULL, 0xBA1CC940E54EFE90ULL, 0xF9E7ADE44E0E505FULL, 
            0x909437021B1CB141ULL, 0xB1027B0BE2FB90BEULL, 0xD533D54BF28501D1ULL, 0xF23E2AC61AC2BC53ULL, 
            0xF604575E8A05BA4BULL, 0xA73C58B154CFCD52ULL, 0x737B707F892EECFCULL, 0x72155250BDB8A37AULL, 
            0x4F8C8E4148334E5FULL, 0xC6A89A4B16311F56ULL, 0x54145FC97D05A084ULL, 0x867E4C62379396F6ULL, 
            0x72642F3853038EAFULL, 0x375E0A1079FF8DF0ULL, 0xA033A774DC67ABAFULL, 0xAC6FBCDFDF5B7CF6ULL, 
            0x95815211F78892DBULL, 0x2C52495A6EB3D639ULL, 0x53EDCE3C0AF259CEULL, 0x2700867072A35EC1ULL, 
            0x0096EBFE38A79134ULL, 0x14664E2B2DBD03D4ULL, 0x51A2391FBE3F0759ULL, 0xBFAA08810B433290ULL
        },
        {
            0x52FAB77CA652DFE7ULL, 0x16C21C6F91E643B5ULL, 0x626A510A6BD69713ULL, 0x41E2E51DD752F268ULL, 
            0xAFB96CDFBFF78289ULL, 0x117592530698850BULL, 0x3ABB68F9DB887B4DULL, 0xFC0DCC81843F4858ULL, 
            0x26E95997E8B821E8ULL, 0x250D29AD9D0C43E6ULL, 0x6CBB30BD701B014BULL, 0x7CB9775795715E30ULL, 
            0xC2901EECAB2DD11CULL, 0x163E13B172E8F136ULL, 0x124877A550BBEA1CULL, 0x6629F96388C2EE67ULL, 
            0x5D79CBF49D9166B7ULL, 0x3A680372D924CC53ULL, 0xF814E696976CC02FULL, 0xD6AB91BB1F362054ULL, 
            0xE654B6ADB5C968E3ULL, 0xB267CD1EE18FD643ULL, 0x7F731FDAA8DCDF77ULL, 0xDC5D960FCA35E709ULL, 
            0x356B38702A25B8BEULL, 0xBAE372FB7904CB5BULL, 0x2EAA70109D477952ULL, 0x01AB677BDF049233ULL, 
            0x202537A735A7EEFDULL, 0xF1F43DA5CDE22E3DULL, 0x6C84DBE2C942604FULL, 0x7F8AF548ED33B7B6ULL
        },
        {
            0xB15D5CA682693505ULL, 0x30AEA8916BDC1DF2ULL, 0xB6C109AFE0F39804ULL, 0x19A140256ABF1DA2ULL, 
            0xB859EB80D4E08B16ULL, 0x5C9CCC85050DCEEBULL, 0xCA17522F39E6AB4CULL, 0xFFF1BFECAC45DAE2ULL, 
            0x44A11D7BD82552B7ULL, 0x4654491B9D2D828AULL, 0x2BB548538C656FDFULL, 0x6A4386D1AB6B4BF4ULL, 
            0x6FA596444571231AULL, 0x80255F66CAA044EAULL, 0x11AA4EB6D6377B6EULL, 0x4B9A386C098605BEULL, 
            0x2B9FD6A9BC624190ULL, 0x10D55EE96AFDAA0BULL, 0xA80E7E877CF0363CULL, 0xEBD7D0B7B975E213ULL, 
            0x35220DDC6287656AULL, 0xD9A85DC238A8C114ULL, 0x7E12B4C257D579BFULL, 0xC832E93D21E919F1ULL, 
            0xCDD94A7A43E5D93DULL, 0xF8BAF37836551C1CULL, 0x4172C6A9E69DA134ULL, 0x2EB097CAF5D39AE5ULL, 
            0x0F5083C0FA775730ULL, 0x536014C00781166DULL, 0x7FA77708D4BF6F76ULL, 0x8666E488DEBC3852ULL
        },
        {
            0xE9B687950D24F859ULL, 0x30E0253EA0605784ULL, 0xED02F988C742468AULL, 0x2D2EFD86EF5A264BULL, 
            0x7F46915F83015E72ULL, 0x16C3FBFB9ECC47D6ULL, 0x04D5A6757BDEBA05ULL, 0x95D1915073CC7F38ULL, 
            0x9A85D90EB81A9EFAULL, 0x43A48702E45C2B86ULL, 0x349317E61F166085ULL, 0xCE270D038644417BULL, 
            0x639B26CBEEEB6A69ULL, 0x0011D769B0EA6A02ULL, 0x2AFAEC01FE208D76ULL, 0xE1423FE16E3BFFE1ULL, 
            0xA0F44B508836EF18ULL, 0xD2C671CE3A93628DULL, 0x4BD5A97FA87604EDULL, 0xE2CEBED72BE00D42ULL, 
            0x56EF196A829DBDD3ULL, 0x820322C1D4D0F150ULL, 0xD89500CAF95A5A80ULL, 0xA042F2B7C7786B97ULL, 
            0x8E1513342835418AULL, 0xD4E73ADEEF53A821ULL, 0xF50C712CC6F19FABULL, 0x0DCBBF18616DDAF7ULL, 
            0xA0E08456818A77A6ULL, 0xECAC45D2C5D3804BULL, 0x4531C923CD9D6A27ULL, 0x02A19538F8C1231DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseEConstants = {
    0xAC8A88392E879051ULL,
    0xB068DA45C4274868ULL,
    0xE82984D79A6430A5ULL,
    0xAC8A88392E879051ULL,
    0xB068DA45C4274868ULL,
    0xE82984D79A6430A5ULL,
    0x06994DE813A3D5D2ULL,
    0xE8F6F669DC1D5172ULL,
    0x5B,
    0x20,
    0x80,
    0xAD,
    0xEB,
    0x05,
    0x16,
    0xC1
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseFSalts = {
    {
        {
            0xE2D5DECD9A885B35ULL, 0xDB445F5FCE932410ULL, 0x232454F8C490EA16ULL, 0x07A2D72A7B5A04B4ULL, 
            0x77B367CB3B90C536ULL, 0x3D70E3397C5487BCULL, 0xBDDEC4991F04625BULL, 0xD8691431FA16BA0CULL, 
            0x395CCF33323C42ABULL, 0x06A6C933928356D0ULL, 0x85D428E9CEC53CCBULL, 0x4DC04C43C56EFF12ULL, 
            0xB417DA37A247A34BULL, 0x9B0897577B6224E3ULL, 0xD58DB614D2A9CE2FULL, 0x91B5F5E2E3DF212DULL, 
            0x810C7193847CF35DULL, 0x6FB30180C3744A00ULL, 0xB800F8B4C6AAC692ULL, 0xBA6A0EAD72396037ULL, 
            0xB189770F83FC58CEULL, 0xDE05E2B7CC6DEA39ULL, 0x6665AECBDAD46996ULL, 0x2DAFCA461CD099ACULL, 
            0x1C34C04F5C06D384ULL, 0xFC4960481C64EA59ULL, 0x92C291F2843F8E66ULL, 0x9E1E6C2B0A4D203AULL, 
            0x997ABC89CFE503C3ULL, 0x856A8BD1EA07271FULL, 0x711EE4A738DB9EE4ULL, 0x2D1A932477228330ULL
        },
        {
            0x70BC750E490BBD7CULL, 0xCAB64C6F99386F58ULL, 0xAB7F3B586CD32EB5ULL, 0xD02C6FD974D886B3ULL, 
            0xBB83CB3CD59075B1ULL, 0xA75E2EE13E5510FFULL, 0x70198448BADA2874ULL, 0x480640C409DA98F5ULL, 
            0x12BF3F32ABEA851CULL, 0x2293D09E72963292ULL, 0xA0FD903E2C3052CAULL, 0x06BBD384321C78A5ULL, 
            0xE36059613AA70B9BULL, 0x5B73B103FE8EDE14ULL, 0x7B32C6ED19716BFEULL, 0x3CBD8FAE45FBB514ULL, 
            0xE362F71D1B3AD25BULL, 0x2BD2DDC1C7FB585DULL, 0xD31D31B628090E36ULL, 0xEC7BBA747EFB897EULL, 
            0x4D86A4988FF69E62ULL, 0x333F41889ABC1D57ULL, 0x2D842C1FE217AEF5ULL, 0x530F48BBADBBA434ULL, 
            0x44BB19C2EA73C109ULL, 0x32803C55F4D16CBAULL, 0x4A6F2CB81DDFF5EEULL, 0x9428E4E4D74060CBULL, 
            0xC2096CB3B7515D9EULL, 0xE2F9C2C572E8DB0FULL, 0xF36C3F27F66FC75CULL, 0x2BBFC494DEC7A969ULL
        },
        {
            0xF8BCEFFD42C8E143ULL, 0xEEC5B2FD037FF8AEULL, 0xD8BD8947A1061E66ULL, 0x591F93472B7C4442ULL, 
            0xE8745062D97A9608ULL, 0x52BC4D572E6A8959ULL, 0x0EA04A34B44649A8ULL, 0xB4516FACB26F539EULL, 
            0x66849B7E980DCF30ULL, 0xD6CC6479A68CF22FULL, 0x126DA726C4246345ULL, 0xB67ECF0F91E46269ULL, 
            0x830C5E9263C5B95FULL, 0x48CB1E17144CF04BULL, 0x957448EC8F827374ULL, 0x01D7D850F953DF5CULL, 
            0x45FECD8BC67553FAULL, 0x27B4F8A75FE29302ULL, 0x975AC3416F428D2FULL, 0xE0712D4F46C32005ULL, 
            0x57E58527ECEC3986ULL, 0xD915F1FDF016A5D2ULL, 0x7FBE61B7297E49EAULL, 0x059A619CA26445A8ULL, 
            0xA59EE729ED4A59EDULL, 0xFA1AE85AAC375F08ULL, 0xD7892BF262A0C2E3ULL, 0xA048BC49DE92879FULL, 
            0x66DAB91F9E1CB3E9ULL, 0x02D6C124F0B20BABULL, 0x601667872714B8EBULL, 0xB6C47F88C9AAF369ULL
        },
        {
            0xF7B9B3261C9C3C79ULL, 0x0FFEAFDD14BADF67ULL, 0x8B810150513EC3D9ULL, 0x3A88529B36BCB059ULL, 
            0x08C9C76A3BF3B004ULL, 0x55BB6BF07ADAC56FULL, 0xF9B081E18454B76CULL, 0x42C0809128221921ULL, 
            0xBA5D1FEA97D69DB7ULL, 0x87DD02676E1234A0ULL, 0xD32450CF5444CCD6ULL, 0x69433045F0234285ULL, 
            0x75892E17AD7833A5ULL, 0xD73E56136CC87EABULL, 0xA2977C15F70A86C8ULL, 0x65741630B653EE7AULL, 
            0x53396C31177026C7ULL, 0xA4D07FD594510B2AULL, 0x453F5E33881D45F2ULL, 0x0B074262C4801EC7ULL, 
            0x54813918C79127E9ULL, 0x3F41D4C3C7A43670ULL, 0x7DA719EB604E42BCULL, 0xB67998B0CDA7CF44ULL, 
            0x63DCCA51E67F6FEAULL, 0xE6D56D9B48846A2FULL, 0xB0FD252AB6458607ULL, 0xB59006A3B3556B02ULL, 
            0x76C7C5430859C683ULL, 0x1098ECBD241D6E12ULL, 0x15E3199C1F255143ULL, 0x0AEB5577B038B488ULL
        },
        {
            0x82822D51CE911A3BULL, 0x7C1590237F2EA741ULL, 0x8D8473DA7ECB5ED0ULL, 0x4EE879E927B50982ULL, 
            0xD9BA07C9637EE03AULL, 0x3CF3AB459659B2C6ULL, 0x30AEB129EFD1D470ULL, 0x6E472A92BD47246AULL, 
            0xB779DEC6C226CE5BULL, 0xA5F40B5BA26DB7F7ULL, 0x712E0C06F039E050ULL, 0x08439EE5C2DB219CULL, 
            0xEF031F860A967DD4ULL, 0xF5FFB65A14E55343ULL, 0xF281A5531A50A40AULL, 0x78002C32A10DF981ULL, 
            0xEF1296E92A04BC37ULL, 0xB38A35E0B153842AULL, 0xDDF62E09E456F63EULL, 0x91AE787F1B91506AULL, 
            0x734634E2FB36C753ULL, 0xE449F9117E14AEE8ULL, 0x3C49B717638C59D6ULL, 0xBA80906BDA8D04B8ULL, 
            0xF814CA596E1E921AULL, 0x48046F3455F7777EULL, 0x2F4CF33E9D2F1F04ULL, 0x3637A51889C69741ULL, 
            0x3967DEBAB640515FULL, 0xDE9A9C832DA0F84AULL, 0xB05B311CBB22C570ULL, 0xA9B41190F5BC8413ULL
        },
        {
            0x5468E7023316B43BULL, 0xF8BBA76F1C638CA4ULL, 0xA0AC56DEC9A7D55EULL, 0xF35503363C36A234ULL, 
            0x23B44E0DF12BA49FULL, 0xD1AE95799AACD3A5ULL, 0xA98EE0124C8AE691ULL, 0xFD5B37AC4D0B777BULL, 
            0xD4E3E2DD195CD928ULL, 0xD699C2610FE84C20ULL, 0x27A318A7327D0AEFULL, 0x7304E45082709ED3ULL, 
            0x9D9603C451C6CB62ULL, 0x92FDDF406E0F9872ULL, 0x38B095A12CC3E51DULL, 0xE2762077CC631B84ULL, 
            0x791AD1F827DA1F68ULL, 0x1ECF436B8EE9B7E1ULL, 0x799965EC9A46F750ULL, 0x5ED6B5822343189AULL, 
            0x1D5956CEB634538CULL, 0x17BB51E5C152A5F6ULL, 0x9C23849EF693B0F3ULL, 0xC4C12359032E2C82ULL, 
            0x11EDBE3B9239BB6DULL, 0x28A701337F682E56ULL, 0xB4A35CA76353F1D8ULL, 0x3DAB6EE8FA4374C6ULL, 
            0x1A6429CC52ADE969ULL, 0xD482721A0F1E7A21ULL, 0xF06ADC783256F6F1ULL, 0x7A673E0526CBF833ULL
        }
    },
    {
        {
            0x9D13BB80277B6209ULL, 0xB8F4D4ACF3CC7612ULL, 0x23F1314CFA7F57D4ULL, 0x539A02DA30717199ULL, 
            0x134D412B895B1EC2ULL, 0xE67FF8989CD88FC9ULL, 0xF1C7207EE1D035C5ULL, 0x05CBEAEFD54A475AULL, 
            0xC933A14D27ACD6B4ULL, 0x1EAB387A9D7E6DFBULL, 0xBA4502486CFEBE30ULL, 0x1019F14D28602C3EULL, 
            0xCAB78787FC90C7C6ULL, 0x5BD76BA9A194BABAULL, 0xD348927C72F7D7C7ULL, 0x78F9016C1EA50F6BULL, 
            0xD059E50D320ECE28ULL, 0x91AD68B04A103E9CULL, 0xC3040EDCB281473EULL, 0x7CEACDD79EA82726ULL, 
            0xEFDE5BCC28BEAED1ULL, 0x7F9C9C75E9AB3479ULL, 0x79C3969BFFCAE438ULL, 0x94A0198E1CD5260DULL, 
            0xB43471AD8DCED127ULL, 0xD848CFD80B612A6DULL, 0x21C1371CCB494A02ULL, 0x5733AA9B9B270FFEULL, 
            0xBE83375CB62B6BD2ULL, 0x8CA4F03EFA7DF1BBULL, 0xF3487770EDFF09B6ULL, 0xB157C9E80516B803ULL
        },
        {
            0xBC1BE5F3ED1DCF6EULL, 0xFCB34B479E7D21E7ULL, 0x16E45976D729FD5FULL, 0xBA6FCFCF01979F62ULL, 
            0x4F69DAD4BA3C2FA7ULL, 0x9440E6A69B47866DULL, 0x3EE858E59B9A5EEBULL, 0x22C9A962F1F40EA5ULL, 
            0x522A2ED9BCD2F909ULL, 0xFE6D2A27BB824A55ULL, 0x3D32AA7F2A89477CULL, 0xB6C89AAC67695136ULL, 
            0xC56881581506ABAFULL, 0x37ACFB63487334A0ULL, 0x745620E6DB97C8E9ULL, 0x5F37351FA8C6E7A6ULL, 
            0xF7E4C4B0B695E309ULL, 0x0F9623A40EB0676AULL, 0xCA652C362213A54FULL, 0x5FCE626E15C94886ULL, 
            0x31AFAF05FC181A13ULL, 0x5DCE7838A21D9106ULL, 0xA12CFFCC2D3E74B6ULL, 0x1D775D62E33BF86AULL, 
            0xDF79814B3D0AC2CCULL, 0x394A9723E4E7CAA1ULL, 0x53471C0C3A59565EULL, 0x642ABF4D37651760ULL, 
            0xA8EC341A68E84F2EULL, 0x6E8E83B9AAAE39F5ULL, 0xADB00C79FDC35092ULL, 0x35FB544AEA8349ECULL
        },
        {
            0x2EEE46F285A73706ULL, 0x38FC47BAE9C26233ULL, 0x9186C4D95C8A64A6ULL, 0x0F5FBB3C914F4FF1ULL, 
            0xC377A7BB2A40DB8AULL, 0x783A06A7B24210F2ULL, 0x468A45AEB630A0C5ULL, 0x4A6995B7F0AEA224ULL, 
            0x54A256BD61D63E5AULL, 0xE0B5B29358D83C1EULL, 0x14AFCFB37460E121ULL, 0x4951BBEFC09D82C6ULL, 
            0x0D526021BCCEB1F2ULL, 0x7EBE698ADFBFFCFAULL, 0xA3E82AFE652D222FULL, 0xFCE07CF6E027A610ULL, 
            0xA8FD2E50E75B33FEULL, 0x5B25F6CFF82AAD46ULL, 0xCF1D5E16A21C6F80ULL, 0x4280531383B7674CULL, 
            0x79987CCCFA189E58ULL, 0xBC759C0B6EC8E0B3ULL, 0xAB0BE22557E33931ULL, 0x1C3AD132622678EAULL, 
            0x3616DA6D9F84C17AULL, 0x20F7432F72C68D69ULL, 0xFE93B70E6FE8D9CDULL, 0x0AD7CCA26702D2E4ULL, 
            0x8431DA1C50EFB0F0ULL, 0xBED40C498FED389AULL, 0xD3ABB11DDAE384FAULL, 0x1A3D4203D017A0F5ULL
        },
        {
            0x752696075D3D152AULL, 0x5CFB43F9881FA956ULL, 0xB17509CDF95A2F03ULL, 0x519B409DED0926C2ULL, 
            0x4E6704645F09AEA7ULL, 0x9924F242A4CF60EEULL, 0x6FD1754909785670ULL, 0xF6DCE2F5D30CF49FULL, 
            0x50B051D409547CFBULL, 0x605B0457B62637B3ULL, 0x89FF04F2FC22675BULL, 0x550078CC0F276296ULL, 
            0x6DD53D7895DC00E2ULL, 0x60BB2338EE1FABDCULL, 0x125AEBCE3556CF60ULL, 0xF8FCAE65470B53EDULL, 
            0xDC098B70BE77071EULL, 0xC2CB62DCABCF914EULL, 0x83A03F1D324DECC6ULL, 0x572C6E2943B1AAD0ULL, 
            0x3E477A88AFE5C3F1ULL, 0x66FD4CEC799B9E47ULL, 0x5C8B6FFC3A451F06ULL, 0xBDA923163E0D5E89ULL, 
            0x7509DF22CE9DFA87ULL, 0x784B4119CA3E271BULL, 0xE270D648B0C61F01ULL, 0x33C98CFC931C67F5ULL, 
            0x4CE84CFAD02227A8ULL, 0x1E5AD8F5FE548109ULL, 0xE9C693907B07F5BBULL, 0x2CF5A4C70B7347B6ULL
        },
        {
            0x7A484056F9F25F6BULL, 0x88AA178123FD92F5ULL, 0x73F2881F0BAB54CAULL, 0x3184F3972D4A9DA7ULL, 
            0xBA33871E27C11940ULL, 0x1F3DA4F48C4A1A91ULL, 0xE8C6F28ABE4B82FAULL, 0x1C62F8BF93ECA5A1ULL, 
            0xEDFD65C346BE0A5CULL, 0x82074958F43EC839ULL, 0x03671808C396570AULL, 0xCD5B234E312C7510ULL, 
            0x5AB2C3C1115D9EB9ULL, 0x0EE1DF701BB3E6B3ULL, 0x78D6D674D6C6984BULL, 0xE6BD80275818012BULL, 
            0x7A284B76CF893951ULL, 0xE347E41C4C98AD98ULL, 0xF58E774E98F13ECEULL, 0xD2E2FE90FE75E4DFULL, 
            0xB9FC2E32167E50E1ULL, 0x27905C8844AB6F02ULL, 0x520809463352EAB3ULL, 0x291824B19660E1C6ULL, 
            0xD505CF315B25F6A9ULL, 0x729F2BA55013B333ULL, 0xF0084339E2B9AB84ULL, 0x903FD1B27F49ECAAULL, 
            0xD4A51F64EDD7DF17ULL, 0xF2566F89904FBF27ULL, 0x50C586B9AEC56510ULL, 0x7C8809D347928DBFULL
        },
        {
            0x4B3E8C99A9A4BF55ULL, 0x5429F4CC56EAB65BULL, 0x60748B1C0A2C2F67ULL, 0x7B48F02C4848758BULL, 
            0xC34BF89F8A707907ULL, 0xBAF86193258E3839ULL, 0xAC1F2871E7D35FA2ULL, 0x61986CBD412FB5B9ULL, 
            0xC4278CDFD8C3CE21ULL, 0x626A0823A02A7B52ULL, 0x9CA6843162E19E1AULL, 0xBD56265A54C138CAULL, 
            0x4A14699623BCAFD4ULL, 0xA839DFD6CDB4615EULL, 0xBF8A851CA5C4C25CULL, 0xAACFC7FEE7F0BC73ULL, 
            0x5D6564CD28B2AD50ULL, 0xA1D326F230F4445FULL, 0x3CF6FCCFC1C2ED6AULL, 0x824782801363A6C6ULL, 
            0x59F8864C8777D645ULL, 0xF0FB6B80F6E0AA62ULL, 0xE7CE2DC418DDD1D6ULL, 0x8CF12464283DD999ULL, 
            0x91EDEB99D4877C2EULL, 0xDB994697F349DB4AULL, 0x1D10E68274BD20DCULL, 0xE1202DCCB9619C70ULL, 
            0xD90E162F1EE69946ULL, 0xA5C1FE756151C76CULL, 0xD2531D44B6E572BFULL, 0xC7F89F40C4329E8BULL
        }
    },
    {
        {
            0x807C5805E00DF32CULL, 0xC1A96F0C1C602865ULL, 0xA52B4B2AAD872CB0ULL, 0x7CE796E41350EE29ULL, 
            0xAE34C32E704216DBULL, 0x274B6A3B24C0248CULL, 0xD569D38A20FF1141ULL, 0x70A9BC9F4A243468ULL, 
            0x7D727C20DCDE933DULL, 0xBD999847EDA70953ULL, 0xF26549562F39D7D1ULL, 0x1F6E75EDC48296EBULL, 
            0x79A5C205B22BEED9ULL, 0xEEFBEB4399F89243ULL, 0x6DCBC8D6050F248BULL, 0x96ADF70E8C2E668BULL, 
            0x49FF0FF989D5D2FAULL, 0x7A4A0483B65C27C6ULL, 0x3CABAA0BAB073F58ULL, 0x93DB405A6B65DAF3ULL, 
            0xF7ADCB3B93C5B756ULL, 0x8A4F5117415C31F5ULL, 0x589F7F1026A02862ULL, 0x7B9C84B7C733F92DULL, 
            0xC75211F257BCF1A2ULL, 0x5E4F0434860C2120ULL, 0x76B87FCAD380B4B4ULL, 0xE72ED914B5FE7379ULL, 
            0x04CC8CD56294CEC5ULL, 0x119CF2004B0D4886ULL, 0xAC8678DE0130AE7FULL, 0xEA7313B5CBCC58D6ULL
        },
        {
            0xA1875B41FED28AC5ULL, 0xA0418517E3D4432EULL, 0x51117E56244B467BULL, 0x044BC0C84C213ABEULL, 
            0x842DBF82874F1425ULL, 0x576BF92A23579D93ULL, 0xC0A6F854B9942B68ULL, 0xC131CE7EE309672CULL, 
            0x9D38F6130A9AAC99ULL, 0xEA6A42DB23D8D3C4ULL, 0xB5197963E1852E12ULL, 0xD59F7212DD27D7CFULL, 
            0x553562AC5432FA1EULL, 0x2C70034D98AE93EBULL, 0xF47FBD9822986838ULL, 0xBD354C87A4074AD9ULL, 
            0xF2F8CF7A8EEDC5BDULL, 0x402C3B7A8450FF14ULL, 0x42E5177863DACF84ULL, 0x156803D81ADCD3BDULL, 
            0xD8D25B63640D814AULL, 0xEFF552A62C1BEA96ULL, 0x5877022E648841C3ULL, 0x4F526C52664E159DULL, 
            0x71CB5497752E59F1ULL, 0x43E44D2CD87D6DE8ULL, 0x203BCCA3E24AE4CBULL, 0x4CC149F609D9FA2BULL, 
            0xBACF96E52DC8A49CULL, 0xCA7B97DD29D60333ULL, 0x6DA59EADCE9BBFF5ULL, 0x28E79BC78CAA2E3EULL
        },
        {
            0x5B88DBDFA29878D1ULL, 0xB977C4625C3DFDB3ULL, 0xE7AF8053AED5D775ULL, 0x2A919D89618A6497ULL, 
            0xF01FAC62DBA4BB23ULL, 0x111D645B200B7374ULL, 0xA218C06A468448A2ULL, 0x7D8A5826F55C2AA1ULL, 
            0x89B051F2A21BAE8FULL, 0x3899944F548E7497ULL, 0x258EC07A4E7BF89FULL, 0x08F1D072B188413AULL, 
            0xED539C1208CC91D2ULL, 0x6339048936F7FF69ULL, 0x00DDAB48E8FDCEB5ULL, 0x5E6010219CB97F32ULL, 
            0x6A7978C88B44E28CULL, 0xE2A64E5B5073FE36ULL, 0x18E8BAE16C5029F8ULL, 0x4071D4BBF74A940FULL, 
            0x3B06F3D63BB592B5ULL, 0x66CEFD0FBC772D27ULL, 0x5DFD2A721260859BULL, 0xEACEF20AA5D7F14AULL, 
            0x256175AAC0E4BF55ULL, 0x1C673C78E6275F3CULL, 0x1E66A680BF1B74E1ULL, 0x4D1AE077BA4785DFULL, 
            0x83248A2D8594562BULL, 0xDD91A4E51F36EA2CULL, 0x427EFCCF2BA7EEECULL, 0x649B3F0FCFD848A8ULL
        },
        {
            0x6BD338ADB274A2B6ULL, 0x484067667DC3785AULL, 0x0ACD0B8192112F04ULL, 0x330E1AB4AF6494B0ULL, 
            0x990D56949269ABAEULL, 0xF544403AED9DBFD9ULL, 0x0706BE05081DE9ECULL, 0xAA2F277A7961B2A4ULL, 
            0x21D4285EE8B906A3ULL, 0xE874C2113E50D2CDULL, 0x68AC61FFDD195592ULL, 0x4F14280F07B93AB1ULL, 
            0x38926C5F530867ADULL, 0xD284AC61F78B7ECDULL, 0x3B4C67614AD80428ULL, 0xAD398A00C2B4CC19ULL, 
            0xABDE1F5082DCC8EEULL, 0xE260651B9F1C3DFFULL, 0x766CBD5AAAE50B99ULL, 0xC4C5A27CF94E7751ULL, 
            0xC3495968AB486008ULL, 0x70031A6F64DEBF78ULL, 0x266BC952EEA53BBFULL, 0xAE60869183783852ULL, 
            0x235058668549B6BEULL, 0xFAF2BC168103B441ULL, 0xF5508B677E887B0EULL, 0xAEEDD390A918DC8BULL, 
            0x504136FF6E8DB58AULL, 0x34AD34A201A512D7ULL, 0x9BE4A0171EE034A8ULL, 0x5F7417541051CF80ULL
        },
        {
            0xC6E614A9532566D1ULL, 0xF8913FBBFA097911ULL, 0x635241DA865FED03ULL, 0xDDF129AAFCBAF618ULL, 
            0xF2C82CC92DBB836DULL, 0x3BA5FC857B9647ABULL, 0x15A52131F3F5B117ULL, 0x596443334732BAB8ULL, 
            0x1562639B4F2CFD5BULL, 0x108384350948DFFAULL, 0x2DA83D67260E0376ULL, 0xF69969BC46BE6D6EULL, 
            0xBEF9D314D22D878CULL, 0x6F0B111299F8444CULL, 0x8B0DDA3CFC8B78CDULL, 0x56E0CD84259E4A52ULL, 
            0x9C98B7CF80D30A3CULL, 0x5D560920618BF283ULL, 0x2FA67AAA0A41F4A6ULL, 0x12407F0BEEC5E74CULL, 
            0x0DD26D6C04546B5FULL, 0x80EA40150438DB59ULL, 0x25F80E849D2D156AULL, 0x651874BB010F3FADULL, 
            0x7FA9F14C28CF29B2ULL, 0x210DB28C91B33787ULL, 0x6F8BB8D257811AFEULL, 0x49B95A1739050989ULL, 
            0x305522E60E50F86DULL, 0xAFB1890886C9D1B1ULL, 0x9D3A93FB7B0A56C0ULL, 0x1226B7653799B8FCULL
        },
        {
            0x5BC5836EA0A5758DULL, 0xF5201979C2F60739ULL, 0x406D259A00C5F128ULL, 0x912D4CB187FF9923ULL, 
            0xD56321045E59673CULL, 0x80E5A473765D6767ULL, 0x59BD101681E8DAD8ULL, 0x493E0F74B313E3D6ULL, 
            0x2E79A5CF14C03F88ULL, 0x207D3BF291CAD545ULL, 0xE66F3DD233135A35ULL, 0x96100C9D94442C15ULL, 
            0x52EFE66CEA72EC2AULL, 0xA8ED6A477128D54FULL, 0xA421F57D5111F86EULL, 0x61B896329A2EFB90ULL, 
            0x3A6D69632FD070E3ULL, 0x5134539A423232D2ULL, 0x735337A60AF6D42BULL, 0x8535AC3A2CE5F3C4ULL, 
            0xC730484B64E4DC56ULL, 0x59F0135A62154A02ULL, 0x1A682447D11978BCULL, 0xF90CDD45567CD932ULL, 
            0xCD242515DD6036E2ULL, 0x5B7BC496CF1F0024ULL, 0x6E90D4C571C44071ULL, 0x376F2A415E86D8E6ULL, 
            0x6AFA14D781CAABADULL, 0x657E0520234BA166ULL, 0x30E9DF74A3F9C11BULL, 0xBD1171376B47D971ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseFConstants = {
    0x421AF6982DED50CAULL,
    0x6003448B4A765CAFULL,
    0x485DC9F48BF5CCD4ULL,
    0x421AF6982DED50CAULL,
    0x6003448B4A765CAFULL,
    0x485DC9F48BF5CCD4ULL,
    0xE9625DB32EF02A8BULL,
    0x58EF286040B06CDEULL,
    0x30,
    0xD2,
    0x53,
    0xCE,
    0x54,
    0x44,
    0xB4,
    0x4F
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseGSalts = {
    {
        {
            0xCF8378C3E78BF60CULL, 0xEC1C221D783B4945ULL, 0x2E7DC9592B67B909ULL, 0x1960AC0AA2BFC379ULL, 
            0x8D268DE84D815690ULL, 0xF2C389F4310F4A37ULL, 0x4BBD4421ED83C544ULL, 0xFD9F1F11F640308EULL, 
            0xAD899A39FB01F20AULL, 0xEFD2B2A738D3D3AEULL, 0x45C7F6780B5CEE54ULL, 0x8DD362F714FE8B79ULL, 
            0x4AB66AED5B8063E5ULL, 0x7822350E542BC976ULL, 0xBC5A8FE16895160FULL, 0x8BDE9B49D0104ACEULL, 
            0x4313836E12451BE3ULL, 0xB5AFEC9F8CDDE8DEULL, 0x5743871BBA14AC8AULL, 0x26806078508A8691ULL, 
            0xB286490AEED5AA97ULL, 0x733406B24A675BA7ULL, 0xBA79D74E1F6AED31ULL, 0xDA90070C9DD3E47BULL, 
            0xCD59F00C827F3413ULL, 0x0A7922C83BC2BF0EULL, 0xF585F06C498E334EULL, 0x6788C9436798DBCEULL, 
            0xC4F325A0F93850F9ULL, 0x5B26A5BB0AE2C1A2ULL, 0x5C6374006D6620F1ULL, 0xD4D65CF1E6BAE6EDULL
        },
        {
            0x2082B7F68EB51789ULL, 0x6FE00F5C7831D340ULL, 0x91A8566B4C774FE5ULL, 0xE95CCEA00EDD8BB4ULL, 
            0x84FE11E067C52EB8ULL, 0xF158AE43E4FC5DC0ULL, 0xFDB71B1D837932F2ULL, 0x0FB75A0A2EEA52F4ULL, 
            0x7A89FF95E307B8B3ULL, 0x3BC3B0E3EC0A602BULL, 0xA0CEF7577DE495F8ULL, 0x3DB1B99950AA87C0ULL, 
            0xE63200E68CFDAB91ULL, 0x03B98FD11689E95FULL, 0xCDC6F7BD127F32F0ULL, 0xB124F65AF3275D34ULL, 
            0x5F604D427943F199ULL, 0xA50E36B04B71EBD8ULL, 0x5588870472FE4535ULL, 0xFC56D9C46D482D9CULL, 
            0xEA79F25086EF1D8FULL, 0x3006824526BBCB5EULL, 0x3DA5237ACAF0CB8AULL, 0xDF13D3052ABDFC2FULL, 
            0x828073D475AD03EEULL, 0xBB3191F47CEDF583ULL, 0xB40DEF0F0CE78F72ULL, 0xEFE27DA72D386B31ULL, 
            0xCDA378160407F898ULL, 0x61F3FFFA0870D044ULL, 0x0CD88450324D13D8ULL, 0xD5721E74F50E0C08ULL
        },
        {
            0x723EEEDE32428178ULL, 0x8915DEB1CE1A398CULL, 0xEEE8842EF5A1C894ULL, 0x350EC20DF32C948AULL, 
            0xA09645E2514F5921ULL, 0xE274F0EFB3C9809EULL, 0x99DC379742DE495BULL, 0x886C35A3306B9BA7ULL, 
            0xB0980C846704A2B2ULL, 0x770FC8E5F02ABABEULL, 0xA8501C26283C70CFULL, 0xD097A26967BA8C8BULL, 
            0x67C0DB790A63B7FBULL, 0x6BC1895A2B69AE0CULL, 0xFBCEC25875A4330BULL, 0x650CBACE2CFD6FC0ULL, 
            0x9C02CCE705F81153ULL, 0x71D4AB1A7C302C8EULL, 0x6D98AD442F45DFA6ULL, 0x2416479AA88DAB6AULL, 
            0xBB104D569B469D9EULL, 0x5300282624707877ULL, 0x7BA965D5225165F6ULL, 0xCAE340375186E6F9ULL, 
            0xF74D8EEB0B696F10ULL, 0xE40246F40657D28AULL, 0x7B60EC839A36A809ULL, 0x4D574FDEF1CD64CCULL, 
            0xAF12CCDDCB80A9CBULL, 0x79062F56A2B23881ULL, 0xEBBE370D49E4C482ULL, 0xBC87809CACEBA059ULL
        },
        {
            0x18B7FD6146C5C44FULL, 0x821B92A23D342E67ULL, 0x1B969888F0D7811EULL, 0x3748294E1139E319ULL, 
            0x0E1A3CF43B50542FULL, 0x15ED5D2946CA57F6ULL, 0xC70FC000250714CFULL, 0x6AF3A2FEBC6EF550ULL, 
            0x4B07831D8C75DACFULL, 0x3465D88EDD5A691DULL, 0xCBA94F9023C53AC4ULL, 0x13AF999A809B631BULL, 
            0xD537D0BACEA70DB8ULL, 0xD4D5ACF425BFBFC4ULL, 0xDB262D18F2E81984ULL, 0x1CA153CBF4C29245ULL, 
            0xF2D09E521B6D0199ULL, 0x256693A1A4012203ULL, 0x97AADC722F7DFFF1ULL, 0x488F91C8F7CF0C72ULL, 
            0x014AAB826DE05FC1ULL, 0x16DE850EF88D4DD7ULL, 0x0D91958DB3481F48ULL, 0x9A1F04817D68E66AULL, 
            0x0091FF04F82B1D5EULL, 0x0A9A428F1BD59679ULL, 0xD4C49A69CC5D4481ULL, 0xFAF665E9257348B1ULL, 
            0xDBC433501818E0D0ULL, 0x7E0D5EE7DAF076BEULL, 0xA37EB0F9468AC88CULL, 0x5ECC32DFF0CF5DF8ULL
        },
        {
            0xA6D8085D63F98DC8ULL, 0x2C3A1FA184255EFAULL, 0x389BF1FF8F3FCDC2ULL, 0x7B9F50669506A149ULL, 
            0xF9F7D0A82DF3CA62ULL, 0x895F6F87946E5548ULL, 0xAFA9CD579428F6CFULL, 0x9E93BD2EF8720355ULL, 
            0x38004A470D15C50BULL, 0xB991648B24AD1D9AULL, 0x9355C41A6F687539ULL, 0x5965B6E1E8C247F7ULL, 
            0xDA4871383A50B7A5ULL, 0x9D9534C8E6D70EB8ULL, 0x33FA6C35B4F4C0D5ULL, 0x711046590D4E985AULL, 
            0xAD6395A375071C58ULL, 0x53C2C84C1D497F00ULL, 0x046A74F83E00C6B9ULL, 0x6A2CFE3489608A61ULL, 
            0x1CBAD563006769CBULL, 0x9188F41A5FD09E74ULL, 0x3E4BFEAF37C484F1ULL, 0x15AC6BC5B812332FULL, 
            0x53BA2ACABAE07267ULL, 0xAB64A26C6852E368ULL, 0xF97CE1D95ED2822DULL, 0x2D7AFFE87F63E094ULL, 
            0x7B7C2EE54226B758ULL, 0xF4364FBA7B447AEBULL, 0xF5467544B33F2369ULL, 0xC6B288EDBA6B7F54ULL
        },
        {
            0x4BD1133C5C4F1F48ULL, 0xC1776CC8ED8A9319ULL, 0xCF0734491B71556FULL, 0xC92BEB1275EE381BULL, 
            0xF20B85E9C34FB6E6ULL, 0xD071E57511422704ULL, 0x6751D66377189206ULL, 0xB3A27719DE64893AULL, 
            0x505736EE506F96EEULL, 0x81850C0BDB571A30ULL, 0x2863B8DF386DFEB2ULL, 0x4603793144DFA6B9ULL, 
            0x6A57BB822CA6E4C4ULL, 0x4424BBB31C306F1FULL, 0xE1F8D6F09284AEF3ULL, 0xA8027FD142306B62ULL, 
            0xDEE65D2558C9012FULL, 0x35CD9F458F260728ULL, 0xADF824A08CF4DC49ULL, 0xC5A729D171E8B705ULL, 
            0x6896789AA29222F9ULL, 0x43D98C7B36BF8807ULL, 0xFDEECCF82D627B8BULL, 0xB489715CAF6B28A5ULL, 
            0x96BE2E1F88C8CD99ULL, 0x7386AB3AE362458EULL, 0xE3E427A11B5076C4ULL, 0x3D070A80F5476481ULL, 
            0x934493340275E4CAULL, 0x7A00FAB62CE08080ULL, 0x13324DFE4F7DF484ULL, 0xD03EAF429AC1C7D1ULL
        }
    },
    {
        {
            0x2C450F6DEC309036ULL, 0x0807B1E79B235C20ULL, 0x1663B93F3C153A28ULL, 0x426424082BBE8246ULL, 
            0x85938A016263FC84ULL, 0xC278BA8E2F9E1167ULL, 0x30415DBFDAD5F09CULL, 0x456613E86CB72D86ULL, 
            0xF6D7F86E75A0ED97ULL, 0x7DE44FC381884FCCULL, 0xC8479FBDCB1950E0ULL, 0xCF2B2F3DB4314A10ULL, 
            0x09ED91DE20EC80E0ULL, 0x87E713795345261CULL, 0x55B1414761521247ULL, 0x3A624CF30A44572CULL, 
            0x6476C167F873DA4AULL, 0x4FF64A0274768A22ULL, 0xEFAA42BCCECB993BULL, 0x06FED596729AACAFULL, 
            0x281BDE7ECC7D53A3ULL, 0x53147B905181CFA8ULL, 0x116F7D58F9516EE7ULL, 0x5758CCA8A5361356ULL, 
            0xE3D1C152DA3F9E84ULL, 0x7CC52BB9E057AE93ULL, 0x9EBCFCB58F430EFBULL, 0xFE033F12BD031851ULL, 
            0x96971F2159EF712BULL, 0x9C2C9B023A0A0A2EULL, 0xBE0978EEA6C3D774ULL, 0x0B7E2E449D85DE78ULL
        },
        {
            0xED18244DCBFDF9A0ULL, 0xA1A51053948BE2AFULL, 0x55D4556427977DD4ULL, 0x9BF7202A60DE906EULL, 
            0x8BD19BFC249C003FULL, 0xAE2693F85BD3F810ULL, 0x74CB49F42E98E8DDULL, 0x21FB96E91A711646ULL, 
            0x8FEA31BCA4E9A916ULL, 0x8F048C431FF29DE6ULL, 0x2A1A647F9C084DC3ULL, 0x336C76B32A74310FULL, 
            0xF2D46168FFA9A2E6ULL, 0x3EFAA8A952CA68A6ULL, 0xB4F5CE4900A756D1ULL, 0x1E803C59EF7F0F88ULL, 
            0xF9974F14CECAC287ULL, 0x5C17F41CB4D18C2DULL, 0xCC0147A22A1A9560ULL, 0xFD656F68332ABC26ULL, 
            0xB399F1148F9D4C9FULL, 0x667E6A4C66C308BEULL, 0xF6A5A46F006E26DAULL, 0xE548CD5FEF6C7353ULL, 
            0x79A41A449669E64CULL, 0xE56348F3A31D9C6CULL, 0x1CB1A77660251F6FULL, 0x78BE75B5FA36B4EEULL, 
            0x9C2EEEB4717B02F2ULL, 0x2644E8A48C474C80ULL, 0x11E06166ED9AC5E4ULL, 0x2765E6C7010F6AB9ULL
        },
        {
            0x9C0C065FAB7C7B4BULL, 0x68D2C26FF19C2FA3ULL, 0xD84A06CEDD4D7B1DULL, 0x94896C39E876E034ULL, 
            0x6ED938600BE675B8ULL, 0x75054CF0E07988B2ULL, 0x28F49635F6B4F2A7ULL, 0xF9FBC74CF93497FFULL, 
            0x08D98871FBB406B5ULL, 0xB313FC28FACFD469ULL, 0xCC6A9EAE307D8621ULL, 0x8DE48E38244B6CF5ULL, 
            0xB1C8FAC0CBCAD788ULL, 0x91CCEC2A7FC3D128ULL, 0x2AB929B2759CC882ULL, 0xF3A1D2733DCD4D31ULL, 
            0x04FA241F2465E6E4ULL, 0x2182CA6B191EA2BCULL, 0x804E71E06437490FULL, 0x171156830B8E1F68ULL, 
            0xD868B39E5B9A2152ULL, 0x35EABBA6565D450EULL, 0x7D5AB6064D7ED193ULL, 0xC4641E1FB18B0BC3ULL, 
            0xF91DC45F75832860ULL, 0x6BC5C309799300A3ULL, 0x16906CBCC4F48BE8ULL, 0xD43B5EB5E3542E7EULL, 
            0x5DEDF13C16DA6CD3ULL, 0x4AF8665F57C3F46CULL, 0x429925373025782AULL, 0xE58FA82778704861ULL
        },
        {
            0x33DBD1AAD8982AE2ULL, 0xFBDDA659B480E4C8ULL, 0x52C7E939C6FE6713ULL, 0xDBCAFD692C65A161ULL, 
            0xF2C3C0858CAB47F8ULL, 0xC99DAB1547217825ULL, 0x95AAADFC316A1885ULL, 0x7DD71625A913BA9BULL, 
            0x169742C9179ED8EAULL, 0xD3662300BFFDB713ULL, 0x2B14579D0B375860ULL, 0x646D9C05F2911C18ULL, 
            0x2394E8FED40983CEULL, 0xE090C5C16F21B292ULL, 0xAE2ED8EA00803ACEULL, 0x5EE00C8D7BA76E54ULL, 
            0xA3FC771A835A5E21ULL, 0x137443306AEEE8C7ULL, 0x9059DE253FD57E9EULL, 0x1A29704843C39B84ULL, 
            0xE0FE265F519E4528ULL, 0xE45E055952C4AB9CULL, 0xFF8B8BA7A95266F4ULL, 0xF90280791EFAD3F5ULL, 
            0x7E094C48A8D0F0D9ULL, 0x504293C5ABC03C96ULL, 0xBC118C994C1E297CULL, 0x2470A8AECE86DA31ULL, 
            0xF4BF73CFBFBC7EF4ULL, 0xF39E2B398FC1C93EULL, 0xBEB5B939BCC4580EULL, 0x81986CE9FE583F6CULL
        },
        {
            0x7005A1068511E45FULL, 0xE53B079FAB9266ADULL, 0x36BC0E3D586F7AB5ULL, 0x537A03CD53DE49DCULL, 
            0x4A29957B98EA1835ULL, 0x32F3AB3610203FF9ULL, 0xF6455B29EA35AB9DULL, 0x47D39E4BBF1D00BCULL, 
            0xC641692C897FC29CULL, 0x398FFFF951CD3640ULL, 0xBEAD8E99D7504FB0ULL, 0x1DA93DEAD3DE494AULL, 
            0x760212DF88FD1997ULL, 0xCF598876617D5937ULL, 0xA6B9C9C3516AE8E1ULL, 0xC0A9B0940EE98E34ULL, 
            0x6F798A7EE260FAFAULL, 0x70A6C9BAA0135C9AULL, 0x953D5E1E63052CCEULL, 0x78D48FDA11039356ULL, 
            0x1A70E9C9021392B8ULL, 0x0D723DCC5B7FB309ULL, 0xD9A82B097DADDE57ULL, 0x386680FA64E627C5ULL, 
            0xED55BD2331092C71ULL, 0x5548BCBB3D4E0E7EULL, 0xE3CB694C4B703095ULL, 0xBF475885BD66CBC5ULL, 
            0x368FC0AB89CC95AFULL, 0xCECD7AFCD71BA314ULL, 0x2CDDBA19699EDB5DULL, 0x9504570E07A35BA4ULL
        },
        {
            0xF174DCC2AC55BBAAULL, 0x9C4F4C0C824E4529ULL, 0x96DE30FA0EA2490DULL, 0x755DD48E8B67E6DAULL, 
            0x5A375C0D87AD09AAULL, 0xBA64D9D0F324EFC3ULL, 0x9630B51BF5B138C3ULL, 0xEBC4D3D08DEC0DCEULL, 
            0x7D7C8C71574FB0DDULL, 0x97A421AD7F018971ULL, 0x3A7B925EB6D011B8ULL, 0x9E19AB8309C40089ULL, 
            0xD407A8C7AE4DB3D4ULL, 0xCDD58369B3FAC0BAULL, 0xA9D02300D07430DDULL, 0xC88CF7F93EDF9FB1ULL, 
            0xFA7965DE9258A073ULL, 0xCCE09B96584E5C14ULL, 0xC67F77C49DB7C610ULL, 0xF048BEB174C3CB0FULL, 
            0xD8635FFDF1D46B95ULL, 0xA67D4C60B0D042F5ULL, 0xD3BF44AA5787295DULL, 0xA997D4E2C22C083BULL, 
            0x0AEE053E6E2CEFEDULL, 0x5FAF13A4B9CA2239ULL, 0xD77318778018969CULL, 0x478F67E951220BA9ULL, 
            0xE2CEF14E0A771813ULL, 0xF835921C360E4B3AULL, 0x48928C2BF27F5782ULL, 0xAE60AD7820DF517DULL
        }
    },
    {
        {
            0x34596BC47430B921ULL, 0x58901ACF68EBF4FDULL, 0x2B155409665084EFULL, 0x0472E277FC929D97ULL, 
            0xA5D84D3B0742DFB7ULL, 0x2C7A81B5DD93252CULL, 0x4A4B5A5E63635069ULL, 0xCA7371536877520CULL, 
            0x5E15D00F94A15145ULL, 0xD3633FBAFB8E462AULL, 0x5B9D7C05C5C924D8ULL, 0xEE240C6D7527E90BULL, 
            0x65EBA47E03F92AB5ULL, 0x2A7AD3346717A73FULL, 0x4E9F188F1E907E85ULL, 0x9B1B5E09E5412E65ULL, 
            0xBAA2A5EC6035543FULL, 0x64FC9CCA9DF7234EULL, 0x9B4F2AB9D2E4F932ULL, 0x95E5C651F1BA5E1CULL, 
            0x8D15A6362C727B36ULL, 0x43934B5315EA37EDULL, 0xEDE0DD77472CE1FBULL, 0x1FBF211008C4CA0EULL, 
            0x6FF97C16D1152650ULL, 0x4B939AAC44B11942ULL, 0x6A99DC0E1EDC8642ULL, 0xFFC1BC9536AB3F8AULL, 
            0x36E5024765BF74E7ULL, 0x624167E1EAE6BB5EULL, 0x579C501CD356FB4FULL, 0xB2F134565555249EULL
        },
        {
            0xD843922AF86D3B7AULL, 0x81D0DE63D37DAE45ULL, 0xEFDDDD9D901807D6ULL, 0x79F3CD87575CD667ULL, 
            0xD2CFF811D8B06316ULL, 0x5FED276ED0662A4AULL, 0x55727BD158A17414ULL, 0xB8722C8DBC0BC064ULL, 
            0x946FC535269AF702ULL, 0x7DC224AE7C1AE5F3ULL, 0xC0FA623B49A79E83ULL, 0x5915A86E588557E9ULL, 
            0x7A0EF2E0E0EE53ADULL, 0x9FAA88219E9D8D34ULL, 0x9D122C065BC3FB85ULL, 0x57FFF406BF4CFD2BULL, 
            0x60D814C788CAD165ULL, 0x711196326CD51CDAULL, 0xBD1F6209F52D63C0ULL, 0x7B6E66FDDEAC4F0AULL, 
            0x7DC3E7AFD3356750ULL, 0x08F71F186270672AULL, 0x4B1E7DEAA74D7C86ULL, 0xA07CB29BF9F1A585ULL, 
            0xF473E2085D2B41F7ULL, 0x736D06B4AFC1BA82ULL, 0x879EF19BC5D94469ULL, 0xAD0D6C495511ACCEULL, 
            0x606FDC88079B5A55ULL, 0xBF4880437B04CC86ULL, 0x10FF7FDF6975DD09ULL, 0xBDD24D46912424EBULL
        },
        {
            0xAA67BE13221C1342ULL, 0x37BC146C666C44AFULL, 0x222DAFC033E7934FULL, 0x4B6CDB0AB0F1EA7AULL, 
            0x5F2FA684F1BF24DFULL, 0x91ABEB9699BC9B74ULL, 0x84ECFD15C4C3BB44ULL, 0x1DE027F1ACA3FA68ULL, 
            0x01F34790F47D1B3BULL, 0x3AA29ED34A4FB776ULL, 0x4E0BC203F284A6FFULL, 0x3C9892AF2D1819B9ULL, 
            0x17A3B68A643DF21EULL, 0xA4540A3AC4B14EA1ULL, 0xB220DF98FD5380EEULL, 0xF0BB772EA3940458ULL, 
            0xF4D4CBBAEFAD0F47ULL, 0x52BD4D07E7E35AC4ULL, 0x5ACFC96B8D238AA7ULL, 0x992CE6E2C1F574A8ULL, 
            0x00B5A54E28609BAAULL, 0x1DD90D27294216F1ULL, 0x30E5E6D9901139B5ULL, 0x43471DA23043E4C1ULL, 
            0x02E8451F6AE7665FULL, 0xB611FD3A80D05D71ULL, 0x3E6AAAF54A07CF4BULL, 0xCAB742346BE30EC3ULL, 
            0x8D7EF381AC3437C7ULL, 0x5B3CB2F8C85AE4EEULL, 0x889B7C3C2D74B319ULL, 0x84B8EA8C0360CC85ULL
        },
        {
            0xB35D800E2BB018B3ULL, 0xC84B8FFB5356C3ECULL, 0xCD6DC2220747EE82ULL, 0xB991694A6FAFFC53ULL, 
            0xD33D0E5A4B868C56ULL, 0x82C0BD6F8B4D1419ULL, 0x71352EA0ECAC62CFULL, 0x49FBA92D62348AE9ULL, 
            0xA2BF9807FB63EDF0ULL, 0xB16A73BDD58D5051ULL, 0xDE63007F5079BA95ULL, 0x3ABC9F389000FF33ULL, 
            0x93BF3E2215D5B187ULL, 0x7C9CDC832C0306D1ULL, 0x5EF2C32992191D18ULL, 0x265AEDB2F5459995ULL, 
            0xD82D0B1068ED4C9AULL, 0xCDF196EF59DF2447ULL, 0x6204F45F2B4DCB17ULL, 0x855C0917E99EC60EULL, 
            0x10825E816073196BULL, 0xD84CD99CDBEC203FULL, 0x2D0BAEFBFD023A42ULL, 0x908423EDD8B65019ULL, 
            0xEDC13EFC59D3A51BULL, 0xD993813DFFD84FC4ULL, 0x97B11F459DEBF834ULL, 0x0D16D14323D96CD3ULL, 
            0xBEFF20477A5C994AULL, 0x3AB3D914AFA87645ULL, 0x5BF888671EC9A644ULL, 0xCA202CE094765D5AULL
        },
        {
            0x1109712411276EC0ULL, 0x17F7A088718EDC23ULL, 0x34C427D52139266FULL, 0xC23ED514B39A4213ULL, 
            0xED73ACE9EB48CF35ULL, 0xE8B5C7AD77CF2AF9ULL, 0xC08F9BDEEE0AA3E2ULL, 0x945ED48C868CD803ULL, 
            0x6EA466BDE776A067ULL, 0x426EDF805D3249EFULL, 0x41558B8564C2F3DEULL, 0x547337F3C3379B81ULL, 
            0x6F15C123B83552D4ULL, 0x229E315930A42C63ULL, 0x6F878C8FCAB4B3F4ULL, 0xEA492D2543EDBECAULL, 
            0xA8E6B3A11C00972FULL, 0xE01278FC9B95744EULL, 0x692FA522A5824BCCULL, 0x3400377258E6278CULL, 
            0xB4C3C79D144061C5ULL, 0x9B14B8E754C56E90ULL, 0x7AC3A637DE8689C1ULL, 0x17BB27379C90ABC1ULL, 
            0xDC5E66CEB4F40964ULL, 0xF6947C7716DC6D90ULL, 0xF413BB280753575AULL, 0xCE3BAF573CAEB1BCULL, 
            0xDABDC5913C64C785ULL, 0xE140EFF7FDA9FB8EULL, 0xFB83FB8B56FF3E76ULL, 0xCB8F10E685C9AD31ULL
        },
        {
            0x3EB8BCA06F5DB79FULL, 0xD1EF55014808C85DULL, 0xEC7DCF532FF7587CULL, 0x8E178D3FA31E3605ULL, 
            0x5B5F86C0535BF210ULL, 0x523E62017A1F7C6EULL, 0x822A196B0AA3D17EULL, 0x7F93F1EB0860FA37ULL, 
            0x79E63444A3D5A4D8ULL, 0xB59A6CB24CB0A599ULL, 0x68284614D9636F17ULL, 0x501ED08AA3E609BFULL, 
            0xD76CAA7ACF058890ULL, 0xEDC4888EE3D807A6ULL, 0xB42F0C8AAB31C3FBULL, 0x5440961948F46782ULL, 
            0x1E5BFA7116C251DBULL, 0xBC7E9D28C1E9561FULL, 0x0837929BDDF794DDULL, 0x73FB45F0C567A555ULL, 
            0x7604698A618B3C5EULL, 0x99D398FEFF9DB0CAULL, 0xD01EFE77A46A2013ULL, 0xD4E1501CF1F03327ULL, 
            0xA18EF2F9D77F693EULL, 0x344B56360812DB7CULL, 0x7EA562F3B0E1F6EEULL, 0x51B328CB558EB152ULL, 
            0x17A4B9DAAA8403C1ULL, 0x364FC9E654A17C2FULL, 0xB149F963A24F0E71ULL, 0xAC09E01D84723E85ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseGConstants = {
    0x3CF40587E62C6D01ULL,
    0xADEE0C02A96998B6ULL,
    0x3BA6CDFD0AD818DDULL,
    0x3CF40587E62C6D01ULL,
    0xADEE0C02A96998B6ULL,
    0x3BA6CDFD0AD818DDULL,
    0x14E78DA52E15F246ULL,
    0x8A10C9280210B92FULL,
    0x79,
    0x83,
    0xDA,
    0xCE,
    0x34,
    0x0A,
    0x89,
    0xEF
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseHSalts = {
    {
        {
            0x547882FF1B959382ULL, 0x375D8BECEE33F442ULL, 0xB69F75562E7725EEULL, 0x16DD9A67264B80ACULL, 
            0x3F422D95C9C1A634ULL, 0x53DFBA26E127BC2CULL, 0x63CA0F3164BD3B2AULL, 0x7319BA33CDDE15E8ULL, 
            0x5D2CA10ABD3CA5C0ULL, 0xA31BB76BE2A14C98ULL, 0x9474B9AE98C4B510ULL, 0x6D9EEB2C93E66019ULL, 
            0xB95C80EAA56ACCB8ULL, 0xB46EAFA7005B56C3ULL, 0x27D27DE45A3ADD85ULL, 0x29341FBA9B861E2BULL, 
            0xDD438EA94DBB6FA6ULL, 0xEEA43EDB87E652DBULL, 0x80D7E67715A13F9AULL, 0xA5CBB25D6E292050ULL, 
            0x9ECDFF63C7F46F2BULL, 0x5CED04514C10B59BULL, 0x3B38F3A8130BE3C2ULL, 0x8BD6FA08CEFA6F93ULL, 
            0x58EB868D7E68E529ULL, 0xADA67D3846DFD41BULL, 0x5943E23049713759ULL, 0x497065595DF03128ULL, 
            0x6B997F3B99075528ULL, 0x81B12098EE88F961ULL, 0xA509480B7A3409B2ULL, 0xED3ED688FEEC2D8CULL
        },
        {
            0x376FAF75642AAE96ULL, 0x9A0F3BAFD33D0AF9ULL, 0x0154212F329ED8B7ULL, 0xD0D67A94ADC2A0EAULL, 
            0x76259AA16C77B5F1ULL, 0xB72CA9B0B4882E8FULL, 0xFF8F9D4AA86730F6ULL, 0xC294F8346D57F427ULL, 
            0x76A42FBF910F465FULL, 0xC3FACAB3CCBD3E19ULL, 0x61150D7FA473B77BULL, 0x184D5F79CDEC2597ULL, 
            0x3AAC740F609FC96BULL, 0xAAA986D97BAAB307ULL, 0x85D94307B2775056ULL, 0x688ED81B31BD73BEULL, 
            0x751CC8545EAAB34DULL, 0xBFD1EB0D3ABE49E8ULL, 0x34BCAA1B6DF4C987ULL, 0x84E814DEDC2EDE02ULL, 
            0x70D5F3A378BC9DF4ULL, 0xFA0556096BBE14C0ULL, 0xFAE4EDA2CB3C98E8ULL, 0x646B75679801A91BULL, 
            0x6315CE59F97E2796ULL, 0x41F13E4A8C36BF99ULL, 0xB0A225117FD9B277ULL, 0xD3192880CDE07044ULL, 
            0xDA117431EEE8B3ADULL, 0x36B77A4943C4EEBEULL, 0x6361CFF1783F57D0ULL, 0x20C6D98DCA7930C7ULL
        },
        {
            0x3F756B06D2EF7121ULL, 0x0937C223C8AFD059ULL, 0x48DE6E07DDA4FC52ULL, 0x095787A82B755BB7ULL, 
            0x650A9D3757A09B3DULL, 0x5F79A99A7CC61DFAULL, 0xFE7CE273D8A75976ULL, 0x307A0A79A98B0F68ULL, 
            0x8CEAD20E4A39B848ULL, 0xB0CBD6347A1216EEULL, 0xFD2A4FC908637EF6ULL, 0xDB49A2DE04BBAAE4ULL, 
            0xAA5954B056A7F8CFULL, 0xB7FE36474B3B59D9ULL, 0xB94F81DCC4781F9EULL, 0xB91055CCCFACEF7CULL, 
            0x30C4BA32108E9859ULL, 0x0494BBEDE07CC2DCULL, 0xFB4FD61C8ACB88A4ULL, 0xD03BEF29CCD56C85ULL, 
            0x383C889AEB350A0FULL, 0xAE1FEB8ACED87D0FULL, 0x331228CEF212BC92ULL, 0xD864C966C0F392BFULL, 
            0xEACF8787784F2DE4ULL, 0x51034F954BB6BDF5ULL, 0xAABC82722833CDF2ULL, 0x0C784C53FD1AF7E7ULL, 
            0x39753C81BC10DF7FULL, 0x4F28484EFD926A7FULL, 0x47808D875C2440D2ULL, 0x0E8078ECC0745C3BULL
        },
        {
            0xDE143D4997A58B43ULL, 0x12C01BCC732B329DULL, 0x03BAE2E862EAB25BULL, 0x2D6589AB38435325ULL, 
            0xBE504DCF4ED9410CULL, 0x93933B680D2E5440ULL, 0x8246E72EFF4A55A8ULL, 0x56C0D22D4ABCE562ULL, 
            0x8186B28A346620FAULL, 0xDFBA2DA58E6E3E5DULL, 0xFD07BB545AEA8F2AULL, 0x8C21C3D6AA073698ULL, 
            0x6ECBE811F2A6EB08ULL, 0xF8C1EB59A59AA03EULL, 0x1A722184032299C5ULL, 0xECC6D0295347FAC1ULL, 
            0xFAF3D41BF50BD076ULL, 0x89ADC212DB6E4A10ULL, 0x0A812EF657B0EFCCULL, 0x15846153E451A475ULL, 
            0x9CF444CF2B6C42E0ULL, 0xA438B74BBEF64467ULL, 0x01A83B0A8C2EE113ULL, 0xEC022C77D234627BULL, 
            0x444E907B9F1C64FBULL, 0x3045CABFDB902CF5ULL, 0x8AD755C0517759A1ULL, 0x6ADED5D7CEF8E2C4ULL, 
            0x9AF536E3A999B6AFULL, 0x4AD7DCC4EF19BE6BULL, 0xFB3C9B31126A1C71ULL, 0xB940D51EEA424E6CULL
        },
        {
            0x19305039C2D49CF8ULL, 0x06C9DDDD369B1AAAULL, 0xBF61EEB3D96EB6CAULL, 0x71F13377AE3CB496ULL, 
            0xFF78653904E326E2ULL, 0xF3D777D7A6D4CCC9ULL, 0xD6802E491B6DBE78ULL, 0xD649EAE7FEEAE3E1ULL, 
            0xFEBE355048218788ULL, 0xC35CA4F7B9AC3727ULL, 0xB472CFDEEB76265BULL, 0x712A26927518F46BULL, 
            0xF5A1E018AE5619E7ULL, 0x05509B7BEA2C5283ULL, 0xBDB0D13B921F4CCEULL, 0x438D0834764FC0A0ULL, 
            0x22E97DD5FFA4B0E6ULL, 0xEF9F774F153B9B45ULL, 0xA1A0030FF9809789ULL, 0x87ECC26CB409353CULL, 
            0x5B546B6C9B0D74C6ULL, 0x0660FC487FB6BA53ULL, 0x972D09AC728325DCULL, 0x48AE7185084C11D0ULL, 
            0x8185D6C39EFCAE46ULL, 0xB25AFAB9022D4E30ULL, 0x994878EACB22F6B7ULL, 0xE2EBC85ED8C0AAE8ULL, 
            0xBE4C78EF483D4662ULL, 0xD15081AB6B1C4D96ULL, 0x6E3063C7125075B2ULL, 0x341430E1C6573F16ULL
        },
        {
            0xA9FBF7080CB122F8ULL, 0x0964C728992AE5A7ULL, 0xE47DF7C419E08ABDULL, 0xFEF3E86AEE78495BULL, 
            0xC756AD72E2F507EBULL, 0x2393375BB7CF3970ULL, 0x88603C020AC02129ULL, 0xAF54491F7FB6B9EAULL, 
            0xEB03755195545BC5ULL, 0xE3136E981CE04627ULL, 0xF397391ACB744955ULL, 0x8FFD51DA1F20AA39ULL, 
            0xE375CD8FA0042A95ULL, 0x71F4376EB1A7A011ULL, 0x665BE340D14C9B24ULL, 0x1709967E885F7A36ULL, 
            0xE44BD4B4D93061FCULL, 0x4CE8511F3D900EC1ULL, 0x556AE37A05D54E31ULL, 0xC6A4BA6C07CAC8B7ULL, 
            0x3D6E14D0B6741631ULL, 0x2622CDBCAA2E3110ULL, 0x169940E88FFC5C5BULL, 0x156F308A2E932D7DULL, 
            0xC87B097ECDC43055ULL, 0x0F98FB6CC90B8300ULL, 0xBF9B700D6CB6B4E6ULL, 0x4CB4F9B628971C46ULL, 
            0x574A024C10C12CB9ULL, 0x936B42BA6E86C695ULL, 0x04C5E10E9030F1B9ULL, 0xB2DC04865DB80700ULL
        }
    },
    {
        {
            0x372CD88C851C590FULL, 0x9D7339CFEE6D94A0ULL, 0x0826F40AC1303D68ULL, 0x89DBAEE44980B1E8ULL, 
            0xA55F3882ACE5EA64ULL, 0xC480A39D74892572ULL, 0x93EFEBA77C139AEFULL, 0xB8844C57C59099D1ULL, 
            0x04344A773D4DC246ULL, 0xA79573C41F74AD7AULL, 0x6C8A6B6C93BA0EB2ULL, 0x42B89953D328D0D4ULL, 
            0xB18ECAB03DFF3349ULL, 0x7CD9C6EC5D892801ULL, 0xD85CA1FF0DC6C476ULL, 0x00EF18EBCA0CDDB0ULL, 
            0xC6158E5C7E7B5CBCULL, 0x1B65BFA72C08B10FULL, 0xF5B819C824F1FDCBULL, 0xD64EFB0AAF334A54ULL, 
            0xE6D005575E59A5AFULL, 0x04296D68A81C95CBULL, 0xC2FBB53D376C2E95ULL, 0xB2246A2829B2397CULL, 
            0xE95F567E4B766901ULL, 0x874CEA1E6BC748D3ULL, 0xFA7FD328A97E962BULL, 0x258571F2ED0CA739ULL, 
            0x597FD0C39E240614ULL, 0x0C730103F2C1330EULL, 0x6F0DD3F7607381F9ULL, 0x01A0F0E5D654716AULL
        },
        {
            0x21A49495A8DFCEB9ULL, 0x3587242A9ADED994ULL, 0xC97192736515C688ULL, 0xF3A8CF06FB264237ULL, 
            0x8B290D46462C1DEDULL, 0x978307417B60A79AULL, 0x4C05525CA615FBBDULL, 0x55C8C995EC073D15ULL, 
            0x8279C4CF4A93DE26ULL, 0xF9BC64C077D7BE52ULL, 0x33D2F0DB7DE2CD1BULL, 0xDF562D7B2A8D7AA3ULL, 
            0x5124CE293DB88D2EULL, 0xA39045D95A520FC8ULL, 0x76A4D4C127D13CBEULL, 0x5EB1A46314F1033AULL, 
            0xB8C31BCEED0311D1ULL, 0xCDBFFF7382C3AA5FULL, 0x4584198209D2034EULL, 0xB93568CDAC9866E9ULL, 
            0x241772FCF41DA458ULL, 0xF230399EC7B28D2DULL, 0x6E5BB331E0E7E345ULL, 0x4AB76D61D850D65DULL, 
            0xB8847B110ED41D7AULL, 0xAF811922092AD9E6ULL, 0x2D649954B7CEDDD3ULL, 0xDA95C9C6EA0FE2F2ULL, 
            0xBEDB3F145D3CFDA6ULL, 0xAAB45476307FB070ULL, 0x2FD8EBAB7EAD63E2ULL, 0x83AA369CE4581205ULL
        },
        {
            0x68FBF6936115B1C0ULL, 0xF25B4AB7D061D8A0ULL, 0x7B0ADB962BA3396DULL, 0x84D922C8D1791E42ULL, 
            0x9B852B76F3B64B63ULL, 0x13264F6561F2F699ULL, 0x636C4EBBAC14450BULL, 0x4D0E53FADB0D8A25ULL, 
            0x9DD5D68DAA5BC5C4ULL, 0xC267DA551E0D9D86ULL, 0x987A22A833B2C87CULL, 0xEB0E654BCD23CD09ULL, 
            0x05C8B2498DD43667ULL, 0xDA7C0A52B0A273BAULL, 0x13E0630F5018E384ULL, 0xC7B0FDEF4C1097F5ULL, 
            0xB516EB24C74F3263ULL, 0x03B7BA9DC3674426ULL, 0x2E0AAFD523E30AE4ULL, 0x9FC6EC2860B02B45ULL, 
            0x4B99C9329A84F891ULL, 0x73F73163BBA97C1AULL, 0xAC723BAE6832E796ULL, 0x04877A472243C30CULL, 
            0xF164E05977DF0B67ULL, 0x96A9A8B19985961CULL, 0x4552488AEC50ADBAULL, 0xBCDC3C1BF68E80DBULL, 
            0x2EEE6E06125720BEULL, 0x0B23741D06DE9F2BULL, 0xB78565B109DDB7E3ULL, 0xAE8538AF5164EDCAULL
        },
        {
            0x1250A214ED74A247ULL, 0x8EABD84CE46D30DEULL, 0x8A33E354380BC021ULL, 0xF0673D3EEA8E8130ULL, 
            0xFBC3D1AFC7883F58ULL, 0xF4FF29D73DB97885ULL, 0x25058D3A2EDD5661ULL, 0x313EA6C5D9CC7FC6ULL, 
            0xF48E95D3A7B4DD4BULL, 0x39BC19B2E2729AFDULL, 0x5F90051FF317690DULL, 0x7C49FD2E89463DCFULL, 
            0x822A08BA05326B70ULL, 0xAE7D01DB56CF7CBBULL, 0x43821D573730E195ULL, 0x1A8BEF0D11FCDA37ULL, 
            0xEF014A7A99FCA9B1ULL, 0xF1D6028B8B642A8EULL, 0x5A0C2007E9DBA3C0ULL, 0xE03E0A54B3FD5D4BULL, 
            0x5E7DF3ABB3652D6AULL, 0x487FBF756E613C71ULL, 0xFC61EDB511534384ULL, 0x76AFB158527F2A29ULL, 
            0x84BC1033C1347551ULL, 0x66BF8679497B4709ULL, 0x3FB4C7A3E18A4FD5ULL, 0x861006148C4878A6ULL, 
            0xDC20BF87AC6AEA1CULL, 0x5115901AED2CBB79ULL, 0x83D5BBB3886F8BA2ULL, 0x450DCFC4E64B8B32ULL
        },
        {
            0xDE1313B093C1D046ULL, 0xA52F542F685FCCD5ULL, 0xBB0E98EF023A5171ULL, 0x6971CB46D1E4EB68ULL, 
            0x74A92039631C291DULL, 0xD001F1CCC4CDF80AULL, 0x2F81999AD943A785ULL, 0x76908FA9915DDDDFULL, 
            0x4BF24B7989C47394ULL, 0x388E8FE19CA767E9ULL, 0x5F1B5512E79E8642ULL, 0x42031D7730BF20F0ULL, 
            0xB1BD24405FF45F55ULL, 0xB0D0EE30443BEBADULL, 0xAAF0FC84783E733FULL, 0x80B4EB955F88BA75ULL, 
            0xEA2734599EE31230ULL, 0x7F0C61EF6050749BULL, 0x1D3372C3EFFDD578ULL, 0x9A6ABE0E14EAAC15ULL, 
            0xB13AECFB6C776364ULL, 0x617ABA371C8FFD67ULL, 0xF94CB493BC626503ULL, 0x68EC1A44D5DFD9D1ULL, 
            0xE1B460FF22004EF8ULL, 0x3D8249944B32AB9AULL, 0xDFEFDBD2D87CD420ULL, 0x7AC91B3E2C99494EULL, 
            0xFA8D28CF14C58F53ULL, 0xDC4D7A608502E82CULL, 0x4F1C8F0DA9D5AE76ULL, 0x6596E214304EC238ULL
        },
        {
            0x82FCA88A34FA5D03ULL, 0x32B4923F8D372F98ULL, 0x1051B4AFEF307E89ULL, 0x059634272C375ADCULL, 
            0x8F2327C072AF17F3ULL, 0x871DDEEB1E0BA1FBULL, 0xD1E7A256E2668E63ULL, 0x16E815497BAEF580ULL, 
            0xCF4732A6019D1972ULL, 0x45546BDF7A3B8E07ULL, 0x67F3D9D0428BA32DULL, 0x315109642EF821BCULL, 
            0x934675C97F27AA9BULL, 0xF84495BB331343D5ULL, 0xCB51039E4841318FULL, 0x32464EDD35153D48ULL, 
            0x699D5F771047CCB3ULL, 0x57A9259C14F9BA17ULL, 0x40AB922469DF8D55ULL, 0xB845970FAE8AB2A5ULL, 
            0x2CF6DFE1374E9AE6ULL, 0xADC5A7E33CDFA70FULL, 0xB86471C5C1A78B42ULL, 0xC06BB802C725857EULL, 
            0x142C54F25F07C5DEULL, 0x983AA51E254729C7ULL, 0x56EFC1110A61F919ULL, 0xF9973AFB663A1B8BULL, 
            0x9003B8B427E6FDB1ULL, 0xEAEEA873748E46D2ULL, 0xA0DDDF8FA271C467ULL, 0x96FA0F4CD076C0E0ULL
        }
    },
    {
        {
            0x4C2A95E68AF42184ULL, 0x0E1E87A5FD4D0649ULL, 0x2EEF481629636688ULL, 0x672C92858FB7B6D0ULL, 
            0x4D174AB281B6A765ULL, 0x0FAE474295B21229ULL, 0x3DE3DDEF056F5CDAULL, 0xCEE1CA6B64CA952FULL, 
            0x9E6CCAC37748D678ULL, 0xB9018B99629D10F7ULL, 0x98EC922BA88B8A35ULL, 0x54C8FEB02E133353ULL, 
            0x06BB2449FEF676E6ULL, 0x0C20E46609A83570ULL, 0xF75A18D87B28AB5CULL, 0x82203EEC6D7F4A86ULL, 
            0x41A8058A4E290E98ULL, 0x346081DD90F83D9FULL, 0xE33C8A49C6235067ULL, 0x5AA9D56065FCCC49ULL, 
            0xC2F29FBED98C697DULL, 0xC2E659143D2C0441ULL, 0x1914157908E2077AULL, 0x78C4155D916015D6ULL, 
            0x1841DD6ED7006E35ULL, 0xCBC1561715299A73ULL, 0xBA47E3A1D4E416B2ULL, 0x5D4157D407767272ULL, 
            0xE460596D6E457702ULL, 0xA178FA0B88B00F75ULL, 0xF76648393B670860ULL, 0x0B00147C64AB0DCFULL
        },
        {
            0x9A65DBA664AD6506ULL, 0x5D922E9655866C5EULL, 0x917717404F44E51BULL, 0xAE5A567D8CEE3B44ULL, 
            0x86FF240DE6B08C67ULL, 0x7015A827CCE854F4ULL, 0x7D984B1D4AE824E3ULL, 0x3683C576386B422EULL, 
            0x53E4791B41A456D7ULL, 0xD94A610759ED14DDULL, 0x72E3DDF14918F482ULL, 0x51D0A7D0D044F212ULL, 
            0x9E2F22D11490601BULL, 0x1AF663C08D23FE0DULL, 0x1F3F9386F7C98752ULL, 0xD8D81FCFAEB56ADFULL, 
            0x953B0C309A5191C6ULL, 0x273786C2AC49B210ULL, 0x4784C729E09E2848ULL, 0xDCF7F0C36D53CFB4ULL, 
            0x45179BE425B76D91ULL, 0xD9A871FC50A989C0ULL, 0xBFB20C16E462FA42ULL, 0xA5149C09EFA9D90FULL, 
            0xE0B2B4F60DDB2957ULL, 0x39627A6E389BD5E8ULL, 0x49B2F9C41C930624ULL, 0x3AC9097D3EE10AA9ULL, 
            0x64E6B8CC963C7865ULL, 0x18EDE575742E6707ULL, 0x21BE4BE8FC401DDFULL, 0xE347BD759231A0B5ULL
        },
        {
            0x7C332493E3413086ULL, 0xAC0D1953D92BD7F9ULL, 0xD0175E53DF954620ULL, 0xC4BB1C5875FDE753ULL, 
            0x082E397AFEDAAF16ULL, 0xD169791F10A0ED0FULL, 0xA1A5D19FE4900913ULL, 0xEA75FF9B6856D1F7ULL, 
            0x95E5AD1AEA558D53ULL, 0xF2ECD77B04D1A7A6ULL, 0x1AE9BF8D588285E3ULL, 0x73730EAE4AEAA0EAULL, 
            0x0926A4FB8A5ACB05ULL, 0xAC37B1FA1D7B07D9ULL, 0x3BD0B32832CD1088ULL, 0xDFB8F7B9326E5158ULL, 
            0x81C188B62A259417ULL, 0x7D0C675D8CDD1F18ULL, 0x5AA9DABEFF21AA4DULL, 0xC162322257ECF9C2ULL, 
            0x7BAC3DC3CDB74303ULL, 0x8D1719ABC3CB714DULL, 0x99715E02AFFE0B65ULL, 0x98AB5F04663D6EDFULL, 
            0xA3283C1384C8C306ULL, 0xFF40C3D32B2C4E16ULL, 0x606F25D293C6E5D3ULL, 0x8D99C28BB695EDE2ULL, 
            0xBBF662C733D1D539ULL, 0xBAA007F6CFA6E249ULL, 0x4EE2F5C40CE14B53ULL, 0x3C7CFA54737490E6ULL
        },
        {
            0x6BFD6722BB2AD018ULL, 0xE257B00CC4433431ULL, 0x53FCDCE045AC9F08ULL, 0x65328E1F11BBA0DFULL, 
            0xCEBA831290FF1582ULL, 0x59AC50C542D2648BULL, 0xE4894D60C345D178ULL, 0x4CBC468FC427B780ULL, 
            0x8E6CBFD60484CC8AULL, 0x17145EE10BA22BB3ULL, 0x3DF8C5579EF92186ULL, 0xFF6BDC7D8F80CD9AULL, 
            0x5A9010D661C4E8D5ULL, 0x050AA3E55C0696C6ULL, 0x7BC58D1BAD675051ULL, 0xFAE304B11077B274ULL, 
            0xA83B548AEB58B756ULL, 0x4986128AE9C10D39ULL, 0xA9CFBD15149798C6ULL, 0x24385C2760096B11ULL, 
            0xD8C637CE17CFB3C8ULL, 0x0BF6F7B1604B0C13ULL, 0x25792B8802992DBAULL, 0xAAD342FFEDB584E0ULL, 
            0xC2D0D2D1E19411AEULL, 0xCEB2B37EA502AFD0ULL, 0xEE70D45B1859C465ULL, 0xCDA2F210E4E9BC2AULL, 
            0x242FD603C2FE6B0FULL, 0x97EF8E6C812E0C7BULL, 0x51AB98F3AA48FF49ULL, 0xF27DA5E255115D8AULL
        },
        {
            0x7F804867A97B5F07ULL, 0xF18DDC7FFAEC7DF4ULL, 0xDDC95F21DF3A803BULL, 0x68D0C6FA36A1EE21ULL, 
            0xFE42F432A591F860ULL, 0x0CF6220B045B2F8CULL, 0xEBF1226496CCFD37ULL, 0x1A741227709A9F1EULL, 
            0xCA2CDCC28DABE6E1ULL, 0x2C6FE1B4CBB7A14FULL, 0x02C27D5539D60F33ULL, 0xBE05637563BCDFD0ULL, 
            0x0BD947EF94265D3BULL, 0x99C2F3BA69B41174ULL, 0x8F240DAEB361BE47ULL, 0x1B643D694C4C1761ULL, 
            0x5FA877D41D2DBB8BULL, 0x1CCC4272896AD6A8ULL, 0x090DD62FB7175D9AULL, 0x064BD948E71ED219ULL, 
            0xC5572477FCAC9BC3ULL, 0x745A89824367C1C4ULL, 0x7430DB4A2E9BDF2AULL, 0xAD31595B0AD3770AULL, 
            0x3BBCD2B1EC6FCDC2ULL, 0x8647A38BBC25CD16ULL, 0x66A86CDAD29A0AE1ULL, 0x3EC94697AC673BF1ULL, 
            0xD35FE9CDF51348C5ULL, 0x3FD62B95080CA2DCULL, 0xC7B5106E01A1D0B4ULL, 0x68370F65C4B925B1ULL
        },
        {
            0x19D8ACD90FCD6B5FULL, 0x2837807462DB663BULL, 0x239AF5EAA5490A16ULL, 0xB4334B379A50CE77ULL, 
            0x71A372179C3365C7ULL, 0x66B01E661A594991ULL, 0xB40C3A0B075F7AE9ULL, 0xABFD71C5A3CCE0B3ULL, 
            0x7BA9151610A822DEULL, 0x200423F732725FCCULL, 0x3D3FD65679A5A731ULL, 0x9DBD98696017B681ULL, 
            0xB5D394B95E2D9F8AULL, 0xDC0266CD6917084CULL, 0xF53C73FAC5115FBDULL, 0x95629FEFD8D210D1ULL, 
            0xF1C6A40C9B5981E1ULL, 0xC68509CA8C1B8D2DULL, 0x51B89660208AE36EULL, 0x3A60495143DCEC08ULL, 
            0xC906A4FB6D08F8AEULL, 0x6156E79498AAB866ULL, 0xD4C8621186B5A370ULL, 0xBD54F6260926DFD3ULL, 
            0xA5314B2D4528776AULL, 0x69E97836A1752DB2ULL, 0xB37D5414F52D3B4CULL, 0xF8C9302C123495F5ULL, 
            0x6B75128B0A6887E5ULL, 0x6F5E16972F2FD9D3ULL, 0x51E0848FB0EBC298ULL, 0x26D01807A9DD92F5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseHConstants = {
    0x81F675702AC40D22ULL,
    0xF102360341D5E297ULL,
    0x153C3DF4746A7AC8ULL,
    0x81F675702AC40D22ULL,
    0xF102360341D5E297ULL,
    0x153C3DF4746A7AC8ULL,
    0x6304A6E7BABCD9B3ULL,
    0xEE8F64D3F6FEC9D5ULL,
    0x1A,
    0xC3,
    0x02,
    0xFB,
    0xDF,
    0x47,
    0x7B,
    0xE7
};

