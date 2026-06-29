#include "TwistExpander_Lacrosse.hpp"
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

TwistExpander_Lacrosse::TwistExpander_Lacrosse()
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
    std::memcpy(&mDomainBundleEphemeral, &mDomainBundleInbuilt, sizeof(mDomainBundleEphemeral));
}

void TwistExpander_Lacrosse::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xC75EB03FCC798E5DULL; std::uint64_t aIngress = 0xF7A2141FC178E2C6ULL; std::uint64_t aCarry = 0xF8A9C9FC084AE367ULL;

    std::uint64_t aWandererA = 0xB7C2606AA4D569F4ULL; std::uint64_t aWandererB = 0x96E13A0BB09CD7F9ULL; std::uint64_t aWandererC = 0xA2B4485369C83FC4ULL; std::uint64_t aWandererD = 0xB124E039879B5529ULL;
    std::uint64_t aWandererE = 0xEEDB080DD26A2854ULL; std::uint64_t aWandererF = 0xAEDE1D59E7252442ULL; std::uint64_t aWandererG = 0x97E896FD59FBDAA9ULL; std::uint64_t aWandererH = 0xF0ADE0E2E2A70E5EULL;
    std::uint64_t aWandererI = 0x9AB2460676F1FCC1ULL; std::uint64_t aWandererJ = 0xE730532DA01AF238ULL; std::uint64_t aWandererK = 0xFD45ABC92FACA9D3ULL;

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
        aPrevious = 9821214178894028902U;
        aCarry = 9406739227183706395U;
        aWandererA = 18409261233390145013U;
        aWandererB = 12599535908895877192U;
        aWandererC = 14688966221476252601U;
        aWandererD = 14816217541552389874U;
        aWandererE = 15004105042767055796U;
        aWandererF = 14136046259456583239U;
        aWandererG = 13458614678193865730U;
        aWandererH = 13256662237009798589U;
        aWandererI = 17259246154969273001U;
        aWandererJ = 16324027194714024557U;
        aWandererK = 10868537474792245467U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: work_a, work_b, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_A_A(pWorkSpace,
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_A_B(pWorkSpace,
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_A_C(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
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
    // KDF_A_D kdf_a_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Lacrosse::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
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
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x8F1B97D65D6E5629ULL; std::uint64_t aIngress = 0x86A843B5855965D7ULL; std::uint64_t aCarry = 0xD1AD146F4FDFD41EULL;

    std::uint64_t aWandererA = 0xC96D941C967E05D3ULL; std::uint64_t aWandererB = 0x8156037F4EEDE008ULL; std::uint64_t aWandererC = 0xEC6F32E4BB90E260ULL; std::uint64_t aWandererD = 0xA27EEC9578A21393ULL;
    std::uint64_t aWandererE = 0xAE3780FF59DF67DBULL; std::uint64_t aWandererF = 0xFA3458344635AA47ULL; std::uint64_t aWandererG = 0xCEC956636ECBB4E1ULL; std::uint64_t aWandererH = 0x8AC0778EDCA1FFB1ULL;
    std::uint64_t aWandererI = 0xB61F7FF5D573C783ULL; std::uint64_t aWandererJ = 0xAF8B31D1A7205D33ULL; std::uint64_t aWandererK = 0xE6C914A1BD666110ULL;

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
        aPrevious = 13106156704924248137U;
        aCarry = 16824761443325352846U;
        aWandererA = 13609479974579108470U;
        aWandererB = 9658091355532325580U;
        aWandererC = 12002395806263345302U;
        aWandererD = 11065972471051243839U;
        aWandererE = 16390226721542777035U;
        aWandererF = 17838807450519076513U;
        aWandererG = 11105646408994011632U;
        aWandererH = 17745950734156069247U;
        aWandererI = 12623362358048729422U;
        aWandererJ = 17570705242820582879U;
        aWandererK = 14717476251560754742U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_B_A(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_B_B(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_B_C(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Lacrosse::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0x90A69AC6921DDA47ULL;
    std::uint64_t aIngress = 0x9CAF50DA967ADD0DULL;
    std::uint64_t aCarry = 0xADDCCA0D067B9388ULL;

    std::uint64_t aWandererA = 0xF5101949C090DB94ULL;
    std::uint64_t aWandererB = 0xF5A438E8B33F816CULL;
    std::uint64_t aWandererC = 0xE872A5DB5E20934CULL;
    std::uint64_t aWandererD = 0xC3C81FD92E302E9CULL;
    std::uint64_t aWandererE = 0x826302DD7C472078ULL;
    std::uint64_t aWandererF = 0xE4978C053F177694ULL;
    std::uint64_t aWandererG = 0x94B91CBD608A711FULL;
    std::uint64_t aWandererH = 0xAD597BC47188054BULL;
    std::uint64_t aWandererI = 0x9E4361A2640B9060ULL;
    std::uint64_t aWandererJ = 0xECE07A119FC11AAEULL;
    std::uint64_t aWandererK = 0xF26406929D17CF45ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB, 0);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    // temp storage: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_A(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_B(pWorkSpace,
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
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
    // GSeedRunSeed_D seed_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_D(pWorkSpace,
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
    // GSeedRunSeed_E seed_loop_e:
    // ---------------------------------------------------
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_E(pWorkSpace,
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
    // GSeedRunSeed_F seed_loop_f:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_F(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aSnowLaneA, aSnowLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
                         aSnowLaneC, aSnowLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_h:
    // ---------------------------------------------------
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Seed_G(pWorkSpace,
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

        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::GROW_A(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Lacrosse::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Lacrosse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x89394D6A912A6C47ULL; std::uint64_t aIngress = 0xB5CACF0ACB8E995FULL; std::uint64_t aCarry = 0xFC08B1BEC869393CULL;

    std::uint64_t aWandererA = 0xAC86A1B1209CC78BULL; std::uint64_t aWandererB = 0xBCFBB54B579C8FADULL; std::uint64_t aWandererC = 0xB3C33582FD6DB924ULL; std::uint64_t aWandererD = 0xA4FC5773A94D624DULL;
    std::uint64_t aWandererE = 0xC1FB1D4118CA967DULL; std::uint64_t aWandererF = 0x953FD26BDFB00C32ULL; std::uint64_t aWandererG = 0xA1934FAC55496300ULL; std::uint64_t aWandererH = 0xE83955ED29F8930AULL;
    std::uint64_t aWandererI = 0xA80F83C240B78242ULL; std::uint64_t aWandererJ = 0x948D8C872D03EA4CULL; std::uint64_t aWandererK = 0xD3A17F9D0CA8E44DULL;

    // [seed]
    {
        aPrevious = 14853878453798620930U;
        aCarry = 10668482081363515437U;
        aWandererA = 13347995475079307548U;
        aWandererB = 18377886965120953893U;
        aWandererC = 15840122809222801366U;
        aWandererD = 18006599986730203770U;
        aWandererE = 11492280247648956114U;
        aWandererF = 15298478096819313392U;
        aWandererG = 9795445109350819236U;
        aWandererH = 11535941469756641642U;
        aWandererI = 12283361308369550785U;
        aWandererJ = 14617571588341191297U;
        aWandererK = 15465501220584562740U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Twist_A(pWorkSpace,
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Twist_B(pWorkSpace,
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Lacrosse_Arx::Twist_C(pWorkSpace,
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
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        //
        // ---------------------------------------------------
        // GROW_A grow_key_a:
        // ---------------------------------------------------
        // read from: work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        // write to: expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_Lacrosse_Arx::GROW_A(pWorkSpace,
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
        // ---------------------------------------------------
        // write to: work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        //
        TwistExpander_Lacrosse_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Lacrosse::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyA(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
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
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);

    // [grow key a]
    // GKeyFoldA grow_key_a_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldA expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 2, 3 with offsets 2260U, 4961U, 711U, 7150U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2260U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4961U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 711U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7150U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 1 with offsets 3576U, 5449U, 594U, 4968U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3576U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5449U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 594U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4968U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 2 with offsets 634U, 730U, 6536U, 1787U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 634U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 730U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6536U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1787U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 0 with offsets 7398U, 3091U, 1376U, 1532U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7398U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3091U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1532U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 766U, 258U, 861U, 1244U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 766U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 258U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 861U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1244U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 3, 0 with offsets 291U, 553U, 146U, 1777U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 291U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 553U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 146U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1777U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 0, 2 with offsets 869U, 1004U, 651U, 1077U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 869U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1004U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 651U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1077U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 1, 0, 3 with offsets 2026U, 266U, 514U, 20U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2026U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 266U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 514U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 20U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 2031U, 74U, 1156U, 1768U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2031U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 74U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1156U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1768U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Lacrosse::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);

    // [grow key b]
    // GKeyFoldB grow_key_b_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldB expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 6161U, 4122U, 7184U, 7332U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6161U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4122U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7184U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7332U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 3 with offsets 8080U, 1370U, 8136U, 3948U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8080U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1370U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8136U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3948U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 1 with offsets 460U, 6017U, 5759U, 3441U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 460U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6017U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5759U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3441U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 1, 0 with offsets 6716U, 4170U, 7270U, 1044U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6716U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4170U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7270U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1044U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3319U, 1346U, 6180U, 4302U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3319U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1346U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6180U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4302U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1432U, 418U, 152U, 867U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1432U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 418U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 152U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 867U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 725U, 36U, 301U, 1509U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 725U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 36U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 301U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1509U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1058U, 695U, 1980U, 389U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1058U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 695U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1980U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 389U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 303U, 194U, 114U, 1685U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 303U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 194U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 114U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1685U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 [0..<W_KEY]
        // offsets: 974U, 1314U, 443U, 1396U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 974U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1314U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1396U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseASalts = {
    {
        {
            0x73F99A770629B63BULL, 0xBC331EF24ABDD9D8ULL, 0xFE062E62537DBC35ULL, 0x7CE1037B5B32ECADULL, 
            0xFA21046E20647643ULL, 0x86E970608B64F106ULL, 0x84117E61AADB221CULL, 0x79F2B72BB017646AULL, 
            0x8E99EED44339EDD5ULL, 0x8835DCD493BC5663ULL, 0xA2D5F634C6384EDCULL, 0x455088557AE750D1ULL, 
            0xF90C52DEF6C38FF7ULL, 0xA7E28CF5CCFE4286ULL, 0x9128ADB7B41C5823ULL, 0x531488B27E4E29BFULL, 
            0x78BB9BD21C009CBAULL, 0x26DC0614D7FB322DULL, 0x33B98AAC6DDA7A9FULL, 0xA39E3904B0BCC7EDULL, 
            0xE4AC079FB25CB2F5ULL, 0xE0BF1A759F9A0669ULL, 0xA4E408229494329BULL, 0xF801828307C7A8BDULL, 
            0xCDB751157CF136BFULL, 0xDBF25571BE4C4F75ULL, 0x86C79C5EE4CBAB14ULL, 0x770036532995B823ULL, 
            0x808A413D383660C0ULL, 0x0AFF0483DC93F48EULL, 0x4C0B34605B49FDF4ULL, 0x55CA7B89BF96D115ULL
        },
        {
            0x6F931EDE0BCB3CF8ULL, 0xC513C6AC228A999EULL, 0x1B4006AAFFB71D76ULL, 0x317F23E8D3A6915FULL, 
            0xE55B9D0300E8DF4CULL, 0x46815D7830705AD5ULL, 0xC05B10E229B697EFULL, 0x733610ED20600949ULL, 
            0x60FD0F71B6B770A9ULL, 0xF3FD66D17D1A7831ULL, 0x15322EEC36BCFCB1ULL, 0xF310D292B1ABFB1BULL, 
            0xBDA927AFD4815568ULL, 0x6D09D87140E8EFBEULL, 0xB21E17A8B182F362ULL, 0xE69242550C640B54ULL, 
            0x3CA2C80A41A74890ULL, 0xBFAC58A57C775D1DULL, 0xB9FC38D4F0DF6E2EULL, 0x0FD0045C5A027812ULL, 
            0xFA9246595B288B06ULL, 0x08F18D5C4C9ACB0DULL, 0x876B7307A4B771BEULL, 0x9D30364719A509E1ULL, 
            0xF704FEA81A6A2489ULL, 0xC3595651152B31E4ULL, 0x405DD4AA31429697ULL, 0x61990A32F5DBD418ULL, 
            0x81C9DE3A32B4B6D0ULL, 0x23DA4ECE1BEB57F0ULL, 0x6E574398DCF49CEDULL, 0x19CB31F761D16EA8ULL
        },
        {
            0x77D0EBCDB108B221ULL, 0xC32366CB69C4692DULL, 0xE154BEDA61D833E1ULL, 0x911951D6FF1488A9ULL, 
            0x00954D5E8635C49EULL, 0x14D4D12D3927103EULL, 0xB5A71D96914CCF9AULL, 0x73BFD49791F0CBBFULL, 
            0x73D5669A5E12415AULL, 0x97416BE554848E1FULL, 0x4F2203F8C4D8301BULL, 0x0A58DAD5FB59B2D4ULL, 
            0x8795671B07B05D5DULL, 0x53EF70C946787C83ULL, 0xC3F37267466E5847ULL, 0x3A76ACAD60579B8CULL, 
            0xB6DBC2E499381F09ULL, 0xABFD931C7B14AB1FULL, 0xA7B3711677532869ULL, 0xAB87461BC719585EULL, 
            0xB314B51004F7F2DEULL, 0x23317E2D4DC36AFFULL, 0x49C88EF6D890DDE1ULL, 0xE3DBDF679BD177E8ULL, 
            0x6324A18422E6AAB6ULL, 0xBD25B3EFD19429B8ULL, 0x950BF975FF82B458ULL, 0x3034299E60750AF0ULL, 
            0x393D00479731CD94ULL, 0x9BAB5CC11EFEB9E3ULL, 0x9243D87844A86B7BULL, 0x5FF9D4D07F491600ULL
        },
        {
            0xC78EA72193EDA860ULL, 0xE1052E3577A6FABAULL, 0x90AE10E398CD327BULL, 0x5D312BB9DD1AED80ULL, 
            0x1B521331CB7C68C6ULL, 0xA61EA5E5BFFD12B6ULL, 0xD197120F9A47AEA1ULL, 0x23B4BC470A7C70B2ULL, 
            0x05FF593C8920D3C7ULL, 0x0C1B45DCDBE42B82ULL, 0x667F01C46935FCC4ULL, 0x6C344B736C9E7B2BULL, 
            0x03006156B450308EULL, 0xF5F0724B366AA35DULL, 0x5611544945DAFE47ULL, 0x0530644191235F65ULL, 
            0xAE29032E7D1AE777ULL, 0x0F6961BE6047A50AULL, 0x5E567B2BEF607E92ULL, 0x2A809E179DD63271ULL, 
            0xF2E57960F9881390ULL, 0x9B6F02B3010A8501ULL, 0xCED56D1B1F749AC6ULL, 0xED9691669C5D54AAULL, 
            0xAFDC5A6D175C812AULL, 0x2140BC54488542D2ULL, 0x041A7051B2C7A17FULL, 0x37A8A197B00B6D42ULL, 
            0x769417E77A6B8A7CULL, 0xBB5C72AB7467F5B6ULL, 0x08BFDED4EE45DC0DULL, 0x6D83E5E5BDE923CFULL
        },
        {
            0x096A14DD1C685FA8ULL, 0x2915C9EDCEA87F77ULL, 0x26B55B391FF70E09ULL, 0xC800045662D74D6AULL, 
            0xB18BE9439F5DA400ULL, 0x3D6E7E68ABFBE3CCULL, 0x8C1BC07D255FD4EDULL, 0xC28EA3E31B256910ULL, 
            0x61FC6D6765B39CA5ULL, 0xFCD37C4BDD2F349CULL, 0x14D326926313B018ULL, 0x05BB1FEF19E9D37DULL, 
            0xC1650CDF2BA7958FULL, 0x6BA9604A26FCF6EFULL, 0x8F6F79AEF70F223AULL, 0xC46D1A7487BED354ULL, 
            0x632D7B8624D599CBULL, 0xF5A0AD979896DB2DULL, 0xCB6798AC813A0A04ULL, 0x7A34AF1E34D2575BULL, 
            0x95904AD8C66202BAULL, 0xDF4C99094BEBF46FULL, 0xC9E34F48856A854FULL, 0x1D14BAC3FC24CF43ULL, 
            0xB165221DB93B357AULL, 0xC3B91B3E7F0C3D8FULL, 0x3C9BCD53B4F1EDF8ULL, 0xF86096A205C715E3ULL, 
            0x8F435952A663C461ULL, 0x6595128AF57C1EA6ULL, 0x21CA0D61AD1863BFULL, 0x1C2EAA6C134363CCULL
        },
        {
            0xEAEDA2FE3A95DBFAULL, 0xD64CCDCD0C9E8B31ULL, 0xCE4CE22C5F51BA2DULL, 0xF8B032F04F03BEC1ULL, 
            0x82B7ECCB0F16A4A6ULL, 0x739669040D498312ULL, 0x91F7286F4B7947F9ULL, 0xBB694A798D789929ULL, 
            0x92F620014C3BFCDCULL, 0x027A341F8356281DULL, 0xD265F927B42B70B0ULL, 0xE1854F3059B767EFULL, 
            0x133A570F32AB267DULL, 0x3F8AA3C41C9B6352ULL, 0x942C00EC425F2711ULL, 0xE4DC3A255A97695BULL, 
            0xB7A1EFCBC46F93ACULL, 0x8B5A5ECF9DC9B419ULL, 0x5C8ED4A9B67EF943ULL, 0x11732AF981C1A46AULL, 
            0x1C70E5A7D6BB0CDAULL, 0xBF96A2E5263804C1ULL, 0x8EFF599C4F617E83ULL, 0x7E8660FB5E6A16A6ULL, 
            0xE68EAF9F7A37B485ULL, 0xA7CFCD28F62B96B8ULL, 0xB3A3A110213F3422ULL, 0x3DB2846AB53B48C0ULL, 
            0xDC10060B45CBADF7ULL, 0xABB6E1B0EE313747ULL, 0xCB1E8E0A568F1286ULL, 0x23EE372DA0F9D206ULL
        }
    },
    {
        {
            0xEEC9FF514271D9A4ULL, 0x62F367313E006E65ULL, 0xDBE2FEAC761F77E6ULL, 0x0B1E102E7299CAAFULL, 
            0xE52F038676F26E49ULL, 0x2222C02779DA4A32ULL, 0x576B899BB2A3B767ULL, 0x31150D12AA52C2EAULL, 
            0xE7D7AC2DA82D15E1ULL, 0x87D9F1E45511A4B8ULL, 0x6CFE81BDFF6A9612ULL, 0xF4D43631080A9E15ULL, 
            0xEAD11A709B0272ADULL, 0x5667EED026D2572DULL, 0x7F77E20EE17160CFULL, 0xD1D5D3EBD64AA096ULL, 
            0x327BD3D1A51E1247ULL, 0x8D3B37CFDB5F82F9ULL, 0xA31FD5EC9C0646C0ULL, 0x23DF9B31D6E4FD6DULL, 
            0x717B3812402E9591ULL, 0x77185E99EFDC0D32ULL, 0x29B990FAD0288268ULL, 0x5D46DC28FECFD682ULL, 
            0x099E4606B590FA0FULL, 0xF4270652C47DD9AEULL, 0xB10EE40B16902A9AULL, 0x7B9F9310CD412CCAULL, 
            0x59889231398E85B8ULL, 0xA6CCF59950E5D04DULL, 0xDF6FAB930AB2F96FULL, 0x5A571A3D264BCE68ULL
        },
        {
            0x4F3529786BA90439ULL, 0x3ACEBEF534692E89ULL, 0xBD476A05EB9E5685ULL, 0x80B6B966260D298DULL, 
            0xB5B83CC599933D28ULL, 0x66564FA2AEF489CCULL, 0x9B7A204C0646AA8BULL, 0x2FCFDB97D5F8F77DULL, 
            0xD4930B314EBDEC51ULL, 0x6C6395FA3AD2C74AULL, 0x2CB896A243848B43ULL, 0xC36F81FDDADF7F60ULL, 
            0x0C972B5EA49C8209ULL, 0xC4191F937B54B9AFULL, 0x33D4ADA9C3DF9853ULL, 0x5613A43C5E81A6D3ULL, 
            0x42A64912FE914484ULL, 0x09D88A24B2A65233ULL, 0xCB5B161A5DA7F7DFULL, 0x36B0600CFDDED44BULL, 
            0x3FD0BC3162ED9018ULL, 0x8ED33B3CC6FCF275ULL, 0x4F5A2B2F36AD84D2ULL, 0xB7AF567C32F24F77ULL, 
            0x15FC7379F007704AULL, 0xAFDD5DE09464631BULL, 0xA89DCDBC66228259ULL, 0x6940EEDBA4C59916ULL, 
            0x0545FD56A07BB8A7ULL, 0x9A1465646A6DF094ULL, 0x1682517A9C4DA7D5ULL, 0x1905427B44897CFEULL
        },
        {
            0x87922833C8D8A147ULL, 0x9334D78DD7639125ULL, 0x4FBE58B245C88AC1ULL, 0x1ABC964AD915107FULL, 
            0xEE9C7B82D865D11CULL, 0xC3668FFD5172FA7DULL, 0x4D4C95F4372BC633ULL, 0xBD1E11F15533332EULL, 
            0x4B896ECC745937E3ULL, 0x45B2EA6376107370ULL, 0xC0EAF91C461D1337ULL, 0xAEB9B494102A575EULL, 
            0xF53AAEAD41B17EAEULL, 0xDB9BE8C2C81FE0DAULL, 0x5EFC80EFC059D7C7ULL, 0xA63B3E5EE7AE45C2ULL, 
            0xCEB68366B01FEB15ULL, 0x33748F76F7B43761ULL, 0xB53D8CCAEBC98064ULL, 0x095331510B99E4EEULL, 
            0x58B06D9D89610A28ULL, 0xFE870EDD918217BFULL, 0x578A222645BB7A9AULL, 0x9A30907E6C618704ULL, 
            0x0C4B31050A9657C6ULL, 0x4AC64D8A184E7961ULL, 0x2DFA424FE08DCBA7ULL, 0x50282489A0A9A757ULL, 
            0xF4C24190334B730DULL, 0x551972AF89E9D83AULL, 0x2F8C8C91379EFE6CULL, 0xFA9D9B418E80E78DULL
        },
        {
            0xA30C2846228A615AULL, 0xFF8A5397436C3D89ULL, 0x005E74F0174F1129ULL, 0xF06B2C5F425220BBULL, 
            0xCEFFD51133A8D539ULL, 0x41C721DEBAC67B68ULL, 0xD224B76B557CF396ULL, 0x2C28EF9C03E8393DULL, 
            0x9FFEF6444B548714ULL, 0x35D1F21A43D98585ULL, 0x52D020F9DA102094ULL, 0x624AD8EA8F9C6651ULL, 
            0x4FDC6D6DAB11106AULL, 0xFCCC5BA7105F7465ULL, 0x4ED2CC4C682FDF83ULL, 0x92D66A33AD827110ULL, 
            0x3ABBB19027046FF9ULL, 0xD732171EFCAA9C6CULL, 0xA89A4321EF631201ULL, 0xF81DE9E909FB9F25ULL, 
            0xECDB322787DB8E8BULL, 0xB9727FE1D4E53EE5ULL, 0xB6DDD9E93671FE97ULL, 0x7359054BDB031880ULL, 
            0x77064C7D5E364DBFULL, 0xF67FBC48EE64B599ULL, 0xCF98673FB3255981ULL, 0xEDD64435D9D9C7D6ULL, 
            0x89485B273F079792ULL, 0x13F20B83E08A6797ULL, 0xFF676766A038906BULL, 0x083FB384DB2D340BULL
        },
        {
            0x2ECB425FCB83725FULL, 0x9CCAC625EC961AD1ULL, 0xE33D0A479376DEFAULL, 0x69C42C3C4325C5C7ULL, 
            0x5D426A022787CD10ULL, 0xC27BEBDEF81BCE4FULL, 0x19FA25034DFCC3B0ULL, 0xA7AE7001A90DE668ULL, 
            0x1AD453270AF065E5ULL, 0x2923EB5AEE3F266FULL, 0x4AECF76DAFC5FC42ULL, 0xA94B6ED33739C721ULL, 
            0x302F47B34D369825ULL, 0x77EE5677AE3364E4ULL, 0xB1181CEB90F5BEDCULL, 0x7F8D9749BAD146E6ULL, 
            0xEA8AA32BA533344BULL, 0x15E5B3A65AF8024FULL, 0x7654AE21C35381C8ULL, 0xBA4351A37862F58EULL, 
            0xDA9BA9CC5CFE732FULL, 0x770A59D924D7C6F3ULL, 0xAE4B76FB287D238DULL, 0x59E316EDB8E4C795ULL, 
            0x79CB7BFA82914BF8ULL, 0xC0708FEDBAA76F54ULL, 0x85C4A44DA7BF63C9ULL, 0x917A33C559A5B03FULL, 
            0x59453E8A6231A9D5ULL, 0xD5A284B6AA38EC89ULL, 0x683DCD47B70993C6ULL, 0xD99AFADBF327DC3FULL
        },
        {
            0x8FD00D98D9929508ULL, 0x4DA56D4987ECEAEBULL, 0x6F928673EBBB91FDULL, 0x4BED08A6A2EE5D76ULL, 
            0xC7404E338411C58FULL, 0x5984323C75B77EA3ULL, 0x670F607210A612ABULL, 0x8A3AE6A99B80DCF3ULL, 
            0xDDA00B381C8DE83FULL, 0x720DF699CEFBDFE7ULL, 0xA664B3D6DA780F3CULL, 0xAF7A0E4600C41423ULL, 
            0xD760A428F5915B8EULL, 0x4C11A70292C29B9AULL, 0xA15E210240717730ULL, 0x42CD2A9155CDFE87ULL, 
            0xD87A7801CDD7663EULL, 0x93D140BF97074FE8ULL, 0x86A03544371430E4ULL, 0x22541FB7CE3262B0ULL, 
            0x71F0E60AACD11E8CULL, 0x14C7C2FB86F77A9BULL, 0xE8E493728646C045ULL, 0xF3DA27034AA9C011ULL, 
            0x7E96E734E5519BE9ULL, 0xA7361CD561855CBAULL, 0xD158C71F080F1ADFULL, 0x8B620B33B89B0F41ULL, 
            0xD986CD99E7EFAA4EULL, 0x8EAF7A12A9BC0CFAULL, 0x9D9230B19B5EAA83ULL, 0x9ED6C5FF322B26D4ULL
        }
    },
    {
        {
            0x45FBB8983E99B527ULL, 0x08E3481224FE3D5FULL, 0x016D234393D0228DULL, 0x8C4495C3B21BAF95ULL, 
            0xF11347F1818D372EULL, 0x00FC9CE8B240047DULL, 0x06F2B81890AA599FULL, 0x6585BE8F3562AF62ULL, 
            0x20D6D22CD307AB88ULL, 0xCBE5DA9DD642B801ULL, 0xCCAFE186525C8A2FULL, 0x65D7E8E6A5564B20ULL, 
            0xD9D059A0E146695EULL, 0xE14C6D151BA9BB46ULL, 0x2E3F125ECE214F0AULL, 0x5C1DCA9C7BA007C7ULL, 
            0x81C2D9EC8D050BB3ULL, 0x0BDB9EEAD53290CCULL, 0x3CE39209F9C42FEAULL, 0x78D94CD04D775E84ULL, 
            0x97F18358A7EE5582ULL, 0xBB3A2458EB8A05FAULL, 0x45F6AFA3D16CAD42ULL, 0x8D4E6C6996EB69E0ULL, 
            0xAFC73672E8DB5A19ULL, 0xB02CAF69FDF1C7BDULL, 0x0CC26DE0DFE8348AULL, 0xFF9A5E5102495EF6ULL, 
            0x90CC8395788E9B1AULL, 0x6CD9BE981D9D118AULL, 0x114EBBC800E94322ULL, 0xD31DF6C1B92085C5ULL
        },
        {
            0xC93DDA770C93EC91ULL, 0x5BAF3F1752D806D1ULL, 0xC8956F8385D0F467ULL, 0xEC5BE1CCFA5FAB28ULL, 
            0x4091484695605140ULL, 0xFF4BBCBD1CE410C1ULL, 0x9824D8F3C028E70CULL, 0x8A9D69869115E3BDULL, 
            0xC4E3FF905D765EB3ULL, 0x8ABAB8B30383F8DEULL, 0x61BF8B412F59F0C2ULL, 0x1D9B3644B001CD58ULL, 
            0xE35D13126F33E6CFULL, 0xC27120FDC7AF20C1ULL, 0x6DC657D8BEDE0F4DULL, 0xEB646DAB3088FA32ULL, 
            0x545AFF6A0F4BD3BCULL, 0xA2767C924CC91AB5ULL, 0xB25C577CF0422D28ULL, 0x925CF36AA5D5D680ULL, 
            0xD49D8CAE504F9FF4ULL, 0x8793DC04E0E3C9DDULL, 0x08D5CD7D5667DAC8ULL, 0x1F57E278E832BB8CULL, 
            0x4B263A9DDBE8BBB4ULL, 0xB554D19EEFC43940ULL, 0x9DD6E1E9515C6B3EULL, 0x574C62DFFCEBFE4CULL, 
            0x80A04469123F79D3ULL, 0x6C49009DC2AA15F1ULL, 0xEE82ABAFB23D566DULL, 0x48A183675A7406EDULL
        },
        {
            0x7CCDC4A7B9772F07ULL, 0x13BDFE80ADEB3BACULL, 0xD914B9CCD9CD9715ULL, 0x86CFF341EAC70AA3ULL, 
            0x8DF3295C711285AEULL, 0xE44AC112ACC4B617ULL, 0xCD2FEA997912F3DBULL, 0xEBDC056E58159DFAULL, 
            0x3FC6E8703A740A01ULL, 0xDCABF3845C450188ULL, 0xE3C75B6DE5510A52ULL, 0x230FF0CEB3E61E59ULL, 
            0x70E005CC87973D7FULL, 0x8AB156F85BB16101ULL, 0xFC07E16B61B8F908ULL, 0xEA4CB94F158ECEABULL, 
            0x06D96C3F37EDBF05ULL, 0x264A1B602624F24FULL, 0xE6872AEFCE4FA262ULL, 0x56CEB5EABCFFD17BULL, 
            0x65FBE80FD8C66EB2ULL, 0x31793492675C6924ULL, 0xD03D4DBBA7F71560ULL, 0x9D4B3BA4ACD261A0ULL, 
            0xB28F1A058EC84811ULL, 0xC722D2BF706EF538ULL, 0x60ABA4409ECA2849ULL, 0x516BCFF4B0750BA5ULL, 
            0x292B64A4779213EAULL, 0xAEB7430288085CC5ULL, 0x199E314DEA787A14ULL, 0xC3590D2A87C6BC7BULL
        },
        {
            0xE6FC243763BB2E06ULL, 0x73709DCC2A3798DDULL, 0x6DC80FA931E9A0F8ULL, 0xA128AB84983C3479ULL, 
            0xFDA6348FC1378EBAULL, 0x9F149733C01FAF60ULL, 0x033F8A5292F9CFB4ULL, 0x91CD218D6C6E44BEULL, 
            0xDDD06CBFF4D15E39ULL, 0xFB4B0AD5EF4EAAE7ULL, 0x98E7BE1545BBA638ULL, 0xBDF7E48CCF9C2BA3ULL, 
            0xD29B2A2B8110BBBDULL, 0xE09DEACD4501981AULL, 0x76ED6ACD3461CE55ULL, 0x5D6A32E66DF392F7ULL, 
            0x16C61031FAA995D0ULL, 0xA46FED74F16F0F77ULL, 0x0149C037871572D0ULL, 0x16BA9AC7A241E215ULL, 
            0xB898FE35110071BFULL, 0xCCAA6A9A109D9522ULL, 0x87321072A7C726BAULL, 0x8AEFF6C4B62C3563ULL, 
            0x88A767941388E2E9ULL, 0x4A932C51A9858AF0ULL, 0xE0531F14F3E7572BULL, 0x52F794B529CD4C02ULL, 
            0x63F336B480134B2EULL, 0x406BEED225008FD8ULL, 0x147134046D0F0237ULL, 0x2F97F0C9D92EC05DULL
        },
        {
            0x75D05A96945AC643ULL, 0xF5D4BA216884EB6FULL, 0xB7BE4502D7B775BDULL, 0xB564B5B897CB3491ULL, 
            0x527B61FE8340CB23ULL, 0xF83D2D89FFBBCC7FULL, 0x241208E3887490C9ULL, 0xA86D49C442CBE583ULL, 
            0x4052900DB9661C9DULL, 0x5CD43814CC168976ULL, 0xC39A5EE4D6F9718EULL, 0x28D2607E2B7D14D7ULL, 
            0x5FB725658D0A5D78ULL, 0x1898849A20C53EA3ULL, 0x4801EFEEE06AEACEULL, 0x4E2691C5E86075C0ULL, 
            0x7306EB762AB70924ULL, 0xB6F950E077A90D17ULL, 0xD452AE4697BC77BAULL, 0x7214BE742C4A04B1ULL, 
            0xB2200A547AF9436EULL, 0x8FC8D661AB76A07EULL, 0xEDCE4856FFEF2E1AULL, 0xC0432752E3E6040CULL, 
            0x7169227D70B4A429ULL, 0x400258ABF5686AC1ULL, 0xDC03DA4F55651016ULL, 0x8593C7A7EEE9F66DULL, 
            0x4BC9A4E60B7733D8ULL, 0x7ABF06388B7BD18AULL, 0xA81765CD97F56D3EULL, 0x326D4FEB4AE8AA0DULL
        },
        {
            0x80540402D098BC8FULL, 0x40C07004ABD073B2ULL, 0xF1B663BB4F490463ULL, 0x117F3DC19168B6FFULL, 
            0x17F303FAA0780B51ULL, 0xAD6A9FED7A9A57A6ULL, 0x67606612A0971CF1ULL, 0x27AFDCFEF6719B62ULL, 
            0x9D173F8581737A38ULL, 0xCA81D295C9EEF26EULL, 0x4286A648D5F96137ULL, 0xF12DBF2CA838C458ULL, 
            0x003BE8429AC8DD7FULL, 0xBC95589588625C22ULL, 0x59F15F6B18E7B090ULL, 0x66C9AA771EBA6C6FULL, 
            0xB95CFBECEA790D5FULL, 0xA6579E336100A719ULL, 0x2FAAE8F67F86C571ULL, 0x6C870C46755728EAULL, 
            0x2E3CADF5FA299F3CULL, 0x5BCC13ED45169ACBULL, 0xA57FA423ADF8E8DCULL, 0xDBB6F5A4530FA23FULL, 
            0x6E187ACA8FBD9A3FULL, 0x3F21578D012A5A09ULL, 0xDC18E1ADF3118D33ULL, 0x8914AA9D647EDC80ULL, 
            0xB0BBE6980D4D816AULL, 0x366F1E1A646EE777ULL, 0xDEE8D47832F2A873ULL, 0xD544D17F69750A10ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseAConstants = {
    0x0F8C374B68C264D3ULL,
    0x2042B09F751D6010ULL,
    0x65FDBD90A742C888ULL,
    0x0F8C374B68C264D3ULL,
    0x2042B09F751D6010ULL,
    0x65FDBD90A742C888ULL,
    0x114B42FFF623640CULL,
    0x863DAB62AFE685ECULL,
    0xA2,
    0x3F,
    0xEE,
    0x3D,
    0x0D,
    0xDF,
    0xA9,
    0x79
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseBSalts = {
    {
        {
            0x7393A67E6A4E5CC8ULL, 0x996C669137AA0717ULL, 0x3553CDA36A00538EULL, 0x00A3D632F57AF00FULL, 
            0x3710963B6EEB0787ULL, 0x3F2AD88EB9774C31ULL, 0x3951DA605923302EULL, 0x8A64A4D1AA8F46E3ULL, 
            0xEF0B85E2ADA4432DULL, 0xB226CCD34DC81F5CULL, 0x7D1A9B5E71A73DC7ULL, 0x5F1F73494CCE2235ULL, 
            0x2EB25D2C2FEF0E1EULL, 0x23DB54AD359C1038ULL, 0x1738B72D2C059EEDULL, 0x3B6A1561AD43157EULL, 
            0x0B79D100A7C64BDBULL, 0xE02565E957C9A846ULL, 0xD3D4C44308E125E7ULL, 0x51CCC904DF92A5AAULL, 
            0xC850DD4D4830644EULL, 0xD485F6C21D6CCCFDULL, 0xEA78E136C5DBFB86ULL, 0xD53794701302282FULL, 
            0xA8FC86E965B2C6CCULL, 0x95BB4C5D3965D017ULL, 0x57352DC264B77B0CULL, 0x976AC79602F69244ULL, 
            0x87C56662E7028D0BULL, 0x32B64F284CF79690ULL, 0x84FEC910AE866453ULL, 0x891F4BAAD77BD096ULL
        },
        {
            0x073863E16B9CCA15ULL, 0x0D171947FCC7AF15ULL, 0x4FDD6E54C52257D3ULL, 0x62820EBA8826B394ULL, 
            0x0B43A126AB9AB378ULL, 0x6C5E8E019B8C23E9ULL, 0x37F65D899EFD3D1EULL, 0xDE59B8F2770CD05CULL, 
            0x2BF912073EC3A635ULL, 0xBAED8D9977824B11ULL, 0x6971AD7C638F4C14ULL, 0x47AAC0784F87AAB0ULL, 
            0x2A462B491B520032ULL, 0x2CC8C7B82BB92648ULL, 0xFE1F6DAF25F48F17ULL, 0x51FF35F8CD526B26ULL, 
            0x74223A95E850D3AFULL, 0xEF9ECEA7A733499FULL, 0x14223062CFEE3659ULL, 0x2D9B6B959165227CULL, 
            0x935CBE6AFFE0E053ULL, 0xEBC92F23EB6CE4CBULL, 0x9CEFCA8912823D06ULL, 0xDA1B240C6205C2C2ULL, 
            0x01EFEC8816F3FF0BULL, 0x0D1A06422BE8767CULL, 0x671CF4CFF8092DA7ULL, 0xE3B64928B13E0129ULL, 
            0x400ACB741E8A6CEEULL, 0x94ACCBB03D9B5C78ULL, 0xDE3B34B811193D20ULL, 0x9D74058C37922E74ULL
        },
        {
            0xA08EC4789C241C49ULL, 0x57A91EA40A979C53ULL, 0x64D036108268CF3EULL, 0xFFE40E7F881E63CCULL, 
            0x044716973BD637A3ULL, 0x06A267650262DF5BULL, 0x5A724240DB3CD6DBULL, 0x8A37259B5D9064BBULL, 
            0x24BD2939E739DABEULL, 0x21EBD30717BFCFEFULL, 0xF69897E757721839ULL, 0x9CF85B094D5106A8ULL, 
            0x37FD42E674753E24ULL, 0x89C48FA382FF313AULL, 0x3E0A3798B4C9EC78ULL, 0x96B5364583B677AFULL, 
            0x630172162A16961AULL, 0x6E8D229C0472BCE5ULL, 0xCCE8E9859299E8FEULL, 0x8EFE014D1276039DULL, 
            0x1C74B2F4518FE9EAULL, 0x2D37DEB3361A009FULL, 0x68A4B1F95A411C32ULL, 0xA5963866BE68478BULL, 
            0x74957051AFC0A5E2ULL, 0x541F8E431497DAC3ULL, 0x88C28FE1FDE9CA95ULL, 0xBF687ECEF9B275A8ULL, 
            0x0DAB36A21B51286CULL, 0x9ABB3E5C710DFFA1ULL, 0x35315971CD6FE81FULL, 0x0A61B07A807EC365ULL
        },
        {
            0xD411162FA9BF26C6ULL, 0x097A568A371AB486ULL, 0x680487D3D679FBBBULL, 0x493AE20A7EB62FFAULL, 
            0x1DDC80C2F3A93801ULL, 0x25EA47DED1F0484CULL, 0x91018AEE2E50F3ABULL, 0xA02F6C44B708219BULL, 
            0x796BF6D2C9A60B9EULL, 0xF52FD8B2EB8C1F9BULL, 0x9B1C429EA49C0794ULL, 0xBE9FACAED8752547ULL, 
            0x6EF20E1E382E7D27ULL, 0xB595F982509EF6A0ULL, 0x8B8D11214DF66758ULL, 0x7723EFA6D0C0AF0BULL, 
            0xE7222349D81F085BULL, 0xEE314F189E0D6027ULL, 0xE0EE6F18DB5555F6ULL, 0x8005F5DB6BD74347ULL, 
            0x00A41C41B9B8CBCCULL, 0x10A5FA97C1DBD8FBULL, 0x9A019C827CE46B51ULL, 0x27FFACE58A9474ECULL, 
            0xEF2A161F3A45585DULL, 0x08DCB0EDC1E9C92BULL, 0xF0373F6196A90459ULL, 0x428599DD6399EABDULL, 
            0xE631CC5B12BA2397ULL, 0x08B3D10FB6C003C0ULL, 0xF65EA7DF6E7D7B7BULL, 0x999D89E2905CC873ULL
        },
        {
            0xBD40F6C65776174AULL, 0x9AAA6BCF6CB12F44ULL, 0x5EA2612B0B3125ABULL, 0x7B68766F47496972ULL, 
            0x8651EDEC2022EA81ULL, 0x20F8F4B1D8960CA1ULL, 0x33A2AFAAA5F82BE8ULL, 0xACCBBB0F2D59DA27ULL, 
            0xC5114220C28139EDULL, 0xA5BB33F856167E14ULL, 0x408F94719C5507D3ULL, 0x44FC665B3CD285D7ULL, 
            0xD25E4E52D9229EDDULL, 0x71B97D195FD3DC35ULL, 0xB9DBE06C8921F8CFULL, 0x4A380079CBF07803ULL, 
            0x4FCDC59A07E7FD5EULL, 0x02A4A3FE79F1F8DFULL, 0xF8E1E013E8E17B6DULL, 0x69CCDCCA252DD3B9ULL, 
            0xA094B6BEB9439D93ULL, 0xC1735A01080ECAC0ULL, 0x9519534AA868546FULL, 0x80E9E783556CED93ULL, 
            0x482D8626674AE649ULL, 0x8FAD95C122AED403ULL, 0x890A3908C9E5B8E6ULL, 0x000EAEFB47E6118BULL, 
            0xABC2A250613ACA5AULL, 0xF38251AAE181A0DEULL, 0x6D398DA2D5000293ULL, 0x9D36CB78670F4408ULL
        },
        {
            0x2A430C263E01AD96ULL, 0x09A785B00482ADD0ULL, 0x83D048087FC0CC2CULL, 0xE60D05E9BC430816ULL, 
            0xC2061DF3EA22A548ULL, 0x09C5F615F77C90E5ULL, 0xA196AEDA48BE0DD7ULL, 0x5897A089E9CCA5C3ULL, 
            0xD0F2BE7804A81310ULL, 0x179E67E249BBB283ULL, 0xE0115001760C2699ULL, 0x6BDAB75A6209859AULL, 
            0xB73E0A04229EDD21ULL, 0x28FFBD2EF911C0FCULL, 0x2883FC8B1C3E8E29ULL, 0x7EAADEC301942FD9ULL, 
            0x3B36E696A316B281ULL, 0xF029E92167C5B5EDULL, 0xAFC8258FE43AB410ULL, 0x65659E924235B167ULL, 
            0x5C9A8BFDC6C95431ULL, 0x52452265327C0252ULL, 0x86D11CD7F82387F4ULL, 0x7AA26D0F1D1B2E75ULL, 
            0x05A4F8C83517423DULL, 0xEA773951A599AB26ULL, 0xB51D68917ECC2DE6ULL, 0xF8ED3CF861D8D23CULL, 
            0xC4D0F9B17FFB653BULL, 0x7382258DAB3948BAULL, 0xCE215D5B3F88F551ULL, 0x73E52C7DEDCD6E59ULL
        }
    },
    {
        {
            0x11CD73A77BF57A5DULL, 0x95CCD33DB32FB3FBULL, 0x440637F9BC402DE8ULL, 0xAD58DEC2E9D45D54ULL, 
            0xF4A03637C9886C0CULL, 0x8E4D417E807191BEULL, 0xAC631EBF59563BF5ULL, 0xC6501B80CEE984AEULL, 
            0x3D3F00758F6CF35EULL, 0xC3DF528C57D81314ULL, 0x1FC758D8C17D46DCULL, 0x2B1584514D0DBB8DULL, 
            0x98524D726125E084ULL, 0xD801929AF47E665DULL, 0x7AA15C6C7E384454ULL, 0x0A669F8BBB35E538ULL, 
            0x4E3C32FB6BB150C2ULL, 0x9E4C54F649605DBFULL, 0x0172E19727EE82C6ULL, 0x7CC5D76006D4489FULL, 
            0xF3798B02A250798CULL, 0xC4D1491D61B08C6AULL, 0xB31B828166019813ULL, 0xF91DF622F02AE95CULL, 
            0xD77E544CB37F8999ULL, 0xFFFC5EFB2E4C3DD1ULL, 0xFE17EE6A7CE5B667ULL, 0x69ECC3C89147BA63ULL, 
            0x1684C792639EBC35ULL, 0x8E2B1A96A9820982ULL, 0x5F843A9ADF27E63EULL, 0x30662EB8AA1AB5D3ULL
        },
        {
            0xF9D10E2DB7E392B2ULL, 0xBA7E31BFDD673D64ULL, 0x0CB3CD19F06B98B3ULL, 0x11EA6724D13E4EB1ULL, 
            0x95F14B0670E22281ULL, 0x0144BD98E4835CD0ULL, 0xB9741E290B1F92C3ULL, 0xE5F2CFEB5117B2CEULL, 
            0x9FCEC348BCBEA289ULL, 0x88C3EA23B37DC9BBULL, 0x1CAF0CB154D55EA4ULL, 0x16DAE676AE6135DFULL, 
            0xCB9A55443E57047EULL, 0x8945DE242E6C5C67ULL, 0x7ADC67DCFDFB36E4ULL, 0xD0DED7B62A2AA3B6ULL, 
            0xF24BBA38058B629CULL, 0x2D5C28D041FA54D5ULL, 0x75334681F957A04BULL, 0xE5D1D35DF06F6CB3ULL, 
            0x74FD99BC1E8376D9ULL, 0xF24E4AE4E3B66602ULL, 0xAC510888A84911C1ULL, 0x09434B2449DDFCA2ULL, 
            0x93CF532B2C98DF46ULL, 0xB11E2C27FF923301ULL, 0x510C01A551A5539CULL, 0xB241C8BBEDCD2B91ULL, 
            0x937D03D4F35C6FE2ULL, 0x5D35087C34118E4CULL, 0x1766A43420C6FC7BULL, 0x98D9B7CF1F3EB13FULL
        },
        {
            0xE48E8CF5026DAB6BULL, 0x7DA16B06591D6470ULL, 0x345A95BD2D457C7CULL, 0xB863400AE8079496ULL, 
            0x6168F7D5F234E247ULL, 0x2AB065CC27BADBE9ULL, 0x0EDB34352B81382DULL, 0xF8DC283A24213042ULL, 
            0xBF803C30942F7F69ULL, 0xA2EC062DA1DB923DULL, 0xC3DA17FB9C637106ULL, 0xE7420812CE508760ULL, 
            0xC3868A33AB88E92DULL, 0x8E2DE725E1B755F6ULL, 0x29FD692E5F4D0EB9ULL, 0xA20860991F6647ADULL, 
            0xD8CFF1052E43D1D4ULL, 0x8DCF99A834DF396FULL, 0x90F54A266F932B02ULL, 0x8BD4D1EDC0D090DCULL, 
            0x94A52B42F6CF5312ULL, 0xEE8C3BE43598E736ULL, 0xDBC9B39E8DFA543AULL, 0xCD2B770A90DF2497ULL, 
            0xE511D0637D8D0CD3ULL, 0x3746D5DB709FD2EEULL, 0xCC599B6F0D809BBEULL, 0xA9F4AB64F49E4DA7ULL, 
            0x9B98F442284C155DULL, 0x5B7567D4C8F042E6ULL, 0x38CBFA8D317B7BF9ULL, 0x7389FD111B5C4D1FULL
        },
        {
            0x24ED1AAD30C3BD8BULL, 0xA60C700D0FC6A81BULL, 0x124D031BBD58E2CDULL, 0x0F6694810751D954ULL, 
            0x75FF3CADD08B05DAULL, 0x895474097571AD14ULL, 0x5C03CCD1A7F7D79BULL, 0xBB7EE3DEA74BF387ULL, 
            0xDB52BEF67417B1DDULL, 0x6CA7F11A0CD5296EULL, 0xED167DC18BD55C80ULL, 0xCB6FAA4BF2F9AF30ULL, 
            0xC74035D59334571AULL, 0xFD318F7B9BE2C993ULL, 0xC781C32C15291C4DULL, 0x7DEA5E63A57CF361ULL, 
            0xD3D0206CB5E2D949ULL, 0xF392B29867D4D2A3ULL, 0x07D90F2DB5CBA6A7ULL, 0x2E5900B85BE33570ULL, 
            0x884AFB77B9A6153DULL, 0x6CE54B53DC17BC3EULL, 0x76BDDE22F6DBF050ULL, 0xBD55248E0B1A9546ULL, 
            0x2A4A9C7DEB6CD909ULL, 0x3E3BFA2DBC98D294ULL, 0xA60EBA301D2057B8ULL, 0xF695ECC115509A69ULL, 
            0x1CFA324964901D77ULL, 0x4F67D4E6E9EEAAB1ULL, 0x3F403FC6C7E42621ULL, 0xBAF0CAAF6778EBDFULL
        },
        {
            0x60CB06A9C745A6E9ULL, 0x7F4160E1131493D4ULL, 0x200E3575509E7767ULL, 0x72445A7E513157F9ULL, 
            0x47EB6C48E4F0F3BDULL, 0x696E05345E1513CDULL, 0xB409F8A9C38738F7ULL, 0x8108ADC475AEEDB4ULL, 
            0x2EED40C51C5660F9ULL, 0x6407E08FF1A7039CULL, 0x9F9FA4EAF80890E2ULL, 0xCE8E8EBA10C98395ULL, 
            0xDBC5DDF7B47C4292ULL, 0xDCF6BC3A6829E628ULL, 0x217B517E3ED033BFULL, 0xDB0E4EF11F4FE643ULL, 
            0xAB49EEA193BF8585ULL, 0x004D1E9D049E5292ULL, 0x698F1019F0DCBA53ULL, 0xF4BDD1CAED8CD881ULL, 
            0x06DFCFCCD5B52ACEULL, 0xB5ABAC5603E7168BULL, 0x7A8B8493C59679FCULL, 0xBC110632CB2ABA44ULL, 
            0xF52D6826447F552FULL, 0xFFD4EB09D5A80236ULL, 0x0577D0920B275252ULL, 0xE0283DAD1786BB63ULL, 
            0xD216255FB676EC38ULL, 0x03007E6BD514C823ULL, 0xBFF0F7183594AE2DULL, 0x3CDAC48FDDF1DEB3ULL
        },
        {
            0xBDCCB9EA2F20DFF1ULL, 0x6AD5975A0501A360ULL, 0x1B08A55C2C6551B6ULL, 0x12E34E29AD83868EULL, 
            0xBDC22DA3EC6A7383ULL, 0x49FCA3D0917E2E26ULL, 0x87B05FC74C9C937DULL, 0x6D93A14B5FFC20D6ULL, 
            0x3824FC9E905B5659ULL, 0x4B0A4780852F7FEEULL, 0x6AC9AB3BCBF0E4D7ULL, 0x885D18085E3E5DA9ULL, 
            0x190C5E1EDF022228ULL, 0x50C4FD2E0E8DD7EEULL, 0x485AB92DFD5C1403ULL, 0xE45D2B5BCF224EC6ULL, 
            0xB8E0612AABE90C74ULL, 0x3330C4AF6DDD141DULL, 0xE1951EB631246C17ULL, 0xB6BD4EDCBA594398ULL, 
            0xC5B699F0BFA310CFULL, 0x3E3E60308C59D4C2ULL, 0xE060C0F3160BFDB9ULL, 0x7CDEC3AC29AC7D3BULL, 
            0xDCDC738504F30B51ULL, 0x040A2E5E2D42F5F6ULL, 0xEDCC8881EB99EB50ULL, 0x22BE34636BE8CEE5ULL, 
            0xC6ED05CCBD4EE7E5ULL, 0xF93876B12F46880CULL, 0x4CA4A39B80A97AAEULL, 0x53213934C150B388ULL
        }
    },
    {
        {
            0xFBE2F38DAB28E21BULL, 0xED3C58CB7EF13305ULL, 0xFC9E786141A420B9ULL, 0x243029B80FA8D421ULL, 
            0xAF1BF4EB9AE33FD7ULL, 0xE959AA1706E17845ULL, 0xCCEA4EEC22E49C7CULL, 0xF80FA8622E52FA95ULL, 
            0x80E22A985323DFBBULL, 0x1418A94FFE6763BBULL, 0xE8E51121CC6C82BFULL, 0x822159206DC8A2ECULL, 
            0xF2C111F358A02D7FULL, 0xA4D208008332A76DULL, 0xDC19598A60DD5A4FULL, 0x9371354545B29096ULL, 
            0xF5C7C6EA36CA737CULL, 0x0CECB05B718FE3FFULL, 0x61D5A5F15F55E825ULL, 0xCD4529550FACCE0AULL, 
            0x6B2DC8AE2F637908ULL, 0x9503C88C3D419DBDULL, 0xE10ECB6FD4CAA25DULL, 0xB959E2543E2D697CULL, 
            0x0664B29FAA2206ABULL, 0xFDBF8B716D38A63AULL, 0xD52AF27440C607A7ULL, 0xBFAD3FF66939C656ULL, 
            0x327A4CE49517C51AULL, 0x1BD6AC22F6CBD40BULL, 0xDD88CE0C6F8938FCULL, 0xE3A4CA4FD4388324ULL
        },
        {
            0xFECC937CA1173493ULL, 0x6930A48877410A8CULL, 0x9F87C1326672ABC5ULL, 0xF071AECD744D74E5ULL, 
            0x8F422A69AB3EFD9CULL, 0x8F16F6A4EA998FB8ULL, 0x371207321E93EB8BULL, 0x4AFB2EB8A1EBCBE8ULL, 
            0x7148F474515CD458ULL, 0xECDC20F1F7918ED0ULL, 0xC8B15F9183EA58A8ULL, 0xAD521DAD66DE7C1AULL, 
            0x6D4FD7401E6D11F3ULL, 0x90BCE675E4D13DF5ULL, 0x350EAC154CB1D108ULL, 0x3CF7C452C139392AULL, 
            0x3B9B427A379948B5ULL, 0x08B7780D3EBD55AAULL, 0xA68829B7E4D82C72ULL, 0x4E469DDE508A95FAULL, 
            0xE24217E14A12C82AULL, 0x107C6D0F6FC5725DULL, 0x70CBDE2039548B39ULL, 0xB3254EA09DCE15ADULL, 
            0x860445AAEE61E5ACULL, 0xECC481A1D9D698A5ULL, 0x20ABBB12725119B8ULL, 0x2B5186DD227D4BDDULL, 
            0x135959BA135C3FBDULL, 0xB9FF539806837582ULL, 0xF3C846ADE13F8033ULL, 0x162FFBFD6A2BD3C2ULL
        },
        {
            0xBFAE41A5B3E8BDC8ULL, 0x9808A7378E8EBE79ULL, 0xEFF8FDFFBCBBEABDULL, 0x5417A580321A5CD4ULL, 
            0x5D2EDAA9DEEE4C47ULL, 0x82EDA3ED387437BBULL, 0xAC7EB9EEDF48C3B4ULL, 0xCFFDE30AD787946EULL, 
            0xC2A384435BE7339FULL, 0xA76A094439C40390ULL, 0xF81321B830B180F0ULL, 0x24DFE3E8184C119BULL, 
            0x7991B5D55DCB5B6CULL, 0x4D47F7698279D1B9ULL, 0x89A8BD7DB4616D49ULL, 0xACEA2DDB37EA6927ULL, 
            0x8E16A55FEEBA82DAULL, 0x007CAA90C87CA403ULL, 0x45B709D96227EDF4ULL, 0xA79DB1A3DBA002E5ULL, 
            0x7DA168B68F570EADULL, 0x8E88C6BD7775ECC0ULL, 0xA602EA52AAA1F44AULL, 0x8858498544C61459ULL, 
            0x8BA0985319F5FCF0ULL, 0x4750C674982238FFULL, 0x9430C09D90B666F9ULL, 0x6803472B104308A0ULL, 
            0x1933D6CE6C098B1EULL, 0xA7CA99211C2FCD8BULL, 0x836D44412E3C6A31ULL, 0xC070252AC4ADA2E2ULL
        },
        {
            0x751923D32623F112ULL, 0x3768E3299ADF196EULL, 0x78D3E3C6C8F85235ULL, 0x1F9421D22638C597ULL, 
            0xA5B7FE6C6B89BC6CULL, 0x19D3C5408E1DB05EULL, 0xFF6F1825928E6F6DULL, 0x33FE7CF3E5EFAB6DULL, 
            0x650E466BB16CFEEEULL, 0x6D6CA35DC57C4297ULL, 0x31E9CA638090F7D5ULL, 0xA4E6AC758A0E7648ULL, 
            0x9AEAAE0A7A8E2BE1ULL, 0x70974E64DB43AA0EULL, 0xE13BB678C266FB3EULL, 0xA11871132D1EDEDEULL, 
            0xD5C0E7145F58E426ULL, 0xA13E4D896AD183ADULL, 0x3606EBF706B497ADULL, 0x4D362D1183573918ULL, 
            0x282D6AF40AD4ECEEULL, 0x299C16AB8C5E975AULL, 0xF85B1BD15A67B322ULL, 0x1FFE5A2029E4190FULL, 
            0xCF7C9D7C48220C56ULL, 0x1D57BB0AC4B90623ULL, 0xB98EE0C9AF4F6ABCULL, 0xB6CC7FE8FE1BDE25ULL, 
            0x1AC4866D16A09600ULL, 0xC44B2AC95634B55AULL, 0xEE29A6708CDF68EAULL, 0xCA64BDCDE631E39EULL
        },
        {
            0x7EBC599B8E9C6622ULL, 0x5ED873F169040A16ULL, 0x4B9828A6B466ADC9ULL, 0xA231B7B454EC685CULL, 
            0xE43BFEDC3CAD482DULL, 0x23552F145FE28C0DULL, 0x7B632E57059EF604ULL, 0x124FA8AE42D0FDE1ULL, 
            0x1728C1722D346A37ULL, 0x4DD513F5BE6EE657ULL, 0xAA79114414E8EB43ULL, 0x5DD59DAD6C233CDAULL, 
            0x19045125E6FDC249ULL, 0xED42E76EC6C690C8ULL, 0x6200B5C17CC071D3ULL, 0x815BCB1447BEAC9AULL, 
            0x2D78262477E2B76AULL, 0xF17DF9DAB95323F4ULL, 0xAB2C8E88CF86AD12ULL, 0x9D739DDCBECBF778ULL, 
            0xB6B79E9371BF4785ULL, 0x7634E616DBCF9DC7ULL, 0xBF3EC01DC35E791AULL, 0x68DDC6498C4CFDCEULL, 
            0x1EF48D581AEEA080ULL, 0x980FDAF22EDC812DULL, 0x8F93BDC6D9039829ULL, 0x415FE6026437C63FULL, 
            0x08A92FA89EEAC29DULL, 0xE5E5EE85CC87FC42ULL, 0x4B03432D55514E74ULL, 0x1BA3006D0F82FE58ULL
        },
        {
            0xC62ACBC137648E25ULL, 0xC64A8A09DACAB436ULL, 0xFE1C9A486767431EULL, 0x42777E571C7D5D49ULL, 
            0x133BF05D14C8585CULL, 0x83CF12BF302119D1ULL, 0xF90461302427F815ULL, 0x2BC8FA4A06EAC70EULL, 
            0xB195D67D0792647AULL, 0xE27C8F7B66E13750ULL, 0xB7425388E833DEC3ULL, 0x495A3D5164E532A9ULL, 
            0x0E2641CD46745804ULL, 0x3CFC6E6FC133CCFEULL, 0xBE3CA99836B8840CULL, 0x12E0E61A83C94A94ULL, 
            0x28F566C14A06F939ULL, 0x987F25DAC9A520CEULL, 0xA8688C8B102B1C54ULL, 0x23223E7B34ACEB82ULL, 
            0xAA0B38DCDF0EB714ULL, 0xCCA306B819BF2D96ULL, 0x50ADEAC28ED5A49CULL, 0x8A3FA483EF2E8ABAULL, 
            0x54B1C3271C2DDA6BULL, 0xA1B51922F33E9C92ULL, 0x28980CFD6D82989BULL, 0x5C23235E2670ACB1ULL, 
            0x8B33E7F55B629E11ULL, 0x7B2860F41A215774ULL, 0xD00F33F1EB4D6FB8ULL, 0x4552F08A823DBF8AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseBConstants = {
    0xE1BC3D4829495F6EULL,
    0xCF7DD8DF67F9E878ULL,
    0x6259D541380D83AAULL,
    0xE1BC3D4829495F6EULL,
    0xCF7DD8DF67F9E878ULL,
    0x6259D541380D83AAULL,
    0xFE3DBD55C5B240C9ULL,
    0x9A4788BCDA080442ULL,
    0x95,
    0xDE,
    0x51,
    0xB6,
    0x92,
    0xA1,
    0x9A,
    0x7C
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseCSalts = {
    {
        {
            0x1AC8B1CD954173CCULL, 0x2F2DF675F4677791ULL, 0x2B5C3A0652CABBFCULL, 0x17F6537E46F1E203ULL, 
            0x1A14284A2DC334ECULL, 0x0B62113A7A506442ULL, 0xCE7D10FBEE82CE8FULL, 0x7BED374219745911ULL, 
            0xAC2B3C302F74352FULL, 0x9C86280E5F4EC706ULL, 0xB80433A1F43ACBE9ULL, 0xFB4F8BDB6F1C39BFULL, 
            0x2F6E2145375BD9EAULL, 0x835FA0378FCC20DAULL, 0x02284B8B7FE4B756ULL, 0xC00C75951F524A64ULL, 
            0x37DC729C70C97AA2ULL, 0x09F6B7E7B38E51CAULL, 0xC8715706ABEAF59BULL, 0x3E387F2D186B5588ULL, 
            0x06CFB2512096C89AULL, 0x03AFE2A217306457ULL, 0x95BE68AE5EAE36CAULL, 0x56723DC5622D8E82ULL, 
            0xB2D31CE215F4608BULL, 0xA1516E7159DCA712ULL, 0xAD27F4C6CF529A57ULL, 0x19C551DC13062065ULL, 
            0x26309D783A55E4EEULL, 0xA11F63891CD439D1ULL, 0xAE4A45121CA2F1C0ULL, 0x0A98E244C381A2BFULL
        },
        {
            0xFCE67B008BDB88AAULL, 0xD60552E1DAA85A73ULL, 0x294AF0A6C978377BULL, 0x4325550A70DA6624ULL, 
            0x78A0868EDDD0E7AFULL, 0xB39FCCBA89E8BA4BULL, 0xAD10CAF6BE64F748ULL, 0x3A9ED3A1779239E6ULL, 
            0x1DC975F9F8A13C54ULL, 0x7F7600F7B8E1A976ULL, 0x8F311A40FCBEFDACULL, 0xFE5A2E163516FDA5ULL, 
            0x115D7DBFB10C9DFFULL, 0xAE4039F2C4B9404AULL, 0xDC94C1E83644300AULL, 0xCCFDFB465F66DF52ULL, 
            0x3E4987A27A2A1702ULL, 0x33DECADEE2D8130CULL, 0x45A6E64DAE395DF6ULL, 0xDD2EFAE9B195A1A2ULL, 
            0x2719C0D7FB1DE99CULL, 0x9E8B7B3CD32B02DBULL, 0x5297D7124E2FC370ULL, 0xE6DC531E3BCB089EULL, 
            0xF274F4B04652BFBBULL, 0x8A7E74EF6F0FDC9AULL, 0xA79F88F0C48DEE9BULL, 0x3AA53F33DB1C1AFEULL, 
            0xEE5ED429E4DAAFD5ULL, 0x37E4501E764C3107ULL, 0x38992A54BA7A861AULL, 0x37CA353F1F47FAA2ULL
        },
        {
            0x9704C50E83A1C096ULL, 0x8E22DAF6472FF473ULL, 0x3B11A87EBDB8DF1CULL, 0x5748BAD9F159CDAAULL, 
            0x6E4BC8A4E8CF8F1FULL, 0xB438FEF15CE4F1FFULL, 0x8C685FE087FA2694ULL, 0x090529A5987D2EA5ULL, 
            0x911AA5C3EAC4E137ULL, 0x254427B64ECBD51FULL, 0xF9DD1612C993C965ULL, 0x8E427F9040A657A6ULL, 
            0xB25FF6E2C9D4B763ULL, 0x66AC80EAABB46939ULL, 0xDD7462B31A05DF5AULL, 0x694F1A311C747905ULL, 
            0x6E9118838F386084ULL, 0xC3F1013349459422ULL, 0x1DDFCECDD4958619ULL, 0xD49E0A02C53D59FFULL, 
            0x75CB74D2F30A65BEULL, 0x2CD027FC9CEDB347ULL, 0x020E7CF5FF22CC92ULL, 0x3A9C2B6381F1D6B3ULL, 
            0x2389F1E65E91ABF5ULL, 0xB567D32B1D2999C5ULL, 0xF1EB339D8C4897C9ULL, 0x3586A6888FB74092ULL, 
            0x2807C2F82CC347CCULL, 0xCA9F1BA6F0085767ULL, 0xB01C990B27A5A18EULL, 0x4D2870E6AE2BFAD8ULL
        },
        {
            0x0F42DAAB924DD978ULL, 0xC9E79C6BF6798BC5ULL, 0xEB673FAF2EE98964ULL, 0x3F6F96EB9D76063BULL, 
            0x021BE1DCC57898BEULL, 0x1F68D6E2E89D4667ULL, 0x415160B903156E00ULL, 0x215681FF4A5A131EULL, 
            0xCC51560F5FAF5E45ULL, 0x244988E318E56784ULL, 0xA82A891FD3FB9220ULL, 0x62941A107A6B3FC7ULL, 
            0xC2B3D225ABED3E1AULL, 0xB03E9C5FCEB11661ULL, 0x552790DBC58C34D5ULL, 0xB766DA3BAFAECDCBULL, 
            0xFEBC91109E7E03AFULL, 0x467EA7011CE0BAC8ULL, 0xE529AC2542617816ULL, 0xCC903BB3E90770FAULL, 
            0x8A1A5DC5E21ACA7BULL, 0xF6ACD6C2FDA1873CULL, 0xB2738183F955A924ULL, 0x6E30FEC2B46E9F66ULL, 
            0xD715E6832240432BULL, 0x8A05881343E959FFULL, 0x8F9CD0469FDBF6A3ULL, 0xA20206C4EA1F3D37ULL, 
            0xD73B4B8E6FD122AFULL, 0x1B1E682227EA7FA4ULL, 0xAF3467946124CC88ULL, 0xBB178BA2174D01A0ULL
        },
        {
            0x43EDF73A4050CFAEULL, 0xE5458B725877C2C9ULL, 0x04EA8E017FDF0951ULL, 0xFCC48FE0EFCAC7DFULL, 
            0x8B0C95A50EA3D42AULL, 0x4BA35CF9D4B4CBF7ULL, 0x411FC9AE91B7BDC9ULL, 0xD8648F716F3B5084ULL, 
            0xD36023DFC8F08459ULL, 0x623D53E23B81BBC8ULL, 0x9F869FD3636FA458ULL, 0x3D26A766CD3E8AF9ULL, 
            0xAEAB60AFDDBF64DDULL, 0xA80BE4698A17A671ULL, 0x5FD6EBC3A117F7FDULL, 0x17A30C457C257F1FULL, 
            0x3471D3C70A6D4826ULL, 0xDC6311FE226DF5C6ULL, 0x20FE72BAD34E5F09ULL, 0xB01EE13A8A04E2AEULL, 
            0x8F70CA024FA5288EULL, 0x463F264E35C64CAFULL, 0x1C1FE644EF444C5AULL, 0x72ADCC3A81E575ADULL, 
            0xE8AB429BF4800ABBULL, 0x702991E519F83E08ULL, 0xF5B01956EF76A382ULL, 0x5B61BFD97B3E9525ULL, 
            0xAD9B5BD5714AE98DULL, 0xA748FBCAF591694CULL, 0x764B80B03D084A85ULL, 0x8FCCC9D72CAD07B1ULL
        },
        {
            0x6A68447963FCC6D8ULL, 0x2D5414A00FF61003ULL, 0x6F9BF71242F1C17BULL, 0xA261503D476934DDULL, 
            0x87A4340FB4B67409ULL, 0x6D6BB65691822A2FULL, 0xF119C700156D9FD5ULL, 0x3A068BB7B9121CCFULL, 
            0xFA73FE1E44096B82ULL, 0x9288353B0FEAE10CULL, 0x0DA54B9695ECD537ULL, 0xB7C18BBBCA0BED1EULL, 
            0x760212ACC63A0CEEULL, 0x7F340B9CA0A36B6CULL, 0x5154E4D7C2D33496ULL, 0x96390837DA9B31E2ULL, 
            0xD3DDEC849CDB4265ULL, 0x7E0FEFF124F48BD6ULL, 0x17843721C8065BDBULL, 0xC0E6ED75DEEA862CULL, 
            0xC48B805D486853EEULL, 0xFCEADFA7C55F4287ULL, 0x7CA6D3DC190D9AF4ULL, 0xA0B0C849C914C80CULL, 
            0xBE66AA268BFE23A4ULL, 0x82AAA2353F722351ULL, 0xB5789CEC78C10A7EULL, 0xC3AEFEAB64CB87D4ULL, 
            0x71FB8427E4CABC88ULL, 0xBB4489F7A10F0D59ULL, 0x0A07512D8FC8F47EULL, 0xAF079301BF1AB9B5ULL
        }
    },
    {
        {
            0x7CEF5FAFF02AF94DULL, 0xBF36427B9FA94ADBULL, 0xF6DB5EFD7476A8B8ULL, 0x873EC3847A34FD39ULL, 
            0x0B86C43FD84CF328ULL, 0x5522EA932E6E8C2FULL, 0xDBA010971347F90DULL, 0xC75895F459480372ULL, 
            0x783D8E8A3E4E2D82ULL, 0x5696BC57ED0D04E0ULL, 0x218D745A247B465CULL, 0x77934889094AB84CULL, 
            0xDC0556C9D8BF891AULL, 0xD1335A4E5E29F06DULL, 0x3A9ECA06DEFCB5AFULL, 0x7BF8891A21871D1AULL, 
            0x958F61F770D013FFULL, 0x12730B69768C14A2ULL, 0x5F930F209F90CFBFULL, 0x994A366DFB584267ULL, 
            0x3859C20D83FF504FULL, 0xDE5547AE39C8A4B4ULL, 0xD86559788731E00CULL, 0x70CBEF6AA5FD8A98ULL, 
            0x59DA4A14AC63C686ULL, 0x4A5921113A021B44ULL, 0xC3C7FD839E4C222DULL, 0x6C51B3939E114D51ULL, 
            0x2F31FBCDC5ED1BBDULL, 0xEF5DC96A9B42E3E5ULL, 0x6784E19D6300C1BBULL, 0xB46F3B2D4F2F6A34ULL
        },
        {
            0xD4DB3A951BB7F209ULL, 0xABFD1954B9FC3851ULL, 0xE7A764A29EFFF66CULL, 0xB008526050939C29ULL, 
            0x78CECE50B9509E00ULL, 0x95305BDAFD641B7FULL, 0xA041C851A382C9EBULL, 0x01274A28AED291F7ULL, 
            0x3B4BC27929700529ULL, 0xA21BEA7AB4B7F4D3ULL, 0xEB13CC506EEF4E20ULL, 0x4378DE0E178EAED1ULL, 
            0x2450DA811035D02DULL, 0x3304E8A98AACA80EULL, 0xDE650224B415E705ULL, 0x269298039B65168EULL, 
            0x3850539AFF9112E1ULL, 0x6C48C24C43B46022ULL, 0x1FA5D883E9EADE2AULL, 0xE128E84225373257ULL, 
            0x3C532BD4ADB6590DULL, 0x06B16E5809E703BCULL, 0x5515A393AB3CE981ULL, 0x928FE1137BEA29BCULL, 
            0xC48907597730F2F0ULL, 0x3E2A1053C38A61D8ULL, 0x7F66A06B682B1F37ULL, 0xBE61B78C8CB96071ULL, 
            0x5B604B2B431ABEF1ULL, 0xE971282A6527DD1AULL, 0xDF33C4F3D8D5F1FBULL, 0x63E2F06A4B58A01FULL
        },
        {
            0x4EC723844744F911ULL, 0x5C2422F6C8778ECBULL, 0x22B09804D465A122ULL, 0xE885594C8C91FB39ULL, 
            0x60B8D141CA4AFAD6ULL, 0x18BDEF032325E060ULL, 0x495A63553849BD54ULL, 0xD5A5995B739EACA4ULL, 
            0x785B9EB75F692523ULL, 0xDB16CAF1720B1644ULL, 0x4332E41F2651F46EULL, 0x2991A4D508D58002ULL, 
            0x1925F39C7D517CDAULL, 0x7E84AB6533977430ULL, 0x36338EE35E11A057ULL, 0x99179CFAE8887BABULL, 
            0xF91D91AE690E15DDULL, 0x784D6EAB31977A87ULL, 0x9631510A57D17614ULL, 0x9497571FB02FD2EAULL, 
            0xD5A8FE38C5D31B0DULL, 0x93196DDA8A9C3546ULL, 0x92E9ACC8713B37C1ULL, 0x1913D199B7BF8AC6ULL, 
            0x7C37EC55A7FAAFCAULL, 0xB601458E1050BA3CULL, 0xCFCEE6D51B37C16BULL, 0x55D854EEAB591239ULL, 
            0x3E860DDEC7FBD0E7ULL, 0xF63DCC5F3152CAEDULL, 0x6323B9FD702859A0ULL, 0x73BA56467A97CA2DULL
        },
        {
            0xDF7B7411B6CE33D0ULL, 0x17D75F6FB3D76B0CULL, 0xFF9C62D28193945BULL, 0xFB1D616CAC00DBAFULL, 
            0x03A19D2ED09D01D9ULL, 0xC91E962E532195D1ULL, 0xAD6EE1B8F60CCD01ULL, 0x46F42A80E5B8B57DULL, 
            0x58FF4D9D3B536F98ULL, 0xF71AB09A14962EEEULL, 0xCB1DF83F19A65B36ULL, 0xAAE9715ECFD4EADFULL, 
            0x788783C03F386FD6ULL, 0x067D9EC87857EF99ULL, 0x965CBEE7D7ED882BULL, 0xDBDAC65A125A8E73ULL, 
            0x1911489719620297ULL, 0x12AEB34D094F81C1ULL, 0x18A9F8971F0FDB05ULL, 0x4100F0325E539FBCULL, 
            0xB6667EE288DBBB94ULL, 0xED59485C1B995DB8ULL, 0x7F198CF6741C6209ULL, 0xD53A22C9A09264C8ULL, 
            0xB4A2FE4B8A256D44ULL, 0x81E7B4F256077A06ULL, 0xD67665DABD7F7696ULL, 0x2D387CD35C3CCDF8ULL, 
            0xE80716FB83640D96ULL, 0xF116681FF1089EF3ULL, 0x88AD6E62D6E96C7FULL, 0xA2C96976C4110A93ULL
        },
        {
            0x1160656B78BD046CULL, 0x14CD201B30603724ULL, 0x915C9D6E541F3209ULL, 0x02D08987F4A13CC6ULL, 
            0x23AC04238A66584DULL, 0xED7519CCD37CF503ULL, 0x5D1B014D8C8B8A73ULL, 0xFFFAF54D1C90D080ULL, 
            0x240B99A1A37B1E77ULL, 0x16EDBF874062B870ULL, 0xBE752930627B492EULL, 0xB959690716BF70AEULL, 
            0x69B577CCF19BDDBAULL, 0x4DD3E794A4F7243DULL, 0xC52FF5395A10D420ULL, 0xF441468C09C4C864ULL, 
            0xB930BAB4BAF7A6B1ULL, 0x10A71383337521B8ULL, 0x943C1BF3D583E967ULL, 0x0A0141E38DD7B4CCULL, 
            0x1B177CE8C5A9A702ULL, 0xCF35A414327597D9ULL, 0x3C925C441CCB607AULL, 0x2C2FF0B928A92319ULL, 
            0xAD5DE1CD0EDDAB08ULL, 0xC5D2F183950CFDDFULL, 0xEB79432A95339791ULL, 0xE5A57FC040E44BA9ULL, 
            0x35DC3E05D0156F34ULL, 0x089BAB4B9FD2B297ULL, 0xDA3EA1B2A1928AA0ULL, 0x48538D721A2F8BFDULL
        },
        {
            0x6E558E4C688A2E16ULL, 0xE23E6DB5BC8A18E8ULL, 0x336AA04D44769136ULL, 0x7113937DCF9F6895ULL, 
            0x0EFA42C7ED4EB8ABULL, 0x2705DF3538A06E1EULL, 0x6DA94195ED071B10ULL, 0x508BF1E28D886107ULL, 
            0xEB9BB6C02B8CE74CULL, 0x24822F8FB67599C2ULL, 0x953F2687905D6BDDULL, 0x185D91BAC4D6AB8DULL, 
            0x598C121F205BBB78ULL, 0xC936977267CDC5EAULL, 0xBCC1B60461006E83ULL, 0x04AF03D837E3380BULL, 
            0xB6A321EFAEFDC9F4ULL, 0xDC2F2F19222DB1ADULL, 0x82FD34334280F6A1ULL, 0xB6391C83D2CBF437ULL, 
            0x25D2219A63BA32F3ULL, 0xF2C44B04B37090BDULL, 0xB35BFACA549FB80AULL, 0x0D012BD7947E2659ULL, 
            0x9206A573772EB69AULL, 0xBE7207FF3873ACABULL, 0xA97E5FD17665705AULL, 0x24C16FAC2B0BBC7BULL, 
            0x2C7585C25E3E9A9DULL, 0x8ECC5FD6117471F4ULL, 0x20A82E4382BA3DD2ULL, 0x2394D973C347860DULL
        }
    },
    {
        {
            0x2613D5EF6CC4D6F2ULL, 0xF88A9ED5F907267EULL, 0x3E35FF7309901F9FULL, 0xFA75FDB1B63C2303ULL, 
            0x791DF9BD60FE4171ULL, 0x932E3372FEA44366ULL, 0xDAF65E23BF3EC6A4ULL, 0x8A65161A4222BB88ULL, 
            0xD3FCDEEBEC032895ULL, 0x20EB90636C95D141ULL, 0x812271531CEE2DA1ULL, 0x48EBEB80A86B6AB8ULL, 
            0xAE0A81549E466213ULL, 0xA34BA68307BC5884ULL, 0x244194D13EC6A265ULL, 0x6A342591FC93AD31ULL, 
            0x9DB14D63C661A9DBULL, 0x7F37BE6B1F1ACDCFULL, 0xA20A6B1C739A9BB4ULL, 0xD33DB0BBEB904147ULL, 
            0x120D4B89B1A68C98ULL, 0x7678910BBF13FE0CULL, 0x064B050E5592754BULL, 0xADBB7DA84CA6EDDDULL, 
            0x886A266C55F0362FULL, 0x25478ADF7417984CULL, 0x8301EB7D746ECADCULL, 0x8016052F869A7270ULL, 
            0xB049645F484768B7ULL, 0x0DE616E2C9844A8BULL, 0x8A181703D3D408B4ULL, 0xC36AD1D158D28187ULL
        },
        {
            0x3FC4D86647B59B09ULL, 0x946A00B2EF54AE51ULL, 0xF6EF16560B1C8745ULL, 0x8077E30225913561ULL, 
            0x6545334C0FA34958ULL, 0xB2F197D92D59A392ULL, 0xC02D2D299EA55E5FULL, 0xBC4385A51D6055A4ULL, 
            0x6032E741AA20CC45ULL, 0xB484C88378AD1771ULL, 0x2C2481490D41B78AULL, 0x4A7D8273447238F6ULL, 
            0xE5C8F800A6DD882DULL, 0x1C6F3B3955F6F02FULL, 0xBFC01E13F9EE110DULL, 0xE37BEB94DC035580ULL, 
            0x5259B6E6E859559AULL, 0xADFE532E4B6E57B6ULL, 0xBF3E50801DECADF7ULL, 0xD0A82DD486895BCFULL, 
            0x5650A612C5CD7D22ULL, 0xCC9758EC930D0C1CULL, 0xD38E54F150DBB2E9ULL, 0x78850B9B3DF648FCULL, 
            0x52E7F990350BBBF6ULL, 0xE211CA9DACA4A766ULL, 0x07A8884A73F1FC25ULL, 0x6822985F27FDF2F4ULL, 
            0x94F72CC28D6AA7C0ULL, 0xD4B533B9403E90D8ULL, 0x0E17004D75A33930ULL, 0xEF04D53D9236E5ADULL
        },
        {
            0x5F53644C8A87855BULL, 0xCBB1CE97B63CEB13ULL, 0xC6C7446F4091C732ULL, 0x342C307D3635DFE7ULL, 
            0x317F18772291E1DFULL, 0xDA079B4996986AD6ULL, 0xF22F0E9DAD9FE322ULL, 0xE9029EDE6D414D38ULL, 
            0x1052DEE2184DE691ULL, 0x85D6CA066F2EFD13ULL, 0xFEA1A394B43EE2E0ULL, 0x5CE86C6C94E4D735ULL, 
            0x494D9CBB372AAB68ULL, 0x9CCDF09B2A2C138EULL, 0x845570EFC27F74D0ULL, 0x347CA2ABC911B29DULL, 
            0x08CEDCA838FF99D2ULL, 0x20C07A84E75F68D2ULL, 0xBC96ACADD72A8CB2ULL, 0xCB34AF1CE43ABE80ULL, 
            0x19CA6E5275B3DBD9ULL, 0x526F8A89FA273149ULL, 0xCF7411382741ADCBULL, 0x9B539FE0774BABFFULL, 
            0x8B545C596E122A91ULL, 0xD750BD5B6D7EFB46ULL, 0x85350DFC267B06F2ULL, 0xCA8EEC5391D63F44ULL, 
            0x3D72664EC9A092CDULL, 0xCB07A618686D428CULL, 0x1985EB82A152FCD8ULL, 0x4787D74D45C32861ULL
        },
        {
            0x7BF54536B56D34F9ULL, 0xE44FF5C1D6FCACEDULL, 0xEB67CF0613A379A6ULL, 0x8E97AAFF2544AB67ULL, 
            0x220D63470081B36DULL, 0x1ED0A57E934F4F07ULL, 0xF3437ACE8E2E88E5ULL, 0x53C885D44AD68FB1ULL, 
            0x7CADEB7D9DE5EEFCULL, 0xCC6A696F498F5282ULL, 0xDBE5CF3D33971FEAULL, 0xC2A1921D0E16219DULL, 
            0x20EBC8B110010495ULL, 0x7454304A26854A22ULL, 0x29138EA17DEBE0FCULL, 0x49939B3E5F36FBC7ULL, 
            0x2936ADA2E52CDAC0ULL, 0xE0E0D123086B65ABULL, 0xCFDFF63EB00028FFULL, 0xBC7C18CD69D3B2CBULL, 
            0xEC48C0CB356F2E81ULL, 0xCF08149C4EFB9785ULL, 0x1730B9CCCEF797BFULL, 0x402273482D9E4F31ULL, 
            0xBD5B41149F8A6611ULL, 0x88E74417D4089CBBULL, 0x86165F8C9A85E5F5ULL, 0x254FE33ADCE1CF10ULL, 
            0xD674674AABA04E83ULL, 0x23FB2C08CE6C4D25ULL, 0xC001E209EAAC26BCULL, 0x5C456D1CED78269EULL
        },
        {
            0x1FFE1A1B0B9302ABULL, 0x336E70845C6EFD7AULL, 0xDD0E000DDA87E7F5ULL, 0xD781BF8AA06E50D5ULL, 
            0xFF610D89EA980DCEULL, 0x80E12DB377F9DE4CULL, 0x0899A68D582AEBA3ULL, 0x486181CB7C7FC9A5ULL, 
            0x0F5B8AEFED961651ULL, 0x9D8E2639FB2D4380ULL, 0x70AB83D0D4F3265EULL, 0x3201996EF687C444ULL, 
            0xCA00045A8A76E5C5ULL, 0xF8570B6220870178ULL, 0x3EA4B706FB6093B6ULL, 0xD3A8358A6484678EULL, 
            0xE968FE1EFE82E534ULL, 0x6DC87860862ED0FDULL, 0xDFCCD0F42DEC1CD3ULL, 0xFD3A3168888E053FULL, 
            0xFD7EB4B1D74D5C7DULL, 0x04A8BE0576D0F1C0ULL, 0x6CE22E1C37211BEFULL, 0x11D151BA2C993762ULL, 
            0xDD9AA671A1AFFE9DULL, 0x326C3810AB874ED4ULL, 0x38CC717B19E30514ULL, 0x21FA663B2F0945B8ULL, 
            0xBA7197BBE42DF24FULL, 0xECB980A21BC6A89BULL, 0xFA829BE8F5A43C15ULL, 0xB4E35DBE0A878664ULL
        },
        {
            0xC6F3817F0F05D830ULL, 0xE42B30BEFDB933FCULL, 0x834A0738FAB621C3ULL, 0x31BE0F42926AA048ULL, 
            0x062618BC437B1DE8ULL, 0x67AB0CC7CCE40129ULL, 0xD5DF6A04063FC515ULL, 0x56C2BDD895A9B8F2ULL, 
            0x2DFC79C8EE78A8BAULL, 0x9BFBAFDB00AD6F3EULL, 0x9078F6097F378FF6ULL, 0x23D9EDF8325644F1ULL, 
            0xD64DEFE1C675EC38ULL, 0x93BC229058B570C3ULL, 0x24B8D85D33C121AEULL, 0x1E53296F0507AE3BULL, 
            0xF5AB011A23C5A180ULL, 0xC24B16E705896ED3ULL, 0x1973C78974D8C34AULL, 0x1BE52773707C65ACULL, 
            0x3048DA444686069CULL, 0xFEAA208F2CDDB082ULL, 0xB388FAFD6497F507ULL, 0x80B5F074965B1EC1ULL, 
            0x9A73315FA2BC152EULL, 0x02815A3672B57EE1ULL, 0xA587E4C657F13843ULL, 0x3B473609694F835FULL, 
            0x446558A7601FDBE2ULL, 0xB0C9B5205C7B0293ULL, 0x21A463C4FB093A15ULL, 0x6E84990E42F0E9EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseCConstants = {
    0x65EA4441B04BB06DULL,
    0xB41AFF5E92902726ULL,
    0xEB825B5B4D00B823ULL,
    0x65EA4441B04BB06DULL,
    0xB41AFF5E92902726ULL,
    0xEB825B5B4D00B823ULL,
    0x14C100B6C70E65DAULL,
    0x77B08D6CB541BFC3ULL,
    0xD5,
    0x78,
    0xED,
    0x35,
    0xDE,
    0x1B,
    0x76,
    0x1C
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseDSalts = {
    {
        {
            0xAC66FC98A2D802C7ULL, 0x23057A1148CC8759ULL, 0x9BC69D5D96F1D9B2ULL, 0x4C20CA847803EE32ULL, 
            0x2E54ECC6B6E4D042ULL, 0x4A7ED2114CD8A801ULL, 0xA376DAA45943EB5FULL, 0xE96D1DF78A2C2F7EULL, 
            0x3DD004330E8C7BE8ULL, 0xBBF6A383A3DB885EULL, 0x5351EF0872570B47ULL, 0xC26998480AAD2F5EULL, 
            0xE21FDC4190442680ULL, 0x247C852E5554B8C9ULL, 0xA74084371DE9A5D4ULL, 0x072B34BA5BBF78F1ULL, 
            0xF6F27E759D94A524ULL, 0x585BF796C5AD0851ULL, 0xE086AEBF1CD32A86ULL, 0xB50704FC2DE2CEC1ULL, 
            0xBCB20AE757B5D9B1ULL, 0xEFE12792D7031EA5ULL, 0x156444CB54861801ULL, 0xD75B3BBDF0B0C6FFULL, 
            0x0995A8054C56EEA8ULL, 0x936EB81ED46081AAULL, 0xD94C3252FCC41914ULL, 0xD2439D75B272C93EULL, 
            0xC3C873F75103DF9CULL, 0x4102A4AC836D5FF2ULL, 0x7660B4CA2D4DFA1CULL, 0x2ED5BD74F34DF56CULL
        },
        {
            0x73062948AF798D3FULL, 0x01AE23B091D4AAFBULL, 0x474E73F03535D33EULL, 0x790D15C8275B1E18ULL, 
            0x118EB762ED89CC6CULL, 0xE44D573EB9B60DB0ULL, 0x90ACE42279897F62ULL, 0xC09FDA5819448ED6ULL, 
            0xB4D90A641339335FULL, 0x989E48C9F8928E60ULL, 0xC0E1E0B0FF7B4CDEULL, 0xE49241AB6D4BF3ADULL, 
            0x0D43DDADB8D56ED7ULL, 0xD6974A8F25302A64ULL, 0x75564E49A0BB4193ULL, 0x83BC49C365DC0134ULL, 
            0x94FD12446F708745ULL, 0x5DBCDF4CBADE92A0ULL, 0x1D489F144279FFFEULL, 0x742E73E4B9007695ULL, 
            0x6D8491662A269CF5ULL, 0xB7214A666BC32409ULL, 0x3E8A413FE9D92C47ULL, 0xC71FD3236E9075D9ULL, 
            0x742413382EC35480ULL, 0x99DBA9F1BF5BEFD8ULL, 0x3D0B82B76BA165CBULL, 0x0F9BEFE2473F78BDULL, 
            0x44AF6529C9A32AE2ULL, 0x3C2FC570C7FF7F42ULL, 0xAC0759B7AC4B896BULL, 0x0BBD15F74FF0FC2FULL
        },
        {
            0xD925941F5E605723ULL, 0x30E95C8B7BB3FF8AULL, 0x2450C2CB08A23677ULL, 0x2A7048C01123A4A1ULL, 
            0x62AF766070AF180CULL, 0xFE7789A0EEA92CDCULL, 0xADF4132B7074AE72ULL, 0x0B5C7584E6AF0B17ULL, 
            0x57EAED503E0D357FULL, 0x1AE4138384FA47D4ULL, 0xEAD0E0E9BC91D3E5ULL, 0xF9E982E1EDE558D5ULL, 
            0xE91A9ECAB13BADB9ULL, 0x52722B792125B338ULL, 0x6B53C7551093158AULL, 0xFF262C880F6C35E0ULL, 
            0xF14618C2801B5CD2ULL, 0x51FAC8F6039E9224ULL, 0xA1FDFBFD1BC19BA5ULL, 0xE3E3AA1215C20223ULL, 
            0x50A9427D178BC33DULL, 0xD03C03FC827D52F8ULL, 0x4EE8AE0CF9242067ULL, 0x7E4570C8680874F5ULL, 
            0x24932E3E0D73F8A1ULL, 0x2A9A817079C197AFULL, 0x912E4D6A4CB7E613ULL, 0x44C52354E91B8E84ULL, 
            0x9FAD15C852260774ULL, 0x2BA8D3EE28B644D3ULL, 0x99CED4ED859E4225ULL, 0x157002AE13EC8DE3ULL
        },
        {
            0xB90FE43CEC8E6AB8ULL, 0x9FFEE0CC0F1BA811ULL, 0xE90696F75CD0BBB1ULL, 0x79EEEB03F6463D00ULL, 
            0x73AA45DC3852E61EULL, 0xA34BB7841D0C6377ULL, 0x1A685357722A6617ULL, 0x43226A9AA05A7A18ULL, 
            0xA57037B32507FE0AULL, 0xBB17816669C812B5ULL, 0xC589866B9AE220BBULL, 0x3056F590D2F53BC1ULL, 
            0x02196749C617F203ULL, 0x59B9C26DCCF88AE2ULL, 0x303E846EEF353227ULL, 0xEF22E580E5697A85ULL, 
            0xDB22A329F99E9407ULL, 0x0B45821F663BBF72ULL, 0x94051E1338BDCD1AULL, 0xC513CEC1D4CAD892ULL, 
            0x47BA38A9A5D554EBULL, 0x531554731E1D427AULL, 0xF2449B37E352E42AULL, 0xF81268341E4AF1A1ULL, 
            0xE85716E1C094CE3CULL, 0x45AADF08CF21C2FFULL, 0x183023D812890377ULL, 0x45D4B28E019378C6ULL, 
            0xFE00B53ACD78580FULL, 0x75FA435BF55013ECULL, 0xCDED07FA3382073FULL, 0x97FE0AF219FB0935ULL
        },
        {
            0x5C273ED68B326034ULL, 0x0B6B214200E81AEBULL, 0xA5C7D388F54F2A68ULL, 0x3DB9AA81D53BDA93ULL, 
            0xE7CCCA41A1C7AB31ULL, 0x9E9096ADA49F9814ULL, 0xD857C227CB5C31F3ULL, 0x94B86A3DFCA9CA0FULL, 
            0xB2AEB08886B7A078ULL, 0x380B12A00EE6E07AULL, 0x8E2FE8911945DF52ULL, 0x0A2F0460130FD5C3ULL, 
            0x3D59D51400650624ULL, 0x556F87BD903BD73AULL, 0x19C74F6122B59AABULL, 0x0A4AD223CD221E66ULL, 
            0x04D6554F11B10EDEULL, 0xE7A0E8AE76EC8BA6ULL, 0x784D58915CD8B401ULL, 0x5D895EE30895F7C9ULL, 
            0x50C663DB8D0CD427ULL, 0x4701DDEF559E609BULL, 0xBAEA43EAA2953DDDULL, 0xDDC484BAC29C3313ULL, 
            0x1BF12E954BE0B159ULL, 0xC5701112C21E274CULL, 0x4B9668263574E56AULL, 0x7631AF8AB1DEFFF6ULL, 
            0xD31B2AA5007FEF78ULL, 0x06EEE7A890069287ULL, 0x5C25B2C09998E092ULL, 0x43D2FA202E465866ULL
        },
        {
            0xB8723C256E7000F0ULL, 0x997FC5228E91BD21ULL, 0x40C9A8BA0742B7CCULL, 0x3E67793764FB8157ULL, 
            0xBD70112A20A3EA8AULL, 0xA58AD778B7D8005FULL, 0x797639E82357765AULL, 0x5800887A2837ABDAULL, 
            0x7E620A8130EFCBD9ULL, 0xD1EBFF18686128B8ULL, 0x9A8405F398E73231ULL, 0xC189954FE14D16ECULL, 
            0x85438E4A080AEF0BULL, 0x703153F55C612B0EULL, 0xCF3D1FD5FE70E539ULL, 0xF5BE55111542201BULL, 
            0xD0B76053666B0681ULL, 0xDC3BF00A9EC97FAAULL, 0x47615FD82DA820E7ULL, 0xAFB06F2EB5B5659AULL, 
            0xA6CCACB9B59AE5B8ULL, 0x2F451C1F2795E4FEULL, 0xF4BADC46D4D58417ULL, 0x588BBA74CB2D2422ULL, 
            0x01844AECBC038679ULL, 0x5163D3FD11842D4BULL, 0x3DB69A3B7DF986DDULL, 0x24F7D08ECE48C751ULL, 
            0x2C3F625A3E9D03EDULL, 0x5B9D3ED71D816127ULL, 0x84B62811F6D5D3CCULL, 0xEED9C1E391ED9A85ULL
        }
    },
    {
        {
            0xB758DF2CC9EB0116ULL, 0x087CABE32999C442ULL, 0x1E0D58437F79B5BFULL, 0xA0AE24D825AC9483ULL, 
            0xD3BD407A484CE723ULL, 0xDB51E4B6E82A1218ULL, 0x5CC33E2EC0D4BB7BULL, 0xC53FF48C3ACF930AULL, 
            0xDA778EFD8873CB7CULL, 0xCDCFFE0C60C56E09ULL, 0x7CB1C0B1D09A8C84ULL, 0x587D678510761137ULL, 
            0x325C2E75039EBFFCULL, 0xB456BCD5EC884E38ULL, 0xC2289855D75338E5ULL, 0xF5EC72246286EF1CULL, 
            0xD9D8D0B173F93367ULL, 0x499079AA351F588BULL, 0xCA7D66B24E385ADDULL, 0xF9D439ED3A7765D5ULL, 
            0x03B3B0002179D486ULL, 0xF23952018954A90CULL, 0x3689D400321B7638ULL, 0xCA0D88CF64342587ULL, 
            0x7F498BD5D52C024EULL, 0xF6165EC7F7B4D6F7ULL, 0x47A270D6991517B3ULL, 0xB8981943DB4021C4ULL, 
            0xD0DBADB9BDEFE3D2ULL, 0x1AB8BA6DDA82C582ULL, 0xE0666A17BA11C4ACULL, 0x3E03D0ECC4835AECULL
        },
        {
            0x6DD133C94E9AC539ULL, 0x90CC3DE33F540D84ULL, 0xD83F71727250917EULL, 0xCD5CA3A8FAA7D790ULL, 
            0x71476FEAAD2C462DULL, 0x983327945D15EDB7ULL, 0xC218327297D309E2ULL, 0xBDC46B5BB117860BULL, 
            0xDE963F65AFD1A697ULL, 0x9F6E3DF602A19E40ULL, 0xDEB22EC23055ADE3ULL, 0x28A0737BAC326069ULL, 
            0x4F88FAFD788A5C9CULL, 0x0B138B93C8893064ULL, 0xB5F07A47F30D76E3ULL, 0xBCAB06A79A8BE21FULL, 
            0xFF762A664541D51DULL, 0xCB50C288578774B6ULL, 0x3650728FEF1A397EULL, 0xB919FC9F8A854354ULL, 
            0x0533D7FF25E7253FULL, 0x9F2990EB0F1B04A7ULL, 0xDEC0176C77F9F8D5ULL, 0xCD66656C49862493ULL, 
            0xBCA063B9377A07C1ULL, 0x805BD3167422F22EULL, 0xC8F3730BFD80954AULL, 0xCA45DDD7C9DF0C35ULL, 
            0x1D15921C6635B00AULL, 0x4BEFD786782EF4DEULL, 0xF4CD0962126210A1ULL, 0x6363EDDE4811A477ULL
        },
        {
            0x52486B5735FBB5A5ULL, 0x478969A3A0D8E5DFULL, 0x27E488B61090BE34ULL, 0x600AC83E64E2ECE1ULL, 
            0x30336CCE74D44E89ULL, 0xF15814018E2EA796ULL, 0x99B5078B95D1ED26ULL, 0x0BD9C0A316ECC6ABULL, 
            0xC3CADBC1BCA45997ULL, 0xE2A8A880942EB3E0ULL, 0xB2723ACB938187D8ULL, 0xB8DC1612A1A8CE30ULL, 
            0x92D82667C7E1DC65ULL, 0x92095490C7DEB62EULL, 0x4837D9364B7561F8ULL, 0xE01556E333019913ULL, 
            0x2FD5082977D4F9D7ULL, 0xE3FD09611FEAA0EEULL, 0x5071A4451D5FB853ULL, 0xC03A2611B20CF79DULL, 
            0x7BB0E7412DE80B33ULL, 0x2CEF0E951C45E79AULL, 0xB395DFBEB9E61C47ULL, 0x3B1A4C628605468AULL, 
            0x7D821F3E3644A1E3ULL, 0x6675ABB6F4CB09C5ULL, 0x775CF22753BECA15ULL, 0xC4E800F9AD42346DULL, 
            0xA05A528E0B684D95ULL, 0x36DAF04096FE0868ULL, 0x027246159B4228A8ULL, 0x99B24A3EBA5917BDULL
        },
        {
            0x97BDDA2766F1EB8EULL, 0xE0FA07CC6C16359DULL, 0x571BBB1C1615B8BBULL, 0x78F997758D30E3D0ULL, 
            0xD04A5A26FC628408ULL, 0x1ADBFDFE4452C81FULL, 0x33C7B43FCC0CFAE4ULL, 0x531130687FA8D05EULL, 
            0xF7541A49A6F93034ULL, 0x21E086C113D1CD43ULL, 0x322F5053433594B7ULL, 0x3F31815BD36500E4ULL, 
            0xE54DBE956C30C33BULL, 0x2604035811600CB6ULL, 0x7967BC2E9D92201BULL, 0xD30B06534B7C1116ULL, 
            0x4BFBDB738C1F49D7ULL, 0x64CF065C0C10168AULL, 0x7D8CBC7E8D8E6D8AULL, 0x62FCF96051D330DBULL, 
            0xB060424E3FA485D8ULL, 0xA8361DD89F82CE25ULL, 0xDCA51D7FE3CB8BCCULL, 0xAA9D90579740955FULL, 
            0x88A34DEC39BDF184ULL, 0x0C554DAA6F66ED09ULL, 0xF9EE6E3743C7FB6DULL, 0xBBEC8E5782FBAB3FULL, 
            0xBED6442A3A798801ULL, 0x597872A45938B935ULL, 0x1AF3802B959D02CBULL, 0x2631CFECF585991AULL
        },
        {
            0x55476F90AD7C880DULL, 0x53241B1861228035ULL, 0x55C68706ECE7C36FULL, 0x32410DE49FBE1590ULL, 
            0xAD90CD9CB84F0D2AULL, 0x34813BED6386F9A8ULL, 0xBA1CA537CC5CF687ULL, 0x8FD384FE33CA837CULL, 
            0x2CBF960C208E4514ULL, 0x784D9119F67D7ADEULL, 0xB129E5C899BDC648ULL, 0x170B481E1360E807ULL, 
            0xCC5BAF62F1CE85FFULL, 0x841922AC091D1426ULL, 0x2BF3B8B1467A8815ULL, 0xBFAA0A300FC57093ULL, 
            0x850F759EDE51EC3BULL, 0x1213C1FC3511342CULL, 0x3940186BF0AA9C7EULL, 0x3EFBAA700A3C7B83ULL, 
            0x19ED694EE0BBD37BULL, 0x1CD4F2508FF2E5E4ULL, 0x89BEF7895FA1972FULL, 0x9DB48F9C25DFD134ULL, 
            0xF2A8389698C5FDC7ULL, 0xDE34B89357D393EEULL, 0x1730DB321B379652ULL, 0x588E1531671E9063ULL, 
            0xBF4BF2FF0E9E4A13ULL, 0xAD0263AC58B51286ULL, 0x90F46138B1464D5BULL, 0x3DAACFDB27CDBCFCULL
        },
        {
            0x23C19788B5E96B73ULL, 0x1BD419BB117E181EULL, 0x3141FE3A7B512C9AULL, 0xDC2B4DE3857CFCD3ULL, 
            0x608686E1F3EB6104ULL, 0xE90A5BBB807B105FULL, 0xD752F2A14FC11F4DULL, 0x4C074C38DBE3635FULL, 
            0x97EAE6B2BB9B06C3ULL, 0x4A5D4D8FE5292D81ULL, 0xFEB4EF079E1E1477ULL, 0xC13B364D693354FBULL, 
            0xC813F61899A6EA83ULL, 0xF86EED123D04C172ULL, 0x61F1C4B534F7D48BULL, 0x8C6CEBADBC2A8999ULL, 
            0x9B67029FA6149676ULL, 0x6A73868E41E98849ULL, 0x6FCE35FB43D16C88ULL, 0xCF9C2FF753F03D67ULL, 
            0x8BD44DF84F4B6A0AULL, 0xBA503975A0EDBC5DULL, 0x330D33E33C77678FULL, 0x3F7A92FAC979FCAAULL, 
            0x93D24E4B8F4C3A2CULL, 0x211DE4FBDC2BCB01ULL, 0x27B8DE35A71DA3D9ULL, 0xE9D872829A1D98C9ULL, 
            0x1D05AE4095AE013DULL, 0x65090B440F8D0BB0ULL, 0xEB53627C08C91B95ULL, 0x90AFA7ECC19B458AULL
        }
    },
    {
        {
            0xF9791C052E7798D2ULL, 0x42765E0C5AAD250DULL, 0xF2506965946243A3ULL, 0xD1EA049D4F74F03DULL, 
            0xBDCE08ED7F4E42A5ULL, 0xA966AB69AD6FF9ADULL, 0x1084624D0FA0F275ULL, 0x141779349480A8B0ULL, 
            0x7FE64F798A2A817DULL, 0xD1686486F19CC042ULL, 0x863E5AF77DE2506CULL, 0xFB584D2B3867824DULL, 
            0x2299DA9F81926044ULL, 0x1EF1A03F8017071CULL, 0xA4ADC5FDCCD4FBD6ULL, 0x6F6D1009960CBD13ULL, 
            0xE052F177F709CD5FULL, 0x5218DAA48502DDB9ULL, 0xACD6359E2A0BA886ULL, 0x8726E6F536B9FFD9ULL, 
            0x2F5389CB919C6F4BULL, 0xB8B9AABBC79658AAULL, 0xC26057315374511AULL, 0x0676958FC36F71B0ULL, 
            0x179F56C3ABACB471ULL, 0x3A29B55B5036AE4DULL, 0xA87278836721C96BULL, 0xA39261793A92E3DFULL, 
            0x434ABF9333AF386BULL, 0x5241CAF5DC31ED2AULL, 0xF6BA0DEF689EF147ULL, 0x2CEBAC0001ACCC1FULL
        },
        {
            0x4DE6DA6DBBA4F4E1ULL, 0x3CF7BB7A5D6B2B50ULL, 0x79E6AE315EE31162ULL, 0xAD8E68A836014140ULL, 
            0x3350F4BFC34EC691ULL, 0x562F140E98E4DCE0ULL, 0x5A8839185EB9A510ULL, 0xEFA6A87367CB0A77ULL, 
            0x9FBCEC988ABCD33BULL, 0xE328AAE2DEC5CF6EULL, 0x5FAE4FE0C9F98DC4ULL, 0x7471604421229ABEULL, 
            0xC27F20F382DAB520ULL, 0x67BFB2F3CD366D81ULL, 0xD2BA74E0B7976780ULL, 0x8B015EADE8404C77ULL, 
            0xF06488314BA7ECB0ULL, 0x638CB50C17FC0204ULL, 0xD9793E3DC6CB79E9ULL, 0x8F0989014390FACAULL, 
            0x17312D08D47A099BULL, 0x5E493BF85B1EADC1ULL, 0x18D413A2C437D47CULL, 0xAEB6C87697575BF3ULL, 
            0x7911C5A8943DABD2ULL, 0x7A67397AF95BAB44ULL, 0x093C6E4D71001B2BULL, 0x1DA8CEC4DD7FB30FULL, 
            0xFEFD8267136A9AFBULL, 0xDA410BC6295C1EBFULL, 0x54AE1B49D66FD09FULL, 0x828F094FE9FB6C6DULL
        },
        {
            0x9BC886CFF1EAC416ULL, 0xC677FDFC21EF0FD4ULL, 0x3178072941415BBCULL, 0xF2B5F014FA242D90ULL, 
            0xCB59D3CC07001E9BULL, 0x513BD6BC8EB66518ULL, 0x8AAE1C6D0538F324ULL, 0x2D9DC6C8B022DC42ULL, 
            0x8A35D339A7531FCAULL, 0x3C70689E73706420ULL, 0x164FD7A772A00C0AULL, 0x02499547A7BE71ACULL, 
            0x51C20C260DF86A56ULL, 0x3BE0DB80095C68D3ULL, 0x3C839E5BBF3851DCULL, 0xE6FC73173AE258BCULL, 
            0xCD8C6E5D654DF965ULL, 0x104FFC20A578AF89ULL, 0x00A73F16F2611726ULL, 0x2D0542511C282D36ULL, 
            0xD316799837DC53A7ULL, 0xF30A91200FACE0F2ULL, 0x7B8B58D3DAAAA60AULL, 0x3421474B1519EF08ULL, 
            0xC14EB182010CFB74ULL, 0x9BC326E322786F2EULL, 0xBA69C2CC5E78B2F7ULL, 0xC507E9BFB4DD3164ULL, 
            0x1AB998FEECA51A2CULL, 0x3340F1F81B2BA4CCULL, 0xD312FE4D675D995FULL, 0x0AAAE4722499E32BULL
        },
        {
            0xF798F073038FF765ULL, 0xD355EAF0D13DC029ULL, 0xD0279A3256B204DFULL, 0x9D021E7E38A3460BULL, 
            0xA5259DB5402DEA00ULL, 0xA8569F2F8EE61ED0ULL, 0x38E576921A54E4ADULL, 0x9E6ADFB7C0E27355ULL, 
            0x9FA5F138EF3B45F5ULL, 0x119A23D2E21E1D72ULL, 0x552A5C32D65DC94DULL, 0x0F90B21115247881ULL, 
            0x38F671178AAB2361ULL, 0x8A5B0B7016E24A2CULL, 0xC3A85F7F33F19DFFULL, 0x486A3DB1B18380A4ULL, 
            0x2B7660951455A573ULL, 0x45771DB7D1C789B5ULL, 0x7D6B7AAA9CEBA131ULL, 0xD86B490C9FCFD69DULL, 
            0x36090DFFE0CDCC0FULL, 0xAC421720803B8A5EULL, 0xB76F57ACBA9DB56AULL, 0xC7D2510464CD1782ULL, 
            0x9A041B4A1E2D92F7ULL, 0xE21A198F244AB696ULL, 0x5633F81AF6681F8BULL, 0xCE3F96BA795B4FE5ULL, 
            0x9F5A265283C41926ULL, 0x2E6B234AE0CBFCA8ULL, 0xE653E027F4D4C4A8ULL, 0x133496677F905E31ULL
        },
        {
            0x831AE2942520ED72ULL, 0xC2542B474C912DB9ULL, 0x5A3FF1A2B69B1FD8ULL, 0x8AB266A4F5CAB6C8ULL, 
            0x76F0D8BA6F74F838ULL, 0xD960CB48755EBD07ULL, 0xAD12F3AE0DDAD1B7ULL, 0xDAAD8E7796F75111ULL, 
            0x57B27601601217AAULL, 0x91E89A2FE39AD32BULL, 0x227B209DF31E2F81ULL, 0xD4E751227479E9B5ULL, 
            0xD34EAFC23333A18FULL, 0x32E698AF63A2CE60ULL, 0x53C7ADC9DFA6A3F5ULL, 0x0C37109AA29C2B39ULL, 
            0xA6B7CDC826B8C91BULL, 0x9FB9B5980DA7EF5FULL, 0x804A2E92475059B1ULL, 0x6510D1F8BAE89392ULL, 
            0x1AB479C06744A096ULL, 0x63A4F27F9773E24CULL, 0x655C0ADA155153ADULL, 0x576ED2D56375E684ULL, 
            0xC782C6872F64CF6DULL, 0x17D43DE8FAA75045ULL, 0xF2B462D799A92B64ULL, 0xDE083D4CA0E6B0AFULL, 
            0x7E811225F00A3275ULL, 0x766C7DAD5E8C803DULL, 0xD9B72CC5D2841371ULL, 0x043684BF7A888240ULL
        },
        {
            0x5A759A07CC59BED9ULL, 0xC11A5757F7B791F7ULL, 0xC8E60BC4B0CE3816ULL, 0x23D475D4BFEDFB31ULL, 
            0xCF58B4EA1F3D0AD4ULL, 0x0A764FF1446B2C4CULL, 0xAB548329A67C93C2ULL, 0x00643590EB1CF1C5ULL, 
            0xCE4826EC711DA241ULL, 0x4B83DF30EF66B0F4ULL, 0x398A6EEA61600540ULL, 0x525A4B20ACC595E2ULL, 
            0x6A6F228C9CE67C31ULL, 0xF9B2759F95D33C4BULL, 0x777E20F030E2CA5EULL, 0x70B71DC681F8A67DULL, 
            0x96D8C2E48E802812ULL, 0x8BBFDCD82754FC37ULL, 0x8F32C150F955C6D4ULL, 0xB877C0787F5AE8B1ULL, 
            0x1923DFBEDA522340ULL, 0xB8C4D3E56FE7469BULL, 0xA358282814E32E97ULL, 0x2E377B96F67A58E0ULL, 
            0x36D7B87FF46B1024ULL, 0xFE18C4EB9997A3C5ULL, 0xBED3BE71606B1342ULL, 0x2FDBF2B423CC5DE9ULL, 
            0xBD5871B68514D717ULL, 0xB6C911D869481EB2ULL, 0x8C5A36571AC32E22ULL, 0xDCFE5CF1A4ABA353ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseDConstants = {
    0xE7719EF058F8E077ULL,
    0xBD6A8FC3A234A6D2ULL,
    0xFB1786E8D02C865EULL,
    0xE7719EF058F8E077ULL,
    0xBD6A8FC3A234A6D2ULL,
    0xFB1786E8D02C865EULL,
    0x97271B01B7B067A0ULL,
    0xC726438BC041BEACULL,
    0x2E,
    0xA1,
    0x54,
    0x32,
    0x6A,
    0xCF,
    0xB0,
    0x8A
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseESalts = {
    {
        {
            0x2D882459A2B2F593ULL, 0xDF1F22AEA7B4D07AULL, 0xA3D5E978DAFB0E9AULL, 0x59E04953008269E9ULL, 
            0xBF06BB507A085C4AULL, 0x072D2E386E595372ULL, 0x11A874A6F3B97CA2ULL, 0x42580F8D320302ABULL, 
            0x3A1DA0C71210FFC9ULL, 0x0D88C863301E5B9DULL, 0x5B53A085CCFF8F38ULL, 0x410126D8528220EBULL, 
            0x2D89547DF5F719F0ULL, 0x6C7B1495B9680031ULL, 0x19C1E532506D87F1ULL, 0x7F05E7D820412101ULL, 
            0x3B5C3F6F7F3BB55CULL, 0xD9263A6DC6402BA6ULL, 0x427E28D8B9BE2405ULL, 0x4F51BC9AE91F1BACULL, 
            0x9A0A203FF1D592F7ULL, 0xE0AC92B81BF7BA82ULL, 0x5C83ABE835B1F666ULL, 0xD843E59A6A547D27ULL, 
            0x19999EC1A95E361AULL, 0x05C3485328280B16ULL, 0xB4104229038D514AULL, 0x5E3298FC77334D2DULL, 
            0xF30AA921A5C419EDULL, 0xFC4837E4D33FD263ULL, 0x77FF6ABF94D99EFDULL, 0xEC844E45FA6A5CDDULL
        },
        {
            0xB57A6092905518BEULL, 0xF4C4A045C164D2CCULL, 0xF31E2721DE9392A2ULL, 0x8956CDA8C7A404F6ULL, 
            0x62746CE43571239AULL, 0xD89EAEF6FCDC886BULL, 0x1752E41A6E21570FULL, 0x4D131CECC008FE32ULL, 
            0xC0EE345FC7230C9EULL, 0x457E10BE3F44F25EULL, 0xFBB8CC8FEC6FB74DULL, 0xE54C3B574DB4E740ULL, 
            0x3CB40A9588DBFFCFULL, 0xD959EFBBEC20004CULL, 0xDA42999C67995D56ULL, 0xBBB731ECCE2628E9ULL, 
            0x00D1DF4C26D66749ULL, 0x3FFF3E4ECD09272EULL, 0xCBFBF4076FBE1DEAULL, 0xDB97AB0C6A0A7C8BULL, 
            0xCC2BAC308F54909AULL, 0xF5FAABC64817D5FFULL, 0x7637E8825FDD0AE1ULL, 0xB2D7FF86771A81A7ULL, 
            0x6703501B418DC9D1ULL, 0x3508A6D429F871EBULL, 0xB4CA6A3590A36DD2ULL, 0xE8497D5846C05587ULL, 
            0xB27E7C6F02F14B15ULL, 0x0296D65D82CDD7A5ULL, 0xDEDF7D26E5A12BA9ULL, 0x82C2F3EE2D15B9F6ULL
        },
        {
            0xD76B97FD94790AACULL, 0xF888FAD9AF3554E3ULL, 0xA5A6E49DDB3EF6ECULL, 0xF9028618F41BE08EULL, 
            0x07F07C41FCA891EFULL, 0x1B52A96E08F2C5A0ULL, 0xE0018A4D5B9779CBULL, 0x0F9EBE82FADEA0A4ULL, 
            0xBEC294D61EB3D787ULL, 0x5713464A2885B178ULL, 0xF7F9BD87A66C9EE3ULL, 0x6B54BF5F3CA9E6B3ULL, 
            0xE6B7C74A5A4D5B43ULL, 0x08A35C2FA3EFF705ULL, 0x33C81F9DEC6160D5ULL, 0xBC6EDF1630B71BE2ULL, 
            0x65E625641125A365ULL, 0xC5CDE3C83F14304BULL, 0xC1A83ABB87FB490EULL, 0x7E16B519FBEFD89FULL, 
            0x124D873B7584F10DULL, 0xD4D8D66034225C74ULL, 0x931418FEEAD7F747ULL, 0x6633B7BD25C0831AULL, 
            0x08C80B3227E2542FULL, 0xDA174AE377CE4762ULL, 0xB780BDFC6FCEC1A8ULL, 0x54A0C27FE866A10BULL, 
            0x51E924B972C34F1BULL, 0xEDC5774FDE9D13C2ULL, 0x50301EFDD9EA15FCULL, 0x9325419E5E0D9B24ULL
        },
        {
            0x906C84E80BECD840ULL, 0xE8B4E18668A1AF9FULL, 0xA9ED7CF951C6B0EFULL, 0x855DC6EA56FB6455ULL, 
            0x93B51729A5365A8AULL, 0x85BE4CD9D8D92BB5ULL, 0x9D31DEC1B6D6970BULL, 0xEDEA34116C9BA49EULL, 
            0x1F080B47E92BFEDDULL, 0xA8A1A05E8D57F74AULL, 0xEA650C5028A80D51ULL, 0x1E28C25B92DAF1A4ULL, 
            0x1E85A98572BF549AULL, 0x5E194B0A0950A199ULL, 0xE064090B11F4F21EULL, 0xB8E77CD1B5924035ULL, 
            0x53101749F7A6B4C8ULL, 0x7E892D3661524908ULL, 0xCE28FFA192F45371ULL, 0x8ACE086795EC4DDFULL, 
            0x9246F2228681AF79ULL, 0x593772CF163B7FD6ULL, 0x0E801A7FE0B67868ULL, 0x49F8AA65AD68194EULL, 
            0x030C023A614CE459ULL, 0x3607A12DC8B4AA54ULL, 0x9B2DFF0655F7575BULL, 0xC34BD417C8C995E1ULL, 
            0x2C91792D50C1B340ULL, 0x74DB89CF5E8FE513ULL, 0xE06C850E10D07F03ULL, 0x4EC0A9B0348EFDA4ULL
        },
        {
            0x2E5C61305ECFED2EULL, 0xE209585204409C55ULL, 0x7B1BDFA61A7D01E7ULL, 0x2B397D1A58B0DB4DULL, 
            0x9D820C96858BFA57ULL, 0x4A9B37E6EDE34369ULL, 0x55AB92D665EAF0E9ULL, 0x047E20317393B677ULL, 
            0xAA3A5361B0937ACAULL, 0xA43DBEE08432231AULL, 0x224F49CEC274CD66ULL, 0x827F7E6CFC6EB9E5ULL, 
            0x481B5F290809BEDDULL, 0x711753B39CCC144CULL, 0x8EAA2B07558C1F73ULL, 0x3FD17163EB2A304EULL, 
            0x9F81BA039D252A12ULL, 0x5FB6A2BA26E9E622ULL, 0xF012FFB90EE8A465ULL, 0x9704BBCBA3D4FAB0ULL, 
            0x63DCFD1C6B87BDCFULL, 0x25DA05CDE5F607D0ULL, 0x0073A9D8D87EE880ULL, 0x0AF01E04E047BBCDULL, 
            0x655DE8CA58341A36ULL, 0x181842B826431E60ULL, 0x998DABED946BDF81ULL, 0x66D677A058DF1E6CULL, 
            0x4EAB2EE19F677A0CULL, 0xA0BB2AE892F86815ULL, 0x78479B45FF34A8D6ULL, 0xF14717DE0E564E2FULL
        },
        {
            0xD11EED311858CD6BULL, 0x7DFFE85B8F0EC739ULL, 0x48AC8297E221202DULL, 0x6996BBF86AADDD93ULL, 
            0x6F68648EBDAAA602ULL, 0x3FCFBCA79E0E7860ULL, 0xC78AA9688A56DC5FULL, 0x683245FE178F65BFULL, 
            0x22467DBC50862843ULL, 0x1A74CD953E21B6BCULL, 0xFB4EA582355DC189ULL, 0xEB8D2EDA79584B59ULL, 
            0x19066950C0D4DA32ULL, 0xA87BC7848F1C9088ULL, 0xFD5EC05E76815AABULL, 0x570EAE0A92AA6DA8ULL, 
            0x48C84CD8A1C9739DULL, 0xA653A48C7F769AFEULL, 0x16947A6060404E26ULL, 0xE67466535CB3922FULL, 
            0x52ADB9189FBFA76DULL, 0x826FCBECC532515EULL, 0xDD977D9EE1C22564ULL, 0x0C0B6C86CAF010CFULL, 
            0xED70FF10F221ADB5ULL, 0x2E64A93F73E36620ULL, 0x483CAA2DA41EAF93ULL, 0x2589CD68CA05042CULL, 
            0xBCEE500BC1928FE4ULL, 0xA9B9D4B1AA75D31BULL, 0x5D7A44E57A953143ULL, 0xC5CBEA7D87BC9BC5ULL
        }
    },
    {
        {
            0xE576BC9B52BCE4BFULL, 0xD8BDF601464F4463ULL, 0xA5D521DA3D5500D4ULL, 0x5952078BF2B38006ULL, 
            0x8E97EB6B949C1CFAULL, 0x188449C919319670ULL, 0x8CBCB1FFAF793E2DULL, 0x086D491EFF3386F9ULL, 
            0x8B1AE7DB70F9B3C1ULL, 0xDC71B925CA272D9CULL, 0x7CA3B960E4207C03ULL, 0xC1394F3F0B6D9D11ULL, 
            0x6429A9B768FA46D4ULL, 0x7FC17E51C1A16730ULL, 0xB25A0ADE9C679FDAULL, 0x734BFCBAE4E8B420ULL, 
            0xE2A48FF73AF51AEEULL, 0x46A95384EF73DE56ULL, 0x09E27ED665751720ULL, 0xC2B8E0951C2532A2ULL, 
            0x366C1D2463D1EC17ULL, 0xE5461BB87D732097ULL, 0x13893E8EF7FDC92FULL, 0xED1508A25F11C1D8ULL, 
            0x173F1215262F28E6ULL, 0x62E89297FE86ECBDULL, 0x12D3434C7FBB85D2ULL, 0x2999DAD91A833A13ULL, 
            0x0D6B40A6892746A1ULL, 0x87B383CC77D4BBF9ULL, 0x85C79FA5AF7BB2A9ULL, 0xE0444F3F93F0DC04ULL
        },
        {
            0xD845B8D0395A543DULL, 0xCBEEEC5613497F81ULL, 0x7D8DB8E2D0B9EA68ULL, 0xB92718E5D63597E0ULL, 
            0xA895AD189D1C4BEEULL, 0x4072195C9F9E4303ULL, 0x42D73F0082AEC429ULL, 0x3E61FEF95E5CD7B0ULL, 
            0xB354C7B88360F140ULL, 0x9B12B0D6908F6D63ULL, 0x17BADCECB2D958CBULL, 0xD127274B5ACE9C35ULL, 
            0xE10737B26CAE5B3CULL, 0xBF1B84755A50A099ULL, 0x86B73A7C0557BC5AULL, 0x94C1EED3EB56613FULL, 
            0x4B464FE99302972FULL, 0x8A273876CC48687EULL, 0xE2F2119FDAD3846FULL, 0xF56E1A65A06E23C0ULL, 
            0x6C8F8EB9FEAAA43DULL, 0xEEDCB88015D41421ULL, 0xC391A7E60F06CCB9ULL, 0x34F488A26A3FA506ULL, 
            0x64E761CEE4E50C10ULL, 0xC56958AE302AA3DEULL, 0x29E66F200A61A819ULL, 0xCABA810A8648E465ULL, 
            0x1295EF5CA868C0F8ULL, 0xC17C0A1BEBEFA667ULL, 0x0547F4CAC46E6C6DULL, 0xAA21D295E8FC3211ULL
        },
        {
            0xD806E3E578BE584FULL, 0xEDD61E1BD956361AULL, 0xE88EE57BBC89AF55ULL, 0xDD4746E31D0ECD47ULL, 
            0xE8DCC3184DCB8C85ULL, 0xD7C4CA572077259AULL, 0x5FD21C9DAF19C2FBULL, 0xB15B929C0F2558EEULL, 
            0x43160E5B1C40489EULL, 0x65D52E0D2ABF3AA7ULL, 0x073E4C143DEE5175ULL, 0x246C1F55886AC18AULL, 
            0x7493A11B00E6CA9FULL, 0xFA2F27157D40A292ULL, 0xE666524279E7DAB8ULL, 0x59ED4FC4656ECE2CULL, 
            0x0BED45578B0921D7ULL, 0xD03E22CCC2EFECB8ULL, 0x5993ADD43AA19F82ULL, 0xA6A62DBA79D69584ULL, 
            0xFE180C20B44968B2ULL, 0x43B2803B90382759ULL, 0xE3D10BA036B8B428ULL, 0x8DF1EB65EFCAA778ULL, 
            0x3C80114D476147AAULL, 0x0413E71977BC9BA3ULL, 0xF59C265D148ABCADULL, 0xF7857BE44E2D5196ULL, 
            0x1FB33486ED274699ULL, 0xE5C5082CBF27DC33ULL, 0x100E244B421E8444ULL, 0xF1AF56FC4AB5A734ULL
        },
        {
            0xF135F4247347D73DULL, 0xD850ADA8B6B1859CULL, 0x5E7AC31ED3DE9836ULL, 0x4B441DDCDD65D2A4ULL, 
            0xB59156C347A7EB05ULL, 0x90EF3E81B07ECC20ULL, 0x6042ED09073371AEULL, 0xF481A50002CED05EULL, 
            0x85CB8EEE99A04E38ULL, 0xC18FA85788FD692BULL, 0x448B35E5C723E031ULL, 0x9ADC6B6B0F540A81ULL, 
            0x9D93C3B732CDFD59ULL, 0x74DF80717AB5F326ULL, 0xF95BD2B401F8026AULL, 0xE0256661D0A57EFAULL, 
            0xDA3994902BE22C3BULL, 0x354B495D5BCBB9CFULL, 0x6B5B098684467F3CULL, 0x85E9B537F44CB83EULL, 
            0xA2E57E0D40EB9C32ULL, 0xF00DE8DF72A69F2FULL, 0xC1C8546C011A6ED0ULL, 0x9A8F70A8C279F8D3ULL, 
            0x72E87BD8AF2644BFULL, 0xDD09AC3EDBF1A223ULL, 0x513970F2B644B9BAULL, 0xA0DF8E17B5BD72EFULL, 
            0xF588A73EEF98604BULL, 0xA4B3E71D533AB4F1ULL, 0x0B93F386E6454BFFULL, 0x6FEC66346653EA37ULL
        },
        {
            0x37E854108C761948ULL, 0xF96566B7ED953742ULL, 0xF0CD72E831E7D48EULL, 0x39BA932A137553A0ULL, 
            0x4B2F91CBF3228191ULL, 0x51A78269A5BB7BF2ULL, 0x9896F7F624CFBF4FULL, 0xB065C365E4DE6650ULL, 
            0x797BAF5837753C9AULL, 0x668CF848326EAF58ULL, 0xB2B188010C5457D3ULL, 0xE8879F7AAA83CBACULL, 
            0xF945DA24A5711F1AULL, 0xB3E263657C64F528ULL, 0x676C296CFA3FA35FULL, 0x03A9141AB9B21EEFULL, 
            0x3F62BD80FC90378AULL, 0x733D5DB610DBB0F4ULL, 0x4972E8A228D32E79ULL, 0x4272F0216BE8E44BULL, 
            0xF47412D32F61A76EULL, 0x3125DEAAFAA72EB4ULL, 0x5B423B2E8AE2F052ULL, 0x7F8F1B316E3AB115ULL, 
            0x4EF47B8E459A1030ULL, 0xAEFD46037A260658ULL, 0x208A9576BD251D53ULL, 0x2119E3D5E4BE0CD1ULL, 
            0x624CAC328B75CC25ULL, 0x72E2DF6858FF2B24ULL, 0xA7EA1DA4014F6829ULL, 0xD176AA6243F942EEULL
        },
        {
            0xA14377ED08C5C74BULL, 0x901022459D95C7EFULL, 0x843CD856BF2E00EDULL, 0x878070FDC0368F07ULL, 
            0xABFA0B3C1871C78EULL, 0x18B41F9587EEA5A0ULL, 0xFDAD9E10EFD0F3F9ULL, 0x2FAC056275D79D9DULL, 
            0xDAFD433D6F4CDA36ULL, 0x489718C05BE4F7ACULL, 0xB856B9EECC75B85CULL, 0xD8E7CFB12205398FULL, 
            0xA2A1AC8F1F1D09A5ULL, 0x667871E1D422C278ULL, 0x4A77596D95BB7288ULL, 0x5EAC14850192E445ULL, 
            0x426FF9C5E4F1907AULL, 0xB160DDFAD9347675ULL, 0x276932DD23EA83E7ULL, 0xAA66D3D7C0CB249FULL, 
            0x66639D0845CA7B70ULL, 0xB74396F3C17FF741ULL, 0x8AEFCEBB0F23B5ABULL, 0x7FB5DD66FCF8AE72ULL, 
            0x9121C720C4AC60CFULL, 0xFDC81A5B3E272259ULL, 0xAF3CD693F7864B72ULL, 0xE99721434C4EEAB4ULL, 
            0xC57D968EF79D2902ULL, 0x32A19955E136D70CULL, 0x521D7D47E246827EULL, 0x43ECA2A5C56FB78CULL
        }
    },
    {
        {
            0x1CEEFE497C661928ULL, 0xAE8A62C109E7E2B7ULL, 0x806937F909CBA0FBULL, 0x8697800B8C822A58ULL, 
            0x24D9EA8FBA9D6E46ULL, 0x44F3E5E2ABE7E0C2ULL, 0x31B02140AFC78CF5ULL, 0xFDF6FF8160811895ULL, 
            0xB8ABFA062409D9EFULL, 0x37CB0250FDB78E23ULL, 0x878CA914F47B8F24ULL, 0xD84F72F3D5651095ULL, 
            0x29F7BBFF3E32D4EDULL, 0xE6F0DD2F76F789E7ULL, 0xFA4F65C56EB9028DULL, 0x56B611B7F38733AFULL, 
            0x58B6BB700AD3FD81ULL, 0x1D4C605CBF69AAE8ULL, 0xA51B44FD615670DBULL, 0x28C06A9D0515A419ULL, 
            0x8C61D18E0552F68CULL, 0x7C6E369B4A5D3BB4ULL, 0xC11345BF646C4CA8ULL, 0x7C8E7F2CAC5C9440ULL, 
            0x5A2F239FEAF2BA99ULL, 0x54CD45881777A91EULL, 0x741F8CB2E09B9110ULL, 0x3DB8A6E8A321D7ECULL, 
            0xDA32D4204ED16DDAULL, 0x0E95067EF9C045DBULL, 0x5E61B73853CEC318ULL, 0x3331D64625782AFBULL
        },
        {
            0x02EAE225643DDF16ULL, 0xAA764660F4D946C0ULL, 0x4EFCBEAB56D95B58ULL, 0x56C41FF7AA2AFBF1ULL, 
            0x99D05A6E115F8B3DULL, 0x8C8FA436C3923422ULL, 0x36A5F6809A9DA638ULL, 0x4D0395366479B451ULL, 
            0xE82A3564BB47939DULL, 0xA80E0BAEF337820CULL, 0x4F0624B11632A967ULL, 0xE101318E6BA75351ULL, 
            0xA5D47FED9AEAF7ADULL, 0x8610EECE20669E55ULL, 0x36DBFC389D902C11ULL, 0x40C5705344ACFC88ULL, 
            0xD4B621DE96E62206ULL, 0xD3DFC596FC6524DEULL, 0xEDA6C7F73A9092ECULL, 0x7AA29AB72A8E91CBULL, 
            0x51A2549C5E2F151BULL, 0xB39EB9B0AB20BD34ULL, 0x6353CACBBCA455ADULL, 0x9C8E531879097649ULL, 
            0xB6A6F8FF9435B846ULL, 0x09CBA7C00121F144ULL, 0x83BA363FAB0629FCULL, 0xB1D3DBA3D055972DULL, 
            0x1698B799B62D2F4AULL, 0x88573FA4844B95E5ULL, 0x9C074CA79DBC2670ULL, 0x0153C67D22DD30B9ULL
        },
        {
            0x2EC5D3E0DFFB08AFULL, 0x6E26B5D40445F8F0ULL, 0x597C03FC672E7A7CULL, 0x2B6051DF3A733574ULL, 
            0xB19956D774FE0903ULL, 0x3FC982F2C32491BBULL, 0x56415DD7965F4E6AULL, 0x1565FDAB3396A54FULL, 
            0x694BCFD8AE621AF0ULL, 0x1D631997780845E5ULL, 0xB1E2C77837911185ULL, 0xB6A8F4067E2D44FBULL, 
            0x4B3DB05D7F0F1E43ULL, 0x72F1295D95B71550ULL, 0xD5C00C8327ACF005ULL, 0x3BC352E536BB478FULL, 
            0xFE7A4EF9675104AFULL, 0x5781A37B72511BEAULL, 0xFB07F1CD10F3F893ULL, 0x54AEF2C4B3789128ULL, 
            0x74A3DA8F3B4F473FULL, 0xFEC347E24D2E88C0ULL, 0xD7792540672A98E9ULL, 0x7BA44E5D9B692CEEULL, 
            0x92CD8189623BB5C9ULL, 0x0518EE2067FD7E10ULL, 0xEF53FFDFC371565EULL, 0x72EBF3591A73FB50ULL, 
            0x4B204D9AE91D0C1BULL, 0x990F7793B146E006ULL, 0xBBFD2B7AC9AF66F1ULL, 0xCF931A4389842B0DULL
        },
        {
            0x703B68C61A0E2A4BULL, 0x05A76179B38E8790ULL, 0x331E3F3AA1731577ULL, 0x956348FFC2CD81B4ULL, 
            0xED4AEDF94064DC6FULL, 0xD249BEBE04C0FD26ULL, 0x8637BD82E43B451DULL, 0x651D4FF7DEB1D571ULL, 
            0xA17615F917DED4C0ULL, 0x22D5E75BB76ADD1BULL, 0x37EE7E1DCE07775FULL, 0xDFF523CD12636B24ULL, 
            0x4205FB260E6E3B7AULL, 0x286A8EDF6F8C5B12ULL, 0xAC8A13E44CC7F807ULL, 0x4F8A616C4CD5C882ULL, 
            0x3877C17E68353C23ULL, 0x46562FA7A4E61BC3ULL, 0x8AC493C329EDD41BULL, 0x626C9E0187F33231ULL, 
            0x25EBA9DF0D0E862EULL, 0x774FCD3C69FD9A25ULL, 0xE2A682966C1D26C0ULL, 0x1A14E725C5198579ULL, 
            0xCD2AC190121218E4ULL, 0x86B2ED262B55C1C4ULL, 0x87479CDDA366A8A6ULL, 0xE1116C4E6E356B87ULL, 
            0xEC1C83D3C6A9F377ULL, 0x2FD16BD8C3EB5F13ULL, 0xC3AB5F0C63D777DAULL, 0x46E524FC435D7E96ULL
        },
        {
            0x4AB827DF95B141E1ULL, 0xD46290AEC371F11FULL, 0x57937F873125ADF7ULL, 0x86159C0222F7354EULL, 
            0x964748ECDE3BB4A1ULL, 0xF29400AFF9E3D70FULL, 0xBBCCC5291E6E6455ULL, 0x3E736DBA0407CF52ULL, 
            0x5D4854F189354B30ULL, 0xEFACFE582888A393ULL, 0x410AFC624AE41BBFULL, 0x4F9891CB2C3668E3ULL, 
            0x2A0B1CD1D576DEF4ULL, 0x58A14B3DAE825F93ULL, 0x860448E0DDE1010FULL, 0xCB15AD6B12B2D274ULL, 
            0x8F9A7F527F5D0B6EULL, 0xADD76A2B7D6812FFULL, 0x3C1B575BE553D529ULL, 0x2690D6BD13D79F8CULL, 
            0x44EA6AAB28276BBFULL, 0xE053FE4BCBD1EFBDULL, 0x5744D8955111DE1EULL, 0x2372E5A9557FE838ULL, 
            0xFAB05B19E1A534A2ULL, 0x5B51E39F383CF058ULL, 0xB5429F42711323A6ULL, 0x6684CA19F3046EB6ULL, 
            0x49C22940F244ABFEULL, 0x064A4B46FE8CD507ULL, 0x6F8E9D351FB0DDFCULL, 0x40AEB61F8FDE0E95ULL
        },
        {
            0x4198D7850430C601ULL, 0x1650F58A51EE57F7ULL, 0x716BF40A8D45F9CDULL, 0x4F514A6C5836A0C5ULL, 
            0x94B111D73DFEDB2BULL, 0x88697E0CD3042F19ULL, 0xBB524F3ADEAFEAB6ULL, 0xA64AA7A5F64DE581ULL, 
            0x10BF927DFFC9FB12ULL, 0x7DB7C16580C59E89ULL, 0x3F2A33DD477ED660ULL, 0x4EC77C2E93083FB3ULL, 
            0xFDAD7072D87E428CULL, 0x46ECFA95582C0FFAULL, 0x8C56D5A141E9B968ULL, 0xFFEA291D83CBE76DULL, 
            0xE20B72BA7A615E6CULL, 0xD2E15766E1BC70C1ULL, 0x8B1A6B2BB67979BFULL, 0x47C6B89FA947B38EULL, 
            0xBF29064C10B6147CULL, 0xA5BB4EC60011360AULL, 0xDEDD82B99D10E9C5ULL, 0x4BC09D5F54656CCEULL, 
            0x416736D5BF21FD54ULL, 0x54F2A5B2BF655277ULL, 0x3A905D07A589F657ULL, 0xC1AF04AB28E3450DULL, 
            0xAE5C407E0B506C90ULL, 0xF766D49A60FE61DEULL, 0x992E1F42C149DCEAULL, 0xFA9E63D96A1F69C8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseEConstants = {
    0xBB005AF6C1249DC1ULL,
    0x6AA467FF61461B9DULL,
    0xBFAC75DF79060893ULL,
    0xBB005AF6C1249DC1ULL,
    0x6AA467FF61461B9DULL,
    0xBFAC75DF79060893ULL,
    0xE5B5FD8C1D5E76F3ULL,
    0x2A147B2A054EFF27ULL,
    0xAE,
    0x56,
    0x3D,
    0xF0,
    0x9D,
    0xDB,
    0xDA,
    0xA6
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseFSalts = {
    {
        {
            0x2018045E8877752BULL, 0x37F64E96FCE1FB8FULL, 0x68E2AC67174F3C9CULL, 0xF6A07C906179BBA1ULL, 
            0x0C0EAA420984AF98ULL, 0x8A471E397FD901D1ULL, 0xAF854EE4991F7BCCULL, 0x7F71BCAA666B8B03ULL, 
            0x9067E2691E8C6882ULL, 0x7F73D820D15A1D63ULL, 0x480B005313AEE004ULL, 0xE25E3304B12EEA69ULL, 
            0x8AFCB2AACD1083B9ULL, 0x00D5484E29D0D709ULL, 0x1675F435D986842CULL, 0xE8765C5157CC648AULL, 
            0x329BE1B4F7D12BFAULL, 0x887AD7AE7B9D7879ULL, 0x47707F8D371BA129ULL, 0xCDADEF3E798725CEULL, 
            0x5084C7C0CE3824E9ULL, 0x6C7AA31295270DF8ULL, 0xE9CF0E5CE76A80BDULL, 0x4D535667107B7030ULL, 
            0xF642C889AB40CC6BULL, 0xD25702D8E777B4DCULL, 0xA5D146051DB8612CULL, 0x565572D9FA1BD713ULL, 
            0xC7C9C3CCF264327CULL, 0x3E1A8C84FAFA308DULL, 0x7A54367A6695A8F0ULL, 0x6468D760F89BDED0ULL
        },
        {
            0x3B3B139C720405EFULL, 0x3D8A2F7689F8943DULL, 0x3DCCE10F83AC14ECULL, 0xAC31D3155333FD0CULL, 
            0x5C0951166845B90DULL, 0x6CABEB9B639BCDCFULL, 0x00B051BC67D90C2AULL, 0x33C13A0C741A058AULL, 
            0x4477FDB1475C72D2ULL, 0x2E9BF49E90A6FB53ULL, 0x286FA7BA11DF9C9EULL, 0xECE61D926149901FULL, 
            0x0306BD5F5D0FE2ECULL, 0x2FA2BCEB2CC67F9DULL, 0x87B46DA11CDD8F58ULL, 0x74B5DACD4A2A5F33ULL, 
            0x7C65A0D3CF04C3DAULL, 0x0E89593109C7CFA8ULL, 0xFE934F988F2A1BDAULL, 0xCAFC51DE3D93C62FULL, 
            0x0FAF994FF283FB2EULL, 0x5F79D76CFA2FF896ULL, 0xAD476DC939CFDC7BULL, 0x450506FBCB22A979ULL, 
            0x56286B92F4EFCC7AULL, 0xB4FF1754D91D538EULL, 0xDDCBCA7CC8581516ULL, 0x106B42D187DFF53FULL, 
            0xFF045D706EB2517AULL, 0x164858E3B60FD332ULL, 0x74B2027215E67FCAULL, 0x64D038C1539B0CCAULL
        },
        {
            0x44F0E49ECBB2D693ULL, 0xEAA98EE4FA6BB6EBULL, 0x6EB8368F322D3E53ULL, 0x9D7F86301284B135ULL, 
            0x13B605EBD757212AULL, 0x66878524D17199E6ULL, 0xA77D45B22F5EED82ULL, 0xA5272AD61F720EEFULL, 
            0x9DD8AF2A332B7D22ULL, 0xD6FE3544AE7F15DDULL, 0x9ED2CF7CF60A1D58ULL, 0x724DE8DCE39D6773ULL, 
            0xCE6E687D6DE44E92ULL, 0xDA6C2E9BB4B3C85FULL, 0x31B211AE6340FA05ULL, 0x9CD37B0135C0DEC9ULL, 
            0x64BAF7BD916080A5ULL, 0x817408A0EFEF56E9ULL, 0xDFE21C18F1C39055ULL, 0xEAB58020058BD75DULL, 
            0xECDA91CBF816A6E1ULL, 0x4DF77AC44B96C934ULL, 0x586B28346F11DCC1ULL, 0x0C45F2989701AF2CULL, 
            0x1799FB493B91B32EULL, 0xC6D3D6E154D2EA0CULL, 0x1CC0AFA3FA8CA4B6ULL, 0x6C120807393B6092ULL, 
            0x9D9B30F96078CB42ULL, 0x683015E63FF44914ULL, 0x1E799ED8DCDA1B49ULL, 0x7B9FC2416A62E1D1ULL
        },
        {
            0x9EAD6F780CCF6169ULL, 0x925DAD64D6D2439FULL, 0xCA18D7CBE9448DEFULL, 0xD27CD5DDB1A45698ULL, 
            0xB6AF6447B820EEFDULL, 0x157BF831A7EEA5B2ULL, 0x56672B2DC9AE61E0ULL, 0x45ADBC881A5AF246ULL, 
            0xC659A21A8BE21449ULL, 0x7CC22348DD78AC12ULL, 0x9FF31E5D33A24C85ULL, 0x3BC5E81EED29E7C1ULL, 
            0xF207A8E8D4CC7418ULL, 0xA1F7F5A7EB4EA887ULL, 0x47BBD95C55FE214EULL, 0x87AFD4C1007224A2ULL, 
            0x5B93D71697DB446AULL, 0xC702B9E0BC774151ULL, 0x6A0F818F3FE0CFB7ULL, 0x7E28DCA988E7CC5BULL, 
            0xDC96939F6AE29FD1ULL, 0x87393C72D275E88BULL, 0xFE1AFE2C47F6A076ULL, 0xAA02CB2765E3A946ULL, 
            0xD62B9F8C5FAAE47EULL, 0xAD8E62CC7DB2EF50ULL, 0x79D3AFF1C9FE4546ULL, 0x35E6ABD52B37B41EULL, 
            0xED4C5CD6B1447ABCULL, 0x598F48419A8A3353ULL, 0xBB7824BF8ECBAC09ULL, 0x924416617A1568E2ULL
        },
        {
            0x6B5EEBF19F5E64A9ULL, 0x8F5A094D23C9B651ULL, 0x541A93E898EE48B0ULL, 0xA55173DEAC19CB91ULL, 
            0x3C18480D315A492AULL, 0x8940FF210780CE93ULL, 0xE6331D128E354E2BULL, 0xCC6D6C816DF6A21EULL, 
            0x8B389CFEFCE40F7DULL, 0xF011185AB9EA6B10ULL, 0x02AB7CB8E347471BULL, 0x5E6F5FFC8CD60284ULL, 
            0x5BC81F9B0EF1CA3FULL, 0x4AFDE9006FE7E13EULL, 0xA8FC43EDF784DD62ULL, 0x74A89284D3034E8BULL, 
            0xFB46443E9CF5FC86ULL, 0x1E041FE82FAEB9A8ULL, 0x6D340A644239250DULL, 0xA8F27311B9280F80ULL, 
            0x9DB5A3D003E461C1ULL, 0x3E797EA2D6EDA053ULL, 0xA0AF070CADE9815CULL, 0x87C9FB63215C5D9DULL, 
            0xA7DBDDE0127D6EC5ULL, 0xD9406CC26B36FF56ULL, 0x898323514A9738AFULL, 0x122FA58D930602A1ULL, 
            0x8E6C460DF324D94AULL, 0xE4006ED2CE6A306EULL, 0xEA4BFE86E5E4D19FULL, 0xDA6DB315E896FA8FULL
        },
        {
            0xFC8D36E147186704ULL, 0xCC8908B0D35D1250ULL, 0xE840A12C485746ADULL, 0x7A3A7841116FCF1BULL, 
            0x4E926DDDFF6CBBC4ULL, 0x404A81FBF3E1A6CAULL, 0x9A125AD4F14BFC53ULL, 0xA601AB47C102D27FULL, 
            0xEC269668468A4073ULL, 0x5E96589D4E311A79ULL, 0xBF9FFA2D92436482ULL, 0x9E3EDAC29F6DF0EEULL, 
            0xBB8F8593B544D103ULL, 0x82EF3261D13C8219ULL, 0x018D240FD17D0F44ULL, 0x531F56B422CF30B0ULL, 
            0xBB5F8CA23B3025C3ULL, 0x69635249EBD057F6ULL, 0xF3E99DD9D72A4EDCULL, 0x63B9610164164A4EULL, 
            0x448DBA1347FE2EDAULL, 0x13F5CC9CF9CFEBA9ULL, 0xB6E33F3E98612915ULL, 0x851B9373FD2AF0A8ULL, 
            0xD6495FFFB5796584ULL, 0x668A942F9FD8ACE9ULL, 0x74FBB786070F80E5ULL, 0x0E3B965915477D25ULL, 
            0x6FC100D5F13A8820ULL, 0x073617A43410F9CEULL, 0xCF635FE172772345ULL, 0x8576CA3184EAB672ULL
        }
    },
    {
        {
            0x4BDEBB606A7EC22BULL, 0xC0FA190DD7A7EB7EULL, 0x99796066552B81FAULL, 0xC6E5604330A5C8D8ULL, 
            0xAD0316261BF50BC6ULL, 0x64B3D24AFABB93B4ULL, 0x4186B199D4EBFA1AULL, 0x3C8E4E62DF02E6B7ULL, 
            0x6FA972E6E9B0BA10ULL, 0x45DE76D6B5284E93ULL, 0xB837DF8465B43657ULL, 0x795FB9551624EA15ULL, 
            0x2F1B56733D3DDF93ULL, 0x3717838D3A3CD3CFULL, 0xB93367D75A0B8599ULL, 0x91FB2946D654B1C3ULL, 
            0x703FA01CFE2AAE42ULL, 0x52D1095784725074ULL, 0xE1B75D6A37879F6BULL, 0xE64D75DEED49452DULL, 
            0x16AC2CDEA49E8FA8ULL, 0x06D9F478C8D40B29ULL, 0x00AE84B394650231ULL, 0x62688090ADD9EF83ULL, 
            0x9292177C08C152DFULL, 0x5557164FC62F3A4FULL, 0xDF5623B468CC1E95ULL, 0x588295CF22ABB3F2ULL, 
            0x2769FC0D262E1108ULL, 0x372433AE5C9D050AULL, 0x50224EB5AD0E96FFULL, 0xB704B8D5FDA4BE98ULL
        },
        {
            0xB2A0A0817C553924ULL, 0x9E1F9A6A07AAE54FULL, 0x88B3DCE477E62AD8ULL, 0x7A81BAA4C1183DA2ULL, 
            0xDB3D74D142C34CE3ULL, 0x3242ECAD35F833D0ULL, 0xA4324641DF843CC7ULL, 0x354E0EB4590096AAULL, 
            0x1DB8D3404F9CBEBDULL, 0x9FF10BE700B03213ULL, 0x57089BA39BE55F93ULL, 0xF82A4DD15C775F4AULL, 
            0x6645B2746C3611E7ULL, 0xA0DE1033C638556EULL, 0x231915F6600F576EULL, 0x8C2F40A42E0F52FAULL, 
            0x11DDCE22B8BF0DCEULL, 0xDB53D4B7B63EDC23ULL, 0xD7F495CC85A69B60ULL, 0x36BB44A38BD554F5ULL, 
            0x0C8951C3C09FCB05ULL, 0x2EC54492A587900DULL, 0xF48CA22E9EC22604ULL, 0xEBD4295FAA1FE8DDULL, 
            0x9D4C79159D9720A2ULL, 0x824004A89E406AB1ULL, 0x344AEEF06D94F823ULL, 0x5E35DF5932B71A0BULL, 
            0x9F0C4F41D25712C8ULL, 0x2A313F784D511A45ULL, 0xC3A9D06CA19B35B9ULL, 0x9587A6D13C76E044ULL
        },
        {
            0x80FCC4A3A41B3443ULL, 0x9B755AF11C15A57BULL, 0xC9393F5F4A1895F2ULL, 0x628FA55C7AD8BCB2ULL, 
            0x0B2D624FF85A6571ULL, 0xC0004D34017C3244ULL, 0x2C0486E86573D6A2ULL, 0xAF6FED6BAD0DA317ULL, 
            0xC863BC8159C58039ULL, 0x90A354008CE0F178ULL, 0x7F9E0A59A209028BULL, 0x8EC816619581EBC5ULL, 
            0xEE443D2870851CA0ULL, 0x1DA37162A30406F9ULL, 0x00C83A36E6BFCDBBULL, 0xDBD70A00B34733E9ULL, 
            0x92F8865F16F2C27EULL, 0xF72630DD8BEA782FULL, 0x6A86B8BAA7AB802FULL, 0xA884947DB416CBC2ULL, 
            0xD7E9249178DCCE96ULL, 0x63B773191A087585ULL, 0xEFE9623624C61800ULL, 0x6998B90129C02723ULL, 
            0x30EABC59AA125006ULL, 0x71DF78252ED5E47EULL, 0x5049CDBD2148F566ULL, 0xF928FA3E0E41B722ULL, 
            0x2CD590AEB599F252ULL, 0x3FE7B1A8BFA14CC1ULL, 0x72D615F44EAE5AE8ULL, 0x802A01E0272FBEE4ULL
        },
        {
            0xB612320A86E4BC18ULL, 0xF933FD2E307EF8AFULL, 0x42F161D1C97467B0ULL, 0x713B346F0B2B1B7CULL, 
            0xA0E894606C2508D9ULL, 0x4C9CF891715696CDULL, 0x24A5CFB3D59CD3DEULL, 0xD8ED2624301E1724ULL, 
            0x619344C09F9C8F00ULL, 0x0FFCD82D2049A3CAULL, 0x946503684DA04158ULL, 0xD987BD57B55A8E51ULL, 
            0xA946A0462D13B4FCULL, 0x1109CB11E5BEE7DEULL, 0xDA182D18030F60CEULL, 0x7374748BAD103209ULL, 
            0x1D9FBB0CEE547550ULL, 0x9055C0CC440027DFULL, 0x99DB7694C5E3111EULL, 0x8C82A6D73CBA004BULL, 
            0x25A060D081D74457ULL, 0xA7E85E0A5851F61BULL, 0xB48CCC976874956AULL, 0xE7C1308EC030556DULL, 
            0x1129AB49B5959A80ULL, 0xDAE6C654E6FF74B9ULL, 0xBE8038D8712B45CFULL, 0x97663047239DA156ULL, 
            0x4FB31568C41AFDBDULL, 0x53DEBD5A47E69E67ULL, 0x622F30A2B503B80DULL, 0x2B2DAEA5972334ABULL
        },
        {
            0xE1DD0F117A02A304ULL, 0x9DCD18F88BFAF200ULL, 0xA1ED903F06CC2405ULL, 0xD33142A4805BF7EAULL, 
            0x3D77798A0064AC95ULL, 0x6D2A3AC853AF1A78ULL, 0x99E0D99D34157CF6ULL, 0xAA8DAE44D594E098ULL, 
            0xC302E54946AB9432ULL, 0x663F388548A4A31FULL, 0xB22E8D41F850B5BDULL, 0x4B4CD07B0F98534BULL, 
            0x699026127E4905C6ULL, 0x2380D07705B37FFEULL, 0x422DCEFB4F4AF202ULL, 0x15FF767FBC508551ULL, 
            0xA747838273540739ULL, 0x71C58C2D53CFA1A2ULL, 0xE739EAD3A001B36FULL, 0xE2D438675D9DA535ULL, 
            0x068F7E1BFC405E97ULL, 0x14F64C569D13BCC7ULL, 0xECFE49E452CBD795ULL, 0xE4D048829C10982AULL, 
            0xA2CD1AF766954299ULL, 0x8A4F48A3B90129DCULL, 0x499ABF89E38292E2ULL, 0xFA2ADAA1DA9ECA5AULL, 
            0x2134AFEE543DDEC3ULL, 0x601B9AD31996D25FULL, 0x31851FBAA2670252ULL, 0x4B90AAFD8BAF8D04ULL
        },
        {
            0x5F38819D19B54DBBULL, 0xC1743D9C3F047D0FULL, 0x1E3E3320B3323446ULL, 0xF01A795F92440C64ULL, 
            0x863D7BA693FCB0E6ULL, 0x8131191B71A049DFULL, 0xDB80FB842C7ABAB8ULL, 0xBE20060F21689150ULL, 
            0xD57AD9DBAA8E8FBAULL, 0x0C16EEED6853D363ULL, 0x08F37B7A081D607AULL, 0x530F4958916C884AULL, 
            0x1106102621D45112ULL, 0xE22DF4FD5355012CULL, 0x08BD99233D298268ULL, 0x1AC3C85D62A1078EULL, 
            0xF7D9840E4EEF55A4ULL, 0x1007FAF04A6190ABULL, 0x1783E01C1D80B0DCULL, 0x2D015108E81EFD12ULL, 
            0xB51646B091FA8042ULL, 0xB8C466386F01DF33ULL, 0x060C1E51B380814BULL, 0x46B4DFE4502D186BULL, 
            0xE66C5A1A85E9723AULL, 0x757793BCB8981E7AULL, 0x772E5899851A7ED3ULL, 0x96D9B26B0665BAA6ULL, 
            0xF5F60177754FBF2FULL, 0xD53B5D3960A01C8AULL, 0xD23C610BE5701F8DULL, 0xD0C2B38C14BB239FULL
        }
    },
    {
        {
            0xAE8810BF84E3EDAAULL, 0x6F30EFCCC57558F1ULL, 0x648CB1BFE8EB4BE2ULL, 0xFDFED619B9620F8CULL, 
            0xD3F53115398D4703ULL, 0x56A8AC0BE547139CULL, 0x00A51FE4B9F8C2FFULL, 0xFC0F5FA4F745E003ULL, 
            0x7FE077F1CFB2C450ULL, 0xC9D5FF699C3D41B6ULL, 0x9F0FE5A7C8B95946ULL, 0x2B89C5D9D909EA1BULL, 
            0x2245B214B4BE62B7ULL, 0x417F67ABEF62BAE4ULL, 0x25994F02FEFFFA30ULL, 0xC5210369E81406C1ULL, 
            0xD016A49C07297C05ULL, 0xC72803D25DE0413BULL, 0x1361032178FF9031ULL, 0x943AD88250770F15ULL, 
            0x3039BEE765C8B9A5ULL, 0xA57530F36E9F2437ULL, 0x9F1D21C7581F1FBAULL, 0x7EC3B1B1C799EC56ULL, 
            0x781AC6480ECC9266ULL, 0x93A5BC992D431976ULL, 0xD81013425B728D33ULL, 0x660FA0BB420C0153ULL, 
            0xA88D53D9285A21BBULL, 0xDEC980CDAE02C358ULL, 0x6ECF5A67A5F4ACF4ULL, 0x29F706BC902097AAULL
        },
        {
            0xC878C803F6B296F5ULL, 0x1C3CEA2ABBB0DE85ULL, 0x553F4943220572F9ULL, 0xC7A1759200F521AFULL, 
            0x01FB6AA43CCF3227ULL, 0xA058B5D21B0EDDB7ULL, 0x315286D86D9A26B0ULL, 0xD590B3ACED1D8947ULL, 
            0xA819E48171D59E33ULL, 0xC53CF20210BF66BEULL, 0x55302BB016947CE9ULL, 0xA8EABAA0A38F39F1ULL, 
            0x8C87FA9DA7776F2EULL, 0xC1B93EA228BE8266ULL, 0xAB05F167B27BD394ULL, 0xEF2F6ECD7F526B2FULL, 
            0x53BA488A01CED03EULL, 0xCDEC39FD58AD3B56ULL, 0xFE07B083D44157ADULL, 0xD09148EC4231F8B0ULL, 
            0xBAE3C6300BAEF0B9ULL, 0x8BEB8D316A5901C1ULL, 0x0A8EEDC3B4B8C78DULL, 0x3CCD4F2A17D03322ULL, 
            0x970CDB3250513155ULL, 0x5266DC628C621003ULL, 0xF8B175330036790DULL, 0xB2C12156982FE876ULL, 
            0x1DF7E652F3BA0F2BULL, 0xA4C074BC56ABE7C8ULL, 0x5F072DB21FDA0A7FULL, 0x976852C32EDF55F1ULL
        },
        {
            0x01B478ABC2C145D5ULL, 0x76CA049BF48B869DULL, 0x4B07255B0E9F293CULL, 0xC68B44B66A748939ULL, 
            0x53BE62C9BF801A6FULL, 0x100BCB2C43B217EFULL, 0x0DB787687F363596ULL, 0x22BF6444CD97BEA6ULL, 
            0xABAEB3256D73005CULL, 0x273BB0B5BE2C53B1ULL, 0xFC3F53585DA554BDULL, 0xCC8176F4BF617209ULL, 
            0xF7AFAF6368D8D987ULL, 0xD3843F16F94EDA7BULL, 0xA8B2256F9F64D548ULL, 0x2762004B28CCF70CULL, 
            0xD43D8E472E0238C6ULL, 0x96D40035AF282BCDULL, 0xD97CB09D107A96D4ULL, 0x97CD8D4BDF7200E3ULL, 
            0x5D8734828A220833ULL, 0x3B39C5B418CEDA43ULL, 0x517601D019C9E2DCULL, 0x0A4957E0873A5249ULL, 
            0xBE77D2F0812D5E1AULL, 0x0055988F0AA232E1ULL, 0x52326CE3EB46644AULL, 0x9F0615B28D5301AAULL, 
            0xD4B8219663214D18ULL, 0xE86F4F358C78D1FCULL, 0x896F97309D94B12BULL, 0x3CD67570EA8CD6C0ULL
        },
        {
            0x5B670A44269D0A0BULL, 0x167A0D19C4A2676DULL, 0x885088DE661720D5ULL, 0x5183DA4DC7F41045ULL, 
            0x1C69913D96C0AF15ULL, 0x0734A18CFCAD8D81ULL, 0xCD102D8A200F2C01ULL, 0x89CDEDC7DD23CD88ULL, 
            0xD50472681FE67279ULL, 0x8E42B66077DDA851ULL, 0xCF0B46E92FB5CCB4ULL, 0x7FFDF3FC48AF0354ULL, 
            0x973DCFC6FE7354E8ULL, 0x386B71FBC61DF424ULL, 0x49862F2405CC62A8ULL, 0xF29D522BD9EC781CULL, 
            0xDAF9A42DEADF3E62ULL, 0x89234AB2F5159999ULL, 0x662231AC81BF02DFULL, 0x678B85F569B0BA8FULL, 
            0x9496CBBDFEA1C7BBULL, 0x2197AC3855DCFF2DULL, 0x3566E4181F16D596ULL, 0xF4FE8B59A2E7DB5AULL, 
            0xEBA50C276A371655ULL, 0xE4AAD1D616BAB5A8ULL, 0x756DC51445088F3CULL, 0xA40D5928F794FF1FULL, 
            0xA8EE6F0734DEF552ULL, 0x1A7540F73759BA38ULL, 0x0842D63ECE737598ULL, 0x4E290FBF10CCB417ULL
        },
        {
            0x7888EB0571C142D6ULL, 0xF8FD4295715F5C19ULL, 0x0681264087319BECULL, 0x58B584F640D1E3CEULL, 
            0x1C0B557894D823E4ULL, 0xB5447F716C58C668ULL, 0x9FBC2D7466221FBEULL, 0x867D947451D40F4FULL, 
            0x335749D2B32A8D4DULL, 0xF2941262559B924CULL, 0x5017A02370E3E922ULL, 0x5C0D6118EB82C93FULL, 
            0xCFCC463D37873363ULL, 0xFDCAF7B32770F538ULL, 0xD66A995A52BC7265ULL, 0xC447FEC8F1C86068ULL, 
            0x0ACCBBCEB0D5A1A0ULL, 0x2E39FD29CB629FBFULL, 0x96A5D565435E99C2ULL, 0xEAF0FE2374816ED2ULL, 
            0x9C7FB03788A5BC7DULL, 0xC003FA79D7A25B2FULL, 0xC5854E93BCCF9962ULL, 0xB0B93DD39573A4BCULL, 
            0x88481015BB12ECDBULL, 0xE06B3DA09CB7057BULL, 0xDC7D8CC2F55AFBFBULL, 0xF2E5556380757AE2ULL, 
            0xD34A51FBDB3E5177ULL, 0x1FC6B8470E5D54B9ULL, 0x428220DCF19FBE54ULL, 0x9D195ACAFE391044ULL
        },
        {
            0xEE534D49206430F4ULL, 0x216F611A8DB80EFDULL, 0x042867BE7430F0C2ULL, 0xF111CDBB11749289ULL, 
            0x1C50F5D9582E2F95ULL, 0x9AD241ECD524A578ULL, 0xF58EF5F5673754F3ULL, 0x97117730BED14C62ULL, 
            0xB10C996BA49B7887ULL, 0x040CF8FC2D926FFAULL, 0x6783E68D3BAEC501ULL, 0x211B4B2075A701CEULL, 
            0x529897C4DA0C89C0ULL, 0x791C04B756A1A140ULL, 0x7B2301A55F367FDDULL, 0xA843FC742061CB42ULL, 
            0x430D2F334B33ACE1ULL, 0xF5D20DFCDC6ABC88ULL, 0xC81B14C544DBD9EBULL, 0xE7361D2F04894576ULL, 
            0x1EEE817876A0B1BAULL, 0xF4D2A42FDC4E66D1ULL, 0x75391BAED8C36ADBULL, 0x537DE7CED441E51EULL, 
            0x557556CC57A19498ULL, 0x7B43BC3AC639DC7DULL, 0x74827FFC086B1A0EULL, 0xB63D72E983F82FB8ULL, 
            0xD3A83E6A882DFDF1ULL, 0x87A65E88B2DD0CE3ULL, 0xEFDDEA8DFB643CD0ULL, 0xB594A692E16C0CDAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseFConstants = {
    0x10BD37BED590E687ULL,
    0x5108042FD2AD5C85ULL,
    0xBBB33C75D68BB519ULL,
    0x10BD37BED590E687ULL,
    0x5108042FD2AD5C85ULL,
    0xBBB33C75D68BB519ULL,
    0x332AC65D61029725ULL,
    0x85A563DEA0B6B6ABULL,
    0x74,
    0xAB,
    0x94,
    0x38,
    0xEF,
    0x36,
    0x91,
    0xA2
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseGSalts = {
    {
        {
            0xEB427AF8BF8762FCULL, 0x125E4A3A14E3AEBFULL, 0x81421A5E0C33B8EFULL, 0x0B6ADB681A516CE3ULL, 
            0x39D2EC1C6549CADAULL, 0xB0438CB5EE6274A7ULL, 0xD54F566F9889F8FEULL, 0x3EC47E5B31F6EC44ULL, 
            0xA8D14E137C4EF40EULL, 0x573FCE036D2E964BULL, 0xB99043225DF2A00EULL, 0xE644541EEB2FBC83ULL, 
            0x9797E79356475D70ULL, 0xCB5DB1AADE534243ULL, 0x3A41D4AAC97AE6E3ULL, 0xCECFCB8968C7EFD7ULL, 
            0x8667102D611BA538ULL, 0x9106B4196BB544A4ULL, 0xD935A3C1C8167814ULL, 0x699E8EB0C5C7EDD8ULL, 
            0x120FB15410FD669BULL, 0x8CBF281020B57B8BULL, 0xAFB090A28578180EULL, 0x7A7AEC4950F427CAULL, 
            0x5763642031C1A2F7ULL, 0xA7F8D43013C0425EULL, 0xE3556D20F1B3A0F8ULL, 0x1B3CB4684A8BCED8ULL, 
            0x82291B33951BAE26ULL, 0x97A0204C95C7E256ULL, 0xAE66627B2666917AULL, 0x79B9EA814C1C3C5DULL
        },
        {
            0x5F5028ABF0CE04D7ULL, 0x63DFE33EBFC5B6B5ULL, 0xC1C9D7D512659FA2ULL, 0xCC6A97D592789F9BULL, 
            0x653CE9A63D7352D0ULL, 0x3179C00556672298ULL, 0xC1B4AB67AA3290C3ULL, 0xA0D719B96A19881CULL, 
            0xDA943427863BA84CULL, 0x2495E8997E228AACULL, 0xB74954A70DFE845AULL, 0xA39777B38824D4C2ULL, 
            0xCE24B8557F045A54ULL, 0xC019A4399829D91EULL, 0x03B10895E77D4E9EULL, 0x32C2DBB8D4CAB9D2ULL, 
            0x66A8CE4413FCF972ULL, 0xBDC2F7F04BB4F3D0ULL, 0xDE8A5B171BEC7F6EULL, 0x986A29F2A90A81F3ULL, 
            0x7A754CA1A1C68191ULL, 0x6D100C7F8736A6B9ULL, 0x3FFA34CDD57563A9ULL, 0x87B898E4C936F300ULL, 
            0xB6EC80463EC8A002ULL, 0x59F57F7E0001568AULL, 0xAAF41EACB56BCB9CULL, 0x4583CB9AA81FC194ULL, 
            0x2DB9BDF419A39C86ULL, 0x7E23D5433B983591ULL, 0xA6EE4D849A4D7CEBULL, 0x14D15F10442F659BULL
        },
        {
            0x8820E1A5D71168F3ULL, 0x29BA9EE0FBF48FC3ULL, 0x62627507997C2485ULL, 0x03BAE9C4DBBEBD74ULL, 
            0x55863B0AAF4DAD0EULL, 0x886D84E73847804AULL, 0xE99C9BFD03816CB6ULL, 0x2F3E625CE8DE11B2ULL, 
            0xCFD18B0DA4FB9664ULL, 0x9DBEBAA0A57C18EFULL, 0x40B29DD060C5EFDEULL, 0x5AFBB81DE648836CULL, 
            0x8CB283E24C6099A7ULL, 0xCF20DC71EEDE1E21ULL, 0xDA62A6FF512A06E4ULL, 0x19899DA03A7ADBC2ULL, 
            0x00F01A4F5464C049ULL, 0x7C8E0FDD488E3D90ULL, 0xFB285EFC5EBD25E7ULL, 0x999F0D27DEA3EA87ULL, 
            0xC0D270B155DAD5B0ULL, 0x6414A476C699F56CULL, 0xC29711B57968716AULL, 0xB0BBF51964706091ULL, 
            0x0DC600AF276F39AAULL, 0xDDDDABDEBFA5F866ULL, 0xD2BB123D5A2638D0ULL, 0x4BAA377F62D44F87ULL, 
            0x13AEE204D35E2984ULL, 0xA05A84163557BB50ULL, 0xC68C80592591A0E3ULL, 0x2784D1B88E8960BDULL
        },
        {
            0xE6EE61E44B7CFD68ULL, 0xFD9D5C726371780AULL, 0xD670E6C2156E8B7CULL, 0x35162612AFA6E521ULL, 
            0xAA912E2B857FCD7EULL, 0xADF9878AFA35C4BFULL, 0xE783778154CD67DFULL, 0xE74152B42095E32FULL, 
            0x3C7262B5CD6A2ADAULL, 0x5599DFFFE20638ECULL, 0xD5526825948F0521ULL, 0x757B82DBAD8621B2ULL, 
            0x0E7B18F12A488A79ULL, 0xA23F4FCC9EE7180DULL, 0x2B34F8B8451E00A1ULL, 0x29670EDDBB7FF06CULL, 
            0x1CDF023EAA80D7D5ULL, 0xEA86FB3831D366CFULL, 0x547B9D3068A94E02ULL, 0x7E91F17C7EC97522ULL, 
            0x22BCAB79C73F2A39ULL, 0x1189AEB9FB839AE0ULL, 0xDF6150A6EDC91E03ULL, 0x19C1E7894B2CABE1ULL, 
            0x95EB29A105145CC1ULL, 0xEBB2AECFC696B1F0ULL, 0xE3722D47424F551FULL, 0x209982C3CE846041ULL, 
            0x396B8F7005A82043ULL, 0x619A70E844C82357ULL, 0xAAE7451424C190E0ULL, 0xCB8B2965F07E4C19ULL
        },
        {
            0x0C8CEE06BD197B92ULL, 0x1CE4C55288BD7FC5ULL, 0x2B5199AC44144795ULL, 0xBCE5445A91064131ULL, 
            0x07FE27C0B8DC9697ULL, 0x24A159E69C7F0EB6ULL, 0xA519316C8F527A9BULL, 0xB8C539F57989D7EEULL, 
            0x038B7DDED17BC6CAULL, 0x16A1A2301E50494AULL, 0x61D6069E73AAE0B1ULL, 0x32E20552439F2B00ULL, 
            0x6B08175F077E4F7BULL, 0x082AC8487B8908B2ULL, 0xCE6697425D2B68ECULL, 0x8D6369719C321B3CULL, 
            0x6E5B0F8C8C510F9EULL, 0x776965AE4277A9D6ULL, 0x85A6277AD45A9F5CULL, 0x91485506603A0DDEULL, 
            0xECE18124007B10F7ULL, 0xA480EC3B8CAAC505ULL, 0xD0392443380BFC51ULL, 0x4DEE551C25AEE36BULL, 
            0x4A06E4C538A7681AULL, 0x44A2846D09F1AFA1ULL, 0x9C3C14153250F06CULL, 0x24860FC67060F32FULL, 
            0x3137FCFBE2FEA85FULL, 0x4943AB0F8931C363ULL, 0xCA6EE0B55476F47BULL, 0x8121EC12E301AB9EULL
        },
        {
            0xE05C92D54060D029ULL, 0xA88E01C261C9E4D9ULL, 0xC6CD22A067EC3E18ULL, 0x98FA832535C4F43FULL, 
            0xB45A982E6E159009ULL, 0x505C95ABDEBD268EULL, 0x4E0401AAAB0C8326ULL, 0xE00401463054DA6AULL, 
            0x23C4B3556A5F5C45ULL, 0xBD434F7EACF1E041ULL, 0x897171360B175D3FULL, 0x4DAAC9FF981A0DCAULL, 
            0x59403C553946E9E9ULL, 0x22514DEF1810320DULL, 0x621145C0848CF622ULL, 0xCAA696E9D2ED5486ULL, 
            0x5B3EDA51EA773B83ULL, 0x45CD6ADCE9BBEEB8ULL, 0x82477F6CF50B47A8ULL, 0x0ACA2A73FF9A5499ULL, 
            0x632541F1D49CB752ULL, 0x8235136606A5967EULL, 0xB5CD2FB0240124ADULL, 0xE3C2D2A691D05324ULL, 
            0x532565A82F0B3D42ULL, 0xFB42A3578379F049ULL, 0x98E3B54AA1B5C061ULL, 0x9979F311FF071156ULL, 
            0xEB761C9C75B9BD65ULL, 0xC16332ED6BE4614EULL, 0xC4CD237E945A6DD6ULL, 0xAA3D18CA3278FA5DULL
        }
    },
    {
        {
            0x2A17A402B774A092ULL, 0xF235F7F2A27E8543ULL, 0x3CD708DD6B88B08EULL, 0xEFC569CD8B5927B7ULL, 
            0xB5E60750BC2772BFULL, 0x1320A56C7C00B273ULL, 0x0E40FFBB6CAB1DB2ULL, 0x8AB890C23E30E2A3ULL, 
            0x997F5C5AB394AF14ULL, 0xFCCBA496C3FAA50DULL, 0x351EC8988AF8CECCULL, 0x9090D08DEF3A5EC4ULL, 
            0x3527E6953E2D34F7ULL, 0xA4CED8DCF10D89BCULL, 0xEC47A2F77AF9D659ULL, 0xA50AB7A493AF6BA0ULL, 
            0x1AD76486F091BE05ULL, 0x8AA6A313C95FC62CULL, 0xAC4D4EB6175CB455ULL, 0xD044123F26FF5736ULL, 
            0x874740BBB8F9B27BULL, 0x14CACEB47A694C06ULL, 0x8C63109AB83B15F8ULL, 0x720564D71844D636ULL, 
            0x991F0BB9D7E83DF4ULL, 0x55FCD7D0373DFE5FULL, 0xE1E0ECC97ED9B375ULL, 0x588E6BD3A6008D92ULL, 
            0x7A1D783CCE48F998ULL, 0x10F6F26F4107FB85ULL, 0xAEFA3161FF96211DULL, 0x294E65B392C7507FULL
        },
        {
            0x0F094E76BBE37AD9ULL, 0xE6F144716BEC3403ULL, 0x817390C1AD585774ULL, 0x78F4D1A578C503CEULL, 
            0x745F8E1883289B4FULL, 0x8982A7588A3DEB9DULL, 0x75D1BD4D8C8B9C03ULL, 0xEC5B06B57FB13251ULL, 
            0x60784087EFA3655AULL, 0x333063EE2830E4DCULL, 0xD13F1B76BF3D8E2DULL, 0x75BD3B533655C48AULL, 
            0x71E88C4165EEDF3BULL, 0xCCB9B0AB27827822ULL, 0x62AAB7DAE893C26DULL, 0x24476C9CE44BDA09ULL, 
            0x782E6CE152C35B24ULL, 0xD7E96DBAF5B2E6D3ULL, 0x5991BD847D0B5BC1ULL, 0x27557BA1D9BCB86CULL, 
            0x453770229DEAC716ULL, 0x2CB922217AC717CAULL, 0xBBF0A518AEEF8BC7ULL, 0xBDF49A711937662FULL, 
            0x5FFD5D54362B4E4FULL, 0xDB8A984097ABCA00ULL, 0x9F81C1D103747E4DULL, 0xC93F9CAEF0E82DFDULL, 
            0x3B55E2E5F74C8D7AULL, 0xF69B1D03FC72500DULL, 0xB57D89BFFAA16703ULL, 0x2A413343C52ECD88ULL
        },
        {
            0xBDFE2587ADF4624DULL, 0xE6459F95D8DEB7BFULL, 0xD350257B6F73F8FEULL, 0x15ABDD34BAAFC9B8ULL, 
            0x11700D4E04545550ULL, 0x12F59C405A4B18C1ULL, 0x29CE36AB56D0D764ULL, 0x09340F0B097BF017ULL, 
            0x4DB671FA1FBB849BULL, 0x5A4A7F99885629FAULL, 0xA013DF0A450E40C5ULL, 0x63FC6C4AD8265641ULL, 
            0xC292DA7427E043E9ULL, 0x4F8B6E3973332026ULL, 0x80462A90B4B2565EULL, 0xB75E769EF5F560B0ULL, 
            0xA412C42DD2A2DD94ULL, 0xBF00C7A29B844E4EULL, 0x1B74AEF4FEDA759DULL, 0xC47C862E7A7011E3ULL, 
            0x8C06450E475C2B64ULL, 0xEA9C57ED365F8A37ULL, 0x43BF53815AFE4FB5ULL, 0xC93584DDC1D1D2F2ULL, 
            0x8B2FD6357B52CCE8ULL, 0x6CE3AEFB1DEB394AULL, 0xD8F6EE237953E00EULL, 0xDFA0D41E9B6BA0D1ULL, 
            0x697C9348686639A4ULL, 0x932CCEF250D1B5F6ULL, 0x6733A00F48AA8FBAULL, 0x80099D05BCF15EC0ULL
        },
        {
            0x0B1D76DFAC7D5EC0ULL, 0xC9BDC59DDE959E70ULL, 0xF0805EE6EABDF200ULL, 0xEF2B69B44CE4C398ULL, 
            0x8A1F088F3C184A32ULL, 0x7BC1A7B571AB1939ULL, 0xAE38B50811AD9006ULL, 0x67AA6B9C1F38AB88ULL, 
            0x0F0D85A2F6404E06ULL, 0xF0F5E1E500ECF6B2ULL, 0xF2A7A5C71A312942ULL, 0xF19D610E8B04DB4EULL, 
            0x64846D1DA53C5EB3ULL, 0x7244C64986E9C983ULL, 0xB7DACEC3438F90E7ULL, 0x4FC2AE8492C94291ULL, 
            0xC50307FEE3C24A82ULL, 0xC253E48A583AA669ULL, 0xCF2142835ED0792FULL, 0x448F5663D221EF21ULL, 
            0x66EFD4B48C067C96ULL, 0x2245B8B395ADF7CEULL, 0xF75A49BDFC2A438AULL, 0xC50049B8820C5FFAULL, 
            0x7DFE7E69DB2BF02EULL, 0x6BBD609C617130BAULL, 0xA23F05289472AC2CULL, 0xA7488CB4203E7142ULL, 
            0x6BFD10510FADF0B9ULL, 0x5DB817B2B4C44C56ULL, 0x5497BE4A3A87D7DBULL, 0x87FDA82EA3738853ULL
        },
        {
            0x80A72B639EA80328ULL, 0xB0EC0852D21979A8ULL, 0xAF34C68B527AFBDBULL, 0xEDE44D12EC855385ULL, 
            0x8E1D6F5DD8158700ULL, 0x3F35A24A42F3D258ULL, 0x630673C5249DC517ULL, 0x4AE8AB70E830606AULL, 
            0xEEFB486DD610D577ULL, 0x4267C09863AAFAB6ULL, 0xB422D5555D03F971ULL, 0xF1EA4BA2777C9D80ULL, 
            0x0743A5AD4A9ECE68ULL, 0xB695D251A001B596ULL, 0xAE2FC47E23974917ULL, 0xBA19246A1CCC11BEULL, 
            0xFB5E9BDEA2525BB1ULL, 0x5A01BA49F8FE3C0AULL, 0x64F8A9A9A638BB6DULL, 0x46D1FF7E703AB1C2ULL, 
            0x5AE6A2A4E194E33CULL, 0x4CC31C05FFE87DB5ULL, 0x1F22E54908D3CBE9ULL, 0x77D026DD9DF1E4C4ULL, 
            0x64428AF24876FEB6ULL, 0x0A56471DB2327648ULL, 0x1895C6735780CCA5ULL, 0x5044AD8AD7D94056ULL, 
            0x8D0DFFA5D1C6507FULL, 0x110BB9A44667A04DULL, 0x7875C314CD058280ULL, 0x0E57702BD88FA673ULL
        },
        {
            0x08DD552B03ECAFADULL, 0xD8A51F9F09506B8AULL, 0x22F8D34484CEBCDCULL, 0x8525E02E9AD17F67ULL, 
            0xF57F63BA141293D3ULL, 0xA72AAE5D12D4B99BULL, 0x4EE830A8924EEB28ULL, 0x4D04A0BBA889B699ULL, 
            0xCE36A1C588DD2E06ULL, 0x01502D004F345B76ULL, 0xA071C3966B556103ULL, 0x6F1294C3D2306321ULL, 
            0x37D09F8A11B2DB16ULL, 0xC239EF6465E29F73ULL, 0x1D9371481CDA1A7EULL, 0x3B38A51B6F8A5091ULL, 
            0x841F58FEDBF4277BULL, 0xA7B18A193FB52D63ULL, 0x4213B6F2DF983B68ULL, 0xFE8821BF6E17489AULL, 
            0x9A3C68A8B1472AD3ULL, 0x43222ACCE8495578ULL, 0x12A385161F25B879ULL, 0xC01FC57E938F2663ULL, 
            0x6AFCA59C4843A2D7ULL, 0xD6AE66E1C110BBF0ULL, 0xC1D4E036E42CF29AULL, 0x2BCF71B20EB80454ULL, 
            0xDA959B53AEE32690ULL, 0xD903022004016E68ULL, 0x6F5809897E544A78ULL, 0x9ACE40295E99518DULL
        }
    },
    {
        {
            0x019E7530A3D62A63ULL, 0x28E0916C335E9592ULL, 0x36287DC50138D088ULL, 0x954AE3BA5F5036B7ULL, 
            0x5743C8A954066B54ULL, 0xC269DE8699CDC898ULL, 0x2F6B7A24F2332002ULL, 0xC6AAAFBC4C956C1DULL, 
            0x146125C311C01037ULL, 0xDC3BF3D52FB84610ULL, 0xD835D8C5BDCE634FULL, 0xA6DF7E42831602C8ULL, 
            0x628B91BAABF9B76EULL, 0xC67ADC164E8A19DEULL, 0x6873DED19DDEB018ULL, 0x0067789055D195DBULL, 
            0x46B25C5714139D0EULL, 0xB0D9AB3FB4E4CE4AULL, 0x5C23AEB1D851749AULL, 0x65AC7B426A5D2A9CULL, 
            0x9F1C0C9192A86100ULL, 0x52D87A87AA1F7C07ULL, 0x5BA1953C592549F3ULL, 0xA8C5621E1D3290A9ULL, 
            0x49A516AD0F455807ULL, 0x9E8A22FB7C26A9CEULL, 0xDB52DB13657416B6ULL, 0x4C06EE76F110D9FBULL, 
            0xCC2086D2453C7204ULL, 0xEA721711ECE2BC20ULL, 0xC49D2CEE278DAE57ULL, 0x50EECB952C68DF20ULL
        },
        {
            0xD8ADD7693861CACDULL, 0x3B5DDD5A9725B4B3ULL, 0x1BD73A69F744F5EFULL, 0x18A87402DCF6E825ULL, 
            0x7FCF5B86C781C3BDULL, 0xA52B98A092139D73ULL, 0x6A1881CC93BBD59FULL, 0x82BD41887DC20C2AULL, 
            0xEAAA0093CC72430DULL, 0x299F0FE26B525C06ULL, 0x7C3B6A9822D86385ULL, 0xCC5AE88DE1F74C71ULL, 
            0xEA213D145FB6140CULL, 0x9CD94E06C9A77E39ULL, 0x06F35F2DCAE3C3A8ULL, 0x68A56E1772AC2BA8ULL, 
            0xF771CEE91682EF9EULL, 0xEDD6BED76F15850DULL, 0x42E1F985E4EEEBF0ULL, 0x96C73F7CF1A432ABULL, 
            0xFF68F0E44C0FEB47ULL, 0xDE78FBB2A391A3D6ULL, 0xB8AA828059F5A5BEULL, 0x8138C60235FD7E28ULL, 
            0xDF5741BED575FDB6ULL, 0x1AEA57AD6B27213DULL, 0x6A840AA7046ABB47ULL, 0xC85911A61189D15FULL, 
            0x2C86EA0D1F86DE58ULL, 0xB5E60CDB11BCB645ULL, 0xA4AEF103CD98085BULL, 0xBA49C27906811FDEULL
        },
        {
            0x97264581E1AD0DA1ULL, 0x2AC3B1A2A46156B0ULL, 0xDFF7B0A715F79B55ULL, 0x78C5B8BE05397426ULL, 
            0xB5C25122B1CB3D34ULL, 0x9095D17B45E7F87EULL, 0xC9415D2ADBBD1207ULL, 0xA05F7935C48E9DBDULL, 
            0xBB9860231FE7F08AULL, 0xC36D6999F83C6797ULL, 0x169E999A58CE4B7DULL, 0xCB3BC33B6901D8D6ULL, 
            0xFD1BBF1236567E2CULL, 0xE601809EB999078FULL, 0x13E839DF88C368B8ULL, 0xC0C388776A0FFB87ULL, 
            0x855329BBE354283FULL, 0x1288A7E1B15E51FDULL, 0x44782232DEF98946ULL, 0x4CF39C372A130575ULL, 
            0x8E1B5FBFF404341FULL, 0xB06B47E92EC341AAULL, 0xFECFC78A8D24C15BULL, 0x9B8AC1D00B4DEDD3ULL, 
            0x81D75550D3FDA71CULL, 0x3EE4EB20E89381BFULL, 0xBD39447B9ADE1AB2ULL, 0x4618E44BF35AA341ULL, 
            0x5E5FDBE7DACDEFA3ULL, 0x7BF6F363CB0230D1ULL, 0x9DBFC8477563925CULL, 0x34E38302EC370431ULL
        },
        {
            0xC691D28B5C09C1AFULL, 0x8992FADF1CFAB00EULL, 0xAB5D0F75EF8FB4F2ULL, 0x093681DF00842D72ULL, 
            0xA3475A25EDD46D8AULL, 0xB9A3A8DF3657E34CULL, 0x1CC00600A11B35CCULL, 0x9093A29F1903FAF2ULL, 
            0x79E4D528988500CCULL, 0x0D9B594AB624FA03ULL, 0x3C58435954276231ULL, 0x370A09834EF38813ULL, 
            0xC22A2F851E096B20ULL, 0x78D47EB928150B99ULL, 0x90C8EF5C97840257ULL, 0x63D7B7045B4A4B28ULL, 
            0x1A140B1A466A2F3DULL, 0x88D20DDCED27CC1EULL, 0x8CA3BF3CC05C545AULL, 0x7325E9A79DBE9618ULL, 
            0xBB720F062025F56AULL, 0xF91C2B931260584BULL, 0xCAA9F7518EA284A0ULL, 0x445DC29456C69B1CULL, 
            0xF0CB1F3EA4DDCFD9ULL, 0x31BA1A46D89897A7ULL, 0xF989E90FC8861AB8ULL, 0xD359FC93183F92C7ULL, 
            0x05210693D21D769AULL, 0xD044A1A441563ABFULL, 0x7D487E57D9BCF86DULL, 0xCEBB1678CA157A90ULL
        },
        {
            0x1CCAA7AD018E28C9ULL, 0x57B173B1608E0A76ULL, 0x314C962024F89C6DULL, 0x674036C43800E9DCULL, 
            0x091E84280C83077FULL, 0x0A4FD6F065F807B0ULL, 0x2BA7C6F680D3F371ULL, 0xE8A9CDAB59325520ULL, 
            0xB722567D23E2AC2AULL, 0x3F0B057173EEBF1EULL, 0x5B479A0353F4BEEEULL, 0xC2BDAF74D64E8ECEULL, 
            0x807CCE6EFE641CB9ULL, 0x0FAEA0DAEE31FEEAULL, 0x7859564ECA31DC88ULL, 0x5FD1C0EF37ED58CCULL, 
            0xFA3E6EAA968AC14FULL, 0x16CF95E32822D665ULL, 0x285FAF512DFDE5A7ULL, 0xFC91D4339B5C3B74ULL, 
            0x3F3E355071F9918EULL, 0x67B9E72460EC5F71ULL, 0xF3233A6A1DF1D5E5ULL, 0x02469267DA575152ULL, 
            0x7A5E2AAF6BC00069ULL, 0x1E72346696D1729FULL, 0x19AA5FCB93F836FBULL, 0xECA2CED8F784FDB4ULL, 
            0x09E5B71BF239EA74ULL, 0x41ECA76DAFB369B9ULL, 0xE20D4D9169F26E7CULL, 0xC02BDAAECA32867AULL
        },
        {
            0x61BDFE927701EF92ULL, 0xFABB1CBB32DBC708ULL, 0xEE89C8EDE20E6D43ULL, 0x960B5106CCF16553ULL, 
            0x0C27E9107CD7B2FBULL, 0x56018354D1EADBA8ULL, 0x7FC496610123DD19ULL, 0x9FCF46056BC632ABULL, 
            0xD6D7902B9C230A53ULL, 0x5D0ED64CDE4BCDF6ULL, 0xE1E9B22D042FFBC2ULL, 0xA66974A771498B9BULL, 
            0x8E2AA6000F1F81A5ULL, 0x61DBB821DCF9A2F3ULL, 0xA42BF56DE85D8CCDULL, 0xBD3162414D459CB7ULL, 
            0xCD7DB7A9FF571D27ULL, 0x94F3EEBC13BA8CFBULL, 0xE166544AA1C98D44ULL, 0x594D825EA266DC09ULL, 
            0x4051E7762CC8EC32ULL, 0xD55CF0D995BF4706ULL, 0x27E0F9BA81417AB6ULL, 0xE85B807C3D7499BCULL, 
            0xE9651EBB37057189ULL, 0x70748CBCB201B7ABULL, 0x2F6A7E971EA8C98FULL, 0xB00D107D4C411177ULL, 
            0xF14D5F81BACBC8B3ULL, 0x2C8C4E3A8D2EB5B9ULL, 0x136F706D8084B01DULL, 0xB8454E6DB223A9D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseGConstants = {
    0xB9A0688B22375B5FULL,
    0x9E5D16F99CF900C4ULL,
    0x8A0EBD31DD6AA9D4ULL,
    0xB9A0688B22375B5FULL,
    0x9E5D16F99CF900C4ULL,
    0x8A0EBD31DD6AA9D4ULL,
    0x477D62B23B7413BBULL,
    0x80F29A4A7CAFEF2CULL,
    0xCC,
    0xD0,
    0xA1,
    0x82,
    0x70,
    0x8F,
    0x07,
    0x13
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseHSalts = {
    {
        {
            0xA33825FD20D9B60BULL, 0x05F698454BE43A5DULL, 0xF25D6A3CAA4EA1E7ULL, 0xABFBDD102EA2C2D7ULL, 
            0x0B5C7AE979905D48ULL, 0xEEB38ECB2C144E06ULL, 0x61C21960D1D62581ULL, 0x56871B9DB7BC9925ULL, 
            0x51E5748638579337ULL, 0xC2B9267BFBCEBB78ULL, 0xB92ABF3797DBC5E8ULL, 0x9DFA4F6889F28994ULL, 
            0xDB71EC26CB517545ULL, 0xFDA43A83748D035EULL, 0x4B411C23E797B693ULL, 0x5F8B2282CAD88096ULL, 
            0x89212F3C1FD882FFULL, 0x4E7D207C951E1501ULL, 0xDCB17CA159024920ULL, 0xF96C727ADCFE7AD4ULL, 
            0x7401A536D71D0637ULL, 0xCAD096E4FAAAFCBFULL, 0x83D0E3245EB57E1CULL, 0x003C7B47440AD630ULL, 
            0x7387945D4236E0C4ULL, 0xE2F14233143BDB77ULL, 0x819D57EF2F0C8E82ULL, 0xF4BE3675508435A5ULL, 
            0xE23CD41BA93A41FDULL, 0x5EB21A50458744B4ULL, 0xF033DD564B4406DDULL, 0xEC0FC62C05670275ULL
        },
        {
            0x2965819741E87D39ULL, 0xEFBC52752C5774E7ULL, 0xD8A1D826F7A2B188ULL, 0xC7FBF28665AF17C0ULL, 
            0x57902F42B8DF4CEFULL, 0xBA37F164320EC0F9ULL, 0x04EE872A946B059FULL, 0xECF4D1815E29E798ULL, 
            0xACACE0C3D58289FBULL, 0xACE712CC184C8AEEULL, 0xDBA0B66ACDB2EAE8ULL, 0x52F5D72AC40BF12FULL, 
            0x239C7E8ABF728015ULL, 0xAAD968DEFD4953F8ULL, 0xA0E33B4DEDD6A761ULL, 0xE4768DEA00B98641ULL, 
            0x78FE390CE7102E85ULL, 0x7CC9B77AD8EE4970ULL, 0x49D5D2EF31930FC5ULL, 0xB96C4CF0311F028DULL, 
            0x7A04062A56B29C31ULL, 0x896898FD2D4026CFULL, 0xAC71AF87BC8FD4DCULL, 0xCCE41DF1B8E00C0EULL, 
            0xB21C5D3650812048ULL, 0x903216A873AE836AULL, 0x4BD3D2DDCFD1E6FFULL, 0x4C4D50CBF7B83DEDULL, 
            0x5E146B61A2199FC6ULL, 0x1AB565BD3158149DULL, 0x3FF8A3829AD597BCULL, 0x650934D00B6150D8ULL
        },
        {
            0x1CFD283DD1A0E0F8ULL, 0x189BF9700631620EULL, 0x23941390728AA407ULL, 0x800EE0183222D5B7ULL, 
            0x6195BDDE1A9336A5ULL, 0x70909804D90F8B2CULL, 0x8CAC7649E9703908ULL, 0x5DDDB34F49AE2B69ULL, 
            0x364A4FEF1D749ADFULL, 0xE563F4E80730EE6DULL, 0x010B0F1DFC0A5A28ULL, 0xE97C0412459F9D1AULL, 
            0x139CC0AE7DEDCA8DULL, 0x83D5CB836E0ECE10ULL, 0x6B910402D5285007ULL, 0x8AAEEBFDF3CFDAA9ULL, 
            0x6F8ACBD9AEEAA4C7ULL, 0xF7743C4E83543941ULL, 0x02D153E3CF963092ULL, 0xA131CB64BE9F0C30ULL, 
            0x743AB651393BAA55ULL, 0x6B91F7EDEFCDCA11ULL, 0x7A0E19793E3BAD5CULL, 0xCEF0BCB972795E70ULL, 
            0x1EC2923B7F69B09DULL, 0xA1F4DFB0EF61F6BFULL, 0x6CA45E1AB8E0CC26ULL, 0x98019ABD8E1083D1ULL, 
            0x38982524E4365FF8ULL, 0xAC19C5D0B89EC06DULL, 0x6A940DF4A9060FB5ULL, 0xC651079F183C1BF8ULL
        },
        {
            0x9CA01A0B0114A7D7ULL, 0x8B3B73E2A1DC9C22ULL, 0x44324E0D48AE5DA7ULL, 0x8F6D1FADE2635DC4ULL, 
            0xE94F9B89CEC24F5FULL, 0x1705796147A3C8D8ULL, 0x2D3548968E356C94ULL, 0x108D57FF0C68FC5DULL, 
            0x4CB0CE7A60AB5478ULL, 0x6988C9408A912B7DULL, 0x00B8043C55468708ULL, 0x8194414AB849A93CULL, 
            0x8D09E484480BF7CBULL, 0x900E4367D47BF3C7ULL, 0x5E35E951BF13ABAAULL, 0xFC8D790018383D67ULL, 
            0x03E1F12F33415406ULL, 0x4D9BF7F942F49585ULL, 0x2B6C73DAC62AE29FULL, 0x15BDF7809BE6B9DDULL, 
            0x99C968730A55F578ULL, 0xB391E928F9CB129DULL, 0x790CEBC3FB66C5CFULL, 0x85212881BFBFAEEFULL, 
            0x11AD05C8BB2E437EULL, 0x074012644E8AF8CDULL, 0x838154CAF25C0504ULL, 0x4F930A887E8CB010ULL, 
            0x66BA89991205AC2FULL, 0x201CE113DDFC684EULL, 0xA9100C00ADD284EBULL, 0xF0BF20FB8E96A474ULL
        },
        {
            0x9721C25D08A3A522ULL, 0x4026FEC1315E79BDULL, 0x8556D70736F38B20ULL, 0x80CBA4371140CA16ULL, 
            0x415ADCC7BD7C4FD8ULL, 0xBAC35E2195A40809ULL, 0xD9D6C93D1138CCC7ULL, 0x57B949B28EC0F241ULL, 
            0x7EA3955818CE9731ULL, 0xDC168A620833741DULL, 0xE17C5E70B04E6E92ULL, 0x25C531E6B338FFF7ULL, 
            0xD3C5E4B44B6D80CBULL, 0x6FFD9F007C9C6554ULL, 0xBC3D72F600734E17ULL, 0x20F43F209B697216ULL, 
            0xAB569A3DD7C57097ULL, 0xEC605D3E1EB8B559ULL, 0x288C5143C87C8090ULL, 0xD6CD30BC16E1DDE0ULL, 
            0xFE5F417F6A58CF29ULL, 0x37951DD2EF6E0C14ULL, 0xEDD51993EED5AA06ULL, 0x206B33C6DC0D4D10ULL, 
            0x8840B810CAD9FCBCULL, 0x206739C5C4E640B4ULL, 0xA101E1CD6C9F95E8ULL, 0xC1BD612AB7E6927BULL, 
            0x35A5EC38CBA50184ULL, 0x0300518A412429DFULL, 0x8A65AC3FB0EBC2BEULL, 0x8EE2F96F9AD73FBBULL
        },
        {
            0xD7CB8CA61F5E5803ULL, 0x27D8F70B4AD65CA1ULL, 0x0EA2A8B16F7FAEFFULL, 0xB543A2F0167A972EULL, 
            0x9D53776C42D765ABULL, 0xE069A413B2317CEAULL, 0x26BEE227C690587AULL, 0xB100EF9197A4E179ULL, 
            0xD9B97AAC9BEB6064ULL, 0xC60DAA7ACD63DC68ULL, 0xF94EF0E4E593F67AULL, 0x737A605E4154B087ULL, 
            0xC1CC7823D94E6F53ULL, 0x431DB7D6A45F4E2FULL, 0x79DE61DEE3D3BFE6ULL, 0x4AC18907A9626834ULL, 
            0x0B795479727B2B7EULL, 0x7522DE4098676CE9ULL, 0x4E22E714FA167B41ULL, 0x8B0556E2608BF4D1ULL, 
            0xB3A98F3A662405FEULL, 0xF0C6B953B7ABBB33ULL, 0x82E084D71110BF4FULL, 0x4D1B6F2B6FBAB291ULL, 
            0xACE786882A1872CBULL, 0xE1435137C6A0D374ULL, 0xF993A1BD1315A218ULL, 0x9E8EAA50A33DF63CULL, 
            0x60324F28A825E4CAULL, 0x87CDA88FBE6260EEULL, 0x37170831143A03C6ULL, 0x6CBAA608AA05CB27ULL
        }
    },
    {
        {
            0xD740E37348798584ULL, 0x7AEFAD85032AC44EULL, 0x2F893644173AD51DULL, 0xD5DD74DB7EB7A6B8ULL, 
            0x6DA260CC3D1A6E85ULL, 0x7214F9196A69E657ULL, 0xDA123CA27096B8B3ULL, 0xB836174328E43A0AULL, 
            0x481AE6104D4366CCULL, 0x2A01632C31641E5DULL, 0xC785AA85AB6F6E3FULL, 0xEECF3D58F3F355FFULL, 
            0xE241DA61848E0F56ULL, 0x4389ED010A624381ULL, 0xBFA667CB8767C84EULL, 0x636A85A14CB05599ULL, 
            0xCA64DCEC2ED1F360ULL, 0xB58AD6022333FFDEULL, 0x4CEF7C4ADCC68A78ULL, 0xC4B3664350C36E93ULL, 
            0x5CC3A055FBDB4C06ULL, 0x949986F3363523A7ULL, 0x5BAE39523F2B2FB6ULL, 0x9BD1E0E882F94ED5ULL, 
            0xFACB4B7B96796AD9ULL, 0x7A45E1FE97ECF871ULL, 0xC0D08AAE72FD1BCEULL, 0x82142018455C86D5ULL, 
            0xCE4565DA98FA3E22ULL, 0x72B408B8254809A3ULL, 0x5937608CB37FC550ULL, 0x16449DC1589A5ECEULL
        },
        {
            0xA0CCC0C03B60DF8EULL, 0xA84611F2CDD90AE0ULL, 0xB605961A247E291EULL, 0x08F13A56073E66D7ULL, 
            0xF49922B5FE7A3B69ULL, 0x88916B27A63C0D18ULL, 0x3ECF6E12C4E33A8DULL, 0x3A31D826D8FF6C68ULL, 
            0x12D27D0D3F011FBEULL, 0xA9C52B09AC3EE4F8ULL, 0xA8B8F35FA86F58DEULL, 0xC6070C9F325C267AULL, 
            0x96539AFFCDA626E0ULL, 0xFF2454A40E8BA0C2ULL, 0xA5F8FA53A1C760C9ULL, 0x909221C5AF72D4E8ULL, 
            0x7AA43B48FC3C0E2FULL, 0x0A4DA0CC4C73CA92ULL, 0xB131A1C560C44639ULL, 0x683DDE53FBEC7B32ULL, 
            0x5B3BA5B26017EF26ULL, 0x38DE3C8C1DC27E9AULL, 0x926DD6B977FF687BULL, 0x107D8C047E05F9D0ULL, 
            0x84823E98FF4FF91FULL, 0x4168EB9502248DDBULL, 0x7BDCDCA60818C389ULL, 0x10FB8F3A83361EE5ULL, 
            0x2C46199BC4D21B08ULL, 0xFA5AB9D6C2A8FDC1ULL, 0x2D4335194AF5E037ULL, 0xDCC2B7C0CE4DBD8AULL
        },
        {
            0xFEA7DFCB1DF9DB09ULL, 0x330862554263F8C6ULL, 0x1B41DBFC977DD5E2ULL, 0x869B4E5D135A1872ULL, 
            0x5F0E5C5347F1BD4AULL, 0xF4C6D250034CBD3EULL, 0x665E8BD79FED7521ULL, 0x989DA429366D00DEULL, 
            0x738908654A77D5DEULL, 0x0E50794605669A7BULL, 0x617EEBDBF1605F06ULL, 0x9ADFAF3FA4A3E0CFULL, 
            0xB2C225AB6B6624A6ULL, 0x22128A2A006928ABULL, 0x62DD801A423AECF1ULL, 0x9E1C8EA209620E59ULL, 
            0x47C7A79EBDE35554ULL, 0xE09F3DBD2E083966ULL, 0xAC28644A9810C8B0ULL, 0xFF8DF134E5135A50ULL, 
            0x01906CBE15DA9B03ULL, 0x84D2FFC2F5DCC883ULL, 0x9356875A17607CFEULL, 0xAFA82033158169ADULL, 
            0xD3E925057AB3522AULL, 0xC569FF12DDE4D55EULL, 0xF36D7F5548381D66ULL, 0xBD97969603A043C8ULL, 
            0x3DDFD0F2FF38CFB4ULL, 0x2E263D0605351E89ULL, 0x292C00F7E80B6D99ULL, 0x10F3D17FC00DF562ULL
        },
        {
            0xD7CA94C0EC397187ULL, 0xAA4CB384BA029496ULL, 0x1B1918978A29F3F5ULL, 0x4BCDC162BD0EF4C6ULL, 
            0x3411FDA30F0CA3D1ULL, 0xECC8ADC3C3D07BB4ULL, 0x165BEA666BA2502EULL, 0x62067E2E06A02242ULL, 
            0xEE86587EF29C1B34ULL, 0x71AE2DE187BC46ACULL, 0x0E948FD1FDF371B7ULL, 0x10363A2B8DD05D2EULL, 
            0xA55C9D9742517166ULL, 0xA86B76F14560DF4BULL, 0x732F5A330B94201BULL, 0x9C554086CFC18F2BULL, 
            0x4EA7A920CB75304BULL, 0x02B353D86E42F5ACULL, 0x3D291809342BDF56ULL, 0x13D0731D5DC96C9AULL, 
            0x4E6C5937EFC2CC26ULL, 0x6C3C66819A7EF8C5ULL, 0xDED8A00214D04DE3ULL, 0x7907CEC947B9CDB3ULL, 
            0x52F37177545D558FULL, 0x6D8A9B2FA00AB97FULL, 0xC29D583CBB089101ULL, 0x035B8A1D15C06649ULL, 
            0x7630769B911A4BB2ULL, 0xFCEE46BB1B214282ULL, 0x15A6091C839249BDULL, 0x38E601C9966CCAF8ULL
        },
        {
            0x304898FA4680C0A2ULL, 0x9DA552810960D0E3ULL, 0xCE2DFE8EC25EF614ULL, 0x9E14D4E11867CC69ULL, 
            0xF65634EDA97EF696ULL, 0xFC2958C3F67D69DDULL, 0xCE037B5C40206BDEULL, 0x0616D72312C499E4ULL, 
            0x1FF68EF2901DC2F5ULL, 0x44A6F13B9C7CD96DULL, 0x3CD8579815363308ULL, 0x51844741DA7EA054ULL, 
            0x6CE180DA2B5F5BDBULL, 0xD0B8B5BD5F46EF12ULL, 0x67A03A46B36EABB2ULL, 0x103248F60D2BA38FULL, 
            0x02C17AFAD764D63BULL, 0x8849C41E94201707ULL, 0xFBE64EC202A4D8ACULL, 0x90965681BF18BD56ULL, 
            0x0A20741DC6F3DCE4ULL, 0x9D288328093FE811ULL, 0x655727D2305D5454ULL, 0xAF89ED0AF1BA17A1ULL, 
            0xA38942DBA915A6F0ULL, 0xADF95D68EDE98E23ULL, 0x0E338722D1847A16ULL, 0x4F14AE04E0FAF4F7ULL, 
            0x16CA66580A6E0338ULL, 0x6C3B579438EEBC2AULL, 0xCEF0E0FA39687A49ULL, 0xFECE90886A53AE45ULL
        },
        {
            0x76EEC00204DD91C1ULL, 0x24D1B3AFF3C76B64ULL, 0xD0F6AC094C94EF6EULL, 0xFEE8FCFA54964899ULL, 
            0x50414BEE3A5EB8B4ULL, 0x087AF8751EA0C59AULL, 0x5F71AD66BEE49ADDULL, 0x8B23BD8535E6827DULL, 
            0xFAA8E6E2935D2FADULL, 0x49447E192829951AULL, 0xDFA896145E97A4C4ULL, 0xB3E46DDD8F98ECCCULL, 
            0x371B3679ED54AE35ULL, 0x2C6B039F2606C5EEULL, 0x36D09AD7D07FF228ULL, 0x9EA6F56EB9EA2BA4ULL, 
            0x670DE4654F206717ULL, 0xA3368710372431E0ULL, 0x56879819F4F4A016ULL, 0x066DFDE8E91A7108ULL, 
            0x716A578AA78A78E6ULL, 0xF5E6DBE56EC4673AULL, 0xC61B6737E99CF597ULL, 0x82572C868C2A4167ULL, 
            0xE1C72BAB277C6D94ULL, 0xB906863BEAD4DCF6ULL, 0x30946C512607184DULL, 0xDA2645361C956FA1ULL, 
            0x018CF611B5AF6C5BULL, 0xA8DDDBBCD567DBC1ULL, 0xAB47165636FC1D31ULL, 0xE0B56DD75882BAF1ULL
        }
    },
    {
        {
            0x4368135DE562546DULL, 0x3EB565F6F1F8786DULL, 0x0C27A1AA11346BD7ULL, 0x7753C50CE7E079A5ULL, 
            0xA30100F890263E2AULL, 0x09738AD13A419D17ULL, 0x2B422AB3751A25FFULL, 0x9C949514BE1CFA86ULL, 
            0x578BB813EE54627FULL, 0x55E4EF573396238FULL, 0x89ECA77B5822EEEAULL, 0xAE4D1743D70853E3ULL, 
            0x28DAB35DB744B1ECULL, 0x984A0CB54AA0EC74ULL, 0x87AD9D1C17B57689ULL, 0x7C6E3BF6C3DC75D2ULL, 
            0x65C8696C29F10E70ULL, 0xA79E055E862D7ABEULL, 0x6FB11871C661A760ULL, 0xAC65DD2CCAF65CA0ULL, 
            0x136130C1E41C4467ULL, 0x4355E128E0FD3F46ULL, 0xD7E03D7A5114FD97ULL, 0x9DAED50A77A1C51BULL, 
            0x6BC4FEC58A632B14ULL, 0xD391A934680DD7B4ULL, 0x8CF8B6CF63190E0EULL, 0x34B79FB6C5A2586BULL, 
            0xD6A5CA589990D929ULL, 0x66C4D577E24F5DF1ULL, 0x7194C29A7E626130ULL, 0x11EEB15008A875A5ULL
        },
        {
            0x14F0CFAFAF4D6005ULL, 0xF3B80C559DF535A7ULL, 0x716D33E0FFAF90FCULL, 0xF5366661C53545B2ULL, 
            0x9278583EC6F8CBB9ULL, 0x27972E792E7F33D7ULL, 0x4636BCBC35241F02ULL, 0xE62838074F4ADC88ULL, 
            0x6F88DF9A8BC8BAC3ULL, 0x91645B9A239D04C4ULL, 0x1920E229589CF176ULL, 0x5B1C7A6B136CF1F5ULL, 
            0x4C8F3E6A28F69112ULL, 0x37E71C4A351F8F5CULL, 0xDCB2F1AFB2CDC0BFULL, 0xF82A4BBB9BE749F6ULL, 
            0x37474C0E953D4F68ULL, 0x513BB5EF22FB1B34ULL, 0x686A9906BF8B3F38ULL, 0x928F2E6325D39A8CULL, 
            0x3F1CC3A42968FAD3ULL, 0x4FBBFBAA38BF98E2ULL, 0x8DAB97C336667536ULL, 0xEFD91797BA3E6AB4ULL, 
            0xA6887999F29111C2ULL, 0x27EB8C9972B8D789ULL, 0xF86476C6AC59D653ULL, 0xE82FAABC10E72D20ULL, 
            0x2E66720EF08CE674ULL, 0x53C55DB9E0196B19ULL, 0xC82AD2F40EBA0035ULL, 0x958BBE5F0F0C5F11ULL
        },
        {
            0x5D2B58C4FAFADBA6ULL, 0x969953B5A4CB2D97ULL, 0x7EF4BBF668135682ULL, 0x074A7A63AC772B7BULL, 
            0x28672C036F4F16C6ULL, 0xC1C254A805DDC05EULL, 0x65DD5333E9FE6C8EULL, 0x26480A32A0D16A50ULL, 
            0x2A0FD3F9A54D58C1ULL, 0x9C30A7354F9BB021ULL, 0xA30E8FE6CB72725AULL, 0x3C531D1E3E2521BFULL, 
            0xD06242A4B6A2C0E3ULL, 0xD62CBFA5FCB98F8AULL, 0xFC4D481E60813A54ULL, 0x55FA1CAA99115CA2ULL, 
            0x2A4E02864E1E3644ULL, 0xEA0AC441E200E19AULL, 0xB1B06B2FFADAEDBDULL, 0x9B82D6771F198D46ULL, 
            0x3B52BF611F32E4D2ULL, 0xF71757D80172EF65ULL, 0x04138DC6C54A4A95ULL, 0x44C8621FFE6EF209ULL, 
            0xA29E891F59B98D5BULL, 0xB155D1805C547213ULL, 0xBDBF712532292381ULL, 0x78FC416CD54DE035ULL, 
            0x1CF2AE8FAD5FFF1FULL, 0x22ED9506AAD54C14ULL, 0x633CC8DF8C327C55ULL, 0xC463BCA1735268B6ULL
        },
        {
            0x9A40879349495E95ULL, 0xBC6E0BEBB81B5FAFULL, 0x75FBE7FCB07FBCFCULL, 0xFAD887E059020562ULL, 
            0x7092AA61B24F79ECULL, 0x285FADC388344EF2ULL, 0x3A9F8E13417C4CF3ULL, 0xBAC65FD1950D0846ULL, 
            0x6E8C185FC599FEB1ULL, 0xBDDA10245E50106FULL, 0x1EE2FBA49C4BD345ULL, 0x642AB332279FF886ULL, 
            0x7C7942963C38B1BDULL, 0x2B26DAE3F6C0FA65ULL, 0x71FE2CB5834D3F1CULL, 0xCA67C43D80D672A0ULL, 
            0x5F32385D04C40B76ULL, 0xE07C01E4D0183C8EULL, 0x1245C54748D0F254ULL, 0xFA50DA1A1618EC88ULL, 
            0x5A94C39ED272C9EFULL, 0xE812B64FDE4FFB9CULL, 0x42EB14642B646182ULL, 0xDFC6BA351085C568ULL, 
            0x420EF57B4EEA840CULL, 0xDB313174033E4DEBULL, 0xBAA0693DEC67AD57ULL, 0x586DFEB3BC9FF89AULL, 
            0xE979BBF6693AA508ULL, 0x1865F00A83D97E0FULL, 0xB2703B55FF066E9AULL, 0xF6198F1642790528ULL
        },
        {
            0x4F3E4D989AB229C4ULL, 0x30CEE41DEAF49C0FULL, 0x418864029BFE5E5DULL, 0x4C7A1B230767664BULL, 
            0x3875384611015944ULL, 0xF17CBF6162D32005ULL, 0xFE689FBEA5A866EDULL, 0xE331D4530E696D07ULL, 
            0x71FB31F184D024A1ULL, 0xF1A7E1BBD5ADECFFULL, 0x7DA57F5FF0E29FD2ULL, 0x91C374FDA552136CULL, 
            0x64C984201D3B3CEAULL, 0xD256129DB35F8F95ULL, 0x1CD2DE38B42C285BULL, 0xFEE593F3B0039E28ULL, 
            0xB2597087E32F2925ULL, 0xC314405334C67A57ULL, 0x675EAB226B9A55E6ULL, 0xDA129F6247EF8377ULL, 
            0x62A3315634F74815ULL, 0x5F89AF735652A0CCULL, 0x9A58C26E0F7F5A2DULL, 0x781DCBAEEB222607ULL, 
            0x8A9498D0F9A31A47ULL, 0x67C077AA68B2357BULL, 0x180900393BAA8C23ULL, 0x402828B235337950ULL, 
            0xC25FA069D09721B5ULL, 0xEC3E7D248D803A53ULL, 0xCC18DF9F4A9D9A9CULL, 0x01BAFF7E3D2BE8E7ULL
        },
        {
            0xD3410AF471F657A8ULL, 0x9DEF90F725F4E54BULL, 0x1D40BFB120B17683ULL, 0x7FB9EF0192881E17ULL, 
            0xC4295064F28FEBD8ULL, 0xA1470333DFFBD69CULL, 0x09EF348BAA72D1EEULL, 0x968200E932586F02ULL, 
            0x7C434436A85E5E09ULL, 0x1C0A90943C9ADB53ULL, 0x42507AF1B66481EFULL, 0x8A5FF4593707A4EBULL, 
            0xDF74F4647289A651ULL, 0xB1776924891339CBULL, 0xB93165893D291BEFULL, 0xB86F36E72B7AFE07ULL, 
            0x0CA50BB68C5C4785ULL, 0xF454DF0D820BA4C3ULL, 0xCA33279850F39106ULL, 0x00B17FF297102349ULL, 
            0xD14A9914B2E292A8ULL, 0xF12DE1976BA80C50ULL, 0xC2CDF30E3B2710E0ULL, 0xF5993085CF2BCF62ULL, 
            0xA9DA2B42A50EF9C8ULL, 0xB918C331D241C692ULL, 0xEC56D54E87173524ULL, 0xCF5C102EF5ACED5CULL, 
            0xE09C0AFA5FA162DBULL, 0x9906DAFE73D623EDULL, 0xB2A20EC232D0458EULL, 0xEDB82388D99125D3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseHConstants = {
    0x391B660994142C65ULL,
    0x17F3F4680B1D70B2ULL,
    0x163A4DF99B6D358DULL,
    0x391B660994142C65ULL,
    0x17F3F4680B1D70B2ULL,
    0x163A4DF99B6D358DULL,
    0x3991CD39EC0633B8ULL,
    0xE2AEE56679B39A2AULL,
    0x20,
    0xAC,
    0x19,
    0x59,
    0x08,
    0xB2,
    0x5D,
    0xBD
};

