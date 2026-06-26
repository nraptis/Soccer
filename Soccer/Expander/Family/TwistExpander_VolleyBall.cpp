#include "TwistExpander_VolleyBall.hpp"
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

TwistExpander_VolleyBall::TwistExpander_VolleyBall()
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

void TwistExpander_VolleyBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 13476601246917644994U;
        aCarry = 14559402969160955609U;
        aWandererA = 9348832356316886065U;
        aWandererB = 16310174262574360392U;
        aWandererC = 13068529705223714842U;
        aWandererD = 13308127391462052096U;
        aWandererE = 12707834759022629094U;
        aWandererF = 9486225315298725160U;
        aWandererG = 10621214290613211936U;
        aWandererH = 10786923747942113124U;
        aWandererI = 9488607077046520968U;
        aWandererJ = 13789237005171846178U;
        aWandererK = 17895272012408026832U;
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
    TwistExpander_VolleyBall_Arx aArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_BArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_CArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_DArx;
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

void TwistExpander_VolleyBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14725986397745549866U;
        aCarry = 9651895954473555886U;
        aWandererA = 12540356145450442148U;
        aWandererB = 16554693196887766301U;
        aWandererC = 12640494591806917006U;
        aWandererD = 13558534350137467425U;
        aWandererE = 12665258699542826629U;
        aWandererF = 18382465418296780692U;
        aWandererG = 18235888579240689394U;
        aWandererH = 10001747848483718288U;
        aWandererI = 12135260792498078049U;
        aWandererJ = 11098397896166468661U;
        aWandererK = 9415712200674767098U;
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
    TwistExpander_VolleyBall_Arx aKDF_B_AArx;
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
    TwistExpander_VolleyBall_Arx aKDF_B_BArx;
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
    TwistExpander_VolleyBall_Arx aKDF_B_CArx;
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

void TwistExpander_VolleyBall::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_VolleyBall_Arx aSeed_AArx;
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
    TwistExpander_VolleyBall_Arx aSeed_BArx;
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
    TwistExpander_VolleyBall_Arx aSeed_CArx;
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
    TwistExpander_VolleyBall_Arx aSeed_DArx;
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
    TwistExpander_VolleyBall_Arx aSeed_EArx;
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
    TwistExpander_VolleyBall_Arx aSeed_FArx;
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
    TwistExpander_VolleyBall_Arx aSeed_GArx;
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
    TwistExpander_VolleyBall_Arx aGrow_AArx;
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
    TwistExpander_VolleyBall_Arx aGrow_BArx;
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

void TwistExpander_VolleyBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_VolleyBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 11961798374936360378U;
        aCarry = 17319427374613154649U;
        aWandererA = 10428373482737622532U;
        aWandererB = 17537503273099196494U;
        aWandererC = 18375156405210360499U;
        aWandererD = 17676127484591871969U;
        aWandererE = 11212956620427158215U;
        aWandererF = 9391416371433979614U;
        aWandererG = 11705918995491738961U;
        aWandererH = 15712662097820102312U;
        aWandererI = 12602409537548428706U;
        aWandererJ = 9662276710353843088U;
        aWandererK = 17167969606828468789U;
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
    TwistExpander_VolleyBall_Arx aTwist_AArx;
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
    TwistExpander_VolleyBall_Arx aTwist_BArx;
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
    TwistExpander_VolleyBall_Arx aTwist_CArx;
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
    TwistExpander_VolleyBall_Arx aTwist_DArx;
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_VolleyBall_Arx aGrow_AArx;
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
        TwistExpander_VolleyBall_Arx aGrow_BArx;
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

