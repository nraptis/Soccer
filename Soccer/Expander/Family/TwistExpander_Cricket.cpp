#include "TwistExpander_Cricket.hpp"
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

TwistExpander_Cricket::TwistExpander_Cricket()
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

void TwistExpander_Cricket::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xC78088DCECED216BULL; std::uint64_t aIngress = 0xEE53BEAB2BDE6D49ULL; std::uint64_t aCarry = 0xC4271605A5400871ULL;

    std::uint64_t aWandererA = 0xDCDE9EE0E1E52975ULL; std::uint64_t aWandererB = 0x9137295F26CF3D17ULL; std::uint64_t aWandererC = 0xE6001FECEAE6DB55ULL; std::uint64_t aWandererD = 0xD8702BAC47EE3B9BULL;
    std::uint64_t aWandererE = 0xAA88B5D120659A9BULL; std::uint64_t aWandererF = 0x8F517E97FD6F6C68ULL; std::uint64_t aWandererG = 0xE0FCE9BC9378944CULL; std::uint64_t aWandererH = 0xB970F8CFBDA28426ULL;
    std::uint64_t aWandererI = 0xB47681E9F648183FULL; std::uint64_t aWandererJ = 0xFF48DDEE75C68DF2ULL; std::uint64_t aWandererK = 0x9B5E91261A8D797BULL;

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
        aPrevious = 14627946058881112673U;
        aCarry = 10788409733486040619U;
        aWandererA = 12357407065526117293U;
        aWandererB = 15989198445976832315U;
        aWandererC = 9656344838100570738U;
        aWandererD = 10393359328049205404U;
        aWandererE = 9959647456624441395U;
        aWandererF = 9809797855918274623U;
        aWandererG = 13322163236293560768U;
        aWandererH = 12752829721505970991U;
        aWandererI = 14275986220634979725U;
        aWandererJ = 9723277778014633559U;
        aWandererK = 9880865672731152142U;
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
    TwistExpander_Cricket_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_D(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Cricket::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xA6AFC1E589359C21ULL; std::uint64_t aIngress = 0x80934F60C0A0FF5AULL; std::uint64_t aCarry = 0xA250D56652A00C06ULL;

    std::uint64_t aWandererA = 0xA7B6E9F9D46755E0ULL; std::uint64_t aWandererB = 0xB2D88220E342297EULL; std::uint64_t aWandererC = 0xF0F40171D34BFE5CULL; std::uint64_t aWandererD = 0xB3C20472BC909825ULL;
    std::uint64_t aWandererE = 0xC2439C40ACDCD37BULL; std::uint64_t aWandererF = 0xE7A47F5D7C9AE367ULL; std::uint64_t aWandererG = 0xEC0CD318DC87DCDBULL; std::uint64_t aWandererH = 0x9BECD31D80EF3CFCULL;
    std::uint64_t aWandererI = 0xE581915EB1451F13ULL; std::uint64_t aWandererJ = 0xFA965FF864D324C9ULL; std::uint64_t aWandererK = 0xE6F5F56B549101B3ULL;

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
        aPrevious = 12296073095037584397U;
        aCarry = 12431818717468260147U;
        aWandererA = 13786718851065794155U;
        aWandererB = 11360192631421530719U;
        aWandererC = 10554942123078963741U;
        aWandererD = 14149389639680971754U;
        aWandererE = 14809893013739198455U;
        aWandererF = 15978539771124757092U;
        aWandererG = 11763655771815803770U;
        aWandererH = 18120392203593314134U;
        aWandererI = 13500130688083644628U;
        aWandererJ = 10749791766536888898U;
        aWandererK = 12071498392130060517U;
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
    TwistExpander_Cricket_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Cricket::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8188474AEEB28BAEULL;
    std::uint64_t aIngress = 0x8530D9FAF1128B07ULL;
    std::uint64_t aCarry = 0x8E9C3596B386534CULL;

    std::uint64_t aWandererA = 0xF50BA4E985B5C445ULL;
    std::uint64_t aWandererB = 0xDC392F0EBD840BFEULL;
    std::uint64_t aWandererC = 0x8B136C181408BEB3ULL;
    std::uint64_t aWandererD = 0xD315D82AAB8F30D8ULL;
    std::uint64_t aWandererE = 0xFCCD7A564DF751A5ULL;
    std::uint64_t aWandererF = 0xA694A08D856A5167ULL;
    std::uint64_t aWandererG = 0xA6E75AF989FCD063ULL;
    std::uint64_t aWandererH = 0xD5577E9FA65C724BULL;
    std::uint64_t aWandererI = 0xC7A771624B00DAEDULL;
    std::uint64_t aWandererJ = 0xAE62B4383C8F8F99ULL;
    std::uint64_t aWandererK = 0xBC000B12C900DC72ULL;

    // [seed]
        TwistSnow::AES256Counter(aSource, aSnowLaneA);
        TwistSnow::Sha256Counter(aSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneC);
        TwistSnow::Aria256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
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
    TwistExpander_Cricket_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Cricket::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA0D71234555E7CC1ULL; std::uint64_t aIngress = 0x8B0705ED5DABE4DDULL; std::uint64_t aCarry = 0xE492A8335C5BD4F3ULL;

    std::uint64_t aWandererA = 0x99511942D33022CDULL; std::uint64_t aWandererB = 0xA85EE14F11E12A3BULL; std::uint64_t aWandererC = 0xEE2D9126AD00AEF1ULL; std::uint64_t aWandererD = 0x8C4299B1CD36546BULL;
    std::uint64_t aWandererE = 0xB315351B37039EE3ULL; std::uint64_t aWandererF = 0xF8C304D4F346FBA7ULL; std::uint64_t aWandererG = 0xE10C92D1AF356C57ULL; std::uint64_t aWandererH = 0xC7F99FD1828DAF24ULL;
    std::uint64_t aWandererI = 0xA1B1E20C7D301CA1ULL; std::uint64_t aWandererJ = 0xD656AAFC6FB3656BULL; std::uint64_t aWandererK = 0x9DE983FD8C536BE2ULL;

    // [seed]
    {
        aPrevious = 14089384025523714116U;
        aCarry = 9567448517593906134U;
        aWandererA = 12956031627364109087U;
        aWandererB = 12440413070548113756U;
        aWandererC = 9711560995809925306U;
        aWandererD = 11826147899090368368U;
        aWandererE = 12137193308268422452U;
        aWandererF = 14302089731973594294U;
        aWandererG = 15945848638287309857U;
        aWandererH = 11202980619174650700U;
        aWandererI = 12081509174889052404U;
        aWandererJ = 17612453657625872906U;
        aWandererK = 14407132102602877457U;
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
    TwistExpander_Cricket_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_D(pWorkSpace,
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
    TwistExpander_Cricket_Arx::Twist_E(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Cricket_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Cricket::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 0, 2, 0 with offsets 677U, 340U, 7300U, 2012U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 677U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7300U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2012U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 2, 1, 2 with offsets 704U, 1296U, 1204U, 1033U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 704U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1296U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1204U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1033U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 3, 0, 1 with offsets 6508U, 4975U, 4755U, 892U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6508U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4975U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4755U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 892U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 1, 3, 3 with offsets 7984U, 6127U, 6778U, 6606U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7984U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6127U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6778U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6606U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 3, 0, 1, 2 with offsets 35U, 1928U, 640U, 405U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 35U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1928U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 640U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 405U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 2, 1, 0, 3 with offsets 1265U, 1294U, 1696U, 1124U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1265U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1294U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1696U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1124U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 1, 0, 3, 2 with offsets 1757U, 242U, 1398U, 2033U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1757U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 242U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2033U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 1, 2, 3, 0 with offsets 367U, 1810U, 1605U, 767U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 367U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1810U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1605U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 767U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 894U, 333U, 861U, 1128U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 894U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 333U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 861U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1128U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Cricket::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 0, 0 with offsets 6597U, 3886U, 6772U, 1393U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6597U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3886U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6772U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1393U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 1 with offsets 7253U, 869U, 5144U, 1053U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7253U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 869U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5144U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1053U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 3 with offsets 4119U, 2615U, 400U, 3039U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4119U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2615U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 400U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3039U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 4237U, 3036U, 5288U, 6805U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4237U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3036U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6805U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 4888U, 496U, 6405U, 201U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4888U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 496U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 6405U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 201U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1621U, 396U, 784U, 1174U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1621U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 396U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 784U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 147U, 774U, 741U, 1231U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 147U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 774U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 741U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1231U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 1705U, 290U, 1333U, 708U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1705U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 290U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1333U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 708U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 126U, 350U, 421U, 616U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 126U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 350U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 421U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 616U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 803U, 439U, 986U, 1046U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 986U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1046U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseASalts = {
    {
        {
            0x96E079D833378FC0ULL, 0x0C49AD20EB8D27C6ULL, 0xCD68801979F77174ULL, 0xCB57E93BD8AEB7A1ULL, 
            0x8020E00FA7A247B1ULL, 0x3032CF3B44A0D647ULL, 0x59CC61D890CB1279ULL, 0x7D7957D11351AC62ULL, 
            0x75C8EFD039389598ULL, 0xAC9272C35260BA93ULL, 0xD75C915CE8435637ULL, 0xA80DC79F47C94775ULL, 
            0xCCEA57A1471E21EAULL, 0xD165FA4E3C1D5CB6ULL, 0xC4823AD4206E2650ULL, 0xEA33690A6A0C33AFULL, 
            0xB0BB5D19A4978135ULL, 0xD693647F22301B40ULL, 0xB85BE3482EB7E217ULL, 0x97B82FF55D96FAB2ULL, 
            0x5FD4725584127C75ULL, 0x16B395A95E646258ULL, 0x4EB1CE19D695EC28ULL, 0x3EF2A765593C9948ULL, 
            0xB8A866F6A7A6B922ULL, 0xAEDAFD9F2C0484BFULL, 0xCA28E298F0444DD6ULL, 0x0CE8D8824FF348B6ULL, 
            0xFE445E39E512E6E8ULL, 0x8D3A87B4BEF5DA36ULL, 0xFB34601C012722F3ULL, 0xBEDE3FC20347D3FDULL
        },
        {
            0x9FC381455F949801ULL, 0x68D81FDAADA7DFE8ULL, 0x62990CF9F5C72A9FULL, 0xB00E6E108B83A22EULL, 
            0xE0D675B4A042DEE0ULL, 0xBB06BA77A4FBD403ULL, 0xB0B29B501BA40FA5ULL, 0x8C4A7C779DD3AC8CULL, 
            0x8964DD2822FDC79FULL, 0x2F369964E92F7782ULL, 0x338E92B95FD0164FULL, 0x3FD7D50597EA5C23ULL, 
            0x16E23BD6B4F13430ULL, 0xF7161CD36DB1BAB7ULL, 0x85EEC7BB3A3331CCULL, 0x778D1EF0E8D50623ULL, 
            0xC0FA39A5ED1C8C58ULL, 0x1C86EBD1BD0106C6ULL, 0x44F5BB8F5695624CULL, 0x4A341539AFA75064ULL, 
            0x77A68A83C5D333DDULL, 0x1BF3DFF73991D28AULL, 0xA5D9B1D0E09C4ED0ULL, 0x58E24833018527AEULL, 
            0x2372E2AB3D02D18FULL, 0xF27D2333FD3E941AULL, 0xE2295F9EEACCB186ULL, 0x5294E33C16C52A49ULL, 
            0xE2EB2C360F62FD4CULL, 0xD97C62FB93821F1CULL, 0x6059675DA1E8C9D9ULL, 0x1DC1CBC0EBB232FEULL
        },
        {
            0xFCA98BD0DECACEA3ULL, 0xE3D3615EA19591D5ULL, 0x2141D14A93182F60ULL, 0xE5D296198A9FD8AAULL, 
            0xC4DFFC8D9E37FFDDULL, 0x1998E7A21121DC5EULL, 0x13A0411EA016122FULL, 0x43751E350545C5ECULL, 
            0xA67A1EAB838E541CULL, 0xBEA11775541EC17CULL, 0xB5057F9A90E2269FULL, 0xC756DDFBD4D69A9FULL, 
            0x60353396461CD7ADULL, 0xAEAE3C1F5C4308B7ULL, 0xFC01B3CE0FD138B9ULL, 0x4E93DDA018800503ULL, 
            0x275A32A72F4E2384ULL, 0x2082EF39B35BB985ULL, 0x51541FE56919B612ULL, 0xA5BF25FACBB8A668ULL, 
            0xB2D590745BC4F0EEULL, 0x595168B9803A03E3ULL, 0x95AC27D535E9D7D3ULL, 0x518C44CA21E7F743ULL, 
            0xFCD434C1AE1F6C79ULL, 0xCDFC07295E465BDAULL, 0x0AB7EA32077079B0ULL, 0xA18404BD94ED7C0FULL, 
            0x0A0605FF41189E1AULL, 0x6A382747700AD6B5ULL, 0xC449CB0086B68820ULL, 0x3592425E2D2FD0C9ULL
        },
        {
            0x4D565C8D8F3E57FEULL, 0x070B0B78CFD2101AULL, 0x0EEC8769F52B92FFULL, 0xD7E319127154334CULL, 
            0x737EC1997C42E61BULL, 0xE304B3351A711E92ULL, 0x4FA1F07CC113A518ULL, 0x8C95A5C2BAAA12F7ULL, 
            0x1E1A94D6F0C8F11BULL, 0xBD438581F0E7CF39ULL, 0x8B6C4FA43B0367FBULL, 0x9F62B377976099CFULL, 
            0x776414D09ADF3D51ULL, 0xF820F0BC744E2DE8ULL, 0x4763D5A3F300732DULL, 0x9D48AE33B4B3D830ULL, 
            0x640F626B0CDB438BULL, 0x05D1DEB5D77F87FFULL, 0x0D7A31E2325CE877ULL, 0x63C3026EDF0C6569ULL, 
            0xBB99C42BFF3C0A4BULL, 0xAF6AC3A01C143355ULL, 0x3F0D8059F661649FULL, 0xCC7C0A9C375DFFE5ULL, 
            0x598572F2D7154FCCULL, 0x33F04434295C4B56ULL, 0xA68890AF6C9904D2ULL, 0x4A80C532C53C9325ULL, 
            0xDDE4E3AB56119165ULL, 0x94D53128E9EFF3DEULL, 0xAF48A0F46E6B1BE9ULL, 0x943045E2DBCFAAC9ULL
        },
        {
            0x70FEFE0A08B6E54FULL, 0x1EFD06D52C9CF7DBULL, 0x95ACB70CBC455802ULL, 0x660FE51167A8CF34ULL, 
            0x683F753570B152F0ULL, 0x03163CE2FED9CE1BULL, 0x47288CE15ECC67E3ULL, 0x6B121B1FFA9CA8BBULL, 
            0xA2D2C8FEED0731E9ULL, 0x31A9888A1B95E36DULL, 0xFB49708608E237B2ULL, 0xF6A120DB2B3C1B65ULL, 
            0xE80368A068720CDAULL, 0xD60254DC59B26D51ULL, 0xBE09A8C5A3D92545ULL, 0xB6216E0B53AFE077ULL, 
            0xB36EE2C5BC06262BULL, 0x1806616F2B5993E5ULL, 0x18C697504BB0D03BULL, 0xDFE5CC86D920625CULL, 
            0xFB8CC8D8D0511794ULL, 0xFC066B288A0EC96AULL, 0x50EF81A35124D53EULL, 0x423DA34419A16D08ULL, 
            0xA53390349ED1DA79ULL, 0x6B99D8EA7BAFF4C7ULL, 0x8EC387FD530692E2ULL, 0x4CAB98D9E9811510ULL, 
            0x2D87E1603994ED87ULL, 0x75280108A784CB48ULL, 0xF4998BFA240E3454ULL, 0xB849094CD0466B4FULL
        },
        {
            0xC6CCE7F18A35E7B9ULL, 0x7139CBC9D7832C47ULL, 0x1FEFC41E4E27320CULL, 0xFFD964F3B3B2A63CULL, 
            0x279BFA740FD8431CULL, 0x90053A62B067E32AULL, 0xC6594741BEDC74EEULL, 0xC99A106B981CB966ULL, 
            0xF5F205946797D12AULL, 0xE498751D799ED783ULL, 0x0877CE012170655BULL, 0xB71753C79C545E25ULL, 
            0x0DA4A1F95691B480ULL, 0xA7BDDF867CCD91E0ULL, 0xEA1A9B0C4463A7FDULL, 0xD5F2A576CCC72B60ULL, 
            0xAD3710354B356275ULL, 0x5DA1E55709531553ULL, 0x9DBED919101EC30CULL, 0xEEC9358825058A82ULL, 
            0xB5E447B24389E026ULL, 0xA19622CCC9028234ULL, 0x1550E6D31F7AB1FEULL, 0xE47B2C800D1F7C11ULL, 
            0x4D597775E53721F5ULL, 0xDE06F79710F2A369ULL, 0x09D46E3C213431F2ULL, 0x421AD821E2A13B97ULL, 
            0x43DB27E0FE213DE8ULL, 0xFEE62DC3EC2C6F1CULL, 0x45E001B514EBD806ULL, 0x612C78803C0B22EEULL
        }
    },
    {
        {
            0x296F8A48CA5F0998ULL, 0x01A2121A6643C5A6ULL, 0x2BF5872724F2F618ULL, 0x12072BBC35384378ULL, 
            0x3F10948D9B1E381BULL, 0xA6D9AC5AE19B6FCBULL, 0x6865F9A9046B0F04ULL, 0x9661C65365FC70D8ULL, 
            0x2E13A3BF49AA3281ULL, 0x1BA086635FA5496AULL, 0xCE6C12D3407966D2ULL, 0x9F5E97E4BFB7279BULL, 
            0x29984FD5F2B62FFAULL, 0x3568E8CA7B6FA3AFULL, 0x7270294FD5FC8D1EULL, 0xA66E8DF2DA633C81ULL, 
            0xCF78982EF91E561DULL, 0xFBF12DA25EEBC3E1ULL, 0xD065475BF03B9F57ULL, 0xEFE143A5390222B9ULL, 
            0x9227CF182CADC5E4ULL, 0xD785AA52ACF155EAULL, 0xA4E67F49D99F6642ULL, 0x2F6965FA4260733FULL, 
            0xD18BCD7B15CB064EULL, 0x28D87675F5BC6B80ULL, 0xBFEFFB92EF451F5CULL, 0x23B0AE6DF8219CDCULL, 
            0xBE9ECBE99DFEAC35ULL, 0xD88BB0F201F41E9EULL, 0xE76592E4DED06DDDULL, 0xC2FE2E67F4852709ULL
        },
        {
            0x27120748C9E9D4EEULL, 0x834AB613419AD83BULL, 0x98CBC87C5CA02900ULL, 0xD27B8596E5C1DAEAULL, 
            0x86CCC0F0CE883BEDULL, 0xF6CF8966769BFFEEULL, 0x2D7985FCA89206DCULL, 0x2BE1985642F2CD97ULL, 
            0xB0CF9950E5A19970ULL, 0x0A84F98CA576D4EEULL, 0x1DBEAD3B069796D8ULL, 0xABE7B0F1D8A184B8ULL, 
            0x1F6EB90A72EB6BEEULL, 0xF40A4B900BB6C4CEULL, 0x3385E9AEEE0D0B4DULL, 0x0DBF78C34BAEE0B9ULL, 
            0x53F0783969F23F34ULL, 0xCE78AAE187654302ULL, 0x49240BD426AC499EULL, 0x3C585DA04783E5B8ULL, 
            0x5EBCE2CEE4A39403ULL, 0xDE83C3B95797F24EULL, 0x40BF8E92A43149BDULL, 0x7F6EA27FF718EF0BULL, 
            0x20C78BAFDC37E818ULL, 0xF033131B511D8172ULL, 0x944D5CF39FE7BABBULL, 0xCA1AA2CDCBA58016ULL, 
            0x77D6B3382909A20BULL, 0x6CF0A9E4A8F00F50ULL, 0x43A2588584212984ULL, 0x049AA8F1C5D2D5E5ULL
        },
        {
            0x4D489F87424411CFULL, 0x064EF04FBA9BC6D3ULL, 0x2FBCFD02A080A0E4ULL, 0xA42E6934A7D7FCFBULL, 
            0x676F011524630D46ULL, 0x5CE916F91EE8CCCEULL, 0x939850F53B80CD05ULL, 0x4ED02F257E7785B6ULL, 
            0x4C01512404520576ULL, 0xDE8BF5B3DFB5A8EBULL, 0x000939D3E1C24DDAULL, 0x89C52F12B961C9EDULL, 
            0x983515371607280AULL, 0x69C34786B7C8528DULL, 0xC4A3BA846B9F11C7ULL, 0x76D05E0B454E3278ULL, 
            0xA116116B64C8E6D4ULL, 0xBF0251F6D090A737ULL, 0xFB64613F64FC86F5ULL, 0x949270204ABB00B4ULL, 
            0xB1E31C67AD3753A9ULL, 0xF3360425283FEA08ULL, 0x507CD0DC73EF844AULL, 0xA4D066CBA69BE4A7ULL, 
            0x70158E2A8207268BULL, 0x7C7BED4ABFD4CD6AULL, 0x65634D367A4A2499ULL, 0xF6B1FB38EF130790ULL, 
            0x90CF20EA707CA012ULL, 0x4D848F2D148938A2ULL, 0x9938B514641CD415ULL, 0x0F4B4CF505F44282ULL
        },
        {
            0x3FAB7251E03C90ACULL, 0x47E89F8F0755014BULL, 0xC75165E4CE97CC62ULL, 0x4B4EC7AB8C29778BULL, 
            0x187CD96BCAA13C1AULL, 0xC7C12EDEB8A1A0EDULL, 0xEAF101048E4C1746ULL, 0x698E0F5640D3E45DULL, 
            0x6E56D1BD38C0F584ULL, 0x36B9A4A2454C61ABULL, 0xF819BF942693D4EFULL, 0x6C16602CA64B7F54ULL, 
            0xBB24D521092A91A7ULL, 0x0881181CE4222B2DULL, 0x2E13BAFCDD4BD7C0ULL, 0xB0E3800A3F4F09D0ULL, 
            0xC662B5E4F4D2DE19ULL, 0x7ACEDD17E305248AULL, 0xCC5CF6AB2806A5E9ULL, 0xCA8126301FDBD8E4ULL, 
            0xCA33038FC6D66DE5ULL, 0x78BF260488AB507CULL, 0xC71D564D1AB684B5ULL, 0x32ADAE90D5F27D51ULL, 
            0xD151B28787E5FAF9ULL, 0xDF8734F11BD043F8ULL, 0x15D4543779A4A472ULL, 0xB6F91648D3A3755AULL, 
            0xEE8EB0318DE41151ULL, 0xCB7B542F54D4B43DULL, 0x953ECD8365EB7417ULL, 0x1ABBA66A0475D802ULL
        },
        {
            0x253916A69C9019ACULL, 0xAE21F8FA920ADD91ULL, 0x4E825DFE6DAE776FULL, 0xB8C2CEEDE0BC2089ULL, 
            0x87199D1ED7C6471DULL, 0x214BF3DEF9239333ULL, 0x1FFA561A223C7C7FULL, 0x36126A64FFD7FE86ULL, 
            0x69E38FE1291DFAECULL, 0xD62EF2F7C3F5E74BULL, 0x178A64E22FC940EFULL, 0x6404D87BF7254560ULL, 
            0x13D9CB57B565EF7BULL, 0x32B141D169BEA0DEULL, 0xEA2953231826EFEAULL, 0xF7D105A78A5D65EFULL, 
            0x44B551EFDE66BD07ULL, 0x4657FBDE9432CEE3ULL, 0x83E5AD91BEE6C268ULL, 0xE2C562542B29B9C2ULL, 
            0x466D381F02EDD989ULL, 0x9BCC41DAEC81E812ULL, 0x1B634565DF2DA348ULL, 0xD5022C16B3531BD5ULL, 
            0x2E00F487336326F5ULL, 0xBECAF48B1C730827ULL, 0x2256DB55AC79F368ULL, 0x661DC6BDBA59C4E5ULL, 
            0xA898DE1A9AFDC542ULL, 0x226E96E8C700DD8DULL, 0xFE6141B71B9A7E43ULL, 0x66E05E70B23CED19ULL
        },
        {
            0xDD9791CE71CC6CA0ULL, 0xA173AB55DE54CAC2ULL, 0xBB329C7D2E7B0F40ULL, 0xF6AF7FE5B6D3B40EULL, 
            0x0ED5D7FB9EDCEB83ULL, 0x82DD65C3E31520A7ULL, 0x88C2B1E0B46636DFULL, 0x192C977997E362DDULL, 
            0x00D67E5939A3067BULL, 0x2F5BA074FEDE2EA5ULL, 0xA7D076DE50D37E44ULL, 0x147D04348B8CF412ULL, 
            0x651F7A7E5696FB84ULL, 0xD165FEAAE59CE33EULL, 0xE9E652C7D5647D02ULL, 0xC8A8B34B4EA75F56ULL, 
            0xCAF038AAAE888DB6ULL, 0xA4F8F1F3CA0E22CEULL, 0x6FABE2C5CE64F029ULL, 0x1C2CD2CE12033CD3ULL, 
            0x72E9177FFBC9AF45ULL, 0x77B427C9FD9CDA39ULL, 0x2E6CF33BB1EBE48CULL, 0xB5B94AB3AC5001D1ULL, 
            0xE806745251DF3F14ULL, 0x5C09AB85A80FDE0CULL, 0xE4BF343FF6E87691ULL, 0x160C1611DFC94837ULL, 
            0x649F0A391E3BA09CULL, 0xD548FEAD7006FA0EULL, 0x72600C9C7D56F0E7ULL, 0x6CB9632585F0C352ULL
        }
    },
    {
        {
            0xFD643814F28BAFB5ULL, 0xF4DB008E7F9F7E75ULL, 0x6A1D54D6CF64951DULL, 0x64C46E3610AD53F1ULL, 
            0x70504EA7BB75B8D6ULL, 0x4DF86655B872B3FDULL, 0x45F0B3E4A94E2579ULL, 0x1909B5D822245E88ULL, 
            0x14A430AADAD5A82FULL, 0x241CED7D609A906EULL, 0x0EF5CDAAA2085732ULL, 0xC2F0A151EC84B559ULL, 
            0x0FC23FB1222B6385ULL, 0xDE3F3DECFE98C04CULL, 0x8F28B7066610460EULL, 0x7463F47C95DAFB69ULL, 
            0x70A893E98C5AE394ULL, 0xAF7860845E6BBDB5ULL, 0x19A060B94D8CDF05ULL, 0x917AF1A227F90343ULL, 
            0xF05DA9392818E50AULL, 0xDC813C209196167EULL, 0x34BEDAA6C17EDF9FULL, 0xD6BE18AB09DE05AFULL, 
            0x7B28437236F06916ULL, 0x2548D6C186A6045BULL, 0x62C2B936FA76D5A8ULL, 0xF17B7A8666FBACBAULL, 
            0xC0896EA1A66B4C12ULL, 0x32F7212A510EFA36ULL, 0x7F7CB365862E8E5BULL, 0x447263AD9B15B3DCULL
        },
        {
            0x9B818C4EFE1B9475ULL, 0x12C34278D828B12FULL, 0xB6464D161AB793A5ULL, 0x663512B15A9CA50CULL, 
            0x2E25CC8AF6B300CBULL, 0xF20FDEA4D6CDA87FULL, 0x580869AB887C39A6ULL, 0x87CBBE63B58ED13FULL, 
            0x95CBF82EED85EA88ULL, 0x3B339E0E17E39267ULL, 0x093EBF35A084EB51ULL, 0xC75AC603E2E78D7DULL, 
            0x940EE12F227AD029ULL, 0x2A7459F15C53B873ULL, 0x5970ED64568710CFULL, 0xB2C1BF2099291D83ULL, 
            0x94EF9D9854A89C38ULL, 0xB07DE2117D19C7C8ULL, 0x41869DD157700B24ULL, 0x7E39214DA251D829ULL, 
            0x3109889CA5AEB851ULL, 0x062F88D5FC041C37ULL, 0x75982ECC4F534F13ULL, 0xEC6C1E251DC36988ULL, 
            0x0E84B10CF2BBCA29ULL, 0xA0822AF629648C99ULL, 0xFAE74917C3916DCFULL, 0x942B4EAADC5F5599ULL, 
            0xD1078AEF7F196A3BULL, 0x4ABD35D8A4694CE5ULL, 0xCB8329FCC0A789BFULL, 0xF0B7BC6A8B8E82D6ULL
        },
        {
            0xC685899488E30940ULL, 0x972DB0510A5145D3ULL, 0xC72F33D2BC3FD6B8ULL, 0xC3316C5C5334564EULL, 
            0xB747EDD7D25A9F1EULL, 0x9CE685BC67134DA7ULL, 0x0613A20F709C7237ULL, 0xDF959898E2638B3BULL, 
            0x2ACB37927CF8E64DULL, 0x0DF0D7076B71BDB1ULL, 0xA3E8B7F0F717B5A7ULL, 0x4F04103B845D60FEULL, 
            0x59F929FA6EAA6267ULL, 0xDB76B191C809100FULL, 0x97E0BECB50A69917ULL, 0xA00810C55C96DDB2ULL, 
            0x723B99BF9B0BE8BBULL, 0x7D93F90671348408ULL, 0xA6A9697D78A79117ULL, 0x12A4260886140071ULL, 
            0x2F435BEA899C6EADULL, 0x1C161DDC71659D1BULL, 0x20725B6157BFC72CULL, 0xB73B2BBB11CF0774ULL, 
            0x4D8A962B552F9C67ULL, 0xE74DDB6383432DA8ULL, 0x290D3DC61F3E3C6DULL, 0xB049B33EAD8FDF2DULL, 
            0x772BF955A8DF58A6ULL, 0xCC01321745150DFEULL, 0xFC8A2DCB81EE7749ULL, 0x2F1F93E98DEFFB3DULL
        },
        {
            0xB4757ECA26A6DB1AULL, 0xE60D4E634ECE184DULL, 0xE739274E6EE6F92FULL, 0x1244801E73AFB0DEULL, 
            0x20EAD24F8031C398ULL, 0x7DEDD557BD79CB91ULL, 0x1151F23450F525B4ULL, 0x857AC4CA8C5700E8ULL, 
            0x84683541798B4D3DULL, 0x454FEC3B0359AB91ULL, 0x9685685DD77FBB08ULL, 0x600F6CA1927D283FULL, 
            0xEF7B1389256D770DULL, 0x506203FA2A19CA8DULL, 0xEDE558C54BF13CE2ULL, 0x331B8468F17D7779ULL, 
            0x0D716218997CD73AULL, 0xBB2A9988AC2AB7D3ULL, 0xFD3FF5BDA90A80C1ULL, 0x4D01DDA4B39B9ED9ULL, 
            0xE5C50DB3994E237DULL, 0x08D2119A4F24057CULL, 0x4A494CDF078F56C1ULL, 0xAECBB57805F6E1E5ULL, 
            0xE91773541C6C47FCULL, 0x4C933B186D9861B1ULL, 0xD678F8F25FBF2754ULL, 0xCB28F5A0308B19E8ULL, 
            0x0F4949E39748A308ULL, 0x4F0985D4E9FC0CA7ULL, 0xD849F51EA26C24CFULL, 0x533CC35D7DBF05EDULL
        },
        {
            0xDA70CA7BB6BF0873ULL, 0x506DD876395859DDULL, 0x75E19FC199A7D9DFULL, 0x92DCF0BF8C0B87E6ULL, 
            0x055FA2B4A253CF0CULL, 0x2E60CE36FE0E8FE0ULL, 0xD19739C9B05814FAULL, 0x2F9572361EBCE273ULL, 
            0x50768EF897EF7218ULL, 0xF213A1305F7447E1ULL, 0x72B1896D32387650ULL, 0xE1B3031CD07201E9ULL, 
            0x915B8FF69C16F177ULL, 0x92A31D6FCEFEE94EULL, 0x2CEB44D7F927F658ULL, 0xB38BABD26979CEAFULL, 
            0x19BE1F25A790E423ULL, 0xF717932EB991FE56ULL, 0x15DBA002A81A0D49ULL, 0x6AB6145E6A20BC3BULL, 
            0xFB22C3F3D08017DFULL, 0x6EB9860AF6619282ULL, 0xF1ADD3BD90469CEDULL, 0x6712642934AA74B8ULL, 
            0xA202C94550530175ULL, 0xE25E223378715715ULL, 0x457F6B637DFF3008ULL, 0x7EEDE1324857D478ULL, 
            0x67FF18B3078A2457ULL, 0xF0A76A17459B8ECBULL, 0x4BC4BBD3294AAAF3ULL, 0x7919EF4D47FA8EC4ULL
        },
        {
            0xCC90217E47AFBD5FULL, 0x96C59E3483FB9BA0ULL, 0x13C153A1AABE8875ULL, 0x21946769A321A3C1ULL, 
            0x36B209CDFC0F75ADULL, 0x0F33AD549AEB841CULL, 0xBBC2784B713FCE83ULL, 0xDBD8DAC5E8F86C6CULL, 
            0x1B49BBEFA0AE8862ULL, 0x84A3F0268A0E97B9ULL, 0x87D847A22A7FEB66ULL, 0x70AE45C58CFE78F2ULL, 
            0x9EC0338D970E44BDULL, 0x1F4AB22CCA029394ULL, 0x14334A422B5E8A9EULL, 0x7BB24F5BABCEBA1FULL, 
            0xDD8572ACF9F43549ULL, 0x7572E9F6FE78B7D2ULL, 0x488B30CB8A2269D9ULL, 0xA8EACA43831BC29BULL, 
            0xF1F7A59E1DE3613CULL, 0x96A6AC1F929D9150ULL, 0x3A271654D3B02286ULL, 0xA7A6A485E3F27F0AULL, 
            0xDEC3FB3EA4C8C0ACULL, 0x80D24E8524969310ULL, 0xBB629B77055DD3B7ULL, 0x8A59A17A963BC1AEULL, 
            0x35D381F82A2944CFULL, 0xFE081DA8D323D48EULL, 0x0126F41E7727E63FULL, 0x7158A0B9A25F431DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseAConstants = {
    0xDD657C57949289DFULL,
    0x968882F1B111E723ULL,
    0x4D6698E0F2595E2AULL,
    0xDD657C57949289DFULL,
    0x968882F1B111E723ULL,
    0x4D6698E0F2595E2AULL,
    0x0FAE881C7AC5BA0AULL,
    0xDB475ED0BCC0131EULL,
    0xCB,
    0x61,
    0x41,
    0xB3,
    0xE3,
    0xDE,
    0xB8,
    0x8C
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseBSalts = {
    {
        {
            0x22675820A033F066ULL, 0x5BEF1D992362143AULL, 0xC1085FDD66376D1FULL, 0x92510C8F7FF6F2ECULL, 
            0x6B7380943BAA5591ULL, 0x46C2CD72122F344FULL, 0xE7CD9B14501F5004ULL, 0xE06C4D2876EC6B92ULL, 
            0x637A94D08C8443CFULL, 0xD6F7DDE6E3422FC2ULL, 0x477B2259EFCFF66FULL, 0xA8D592E4B980C4DBULL, 
            0x23B62D55D9FAC942ULL, 0x8CBA1A2EABB37651ULL, 0xEE54755601C2A9F0ULL, 0x24B81C2A6F189C18ULL, 
            0x7F01B5257EF42BFBULL, 0xA0B4A2209BF30A39ULL, 0x4192433F2DE1400AULL, 0x7412BA767BDD6466ULL, 
            0x1493EDAB75A7ECC4ULL, 0x95A9FB7B761DA539ULL, 0xAFE938A4D42407B2ULL, 0x29BDB6511B8F13CEULL, 
            0x061109157FDD1BB7ULL, 0xE0ADFCCBE0EE9471ULL, 0x5B1248CC85638722ULL, 0x952AFDA0EB0781DFULL, 
            0x89444266800BBDD2ULL, 0xED17C9044B13FB75ULL, 0x1E1BB4D33A96E02FULL, 0x21F967EDAB61412BULL
        },
        {
            0x403B681CEBE36BEDULL, 0xC452E1D8134DB451ULL, 0x15D73CE06FC48438ULL, 0x67FA24C45BD3658DULL, 
            0x8F3967BF236D54B9ULL, 0x897924390F203C66ULL, 0x138BF55862266126ULL, 0x5B5FDA709FCCFC9EULL, 
            0xA11C992EEDD634F8ULL, 0x7538AFE29483C37EULL, 0x82B7C4848484679FULL, 0x4E5E848B5E3C4755ULL, 
            0xE5F28CC61B8168DBULL, 0x94809643C8C6C990ULL, 0x548FE73E62976F80ULL, 0xFB591A9F13B53869ULL, 
            0x58E26B983AAD146BULL, 0x85BA014BB9ACB700ULL, 0xB8BAFD5F30CE2C90ULL, 0x35402D584C9E7EB5ULL, 
            0xEE9EE59EE3586330ULL, 0x5E98705A66802C18ULL, 0x0C12FBE53D5302F1ULL, 0x3A35A6587C939EFDULL, 
            0xC4D603F286058999ULL, 0xB0761581553E358FULL, 0xFA309CDB66E37022ULL, 0x6DE4646366E67592ULL, 
            0xB088BF6946E11E12ULL, 0x221E7CF1629F007EULL, 0x144AF11F7B3D1C7BULL, 0xC9DCA4E5E9D37453ULL
        },
        {
            0x5B89F4F5678D22AAULL, 0x8F91385765F93E1BULL, 0x902D04EB72F20EE2ULL, 0xC8365BE10C663FE2ULL, 
            0x6B60D027EC8CD5BCULL, 0x92F954A9E5877DDDULL, 0x8B574254D914F997ULL, 0x11D0A9F7F5176845ULL, 
            0xE21C82EAC1312FE5ULL, 0x4A6101F7A5E8B3B2ULL, 0xA578902F243D8AE3ULL, 0x83056F31E172EEB6ULL, 
            0x7EE9A7A4877151BFULL, 0x9F8B9A7362B19204ULL, 0xC325EDD9398EF1D9ULL, 0x34C4DDFDB803D3F8ULL, 
            0x8506F58040AE7535ULL, 0xCBC934FAD54E24F9ULL, 0x349927BE763979B4ULL, 0x9FE0C5D52087E2C4ULL, 
            0x26B4D00DBE3AF698ULL, 0xF44482525FBC86C0ULL, 0x42BC0E927558BD79ULL, 0x303EA7EE38463391ULL, 
            0x333C604DC84B157BULL, 0x4E423F3F4741DE93ULL, 0x676402CC6ED566B4ULL, 0xF3D129F5F123630AULL, 
            0xC166BB66215A51A1ULL, 0x2F0C8CE444347018ULL, 0x8566EEA182D43373ULL, 0x8FE61EBC15D27CCEULL
        },
        {
            0x6FFD53042A16E8ECULL, 0x22CEB6860BDE8B47ULL, 0xE4009945CFB7EB44ULL, 0x06B01C9B37016296ULL, 
            0xD3312F4FE5768FA7ULL, 0x114400BBDF49AFCDULL, 0x1D20A9E32E6AB4F4ULL, 0x80DD49592A18E2CDULL, 
            0x05D7B00D65A6E414ULL, 0xA5E489A1986B253DULL, 0x1EA154EA65C7BBCAULL, 0x75EBE6BF13606255ULL, 
            0x997AB85B4CBF9B85ULL, 0xF522B9145F0141C1ULL, 0x58736E84C82E7E2AULL, 0xB78217A56F5757E9ULL, 
            0xED48DFA5316E45F0ULL, 0xA10A83990A618398ULL, 0xEC94455166190192ULL, 0x9F293363657E67CCULL, 
            0x0AA50B8D59C7B174ULL, 0xDC5C49C1DC8313BFULL, 0x4E949A7F31C13B68ULL, 0x876C32D3D8F6E5ADULL, 
            0x1E6C15927ED853F4ULL, 0xB58BDAE7B5F7E57AULL, 0xD82502EDBE775E70ULL, 0x6F0646C87308ECE9ULL, 
            0xD3C7485F49A6E96FULL, 0x9B21497A784B18F1ULL, 0x3B1831A58726687EULL, 0x5ED20BBDD4C18AE3ULL
        },
        {
            0x5114B7F239FFCE28ULL, 0x8954E0D98332510FULL, 0xFD91DB2F0EC783BDULL, 0x08634EB417EF846BULL, 
            0x07B4FDD6CE345F47ULL, 0x50AD2FF4C97A56C4ULL, 0xAF76163121A14C9FULL, 0x1F89173B2817B822ULL, 
            0xB031421C5A7A1C2BULL, 0xEB2E8CDC278D033DULL, 0xDC7B88CA1F6BF5B5ULL, 0x884E234ED0CB4999ULL, 
            0x591AAE1BC42C7649ULL, 0x11B9E1F9BACF6FD1ULL, 0xDF9CD6A8D40C72F4ULL, 0xFB88A979FA23EF91ULL, 
            0x80D49A0FF12FD83AULL, 0xEEC9BCFFCEE97877ULL, 0x6EB7C641A298FA7DULL, 0x0303D1046EF1897BULL, 
            0xD99C76B28F11DBC4ULL, 0xA29085A3BD795CA2ULL, 0xA97882E91F282D31ULL, 0xA472D4A29F1A2250ULL, 
            0x9FB45554A6A6DC07ULL, 0x32FF7D7CBCC6ED80ULL, 0xAD772B4C49F199EFULL, 0xCE07F934C654B2A6ULL, 
            0x7D48A642D49FFB5CULL, 0xAB3F54B733D33A86ULL, 0x114B46AEB5433872ULL, 0x0B4DC5485F7779C2ULL
        },
        {
            0xD3814AFA7F469464ULL, 0xEC7EFADDAD5CC2A1ULL, 0x938BBBACC345E468ULL, 0xD617869CAE590E50ULL, 
            0xF7BE7AD834F51C69ULL, 0xBAC5CA74989DBF06ULL, 0x2BC4558324BB44C3ULL, 0xC188364D4ADA19DFULL, 
            0x00D5CCBE8D825C23ULL, 0x1164D3B18F39C6ADULL, 0x74CEBA9622291099ULL, 0xAA92FB32995C5A94ULL, 
            0x2A233EDB9B205C6FULL, 0xDD6ABAF7D069A5FFULL, 0x013114A4EB077E02ULL, 0x022A215E09B21C0AULL, 
            0xC83B1AACB2A16B7FULL, 0x3E2166E30F062874ULL, 0x37DFAAC9C7C20EA5ULL, 0x58BDD7F5B58D3668ULL, 
            0x4E4EE04068F24852ULL, 0xD85D660AF9808CFCULL, 0xFA75E951112322BEULL, 0x0811052B28E6B816ULL, 
            0xEE2CB89CF866A71DULL, 0xA1DD2EB42107EF18ULL, 0x45099FAA85A92015ULL, 0x8B4C0E3E264842F7ULL, 
            0xF2985ECA82D8D3F5ULL, 0x78316006517881A1ULL, 0x76D3737DD3E22C03ULL, 0x37A0699B578454D0ULL
        }
    },
    {
        {
            0xF4251939928D1FA9ULL, 0x954FE49D4E0EEFD6ULL, 0xD3EE6985E7E3593EULL, 0xE03683E04FFCCB8CULL, 
            0x5A9AE1ABB2D12996ULL, 0xD47223536F93F6BBULL, 0x73C79D5AB2C26A36ULL, 0x66D30BFF90EB20F5ULL, 
            0x894492D683B159C3ULL, 0x02EE05B24B133434ULL, 0xFFCDFAE4A863238EULL, 0xB05EFF7D19190CCAULL, 
            0xC97BD6763E0571F8ULL, 0xA004C2E605184EF1ULL, 0xCFEF9A40E1747E2CULL, 0x108BF5D0FD0B9377ULL, 
            0xD8CEDDA62042E5C6ULL, 0x47571BC1A6D304FFULL, 0x9E8003CB00E30E5FULL, 0xC0AE7E4CB149C82AULL, 
            0xAE73B1F56DCA98CBULL, 0x4073FCF1F27C9A70ULL, 0x226089572F1C7803ULL, 0xC9D6EEE58B3CFA0DULL, 
            0x467946295F98E06DULL, 0x41E7A9205F080361ULL, 0x50FBCDFC7D105E51ULL, 0x7CE146C967AABFCAULL, 
            0x86210F401860EE0DULL, 0x8941870738606649ULL, 0x22913D9B87B9FCC7ULL, 0xEE968F63C7FEB55DULL
        },
        {
            0x333848CFB04E215CULL, 0x4BC2666A865DC83EULL, 0xFF43C08FD59803D8ULL, 0xB62CF738112245EEULL, 
            0xEFD4704D220A49C7ULL, 0x18C5F48410B91385ULL, 0x430389B6874BCEA3ULL, 0xF911A3AB6D0080F7ULL, 
            0x4F766FE75D95D4D3ULL, 0xBCA597B13F36986BULL, 0xCA56E9652F290C03ULL, 0xCDF0C5FA2E3FEBCDULL, 
            0x86D13EB9669618EBULL, 0x8FB3060E0C64BB32ULL, 0x53AC75E4F261F2C0ULL, 0x02C3ED6761820C29ULL, 
            0xC0AE4E9206BB7848ULL, 0x2F470AE43012D2A6ULL, 0xBC18C288EB30AB2EULL, 0x335D9E716EA0CF47ULL, 
            0x6AFC90E3CE2692CBULL, 0xE782136922CD92D1ULL, 0x9B40A24D4C79F6DBULL, 0xB54AC02F24EBA974ULL, 
            0x1AF072C113681FF3ULL, 0x70B7868FEE372CA9ULL, 0x9E893E37B3199058ULL, 0x1ABD41B768EA8474ULL, 
            0x11988E2F3B9FA560ULL, 0xCFC96ECEBAEAFE9AULL, 0x482423DE5DAF073AULL, 0x4B5FA2C3B0B31969ULL
        },
        {
            0xAFA3FFD7FB5DF8AEULL, 0x06DAFD056834E95DULL, 0xA2768E534501053EULL, 0x362325B2645BDB34ULL, 
            0x52EB3F9B320E6C7CULL, 0x33D44E6E1503277BULL, 0x1EAC4E18EC45CA7AULL, 0x9BFD6B337C910C2BULL, 
            0x83AEF7C8D0C82315ULL, 0x3ECF95FE99B47BE6ULL, 0xC037A4FF0D1580F5ULL, 0x6D8FA7DBF5E92F77ULL, 
            0x293677045A8FF97DULL, 0xBDC3C83B3E51DF47ULL, 0x7070E8A6C3283310ULL, 0x2943F9ABF6336FFEULL, 
            0x328AA135401E3F0DULL, 0x8B4DAA9A69B1A598ULL, 0x9DAE90030A746BE1ULL, 0xA7DC178B64A043EDULL, 
            0x68CA3A6BE34590AAULL, 0x1C600C108361C203ULL, 0xD2E352BC5CD6FF7DULL, 0xBEF869D9041473E9ULL, 
            0xA9919BD3F378D39EULL, 0xC8E56E28E59BE0B9ULL, 0xA9E6CC52F89E302CULL, 0xF93F7E17ECBCB3D1ULL, 
            0x36772647C9BD23AFULL, 0xF82F625ECB89B9AAULL, 0x1824F6FDECD6CAC2ULL, 0x2ACB42D9A470D2D3ULL
        },
        {
            0x6EF15091E350C029ULL, 0x1416B49EB3E6CDFAULL, 0x6094F5DBE6E92D7EULL, 0x8E20308DB08A30BAULL, 
            0xFF78745D52CB78EFULL, 0xB519C363436A7666ULL, 0x56975DED1D3AF5C8ULL, 0x85CEAB5FB224AC41ULL, 
            0x211E8C3E61EA7361ULL, 0x7BEEC50BBD6B1675ULL, 0xB7144430A6645F1BULL, 0x744478EA3D326E39ULL, 
            0xF4F55266CDC1CDCFULL, 0x0416358240A845C0ULL, 0x0244DD82384070B5ULL, 0xBBFD76CA11D276BAULL, 
            0xD80A28E9EB99EC26ULL, 0xD2EB5079A71EC764ULL, 0x545FABBFD5FEDC80ULL, 0x708C77E4598B7708ULL, 
            0x50AABE7E12B4344CULL, 0x9E117E05B7D6735DULL, 0x6C8CF934F577F3BEULL, 0x67CA33B29A095783ULL, 
            0x0E76665D49D7A472ULL, 0xD43DB7756F29D1D1ULL, 0x4809FF8E490C9170ULL, 0x3E86A715DD5BCBB7ULL, 
            0xF44A5E280E7FFF29ULL, 0x778FFE2DFFC04C1DULL, 0x45E7E9EE8B092720ULL, 0xC696B1B172A04783ULL
        },
        {
            0x180DA8AA07312339ULL, 0x060764448CF78A0BULL, 0xAD32447B4F740C18ULL, 0x3D340BD331676F11ULL, 
            0x197C49EA25FAB25FULL, 0xDC5BAD1223EEC437ULL, 0xEBF24A2F68CAA1BDULL, 0x238A8D71FC204E86ULL, 
            0xCECF984778045114ULL, 0x97B8809B1CB627E1ULL, 0xE0B77B5E9FD1D18AULL, 0x4A3AE12EB8EE62EFULL, 
            0x39FF60EC761EE13FULL, 0x169F4B3BC3D1D08AULL, 0x7DA62CB610F26794ULL, 0x4432FF33C01AE21BULL, 
            0x038FE7B4BF604211ULL, 0x9B90225D1AB7E322ULL, 0x112EACBC2199AFAEULL, 0xC69C3593BBE5A7C5ULL, 
            0xAC1A9492AB5E2A9AULL, 0x4397159BEC47B06FULL, 0x4056378F63BF60C3ULL, 0xC1C6765F679918D2ULL, 
            0x6AC1F0899152C2B6ULL, 0x5D9AC1923511B9AEULL, 0x25B0B2D862C754C4ULL, 0x19956778F6A825BEULL, 
            0xE9CA8F03074ACC2EULL, 0x74CA6F46F23A9D47ULL, 0xA5DB54EE9D0E0EE6ULL, 0x67D3897088453DDBULL
        },
        {
            0xEF546A9646CBC317ULL, 0x9C85718BF1B962AAULL, 0xDAB7A942040D3052ULL, 0x07E63349FB406A93ULL, 
            0x9D236B7AA40893F3ULL, 0x8621E63DF6EEBC32ULL, 0x61EB8008EB2EC4F4ULL, 0x5791D9DE01C6A52AULL, 
            0x27CB0E1ED791763BULL, 0x28A2C8DC618D0DDCULL, 0x4B2D3E6408A54F4CULL, 0xA1A2CD6BFB167148ULL, 
            0x59BA6E8DF6C8BE2AULL, 0x69FE57472F043BC4ULL, 0x783354C1B7563004ULL, 0xDB23A2078B1A5A5DULL, 
            0xE564BB96A41AB93FULL, 0x5BD0700AB7841871ULL, 0xC1C12E7FB133A350ULL, 0xF76D641220E6391DULL, 
            0xF7C2318CFB302C43ULL, 0xDD17371226AF594BULL, 0xB3EE7E6D45E3764FULL, 0xE48752276AC68DC7ULL, 
            0x6C1C7D6639267EA3ULL, 0x05103DA1747F9126ULL, 0x852D68A431913D62ULL, 0x62B86D423F7AD2ADULL, 
            0xDAE0917503AA86EBULL, 0x899DD55B9ED42CA3ULL, 0xFCABE971A4FB0834ULL, 0x2A2B116D4025289FULL
        }
    },
    {
        {
            0x93DE127F6911AF9DULL, 0xB1CE3F7AC35B50A0ULL, 0x21D90B310A9B0EC7ULL, 0x58D04AAAB30B4497ULL, 
            0xE0D58557681EC040ULL, 0x1830E8B2758304C4ULL, 0x63451491005F2A55ULL, 0xE920AFB72E1E6D6BULL, 
            0x9A9D5698D3890F0FULL, 0x9018AA09FC08F1E4ULL, 0x09340DCD826CC1D7ULL, 0x8314AE236247D0F2ULL, 
            0xC431D185251ED6C1ULL, 0x4A092A8283A9A57DULL, 0x6E9EB36094738CEEULL, 0x5808BBD3C17CEF8CULL, 
            0x3AB384811AE09881ULL, 0xCD1E0DD09E468923ULL, 0x0310C7D3F4584ED2ULL, 0xE0221C8376621071ULL, 
            0x56A30D3026276AADULL, 0x64E18976A3D1CB99ULL, 0xD3D3F00C4D752D85ULL, 0x63EC62E599AFF542ULL, 
            0x8FB9B1E809EC3740ULL, 0xCE96F0C7FE8B5FC2ULL, 0x95F8D557BA30E046ULL, 0xD812E4F4EB67AD6BULL, 
            0x36ECF37D4B202B27ULL, 0x9823C3A5DFC83E5BULL, 0xE67DF68B5564201FULL, 0xA67D6F5E8B183D00ULL
        },
        {
            0x8B3872240E383FA5ULL, 0x971A99788C3B408FULL, 0x258B0425AB0CEEEEULL, 0x2F8CB27E611BFABFULL, 
            0x022A23454E025730ULL, 0xD9C002E248DB73B2ULL, 0x0ED8D2181D32DE95ULL, 0x1101F7BDDB780A61ULL, 
            0x3417EA0A448F1915ULL, 0x353FED68E524852AULL, 0x6D85973B5476E37DULL, 0x1E9A7129F723ABABULL, 
            0xCDF9EA6581B5E2FCULL, 0xAE06F1DD0C4399CCULL, 0xB90E4C330D971F65ULL, 0x98614ABAC9E347D2ULL, 
            0xD32EADEECCCC87ACULL, 0x6D08F043989C5F93ULL, 0xC35D93E8192BAB60ULL, 0x8280EA0838D92512ULL, 
            0x5DE62913B16EBAB9ULL, 0xDD19C435C1F86AA8ULL, 0xE31AE01863DBCCD1ULL, 0x0E0C5803CF3ADB00ULL, 
            0xC824F3AD829B0830ULL, 0x63D79A721447955AULL, 0x8F35ACB4EA3544ACULL, 0x0F90B122B4ED220DULL, 
            0x1D6C514F9CB77080ULL, 0x3345A60E4CF97C40ULL, 0x66DF00879CE9ADDEULL, 0xA4D659152DB89D5DULL
        },
        {
            0xC5B80822A2F3A00CULL, 0x4CD3758741E23054ULL, 0xFA3468E8EA492F2DULL, 0x6E12FF15F66ED69BULL, 
            0x513068C5580C4C6EULL, 0xAB401430AE00C3B6ULL, 0x0B7566FD092B94DBULL, 0xC949FAC6475522DCULL, 
            0xCF157B0FBB02CC83ULL, 0xFB57DE7DC0261E5EULL, 0xF7E544FD74FBFA40ULL, 0xC5FA58C514D883A8ULL, 
            0xE3A517562E6D7BE1ULL, 0x8F27BE6B9466F4FEULL, 0x8A676F1610DB9106ULL, 0x1644619E75C57B96ULL, 
            0x56E91B7818169203ULL, 0xB2852039D78D3E84ULL, 0x4F8C5A0A7B565839ULL, 0x08C7D11E83985978ULL, 
            0x0AAE70BB2F234F55ULL, 0xAF14DA6885C922FCULL, 0xDCE845A96919E4C3ULL, 0xCC5963AA0329A969ULL, 
            0x5FDBF8DA434ED8A1ULL, 0x6082AAEF7A70E47FULL, 0x270FDF747C8D632EULL, 0x4B17EE62D90632FFULL, 
            0x06E23B12FD7DD080ULL, 0xB8490E45BFCA55ACULL, 0xD458A3177223755AULL, 0xBFD699BCD08294DCULL
        },
        {
            0xF47B24B23882C0E8ULL, 0xB06168377A08E7C1ULL, 0xB424F76F86185B9DULL, 0x794EF64815F6F49BULL, 
            0x283BD2C36BB8CABEULL, 0x808C87A3ECD97734ULL, 0x1EBC4D781E1B5474ULL, 0xCC47B359ADD33F4CULL, 
            0xE5EC197A5B842B0AULL, 0x043FCAA268F4DC48ULL, 0x412D2693886EA978ULL, 0x096C8B25BD022172ULL, 
            0x57AAEEC0A2E9916AULL, 0xCA62F977CA3F031EULL, 0x1558E94E3083F4DDULL, 0xB7B1E63C2B243840ULL, 
            0x53AB69BE9ED0FE5CULL, 0xEA968570EC7F56C8ULL, 0x05A09CEA573AC2D7ULL, 0x02ABCC9334B549B0ULL, 
            0xBFD477F80CAA880EULL, 0x53DB05B6BA7F0AD4ULL, 0x2A7CC6EEE020DB19ULL, 0x9354A95A9C35894FULL, 
            0xD02871EA85C087B5ULL, 0x089E19F7E460A08FULL, 0xD8C35394150066E6ULL, 0xD8B396B48EB88753ULL, 
            0x4F0D61C13E05507AULL, 0x0E58474EC56DC576ULL, 0xBD262B63A9F84A7FULL, 0xFA442227FD07BFABULL
        },
        {
            0xA74F69172A259EEEULL, 0x390E23DAFEA52BCBULL, 0xC6031603C3755FB9ULL, 0x6D4A01AF97D04A60ULL, 
            0xDA195DF562DB06EBULL, 0x424769425C7D0751ULL, 0xE9BD91504BDDD04DULL, 0x913491F8007E7CE9ULL, 
            0x200651AEEE812D62ULL, 0x95796078CD9289C4ULL, 0x4A07B55930898B3DULL, 0xD746505CC56CE835ULL, 
            0x8DE341DB9D79E26FULL, 0xE2369A643D500248ULL, 0x9E6C22EF19CACF79ULL, 0x3395C80347AAED23ULL, 
            0x2A52E610563F8860ULL, 0xBF346F264E5D0947ULL, 0xD81DA4F58A44BC38ULL, 0xD9A4D3BEA0AECFFCULL, 
            0x98E164B6B29FC8C0ULL, 0x10D5FFC541354828ULL, 0x91BB30767756D872ULL, 0x07DF41BF6D0C5D1EULL, 
            0x96A7232DC0ABE854ULL, 0x7607AC0200C90220ULL, 0xBF877185A81652CAULL, 0x2025575D99D94FB2ULL, 
            0x990EC084202AF970ULL, 0x3D5D0A18779A9E51ULL, 0xC7DB3B21BB37F496ULL, 0xB16F17E0EF6557BFULL
        },
        {
            0x79557B86688A19B3ULL, 0xD89E66664B2E850FULL, 0xBCDA3F25C15A6BF1ULL, 0x72FDDCB649A4EACCULL, 
            0xBE46DD5616FCA83FULL, 0x63502DEACA9C1711ULL, 0x8667C3947DC4DEBAULL, 0x8B56B280100873CDULL, 
            0x4717CD81860E52F4ULL, 0x7938E0B8BE087C26ULL, 0x4C1FB9312499DEDBULL, 0x30059F5B0716292BULL, 
            0x97251AC9E40986FDULL, 0x43D7017A05EF415BULL, 0x02FECC31FCB0A461ULL, 0x9D12E47F7C8201A3ULL, 
            0x8232B06180C5AA09ULL, 0x3AB3DF729901D002ULL, 0x3F486C242C074A53ULL, 0xBB6F9EDEF7CDEF03ULL, 
            0x5A5309E20517C56AULL, 0x376EE0D8D4C618A6ULL, 0x4218B491270280E1ULL, 0x6D017E37BE91DD26ULL, 
            0xA76256BF46785092ULL, 0x8A8E861563893164ULL, 0x4E610340FD2EF47EULL, 0x248F92671D56B136ULL, 
            0xB02A259B0BEEE193ULL, 0x26E52322CEA8CDA1ULL, 0x1D06D4337C1EE535ULL, 0xC4DEEB615E2B37E5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseBConstants = {
    0xB0DC478A70F15049ULL,
    0xD987AF933AA7018FULL,
    0x692E61E97D38AD65ULL,
    0xB0DC478A70F15049ULL,
    0xD987AF933AA7018FULL,
    0x692E61E97D38AD65ULL,
    0x556BB91DA581EA24ULL,
    0x1EAD6C3C7D6A26C5ULL,
    0xFE,
    0x6D,
    0xDA,
    0x02,
    0xB6,
    0x1F,
    0x26,
    0x39
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseCSalts = {
    {
        {
            0xC2D5B06020F144B2ULL, 0x40EFDC06079F6DD6ULL, 0x98ABB89F933AD912ULL, 0xDEAB3CF963B01DA7ULL, 
            0x1A1BEBCF791D50DEULL, 0xD3D25DEAF5A5ED3EULL, 0x8ED3D060A12E818DULL, 0x10DE438B38B08B2AULL, 
            0xDB7A63B21883523CULL, 0x578C4B171B00E728ULL, 0x7E3FE2B525CA50CBULL, 0x303A5FCC69247BAEULL, 
            0x20AD81F939893766ULL, 0xEDF54CDFF568B037ULL, 0x70025B2D8DA3D6D7ULL, 0x0704203B431E71A9ULL, 
            0x5FA5B7C14B6FF0E3ULL, 0x8202894CC53298E2ULL, 0xADE7B95A86151B47ULL, 0xDFC43E14E8CF3D44ULL, 
            0x9DC714B7DC604084ULL, 0x9CDE6A17ABB05ECDULL, 0xC7EBF4D99D3FE013ULL, 0x6FA0000A4B0A2C54ULL, 
            0xF5AE02F3C9136A29ULL, 0x3DD885816F62B642ULL, 0x7FC21772C7A40F90ULL, 0x3A38C65A66B8EAAAULL, 
            0x6B418ED91E2E2994ULL, 0x8C4D878B56B1C88DULL, 0xB0BAD61072B83BAEULL, 0x05D599DCB93C117FULL
        },
        {
            0xE32728A8E9858BF8ULL, 0x597BD973BB4FCC3FULL, 0x09FB98DEE272812AULL, 0xDAA489B703064ADFULL, 
            0x0C1523BB9F5CFB84ULL, 0x793FF8810B0E6279ULL, 0x0EE21220913EA211ULL, 0xF68E5ACC890A6F12ULL, 
            0xEB6F50850E43BE44ULL, 0x7BD426F05FF17AB8ULL, 0x6ADC3F4908A4B65AULL, 0x236ABDFFB185BE78ULL, 
            0x37ED81A4A23240A0ULL, 0x4D984AFDF09615C7ULL, 0x7EF51A9C699CE380ULL, 0xA7D8B829C468593CULL, 
            0xB2704F35244C1793ULL, 0xE7F877C046DBA37FULL, 0x471747A5BC6EB68BULL, 0xBBC47259F0B6E6D0ULL, 
            0x078B2AE040F6A07EULL, 0x1838AA4915DF7ABFULL, 0x3171CDBCC8722A7AULL, 0x9A14CDBDEE65C545ULL, 
            0xC48B0E25560F5C32ULL, 0x8EAAE184B6952B79ULL, 0x8446591995FDA9D4ULL, 0x1B03DE0837836386ULL, 
            0xED9B36B121CD26EBULL, 0xCE990FF737346030ULL, 0xC8767152162E2822ULL, 0xBD83F1C20A2400DFULL
        },
        {
            0xBC61CC74CB8297C4ULL, 0x957D788FB258D533ULL, 0x04BA3128F9636495ULL, 0x935783C67E0C2F5CULL, 
            0xEEF02ECEAD27DC3FULL, 0x24472C44B719B144ULL, 0xA324B9A3709A763DULL, 0xE17E21B7E9E1429FULL, 
            0x2E2A4CF0A8DADA98ULL, 0xC1F99B8C40633211ULL, 0xC7A42491F45C6C58ULL, 0x24201AB54DDF8478ULL, 
            0x47C5165B146B8566ULL, 0xE645290630E91CBDULL, 0xA6D3A0961B7E14DAULL, 0xA043F3376A21A8F5ULL, 
            0x44F8C22DBA6B3427ULL, 0xE8BB1B97123D4CACULL, 0x5C2FEF97AC78C140ULL, 0x8CBE3DE0102EB5D5ULL, 
            0xD11B053E9E3464D3ULL, 0x30EFA6D3CD932493ULL, 0xF86301EB3186D8EBULL, 0x604C8E261D26CD0AULL, 
            0x81B4826A1B3D9F59ULL, 0x0699060398A0FC50ULL, 0xDF02A8BA9A3B76D4ULL, 0xE15EC9F8B3A7E91DULL, 
            0xDC4DDAA1B291A79BULL, 0xCE250CE80CF3908BULL, 0x08BAB695CD9D746FULL, 0xFB351C3CA7B66D9BULL
        },
        {
            0x7FA47EBA5E4804B1ULL, 0xC71A44F625063D6DULL, 0x65F17A25C73390C2ULL, 0xB5769E4FB8A4A675ULL, 
            0xCC6949A2E4A8EEE8ULL, 0x031889DC3E7EDB9EULL, 0x8EAB46171D952243ULL, 0xE2AA314DF208D701ULL, 
            0x20FA6EEFEDB798D4ULL, 0xA0AE3056C55C2A18ULL, 0x99F221BEBF9A383EULL, 0xCA5C10A2DC81B9F8ULL, 
            0xA7EC44C8893D69DBULL, 0x16272B398CDF5258ULL, 0xE9A10BC868901C20ULL, 0x4EC31DD99FF15198ULL, 
            0x2BF805E5BF787364ULL, 0x9B0791260D1AF040ULL, 0xB8768225823FBB78ULL, 0xF06B05AE207E8CA7ULL, 
            0xF9DD95ED54BDB40BULL, 0xCE82D86C10B7FAF3ULL, 0x2C447A45AE5CBAB8ULL, 0x628DD36570384C26ULL, 
            0x79A7CC57E7A69B13ULL, 0x047B44E9C6C5582DULL, 0x4DD46130F01667E0ULL, 0x465ECBDE76A0C1C2ULL, 
            0xC6B1652A3F2DE364ULL, 0xB79E34E2406050FCULL, 0x546D0C1C6ED47224ULL, 0x2DE2775D3C64DEB5ULL
        },
        {
            0x8EEB268399597365ULL, 0xD1E388674DE5E99DULL, 0x0C48CE9B244DCF1EULL, 0x8FA53BF737F9703CULL, 
            0x4D9EFBD4A242DE85ULL, 0x5CFF504CA448F2D8ULL, 0x2A0C972E8D890B41ULL, 0xBBF346026F631A74ULL, 
            0x3C549E6D5DD97685ULL, 0x11ACB805689F20F0ULL, 0xB0F27C0F248E545DULL, 0x8FED5423CA20071FULL, 
            0x8AB9465B9599A14BULL, 0xCE3619B7C55F7B45ULL, 0xFEA840356168A3AEULL, 0x9045CA1109FB9DA5ULL, 
            0x7F6380C45E2DEDE0ULL, 0xA6DDE15A6E5FB8AEULL, 0x3C094ECB2CAB3CEDULL, 0xBCEDD3D458C289DAULL, 
            0xE95BF7CD6723D1F6ULL, 0x613CED6A01747624ULL, 0xF10922FA62E7DE37ULL, 0x4915753F123BB7C1ULL, 
            0x93F4FBB173D7317CULL, 0x9779D84C94B39471ULL, 0x529890E010C50571ULL, 0xE2D7E7E1AA42C1AEULL, 
            0x4555781EC1E0AF3EULL, 0xB2C7203823986D96ULL, 0xE8D4DA1E6F218D5DULL, 0x260916CA09468D68ULL
        },
        {
            0xC975FAD4CFBFEDBEULL, 0x9F890629F76FF4F0ULL, 0x5AE4F50594A3394DULL, 0xD1C0BA38C5B3639CULL, 
            0xAC83E6554E7EEA92ULL, 0xAA861264979A4932ULL, 0x06D315D6ADD3549BULL, 0x487D5F2AEDECE779ULL, 
            0x39E6C6C43F018E21ULL, 0x692857E707452658ULL, 0x0688D7459B7BBE89ULL, 0x708C4793C6134DE0ULL, 
            0x2EB31AA73E5F2D74ULL, 0x91027F0B1694214CULL, 0x76F4F7AD322FE61BULL, 0x5DF5BAA8BD8F8E9EULL, 
            0x708C582E4FC24C29ULL, 0xC4BDED9A918BC9FAULL, 0x16DD303313FC29BDULL, 0x7524DD8828AFBBFAULL, 
            0x927F4F0924708C13ULL, 0x4C83DDEBCC839C53ULL, 0xA9CA524BA7D3DC96ULL, 0xF4E87947861BFD55ULL, 
            0x8B93540974D085E3ULL, 0xA9EE0576A9D63FDCULL, 0x26C408EF3D4F8381ULL, 0x68B701490545CCB0ULL, 
            0x5A11EBD15A71B07BULL, 0x0883E17DC85F4CE7ULL, 0x496ED5E9A5B130B6ULL, 0xE9687D43303BD7D2ULL
        }
    },
    {
        {
            0x813D0873D6AC09B1ULL, 0xA1620110AFED3DA7ULL, 0x965634CB5718B09DULL, 0x0CF02F04F5CC5817ULL, 
            0xAC5A0351DC375527ULL, 0x362FC84C8BB3EC7BULL, 0xD348668203DC15B9ULL, 0xF28B5420994F8A70ULL, 
            0xD647D0E7777DE422ULL, 0x5D346CECE5FC4AFCULL, 0x5DE09FA45D38842DULL, 0x9C11C69E6EDA5939ULL, 
            0x947676DE23E06205ULL, 0xC137A99AED7C77F9ULL, 0x139ED341CBC83B41ULL, 0xCEB80B6A824DF3A3ULL, 
            0x6234D0FF66C0523BULL, 0xF5614A3A6FC103FAULL, 0xE016191A8DF52174ULL, 0x0FBC6A4A1A702BC2ULL, 
            0x34C54ECA2CC67816ULL, 0x50F742F8AF8AB60BULL, 0xCE9617924EE700B5ULL, 0x58E0C5BD9C3C3F1AULL, 
            0xF4B1CA2357621482ULL, 0xDEC499C2105CF54AULL, 0x25D51037D4734DF2ULL, 0x8CAB45FEBD528084ULL, 
            0xC03796318ABA2ECBULL, 0xA131367AFF4C4B1DULL, 0xAAC6AC993618810DULL, 0x0EDF916EBFF3C5BAULL
        },
        {
            0x331012984D3C6ED3ULL, 0xE65730CDEBC0F695ULL, 0x498473F112313447ULL, 0x190A4C5C134AC32CULL, 
            0x7ABBB5D95FD83608ULL, 0x74815A2800A96141ULL, 0xAA1098DFD15AC1C1ULL, 0xE51E88B3CB05CF77ULL, 
            0x20422FCEBC33FEDEULL, 0xE6A4F6EEA3DC8980ULL, 0x1F6C71B458EA572AULL, 0x853C39E9735FF82AULL, 
            0x25AAEE25A690E626ULL, 0x39ED92DFE4A2A9F4ULL, 0x154D86D8468E011CULL, 0x38651672B9EAD631ULL, 
            0xADC7311150394EDFULL, 0xB2DB8432AF3E6F16ULL, 0x025283102E77D5CBULL, 0xC627FCE55F0279BEULL, 
            0xCFE32335F67A9279ULL, 0xF27091BA81EFFBCFULL, 0xCE0B028322D181C6ULL, 0xFF15F6976178E026ULL, 
            0x15C57A7122EF1866ULL, 0x10D511D89C8D2356ULL, 0xFF57CC1FADCC58E1ULL, 0xA4A2DE13AEFD6216ULL, 
            0x7BE237B6CD37DE38ULL, 0xFD01CBDDC909081AULL, 0x2F76FF54EF3EFFCFULL, 0xCF949F93684DE490ULL
        },
        {
            0x6753E3F3B20A598BULL, 0x016AF4E10F2058E0ULL, 0xB442211FC2242F1DULL, 0xDAC744F5C7C76076ULL, 
            0x77568C8CF51C61C3ULL, 0x778E538A3B96DAA7ULL, 0xDB75918F740D5E24ULL, 0xB568301C82497C89ULL, 
            0xC4404A78779ABC27ULL, 0x16F0211455C94ACAULL, 0xA91EAA86626A1903ULL, 0x064AFC9DE3EB2DB0ULL, 
            0x9787E758ED463A51ULL, 0x91653E0880412A51ULL, 0x65CB72FCD17C2F66ULL, 0x7983FE85D6970533ULL, 
            0xD8C98128BD1AD61FULL, 0x0DB6483E757C7562ULL, 0xA05700658C44A8E8ULL, 0x693BCBF17386E1A9ULL, 
            0x11F92B0FC6461522ULL, 0x426E305C483CF03AULL, 0x581D9DF5BA620638ULL, 0x10E56BFF05E9C86BULL, 
            0x6AA4FC2D4F59530CULL, 0xCB8308A4FDD74084ULL, 0x533EFF917CC4B253ULL, 0x6B70E9A0DA0ABF9EULL, 
            0xCD119F3EE5D5A0EEULL, 0x0FE9492980CA3DA5ULL, 0x6DF92B0B0081B420ULL, 0xC8247CCEDA705F4DULL
        },
        {
            0x21311BE87C2ADCA8ULL, 0x0D85B83E39A6FE89ULL, 0x17A7C4F68D5FA232ULL, 0x10648227C3DB302EULL, 
            0x8B24717236CCC207ULL, 0xF33FA1B9F1FBBC8DULL, 0xCD9D1E3913B81CBEULL, 0x8566D7DD7ED181C3ULL, 
            0xA47042C45806A3C8ULL, 0x9B41228F5867ED34ULL, 0x45771FE651E0F6BAULL, 0x4ED7DFEA692028B6ULL, 
            0x30500BAA12A402C3ULL, 0x0B69259B5C055FE3ULL, 0xB47500F7297539A4ULL, 0xEBCAE9EFFE74D71AULL, 
            0x463EF2B566F1CA4BULL, 0xA9A6A55FB8C67068ULL, 0x20D31CD4DC5881E8ULL, 0xECC8C0F41FD53C49ULL, 
            0xD334F38A5B966176ULL, 0xCE59AA3A65A286E4ULL, 0x53DAEA355A8DAD52ULL, 0x6944E4B34BA36EC6ULL, 
            0x02EF69C97C900A5FULL, 0xE2A0425B982E2538ULL, 0x5F0D0B857607C9D7ULL, 0x8AB8056820DD99B3ULL, 
            0x4A8137EC79254EAEULL, 0x3B3519117883793AULL, 0xB185FE913BD42F8EULL, 0xF9ADFD73CCC6B9F1ULL
        },
        {
            0xA234B183DF20E0ECULL, 0xB11044A9DBB70410ULL, 0x34ECD500C9F9AA13ULL, 0x92E0240D49190F7FULL, 
            0x79C4DA5F06796CCBULL, 0x8ED431CAF750E6BBULL, 0x499B01820B956A37ULL, 0x6687A6E3D5139B24ULL, 
            0x2B94842AA9FEC95FULL, 0xD27528A615D9794CULL, 0xE4F3E84BA3EA9CC3ULL, 0xCCF64DED5A1FE514ULL, 
            0xFF25D80A7A10CA80ULL, 0x9FC26BC246423A93ULL, 0xCFBBC3817E8F434CULL, 0xDAE209B0D8E80FB1ULL, 
            0xC017357C90A91BB1ULL, 0x4482F7383BE7898BULL, 0x5C6CB848AFEE188DULL, 0x598D1BEE41F9593DULL, 
            0x62B195491AF56FDFULL, 0x6506D2A661E7CA61ULL, 0x07A7DD0DFA2A1EB6ULL, 0xC21B69494DA7B410ULL, 
            0x83F1D24B97E8D535ULL, 0x50F4061C4AB84FCBULL, 0xCE86679A10725CF0ULL, 0x33272A7DC0300E14ULL, 
            0xD2AE72A64CC02D50ULL, 0x529D4F660C580E8EULL, 0xD40EA5334945F3F8ULL, 0x2FA60591E80E9D2CULL
        },
        {
            0xA79F5B3CC3F0F792ULL, 0x98DB2358727F07CEULL, 0x485A83C6B11F49A9ULL, 0x9E7CDC771EB9997FULL, 
            0x010F5EB8AE80CF8BULL, 0xBCAC3F2178D32169ULL, 0xDBD2E23106B77B53ULL, 0x4DE66D7B68A6CB54ULL, 
            0x141083C4241B9FC8ULL, 0x55ECBCEB1659CC41ULL, 0xDB892DDDF6932BFBULL, 0x3A20FEAC68F32B4EULL, 
            0xB278D7341B2E6AC9ULL, 0xBFED1B9CE3ECEC0EULL, 0x510159451104767DULL, 0x5FF4A421AADB852DULL, 
            0x97ABF0C7C0C8AEB6ULL, 0x22613D1386F389D2ULL, 0x919B71AFFC62CE14ULL, 0xE92BF2634C35A9FDULL, 
            0x7E87DB2F6DB20A4AULL, 0xDD370010616C7F0BULL, 0xF4BA8B5AECECE3E9ULL, 0x9C05E266F48742BFULL, 
            0x6F1692F8969672C6ULL, 0xC122BE7066387380ULL, 0x8E54DC106F3DCAD1ULL, 0x1F8A939938AB71A4ULL, 
            0xB0683679A301D409ULL, 0x9D03D59915CC7DA5ULL, 0x492BE40237C5CA01ULL, 0xE590B02002496543ULL
        }
    },
    {
        {
            0xDF618D6D116A0703ULL, 0x75225F235CE94BD0ULL, 0xEA8AD14350CF08ECULL, 0x3C877D53F2F41544ULL, 
            0xEA9F4DB9CBB900A1ULL, 0xFAB2370EFAE307C2ULL, 0x520CB528F066D4B5ULL, 0xDF3005E2577D335DULL, 
            0x4464CAA75D97EC20ULL, 0xB2BC83FFFFE854DCULL, 0xE093725CC8FB60A0ULL, 0xECED09E67F6D65FDULL, 
            0x446AD03F960508B8ULL, 0xD8BE20D80CB78FCBULL, 0x932FEA73B9842547ULL, 0x63462CACA6BD35BFULL, 
            0xE0447E3B714B8559ULL, 0x5678785CA66835FDULL, 0x69619945279DE88FULL, 0xECD1619CB091784FULL, 
            0x3D429B1A79FB0470ULL, 0x44186023C60D448FULL, 0x9D72EA61E9C373A7ULL, 0xD34E02507B96C8C9ULL, 
            0x94CB4A46F8821793ULL, 0x20CC8C49B7B08E6CULL, 0xE17E6357565D02C5ULL, 0x85087545A39B58B2ULL, 
            0xCEECC7C30A89499FULL, 0xA0830CF41F2E5890ULL, 0x910239DC2CD68FB2ULL, 0x87224277DDBA61D1ULL
        },
        {
            0x9BE53B5F9CEC4D1FULL, 0x5AC75D1086CDFDC4ULL, 0x937BD25CA62A7A1EULL, 0xFEA2047F65ADD535ULL, 
            0x663279B4EDE77279ULL, 0xF8DD9A78AA29C57BULL, 0x738A3A95713D2842ULL, 0x92EC0E4F0584AF73ULL, 
            0xACDE7645FEB8BD57ULL, 0x3C709C7ECF767920ULL, 0xA56E4725599E5CDCULL, 0x815DD89F75F111C5ULL, 
            0x382DC42A8A73C8D9ULL, 0xD35E959BF16DA688ULL, 0x0A3BCAD76C9360CFULL, 0xF836CA979B999CC3ULL, 
            0x1A31A3E4848C30CFULL, 0xA690068D7AD7999BULL, 0xDAAF0369FE34C53BULL, 0x920154A463231E8CULL, 
            0x1D3CDCDA26299D8DULL, 0xA75644CD68BA72AEULL, 0x991D6060098E25F4ULL, 0x0BFD397988A9ECD3ULL, 
            0xA32CB7823CA09408ULL, 0x1007599B10696137ULL, 0xA6C75CF76A24B489ULL, 0x3ED250A7C048892AULL, 
            0xD4C1C24775B298B2ULL, 0x2CF975216F03AC47ULL, 0xB1BAB97302AF49C5ULL, 0x69F47006DA8E0018ULL
        },
        {
            0x3866179DCC27D527ULL, 0x2DF02F38EB5B7C05ULL, 0x46052EE6E55C7DD2ULL, 0x2ADF3B65562A55F1ULL, 
            0x87287DD6EC005466ULL, 0x03FF14C80104FC9DULL, 0xAE3931C301637F32ULL, 0x6C50251D4E651F31ULL, 
            0x8E21FCF3ECCE706FULL, 0xD3B60B254D030348ULL, 0x42F2536B1CCDDEAEULL, 0x8B43C19E9C660D65ULL, 
            0xAE14ABDF04682F7BULL, 0x4B3A92A4DAA9A017ULL, 0xCBE0E3A6998160AAULL, 0x8C7A579CA8FED052ULL, 
            0xF25BABCBB5C55E58ULL, 0xD88355C64833A48CULL, 0x8967113CF934B6D4ULL, 0xC1F2621E8A637A22ULL, 
            0xCF5F897F0C587906ULL, 0x14306F71C4E34036ULL, 0xBED73DD8C879F74EULL, 0xAD4CFDF9F947A501ULL, 
            0x7131650E14632106ULL, 0x7DC7FC6B5F1F4154ULL, 0xB782F76AC0DB0B6EULL, 0xD3290030EE75DA6DULL, 
            0x44D294729912F35AULL, 0xAAB8B15DA29B5927ULL, 0x6974BE934CB0B962ULL, 0xABEA96A0DDEAD1E1ULL
        },
        {
            0xCE50D2BBDDC2C5C9ULL, 0x9C105C6809A6D396ULL, 0x892511C7D8A5CFB3ULL, 0xA07A7E582A643E29ULL, 
            0xDE9E9C6AF0591F62ULL, 0xCC10F7CB82AD1173ULL, 0x2B9A49097566FEADULL, 0x0901E5B0EADB5BB2ULL, 
            0x68373FEACED30A45ULL, 0x66DD6402962DAAEEULL, 0x2C0346182FB58F72ULL, 0x46F890A227E6BA23ULL, 
            0xE50C05A58C6D7E4DULL, 0x6A8D7182B18BA13BULL, 0x68B2D1A937603227ULL, 0x4ED220D80E323D41ULL, 
            0x0BF475584A6262E9ULL, 0xEFAF0F22F9A0EF0DULL, 0xE68C485738899E7EULL, 0xFCF035D91BDC0192ULL, 
            0x06566A6E470E7BF2ULL, 0x2D11C4E7EE72C45FULL, 0x492867F6405BB2F1ULL, 0xFF3A4E113AE0BF02ULL, 
            0x34C9B716F6D232AAULL, 0x3C0BEDA71CE2208CULL, 0xEB14B7886251F714ULL, 0x1D383A475F8F62F8ULL, 
            0x833C70A2B5F643EBULL, 0xB308C333E30CF0B9ULL, 0xBA68EC80A5FE365FULL, 0x8142C710BF9C9530ULL
        },
        {
            0x56C0ACD4A8C2C222ULL, 0x0659FA840D891C12ULL, 0x426324B7FF010FD0ULL, 0x91A487A3D2452C3FULL, 
            0x67D280CB24509CD8ULL, 0x1B5EB0DBB68C7E76ULL, 0xEB719473CDCA94ADULL, 0x6B71DE5D879A4093ULL, 
            0x09E82B3E17F1FCC8ULL, 0xD31F775CBFCD367FULL, 0x1049028A915BB94AULL, 0x7C3FE291002C1095ULL, 
            0xC7C7005A290DD733ULL, 0xD1CBE5F5D6A4C5F0ULL, 0xEB99004BB9B2BBFDULL, 0xC9A4464B9994EA50ULL, 
            0x6207191ACD27EFD2ULL, 0xB8A01AC44116158EULL, 0xF03F80392166902CULL, 0xB2C4158D26413F46ULL, 
            0x957AF30708E8262AULL, 0x1A7270F8039F3812ULL, 0x89A5EA9E8DC7C110ULL, 0x9ADCC06DAA733016ULL, 
            0x2BEB12DF21F551E1ULL, 0xAA7E80D80BA0BAAEULL, 0x042F24DBAB5A5263ULL, 0xE3D95B870FF02717ULL, 
            0x1330DE898A658C06ULL, 0xCD672F86007BA34BULL, 0x45B14E695AD83FBEULL, 0x70E4BB9A6367CDA7ULL
        },
        {
            0x136625E6C3255290ULL, 0xF00FE9DC0B2F520CULL, 0x621C81B2394ACD9EULL, 0xC80C39E1603917A6ULL, 
            0xB0A1DA214BF9EE1DULL, 0xC798834008C2CDC2ULL, 0x5B2B3772AB109357ULL, 0x92E83A1FDC4A1378ULL, 
            0x4C3C4330BEB84810ULL, 0x952CF3CB7A463054ULL, 0x1FC0603AA90496B0ULL, 0x83472F59104EA583ULL, 
            0x8B6ED845BE68C7F0ULL, 0xFE26DED77F5EC3FDULL, 0x0142213AC494C76CULL, 0x94D5EDD89F86EB17ULL, 
            0xA72D3E1AFAC42CE5ULL, 0xDA89DA17DACFAF1FULL, 0x5942D0E683CD4361ULL, 0x31FB3D49E53FAF4AULL, 
            0x80C61E4276692F5CULL, 0x2265CCF17026F8EEULL, 0xA475B5B73CDC112CULL, 0x4B10412124219A8EULL, 
            0xC6AAB0026ECE7709ULL, 0x06CAAF7FC3A21013ULL, 0x4E9AB29F9C98C15BULL, 0x54046C3C9B40B8CCULL, 
            0x77A0F628ADF619A3ULL, 0x0CA3D99907A71C67ULL, 0x55153ED99A7793D1ULL, 0xE97658617ED8D97BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseCConstants = {
    0x2C03C7FC64446CA5ULL,
    0xEDFB3B8A4E77C55AULL,
    0x4E376D059B78A0C3ULL,
    0x2C03C7FC64446CA5ULL,
    0xEDFB3B8A4E77C55AULL,
    0x4E376D059B78A0C3ULL,
    0xE2053D5EC58A0763ULL,
    0x3A12748FC40259B7ULL,
    0xD7,
    0xC5,
    0x23,
    0xB4,
    0x7C,
    0xA7,
    0x4F,
    0xC1
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseDSalts = {
    {
        {
            0xFD290D6350F19674ULL, 0xBB319216E7FA1E47ULL, 0x55FF7AFE47DAFF12ULL, 0x63E39416D211E2E0ULL, 
            0x5ACB114160153CD4ULL, 0x497690C51DDE0917ULL, 0x624283B9D8B289F7ULL, 0x11B8B7C269A7FA95ULL, 
            0x1D165ACC3EB037BAULL, 0x2981B45AA51B4635ULL, 0xF4B5BF2A45527810ULL, 0x1C2B03EC598E6E11ULL, 
            0x49910CD916AE01E5ULL, 0x290CBDEB69141C1CULL, 0x5D2094D2F4085DBAULL, 0x65F30EB3ADFBFB05ULL, 
            0x3578B67B4B323929ULL, 0xAECA993979118402ULL, 0x2B2039E049F917B6ULL, 0x8F98DF5179F50F46ULL, 
            0x91C27973DCA475C5ULL, 0x7F1E1CE82DCA046FULL, 0x15BCE7E0C98776C8ULL, 0xB88F201564F3438CULL, 
            0xFAB5B980BEE4B00AULL, 0xEEEF7557D7D2B254ULL, 0x0F2C9F86656158CCULL, 0xAAD61499996A200BULL, 
            0x0DBBCA796DC4AAAFULL, 0xD9D64A0D3F87E68CULL, 0x25532272D656C0A7ULL, 0xE4D86521DA9015C5ULL
        },
        {
            0x00193A5527EE8188ULL, 0xCC9CF4D6DAE49BF1ULL, 0xFFB40AB9A79B78D3ULL, 0x7CA0C07AFA5914F1ULL, 
            0x59FC0B21F559CD70ULL, 0xD5049B761B3297F7ULL, 0x3040246F05EFDA1BULL, 0x65FA50838FE07463ULL, 
            0x92E5EE3AE8E74CFDULL, 0x576C4DBC1244EC32ULL, 0x1C7A73DFCB1A4F81ULL, 0x56E5DB4866C1B0F6ULL, 
            0x7D7829C3751479B6ULL, 0xBD029934FF076435ULL, 0x1D9AC2FEC3DB432FULL, 0xD2590888998FDA8CULL, 
            0x7D475821C4ED03BAULL, 0x2B33EEC6CBAB9508ULL, 0x3F8584EA68823A3CULL, 0xD268150429585FC1ULL, 
            0x77F2E4643C3A1A0AULL, 0xDB4E4700F7F133F7ULL, 0xDED43851F37775F6ULL, 0x0F2D259979BC27ADULL, 
            0x2A716014294BA71CULL, 0x77EC356B6E60B1BDULL, 0x9AB2E47BE9B3B700ULL, 0xB8659F05ABAFA533ULL, 
            0x8315FAD80A5BC401ULL, 0x165D2D9349DB2F68ULL, 0x76288817E0808A8FULL, 0x3F51725149D69B06ULL
        },
        {
            0xFB13537883FC4ADAULL, 0x5C539BA0065432ACULL, 0xE0639A9BB8F45F28ULL, 0xD8C04ECF21F3B463ULL, 
            0xF0D1FC0A4814014DULL, 0x8E48BE5FB0FA4175ULL, 0x827BCF1D35BE6204ULL, 0x48744A5520CE03A7ULL, 
            0xA68368117A725ABFULL, 0x55CF4DE8185D6AD4ULL, 0xB89C01516C1F51AAULL, 0xE9935732E0D10048ULL, 
            0xAC7AD285D63878C4ULL, 0x481B78C4C5D4DCB3ULL, 0x69555AB16122852AULL, 0x36D64A272FCB9353ULL, 
            0x4172DAF4BDB923C0ULL, 0x6B644066C8F04BD5ULL, 0xBBA98DC405CC828AULL, 0x85F2B4D3AA7FFAE3ULL, 
            0xB7B7E66A05EAF597ULL, 0x3ECB47DAE2378DEEULL, 0xA8472905FA7B374CULL, 0xA129EB0EB5D4E5CDULL, 
            0x02C552F97C977E0FULL, 0x23DC12BEE8CE7BC1ULL, 0x8D7672A4D155A0DFULL, 0x5BA86C3FBCC50C95ULL, 
            0x937B434D6441BA69ULL, 0x29671FF5FA5457E3ULL, 0x73D5953FAA4542E5ULL, 0x752A1F2AE235799BULL
        },
        {
            0x2D155E85267ACC32ULL, 0xB0539D459B39FFBAULL, 0x6A079150C62E7081ULL, 0x9ECD614126F14C89ULL, 
            0x3CA03D67C148D2C9ULL, 0x65F1297B573D8532ULL, 0x5BC6377599D63C1DULL, 0x61DABB3C02A8449CULL, 
            0x18D51E728AA46F8DULL, 0x663B973FBD3887ACULL, 0xDFE6D5D8E4AD4C21ULL, 0x924A111AC508F3ADULL, 
            0x23EDD1CC85F5A9D0ULL, 0xBB2C29AD2A5FFAA1ULL, 0xC413906D7C382E17ULL, 0xF780DB03E9CADB0FULL, 
            0x4894F1D85DBFEC84ULL, 0xB389E01E6051BDF1ULL, 0x62C284135D96B4F5ULL, 0x7FDCA3B2E8B14828ULL, 
            0xA4287A0B366D84D1ULL, 0x073E986863F3232AULL, 0xF4D214FF5A78C30BULL, 0xB05E0D6770D6BCB1ULL, 
            0xB5A1E91A7D892674ULL, 0x47FC80CAF9019FAAULL, 0xB9C7F58CC5C577F2ULL, 0xB21FBAADE4458471ULL, 
            0x739AD4DAC166318DULL, 0xAA225E932912FEF0ULL, 0x00FDCF9F23A901ECULL, 0xD4F42B24A5CF64F3ULL
        },
        {
            0x9DEAEE7466C5BE4DULL, 0x3FE61332E99501A6ULL, 0xB390BECC67679590ULL, 0xEF859F683DB21BB5ULL, 
            0x35317F4F78E05040ULL, 0x2D168DD0BE8E776AULL, 0xF0E7A15E427E5823ULL, 0xE2D4E093FC695239ULL, 
            0xA30740E901261984ULL, 0xDFAA82C886A4C2B9ULL, 0x751553E93A97E227ULL, 0x9E838EFE7924A32BULL, 
            0x27E7C0C9D7EB1739ULL, 0x9ECC67279A2051A0ULL, 0xC235CEAAA5320687ULL, 0x29882076300DDE13ULL, 
            0x5DD52FD40CC3AED5ULL, 0x3381CF4FF89A80A9ULL, 0x7EC7A708A00F9665ULL, 0x7293153CDD640028ULL, 
            0xE00B7FC20F6CB838ULL, 0x59C72793C8EA578EULL, 0xF13838A53D382857ULL, 0x15B7B0EBDD2B0126ULL, 
            0xF17F18AF05CE53AAULL, 0x5FC827DAED8FB268ULL, 0xEA55289F426D788AULL, 0x53310631D15C3514ULL, 
            0xE02906B62281FA70ULL, 0xF06DDDFBDE097FCDULL, 0xE75D71CB74903004ULL, 0x52DDE4373894E9F2ULL
        },
        {
            0xB1E6DBB61A1F96C1ULL, 0x3B2E21CAC1729493ULL, 0x34C75418C220FA83ULL, 0x780FD1C558AEFE68ULL, 
            0xDFE3A8C1B8E4541AULL, 0x7BE2ED3961E9FB0EULL, 0x9EE9DEBF505B4583ULL, 0x15BD1F503C1AFB2AULL, 
            0x81D1B1F223952E56ULL, 0x23278FBEF08CAC66ULL, 0xD8171A9B02960A2FULL, 0xAD659F4EFCE05DFCULL, 
            0xB698499BCE36A0B9ULL, 0xB610CDDAB2DE690CULL, 0xF021C0A3B02F39D0ULL, 0x073DB0E561E31BC7ULL, 
            0x337E9EECB40697F2ULL, 0x78FCBD5DF0BB1394ULL, 0x086C5A647649EA7CULL, 0x60B998DE3BB5BF9CULL, 
            0xD1BCBF5E8B8DC4DCULL, 0xD4EDEEDFFE94BB17ULL, 0xE205A163CFBAA681ULL, 0xE33ED0598F3917E8ULL, 
            0xA08B36F8F165777FULL, 0x82C18A2FB6C8F58BULL, 0xC185D596BE741611ULL, 0x29851E0C788789BFULL, 
            0xEBF2321B8EC71ECCULL, 0x081F7DAF865AE5E1ULL, 0xA289D28555F8CA97ULL, 0x1D397076B04D7331ULL
        }
    },
    {
        {
            0x4E710B29F857BCE0ULL, 0x2F1F7589EF5FE2C2ULL, 0xD78E779A12BD1982ULL, 0x43C3F7FB564BC675ULL, 
            0xAE88BF57839B12F6ULL, 0x9558F47536897FB4ULL, 0x52A27FDE45B6006CULL, 0x31C52FA8DA4C3A8FULL, 
            0xB6F3ADC43A4D46D9ULL, 0xC62349EDAC1D5AABULL, 0x2600D10BADD13EF8ULL, 0x1DC40D91C37C0886ULL, 
            0x74F27AF32C724653ULL, 0x98E30BF36E681DB6ULL, 0xBEFC9B61CA48A861ULL, 0x7D8031AFFC3BB573ULL, 
            0x633A088063C3EC97ULL, 0x8AC4C2BF5078590AULL, 0x4A7BF3F8B58CEC20ULL, 0xBEDF3B1362B2964FULL, 
            0x7158B2D0D7240D72ULL, 0x5AABDB28E5487388ULL, 0xD2D66186A70C0CFEULL, 0x0C34287459AF06ABULL, 
            0xE61B997A176D4774ULL, 0x4C7D9C4C62B3B629ULL, 0x9BA620CF44F01B9AULL, 0xBE025B4979F32F3EULL, 
            0x85BEB6B760AFB5DAULL, 0x173529400B36AF49ULL, 0x123FE51BEBFAF0D5ULL, 0x693EC26CAE3C2CBFULL
        },
        {
            0x99C658F6D1054FA2ULL, 0x749342F2B973C404ULL, 0x826B4B0BB3D212C4ULL, 0x647E0A7209581AAEULL, 
            0x18808F7AF0C74416ULL, 0xEA99CED914B0C397ULL, 0xA191F9E827B73F08ULL, 0x25E2F868930210B5ULL, 
            0xB1E2556B7B538FF6ULL, 0xD0E04774D1D00A40ULL, 0x435B992873CA7ADCULL, 0x78E92038262C938AULL, 
            0x2A7C76742FD14483ULL, 0x8E57BDF0753D1964ULL, 0x124794D3C1231941ULL, 0x1DE05C676BF3A7BAULL, 
            0xC81EED343E195EFFULL, 0x11FFFDC8D7367771ULL, 0x3B154FC283FCE238ULL, 0x7A0D53C1CAA4E99AULL, 
            0xBBDD3AF96D67BBCBULL, 0xE347F34AD6A28EB6ULL, 0xB239F8E2F277D79FULL, 0x04C83F5FA5A6B100ULL, 
            0xDACCA5D0F7844074ULL, 0xB3574D1AC74E6EF2ULL, 0x0360A818AD5431E7ULL, 0xE471058DE1B43F5EULL, 
            0xFC3B6AE912C7BF0CULL, 0x9294C15BF41FFCE3ULL, 0x8414495BFF07591FULL, 0x252FF41DA1E4882DULL
        },
        {
            0xD9A1A9D3B4E84621ULL, 0x19DC16324B09FEBAULL, 0xA2C955754B4C1CD5ULL, 0x6FCCE0EEA2971B6BULL, 
            0x29374824176BA346ULL, 0x82DF2CD5C770953DULL, 0xB30A98CF49AD52F9ULL, 0x90A09D1CBFCE3FBDULL, 
            0xC5FD0E4A51996C93ULL, 0x6C972DF4E1DF37B9ULL, 0xB66F8B37B0A080F2ULL, 0x5FBFEAA34F6BBE25ULL, 
            0xEB769303B3AF850BULL, 0x2C9EFEB4D86E6583ULL, 0x5673DCCA9B398FF0ULL, 0xAC28D2F49511AA3EULL, 
            0x3D080B732FBB5BDDULL, 0x0F22091792BF9720ULL, 0x305329EFFED3ADCCULL, 0xC9508C0597C7CE03ULL, 
            0x4E493F555F317328ULL, 0x73011DDA895528A3ULL, 0x802CAC0806BDB106ULL, 0x25777D4A753B9FADULL, 
            0x8416C2F469474DE0ULL, 0xC364F1D69BE7E528ULL, 0xA7D64C340D244367ULL, 0x0B6FFBBDAD83C318ULL, 
            0xA48F1C592E03DC39ULL, 0x3EF08A76CA5376A8ULL, 0xDDF3E9AA62091A1AULL, 0xAC40923B3D4F4CB0ULL
        },
        {
            0x08D2B1A5C1495626ULL, 0xA09D34A27395C62DULL, 0x9336E9F6519536E9ULL, 0xABCBA2A83BB90D3DULL, 
            0x21ECF9104038420BULL, 0xECC27281D38CAC05ULL, 0x04DF42C0BFEC7E4FULL, 0x7004B4983DA3A98AULL, 
            0xCEC4FF8B5193CB65ULL, 0x629F327EDA85426DULL, 0x11E76CA026B60B91ULL, 0x18B34CAB70BFC2DCULL, 
            0x3D6B37D93A17CC6DULL, 0x35DD84799D574881ULL, 0x27BBB5CC5AD7E0A0ULL, 0x2045798004AA457EULL, 
            0x3F965A71563AB714ULL, 0xB24DC0FAD81781C3ULL, 0x35A6B861DBF933F8ULL, 0x78A542AC4C06ED98ULL, 
            0x35DED735461F46CEULL, 0x70AD0B32AF20CC28ULL, 0x7C16F1FF35FDB3C2ULL, 0x7C751D41E02F022EULL, 
            0x487705908DD182B9ULL, 0xD0742551CDF2DCD8ULL, 0x4EA372D380FA0F27ULL, 0x3EA54A9C79784B7EULL, 
            0x214C903B3C2D643CULL, 0x40E136407CAF2327ULL, 0x46C16B64A3D82900ULL, 0x9C74F21F6E7F150DULL
        },
        {
            0x539B2F37E4942FE9ULL, 0xF2DCF679B4A144E6ULL, 0x6321EB401938BFA2ULL, 0x59BD624CEF37A59BULL, 
            0x22C6A1EDA75144B9ULL, 0x45BD1CF16AD153C9ULL, 0x7E4AAD8EE0417EDDULL, 0xE61792232FAAD5F3ULL, 
            0xABA07A276A9CE651ULL, 0x4708573E3D0651F5ULL, 0x1C131842CA24390EULL, 0x061955DF2A39B371ULL, 
            0x7A74C460887F3D68ULL, 0xFF832E33D009DB84ULL, 0x991460411EE88F79ULL, 0x1ECED91FAD2A6F79ULL, 
            0x097B5F462D334CBEULL, 0xE71BABC80F32B4E0ULL, 0x9B217D33CBE3480CULL, 0xCA9DFD72172F3A69ULL, 
            0x082FBB87795AA146ULL, 0x771B4BAA0FEB1145ULL, 0x6ECFBFBE4B045B93ULL, 0x0BC067DFEDEE4F5AULL, 
            0xEAA288A7C270CC6AULL, 0x1B4D9864345DFBE9ULL, 0x83A6E9C1C8C5B064ULL, 0x6590F40652E778F5ULL, 
            0xA0633123CF248A40ULL, 0x4A1CBDDCEF43896DULL, 0xA046A975326F0C7AULL, 0x92F1799711582712ULL
        },
        {
            0x8F5918D1C50ECE1FULL, 0x01A5B70461A3AD0FULL, 0xB96AB698E44C1075ULL, 0x5FD520C53EE072F1ULL, 
            0x195688C330E03BABULL, 0x8EA449C4581E8E44ULL, 0x93368F3EC8A5121AULL, 0x358C8D08CEC89903ULL, 
            0x56944DD1479FC996ULL, 0xE7EF2C6EE5D8AF3EULL, 0x9EF898D52D999E81ULL, 0xEA33063E615B5A15ULL, 
            0xD1DF0FF29824F9E1ULL, 0x50044B5FCEE4CD25ULL, 0xD990D1F8649C9C16ULL, 0x33FFD43A854E4626ULL, 
            0x8F82DA0714E24159ULL, 0xA59DF35048AFAFBAULL, 0x62D7DB142E9D00E6ULL, 0x7173FAB07424D4C4ULL, 
            0x27F1E8A1F75E3F68ULL, 0xF95159BB0873CA93ULL, 0x0EB135846B3CB8DCULL, 0x8E7E3A051FB091D6ULL, 
            0x0B0E60B6C27EF0A8ULL, 0xF75F3DF550641A2DULL, 0xEDB6B8F789CD0556ULL, 0x23693FFFCF5E2ADFULL, 
            0x0B2A9BC2C05C0A61ULL, 0x9467D7469D9410A9ULL, 0xAA436A6673A77605ULL, 0x37EA61B3C5D95A18ULL
        }
    },
    {
        {
            0x82A34811A4CD7F51ULL, 0x7659280403A92CA2ULL, 0x71CACB9B1C6BE2DCULL, 0x76004E96E267FDAAULL, 
            0x34C1CFECCE3B9572ULL, 0x16764BAA373959A4ULL, 0xEE3C3EB5280E2C5FULL, 0xF021BB2F6512EE6AULL, 
            0xCDA1185C770812E3ULL, 0x09AC08848204009CULL, 0x88B63860D3485078ULL, 0x40655C599D1B3132ULL, 
            0xB465ECB1EE01DC14ULL, 0xA95056E7315ECB00ULL, 0x9FCF93A483DA44CBULL, 0x254CDFEC1E369EB2ULL, 
            0xE1B002806986224AULL, 0xB1703870A156F35FULL, 0x70DE5FEAC3418121ULL, 0x6A522EEFD264C2A8ULL, 
            0xF206E8FA2AB11E0AULL, 0x26F7FDC15C56515BULL, 0xBA473A8C919AE622ULL, 0x4DA86D227E4013A6ULL, 
            0xE48E9F77F350B976ULL, 0xECE8582F0A249AB4ULL, 0xC52FF27BE9DC106BULL, 0x853D958D89B80C70ULL, 
            0x4D8001B8524A0717ULL, 0x07C9737CFF77E5DDULL, 0x45ED793D2C09E829ULL, 0xFB809B059DE32ECDULL
        },
        {
            0x5006831ACE200A0CULL, 0xA84FB7F97E1E95A9ULL, 0x2FB235FE053B66BDULL, 0xC3CA3FD3B5E77CAFULL, 
            0xD8BB17BB36D2F554ULL, 0xDAFDAAEA9FE90E69ULL, 0x99015B57917BE459ULL, 0x6DADC45E1F066374ULL, 
            0x8C4E7325BF547D14ULL, 0xA0097859A41500AFULL, 0x40D9BA0C518191E5ULL, 0x4701274D5084A598ULL, 
            0x4A5A6CB29291DEC7ULL, 0x656257F594451D70ULL, 0x8F324E992925D242ULL, 0x62962D2D4EC0C0F1ULL, 
            0xCB571A204075A7C8ULL, 0x56040281B972EE58ULL, 0xE54C8A066B15A594ULL, 0x950A3F825E90C4BDULL, 
            0xECFA5433C60EDE4CULL, 0x5F97EB80E65C059CULL, 0x8C3006332A95C36AULL, 0xD6C7B5FE5962D7FDULL, 
            0x495CE6108FB33C0BULL, 0x306689020EA751F3ULL, 0x1E9F0675DE81AEE4ULL, 0xA145468F0578AE7CULL, 
            0x4CC10873FF17BE21ULL, 0xD05DFA5F1AA5F52CULL, 0x668B43C4B18166CFULL, 0x0AEFD1544ECC2EA2ULL
        },
        {
            0xF1C443AB3A24B8D9ULL, 0x98D34FAFBF567E80ULL, 0x45D41DC86C794D5EULL, 0xCE6EFFAF2768A9FCULL, 
            0x6F39AEF1446C67AEULL, 0x02A1815513799B0EULL, 0x426E6E4A3639FB21ULL, 0x24087FF0088B293AULL, 
            0x589DA95D19A3D410ULL, 0xC938B47B712C118CULL, 0xE0635BDAFA68EF4AULL, 0x5FA3ADD8CF36BDBAULL, 
            0xCB7AE186AAA98318ULL, 0x765EB880AF77984FULL, 0xB06A4E7ACEE7A640ULL, 0x70ED579EDE60DD0AULL, 
            0xDCB7DD5A98352A36ULL, 0x0817C94BFE7A3B90ULL, 0x21C4955902A55ACEULL, 0xBB3C1FDF5E8100ABULL, 
            0x1F1CE21303AB19B3ULL, 0x8EAB75BEFBE71D09ULL, 0x202D243E76A684DBULL, 0x098EE5F4078EEE96ULL, 
            0xF965EA1E49F61861ULL, 0xDC0F3A6B1D14EACBULL, 0xAC8002A581FDD62DULL, 0x372F1BCEEC99C832ULL, 
            0xD00218FA6059740DULL, 0xCC930767846B404BULL, 0x3FC39BED942C7849ULL, 0x7F58F20E299DA72CULL
        },
        {
            0xD65C3510005E03E4ULL, 0xF22456BB8B1A8DB5ULL, 0x027CCEC9984E85ABULL, 0x464A26D1D115D438ULL, 
            0x299991AD12742570ULL, 0x169B18F3CB96B757ULL, 0x21035A4043C6B2DBULL, 0x7C0C94CF0F4933D5ULL, 
            0x437F33E6D6FC7743ULL, 0x7F6BBDB5B38A1456ULL, 0x26B608E72221109BULL, 0x5CE2A80E1A8F42ECULL, 
            0x77C911194BFCC406ULL, 0x62155ED4B86C937AULL, 0x21CCF954C1577922ULL, 0xBD939D825FED21F7ULL, 
            0xE8AAB8C7650C61CAULL, 0xBA2CAABCEE4AA1BAULL, 0x31A5CCAA0B3FD8DEULL, 0x57175527A14A3716ULL, 
            0x09FBF31BE339A7AFULL, 0x5799837B1E06D0A0ULL, 0x8244BE536D42F52CULL, 0xFE5C4218BB8FCE00ULL, 
            0xEF4AB6623DFCFBC4ULL, 0xC3E4E3B52C0A570BULL, 0x8EFC3663EB655B95ULL, 0xC840A993D50FE061ULL, 
            0xB3FD513482ACB85FULL, 0xB4FE5F94A980CC61ULL, 0x2B270923E16A1C2BULL, 0x7E93F0D4F11FBEE7ULL
        },
        {
            0x7205E7A3546A1367ULL, 0xA35DC9E82E5CFEE3ULL, 0x1DB91E821DA19028ULL, 0xEAA166DCC876BE7AULL, 
            0xE2B1FF204834C547ULL, 0x18A3A8DDE0D9E3C0ULL, 0xD7EB8966949A2222ULL, 0xD8B5A9321EB6BA80ULL, 
            0x8AD3B5F1152CEECDULL, 0x5FCA0FAD65549871ULL, 0x458114F50F4D283DULL, 0xE49FAF9F5EA1145FULL, 
            0xBEE89E3B575B9CAAULL, 0xEFDE13A8B9D61F0EULL, 0x8B48731AF0C28B7DULL, 0x0D8B2B3544227258ULL, 
            0xCCDE68E44EB8A1E8ULL, 0x5EE65308AAF1BAD8ULL, 0x18086D17501594FEULL, 0xA9E68DAD209CF2BCULL, 
            0xA6EBFD59E72D7E80ULL, 0x2311B18C54A67057ULL, 0x19AAD91F1416B073ULL, 0x48631FB342B798B5ULL, 
            0xA2378E5FE638C8FAULL, 0x2AD9B090A95D3FB2ULL, 0x2901922E873185A4ULL, 0x75C773FC0E801B91ULL, 
            0xB80DBDFB3E9A19F3ULL, 0x88239E6CCBFC6B81ULL, 0x645EC703F74411D6ULL, 0xC94F77D3F73C36C1ULL
        },
        {
            0xBA431069399EE493ULL, 0x0904F55324093308ULL, 0x9693A4BD1ACA6F1CULL, 0xF181C70B0BA3B53AULL, 
            0x8444795B95465F03ULL, 0xFFB69DFDEF327BA2ULL, 0x1847577D64E8F303ULL, 0xED2D75868E107BE9ULL, 
            0x7015C262B9322629ULL, 0x8FDB3514A86E80A3ULL, 0x0D6C101B48EC5FC4ULL, 0xE493FEA483E2BAE2ULL, 
            0x6B4AA3503A88DB36ULL, 0x6E44F1549BE3688CULL, 0x81C552507B169F32ULL, 0x07ADBF23205EB73EULL, 
            0x4C62D63FAC7C40FCULL, 0xA02427164652B83BULL, 0x2C21F0C5B3CFFE83ULL, 0xC83777547443DE5BULL, 
            0x1E5A63AC6465B009ULL, 0x6AD5128620FD4339ULL, 0x0136C9F8AE7C5431ULL, 0x0BC8BD36E3B25FE8ULL, 
            0x91FBDFA69A986E36ULL, 0x51E84CEC367420FAULL, 0x35A21058C5186C62ULL, 0x19E4701DEE3EA7CBULL, 
            0x6A1DCDB640938096ULL, 0x6789337348085F97ULL, 0x43E032BC33928B05ULL, 0xB576D45994FBBF58ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseDConstants = {
    0x921C0AE7EA12F475ULL,
    0xAF2CB23BA428A5A4ULL,
    0x833D073221B1D756ULL,
    0x921C0AE7EA12F475ULL,
    0xAF2CB23BA428A5A4ULL,
    0x833D073221B1D756ULL,
    0x1C4784FAA9809987ULL,
    0x9B41A37B34619A2AULL,
    0x90,
    0x98,
    0x65,
    0x75,
    0xD9,
    0x65,
    0x52,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseESalts = {
    {
        {
            0x83726372C50652BDULL, 0x16640E0EF9D0C326ULL, 0xDC55950F92852FC2ULL, 0xBE71ADAAA924DB6AULL, 
            0x8762619DAE9DBE2EULL, 0x1DB943AF05261E66ULL, 0x03006AAE1AE2E59CULL, 0x087EFAFF3E954EB3ULL, 
            0xA950589309E611A8ULL, 0xFADEBF0188CE12A0ULL, 0xDB2BB5BFB0187421ULL, 0x6CC19E888372EF0BULL, 
            0x208A715B6E4FA454ULL, 0xAF8CF1DBD63AD92AULL, 0xFF5283B855680003ULL, 0xD1B2AC1BF94A7BFFULL, 
            0x67B03B775CD25DAAULL, 0xAB29B89D1E7BE389ULL, 0x3EAE87F3158C91C2ULL, 0xE875AA837D11EBD3ULL, 
            0xFCF38EE9F4B83206ULL, 0xDE7F5B0EC4BBB3D9ULL, 0x937141EE9CEAB927ULL, 0xCEF999CFBF1FE4BDULL, 
            0x081DD1DA18DE722EULL, 0x9258D0A8D50A0ADAULL, 0x69725DA6D9060CB6ULL, 0xD4F7FB13A8DAD49BULL, 
            0xBF779266CC4DD760ULL, 0x6CF770A59FC26D4CULL, 0x095142B9D1CD5A2EULL, 0x7828B670EB3C5F76ULL
        },
        {
            0xFDBC37AFCECA28DDULL, 0xE5EEF66D0DD72371ULL, 0x73ED2CBB6747DDB7ULL, 0x8ECD369B19D968A8ULL, 
            0x8F7BB155E5B0D736ULL, 0xBFFC4B0328A712A7ULL, 0x27626F9C20BBAA68ULL, 0x9B373017C752CACFULL, 
            0x9C84D2BD0677BBB8ULL, 0x3E1124C364D2ADF0ULL, 0xEFB49F4F8ADEFFAFULL, 0x8A284649837F870FULL, 
            0x3014AB8AAF57EB04ULL, 0x8D2AAE99C979EB48ULL, 0xCF11A708FE5143FDULL, 0xEA838DF039B61BEBULL, 
            0xE3AA63027B10049DULL, 0x4581D074D792A6E9ULL, 0x7A47B35A63EB5C23ULL, 0xBF2681264044BA4CULL, 
            0x204EF45D358608D5ULL, 0x8F6543CE738B63E9ULL, 0x1F124C5D10B64B36ULL, 0x85790E9FD6B8E7D1ULL, 
            0x47CFCE3C71C49064ULL, 0xE2A7727D48ED7381ULL, 0x26803B09C26DFC4FULL, 0x0D53B71C4FEF24ADULL, 
            0x738DBEFBD0F24B3CULL, 0x209F0E500C256659ULL, 0xF4B4EECAC57331F3ULL, 0x678702E0E16C68D0ULL
        },
        {
            0x4DEC9F618BD56EA4ULL, 0x05C387D506F9607BULL, 0x030B52240A9D2269ULL, 0xA9C92752DE4D8BCEULL, 
            0x0D4613DB5DDF0703ULL, 0xDA9E3C45BAD62B62ULL, 0xB21C1C6636A8CC42ULL, 0x00D69EB577D4F99AULL, 
            0xC38CF442C7AC2F58ULL, 0x437272260945A498ULL, 0x71E8539E694860CAULL, 0x47193E7DC37D4261ULL, 
            0x9397F74B0BFF76F3ULL, 0xBFDAE3CBEAFA11EEULL, 0xB3B9D3DF531B42F8ULL, 0x47A60E352E0A987BULL, 
            0x7D5AEE526E3D2A0DULL, 0x48F3D418ED66A306ULL, 0x340E43B9C64B4B31ULL, 0x944C17F21542FFFFULL, 
            0xD882223B3C271C41ULL, 0xF5C1ADDFA981F019ULL, 0x6F7957589D8BA756ULL, 0x437D3614397CE8AAULL, 
            0x423BF91969D551E6ULL, 0x8657C18DCB76BDC6ULL, 0x098A922B418C1860ULL, 0xD11D89A0D91B322CULL, 
            0xC0826412920F10D4ULL, 0x8B1CFD65BD6BCEC4ULL, 0x4DC796612D1B9F8EULL, 0xDDF8B45BFB85EABEULL
        },
        {
            0x2DB674C8E2263614ULL, 0x520ACBFE0703D6E7ULL, 0xCAD6B46E4267F490ULL, 0xABF69FD69B824A0AULL, 
            0x2EC7E8A0D70397F5ULL, 0xB592CBBC34E3040CULL, 0x099D3DCAB6279F27ULL, 0xC096EE5A122503B0ULL, 
            0x663114056294344AULL, 0xC01E0B24168C48DBULL, 0x910EEB1E02424CDFULL, 0xC00987EE2C688DA7ULL, 
            0xB5256A7915469D81ULL, 0x4BC56FFD8423C247ULL, 0x5DCB4EE920B82A78ULL, 0xDE9B51ACFB1F67A1ULL, 
            0x4AFB3FC912FC7F74ULL, 0x0105D43E325BFE89ULL, 0x5A42F24B413CBE67ULL, 0xE1EB351C314FB5A2ULL, 
            0xC58D955538A1F462ULL, 0x5E83DBDBA4D71B5EULL, 0xC27B423362117C7EULL, 0xFE192EAF7658BF43ULL, 
            0x1F171748C324B543ULL, 0x3103630D9E92E846ULL, 0x5BB0128B542C11E4ULL, 0xBD7A9A7F187E5DF5ULL, 
            0x2F323955E0595C11ULL, 0x628F686FEFFE338BULL, 0x086C9CD82E576B67ULL, 0x7C7BCBA405B58F7EULL
        },
        {
            0xE1345599EF5FA6E4ULL, 0x950474CF36B917C4ULL, 0x9E7AA8C5EA7CC6B8ULL, 0xF0CD9F8D46B7ECD5ULL, 
            0xF27BAB0482CD06FDULL, 0x6D91498D9E938BC3ULL, 0x5470A84961B6F954ULL, 0xBFA78AAC3D29692FULL, 
            0xC97F33785A6CDD8CULL, 0x43FBBAC1A6BF2E16ULL, 0x823958AFA0A93B34ULL, 0x036EA948FA98E7E7ULL, 
            0x3894F7CBFF24A631ULL, 0xFBDC4DA473DAE023ULL, 0x6E2C688BA9CD2C57ULL, 0xC54CDCAE766F6C42ULL, 
            0x746DF4A519BF18D6ULL, 0x3FCEFFC49525D171ULL, 0xC24E2EC4D376644DULL, 0xC9B2F8E3191058F8ULL, 
            0x9A9912B392AE6D0EULL, 0xFBE3C4A1AE51908EULL, 0xDB48908F5DE6E7EEULL, 0xC233C31F4525B868ULL, 
            0x8B416D89FE921898ULL, 0x600C09EFA65CC77AULL, 0x227CD7B4FCC1B72EULL, 0x2376598D26D52BC3ULL, 
            0x5FF5BB45E3E44D14ULL, 0xB53A15516C69234DULL, 0x16A2FC2AC9AD9425ULL, 0xE51C1C60E2352843ULL
        },
        {
            0xB6D017A59ECB889AULL, 0x8B482D12A95962D8ULL, 0xBB0B31C68D7DAD09ULL, 0x0CC953988FC7DE24ULL, 
            0xF6A302829BB0952BULL, 0xE277C447C4BE256BULL, 0x09A83937AEC737EDULL, 0x042313F6DA234440ULL, 
            0x862BA7A58B04B4C2ULL, 0x828AE2BAC627C384ULL, 0x2ADD9A82DC2D7CDDULL, 0xA2E467831D170B62ULL, 
            0xA146654216BB1E0BULL, 0x5CB5D5E95F70C864ULL, 0x217A768AED6EABD1ULL, 0xB180D84D7E71C5A4ULL, 
            0x5ED374B5D01B05B2ULL, 0x02A2AAEB7AED6CDEULL, 0x4F4507F512EACE3FULL, 0x59CED7EB5B64787AULL, 
            0x176CD44B64852B53ULL, 0x4216213EBB5E929BULL, 0x336CF67BD36E409DULL, 0x55EBCD89E3E728AAULL, 
            0x55782C6DEE7FEEC9ULL, 0xC4E3E996211C5C2FULL, 0xD913DDE297A79DA3ULL, 0x8128230809F4AE07ULL, 
            0xF64A2EA466B23023ULL, 0x5580C93FCD10202BULL, 0xA1911EC4E7AA1249ULL, 0x64B5BAD566ED2F63ULL
        }
    },
    {
        {
            0x524E4DB2D3E4D822ULL, 0x8EDC24B1A6DA78CEULL, 0x7B500B349BBDAD7CULL, 0xA4D8D8EB04A2F334ULL, 
            0x200608E62F63AFFAULL, 0x98B790D487333E2DULL, 0x23C73C70C2681B5CULL, 0x456E8FBEC8330296ULL, 
            0x4B348B1E4EAB7BD7ULL, 0xB6D962F430B4446CULL, 0xC50F7863B4CC79ABULL, 0xCB408E18A086E73CULL, 
            0xD95B9AB0B5400E0EULL, 0x7E59CBF5D1BA65F8ULL, 0xC2FE024349EC17B8ULL, 0xF1FD1465D2B09209ULL, 
            0x0AB638C6E0B05DB0ULL, 0xA30BD5540024A1EFULL, 0x90D6754F71837FCEULL, 0x56135332DA0746E5ULL, 
            0xDA035D861F67D5C8ULL, 0x5A95DC0DB3F43509ULL, 0x3EFDB95A52D17C64ULL, 0x72E5B3626EC4DA49ULL, 
            0x1CFADD22CCED9586ULL, 0x5B16AA9D684FC463ULL, 0x9F319E7D5B045D69ULL, 0x5A7A97526D37F903ULL, 
            0xBCECF483DB66E5F4ULL, 0x83AD71150D45A3A5ULL, 0x1B0399AE5A8AE0DCULL, 0x04985DA9789397A3ULL
        },
        {
            0x358C8367E1940238ULL, 0x01FF4C1F710F0BA6ULL, 0x616AF6AEAB4ED763ULL, 0x61F082342D4B761EULL, 
            0x961285FB63F58102ULL, 0x6C491EBF87E23E62ULL, 0x78E07687E5D4C4EDULL, 0x250772CAD6E891E5ULL, 
            0x1FB40E7A632DCCBAULL, 0x82DA7F9A848AFAD9ULL, 0x4D247955B53C45FDULL, 0xBE5EE21E455A19D3ULL, 
            0x3D36589D04BF03AFULL, 0x1F57999EC498D1DDULL, 0xBF148DBE1DE183A6ULL, 0xF44AD08AE1E569E7ULL, 
            0x4A8DFD94DA760F7BULL, 0xBF2A2CDB95354300ULL, 0xAE3E93C310682DA0ULL, 0x7965E14A9EE8815DULL, 
            0xB53DC0B90681F592ULL, 0xFB885D0E0EC6ACABULL, 0x70B6E5A5E5646FD2ULL, 0xA43AC71215EA9791ULL, 
            0xA53A4F1F06E0CF7EULL, 0xA63148CD18813068ULL, 0x583492FDD2043C13ULL, 0x8D435FD3663630B1ULL, 
            0x8CCBF1619EF55B45ULL, 0x350FD23918BF0DD7ULL, 0x5B413DEFCEE9622DULL, 0x4ECF0CC3339AABA1ULL
        },
        {
            0xF87A77C49B0622FCULL, 0xAE98C161B8BC3094ULL, 0xA8E0C52386C5BBD4ULL, 0x720D249E9B635359ULL, 
            0xE976325CFB0FB676ULL, 0x61A88A4F1C3AC199ULL, 0xDBABB8D03888ED20ULL, 0xC87A2A71DF8F0065ULL, 
            0x24C0B571A1F44C13ULL, 0x8DE348D64BB711D0ULL, 0x251EB952335189BEULL, 0x32CC8EDB038BABB1ULL, 
            0x77475FA6FE9EC0B4ULL, 0x7DF1BDAA8250CF2FULL, 0x3D08B0D29FAF44BDULL, 0xD7BEEAD694E98048ULL, 
            0x7171ABBC03C1E206ULL, 0x97BFAE2BC9795683ULL, 0x274CC8055E01FBD8ULL, 0x9F4AEA5D28B962EBULL, 
            0x54A3FB38D789BC7AULL, 0x1ED44DB89E36FF5BULL, 0xF465FDD7F0B8F974ULL, 0xC2367FBACB4DC386ULL, 
            0xA08AB3D2F69CA551ULL, 0x28BBF1AA74735C21ULL, 0xCCC1CAD39274DFA3ULL, 0x449093123929DCDDULL, 
            0xD8F9CFE10200F733ULL, 0x8585224D9EAC8C42ULL, 0x1ADBCC2AB4FAE846ULL, 0xF762AFB2A722429EULL
        },
        {
            0x0C29024BC06EF23BULL, 0xCB813384C1F1C546ULL, 0x75572C40DA74B406ULL, 0xD783F61F2ED6A0D6ULL, 
            0xC35D46DA6CC05B08ULL, 0x1963866D8B4CA697ULL, 0x3C18BED57A040C6EULL, 0x950F367284DB0F62ULL, 
            0x20FC6AB3B0186648ULL, 0xC8BE920F2FC1361BULL, 0x6B9F152C9709C323ULL, 0x27E0FFE5A9DB5E96ULL, 
            0xCE18AEC234242DD0ULL, 0xFFFB4331909D7BB2ULL, 0x771B52E43EC5B7E4ULL, 0x9FD5D93B1AE934F2ULL, 
            0x27E730773D6332E1ULL, 0xBFD6150C14C5C8AFULL, 0xA2E018230EBB4507ULL, 0x3023FE88998A2CEDULL, 
            0x9FB30B0C1AA41399ULL, 0x629E6E2108E9AD42ULL, 0xD67ED939E31FA322ULL, 0x60F15C314F1780C4ULL, 
            0xA22012B4164EFC76ULL, 0x6A5BCA3E40E9F244ULL, 0x87EA821448952960ULL, 0x9A47CCC16C2DF7B7ULL, 
            0x812E715DA43DCC77ULL, 0xB4A3A7B5971F6B9EULL, 0xCE6248A32C53E549ULL, 0x2B3693FD42FB0B39ULL
        },
        {
            0xD6A58AB64D45F8F5ULL, 0xC8D2FD6627653359ULL, 0xB1B05F0A46BE9DE7ULL, 0x1B31CBFB3C2895C1ULL, 
            0x6D5A941464A9BBD5ULL, 0xF09DE264FBEA3173ULL, 0x54A20B0D473D546BULL, 0x98440D6568A45BA8ULL, 
            0xB5586DE4C1829546ULL, 0xE59C10FC22E0640EULL, 0x827A4C073B209E07ULL, 0x0AA65489661A5632ULL, 
            0x0A0707386A0F1979ULL, 0xC25498FAD0A92A14ULL, 0x0ECFF754491B9892ULL, 0x567018BED954C1F2ULL, 
            0x5386E8D76F912770ULL, 0x872DFF99BEB395CEULL, 0xFA00D01831529336ULL, 0x997FF73AC2300358ULL, 
            0xF575737620DFF2EFULL, 0x5C6DB34F23D540A4ULL, 0x159BB0DDDE09C4B1ULL, 0xC45F6A5298CB2ED6ULL, 
            0x7227D760E356EC18ULL, 0x36E4A39FD0CCBE6FULL, 0x35C0AFD31C7206BCULL, 0x9C1A97A435928864ULL, 
            0x6D7FA9A6B3292764ULL, 0x06BC48AE7DBD8AB8ULL, 0xADD43B7CB2533C53ULL, 0xB4E6CA0C37B0D874ULL
        },
        {
            0x38DE93849BFB306EULL, 0xB88F8E97CE5C4DB3ULL, 0x2C4683FF59ECADE5ULL, 0x226E143CF0C6999EULL, 
            0x0147EFB4CAA8AFD9ULL, 0x37178FBB620AA35EULL, 0xED5811239ECF4E8DULL, 0xA88C31CC1F626D4DULL, 
            0xB94AED6E4DE9AFE6ULL, 0x2C11916674593252ULL, 0x14786EAB7E57E9A0ULL, 0x369593DD243AF303ULL, 
            0x3A42A1CD232E0329ULL, 0x9C6AF11CD76A1C39ULL, 0x591510F65FCF0AE5ULL, 0x0960564B963D2CB9ULL, 
            0x3AC38AA7FD498CFFULL, 0xE7D4360FACF2BC81ULL, 0xAF6AF95791C325FFULL, 0xEFB469D5FE748267ULL, 
            0x1860518BCDAA84D1ULL, 0xC51198BB7560C768ULL, 0xA3B385173C74DFF8ULL, 0x72B1F76D8E2FBB58ULL, 
            0xA7BDA0BA3785386BULL, 0xC447BCFC08E0C557ULL, 0xE16E3F73DB779A14ULL, 0xCBD57DC83F122434ULL, 
            0x965345A884D53C2DULL, 0xD266C966F9423FA3ULL, 0x636A2ED56574DC2DULL, 0x86178FC919A1375BULL
        }
    },
    {
        {
            0xAF517B9F045217A4ULL, 0x5D95019C868F189CULL, 0x93A7EE0A16DE0F40ULL, 0x34D3FE36C9657C93ULL, 
            0xD3393899B7FD4B2FULL, 0x4AA88BA149A9AADBULL, 0x0E86CE73B723BBF1ULL, 0xE53463C7D42EE204ULL, 
            0x160FF15B4694DF1AULL, 0x8950D156B83C6838ULL, 0x30C158CE0DCB3247ULL, 0x9F9B6CF9DF6E1D28ULL, 
            0xB474762B6390B652ULL, 0xABEFDAB66B00090BULL, 0xCC40C3AB6A1ADB36ULL, 0x73867B08A00BCF16ULL, 
            0xF10C0DB72E252855ULL, 0xF8155D92E9297A75ULL, 0xDA39B51FF71EE465ULL, 0xBCE2E86A6448E0BFULL, 
            0xDDDDCC7F65084052ULL, 0xF9050638FF6CDAC0ULL, 0x2E9E9D2B683BFF24ULL, 0x4BE40083338E4193ULL, 
            0x66A836142EDA7B64ULL, 0xB5DEA7A34B94E257ULL, 0x4D8FD0DB21A9ABD5ULL, 0x52D02498D5A91EE9ULL, 
            0xEC3EECC5ED23BA2AULL, 0x6C3CE5642D657EEDULL, 0xB7E857819BF1C35BULL, 0x87A44D111BB6F9B7ULL
        },
        {
            0x43A3046803FAA928ULL, 0x9B59BBCBC82C5F5CULL, 0xF9679F79FFD82ED8ULL, 0xF09F0B7F646E51FFULL, 
            0xF2D1853ECFABA2F9ULL, 0x9E182A8FAC566DC7ULL, 0xE3ECBF4D9891A33EULL, 0xB1AB9FEA0051A265ULL, 
            0x9A5CAE5FF6686ED5ULL, 0x6CA56B4491155FD8ULL, 0xAEE8528F6916B44AULL, 0xA726DCDA05987A15ULL, 
            0x3680E809F6266621ULL, 0xE51182F1EB3AB12AULL, 0xA6DDE46CB1E85C9DULL, 0x2E4AB3CF32DF532DULL, 
            0x01A3F2A7DA73A71FULL, 0x6CA4AFDBA73C46B2ULL, 0x0B8580A8D4D5920BULL, 0x0E5F9771477677DAULL, 
            0xB044B02C8BB0F66FULL, 0x8D07BDD9846657CEULL, 0x225804AF15965C73ULL, 0x6BAE1E274FA14785ULL, 
            0x20B4EE9B8307FBC5ULL, 0x12FCDAFA000A14B3ULL, 0x76165CA93D283D4FULL, 0x76B02EB475C1E8DDULL, 
            0x3BDDA6BBCEC9A4E7ULL, 0x5A3A39E9E8B8A9B9ULL, 0xD66906D5A39633D4ULL, 0xCD5182E5CCBB5E7FULL
        },
        {
            0x3B7937A5A6A8B6C5ULL, 0xCAC91E44047E1CEDULL, 0xA618E9815876E5F5ULL, 0x03949B05636F569BULL, 
            0x036C0FEF6697EA04ULL, 0xFFE3EE5F235EF500ULL, 0xD84F866B36E5B8C0ULL, 0x4FA6FB581E6327AFULL, 
            0xECBBEBECB6BD1A13ULL, 0xD17142EDFAF92FACULL, 0x351BE50BBEA42670ULL, 0xBE23AE8181098BD4ULL, 
            0xD95C870E0F6A8B88ULL, 0x247DBDB4AEAB3A7DULL, 0xA78C4BF3284119E0ULL, 0x67639B0BB9325153ULL, 
            0x9078164F6FEFC047ULL, 0x3C9077FF9C7D13CDULL, 0x648304F33281D763ULL, 0xCA17C6B35C4C242FULL, 
            0xBA4B13A0CD6761A6ULL, 0x6B7B575FC4E85992ULL, 0x90F71BE3AC5611E0ULL, 0xF4E849033FC92A1BULL, 
            0x045E0EB386920A62ULL, 0xC597B9F6901D6410ULL, 0xEBFA035DF65CC8D6ULL, 0x37984135CBA274B5ULL, 
            0x3648A66CBC924D60ULL, 0xB7C47F029176A779ULL, 0x64B1785E6CAD392DULL, 0xB3CD7E61AA429A1AULL
        },
        {
            0x68F4B1DD1C15CAF0ULL, 0x56E20B3F2C6E1F4AULL, 0xBA811FE8D408A778ULL, 0x79E35A3A640D17ECULL, 
            0xB9124CBA22D1ACABULL, 0x314B25F8A737C8ABULL, 0xC9CF40A67E85213DULL, 0x1A353DFA6D4C1C9CULL, 
            0x665C1531A6A88823ULL, 0x947870FEEC9F3E6AULL, 0xCA1BC7AA8DF3177BULL, 0x40BEB1DDF0C26F5EULL, 
            0x0745974D27F5DA1CULL, 0xD48EF3B906517BF1ULL, 0x4FA8E0239F4B4030ULL, 0x4F5CBB514A923F0DULL, 
            0xFE501C2421C7ECA6ULL, 0xFD668CC68E476102ULL, 0x5A002A0092E91DD0ULL, 0xC00A04C6804B1259ULL, 
            0x5F3CD651F84EDAC2ULL, 0x7A90BDBF2A783106ULL, 0x3D33F9DC97524684ULL, 0xC8337A8257863649ULL, 
            0xA5990E720F163009ULL, 0x604E9808D4BD86CFULL, 0x946299F91E52FE6DULL, 0xCBAE28FA19EF3B37ULL, 
            0xB99E60E9A1E399C3ULL, 0x328CD3FB724D9F8CULL, 0xBFCA0F5C61317BB8ULL, 0xE523947F654CE171ULL
        },
        {
            0xD302458F7D6D8E8BULL, 0xB44345D79E7FE2C8ULL, 0x701936F58F2C6605ULL, 0x0B794ACE791F63DDULL, 
            0x4BA398C800ADA6A4ULL, 0xECE8E622F0DA4B01ULL, 0x1C6BB6F8917089B6ULL, 0xAC84AED4D70FC7A7ULL, 
            0xFA216269FD2D65C9ULL, 0xDC8ACC022E627228ULL, 0x36769857FF4BB11AULL, 0xF2D8AE4BBDB0D010ULL, 
            0x2ACAAD9F0E03C08DULL, 0xB0475F1946CC1AAAULL, 0x8FF60FE0D90EBBD7ULL, 0x1AE78087ACF603AFULL, 
            0x413EC5DE2B0C18AAULL, 0x1C61990471C0525FULL, 0xC2E59F15DF79C866ULL, 0xE3CFF69D6E0AAABAULL, 
            0x82FFF7C417BEA41BULL, 0xB7D9F29F08CEFAD7ULL, 0xEB7D83055A8FAEF5ULL, 0x4853948B5EA0105DULL, 
            0xBAD10B6265E21DA4ULL, 0xD7B8D8E8AAACD073ULL, 0xF08D58F520B20D03ULL, 0x23F82995B499D060ULL, 
            0x156BC127C119ABE6ULL, 0xD1A11B99704793B5ULL, 0x9C292A342272EB1FULL, 0xED9D760A2794265FULL
        },
        {
            0xAE1EF090BC46B7E7ULL, 0x7B5AE7E8C4936300ULL, 0x9EA56E1A3DB7AE59ULL, 0x88DF59C2275D11C0ULL, 
            0x693A0D1F687ADE39ULL, 0xBC56CC605D7980D7ULL, 0x4F32ECBB958719D4ULL, 0x30AC1188BBFD74E1ULL, 
            0x840A958B3B68B7B5ULL, 0x0F0E5707A4A06AE6ULL, 0xD86A2E1FC488B957ULL, 0x0A46F1EED24F3FE6ULL, 
            0x2D72D86602AA0172ULL, 0xB74E4D9BF3BBC5B5ULL, 0xA8869F9FA114617AULL, 0x5DA48000E006BC6DULL, 
            0x80C4455BCBB2D147ULL, 0x6FED8337A9AA51FDULL, 0x3482C20C1F0A1336ULL, 0xF3019D3348E916A5ULL, 
            0x6CD9F53FA54A9CE4ULL, 0x04FB289D8A447FA7ULL, 0xF87A7EFCA0E8C04EULL, 0x285E2D30B72D8B66ULL, 
            0x28D82F09081ABA11ULL, 0xF138DD200F3A2211ULL, 0x5E8B377B9A674D7FULL, 0x76D490C044A7A135ULL, 
            0x10AE88507775D7E7ULL, 0xCC72784B654E633CULL, 0xF652EFF132E1D7D0ULL, 0x124C0F6B04582986ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseEConstants = {
    0x9DCFB262EB15489EULL,
    0x043B0F1EE5CCFB4DULL,
    0xB11C4D5B839932F0ULL,
    0x9DCFB262EB15489EULL,
    0x043B0F1EE5CCFB4DULL,
    0xB11C4D5B839932F0ULL,
    0x58B4F8BDD2E2CC75ULL,
    0x5315BFB71304926EULL,
    0xC2,
    0x9F,
    0x6A,
    0x11,
    0xC8,
    0x4B,
    0x81,
    0x0B
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseFSalts = {
    {
        {
            0xA4BDFAC569507173ULL, 0xDC729557272ACF25ULL, 0x5BAA5B60C6D09CF0ULL, 0x5C9302520DE73B22ULL, 
            0xD6F4D224919F7661ULL, 0x5C4BC0F5448893F4ULL, 0x1D8726F8E5B9B503ULL, 0xC5D6C7769A88BA1BULL, 
            0xFB143607C2BEB7F0ULL, 0xC60B74DECC58EA64ULL, 0xE6E8B00BB641B0F3ULL, 0x0E978842E13CB259ULL, 
            0x34090395FEF89398ULL, 0x7D66262438327814ULL, 0xBD95BF494F6F162AULL, 0x5EE0A9AE7C4D078AULL, 
            0x187C67FB63536929ULL, 0x9D44F550736F135CULL, 0xF942DCA7376DD7A2ULL, 0x2B59BEFBE04F6F92ULL, 
            0x478D591D402BD976ULL, 0xA045A2DC959D5B24ULL, 0xCBCA8B40538BD9FDULL, 0x3C5B3CD307F08F0FULL, 
            0x0FB2E5E4535D8AA2ULL, 0xBB699870D056F98CULL, 0xE3AEE7EBF7C83A99ULL, 0x67DE6CA403540BADULL, 
            0x7AC0748F8546027FULL, 0x0D4744CBFF3870CAULL, 0xBCE5BD8923ECC863ULL, 0xA6B64750582F472AULL
        },
        {
            0x0FB34BBE3DAD0BC0ULL, 0x8DB32711299E1942ULL, 0x438E6949FF069E9EULL, 0xE88B379CC26A73DCULL, 
            0x69BB90926A365980ULL, 0x50DF21008601EDDEULL, 0x66D337053DAE5B18ULL, 0x8840C01068FFE2DEULL, 
            0xAD3E8597D85B776BULL, 0xD4F70DCA148483BDULL, 0xEEB1F517C6FFCD6DULL, 0xA46850740507A3BDULL, 
            0x06D2E504D5917217ULL, 0x3BD2B7BC70C2DB75ULL, 0x5CEEB3FCBAA71806ULL, 0x3E0D79B19E9DC170ULL, 
            0x554DD3C7D48F1661ULL, 0x458811F397FEB541ULL, 0xACDB668136CA5DB8ULL, 0xB5FDBAA8D4260C87ULL, 
            0xC59A4276A4AB9558ULL, 0xEFCC236666D89E1AULL, 0x47363A80D500F302ULL, 0x57FAF52BD1F76840ULL, 
            0x99C6F8D5D790075EULL, 0x3E94B3B7418EDC64ULL, 0x4FB3370DDDE94A97ULL, 0x12A00ADEBD2C343CULL, 
            0x443C0830313819A9ULL, 0x714E1AF19E9F633BULL, 0x9A23D09398A353F7ULL, 0xC84A044121CA50B7ULL
        },
        {
            0xB2BDECC626CFBF76ULL, 0x7EC54590E003432DULL, 0xC425CFD3D07DB386ULL, 0x59AFE92C674BEF50ULL, 
            0x87AC740121D145BBULL, 0x4780C53DD2DE2337ULL, 0xD456F0AE90AA3FBAULL, 0xD7C876E14E4138EBULL, 
            0xFB13CDCA067C0641ULL, 0x30E3E899FB3CD422ULL, 0xB71FB4FBD9A1C8BAULL, 0x3AD3A9A399E31BF6ULL, 
            0x34BCA40310A3D168ULL, 0x5DEA3FE6A6470C30ULL, 0x1607F4DEA2690AE1ULL, 0x31C71982BD13019BULL, 
            0xACDC5F0191F31B6FULL, 0xB6725DDB9D905B16ULL, 0xB1DEEA1EEDB4426AULL, 0xB7A450D0E88C8FD4ULL, 
            0xB0D6FD497BA5959DULL, 0xEFEAB43D068B110BULL, 0x7F9014E2684BE597ULL, 0xB71E7BD0157EBB70ULL, 
            0x05C5152D0061FA8CULL, 0xF2892E8FE8AC3EC2ULL, 0xB3F34B93DC5E2529ULL, 0xE667E211CFA1D8C7ULL, 
            0x5C6F674CBB71459EULL, 0xD82AACA1424DE54EULL, 0xD00764CD1C11C6CAULL, 0x6704DA3895404990ULL
        },
        {
            0x0AC78C36720AA3C3ULL, 0xFAA43CF53EC09B95ULL, 0xE8AFA39E50401ADBULL, 0xED52FA8C011202F9ULL, 
            0x5D858239A3407BE9ULL, 0x1C3272AF31DB5AAAULL, 0x64EA9FBA9EBFFF13ULL, 0x6F2C6D5B5E9837A6ULL, 
            0x0C536E53787309D8ULL, 0x936CF8566F359423ULL, 0x8DE8A389A7E1ED2BULL, 0x8ABFD29ED2B692A2ULL, 
            0x0B66F6A6F4810353ULL, 0x528AF774A31C5028ULL, 0x5DF59A1AEF390DCBULL, 0xBEE90795ED96D4ADULL, 
            0x6961683664E78EA0ULL, 0x8E2D26FEF11516F1ULL, 0x2B0C9C1046EFD144ULL, 0x8BE253AD2D24FD20ULL, 
            0x55F09E35391FB801ULL, 0x920CBCC735C13ED5ULL, 0x7FE087E3054557E0ULL, 0xA93CD822F5E906DAULL, 
            0xF01BE513C0CE62B2ULL, 0xBC0A6C6CF0B4C877ULL, 0xB43DC875DC24688DULL, 0x0E8E6F8D13AFE6F5ULL, 
            0x1CA2BDEA2CA9E76FULL, 0x1C9BD526F0804CE9ULL, 0x647BD1AE7C0F2D5CULL, 0x7027200EFC0B765CULL
        },
        {
            0x9AFB0588DA18D8A0ULL, 0xD039CF2A5FE383DFULL, 0x94BE3CE6ECB8D6F5ULL, 0xA380B105EFB0A099ULL, 
            0x4370BFEE4492B477ULL, 0x0BEE282BC8436D57ULL, 0x5C0F3764CBE7637AULL, 0xD35B7EA97F334FAAULL, 
            0x1DDF766CF1BFC8FDULL, 0x149D3E830422F6BFULL, 0x30BD6D213FBE1FEFULL, 0x3475B610BBDC757CULL, 
            0x34251A5BB9925AD5ULL, 0x528C3E17B4A8637CULL, 0x77E148466D220BC3ULL, 0xE80AB11402492A4AULL, 
            0x635AC894ABD0837BULL, 0xE58CF260E0AF1787ULL, 0x10893433A6F97A9CULL, 0x3D666BB53D80034DULL, 
            0xC960C3AEAFACF16BULL, 0xFE5C04A0B2FB7710ULL, 0x39B81ED4043BCB4AULL, 0x80D0E02FD65BB5C6ULL, 
            0xA27C4617A3FAE1AFULL, 0x54027F204B2CDBE8ULL, 0x8E2A5421C8855769ULL, 0x06B1F1AA383FF490ULL, 
            0xCC037E1E9E9FB80CULL, 0x945A924130058872ULL, 0x9CC41317AEB9E3B1ULL, 0xBDCBAE5B17B6FE50ULL
        },
        {
            0xDD2E6497A5571D69ULL, 0x10980B0176AC131AULL, 0xF2F122939CF70DC7ULL, 0x05271C83D32F7F9FULL, 
            0x758CFE22370739E9ULL, 0x16B116CE0338C07EULL, 0xC058A8547843D21AULL, 0x1885985EEFE44189ULL, 
            0x74317958F07E376DULL, 0x7C9C6B614101A2E5ULL, 0xE57C2591FE557493ULL, 0x5B5BF881D865FAE4ULL, 
            0x613A33F8AC51ADB6ULL, 0x90DAF50F8D8B50C0ULL, 0x1B4A2D5B21498267ULL, 0x687566893CB10C81ULL, 
            0x61FAE374187CA718ULL, 0x005CF7CDF57A36DDULL, 0x34F56443E20341E5ULL, 0x0F1F6BE5B3BFB522ULL, 
            0x12EDDCD55C8084D8ULL, 0x993A7B812715FFD8ULL, 0x0EE521AB31C0D4ACULL, 0xEA1E09FAE736190AULL, 
            0xA876DC99A90B972FULL, 0x2898C23220D3CA44ULL, 0x69AA8123662B8FB1ULL, 0xE89BDB6653A10B3EULL, 
            0xD4181E363330923CULL, 0x8D4B2ACF484A18F8ULL, 0x1579A59D8CF3A08CULL, 0x1E7D04706982C6DBULL
        }
    },
    {
        {
            0x9BA29218EFAA6B1DULL, 0x131D5143CEDB319CULL, 0xDAC13D35176C376AULL, 0x7717A56198F27DCBULL, 
            0x1BCB03861CEBE401ULL, 0xC09BE54B9E7563B3ULL, 0xB55BD185AF99330BULL, 0x92597601BE268477ULL, 
            0x84843C77013F85BDULL, 0x8792A89E52774BA6ULL, 0x1BCF9B2AA749731CULL, 0x5096543B5303C9C6ULL, 
            0x4B62B5FA831CEC1EULL, 0x061242DA117D048AULL, 0xB9FD19D544442806ULL, 0xF34BDBD50543DCFDULL, 
            0x2D4AAE1CE777A89EULL, 0xD71287FEC1ED1212ULL, 0x60A4BB8E9490D2C3ULL, 0xC0A4C60C0EB532D1ULL, 
            0x8C23B0E5DA5B5186ULL, 0x672ED94B86428A9AULL, 0xF60A21387AD7C0C4ULL, 0x30E0448AA9F34641ULL, 
            0xDDFBFE4C7265772DULL, 0xD265CDC12D8F3528ULL, 0xA023C8F82C33AA42ULL, 0x1C4B929C1D7B4482ULL, 
            0x8F17D12FE6A3645DULL, 0x780DEB734C1C049DULL, 0xDF072E91EF26E3EFULL, 0x40429C0EDE0A6EA7ULL
        },
        {
            0x1DD4F51B7BCAD6AEULL, 0x39F76D014190EA45ULL, 0x67004E7143DA4FE8ULL, 0x4AC668F1846FEAD9ULL, 
            0xF047EB5A7D134219ULL, 0x2BC438DE9F55406CULL, 0xEC6864418D9B3AE5ULL, 0xCBBC2540D346DA06ULL, 
            0x9BB488677CDBFFFAULL, 0x2FE66F71DC1304C0ULL, 0x715520CA253CCDFEULL, 0x7FC14AB9A14C2824ULL, 
            0x021EDEBA20DB785CULL, 0xB6BE18FEAEF9F340ULL, 0x9A52082AFFB16643ULL, 0xF3541A1899F9501BULL, 
            0x8DB304F024D22A51ULL, 0x8479BD4DAD572A5EULL, 0x68E4892164317EF7ULL, 0x1564ECC5C10BAA98ULL, 
            0xC2FCBB7F9FF7953CULL, 0xD9B19220FD82BE0CULL, 0x55BC72419245C989ULL, 0x71644782BFE060CDULL, 
            0x2136ED87387CD0F8ULL, 0xA0AB0A2952CCD15BULL, 0x5E79329D08FDF06BULL, 0x48F676379E72B8E9ULL, 
            0x9EF6CF9E5CFF2FDFULL, 0xA72B2F5672A056E8ULL, 0x2920BD1BF3676E56ULL, 0x0BF4D7A955CC7C15ULL
        },
        {
            0xD1D6AC3FFB81CC89ULL, 0x747E8D3FBF62720CULL, 0xFCCBA05C813EC9AFULL, 0x05A37F85F764BB2EULL, 
            0x9F1524FC6512B2B2ULL, 0xB296486E901C9211ULL, 0xDFA92FB601A1C041ULL, 0x751092F4C0D75723ULL, 
            0x49E626BB5D0F98C0ULL, 0x9AA843A4CA4431E2ULL, 0x9BCAA8AE361C10FCULL, 0x1ACDE79FE34FDC90ULL, 
            0x41657B8E482F1684ULL, 0x51A170533C31A2E8ULL, 0x6E0410E904B5FA48ULL, 0xB8286C76D212038EULL, 
            0xABB5F4DB09D6C2CBULL, 0xCDF8F77A4D4770E9ULL, 0xEA5D854BAFE65ACFULL, 0x1A362D92E0A4A9FFULL, 
            0x3215D496E6025039ULL, 0x47B66822162EACD9ULL, 0x48B94F92A6E2A38FULL, 0xC0E18226C67605EFULL, 
            0x2BC202630CD6500AULL, 0xD297CAFB9D126CC0ULL, 0x5DE98451B8DADB76ULL, 0x4FF922B84C6537AEULL, 
            0x73726187B2F42754ULL, 0x29AB86E02281CFACULL, 0x041D1533058B9DADULL, 0x4D99DC18274777B1ULL
        },
        {
            0xF8C3C5ADC9EBDF31ULL, 0x402D17243E5E5CD4ULL, 0x11E147A0453EC091ULL, 0xCAF91A307E09DB6AULL, 
            0x057479670B1D8269ULL, 0x8747A0F9FD04AF56ULL, 0x678CEB7F2ED537DFULL, 0x0CF1720C880763EBULL, 
            0x2DB079A4EEE81C5BULL, 0x9FE73C23E9054FD3ULL, 0x72FA839C9800E6FFULL, 0xF452164B698A0FDDULL, 
            0x647FCE648DE49F3FULL, 0xD5F412ABA6245605ULL, 0x29011BDD0162CC11ULL, 0xE5820810015BDDE2ULL, 
            0xFE5038581734DC7FULL, 0xFE504B6353048694ULL, 0xEFB0FF506AD5AC0DULL, 0x7854E90E417FDCECULL, 
            0xE9855AAC61447BC6ULL, 0xF2333FD4009EC6F8ULL, 0xB0162F5BA09093D1ULL, 0x605C23B59D4F2FABULL, 
            0xC148568EE260D536ULL, 0x4176EA5D59F54CB7ULL, 0x4B0A9EF24965C457ULL, 0x3C8E869096F73816ULL, 
            0xDF659518716A5BCCULL, 0x8A2B408DE870E0A7ULL, 0xDC578BBC065F67A6ULL, 0xFC8311E35AF5C14EULL
        },
        {
            0xB255E233EBF1A01DULL, 0x98563525A107DB33ULL, 0x45ABDFBB1CD136B0ULL, 0x29FBB316376A9A7CULL, 
            0x63919E87C3AD8FDBULL, 0x9EEAC61976E17BA3ULL, 0x131DA49135B1740EULL, 0xC3B1C0221F5CD75CULL, 
            0x0AAF29089C85C112ULL, 0x024B47ED754003CEULL, 0xFFD55DD4D951618DULL, 0x0F7174D8A1AFEF89ULL, 
            0x876C6259ACE3FC34ULL, 0x91CB93C612E93B26ULL, 0x7C9B96E8B0E6A75AULL, 0x62C7CFB609801398ULL, 
            0x467778F7E1BEF000ULL, 0xFC01DC8C70D46D43ULL, 0xEE427D0AF8BE7A9DULL, 0xB4CB005D07E0D7DFULL, 
            0xEDDA16EF090F2F26ULL, 0x58B0569F94FBE489ULL, 0xE34BA9D790AC81C3ULL, 0x7CAB634BABECB87AULL, 
            0x28791CF569FAD8F5ULL, 0x236BC598B89281E0ULL, 0xD25340AC90270E43ULL, 0xC3B0419A25A603B8ULL, 
            0xF6C964909DACC8F8ULL, 0x5200573BCF100A33ULL, 0xAC9DF9D1FD69938BULL, 0x165BAFCEF06D5D01ULL
        },
        {
            0xE0ACAA6BD7DA5956ULL, 0x2BDE2CA3302679B7ULL, 0x674B97FD6A6D84FCULL, 0xB116CE42B7F99E99ULL, 
            0x4E1380053A183967ULL, 0x92C32F194517E88BULL, 0xCBBE3F69ABC66B84ULL, 0xC9910EF6F0192117ULL, 
            0x761EC89E2E9C777AULL, 0x0FCC8186BCBFF231ULL, 0x34E33E7D51DEFB63ULL, 0xE6E81433CFFDF315ULL, 
            0x9E823BE5996327A3ULL, 0x39E768C5E81059B9ULL, 0xD7B62431714B932BULL, 0x4CBDA263FFCB2BB6ULL, 
            0xC53214FEBC6C7520ULL, 0x4CA389882AC90658ULL, 0xEE45FC126EEED83BULL, 0x940A1E8DC0BC6829ULL, 
            0x2B8B59B065D4564AULL, 0xBD3FF324CEDDAFF5ULL, 0xFFF1850F653FE104ULL, 0xF681078B7F88937AULL, 
            0xB0C78E83D96F0DCBULL, 0xA5657C080ADB04CCULL, 0xDD58B4E43438122DULL, 0xD797ACC440EBC2AFULL, 
            0x37F704DBAD080394ULL, 0x7AFA6AD03E7B42E7ULL, 0xE62B8033F66798A4ULL, 0x4B3776493F1B7C37ULL
        }
    },
    {
        {
            0xE903295B946AAE43ULL, 0x6E68D73653AF2078ULL, 0xC90287EAE6C1E9D5ULL, 0xFBC11ABCDCB73345ULL, 
            0x7446CA41C95C6B24ULL, 0xB33FC6F8FB82E130ULL, 0x4F3DA35F53930824ULL, 0x8211FB03BE20B425ULL, 
            0x2F0412A4A9D52530ULL, 0x5806F93C096FA39BULL, 0x89E867DD116D951AULL, 0x065143000BA8C5A4ULL, 
            0xB6A400EF1F268A2DULL, 0x5BE40676D1C5ACDFULL, 0x31C339BC7162F4B2ULL, 0x4207F99F65960F70ULL, 
            0xA4DFFF17DEC7A231ULL, 0x4F1CA17E6D07B337ULL, 0xCFC00762F464D0F3ULL, 0x2D54438C635776E8ULL, 
            0x0C0CD94376320FEAULL, 0xEE90316D16362C51ULL, 0x88A8B2732CFFE7DAULL, 0x8CDCF0D40A7D3805ULL, 
            0x201AAD0E4D728DB4ULL, 0x61DCCB8E5B02BDC3ULL, 0xB8F523AC39BE31BDULL, 0xD6976D957172110EULL, 
            0xA59E66DB0D9E1B2EULL, 0x068F93CAE2452D70ULL, 0x41EB0D4E133EA60CULL, 0x4A16DDF757C446CBULL
        },
        {
            0x4F99CDEFB3FF1466ULL, 0x7F78BF0B5DD23F1BULL, 0x77E6856E80575A57ULL, 0xDD04ABB221B3E903ULL, 
            0x1DC826D2A3F2B829ULL, 0x2A27C604AACB356FULL, 0xA4B80199C04170F4ULL, 0x024B87E1902539E9ULL, 
            0xAD155448E7DE9F1AULL, 0x451BDD6E3B656CC5ULL, 0x4E466F15779EA135ULL, 0x2EEB4870499A7CA3ULL, 
            0x0E6C568ED997AA0EULL, 0xAFC321357C06D7B2ULL, 0xF5BDF2812B7FC565ULL, 0xD55ABFF9DFECD452ULL, 
            0xF35671D63D0F02B3ULL, 0xAECAB4EBF0DF15F7ULL, 0xE589668A2AF3C2DAULL, 0x7DB961F25D444C7EULL, 
            0x70C76E7327B48094ULL, 0x90832314C91F757FULL, 0x0897B2A16228179FULL, 0x8BAE8198BD167F8CULL, 
            0xF01CCC3ED5C000B6ULL, 0xAF72E8B244050875ULL, 0x2114F94501F5D53CULL, 0xC68BA664F5F3B9BEULL, 
            0xB072BBB4E0B61645ULL, 0x192B831C248013BFULL, 0x0942FEF1CF777451ULL, 0x0938FBF3C4B119D7ULL
        },
        {
            0x27245C47D0EC8B30ULL, 0x39799E55FEF9A181ULL, 0x6398488E3D45E4FEULL, 0x62CB6574F09CD0F2ULL, 
            0xBBD685CD89A15D1CULL, 0x80AEC7DC9CF986DEULL, 0x4CF8F935D5F21B4FULL, 0x64ADA51B0BC3CA10ULL, 
            0x0EF783B87F1530FFULL, 0x19C75C3EAD9B6051ULL, 0x65461C204A96BB15ULL, 0x7F946826184D5573ULL, 
            0xE035CD05699E6866ULL, 0x8825C0AE1AC97221ULL, 0xEDE6C5C883304B7CULL, 0x6085C7093D4230F5ULL, 
            0xA670A14EE7AADB9BULL, 0x1829E931788518D0ULL, 0xD9004502D43AD1B2ULL, 0xD300BC132F020BD2ULL, 
            0x17AB2C6C0BF6233DULL, 0x35A6B5BCAEA01B0DULL, 0x1C03FD2AAE997CACULL, 0xE15CBFA46448C0DDULL, 
            0x680E2C93683492B6ULL, 0x29A4562423CB7BCAULL, 0x78A57CEF4251CD5DULL, 0xC971113767D23B6DULL, 
            0x43131EE96BF5526CULL, 0xE76F808FD051FB25ULL, 0xD6A2844CA51D921CULL, 0xABED162BD90ADA5DULL
        },
        {
            0x651C53E44DBD77DBULL, 0x4021D3164CBC7029ULL, 0xD90D4E80DD72B7AEULL, 0xC9CED725F40B2C86ULL, 
            0xA1A9C590F67EDD31ULL, 0xFF553D21251D9CE9ULL, 0x4036862CB6F1A130ULL, 0x88F59C194AA343AFULL, 
            0x1C53C8AE5E18829CULL, 0xDC5AAD3B6A80C5FBULL, 0x8C27366813A631D6ULL, 0xB37FCF8157D78F62ULL, 
            0x6B35792B18F07BBEULL, 0xF6784977474E8C4CULL, 0x5C968ED0DD03410AULL, 0xB1985DDB39F55F48ULL, 
            0xA752515D8D7D3329ULL, 0x2B7AA2A78CB4DD6EULL, 0xB1CD14F3F4F6C9A6ULL, 0x9CCD988E40411941ULL, 
            0x591586064DABFE99ULL, 0x8759C3C299E0BC1EULL, 0x65AD59BC31A20CC1ULL, 0x077E03A8A4BDE431ULL, 
            0x42C32A5D0C158BE0ULL, 0x6845B177FCFABD3CULL, 0x5635B81C1289DA43ULL, 0x3ADF100361FCB175ULL, 
            0x62D4CF15F3F90147ULL, 0x25F8EF21550E4B2BULL, 0x813DB2D12147E360ULL, 0x99102327D672BE74ULL
        },
        {
            0xEE3D90511F38C7AFULL, 0x5814CF488476FD3CULL, 0x614D24E97E88A00DULL, 0x99D8ABFEABBF0687ULL, 
            0xDE45D7AB7B830CCCULL, 0x6DA0271A074B3A07ULL, 0x3C4A03D11AAF56C7ULL, 0xFB88B8E4B8527C40ULL, 
            0x4AC409BD31F6EDFFULL, 0x790680AEC9526FB0ULL, 0x8EF9976F13BB8238ULL, 0x53C159982646E8AEULL, 
            0x870F1EC000905CF4ULL, 0x8BF78CDB52725BE1ULL, 0xB31AC396E92E2FFAULL, 0xA3C5F25F89598767ULL, 
            0x97E03E75D8D32D5AULL, 0x767A7B5F419AB28EULL, 0x4B12DABE5635B9E7ULL, 0x592CA8D0A0D7F841ULL, 
            0xFE1A5A3B7ADB7635ULL, 0x62F2AC26140C45C8ULL, 0x451D43D3A663EF84ULL, 0x37D8820370987561ULL, 
            0x6125D212AF99939AULL, 0x4A9307AEEDAE64E0ULL, 0xA14A0E1E8150B21CULL, 0xB3FD5705BF63E2CEULL, 
            0x322EB4A2B6700CCFULL, 0xC5CBE13989849B00ULL, 0x6EEE58F792CB98D1ULL, 0x89B1725AFBECEDBEULL
        },
        {
            0xC5FC423EAD1552B8ULL, 0x127FE1AB53C1DD38ULL, 0xD91D0F0AC4A578A9ULL, 0x1B439A188D8A1E2AULL, 
            0x61D9B747979C7144ULL, 0xE7E03FA1F11A05AFULL, 0x588A1B583D7EEC2AULL, 0xB8FDBC4B606ED96CULL, 
            0x560B37F0C9CA0FF9ULL, 0xCD167FDB9B8318D4ULL, 0x88DE37C889A719CAULL, 0xFF9F2E2E3AD14CC5ULL, 
            0x3BAC7FBB172F2A20ULL, 0x00406FA666670489ULL, 0xB90EF63B10CB779FULL, 0xA26A3D54DF400D76ULL, 
            0xFD5B35A98B767D0AULL, 0x3E82DEF826D2C2C8ULL, 0xDF41EA21E902D1A7ULL, 0x64CBAB4DE774840EULL, 
            0x7B33A7E1500DDEE6ULL, 0x4E1F18654BFEE905ULL, 0x3422D97696AE07F0ULL, 0xF258488CE36E0E7FULL, 
            0x547245CCC10698A8ULL, 0x81B89B30A37DBBA8ULL, 0x467FD364FB458C2EULL, 0x48F6D30D13071E7CULL, 
            0xB8B6EF4ED964C342ULL, 0x65032D7BECED2970ULL, 0xBE92B65D6D485F55ULL, 0x50E2E54B93EB6B0DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseFConstants = {
    0x965DD23D442523CFULL,
    0x33A4242BCEB14E7FULL,
    0xA5F66F0311913A16ULL,
    0x965DD23D442523CFULL,
    0x33A4242BCEB14E7FULL,
    0xA5F66F0311913A16ULL,
    0xFC9909B38479BFB6ULL,
    0x098FE5EA7F27BFDBULL,
    0x75,
    0x25,
    0xD5,
    0x42,
    0x3D,
    0xEC,
    0x59,
    0x66
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseGSalts = {
    {
        {
            0x04A507AC33B3F368ULL, 0x2D99DC9AAB97816BULL, 0x574E7F5B1D8E414CULL, 0x0EA620D43CC316A6ULL, 
            0x519AF4CC6109284AULL, 0x2CC26B43D2291610ULL, 0xE184A626D1DE715AULL, 0x3A77972CA4EC9556ULL, 
            0x1EDFB68729C87E21ULL, 0x869E46F6824D1198ULL, 0x5F435B162B7C75C8ULL, 0x382ED2BB96204D3EULL, 
            0x8D5453A128EBA99AULL, 0x073EB3DEC014C27DULL, 0xF99089A03553A6DDULL, 0x4466B1190A17BCC3ULL, 
            0x6B6B3981CAABC91DULL, 0xAF86280A37E98575ULL, 0x9C429571EEB06B0CULL, 0x77D9D352929B4390ULL, 
            0xC7F526680CF1E07AULL, 0x15A112601E4E66E7ULL, 0x8F0A55AA5BC4AEE2ULL, 0xD06E6E82DEC65473ULL, 
            0xF870239E2F466DDDULL, 0x5534941E99AE0380ULL, 0x70BA18AA83282903ULL, 0x846C2FBA8B53F2C3ULL, 
            0x3BA05A12E3C0309BULL, 0xAAE49954726CCE45ULL, 0xD1B853ACBBAC0D0CULL, 0x9BFCAD36ABB1D7E8ULL
        },
        {
            0x90C2387F0809C6BAULL, 0xA9D0A9344395828BULL, 0x3C407A7546F68694ULL, 0x6AAB4876A1B2A9C5ULL, 
            0x37954D56F22E7F0AULL, 0x0746CCED7B34307AULL, 0xA7C234F348B98614ULL, 0xFAF4CCDCE55798C7ULL, 
            0x7049C8FCE025F8BEULL, 0xE99CD1BE2D1308DDULL, 0xF51ED206FBA98071ULL, 0x3CD24ECABEC75DD7ULL, 
            0x6CFF18712DD4BB60ULL, 0xEB0D4BE524FCA43DULL, 0x578D06834AFBBA69ULL, 0x5B6E92F163D63DACULL, 
            0x8956C8F333BF6019ULL, 0x3210766CDC1B221AULL, 0xA6F05AFF9A98B756ULL, 0x12980336E8361FDCULL, 
            0x0C00B75DB6556413ULL, 0x9566A1DB2C5E0100ULL, 0xC8B0A5092C1D3C66ULL, 0xE654A3B29F7566D2ULL, 
            0x135D4C5DD04A1354ULL, 0x0699505BC527A2CAULL, 0x9A58CE12CB503560ULL, 0xA57FDB968D7586FDULL, 
            0xCD70C864124C452AULL, 0x08E7299F37EC4C5EULL, 0x8D8CABB9111CAC6FULL, 0xD716304EC901532EULL
        },
        {
            0xBCBC6A4EBF4D1630ULL, 0x675788F78A5C7C3AULL, 0x12FA38BCEB2C2E52ULL, 0xF91076D6827862EAULL, 
            0x7A591A9C2A09CE8EULL, 0x5BB785BF0F225B53ULL, 0x25015EA24DB8F589ULL, 0xFEABD5082128E196ULL, 
            0x282A3C2FB29F0645ULL, 0x1844A7795F93F3C7ULL, 0x8197D207DF5899C8ULL, 0xFD831E453748F331ULL, 
            0xA37C37635B370746ULL, 0x034F6680672832F9ULL, 0x9C1EB5DD96C3F8BDULL, 0x33DF63A48F761025ULL, 
            0x42BFFFA90A892E13ULL, 0xB523C684166F3669ULL, 0x97C83681F86A8C6DULL, 0x5DA8D070912E71B8ULL, 
            0x444A6BD271B83CAAULL, 0xCA9CF26E6E3B622FULL, 0xFFBDADECF228C54EULL, 0xB6EA59C6495A0028ULL, 
            0x5D5E0D0F64219AC8ULL, 0xDCFC775E33B0836AULL, 0x92493E0AFA22D042ULL, 0x78715275F1ECCF36ULL, 
            0xEB4D18CC3ACEF431ULL, 0xB0EA8C2BD1641389ULL, 0x8F14BD8F0C13CE45ULL, 0x949496E4E8F93F4FULL
        },
        {
            0x46050003BD840B30ULL, 0x42878E224F9E4556ULL, 0x126238F87869B1F1ULL, 0xD5EBB810E78CD736ULL, 
            0x029C69BF3964DE2FULL, 0x1FCFAF862CDC24B6ULL, 0x197E5E710A953BBFULL, 0x380F239CD4BA0D56ULL, 
            0x6126C88DF583CCB0ULL, 0xD56D7736EDAA9234ULL, 0xDAAE6A58CE29E47DULL, 0xFDC9CB87B961498EULL, 
            0x1B5339878B33906AULL, 0x496CE5C9A06FDE62ULL, 0xD7D222178A7550FCULL, 0xB998BA375A7CCF6BULL, 
            0x316FF6A7186124BFULL, 0xC0C96547E8DDAEF0ULL, 0xE9CDF3D737D5E6DAULL, 0xF3FFE0BC42051FD1ULL, 
            0x734549CDCF7140AEULL, 0xE567BBD567BAA7EEULL, 0xF2F77B7794FC7C42ULL, 0x78CA93D2CD802213ULL, 
            0xCE560CC569FDD3FBULL, 0xB6C46AF41DB0739EULL, 0xF878EF63E0E38AF7ULL, 0x0679F85012425AEDULL, 
            0x9274A0C47C15B08EULL, 0xFD9CAED2C2D76E1AULL, 0x5FA1ABE0AF274D6AULL, 0x28970A905421BFB7ULL
        },
        {
            0xFA7CC74830A7640DULL, 0x842A852DD6C67AEAULL, 0x92FF6CDD4511C84DULL, 0xD39BDDF38CFF93D6ULL, 
            0x0B9EF77071018798ULL, 0xABA4E591ADA6B039ULL, 0xC9CBA00FE472CD22ULL, 0x8ED4571C98AB12A7ULL, 
            0x34AE14EBACFBB1C0ULL, 0xABD79E386C45A53EULL, 0x0EE7CC8E4C167365ULL, 0xC89E34E464DE897BULL, 
            0x8133D3758C9795F1ULL, 0x07C915CA26629DD2ULL, 0xA154BB4580E510DDULL, 0x62184E5C9B854352ULL, 
            0x643443015B36794EULL, 0xB382CF4A5D448500ULL, 0xD14A72AAE5D1AE69ULL, 0xFCF90E9EF89352B7ULL, 
            0xCBEF941B4C05AB67ULL, 0xCB8B3A1E0E436DAEULL, 0x06EB6BB7770AAC40ULL, 0x38A34BDCDB3992D2ULL, 
            0xCA2247E753B1627BULL, 0xA8CB6DD2A5A6DB55ULL, 0xA6A7DB0EB34980D9ULL, 0xFC1AA5BEFC4CB3D9ULL, 
            0x29EEC73E50130A31ULL, 0xBCCF0E78C84E2A96ULL, 0x589622EDFCFDE70EULL, 0x29F648FE78FC747CULL
        },
        {
            0x05BF391A946383DBULL, 0xF6A02FA7AF54808DULL, 0xF97458F144F73436ULL, 0xBB8C40060DDDE2D2ULL, 
            0xC34E41F572B75D03ULL, 0x8596B521CAAD27B0ULL, 0xC1611CE6BCF608F5ULL, 0xABDA9DE3EE7AC8D3ULL, 
            0xD015645584869ADBULL, 0x51C4F6E0D443594BULL, 0x61DBDB6C518043DFULL, 0xCE3CFA56238F524BULL, 
            0x4FB4EA232687DD69ULL, 0xAD655679D2AEC658ULL, 0x7EC9BB3FB752EA25ULL, 0x9DC456B70AA14A3DULL, 
            0x3ABA9BDCEC9E9A5EULL, 0xC4DA7E1500098441ULL, 0x4E7D47B67E4DD2FFULL, 0x7BE2D544043EB8D0ULL, 
            0x5446FCECCFDDF51AULL, 0x5BA88C78716AB7AEULL, 0x602334A720437A11ULL, 0x230B84AC65B6A8EEULL, 
            0x698D5276FE3EEB9BULL, 0x9F502F8F9378681EULL, 0xE97822FE575D2FC2ULL, 0x5EEA82DFB354B019ULL, 
            0x039280EA4309E495ULL, 0x3E74D860A1F1D10AULL, 0x226E9AE75C47D188ULL, 0x4BD91D2F42D70C3EULL
        }
    },
    {
        {
            0x39A81996818615C6ULL, 0x01E1AC71DCF31750ULL, 0xDD58140DBABB7FA3ULL, 0xBD183BFEF88FD10DULL, 
            0xA84E245D053BA1A9ULL, 0x086C40E13D39E864ULL, 0xB21BFA0F3FB44B49ULL, 0x1B06DD5637F1EFD1ULL, 
            0xD6775A00B5D0C040ULL, 0x812727615FC13C1BULL, 0xEF4F86D293846247ULL, 0xE1FE151B5E9E4B89ULL, 
            0x61F133BF547AA1EDULL, 0x6E9A34404FC466C6ULL, 0x70B7433641294CE5ULL, 0x073BE5DB338C9D07ULL, 
            0xDDA1628CAF3F736CULL, 0xE2B85F2DE41C47D0ULL, 0x184C215510C1FB17ULL, 0x006F2EC66F2F2FD0ULL, 
            0x19366BB27821451EULL, 0x1FEEB850057F6D7AULL, 0x3A8493F8D56BD4FDULL, 0x880447251DDA79F3ULL, 
            0xDFE03AC5F10FDA3CULL, 0x63B345238A479D1CULL, 0x74E21D158B34D6C0ULL, 0xABC5ABB549C4ED84ULL, 
            0xCB2C15529CD68BB9ULL, 0xAC8BC41F216BFF17ULL, 0x7D7ECFE620D78D01ULL, 0x639E0AAC13CB3E4FULL
        },
        {
            0x6C293AC19FE94824ULL, 0x49C0A2A97987A437ULL, 0x05C5A3911C3C9313ULL, 0xD3CF7BC799154027ULL, 
            0x4723F22F932EEC86ULL, 0x461D3EDEF8644CCBULL, 0x4A27A500A381BB84ULL, 0x17A638591B632BCEULL, 
            0x7A8B57D63BD1130EULL, 0xCF2952299A9BE4C6ULL, 0x20654E9137BCC4F4ULL, 0xAA3A4D4B482789F2ULL, 
            0xEAB3A0C73461A28CULL, 0xC4090004CD4464A6ULL, 0xCD32A83E5ECA20A1ULL, 0xF463ECF4305ADAA5ULL, 
            0x05558E28F1111F01ULL, 0xC79B985A541F31D3ULL, 0x9E5967D331D687EFULL, 0x321B7A4B681EF7D1ULL, 
            0xDF935631B7627C2DULL, 0x3D3C0ABC14B18641ULL, 0x10BDACC1128ADBDBULL, 0x609320FE7D29F669ULL, 
            0xB100AEE1994E1952ULL, 0xAEB1B76A4C8329CAULL, 0xF21ACB764BAEDE19ULL, 0xB6123F1018912DBAULL, 
            0xC7E75E70A07A211DULL, 0x1A90F7A66142223DULL, 0x2E0415A76E31CC3EULL, 0xF37F029B26EF1BBCULL
        },
        {
            0xAEC45B4477FE5565ULL, 0xFAFD7BC513359921ULL, 0xA83E45E4D8990A02ULL, 0x90162C3FA71201D4ULL, 
            0x4FCD60A10D1B5604ULL, 0x3AA0632B445E02B6ULL, 0x9380EAD6D31361EFULL, 0x30054D0B2779FCFDULL, 
            0xDEBD08DD682A326EULL, 0xBD66F7876207371FULL, 0xE6F6ACC15635C477ULL, 0x16D63D1971F6C556ULL, 
            0xEC9A622A80206E2AULL, 0x9A0BEB2B2140108DULL, 0x90BB71C27B9BDF74ULL, 0x40B8B30BB973E241ULL, 
            0x03C5A90629199913ULL, 0xE955F6A66FAF59A2ULL, 0x3E6D345AB0BEC4F6ULL, 0xAE910EBEC5680C45ULL, 
            0xA75A0C3F85E3FE27ULL, 0x2C8A75F087240ED4ULL, 0x674139E346F67B9CULL, 0x483528BFE8959E3CULL, 
            0x2A7AD85DDBAE1E84ULL, 0x37453C42DB1A1A23ULL, 0x3F4F4CE807D76B08ULL, 0x13A44831EBD92B51ULL, 
            0xA9FD9C72E4FBD346ULL, 0xC05B620E243AEE42ULL, 0x3A80D2CAF3E37D35ULL, 0x538F1078ECC0D1CAULL
        },
        {
            0x7E770EE3D2D7FDF5ULL, 0x904A873BEA512A5EULL, 0xCA105E36153BAF8BULL, 0xB7CC3774697F3441ULL, 
            0xFFBE147C13A9F5ABULL, 0x7CE5DE495A1FB72EULL, 0x436D88D9B0B21E6DULL, 0xDE14F3599A1ED0C8ULL, 
            0x643A23A8ADDDEFC4ULL, 0x1404054DB67DBBFFULL, 0x51A097FFD0D655EFULL, 0xAC292D895705068FULL, 
            0x3C66FBBFAC344816ULL, 0x0C1AF2564B3A845AULL, 0x01D0F013BAF04DD4ULL, 0xD983D57D3FAC816BULL, 
            0x1B57D8AE441B219AULL, 0xB7475DE5E41EBEDEULL, 0xEAE9F4048A225B12ULL, 0xA60BFA305A74659FULL, 
            0x90C33C93EC4B5A9EULL, 0x36BA2C627F1373ECULL, 0xDC8FD8B2E88C126FULL, 0x743B421E8ECB65C9ULL, 
            0xD08DCA3FC153C616ULL, 0x2C57C767A2F3F93FULL, 0x0978DD84A589BBACULL, 0x2E9A1585AC670E49ULL, 
            0xFEA9041AC8033EF3ULL, 0x80A61AC05E6267DEULL, 0x8AD01FBD0B12DC0DULL, 0xEF05CA8D3CEFDB17ULL
        },
        {
            0xF8BCB1121B2B0895ULL, 0x540DE37EA83E592EULL, 0xA0A51DCD0A8D2BB3ULL, 0x3311806195D29DE2ULL, 
            0x752E8F6E7FDDC5D1ULL, 0x8B220077624AD200ULL, 0xEC7F2942FC3F7B99ULL, 0xBC7094530CC37D2BULL, 
            0xC1E99E4BDD66A6E9ULL, 0x73427A651F3BA73AULL, 0x3D5579B7E49E11C7ULL, 0x0BE9651B85382DB1ULL, 
            0xD5FA0C6B3C00D72BULL, 0x03AD7212FEA99BDCULL, 0xA2C3709F9F83259FULL, 0x3317667CCC247981ULL, 
            0xBEE72919D8138B82ULL, 0xB23519CBAC21C506ULL, 0xB9A6E60ED8F69273ULL, 0xB17F117C1DD38F82ULL, 
            0x5C8F07C8924328AEULL, 0x41917133AEDED00FULL, 0x5632DCFF5F33E66DULL, 0x6967E54DFAAB337BULL, 
            0x31917DF86E72930EULL, 0x3A6DBC67721D713EULL, 0x12BCB334BF135A48ULL, 0xA0D4CD27949190F9ULL, 
            0x56366AC9A13CB253ULL, 0x0F9777C839F218F1ULL, 0x650A2D1ECBC08667ULL, 0x94F9805CF27AF9C6ULL
        },
        {
            0xF32B7BC04F92A383ULL, 0xFFBE731D048BDF1EULL, 0xB486965315D64CAFULL, 0xD6E12684165C4168ULL, 
            0x3182B3C0D114DF1AULL, 0xEA6FF0D164B26856ULL, 0x15A1A27C748A925AULL, 0x19B98C7B42B622F4ULL, 
            0x2C4D5AB1F7A6A8F7ULL, 0x98432B7D740C5CA1ULL, 0x66A9E3BD9A6B78E3ULL, 0x18CC7FA0ECAC5F0EULL, 
            0xFFCB5E0289E6BBBCULL, 0x57340CBB55DB2F3DULL, 0x4FC4C663E5F25AAAULL, 0x18EE3A849C0CAE8FULL, 
            0xF5945B7D6FE8A46AULL, 0x551F375052792830ULL, 0x70858C24B53BEA9EULL, 0x57ADF2FB49BF316AULL, 
            0xE8DA66520B016506ULL, 0x16DFB3891916A223ULL, 0xEF7BBBCD0F242141ULL, 0xAA3F7AA207856C57ULL, 
            0xFD2A0AAB44C82915ULL, 0x176BFA6D8F85BC52ULL, 0x9D93CADEA3A7DFF3ULL, 0x3A8C1CB9695256F2ULL, 
            0x975AA8CF19B608FEULL, 0xBDE279891DE083D1ULL, 0xA116E1285B06A305ULL, 0xD4A2A3D6601D33F7ULL
        }
    },
    {
        {
            0x7F4B5E9E3F52D900ULL, 0xA8867D68D4FD8943ULL, 0xE3804DFAB90F5FA1ULL, 0xB0C7527D1917AAC6ULL, 
            0xAD79A6706A01A2A6ULL, 0xA78696A6E5CB5DE1ULL, 0x2324027BB5837F5EULL, 0x3735C38E5F7EA77EULL, 
            0xFF1993AD2E324B00ULL, 0x82D9A8378C01CE37ULL, 0x751D83ED361DCA6DULL, 0x03BFF4B6D66DA9BDULL, 
            0x736DBE853961B86DULL, 0x69DBAEBC52BE9F06ULL, 0x9879BD4BFD90B98CULL, 0xFF2E918865109E26ULL, 
            0x755749D57D22FF11ULL, 0xDF5D59D38EFF7F34ULL, 0x61F24FB44FA92515ULL, 0x61CDA004354BA5F3ULL, 
            0x7B90A8797F69772BULL, 0xC18E6261533CF543ULL, 0x25AFAEA822F83BDBULL, 0x9D203F5BAB45A33FULL, 
            0x5775992F5CB1BAF6ULL, 0xAFAE082E94064DC3ULL, 0x15BBEADCBD85181CULL, 0xCF279C0BD07614F4ULL, 
            0xE627DC60BE0BC4CBULL, 0xC0D8C247B47D62B2ULL, 0xC8C40A2272A15EE0ULL, 0x985FF6BB564C4C06ULL
        },
        {
            0x4999918C0D49DD3DULL, 0x7FBE2E40F0FEA720ULL, 0x75805F4E621A351DULL, 0x73A3402673E17FEAULL, 
            0xE381D71E06AB974BULL, 0x2896717713D1BD69ULL, 0x3C9BDF655D523278ULL, 0x2D4236F2B9E6BD45ULL, 
            0x05DA5540D8B7F1A7ULL, 0x80C5D03FE1D046D3ULL, 0xC330550B3D99D986ULL, 0x500D7012EE70146DULL, 
            0x19F38B6B33FA2220ULL, 0xBFBB7099EA2B7846ULL, 0xE37409A8804769CDULL, 0x2445CA87E83C88B4ULL, 
            0x978EC82B7E558BFCULL, 0x529C33581322A985ULL, 0xCAFC38E8B7BFB3EFULL, 0x5DDF22E883CA8BC1ULL, 
            0x67344B13B96FCBE6ULL, 0xF78E0F3446E3074AULL, 0x06FA8EC3E283A1EEULL, 0x228A3DD5C625DBE4ULL, 
            0x6A8712CD761343E6ULL, 0xD732F113C5F4ACCBULL, 0xB9D213B8DAAFE67CULL, 0x40ED843134855BD0ULL, 
            0x46C70E2939D0F3E6ULL, 0xBDCA3DF685D672A8ULL, 0x6433D23123B12AC5ULL, 0x3D6F909B21736391ULL
        },
        {
            0x411EC944A7612CBCULL, 0x75692F8D26085F4FULL, 0x43BC11ADF66D8D2AULL, 0x97749E90EC2B03E1ULL, 
            0xC83E583FA4AC4F9FULL, 0xF13D7F2F030D835BULL, 0xE34916AF44A5B80EULL, 0x73734059EEC553F3ULL, 
            0x124BF8DA68393486ULL, 0xAFD7F47A0CD3212FULL, 0x43115B6245765CFFULL, 0x5D7251055C239C9AULL, 
            0x57EC707C23F7594EULL, 0xE00B1314672F3B13ULL, 0xCBFEDCB63E774603ULL, 0x0B8FD2AF2DCD6A58ULL, 
            0xA2DCAA98729E6612ULL, 0x92208F7E8F0D9EE0ULL, 0x5DBF38E1CCED228CULL, 0x099295B08FBD2261ULL, 
            0xFBE738ED3A6A2A2CULL, 0xFB5E1E3C6A8ED2C1ULL, 0x349CA35640F3BD30ULL, 0xFEF5585951E3654EULL, 
            0xB2B3F84B77ECBFF7ULL, 0xDEF15AAFEB114F2BULL, 0x08F4AF4A240A1F4DULL, 0x1DB456D26B8D60A6ULL, 
            0x40083AB0C18B1EB8ULL, 0xC39856583386312DULL, 0xC920D4D107E5CD06ULL, 0x3C59AB08670311DEULL
        },
        {
            0x244D02673878F700ULL, 0xDBE6F5EF0E15BDC6ULL, 0xC0DCE2E789189F2DULL, 0xD19C545C2C65953AULL, 
            0xE2CEFEA4E01A8F34ULL, 0x5716D2C01F11DDB6ULL, 0x3CC78AFB69E2F2B1ULL, 0xF9DBA4657B5EC821ULL, 
            0x1AF288297D6C4FEBULL, 0x72819B71C7D421B8ULL, 0x7E96A3C3397E2B32ULL, 0xBBFF3348ABFD01DCULL, 
            0xFB512C82DAFCF936ULL, 0xDC7E919A8F2AF63DULL, 0x1CC01EE06AF30CC0ULL, 0x77D1C10CA4249ED9ULL, 
            0xA87573F19AE5957DULL, 0x1596CC69D5457C9AULL, 0x5F410A0B1CC1B230ULL, 0x97821D9B53C5CC31ULL, 
            0xD6267C0ECBB43B35ULL, 0xB382FFDB6533E3C8ULL, 0x2826420AB68C82C9ULL, 0xDE1C87C0E42C7408ULL, 
            0xA19C58F89E7798CFULL, 0x515E89AEF6504E06ULL, 0x2785799F15FDB7C9ULL, 0xE32F85E5AB0DF096ULL, 
            0xF5F5951966197678ULL, 0x578AFEC95A49F171ULL, 0x80F92578CEF61650ULL, 0x51AA02FF52F3A774ULL
        },
        {
            0xCBF653D091A4B0E3ULL, 0x9A0E370BC9B4650EULL, 0xB57DF05E3F8CEB32ULL, 0xBB67B6EB04B2370AULL, 
            0xC9C3FA059D54E348ULL, 0xB60E870AAF6839A7ULL, 0x5BB3B448A47580FBULL, 0x8D750D5618700EA8ULL, 
            0x70295F06B12A5D97ULL, 0x0A8B3F0D03A1F460ULL, 0x86A692B6B9B4AF06ULL, 0x3A9F8E3C82E1C15BULL, 
            0xA7FED1622B40A57EULL, 0x5D0A446E954979FAULL, 0x489143092E5F110AULL, 0x75C80565F02A6AC2ULL, 
            0x8ED03DADEF291A66ULL, 0xFBE7D7E14197E9F9ULL, 0xA12CB4D56A7648D9ULL, 0x876FD608B336C88EULL, 
            0x86BB7C06FEF9A880ULL, 0xF10ACB35DAFF05CEULL, 0x53A7515B1CE5E337ULL, 0x959EC7DA5BC925EAULL, 
            0x62ADE4A4A7A15DE8ULL, 0x7C271A1FE5E69568ULL, 0xDBAC7282F13611DDULL, 0xF0D5CAB77D1AD934ULL, 
            0x350705BB0911BC2FULL, 0xD939402E53B7C090ULL, 0x748D917CD881DFDBULL, 0x7C24F7ED4AD9E840ULL
        },
        {
            0x45ECE66466903F88ULL, 0xF6D81F62CE44C76EULL, 0x1058CF66AFAD3977ULL, 0xDD0D12A08DBE6E1DULL, 
            0x2516214289619463ULL, 0x218DEA2558C7AF69ULL, 0x1BDA9914B0B95769ULL, 0x2929DABE520C522DULL, 
            0x5BF2663E986FCD5DULL, 0x779E4F5C555FDDEBULL, 0xEADB5BAB4166225CULL, 0xFD26BBB34777535BULL, 
            0xEEA83ADD4C182B49ULL, 0x1C280E9170C79B9CULL, 0xEFDCCCE6443E9FDCULL, 0x65A81496EAA0866EULL, 
            0xA68BB0600EC4AB93ULL, 0x4DD8CF1196BFE88BULL, 0x82D5AD576F06B339ULL, 0xB48FBE2386A5AD2EULL, 
            0x9F9E1FD1D2C598B0ULL, 0x24456D8966640974ULL, 0x1B0F2872D37E8374ULL, 0xEFDBB52C6F526583ULL, 
            0x6B66B73640F0BF92ULL, 0x8C6396038EC60776ULL, 0x7C43CBC51A2B7048ULL, 0x97929BB8CF3119E7ULL, 
            0x188F0E77E4FE1B3BULL, 0xD39B7BE934AD0D4CULL, 0xB4232EC95C75D149ULL, 0xC1E4A1F98E22F7F9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseGConstants = {
    0xC3F904E7E5826690ULL,
    0x2BA70E51FB6BE4ACULL,
    0x5A94FCFC5AF0B6FFULL,
    0xC3F904E7E5826690ULL,
    0x2BA70E51FB6BE4ACULL,
    0x5A94FCFC5AF0B6FFULL,
    0x4E6252CDC20D119AULL,
    0xCA6AE9AF66580776ULL,
    0xE4,
    0x12,
    0xFE,
    0x09,
    0xD7,
    0xC4,
    0xB1,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseHSalts = {
    {
        {
            0x303F2904CCD7615CULL, 0x39892FC505A19E3AULL, 0x054B18E4CE291E69ULL, 0x710AB7B416245BE4ULL, 
            0x3CF5930BF8700F0FULL, 0x05768B968DA0DE11ULL, 0x4BE90082BC485C1EULL, 0x4D1B571A59918E7BULL, 
            0x03507F4E887D884AULL, 0x0318F86556E4E0ECULL, 0x4D3EE7E9B85EB232ULL, 0x8234F1EFECEF1C0BULL, 
            0xA9A7D5EB47649C56ULL, 0x8A0DB7A824F3EA34ULL, 0x3B390403AF5BF325ULL, 0xE691F8E7D1F9246DULL, 
            0x23B1CD5E641A9155ULL, 0x1FB8CCC6E3912B6CULL, 0x393C9E2FAD85F342ULL, 0x899B014F39AD96B0ULL, 
            0xBF5C2DF76EBD8036ULL, 0xB408C06EB5485206ULL, 0x9D65FA0381915E41ULL, 0xDF35CA7E6EF8F563ULL, 
            0xD5B782F147F32FB8ULL, 0x3090CB43ACE86C84ULL, 0x8D890269E2163EB2ULL, 0xDA88DE8D5F10576BULL, 
            0xBC605BB48C7E932CULL, 0xAB794F94BF7ABC35ULL, 0x42F3F49DAC6754FAULL, 0x92719927C3E9720BULL
        },
        {
            0xAE823CFBF2C3EAD8ULL, 0x28D82A9B4E3790C4ULL, 0xEA851BA3FE85345CULL, 0xEF015C856673960CULL, 
            0x869128082D21E726ULL, 0x76F68DF7A5DF0072ULL, 0xB8E0D2F69D1D19BAULL, 0x5D9FB1D6A8DEA1EAULL, 
            0x739F60D279EF42DCULL, 0xBC370555C41384C3ULL, 0x647DE9762F681304ULL, 0xC1DCB7583B5D4FECULL, 
            0x4E4DFA8781D6A576ULL, 0x985C6F4C6DFCFD21ULL, 0x95988C9CDA98E940ULL, 0xF7C1454A4BF47685ULL, 
            0xE68A308E41048744ULL, 0xBE85B12E85E9F228ULL, 0xBD7130854DBB1402ULL, 0xFBA93DFE3382E020ULL, 
            0x05A5317B240B1E23ULL, 0x90D3F1B8612C2605ULL, 0x6D57AB3F4F5EFAF8ULL, 0x9F607CF5D4461389ULL, 
            0xB47925E4FA0B20C6ULL, 0x68707E6FD92D8B6EULL, 0xEAB16CBF9EA6FBA2ULL, 0x1F52A2AE1DDBC1E1ULL, 
            0xEFBAAEE7AF8CF507ULL, 0x5F0A3E77E9679108ULL, 0xAE13532B0171E274ULL, 0x3A8276FDC2301951ULL
        },
        {
            0x9CA639F0A841BD86ULL, 0xF79AB4E62FA19018ULL, 0x928615FFD8B6D055ULL, 0xAB34F7EE5BE3FAFCULL, 
            0x3535A6B25F3F41ABULL, 0x90C1FA6BEB0B3044ULL, 0x4D43DE66B2026FFDULL, 0x6BF30C50A2C2DA83ULL, 
            0x90EE557AA3024B3BULL, 0xE7C564B1A03DE185ULL, 0x56B194AA5B75BAFDULL, 0x46D1F10675BD06E6ULL, 
            0xD0582A20F84E4BB8ULL, 0x8ADFA811BCB5B9ABULL, 0x4F826EC22A9F79E4ULL, 0x72570873C47695ECULL, 
            0x209F055C789E8A94ULL, 0xA9E200548DE8F4F3ULL, 0x03642034FFA1BF2CULL, 0x58296358D70BA951ULL, 
            0x722C6343337AEF28ULL, 0xE08BD4CA7D6DD9B8ULL, 0x7D100AFCA71E7E51ULL, 0x68E0D2F62A829AA0ULL, 
            0x67E309C7BF4D16BBULL, 0xE02C7167BBB51EF0ULL, 0xB035FBC9F2E6289CULL, 0x8E855F478F48F177ULL, 
            0x30BFBFD7154D961FULL, 0xC5CD3B6AFE32C253ULL, 0x1C73AACA53CD5279ULL, 0xA098E4AF3FAD2387ULL
        },
        {
            0x0685DE5B6EA7C745ULL, 0x67DE8590A95D9DF6ULL, 0x8F12E5043F3FCD1DULL, 0x4303C43703AEE79AULL, 
            0x1DB1848BB8DB2832ULL, 0xB4A694BB99C338DCULL, 0xDB179ABAD499454BULL, 0xBFC0E392B7B6BF77ULL, 
            0x14A258A6827FBF2DULL, 0xA1A0DABCCEE74035ULL, 0xC3FE112DDFEE31CAULL, 0x3A8F8E853CA06EAFULL, 
            0x35FA4FCE500B824EULL, 0x60A591FC831E0BE4ULL, 0xA2C4EAA34E801BB6ULL, 0x37392A788BEBBC7EULL, 
            0x9863DEB93BE898BCULL, 0x31E3DD5D1E5BC251ULL, 0x594BEE7D814F321FULL, 0xE4D6F8CF172C56D7ULL, 
            0xC91757CD276D4C34ULL, 0xD226DDFECADEBEFDULL, 0xC4B57A20DC7DBA5EULL, 0xEDE5281A79643485ULL, 
            0x83168A9B554EB81DULL, 0xDBA50DAE38010136ULL, 0x7286737CEFD2C85DULL, 0x1ABBDDD42C550E31ULL, 
            0xBEE140F0BEE03A96ULL, 0xA4AEDC67769E05B8ULL, 0x0FC799D239DE8287ULL, 0x6303C6B1A48799C0ULL
        },
        {
            0x0B0DFF4560A0013BULL, 0x72303D00A720BBEBULL, 0x83D4B811F837DCA7ULL, 0x8628186594ABA863ULL, 
            0x78D92A84D3BA2DA4ULL, 0x52EE58141A879C51ULL, 0xF3A213C5C6E99C49ULL, 0x18C1EC6A26B58210ULL, 
            0x3C63C1F087714BB3ULL, 0x198248B0710907C7ULL, 0x40E585704C9D0611ULL, 0x191BD25EEC159EF5ULL, 
            0x59048AB3BAD5DDB7ULL, 0xE8149BFBEC90798EULL, 0x2A4B1A389D5533B7ULL, 0x7B87832A3979AF89ULL, 
            0xBF707694D5D4ED2CULL, 0x5066B87FE2232F4BULL, 0x73291A1009F0A73DULL, 0xA3CBA73697ED52B8ULL, 
            0x51549E17F049CF9CULL, 0xC1A2D9F3345AEC70ULL, 0xAAE494ED2AB27A78ULL, 0x37D32E4F06EC4B79ULL, 
            0x1E74C5E2AC91A987ULL, 0xC2CEF7624E8C5402ULL, 0x0D85C19F68006303ULL, 0x8E307285AA08D3DBULL, 
            0xD93B1B5EA2B267C3ULL, 0x66EBF99E954DBCC1ULL, 0x89DDC040C91465DBULL, 0x834410B43D11C04AULL
        },
        {
            0xA076BDC539AD7CA8ULL, 0x2F7E1C7CD5554EFCULL, 0x39EB709BBF9A215AULL, 0x72E19376EA32A60AULL, 
            0x72CCA23B56355C31ULL, 0x89FBB9DFBC55278BULL, 0x0BE7C6B69B130ED4ULL, 0xA58B4303D985EB13ULL, 
            0xCF2C0DDCFBA37F53ULL, 0x846D1F919048B0ADULL, 0x63ED6F9DFB72E776ULL, 0xFC66EB86D5F20434ULL, 
            0x4E72F4BB704220B3ULL, 0x2461F5AC5786EC52ULL, 0x49705799D404303BULL, 0x1328347042CAFF63ULL, 
            0xD08F2B6A1F1FF59DULL, 0xD0ABEFAF2BE477EAULL, 0x5560556F6DFFA803ULL, 0xCAFE84A77F0F1550ULL, 
            0x37208C5CDC9B72BBULL, 0xD1995890FA04457AULL, 0x50D257EB2099AF80ULL, 0xD842974E875F6BA0ULL, 
            0xEC2F52261D28AA8BULL, 0x109B7450B2BFF691ULL, 0xEBDA5334AA9251B7ULL, 0xEA1940DD91718A88ULL, 
            0x0F6F109DAC8051A1ULL, 0x3526F241765FE9A1ULL, 0xB24F641D675BC03AULL, 0xF09CE1A187586467ULL
        }
    },
    {
        {
            0xA6FC633A8E78B118ULL, 0x5127EE7B39B279ADULL, 0x0D9CA39582EB4273ULL, 0xE981128C0BBA99C9ULL, 
            0xDAB6D4E73A4D0DD9ULL, 0xE4B75A1ED360819EULL, 0x966C744E31630FF3ULL, 0xE7FE76929C1A5B26ULL, 
            0xC6109134458BFB50ULL, 0xB46161649C397F82ULL, 0x412AC276538BBF63ULL, 0xD2F89E5E9A3190ADULL, 
            0xECE3E40599D2CA79ULL, 0x73A77311CF1BCA75ULL, 0x718E4A54EDE7472CULL, 0x6B4E5DA31D170AEAULL, 
            0x5EBACE243E16E407ULL, 0x1196B6E04B396DA1ULL, 0x7E7086521936E4F8ULL, 0xDDBBAF3BFE08CEFEULL, 
            0xF3B9C1EDF7D6C46FULL, 0xF3C53474A6BC1A49ULL, 0x6D989B8EE708C07CULL, 0x0C2F1392F9E3CDB5ULL, 
            0xCF6052E5EC95B2E6ULL, 0x6929A4E7C650C9E9ULL, 0x9A9F65433BCDE003ULL, 0xAAA0E51EB35208FBULL, 
            0xA06CC7F2DCD3F900ULL, 0x3E492456F5B1D285ULL, 0x9070C4DE499BA5A1ULL, 0xDFA47A800853E19EULL
        },
        {
            0x22A57DEFCFA15B8FULL, 0xF87FD0F0065E2910ULL, 0xD253317D04637991ULL, 0x4C62725C499CFC7BULL, 
            0xE6DF69F451A718A1ULL, 0x73AC8F78CEDA45D4ULL, 0x8F299BF1EA011752ULL, 0x6C4D4B61B55173F7ULL, 
            0x16C3D46F8A89EF3DULL, 0x6CBAFA500C6008CEULL, 0x2125F82F52EC41A3ULL, 0x7826CC9D331EC322ULL, 
            0xC464BE7F56690F6CULL, 0x6B9229FA9E437EE7ULL, 0x834B3F61DA954B1AULL, 0x7CBC3A1C5458CC0BULL, 
            0xF8A8C12D163C8491ULL, 0x06F71BD35985AC9DULL, 0x3F8EBC692A122021ULL, 0x45C341872D7435AFULL, 
            0x8CED19A9E0D688A5ULL, 0x83D610D849791692ULL, 0x7F181A845807F0B4ULL, 0x63A333CB4C8D93DDULL, 
            0x3AC4737B9C5BA49AULL, 0xA3E150FAA8D4F030ULL, 0x7E4E187F8A2DF8AEULL, 0xFF5262165527F5A6ULL, 
            0x0D4EE01175E5A580ULL, 0xC9ABC98DFC748290ULL, 0x5E25A20DFCD4EA9BULL, 0x6E216D31805345B1ULL
        },
        {
            0xC5253308B3267704ULL, 0xDBDDC4A78E846922ULL, 0xC9C0B1364231CA32ULL, 0x42268A3DBCB71C73ULL, 
            0x9F85FB9BF5E5DDD2ULL, 0x91262168839480F7ULL, 0x23E408EE234CAD2FULL, 0xCF87AAD62A1A3B5CULL, 
            0xB388911E2DC24302ULL, 0x7ED009F548B4E67EULL, 0x8F9F74F562A44EB7ULL, 0xDFA2CBC8382E7FD4ULL, 
            0xAA9D58524CA643DCULL, 0x38B25056428187F5ULL, 0x626D387FBF1C5117ULL, 0x3212E3FC72978922ULL, 
            0xF1D2DBB7004E9484ULL, 0x7208B5440D1F6218ULL, 0xE1768A691A2FED78ULL, 0x706F0FA333A3A0A6ULL, 
            0x1039F174DEFAD11CULL, 0x5EFDFC3F595B1FA4ULL, 0x8CA6D099C3617BFDULL, 0x4141043849BAF81EULL, 
            0xD423BC20A9E4793FULL, 0xA4FC08D237A7044BULL, 0x36FE1877CD6D0A1CULL, 0x009C04BEBB4FDF22ULL, 
            0x81BF6B78075D95E9ULL, 0xE79269AE9CC9EA41ULL, 0xBB63DA606B5B7089ULL, 0x3697AC7D88B3CF5AULL
        },
        {
            0x3D5880929F3331CEULL, 0x830A810EA2B0F72FULL, 0x4FB4C8F34885DE6AULL, 0x1701F338E7B66B59ULL, 
            0x4CEEE6ADBC960ACBULL, 0xBFAE4CFFDCD529F9ULL, 0xA20DF818E661A48CULL, 0x35BF41CD562F83F3ULL, 
            0xFDB9DED0B18FF486ULL, 0xFB6516A3D65F3BCAULL, 0x8E9EE9EAAB2E9710ULL, 0x1C7DBE3A330A5AC9ULL, 
            0xFF378D16B2EFF746ULL, 0x14EC2EBAD0679D33ULL, 0xE534ECF00AEC8CBCULL, 0x2AD603AC4E690B4DULL, 
            0xDAE3A030854553D9ULL, 0x2A021E19E1C76CDCULL, 0xF1A8F772F87B17FAULL, 0xD0313F92E38B92AEULL, 
            0x9C740814CF727EDCULL, 0x243E0B8055AB8665ULL, 0x463ABD137D067C25ULL, 0x153883EC29B61A48ULL, 
            0x051726B07AA9016CULL, 0x901A025355214E3EULL, 0xA7C7962E80BD413CULL, 0x4A04098ACF855131ULL, 
            0x6E4149297ADB53FCULL, 0x58DA31CEC8739AEDULL, 0x53AB5ED4D2540973ULL, 0x13FBBE2D1ED43732ULL
        },
        {
            0xD8549D23BC98ABFBULL, 0x82E8710E4B3AEFF1ULL, 0xF87DC8BC40EAEDD6ULL, 0x964CC1EB602BFEAFULL, 
            0x8CB48C074A50E7DEULL, 0xA5FF9D002621B8A7ULL, 0x6CD47D7FE19DD58DULL, 0xD1E5D701DAA88D9CULL, 
            0xFCC9BE7DC4BA9A18ULL, 0x704CF9AD148A41FFULL, 0xAF7FBA3A087A89A8ULL, 0x0EC336EC45D0B6D6ULL, 
            0xE040EC7E09A3EB20ULL, 0x8F5B26B1EFFAAE58ULL, 0x80BF449FF0D7C816ULL, 0xBA8CE6943AFC39E0ULL, 
            0x08D101421EBB5D10ULL, 0xD496DD1044CCA425ULL, 0x42DC65239F0FC14BULL, 0x17DCEBB59403444CULL, 
            0xA980E0A525BE9045ULL, 0xC40BB55E70463638ULL, 0xD8B3B016FEDB1FE7ULL, 0x122B04890AB983E1ULL, 
            0xEB42F8603C12B984ULL, 0xA7719518010A8C09ULL, 0x7012791BC3327CC8ULL, 0xAF130D569407E230ULL, 
            0x9F4AAF656A853286ULL, 0x2B907F8AFC87D5FEULL, 0xA0D6B53F9DA608BFULL, 0xA61DE03D85446972ULL
        },
        {
            0xDA0E34D178A05CEBULL, 0x28E680F87630305AULL, 0x248754EDB31E3F83ULL, 0x6F37AE26ED436E32ULL, 
            0x3ABAD4CC09D4BDE5ULL, 0xA40C682E53A455B4ULL, 0x3EAF02F00A96CDF5ULL, 0x3584C4762C535ACEULL, 
            0x56C9E527E67F9D42ULL, 0x78B8B753F3E83C5FULL, 0xA1130367F94A44B0ULL, 0xE6646B88CAAC570EULL, 
            0x591C7A487BE0B89FULL, 0xD1C8667905E1599DULL, 0xA968F80CFB46435CULL, 0x48602E2FB8404AADULL, 
            0xCB0A4F9D60387D8CULL, 0x8F74616B9B5A9FF8ULL, 0x80758A31FF97EFF2ULL, 0x1D144954120E23FDULL, 
            0x09D6B8C80AA8A652ULL, 0xB06A12C1022C5220ULL, 0x8AF110E0203E37E4ULL, 0x9E6EDC0745D05163ULL, 
            0x72813977E6EC65AFULL, 0x1A436AC2E81033F9ULL, 0xE1AA57FC5E97C733ULL, 0x416F47175088D92EULL, 
            0xB419711D0423E946ULL, 0x66CBDC61FAC356DBULL, 0xC72EE773795F782EULL, 0x9A8794A4D81D80CBULL
        }
    },
    {
        {
            0xAF5F1623C876AB63ULL, 0x5C1288B6F85A0D40ULL, 0x41DF795912B07309ULL, 0x770D5A8AFE03421EULL, 
            0xCFA07FD09F0EDE85ULL, 0x6EB4596DDFDF5D1BULL, 0x60252184C3EAFA63ULL, 0x2DFCBA8702BA7C36ULL, 
            0xBE9D2C96101FE201ULL, 0x5C9E8D8ADD55FFC8ULL, 0x232DD308BCA1D9F4ULL, 0x97E92A52F356C3E7ULL, 
            0x8154888D6A568866ULL, 0x548C66DAB3E9635AULL, 0x9189E09DF32BBBD2ULL, 0x0E6553BEE2DFB0F0ULL, 
            0x7300744AAC4ACF78ULL, 0xED7C5FF1CEDC3F73ULL, 0xEF3CD3D99CE52F70ULL, 0x7A7440F8C6FD0549ULL, 
            0x48FBA91963A607CCULL, 0xBDEE2CE4375AB9E8ULL, 0xB1443BA3B8214483ULL, 0x7191FD14D61B1234ULL, 
            0xE846538A27672A50ULL, 0xADFFEA1CE358A1F0ULL, 0x5B065439D8D15C27ULL, 0xACCC2473EE72189AULL, 
            0x800BF99F0292CB28ULL, 0xC0E5C05E23F64631ULL, 0xC6A0949E80D40DDBULL, 0x800F6C6B5E82AE81ULL
        },
        {
            0xDA76A4BB92FB2C6EULL, 0x28C30B14B4C6DF1EULL, 0xAE19D4308E465DE8ULL, 0x7CBBA0D5A7BEC081ULL, 
            0x93C5A134D4DA159AULL, 0x39CBB52616C91C5DULL, 0x1A4BEF6E3F84C1A8ULL, 0xE94083BA81ABED9AULL, 
            0xA18DFE4A68C53017ULL, 0x9A01B40A36623350ULL, 0x17E114A9DB1BA252ULL, 0x96D5025A70702024ULL, 
            0x5C39898C79F3094FULL, 0xC91AE1BE91B13BE1ULL, 0xF17EA314D9EF94CBULL, 0xD55BF6F997EAB8B1ULL, 
            0x1CF8F72E7445D054ULL, 0xF5547716D0448773ULL, 0xCA245BCBE1A53313ULL, 0x2E77F97AF5F5C042ULL, 
            0xF256642E698F0483ULL, 0xB62D34429B264984ULL, 0x15983A94DC5B3C82ULL, 0x51EBD3498539AAFBULL, 
            0x07083206825D4A6AULL, 0x83B0520F3D27DC9AULL, 0x672B5073BBB69D6DULL, 0x9D9E19918843CDC2ULL, 
            0x291FDC5BF2851347ULL, 0x781BF97648654AC2ULL, 0xDA64DA3AAD597B7BULL, 0xBC9B30A816E5851BULL
        },
        {
            0xCE2861C55054170AULL, 0x707BEDB82A86C9BAULL, 0x87EB28672E72F439ULL, 0xE1955F5FFD921D5BULL, 
            0x0CE40627A3666957ULL, 0x7C9AA7E9E02AB2A2ULL, 0x4C049055AA1D7535ULL, 0x881B34EF3A87FB17ULL, 
            0x16854974C7026D9BULL, 0xA96EE0BB3D571D12ULL, 0x980060EBEA643481ULL, 0xC44E0622A8B5CA37ULL, 
            0xBE2B35FFE1853F46ULL, 0x1A98801B0F3E79A1ULL, 0x206DB9BB497917EEULL, 0x4616DA6E3713DE83ULL, 
            0xF81461AC237F2481ULL, 0x39928AB35C2D47D6ULL, 0xCFDD68A55C4E1463ULL, 0x75C1F69EB2A80F68ULL, 
            0x958300640833ED81ULL, 0xB04439B0ADFBCAEFULL, 0xB76673D6C99B0429ULL, 0xEE2BCC1922945026ULL, 
            0x0C3E6B1F3A178B34ULL, 0x4DD53E96C58B0F64ULL, 0x69396B05126F6F46ULL, 0xBAF392C77C8DCE7CULL, 
            0x002A1AFC20FAE8D6ULL, 0xF1263CCB722CA452ULL, 0x599669E9C1C11CC9ULL, 0x7FFE1DE063F08404ULL
        },
        {
            0xC12164783EF9100CULL, 0xFA246298067189E0ULL, 0xDC392ACF20E5CE69ULL, 0x82EBDDB097470642ULL, 
            0x1613D211D448CFB5ULL, 0x3FFE88726DADAC74ULL, 0x09A52D73C95D59B6ULL, 0xE42F881A1C5ECC31ULL, 
            0x6C38691DDFD40EBAULL, 0xBA6AC4FB15254835ULL, 0xBAA68B003B613638ULL, 0xCE28EB8B964F7E50ULL, 
            0xCA4FCD9DAD8D258BULL, 0x2197A09F827B0C9FULL, 0xFB0A7AC72D92CF63ULL, 0xE77953097CF2099BULL, 
            0xC6F17A025CE9DB35ULL, 0x919705B5AFAEFC38ULL, 0x0B0F019A3D01F8DEULL, 0xBA0473E6EE57B58DULL, 
            0x175F3CF81A09DE86ULL, 0xE8DAA91AABF79E99ULL, 0xF0D9E0654998DFE6ULL, 0xD2BF00AE8FADA78BULL, 
            0xB139EFF215D05A1EULL, 0xFDE41994980BF151ULL, 0xEE44C496A11210A8ULL, 0x17A34DA1BB68FD09ULL, 
            0x804B3AB177DC5892ULL, 0x118FFFBCE314DC75ULL, 0x26ED7709866164C8ULL, 0x04CFF896CF0D9BACULL
        },
        {
            0x064F3CF7EAB455D2ULL, 0x4EFED2DF32149A42ULL, 0xD3D24C9FAEB94FEAULL, 0x08307EF96BFC82C1ULL, 
            0x4ED5D6138BA74661ULL, 0xA9DBE1563F05AF7CULL, 0x5FFCD1929A9E8E86ULL, 0x5986FEE5051DEAF9ULL, 
            0x834857BF2C2F60DDULL, 0xB6E0FFF420628CA0ULL, 0x089443C5E32397C1ULL, 0x81CA803A61D11536ULL, 
            0x7FE39E91D9507CCCULL, 0xAF270C11485E68D4ULL, 0x7D59828AF30EFE41ULL, 0x343905B8C53DD0EDULL, 
            0x55E36E1D5BA45371ULL, 0x1F314F5BDB56E508ULL, 0x943D250A2C978713ULL, 0x4B56358E82DBACEFULL, 
            0x4F61C9CF772025DBULL, 0x22B2EC141DEDE514ULL, 0xAFBC31AA1FF5F667ULL, 0xD6E2B72AB9E8D33AULL, 
            0x10CC588FC6DF7DA1ULL, 0x46441761B6DC190BULL, 0xCDEA8C10A0AA4D1FULL, 0x5C405F1DFCA29796ULL, 
            0x0830936454AD3C2CULL, 0xC40544A890E168ECULL, 0xCCC24C31FBBB0918ULL, 0xBD012A86531BDCAAULL
        },
        {
            0xA80744CAFEBE6680ULL, 0x15E43AB1023A6EF7ULL, 0xB34D9A3A1501D018ULL, 0x77AEB37966CDC67AULL, 
            0xD31E6EE4E922D7B5ULL, 0x113C165DA8B5A1BCULL, 0xA37B5999635B7387ULL, 0x56D61953FF16C056ULL, 
            0xA4F530CF6A7C21A7ULL, 0x807C12F4B2B766DBULL, 0x581276B776A120B7ULL, 0xD000988A382C1D50ULL, 
            0xFD89DC3BD588E421ULL, 0xBB12E1C62D27C879ULL, 0x36D7840E70189A93ULL, 0xE164BE78CBF38E61ULL, 
            0x644150D4E65886E8ULL, 0x5B9C12DA49D758CBULL, 0x73E8EED51A77AF48ULL, 0x43CC5F2519A0B443ULL, 
            0x0D0F5B7485A88144ULL, 0x60FBFE62B631F5B3ULL, 0x8DD5200BEC765BF4ULL, 0x0693F5A344046647ULL, 
            0x06A6A080443070D6ULL, 0x443AF8D3CBA029DFULL, 0xAF069B0553713606ULL, 0x6C6E4D8CA7D9909AULL, 
            0x6A05110FB10BB576ULL, 0x9EB411D38CBF93EEULL, 0x2A1FB15CFBAD4094ULL, 0xDF9D19AE5EE597D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseHConstants = {
    0x258F35B6DD0A6715ULL,
    0x7A0A79C0707AFF4FULL,
    0xF29C73D45E41510DULL,
    0x258F35B6DD0A6715ULL,
    0x7A0A79C0707AFF4FULL,
    0xF29C73D45E41510DULL,
    0xD68BB11196697D03ULL,
    0x80DC6BDAFBFCA90CULL,
    0x10,
    0x4C,
    0xD3,
    0x24,
    0x35,
    0x23,
    0x71,
    0x93
};

