#include "TwistExpander_PickleBall.hpp"
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

TwistExpander_PickleBall::TwistExpander_PickleBall()
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

void TwistExpander_PickleBall::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xF36D8D7F48089B23ULL; std::uint64_t aIngress = 0xFCA29B409FBAB8DEULL; std::uint64_t aCarry = 0xF2961266F20DBD78ULL;

    std::uint64_t aWandererA = 0xA5898D19953A6D93ULL; std::uint64_t aWandererB = 0xED438FC7CE9007D7ULL; std::uint64_t aWandererC = 0xAA52C7D8C9C16AF1ULL; std::uint64_t aWandererD = 0xCC15747BC20B4315ULL;
    std::uint64_t aWandererE = 0xB60494304F3F3F80ULL; std::uint64_t aWandererF = 0xD1830F5769755742ULL; std::uint64_t aWandererG = 0xEA006FD35106B67DULL; std::uint64_t aWandererH = 0xED4C292A5EFBA751ULL;
    std::uint64_t aWandererI = 0x9C85310E5CCDCD4AULL; std::uint64_t aWandererJ = 0xA7B7A2BF4FAD6981ULL; std::uint64_t aWandererK = 0x951AE3A56DC363F6ULL;

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
        aPrevious = 16525480899015746967U;
        aCarry = 18286982138924913633U;
        aWandererA = 18403368580589317172U;
        aWandererB = 17029048325125618212U;
        aWandererC = 11820485933615395869U;
        aWandererD = 16062569992580947000U;
        aWandererE = 16907903540859033128U;
        aWandererF = 13427721065297378410U;
        aWandererG = 11245990364373131190U;
        aWandererH = 13648378622646255702U;
        aWandererI = 14431254648180936666U;
        aWandererJ = 9710603512693801238U;
        aWandererK = 11098643026180755071U;
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
    TwistExpander_PickleBall_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_PickleBall::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA91C065CF5026C2EULL; std::uint64_t aIngress = 0xFA934DE2F7C5EA02ULL; std::uint64_t aCarry = 0x9A1A584617DDFC0BULL;

    std::uint64_t aWandererA = 0xEA08E3623C63746FULL; std::uint64_t aWandererB = 0xD916BA41ED067532ULL; std::uint64_t aWandererC = 0xBA79CE2B79FB8F1DULL; std::uint64_t aWandererD = 0xE36BB4FE414D1302ULL;
    std::uint64_t aWandererE = 0x8DAC713A392FA19EULL; std::uint64_t aWandererF = 0x95157D150ED5A7CFULL; std::uint64_t aWandererG = 0xB0AAFB5D096A1D7FULL; std::uint64_t aWandererH = 0xD27D491E04E64579ULL;
    std::uint64_t aWandererI = 0xF2D6117509250B02ULL; std::uint64_t aWandererJ = 0x871D22D77BD0EE40ULL; std::uint64_t aWandererK = 0xDAA01A2FED7628F0ULL;

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
        aPrevious = 11720796384523920732U;
        aCarry = 13211766295121763308U;
        aWandererA = 17485981800961013318U;
        aWandererB = 11582165413465956850U;
        aWandererC = 17214175195655668412U;
        aWandererD = 14903691048100669685U;
        aWandererE = 15542462350205897947U;
        aWandererF = 10063938087197495212U;
        aWandererG = 15421032782496128814U;
        aWandererH = 14113773522352129607U;
        aWandererI = 12084701668240792317U;
        aWandererJ = 14865086313173522058U;
        aWandererK = 11019647877823706515U;
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
    TwistExpander_PickleBall_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_PickleBall::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC915406BE7FDC55CULL;
    std::uint64_t aIngress = 0x94D6BF85199A0199ULL;
    std::uint64_t aCarry = 0xC8D7A535D2BDF120ULL;

    std::uint64_t aWandererA = 0xBA00EE04A6418F48ULL;
    std::uint64_t aWandererB = 0x8D07884236A6FDF7ULL;
    std::uint64_t aWandererC = 0xEC8A7F99A2C37C92ULL;
    std::uint64_t aWandererD = 0xF9B172A36840D304ULL;
    std::uint64_t aWandererE = 0x847235A31A3D2905ULL;
    std::uint64_t aWandererF = 0xF0CC10B838A53145ULL;
    std::uint64_t aWandererG = 0xD2DABE011171E529ULL;
    std::uint64_t aWandererH = 0x9EA9070EDE0570F1ULL;
    std::uint64_t aWandererI = 0xBC9182E99D87BDDBULL;
    std::uint64_t aWandererJ = 0xCD7BC53E5F098AE8ULL;
    std::uint64_t aWandererK = 0xF3E5C0CE6557882BULL;

    // [seed]
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneA);
        TwistSnow::Aria256Counter(aSource, aSnowLaneB);
        TwistSnow::AES256Counter(aSource, aSnowLaneC);
        TwistSnow::Sha256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
    TwistExpander_PickleBall_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Seed_I(pWorkSpace,
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

        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
    TwistExpander_PickleBall_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PickleBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_PickleBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB896916437074356ULL; std::uint64_t aIngress = 0xA0EB4174AA89B60AULL; std::uint64_t aCarry = 0x82B1702AF4A2E1B9ULL;

    std::uint64_t aWandererA = 0xF48FBBFF2EDE2D75ULL; std::uint64_t aWandererB = 0x800F524DE8D65C3EULL; std::uint64_t aWandererC = 0xF81AAA5F283851C0ULL; std::uint64_t aWandererD = 0xB0DF8997A9C084CDULL;
    std::uint64_t aWandererE = 0xAC6D7A2E1F2CCB10ULL; std::uint64_t aWandererF = 0xEBF06AA45A49A622ULL; std::uint64_t aWandererG = 0x96DA1604C5ED32F0ULL; std::uint64_t aWandererH = 0xAEA8F85FB852B745ULL;
    std::uint64_t aWandererI = 0xFE9FBD0E71CEAA19ULL; std::uint64_t aWandererJ = 0x80E7EEA9A6B892A5ULL; std::uint64_t aWandererK = 0xB3E28C4FF3761114ULL;

    // [seed]
    {
        aPrevious = 17391603821377586892U;
        aCarry = 11805213192020087632U;
        aWandererA = 11193904968081643573U;
        aWandererB = 11949005902594333195U;
        aWandererC = 9463602083886809088U;
        aWandererD = 11020891241249835541U;
        aWandererE = 13920167424487025201U;
        aWandererF = 11948840560332718941U;
        aWandererG = 16298545637644190856U;
        aWandererH = 13032057722892737131U;
        aWandererI = 12563948846026589653U;
        aWandererJ = 11437024003110922694U;
        aWandererK = 15645145223869851170U;
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
    TwistExpander_PickleBall_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_PickleBall_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_PickleBall_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_PickleBall_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_PickleBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 2, 0, 1 with offsets 2829U, 1915U, 6293U, 7557U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2829U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6293U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7557U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 0, 1, 3 with offsets 2769U, 7117U, 8170U, 1460U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2769U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7117U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8170U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1460U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 3, 2, 2 with offsets 1069U, 3702U, 7591U, 5706U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3702U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7591U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5706U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 1, 3, 0 with offsets 3102U, 2143U, 7613U, 6818U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3102U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2143U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7613U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6818U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 3, 1, 0, 2 with offsets 1093U, 1338U, 1468U, 31U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1093U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1338U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1468U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 31U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 0, 2, 3, 1 with offsets 1869U, 1357U, 896U, 868U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1869U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1357U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 896U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 868U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 0, 2, 3, 1 with offsets 896U, 96U, 1463U, 1369U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 896U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 96U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1463U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1369U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 1, 3, 0, 2 with offsets 1383U, 1523U, 1981U, 1329U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1383U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1523U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1981U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1329U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1869U, 484U, 1072U, 1209U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1869U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 484U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1072U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1209U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PickleBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 1 with offsets 2346U, 6406U, 6410U, 1216U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2346U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6406U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6410U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1216U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 3 with offsets 1066U, 4944U, 2561U, 5847U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1066U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4944U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2561U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5847U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 2 with offsets 4246U, 4497U, 3969U, 1155U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4246U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4497U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1155U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 0 with offsets 7238U, 7263U, 4689U, 8130U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7238U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7263U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4689U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8130U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 1595U, 6517U, 7515U, 5670U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1595U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 6517U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 7515U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 5670U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1559U, 93U, 1295U, 1894U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1559U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1295U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1464U, 366U, 1597U, 1714U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1464U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 366U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1597U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 313U, 1980U, 911U, 2002U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 313U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1980U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 911U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 2002U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 997U, 1165U, 599U, 959U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 997U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1165U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 599U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 959U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 3, 2, 0, 1 [0..<W_KEY]
        // offsets: 982U, 1240U, 134U, 576U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 982U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 134U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 576U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseASalts = {
    {
        {
            0x583CCA3CF9D626ECULL, 0xC453C76C7616DBC2ULL, 0x80F14D0A19696C50ULL, 0xBCDE5E6F000F97B1ULL, 
            0x17CD39410D639662ULL, 0x2FA41E6DE0F4F8FEULL, 0x2DD8BC4A343AF9AAULL, 0x1358B436A406D02BULL, 
            0x8CD961049731677BULL, 0xD1BB1B1DEDC812ADULL, 0x86C74152A075E37FULL, 0x2DA5ACE6D34C528BULL, 
            0x51F1D58FC9BBF3BDULL, 0xAEBC1C43D2D6E20FULL, 0xAB9EFDAAFB69744BULL, 0x457083DB60E0ED99ULL, 
            0x7A37371340F6A352ULL, 0x255F130808B7CE3FULL, 0xEA57AC51E21C0024ULL, 0xC8A3A3D58D9D1ED9ULL, 
            0x521F373F1EA5D644ULL, 0xEE1EB72F4BB8858BULL, 0x3A032BBE091762D3ULL, 0x419B93F34FCD63E8ULL, 
            0x1618C932A0AE343BULL, 0xD929CC6721B69D60ULL, 0x7E3BAE0419A23B5EULL, 0x27C7241F9357949CULL, 
            0xF9394DEFCB1B0ABBULL, 0x57C05448F7659C4DULL, 0xE28E9A6B805EAF82ULL, 0x6A573AE9862A3BA8ULL
        },
        {
            0xD4DF341DDCD2BDC9ULL, 0x213E02321EE2150FULL, 0x4DD78F45A335B506ULL, 0x9BF0EA9A2427B6F5ULL, 
            0xD9A5D265D9B83EB0ULL, 0xD56A46693A9CDC04ULL, 0x72E42A003E6DABB6ULL, 0xAFE9B54BC07F022BULL, 
            0xDD8281FDA8EDB1BCULL, 0x4B8EB9E69EFD68E2ULL, 0x70E1CE6A528D3302ULL, 0xF899741BC54EFF3EULL, 
            0xBC4AB3BBD8DA6C59ULL, 0x22C34C8BD0E5530CULL, 0x2630A9C31858A092ULL, 0xC810F03720A5B3FBULL, 
            0xD6B17B6D5232F774ULL, 0xD4B260CBC2983D18ULL, 0xD82B4644FFEEC3A4ULL, 0xDF37BB8FC66F4AE6ULL, 
            0x83AA70B5F7724B66ULL, 0x019395EA7FD191D2ULL, 0x3C54957A776C6B4FULL, 0xE33A3E07E4547C3BULL, 
            0xFBA7A5B72E301D9AULL, 0x5449B1A577571D8AULL, 0xEEB48C403B717D15ULL, 0xFEBF9603E8EDFB8EULL, 
            0x7FE9B2B942E1B221ULL, 0x22AE296F0BDA9BB7ULL, 0xF12629E28FF978A7ULL, 0xA530BDD2E6CDA78FULL
        },
        {
            0x7A5F6C12D95AA71CULL, 0x9CC7E65870FFC9D5ULL, 0xC23DDD3A17A0A30DULL, 0x4285C84E4EB4AF5FULL, 
            0x5A30AF5C7E169065ULL, 0x38C56AD0D8F1CF9DULL, 0x0CE50CCE1E167108ULL, 0x432EC45B375A2F7BULL, 
            0x46EA77282047CD94ULL, 0x98A6151C5DEF9ACBULL, 0x97AA468FCC761E50ULL, 0x8F8C44DF3C8E2530ULL, 
            0x1E559F847838679BULL, 0xF26F3F30E68B4027ULL, 0xE68E7850BC54A68BULL, 0xAD65E246B9ED4A24ULL, 
            0x68B6AE69AE078273ULL, 0xDBC5035CDF7EF470ULL, 0x2573C788E9229B6BULL, 0x049A3F579D47E400ULL, 
            0xC7BC41BB9B80E2EBULL, 0x7BE486C250519555ULL, 0x6422FC4D6CDC44EAULL, 0xC0BB6A567FA0D5E9ULL, 
            0x3DA64D5BEDFC13AEULL, 0x8224F173ADDDAEE6ULL, 0x164BF4055D40C873ULL, 0x75D3EECE91761B14ULL, 
            0xC806A315154399D1ULL, 0xE52192AD08974684ULL, 0x4F6D27AC6A326F65ULL, 0xDF86FD37BEF3EDC6ULL
        },
        {
            0x75B1EE1DDB4946B5ULL, 0xFA48C3E5BDD692F9ULL, 0xFB96A02CA5E52CB3ULL, 0x4A4E9B6229899B94ULL, 
            0x9DF7FF0372C19B9FULL, 0x078CC714BAA2BA94ULL, 0x3ABA8A51B01F3455ULL, 0x6CA1CA42952EBED2ULL, 
            0x4CB1C72635539509ULL, 0x4BB7F9CA2CC68CB6ULL, 0x07EB50C99655D070ULL, 0xE9492E49E267DC4FULL, 
            0x954CFB9E05D53C73ULL, 0xBC08F1CE435B1521ULL, 0xB903449F2B7C90D9ULL, 0x40513EA043846A9FULL, 
            0xAFF01775ABCD3881ULL, 0x4FA68BBB56D13FD1ULL, 0xC901B345D89FF53FULL, 0xDA1BE35E2CAB2453ULL, 
            0x8EE8B4FB4658B886ULL, 0x0B137CD8863DCCB4ULL, 0x9A5D81A067AFC92DULL, 0xC8EE6AE29AF53C5FULL, 
            0xAC065210117DF6E9ULL, 0x7CAEAFE4BBCC43FFULL, 0x4E0B72204DC3B72AULL, 0x1894F77DC23DB411ULL, 
            0x4FDB70B7531E206BULL, 0x41262E2517490F5DULL, 0xA2DB8458E2A540C2ULL, 0xA99B4CBF573DC800ULL
        },
        {
            0x7D238D56570F9C40ULL, 0xAC5B3B4BBA3598ABULL, 0x35141D715E34EED5ULL, 0xFA956CAAB4A2D2A8ULL, 
            0x26D780C3F63FC0F7ULL, 0x4B3ACF99D8FB3889ULL, 0xC27B1CF1CDC17116ULL, 0x949A6EC7455BE3AFULL, 
            0xC15EEA7FFB68B828ULL, 0xF76D9516FD2795F5ULL, 0xABF54ABD6B3A99F7ULL, 0x6546B98BC601D8A4ULL, 
            0x8DA2A20232C3B142ULL, 0xE8F1C900795AFE27ULL, 0x7097C23157836973ULL, 0x38DB67E97CE3C25CULL, 
            0xF3037F8AB77E8A78ULL, 0x4F417F6A66CCA20EULL, 0x7F2CC290E6222106ULL, 0x2A7197FC54E3EEC5ULL, 
            0x4511AC35AF45325AULL, 0x05510F5024CD2044ULL, 0x2DA6557830133ADEULL, 0xDA3A5D5DFAD14D1BULL, 
            0x7101DA9EE4B40767ULL, 0x74E3CBFD51647A3CULL, 0x1A8AFB271ED26746ULL, 0xC81F8BD93CD710FBULL, 
            0x2D73382A38170D73ULL, 0xDEE3CB97665C4A39ULL, 0xC9D483003E4084B7ULL, 0x5D503A2C4BBEBA50ULL
        },
        {
            0x6C55EF7F40D8B75DULL, 0x89B3E2892B65F24AULL, 0x5F3D27C09DD6F9A3ULL, 0xA3270935D7E60723ULL, 
            0x59FA951DD09F4041ULL, 0x4F4515F6DEBF2BE6ULL, 0xB8755EACDE83CAAFULL, 0xDAF6929A6FEAA6E8ULL, 
            0x679360A8BD80286FULL, 0x1BFEA7A17A750A3CULL, 0x43414B3D1C5F2B1FULL, 0x4AFCD975921F4673ULL, 
            0x3089300B2EF4AE43ULL, 0xCA3D958D73C846D9ULL, 0x6D60E9948668A1BCULL, 0x693FFA211F889C60ULL, 
            0x9B6B075BC1EC0390ULL, 0x2511379A40F51368ULL, 0xA0E425457924EDB6ULL, 0x04EA61A4D19335F9ULL, 
            0x28AE295CCEF3FA2EULL, 0xA0BB605BAD2DA21AULL, 0x0ACCBABFC7A028CDULL, 0xEF1F507B4AC71F5CULL, 
            0xC70EFDCA38D7568CULL, 0x19F765C2A1A5A4B3ULL, 0x98C4C368059D94A9ULL, 0xCFDBE1D788D049B4ULL, 
            0x549B1498161A3B70ULL, 0xF199DE45A0380B32ULL, 0x9ADE932A101158CEULL, 0xCA30BC5DDA33C168ULL
        }
    },
    {
        {
            0xE338B0FA0FCE5094ULL, 0x1611732A644FC10CULL, 0xE35472B07FBBC96DULL, 0xC0B338BA95C84A77ULL, 
            0xFDA6FAAB0257A36AULL, 0xA4D66C52DAB5F066ULL, 0xEC3894CAB6DE10BCULL, 0x024D8A44DD39B3FAULL, 
            0x8BA7C1D98448EE8AULL, 0xD94298DAF39BA55FULL, 0x2122E07920B1C632ULL, 0xD76974B0C40EC405ULL, 
            0xF84F81EEAEE56489ULL, 0xCCD7730D989F0C47ULL, 0xDAA21A9372D5D93DULL, 0x7E6747EBDF3B75D7ULL, 
            0x1DEA84A7366722FCULL, 0x1E5BFD44383F2DC9ULL, 0x28D512B8A1B0B98FULL, 0x9161F0597049E287ULL, 
            0x752FF2C144982E20ULL, 0xC921205ADCC81F11ULL, 0x377691DC9283FE00ULL, 0xDB0FB5C8DF15B73BULL, 
            0x0225BA6E19B4A33DULL, 0xCC8EF6FFE7D868CFULL, 0x27736F5657948241ULL, 0x0475562DE148B57CULL, 
            0xF01A92AAA6514130ULL, 0x36DD908B6E376F37ULL, 0xFFC6D247ECEC90AEULL, 0xEDD2F7111DD8BDD9ULL
        },
        {
            0x1D7EEDFD3CCD1B5CULL, 0xD364C71C12355769ULL, 0x5E7C01E492E55554ULL, 0xE99DBA209605BF47ULL, 
            0xD68AEAFA40A2317DULL, 0x1BC02123BBBA1581ULL, 0x2CEBC8DEB74A32D1ULL, 0xC7D800F2ADBE9C01ULL, 
            0xC5E2D85EE8FFCB08ULL, 0xF344DD3AF911F51CULL, 0xA3804F3AA5BD50A1ULL, 0xAE03A808BFA64D4CULL, 
            0x0CFE75087A0C7AC5ULL, 0x21C27873F86189FEULL, 0x7A7E48E35E6E3B4FULL, 0x973A9AA6F9262F46ULL, 
            0x750606E0240D453EULL, 0x5881A2BFED2AD347ULL, 0x6D9636199E3E9673ULL, 0x1D2950FCD8A9C118ULL, 
            0xADDBF6B724F69D3AULL, 0xA39EE77F3D317CFEULL, 0x4C29738B0411FF9EULL, 0x87EDA3861CC8148DULL, 
            0x2F8ABBB2B0434911ULL, 0xB9F8E1FE9A9F25CCULL, 0xAD570CDA513353DCULL, 0x687B2966AD4D1221ULL, 
            0xE344DB8DE37D88E2ULL, 0x08153295AFA70EE8ULL, 0x1CCEFABBA04D4043ULL, 0x1A49791CFC31344FULL
        },
        {
            0xD8826710A61F7EA8ULL, 0xAE8B8F6877996739ULL, 0x1D5C396A335DB019ULL, 0xB7DB29E17E0B3A10ULL, 
            0x8B39EF482A122F95ULL, 0xB4772896DE2885DEULL, 0x03F3A20903B4852CULL, 0xF68419F72C942C38ULL, 
            0xFBE985E0B1F9DA65ULL, 0x09E163D0DDFF855DULL, 0x6C4FF5EF08C34FB0ULL, 0x5C0792EA5B19E547ULL, 
            0x5E4E42B1D6EDC2BDULL, 0x8ED2DFE15F46BD2FULL, 0xFC524EF19A6981A3ULL, 0x127E015CB5CCF3F7ULL, 
            0xE71A202C1C13690EULL, 0xD6DC9DF3EEBD2FCDULL, 0xD4C94B5D4B3A6198ULL, 0x959722CFBE3DC917ULL, 
            0x0EEB668712CF57ECULL, 0x549419E5EAFB5B87ULL, 0x747E3FE509B35C27ULL, 0x3DE6AE10BEBF07AEULL, 
            0x6E79CDDC1DED6B09ULL, 0x655676D946C7AD53ULL, 0x652143424D245E1FULL, 0x3CF3D4B15FA9743BULL, 
            0xF13211B799D836CFULL, 0x783700157B360049ULL, 0xF3216E0E8546E757ULL, 0xE4C74F2E17D1AD98ULL
        },
        {
            0xCE189C4A12647C3EULL, 0x1ABBD3B0F8ED8CCEULL, 0x18B4C95CC5C41590ULL, 0x16CFDF7EAF26024DULL, 
            0x6429CB65F05E08CDULL, 0xF7ECDA51A3E9FF81ULL, 0xF83B994E59506126ULL, 0x0F48B005B5EA4928ULL, 
            0xE173580FB974B85AULL, 0xC9097F4156B1F422ULL, 0x9BC1AEC452CA0037ULL, 0xB2843BD547AA6C8EULL, 
            0x76D8D78B5B881084ULL, 0x9BFC981133C15E5EULL, 0x1BA9C64A8348DE4BULL, 0xA0D7D4A10558E099ULL, 
            0x960C7968068CDA1AULL, 0xA27C4A3048701479ULL, 0x530AD28831BEEAB6ULL, 0x2B7F5C2561D05356ULL, 
            0x4285A6D83DFA7DCFULL, 0xC7A60A7116B3A95FULL, 0xECD50B8F5353BF8DULL, 0x26C12DBD0FAE1FE5ULL, 
            0x4CB1C1D47EC0D35FULL, 0xCDD0EBBB3C20FF4FULL, 0xC2AE6345B13B8ADBULL, 0xE41636E8D575B4DDULL, 
            0x64044095A4092A67ULL, 0xD1532FAB0E8C4B00ULL, 0x34F036CD24A83EB2ULL, 0xB567B7B5CC624BC2ULL
        },
        {
            0x3AB80388AB2E0F00ULL, 0xD6589010B26571A6ULL, 0x42A48AC284BE3F27ULL, 0xB31E50697A024168ULL, 
            0x29A512C528973E3BULL, 0x298B3764F1BF5212ULL, 0xE54009438311170FULL, 0x2D542FE23557079CULL, 
            0x621EB91EC3351F1BULL, 0x08A62C4BD254B5C4ULL, 0xDC511F92C244F705ULL, 0x552507BF1CB23B2AULL, 
            0xEB5FAF304C395EAEULL, 0xB8AE422C5CAEBFE7ULL, 0x18885A8C7BB6AC15ULL, 0x838138C78B5C62BCULL, 
            0xAEDEB9EE6A23A674ULL, 0x942576F680A10F5DULL, 0xCAD6A08B596E4C9EULL, 0x59495036769B9FD3ULL, 
            0xF00E955CFB4CDA17ULL, 0x9DC40889219E25E5ULL, 0x64823D33907277D7ULL, 0xEDE6F884F39BB556ULL, 
            0x854E74C8D43EEA11ULL, 0x4CF7FD1CF13CDFF2ULL, 0xF0FDD55040263F7FULL, 0xDE2F0B5F9277CDC9ULL, 
            0xA4508E2C9B4647D1ULL, 0x81C45067797D8FCAULL, 0x25DA656F6FF3E194ULL, 0x82B2D3DAD884F882ULL
        },
        {
            0x253CA67CF7482C5EULL, 0xF8318C7F263AE82DULL, 0x65424AFD12D6359FULL, 0xD2059DC4308DF81BULL, 
            0x42DE6B57A399FD82ULL, 0x95ADF4542766F7B2ULL, 0x2841DF8E72090D41ULL, 0xDF7B24502BB2C440ULL, 
            0x38E32517C9AEE673ULL, 0xB5C5E50942F7F0F5ULL, 0x5C7706688F5FEEF0ULL, 0x0396E10821604AB2ULL, 
            0xCB4D074BC04DD554ULL, 0xC35D33A6017AB3F7ULL, 0x47C6B34416E783C2ULL, 0xEABAFC9F464D26E1ULL, 
            0xD430A30A6CE79824ULL, 0xEA38808A9ACFE39EULL, 0x6F8E95FF17AD171FULL, 0x408A6E63A30D8C6BULL, 
            0xB0C26AE5E0E559A6ULL, 0x450B8604D709D051ULL, 0x5950EB8ED72445E0ULL, 0xF2D4125BFD34EB13ULL, 
            0xB58CA649C0607345ULL, 0x632BF66C296FE00CULL, 0xB525DFC2D0CBF995ULL, 0x04253CE1B761C23AULL, 
            0xAB9E7DBB6A56CD11ULL, 0x4A4EA4B8E2B4524EULL, 0xD0D64A0F67D80519ULL, 0x274E1C45C0C3E9D7ULL
        }
    },
    {
        {
            0x0B6449F714A0A6ECULL, 0xA9212192E7CFEE5BULL, 0xD7BAD882A05D95FCULL, 0xAC0AB45F5B2CCA8CULL, 
            0x92CF8F8733C247A6ULL, 0x60683D13CD411C92ULL, 0xF564D43F743E4327ULL, 0x5EEEF0C0073CB3CEULL, 
            0x59DFDEF22EBE9C8BULL, 0x669337A34D7B1DDAULL, 0xCEED6B420A72EFC4ULL, 0x65B7B2C0324B4138ULL, 
            0xCA38363D7830619BULL, 0x7BE190A51161A83FULL, 0x9F1CD68544C0146BULL, 0xDB31556B4DEB4D2BULL, 
            0xE32D375F4E6D6C61ULL, 0x2E5694839A8B523AULL, 0xFAD63FBC4FE0D2FCULL, 0x7648D4B30296FE19ULL, 
            0xE534504A1D45E204ULL, 0x6C0646B1D5C9E58DULL, 0x4474EB1054ED70B7ULL, 0xD99966C3BBAAAE4CULL, 
            0x80A93BEABA056066ULL, 0x1338F695EF0F2E77ULL, 0x2238A81B9DCE81C7ULL, 0x4D72E30A30A0C4C2ULL, 
            0x3271206050EF4871ULL, 0x72E08875BB96F313ULL, 0x4F71A2B95A030171ULL, 0xC129E97068E71D22ULL
        },
        {
            0xAF1B25BC760919BFULL, 0x66BFB79A97C656B5ULL, 0x4B002FDEF97964DAULL, 0x4388ED9BC6EA4F97ULL, 
            0x8147225781BF5974ULL, 0x6B0D3C27B167EBD5ULL, 0xDC5967DD0E5555AEULL, 0x1EF1917CA07EC6A8ULL, 
            0xBB36476488A3D815ULL, 0x3F6C531401FD4982ULL, 0x389F55179B40F982ULL, 0xB7A79A7F8F47F3F6ULL, 
            0x80A88916DB7ACFF0ULL, 0x93E19CC376758633ULL, 0xF8C9F5E4A7B43564ULL, 0x012D44D6631C6F3DULL, 
            0xAF657F72EA94D860ULL, 0x032D48B4EAC9B958ULL, 0x8FCD696EBE03710AULL, 0xEEF4678E6FF495B1ULL, 
            0x58534770AF00A5BBULL, 0x24242F9DF52B4338ULL, 0x0ED56C83F30E7F21ULL, 0xB87505E8605EDB39ULL, 
            0x0B5E34892DEFF81DULL, 0x70FA374574D932F2ULL, 0x90C62D2BF83E9045ULL, 0xD50D34352BE9CF4DULL, 
            0xFEC9427E15291B22ULL, 0x786CE57D92CDD0ADULL, 0x5EF28A547EB5D1F9ULL, 0xE3584E43779C19DAULL
        },
        {
            0xBDE32315748C8C2CULL, 0xCB0F9D509FCE7851ULL, 0x61728F910CA08591ULL, 0x9FD27542C655542EULL, 
            0xE760ECFDB28B4725ULL, 0x1DE6AB0693B05B48ULL, 0x25FE925EAA8FFDC7ULL, 0x5FF59C9B16827415ULL, 
            0x6359954388BB1165ULL, 0x5E5E4B7A89AC0644ULL, 0xD7123F66601F2193ULL, 0x0BBEEF0A928847D4ULL, 
            0xED86F050D0C0CCBBULL, 0x575D548EC7443756ULL, 0xCC0000DCFB3E150FULL, 0x949CDF51CD575800ULL, 
            0x34B507F3396C8EB1ULL, 0x14B6E547C671C4D3ULL, 0xD55514B205594CCFULL, 0x6C453CB7179C7084ULL, 
            0xAE3210AEE3285AE7ULL, 0x3726CD7811C54F6BULL, 0x6C15AFA7AD0B3D05ULL, 0xDE0C503AF8888070ULL, 
            0xE53C205DCA2F1C9BULL, 0x0AA333562EE9D191ULL, 0xFD96D4FF1FEBF20AULL, 0x7C12A50013360BE2ULL, 
            0xA499BAD435D31B8BULL, 0xA91F57236F8FACF8ULL, 0x1D7A5139AC9658DEULL, 0x5256C645CE8A7B5EULL
        },
        {
            0x0CCCE621D6F1D3F8ULL, 0xCC3391B708362F22ULL, 0xFB130691DC3EC732ULL, 0x97B584946D3D71ACULL, 
            0x1EC4D2010A9986FFULL, 0x634E117D2575F17CULL, 0x0515B56479AA6FEFULL, 0xED33CF3321B2E6C7ULL, 
            0x416C251001FF26C3ULL, 0x18988FCFBCAE3CF1ULL, 0xB450C89F0BE24FA0ULL, 0x7E0594A6F2641911ULL, 
            0x6976B939D68F50C0ULL, 0xDB478E143D072B77ULL, 0x65EC3216F73C19F9ULL, 0x428F9F86B2962B1EULL, 
            0x5C9CBCC448C908F6ULL, 0x6FDF970B3C384E49ULL, 0x1983BE7CA2A21962ULL, 0x0AFA2B7A307FBF17ULL, 
            0x989C15039C87C19EULL, 0xD1087A208D4CDB0EULL, 0xBD5706C2070F651CULL, 0x172FE05DE3EB5F38ULL, 
            0x25DF18640B532823ULL, 0xAFCB2244C79C096BULL, 0xC0CA698E77216D4AULL, 0xFEFE6111AFEA9359ULL, 
            0x4155013C044EF412ULL, 0x949CFFF46F272B1CULL, 0x764FEC784EB4CC6EULL, 0xB7EFDD58B0DF4602ULL
        },
        {
            0x79D7F0DD65C0D929ULL, 0x2ACB749F81794EECULL, 0xC0E92587E6F2C3BFULL, 0x2B3FA79549AD0A68ULL, 
            0xCFD1E4CE5EDFFFCCULL, 0x9691736B31FA963BULL, 0xD71AB5AC37225D4CULL, 0xA85B9FA7AE988A82ULL, 
            0x0922D02AF59D96FBULL, 0x2DD51905683FD27FULL, 0xFEEF34869765E26FULL, 0x111650173C191B21ULL, 
            0xE29F296401429EB9ULL, 0xF823248AEB17AAE9ULL, 0x5C32ECB5303F9622ULL, 0x861A8CAA7D5F4353ULL, 
            0x8A2D1D513D292B08ULL, 0x1D45C9CFADE9AD02ULL, 0x78D5224C00FBA102ULL, 0x6265647670A120DAULL, 
            0xC8E815D69EEED22CULL, 0xE7CEB7852A4F5ACFULL, 0x96A6C49E1865021DULL, 0x2C3C505BEFC1F9BCULL, 
            0xB98F3080C23636D3ULL, 0xABE31F8A81094FF9ULL, 0xBDC73DE7F94A2C00ULL, 0x753EC36FDF57621FULL, 
            0xD9BF376F3303BFDBULL, 0x972C2336656946B9ULL, 0x3D46FA301E3BA0F8ULL, 0xE4B4FA24FCFE971EULL
        },
        {
            0xF8E093A81897C364ULL, 0x559C8E1D21E95FEEULL, 0x1ACC2D844EFD0828ULL, 0x221BC223F06BDE6DULL, 
            0x7209E46DFBB10D62ULL, 0x6B5A7D773207765DULL, 0x18A92B6B2CC896A8ULL, 0x74BA5910A1F184A6ULL, 
            0xF60992EA6B25E124ULL, 0x5E5538F93B75618BULL, 0x0C900C8750E27B7DULL, 0x46569FF3F40F40C2ULL, 
            0x4B0830FF15DE578FULL, 0x4ABB7547A618B450ULL, 0x67002D8BB56A4063ULL, 0x282014C606206C6AULL, 
            0x19272A1D712549E1ULL, 0xDCE2856B9704657EULL, 0x755D554E39F333FAULL, 0x580026439E4CB2FEULL, 
            0xDB7890B18C4CC479ULL, 0x86D1FC45988F7768ULL, 0x908249654B2ACAFCULL, 0x61DB29FB4B7DFEFAULL, 
            0x7BD175EF78676E3DULL, 0xA3625EC8B29F4120ULL, 0x510D9C35E3D9B159ULL, 0x4AFD35D090946B26ULL, 
            0x6619CC28E115EC9BULL, 0x320221D696524A6BULL, 0xA68C65C4080249F2ULL, 0xDAF18E82ED7489BFULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseAConstants = {
    0xF7E529319168BFE4ULL,
    0xAEE71283E6CA48C7ULL,
    0xEC55A270739C2BA8ULL,
    0xF7E529319168BFE4ULL,
    0xAEE71283E6CA48C7ULL,
    0xEC55A270739C2BA8ULL,
    0x114315418FC741DDULL,
    0x8F4AD66BEF8F00CCULL,
    0x68,
    0x99,
    0x9F,
    0x4B,
    0x85,
    0x5F,
    0xAD,
    0x95
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseBSalts = {
    {
        {
            0x974A54AC44B5D055ULL, 0xD1A83736AFC9227CULL, 0x0A581C0083DC19D6ULL, 0x84C74FA9D1ADA020ULL, 
            0xA9DFDD6A4FC33D20ULL, 0xBB3A40CFBEE3951EULL, 0x1FDFFEB126ECF25AULL, 0xEF9AEE66F7166409ULL, 
            0x14ED3285C39B075AULL, 0xF50642D3FFCEC0A0ULL, 0x26754A79337818EEULL, 0x2FF5D300E8C44848ULL, 
            0x73B8A3FB4035E9FAULL, 0xD02C49663438B7A5ULL, 0xE65EFE7ED52759A6ULL, 0x8995C724AF09E62FULL, 
            0xC9A59E232193FC0DULL, 0x33C26A1038DB48A4ULL, 0x5B1941F1A34D23C3ULL, 0x579B1998E0BC8032ULL, 
            0x0E10DADEB159022FULL, 0xAB6D3977CFAA28A0ULL, 0x3BAE7C0D325B5AE0ULL, 0x9C954D46F6027A02ULL, 
            0xEE55B88CF673948CULL, 0xA4C69E4A63CA09ACULL, 0x576FD2227038B9F9ULL, 0x21481187C07FBBB5ULL, 
            0xCBD0D85167A5735BULL, 0x88A4D7C5325E6D06ULL, 0xA0AE33F50AADBAC6ULL, 0x972C94975E2C141CULL
        },
        {
            0x3CD53DBA7F383874ULL, 0x21D6F0262FAC14EDULL, 0xEB9C2FBA82D45733ULL, 0x878E415B49AE8D93ULL, 
            0xB5C53CC1F2CFAFBBULL, 0xC35449D6884F6125ULL, 0x47FE7F4266D0EFCFULL, 0x6186A139E0E81A5EULL, 
            0xABEBBB08C56DBB50ULL, 0x4C98F8F5A27E5B8DULL, 0x75F1C770949E2BA8ULL, 0x99CE48B1EF0F104CULL, 
            0x18E17666199EFD91ULL, 0xDC42ABE273D86B58ULL, 0x30E3F4F43A8907E8ULL, 0xFFBE6FE3A4E63A3EULL, 
            0xBEA80BF4CFB1903AULL, 0x04DAC06A724C7F27ULL, 0xE228F2D7F4F917E9ULL, 0xD34C7E5DD333565CULL, 
            0x5B0E8199B4DD8BA3ULL, 0x52CF801C168E7E5EULL, 0x65FE35D586F349A9ULL, 0xBF2005B625F04E59ULL, 
            0x8FC5320CBE3D1B54ULL, 0x73A810A2F87C5B3CULL, 0xDD75815EA1A70D4CULL, 0x47AFA42EC35AFED7ULL, 
            0x78A2D2FC9D3B4255ULL, 0x626A2D690DE52446ULL, 0xB3989F63D09F431CULL, 0x24B4CA55959D74CCULL
        },
        {
            0x47A28349C3FB60AEULL, 0xBDDFCF6DBB857394ULL, 0x91E078A0084E2333ULL, 0x16C3542914E0946AULL, 
            0xA14B15B084BDA8FBULL, 0xD3DF27F637E735AAULL, 0x16848D5C18B4BFB0ULL, 0x3E4FAFA283E54F5BULL, 
            0x7159DA528263DE78ULL, 0x531B1936976BED7DULL, 0x5FFCEE2149308E9BULL, 0x9BF6C823CF93B034ULL, 
            0xBFA9C536D52F9E66ULL, 0x285F3AAAD20176DBULL, 0xE64C2D1693DF3968ULL, 0x6D15C7323EF06DE3ULL, 
            0x530942DD6D4113DDULL, 0x5FCCD8F111578407ULL, 0x369A22E1F9585BABULL, 0x7B167EDC8404BA36ULL, 
            0x38DFA8A0EAC6315EULL, 0x3FDCD886F66D800AULL, 0xF669E9EFC6E402E6ULL, 0xE6D5EAD5C2F07403ULL, 
            0x0B3AB6C321EDB6FBULL, 0x3ACDDCF9B0627438ULL, 0x8DC488936AEA994EULL, 0x1E8E97A3D6E61D55ULL, 
            0x96ADD2959D383950ULL, 0x0126C52CAABF5194ULL, 0xAE624568AB282001ULL, 0x32C94CDD4E5544B0ULL
        },
        {
            0x0DEE49651032C812ULL, 0xF45D10BAA86C9566ULL, 0x6AEAE15120C16C91ULL, 0x2AEE0FB2180CAEACULL, 
            0xA331D739C0CB8481ULL, 0xBDF816BD61767219ULL, 0x2F24F0EC2FA28AACULL, 0xFB3583CD5C2CF9F9ULL, 
            0xABE81211979705AAULL, 0xB7D4CF233E47C1CFULL, 0xE48BC1CDA4BEB7E9ULL, 0xB529DCEB0D8F8DADULL, 
            0xE5BB9D8E8650E07AULL, 0x9722F491CF895F87ULL, 0x7E7A9FEBACD27CF6ULL, 0x7C04D02605E815AFULL, 
            0x6F365E2429D44297ULL, 0x52F77CFFA1FD054DULL, 0x008B6F69674E7F61ULL, 0x46D30CE9D03C578EULL, 
            0x9E6489A20B0C1082ULL, 0x63E4CCE1E18D4A4AULL, 0xB53FD89AC8151E45ULL, 0x7949943D805BE3FDULL, 
            0x3A681BFC1C37FA47ULL, 0x3477FB1D80D8CB35ULL, 0x858198E5996F0F93ULL, 0xB079E7534928C12EULL, 
            0x3C0B29A7887C2816ULL, 0x560CD1E7B582EC3EULL, 0x4874CD7C37487415ULL, 0xABA861D9DC16C3F9ULL
        },
        {
            0xC91116A3F8E66C7CULL, 0xCF01637D18846FD6ULL, 0x19FE0E4694AE15AAULL, 0xF14DB962A37475A9ULL, 
            0xC4DACD0B4EF5994BULL, 0x68B5A905284F4631ULL, 0xF05B7F7650FD33BEULL, 0x49E06F21F74BD82DULL, 
            0xA4B9D8A7CD501777ULL, 0x0B8FCBFC3A3E457FULL, 0x0F660D677BDD56FDULL, 0xEED759158A3F6703ULL, 
            0x649D8998DDB7957CULL, 0x137BF003B4C909E0ULL, 0xBE6076E90D220C5DULL, 0xAF837BB1F260DCFBULL, 
            0x7536AB8DCA3E779CULL, 0x8595353A585C3F55ULL, 0xAC3C1DE45E2C4167ULL, 0xAFC893C08AE6E401ULL, 
            0xAA48C7693F2F64A3ULL, 0x09C15B04562B73D9ULL, 0x46BC55F3ED818F5FULL, 0x9B4ACB8E6686008BULL, 
            0x261D12E94D2B6B4FULL, 0x3356ED95F3AFFB5FULL, 0x922514A9885C0992ULL, 0x0C2AA8CFBAD45277ULL, 
            0x95E23AE2358D740EULL, 0x41140B4066D0372CULL, 0x99ECDADFF3BA667BULL, 0xF40BA0C985441CE0ULL
        },
        {
            0xAE81B914A67FD65CULL, 0x44CBC851C10E4791ULL, 0x5F769F51CF5BB066ULL, 0xCF95EFBFEA88AF8EULL, 
            0xAFE1636C243F0EB9ULL, 0xB921CA211A451E1EULL, 0x12374E8F92F133BCULL, 0xF600D86B619DB051ULL, 
            0x8083625A2DD185F4ULL, 0xB090530638D9D980ULL, 0x2E8361C34D1236DCULL, 0x9D254E0F8FAD8009ULL, 
            0x0D9B0A357AB01FDFULL, 0x56BFE8FCE1A34ACEULL, 0xE0A5F3C2F5C6BAF1ULL, 0x05F101438A1DEA65ULL, 
            0xF035ADBC582635B9ULL, 0x3C6D3CD0394330A8ULL, 0x7BDD85E5D34D317BULL, 0x03AE571025EB904AULL, 
            0xB0201BEF67398C8DULL, 0x55F1DE5BC14AD416ULL, 0x9C4D590DBBD19E14ULL, 0x547CDA3231990D08ULL, 
            0xD6CDB2A864B2BF6AULL, 0x5C43A0E9CD134D82ULL, 0x148B531035BFA52EULL, 0x931020D615A08FD9ULL, 
            0x704E3296119B5C2DULL, 0x5CE604FCC85F3127ULL, 0x1B9AD573A91D9182ULL, 0x15F88BB61F28CDF6ULL
        }
    },
    {
        {
            0xD42F867CF50D2623ULL, 0xC3ECF2EAEDB8E982ULL, 0xD0A7FD28B2F1A8DEULL, 0x8F2CD99BEFC7DD5BULL, 
            0x5F47168587A36FB5ULL, 0xE57EE471BA18BDF9ULL, 0x849477E5B5FEC6B0ULL, 0x91CEDE7688B34AF0ULL, 
            0x48266E8F21AE80DCULL, 0x09FFE51CDE59F6A2ULL, 0xCC0E2E957D2C8F6EULL, 0x94BEC9FBC1E1CE3DULL, 
            0x74478BF1CCA7277DULL, 0x348D5621F663EAC6ULL, 0x96E88087464CB01EULL, 0x2F63C7A8B0E44CEBULL, 
            0x7D2215085320ACD7ULL, 0x7312264ABA067C8FULL, 0x213F6E8A2A9045D6ULL, 0x835509B93BFE2F89ULL, 
            0x569AD65443D5978CULL, 0xD5BADD970E09C5D1ULL, 0xA0B65E0FB428FC54ULL, 0x4C7386FBEFAED839ULL, 
            0x9516B5619649C60FULL, 0xAB9A4290EFCD2498ULL, 0xB6A8FE0846ED2562ULL, 0x95CFD9B5679D315EULL, 
            0x149A15AD7D7347D8ULL, 0x07B4A9A36CA2E894ULL, 0x19043383089C2F6FULL, 0x1F7384C7E7F707B9ULL
        },
        {
            0xEE7EF5A520DC90A9ULL, 0x89E540DB83B19A42ULL, 0xB01F2BF686928ECCULL, 0xE71C23244008130DULL, 
            0x88A014B407FDDE20ULL, 0x642C14B274BE51DEULL, 0x4A38BD51238CDE90ULL, 0x182EFE5D4A62DC06ULL, 
            0x369AFDB213AE52C1ULL, 0xCBBAC759D911FC6DULL, 0xDAFD3D5871BC678FULL, 0x3F017EE317F333DAULL, 
            0xA6D42BE15323B0C4ULL, 0x843E2DC21CCFCDDDULL, 0x4FA1D1E4ABBE9E3BULL, 0xC51BFAF9A4E806E9ULL, 
            0x34A34BCB9109121CULL, 0x05299326C61ECBA1ULL, 0xD0A4889228276E60ULL, 0x2449906AE5AC8BDCULL, 
            0x80391B9CC24F0CA0ULL, 0x877E625C96E82E30ULL, 0x554E41E554645C13ULL, 0x2F40B5FF5E7C3B5AULL, 
            0x54DA8D4E76E34A74ULL, 0x5A3FA0985600460BULL, 0xF5A6A979936C6A5EULL, 0xEB75091B1FB034C9ULL, 
            0xE9A2F79A9A2179E8ULL, 0x6D100725F5070F51ULL, 0xA4D3A76D62FAA15AULL, 0x4285ED50250CD3A8ULL
        },
        {
            0xD37433E94B45C346ULL, 0x4393AFA6D9594B1DULL, 0x2278E418C3CA9E28ULL, 0xA80163B6FD16E887ULL, 
            0x0F66CBAC80EBBCEEULL, 0xF45EFC573D29527FULL, 0x0B6EBEE441043318ULL, 0x6C689C99AD95C26FULL, 
            0xE202789F0C8AEEC8ULL, 0x982756B0B71CC79EULL, 0x9BF9EC09D13F1027ULL, 0x770EB7036A5C7848ULL, 
            0x92B1F7AB994BF2AFULL, 0xF72877093F63A0D2ULL, 0x9D2F535E0D6CBFD2ULL, 0xBE1CE2F0BE4D6D2BULL, 
            0xAC313112C71A5C73ULL, 0x5FEFA2F09E33632FULL, 0xDEA88EE2C6FED1E4ULL, 0x4B3A3512A8FAC25CULL, 
            0xA594EA5C0B388F93ULL, 0xA644CC001F6F3154ULL, 0xE99AEE5A1E077E89ULL, 0x7C703B2FE9885339ULL, 
            0xDB274137AB371F02ULL, 0xAF2888AB158B4089ULL, 0xC26066C010B0612DULL, 0x9D151E8F4DC1C858ULL, 
            0xA6ECF9DB97B106B0ULL, 0x28589A3EB23FCB47ULL, 0xC5036CD8A88BB997ULL, 0x413440B5CE954C2FULL
        },
        {
            0x825B735E535F1171ULL, 0x09FB7FB53C3D921BULL, 0xF5D2314B30B8A89EULL, 0x7943FDAAEA51A833ULL, 
            0xA31BDE13F3CC4EE6ULL, 0x711BE48BC6704B8AULL, 0x3EFDEC0F2BA64141ULL, 0x894C01DEC0BF3969ULL, 
            0xF1C764FBD3B4D74EULL, 0xF8AE77B5970B84A5ULL, 0xAC452A9CE5ED6BA9ULL, 0x4430BBE03312D951ULL, 
            0xD6A43E687F0CCFF5ULL, 0xE09961323CFA18B7ULL, 0x4EF7EFC68C4DF24EULL, 0x9D8E797E40F8BC19ULL, 
            0xD8BA44E4456F6005ULL, 0xBFE5785F650AD8AAULL, 0x7105DD5CCAF1B1C5ULL, 0x69EAC3A9D4747F86ULL, 
            0x88BE7D1EAD8E1487ULL, 0x428C88DE12CD5B35ULL, 0xF90C7D3E6F0E72FDULL, 0xCDC606D385F6F425ULL, 
            0xA17CE3253453D631ULL, 0x4CF1C073B9256BEBULL, 0x65E45798CCB2A2E9ULL, 0xE558EB088E8368B6ULL, 
            0x01F5B0CF797F411DULL, 0x7A45847E82E27FBBULL, 0xA8FF2E8BD2132A0FULL, 0xAB622D5305D28BB9ULL
        },
        {
            0x382C8B8B94F09F76ULL, 0x04A5C444D489EC86ULL, 0x0D76E0D2AB09277BULL, 0xCA64E33A211D83E1ULL, 
            0x0743F1E758B51F78ULL, 0xB7F271521C7E6D7FULL, 0xA98E36AFA4280986ULL, 0x6CDBA0B32CA7F0ADULL, 
            0x18E0435CF5277D4EULL, 0x2D1322CA7CFD073EULL, 0xC3650E76544D36ABULL, 0x3A7F441F8C35C2D0ULL, 
            0x8D1C3084AAD78C36ULL, 0xE7FD4733F6D89854ULL, 0xDDF26E181B9B9A39ULL, 0x26CFE7C26A9FD734ULL, 
            0xDBD5CC09FA9571D9ULL, 0x86F1A7BED60C6DF2ULL, 0xF97A9B6A0D238BD0ULL, 0xDAE8EB7F7B2DE1B3ULL, 
            0xB8ACCB6BE010EA14ULL, 0x0EF358F593B2D6C8ULL, 0x66292D3E0BCC70D1ULL, 0xED4D273D0C84EE06ULL, 
            0x5BA31D1DD130A6F8ULL, 0x7F79F0F5BA0FC254ULL, 0x6DCFE2DB369FA7A0ULL, 0x6B35685325253C1FULL, 
            0xA856EF015AC15499ULL, 0xFB28475548904ED4ULL, 0x67B3E80A63F78516ULL, 0x4EDC7CA1667AF78EULL
        },
        {
            0x7285ABB15325D656ULL, 0x6692116829E443ABULL, 0x9C245A868929389DULL, 0x0C38014AE64782D4ULL, 
            0xFD848DD471B5C5E4ULL, 0xEAC50267B74A891EULL, 0x07392CFAC403F385ULL, 0x9C65A03C61FE67ACULL, 
            0xA3BC1A62979F82F6ULL, 0x0B983F1FFAEB83A3ULL, 0xD1155DA796199A79ULL, 0x2F920F5A42232E3EULL, 
            0xF8DD0E554D08994DULL, 0x02977624A2A7B411ULL, 0xA624C96AD3BCCCE1ULL, 0x2281C81F15E6571EULL, 
            0x68483F257413D7A8ULL, 0xC0320C59A0271BEBULL, 0x0C42BFB53E4E25D8ULL, 0xD7024618D336A524ULL, 
            0xF690376AA542A58AULL, 0xB25EAFD837766042ULL, 0xFC0D6FE48AA4A6ACULL, 0x61A39D2D7847F182ULL, 
            0xFB6DE8408C674D08ULL, 0x1146431ED151D1DFULL, 0x44EF00C7230941F1ULL, 0x28A4A3ECE210EAF9ULL, 
            0xE52577553321D4B8ULL, 0x4320CC97160FB9B3ULL, 0x644CD05A6B33C178ULL, 0xD8FC4D9596CCF931ULL
        }
    },
    {
        {
            0x23B8909D07F7A0BCULL, 0x178B666ED89075A8ULL, 0xDADAC93E845E9120ULL, 0x7D0AAE5A28FF04A2ULL, 
            0xE339CC79BED57444ULL, 0x0BF5AF11FEDD0909ULL, 0x4B235BDB8601243EULL, 0xEF3CE52F34635DE2ULL, 
            0x340E855D27941D79ULL, 0x6DE51B4FB980D1F4ULL, 0x9C2C0C6540C556FCULL, 0xA4D878204BB0EEA1ULL, 
            0xDC8E806B5DBEF111ULL, 0x0E5B7A961DDDDADBULL, 0xF625E28A8FD2A9A1ULL, 0x420C44B534770935ULL, 
            0x1EAE5ED99053189BULL, 0x60F1F2D7844F5D25ULL, 0x718D9E1F489BBD22ULL, 0xF9EDE452FD5EB90BULL, 
            0xF3614CDE5474C442ULL, 0x361895B17AE09119ULL, 0x97C223DD64AE7F04ULL, 0x4B47C5E355A0B223ULL, 
            0x980783307ACB577AULL, 0xE07CC58051CFCF6FULL, 0x96632CF1A54E23DBULL, 0x6FF1735C1317A82AULL, 
            0x484CE82CE0A55257ULL, 0xE18922E7D40389A0ULL, 0xE62104F13430151EULL, 0xDB8F963619203D2CULL
        },
        {
            0x2DB40F55341BBB12ULL, 0x7CB432EC913925B1ULL, 0x5D3D63EA0BEBCF89ULL, 0x16053B057EED2D21ULL, 
            0x6844C66876EAAF2BULL, 0x1A4815D81FE89D5BULL, 0x8DAB6D709E686FA3ULL, 0x9346F7A456178122ULL, 
            0x685ABC3E00985E0BULL, 0xD158E691D11E0760ULL, 0x77B4025AEE1BA684ULL, 0x150B2CFF45907484ULL, 
            0x5791F5B01B31BD8AULL, 0xE9B7540708BA3A77ULL, 0x8A5A77231225A19DULL, 0x5E038C72ECD0C53DULL, 
            0xE55B27D41FE078F4ULL, 0xB4DFCC1205AEE595ULL, 0x63876FADBC9A5C42ULL, 0xA3E797F754D6AF87ULL, 
            0x73F4FC5F8D051B48ULL, 0x53A164EA8E79C213ULL, 0x2E8DA96390D23607ULL, 0x80BF1BE4BCC1C565ULL, 
            0x830E59CF29C680BDULL, 0x1468D65E843B56B8ULL, 0x806B4BF5C6B99F56ULL, 0xBAF88E64A87BC41BULL, 
            0x34E02837B5666638ULL, 0x9FA100616D0E6FC0ULL, 0x49E36F35E0208B4FULL, 0x4AD2D23B8B157378ULL
        },
        {
            0xEAAD020F6BC2DAADULL, 0xDF51BBF643E034E7ULL, 0x9CC0110EA36E8648ULL, 0xCC8A311D49A68574ULL, 
            0x6C02A1F5D8249360ULL, 0x9C552C5C6ECCF53BULL, 0xF3C8B30C1A397B16ULL, 0x83C003E9CEE3663BULL, 
            0xC51A2EDBA729E63AULL, 0x60B540FA81831FC5ULL, 0x3CF413A3CC6778D0ULL, 0x3AE7AE06D67847FFULL, 
            0x8DE21AA0F62C24ECULL, 0xEAE723228AE883ECULL, 0x4AAC4B37C8789AAAULL, 0x475D46081DE9D946ULL, 
            0x823F5C8D4639558FULL, 0x316FA39B35D5EEA2ULL, 0xD7B0BE95ACC89EC0ULL, 0x4F3347C67DC57A9EULL, 
            0x3FF89BB38BBEFB6EULL, 0xE6A99D16C790550DULL, 0x43797DF28ACD3283ULL, 0x84EF72DE5A5E1A9AULL, 
            0xBB6928A98168A642ULL, 0xB4B739C7916CBE13ULL, 0xCD9A020E8BF12393ULL, 0xBB74E809958CDF2BULL, 
            0x69849EAC3E53CFFFULL, 0xB25F5005E4D2497CULL, 0xD8A4908E712A4E3AULL, 0x73226545460FD5E4ULL
        },
        {
            0x9EA9E54A0B460908ULL, 0x97F2C7F85280EE68ULL, 0xE654BBBF31D0E693ULL, 0xCB55241013523764ULL, 
            0x639C0DFB06F5690EULL, 0x9B4C7558147EC9D3ULL, 0x5F468C0FA0846602ULL, 0xBAB02B38D1D182B8ULL, 
            0x26C6B951123117ADULL, 0x950BADD9C9D33DAAULL, 0xE3DEB375477D7104ULL, 0xF5842F1D14F58E62ULL, 
            0xC8B75BE5E6FE980CULL, 0xB10903FC5F96BCE1ULL, 0x1CEFC1CD5B9F6012ULL, 0x152205FC489B0F8EULL, 
            0x43FF8700F3CDA605ULL, 0x49C0443A7CDF388BULL, 0xDD369E52C3E55841ULL, 0x4D979ABC252A82FFULL, 
            0x13D93DD6C745C61DULL, 0x5A6860B92A55A2B5ULL, 0x9A69D2D4C26D3929ULL, 0x0AB8074015FE5925ULL, 
            0x6D5B6A82C213A140ULL, 0xF87E985AC9D747D8ULL, 0x77769F9945366961ULL, 0xDB9302EE9FB26C12ULL, 
            0x8E33E378DFAB8885ULL, 0x505855E9927248CFULL, 0x6FC40F3EE50CFC1CULL, 0xE769690CA6AB925AULL
        },
        {
            0x1D72194AF5848CB0ULL, 0xE70E542ABC0A5F32ULL, 0x2ABB8D846E208253ULL, 0x7FCC6EB23E52A53BULL, 
            0xF029E3CA33B6D89CULL, 0xA713DCA3F0E1DC3AULL, 0xBAD228E20A7DE9A7ULL, 0x4628B0E94C30CCC6ULL, 
            0x29714CD69E71CAFFULL, 0xD9DEBE64A1844D29ULL, 0xFFEC1BF52D6D3D03ULL, 0xBFBEA32707F74F48ULL, 
            0xF999E637405991B4ULL, 0xC92FD11268ED9A31ULL, 0xB3170DF887ABE4FFULL, 0x60849B5605F759D8ULL, 
            0x8591EF14E3A4DE66ULL, 0x274030E7F0B5FF5AULL, 0x93B3B893D1A70373ULL, 0xBD2B5F221F7D1D13ULL, 
            0xED3341902923ADF2ULL, 0xC7E2DF8618AA2280ULL, 0xBBECB2D0A9C35D80ULL, 0x28F24F98C72A8CF1ULL, 
            0x38329C4F7F4D5A19ULL, 0x4F51F385304B7382ULL, 0x65A4CB6F2A871186ULL, 0x7E8F46CA59470CFFULL, 
            0x83E484137D7183DEULL, 0x1032BB018352C37AULL, 0x6B232A2C5DFA393EULL, 0xD041EB1212019D01ULL
        },
        {
            0x31C8F96E71FFED17ULL, 0x0AB546B1AFB88546ULL, 0x02C8C6F920569B99ULL, 0x68DA8809E131B552ULL, 
            0x8515E0709D58C3E4ULL, 0x41304F0CD20EB6CCULL, 0x0F7ED88852F913BCULL, 0xA628E40B40B63C73ULL, 
            0xF8E50E3701E4A8FCULL, 0x921B6A115EC4D5F7ULL, 0xCFB27EDFB8257E51ULL, 0x93E1AADCD7F1A4AEULL, 
            0x41D93B86777874AAULL, 0xC93CD8D06CAE5738ULL, 0xA386575968994A5BULL, 0x1E4B5CBCE158CE25ULL, 
            0x40954209A01A0626ULL, 0xC47046394F3558A5ULL, 0xAE7B52260C23F3D5ULL, 0x8166BE0D794660BCULL, 
            0x5956DDF1B42C2B57ULL, 0xA97E9D9A5C24ABB4ULL, 0x4BD9353545357AF1ULL, 0x2381BDECC0CA316FULL, 
            0x355DEA15D817156BULL, 0xEB27B5C882886034ULL, 0x1ED4EDE4C34B82BFULL, 0xC112FBF2C63521ACULL, 
            0xE80FA8B85BF10A0CULL, 0x4C147233448FD825ULL, 0x78527AF431BAEA8CULL, 0x959338180C3B74DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseBConstants = {
    0xF8C3973E5ABECCB9ULL,
    0x48430D8554C15E8FULL,
    0x0F961826037676ADULL,
    0xF8C3973E5ABECCB9ULL,
    0x48430D8554C15E8FULL,
    0x0F961826037676ADULL,
    0xEA4D1D6C2F638D0DULL,
    0x0D6EDCC3870FD98BULL,
    0x79,
    0xA7,
    0xB3,
    0x65,
    0xDB,
    0xFC,
    0x86,
    0x83
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseCSalts = {
    {
        {
            0xDB9CA83A25C04DF7ULL, 0x140C1E7ADAA08C5EULL, 0xC32C9061E4EBC94DULL, 0x6E22B86BDBDA922AULL, 
            0x1F57027D5DF6D5AAULL, 0x40C3BDB46C09FF29ULL, 0xF982E0CDBA4575D1ULL, 0x0360F5425648E7FAULL, 
            0x5F73624071E3575FULL, 0xD966008FE3A4DBA1ULL, 0xC2573C9F3497B100ULL, 0x3617042E002F7D59ULL, 
            0xF849DA440D31E072ULL, 0x1817F92708889D7BULL, 0xAEE05D2945489D1AULL, 0x906B99F1D1E093A2ULL, 
            0x430C5E06F6D5B23CULL, 0xB2825DE789D7DA39ULL, 0x545A5F8A0BA7D6E6ULL, 0x6DDC58812F006C69ULL, 
            0xCC425787A2FD2879ULL, 0x0ED303D59FBA9857ULL, 0x34C294C8FB18575DULL, 0x69D23AF71DE3294FULL, 
            0x389CF636DEE58956ULL, 0x74C159351854535AULL, 0xB1C4CD6F5387FFBEULL, 0xC7E2DF9227A2C9F1ULL, 
            0x8F6FC0B72F6D3D20ULL, 0xFE201D8149D7A21EULL, 0xAA20B48BE2E65CEDULL, 0x57CBEA0E4C3E27ACULL
        },
        {
            0x55D33F79D39013F5ULL, 0x4B880C05C21FE0D2ULL, 0x324DE1EACF92401FULL, 0x39DD238EF36D50BAULL, 
            0x436604D52A19FA0DULL, 0x80F6B335A12E2812ULL, 0x5B46C009C1309437ULL, 0x023A85E8AC8C710CULL, 
            0xE62C07F406EA781AULL, 0x6EA58E56C5CA2D29ULL, 0x1523B0E4377D3299ULL, 0x13CD9A2C4383AAE4ULL, 
            0xAE2D95946DF2CDF8ULL, 0xE00914F4114AF008ULL, 0x6CF65EDA438E437EULL, 0xBFF20B063821D2F9ULL, 
            0xEE9F4A3EFF9DDCABULL, 0x8D54B4AB9F6A3E1AULL, 0x212822A5CF5F9AC8ULL, 0xFA7B018E4DAB13DCULL, 
            0x1044A41E6436D9B6ULL, 0xFDA259BF6D8BCD5FULL, 0x63DC02075E2FB284ULL, 0xA72707774A67264CULL, 
            0x3DD1628FFCB2721AULL, 0xECB95D8FE21DF153ULL, 0x998E2F96A4B1581CULL, 0x427662A5849F80FCULL, 
            0xF55C65D0240A0D5FULL, 0x7CA00ED2AAD44189ULL, 0xC3B0F27958FDDCC5ULL, 0xF5256EF036B34217ULL
        },
        {
            0x351718C32ACE7DE5ULL, 0x2AF60738436FDF4AULL, 0x48615065E9EA44D5ULL, 0xD384C6A80319361CULL, 
            0xA2F4AFFBC584FFD0ULL, 0x1179BFE14895C864ULL, 0xE24B000ED70503C5ULL, 0x165F3C1E3701CFBCULL, 
            0x974A139B062E4F30ULL, 0xB151ED71D74CDB53ULL, 0x414608F0ED290DE3ULL, 0xFF42C637278F3557ULL, 
            0x82D9804A23F6AC14ULL, 0xDEA9C112D64E2D79ULL, 0x9B949E81A8A5A604ULL, 0xF6701835C413D6B7ULL, 
            0x2A45B6ED983333E7ULL, 0xBB52FDDD488BCAD9ULL, 0x3C88B598F7A31946ULL, 0x700920A6DDDA9BF9ULL, 
            0xCBB0A9785C827012ULL, 0x75033BC22F5967ECULL, 0x43CB63F85D5D1832ULL, 0x4B96D9611219C9B0ULL, 
            0x0F29FB6ED33D5AFCULL, 0xDB8A5E2BAB0E8310ULL, 0xA6B2FA938464AF53ULL, 0x79FF98821937EBA3ULL, 
            0xBCCAA0C5A47AB895ULL, 0x2DC9C45F2C339C40ULL, 0xDC16C74ADC6CCC1BULL, 0x48CE589732D5E777ULL
        },
        {
            0x394381F1F1834185ULL, 0xDAEB05E7008448A7ULL, 0x83EA8DBB05DA69A9ULL, 0x49AF90F77FA959EDULL, 
            0x300C328CBDF61204ULL, 0x27CD8EEC132E8364ULL, 0x167D27D656E8CAC6ULL, 0x41625BCA74565915ULL, 
            0x21FFE1DC1B496A55ULL, 0x6146F27CD0F99753ULL, 0xEDA8461DDF7A82F6ULL, 0x47D7C4A2A42B4A96ULL, 
            0x62E81E62BF0B5EBFULL, 0x40CBDC78C1E89A1CULL, 0xEAD20F56F22794C7ULL, 0x607AC5A884AF74E4ULL, 
            0x4174744003099888ULL, 0x0E117D8D7BAF34D0ULL, 0x465B1D7F374F7B9AULL, 0x095BB58A0054D7DDULL, 
            0x7F830E527F4D096CULL, 0x5AA4D78F74021ADFULL, 0xA569ABE8E0E500F4ULL, 0x9E0E07C080C8AAF7ULL, 
            0xCE2231C034B115B8ULL, 0xF8B9B6521882F8C7ULL, 0xCF47F6F423BC3CFCULL, 0xC1D5235FA7865DCCULL, 
            0xFDB0F6D93ED4FB6AULL, 0x737DE66E7B4612A1ULL, 0x1708B50E9842FA7FULL, 0x17EC699BDA81FBBFULL
        },
        {
            0xC42D10CB9F7106C2ULL, 0x7B3395893C628687ULL, 0x7CE90DA3183C3E65ULL, 0x532F0C2561C76CA9ULL, 
            0x07A160FB2E8BC271ULL, 0x5B6520D93064EDB3ULL, 0x879F7FF397ABDAA9ULL, 0x81DA6CAF77287229ULL, 
            0x908E0D3A73CD62C0ULL, 0x784FD85F40F316E1ULL, 0x1D2E6185C3679DFDULL, 0xB442E7FEA91ED084ULL, 
            0xA98581E1BD67C9A0ULL, 0x77C883410E9A4F51ULL, 0x3C072A4C362D00A3ULL, 0xB955C8436BAB4E8AULL, 
            0x7F1C959BCCB215E6ULL, 0x5E19BF6BACF13A86ULL, 0x64492E0E725FEADBULL, 0xDAFAC3124EE15AA1ULL, 
            0x2EB7DD87369D6CB6ULL, 0x7C5B60214A3F6026ULL, 0x1BB9A5AFE6ABFEB9ULL, 0x430E8C747D8C87F3ULL, 
            0x970475159B3EB987ULL, 0xCCC06868240BFE88ULL, 0xC0016AFF6C186A4CULL, 0x3A32D6BE96DBE133ULL, 
            0x33039F6D77FBFDBDULL, 0x4A16B3B77F0EC70EULL, 0x2A5DA5B0E06F1299ULL, 0xD1179AA526556F00ULL
        },
        {
            0xB14B96CFAB183F72ULL, 0xF44AFE1A7E519DD7ULL, 0xE94B09E99022A06AULL, 0xBFD16E8BC1277A1EULL, 
            0x178E836E7785292FULL, 0x3A22F26CC2E0DFE2ULL, 0xD69A826592D5B800ULL, 0xFA9F3A7F28439B87ULL, 
            0x6BF0F66704E58631ULL, 0x86ABEFECBBD1FAB2ULL, 0x675CB5B9AC27ACC1ULL, 0x79EFE8F0C5BADE47ULL, 
            0x837F3835DF24BCE1ULL, 0x3D22F46C10B738A8ULL, 0xC6455FC936C25193ULL, 0x170EA670A82884ECULL, 
            0x1F629EC09F5D7B92ULL, 0xB43038574D19F1D3ULL, 0x5D46BA5D2E57988AULL, 0x5153B4004287D9CEULL, 
            0x5CF75E44B3A03A1BULL, 0xBD819A4FC3B1EB4CULL, 0x9F312E3BC469577CULL, 0x7F4D13BA93A1025DULL, 
            0x710FFE53A2547B03ULL, 0xEC299ED945E1B9D3ULL, 0x97D32451C6BF291BULL, 0xB21FBCED4F0864CBULL, 
            0xB2D09BCE83DB2798ULL, 0x6A052CD3899A84A9ULL, 0x77348A1FD825BC65ULL, 0x9626BCDF6D2C648AULL
        }
    },
    {
        {
            0xB74114870D5EE8FBULL, 0x1F0B07FAFA4CB2A1ULL, 0x4BEEE662B7BC9FF6ULL, 0xA8B04D11B5A0F445ULL, 
            0x44090E0528EF4DE6ULL, 0xB341AD5CD528310EULL, 0xDC7560D3D967DC51ULL, 0x7B3395FD36A09F4EULL, 
            0xB87B407FA64C0100ULL, 0xD92363E1BF4C04D2ULL, 0xAF1E51D7FFABDFF5ULL, 0xAEA2317603DEBCCAULL, 
            0x0AEDBDB8E00A1C4AULL, 0x9E05CCFE999A280BULL, 0xDC88D3091BF53177ULL, 0x47B15FED9082ADD0ULL, 
            0x44FD1860898CA9DBULL, 0xAA2D5CB798053012ULL, 0x1BDB54365EABCA66ULL, 0x450387D333FC73F6ULL, 
            0x444CF50E4FA4A90AULL, 0xF0B5B8BD9C3DAE29ULL, 0x798AE4424D68A3D3ULL, 0xB64B2EE0581EBD35ULL, 
            0x793A4A8AD5A7C10FULL, 0x1C3141735A8B2009ULL, 0x5721245EE0ED41EAULL, 0x45C6DF20E182490AULL, 
            0xA02794934D75121AULL, 0x6247A15C1D11AE43ULL, 0x37B402FB0F45D4DFULL, 0xA188F1B7D8E2D8B7ULL
        },
        {
            0x0136E71AEC2D355DULL, 0xF0E20D1CBBBB4AB8ULL, 0x1ABBA9F279A7B94DULL, 0xFB07E6953F474207ULL, 
            0xD27857749B5FE587ULL, 0x92302376721F955BULL, 0x1D05794E0501FC6FULL, 0xA858C93AA5DCDD1BULL, 
            0xB4192060C125EA23ULL, 0xB4C937E3B4F075C3ULL, 0x7A9EFED36DAF342BULL, 0x51C3905DE7067CECULL, 
            0x6F1A11E853881DD5ULL, 0xC1F49D126CDEFCB8ULL, 0xF7B324DA71A9FC25ULL, 0x25F4097280FFB68DULL, 
            0x4AD0ED7EB4F17F80ULL, 0x468ACEB72835751AULL, 0x6E321F9301F9F266ULL, 0x48275D92110CCDE3ULL, 
            0x6CD24116A7264DF7ULL, 0x63A115C1538A6CE3ULL, 0x92F846269E21FA49ULL, 0x452228280B36F1C4ULL, 
            0xBAF31FB2F437A596ULL, 0x3508E9B11FE78DCCULL, 0x3861FDBCBB374BC6ULL, 0xB2B4E8E8B17E951EULL, 
            0x3F15C1E9C709FF42ULL, 0x43A55723B1EB953BULL, 0xFA43688D11272EE5ULL, 0x919C55D2CED72A88ULL
        },
        {
            0xCC4299589FA33A09ULL, 0x6E47C795D7450FD1ULL, 0x9CAAC2619BB1063DULL, 0x12F6835C726E7462ULL, 
            0xA7A8ADD5C7DC088BULL, 0xE664AED085F657B3ULL, 0xAFF92C475A8BF5DCULL, 0xA2F27C474F325462ULL, 
            0x3417CEDC864646E1ULL, 0xFF63ED26DDD6921FULL, 0xF0EAE8C0031FE698ULL, 0xBB28AD1785955BE9ULL, 
            0xF231919CC4165E72ULL, 0xCD20823BA44A1305ULL, 0x13DB9D9CCC16279FULL, 0xE2BC78653759DD00ULL, 
            0x78B0929CAB6DC2FDULL, 0x6DEB7FEF65FB3D6CULL, 0x5CA640F88BF58D69ULL, 0x7522ACCC35876DC9ULL, 
            0xBF0141DEF5E0D9E0ULL, 0xE83736782006E42BULL, 0x5CA0B3AF7B82A7EFULL, 0x06B7A38C535CC080ULL, 
            0xBD2F1CB4C181FFB1ULL, 0xB9833E6CC3CD8EEFULL, 0x786864AEFF1BF393ULL, 0x1E8768B74C751578ULL, 
            0x4EB80B9DA48EACCFULL, 0x367AC9798E9CF76AULL, 0xFD01B654A4D5D9ACULL, 0xE5E8CE8C2D9EFD6EULL
        },
        {
            0x9B3B1FFBEEC1EEA8ULL, 0x6BCADE6A59FBC156ULL, 0x176C107DC187F8F1ULL, 0x63B9B501278D81CEULL, 
            0xEAD8FF8D859140B2ULL, 0x79B294BB4B7933B2ULL, 0x44E1EAD7E870ABB0ULL, 0xF6CD7D1E7BC2445EULL, 
            0x4E779CB76850F18FULL, 0x0FC4D53591197FCAULL, 0xFE5D58E696E0FD96ULL, 0x5E083862F727213FULL, 
            0xC2B73414E56711A9ULL, 0x7C694A9128EAFB3CULL, 0xDD504EE03A56B26EULL, 0xDAEAB00C4968DAA6ULL, 
            0x2CE5176996593C0FULL, 0x43E36E5471051E8EULL, 0x03E5147405A4C14BULL, 0xB64690CE2A5DC534ULL, 
            0x22D95BC47DAF914EULL, 0xB8CB473592A98DF4ULL, 0x6C1D637758957A45ULL, 0xB128E5B31FE247CDULL, 
            0xCECDA8E0F0BE82BEULL, 0xA120914B8BB31306ULL, 0xB3793141AF9C8048ULL, 0x69DAB17A369E4BBCULL, 
            0x277FEBB2A6B6D9CBULL, 0x12059531753A05F3ULL, 0xF7A9654AE2C430D8ULL, 0x0AE58311D7C6BD44ULL
        },
        {
            0x103C21860A196E95ULL, 0xFCC5A429B2DD1514ULL, 0x6A2BC3F9466F1372ULL, 0xFF11D8E8D43D78C8ULL, 
            0xD8F99ED416D41269ULL, 0x4846D8442ACBCDBCULL, 0xFDD4D1A14E6BE682ULL, 0xE33389B9D5C6D049ULL, 
            0xF3395AB32CAEF3D1ULL, 0x40AA13264BE01C42ULL, 0x4479E84BCB0FF917ULL, 0x812C31A9EA3983C6ULL, 
            0x78450064F1C25C18ULL, 0xC077367D6EADD2DCULL, 0xF08ABAE448943DA6ULL, 0x37A13559EF84C016ULL, 
            0x698E8F55A1FC5416ULL, 0x88DDE929291088FDULL, 0x960B223BCCB4CB51ULL, 0x8EA732E644E36667ULL, 
            0x9DB4B9D1A6F623C7ULL, 0xC3CEAE12B17353CEULL, 0x86D1CA81F4D5112AULL, 0x714D1927A88BACDBULL, 
            0x7B9BC97D4AEB0067ULL, 0x0C90BF059FD0D29AULL, 0xC12EAAF3BC71DB07ULL, 0xA1BF07775D08C5C2ULL, 
            0x7C3F166405AEE052ULL, 0x2C330B4A178B3590ULL, 0x0DAF783061F8B79CULL, 0xDCD861665C54E5FDULL
        },
        {
            0xD95A4D81699E6C25ULL, 0x2DEFFF2199EB9626ULL, 0xFF2656BCF8716603ULL, 0x2B83BE8FEBC2475AULL, 
            0x51255F049CFC8624ULL, 0x95AFF3FF2F23AD28ULL, 0x3F10B55C6743A7CAULL, 0xDEE94AF7AF80F7DCULL, 
            0x76B1E5867BE0A09CULL, 0x454D4024949049A4ULL, 0x0B569364E3DFB024ULL, 0x7BF5076587282A68ULL, 
            0x40FE559E8A0B9EDAULL, 0xD5870C23FAB1CCADULL, 0x4504DFCEF3578C64ULL, 0xB6A16CB4E85D70CBULL, 
            0x3F439AFC3948250AULL, 0x360A03D36CA351D8ULL, 0x9981E8E88EAF3537ULL, 0x1FC89A38C5E14511ULL, 
            0x545F5DA124AF2685ULL, 0x87E81C414166A349ULL, 0x846F1D5891F4CB6BULL, 0x888BF7D8129B7032ULL, 
            0xC03032990FB6C8BCULL, 0x86A32EE68248BC0BULL, 0x3E3B188DAA09A2D9ULL, 0xE277BDC5D1C7D5A7ULL, 
            0xE3C2BE563A2D5193ULL, 0x7AF5E0E073776177ULL, 0xDD87D5AAEA36F89EULL, 0x506BD07BA96E609EULL
        }
    },
    {
        {
            0x6C49E9084C435253ULL, 0x7B4DE3276A188A1EULL, 0xAA32B0A58ACB6EDAULL, 0xE33998AB55836922ULL, 
            0x3CEB796A0511494CULL, 0x1E1E1B487E2F4112ULL, 0x6527D9E6CDD95571ULL, 0x62CF253090EEF9D2ULL, 
            0x133FA56473694888ULL, 0x6A3F25CBC1ABF888ULL, 0xA7FB47ED74D36DD1ULL, 0x399036766006A8F1ULL, 
            0xD1272AB7EB017451ULL, 0xF04FCB271A756C8EULL, 0xC25B4002FCD7848BULL, 0x99E6C091AC345615ULL, 
            0x21D6D449B8072548ULL, 0xA2168C982D64732FULL, 0xA88202E9BAB721B7ULL, 0x38878A80FDA01B31ULL, 
            0x2D471FEA376D1BB0ULL, 0x3C85EB82F5EB2841ULL, 0x73CB6A3F2D88C26EULL, 0xDEC8D962A6B84000ULL, 
            0x1721D93AA16BF060ULL, 0x7F500C5EF9E951F5ULL, 0x93340983CE2B1231ULL, 0xB0F5E627BA924BF8ULL, 
            0xED73E7A664FFF1B2ULL, 0x57CE85D11B1C1196ULL, 0xD6AD70E9EFF6035BULL, 0x98E041323FE351E0ULL
        },
        {
            0x5169091032EE7932ULL, 0xBA8826D764DADE1EULL, 0xE3E15C630C5E050DULL, 0xB89D7DFD5D6705C3ULL, 
            0xB2C8EFFCF916E007ULL, 0xA133DABC7E23EA55ULL, 0x9702DD919679A2D4ULL, 0xE80A2E3EFF49D07BULL, 
            0xFC9B6DE544375F5DULL, 0x5A7AF34E6AB58983ULL, 0x1745F40171F5DF65ULL, 0x384E11B46EFDB622ULL, 
            0x8748C7FDE526AED3ULL, 0x7B40734EACD906E5ULL, 0x3D52C58C73096ABCULL, 0x5743D308EF891D90ULL, 
            0x9BF18C9C2E3AAC85ULL, 0x6C4F3D00E6F91C7DULL, 0x3C9E61719D2C2E1DULL, 0xD39DFA2E641E52B7ULL, 
            0xE8B526832085F9E5ULL, 0xDCEDE250D5FBDB61ULL, 0x93F13F8B4593B615ULL, 0x8BBC4C6758EF2AAAULL, 
            0xD1AE1250EECD8406ULL, 0x195429358749D91FULL, 0xC5E12E712DD8A7DCULL, 0x6DF7CB17CFD4386FULL, 
            0x5526196A0533F48FULL, 0x54B0900B6B6C65A9ULL, 0x31E40E75E1E1B1F3ULL, 0x3C79B11610EFC716ULL
        },
        {
            0x93CED8F33443E87CULL, 0xF5492E6E96D2584BULL, 0xDFC4998660D1A74AULL, 0xED9E157064C4D1B0ULL, 
            0x101548CB3D7AC1C5ULL, 0xC0D1EA1CBCF65069ULL, 0xAB0AC83A71FD991CULL, 0x10C3C7EA159A5A22ULL, 
            0x5FDE96C6534B1A48ULL, 0x1726935F8AAB5033ULL, 0xA98A0D02C3A06DF4ULL, 0x7CDC1C4539E7F238ULL, 
            0xE8AF06784F272275ULL, 0xA249DA3291642601ULL, 0x6C321A5BAF4B1E47ULL, 0xF3D03A1CB878D937ULL, 
            0x5BD8ADF10BAC29D2ULL, 0x9BB0AA439AAD75E4ULL, 0x21240ED35C4B564DULL, 0x860F0087B6572FFCULL, 
            0xACB9561709D51666ULL, 0x9C3DEBA8717FE0C3ULL, 0x6D3F84059B54EF9FULL, 0x7D0CE331D4763FACULL, 
            0x3202B26AEBF9C53DULL, 0x6FE099F85FB9C1E5ULL, 0x1093F581B71F27E2ULL, 0x23BA34F2C13FE3CCULL, 
            0xF0EE94250CD867ACULL, 0xD7712B56943BE563ULL, 0x875CB048476C5842ULL, 0x65A9A5F2B2F0E8E5ULL
        },
        {
            0x1ED2E0DFFF221044ULL, 0x6E025E45C7A79053ULL, 0x9911D44A0E28970CULL, 0x812278C7EC0E2728ULL, 
            0xAB4EB4AB49F8E5F8ULL, 0x97ECF6E36BF1D935ULL, 0x0A3CE7D4DEB69EEBULL, 0x643A56BED64C6BACULL, 
            0xCFEC17830C1E4F35ULL, 0x3985041FE6F1B6A1ULL, 0xDBD0F2AF8D5DDBBFULL, 0xA1CD9651BB4274FBULL, 
            0x923CE08976FB79ADULL, 0x6332E45DFCAEDF7BULL, 0xDFBC34194B56F146ULL, 0x2544513725E31925ULL, 
            0xEEDD647D54EAC873ULL, 0x6F5EFCE17591C061ULL, 0x7CFF4F1771DB3426ULL, 0xED08A6EAC124F5E7ULL, 
            0x8026BB66E017395DULL, 0xC19A35095E6B7B62ULL, 0xFC91A62D0E922F89ULL, 0xE620474BF42244D1ULL, 
            0xF297E7E2F362FBD1ULL, 0x9358D447F6DB9176ULL, 0xC15A27F7C145BB01ULL, 0xE560E089A51A1B48ULL, 
            0x387C30EC896C427DULL, 0x58EECFD35717799BULL, 0xFE3FA485452F11F4ULL, 0x2DB6E017AAF68B0BULL
        },
        {
            0x8B67FE5FF72D1D2CULL, 0x466DD53E0EE76FD2ULL, 0x5A063BB5F54A4D31ULL, 0x9E07282182B92555ULL, 
            0xB4AB74CE32196777ULL, 0x068F7771B1CA6D1CULL, 0x2DE423F39570ECF4ULL, 0xC7B0DD3DB6CD5619ULL, 
            0xCA2C65282D5B6ADEULL, 0xA2991DDB969BB3B2ULL, 0xDA848A040A16B545ULL, 0x69C4AFDCCB590F98ULL, 
            0x35EC81B5597D6FD5ULL, 0xBDEBE99EF08D47EEULL, 0x2133C207AC7469E9ULL, 0x51F02187B8241FAFULL, 
            0xB240AEA69AA9E907ULL, 0xEFA0803D58CDA5C4ULL, 0xD952E6948BBF6F0DULL, 0x9573ED4131A96A11ULL, 
            0xB356CB8EF68ADF9DULL, 0xEB148A99F3537717ULL, 0xAEBD72041EF71EC2ULL, 0xB8A167BE6A4D9801ULL, 
            0x810919D974D916CEULL, 0x45B6E0B13A41B938ULL, 0x38B1A2BB68F7A10BULL, 0xD812A27C8C168336ULL, 
            0xD3829110C5A285D1ULL, 0x920697D710992ABAULL, 0x5572D7D97BEAFC6AULL, 0x724C5108D06513F9ULL
        },
        {
            0x9425053082908260ULL, 0x49B6854489090EB9ULL, 0x8ED7C2E105A390A5ULL, 0x00F0219B716F529AULL, 
            0xAB53F0CF2B90F5E9ULL, 0x86B1081D539BA8E2ULL, 0x842781A208F8621CULL, 0x4A9B2C931AED0D5AULL, 
            0xFC2E4966CBC50F64ULL, 0x02FD988CF0B094E4ULL, 0x71FC1E32363A5035ULL, 0x3C7EDAE19E912721ULL, 
            0xF237D73F8A3E6CAAULL, 0x801C07F79429A135ULL, 0x22887731D0FEF5AAULL, 0x351AEDFF2C94E2DBULL, 
            0x342FB3E1FFB4E1F9ULL, 0xFA0E8D56357422E2ULL, 0xB5BD43D821EA5D92ULL, 0xDCE7858D317270D3ULL, 
            0x6AA54B28A5AABA41ULL, 0xC77D47AD973F50FAULL, 0x5118FD435E3024FDULL, 0xE4575EFC3B76551FULL, 
            0xED74DB51C7D3DBCBULL, 0x4504E55AC3AB22BEULL, 0xD49ED01AEAD03F47ULL, 0xA55FACDDDE990177ULL, 
            0xDF36CD2CF57E6590ULL, 0x3EA2B43E6BE184B7ULL, 0xF8B537E0EFD7C66EULL, 0xE0B730B6811FE449ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseCConstants = {
    0x5C6A538BCD49A687ULL,
    0x5D281AFE85C66097ULL,
    0x9346F78BCBC49278ULL,
    0x5C6A538BCD49A687ULL,
    0x5D281AFE85C66097ULL,
    0x9346F78BCBC49278ULL,
    0x7587FC16FF30F792ULL,
    0xB8B07C667BC590A1ULL,
    0x89,
    0x6F,
    0xB3,
    0x6C,
    0xB7,
    0x7A,
    0xC3,
    0xDE
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseDSalts = {
    {
        {
            0xE9A105921C1B8C7EULL, 0x424CD5D3516F9D78ULL, 0x089F6FCF3D101BF7ULL, 0xD7589F94A3D2081CULL, 
            0xD6869B8409DA69EAULL, 0x6E1F98D78B611FB0ULL, 0x87EB70C9030E7445ULL, 0x533155AAD1FFCD45ULL, 
            0xA5517AF3D5D4A47EULL, 0x78C76CB85EC36C3AULL, 0x87DFE082A3B0A4CAULL, 0x69E42317F456150FULL, 
            0x2495F22AEE6FE688ULL, 0x66725263510BFF91ULL, 0x0B882923EE13211CULL, 0x5DAC993C1BE9F06AULL, 
            0x0A7B831B32A40A7EULL, 0xF4E84A6AED0B2ACCULL, 0xD6256F93C412CD32ULL, 0xD61BC135446AE7A6ULL, 
            0x891FE05D5EBC9185ULL, 0xF0776B0AABBC68F7ULL, 0xA3AA101037F9EC55ULL, 0xEA4D04B8CF9123CEULL, 
            0x465DCFB41FD5932EULL, 0x103EE9061B89E003ULL, 0xA7C470EE93CB1E5DULL, 0x0C05207869B505B0ULL, 
            0xABE4ED8FC005A1A9ULL, 0xF3D1753415C1D744ULL, 0xFF509391FB463AC5ULL, 0x8A5F812CAF0C798EULL
        },
        {
            0xB2003FBE5A86C111ULL, 0x89ADF644B7B00DD8ULL, 0xFD0BC03D8DF6338DULL, 0x26EAAD25692B1468ULL, 
            0x23E8DF4EE3625B6EULL, 0x735681C6BE3EC316ULL, 0x45A3E014345049CCULL, 0x07D295E3BA39ED9FULL, 
            0x2096E48E544DD1A1ULL, 0xFD691F4DD5E5C985ULL, 0x92482E3319768A3FULL, 0x4664F8BC6BFC5B4FULL, 
            0x4549CBA15D3733BDULL, 0x67FC99BE1C9F8CEEULL, 0xD8A684C7D1E9B2EBULL, 0x465B1EAD1C93A150ULL, 
            0xFA0D1BBFD6ED85B0ULL, 0x6D043839FDFD786FULL, 0x013FA61F3E93ADE7ULL, 0x5E5C86D3346531D2ULL, 
            0xD2BC6F0C907DF151ULL, 0x6BCE23A755F8B9A8ULL, 0x6FA67C06895A948FULL, 0x676110956E85B95FULL, 
            0xEFB019342739AA83ULL, 0xF78C767296F8F2F3ULL, 0x398491AD3D28760EULL, 0x1494770604195622ULL, 
            0x162538189EE068AFULL, 0xF623E8CFEB693B32ULL, 0x432F208E19AE77F3ULL, 0x4FF7284AE7B97171ULL
        },
        {
            0x0F5C58F7D96C4CC3ULL, 0x5AFAA18EC5320B18ULL, 0x2831D9C2FCE02744ULL, 0x64237FCFE0139D89ULL, 
            0x1EB0059C6E7DD042ULL, 0xF6E5E7791A29BE2CULL, 0x7F3E52E5BA572E33ULL, 0x203586B735BEF74CULL, 
            0x2AD8D4EAAE34990DULL, 0x494B617090E08C64ULL, 0xE70DDF5BEF38CA7DULL, 0x002E2556E8FF0739ULL, 
            0x686EFC51C76142A7ULL, 0x1968973D5F4B0417ULL, 0x0285D62B977CB3CBULL, 0x9C5ADCD6C7FD39C1ULL, 
            0xEA2276B180D4F091ULL, 0xFDA6369439E6A5FDULL, 0x717C9FB858C83A6DULL, 0xA41D9ADF42A27F56ULL, 
            0x87ECFE879B5F3121ULL, 0x78370EC2E4EA7F79ULL, 0x958AEEF1692A1CB9ULL, 0xCF5A5F5736AEB323ULL, 
            0xB6DD3DA1B4B5BCB4ULL, 0xF65F8A88D88A472BULL, 0x8C1A911AB91797F7ULL, 0x3AB1880060C29858ULL, 
            0xF3CBBF672A5EC833ULL, 0xC63331488198A86BULL, 0xCF1F611F063D1422ULL, 0x31361C63241C8B5DULL
        },
        {
            0x14F871A85714F6ABULL, 0xBE6D6CE807140374ULL, 0x5B14429D0E807789ULL, 0x93E8C2E9DE07EEE8ULL, 
            0x348B284FB6B95716ULL, 0xC7BC7C8F36726DBBULL, 0x7111ED1D3B9C1788ULL, 0x98A6BB397D672D46ULL, 
            0xAB30B2D4B2BF4188ULL, 0x14A69073A20A6CF8ULL, 0x15600C873C9A2899ULL, 0xB362D17625F818B4ULL, 
            0x50CBF6F24C3AED33ULL, 0xEFA3109146F2263FULL, 0x008F4C0053C04DD6ULL, 0x9A880E9A1B293A1CULL, 
            0xC539DD3B230EBFDEULL, 0xE3AEE42B5A811947ULL, 0x33D0D79E0D3D1464ULL, 0xC30DB2B683FAE924ULL, 
            0x23C39F15415718E8ULL, 0xE5E70314B98A1D62ULL, 0x2E3821BCE98FC4BEULL, 0x94E845217CF482D3ULL, 
            0x701476269E25AE72ULL, 0xAEE997D9AFB56886ULL, 0xE9F23143B7FFFB84ULL, 0x829B44AB8E96B1F8ULL, 
            0x9FC7CB95F6AAE0ABULL, 0x79A3F56835B5E805ULL, 0xBBF6F7557C485BD6ULL, 0x9A4EA18218517BC2ULL
        },
        {
            0xEDA8A4C25DB2194CULL, 0xCFBE9A1FB0FE477CULL, 0xDE8342C794A43AE6ULL, 0xFB37CCF480410CC3ULL, 
            0x5B7EBE76C788F480ULL, 0xBC85EC02C4DC9FD4ULL, 0xB6A2E19FA3196662ULL, 0xE89BD2B44412253AULL, 
            0x618F6DDCA5642009ULL, 0x3DA79C198E96E215ULL, 0x1F52398D6F282E2DULL, 0x2E16AF0909581E0DULL, 
            0x8D3111C48430F863ULL, 0xE3B25D60E5BBE8BEULL, 0x879BDF39339CF658ULL, 0xE69CC773EBD4D1C5ULL, 
            0x54307F9CCC723CE1ULL, 0xB80D749D5B4D8A49ULL, 0x6972285B0E4D3BEEULL, 0x96CADD4B6C4153A8ULL, 
            0xD5E5896B94D6F621ULL, 0x9BAC79F931E80E5FULL, 0xB93273EBC2BDA5A7ULL, 0x834920F07C492F77ULL, 
            0xEFC83147C463F9ACULL, 0xDA7C6305DEEF3D39ULL, 0xC63558F9B927F17DULL, 0x37382099628D230EULL, 
            0x6B79B729AB3F5D5DULL, 0x96D969C3F8DFA532ULL, 0x999707D12CC15AF8ULL, 0xC4A9FEB18054F83AULL
        },
        {
            0x452446DA09B0BD15ULL, 0xAF3E8FD70F940776ULL, 0x0C1E6A6F39593A0BULL, 0x21BD0A1A2FD9A6E1ULL, 
            0x17727ABD72F08461ULL, 0x9BD30C0B46FF35E1ULL, 0xA60402396F5D8CF6ULL, 0x026F56BF9D399AB2ULL, 
            0xD8B44165AB6A3BE5ULL, 0x5FD0AF8D5D427AD2ULL, 0x4C0EA079AB794E6EULL, 0xE96614A66196765FULL, 
            0x2EC9C2B1DA2F0644ULL, 0x800D9D18D617FD31ULL, 0x3E76D2890F3E297AULL, 0x8805106974021FD8ULL, 
            0xD8DEDA3E4FCDC508ULL, 0xBA8EA503B4C2B245ULL, 0xF72899C3C5F5CEA3ULL, 0x30BC4DA81DE1E1A9ULL, 
            0x8AC68C44049D469AULL, 0x238E9C39A5352F1BULL, 0x4598A7FE5660B64BULL, 0xE3BDF18890ECD864ULL, 
            0x840C547B9925EE43ULL, 0x787B8B08DC944815ULL, 0x15FC5157A83E444CULL, 0x843089ED74279055ULL, 
            0xD5BC8C7DE852ED71ULL, 0x7DF602B25A23FAF8ULL, 0x028347DF9EF7EE9EULL, 0x723FDC602D4E5672ULL
        }
    },
    {
        {
            0xA9AE66F88A25E444ULL, 0xCB95839A36704066ULL, 0x837ECD6CC445EA02ULL, 0xE7660AAF0D6902B2ULL, 
            0x602B5365919E40F4ULL, 0x06EED89937ED49D2ULL, 0x4B128E4331D854F6ULL, 0x6DE81119CCD584E3ULL, 
            0x60143C2D0724D316ULL, 0x5CD5EFE232E472DAULL, 0x641EDFF9B5C19B60ULL, 0xFE036F3FF9475757ULL, 
            0x050BB39432E92515ULL, 0x25C3CD36661EF349ULL, 0x87859F6E2A34612EULL, 0x4AA1CD4F6787C430ULL, 
            0x2168CC8B3E56D023ULL, 0xDC722284E8CC292BULL, 0xE637C43B7CF75B4DULL, 0xCF867A9C65152A8DULL, 
            0xB3506363B91C245AULL, 0xBDE99C6C1E8FF641ULL, 0xBB90CEFE6F4F816DULL, 0x1C086DFB516798E1ULL, 
            0x1E06B5DDDB7A0393ULL, 0x0BF2007C51ACD18FULL, 0x249F5B31F089E45BULL, 0xFF71D3FA0DB0E149ULL, 
            0xC72B37666B099C72ULL, 0x0D0B60590A35CCE4ULL, 0x1772ACB844303473ULL, 0x3AE75668D87E660BULL
        },
        {
            0x665E3D03F859036BULL, 0xC1654CFA89535425ULL, 0x90BA330F2830B51BULL, 0x16FD544DD1BAF2FCULL, 
            0xEC111F66DAFD2579ULL, 0x3A30184F3589982CULL, 0x7BAA2F025CACE3A9ULL, 0xC5889B972C585969ULL, 
            0x2FF4F120510899A2ULL, 0xEC993097C2B1CD60ULL, 0x6657B1E60FCCDE82ULL, 0x5619ABDC2A48A50AULL, 
            0xBB55F0187D25F10BULL, 0x0B7BDE191BC1DA13ULL, 0x54EE0E4BAFA5E3C0ULL, 0xC3E186433B85D93EULL, 
            0x3A2BC9FDC624E6D1ULL, 0xF2B4E1A0CA60B747ULL, 0x220751E1EE4F6BA7ULL, 0x8DC5D27755588DEFULL, 
            0xF688EDF31EC3F3BFULL, 0xED20C10A62C6C76AULL, 0x16D4D01873C74E76ULL, 0x965D63B7DE3E20F9ULL, 
            0x549CD0C0A989C389ULL, 0x83AE14CC195160D7ULL, 0x174AAD1338D6704EULL, 0xB649916DCA965296ULL, 
            0x5ECC1900580A7D1AULL, 0xAFF7DD64981B7795ULL, 0x04191418B82B62BFULL, 0x93CD049B3560C678ULL
        },
        {
            0x6F506ECDF576E748ULL, 0x687691D0904DFE94ULL, 0xEE66BE48CB2B1EF6ULL, 0x0BEE5BF245E9D477ULL, 
            0xF062A08B2A197EFAULL, 0x9E762D52A2CA3750ULL, 0x200FBD40628FAFBAULL, 0x4FA3616C445700D5ULL, 
            0x25E7EA98528ED045ULL, 0x3F8FEC2B8BF46ABEULL, 0x8F5E167BA53B899AULL, 0x8109ABF09079DDB4ULL, 
            0x1238263B2899004DULL, 0xDC790A5CCBFFC3E7ULL, 0x50D69A7AF3741674ULL, 0x8FF5DD62D57BCAEFULL, 
            0xCF4317875D62B8A7ULL, 0xB5C77868E699B750ULL, 0x0E2256C468CAD7C0ULL, 0x4EF852B998634D87ULL, 
            0x3662175CEC0E56EEULL, 0x65AF5F3472CB578EULL, 0x37FBD43B90E4BAAFULL, 0xC14197747608D6AFULL, 
            0xB796A4AE918F26B1ULL, 0x1DEC8C5B4886E3B1ULL, 0x96404C32A732BBABULL, 0x96F7D71C2073D4F9ULL, 
            0x5CFCBECEF027038DULL, 0x6F4EC6E87B9BCCF0ULL, 0x40C9B6AB5AAC260EULL, 0xCC441379F19608A8ULL
        },
        {
            0xE267D3603C5114DBULL, 0x4C387654A3DF9818ULL, 0xC7443EEEA115F1F2ULL, 0x2AE03F3554148039ULL, 
            0x6AF6F887D96B4F75ULL, 0xF4F2F38645BF0CD2ULL, 0x30625C78CBA74189ULL, 0x05CEECBEDE163750ULL, 
            0x1B1B5AD950045C9FULL, 0xD7543EAF90DBCC9BULL, 0x7AC1C86BC7C27E10ULL, 0x2EF9F79583A51CD5ULL, 
            0xF3922DDF43857323ULL, 0xA3789E117253D0E4ULL, 0x36F955D33E6FEDB8ULL, 0x0E86ACDDEDB5594BULL, 
            0xDD27F247FEC08F1BULL, 0xB1E9346EEAD42CB1ULL, 0xFD3C087BB6382345ULL, 0x7ABE781543C1AFC1ULL, 
            0xE068B75F87A95051ULL, 0x7BBC400ECFE2C6CBULL, 0x4CDFDB3DABC40A1DULL, 0x264F5A37DE03EA0AULL, 
            0xB4C3846E51560225ULL, 0x21671DA8F52C9763ULL, 0x9326DF36D6A71CD4ULL, 0x824AFDBEAECDF424ULL, 
            0x162E274228C2B79CULL, 0x5592FABAAB06C0BEULL, 0x49C166E4BEDEF8E2ULL, 0xE43703FF3AC87A95ULL
        },
        {
            0x504617EA4B3C18E9ULL, 0xDA14BFBCC66D2547ULL, 0x992FAFA6D8AB2B34ULL, 0x47537A628AA17803ULL, 
            0xD444082D3020A363ULL, 0xAD24EFBB31F40E5DULL, 0x188779190C40312AULL, 0x501D01F5228F14D8ULL, 
            0x6B2ADDD118DEA432ULL, 0xC20571BCECAC52C2ULL, 0xF9CE3395C0CEAE9CULL, 0x44CD8E82CDC5FAC7ULL, 
            0x6A52EB8B35C2FC35ULL, 0xE6B0B8D4CDFA1B7BULL, 0x6606C3F446B6748EULL, 0x6DCA6B1275999EDEULL, 
            0x7478BD1AC3399A29ULL, 0x5ECA18DADC5ED706ULL, 0x9A002487C9535A01ULL, 0x1FA6499419600564ULL, 
            0xA573548B873869AFULL, 0xB6B4C83F4C66005EULL, 0x9BD630344C6E6B03ULL, 0x43851FD3271D4CEDULL, 
            0xE310AEDFF166C419ULL, 0x5243F0190DEB012DULL, 0xA52FE3A04C4A311CULL, 0x4EC1008C0C425527ULL, 
            0x5A5BA0282F6C12C1ULL, 0x321D499E26523304ULL, 0x8463CCCCDF9A7588ULL, 0xBFFBE4AA88278737ULL
        },
        {
            0x78E78D9EE2495C73ULL, 0x17030A21B0CDDF9BULL, 0x931151FE58174B07ULL, 0xED7B75F039E7BBF4ULL, 
            0x49646A3C814E525EULL, 0x4D4264E05111D5BDULL, 0x869FF369E190408CULL, 0x1E2E08E9136837B0ULL, 
            0xA4CC7754AF742585ULL, 0xCC0DE6F8F4F62982ULL, 0x52DA993AF0DBD867ULL, 0xFF1A3D6EAB7FD9B3ULL, 
            0x522D18139DEB5C7FULL, 0x7033DBDD1C3BF4B7ULL, 0x815C9BC13C13280AULL, 0x488BFD76C46AD55DULL, 
            0x67060BBBE5670DC7ULL, 0xFF3EA1AF7AC28620ULL, 0xD7BD533E7D2FE976ULL, 0x64A936CCAAED255AULL, 
            0x93123A5851B15699ULL, 0xFF6BD937B32F70E8ULL, 0x6C6190EE4DDE3A00ULL, 0x0B05BDBC1AD0AD8BULL, 
            0x3A91AC2144375581ULL, 0x17F7FA08D8C79172ULL, 0x9F5B2D4A149AB213ULL, 0x7969452D6D450493ULL, 
            0x08F58D73848B9FD4ULL, 0x471191C6E32E1863ULL, 0x41B04AAD643B9AB9ULL, 0xC5CFF0189FFEB019ULL
        }
    },
    {
        {
            0xA1893379F5DED6F8ULL, 0x8BAAB799D0D9F312ULL, 0xEA90658E6A9A3502ULL, 0x7973FEBA972280FFULL, 
            0xE3C1DC17886C9CE6ULL, 0xAB7287E99418B2BCULL, 0xB425FED3D507840FULL, 0x98E70EBBFD225FD2ULL, 
            0x200D34DAA582E452ULL, 0xC38CD2A61C5C7711ULL, 0xBFC285100BC4A27DULL, 0x6BCD6175621C79ECULL, 
            0xDF3B5721B1BF60C8ULL, 0x84EDF8FD6B8C6D46ULL, 0x0245FBBCBA0E17BDULL, 0x356B82511B6E03D5ULL, 
            0x50706A71404643E0ULL, 0x614FBAA109B05646ULL, 0x202305F144F95C58ULL, 0xB574543538D52DFFULL, 
            0x8FF127AE76C86FB5ULL, 0xFDC7D936559015C9ULL, 0x5F89FA5920173DF8ULL, 0x987EF40AD9A1D997ULL, 
            0x0A23A9C05E66C6E2ULL, 0x00757E17F643A3DAULL, 0xCAB26981E5B80CD8ULL, 0xA8691898858114E2ULL, 
            0x9B8F62CA7BC03D92ULL, 0x1F8DCC2CE897F7BDULL, 0xF243747EC4CC51DDULL, 0xF44B9F22F24B45E1ULL
        },
        {
            0xEDEE60405FEF6073ULL, 0xBF0F40191E87F5AFULL, 0xF6D86E2230C9799BULL, 0x4627270CF2CE5E4AULL, 
            0x8505E7A12FD5AB20ULL, 0xB62ECA6C9D8840ACULL, 0xC452E8B662C8FA6CULL, 0xB2504613CA9F102DULL, 
            0x5B2206E753A7D861ULL, 0x6D9BAAB459FEE3EAULL, 0x5975D5E818884273ULL, 0x0CBF599730981762ULL, 
            0x2417D57E863E62D4ULL, 0x52F37D4615D77399ULL, 0xD41E63927560085FULL, 0x7DBA34793059C9F9ULL, 
            0x6BAC55CBECD7E46AULL, 0xF286AF603134D252ULL, 0xB5D3F07C18E4E427ULL, 0xDE3D8F52D9B2422CULL, 
            0x96CC089A2EAB21FEULL, 0xC957859E1877DED9ULL, 0x2DCAA0B0CE09410AULL, 0xDD5E447B43625E35ULL, 
            0xA1D371F7C03539CDULL, 0xCF843CD22EA6A784ULL, 0x5DF379EAD8208E02ULL, 0x383BD1D2E5B8A0E2ULL, 
            0x5D86893648E4B23EULL, 0x307DD01B71FE5F1EULL, 0xE97FFB20A29D19CEULL, 0x8B63D9281C67B5FFULL
        },
        {
            0x6C9141A9F6882AC1ULL, 0x48B1DF1DE4E2D572ULL, 0x50C7C560D842DD1CULL, 0x22D427F6DACBB596ULL, 
            0x1C8A760C58221F13ULL, 0xB6D31904E0A049D0ULL, 0x0BDEBCC379AE38B7ULL, 0x86EB2B4578040E38ULL, 
            0x6480B08E69E54991ULL, 0x071CCC04BAC02CDAULL, 0x6F89B0E87043C15DULL, 0x4BF0B98E2CE63EEBULL, 
            0x8F4AD15C5F3C159AULL, 0x3FF4A290B469FE42ULL, 0xAEB69928BF733B79ULL, 0xEEB289AB80A59B48ULL, 
            0x59DCC4991D48485CULL, 0xB8965E1D08E7A46DULL, 0x38D45301B7C1F92CULL, 0xE36EFEB40D221EA0ULL, 
            0x661F8D7DDA3046AEULL, 0x6E609B04A8B05B83ULL, 0x43E03F36848B4660ULL, 0xD35574C424FB5E55ULL, 
            0x6758374DFD2D1665ULL, 0x3CB0D9610E9BFE50ULL, 0xDC7B299B8C2E1EFCULL, 0x26C04D91F83C3A16ULL, 
            0x32CA21A7E3958BF9ULL, 0x960DC358B1A1072BULL, 0x4BFA7406A4B85609ULL, 0x3824B8220416C1E3ULL
        },
        {
            0xF26860CBCB493B8CULL, 0xBB0C9F8CBFC0F734ULL, 0x559CF25C6F0C0A02ULL, 0x82E61BD3D7A8395AULL, 
            0xB527BD1C688B4235ULL, 0x3E78EAA4F649C4FEULL, 0xF76A39FD70BDB547ULL, 0x7F4EA5A91D27BA62ULL, 
            0xCCEE1CED5A12A2CBULL, 0x65BD7623A09CEBF5ULL, 0x94D0C9ECA9BC8613ULL, 0x0796A0BDD721219BULL, 
            0x8F2F9CEF2AFB7758ULL, 0xE10CEB2BF333713AULL, 0x5E377A905DE35FC2ULL, 0xB16A4A472004A930ULL, 
            0x24F10EF7F08FD40EULL, 0x6CAC6E412336545EULL, 0x31E07CF8A91297AEULL, 0xC936E2C57412341CULL, 
            0xA842793ED85ECD8FULL, 0x83DE5129924803D9ULL, 0x0F1A55538667C139ULL, 0x4E8689EA2454D918ULL, 
            0x901110C1E071B270ULL, 0x45AF907A5D335324ULL, 0xB6FBC3EA859EC473ULL, 0x14ABFF6EF47AC10BULL, 
            0x62170977CF6AF684ULL, 0x0510E3E92A89D9F6ULL, 0xCB128D80919AC2F1ULL, 0x6488236D32E4D747ULL
        },
        {
            0xE0A34B602D64976FULL, 0xD2D786E48CE7C7D0ULL, 0xA88611F33E80AABBULL, 0x0E61C3CD48201440ULL, 
            0xC07E71D4A7772EFAULL, 0xC6DE570C988EB5FCULL, 0x1AFF7EBBDD1D6F80ULL, 0x3D57DEAA018DE865ULL, 
            0x18CC8FEC76FBCF99ULL, 0xF338C0CAD0CCD2EBULL, 0xAA7A99174C2EF62FULL, 0x21542162BD9BF392ULL, 
            0x117C0B7DF5DEFF57ULL, 0xC3B9BF9C5857C31CULL, 0x09B73321988954ECULL, 0xD80B84A8A4E476DFULL, 
            0x6400FBFE3B191CB0ULL, 0x7567BD889E29CB99ULL, 0xFEFC5F9D6F105C73ULL, 0x5CF9D8F9848556F1ULL, 
            0xBEB138CD9818B552ULL, 0x493D339C5127F185ULL, 0xA80D15BB42F7A72DULL, 0x7C1B22BD9E04D984ULL, 
            0xF2154FF00FD04C92ULL, 0xE7AB19E913EC3882ULL, 0x5F0EBBF6F1F02121ULL, 0xB879A3DA89C94AD9ULL, 
            0x6C84DA517FEB3C82ULL, 0xDAAEC97C872B4ABDULL, 0x17FD7DCC465CCD11ULL, 0xC5D8C7EF13BD4A30ULL
        },
        {
            0xABD8BF85E912520AULL, 0xCBEEA2FD6B3358BEULL, 0x620A252381E0F482ULL, 0x529187326C8A3D7FULL, 
            0x156A81853EE5C65AULL, 0xC38B9C2E17FF0C32ULL, 0xD40ABDC431584F23ULL, 0x15A675737C66C447ULL, 
            0xE3EC13FBEECDEE36ULL, 0x6229F573F248A17CULL, 0xD0A62902C54E3615ULL, 0xD37100A3490F48A3ULL, 
            0xEA236111AC55E996ULL, 0x7EA4FB8EA069354CULL, 0x586AF6AE112BF067ULL, 0xFFC474B1A6CD6A69ULL, 
            0xA433165458DF8899ULL, 0x84F9358AA39F8BFFULL, 0x118B34101A49ED1FULL, 0x88F1659D14AE6EC0ULL, 
            0x93CF7A47497A6563ULL, 0x8E8A4272C783F636ULL, 0xEA5F2DA5D7C3EBDFULL, 0x6D8E41A9DD71AD95ULL, 
            0x969E535641172F90ULL, 0x07E630DFCB46ED68ULL, 0x2B0F7F97241803ECULL, 0xE99E2B408F9917C3ULL, 
            0x439CFDE1EF3AC8FCULL, 0xCEE5A483023F3A89ULL, 0x9C6D1E85FFD2E9DEULL, 0x809164F4F6276CF2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseDConstants = {
    0x41D836E8D7E52FEEULL,
    0xF38E4F5F04AC05C0ULL,
    0xCB33E181BB8D3524ULL,
    0x41D836E8D7E52FEEULL,
    0xF38E4F5F04AC05C0ULL,
    0xCB33E181BB8D3524ULL,
    0x986B1B2ACAC5A7DAULL,
    0xC5EAEBF2800A332AULL,
    0xB1,
    0x73,
    0xBA,
    0xA3,
    0x49,
    0x14,
    0xBA,
    0xD5
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseESalts = {
    {
        {
            0xC2AD2CA5ECECB427ULL, 0xE621FF7BA368407CULL, 0x10371FAB2FBBE97AULL, 0xC1E456D334A48C91ULL, 
            0xA0E24786C155F753ULL, 0x393017EDE9C09368ULL, 0x08A03F2A735DB396ULL, 0xD52D32C1790CDB7DULL, 
            0xA9C82BE305D86693ULL, 0x61E973EAD31E211AULL, 0x6C45E19381FBB358ULL, 0xE98A85188B0BC4CDULL, 
            0x4B92F400CF92DA7EULL, 0xACD69FC1E326581DULL, 0x751D4A0F3FA10F00ULL, 0x770C9215F3C09AE2ULL, 
            0x7D3C8030F1B7C953ULL, 0x450FCB1DCB2A0858ULL, 0x7823FCBD74F9B69DULL, 0x1F8C121771057AB1ULL, 
            0x5680D8725E07FB5EULL, 0xFB9CC35BADBB81E3ULL, 0x046E1922A9BEA520ULL, 0x55ED232E1F68A8CEULL, 
            0x9B93998BCB764C15ULL, 0xE2F04941495C76D2ULL, 0x51B08EF9B9DF049CULL, 0x88929314526C0523ULL, 
            0xB83597A9616367A7ULL, 0x37CE9D672DAA2E15ULL, 0x25D48D23DF033C6FULL, 0x231C482483DDB5A0ULL
        },
        {
            0x2AAD20B801D627EFULL, 0x7C286B697D5A3721ULL, 0x0938ACE07FDD3207ULL, 0x8C1FB759DA548E4FULL, 
            0x0AB9D4582DB82BA7ULL, 0xCFD74EBB377CFF4EULL, 0xBFA49C58A65977A9ULL, 0x16FC63C36F1B5514ULL, 
            0xF3A8C74D51A58BF5ULL, 0x1E258B823C83D124ULL, 0x2299D54EE0083BEEULL, 0xA33A70D7348E0747ULL, 
            0x4ADF8455FDD97181ULL, 0x4E744573306443ADULL, 0x6649E0B12F20794BULL, 0x45D854E35E8694A8ULL, 
            0xB2002B6C79DEF2B9ULL, 0xA0B2C3ED278C72ACULL, 0x59E0D9AA7DCAD949ULL, 0xE2AD0EC6277C96A2ULL, 
            0x5985FAC7C255FC67ULL, 0x2C0CB1B05BE4F08AULL, 0x937158FA722E5133ULL, 0x3F74863318BFF8F1ULL, 
            0x9D53E6D2F3B20266ULL, 0x5366B957C192CA38ULL, 0x1E5F3BEAEBDE4615ULL, 0xBAFD9D0331FD2023ULL, 
            0xBE0DFCF5786BE947ULL, 0x348FE9FE478B7A25ULL, 0x203AAA7265F8E647ULL, 0x03534F7ED96468F7ULL
        },
        {
            0x7ACBD7F3625D0060ULL, 0x81E6B77D972A5C5AULL, 0x7AD9165C1A5EBC6FULL, 0xDC5DA1FD1550716BULL, 
            0x5B7BDDE708895F1CULL, 0x8C9AAAE89ED842B2ULL, 0xD258AD690FE97469ULL, 0x77FB900376448071ULL, 
            0x49C664897AA3592BULL, 0x8B1930219286D478ULL, 0x8189C16D500100FEULL, 0x90E82134FB9A2FB5ULL, 
            0x3983E399F557E0EAULL, 0xD99C09822E851CA3ULL, 0x56E813FD29369C27ULL, 0x3B53D13E40FB8CE1ULL, 
            0x823005C716686CD4ULL, 0xA3DDE30E41C13315ULL, 0x266671BA81B34264ULL, 0xED34E9BA29BD7F8EULL, 
            0x120F867B914A744FULL, 0xC65F706557E321F5ULL, 0x3AF2D435E71A67DEULL, 0x0E67F50029304837ULL, 
            0x61497ECE12DF3FDBULL, 0x14FB40B431834FF6ULL, 0xC99142F1784B566BULL, 0xEF960CBBEEA96743ULL, 
            0x6F8AC4132739195AULL, 0xC4B08D41EF0E0CC6ULL, 0xCA799065C5D76357ULL, 0x94FF3FC074368022ULL
        },
        {
            0x3AC6C8B78604048AULL, 0x2CFDF6DC8685C5F1ULL, 0x26A9BF1B5F9ABA8AULL, 0xF6B8D581768D0C6EULL, 
            0xC76AB9A50F0F1C88ULL, 0x7C1E4DCB3755F34EULL, 0xE3D06ED08ABF2CE2ULL, 0x9A03CE3F15961061ULL, 
            0xB263FBEFCF60117CULL, 0x80DE35C13CE78490ULL, 0x4A5C3D2F1E8E1572ULL, 0x9EE90EA6A1B9CC1AULL, 
            0x1953456FCDFEDB66ULL, 0x69A6E134F4DE9D7CULL, 0x8FC1C6D147F1A0ADULL, 0xFA0B7B74FC05C68FULL, 
            0x12AE83DAF366C2CAULL, 0x2518DCFF8FCA8A86ULL, 0xAA83A763D916F83CULL, 0xFE20F2A23909090DULL, 
            0x686463D3F62B307DULL, 0x5A63710F7EC6D3F1ULL, 0xD9B40F2EEA09A80BULL, 0xCAF1CB8F9EF217DDULL, 
            0x5FC3EB0E2F5EED95ULL, 0x881473DF3D516271ULL, 0x9963ADAF3830F369ULL, 0x486626EB19528C38ULL, 
            0xB1CB717F5FDDF9B9ULL, 0xA0061CCDA37EA23EULL, 0x9CB1B3E40E8BAA5DULL, 0x6F1BAE6A8E4B86B9ULL
        },
        {
            0x8C50F0D5D5BCA443ULL, 0xBCFF2E8F9742412CULL, 0xC9159F42B79E8F6FULL, 0x5C279DFF5590ED64ULL, 
            0x2FE1F3F184824C4BULL, 0x683C4712C19A64A3ULL, 0x791A9235EB415F21ULL, 0x04340785BB6DDDA0ULL, 
            0x434643F46F331854ULL, 0xB5819DA0E5950C4FULL, 0xC62234AAF8BDA958ULL, 0x14F90BC3F5BF0830ULL, 
            0xBCC0753A56E26995ULL, 0x9E959ADA8354BDBAULL, 0x3E35EA99DC530DFFULL, 0x6B8F0534378CF8DFULL, 
            0x1679F28FBDF2675AULL, 0x8E2E1C1327CFE634ULL, 0x4EC4E4821A6E4A17ULL, 0xB909BFA314929F1DULL, 
            0xD555579BD599C08AULL, 0xEE09246011BD0D13ULL, 0xA8B6853979452110ULL, 0xCE0E5A71F946961CULL, 
            0x58037A8A9E39F3E8ULL, 0xF80F093728EC9153ULL, 0xC4B54C0E93F3B7A0ULL, 0xDF6321FD3F662CD7ULL, 
            0xA28153133C6E1347ULL, 0xAD6797FAB0921EB4ULL, 0x64F7F35490A782A2ULL, 0x9C682FA195152A9DULL
        },
        {
            0x4F17C29EC9ED0ED4ULL, 0xA92EE7B13DDED55EULL, 0x63E46BAEB8D8DF5DULL, 0x6340D8F84E63FA1AULL, 
            0xD41A759BBE046BA0ULL, 0x084F8F392307708CULL, 0x09903951141D6DF8ULL, 0xD93510BBC994CF3FULL, 
            0x15AB47317DD6C4E5ULL, 0x6A6B4388A4461119ULL, 0x6AB6E59F446FCCECULL, 0x8904225608765834ULL, 
            0xEDB4B9E94F9D9EC8ULL, 0x153736D45F610764ULL, 0x9E8FAE07FF7F4181ULL, 0x073EDE10ED3F5559ULL, 
            0xE192EC7F038D47DAULL, 0x1B73A659C3863495ULL, 0x13F2F866B5C0601CULL, 0xDA9C1980EF429516ULL, 
            0x68990F7BFBEC9E4FULL, 0x0AC5C9378A48FD65ULL, 0xB21E348C0EFD6D27ULL, 0xA93F1BC9E33018C4ULL, 
            0xB421AC84287659AAULL, 0xB918B842A3253E35ULL, 0x3BCB3D9511CF8183ULL, 0xA80AEA52755C6C00ULL, 
            0x32D84331EF3559FDULL, 0xFDECAF84D04F585EULL, 0x1DA27F4A798C5759ULL, 0x4F663766A576CBFEULL
        }
    },
    {
        {
            0x0D49A7025D0A8696ULL, 0xE2BA7523DC7B7F44ULL, 0xD8ABB7CFCE3D40AEULL, 0x5CE9B00DEEAE8A9FULL, 
            0x16D069F22A8FA7ABULL, 0x5A4BC5959F4C2FBAULL, 0xEE04021F7EA86A99ULL, 0xCA71AB5B7AB706B5ULL, 
            0x284AACEB878DE1C5ULL, 0x9D5B64C51C7DF11CULL, 0xC544EBDE9855F530ULL, 0xE02144EAF762F79EULL, 
            0x0F4869E406B240E1ULL, 0x9DE2DDC5FE687513ULL, 0xF302DC5E3CCE9358ULL, 0x63CE6CAD0F72D55DULL, 
            0x6DFAC7328F3D0006ULL, 0x353AA754ACA997C0ULL, 0xB2477615DF0F9A48ULL, 0x28EC3E6C44DB0B01ULL, 
            0x87DEDDD6FD43CA5EULL, 0xA68D0D28397532FAULL, 0x47C54123CFD6E7FCULL, 0x65DE82943F6C3D7CULL, 
            0x8B92C6E463FA2C41ULL, 0xB755E62A4E2A741BULL, 0x075407F9303287EAULL, 0x5EADE563C9B06716ULL, 
            0x45E2317CCD752E46ULL, 0x695767A59BF9CE87ULL, 0xBB2F9506CE87CE30ULL, 0x83DC02805B65FA90ULL
        },
        {
            0x00F24DA4D3495D8DULL, 0x363AC7342212C7BCULL, 0x98EC1AA875F5EAB4ULL, 0x8E8E507DD273F1AAULL, 
            0x6D795B023AC97F94ULL, 0xC5875148EA310B85ULL, 0x353BADF59CD0224AULL, 0xD53EE28BCC73B98EULL, 
            0x8C80D663A5BD04FBULL, 0xD6450ADBFCD33FE4ULL, 0xB88852226E9A3EECULL, 0x686E20BB2857C7E6ULL, 
            0xE27F3BCD818CFD80ULL, 0xC43634D30BE16AEDULL, 0xEE4233965D029A6BULL, 0x6BD63BF69B9B6778ULL, 
            0x2820B5B12FD4A961ULL, 0x3812886375A319FDULL, 0x54D3F481DC85A47DULL, 0xFC37B0D08F62A954ULL, 
            0x7E5802F3838EC668ULL, 0xC50D6309075C59F6ULL, 0x772438A5CC13C23DULL, 0xA61D70BD4B4631A4ULL, 
            0x648A573EBA110B30ULL, 0x4FE91D2170DADECCULL, 0x4FED3AC2111A87EEULL, 0x4BB5C42E6149AED8ULL, 
            0x7EFA6CBDA2F32DF4ULL, 0x488008AE5FA00D05ULL, 0xADB5B71F48A3A6C2ULL, 0x409CE2DAFAF48E5DULL
        },
        {
            0x4BAA4481FF0CC07BULL, 0x6F9315105D8A89D0ULL, 0xCDF55C65CB211AB6ULL, 0x1FB30B9D87CEE3F0ULL, 
            0x1C48C8FA436B6197ULL, 0x5295A01D48659F49ULL, 0x9A8DBEDDA6CE8B0CULL, 0xAB7A03D00CD2F132ULL, 
            0x80CA388278BCC1DEULL, 0x0D86C31A1AE23242ULL, 0x9BE7D0E1DD5F85F0ULL, 0x3BD6863E6C71C851ULL, 
            0xBF55490E5DF7D913ULL, 0x522815ACB4EDF3A1ULL, 0xD00614D7BEA8F81DULL, 0x8B82A5DE69F934A8ULL, 
            0x9BA375049C4E911DULL, 0xDDED38E8DD9EECE3ULL, 0x6AAF599842515ABAULL, 0xD5E46627A0B43FBBULL, 
            0x3FDCFBED0EEC3644ULL, 0x84E1392C890B3950ULL, 0xB24A64CA44A51F22ULL, 0x290BEE3BEB4B14D5ULL, 
            0xEAE3B0E6579F1DEBULL, 0xD60F9B86C7D348D7ULL, 0xD3EF54A85D749FD6ULL, 0xB97338779BFE72F5ULL, 
            0x9A465B8052FA0E5CULL, 0xC3CBF6291675AD1EULL, 0x04047D5C43442714ULL, 0x2B4229AE2F0B13DEULL
        },
        {
            0xC96368E6EC13BE4BULL, 0x63C93257D4EC98C1ULL, 0xEAD25ADCF023B533ULL, 0x0A9F8F22C1EDE98CULL, 
            0x7BD692617414DF9CULL, 0x28F404C6C6535090ULL, 0x98463D647860FF15ULL, 0xDE9587DE3766FE3DULL, 
            0x3EE5374F4BB326DEULL, 0xF52173562F3FE1A1ULL, 0x43E829E18A4AD448ULL, 0xB14FA2CE5E999B47ULL, 
            0x2763DCEDED0F9C62ULL, 0x4AC0424DED83203BULL, 0x88921B5B7D77D24EULL, 0x38BEE19E8E523F88ULL, 
            0x03747363D186BF56ULL, 0x10973C18747735CDULL, 0x10F85462108F5D52ULL, 0x4A94ACCCED1DDC97ULL, 
            0xDB27FF889218F61FULL, 0x8DFB792A3F01C00CULL, 0x5596C7ED849CE6C7ULL, 0xE7A798B5AED1E1B5ULL, 
            0x26120481D980885EULL, 0x371533AEBB898106ULL, 0x02468C9D13A8D4B1ULL, 0x0F9E22F81D0B7EEFULL, 
            0xA1AEC5BE2B38BC16ULL, 0xDB407B8EFF48AC6EULL, 0xBC1387A77727799FULL, 0xE4EC7269A1799533ULL
        },
        {
            0x75DCE91964BAEC59ULL, 0x0FDCA1D3D10684F2ULL, 0xDBC4DFD346D93FAFULL, 0x0AB86D857BEF9E51ULL, 
            0x6A0960DE39F0E745ULL, 0x6755800772FA63A9ULL, 0xE48FF8CDD5DD09CEULL, 0x9EAE62CFF80573D9ULL, 
            0x747EFA9E38B92C25ULL, 0xA54F83ECBE2948A7ULL, 0x5346D9E64B60429EULL, 0xF6269628EBDA9293ULL, 
            0x154DBEC968F6DCF4ULL, 0x1E928870A650292EULL, 0x65C612F09C46713AULL, 0xD2B58C4CD645E5C6ULL, 
            0xEFA4123601AFD0E6ULL, 0x213E0442AF3848A6ULL, 0xD281945AB6337C50ULL, 0x0D48AA86B1273A7DULL, 
            0x37C4C1E1D6E313EDULL, 0x663A44D5AE9E1D9EULL, 0xA23B790DA86835F5ULL, 0xCD034548E056D3B3ULL, 
            0x89C30A2D52D6EFDBULL, 0x1622D78999E815FDULL, 0xA406C21BEE0B8199ULL, 0xA75B2EF0DD15604FULL, 
            0xEFDF90E2ADEF1010ULL, 0x12963E702D460595ULL, 0x31CB296860658C87ULL, 0xDBA19FDDDF37E589ULL
        },
        {
            0xC43AAC52DEF9F92DULL, 0xACFD200DF3D48F0CULL, 0xC03C0C8C2B20604BULL, 0xEA986AD4198D5150ULL, 
            0xC664310947AF3A3AULL, 0x1EDC0FEF52591A91ULL, 0xA37CD9322917B25EULL, 0x71C7B6E6020E8D5EULL, 
            0x04E2ACC0C50C1997ULL, 0x9EB3512A13316623ULL, 0x43ED92DB17CF4BE6ULL, 0x36C25D581BC3F8C6ULL, 
            0x518E443D6480A6DEULL, 0x1B252D2F5B715BD8ULL, 0x4E49AC7CC2758CC7ULL, 0x555290BC8E958EE5ULL, 
            0xAA4BA6628C3F81E6ULL, 0x0ACC281CC4DC778DULL, 0xBA63CA444362F5EEULL, 0x86D1ACC83463D513ULL, 
            0xFD3F171BBD553AF9ULL, 0x6C26BD13479F8B30ULL, 0x4EE361C545397A48ULL, 0x90F4C9C34D056280ULL, 
            0xAB5EA5C3E79076F8ULL, 0x196277D39DBF729BULL, 0xC44B15E4BA34C4F9ULL, 0x88C4FA16DB8D358EULL, 
            0x1939ECEA80637751ULL, 0xA65F026F88A15515ULL, 0x34A8E5A876D8E4E9ULL, 0xA9FB8C73DFB0BFECULL
        }
    },
    {
        {
            0xFC75FE83BEB96617ULL, 0x8DBB9208D37EBA1BULL, 0x5C67B012B8A32F5DULL, 0x19A6EF5D24A229EDULL, 
            0x6EAB91F89F2DCD9DULL, 0x28E5F8A1528D3E92ULL, 0xF9FBB6DEC2DE2D69ULL, 0xBC94B714A6CA1D23ULL, 
            0xD1E797DBB899B2E1ULL, 0xFE62F2214BF18595ULL, 0x01B132ADD029C55EULL, 0x4052B43AD95CA45EULL, 
            0xA073ACBDB74844FFULL, 0x1B4BBAF37A75A707ULL, 0x2313D3AD7BE4E7A3ULL, 0x7BDF13A286A2F6A9ULL, 
            0xCC575880F17BA7C5ULL, 0x9469F1A2A7CB0F4CULL, 0xBE452B8DA37AEEE8ULL, 0xE8A12DCF57A4F524ULL, 
            0x6765440EF5DF39C5ULL, 0xBC51EA4C57D4E7F4ULL, 0xE5769C60D39792E6ULL, 0xC24B9C72E1111D1AULL, 
            0xBB76A74B6D1E3BAAULL, 0x918C1B18EF0E6A0CULL, 0x7C9001DC4C0A01C6ULL, 0x70504661D7DCB390ULL, 
            0x2B39B66FC6B789D8ULL, 0x037EC93F065E8819ULL, 0x7484DB7783D4DB54ULL, 0xDC83B68323ADA1BFULL
        },
        {
            0xE0B65708622FE1EFULL, 0xB3FA37A26E9D5C07ULL, 0xCAF698C32C647914ULL, 0xA076E06BF1EB83E5ULL, 
            0xF34DFE7AF48D536BULL, 0x882C1DF323F78958ULL, 0x055BAAF233F17BA5ULL, 0xA8F82EC3C02C7663ULL, 
            0x879D59EE35042F69ULL, 0x343458159B398629ULL, 0x7973B49543F43477ULL, 0x5627F46771ED15CEULL, 
            0xD992A32CAE32B80BULL, 0x78DCE042AF1D523BULL, 0x1A565F3AA35C9D2AULL, 0x11E1F078CEB331DFULL, 
            0xC61CEF75D0D4BAD8ULL, 0x4E44CD50A5B36F97ULL, 0x27855B32DE96CFBDULL, 0x7E99EB6E4693B552ULL, 
            0x9B43F0502849BFB9ULL, 0xD36ADFBC0EFC0FE0ULL, 0xCD4958BA5934AD81ULL, 0x9303B6A27881F956ULL, 
            0x792512B2FEC3057CULL, 0x1924C31339F319C3ULL, 0x31EB79E168341701ULL, 0xD13B4739E69051FDULL, 
            0xAFEF24CE68350806ULL, 0x74123A06E11B8809ULL, 0xC61FC399F03E6195ULL, 0x1CF0041A18654AACULL
        },
        {
            0x79D5397C74AD9BAFULL, 0x9449FE3C75593388ULL, 0xF8D76FEE756C979EULL, 0xA98AA4DBCA228955ULL, 
            0x8CCD68AE8992B11FULL, 0x18F72473477B936EULL, 0xE35ECDCED8A29450ULL, 0x4A39CDA41A538ACEULL, 
            0x9EF54103DE0F132DULL, 0x97BEF0D09A06B4AEULL, 0x8889E41B502A54FCULL, 0xCA74F77D48903BCDULL, 
            0x0ED895821AA1B869ULL, 0x53BD6E3C0B1D124EULL, 0x8D557A7018EFC886ULL, 0xE6195F139E38CC96ULL, 
            0xA772A31B8314DB2CULL, 0x38ED9D50F38623EBULL, 0x522E93FCBFB605BDULL, 0x317BBA3D28BEB21BULL, 
            0x9256613D5890B0EFULL, 0xD6DB81BBDC2CFB0EULL, 0x80AA579A7F75430DULL, 0xD0C3C7671B65730AULL, 
            0x64ECBA58BFE06BA0ULL, 0x03C155A2F557FF88ULL, 0x5A661C7CFE502A3DULL, 0x1C370D0C749C7DFDULL, 
            0xDC87E8BC4099037BULL, 0xD5405C4FDC1C2447ULL, 0x58E22E61E44E9B23ULL, 0x4CC07FBB5C63F26AULL
        },
        {
            0x553098936507A07EULL, 0xC14A060F4066A487ULL, 0x7DFB007D5ED1369FULL, 0xC82A6FA1416B4C3AULL, 
            0x335BE72E1642A0D3ULL, 0xD3E2680C1C452673ULL, 0x01B313BFB6419EF7ULL, 0x452C96C3C973811CULL, 
            0x3EC4120465A1E115ULL, 0x3E970FDBE33114B7ULL, 0x36705CD8FE05216AULL, 0xC36B54F439029EC0ULL, 
            0x72FFB9FC81280F2EULL, 0x085306250D0D5AE6ULL, 0x75666B38C160A32FULL, 0x8E9AC4DB966E9100ULL, 
            0x6835E788F3E6A540ULL, 0x3B5EEBF9A06493C8ULL, 0x06D516DEE1E3AA68ULL, 0x77BB24392E25CB90ULL, 
            0x22A2DCB76D86EF64ULL, 0x439BFB388D0C26B1ULL, 0x087CD21E24F75C9FULL, 0xFAC28CCD781FD8C1ULL, 
            0xD25C473BE1F2FBCFULL, 0x53FEE1C7A7E0085EULL, 0xED225A96FD236AF4ULL, 0x54A5B824193A4CAEULL, 
            0xCFB50E36A5C16EA1ULL, 0xBFAA742B90B3BA3BULL, 0xD8B1F18744185A8DULL, 0x91ECFE037494AEE1ULL
        },
        {
            0xBE3CAD2905B78A77ULL, 0xAA313E07337926F1ULL, 0x00BCA760B8B8C3DAULL, 0x36E82E586C7C3565ULL, 
            0xD6D4942CCED593F1ULL, 0x4055E4B2F559BBC1ULL, 0x5E3D5143B497A3BCULL, 0x7AA5B591EC99D23FULL, 
            0xC56E3057C21826F9ULL, 0xAF0D6F373464332CULL, 0x58B0B516C618A7E9ULL, 0xFE2401984293A498ULL, 
            0xE802F541AEF961D8ULL, 0x59F183144C5B50ABULL, 0x0945CA748576F01AULL, 0xEA0E37F911E40E16ULL, 
            0xB3642E5C5542B6E9ULL, 0x9913AD41556B85D1ULL, 0xD518E7D54340805AULL, 0xEDB264217E8E8122ULL, 
            0xDC0939369064976EULL, 0x5B2BAEC5F33C56B9ULL, 0xCC36367EE64315B9ULL, 0x74FF95AFFEDEF999ULL, 
            0xB191D0E8C2808666ULL, 0xA98233A0A585BDC0ULL, 0xA11BB4A69B6192E7ULL, 0xFB9479F6D7E07F4EULL, 
            0xF39390FAAB7EBA83ULL, 0x1862C3A143CB07FBULL, 0x54F8C9938F849AF2ULL, 0x9F26B37727EC6814ULL
        },
        {
            0xEBD8223C12AB71FEULL, 0x8C53273D253E67D5ULL, 0xA0157E62BEC06363ULL, 0x820CCECFADDF3E61ULL, 
            0x7EF3CDFDEDC23E54ULL, 0xC4F47A8F25A57971ULL, 0xD49B9DBE10AB07FAULL, 0x5DE18160421319ABULL, 
            0x1A0FB9AFAC3F3410ULL, 0x02BDF266FFCCC59AULL, 0x996227688F03D9F2ULL, 0x5D955D342374FC6EULL, 
            0x27F168EC18438C14ULL, 0x87EABC886382D8EBULL, 0x199882EE2FA18C49ULL, 0x4E62ED1A23C0AFF8ULL, 
            0x08D0732E70B293F9ULL, 0x1E478E5A4547CA61ULL, 0x74D066C7EF52005BULL, 0x66603BDF966EA5BDULL, 
            0x395722F3B0807C48ULL, 0xBA47DB8ADBCE3CD5ULL, 0x45354D3D60173F51ULL, 0x128743DB80B29C21ULL, 
            0x393779FA47BD841BULL, 0xF24EC4228BEE1B74ULL, 0x49A4E1594AFD744DULL, 0x0D45F494DA13D740ULL, 
            0x55C94B09F49355C8ULL, 0xCE018D796FFA9519ULL, 0x409DBED0E6AE21DBULL, 0xC408407420E0F255ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseEConstants = {
    0xA0686CE8950C20FDULL,
    0x1DDEAC144F69B56FULL,
    0xA2F66C0906E591DDULL,
    0xA0686CE8950C20FDULL,
    0x1DDEAC144F69B56FULL,
    0xA2F66C0906E591DDULL,
    0xF6E256E767E817ACULL,
    0xC1E7E63E08D382FBULL,
    0x48,
    0x17,
    0x1D,
    0x15,
    0x58,
    0x14,
    0xDC,
    0xC6
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseFSalts = {
    {
        {
            0x33A409BC99E93F5CULL, 0xBD55DFA2F6329DCCULL, 0x03CD5069A674038DULL, 0x9792F910E6609117ULL, 
            0x8670CD4DCFA09CE4ULL, 0x6A4D42D39F356700ULL, 0x7C6B90D1A2D28358ULL, 0xE0B4F53EBC65921EULL, 
            0x8C9F894450BD513BULL, 0xDB4FB50DCBCBEC44ULL, 0x9B91876301FB9879ULL, 0xB9AF8735F5DDA2D0ULL, 
            0x2618C2DC047225CFULL, 0x481BC39E3BA8E38AULL, 0x777640950D1EC50DULL, 0x94745CB2203046ABULL, 
            0xF479518F80431C21ULL, 0xD28CAD0E6AD8007CULL, 0xFFA53E1CCF6FF45AULL, 0x33EC8811CC6A15F2ULL, 
            0x1FB829B6705C97DCULL, 0xA876448DA3EB5727ULL, 0x9C379F83B05BA49FULL, 0x692DBBC38A452F59ULL, 
            0x16B6234B83A59138ULL, 0x9874F25F97060F2FULL, 0xA1430F2A6CF619B6ULL, 0x7DA96BB5B3237F8EULL, 
            0x731C6C84A787E359ULL, 0x492FE8B020ADBE53ULL, 0x6C1F48DB4FCEAF6CULL, 0x0999484913ACDF89ULL
        },
        {
            0x91120B8ABB916149ULL, 0x60899864F04B364CULL, 0x222DA8A15E24A85FULL, 0x2361064D519E4D81ULL, 
            0x685CA2E49E4A1A95ULL, 0x78B41FEA8BBAAB3CULL, 0x447BDB716DCCDE7FULL, 0x5B89BF7DF3268F7AULL, 
            0x02221DF910AED436ULL, 0x01273D2A05B1BD2AULL, 0xF7B58471F5AE2303ULL, 0x5260596F4374F717ULL, 
            0xF1B031095299735DULL, 0x399FBD6239EC142FULL, 0xA0545AFA36B78195ULL, 0xDF925404772D2B15ULL, 
            0x274B26495F898C26ULL, 0xB7C138BB7B207838ULL, 0x318FBD9404E3F8AAULL, 0x812EBDD65F09A22FULL, 
            0xF99D21A4D369779BULL, 0xE6DBC142E1FC1A9DULL, 0xB63836A1EF2A63B2ULL, 0xF46A45D4395F2292ULL, 
            0x3FAE85F9127A22C4ULL, 0x569CF0AC181289B2ULL, 0x3F2E5BD89C35B88BULL, 0xCFC053513AF76E8FULL, 
            0xC89A08DBF0263E55ULL, 0x67CDC45B5B2800BFULL, 0x9146936AE769876FULL, 0xE08784E2865FFCE2ULL
        },
        {
            0x4D943DB09074E2C4ULL, 0xC7B24796592EC707ULL, 0x0DAA229117A61E8DULL, 0x36F92E10EFA55B78ULL, 
            0xCBFAF16C93F56EC6ULL, 0x7C21F9D667A3BD94ULL, 0xC79B2E54A2E39156ULL, 0xF2A340D465412C1EULL, 
            0x24BC2332346B03D5ULL, 0xA6E167E6868821CCULL, 0x01FB3566058BBCE3ULL, 0x0EC546CCDE5B706BULL, 
            0x5C7EABE31A13CD7FULL, 0x6525CB6E5E5DAA94ULL, 0xB341C5FF4A26ECB9ULL, 0x01F4F925A5904F58ULL, 
            0x4CD028F1AA54A026ULL, 0x123FF50C5744D50FULL, 0xBC44095C222C0D51ULL, 0xE2EEE197BCA5B9DDULL, 
            0x20BF6C50C8E5921AULL, 0x08EBC617CCE4AE4CULL, 0x1FE6457363475EC5ULL, 0x151C5B613B6DA2C1ULL, 
            0x121BA4453DF99853ULL, 0x5FA84236B87D3414ULL, 0x84D130355D6718B5ULL, 0xD871272ED8F58823ULL, 
            0x9206028BC20C3BF2ULL, 0xBED93B4FC6C10A39ULL, 0x8771A76188410247ULL, 0xAAE27D2CBFB505CAULL
        },
        {
            0x61F9D936D3E3916BULL, 0x04ACEC853769E012ULL, 0xEE9AAB27CB821ABAULL, 0x3167774D0ECAB2F9ULL, 
            0x1B268084EF246FE3ULL, 0x8D17E31214A735E1ULL, 0x49A7AC782A44F225ULL, 0xF6DB27D2C1979657ULL, 
            0xE2B74A1E6F872470ULL, 0x89CAD24755DEFEF7ULL, 0xC8CDDA51C1454590ULL, 0xC139A9DEC6AC21A4ULL, 
            0x19475A432C461333ULL, 0x2A8ED8400A04340EULL, 0xB461E45E97A91417ULL, 0xDD01B131FCA8436EULL, 
            0xFD77C7A6D00713C5ULL, 0xF981328C124A8959ULL, 0x8CFC6D8B1211524AULL, 0x568E8DD0BEF35129ULL, 
            0xCF7446071AD5A3D1ULL, 0x67A2E9174E63E779ULL, 0x0A1A39DA69A22237ULL, 0xF83E0494881D1190ULL, 
            0xBC5572DDF0CC250CULL, 0xFDB6736447EF32F9ULL, 0xE56F5255CD0FF226ULL, 0x64349371AF31E474ULL, 
            0xFD1C016895A11F51ULL, 0xCF176BE16EAEF4B1ULL, 0x9AD1892CF0093F04ULL, 0xF6DABE6B557170E4ULL
        },
        {
            0x3DB2EA15DD01D20DULL, 0xFACC25591733D981ULL, 0xE7092A75CFD0E65AULL, 0xA42FDB5790B692FCULL, 
            0xF42759E7B4152C28ULL, 0x6DFE5C35085C75E1ULL, 0x330203DB98698B09ULL, 0xEA7F41D10448FCA9ULL, 
            0x18CCA009565EBA26ULL, 0x383EF3F4622ABF1DULL, 0x57B3A3EE4884DBAAULL, 0x08CCEDDAF1CC432EULL, 
            0x60ECF8371F8414D8ULL, 0x838140B85FC6CE3CULL, 0x71BBDC8C46808D91ULL, 0xFA61A1B659B54F29ULL, 
            0xF3E7FC2E104B7E64ULL, 0xD8BDCAC905A98DCFULL, 0xA6DD1EF6AA496EA0ULL, 0x3B4CE42CF306B532ULL, 
            0xDADED50939BDE082ULL, 0x96868F851AC724E1ULL, 0x450EAA82BFF77547ULL, 0x2CC5BC0E68316DCBULL, 
            0x6483C2DB484CE51DULL, 0xCAC77485E16E0D1EULL, 0x803F44422C2BAD82ULL, 0x9E5B20B09A8BC9ADULL, 
            0xBE20316D2962106CULL, 0x2830D3739587C480ULL, 0xD5DECA67344EFAB7ULL, 0x4EFC745ABF546305ULL
        },
        {
            0x4F5A5B457F6152C9ULL, 0x5F01DA8B3FD77084ULL, 0x6586F4EC779DA148ULL, 0x27EB84FA563F7E5CULL, 
            0x1D71A2EE92FFD51AULL, 0x072BC3377BFF6D75ULL, 0x58359BA17AF3E3E7ULL, 0xE4828F90E1F8AA48ULL, 
            0x58611813F4049E7DULL, 0x3514B056677236EAULL, 0x46A588A0C999C9A5ULL, 0x2EDC305B15DC41BEULL, 
            0x1B924000390A7A78ULL, 0x1626160D45C8C963ULL, 0x1307BD1800988A88ULL, 0x6DF09DA761CED3B7ULL, 
            0xD5881AAC9F623566ULL, 0x2E98ABB35F24FAE2ULL, 0x1C1617FFA72CA356ULL, 0xB92E42B0774ED99DULL, 
            0x677FE159A529DC20ULL, 0x3AE1DEC5D290B539ULL, 0xF31CEFB07AB27A3FULL, 0x86797C456FB65723ULL, 
            0xDDFDEC5933E9E580ULL, 0xB8E6461C124210B6ULL, 0x45B15230BF4FD8C6ULL, 0x360446C14DFD3E4FULL, 
            0x2EA05FDFDB4354FAULL, 0xBE48113C0A68C202ULL, 0x8183ECA78054E715ULL, 0xEF83D4638247D5D1ULL
        }
    },
    {
        {
            0xDACF4601B29BA7A7ULL, 0xE1107A3D7B72624DULL, 0xE34496BEBFE7D211ULL, 0xDC921A10CE6AAE9BULL, 
            0x0BC82CD355FFDF47ULL, 0xDCD4E9EFCE2CF24EULL, 0xBA616C219015B899ULL, 0xD139F0EE41841043ULL, 
            0xD3A9D478A4E69CEFULL, 0x657DFA5772CF4A66ULL, 0xE83BC97D7630B5EEULL, 0x11DDC68FCAB6725DULL, 
            0xFB889D8DA4370A5AULL, 0x9E4515BD85EE1DF8ULL, 0x97E53BE630714FCCULL, 0xC848FDD6EA3EB911ULL, 
            0x8BEF31B98ADE4CB0ULL, 0xCFE133A8C7443965ULL, 0x6D7A2168646DA8B3ULL, 0xF31957A5A33B64FBULL, 
            0xA8260F1AB2510ACCULL, 0x02FD046E55CA2AD1ULL, 0x3260869C84B08C76ULL, 0x59E7A62EEE40FDD8ULL, 
            0x170897C620C0957CULL, 0x57EC8B0AED7262CBULL, 0x04F043793F19CDD7ULL, 0x50E011B38D634776ULL, 
            0x436CCA7070F0801CULL, 0x64E218788CFBA544ULL, 0xBD9548362B268524ULL, 0xA21CAAA1E9AD3809ULL
        },
        {
            0x3952AF2F6FF9A944ULL, 0xF29D40BE41652DC4ULL, 0xC3D7312B51AB5356ULL, 0x35B0BC2359E599AAULL, 
            0x417FD42DF97E6F52ULL, 0x1FCBF3B95C795CB9ULL, 0xC966EF73702D048AULL, 0x96403F2E8A52BE23ULL, 
            0x1303127855F18F67ULL, 0xFE538667D5240710ULL, 0xDB560B458FC5A732ULL, 0x1003AF586C0649B7ULL, 
            0xA0755E8DAF271F6FULL, 0x88D7E3353212EF45ULL, 0x7E96B459ADA5EC7BULL, 0x0A8D06FCFBD51189ULL, 
            0xF93DDB9E78976239ULL, 0x6D8F255A38743E42ULL, 0x01CF82419825ABD2ULL, 0xF650853C843496EDULL, 
            0xB290D29BD28CE179ULL, 0xD4DFED3293E9FB85ULL, 0x3385E11FA05ACFA3ULL, 0xE792623AD5BE2E69ULL, 
            0xD9B45230A4973C46ULL, 0x8FC74A30DC8F79A4ULL, 0x17BD2B0A35E162EBULL, 0xC399267460ADB7C9ULL, 
            0xDA6C37C758EE7BD4ULL, 0x0C3330A863EBB7C7ULL, 0x90220AD2507A31A5ULL, 0x71F989169836B941ULL
        },
        {
            0x70A6FD6356A92F46ULL, 0xD7BB58EA0B207004ULL, 0x46453BB8D19BBC80ULL, 0xC5379325DB437BE0ULL, 
            0xD053B1272F958715ULL, 0x7156D20F6C50B5FDULL, 0x1B667DBCC3163399ULL, 0x8E2B2DB13DD120A9ULL, 
            0x1BD0B945A6F34AE8ULL, 0xAE2D6ABB6F643F77ULL, 0xD61FDFAEDB309616ULL, 0x4F742AAA2387CA13ULL, 
            0x87CA833A8E687A34ULL, 0x8D0BDA7CC72FE94CULL, 0xAF8282C50A6D5780ULL, 0xE4B9385BEE1088B8ULL, 
            0x46B90B2AECEB4611ULL, 0xE4EAAF8190DE0E81ULL, 0xCF5D8A296E06E40CULL, 0x9C102EBB816BDD53ULL, 
            0xB035BC3590CE4449ULL, 0x7F2AC4A1154AC96EULL, 0x30D37AA016CEE0D3ULL, 0x6EB5392B248D0A66ULL, 
            0xA0152AD809B3CAB7ULL, 0x4F704F07760F1953ULL, 0x972AF61D8B8F0D76ULL, 0xF46133B9F83F74E1ULL, 
            0x7AE6BF724994BC0BULL, 0x8C677D39DF45823FULL, 0xF92D5AEA186B5F56ULL, 0xE65974BFDA4A26DAULL
        },
        {
            0x01E66862017F24D6ULL, 0xC82657AB6AD91DD9ULL, 0xDDE41A20B7AD44D5ULL, 0x6167D2714D67647AULL, 
            0x5AB424B593A58B53ULL, 0xCE17C7778AB4CF91ULL, 0x21287F2D785FF8B8ULL, 0x24DDE1474B64CA39ULL, 
            0x636A853F142D0D7EULL, 0x9F718811193F5919ULL, 0xE15103A3FEB341F2ULL, 0xE806B14545D701EDULL, 
            0xF330AED7E256FFC7ULL, 0x6331212738F08A22ULL, 0x615A952C1605618FULL, 0x284FD34F82827DA0ULL, 
            0xA9F440310610F38FULL, 0xB30E56437759765BULL, 0xDD37B10CF25809F9ULL, 0x8DDC6A63690E0033ULL, 
            0x5D5D944F7BAD2601ULL, 0x7CB3705733B818C0ULL, 0x02C7518F5E8D7CC6ULL, 0xD6D558984310253FULL, 
            0xC357A87AB2487238ULL, 0x54408E880734884FULL, 0x82FB18BFCCAEFCFDULL, 0x1A50CEBBFB8E7C10ULL, 
            0x8C37DD442BF05368ULL, 0x0A0A1FD535D8FC86ULL, 0x80FEFF033DCAA869ULL, 0x8252564225DC7537ULL
        },
        {
            0x2A291AE99EDB0391ULL, 0x2917781D493E6FAFULL, 0x8806535C224852B6ULL, 0x8F99DFE0B90BD061ULL, 
            0xE4FD8604D08A2F8EULL, 0xD73C3811EC4172CBULL, 0xD16CBE4F098DD0E6ULL, 0xD533DEDFB07983ECULL, 
            0x88652AE29622E7E8ULL, 0x4C5BC870A324D65FULL, 0xDDDC767AE03C92CDULL, 0x88B93BCC4414DC7EULL, 
            0xB3C7938845A2868FULL, 0xBBDA1F5891DC3C9AULL, 0x11ACB64C92FA67EDULL, 0xAB53B86577F2B444ULL, 
            0x95B234DF92E709B2ULL, 0x6D3C9E7C50F9D327ULL, 0x1B85F4E63A8E09D7ULL, 0x36F33472D1BAFB30ULL, 
            0x6C475DF44704603AULL, 0xA8AF73920774D1D9ULL, 0x6E3E3CC1E2EEAA7EULL, 0xA57105632D0CD3C0ULL, 
            0x86502CA4BA9764AEULL, 0x85F8DEBE35506BFEULL, 0xAC6B2525EC8020BAULL, 0x1E3DD22F37D7C44FULL, 
            0x7214E391A54BE74AULL, 0x7C56426C37765A38ULL, 0xF35020CB0FE23372ULL, 0x8F5303A52102B915ULL
        },
        {
            0x844C97ACE66654A1ULL, 0x706FCEF2B2AAEC25ULL, 0x6DA485FED209B086ULL, 0x7E7837357FEB33CCULL, 
            0x29790E81AC225E76ULL, 0xBB4FCBF04DD99D55ULL, 0x5D22B4355FF5C413ULL, 0x0C3F88B4185F5694ULL, 
            0x47C635196B19287BULL, 0x3A8E2588C61FE864ULL, 0x4A019B93033CB568ULL, 0x8DFEB9B0168F2E81ULL, 
            0x3A379CBBE03D6601ULL, 0xA02301500B24C3B5ULL, 0xDAA2FEC765DDC9A0ULL, 0x22CD692D8CB532D1ULL, 
            0x1643AF06A5340891ULL, 0xCC18BF09DD1DD6CCULL, 0x07A5886268D941F6ULL, 0x33ACE3307D6C81B9ULL, 
            0xF9EB7A74470EA389ULL, 0xC709CB89862D8343ULL, 0xEFBA5D2FB2383052ULL, 0x259304E46D02708EULL, 
            0xC8BDBB2B8F754721ULL, 0x512C2E87F32CB20AULL, 0x8CF6A14CCBE3DAAFULL, 0xEF99F64D1C9F55D2ULL, 
            0x13077BA9DE47C375ULL, 0xAEF8C6242ADB897EULL, 0x321165A615EF3A5BULL, 0xC640D325B9381E5DULL
        }
    },
    {
        {
            0xAE06C68AB12BD052ULL, 0x082E055A6DF61DF5ULL, 0xE45B6B24D983FC82ULL, 0xE73B619589290E55ULL, 
            0x54F43894FA7250F3ULL, 0x3601CDDBF0CEFDBBULL, 0x5F014A19F9193348ULL, 0xE1BD75F834584507ULL, 
            0xBD21EC72A86131E4ULL, 0x8AA29DD7A0A4F317ULL, 0x3F5767CDDA767C99ULL, 0x67B47C83DD7D6F7CULL, 
            0x482E971B19D847CDULL, 0x47E49F8CFBD811C8ULL, 0xF3CF742082900336ULL, 0xF2704DCD9160DF81ULL, 
            0x6FE919571E74C5F6ULL, 0xA6207B5F1F197DA4ULL, 0xFC5DCC70BC6439CCULL, 0x2B54C05A50CC0BF3ULL, 
            0xFBCF0763E6918216ULL, 0xA30092CAECD50BAEULL, 0x482533B2F61F66AEULL, 0xD22B00EBA6D0FD15ULL, 
            0x0EBCCB030DED8B6DULL, 0x5BA5B39F6C9FD37DULL, 0x1C65FB775564D85CULL, 0x47A4210B16CBD80BULL, 
            0xA689A94946C6239AULL, 0x8985F8B0A597F9FFULL, 0x25388FD09B403338ULL, 0xA152B54CBE5FBBAEULL
        },
        {
            0x9A0B6B0F9474BFECULL, 0xF3BB382F0E872B26ULL, 0x501348EEBED9213FULL, 0x46946B7F769F283BULL, 
            0xAD35F29660C6721CULL, 0xF45A4AACCD212972ULL, 0x385548B5B3C26A03ULL, 0x37082957422E68AFULL, 
            0xE64C77FD602B479CULL, 0x3F593A5A6918143DULL, 0x63AEC067B8B5DC72ULL, 0x23C9479066B11A2EULL, 
            0x127CA52FFFE3B649ULL, 0xD2C8D9496F71F4B6ULL, 0xE83CD7056C1900B4ULL, 0x6AC5973379DB9105ULL, 
            0xC80081DDEEF5FE68ULL, 0x0153DCBB61FD24B0ULL, 0xE04B3574D896E8CFULL, 0x7301805E455C1F2BULL, 
            0x12AC064D89AFE4CCULL, 0x1E36D0C5C642C264ULL, 0x86FB1F488C22A4A0ULL, 0x152AE97F07D7EFFEULL, 
            0x0AE5A19A1F87C06DULL, 0x61C9C06488AEE13BULL, 0xE938C122C58688C3ULL, 0x0756D42ECD8A78C1ULL, 
            0x1962DACEFD5964D3ULL, 0x07F9C4DB60B19D2CULL, 0x3E47AA7D9E278BE4ULL, 0xD1F2620F7E10B9AEULL
        },
        {
            0x1DA36D430DCF68DAULL, 0x8BF77747F5932450ULL, 0x6B560B96FBF48A48ULL, 0x17113C8E485366E8ULL, 
            0x04D2A2B597F0B6EBULL, 0xE813123D33AE3276ULL, 0xAF94024549E44AE4ULL, 0x6488F5F6DCBA2A7CULL, 
            0x012F2C227FDB8126ULL, 0xCA6937D63806BFC6ULL, 0xA797CD3294CC35D6ULL, 0x84C6B4AC3ECCE69DULL, 
            0x47674C1CAA007732ULL, 0x51B4A1BD8A8C1505ULL, 0x7557D65FE302F3EEULL, 0xF6E8287B24179EC6ULL, 
            0xBE131D25EDCD0773ULL, 0x2C52057CFF3ABB53ULL, 0x00BC8707A13CE6FCULL, 0x18940FF8645D9B8DULL, 
            0x4BD0C012D1408799ULL, 0x7DA157703A7497ECULL, 0x1C963588215BDE18ULL, 0x7A9D85171F553EFBULL, 
            0xC5789494F09AE97CULL, 0x743B55A4A9301D95ULL, 0xAB259120022C8D55ULL, 0xCF333C21F3CBA26DULL, 
            0x505531CCF0BB3B9FULL, 0xA78946E867D08EFDULL, 0x5F8D1EAA14C93E96ULL, 0x98226838E0764AC3ULL
        },
        {
            0x66DC727996FCEE05ULL, 0xF8B92823EA996DD6ULL, 0x6931525D25574E52ULL, 0xB0D369A684B4416BULL, 
            0x359ADFB41552DEAFULL, 0x9A562537F0A64310ULL, 0x4B5D50979E364DCAULL, 0x6350361C9CAD33ABULL, 
            0x367CF3D0C221AEB6ULL, 0x002937779D718403ULL, 0xCFF262ED0414EA5FULL, 0x9F244466C980DCCDULL, 
            0x161C37C5B7E028BAULL, 0xFB0FD48C7412ACAAULL, 0xAB0D8F8D197834E0ULL, 0x3445E624D1A302E3ULL, 
            0x3929304656ECEA35ULL, 0xEB18C9A31D854B26ULL, 0xDDBADC118D268181ULL, 0x6AEB05631EEE02DCULL, 
            0xB21816634DCCBEDBULL, 0xB9595D6C151318D1ULL, 0xBC770237E3D670BCULL, 0x606E64CEE97476F0ULL, 
            0x72CEEF58658C5F9CULL, 0x76516B2AA071F51AULL, 0x048FC67359F223BEULL, 0x17BEAA89EAC6205AULL, 
            0x3C36A86086094979ULL, 0x1D4EBD4F2EF3E113ULL, 0x1394822A3695F76DULL, 0x81B0C1DA4C339738ULL
        },
        {
            0xF2D53DF97C9E01CBULL, 0x24E963FD7CB95467ULL, 0x2D3E67BD06448901ULL, 0x1120E273E1CFF760ULL, 
            0x2D9AFDA934BBCFEBULL, 0x82CAA02CE53523F7ULL, 0x3D008EB0F5035310ULL, 0x1CD5E79382A8458EULL, 
            0x186937F6995D9991ULL, 0x91C38B1596B38F57ULL, 0x3395EDF854614928ULL, 0x73D4C08C89B8FBCAULL, 
            0xE0B65BAE29754EF3ULL, 0x6506CC7543797E9DULL, 0x64097EF9E95FC47FULL, 0x31A1B9339A3106B4ULL, 
            0xD15E48A710464EF1ULL, 0x2CAE5E57E11ADC9FULL, 0x0C907517F3129582ULL, 0xA1F71DCE113E3DFCULL, 
            0x4B690AD897DB3340ULL, 0xA59DD7314710C199ULL, 0x82B5EB9CD13A04C7ULL, 0xED65C348191365FAULL, 
            0xB3D5F8C46FCEBB9FULL, 0x0F4BE8AD2BB69C7FULL, 0x6694FAED97D08EB4ULL, 0xEF01ABA96F795B4DULL, 
            0x8B3A82122872A8B6ULL, 0xFAD268108B4BCE3CULL, 0xEEB55C7989F328D7ULL, 0x7C68D919E634A6D9ULL
        },
        {
            0x1FBC166918566497ULL, 0xECCECCD15852436AULL, 0x4998FF281EAA254FULL, 0x64206B1818731219ULL, 
            0x6F2EF1EC25869E94ULL, 0xB8DC1981A9AA7F5FULL, 0xB0448E778D23A77BULL, 0xA1B39B404D9CF9A3ULL, 
            0x4512CE5EED3648E3ULL, 0xF8B06C0CCE2B14F4ULL, 0xA461FBA6D1ED9BDFULL, 0x1F88DFC83823DEADULL, 
            0x605AEBB66883DD05ULL, 0x127E51DE933BD171ULL, 0xB772A1AE7FADD176ULL, 0xBD654A0752E6F134ULL, 
            0x806ABDC92947C062ULL, 0x08A21862177CC3BAULL, 0xC94D1B3A117B0BA7ULL, 0x3C75A6E68EAED212ULL, 
            0x2F28C480545E7329ULL, 0xD2DEA85C98A0C182ULL, 0x32CD872C244CB49AULL, 0xD70F7F4D9788B1D2ULL, 
            0x781AD288DE959A75ULL, 0x65C3646C88B487F7ULL, 0xE49B6C0FBD980A53ULL, 0x7D3BDFB85752A8C5ULL, 
            0xA55F889B07A7D186ULL, 0x364AE655286A8481ULL, 0x5E968F6019A86C16ULL, 0x53E169C87D2D31CBULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseFConstants = {
    0xEB2B6A871193DEF2ULL,
    0x75ED64F436B42572ULL,
    0x70BE89880F9B06D8ULL,
    0xEB2B6A871193DEF2ULL,
    0x75ED64F436B42572ULL,
    0x70BE89880F9B06D8ULL,
    0x70C7641D5A877C4AULL,
    0x353178D75BE40B7CULL,
    0xB8,
    0x64,
    0xDB,
    0x56,
    0xDF,
    0xFF,
    0x81,
    0x40
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseGSalts = {
    {
        {
            0x21749C3E3EC10F53ULL, 0x688DADD48761AE32ULL, 0x1FACE1EC266E53BBULL, 0x752B1B1475DBB502ULL, 
            0x37CBA2E0682C2A2FULL, 0xDD58346776A2F11AULL, 0x1F47AF186FC69545ULL, 0x0172AFCCCDF27A50ULL, 
            0xBC5EC6D547BFF5D7ULL, 0xF9A987DB807238D6ULL, 0xD2A36C00FBDBE05EULL, 0x0E11D6D1274C2F16ULL, 
            0xCF6DF9B9C274979DULL, 0x98FE98430E27EF28ULL, 0x01745370B45AE437ULL, 0xF311C532A64DBF55ULL, 
            0x273F60273D4E8FCCULL, 0x9AD226C771509AB9ULL, 0xBC7609516D9133A3ULL, 0x1FE771EE043FAF59ULL, 
            0x206029B3E799294DULL, 0xFD3A8FA6F5068DDDULL, 0x4C76982BAF4277DFULL, 0x9F9BF8F00D12EE25ULL, 
            0x11B94FB6CD725C12ULL, 0x1745950EED79B938ULL, 0x3C2A5BCBBB2A6AEEULL, 0x54EF6DEFF14787CDULL, 
            0x61ACBC8074B22FEBULL, 0x05DAC0D0CE8D531EULL, 0xF49517B95717B750ULL, 0xE651A5E3120AB6E7ULL
        },
        {
            0x9D8A761F14FAC28DULL, 0xEC0F1CFB16A63BA7ULL, 0x36D7A3FBDE817C36ULL, 0x1DB146EB612E66AFULL, 
            0xCBA76766A50CFFB9ULL, 0xFD508EA776AC9167ULL, 0x62B699D1F316FDAAULL, 0xC6267D36777BB212ULL, 
            0xE42F2D88024816A8ULL, 0x1C8D9C73533A3DABULL, 0x13EB10A38FB75D77ULL, 0x98232A7D8EC4CF01ULL, 
            0xCEA3DBC4CA3A3BDAULL, 0x46F98AA9C57B923DULL, 0x81F30C1DE7621BCDULL, 0x2DCDD29F270B6EECULL, 
            0x0037C9376804A4D8ULL, 0x21C973D29E6B0A55ULL, 0x37AF452AD904C73AULL, 0xBE1E8F8211423506ULL, 
            0x8307FCF0DD2D57EDULL, 0x7D96E9312BCC4A5DULL, 0x623B5820837A0335ULL, 0x2E442BE82BBCAB5DULL, 
            0x331E7F69495DBE29ULL, 0x8F0D739F4E64A91EULL, 0x08020D0BD05393F2ULL, 0x956E47050A8747BEULL, 
            0xC09F013CB516EA84ULL, 0x3740E2C458FBB4C9ULL, 0x86A7DD4F39847E0AULL, 0x4EEBBACC93C37FF6ULL
        },
        {
            0x0FF3E1C87ABAD350ULL, 0x12F602C49F4C726AULL, 0x83E1C1D772A79598ULL, 0x85F5B2399B35A971ULL, 
            0x0E2D3FE52D76ED72ULL, 0x3FA663A6DFB51DF7ULL, 0x9F5606B4028C15F2ULL, 0x892661F4C9BF6E9EULL, 
            0xDE6E916333B99053ULL, 0xAFB3EB7FCC4923B3ULL, 0x7673BE0A4E9DE0DDULL, 0x70F158ADD25CC389ULL, 
            0x22E71C1F7B31D363ULL, 0xFF2E08D69ADFDE66ULL, 0xE97A38770A947A60ULL, 0xDE4A46BC9013D013ULL, 
            0x8A0683FC3C1ADE6FULL, 0x47A223C6E92FAB4BULL, 0xF8ABC57E8986FFD8ULL, 0xA481B71C8A329A3FULL, 
            0xCBA516FBC9EFFC90ULL, 0xC0BEE294F590BE9FULL, 0x6DF0DEC406617964ULL, 0x78C2132C77ED27CAULL, 
            0xBB050FB3BE7335FAULL, 0x37AB33632252FA04ULL, 0x7FDD75C9D9BC15EAULL, 0xCB09A0C021EF2FF0ULL, 
            0x450EAEBF63F98E3DULL, 0x5E0A5A0D1AEDB08FULL, 0x5C45D5EECC56AA80ULL, 0x7C19693F7FFD9D1FULL
        },
        {
            0x0F542D0FDD4694B3ULL, 0x82C71A01E73AF21DULL, 0x4EEB59598851E8FDULL, 0x347EDFA0AABEE984ULL, 
            0x71274F8EAC7F3761ULL, 0x0B81F04B347C8E68ULL, 0x29A8D15FD9FBC4D0ULL, 0xFDFD2C7CAC13D061ULL, 
            0xD0C07662DA547F9AULL, 0x4AAC3DC1F84E69DCULL, 0x3FCAD8CFFF54AFD0ULL, 0x7327CB3D69AEFA4EULL, 
            0x03379BB5801EB5D9ULL, 0xA0569FC3991D8E2BULL, 0xCCE7E4E545A8322AULL, 0x2C29AC0197ECF683ULL, 
            0xE6331098BD1819A8ULL, 0xDC66351ACFF37FD5ULL, 0xC4442E155F85C4B6ULL, 0x5DC9026CA02EC5A5ULL, 
            0xF114DE4778F242B6ULL, 0x1E7635F1169288B6ULL, 0x7AF9BA00C392607BULL, 0xF5027B37D93E3B6BULL, 
            0x13CEDCD12361B3D9ULL, 0x2CDFA344BEA88290ULL, 0x76B8BE2F37679D35ULL, 0xF9607D0A9213E798ULL, 
            0x04386FC597EA26C9ULL, 0xBCC1DF0C38E9A90AULL, 0x7011CD561AA37EBCULL, 0x132A91FC45A8E1FAULL
        },
        {
            0x98F11857A4164A19ULL, 0xE3C536FB74D51FC2ULL, 0x61060B2E95E80F37ULL, 0xBC6B83FE2FBB4ABEULL, 
            0x4937F2FAAF133E07ULL, 0xC1112E50AC3545F3ULL, 0x81A4EBBB942F7718ULL, 0x29B9497297B57238ULL, 
            0x26DF960F4CE02304ULL, 0xDD6D50C81B2AAEF4ULL, 0xC113C68AD16A27D6ULL, 0x84612C7558658896ULL, 
            0xB93CE5606BDE1DBFULL, 0xFC69DF0098CD3FC6ULL, 0xEFDE80613477D09CULL, 0xC246AB8DC8AA1EDDULL, 
            0xCE6ED5CC6E225F34ULL, 0xDA8379CFA489F5D4ULL, 0x25DAA7C26448FE02ULL, 0x21D3CBA15CCA4EE1ULL, 
            0x8980ED5E0C61F510ULL, 0xBE0F6F7A6C95919EULL, 0xF241F5A18DB1A936ULL, 0xC4C2E58CA8422181ULL, 
            0x6F711460144311BBULL, 0x23B349941CC3433CULL, 0x00C9687EA2B49B24ULL, 0x6BBBEC754F8C91C3ULL, 
            0x8CC2C23B95F22597ULL, 0xDCDB5418C3EAEA8AULL, 0xE77750CFB1AABA8BULL, 0xBC0FA9D9694CBD5BULL
        },
        {
            0xF7FC3CA0F7252523ULL, 0xC9130F848A8F8BDCULL, 0x252C7E704D088375ULL, 0x92CD3881D4AE6259ULL, 
            0x4335D6F5715F9E86ULL, 0x9F2783AE54231D71ULL, 0xEE9C0098F12C8BDAULL, 0xE6BE063D37B2EC7AULL, 
            0x1DA7DD2BBA1CB220ULL, 0x0F1D760CA2987FD9ULL, 0xCDDB7C2B4E5E0A57ULL, 0x78B848B91B0D3788ULL, 
            0x73E4092C243C888CULL, 0x23798C174C611D95ULL, 0xB1B593B1DF259E46ULL, 0x144251FA42C57C58ULL, 
            0x71C7AB7F5AF73B12ULL, 0xBFE7AE217AC92522ULL, 0x1BB609C955E28679ULL, 0xE4E065EBF77B9BB0ULL, 
            0x2166251EFA164255ULL, 0x047026467D791BFDULL, 0xB10B36216715506FULL, 0x56C54593885B6310ULL, 
            0xCF5A809C28495F84ULL, 0x8F688FD91677FD24ULL, 0xBBFF4D854773C907ULL, 0xF7C1E2DB168654C3ULL, 
            0x6411D0882EA068F8ULL, 0x3252832F6ACAE3D7ULL, 0x60274F20E46DBDB9ULL, 0xE09077D7840A76ABULL
        }
    },
    {
        {
            0x546D98B7F7717173ULL, 0x58FFCD1130A9207AULL, 0x8DF3A8A7F0D94C79ULL, 0x569E25E6EC1E3D4DULL, 
            0x1F73B43C816BFCC7ULL, 0x085C2232E2E7AE13ULL, 0x5FA17573A398DA93ULL, 0xA1CB418E277D7709ULL, 
            0xBDEE1FEACF16FC18ULL, 0xF2BC5D8E5F930B7FULL, 0x93DED383E90F1925ULL, 0xDC0C426E65D7CBE7ULL, 
            0x033A395A604B8614ULL, 0x70FC7EFD2095E225ULL, 0x8BA39D0E412102D5ULL, 0xD33DFF19E031B012ULL, 
            0x4D14E96370D3D945ULL, 0x171C97CCBC0DEA08ULL, 0x68F4915E03AC6BF2ULL, 0x296FE820552AB537ULL, 
            0x6EF6B896EF594AE4ULL, 0x239C7FD2847EEE91ULL, 0x653FC588644D5B27ULL, 0x69CD5E248CADA4E5ULL, 
            0xA949512D623F206CULL, 0x3CC68609C00DE967ULL, 0x4073A1C88295A5ABULL, 0xFB76279AE38EABC2ULL, 
            0x1CA625A35D542B12ULL, 0x4D23E0F777C12D31ULL, 0x65B56FD8FCEA31D1ULL, 0x4FA53542D90073BFULL
        },
        {
            0x4588C0AA387ED740ULL, 0xC8D65F6C3ED7B71EULL, 0x4FBBDBA4E6062CFCULL, 0x2A17687B48FC01ADULL, 
            0xB5A01CFA2559C418ULL, 0x7F3C43702356D693ULL, 0x405C6578B1AE790EULL, 0x5E476BC234FC6A4FULL, 
            0x80D856E97DE5F7C0ULL, 0xC7319FE709140FABULL, 0x644BAF9A3603E0A5ULL, 0x6D2DFB451DCA9DC9ULL, 
            0x49FAC90A8707FADBULL, 0x7D289A3542B08EC1ULL, 0xFF31F2105D5E16FDULL, 0xBEB4051953523113ULL, 
            0x3D9B58934310D2BEULL, 0xBB3B77A7C4FC97B7ULL, 0xE6B4CED2E9ED1A9CULL, 0x15B16D97CFBACBBAULL, 
            0x6CAF7F987B6FB8DAULL, 0x9BB3F0DED74DE1A2ULL, 0x418E777B8C4048C2ULL, 0xA477C53189425F9AULL, 
            0x6F44FD8D1E54813EULL, 0x70D714B5C77BA98BULL, 0x58F33A4B1DE5C8C0ULL, 0x49C947A2B017B719ULL, 
            0x7047E8C587040057ULL, 0xC95C770CDFB9B939ULL, 0xB6C98B638AD37E62ULL, 0xB7C8345C0F4E4A9DULL
        },
        {
            0xA5FEC1082971A1F8ULL, 0xA1E0DC4308715276ULL, 0x5BCE82873E6BC5D9ULL, 0x3433CB7A6D9CF948ULL, 
            0xBAF96C169F70B2B5ULL, 0x09E2E167C98CDA26ULL, 0x3A95334488CB0DA0ULL, 0x51F56BBF8ADCDA8AULL, 
            0x6BBA4BF560A53152ULL, 0x165E1AC384E73962ULL, 0xD5324D60CF33AA3FULL, 0xAADC63A77213CCC0ULL, 
            0x615EA3FE7406F0CEULL, 0x5729DCE495AAFC22ULL, 0xAC1A9CD8FF5DE5BFULL, 0x77C704624FB6879BULL, 
            0xD56A0FA746D4E46CULL, 0x60D5FFD6F0BCEDEBULL, 0xCFB4B6C704861FA8ULL, 0x055F9530B8F01F15ULL, 
            0x2BC0FC04757638EAULL, 0x51AA37FE4B6B10E0ULL, 0x7991DFBA4CB567FAULL, 0x55038103DBA27439ULL, 
            0x20CF276D29E8DA28ULL, 0x05733F6794EDBD04ULL, 0x77F0B7D5DAB3E8C7ULL, 0x2BAA9C7FAF08D610ULL, 
            0xFAF4A3BDCEC8401AULL, 0x21C1E30A4B37BAD2ULL, 0x21B14420D65DC960ULL, 0xA1410A950BAE46C9ULL
        },
        {
            0x81214CA3E02DE7DAULL, 0xD121048D5D40C588ULL, 0x3E4B151FD95D111CULL, 0xDBF9DE25349CECF5ULL, 
            0x7D05A35DAFAB2F96ULL, 0x636E34B393DE1DD3ULL, 0x64FA8DD78FFE6039ULL, 0x2C45999FF372837AULL, 
            0x450DEEDBF67BBF72ULL, 0x956D01A2D295C386ULL, 0xB1B83305DD1A2094ULL, 0x231E36092445ADA6ULL, 
            0xCBD6F754D044ACD1ULL, 0x98E581B62C4F5319ULL, 0x6D76615F982B38EBULL, 0x38E99672F89168E2ULL, 
            0xA2F55DC3F2F02AD4ULL, 0xEC5ABCABD7702EECULL, 0x83F163A5ADDA4C72ULL, 0xEE02065C7305ECAFULL, 
            0xB053757B29C77327ULL, 0x012F75AA210CC01AULL, 0x4BD8E13E9D4AA88AULL, 0xA3749920BBB70A9DULL, 
            0xF6AB0CE6A70783C6ULL, 0x258B692BB3507AB2ULL, 0x4EE63005DFD58AE3ULL, 0x53DBB546F5972C2BULL, 
            0x2F1A30DA2F64F60BULL, 0x30931AC6117BFC4EULL, 0x767369B457CEE6F6ULL, 0xE416617C12456C37ULL
        },
        {
            0x9F000B3B114FA6C3ULL, 0xFCD8F5A33FA3022FULL, 0x053844B3FA017A01ULL, 0x4BCD1519722A0C81ULL, 
            0x290A6BE0AD8D6AD5ULL, 0x24A49959CBF8F36AULL, 0xE51C0F4535165656ULL, 0x62F2FD63E9BC1469ULL, 
            0x728079C1273BBE30ULL, 0x67BDFF48B593165AULL, 0xF582DD03DC029D4CULL, 0xBEEB98C8E966E90AULL, 
            0xCBDDC229DE572239ULL, 0x75B1FCDB69C3A2E7ULL, 0xD27BA4B2189A0CEDULL, 0xFCACD153C314D4E7ULL, 
            0x44ABB85D348806FAULL, 0x5AE6EF3051CE12FEULL, 0xD9DEFDB5AAD79E75ULL, 0x782E5BA1EF54AFB1ULL, 
            0xC3A0696E12534C5CULL, 0xBBD89B95FD6A3595ULL, 0x126B112F057C0AD6ULL, 0xAF39BA7C032E58ECULL, 
            0x5DCE7632B66ECE49ULL, 0xFE759272D919191AULL, 0xEACD209C72225457ULL, 0x28164AC5CB54268CULL, 
            0xD43B5FC94CC50AF5ULL, 0x422435E0E7761E2FULL, 0xBCBFDCD4DF066C1BULL, 0xD79BA5763D913781ULL
        },
        {
            0x1CDC57CD89BBB9FEULL, 0xB2968D762466EDA2ULL, 0x16ADBED3F57BB7F9ULL, 0xF9777C0DC22B7B47ULL, 
            0x5373DCDA34EB20F6ULL, 0x34E684A20327922EULL, 0xC0834F83A96558CAULL, 0x163758F130D3E455ULL, 
            0xC8EB90E76BD4305DULL, 0x199A239FDA513311ULL, 0x527B4D0A0DB5718FULL, 0xF0D635FF0833A0D1ULL, 
            0x1B89B62DA82FDD2CULL, 0x88CCD176AF9819B5ULL, 0xFE11E40DABC3AF4AULL, 0xF0D3626D7DC9B45DULL, 
            0x5BF8E3520CFFAA23ULL, 0xBEF45F8584F705A4ULL, 0x2ED24A977FA6F635ULL, 0x3A53C9F44012F211ULL, 
            0xBB5F3DBF07EAC6AEULL, 0x7AA6480576AAFE6EULL, 0xFED5B5F4C9C3DE7DULL, 0xB3EBCD2E3F6F4E74ULL, 
            0x41CD622C45496469ULL, 0x24C72A3F981DB2ADULL, 0xF43D04DCF76AF981ULL, 0xE1EC6167BF453F26ULL, 
            0x39FC5F712DC98958ULL, 0xBB236B10A7258619ULL, 0x1272FBFAE29C8E82ULL, 0x408C2EBAB6C5EF64ULL
        }
    },
    {
        {
            0xD957A98CB941EBE6ULL, 0xF14484755B33143FULL, 0xD772EF9C94FDA3CDULL, 0x8BF8AC3AFCEC99A6ULL, 
            0x925DBC71D9D9562BULL, 0x938A9F24EF69908FULL, 0x3D4496F96483B3CCULL, 0x520F87F91B593BA4ULL, 
            0xE4779150209AAB31ULL, 0xC5EA02E9015C1525ULL, 0x60E6B9277AEAB636ULL, 0xA0DE8A2802260623ULL, 
            0xAD8434177D268D6BULL, 0x821EFE96592AF236ULL, 0xCCEB1AEADBFD2702ULL, 0x77BDA26CAAC5D69EULL, 
            0x09BA4E6D107D018FULL, 0x5FE6C179D603BE12ULL, 0xC25A4C5DDE3C0D77ULL, 0xBD2F79F6D385D01BULL, 
            0x8B003CA064A46218ULL, 0xEED9C86A114230C3ULL, 0x2DC305FFD25EE490ULL, 0x6CCC150108872D4DULL, 
            0x90E365AFB250EDFEULL, 0x341AEF01AB1909C2ULL, 0xEE6910C89D4C22CCULL, 0x61DB68BD07E58437ULL, 
            0xB04CFB13F6177012ULL, 0xA29CE00303A7F3D9ULL, 0x62E971F834D989BFULL, 0x8D20D163F0C100ECULL
        },
        {
            0xB3F3BE041A9C187CULL, 0xEC9A09FD291EAD17ULL, 0xF4C55AF3A7B66899ULL, 0x5913994C5054B9DFULL, 
            0xBF46D56F90FB8012ULL, 0x9BD4E88313EDE10BULL, 0xF5B2EE7DB1F6C9E2ULL, 0x5A8667A5CCF6B959ULL, 
            0x9F849E52DC58CC6CULL, 0x932EAAA94E49BF13ULL, 0xDE69EA0C6EA7D06DULL, 0x2991579419E1992FULL, 
            0xC3FA13812B58D747ULL, 0x79C7A77A9340BA26ULL, 0x1353881B528A282DULL, 0x1F7A6C88EC97016FULL, 
            0xF0E9C550D306B704ULL, 0x221CF25A2287F6DFULL, 0x421F908D762C2281ULL, 0x3E6BB21296436084ULL, 
            0xCFAE13DFE4DF8F0BULL, 0x370B8997C60B96A1ULL, 0x342C3A7295E82110ULL, 0x2EDCB4A4750DA4B1ULL, 
            0xEDBB31A10007BC50ULL, 0x7B6D0425E8DE5EB7ULL, 0x39F248EACB1242CBULL, 0x25CF9E78323497D0ULL, 
            0xBEF3947CDB326E86ULL, 0x34633646149E2E79ULL, 0x348FD03EA325AEBCULL, 0xB21E16194D9029D4ULL
        },
        {
            0x5EAD4437951CA774ULL, 0x574400E10FAC3AC0ULL, 0x0F6CD47416167BDAULL, 0xCD405E8361C408EFULL, 
            0x8744D61311AE64F8ULL, 0xCC54CAC88F009EFEULL, 0x1BB1891DAFFB442CULL, 0x9B4E3A2582FAEE9DULL, 
            0x0F586050999F0F96ULL, 0x7C062880E9DD5801ULL, 0xEC64C1AE343A320AULL, 0x908B269667C083CEULL, 
            0x5D67303DA33693EBULL, 0x305486D113E0E397ULL, 0x17170204E477EC11ULL, 0x5555968B3E801BB5ULL, 
            0x4D3ACD98E26224C8ULL, 0x290F73DB57F92E1EULL, 0x0F7C2109D4B7556FULL, 0x01D2D4DAA21DF052ULL, 
            0x63A011B8B2F2273FULL, 0x945F3F8282EB4187ULL, 0xECAA7824DEBA8D84ULL, 0x794D480B26690F42ULL, 
            0xC82579E0F1A31E53ULL, 0xD558A3466A1DD43CULL, 0x1F412D30F04656E6ULL, 0x131431E68B8F7D39ULL, 
            0xB5458637917527E3ULL, 0x61B34D63C071A7DDULL, 0x23FE304F9A08C102ULL, 0xAB28DA81594B5A74ULL
        },
        {
            0xAA7BF15A1B002991ULL, 0x53680000C0237F3BULL, 0x3E31A0CFBD705198ULL, 0x3AE3DBAD874ABF51ULL, 
            0xEE2085609560BBA3ULL, 0xCB50260A8E73C02CULL, 0x6B97A63274497A0BULL, 0x1B6ADEF14ADD3C15ULL, 
            0x82095FD51EB71A95ULL, 0x3ACAEC28E99707F4ULL, 0x63EFF90153AEA68FULL, 0xEFE18A3766DB8EECULL, 
            0xF4E50383EC8F75F3ULL, 0x40C49E4476F5CDB9ULL, 0x1A02EC6D0CBC0DCFULL, 0x3CAEC83B9634B1F6ULL, 
            0xA94C3E414FE748FBULL, 0xFB423902BAF1E84DULL, 0x77A8A8CCAC93B959ULL, 0xCCCCE01EB00A0FCDULL, 
            0x15584E0F34A51610ULL, 0x32863349DB2A28B1ULL, 0x73445AF6695E8B19ULL, 0xEC2A6769100870D7ULL, 
            0x8119E1161EFAA0F9ULL, 0xDD567B26B1D5C2B5ULL, 0x48EE9CE217371C84ULL, 0x50B2F9533AF0DFE8ULL, 
            0x31159D1CC0872692ULL, 0x0610B37E79E1BB54ULL, 0xB6835CF232A922A5ULL, 0x817934702B4A4DFEULL
        },
        {
            0x8898AAA7FA47CA1AULL, 0xFB1A6939F0ADFD2EULL, 0x6CF0D6066E53253AULL, 0xB71BF367AB301DDAULL, 
            0x4343AA152CBA9411ULL, 0xA98A226A00F6588FULL, 0x00B834425E416333ULL, 0x89FA54B1DFA7DF0BULL, 
            0x516DB6EE88DAE10FULL, 0x3B71359B838A6E21ULL, 0xF4E40937E1CA04F1ULL, 0x87B8D9BF8EDE341DULL, 
            0xC81DF708039B1173ULL, 0x126F6C3B8CBE5105ULL, 0x6E2754F14F1DD520ULL, 0xE45294CFED925E9BULL, 
            0x03D71964328C32B0ULL, 0xC3E3B515E69BC85CULL, 0xCA907CB6488985FDULL, 0xFAD3A9B5C053E823ULL, 
            0x849493C2464959FBULL, 0xFCDE0CC32AD949CCULL, 0x49BF3F895F984BB4ULL, 0xA63A77878F467B1BULL, 
            0xB84D2D46B4CB7C8CULL, 0x7517E82445379ADBULL, 0x81A1128B11FD347CULL, 0x4230376B1FE09DE7ULL, 
            0x990C1C444CFA4A70ULL, 0xEB28355451FF5EA4ULL, 0xB53EAD8728DDA511ULL, 0x3C92821BCAE7E0CAULL
        },
        {
            0xE45BC72AC2E64AE3ULL, 0x2A66AD6503C06E76ULL, 0x0DC68260665FA17BULL, 0x7C0327F9914053A3ULL, 
            0x802724CB5E202A8AULL, 0xF152A561E3FA1BA8ULL, 0xBA2CA1015B1F769DULL, 0x29494DF265FBE929ULL, 
            0xE2CF061A446A4D67ULL, 0xB212C9388EE3A4E9ULL, 0x44BEF4B5A48AAE2CULL, 0xDD0A60E7B08FC17FULL, 
            0xE3DB69339B186E65ULL, 0x817F35B5ADBF9B84ULL, 0xFDA22CEA8A0A99DBULL, 0xFC10F7827170013EULL, 
            0xB4464668479D5F1AULL, 0x5F5F658422A2A225ULL, 0x6FD6A77F02D6A7FCULL, 0x84830E8FF72F9333ULL, 
            0xD00FD51EF473C0C2ULL, 0x12E07A00869988B1ULL, 0xB71F447C42741A49ULL, 0x8A11503F6D3578E5ULL, 
            0x8B6C22EDFAB60C6DULL, 0x880B690A1D4CE2C4ULL, 0xB497ABF18C0ABD13ULL, 0xCF081B1294BD1AE5ULL, 
            0xCFEDAB49095011B1ULL, 0x1BC3442901B3C4DCULL, 0xF286DFFF604D7867ULL, 0x3CC4549E56CC10B8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseGConstants = {
    0x54473B133D05AF0EULL,
    0xF16C5DE78A81CEF3ULL,
    0x37C2396384A6814DULL,
    0x54473B133D05AF0EULL,
    0xF16C5DE78A81CEF3ULL,
    0x37C2396384A6814DULL,
    0xE0F6733D7808FDACULL,
    0xDBD7279C88F345B2ULL,
    0x6F,
    0x16,
    0x0F,
    0xB3,
    0xE8,
    0xF4,
    0xCC,
    0x91
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseHSalts = {
    {
        {
            0xFCFA441E591C4C21ULL, 0xA983D6D988748691ULL, 0xBF06AC3B51487CCFULL, 0xAE2174B3C58209B8ULL, 
            0x11F3C346BB6486E8ULL, 0x46D02ABFBF8ED686ULL, 0xD1D2B552E75FC8E4ULL, 0x0BA67512898DD7A2ULL, 
            0xBB4BF1D0938C60F9ULL, 0x6006EEFD74303CF1ULL, 0xECD50AF224918B7FULL, 0x8CFBFC6C753B04F2ULL, 
            0x50348236E9D18CD0ULL, 0x488E7F477A88EB50ULL, 0x1D632EF59F0279C2ULL, 0x9FE4F9F8E7A08DD0ULL, 
            0x89E3E60D6D315B50ULL, 0xC193D3B631C86032ULL, 0x0FC807A7F94013AAULL, 0x459CF0EF05882CC6ULL, 
            0xB12CEE432424F074ULL, 0x3140B5A9FC977AC6ULL, 0x05CBB5C6546241C9ULL, 0x09F51AB38D7C743BULL, 
            0x1F279FF8FA9B85E3ULL, 0x5DDF575C7031277EULL, 0x6369528BD41D9696ULL, 0xD8962C0F91F4F06CULL, 
            0x03ACBA60BF470E98ULL, 0xBAC4B871A70D7E25ULL, 0x2A591623034C98F5ULL, 0x0B45FD7A55C7C0ECULL
        },
        {
            0x19BF4B560DD7B7C4ULL, 0xE585109133B428D5ULL, 0x8FBB15E04477B303ULL, 0x858BAC4B5BD7CE38ULL, 
            0x3DDC43C371F194C4ULL, 0x03C068EBE6A722A2ULL, 0x7512837CA287616AULL, 0x5B929882974728EEULL, 
            0x9EEDCD856C3305ACULL, 0xC9787E213AC99226ULL, 0xA69F25EC56F3E1C7ULL, 0x858F018AC77EEC30ULL, 
            0xBCA62594AA7B1082ULL, 0xD81D88A9AC552ECDULL, 0xB09F908CF3CEAE8EULL, 0x507DCF0AC53E42EFULL, 
            0x637C65C6834D0214ULL, 0x61E493D768715102ULL, 0x6519726755B7C699ULL, 0x38A6C5C4CA9130BDULL, 
            0xC2BA70B678385887ULL, 0xD19FAA58A25C2883ULL, 0x336ABE0F301DAED5ULL, 0x8959082627EDEB18ULL, 
            0xA63BA05D1C6C98CBULL, 0x9BAD62F08DAB1DCDULL, 0xA7A13A6E63C92F6AULL, 0xF7466E2C3AB015A9ULL, 
            0xECEA85CD18A43E01ULL, 0x0178191E082C947AULL, 0x89D44264C0733753ULL, 0x5A1AEBD4360FF4B2ULL
        },
        {
            0x5E50FBDE5A7F9155ULL, 0xA47967B06EE62428ULL, 0x246A8D63C9A63481ULL, 0xD549AD0F42ADC1C2ULL, 
            0x36A7DBEABC986CD8ULL, 0x84E23151668D329DULL, 0x45AF5F3D374AAD91ULL, 0xD7C9FE30B8077E87ULL, 
            0xAC658B68DC4DECDDULL, 0xC8B9649F2EAACC19ULL, 0x9511AD0DBC2C3265ULL, 0x5318443D2747F4B9ULL, 
            0x833CD93920076F65ULL, 0x0D17E44AA56DFE8AULL, 0xDC4701FB9702A677ULL, 0x7C433159556CE758ULL, 
            0x6989643674CFB43DULL, 0x0AD04B6FA128CE2DULL, 0x2D034557B49866E4ULL, 0x1020B98178E7B05BULL, 
            0xDC1A6712B93E3B3AULL, 0x58CEACC8C780FA52ULL, 0xCCAE397C46511283ULL, 0x660A76EAA7447793ULL, 
            0xA3FC8823F97B447EULL, 0x2D752391D7CAB669ULL, 0x120ED80717030187ULL, 0x2CC76B5C59B1BF16ULL, 
            0xE493EAE5C9D5B1DCULL, 0xAD2655E423CC7B3DULL, 0x5876FE67F0931388ULL, 0xB4E3B36758641960ULL
        },
        {
            0xE251D176B3435987ULL, 0x842D7FDAD1CACFFCULL, 0xC031FBE9EDBAB8CBULL, 0x8DAAC6200151F8E6ULL, 
            0x33B738F489FCFC1CULL, 0x3674B27ACEBC4B27ULL, 0x73223F30F86D00E5ULL, 0x237C29E6B71EDF08ULL, 
            0x0CFA3C005CD3419EULL, 0x4B1BD51C6FAC5610ULL, 0x1B0B3FBC6C60D8CFULL, 0xDC4946B8A11D5472ULL, 
            0xBF70663FC3665124ULL, 0x028339326FADC03AULL, 0x2C602A26FD41EEFDULL, 0x8508445823FD4F6BULL, 
            0xDC2ABB17335CE6DCULL, 0x9C2EE0BD03BD71EEULL, 0xF3B43E915781215EULL, 0x8310E24546327A34ULL, 
            0x1B2E5DED19965468ULL, 0xCF6C3B196690F498ULL, 0x06E3ED098385E9ACULL, 0xC1099601506B28E9ULL, 
            0x2D06B00ADB548F48ULL, 0xC607BD92FB897558ULL, 0x0AC212C6ECFF108AULL, 0xD7AC0A2DF83787B1ULL, 
            0xDE69D17F0B5BC93EULL, 0x6A270DC2EC65D39BULL, 0x7227430D72873CB2ULL, 0x7259E9BFA8F5D516ULL
        },
        {
            0x19A79A9A4F49EC2CULL, 0x2AC4B47BCE2ECA46ULL, 0xA07FA6E15E31F19CULL, 0xB72BA2E895D19247ULL, 
            0xA6B351EABFD83C34ULL, 0xF62B38B9F87A4EC2ULL, 0xAC51B135238B147CULL, 0x0C62E39E52CF3975ULL, 
            0x51322D891D54F791ULL, 0xB11A580B25104382ULL, 0x7C2ED6DD88BFAAC1ULL, 0x7D64770C7827595CULL, 
            0x9F0772E591585519ULL, 0xEAEBB4D93A5300D0ULL, 0xD4B7BFD146CFD695ULL, 0x239B6F3971A40907ULL, 
            0x6F890606281462DAULL, 0xF70730C92FBD27FAULL, 0x8950D5450A341F14ULL, 0x3FEE1E4BD48D48BDULL, 
            0x87FF7ACB5A843BA9ULL, 0x80A6D42BB45A8F94ULL, 0x7FAD8117DA90196BULL, 0x7FE05E6959159B86ULL, 
            0xCC030EDC16601F0EULL, 0xE5E5F16E991CC911ULL, 0xA36F2C63D7ABAE6AULL, 0xB9D1395088BBFE6EULL, 
            0x416097606A0F760DULL, 0x5C7ECB586E1077AAULL, 0xE60ED19300C8C046ULL, 0x037DCF1D56B0F22AULL
        },
        {
            0x5944D138690765A1ULL, 0x3DECCBA4EB42A360ULL, 0x685AEF3561220179ULL, 0x493AA62A54E2B814ULL, 
            0xE52648A8C96A83B5ULL, 0x55E8D88F56FEBE5DULL, 0x3D8796F71C1DFD91ULL, 0x9A605C296CEB508CULL, 
            0x1EA1A53BCEB379F5ULL, 0x644D334C118C5EA6ULL, 0xF665431F394AFF03ULL, 0xBD94F662057C5D9BULL, 
            0xC789916156B352E1ULL, 0x9CE12F746B84A02FULL, 0x33ADF8879B5786EFULL, 0x5CB17A467B452591ULL, 
            0xE17B5CCFDCCD8D60ULL, 0x524A18E1EED6ED79ULL, 0x039F217B58B7CE7AULL, 0x3593638E5B5CDDDDULL, 
            0xC45F52BABB362906ULL, 0xDA02D4AA4E7D91E1ULL, 0xDC264D5F2CCB06DAULL, 0xEDF26A8B9F88850CULL, 
            0x278D0F84F1861DE6ULL, 0x2265E947FC8C319DULL, 0xA08E28E32255DB81ULL, 0xAD621D4B68996FC5ULL, 
            0xA0FD16B498F8DAC0ULL, 0x58DC84A071A38C96ULL, 0x9F0669DFAD8012A6ULL, 0x604380E244FE859AULL
        }
    },
    {
        {
            0xE52F1B9F56DA6D9CULL, 0x58E48450C25BA268ULL, 0x8286463DC856259AULL, 0xF30FBE9BABC36517ULL, 
            0x5EB087DB41406BF4ULL, 0xF45625BA05B3B5ADULL, 0x162387344BD42F9CULL, 0x181C89060565A771ULL, 
            0xF5B61CD2167F9954ULL, 0xF83732B7741F8E41ULL, 0xB91B4D926953C0E4ULL, 0x99CFF3F574C27308ULL, 
            0xEBBA171AE89DBFCAULL, 0xBAC78C2207C8196BULL, 0xF73F5E6058E76642ULL, 0x40D91EE8551B1B4FULL, 
            0xD5DD4B6F43EBE19CULL, 0x6F3B3C23A90C4A5AULL, 0x9CB13F5B72780168ULL, 0xA7B9A2345D50683CULL, 
            0x582328F0F97667D9ULL, 0x51AB38A5FCC940BCULL, 0x082F7A847BBD8C9CULL, 0x7817A36D0B78360AULL, 
            0x3D04748FD21788DFULL, 0x5D265DC48F4BE6F0ULL, 0xFD25396916BDD397ULL, 0xEE35B210118CA26AULL, 
            0x6F736EF47288C6CCULL, 0x7CCA687B0D21F50CULL, 0xDA78122A31573252ULL, 0x6EA6D6E8024DA013ULL
        },
        {
            0x2618A247279EEA94ULL, 0xD59ECB74D82C55F9ULL, 0xC1C495D58760D9E4ULL, 0x2AC28AF480934EF5ULL, 
            0xB6F0E2ABF8CBB95CULL, 0xFB92BF8801DA8DB8ULL, 0x0C54D6C02E4C200FULL, 0x75CE533DA010185DULL, 
            0x4FE16AA77C78C518ULL, 0xE995863450DF8070ULL, 0x1B6AFD9AACE792DFULL, 0x2003A2237718576CULL, 
            0xBD95321CAEC64B08ULL, 0xB36A4582014A1B70ULL, 0x90F7CC5E047A6B10ULL, 0x3E6CABFA94240745ULL, 
            0x2A8119A42E82A558ULL, 0xFACFEB0F86DD4CA2ULL, 0xA552E36C31F7C31EULL, 0xE21D5CB8E84A197CULL, 
            0x8FC6A21E399561FCULL, 0x2FE64EE969F413A4ULL, 0x907B442196CDA6A0ULL, 0xA07D24F7113D2A0CULL, 
            0xE4C9DA679622DA83ULL, 0x2B4688DD65CC99F6ULL, 0x82D0F4D681680BE1ULL, 0xD72B2A10A868F6F4ULL, 
            0x1298E7D9CFA2B6F0ULL, 0xE095CE549E4CE9A2ULL, 0x0612B64DEE4D3F0AULL, 0xCF8BC71B72A17147ULL
        },
        {
            0xEC51B5429691257BULL, 0x8D0B3CD249348B63ULL, 0x8D418BF1F31EB8F7ULL, 0x9DFCB98177C63015ULL, 
            0xFEFA0F8667FF4A71ULL, 0x4E335A37924EECB8ULL, 0xA2692A3F91D91539ULL, 0xEB67359310564A69ULL, 
            0x1EC04CC91D2BF4CEULL, 0x277DD33DB111056FULL, 0xFFF90ADD9A789D25ULL, 0xA10F380A4A4ACDA0ULL, 
            0x4DC74081C76C28C8ULL, 0x589960C35404CE09ULL, 0xC66357E938339A1BULL, 0xB1D2DEFBA6F4E390ULL, 
            0x3D6988CEA5389A02ULL, 0xB949D447FE20C287ULL, 0xBE51FBBB53236487ULL, 0xA99D8BA9DAB1FE42ULL, 
            0x2B19457D379D7843ULL, 0xE6B9AD0DF7167F2FULL, 0x7175114BA034069FULL, 0xB99CD283B4953BD0ULL, 
            0xFDD766202C2DD69EULL, 0xE0F1C1B135497380ULL, 0xA438CA68A2ACCFF2ULL, 0x40E6747017B7337FULL, 
            0xA7C5E4F186E9A1F8ULL, 0x33DD6AC1F87F0616ULL, 0xECC157FCFC19E9B0ULL, 0x5430B45C01F57D1FULL
        },
        {
            0xD5F0006F7B67A57DULL, 0x3878DBAE6E39C970ULL, 0x2F1AA0094BB012E8ULL, 0x3208AC092D4E55C4ULL, 
            0xC456A921CA22C5C8ULL, 0x98BC33E6E292FA1AULL, 0xFF1AF30AE9060144ULL, 0x87C3D6DB607A0240ULL, 
            0x5883B83F95153518ULL, 0x01C55D9A71A4BC69ULL, 0x4CC53F04D14E5FCFULL, 0x40E66F137467F4ACULL, 
            0xEE6254710C586B67ULL, 0x3303B27EE327EDD4ULL, 0x7F7684B89D0E64C8ULL, 0xD385639138EDA96AULL, 
            0xDE4B85F8698E7468ULL, 0x4C2306943E686DE4ULL, 0x08D8F7A326010B33ULL, 0xF119735865FD1903ULL, 
            0x091FFC22A3BB3E29ULL, 0xC45B0E982F9A4574ULL, 0xEE36337F57FC382AULL, 0x3FCDB213BBA52763ULL, 
            0x47D62D543991002FULL, 0x399435AA3F23A56FULL, 0x7F86383C3D96D06EULL, 0xF1B78A1C1B1EF330ULL, 
            0xD7774157A5E4C623ULL, 0x85DEFC226520B224ULL, 0x83227C84C5A68095ULL, 0xB9337049A369A82AULL
        },
        {
            0x658C1988869A7094ULL, 0x71A12463CEDAC2EBULL, 0xF7A3BB307D361558ULL, 0x62834E84B4F91BB3ULL, 
            0x1F78C2B23F6C4813ULL, 0x10606841F4F144ACULL, 0x649A58ED06CD006DULL, 0xD3BB2EBDC1E455A5ULL, 
            0x8FFE84F660185C1FULL, 0x1DDBE4DA49F21FCDULL, 0xA6AA2BB38004211FULL, 0x53345A99721BFE2EULL, 
            0x979BB8D270D06E18ULL, 0xB3309A153294A2A8ULL, 0xE1B39DAB99718834ULL, 0x6DE96CB6B42E8F79ULL, 
            0x9CA6BC33AA50F099ULL, 0x2B316D78BD1FB8BFULL, 0xB89FDD5AF4DBA9E8ULL, 0xD1A7958BD42CDAFBULL, 
            0xC7DA8AD548B52330ULL, 0x40BEF0C2B5EE1BABULL, 0xECC46690DD080C38ULL, 0xA5DC8A8DEE6DCBB3ULL, 
            0x799BAC94CE8CDFF1ULL, 0x349F0AEB3D6ABA6CULL, 0x8B5F052907A676C9ULL, 0x4F9EEAE2F58033CCULL, 
            0x1D843F8F52D4BDF0ULL, 0x87F21CF26F0F77DAULL, 0x55958042502985F0ULL, 0xD30ACB2F39717510ULL
        },
        {
            0xD0FE6833FDD5A12EULL, 0x0F783766C5731AD4ULL, 0xCD051FCC58DE3FD0ULL, 0xA4A7F7429362904AULL, 
            0x59E73F4184F8FB86ULL, 0xAA3FFC06AF1B4CE6ULL, 0xE28EB95B0574FE8AULL, 0xF702DAC43E62B9F7ULL, 
            0xB87CEF1BFD9C53D4ULL, 0x39ACB1E4B4E24533ULL, 0x464A842412E67A57ULL, 0xF95E403B6657CF19ULL, 
            0x1043D6421ECC7B46ULL, 0xC75B21787F76C2E4ULL, 0x75030119278C2DB6ULL, 0x4B98EC4310887407ULL, 
            0x09A737E727469349ULL, 0x653BD6D8C05871B5ULL, 0x23692369556E3C8BULL, 0x3D6A75108AF06578ULL, 
            0xCC0FA69CC1C994FBULL, 0x3981FE05C166EF64ULL, 0x8B529C99F36570F4ULL, 0x25A1EC8F966A2B15ULL, 
            0xCE33237AB23C71ABULL, 0xD4383C9F510A1F61ULL, 0xB1747E5B3AAAA7C7ULL, 0x7F368214B079E592ULL, 
            0xD321237E8C8FA4A0ULL, 0xF307242622C7AD7EULL, 0xBA9E2DEC2AF6141DULL, 0xCB548AB80CFD97A1ULL
        }
    },
    {
        {
            0xD6EAC00D3980A8F8ULL, 0x2BC4F9F0E98C6A50ULL, 0x810E23B5F273BC1AULL, 0x242462384F3B8651ULL, 
            0x6E1D14E5723A1855ULL, 0x5FA8F3886B7396FAULL, 0x5FD7BEEEA84CB7A5ULL, 0xFF01355A9F6ED69EULL, 
            0x8A25B8A9E2F90FE6ULL, 0x7413633A8F404180ULL, 0x6F0D0D34FA2179CEULL, 0x979CD756A4ADA36CULL, 
            0x5D4A3C7C234D6CA8ULL, 0x77EB8176C8CDDA85ULL, 0xB181F5D315E64793ULL, 0xFC469901B415E13AULL, 
            0xD018418FE50FCA61ULL, 0xAE89894A95248031ULL, 0x5E33B6567AC76427ULL, 0xD66F68175545AF89ULL, 
            0x9849C94FFC77E2B2ULL, 0x4395FB5990CDD477ULL, 0xB5ABCE6396113913ULL, 0x6E1C644AB1A727D3ULL, 
            0x36151AA86E9A099AULL, 0x28F2959F8768E806ULL, 0xE24A9EFA6F428731ULL, 0xC99359AEE64A82A9ULL, 
            0x2DFFDA6D8EBDDDCDULL, 0xDFDEFC0886B73824ULL, 0xF5AC36B4CCE0F9C4ULL, 0x7AE5DD4696631B7AULL
        },
        {
            0x0BDFA9B58469B88DULL, 0xA187272E147F0780ULL, 0x744AFFC192F1EE52ULL, 0x73CC57BC2B8E9B52ULL, 
            0xF091F7E6553E29B6ULL, 0xADED84AE8973ACA6ULL, 0x44CEBE1397FC461CULL, 0x76D7D216EF2443B0ULL, 
            0x17606383A371C0C6ULL, 0x1E23B81E253E88A4ULL, 0x33689E42E7DFE845ULL, 0xDC0A557DD5497348ULL, 
            0x0EB56983CF16D365ULL, 0xCDF37645556EEAF0ULL, 0x80F1789E7E813309ULL, 0x9133961D4C0EFCC3ULL, 
            0xCA7BC40FB55ADFB8ULL, 0x3EBE6D49C70CD33BULL, 0x1AADD7777E4F2613ULL, 0xBF50DA490462ADDBULL, 
            0x09E65830D3C20871ULL, 0xD7BE18D65C0E2805ULL, 0xF4B27C3AF1F7A018ULL, 0x63967AF2B9405144ULL, 
            0xB914B4368B067BC3ULL, 0xA1F28C0A6CB4E20BULL, 0x688E145AAFF71B5FULL, 0x82C55453EB595E81ULL, 
            0xF9ED59DB58301C65ULL, 0xCE1DD5770C045745ULL, 0x909A19631432166CULL, 0x9B50167E5B0ADD3CULL
        },
        {
            0x4E48720907ABCD28ULL, 0x7495FFAC5C88E0E0ULL, 0x142CE0C8BAB9217DULL, 0xD05C7D5D7E4D1B1EULL, 
            0x7A9D6A7FD1776CE5ULL, 0xE7FDA95A89B06770ULL, 0xDF1BCDA239874241ULL, 0x1C96180D621C71F0ULL, 
            0x1D3713136B36D022ULL, 0x30BAA18476C44D6AULL, 0x8DBEADA973F2EC14ULL, 0xEAD057EB5323DE27ULL, 
            0xCCC56E97CF3854F6ULL, 0x6AA90239D6E6B3CCULL, 0x63A657F906E778B1ULL, 0x68E888A3A8DC3C3AULL, 
            0x169D81C7026028FCULL, 0x7F826E76E33D8F57ULL, 0xD494FB8701A08707ULL, 0x131D3EE81BC63B11ULL, 
            0xCB2DB2F7BA81F520ULL, 0x6B7080CE1E3BE4C1ULL, 0x09AEDB96ACAC3952ULL, 0x495C9E65E0F59732ULL, 
            0x279711375F25E274ULL, 0xDE9824B258EA2706ULL, 0x203804DC7D09664BULL, 0xFD5F1D4B58F041E6ULL, 
            0xBC67D06CCD5A2F8AULL, 0x8F771D422851F302ULL, 0x7689D2CD8FB5858FULL, 0x624DA05FB01E343BULL
        },
        {
            0xE5BD5784DF0E062CULL, 0xD34502E164F52509ULL, 0x9D91FF6C7FD2F928ULL, 0xCD3FE154F1AFD102ULL, 
            0x35BC271B954F5C33ULL, 0x25ABBBBA1BB263AFULL, 0xC764C40FF3879E88ULL, 0x8636CE9677A9FD5FULL, 
            0xD000C2640DFCD002ULL, 0xE046E2FDB17C6AD5ULL, 0x6D3D62F4F6A9B6E0ULL, 0xE6481B63DB1FAADCULL, 
            0x4457E78E79053BA4ULL, 0xCE799B8B38A3B287ULL, 0xB1DFBFBD736D680FULL, 0x13B7EBADF042013AULL, 
            0x3BF87A99B3C6FF02ULL, 0xA4A2B0820F00E6FDULL, 0xB6E1C536CE1A4AEEULL, 0x24A7B4CC4C107A85ULL, 
            0x1C329D8BE65FC378ULL, 0xB0278C9C77062501ULL, 0xF4FAEB4F32B94C6DULL, 0xD2894FF7AA8AC6D2ULL, 
            0x1310C3F459255DE8ULL, 0x6D1EA87FD2B92F28ULL, 0xD17DE19E958350FBULL, 0x4BF92741EB3C05E9ULL, 
            0x43A8859E374384E9ULL, 0x31D810A4BBD2305AULL, 0xE4DA97E5EC594A37ULL, 0xE4F8BBDD236D5A1AULL
        },
        {
            0xC718291113911FE0ULL, 0xC3DC591CC899B1D9ULL, 0xADA0C6520C0C0149ULL, 0xFD2DB96C2669E726ULL, 
            0x1CE4448B6BBB34C5ULL, 0x1A2C86761136C933ULL, 0xCEA24C1FE46E5645ULL, 0xF60E10457B1B3A52ULL, 
            0x172C292E55CBACAAULL, 0x62B8A3965A333E82ULL, 0x1F7DBF3F66E57FA1ULL, 0x22787DECF9050230ULL, 
            0x116007E9C59720DFULL, 0xF45DD9A4E0FDFEA6ULL, 0x207030FE13A5FD55ULL, 0xA65BA9AE0D2E4FDAULL, 
            0x26327601D6BB9549ULL, 0x461A1065971F35A1ULL, 0xF89443FA00F3FDC4ULL, 0x649C6F4CBE846353ULL, 
            0x33F783570804C358ULL, 0x23111AE3745A735AULL, 0xD70C74B05CB60BC0ULL, 0x333F4527E81E9B46ULL, 
            0x699DA24B8CE72D12ULL, 0x1DC6B29340AA70C4ULL, 0x8249D007F74260F2ULL, 0xEA2415695E40173CULL, 
            0xDEE938417D68BA37ULL, 0x071A73735BB76307ULL, 0xD2D6C5C628D082FEULL, 0x71C540F17C84B2D5ULL
        },
        {
            0x7E34DEE84598410AULL, 0x4AA8EA02E1A666F0ULL, 0x277F706A6028326AULL, 0x89A3BB25DD4F811EULL, 
            0x7F005A46E493B76FULL, 0xF7E0DFBC839E4E04ULL, 0xB83CB22158598A7DULL, 0x5F1A187B1B6C5D63ULL, 
            0x3BA9985253659239ULL, 0xC5351210BB187D23ULL, 0xFC5D31247CC8699CULL, 0x5A132407860351CEULL, 
            0x2D984F2B91B2362FULL, 0x3EF897CBC8677A2DULL, 0xF54BD5538DACE65DULL, 0x5D744C64E7AA1CA0ULL, 
            0xEA5A9DED3FD530FAULL, 0x6BF54BC8915598B0ULL, 0x7DC5F2AE3D8B0A25ULL, 0x283E10297DA636FBULL, 
            0xC92BFAAA61AF284CULL, 0x9B4136DD8264964AULL, 0x87FA249D9198E0FEULL, 0x59FDB2BC6CCE71FCULL, 
            0x0D1418452FED96F5ULL, 0x3AFC202E6597BE5CULL, 0xBCE26A9F44B89112ULL, 0x0482A53BAE6D56E9ULL, 
            0xDBF4C8729691B886ULL, 0x431A6D255EFF860AULL, 0x7F6FF94147D4EA30ULL, 0x85F90574F0FB873DULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseHConstants = {
    0xC0ED2C67ACF4FC79ULL,
    0x3EEB602FFF59D96DULL,
    0x97C6AF7C67AD3D68ULL,
    0xC0ED2C67ACF4FC79ULL,
    0x3EEB602FFF59D96DULL,
    0x97C6AF7C67AD3D68ULL,
    0xFA55973603614B40ULL,
    0xA2FCDA2EC88494A0ULL,
    0xA8,
    0x75,
    0x5D,
    0x83,
    0x35,
    0xC6,
    0x83,
    0xDD
};

