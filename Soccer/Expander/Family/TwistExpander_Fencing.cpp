#include "TwistExpander_Fencing.hpp"
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

TwistExpander_Fencing::TwistExpander_Fencing()
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

void TwistExpander_Fencing::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow);
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

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
        aPrevious = 16604274098010777989U;
        aCarry = 14385333487273460797U;
        aWandererA = 11563904965839631237U;
        aWandererB = 10337688637192587718U;
        aWandererC = 15246579289953503667U;
        aWandererD = 9444431351280943190U;
        aWandererE = 9750379297916725496U;
        aWandererF = 12077968715307697335U;
        aWandererG = 16210693996745730361U;
        aWandererH = 16475914008446209059U;
        aWandererI = 12043074238189723666U;
        aWandererJ = 10174668903699571921U;
        aWandererK = 13033508507120228984U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aArx;
    aArx.KDF_A_A(pWorkSpace,
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aKDF_A_BArx;
    aKDF_A_BArx.KDF_A_B(pWorkSpace,
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
    TwistExpander_Fencing_Arx aKDF_A_CArx;
    aKDF_A_CArx.KDF_A_C(pWorkSpace,
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
    TwistExpander_Fencing_Arx aKDF_A_DArx;
    aKDF_A_DArx.KDF_A_D(pWorkSpace,
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

void TwistExpander_Fencing::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [kdf-b]
    {
        aPrevious = 15587202655904207221U;
        aCarry = 11480432261906972162U;
        aWandererA = 10510404592941988650U;
        aWandererB = 18389235019573681992U;
        aWandererC = 17735367890665826921U;
        aWandererD = 12217655547745610470U;
        aWandererE = 11652810955709518252U;
        aWandererF = 11490868948791088443U;
        aWandererG = 10560381390720348902U;
        aWandererH = 14856919247997077789U;
        aWandererI = 13231300917306751409U;
        aWandererJ = 11118283260801801482U;
        aWandererK = 18204751819758113043U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aKDF_B_AArx;
    aKDF_B_AArx.KDF_B_A(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aKDF_B_BArx;
    aKDF_B_BArx.KDF_B_B(pWorkSpace,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aKDF_B_CArx;
    aKDF_B_CArx.KDF_B_C(pWorkSpace,
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

void TwistExpander_Fencing::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aSeed_AArx;
    aSeed_AArx.Seed_A(pWorkSpace,
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
    // GSeedRunSeed_B seed_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aSeed_BArx;
    aSeed_BArx.Seed_B(pWorkSpace,
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
    // GSeedRunSeed_C seed_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aSeed_CArx;
    aSeed_CArx.Seed_C(pWorkSpace,
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
    // temp storage: operation_a, operation_b
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aSeed_DArx;
    aSeed_DArx.Seed_D(pWorkSpace,
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
    // read from: work_a, work_b, work_c, work_d
    // temp storage: expand_a, expand_b
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aSeed_EArx;
    aSeed_EArx.Seed_E(pWorkSpace,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aSeed_FArx;
    aSeed_FArx.Seed_F(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aWorkLaneA, aWorkLaneB, // output lanes
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
                         aWorkLaneC, aWorkLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_g:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aSeed_GArx;
    aSeed_GArx.Seed_G(pWorkSpace,
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

        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aGrow_AArx;
    aGrow_AArx.GROW_A(pWorkSpace,
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
    TwistExpander_Fencing_Arx aGrow_BArx;
    aGrow_BArx.GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Fencing::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSourceInput,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSourceInput, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
    {
        aPrevious = 10923212122870087354U;
        aCarry = 18082184743332252841U;
        aWandererA = 10338105753106260741U;
        aWandererB = 14365735022139915598U;
        aWandererC = 16057015291653775060U;
        aWandererD = 15258452606990110353U;
        aWandererE = 14977229545007330596U;
        aWandererF = 13567736332971054322U;
        aWandererG = 16720626740102756011U;
        aWandererH = 15087212373008822181U;
        aWandererI = 17268270185651205009U;
        aWandererJ = 11717224964649795347U;
        aWandererK = 17726206449457691954U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aTwist_AArx;
    aTwist_AArx.Twist_A(pWorkSpace,
                 pSourceInput,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aTwist_BArx;
    aTwist_BArx.Twist_B(pWorkSpace,
                 pSourceInput,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aTwist_CArx;
    aTwist_CArx.Twist_C(pWorkSpace,
                 pSourceInput,
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
        TwistDiffuse::Diffuse(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
    }
    {
        TwistDiffuse::Diffuse(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Fencing_Arx aTwist_DArx;
    aTwist_DArx.Twist_D(pWorkSpace,
                 pSourceInput,
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_Fencing_Arx aGrow_AArx;
        aGrow_AArx.GROW_A(pWorkSpace,
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
        TwistExpander_Fencing_Arx aGrow_BArx;
        aGrow_BArx.GROW_B(pWorkSpace,
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

void TwistExpander_Fencing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 3 with offsets 6341U, 1849U, 7587U, 7840U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6341U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7587U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7840U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 2 with offsets 6712U, 6729U, 5543U, 1938U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6712U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6729U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5543U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1938U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 0 with offsets 5579U, 2999U, 6023U, 5579U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5579U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2999U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6023U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5579U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 1 with offsets 4957U, 7953U, 934U, 4937U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4957U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7953U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 934U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4937U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 with offsets 280U, 1754U, 362U, 1195U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 280U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1754U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 362U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 1, 0 with offsets 153U, 603U, 1853U, 503U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 153U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 603U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1853U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 503U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 644U, 1060U, 462U, 1426U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 644U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 462U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1426U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 1, 2 with offsets 1369U, 1603U, 914U, 2014U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1369U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1603U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 914U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2014U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1055U, 87U, 714U, 1258U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1055U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 87U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 714U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1258U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Fencing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 0 with offsets 315U, 6413U, 400U, 1051U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 315U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6413U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 400U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1051U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 3 with offsets 1712U, 4679U, 8087U, 3749U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1712U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4679U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8087U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3749U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 2 with offsets 1977U, 1382U, 8135U, 3027U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1977U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1382U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8135U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3027U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 1 with offsets 5542U, 914U, 2663U, 7885U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5542U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 914U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2663U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7885U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4779U, 7154U, 1533U, 224U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4779U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7154U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1533U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 224U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 357U, 1049U, 66U, 107U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 357U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1049U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 66U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 107U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 466U, 894U, 1896U, 1713U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 466U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 894U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1896U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1228U, 1233U, 260U, 1900U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1228U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1233U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 260U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1900U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1561U, 1492U, 987U, 1950U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1561U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1492U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 987U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1950U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 [0..<W_KEY]
        // offsets: 1639U, 1500U, 1448U, 1883U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1639U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1500U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1448U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1883U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseASalts = {
    {
        {
            0xCEB6DC5FA7BC8760ULL, 0xAE3834628EE07745ULL, 0xA4C5810EB0F0E807ULL, 0x83D2259C33EFEB5DULL, 
            0x59C26AA748A0FA7FULL, 0xFA253341A2FC11DCULL, 0xE3B77D180221644BULL, 0x9EB1522A40011758ULL, 
            0x945EADC08AE71A1FULL, 0x9579A4AED5D23F40ULL, 0x7031F1510B4F491AULL, 0x189E970973F8F895ULL, 
            0x1BD21DAC60E7D8EBULL, 0xBC7B927E12C922CFULL, 0x09CB39AA576484B5ULL, 0xB55481DF8AE904F6ULL, 
            0xE9F77AEF7429EF1DULL, 0x58EE939D213FB1AAULL, 0x16901490B06C4253ULL, 0x709CA5DCB225C126ULL, 
            0x0DAAEAFDC9AB1CA6ULL, 0x4BDC5C861117D157ULL, 0x2CE3FC047CC22660ULL, 0x1C0BABBEFE0DA5A4ULL, 
            0x0C1D5394D15F1ED5ULL, 0xB59955F74F8052DBULL, 0x6DB0671AFC5C360BULL, 0x847CA67F4C9BBBB0ULL, 
            0x75540FDC42BD5A85ULL, 0x25A58B0A1C55AE70ULL, 0x56BADD906F49FDCEULL, 0xBF4D67BB478A3766ULL
        },
        {
            0xBE468B6B3AC58B80ULL, 0x2BB5DB5C867DFCAAULL, 0x5F3BE7A8D0BA02BFULL, 0x3035585C4848B6F2ULL, 
            0x846B1A7150F66FB1ULL, 0xCADDD605BE04696AULL, 0x162678A2F405F653ULL, 0x48C2F097380ED633ULL, 
            0x963ECE4309C83741ULL, 0x5701435ECA623D5BULL, 0x5BC7B05DEDA86697ULL, 0x08768A1A7507ADA0ULL, 
            0x1EAE86C8CF3A8254ULL, 0xF64DE0855CA99B54ULL, 0xA88B5F9229649CE8ULL, 0x3D6B35FE7CDE7F9EULL, 
            0xB53403B075EE61A0ULL, 0x665AB5B5C7B240B1ULL, 0xE46CC4CEF3495440ULL, 0x8BD783EEBE3E16A2ULL, 
            0x84130B933D69F970ULL, 0xC9711CF23C18415AULL, 0x47639E0F72A4AD3DULL, 0x5766DE04B4906428ULL, 
            0x4EF753B3CF3BB59CULL, 0x78FB9B18A3330502ULL, 0xFDBFFD5F2E6B5D03ULL, 0xDAE5DFAED2CEAEDBULL, 
            0xC35C15E473DFB257ULL, 0x0893B1272723DAD1ULL, 0xDBFF146625455033ULL, 0x89170D39BFB28D35ULL
        },
        {
            0xF9E78EEFE1AAE810ULL, 0x5657808EFE970A0FULL, 0xD861520C0624099EULL, 0x1E45BC16184C100EULL, 
            0x0290FD36BD095865ULL, 0x02670191FE2A67F6ULL, 0x680EFC10552DA2A1ULL, 0xB21B8FAC8579588FULL, 
            0x4CDCE8D0CBC66C74ULL, 0xAFE1899C2EEE291FULL, 0x5CC32013C33ABF3BULL, 0xF7B135157C4C2384ULL, 
            0xF9DDE463843E4AE4ULL, 0x113AEEA120ECE5B0ULL, 0x7DDB58E869396460ULL, 0xE264FA45F117ED97ULL, 
            0x9A72166B46B8D107ULL, 0x5AD287D739CB3C95ULL, 0xC01DA488F1B2095BULL, 0x2D18FBA87C38F30AULL, 
            0xC833F98033985589ULL, 0x5B1CC14D3C7E603AULL, 0x25A3A3BA45226A84ULL, 0xE1ECDEB965003A8FULL, 
            0xB1936FBD1F55A7EFULL, 0x9353E62F8BD4BE27ULL, 0xD1312CF7B8F63232ULL, 0x1DAC6DD54E1C5CBCULL, 
            0x47D519F6D55A9848ULL, 0xD75FC45BFF6F1FB7ULL, 0x145D037276F07842ULL, 0x95B0A23F52F4D491ULL
        },
        {
            0x2E1C8178DF03268AULL, 0x7C95E1C180E07FDAULL, 0xE96DF47C3FA22812ULL, 0x744015F1A2FAE58AULL, 
            0xC980A06EC2DAB857ULL, 0xD5CBF2E9D437CABAULL, 0xE8A7A8BAE6969ED0ULL, 0x366690E0D8D914B5ULL, 
            0xA414477B9B6D8E5DULL, 0x1DD197A5EB06729DULL, 0x2FB340C37EE9A195ULL, 0xD5C084383AB0F653ULL, 
            0x8C660CB4F5830E95ULL, 0xD3123A15A3B7ED15ULL, 0x0F0BF41AA3F90033ULL, 0x0C93FDE4370EC236ULL, 
            0x232F49D1ADF62C73ULL, 0x616D4558BE35636EULL, 0x0D9CEDB635191ABAULL, 0xE0CFBFDD36FCA8A6ULL, 
            0xF5A42E82150AC1F3ULL, 0xC7EDBE6A2F07F5E0ULL, 0xE8F0DB798A07F129ULL, 0x851DE8546D18217DULL, 
            0xDB283CF7ABE862F1ULL, 0x14E226684532DBC4ULL, 0x6D0AFE8CDBC23821ULL, 0x114C5BD42D112AFDULL, 
            0x3EDD6D613EE833C4ULL, 0xBE5378FBBFC50088ULL, 0x00689574D2ED0BFCULL, 0x79322A52374343D6ULL
        },
        {
            0x9B59670D93317F50ULL, 0x361D19CD2FAFFE57ULL, 0xC2ABB865D48CB638ULL, 0xC522AA24A60E1B98ULL, 
            0x9A81681C9C800F21ULL, 0x83052AD3EC4ED14BULL, 0x48A7A25C74E0A1EEULL, 0x40A7A63BDA53D0B5ULL, 
            0x4728127F668D5509ULL, 0x569468635A9F08D4ULL, 0xB3760862C72C8634ULL, 0x8A3183FA2ABDC951ULL, 
            0x584474DCC7F8EA42ULL, 0x72F15DEFD331D39AULL, 0xAC90E92B9282B6BEULL, 0x719D3230D0D104BCULL, 
            0xBA3FB31E7C27CEFFULL, 0x6090CAE52CDDB7F6ULL, 0xCEF23AF2E6D1AEAFULL, 0xF3C325A3F4C08A80ULL, 
            0xCDA598B10932897FULL, 0x6292BAE6F0AB0B64ULL, 0x3EC811602F60DBA4ULL, 0xCC888B1CEE1DA2B6ULL, 
            0xA0B227AAA1351850ULL, 0x7CEFBAA12CE406C5ULL, 0x6F742D6739C184B2ULL, 0xB999280C0C451122ULL, 
            0x345C449D35498EF7ULL, 0x00FE4379B3317C48ULL, 0x65D3F82EE084AA49ULL, 0xE3E0D9F394F12718ULL
        },
        {
            0x43AD3481D936AF94ULL, 0x952840D4E94C8729ULL, 0x0B9B9015334D01E3ULL, 0xC9A71D7C5E41828EULL, 
            0x2DF83B9573BEF064ULL, 0xB7F335F455BC1E2BULL, 0x52A20A351AD76D1DULL, 0x70B04260423E9DDAULL, 
            0xDD022CD7A985A476ULL, 0x5D1131BB1B6DD7BEULL, 0x59F941F8E47D440CULL, 0x29FEB98BD433CC8DULL, 
            0x822B76E49F605DFAULL, 0x93266CB8CB0CEB7CULL, 0xC12C82C3A782B188ULL, 0x0677087B38F36032ULL, 
            0x97CB9F5C956F04FAULL, 0xBC242B0979ECAF4CULL, 0x8F742E844A0DC9C1ULL, 0x0DAEBA2E7A76B30BULL, 
            0x7EBA8288CC6BF5F7ULL, 0x6595335DB5832AC4ULL, 0x500841B910D00C25ULL, 0x4E9440041A97A4BAULL, 
            0x1256C805A9E41A45ULL, 0xBFE1CA88D29A6BDFULL, 0xC6A1234805C424B4ULL, 0x54A5B9553B98AA96ULL, 
            0x32D4F1CADB397231ULL, 0x21DD50C4482561CAULL, 0xE592242D34C0119AULL, 0x99BF4CB154D8259AULL
        }
    },
    {
        {
            0xE2B434753A3B9179ULL, 0x654F10ACEDF7841AULL, 0x7F7A06E66D241B23ULL, 0xBFD8AC4CFD18F5D5ULL, 
            0xF3E646572533D160ULL, 0x7A90DE5CFCBBFAD8ULL, 0xA1984C166788B10DULL, 0x5A03F64DA2E5B897ULL, 
            0x248E414E6BCF34E6ULL, 0xA38AAF48ADE819EEULL, 0x03F188F8CFB961D5ULL, 0xF6B6D198541B2E29ULL, 
            0x16676A84433F39CEULL, 0x8969ADBE5E6AFB85ULL, 0x676E7F917214E75FULL, 0xD2BCFA5E2E3C879EULL, 
            0x5E111E06A49A27D4ULL, 0x4D661AE563A4FB8EULL, 0xED84BE8C36647FC1ULL, 0x4FF7AAAD53999C34ULL, 
            0x4398E70BED687134ULL, 0x5D5D626C9390F781ULL, 0xE02C1C05041E2751ULL, 0x266E9922ADF60461ULL, 
            0x3339C387BF6758F2ULL, 0x6E7AF1251B06B10FULL, 0x44D51EF3F34AC4CFULL, 0xB795D5B70A2B16A6ULL, 
            0x8226EE90E506CF5AULL, 0xB42CBFC00F39F784ULL, 0x0BC1E8A714F8F93CULL, 0xF19FD718DB3F0147ULL
        },
        {
            0x3D40324319FD64CAULL, 0xD49A15F215D5AF53ULL, 0x29976B0762CC76BCULL, 0x19729CFD9C5990BCULL, 
            0xFA25A74AB3256E91ULL, 0xAB3357AEA71228ABULL, 0x1E02B90D4ECA7534ULL, 0x76A52238A7C192FCULL, 
            0x0E693A6732704D79ULL, 0xF59E489ACF2D63FDULL, 0x08AD6B40A9965D8EULL, 0x930C0F8DC7A6E5AFULL, 
            0x665CBA9F084F08B6ULL, 0xDC5AEC1A9535F771ULL, 0x12EB773BEA0CEF34ULL, 0x65C5B4ADAC6CB6A4ULL, 
            0x67EACE5428943B7CULL, 0xF15306A83209F1D5ULL, 0xF18B510A59352871ULL, 0xFA27D3189BF72706ULL, 
            0xCA17BF3174E45BC3ULL, 0xE0C15CE33C36410AULL, 0xD6FD7B2B708C4216ULL, 0xB8A6582D09876CE8ULL, 
            0x17633D1A9EDFDFBBULL, 0xBD4B88522C787C08ULL, 0x324031381D1F8315ULL, 0xDE1A066DD529767BULL, 
            0xD1CEB25117DE573DULL, 0x5B56515E3F1014AAULL, 0x6D366B6F2CA46A34ULL, 0x70C28A3D328DCF1BULL
        },
        {
            0x03C4DE21D86D118CULL, 0x615F006CFE8D1017ULL, 0xEE1C30FE751469BFULL, 0xF4A344E8DA3B1AADULL, 
            0xD9B551A7DAD859A4ULL, 0xD3A0F67ACA8468B8ULL, 0xE964906C7D8A028EULL, 0x76959E9236621C6EULL, 
            0xCE66C6A501B3788DULL, 0xCBC5D5CC5D48140DULL, 0x3635E466E27BF39AULL, 0x9521462F9C4E6F21ULL, 
            0x860B28D300C2B381ULL, 0x8CF034B2D8C826A1ULL, 0x16D073E54454E009ULL, 0x3DA709E40CB69167ULL, 
            0x71D6A1274D984866ULL, 0x43AF4045D86549BBULL, 0xC43E3BEFF4646BCDULL, 0x77FD07C51085291CULL, 
            0xC27CA83B155563B4ULL, 0x516F8389E29124B9ULL, 0x7031BB383EC04F2AULL, 0xD6A3BC5508E82484ULL, 
            0x11E63E2AE662C4B6ULL, 0x2B46E9C503F5A4D8ULL, 0x32B4AC387810D7FEULL, 0xC04B45F331E73FD8ULL, 
            0xDD5ED262BDAE2DAFULL, 0x57908B7E2C68E1A6ULL, 0xF3D6D1F6094DC081ULL, 0x0D2F0F1194DCAB73ULL
        },
        {
            0x19323E7B2B73E4E8ULL, 0xA8A524A40DCC5075ULL, 0x994B51778A552351ULL, 0x1C61793413B063C4ULL, 
            0xBB4F762891C19EABULL, 0x66DB7EF658D14D13ULL, 0xD7A431332F13A748ULL, 0x3A84EAE054BE39D9ULL, 
            0x2F0E1DFD31D5FECDULL, 0xFE2424FE558BBA25ULL, 0xA41772820C541AC2ULL, 0x7CAE7AB1D71E5E56ULL, 
            0x9D1337B0B51BC42DULL, 0x842ACB662CF58C74ULL, 0xA51049205DB6CEF2ULL, 0x3B199A7ED51DCC2CULL, 
            0x14F10C5E2232B96EULL, 0x249FD7EC94A0E11DULL, 0xFED98B75C636CBBEULL, 0xDF568FE80314FA79ULL, 
            0x8627AEF74493C850ULL, 0xDAEEEE6D85A7FA90ULL, 0xE3DA3F4CA76FA12BULL, 0x07055F3DEDBE9728ULL, 
            0x71F1A9E5B2651200ULL, 0x14C8D4ABB3A61F02ULL, 0xBC2D04DFB86999D1ULL, 0x2DB82F210F295926ULL, 
            0x3021CE59AA140915ULL, 0xF07555F5E58AE4F8ULL, 0x133B9001AD6A69C6ULL, 0x5D4810D4587C18AAULL
        },
        {
            0x90F5A56061590106ULL, 0x257A8EA65A9F099FULL, 0xDCD806DA1D9C46D5ULL, 0xAE605B54634C0103ULL, 
            0xD6EFC2C5EEF54B81ULL, 0x859E8EB09C2E865DULL, 0xE6DD102228BEC155ULL, 0xFC9A39D5A94F9EB7ULL, 
            0x27E6E4A64CD9CA88ULL, 0x3813E00B32766777ULL, 0x345CCFDCEA5E4942ULL, 0x830B733D8CFF8373ULL, 
            0xF548C9119C00FB49ULL, 0x4CFDCA05D048DF87ULL, 0xD05E47E626AD9133ULL, 0x7DAAE1E0C17F2CDAULL, 
            0x8FB36EA7EF87CB78ULL, 0x1B554DA6A45B8D8CULL, 0x76CDC91B5BB837E2ULL, 0x49702B8F2BE9D6DBULL, 
            0x3AF2E7E7AA447690ULL, 0xA531F3D806F32637ULL, 0x11F29673CFBBACD1ULL, 0x3940A56D7BEE2726ULL, 
            0x43FFC4E1362AB151ULL, 0x684F0C438A5FB0E7ULL, 0x8904B53744D97BB7ULL, 0x066D806C3A32CF12ULL, 
            0xDDB86D76D676A925ULL, 0x68E816702E722661ULL, 0xCFF3AC0184BA84C3ULL, 0xFB419221506B02C7ULL
        },
        {
            0xEA144FACA43E2C16ULL, 0x4E3DD68655D2697AULL, 0x6A62BE938A413CE9ULL, 0x52433336E19051A1ULL, 
            0x6A1728FAD1FF4321ULL, 0xDD68C0330B88A021ULL, 0xB6111304AD1FB4DEULL, 0xFFFF182428915541ULL, 
            0x28309A25F1FBC597ULL, 0x7EAAF5B9840107DCULL, 0x0764585C7BFAB254ULL, 0x444DD891134E4645ULL, 
            0x1D37DE8B92E851B7ULL, 0xAE8F1538E95F467FULL, 0xBFFB4CEDC1ABA7D1ULL, 0x0DDDB300853E4B1DULL, 
            0xA3A6BFD02E404BDDULL, 0x29A9FC9EDA15226AULL, 0xAA430D2232C645D7ULL, 0xDF10109460F04DFCULL, 
            0x693A97AB61FE9571ULL, 0xFC44E72EB14AA4C6ULL, 0xAE5916941CACBD23ULL, 0x294E154D1E3711F7ULL, 
            0x970D36E3E60369FFULL, 0xB146DE081DF28C52ULL, 0x5825E50C4E36DF24ULL, 0x8C6FDD970B394153ULL, 
            0xEC265D9EBAADBFE7ULL, 0xC2DB26C44F22664CULL, 0x56D99B0E000DAE24ULL, 0x6D7D330B448AE7B2ULL
        }
    },
    {
        {
            0xCE803CF8AE75D4D0ULL, 0x4F3C84EBB10BD0F3ULL, 0x6994B4FBF0ECA2E4ULL, 0xE1884654323FB34AULL, 
            0x43857249FD1AEE93ULL, 0xE3F5D43D7A592EE5ULL, 0x1C61165B8502306AULL, 0xEE17E3C3D10B3A58ULL, 
            0x0F9EA55243568E9CULL, 0x62A65815DAA48FE9ULL, 0x69ACD510ACF4D9A7ULL, 0x790B89E5AF18061EULL, 
            0x77A2CE41D76EB327ULL, 0x295124BB8E8355DDULL, 0x6BD6B9C5B74CBC9CULL, 0xA78310D046DF1D16ULL, 
            0x5C1E8F2519E5AE17ULL, 0x68FADFD052307606ULL, 0xC3399653ECB7DECFULL, 0x525960585DED930EULL, 
            0xBCAF80AA4FDF4758ULL, 0xA70B24B4D757B4EDULL, 0x20DC6EFD991BD303ULL, 0xCE79D11D8F71B240ULL, 
            0xBAD60DC5550D5EDEULL, 0x634E0BD47045BE42ULL, 0x965E3DB0C77C3F1FULL, 0x563EF7F0361F6713ULL, 
            0xA454FE0EE50F1689ULL, 0xC3AB984049CDEAE5ULL, 0x55088F436A0BE9FAULL, 0x40DB50B115A7E4ECULL
        },
        {
            0xDF96E033725EADE1ULL, 0x8F107F4A60D3106BULL, 0xB8029B932C2A12DBULL, 0xDFEE94E2E94D3B26ULL, 
            0xE27269C1339306C4ULL, 0x0344F00E5F2EF899ULL, 0x26D06EE3ECCE72ADULL, 0x5323DCF65C5447C1ULL, 
            0x4BAF101D8590B5F0ULL, 0xBFF2D213F9E0E408ULL, 0xD8DADD63F1A31C93ULL, 0x03E2D9629D038963ULL, 
            0xD65284E301A3D590ULL, 0x8CD190B13FB10B41ULL, 0x76CA8A62C5A86EA5ULL, 0x7CB1C1D89E3E7C93ULL, 
            0x5435FF5BE24CBCF0ULL, 0x9A0564DCF5E50966ULL, 0x9AC9672E8860C949ULL, 0x08C5371820B64C8AULL, 
            0x04A185963C2796C7ULL, 0x95EB099FECB618ACULL, 0x956C6654891F5130ULL, 0xB2DF75D281C6DB2CULL, 
            0x11417F107EC6912FULL, 0xC717BD65000B56E6ULL, 0x6BDBB85F1FAD27D0ULL, 0xF5B29C194F0B8B2BULL, 
            0xBD55CFFAE99FDBC1ULL, 0xBB7C78120BD71C0FULL, 0x8BC2A215567E8BABULL, 0x4C0EC3B5189F8F19ULL
        },
        {
            0x30BE777D149A9F07ULL, 0xA514E881166A992CULL, 0xCCC0E5B7602246A6ULL, 0x38353411DFC1D039ULL, 
            0x1B59D15B6083BE90ULL, 0xE1C79A26071A609DULL, 0x966CFD78623CA297ULL, 0xFD8D7910B774B196ULL, 
            0xC390C578CA2341D0ULL, 0x3DCEBFCB220210B7ULL, 0x5985B947817ECD8CULL, 0x0F168B66D4657AE4ULL, 
            0x4142EF8FF2796F8FULL, 0x91C915243115DAC4ULL, 0x920C0B0139B6B32EULL, 0x5243ABE0D4D927BAULL, 
            0x95FB2973EE27991AULL, 0x7C5A2F70C10D3C44ULL, 0x5630F216C19787CFULL, 0x8C81BC4BCCD6D370ULL, 
            0x42AC1DCA83CF60FCULL, 0x4F267B6C315FBBDFULL, 0xB53021E619D7CF6CULL, 0xDD503EB07E4FF25EULL, 
            0xACD68B50AD473D6BULL, 0x471E1F14DAD3D166ULL, 0x567C72CD77D3D61FULL, 0xD4ED7739ACA4D952ULL, 
            0x961C592E58E8EFAAULL, 0xBBF8686C5D24E442ULL, 0x86FFED7209B8EDA7ULL, 0xCEDE98476DD61BDBULL
        },
        {
            0x89773F41B0C2D8FDULL, 0xD1FB802B1B2EF5B8ULL, 0xD85B73081AA683B7ULL, 0xB5D5B9B3FCE0E34EULL, 
            0x798007BB38090E70ULL, 0xA67BA816602FB95EULL, 0xE2E0328E6F72F5A2ULL, 0xE0EBF289C376240FULL, 
            0x469967B55004B819ULL, 0xD678E166D70BA958ULL, 0x9EC18461889009ADULL, 0x0C8455EA2C01FE3AULL, 
            0xDB9C727DD1372CB1ULL, 0x91F1A9DD1C8E9179ULL, 0xAEA287A02AF9DDA1ULL, 0x4A48D6A0BB484BDAULL, 
            0x5F20215CBBC87156ULL, 0x7F83B8DDD81E1942ULL, 0xE3B4E0763DEBDBCAULL, 0x34A72D7303DF9539ULL, 
            0xC496BE26FC25544FULL, 0xD5EC5A22150E795EULL, 0x12C688FD283B4760ULL, 0xE085908992A672DBULL, 
            0xE4A8CF4484BEEF88ULL, 0x012DB97EC055333EULL, 0xB0007ACEED1E4E5FULL, 0xEF670CBBC811F4DDULL, 
            0xA434B5107285BEA9ULL, 0x75E4B77EA6B87FD8ULL, 0x97F467F9E3D74290ULL, 0x776FFE3A78C651BEULL
        },
        {
            0x32BBC2D05FDC6D82ULL, 0xE3F2AB2DEC2F7BBFULL, 0x56FF8C37817153BDULL, 0x2856B18242AFE3F5ULL, 
            0x500EDADA01972196ULL, 0x16774C6F8C711936ULL, 0xC16CF38EBC67467CULL, 0x6C126889C6071BC0ULL, 
            0x32D53AEB21B0C726ULL, 0x6C6F3274168250BDULL, 0x45673E37D441CE80ULL, 0xD57DFE18E0FE2170ULL, 
            0x4C31203C0E43A9BFULL, 0xD8C9AF08E1E672E1ULL, 0x526161E542270FABULL, 0xE67AA16800EC7415ULL, 
            0xD79C3FEE240204C6ULL, 0xE5422DEBA38FA682ULL, 0x2BC1FAA5995A2967ULL, 0x828B141EB2AA357AULL, 
            0x9DC34E09DF36FF80ULL, 0x44494722AE801F3FULL, 0xDE6F11C3899A721CULL, 0x9E04CD74E1DDC323ULL, 
            0xBA87C4796ADE319DULL, 0x36C4BED8CBA45EF8ULL, 0x16BD476F2DA35076ULL, 0x3A1CF6E570FA79DFULL, 
            0x023CB38B46151889ULL, 0xA6F5261C2F4213DDULL, 0xBB315622DBA7CF61ULL, 0xCA302021D4FBC470ULL
        },
        {
            0x7F127228DC20B6BFULL, 0xC7E28C2516AEA3DAULL, 0xDF108B5E8251C875ULL, 0xDD80426B2FCFFA7CULL, 
            0x0FDF56B8B2B01EADULL, 0xF92B763AEA3CEC67ULL, 0x75D6634C07AFC100ULL, 0xEE204812E14B1696ULL, 
            0xCD4AB2BFEC9F8BB7ULL, 0xAC3528664DAC7045ULL, 0x2FC98DD23156D3B5ULL, 0xD95F0325CED4565BULL, 
            0xF416616664D33BAFULL, 0x54B03BEE8454473BULL, 0x04C90E4B675E2340ULL, 0x73C8B46F0682A052ULL, 
            0x8541CE622C0A5AAFULL, 0x2AF626D55AD3F8A3ULL, 0xA0A197B0ABDFDC59ULL, 0xAF470C1455D81293ULL, 
            0xDA384A1E18009C51ULL, 0x4747AFC39BDBEB14ULL, 0x9C73140AB1D02EBBULL, 0x5B585B97CA8B36C9ULL, 
            0xEF81DE21A6E4ED92ULL, 0x942DAF4A54B3728CULL, 0x725A4B8BCF760B65ULL, 0xC285743EFFC0CDFDULL, 
            0x3A19D353A17F47DFULL, 0x5A08332D81080E90ULL, 0x9A7D09427B98BE58ULL, 0x0AC5D5D071EE4CD5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseAConstants = {
    0x76B48D4D6D493BEDULL,
    0x7228424DC7CEC0E8ULL,
    0x4C646CE534CC33C9ULL,
    0x76B48D4D6D493BEDULL,
    0x7228424DC7CEC0E8ULL,
    0x4C646CE534CC33C9ULL,
    0xD85B84C518454A14ULL,
    0xD159813B5B98E0F7ULL,
    0x06,
    0xB7,
    0x4B,
    0x4A,
    0x3F,
    0x78,
    0x31,
    0x3A
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseBSalts = {
    {
        {
            0x9120485BA2E5DE42ULL, 0x3A2252650EB8F41FULL, 0xC9C9FDFA0483E0A7ULL, 0x287B765CB3341F00ULL, 
            0x9AECBCB6B31A56ABULL, 0x4FE2C2F498488A9AULL, 0xA1CD1AC11A4ED19BULL, 0x5535F72D5F708D81ULL, 
            0xC791EBF3C7FA5591ULL, 0x906437B01447E5FBULL, 0x67812DF0229B8255ULL, 0xE997A7922C1BE2EFULL, 
            0xB71D0D748DB2D33AULL, 0xB626B7BFD9A2647CULL, 0x59CE94A047A6DEDEULL, 0x3C98147F16A1C2CCULL, 
            0xF5A0F485EA0C078FULL, 0x8B7727D7DA2DB268ULL, 0x3650CC67BA361E73ULL, 0x2B5AFB4E94D5E6F0ULL, 
            0xCC635A7FF961EB62ULL, 0x70D54FD6DD76484BULL, 0xB267176AA92477D7ULL, 0x53BAAA2B3DBE4C5AULL, 
            0x2DFCCA8CB1C7A5F5ULL, 0x6CFEE1CD7586F830ULL, 0xA2B259579E78F88DULL, 0xD7B4B42E1F1306A5ULL, 
            0x537D2FFEB252A925ULL, 0x12EE98FF9634C702ULL, 0x8F3B6804B47A01EEULL, 0x713CE5D1A09FAE37ULL
        },
        {
            0xCA2B44600325CCEBULL, 0x8F40C8DE2FEDEF2EULL, 0x20A8BFBE6BE1881AULL, 0x08EB098EADD53CFCULL, 
            0x4E7C059A889DC373ULL, 0x6AEEC1DCE3633F09ULL, 0x15008F9248C7422BULL, 0x71E3163D46079AD2ULL, 
            0x43EDD4AF300D0556ULL, 0x3F8ACD99A4298C3FULL, 0x94A7770100E15F28ULL, 0xEB89662698E4D1BEULL, 
            0xC4E50BCCB84B4669ULL, 0x314DA9845EFD0383ULL, 0x13CA9B3CB5362731ULL, 0xFD1E0AB9496A84B0ULL, 
            0x0DA6B278A337C1EEULL, 0x8363731265DB1116ULL, 0xDA54E706A62FD59EULL, 0xD4C8DDE839BB94B8ULL, 
            0xD3F25CA8AE72F203ULL, 0x9BE3579B09D4FDB2ULL, 0x34B55798559017DAULL, 0x673CA6027855174BULL, 
            0xDDF817D845338E7AULL, 0xC74DFDDAA84F8B02ULL, 0xD6C0E48933BDE792ULL, 0xCDD8BA32AB050993ULL, 
            0x6A98EA1C39DEE64FULL, 0x5EB88876BB05A93FULL, 0xCAFBC26353816743ULL, 0x71D39D4521EE16F7ULL
        },
        {
            0x8A97F4126BC84E04ULL, 0xED437CFC8459DB93ULL, 0x94A9AC0FAE9AE04FULL, 0x2958C61B613B42A0ULL, 
            0xEE7D3D65601553CFULL, 0x567449BB50865FB3ULL, 0x6181FC072889BAF3ULL, 0x5DAF6F173974530EULL, 
            0xAE3B484A4386A2E3ULL, 0x5DC44F320F2F0500ULL, 0xDD1486989DEA81B0ULL, 0x372D1400492394D9ULL, 
            0xA283CD94F14AA3CFULL, 0xE6D1A0AA3A120745ULL, 0x61903AB866915D5EULL, 0xD4110252EE07EBD9ULL, 
            0x698CDF79C2761492ULL, 0x2858F57117A3FB28ULL, 0x278779F46F655DF0ULL, 0x227EB564359DC1B7ULL, 
            0xCD557F8704DB1700ULL, 0x247AA1E428B0DBCFULL, 0x55F7180C2993A39EULL, 0xA53BF98850CEA253ULL, 
            0x42A009402E3D2178ULL, 0x8E2821F3A1A2B830ULL, 0xC0EF00395276122EULL, 0x5C8760DBEC579636ULL, 
            0xAC68DA000A25AFD6ULL, 0xE384183D3A34ABCAULL, 0x6B8BE4BBD43E42B8ULL, 0x73B4F2CA433C980EULL
        },
        {
            0xA744D729EF2BA68BULL, 0x4ED64FD7CDE9BCCEULL, 0x1F3A8894613FB023ULL, 0xDECB1A6F01C31C0CULL, 
            0x87A09AA9D1DD8343ULL, 0xEC759AF0EC2CF621ULL, 0xFAB9AB1D50DF2F1DULL, 0x7F34F4B5544A7B10ULL, 
            0x992225FAF0CAE7D2ULL, 0x3AE9A3397E7DA5D1ULL, 0x71FEC82717E31CC5ULL, 0xC097CB1E3C4010E7ULL, 
            0x018885709B3A8CC8ULL, 0x5C4D7B24FA1BA9FFULL, 0x59C3D56712FA031FULL, 0x1F5CE19BC9A00E41ULL, 
            0x75DF0A6755F64B0DULL, 0x815EF3B0BF2689B7ULL, 0xB6EFA62990B616DFULL, 0x08A3CC87F9C27C97ULL, 
            0x4CCF2D08088D1ED7ULL, 0x3B8C23A246A50D40ULL, 0xCC510F8037B284D1ULL, 0x3867008FA3E78EFDULL, 
            0xA889E618BAE84F7DULL, 0xE6159A8BA08DF1E3ULL, 0x946C002F8C4A770BULL, 0xA1E5AA6DDDFCC795ULL, 
            0x96E2D5AEA4C39CDCULL, 0x417741BF754FC978ULL, 0x3CFCAB228711226AULL, 0x557813ECB7449841ULL
        },
        {
            0xF4347AB2990C2F4EULL, 0x412C26219AA273B0ULL, 0x9843D2CD752083CFULL, 0x25FA7821F4496916ULL, 
            0x0BF0D90BC96F0271ULL, 0xE90FB300F81CC13EULL, 0xED071B885CD45C41ULL, 0x1BE25F722D2A39C6ULL, 
            0x2F7F82C266397983ULL, 0xFE78046A96AA89A1ULL, 0x40EBB16F096C08C9ULL, 0x21F0483C0BBAAD89ULL, 
            0xD73343ABE11BAE0FULL, 0x11DE333B3DD48D56ULL, 0x92FD26DE951A8A8CULL, 0x308E346756D2FCBDULL, 
            0xD4624945C016187FULL, 0x2D46F10CB50BD09FULL, 0xBA4BDB9F34D6A8AAULL, 0x6F92B50C6D783DC2ULL, 
            0x64E7D65498498CE9ULL, 0xD2A86BBB4100D80DULL, 0x709AE03543A7645DULL, 0x371AE8748EE9626CULL, 
            0x961130B612F8B2DCULL, 0x8EABE1BB5A0521BDULL, 0xB3B0C6F5378A6D5FULL, 0x60CBC10847F6DFFDULL, 
            0x8BBB970411DCFC6BULL, 0x26DACD28A18010F9ULL, 0x5B77AA15510BB0A3ULL, 0x88D5A1F6F78A4B10ULL
        },
        {
            0xFBB8E6B1C8EB6ECFULL, 0x48242FF367D3B515ULL, 0x809AA639305C1C14ULL, 0x1680D9859199C4AFULL, 
            0xF9E648B759EBD20BULL, 0x696426B92EBED9B9ULL, 0xCA7186C1660F5E64ULL, 0x19CC80A616AE4FC6ULL, 
            0x9C82F11C59383105ULL, 0x189C0FD3C53E01B5ULL, 0x7C1076361356A08EULL, 0x259FF7A4560CBE57ULL, 
            0xA2170591D00831BFULL, 0x27F03D15FB264315ULL, 0x902DF2EB30CC0919ULL, 0x5758A7352E270729ULL, 
            0xD03230ACDE2992E6ULL, 0xF02CDD33FE9F4BC7ULL, 0x539659DE540F0A69ULL, 0xCA7F34E481F8654DULL, 
            0x4066D1D66F8043E6ULL, 0xD938A68EBF3FC824ULL, 0x50952B265777FAB6ULL, 0x9F334A8D44A6F33CULL, 
            0x9A874639854B3376ULL, 0x67AEB3E808D6894FULL, 0x93B8C1BD02C94451ULL, 0xD3A2D3D97F16D3A8ULL, 
            0xA9C99FB4FA96AE42ULL, 0xDD836E43E4A2D042ULL, 0xBF8752CF63BB312CULL, 0x0096239A295C4A49ULL
        }
    },
    {
        {
            0x760182B687F25984ULL, 0x17D0DF7B06F9C8ABULL, 0xB1E310F78FBD9792ULL, 0xC13B1198A872DFA7ULL, 
            0xED93A1C92D6247AAULL, 0x001393CB41F44C1FULL, 0xE816A0E8EB66C208ULL, 0xF3F04F526AAA508BULL, 
            0xEE1BFE53B953E31AULL, 0x03F90EFB01E1246DULL, 0xAB11758CBAA59ABBULL, 0x7290E65030F04291ULL, 
            0x29505867626A2F14ULL, 0xF3668D8CBFFD365BULL, 0xB8B7F4FFD2B866B9ULL, 0x21B99DF194B29192ULL, 
            0xDF37681BD3EB949CULL, 0xFF2E76FB8FDE7BBAULL, 0x03D05D254FDC7446ULL, 0xD7B3EE158DAB573FULL, 
            0xD352D2986A3CD7A5ULL, 0x267C048E6CF936D8ULL, 0x53CE78E1D7CA1379ULL, 0x8C40048CEA708949ULL, 
            0x3D94E2546CE4CE72ULL, 0x04D507508F15D2D2ULL, 0x26E78F8FA57070F4ULL, 0x14C8C2A265C2F871ULL, 
            0x212A0F5396202A0BULL, 0x1022D89CF41B2FD5ULL, 0x210255A8726BEDA2ULL, 0x74090FC2CF015560ULL
        },
        {
            0xB53C1A023D0F99FBULL, 0x313F19DE57C4D022ULL, 0x399AF1931214C706ULL, 0x4B9F743A0A15CE3BULL, 
            0x8B99F0EA9BEE7E04ULL, 0xC432B6A3D22D1139ULL, 0x0E121C0174A1E266ULL, 0xF35E480ACB78AD89ULL, 
            0xCC377D3187AB23E4ULL, 0xFDDA8768B0302E4FULL, 0x4ABA5D79C5CC5071ULL, 0xD913A92A17890E71ULL, 
            0x7BE9CE3C356544FCULL, 0x6BE74DC342F04568ULL, 0x568939BE04FEF49EULL, 0x6D071A9C5E79A6C0ULL, 
            0x5017E38B9F629D24ULL, 0xBE285123D8B08E37ULL, 0xE8A2840B324D57AEULL, 0x958952167C133E8EULL, 
            0xEAB48BE82EC62A1AULL, 0x87C7BF0F72B28592ULL, 0xBF02944F178E0A79ULL, 0x2599161463214EFEULL, 
            0x36280CFE6AC9FD41ULL, 0xE2D9C892843104A8ULL, 0xD0276FE36E8929F0ULL, 0x3F3C4B36198FE3A7ULL, 
            0xD758715A69171CDDULL, 0x43C18406389E0DAAULL, 0xF459CD91EBB0E4EAULL, 0x7560A3A2E9ED3EDFULL
        },
        {
            0x9206E82B7F0806C4ULL, 0x064CCF69A2062E22ULL, 0x00B70C3F8C63D13CULL, 0x17D9565A2177CF80ULL, 
            0x46E13A1F4A52EF29ULL, 0xB44F6901B27AA9C2ULL, 0x58F80D9FE17BE876ULL, 0x5546F2F952C1A2FBULL, 
            0xA2F89414F7714A6DULL, 0x24552BE0DDD1D295ULL, 0xD7846182751A908FULL, 0xFDEB30F3D6FC14F7ULL, 
            0x838804745A18EC02ULL, 0x28FB6295BAA14EB0ULL, 0x3797884A1D10A81AULL, 0x028E1EB5AFD14EF0ULL, 
            0xC0597E96E8555333ULL, 0xE5F8E9A9CF9BC422ULL, 0x9D829F33C32B77E3ULL, 0x5ECE8E8C2B7C45AAULL, 
            0x68F859490C6F619AULL, 0xEBA385489BA811E6ULL, 0xCB3707DB7EA1A696ULL, 0xBE360A1F59082BB1ULL, 
            0x648804783B2F6D29ULL, 0xAA713042FD76C620ULL, 0xED61E901DC1BB3D0ULL, 0x1899FAEAC0549B72ULL, 
            0x7E228B1B47D71175ULL, 0xA5F9E950C11E7A73ULL, 0xDDC9037DD6FBD101ULL, 0xA4B5A2B9BF40DB53ULL
        },
        {
            0xDD07D429E6E20910ULL, 0x95FF02272E4B626AULL, 0x460A63280BAC982CULL, 0x3275ACBDAD639EEDULL, 
            0x9C81F3FB2D88BBFDULL, 0xDE23160C3D56FC95ULL, 0x42C4FE965314526BULL, 0xD2D9D348E177C33DULL, 
            0xC5C30A9E4402DFB6ULL, 0x093F1B0E28645E86ULL, 0x33EF0F6E7939E4C5ULL, 0x5459722B122D10C3ULL, 
            0x959359D2BAE87624ULL, 0xE55EBC27DD7ACFFAULL, 0x772EDBD29988DEB6ULL, 0x469352C815FA7841ULL, 
            0x22ABD22AED1356AFULL, 0x547E033A2D2D2616ULL, 0xACB058ACD4274C6BULL, 0xB54C33F495D53451ULL, 
            0xB8CF37A294DF46E6ULL, 0x1F14090A4911BD25ULL, 0xE24AF065458246B6ULL, 0x4FDD7368B2DD3927ULL, 
            0x2A4BFA3AAFDBA3EEULL, 0x0E9779F2834C6358ULL, 0x50C8DA9973DC2B03ULL, 0x58639965B062F8A7ULL, 
            0xF20925EA9F47F5DAULL, 0x4B496913E32A7F06ULL, 0x218CF313C7671105ULL, 0x376234310EE454E8ULL
        },
        {
            0xCD59A11A00857B15ULL, 0x586AA2202F61C109ULL, 0x8102A46E86A57F72ULL, 0x4D3637D84B80AA1AULL, 
            0x681F87B8524534BCULL, 0x0291705D6AAF65CEULL, 0x37123CC1D3610091ULL, 0x7541409D121B435EULL, 
            0x6C61E61DE21AA135ULL, 0xF1E4B3ADDD6CF248ULL, 0x98F15BD01A928061ULL, 0x57A684C2A1CCFD55ULL, 
            0x460064B3A3CC6A8EULL, 0x9854F814CCB82D00ULL, 0x369E24918D3E18C2ULL, 0x5717E49FECAF7602ULL, 
            0x685C5574B435BBF5ULL, 0xBAEDEBA800819B63ULL, 0x30F26EAA31C8CA09ULL, 0x8B8922DC0D335DA2ULL, 
            0x04E607396D187A78ULL, 0x79B23A8CEAF74644ULL, 0x8C6D3026715D15A9ULL, 0x46CA8593963C3189ULL, 
            0x3EF4AB204767FF46ULL, 0x9877BB389B475307ULL, 0x969EDA1252AF187EULL, 0x10239B4FE5114C16ULL, 
            0xB8F3D493487FEA4DULL, 0x93F4F07AC82FFD93ULL, 0xF2BC2C7182B99F15ULL, 0x62514924A8E11FE2ULL
        },
        {
            0xE91C97E0156B0E31ULL, 0x727518CA00118B40ULL, 0x5747135D8D8815DCULL, 0xFE4BA0E2FC0D36EAULL, 
            0x3574110DB17CE967ULL, 0xC6C84057869A00B9ULL, 0xD82B62F82ACE005DULL, 0xA71BDD82364582FAULL, 
            0x96A51ADC937AB68AULL, 0xDBBF44BC96244C6BULL, 0xA06E738A9A0C0DF7ULL, 0x290223B27EB7DC89ULL, 
            0xD3854D3076437991ULL, 0xAECAEEF075439ED0ULL, 0xF08ACA2DEFFB72D8ULL, 0x3B085864D9E4EB43ULL, 
            0x98254D757A9BCD4AULL, 0x0174F2640474E1DEULL, 0xFD9E527F9BA89ED3ULL, 0x784F924177300DB0ULL, 
            0x895B1338C69B9D6BULL, 0xAD76F32281CF5B70ULL, 0x1127DE0D29BDD147ULL, 0x3361D1ED074DB2DCULL, 
            0x9EEFC8B08BF59951ULL, 0xC8ACE2F38B2C84FCULL, 0x0DDF2460198BF89DULL, 0x3D93F87B7B174B9DULL, 
            0x6586CC70A441DE95ULL, 0xFF011A4B96CF88D0ULL, 0x772498FC8615C297ULL, 0xEFC3569A443C9E48ULL
        }
    },
    {
        {
            0x2064464C3E5C6DD4ULL, 0xF60C83B396E62D9DULL, 0xDC3E8259508790B0ULL, 0x3E84C18A7454244CULL, 
            0x19C453302650EB3FULL, 0xB7BD7285B937F58FULL, 0x74E845A6F6B73EE5ULL, 0x385EB90B1CDB725DULL, 
            0xDE4C26F28881AC06ULL, 0x985CFB55AB6F3829ULL, 0x7B32D15A4B6C54DFULL, 0x7018FEDD2534622AULL, 
            0xA40C759E25EAF060ULL, 0x43DDD6BC5E1F2501ULL, 0x2BE26A9CCB69C906ULL, 0x219B911C4DFDE8FAULL, 
            0x8E4A39AB376A510DULL, 0xA5BFBE49FB3E21C4ULL, 0xF1D5A549F7BFC6E1ULL, 0xDFA87E3863873755ULL, 
            0x98E42A749684E833ULL, 0x13C67A0C25393960ULL, 0x80B64A302E6ADA3DULL, 0x5A0F902D36846AA9ULL, 
            0x4190B68F0201203FULL, 0x303CA4CF71864CCDULL, 0x271BB563C49C2FDAULL, 0x35347FA7B12BF910ULL, 
            0x0F9160684403F293ULL, 0x8421BCA7A924F6C6ULL, 0x7ABBF816D98EEFC5ULL, 0x892738B30994732AULL
        },
        {
            0x896E0881F2B874FFULL, 0xE276CF13F33283CEULL, 0xCB49CCD275498D78ULL, 0xB6AD05C2ABAF7FE2ULL, 
            0xF649DC2BA242891CULL, 0x9B4532FAB850B19DULL, 0x573AB7E3FD4C2066ULL, 0x6F72A4579FC97658ULL, 
            0x77E31C091C1542A4ULL, 0x3341B7E2CEC803ACULL, 0xFD6587A5D4359C21ULL, 0x50FC55F6FF807C31ULL, 
            0xAABEC2DF80C258B5ULL, 0x1740CD5167D9EE9EULL, 0x09BD5E92E0F3EB63ULL, 0xAE8066D1AE2DD047ULL, 
            0x7FDFF18A390EFC84ULL, 0x275665E9FEBFF66BULL, 0x110F2480C14D6BA0ULL, 0x5031ACDD66A4D003ULL, 
            0x551968597CA07EACULL, 0x5EE40B616ADDE5D5ULL, 0x882403CF41A132A4ULL, 0x66AACD50C9B09351ULL, 
            0x9E4F34B9B8E3F130ULL, 0x6F61690FAA2AFBF7ULL, 0x159E365A16610C8DULL, 0xA64E6AEB295B7C05ULL, 
            0x05296FA72A7785A3ULL, 0x308D46EA402E6390ULL, 0x5C76619DCF75E18FULL, 0xB67A6025A8A2ED26ULL
        },
        {
            0xE033A7E106481E9DULL, 0x075327D153D116E7ULL, 0x7A09B147F7961D8BULL, 0x03A759F358E6FB55ULL, 
            0x8DE77F11B3433734ULL, 0x667B56DC4A25C2AAULL, 0xA479B1D1DF5C4CF8ULL, 0x8A7CB4514020D154ULL, 
            0xFB546422BF5005C5ULL, 0xEAE6770A9AD48271ULL, 0x1ECBE8E552BB7D22ULL, 0xD4D09BDBB91DB81EULL, 
            0x5CC49CDE2E359414ULL, 0x1C2A9CA18975D4F6ULL, 0x9C38B28DEFAF28FDULL, 0x1CE5C58018D3910EULL, 
            0x99496C3E75FB4697ULL, 0xACFFF2C319C3DBFDULL, 0x64B783843C3ED321ULL, 0xAEDC80A636695DEBULL, 
            0x793571BB1238ADACULL, 0x0B88106487CF5679ULL, 0x856282D4A9E96439ULL, 0xD5C8447A20023645ULL, 
            0x209BBB0F927BF818ULL, 0x7E9CFF8AFF57C926ULL, 0x7D4070888747CBF0ULL, 0xBA5B28D9D26BCC24ULL, 
            0x2B1647CBEC6F58A6ULL, 0x52CB2D296356D3D3ULL, 0x53E4585F2D65EBE3ULL, 0xCC0B6B74FF3FEA41ULL
        },
        {
            0x5A4BD951910412B6ULL, 0xE4A99B7C654A5DE7ULL, 0x0C303071B4E69981ULL, 0xFD4BC1C325AAAC70ULL, 
            0x20F1A023422D74BEULL, 0xB0EF7572A4937923ULL, 0xB32BBBD83099A0ABULL, 0xEFD61A8735A67DC6ULL, 
            0x68BA62DE0273595EULL, 0x6C4A37417694C8BEULL, 0xD65BEC6069095AE3ULL, 0x2138376B67ACC299ULL, 
            0x09CBB03E16CE7636ULL, 0x88293EBB72EBFC72ULL, 0xB0CB271EB8987ADBULL, 0xDC2D6C6F09597D5BULL, 
            0x72EA7B61295F4CF6ULL, 0xF1C641041A04DA74ULL, 0x71BFE93AEB77681CULL, 0x4D574979851B8027ULL, 
            0x863CB2FB1D3CD026ULL, 0x531B522BEE21388CULL, 0x52B2BC9B4C21B5B9ULL, 0x64F9D935B40C92E7ULL, 
            0xC54AF287B4BAF049ULL, 0x28ABFA131BD71612ULL, 0xAF01FC719132B685ULL, 0x25D346BA2D6C019AULL, 
            0xC8BFB97DECF8E32CULL, 0xC71A3F6BE850BF3DULL, 0x91EF4AB046A83725ULL, 0xD367E7CFB6B62E8AULL
        },
        {
            0xA36692A46B70E08AULL, 0xAD18443CA54F7FD2ULL, 0x7F15A8599DD18157ULL, 0x5FDD514B760E3F9DULL, 
            0x0F49F71377085B64ULL, 0x4E9EE02ADEC2D42EULL, 0xBF88A4BC85D225D4ULL, 0x8899A420DC0CD523ULL, 
            0x64BD881847FAE4CFULL, 0x7C424AFE2C7482A1ULL, 0x558C48C14B8D8C9EULL, 0x32F6DD3504F463C2ULL, 
            0x7E9027E3B215517CULL, 0x4242A67B0891A217ULL, 0xD122FDF7DDADB61EULL, 0x0F0DE1BC2C4AAD8FULL, 
            0xE83EAD0FBDAAB3C4ULL, 0x8C119BD42FB2BC9CULL, 0x13EA0D1872853654ULL, 0x3348C85FAAF8233CULL, 
            0x2CE44C5973E2AA3FULL, 0x14EF24B8321F6F8FULL, 0xCB7D462EF10A3E24ULL, 0x5F6CFD381B0B7D29ULL, 
            0xFA59D9D902098254ULL, 0x075FE40C94AD3BF6ULL, 0x1102F561BD51C15FULL, 0x8A9220EA6369ECE6ULL, 
            0x8B6BCC41E9223F68ULL, 0x8E0AE99B7A79AD01ULL, 0xFB80141AEC5B20CBULL, 0xE720D43090540201ULL
        },
        {
            0x97EFC386A31B0DD3ULL, 0x6492EA1FB4BC91B9ULL, 0xEA81AD2FC010BA88ULL, 0xE3E2B7B349D2E24DULL, 
            0xC9960DEB481205DAULL, 0x991955EE59DA21CAULL, 0xA4FF96F93F69FAD1ULL, 0x9475D7711B2B91C5ULL, 
            0x6707008D63311A5DULL, 0xB6898F5D6D61F0AAULL, 0xDE686B51332D20F9ULL, 0x1DA37FBD924D0D1BULL, 
            0x5317571C309E90B4ULL, 0x37A4AEC23C6C0E31ULL, 0x3B41A6C5299DF1F9ULL, 0xCEB8F5C814C8A7A6ULL, 
            0x117ADA68257F6FA7ULL, 0x671541972CCD60A7ULL, 0xCDC801D23E44BF7EULL, 0xE81939DD85D8989CULL, 
            0x495BD66BC203E5A4ULL, 0xD30B2D0690877A6FULL, 0xDDDAC5CCD826EFC4ULL, 0x8F78F04F06E3BB8CULL, 
            0x01E85010DD5A7E46ULL, 0x302768A636C86CAEULL, 0x5320F9581D96F39EULL, 0xF4836E847F18FAC7ULL, 
            0x1F2260071EFA8708ULL, 0xC06E9E5AE6B7EA30ULL, 0x4CF2496C6BCBC8B9ULL, 0x8FC7264FE9991C32ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseBConstants = {
    0x75BB7532F79932C3ULL,
    0x0262F71412CE78C2ULL,
    0xE4C366920E38761CULL,
    0x75BB7532F79932C3ULL,
    0x0262F71412CE78C2ULL,
    0xE4C366920E38761CULL,
    0x90C531287395FFFBULL,
    0x5BFAC5124F31D723ULL,
    0x52,
    0x79,
    0xB4,
    0xAC,
    0xA3,
    0xA4,
    0xBB,
    0x96
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseCSalts = {
    {
        {
            0x797F63F8E6A9C109ULL, 0x4D48173627B76AD0ULL, 0x159364F2570B8616ULL, 0xF0277B4F57610078ULL, 
            0xA5072A327CD3CEA8ULL, 0x83F3352C31A9CA1FULL, 0xD93F9E31ACA8E8CEULL, 0xCCC1C641D23065A2ULL, 
            0x28FE4086A9B79C01ULL, 0x84D142F9697CDAF9ULL, 0xFEDB4B378DCDDD93ULL, 0x96C74296E7D9B627ULL, 
            0x5C8DFE29BFFB2162ULL, 0xFC61FDC792DE7CAFULL, 0xBD5A9FE2A356DBA2ULL, 0x1163E5BE505E1EB1ULL, 
            0xD2603057C779EF8CULL, 0x3BB9065495C6D5F6ULL, 0x0370650B8B40D728ULL, 0x563767CC59F8CF54ULL, 
            0xB56FB11A49375AE3ULL, 0xBEBFCF0A71CA937FULL, 0x25983506A0344A2FULL, 0xAB294C386EC0405CULL, 
            0x1D11BD424F518254ULL, 0xACC5A5D0D6B949DEULL, 0x3CF26F9BD34686A2ULL, 0xFF0585155F0FDFC8ULL, 
            0x62CE5C56C169E5AEULL, 0xE869EAA88B574DF7ULL, 0x242A27EAE234CB60ULL, 0xEC7D6584B78856D9ULL
        },
        {
            0x9546C3BACC306316ULL, 0x2E18FA33E905694BULL, 0xC59CC892568D4AE0ULL, 0x96A2F589A0AF15EEULL, 
            0xF186E24ABE1EEC6DULL, 0x2F71696A8EEB752AULL, 0xA688B716D71DBABCULL, 0x68B240459050CE33ULL, 
            0x5CC42E3ABC0EB9D0ULL, 0x7C8E846C03FED863ULL, 0xB1B42095FE40260FULL, 0xA0A9FBBBB157775AULL, 
            0x061BC16DBB619F45ULL, 0x1940FC7458DEB581ULL, 0xD5DB556469C41040ULL, 0xAB14D2C8C0874E52ULL, 
            0x5CA01C08D8660681ULL, 0x444AF811A116B3D8ULL, 0x50F0DE06BAE4DE30ULL, 0x085A36700149D437ULL, 
            0x90E02B3A768DCA32ULL, 0x96CD059B263AC1EFULL, 0x26665EEBBE2653F6ULL, 0x4823B1CD91A46B72ULL, 
            0x52DF9E5F97473DD8ULL, 0xFF85992D9A1F0343ULL, 0xFFE462B442692670ULL, 0x039CBBB7F58A8AAEULL, 
            0xD6A9C3B739C59430ULL, 0x0BDDB8CB1D234F89ULL, 0xA5D4FA32F778F2EAULL, 0x712464C9B420C766ULL
        },
        {
            0x2484CC76045A24AFULL, 0x1102E6C41182E68FULL, 0x5A308752D38001C1ULL, 0x387F2F4EEAF8D204ULL, 
            0x174784ED15D3FFA8ULL, 0xFFC9FFD2BB1F7F1DULL, 0x0CE8BB731ABA970CULL, 0x2794B220DF9D56F2ULL, 
            0x576E22F6F93F67B6ULL, 0x214077D9394D9BC8ULL, 0x08BD363347FB52C8ULL, 0x999DD92AA578A910ULL, 
            0x09CBE50050F0911EULL, 0xEEF2608103A05031ULL, 0xF3EE882126363FF8ULL, 0x5A99A36DA6E4CF55ULL, 
            0x432C37A49415AF21ULL, 0xD335706FD6E8445CULL, 0xB6C84AA991AA3EF7ULL, 0x338C0187497B753EULL, 
            0x229289D08458DB03ULL, 0xB5053C98741B9997ULL, 0x8E83E2ECBCC4E316ULL, 0xE0CBB437C9B09ED9ULL, 
            0xF8044467E85A9F7BULL, 0x9852047F69E86D8CULL, 0x1D3A08C2C456343DULL, 0x0E57C63B7DA518AFULL, 
            0x682C495C20C75952ULL, 0x3701E9C36D41893AULL, 0x8180D14C58EE5F60ULL, 0x28921FB990E69794ULL
        },
        {
            0xF5413B99DE081D2DULL, 0xEAE972C85DB59CA3ULL, 0xA3A2ED1047982943ULL, 0x4E40D359F55FE30FULL, 
            0x7E761A6E0C618AB4ULL, 0xB626EA4D32CD0C08ULL, 0x0C5E10B4D8FEE578ULL, 0x62B7373CC4CABA52ULL, 
            0x42257E4BF1F32981ULL, 0x3F4EB0B36DB74B5AULL, 0x433A16DD59E73770ULL, 0x91D4F81C1ADDF2FFULL, 
            0x6A756425BA3D418FULL, 0x3187ED5E5349B267ULL, 0x72F4528FFA74C712ULL, 0xF9546DEF79E607CDULL, 
            0x8F5368B7916115E9ULL, 0x7572C9926C6F7719ULL, 0x84764B2F5DBB5059ULL, 0x5B725889B4176F3DULL, 
            0x1DED3BAF77A0F1C1ULL, 0xE4CCE5C2307267BBULL, 0xE7E93BAA6E9BCB9DULL, 0xE325EBDEE8C73080ULL, 
            0x70706B5BBCE3D666ULL, 0xEB1640DEFBDD48C6ULL, 0x9952914D9D5A40E0ULL, 0xDE804864AEA06DFCULL, 
            0x56D2E8425C5A9848ULL, 0xBC9A02FCB6B07302ULL, 0x9FD1A75CB51BEBB7ULL, 0x7241A90C13FDE88FULL
        },
        {
            0x9A0E4E1021E22C93ULL, 0x3F48CE6FF7CA0687ULL, 0x11BD3387C80AABE0ULL, 0x0B91774F9F366CDEULL, 
            0x951576BAA075163EULL, 0x68C72FB9F52A3857ULL, 0x1676436A83B9D007ULL, 0x3ADC46503C49F963ULL, 
            0x9D9991D4F8AF6E4EULL, 0xA417854FB6F2BE10ULL, 0x74EF366B16E3C50FULL, 0xF7A388CDA7276A3FULL, 
            0xD0923F9ECF87411DULL, 0x5C94A9A2582DB05AULL, 0xF947AC741C9606E5ULL, 0xBB446252C5D1C716ULL, 
            0xD531378B4216727FULL, 0xF4B971EA6FEB9A52ULL, 0xF36E105228E346A3ULL, 0x13838C25DA76FF0CULL, 
            0xDBD0DCF5F5003EA0ULL, 0x9604CF9FE8BA2B19ULL, 0x471F7A9EA187D898ULL, 0x9B7BC56F605CE70EULL, 
            0x45479AC6C4B4B607ULL, 0xFD09FF3016D45B0AULL, 0x8A09D6615BCA2151ULL, 0x165B152370004ABDULL, 
            0x52D61BADA3F1AD4BULL, 0x94ABF6B993796C62ULL, 0xD56580A06D0FB230ULL, 0x7784D1D7CE813432ULL
        },
        {
            0x6034C7E9A491842DULL, 0xB25784A0CE91E819ULL, 0xA49CBA1B07C75D01ULL, 0x9DBBFD8AFCF5DD33ULL, 
            0xF763DCA6ADDB0049ULL, 0x6C8115561524B6D3ULL, 0xA53160089848EF13ULL, 0x61A8E65BEF23A9AAULL, 
            0x2001F24F39A08614ULL, 0xBD56BB8B5898512EULL, 0xB8804AC708A3686EULL, 0x6E95E236D4658B09ULL, 
            0xC0B739DEA5385EDDULL, 0x6EEB17F07D833948ULL, 0x06012E87FB55EFBEULL, 0xCA30079311BA8D21ULL, 
            0x839D5DAD6991AEFBULL, 0x07B4333DC14145CAULL, 0xCE7FC359906BE603ULL, 0xDCC11B3C89B26AB2ULL, 
            0xD8835FA9EC238506ULL, 0x81944F52785D619FULL, 0xCC96CB3C1FD611E0ULL, 0xD19F59B05BB3935AULL, 
            0x683512658B196C65ULL, 0x5B33CB36FC5AD434ULL, 0xF293281DD5E39362ULL, 0xE9823AB59E83220AULL, 
            0x5ED8331EDE2C91C5ULL, 0xAE1E8A94B54F868CULL, 0xED59B87E016670AAULL, 0xEA65C4588E49DC52ULL
        }
    },
    {
        {
            0xEEE38805200A75DDULL, 0xD9014087591D1D4DULL, 0x0C1807F50144FDD8ULL, 0x888944C6DCF56EA0ULL, 
            0x79A0E569EE6E7EC7ULL, 0x7D983A75643752A9ULL, 0xB6C629FE6A195132ULL, 0x0ED494F787793EB6ULL, 
            0x626B9F5E9076EC52ULL, 0x2D7A588A0D549D68ULL, 0xA962F2FF2659AE20ULL, 0x182101172FE8E188ULL, 
            0x065D234162AC825FULL, 0x9E88DD6095DC962FULL, 0xA183F8D2C28D6E4BULL, 0xDFE9DA840B937DC8ULL, 
            0x80827F5B226599A3ULL, 0x2AB01E14BEF8B011ULL, 0x67F6BB4046E37CA2ULL, 0x1EA6EA3F35A22F66ULL, 
            0x20824473A2DFEE1DULL, 0x59400FE07BB917F0ULL, 0x1E89D0FBCE420B10ULL, 0x17832C04FCEA9231ULL, 
            0x8D38E2168EA81B0AULL, 0x46872A9811BF3725ULL, 0xF8F30358CFE0A51AULL, 0xE8EFB4B60D64410BULL, 
            0xB388FD8EA1F33D97ULL, 0xA858C88D25D31A8EULL, 0x8D990CE6210C23B7ULL, 0xEE357C3FE194DAFFULL
        },
        {
            0x9E525DE24A53E0A2ULL, 0x70C15FEA09503430ULL, 0xD69D0AA5A22E80C1ULL, 0x3D1434FDA85BA094ULL, 
            0x8F28E9C14947D0B9ULL, 0xFBD2DAA7CB8D749BULL, 0xA6E1E087C0AF325EULL, 0x54F6EC17308E4023ULL, 
            0xFFBA9F24AC5A0705ULL, 0xC33E91345505F32CULL, 0xCA0AEF0020198D77ULL, 0xACD4D9E0A44D5883ULL, 
            0x7C682EAC45DF5BE1ULL, 0x8E8F14E69843DA2CULL, 0xC888E785F8EC5879ULL, 0xC4E3FC5A957792A5ULL, 
            0x57ABEBC18813AC40ULL, 0x1BAF8CF950266F55ULL, 0x3F0D567FA6DF89A3ULL, 0x886DE692F5DDDE98ULL, 
            0xF2D750BB9D88F341ULL, 0xD9E979356671600AULL, 0xD34C9C135922D209ULL, 0x92EE818F9704A818ULL, 
            0xD4067601BEBC6930ULL, 0x3842AAAE736D365EULL, 0x64A43135808637B0ULL, 0x86EE933D5DC84378ULL, 
            0x101F110738412814ULL, 0xAD36910949ACA0DDULL, 0x9E96BA8D5AD93B32ULL, 0x09753FA3C212FB7EULL
        },
        {
            0x6558B59B35D05D4FULL, 0x0CA12644EB4D63D4ULL, 0x4B0D98017DCC6261ULL, 0x677A6D062C6647A7ULL, 
            0x54A6D3028B2B11FFULL, 0xD518FC28BA34F0B9ULL, 0xBFA4EC718322211FULL, 0x3D4C35EB32761AB9ULL, 
            0x732BC4690E394AC0ULL, 0xAD3990F35BCCD66DULL, 0x80EE21F153ADAE1AULL, 0x746914BC950D749DULL, 
            0xF547F0D8DB03136CULL, 0xCDA9FAF44D4ECD49ULL, 0xC96747867756D9B3ULL, 0x18017854A91A6D68ULL, 
            0x4DC3F2ED85953E96ULL, 0x81616C80748AD0E5ULL, 0xB2779777B8D0536BULL, 0x237D14B2D7389564ULL, 
            0xF6B389D8F13DFB74ULL, 0x791BEDE28602823BULL, 0x1E925474DD6BFBA5ULL, 0x317141451FA1FD95ULL, 
            0x04E031BA2A6501CBULL, 0x45C36A5328BDD074ULL, 0x0477842C0B656AACULL, 0xF91CE3FDCCD76A05ULL, 
            0x77F883EEACCDD0EEULL, 0x98FE18A84D020738ULL, 0x2806AA7CBE510F10ULL, 0x5B0AB76C6BA4B374ULL
        },
        {
            0x5AD71FF141039B51ULL, 0x4E9249459C2E25A5ULL, 0xCA699D9EE5ADF544ULL, 0x6CE3A1932D5D2588ULL, 
            0xA0ECE9A98EC0CCCBULL, 0xF7D549E1001E787AULL, 0xB0C0F7F7417153E7ULL, 0x218DEF1AB173B1FFULL, 
            0xD9317A131107435CULL, 0x9F12B46423726472ULL, 0x2AA3793ED28D1FC9ULL, 0x7060E9C604AE0F0AULL, 
            0x3A9E9928DFFB545EULL, 0x4F93C10ED68694EFULL, 0x2D40F6E644B57F7BULL, 0x54895E73549A2BA1ULL, 
            0xD7A411EA7B6D6653ULL, 0x15E379C89E7ADFECULL, 0x9D0C9654F20A4A5CULL, 0x9473338AF4AF98B9ULL, 
            0x85EC47E484EDF8FEULL, 0x43A7C9908509437DULL, 0x8C9B1A3E4B15E7F2ULL, 0x352DA2731E26F753ULL, 
            0x717778A8D80FD6F9ULL, 0x2CDEA4105DCBB086ULL, 0x411E576FC2698E69ULL, 0x96DA66EF8E7EBFB5ULL, 
            0xEB19EFDA2BDB9826ULL, 0x32B47072A8C6B3ACULL, 0x8F285B14DAAD204CULL, 0x3541447585DAD931ULL
        },
        {
            0x1B577FD0251CBDAFULL, 0x0BC7DFDD25664239ULL, 0xBA754471139C8A3BULL, 0x59B82CE690E3C8DFULL, 
            0x0D7B1DB78B6DEBD9ULL, 0x2D32DAD8EAFEB1DFULL, 0xD721A4B564193C39ULL, 0x2237C77CE217B711ULL, 
            0xF34D763246A9BBBDULL, 0x83EF46462917B460ULL, 0xB151C3BC23EEA290ULL, 0x5AB9E9B9F72C8E2AULL, 
            0x200606A0FDB2FF60ULL, 0x54F805D23940EE4BULL, 0xB2D85DF0C869BF71ULL, 0x1D7E16C982CA5288ULL, 
            0xE4A0ACD9FC61C998ULL, 0xD964EA82F4663EE7ULL, 0x0A1B0CE9650202E6ULL, 0x23FD2B0518827977ULL, 
            0x85CE27C79C28915FULL, 0x2B7D58A9489066ECULL, 0xE8B324EB30BCD5EFULL, 0xDB2DA7C5C1D9A8D1ULL, 
            0x52B12AC53C355F58ULL, 0x7C23DEAE105353FBULL, 0xEB888E57C08B3A54ULL, 0x9666C592FE45FD49ULL, 
            0x9CD32714E51EA9E6ULL, 0x8DDFCB5A1862009FULL, 0xE6277013D6F9016FULL, 0x205DF40A0CA99104ULL
        },
        {
            0x9DC2F654070143BAULL, 0xD7269E3EBEA35033ULL, 0x5BABD86B5038E0FAULL, 0x023AE89E9394F7EFULL, 
            0x09DE7CCD30E13548ULL, 0x1EC5B88D33AACE85ULL, 0x6E1C589F581F0BE0ULL, 0xA84F4C3D891D5D30ULL, 
            0x90845D87CFED416BULL, 0x428E6E1CD591A89DULL, 0xB69AED230140B9ACULL, 0x0DAB7949AD2629AEULL, 
            0x8B76F8E0D0EE8866ULL, 0x5B12E4682269332FULL, 0xD3BB99F6550B91F2ULL, 0x8B291BE979F29074ULL, 
            0xE54BD01840D0F745ULL, 0xF5FE5203D4F1415FULL, 0xB7099CA8B972A047ULL, 0x10027AC2493A080AULL, 
            0x55EA9A54356992EEULL, 0xBB62843B09BAB69DULL, 0x01A53862211288D6ULL, 0xFCEA74476F0F4001ULL, 
            0xEDBD9E2E2BD1BC96ULL, 0xF9F116EAA3D342CCULL, 0x310D5E85234E5517ULL, 0xCE771D14DA9FD69EULL, 
            0xA13F29DFD44B2D77ULL, 0xFA4B451493C37811ULL, 0x70B0B002DE03A22CULL, 0xD38FE9A8B6126F18ULL
        }
    },
    {
        {
            0x7EFCADE45BBDEB8DULL, 0xCE2AE1598C54CFF8ULL, 0xB9F71790826D83B3ULL, 0x153B7309E8950122ULL, 
            0xF3440FCE1AEAC8AAULL, 0x3B2E64BDC0EAA5B1ULL, 0x8CEC60C40C1564D2ULL, 0x6FF914BEF37D5B01ULL, 
            0x5226BD4029C5FB1CULL, 0x53FC9A2599312987ULL, 0x09077C86915B072AULL, 0x1EDCF0986A7C1952ULL, 
            0x8B2DB3C92BF62AB6ULL, 0x3E4943A468DBFB78ULL, 0x3E0AE7515F4FEAB2ULL, 0x797BDB71E98B65B8ULL, 
            0xA623FF107E606B4DULL, 0x5A0629BB80DF8A7FULL, 0x22C33C2F2BF2B1D0ULL, 0x95F34ECA78770870ULL, 
            0xE1BD3F0345EB62D0ULL, 0xC2778232D597EF0FULL, 0xAA3ECFCBBE32C545ULL, 0xDC837B9548163283ULL, 
            0xCE813480ED5300A1ULL, 0x87AE656D8BCFC0A7ULL, 0x3A6280E8BEC8C87CULL, 0x02FC02933D01A100ULL, 
            0xAE11A35F1C9F4413ULL, 0xF1CF564113D56F9DULL, 0x22DDC69238D9582DULL, 0xE76C0AF8F9778A3AULL
        },
        {
            0xEB1A413EE7083526ULL, 0x6D43350F4B222DD3ULL, 0x665E7E310182C969ULL, 0x10636F25CDA56E93ULL, 
            0x17AF42D66B9D1B9FULL, 0x5DDF1E7F18C1590EULL, 0x19E75432C5A62FCAULL, 0xA46B21B5350A0B73ULL, 
            0x2CAE030F9B21346DULL, 0xBF9DE7B3FBA43078ULL, 0x4C395DA97DAFFDF2ULL, 0x81CAABE23533A07EULL, 
            0xC0156CCB445F84D1ULL, 0x2B07A20D984AC4F3ULL, 0x19DD5B44D6B460F6ULL, 0x8A7DC11E7D06FC34ULL, 
            0x2EC5F872AF74A925ULL, 0x12B0C16BA513A034ULL, 0x1566DC12C64E6052ULL, 0x236C4369ED15E7CDULL, 
            0x0C52520F43722803ULL, 0x980D6D6519D8796BULL, 0xD96C181AFF42E3D2ULL, 0x0A9B7ECBC7EACFF7ULL, 
            0xD791481005B0A462ULL, 0x2AE74313EA050439ULL, 0x46E5DEBCF19D5DE7ULL, 0x0529EFF5A99AD800ULL, 
            0x244BB4BE26AA1C99ULL, 0xCC21B5B698A8BCDFULL, 0x1B2C3ABC0A1101A7ULL, 0x821413741548EEF2ULL
        },
        {
            0x45C306089D97F920ULL, 0x5959DD0DD47F51E1ULL, 0xA156436C9E02FDE1ULL, 0xACB307BF5AB74421ULL, 
            0xC2A6CA2DAE46541CULL, 0xE23301D3FCD1F258ULL, 0x915841B23A9390EEULL, 0xDB5F0B0E569CAB5BULL, 
            0x03D88B5BAAFD1656ULL, 0x33DF8108CCD22166ULL, 0xF1E2AC5307DE67D5ULL, 0x56A7B0E871B66ABAULL, 
            0xDF67B91819BA0013ULL, 0x378FB96B4C2E8BAEULL, 0x43686F11988F2D4DULL, 0x25D55EF75D38D9EEULL, 
            0x340D8917970B036FULL, 0xF6F2579780ED25E6ULL, 0x882FDF93520FB113ULL, 0x02A09ADE8EB44D16ULL, 
            0x4571D4E6B48D620AULL, 0xA96CC7C33CDA3214ULL, 0xC58422C04559BF78ULL, 0x922943395D46258BULL, 
            0xD9C86E9FC0315134ULL, 0xEC0C50BC9ACCFEA8ULL, 0x2A1D89BED768A560ULL, 0x1C79CA71D0FEA180ULL, 
            0x826AFA226F18F36FULL, 0x474B595D5F7F69E2ULL, 0x505EAF03A01BF0A3ULL, 0xFC82E5CF9E981703ULL
        },
        {
            0x93CD1D08A2DF589AULL, 0xCCBE5EEE4D7763B3ULL, 0x88C06191E5CC3E49ULL, 0x0A6E4D93F96A2C74ULL, 
            0x52CA26EFF5F0A2FAULL, 0x78490C03CF7ABAC4ULL, 0xB108113F0CDCBA41ULL, 0xBCD91CD73534D1A5ULL, 
            0x41CD4DBBD8D82713ULL, 0xF951C63D906BA6E2ULL, 0xB137D7DC2859E708ULL, 0x3B7A29537C4581CAULL, 
            0x0335DD72C1CEAC5DULL, 0x4A33B98F6249B7B6ULL, 0xC97C066AF086D9E0ULL, 0x8832CDBCD5DF888FULL, 
            0xFA4626940F820C84ULL, 0x545241A564BB477AULL, 0xDB15621965B17EE4ULL, 0x6FD68E2F367605C4ULL, 
            0x2D841819335D6DC4ULL, 0x64DBD52650BA8AA6ULL, 0x13E88AFE1B38AA85ULL, 0xDED59EDDBCD33F00ULL, 
            0x766586AC3F51E89EULL, 0x8566C82E5BEB525CULL, 0xD38E4F0258E1F2BBULL, 0xAFECC37466BE6817ULL, 
            0x3EFA2CE2B44C3FDBULL, 0xC85A72A114D61A5AULL, 0x36BBB0DB12571A73ULL, 0xD50F1436F74E7DD2ULL
        },
        {
            0x95B41E93CDC3FCB0ULL, 0x6F2BA0D8E86ABEEDULL, 0x381A9B70E4093C0FULL, 0x54027F9F90AB5E05ULL, 
            0x6469E7AD44B0B574ULL, 0xE3367807042487C6ULL, 0xF5D765E5FC0635D8ULL, 0x475753CD1BCB6CD5ULL, 
            0xD7E2CC93226A9861ULL, 0xF024D75FE9A146C2ULL, 0x6AE0EDA502CE06D3ULL, 0xFE59C17093E9B8CFULL, 
            0x1D0699022BFA26D0ULL, 0xECFD2D733B868C9DULL, 0x60710E605D763ADAULL, 0x024CC731C5E8F231ULL, 
            0x5BA2DAF062A1B60EULL, 0x2C37C80301AB817DULL, 0xBCD83949DD23D155ULL, 0xB1EA623A0C832644ULL, 
            0xF697C46468BBC52CULL, 0x9B2249BED35CA438ULL, 0x3BC6CEC713729F95ULL, 0x4D17B43CEAF60706ULL, 
            0xC7490208D1A2E9ACULL, 0xE2894696CB82A6CCULL, 0x102F714FF135ABB5ULL, 0x5E007A24F9136B0AULL, 
            0xAD17559B9A9C2A13ULL, 0x49DA51220CCDA879ULL, 0x32E63034099071E8ULL, 0xCF4DB51974BABB8BULL
        },
        {
            0x858538343DB31BA9ULL, 0x2FDC12A6F2B9A78EULL, 0xF2386BCE2868000CULL, 0x77AF90E941C11059ULL, 
            0xBD5534B23F904661ULL, 0x0DB97CE61242441FULL, 0xF0FFFAFD814FF9F3ULL, 0x64A61005CCDA06CDULL, 
            0x981FF039B334603CULL, 0x472348E197BEA7CCULL, 0xAD6F22DFC9491FE6ULL, 0x787CFCCE442AF039ULL, 
            0xDE025262DECF880FULL, 0xCCF41001255B8B88ULL, 0xDBD5934E4294BEEAULL, 0xC51C43736F74DDA8ULL, 
            0x36DF969908D609DBULL, 0xC689F4C6C257CBA9ULL, 0x99F24EEA3F293B8FULL, 0x39BAC519D21B7348ULL, 
            0x93E3E12BBA64CAD5ULL, 0xE4C0045951647DDDULL, 0x4B1DC1A54AEB315CULL, 0x45FBA559319B55F5ULL, 
            0xA5C6BBFF29E09491ULL, 0xEC72B55395038CE7ULL, 0x7E7506813A5BC920ULL, 0x8AFE1C798F615424ULL, 
            0xF0A7C7D9FC302921ULL, 0x75C2635E73DE0BA4ULL, 0x4A8EEE05163F7F5BULL, 0xD36BF6F29685E67BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseCConstants = {
    0xBBAF3858E6C843A0ULL,
    0x1087706EB6B6F8F7ULL,
    0x6631A3245B8EDEB3ULL,
    0xBBAF3858E6C843A0ULL,
    0x1087706EB6B6F8F7ULL,
    0x6631A3245B8EDEB3ULL,
    0xD0A1CF186A0570AAULL,
    0xC7AED29DE9CFCBCCULL,
    0x56,
    0xB2,
    0xF3,
    0x37,
    0xFA,
    0xBE,
    0xA1,
    0x91
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseDSalts = {
    {
        {
            0x83111B5B6E3209D0ULL, 0xED271D2739FB5A7EULL, 0xBCF9E66282420124ULL, 0x02FFA65BCC8C5098ULL, 
            0x9B4014196C19C53CULL, 0xAD60C66435E2CBA0ULL, 0x047D6D1E0DE703C5ULL, 0x4B5551EEB8BB8F8EULL, 
            0x9BB63F7108C0A53EULL, 0x5527BC7411B6A1C4ULL, 0x392F0597B081C587ULL, 0x3CB06B652D59F139ULL, 
            0x5BEB2FA11B4C6F1FULL, 0x957460FACDE6415CULL, 0x39EAAA7A5929CE01ULL, 0x0BE2BE91047B5A8AULL, 
            0xAB7C982DFEC5F698ULL, 0x9B2793AE7BE90B0BULL, 0x9FFA2E17DC464382ULL, 0xDC0B572529667164ULL, 
            0x083313452CFC977EULL, 0xDBA75F796D75E658ULL, 0x81921E0904BC4174ULL, 0xF27A06A091B17B81ULL, 
            0xB116EBE452842CE1ULL, 0x55B23732271B70E7ULL, 0x1094072C12CCF8E9ULL, 0xC4D869EA0BAD95D3ULL, 
            0x9D79BBD15B7E8D15ULL, 0x1E53A42BB516DF83ULL, 0x21FA3021D78F3C42ULL, 0xC33BBEB66CE23A0CULL
        },
        {
            0xEADCEBF767F8E575ULL, 0xEDCFA7F422A9E58AULL, 0x6819B6A42C6D6F78ULL, 0x2624539919496CA1ULL, 
            0x52F1B52A4168FB50ULL, 0x44179E846BD2DC6AULL, 0x2C78BA240A8C9C35ULL, 0xF7970164BE62C054ULL, 
            0xFDE4998392088D33ULL, 0xA6DAC4A22BA883BCULL, 0xEE453AA2F1A0A362ULL, 0x9450B36CE354C768ULL, 
            0xE5B4F3CE31607A8AULL, 0x79556B7FCF076BC4ULL, 0x4C62A1535064B930ULL, 0x14A7B4FB9924598EULL, 
            0xAA10582721E37B1AULL, 0x7DE49D3C2ADC1A75ULL, 0xBFF6025EBEB71B3EULL, 0xFA3F05D4CE7C5AF8ULL, 
            0xE70C3937D91C1391ULL, 0xC104B615F3B6B914ULL, 0xA6B3498A43530E66ULL, 0x426A0883FE33C6F3ULL, 
            0xEA72CB6EE397AD67ULL, 0x46101F9E1B6FA6ACULL, 0xA046B0CB8F7785DBULL, 0x17B3B873DD57846BULL, 
            0x272D3A23D3960A5CULL, 0x0213EDC60F27507BULL, 0x3DE077DF17299AEEULL, 0x51C1E11F5F803DA5ULL
        },
        {
            0xA3E6A5CAF4B72EBFULL, 0x14573A46E45D83D5ULL, 0xD1AAB72C9DD1D3CAULL, 0x596B48D4E1235F65ULL, 
            0x9360D1A1F1C8A679ULL, 0x4AF85C8BD269C6E8ULL, 0x70E9FDB97DB79529ULL, 0x4AF3CC6540AAAD55ULL, 
            0xF3A4B0A4B581CBF1ULL, 0xAFF32D8812A19AFEULL, 0x646BC16436B0B30EULL, 0x07C1022DAA6E46F5ULL, 
            0xE01828B837A0D092ULL, 0x43D6D14B695B7088ULL, 0x4FFA8E3ECD93A63BULL, 0x875D72123E710E6EULL, 
            0x83DEC92CD276ED5AULL, 0xC2A3C8147E930C20ULL, 0x2399B161FC3F912CULL, 0xBE657C51BF019D9EULL, 
            0xE54D85A1CDC072C5ULL, 0xABD771D63D2E6D23ULL, 0xE05C2965ECDEEF6BULL, 0x31F3E4E73B54B66AULL, 
            0x6E77D0F94D2EC8BEULL, 0x89D6EF5B0EF5E2D4ULL, 0x1A1B8BCF3D23036DULL, 0x3FF3470E6B1513AAULL, 
            0x016B26CE228897D2ULL, 0xEF734D77B77781D9ULL, 0x0CFE48A66D7184EEULL, 0x43C75599C75FBE19ULL
        },
        {
            0xB65B6729D13F9E06ULL, 0x05AFD49635F8F64CULL, 0x9FB500ABF01BE6D5ULL, 0x00A26258F4E20AFAULL, 
            0x930A4FF3FCE1137BULL, 0xBF0980AD0028663BULL, 0x33E887B42CBC700DULL, 0x7E334978EF35A3F3ULL, 
            0x7B926E6E83ED0D79ULL, 0xA0C673D8F01832C8ULL, 0xF7CFF8AF49A2F6C0ULL, 0x722CF7227C6D402AULL, 
            0x9FD3A6D173D266D8ULL, 0x7643BAADBC2164E1ULL, 0x150B264B07EEFEB7ULL, 0xD04D9B1522D01740ULL, 
            0x79F62F36F586DA2DULL, 0x5FB3658ADCBC63BCULL, 0xFED997A7F8021822ULL, 0xFB37FC884AF4506AULL, 
            0xA0915660CBB0EA37ULL, 0x4FDC6EC029027A9CULL, 0x6367B35703FBEB9EULL, 0xFF86380AFD3D4279ULL, 
            0x004EE88F80E80994ULL, 0x9D00A1DB6AA823B2ULL, 0x79C0DD1515ADA81BULL, 0x82B202F3B894980DULL, 
            0xE5AD58407AACF0C4ULL, 0x0D0710E78860F254ULL, 0xC341432D9F5DF95DULL, 0x1DFC4E216463FA65ULL
        },
        {
            0x12392B434D30D3ABULL, 0x177140D2FC36A043ULL, 0x7C303481D7A407ABULL, 0xB464524A7A466BD8ULL, 
            0x67139E1DBB6F38BBULL, 0x7786BC837CBAA78BULL, 0xB541E8A285E079F5ULL, 0x8011A7FFEE7119CCULL, 
            0xA3B350EBABD22E11ULL, 0x99EC188B34A9A459ULL, 0xFBF953ACCAA3E815ULL, 0x7FAEB077364223ADULL, 
            0x04A5BCE56D0F0AC4ULL, 0x6708170850AA3456ULL, 0xE0A8965147D642A8ULL, 0x4F3BEC040463C22EULL, 
            0xC0109D0267601D5CULL, 0x22CCF26B0A25B964ULL, 0xC27CFEAD8FEFA814ULL, 0x6F21E237FEF7E5F7ULL, 
            0xD760ECDF4692154CULL, 0xF0156F6C2651C6EDULL, 0x5E2910D0FC580ABCULL, 0xCC7522B3257BFD5BULL, 
            0x303B52DE33036E55ULL, 0xCAB279D9E8233700ULL, 0x4C29C5D8B06234CAULL, 0xACC64654FA0AB5FEULL, 
            0x8EDA32714756F4A5ULL, 0x3D1A9528B56CEB92ULL, 0xDE966AAF6599DAA9ULL, 0xCEAA42F6CE351A5EULL
        },
        {
            0xA2BEEEC7C0B82836ULL, 0x4F057DE2AD35C4F0ULL, 0x5A3E9E681A077FC2ULL, 0xB5D607D61EA386A2ULL, 
            0x5286A101ABF6705DULL, 0xB507E7EC3CBC98A5ULL, 0x308E9DED25385B2DULL, 0x886A50991C083CD7ULL, 
            0x9FAAA77A0DC3E3A9ULL, 0x2D5BA30DDD8150E6ULL, 0xCE348010E869C6D3ULL, 0x40F60ABA56BE383DULL, 
            0x0F51CCB2A33C7631ULL, 0x15676174239DBBADULL, 0x4D72A7C294FC83B7ULL, 0x32198ADCEC7AA81FULL, 
            0x3896F5F9F883F9FDULL, 0x604DABFD80DF2517ULL, 0xFBA04EB401264F72ULL, 0xF9A5346EFDD9E4D5ULL, 
            0x112554CD855F50D5ULL, 0x4D9C6C010D7B4CFBULL, 0x49268FABF6E02EA7ULL, 0x9E762CA818FDD4C8ULL, 
            0x15ABA5DA673C3534ULL, 0xCCD2522D5E216FEDULL, 0xF905F97C43E67126ULL, 0x5CEB3E7A49E8CAF3ULL, 
            0x35CAB2088871E26EULL, 0xE86CCC8A7B327B8AULL, 0x5B365009A1B90620ULL, 0x3F33A5F5AA6EB7A9ULL
        }
    },
    {
        {
            0x0F7979EC23E81D48ULL, 0x9E79BE882DCC3BF0ULL, 0x0D10944DFAC4653CULL, 0x65867C46840CB882ULL, 
            0x5892E5EAE113F24FULL, 0x42DD951E8C2B279EULL, 0xF80F6CB574CAF4B0ULL, 0x9C2DF3E4AF28E6D0ULL, 
            0xD2908BC3F9A48FCCULL, 0xBF4A40D7BF27BAFEULL, 0x244B7BAF548DD9EBULL, 0xA703CB9821127EC4ULL, 
            0x340B35773BF689B0ULL, 0x2C7A040B625D99BDULL, 0x4F9235C71D46467CULL, 0x54CFDD533087C7EAULL, 
            0x2E7A640BCB2813EDULL, 0xB104284086A1DE66ULL, 0x058431EAF523309AULL, 0x23738021E9964B88ULL, 
            0x3D051B87FD6C63EDULL, 0xAD338B1E758F1CAEULL, 0x2C15BA28BD3D6BD6ULL, 0x5A56032FE254F6FFULL, 
            0x9C45B1B6CE7FD98EULL, 0x52AD2ED6DF2763B7ULL, 0xB68E01A27A549133ULL, 0x2AAFA73D42677553ULL, 
            0x710B5F0F771319E7ULL, 0x6776E766728331CBULL, 0x903BA5E58AF3BA42ULL, 0x45EE237CFDD6B6C5ULL
        },
        {
            0x94DF68CC1621350EULL, 0x55BEEA1450BD915FULL, 0x25E764605BDBF8BAULL, 0xCDA255EF34D6CBEDULL, 
            0x22871DA3B051C90CULL, 0x0361C4F682838D97ULL, 0xFE06A75F14D6ADF8ULL, 0xBB8EE29D8E1A5DD2ULL, 
            0x8E33F793FD48C087ULL, 0x244938EB3245F91DULL, 0x094A3D30B153942AULL, 0xBBBDF116167B694CULL, 
            0xC644A751808B14A1ULL, 0x0895541FB6E6585EULL, 0x7FC14417C10B7AFDULL, 0xC422AC49A8E850F7ULL, 
            0xBD5073FF52F8C325ULL, 0x3B7F025DFC0DFB04ULL, 0xC6CDE442871B0ACAULL, 0xE9C28AD91A84DD1FULL, 
            0x626E20E3030CE95AULL, 0xE706431708C66231ULL, 0xC0C8D8A641778BEDULL, 0x71817ECCF9233E41ULL, 
            0x4164E43DE08C176BULL, 0xD3DAD168E3F3AB23ULL, 0x8DA92B24A72EA3D4ULL, 0x4AC4CF231D1A834AULL, 
            0x7B9ABF65D288C32AULL, 0xA11F0F549A8C8202ULL, 0x400A02630C84BC16ULL, 0xEBB5D780A3CC6201ULL
        },
        {
            0x2582A6F019A283B3ULL, 0xFADBBEBBC24E45F8ULL, 0x3FDB5E040220BC11ULL, 0xE829020F8F3DF51DULL, 
            0x921106B0B75850D1ULL, 0x196F87C5AF3AC227ULL, 0xFCFB722016CAA35EULL, 0xDCC486784DD54970ULL, 
            0xE649367D4E31C39CULL, 0xCD77BB6C0680068BULL, 0x802936B13895178AULL, 0x82FC856827BD256BULL, 
            0x75AD53F0E6EF7236ULL, 0x41823DCB778C8045ULL, 0x538043CCCD1ADDDDULL, 0xF1A289ACFE3E79CCULL, 
            0x94D136D82D9082DDULL, 0x2FA157203F656090ULL, 0x2653BCD9432F4663ULL, 0x369E9AD408D71D25ULL, 
            0x548B8FCC4AC7FD82ULL, 0x9D46ABEA3C39C33BULL, 0xF09A41AC13584F29ULL, 0x069002BC7E83019BULL, 
            0x92D736613C821F43ULL, 0x71A7AF337359B95EULL, 0x566C616857228D24ULL, 0x46018AC4E41A63EBULL, 
            0xD2327677E7D5AA67ULL, 0xA66A5B40CE67D2A8ULL, 0x31DD7D7B0752CCA5ULL, 0xF497766230D07BC6ULL
        },
        {
            0x80C2F58B83A300D7ULL, 0x73C3401EC7F19CAAULL, 0xE2A005AD55AED9A3ULL, 0x7545A39E27E970C4ULL, 
            0x1EC6D696C0D2C53FULL, 0xDE33697B505B9C6BULL, 0x2D37CA3BA83E77FDULL, 0xD9599CA32BB825EBULL, 
            0x434DDE416ECD1555ULL, 0x1DF86BFCD9451202ULL, 0xA94412BE1CAA95ACULL, 0x7A123E16BED443E8ULL, 
            0x173CB25C7C560835ULL, 0xF5A159D3799F7751ULL, 0xA3531F1DB553A414ULL, 0xDB434A10FDD38C4AULL, 
            0x330E91D8613B868AULL, 0x64D1745EE633D4F8ULL, 0x900354249869B082ULL, 0x853503B9673A772AULL, 
            0xD0588BB0AAB894FEULL, 0xA958C2D7B1072587ULL, 0x5BE2C264A00E7D95ULL, 0x65B763AB5E21EDCEULL, 
            0xA2D6BBD6B7DB0D55ULL, 0x3D4EA43BE7C6363BULL, 0x59D1EAFF445269A6ULL, 0xEB6C4569F24FCEFDULL, 
            0xBE8CF81C0A5C0D21ULL, 0xE6186EBA79706194ULL, 0xEB455BC2F50762D5ULL, 0x0F249C440E8EF915ULL
        },
        {
            0x4ECDCE4644948859ULL, 0x94A7922CF070BC26ULL, 0xFECB480467EFC300ULL, 0x01F5F0ECE6FFB213ULL, 
            0xA671545F794D9E3AULL, 0x1924E89B7B4279D5ULL, 0xD2F8252E8E727A1DULL, 0x12385A66C3999B25ULL, 
            0xFF285CDA4D70EFBBULL, 0xFDBBEE9C1FBB79AAULL, 0x5DCAA14D466FF661ULL, 0xD2A57AD81AFB35A9ULL, 
            0xFB02438ABD9CD767ULL, 0xAAE718CCDD3A1BC2ULL, 0x501485D8F1A60427ULL, 0x6D81C67C64D5883CULL, 
            0x47AECD5590BC6F43ULL, 0x112BD2792613DE2BULL, 0xA1FE97E918999384ULL, 0x36E01E09DFB38868ULL, 
            0x4E1FC8353CFBE6FDULL, 0xBC61AFB8294BCEFFULL, 0x4826D450F950189BULL, 0x8E420F97FBC3A68DULL, 
            0x99E8EFAB3501158CULL, 0x92070C60D58198DBULL, 0xEAA4AB4F22202EB7ULL, 0xFCDA7F0FB80AC183ULL, 
            0x685DFDDA6A25403AULL, 0x6E1D5CD36A38B30EULL, 0xF66F6B15DAF7D026ULL, 0x60805C71C10BCEAAULL
        },
        {
            0x91E0ED22FBFCBFAFULL, 0x4FBAB52B401E736FULL, 0x18A359D6C587EE61ULL, 0x2B9D17B454F1F553ULL, 
            0x7E69A98D47156047ULL, 0x6BA52EB40A1A4643ULL, 0xBA14A753DE0BE744ULL, 0x0822A555D88CF287ULL, 
            0x9B7E6163DA0A1170ULL, 0xD23942D867DFE4B7ULL, 0x3C325AAFAFCB3F5AULL, 0x034D1E36FF041822ULL, 
            0xEAF60E4411F9E712ULL, 0x07864655E561DD73ULL, 0xF68AD1125A521E81ULL, 0xEEE953BE96859738ULL, 
            0x709E66CDC0EDBED9ULL, 0x92BE5AB2534FF13EULL, 0x94E09FC1ECC16F9CULL, 0xE9ABAC267936C573ULL, 
            0x96E6CAF4C1BC0ABDULL, 0x3DFFBB040EC5EE4FULL, 0x105F003C7D1C2014ULL, 0x802FE57C18968782ULL, 
            0x6695F16E94D6EDC6ULL, 0x2C61273CE777FDE2ULL, 0x3DA04F146A48AF20ULL, 0x5368417CFDD7CA37ULL, 
            0x009F1A016762DA4BULL, 0x339FF042ACD0F889ULL, 0xAF44809D39C47EAEULL, 0x31EB927CA195674BULL
        }
    },
    {
        {
            0x9DFAD1196E20F5DEULL, 0x8EAB829C01301260ULL, 0xEBEA10B31C28DDCAULL, 0x14AB89CA8428111DULL, 
            0x74FEAE8179100577ULL, 0x19F9586E2AE87267ULL, 0xC146C42045F4D1C1ULL, 0xE875A0AFFE6F34C0ULL, 
            0x1CF1C9444E3F9F8DULL, 0x3F5B468FB4D140E0ULL, 0x051D4E4B416BB862ULL, 0x8DBB822475914AD3ULL, 
            0x8E4B5687F9C24084ULL, 0x05007AC66AE3354AULL, 0xE0F943F97BC56CC1ULL, 0x8F31F44A3F684D33ULL, 
            0xAD248AAB0193D399ULL, 0x07D52B57931BC045ULL, 0x437AFAF85AE8F865ULL, 0xEFE82B2E70BD477BULL, 
            0x2E3686774F896DB6ULL, 0x77DB2F76005E46CAULL, 0x44D53BBD6B855912ULL, 0xE48CC82C0445E6C1ULL, 
            0x7E88051A2CF20F45ULL, 0x1C25FD4EBA2587E2ULL, 0x1F5E7F04D909AB43ULL, 0xE4607D1A9C858D0DULL, 
            0xF66BD688A87D2A77ULL, 0x6DB4074AFA59802EULL, 0xD40CAD0C9340DF79ULL, 0x50C66DFABE9933DAULL
        },
        {
            0x19F5CA195BC30848ULL, 0x31539737B48247E0ULL, 0x2888080ED948F15BULL, 0x637700987AC8DF2FULL, 
            0x54049344BC812ACBULL, 0xBAFF301386CB76BBULL, 0x5A8E3F3B5422CE4FULL, 0xBBAFE59722BAEED4ULL, 
            0x8E36B20D7E897D23ULL, 0x1998EB9DF33E5F49ULL, 0x0BA5C6BB1E3A4781ULL, 0x56941B8A2C65F7D2ULL, 
            0x7EAD4A8ADAFBFD75ULL, 0x274D9C62D1D6AA3AULL, 0xC81F8BB49838F230ULL, 0x93B13DCA94F9AEB7ULL, 
            0xC2619EA923EF65DEULL, 0xD07AEFE884AD3D06ULL, 0xA77DDBAF932024C6ULL, 0xC70199D2196607EDULL, 
            0xE2962DF24D0255F2ULL, 0xFE1CE226366D13BEULL, 0x056200577B82D767ULL, 0xA304A10F1F4D230AULL, 
            0x86C31E72F1840466ULL, 0xB490D23D11D86EDCULL, 0xA06CFFCC6FAE1CE6ULL, 0x2869F18DF18EAF44ULL, 
            0x34AF577BCBB67BC9ULL, 0x7C5CA45C101CA2FCULL, 0x40203A9CA08330F3ULL, 0x1B94E7906CC42C56ULL
        },
        {
            0x87E69057E4ABEB10ULL, 0x7BCFC35A7AE0E041ULL, 0xDF7BC6710415B04DULL, 0xE4F0BB8C32574E6FULL, 
            0x72B4FC42CDB993DDULL, 0xDCBE8D2D8265311AULL, 0xB9884746695D8A1FULL, 0x247101337D4F908FULL, 
            0xFEF881AE0F1D9F33ULL, 0xB58ACFADABE6A5C2ULL, 0xBCDA926094397E9DULL, 0x10C975F610BCBD9BULL, 
            0x15CC6293FF227B12ULL, 0x465A075FD0505880ULL, 0xA73BA755787D0F25ULL, 0xFB4A037A24A0AA84ULL, 
            0x8F60CCAA8A49EC27ULL, 0xE8E99F6BF55EE7B5ULL, 0x5BA3F34B9392FF1CULL, 0xA48B2D0ECBEF566AULL, 
            0x6A3ACF3B6320F8B2ULL, 0x21D5FAA9FCD8C94EULL, 0x592AFB78725CEEBCULL, 0x5A0F51B1E842CD0CULL, 
            0x017AADB1DC077922ULL, 0x6BBD36EB467C1E7AULL, 0x1045F2C08505213BULL, 0xA5D3826439E81C76ULL, 
            0x7DDD61EBF8AC84C6ULL, 0xBD840B28F1FE4897ULL, 0x696A3C79EDD8C5C1ULL, 0xCE0B3CCB014B6312ULL
        },
        {
            0xF9486AF12FCEE612ULL, 0xAE0FF21932629EC8ULL, 0xAE789C8E1326C5BFULL, 0xB83697F05BBD7E3BULL, 
            0xCAC61D855AB47F7AULL, 0x31C00E19FD9F98B4ULL, 0x9924F236A807B8E2ULL, 0x6AFE6B5083FFD737ULL, 
            0xFD0DE418D884E227ULL, 0x79C8BA0C35E1E4F7ULL, 0xA4CCE8CBD0AA30ABULL, 0x4C97F3F0038B790BULL, 
            0xB783FC1AFDC59B65ULL, 0x210CB6AEE367E6F2ULL, 0xF308D670F7FF0A62ULL, 0xC757F6EB56606D0CULL, 
            0x96AB168BAC124D0DULL, 0x96B82EE51961A68BULL, 0xD7C14B0758DBB93CULL, 0x839F17E4AC74F688ULL, 
            0x3600FCC81388824CULL, 0x4B491F30975F2069ULL, 0x40645BF14389DA77ULL, 0x7F3E6498B8870A05ULL, 
            0x367BAF1D0BED720AULL, 0x28FD45B5B0742BB1ULL, 0xA177599919CE5C49ULL, 0x1598A293D82D2E8FULL, 
            0x63A9845D1A697342ULL, 0x7E09EA369C41236BULL, 0x9061739D8020CF85ULL, 0x32C5E4FEDAF1EB29ULL
        },
        {
            0x78C09900AE58FDE4ULL, 0x3A11C0722B390FB3ULL, 0x68A5CBC93D2578B1ULL, 0xE7372091796A9877ULL, 
            0x27855DAF1181B1D5ULL, 0xD79B499FB767AA68ULL, 0x8E4EE74A00D5BCF7ULL, 0xCA57093A836CD9DDULL, 
            0x99E05473778CEB5CULL, 0x38E89FC0C6F31971ULL, 0x90B1C8659D5955BEULL, 0x3D60C4E8E4F31B66ULL, 
            0xBF9B1BEB13E1E63DULL, 0xA87DE822E9BF7BA6ULL, 0xF9E0C721393B87A1ULL, 0xBBFA6BBDFFD6484EULL, 
            0x82D98B6F73C607B0ULL, 0xEE369826A9BA4C57ULL, 0x816E14A167143557ULL, 0x87E04BE0E09176A9ULL, 
            0xE65FB8FC46137185ULL, 0x72BB31EF2AB937DDULL, 0x438E3D5F9109C918ULL, 0xCE38593C31612224ULL, 
            0x5598E7791A8AC67FULL, 0xDEF1FE6A6B2F64A8ULL, 0x3E5A867DE629A7A0ULL, 0xE997BE3E91A0AFC0ULL, 
            0x55A99F048D47450AULL, 0x108F7A0AF56F984CULL, 0xFD0C7946BB3E295DULL, 0xDED88F7E0B68A270ULL
        },
        {
            0xDCDC5A2F9DA913F3ULL, 0x505FA8337EC8169AULL, 0x43B608B6F01F3561ULL, 0xDEC84F4309782D0EULL, 
            0x8861899B4DE5B990ULL, 0xBD4E71A27354E0DCULL, 0xF552EA90970BCA6AULL, 0x6A3FCF3EB790E8DAULL, 
            0x68B3CF630A3F8648ULL, 0x933B33755A68CF99ULL, 0x68CB3FAFB86C2879ULL, 0x0348A3EA1558A74AULL, 
            0x67FBD49817DAD18AULL, 0x636C183821634934ULL, 0xAB355EB5ED2BF7B1ULL, 0x3A711A1F4F81F83CULL, 
            0xA73CA090242E4C51ULL, 0xC3FE07BEC79419BCULL, 0xAAD6B87A7154D4E2ULL, 0x9D455CDB6EA591FDULL, 
            0x6066344212D0FBF1ULL, 0x9E22BF7BD1EBC217ULL, 0x269D42B1DE8D4E61ULL, 0x6624777E51338621ULL, 
            0xE6C973BFF7CA7B70ULL, 0xD542416D99E01284ULL, 0xCC482F1A0CF37942ULL, 0xE8E12351EBA86705ULL, 
            0xB4B42498087625A5ULL, 0xA1E3E4C5B9B7488BULL, 0x0FED41C56060356DULL, 0xB599BAE45E91C2D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseDConstants = {
    0xE3DE6FF6E75DF2EFULL,
    0xA31CBC23088985B9ULL,
    0x6748BB1B4296708EULL,
    0xE3DE6FF6E75DF2EFULL,
    0xA31CBC23088985B9ULL,
    0x6748BB1B4296708EULL,
    0xE44463DFA8085E79ULL,
    0xE60F3BA59F88695DULL,
    0xB7,
    0xEB,
    0xB8,
    0x29,
    0x85,
    0x43,
    0x42,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseESalts = {
    {
        {
            0x48D6338B5329254EULL, 0xA386BC01E0D5EF74ULL, 0x3C7DFFE451809E1BULL, 0x10027C6A734D3008ULL, 
            0x66C1345A048FB946ULL, 0x344A2151E01EE31DULL, 0xC74474B61B221BEEULL, 0x6AC3A15A8837C353ULL, 
            0x0B540C9CE7FBD544ULL, 0x0E358D215CA33126ULL, 0x6DE20E7AE00AD76BULL, 0x06037E61603A4A8CULL, 
            0x31B89A48FE474759ULL, 0xF99C94181D01ABF2ULL, 0x807A35FA21586A3BULL, 0x688BEC4B16963678ULL, 
            0xB1E07E9A703833EBULL, 0x9E74CD12D1176386ULL, 0xC37FBA362CCCC538ULL, 0x9B414DFBE76A6246ULL, 
            0xF7EA6A6B67F7BB1BULL, 0xDE389A10A016145AULL, 0x617C039E8FB97D1FULL, 0x574AABEE06740149ULL, 
            0x9E991FEE5041968EULL, 0xBEF0DD7CBF1BD5BBULL, 0x8C821050ED6A0588ULL, 0x88F65824DD052249ULL, 
            0xB27CA76641501A10ULL, 0x9A509F7FEAE7E90CULL, 0xB42987F1E398EE1FULL, 0x62643C1B7EC00165ULL
        },
        {
            0x2CC6236778BCF363ULL, 0xACC22A30D87ED1D1ULL, 0x02797A1CF68D9070ULL, 0x36DF830FE962893AULL, 
            0xF16344AD40B88B58ULL, 0x6015858AE26DE0B7ULL, 0xDDC3E150B9F3DE37ULL, 0xDCC75EE6C0CD88E8ULL, 
            0x6C413B87C1ED3B26ULL, 0x0DDF58C44FF11390ULL, 0x752DB2A794E839EFULL, 0x6FCE34BC515A86E9ULL, 
            0x63EBEA3D87BA02F9ULL, 0xD3B44A8D79AF14E8ULL, 0x5BBA99FF7A1D6478ULL, 0x6A2B5CFBD6ABC7F0ULL, 
            0x866A2B30A9271867ULL, 0xF5A2813E66734A86ULL, 0xEDF7A793A232A2E8ULL, 0x4BA0F78769A4667EULL, 
            0xB386C3AEFB796DF4ULL, 0x5F2A8158886F3DF5ULL, 0x4E6F11B00454BAE3ULL, 0x04B1A37D65A25743ULL, 
            0x52E9943A0775BC11ULL, 0xB381871076FDD024ULL, 0x20C280862B7A980CULL, 0xD858F5B2A53CA3E7ULL, 
            0x9CC67153B7A37158ULL, 0x24FC883BE182402CULL, 0xA2306B626FF5CCB7ULL, 0x5A1FF5B04FA7B944ULL
        },
        {
            0xC0C827B672052DB7ULL, 0x473F040321A7DCC5ULL, 0x8A0B90CB421EBA77ULL, 0xE030CFB6FAA62238ULL, 
            0x6450980BFAFE30E6ULL, 0x2E313553C95C77CFULL, 0xB68AC3F3C3F79AA4ULL, 0x41E32B70867068F3ULL, 
            0xACB2E724CE34B04DULL, 0xEFD3CE9D7697A838ULL, 0xCB9F63BFFDEAA9A5ULL, 0x078F7BD0D3205678ULL, 
            0xBBF94FA75BABBD8DULL, 0x2433B315FFACEBF5ULL, 0x101F04CF90713C7DULL, 0x7C4B910408608A8EULL, 
            0x3BE25AB21E8E26B5ULL, 0x835703BDA2F099C2ULL, 0x1A4C4C2880B3BD74ULL, 0xCCEEB9E378443658ULL, 
            0x1AA0924EFDC8AA85ULL, 0xB41B937DB79DEB9CULL, 0x97FA52567FB93583ULL, 0xF353A0762C5502A0ULL, 
            0x60789B2B8D2A938FULL, 0x6281C1EF80FCBF1EULL, 0x8C4D7DE28B61BA45ULL, 0x4F1B0E23AA6F5DABULL, 
            0x815CC77868285F0FULL, 0x17C39CB00179231CULL, 0x41BF762B0BA1353FULL, 0xFE2804E248C6D99AULL
        },
        {
            0x6067C0EE19714CF0ULL, 0x890B6BCDC6EA702AULL, 0xCEFA8D38198DE954ULL, 0xD7B1958BBAE4B639ULL, 
            0x33E54EDC8AD2625CULL, 0xB5E08E9B868351FDULL, 0x240420C908ABAAE0ULL, 0xE9BC8CB31DF564ADULL, 
            0x3FAEDC17264ADAC3ULL, 0x09B7C104B3C89DE9ULL, 0xDC3B6B347C286C14ULL, 0x46A3F22448F989C4ULL, 
            0x5646EF35E0D48FF5ULL, 0x3942392090DA19B2ULL, 0xB2369C301AF93167ULL, 0x31D552B0D2DA3FA2ULL, 
            0xEB6BF026A83373A4ULL, 0x27422810C7417C77ULL, 0x6A0CFAB6457B21D3ULL, 0xBF53448621B276BCULL, 
            0xAFB3858FDA1CA727ULL, 0xA0FCDC4125E2B506ULL, 0x10B41BDD00011741ULL, 0x5B7EE22BF95F7799ULL, 
            0x54100F304E833144ULL, 0xFB15779AFEE3718FULL, 0xA8C9D819EAAB63F0ULL, 0x7F504449D16AE72FULL, 
            0x82F0EC56F735BBF3ULL, 0xF0BBEA05D26F5EFDULL, 0x1A4F2C7A4B075D16ULL, 0x5761A5ACC4352D7DULL
        },
        {
            0x2E12BC9BAA44BC5DULL, 0xBBF6462AC3D4A6CBULL, 0xADD725B829434814ULL, 0x1A0C3173C6D7AE02ULL, 
            0x97A30E1C169DF86EULL, 0xAD04E33362527A55ULL, 0x733A626DE3BD2111ULL, 0xDE5ED7854D8D4405ULL, 
            0x91F3BAAED694A40DULL, 0x9AB026811DF0D20FULL, 0x4D24CC1056347EECULL, 0xFEC75DC157D60B65ULL, 
            0x0F922174294C4A40ULL, 0x4044602BD3594CCCULL, 0x96AFCE2DC6A9F27BULL, 0x1EB802D9638F4EC3ULL, 
            0x62FE4EC25454AF70ULL, 0x82BBCF2421719CE9ULL, 0x7628CA797551C558ULL, 0xE16DAD5F7D848AACULL, 
            0x128D46DA94727100ULL, 0x591547ADCE5F6318ULL, 0x3F8B3CCA5737DEECULL, 0xDBC4473965A3C095ULL, 
            0xAFD8AB98D9713573ULL, 0x2F6E1BF28D68479CULL, 0x8B784AAAC150661EULL, 0x430EF362463C7D79ULL, 
            0xDDAE0F61F68E1DD9ULL, 0x75844E2773865D4DULL, 0xB47C92E7A902C52BULL, 0xE5E073515C8EFA89ULL
        },
        {
            0x9EEB3C8DC3D6D279ULL, 0x08692F77D5F6D2C2ULL, 0xEEAD43AB7BD6E85BULL, 0x4CBE1C86F8A54C5BULL, 
            0x5AFF5726B9E9F1CFULL, 0x2B3D3018090978C2ULL, 0x37B1B718A6DB2502ULL, 0x13A3A7BDEB5B26DAULL, 
            0x5DC35D3790ED82AFULL, 0xE3DDDF3DEAE498BEULL, 0xB10A21ED26D2772DULL, 0xC340CDA071677808ULL, 
            0xBEC85EF5FDD40FD2ULL, 0x22E606F6E316E629ULL, 0x108600D8E7318D02ULL, 0x479ED2C2314A413CULL, 
            0xFE11E994E188BE7AULL, 0x0F7E453C87E72308ULL, 0x9C0F7DB3011B5D84ULL, 0x45543193AB11BC38ULL, 
            0x6E59E182DE1532F5ULL, 0xE6C45DB270001AA2ULL, 0x2A77BCF36B4F3116ULL, 0x9D8C4622C6DA7516ULL, 
            0xD4E2C4651F3792D6ULL, 0xD2CEC9093DB1912BULL, 0xB171EA2FF9CC351DULL, 0xE1AEBBB2F68FCCC9ULL, 
            0xEACE7D8557208565ULL, 0x3FBF1346B1444B33ULL, 0xADDF5B8ED732BA6DULL, 0x56259C1EB4385B95ULL
        }
    },
    {
        {
            0x2B0249301B9D1758ULL, 0x724DDBB9115D65D1ULL, 0x09071F4449B3E79FULL, 0xCBCE4D2A9E67635DULL, 
            0x0B66A93CCE849071ULL, 0xB8052948C7AEB179ULL, 0x288647F3EA30E91EULL, 0x3DC345E4FFAB23F5ULL, 
            0x8D0AF69889730A60ULL, 0x817DFBB6216564CDULL, 0x174E41FEEFE1FBA9ULL, 0xC75FD7BD211A5417ULL, 
            0x4FA4ED7C31C6153DULL, 0x678E14979D797C72ULL, 0xD831C414760B44ACULL, 0x68779A0823CABAEDULL, 
            0x41B02285F787CECBULL, 0xCE4045E5B83E34B6ULL, 0xAB42CC97FB8BA24BULL, 0x106C82568C731941ULL, 
            0x75FA61BC04ECDA62ULL, 0x9B1F27EAA206ECC9ULL, 0x35605BE3B58394ADULL, 0xB796DA1E45AC6C5DULL, 
            0xBDA02C3D60C5E8DEULL, 0x8A59A2B06E61AA23ULL, 0x6644B6B8B9CC8526ULL, 0xA9DE36C04A5CB591ULL, 
            0xBAAAB7693B0CB955ULL, 0x305DAE9FE74D5385ULL, 0xB3B5BA3D48DB9420ULL, 0x30A8CC05529305CEULL
        },
        {
            0xCF72CB60D40B36EAULL, 0xDCE47C6F21C61E12ULL, 0x8FE3ACDBEA671A14ULL, 0x6B6257DB88345533ULL, 
            0x3EA816673F04CEABULL, 0x27EC654ED782A37DULL, 0xA3375812006A49FCULL, 0x9B895D1A2651161BULL, 
            0x6A4A8CCBAF636124ULL, 0x56176A806E1B5EBAULL, 0xEE4BAB75CE4D85EBULL, 0x2C2CC5633892E82CULL, 
            0x6BCA3E0E8727E093ULL, 0x9274B3D7045E488BULL, 0x79E8659B9E6AB159ULL, 0x946B0BFA1E5DBA94ULL, 
            0xE73DFA8E18CCC755ULL, 0xB0A80A99007123A5ULL, 0x9135B789DA5E0B41ULL, 0x1B6E62DAA437BD9EULL, 
            0x432AF0624443B0FEULL, 0x3F664C9973D12682ULL, 0x76182FBBF15FB15DULL, 0x19CB397F6D820415ULL, 
            0x2D13254B912DA58AULL, 0xA3B107AD79480F8CULL, 0x5E9A4E7D80F32868ULL, 0x53E426765E9188E6ULL, 
            0xFCEA18B911955F1CULL, 0x0027B8B36FD159CFULL, 0xB2D4F606C74E7309ULL, 0x78AAADE2D3714956ULL
        },
        {
            0xD9FD14288F805F5EULL, 0x77BC776143633502ULL, 0x3AFB1B4F3A926F78ULL, 0x4896BB74AC3A58A7ULL, 
            0x9ED5BD90F0C666BAULL, 0xE336D2E20BC85FE0ULL, 0xE4D21005F260C295ULL, 0xC5F45DCAA828CACAULL, 
            0x07FBA66E2F76EC33ULL, 0xA2511D9C986AD4D3ULL, 0xF532DE0FE7A2E40DULL, 0x786930333424A128ULL, 
            0x9F6B6A1A7930C915ULL, 0x598D70190E9A191AULL, 0x54A0F87FBA2BE08CULL, 0x95086F49EB59EE87ULL, 
            0x3A229851D69277C5ULL, 0xE65ED707782D5A6FULL, 0x59E1CC40BD50C341ULL, 0x240CB9283C993AC5ULL, 
            0xAC12C53451372BB7ULL, 0xAF2CFA1D923F2488ULL, 0xDE012C070AECC8D7ULL, 0x976F83B4F616BAB5ULL, 
            0x7FE53E2DBC97120EULL, 0xE2F9D6CA699C3F93ULL, 0x09A48C09AA77FC9DULL, 0x7FE98C059A54B33FULL, 
            0xFB6A7247CEAE73BFULL, 0x6EF44EDE2BB91BBDULL, 0x477C522501B4013AULL, 0x4A980BCA20CEE638ULL
        },
        {
            0x65BDD83D95A1D387ULL, 0xF7AACDE7706158ECULL, 0xE030C12BBF8D7D6AULL, 0x06E0B18CCE526A38ULL, 
            0xDE43D8FBB977B9D5ULL, 0x325BDE597EA83E9BULL, 0x93E43D97369D973CULL, 0x622430AB67D974DAULL, 
            0x97A703436C4F2419ULL, 0x1909347A1FF7A9BDULL, 0xB91C3359C5CE40B8ULL, 0x9C913085D6D56B85ULL, 
            0x3FCEEDB198AADA71ULL, 0x40A50B050457827BULL, 0xC67D91FB4FBABC8FULL, 0xEC6169F286F14DEBULL, 
            0xCB6A37933AB1FF9AULL, 0x11A5EF9C4919A1CDULL, 0x75DFB878620651A3ULL, 0xDC3FD47BA9164EA0ULL, 
            0x51E584C1681685E8ULL, 0x2E1B6595B9E5135FULL, 0x6356882662A52375ULL, 0x48B784BB931BC128ULL, 
            0xDEEB2BB430A308E3ULL, 0x25091E59BE475C5AULL, 0x3E9A7C5C34A2DCC8ULL, 0x19244466F980E2C8ULL, 
            0xC51F6CA6F8987CCDULL, 0x7DFBD46507BA3574ULL, 0xAA9EEC5CE2C4C0CCULL, 0xD5C6A1F1FFCC7C5FULL
        },
        {
            0x7DEC6FE562FFFDFBULL, 0xAA60B15E82F04EC2ULL, 0x149BD5D27B1AD149ULL, 0x86CB9324C9D41E32ULL, 
            0x728D65A231185739ULL, 0xFF69A32C063B34D3ULL, 0x046E3E381F833859ULL, 0xA450F96270054EB0ULL, 
            0x0C38D93037007A38ULL, 0x6AE24501E9BCB429ULL, 0xB807B8D51E66E941ULL, 0x133F9424C755F08DULL, 
            0x2E3822A7C811BED4ULL, 0xDE25150F07AB0EF1ULL, 0x0501128850BFF73FULL, 0x3BFEE76AF8071E66ULL, 
            0x112D6ABDE1BCE469ULL, 0x6F998BA23E7E359AULL, 0xDFCC5AE7F57D98FFULL, 0x86DCD8999A4CF67FULL, 
            0xA29DC4C08DCE53CCULL, 0x5DA2F78D7B38367AULL, 0xD13CFD5A3AC05FB5ULL, 0x688C49748CD76359ULL, 
            0x1302C87328ACA50EULL, 0x3E96C245CB88B945ULL, 0x07D30E614C2DBDBAULL, 0x85A96A67BC16C3CCULL, 
            0x8B8EE68B7A2862C5ULL, 0x2976EAF1AAD56D0DULL, 0x1ADB9C46B8F6905EULL, 0xFC64D05F86E8349DULL
        },
        {
            0xFCE08E88C07F9475ULL, 0x9F41543577246A51ULL, 0x82B408CC1E995542ULL, 0x6768B6BC2B55CDC5ULL, 
            0x055B617FB5DD0036ULL, 0xDAB3F68C1927F2F1ULL, 0x240774483936E0D5ULL, 0xD5E02406EE7A1D22ULL, 
            0x2F317115B44013A2ULL, 0x7F32F38BB446CABDULL, 0x71DF54518FF63C87ULL, 0x0E0FC40A216ACFC5ULL, 
            0xD68C20F1C02E0B70ULL, 0x1C73746344C930CDULL, 0xE435E5C678A57333ULL, 0x73C5C1F93332DFFAULL, 
            0xF5C3BBEF4D0D9FC0ULL, 0x562CC285E41A1068ULL, 0x5F4CB924790D91E8ULL, 0x725B39C7E0F568F6ULL, 
            0x45125464A8A4D604ULL, 0x8D999F40C6BA743BULL, 0x5B0307886DD7E1D8ULL, 0xC790142F04299A1EULL, 
            0x3D001C1F77AA236FULL, 0x12C4AAD7060D8961ULL, 0x7DB7A833E3DEA909ULL, 0xE5EC068C9ABF71DAULL, 
            0x5559B2E32F8BDC5DULL, 0x330DBE592321F5A8ULL, 0x237EEEB14FA7F3F9ULL, 0xEA96800A522F253EULL
        }
    },
    {
        {
            0xA9D180154A45E496ULL, 0x9311B05F013372A4ULL, 0x630BAFB85F55F642ULL, 0x9C8298A619C07F3AULL, 
            0x11B7A5574F349506ULL, 0x87AD874D79ACDE1AULL, 0x48F066E72958E234ULL, 0xDB35684513F4745EULL, 
            0x566EA402A677228BULL, 0x3BFA482697CABDE4ULL, 0x8241EEE27219DC33ULL, 0x49FE5A9DC3B56895ULL, 
            0xA1432CCD46D89679ULL, 0x6C4B274C7848E8FDULL, 0x0E293B76FF8D084CULL, 0xE1CDC56FDDE9B81CULL, 
            0xB297F21E0F9D0CA2ULL, 0x5CFD2B06741CD212ULL, 0xB6FE1A5BE72945B3ULL, 0x3AE5CB61EE544BD2ULL, 
            0x030B5D652CF66AC9ULL, 0xFF62E2DA1E967B18ULL, 0xF6233264F67D1D9CULL, 0x4FC1565DEC531317ULL, 
            0xD8554A24496D3A6CULL, 0xB90DFA94BB44E90CULL, 0x9B3A997D500B7B26ULL, 0x8DF1B0CABC4FBAE9ULL, 
            0x879870243F046CF7ULL, 0x940BF5C618F0E6CEULL, 0xE32C812FFB56C081ULL, 0xD9E8B0F7D7EEACC0ULL
        },
        {
            0x81B31F1A3C61DD82ULL, 0x681E984CF96674E6ULL, 0xFCE663CC1AF2BC69ULL, 0x65D9D9B8637FB7D6ULL, 
            0xE51C54C3E64171E1ULL, 0xF80838254109BF26ULL, 0x88FA301F921DF21CULL, 0x7B4CA340D772970AULL, 
            0x03F71D12C4132C4BULL, 0x430FC7D6CDD050EBULL, 0x5A5C1BCBFDF537A0ULL, 0xA12716321AD3C3A8ULL, 
            0x90368A181475983AULL, 0x07A071440F15E33BULL, 0x5DFEA87F9B1424B0ULL, 0xEC2B1E0903266031ULL, 
            0x92C10FD9B9640FA7ULL, 0xB77B9E82A3FD0887ULL, 0x99EAB643FF13F588ULL, 0xB617EF05950C7405ULL, 
            0xC2820F7A4322872CULL, 0xF6EA9CDCB1FE866EULL, 0xCA4C501962D60EAFULL, 0x014C16E3242CCB0FULL, 
            0xDCC8DDF62442B70AULL, 0x0CEDAD8CCC51DFB3ULL, 0x8301C727D3CD1BC9ULL, 0x46AE10171B4709F0ULL, 
            0x742C248D4E715BBBULL, 0x32D5261DF3B5FC09ULL, 0x80377846A72258D1ULL, 0x1884CE80D060F1CDULL
        },
        {
            0xE55FC5B8E607B1EAULL, 0x1BE619157BF5CD4FULL, 0x0A184C8DBAB83A51ULL, 0xF5B5571338CA9A7FULL, 
            0x2CA77E27EA1A1320ULL, 0xC31BF053EB353B24ULL, 0xB0D3A024D2609A78ULL, 0xB5A74C4B59C6A9C9ULL, 
            0x6683AE9F2E2CE67CULL, 0x225971DE054E0AD4ULL, 0x443354A3B83DEB0FULL, 0x16E1454AAAAD7CE3ULL, 
            0xAC418ED9D0E9BD9DULL, 0xB062AAE537A68145ULL, 0x38E188A3AA1AD6A3ULL, 0xE41F1BC6A2BA7011ULL, 
            0x62E635D70535F11DULL, 0x893ECB9CA1012C11ULL, 0xAB0D1AD1E5D5EA5DULL, 0xECF206957A4623F8ULL, 
            0x4C4751728E8E4DFFULL, 0xFB50910428010B15ULL, 0x9865604B7B383ABBULL, 0x8FEBA40CDCA406BFULL, 
            0x33E74604D99AE9E3ULL, 0x7A0C7F4BDDE575A8ULL, 0x82CD8DD9EC8D81BCULL, 0x320AA16DA0C8B46CULL, 
            0x0A501022578AB199ULL, 0x05CBA42DC9726A3DULL, 0xE3D8F0F250C6427DULL, 0x220FC8FA0E639E87ULL
        },
        {
            0x076A12ADB46A53E5ULL, 0xE68A0DE5DC42A00BULL, 0x82266399337DA620ULL, 0xDFE0A71E041D53ECULL, 
            0x760547E774871264ULL, 0xDEE394E92C97C8B9ULL, 0xEFB0FCFD78B5E5A6ULL, 0x99A1541597B228A5ULL, 
            0x229D5C949C00235FULL, 0x4719F59C3D47DDE7ULL, 0xDF620A603C394E76ULL, 0xB33CD9D533389EF5ULL, 
            0x7B5974427144FFBEULL, 0xB25C39E1A65F0B8EULL, 0x3711939F5FEC2D62ULL, 0xFF2604CD1B866C40ULL, 
            0xCAC57378DDD632CAULL, 0xE0CC2970E6B9D703ULL, 0x708FE1E722CA25E2ULL, 0x80F77C99F034E53BULL, 
            0xA867891D31824B4BULL, 0x4BCB6AC84134F5AAULL, 0xAF5EAB71A7E755C0ULL, 0x5AC8C58C651CED93ULL, 
            0x0CA8955A7558A700ULL, 0xE881FA1DA29C3868ULL, 0xDB2EDAE9C6E04DF3ULL, 0x4DCB60A8AACF1DA4ULL, 
            0x0B61AD70D1D47CE3ULL, 0xA494CFE7E6EB0750ULL, 0xF6926BE35BB228A1ULL, 0x1622AD6B3C7FD13DULL
        },
        {
            0xDEDDA8FB1C103883ULL, 0x38705E43A6B9CE78ULL, 0xEA4F6BE66C647B37ULL, 0x150E22EA28AC1A90ULL, 
            0x7B3CC4216674327DULL, 0x250A4863FC4E97B7ULL, 0x38A9BD96C493C54CULL, 0x561A2336EEF4838FULL, 
            0x5A77BDE1B2EF1462ULL, 0xA50DB0562DB2AE3FULL, 0x2A4492A47770917CULL, 0x20CD20AAF10B0B9FULL, 
            0x6FA1940EECEAD426ULL, 0xF70E2B7826414457ULL, 0x63A26E05A7A87CEBULL, 0x6E90280FEE81B31FULL, 
            0xA499D93A97EB67FDULL, 0x98ABF77568ABE41BULL, 0x9E6C9B08F4FBFAD5ULL, 0x5461DFDFC4950EB0ULL, 
            0xFAFEE8E0122757B9ULL, 0x354DBF8787021515ULL, 0xA6CF94F40ECF2E61ULL, 0x34DC70501096B7F0ULL, 
            0x691025EB853C3653ULL, 0xDB4DAE92AE6D812CULL, 0xEEC3EAAF99482B52ULL, 0x2611AA9D2D8599D5ULL, 
            0x475E4AF59A8E662CULL, 0xA184E485FD2AA176ULL, 0x85625FAD8BCC1697ULL, 0x5B168AEA8612A1FCULL
        },
        {
            0xAC43DD17C58473CCULL, 0xCB118F3023D43AA5ULL, 0x17E7EF3AA9B3C51BULL, 0x100DD391F470A74CULL, 
            0x45CC519659C61FA5ULL, 0xF3771A451ABFC082ULL, 0x6E612B4EEAD1D2B2ULL, 0xDE4C1CE0E4E5325DULL, 
            0x22D029A8449229B0ULL, 0x2DBCBF39A1E9260FULL, 0x8C495C00B2036995ULL, 0x8A75C7316DB172B5ULL, 
            0x3613F045F47CC184ULL, 0x0C663A72C8B7B663ULL, 0x31135F32D4F41723ULL, 0xD62E37A86EEE91ACULL, 
            0x295801072980F164ULL, 0x66C6302963C33AD2ULL, 0x40AD058BAB5747F9ULL, 0xF9964078A22E5C8EULL, 
            0x4AF6105439C96198ULL, 0x3A6E8541FE82DAE4ULL, 0x76E1D4F3B5814E7CULL, 0x60F6839A7C33DCC2ULL, 
            0xB62432C414646463ULL, 0x7EF8EBE8DF0DC5F2ULL, 0xD9CDB338664745E3ULL, 0x60F7F15ABF3E2CCEULL, 
            0xA717CF8FAD90D5EDULL, 0x564AFACCD3CA1A66ULL, 0x93367AB64E01E53DULL, 0xE57C18F2E98DEC95ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseEConstants = {
    0xB04AD6CB7CAB724FULL,
    0x43710BAE8F5FFCDAULL,
    0x096EF22120079EE0ULL,
    0xB04AD6CB7CAB724FULL,
    0x43710BAE8F5FFCDAULL,
    0x096EF22120079EE0ULL,
    0x5870830793F1B5EFULL,
    0x2A1650B416B3EE79ULL,
    0xFB,
    0x33,
    0xB6,
    0x2B,
    0xB3,
    0xCE,
    0x96,
    0xA1
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseFSalts = {
    {
        {
            0xA1167533E5E293B3ULL, 0xCAC4164741DCEAEDULL, 0x7350DC834B69FF2FULL, 0x94EF24044769C073ULL, 
            0xE243A307E7BDC2B8ULL, 0xA996062271EB29C5ULL, 0xB3EB28D12F15522EULL, 0x4975AC686F8F13A5ULL, 
            0xB6D83D9CCEAB06B7ULL, 0xBD489202AFAF0179ULL, 0xFB5580054A2889A9ULL, 0xBCED55E93F6EACE0ULL, 
            0xE717C823B7EA667DULL, 0xAD814B05A8CD6072ULL, 0x3DF375E3CF64B89AULL, 0xF59DB5E5F1604978ULL, 
            0x5AFE914E415231A9ULL, 0x05DA57D5EFA1363DULL, 0xCF746535FB93AD1DULL, 0xD7A022B976062C71ULL, 
            0x671ED4F22C02F8ABULL, 0xEF2F97D0D25136BDULL, 0x2D8EB20FCC7EFC37ULL, 0x573E77DB9481757FULL, 
            0xA0743D4A3D558A0AULL, 0x8C828B2A85A66C7FULL, 0xC088213C9AD62873ULL, 0xED3176390916BB5EULL, 
            0xADDC90CA9644155BULL, 0x735E99CA0B8A0FF5ULL, 0xDF4307BE3C13D1C2ULL, 0x3297A93300D4D38DULL
        },
        {
            0x40633155CCB65A57ULL, 0xE9F500480DA304BDULL, 0xF5C69E53302C3AACULL, 0x8C285A7F49864B03ULL, 
            0x79F7EC51D89817F8ULL, 0x8C8443A5F9CD48A3ULL, 0x59C5987C154F2859ULL, 0x639D2854E1CD6E2BULL, 
            0xF004FD974FE063D0ULL, 0xE37298F1B9D80933ULL, 0xDB01DB0C9096D388ULL, 0x6FC39816AFF89A03ULL, 
            0x9D56E09ABA47E0E3ULL, 0xB138119D5FD8B99AULL, 0x0C04E2CB87438835ULL, 0x9DC2946E6D88D7C5ULL, 
            0x3F0F5DC86D0C05D5ULL, 0x1C2A9489C2066F14ULL, 0x71BFBCE9984DEF16ULL, 0xD90FFCEAA6D73151ULL, 
            0xE5B9C96C6A1C77FFULL, 0x407706CB5238A797ULL, 0x0473CC3EB0DF39B7ULL, 0x517B2E13E05B698CULL, 
            0xC3D2EB367392F9F2ULL, 0xD302619D44B805CFULL, 0x8DB901D5496C7373ULL, 0xC42238B379CFD694ULL, 
            0xE26BFA8F5B61B179ULL, 0x67B07232D0F14A85ULL, 0x41577A5A946D9652ULL, 0x32F559A932245599ULL
        },
        {
            0xDF7EA759966EB643ULL, 0x5C12D37E448C2FFDULL, 0x151768EDF580EE99ULL, 0x2FF5C410F7FA53B7ULL, 
            0xDBE411A87D58AD29ULL, 0x4F614E6ECF953311ULL, 0x24230356EB73F1E7ULL, 0x2CAF59686876EAAAULL, 
            0x8B4098D848354BC6ULL, 0x91B87C1B1C8C44D3ULL, 0x41672F4BCA111779ULL, 0x65A83D198AFEF92EULL, 
            0xB4A027F247B9BB93ULL, 0x2A7CD805361A4370ULL, 0x2554E812E15CE5EEULL, 0x3BB752C908A2415AULL, 
            0xFBFB1E1EEF7F460FULL, 0xFDCD50BCA1EEAEBAULL, 0x9E335A5ED3D1EC80ULL, 0xE229238DE4A19129ULL, 
            0x120AFA7D1D2C30E0ULL, 0x94D88ED62EE42257ULL, 0xB4D5E225F31851F6ULL, 0xE0E9407B368AA6ABULL, 
            0xC178E5AFF8196077ULL, 0xB169CA144E833C21ULL, 0xDC24CFED8C88350BULL, 0x62A5E75842D63B80ULL, 
            0xADE2C337DDEE0103ULL, 0x8EDAD399DD107508ULL, 0x7414698054C94467ULL, 0xCC1C1149FB68D623ULL
        },
        {
            0x8277E30F13A21098ULL, 0xFE061AF65EADBDEBULL, 0x8D06DA6D5B0A797FULL, 0xED2A78139260BAACULL, 
            0xFF1C6EFD45E587DBULL, 0x4AE1309D2C28E29DULL, 0x493C232E2E1650EAULL, 0x6B7CD889D91F4CADULL, 
            0x6FA95B84C1B04CD7ULL, 0x6F9E745D1B6C351EULL, 0x5EADB48A0C8A42C9ULL, 0x7946167D07D08EFCULL, 
            0x6343BEA1C9F909F1ULL, 0xAEE5CE7D02B86B65ULL, 0x3C7E0D6592629916ULL, 0xB96ADFE77E7493AEULL, 
            0xA41802567C357B52ULL, 0xBD2569488BE7C78CULL, 0xD1AA97D775660EA8ULL, 0xF14C26D6F4ADD9FAULL, 
            0x3F915DECD523A67CULL, 0x9FEAE22FF611DDD0ULL, 0x7C2023279E81C629ULL, 0x3F2B720E93D39D0EULL, 
            0xA9F86BC54623929DULL, 0x068AA4AF739AA181ULL, 0x2D823F43036DF8C2ULL, 0x90CD852052AE6434ULL, 
            0x5C95E24742C45D3AULL, 0xE5B29A40D1C6C593ULL, 0x27ABA1E433EA3CD7ULL, 0x2FC41AF51CC92684ULL
        },
        {
            0x967A6A597261D39BULL, 0xEF8F1393C3C91572ULL, 0x71C224BA08F1861DULL, 0x4860438B0F60550DULL, 
            0x40D535B12F857CDCULL, 0x65ED91FAC91EBA86ULL, 0xC49E1742212ADFF0ULL, 0x8CDD1421E197DF13ULL, 
            0xE2E9CE1E80BC9968ULL, 0x2E05103B5F71246DULL, 0x997AD37F516D8B23ULL, 0xE939DE45156CD578ULL, 
            0xB660664EFAF08A5BULL, 0xE729891248448170ULL, 0xD6E6E3EFD22344F3ULL, 0x5AAB0CFA8FE6EE7AULL, 
            0xBBA8ECED433AA39CULL, 0x4B874EA868044F5FULL, 0x1361D3F17C87FF23ULL, 0x4F263BF5582BA58EULL, 
            0x84AC1D86501376BDULL, 0x6E33A5EB94F55328ULL, 0x191988DCC705EB0AULL, 0xC8794B03AF7FDFEBULL, 
            0x68E7C4BEAFF23B31ULL, 0xBC2F5D22A97D5953ULL, 0xE651146EF94B9474ULL, 0xB6D01C0F7E502D47ULL, 
            0xB14B9BD64F6DE080ULL, 0x69B8246CCF74749AULL, 0xA245B47127776FC3ULL, 0x17F548F885B9460AULL
        },
        {
            0xEC5F0EFDE68216F6ULL, 0x64AFB412FB0D2D81ULL, 0x62467A0E27D6EB1EULL, 0x000EE427190FAB1FULL, 
            0x6EE9170733AD63DFULL, 0x7F416AB632999195ULL, 0x78DB0B9D4D07ABD4ULL, 0x067D3E2EC41228F2ULL, 
            0x502415D3E2BFB401ULL, 0xED8B70B5D1A7569BULL, 0x383968184AEC01EAULL, 0xA54FF914D01E2B70ULL, 
            0x63DD88CE9D270B67ULL, 0x96257CC0BD94B100ULL, 0xDAB042B1C5E5EE6AULL, 0xFE9888889E8780BDULL, 
            0x5F81ACEB18032F13ULL, 0xCA00204C8CBAEF63ULL, 0xAC803AF31B18CEABULL, 0x9676113EDBA04A1DULL, 
            0xAFF180D19ABD1020ULL, 0x33614AF1D096C8EAULL, 0x431B9B2DDD1D9FEBULL, 0xD21EDE851EA10279ULL, 
            0xE250535779020ACAULL, 0x0E0D5A3498003230ULL, 0x4DD3459B5BACD842ULL, 0x2F2817021EC899BFULL, 
            0x848524193EFC062EULL, 0xF65F02884F6EC23DULL, 0xC18B66D74F887259ULL, 0x2B9E6CB2E459C382ULL
        }
    },
    {
        {
            0xC5900C2D5AE94901ULL, 0x721C4E36223ED0BAULL, 0xB0825B2D97A77C9DULL, 0x01128532AB18A6DEULL, 
            0xA7FEB98329788D5DULL, 0x79F919FFBEFB5FB1ULL, 0xD6782FF209FFB6DBULL, 0xF6F9207C589A5F86ULL, 
            0x4681450C7F54CF03ULL, 0x944065A33B80AA91ULL, 0xB3875DF54540BE16ULL, 0x5889BF1C9556324DULL, 
            0xD50CF77FC68B298EULL, 0x2C33586B3A998417ULL, 0x786C1AE9545661F6ULL, 0xAE4FC1C6A7A440FDULL, 
            0x5F5C3E4E0FD81BACULL, 0x2655EA29CF7F4548ULL, 0x25BB8B675F4E8DF3ULL, 0x8E5CBD51788FF2FEULL, 
            0xACA493495698037BULL, 0x6223DADA09A6BFC4ULL, 0xB35FBF7E8391B031ULL, 0x3815705E77736506ULL, 
            0xE4CC4F7D41624827ULL, 0xEFF3889217E4EDFAULL, 0xFC3D3E31522CC949ULL, 0x365642EB0BD53A7BULL, 
            0x30E176E2531EA10FULL, 0xA7E274B5DCEBB58AULL, 0x3FA5238D38D39DA9ULL, 0x18DD7659D229511EULL
        },
        {
            0xA568B2F05F417036ULL, 0x0F1FF3E31FAB1AC9ULL, 0xDF0B1FB2316DCAA3ULL, 0x3292C1EDE8C92047ULL, 
            0x3013163B8C8BE737ULL, 0x8F116107B87DB3F5ULL, 0x10543C596102B127ULL, 0x0CFCBCEDBC2219E4ULL, 
            0xC841ED915E190B01ULL, 0x93037C20F7C0B0CEULL, 0x1DA67C2AAFD6E5C8ULL, 0x3E26E1D83EA14D4CULL, 
            0x690A4AAA2CA444FFULL, 0xFECC2D4F2B2259D0ULL, 0xF76C4BD2FE7E8DD8ULL, 0xD852690418D798B2ULL, 
            0xE4055E73F964D38CULL, 0x3F9656B3B365D7BAULL, 0x4820971D1C777F3BULL, 0x426618C7096A3713ULL, 
            0x741F7AB837B21E18ULL, 0xAACC99AFD26BEB63ULL, 0x99DD63FC362BF551ULL, 0x49A73986C93DA51AULL, 
            0x471CDFCD4DECBE2EULL, 0x543AAA35826997D4ULL, 0x7BCADE8862A6F479ULL, 0xF674D70C71ED2611ULL, 
            0xE437B3DE2285B230ULL, 0x193286C4255BF7B4ULL, 0xD7D3CE1076FA6365ULL, 0x45D209372A3961D7ULL
        },
        {
            0xCE54D4531F3B80EDULL, 0xF239F28A133AA8A8ULL, 0x70834F20491DF809ULL, 0xA8DBDD649F22E299ULL, 
            0x830B6BF36534A794ULL, 0xAD1D1A95A6A8C0DFULL, 0xB91395207BB39397ULL, 0xC87687A1542D5F11ULL, 
            0xE8D56314050FF2F1ULL, 0x33C9CA5AC7EA70F7ULL, 0x0B9F8FEEE7B35FD6ULL, 0xE3EAAEBF18D41F0FULL, 
            0xC88DC27870E0AACCULL, 0xF66D329807854783ULL, 0x6255FF625C0F416DULL, 0x1B4046EA65FF5F77ULL, 
            0xD109230C24E31266ULL, 0xED8701D4838C2860ULL, 0xE6D925D4EF59C682ULL, 0xE1AF3A64252C04FDULL, 
            0x340CF5AC2CB04441ULL, 0x86CFF8F2FF3C4314ULL, 0x2EC6DFF82CE2FC2EULL, 0xFC75F9EF306334EDULL, 
            0x51BCA2ECDB7A3D77ULL, 0xBC93841959640BF3ULL, 0x0E06F1A858D227C7ULL, 0x5113D981188C86B8ULL, 
            0x98F5BD699E16FB5EULL, 0xD9DC4FDE5A442C38ULL, 0x485E58E0EC4A5C82ULL, 0x1FEE12FDF4A00985ULL
        },
        {
            0x69E21BCC4F33A247ULL, 0x6828675FF91ED498ULL, 0x9EDF6386A8FD8DEFULL, 0xB465D7565608F279ULL, 
            0xE5AAD242440879E2ULL, 0x3FE2C80D3ACF4E5BULL, 0xFCD0DD7D5CC7E826ULL, 0x99C2BFDDE314AF3DULL, 
            0x26037FCFD784E038ULL, 0x9903AE6AE75174C0ULL, 0x3D19B5F1C0846606ULL, 0x53548923E133F83CULL, 
            0x0C6B72C3404FBF96ULL, 0x932FED9B3F5EDD61ULL, 0xD8301A008186FA60ULL, 0x7A61623FB91611BDULL, 
            0x67232B05245276ADULL, 0xCBBF6B398B957482ULL, 0x5322A3686D66F5BDULL, 0x5D78EA345496D9C8ULL, 
            0xC8D39BD803A9C15BULL, 0xE7289C723878D1B3ULL, 0x48CC5C8EA893ADBDULL, 0x522788C31B0ADDFCULL, 
            0xE8AFED83C0B82231ULL, 0x377B9FFB32C6D56EULL, 0x3245FC092FC813C1ULL, 0xFAAE5920040ED0A7ULL, 
            0x598BDF9776B13B87ULL, 0xD5A20AEB91A696E2ULL, 0xB782B97B7C79C29CULL, 0x081924911F54838FULL
        },
        {
            0xB60513F40A3A7566ULL, 0xD804A36EB2E55398ULL, 0xC63FDB6B04083E56ULL, 0x613E77AF9DAA96F2ULL, 
            0xE0DFFBB1BE3FC11EULL, 0xB7221C5EF6A43D7FULL, 0x552E27944BA137BDULL, 0x0FEDAA3715722BE3ULL, 
            0x2319A4837788AC01ULL, 0xFA65AF21C1FD66B6ULL, 0xDE786389946FDE35ULL, 0x90542D038EB7AE90ULL, 
            0xB451B183C677A837ULL, 0x77B8AC824BB9240DULL, 0xDEAE590350032310ULL, 0x2732A4BEA95FD42BULL, 
            0xB507522B3109012BULL, 0x4657F8B9170F015FULL, 0x3272D7351B080443ULL, 0x8A6F39932EB88F35ULL, 
            0x8E99C425D0013A3BULL, 0xB65894644566B3CEULL, 0x5C03A4BEC73E6267ULL, 0x5E2CBD7CAB0F2748ULL, 
            0x4AA17F16E1CFAB78ULL, 0xF2426F505F6853B8ULL, 0x3EDCDC0CBBE66154ULL, 0x69E0AA8C479A9346ULL, 
            0x2B116A4C60975D98ULL, 0xEC71026B8039FED9ULL, 0x88675BA0CBE874C7ULL, 0xCAEC5A9FBDEC3D24ULL
        },
        {
            0x32D2BCFEB63767B2ULL, 0x0D26E21AF6C9722AULL, 0xBE3E94A9C7734423ULL, 0x355DBC322F9816D8ULL, 
            0x7E63ABC9D9BB1C4FULL, 0xC09F09296F21CEECULL, 0xAAD31C3D194042DDULL, 0x31657AFA00DB2837ULL, 
            0x0B9010BA2FBA7916ULL, 0xE04FD74FA0AABA77ULL, 0xA6309ECEEB1940F5ULL, 0x999E271BD869AD44ULL, 
            0xF730BF42C4418542ULL, 0xDFDE9D9D0BC2538FULL, 0xD02654A1DA4CCAB0ULL, 0x220E2DA62F992C9EULL, 
            0x1FAEEFAA2270CC93ULL, 0x3BCFEECCD6EC8263ULL, 0x7963DABCD0749058ULL, 0x800550B7657BB4EDULL, 
            0x442860300EEEA5D2ULL, 0xA1032D891CC89A37ULL, 0xFFDCAEFDF9475FE9ULL, 0xC007F5D9519D7EC5ULL, 
            0xF4B478521B13AB05ULL, 0x5EF81334C3347855ULL, 0xB67D30961EF3F6DAULL, 0xE08A618839ABC311ULL, 
            0x481AA471C27CBF73ULL, 0xD52B74F695A7F8AEULL, 0xAD0395ED2AA581EBULL, 0x694E7BBB906443D9ULL
        }
    },
    {
        {
            0x0E286D0D4165B8E8ULL, 0x7C62C079E231CCFBULL, 0xDC505D1404A3E2EFULL, 0x41F0D5DA121F13E4ULL, 
            0x96E525A98AAA075FULL, 0x9F583276866756F4ULL, 0xAA0AFB989811A48FULL, 0x19552748F316B528ULL, 
            0xCD4637F5D6F35FF6ULL, 0x6F1507C53D154615ULL, 0xAEDF31E43411B80FULL, 0x426D0163897C914CULL, 
            0xCF8366A21AD1669EULL, 0x984B924420D92947ULL, 0x5D43F2B3F1320D31ULL, 0x9EA5AFCD8947AA57ULL, 
            0xDA8D8990B6AF1ED1ULL, 0x8830DD990F8F737CULL, 0xE322D96FA08A4775ULL, 0xFB32D113A37C3868ULL, 
            0x4AB35CA42E3B4432ULL, 0xCB18B03739FBC96AULL, 0xC85D5B60D7E55D3FULL, 0xF623852B459EFC73ULL, 
            0xD17F62FBF274B5EFULL, 0x5F4BA26C713A154AULL, 0xE6ACDA2B53832A2BULL, 0x75C818E72347CDCEULL, 
            0x03ADCBC8491BEEC4ULL, 0x5B7957136CFF6391ULL, 0x2B5A43F26E72C6CFULL, 0x51FE5C6D9AB790CCULL
        },
        {
            0xCCD8B7C434A92420ULL, 0xFD96B798F3127A65ULL, 0xEEEE4D10D40FAE4CULL, 0xFCA9A476575D2248ULL, 
            0x61EAE06EBC173E72ULL, 0xD98C99486374C17EULL, 0xD8443D2CB60A63E4ULL, 0xBB21559DE59DE808ULL, 
            0xB3514D5BC59C1EA7ULL, 0xA6FAE2E07F8594B0ULL, 0x395B5417DD0137F7ULL, 0x547DE3DF47FA8F3EULL, 
            0xC398C13D5D8BAA61ULL, 0xF8063B49C69AF1B0ULL, 0xDCCB7CC5C8DD097FULL, 0xC8316B31E1CE1412ULL, 
            0x2BC69ABE3BA13A68ULL, 0xF937F6B1AB25BB36ULL, 0xBD249AA3DA62E7E2ULL, 0x20CE6FF95A1D3951ULL, 
            0x3E38B46AA7B33A4EULL, 0x3AAB5B6D4E6F9CDDULL, 0x646769068CB30C02ULL, 0x1C5856336701FFC5ULL, 
            0x96E6A3B4068EC009ULL, 0x29C0E153A2EA8401ULL, 0xA79959792CF83FDFULL, 0x6BC9C67E5A074EB1ULL, 
            0x1FBA0FA96DD0E13BULL, 0x8202F16445FEA3B6ULL, 0xD7F946CC207A3945ULL, 0xE1279E174067DDF2ULL
        },
        {
            0xF1DD870A61357077ULL, 0x7BFEE1D204C3A81EULL, 0xF673678E30A111E0ULL, 0xCED5A1F5F0748122ULL, 
            0xF6251A8B9C39F7A1ULL, 0x5F20865406FA90D0ULL, 0x234B530BCDCE2034ULL, 0x2E01E315C24EF2B4ULL, 
            0x87FE2BAE09C14253ULL, 0x44394D788265200BULL, 0x5179D217E28E192AULL, 0xD5D27E9F6B287D1FULL, 
            0x036D93F37B1BA0CCULL, 0x5B6B0AD4AAF37AD0ULL, 0x038FA189403A279DULL, 0xD750CDE7450A060FULL, 
            0xD3279D0716F2B8D6ULL, 0x7C406267EF599C03ULL, 0xD4B8B901EBB40A73ULL, 0xD3046E097566AB6CULL, 
            0x8C6AB5A591921668ULL, 0x9F7BBDCDA3583367ULL, 0x4B10F20FBB794D5EULL, 0xE54B3BD22472BC95ULL, 
            0xF0CA19693A0FB395ULL, 0xE28CC3D4764640AAULL, 0x4CC5C4F24C1A92A3ULL, 0xDB54CCDB8F88DF33ULL, 
            0xCFEA7A369FC7C5CCULL, 0xB37E8D319FA1C88EULL, 0x59E80100477D9D4EULL, 0x796703B8EA6555E3ULL
        },
        {
            0xB2E4BCF8DE7D8FF3ULL, 0x9A13DE4847F64FFFULL, 0xDD1054C789D44B9DULL, 0x1176D3719C9604A1ULL, 
            0x3E14DEF650E07321ULL, 0xCA850F205993D95EULL, 0xD3D4B2F72E7BDAE1ULL, 0x5614DA911B4E974CULL, 
            0x3BAA89010614B476ULL, 0x4E5BEE2A0A45D49BULL, 0x0E280D5CC737AC5FULL, 0x8178DD6B375E172DULL, 
            0xD1FF09C9AED7BEFAULL, 0xCFC525DB5E25C3EEULL, 0x81AD98C8C1B01CC3ULL, 0x62BC1869AD43C4B4ULL, 
            0x45D9540C34A65AA3ULL, 0x7F1FDC2B950B4E8EULL, 0xF3CF23A77C396F5FULL, 0xB21EBE12EABAEC42ULL, 
            0xFCF651DD43B0DEA4ULL, 0x1D7C12D627B1A501ULL, 0x64B3725E0282075AULL, 0x035A1DEF2AD10450ULL, 
            0xD2193FFF23C7D89EULL, 0x542DCD5ACE67E5EAULL, 0x16335EF0EF8770CEULL, 0xC305F871761C8C7BULL, 
            0x4D2845C86F1E9CB1ULL, 0x4FD8B1CAA374CBCAULL, 0x7C9EFD643B07FDDDULL, 0x1AB1E2187C19A4E6ULL
        },
        {
            0x144AD10B3423B743ULL, 0x19953B7BDF9EF136ULL, 0xFA82D259CFC5D833ULL, 0xB0B8B780FC446A2FULL, 
            0x639365620008BE9FULL, 0x416F7C81F2A03D01ULL, 0xCEA5D2E7ED484D70ULL, 0x8F5DBE8CBFFCDE69ULL, 
            0x65152244C506320AULL, 0xC1855B9368B5E981ULL, 0xF8127B442AD7219DULL, 0x4D57D4C0C0C97555ULL, 
            0xC56B8808B2A27F0CULL, 0x156F7533BCF64F80ULL, 0x17F4CCA86EDE7E16ULL, 0xA423E7782341C4C8ULL, 
            0x4A39638E042F3E3CULL, 0xA6F17B21DD424EDDULL, 0x2AD77E561AABD392ULL, 0x67ED211DF3CF1840ULL, 
            0x25A7ACF59FD312B5ULL, 0xCE1564152F488D66ULL, 0xF3F1367DADDB18B7ULL, 0x42306972AF670E61ULL, 
            0xEAA3439A3DD6B0C0ULL, 0x83EA7EBA4820D9F1ULL, 0x5EA5B5AD2363EA34ULL, 0x465446A092143585ULL, 
            0xDBD6FD2F07F89FCEULL, 0x2F0ABF10D411B6D2ULL, 0xDD472D1A0479544CULL, 0x478BE928DF6D8C30ULL
        },
        {
            0xAD8266AE45304FB1ULL, 0xEBB38E582A3E9056ULL, 0xA1EC258768188FD1ULL, 0x930AD141F4C80FD5ULL, 
            0x73A4310FD349FBA3ULL, 0x9F9221F2E59F1BA3ULL, 0x27759D3F01B3E8DEULL, 0xD101E4ECED0B6617ULL, 
            0xE6B60D5132AD0E8CULL, 0xEF9B965D8C576FD6ULL, 0x1D47EED4CEE23204ULL, 0x01DE39B95605A8A3ULL, 
            0xA91DA5E8B04D9550ULL, 0x02E0B62250B69947ULL, 0xEDDF132DD73353E0ULL, 0xBE518555A5866090ULL, 
            0xC3405FE7AFF8F7E7ULL, 0xB5A5DCD7549C8F42ULL, 0x5CD7223D9D2617B7ULL, 0x2898FEB35CAA405DULL, 
            0xDC0B5612E49D470CULL, 0xADDA2943D0FAA5CDULL, 0x5C3BE3BCDB63D221ULL, 0x1D287A7E0C513ABCULL, 
            0x17F9490B7C75E4D2ULL, 0x0900B48C274D93C8ULL, 0x2042C68FF58A9142ULL, 0x5F77A18DDDA9CE6DULL, 
            0x5F78E225772A717AULL, 0xD5BE1E03396AC58BULL, 0xCE704B497BCAC609ULL, 0x198A88F26AFE57C3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseFConstants = {
    0x8B7BF529B9EA94B2ULL,
    0xC378979A13D34354ULL,
    0xB95662281A52B786ULL,
    0x8B7BF529B9EA94B2ULL,
    0xC378979A13D34354ULL,
    0xB95662281A52B786ULL,
    0xEF52CAE9D06CA318ULL,
    0x5B68B14AD37FEC5DULL,
    0x06,
    0xC7,
    0xA5,
    0xAA,
    0xB5,
    0xDD,
    0x5F,
    0xA4
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseGSalts = {
    {
        {
            0x19A64BDC7CF85E03ULL, 0xBCCE9C26EB3E141EULL, 0x195BCBFA6950BC57ULL, 0x172775652AC36D08ULL, 
            0x88AE4C436839B6A5ULL, 0x54C5399699284CD0ULL, 0xE46CB4FABE64D112ULL, 0x3835EDD61E4FF84FULL, 
            0x632498F06B89083BULL, 0x93EF89B2051757E7ULL, 0x8B2FFF8AF2412075ULL, 0xA4492CAB13CA8423ULL, 
            0x420D309F721B675BULL, 0x1E874334FE43A519ULL, 0x4DBF21DF2A9AFF0EULL, 0x149954211E87D892ULL, 
            0x6F1C8712FCD299FFULL, 0x4F806AFE3A0EB481ULL, 0xAAFF9AC8002F45F2ULL, 0xAE84E15D9D53E2E4ULL, 
            0xFF8AF015CB735B7AULL, 0x5AB92550AEB4817CULL, 0xFA9FF84EBFABDEEFULL, 0xCCA78CC63A4B49C0ULL, 
            0xF5D36C0269DC4181ULL, 0x6754A58504A3C9BBULL, 0x6B157C941410E3EFULL, 0xE6997BE6BFFCB3CCULL, 
            0x5D77673D0EB220BDULL, 0x0E86520A7F949217ULL, 0xA9E5B96125FCF004ULL, 0x5B814B1F0ECC3A37ULL
        },
        {
            0x5BECB70797AA0981ULL, 0xC53B6FF9181BABAAULL, 0x9077350244C9F98DULL, 0x69A56451FDA97B39ULL, 
            0xC83B29E48411E07AULL, 0x5F76B4A82854B31AULL, 0xE071E1C4236EA942ULL, 0xC4C04E1CA6C62FBCULL, 
            0xF3271BCC5C0F28B9ULL, 0x09E70E580F742F74ULL, 0x2129F529963C7567ULL, 0x047EF4A673F3A8D0ULL, 
            0x83CE87F92F2C7228ULL, 0x03478D42AD3D8043ULL, 0x92F3D151F679BCB7ULL, 0x8AD4EDDC010C20C8ULL, 
            0xDEE924C0E0342DF0ULL, 0xA30B7F457539F18FULL, 0x047EC2F7DBDA2AF8ULL, 0x3CB7C449E792BD7BULL, 
            0xCA29C1AF362226B6ULL, 0x6BA942BCB24D8F68ULL, 0xF78CEB070AC220B6ULL, 0x2767B03B1383E051ULL, 
            0xAEEEC2259FFBF922ULL, 0x424B908BE395BDD7ULL, 0x4C64C3F1C35C255DULL, 0xE5FA55BFF8E939F4ULL, 
            0xA94682CF12853FBFULL, 0x11C3C25239409290ULL, 0x7ADAD96BBD022EA7ULL, 0x280C6E49F88943B6ULL
        },
        {
            0xD950245C611454EFULL, 0xD5D9D15E2B1C9A59ULL, 0x297934BAE2631BC8ULL, 0xD6F2C00C301E06CCULL, 
            0xEF760E065B45580BULL, 0x8D7B1207493E6777ULL, 0xD4E7AAF29FBDFA7AULL, 0x69F2E98F4E4CF35AULL, 
            0x2689DC1541854FD8ULL, 0x61AE72BC543D356AULL, 0x385BC2BA0EC84328ULL, 0xE28A1A03D268FCF8ULL, 
            0x42704FDDC4FBC4FBULL, 0xDB854CA1E7F17FAFULL, 0x427CDD25EED2DC1FULL, 0xD358BE78E072C976ULL, 
            0x6DB9DED8F56ECA92ULL, 0xB87AB0C3445E550EULL, 0x7FB8602E3E9B7BB8ULL, 0x1AD9EA97D2BF360EULL, 
            0x9B345CAEF1583BEFULL, 0x4F7B8D6C59728509ULL, 0x32765E1A7BF9784AULL, 0xE354440828222BF1ULL, 
            0xEDF1EFA12A16952EULL, 0xE31C56C6E1EF9950ULL, 0x2CB3C273E957F323ULL, 0x5CC9CDCE133BB6B6ULL, 
            0xFED9731F7B2AE5D7ULL, 0xE8090A7641FBA47CULL, 0x126723DE0F26D9A6ULL, 0xCB59AE1810C50C2CULL
        },
        {
            0x6C08C8DBD45436C0ULL, 0x8B6AA1A3290FAE80ULL, 0x74E164744D3C72FBULL, 0x205629BC6F666A13ULL, 
            0xB287F73E1764841CULL, 0x7D9AE0EA5169B192ULL, 0x81B0563CECAC352AULL, 0xBC13ADBCC23F4E23ULL, 
            0x2F1FBA9B176AA501ULL, 0xF6CFC9EC5AEF3D41ULL, 0x35842E7C67557F41ULL, 0x041953A2D88658DCULL, 
            0x627A09B62A6CFD68ULL, 0xAD303CE3056B9289ULL, 0xA9F8F6E974D22F50ULL, 0x0135C90E3AEB70B6ULL, 
            0xADA87CC586273192ULL, 0x2C466EC7C7AF1611ULL, 0xCA8B850B7C9216B3ULL, 0x58B6F7162FF99767ULL, 
            0x653B26ADE4195A37ULL, 0x81A469AE2D3EE096ULL, 0x3530594F09278E8FULL, 0xD2B6E8ABBDF74C88ULL, 
            0x8F5033DE11A60B1DULL, 0xEF8E1E8A90B893F5ULL, 0xBBBD9317C15768A7ULL, 0x0D24998F3B401528ULL, 
            0x5F51138D34CB89F5ULL, 0xBC7388EE4327FAD4ULL, 0x96DDD3EF5028655FULL, 0x330ECFE1A656F8DFULL
        },
        {
            0xE3A106E274F6A1FBULL, 0x0C342187105E481DULL, 0xDD6EF1DEC7E18B3BULL, 0x0EB5CBDDC4FB208FULL, 
            0x0B384928B24EF3E1ULL, 0x0320B7D3037EC588ULL, 0x6361ECD6D738888EULL, 0x9BD222B3CE5784ACULL, 
            0x21AA1C1D391CF782ULL, 0x131914BBCD5B854FULL, 0x27ED8E1073EDF2FEULL, 0x80E2CF0B720D3DD0ULL, 
            0x82FCE3D079D6AF02ULL, 0x18ED7796C87D0BB5ULL, 0xD0CE1AEA4391563AULL, 0xEC7518EAB23E1C48ULL, 
            0xC33A91FDAE040121ULL, 0x14A25F0CC44F1F73ULL, 0x7EA7068B7617A097ULL, 0x409D1BE38C0EE594ULL, 
            0x7DE7EE5245695FB1ULL, 0x5011D5094E87A0BEULL, 0x74F9D3E1408AADDFULL, 0xE41B04284270A076ULL, 
            0xB7F552568D6BC589ULL, 0x3C5790898F65EE94ULL, 0x8714B2493ED699A5ULL, 0xFE775E9B442A3A89ULL, 
            0xA514F1041E3EC1F4ULL, 0x7BB6784FEE5D2027ULL, 0xB161AF3637537A61ULL, 0xB573747446752B53ULL
        },
        {
            0x52AAC307907F9BABULL, 0x0369B19209022705ULL, 0x16BC1D243C5EEE70ULL, 0x27ECE232740B29C2ULL, 
            0x5EFB8F5697CEA30DULL, 0xA21B64266C80CAB1ULL, 0x397ECB0F7DAE6BCAULL, 0x3B8B418F7A062417ULL, 
            0xA9D3BD13ECAC1A6BULL, 0x20DEC7A4EB15B8FDULL, 0x792C2AD751FD6815ULL, 0x6AB0F72386149E9AULL, 
            0xCBA18237125D39D9ULL, 0xEB47906A7437CEFDULL, 0xAC26C9DEB3E0304BULL, 0xBA15003982E75483ULL, 
            0x733647E41BB6F230ULL, 0xE925F80763F689E2ULL, 0x262D3C987A797F14ULL, 0x223F5FECDE5FE3D6ULL, 
            0xC72AE5507DB4D951ULL, 0x7EB1138826D0585CULL, 0x1139FA40A0E28206ULL, 0xAF05C4EE1D03BD0FULL, 
            0x1A878155DBB54196ULL, 0x363FF32F3CF4685BULL, 0x64E5C999D2B2AA59ULL, 0x7DAFDB51EB90EE2DULL, 
            0xC28741A47B777EFAULL, 0x451A1F21B758FF0EULL, 0x67A5CA21949E64BBULL, 0xC833FA2469174930ULL
        }
    },
    {
        {
            0x6B4ADEB284730B3AULL, 0x3A27D04F8F6BB8B4ULL, 0xEF49A14FEE07CEE0ULL, 0x51436C6A174F697CULL, 
            0xF7B188DEC265709DULL, 0xBD710C02745F593FULL, 0x368D00890357729BULL, 0x388159F10C237FCEULL, 
            0xC7937CF16BC248BEULL, 0x4E6E3A0D1092ADA5ULL, 0x5EB57827E15DE7ABULL, 0xDC861D2E1D60FE83ULL, 
            0x8C8F0FA91D6A202CULL, 0x8AE16883A94A6401ULL, 0x7B50555EECF6D255ULL, 0xF2C40A2D399325D7ULL, 
            0x2FC30771D4ACF960ULL, 0x8C6BEC50AC97622AULL, 0x5600595D3C192CDDULL, 0x4A8140E18AAD21F9ULL, 
            0x6B69B0B28230AD2FULL, 0xE09FE76E7989331DULL, 0xF1D30DD5140B3503ULL, 0xF7426CD4E21B455AULL, 
            0xEAE9B578E2430020ULL, 0x8732117E1A4593ECULL, 0xEA4D40CF15901D8AULL, 0xD4D27D48E2A9975FULL, 
            0x3BBF466549B76C20ULL, 0xE043EAE37A5C26DAULL, 0x5702D44573407F46ULL, 0x9550120E97DECF8EULL
        },
        {
            0xBBDA9CBF0F91E55EULL, 0x365C1F2A2D7F5177ULL, 0xB09B6CEF7A1010CFULL, 0xDA10A1043ABD2C8DULL, 
            0xF278D361E1B63982ULL, 0x40BC5E19EAD09E5CULL, 0x57CFD60A075BE604ULL, 0xC93BE263FE5E1673ULL, 
            0xA98832DC969462DAULL, 0x37046EA78F09EBF9ULL, 0x122285EBEE4C3DEBULL, 0xEC9D7BAEF7F348A1ULL, 
            0xF299AB7D36289534ULL, 0x6E0BA925C9CB3098ULL, 0xC8525A40599FF32FULL, 0xF14D2F15609AD942ULL, 
            0xB1586C9EE780A089ULL, 0x3129BDC00F067846ULL, 0xD1166EFB947F7AD3ULL, 0xC8668C82D3818812ULL, 
            0x7EC5CC72B57D5E25ULL, 0xE82DF7EE315E1D78ULL, 0xF323B182472042B2ULL, 0xE4973044F2BA4FCEULL, 
            0xB6B0C7ED3F1C7056ULL, 0x54E8D92D845FB3D5ULL, 0x0F0B270356E8CE48ULL, 0x5F6DE27F2AFA9D80ULL, 
            0xFCA5241AB85C926FULL, 0xE8F10EC691A8DB13ULL, 0x0A9F84D7D2C58311ULL, 0x92265037671A0EA0ULL
        },
        {
            0x7126EDC2BC8F2FD7ULL, 0x616D6BBB5F027865ULL, 0xB1165FEE462CF431ULL, 0x2F11F48AEFB4D554ULL, 
            0x40A667E9B2093F8FULL, 0x86D958D4A7C687F4ULL, 0x4841766CAB81F4D5ULL, 0x1E3249BF1977AC2BULL, 
            0x78EDE92FD8257F97ULL, 0x2597A739BF3C4091ULL, 0x7B74ABB653C0C32BULL, 0x7D4390E7AE6E4E2CULL, 
            0x41ACC1CF00AFC99AULL, 0x8D7E5481406C994CULL, 0xD7A9E1D09CD05713ULL, 0xC8433507EE0CCBF7ULL, 
            0xE64345EB035CC98CULL, 0x29226C89247DD0E5ULL, 0x44E1A7F367A28BC7ULL, 0x9725434B8DBFAC3BULL, 
            0x5C036970A5FB2A96ULL, 0x25CAE7FFFF9E10CDULL, 0xE6B7487901B5288EULL, 0x8CCC5FB2E73C1984ULL, 
            0x90382CE0B15964E5ULL, 0x02770584D5BEDEC9ULL, 0x5395544D6E2C47B9ULL, 0x6321C0366C332EE6ULL, 
            0x13BFC6B2C433D9BBULL, 0xF1D758C7E89F90CCULL, 0x3E6EFE3174481BB5ULL, 0xAAEB13290D848F20ULL
        },
        {
            0x903C810A554EFC6AULL, 0xE318E4D4D53747E2ULL, 0x0817445C4755C5CBULL, 0xA1D2BAE93DBCFA2AULL, 
            0xBB03321072E45E61ULL, 0x97A7335ACE6917B4ULL, 0xF32A20386B3FBB81ULL, 0x88366D96A5022615ULL, 
            0xE8AA8DB53A70B9EBULL, 0x2ECDCA00A2E4B573ULL, 0xD64309516D9C41C7ULL, 0x6D3812039233A93DULL, 
            0x81AD4720848CA750ULL, 0xBCBDB0B7D721FCB9ULL, 0xCEFD8227C4BE2319ULL, 0x2BCF71D1FF527FAFULL, 
            0x1D963A40B8376203ULL, 0x9CEE6D9CC731AB80ULL, 0xA70DF3765DD0F6F0ULL, 0x027F5E94AA629418ULL, 
            0x743873E8BAF4B6C8ULL, 0x048FDDF2BABD905BULL, 0xD45A95B0DF242A8EULL, 0x402BB7446BF17CEEULL, 
            0x7EC8B0C84548E08BULL, 0x976CD0B127B6CFC2ULL, 0xDA9AC9719D661CCEULL, 0x5CD20AA108665C34ULL, 
            0xCA77E27EA2E49014ULL, 0x8C1AC8C04D3BE823ULL, 0x5C3149DCD827CB79ULL, 0xDF0CB622F37D3280ULL
        },
        {
            0x9C6AF9D99D8F0327ULL, 0x8A1AEF59286E0B4DULL, 0x78BDBA4EDC31B0E0ULL, 0xC53BDDA1D656EFC3ULL, 
            0x004DCBBA75CAE5DAULL, 0xE34B6D57E41CC2B7ULL, 0xAD58C8B99D4A5F0CULL, 0x8E68B4315944E07DULL, 
            0x9FD05051D17EA5FFULL, 0x98B521109BC8B210ULL, 0xF5DD0CD17CC713C2ULL, 0x8B38B0ACDA7167C9ULL, 
            0x8E14CCA47610F04AULL, 0x1FF2FEC60026CC5DULL, 0xB7C864152B471ED0ULL, 0x6479BC290AA987FCULL, 
            0x26BB62FD9DD4A282ULL, 0x2032F38C999EA62AULL, 0x954BE45BEA5FAB40ULL, 0xC24354A80D55D323ULL, 
            0x3A19015B0078CBCCULL, 0x6D02CCE9ED17DA0BULL, 0x781A780A31A794A9ULL, 0x9CDCF5AA459B4488ULL, 
            0xBF5900DD000C40DCULL, 0xBB0D3EB719F8B49AULL, 0x49DAA2586CE439F7ULL, 0x036ECE4FD7DD1B8BULL, 
            0x48B253804B5B05E6ULL, 0x9AF356C7393073E9ULL, 0xD7CA1B0CBD8CE6F6ULL, 0x4DEC844A1F7E0794ULL
        },
        {
            0x00C740C54CB8FD20ULL, 0x588450C240276BE4ULL, 0xA87A26D75DF66A26ULL, 0xE55C1B76F81EDDFDULL, 
            0x956452746B7FE3EFULL, 0xB0783753C8F5D23FULL, 0xE416A16841A6A1E2ULL, 0x9FEC3F7F9E52D34DULL, 
            0x9AE73F085D9CB63DULL, 0x25142E751D7AA4DEULL, 0xF4E09A8F7B3CB37AULL, 0xDE3137E2CDB79D43ULL, 
            0x41AF12D1CCF88308ULL, 0x972F146B9BF8B47EULL, 0x6424B0C180E22918ULL, 0x45D4C64D2BD21352ULL, 
            0xBA06C3F24E4FBB4CULL, 0x75276C2B2E12C2EBULL, 0xEDFFBC83D4C612A1ULL, 0x9639919BCE524960ULL, 
            0x44127B5628FA3CF4ULL, 0xBA0F48B53A94BFEDULL, 0x6C833EB65D6F5C1AULL, 0x4A85C7D3BD9656CFULL, 
            0x84817E11B1B8D06BULL, 0xABF38A3879261857ULL, 0xD62E13D5B444848EULL, 0x5355471A6BFB7C26ULL, 
            0x03319003CBC62943ULL, 0x0B28D40815497709ULL, 0x0B7F14276A15CA8DULL, 0xF1267F137697F6AAULL
        }
    },
    {
        {
            0xDD65C7010E235CFAULL, 0x1FB68E7E8B1990E2ULL, 0x42CD408C4E4DFB24ULL, 0xF668E133681C6F99ULL, 
            0x5766B4976D8D3737ULL, 0x0A3516DEB35F6E89ULL, 0x70CF6F2234B483A7ULL, 0x7EF63146009557F0ULL, 
            0x7E40BD465A411549ULL, 0xE0B04E5907097205ULL, 0xDC7B3679D466237EULL, 0xDDA99835081BB1AEULL, 
            0x00FF26839138BF02ULL, 0x8DFEF068E06FC9E5ULL, 0x4665C257A10913DCULL, 0xE2169ACC17C2C5CDULL, 
            0x6AA2897D8CB3D3FBULL, 0x63200F77E9EEAAD2ULL, 0xB5FD6C58104BD79DULL, 0x6B708EDB6C2D235FULL, 
            0x99C7684510BB6BFCULL, 0x4AE55724F6553D6DULL, 0x67551DD56A2418EEULL, 0x9D5839F819026297ULL, 
            0xF29F26D8531475B2ULL, 0x7E5CAC35E5768104ULL, 0x1D2D54052276B5F7ULL, 0x79F3415B1669557EULL, 
            0x31622D9D0AD971B9ULL, 0x3019C5F26DB6D8D7ULL, 0xD125C6E1BFC033E0ULL, 0x712B00715A831BB7ULL
        },
        {
            0x08C746FC7ED37181ULL, 0xFD4E3E50761D54A5ULL, 0xC85C37FD6070A98FULL, 0x7371614A9FB02D63ULL, 
            0x8BEB6C3ED7E234F2ULL, 0xC5740C44D08F5C2AULL, 0xCBF774E83A95CD65ULL, 0x65E876A6CB607DFBULL, 
            0x8C45B3C98939FAA3ULL, 0xC10CBA2C039E3F7AULL, 0x7E383D44F2FA7123ULL, 0xA47768A1C7E36FA7ULL, 
            0xBA2578CC3636058FULL, 0x3BDA2A4BBEA26221ULL, 0x583C9B55C908CD20ULL, 0x5EFDA66B8C4EC01BULL, 
            0xB6FD5926FEE2F464ULL, 0xA039A18A9E65E366ULL, 0x8F7A3E0DA1DBB701ULL, 0x490551262ADA571CULL, 
            0x6EB0B554705A120EULL, 0xCB12FCBA5E9D91D8ULL, 0x6F83A4FCD78D873DULL, 0xB68A3D1310C062E8ULL, 
            0x7AD748174163C2B1ULL, 0xE2623BDCD8EE0915ULL, 0xBF5EFC906D74BB71ULL, 0x4D4FD2CF6362BA62ULL, 
            0x73842187B258DA29ULL, 0x6CBA9ABB39C41EF7ULL, 0x0DC0EF52B560708BULL, 0x18AAC882B840BB2FULL
        },
        {
            0x4B2B244CE12AAF05ULL, 0xE14A04F1A5E93E49ULL, 0x09B1B152542CF2ABULL, 0x6836EB148BF8E9C1ULL, 
            0x28FBF777344F43B8ULL, 0x7F939346A497248EULL, 0x80A3CC792561FBCCULL, 0x5A93D5E8DACD11E8ULL, 
            0xEE2F3F30E42C1CAAULL, 0xA4F9365990742BE2ULL, 0xCCE8ACEBFFD884F7ULL, 0x30E1854906468D11ULL, 
            0x69BE00279262EB7CULL, 0x1B449AE3F9722AC7ULL, 0xC44987DAEFFD7E9EULL, 0x47222AB493F16CCFULL, 
            0x71831181C61744CAULL, 0xD4304457BBF2208CULL, 0x93A5035720D61CA6ULL, 0x3D6EAA694EE02357ULL, 
            0x3C40C0A16299E1C0ULL, 0x9231E8EF0BBE3B3DULL, 0x502E69D8EE5599B1ULL, 0x1B4DE38CDDDE1AD2ULL, 
            0x749B28826C783AD6ULL, 0x758501B09513B803ULL, 0x82B2AF7D61A0F2D6ULL, 0x7E6D74424EBBF4E1ULL, 
            0xD68907B8DD42EE05ULL, 0xE71BC72A62F188C1ULL, 0x1B8CE99AEA35D5D8ULL, 0x778BC8F2EA065BDEULL
        },
        {
            0xD0F6664F74C494E9ULL, 0xD515D1841834CA29ULL, 0xB8E2B36B72EF5A31ULL, 0xA3028B860BEEAD9AULL, 
            0x230A1BFE2073591DULL, 0xC1CB32648A475D37ULL, 0x938796071A38CF54ULL, 0x03BEB1D3A4644265ULL, 
            0x5EC8528D9E2CE90EULL, 0x8C128B2E16DCC433ULL, 0x4D6F2BA5F60B17FAULL, 0x601B802A416F5BEEULL, 
            0xDE044EDBEF4A65BAULL, 0x61D65F64438EAD3FULL, 0xAC6232FEB34FA4C6ULL, 0x3E91B5865B6CD11AULL, 
            0xDF8478BD596D4F35ULL, 0xA7B2CD70B25F79E1ULL, 0x8CB8AD47B6296235ULL, 0x17AF0502A6854860ULL, 
            0x8659BBC572E970E4ULL, 0x43DCBAE1CEBCBE80ULL, 0xCB8DF0D9826711FEULL, 0x2507ED7A6B44C0D3ULL, 
            0x88581F48E2F8E4BDULL, 0x67758DBDCA6737C2ULL, 0x0821D2A08DD65190ULL, 0x1E379F1E5E87C5F0ULL, 
            0x6BCD2604CCE6A9EBULL, 0x060DB2919858655AULL, 0x68513FC2C241503BULL, 0x45CA8483A5407BB1ULL
        },
        {
            0x4C56501107681409ULL, 0xA7D9DE660A4BE0EAULL, 0x0FAB7E48E604908AULL, 0x4C68C00472F9045AULL, 
            0xEE37BA6BB5F5BE0CULL, 0xC357A9D266C57790ULL, 0x9526677E43DFBBCCULL, 0x97067F6FAA8AFE49ULL, 
            0xE8CCC37663E01E54ULL, 0x4F84E100CFB2EF0BULL, 0x3F6B5292B1230AE5ULL, 0x261DB7F11BAA943BULL, 
            0x38D1AC73B9E0C7A6ULL, 0x645069F96BAE3112ULL, 0xAC6DF3291CB5D5C2ULL, 0x1E256B1684AE007FULL, 
            0x4B05AEE47F554A28ULL, 0x927B4ABE83BED87BULL, 0x4EEFED3D4AEE24A8ULL, 0x54C3FF0EAC17BAE2ULL, 
            0x54B0794A7FE10A76ULL, 0x8F8F1C4FB3196648ULL, 0xAE8055BFDBD7474BULL, 0x06F4AC05BA0091D2ULL, 
            0x4645E97F873C3F85ULL, 0x5A81397DCF1F7F9CULL, 0x8F3153E9489841FCULL, 0x9AD588FEA7E31645ULL, 
            0xEE707CB9023453C5ULL, 0x3A49DBC45EEC85D8ULL, 0x409864789ACF4541ULL, 0x4612AC4CBA967334ULL
        },
        {
            0x307C7B58E44DFEFBULL, 0x41C08F25AE8A43D7ULL, 0xD1F43A2973B4614FULL, 0x61F2F6EFED6A3A6BULL, 
            0x041C359B46B32DD0ULL, 0x5C5CF099BE525002ULL, 0x0D0518052026836AULL, 0x944F214458FA5764ULL, 
            0x563BA3B2E97CC7F2ULL, 0x986A211A91080BC0ULL, 0x9552E1B04B2EE98CULL, 0x71E4A0E311593370ULL, 
            0x38BC5CE04ADD4869ULL, 0xF90F0A9EB2969ED2ULL, 0x81289C36F3ABE53EULL, 0x933F1A12A601C3EBULL, 
            0x4505EA5A0DC0660AULL, 0x0245331125E82285ULL, 0xFB4719A35D2D6221ULL, 0x0447A003A47A57A1ULL, 
            0x06FB160B147DA624ULL, 0x14DCDD4959E981E5ULL, 0x69BF94C2C8A14945ULL, 0x57C45BCC34B9461AULL, 
            0xEF8AEC0317F721A6ULL, 0xC9980E4DF49FD465ULL, 0xB3DBA6249781C504ULL, 0x1CEFC3250B8CACE9ULL, 
            0x6E86DF69331E072EULL, 0x8AA5572BE234ED2CULL, 0xED3DB996C5679E82ULL, 0xEF6DDDB6C9FDF83BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseGConstants = {
    0x0142E5E21AEDB704ULL,
    0xE4F0DD1585FF4BE8ULL,
    0x1AEA247CFC5D8605ULL,
    0x0142E5E21AEDB704ULL,
    0xE4F0DD1585FF4BE8ULL,
    0x1AEA247CFC5D8605ULL,
    0x387B05709CC1ABBDULL,
    0xDB092ACEE5235FE9ULL,
    0x13,
    0x34,
    0x28,
    0x06,
    0x1F,
    0xBF,
    0xBF,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseHSalts = {
    {
        {
            0x42AB0B339EB51A46ULL, 0x681718D482520C66ULL, 0x484815F891769E9EULL, 0x3727FB176D541F2BULL, 
            0x420B9EEF9AEB27D1ULL, 0x79C4D27FADB4E70EULL, 0xABD68D8B49F347C3ULL, 0xF95801C4D72E9098ULL, 
            0x9F3DD12590912FE1ULL, 0x03E8867173067671ULL, 0xBCAB363C48559264ULL, 0x76F631715BB0265AULL, 
            0xBE3988D199798C6FULL, 0x88F9F26BAEB20EA4ULL, 0x9FBEB6B736A8A7EEULL, 0x49F6F4BB65FEC4E2ULL, 
            0xB4922FAD065A8022ULL, 0x7BBB0BB6DA5122C0ULL, 0xCD66DF1C31C47998ULL, 0x014C20C53620CF3FULL, 
            0x8CB3CCF2CCF7A35DULL, 0xCB0EF39FB213C850ULL, 0x8A4290483D7E6874ULL, 0x376E6851658D0D12ULL, 
            0xF1F486DCB8531BC3ULL, 0x4D0FAEBDBE8C99BEULL, 0x9A3654CD3B0AAA9DULL, 0x3B08D83920E0AD34ULL, 
            0x2A0D80214153D93DULL, 0x74A5B9BD08C8DD38ULL, 0x563077FD71EC492FULL, 0xC770E672C10ED844ULL
        },
        {
            0x51AF6560AC58926BULL, 0x0395D131B3C1547AULL, 0xC5A9EAB9051B955CULL, 0xF3C64E41F653FE6FULL, 
            0xC03BC92B521C0282ULL, 0xB33348D26CAF9710ULL, 0xBD6A7E8E7816C524ULL, 0xFD676390FD6D8C6CULL, 
            0x1A855A49586FE59FULL, 0x87433C4F88F9EE9DULL, 0xACD368688C4BA826ULL, 0x9230C8F62070C5F7ULL, 
            0x9DC96B1EB34BC524ULL, 0x2F13269F7C4B28D6ULL, 0x7F6259ADC4689FC9ULL, 0x63BB7143FE276ABEULL, 
            0xB19BED6F3C5E98A6ULL, 0x51C1F56CA787BA1BULL, 0xFBE874AB2ECCF20CULL, 0x0F69CB2A3D283D2FULL, 
            0x79BA620B92A4B873ULL, 0x8CA7C12862E75870ULL, 0x02846F4C0F1E59FCULL, 0x6CAE2E5D59418AEBULL, 
            0x4A85DB52D87BAF1BULL, 0x8453BB0034A0ABD7ULL, 0xBE90BE8E01BC46D3ULL, 0x2D1B26172338CC42ULL, 
            0xE81F67E4BAF9DD6FULL, 0x186E18235DE30963ULL, 0x61049067223B1783ULL, 0xC1E3A69DB9531215ULL
        },
        {
            0x73FCA9C0AB0E21EDULL, 0x3D9E18CA2FC900B0ULL, 0x6AF4786762C1245BULL, 0xFDFE43DC4D55176FULL, 
            0x28A5EFEEDAE5228EULL, 0xA4A1CB7C1B11E632ULL, 0xD9D442C0C1EA5168ULL, 0x007F0BB8AB844EA1ULL, 
            0x9B9B68AACF15D794ULL, 0x55CC6EE3ECC09F9CULL, 0xC046B0D3CD1CA0B1ULL, 0x542E46056705D804ULL, 
            0x10FAC80FD23462CEULL, 0x550E1786A0832F14ULL, 0x839B2746CE0D4260ULL, 0xC374A668E3712900ULL, 
            0xC78EC430DD21B41FULL, 0x1C27158FE5717817ULL, 0x7D61F660714288ECULL, 0x18FFB90EE74CE5E4ULL, 
            0x9CB5F1D783AD5416ULL, 0xBC941634D5ECDAF3ULL, 0xA46257472DBCDDECULL, 0xEEC1D80129180BB5ULL, 
            0x4AFD969EA2A9FAD3ULL, 0x5050FF435FFFA2DEULL, 0x61420AA88CA2AB95ULL, 0xC979AF260C153E86ULL, 
            0xB6996F653C4275BDULL, 0x4BDCA8B16BE3AE19ULL, 0x6C55661A573B4A1AULL, 0xDFDBFA198E65929DULL
        },
        {
            0x0A6EDF75CB1A05D0ULL, 0x7AB278BB3933CA76ULL, 0x19266D123820F382ULL, 0xBFF1DB4F84DF8426ULL, 
            0x8101545350F370A4ULL, 0x65E61EDB7558851CULL, 0xCE60DC7BE4B487F6ULL, 0xF72617A1234A0368ULL, 
            0x3B989B263AE526CDULL, 0x03E82E9B1A9B003DULL, 0x18E391833B4ACD6BULL, 0xE999CB4EC349E54DULL, 
            0x6E37A40C99F3B969ULL, 0x8C2B26C3BF5D482BULL, 0x1D05CEE279595647ULL, 0xA8524884FAF9B1EAULL, 
            0x2EBC9A5A76C4B5CFULL, 0xC43DF39F6931CF71ULL, 0x7E413A036322DD31ULL, 0xA18B48C5AC6F8504ULL, 
            0xD6F042ADCAA5CB1CULL, 0xA2FEA5BC41FD8BB7ULL, 0x1D6C84296B126F73ULL, 0xA0A762A22B9A92F0ULL, 
            0xF2F69F33413A80B4ULL, 0xCF6D77A8503EA682ULL, 0xAF826FAFA9ABA146ULL, 0xCA2308ADF67B550FULL, 
            0xBA37BBDF52D7441DULL, 0x4C85F68A307CDE62ULL, 0xE2D39DCA0ADD7AEEULL, 0xA374DA7F3A34963AULL
        },
        {
            0x6CD44F4E893FEAFEULL, 0xF7E65F902B5AA6E7ULL, 0x28B4600B33D03082ULL, 0x291A188860BE5B68ULL, 
            0x28558844899DFB4CULL, 0x587245CE9A2D5DCBULL, 0x1D4AB511873207CAULL, 0xCD04DE28717A13AAULL, 
            0x53BA1D1F3B329CB7ULL, 0x2650436D80B62009ULL, 0x7EE50DA531B55D13ULL, 0x966A64F40CE4C950ULL, 
            0xFAEEA277A2CCEDA6ULL, 0x13FCA4B5B33C92D1ULL, 0x7BEF143555588BF3ULL, 0x278DDBFC800AAAEFULL, 
            0xD981C42C413C7C52ULL, 0x78836CF7257BBE06ULL, 0xB4CD2DEAE4C1B6C2ULL, 0x28E2FA1CF44DAD01ULL, 
            0xFF9D413673223768ULL, 0x976FFD208097A36DULL, 0xA23CA7D259AD9C27ULL, 0xB6454C81A4BB464AULL, 
            0x02F1BB0B0E9AAB93ULL, 0xC61019D403B7B002ULL, 0x3AF1DBEEADACF2C9ULL, 0x663A92C53F6C8E84ULL, 
            0x1335B0399B832F2DULL, 0x0F733100C0E1CC3CULL, 0x1662E00EAAE4A538ULL, 0x4F1508926072D49CULL
        },
        {
            0x2977AA1C2313F526ULL, 0x17109D62DD71D0FBULL, 0x0D90E291B61DC50BULL, 0xD892F4AB281E0A64ULL, 
            0x188F9AE838155BB4ULL, 0x5B2FFF07AC5C6760ULL, 0x66BAF18F7EBCD8C1ULL, 0x06FA4370F59231FFULL, 
            0x3C076C20B2AD0B1DULL, 0xF244AE4A3A842895ULL, 0x92CEF6524DC3BEA3ULL, 0xBD2B0C49F44314A1ULL, 
            0x5EC5D4B36ACCE4A2ULL, 0x8C1BD4A5D423DDCFULL, 0x3BC3778F78D9C73FULL, 0x1B1F79A431004344ULL, 
            0xCD4CD20E64475D0BULL, 0x8266C30661B97BC2ULL, 0x4D5A44E5651459F5ULL, 0xD2A1BF1329FC427FULL, 
            0x8964FB38251F1985ULL, 0x26F12769384E447FULL, 0xF06763ED2365C806ULL, 0x704856C70C8FDBCFULL, 
            0xD542B73B7B562843ULL, 0x5A4D1E368E007B8AULL, 0x1F149D654A7F4141ULL, 0xD49BE763CA86EDC7ULL, 
            0x45624621D509F48EULL, 0x239B3229A81CFABFULL, 0x79C1023C640BBEC3ULL, 0x0FB2D6F5D704CD12ULL
        }
    },
    {
        {
            0x1EF2201C8159531EULL, 0x82BF861D6BB06FB9ULL, 0xB02B347E2A8383CBULL, 0x5A2396E489B566CFULL, 
            0x3C76AB491CC93590ULL, 0xA153FE937F788492ULL, 0x04342E72898EB014ULL, 0x8B2D2443EE8DD94FULL, 
            0xA42610DE79BA64CAULL, 0x4846FB0DAB29A834ULL, 0xB5C14C2361242F7FULL, 0x352CF6DCB4A72E76ULL, 
            0x8496E04F751DFA86ULL, 0xD1912106F8C120FAULL, 0xBAFC897C96C50EC3ULL, 0x819E7182CB365178ULL, 
            0x89DE30BF590F56D2ULL, 0xD3B819415D437E33ULL, 0x64C5A85BCB222F45ULL, 0xC8A376E65882FA82ULL, 
            0x9FE189F57F6FD11FULL, 0xA5829A464E983927ULL, 0x5F34CACE5B3CAA04ULL, 0x0E4772D4C838C560ULL, 
            0x89C521DD1E714B80ULL, 0x6246EDF38B24848DULL, 0xBD93D33DFC661368ULL, 0xF8E76CC9A7B47EB6ULL, 
            0xAD7296A9D8B8BE70ULL, 0x171F692EB81892FCULL, 0xE40804C6DDB0B889ULL, 0x30297F2F677B0BC7ULL
        },
        {
            0xE1C102133EC3F446ULL, 0x05120336F10C8C36ULL, 0x18944D9835F4B9FDULL, 0xAEA72FE07249E136ULL, 
            0x729EDD8C61FB3D80ULL, 0x503B13B45C79C4EFULL, 0x268D39FB9C8F72FDULL, 0x5B8CCEAC61E93F60ULL, 
            0x5AB740D34B32E3AFULL, 0xABD9C1D5BAB77A84ULL, 0xEEB856BD30EC79F2ULL, 0x32A708D9D1173D7CULL, 
            0xE263F8D23E73231DULL, 0x2D0DAFCF19922731ULL, 0xA679A69B32149FDEULL, 0xAC0A9B65A7DC6F3FULL, 
            0x8B2D79CA70353A0DULL, 0x3BA142035DFDE64AULL, 0xFC693DF01398591DULL, 0xC924EDDDA4F2EE7EULL, 
            0x9FF339B82F06D572ULL, 0x688B7060F945214BULL, 0xDE0BD09913A14625ULL, 0xF771A006E7829718ULL, 
            0x673E6F57718C4969ULL, 0x17F9FFBDE0D1CE86ULL, 0x87003A3EBA2D6474ULL, 0x2458D2D2C5CF50ACULL, 
            0xB4E1482ECB56B37FULL, 0x36007633785CF026ULL, 0x40C2116E34CF44F3ULL, 0x5720FA8025692C34ULL
        },
        {
            0xCE212BB4EBE66BFEULL, 0x059070EF77B389C6ULL, 0x463424698124AB08ULL, 0x969B9216E3F09D73ULL, 
            0x911D703DD1DE94A7ULL, 0xE707D34893A5C68EULL, 0x70743C43B7965619ULL, 0x17D9032150CC7195ULL, 
            0xAACBB83475804C5BULL, 0x0B1A5BEF3C60BF05ULL, 0x27B131BBA83D9051ULL, 0x32FAF373AC7D7AD1ULL, 
            0xE0F79357617E2CBFULL, 0xFD86A6D50D2538E5ULL, 0x574D534AAF8195B1ULL, 0x675E183C6FDDF8C7ULL, 
            0xE65DAE8B80445005ULL, 0x1EF0D5338EFEF280ULL, 0xBECC495CF8223C8EULL, 0x1EB4A3C8D4D541D9ULL, 
            0xCF42F641361F3C45ULL, 0xB0F535AE95876F76ULL, 0x725C8645C719EDE7ULL, 0xC20517C571AC0819ULL, 
            0x4A01BE952D0AF229ULL, 0xBE7307F53B1F4295ULL, 0xA418009720390129ULL, 0x22C90A9484A6B6E8ULL, 
            0x5D64C38D2315B03FULL, 0x3487CCE65C26840CULL, 0x44515281BBB3BF5FULL, 0x00DCD4F768BD9C35ULL
        },
        {
            0x4AF3AC203241D615ULL, 0xAECA7517FA59C54EULL, 0xBE0A69D46D8D2DA8ULL, 0x5F1D8C56AE0FC6DEULL, 
            0xF16F3A93961B27B0ULL, 0x7D428218A61D16B8ULL, 0xED7BB0150843F35AULL, 0xD37B85938178FABCULL, 
            0xE229FFDB0B5F8B13ULL, 0x4EB5ADC5B614FCC1ULL, 0x381E8F940625B935ULL, 0x81EEDB0D1FAE6A09ULL, 
            0xFBEF32FE2E268F16ULL, 0x33836F7417AC44B8ULL, 0x6C8F94B26CE27B5EULL, 0x4E900E8F1AA558D7ULL, 
            0x94009073D46961F1ULL, 0xAA0A09EC5CD0C17BULL, 0xEB6E438E4BA43D45ULL, 0xC85C84A80FE161B8ULL, 
            0x0667AB75E9843F94ULL, 0x641E4B4423196721ULL, 0x6791F86B7AF6F4DAULL, 0x11BBBBFBA5CC7016ULL, 
            0xDF5C9B1E614D2FEDULL, 0x71FAC69A3F8EA9BDULL, 0x2389951FFDB79C2EULL, 0x6D4B0E2114B15E5FULL, 
            0x2A9C0CD6379D9A84ULL, 0xA0EF3FCF23B32A64ULL, 0x93B87E3199057971ULL, 0x09B7A443DF75B9B5ULL
        },
        {
            0x73009D22A40FF4F9ULL, 0xF53256C3A021139FULL, 0x5E56F0B73A399E30ULL, 0xB4CC03466A479ACFULL, 
            0xCB39353C94E8ECBFULL, 0x172B6C370B98657EULL, 0x124B07CD88B3305DULL, 0xA42CD00DBE5C0986ULL, 
            0xFCCBB66CC12B5274ULL, 0xB760DED19206EF24ULL, 0xE7C1A26113480CC0ULL, 0xCEFD4F9923A23846ULL, 
            0xF5E6A610B9CE87CDULL, 0xF38C424D5D906EF8ULL, 0x57EC5BE99F09ABEBULL, 0x5BCA4EA400AF1EECULL, 
            0x3F1ED4C9942FFE31ULL, 0x36860460F5A8EF85ULL, 0x718F96CD1EC2CBC5ULL, 0x9CC91D0088AA018EULL, 
            0xE8C0D725693278E7ULL, 0x8C790BF352E065B8ULL, 0x8EEDCAD9D59CCEF7ULL, 0x39E286AAB66EAB2DULL, 
            0x94A377C554DA79E1ULL, 0xF885D98053C608E5ULL, 0xEA6E63A7EB346527ULL, 0xBC150ABB159FFE00ULL, 
            0x4A5275D889B13F96ULL, 0x918254B7C4FD3C59ULL, 0x05C098EE6CBEC3ECULL, 0x387D06C826C1DF6DULL
        },
        {
            0x370A9612C98576FAULL, 0x78D431FCE8E4BF4DULL, 0x9C3C4128B629A536ULL, 0x97DF431123AA06BEULL, 
            0x8AB7C7695D2CD228ULL, 0x9D8298B0D0A5922DULL, 0x0DB0FA0131C5F8CDULL, 0x7BEAFA614F083776ULL, 
            0xC0F927184C89FFA3ULL, 0x8E22B385DD60A109ULL, 0x445A11359EED330BULL, 0xE248B38F6CD5567DULL, 
            0x4D5FB3E2FC21FF86ULL, 0xB5CB5A54ADC3B605ULL, 0x6C1765BBD9CA7F00ULL, 0x7DD4E5FAE75A7820ULL, 
            0x8B4D2EA9DB4F8D91ULL, 0x696D0FECDCE510A3ULL, 0x229646BA9D16FF08ULL, 0xBC39C1134A2B24F9ULL, 
            0xA447BD645993B4AAULL, 0x46B6498B95806CBCULL, 0x726A59B3B5CC9073ULL, 0xC72480E11A0C0BD3ULL, 
            0xD889716EB7C17885ULL, 0xA1C6D020A40D1BE5ULL, 0xF5C23FFBE9421808ULL, 0x2D5A79F804485A8CULL, 
            0xAA11726603D6394EULL, 0x7FA5EDEFADB51196ULL, 0xCF9DD2CF5D67B96FULL, 0xF4BB6F2EF3260508ULL
        }
    },
    {
        {
            0x653B38CF41A9D3C4ULL, 0xCCB5096B42C70674ULL, 0xA99C76C0199D29CEULL, 0xDB8342C3574AFF92ULL, 
            0x9255E491D274595EULL, 0xC5484E9EDFE46B31ULL, 0xE5C321B9C3351EB9ULL, 0x137D2F85FE4AEA90ULL, 
            0x87D75A99021B0225ULL, 0x0B4AA81E3689E568ULL, 0x5F95ECED91D110CBULL, 0x3E3EFD2A7604D5DDULL, 
            0xDFE64FAB5D0E2CD5ULL, 0xCF7AA8C44595D474ULL, 0x8D6759D8F30F9C3AULL, 0xBBADCAEB68F8EDBBULL, 
            0xB37EDA0E4FD6D099ULL, 0x71CFCB7F3D692426ULL, 0x2EFFB9C3E0A24FC0ULL, 0xF53530FBB6147865ULL, 
            0x78E485540CE9AF38ULL, 0xC3DD41B45EF62A4CULL, 0x3CE7A126A808ADBBULL, 0x80EE0C317DAE4C14ULL, 
            0x8E3714BFA06E8ED3ULL, 0x852827C1FDB482A6ULL, 0x5A952100D7BEA8D3ULL, 0xC1B4006320F3E53BULL, 
            0x822A5E7BC8A67D3FULL, 0xA5E6E3C1432AB70CULL, 0x42677395E6AE771BULL, 0x8A002F10944F6FF1ULL
        },
        {
            0xCCCDD00D69269727ULL, 0x940F55891558E180ULL, 0x8AF270EA1074BE95ULL, 0x988F4F60167BCD8EULL, 
            0x034C83FBB99C09D6ULL, 0x6307AB8274740DB2ULL, 0xD6A3ADEFE1F3E344ULL, 0x71913363645E4DA0ULL, 
            0xE62C77D845555871ULL, 0x1B4794EDD3C822A3ULL, 0x7105598A6B2929B3ULL, 0x35D5144D978EDD44ULL, 
            0x21A37DBDB2E31245ULL, 0x96CCB9687C08DD5AULL, 0xFCFEA87229B14423ULL, 0x45A3229003ECDECEULL, 
            0xBF9F8C6A287A5F43ULL, 0xC1B4756DA8F85BE7ULL, 0xF65C1C72C967D905ULL, 0xA61351F00DC39B2FULL, 
            0x546DB3EEB1D3BC73ULL, 0x46265D8825E5BD63ULL, 0x1680D846734F9897ULL, 0x3B27994B531306FEULL, 
            0x03098870A60F9F3AULL, 0x702508C489D70D83ULL, 0x818B1A509FF3E9C6ULL, 0xB3C3B3DC6C39E10EULL, 
            0xF6CBF88BD9819C05ULL, 0x29A6E85ED99B9D80ULL, 0xB72422726E10F829ULL, 0x147C43DD7DCF9992ULL
        },
        {
            0xFFA257AD60C52DC5ULL, 0x3C543634E04C1B41ULL, 0xD96779C9C4F1B082ULL, 0xB08593A0FAA41C4EULL, 
            0x0DD798330AF36719ULL, 0xA832635E3BDD45E3ULL, 0x9FE9ADF524FCA347ULL, 0xFC771E7AA5D8C785ULL, 
            0x8E9E0CE2E84ECB1BULL, 0x63C2D488D3788D7CULL, 0x0CE4B7D26F0296DCULL, 0x17BC14315CFCC1A5ULL, 
            0x3B35DA0841413A29ULL, 0x17A19D636BAB3825ULL, 0x8C41C8EF02C47060ULL, 0x4683D9FED570EB9CULL, 
            0xF80B84EEEC140C53ULL, 0xA18C60A3C2CED8A3ULL, 0xD3E8CB155216E49BULL, 0x3959455D46AEA809ULL, 
            0x20D6AA4E202ABA4AULL, 0xDE17262549A2C6C4ULL, 0x58EE099139C8CB42ULL, 0xC5E29950905C0A71ULL, 
            0x721FEF6798C36AA8ULL, 0x79633CD7F17F95A3ULL, 0x937EBFD5E3D2B2BDULL, 0x4AFB02BADAC61CD8ULL, 
            0x9B1105CE045C56E0ULL, 0x6AE21D248E04FAA6ULL, 0x89119C258266B656ULL, 0x97FF15851A4544FCULL
        },
        {
            0x2BC42CA09FBAD684ULL, 0xFF337DF1FBB6AD2FULL, 0x3DE733597172E83CULL, 0x0624A2B6E0649EBAULL, 
            0x1D420F9B40C0DFB7ULL, 0xD8F9BBC9B0CE6017ULL, 0x213760740482BF5FULL, 0x9DA388D8EA48D8C1ULL, 
            0x2C10680DA335E4FDULL, 0xBDF865E48CDC4DC8ULL, 0x812C586B2502199BULL, 0xE86F028CB46BDD1DULL, 
            0xD4148B6E17DB2901ULL, 0xD72FC9062D85C786ULL, 0xE4A4CA96F23BA33DULL, 0x8EE265913EFF012EULL, 
            0x0A0862DAFD36324CULL, 0xD31C0C9B55715FB3ULL, 0xFB82B160682D7A16ULL, 0xBABB81385227580BULL, 
            0x7026181343AD5B0BULL, 0x179B3B7471070BD6ULL, 0xDEDED6E43BCF8D95ULL, 0x417CB0C4B86A9361ULL, 
            0xD4BF840722461D8DULL, 0xAECCCA0B6EB91A7FULL, 0xA588943D75055CCCULL, 0x1014A5DC162B9073ULL, 
            0x373DBBD411A2BCC4ULL, 0x5ABEB23BAD95CC71ULL, 0xFB273867D57ABD74ULL, 0x738E1AB99F091614ULL
        },
        {
            0x5A1F2BE7C5FC1D73ULL, 0xA19A6630C79DEA85ULL, 0xD07C890645CDD2E2ULL, 0x0DE33979B07162D0ULL, 
            0xD31763FCD3A36C3FULL, 0x8AFB6AE3CDEDA6DAULL, 0xE31BD952904DC8AFULL, 0x254718134F744086ULL, 
            0xA54ECF0B29B19F6AULL, 0x4EDC7BFCB2263F1DULL, 0xAFD2CE5C417CE64AULL, 0xC3313747ABE74101ULL, 
            0xFEE33328F4A50A26ULL, 0xE8A4FA5C018677ADULL, 0xA22805ACDFD5D22AULL, 0x1F4DD65B2F264ADEULL, 
            0x56B87B2E5D40B749ULL, 0x648496B8F734289DULL, 0xCF5276E6BA0D5DA6ULL, 0x45749D7278FC94BBULL, 
            0x3EBC402FDABB48ABULL, 0x0E613B14A4F4C85EULL, 0xEB54E8CD97BB07F6ULL, 0xA44A46E1F862F1CDULL, 
            0xC2F69352E64AB82BULL, 0x76E7FB1DC267BC72ULL, 0x17CB06556A937DC2ULL, 0x79C44CED8D258926ULL, 
            0x49747B153F3ACCB5ULL, 0x878EB2E8E39892DBULL, 0x31E99994F1D5E1ABULL, 0xE5C4ADE38C1A5FDBULL
        },
        {
            0x2C23C51C7D6F2C52ULL, 0x4EB7F57E96704645ULL, 0x6CD0FA6C3288C466ULL, 0xC2411551DE1E145DULL, 
            0x1F8984E97024B40BULL, 0x508DB745DF5878C1ULL, 0xB2D6B6D5B322F81FULL, 0x351F7501F73B52B8ULL, 
            0x8A0D7C0B76563F29ULL, 0x9F9E0E2AB3876257ULL, 0xDEE4021898AB9D94ULL, 0x11D1449E31D58051ULL, 
            0xD3907BF005349D91ULL, 0x26400B4B32C84168ULL, 0x2ABF049472CA603DULL, 0xED443E93F76B2715ULL, 
            0x89E432B1A8D861C4ULL, 0x4A30F3A04088AAD1ULL, 0x648064920D6A8256ULL, 0xE9414B46604262CAULL, 
            0x705773C85F14682BULL, 0xC810075DD9B5F6E7ULL, 0x53CA65D9381DEE52ULL, 0x28BC4741C189DE45ULL, 
            0x57AC17DB5B712207ULL, 0x1E12C3299BBE2DEAULL, 0xC2FBE9C03DB5DD7BULL, 0x8A4C1FB09CDBCE7DULL, 
            0x02F159CEBF1C6DF4ULL, 0xEF59F9D6069AFF60ULL, 0x011C6C26E8AA8A64ULL, 0x02EC752783915526ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseHConstants = {
    0xCE70209B963D4E1FULL,
    0x5F72AF0CAAB81E0AULL,
    0x4D55A41CCA608B72ULL,
    0xCE70209B963D4E1FULL,
    0x5F72AF0CAAB81E0AULL,
    0x4D55A41CCA608B72ULL,
    0x8E9CBEC0116C54BEULL,
    0x4D1EEF3955DDC6B8ULL,
    0xCE,
    0xDC,
    0x23,
    0x2C,
    0x8B,
    0xE6,
    0xAB,
    0x7E
};