void TwistExpander_VolleyBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 2 with offsets 2539U, 6926U, 7748U, 3021U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2539U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6926U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7748U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3021U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 3 with offsets 3866U, 5573U, 8022U, 1216U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3866U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5573U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8022U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1216U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 1 with offsets 1837U, 3821U, 6832U, 944U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1837U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3821U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6832U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 944U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 0 with offsets 1351U, 2489U, 728U, 647U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1351U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2489U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 728U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 647U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 with offsets 1746U, 11U, 1291U, 44U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 11U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1291U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 44U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 2, 3 with offsets 439U, 1232U, 86U, 1565U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1232U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 86U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 1, 2 with offsets 1444U, 365U, 847U, 1080U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 365U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 847U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1080U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 1, 3 with offsets 833U, 1856U, 7U, 873U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 833U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1856U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 873U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 509U, 564U, 423U, 1881U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 509U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 564U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 423U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1881U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_VolleyBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 0, 1 with offsets 4271U, 5262U, 320U, 5407U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4271U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5262U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 320U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5407U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 1, 3 with offsets 5359U, 2765U, 6144U, 6526U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5359U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2765U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6144U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6526U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 0 with offsets 387U, 6680U, 4799U, 805U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 387U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6680U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4799U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 805U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 2 with offsets 4027U, 130U, 2149U, 4052U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4027U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 130U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2149U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4052U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5391U, 7740U, 629U, 5875U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5391U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7740U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 629U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5875U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 157U, 222U, 1448U, 260U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 157U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 222U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1448U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 260U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 37U, 387U, 1123U, 1049U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 37U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 387U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1123U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1049U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 279U, 1718U, 1713U, 1226U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 279U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1718U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1226U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 537U, 1133U, 295U, 1634U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 537U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1133U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1634U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 3, 2 [0..<W_KEY]
        // offsets: 182U, 416U, 2033U, 147U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 182U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 416U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2033U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 147U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseASalts = {
    {
        {
            0x2D94BDEB0D17AC75ULL, 0xCB81C094448D8FFDULL, 0xB6E2935AF3CC8427ULL, 0x3396A02BF29CE417ULL, 
            0x3B96CA911C94A493ULL, 0xADACCF34B9645B52ULL, 0x1464D84CE8A95A71ULL, 0x8321E4FDF56D6233ULL, 
            0x3A59E6038DE2D177ULL, 0x49F95A68A29D26AAULL, 0xC294D9CC096C616BULL, 0x72F4CEED57D420AEULL, 
            0xC03647ECC6B4EF62ULL, 0x96E5E4AF96F16C62ULL, 0x7287A4BDA30B5D84ULL, 0x583347B45F6A2A00ULL, 
            0x5FE66D39FE420BD4ULL, 0xD110A3E2D781B475ULL, 0xAEF34C36C722BE2EULL, 0x7D00D327EAACF61EULL, 
            0x55E6EB1FE7CE180FULL, 0xB466DF740EFBB6BCULL, 0x675E98BB0CDAF2BDULL, 0x93258AD97B36D585ULL, 
            0x4FE3E1F41AAE8AA7ULL, 0x401B82BB71B4F136ULL, 0x6FB73DA55A726F33ULL, 0xFA3B9D72D5D3A08DULL, 
            0x43B9AC235A4D002CULL, 0x9C7BEA26895AB0AAULL, 0x6D357F8559733AC7ULL, 0xF55BCD542B5B3055ULL
        },
        {
            0x300EDD9F3103F16BULL, 0xE73C12480F284B78ULL, 0x1F51A45E9F7E9160ULL, 0xA820F3411151A9C8ULL, 
            0x594BC9D2BFCDD49BULL, 0x71F1546E0DAEAD1CULL, 0xCCA58BB0BA6A7CB4ULL, 0x6446E70921053220ULL, 
            0xA533CE2A300BB777ULL, 0x3F36274D58DC6E10ULL, 0x4E6222D33171B9C1ULL, 0x2A5985805BA815C8ULL, 
            0x558EF4BD196837DAULL, 0x76D3C5412E8485B9ULL, 0xFC3A404EEB059AC7ULL, 0x94E2DAE03BD0C519ULL, 
            0x29A522BA72A0BCC6ULL, 0xE909F2DE6B8C8372ULL, 0xEED5B0E32973BA30ULL, 0xF5557A83AFB941E0ULL, 
            0x9B7E9CDAFD5CF8AEULL, 0x750BFC8A5594D212ULL, 0x7D5886CCF5FF3D4EULL, 0xAAF803DDCC7DA24BULL, 
            0xC93DE7DD78B0CA65ULL, 0xD95A0CA0FC1CAE45ULL, 0x0D36865080132629ULL, 0xEB730ABB9483C4E6ULL, 
            0xF79A59E85649108FULL, 0xEA4BDF6B507F759DULL, 0xE27AF0249E3E3F76ULL, 0xB5833D3F73EAAA37ULL
        },
        {
            0x0334C6AD5BE963DBULL, 0x25B7E92B7F4AD7EDULL, 0x6A72F15F8A45B484ULL, 0x0CC6031735095BABULL, 
            0x50FDA22275A99A33ULL, 0x1B2BE7D8E0ACF6E1ULL, 0x301043D3314C8A12ULL, 0x2DA9631DB8FA3FDCULL, 
            0x7264E17AC4BAF936ULL, 0x0FCF9E68F24A3E99ULL, 0xC25FDAC020AE5A4EULL, 0xD9D3F1AF8A615DD7ULL, 
            0x5E6F4750367AC31AULL, 0x79496DD065BEF38BULL, 0x1E18028D1A2E3AAAULL, 0x9471FBD13E37EF47ULL, 
            0xBB74F9F6BD9B4378ULL, 0x022A0B79CCCDF237ULL, 0x25F3A9FAE34B2ABDULL, 0x4E3253DB91687C39ULL, 
            0x538B0C01020E413FULL, 0x4961BDFCB486D692ULL, 0x558BA580F526B178ULL, 0xF034CE5BE84D489BULL, 
            0xC61A3A180215B505ULL, 0x7BD70E5BB27A4005ULL, 0xA1973CA04AB044CEULL, 0x7754C4362AC7656BULL, 
            0x6A6C4D88FD41DA77ULL, 0x746285DF78C8EC3AULL, 0x3C10369EEB822726ULL, 0x514A67DD7A8FF2C8ULL
        },
        {
            0x7E2E8BFF96A8DF4CULL, 0x2C0AF67E2F709D75ULL, 0x2ADD7E703EE85550ULL, 0xD8105EBFCFFEB8B4ULL, 
            0xC7EECBF791955D3DULL, 0x13F4B2A18616F84DULL, 0x311B405263E43D6BULL, 0x0D98FA6D6A42BC29ULL, 
            0x64E7E37ACCF7B640ULL, 0x79942F13A41B719BULL, 0x049105B98A8D750EULL, 0xD6F656273FA4A4C3ULL, 
            0x47115B314D31279EULL, 0x05B09E3C0E830171ULL, 0xF5FB14614E133318ULL, 0x84639A2B0C86FF87ULL, 
            0x2ACDABDC1CF35606ULL, 0x4C7CD1A2596CD4FFULL, 0xDD89381F349E513BULL, 0x71410C163552FCA2ULL, 
            0x6EB1F8A5E730100BULL, 0x6FA8FFCB18309A38ULL, 0x66D02D1EDFFEA324ULL, 0x5A31EF05ABEEB322ULL, 
            0x473F9D1D5A9175EFULL, 0x22EE4194FE645224ULL, 0x245ABE22982F263FULL, 0x976D6A75CE953A89ULL, 
            0x8783F2D933CADA61ULL, 0x67DCCFE8F7FF56CAULL, 0xA3C03D429AEEA5FDULL, 0x1F90100D4433E0ECULL
        },
        {
            0x2D11D5832A8B3AE2ULL, 0x88526D6CEF6D4B83ULL, 0x0FCBB1B9F4B9BE2CULL, 0xF754E496A5BEED46ULL, 
            0x2E132F295C711272ULL, 0xB86CC9E813F5D4B6ULL, 0xC2AB86A060F0B35EULL, 0x67B09F34A6FC178AULL, 
            0x62D5E18F1AEED416ULL, 0x3DA4BB9BA9905977ULL, 0x3968912371F3D2DDULL, 0x372868D3D8DFCF20ULL, 
            0x6F730D4C14224324ULL, 0x43205EFCED6B1F7CULL, 0x83CDB16E21D1C455ULL, 0x29894B0398766C1FULL, 
            0x323DE0C592441B6FULL, 0xCEEFE5B107CC5475ULL, 0x8FD911EC0E952858ULL, 0xCEDC38C52E36C999ULL, 
            0x39677EED82467803ULL, 0x97CEF5A02A08BE3DULL, 0x6A4269DBA31E22B9ULL, 0xFE0132BD84C35C8AULL, 
            0x8ECB9556AE834006ULL, 0x04B9BB14BFB053D3ULL, 0xEF9A715C6239E464ULL, 0x9ED17C488D78B6C4ULL, 
            0x8ABA64634F35E040ULL, 0x5A55D32D39C1044DULL, 0x5D6676D0390DAD8BULL, 0x8EC3C23D869C48BEULL
        },
        {
            0x377E78803DB6C980ULL, 0x8F3F7471C481DB7FULL, 0xA6ED3026E80ABFA8ULL, 0xA1B31A1493DB4035ULL, 
            0x218B80849637FECFULL, 0xFF7DBFC3EB94FF1DULL, 0x90BEFA21529A83F5ULL, 0x2D121FABA0585A0DULL, 
            0xEC519EC75FA8F2B5ULL, 0x3483E3139DE5FA7EULL, 0x828529BDA07438ABULL, 0xA57CABAD9FF77ECBULL, 
            0xE20DB8CF8BFB17D5ULL, 0x64CFC5F371140CF9ULL, 0xB59420A79BCB089CULL, 0x0CC93966F113E44DULL, 
            0x5CFB29223BEF09ECULL, 0x22A7F9262E791B14ULL, 0xB7E1451CC6C74D2FULL, 0x1BFEF5AFE768C195ULL, 
            0xFAEB62A2039F6E6DULL, 0xC2857797D802787BULL, 0xB8BBF1210461C93FULL, 0x502EE04694355BECULL, 
            0x8D3357F9E542EC7DULL, 0x0C91E70E8C6F5F3CULL, 0x3E0A8BB3E301F1C9ULL, 0x93F12E60F66812D6ULL, 
            0x3175F8CFE0CACFF3ULL, 0x6B455438E54CD7ECULL, 0x70D803BA39E71350ULL, 0xBDE835953EF95154ULL
        }
    },
    {
        {
            0x90B2C52AA3B97E74ULL, 0xA37F9CF97EA920D4ULL, 0xF43864E356BA1134ULL, 0xC0820DFCDAFB9E15ULL, 
            0x571EF263FA74E49BULL, 0xC0ED22D753162298ULL, 0x9FCBC3C62168DEDDULL, 0x72581A49B4E54EDDULL, 
            0xD5708E9A4BA45F43ULL, 0xE202136B03BD9EC7ULL, 0xBA190E942CE1308EULL, 0xAD988F5FF0C5E7E7ULL, 
            0x0C293B424A0B101EULL, 0x90E9C11B01F22D08ULL, 0xB8E8F371A5C50254ULL, 0x1F331D72E9015132ULL, 
            0x2E51081E07588AECULL, 0xD1EA72A45F5F43CEULL, 0x0D1120B273D90761ULL, 0xB8DE4561E499C21BULL, 
            0x6FDA7F57BF6CEA65ULL, 0xA1A9966ABF8AC8A6ULL, 0x05EED574CF9D4F93ULL, 0x4737F468C4E7D05AULL, 
            0xB78AAD51AD208E13ULL, 0xF61683FA671CBAF0ULL, 0x0E82DB38754032A8ULL, 0xED31E1F413C605C3ULL, 
            0x584D37DB8C0A38CCULL, 0xD1907925770077E2ULL, 0x64D80C5AC20243DDULL, 0x02775B09D7ED054EULL
        },
        {
            0x3EF38DCC8E1A6BB0ULL, 0xAA3B710F9DE53CAFULL, 0x18D1FF2164D6D7A3ULL, 0x666BB0B9F0028F87ULL, 
            0xFDD91CF493A47F1AULL, 0x685CFC1DC075EC70ULL, 0x1293B4C0F4F49EF0ULL, 0x98E3E6D7E3C1855BULL, 
            0x0B3F7E047BDF6AF1ULL, 0x0E1C9E9AEEF8136BULL, 0xD6A8ABDB6164C143ULL, 0x2CCCFA139CDF1DA0ULL, 
            0x2CF3C4C63D31BEE7ULL, 0xA07B8D0F2FBD3D35ULL, 0x2AF116A047AE6184ULL, 0xF60DDDBE991AD4D2ULL, 
            0xFCCFE869BBBD1934ULL, 0x06B6A34B6F231901ULL, 0x5FF298D8FC2140A5ULL, 0x901891BF21E9CB98ULL, 
            0xBCD56A93EF407265ULL, 0x10366781EA7F49BDULL, 0xED340D8AA524C6FEULL, 0x958AC2FE2757E0BDULL, 
            0xDF191019C4939D23ULL, 0xC041389180B86352ULL, 0x476509E0E20D5E49ULL, 0x9C5406D5AF1FB0DBULL, 
            0x76029845AC453E01ULL, 0xD355847229AEE8F9ULL, 0x6C99CF0A0EC5FFC1ULL, 0x56099CB7A403194AULL
        },
        {
            0xAF39BF524F925819ULL, 0x03610C660F7B8C26ULL, 0x14073F294C56BB2DULL, 0x7D94AF2DAD9130F1ULL, 
            0x067359D18C4E8327ULL, 0xDCE8D3BE459570B2ULL, 0x98D096112472B988ULL, 0x4AD095B6A6A51E1EULL, 
            0x54F770094A517735ULL, 0xBD08227BD656DCD6ULL, 0x883377641D57E21DULL, 0x6967C4D2E93C0FA4ULL, 
            0x1A718E6203EA203FULL, 0x51BC7DB6FF2BC052ULL, 0xD9D3011972CF0BB1ULL, 0x38A9008B0B58B274ULL, 
            0x7F449238D2CD5F10ULL, 0xC274608FF4D00B83ULL, 0x48CE5FCDDD6D5A0FULL, 0x42495BC4A25DF548ULL, 
            0xB74666131FE00C5BULL, 0x38BC0664804714B2ULL, 0x2DA48E0C3244B124ULL, 0x1CBD9A82B032D3FDULL, 
            0x98572971B16788EBULL, 0xB491F080DAF197C6ULL, 0xFACDFB7E4B458C23ULL, 0x421F5A3200771106ULL, 
            0xC52D0B14BE037D25ULL, 0x70C5425ED7A64A4EULL, 0xCBBB033892535392ULL, 0xFCE3EC34E95F10DFULL
        },
        {
            0x42DB710EBD306052ULL, 0x376CAB848C970862ULL, 0x1AC9D9510DD1DB6BULL, 0x1169C60655657912ULL, 
            0xDAC6CC39FF6308BDULL, 0xE688826AF340C56FULL, 0xF161C4D18B2E4F3FULL, 0x02CECC1788001EBAULL, 
            0x573A4BFCF387F38DULL, 0x99A38BB740FAF3AFULL, 0xD016983CFD37A52BULL, 0x35317DC578854C0FULL, 
            0xBB926C57850D956EULL, 0xC571C0D3F7160F65ULL, 0xBAD3679729200727ULL, 0xAA4E09F7BC69F956ULL, 
            0xB79333AFDC938061ULL, 0xF54A75A10947CE56ULL, 0x1952994793671590ULL, 0xA63E28B84C2433D4ULL, 
            0xE5AB969218FA9271ULL, 0x0AEAC182370FE474ULL, 0x1B49400B68144D03ULL, 0x5F467F7A3BB7DDFDULL, 
            0xCFB77668B417FD62ULL, 0xA5F961D33758DB12ULL, 0x05196F6A2AE9B86EULL, 0x4A5840F59F6CE52BULL, 
            0x7BAAB1CEDE4563A0ULL, 0x321301BB521BFD7DULL, 0x11129AB1405D587FULL, 0xA86BC77FE277055CULL
        },
        {
            0xC7C1F34EFE02A26EULL, 0x3959F8667C75A584ULL, 0xB3216A50CB446B89ULL, 0x94F47B594D004213ULL, 
            0xCD996B2B2BE560F4ULL, 0x38373CCC11B01533ULL, 0x53C3A20B492EE0C8ULL, 0x6DFD9ECC762DCC77ULL, 
            0x3965E2B33F47BF8CULL, 0x2D1E8A392F4AA36EULL, 0xB5934E771F5E32C5ULL, 0xF83714D1C7E96CF0ULL, 
            0xD7248663A9B96852ULL, 0x916CF397FE26BD99ULL, 0xCC2141D637DFAD90ULL, 0x9EF0D1194E1A95B6ULL, 
            0x3867B9ECF57370B5ULL, 0x726E3ABC364721B9ULL, 0x4E28B46077EEBDB0ULL, 0x10677BB72A217F28ULL, 
            0xFE71755647C4A7B9ULL, 0x36085D36DD0AEAC7ULL, 0x96E642D7D149C1D3ULL, 0xF1C07DF60141B296ULL, 
            0xE7CDE3C7B13E1A0CULL, 0x14D9883A4B011672ULL, 0xAB18794EE7694F96ULL, 0x1074C9360DB0EFB5ULL, 
            0x26F5F7C52C8B9FC2ULL, 0x2E591685FA405E32ULL, 0xC8D4FE7F79A8E9ADULL, 0xAE74C2A95019A0D4ULL
        },
        {
            0x9B8B782DB7B03CB4ULL, 0x1C504FB4415C8F79ULL, 0xE22C69B1F59D5442ULL, 0xC91874B3FA02A410ULL, 
            0xCBE776BFEDF64C8EULL, 0x2FBBB495BDBB8BBEULL, 0x8F4E8C1F358A0841ULL, 0x8C91865B3F4ECCB7ULL, 
            0x6D6464BD30C97AFCULL, 0x937EEE254F2138FFULL, 0xE940152CB8F630F5ULL, 0x2178FF33FD1E0096ULL, 
            0x43F73A25498F87E1ULL, 0xADF90DFBC7A9CDDEULL, 0x84401CF19B074F5DULL, 0x60741A542CEFA2F3ULL, 
            0xB46C20F5634331FFULL, 0x10CE76B7BF8D697AULL, 0x02F38076F36D6772ULL, 0x7328871FC7E24F81ULL, 
            0x34EA783FAC8957DAULL, 0x61550C1A65E05E64ULL, 0x659D4C1824BDB7CCULL, 0x6381B3862D70FDDEULL, 
            0x8E052C7B26792B6BULL, 0x6C2C7FEFFD4A092BULL, 0x4D42647AF95BB7E5ULL, 0x89A59AB769557A4BULL, 
            0xDB4B08D3EA833733ULL, 0x0FACCE1042AE66CDULL, 0x6CEDFE2187F2C7BDULL, 0xEFAE7214F4577EF1ULL
        }
    },
    {
        {
            0x1D92769A84038FD0ULL, 0x5867A4D1FA29FB38ULL, 0x25EF3DE8D969C9D0ULL, 0x405B8BC3908409AFULL, 
            0x9812F9CC370058F1ULL, 0x9874EB15C0B1A86BULL, 0x6EDAEC3AA4973731ULL, 0x37C929A10508ADD2ULL, 
            0x6770CA9884D35B5AULL, 0x929EF03CB2850E83ULL, 0xA5D4F9DC09FB6F8EULL, 0x959C06EEFD3DF0F1ULL, 
            0xC3B3B71D2B03C3B8ULL, 0x2D20F3798CE7FE15ULL, 0x50889050DB7D3EDFULL, 0x51580CAC6AEB09BAULL, 
            0xBE65C4B8FF8259A9ULL, 0x8159F3F0BF34BA03ULL, 0x2DFC9443170B8CF1ULL, 0x37A4F9A92770C4A2ULL, 
            0xF04FE0BBB367F527ULL, 0xFF04209DCF450F9EULL, 0x1E3FF64C7F36632AULL, 0x5587F0EE619B0FFEULL, 
            0xF6E67743F0AC08C4ULL, 0xE3490CF15BC89FD5ULL, 0x7BD0E1C620169E2BULL, 0x5CBAF7F2C5704EB3ULL, 
            0x483080776639C24DULL, 0x210C5CB8F099EACFULL, 0xC607ADA8A4E5F97EULL, 0x7C3AA316420436C2ULL
        },
        {
            0xA9BDF107E97D6E52ULL, 0xB7DB8059C9C363B2ULL, 0x70308625350A703DULL, 0x8F0A83E107E64BABULL, 
            0x44F004F2DC8390F4ULL, 0x1F71125ED9D94302ULL, 0xB91AF1F2B6E3C40EULL, 0x6581495C30921159ULL, 
            0x84B5DE837768CCCDULL, 0xA76AB642368B61C7ULL, 0xF7FC1B5EDBE0BBB9ULL, 0x870D410EAC071051ULL, 
            0x6FAC8D76847CFD5AULL, 0x9E9C32CB203537F5ULL, 0x9930B58FA2A78907ULL, 0xBA52F61B9C18E601ULL, 
            0xBA5382660DD340ABULL, 0xDDCC759C0CE7B631ULL, 0xEA8BC1428132EC4CULL, 0x692CF8BCEB4FBE02ULL, 
            0x6841E6F5F959627AULL, 0x1A8DE4ADBBEC0829ULL, 0xD9C69B3CE3854A8EULL, 0xFE1FDACDE454DC34ULL, 
            0xAA907D0F398C2E9EULL, 0x442F00A324853BA6ULL, 0xF4EEDBBE81FB186BULL, 0xDC7BB7C15B7E2FCDULL, 
            0x73F65AA9FDE165E0ULL, 0x4F730730662431A5ULL, 0xD9DDDE16E29AA688ULL, 0x29B8E5F196A796DCULL
        },
        {
            0x868392F8824C2F2AULL, 0xF46EEFC35CF020CDULL, 0xCA2C8D6360597D77ULL, 0xC8A0D9919E77DAC6ULL, 
            0x89B0780ED91FB24CULL, 0xBBF4B091AAC2CD43ULL, 0x4CFA656C6BA61338ULL, 0x851671CA48DCECBDULL, 
            0x36618F4E19190793ULL, 0xFE70939BD683601CULL, 0x13B5E509ED6F9CB5ULL, 0x8D1EFD3A7FB87090ULL, 
            0x01784E26BB28F7D3ULL, 0xCD93FF1043962D26ULL, 0x0AB0D87D508D7E07ULL, 0x2C7FB536D41545F2ULL, 
            0x0A741B6ECC91413DULL, 0x0747AC340FB3B125ULL, 0x8272F9A0C0851140ULL, 0x0AAF8E12938B8E3DULL, 
            0xDF1919D78DA144DFULL, 0x85A39C4E725F30CAULL, 0x4CF82C7C011475CCULL, 0x766BD5AC872228D0ULL, 
            0xF1B14A17E975C5F4ULL, 0x742A4FEA159AE773ULL, 0x464EC271E0FA0497ULL, 0x952D7884C833D931ULL, 
            0x88A0351FEF9A0019ULL, 0xD8BC9AAA80A6E6C3ULL, 0x5647977857877176ULL, 0x123B7F89A2159B00ULL
        },
        {
            0xB46CC41721415FA3ULL, 0x23A1C9B65C62E73BULL, 0xE5AFC898443E8A57ULL, 0x30461623384649F7ULL, 
            0x51BB610C4ED45082ULL, 0x12E9FF9A9C29773DULL, 0x43C225B0653A33A2ULL, 0xF58E7F4A39D0BAE5ULL, 
            0xD85EA86B72FC3E64ULL, 0x7E157EFCB244AAEEULL, 0x37D520D786550517ULL, 0x1880FBD9E71595EEULL, 
            0x8ED42556922F96DFULL, 0x6F47209C94881665ULL, 0x1D58C98AC924D5C0ULL, 0xDDE8690B5A53A515ULL, 
            0x258FD367B5B0F80CULL, 0xCBCF06C43607549EULL, 0x97E4CBE6923CA887ULL, 0x07DA779681624D18ULL, 
            0xC48F7BBC4BAB8358ULL, 0x70F90C088EC7DB71ULL, 0xCBB7D5CF142D9B46ULL, 0xDC507229AADA7C8CULL, 
            0xF2AE1030C4EA4518ULL, 0xB7A3E9BBA5F811AEULL, 0x469046019AAAB68CULL, 0xB2A21941B9DACB24ULL, 
            0xB83B85D792C5742CULL, 0x00E9AA8D33EB0581ULL, 0x0029B0F878D884D8ULL, 0xB485646CF55005C4ULL
        },
        {
            0x37BFC3E292DEB633ULL, 0x6BF294EA4D6F1D0CULL, 0x67AE71FADF8C3D56ULL, 0x51E4B92A5B6294B9ULL, 
            0x3B191522015F1C3EULL, 0x14ED092CEF1BB4C3ULL, 0xFFC4D9E85DAA8F4AULL, 0x815ADA9329458103ULL, 
            0x666F08529A577F91ULL, 0x07409534865BC9D8ULL, 0x18E919ADCBEFDCBDULL, 0xB6D2E854036095D3ULL, 
            0x4CAD9A4F346274DBULL, 0xCD430DCCE4FE8384ULL, 0x86403BFBD24E2CB0ULL, 0x40C22C640D604863ULL, 
            0x2D93638CDFB441BBULL, 0x4F24F93A355F830DULL, 0x0047DF371D4E8694ULL, 0xF7F6E58DA5555044ULL, 
            0x11648A5C7D45F44DULL, 0xB018A7BB55F17F88ULL, 0x151EF0FC81194E96ULL, 0x3573568A2BC80644ULL, 
            0xDCDF2C9F2AAEF629ULL, 0xDAAA3F85EA81C1E6ULL, 0x5363417E947AE30DULL, 0xC0F66ADE06112001ULL, 
            0x27BDEFC70C8B0CA1ULL, 0xE3F001B7209C7490ULL, 0x5F7EE76D19543783ULL, 0x3F5C2287027CE66DULL
        },
        {
            0x46DD860FC52C4B81ULL, 0xE5890E2E47E19DAAULL, 0x84C63C62ED7815BAULL, 0x4308D2A9D316A992ULL, 
            0x4C0145F228AC9638ULL, 0x934A8021691AA11FULL, 0xBB103D42AD06402EULL, 0x5293DEAC148C1C7FULL, 
            0xEB6B7354B0E41A8EULL, 0x33F32149108A794AULL, 0x3B48E12CE0F33B2FULL, 0x889DF72356C188E2ULL, 
            0x74F2E677D9CAC945ULL, 0x5A7B8B930A442845ULL, 0xA2E5AC62F4393870ULL, 0x0F60F7017A29B213ULL, 
            0x849BE5B83DEBE92EULL, 0xE97E14BED8E33074ULL, 0xB2758B41BA0D9483ULL, 0xF7490F608FDBE1FCULL, 
            0xDCFC0946C9001BD5ULL, 0xFEA696462BD2BCF1ULL, 0xA88565562D38AB3EULL, 0x6CD28AFA69188533ULL, 
            0xB6122646A0282845ULL, 0x97E046BBA06BC64DULL, 0x9BB13B943D9DCD43ULL, 0x031B5B4697D254FBULL, 
            0x9B462D4EF27E9131ULL, 0x74F42B4BC8B23808ULL, 0x4E5B78F979ED46B6ULL, 0x9188562374C6C971ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseAConstants = {
    0x4D38A0C2BA8A038BULL,
    0x7648F3BF985F3A3CULL,
    0x6FB5C6CB6B49F3D1ULL,
    0x4D38A0C2BA8A038BULL,
    0x7648F3BF985F3A3CULL,
    0x6FB5C6CB6B49F3D1ULL,
    0x8E49551F37E27299ULL,
    0x201A366EFF3926FCULL,
    0x3F,
    0x78,
    0x7E,
    0x5A,
    0x17,
    0xFA,
    0xB1,
    0xB3
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseBSalts = {
    {
        {
            0x7459D3D848EEAAACULL, 0x1E70AC78DF706CAFULL, 0xA2F31B30426CC1CEULL, 0xA0B227F01389744FULL, 
            0x10A94E3A24A0605AULL, 0x51DE92661D568D82ULL, 0x5C5911AE63B69B79ULL, 0x8E0ADA5F60CE2EADULL, 
            0xCF0CA757D6AE1F5CULL, 0x8E923621F3965FDEULL, 0x16CA4D57DCFF834AULL, 0xA6B5CBEA0D2650B5ULL, 
            0xF42E03BC5EDDDC5DULL, 0x65A948318B15A456ULL, 0xDF77EBB212E8D556ULL, 0xA88C8964463E5F28ULL, 
            0xD6F183B9EBCE7EFCULL, 0x9D9E04350D64D528ULL, 0x6ACF9195770854F2ULL, 0x3C2A6E3DB6E59743ULL, 
            0xCB56E94E9BA366D8ULL, 0x610AD756265A5784ULL, 0x19DAB71B67F05B1EULL, 0x795342DD891BA6A8ULL, 
            0x0ED37F49F6F27F9CULL, 0x9DE2F6F81D94ADFCULL, 0xF94A3F42AA1CE45AULL, 0x6692C915D01A2017ULL, 
            0x04F290C02347F8BFULL, 0x85C8019A52028398ULL, 0x651CBF56C699D4B0ULL, 0x0C02EF10264D3677ULL
        },
        {
            0x2C93A541686B0A65ULL, 0x601724F5D962C30EULL, 0x695508F31F0BBA42ULL, 0xCD7FEDF918C8359EULL, 
            0x4364DEDDC0171808ULL, 0xD482FF6FCB218877ULL, 0x852BF62303DCACD5ULL, 0xD43D5E02134FA11FULL, 
            0x9A57C2092B3502D2ULL, 0x249726F64BD223D3ULL, 0x6FAE552A7D53B129ULL, 0x3AEB382948171FA7ULL, 
            0xFF02D322128E940EULL, 0x34578DCA267B7EA6ULL, 0x1BFFD7572A6CAEF3ULL, 0x63277C43BBA8BE0CULL, 
            0x1EDE9AB5A20F09CAULL, 0x755AE2998C723B24ULL, 0x5AC6BCD45F923653ULL, 0xA0621D21EF30B29CULL, 
            0xA6F4BA6B26489D92ULL, 0x888EFA71FC020FACULL, 0x6A26D950D20E27ACULL, 0x894A9604B948FB1FULL, 
            0x8C0A97BDEAE85B75ULL, 0x0F72042C8D8AB363ULL, 0x4308BED089012E9EULL, 0x027689D0C930C32DULL, 
            0x29B59B703907EF1DULL, 0xC17A015B7A93CD14ULL, 0x69B63A7C72C2210AULL, 0xB580E29099DF34E7ULL
        },
        {
            0x614242DCFA5C719CULL, 0x95E20DD1B7FBFA0DULL, 0xB4E5A5706A0EECD2ULL, 0x22A5C289DF09AA7DULL, 
            0xEAA30C321B99393BULL, 0x2582EDE48699D037ULL, 0x946AA3284DA6EBB4ULL, 0x74D03F2337532690ULL, 
            0xA1CC5DA7A971DE5DULL, 0xE2E93E6037FBCA24ULL, 0x1AEEE826E3389649ULL, 0x7ACCC4685C3A8F29ULL, 
            0xB3D0F708A2EB5023ULL, 0x9E167A8E8253309BULL, 0x4CF644CF532E1EB5ULL, 0xA031ACF45D8E4E21ULL, 
            0x1144E3806E57AB9CULL, 0x31AC1652073EB9CFULL, 0x392CE57D83C69061ULL, 0x404B31692AC30373ULL, 
            0x982B62A86A964549ULL, 0x2F412E91EAB1E306ULL, 0x7863FB7C22FF1768ULL, 0xD898A2886F988809ULL, 
            0xDAA83539A58F8141ULL, 0x7BF67BA52413F731ULL, 0x94663AD737A631A4ULL, 0xF74310749A8714CAULL, 
            0x6DEC6B6A843A6D13ULL, 0x5D60CBDD1F663144ULL, 0xDEB7CFAFB3FBAE47ULL, 0x8A637B7A4A618066ULL
        },
        {
            0x3CBC080DAE1B6943ULL, 0x9182500DFD3349BFULL, 0x48DFBE93A94D0FDEULL, 0xB464D3BB1B404AD4ULL, 
            0xD150266262DFE6D9ULL, 0xEAE63E815D2B6869ULL, 0x897B2FA6C7411C9DULL, 0xB7F811AB9DD67BFBULL, 
            0xA46E5BC51BEDD70EULL, 0x86EFC6E9E637CF8AULL, 0x0067003EBDA0D627ULL, 0xD313C14905D3E540ULL, 
            0xFACD7FD4516A705FULL, 0x72F395DE91C82A70ULL, 0xBB543B3133DB661DULL, 0x1938D07201744AB4ULL, 
            0xCD762F9DFDFC23B9ULL, 0xF31ADA7E62230491ULL, 0xCBDA0C53D0CF0F98ULL, 0x59BE8AD7056D0C48ULL, 
            0x6B0A1D48DA296EB5ULL, 0x7D0A7C9D12553935ULL, 0x14BF29691C5E414DULL, 0x143CC323C1F95096ULL, 
            0x0971EFCED4AA759DULL, 0x5B1C24FD471D5F6BULL, 0x120D7D170F729A15ULL, 0xE418C1087DCD42E9ULL, 
            0x9AEF2A4325719DF3ULL, 0x71D6FE48FE7E372DULL, 0x6F6D30F277454AEBULL, 0x4FD498E7516C4637ULL
        },
        {
            0x694B89A675EF462AULL, 0x8F3105BD187A5A62ULL, 0x3AA8592C3AA1EB29ULL, 0xEDE78175CAE819E0ULL, 
            0xE2C8D3609592B5E9ULL, 0x9E6D4A63DDA3CB1AULL, 0x312A1157822FD397ULL, 0x024DB711D1CCDEDAULL, 
            0xC27960154CA42905ULL, 0x12E91C65A0A840ABULL, 0xD36720D74FE90451ULL, 0x14BCD7F9065476B3ULL, 
            0x140D303EBFA18932ULL, 0x76F85593D5080C2CULL, 0x8C25B76247C63105ULL, 0xF420C17472BDE3BEULL, 
            0xEF5416393904B1EDULL, 0xECB054E286AA5B30ULL, 0x5C7E5373CAFF06FFULL, 0x132ECAAF6A3B9ED8ULL, 
            0x740F587D0C3EA2F2ULL, 0xAFB6237A02709F31ULL, 0xB8F0B8A1809B19C9ULL, 0x59CD99DD6065D3BCULL, 
            0xBE7FC869D3F25AFBULL, 0xDA1A29803DECD402ULL, 0x9F84F5360C1D85BEULL, 0x26C632C162C99825ULL, 
            0x94E6162C2D4F7932ULL, 0xE8B111A7035C6C15ULL, 0x1984AB7E0C8ACEAEULL, 0xE563C9E26498F252ULL
        },
        {
            0x58E062A7D68F7A4BULL, 0x60050A578045898BULL, 0xE28D6583DB26E5C5ULL, 0x3ACF34DF72EA5FA4ULL, 
            0x479D69051CDF6B48ULL, 0x19918AFB959F6998ULL, 0xC59EC8B8AEA112FAULL, 0xA518A4AC4099AD01ULL, 
            0xCBADD13B0AA40F3AULL, 0xA899C032BC5D944AULL, 0x1F0E97DECFDDCAB9ULL, 0x0856B694AC7DB378ULL, 
            0x77520AF9DA05AB8BULL, 0x7D93212599A513DFULL, 0x906A78B6CA404B12ULL, 0xB43F27B169F0236FULL, 
            0x55FC70F1FE0D5E60ULL, 0x81C2B37C6E9D92A8ULL, 0x5F4851E075915289ULL, 0xF43DBAD361A29ABCULL, 
            0x48503BB9FC6C735CULL, 0x7C164E8B41613682ULL, 0x6934B2B6A5B1A67FULL, 0x0BAC19A08EB349B6ULL, 
            0x43175241BE82782CULL, 0x3F176B1B31C017CBULL, 0x146D1B9B35147920ULL, 0xFDE9F9632280DC69ULL, 
            0x0C2CBDEFF2A4D97DULL, 0x54135A7731CED570ULL, 0x8698D3553D4D4C56ULL, 0xBBA7E88EEEBCBBFCULL
        }
    },
    {
        {
            0xD4F7AEF1D9556ECEULL, 0xE8878CA6F20134AEULL, 0x46D1E10C2EB76EF5ULL, 0x823A88156A9C57CFULL, 
            0xE0D9ABF7932A78F2ULL, 0x9EE8D86125860256ULL, 0x0ED3AA15134751F0ULL, 0xFEFA8C1AAA9BC9F3ULL, 
            0xC104726920994C69ULL, 0x7A0C7DC06C71671AULL, 0x1AB76CE38E6E98DAULL, 0x7DF37BF22E50B23CULL, 
            0xD1EECED0480B4880ULL, 0x68B37FC7803E0081ULL, 0x4E69CE43A0E162A5ULL, 0xD0FD45CB6AE49116ULL, 
            0x2703FDCBC3CC49AFULL, 0xA577BD956DEDD001ULL, 0x1423B5034D203F3DULL, 0xFE1B962ABCB1BC73ULL, 
            0xDCD3E0A25E19C58EULL, 0x8BC0EFC0C14E4139ULL, 0xEF84693DF42D52E2ULL, 0x2FA4CEF769014C86ULL, 
            0x8C842B404CA36D66ULL, 0xDB91D9031668A5E1ULL, 0x2ACB65AA31D26D02ULL, 0x92DC894F4F6D3923ULL, 
            0xCDED75946EEF86C1ULL, 0x22F0E724C4D57DD0ULL, 0xD41C1FB60CFD8BBFULL, 0xC8B79622A5DC2C1EULL
        },
        {
            0x86429B3CD654290AULL, 0x2BB3F320732218C6ULL, 0xD529CE78574BFB36ULL, 0xD3F30AC38099EE58ULL, 
            0x563CBE7CBCA686FFULL, 0xEAD6110B0D38B5A7ULL, 0x91F4A4B7F5FF279CULL, 0xFF7B55370E86D9F1ULL, 
            0x363096F9C1EF677FULL, 0x6E9271F9889A9DD3ULL, 0x4B46A6DAEFBC3539ULL, 0xDAA8B570BE3D4843ULL, 
            0x33F7A47160C5ADEEULL, 0x12BCAF7591D7E089ULL, 0x9BAC23B48FF84D26ULL, 0xD7DB1F1A91D7BB12ULL, 
            0x2D4BC16738E98B5BULL, 0x56CF3CBEFA777592ULL, 0x466A46679D9408B5ULL, 0xAFBE29C9FE1E7A6AULL, 
            0xDD139152FC269B0FULL, 0x058FE2883E0D53BAULL, 0x344B4CD754FFA3AAULL, 0x66493EE6068A9968ULL, 
            0xE59241E65CC857A2ULL, 0x848A165C9A1B7E34ULL, 0xF4D88E049325B582ULL, 0xDAE9EA3C106D236AULL, 
            0xFD66242E3579ED9FULL, 0xB6A515DF9A8A9214ULL, 0x7EF3968ABAFADCF7ULL, 0xFA62E292EDF1D972ULL
        },
        {
            0x87D3257460815A7BULL, 0x42C626F87688CBA6ULL, 0xE97F0DDE2E94D4F5ULL, 0x6135EA90300CB64FULL, 
            0x48F56E161E37473CULL, 0x059AC72BEB462A0FULL, 0xFD2474192A4FE225ULL, 0x20E464D25B2E4521ULL, 
            0xF7C7238B7FC86979ULL, 0xE05C14958ABAD617ULL, 0x62EEA5D38BD5AA9CULL, 0x4309EE94BC96217EULL, 
            0xD27700B0B129162DULL, 0xC2D4495C058C904DULL, 0x921F84A3BE5CFC49ULL, 0x5BA9D651B140CCD2ULL, 
            0x33CC1BB2491278A7ULL, 0x4D0E2AF012BA633AULL, 0x148EF0895265DD37ULL, 0xA920E28B77E1F59FULL, 
            0xA3AAE7DFBAD80613ULL, 0xEA16E1041BE39A08ULL, 0xC0D4BC9F5C79D9B6ULL, 0x73530AE5A6495E88ULL, 
            0xB528034474C445FAULL, 0xD16E6504ECC461B6ULL, 0xDBFFDB4A5835BB06ULL, 0xC588635509A7FDD2ULL, 
            0x4E0033C59484E588ULL, 0xCD33708215D240F8ULL, 0x80735063F438E65BULL, 0x42207C8B38D58D86ULL
        },
        {
            0xF36EAF702543A8B5ULL, 0xD201C847D9F51F0DULL, 0x87BA818D522D5D7FULL, 0x24C03998D37C7C7BULL, 
            0xDE020346BD492C48ULL, 0xFE7A13A1C78465BDULL, 0x20837E90ECD0ECDAULL, 0x6E9A5A6A96458561ULL, 
            0xCDD25CE34FA5D666ULL, 0x28ACC100502C7A96ULL, 0x488ADC418BCDE951ULL, 0xF89EE7C265FCDF33ULL, 
            0x0D1EEDA9FFB94D71ULL, 0xB7910FE59562E823ULL, 0x3B639E1F6319176BULL, 0x13F39022054949E5ULL, 
            0x0E17313F02B6DB13ULL, 0xB037BC1BBEBE7311ULL, 0xB7FAE59C4AD6F4B2ULL, 0x84D0B3F3880EDB94ULL, 
            0x0A953FB05B2BCEADULL, 0x86DC19F8A885C3FFULL, 0xF12D2F15215C16ECULL, 0xE39C089D338C2E1AULL, 
            0xE087B201C6C8E1B0ULL, 0x0C7B6BBF9112E6B3ULL, 0x18B2F6AA630729EEULL, 0x755CCF14D5F32856ULL, 
            0xE18CAACF28411C77ULL, 0x521D474936CBD209ULL, 0xD441F1A251C3B9C7ULL, 0x7A2C7DDE17DC62F9ULL
        },
        {
            0xE11EAE8D214D76A9ULL, 0xE7C409C784BC9C4DULL, 0x18852F5D72D03270ULL, 0x27262FE4BFEDE7D5ULL, 
            0x45ED833825737A42ULL, 0x90DE94F63F644350ULL, 0x23569439A8283B7CULL, 0xF73392DC077584B0ULL, 
            0x855CB98905265562ULL, 0x7109274281ECC738ULL, 0x56E41D43913712DBULL, 0x324897DB1E85FBB7ULL, 
            0xBC82EAB2A4D73EF8ULL, 0x88855B2FB61B59E2ULL, 0x8BBD7F9FA3ECB557ULL, 0x16F11820609B8A2FULL, 
            0x16A9201B00496257ULL, 0x174F6DA9E604A15CULL, 0x3DCFAD1A6776F38DULL, 0xD4C85EF33EE2DFDAULL, 
            0x31BE4AAF07ACE7A9ULL, 0x1955895423DD50ABULL, 0xDA68A84388DD72D5ULL, 0xABB42C2A5B62BB1BULL, 
            0x325FCA1E218D7C8BULL, 0xF4E35FABDAD9A7F7ULL, 0xB53829FF055299DFULL, 0xF7DE5F81440005CFULL, 
            0xAC38C8F87A4CA8C1ULL, 0xB24BBA9D645C7DC9ULL, 0xE199482117E18D16ULL, 0x39FED50A973A08E7ULL
        },
        {
            0xEF2573BA07B2B276ULL, 0xC773E784EA6264E9ULL, 0x3E76C69458C4ED02ULL, 0x4D4E5E28689AEFEFULL, 
            0xE279DA14E01DDBDCULL, 0xBD421D65C8D3F7F6ULL, 0xB1D3ED17C181F896ULL, 0x712FF9C7D7788740ULL, 
            0x7032FC022116BABAULL, 0x926728DC688E87D0ULL, 0xFFC25C1AEC58A0CEULL, 0xDB08046855B63DE9ULL, 
            0x86257EF5CA394611ULL, 0x03D46FC2537647F3ULL, 0x6F0BAB29B2146147ULL, 0x18AE72214DC3E436ULL, 
            0x78E78E65CFE06DBCULL, 0xAAB390F6264B81D8ULL, 0x47FCD2817307D15FULL, 0xB94E6BD59EB3EE6EULL, 
            0xF0732E87DA142F83ULL, 0xF144DDC4625E50F5ULL, 0xB78916F794C4B081ULL, 0xA7058247FBAD53A1ULL, 
            0x977FDF63A9C24EACULL, 0x3299365DA1A77A96ULL, 0x67E85D767E18867AULL, 0x8AEF4CB348D7A862ULL, 
            0xBC0F82A30843C113ULL, 0xC35DFE4ADF4CA882ULL, 0x33D9B0EEDD71BD68ULL, 0xE7505D0C144C0962ULL
        }
    },
    {
        {
            0x9160A64A2B3BCDA9ULL, 0xEB3F300969AB1123ULL, 0x34E1DB0472E38E78ULL, 0x47E33FD32F7E3B6AULL, 
            0xB1F8A3FF2DBA1F97ULL, 0x78BB557100227AA4ULL, 0x4DC9A1E00BFB5F0EULL, 0x467D545EF3B11AEFULL, 
            0x9EF63EE12318FF18ULL, 0xEDA585264DE352FEULL, 0x413663936E3787B6ULL, 0x046122C596914D37ULL, 
            0x398C19FBA490935CULL, 0xF4353696D62D0E0BULL, 0x44DA97E4BD0F745AULL, 0x7D272C65F4092281ULL, 
            0x86C592CADB91F2C2ULL, 0xD6FF02869D2EC3B4ULL, 0x4A17784BF9BA03EDULL, 0xB9FFB68B563F4398ULL, 
            0xD2DAF43FAC382CC8ULL, 0xD129B178D6E3A825ULL, 0x925C58A7DE89142DULL, 0xBE73D80186569AC4ULL, 
            0x3D2E0E30AFEF16D8ULL, 0x46FA7D295C098772ULL, 0x2EB341923B067E43ULL, 0x6E971734C5AC43D4ULL, 
            0x01CEFC51015D8AEEULL, 0x35CCCA04A807EE2CULL, 0x610AEBAED1949866ULL, 0xF76C3807EF52D381ULL
        },
        {
            0xC7117E43C791B581ULL, 0x26DB9550165F42BDULL, 0x4865018837DBC83CULL, 0xFD7058CB4D255F49ULL, 
            0x2D043381332F7D5BULL, 0x3CDF5C601E3A7838ULL, 0xC4B3905168BBC253ULL, 0x3B6A8D98794D2D14ULL, 
            0x7A2E1AF2A6DB1C9BULL, 0xC3E451C411AD73A8ULL, 0x3824AF40E4C95E54ULL, 0x000BDEF5BB7AADACULL, 
            0xA0B64A0E89AD4E2DULL, 0x8306A360AAAC7876ULL, 0xABBA749D48BBD620ULL, 0xE3FF047968671AA3ULL, 
            0x57268F87EE5AB867ULL, 0xDBBFB1E99410202CULL, 0x1779AA045184632AULL, 0xA3DB93EBD16BF5DBULL, 
            0x82304FBB8F66E3B4ULL, 0xCF2A9E073D575F4AULL, 0x7BC24D17360F12BDULL, 0x5403EA20BB168603ULL, 
            0xC7C6A36F946E7B9DULL, 0xC412FE43A4E67A19ULL, 0x786F796BEEC25D9FULL, 0x49C481C21BC735E5ULL, 
            0xEE84F9A01128960CULL, 0x2345A904810FD9A5ULL, 0x519C1BF52DB63FD2ULL, 0x8A4BF5101990206FULL
        },
        {
            0x415EA06218D63626ULL, 0x1FD3504B4DA2C158ULL, 0xB27A5369161C8F08ULL, 0x47F37255098E7706ULL, 
            0x54759BCA91CACA82ULL, 0x0B657C4E2DDBDAD3ULL, 0xE32C29FDF0750286ULL, 0xD31BC310CEB6B8F4ULL, 
            0xABDC21CDB0191A14ULL, 0x869A06767AF3DFE5ULL, 0x9763EAD055FB60ADULL, 0x66BB7076CB864F03ULL, 
            0x81E90885C09986EFULL, 0xD2012FB73C4A07D9ULL, 0xD214CF6D96309662ULL, 0xA2D09841B88CF586ULL, 
            0x211FEA37BD7044CAULL, 0x481D005E0BE3D249ULL, 0x810F856EC8A15139ULL, 0x13BEC6437F1198A5ULL, 
            0x10A6E5074CCCCD16ULL, 0xB33F5307BBBEA277ULL, 0x8F9AFF5C4C3AE3DAULL, 0xA1B5A33DF5D38EEBULL, 
            0xA8E1DA26049EF659ULL, 0xF480296BB4EB7979ULL, 0x2371DB6AD383B650ULL, 0xE72DCFD0A918A75FULL, 
            0x089E6E6DF13656B6ULL, 0x0D4E312C1B136885ULL, 0x31A8BA1B885279BCULL, 0x478B76475959AA8AULL
        },
        {
            0x00543AEB77B053D5ULL, 0xA83DD2F04742A88DULL, 0xEBFF788EA8279713ULL, 0x1E8BF42D7DD736ABULL, 
            0x8E0C8F13DB3DB1BFULL, 0xCEF18A3A6160BAB3ULL, 0xADCF5E4604D97967ULL, 0x25CF6AD81BC99E85ULL, 
            0xBDBA8F10BCC6EF67ULL, 0x8C59C1F1B539B84CULL, 0x1B278B3C9779CA53ULL, 0x2DE6D15B5EBA42BFULL, 
            0x7A3E54CF5EA9508AULL, 0x0F2FBF98B9F46D47ULL, 0x663E32CDDBC12CCDULL, 0xE5DC5556A6FB7A6BULL, 
            0xF083FCBD586CB3ECULL, 0x45C22AC0401D5034ULL, 0x94CA1B7B57743961ULL, 0x68F7A7CDE581545CULL, 
            0x1186E03968CA1736ULL, 0x07B7D5C4DF63FF09ULL, 0x426CB759435640B5ULL, 0xDB5355F4FFD20E87ULL, 
            0x78CB38420A1558B5ULL, 0x95AD8F898E921F8DULL, 0x7C991F6EF899EA7AULL, 0x60A1B06D9BBF66D6ULL, 
            0x709C2B61EE52CE56ULL, 0x8850928E3BEFF7E9ULL, 0xB8B1BE1B0C48A578ULL, 0x0915E78F69A2EAEBULL
        },
        {
            0x9B6E2257B5D49D96ULL, 0x751736166F74235DULL, 0x78CA7B4E319A20A4ULL, 0x7151A1164A0660CCULL, 
            0x0D568FAACA95BE2DULL, 0x8DC7E2EC03F81E5FULL, 0xF87F36BF25A9486BULL, 0xBB5914BECD79C088ULL, 
            0xED3006BF78335FDAULL, 0x8985956AC6A97838ULL, 0x657B4F0BE2007E67ULL, 0x06A0AD54E2EC1D17ULL, 
            0xBBE1911757708C9BULL, 0x4C14240EEDAC0CDFULL, 0x2FDFAF2979641629ULL, 0x88A4B2F67DEB9B1BULL, 
            0x70B67A5522167F58ULL, 0x3248144D17260F89ULL, 0x1306F32CB708FAC6ULL, 0x7EA411B062092698ULL, 
            0xA1F6FE8D4DB4C71FULL, 0xDD170819FF727FE0ULL, 0xBB8FB2C6517CF684ULL, 0xF851819DA453FEFEULL, 
            0x77A8A164FDE90C1FULL, 0xB322DF0CE366EAFDULL, 0xE99549E4F1811099ULL, 0x34D21A4E1328D29EULL, 
            0x8CD930626AEB1EEBULL, 0xE5159323D08BD8B9ULL, 0x894151265C999421ULL, 0xC5AA0764322AEF0EULL
        },
        {
            0x612E9AF95774D520ULL, 0x8CBDE55AB1431550ULL, 0xEE97B1323D4E4503ULL, 0x25AF1121A2D02AC8ULL, 
            0x0E1F0C7C4DBED679ULL, 0x4EBF2FA0A3F78070ULL, 0x69C2CEE843B99AE5ULL, 0x216FE983198617D5ULL, 
            0xD093913C527490DFULL, 0xFDB7BD74659332E0ULL, 0x1E5BF0B4016B6A35ULL, 0x7AA130357C7A5FD2ULL, 
            0x44F9D1252FB03C22ULL, 0x3B4CAF3BFF43D78AULL, 0x02658260B42C8E7AULL, 0x70F15A2910653338ULL, 
            0x1CF5CE4AAFDE462BULL, 0x64066A3AA6387761ULL, 0x9C40E02E2D9B487DULL, 0x373241F596AC778CULL, 
            0x85BFBF6A5F642F33ULL, 0x9A01B57C65249C56ULL, 0x0280156CE6276982ULL, 0x96A47772705FB784ULL, 
            0x4D2DDB535A768153ULL, 0x9B99F6EF59B83473ULL, 0x9B04ED8AC4BF74FFULL, 0x26D79A7D258E2EF4ULL, 
            0x2E6A4025852578F0ULL, 0xE2327C6C40F65723ULL, 0xA76BA3F44DCE6963ULL, 0xC5EE4E85ADA63761ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseBConstants = {
    0xED30972F3C8CED70ULL,
    0xA5329C9690B71B33ULL,
    0x3298818ED6564240ULL,
    0xED30972F3C8CED70ULL,
    0xA5329C9690B71B33ULL,
    0x3298818ED6564240ULL,
    0xF83ABA69FBC266D1ULL,
    0x84A43EE03549E21FULL,
    0xB8,
    0x7C,
    0xB2,
    0x61,
    0x97,
    0xEB,
    0xFC,
    0x27
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseCSalts = {
    {
        {
            0x43C9810E919EAAC1ULL, 0x3DAAEE5FEE5F1F0DULL, 0xB0BC58BB914B2A36ULL, 0xE151F2309646895CULL, 
            0xB1BE2A01C9B4864CULL, 0xDB7EDB131E333926ULL, 0x3373544E0CFB83ABULL, 0x34333B183E11AB39ULL, 
            0xAB64EA3D69FA91A1ULL, 0x368DE958F9EDCD3EULL, 0x2EAFBCB54C25B921ULL, 0xC0AE54C26478A6C5ULL, 
            0x091CA14F45B17585ULL, 0xA6E9BC418233750BULL, 0x47BF1DC5CD017F32ULL, 0x5F14CCE41B803029ULL, 
            0x3F9715F5F8A72A1CULL, 0x52E4E290AF92D091ULL, 0x96595BCF65665F5DULL, 0x4C234D65FAA232F1ULL, 
            0x88462A94969E8E21ULL, 0x051D421250D3E4ADULL, 0x85F5D03E025D0338ULL, 0x2B4127D190A53FEEULL, 
            0xCB8A981BF025EAE3ULL, 0x3036A4E60F2649A7ULL, 0xE9E21B0FDA683B17ULL, 0x09723266615ED155ULL, 
            0x5EC80F1E780F4E63ULL, 0x9F2D45726A583B20ULL, 0x4194AEB36582BACBULL, 0xD58D7B8E3A3D512CULL
        },
        {
            0x7DE0A8A917DD8DF6ULL, 0xF8A37855FA8417A7ULL, 0xFD572832A59B0F0DULL, 0x5DB1CBA7B7AAE35DULL, 
            0xF32C1CB54356811FULL, 0xEC01655494F59B8DULL, 0x8B984C3B328A3CF6ULL, 0xC5749CAACCBF2041ULL, 
            0xEDCF461882EED663ULL, 0x805C3CB3CCAD7222ULL, 0x1509D1C9ABBE2C75ULL, 0x112408332E2695A0ULL, 
            0x54EFCEA561327020ULL, 0xA24C4E8E9A06686EULL, 0x1629A127D47A1D71ULL, 0xE7D9B6D62E9E982BULL, 
            0x2C9DADBB9EE2875AULL, 0xB5DA908D76FBF7A8ULL, 0x6BC940966A681F72ULL, 0xEA3DA7DAD9A079D4ULL, 
            0x4BC443B7196029E6ULL, 0x3FC0DB0321343D06ULL, 0x438DA0629B6C986BULL, 0x2F20B2DA6385733BULL, 
            0x58D5A68929D7BDDAULL, 0x8E981B032411AEFAULL, 0x40EC395836EA8542ULL, 0x21AF379EF9BFD11EULL, 
            0x49E9C09804C3A761ULL, 0x764C45EC3A47FC15ULL, 0x328C58581DE12FBEULL, 0x8535A9F07643E65EULL
        },
        {
            0x885DEBA43811703EULL, 0x07FB1221D5D58ECFULL, 0x600454CC31C22914ULL, 0x6B8B910EE2D1C72EULL, 
            0xEB9129807839C26AULL, 0x51824A3FABEB958CULL, 0xF5C4572C101C5770ULL, 0x94756186AA953B0AULL, 
            0x238E392C8B6DFDF8ULL, 0x7ACD3C0B35CC1607ULL, 0x8E99FA3D68DCE225ULL, 0x33793470049135E3ULL, 
            0x00270A3B34D370A2ULL, 0x75771CFA513D3299ULL, 0xAC05E0E76AC56A50ULL, 0xA8FF49ACA9B4988FULL, 
            0xDBB7C49A5D651AF1ULL, 0x4130DC25AF4D4823ULL, 0x40374C854EB14C4DULL, 0xDCAFE6183980173AULL, 
            0xE36E4B5E436F9A76ULL, 0x96BF518A37D2E6C4ULL, 0x320E277F649376D2ULL, 0x3496F25268A7AC73ULL, 
            0x284F0F64979CC291ULL, 0xF0C87BA2FFF039A4ULL, 0x99C46547C2056F2EULL, 0x2036466A5FE31CC5ULL, 
            0x8886B9D24EB9A86EULL, 0x1443C7731D766E88ULL, 0x7D074ECCECA655B5ULL, 0x1EA030D8C8F4DCA4ULL
        },
        {
            0xB325E5F52C0B8C68ULL, 0x35613082A5F9FD2CULL, 0x854A19DDC2D60964ULL, 0xD65EA3D484794E5CULL, 
            0x90D03FAEA81B94F6ULL, 0xEF45B56B7FE90CCFULL, 0x5E6E3057630B6BD0ULL, 0x26E25C92F5593364ULL, 
            0x12CD36BC71BE268FULL, 0xC0F086E14659C424ULL, 0x9EE35F97DFA11168ULL, 0x537787075C02BCB1ULL, 
            0x97AA76928B602624ULL, 0xC5B5872F965E2FB9ULL, 0xDD11F8532B0AD873ULL, 0x9B68C1D028449745ULL, 
            0x7637B51891D53B17ULL, 0xF13543CF7A5F08B7ULL, 0xB2C9949E77D0D49FULL, 0x98327984D5DC4E99ULL, 
            0xEC4F3CFD83C064A2ULL, 0x28C1271B0BC405DBULL, 0xA2406C3BA68D940DULL, 0x9129C169D69C4062ULL, 
            0x5AA1BD5E41BCC8D2ULL, 0x0166A51B2959A69AULL, 0xA88CCB50D1BBB84DULL, 0xD93AA950249D0A54ULL, 
            0x43F69F9DA6CCFDEEULL, 0x8C15123CC8AB0C26ULL, 0x32E29F675730E18DULL, 0x2B2EC2D213EE8024ULL
        },
        {
            0x764AEBEEE656B2BAULL, 0x7AAAA37BF1E742A8ULL, 0xB4A635B6D7CC5FCDULL, 0x7905B935F8E67419ULL, 
            0x1046BD7C685DAC13ULL, 0x36508141F566CAC5ULL, 0x8DC7116AF409C437ULL, 0x3F030FB7A7D766BEULL, 
            0xD6A7F43A6DEB7BF8ULL, 0xC447E07A3EAAC3B6ULL, 0xE50C31EA4A31BA56ULL, 0xF5A56381C01FB02AULL, 
            0xA601FD10C764A747ULL, 0x67CFC3F0BCD809D3ULL, 0xB7869B91E9F4A2C7ULL, 0x6DB2779935C7C9FEULL, 
            0xDD4855106F1001A0ULL, 0x546750F008C6B2CAULL, 0xA4F4710559C222BBULL, 0x83AB6272FEB2E0CFULL, 
            0x2B0807ABD93F2A9AULL, 0x444F1102CED27140ULL, 0x11C059666DE331B6ULL, 0xAA25443D463F491DULL, 
            0xA2BACB8C6DE41286ULL, 0xFB969AF09E1B548FULL, 0x38956D5BBB2E7716ULL, 0xCEC1CF0523FE060FULL, 
            0x1C33DD13EBB04374ULL, 0xE84EEF24AFB483ACULL, 0x76C5FC0D36B635F6ULL, 0xEA8B424AD0505449ULL
        },
        {
            0x10DE9024547E362AULL, 0x932975F899B72C60ULL, 0x492DA5A24C490025ULL, 0xDE06C67CBDC7970BULL, 
            0xFB2999FB3B582562ULL, 0x4718A13026BE5309ULL, 0x71B64D6B74F54022ULL, 0xDCD484594B90CBFDULL, 
            0xF64BA2098214018BULL, 0x65DDC4B8163B93D7ULL, 0x4A5AE9AC78E8D125ULL, 0x66FC8F44EE83EF9CULL, 
            0x7FD13CBDD1401780ULL, 0x954682C1CE3D6954ULL, 0x8122DECF562466DAULL, 0x3480F8B4DD935777ULL, 
            0xA2010F5746029D2BULL, 0x48F5080F20A8F52DULL, 0x9A0DDED9D84B7749ULL, 0xA365F772D2DF79A8ULL, 
            0x3558B9E03B7452C9ULL, 0xBFC0B4350559EFD8ULL, 0x795D7ADC03B1B946ULL, 0xA18EC02A8247E46FULL, 
            0xCA9AC116475EED17ULL, 0x7B2F66F8C91D2E1FULL, 0x33DC395DCC585EE1ULL, 0x6669C71CCC206534ULL, 
            0xC5374626BF92E709ULL, 0x37931FEF50A5FDEAULL, 0x5C63E9453920C8FCULL, 0x39E9B1480E54364FULL
        }
    },
    {
        {
            0xD23F6E558E6226D5ULL, 0x000B0FE4F44A6220ULL, 0xE3B56C0B1024FBF6ULL, 0xCF43F847C15EF493ULL, 
            0x416FB2ADC0FD71FCULL, 0x689AA59E386108AAULL, 0xB178E2A43CABF5DDULL, 0x222BD4483CD70BE1ULL, 
            0xB315593CE44FEAB1ULL, 0xB181A7DB8DFBBB28ULL, 0xE3DE01ACC4BA4294ULL, 0x18545DA00A30869BULL, 
            0xA55CC105757471F7ULL, 0xAF1D1E8B7D3010FFULL, 0x5D754C5FC27C31E1ULL, 0x463072B06C3DFFBAULL, 
            0x1CFD2B71978E15E7ULL, 0x3E19FE6789CBD2B5ULL, 0xAF861F58D07F0409ULL, 0xCCBD2EC746FAEE04ULL, 
            0x226C4F406CBBD167ULL, 0xA6D864CF62C5AB43ULL, 0x74661C9C1F35D7CCULL, 0x3A77DA6FBB4CA313ULL, 
            0x1CF803E3A1504B16ULL, 0x7A4FE58B1DEC3167ULL, 0x19981945C9A6DDE4ULL, 0x00F3223B38E29713ULL, 
            0x902C05883A8A3698ULL, 0xF9720D669286BBF4ULL, 0x2CB5B76B6BA48D60ULL, 0x5E26A95C5185957EULL
        },
        {
            0xE89E9779EDC989B6ULL, 0x182E7B004EFD5E87ULL, 0xBB15EDF3D07CE4BDULL, 0x3C464E6F229265BEULL, 
            0xA2EB24807CE78CC4ULL, 0xF498C4BD117C9539ULL, 0xA020F68E4562D149ULL, 0x00C4B0DFFCD4BB12ULL, 
            0xE66426E331B4220CULL, 0xFD01372C1C06A3C8ULL, 0xE28786E79E9BBA6FULL, 0xF0811E4F7314528BULL, 
            0xAA773ACA700B94EFULL, 0x49CFF3B746D62DF7ULL, 0x044F4F42FC1679F0ULL, 0xF02C13A0DE0B36A1ULL, 
            0xBF63C729252670B3ULL, 0x5B084E09531C9866ULL, 0xDB5EC72F66EEFC2BULL, 0x9FE7D50939746F5CULL, 
            0x5B2FF3CAAB745C7BULL, 0xB8D9A94CCE47F8CCULL, 0x74E53CCDA4CF378AULL, 0xBDD35F48B5B78E4BULL, 
            0xA33D4455CF198871ULL, 0xCA0C20FF7148CDE4ULL, 0x30E4CCDCBC788FB4ULL, 0x40380EC2D109BB83ULL, 
            0xF92D2C3CDAAFD042ULL, 0xD42EA8C401B7BD81ULL, 0xBB5B20CE3D89047EULL, 0x04CBE419F06A3BC1ULL
        },
        {
            0x2A21BE0290A629C4ULL, 0xE5982FEEEB7F6257ULL, 0x21FE2C9E67D44ED0ULL, 0x81359BFF3270E9C0ULL, 
            0x58ADA3362A91446DULL, 0xD79284F6A7EB68DDULL, 0xBFD20D51C76D32E0ULL, 0x49AE37BE7A9EDEE5ULL, 
            0xCEB347F3DAD687C2ULL, 0x791960991FCA5257ULL, 0x7BEBF5944800A0FDULL, 0x5B5BFEBE696E2A22ULL, 
            0xD0569799C367E0A1ULL, 0x1565032055C0AC46ULL, 0x97FEBF16455EF84CULL, 0x79871E15F987DE06ULL, 
            0x8EBBEA5BBED29FBDULL, 0x5FE65BADCD13996CULL, 0x2513FA587D7065E7ULL, 0x9C82B6B1B12B1AE9ULL, 
            0x4E34DA54B7725748ULL, 0x216ECC6AFD8D20CBULL, 0x94A74FED80FC4283ULL, 0x66DC28E11871954FULL, 
            0x514263AFE035D361ULL, 0x316CA41646122B89ULL, 0x594768EA2DCDBC11ULL, 0x6BE049977B0ECAEBULL, 
            0xFD3230DF1B5B0A06ULL, 0x4E6E0666819527DAULL, 0x821A297E9B262200ULL, 0x72F1C7FB4573C9EDULL
        },
        {
            0x1699989657147A36ULL, 0x476023735EAF5725ULL, 0xB3310465C03EF4E7ULL, 0x60DBD7CDB4DD0CFEULL, 
            0x671FE9E01252273FULL, 0xB6DE7DC0EEF11CB8ULL, 0xCD627E3A85643D2AULL, 0x604F005FEB77E660ULL, 
            0x4CB4ED67E26427EAULL, 0xDB3339E55B37AB92ULL, 0x58F563B6F208DF06ULL, 0x65FB1FBB8B5CA6FEULL, 
            0xA75524499CCBE9E0ULL, 0xC338D8F9BBC80F1BULL, 0x4868B100AD4B0E6BULL, 0x38F5C67B8CAE0BD8ULL, 
            0x7C2C87D4F6F9DDD2ULL, 0x8CA5D79B2FC715D0ULL, 0x93E231D50C6A7349ULL, 0x1C0CBD77D237AC0BULL, 
            0x5A5BD928F6ACFF24ULL, 0x3ACC43BC2EBB02C7ULL, 0x626797E09B375446ULL, 0xC3F1EA9DCAC5A3FFULL, 
            0xC9F9699952B16207ULL, 0x26726EA9934BAB88ULL, 0x7F75C51A4CA5B2BAULL, 0xAE65BFF53AFD3C5EULL, 
            0xD76CFD1071336D16ULL, 0x02C6C451123B9781ULL, 0x166F8B2B0A8EE083ULL, 0x055C4D6102336081ULL
        },
        {
            0xB1EBD791088997C4ULL, 0x0E40D52DA6CF9789ULL, 0xDBD6F8AAADEB7C57ULL, 0x8EC1F630CB779B75ULL, 
            0xF8B4B1A78C9F571EULL, 0x7C27FA86BAD184DEULL, 0x43297F1FA7D14669ULL, 0xBB783758EE1E7649ULL, 
            0xA1CEC4361DB93A9CULL, 0xF468A4E5B51A0BA8ULL, 0x500775CAB7559EB2ULL, 0xB25021BD91795768ULL, 
            0xA567B33EAB9CF555ULL, 0xAF3179BAED883FDAULL, 0xEEBC985EEF6D40C0ULL, 0x5ACAC2707408146FULL, 
            0xEFA77ACC7A02DBA1ULL, 0x6305DCFF43EFF891ULL, 0x3471AA3A361CE2E7ULL, 0x7622307C6243C335ULL, 
            0x3AD53E727CFF9226ULL, 0x1DC8E59F37F697C2ULL, 0xF18F10B449355077ULL, 0xE092C759D3E87BDBULL, 
            0x28531ABDA38094B7ULL, 0xE5E910EABFA30708ULL, 0x5270C8A3C0264513ULL, 0x3C2BD4845F15C106ULL, 
            0x5118F7F70805713AULL, 0xDBDB1442DDA0D9E7ULL, 0xFFF2F6F655CCA2B3ULL, 0xC0141716E023622FULL
        },
        {
            0x94F415F88ED068E6ULL, 0xF2FE2D1E0A04C947ULL, 0xDAB512540044FEDEULL, 0x3C3A84C1DA724710ULL, 
            0x5AA37A68E4EA4300ULL, 0xE6E6AAFA125607E3ULL, 0xF402F06A780F5774ULL, 0xBDDED555EAB5A207ULL, 
            0xB98913AC15EE82E8ULL, 0x98755016848CBC03ULL, 0xEE03CA6464B436ECULL, 0x21E72F6062C1B49DULL, 
            0xD930928E2B619368ULL, 0x7B24851298A855DEULL, 0x279D17D5927E85A4ULL, 0x46C315CC01E8EB9DULL, 
            0x42D38A8983C795BCULL, 0x5D4763AC4FCEE824ULL, 0x6913559A8493715EULL, 0xB05EF8DA4398A7E9ULL, 
            0x028C84DC3C9B2ECCULL, 0xBD90730591AF7A0DULL, 0x8229BF313C20F51CULL, 0x6D19271388458FA7ULL, 
            0xE7F1D9FB75A3D07AULL, 0xEEDDE35F0EE9D80DULL, 0x93863E4E44D98BD2ULL, 0x1E879B757093678CULL, 
            0xEA4BF5AFE1E42C14ULL, 0x59B393F2120FFBD2ULL, 0xBD89CDFA94EE16E2ULL, 0xA13321A7C5BE5D93ULL
        }
    },
    {
        {
            0xA11ADED69E3AAF3FULL, 0x354CF11B6283C8A4ULL, 0x00304E2B1236E23FULL, 0x9B8EE2864E9F31CAULL, 
            0x7F69F48BB0EE1F78ULL, 0x28323AAEC403CB1DULL, 0x92839ED8661D5C39ULL, 0x5B43C378929A534EULL, 
            0x4CCE5F793E6BC44EULL, 0x47E5755EAED7B817ULL, 0x5D91B20FC43CA753ULL, 0x54B9C25A557FCEDAULL, 
            0x61373635C9FC7B68ULL, 0x063F4ABE2E440A90ULL, 0x3156E77F84412537ULL, 0xA229DEFD6B90D6FAULL, 
            0x91B53B44F7C5BF1DULL, 0x0657B7AB43874D52ULL, 0xECD789CB23289F9FULL, 0x3EF21260E41866FEULL, 
            0x41210503189A73D0ULL, 0xA689E638DF9C250AULL, 0x6B86D15E4D49C310ULL, 0x3C6A1BC768C557EDULL, 
            0xAB9D5CDB7BDD2F95ULL, 0xAA4E8A1BE65AC40BULL, 0xFE031E78A1846A26ULL, 0xEE52F5E90F899CBCULL, 
            0x141977B259D932FCULL, 0xECC240A17E4A6339ULL, 0xB947C5CCEE3F2E19ULL, 0x81C83B2E08224288ULL
        },
        {
            0xCB7C2118F9337759ULL, 0xE7ED40C65E7D77BEULL, 0x3BE6D8B6BE0F270CULL, 0xB18333A065030CA0ULL, 
            0xF9D43D495331216AULL, 0x6FE52E02569330A8ULL, 0xBD1AF50F91415A09ULL, 0x6AA96CAA1705846CULL, 
            0xF1E509CDBFE04519ULL, 0x72F4C05AC3D838C0ULL, 0x61EC012B42634F62ULL, 0x83EEE5B4B883AC28ULL, 
            0x1B904CF873E7087FULL, 0xB4227CA31842160BULL, 0xE0ED15F9F4B8CA62ULL, 0xC05CDD310A53293BULL, 
            0x57FD25AE5ABE0A30ULL, 0xD1800585886B5C19ULL, 0x1CBDD6C69CFEACACULL, 0xB220D060000C185CULL, 
            0xEBD9950E76E5EA02ULL, 0x53DD03D47EA189D2ULL, 0x2AEC65A32BE7AF78ULL, 0x34A2898A89C26333ULL, 
            0x13AF95B1FE40FE11ULL, 0xD65DB4ECB58C5780ULL, 0xC3F807E1C6F5F8ADULL, 0x97FE21EA76E98F56ULL, 
            0xDE4AE374910BB765ULL, 0x588EDE31181C095BULL, 0xA84028D75E5184F2ULL, 0xC5FB821CF30367E1ULL
        },
        {
            0x5EA9475059EA45A0ULL, 0xCC0881F7DAE3587DULL, 0xA8C92EF5FF463A69ULL, 0xEE0D55541A93F7E9ULL, 
            0xC96B3BBEA6E39528ULL, 0xEC9BCCD96EC69C39ULL, 0x5DFEDA4DA15D258EULL, 0xEC1DB430444FBD52ULL, 
            0x107052ADA3DF0E44ULL, 0x02759F829C7BD626ULL, 0x162DAB2BEE0FA9CAULL, 0xA94BCCFD66BB96D5ULL, 
            0xB739201C8559F602ULL, 0x7F848BE61819A116ULL, 0x7D39D20A32D03F55ULL, 0x84749012BFFD8BC3ULL, 
            0xA8D78436FF640B4FULL, 0x4B0E4383F0B7C9A6ULL, 0x2537C6B5854B5D69ULL, 0x746BAA97A3E68A25ULL, 
            0xA7355421984DC237ULL, 0xAFE9929D12E7D555ULL, 0xA198085676FA40A9ULL, 0xF6CD63A1D17A76A1ULL, 
            0xDD77CE625FBCDD3CULL, 0x3A84DFEA78FCDB6EULL, 0xA75028A8CA607FA5ULL, 0x45EF112F3023906CULL, 
            0x3605BD0F2665722CULL, 0xF6A8027E36076722ULL, 0xF118D9BD9A0AB91AULL, 0xF28D11A52496F469ULL
        },
        {
            0x0BC7E303703E3AB1ULL, 0x6830E04C58FC50B5ULL, 0x176A1D52F293F752ULL, 0x803210A68818D0C8ULL, 
            0x6C549155EE79AA3EULL, 0x8FB8C005BE293D0CULL, 0x2EE2E0C2A7204C0DULL, 0xBAF3D5AEC0125711ULL, 
            0xBFBB22B44D1F4998ULL, 0x629DABA5E5B6FF4FULL, 0x44DCF109EFBCE971ULL, 0x8CBD9C38111D97C4ULL, 
            0x2780FE4971701380ULL, 0x6A0A48089146F6CFULL, 0x4DF52B774CCAFB0AULL, 0xE478D4A94012FC5CULL, 
            0xDB8094F932286C2FULL, 0x18BB8AACFE35E79FULL, 0xDF4B1E51A8FB1819ULL, 0xA2CA2EA6E2C36694ULL, 
            0x6396C03E6D7B054DULL, 0x8DDD640EDC0B1C7AULL, 0x3FBDAC90C36888F6ULL, 0x094EEC9505719B0AULL, 
            0xEE5C41A638FC6ABEULL, 0x53D12CC12199A694ULL, 0xC8E4C3A5E8EA7D95ULL, 0x206E31EECFB0D0E5ULL, 
            0x5D320AE6E1071EB4ULL, 0xCA0380F5253FC6F6ULL, 0x9F2E05E10E860589ULL, 0xAE0A6FD3D1BC7772ULL
        },
        {
            0x6CF11F7A37CA3518ULL, 0xFEC3A19030972E91ULL, 0xA35DE7961717AAE8ULL, 0x713E9A7C110797B1ULL, 
            0x2C6B7D92F9B2F8EAULL, 0x28290CC29AF8CF61ULL, 0x14C9A20777E48358ULL, 0x7B6E2E7A39C3CBF9ULL, 
            0xF26E8B3948681F44ULL, 0xD5C4F604B447F9DDULL, 0xC6FC00782A3E6282ULL, 0x2E049E8A4D819799ULL, 
            0xD2A0F8903CF8DD54ULL, 0x64C9F959401ABCA2ULL, 0xFE14294AD2FBFAFEULL, 0x2C2A74DD0882176BULL, 
            0x611CF6C162216FCBULL, 0x4D0107D6787E815AULL, 0x530A2C5CAC782D73ULL, 0x490CCD148DAA30BBULL, 
            0xF2ED470DD9A804D0ULL, 0x753B282C3C144A4DULL, 0x62C5554FE0833FF4ULL, 0x3B11342C9B1C98B6ULL, 
            0xF1247048F86D4EB5ULL, 0x9AA01BC7542C0C6FULL, 0x7BEB9FDD5E2676A2ULL, 0x450DE51EC6D71F65ULL, 
            0xB56D275EBD09F5ABULL, 0x65C96FA028F66586ULL, 0xAD48C2E35E06BBBBULL, 0x34235D195F288A12ULL
        },
        {
            0xE50623CB8BE680C0ULL, 0x8FB6CB2F8E695062ULL, 0x05A5B9812ECC70ACULL, 0xBA705FAAFA91EE66ULL, 
            0xB535BFADC01366F0ULL, 0x0FBF5779184FDF6EULL, 0xEDFE6800CC497CEDULL, 0xEA827AF90323412BULL, 
            0xE28D595D982FE0BCULL, 0x12923D24E6885A23ULL, 0x1A23C1270DB65CC4ULL, 0x5D05239D01CC058DULL, 
            0xE58EAB115C5309DCULL, 0xA554D42B91561645ULL, 0xEFF3C57B6EEC2884ULL, 0x607BC6374EB3B48BULL, 
            0x62723AA1649EDBADULL, 0xE33DFFACF19755F7ULL, 0xE7FCAC67FC497F3DULL, 0x6C0F9375AAFC094FULL, 
            0xC9ABC09AF2B9C82DULL, 0x1E37A931CEAEF2ABULL, 0x5500F2CD4707B4CEULL, 0x44C351D7FA0A8F7AULL, 
            0xD63C0AA1AE2351DEULL, 0xDBC54C18010EFB4EULL, 0x23DD83767203CCCCULL, 0x882411E67817BC30ULL, 
            0xFCCF94EE37039642ULL, 0xAAA734BCB2001401ULL, 0x4894AB5A43726BAAULL, 0x4D7F7C27336E8BB4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseCConstants = {
    0x813F189AB00E67F4ULL,
    0x1B1136663258E902ULL,
    0x470D6DA22479C685ULL,
    0x813F189AB00E67F4ULL,
    0x1B1136663258E902ULL,
    0x470D6DA22479C685ULL,
    0xFFB9145210C103CCULL,
    0x00BC7EDCE51B28A6ULL,
    0xB1,
    0xCA,
    0x61,
    0x23,
    0x10,
    0x28,
    0xF6,
    0x5A
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseDSalts = {
    {
        {
            0x2AC31BE9107EB5F6ULL, 0x91490136DC4B89F2ULL, 0x54F0BD450DE30B16ULL, 0xEB726F79F54FE813ULL, 
            0x780E9CE14C19B897ULL, 0xCC6EB278864434B2ULL, 0xBD45B8616E3E9393ULL, 0x7350C0E45F5573ECULL, 
            0x14FA1D2BE9421237ULL, 0xC0AD4A7FF2B883A0ULL, 0x0CCD76475F8CC053ULL, 0x0F4399234259D11FULL, 
            0x7D4B3C711C285F2FULL, 0xCB25346B19AD3E0BULL, 0x2AE317D64A2BFF49ULL, 0x055512C708F85562ULL, 
            0xF62C6EADF320F850ULL, 0xCB91564D73C483E9ULL, 0x9A0B2A90295A33A1ULL, 0x0014E46985078E17ULL, 
            0x7E6DD0DD346FD01BULL, 0x4B6EB01C6F722942ULL, 0x3847F771B15C1DFFULL, 0x9FBF17EBFDDCAB59ULL, 
            0x828173B9E6318C8DULL, 0x95E0FD580BA30984ULL, 0x64DA3B04A33DAF48ULL, 0x88C4868771D74BDEULL, 
            0x567820804C13B437ULL, 0x30D5E1E4D8BA11E0ULL, 0x59061C2D240BBBADULL, 0xD2C7ADE2C59B0BEBULL
        },
        {
            0x3AB9ECE995F21F31ULL, 0x36185ACD4DED1148ULL, 0x7B6C1860F1E23798ULL, 0x186BFCDB62B5FEB2ULL, 
            0x182A2E9B0E29618FULL, 0x345F03D5C005EE2AULL, 0xE51938BDBC4E487BULL, 0x04AFA9B4A1A190DEULL, 
            0xFC3ADA71093CCB55ULL, 0x57AA367FCE47DAFFULL, 0x7F063C6405243049ULL, 0x62656511F8A58EA8ULL, 
            0x251850D260F64E9CULL, 0x5284E80DB049A78CULL, 0x383E3EAD77302CD9ULL, 0x4B72EAB7A08883EEULL, 
            0x943EA6E5A22FE83FULL, 0x93B23B42E541446DULL, 0x6D3A9EE7D7768B02ULL, 0x7C9A9BF16DBFD0DEULL, 
            0x56173E3C616FEF2BULL, 0x9D91F48D52407451ULL, 0x02F9ED796A2B781FULL, 0x8E9F4464C6E82022ULL, 
            0x10EDEC54CBF38888ULL, 0xE37CA787EEDC466AULL, 0x343C8C5742AB52FDULL, 0x03616C94B3813D11ULL, 
            0xEBD7EDC250BE0CC4ULL, 0xCD70D65FCA233A2AULL, 0x405B5BFADD02FE4CULL, 0xB75138CDAA723A63ULL
        },
        {
            0x3535CAA0D61F86F5ULL, 0x0904000A64F54871ULL, 0xA5286CF647A9C7EFULL, 0xF6AA9553BDD621FDULL, 
            0x5F1FA2A3350F11ADULL, 0xC11F25A250DFE3AEULL, 0x8BCD250F29987D38ULL, 0x60EE7F1FCBA440FCULL, 
            0xEF993ED1FF45CB11ULL, 0xCA816DE514DBCA32ULL, 0xC3DC94077689A51BULL, 0x7A768084FE27B4B8ULL, 
            0x43628FC9C67CE352ULL, 0x109131086B06F79DULL, 0x3E68623844E386B4ULL, 0x0A649F5CEA30F1DCULL, 
            0x6D23E3D2BC18D186ULL, 0x363A3986F7175B5AULL, 0xA3F1B3B3FCE98D7EULL, 0xEB1B56AC2333DC63ULL, 
            0xF5E8B56359ABDFA0ULL, 0xE2DD7DAFC3FD6B91ULL, 0xFCD36B8FE3F00C8CULL, 0x7AE9B9554D68C241ULL, 
            0xA728ABBFACD98700ULL, 0xAC1F0F85ED64B152ULL, 0x662150B47DB135E6ULL, 0x9090BC3570126CB5ULL, 
            0x1864740F01CBA3B9ULL, 0x75092307573B2744ULL, 0x74D88890BBAEEE5CULL, 0x5E10371A883E1FAEULL
        },
        {
            0x9A87C6B35B0F7A65ULL, 0x5FF15FB5C43E2367ULL, 0x738BFDED12432346ULL, 0xBC4B443328E4049CULL, 
            0xE4196CD0E846EDAFULL, 0x6462393BD633C376ULL, 0xFB5DC840F327B921ULL, 0x3CDBC217045B0D1DULL, 
            0x9E3D7C2792E60ECDULL, 0x877DFC8AE5D138E1ULL, 0x8AAF82EDB1650D2DULL, 0xD831EAB8606686D9ULL, 
            0x0DFED85689F40565ULL, 0x1B209B3B53D40C4AULL, 0x6CAC6B8960A4819FULL, 0xEAC1F788BCBD21D5ULL, 
            0xCCF3D9E08FFDBFCAULL, 0x4796255FC713FC51ULL, 0x5FA09F4DBD37D3EAULL, 0xDC4AA29DA93E5ADDULL, 
            0x22EE9D006A785740ULL, 0x7B6C3C9FF33391B1ULL, 0xC4D5870F0BAB861EULL, 0x3137D2C125B1E8EAULL, 
            0x3FABBCC37634D29CULL, 0x0BD7B62BB44B14F2ULL, 0x3E1B72C58F80F7A3ULL, 0x6925E2017BD14AB5ULL, 
            0x21096D29DD9C9195ULL, 0x21E686CF8981938AULL, 0x0B5240FCEF666CDEULL, 0xE690FBD667DE7925ULL
        },
        {
            0x2706D2C0A2F7ED8DULL, 0x61A738A4553B8E67ULL, 0x2A31CDE13ED6F0EDULL, 0x5B8BAF57B3194470ULL, 
            0xFF460CE2B1EC5B03ULL, 0x990C3C1145465448ULL, 0x31B2E428CA6F6DF7ULL, 0x1BB2425D8F06AF4AULL, 
            0xF0F00B17F76085F1ULL, 0x731341170E9EF479ULL, 0x09F8E163E98E91D1ULL, 0xCA099F2568CEAFE5ULL, 
            0x383A0B744D841FA3ULL, 0x83729BEBE1FC23E3ULL, 0xB822CF53B0AA08D0ULL, 0x3A0DCD4F5FE77BDAULL, 
            0x3FBB23ECE0F628E3ULL, 0xBA32255A4CA46274ULL, 0x4B322FC883110A6EULL, 0x01982530E551FEECULL, 
            0x42754F35D8BEDD09ULL, 0x8C11A55029C3FF09ULL, 0xCA434EEA1A63FCF6ULL, 0x4148C84EB59B7808ULL, 
            0x3C8D2D297660E885ULL, 0xADD8BBDB05F6939DULL, 0x21B201E4A4A8615BULL, 0x0F9F20A209475457ULL, 
            0xB5E1372C4EDE95DAULL, 0x005B4E886851BBF5ULL, 0xB5A800D60172DC79ULL, 0x4B718E331F1C70FDULL
        },
        {
            0xBE7A2C5328BB9136ULL, 0x5E4DBE40E0819263ULL, 0x33E8970DD81775D8ULL, 0xC1A0A46A2C62D5D7ULL, 
            0x765FE0F6744F8B2AULL, 0x3990D877922186BBULL, 0xC50D7610A577B773ULL, 0xB6DB973962138DA0ULL, 
            0xE06FDDD6DD61DEB7ULL, 0x7EF462366D4B3CF8ULL, 0x82209DE4C16B82B7ULL, 0x4896B8E152E8A4F7ULL, 
            0xF5316895C96D6B17ULL, 0xE5CED5F5261E4FF9ULL, 0xF9FF9310ABD8136CULL, 0x1825173C115150C7ULL, 
            0xDA9EBDD9CB990DCEULL, 0x687CB42F9420DD25ULL, 0xBAF092C6E49C15C3ULL, 0x1E8EF79BB0F23F31ULL, 
            0x12ED55F2F06571E4ULL, 0x67D1F03747287FFFULL, 0x2015A874CC3BD125ULL, 0x7C012FE4770AF437ULL, 
            0x688D0A12C395181AULL, 0x21DE46F5193A3A5CULL, 0x4C944A79A7719A05ULL, 0x5A9EDD8BF091EA5EULL, 
            0x0B0EED3210A62FF9ULL, 0x3E26A2CD4E14A5C3ULL, 0xCBB8544E6157EFD8ULL, 0x1D7D2CB844CC2CFFULL
        }
    },
    {
        {
            0x588510CE01FB7795ULL, 0x1F64A6AF93253DE1ULL, 0x76EF8280237313B5ULL, 0xF02C97958E79880AULL, 
            0xCB70B2B73ABC6ABFULL, 0xBF865478A75EFEA5ULL, 0xF5413763B3D9C7E0ULL, 0xF68DB8B4F9C7BA8DULL, 
            0xE4F6E29D37F66357ULL, 0x2C3D6A1162AB5A16ULL, 0x58EF807109B3322DULL, 0x1390F2A2DDD79C43ULL, 
            0xC37200DC94D58B07ULL, 0x4FE4704401FBBCE2ULL, 0x171F8F3799C6AE9CULL, 0xB0E72A9A206E9D67ULL, 
            0xD8770F3B24E5FFE8ULL, 0x5D8C5033CAF3FEA6ULL, 0xA7487004AA954D85ULL, 0x0D4CDB81A4CAAC29ULL, 
            0x3E37C0F3173ADC28ULL, 0xE566633807470B1BULL, 0xB3F1BF974B361C7DULL, 0x8DE936664756A708ULL, 
            0x3638740B9B9BE147ULL, 0xB98FC23DED105179ULL, 0xED8F244A0BC62177ULL, 0x37B3769D07426D22ULL, 
            0xE519B97914BEA530ULL, 0x035CC9EABFC55036ULL, 0x70F9C2017A5F9D3DULL, 0x351D9F8C963B9C5AULL
        },
        {
            0xC37E17463C9F786EULL, 0x75B79E21C04FDC27ULL, 0x5E80CE918AC70F41ULL, 0xFC47AA8E2369E60FULL, 
            0x3E4D888FD4AD4C67ULL, 0xB05498246062B41FULL, 0x29E484371691D2C1ULL, 0xCC8A1A0191F847E6ULL, 
            0xC17541BA555A436EULL, 0x08CA5C292B96CEB8ULL, 0x64D5E29481A3DFD1ULL, 0x2B0732B10A506B9FULL, 
            0x1AAB1E15A56667C1ULL, 0xF0D53AE89B6D9E96ULL, 0xCF85EB357B5492A8ULL, 0xCEB59A2D3640A310ULL, 
            0xFE56EB0D6B3C9183ULL, 0xCC2659112C2CAF2DULL, 0xA57E4369C2936404ULL, 0xAF6839809165B378ULL, 
            0x33A11081BF3D1634ULL, 0xF47B3F9881DBDC67ULL, 0x5FCAF8E837767CD8ULL, 0x6EDAB35B77EFFF65ULL, 
            0xB80CE34619B4E87FULL, 0x6F112E72EDAAF765ULL, 0x339B3C4B7AEA7DA4ULL, 0xB3BEBC39EA5A87DFULL, 
            0xEBC194942714A553ULL, 0x9AF791A97D0474FBULL, 0xF12A9D403301702BULL, 0xFFF5F74E5C9096F7ULL
        },
        {
            0x94023A27794D2939ULL, 0x0521EC4C9062D38BULL, 0xB4E817AF8972E089ULL, 0xD7F8183A806000FEULL, 
            0xB94A9B343F698120ULL, 0xCE5FA8CFC4B0C004ULL, 0xEA2D52B91FF49DE2ULL, 0x5410C7631103FB4FULL, 
            0x74F59EB42A1D402BULL, 0x152A230E58282267ULL, 0xEB39F1462CCA5C26ULL, 0x40BD7A192B2EB3D9ULL, 
            0x1563C7D4EAAA3224ULL, 0x1B2A6B6206A21DD3ULL, 0x436D47987F2D21EEULL, 0xD72B04F30B5BB674ULL, 
            0xE94F7875E029F4D7ULL, 0x1D519A6A844183CDULL, 0x283E7F51187D9029ULL, 0xC4EBA9FBDD911049ULL, 
            0x24A8F381DA2DFACAULL, 0xD65A64EA643195C8ULL, 0xAA6B690375E29FB4ULL, 0xEB77869B1B1FF536ULL, 
            0x3F73BE5342701FA6ULL, 0x314D7D78C4475820ULL, 0xB109BA964DAD48FCULL, 0xD48E50CD94A09397ULL, 
            0xF3D3F4FD714A3766ULL, 0x36F7C292409DE5BAULL, 0xCEECDE03C05E2037ULL, 0x31E541FA8D8A372CULL
        },
        {
            0x97B8CD7992364628ULL, 0xF82116B205931855ULL, 0xACD7769725C29E8BULL, 0x873A37F1B72BB97DULL, 
            0x0D02C690314DD301ULL, 0x36F2365E30EB1B0DULL, 0x9B113AE668E1725DULL, 0x557128B3F6251208ULL, 
            0xADF5B93A347892CAULL, 0x98CF56D8219B647BULL, 0xEF6F85AA514A2D99ULL, 0xE04679B1CB2AAC9AULL, 
            0x06123BDC9D8D1819ULL, 0xD03311D6D7279B64ULL, 0xE0FD1A01C657E711ULL, 0xDA9E9963F037AA41ULL, 
            0xF3AD30A64F70FC3DULL, 0x0C68E02E3FA6ABD5ULL, 0x7DFC2986978D3C1AULL, 0x6E56B81FA802DED5ULL, 
            0x05EAADC83B980025ULL, 0x2EDF33653CF1375EULL, 0x973EC81117AFB03BULL, 0x6173F513A764CE78ULL, 
            0x4ED5DBFF960FD692ULL, 0x275FDD4746866B6EULL, 0x4FF56FF023B11757ULL, 0xD26FEA13CAA69F3FULL, 
            0x829ED45A791F6936ULL, 0x944099FF3995F243ULL, 0x6E9F435B4B60B060ULL, 0x349BD24E66A9885DULL
        },
        {
            0x9008E9AF326052DBULL, 0xDC97C8E74C4CBDB3ULL, 0xD43C4A7DDFD367E3ULL, 0x84BF764A59D51EFFULL, 
            0x5C638459E856F1E9ULL, 0x9B6F0F560CD4D2A3ULL, 0xC5A81A0C60845B33ULL, 0x1E6B73B82BD753FEULL, 
            0x7E07621E15F8AB67ULL, 0xBF9CC64917B0AD26ULL, 0xC784743BB680CC47ULL, 0xCB9BF96370FF670BULL, 
            0xEA8D52D3176AB2B8ULL, 0x420801287E87CBA6ULL, 0xED85C23F1295844EULL, 0xAC976C64011A0CE7ULL, 
            0x6E01CBAC5BF61A3FULL, 0xB1DA8A666CF48DF6ULL, 0xB24E67148C566722ULL, 0x2821E83D156D2182ULL, 
            0x8862D497CAD32198ULL, 0x8C2FB5ED6E56E956ULL, 0x41250EF0BEEA490BULL, 0xBD00E5BF458B7301ULL, 
            0x60F262D4F3315B5FULL, 0xD48CF0D61DF03988ULL, 0xB7A567D3531E69D1ULL, 0x940412DBA46D8929ULL, 
            0x8FF27C898BE8BC59ULL, 0x289844E9E05F25B9ULL, 0x61EE805E3811F712ULL, 0x2F1EF205E4AEE573ULL
        },
        {
            0xA77AEF7119852524ULL, 0x054FC95A12EACD98ULL, 0x6103B858C2C6E8F2ULL, 0x2151C9A03C7B9826ULL, 
            0xCB0984A811F09DB1ULL, 0xE4809CB444CB28DAULL, 0x1050508311AA0AE9ULL, 0x03C1B1908C4791D4ULL, 
            0x19AFA75110CBFB91ULL, 0x16D1F9226B181B73ULL, 0xB777A0CCCA4F7AFDULL, 0x2F45FB6A02E990D5ULL, 
            0xF0319EDAB26CD0B4ULL, 0xBED69A43ACACEFDFULL, 0xFE86119D6DF1A89EULL, 0xE47535B06558C174ULL, 
            0x9328E015240D24A4ULL, 0x18ACE0F84CAD4D56ULL, 0xC0E42FA189A03B8BULL, 0xDD3F2654DBE3AF0DULL, 
            0x2C8D545AC9191E4FULL, 0xAA0EC6EE104B2CFFULL, 0x6837317C464A21CEULL, 0x975FBD96458B704FULL, 
            0xDAA8CDDA47164714ULL, 0x89806BF4A5D1CD2CULL, 0x38987DC6D25CC92AULL, 0x71D6AF9A970006E2ULL, 
            0x304FE451DC1C658FULL, 0x1F9D8774D666A9B3ULL, 0x175E7A1E959B90E8ULL, 0xB64D727340103BD6ULL
        }
    },
    {
        {
            0x1F5F415F851D40AAULL, 0x93D4C3105917DFB9ULL, 0x86B8D6321F025042ULL, 0x8307574D5B09991AULL, 
            0xBC965FC1DB06599DULL, 0xC9306D82FC6E5C0AULL, 0xB3C22FA5EBA6D0B5ULL, 0x3163747FDA13D121ULL, 
            0xECACF89B66F83BDBULL, 0x9496EE7E901AD990ULL, 0x4ABF68A9A84E2A95ULL, 0x1CF6EC9B21C66F7DULL, 
            0xCD3D36DA66F2D33DULL, 0x99C326160FC53ABFULL, 0x80A6301C402F93ADULL, 0x1404173069542276ULL, 
            0xE8FD4053345608D2ULL, 0x77CBBA81E9DA4FD6ULL, 0xCB315407B7D7E3FAULL, 0xF3938E89068C31ECULL, 
            0x232FB393359C75E2ULL, 0xC06370B3905031F3ULL, 0x19CC3E3F922DCF41ULL, 0x26A659149CAAFE23ULL, 
            0x7758FE973C5F2891ULL, 0x3AA881DA3E62BDC4ULL, 0xAB48CDCE712D5825ULL, 0xA556F2A71E7A80CBULL, 
            0x50D78FB8D89CFFF6ULL, 0xB8D2BE558F5D8A25ULL, 0xC66B35F4FFBD66C7ULL, 0x7AD277C7789DAD1FULL
        },
        {
            0x88E09629601920FEULL, 0xC3E08290097AEBB2ULL, 0xBC60697A39C90202ULL, 0x654756D29F3FA751ULL, 
            0x02DAC4DBC1CDDFF8ULL, 0x82251B9D00561313ULL, 0x6D5E714DC99D9326ULL, 0xF547CFCCC46AE378ULL, 
            0x9CACC7E5D93181E1ULL, 0x82B621537A9448ECULL, 0x82DB2C7DC9A545A9ULL, 0xCCC0C4949BBC18A7ULL, 
            0xADC3FEB65AAA3E52ULL, 0xFC332DA59232F8FCULL, 0xEEB7FFE8D0EE998BULL, 0x2CFC88B44528ED02ULL, 
            0x573B531E695BB730ULL, 0x35991C6659780D90ULL, 0x29FB8F1265142E10ULL, 0x3FF3D0DB2BFE321DULL, 
            0xD912D1D9B9F0690EULL, 0x8C8E30831D91DC86ULL, 0x5C9A71F2911122B2ULL, 0x5D49E5EC0B74C7E8ULL, 
            0xA0B399B318014613ULL, 0x3A0167A3DB24989DULL, 0x7E2F7A48A5897719ULL, 0x9E99B757367FCEE7ULL, 
            0xABD95F3F39920057ULL, 0xCB564A3F3D781581ULL, 0x5CF8E1525E10D7FEULL, 0xDC332758A7AE28C3ULL
        },
        {
            0x49FB40D14E540234ULL, 0xAA9F1D5BDA5C7F6FULL, 0xE897DCC098476CA3ULL, 0x8CCC5D50B6DCA183ULL, 
            0x08708EEDFDE53BF2ULL, 0x85693EE59232B435ULL, 0x3BEA98579507786AULL, 0xB67B0E647F1363AAULL, 
            0x30F7052DF4E9E4A7ULL, 0x1F3CAF259087D3B4ULL, 0xAB761E0F3FAF5E80ULL, 0x7A9150ABEA666C69ULL, 
            0x090F7E3BC0FA1D7EULL, 0x704617B030E78EC3ULL, 0x095C78CBBB045B9FULL, 0xA30C3D3EA358202CULL, 
            0x33D20D9AB4CAA59AULL, 0x7B260F2014E2FAD5ULL, 0x77112AD92A221358ULL, 0x81150C817B876845ULL, 
            0x0CA67B46ECCE9B72ULL, 0x5C56DD0EFA87D99BULL, 0x35DAA528A39E4486ULL, 0xC81A3022AF694837ULL, 
            0x84778F1AAA8442F0ULL, 0x8E8535BBBC53CC5BULL, 0x40F90553FB414C18ULL, 0x692D70086C140771ULL, 
            0xD24D3CA26F145DC8ULL, 0xCEE70137B7C3E07EULL, 0x2A0F30783AED279FULL, 0x3CBB6C69B4DA39AFULL
        },
        {
            0xD2AE9E11F3AE816BULL, 0x102A988C0741A8CCULL, 0x8738FAFE2B416EB0ULL, 0xF60CFD723F5DB41FULL, 
            0x152997F56826239DULL, 0x8515C7E09ADF0C0AULL, 0x9446281A4FE5105BULL, 0x7352B56A1C3547A6ULL, 
            0x036AD6BFBB1A5FBFULL, 0xD2AA4A461E867989ULL, 0x50DE45EB57A46346ULL, 0x2485EA32AE6EA0C5ULL, 
            0x24A3D5978F262717ULL, 0xD837A0A8655C0433ULL, 0x870FEA5DEAA61F58ULL, 0xE6B02D2BE9D5D613ULL, 
            0x471BE1713B34931DULL, 0x4223E4D08CFC29E3ULL, 0xFF852F56A1EFBC4EULL, 0x539367F58E05B62FULL, 
            0xAF7A32008CB7937AULL, 0x1254A7B00D523AACULL, 0x634A43A4960A4510ULL, 0x1034B2261579704BULL, 
            0x603D1C62FDD2532EULL, 0x177C9FA69D8D4D8FULL, 0x082EC105F740BD64ULL, 0x743B2A040DC58715ULL, 
            0x18867150AF1A3C3DULL, 0x4F85E06F8B71F594ULL, 0x574867ABFAA6156FULL, 0x80FB843ECBE74D30ULL
        },
        {
            0xB5482A76323D6153ULL, 0xC9FCBACD896D2C3CULL, 0xEE56DFB75A6B450FULL, 0x6762C991E31EF791ULL, 
            0x4FEEB0ADABD95964ULL, 0x85B9DD29CC09AC96ULL, 0xF16F703904336012ULL, 0xFB7CC67E38C26B2CULL, 
            0x5881343302CE01CAULL, 0x58AB26C49172E403ULL, 0xCA086CAC8B499E52ULL, 0x840E13FD0241010EULL, 
            0xED9A2E3745F150C9ULL, 0x26EACEAE34531F41ULL, 0x42D8040EF77D900AULL, 0xC492501775919429ULL, 
            0x4F5383C90871F43BULL, 0x75A7D18F3F851177ULL, 0x15E5C36517BC5A00ULL, 0x1AAFC9BA17392323ULL, 
            0xE88E4F2CF44E789DULL, 0xC743143AE4175F78ULL, 0xCD81C01AF4D1392DULL, 0xFD947858F1D738F5ULL, 
            0x32FD5BF11FA14CCFULL, 0x032FA50734CD42B2ULL, 0x0802915F93BA9C1BULL, 0xE6A4E82A66F1F214ULL, 
            0x93F7792200499418ULL, 0xDACE160AB205430FULL, 0x5350DB53632C4E9FULL, 0x1276952E51E4DFCFULL
        },
        {
            0x24CC72991F1B90BCULL, 0xBA4DE2CFDB1F13DEULL, 0x03D57A000A9231CCULL, 0x6D802B76FC009043ULL, 
            0x66EFAC94EE7410BCULL, 0xBB3C5F20DE777183ULL, 0xF97F365E78B903D5ULL, 0xE5BDFF0F789EA15CULL, 
            0x81A1FFE92505C247ULL, 0x53C54FB6DDD3349FULL, 0xA97BD3A35A697EBBULL, 0x40226A312CE5107EULL, 
            0x60133C235F196124ULL, 0x93BBBEA6E0F223FEULL, 0xB32A8C883073EFB8ULL, 0x7CEE1DF2578333C0ULL, 
            0x8961EB7E8E8E6EADULL, 0x7F7BF2CCB13CF202ULL, 0xC614B8E1EC8A969BULL, 0x5962994C6685C8BCULL, 
            0x8104DD4079EEC41FULL, 0x0FB3902CE20A1B9EULL, 0xDF3F7AB33769EF9AULL, 0x2EB77F0060FF1685ULL, 
            0xBBC0FCB19577C0FAULL, 0x49F5AFCAAB0EFE2DULL, 0x755CCC1A55E9D837ULL, 0xA275BB763F02EA36ULL, 
            0x18B2A28C836E6436ULL, 0x6ED0B9706F35CDA0ULL, 0x4F0687EB657FCE02ULL, 0xC32F7D4A16979CB2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseDConstants = {
    0x1C8C8C24A7C6F9A2ULL,
    0xD2424D02A116A9FCULL,
    0xCAB189526053966DULL,
    0x1C8C8C24A7C6F9A2ULL,
    0xD2424D02A116A9FCULL,
    0xCAB189526053966DULL,
    0xAA5F4ADF3FF6C2A1ULL,
    0xAE59141BE55A3A85ULL,
    0x5B,
    0xDE,
    0x6C,
    0x40,
    0xA4,
    0xAF,
    0x39,
    0x27
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseESalts = {
    {
        {
            0x056E144098BCD4C4ULL, 0x61F29A2876FF3F97ULL, 0x0561BBCDB777352AULL, 0xF953BBA52147A16FULL, 
            0x4A40DEB6527E34ADULL, 0xC5ACCD5F57A78BEFULL, 0xF33A30E3481B8AB8ULL, 0x30858D862CB1F451ULL, 
            0xCCC8976054CCEA48ULL, 0xD35CFFF962596BEAULL, 0x67BB6E234DAAB103ULL, 0x87A58CB7A42384A6ULL, 
            0x1BCCDAD18D4FBDBCULL, 0x24615A9F214ECFE5ULL, 0xFFD766913A46B829ULL, 0xF0CD75EC0732F355ULL, 
            0x338F3203ADC47A64ULL, 0x1EDD544F37F071D3ULL, 0xDEF0B6A5DE865648ULL, 0xCE5D50422539968BULL, 
            0x9B2064C105D4A74DULL, 0x78AF349D935B0E0BULL, 0x8CB42336BCC12A9AULL, 0x7124F97549319343ULL, 
            0x5DBAB3596D43B863ULL, 0x4AE4B52CA5BE4D25ULL, 0x55F61C67499FAC7AULL, 0x406317BC8B967FC8ULL, 
            0x74B580CF9186FC16ULL, 0xA3255127F051339EULL, 0xE6DFDC1ECA2D302CULL, 0x50F2CBAC2D313716ULL
        },
        {
            0xE3B3ED685ED175DEULL, 0x37B9FBDEAE7F4A0FULL, 0x0C71BFE426FB080EULL, 0x0CC5AC2EA1B751EEULL, 
            0x20CA3F293C1C4B69ULL, 0xABBF006A23D259D6ULL, 0xDB3E5BFD5E62C2A5ULL, 0x6E27FCBB785EB4A2ULL, 
            0x0C70A3BC2F8D5988ULL, 0x12B57B2240ADBF22ULL, 0x371467930421FDC5ULL, 0x1243E1B16582B2A4ULL, 
            0x287BD61F160ADB8EULL, 0xDABB5C24FD14827EULL, 0x0AA52638294037D0ULL, 0x75092BC9CB07D7F7ULL, 
            0x119CF74F96D16A9FULL, 0xBD1E446549027D4AULL, 0xF3C633EA52734567ULL, 0x8BF855E1BA35EF03ULL, 
            0xAF286F890689C4A4ULL, 0xA07AFFB17834502FULL, 0xF70F1461B583AFC1ULL, 0x1CFB55B365BF6C84ULL, 
            0x6F823EB5B48DE906ULL, 0x9170C403DCF4FBDEULL, 0xEA81DB51A0DC9999ULL, 0x89CE3F29BACE16E7ULL, 
            0xC6F2F91FE710A1A6ULL, 0x0A47FD966B0C6492ULL, 0xA22E1ED2D204921DULL, 0x2082ECC14CD26408ULL
        },
        {
            0x4570A2977ED8BDBBULL, 0x4260E561E33322F2ULL, 0x8EA1A92FF62A3984ULL, 0xC30AD27A86AD8037ULL, 
            0xF63BF6B61CE65539ULL, 0x33DC22DCA44DD0B1ULL, 0xA25702DA70502BC1ULL, 0x6CABE4E45CC871F2ULL, 
            0x8F2B5C317D3130CEULL, 0x67741831E9D527CBULL, 0xC72E684996C57040ULL, 0x9FB3E3D019789099ULL, 
            0x97E26E362562372DULL, 0x04E2FDCB3DEFC999ULL, 0xCA6CA487A35B9B99ULL, 0x86222E1D6C716AC3ULL, 
            0x6251D43663F8A262ULL, 0x233023E3A903BDECULL, 0xEFDA57F3E0F03B5AULL, 0x5438915D98112CE1ULL, 
            0x7C3A5225AEBEA292ULL, 0x98A92D9EFB7E47C0ULL, 0x6EF6028E4DCE1F9CULL, 0x3D6C670572F2B62DULL, 
            0x21F7CC633583C42BULL, 0x9844B2A1B354338AULL, 0xDADB3F0F6F06F247ULL, 0xCBA5157A8BD7B952ULL, 
            0x40EDA33041017033ULL, 0xD952BFEE4A6F9BE1ULL, 0x4441CB867C810D08ULL, 0xB7AE70447E7D0B03ULL
        },
        {
            0x1AD0C3A19AA2A2BCULL, 0xA9753A61495EB26BULL, 0xE69B36932B212E10ULL, 0x900FA96E950B3F67ULL, 
            0x9C07681C5770AD4CULL, 0x3E38D709855B7F78ULL, 0xE2C25339CF2EBBFBULL, 0x3DE731D150D6A519ULL, 
            0x83C350A719E8318FULL, 0x76CB5636579E4D94ULL, 0x4F7A64BA210E581AULL, 0xC67B3F79DFE93ECAULL, 
            0x3FDCF3C0D0B4BB71ULL, 0xE3C78A7C4A9A010FULL, 0x5E90F5891AD14F58ULL, 0x63082467C042CDE2ULL, 
            0x050CBBDF4F809910ULL, 0x47B92228164FCA26ULL, 0xA66A8C79E6F044D5ULL, 0x473B1D01BFF9C9D4ULL, 
            0x7F168DECA6922C00ULL, 0x4DA931D009F3ACCEULL, 0x5846110B9AB79D02ULL, 0xC290751C8DC5401FULL, 
            0xB02502E752919A4BULL, 0xAF09D9777018E024ULL, 0x1C04D42F32068461ULL, 0x32863988F8B9262DULL, 
            0x1FF1BE589EE4A909ULL, 0x14E230E37A395FE3ULL, 0xB686E10D957F7055ULL, 0xCA568432C6718A12ULL
        },
        {
            0x82D21735121FB09EULL, 0x2BB756B683C6C2ABULL, 0xBCCB0A9C3EC5BCF5ULL, 0x572DCC612586D3D5ULL, 
            0x46756586F3B6048CULL, 0x30B060B3CF397FA7ULL, 0x4BD07F25DD1F7B0FULL, 0x6A05F1C47A630F8BULL, 
            0x78322E3683E564C5ULL, 0x44CC8AB42B64DA89ULL, 0x5E960191E72C3B03ULL, 0x04444AA52E776DF0ULL, 
            0x1CEA2ED7B9D0E20AULL, 0x5B212EADDD8D27D8ULL, 0x5283B04749EA2FAAULL, 0xF966C70D7FFEAD5FULL, 
            0xBAC442BD7FD8DA0DULL, 0xE664C0B52D968C56ULL, 0x8AAE30CDBEE8B116ULL, 0x327E50D3F4647B6EULL, 
            0xE40877A2511215E5ULL, 0x7A63DF497B6A0B27ULL, 0xE254075228FF7309ULL, 0x961B529C4F6F790DULL, 
            0xD961F091B61FDEF8ULL, 0x62182ADBF03B55F2ULL, 0x1D76EA471323BBD2ULL, 0xBBA13A91347BB670ULL, 
            0xB3CCEE08CFE4729AULL, 0xDA89EAAD982A7B07ULL, 0x5008903F992FBC26ULL, 0x0DE2DE522E739168ULL
        },
        {
            0x68F3230B9C01AF29ULL, 0x783C23850E4ADB79ULL, 0xB525D3A75144BA0AULL, 0x24314EC4DB6AE3E4ULL, 
            0x2A2125C3228C540FULL, 0x4D28FEA2DF2A4C0BULL, 0x58C5EA62B093303AULL, 0x0E7C3D350BC7C45FULL, 
            0x20B0E691C22BB2E6ULL, 0xB031B7EE671A4577ULL, 0xA1A454558D6ACD8BULL, 0x29BB8A230B1D810AULL, 
            0x26098C97C7A43F1EULL, 0xD2D1EDC6F3DA0774ULL, 0x59DFAEA5361B5CE3ULL, 0x335148E4878D1B6AULL, 
            0xB4D7133293531B0EULL, 0xAF4301BFA9973C8BULL, 0x517A068382BE7393ULL, 0x1F839B5521FFAFB5ULL, 
            0x6427DBE15A33B1C5ULL, 0x0E8C7E52A374D08AULL, 0x6D5ECD105F2BBB10ULL, 0x573F2F43D6CEAD65ULL, 
            0xA1CFD922F3AFFC27ULL, 0xDFF52C774B6D31F8ULL, 0x9E47D66AE298C854ULL, 0x20EF98DC0CE7CF53ULL, 
            0x8655D3FEDD218105ULL, 0x775377752D4C9DECULL, 0x7E3A6D575B58475BULL, 0x6804098579764C25ULL
        }
    },
    {
        {
            0xD3E399A41ABE2FB2ULL, 0x90AAF65381A2B6DBULL, 0xBF504EB6EF9BD11AULL, 0x1214069384C25603ULL, 
            0x665D0F2E06FEADD5ULL, 0x1374B73456F54321ULL, 0xA9D3E80082BB61D6ULL, 0x14A95AB9FE47671CULL, 
            0x818DB92267F9752DULL, 0xB0A5789F71BAE17FULL, 0xBFBFFB3D011F52F2ULL, 0x36EF3E5416933707ULL, 
            0x37C8D58B464BF6AEULL, 0x710B2DBA56255A92ULL, 0x9F87CC4DDDD8F3BCULL, 0x5D773760F9D4C919ULL, 
            0x54D1EC0617072E82ULL, 0x2DF87BF6BB6F0420ULL, 0xFB7815EE46213EB6ULL, 0x4FBBFF2D79AA3ED4ULL, 
            0xCF9867FC4E6BFB1BULL, 0x0DC7AE95ED3B75EFULL, 0xD7D48BB333216CDDULL, 0xC37948FB172B495EULL, 
            0x46A26206CD94AD31ULL, 0x49A3D3D877FEF987ULL, 0x0C472E7772746D9FULL, 0x7A461D99A3C67AB9ULL, 
            0x87DFC90F929A4C38ULL, 0xADEF7CB6FF3A5BFFULL, 0x8A5E6F604FD92BD8ULL, 0x27707D3975014284ULL
        },
        {
            0x5F6CE8EC5C2E8BE3ULL, 0x36CE2B7F1C3CDC9CULL, 0x52BC88CC477E4503ULL, 0x808DCBC4850A81C4ULL, 
            0x9B8E839CB9E6B01DULL, 0x2023F1A5CB17B548ULL, 0xC144347414E08E02ULL, 0x20A2D41B65453977ULL, 
            0x2E6CBF882F6F6239ULL, 0x5D5AB94D0848122CULL, 0xFBBACEBA5AC8D9E4ULL, 0xE9A18D2972C2DAF8ULL, 
            0x6FEAF5D388B32D3BULL, 0xC543A62071B74B01ULL, 0x9E4308806238AEDAULL, 0xAA86B0EB282DC47AULL, 
            0x3466F7095D42F71DULL, 0xD9387344E226755FULL, 0x4578C6134EF72930ULL, 0x05295EC352212AAAULL, 
            0x313FBB10CF49F9B6ULL, 0x087157C99E2523E5ULL, 0x7D754F656318BA25ULL, 0x63693EC48499911BULL, 
            0xC8CFA2036DE6E702ULL, 0x4C3733D2CB4DA4C2ULL, 0x9B22AA57670B117BULL, 0x40E8596DDB6E893CULL, 
            0xB81E0817BE33E6E0ULL, 0xCEB813A3A2411027ULL, 0x7CF80381AD13D778ULL, 0xC88849F35EC89628ULL
        },
        {
            0x00D373BD1BA47374ULL, 0xAC64153FE2629B65ULL, 0x5FF186C5E4C6EA91ULL, 0x97B188B264FAC781ULL, 
            0x97A6B3316FFA1E90ULL, 0x07978AC5306A20D5ULL, 0x87532928B2BED231ULL, 0x48D1B02C72D9FAB5ULL, 
            0xBD08759776A3AC6DULL, 0x652EDAF45A27E102ULL, 0x3AFF5793076A200EULL, 0x8A857FDDF832B5DBULL, 
            0xBB06B80679F4A915ULL, 0xE94B74C004012BB5ULL, 0x953430960933FF96ULL, 0xDDC7FD44F2296B7AULL, 
            0x35C7BD860C1559E0ULL, 0x9BD19BBA83B0BACAULL, 0x1C255B7841BC34EAULL, 0x3A6531225798C105ULL, 
            0xDF9FC56E5E9CA1EAULL, 0xD2B019CD2A6CAE11ULL, 0xD4EA963EB962052DULL, 0x96A8460F5DC7FBFAULL, 
            0xE1307CC56D7EBAA0ULL, 0x6864A1837D3F71C7ULL, 0x26729BB454E81E10ULL, 0xBFE64165E19AA100ULL, 
            0xC3B92AA6475CC0FFULL, 0x2627674042D6DBB6ULL, 0x77A8DFFD0C929825ULL, 0x1D14A1D11899BA06ULL
        },
        {
            0x47FEE39991B404EFULL, 0x93B58D4D2E55D066ULL, 0x0616D80BC50029ECULL, 0x9E6673ACE670B504ULL, 
            0x2BA7547209112841ULL, 0xC00AAF7FD19FECBCULL, 0x2E465B4BB05C6B1DULL, 0x704BF020A3A4986AULL, 
            0xCCFFA64F2DE315B5ULL, 0x79DC7984BCCFC4BBULL, 0xA46F5CBB89A9C518ULL, 0xB57F4218FEAB84D3ULL, 
            0x9BAAF72ADEDEE6A7ULL, 0xDAEAB709504B24A9ULL, 0x7C90F5E3F90887B6ULL, 0x83C23CA9B809DE08ULL, 
            0x2C3DAFFB043B0E1CULL, 0x8B1A6F21C8437F8BULL, 0x2AC1289ADAC99097ULL, 0x673A09BED20C9E15ULL, 
            0x8A27882EDF872140ULL, 0x450FAE6416BF9EB3ULL, 0xB25F1C6631449462ULL, 0x8F5F2FE4C362D78AULL, 
            0xA868CFBFB9E3A287ULL, 0x34DA8CADC0F3A00EULL, 0xBE45924D5EF0ADFBULL, 0x2D1A6B8BD554A9E7ULL, 
            0x582758E950EB3CAFULL, 0x7856A0FF395E7892ULL, 0x2D497D5273250F58ULL, 0xAB197D9C511428E7ULL
        },
        {
            0x6348AE6A02A45FF7ULL, 0x24FB00D768A1DB3EULL, 0x905551CAFB5C7074ULL, 0x7D2F12812EA37EC4ULL, 
            0xCE9617AEEC37ABA1ULL, 0xD78516002CE12174ULL, 0x22F383B2B603EAE9ULL, 0x5C707D7B5D80F5E7ULL, 
            0x51A7DD5D7C2BF039ULL, 0x190922952E47D528ULL, 0x0DC966E7576B4CF8ULL, 0x5D19826A3385B595ULL, 
            0x95B5002E7D76BAF1ULL, 0xB53C010C78507F49ULL, 0x1F44C3AE32081FBFULL, 0xBA76F187892675D6ULL, 
            0xE9143DC6F9B708B9ULL, 0x7307F94D24106380ULL, 0x1878EEB075CE0D57ULL, 0xA8D9E876B40DA094ULL, 
            0xF87DD3DAAA50A560ULL, 0x2301EE5B59C70AD1ULL, 0x65904C30B58C13A4ULL, 0xF0E6C096420F73A4ULL, 
            0xD939A01E00E1D73EULL, 0x3437F5E0DE112FD1ULL, 0x57201C85331DA318ULL, 0x5391B8FCA7387037ULL, 
            0x6D6F2F344B6436A6ULL, 0xA97AB2D9C54F8FE2ULL, 0x96A2FFCFF1997705ULL, 0x8A54F1FC7A283DF8ULL
        },
        {
            0x70E1A127DE850EFEULL, 0x81EEDBD87248896BULL, 0x491D726406FC5062ULL, 0x4144D29491433FF9ULL, 
            0xA605E124EB300EE3ULL, 0x7C8C1C9317103C5AULL, 0x02F5BB8A0CC31F5DULL, 0x679A1BA98F1DA975ULL, 
            0xCC8D9932C7C22E7BULL, 0xB25A625FDD2FC710ULL, 0x39BE28F88761FE9AULL, 0x4A9F668C30153AE5ULL, 
            0x56E9696DC2D41F89ULL, 0x55E1E525A0958D84ULL, 0x8C51E2629976D274ULL, 0xBB115E541D9E64ECULL, 
            0x549A6C9AABC5AC8EULL, 0x8F8F183433BFC1C9ULL, 0x5D54A09908C70484ULL, 0xC5EAB056F6EE991EULL, 
            0x251CB0D6A60BE303ULL, 0x255F4221910CBBD9ULL, 0x4223E25B395938B8ULL, 0x9501BA3429ECDE37ULL, 
            0x890B6F56B578D9B3ULL, 0x5F06358C13D3F6B9ULL, 0x261D4E9EE3AE9452ULL, 0x6F711762CBC34758ULL, 
            0x3EDDE0FC50C3373CULL, 0x9C2BB0BE04529FCBULL, 0x3E816FE283053DE1ULL, 0xD33EFADA78FC99E4ULL
        }
    },
    {
        {
            0x7A7DE1A296E72ABAULL, 0xD5D48A0374F2AA41ULL, 0x97D6DFFBA4AAD4C0ULL, 0x70C522FDD588ADE9ULL, 
            0xCE67D21BCB381899ULL, 0x50320E016966D2B0ULL, 0x80D37E0477C4320CULL, 0xEC759A84D3B12828ULL, 
            0x509071064A608FDBULL, 0xF533F2AF0BFEE136ULL, 0x69F0A512D3288BA3ULL, 0x2BD46048A3C2AF6BULL, 
            0x8AE6873B022C165CULL, 0x33B103636EE54906ULL, 0xB45308B4E393E4EBULL, 0xB2E826DB2FBA4AE7ULL, 
            0x6968658825800208ULL, 0x6F224089E109121BULL, 0xFE99756625A6E2FBULL, 0xC7DABD308BC5A295ULL, 
            0x5E2B2637EEE76D95ULL, 0x1417F5BB515D5022ULL, 0x2BBBCFAB3745EF61ULL, 0x710F694F37CA9AA6ULL, 
            0x33A84E2099EC2685ULL, 0x64D5958B65B37B0CULL, 0x72274A830E059ED1ULL, 0x098B3D76D23B4B27ULL, 
            0x09127EB772382E8EULL, 0x84E953813E48B46CULL, 0xBC9C22848908CFAAULL, 0x67AEF9EAECC8A49FULL
        },
        {
            0x4BAA441A92D6D2FFULL, 0x690FEB13DF98D7D1ULL, 0xD02C0B787DC914DEULL, 0x7F5D711EA41A3BF7ULL, 
            0xB6BC19EDC2EC8C00ULL, 0x4B3EF965BE5DF099ULL, 0xD115EDFEEFA94FDDULL, 0xFF2C911780E4ACDBULL, 
            0xC989720400587D43ULL, 0x26BBB53B90960D56ULL, 0xD8EB1DD22A300971ULL, 0x8BF08A225A35BDD8ULL, 
            0xE5F0CDDA1556F71BULL, 0xC887603E0790A9FFULL, 0x6B262536CDBFDF2EULL, 0xBC6B0F62B4DA5ADBULL, 
            0x5986CB7A997B68A0ULL, 0xB34211554A8B90B8ULL, 0x42F90F70123B5908ULL, 0x0252F6DF8B289D53ULL, 
            0xA827DAC133BB21D7ULL, 0x23714DE4DAA9B6A1ULL, 0x95E923D881984585ULL, 0xA33F1DE0C67B12F7ULL, 
            0xE1183E3B97C061A8ULL, 0x09F73D182F8648F9ULL, 0x188209EBD7FC6F0CULL, 0xBAA7FB865B11C64AULL, 
            0xD81776CB2F443231ULL, 0xEF3E974D7DC5873BULL, 0x6918B608CE0B0EA8ULL, 0xF18EB6AB8DC3BF73ULL
        },
        {
            0xD08CA0382B2D6E4BULL, 0xB0B7B67A7EEA6303ULL, 0xCE52ED4611B944E7ULL, 0xAAE016AF0E2CDFF6ULL, 
            0xBA44C4D0DC65FDEEULL, 0x249720AAECC531CAULL, 0xAEFE58349D7F6840ULL, 0xF7BACBB270765EDAULL, 
            0x73793AE4810B45EDULL, 0x43299277B371E122ULL, 0xC2E21232F8288E64ULL, 0xEE6A1EE3DE27AF2BULL, 
            0x4D279409E1D4243FULL, 0xD35E36E8EB0F6192ULL, 0x9DD1C406DCA6DEA5ULL, 0x37EE0C5C09378DFCULL, 
            0x735B7CBE9250B769ULL, 0xABCD81A3E7AF8BC3ULL, 0xC5F946089789FAFCULL, 0xAB0C61F0EFC06B81ULL, 
            0x4DFDE4AD8492FBE6ULL, 0x05AC34CE92E0C1F1ULL, 0xA68543CC538FE4FDULL, 0x780CB30BD57680F9ULL, 
            0xEEBA34050B1F1847ULL, 0xC898E0687A481BA2ULL, 0x1676D99966BE609CULL, 0xCFE012D68808AF23ULL, 
            0x968776B782A4F682ULL, 0xE4FD6BCE9BBCAFF8ULL, 0x0670DCABAB0BC3AAULL, 0x526A85925ECF478BULL
        },
        {
            0xBF2A63684B7C7287ULL, 0xEF6E93AB364754A7ULL, 0x39B23678A9AD22C1ULL, 0x5F7689F5D7A47CCDULL, 
            0xB4CC8DF3D4A9183DULL, 0xE928B6EE5720C092ULL, 0xCDA0274D6C11C3C2ULL, 0xCD45BC6BCB010FA9ULL, 
            0x15AF3B548B726008ULL, 0xADCC9FF67D3313F9ULL, 0xEFDB413DB8AF085BULL, 0x0AB260EFBFC183D3ULL, 
            0x5A9BC14C8B9F501FULL, 0xB395488CCB8230A5ULL, 0x808DA7A038EB5329ULL, 0xDC2FC96C62D4E131ULL, 
            0x209FBEF0B67A6F94ULL, 0x1521E746E9080A39ULL, 0x30CF0CD6A009F45CULL, 0xD1239F762BEA778EULL, 
            0x8D7B14715D9CD581ULL, 0x3B388B9F510341CAULL, 0x51EF08C00F9521A7ULL, 0x40B8F685225E3091ULL, 
            0xEC50FE115F0F711CULL, 0x13BA8C4D6AA01C56ULL, 0xD7768FCE162ACEB0ULL, 0xA2535003C332D946ULL, 
            0x674F95CA16A270C5ULL, 0xEBB47A5C02674939ULL, 0xD8FBC2378B336330ULL, 0xC904A256ED9E9073ULL
        },
        {
            0xED14A89031F04C1AULL, 0x0A612C8FBE678567ULL, 0xE9DAB56A3DCD176FULL, 0xCF6E0068192B2604ULL, 
            0x4FF57FFE46FBB848ULL, 0xC212F8A4A9D404BAULL, 0x8E65E4941B95A1A8ULL, 0xB9736EF70AF342D5ULL, 
            0xD704427468417D4DULL, 0x68A426032778A3D3ULL, 0xC5C3A1AD6AAF61C6ULL, 0x2A1BA37124E88C73ULL, 
            0x4997A6B0E7248BC7ULL, 0x5CF4014BFB4B7127ULL, 0xD3B80C66A1699A47ULL, 0x339DF74B508B10F8ULL, 
            0xB94D5C57F0DB226FULL, 0x9E6A8A6CC5C110D2ULL, 0x68C4FC33032B09E8ULL, 0xF6A7623C96351AB2ULL, 
            0xF7BCB8B4C7A57149ULL, 0x11FBFE36F503CC01ULL, 0x884038806A3E7C8EULL, 0x6ECA27E0ACA78970ULL, 
            0x029068D1E80B5503ULL, 0xBFC0C23437D71BD7ULL, 0x954C3787C315E2F8ULL, 0x376AFFAB0AEBABABULL, 
            0x926EC8E027491BA5ULL, 0x82483478CA952DB9ULL, 0x71D36456CD1CB64AULL, 0x47C3FB7E2050145BULL
        },
        {
            0x770F7AB6BF8AD9EDULL, 0x1CB4A9BFEA3EF564ULL, 0x7EEC3A25961173B8ULL, 0xB95810CE68A77C84ULL, 
            0x1FF36C4C761C2983ULL, 0xDCF2AA176CE6B145ULL, 0x9A0FA1074AC7FC3EULL, 0xB7ACA8635C56FF26ULL, 
            0xC0458BC75408A949ULL, 0xC014BD23E0A4AB2DULL, 0x82F8BBB88B2866AFULL, 0x1D242855818A61C6ULL, 
            0x6A6954FEB98AF05FULL, 0xB73CDE8F292976B4ULL, 0x580253C5C546A8BBULL, 0x6372224CF4751F4FULL, 
            0xCCFBCDF438B0A3D9ULL, 0xD057798BDC6B68F5ULL, 0x5585CDAB3BCBC6CFULL, 0x1CE44FA9BAA69392ULL, 
            0x670532003AD463B6ULL, 0x3451D66E08BA0785ULL, 0x3327FF065029F04CULL, 0xAD255BD506ECF269ULL, 
            0x9C09B402ED0FC6F6ULL, 0xDD4D1AD5E942CE3FULL, 0xC33C39A7FA9F8786ULL, 0xDE7451636566C0EEULL, 
            0x583896288C92F850ULL, 0x6661C4CD41EEAC04ULL, 0x9408C8BB1F7C229EULL, 0x1D963EF00C75F518ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseEConstants = {
    0x04902EAFE70D6E5FULL,
    0x6A104DEFEB61A320ULL,
    0x9A5D4F16D2491378ULL,
    0x04902EAFE70D6E5FULL,
    0x6A104DEFEB61A320ULL,
    0x9A5D4F16D2491378ULL,
    0xA5F0DD58343D6DAFULL,
    0x553E6DF92BF01C39ULL,
    0x4D,
    0x1E,
    0xFF,
    0x72,
    0x92,
    0x97,
    0xFD,
    0xBD
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseFSalts = {
    {
        {
            0x9C08497F5E87B44EULL, 0xE3628A3775EF739FULL, 0xC1DF318CCFE9BA6BULL, 0x6D30130F8A42C03DULL, 
            0x107ECB0702F05073ULL, 0x89367FEF179670F3ULL, 0x534CEB534C4D28C5ULL, 0x87FD82EA61331ACCULL, 
            0xD4723A52D19AD67EULL, 0x77A0FAFCB951C7E9ULL, 0x42E814157D0CB3DDULL, 0x611AFC7C9D2BEF35ULL, 
            0xE331CEBB45C58F06ULL, 0x8B586CD55A556B3AULL, 0xCF06EF0491AD4F22ULL, 0x5C4C877EC5572D14ULL, 
            0x49EF4E480C67350AULL, 0xB4C588DA896CB1A5ULL, 0x5826E9C7216064F4ULL, 0x72B9936550663040ULL, 
            0x52FBE9FC4F6C0DD6ULL, 0x0C9B91A4A0931E7CULL, 0x0C4C4F15AF1C286BULL, 0xEDA03F2E8B24CE5BULL, 
            0x79A64AC9B627F883ULL, 0x204268F0800B653FULL, 0x36FCFF2666C681CBULL, 0x12E8B0A932A59D08ULL, 
            0x9D1E936079BFCC1FULL, 0xF52C4BEBAE840EAFULL, 0xCB06A01B3B7788E9ULL, 0x8733E0A2A6BF474AULL
        },
        {
            0xBAEC3D73FEFB72D0ULL, 0xE5C2EB1FAF4F661CULL, 0x436CE7F46C2FCA4CULL, 0x8A8CC9A5712714DEULL, 
            0x81BEF3D41D309B94ULL, 0xA2FC4F17142019D9ULL, 0x4D4B7A434585E4CEULL, 0xBC50CF940A7C48E7ULL, 
            0x22BF6388A0BBC218ULL, 0xCA294DB2A672FBF0ULL, 0x6787445FE3878CA0ULL, 0x182D826C9973E437ULL, 
            0xD25D56EAC74872E5ULL, 0xFD46D9AAB453D8F5ULL, 0x0A1A60707E5E2BDFULL, 0x93A7CDAB957425D2ULL, 
            0xCC08557F88672D61ULL, 0x708E2885137E7F6FULL, 0x1EDB6DDFA47C68B7ULL, 0x06EBE3E168E7A2D4ULL, 
            0x51299F68B25243C2ULL, 0xAF8F135F56630A71ULL, 0xDE50C80421624D00ULL, 0x94A3F6A47223A59EULL, 
            0xA29BA209D9F37495ULL, 0xCBF1BAE72004E07FULL, 0xDE03DA40C92E8DF3ULL, 0xBE0F9467BEFEEBE6ULL, 
            0xD73459EA7E5A7A14ULL, 0x387D78848E72C192ULL, 0x2335EB01F5F6C352ULL, 0xA0D551842994A2C0ULL
        },
        {
            0xF54AFC9FBA165B3BULL, 0xCC37F4B938FD3EC2ULL, 0xE50DBAD654ED273DULL, 0xD2F4220FD88D7F3AULL, 
            0x6AD0CBA679B7B6A7ULL, 0xC6793D4E856C0706ULL, 0xD6BEFD600F0AF21EULL, 0xECE6895AF850706DULL, 
            0xBCA54B8E627D2E01ULL, 0xC8B6F7543DFA443BULL, 0x75E1B0C5BA71B6E5ULL, 0x79D38E0132B035CCULL, 
            0x1E376B66B905079DULL, 0xA6475D2A6D1E86BFULL, 0xB75AED7F007C2C17ULL, 0xA2672A410402BFD6ULL, 
            0x9781C86B66784179ULL, 0x7BFAFCA87AAC406CULL, 0x3F83FA795ACE3C56ULL, 0x52F8C6040A60FB4FULL, 
            0xECC6FC5EABB81F6AULL, 0x863667F84830EDF5ULL, 0x90168A841FAEDA8DULL, 0xE39763312AD991C8ULL, 
            0x45DE1C85C7BA4A36ULL, 0xDEEAEC0708238770ULL, 0xF5FB40723BB0B36CULL, 0xAFB48A5802E21FCAULL, 
            0x0355A4B1BD44E99DULL, 0x202A15A005F2DF29ULL, 0x9DD1D7539FE4ADEAULL, 0xEBEC00F32955654BULL
        },
        {
            0x6D1D6A36F8424D5BULL, 0x0DD5F061FF4950D4ULL, 0xAF833CE0859D909DULL, 0x850C32B034DD0BD0ULL, 
            0xB8A7BBF3F5A30386ULL, 0x2CB349CCE841C769ULL, 0xCF93BD0C36C9A733ULL, 0x3D8499745B1C3EFFULL, 
            0x0DA1C6B0561DC39EULL, 0x8A1B72910B4AE98BULL, 0x7F8A3570ACF9AD65ULL, 0xF380BF0F038299FFULL, 
            0x4646D643CA5E0EB5ULL, 0xC81D848438976F1CULL, 0x3403E59125EAF2CBULL, 0x67E1A2D7D84EBB4FULL, 
            0x87A8739D3253C838ULL, 0x205D494AABABFF44ULL, 0xB975B78C785339CEULL, 0x509864F203304EACULL, 
            0x85911F1078A01A37ULL, 0x6413C2CB641D9915ULL, 0x173E9A4397653F93ULL, 0xE167846D4448E750ULL, 
            0xDC39413C83E8FE3DULL, 0x27FD7E50B0EDC0AEULL, 0xE4ACC46561725D0EULL, 0x345CAD492969B9CFULL, 
            0x93BBB9F983861C74ULL, 0x915FECE5EAB36F12ULL, 0xCF9EA9FBC4F0ED42ULL, 0x6AC38F8094644781ULL
        },
        {
            0xA8BC5C501789082EULL, 0x4C1655029459B2F4ULL, 0x2A917EEF26EC539BULL, 0xE6C1B27539CF6B0FULL, 
            0x55FA76D078584416ULL, 0xF35F5D7EAF5FC7FFULL, 0xA218CF13088B22F7ULL, 0xCB7983190DDE7C0EULL, 
            0x145E42B846DF0971ULL, 0x276CCE626CDC1D90ULL, 0x072BF61BECDB83E9ULL, 0xDB5CFBEB3D3AD7ACULL, 
            0x2A4B9D61E0FD36DAULL, 0xD69B4A8BAD2274C1ULL, 0x39D0EAE7258AB946ULL, 0x461ACAEC5DB920C3ULL, 
            0xD15255FED4C9A74BULL, 0xD59986029E0AF311ULL, 0xABD0794BA459389DULL, 0x6BC3386B7BE8DCCBULL, 
            0x2B3C6FB7B0924261ULL, 0xD9CCD25F4A131996ULL, 0x939C0D58615C64BEULL, 0xC1C95652756D8839ULL, 
            0x838AB9E14D2EEE36ULL, 0xA1EB387AF8541E83ULL, 0x01154749E2C96064ULL, 0x3821DE6156B9247AULL, 
            0xF0868717289E6974ULL, 0x59375B87ED69234EULL, 0xD4708D6C2C187743ULL, 0x45FC6F3C63834401ULL
        },
        {
            0x7009B3831B9B069DULL, 0xE6165C4704545887ULL, 0x2C5AD36F1D6A64D2ULL, 0xCCF2FC4AA0BA098DULL, 
            0xD040FEEC9053A5A1ULL, 0x2B862447A998C0FDULL, 0xF1DA0F0D6D9BAD5FULL, 0xF493D783FF5B5744ULL, 
            0x5F6CD34FCE3F348EULL, 0x0CA1CFEC690E1E20ULL, 0x487380D3B3522CF6ULL, 0xB69479D67BB7AA99ULL, 
            0xB86A8B66B576FA38ULL, 0xF1F1FC83B2C4B0A6ULL, 0x8C3F3813F95C0594ULL, 0x78B976DFE97096C1ULL, 
            0xE568B4860CFCA0BDULL, 0x8165CFE346A1D6B5ULL, 0xC592B769ADDF1098ULL, 0x04AD9AF14B321321ULL, 
            0x1BD68BFEDABC8693ULL, 0x9A12D8421596505CULL, 0xF704E7A2CBBA33DFULL, 0xD3133E65A496B119ULL, 
            0x4D7C6D03F10BBD39ULL, 0xA7EAB3BB6D232CF9ULL, 0x037BEB045EE7CDA9ULL, 0x6C8368CB218FC8F9ULL, 
            0xC68DFF840729EEB8ULL, 0x7B725D413291544BULL, 0x45EF39E8F95A5E70ULL, 0x3F6E86AD76AA8255ULL
        }
    },
    {
        {
            0xE76239119A7D8F28ULL, 0xD2DF288761783E23ULL, 0x65D1CD1F269A8A48ULL, 0x6B5475BC1E6BAE6AULL, 
            0xAB619DCFA70FC23AULL, 0x07837EFD5EB61776ULL, 0x3CA95F2B1753C058ULL, 0x65A8D7CE7E2A89A7ULL, 
            0xA18C171B84AC6C9FULL, 0x528E3B7725B0240CULL, 0x2192E10A87C0FDBBULL, 0x09036433CD1854E1ULL, 
            0x9E82D065BD8E5039ULL, 0xD9B07415EF3D8DDEULL, 0x7003139239997683ULL, 0x0A4F75A0EDB791DDULL, 
            0x253A8E95FC71A2B5ULL, 0xE131729B2B94223EULL, 0x9E649A1002AECB04ULL, 0x97CC086E3ED48543ULL, 
            0x55FDF787769DC33AULL, 0x41547EE681AF01B9ULL, 0x70E72C723C336F1CULL, 0xC60ADDD8DED7AE17ULL, 
            0xD84D6FD3DB884F37ULL, 0x6A583BE322A3A041ULL, 0x36184FA942BBA7E1ULL, 0x1BD7670FC91D4E9DULL, 
            0x9485FD9368BBBFA2ULL, 0x80808FC0DC614690ULL, 0x69B96728492EFC33ULL, 0x5504ACF62D47CF3AULL
        },
        {
            0x46F6D8A4D3EA2047ULL, 0x54A09EB4E0097A26ULL, 0x1520B4522439E6CDULL, 0x53128A038A32AA6FULL, 
            0x8D7C927598454F33ULL, 0xE58F06DDDA48E852ULL, 0xEAD2E5A747E6EB09ULL, 0xF59A42DB1C3AB8C6ULL, 
            0x099F2284B8A90DC2ULL, 0x9043E4D21AC1DF4EULL, 0x1F91C13C7FACBD99ULL, 0x0511033D72F2081CULL, 
            0x8BEA0D2243AB9A55ULL, 0x8DD89C754FC624D4ULL, 0x3575D68B3D8FF877ULL, 0x1634411B1B816332ULL, 
            0x559C47E36E1BA356ULL, 0xDC1E38E7490EDEC9ULL, 0x27AE5A282F2FAB7AULL, 0x894796139CF80976ULL, 
            0x45BF7C8F5782A05CULL, 0xFDAE00238946C98CULL, 0x976BF408A241B8F6ULL, 0x2ACF153E3431AC91ULL, 
            0x5BCC7097B15B2E32ULL, 0x722D5F0EFE4E302DULL, 0x7A71A03341C464C9ULL, 0xC89CF7F1AF76870AULL, 
            0xE2AD3EB49F003BCCULL, 0x812E8BAEDC69F80EULL, 0x2FE97E13C5C26088ULL, 0x512313BFAA3FAB7EULL
        },
        {
            0x0699D827229BE86AULL, 0x9C1D5DDA2BB1347EULL, 0x1DA4D15111DD8401ULL, 0xCCCC4589EFFF6405ULL, 
            0xFEF39A2D643D05BAULL, 0x91D7A12369EF6D4AULL, 0x28D37D2AB9DFF159ULL, 0x95BA94365C24D188ULL, 
            0x6E586F048F6EB6BCULL, 0xE1187141C1B6EE87ULL, 0x7DB697FA3FE2A119ULL, 0x2B3BAD29E115D40AULL, 
            0x98985BDF13E1A48BULL, 0x0140243330320329ULL, 0x0815AF2890AF3939ULL, 0xAC700415DBF64548ULL, 
            0x2D82CBB874442B09ULL, 0x10DE2574B2B5F7FCULL, 0xD8C2E5C0A8969F4FULL, 0xDA238D7A836D4817ULL, 
            0xD6752BDC9B625349ULL, 0x8A8454DEC961EB42ULL, 0x9373CB4363B7D4D8ULL, 0xB2580D91FCCA5574ULL, 
            0x188BD5A41AA44047ULL, 0x1DD27721596E7722ULL, 0xC1C510E8038D2957ULL, 0x40BE686C59F3BA97ULL, 
            0xA7C7F1CC437890C2ULL, 0xFDAFF859C5D6BFE7ULL, 0x47C908F4F421987FULL, 0x2E33250FA7A920BAULL
        },
        {
            0x763BF9E5D96C10EDULL, 0x850B1C59339B5DBAULL, 0xB17012BFC5958B00ULL, 0x72D76273F4773FC8ULL, 
            0x313B6A1AA2483161ULL, 0x41171564C1B87DEEULL, 0xC11782E6F27EE042ULL, 0xCC820DB82EA18AC3ULL, 
            0x61A3D6771FCD49D6ULL, 0x3F3FE38AB71712DFULL, 0x0E08C00FE3016565ULL, 0x2DB912DBB6D7B827ULL, 
            0x83F6B8E2DD445110ULL, 0xBECEBBBFBBBE12C4ULL, 0xB76003101A11A676ULL, 0xAD757C2B74E75C63ULL, 
            0x50D33C20F487F1D6ULL, 0x0A4512F6F40D8FB4ULL, 0xE39FE6E5171E6C52ULL, 0xCB321C0A7E57C624ULL, 
            0xC5F568EF6C101AF1ULL, 0x2EBA2E79BCC0D181ULL, 0x8BA35E146FAD0DE5ULL, 0x262CB3BEE1924133ULL, 
            0xDE711A37CB3E1E29ULL, 0xBA65CC8285D21D4FULL, 0xE0CD0C91DA835501ULL, 0xF36CA20A91394CFFULL, 
            0xC30362BD1C3CAE92ULL, 0x0BD2ED4922438AC3ULL, 0x3DECCABB93BA6236ULL, 0x929E60ECA964626CULL
        },
        {
            0xC581B5FA41C99924ULL, 0x1C4E4FFCD305C03AULL, 0xE2CE8C01D91BA98FULL, 0x3B28DA7AE84980B6ULL, 
            0x38EEEFDA9DBA9407ULL, 0x9D742F7A253963EDULL, 0x77D16B940D0A272FULL, 0xF2A188BBFE819DDAULL, 
            0xA2C290A3D5DBB154ULL, 0x023F87D3A0617DE3ULL, 0xC454FF101EAF74CAULL, 0xCE8D0238A74F9726ULL, 
            0x6139815DDC6D0833ULL, 0x76F36BEF82C0DD09ULL, 0x9CAA2DB0CB4D5D1DULL, 0x6B182650A5515A69ULL, 
            0xCA27B01E0C68603DULL, 0x674CF6FEB7393E4FULL, 0xA9650AC2E8D6272CULL, 0x43B3139F2912EE70ULL, 
            0x2ACC329FE2E3437AULL, 0xD8CCB1632C91C094ULL, 0x032D0ACDCC8096A8ULL, 0xD08C3D28AF23DDC1ULL, 
            0x308960FA90199C03ULL, 0x2BD83380FE5C74D6ULL, 0xC3A3045A5236BF78ULL, 0x774C65D53C12AFE5ULL, 
            0x220388560759E5B8ULL, 0x29EF56D2D9F7AABAULL, 0xEBD95B6682C5063CULL, 0x31ED82A83310E8D2ULL
        },
        {
            0xCCAE445ED1C09D4FULL, 0x612D9EE597D67C60ULL, 0xA4E6E28B3A1AF283ULL, 0xA17703887DA2AF87ULL, 
            0xEADC288AF610F3E5ULL, 0x1DE2813768EAEF5CULL, 0x7311847D8C154E95ULL, 0x6DE504FCB04DFE43ULL, 
            0x02F8D7A0EE03A949ULL, 0x496D36990ED10B00ULL, 0x4C290646865F9AD6ULL, 0x17CA0DA536561E80ULL, 
            0x9EFD3266400A6E87ULL, 0xF5066D4EC2BCA9CDULL, 0x9309CDC858ABB206ULL, 0xB4A03B951876BBC8ULL, 
            0x84EDD3266A72F642ULL, 0x81199CFCE9DACEB5ULL, 0xD58E1B8FF2FA1E07ULL, 0x3496B4C9BAE8B989ULL, 
            0xE4AB944C7680456DULL, 0x39AA694F6E27DEC1ULL, 0xEA17A07E7057AD98ULL, 0xE52D976711170EF4ULL, 
            0x31CC51970BBBCD2FULL, 0x99FACED6AEB47B07ULL, 0xF98F53A5F6339819ULL, 0xED00D4A9F2BD9C65ULL, 
            0x1E7A50E4655AA47EULL, 0xF84F5F31400BF6D0ULL, 0x4F52A89D4204C3E4ULL, 0xA5164E82FC91E807ULL
        }
    },
    {
        {
            0x682B570F47A4AF18ULL, 0xB7299B0D7EDD9381ULL, 0xB33C51CC9141F091ULL, 0x447C6C142DA6A9DAULL, 
            0x6AFDF2C69323DFDBULL, 0x680B88701453679FULL, 0x11EC2E085D25B0A8ULL, 0x5826FA79238F0A6EULL, 
            0xA704ED08A0A3B55EULL, 0xB8B2D2178A009E7DULL, 0xD0CCE9CDD38A2234ULL, 0xDA7BB1D5994443BBULL, 
            0xD3275C65D317A2E6ULL, 0x2F4AE9CFE5C2F1F9ULL, 0x1B0823576546EB76ULL, 0xF0E4CE8531971994ULL, 
            0x0D8B59D05929FE01ULL, 0x73117ACFFFBE39BFULL, 0xCE0B994864A709C6ULL, 0x57386DB160CF06E0ULL, 
            0xB8B8445FDFED5980ULL, 0x82D88FFA5A7C5B68ULL, 0xBA08A590F30FD543ULL, 0x9C4276A10570D857ULL, 
            0x27C19D0DEA469EF5ULL, 0x0DEC2D44B7D5AD9DULL, 0x438DE08A310E1428ULL, 0x65C02B40BF3F1BBEULL, 
            0xE905D4FF3F2F12A1ULL, 0x0C5C7F6C8C6EE0EBULL, 0x629DE7FA601F85BBULL, 0x28C14DAE41A4BC03ULL
        },
        {
            0x8DA09A50E188CBECULL, 0x8930FD5944E2A048ULL, 0x4F74C8F1E161C48CULL, 0x3717EFB29D743E4BULL, 
            0x883156B100F29FCFULL, 0x296C4C1E89EE6483ULL, 0x2CC4A8C6482E8725ULL, 0x6B3651206CB3FF14ULL, 
            0x7599827BA6555F3CULL, 0x199A6B4D1366F541ULL, 0x4514A79B90F64379ULL, 0x1A1CE92F1C16763EULL, 
            0x05BE82A1D95335D6ULL, 0xCBE16B8BE0A479EFULL, 0x9947174DBEADD401ULL, 0xCF8D6DA5112F438DULL, 
            0xAB60501BF5DFA064ULL, 0xCEB81ACDA93FA169ULL, 0xCD0E4C8B9C536BD3ULL, 0x40FD89279F01417AULL, 
            0xAC1157D69B18C2CCULL, 0x355BA12346769B58ULL, 0x019E48DEA808C386ULL, 0x09BF40D9B5998C41ULL, 
            0xAB7700DABE2F87ADULL, 0x0DA8CFEFDD180E27ULL, 0xC02E6E261D1CDB95ULL, 0x0BD597D7C9641BC6ULL, 
            0x6C8FE089955F2BADULL, 0xDCE287538F999335ULL, 0xF3BB94E2826DC8DEULL, 0x05B778FF6DD59724ULL
        },
        {
            0x196F52B396872FF5ULL, 0xD036C00740BCF9DDULL, 0x9F56052A982A811CULL, 0x459283D97E5218AFULL, 
            0x8FA7C350773AFEC4ULL, 0xD3F5DEA12939F5DAULL, 0xAD503F02BFA4EB3FULL, 0x98791139E67CC4BBULL, 
            0xA24AA40964FCB8ACULL, 0xDCC5E7DFE99A22DFULL, 0xEAB16BD929D2DF0CULL, 0x0A16D958EE4D4B14ULL, 
            0x194072B333C95911ULL, 0x56A3C2EAEC9AC19BULL, 0xF9E2A0D7657B8FE2ULL, 0x25108696895F3A08ULL, 
            0x1511827B1B2AAB4CULL, 0x0B1532893AF6BA62ULL, 0xD3A4C76531AA89B2ULL, 0xFB2A66D990369D88ULL, 
            0xD7A6C310104F8510ULL, 0xCC858A9FACA2BF2CULL, 0xCEFBCC42C21025E4ULL, 0x22AA61CF5D64FA9EULL, 
            0x9A5160D64F08F075ULL, 0xC01760457891E3F0ULL, 0x5E50BA0655818F11ULL, 0x16A380C05EDF8E82ULL, 
            0xC36921C3C54E4269ULL, 0x995F44328E7D86FFULL, 0xFAEBA5DC93240BE4ULL, 0xC5CEF1EA0F01F44EULL
        },
        {
            0x0E953C09D7205AFDULL, 0x8D2A1ECF7E0F0D3FULL, 0xF2E7944BDF4F2ECCULL, 0xE736716F7CEBF99FULL, 
            0xCA14204BD848283DULL, 0x3A4AEA34C4F630ADULL, 0x3BC085F60B90DCC5ULL, 0x5BEFA02CBD18B8B0ULL, 
            0x058C393C5282D99AULL, 0x38F37F30E5983D5CULL, 0x5D3E71A30C2653A3ULL, 0xEB8C4DABE235BDDAULL, 
            0xEF980AC49B78CA9EULL, 0x392A6B17FD3092C3ULL, 0x3332BA45CD0DE8B0ULL, 0x211CC7DCAC55C86EULL, 
            0x42CC3A0A09E8742BULL, 0xB969B2B187A43F8EULL, 0x59B7E9AFB53F6413ULL, 0x97688A65BAD88734ULL, 
            0xBA84578DE52AC6B3ULL, 0x6F1293F36DEE7F0BULL, 0x779604611DED00C0ULL, 0x73ABC1A2140F7980ULL, 
            0xE0C557BE4885E13CULL, 0x89E2E12A843F75C3ULL, 0x60A4FED0174A8FCFULL, 0xB9C8BA27E6565ECEULL, 
            0x0BBA7D0C27B96431ULL, 0x0E1C1E888748704FULL, 0x62CAF9F5683C6316ULL, 0xA60846A6236559BAULL
        },
        {
            0x1B9ECC7B2911F4AAULL, 0xD831E692D54E3807ULL, 0x14F9C8E5D05CD805ULL, 0x12F64C300A82BD01ULL, 
            0x8B191E80C3C1B744ULL, 0x73B9D7FFEB6F71D8ULL, 0xF56EC8490DAA0CA5ULL, 0xC5D517EE5A16ECABULL, 
            0x2A5DED89793161CAULL, 0xD0453B8128791519ULL, 0x062CCDD93FA1A4D6ULL, 0xFE4AB1C87883A161ULL, 
            0x584BC84C6B6091B6ULL, 0x6D796FF6B1C8423FULL, 0x095AFDECC349E4FAULL, 0x30DB907D45760434ULL, 
            0xEBB8DFCA31808305ULL, 0x3E880E8506A4CAFCULL, 0x0EF4FA0BEFEA5591ULL, 0xB33B5216D2629D15ULL, 
            0x22AA7CDE89E9EEF3ULL, 0xCB7CC934EB4BFE7FULL, 0x05931381B34A40C8ULL, 0x79676C03217F2B4AULL, 
            0xE459F67FB4BDD677ULL, 0x2C028EBADABF2C63ULL, 0x7FA1C9E254045073ULL, 0xFA824B2F50C00468ULL, 
            0x078C508372069A4AULL, 0x2F22391616AF9EF0ULL, 0xAF60EFC076732835ULL, 0x3AC1455F61A49C65ULL
        },
        {
            0x7FB4E042DE863C43ULL, 0x369DCDCC24478C07ULL, 0xAAFF522454178166ULL, 0xAAD54BE9E781F5CDULL, 
            0xC43F20552A0E1C15ULL, 0x43945721596FE379ULL, 0x40E3B5A704F16BBFULL, 0xF60EE46DAE8D7C01ULL, 
            0xD0CD87F0A8756F8CULL, 0xD95CB6E69B7FCAFDULL, 0x92D95D946CF54770ULL, 0x35FC055E81AE87CCULL, 
            0x45DC7CB1F83CB3B8ULL, 0xBEBC5120ACBD7919ULL, 0x6D2C77B206FEC48FULL, 0x478DA98E9F12D2AFULL, 
            0xBB23433A1D477282ULL, 0xE2DF155189B784F6ULL, 0xDFED19C0E08BA8A5ULL, 0x4883986E69ACDB6AULL, 
            0xBA5472CD6F2687DDULL, 0x293F409BC6FE605DULL, 0x5EBE144B10F12EE5ULL, 0xFBBC283C5BF42D7CULL, 
            0x83E38D8152B0EDEDULL, 0x6AB4796D0541A629ULL, 0xDBF76B6C9D3BC1C7ULL, 0x6176AC1577A2DA3BULL, 
            0xFDBBF7106EED2C9DULL, 0x7F69F31F5B08479DULL, 0x46E6BF4C81B73A4EULL, 0xF37DE4E0CAF5E487ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseFConstants = {
    0xE3A36EAF301E2E9CULL,
    0x36D4FA3E364FFB9CULL,
    0xA6D99DBD71CC2C7FULL,
    0xE3A36EAF301E2E9CULL,
    0x36D4FA3E364FFB9CULL,
    0xA6D99DBD71CC2C7FULL,
    0x6D01E68D7C5A6982ULL,
    0x341E104DEF6CF56CULL,
    0x52,
    0x56,
    0xD1,
    0x3B,
    0x5F,
    0x47,
    0xE2,
    0x1F
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseGSalts = {
    {
        {
            0x0E7C4ECCDBB20B40ULL, 0x539B03DBF075CFDFULL, 0x54DE0BFCD258EF3EULL, 0x187ECC016719DA0CULL, 
            0xE580757902587509ULL, 0xE2EBBAEEED697B93ULL, 0xC53D054B3BF8034BULL, 0xC976E2ABF2EBA780ULL, 
            0x61638C8C290C264BULL, 0xC3A5DF3C53A2CC65ULL, 0x53854CB85D6C121FULL, 0xEE413439C2C4036EULL, 
            0xFC12FF855706F4A2ULL, 0x587B9C7059D7F2CBULL, 0xA148011A3297C71DULL, 0xF233F439E17831E5ULL, 
            0x0730657A8638A13CULL, 0x9FAD97FADC923706ULL, 0x21825D9C40E5099CULL, 0xAAA52805C194BCCCULL, 
            0x96D7F82A67B6096DULL, 0x21E3D38B470A77BBULL, 0xE3DD9C532A5170A7ULL, 0x95FAD4E6E7B499D3ULL, 
            0xF7D395C4F2CAF399ULL, 0x25398DF89035928CULL, 0x702C066706726EA7ULL, 0xD4D5C5E5CD8CDC05ULL, 
            0x5D8BB4C05C12FC45ULL, 0xF9D99F2F1440C224ULL, 0x78A5CE03209E43A8ULL, 0x0D9897FD2FD053AFULL
        },
        {
            0xAE88037C9D887F9EULL, 0x529869B803C31393ULL, 0xB85032ABA435EC28ULL, 0x8FD011C6E53D51BCULL, 
            0xD31D1B47C40CBDD6ULL, 0x00E42C731F848848ULL, 0xD924982F002091CAULL, 0x695A205AD8F75565ULL, 
            0x4BEBA32750FF803EULL, 0x8AE75B33D4532BBBULL, 0x1D85EC29244C7C67ULL, 0x9CE4A55D915BCBB8ULL, 
            0xC6CB8E11A97CBAE0ULL, 0xFDDD861850D6246EULL, 0x1FC151AB63268290ULL, 0x4F7D23E8F583E408ULL, 
            0xE5EB9293F642D9FAULL, 0x25BCA49CA9680CE5ULL, 0x6A714B29BB722CC0ULL, 0xD66DAF933CC8CFF8ULL, 
            0x54137A0F97949E37ULL, 0x81BE32998833C92FULL, 0x913A9358359A5C76ULL, 0x8BDC31131D05F129ULL, 
            0x977DC0E44D1FE5C8ULL, 0xBC4AD001758B6CACULL, 0x0B86B68E9FC75100ULL, 0xE460D48AD8E55B9AULL, 
            0xF2F8E7629E334D98ULL, 0xE80F062F1C5A6BE3ULL, 0x1673668B48E79BA2ULL, 0x000FD7D02588DF32ULL
        },
        {
            0xC036CC83C944ED79ULL, 0x12B34149BDE47845ULL, 0x2F327B3D902A7A13ULL, 0x01D94238BEAD4719ULL, 
            0x4212EC9772DCC01AULL, 0x9963CC83C203D1B5ULL, 0xCD1D9B251C621C60ULL, 0xD89641EFB328157EULL, 
            0x2847A216CF9DB475ULL, 0x1CC7DC14C131DAEAULL, 0xD52D1F8C092CB3C7ULL, 0x8314F8688EE851FFULL, 
            0x231A5A0E9A7789E3ULL, 0xDE8C5091CBCADB20ULL, 0x2486C95405FC63CDULL, 0x73BF5ABCA76805FAULL, 
            0x12F6E641CF53415BULL, 0x3C50CE603307FEF4ULL, 0x6728D6599F3FE9B0ULL, 0xD051E8BC6F74511DULL, 
            0x8E6EF63DA6EC99A6ULL, 0xE17EE18A3EB8ED11ULL, 0xDD5612C127D9120CULL, 0xFC818D9DF38681BBULL, 
            0xA6108773AE812C69ULL, 0x2353A304DF3F47EFULL, 0x006B757AB9FD4C28ULL, 0x67E6B5F36C96DE11ULL, 
            0x29EC78D41C24BEB8ULL, 0x04C511C2F44EBCC5ULL, 0x561F561D60CBA30AULL, 0x587133601DB9F400ULL
        },
        {
            0xC05C1FC5D623A8AFULL, 0x676D75D51CB99774ULL, 0x8253936BEA974F6EULL, 0xFE60E96E28226A2EULL, 
            0x7C24C9597C1A96EAULL, 0x37C50F4B155C5DEDULL, 0xC179E8E5DA76C3A5ULL, 0x25D39FF3F3235486ULL, 
            0x4BE7C77B69F4B25CULL, 0xFC37AE767B7469A1ULL, 0xA8AA87BD0108B26FULL, 0x8CB2153D013D2F5DULL, 
            0x43B0593A8A74674CULL, 0xA6A0465EF8B47A91ULL, 0x96066AD30C0A6A2AULL, 0x5D41F9B79EF18708ULL, 
            0xDFB731EF75820E1CULL, 0x5DC1EAF4A5FA972CULL, 0x3A58006FA0F462B3ULL, 0x686A28BA9F045AC9ULL, 
            0x55498F01C9CDEDD2ULL, 0x3E24163BCBFD99A7ULL, 0x8484780A8776FCD7ULL, 0x25628CCBB8E37D10ULL, 
            0xFBD4197639C89D20ULL, 0x9C47668ACD2C844BULL, 0x6D9EF79062E71CD2ULL, 0xE855C98FF6A50ACDULL, 
            0x2BE5381E0D0E5015ULL, 0x787B2FEECAF3C083ULL, 0xCE6A6A7DA9493CB4ULL, 0xF6B2B6268A42B175ULL
        },
        {
            0xD2EE4A2C13B94403ULL, 0x52FC9C5D15BCC690ULL, 0x7BBFB7A86E3CEAE4ULL, 0xECDA965AFAC22A2EULL, 
            0xB53FAC78EC028AA1ULL, 0x2B1A5B8D0CEC3EE1ULL, 0xBAE3918170D8A90DULL, 0x097F0EA7A32E447CULL, 
            0xA0DBBCE010C90B96ULL, 0x12937CE8184E00F1ULL, 0x201C1AB0713F3F12ULL, 0x8DC848AA08985FFFULL, 
            0x7B36B03521EEDD56ULL, 0x5C40F48A8DCD336AULL, 0xBEFB48DFE426B8EFULL, 0x2F0E2DB8646968D0ULL, 
            0xA0F94DA50F30AE24ULL, 0xE7C23FC7C03618E9ULL, 0x8C41AD4E24CED351ULL, 0x73DA9225B086C43FULL, 
            0x29B88BDC955D8055ULL, 0x5E99E4495728911AULL, 0x2BAE36CD2F04DCC6ULL, 0x5E54D6B7F2E59478ULL, 
            0x914A38D6E47E0172ULL, 0xE71C282C4734CABEULL, 0x5763D7F026E4A6D6ULL, 0xE2C04B71936F3193ULL, 
            0xE4A8EA2D93C17C3DULL, 0x184BC789E18AA40BULL, 0xF81BA20CF0C230D9ULL, 0x625D3BE09F3DB5E4ULL
        },
        {
            0xE676D85D5FD4E8EEULL, 0x89C0A7BF57D4B015ULL, 0xD29129DE18D7B867ULL, 0x11974E2D04039EA0ULL, 
            0xD2912623A5D4DDA0ULL, 0x2478680C8B241401ULL, 0x732D9A9EA5589E5EULL, 0x7633641298E9483DULL, 
            0x07805714C79AA02FULL, 0x8AFDE630346EEFA8ULL, 0xB851D497FCEC918FULL, 0x0F72EA1C2B9C0381ULL, 
            0x1DA6724EB4A40D31ULL, 0x659CBC5C8EAB3414ULL, 0xD65439DBDA6E632EULL, 0x78B4A2E95635BC84ULL, 
            0x7031E7A89DA09B88ULL, 0xE5D44707E5DDF9E9ULL, 0x7B02644355F5AA73ULL, 0xD2CD7BACBB325AF9ULL, 
            0x79C2632A2397E1CFULL, 0x5C5DF867D54DC5B7ULL, 0x760C31145F1C735BULL, 0x52B43AAE64497EF5ULL, 
            0x7AFB1BDFF2029693ULL, 0x8D4D3A4735498DA2ULL, 0xFF32A35A2568F50EULL, 0x08B67918BDCA18CBULL, 
            0x9A643D75891C30E1ULL, 0x038EAC894DC34109ULL, 0x7F088232D4E88CA7ULL, 0x7369802037AA8D7FULL
        }
    },
    {
        {
            0xEF188254563D25B2ULL, 0xF172BF11B9241E70ULL, 0xCD8CA5A61890FCD1ULL, 0xB07FABC3AC15F322ULL, 
            0x597781BEA4D24428ULL, 0x625D7A7474D1EF4AULL, 0x231259C23A9E9376ULL, 0x5BDE49B06A700A9BULL, 
            0x179F9A83D44A77BCULL, 0xF0B71162F460107AULL, 0xA8C9C3A7E91E213CULL, 0x002C13592437F199ULL, 
            0xEA572B299AEF0092ULL, 0xCA4D2D2A22A498C2ULL, 0xDBE64F86426C74EAULL, 0x3D2C39A3401649D5ULL, 
            0x95E8B21CAD98750EULL, 0xBF5E63F34F3230A5ULL, 0xB92055BFB8315A3BULL, 0xB4CC636627BBB570ULL, 
            0x975ECF77F1EA02FFULL, 0x57FFA35832C91C0FULL, 0xFB574B2C2361E54EULL, 0xC6E53BBC0436D4ADULL, 
            0x2D1E2423D39ACEECULL, 0x9B78F6A2C26D4F5DULL, 0x898102D0A43F7587ULL, 0x5F95F522858A60EAULL, 
            0x819E9433B758910AULL, 0x2BABC403661E96D8ULL, 0xD5DF2513EECA2E41ULL, 0x99025805FBF1E105ULL
        },
        {
            0x5C867D8FE907827BULL, 0xE188B0B02D3F23E8ULL, 0x0E198CC57FF4BD51ULL, 0xD203150D6D5B9FD1ULL, 
            0x0C3749196D23A4D0ULL, 0x40447608C60B14C2ULL, 0x23DD8CC3F3B4E315ULL, 0x569A2B8E08C14749ULL, 
            0xA8344FCEF127483CULL, 0x6120BF51E8650B5BULL, 0xF815928734FE7651ULL, 0x250DF2088A1C1017ULL, 
            0xC8A763013FAC02A2ULL, 0x4C85D89E4F1BFBA6ULL, 0xD9BA98A749947E8BULL, 0x1BE4F68E891E355EULL, 
            0xD9E02DEF848203FAULL, 0xF098434E5B4E75F6ULL, 0xE95BB612859BBDA2ULL, 0x264EA59DD9810992ULL, 
            0xD91789C628F64337ULL, 0x8B365039EBF64B2DULL, 0x55C335FA83D054AEULL, 0xA78465135EDFA186ULL, 
            0x203CA973ECC0A23FULL, 0xA8692955CFC99179ULL, 0x967E826E44D510FEULL, 0xE86267C7E72025CEULL, 
            0x766556C47540A4A8ULL, 0x5EBC3A36218FF484ULL, 0xA2B16AAB9240B6CBULL, 0x5A38A3EB60F34209ULL
        },
        {
            0x25CB6E8C5447B917ULL, 0x7D47964A37691883ULL, 0x51C03F2D989E6A70ULL, 0x4C19D6D4D8E9E5F5ULL, 
            0x4F83DD938FC1C3E2ULL, 0x2EC1847CBBA467F9ULL, 0xD15805ED3057A298ULL, 0xC6B3FD4537D763DBULL, 
            0x2CE9EB5C962AB219ULL, 0x40F1A80418BB6D58ULL, 0xA18B72FE3EEAD14DULL, 0x30517B7BF8B7F3E9ULL, 
            0x5F502A9355BAAAF3ULL, 0xD07E05CC94028AA6ULL, 0x6690BDEE278FB9AFULL, 0x2B780CDD2634B9DBULL, 
            0x77D4DA53F1D86F13ULL, 0xBB2BDA05F1D1E47CULL, 0x2B0199F26C12CF78ULL, 0x38F9919D9EEAA6F0ULL, 
            0xD48B892E2A22060BULL, 0xAD07BA90FBC85DC8ULL, 0x7A7F7B4DC88BF0F7ULL, 0x95099EF4E0D5CE60ULL, 
            0x03B2DC422AB15187ULL, 0x0737F5C76AF557B2ULL, 0x68A8A2CE491D02FEULL, 0x5D6D6F8D11A8183EULL, 
            0x876EA3F4C4DD9E39ULL, 0x1574269B9A78574DULL, 0x49D1B3FD9175E3FDULL, 0xA044F95EC52B1210ULL
        },
        {
            0x4139916B99BA2539ULL, 0xC0EF0E1F3023126BULL, 0xC5B9D6A725F9FBDEULL, 0xA2FDF7ED5832E83DULL, 
            0x5CB688738039F14EULL, 0xA9299E2C7E2BBA35ULL, 0x564958F7944A9028ULL, 0xC0FBFB502BD69014ULL, 
            0x7F004364E0412A6BULL, 0xBBCA184C15DE0CD8ULL, 0x10C3CB385398C8BCULL, 0x82AAF24564604B31ULL, 
            0x5B6D7D980E09CD2EULL, 0x4CBC281DC8FF9FD8ULL, 0x7816864D2164C359ULL, 0x4DE544DC6FE26081ULL, 
            0x5AB01E93F9B5B5A0ULL, 0x6256A0305EF16139ULL, 0x008D1934B9211E23ULL, 0x2CD2BFFDDC3B6402ULL, 
            0x5D542B63A997B0FAULL, 0xC09F2ABCB56B13B4ULL, 0xBF25D8A661F5592FULL, 0xEB5CB702F97A0C14ULL, 
            0x9185405BE29EAD9DULL, 0x0960ECAE2CA4F49EULL, 0x7C7ABAB55C0B5E35ULL, 0x5A8E38212DE0B15AULL, 
            0x64205AA4502E6514ULL, 0xC8126B80A701BCC9ULL, 0x5D4A2087857546FAULL, 0xC7B8139F2F5270A7ULL
        },
        {
            0xA7A35FCAF20C2E90ULL, 0x5BC0D40BCEDDC2E2ULL, 0x2B61F68BD058B730ULL, 0xB93EF6616F159C00ULL, 
            0xEC5D1D6DF9C6C4AAULL, 0x603B052D1893790FULL, 0xCC5AD0A1A76F4C27ULL, 0xD9A1B3F7294B0C63ULL, 
            0x9D31DCA473BA4DFEULL, 0x0594235FEAE81D3DULL, 0x25F0AB30D26F6145ULL, 0xF7B6C7ABA73EDCB8ULL, 
            0x8C589CCF8177E2B3ULL, 0x341A157D031527BAULL, 0x7D221A1606BFAD49ULL, 0xCE98D7A7CD2919DDULL, 
            0xB80F2F8049BA433BULL, 0x7CDF05EBD5A87E2BULL, 0x9FCE8820583E70BEULL, 0xA6F5FB818AA7883BULL, 
            0x9B0E9778182DC148ULL, 0x45DF44C065466485ULL, 0xE8DD8482318F05C5ULL, 0x6F7B33521C96270FULL, 
            0x73F9DDF88C49D012ULL, 0x937061F5429DFF44ULL, 0x658604D26CD19BE8ULL, 0xE646058B0B0EDA6FULL, 
            0x437D894B60B12C6AULL, 0x3E857BC2C47714AAULL, 0xC5E0D47631E4DDC7ULL, 0x3788BE9AF329D923ULL
        },
        {
            0x86C42C6B0B79B1A1ULL, 0x7FD17B772900B413ULL, 0x036EE7CC3CBC4E28ULL, 0x790B97D45A6875E4ULL, 
            0x02AD0351F67BDA2FULL, 0x29D4C6A1600585F6ULL, 0xF7B04E0D94100CECULL, 0xFB93078CD1DB4C85ULL, 
            0xE23B741B1BB89294ULL, 0x6D4E7C851283120BULL, 0xDF5043239752E88AULL, 0x8F93876843F9B0BAULL, 
            0xCD69A748F5F847B6ULL, 0x84AC0AF322DB56E1ULL, 0xC006F9628FBF06E4ULL, 0x88E1A55B8582AFB9ULL, 
            0x7934A15DAA15C26FULL, 0xEB52AC5985EC9CFDULL, 0xE0B73D45793E6808ULL, 0xA4A0CA8C02A8DA39ULL, 
            0xABF3A410989880E3ULL, 0x4EFB35A48BA489D6ULL, 0x6570A18EEDFFC664ULL, 0xCFC1733B6720B99FULL, 
            0xF5DC7663D1C36B1BULL, 0x56E1C0DCAA1609B3ULL, 0xA62B52782E12DB4FULL, 0x83CBBA4F4E690362ULL, 
            0x61A233AC5C5203DFULL, 0x5CA30F70A4507FA1ULL, 0x00B1378B46077B38ULL, 0x3405F0B059A0FD10ULL
        }
    },
    {
        {
            0x3D7B3B094563B79AULL, 0x627525D4D9169510ULL, 0xED2C673C35F149BEULL, 0x31C2A5713C0D7946ULL, 
            0x80BE5B8ABEAD6434ULL, 0x68B2C6191C6198A1ULL, 0x8A79D4CEC2A008A5ULL, 0xF1F8AEAF993131C6ULL, 
            0x1AE70A0ED7306A13ULL, 0x4038FCA66B5FCE72ULL, 0xE2B9185847C2D02CULL, 0x4E7120D50D322B98ULL, 
            0x3C6E4F8EEBFC7C04ULL, 0x6910B1EC16FED552ULL, 0x59861B114F5F76EBULL, 0x942DED4E7FAAFF48ULL, 
            0x3ABD318D0DD68A06ULL, 0xF3844480493AAB4BULL, 0x93C31A4965F7A04BULL, 0x95B0FD22393D5F23ULL, 
            0xC0A5EF6FC69D6EB4ULL, 0x40CADFD5219CE5F8ULL, 0xA7312485CEFCA58BULL, 0x1294BA09F746AA10ULL, 
            0x578B247C3F7EB67AULL, 0x87609DD7B481491AULL, 0xFFB0C33F93D7BF91ULL, 0x86099804CB35764AULL, 
            0x952E0A53D6246DD4ULL, 0x1C67142FAF3253D5ULL, 0x2C84CF0E14CDC270ULL, 0xBCB6C410973B89AFULL
        },
        {
            0x79F74E8CD85BB779ULL, 0xE742B4A29B38D769ULL, 0x343F239A0A3BD1E4ULL, 0xF5BC746F0C0825D0ULL, 
            0xD7238F84060CFE41ULL, 0xBE25346D9117D6B1ULL, 0xF3B2638CBCCEE7A3ULL, 0x4383EA7FF7A84BC6ULL, 
            0xA827B53CFBBE5DC3ULL, 0x95F4D1275E49F9AFULL, 0x7FA58C5A27B500E8ULL, 0x17D33C57E308297FULL, 
            0x29D2B7CB8ED0811CULL, 0x6F05711EC127DE0CULL, 0xE5DB160412B4818BULL, 0xF4AA908D3B4303E5ULL, 
            0xA0B46C01E6FF2D4EULL, 0x00C489837FBA9F9FULL, 0x7DACE01EB5AC7EFBULL, 0xBED766674731D047ULL, 
            0x524ED77654776E28ULL, 0x4C513EA76E822EDBULL, 0x0940265E9E3ECAAFULL, 0x647FD3F2E75659A9ULL, 
            0x755C8A60FD21A276ULL, 0x5ADD0CDADC3EABB7ULL, 0x5B143C02CBDE6EA4ULL, 0xD2AD57C087082641ULL, 
            0x427877BE908260D4ULL, 0xD40BB7C37882EA73ULL, 0x559F8C3A6D2A6C33ULL, 0xC896CC99E2634AC4ULL
        },
        {
            0x168DEAA46F68433EULL, 0x09845BB74E055849ULL, 0x40D8302DDDB62789ULL, 0xF1DA3FB88DE21940ULL, 
            0x63B0380442ACA051ULL, 0x2336970B678AE4ACULL, 0x49265B4BEB1763CBULL, 0x3AC588124CF0EF21ULL, 
            0xB5DDE1FEA1C7B7D6ULL, 0xCEDA22611A31D3A1ULL, 0xAAAA737F0E884475ULL, 0x5753506A3EB6EC12ULL, 
            0xCC87D0371DB0177EULL, 0x5E1B91CC50FE7003ULL, 0x5CDD0482BEC3C09CULL, 0xFCE7FD35EB9908EDULL, 
            0x438CD178B92A80A4ULL, 0x031D08DCC439A463ULL, 0x6BBBA2D82628D6B3ULL, 0xB2373EAFF5CD270CULL, 
            0x8BBA9B8862C71402ULL, 0x4D0638C90F03739FULL, 0x18AE140E47EC9EA0ULL, 0x17DF4478258ACBD3ULL, 
            0x200831411C16E90BULL, 0xD22305D8B17C8C05ULL, 0x59E642CB82D66F44ULL, 0xBCD0555871DDE87EULL, 
            0xB85B6676374F6D44ULL, 0x870EF04AF8A41FE5ULL, 0xAA2C33DEAE89D824ULL, 0xE3F3B2AA97E6C10CULL
        },
        {
            0x1BEC5B1E7AFC5F43ULL, 0xDEB284DB4B9EDD33ULL, 0x7308FD476ED4C3EFULL, 0x4C191F60DF023F8DULL, 
            0x546257CAC0AC2C3AULL, 0x4977666A9C053172ULL, 0xB3F65E3C9397EA24ULL, 0x355EF9DA6F0C7D7BULL, 
            0x3FAAA1973B1D892BULL, 0x39CC7FC33C86952BULL, 0x102B889783ACAB9AULL, 0xEA14689FF4FD6355ULL, 
            0x73A5D0DC14F6FA25ULL, 0x988EC83B184A6F9DULL, 0x8A2F816850449AA5ULL, 0xA773FC367EDE34DDULL, 
            0x3FB14BE148CD67F7ULL, 0xC23AC4A835E2A45DULL, 0x8407128F4CD5E0E9ULL, 0xD8E915D2D52F031BULL, 
            0x98576BB33240FCBFULL, 0xD1486CA2F985EDB2ULL, 0x76B8CB589783FF71ULL, 0xEB6145DC0E8905C2ULL, 
            0x2523706C06AF53D4ULL, 0x269908F4F64E46A6ULL, 0x088A06E903DDC5D7ULL, 0x9FD0CB02C7925A1EULL, 
            0xDF9DAD287D78BA27ULL, 0x484472E487EC0ACEULL, 0xB394406F28705D02ULL, 0xA82F529CD43F879DULL
        },
        {
            0x06A053DA860E0B8DULL, 0xF023D66D339E740FULL, 0xD0B517A9D19322DDULL, 0xF0A48EB0C4144CADULL, 
            0xE30EAB24DF923BFBULL, 0x69F6689373EE80A1ULL, 0xB528A152F36943FBULL, 0xD7C534B84BF6D49EULL, 
            0x8C8BC74DA78CB1EAULL, 0xFF2B584A781F1A45ULL, 0x0B3CA7DD1499CA88ULL, 0x3BF65801AB005382ULL, 
            0xCC3B3EEE76D94CABULL, 0xEE125143BA94B82EULL, 0xF261A2DE8839DBAEULL, 0x8A298EE0B34F4F06ULL, 
            0x984B300E719308A3ULL, 0xC61D05C3A1D0C564ULL, 0x2AB3FE50297F43C0ULL, 0xBD410EF9EFA2C183ULL, 
            0xCFCE30E50387C80BULL, 0x41570C0FC12D8F72ULL, 0x7C0161D4F86A631DULL, 0x2347778E3782383AULL, 
            0x5D158D8F59D206CAULL, 0x432C714C969CA527ULL, 0xAECCE0E9E7C23F2DULL, 0xA8A4181A65EBDB4EULL, 
            0x70C20A601ECFB3A7ULL, 0xED9120545FED6733ULL, 0x99E6F8EBB58C2765ULL, 0xF8493CA40041B2C8ULL
        },
        {
            0x9EF2DAB7681CCD25ULL, 0xC7CED33687AC8AD0ULL, 0x0BBB9D58B1A390CFULL, 0x16D2ABDDC1876838ULL, 
            0x5289C6EF88F62BFFULL, 0x04DAF1285DFFEBD0ULL, 0x9A968C4BE56FE07DULL, 0x9EABB30C30685A40ULL, 
            0x4C734C1BB5C6CE32ULL, 0x33C745E76D648853ULL, 0x8DF751EA757637ADULL, 0x47D5E9C1C8E1A1E3ULL, 
            0x50976BB2D20DED7DULL, 0x3E8741E0384DA95BULL, 0x93E0793BB003FC5BULL, 0xF0BA7C67975EAC0DULL, 
            0xD8E7151CD678967FULL, 0xD61525BAB8722976ULL, 0xFCA85A4FEF1F9723ULL, 0xCFD43F8623A29637ULL, 
            0x313D03FA8EA054E7ULL, 0x8DD2DE8822415B6AULL, 0x75C5B3FBE19CA29FULL, 0x31BE15F138D85AFEULL, 
            0xD7C534816921A10FULL, 0x043D846A827A7CD2ULL, 0xCEF8E39E5C8B7850ULL, 0x7CAB8445694DD470ULL, 
            0x205A3734BE248298ULL, 0x91D10068803C95A0ULL, 0xA97A9CB4037BB5C8ULL, 0xB212E624392D166FULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseGConstants = {
    0x1AB999503ECC9281ULL,
    0x1DCFB927977C42DCULL,
    0x360D978FCB8C9583ULL,
    0x1AB999503ECC9281ULL,
    0x1DCFB927977C42DCULL,
    0x360D978FCB8C9583ULL,
    0x76024B7EB4A73BABULL,
    0x0806CF5FD9102F37ULL,
    0x01,
    0xE5,
    0x9C,
    0x66,
    0x22,
    0x05,
    0xC3,
    0x8E
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseHSalts = {
    {
        {
            0x4797C46548EE6F2AULL, 0x4DE7A382080B3F02ULL, 0xA1FA6ADF081033F6ULL, 0xA23094CFD7FA2DB2ULL, 
            0x58B354F20982DE56ULL, 0xEA26F91EE740F007ULL, 0xD43514369B77BD56ULL, 0xB806AD858685350DULL, 
            0x8A403BDB0BCF67A1ULL, 0x37439B2C0F2F807EULL, 0x1708BFA3AA7A7998ULL, 0x00FE89753DA58EFDULL, 
            0x2DD4951804B17B0AULL, 0x563A917D30F0D93EULL, 0x838079043B4E8768ULL, 0x03D038627EAAEA33ULL, 
            0x42C22EA82C40542AULL, 0x1DA7577FB8E7AAC5ULL, 0xF3EB5723C1D3B876ULL, 0x55EC2324D194B415ULL, 
            0xF228139AEFF848A9ULL, 0x570A1F3366DA819FULL, 0x8B3E21DA16F0B88CULL, 0x349D64E46C209908ULL, 
            0x0391A46378FAC57DULL, 0x2EA2C509F8CC815CULL, 0xB1FE8A5B5DB2113EULL, 0x5923084BF639868BULL, 
            0x92946F3281D9A4DCULL, 0x509EC74C1874A24FULL, 0x404AF1240C8183B4ULL, 0x1A866765EB860B27ULL
        },
        {
            0xDF28DDC4F0886F24ULL, 0x98056143FFF9F4E7ULL, 0x192B4BA154531752ULL, 0x7FA7FC0FCAE38F2AULL, 
            0x7BC18D84FE9A6B46ULL, 0xDF96DD7A73399D68ULL, 0xBBD6275FEAF7B93CULL, 0x50B51B123CC26FBCULL, 
            0xD1876F5AB8B2C163ULL, 0x7F77FFEBAFDA2E92ULL, 0xD8BD206BBED6A6C5ULL, 0x48B9DF8EDD507844ULL, 
            0x95CC675A6AF510E2ULL, 0xB4E2C270D8BF56E9ULL, 0x54BCB57038127890ULL, 0xA44B24D8C9DBBF49ULL, 
            0xDFE85DD9DC36D7B4ULL, 0xE371894344D5862BULL, 0x6BA92FFECA3C1F69ULL, 0x37A90AC19C403967ULL, 
            0xE27BF71C4767E57AULL, 0x0E8BC700B4A3B6E4ULL, 0xDD56C2BF8C7500E4ULL, 0x6A80054BC09D3DBAULL, 
            0x1368ABC9CE1F77D0ULL, 0x004302AC8D147EE9ULL, 0x8DD40333B3C0852BULL, 0xD57D970A99DD96CFULL, 
            0x772E5F94A8C90EBEULL, 0xB844F5D1DC62DBBAULL, 0x5E7DC5232A2D1E6EULL, 0x2F9FC0FEF4529062ULL
        },
        {
            0x1078E1E53E247366ULL, 0x0116DDD8BA67EE29ULL, 0x26EEBEAFE7068FC6ULL, 0x9A042D330FBF6BE9ULL, 
            0x9344AA9BD52D83C5ULL, 0x1CE3C6BFD666E834ULL, 0xCA43594F262FC6BEULL, 0x997DA2523F535D5AULL, 
            0x151316AAA0C3DA66ULL, 0xB1241351A657924EULL, 0xA97EAD9BA62C8836ULL, 0x4FF73647D145963BULL, 
            0x16AEBD2FCE4CF4C3ULL, 0x76974CD705C5787CULL, 0xB2F1EF28FB05AB55ULL, 0x8F8FB641A9AA935EULL, 
            0x5195A555DC33579BULL, 0x7573F5EE58F6D9EFULL, 0xEA765250FAC58F83ULL, 0xB7E743A6D21493ABULL, 
            0x13DD18BA59CEAE6CULL, 0x4919035D5BB9A212ULL, 0x4F513EE34A3AFFA3ULL, 0x372F389BD5DE27FBULL, 
            0xFB6AD779204D33AFULL, 0x5CC355F96ACC14E0ULL, 0xAFB0390908E222D2ULL, 0xA3CA50FBFB5F784AULL, 
            0xCA227F7B9F401639ULL, 0x571CC4B3EDF081E2ULL, 0xC60A1FD0FABD9C06ULL, 0x597C69226037167AULL
        },
        {
            0xD2C33394DD2F4BFCULL, 0x6E5D67FE60B41392ULL, 0xFD7CEDB63C6FDC03ULL, 0xD6FB9516E9A7235EULL, 
            0xBFECFD4EDB4B3B9EULL, 0x205185F6C7C65531ULL, 0x9D49A195FF2CA960ULL, 0xA498B9DF15090C4BULL, 
            0x106BA441A26E126DULL, 0x2F112166932F60A4ULL, 0x00BB2986CF715349ULL, 0x67AA57FCDA427533ULL, 
            0xFB094805A72C4561ULL, 0x36128228AA6A54E3ULL, 0x00E3CA7FCC5B612EULL, 0xBC63EAF68050A46AULL, 
            0x1908BFEE59765E76ULL, 0x94DE8F43F65E162DULL, 0x237E9E02FC34C25EULL, 0x116E970F40968E83ULL, 
            0x8A537A9E424D6725ULL, 0x61ADEF21533AE53BULL, 0x93E2EC414363CF8CULL, 0x2AA97A8BD3A24807ULL, 
            0x070E507398E3FC0AULL, 0xB33C60EDFF5F7040ULL, 0x74A9C3B530DDAF12ULL, 0x5B5C96642CCC501DULL, 
            0x9EADF82D920859E2ULL, 0x93FA44DF71E952F1ULL, 0xC7D44D84B6E36B63ULL, 0x76F4F06E05DB540CULL
        },
        {
            0x5CAA0522ECB5FF36ULL, 0x8A683D157A5C8B9DULL, 0x157CBFD3A87FADC7ULL, 0x26F52962D6F7BDE8ULL, 
            0x1369181156DB5EA0ULL, 0x81BC022B453C010EULL, 0x27E8341E10DEA83CULL, 0x6DC701F6ED4DEC13ULL, 
            0x1D75A72EB33D311EULL, 0xF75C272AB085498DULL, 0x9F1726D2DB57253BULL, 0xEC3778E1D1A08A91ULL, 
            0xAA12942284D66030ULL, 0xB0BD91B950AF6808ULL, 0x914697E9B6ED7143ULL, 0xFC334F7F0E9C4F7AULL, 
            0x4E770A2D632C4564ULL, 0x1FFFEFAD7771F88CULL, 0x98849634884ECADAULL, 0x30BEBEFD02AA0AD5ULL, 
            0x2FCFCAD549152220ULL, 0xB84A1827EC18947FULL, 0x4EFEE3F9CFFD0334ULL, 0x8733109788603622ULL, 
            0x896D95019BBC96F3ULL, 0x5E0401F638969272ULL, 0xDE91C4A66B572D5BULL, 0xEF192A6257DDA293ULL, 
            0x415B000D96FAA471ULL, 0x3CFE16346643D6E1ULL, 0x27E1A4C4D059A727ULL, 0x1C3678739AF777DBULL
        },
        {
            0xA1872264F4A2CCB2ULL, 0xCCDF6A4596153B52ULL, 0x9A0EACB1B5B2E35FULL, 0x76EC79235F99A3A3ULL, 
            0x3988F66802BC5F8CULL, 0xE89EB4DBB4E3393FULL, 0x0DED0665304067A8ULL, 0xC71CC43699D37B15ULL, 
            0xF6F13D4F15FB4DEEULL, 0x6CDC5EAFBEF22561ULL, 0xE426A94813DD750FULL, 0x40E94BA003DF8AFAULL, 
            0xFDE97BC7280A8C78ULL, 0xD7E795B853EB9543ULL, 0x43885E25DEC8EE9EULL, 0x530135DB624FD056ULL, 
            0x28B3D08FF9857165ULL, 0x617FE671332CB872ULL, 0x7462836F963DFA70ULL, 0xF239E2A0A677377EULL, 
            0x536988D7DDABCE6FULL, 0xE7513596CE8C558DULL, 0x9C2D59DF2969F01EULL, 0xDAE6B2D1C14B4691ULL, 
            0x848B334C813E3EB4ULL, 0x434133CD321291D4ULL, 0x57CF6F0408505617ULL, 0xA151673E7AB9264FULL, 
            0xD9A3A3E7034122A1ULL, 0x5607542822C03A74ULL, 0xD26476CAADB83717ULL, 0x78801AA7AF6F97BBULL
        }
    },
    {
        {
            0x493D6A61EF91CF52ULL, 0x96AF20A3B5DF25A8ULL, 0x2C5F98BC3F1F6A2BULL, 0xAEA449676843E4C8ULL, 
            0x530741CA2CC47533ULL, 0x29E209A416E01F59ULL, 0x6FC12B2B8584E8A4ULL, 0xC53A27B66F81F601ULL, 
            0x5EA39C2A38D66D83ULL, 0x79786B6D41FBC8F2ULL, 0x5E1D12345C8E775FULL, 0xAAA015051C921351ULL, 
            0x411B804FD2453676ULL, 0x4F63F9FDCFFBD7E4ULL, 0x1AB3DC660D26C98EULL, 0xDF8AE7E544B92D4FULL, 
            0x4DA1D1C96CF58079ULL, 0x4CFC2A0303EA54F7ULL, 0x99676E16FC705A0AULL, 0x91B788DFE29DB120ULL, 
            0xA8E776F21A4449F8ULL, 0x4138AD2248965784ULL, 0xF1D9CA6CDBA5DCF5ULL, 0x5DD451B6970590F0ULL, 
            0x9E33F5DA179C2A8FULL, 0x14FE58BF47BE5A4DULL, 0x0066A94DCE938F8DULL, 0xDD6436081F56A128ULL, 
            0x59D87E2114371C91ULL, 0x650688224666F272ULL, 0x085D6C60A5AF96E8ULL, 0x3AAB10D6DFDDA379ULL
        },
        {
            0xBEF6839463FB7E4FULL, 0x33422399732801ACULL, 0x1B4421E6407DED64ULL, 0xDC3AD93F98775C5DULL, 
            0x6E76D1A9B87B816FULL, 0xD2FE16DC90A3F71AULL, 0xA6DFB5121007CBC2ULL, 0x947D4BB1562D4175ULL, 
            0x07190241B533E0F8ULL, 0x5A994F7720D562FFULL, 0x45B1A070D98C6EDCULL, 0x7D885E3E202C3A56ULL, 
            0x5FBA6E1BD9B58AEDULL, 0xC59BEE22556157A2ULL, 0xDE5E61B8498C4675ULL, 0xB6C16B10E4F9D933ULL, 
            0x43CAEBE42800A552ULL, 0xAE14C15DDEC4CEDBULL, 0x5D656838881EF867ULL, 0x8D2A83F996F553C3ULL, 
            0x6E9F2EC28074E96FULL, 0x89CC990311334DE6ULL, 0xD8912285E52B8608ULL, 0xFFFB60E04BBF572CULL, 
            0xA90D1DC72539FABDULL, 0x988E9A83738A0F01ULL, 0xE9E4706A2C36E684ULL, 0x5E05B580F0B715C7ULL, 
            0x6E93E7B56CF49777ULL, 0x65614BEC5B18982BULL, 0x9BB81A5283FC54FCULL, 0xD8E980DB38E8E42FULL
        },
        {
            0x176EC2822E5BDC32ULL, 0xB0A84EE73B1BEF10ULL, 0x486F8730A71CB986ULL, 0x2324570D5DD560F9ULL, 
            0x77D2A4A6A253DA07ULL, 0x3EEABEB635DE2EA0ULL, 0xC6708B168F281FB5ULL, 0x392D1C7B019C97AAULL, 
            0x91651038497007B1ULL, 0xBE4012756257FA5AULL, 0xB84BD58F428EA564ULL, 0x909744B8E5D22961ULL, 
            0xB827552A47BE767AULL, 0xBEE82113FC9C9771ULL, 0x6A5914544E3D9777ULL, 0x90F9C8A8761BD99BULL, 
            0x8476D33A7550BA4FULL, 0xD5388AAEAAEB492FULL, 0x3AD7DDA21E5823D3ULL, 0x78BE9977956CCE5CULL, 
            0xBBAE689C4F03F843ULL, 0x4643BDE2B0A26E50ULL, 0x813A70253F8BBEBCULL, 0xC4FEE34F76BB8246ULL, 
            0x5889A9E3468F18F1ULL, 0xEE613E23A6068AB3ULL, 0x44E6F6537754E85DULL, 0xF6BB7E49893C5789ULL, 
            0x5F0545AB677427F6ULL, 0x93AF155E3371E89CULL, 0x9E5BA1EEC7574C18ULL, 0x96272DACCE214C61ULL
        },
        {
            0x974D3BD403F5BD89ULL, 0x9797B291991ECF74ULL, 0x18F137335158FB97ULL, 0x011BFCAB83BAAC1CULL, 
            0xF84F4B2B4DE98FBFULL, 0x6E778AD7B0DCF3FBULL, 0x94C529A45AA4D888ULL, 0x36AF51957C7E0C95ULL, 
            0x48200C0D0D713551ULL, 0x8A7591929A670751ULL, 0xA5F561FA0899DE1EULL, 0x83686AF066D9A643ULL, 
            0xA66484635E762CA7ULL, 0x3952F6ECC1319196ULL, 0x8686655C43792350ULL, 0x23F3D1388AA29F49ULL, 
            0x1BA835E1B4EF4B21ULL, 0x6CDE612806B6AA2EULL, 0x6F47217232A8B32FULL, 0x125BB7E2B0520A3EULL, 
            0xB7D3DD7F7EB85FE7ULL, 0xEEA3EBDE8D8676BEULL, 0x16867F1227BC2BB0ULL, 0x87FCA6C05625F1AEULL, 
            0xB8900AC198ED7667ULL, 0x1528D868063BD8DFULL, 0x6FF7EF19FD9AB99EULL, 0x8FE357BC3ED4E244ULL, 
            0xE419292F93BBB7C6ULL, 0x50CB0428489319ECULL, 0xF150BB873303629BULL, 0x2DB8F54E87E05C78ULL
        },
        {
            0xE4A98D588B088BCEULL, 0xE2ACBE40F4D92306ULL, 0xB9973C6C62EF1EB5ULL, 0x15D33B4C63BF0CACULL, 
            0x0732A6417BFFBEB1ULL, 0xA73B7235940FED20ULL, 0x037D5198BDE67715ULL, 0x9CF5479C5F038DDBULL, 
            0x865638BA260EC41CULL, 0x35D96D8F5594662BULL, 0xC1C90D3B4AD36E67ULL, 0x76E3913AF1440B49ULL, 
            0x7A3AF67046DD3EA3ULL, 0xD0C21EEDD090C4EAULL, 0xC07480CCE79F1CC9ULL, 0x1F7D02FF5AB26777ULL, 
            0x8A511DB6B89CB69AULL, 0xCA6747157F92E1DCULL, 0x357534F7C55E3891ULL, 0xE3EBD98092A978B7ULL, 
            0xADCC48C7B9677BDEULL, 0xC6AB6B1263C6158CULL, 0x2DF18463D5A557C2ULL, 0xAB7C26405BE43F4EULL, 
            0x904D4361289992A0ULL, 0x69A80DA2D1444032ULL, 0x9B1AEEDC53ED8BB4ULL, 0xA1F6D98D13F9192CULL, 
            0x0E219FA45EBBF63EULL, 0x4E585C250BFD24EFULL, 0xF468EF546679E535ULL, 0x6D962867F1B66F2BULL
        },
        {
            0x37ACC8B26AF8E3BDULL, 0xE11B325F5750720AULL, 0x79397A22E992A0C2ULL, 0x9A1BC650656FCEDDULL, 
            0x20304B36DD43C876ULL, 0x33AAFDBDA02C03FEULL, 0x1C56981F6B342C04ULL, 0xA20C75D035A1A7DAULL, 
            0x383F0A9A04B533F5ULL, 0x1B60130C3E422106ULL, 0x4539EFB288EE415DULL, 0x1B9AED95DE346FABULL, 
            0xB754DF0CFAF2D902ULL, 0xA85C1650F780EFE9ULL, 0x38F23355C434DF34ULL, 0x23A5E0399E1CA2F8ULL, 
            0x52CB7A0D4B5652E0ULL, 0xFFDC1EA548A2268CULL, 0x7A5E0CB63C39F02AULL, 0x03B85F29EAE3890CULL, 
            0xA63081A2A4927416ULL, 0x645267D62D46E076ULL, 0x61BF0462D9E32B24ULL, 0x939CA9308113DAFDULL, 
            0x6AA796CD628EA35CULL, 0x089109AEB6AE2762ULL, 0xED49C19A566BD288ULL, 0x7F17146C17A2F9ACULL, 
            0x943D0D8E6AE6F57BULL, 0xE7BFB012B33C2065ULL, 0xA0D3B34F087D003DULL, 0xBFBAB61F420C8199ULL
        }
    },
    {
        {
            0xCE46A981832265FEULL, 0x1734DB218F02A31EULL, 0xB3FED1CD509BE32FULL, 0x30C044EFE7C5E24BULL, 
            0x94BBAE35C3535D65ULL, 0x3954F432CB8494B0ULL, 0x730AB20D45ABC034ULL, 0xAFA7C88FFD4B51DFULL, 
            0x3684E2B785A7FA28ULL, 0xBA327B131F22ED90ULL, 0x66FEFE0760953E49ULL, 0xA2F516987ED6A33CULL, 
            0xFD815F3F2971A0AFULL, 0xB0B9909711812ED2ULL, 0x53AB09E781EDF4B4ULL, 0xF4483EB9C1F5564CULL, 
            0x44C0B8928D1F4852ULL, 0x968DC0784DC5B7BBULL, 0x6D07572572443446ULL, 0x6E142BC3D25566CDULL, 
            0x0B53FD8419139D25ULL, 0xDBF44EBFD6130670ULL, 0x93DE78A160E1AC68ULL, 0xD4DC31474A4E8086ULL, 
            0x17F1E428E9AFBD87ULL, 0x08A8BCDD51FFEE3CULL, 0x8D08D50AE0195ED3ULL, 0x515E311540C5113AULL, 
            0x80F4283973FDB2E2ULL, 0x8B1739A1C1EC4A32ULL, 0x6973CC2ECB73BF1CULL, 0xBD6EF5076FC14DFEULL
        },
        {
            0x890B326720E4367FULL, 0x3620106C39FA0354ULL, 0xEE520DCFE72D394CULL, 0x0AF44AB61033CAE6ULL, 
            0x627A3CCCC2DFEE56ULL, 0x038146C4D8CC0162ULL, 0xAA46F7695D1FF8FEULL, 0x1D971E07E4DFF1F1ULL, 
            0x4D2395380F92DAE4ULL, 0x43DA5BEFA4E735C8ULL, 0xC0FEFF4FBE6CCD61ULL, 0x7710131F38ADA018ULL, 
            0xCA2802E41C14DC25ULL, 0x738EDBFB62D06A2AULL, 0x466B8F59C5167095ULL, 0x3777F613B76B8CFBULL, 
            0xE68414E8C9FDA645ULL, 0x93B2B50FB5A7AC30ULL, 0xE6B0A5AC809165CDULL, 0x9491EF0CCE0039E8ULL, 
            0x81EF0D25346AC780ULL, 0x98541A91727F66CBULL, 0x628110D6A1F3B042ULL, 0x7C068407B7902AD8ULL, 
            0xE90C186F32D6211CULL, 0x6BAFA0E8343641A1ULL, 0xA17C0C0E6616E865ULL, 0x6F8408CE3803F7A1ULL, 
            0x220623E781739D76ULL, 0xC716F8C4EC623150ULL, 0x241FF26F0DEA3E2CULL, 0x188A8E9D4EA8EC56ULL
        },
        {
            0x7452A22F849C5F34ULL, 0xF7FFFD7E7C8649F4ULL, 0xDFBE0D630BD5E699ULL, 0xA4956F25A82A6C9AULL, 
            0xA076123D7E77E068ULL, 0x3C34E0B5894790DDULL, 0xD0487390E3D56A9EULL, 0x1693ED53327B97FCULL, 
            0xAF702E85229A6B2AULL, 0x32CD29DCF0534119ULL, 0xE8210FF0F9656D3DULL, 0xB9476B13943F1116ULL, 
            0x25A00CBED6DAD78FULL, 0x662476F695AADCEFULL, 0xC7E8396E9A016F3FULL, 0x6C1A837DB8A8D9DEULL, 
            0x1A17B0C4F205F507ULL, 0xDA82408E2C29A22BULL, 0x6E4FD0B9B5E6E57EULL, 0xB8E743FCC1541667ULL, 
            0x80F8A6C7B6895F60ULL, 0xB8B436B003C43BACULL, 0xC0CC0F72D5FEDE87ULL, 0xD901FD3DCBFD4421ULL, 
            0x5529C1EDF162C299ULL, 0xEDADABF0DF59C271ULL, 0xB891EA888659B8E3ULL, 0xB0F27F62F6E68AB9ULL, 
            0x212800CA5878876DULL, 0x01F307EB29A4E7A6ULL, 0x4434230730DF7634ULL, 0xA490E5188DFA7C05ULL
        },
        {
            0x8C683E921678FC4AULL, 0x0EE5EDA93DA595C8ULL, 0x5BA20BC2B71BD413ULL, 0xE3D714636CA2150CULL, 
            0xB86ED7F28DD0E48FULL, 0xFF9E8BF549ADD46BULL, 0x7D0D20FB2DB7A543ULL, 0x8ED338B0D6159705ULL, 
            0x48E6C106F4BF590DULL, 0x27E9512FE0C8204AULL, 0x17BFE6415E60C0AEULL, 0x25A9D95D4B72D1FDULL, 
            0x5921F0180A47B3C6ULL, 0x8E3B211D7DC4C5ACULL, 0x8EAC621DCED05205ULL, 0x2587BCD7725AD823ULL, 
            0xEB179FA17356B6B0ULL, 0x999722D08222BB9EULL, 0x40F3EC705C624CE3ULL, 0xE5FB4F98E1E4D90BULL, 
            0x56C242E26B270170ULL, 0x9B38FB0D83F9747BULL, 0x8C9DAEE6C2B51F1CULL, 0xD1DAE7E464817D6DULL, 
            0x03F8226FB56954DEULL, 0xF86019175CA607E8ULL, 0xC64EBCF3FAD5F983ULL, 0x8D06DEAAD315E371ULL, 
            0x5726927C54D9AFA1ULL, 0xAB4639424391ADD7ULL, 0xD83670146EE2F4ADULL, 0xD2D773D146D5DF81ULL
        },
        {
            0x1DDCA4DBF86983EDULL, 0x19FCBDB2299A1A8BULL, 0xABB230BC226AB155ULL, 0x52002EEA19D1125DULL, 
            0x367B0811FC5397E3ULL, 0x5B6B7181250496A1ULL, 0x1F575DD4B1475B90ULL, 0x13A3C4190B6FFBD8ULL, 
            0x0E8131614219CDA1ULL, 0xD411344176508C9FULL, 0xC9EB6AE960346DE1ULL, 0xE0787A9F7DAEFC4CULL, 
            0x9ACC904AF4CDA4DCULL, 0xD21A11D894E9687DULL, 0xFAFFD40C65457E1AULL, 0x31FD2DBBE3E35AC9ULL, 
            0xBF3074956F9B3A0FULL, 0x0943BCCAC3B031A8ULL, 0xFA95F05572B71027ULL, 0x250C758D805D3A21ULL, 
            0xF86B66123464D3D7ULL, 0xDE3C58EDDCF24415ULL, 0xB38167FBE1B5D63BULL, 0x78B14C857C5AFE60ULL, 
            0x6E0CF6556FA05C0DULL, 0xA4B3D3BF7C4CFF8AULL, 0x5EBDE30E5E4A572FULL, 0x40FE4EFB5FB6E531ULL, 
            0x4CA9C119A01A60B9ULL, 0x4E59F855E49C2F1AULL, 0xD3C851307171A343ULL, 0x5C0AE4180C99F9B6ULL
        },
        {
            0x8EB073B371F43D3BULL, 0x849ABB07D43C3372ULL, 0x56717767EDD7C53DULL, 0x39CCC15CB0500BEDULL, 
            0xBECA4A82532BA376ULL, 0x5C5B1D57027414FBULL, 0x802A48E34E8F99B6ULL, 0x4649DBF651CBA8FAULL, 
            0xDE495A48EBB5C320ULL, 0x51823304EF16BE35ULL, 0x6AABCCEFB021298CULL, 0x6D0FBB590225D0E4ULL, 
            0xEC3A2E435DC52687ULL, 0x0B49DFB41A914552ULL, 0x3DFFF5BC10668D3FULL, 0xD347A00D89E123EBULL, 
            0x706E83FE5173DED8ULL, 0x9E697BBA26158EABULL, 0xC45FBD633CB31421ULL, 0x09CABEB80620A0DFULL, 
            0x5A95F52026CB5C6FULL, 0xF79826EA97F2B4A3ULL, 0x302DFBC47EF09E0CULL, 0x652C30D50104B4BEULL, 
            0xC23300C1AB33C70EULL, 0xDE34890DA153A86EULL, 0x156647696455FC81ULL, 0xD47C25C68031EB32ULL, 
            0xD0B3A1110174A6D2ULL, 0xC5CA1E6CFCCDA6D3ULL, 0xD6DAA0371A24BE71ULL, 0xFA623EBD2CABDAF8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseHConstants = {
    0xF322576E1F7EB292ULL,
    0xA8DBF8DFF84771A4ULL,
    0x354FB3636592E5E2ULL,
    0xF322576E1F7EB292ULL,
    0xA8DBF8DFF84771A4ULL,
    0x354FB3636592E5E2ULL,
    0x3B5468A27C318438ULL,
    0x82FE236F80BE5698ULL,
    0x30,
    0xFE,
    0x3E,
    0xD6,
    0x74,
    0x40,
    0x53,
    0xC3
};

