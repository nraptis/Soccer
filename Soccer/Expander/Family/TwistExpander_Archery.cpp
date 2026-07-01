#include "TwistExpander_Archery.hpp"
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

TwistExpander_Archery::TwistExpander_Archery()
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

void TwistExpander_Archery::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x864A854524FD5F69ULL; std::uint64_t aIngress = 0x9692E576D266F213ULL; std::uint64_t aCarry = 0xF018F129BCF11ACAULL;

    std::uint64_t aWandererA = 0xD4A29D95E8CD5873ULL; std::uint64_t aWandererB = 0xD400AE7049ECFFA6ULL; std::uint64_t aWandererC = 0xE1E3A09ED88E9A83ULL; std::uint64_t aWandererD = 0xB5CA7FDBA4FDF797ULL;
    std::uint64_t aWandererE = 0xCF32C8AA636814C5ULL; std::uint64_t aWandererF = 0xD759F46CB611E52BULL; std::uint64_t aWandererG = 0x99932862AFA96EFEULL; std::uint64_t aWandererH = 0x827E2FDF7983EF63ULL;
    std::uint64_t aWandererI = 0xEBE3D3AE6CA08E3BULL; std::uint64_t aWandererJ = 0x8E97C8ECEFD5DC82ULL; std::uint64_t aWandererK = 0xA8B9A059CD30A559ULL;

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
        aPrevious = 11351943163132900305U;
        aCarry = 11332307061798182842U;
        aWandererA = 11349623524192657251U;
        aWandererB = 17020795984835384826U;
        aWandererC = 9446073888189163225U;
        aWandererD = 15710013226954549136U;
        aWandererE = 17389055511941673925U;
        aWandererF = 10164034436168913362U;
        aWandererG = 9364132105598896726U;
        aWandererH = 11222470974927991592U;
        aWandererI = 9762014090242545595U;
        aWandererJ = 14579462273724783919U;
        aWandererK = 16183753693651681116U;
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
    TwistExpander_Archery_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Archery::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA4F19B38A0516C0AULL; std::uint64_t aIngress = 0x998B4199C6B66C4DULL; std::uint64_t aCarry = 0xA3C7E4F355218EE7ULL;

    std::uint64_t aWandererA = 0xC0F2C7975F4971CFULL; std::uint64_t aWandererB = 0x93CCFBA20166C62FULL; std::uint64_t aWandererC = 0xAF1BEC2E80CBF40BULL; std::uint64_t aWandererD = 0xDC5EC4B992A96B66ULL;
    std::uint64_t aWandererE = 0xF732F6ADC00DDECCULL; std::uint64_t aWandererF = 0xE5E2C5C02ECDBF77ULL; std::uint64_t aWandererG = 0xB0088C60B8CECC62ULL; std::uint64_t aWandererH = 0x806A6E869C5870A0ULL;
    std::uint64_t aWandererI = 0xDFC1042352AE6C99ULL; std::uint64_t aWandererJ = 0xACFA74DB77DD3CD7ULL; std::uint64_t aWandererK = 0xBB8723DDC2A5D686ULL;

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
        aPrevious = 15890492431512841495U;
        aCarry = 11583578051322957089U;
        aWandererA = 18404857943479923619U;
        aWandererB = 11392868860163492292U;
        aWandererC = 14208667142418767079U;
        aWandererD = 12045183716089574780U;
        aWandererE = 18145939904483065600U;
        aWandererF = 11154356382666858071U;
        aWandererG = 16025957025010880021U;
        aWandererH = 15383057834445311930U;
        aWandererI = 16580538762776114920U;
        aWandererJ = 18235985216413923367U;
        aWandererK = 10769559325807577740U;
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
    TwistExpander_Archery_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Archery::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x81DE5AF9259853ADULL;
    std::uint64_t aIngress = 0x82B3A1A5B6343FA4ULL;
    std::uint64_t aCarry = 0x90DE42CF76795982ULL;

    std::uint64_t aWandererA = 0xBD7D26CF66896D3EULL;
    std::uint64_t aWandererB = 0xC53862282F1D0E4DULL;
    std::uint64_t aWandererC = 0xC09AB743799810E2ULL;
    std::uint64_t aWandererD = 0xC31D0D223FF0812AULL;
    std::uint64_t aWandererE = 0xD993467A029F0FE9ULL;
    std::uint64_t aWandererF = 0x99C885CE0754EC43ULL;
    std::uint64_t aWandererG = 0x897420C71ACF9E82ULL;
    std::uint64_t aWandererH = 0xC3D1F525CF609A82ULL;
    std::uint64_t aWandererI = 0xAC32DFFBACC66497ULL;
    std::uint64_t aWandererJ = 0xAF06689620F5A154ULL;
    std::uint64_t aWandererK = 0xBAB9198C50753204ULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::Aria256Counter(aSource, aSnowLaneB);
        TwistSnow::Sha256Counter(aSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneD);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    TwistExpander_Archery_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Archery_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Archery::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD9C9BC8226001FD3ULL; std::uint64_t aIngress = 0xC86DC5F749F982E2ULL; std::uint64_t aCarry = 0xABA80E58D847B052ULL;

    std::uint64_t aWandererA = 0xEC7EB0A2348D174BULL; std::uint64_t aWandererB = 0x98A7BC17A2422EB2ULL; std::uint64_t aWandererC = 0xD8918AD40D244BADULL; std::uint64_t aWandererD = 0x9768416816761F41ULL;
    std::uint64_t aWandererE = 0xAAC5F7253421D1ACULL; std::uint64_t aWandererF = 0x81A404CF5B0B3D94ULL; std::uint64_t aWandererG = 0xBA241673F92564BAULL; std::uint64_t aWandererH = 0xCA75155F71AD8C10ULL;
    std::uint64_t aWandererI = 0x9B5618633E5F0E70ULL; std::uint64_t aWandererJ = 0x95CD91C37E4288AAULL; std::uint64_t aWandererK = 0xED32361FBF19DDCEULL;

    // [seed]
    {
        aPrevious = 13934175407158322358U;
        aCarry = 17420095721741836362U;
        aWandererA = 11899643206384305644U;
        aWandererB = 10396073031140756058U;
        aWandererC = 14670948542916380059U;
        aWandererD = 17614264321804415789U;
        aWandererE = 11782434239852331846U;
        aWandererF = 17738444904798017708U;
        aWandererG = 10294334513174254682U;
        aWandererH = 13426594206162350461U;
        aWandererI = 15606948017370219400U;
        aWandererJ = 11123898356641906762U;
        aWandererK = 18069138689086256956U;
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
    TwistExpander_Archery_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Archery_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Archery_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Archery::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 3, 2, 2 with offsets 2826U, 7819U, 3956U, 6629U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2826U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7819U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3956U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6629U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 1, 1, 3 with offsets 8121U, 7793U, 553U, 7029U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8121U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7793U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 553U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7029U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 0, 3, 0 with offsets 7763U, 5594U, 5191U, 6954U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7763U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5594U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5191U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6954U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 2, 0, 1 with offsets 4602U, 1084U, 7355U, 1200U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4602U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7355U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1200U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 2, 0, 1, 3 with offsets 119U, 347U, 368U, 816U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 119U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 347U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 368U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 816U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 3, 0, 1, 2 with offsets 757U, 1783U, 1102U, 214U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 757U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1783U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1102U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 214U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 1, 3, 2, 0 with offsets 1647U, 1435U, 1223U, 1790U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1647U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1435U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1223U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 3, 0, 1, 2 with offsets 384U, 386U, 64U, 1441U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 384U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 64U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1441U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 1459U, 1950U, 573U, 1704U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1459U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1950U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 573U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1704U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Archery::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 1 with offsets 8032U, 1855U, 1629U, 5277U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8032U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1855U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1629U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5277U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 3 with offsets 4938U, 3756U, 1729U, 6455U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4938U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3756U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1729U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6455U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 2, 0 with offsets 1921U, 3828U, 1341U, 2010U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1921U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1341U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2010U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 1, 2 with offsets 4288U, 429U, 778U, 4858U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 778U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4858U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 2954U, 3189U, 5609U, 6455U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2954U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 3189U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 5609U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 6455U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1335U, 753U, 1167U, 707U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1335U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 753U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1167U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 707U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 1820U, 1303U, 1762U, 1556U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1820U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1303U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1762U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 100U, 1266U, 382U, 952U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 100U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1266U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 382U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 952U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 176U, 1225U, 1521U, 372U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 176U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1225U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1521U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 372U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 1681U, 729U, 1017U, 451U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1681U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 729U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1017U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 451U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Archery::kPhaseASalts = {
    {
        {
            0x6DFD2D3EFE519F74ULL, 0x473EBEDFA140A0CAULL, 0xCA0F390B4D469A22ULL, 0xC3680724A2A0FF46ULL, 
            0x806FBCE1E467B52EULL, 0x0052DABF9DDA410BULL, 0x306F8F6C00A705B8ULL, 0x040A0A7DEDC6B817ULL, 
            0x1CD55E838810B289ULL, 0xB425749327ACBB40ULL, 0xEFE0BA6B4C5138BFULL, 0x1E4AAA605BA45828ULL, 
            0x1AE58A2F7884AD08ULL, 0xFEC359B34CCCC347ULL, 0x57EB5DED4316C3B5ULL, 0xB762190E662B3C77ULL, 
            0x06862DBC63AD3A8BULL, 0x56DABC0C39D69E8DULL, 0x7B15C63B704319B2ULL, 0x14F26BD3FB979335ULL, 
            0x7A2CFEB0E74F1457ULL, 0xED07DC1F7F22F4BEULL, 0xF75C4D2DE262A4A9ULL, 0xB4F90B4E85DB83ACULL, 
            0x77354C72F6DAA8EDULL, 0x2171985A6373E71EULL, 0xDCA5D2DDBA93F5C4ULL, 0x44F6249B5A52683CULL, 
            0xCB9E1D6302E2AF22ULL, 0x9C467049BCF1C90AULL, 0xF56008571D643D03ULL, 0x0F22E55B657CB567ULL
        },
        {
            0x22406C045962F0D0ULL, 0x8D272C0D7680CE0CULL, 0x0E09AB0672029E7EULL, 0x929E9071886AF77BULL, 
            0x2B842BDEE60441D4ULL, 0xD16094814715339EULL, 0xEC6F975FB6C3B339ULL, 0x8D14AC34A66501ABULL, 
            0xD9F9619BAE419165ULL, 0x70364E3D2B24924CULL, 0xED6B2A6429E54A79ULL, 0x93898F24AFC472ADULL, 
            0x644ACCD5889D36D4ULL, 0x1D604BF9D64CEB15ULL, 0x4B400DBDFBDA5768ULL, 0x37B4E0E8F44A5C9CULL, 
            0x193C651145F04D7FULL, 0xA0AEA469A8ACE98BULL, 0x4232077EDF6A4707ULL, 0xB4689843FC0789DDULL, 
            0xDB8CABE926C7EF26ULL, 0xAF81538236AEADC7ULL, 0x2EDEC1A7CE1DB5A3ULL, 0x9579DFB2345D9E46ULL, 
            0x552BE7FFC8C7E79EULL, 0x8603C25096FE20B7ULL, 0x5A2461BB2DE15935ULL, 0x8B97299CEB8AC552ULL, 
            0xB48B191F0A14C312ULL, 0x6E6251E291A61F3BULL, 0xF15C41F7FB4AC048ULL, 0xDB05355F9A0DEE61ULL
        },
        {
            0x53690CFF711BAE99ULL, 0xF3D915C6D0DAD51AULL, 0xC5A5E5FBA8C7D2E4ULL, 0x079EABFBDF8F06BBULL, 
            0x54FB1CCE78D39AD5ULL, 0x478ACA0B8F9BD1D2ULL, 0xB76AE1A278DE74BAULL, 0xB9483F9CA11E10DEULL, 
            0xDDDF057FC26C068DULL, 0x1141A94B15972AF0ULL, 0xB71C6AD333ABB1D4ULL, 0x07133972B64F658AULL, 
            0x212D909FF777A8C5ULL, 0x3A07DCA553F81FBAULL, 0x7058E079FFA5D4D5ULL, 0x75371ADF9D4CE662ULL, 
            0x13178D0A2219AD27ULL, 0x9547F9E0BE7AC0AAULL, 0x4FEA619EAAD0E4F6ULL, 0x7D85F5D07BE8127DULL, 
            0x6B81E5648F3E226AULL, 0xA3C5638DFEF0FB8EULL, 0xE6A538DCA30560F8ULL, 0xBB96B69F732C1AEAULL, 
            0x0F674210FB96C19EULL, 0xAEDB1DC06407ED80ULL, 0xCE9BBAD919335FC6ULL, 0x14F5CF6EEC966D3FULL, 
            0x0E8201F10D5E88F3ULL, 0x989138E1940510DAULL, 0x2DE934B78E1F18E3ULL, 0x00061BF28801E272ULL
        },
        {
            0x036C0FBCF3730F96ULL, 0x05E881D063A1C345ULL, 0x644DF3F3B3696A63ULL, 0x34E381722B87BC7EULL, 
            0x921597C4BBC2F39DULL, 0x63F4D57E7A5D9EC3ULL, 0xE943A10F2E2124C9ULL, 0x9312F6A94CDA634EULL, 
            0xBEDB11065477AB4AULL, 0xE800B334F3F8E5AFULL, 0xB2A8B67FF482246EULL, 0x19585CCB936E83CCULL, 
            0xD46DDA2D76E579D8ULL, 0xDBE9C379581F46A9ULL, 0x181CC4AE73B46AD9ULL, 0x7E07C0F91B02CC71ULL, 
            0xFCB5A158572457FEULL, 0x2737CEA4B1EF9E1BULL, 0x299DBD116440E75EULL, 0x0904765B109A5681ULL, 
            0xA31496DBBE09BBA2ULL, 0x45A9DD8D868F1099ULL, 0x7E0FA59B9AD85454ULL, 0xEB01D7765EECADBDULL, 
            0x02E2F3686D1BB5C6ULL, 0x3D2371AE610B4539ULL, 0x48D8CC641DB9AA6CULL, 0x944402EA91A52E88ULL, 
            0xE15C77DFE266E6BCULL, 0x7195F4E97E479B1DULL, 0x4667E8FEDB654FDCULL, 0xF8AAA5774C45481DULL
        },
        {
            0xE2F6F956CF7C3D01ULL, 0x2B22F76BA062151AULL, 0x157178598B855C66ULL, 0x7C60824FF2C30C14ULL, 
            0x9D07FAC28CAC811DULL, 0xCD0CC1543E595839ULL, 0xAEEB8BF1961576F0ULL, 0xAEC6EA3FCDFCC79EULL, 
            0x626A670CDA857BC7ULL, 0xD46804C271746333ULL, 0x618921951665152FULL, 0x6F31EE7FB3CF7BEBULL, 
            0xF8331406433E66D9ULL, 0x53F5FB8D733E3044ULL, 0xA12FBBBFEB0A8195ULL, 0x2E1C745BCB1C5087ULL, 
            0xB28EC2E27B8E104EULL, 0xBB17E731ABE366A4ULL, 0xCAC31ECD6D2C820EULL, 0xFE8EB5C621439E39ULL, 
            0xD4008D16F5D89F5AULL, 0x36418FBDFA2ACBF2ULL, 0x0E4A1A81248C8E71ULL, 0xDADF7BB3653D49B5ULL, 
            0xEB24D17F118D8DD4ULL, 0x5EA6D2BF9698D201ULL, 0xE735A44D62132D98ULL, 0x6EB3F8A3497AA02CULL, 
            0xC79AD4B1E099EF79ULL, 0x76B967C7829961EBULL, 0x2477F0B3ECDCB46BULL, 0x84396AE82B6E9E0FULL
        },
        {
            0x2679EBCA80D78545ULL, 0xB525C2F034799158ULL, 0x9866D9D38EB63DAEULL, 0x148FC97FAE561AB4ULL, 
            0x21CFB522192A1047ULL, 0x73097C73698CB17AULL, 0xF255B837CE42D664ULL, 0xBA9F1A18C83FF4BFULL, 
            0xE63C6268C3C7DAFEULL, 0x47ACC65814FD8BC7ULL, 0x50C1CD09A7ACFF0AULL, 0xA331B9AE25974AE9ULL, 
            0x44EB552CAACE30BCULL, 0x52E65C739CE99465ULL, 0xBBC1022BB02F6E24ULL, 0x201C8990E9C02A5BULL, 
            0x61F0BA966AC5BC7DULL, 0x4C5FBCFF2788E1FAULL, 0x0C3122477E9C3D9CULL, 0x4B07B8F279B6203CULL, 
            0x495A021D3B76D2DDULL, 0x97D0F397313BF4B3ULL, 0x0016B362B7081C57ULL, 0x5EC52E3CAF0123C6ULL, 
            0xF3265A2A32AD0F9DULL, 0xBA6331570C81F591ULL, 0x05D8FA9A24C7C061ULL, 0x77A33E7602285717ULL, 
            0xB2ED9D131AD873E5ULL, 0xFF15423CF7BDBC14ULL, 0xEAB5B84F9458F62AULL, 0x6EF6C5B32499ED8CULL
        }
    },
    {
        {
            0x80BA1B699ED6F13AULL, 0xE3F165E2551FB7B3ULL, 0x8D35BBB362639D94ULL, 0xEA5C8FA597CE4B95ULL, 
            0x8AB6F63486662099ULL, 0xD5699BD126592CE8ULL, 0x9BF4AA3CB136BB47ULL, 0x279790F2E3BAA600ULL, 
            0xA730E1DB161479DDULL, 0x3118B4F497305F8CULL, 0xB3E98B885E890703ULL, 0x6B846F8C1104896BULL, 
            0x62D0662D775E2842ULL, 0x0A5A2D1C20A49650ULL, 0x12639A174004FC55ULL, 0x0906C0BF3CBFAD61ULL, 
            0x6868D96549C9C05BULL, 0xB07D464C35992976ULL, 0xD4C9773EF9C2814CULL, 0x9D0E191F9F520129ULL, 
            0x88E8DAD58830B9CEULL, 0x1FFC7EB71E822BEEULL, 0xEE493B502B54BEC3ULL, 0x7BBE0285969D31C7ULL, 
            0x1CC5675AECA271C3ULL, 0xA6AE9F28DE1B328BULL, 0x31217BD0D3CAD644ULL, 0x50B4CAB0C4A014D7ULL, 
            0xDE4988A70AB25FA0ULL, 0x3F1C7499FAC9E9F2ULL, 0xE30769274F995716ULL, 0x4E9C173944DFF996ULL
        },
        {
            0xEA9C041EC5AAE62AULL, 0x87E6DA55FE6BBD0BULL, 0x51E32916E3155148ULL, 0x9A845EE8005AB8FDULL, 
            0xE039A877E89681ADULL, 0x858E11DF5BE021F9ULL, 0x18A09606C483A2EDULL, 0xEFA3E903C25E4DD3ULL, 
            0xA409AEFBF71FCDCAULL, 0xE344A8A69426B9B3ULL, 0xCAF3AD39C1654D30ULL, 0x62855E2018C229EAULL, 
            0xFEDF67EE26822375ULL, 0x5B63AF393D63750AULL, 0xED4CB482DE764212ULL, 0x056651142805C364ULL, 
            0xAF0431D2837C7C49ULL, 0xBA5B89F6381D6C45ULL, 0x35A4B12BED6E6EACULL, 0xC7678BC5E2A3D0FCULL, 
            0x6A85B6A008260DBFULL, 0x9110D995008CD465ULL, 0xCAC03FB99D1629B5ULL, 0xDCA44B1BD6D9EF08ULL, 
            0xC4797F5E1768AACDULL, 0x339E91D2332EE24BULL, 0xD47D2F165892FD43ULL, 0x429EB9473993D97DULL, 
            0xDA4756F947F9B4DBULL, 0x824672D92972073BULL, 0x210E5D23481770ABULL, 0x85EEE5FFA2AB9907ULL
        },
        {
            0xD62A6E3D6B9C13BDULL, 0x7F4001BED18E92A9ULL, 0xFB9A6D5009E36CC9ULL, 0xCBE2D53E160689CDULL, 
            0x146AA4B36BB0BC20ULL, 0x490C59C8BA0AE8C6ULL, 0xB4DA7FBEF0081279ULL, 0x16C9C6C56D332D5FULL, 
            0xC96731DE00BB19ABULL, 0xC6C76461E1B8E04CULL, 0xEF0A7FC9681DC727ULL, 0xF43AC859B35A7547ULL, 
            0x4800BAB98EC431A5ULL, 0xA8330F727C7514A0ULL, 0xD935D1C89EEA81BDULL, 0x3E31AACA046C132BULL, 
            0x7B93A44DF0AEDD40ULL, 0x7DA8BA33C576ECFCULL, 0x9BCE40685113B5FAULL, 0xBEB1548183CF244CULL, 
            0xB57D89816108B0FEULL, 0x6D808F9C2F4911B5ULL, 0x95D36AA2123DA08BULL, 0xB77CD51A41166E81ULL, 
            0x60480C391FA41DD4ULL, 0x5DC4A4E344E47D53ULL, 0xF80057FFDFB4C505ULL, 0x50918A6BE78FB5C8ULL, 
            0x5D38F9B5DC659F7EULL, 0xEB4B5A0E206E87A8ULL, 0x3349CEBB0AB0F4FCULL, 0x0762968A2F944891ULL
        },
        {
            0xD9C73E12DC32A5CAULL, 0xCD18B77C90D01447ULL, 0xC6D74796E08EB1A6ULL, 0x5CB2284BBFE0FF8EULL, 
            0xE3D6948D243AD6C4ULL, 0x66680FB85296C853ULL, 0x654CB1F2C8356BC7ULL, 0x35C6A21009C6AC56ULL, 
            0x59ED55CA85486BB0ULL, 0x7773C978F7F556FAULL, 0xF4DDDFB59E251C4BULL, 0x2FB3D4BCCF158E74ULL, 
            0x72B1148225CAFA2FULL, 0xE05DF63922F6AF3DULL, 0xD82CC7EAA6B64C8FULL, 0xFAE2353FC0C983DBULL, 
            0x5160D1AD9AEF057DULL, 0xEFEE06B08D8D875EULL, 0xB411BE265C2FDCC3ULL, 0xCD7D0F58D761CC97ULL, 
            0x9224046E3547F02EULL, 0xAAF659381E91F374ULL, 0x74982FB8452F3CDAULL, 0xB6E7B425DD45BFF9ULL, 
            0x8C5B03E893D7E9CFULL, 0x0092425079FBCDE7ULL, 0xBF71A02EB66859E8ULL, 0xFFB858F4712E2E1AULL, 
            0xB2C9883E50BE2155ULL, 0x45024BB1E155132FULL, 0x9B6EA1DFE25DC90FULL, 0x693EAE3AA3ED4448ULL
        },
        {
            0xC94BDE84E7FF7B78ULL, 0xFC21712DC90240B8ULL, 0x75D2017C6BD3F5EBULL, 0xAB66673DEA0451EEULL, 
            0xB7791A81FFB48585ULL, 0x14C90F0DAD1C3C02ULL, 0x49BBB962522FB6DEULL, 0xE51FD9ED628BDE07ULL, 
            0x942B6F3DC2849339ULL, 0xC03FA88109434887ULL, 0xE5CD6760712BF66AULL, 0x6F61503C6139CD34ULL, 
            0x47F527E629B3C108ULL, 0xF072DC4B117E9677ULL, 0x001039CF6E17E486ULL, 0x782219873B66851AULL, 
            0xD5DF4CD3C6E0634BULL, 0xFDC03FE1CE358985ULL, 0x553F06DE13D65CB4ULL, 0xCD92D80875BEA2B0ULL, 
            0x4F44ED83E895CBF8ULL, 0xF7089C459D01B753ULL, 0x5D22E361136EF27EULL, 0x3F63F637B71D0652ULL, 
            0x2C75EE9CC44BA732ULL, 0x6DF94EE44006B5EEULL, 0x3FDAA958571978C3ULL, 0x18D374247C0283A2ULL, 
            0xACF33F359DBAA74AULL, 0x456D04AEE8ED9F15ULL, 0xA3077838D8997367ULL, 0x51D7962AB8A30EE5ULL
        },
        {
            0x811E76121786B2B9ULL, 0xB51470A3043DBAC8ULL, 0xDD378A353E6D8161ULL, 0x2401EF73C0CF7984ULL, 
            0x4C02400C0B575AAAULL, 0xFA5DBE680B3FA97AULL, 0x76023D5CF78BD331ULL, 0x51D3C529C561DAD9ULL, 
            0x9FCD7EF74E095EC8ULL, 0xF9D44C871137B11BULL, 0x26DD86EDB3A98B44ULL, 0xEC186433C82D20D6ULL, 
            0xC1F2F559569C9776ULL, 0x729124CDD5AC1791ULL, 0x986F6A539784378EULL, 0xE26BE1A12B529315ULL, 
            0x60890CF4E01EC7A0ULL, 0xE67064AFCAD09726ULL, 0x995E917C2FC8B93EULL, 0xAF1FC9C51A27E175ULL, 
            0xCEC7D18862BC9875ULL, 0x7EF3A57D385CF132ULL, 0x8145CAF922534520ULL, 0x6784D04C2F7D0E62ULL, 
            0x689912750BDDE886ULL, 0xCDAB56799B2CBAD1ULL, 0x5426319B57186115ULL, 0x66098B01A9C2C953ULL, 
            0x4B760EA27454EDF6ULL, 0x07FCBD27382276FCULL, 0x80C54481B8FDEF38ULL, 0x426EB7BBBAC7FA75ULL
        }
    },
    {
        {
            0x59E621EBEE92AF33ULL, 0xE16450246D04A418ULL, 0xE20737F34A573912ULL, 0x738405E4F4AC283EULL, 
            0x5B7A421A2E8D4549ULL, 0x14D66288DD11FC1FULL, 0x3D1DB73B6EBE0355ULL, 0x6756E121D064FEFDULL, 
            0x8818AAD363C7A900ULL, 0xFAE4FC72C27F703BULL, 0x456D02DBF7C08F9AULL, 0x9C936D1C95DB0BEDULL, 
            0x70604792B8727891ULL, 0x8B995E5E103CA7F0ULL, 0xFF1D3DFF342A18F4ULL, 0x98497D9D3E296305ULL, 
            0x325BCC28EAFD55BEULL, 0x8AF456EE10C107C3ULL, 0x1AB7ACB7A6400112ULL, 0x82246E416FF031A2ULL, 
            0xB037D9F54C03A90FULL, 0x353ADD427FFE546AULL, 0x38DD7C0CDC8463C5ULL, 0xF88371701C331D31ULL, 
            0x6C0C680D58562B70ULL, 0x8264B1AF77995CF4ULL, 0xE853946FBE54E6CDULL, 0xB041BF2802AC4F53ULL, 
            0xD63A8C0B79B7E5D5ULL, 0x714121F983490623ULL, 0x41E8FC6640A7306EULL, 0x7C7F908821A47891ULL
        },
        {
            0xA48FAE56A2A35B7DULL, 0x2DFE870285CE1DB7ULL, 0xECB70263B9BE46FAULL, 0x3E31512CC5C665EEULL, 
            0x990F3CD58981B3ABULL, 0xB32BA614962BECBFULL, 0x39DFA09C510E1269ULL, 0xC83258B1156219F0ULL, 
            0x598BF459C93F38EAULL, 0x87931DCA9FB02F02ULL, 0xA8CF6A00ABB59DB5ULL, 0x068739BDB7425AC4ULL, 
            0x44BC7EA5F39A7FF4ULL, 0x6D7B56A6571598C0ULL, 0x32C7325EEB157384ULL, 0x475CEC125CD1719CULL, 
            0xDF363D7F1197D083ULL, 0x0DF357029300F6A5ULL, 0x5A327E2A0863B4AFULL, 0x273BDCD9A4C58E24ULL, 
            0x6C94A83B629003C6ULL, 0xA326BC765DB044C0ULL, 0xD34211E3308063BAULL, 0xBB219630BDA3F0F1ULL, 
            0xF91209C86CE0F847ULL, 0xEDC1B6BAE3654D94ULL, 0x59E5505C31ABFD4BULL, 0xB18B606CCD85C868ULL, 
            0x31F2D929482E225EULL, 0x2BA64C1A6F3F211FULL, 0xB1645E68BCA71007ULL, 0x0835974CC2EB8773ULL
        },
        {
            0x60B5A7DC077B4D75ULL, 0x08B9DFFBF33BF663ULL, 0x4FDE2B155F847FE2ULL, 0xB08128615CC2444FULL, 
            0x48E867B0A0985FF8ULL, 0x8AE937C3D870CC1CULL, 0xA4F978393380E758ULL, 0x60422BC7502AC51DULL, 
            0x29D5DA1825564B59ULL, 0x5B8E978A31C6C9B7ULL, 0xC80F7DE6224A27D3ULL, 0xFE69291F20928412ULL, 
            0x77BCCA991E7E878CULL, 0xCBFFDF8B0808D2B9ULL, 0xB0983AB5000B531BULL, 0x717AC23D0DA172AAULL, 
            0xF6D07E201AB13636ULL, 0x12FDC95600CBA9DAULL, 0x65CBE83ECFDBC005ULL, 0x05D2041D4A3DB362ULL, 
            0xA9FD5B32723517C5ULL, 0x1AE451B04645695AULL, 0x29DB1D7E8188A068ULL, 0xF44BB310D8B55122ULL, 
            0xE126F0BCEF57CCA2ULL, 0x0EE49C074DEAD280ULL, 0x6F4370816B0BBD30ULL, 0xC372327A34BCBE74ULL, 
            0xA1587287980B9BC6ULL, 0x141F0C4BD068984CULL, 0x517D2A2A3875A36DULL, 0x767B0955B50514AAULL
        },
        {
            0xF888525521B1658CULL, 0x80DA383DAB4C7C22ULL, 0xA7D2FC700F4F3BA2ULL, 0xA94677AD43517507ULL, 
            0xA5747F291893133DULL, 0x1245BB6DE42100C6ULL, 0xA4B4027B43368F04ULL, 0x3F28151EA18B3B9DULL, 
            0xC40440BF9E3D7D94ULL, 0xF5AEA36EE6C88E6EULL, 0xA5CE05F3BACBA0ACULL, 0x31203FD8F58B05BFULL, 
            0xD7F01DCFDF04277BULL, 0x657FAED4D1A8B11BULL, 0x39BC82EBD9A886BCULL, 0x30EA1D4398C38E29ULL, 
            0x7FA6AC68430A6CC3ULL, 0xDE72A67A3F8A0D10ULL, 0xC7E8A50757287361ULL, 0xD6FC8131178EB606ULL, 
            0x7FB455F5C687DC5BULL, 0x4F8C4EB1BCFF6956ULL, 0xF63E96ACADC9C741ULL, 0x28852A49F300574EULL, 
            0x6219914D1ACE5963ULL, 0x7D6922734BCB4C35ULL, 0x440E399149C539F4ULL, 0xFB56739DFBFEA1AAULL, 
            0xD34B7CA523819B38ULL, 0x8285C3D2DD46812FULL, 0xE8E420875084EB5DULL, 0x2507D4D449C06153ULL
        },
        {
            0xBCF0E10E0F93F98CULL, 0x59CB00AA34CAC622ULL, 0x43A0F4D24B607627ULL, 0x2955A0CFAC53402FULL, 
            0xBC0770B33EB2F3CCULL, 0x7FEBE7861C769E5DULL, 0x204B17C4BFB2C50EULL, 0x51522D066767EB15ULL, 
            0x0B898F4E8F1B652EULL, 0x52D5EEA9A17293F4ULL, 0x6B4677EC633699C7ULL, 0x3DC0EC38FBF8B295ULL, 
            0xBD61EF59054C0D7DULL, 0x2C69BCDA40541402ULL, 0x8FC60E995D72930DULL, 0xE1D29E63CDEDE08CULL, 
            0x47933C1F73AA0EEAULL, 0x965A5E4372EE36A1ULL, 0x776386F303BCAF40ULL, 0x03CF0789388599E7ULL, 
            0xF90D050B9F642B82ULL, 0x1CFA3C8D30B9715BULL, 0x2003EF04057FA6EDULL, 0xCD2DBE06EC421396ULL, 
            0xAC484F455498F0E6ULL, 0x91C74668CC20E248ULL, 0xA96A4DA9601D5779ULL, 0xB510E79837B90724ULL, 
            0xD0C9456EC64B8F89ULL, 0xAE28B1447FD1CB64ULL, 0xA19197816360D16EULL, 0xE14C0909FED0EE8EULL
        },
        {
            0x9C61858A50FC4788ULL, 0x791F91712BAD52CAULL, 0x4A3879331A7F3581ULL, 0x0BCA32246B8E6C81ULL, 
            0x0E98B361AC5FF040ULL, 0x8944D03393C107A9ULL, 0x975862CAE9FFB41FULL, 0xF32D52ABAEA8E6DEULL, 
            0xA714EBB249E1E38EULL, 0xE2EDCE309843E370ULL, 0x06FD68456524F543ULL, 0xDFA6016AB2C4ECD8ULL, 
            0xE5DF041F068C85ACULL, 0x95D01339307D7D5DULL, 0x132EFFBC91D0168BULL, 0xB332E99F256E379CULL, 
            0x6708718522E32C5EULL, 0xFB07702BC3A03423ULL, 0x97B6F60343216F61ULL, 0x58B54D57DA9A0FCBULL, 
            0xE1E589D222725464ULL, 0x338BFF7859CAA77FULL, 0xA2DB458CE298AF0DULL, 0x214F184FB98E3F38ULL, 
            0x871820EF64F17BD6ULL, 0x8F4A30A1CA823D1AULL, 0x510A175BE42676A3ULL, 0x720A64100C7E66ECULL, 
            0xD0DB779564C220EDULL, 0xBBFD48B42289789AULL, 0xD6F9213BA9379858ULL, 0xE59D01CF19F3E423ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseAConstants = {
    0x1DE089129D685C43ULL,
    0xD4A9405D98DB7210ULL,
    0x342397C7F54615D6ULL,
    0x1DE089129D685C43ULL,
    0xD4A9405D98DB7210ULL,
    0x342397C7F54615D6ULL,
    0xA5960C7145339112ULL,
    0x535B0049F3B3589FULL,
    0xA2,
    0x83,
    0x73,
    0x16,
    0x17,
    0x9B,
    0x31,
    0x12
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseBSalts = {
    {
        {
            0x6919D252F6EE6EECULL, 0x60D713C859CE671DULL, 0x98CBD9B91634806CULL, 0xB94EEC9F9172839AULL, 
            0x99F7520D653B7A37ULL, 0xCB5759375E5C656BULL, 0x8DE7AB8D6B7770A2ULL, 0x1EEE7D9AA291EC52ULL, 
            0x6EA6F04ED26FAA7AULL, 0x529AC452E8C6963CULL, 0x38E413FEEEB5DD2CULL, 0x3B48CEF19B42E16CULL, 
            0x8E3DC7036E0EECF6ULL, 0xB2FE3E674C7A1DE6ULL, 0x0E4633BB4652E4D7ULL, 0x03896154D87BFD41ULL, 
            0x91DA33F64324F383ULL, 0x3609F2E1D44466AEULL, 0xFE14B3F8F09C12C3ULL, 0xCE1B60D88DF71FF9ULL, 
            0x17685FE9707EE088ULL, 0x37971DD9CB8C0715ULL, 0x2BD2D393837C626EULL, 0x4CB7CF208CB88C69ULL, 
            0x0FE3D533D4D584E1ULL, 0x4120DE64D21323B6ULL, 0x261865756B87ADDFULL, 0x43CDB3525FA14535ULL, 
            0x70C457FD6E0C0B2AULL, 0xDF2638D1479FEBB3ULL, 0xBCBC75C67CF3F3FEULL, 0xC65E8AA6CFBB642CULL
        },
        {
            0x550EFA354F3FE7D5ULL, 0xAD43E1BF8F31A8C9ULL, 0x921B1E32EE38BFB0ULL, 0x76EFD16DFBE58759ULL, 
            0xAA880FC6E2B2FB74ULL, 0x5C7EAA614065F360ULL, 0x6C00469BEE822F88ULL, 0x1A8CD60209923777ULL, 
            0x3D177ECC8171B907ULL, 0x4C9F5A43F336603EULL, 0x282E8C4FA6654AF5ULL, 0xC88A84B0F05BC32BULL, 
            0xA837E491B2A66691ULL, 0x3595EE54B3786CC9ULL, 0x29EEEE862242A0D7ULL, 0xCB6BE946C597EA82ULL, 
            0xF15443BD52A7E8C9ULL, 0xF340EA3728720D2BULL, 0x1C3EC7637C292212ULL, 0x9A4A52814F335D5CULL, 
            0x0BAE3B6C17B657CCULL, 0x5061D14EB2406DD5ULL, 0x302DC76E7E3CE518ULL, 0xA4EB0892DCBBFB61ULL, 
            0x0B78C03D7E16AD62ULL, 0x4AAE758A1E65092BULL, 0x972DE04E57B84D2AULL, 0x73521F7752662F47ULL, 
            0xF6A630FF78EF29AAULL, 0x6C1D115646F5C486ULL, 0xD6CB8D4B210F9182ULL, 0xFC44434142304F1BULL
        },
        {
            0x0F21DA93E8514FABULL, 0xC58E97719AF28EEFULL, 0x996EA28A0160D336ULL, 0x94780F58CA5D5201ULL, 
            0x19F6D8BC97C5DF60ULL, 0x6C67D40087E5D5ADULL, 0x380708980BC18E08ULL, 0x7F0F7CCEF353FF45ULL, 
            0x377AFDA86C91EB9DULL, 0xF7535703D4716B2EULL, 0xB4B061B973FEDB8CULL, 0x1535F27767A013D1ULL, 
            0x80010A27AA00C57BULL, 0x5A58EBC9F860031CULL, 0xE7763DE99CCC9626ULL, 0x8DB982FC1C9BD7AAULL, 
            0x5D838A4C16AC21E6ULL, 0xFE21417D866F1065ULL, 0x9C55D98D8F02F701ULL, 0x3D9F62D28991A803ULL, 
            0x4335441C79990E88ULL, 0xA6C23A47D656B480ULL, 0x6C4F026C3043F24CULL, 0x9F81DF62BFD942FCULL, 
            0x10BA16E3DE7815CFULL, 0x40F649DB7ADF5F28ULL, 0xB50BE77B46F01BDFULL, 0x7700DD19A09D6980ULL, 
            0x9FF5BEF728629860ULL, 0x9935F6D210F491FAULL, 0x34F2DCE0FEAF4364ULL, 0xE1C0CB6690C3A147ULL
        },
        {
            0xD08038D674EF710CULL, 0x420ADFBDEB57FBCEULL, 0xD4318A1A6520FD66ULL, 0x957073B931E6D713ULL, 
            0x4B86261369278D1CULL, 0x5DB19E5D32F72C45ULL, 0xBAD2747623F9ECCBULL, 0x5F149FD803DCD612ULL, 
            0x2AC8797DDA7AB7E7ULL, 0xF21BD369F9167C81ULL, 0x8567555E576A97B5ULL, 0xEAE2E4B3E568B440ULL, 
            0x9C7A73567E8E8773ULL, 0x6691CA45C79BD6B2ULL, 0xF863FBE8B86CC1C3ULL, 0xBD21A9F39B58F203ULL, 
            0x39A890D3B7168F59ULL, 0x99200B1C2C733BE9ULL, 0x802CEC1857CE00A4ULL, 0x4BEFAD91A1A1EC69ULL, 
            0xF32BE27B7CAA6EDAULL, 0xAE051974A479E823ULL, 0xDFFFB485C27CC010ULL, 0x68DEC20DB1FCDA80ULL, 
            0xF3CCFFE827CDC0CAULL, 0x42CE142A1F665B92ULL, 0xA479C0FB64156207ULL, 0x03763C8A349B5E68ULL, 
            0x92CE97875F3C73D6ULL, 0x282ACE49DFDC2C7DULL, 0x8DA831AC6371C9A0ULL, 0xAF31B1101E4EBD85ULL
        },
        {
            0x64B2325C64D49BF8ULL, 0xDE2CD1A7F7F3610FULL, 0x1C18C8F560F013B0ULL, 0xB092A21639B2AD8BULL, 
            0x5607CB361D7C20CFULL, 0x10B9D4663C54A712ULL, 0xA44BA3E3DD70B91FULL, 0xD823A79851F35349ULL, 
            0x0B88E0D7F0CE5D12ULL, 0x7852F1BB1B06F93DULL, 0x22DEF80835E3CDABULL, 0x42D2A319618F3D37ULL, 
            0xBA672D33D2E9A143ULL, 0x1305D865714E350CULL, 0x5190D79BD2BE74AFULL, 0xD915501F41919F96ULL, 
            0x64650859E3EEF8CBULL, 0x29DE1C5A654D8FC4ULL, 0x312BD46EFF44A204ULL, 0x842A4602B70C8A14ULL, 
            0x02A3A1AC48926E6DULL, 0x2AA96C6B54E92948ULL, 0x2F51F7BB795D2732ULL, 0x6DB04B848BC50A63ULL, 
            0x35D7A653F007859EULL, 0xB00FC25191F4D97CULL, 0xEE11AF4B56891D0BULL, 0x10CFBEF6AFA386CFULL, 
            0xE3C98F427DE74E58ULL, 0x329CE9B0DE76FEDBULL, 0xD5059673FACA7BCDULL, 0x74851A1A10F4C6DBULL
        },
        {
            0xCA52992BED1AFCD5ULL, 0x2001DCAE8E34EDDDULL, 0xEFDEC676847C7BB4ULL, 0x1530BC4BA3C194D6ULL, 
            0xDC6F4FC342CEAC73ULL, 0xA5485F81079EF18EULL, 0x457124C8040D4722ULL, 0x5AC8952CCCD6DA7AULL, 
            0x9D49B5ACBAAF3C66ULL, 0xE127A8499E8214C6ULL, 0xD9CD5BA97F35F5DBULL, 0xA8D822FD79895505ULL, 
            0xB12E2E57B4044A86ULL, 0xC155739C06EFAA08ULL, 0xF5D80795F89571A2ULL, 0x8414B685CA8C0829ULL, 
            0xB56CFE922E9CAC17ULL, 0xB54EE45576C368FAULL, 0x6B49062E7BB13021ULL, 0x0A1B075FEC4D6C79ULL, 
            0xB258B5602742EE25ULL, 0x91535F224940B5CFULL, 0x1373FA996FE39414ULL, 0x6E8B7A53ABE0C599ULL, 
            0x0117F70E5F967BEFULL, 0x781C9B1430B5C3F1ULL, 0x85639860A76558AFULL, 0x6C32F7C1C7960277ULL, 
            0xAF8F6CBBE021A5ECULL, 0xFBB2AABF43C6EA82ULL, 0x924E4C92FF723E50ULL, 0x074FAC5834FC9089ULL
        }
    },
    {
        {
            0x62195BAF0C9B18F2ULL, 0x3D14D149F980B2CDULL, 0x32BEB7A35C3BC4B0ULL, 0x682F1C8307FED75AULL, 
            0x52AEB2147774B85DULL, 0x3177FFF177CB3AA0ULL, 0x08D3044F7091B925ULL, 0xDE712A8AC7A5193BULL, 
            0xBD7CEF7591AE2DFBULL, 0xE754545145E7A3D3ULL, 0x4FCC1A01CD9A4362ULL, 0x65922BD7DE7232ADULL, 
            0x65CB32AEBE260994ULL, 0xF12DE4F8EBBDF0FDULL, 0x1B382D1B8870B308ULL, 0x99B2FE59C57E13ECULL, 
            0xDEA6E47112A09C78ULL, 0x4334E9510A57E695ULL, 0x90EB793460C40C76ULL, 0xDC169AC1E01EA46DULL, 
            0x396F892D1C3C2402ULL, 0xD06A5BD657B3FFB5ULL, 0x5674827584DC8062ULL, 0x93D72E8DE0A99375ULL, 
            0xBC064DF2E5F94B70ULL, 0x0C2BBB7ED8298789ULL, 0x9C9AB5DC63D79E75ULL, 0x94AA1DD4F08743AEULL, 
            0xC0447CA81B1D823EULL, 0xE34D8E22337390F8ULL, 0xD8D4DB903B871450ULL, 0x56D483965A3D73E3ULL
        },
        {
            0x2E23DA45A22804E6ULL, 0xEA1B342FFD128920ULL, 0xA9725D0475F61EB9ULL, 0x386D69C83931B516ULL, 
            0xD77845AB8D16CBF6ULL, 0x95213399C2738D3DULL, 0x2673D085A8351952ULL, 0xAF3A8CA04936046DULL, 
            0x6AE5B1B2C27BA05FULL, 0xC06070B14FD83049ULL, 0xCE08B61CA8B5065AULL, 0x029023D0020DC3B3ULL, 
            0xDD86F2F494B7B92FULL, 0x3BE3879743DCD985ULL, 0x609C73B5431BAF0AULL, 0xD02E9D8AA6E7C319ULL, 
            0xEC5ACBF5244BD142ULL, 0xFE38623A4B9BBD5EULL, 0xC705A54E859179AEULL, 0xED2E79127AD5DF76ULL, 
            0x1C76C08C92D960CAULL, 0x50F418EE94A380D4ULL, 0x79936F8443AE13FCULL, 0xFCE8ECCA2C666638ULL, 
            0xB5A723D2BA2707A0ULL, 0x9BC718A9E1FA1295ULL, 0x9BB0CAEA7F03C586ULL, 0xA65A262C36138D59ULL, 
            0x91D72E1F656DCB6CULL, 0x6DE7950719DFBD04ULL, 0xD1A1A197F5D19DBEULL, 0xE4680DF676AB7807ULL
        },
        {
            0x28AE010664DDC5F9ULL, 0x0FE34253F31E7EF9ULL, 0x4CE04CC4A0FB4BF1ULL, 0x44C71E8827FF7E47ULL, 
            0xAE0200241CA30749ULL, 0x6EE5A9EF0CEDCD27ULL, 0x302CFED58F71224CULL, 0x78B1E27C968BCB93ULL, 
            0x2FB9BBD198A92FAAULL, 0x6CB55F034D75F6B7ULL, 0xA8E73D6151AA0DAAULL, 0x2FC2B5340F323B32ULL, 
            0x9C078327D7E6AD3CULL, 0x9C4CB96231B70762ULL, 0xE8180B701D835887ULL, 0x4141F3EA0F71F27CULL, 
            0x8378E12AC4C82C22ULL, 0x9D9683DC27702033ULL, 0xD4250D97D553579EULL, 0xF25E0DF597887BECULL, 
            0x866AC49214459D27ULL, 0x999D7257B865B970ULL, 0x454B71B0CB6FA92DULL, 0x0EAC70B40FDDCDA8ULL, 
            0x0D7E2BF1D1121BD9ULL, 0x7D46858315313E20ULL, 0x000884DC6ADE4C6EULL, 0xE73683C363E6E579ULL, 
            0x90B7211AD5CFF485ULL, 0xAD8143C777F2297EULL, 0xFE1057D3D7BFF340ULL, 0xF2AC295F981EDBA9ULL
        },
        {
            0xADC07F52D35644EEULL, 0x059D0AB4D85C2F5BULL, 0x57C4E3760D82512DULL, 0x1DD24389BEC4A338ULL, 
            0x11468284AFAB9064ULL, 0x10EDF4BCC71DCB4AULL, 0x7DF9C86746D34C17ULL, 0x9AA098F649D53CA6ULL, 
            0xE2FB45F083DA42D9ULL, 0xCFBE0CA15F77BED1ULL, 0x422CD1FDD0A30D74ULL, 0xAFDC7D4240672708ULL, 
            0x7200EB4ECA443576ULL, 0xB48575FB8F7A9034ULL, 0x172E6F936D4A6857ULL, 0xF677D5F967B97807ULL, 
            0x2DCD87A7EE193474ULL, 0xBA53A1C050C56546ULL, 0x6FFFC5DC29457D5CULL, 0x98FB213B358C1E3FULL, 
            0x2A263C23B9614F37ULL, 0x0E55F524C0DFF423ULL, 0x006E5E01AFCEB5E1ULL, 0x5516F30AD69BA3F9ULL, 
            0x18895D89F915C5DAULL, 0x9688B1C1A3B733A5ULL, 0xC7F6AA453B1C1E0EULL, 0xBBC1D37BFED7C640ULL, 
            0x154FE0B1FF866835ULL, 0x3CF2DEC80F2ADC2BULL, 0x03193A760FDD6EE0ULL, 0x4E5C15B7828F6457ULL
        },
        {
            0xCB59B96A418A5F3DULL, 0x2BECAA16B4853095ULL, 0x7F7868937B1083BBULL, 0x87D58746576F01ADULL, 
            0xD022DF006A107731ULL, 0xC4F49F76C5090122ULL, 0x792CBF7562B80DECULL, 0x6DDD4E8D2B7382C3ULL, 
            0xE8D00A18DDE3D771ULL, 0xA2649ED47AA20466ULL, 0x9BB0AD81B3D036EBULL, 0x4E2B47596AC0C594ULL, 
            0xB44E9562A464F8F1ULL, 0xEBB5769791F9ABFBULL, 0x16B4D09C9AFBDE8DULL, 0x2C4915330DEB0165ULL, 
            0x3FA07849B9FAAED4ULL, 0xC1A073A38B449CD1ULL, 0x78B8E0BECFEFA08AULL, 0x91F8D36AF778C9C4ULL, 
            0xD494125DF7A1D503ULL, 0xBB87AE038AE862F4ULL, 0xA168B7AEAC1A1C0AULL, 0x14CB036F8482147BULL, 
            0x0095018A40945FA5ULL, 0x13042AA3CF0EBE89ULL, 0x5675BCF40C7C49C4ULL, 0x4E0FFB8BE87923AEULL, 
            0xF6B321D9967759B0ULL, 0xAC648D2868178AC8ULL, 0x17589F2C9E72FC5FULL, 0xC6452A9A0247782CULL
        },
        {
            0xED68FBEF6295F53FULL, 0x8B8286493F5AD208ULL, 0xACDED2F4FDE90E2EULL, 0xCA054C10E8E6DA3CULL, 
            0x02199B60C8551CB3ULL, 0xBE2FDE6806709009ULL, 0xEB4F1CCDC7C19E5BULL, 0x457EE389EF8B168CULL, 
            0x7F89F06B8970C795ULL, 0x8ABC141C3097420EULL, 0x19FD96F3DBF698D6ULL, 0xEDE1AE0DA7FFA072ULL, 
            0x4B8A4603A6C7D306ULL, 0x897D54108397A159ULL, 0xF6864E743E108D59ULL, 0xD3EDA677272FB4A1ULL, 
            0x0A744DC18091056DULL, 0x7754BADBC6E4D677ULL, 0xB19B170ACE1A6169ULL, 0xBB0724C146BEC01DULL, 
            0x596334167A9777C7ULL, 0x2114AFA43627B2B2ULL, 0xCC19871238B25E67ULL, 0xF4FC8199552C3237ULL, 
            0x5A6D2731FC6A3B3FULL, 0xA1A71116A40DD757ULL, 0xD1170F91E66BCF83ULL, 0x4A69B0AB1DC38498ULL, 
            0x10849B3A5AC64A80ULL, 0x7712BC0EA720D983ULL, 0x289AD64B7BA7E6A0ULL, 0x6FCFB1875E6FC5D9ULL
        }
    },
    {
        {
            0x316DDFAB8DC2A6DCULL, 0x4731633562639304ULL, 0x555005CDE0FE7EBAULL, 0x345F8C3A1F928A8CULL, 
            0x3F0E7B7BCCA0E91BULL, 0x268A5AE00A436EA9ULL, 0xA6958B26E0FFD792ULL, 0x05D6DADC48DEC458ULL, 
            0x5CEFAF8D52105516ULL, 0xB46CF5CB74AFD0DEULL, 0x038058EECA97B3BCULL, 0x9542221DA1F714C9ULL, 
            0xA71DB1A5ACCD25AFULL, 0xE1AB2B9DA1C4BE35ULL, 0x8AD2137F7C15AE10ULL, 0xCB9031A29121E416ULL, 
            0xA4FA748CE2A8DC99ULL, 0x6D7ACDC01238F3D5ULL, 0x71790E5C887F27CFULL, 0xEDD189B76CF34D0DULL, 
            0x26A0A76F51B7FF58ULL, 0x057DAF5E51E67840ULL, 0x2AA6EE6F5CA22E4CULL, 0x58DB67C2684F9180ULL, 
            0xF5C471A8A5034547ULL, 0x2A2BA92D5BA148D3ULL, 0xCB66DD3D2351D1A8ULL, 0xA1909F435BF377A2ULL, 
            0x5F5F8E6D79DB5068ULL, 0x55D42065916D00BAULL, 0x46DB127879C362E8ULL, 0xBEDECE986A9E260DULL
        },
        {
            0x3F687CA431BE7946ULL, 0x2F4517DFAAC3989AULL, 0xF61D21694EDB61FFULL, 0xADAED16B47353205ULL, 
            0xF4EFA3E858484D49ULL, 0xB2906CCB6A2770A7ULL, 0xFDCD778F5239362FULL, 0x8395629BE2210CFAULL, 
            0x6FB4A2E3857DA32FULL, 0x793908F556810464ULL, 0xC42441C3A6AF6920ULL, 0x4043D1C42F4CEBB8ULL, 
            0x8816A1CF5F5EC612ULL, 0x3C270ECE2A575D54ULL, 0xF74543A6518F8160ULL, 0xDF11744B1E79FA01ULL, 
            0x04EFF4C1A33A61DFULL, 0x1FA7E2D4297B66A7ULL, 0x9053B9156F9013CCULL, 0x08DC486019ED4C87ULL, 
            0xD2DAF686E89DB0B3ULL, 0x4C1F69836A7DD47BULL, 0x3005EE48C22E6B6EULL, 0x731E63BC841BB49EULL, 
            0xBEEFEB293383EC24ULL, 0x35C7DE14BC63DFC6ULL, 0xE0330267C66A2277ULL, 0x32BBE6C612EE9BE6ULL, 
            0xC97C0F3E9DC40284ULL, 0x0F5352AE62EEE0A0ULL, 0xF9698FC2054E7EACULL, 0xA741FB32433C2CFFULL
        },
        {
            0xFB70F4EC6B2172C0ULL, 0x6F797343815D4951ULL, 0x2CE84E70456BC79DULL, 0xFBE63AF432B0C333ULL, 
            0x1BCE4D7983E76514ULL, 0xB9D84F1C82470B5BULL, 0x1CC6226B4CFFC8F6ULL, 0x634AFAAEFBEF4BC0ULL, 
            0xD374DD011CCCFFE8ULL, 0xE5037E29ED3765BBULL, 0xCA8FC8D37B9058D3ULL, 0xFF9E21032CB77D3CULL, 
            0xAECE0B5355A5F5A5ULL, 0x5F923D80EC226B33ULL, 0x252DE34EC6CAC3D3ULL, 0x13A4F1F9C7029EE0ULL, 
            0x9F33C3A34123A875ULL, 0xDDC8DB399DA43C5CULL, 0x4B8A23ED22ABB1DAULL, 0xAD5C14EBAB940D84ULL, 
            0x7F040E8EA6935DE0ULL, 0x581FE6E8D71D2959ULL, 0x5BEFAE7CEF78E079ULL, 0xA0347559B01EB622ULL, 
            0x9FC15AA6A5111C9CULL, 0xDA7214C051CE3970ULL, 0xD3E21FECC28C12A1ULL, 0x4DCB8364ACA747BCULL, 
            0xA302F909C4FE1163ULL, 0x279B70CD0E1B92D3ULL, 0x482D52453DF86AEBULL, 0x85DDD413CC2E5EE0ULL
        },
        {
            0x6EC58C48174A31A9ULL, 0xF03812EBA7D0ABB8ULL, 0xCD327668131865CDULL, 0xD619E0469268BE77ULL, 
            0x90C117B544724CE1ULL, 0xABAA1FE4C68A9F5EULL, 0x8A6CEEB54BB5D205ULL, 0xEF8287B05D7535C0ULL, 
            0x9AD3A38671929883ULL, 0xA2BD161EC3F6EB94ULL, 0x72D4071E2B2CCDF6ULL, 0x470E826360C5FA0CULL, 
            0xC9B77FE7B37C7B94ULL, 0xA66D690A4D538C68ULL, 0x89E012441AD9F53EULL, 0xD3733B6FDB823191ULL, 
            0x964B2FC2D79B0E02ULL, 0x14B0D184FC387A31ULL, 0x072E7D0F506F99EDULL, 0xE89B18F248563060ULL, 
            0xAE16C8AEE2DFD05DULL, 0x076298C8F499B2CFULL, 0xF1BABFF2174F6593ULL, 0xF382133954EE89FBULL, 
            0xC9178DFE767C3827ULL, 0x9878FC124F25745FULL, 0x59D044C50BFC2F48ULL, 0xDBD25A45502E12CDULL, 
            0x5FDEDA5B39D15701ULL, 0x5D2EE7EC3A1E72BEULL, 0x8DBE2F9560A6822DULL, 0xA52FBD1D02C63A67ULL
        },
        {
            0xC5CD673397A57023ULL, 0x9D4000DEDB155BAAULL, 0x7ECA53AA06E91F21ULL, 0x2BF90915D01B0551ULL, 
            0x925024C8FE478D1AULL, 0x1D6640B814618A5FULL, 0xE409DE550D8B265CULL, 0x8446660F66FD5AD7ULL, 
            0xD14F7DD46493C47BULL, 0x740AE0422E6C3EEEULL, 0xBBAEA71B2104A1A6ULL, 0xFA57C5DE61927B54ULL, 
            0xCCADED8C799320D7ULL, 0x1073F44F6D3DC61EULL, 0xF292D1FD8016988AULL, 0x2A9B89F505AA9BA3ULL, 
            0xD65CA2B4E7603A39ULL, 0x6692D396FCC7C200ULL, 0xB6B83557990C2029ULL, 0xCF58DF8539D16DA1ULL, 
            0xAB4B71005BCB3162ULL, 0xB3A26C7BE4EDCFAEULL, 0xDB7D19892457DFBAULL, 0x04FAE29E2C8AFE1BULL, 
            0x30AB1EADE11C8A5AULL, 0x111BA3F6AE9A0582ULL, 0x42BDA98DE8F9E8E0ULL, 0x81417DC2C24BC853ULL, 
            0xAD8C71537B17DA94ULL, 0xE1C0FEB65E2849F3ULL, 0x240D8AFD4A7C4A90ULL, 0xC68FD23EAD84B475ULL
        },
        {
            0x05D31627EA6F8C34ULL, 0xEEF806C2F9DFB31DULL, 0x49FC13ED48A2AA29ULL, 0x91734D6502186CF7ULL, 
            0xD86A75AAB1B10442ULL, 0xEFD60AFBAC0D9EDBULL, 0x047A3FF29232F27DULL, 0x6A5E6902C91A22B6ULL, 
            0xA1A530AC26C3F860ULL, 0x189CCFD29BCD5893ULL, 0xFF91B9FA004BEE91ULL, 0xC308383563B486DAULL, 
            0x6C0C8A177F10411AULL, 0x5FA6AFC50E85D888ULL, 0xAE76334DA0827594ULL, 0x3566B290DB3BCAAEULL, 
            0x0417B88B074C5485ULL, 0x09C216481DC4FF33ULL, 0xC2037293FFB72A6CULL, 0x7C34B8D4FFAB7FFFULL, 
            0xDD4442C14A539EECULL, 0x6FFC65728F184B01ULL, 0x212441B20559CF01ULL, 0xBCC4DCF7222A1E83ULL, 
            0x738E08CDB388C144ULL, 0x5F7E11608189278BULL, 0x3FA23B2AE8834D64ULL, 0xDC18F6839F8655D3ULL, 
            0x9561E09DCCD83AF9ULL, 0xA5E4C53780BFC7FAULL, 0x5E2E4B4DC411187EULL, 0xA82077AA763EBC3DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseBConstants = {
    0x33A29B008A618A57ULL,
    0x288B94FE966EB8DCULL,
    0xF1C200775D386B16ULL,
    0x33A29B008A618A57ULL,
    0x288B94FE966EB8DCULL,
    0xF1C200775D386B16ULL,
    0xED12BF31302DE3B9ULL,
    0x2850BFB2F25DDDD7ULL,
    0x19,
    0x58,
    0xC9,
    0xB1,
    0x14,
    0x7D,
    0xB0,
    0x85
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseCSalts = {
    {
        {
            0x74B68EB77B4C30BEULL, 0x434DDF93A53307C2ULL, 0xFC8E8AABF76D9CD8ULL, 0xC410D9FBDBD6A152ULL, 
            0x358108E4B3BB1D6EULL, 0x52940A34E7E13BF8ULL, 0x976A3A4FDF392004ULL, 0x06412E15BCC8020DULL, 
            0x7743885A7489E65DULL, 0x2EAB90B3EEAAB184ULL, 0xDF025A09A33AEB57ULL, 0x9D2011CE20FC3F04ULL, 
            0xAC111E16749DB4A2ULL, 0x3B8DEC27B17D20B0ULL, 0x136AF5516986293EULL, 0x3B46DCB86291E66CULL, 
            0xB19105A54E1D9FC7ULL, 0x4981F0C3B503ADB3ULL, 0x1F0DF421FA56C8D0ULL, 0x843FBFDDF6F27662ULL, 
            0x17CFF5A930B461E3ULL, 0x0FA99EDB8A2B9627ULL, 0x20D88F193885195BULL, 0xC029A59BB64FBEAFULL, 
            0x7EE9160404B3848FULL, 0xF99A5AE7D48AEB86ULL, 0x194DADCABB01AFF7ULL, 0x11903F0A09F02178ULL, 
            0x9FA803B2988C7E81ULL, 0xD71FCDFFE37A5AF9ULL, 0xCAF87C1B1DEEE6A0ULL, 0x67907FF26C427D9EULL
        },
        {
            0xFBE63BF0E692B137ULL, 0x1D64344829A9A603ULL, 0x18588291942FF808ULL, 0x152B875DFB407542ULL, 
            0xC9A0790701F90672ULL, 0x49510C2948C6464FULL, 0x022BD87D74BEA0CBULL, 0xFC1AA7F2F1BEACA8ULL, 
            0x5D13558D4D396995ULL, 0x40180B96AD72EE79ULL, 0xA9BD910D942B160DULL, 0xF3DB1DF5DE89C5B9ULL, 
            0x03E696FD03CFDF42ULL, 0x239876ECC482D39DULL, 0xD09E1E1EB3E221EFULL, 0xA22C4B041DDA11CBULL, 
            0x5B352605199EA702ULL, 0xE4445D87A37E2D7FULL, 0x034D082D8E321B3FULL, 0x6D8140FDBA45B51DULL, 
            0x786E2F2E231EB4EEULL, 0xA7BA37A0DC171380ULL, 0x10293C9BBDB1E53BULL, 0xF165BED3CE065D5BULL, 
            0x47AAF57EAD1775C3ULL, 0xDEC7AC7420546CFBULL, 0x55CB34914C720DE8ULL, 0x0F5310C05B0BA0F7ULL, 
            0xB538B9CD2984C4F6ULL, 0xB11329C41AEC7AAAULL, 0x73EC163A5CB65D40ULL, 0xD2E54807D9D7AB1EULL
        },
        {
            0x0A8BC9441A1B6B56ULL, 0xD8A829A7C07F07B2ULL, 0x65DDC8AAC75447D9ULL, 0x86418F612A08883EULL, 
            0x465336607CC7BE1FULL, 0xFB8A5B09DB4D0C77ULL, 0xE935B21C15D4AFE1ULL, 0x54A0C3BA394E74ECULL, 
            0x6D5DEE1524317088ULL, 0xD9B44F37BD13F5FBULL, 0xDF48318F500F9ED8ULL, 0x4CA32EADDBD8BA5AULL, 
            0x6637FE1FDF6012F3ULL, 0x5E52743D4BEC5095ULL, 0x3AFF57A6696119EFULL, 0xD9F4707C3E5096F4ULL, 
            0x32B8923EBAD38103ULL, 0x14BCB68C4934FD82ULL, 0xBCF6193C83F4A99DULL, 0x81A33FDCB9AD5164ULL, 
            0x8DB86CE1E4B6D814ULL, 0xDF5C1635AA962A21ULL, 0xE135FD33FA43548BULL, 0x04594C52E1FBB1B9ULL, 
            0xB8E8EA6B36D9CEACULL, 0x018DD9387A4486D7ULL, 0x087068416B396995ULL, 0xFA39C0EE12F3AEFAULL, 
            0x34DF40F00E74F2B9ULL, 0xB57211116498BDAFULL, 0xF02780191E426282ULL, 0x5B4638F1FE0844A1ULL
        },
        {
            0x70274E1B3E342FC6ULL, 0xDCC296EFEAE17440ULL, 0x2B2529CEA1B59F89ULL, 0x6918303E6592A8A4ULL, 
            0xD5C2DFD13A3FAA8EULL, 0x393BC084D12D98A3ULL, 0xD4320002B3586E3DULL, 0x200D2B0F355A7875ULL, 
            0xB6CA4278B216F44FULL, 0xF995638CEAA42CECULL, 0x5B73643B6B07133EULL, 0x27F2B4BAE687146FULL, 
            0x3A2C187D1F94AEF7ULL, 0x3F7593F709A996E7ULL, 0x3DB3FC785703451DULL, 0xFD2945EAC1C788ADULL, 
            0x124F3F19436AE48DULL, 0xD6D7E9B0229C809CULL, 0x10661214C9B9C7A5ULL, 0xBB22CAAEC1FD7A46ULL, 
            0x84FF8960489F66F8ULL, 0x95BD0AE44F9DDA6BULL, 0x9779FCD61D99D936ULL, 0xBD33034BE3E6A60BULL, 
            0x05C915CE953B343BULL, 0x4B5FD80E4600E752ULL, 0xBE08A38A46BBD350ULL, 0xC740332E53AF725BULL, 
            0xA4222C012512B96EULL, 0x726507C6AC6D7CCFULL, 0xB288BE67C8F813E2ULL, 0xC920FE09AAB04CC9ULL
        },
        {
            0x407E498415903C7BULL, 0xEF18C0441BCCB66EULL, 0x96879FC01090D854ULL, 0x9C55A935517A8483ULL, 
            0x231DCCA3FDB5C619ULL, 0x2B8C018B8FE3C9AEULL, 0x9FB8EA1AAE47536EULL, 0x36805F15FD5B836DULL, 
            0x9684740624F97BD4ULL, 0x7C5C8160C980A3E5ULL, 0x426BC37D30333731ULL, 0x21B2672BE1FCD2CAULL, 
            0xEB7A6FA217EF0BA0ULL, 0x16442485F8BCC1BDULL, 0xFCD8F4C6B78A9564ULL, 0x6A8D4DF80DA15A6BULL, 
            0x4124DE4C13B6BF83ULL, 0xB2F9958D2497EA16ULL, 0xFAA7CDDCA9587C0DULL, 0xAE0A7C1CADAA4BD0ULL, 
            0x3B0A570BD152D7EDULL, 0x9F658008727429FDULL, 0x93A97A5E1ED85D83ULL, 0xF929901A7D85C256ULL, 
            0x6AF4F997A5EE4539ULL, 0x03C244936A91602EULL, 0x5B134EF6DDF4BA4BULL, 0x92EDE0926E36BA17ULL, 
            0xB28AC07423A9AA1BULL, 0x7E23FEBE7A6F04C9ULL, 0xB997D9D22FB7FF9CULL, 0xA6BEEC71989D8C14ULL
        },
        {
            0xC5ADC0DBE57FD429ULL, 0x2D09AF93ADD30F77ULL, 0x47C9D02E7437FC37ULL, 0x89187061691D5416ULL, 
            0xC67B7474B51C8635ULL, 0xA2340E1AD396FAB4ULL, 0xCD43119B397AC271ULL, 0x4E3C795A4172692BULL, 
            0xE20A1DD9B53FA204ULL, 0x87E743AC1F446921ULL, 0x284F3B2548D09DB7ULL, 0xE3422CC1CDC828C8ULL, 
            0xBD28E4A8F4CE41D9ULL, 0x5DF63945173C9F4CULL, 0x600A1EE2F57AB5A2ULL, 0x3E21E3E3350D08FEULL, 
            0x62D9CED795308FCCULL, 0x672602A20D952072ULL, 0xAB88420D881D343EULL, 0x1F53F508E5D01E69ULL, 
            0xD6AA7341D6A2E9B6ULL, 0xA239D032D6E83534ULL, 0x62B468C80E10B13FULL, 0xAEAF127F335951B8ULL, 
            0xA2AC3F0C1C4D298EULL, 0x9303176496E87AB2ULL, 0x5156A2E8E3392B16ULL, 0xB6275AD8152B1FFBULL, 
            0xFF1A421197087447ULL, 0x6FE8ACE69211D0C4ULL, 0x52C648A99BE3CF65ULL, 0x9A04DD52AA437294ULL
        }
    },
    {
        {
            0xE6F47E89FA9F6D8CULL, 0xBA2AB3DE9EA921E9ULL, 0xDF71AC7C9D826BC5ULL, 0x44DBDA28477CF34BULL, 
            0x6C64941941ADB8AAULL, 0x41FDB097E3BB70DBULL, 0x4532EF1FBA93ECFFULL, 0xC67D8F7CC100ABA1ULL, 
            0x9E7B299540BD12E0ULL, 0x98AC045281919FD0ULL, 0xDBF8338AF6F4AE72ULL, 0xE057E2AF5262429BULL, 
            0x5809D83D87A6035FULL, 0xFECE508057F5FCA3ULL, 0x933C5EC9C493128DULL, 0x733A4DFD9F4AB7CAULL, 
            0x089B855E72C9D22AULL, 0x5E138E53C6498836ULL, 0x452822E6C622BE53ULL, 0xA76EA6DFADE3D70EULL, 
            0x48C08FA1EB3BAD2AULL, 0x05AF3AE2AB192EECULL, 0xE156F9DAF137EE0FULL, 0xEC5692DDEDE44829ULL, 
            0x5C2A0F10543F20D7ULL, 0xC7FDC32BC10A3211ULL, 0x5916BEDF1726C76EULL, 0xE052351914D8576BULL, 
            0x067080C09C34E5BDULL, 0x57AF7ECA60C9C20EULL, 0xB3CC5632EF954FABULL, 0x0CDE48EDB733E617ULL
        },
        {
            0x2436EC4A38428B07ULL, 0x88F0BD217757BE0DULL, 0x18B6601FD0234873ULL, 0x434F980CB5CD96F6ULL, 
            0xCE473724B03CC787ULL, 0x5159320B926F9215ULL, 0xA7E251B2FD44883CULL, 0xB7BC3F20F598F0D2ULL, 
            0x93FC0EF8AA36B170ULL, 0xB9CF08E8C5CDE604ULL, 0x08E53057A93B7778ULL, 0x839D1E241A905A1DULL, 
            0x88AE7AB7B403DD07ULL, 0x41E689252898222FULL, 0xC424C1DE9C5BEF02ULL, 0xD490117C6368318BULL, 
            0x46E638F2C8F77E36ULL, 0xB904A4680C5E93DEULL, 0xF275FFBDE9DD56A6ULL, 0x75562041E48DD687ULL, 
            0x981E6A6959D4257CULL, 0xDCDEEFE94EE88981ULL, 0x56EAA6EA59F08773ULL, 0x8EE5370C807556B6ULL, 
            0x9E5737A20998701FULL, 0x4B47D49031A5E48CULL, 0x2B58D3FC3C631F9CULL, 0xF3A93F25AEFB0475ULL, 
            0x3A462107F574DA01ULL, 0xC494B191AE621FBEULL, 0x3E422637DDD6A4BCULL, 0xF39D66D8EE299EA9ULL
        },
        {
            0xF08AB4B6133A180FULL, 0xF38BF0289AA6AEC1ULL, 0xA3D042EBA25458DDULL, 0x16A1D0A30514206EULL, 
            0x465F3C502AF36C58ULL, 0x8F0BB8DF8BC80EECULL, 0xC6CC403D38FB163EULL, 0xEFED8339E99353C9ULL, 
            0x26EA0CC250FEA741ULL, 0x84158DF0142D4C28ULL, 0x884163A734B26F55ULL, 0xECC70319FB169298ULL, 
            0x8992C184752CCEDCULL, 0x9891F91484033E8AULL, 0x4C834D28CC92AA80ULL, 0x428A860542ACE88EULL, 
            0x6452228F0530FD64ULL, 0xBC98331D7E11C2C5ULL, 0x03700F08F1C896F4ULL, 0x3787D40A843820FCULL, 
            0xF9B7B9BD16268C3FULL, 0x74B01813745F4FFEULL, 0x8D6E9A9989C468A1ULL, 0x750275B5590D0F76ULL, 
            0x0DA75ED38FAC8AF4ULL, 0xEACFCE095B6860F8ULL, 0x6393C53D20169049ULL, 0x0E95FD2BDD4C46C0ULL, 
            0xC5A4C3AD0BF28A6CULL, 0xC8CD1A99100998E8ULL, 0x016A027844355B62ULL, 0x03FDC0B1A6E2E47EULL
        },
        {
            0x9801D159253E6A65ULL, 0xF559F59C0283FA2BULL, 0xD0D70D8E032DEFC3ULL, 0x1EB438867D27D24BULL, 
            0xA157533A43110CB3ULL, 0x188EA956379010F4ULL, 0x9A39A3C631AA8934ULL, 0x0C3D1C2D91BE220CULL, 
            0x0C1461463C69521EULL, 0xF61D0F2F5DEE8E0FULL, 0xCF5F4AB6EB4F5BFBULL, 0x8F3994A6490E662AULL, 
            0x2D27EDD02995D6A4ULL, 0xBDB685FE4BAB3C8CULL, 0x59E085616EE2038FULL, 0xB231A4E4D08D27BCULL, 
            0x14DFE0F1C71AAE26ULL, 0x5338B32CC959A929ULL, 0xBF63587927461E20ULL, 0x76601C691DDEE7E0ULL, 
            0xF820FF015A5AE3E5ULL, 0x366CE93E15F07E6BULL, 0xC0A6B25644BA7EE9ULL, 0x69A356B752F6C908ULL, 
            0x27EA5DB83ABAB67FULL, 0xAB4737BE43038A37ULL, 0x2B5A63E73F8B52B2ULL, 0xADDCF36045816172ULL, 
            0xD7A589987CEAA4C1ULL, 0x3CD6EFB13FC65B25ULL, 0x47030C37A199CD30ULL, 0x1B614558C657D15CULL
        },
        {
            0x785B572FA897EAA8ULL, 0x2E4727B4765C27C5ULL, 0x4C84DFF364909267ULL, 0x39939F424085D0C8ULL, 
            0x1F0871BC51004E40ULL, 0x9E27296535A3C739ULL, 0x9EB20EEF0CAA47E8ULL, 0x677D6E50DF2716E8ULL, 
            0x0A6FE0BBDB5F9C26ULL, 0x9259908B45E20CA0ULL, 0xBE36CD907BFA260FULL, 0xEB226B9B87C75461ULL, 
            0x835292E25D789688ULL, 0x49B8961342E9B800ULL, 0x65230EC71A2CAE55ULL, 0x0BFCDA97FCD3E603ULL, 
            0xFC84524BE099EB2EULL, 0xF8856949FF98C18AULL, 0xAE839E5A50EDCF32ULL, 0x60934A8E5C6F1E5EULL, 
            0x876258D726913799ULL, 0x6AAE87EB2B67C58CULL, 0x91BBAEE11D96D9CDULL, 0x96BC1173ACCEDD2AULL, 
            0xB185FE40A9663A7AULL, 0x399BA73B4FAC974FULL, 0x280FC985D364EBB1ULL, 0xDB22E176DF779DEEULL, 
            0x91D76440F5B912E3ULL, 0xD107245C0778DD5CULL, 0xD90D862C04F61EF2ULL, 0x78D8B37F0E0730A3ULL
        },
        {
            0x5A294E6BA1FBA803ULL, 0x4615466CC904FB12ULL, 0x2FE1FA76C387CD1CULL, 0xD0C68B7556D55486ULL, 
            0x57664D9187F30E71ULL, 0xC613E24355B6624BULL, 0x83A982D224D0BAC3ULL, 0x53DE3874BD45B05EULL, 
            0xFE81AA1D105F54B9ULL, 0x7F5ECDF0B64A53FAULL, 0x7C898FCD58CB9342ULL, 0x6092E198B4D09E21ULL, 
            0xFD14DEF7E390C3CEULL, 0x1B2C47C22403EBFBULL, 0x63830D5F8F7880A5ULL, 0x5D6A3E12B022070AULL, 
            0xD9CC1D5E018CB4CAULL, 0x008B9E3B312F6ACAULL, 0x46C1D6E2A332E0A7ULL, 0x95FC9947B13F0521ULL, 
            0xD35A7013B40A202CULL, 0x8F61933D424890E3ULL, 0x35A470D535F8E15DULL, 0xA3C86F439D9F7B30ULL, 
            0x951A1DE0DC29A1B2ULL, 0x8BDC2E59E44AC509ULL, 0xF718BBB06D12591DULL, 0xEF002300E76E301FULL, 
            0x7DF5AE9E44AD8A28ULL, 0x402FAEAE8B815A2AULL, 0x3BB688DE0578AAAEULL, 0x9507BC68ECAA08A2ULL
        }
    },
    {
        {
            0x567E6B8672CF302EULL, 0x05D347037833C362ULL, 0x7CF505FDA71D4C88ULL, 0x47B7A6D548A2C042ULL, 
            0x070FC50A9383C8CEULL, 0xA33A8FD9E52B735FULL, 0x16D7507D11502549ULL, 0xA87E66DC36267893ULL, 
            0x5559194FAC3BCCEAULL, 0x5AD5835181E411A2ULL, 0x307B72E2757B732BULL, 0x1495D68F438A1678ULL, 
            0x41B92A87B4C11CB7ULL, 0x5F32DECE5F1D61D6ULL, 0x767EBADC4228B398ULL, 0x1E7150B0B2EC15D5ULL, 
            0x7CF78D9935CF5F4AULL, 0xACF94A1331BB8D82ULL, 0x8EA597A7EEC23312ULL, 0x712713FCACD58B22ULL, 
            0xF71BA3B7B7C4F2C9ULL, 0xB980AB68B7ABE23AULL, 0x078B1FD41A247335ULL, 0x68D3A214EE264FD5ULL, 
            0xCE26FDA003707D1EULL, 0x682BEB2745FA36F5ULL, 0x12A04FAC39DDD591ULL, 0xCE246F1908930E1AULL, 
            0x1A5A01CD98817236ULL, 0x17394900151E4DEDULL, 0xF807FFC0967FF703ULL, 0x79FB9937C35274EFULL
        },
        {
            0x25C3D47239D6FDBBULL, 0x3352EA988B9B3317ULL, 0x80A9C8A5335E2042ULL, 0x3652FB0E863360BDULL, 
            0x525ABA276905FF30ULL, 0x0EE5B610A8FCBEFCULL, 0x7DD3A410D119198EULL, 0xEACF19C28D3F90D4ULL, 
            0xDFA6256ED28EA83FULL, 0xC281BA301E90F95FULL, 0xA9A74DA82E00933DULL, 0x05B8FDA3E82B9207ULL, 
            0x0EBE1F054B6F86B9ULL, 0xA02835BA73D053F5ULL, 0xC6D841E451FD3252ULL, 0x5D6D450AE9A6480EULL, 
            0xCF2B6F14CAABEC9BULL, 0x78C89285A574491AULL, 0xF5194D9498E76275ULL, 0xB3096B113C400DDDULL, 
            0x79D56BC6F0F13FC7ULL, 0xD86DDD8E10174EB3ULL, 0x7C6E8D87251E7E75ULL, 0xCB9C4A728512557FULL, 
            0xF441EFD7F0A5581DULL, 0xE5FD79259F9BDC73ULL, 0x64A5503698250B7AULL, 0x69FD1AD4661F8999ULL, 
            0x6B0D1DFB6C3F8ECBULL, 0xE31B33A8628E7B94ULL, 0xB69FEC82FB609338ULL, 0x75250CCC0C7912D3ULL
        },
        {
            0xB6F470F022B96A95ULL, 0x8316B9EE52529338ULL, 0xBE81D9FFCB289A8BULL, 0x4A7A6DD13EA174B8ULL, 
            0x7F1628DD6C4E1E06ULL, 0x62903B9396A7150CULL, 0x3BC79ADE4F00FFECULL, 0x934BCC7D9A6382FFULL, 
            0x5C02146704DE3FC9ULL, 0xC03E5AA94EE6348BULL, 0x3459BE19BCC95BA2ULL, 0xF9C5D0D6FE47D76EULL, 
            0x5FF48746AF11E5C6ULL, 0x5C322842C1713FA6ULL, 0x3AF92258797E8432ULL, 0x2ABB649E148DB6CBULL, 
            0xAAE38A5EA094AAC7ULL, 0xCBE24F962E4EC8F9ULL, 0x95A9CAAFDB428B2FULL, 0x77522503FBED61C2ULL, 
            0x15EACB10F046A5ACULL, 0x44CA4D6BBC1E68EAULL, 0xA7A3372B8705CAB0ULL, 0x8ED0AF603099A2B2ULL, 
            0x846B058B3F6D8B66ULL, 0xBB20EF76BEA21033ULL, 0xC87AAA60EEF6FF6CULL, 0x67425D71F86A2E98ULL, 
            0x0B7A9803BD64488AULL, 0xA99290ACACE48CC7ULL, 0x66D73200FB4A042BULL, 0xF73E43BFFEA3853FULL
        },
        {
            0x6A288077772AC68EULL, 0x7336647BCD1C01FDULL, 0xB134B134DAB8E108ULL, 0x92F536EFEB54F9C3ULL, 
            0xCD80C1E19913E855ULL, 0x0C86450A820BB265ULL, 0xABF9EFE003DC8FE7ULL, 0xFEF548F12E7D3012ULL, 
            0x6604FC2EC547010CULL, 0x4E53227F11991478ULL, 0x952DA535FFC432C4ULL, 0x897CF50667BBF5CAULL, 
            0x2D8F8AB5F8BD8555ULL, 0x07851CEBF2953381ULL, 0x69CD796C50C9A48EULL, 0xBF1866F38FB169C0ULL, 
            0xDC07DECC2636F449ULL, 0xB275C9AC940DBC85ULL, 0x35D8B12362BC6481ULL, 0x5A7098CF7A2FD59AULL, 
            0x5CDE0EA71C16A42EULL, 0xB39A408DEB4C38B6ULL, 0x478CC56E9BAAA3D6ULL, 0x36F18001482F3496ULL, 
            0xBD4FE26E889E7122ULL, 0x234444253DF64D43ULL, 0xE70D70919C9FA815ULL, 0x0131A49036B668B1ULL, 
            0x0260DA209FC2DAA1ULL, 0x9795F7C0DDBC772FULL, 0xD9CEC323C1321228ULL, 0x4BCEBDFC8FA79F5CULL
        },
        {
            0xD0AE3883790B1517ULL, 0x15DE1742368F6A15ULL, 0x86C9E1D559D83C71ULL, 0xA097038F46B79F5EULL, 
            0xAE1033496784F45BULL, 0x906C408D5255EF0AULL, 0xFB29F7C3E0F38808ULL, 0xD3130A7780CB4B4CULL, 
            0x6D98E14A63937621ULL, 0x00B43B3E4CE167E0ULL, 0x1F92480876F56862ULL, 0xC9E346293E2FD4E6ULL, 
            0xBEAB4CD06C2AEE43ULL, 0xFCD2701E74B8B18CULL, 0x11FEC29DD73651B2ULL, 0xD009186B8746C03BULL, 
            0x373FEECAC9C0DBCDULL, 0x29FFBD128D41AF03ULL, 0xF447D15206894C76ULL, 0xA7D8E41A573E6F47ULL, 
            0xB01D1FAB8F73993CULL, 0x86BF987954E8A87DULL, 0x70E8384954AF9917ULL, 0x213D1314911B176CULL, 
            0x183E033CB45C82C7ULL, 0x98266801C3EC1637ULL, 0xB98930B39BF5B69CULL, 0x7B03C9C3C6751842ULL, 
            0x0CA1760E0710568CULL, 0xB9C6E9ACE255615CULL, 0x9E8FC0B6D0CEF56BULL, 0x7E49056C9D37F8EBULL
        },
        {
            0x3229AC314337B7EBULL, 0xDF30C0220D524E14ULL, 0xD842AF65A551A6FBULL, 0xD4CF71367D05B262ULL, 
            0x1A693961D95E8E9EULL, 0xECE3251F2F9643F7ULL, 0x67A8F2EA953312B6ULL, 0x22A655CDC2BD1F14ULL, 
            0xA19E8C95D2684D1EULL, 0xC858698842502366ULL, 0xF134B1474C3AF525ULL, 0xAAA4E30F0F6D6021ULL, 
            0xE937B528B659ED30ULL, 0xAFFECD5612AE3F6FULL, 0x958A41F80E2FB407ULL, 0x322F17FDA4B25E62ULL, 
            0x0D86DD7EC2A18CBDULL, 0x4FA4653D601B98BDULL, 0x070DD75F360EAB47ULL, 0x48EEE83E5351FACAULL, 
            0xDBC6BD1002F656A2ULL, 0x61F37A1E09E26851ULL, 0x09AFF7955484908AULL, 0x2E7F579A0CB4AED5ULL, 
            0xC760F72D9EF9E258ULL, 0xD7C4F49FDB1C9F2EULL, 0x022EA85436A3D275ULL, 0xB41FD5DAD038E9DDULL, 
            0x5D585B77C14E9DF6ULL, 0x4E7718DF5FDA37C5ULL, 0xDC1A03DA73DC11D3ULL, 0xEA9FEC6A56E52A72ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseCConstants = {
    0x6B46C46901D3A08AULL,
    0xFA3EE05AE5607A6AULL,
    0xA7091AC960EAEE46ULL,
    0x6B46C46901D3A08AULL,
    0xFA3EE05AE5607A6AULL,
    0xA7091AC960EAEE46ULL,
    0x659D221116C6E385ULL,
    0x2F9B75A0B1217FF0ULL,
    0x2E,
    0xA7,
    0x37,
    0x97,
    0x87,
    0x41,
    0x7C,
    0x19
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseDSalts = {
    {
        {
            0x81D63F60907064CAULL, 0xEB5CD9B20D39B3E7ULL, 0xC506985756CA273FULL, 0xC9119810D51870B3ULL, 
            0x3089A7C60022F5E7ULL, 0xFDCABCC843481D95ULL, 0x06D7BE828AAED759ULL, 0xCC9C95D6C3EB55E4ULL, 
            0xA381A13C8FE9A2E9ULL, 0xB9F8DF5DC46783FFULL, 0xA3E99E59FAF350B7ULL, 0xA11D6BF5E4C15073ULL, 
            0xC5BA93821A44FC7AULL, 0xE19B722D03D2A0F7ULL, 0xA19BC222023FC71CULL, 0xBEE4B9F62C8284F7ULL, 
            0x57AC2D4FA1525C71ULL, 0x5C9902B4AEAD52F7ULL, 0x14C8B1C42342FEC4ULL, 0x41BDDE9E5C56850BULL, 
            0xD7291B5BB4B5C232ULL, 0xD13C7CB35DEAF54EULL, 0xBC49134D7763AFC6ULL, 0xB1311356B361338CULL, 
            0x96DE865EDB3AB7CDULL, 0x46DFF7DAA698274AULL, 0xE1728A247A76D907ULL, 0xBDE90A89AD8ED304ULL, 
            0xD3D6332B78AC7471ULL, 0x9AA7BC322E2DA577ULL, 0x92F4EFCF3973385FULL, 0x527E2DD7E62C611DULL
        },
        {
            0x8761E58007477E67ULL, 0xF7F87A3601729611ULL, 0x670407CD1B51AE5EULL, 0x55375E6205802F5AULL, 
            0x541B0ED2354AFC57ULL, 0x5CAAF6E6B7F6B1C8ULL, 0xD7FD42ADB21884EDULL, 0xB8324B7B7D952FD9ULL, 
            0x754DAD4BDAAA1B92ULL, 0x1EB260F193D8D679ULL, 0x8D6DD63EE5436137ULL, 0x9B9117F729532F00ULL, 
            0xDEA9D6247FEFF099ULL, 0x5966C3860FFA0A3DULL, 0xBD03F6BD670CA577ULL, 0xD237A39EAD2B656FULL, 
            0xB3EA2D44AB0D5FD3ULL, 0xA7FD8FFE5BAAD8F5ULL, 0x404D23D21D61A267ULL, 0xB0ECDA09101D934BULL, 
            0x7E3FE7E8284D6667ULL, 0x406BFE7230CCC639ULL, 0x4F591CE9D1EC363EULL, 0xFE8D8B5330902DABULL, 
            0xC8FA895B8C57FD8EULL, 0x66FC02D002022A62ULL, 0xD2FDCC392FBF1B45ULL, 0x3721499EEE6312ADULL, 
            0x12E858FA79646068ULL, 0x0507CF81CAEDEEADULL, 0x14579CD650CF1D33ULL, 0x26EA214372329A61ULL
        },
        {
            0xF0A5CAF6001641F7ULL, 0xAD3B1376FEC31D17ULL, 0x27875FA8B74DBCF7ULL, 0x2716F4E5202DF901ULL, 
            0xA709D918334579B6ULL, 0xABFCFA9A872C00B5ULL, 0xF58A060DFF5EA0CDULL, 0xDF9AAB310B9A585EULL, 
            0x262F76321FD8175CULL, 0x1C54BD7A0FD63125ULL, 0x3E2BA9CE22D24026ULL, 0xCB49D678DD58AB68ULL, 
            0xBB7E6BF849595921ULL, 0xB93136E3AC18A6A4ULL, 0x1E4ACD5C9816F41BULL, 0x126632FC68E90787ULL, 
            0x82308F160E08B007ULL, 0x1316498E37D9887FULL, 0x8CB171E949BB69ECULL, 0x6FDE37AACF3895ACULL, 
            0x0A572AA22B5F49ABULL, 0x880C913F66805F56ULL, 0x4BF242DE78382C0EULL, 0x5A31CF4F617F47BDULL, 
            0x5B6AE786ED4578BCULL, 0x7D7A8CCC8D819509ULL, 0x2E8A707BF3944EA5ULL, 0x7B1CCC779686BBAEULL, 
            0xF360E1E8D410F633ULL, 0x7D1B70F7B40ABDA7ULL, 0xFFA5274C19D31F5CULL, 0x2DDE7345603A3F0DULL
        },
        {
            0xD6DB1CDAE6FF30EFULL, 0x279CBF48B4F41AB2ULL, 0x94CACC5CF7A7F633ULL, 0x9A1E81733923430FULL, 
            0xABA7DE2D487E8998ULL, 0x2D277E9347CBD1C7ULL, 0x06AEF3C416956FA6ULL, 0x2227684913098C32ULL, 
            0xA8EAC50B4B3E251FULL, 0x5FC93FA624F4D00CULL, 0x43F0D30807ED6814ULL, 0xFE8CDBA606A6F388ULL, 
            0xE11BA8425C108D49ULL, 0x9495C2FDD0BBB95AULL, 0xB4D554C6BFF16376ULL, 0x2CAE13173DA96E82ULL, 
            0x1DAFB78DB618E3DBULL, 0x74E01AE47018A49EULL, 0xA17579036B1E617EULL, 0xF5E49C022092C251ULL, 
            0x701D108081F8686DULL, 0x1DB6A6D33795A447ULL, 0xE32A25E7351E3520ULL, 0x3DA443CDC3E4C2B0ULL, 
            0x57F68D4C3F6FDB34ULL, 0x04E4223583CEDAD6ULL, 0x69F284F08BEE3D46ULL, 0xBB487724BAFB8117ULL, 
            0x8B3FF596A588FD2AULL, 0xF6C23975AD7749EDULL, 0x1920AECC7F654007ULL, 0x1FCBC2FD8B979C1DULL
        },
        {
            0xEC0468AEE420A20CULL, 0xD02113F8B09A760AULL, 0xDB192371756EF024ULL, 0x45971C1D1E02BEA5ULL, 
            0x6D9348B455926629ULL, 0x716166CF4AE4863EULL, 0xBC06ACB1DE4FB4F6ULL, 0x4284B7209DDC002CULL, 
            0x690ABF111256D7D1ULL, 0xE1ED24F366B81272ULL, 0xAB21436AD1D9E5D8ULL, 0x52362CAEC0E1A83DULL, 
            0x948AA9FE51FA7F1DULL, 0xAED55FA5E01FC7D0ULL, 0x6171652355B5EE0EULL, 0xE9B53191D4451FF1ULL, 
            0xE40D6C249ADAF6D5ULL, 0xDC99D733F3A45D37ULL, 0x10E0F8A6516D4A9AULL, 0xB19F11581E30C701ULL, 
            0xF40355CBF2B5806DULL, 0x68B795D61BC8FFEDULL, 0x9902ECB791B98807ULL, 0x5A5F5BECB3AD67C9ULL, 
            0x14A438B4DA0578CBULL, 0x659EC39DBBAA1480ULL, 0xE786AD65C35CC2C2ULL, 0x40E2B71DCA2298EDULL, 
            0xDE749E0AD65F8E9CULL, 0xC19DE4932746AD19ULL, 0x5D533377138F9BE9ULL, 0xAE31CFF9A02BF61DULL
        },
        {
            0x5DF82DC90D274191ULL, 0x36F6809EDBBE27A4ULL, 0x0D3E5121863868D6ULL, 0x90F7AD7C4D545392ULL, 
            0x8D5FC92FB1172074ULL, 0x91FFBADC4BB76BD5ULL, 0x9B831F05F5971BB8ULL, 0xC82EC3105A6B67F9ULL, 
            0xC2E02F287C1C74AAULL, 0x68D4CDFFD1149A33ULL, 0xF1CD1969D9E7C01DULL, 0x5A284A7B8726503CULL, 
            0x3980DCA35D29C5A7ULL, 0xE0D863F615EF79BAULL, 0x17BB48ED013D1E86ULL, 0x77F95FF45DDB89B4ULL, 
            0xDCF8BD9E17DD879CULL, 0x5FF8795004AEE3A0ULL, 0xCDD72DEC1DCC486AULL, 0xF323EEBF0586BC07ULL, 
            0x5A3A6DBDCF47F526ULL, 0xC9DE4FC2FB00CAA8ULL, 0xB469FBD0F8F27A24ULL, 0x637E07F02706D017ULL, 
            0xB2FAE752DEE3201DULL, 0xD68E5E84808990E2ULL, 0x2A1ACBD20FE18134ULL, 0x7CFB98E40C54E7A8ULL, 
            0x36700541F77338D5ULL, 0x7F1E7BE0C1295DA2ULL, 0xEC4F9D2FFDDC2E15ULL, 0x680F7EDB75C23AC5ULL
        }
    },
    {
        {
            0xF470C0672CC61D27ULL, 0x41D9F09A41C7A469ULL, 0x20725E12E53DE9EFULL, 0x941A5C02E2C37A68ULL, 
            0x1D5A670963BD8784ULL, 0xF65BA11FF547EC5AULL, 0x2E7DAEBF9CEC89DDULL, 0x139437BB73588053ULL, 
            0xE79ADB4B72141C33ULL, 0x0EB77DE29A8E2269ULL, 0x9B76395E16429FF6ULL, 0xC171CF2F337796ECULL, 
            0x8FB03E974D68FF0AULL, 0x286F7F95656A1333ULL, 0x19E8084727DA620DULL, 0x592CDE3F8CD67693ULL, 
            0x5224A89DACCEC45EULL, 0x7EE5B32459AE8471ULL, 0x75F44164541584ADULL, 0xE7C8AC707E597B9CULL, 
            0x8D430E5E112FBA64ULL, 0xA1C31F43C7DAED9EULL, 0xDB9678F020A71929ULL, 0xD0455328D0CA6E3BULL, 
            0xDC9B3FE69750711EULL, 0xFF2B27C220CF9219ULL, 0x9EA4E148E2E99E44ULL, 0xA128D84E5AF982EBULL, 
            0x47E655CA00130B06ULL, 0xA180E72DD2083AA0ULL, 0x40C019A4B65FAC8EULL, 0x08927D204707113EULL
        },
        {
            0x97F2310DEE4F4CDBULL, 0x752955E3E974C819ULL, 0xC5349EAF86DA9972ULL, 0x973BE09FE4F7E6DDULL, 
            0x698C7A9DB1614ABFULL, 0x3F9618A8EAC9AA8FULL, 0x41C1FEF8E79FD693ULL, 0x8D5AC12AD92296EAULL, 
            0x8B778E3C5C290237ULL, 0x716AC80FC94E4E00ULL, 0x88D2FC3FC38D5BF1ULL, 0x6B29CC5E53374EDCULL, 
            0x5506A66B6E84ACDEULL, 0x20BB4F6B94F995D0ULL, 0xB556615DCC9CF689ULL, 0x3B5D97BA189F9A70ULL, 
            0x595E4C47F1CC1CE1ULL, 0x9C34AD9F846283CEULL, 0x0E4E61511E2B4623ULL, 0x65AC0F7F40ADF5E7ULL, 
            0x3BE4439405950A23ULL, 0x9F662DB8D8162B6AULL, 0x0DEA596138C516F3ULL, 0x092EC96F60F8362AULL, 
            0xBD62231C8A7F7ACDULL, 0x13CA30A31C7C6A20ULL, 0xBE7D6C46C045E34CULL, 0x2F9DC39F9E9A22ACULL, 
            0xBAD26C22F3D1FC84ULL, 0x91A460F518C5FF3DULL, 0x178669AD46FC4F1CULL, 0x0060B9E209A81783ULL
        },
        {
            0xC17D285847467D7BULL, 0x0D5A6CBC53A67F1EULL, 0x137505CB0B1C7F77ULL, 0x3B143AD705431B48ULL, 
            0x8C86F06A1AD56E35ULL, 0x1D6FB7C828DF21DFULL, 0x1CA38AB9E657A19CULL, 0x87BC386344182262ULL, 
            0x8C7088EF5CA78D6FULL, 0x1CC64A8D0A9A4ACDULL, 0x81AE5498D32920B8ULL, 0xEE4283CBB2295147ULL, 
            0x4FB0D9AA66A19780ULL, 0x032B8B325D677B7CULL, 0xE7C60388389CFA08ULL, 0x68BFF14133C8CCE7ULL, 
            0xF5EAC1D51F2BCE08ULL, 0x2F7F09F6839C26CCULL, 0x29666924F481C171ULL, 0x847CA6A18F05B015ULL, 
            0x1408A6A9186FEE4EULL, 0x8BC69EA49EE9FF2EULL, 0x5BD064195E92AB9BULL, 0xDCA734ADCA972284ULL, 
            0xDC05A5D139149891ULL, 0xE978B5A8B3883533ULL, 0x2529012BF7BAAA82ULL, 0xCBBD75BEC01E74F8ULL, 
            0xB75CBCA500FDA5B5ULL, 0x5679A71058BF0739ULL, 0x27B71F8244F57DF0ULL, 0xC0D453DE5A7E663AULL
        },
        {
            0x2A521078AEB2B4CCULL, 0x02C3855C6B6DD788ULL, 0xE4213A1C8D978216ULL, 0x1FDC599A76F7B018ULL, 
            0xD45B20EB3941927FULL, 0x8437ED2D0DC2C952ULL, 0xDE44B59BADA7F31AULL, 0xC77733EFF3655EDEULL, 
            0x1533818D9B82A5A8ULL, 0xD05CBC174E3D7C46ULL, 0x29549874E0BBC1ECULL, 0xB95E56718CA1AA84ULL, 
            0x5088A232121E899EULL, 0x5A4D055903D83B27ULL, 0x00FAC717D3732C8AULL, 0x6EC845F94ACC8A0AULL, 
            0x890A21F127F5BF68ULL, 0xEFBC1BC219009C1FULL, 0x1E2E587DB69DEB0FULL, 0x5470954D01FCB383ULL, 
            0xD4C6A05CEB10B091ULL, 0x082E14A9F45F9655ULL, 0x85ED65A9D384AEA1ULL, 0xE77D27247BC56A86ULL, 
            0x98A61F04EE2445A7ULL, 0x4A636599DAEF0B9DULL, 0xB53C479240C2CB83ULL, 0xE658980E32CFE0DBULL, 
            0x9AF85D324609F109ULL, 0xAE9C78408EE19EEDULL, 0xEDA901CB5927A76EULL, 0x5399A313979DAF01ULL
        },
        {
            0xE746D5DF843EE25FULL, 0x12614F44426F68FFULL, 0xC4C734F322DD2982ULL, 0x6782A3AB5BEE2672ULL, 
            0xF8E74D89D90ACB8CULL, 0x6A5304DC304118BAULL, 0x764EEDAED1AAB6E4ULL, 0x6DD4F9F8450D3E0FULL, 
            0x748F78574F183DCBULL, 0x4E767B38E87AB844ULL, 0xF60116E72F55A122ULL, 0x8656F0C3AD8B15DBULL, 
            0x56A1111FE6EB532CULL, 0xB3EE10B1AE6E1F2CULL, 0xE06632DDF50E554AULL, 0xD920CE9E8446406BULL, 
            0x1DD23FD3004443A1ULL, 0xA3ECADA93BAC3401ULL, 0x259BC853B3643399ULL, 0xAE2462F145D5EEBBULL, 
            0xA71389E390EDE92EULL, 0xB21AF97824F551F7ULL, 0x79C857FF3CD0CB12ULL, 0x6C7CDF1E97746353ULL, 
            0x66E3CA238F89A35BULL, 0xAF491119484FFB68ULL, 0xD68F9341EF2A13ADULL, 0x747E509F1E7CE6AFULL, 
            0x6B46B179988497D9ULL, 0x72D3568A5EF6DAF0ULL, 0xF36A53E0E53CA114ULL, 0x7363FF89FD3B9139ULL
        },
        {
            0x3479A1C90C7D6E6DULL, 0x0D843DC77F9A880EULL, 0xC22E6E8B5CEB46BBULL, 0x1AB1CFAECA59CC93ULL, 
            0x9CB54AE6BBA1B81DULL, 0x65E53F8D93C45CA1ULL, 0x011D68176AC6238BULL, 0xDC1651AE6FC69613ULL, 
            0x27092849F7690899ULL, 0xA2014A8656DFB657ULL, 0x03C5C1B44C1B1290ULL, 0x99607A368D0604DEULL, 
            0xDDF96F18B89FA5CEULL, 0x7D52B6936DCACE70ULL, 0xECE9AB82235003DFULL, 0x118CB1EEAA5EB32FULL, 
            0xE0E3997F0DD37222ULL, 0xD2E6E1D5C4F1F23BULL, 0x9907D9D9D693ACCAULL, 0x82928DACCB628C89ULL, 
            0xD1EA0C717550DE3CULL, 0x5634585B60CE2939ULL, 0xA3B05B510E5A0E25ULL, 0x394268818CD2E2E2ULL, 
            0xA010821EA4B68216ULL, 0x364580E87699B992ULL, 0x57E78225D9EB0278ULL, 0xB09B97332086CC1CULL, 
            0xC2478745FE2460CCULL, 0x1A77115A4EEBAB41ULL, 0xEA28CF94851F458EULL, 0x88C20BD4BE7F6E57ULL
        }
    },
    {
        {
            0xCFA69A580FCF625CULL, 0x51C68EE808743579ULL, 0xC71B4714F7FA4697ULL, 0xCF11B8BAB698D9DDULL, 
            0x9C23A054E0F06214ULL, 0x5ACB53D0D243F034ULL, 0x8786D678CF1527C2ULL, 0xD90CC85535F9A34EULL, 
            0x91906A382C08590AULL, 0xC0FE4221F08AA524ULL, 0x6F30279B874B9B3DULL, 0x746C2C30DA1F8BB5ULL, 
            0xCDD8EED8D39043ACULL, 0x37FB1B8329B9E1F0ULL, 0xE4BFAE697D5923CAULL, 0xDBFA99BB1021DE8DULL, 
            0x6FF6A786163A3AE5ULL, 0xD0969CA5AF3E43EEULL, 0x17CE89C232B5A5D6ULL, 0x2E680C416DE09134ULL, 
            0x1977CD016AC02E5DULL, 0x987043631F369D25ULL, 0xF583176E76E98028ULL, 0x7FE725028B858824ULL, 
            0x638FD72A374EE7E2ULL, 0xA5CF9E8923693980ULL, 0xCEA214F3C13D5F9EULL, 0xA044BF1C54B13E24ULL, 
            0x9B5865E1968C2ED4ULL, 0x7DB9C4BE89872B97ULL, 0xC85334183A9EDE79ULL, 0x5E51C1D65A75B578ULL
        },
        {
            0x90D3222AD8C08755ULL, 0xE8C961C417AD3163ULL, 0xD21B1EC2F8D6122EULL, 0xBFCD21FB1855F693ULL, 
            0x3FE85EB3DDB7DB65ULL, 0xCE696BF488ABFB5CULL, 0x87FB4B93CD5C3AFDULL, 0x3362B7617253C62EULL, 
            0x47853873B34AFBB3ULL, 0xDAA773FF4967D9D8ULL, 0x3815E2BDCBF56564ULL, 0x5026FA380AAF25CEULL, 
            0x9D56037620ADCC07ULL, 0x9583CD6D60FC455EULL, 0x9665BB50263DD7F7ULL, 0xDDF5794406A256D2ULL, 
            0x03BA46B235E553BFULL, 0x065B6515A3DD7821ULL, 0x52EFAF3636BB12AAULL, 0xFD2A4E88A393EA64ULL, 
            0x1BD4CA54820C86DCULL, 0x0C103D76A9C2E77EULL, 0x7038D4F363735313ULL, 0xD1C0225F0DC0F061ULL, 
            0x6E653C78993D5084ULL, 0xB2BD200DAE45B206ULL, 0xA9126E9442F51B4CULL, 0x23A587D87998DB03ULL, 
            0x26A105D6F4CD9400ULL, 0x8FA6D4F5B713634DULL, 0x05C1960EA398A2C9ULL, 0xFD1C7DF4457524D3ULL
        },
        {
            0xB056002219A26B23ULL, 0xCB724C775EF3CBEFULL, 0x0E5157FF7C9B7B93ULL, 0xC33BD1AD75A51B8BULL, 
            0xD96FA385A2AE0972ULL, 0xC0E5A47C6C7A6B53ULL, 0xE138A4637972A72AULL, 0xCE70BF851C1375FCULL, 
            0xE8A208936ED36DCAULL, 0x2497A9FC8A05CAC8ULL, 0x887A0E77E12DC177ULL, 0xDA5445F264869F15ULL, 
            0x90934707563ACB16ULL, 0xB0CD8079481F9E86ULL, 0x4088B9F9A6A5E5C4ULL, 0xCF5C95D43D52C949ULL, 
            0xE24E469B25BF1AA6ULL, 0x02EF3AC982172239ULL, 0xAFF543874304C580ULL, 0x219FE24B5357FE5AULL, 
            0xF2BDC8CE970F2E04ULL, 0x71091CCEC62FD17FULL, 0x3F4E8D1DDEA3DC6CULL, 0xE54AC816D58C873BULL, 
            0x5ED9A17F8D1FBC4DULL, 0x752F354F6F39342FULL, 0x61377AAAB4E0E9EBULL, 0xFD8291D897C40D12ULL, 
            0x00CC0F0A00D2FD0DULL, 0x2CAE62407F31F851ULL, 0xC0495909AE994E5AULL, 0xC2A0CDC94599ED9DULL
        },
        {
            0x3ECC3FEC85E7A13AULL, 0xE308B299834EAAB5ULL, 0x558F281209F269DCULL, 0xCA8E0803C202D4F1ULL, 
            0xD976B7ED16A1890CULL, 0xFE06B9384D400ACDULL, 0xD632DFC3366FDEF9ULL, 0xC2CB4F587036A542ULL, 
            0x4820701CC2BE18F0ULL, 0x7D7469BC6152A4BAULL, 0x38833D3247BB57C1ULL, 0xEA56DC63CF017868ULL, 
            0xD1675E418E517C69ULL, 0x66BB6BAC45696032ULL, 0x3EEC629699480423ULL, 0xB2D2290F1D1D99BFULL, 
            0x0E7266AB66392734ULL, 0x52B3023078DAAB3DULL, 0x999F8A7C79B4606CULL, 0xBBB70D7D32C7F317ULL, 
            0x496975E8B1BAED7FULL, 0x5B8779A4F13599D8ULL, 0xE2EDD3932C6153CBULL, 0x7CAED6976CD9634BULL, 
            0x2BDD1FC65FC97BF9ULL, 0x5042EB79D95AD519ULL, 0xF0E9C6298648A4FDULL, 0xF00413B0EF5357C0ULL, 
            0x68F2A68E659D5028ULL, 0x1092EA7B2BC9EB68ULL, 0x9FFD899CBFC93566ULL, 0xFF29B5E7C506FF84ULL
        },
        {
            0xF92635613E2ECE16ULL, 0x820D81AC984C4AF5ULL, 0x0803F90AB3F4E86BULL, 0x899BFC3A321DB1BBULL, 
            0xDF7E2D2EFF484AEFULL, 0x70F19CF1DCADC7DBULL, 0x94D961EE2948555BULL, 0x3D7F7749DD08824EULL, 
            0x3B71D766D22A6CD8ULL, 0x8D212E61A3BA44FAULL, 0x69FB0282DDAC3025ULL, 0x97D3AC090592D60FULL, 
            0xF6D6F7234B52B6BCULL, 0x7E5F2082DE60E119ULL, 0x25259F16EC612DDDULL, 0xC4F950DDFF145638ULL, 
            0xA6B61FF3E9E9F7BBULL, 0x15652B9DDCAEF946ULL, 0x503D0FBF11B54ADFULL, 0x32025CCE35794D82ULL, 
            0xB975489EE036521AULL, 0x7337E104B208673BULL, 0x960BF96CF389E879ULL, 0x11B33D74D0494011ULL, 
            0x53CB1352FED5139EULL, 0x82C4106BC36F4988ULL, 0xABE34DB54DB83463ULL, 0x3353733BBA6F30E7ULL, 
            0x6FA5836311509178ULL, 0xC67F50D5EFB2EA1CULL, 0x462788506EA968A3ULL, 0xC2B71BFBF9C7D4B5ULL
        },
        {
            0x99881AD2288932EDULL, 0x595642EC124982EFULL, 0x9E2D78A5F45BE6C1ULL, 0xE93784D4EAD404A3ULL, 
            0xCCD8ECE5AAAB5861ULL, 0xBF46772706CF64A9ULL, 0x79BAB2144F68DCE7ULL, 0x91296CF5AE54DEFEULL, 
            0x633654270225403AULL, 0xB215F9FAFE3B6B23ULL, 0x6FBAC67EF8BEA1F4ULL, 0x7421ADF76764C40EULL, 
            0x4478D536DA41200AULL, 0xEF6B77E5626AE14EULL, 0x6AD5F87107384EFFULL, 0x7F73042A6E95220CULL, 
            0x89A6550E744538A4ULL, 0xE27E9D51467741ADULL, 0xD85BC8024C67CFF6ULL, 0x8A07A0F47F6C59E0ULL, 
            0xFB28E14C5F204001ULL, 0xB0208518D6B82C11ULL, 0xE6562B9745EC4D37ULL, 0xD7E29D3954F14E4DULL, 
            0xA334649D6C311A99ULL, 0xECA6A6FD6783534FULL, 0x4B9A43089F228B37ULL, 0x76236F2C336C8398ULL, 
            0xB43671CB830CD56CULL, 0x6E644551C2A5AF44ULL, 0x82A68ABD237DB1CEULL, 0x50C6526B2B226291ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseDConstants = {
    0x1D505EB590BF0E73ULL,
    0x6B8BA0D6CCD9F97AULL,
    0xE3308DF9DE2077B4ULL,
    0x1D505EB590BF0E73ULL,
    0x6B8BA0D6CCD9F97AULL,
    0xE3308DF9DE2077B4ULL,
    0x298694C7185DC58FULL,
    0xD8F23BF4F7D99B65ULL,
    0x5D,
    0x7C,
    0xFF,
    0x56,
    0xB6,
    0xF3,
    0xC6,
    0x8C
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseESalts = {
    {
        {
            0xA644D4D3DF8D88DBULL, 0xBCD7AE68C4E17437ULL, 0x9537A68400C5A65CULL, 0x3B741957F74BF99DULL, 
            0xD08A14D1907FDF0EULL, 0x2307B4DB307DF34CULL, 0x7DD3CD27E97283D6ULL, 0x8B6DB3FB84F68DC6ULL, 
            0x46FD511A68D13D43ULL, 0x7205B518EFFD92C0ULL, 0xF49C762091927974ULL, 0x59E71380A2C17486ULL, 
            0x0B52B8E968ED778CULL, 0xBB11AC8D86403A4CULL, 0x3B7BB5088E1D12A2ULL, 0xF34BC8748B2E000FULL, 
            0x90821EDDE71662F5ULL, 0x337ECDAE80B4B34EULL, 0x6AE9916C208217EAULL, 0x2980DD95037631A1ULL, 
            0xA38314857554FA57ULL, 0xA90A2C61C262E898ULL, 0xAA3793481FE0893AULL, 0xBCFFD0E3A567B0E3ULL, 
            0x2767413113099606ULL, 0x386F8F7CAF224888ULL, 0x56E7CC10BD61F1D8ULL, 0x12D370D72A5B5D04ULL, 
            0xEEBD1161B2B9228FULL, 0xDCF0AEA28003318BULL, 0xEC68431CC8B3BF5DULL, 0x05D606E4148CF092ULL
        },
        {
            0xBEDB9F92A54A6EB5ULL, 0x8A1541A02D48340AULL, 0xB6F512D8425A02F5ULL, 0x77189141CBB03E73ULL, 
            0xF6EED15320914C2AULL, 0xAECF2EEF2AEB44EAULL, 0x9E10AF55EFBA8178ULL, 0xB620A520749D7E72ULL, 
            0x1D0297D114B57660ULL, 0x7AEC48E692015FDBULL, 0x696B5F8A49C8764DULL, 0xDBBC8DABFAC1F7BDULL, 
            0xE841A0BAEA09F19CULL, 0x57E9E2C6DBC86DB2ULL, 0xB46B82C5327113F0ULL, 0xDB791D70154B352EULL, 
            0x9AD444944512867FULL, 0xC26E21E7A48E6C0FULL, 0xEE905F9886EB405CULL, 0xAF4F3E55CBADA572ULL, 
            0xAC2C48A4E2CCB158ULL, 0x4F5CE658472B103CULL, 0x0F999EC19A42054AULL, 0x92571E3AE0A0DC93ULL, 
            0x17A101864C3749E4ULL, 0x1B532AF7ED966EC0ULL, 0x12DCD48C8B713C4CULL, 0x46A11183D2D22167ULL, 
            0x2EE49B225A5CEFB0ULL, 0x3CE240003CFC91D6ULL, 0x4FD8CE4DC47E0465ULL, 0xA8823C5935186502ULL
        },
        {
            0x7CFF1FEC242FEF20ULL, 0x3EB003BDF14B9742ULL, 0xB2E12C202AFE72B1ULL, 0xF5BF181C380AC446ULL, 
            0xD8609687CFD92F1FULL, 0xF033CA04E7B61C6DULL, 0x3A39D2E630EABF14ULL, 0x37862138E46CE3DEULL, 
            0x9E5EEB7F017C625DULL, 0x5C413EC6D41E5FDCULL, 0x6546FD86EF9A2570ULL, 0x719AB026077C9019ULL, 
            0x9E1CF1FFC8DF9D45ULL, 0x800C6B32B0F75163ULL, 0xD578EC0DC1F7E4D3ULL, 0x0B0BBC61B6339496ULL, 
            0xFA1F09DD348FFC7BULL, 0xDA090FF66B3D7682ULL, 0xCB7D54FE36FBE4FFULL, 0xFEB095798499232EULL, 
            0x678D1CC7227AE3B4ULL, 0x4CCBE9F2849C8103ULL, 0x53FA8D5A1E88B757ULL, 0x957E0268D61C0E62ULL, 
            0x10C878715BB7AC2AULL, 0x24121757F18C4F83ULL, 0x06B36538275A94D5ULL, 0xB30E67123E77E69FULL, 
            0xBFDD3D8E52817109ULL, 0x58945D9368A2BAE2ULL, 0x53BF60E6F53D2258ULL, 0x8200559F0220CD2BULL
        },
        {
            0xDB57707BD06E91E1ULL, 0xD0656CDC90A64775ULL, 0xB7E82E0978C41C27ULL, 0x3B79D0DA7861726BULL, 
            0x0B9D706C82FC3D9EULL, 0xC62A37E775E210A4ULL, 0xC9F5620EC8C667CBULL, 0x349019E047554777ULL, 
            0x1D8AD3F97AF208E2ULL, 0x6F0739B91FADE1CFULL, 0x15E6FE1A44B29993ULL, 0xD781EBCC941368B5ULL, 
            0x67C6AA1EE0A67E15ULL, 0x5D7CEF72609DDCE6ULL, 0x8D45CA1D9A7C3DF5ULL, 0x51C808DE9606F9C8ULL, 
            0x538C3AA9F014AA30ULL, 0x166612A4BEC10A40ULL, 0x0CA411DFBCDFFB6AULL, 0x949ABFB60E3D2653ULL, 
            0xB875C2871C8B467CULL, 0xDD4C301F6E7BDF42ULL, 0x98433FC708C6418BULL, 0xCD01E2B22077E41BULL, 
            0x94116BD51601463DULL, 0xE68BF95E510F0558ULL, 0x35B09A32D0CE90F9ULL, 0xF41C7E7F78F3FC56ULL, 
            0x7376813E87F8D8C2ULL, 0x2EFD1CC40F41244FULL, 0x44A814B0F24DF7C6ULL, 0x4CEE734D3C1E9654ULL
        },
        {
            0x334514C3A957CF73ULL, 0xDE3007B010037343ULL, 0x725F7F2269B044F5ULL, 0xC27CC9F16D70A543ULL, 
            0x637D274E1092EB59ULL, 0xD59CFAEC2C25DD98ULL, 0xA6053B99DBA292B8ULL, 0x2701BD8F3AF6E1B7ULL, 
            0x5DC6EA001792E7E5ULL, 0xC0B904AE142075E3ULL, 0x220DE2F265D10FC1ULL, 0x32558A7E72D779D9ULL, 
            0xE19B0A234F32B430ULL, 0x38F977551A7F8E82ULL, 0xBA785F576C243637ULL, 0x4B1C6A7E68CBA867ULL, 
            0x280F88F35FBA5C7BULL, 0x983255FB264BF8DAULL, 0xF44393CBFE7F7B95ULL, 0x0B098039AA6A3DFDULL, 
            0x96ED81505C5588A0ULL, 0xCD384AC80810CBFAULL, 0x146C6BB6056A782EULL, 0x3D9F8E0F1FEC373DULL, 
            0x073E1CA707DE5B4EULL, 0x778BD316B45D9625ULL, 0x65272D0A6D6AB4B2ULL, 0x72AA89715705D92CULL, 
            0x141FBBB112674718ULL, 0x1316BFF913AFC438ULL, 0x87B6385D5A27EFCBULL, 0x6C058DD5F1BA3824ULL
        },
        {
            0x355E9497DB48E310ULL, 0x8E4D6A8A580D52C9ULL, 0x9EA30CE6A317E898ULL, 0xC5369968370B5BC4ULL, 
            0x37B56134A074EFDFULL, 0x784B78F182400120ULL, 0xA76F21F189037DAFULL, 0x1A3658AC4CE13562ULL, 
            0x104BF084D6B4FA97ULL, 0xF382076B9925F374ULL, 0x5F1D6252DF4AF06CULL, 0xEFE3EAB522190628ULL, 
            0x830E74BC267A3D62ULL, 0x27D5FCEA76FC0372ULL, 0x9BEABF74A7B2DC22ULL, 0xAC159FA0B8174884ULL, 
            0xBB931A8097ACD076ULL, 0xC2DEDF9983D5CF85ULL, 0x17B3BB01305E5AC4ULL, 0xE68FD07F13D9DE3AULL, 
            0x619077FBCAB4812FULL, 0xBB3FDB5EE85E4176ULL, 0xBE82DC46A0100F35ULL, 0xF536FD3BADEF3BCEULL, 
            0x1841381CE21DAE60ULL, 0xB40A0AC9F814B8AEULL, 0x02489822DDE19FB0ULL, 0xAA318F20B308337CULL, 
            0xCB4DE6089C54268FULL, 0x6D0BBA8843C0ACE7ULL, 0x8AD700DB6AA28AE6ULL, 0xD3783C6F7DB0948BULL
        }
    },
    {
        {
            0xF0F4F7737DE9D19DULL, 0x0F3A1D630C20B439ULL, 0xD57808726C813200ULL, 0xE1CB010E67EB7711ULL, 
            0x53CB475B1306DA53ULL, 0x102E5735D5819512ULL, 0xCD506CE19BC2928EULL, 0x3B840B1B66FF4772ULL, 
            0xDCA81B8DBA358A59ULL, 0x2A191D6310A8BAF8ULL, 0xC9E65985E8EB7A1CULL, 0x0DA2F65F1EE5DB45ULL, 
            0x09A265AF3B09DB79ULL, 0xECD14D4EC67E4C72ULL, 0xB5C05B9A54D76CD0ULL, 0xA7E850C863F7F447ULL, 
            0x8B9E3EA7EF0ABD28ULL, 0x62CD1EAD85BD5A8DULL, 0x96927FC643484034ULL, 0x2E80EFC063320E49ULL, 
            0x1AA1F408435B2E7EULL, 0xF06294C138186F28ULL, 0x7E78DD5E57B66DF4ULL, 0xE586578EF597A1C7ULL, 
            0xE02CA6AA0BF665C5ULL, 0x1A30E79F5B5A9E50ULL, 0x9D55A104833F230CULL, 0x656F51E2B7954780ULL, 
            0x99F120AC6C20748BULL, 0x7F1C9C9A01365EC6ULL, 0xBA2F9E6EFDA9B8AAULL, 0xACC90A0D494482AEULL
        },
        {
            0xA1A9112423401005ULL, 0x064506611C4E6332ULL, 0xE346A4F2C05816DEULL, 0x278DDE624A193A34ULL, 
            0xDCA7403ED41A341AULL, 0xA23F3E4589BDC757ULL, 0x0C62A1FC17ABD0BDULL, 0x2FC8A05D79A4A072ULL, 
            0xD499EEA7DDF9DEE2ULL, 0x3767F2C65EE31F37ULL, 0x342323FDB86D21E8ULL, 0x846C97B999018669ULL, 
            0xE136945273E66EF2ULL, 0x1A9E8E58DD5E52F0ULL, 0x963C397E1FFB1642ULL, 0xC1FA92E9F5161DADULL, 
            0x3F10C07E064DE962ULL, 0xFEAB27C55934D325ULL, 0xBB44F55BCF541908ULL, 0xDB96A67CB4F21B07ULL, 
            0x476DD8369615C8F4ULL, 0x818E8276863C4A1AULL, 0xDF778F497D0E506BULL, 0xE09E49348DA37DBFULL, 
            0xB490746379B8F4C8ULL, 0x7EE65D3AA04EABCDULL, 0x2E78916FF6D89E85ULL, 0x7F1881770F117BF4ULL, 
            0xA3F7B1CD02F2A2E2ULL, 0x2A0F26AD6A5CA544ULL, 0x268FD05694AFCD5FULL, 0x93F1C2DB37DB8B9CULL
        },
        {
            0x50D987BC8234075AULL, 0xC672E6F15D80EFAFULL, 0xC28F6E9F074BAB42ULL, 0xBB8CE8BC8A27D9E8ULL, 
            0x32975ABC2A5339B1ULL, 0x5B3B9DAD3FDF277CULL, 0x91705D1342B812D9ULL, 0xB21B157968F4D44AULL, 
            0xC8C12D8E024F9920ULL, 0xFCFF48E951786F30ULL, 0x040B1E018C4B5E7AULL, 0xD20F7AA6FD20A3D4ULL, 
            0x6B9EE4E42DC61D54ULL, 0xA5C5AC558517670DULL, 0x35967ADEB63BBD1EULL, 0x0A32CA56ED92F140ULL, 
            0xA8711E0B346AA2A6ULL, 0xB49EB333779C4A85ULL, 0x13BBCB4BE094C331ULL, 0x8A4392D596ADAB8DULL, 
            0x79F24A6D7DCAC1DCULL, 0x3C110888A2807FF4ULL, 0x4882D8DBE1688576ULL, 0x8B88EA27B40FF2FBULL, 
            0xC76AA74D0459637CULL, 0xC75D7E138588AC91ULL, 0x5E78A1A1877C961AULL, 0x34DC5288C9E906A5ULL, 
            0x5CD23D4311D7C11BULL, 0x2974CC03C2D590D5ULL, 0xA2AB6A365B017A9BULL, 0x4A47D76C4AAA95BEULL
        },
        {
            0xB3B2A3972E8A1A39ULL, 0x02AD6AD36C587F31ULL, 0x65AC7513674798A5ULL, 0xD364473D1E42DC2AULL, 
            0x7A2935E6CB96AED4ULL, 0x5E2D49A89D729DCDULL, 0xAC2BEF7498D85074ULL, 0x12E3C08879875BC8ULL, 
            0x36DF859649064947ULL, 0x4E4F511D13E30973ULL, 0xEA582EA7CD09645BULL, 0xBCDB6714101580E5ULL, 
            0x7A91C09DB5B70078ULL, 0x19F0D60959C3F392ULL, 0x638D174E9C745FECULL, 0xE7D87319DE3AD052ULL, 
            0x54B9B9DFD625120BULL, 0xB228F3708B46EC05ULL, 0xF431F3B5753DF386ULL, 0x180FB7E5B4C5ED73ULL, 
            0x015FF4A0B6EC112DULL, 0xEAB1CA0B284E1396ULL, 0xFB886A3F3E336CA2ULL, 0xF2B827F3981EA460ULL, 
            0x6888F72910A0F6C7ULL, 0xAA0A739343BBCC37ULL, 0x9970E3593981FDD9ULL, 0x5295AF1C6F939FBEULL, 
            0x8AD9389E8D8B8357ULL, 0x8B02E1DBB8C152E2ULL, 0x7EB6EADB8FFE8E61ULL, 0x6E2F798FDE548CB3ULL
        },
        {
            0x2A1461E368C88720ULL, 0xBF7F908F4F2317D6ULL, 0x23E7734E53913549ULL, 0x65D190AF08557CCDULL, 
            0x26B28AD8F1B648FCULL, 0x94DC24336F6953A0ULL, 0xDB6F14925069E5E8ULL, 0x94CA83C601C0F480ULL, 
            0xFAAF85D7B220090EULL, 0x4930373ACD1A403DULL, 0x96053DD701D5E1E9ULL, 0x5657604230CF4C0DULL, 
            0x74AEC03A95D9BE4DULL, 0x32A6776A3E721EFBULL, 0x6672562EBD6E4AE2ULL, 0x1820C5B5020DD7BAULL, 
            0xBDB793F6E8DB6527ULL, 0xF3955D6F3ACB4BB4ULL, 0x6044C3EC488644DFULL, 0xE6CAFB90A07B7A69ULL, 
            0x0D4B150245262D5FULL, 0xB22A39DA72551AA0ULL, 0xD819997E190827D0ULL, 0x7A222629D93F6B81ULL, 
            0xA6507DBE68CB5E20ULL, 0x99D3F941661021BDULL, 0x4CF7CE880329FB2FULL, 0xDF661C161A80AB16ULL, 
            0x2E1A406671E7A698ULL, 0xFBDAAB69B063AE22ULL, 0x5D82421ADDC54278ULL, 0x1CF997D289CF6150ULL
        },
        {
            0x5A725615F6EBA1D0ULL, 0xF59CDA8F7744044FULL, 0x1D33FFC8014D0D69ULL, 0xB4B02162580C2B32ULL, 
            0xA0A732994149A690ULL, 0x492781F51317BCF5ULL, 0x793C05005C6EB4CCULL, 0xDB20D20F4EFB40AAULL, 
            0xC38B8046EF9820B9ULL, 0x0C6B8A5B95CCA7C9ULL, 0x2F64D01C1BF9116DULL, 0xC50054384D114BD2ULL, 
            0x3FE50C939DCF7FC8ULL, 0x27DE9336E149ABCEULL, 0x62F041DD7B861BB1ULL, 0x8E8FBE831FD78E53ULL, 
            0x52EC4BADBF287FDDULL, 0x5650A09A109F8E22ULL, 0x1D99E38EDA156FE1ULL, 0x2C56155B6CE1A04CULL, 
            0x979F522CA51CFA8EULL, 0x1E9E79EE0EEB2C43ULL, 0x20852E1AFFFF1CD7ULL, 0x64D975014959A813ULL, 
            0x54D66E00D7581F3DULL, 0x34C623D6FFDBA581ULL, 0x090DF967FAF44CFFULL, 0xA9F62ADF69F2BA03ULL, 
            0x018AC1B2F0170B9EULL, 0x2658E0BAB3F864DCULL, 0xDE8938CD9569D4E6ULL, 0x7F003B6524A94357ULL
        }
    },
    {
        {
            0xEDED2C21038BF9AEULL, 0xAC6BC4483912F542ULL, 0x7D8BF1BEFD8ECAD3ULL, 0xB9A11989C4D617D0ULL, 
            0x1111A8DE84EE85FFULL, 0x457F72208563DE95ULL, 0x13C4BDEE768C11A4ULL, 0xA426E04E7EF73400ULL, 
            0xDA25EB2EE3AA822DULL, 0xAC93BCE58EF36217ULL, 0xF513E6B483FF6FBFULL, 0xD6C4A3E7FB719FF6ULL, 
            0x3EAB043A52BF544FULL, 0x96359F0198B04DECULL, 0x7CCCF46895041A02ULL, 0x38786A6A5B9D3AA5ULL, 
            0x5EB91996B541F544ULL, 0xA0E17A3A420033F6ULL, 0xB68A278E00714CD5ULL, 0x793111DC11E020F6ULL, 
            0x8879580DB6EB54BEULL, 0x972EF2175758CA1AULL, 0x022805B816093285ULL, 0x520A273483B6D20FULL, 
            0x64E4EFA58B628700ULL, 0x153E78F29B236EEBULL, 0x476CAE5C5269215CULL, 0x0450510BEB85307EULL, 
            0x0916C79D448513C2ULL, 0x5BFD393331038385ULL, 0x2A27828C8D2245E4ULL, 0x2BF79D4658672BC9ULL
        },
        {
            0xD53367CD7D4B8142ULL, 0xF10B0E27D1805B9CULL, 0x2180C4B6D3F02FFCULL, 0x9C2DC2EAD0FB229CULL, 
            0x89A798C72774C069ULL, 0x35E2D7E6CAF9315BULL, 0x57A949EB575FC01CULL, 0x7E2AD6D192958461ULL, 
            0xDA12AA28051C7E9EULL, 0xCA8D9D7DC90C4762ULL, 0x37F0CA22301AEA53ULL, 0xC18AEB871FA91EAEULL, 
            0x8A5FB9A68DF8490BULL, 0xF0AF596CD1ECBA88ULL, 0x04CAB40356B644F3ULL, 0x5549DAC2CC789DE7ULL, 
            0x0907F6F612AAC4A2ULL, 0xDFBF6EDAC8F5C9ECULL, 0xCB2E63768B18EA17ULL, 0xF600860867493625ULL, 
            0x75162077927EEDCAULL, 0xCD2B6B59B9F41DA7ULL, 0x51AD4E36AC39C28DULL, 0x883DD1D66EEE1A73ULL, 
            0x4279241B43C44A0FULL, 0x020147207FFFB944ULL, 0x47C9B49F42BFE258ULL, 0x2A44544A25FE7591ULL, 
            0x4304B29909FC6407ULL, 0xC4CD4A03E236D795ULL, 0x86D3764768244205ULL, 0xC3673FF292304696ULL
        },
        {
            0xA70AE21A56571523ULL, 0x7DEEF40BB90DCE33ULL, 0x46D7A9E464F1E8B7ULL, 0x9666654A4BAFE034ULL, 
            0x60719868CA4FFF6FULL, 0x549E67B7E610679AULL, 0xC0F0BD2586A4CC1DULL, 0x4CCDE884257C55E9ULL, 
            0x7D54C52CF5FC732CULL, 0xE7D762C254E2E514ULL, 0x9A544173B9441709ULL, 0x0BEA1091C4F2A2DAULL, 
            0x1051F9EABD7D789DULL, 0xD1680196E7847E94ULL, 0x0A30C54E8778A608ULL, 0x22BFC950CA6CB946ULL, 
            0x4D40B342C74B5B6DULL, 0xF7AB6DD1DD4207A0ULL, 0x4379AAD219464D04ULL, 0x9E61DA1BA1740666ULL, 
            0x4161FBF87A630696ULL, 0x943FBF32837FA43CULL, 0x469E68B8F10581F1ULL, 0x62CA509364B3FF13ULL, 
            0x06304C214CF88801ULL, 0xDC20ED81C81690CEULL, 0x7EE46C2303A527B1ULL, 0x34A826ABF2029932ULL, 
            0xCAC8156DF3718CE6ULL, 0x7A780FB983BD0D9BULL, 0xCBFEEA58D2A85F70ULL, 0xDCEC2B630B7FA20FULL
        },
        {
            0x90D825B59CF389C4ULL, 0xDD0AAD48F7338337ULL, 0xA942E5C16A862698ULL, 0x30B91F53233A4D79ULL, 
            0x5B015F4C0AED386DULL, 0x75C289DF5D8B59B8ULL, 0xC8D3F3DE7671015BULL, 0x7E52095DC76BD9B1ULL, 
            0xD5D7A25735CC0947ULL, 0x905727CF499A4F84ULL, 0xFBD90859B386D3DBULL, 0x4CEA59EBD948FEB2ULL, 
            0x04AA70EDE551B01CULL, 0x08DBDDCE101A7FBAULL, 0xEA69966B983B1D4CULL, 0xBABD83AD813D2402ULL, 
            0x341043CA674E38BCULL, 0x1827B776BD4D650BULL, 0x6F9AACA0CF478787ULL, 0xC10F1C189AD625D9ULL, 
            0xE4C285204620C452ULL, 0xF79E188A8EF2B82AULL, 0x0CFAF3A2C777831AULL, 0xECA4248817AAEB1EULL, 
            0x8DB54F7578D54B44ULL, 0xD94E0834AC69BFB1ULL, 0xB9C4F3C0CCE6B53BULL, 0x5DE35ADFB22C80E9ULL, 
            0x220351475C56A38FULL, 0x8CD9F596C3A04D82ULL, 0x621E43182AF0F8A1ULL, 0xA2B0ECDFBF1B45E5ULL
        },
        {
            0x86741F572002B849ULL, 0xF474153BA664C2C7ULL, 0xD735563A22B49ABDULL, 0xE7DB96ADE8FBCB76ULL, 
            0x971AFF31AFC28990ULL, 0x135B078EEA81C3C5ULL, 0x1538EEE3D1C63E74ULL, 0x67D963C86159F53BULL, 
            0xEFD86D0DCA3A60A0ULL, 0xBA0A2FCC3F1FCB0DULL, 0x97C7348FD902824EULL, 0xBD9F380B744AFDAFULL, 
            0x19FA4112F1F0B2FAULL, 0xE51477C36CE5E25BULL, 0x98A76A65B4BE56AEULL, 0x66833A1B05C619A7ULL, 
            0xD873C08546E78378ULL, 0xEC6E6A32843CD8FBULL, 0xEAEF0A648A086E43ULL, 0xBA08B9B9E5B167C4ULL, 
            0xDE2B9E5E9489FBE8ULL, 0x838EBB501C9305B2ULL, 0xC066E8CEBB8F12D3ULL, 0x4D9E70E51BD4DF0FULL, 
            0x0D53B19E0804D7B4ULL, 0x340C9DF6FDBD7073ULL, 0xCA7BEE6E66D052CFULL, 0x2B1EC6D4C2E2873BULL, 
            0x69FE75FF5201B751ULL, 0xC3FB522C03075ABDULL, 0x998457EE54A696ECULL, 0x01B99001E533D2E1ULL
        },
        {
            0xBAE9A0E6EAE4E295ULL, 0x4946E0EBD4412726ULL, 0x7D05B2B798B365E9ULL, 0x4304ED34914F138DULL, 
            0x88E31BD8232A323AULL, 0x9FFE4CFA59B04768ULL, 0x4F8B0ECAE57EEBF9ULL, 0xED1B5A9C6C37292FULL, 
            0xFC4F0B41BA420E53ULL, 0xF30E3C45FC29D545ULL, 0x96EF78B674FFC126ULL, 0x9849FB621A9D731BULL, 
            0xB7469E29EDB05EC3ULL, 0x092C67BC97B70C92ULL, 0x20678A3B52643F0CULL, 0x67F9A1D74CA25CE5ULL, 
            0x440C2E87593575CEULL, 0xA85FBAEC7B7F9AC4ULL, 0x91C08CA6279E4D8DULL, 0xEE2A0DD6AB381749ULL, 
            0x9DEEE2267D26CE4BULL, 0x6EDFB8D55F8E93F8ULL, 0xA2899BA3E8F7E0FEULL, 0x928DD4C266323B14ULL, 
            0xD652DA086E1E0A38ULL, 0x4692F968D2D3B561ULL, 0xC942D0413A0537FAULL, 0x50482A7043480AB7ULL, 
            0xD4EC4CC1FDE94FD3ULL, 0x55E10EE29DEAF1F7ULL, 0x46354607A6BF7D63ULL, 0xE8CDF58DC8C6287CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseEConstants = {
    0x7E33E88C1606F9CFULL,
    0x3E44F88F561A1012ULL,
    0xE6111ABF54E4B115ULL,
    0x7E33E88C1606F9CFULL,
    0x3E44F88F561A1012ULL,
    0xE6111ABF54E4B115ULL,
    0xD609730ECFAB072FULL,
    0x16A98F1903E5BD7AULL,
    0xC2,
    0x3D,
    0xC2,
    0x1E,
    0x9B,
    0x21,
    0x03,
    0xE4
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseFSalts = {
    {
        {
            0x24D6093BD92B1DF3ULL, 0x62DA1BC697A4F4F5ULL, 0xED72DF3EBB33B512ULL, 0x5F669B7D9C3F5E3DULL, 
            0x3F2E97ECF8B90CA7ULL, 0x378A9A87871C4D15ULL, 0x5AAB0E51816FCA4CULL, 0xF0B6A2AE0C877513ULL, 
            0xFCA6EBD76E04821EULL, 0xDA919B250B730E29ULL, 0x0D7CA4784C329219ULL, 0xD7B35C5598C70939ULL, 
            0xA40C2A81A2922D68ULL, 0xED6BBDFFB7C6C439ULL, 0x985705FFA75B5FDCULL, 0xB489B65F7F0ECE2AULL, 
            0xE6D0C124C1680A34ULL, 0xC8FE067DEFF54420ULL, 0x51B0E3C0DD4C3924ULL, 0xD776CD33648BEB14ULL, 
            0xC719519E2585965FULL, 0xBCA202763140E15BULL, 0x63E4322637D6FB20ULL, 0xCA48C33CE2634DF1ULL, 
            0x47388158E86A9789ULL, 0xB5E5F132A4B9D544ULL, 0x8007E433AD2E8FF6ULL, 0x039611F3001673A1ULL, 
            0xBEB69A7252034F11ULL, 0xB85AAF2236795CA4ULL, 0x2707E5384173CD47ULL, 0xD1C71A5D5F274C0DULL
        },
        {
            0x324455D9B35710D4ULL, 0xD96E91B68A6AF79BULL, 0xB2FF0D364F3687AEULL, 0x5E23A0D91B9C9C12ULL, 
            0x08885F2087342408ULL, 0x427519D690784109ULL, 0xC0C4A9E9C2EFE2F0ULL, 0x1C8C01BA43CEE428ULL, 
            0xA5313CDBD7FC0019ULL, 0x48143A77486B3940ULL, 0x0CA1209C9D9A3AF1ULL, 0xF13DD64808BEE718ULL, 
            0x4F491F6C54700DBFULL, 0x6620CEACDB106873ULL, 0x88E572802CF11BDAULL, 0x6B1CAD919F68680AULL, 
            0x588CF39A2F3D2D51ULL, 0x5A223F9B0BBE61A5ULL, 0x8B83460F17E32524ULL, 0xA4818FC86593DB60ULL, 
            0x390F8CC28B9E3C62ULL, 0x94C9CBC481B8865FULL, 0x71946F39F15473D8ULL, 0x4CCE7429C4D3038EULL, 
            0x5878FDD735B78E42ULL, 0xA3315437792E7E8EULL, 0x27319294C20FA159ULL, 0x81ADDA32CAD371AEULL, 
            0x1EA7FAE9E3838753ULL, 0x3D975736A4A89965ULL, 0xCEF8444907644203ULL, 0x212AE48BBEA31B09ULL
        },
        {
            0x7CE40A1DC2F0A4B3ULL, 0xD9D80C44F9F6DB9CULL, 0x2F4EEB44ED8DC789ULL, 0x828FAAC9FAFDD2BCULL, 
            0xBDE84925A65716B6ULL, 0x40C15AC28EDC0A81ULL, 0x5067061DA5458A26ULL, 0x05144699B2DE26A2ULL, 
            0xFB4ADB0BC6DDB6FFULL, 0xBE1F46DAA2F705A1ULL, 0x52EB8A0D009BB799ULL, 0x7F1D9A531859BBE9ULL, 
            0x1989716F721F01D7ULL, 0x7C45241C94470D7EULL, 0xCBB735EA25BEC245ULL, 0x202CF181E1C83A1EULL, 
            0x92BC059449FBF2DAULL, 0xF2BE87C2CA34C09BULL, 0xECB8DF880BCD6C34ULL, 0xD8F363441145C057ULL, 
            0xD6C4300C04AE3694ULL, 0x56381F5D3C6AE723ULL, 0xD7A99F46E10AC96CULL, 0x35A9773CC4B39CD8ULL, 
            0x8D0F262572414415ULL, 0x1A474ECA3E00880CULL, 0xFBAB0B4DD56859F7ULL, 0xE7C8F4C5977FBE39ULL, 
            0x01778552F29B1E0FULL, 0x50C88A75C2ED1E04ULL, 0x6726E0D3C693B898ULL, 0xB87DE1966A7ABA70ULL
        },
        {
            0xA7CF0EC511532A47ULL, 0xC99B2FD48D583C9AULL, 0x3D5B1CF422D27C8AULL, 0x4BB04561E4D3127EULL, 
            0xFB86E84923E680EEULL, 0x451C6F170767F48CULL, 0xD103394B025E1A22ULL, 0x1D4B154312E1D5D5ULL, 
            0x167E1E9D77030326ULL, 0xB75E64A0F6A24FC7ULL, 0x1CEB7EF098ADCC61ULL, 0xA2AB0DCD05E892B9ULL, 
            0x7F6E70D944F47B46ULL, 0xD4913B8C5BE252C9ULL, 0x11488D8F178D969CULL, 0xB6E286FDB9E39279ULL, 
            0xDDEA43A6A14D7137ULL, 0xD6AAADE55696E5BAULL, 0x4FADFEF00169BA65ULL, 0x703A93E7DAA9C9ADULL, 
            0xB26403AC7DBF6B5FULL, 0x96C6DDEEE38C3A4BULL, 0x2FE11D3DE8644127ULL, 0x1BC1B7DCE51BA6C0ULL, 
            0x30046DB30A28F174ULL, 0xE5FE97E7706E68F9ULL, 0x0A36BBE635E38D04ULL, 0xD1D100521FBA8D08ULL, 
            0x5214197ADEB2261DULL, 0xE9D04638B77A5CBDULL, 0xDF6793BBA998B7C3ULL, 0x6872E3A1D46F8E91ULL
        },
        {
            0x1818D02D4325AE5BULL, 0x159F620D0F51CE9CULL, 0xFEC9916C7E08AA14ULL, 0x5C1C1F98455167F0ULL, 
            0x5BF36A8176B0AC49ULL, 0x2E5AFDCEEDC2E964ULL, 0x3E77AFACEAC20C2CULL, 0x5300468D417C8004ULL, 
            0x92B6E7EC3812EA67ULL, 0x30342EB442D0C5E4ULL, 0x67FF1E3022D8C986ULL, 0x451D43B3CD7D748DULL, 
            0x288619E9A59D35B3ULL, 0xE3EAE36B334AF30AULL, 0x9DA108D1D78BDD10ULL, 0x7EAD5E49AA49A847ULL, 
            0x4364EBC50D01F3F6ULL, 0x81BDF72FFFDD3BA6ULL, 0x712FC52645E80EFCULL, 0xF434E5BDB30B1EF4ULL, 
            0x0AF545ECEAAA3CDBULL, 0x756E3AE0CDCC9A97ULL, 0x9959BF52BB675124ULL, 0x94EA6161615EA220ULL, 
            0x997161B6BF29DF77ULL, 0xC9B34413004575D3ULL, 0x4A9E8BF88BD2BA5EULL, 0xDE1ABC839E8134A1ULL, 
            0x45DDE82ED056D3B1ULL, 0xA1CDFB35411625A1ULL, 0x2CCBFB25B4E656BEULL, 0xD4D2429ABD04557CULL
        },
        {
            0x91BFEF7264AD56B4ULL, 0x41F6880BCFED65B3ULL, 0x0DBE62095AF520F5ULL, 0xB7EC722B511482B4ULL, 
            0x98613F8620281881ULL, 0x18D0A62E312D34F9ULL, 0xCD4A304E74E93D0CULL, 0x0E3331CC184C8E6EULL, 
            0x97DD71132E623A4DULL, 0xF5AB0839D4F2429BULL, 0xB11EBBFAF78D5F12ULL, 0x58804C5BF0CF6CFCULL, 
            0x38522D98E84A49EAULL, 0x73B71D2BA3307D6FULL, 0xCA723B9C381805B3ULL, 0x49FFE7B2250C6FFAULL, 
            0x2E924FC3FEA9FC60ULL, 0xB346577FE1AB7AA6ULL, 0x98B93B2C2EF4FDD3ULL, 0xAA294AEE07BA8D83ULL, 
            0x488E1B415B4F383AULL, 0xF1976DC9CD95716BULL, 0x280AE892B5D5C602ULL, 0xCE9001B6F12F064EULL, 
            0x3AD085A36A34B4BBULL, 0x69CF46982D843FCCULL, 0x9DBDB918815FEBC0ULL, 0x77B26B284FD7171DULL, 
            0x790932B037950C1CULL, 0x2188F4F1CD92D6FFULL, 0xF782D28251D0B110ULL, 0xF6E1E7C70D0C77B9ULL
        }
    },
    {
        {
            0x92F0FAE0D875D806ULL, 0x6CB9A633462BCC7FULL, 0xBD9D9484ED2AB3DAULL, 0x0C81F410A8108980ULL, 
            0x497775784C3E8D0DULL, 0x38C577A87C712046ULL, 0xE784C61DF4BC5B50ULL, 0x6F187696C03ABB87ULL, 
            0x3C73FD548DF6197DULL, 0x501499316370EB5BULL, 0xB5FCA627469354AAULL, 0x5561DF443139E360ULL, 
            0xBB7AF2D40C72FCB5ULL, 0xEC74E6BBA4E47E5BULL, 0x37AE9175D9696CFFULL, 0x0C040B17D1B4BD76ULL, 
            0x32A659539227E304ULL, 0xF3DEC5B1A5218B6EULL, 0x7DDD2E7FFBF7489FULL, 0xDE08DC76B7E5AB91ULL, 
            0x692C5EBBCD569313ULL, 0x158808B888790ECCULL, 0xCEA1992FDA76B719ULL, 0xF879F36C8E4F4CA8ULL, 
            0xAEB5F320695C08A4ULL, 0x21322390097C22A2ULL, 0x5F945C06B5F52183ULL, 0x5E974F137DDC54AEULL, 
            0x5ACCEC6DE03DD43DULL, 0xCE138F80DE1ED8F3ULL, 0xD536D4E99152C81BULL, 0xA096EDC32162B0D3ULL
        },
        {
            0x1177199873A5E839ULL, 0x19747F5C89E61005ULL, 0x4ACD0A3A0F9E36EDULL, 0xF69FBC8BE6852A2BULL, 
            0x44395D64560E385EULL, 0x681039B3F42C73EAULL, 0xEE03450DB1CCECF0ULL, 0xCD52BEC01F96D734ULL, 
            0xC88D5CD42D525506ULL, 0x635CCF595277BB90ULL, 0x84B9426A35BA8512ULL, 0x2DA8E420A991C55CULL, 
            0xDF13B8490D574E0EULL, 0x531C112FA4A324C7ULL, 0x07618222233AE4DFULL, 0x01797372C548ED53ULL, 
            0xACA495A4A77DFA70ULL, 0xDCAF51669D38E912ULL, 0x563660D5D69E25BBULL, 0xCB80C22F909C5291ULL, 
            0xADE02B05B623D516ULL, 0x0912D2AC4BED4364ULL, 0x40E1C8E2A79F8F95ULL, 0xCF0D094B83CB7DE0ULL, 
            0x7709ED36BD786EA6ULL, 0x2FC2F6F35EC39FC8ULL, 0x102275669C13A831ULL, 0xF6760893E7CD74C6ULL, 
            0x21657C6CBDF98AF1ULL, 0x99CA2F7D6DB52BB4ULL, 0xC57179E45FC5D2C1ULL, 0x1BA19C0A8E8E2597ULL
        },
        {
            0xA81D4CF0F1E213F5ULL, 0x77E7BEBBA5CDBC93ULL, 0x995EEF0A0668045CULL, 0x72BB11F431F54F83ULL, 
            0x1ECA54545FA5075AULL, 0x31B5C8B358A1106DULL, 0x604595ECC782185CULL, 0xA51322FBD93C3A0FULL, 
            0x47086CFA930E1230ULL, 0x3FBE59DB0EAD68D7ULL, 0x8194DA33D7367DEEULL, 0xB209ABB833412C00ULL, 
            0x154743668F4F453FULL, 0xD67A6B0D9932C31FULL, 0xA7E25B905F521CE0ULL, 0x7367CDA7C926B538ULL, 
            0x789C4BA1BCCD0D51ULL, 0x2B15270F97A48492ULL, 0x1CB9A35B3C75BDB4ULL, 0x84C59597B90F085BULL, 
            0xA8C417D4B5C7152FULL, 0x90D5DF4DB07B0CE7ULL, 0x09518BF0E23635C5ULL, 0x8D0E95C8F188E9B4ULL, 
            0x12C31FFBEAF43D40ULL, 0x04FE4233A8258D9FULL, 0x44AB3B01BCF5F1B2ULL, 0xFA030DE1406E678FULL, 
            0xFACF6459DB518965ULL, 0x034316D61BC1E050ULL, 0xB2DCD417C01A35F2ULL, 0x95231E452799A71DULL
        },
        {
            0xBDB6DE5D9F23E8D1ULL, 0x7C96837DA9ED12E1ULL, 0x9C371D58592320BCULL, 0xA0865C0C4BB355A9ULL, 
            0xD61EDC61868F47C1ULL, 0x84F31D24404D91BDULL, 0xDF4B5B5F79F8E670ULL, 0x1E2B90590F55EBE2ULL, 
            0x4F2C4A4E337DCCB3ULL, 0xEE2DEE93A38E3FD2ULL, 0x26C3BDEB334D593EULL, 0x4550FF02775C92C4ULL, 
            0xB792CD1196ACC9EBULL, 0x602ABDCB9EB8059EULL, 0x20944B24492A2985ULL, 0x047946FB2531B5E1ULL, 
            0x04B8DFF949A4C9D0ULL, 0x9B8C9CE2138457CBULL, 0x3AB7EAFB58469EF0ULL, 0xA931C05C9BE81293ULL, 
            0xCE66939EA754726AULL, 0x2441C6428664E0A2ULL, 0x8E1BE3DA71F02874ULL, 0xD44BDC4AD744DADEULL, 
            0x7CAEDFA1A2A24394ULL, 0xA2473755C0FFE428ULL, 0x78C3D5280FCAB6A2ULL, 0xAB6788FB658CA9B2ULL, 
            0x5B763CAD6C8549E8ULL, 0x91FEBE439CEDEAC6ULL, 0x3664FB8D04B7597EULL, 0x53979ABFCF04B24FULL
        },
        {
            0x2C5427B5B482C45CULL, 0xDE068B8E34F94F48ULL, 0xE888DAD8B275DEFBULL, 0x32CBD911C364FC9AULL, 
            0x8332D7D7A16C8A71ULL, 0x6B153949A3D2AB97ULL, 0xA8362E6E7E0F0EC9ULL, 0x8464F1C17726E169ULL, 
            0xC55DA2FBCB06CCEFULL, 0xD468E9F324364CACULL, 0xC9F3DE6A395DFEF2ULL, 0xE8CE7538F3B0A1E7ULL, 
            0xE4912629D173DFB0ULL, 0xCA2C5F0436F6DDE7ULL, 0x4396F5E04FF771B8ULL, 0x892DAFB04612256BULL, 
            0xCA8FB87F27DBC8EFULL, 0xA8C207B6E9FCA5B0ULL, 0xADA057D66DDB8E6BULL, 0x0334E48A2C712EF9ULL, 
            0xBF3695223B4EEFCEULL, 0xD76AAC0CE2B936A3ULL, 0xE11DA3FABAD9B2ACULL, 0xD86E44F9D57A37F4ULL, 
            0x3BF0F0823A72D4B3ULL, 0xE8B6BD3222801E93ULL, 0x751EC1D42E80385EULL, 0xBEB31CA3B2A0CBF4ULL, 
            0xD8B472C8B51FEFA1ULL, 0xCD66466DB9F3BBA2ULL, 0x834D1C20A11BAAA4ULL, 0x8D878B5BA024334BULL
        },
        {
            0x98CE71DB5853C406ULL, 0x7357D0E4B5BF1186ULL, 0x52EF6F2B370C7CFCULL, 0xE68747EDB7CCAE2FULL, 
            0xA6A9B12C95F57C61ULL, 0x81567C1C0924E748ULL, 0x744101164E12CF50ULL, 0xF34ED05A11E12AB2ULL, 
            0x3785EE82BE5F957EULL, 0x63F89BE878AF3D58ULL, 0x5823E3713B973A6AULL, 0xDC08B07941FC9556ULL, 
            0x37D7177765B56317ULL, 0x0172437DF0B422E3ULL, 0x0D82DD19954448A1ULL, 0xA79A29A1BAC6EC39ULL, 
            0x3FD6999D0EEE4228ULL, 0x7D3EA34F928A168BULL, 0x74894AE07E76A638ULL, 0x187156A78802DC5FULL, 
            0x331357E613319CC3ULL, 0x00612EBBD556392FULL, 0x9DBB17231CD0A8F1ULL, 0x1F2E220E57A61A1CULL, 
            0x059E3C95FA21C5EFULL, 0xA26580A33C44856BULL, 0xD3049EEFF17F0406ULL, 0xD1717C9FFA9B1F94ULL, 
            0x35B953B6AD7787E7ULL, 0x83DD34554E203A7BULL, 0x74D53FA1F855A25EULL, 0xD7317548E3A64C9AULL
        }
    },
    {
        {
            0xBE47CC07F1C8377EULL, 0x328EEAF6182A96E5ULL, 0x6AF91BAAA409A6EEULL, 0x330289B9D1F3EA10ULL, 
            0x80E3FD87EC55DADAULL, 0x7FDD1237C83A3D74ULL, 0x2E56329B98949735ULL, 0x24F98BE585F70EDCULL, 
            0x99243C7D014DF26EULL, 0x7C03E38F5A734262ULL, 0x5A9F1FF2108910F7ULL, 0x920A03068BA0C2F2ULL, 
            0x872AC1A0FA02077FULL, 0xA3F0FA7CE53E4FCDULL, 0xE8FD876B88A0996FULL, 0xEAE39CB42F773185ULL, 
            0x44EA08923B4B9EA7ULL, 0xFFF70F5C4D031C30ULL, 0x1CFF225B500EFC33ULL, 0x372C216DEC805468ULL, 
            0x2CAD82D3B61FE740ULL, 0x1FEEAD606F653AF6ULL, 0x06CC26FD2C9674BDULL, 0x1896B516931E1A0EULL, 
            0x63AB45E4EB7A5FFDULL, 0x318DFA404F735A16ULL, 0x4850138C26B9DE85ULL, 0xE56BC8F223DDE6F9ULL, 
            0x089AB88FF676F2E4ULL, 0xB8D0C284FD9600D9ULL, 0xEB807CB6253581ECULL, 0xF488A1DEB2269B43ULL
        },
        {
            0x4CDADCFB3DCFBE52ULL, 0x5646095089CD699FULL, 0x0EC4A86E6E363622ULL, 0x4DD3FA9835AD23F6ULL, 
            0xBB74E6DFDD9096ACULL, 0x2C688CF087236464ULL, 0x698B5F7E87AD7104ULL, 0xFA7631F978162369ULL, 
            0x7959C750958B433EULL, 0xDA4F119222BF19A6ULL, 0xBC2E78B756E437F2ULL, 0xE96F4E2C43DA7219ULL, 
            0x17207CA0BA352B56ULL, 0x4A64DE3FDF765595ULL, 0x8F8D408F2E9D0FE2ULL, 0x561EDF3A75A0AD8FULL, 
            0xC57C790C39D04A70ULL, 0x84E7F649EF6F332EULL, 0x4870B26CFA190260ULL, 0xAB675C175ACCB61EULL, 
            0x9FD9C037E6290F62ULL, 0x7CFCFCA85FB7B129ULL, 0xACA99EFE868C27F9ULL, 0x3A23CAA7378E259CULL, 
            0xEF6134F2A6454EA3ULL, 0xBD99ADCCC7AFB482ULL, 0x39BCBA38B5119D13ULL, 0xE243EEC0F32B99DAULL, 
            0x13F04E85F8D0CA92ULL, 0x05DC9487CC9D8B52ULL, 0x4BDF98C099100C72ULL, 0xC84E67DE3B89A521ULL
        },
        {
            0x8927B51838780914ULL, 0x1DE4E85E8BE22726ULL, 0x7A306925DD86D00EULL, 0xCFC53BEAFD225A71ULL, 
            0xC8A96917A4C99120ULL, 0x73210FBFCFEF917FULL, 0xBD2A0D14DC6F0ECCULL, 0x287262E1295A7247ULL, 
            0xD13FBA79BE577574ULL, 0x8029EE9C0F41DE91ULL, 0x4AC95A15CBF2B06BULL, 0xDFF33E7FE05D2A7AULL, 
            0x2AAE5D79247D83BDULL, 0x67EE728C8609DEB0ULL, 0xB29CDBC1015D019FULL, 0x23A4954853736167ULL, 
            0x9BFEECFF6DE89B63ULL, 0x51E823A0842F7B3FULL, 0xD234EA0CB8D13053ULL, 0x4A326C500AC0387AULL, 
            0x26A30DB4A80D98F7ULL, 0xD02F582F38AB7095ULL, 0xFA6C048EA2EF8E42ULL, 0x472D63AEE9F90CB2ULL, 
            0x2BF528716BAF9B3EULL, 0xCD85F9A6746B1667ULL, 0x484BDEE183A7700DULL, 0xD0AE7C9143C6AD6CULL, 
            0x0BA99E9EB6ED3754ULL, 0x0B746ACEDDB46388ULL, 0xC9AA54D7AE744920ULL, 0xCF0910629BBFAD9DULL
        },
        {
            0xA7AD68A7473C7FFEULL, 0x2F383FF449EAD9B5ULL, 0x5376A8B31E54926CULL, 0x1331175D6B651B3DULL, 
            0x1C31B86E65343288ULL, 0x78ABEDF69496F489ULL, 0x1FC5B0B696CC1E93ULL, 0x61FF2EFB79C0920CULL, 
            0x0B6940F7D67CD07AULL, 0x79D436D3703D68C8ULL, 0x4025996F383DB060ULL, 0xA94F52D43AAABEC2ULL, 
            0x03C35D719B92C697ULL, 0x43CF460D757EDF7AULL, 0x835C53DB6A3E93B6ULL, 0x03B72849836D4CCFULL, 
            0xE6FC9D8F9A7DA044ULL, 0xC94628448F808D01ULL, 0xD8FB5AD2F618EE59ULL, 0xFF1F703A550F689FULL, 
            0xEFC0A6B519D7D703ULL, 0xF6AB3EE603D073F8ULL, 0x373A4D22EE1ED6CCULL, 0xFFE3DFA72845BC46ULL, 
            0xDDC1F344AFB2D00DULL, 0x2FB1DE6C8BC527A9ULL, 0x0C8E6512D6BFF536ULL, 0x1EA53646E23B3340ULL, 
            0xAA12074AEC141E3AULL, 0xCAB9B550CDA94D91ULL, 0x88BBF455F43D1A0BULL, 0x0A0A5A9F0C0741BEULL
        },
        {
            0x87C485408657D2C9ULL, 0x51E679103C8FED80ULL, 0x1A5609E656731912ULL, 0x7FB288EBB5B36D30ULL, 
            0x4AF53245EC3D9212ULL, 0xA1CFD04294479A1FULL, 0x15E1E908AE13636EULL, 0x4984BE418A568DB1ULL, 
            0x84A2A0EA8375EEA6ULL, 0x5FAC4EAEE1B6339FULL, 0xE35A4ABB04F41468ULL, 0x5ABD2C9E35B4923FULL, 
            0xFCB56004624614EAULL, 0x97B6FAE2EE8B71B0ULL, 0x0BC0BCE9621FB1C2ULL, 0x6AFD663A4CAF16D8ULL, 
            0xED6F772F74D36C85ULL, 0x9C287195919BD4B5ULL, 0x85A826FE076C34C5ULL, 0x3C01AE071B222375ULL, 
            0x55E1E576C391B929ULL, 0x20C9B5DF09F007A7ULL, 0xE224BA6E54F7CB01ULL, 0xF04B97FEBE0D5C7AULL, 
            0x2CD4F1668A010501ULL, 0x3505E069EA55FA99ULL, 0x1B4198A896B26E70ULL, 0x5E3E2357431D452EULL, 
            0x670C857A5420CE68ULL, 0xBE0F138638BB518AULL, 0x5A44E4E6817CE29BULL, 0x5A9EEDB2F64E796CULL
        },
        {
            0x966EA1B199C89EF9ULL, 0xBFBBF7078D20DE8CULL, 0x8CE33735F116B156ULL, 0x8115CA08A05B18D6ULL, 
            0xD62910B2676C00F6ULL, 0xD2A07BF4525E13DEULL, 0x99063A5A4AC9D391ULL, 0x77D373981DFEDC08ULL, 
            0x13E2EDE19CD0D259ULL, 0xB988119964DDDC8BULL, 0xB55E50FBE1CC4116ULL, 0x2A087CE699C6D919ULL, 
            0xACAB0BA7CD2F3E76ULL, 0x05149E9C4E50884CULL, 0xB17E1B9040535461ULL, 0xF4BC8A5B5750B123ULL, 
            0x17A5547DA76E0BCEULL, 0xA89D93A5AAE4E7D3ULL, 0x202DD4117B15DEB2ULL, 0xDF1AB4531F3DE156ULL, 
            0xD49D63AD41EACF53ULL, 0x050091F0876534C6ULL, 0x9AF87E4FA6CE5C38ULL, 0xFF5E8B78D02CCA22ULL, 
            0x43C493447833A7F5ULL, 0x8F2B799834397BA5ULL, 0xE0E74AA85645F060ULL, 0x9723D3360E6848A8ULL, 
            0x764E94B8B04E8B66ULL, 0xF75B1EE4E045D275ULL, 0xC36A4ED414604BD4ULL, 0xC05418989739D367ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseFConstants = {
    0x62112381337A3BBEULL,
    0x82DD46547057DFBAULL,
    0x2D4600F2B2479E42ULL,
    0x62112381337A3BBEULL,
    0x82DD46547057DFBAULL,
    0x2D4600F2B2479E42ULL,
    0x1C04C67DD0A501F8ULL,
    0x10761806D0C56C62ULL,
    0x6A,
    0x76,
    0x59,
    0x06,
    0x54,
    0x6A,
    0x04,
    0x40
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseGSalts = {
    {
        {
            0x01CA00F494CF1956ULL, 0xA7B050057281F3A6ULL, 0xEEC4587031848563ULL, 0x54AC190D345E6753ULL, 
            0x84C493E197EB014EULL, 0x217722363C1FE21EULL, 0x87C77D7FCA0C4C6BULL, 0xAA31209563460B93ULL, 
            0xA6DB8F71D53D1E0BULL, 0x00671AD50410A65CULL, 0x00D31FE483915A1FULL, 0x6606ABBB53363B51ULL, 
            0x3907B2CC62A53E36ULL, 0xE7824C28D4991894ULL, 0x85DDCEFB41731C7FULL, 0x2F9981FC587B46AAULL, 
            0x5D09D549384A69E3ULL, 0x47153F14F92893D0ULL, 0x5A4A8659BF20D5DBULL, 0x82F3175A453C2A94ULL, 
            0xE1C7ED1A7923CEFBULL, 0xB4AFBE5FF7374C21ULL, 0x499DB91D438F4959ULL, 0xD9AA2AD909973B0CULL, 
            0x11EC4B0CDAAD71DEULL, 0x4E497A250A5F2EEEULL, 0xDC9ECB76FFB3378EULL, 0xF4E0B21E65D4FBF9ULL, 
            0x5912D768289831F5ULL, 0xA513CFADC66268E5ULL, 0xFF8E63EADE036BD9ULL, 0x42F9B97C74A25965ULL
        },
        {
            0x7AB3639A75887C9CULL, 0xBC95C21DD0B91BA3ULL, 0xFED14C9533E385F9ULL, 0xD76FCAE43BF9728CULL, 
            0x874413EFB728A0F1ULL, 0x9C13EB01D998140EULL, 0x3D26CDAA962BFF8CULL, 0x691DBD279B49BA8CULL, 
            0xD294E96F4D9EEBA0ULL, 0x1D121AF1527C6E80ULL, 0xDF1873169AF023FEULL, 0xE93B92118AE8C313ULL, 
            0x3F000F4C9FEE8147ULL, 0x9DDB1CB072668DEDULL, 0x771513A7AAC510FFULL, 0x3DEA499EF9B2AB08ULL, 
            0xD0D086CE81B52BB5ULL, 0x94060E5EA7BC9822ULL, 0x34F792C7C09E7885ULL, 0x5571DF535D576218ULL, 
            0x0D42369F30B69DC9ULL, 0xA6D69D015821BFBEULL, 0x310D025E0312E181ULL, 0x1EE0D3FFF6C857E4ULL, 
            0xFDE1A4BEEB3FB501ULL, 0x026D5B48B8C1EFF5ULL, 0x2E3E3F2C87FD8CE3ULL, 0x35C54B92BC034E68ULL, 
            0xE3C99B41F3BF832AULL, 0x5DE1049CE85E2618ULL, 0x9CBCFD8968175662ULL, 0x893642D79F37106DULL
        },
        {
            0x0470B59FE849E9D4ULL, 0xA4719F8D38AB7AEFULL, 0x7F587D3343A56B5AULL, 0xAE068529D268FAACULL, 
            0x1D465A9E45EA3602ULL, 0xECC12648E03EAF3CULL, 0xF1618A8B09E718C1ULL, 0xCF10F352E474A399ULL, 
            0x883561FA7B415B70ULL, 0x212E48E209062BE5ULL, 0x4D578B96D7CC0A9CULL, 0xC890598E0D80E053ULL, 
            0xBE892F1B25F16F2BULL, 0x001B4B0A6AD6D1B8ULL, 0xEAB95A841B7748ACULL, 0x525BEF10DCCBCA68ULL, 
            0xE3AAE2FECE227FE8ULL, 0x5AA31DFF4931D3D8ULL, 0x157DA65429240B36ULL, 0x017C38A5A9AC37FFULL, 
            0x1C6017547C8CFE94ULL, 0x5BFEC195060420FFULL, 0x1A277B7AB4D42C6FULL, 0x0204BE3720D88281ULL, 
            0x14217BE535BED025ULL, 0x6E5DF9E69A89E4C1ULL, 0x52632FC625B8CDBDULL, 0x8DABF858477142D9ULL, 
            0x7C3A08E601B827FCULL, 0x9E3FB9956B509DC6ULL, 0x01BC8E3F864CDB20ULL, 0xAA3049FD43506678ULL
        },
        {
            0x80F72090C6D56B20ULL, 0x12AA6BCF0971B73EULL, 0x7628BC1250A2AE21ULL, 0x25636A5879748507ULL, 
            0x0514A106839A64D8ULL, 0x3CC2ABA3F286369FULL, 0x022CB3ADFE2091EDULL, 0xEF9BAD614A3B49CBULL, 
            0xFF7E35085457519AULL, 0x29DC158A65557B2FULL, 0x035937415AFD90A9ULL, 0x45DA277B1C28FC21ULL, 
            0x50C955DF2EA307F9ULL, 0xBBF1D86179B998CDULL, 0xE59A734EF312924CULL, 0x704148C79E5B8AD6ULL, 
            0x5DC0638C0225E35AULL, 0x8CA2E229AEA1EDA8ULL, 0x2F998DB5F4DDEC4AULL, 0xA654ED361C14962AULL, 
            0x364A3033BB6158C9ULL, 0xD3045B3F56D0A234ULL, 0x6D53C8798E6452C8ULL, 0x5781EE4BBF28FBBAULL, 
            0xB943BBDE66EEF9F6ULL, 0x6F51F3DEB5D8BA41ULL, 0x21346E36EDFB8F1FULL, 0xE0484BD67D057BC0ULL, 
            0xF108FCDD4D956CABULL, 0x2D251BBC204CFFDCULL, 0xD3E777425D2C7E03ULL, 0x3A2DF4943B5CAC27ULL
        },
        {
            0xA8A91F38AD35DBF9ULL, 0x6DF5781289C8C0CBULL, 0x382A3FDE95FD7D26ULL, 0xE3A4E6325B9C5223ULL, 
            0x8989CC3E936A309AULL, 0x6EC603F4A319533BULL, 0x1C3903CC5B98C3B6ULL, 0x13CE2F7B8CFB0C37ULL, 
            0xE44FE9AA3C988A69ULL, 0xEFEC70650526F117ULL, 0x91A2607339B29931ULL, 0x895B85F8223E63C5ULL, 
            0x8C3531569F8D3005ULL, 0xC75E906192F6F6A2ULL, 0x66AFA9E002C90F2DULL, 0x5F16CE5F5E434C2FULL, 
            0x30E93D4ED107793EULL, 0x914724F62EBB6E55ULL, 0x36D6E37BEE40EE1BULL, 0xD3B01D3513379E58ULL, 
            0x45BB1FD6C5D379FCULL, 0x62A15A5CAB5A66C5ULL, 0x3615385A4A166467ULL, 0x1F774AB298C34C30ULL, 
            0xDBCEE11CD8B9216BULL, 0x968BA6D5D2C579CEULL, 0xF2E724A8865CA233ULL, 0x39C259E92D73AB2DULL, 
            0x9D7DD86A90F212E9ULL, 0x8A885E59CADE96BDULL, 0xC20334B18EDA0315ULL, 0xE289C739A2D7B3AAULL
        },
        {
            0xD968E743541779DAULL, 0x67A214CB609A0EC2ULL, 0xC3DD0F73673776EDULL, 0x4302420C0BB97636ULL, 
            0x52C8794BFBE6A57FULL, 0x9CFB8E9F4676FA84ULL, 0xD3E14C623A5DFAD7ULL, 0xD5BF9886C7F667E3ULL, 
            0xE1680F4A5CF8CC75ULL, 0xF3B5ECDF6111CC15ULL, 0x53748823B7FFCF77ULL, 0x2EEA5030250C607BULL, 
            0x7C338EEBE40E7870ULL, 0x3168A58BD65D3E3CULL, 0x7192EDAD17094208ULL, 0xE8D7A149E615B206ULL, 
            0x4F90E4548E3D21F4ULL, 0xD70ECBCEE4EB14ABULL, 0x1F97C71F62AEB868ULL, 0x5F3F0339561BAF47ULL, 
            0xC0112B4BE98ED99AULL, 0xFEFFB65E3EF1CC58ULL, 0xE1AC68905D192F8EULL, 0x58C259CC8CD5E11EULL, 
            0x00E87A3890D185B4ULL, 0x878ED1C3CF5C7097ULL, 0xD362D97EDF1CFAD8ULL, 0xDD7FF3D4D145106DULL, 
            0x46DCD4196FAE1AFCULL, 0xD3A388CC1B96CDC4ULL, 0xDF0D0462DE8178EAULL, 0xF5CEEFA9F0060E49ULL
        }
    },
    {
        {
            0x1D332FE98C004971ULL, 0x9C672A9B65AD4952ULL, 0xD6365700976D4677ULL, 0x6DDA6A9B8A50CEE2ULL, 
            0x3552BD8A1475060BULL, 0xD6C77B53D7138286ULL, 0x8B51D61F91907BDFULL, 0x306D6779DAEB1EC2ULL, 
            0x6CA5C4AB4D5A200FULL, 0x105A3440EF4BC1D9ULL, 0xC59A37FE0613190FULL, 0xF28AF2FC68185663ULL, 
            0xBF3F1FF192A55FBDULL, 0xA1B282567258F2A8ULL, 0x1BB131E213358713ULL, 0x8A1238117B3224D5ULL, 
            0x140E58DE496C51BCULL, 0x1649CE4110961730ULL, 0x0FF4B8C665FF0D94ULL, 0xFDF56AF5743B60B0ULL, 
            0xD5FE3D5BAF80FAA5ULL, 0xE4A2560EFFAD6945ULL, 0x22BC4896560FDB2DULL, 0x7F7C95336BCFC140ULL, 
            0x3F50E90E734DA1DDULL, 0x7717F817DB183261ULL, 0x42AABAE75A32BF71ULL, 0x9B5C91B3A40C582EULL, 
            0x1E72EB18F214EAC0ULL, 0x725AC4AA42F2C54BULL, 0xFE2E0B17073A63B4ULL, 0x9E33FB224A1B5448ULL
        },
        {
            0xFCE57F18835C0DE1ULL, 0xE7D977AA155D8B71ULL, 0x8C6EA619F5007AD0ULL, 0x5483C67A2D20B856ULL, 
            0x5503D52AC9C23243ULL, 0xCE51640463AC6AE8ULL, 0x6DFED82DD5A263A1ULL, 0xAC84ECF0B92A184FULL, 
            0xDB92591B52DC9117ULL, 0xB1DA8709A4D89CD7ULL, 0x240E7EAC177601ADULL, 0xE4F8211C297662BDULL, 
            0xC2DA528CA550498FULL, 0x37FBB706938B682AULL, 0x827BA80905FFDC90ULL, 0x63DF88573137035AULL, 
            0xB872E243ACAB18C2ULL, 0x539581586A6BEA2BULL, 0x2E958282FA8557ACULL, 0x21BA68B7A733026DULL, 
            0x3F040282C5C9FB74ULL, 0x51FDC04DD82D5959ULL, 0xAA1E4752FDBBEE1AULL, 0xF07683B3E9D7413CULL, 
            0x283601D585E701ADULL, 0x880572883298D3DBULL, 0xDCE13D477425E035ULL, 0x4AD2E9D0A50EA0A6ULL, 
            0x3AAABCE59126ECA3ULL, 0x56DAC5FAF55419B7ULL, 0x0DB2B68318071D94ULL, 0x8ADD278B7B9B1F27ULL
        },
        {
            0xEE3206FE1992636DULL, 0xA269A88AD269D479ULL, 0xC756291D32635AE1ULL, 0xACBD15105FFD180EULL, 
            0xD5975F1F52F0482FULL, 0x792E67FC5A63FF3EULL, 0x33AFEF37528E48D2ULL, 0x592EA063EBA7CD85ULL, 
            0x2672D6C606687EFFULL, 0x3150CB650038BCF0ULL, 0x0C36115C8A3F7622ULL, 0xF0CF0B5BA6F5E6E5ULL, 
            0x5249622BC889C8DBULL, 0xBB02E1065AF11EF7ULL, 0x58899DBDC0E1B67EULL, 0x2F2BA3C8FEF680ECULL, 
            0x4FDE6854E3F423CBULL, 0x236FBD230FAF5086ULL, 0x2A496909D5216F89ULL, 0x4ABC844CB2E36CB1ULL, 
            0xF1EB836917D7C3DAULL, 0x5596607938099F21ULL, 0x43FA7B85CA689F7EULL, 0xBAB8FD164F7D942CULL, 
            0x33FC6484931D095BULL, 0xEDE6162C3BA9D2ABULL, 0xB35832FA3B11F0ECULL, 0x8287580BE40298A3ULL, 
            0xBBEEE7FA7A4BE096ULL, 0x1F3C176232DF430FULL, 0x97AC7D8AD438DDFDULL, 0xD7E2CF39A8F425FEULL
        },
        {
            0x5EAD673D6E10F9ABULL, 0x3FC953303DA13A22ULL, 0xAD19B34B269A53E6ULL, 0x40C1148D506C64F4ULL, 
            0xA91AF41DDE1D63DAULL, 0x5F893A21722ABA79ULL, 0x768F4CD8C8E1640BULL, 0x59460AF4A8F7C320ULL, 
            0x1D5381B722073D55ULL, 0xA7A63233B61BA856ULL, 0xCA2F2798D1AA2F8FULL, 0x8AB92C17D58F2FCCULL, 
            0x94B7FD9390F41790ULL, 0xD51C9AEF6131A83DULL, 0xEE2E15C8F32773DBULL, 0xBD056FEDDFFA647FULL, 
            0xE2C3F549AE4C5376ULL, 0x74D3AC6CDFF5E25FULL, 0x94A25248AD7DD14CULL, 0xA5D14C748F072243ULL, 
            0x80477E92522DAD19ULL, 0xF43475C3F5FB9AA7ULL, 0x87DF28239F2DAFC9ULL, 0xE25552FEE32C593CULL, 
            0x9289981DE2BA565AULL, 0xCA3D35E069721A4FULL, 0x257DE0EABA10C482ULL, 0x05D260EEC2BE56AFULL, 
            0xEDA6CE17555CCDB4ULL, 0x7F5EAACEDB731CFBULL, 0xC4A43BEC93EB4FDFULL, 0xC99B721DECB5F48BULL
        },
        {
            0x46755B7556FD055EULL, 0x4FC3BD4717DE6F13ULL, 0xA46D55AA49E6A348ULL, 0x141A13C351450F0EULL, 
            0xCA9F5D79633DB239ULL, 0xBD2049E445BD3FBEULL, 0x979FFEAA033F2AA1ULL, 0xE3E95081181FE3F9ULL, 
            0xC0621F1191E9421CULL, 0x939ECE751B428941ULL, 0xB7F1477B965B08CBULL, 0x6072D02E2EF55876ULL, 
            0xA2A1229E1D98D879ULL, 0xA65738FAA067B37DULL, 0x9EB8193D6050185AULL, 0x062D499DA66F7178ULL, 
            0x469F25FED92047CEULL, 0x3EE1F8C3CF1E51EAULL, 0x3F1928350F247730ULL, 0x5D54D570B2EEDFA2ULL, 
            0x62649836C0C38693ULL, 0x50A1104EC8420B27ULL, 0xE0D93E2B61757606ULL, 0xE9A36D2D2F49AF45ULL, 
            0x7F86FAF79DC0B6EBULL, 0xB5F888385CAC0432ULL, 0xD230A58677894229ULL, 0xF90771B18A21BF9BULL, 
            0xA339514C3B496C59ULL, 0x689BC320DAB3F8ACULL, 0x889ABF2F8595CCF4ULL, 0x8B14BADC66E1E3D7ULL
        },
        {
            0x1F70FABEAA4774A4ULL, 0x3415446307626B66ULL, 0xA3C0225ACBA93B78ULL, 0xEB70E2D9D495D139ULL, 
            0xB0C06A4AC220E3E0ULL, 0x13B600C005D38D50ULL, 0x82E5E9438A2D37D9ULL, 0x4570A27102EFD40CULL, 
            0xD35CDBCBBD6E5AB8ULL, 0xDDE4394055E0A41AULL, 0xFDCE1C8ADED2D58FULL, 0xBF35C04BD7A8A30FULL, 
            0xBD9E5CB3880C54DAULL, 0x84C33BDEF0EADD54ULL, 0x1B94E953D274428FULL, 0xD4718680D9201AEDULL, 
            0xC252B3DEEEC75674ULL, 0x6CF25A71FAE129AFULL, 0xCEC2AAFAFD43D14EULL, 0xE712AFC3CFD13CCEULL, 
            0x64B939E5D550D048ULL, 0x2E93DA5629F0E1F0ULL, 0xF9EE1E92E2AD09BFULL, 0x97AEDCBEF11C751EULL, 
            0xA01A5F6ECA296808ULL, 0xA06179699FC93B9EULL, 0xB27758513B7CCDCDULL, 0x16BB953C0B19DAFAULL, 
            0x56C77F45BAA8F021ULL, 0xF742F287238F88AAULL, 0xF36A85343C75BF02ULL, 0xC6727E8D782250D2ULL
        }
    },
    {
        {
            0xD2093A45A55AB102ULL, 0x6244B8E4A312D991ULL, 0xE30E287AE94DC905ULL, 0x65C504632B076227ULL, 
            0xA12451013764F088ULL, 0x9206D0FC2BD9500EULL, 0x8D6CD3901074DF3EULL, 0x33640B414525BAC1ULL, 
            0xDB89D6898C330084ULL, 0xDCD4B0D8311CFF96ULL, 0x13654FA6FE10E3E0ULL, 0xDF44F39A23B190F0ULL, 
            0xAC36E4E009416CCFULL, 0xD49D3DA18E4B42CAULL, 0x69196DF00E7D675FULL, 0x59530C3251E49975ULL, 
            0xEF6309F660675252ULL, 0x1323AF888427DA8FULL, 0xB65DC180BDC0D92FULL, 0x900981AFDB56E3A7ULL, 
            0xC016954A59FECC30ULL, 0x3D19F1E84C049341ULL, 0x50FA46F061B5D2E3ULL, 0xC095CA12CFFD167CULL, 
            0x5D38C7002A985958ULL, 0x43B835AA51F6678EULL, 0x95D5E0741CA647CBULL, 0x9396F16E676F3116ULL, 
            0x78EBAF6FA45521D7ULL, 0xFB3B2AF5B762FA0CULL, 0xF15BF8265C401E8DULL, 0x36D3E800AF76C5B1ULL
        },
        {
            0xF8A63589909DFE95ULL, 0x98CBBF5CEE38E90FULL, 0xACA4F9A5DB1F11CEULL, 0xFF706F006D2FEF9AULL, 
            0x5D2E4D37CE6C95BDULL, 0x30CE7DE210C044DCULL, 0x4EB0539EE7C53B54ULL, 0x309C2FEAA5A6F705ULL, 
            0xA1FAA5C729F4A623ULL, 0xEF6FD60D708893A5ULL, 0x1C7E52384593C3CBULL, 0x8A4D71B5FD20779CULL, 
            0xC1D311A12EF2DD97ULL, 0x86A6CF2CBE78BE10ULL, 0xEF9F122A70C23358ULL, 0xF4B4A1E8EF805B75ULL, 
            0x80940C4DA0D3394FULL, 0x8798D21ACBBE01E7ULL, 0x6B79FA66E2736A3DULL, 0x8EB2806FE96C56ACULL, 
            0xB33BEB7388B62C13ULL, 0x3EFB382EF1384379ULL, 0xC6119FA5FF86209DULL, 0x52490D9997354803ULL, 
            0x05C31105715E6B10ULL, 0xCA505B6BBF19E5E3ULL, 0x7CE238E76519F703ULL, 0xA90271A212C86DDEULL, 
            0xFBE153D82C9586A6ULL, 0x94AF7D1CC02F8C17ULL, 0xDD239E40D9A6C6CAULL, 0xB2EB28CB1E583E40ULL
        },
        {
            0x4EAC857C00E8218BULL, 0x1BFF4800A6B9E21BULL, 0x4400775039DB0EDEULL, 0x71046D6021A9A40CULL, 
            0xF58E17D774F3A45CULL, 0x4E2C68078E348802ULL, 0xE89E2A70DE3FCA55ULL, 0xFF0B544E36244938ULL, 
            0x8287B0908BF2F3DEULL, 0x1D5E20176C786A84ULL, 0x89257E80671F24E2ULL, 0x775990E453BA49C7ULL, 
            0x254EAB43FA717FA2ULL, 0x09D6F12B9D62F063ULL, 0x880182C1F4AAEECBULL, 0x521A34DE1BE304EAULL, 
            0x1F903AFC38538580ULL, 0x5E3F9641635738B2ULL, 0x4927D43313D2B50CULL, 0x7E6C09E2A619B01EULL, 
            0xA95D3308A7CC27E8ULL, 0xD88B7D6F4C9DCE02ULL, 0xADDB8DAD6798F610ULL, 0x4B13D26CFC2B357CULL, 
            0x0DD0325BC755DF5DULL, 0x43F33743B1B6CDF3ULL, 0x1CF73B1D2EB7BE11ULL, 0x78B2FDA124A5DD6CULL, 
            0xE2556649BFE62C77ULL, 0x30C993F95A0D8BB1ULL, 0x28C171491939D829ULL, 0xCF2B2F0C52D2CE17ULL
        },
        {
            0xA9ECD421ABFBAFBAULL, 0x72A84EE10F4AC704ULL, 0x2B8A018E2D415B27ULL, 0x9FE84A7CD35EBDE3ULL, 
            0xCCF597970542392FULL, 0x4F8A11F6ADEDE6D2ULL, 0x105D541788AF1078ULL, 0x31320984868FDCBCULL, 
            0x99DFF10EE3426DBEULL, 0x5CD1EFBAB14BA0BDULL, 0xCF4E6D7A8F106E2AULL, 0xEC86D40D4334162EULL, 
            0x52058993CA7E2B4BULL, 0x425F251F6710269BULL, 0x04B47357DAC5FC5EULL, 0x1FEB6B4409EAEF80ULL, 
            0xF275C1D598DA7375ULL, 0x061901E2933BE951ULL, 0x726B098368C50139ULL, 0xCAB733046EC4D7A4ULL, 
            0xE8DE91CB82C04117ULL, 0x64A45E45BB3F425DULL, 0x11CF32A1CD4E902AULL, 0x8E02A2B2D95E0918ULL, 
            0x6D43D938E10D308FULL, 0x2CA1D6315720AB9AULL, 0xB76A37878633D493ULL, 0xD9CACFC27486E509ULL, 
            0x38F96CE19C68681BULL, 0xB87B3A5CB8C62FA7ULL, 0x541D51BA3EF00859ULL, 0x7B2C1510C8B7DD64ULL
        },
        {
            0xAF0C77C7209EF2C0ULL, 0x6A192FCB94ECAB12ULL, 0xD8A57AFD2CF2CED1ULL, 0x7551E2B71AFC5307ULL, 
            0xA0F6C5F8A74B70C1ULL, 0x9874043FA330AB2BULL, 0xC004BDF5FB33A235ULL, 0xDCD1377B41178C49ULL, 
            0x80A1A5FD79E6F846ULL, 0x1E1D803943308998ULL, 0xA27B17F7712B2275ULL, 0x6E5F544FF6B6BD55ULL, 
            0x15504D9DE72F171AULL, 0x21A0AC0BFAE112BDULL, 0x6D4D5650CA5F2977ULL, 0xB559147C7220FFA9ULL, 
            0xA67691D69E22ECEFULL, 0x123B1D37E3DB1209ULL, 0x08C407A90D53EFCCULL, 0xA61421AC6C1B6C35ULL, 
            0x5691F702ED16F374ULL, 0x628A383A3A965B1FULL, 0x6AF7271CE7A47296ULL, 0x09B85DDDD2A8263FULL, 
            0x0BB73630453B2945ULL, 0x1F255354F3990553ULL, 0xC33B55EF2404157EULL, 0x472D60C1A43A45B9ULL, 
            0xA283523235B0855FULL, 0x5834F14CAA073976ULL, 0xBC6F8E5D3909E331ULL, 0x5EC1B290D6A7EBF7ULL
        },
        {
            0x98A396B653BE5843ULL, 0x1269ED8629F51D91ULL, 0x513D05161460C770ULL, 0x8C457F71C332C9BFULL, 
            0xB041F2BC20EAE8E2ULL, 0xCD8179AFD4D43B39ULL, 0xCE762C5E6536A02CULL, 0xB1F708FBA1FC2C1BULL, 
            0xA553A311A8B8AC95ULL, 0x0BC529108CE57D0CULL, 0xACB9407122FAE023ULL, 0xA9F3600AA8C064EDULL, 
            0x28C56C85C2BCEBFCULL, 0x89D95C480BD2F88FULL, 0xD27F6AF1C6F49D6BULL, 0x4560C51EA267F041ULL, 
            0x480E99A787DE084BULL, 0x423F1E46C4DC1B2CULL, 0x3D7D6BED8259F38FULL, 0x05E450EF5397A463ULL, 
            0x4A329E9FBA33F993ULL, 0x3DB53FE5D2AE1A38ULL, 0xC5A340EC31649578ULL, 0x11D6237910530F96ULL, 
            0x92E6A7DAD9967B36ULL, 0x27D89BD2B4C6635EULL, 0x9FBAD4D3D53E54E0ULL, 0xF956E3B2D07656F0ULL, 
            0xC1E20A553F7D7087ULL, 0x3FDD57E817F9A52CULL, 0x04EA4BCCB4E9F6B9ULL, 0x6FA881D1E03AB0CDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseGConstants = {
    0x5AE5EA2B005EFE7EULL,
    0x341DF29C60908FAAULL,
    0x346CDBA1B9AC4DC0ULL,
    0x5AE5EA2B005EFE7EULL,
    0x341DF29C60908FAAULL,
    0x346CDBA1B9AC4DC0ULL,
    0x37761A5DCF822FDAULL,
    0x410C1AE7FC51891EULL,
    0x8D,
    0x08,
    0xF6,
    0xAD,
    0x52,
    0xF5,
    0x63,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseHSalts = {
    {
        {
            0x82737D3F680BD060ULL, 0x072E2B189944030DULL, 0x2585116511F5E96EULL, 0x8CCF07700BE6C166ULL, 
            0xECC4259830EEEEADULL, 0x4559E5A2E3C123E7ULL, 0x355C363BDF225659ULL, 0x378F4841DC207437ULL, 
            0x0FC5903CDBC5F1C5ULL, 0x61A88CE1441C75DFULL, 0xA6A5C15F6173861CULL, 0x184B83C300AC3BC9ULL, 
            0xB886E9DCA4433A9AULL, 0x94E701B9AFD61915ULL, 0x840FB77B3044C3E7ULL, 0x234360F225BC9C1DULL, 
            0x0A176D9896100245ULL, 0xEBFCC9EA047B3610ULL, 0x2FE7E5779C48471BULL, 0xD29330EA3AC81928ULL, 
            0x49E97796961BEADEULL, 0x75707E50AFCFA607ULL, 0xD400465EF336B639ULL, 0x2087D84556BE30D1ULL, 
            0x9C75731630B989FEULL, 0xE2AFC55147D8E0DFULL, 0xB287D2C589F55CC3ULL, 0x639304C0E4DFBE4CULL, 
            0x4523F4B3CE9FAE87ULL, 0xDC5177A4DAA06567ULL, 0x36521D28C71154ECULL, 0xF7D2B156AAC8F4E5ULL
        },
        {
            0x0635345B729E361BULL, 0xA002CB8001FDB2C3ULL, 0x3A09ECC49EE0C74BULL, 0x727F77444EAA9BA7ULL, 
            0xD5D13C3C7310CDF3ULL, 0xC1982E04E89508F8ULL, 0x38D9BF3F40A3398FULL, 0xA63E7B54F2C6591FULL, 
            0x0F6167D71921EFB9ULL, 0xFFA3D702CFEB5D30ULL, 0x34B275B70347C2D9ULL, 0x377EBBE05D70A9F1ULL, 
            0xEE9F2AE0D5EA1750ULL, 0xD9C07BC693BF9E63ULL, 0x4A0BEF065D77F7CBULL, 0xDD328409C5EF7892ULL, 
            0x6DACAF7ADE9BF32AULL, 0x04D16EC92F08CC79ULL, 0x905320D5822B3026ULL, 0xE692D6212E7014ECULL, 
            0x678C953C27331487ULL, 0x99578C8A5436D188ULL, 0xB931E85D817F8B9AULL, 0xE4F532E76F318920ULL, 
            0x56A5064122D42830ULL, 0x57DFDA63184F8BCDULL, 0xC79E62178D8CE599ULL, 0x41E1007C5E0647BAULL, 
            0xCC9CAA2E2A265880ULL, 0x607D97B16F56CC93ULL, 0x12FC45E24EA3A525ULL, 0xD639F56A5ABB5B3EULL
        },
        {
            0xA1C36D84DA343139ULL, 0x6ADD636EFEE095A1ULL, 0x51DA01284ADF9F99ULL, 0x5DEF224DFDBC28FAULL, 
            0x78AE8DE685C156C5ULL, 0x2602BD6D641F3FEFULL, 0xF0E10BF7E617471EULL, 0xA8386D00E92CF92FULL, 
            0xFBF4FB814D81A9B9ULL, 0x339B51E95C360875ULL, 0x55495AC8020B0A2AULL, 0x41E4A7336D754408ULL, 
            0xD648478DE6FFCE15ULL, 0x21D9CD6C76F20C67ULL, 0x49285EDD64B6BC42ULL, 0x288FD0F4AAEF8CD5ULL, 
            0xBD84031057A1F13CULL, 0x45D0980E40E5EDF5ULL, 0xE23F33DE27FE1A23ULL, 0x40F0C7FA92137D9EULL, 
            0x3466D506CEEA530EULL, 0xEC4B012557A24682ULL, 0xA1AF2099A65D928DULL, 0x5D7738C7354EC6A3ULL, 
            0x4A12CD6C42601718ULL, 0x3DAC5E6EB15D0AAEULL, 0x09A58484825E0595ULL, 0x19A0DE7549A7FD56ULL, 
            0x02D8273B70488101ULL, 0x7AC089CA89028235ULL, 0x43C307E4ABC0CAC4ULL, 0xC8AE210D967EC79AULL
        },
        {
            0x7FB304163439939DULL, 0xD2750DCD73AF4925ULL, 0xD68CDA1457994873ULL, 0x8BDF9AD69DB409C9ULL, 
            0xDE30C7198C193B8DULL, 0x7B846E7A9CCD8CA8ULL, 0x6611E0262434FDD5ULL, 0xC38CB32648E46E0BULL, 
            0xA324ACFFCC1A372CULL, 0xA446ECE3301BCEB9ULL, 0xF1009FB3FCD25A13ULL, 0x892172554C4FACE9ULL, 
            0x509F7999B4FB44DAULL, 0x4679AC16A5115908ULL, 0xB15C46C7D85CC998ULL, 0x6E4AC8D80DD5E8E5ULL, 
            0xE56CD3C92EC1D343ULL, 0x9589389F7934A533ULL, 0x236EA0A36C3E2356ULL, 0xB0570F17B151FD1CULL, 
            0x50C60711895D8E92ULL, 0x55EAE98D16C52693ULL, 0xAD7CC772A5646D70ULL, 0x1E03B1F23E47ED97ULL, 
            0x33113A97398F37EDULL, 0x2DF93C43A0B475F2ULL, 0xD51386194C2D73ABULL, 0x8B2544B26883CCBBULL, 
            0xEFC71926A64A2FEFULL, 0x3A103DB1F6DC5C87ULL, 0xD5CF4B9A2841258EULL, 0xA5C5460110FBF982ULL
        },
        {
            0x2016E9F0347E4F5EULL, 0x060DC5B5463B4F57ULL, 0xF1B960EABA8505F7ULL, 0x02EEEB178697427FULL, 
            0x4BF2C8D52FEED832ULL, 0xD6CF969E69C27FD4ULL, 0xAFE711A476206857ULL, 0x0B9E6FC56CAB955AULL, 
            0xA2120BFCF76A68BEULL, 0xC6D4AA0FC4729896ULL, 0x894CCA60BBB7DFCDULL, 0xF78D2B6851D3C779ULL, 
            0x202223F6BEE273F7ULL, 0xA0CB7D3BBCD0A373ULL, 0xB3C38827C9B7C581ULL, 0x96675E0FAE7EF7B1ULL, 
            0x0BCA72AD76EAF093ULL, 0x987CC3EFD6B45DB2ULL, 0x83662DEA64739A2EULL, 0x72859497E3008A11ULL, 
            0xAC00E77670182E67ULL, 0xE1669C6F109B6B67ULL, 0x655B9F1F2B083780ULL, 0x75E097E197EDB559ULL, 
            0x7B7230426A672673ULL, 0x198DB633129E878EULL, 0x7A7299D9554E3531ULL, 0xAF31883EFEFB37AFULL, 
            0xE47743B4086DACA9ULL, 0x6B0F473A05F62BE5ULL, 0x9FF6E91B7FE0DCBDULL, 0x37BA718DAC21A858ULL
        },
        {
            0x4D40BFC68AE4F8EDULL, 0x2A6DE2DB118EAA23ULL, 0x23F25B3D3C363857ULL, 0x68B802BA87BC615BULL, 
            0x258B10849E9B7846ULL, 0x0584E89F8CC01023ULL, 0x16ADEB1E8464F91CULL, 0xCE23639393DEF6D6ULL, 
            0x84FA2D41265108E4ULL, 0x38152A560BB7A7ABULL, 0xAA9AA44A73D58122ULL, 0xE8A346A62C029906ULL, 
            0x63070E0D11698F3EULL, 0x56D03C2DA9BB428EULL, 0x3B4DC0B47DAA9713ULL, 0x9DA6A425858E69AAULL, 
            0x1BDA3018FC6D0422ULL, 0x61888C32FB9F738EULL, 0x3350A49A71AC2B8AULL, 0xA89A2311603A6E8AULL, 
            0x0D3C292357E97C00ULL, 0x616B617193F6F20FULL, 0x4BC85A7D202BBC1AULL, 0x913A74EBD738640DULL, 
            0xC41E816A4E36D5FFULL, 0xF2A58F2B9F3289A9ULL, 0xB9FBE8FD53AEC1A7ULL, 0xF7313E03CF5E0179ULL, 
            0x4DD07D70D4425F29ULL, 0x6740E16CC4570BE2ULL, 0x02C6E87A85772F21ULL, 0x3E98EB6B5AF196E8ULL
        }
    },
    {
        {
            0x6337916E738FD1B6ULL, 0x63F742DECBF93118ULL, 0x2983D891174647F8ULL, 0x53CD94599D65C8E8ULL, 
            0x4D0697571462BA67ULL, 0x91358538F57C09B1ULL, 0xB781AF17F045A09AULL, 0xA83B60BB895D3930ULL, 
            0x8163F88E9D7FFB7EULL, 0x5A0E69A11DB85347ULL, 0x99C17BB41C9F3B3FULL, 0xF5A8EA7A8CF89A28ULL, 
            0x850DE8CA6F001F09ULL, 0x0E7F67D3C57074FDULL, 0xDDE95DD8475C5B17ULL, 0xF03E4EEF10F9AB5DULL, 
            0xB622ADA8446B3173ULL, 0x27E41164F2303E16ULL, 0x466D7955E45205E8ULL, 0x9E85C38397ED26CCULL, 
            0xF028151CE24EAFE5ULL, 0x0A6E063DC5027220ULL, 0x7FE124A936B44954ULL, 0x27353A00EC8F4A2EULL, 
            0xD84F0B4A48B97263ULL, 0x74E2AFA1C9C4D8F4ULL, 0xCD6DF8FD55EE2A2FULL, 0xFCAE5F3FF325D3E5ULL, 
            0x897485C5E35802FBULL, 0xC0C60CE206385E80ULL, 0xC7807813CFB27659ULL, 0xD8EE2C5E254CFC65ULL
        },
        {
            0x061A1EBD8DCF5BF6ULL, 0x9420610050882FD6ULL, 0x402312988126584DULL, 0x9CA09D8BCC3FF879ULL, 
            0x61EF0FFDA571F229ULL, 0x2FCBAE5DAEF408E0ULL, 0x14D3741F1792F084ULL, 0x1D80BE129968D803ULL, 
            0x55E26B78C3B2B2C9ULL, 0x09513C879B9C5B5EULL, 0xC186C1702F5EF375ULL, 0x3098698B874C1AC8ULL, 
            0x901BD22A539CDF14ULL, 0x50344E04DEB55D07ULL, 0xD9C7D8C4E15F37AFULL, 0x561CA8BA6FC4F52BULL, 
            0x559D3376CF764D19ULL, 0xA3F00CE5D74665E2ULL, 0xC2837F15606DD8CCULL, 0xB109EDB29814B7B8ULL, 
            0x083E6EB542E3C515ULL, 0xF235614D6F0DED17ULL, 0x7711AF6CF54F6AE0ULL, 0x4B9CEF1BD15A1C22ULL, 
            0x72DD56172CA735F6ULL, 0x3E02E68609E24089ULL, 0xF40F9395C132A508ULL, 0x13F44C89BBF0D632ULL, 
            0xA882BC7934664F67ULL, 0x8B7A5EDA928A58CAULL, 0x1AD28F3E01BC3158ULL, 0x30CC5A14597A9CDEULL
        },
        {
            0x7A77AE282D812B6BULL, 0x0A0A06090F19E38FULL, 0xE2BA979021EA1F03ULL, 0xB8F4FF55538CEC10ULL, 
            0x08E756F5593A4BA1ULL, 0x0508ECB1BFF38C37ULL, 0x00AEA457D90A2281ULL, 0xA72F870309F844CDULL, 
            0x90E7C5DD74B54212ULL, 0x40006BB99DC6BDC5ULL, 0x01EE9A5E1351C41BULL, 0x30FDF47BBE3FDF34ULL, 
            0xFEFB54717406B1B4ULL, 0xE67A685BEED255AAULL, 0xD00CC209B2BD6223ULL, 0x37D43F9C2A37D310ULL, 
            0xC2507A92308B73D3ULL, 0x4A64AC05C5B00BA5ULL, 0x3B6EB3DC8BAB748DULL, 0x46124CD7E808BD52ULL, 
            0xE1AA4225D2409806ULL, 0x5BEAFFB51E89FE40ULL, 0x436E58C200A81E2BULL, 0xF330C9B636137E29ULL, 
            0xE7BA26325FEAD9BAULL, 0x1DAF638264CFD1D7ULL, 0xCF4E2EBBB68CACC2ULL, 0xC32FECD8EE54EC5CULL, 
            0x1F407C67D82310D1ULL, 0xAF9993AA47144A52ULL, 0xF767E3391EC99961ULL, 0x1A3D0FB9DFC042ADULL
        },
        {
            0x976B03E88EEC5C1DULL, 0x364972F650585ED2ULL, 0xD78880626A38CCD0ULL, 0xF3B46498FA5792E7ULL, 
            0x124738FD27D803DAULL, 0x8FFFC3E72DA0832CULL, 0x884288388DEDFD83ULL, 0xC980429BB681E249ULL, 
            0x58A459D245D334B4ULL, 0x6BC3708621DD8EC7ULL, 0x261ADED29B4E2480ULL, 0x335636D436E1E22EULL, 
            0x30A219321B8D60BEULL, 0xAD969F6A0607DAB4ULL, 0x69482CAE9BAA1F8BULL, 0x439089CE421C8192ULL, 
            0x9F8D6A1BA3B08CCFULL, 0xA727FE00237F2483ULL, 0x221453A05956B7A5ULL, 0x381B0FD6F883A375ULL, 
            0x43EDC09EB438D29EULL, 0xA5532B1C7D79CFF8ULL, 0xF0ABF8548BBD6B4AULL, 0xD7AFAE2CC0AE3757ULL, 
            0x9917322882160544ULL, 0xE5EDF93A780C9B69ULL, 0xE76DC94A649BA2AAULL, 0x6E07AE7A0AAD1D7FULL, 
            0x304028E985BAAE8BULL, 0x306E5C92AFCBE3B0ULL, 0xFFB1A976AB32533EULL, 0x544A251F5829B6E3ULL
        },
        {
            0x205D32D18CE898E0ULL, 0xF29686EACC54B897ULL, 0xEAD837E0F255893FULL, 0xC38414295F425A3EULL, 
            0xC9E9C17B46BA208EULL, 0x57BC47185167CB07ULL, 0x1B685B4EAB244444ULL, 0x42A7A2BB0888B3C3ULL, 
            0x01BC7428540C731CULL, 0x8D61E635F63D803FULL, 0x567228281A181A3CULL, 0x862AC88B00C57FB9ULL, 
            0x4327256FBF58B07DULL, 0xF159BFE07567C5ECULL, 0x4F46F4993962D261ULL, 0xCE79FB04982B3D6AULL, 
            0x6552623A8623013AULL, 0xA365AD657A6F9E6CULL, 0xC5C9CF5BB31772BEULL, 0x045E85EEB300258DULL, 
            0xF3E1CC1DE2A4F682ULL, 0xDAB98D87E5F6862CULL, 0x7376987A48A2ACF4ULL, 0x37546ACA6B567AF9ULL, 
            0xC5001440E04D465FULL, 0x3C49C7A614658CD4ULL, 0x54509F5EDC5D3FA7ULL, 0xC59E434F8B2E2848ULL, 
            0x2BCEC63A54CECE92ULL, 0xA004CBF7D9E8FEB7ULL, 0xA1091C1C666B9C67ULL, 0x0AA1E919E0F5E374ULL
        },
        {
            0x8F68163E022EA0B8ULL, 0x507561BAD0BEEB5EULL, 0x63562902DBB8881CULL, 0x747EF370C1B0F111ULL, 
            0xCD880B4250898827ULL, 0x73A2BADD5F8560D3ULL, 0xB6E8ADB3F66B88C5ULL, 0x38A405979D84E82FULL, 
            0x877B9C8F105A0B56ULL, 0xDE6FFA63ED9E765BULL, 0x992B7337E0E58DADULL, 0xABD37724E9638BF0ULL, 
            0x33E059A4C20BACD6ULL, 0x8DE86C70B0DE254BULL, 0x2A32102F6DA3E899ULL, 0x83E7C831B4173A2CULL, 
            0xC80D5A32746588CDULL, 0x18A0A4095DB160DAULL, 0x7865ED243A19D2D1ULL, 0x1ACE4F7BF54608F1ULL, 
            0xBF5F2A113789741BULL, 0x5A322ADF06084947ULL, 0x595BF90A233FD990ULL, 0x34BF1A9098790DB5ULL, 
            0x97CF9CFEB9FD15C2ULL, 0xCE786E71043FFE6BULL, 0xD26B3169EE2FD654ULL, 0x68E6EE7FF5E61D53ULL, 
            0xB20A69D09836201CULL, 0x82EA804134609C83ULL, 0x8CCE2378E044FFF1ULL, 0x5B805BA3889EA1D6ULL
        }
    },
    {
        {
            0xDC4E5B8FE160D78FULL, 0x0D34B21245BE7F26ULL, 0xCED4C5ED4A500A2FULL, 0x2D5E1AF547724CFCULL, 
            0x0E35764236B4CEA6ULL, 0x2FA10276556FF316ULL, 0x65E5E607A0A5FC8EULL, 0x488C8F9FAD08DFF1ULL, 
            0x8D8A65CBC5F21BBAULL, 0x990F2B39927C26A7ULL, 0x506DC9718C08C828ULL, 0xB41EC3F390093E7CULL, 
            0x646BB36735F912E9ULL, 0xFC7242EB80E8387FULL, 0x144D28743D72362FULL, 0xB47DCC8D9EBD4806ULL, 
            0xE98680F28B1059FCULL, 0x4F2EC5A8D247B794ULL, 0x03CB3C05B61371E3ULL, 0x24F7B2CF7F87EF34ULL, 
            0x8C6E94C063CAA6F9ULL, 0xC456969B1A3011EFULL, 0x54BA82182245F5F8ULL, 0xCAB4125E7AC4387FULL, 
            0x567A8211447912EDULL, 0x58EAABFF5DC163A3ULL, 0x909927EC927FCB59ULL, 0x28404D97D279D608ULL, 
            0x41A6C12C030EBDB1ULL, 0xBBA4C39FBF65CAFCULL, 0x6C1FFC0ADC86F74EULL, 0xF6C61B430EA202A4ULL
        },
        {
            0x7CE21C5E440C78DCULL, 0xE538F5045639BBFBULL, 0x5256CCEBF5923B26ULL, 0xFBBD412324C43118ULL, 
            0x52FFF9A323928B32ULL, 0xA8101184486A2822ULL, 0x68D92B1AF6CD09DBULL, 0x22944C0AE1817CADULL, 
            0x53F9C4356BB6B82BULL, 0x3B1CC6E16D21A620ULL, 0x42CE52BEE3B47F7AULL, 0x4DAB0BFCB6454C39ULL, 
            0x21B2694085628AD2ULL, 0xB7FEAB39527A87FCULL, 0x588E82FFCEACA26AULL, 0x0FCCF514E016CE52ULL, 
            0xEF6188461B153AECULL, 0x5A7A175692B1FB32ULL, 0x2567600E9D1F8EFAULL, 0x2B65047D18AC43F2ULL, 
            0x9F6AF4D8BDB3B901ULL, 0xE8FDC61AB0DF9EFDULL, 0xD369066C6D5AF795ULL, 0x0060B2238E1CB462ULL, 
            0x62BB73BCB254FA3DULL, 0xD5F7004C6616D3DCULL, 0xF00503C6D9FB463CULL, 0xD8490D3D16BAFE23ULL, 
            0x4796537221AA91E7ULL, 0xAE404C0DCB2188EFULL, 0x1B0E75344DFABE91ULL, 0xCFD4E478CC6F22ACULL
        },
        {
            0xCBCB16FF3348F02DULL, 0xA73E451B54715756ULL, 0xC8196D7735901B28ULL, 0x658B22DE4529A961ULL, 
            0xDA4672AFC54AE621ULL, 0x73D404C5980A2042ULL, 0x150ED89A3EB95C0BULL, 0x21FBF0F8C5E8118CULL, 
            0x415A955767036B43ULL, 0x3AAE69E3967F03EBULL, 0x3CC2CE98A1B5703CULL, 0x5015985391C984F8ULL, 
            0x02D11F47B45801AAULL, 0x89CC82DD4CD4CA70ULL, 0x5ECA8F92782D2009ULL, 0xF03DBC51F036A23EULL, 
            0x16D2AEA0D5B723DDULL, 0x5D460F7ED31A187EULL, 0x7E725283714D7E79ULL, 0x16CE6B18B984DE25ULL, 
            0x56526030F64F36A6ULL, 0x4A662F14CA1BE091ULL, 0x2E2CCD60F012A870ULL, 0x5634BDA4F87A44D8ULL, 
            0xD9C967A88E143BC7ULL, 0x68F8BBD5AFB84229ULL, 0x7D751AB21C86884DULL, 0x01F78EC4B5191C2DULL, 
            0x0AF203E64F0D5229ULL, 0xE70CEBAC0160260DULL, 0x633917D7F05C7A23ULL, 0x39B8E44ED6541190ULL
        },
        {
            0x183F0A6F39108371ULL, 0x55B7AFA7F1DF35A8ULL, 0x8772DCA66F45DCCEULL, 0x8FBDA614067202EBULL, 
            0xAA31BFD9C5D412B9ULL, 0xF087BDB290077A05ULL, 0x300857A4BC52BFB5ULL, 0xE396AE6239ED8EBDULL, 
            0xB30259B9E0F4217BULL, 0x3582BADA8E810C36ULL, 0x0B6B6870F44FADD0ULL, 0xC74DBF2E0775EF51ULL, 
            0xC0AC58F797384FDAULL, 0x8752F3F13CE5729FULL, 0xC0C7765C3B6CF15EULL, 0x732CE85D6727634EULL, 
            0x7D4711CD91D5E624ULL, 0xF6B64FF3650B4AF1ULL, 0x1F7AE182E7E61DECULL, 0x662AE4F4FB4FE690ULL, 
            0x2DFFAFA0149F9D80ULL, 0x583E4FAD4A1E4A8BULL, 0x6433BB594208C191ULL, 0x86604DBB1A541F69ULL, 
            0xB0AF04A65A91B26AULL, 0x0FC495831C66365EULL, 0xD139CD1F07F1EBD2ULL, 0xF108979CF655B2F8ULL, 
            0xBEE361FB56C4E34BULL, 0xB3EBA203131EF93DULL, 0x7507D2676FBE433BULL, 0x30FBE30D6FB1E4B3ULL
        },
        {
            0x8760E5F209B4609DULL, 0x0FA311645EEBF3CFULL, 0x95073B57BC70DFF6ULL, 0xC822DF4EFE2AC8F3ULL, 
            0x2383A4F3FA191572ULL, 0x09D9A5420417E939ULL, 0x358DBDF525B4E32BULL, 0xCF67A5BBE199D4ADULL, 
            0xC7708B450F354E8DULL, 0x2DBC600D9A5E48D4ULL, 0xA67E5C9FA1029C17ULL, 0x75C9E961803B4895ULL, 
            0xB6045CA2657FCE25ULL, 0xF2EB899EFA95862EULL, 0xA253CADE9BA3AA52ULL, 0xA6136768A46B1B3AULL, 
            0x52DA8D78690756A3ULL, 0xD638B93F21EAC115ULL, 0xE1B7EA5D10CD5AC2ULL, 0xCE6822D86E8468E1ULL, 
            0xF786FB1D082020F3ULL, 0x2028B6CED77BA19FULL, 0xB8E4ADA6F4371395ULL, 0x15FBAE1B47096644ULL, 
            0xE64218E345DA6504ULL, 0x73A1B0F372C6BEFBULL, 0xA9A507AFC4C838DFULL, 0xEA4721B6678F1BF2ULL, 
            0xF1C82DC43801FD78ULL, 0x99729D66347154EBULL, 0xC764EB600C046D2EULL, 0xC291186E99BCFC42ULL
        },
        {
            0xCFE40E8FCEBF9A62ULL, 0x235CCCE7F15C6248ULL, 0x21B6AC49223FDB7CULL, 0xF55C8E24856ADB73ULL, 
            0xB787169585DCDDF3ULL, 0x677DC1F67F422514ULL, 0x2D8ED194428791D3ULL, 0x6616621A7AE8CA56ULL, 
            0xE7997439F14F893AULL, 0xD1D5647F2035250AULL, 0x05EA11F3EB1B34D8ULL, 0x1DF15D046B3E1812ULL, 
            0x12544F37FA4EFE62ULL, 0x60DE72F9312A6198ULL, 0x84C602428381E20AULL, 0xC554663F88E2D729ULL, 
            0x1AEC8D81ED8E584DULL, 0x0C72C2CAB026DCB5ULL, 0x1E6B32DB1C642558ULL, 0x1D994A35FD26BF25ULL, 
            0xC9900E30E67321B8ULL, 0x5E8104AD95C8AFF2ULL, 0x6555DC7B96C71FACULL, 0x44368DBFB4AFD459ULL, 
            0xCF3D8A4C24F17B40ULL, 0x3FCD8EDE4F6BF536ULL, 0x43180712F2269CBEULL, 0x9FDA10B47B2D1212ULL, 
            0xE50BC10792712D96ULL, 0xECBE10AA42C44ABCULL, 0x1F27758A397EF186ULL, 0x497715CEA88F2897ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseHConstants = {
    0x09CABA348C05F8DCULL,
    0x4A1CFEF532BCD493ULL,
    0x1A4C3FE77184F3B0ULL,
    0x09CABA348C05F8DCULL,
    0x4A1CFEF532BCD493ULL,
    0x1A4C3FE77184F3B0ULL,
    0x1495170F40A31A0EULL,
    0x620E8C3F32E91E89ULL,
    0xE0,
    0xA6,
    0x67,
    0x72,
    0xFC,
    0x1C,
    0x0E,
    0x7B
};

