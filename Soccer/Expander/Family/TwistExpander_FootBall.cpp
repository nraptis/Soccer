#include "TwistExpander_FootBall.hpp"
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

TwistExpander_FootBall::TwistExpander_FootBall()
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

void TwistExpander_FootBall::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet);
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
        aPrevious = 12567093800628588606U;
        aCarry = 13326518036339017148U;
        aWandererA = 12844954500849297992U;
        aWandererB = 10382297642888781652U;
        aWandererC = 11151269087988674815U;
        aWandererD = 9446939688504437915U;
        aWandererE = 11988834896218855266U;
        aWandererF = 10707010042430454597U;
        aWandererG = 13548010341206101394U;
        aWandererH = 12104897987125773492U;
        aWandererI = 18324229423857302460U;
        aWandererJ = 18324148663860167877U;
        aWandererK = 18034432131191697446U;
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
    TwistExpander_FootBall_Arx aArx;
    aArx.KDF_A_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 mSnow,
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
    TwistExpander_FootBall_Arx aKDF_A_BArx;
    aKDF_A_BArx.KDF_A_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_FootBall_Arx aKDF_A_CArx;
    aKDF_A_CArx.KDF_A_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_FootBall_Arx aKDF_A_DArx;
    aKDF_A_DArx.KDF_A_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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

void TwistExpander_FootBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 11595764814554827889U;
        aCarry = 17942659863630814059U;
        aWandererA = 10142285518540849864U;
        aWandererB = 14110118191400470631U;
        aWandererC = 12698576667285045035U;
        aWandererD = 9771449154759830331U;
        aWandererE = 10262393505522723215U;
        aWandererF = 11307055207032035239U;
        aWandererG = 9241486321377036498U;
        aWandererH = 16162950473890609274U;
        aWandererI = 12699212428335863403U;
        aWandererJ = 13230702152431991678U;
        aWandererK = 11160056335769594968U;
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
    TwistExpander_FootBall_Arx aKDF_B_AArx;
    aKDF_B_AArx.KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_FootBall_Arx aKDF_B_BArx;
    aKDF_B_BArx.KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_FootBall_Arx aKDF_B_CArx;
    aKDF_B_CArx.KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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

void TwistExpander_FootBall::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pSourceInput,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pSourceInput, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr) || (pSourceInput == nullptr)) { return; }
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
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneA);
    }
    // KDF_B PhaseA invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneG);
    }
    // KDF_B PhaseB invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    }
    // KDF_B PhaseC invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseD invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseE invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    }
    // KDF_B PhaseF invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseG invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneE (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseH invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_FootBall_Arx aSeed_AArx;
    aSeed_AArx.Seed_A(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_FootBall_Arx aSeed_BArx;
    aSeed_BArx.Seed_B(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_FootBall_Arx aSeed_CArx;
    aSeed_CArx.Seed_C(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_FootBall_Arx aSeed_DArx;
    aSeed_DArx.Seed_D(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_FootBall_Arx aSeed_EArx;
    aSeed_EArx.Seed_E(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_FootBall_Arx aSeed_FArx;
    aSeed_FArx.Seed_F(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_FootBall_Arx aSeed_GArx;
    aSeed_GArx.Seed_G(pWorkSpace,
                 pNonce,
                 mSource,
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    }
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_FootBall_Arx aGrow_AArx;
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
    TwistExpander_FootBall_Arx aGrow_BArx;
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

void TwistExpander_FootBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_FootBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_FootBall_Arx aTwist_AArx;
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
    TwistExpander_FootBall_Arx aTwist_BArx;
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
    TwistExpander_FootBall_Arx aTwist_CArx;
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
    TwistExpander_FootBall_Arx aTwist_DArx;
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
    {
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    }
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
        TwistExpander_FootBall_Arx aGrow_AArx;
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
        TwistExpander_FootBall_Arx aGrow_BArx;
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

void TwistExpander_FootBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 1 with offsets 5150U, 5797U, 5422U, 2065U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5150U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5797U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5422U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2065U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 1, 3 with offsets 6864U, 6043U, 5047U, 1237U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6864U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6043U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5047U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1237U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 0 with offsets 3482U, 5863U, 4523U, 4045U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3482U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5863U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4523U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4045U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 2 with offsets 4065U, 2184U, 1319U, 373U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4065U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2184U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1319U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 373U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 449U, 1538U, 385U, 54U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 449U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1538U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 54U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 2, 1 with offsets 597U, 275U, 1008U, 1394U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 597U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 275U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1008U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1394U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 1, 0 with offsets 1024U, 1693U, 1416U, 1051U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1024U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1693U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1416U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1051U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 0, 2, 1 with offsets 900U, 171U, 240U, 279U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 900U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 171U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 279U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1108U, 1330U, 1456U, 682U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1108U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1456U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 682U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_FootBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 3, 2 with offsets 4184U, 6188U, 2175U, 3465U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4184U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6188U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2175U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3465U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 3 with offsets 1113U, 5290U, 454U, 7291U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1113U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5290U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 454U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7291U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 0 with offsets 8161U, 4724U, 1235U, 8024U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8161U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4724U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1235U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8024U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 1 with offsets 5466U, 3571U, 1459U, 30U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5466U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3571U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1459U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 30U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7294U, 3541U, 7468U, 4818U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7294U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3541U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7468U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4818U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 0, 1, 3 with offsets 141U, 1060U, 130U, 1900U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 141U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 130U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1900U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 3, 2 with offsets 1963U, 616U, 389U, 1556U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1963U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 616U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 389U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 2, 1 with offsets 1879U, 607U, 1693U, 1788U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1879U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 607U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1693U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1788U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 3, 2 with offsets 1253U, 1077U, 686U, 620U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1253U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1077U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 686U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 620U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1008U, 47U, 824U, 236U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1008U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 824U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 236U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseASalts = {
    {
        {
            0x6B21AA5641F86702ULL, 0xFD29E6D1010DA62BULL, 0x125E84031DB096B4ULL, 0x4005EB87CE1A7B39ULL, 
            0x50665F0BDDD84281ULL, 0x526EB3BFC815876EULL, 0x6A33394F86832C43ULL, 0x7DDC3495ADF5FC70ULL, 
            0x49C9E43AEA3269FDULL, 0xEA649DD056DD9A57ULL, 0x675C76C72F478CA2ULL, 0xED6C13D01FD195B9ULL, 
            0xBC573CCBEE289FC3ULL, 0x9A6BF39F7CDBB02BULL, 0xEC6D4E21231DAFC0ULL, 0x608480B86DC065EFULL, 
            0xAD3F83D001DC207AULL, 0x7DF9CA0C2D812BA0ULL, 0xB0C2EAC880D2E794ULL, 0x2029650CFC98489BULL, 
            0x293C35CF78D589F0ULL, 0xF26710990F191022ULL, 0x5E14705607FB8010ULL, 0x7422ECBCF333E042ULL, 
            0x39364E28058B8537ULL, 0x7930BE30DFC9887CULL, 0xE168E13314E2163CULL, 0x8AC82A7619D4DDC2ULL, 
            0xA7EE09BC2D10117DULL, 0xF5DDDB604CF4F337ULL, 0xB98AC13AB177EB1FULL, 0xD4C32D8A27248CC8ULL
        },
        {
            0x6C01CEF303EBA38EULL, 0x6E10D1F430C4D484ULL, 0x3CC79D0960A33713ULL, 0xB9E610EB999EA0FDULL, 
            0xB918C0D39DF37C72ULL, 0x5ACCAD47BA7FBDF4ULL, 0x8E5B844A97FEC6C1ULL, 0xBD01DAB2B40E3802ULL, 
            0x4970ABBA930906D9ULL, 0xBFA4572CF8E02021ULL, 0x80F790EA2CDDCC7DULL, 0x0B10476B4983364DULL, 
            0x4CB5930F4F87F6C4ULL, 0xB8A1729E81EAAC8DULL, 0x41123A4A0CFE5520ULL, 0x976F742DDD6F625DULL, 
            0xE55A04D093FA1C50ULL, 0x1AF7AA8C9E6F201FULL, 0x080AC1A94DA00CD8ULL, 0x4E163318943D2340ULL, 
            0x3F153E5AEB828E79ULL, 0xDC9C74EE2D1CC05AULL, 0x55A82C4CA96126E9ULL, 0xBE0CBF8B997AF94BULL, 
            0x681EAE0328BAA598ULL, 0xA28B214B6EB41548ULL, 0x09BE30860541156DULL, 0xADCE67187B570D81ULL, 
            0x50C1D179F4B4F8EFULL, 0x69E13CE596D706C8ULL, 0x2714D1799F672D85ULL, 0xDE82FC18DB3637B3ULL
        },
        {
            0x3802D7295BACA9DDULL, 0x3F3B88636DE0AE29ULL, 0x926C2E1EE42CEC25ULL, 0x7E800D95C86C7DE3ULL, 
            0x2D8513AA9874AAA8ULL, 0x6175846ECE556691ULL, 0x25F3B9C5CB82D7DEULL, 0x6A11F4BD127C1E03ULL, 
            0x514EA1C5C9A18376ULL, 0x8C1C53CEA618A430ULL, 0xAF46403CF4908846ULL, 0xDDF11948F96B6CD5ULL, 
            0xDBA9985CA700683FULL, 0x5651E6FC84851EF7ULL, 0x10634F4E3963AB1EULL, 0x7725B14AD0531D79ULL, 
            0x849AC915B51C4D0EULL, 0xDA2D9F81C31B05C4ULL, 0x5D2ACF2BA398FE20ULL, 0xBBFBD94118FF4B24ULL, 
            0x7D0A13E0A35E80E8ULL, 0x31C5CB0AE648E661ULL, 0x6170DF3BA583270BULL, 0xA8AAF679DBBE9E4CULL, 
            0xB3BE2093B8006BC2ULL, 0x695C41FD808DC7D2ULL, 0xBDCA769AABB49969ULL, 0x585E0FD20E612795ULL, 
            0xC7094EEDF6344FE8ULL, 0x83D671BF3BF9DACDULL, 0xFA463C2CCAFC7E26ULL, 0x88CF333278D22289ULL
        },
        {
            0x56B3A6A6F571CF55ULL, 0x83CA0575878586FAULL, 0x55F850E7022C8F34ULL, 0x102AA9FCF2E0DAB8ULL, 
            0x05964823A62216DDULL, 0x822292ECC98DA063ULL, 0x2898EB231ED98673ULL, 0x622A5566523CA076ULL, 
            0x948F1C6FD7F7E29FULL, 0x498DEAC7DDC9F4EBULL, 0x4FE8B0F8AEBECF5EULL, 0x37CC58845B02590BULL, 
            0x41CE66FE1CEEB6FEULL, 0x4F12A3E278B2C4F8ULL, 0xC56E920538ED78D6ULL, 0xC0E24FAC5A867715ULL, 
            0x904BBFCB35D1F55FULL, 0x07D46FBC26D2F96CULL, 0xCB0BD6E3FB1E633AULL, 0xE4746EDB66371AFAULL, 
            0x347BF76C789BB0C5ULL, 0x3C761D658FC20ACAULL, 0x9AF3E57E4AC3FFE0ULL, 0x94D1045CA27793CEULL, 
            0x8A3EAF14D2778CE5ULL, 0x85074C1C18C87046ULL, 0x5BF730FDF070C7FAULL, 0x958F30D4DA6D4D78ULL, 
            0x41E282C48BD76FD6ULL, 0xECCF22127FCF113BULL, 0xF2D039567529E668ULL, 0xEF5B8BF6C0CDDD94ULL
        },
        {
            0x5EAFCE9E2D36DA04ULL, 0x078C9AA57C26B7B5ULL, 0x907C09AF0CE5E5BCULL, 0x814E7EFDF01968ADULL, 
            0xECFE3039D6815922ULL, 0x500487D3422F95A2ULL, 0x2A1C8510176A9965ULL, 0x028C25883338F37CULL, 
            0x6C25FD1877834CE9ULL, 0x63308A48B71854DEULL, 0x69A0A1AA8BB8C0F7ULL, 0xE5211DA717F406BBULL, 
            0xFCD911E455C144BEULL, 0xD8636C8D2CF377B2ULL, 0x34973E88A5448F53ULL, 0x084B06561C14B7BBULL, 
            0xC587D3C7D765E9C6ULL, 0x15EA62C966C2DE05ULL, 0x48A71F301CB71BF0ULL, 0x637C120CA4076326ULL, 
            0xFAD29607FDCC16A4ULL, 0x7F0E236D774C3BE0ULL, 0x57F4BAA61A3866EDULL, 0x2CA9D1B19BCF25B4ULL, 
            0x348BD820153F7F4CULL, 0x5179B2D5259AA22EULL, 0xF3FE34E6BEEB419DULL, 0xE542BA1BBF612AFFULL, 
            0x981DD6B5CD92038AULL, 0xFC9882C4BA0012C2ULL, 0xD8DCF1988C5EDD59ULL, 0x4818FC4158A5797AULL
        },
        {
            0x7C3EB660040255C4ULL, 0xD5AAB2311F1182CCULL, 0x73710561EE3ECBD3ULL, 0x19951BCC1997BAE1ULL, 
            0x2FF5A296D0DE119BULL, 0x2A2CD04B2962764DULL, 0xFAA4CC190EBBA0F3ULL, 0xF96C18CBB9C5AFBFULL, 
            0xC9B79DE44282D597ULL, 0x5608EAC077CE3DB5ULL, 0xECC3A258B9915B66ULL, 0xFD6F4043C7284E99ULL, 
            0x6F0443AAD1C1AC6AULL, 0x0262E545BE8DF624ULL, 0x85AF7D4055031366ULL, 0x97B49B6FE6CDAC88ULL, 
            0xCCA3C43C56B0934FULL, 0xB966484D3E2A4230ULL, 0x3B410CC5075B7A34ULL, 0x99A30988175A5352ULL, 
            0xA7EF5B7A1FE174B2ULL, 0xD4C50524102525CBULL, 0xDA3786A6721A2F5BULL, 0x9D9E347657D12653ULL, 
            0x44AEC9750D93CAA2ULL, 0x95E23BEEB86C38D5ULL, 0xE939B084A57B0286ULL, 0x4A080A9E4334895DULL, 
            0x4E5401BF506A0C45ULL, 0xA4BD48EBB9B612C5ULL, 0x9980E09A5E255616ULL, 0x344F597F3EE4C26DULL
        }
    },
    {
        {
            0xD990D73A935C9B7BULL, 0x47DB3CA420F972D2ULL, 0xB06B0C39405E1300ULL, 0xDA508E516D334690ULL, 
            0x39CA7083BA1A5660ULL, 0x6C58B95E3ED146B5ULL, 0xB685765EEEAC4CFBULL, 0x966D1039610A211FULL, 
            0xB6769788FF4E606CULL, 0xBAF2C568487C3173ULL, 0x290CFBDFB470B82FULL, 0x9AF54A146B368378ULL, 
            0x0D4A6B20C3B107A9ULL, 0x0429C0866AD8A664ULL, 0x728D4896D12316C0ULL, 0xE9DE89E251F7573DULL, 
            0x298FE2775C8CDD84ULL, 0xA73BF1F65F37F928ULL, 0xFA8DA9FD5DA436B4ULL, 0xDC0BDFD10C3D4B4BULL, 
            0x2B3D5A3385FA9DABULL, 0x94EE50379D46E597ULL, 0xCD21A1CDAF8AC62CULL, 0x1CE68D9240E5E4DAULL, 
            0xDDFE5277EAA9E3ECULL, 0x620610B1F3470B29ULL, 0xBE2610D4E6A74331ULL, 0x5BF2940EB9F5EB66ULL, 
            0x7CEEEC49FFA63B3EULL, 0xBD91F2A6418B420DULL, 0xEE4EB2E849B69260ULL, 0x283DD90994F498CBULL
        },
        {
            0x4976A2A34AD1E123ULL, 0xC0FF301D7BE4214CULL, 0x8BC35FDBC424B20CULL, 0xF59B0BAB6CFA9E8DULL, 
            0xEF8F7827B53E4BA4ULL, 0x22F60102B64BEA8CULL, 0x119DCCD5762E74A3ULL, 0xCF9BD39059386EA5ULL, 
            0x4E207C50FC780BE2ULL, 0x6D9F62D5596FEADCULL, 0xCE2B655BDE37ACE4ULL, 0xADC0668B3E089420ULL, 
            0xB92F663D7206D65EULL, 0x63E83B3E63CA82F7ULL, 0x4B7D31B1D7109FACULL, 0x9E03EEF15B4233CFULL, 
            0x4F91B1C30E9B1DCBULL, 0x816458F15D84F49FULL, 0x9FECAD6C512F818AULL, 0x9903677B2CF2EBEAULL, 
            0x07D841C3006E41D0ULL, 0x9AFF075165B24EC8ULL, 0x667BF6F16B81324CULL, 0xDFB03D7A806F7245ULL, 
            0x5ADB43B56B85546FULL, 0x87C0DD8CF5ABD800ULL, 0xAE3574C4058817A2ULL, 0x97C2BAC307B48FCEULL, 
            0xA0FEB3CED0760519ULL, 0x70C618F2FAB7586EULL, 0xDC91BB7B90BEBAE8ULL, 0x686F7902F3093DEDULL
        },
        {
            0x86A9F3A4BC421A9EULL, 0x8C3C4CE32B8AA872ULL, 0xAB0FCE2B0F8D7BA2ULL, 0xAC46332D68F0EF8FULL, 
            0x7C6027EC5A3491F1ULL, 0xA2C428398FF41C51ULL, 0x6760C91F83B4B36FULL, 0xC4B249B533E3FF3EULL, 
            0xB60566C38E8F79B2ULL, 0x2B8C0FC786317C44ULL, 0x6087D90215144B2FULL, 0xCEB52FAF2051D23EULL, 
            0x2BFF2DE686599CB5ULL, 0xFDF4B576479769A5ULL, 0x8EADD33449BD9C2FULL, 0x28205B0B6B4A0F57ULL, 
            0x10E8B89341D78FA7ULL, 0x28A1BB0FD3CF330DULL, 0xC7F4E8F1D564D4C9ULL, 0x08D6FD747B4AF4D1ULL, 
            0xA6F933F332BF7E8EULL, 0xDE10D2E26365F4A7ULL, 0x022BF955FC5A17AAULL, 0x3F0FB9A7F9A706F7ULL, 
            0xFEB261C495AB9881ULL, 0xACE11A3D06E14322ULL, 0x5DF57E36999B4651ULL, 0x6F8DF67C1315C565ULL, 
            0x1EB470DBA6368229ULL, 0x261810E7A467E418ULL, 0x82B90C537AC6BCECULL, 0xFDEC707D6568ED3EULL
        },
        {
            0x7E9842C3728C1A66ULL, 0x95034A78D55EFCB5ULL, 0x8D6727DBF3009388ULL, 0xD7C0D8A4C3B75F9EULL, 
            0x7DCFD109EC8FC566ULL, 0xA0F2F3B01CB7897EULL, 0xB16624607AC3338CULL, 0xB263164A4582A3E7ULL, 
            0x1F10BBF1B0B01CD7ULL, 0x1EB3036CFDA4F3DDULL, 0x8B48E003B4725D5BULL, 0xF573D97CD3050A89ULL, 
            0x3F882E005DE26008ULL, 0x50FEB6A90F7A81FCULL, 0x9261E6F58C7ED67FULL, 0x69411368413D33B7ULL, 
            0x60FB137AFA9ADA5BULL, 0x9DA9EE7865642C9AULL, 0x2E37E2DF8BF49B9AULL, 0xCB93FAE710479D70ULL, 
            0x537783CE5C4BE131ULL, 0x831DC2D280795096ULL, 0x45765FE4B2B70966ULL, 0xE01B3C0C56EA868DULL, 
            0x51FD747190CC0E0FULL, 0xDB726791780995E5ULL, 0x987E7C817839772EULL, 0x6A39674BC4138774ULL, 
            0xD2B4D94F6F8415E3ULL, 0x70C141E8299B9B34ULL, 0x3FDE175BB6E36F25ULL, 0xE9A3A9454E45BCF0ULL
        },
        {
            0x9B99C329DCBE6771ULL, 0x52A7C7AA1B24534AULL, 0xA32E8CCB6747549EULL, 0xABAAD12ABACF6488ULL, 
            0xAE912E39DD14AFFEULL, 0x7911C2B259ED4DCFULL, 0x5F637CFA1B8C443EULL, 0x80E1DC377E84AA18ULL, 
            0x3CA708EDF58DFECEULL, 0x2E9333417FBA0042ULL, 0xEFE72B4819FBE922ULL, 0xE57D6EE2FED50E2EULL, 
            0x3DD57179E62C3CCEULL, 0x6A57AF6D125BFA6DULL, 0xC25183515B316F7CULL, 0xD574802A9265F28CULL, 
            0x7955D7DCBAF7D116ULL, 0x13C6DA4AAFB1921BULL, 0xB98D757A44D0BEF5ULL, 0x8E0572CD59247F32ULL, 
            0xEC48C5741BA1DD68ULL, 0x21A703A0ADDC6F10ULL, 0x00376F0CE953F183ULL, 0x187E3AC7AF4FD167ULL, 
            0x239A2E127F25B997ULL, 0x7154D52574C3C028ULL, 0x43A204D987640331ULL, 0xE5600AEB407208B1ULL, 
            0xDF66CC08B6F615CFULL, 0x51AB2B08E3741B0CULL, 0xED0DD70FA9E4D2D3ULL, 0xC98FE26E7B58316BULL
        },
        {
            0xFFA9F7ABA52E5631ULL, 0x6E3C77182FC9F38DULL, 0x1D2C70AA1AF2C885ULL, 0x0C0D272039FFBA39ULL, 
            0xF6840BA1A6F7D94FULL, 0x9A38F8676171F22EULL, 0xE4B1B1813FD30D99ULL, 0xC1CE80DA4B816AA2ULL, 
            0x587987BBE2D9CABEULL, 0x6DF3FF7F804AB12EULL, 0xDDB99D930457BB85ULL, 0x4FCAD2833B154F11ULL, 
            0x46E96F75ACC72554ULL, 0x86AB409A764B2E40ULL, 0x753AFD3B0335A9BEULL, 0x384BA9B63028801DULL, 
            0x2DF6B84AAE2BAFFFULL, 0x0E886952975A5E36ULL, 0xB0E993C8C408A138ULL, 0x182A78822974C42AULL, 
            0x430FA6DC24A0F341ULL, 0xC7F9BDFE16F3A331ULL, 0x7508BFABA1F8DB25ULL, 0x4B87231CB589C4D7ULL, 
            0x909BC036B143DFDCULL, 0x0F5DFD5148E37D2DULL, 0x953AE3FD752BEB88ULL, 0xF7F588AFC5BF157CULL, 
            0x380F41C8721AD880ULL, 0xE964DFDBA4A604B6ULL, 0xF2E4B02C1F9D621DULL, 0x8F238F16BE838E0EULL
        }
    },
    {
        {
            0x34140BF529001531ULL, 0xDF190E22D6881369ULL, 0x51D1B2E9F0C4C4D4ULL, 0x7865D251881F0ABEULL, 
            0x7FD463709D364B23ULL, 0x734B1FA2C70CD8AFULL, 0x6D62A9648C728DD9ULL, 0x123EC1AB96EA8CDCULL, 
            0xF8CD555126CB0E1DULL, 0x47D6BFC06271E842ULL, 0xC4E3CD11A2E48CF6ULL, 0x853C30CE6D9402D9ULL, 
            0xF9502E6CF4703213ULL, 0x0F4C13838A7C930BULL, 0x80EA9D320EDB48C0ULL, 0x4FE77B28742F677CULL, 
            0xBB1383B65A7443BDULL, 0xABAB16F0041AD880ULL, 0x835784648B56D01DULL, 0x78F550A439627BE0ULL, 
            0x11CF5623F85350E3ULL, 0xD88507EFD7D8C7E8ULL, 0x6CDA4E2912BB2C7BULL, 0xAE24C4DDF1534160ULL, 
            0x5BAD36F2EC9FE7B9ULL, 0xBC53CBA1D455D75DULL, 0x7942958B89108553ULL, 0x17731ACD4E548602ULL, 
            0x8A5D0C6301D68BCBULL, 0x6991DEC1DCC6C8AFULL, 0x508B3FE63B1931E7ULL, 0x0DD417BC0D8115DEULL
        },
        {
            0x1887C9FCF697554BULL, 0x9038E1F10783CD99ULL, 0x44B2609E3365A186ULL, 0x85E1E6AB5895D389ULL, 
            0xE487C52B127F5617ULL, 0x9B1E4C1E79374E89ULL, 0x1C1554A5A4920419ULL, 0xE67EB46D959B5FFBULL, 
            0xEDDCA59EF9D236F6ULL, 0xA5854613C8E31B3BULL, 0xA8A7C2226686CA86ULL, 0xB623D10919880B9DULL, 
            0xB46170C1D67EC55EULL, 0xFD75FFE1EFF9B46FULL, 0xAF3F9078D08F1456ULL, 0x49E364996CA81FB2ULL, 
            0x603EFF2E0B86FBEDULL, 0xCD305340C53A7E06ULL, 0xF206A4A26B82329BULL, 0x52FEB4369F76294EULL, 
            0x13AC1DB1435EB9BDULL, 0xE15EBB2BEBF83149ULL, 0x6442E83F69FCD565ULL, 0xD7193B3FA90895F6ULL, 
            0x2684EECE77B12BE7ULL, 0x343DA2B168F8B271ULL, 0x7130DF864C844235ULL, 0xDC71B06DB73F0B6AULL, 
            0x70BB094FB9574CE9ULL, 0x1DDFC48A4562DA95ULL, 0xF9845E20EFB83B65ULL, 0x71E173A49E0B9957ULL
        },
        {
            0x2D67EC3D9D0946FEULL, 0x6E2334B48AEBB22DULL, 0x25CA0DE5AAE82676ULL, 0x083EC10C683094D3ULL, 
            0xB6C31D2054C1F260ULL, 0x54FC7C560C7F8558ULL, 0xDC4CB385E90985BEULL, 0xC5B7D6E66280353EULL, 
            0xE5FC9BC7EA1F2F78ULL, 0x1B0D2B95F70AECEEULL, 0xA2D7D78F1D43DA2EULL, 0xF93DB590AFC2624DULL, 
            0xBFB272E525C114E1ULL, 0x3F508CDD76655851ULL, 0x54C071AE80B43A0BULL, 0x86B6AF83A500C0ECULL, 
            0xF9A749676CC29EFCULL, 0xCD6724C287CE6C7EULL, 0xCD9CE2255FA56FA0ULL, 0xDB7FFE51A289A2C1ULL, 
            0x7566755F12106BEEULL, 0x5CC9A490FA86B295ULL, 0x8A48334910C4261EULL, 0x7C18EC1C8F5D983EULL, 
            0xDD68D553C82A31E1ULL, 0x5EB51D8A3C11E7E1ULL, 0xF3DCFDAA48571202ULL, 0x637E0CE1F0CCBA14ULL, 
            0xE45D6E7B7652C71CULL, 0x4C5CE8510ED51459ULL, 0x1309995568BE6DE9ULL, 0x002459904D127995ULL
        },
        {
            0xA5543BF5743D75F7ULL, 0x44F1F5CE0FD29600ULL, 0xB10E61D8111A2551ULL, 0x896628C461112E31ULL, 
            0x707B3D663A6BDC48ULL, 0x7E7433C2E8797ABFULL, 0x48C2CB20DE68DE11ULL, 0x2A77818A64ED60B7ULL, 
            0x81E729CEA0B8EB3CULL, 0xFC6984BBD80A7A18ULL, 0xC899D25D4CF72FD8ULL, 0x444C88E309C849BFULL, 
            0x3E7B0F0A9C17F74EULL, 0x6F4D7CEC438402D3ULL, 0xAE2CD4D8FDBC62C8ULL, 0x14BC09A298F8A70EULL, 
            0x393779FDF2E6DD19ULL, 0xBF17B265AC6E6DF7ULL, 0x61832B9A5AC53177ULL, 0x70864FF01EF2F8C8ULL, 
            0x23B94B4A94473263ULL, 0x1A62A9CA1F4CB413ULL, 0x16343C8E06F6E6EAULL, 0x8BA9E9F497117B14ULL, 
            0x2EB23BAADDDC42DAULL, 0xA0232107C72602AEULL, 0x918534EEE707E655ULL, 0x4662591CC94F01D7ULL, 
            0x88F61830FD1F8A0EULL, 0x14BA90A2861B24D0ULL, 0xD3308AF1EA22216FULL, 0x7B41717DA5254ADCULL
        },
        {
            0xBFA801F3D0D619C5ULL, 0x43E12FF06538C83AULL, 0xFF51ADD02D0522D0ULL, 0x5FADB3847E1BB63AULL, 
            0xB6069962551011ADULL, 0x08F517B3868924CEULL, 0x47D5A5B2E3296237ULL, 0xCF41117CE525451DULL, 
            0xF45A044A0422B2ABULL, 0x5F5DF07E074E23B2ULL, 0xF7EBB8771E04AF0BULL, 0x98F013D3FE900715ULL, 
            0x1352A6C1B59BD963ULL, 0xF4F8E5CC6BD31179ULL, 0x1D449550FA55905EULL, 0xCADF0A4865027062ULL, 
            0xD5B766F227B2EDDBULL, 0x8C5EE6420D90E79BULL, 0xD79B7C2A8D4F16B6ULL, 0x206013D1F1E30A37ULL, 
            0xB5930ADC9BD13847ULL, 0x4A347A329CD4E968ULL, 0xDCA421E9A53AECFDULL, 0x4AD497D6E46FE9DCULL, 
            0xD62C1C5FFADCBFC5ULL, 0xDB802B902171BA6BULL, 0x055559B999148185ULL, 0x0AE33FD040DB35F7ULL, 
            0x009E93420608F98CULL, 0x120B8AA9B40B62C3ULL, 0x681B22A792CABBE2ULL, 0x29E7E249563DFE96ULL
        },
        {
            0x7A5C440155FDF33CULL, 0x465BFFFB9FDA2AEAULL, 0x4EE21686077F6D74ULL, 0x01CB025C6D88DB8AULL, 
            0xA8AF4347721312B4ULL, 0x1F2C947DFD672CC5ULL, 0x0F29540573B4ADEDULL, 0xF8D3BC2D9B71C763ULL, 
            0xD2500B7C0A30BD9BULL, 0x2A49482E9AB9C1E5ULL, 0x7862E3AF86D80DC7ULL, 0xF7846BD233439A69ULL, 
            0x9ADA5ADF217FB4C9ULL, 0xDDF019C6DC1EC2E4ULL, 0xD1AC1AC678F8E3FBULL, 0x5F75985AB1F766BDULL, 
            0xAF471594C8026143ULL, 0xF7F91DEDF239D9A7ULL, 0x505F737B50DBE858ULL, 0xE619572B930CDF24ULL, 
            0xA9544D3D84E64FAEULL, 0x53276510295FAF28ULL, 0xE25C703DE584A958ULL, 0x7EDC2469B4DD8831ULL, 
            0x351863CD375E6BC4ULL, 0xF6E92B12792682CFULL, 0x5736D09B355B9DC7ULL, 0xE199BB4720ACE47DULL, 
            0x1F1C68B40B57F20BULL, 0xC035DEA86075C577ULL, 0x7D02C2483B05B6BCULL, 0x5FB6A89333152759ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseAConstants = {
    0x1B399E3C6A7032B1ULL,
    0xEBC1BC4C800CEA9CULL,
    0x3D618510BC26712DULL,
    0x1B399E3C6A7032B1ULL,
    0xEBC1BC4C800CEA9CULL,
    0x3D618510BC26712DULL,
    0x528E0BF7ECDB7AADULL,
    0xC8A32BFB2BC67145ULL,
    0xDC,
    0xCE,
    0x41,
    0x4A,
    0xA7,
    0xFB,
    0x8F,
    0x31
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseBSalts = {
    {
        {
            0x194D09BA5CF4EDACULL, 0x70DB262E3AEF7298ULL, 0x3E4E79BD84AB17D6ULL, 0x2AA1232F85984FBCULL, 
            0xACC476E93F9CDCF7ULL, 0xF3D78543B195C627ULL, 0x5463CD68C5A79950ULL, 0xA072E1F3E7A010C0ULL, 
            0xB0924F71B30ABA38ULL, 0x05F6AA2C10AE8618ULL, 0xCCD8A0F6CD0DAFC1ULL, 0xFD39FC5AB29596C6ULL, 
            0xC3D214AA4A4E8062ULL, 0x04B4E40FA0B775A7ULL, 0xE215C44F4606BCEAULL, 0x4A35A3BCA8C7244AULL, 
            0xF70C337C87164FC4ULL, 0x2369F35477AB7DC8ULL, 0x9D76CF22301A3181ULL, 0x471B137051017064ULL, 
            0x6D4D1814D7278ABEULL, 0x42C8DE6DE912DE50ULL, 0xD45FC64E00147709ULL, 0x6A6AD7006B98C467ULL, 
            0x1A3B88C0BEEAC913ULL, 0x802B588AD31717D3ULL, 0x7B711CD0CDAEAA02ULL, 0x3FABB054D80E3CC2ULL, 
            0xCB23C7EF1F5A0504ULL, 0x6DF9D83955678C38ULL, 0x30A726809EFAF349ULL, 0x96B04BFA975004FBULL
        },
        {
            0xA4C3141E33A5FF9DULL, 0x045E5D56B05C57AAULL, 0x60795F0A1357BCF0ULL, 0x04054B07A542525DULL, 
            0x014FB17B1230335BULL, 0x3C7420E0FB4F3A3CULL, 0xAF4774221AFDDD08ULL, 0x59D872539758196EULL, 
            0x3225D536EB4DACDDULL, 0x97DB42EA41B4A029ULL, 0x9D9F27A7A73A01F0ULL, 0x25238AEE259640E5ULL, 
            0x4F28DF913D5BCD35ULL, 0x3F13931CB632676FULL, 0x378874C521FCACA7ULL, 0xE8D09FDA943657BAULL, 
            0x1BB6E5E6E882614BULL, 0x4552929706CDA3E4ULL, 0x9C3F08FD76304A8AULL, 0x634661D724671B0CULL, 
            0x405A6CC3F04BF1A0ULL, 0x3B1FAADD754C2B99ULL, 0x651F39B3ABF64FCBULL, 0x0C80FC6C654E4653ULL, 
            0x7A934F155AE9A79DULL, 0x379361EDF6299CB4ULL, 0xAF84F63AA95BBB59ULL, 0xDCD234E64BC863E5ULL, 
            0xBC08925AC9A86940ULL, 0x3AB03BF229E492C0ULL, 0xD0CC97AB03EB8569ULL, 0x04E8489F1F4CB469ULL
        },
        {
            0xB846CA4A48000D5CULL, 0x2E9467C01D0235CDULL, 0x073177BD5C3AD191ULL, 0x9CB9AE54A3E65DA4ULL, 
            0x8B3097490CFA0813ULL, 0x5DEBA0BCA0181C59ULL, 0x3E2EFEC0FE684715ULL, 0xC14281FCA9A6BB46ULL, 
            0xFFC1455CFDD59DC8ULL, 0xF3F29DDDFB42CF94ULL, 0xC85BB22185CEC494ULL, 0xB3239A07EE0B79F6ULL, 
            0x4CBF1E3773222D7BULL, 0x84CD67DA6D1853FDULL, 0xBA4287B42C5EB95CULL, 0xB77BAB34172CF8B9ULL, 
            0x8647B12854DEBF18ULL, 0x95588F0268228B3AULL, 0x347F45FCB966D701ULL, 0xA52F6C6108734E2BULL, 
            0xB2371133CD611F01ULL, 0xABE6EB4786631B4CULL, 0x4771039ACE476FFFULL, 0xB1C2DDEB3FF13A7DULL, 
            0x38237B7634CADC56ULL, 0x5E165C14B47EEF6DULL, 0xE8BCE99BE6EF66DFULL, 0x256E264247C9F0D1ULL, 
            0xB93C9AF2CAE2F411ULL, 0x5589323E17958922ULL, 0xC814626B1A263543ULL, 0x53157C43392FA074ULL
        },
        {
            0x02C20E8861EC6C3FULL, 0xB18096970F45DC3BULL, 0xFB2A35095AFC9A72ULL, 0x7A3C39EBE00FB3E4ULL, 
            0xCC7011DEAC399E7BULL, 0xB4EC9FE8C6A139E3ULL, 0xF8C0C5DB40E40BDDULL, 0xAF2CB2F6B086667BULL, 
            0x6001BFB69F077631ULL, 0x73186004A45D17BEULL, 0xA688EE35A2FB81BCULL, 0x64E8612E842C928FULL, 
            0x4AF854803D2E6CF9ULL, 0xA7552565250F0318ULL, 0x9E70BF1E49DBE930ULL, 0x410DFC64CDD1162FULL, 
            0x7BA887ABC43F18DCULL, 0xE95E3364581E0534ULL, 0x3A3FCA69323A1CC8ULL, 0x986DF348535D47CBULL, 
            0xE80199C0C419A7A6ULL, 0x8A0C94C0A6226302ULL, 0x92A6A709859FE028ULL, 0x45BA8DBA50EEC071ULL, 
            0x6C3329DE08F98497ULL, 0x120748B062465A85ULL, 0x8FCB55F254DCC521ULL, 0x70A38A51E2E4E549ULL, 
            0xE5B43D4D58359655ULL, 0x43D1247A17A50A5CULL, 0x90EBA4BE396BDF4EULL, 0xAF60EF050584D164ULL
        },
        {
            0x7F7D98C374594900ULL, 0x456601E80BDA899CULL, 0xD7E01C63507E148BULL, 0x0D5C72339CAAC711ULL, 
            0x11EC269FF1F47A67ULL, 0xB65FA3BB0A44B892ULL, 0x341CF49079FD3C01ULL, 0xF520CE2B557684C2ULL, 
            0x281C68B1AA69BE1FULL, 0xABB34995638E023BULL, 0x9D5E8346FEAE422EULL, 0x62F865038A972109ULL, 
            0x713127373183DBF9ULL, 0x02C479F75A7731E2ULL, 0xFE1A1705E6ECEDB1ULL, 0x94B7AA2F57FA33EAULL, 
            0x772E5ED52B89C868ULL, 0x74AF767F0367B582ULL, 0xCA83379123BE2F4FULL, 0xE61C2469AFD90861ULL, 
            0x9149702C789262CCULL, 0x7A30ADF04FFF3CA8ULL, 0x5AC4271425A50BFDULL, 0x923F98C8F1C55683ULL, 
            0x94B83298B31489CCULL, 0x591FC3532101A938ULL, 0x55F1B53F85A26BE0ULL, 0x4E159DCED514738FULL, 
            0x33B5BAB86F8584CCULL, 0x9D05366BA990DD23ULL, 0xC7AEF5AF02C60FC7ULL, 0xB3D8CC5AC051A900ULL
        },
        {
            0x2998D020389CB0D2ULL, 0x1B4290BEE32E53B1ULL, 0xBD40A075075A225BULL, 0xF37CE7C01F4480CAULL, 
            0xE02FF6B98AC51F35ULL, 0x6E55AC19025A803DULL, 0xD4C7177BAE0A9326ULL, 0x692A7C4A6271671BULL, 
            0xC7A26CA0AF0CBEADULL, 0xD3C79EF91488B358ULL, 0xF8AEF14F1884AA33ULL, 0x0DA063128A30AFFCULL, 
            0x16B7B2260F214104ULL, 0xFB097CF9880E0A9CULL, 0x0CFC7D273E093039ULL, 0x37AFF8BBEC00C79FULL, 
            0xF7B3AA26F04FE28BULL, 0x084686F6835615A2ULL, 0x069DB3C42F2E2816ULL, 0x1F59C897CD76061CULL, 
            0x81BCCFCD2BF1255EULL, 0x80A3362CBA183164ULL, 0xC887B9758DBCC7E0ULL, 0xC6DFEEBED5336898ULL, 
            0xC932D87D4629073CULL, 0x993C42A2F9B3F2D4ULL, 0xA624E566DA64DC78ULL, 0x340E39FE80BE5898ULL, 
            0xB7F01E2328E81565ULL, 0xB4BF04A206796A3DULL, 0x0696CB3443FE020FULL, 0x7850811431E78431ULL
        }
    },
    {
        {
            0xD5049B3516332675ULL, 0xF5ED43A0FB9498ECULL, 0xB843D74EFC70B94BULL, 0x4870D5EB0E451838ULL, 
            0x62E36EDACA98F95DULL, 0x32269BE1459CFDD8ULL, 0xC04BA2015B6B0239ULL, 0x1CD1849B93A2BAF3ULL, 
            0x1855A5A480DAC459ULL, 0xC2E2AC418D0D4D4FULL, 0x6B2624A6FB0E0F4AULL, 0x027D77DCD52441E3ULL, 
            0xCC2CC425824E6F8AULL, 0x7F7AD03E8F43C789ULL, 0xCEFE4AF2D6A2C2EFULL, 0xE05F028E61F020BFULL, 
            0x4EEEBC5941B34D0CULL, 0x0BDCBF37DE6E8948ULL, 0x66A0F7E4AAA1DAB5ULL, 0x46BC38DCFC8F5C80ULL, 
            0x7A291108971FD581ULL, 0x1BCF50445A2ADC17ULL, 0x62F26BE30FD1130DULL, 0x5E9694EA05E4BA31ULL, 
            0x248FCE31D93507EDULL, 0x44B3372C783931AEULL, 0x1E3B3881FAA608CBULL, 0x0BEE02202E9DA512ULL, 
            0xA1D8B053D1279EBAULL, 0xCF6CD4EFF9C31821ULL, 0xA3495FB8C6D7708EULL, 0xD19630D95A326BE8ULL
        },
        {
            0xD7DAE8D3F0159C05ULL, 0x6687B20E8039E8A0ULL, 0xD06C7A31C3FAE743ULL, 0xC785ED15A343B925ULL, 
            0xBF5076C1A4C1B705ULL, 0x80059DCC5244749AULL, 0x042BB2B5146B2D61ULL, 0x7CC09C8434860CF0ULL, 
            0x22C6765C7725A560ULL, 0x53E25D757FBF5136ULL, 0x2F4B386812900080ULL, 0x8DB908C7A2A2EA0DULL, 
            0x243C1AFA5EC192F2ULL, 0xB6B757C094415DA2ULL, 0x2B29ACF44888E662ULL, 0xECC5C1659E1F9F89ULL, 
            0x87FEDC5A2294B23DULL, 0x11450CF1B601F660ULL, 0x97FD7CFC450B9C05ULL, 0xE525E77E9E0DDF05ULL, 
            0xE96F2526F8426AC0ULL, 0xAC4934FFF5E5C19DULL, 0x8CD40154211716CFULL, 0xA3542CE7E85734CDULL, 
            0xD82B666231C0BF8FULL, 0xE23F1EED48932920ULL, 0xAFD0F28C5986ADB7ULL, 0x008C1C3066558C3DULL, 
            0x72B9342B6C434FAAULL, 0x6E0FD9414199705FULL, 0xCD4E8083780C2AE2ULL, 0xC09DFB46D2D2C3D2ULL
        },
        {
            0x7FFB4F64C59496E7ULL, 0xC7FFA87CB86E3996ULL, 0xFAA11CA180A83DC1ULL, 0xF35B29F8A3756D78ULL, 
            0xE9A21B305FFD2E11ULL, 0xA56498688CC133DAULL, 0x3F0A59EB1E6CC7E8ULL, 0xBB6509C91F7E05E6ULL, 
            0xE83FFAA12BB02339ULL, 0xEEC59B8CA6A21982ULL, 0x833DDA8EB2CEDBA9ULL, 0x5D5A29A1757460A4ULL, 
            0x49AA3FB049A87267ULL, 0xA29E5BA0956DFFB3ULL, 0x007D2A50E34A76F8ULL, 0xA7722CD7554347F7ULL, 
            0x0FFFF573782388D8ULL, 0xE5EC5695A6C0F08CULL, 0x84F8DC426BFC21F7ULL, 0x5F2BA258BF72505EULL, 
            0x4AD30120B4C6FF1CULL, 0x2ADFBAD4740E5AC1ULL, 0x94A9CC38E1393388ULL, 0x083981B0E28A1A8EULL, 
            0xF776F68462DBD9A3ULL, 0x2FB3EAE6EB2B3930ULL, 0x976062914B4AB17CULL, 0x76725E6227A8335AULL, 
            0x3B5BD373C15BB54BULL, 0x814065EE977BD9C5ULL, 0xA013D5C0AC97D2A4ULL, 0xB499E2C87D67416EULL
        },
        {
            0xCAACF0757DAFFF26ULL, 0xEEA10FC48E17142EULL, 0xBF5F7B36FEA5DD0DULL, 0x796BD7D164B7FCFBULL, 
            0x057BE555CD18E257ULL, 0xE9630145FD86C610ULL, 0x6C9B336215FA55F8ULL, 0xC904210EA403704BULL, 
            0x968DDA6E05C78A05ULL, 0x5833DDA11B0DAFB5ULL, 0x6C22B692AFE0EBB3ULL, 0xD36B07DC33BABDD2ULL, 
            0x87B7064395DFAC74ULL, 0x6FF33E516C8B7AAEULL, 0x3D089DF0454BF6B7ULL, 0x6E058C1099F47A16ULL, 
            0x855E0B366177ACFAULL, 0x48585A0C1AF32638ULL, 0xA676102AA520174EULL, 0x1E98EF5B16803F1CULL, 
            0xAED22E10AABBA1A1ULL, 0x7135BA15E7A7E3E3ULL, 0x9F1407C34761EE57ULL, 0x23A68673851F1CE3ULL, 
            0x508A5E3F26D52819ULL, 0x23A3451FBC9981C9ULL, 0xDD0D73DDE50052DFULL, 0xE2E1CC3F2A6BE3B2ULL, 
            0xEF7CB585C1C65496ULL, 0xA16878042D240179ULL, 0xDE54D8C1555BBA85ULL, 0x7F17889E46D74C7FULL
        },
        {
            0xBB0DDA6FC9BB6889ULL, 0xD6D988128664C340ULL, 0x59E0B13372F1B49CULL, 0xF928F5826BA4B11EULL, 
            0xFAD904264FC0862BULL, 0xED5F9AB9B34D7CD2ULL, 0xDE2CC2F9DBB971F3ULL, 0xCE2D56AF89EBA18BULL, 
            0x5B0EB6912296941AULL, 0xCCC4ECD93F3A6F34ULL, 0xFA4DD3BF8C207662ULL, 0x31D09632F069E112ULL, 
            0x42228D6DFE1259D2ULL, 0xC10DFE33F96EBDDBULL, 0x62ECF27FD8651B55ULL, 0x946A8AF49D49FA66ULL, 
            0x6358DE436F2E891FULL, 0x37863E1377833A35ULL, 0xA8105F2093C42705ULL, 0x45F0C27B7B6DFF1FULL, 
            0xDE0DD9602524E9E7ULL, 0x2E11C1B60FB59CEFULL, 0xA654CF08C8981566ULL, 0x0DF2E697C68BDC40ULL, 
            0x111805B2E907692BULL, 0xEF3C333E62B36503ULL, 0x1A4581CDC3035BEAULL, 0x0C70F0B651375505ULL, 
            0x24FEEE7225FFB848ULL, 0xD4A7CD3B5EA4856AULL, 0xABA0BD98B9B9EA0CULL, 0xF3BEB56BDC7C9F5BULL
        },
        {
            0x1886693F89190FAFULL, 0xC6000A90ECDA5918ULL, 0xA338D90E218EBE96ULL, 0x0ECAF6B133D9BCC6ULL, 
            0x285EDA5D2CF8035AULL, 0xD54E6F8D9A9E05B8ULL, 0xB306D55CC0287736ULL, 0x0C094A2A6B300416ULL, 
            0x5F4ECA51090AB573ULL, 0x71AB6026295304AAULL, 0xCA46E3435CB85186ULL, 0x76F2DBFF4011D11FULL, 
            0xC6D49B606F4965A9ULL, 0xCDC717B4824FA0D2ULL, 0x081A21A2FB32C78FULL, 0xF60CEB0626D38DA9ULL, 
            0xFC9DF5E143C32F55ULL, 0xBDE641485E21ACD1ULL, 0x94363952B0AF8F60ULL, 0xD8A9B3A3A0D4F918ULL, 
            0xEDA41E3DE1010165ULL, 0xEC3533670065E9D3ULL, 0x623114D9E8AD9F1BULL, 0x46610F01AED50366ULL, 
            0x7EA3A65EB16FBF6AULL, 0xEBDDB9DACF0B7196ULL, 0xE285B16391862ADBULL, 0x8D4DD556F1F56982ULL, 
            0x55A34054CDE1838FULL, 0x5C3119477AC0306FULL, 0x30EC1B925080446FULL, 0x5FE4BCAB859A624FULL
        }
    },
    {
        {
            0x154E6B5C2F10085CULL, 0xE76753467EB7DECBULL, 0x7F47FCC6E05FCF95ULL, 0x43BFAFD786C5A96FULL, 
            0x79288AA85D20D2F5ULL, 0xEB3831D462683810ULL, 0xC4986BBBBBD87547ULL, 0x2F1CCE533FB8FECBULL, 
            0xEEB0A7D8A6075D46ULL, 0xAEC90B0E01ABACC5ULL, 0xD4575D30259324C9ULL, 0x2217130BD68CFED7ULL, 
            0x96A34E5F6F48162CULL, 0x9C9700ED8CCE9721ULL, 0x1683D835CAA52026ULL, 0x3F7306EA8062AE9DULL, 
            0x48B87AB7CBB0D145ULL, 0x5A15BE8D89B2FB7FULL, 0x28A3E267FE9B861FULL, 0x995203B4E31AECEAULL, 
            0xEB0152E8B09EFBE0ULL, 0x147F56200DA538ACULL, 0x4FD95B1E5DA77978ULL, 0x3EA4BC31E9D4CA56ULL, 
            0xCA9B3A74DAF1C938ULL, 0x2A03CC55D24864E8ULL, 0x258DA2301F2D2B6EULL, 0x62E6AB3F77A722BEULL, 
            0x2104D956321C2708ULL, 0xC2D16A17930B7E32ULL, 0x1CA5B38A1EB1AE78ULL, 0xADB472BB341917A5ULL
        },
        {
            0x2665AA0816CEE482ULL, 0x2A03B9C00FD8F538ULL, 0x0DB7BFBA12F999E9ULL, 0x128C166E072175B2ULL, 
            0x5617F2F8E38D08A2ULL, 0xF456C7A7E294702BULL, 0x5DCFED6D575B349DULL, 0x3C6A0522BAD70EADULL, 
            0x3413697C8E8266BCULL, 0x6334826B7E77E753ULL, 0x40A6D46CCAEF3C66ULL, 0xC68C6C71B22359A8ULL, 
            0x11EEBAF1527B4D26ULL, 0xFE88FFFA25B3F6B6ULL, 0x303ADCAEC1330836ULL, 0xCCF754ABFEBA4D36ULL, 
            0xB2067CF734FFB8D7ULL, 0x220B7BD3A026CC53ULL, 0x34C1D6EDCC7F612CULL, 0x965A3843108032FDULL, 
            0x6775EDA755851D02ULL, 0x13A364D2356BC115ULL, 0x144D8CB6BFA02623ULL, 0x39C7E2274EB7C91BULL, 
            0x5AD2CB6B97F3C322ULL, 0x145757A611DA16E0ULL, 0x56BD8C98E876F772ULL, 0x17DD293950F0C684ULL, 
            0xE2B24D50C8820C60ULL, 0x0EC97C75F2A2EC45ULL, 0x04F898C95C711E92ULL, 0x94319F5DCC1B0791ULL
        },
        {
            0x0831479B2C306E69ULL, 0x069F3CA48ABD92ACULL, 0x46AEAE93BF2E2913ULL, 0x4DB33F42C6946714ULL, 
            0xA0254AB5337131FBULL, 0x28DBF6BDE0D8BE2DULL, 0x1808F15EED7799DCULL, 0x2F5C3D290416D504ULL, 
            0xFDAD427CFFE718E4ULL, 0xF151221073001669ULL, 0xDB2E321A8CFF5F73ULL, 0xC030CF6CBE25A0E1ULL, 
            0xA514DA939283438BULL, 0xBB6B5E804B89ED26ULL, 0x9292B9A5DB5435F4ULL, 0x60B9275FBED9ED92ULL, 
            0x88B97CCBC2DBD160ULL, 0x95C2A1D134ECB816ULL, 0xA58577C5299EB7E9ULL, 0x97A3127908CFBC77ULL, 
            0xFD16C46D558286D6ULL, 0xBE64C9F278A33D30ULL, 0x924C0D0DCA95144BULL, 0x04BC81A1CE5F37A7ULL, 
            0x599219DFEB946D4FULL, 0x0001B0AC407D5ADBULL, 0x50E86461FBE49726ULL, 0x7FF7DDADCD0AE660ULL, 
            0x9F4546CB7FC74729ULL, 0x2D6F3865EBC56DFFULL, 0x50461988CD9A3BBAULL, 0x960745AC38B295CFULL
        },
        {
            0x9109E60CC429FF6DULL, 0x4B9200DC0C6ACAE6ULL, 0xBFF35C2EBE82F13DULL, 0x091E31A576250C32ULL, 
            0xED550E878768A653ULL, 0xC3487AE175F3D186ULL, 0xB4F49F312303FFF5ULL, 0x640C96F31AC914DBULL, 
            0xACF99A44FA23EABFULL, 0xAC67C3A1A01D6BE9ULL, 0x12605E308B2EA803ULL, 0xCCC6F9916F6CB12DULL, 
            0xC4F0E8DE6B07204FULL, 0xBB9517EBF07AB2BEULL, 0xACEF59A8817AA0B3ULL, 0x06DB76364D40F01CULL, 
            0x90A78DD504877528ULL, 0x8E1CA4A406531F8EULL, 0x3AA99143425AA43EULL, 0xFB89B2EA89B6EDCBULL, 
            0x1B7D7780AE48B861ULL, 0x865870D2FDEAFF69ULL, 0x9987396FF624A0D4ULL, 0xE808524AB1B3C62FULL, 
            0xA8594312167863F6ULL, 0x22A1CD995112ADC1ULL, 0x7959373B3540B074ULL, 0x3AEC4AF2A3E52512ULL, 
            0x33716C5AF5E6DEE4ULL, 0x72010395956AFF14ULL, 0x4DDA0DD48935481FULL, 0x7310925A39F8B3EDULL
        },
        {
            0x6DC31B82516009E3ULL, 0x7D9A96CF696C2378ULL, 0xB53E16CC1975579CULL, 0x2FA901A9D8812B01ULL, 
            0x53E875739BE84398ULL, 0xD6C6CAC48576E4C3ULL, 0xA95926D01C4CA49CULL, 0xE63171E2E387BEA9ULL, 
            0x26389A7431912026ULL, 0x9A10D97BE2A66934ULL, 0x3E4B9849979DECA1ULL, 0xEE2B961D173B75A5ULL, 
            0x803C475BECDCFA78ULL, 0x811BB1815E4CE832ULL, 0x09F120A6100A1937ULL, 0xDBD1353D8A81BA1EULL, 
            0xB6CCCEFFAE6CA69FULL, 0x19A56893E99F55C4ULL, 0xD30E3FFBE0D734ABULL, 0xFC70807F0C576B73ULL, 
            0x2216A9C0F2946E30ULL, 0x87AB81AFAE95721CULL, 0xDE8A94A1771FD4CAULL, 0x32EDA8795FCF86C9ULL, 
            0xCED28F92156FA794ULL, 0xE96AE05C48B8C076ULL, 0x9C26E58678D20138ULL, 0xB230181A08228C20ULL, 
            0x277BB2E5F646A3C1ULL, 0x429B4B40B9810436ULL, 0x9FFB827CB08C0E87ULL, 0x58B1531D0D08EF44ULL
        },
        {
            0x13F85DF0FBED9E0AULL, 0xFA352C166C4BBF07ULL, 0x82A385E29766EC66ULL, 0x3979EF2FC1F4EAD8ULL, 
            0x63ACDB6E1033C262ULL, 0xC897666579C05133ULL, 0xAE531EBCDE2BD6FAULL, 0x3E13CA38022C16EFULL, 
            0xDA1759B674950C3DULL, 0x97EFDBA328CB2DE3ULL, 0x1202C7D55622114DULL, 0xA14ED98536A7CA0EULL, 
            0xF193924FA5DD502FULL, 0x15443E0826BC16BDULL, 0x4456E6C9021097A2ULL, 0xE95118DCE9F83262ULL, 
            0x948B98F0921D7752ULL, 0x2177434A4EFE27E5ULL, 0xF94BF5915887B599ULL, 0xC6C458BCAA145C5FULL, 
            0x3E329DD2F7294591ULL, 0xC0F67256F06B0DE0ULL, 0x7317E69FF3A386EEULL, 0xDDB5F50EBA0BC8DDULL, 
            0x17F35F7EC65719CAULL, 0x4E0A056C68CF9DD0ULL, 0xB88EE364AADECF85ULL, 0x79533FE904BF3685ULL, 
            0x1264E4E4C07BA678ULL, 0x166056AB64094EFFULL, 0xDE44E9EF6F53F368ULL, 0x00A9C39F0F809ABAULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseBConstants = {
    0x0C963A10F6D460C9ULL,
    0xD2571C97259B309AULL,
    0x32421DEC7672A196ULL,
    0x0C963A10F6D460C9ULL,
    0xD2571C97259B309AULL,
    0x32421DEC7672A196ULL,
    0x8ED9AF2D79BDD3B1ULL,
    0x1E2437EDE93DDDB5ULL,
    0x6F,
    0x8F,
    0xEF,
    0xF0,
    0xE7,
    0xB2,
    0xB7,
    0xDE
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseCSalts = {
    {
        {
            0x3AA3922BA80D1FFEULL, 0xDD9C7F14AA7B65E7ULL, 0xEDFF5CCF93A9F76DULL, 0xE6593D38013FA68CULL, 
            0x484D29BAAC79D800ULL, 0x17C75A2C62547201ULL, 0x28C39DD0C0C9CD6FULL, 0x9C6C47D5DA15B240ULL, 
            0xFBDDB8607F7188CBULL, 0x4D654E3A87E0CF8CULL, 0x97B4094128B86072ULL, 0xFD2457C7B106C44FULL, 
            0x0184958D11CCCEAEULL, 0xCACB4C6D5446CF36ULL, 0xD58608EE07423BCCULL, 0xE0CBE20354A3E74DULL, 
            0x55676A1FCC627710ULL, 0x1194A9BDE0F457C3ULL, 0x1BE237F719AE3046ULL, 0x1C1CE6A7CBA56F8EULL, 
            0x8B4B01BDEB85DF78ULL, 0x06A9FB6422F5FF26ULL, 0x4450A85B368335E2ULL, 0x87C0D5BE280D77BAULL, 
            0x7B05C418CCB6319EULL, 0xBCA93D4673365ABBULL, 0x6E9E4A294E4C4A1AULL, 0x15C6C6736ED785D9ULL, 
            0xD01B2023AA690183ULL, 0x102E6F4242C19926ULL, 0x39020F30D8B15679ULL, 0x96FA0F6C942F1E16ULL
        },
        {
            0xDF89CF40626CA082ULL, 0x5584C56EB077ADD3ULL, 0x5EFC114AC8D609C2ULL, 0x36EDFCCF00AF045BULL, 
            0x27E2FEE3B4C990CAULL, 0x26AA79E17521F806ULL, 0x597133B7520B8EB7ULL, 0xAE4B31BF1CE44972ULL, 
            0xF0D8417B6AD65DF3ULL, 0x2BFF3016FE328A47ULL, 0x36693B63BE6D0BDBULL, 0x528BC836D54BBBA4ULL, 
            0xFE23473E4393C42AULL, 0x821B55368F8580E6ULL, 0xB659A992A1F00376ULL, 0xEC498216FD68D4B2ULL, 
            0xECD7BE5A8B408861ULL, 0x368375DC8FCBF1BCULL, 0x0F43980F6DCC6623ULL, 0xE78122171F8AE409ULL, 
            0x99D6D9ED8AF95A81ULL, 0x87DEB4A1B4CD68C4ULL, 0x49CA012DE50F7379ULL, 0x84ECB29FB287150DULL, 
            0x190CC0C8C76EF77DULL, 0x19B06135F1FF5782ULL, 0x52A52F3FDDB4A46DULL, 0xCF93CBF252F38D64ULL, 
            0x3BA2E9082DB1714BULL, 0x098570F0EC13285DULL, 0x6725F308ED50AD46ULL, 0x3F9909B48C1E5202ULL
        },
        {
            0xC25CF5C35F045E84ULL, 0x8D8FE50806A86C7BULL, 0xD0E9FDFDFF225082ULL, 0x2199E96D52DD04D3ULL, 
            0x7C6C67A562E4D97EULL, 0xC8939A5EC6AABA16ULL, 0xAE9ED9EA186307C8ULL, 0x793160B1AFA00EDEULL, 
            0x03EE8A4052B74CDDULL, 0x1BD6ACB60C0374F9ULL, 0x1B162740820508DFULL, 0xD1D4DC6EB30B8248ULL, 
            0xBF4D8522C81E979CULL, 0x966244C2E342DA6FULL, 0xE7A57442537298F7ULL, 0xB94F6451D6B0B61DULL, 
            0x327BD4889F532CE2ULL, 0xB1C136F8733D7B18ULL, 0xEA970A2FC68EE86CULL, 0x7A508B99E498AEBBULL, 
            0x93FA60B0D36A326CULL, 0x28A554787DFA077DULL, 0x35E98FA6D9D5DE6BULL, 0xFB04C8A289945F50ULL, 
            0xAC563D2CC0932964ULL, 0xECEEC8B1D5762EC6ULL, 0x8B4FD2461838BB64ULL, 0x62F3B24C32A95808ULL, 
            0xBD8B907B082ABDDEULL, 0xC52B8655E3667456ULL, 0x2C6B64E2829C0574ULL, 0x30245FB1E5E9C87DULL
        },
        {
            0xC42D5171E0E9AAB4ULL, 0x6AA9CDAA28669B5CULL, 0xA250263D71FD4BF3ULL, 0x30BBD59FA32359FEULL, 
            0x76A7BD808CA1A77BULL, 0x522116F93F3E0598ULL, 0xA580B6CA751CEA33ULL, 0x6E52D207C2A2F1D7ULL, 
            0x64FA058ECAB7822AULL, 0x79F54179B13AF216ULL, 0x0F44FFDDD9EBB028ULL, 0xD699FF7A7F7489FDULL, 
            0xEFBEB4DF36EA64F1ULL, 0x889FECB4DABEBCABULL, 0xD4B832F8FE5685CFULL, 0x5642CD9A2AB8A154ULL, 
            0xE9FCD215AF4F0136ULL, 0x662E7BC6A750648DULL, 0x2C187530BB7D7B5EULL, 0x4DB7F5697CB76655ULL, 
            0xFECD88B066BEF172ULL, 0x6BB99B6FA44B1189ULL, 0xC83CCBD60DA20E16ULL, 0xFE217B2F87D72889ULL, 
            0xA8D4399F0A10ED5FULL, 0x5E600E59D695E298ULL, 0x8E97183889ED6886ULL, 0x899AEB52904DCC18ULL, 
            0x41AB3AEBF9A425B5ULL, 0xD9FBF05E7E4A8097ULL, 0x4CE270ECE613AB6DULL, 0x3DD59918661B4F4BULL
        },
        {
            0x81BF127A9D3DFC23ULL, 0x825806EC85A5F40AULL, 0x208F7A8D51D013F1ULL, 0x4AD8A1198E9C5E9DULL, 
            0x7A846B1E0E881572ULL, 0xE625C4B24D9FD93FULL, 0x90CD47B7E58F075BULL, 0xA3FBC8CFA428E928ULL, 
            0x31486022C6601C3AULL, 0xA1A09344751E160FULL, 0x9D962EE7FDB64D4DULL, 0x4053AD7AFA9261A6ULL, 
            0xB6A005D2F7E9C92FULL, 0x3D469FA58AB21A94ULL, 0x92B4766DC3A8DBFEULL, 0xFFEE88A449F1D502ULL, 
            0x7648E3AF9478BA77ULL, 0xB7B5BE054D441D2BULL, 0x1A480C558083A584ULL, 0x479B3D277CB445DCULL, 
            0xDA81FD35155FE46AULL, 0x6346A97E61053A0EULL, 0xC99675B395F989C0ULL, 0x53CDBC92025CB61EULL, 
            0x73E9780CF537E6FAULL, 0x254C612B45D5AEEBULL, 0x77A58843526955E1ULL, 0xA1AFB6C17A08A0C9ULL, 
            0x2058DC199EF631D5ULL, 0x8858B8F3B5D4D029ULL, 0xB17943D0D71AE9BEULL, 0xDCC0766A75EE3EA2ULL
        },
        {
            0x7E7DE16DCA9CC081ULL, 0x12C70FC42EF0B455ULL, 0x3086230C25A5704AULL, 0x229F1CB50E51DA5EULL, 
            0xEF7D58085E28154CULL, 0x41A96E59B83A038BULL, 0x94982F61D9A5EB4CULL, 0x6BE46B90156C3620ULL, 
            0xCC672E3E8CCB8AF9ULL, 0xFAC32E44F99488B9ULL, 0xE3FDB75D971C5BDEULL, 0x1719A3D349D53B48ULL, 
            0xD98B38E41C6E0064ULL, 0x9D951D105DFAB080ULL, 0x446162A9B02838AEULL, 0x916F144DB941FA8CULL, 
            0xCB10B4E646564862ULL, 0x646ABA3C54CD9420ULL, 0x4F365F172B69813BULL, 0x4DC6C9D42C600842ULL, 
            0xEB3860D7F65C5789ULL, 0x1AF87FB39582ADF3ULL, 0xE2C3FC68C7536032ULL, 0xAA36F5FF9E625860ULL, 
            0xDB66021A32C4065EULL, 0x43CE79105199984DULL, 0x9D2AFC76DD90E60FULL, 0xBC0638A355EAE25EULL, 
            0x0047FF97E615AE0CULL, 0x66E97868535F7C65ULL, 0x4D235C0507EA8F06ULL, 0xD6664D91A2055EECULL
        }
    },
    {
        {
            0x3690DC33F68176DDULL, 0x4950569329D4D1BAULL, 0x966FA6630A4FA8E1ULL, 0x706F4549BD2BD0F4ULL, 
            0x903512D9033AEAC8ULL, 0x26C8CF9EF10C79D6ULL, 0x2FD18E8B34554B47ULL, 0xF9904CCA517AE090ULL, 
            0x53DD2BCBE4C01DA8ULL, 0x00754829D25D1FF6ULL, 0xFAAB39C55B0BA943ULL, 0x65DCE344C1172DA7ULL, 
            0x3AB57C813EC0A601ULL, 0x9B19D6628C500D83ULL, 0x9CC9125D0AD7AF11ULL, 0x00539991D18BEB6AULL, 
            0xCE3456B34B7C9C8CULL, 0xA3536D7AF8D0738FULL, 0x08439283E7122E7DULL, 0xB243D191A68B9157ULL, 
            0xA173DC41829858B7ULL, 0x22E11A321B4AA28AULL, 0x3670A638427F237FULL, 0x378B9F8972D230FEULL, 
            0x9EC5C23BD8547DA2ULL, 0x02E849FB6A4011DFULL, 0x435E09682EF81E70ULL, 0x40E8CABACF438D81ULL, 
            0x0B55687719D1F40FULL, 0xBA2D9A25E8351DA6ULL, 0xA4CC495240588184ULL, 0xF59CB724518E7F08ULL
        },
        {
            0x1C329BA28717DDD3ULL, 0xCC21600C81A93A52ULL, 0x5D6A546459999564ULL, 0x41380CA7CA78A5D2ULL, 
            0xCA7AE3143340C840ULL, 0x3ADE266D6B5DF899ULL, 0x9C71CD0A5EC12B28ULL, 0x968507877455E9C3ULL, 
            0x2079F628E1A8F98CULL, 0xA3D8E58114390781ULL, 0xDCBE51479AF36EBBULL, 0x1BD24B50C547442BULL, 
            0x32A35A522F3FC50FULL, 0xE452871167F6C4A2ULL, 0xFFDC6EA9EE1A6AD6ULL, 0x1D18E0A4B12C6CB6ULL, 
            0xE30C361456D82825ULL, 0xF30DE37BB7222411ULL, 0x4AC9A12561DBC36FULL, 0x46990A6CC6EFDBB2ULL, 
            0xE6468AB063E3BE29ULL, 0xFA7AE291152AEBB0ULL, 0xEF6A0508CEF65353ULL, 0x18CB9F45EA4D693AULL, 
            0x08922A8CC6DD69DFULL, 0x50FB59E7AE18E608ULL, 0x72253BEFF57A0B72ULL, 0x1F7471188B01A2F4ULL, 
            0x8CA4EA9E394DC2B4ULL, 0x69B7DE120713310DULL, 0x7F98D9B8FD4C0033ULL, 0xF62EE6066E72ABA7ULL
        },
        {
            0x9493FCED3EDCCFA2ULL, 0x53CC2AA0831EF33EULL, 0x137CBA76588835E1ULL, 0xCC30250D126798FAULL, 
            0x500792B4C99A4941ULL, 0x973409ACDEAEEF16ULL, 0xC53FA05F6F34EA10ULL, 0x82C5CD51EFD5A009ULL, 
            0xE136DB2E1927DE0FULL, 0x9277A1A9A85CD4E9ULL, 0x5C4C57FAA2CFBD96ULL, 0x6A0AB6A2FBBCF29FULL, 
            0x1B0AFFB183744619ULL, 0x93FF70D3B96378CBULL, 0xB25CFA0F8EF4D5ADULL, 0x7BCDB3E39C3ECFCEULL, 
            0x51D813A6F5A72816ULL, 0xBF13525E8ABDCB08ULL, 0x5533EDD8D061A33DULL, 0xC28BCA6B56D27658ULL, 
            0x26A470F4302DCC43ULL, 0x6A8781FDBABE4919ULL, 0x8BBEE9866501BDC9ULL, 0x2383547E90F14E3EULL, 
            0x533B7EF030F22DF5ULL, 0x953973F188530942ULL, 0x5582245DCB63A809ULL, 0x554A284C199A25C5ULL, 
            0x5AC019810868763DULL, 0x86BD1B4CDB5930EBULL, 0xC2CB3711E0E9934CULL, 0x328E93CFCAD61475ULL
        },
        {
            0xF3B5E9084E5BE4ADULL, 0x80BA55CC2471EFC5ULL, 0xC88137979CF7643BULL, 0x1E57376D98B7DCC8ULL, 
            0x035A6A7726D09D82ULL, 0x1ABE3ECC71CC454DULL, 0xFF13643AAF59FEF6ULL, 0x502C18DDDA5BE715ULL, 
            0x1494517774CD249CULL, 0xDCF57BF2460CDAE6ULL, 0xF438E8E844339FBFULL, 0x662794A6F7D4B719ULL, 
            0x255C92B616EE1FA0ULL, 0x9FA9F6C556DA94ACULL, 0x57C3B60C8897ADCDULL, 0x9512B1BDDDF6BF07ULL, 
            0x2048A2DB05AE1DE0ULL, 0x6DB0B07A425685CBULL, 0x02A0D70F4DF10F6FULL, 0x9DAD2E7FB55D0DBFULL, 
            0x880F2C716EED2549ULL, 0x12F20337E6192BB8ULL, 0x064F1FB67789D34EULL, 0xF1F9B84AFA640A1AULL, 
            0x53D4107D63CC116BULL, 0x9A652A24EDD70817ULL, 0xA2320D3F33F831C6ULL, 0xCECB534853A42E75ULL, 
            0x650E1B6FA49CC714ULL, 0x5F12EA973238F6B5ULL, 0x36E8A28D30739F65ULL, 0x35AC2C125D4F659FULL
        },
        {
            0x2460B606E57CDBD7ULL, 0xB5C0070E5FEFBDCEULL, 0x9E84D54CF56762FCULL, 0x4C093FB314A1FD0AULL, 
            0xE259761DA43F5D5FULL, 0x75517E79EF1867A3ULL, 0x94D693384DE40B4EULL, 0x37269566162845C0ULL, 
            0x7FDB64E8AAB49D22ULL, 0xD3694BDF2830285DULL, 0x50E6D849324E9237ULL, 0xCB52287AA5C2EEF2ULL, 
            0x694C39180652B1C7ULL, 0xA846F466BF296412ULL, 0x7E9771913C721C53ULL, 0x59C30FBF0FB7ADB3ULL, 
            0xE823905BCBC9104EULL, 0x7E9FEA92F197988FULL, 0xA719150864D21D58ULL, 0xE9AFB4F99D6C33EFULL, 
            0xDFBB90020BA186DFULL, 0x1AD0DA5932E98DEBULL, 0x4A14A8907CFA7410ULL, 0xA2979BB26E790C26ULL, 
            0x554FB92D8226E4E0ULL, 0x90BA790924C4C571ULL, 0x0D9C2B2211B57883ULL, 0xD3AD43D1C3229960ULL, 
            0xE5D761008FC5AE9AULL, 0x53509E638B4A2BC3ULL, 0x091609AFCE6C2A6DULL, 0x8E567544F4D80C9DULL
        },
        {
            0x2F7BD304B991C364ULL, 0x7299F8828D8C72A7ULL, 0xEC036EB492B70385ULL, 0xD2E8D98EDD34D168ULL, 
            0x06D86860FBD887E6ULL, 0x6592DFEBCF35EB7EULL, 0x6EBCF5A1D68ED67FULL, 0x635DA5297ADCF871ULL, 
            0xA9CC86BB99056965ULL, 0xFC7AC020399707CFULL, 0x965EB8E16902BF09ULL, 0x90F93475F3060CC5ULL, 
            0x766B72572A958E97ULL, 0xF403617280C66153ULL, 0x99411AD4C3A1FBFFULL, 0xB76E10BE2C6DC115ULL, 
            0xC293B4F368D6495EULL, 0x6604592C19EF2F66ULL, 0xEB48117B25D0B686ULL, 0x4469B0F0084359CCULL, 
            0x6DA2E3D0D6F60D8EULL, 0xFC9AF697B5CA1D05ULL, 0x8E364FBD47B43B6DULL, 0xF6BC18B5C2EE34C6ULL, 
            0x83038951A33360E4ULL, 0x84AEDA16DF9CA2F8ULL, 0xC59F354F2FCE9D20ULL, 0x6E05BED13AD31D59ULL, 
            0x8D14679158B8A482ULL, 0x9948016FC1D49751ULL, 0xC83C5C43B3AE380CULL, 0x5C62CDE5228FBAE1ULL
        }
    },
    {
        {
            0x3F3876479EDF807CULL, 0xC600794C9B642BC0ULL, 0xAC76FEB886DE3340ULL, 0x5B93450CD26A4D31ULL, 
            0x4BB95FFAC03C14CAULL, 0xA7D204F7ED5A2919ULL, 0xFDCDD0934D3A187AULL, 0x3E58F3FE86B21C65ULL, 
            0x28CB2A97A609F89BULL, 0x777153DCFF77AD9BULL, 0x84697A5A63740B65ULL, 0x8E530B63F698E76CULL, 
            0x590A408F3F1D6B0BULL, 0x500830CD21902A9AULL, 0xD7D5F0F70CE8D934ULL, 0xAF41AE1AF9A2A9BAULL, 
            0x6A3DD486D7EB06C8ULL, 0xE33CB6D18C882836ULL, 0x26F83926A76C1584ULL, 0x409757807C564EBFULL, 
            0x00CFE8102F78E07EULL, 0xBC7B9B67373330C9ULL, 0x7B71B7FC7EA602EFULL, 0x3C452A286B0D7977ULL, 
            0x607A63447E90D8ECULL, 0xD52A4AC164E786E6ULL, 0xFE3AC57260E0BA77ULL, 0xA70D3E6655D12880ULL, 
            0x90F2C9CF8DCBA23EULL, 0xB36F3BBAA29E90C5ULL, 0x0B8327A8016CF3D1ULL, 0xA7D0F2FE40C2D682ULL
        },
        {
            0x825B04F2B303B702ULL, 0xE8179B5EF032DDA1ULL, 0x4DD141365849C9CAULL, 0x7D8F01A392C7339AULL, 
            0xDA9A7D631E4225D5ULL, 0xFFBB1B8CC20BB31EULL, 0x958E2519033FCE82ULL, 0xCAC377E20C63FCFCULL, 
            0x1576EC26D860AA4FULL, 0xBC980E5C3879321DULL, 0x5E3EE365F76F4467ULL, 0xE3CA29DE9853FE62ULL, 
            0x41BD2A0008DC6F3EULL, 0x4E8F4E7CB67B5014ULL, 0x80B0966D7EF32A07ULL, 0x6A067BA265A0CC9AULL, 
            0xFFBB45C5640D6A05ULL, 0x1556C6EA2FF5B121ULL, 0x9CF65852E2850BB0ULL, 0xF2E9FC5B0170E068ULL, 
            0x4F9E7FDE8B3A5682ULL, 0xCB6D8D18B1D0570EULL, 0x5660C639FF3EAF70ULL, 0xCB89C41BCF80F512ULL, 
            0xB9E86FD3B0141EE2ULL, 0x0390C060A356F915ULL, 0x6F0D6FF7978D02FBULL, 0xEBE2C519419F188DULL, 
            0x1910C4F42EAC8EAFULL, 0xA09FD5A8DC9D2173ULL, 0x63BE558AC2216ED3ULL, 0xE227A9E3F46D4956ULL
        },
        {
            0x803320874ED4ACE4ULL, 0xAECE86F2AF29EC51ULL, 0xBF1E0690E0A06AD2ULL, 0xE20E670BCC47935CULL, 
            0x0009A7EF3C008FE1ULL, 0x59C13AA3FAA2B3FFULL, 0x806C75029121CB7EULL, 0xC896D6F5607A8840ULL, 
            0xE238A927CA2956F6ULL, 0x9082F13A2F73CA9FULL, 0x73818E2BE1862578ULL, 0xE34341BE6E275CB3ULL, 
            0x48E3611AA04799A5ULL, 0x19A00394918EC693ULL, 0x61926BF31E119E75ULL, 0x3058E798F12BD74BULL, 
            0xE0046AA9C6F5CC66ULL, 0x0D66680CA68F89A8ULL, 0xB9F26102170306C4ULL, 0xA5666DCDA898B8B5ULL, 
            0x10C80E511B6815C2ULL, 0x3C0D21D2C14824A1ULL, 0x569B9F6856E2953DULL, 0x0E687E6204FD74D0ULL, 
            0x2426AB2530588227ULL, 0xD6C5B2491485DA4EULL, 0xE129BEFBDAF30010ULL, 0xD2A0C8230FE2C74BULL, 
            0x14C912F18BD2BD39ULL, 0x5EBCBC0251EDABCBULL, 0x53AB3B5C40A5B83DULL, 0x7F6F1F3B2E67E174ULL
        },
        {
            0xA33C8E0E43ACADFBULL, 0xBACEE8A9CB451249ULL, 0x75AA2BBD0F4EBAE6ULL, 0xEE174723E3EF7F80ULL, 
            0x25CC778107675E6DULL, 0x1D096C012276AD29ULL, 0xD7ECE53F0CE0AC9EULL, 0xF57BDD42A059B728ULL, 
            0xD43F2BFFA5583367ULL, 0x37BA1675CD89C154ULL, 0xB474B72287D7C8B4ULL, 0x044F6D43DE2B9FFAULL, 
            0xD5F2A2D197E9D912ULL, 0xBBCE4DDED9851ABBULL, 0x4BF29FBBDF3232CCULL, 0x750434D27DC2F727ULL, 
            0x72AB5EF040F30A32ULL, 0xE55824E1C5EEFC82ULL, 0xA95F7DF202C34B6DULL, 0x75F5BE77ED086491ULL, 
            0xA23C167667BAF5A9ULL, 0x49E7EB0B8F17AD65ULL, 0x1F4A161505C0C3ABULL, 0x59046F405270EEC5ULL, 
            0xDC95C811035056D0ULL, 0x3FA37AA56C3F3720ULL, 0xCA96A4AD6217E487ULL, 0x60017C5538BD8F92ULL, 
            0x4320F35C3AC8F3C3ULL, 0x68390A5F67006670ULL, 0xD2CC112D828F802AULL, 0x1150AE2BAAFE566BULL
        },
        {
            0xE21962753AF256F2ULL, 0xFD27FAAB807DAD32ULL, 0xFEF0BE9FD37B50FEULL, 0x0D7B8557DA895631ULL, 
            0xDD8562F16C6C765BULL, 0xA9877D87AE33B17AULL, 0x56ACA803DA95574CULL, 0xFD3FCBC82653054DULL, 
            0x12A4A80552CB8AEAULL, 0x70755D8CE644F833ULL, 0xFBF4C69BA5244382ULL, 0xBEAB8C718BB0A0C9ULL, 
            0xAB06CE1F3C60FF87ULL, 0x01877ECEE535403FULL, 0x4D11BABDC6C69A05ULL, 0x344A75B0C05FEB63ULL, 
            0x9C4E965A5E682DEDULL, 0x04ED11D81CC06C37ULL, 0xE194E529716274B5ULL, 0xEA2072988FC4914EULL, 
            0xBEC70A470405207AULL, 0xDC64215E2D241250ULL, 0x76D7C6563BFD1721ULL, 0x67801D176C8F10A7ULL, 
            0xE03B6EF0D3D5E65DULL, 0x79C69E9F8B5A0D94ULL, 0x7A71575FEF0646BAULL, 0x6ABB32A633B39A75ULL, 
            0xAE7E8F27CACC60AFULL, 0x3C8E2334EEFE74C3ULL, 0xD783187B52427841ULL, 0xC4B84A75115643B3ULL
        },
        {
            0x645F22E9D79E0D12ULL, 0xE024E8D978FE598CULL, 0x723DF15C545D2E3EULL, 0xCF3A4833C243AE4DULL, 
            0x2A22D058831B8D0CULL, 0x83222AFFAB38341DULL, 0x06DCE29B71CE9154ULL, 0x7E7040E5161AC234ULL, 
            0x80533DD7A71C221AULL, 0x2885B6D2568A9E17ULL, 0xF671455D43B50729ULL, 0x13EEA867A744CE96ULL, 
            0x7AD75C41BCEDD461ULL, 0x845A71BE77322E0BULL, 0x6B98630571EB5E07ULL, 0x9778E9FC0EAA6F17ULL, 
            0x0DC5328EACA8D032ULL, 0xE76F5072010AF108ULL, 0x9F1F8FD8588E7F96ULL, 0x431FA132AD1E8824ULL, 
            0x9F8C7AD6C8D657EFULL, 0x8D82917BF02CAF47ULL, 0x1EF28299ACCA5B95ULL, 0x63F0C72055246E44ULL, 
            0x54B2349E170E3D3FULL, 0x1D0830D7F3CD19D1ULL, 0x4F1FD08AB9961028ULL, 0x5ADEA365ED6C6508ULL, 
            0x629897C848E618FEULL, 0x3D9F266B8F6913BDULL, 0xF8FB7E6824F14E24ULL, 0x2D1CF5D5BE489B11ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseCConstants = {
    0xDC57858F744E34F4ULL,
    0x8112090F4CDA321DULL,
    0x29B235913C48A910ULL,
    0xDC57858F744E34F4ULL,
    0x8112090F4CDA321DULL,
    0x29B235913C48A910ULL,
    0xC9D0F75D68E317BEULL,
    0x63312923BDB25081ULL,
    0x25,
    0xDA,
    0xEF,
    0x77,
    0x7A,
    0x40,
    0xB1,
    0x71
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseDSalts = {
    {
        {
            0xAE82CA00DC42668CULL, 0x34D5E9DE316C7701ULL, 0x70849E1E82158482ULL, 0x3C5353F044D163E9ULL, 
            0x13368354E33E15B4ULL, 0xEFE39FCAB69046FDULL, 0xFA764E81623D6F41ULL, 0x364310E1A317396DULL, 
            0x246BFC6635AF3AD6ULL, 0x625A753B9CBB897BULL, 0x1AFD9A4D511B2ECFULL, 0x2F8DF6CA367C564DULL, 
            0x4D7E2261836F152CULL, 0xF877047D1A905969ULL, 0xD028E009E1507BFAULL, 0x721D8084FAA3D048ULL, 
            0xD1C6F3AE8C67CC99ULL, 0x078D871E17F5E16BULL, 0xD8950491915DBB1FULL, 0xF601597AE6F601FDULL, 
            0x4A86D1DB0FF820EDULL, 0x20E8ADC26FB04435ULL, 0x80590894B23C6FB2ULL, 0x40FDDABD50D5824DULL, 
            0xD89899EC9253AA77ULL, 0xD1EBBFE3222C0C91ULL, 0x660D2AB564EF4256ULL, 0x5163BA69978A4B7DULL, 
            0x7E4F2524C5E0C42FULL, 0x659BB14176A5DBAAULL, 0x7559215A0509D4DAULL, 0xDA94BA4A24B7FF05ULL
        },
        {
            0xA275DC35BDF4F667ULL, 0xA5BA824A8CE2A859ULL, 0x07279831321B3CE8ULL, 0x09E5AA9AECF706DDULL, 
            0x71D16E8BFEEA45E1ULL, 0xEDFC8D2A58C34F6CULL, 0x3A4C891D2F53F50BULL, 0x8C9B31C330E1D0BEULL, 
            0x2BA8C9884202251CULL, 0xD5CB30DBB388B803ULL, 0x9D4D637D4AC550EEULL, 0x574BD0EB396DCF35ULL, 
            0x73682C0902487EAAULL, 0xFCD6B38AB58EFC67ULL, 0xE3B5B026EE1DFFCFULL, 0x1E0BA72D68916196ULL, 
            0xBD9584ED8C7E982BULL, 0x219230AB70A9ED66ULL, 0xB287744628505B9FULL, 0x5092CB8829B02875ULL, 
            0x655E75555157F0DDULL, 0x09FC02415CB62654ULL, 0x8B19D3200CE709F5ULL, 0xA9C5D554FDDE2EF8ULL, 
            0x4923A72F351AC8B8ULL, 0x7581D98E569A5CEBULL, 0xADB3D855B2EE5E74ULL, 0xD43D2A00DF8968E5ULL, 
            0x9D32265FD7C8E296ULL, 0xC098077FD03693C2ULL, 0x2B9631C01F92D230ULL, 0x1287DBCE47E82EA1ULL
        },
        {
            0xEF9DBABEC5D8230DULL, 0xCD7F37C14ACF0C59ULL, 0xF2600EDC48A32BA0ULL, 0x6C8D7776D23542CDULL, 
            0x6E9FCC6E8089BB83ULL, 0x61182BA8E5B2A852ULL, 0xB1DE6BD875272EEDULL, 0x05D7E60365300B0EULL, 
            0x87BAD119487FB350ULL, 0x8F51E75DDCE9F831ULL, 0xBCC4253DD6F94746ULL, 0xBE67AE6609950538ULL, 
            0xD9DCD9E8B9F54544ULL, 0x9BD439F890DA883FULL, 0x05D5BB2E32D096CEULL, 0x32D1CD355D69D240ULL, 
            0x23C0210B53D9BEA4ULL, 0xADCD8CD43F666F18ULL, 0x1B422C59607BDF74ULL, 0x434C3242BE474DD0ULL, 
            0x3552BD383474B84FULL, 0xB2BB56954698876CULL, 0xA8E6F14B2A0548C0ULL, 0x5A6461BFE5B43ED7ULL, 
            0xF703809F93FA5705ULL, 0xE9BA3CEC30751873ULL, 0xBCFF378345CBA59AULL, 0xAACF0A704C66086CULL, 
            0x897E7F4BF49DBC36ULL, 0x424F49BC365ABEC8ULL, 0x15EAC007FF991B56ULL, 0x511726F70C7FB200ULL
        },
        {
            0x85A77A8D36927AA9ULL, 0xDEEDDC917DC4E676ULL, 0xC653AF525DA1FD61ULL, 0xA3E6128BC68AF72CULL, 
            0x6B526CF162D8D8CEULL, 0x17C72CFAAC402CBEULL, 0xD7B13D970F218AA3ULL, 0x653395E2862A3866ULL, 
            0x161607240A660EB1ULL, 0xC5707D9D4FCD3433ULL, 0xB12843DC186C8CFBULL, 0x8C78CF1F6488DE3AULL, 
            0x56E29ABBAD42B0F2ULL, 0x728177B30444B458ULL, 0x49D332F34DC11BF2ULL, 0x527F359E394E5E18ULL, 
            0xA4D724E8B2070D0CULL, 0xB440DF8B18AB0EBDULL, 0xC996F949D4467AF3ULL, 0x51BD87ACF9E4EB33ULL, 
            0x0496CA5AB9C32E7EULL, 0x39B26F0FA1FFD4D6ULL, 0x6CF61D58D5F1BEA5ULL, 0xABAFF783CEE3C358ULL, 
            0x47EE3AF730B0348EULL, 0x0A46F150ABEB9373ULL, 0x53028EFE5B03475EULL, 0x22271F21FACB3872ULL, 
            0x73E09F0D4CB62F6FULL, 0xC6163EC947E9ECCEULL, 0xAB227B0D6DC36AF5ULL, 0x2C56C0E7A36E975BULL
        },
        {
            0xEA12AC091E88A11CULL, 0xF283373B5DD83E67ULL, 0xEA10C1295F0E0B6BULL, 0x9549954C1300BB7DULL, 
            0x1DE1A6B43B511910ULL, 0xB7326E2DEA89F76AULL, 0x917070AD8F403328ULL, 0xF3DD8CD1A32BD014ULL, 
            0x8A65A0A0B9BED9E8ULL, 0x04D0FB394F1FFF44ULL, 0x6C7D380FDF5CD93DULL, 0x30BA6789A3DCD8DCULL, 
            0x2703C86086DC9AD2ULL, 0xA6D862CD3019CECCULL, 0xC713E6717E36C248ULL, 0x0EAC4070B381B1E0ULL, 
            0x2C13C0D39E0FC775ULL, 0x8B303434DE713205ULL, 0xFC093D5450C33F99ULL, 0x3753A45DCC7D9524ULL, 
            0xAE895F5BCC7C0C07ULL, 0x34FF5C52683A8490ULL, 0xD04938DC15E5B46FULL, 0x33846AACA54AFB97ULL, 
            0x0CA358A3821E5959ULL, 0xEA37D5734D374CD3ULL, 0xFA26F492AEF80C8FULL, 0xAB0FC80786D1C38DULL, 
            0xCD3373384FA8A8B6ULL, 0xAC0E26797379569AULL, 0xB14ADF7EBDAA419CULL, 0x5DDF57215375390BULL
        },
        {
            0xB4E6D66D6EB33D55ULL, 0x93F8B1DB8F622F4FULL, 0x530CF927C47D6044ULL, 0x9BED90BF48DD9B7FULL, 
            0xD4D72AE04FE07B01ULL, 0x64FDEE1BB3545061ULL, 0xBD4866B810CE8E60ULL, 0x29E2BB03CA0210E3ULL, 
            0x1A4748D250DD166EULL, 0xDADD30CF830C0BFFULL, 0xAAA8C644D3514DAFULL, 0x425ADE799847A9EBULL, 
            0x762F77643D3EF3BBULL, 0x8FF0A272B133453DULL, 0xA99E46B4EEE2D660ULL, 0x321EED06622292EBULL, 
            0xA179A72A61CFB8EAULL, 0x4EA4F3C36FDF9DEFULL, 0xDE931B49123FFD72ULL, 0x79B78915E29A15F2ULL, 
            0xB7725ECE05309116ULL, 0x2BB948F80156F27CULL, 0x6A39A797C613247AULL, 0x4CDEDBDC9ACABE41ULL, 
            0x8BB90EE76234BCD6ULL, 0x06CD2889604B02D7ULL, 0xA8CF4BBC9ACF86A4ULL, 0xFE45BE2878D0821CULL, 
            0xA2B24869F18B7484ULL, 0x9B815A751970723DULL, 0x93ABA1B466C97A3EULL, 0xE2B054930C66DBCDULL
        }
    },
    {
        {
            0x3E47EE395992B759ULL, 0xEE14D84F97216B93ULL, 0xCEC15E117CEA93F1ULL, 0xBB6E8B7DBC94C4BCULL, 
            0x25508AF12BDF2139ULL, 0xA84CF8D540E92D14ULL, 0xE028A93BED45FC8AULL, 0xC4530397CFC50BDCULL, 
            0x6A1AD5DC9BE36D99ULL, 0xC0D960AFCC400784ULL, 0x813E22447BC72608ULL, 0x6DEB8840DE3315FBULL, 
            0xBEA646CCD2906666ULL, 0xD997C92FC56B8B41ULL, 0xCE7EDED04286F1A3ULL, 0x68C174EE32066407ULL, 
            0x07CB75FA46F9603CULL, 0x106528EDD9E75BCEULL, 0xA7061378DF2A0051ULL, 0xF239B6AC808AA5AAULL, 
            0xC125817DD05D73A7ULL, 0x201EA55A324BED2CULL, 0x3F6C4CD003CA4B50ULL, 0xE8AE68E9AA97E856ULL, 
            0xF5CD4B0B24EF914CULL, 0x7EB898AF8D06E540ULL, 0x9CC30502B054B2ECULL, 0x5D939760A6A7111EULL, 
            0x90A08503123CFF3DULL, 0xDC6DD0A8F74FF1EBULL, 0x354C597B647A8C22ULL, 0x1D20B48722EA67EDULL
        },
        {
            0x79800F5B490E3E26ULL, 0xD2C43539AEDCB301ULL, 0xD09D03CC2AA28B27ULL, 0x00358E293B40C011ULL, 
            0xC746C2B3D080AB90ULL, 0xFB02DA6DBFC0DD81ULL, 0x499961E71388E704ULL, 0x5A4ED82FD491C834ULL, 
            0x94A6C9F1CFD45151ULL, 0xACC7F30D82DF73F8ULL, 0xE39CC7E301E71499ULL, 0x1DFD9FDA771CD808ULL, 
            0xA696ADDD99B8BB8CULL, 0x8100C9BFC9B004F7ULL, 0xE07715F12C51EA76ULL, 0x6575130FAF93C905ULL, 
            0x6C6ED031B0644D61ULL, 0x421E5079FAB4E167ULL, 0xE0EEBD3E5CE306A1ULL, 0x04F53ADD70BC73D2ULL, 
            0xB7ACC86980FD698FULL, 0x2E49F2BE78E27254ULL, 0xDA3766D2FA4F3803ULL, 0x16052EE768200220ULL, 
            0x0297CAD3D7CAF108ULL, 0xD589D88FFC603230ULL, 0xE15EDC3BF11DD3B9ULL, 0x29DDE5318634F4B1ULL, 
            0x6F8D6481FCE482B3ULL, 0x722AFABF14A15B52ULL, 0xC0CF9DF94C59515CULL, 0xE6728FCC7D50A7DCULL
        },
        {
            0x4EA499B70A5CB1ADULL, 0x932F065391A75BA4ULL, 0x0101B72743B0D2C0ULL, 0xB0C44CFE5B703445ULL, 
            0x45B5A9369F0397CEULL, 0x85AB9E0E5DEFB7D9ULL, 0xD3485700CEE62E46ULL, 0xBA7447BD448CED36ULL, 
            0x8A0AF7A7029E3EA8ULL, 0x9842E4DF0E7D5348ULL, 0xE542A1F1696D73B1ULL, 0xA4421D71D2D1A8C2ULL, 
            0xBC59B5AC73C11BFCULL, 0x8A0C3502E2AAC640ULL, 0xEB7A64410051A3FCULL, 0x7384C3A4D85D6914ULL, 
            0x2F0A2669EB7809D4ULL, 0xE1E3374C35046139ULL, 0x6E143C6A97C1B856ULL, 0xBEB726BD111D85CBULL, 
            0x0A5B80FFFC667D03ULL, 0xB408116C3278E49DULL, 0xCC1E74DF435D1247ULL, 0x870BC05EBCA02E9CULL, 
            0x4C1CBF25588FEF74ULL, 0xA1083A03326BEA6EULL, 0x38B924682B29D9F2ULL, 0x488707D87898F3F8ULL, 
            0xAC7E54F098F0DDC3ULL, 0x089841427AB712C1ULL, 0xDB8C4D5DF25720D5ULL, 0x2325FEC8FF743313ULL
        },
        {
            0x255F4ED65DD56CA3ULL, 0xB2D5C6DC48883C69ULL, 0xD1FA805B15F99988ULL, 0x2F6E364C0DB67550ULL, 
            0x89C83165571F5B37ULL, 0x5D683341865ABB80ULL, 0xBECF531C03020B1FULL, 0xB36D04AAC52BF8FCULL, 
            0xE6F9D3AB78F49996ULL, 0xFA4E01C11055A830ULL, 0xBBDEA39B12056E26ULL, 0xDD5BFDB8F0E27A64ULL, 
            0x1B28EBF0FB27F755ULL, 0x0BAC808677BF4C37ULL, 0x1D71BE184246C329ULL, 0x399F4BB65D52699FULL, 
            0x67D225BE7CFE0897ULL, 0xE5881A0CBFDC6ABAULL, 0xE13995FAAD2470F2ULL, 0xCB23B9AAFC5A6FCDULL, 
            0x2A61D32428DD9137ULL, 0xEA07598FC5FE0ADEULL, 0xDAD4A50E6CF603B3ULL, 0x32EA14F668465F13ULL, 
            0xACB731807F3204D7ULL, 0xA3C2A86D4B08ECE9ULL, 0x5A4442FA212FE428ULL, 0xAC311C97BF3CBD64ULL, 
            0x9942323444AD1D5BULL, 0x6BCA7A0A23D2202AULL, 0xF37E9911CC424D91ULL, 0x4227176487FB6BD6ULL
        },
        {
            0xA568923B604DB3F7ULL, 0x0ECDDAA865C8937CULL, 0xE9FAD34669A98A27ULL, 0x262F09A7132CCA9BULL, 
            0xB4EC3D6168D05EEFULL, 0x733A3F159B320BB4ULL, 0xA71F842181CE5608ULL, 0x912D757546CE7169ULL, 
            0xABBEB5F709A678BFULL, 0xFF3DA5D3D37FFB37ULL, 0x55EA58C1D32F6642ULL, 0x1687644E3FDB1226ULL, 
            0x665C6DD8BACC107BULL, 0x98A754B894EAC656ULL, 0x6C446D558F8ABB75ULL, 0xD7C46BF010FD0086ULL, 
            0x0209BFE31858B573ULL, 0x04758619B5549C5AULL, 0x45EE89EA91A8B103ULL, 0xCD4FE948CE146423ULL, 
            0x1E293A675442B008ULL, 0x3F148A08241EC509ULL, 0x1FC38534F7E2AF1AULL, 0xE9787A4BB916F8CBULL, 
            0x9FBDFFE6B5F08A74ULL, 0xE87E9819591D72D3ULL, 0xDDEB3F50C2995CB0ULL, 0x7510AED22B715C14ULL, 
            0xC34A393FDCE8CDD7ULL, 0x629A633C09E4A595ULL, 0xFD16351D074A3F0EULL, 0xF4DFA0A2855CC438ULL
        },
        {
            0x62313FAF0B2C4C9EULL, 0x7AECFE7BCA9E62D6ULL, 0xE125A3B787978045ULL, 0x8C469AE26551571DULL, 
            0x86B61142D4F595D6ULL, 0x08E2B171F7C54463ULL, 0xDB60FC5B4BFE03B6ULL, 0x909BB9F1F6393222ULL, 
            0x485231BC22D53430ULL, 0xDF8929F7CD33E048ULL, 0x435AEB9C05C5FD60ULL, 0xC1E581015351E49AULL, 
            0x0B1F5C454EEAF34BULL, 0x44077BFF77E536A3ULL, 0x3BD7B9CBF0F514F5ULL, 0x60583EC69B918194ULL, 
            0x0807B63B6817947EULL, 0x118326396411FD5CULL, 0x154C8C47D14A5C8CULL, 0xCBF9871E3A4A5475ULL, 
            0xAB05C62F1D6BBF58ULL, 0xD91F5587D06E81BEULL, 0xA263F71D051E03E2ULL, 0x59E2C07969E1A437ULL, 
            0xAF8627C4062C39D2ULL, 0x5E400CB8D4499B5EULL, 0x80CB71175911B566ULL, 0x2327F118E4DB9577ULL, 
            0x5BFEFD3B69707D63ULL, 0xCAD69FD58908F584ULL, 0x070ECE59CD3775B3ULL, 0xCE209A99E130ED40ULL
        }
    },
    {
        {
            0x67B3132D97008BB7ULL, 0x82943FD956B42506ULL, 0x4C70B37CA6FF93C5ULL, 0xD0385439EBC81D6FULL, 
            0xA5185C4F1C342BFEULL, 0x619CA2B6380B6FE2ULL, 0x5CE5FFC86D6F8388ULL, 0xA3357528386BD22AULL, 
            0x7539D4F61D89FD8FULL, 0x2D73338CA6A6F4CBULL, 0xA54B4F1FB9CE7B1BULL, 0xFCAE18DA05C2FE89ULL, 
            0x5D9F7A4B3020196EULL, 0xB6AA2AC18E87DB5DULL, 0xA6A28AB87440895DULL, 0x3DF93138B61BA89AULL, 
            0x744CF7013B8D1420ULL, 0xB3A4F602681B5282ULL, 0x648D3EBDE27B3742ULL, 0x97E409B9B7F870A1ULL, 
            0x054F401DB33D8CE1ULL, 0x41AE9DCEADC796C9ULL, 0x053E77A89FFEFA1DULL, 0xCC92E3854996AD7EULL, 
            0xDAF053B8E80EE1DDULL, 0xB78BF7A925E8C27CULL, 0x069A912067168FF7ULL, 0xA7C2F5BF66BA01B5ULL, 
            0xB1A6A29B14047C56ULL, 0x7B20FFB6FB348BC7ULL, 0x544C82F40E3F50D2ULL, 0x5F7014DA85EDBB80ULL
        },
        {
            0x7A8D909AD3FB36AEULL, 0x4713DE7E19788710ULL, 0xBCB7AC454F757324ULL, 0x9E379BDEE268C63EULL, 
            0x5C3607F9F38DB4B5ULL, 0xA1E1B2FC7376585BULL, 0x02AFB076AAAD963EULL, 0x011E41A9D0083563ULL, 
            0xB59CE36C472D4809ULL, 0x8CD7BC0D2ED5E2A1ULL, 0x8BB999191C96DCC5ULL, 0xA9EB32321EDE0302ULL, 
            0x40652CBD7DC2D007ULL, 0xA7A1D615A6302EC4ULL, 0xDD4CBC71BF4159DAULL, 0x6FEEB3E24EDEE095ULL, 
            0x18962DE80884ED84ULL, 0x11EC25CB8A32D3BEULL, 0x98ECCEAA57F4EACCULL, 0xDC4F91B0E193845DULL, 
            0xABD6A05444686855ULL, 0x2BF33B9A5C543C66ULL, 0xD57E6F681BB95D0EULL, 0xBE0ACFCBE0D88197ULL, 
            0xEAE29E36E64AA11BULL, 0xD2B7AB4AF124BE73ULL, 0x095513F3BCA0C044ULL, 0x242C72556D45817BULL, 
            0xDE8863511F6F89DAULL, 0x0D27E7A58BD8F066ULL, 0x73D64C61FCF4129AULL, 0x90E0F7C6E02A2FCCULL
        },
        {
            0x591796F1A80648ADULL, 0xDC8DAC482CB2ABF7ULL, 0xD32B4C5768C6BD2FULL, 0x48B3067BE9F91A44ULL, 
            0xE00F15A622D9B80DULL, 0xBCFF87482C188B7FULL, 0xC296D9972793BD15ULL, 0xC548A9A2BA8290E2ULL, 
            0x1092FBFBA93BE54FULL, 0xE326EAE4464EDC01ULL, 0x812C1E88DB05CAFDULL, 0xB819AF3DA896E9A0ULL, 
            0x010158AE1D9D2DC0ULL, 0xEBA187E7D4B1AB5CULL, 0x632592C4E836C32DULL, 0x512BD3E888288C69ULL, 
            0x2968BBA824A69A5BULL, 0xC1B136FD0502032BULL, 0x4D910A46B336C3B3ULL, 0x68E22FAE7EAED80DULL, 
            0xC6768B7617250BF2ULL, 0xF50D1905339CC454ULL, 0x56805179224C8915ULL, 0xBD12436A457E3E3AULL, 
            0x94A2B83C84985C0BULL, 0xBB7233011BD20953ULL, 0xA0A15A5BDC56423BULL, 0x3A37E5037C5F50ECULL, 
            0xC56C131C6CBCD90BULL, 0x31B49A0933CE5FAAULL, 0xC597E9EB962E6436ULL, 0xD87CBA6F5AD9A3F3ULL
        },
        {
            0xFB7F99FFAEEC0EF2ULL, 0xF38103E7287B52A3ULL, 0x4D0BDEDEBE1A1CA8ULL, 0x99CD5A077DCCFB00ULL, 
            0x573D10E07F8BAE6AULL, 0xFF8A119473CCC411ULL, 0x849D606852BB2F36ULL, 0xE2A258E559D88D82ULL, 
            0x747F52D301E1874FULL, 0xA14B047657FF718DULL, 0xFDC3A65D33C13FE3ULL, 0x8D23CBCB638AF3D0ULL, 
            0x03CF17EE24A65EB6ULL, 0xA8E7CB4DE213DC2CULL, 0xEB6D7E3189594F84ULL, 0xC94903F6E02B573AULL, 
            0x08238C806D076BADULL, 0xCCB214B6F9BCB16FULL, 0xA5AF8173C39868AFULL, 0xD8871FF28CD5A8F9ULL, 
            0x99BD6D2B00F02AE4ULL, 0x512C7CF959E30589ULL, 0x8D549FA0F9571454ULL, 0x5494E17200B16C51ULL, 
            0xB565DBC97B700FCFULL, 0x3B79B18B3BB9C71BULL, 0xC93FE489D91980F8ULL, 0xB81B4D74ED6FC2F7ULL, 
            0x98AED2CAD274B75AULL, 0x8FAD63AABA3F9FE4ULL, 0x91C6D03C0962BE0FULL, 0xD3025EBF781209DDULL
        },
        {
            0x8B2D3E6E513BD578ULL, 0x438CA4C0BA286F90ULL, 0xF545E3331C01BCEBULL, 0x1E2E96C5B18CA243ULL, 
            0x43B8EE8A7243446FULL, 0x4BEDEFFF10BBFD75ULL, 0x9385F6CDD8C47D9BULL, 0xE5C62281754392BAULL, 
            0x3CBCB66920895F55ULL, 0xE42F1010A6F88998ULL, 0x3C0D3B1C17E5D4C5ULL, 0x526AC7AFAFDDDF09ULL, 
            0x598389971E581877ULL, 0x59A6821B6D29CFE0ULL, 0x71491741F3EEE52EULL, 0xB410FC32C3F264B8ULL, 
            0xB8D5B701CC6B0B5BULL, 0x1E8498C2B021AED5ULL, 0xE0B4A8417132E10BULL, 0x029DF7E9935F0183ULL, 
            0x4A3A30620F656494ULL, 0x13169371050C0409ULL, 0x295C754A1AC8D254ULL, 0x06D0791355400B93ULL, 
            0xD12EDEA5C34A4741ULL, 0xB613F09FBFDD9876ULL, 0xF14C745074F0575BULL, 0x04EAA269EFB007DBULL, 
            0xA57666F70BF54863ULL, 0xDBC9A132CFF91F89ULL, 0x2765F16F97BC4ACCULL, 0x5B04AB983095F98BULL
        },
        {
            0x88E5F096E404E269ULL, 0x380753C0C90AAB15ULL, 0xB0221A6E7B387FEDULL, 0x7EC3097D43FA2F50ULL, 
            0x7DCA0851ED0F6F77ULL, 0x3D68805350B10388ULL, 0x668B1F6CF4018BC3ULL, 0x57B254D4724D6AADULL, 
            0x80B26122EBB28343ULL, 0xECD0D91B79365889ULL, 0xE9A36A4B3098CAC0ULL, 0x133084A1D5BAAC29ULL, 
            0x9645ACBED299C2EFULL, 0x8F7A0E5D57243B17ULL, 0x137367940CA6439AULL, 0x554249AFCABA4BEDULL, 
            0x1FD02063BB02A274ULL, 0x70D0D8D6560B3B15ULL, 0x47BFBD660B00B43AULL, 0x8D31B27722A912BAULL, 
            0xB56537E0A1583DFDULL, 0xA5E7B316CD566989ULL, 0xE934EB0D0FB29886ULL, 0x52A7C8D214289407ULL, 
            0xA2EB69E66D34BA8CULL, 0xE4FCC712F69344AEULL, 0x1101AF6B49EBC272ULL, 0xAEA4341826F554F7ULL, 
            0x355383144F1E87E9ULL, 0x37EA896850767E88ULL, 0xE9945B496296E8A0ULL, 0x2AC4F22DF72C0EBCULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseDConstants = {
    0x368BACB8DD87BB89ULL,
    0x453F6206FD17CA4DULL,
    0xC51217BBFDDD2E80ULL,
    0x368BACB8DD87BB89ULL,
    0x453F6206FD17CA4DULL,
    0xC51217BBFDDD2E80ULL,
    0xFBC88090409D49DFULL,
    0xD431910BB18B0CFAULL,
    0x01,
    0x58,
    0x9C,
    0x37,
    0x6E,
    0x2E,
    0x40,
    0x35
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseESalts = {
    {
        {
            0xF113066447AAA68BULL, 0x0D17EDEB90946848ULL, 0x32D6270D8015A50AULL, 0x1749E1B7D7BA3E9AULL, 
            0x8C9C75CCA5B68CFEULL, 0x3394E8A8C107C930ULL, 0x5E53E099786FDBB4ULL, 0x76B2005434929D11ULL, 
            0xFCBF9077ECFAA98AULL, 0x24ABDB3898A6A602ULL, 0x2292D2AC3B4FDBCBULL, 0x14936A594BC34463ULL, 
            0xD0D752E1EA757077ULL, 0xCC63C651EFBD56A3ULL, 0x44AB4BBF158569F6ULL, 0xFBF12D0C54C8A424ULL, 
            0x6170B7C18660ADE5ULL, 0x43BFF83B31498E4EULL, 0x67F373FDA356675AULL, 0x469E8A639337A7F2ULL, 
            0x272E1B8FC9AEEE41ULL, 0x13E874BDCC91947CULL, 0x9591DBA6BB4591EFULL, 0x4E5EED0B2523EA5AULL, 
            0xA7AE628FC05BAD21ULL, 0x68FBD6042F3DFC59ULL, 0xDEBDE48292036577ULL, 0xC9CC6E36706C27C3ULL, 
            0xC134615AA8AB5A31ULL, 0xA50B318434D4ACCDULL, 0x2CED0649BB8A8B20ULL, 0x4DAABA86535808DFULL
        },
        {
            0x792BC056EC5BEF30ULL, 0x7CE4FFA128ED457FULL, 0xD3ACA81D094E01B9ULL, 0xB5C7507BFC439EEEULL, 
            0xB2137FFE864E7A88ULL, 0x904A20A277A9A81DULL, 0x86CD57A493D7C56AULL, 0xF5123E4351DC5B72ULL, 
            0x01F5713D941D4F79ULL, 0xA312E8F183475F61ULL, 0x08C4EEE4B3D302D1ULL, 0x09D5B21262E80FA2ULL, 
            0x28713645A6EF7583ULL, 0x528C7077B1553005ULL, 0x4A91EBAFFA929F3EULL, 0x3B002F7313E44BCDULL, 
            0x192059FBE29B4EBCULL, 0xE46FEF959B8E3717ULL, 0xBD8F7DB6BD964534ULL, 0x4C6F060442D0A5BFULL, 
            0x2423E52C2F118E35ULL, 0xBE15601F053A7A97ULL, 0x183FF9DBF648056EULL, 0x93BEB5B61AFE1DCBULL, 
            0xD5885F92D9E0ED20ULL, 0xBA830F40600CD725ULL, 0x2A7B40B440020A4AULL, 0xFD8E3FBB12FA9577ULL, 
            0x302485617907C29DULL, 0xA290EE0DD7B96C6BULL, 0xBED684DB1AD43551ULL, 0xE99175330D184ECDULL
        },
        {
            0x3293EC88303B2E92ULL, 0x1DDFAB5C144701D3ULL, 0x7D148CF9E40F669BULL, 0x763691CFE8DF51B0ULL, 
            0x672AD2E5BC1EE94EULL, 0xDAFA7F0823D2887DULL, 0x18E2CEDD97851ABAULL, 0x87A7A4DA15F53327ULL, 
            0xF544406107E99F67ULL, 0x19EDE7D0DD512740ULL, 0xBF17F41B23C1EC51ULL, 0xC7D5F26798B4CC26ULL, 
            0x4D7FC274EDDCD62AULL, 0x4A7B11391561BF50ULL, 0xB5B99C1520B3D211ULL, 0xA291DD1C0019DE2AULL, 
            0x0856DE1BF8793485ULL, 0x7FE457BCBD105641ULL, 0xB9CA34D605D54047ULL, 0x08AAF8F357F20F3CULL, 
            0x82D731149B325304ULL, 0x28828B3D8B40E6CCULL, 0x39BDEC5F0F8E1861ULL, 0x48119F8F3A5E7DF5ULL, 
            0x00FA2E41E55E5C8BULL, 0x4478D85FCC0A4800ULL, 0x84E94991EBEF75EEULL, 0x2C449EE0AA3D77ADULL, 
            0x8C3143E500131AE5ULL, 0x3EB77CDE684BA803ULL, 0x64E196BA4AFEF886ULL, 0x3DC6F93C40023827ULL
        },
        {
            0xB5F3451686C20284ULL, 0xD46D2D1EBB21B96EULL, 0x6410B9579B51C97FULL, 0x82DBAE2D4BB85827ULL, 
            0x569DE40076405189ULL, 0x4EA85554FC964B8AULL, 0xD6F2466F4930D338ULL, 0xF5C42955E6C8D4DDULL, 
            0x022D3029F994D9B1ULL, 0x411F16D86FB3D6EEULL, 0xCD41F1DA8FD473FBULL, 0x5B06CED8474397D1ULL, 
            0x49D0F4AAC8CAE9C7ULL, 0x89550C0239578638ULL, 0x70F19E859372B6A9ULL, 0x8A194B3E4B879817ULL, 
            0x212604EA132DE130ULL, 0x803B301B8C2DB520ULL, 0xDDC9274D148FF978ULL, 0x8C7113A03ADCB4F7ULL, 
            0x71EC0AC053F9833DULL, 0x71C15D5252E0C281ULL, 0xD0B7854B25DB19A1ULL, 0x92D5EB18448906A0ULL, 
            0x52020EB3CCBF534CULL, 0x5130261AE57F19CBULL, 0xF20518641412607FULL, 0x4A5BCBCA40EC4479ULL, 
            0x3F51D6979203910BULL, 0x20E2F619AD706493ULL, 0x539163FD4C101D6FULL, 0x8E9B0A9FA168B23BULL
        },
        {
            0x4980CD426FFA5787ULL, 0x6A6BB1B4A464E946ULL, 0xE36BDF41855997F5ULL, 0x430D0EADA3B28147ULL, 
            0xC0CD2BDFB9FA022FULL, 0x705CCFFDC34DBDB7ULL, 0xE3BE7F675CE85D10ULL, 0xF28D5D0554B7707BULL, 
            0x4B1C8DB416EC2B2AULL, 0xDFC8BA476CBEB7F1ULL, 0xF8E3671C2B4B913DULL, 0xA9E35206AC883D64ULL, 
            0xE1AD0ECBE4E2C831ULL, 0xBEB735A798F741EAULL, 0x6F96AEC0A6CF7F11ULL, 0x84AEBCCBC038F73BULL, 
            0x2C8A23313DB6E536ULL, 0x4C5462CB15F13668ULL, 0xB4F925E6AE9C24EBULL, 0xE03AADF0B7021E0DULL, 
            0x9E05EEDB1E101AE0ULL, 0x60CF20EFE1142A48ULL, 0xE98A9CC7BF6122C0ULL, 0x51D095D0C1B862F2ULL, 
            0x4467D017C3957431ULL, 0x11DB4B0A514201DDULL, 0x4CCB8C9F6690C6C5ULL, 0x422E4C02BD4429CFULL, 
            0xB314B1E79C14199EULL, 0xF119EA804809256DULL, 0x1557B87F59E8342DULL, 0xD1E4A19B2BF0EEC9ULL
        },
        {
            0xEC6216B9EB1DC53BULL, 0x7878806895847BB8ULL, 0xC61456E4FE7673C9ULL, 0x95E6D78CF9C84D32ULL, 
            0x311F7C37B96DDC21ULL, 0x69B103B96CFBAA5AULL, 0x0C8542ACAE2E0D05ULL, 0x551F8D315F390F17ULL, 
            0x834A562161AD361DULL, 0xD117C60E33349244ULL, 0x09398AA5A08911FAULL, 0xAA98CBBD54B0E357ULL, 
            0xD501747EC67F10B3ULL, 0x10405459B8BC8E43ULL, 0x7FAC69E04DFE3182ULL, 0x1F977CD0E9843DD8ULL, 
            0x68BEC3B2AEF15917ULL, 0xDB3ABD78DD6FB581ULL, 0xDA53F55F8C811551ULL, 0xCB508B16A13B4560ULL, 
            0xABDB851D6FA7920BULL, 0x4950063AFB1CD625ULL, 0xFA4D8E69607C45DFULL, 0x5F2A673BDF843BB8ULL, 
            0xDF92E4F3D4A1FF94ULL, 0x1B2D0EBD19DA5D79ULL, 0x195CFBBB8F7FA48CULL, 0x8F2FF93746C23515ULL, 
            0x61DC90F01553D224ULL, 0x4D7F90D6B5937947ULL, 0x3D83078D719FD9C0ULL, 0xAEB36A709A21BD8EULL
        }
    },
    {
        {
            0x1BC907F11D3DD4A3ULL, 0x737E7676E4D6299DULL, 0x9D1E057EF0075650ULL, 0x132F2DD7BFF5DE6BULL, 
            0x2C56D394BA109C8FULL, 0xB8F0BC63E1BC36E6ULL, 0xDF8171C64A423527ULL, 0xBE6F141F653E48E8ULL, 
            0xF418ADA37C81AAC4ULL, 0x0C91039D03B96B40ULL, 0x8193F32501141448ULL, 0xA152D64A5DB7BA76ULL, 
            0x1F20A342B06727F6ULL, 0x7496264332639476ULL, 0xC226333E1D8465BFULL, 0xE9328BF3AF79E728ULL, 
            0xAAD2CE5F615A196CULL, 0x7FCC3AEAEF5D3C4BULL, 0x84F604D10E2D8297ULL, 0x0F50BD0EB943BBDAULL, 
            0xEF46D349465BC4DEULL, 0xEC303AB14365FA9CULL, 0xF146CCD7445FE443ULL, 0x43CE325CE353708BULL, 
            0xAD94807181D615A7ULL, 0x4F9625FFC256C03DULL, 0x2289D8BE2537DF48ULL, 0x294CBC274770D91CULL, 
            0x5DE0FA317C7F5D63ULL, 0x378EF2125F5455A1ULL, 0xA28B502273AB7FBCULL, 0x0E05F9048405DB51ULL
        },
        {
            0x22B1C4233F85D2E1ULL, 0x44AC9ED9AA3600DCULL, 0x8A88879EE430B5F9ULL, 0x7F5930AC4F7CB9A6ULL, 
            0x7D94DAFF370BE355ULL, 0x4F9BC3180B66433DULL, 0x09E3C2142D1D7648ULL, 0x9C8CBAB7F5B668B8ULL, 
            0xD1C62B499F693575ULL, 0xC1148434278A3149ULL, 0xE4FA99A3055D07A4ULL, 0x148E3F73551ECD5AULL, 
            0x725414983DFB8AF5ULL, 0x2434BF6DA15CD502ULL, 0x9E5CA767095AC167ULL, 0xC2EFE49358EAB01FULL, 
            0x9C4B0C563EB0EFD7ULL, 0xF404E94330FEE386ULL, 0xC5DA4E57DE49A7C7ULL, 0xB71E36CDB60D23E0ULL, 
            0x2243156C6AC101D9ULL, 0x7596E47958EC0500ULL, 0x54438D8C435FAEE7ULL, 0xA227C70FECBFB6B5ULL, 
            0x6F0FB27C425760C0ULL, 0x65FB446044F1473FULL, 0x899B2C1770F1F65EULL, 0x5FDCA501E7EC1D89ULL, 
            0x005FEF20F4259478ULL, 0xB4449C7213DDCF0CULL, 0x1927EDF229E0C6ECULL, 0x741FE45057FD4418ULL
        },
        {
            0x05470915E751B151ULL, 0x3C20A59A7B0219B5ULL, 0x492B6009BDC1DB24ULL, 0xFB20ECBD7A5206E1ULL, 
            0xB49FA9B848A9FFFAULL, 0x29D1DCAD9686F5A4ULL, 0xC307F69D1BF7C745ULL, 0xFA42C71B51D5AA19ULL, 
            0xE8C94E85EC5B2CC1ULL, 0xA30059B4FCC9AF14ULL, 0x48A42A395AC5D9F6ULL, 0x39E6ECD811A4AEE3ULL, 
            0x192A13D70548249FULL, 0x05D9E8506661B7DBULL, 0xC22C8BB087E6BB1EULL, 0x88535C3402F38A07ULL, 
            0x8B76EB2862B3DE7EULL, 0x3E819F834D242F13ULL, 0xC60358CB010BCDF3ULL, 0x2577B2B51765D988ULL, 
            0x999CC2B6AFD10115ULL, 0xA2A1C420DAC54AA2ULL, 0xF594F338E09D511DULL, 0x1C10AA62C68EE129ULL, 
            0x40548C712CD0A00DULL, 0x0D2E8B29B89704D6ULL, 0xB1F4FE7191FD4A88ULL, 0xF8783821FBD97AA4ULL, 
            0x5C023172E12FC601ULL, 0x5B8FDB5A171F12CDULL, 0x6081E01E83E1BF6CULL, 0xEF8D3ACAA1DDF650ULL
        },
        {
            0x7280243B2DAA3D69ULL, 0x5142F2DB30EB2691ULL, 0x1E07A715C6DDCAB5ULL, 0x03AD9215B222607AULL, 
            0x743C18EDD1A78100ULL, 0xA467658B34DE9897ULL, 0x799F0E6B7526F181ULL, 0xCE49A1CB60610EBDULL, 
            0xF840323B4A73B648ULL, 0xB2C072CC4F8CF196ULL, 0x7339F599CB3E7A8DULL, 0x0618153E927E79C6ULL, 
            0x11A18614112A2B7BULL, 0x4245D54E3C31C4E5ULL, 0x4CA4DFDCAA7A428BULL, 0x7919F8782193B3DFULL, 
            0xEB260AFEBF5D72EDULL, 0xA8D16E2CE7E214F6ULL, 0xE4AC5B56E38AE0F3ULL, 0x21E99FD04385E33BULL, 
            0x05E081AB141F082EULL, 0x6497796EEC44C0D3ULL, 0xCDB15648CDDB495AULL, 0xCA23D6462A6FD29FULL, 
            0xAF7EA1F9FC4772E7ULL, 0x93F49EC0112A7D12ULL, 0x29EA04F65D39E633ULL, 0x3CFB369E20B3401EULL, 
            0x1FE11D7BB430068EULL, 0xF7585DCE027677FEULL, 0xE699A937BEE6747EULL, 0xEA5003F70B749398ULL
        },
        {
            0x469B8A82E3A09C1DULL, 0x2AE7BCFA13BD6C28ULL, 0xD6C3F9341B84419DULL, 0xFE5EF876F080E386ULL, 
            0x5EC9364FE8F958C7ULL, 0xCDEE0CE3240E39BDULL, 0xEEA058A67E33786CULL, 0x479B26A17CF2DED4ULL, 
            0x9AE732C073936D32ULL, 0x997C3F326300546AULL, 0x555A0B7DE154F83BULL, 0x4C65D5044D8D91F2ULL, 
            0x520B7D2AA723B48FULL, 0x06A61C33E20C283BULL, 0xB78BDF69C3FBBD89ULL, 0xD1A3E6A79277D65FULL, 
            0x49191F0696BA5506ULL, 0xD68538FA5CAEEB65ULL, 0x93C66FC5F1753AFEULL, 0xD2793A8643540CCCULL, 
            0x7DC2624D35299A3DULL, 0xA17E50BDB00A3076ULL, 0x7F8B39CDB16B1C59ULL, 0xA9303D064FB1EBCAULL, 
            0x142474256606D07FULL, 0xAE7C41D4EEBE908CULL, 0x6757CE32BDD66B2CULL, 0x435303A612E9273CULL, 
            0x733476833C943212ULL, 0x578AC420677338BDULL, 0x47E46063311793E8ULL, 0x29262E99D4833CF9ULL
        },
        {
            0x07A64D5DB502D912ULL, 0x14ACBCC0BF5E08A1ULL, 0x95C462A8539BFF45ULL, 0x57442D1C794AFFC6ULL, 
            0xDF945B104D922EBDULL, 0xE168FC63FAA343D5ULL, 0x9B883A130713138AULL, 0x6ED2457BA3B33BC8ULL, 
            0x3A2D17DD6723CF63ULL, 0x24F1BEF414BFD87EULL, 0x25286FA4641F1819ULL, 0x9FBD5A3E9C75BE5DULL, 
            0x8DE4CA8CE96724BAULL, 0x36176E3F482428A1ULL, 0xF9A2320276663F23ULL, 0xA99B75C203F21401ULL, 
            0x4EA4A5629C841E58ULL, 0xC08AA1DD1F66712DULL, 0x034986F641934529ULL, 0x7B79CCED0C38D714ULL, 
            0x727C8EECBF02E240ULL, 0x72C1301126AAE859ULL, 0xB1858495BC3CEFD3ULL, 0x6CF6726CDDE5D2A9ULL, 
            0xDBEF1B62647AD24EULL, 0x59C680CEEB06282CULL, 0xACC26E40F77FB738ULL, 0xACAEC059FBCE68E4ULL, 
            0x4347D6597BB186F9ULL, 0xB0C2C996D7EAC32CULL, 0x88F8719C4C9B1F5DULL, 0x1ECE67E192AB7503ULL
        }
    },
    {
        {
            0x6D7B181AA6A21CFEULL, 0xF01D7BEA9427978DULL, 0xEE2594EBB1CE8663ULL, 0x107F5B61143E351BULL, 
            0x7D306486A2454EB5ULL, 0x7A08F6D63053D82DULL, 0x57161A5AFD3BE870ULL, 0x94D3BFCD2474A0EEULL, 
            0x2DE9CFD7B06E9E0AULL, 0xF2D8C3491893AAE6ULL, 0x19B06B2716E81AB4ULL, 0x510FE9093C385043ULL, 
            0xF705CCE7677C5C19ULL, 0x99AAC6C4426515FEULL, 0x270728939E07674FULL, 0x66B002712E0BADC0ULL, 
            0x9C6D85086434AD0EULL, 0x40862D1C38167C76ULL, 0xB7662A26EB5D583CULL, 0xAF9D77E330AEEA77ULL, 
            0x071AE8DA748B9D01ULL, 0xAC70A78CC7BDF634ULL, 0x287409DB951DED05ULL, 0x318546806892B602ULL, 
            0x6B5D089A34675BABULL, 0x082513507296F6EBULL, 0x491F23D387521BEDULL, 0xE67EADDF6E2A4335ULL, 
            0x0E3720405AC10577ULL, 0x7A8001555B4DAEE6ULL, 0xC1F91D1980E6637EULL, 0x66A79CC0AFBAB881ULL
        },
        {
            0xAE7C86CD07943ACCULL, 0x57486CC1584502CFULL, 0x96C5867C32451181ULL, 0x04FD10AB69B05761ULL, 
            0x309CEFF694BCEC5FULL, 0xC5376ECAC7A352ADULL, 0x3A9839FB457156A1ULL, 0x406A6BCB04E65A80ULL, 
            0x58D1821AF2E77047ULL, 0x4D4BDCB4E977A93DULL, 0x25754BFB1EA3A317ULL, 0xA600A94AAEA9E1EBULL, 
            0xD034551AB82AF34AULL, 0x69A02D6C69926558ULL, 0xB5583D1FBCAC8C00ULL, 0xD71374A0C9A0452CULL, 
            0xD1F2E7EC2BB0C695ULL, 0xFC41FC1BE9103058ULL, 0x56D0DC0F2E2B3C97ULL, 0x20ACE7CE2A311702ULL, 
            0x046ABB6D70C71E45ULL, 0x32137D1A6BCCDC31ULL, 0x50B9AE4C90E556E5ULL, 0x89F240F30EFD2BE2ULL, 
            0xB73929355B9F42BBULL, 0xD5146455E0BA9B3DULL, 0x93822705150A12E8ULL, 0x9E2DE5C0C2E20D1EULL, 
            0xD6DFC815A6A3AC90ULL, 0x8E63CBCB3B4049EDULL, 0x080270A742CDF246ULL, 0x89CED5381B44C923ULL
        },
        {
            0x9C40FD060DD8E547ULL, 0xB3E1A12D86D8352DULL, 0x995833B63E33EA07ULL, 0xCD5F7BF9474ABEE9ULL, 
            0x207FAF0A0F17EA4AULL, 0xDC29B1F37AE05620ULL, 0xF22C3508416E8E4DULL, 0xE3B22945E4AC2D36ULL, 
            0x96391B96E77BE3DDULL, 0x935A4E0C65911FE4ULL, 0xE5A52C0BB2454681ULL, 0xD99F5EC9B2F2D4FAULL, 
            0x0871E61997F320E7ULL, 0x8BA6F66FCBE82B4FULL, 0x0405599A142FA4C7ULL, 0xFB122B2623CFF4FCULL, 
            0xA0313E31BA2FA564ULL, 0xD3007555253A8FA4ULL, 0x379D397619F77BF7ULL, 0xEC145DD056E184B8ULL, 
            0x6CD7EA75CB229B85ULL, 0x7DB62EA5501F0ED4ULL, 0x0447C8A8BFA29C4EULL, 0xFF4106F83B316B66ULL, 
            0x19AC13DD57B8926BULL, 0x491001DFF42887D8ULL, 0x7801D108D7B48CD6ULL, 0x8DE75DD352EEBE5FULL, 
            0x3799FBB8626A17A8ULL, 0xACFA1D1074D879D2ULL, 0x4E99BC205C49C746ULL, 0xECF6DEE11822F4A3ULL
        },
        {
            0x9E61319956FBC6B6ULL, 0xBEB275B089977EA5ULL, 0xBC94E338090E2B98ULL, 0xB71A11561D256E6CULL, 
            0xA746CF3769C73E9EULL, 0x32E5F0D0F5191BFFULL, 0xA7698A8097F31026ULL, 0x6242457F5443D9DCULL, 
            0x318C7F80B7354BBBULL, 0x96E5BA9F8CEA1E16ULL, 0x19405E47122E324DULL, 0xE9702FE314154632ULL, 
            0x13E36C2EA35808A3ULL, 0xEC6B4D167D654BD9ULL, 0x1397CE363B51F64FULL, 0x5E74851650633CDFULL, 
            0x1C31643BDA2A74ADULL, 0x5176EC99FAA39A88ULL, 0x06102C734AF90D47ULL, 0xC7B91CE9584E7F1BULL, 
            0x133C00A2F37982A7ULL, 0x65FDBDFFDE139E7AULL, 0xF8EA366D48F4492BULL, 0x045E268775E870FBULL, 
            0xAF4A67E86C868EC2ULL, 0x60D35F601D4C716CULL, 0xC996DBF34CB9CDEBULL, 0x82EABB3ADFDDA527ULL, 
            0x19EBCEB64743FCD7ULL, 0xE1F7119550479F73ULL, 0x1F1AA5F8B497A4E4ULL, 0x08A007167B98A533ULL
        },
        {
            0xA063728EF356232FULL, 0x7483BED9AD8E48BCULL, 0x5BF5F7441D8A7BC5ULL, 0x731ADBAF30347AA5ULL, 
            0x9D9027701B0D6F2EULL, 0xA08566ED30FD4960ULL, 0xC963CCB7222EEFEFULL, 0x571B430F776EA719ULL, 
            0x094230CFC41723C0ULL, 0x240C8A2EB59277DEULL, 0xA25D2383CE9B3744ULL, 0x6F6FED48661EF35FULL, 
            0x16A17F6DFA96E690ULL, 0xD01C8CE03AF44E1CULL, 0xDAEF1A553B6923CCULL, 0x1AFADA809860EB69ULL, 
            0xED04B68559468A09ULL, 0xAE13827EF276A137ULL, 0xE2BF7A3E93EC0279ULL, 0x152C4A5AE71432D3ULL, 
            0x468DD88DC53C9F29ULL, 0x8F6D474C9A921D7BULL, 0x8A282D18376860EAULL, 0xFF3A89A002EC2E45ULL, 
            0x5F268900C176353DULL, 0x8893935B2C15C4D9ULL, 0x9BB390FD35B82A6DULL, 0x0501DE0B8650D0E9ULL, 
            0x900616A8D5EDBD87ULL, 0x0AD1317BBF8BA521ULL, 0xC5074E523877632FULL, 0x4BC80828EE14B209ULL
        },
        {
            0xE33AF24A30EF75C1ULL, 0xBFC8251A4857210FULL, 0x48784037C4009AB0ULL, 0xF20EB3050E0329D2ULL, 
            0x5759D925EBF6335AULL, 0x4FEE7FB749C3432BULL, 0x54415093565F89F7ULL, 0x90F782CB4A778CC7ULL, 
            0xCB9F1E56C632B5D6ULL, 0xBC458E95CCEA85B6ULL, 0xEC4858503846C52DULL, 0x6CD1AA359D4A0DCFULL, 
            0x2189F68E3A133E6AULL, 0x7659A2546DFA682AULL, 0xEE3A364EFB459F12ULL, 0x886C487E68BFCC97ULL, 
            0xB1D60CCEA2DD2F8BULL, 0x68BC35D5D8C836ADULL, 0x3C793CB66514D705ULL, 0xA0332576664A9D17ULL, 
            0xB34960C9878FEC0AULL, 0xFCA0A8CCC108801DULL, 0xE4B821B9B77C0113ULL, 0xD97DCC0941F734BCULL, 
            0x1CF677D0DE11E908ULL, 0x079D1637BAEDDD61ULL, 0xC55E6EBCC7FFF57FULL, 0xFD7C3E6657BABA09ULL, 
            0x7876CA6BBB9229A5ULL, 0xA40FD65C0505ABD5ULL, 0x2719D71969F9B207ULL, 0xA357E08757E8F116ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseEConstants = {
    0x714033B43685D301ULL,
    0x742A0CCACAA052ECULL,
    0x2D1D7150A9FC3263ULL,
    0x714033B43685D301ULL,
    0x742A0CCACAA052ECULL,
    0x2D1D7150A9FC3263ULL,
    0x11FA7C2FA3079F20ULL,
    0xE70B8CB0B6235517ULL,
    0x57,
    0xC4,
    0x6D,
    0x01,
    0x3A,
    0xBD,
    0x43,
    0x09
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseFSalts = {
    {
        {
            0x109BCE64C117903BULL, 0x153D0F568E6A4F64ULL, 0xC55495E26AB0E7DBULL, 0x378B0E3589B6E011ULL, 
            0x34648B05B4FF2EB7ULL, 0x24AE089243DD0CCDULL, 0x8D0C5D4ADAC810ACULL, 0xB32EBE6F8C531A29ULL, 
            0xAA3BA613DE7E5992ULL, 0x1A10B51BA4EFF298ULL, 0x914E66F04262C070ULL, 0xDF776A51B878A8D1ULL, 
            0x7CE9F24085B6C2CBULL, 0x51588D56B54374BCULL, 0x24694BF303AF9C66ULL, 0x520DCF866FF39E72ULL, 
            0x270DD25710FC4CD1ULL, 0xA612605F77301B29ULL, 0x2399C66A0B62A8C4ULL, 0x3B64E6D93CC34764ULL, 
            0xC22F7417E996B80EULL, 0x797E86C1D8B95E0AULL, 0x110630D372FE1BCCULL, 0xAD078D29BD60695FULL, 
            0x9B7D610D68F233E4ULL, 0x256E65CA70BC2C00ULL, 0xDF70159C2E76E485ULL, 0x04A8189EA9FD790BULL, 
            0xD12FAAF0F05908EDULL, 0xEED4583F416740F1ULL, 0xACB3233796850463ULL, 0x339B8A1E8BBACA1CULL
        },
        {
            0x0557B929D6ABE76EULL, 0xF04B2D5D169B58DFULL, 0x26E4834EED499963ULL, 0xB2668395CB441D23ULL, 
            0x692BC7A0C28F61CDULL, 0xE5A1EF3FF190EDE1ULL, 0xDCC241DF1FB69C62ULL, 0xAE52F86B1A6E3368ULL, 
            0x1B741D50C42E8D35ULL, 0xB93FAEE44C058E9CULL, 0x160336E37CC5C844ULL, 0x4B230ABBBEE32867ULL, 
            0x1D7C02482DAAB179ULL, 0x6E535AA585721B3DULL, 0x69A0596B580F1EF0ULL, 0x324A8DCD4DFB684DULL, 
            0x4A35FC795C8123D5ULL, 0x07528373DAB498C1ULL, 0x7E96858B8C2E9DFCULL, 0xD2BFDAE265C553C5ULL, 
            0x434780247EF7F8DDULL, 0xA93B935338C365ECULL, 0x8CC935BBCCF723D3ULL, 0x140B3E2986A45A7EULL, 
            0x89D0CFF8EC27F452ULL, 0x73442469C40BBEDAULL, 0x76EBC2B92F2CC040ULL, 0x321A5F2BD77E2EB9ULL, 
            0x3D845E055328D378ULL, 0xB57AE57995F2D10CULL, 0x055B288F5195F00DULL, 0x4440D86506F543FFULL
        },
        {
            0xF18B5EB8F64052EEULL, 0xA11BDCB24670A95CULL, 0x66F3414B568EDB79ULL, 0x11BB057215905110ULL, 
            0x12A1BC4E0C4C1C7DULL, 0x2D0916D62696377CULL, 0x5A9051D671A3EFB6ULL, 0xEF0D41B00847906BULL, 
            0xC802457C191F5E68ULL, 0x8AC4D4E20E25880AULL, 0x28BF8BEA209B1A60ULL, 0x1CADD90779FB9250ULL, 
            0x96D8B62EABE0BAA6ULL, 0xB979E73626C831EDULL, 0x32ECEF6B9467E962ULL, 0x6BE250850CBFB46DULL, 
            0xF03AF1F1CE570781ULL, 0x6E5903C0E5041C8DULL, 0x4FADFF7F256433D3ULL, 0x12E92DACCCE428F2ULL, 
            0x6B19156BCAC17D42ULL, 0xFA8E257A85280891ULL, 0x071672A6CB1BB77BULL, 0x611836CB03EC3AB5ULL, 
            0xA972724C586225BBULL, 0x263C934347704B6BULL, 0x06CFB1B87431B0C9ULL, 0x73701734325F5558ULL, 
            0x0380185CE30C05FFULL, 0x0BC3CBFD2C37758FULL, 0x5C5AA70E24A60D94ULL, 0x29D8DF8DEAECB7DFULL
        },
        {
            0xAD327B3BD3D352A7ULL, 0xC0B942CE56003194ULL, 0x6D55C85955218D59ULL, 0x80E4B3ACD29834B5ULL, 
            0xA9C3CBCBB515FEAAULL, 0x482E69B8D6619158ULL, 0x890B92073EBD15E3ULL, 0xB807B8BD4F5EF680ULL, 
            0x9355493A8BA6FD92ULL, 0x39DACF9A5E63D0A0ULL, 0x34FFB769721B39A6ULL, 0xF166ABC48C0FD52EULL, 
            0xE223F4194B936FE7ULL, 0xF03D0083232A420FULL, 0x5ED58C14E25FC7A1ULL, 0x11F54A75229C8AEFULL, 
            0xABA031451094DEEFULL, 0x5240F04131559649ULL, 0x7D4782EE98B23CA7ULL, 0x5FE1BB4DA9479DB6ULL, 
            0x93F4C08B5E94E180ULL, 0x7FFA47AD3D44866BULL, 0x51091CB0ABDFF00AULL, 0xB1E6C481462C6E91ULL, 
            0xFCC76D9822A195A6ULL, 0x39F4C1A4126BF4A5ULL, 0xC32A6AE349179E20ULL, 0x128A41EEA4E83096ULL, 
            0xB3280F240815D908ULL, 0x60A3C470F4032238ULL, 0x53920B6CEA0FBD96ULL, 0x3DE4D4C2BFDDC298ULL
        },
        {
            0xCC57598FED1E031EULL, 0xDBCB80895BD05877ULL, 0xD21E5849986DFAB9ULL, 0xD594B3DD65EAA21CULL, 
            0xD53E6E368F06CE15ULL, 0xCE526F8640A587D0ULL, 0xC8DBA97AF328D7D2ULL, 0x56A2E2304F910536ULL, 
            0xC369635C013E5643ULL, 0xD352DB87E9A2BC1CULL, 0x7783EBF37C67C902ULL, 0xE946E563F6744164ULL, 
            0x24204B4578A73FA8ULL, 0xA4F408B797EFF466ULL, 0x5D39A7D403EB3E2DULL, 0x59C537CC10359D36ULL, 
            0xF4D6BD7B80B391C9ULL, 0x27DFE7DF559BEFACULL, 0x872A88A48E8BE1F8ULL, 0x2E2D7FB126F57352ULL, 
            0xF325F2EB0F671FBBULL, 0xF3E6B440179A242EULL, 0xC745CD6DBCF39A12ULL, 0x9EFC4F55F3FA80DFULL, 
            0xAB2D142DB25DE4ABULL, 0xAFB96038787FD2ECULL, 0x1739A01E56BAA6CAULL, 0x5997FA58517B92C0ULL, 
            0x5489CAD36E7AB8B6ULL, 0xE281C2AD86B05319ULL, 0x976B62AA3FC45CA5ULL, 0x56758BAB03AFE421ULL
        },
        {
            0xB4D367D957D7B0BEULL, 0xCF31A9779F2E22B4ULL, 0x22F5367A5027B1B8ULL, 0xD1108108189A4E85ULL, 
            0x8BA624C5403E2A6EULL, 0x4251E4062082919EULL, 0xE19DD05A2F0D7E11ULL, 0x86EA8F998A097643ULL, 
            0xE890E67235186360ULL, 0xC7CACEF2F76686C4ULL, 0x983001587AB4FDE9ULL, 0x3C8A04CA45757F2BULL, 
            0xE6B64F3149257AE7ULL, 0xA1E7C54AFBF13B38ULL, 0x422C5E4A92AC02F7ULL, 0x3A0A3B824AB5434BULL, 
            0xC8D17C8213579A55ULL, 0x903CEA9D74F9C252ULL, 0x1980411DE9DFC07DULL, 0xCEA7514AAB59901FULL, 
            0x2E34CC4ED869D94BULL, 0x8912D7A26331402EULL, 0x8DC0AD1B6CD93980ULL, 0xACC7A4F7ACA79DB7ULL, 
            0xFDD5C433167535F4ULL, 0x191E5D58635B958AULL, 0x1C70915B18879E17ULL, 0x545FBEE549F8722FULL, 
            0x6207D8DE63D13A8AULL, 0x9AC98257CDCBB7A8ULL, 0xAAAA485FF20FBA48ULL, 0xA25F7C919307AD07ULL
        }
    },
    {
        {
            0x399BC62A71AA62A8ULL, 0x77B71271012F3B48ULL, 0x1FC3F564F4E078E3ULL, 0x8D40633D1DDC26CAULL, 
            0x01496022EB2B5BB2ULL, 0xF8AEAB4DDD6A3314ULL, 0xBB652851CF9720F8ULL, 0xB2FB9ECD90C72232ULL, 
            0x93205B25B2486B7CULL, 0x633B446959C7B139ULL, 0x532113C14D1C4527ULL, 0x4331872921640AC4ULL, 
            0x44FD29A35C4E8FB2ULL, 0x2E5C33154355CDD7ULL, 0x062679BEE9ED7080ULL, 0xC98AE9423637C8EFULL, 
            0x4F2C4C6AAD565B7BULL, 0xC9D643BF14E7ED7CULL, 0x09E8E4C591C31602ULL, 0xE0F73B7FE59F1434ULL, 
            0xB1D9BC993A37E0A9ULL, 0x08C9939E5EFABA4EULL, 0xB581F404B58565E6ULL, 0x2347865B74AE4F52ULL, 
            0x381C377BBB0D4D91ULL, 0x6E8EADECA16030DFULL, 0x325BF8F13888B522ULL, 0xE6772794944D45AAULL, 
            0xFAA1B95E474AC3F4ULL, 0x0F1CC809BE26B8D9ULL, 0x9EC518F684796F86ULL, 0x0E6A65141D9A47F1ULL
        },
        {
            0xCBD40AA3AE01CF65ULL, 0x7CA9BE8D0119D8DCULL, 0x494B98E5645F8E5BULL, 0xFAD3700396DE44C3ULL, 
            0x0642CC2D28C112E3ULL, 0x99FB428A1B8213FDULL, 0x7F9B29D8255288C6ULL, 0x086C32FF36C300ACULL, 
            0x10F64A71D08BD338ULL, 0xD1AC2C895941C70CULL, 0x24CAF0AA21FB6828ULL, 0x3D59939B00F7E115ULL, 
            0xD8F07D815C136E4CULL, 0xF3A011041289EF54ULL, 0xD1FA0BDDD9630046ULL, 0xD9AA8CFB332D0324ULL, 
            0x9F5858E4C1BA5E1FULL, 0x81DBD446BF9518CBULL, 0x0C555BE4A2962657ULL, 0x2254D2329F00AC1FULL, 
            0x477A63188BBCA242ULL, 0x3BA19A5B0FF3E393ULL, 0x810F759E43E9ED05ULL, 0x8E307A20538A40F4ULL, 
            0x44E732AF6A4CF07CULL, 0x9A1F4860CD3ECD2CULL, 0xC8B7FF45FC60E050ULL, 0xF6FA18BF8D4E5E62ULL, 
            0xA52715E139AA27BBULL, 0x52E0D2F8AA7C5CFEULL, 0x1AC9FBDFE564A9BBULL, 0x5F95B08D0C006D9EULL
        },
        {
            0x7ADF6C782B2EECE6ULL, 0x2E4E4E6DF5E15C6CULL, 0xE6ECDC62DB020DABULL, 0xE0D2F55955700022ULL, 
            0xBEA7043500BF8D42ULL, 0x7CBB4C19218304ACULL, 0xDA9D5C28437EFD49ULL, 0x09D3EF3F82323DCBULL, 
            0xE7AF375DE85CC6E3ULL, 0x1C9A5F26DD8EDCEDULL, 0xD73FB8B72399ED34ULL, 0xE5E92755BF850543ULL, 
            0x3AF79D25B9105A3BULL, 0x2C80F5E77AC88F9FULL, 0xF6A5DC73C65E8EBCULL, 0xDDC9A18D3B61FAC5ULL, 
            0x4EA6FDA43479550BULL, 0xCBD302129E0FFF7BULL, 0xCC6AAEFD30EEAE98ULL, 0xAECFCE40F9288BB6ULL, 
            0x56ACEE6CAD951730ULL, 0x9C3029A3EF8D3A14ULL, 0xA6DDE49EA494A46CULL, 0xE6C79855D24FD1C7ULL, 
            0x9C86A32990E7D726ULL, 0x2E54C60447A6673DULL, 0xFB8B05181A9A0868ULL, 0x6985FB05AEF533E7ULL, 
            0xB8A3C0344B0721BAULL, 0xA707A5646302675CULL, 0x0344669D32834BF4ULL, 0x0203D3B1C657EDE1ULL
        },
        {
            0x8D8336D13B8220DFULL, 0x9F391A47321853BFULL, 0x4F510F6895889619ULL, 0x86D5D1E8C5692CDDULL, 
            0x7FDECB4941D702FBULL, 0x12E63E1CDBC827E1ULL, 0x1AC45BF43CF28E65ULL, 0x3BF3FEE454DC2FAFULL, 
            0x11FC62B689DF37ADULL, 0x3C3EE353482A29AAULL, 0xD83C45979644DB65ULL, 0x14F3AD5D090E398AULL, 
            0x805DB06E637CAC79ULL, 0x4D3FF843FC6B2A2FULL, 0x9AD1A368A9B1EF20ULL, 0xF687E05C64CB07BDULL, 
            0x70BB0195B8DBB621ULL, 0xD6EB8075B6E5E00FULL, 0x5157E939A679EF6BULL, 0xA091996915684741ULL, 
            0x48BA9AFFEDF1B01FULL, 0xAB1C34BBF7C3B8F9ULL, 0x6E5DD7B66D708AB9ULL, 0x95A7E56D909FDD12ULL, 
            0x25352B85E523AC84ULL, 0xF3CA5532A338F356ULL, 0x50E735EF5C6936BAULL, 0xED53EC3A8BEEFE9FULL, 
            0xCE4ECDBDF91B9680ULL, 0x2DB49B6560994C7FULL, 0xFCDC038356303901ULL, 0x553CD292EAB6859CULL
        },
        {
            0x06B75886469437E0ULL, 0x7D0C6DF80B5618AAULL, 0x684D146376297036ULL, 0x65915E7DC0C51CC4ULL, 
            0xB27AFA9F0046717DULL, 0xE51CE2DD37551E5BULL, 0xF81101CBF96F31F6ULL, 0x7637B65A6DEFB1F7ULL, 
            0x02ADBA5EF618057EULL, 0x0C4286E01A86A01BULL, 0x8B9919D0B406A272ULL, 0xE22C19DCC9477423ULL, 
            0x641E513113223395ULL, 0xB75DF2696A3050DCULL, 0xAF3C7A9C0581724FULL, 0xCAB5803801EB427CULL, 
            0xD032292C0A876732ULL, 0xD15C279B0B3303E5ULL, 0xCA09FAB09FC0F4AFULL, 0xE456291486A84736ULL, 
            0x23F1FACF31417679ULL, 0x6FF93C9EB257F482ULL, 0x701059C02595DC42ULL, 0xCABFA2FE98834B03ULL, 
            0xD31C32C572B03238ULL, 0xAC6A0F2FDD30F37DULL, 0x0680B8943BF4620AULL, 0xF789744FA31FCCF8ULL, 
            0xB73E40AB5F775ECAULL, 0x662035DFFD810B8DULL, 0x12DC8C8F5712D2D1ULL, 0xCFCA2A33161D333CULL
        },
        {
            0xF4897520C663F662ULL, 0xE4676C7213D3F026ULL, 0x8DCD0DBF901505FEULL, 0x739577DF11382150ULL, 
            0x83CCF17CE6F5C671ULL, 0xA76F739945401019ULL, 0xA0AA823CAF9A3E3EULL, 0xF63D486AB4576C98ULL, 
            0x57BB22931E12A94CULL, 0xEF8E4CE13A4E7062ULL, 0x50C3AE3AF3B93754ULL, 0x61064752717ECFADULL, 
            0xCA0D5F9F8AA318D2ULL, 0x533579898D589FE9ULL, 0x417D2ADE40BB6BD4ULL, 0x1EA6243C480FC096ULL, 
            0xE5668E5CE080697AULL, 0x4F368E8C658FBCAEULL, 0xD10E9C1AF1ACC72DULL, 0xA26705C8CAA4632BULL, 
            0x42FB1DC21B6B5534ULL, 0x08E4F32614BE50F2ULL, 0xDFE720E8B872D541ULL, 0x678EF30F91A04918ULL, 
            0xD4E558B97DB5DBFEULL, 0xC3D4698438FA4D36ULL, 0x9A88E5D14DB9ACEAULL, 0x0873CCF7230CA723ULL, 
            0x3EC19DAE7D49BD54ULL, 0xFEBFCD4141E650E5ULL, 0x27F70A930B2D16BCULL, 0xAE1749B72E518573ULL
        }
    },
    {
        {
            0x8CBD70BB97D2386DULL, 0x555C228464763861ULL, 0x227829512FFC6362ULL, 0xBD3A94EBE1809C2BULL, 
            0x8EF75E6061155BD4ULL, 0x8111D38A28F01E90ULL, 0x4B5F1F2999FB03C1ULL, 0xFD524FDB47AACFEAULL, 
            0xE13F8C96D728C62BULL, 0x093F066631553461ULL, 0x1F3CCC0D46A5FB42ULL, 0xA1E4650677F212CAULL, 
            0xDC71010D812B46A2ULL, 0x7FB0227365325602ULL, 0xDD020D3F85D9607FULL, 0xF062D8E6713E3F0AULL, 
            0x6EAE60DB80221C4AULL, 0xF6DC7FB642374B4EULL, 0xCA48B5A244714F78ULL, 0x3FC3D371CC42E09FULL, 
            0x95162A6843C225BCULL, 0x0F663F30663F25A6ULL, 0xABF9A0E9D335AD24ULL, 0x4EC32F0E272E4B9BULL, 
            0xBF8122561BC7B783ULL, 0xF20F764EFA231C56ULL, 0xCE6CC92F90E18F18ULL, 0xC56AEAA7253BA1E8ULL, 
            0x746A6F4C3090B6BAULL, 0x56656B7D638B3AACULL, 0x82BFF35CAAF6D2A7ULL, 0x5B7E437FEF1F40B2ULL
        },
        {
            0x3E188A1AF91C9A2DULL, 0x4CD65C58B9DA1CD7ULL, 0x6ABC4C5E509FAF70ULL, 0x2653689CA0FBBD8EULL, 
            0x02E9FEF80B993A47ULL, 0x75E3DA63B3D74A3DULL, 0xCA0F39A35DAD46D5ULL, 0x3F6800B97D48DD9FULL, 
            0x1D5B83393974CB70ULL, 0x9334FEEC43E9B53AULL, 0xFEFD6879FB2E714FULL, 0x9289845BB1A05A9BULL, 
            0xA7B7CDA584B00E2FULL, 0xA3099CC698951632ULL, 0x696772C1633FFE45ULL, 0x4B64863A5796AB90ULL, 
            0xD1393555BC1010B7ULL, 0x1BD6E1F23C1F7743ULL, 0xE77F8A23B8936FF8ULL, 0x5EA7B28B5916B9ADULL, 
            0x27651E0FA8ADA9BEULL, 0x0C984296C75D5FF6ULL, 0x4779A38317B37724ULL, 0xCAC65275CC9D28D6ULL, 
            0x2EA725F0CCFBA3D7ULL, 0x47B154F05223ADF9ULL, 0x32DA3697CD433823ULL, 0xE03EE67E569A2DF0ULL, 
            0xF2C9DC3B99D948A6ULL, 0x195FD33358BABF0AULL, 0x405285298F814271ULL, 0x4147074070A64354ULL
        },
        {
            0xCED229D1CD0DA6B3ULL, 0x2C265C4DD314BA7FULL, 0x0165DE0EB0F9CDB7ULL, 0xF83ECAF27E1493F7ULL, 
            0xFD3C9A0646C5EF3DULL, 0xE2C7A14392FCB6A2ULL, 0x97613BA0C3B3D3B3ULL, 0xB12DC69777DDDA98ULL, 
            0xC23E2E41AED4AD8FULL, 0xDC9FBE3B806943C6ULL, 0xAC52FEC829FDE01DULL, 0x845F0854A0DCD96BULL, 
            0x34A056491EDA1D26ULL, 0x9F48F1FF22A8EB65ULL, 0x033C651AFAE3B251ULL, 0x0C4B145A1EF1E295ULL, 
            0x790ED9769E30F536ULL, 0x95E2E2F95432EDCBULL, 0x0C87B8124F2AB60BULL, 0x2B29E32B2B0E0E4FULL, 
            0xBB805443CC7DE098ULL, 0xB024D4E96F03A26FULL, 0x0B68E7E2503367D8ULL, 0x5CB3DC47217B3A11ULL, 
            0x72828904920FDC8FULL, 0x89FBD755DB902E09ULL, 0xA56B70465CFB631EULL, 0xB01C5F0C78445654ULL, 
            0x86470CAF03DEAB8CULL, 0x4033AEA8E323EFE3ULL, 0xD0348F2D06E3D3BFULL, 0xB62938BE225F695BULL
        },
        {
            0x3FCAD23F116643B2ULL, 0x4D887957A218C580ULL, 0x3A4B263D529BFE0AULL, 0xE708AAAE2F2897C2ULL, 
            0xA9F7C6703FDF6979ULL, 0xE2775C4C811569DFULL, 0xFCFC8F942957C35EULL, 0x6BD4C46CBB2B587AULL, 
            0xE01CA7144F343802ULL, 0xD5C2C0C0B22E2654ULL, 0x68E4664EAC68F5B1ULL, 0x122411D7B3567395ULL, 
            0xB0004E9D65ABE4ECULL, 0x53F4DE95706D1E3EULL, 0x06A64D4F2ED97C5FULL, 0x7C75B380A4199308ULL, 
            0x54F78D8196DCD988ULL, 0x9BF63A8935A0082BULL, 0x86AE0CD1E90483A9ULL, 0xD7EC9A14014F6BE6ULL, 
            0x17EB8A22861A6134ULL, 0x6408E5BCAF010DCEULL, 0x0D2085DB78524B42ULL, 0x6499150FA45D50CCULL, 
            0xA06C8A1635E8F7D3ULL, 0xBA3BF6DD5A0DF0AFULL, 0x66CEB92968554CC3ULL, 0x94A563F3FB81F0B1ULL, 
            0xD5D582D9D583BEDDULL, 0x35684E1D173F3D1AULL, 0x69487E9BA2D33FC9ULL, 0x2757A6109B898281ULL
        },
        {
            0xF54F7746F4EFB08BULL, 0x88FB44FD676AE61FULL, 0x09C2A1993B7ABDF6ULL, 0x5941EEBF905D4465ULL, 
            0x6046E29D9B489A99ULL, 0x5B39B1C59C69A9A7ULL, 0x75616024732FB0F0ULL, 0x5FE99DEE4D75EA78ULL, 
            0x651F573A24C1BB77ULL, 0x836A3B4EE6D98DFAULL, 0x763588423CB0D6C8ULL, 0xEBF32ABDE44EB79AULL, 
            0xE7EEA6AB469030F1ULL, 0x681D765B735D39C0ULL, 0x719B8DB4CDBC0D64ULL, 0x67973679AEFAFDE2ULL, 
            0xE4EA6C4621CF54CBULL, 0x1998CC54DC869650ULL, 0x733597051378BBE6ULL, 0x7EE4DDF675B5D574ULL, 
            0x3D143D663CAEB8D2ULL, 0x27F5B72C4758B17BULL, 0x2009A6A1B4AA0F01ULL, 0xADEF41C6157420D9ULL, 
            0xAD11E78D5A9FD293ULL, 0x169532376F90D349ULL, 0x3EA56650DB305B18ULL, 0xB05D3241502C7B65ULL, 
            0xFF8D081F5EB9D538ULL, 0xF1576A4A0169CDC5ULL, 0x63797785FC02655EULL, 0x75C3C561583F1F15ULL
        },
        {
            0x2D1CA27DFD4C744CULL, 0xA5BBEF632949E5EAULL, 0x971AB8EFC67F0C8BULL, 0xCCB3B1B8BC119B9EULL, 
            0x566828B6A3C9462AULL, 0x3C5B4B2A2EE3FE17ULL, 0x3188654364413E99ULL, 0xC208EE1F0B255D3AULL, 
            0xEE3B1E811503C6BDULL, 0x4B9E55F104D2E173ULL, 0x64EF61E74D96BE0EULL, 0xE25E4C0F30783509ULL, 
            0x0A66E2D4E0A9E02BULL, 0xF8027C5573DF4D95ULL, 0xA43037557BED1AD3ULL, 0xAB6A2E704C290D46ULL, 
            0x7DD5398A38101B24ULL, 0xDC751BB3791A0AD4ULL, 0x902CD6125DFAF968ULL, 0xF8D91070577519C8ULL, 
            0xEF647D28D3EBB518ULL, 0xFF00E4B573596F69ULL, 0x81D66F32E2608FD3ULL, 0xAD159A71BA96BFDAULL, 
            0xB1493EEAE40FB4B2ULL, 0xFE758537FF008993ULL, 0x3949558AD9BF0477ULL, 0x15722273B060CF1FULL, 
            0xA30ABCD78E66CD4CULL, 0x5C47A98953EFB499ULL, 0x1ED2C215AC916A7BULL, 0x5FCE0935D68F6E03ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseFConstants = {
    0x60698B8C10861CA9ULL,
    0x6FCF003B7E91D858ULL,
    0x143B88EC14249106ULL,
    0x60698B8C10861CA9ULL,
    0x6FCF003B7E91D858ULL,
    0x143B88EC14249106ULL,
    0xFFA87A4139CA1931ULL,
    0x8071AA76DC5D36B2ULL,
    0x32,
    0x75,
    0x88,
    0xCA,
    0x6F,
    0x27,
    0x92,
    0x1C
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseGSalts = {
    {
        {
            0xB04C960F5EB15877ULL, 0x544C7B4CF506CE74ULL, 0x1E6BAC16048B1100ULL, 0x848E538FA8C488D2ULL, 
            0xAEA1BD987578A384ULL, 0xF15F6D0AA4726A88ULL, 0xF35CB14204AAB4BEULL, 0x8A082387D47FF085ULL, 
            0x236659F9ED712AA8ULL, 0x78CE18B027F62F1DULL, 0x91EF76AF01A0E37EULL, 0x15F9DC3871EAB28EULL, 
            0x7FBCC78997B3F4C3ULL, 0xA8E368D835E39BF0ULL, 0xB497FDF84B3B2A47ULL, 0x13DD82FC8FB34EF4ULL, 
            0xD9865266375CCAFEULL, 0xA6609BE670336642ULL, 0x5890BC5B10A33269ULL, 0xE2C4A9FFB280160BULL, 
            0x562AB69F6982EA63ULL, 0x0FB24A47F19FF566ULL, 0x147A679F5C08A3AAULL, 0x3DFA90C477C325A9ULL, 
            0x8E50CF06B42DA5A0ULL, 0x9C98B9D030F90637ULL, 0x9905C98EE6059FC9ULL, 0x493A84E3D2482D66ULL, 
            0xA6DBFDC57CB94BC0ULL, 0x4BB73EA05CE1732FULL, 0xFDF1226719B9AFBFULL, 0xBEB4D8E339A30E88ULL
        },
        {
            0xCBD25C81DE59188AULL, 0xDD73B6C506B43D81ULL, 0xBD65481E741A94B9ULL, 0x6C40948FD7BBD82CULL, 
            0x41944F2CA97D5487ULL, 0x503F9BBDBAC670B6ULL, 0xE46992C990D43F26ULL, 0x6EB8A24BF516E5AFULL, 
            0x3F117D36545800B1ULL, 0x9CEB190114C3855DULL, 0x6F7C035F0AC3AC1FULL, 0x226528E74A2387A2ULL, 
            0xE304091FDD35F4D3ULL, 0x6162218ECD01123CULL, 0x967240FF67C8EEC1ULL, 0xCD06012A077A6207ULL, 
            0xFE1A474543D1DA06ULL, 0xF2B23DEDCD7CD761ULL, 0xFC0529B4786D696CULL, 0xC9E7B3FDF7654267ULL, 
            0x5FCD952A49F5CA84ULL, 0x1C8F39ABC8337045ULL, 0x049E9E54DDE5E50BULL, 0x89BE2AF008768AF0ULL, 
            0xE16A6782319130C9ULL, 0x5F86098C5BB901AEULL, 0x80874D0D1F68077EULL, 0x8C2513AB9C293A5FULL, 
            0x8762D8D7ABED27E1ULL, 0x43E4AA49C027220FULL, 0xCA95F541034AE200ULL, 0x936BE8C3C33B8579ULL
        },
        {
            0xE64E1466003A86A9ULL, 0xF1816466B5A30035ULL, 0x28952199D2318D9BULL, 0x7F7C7D4482AC286FULL, 
            0x70378A626C31E420ULL, 0xEF4BF41885CC7634ULL, 0xD285303220BE0858ULL, 0xD28245C7158F1C75ULL, 
            0x472C431494B0492BULL, 0x131B062AD580C4B2ULL, 0xD6F43051474326A0ULL, 0x360A8C206429B9F8ULL, 
            0xE279B6F0635A8EE9ULL, 0xB73D63F839160161ULL, 0xE615C8AC088E060BULL, 0x1306E73063AF5053ULL, 
            0x8A9CDE4D4BA3ECE2ULL, 0xA68AC90DE4638BE4ULL, 0x3A35E3376E4ED8D0ULL, 0xE03F23C6DFE09625ULL, 
            0x715AF8F531A001D0ULL, 0x950559356EF3C102ULL, 0xAC5049E4F1CD312AULL, 0xAAEC7D8465776B31ULL, 
            0x54884BA4D2DBFE17ULL, 0x6BE0CBB8E0F8E516ULL, 0xEA0B6BA73E660517ULL, 0xA790B879924D41C9ULL, 
            0x53034208357A3A16ULL, 0x3B3ED8890A68F8E1ULL, 0x6AE80D8A9E6B1620ULL, 0x082F762B05FE1649ULL
        },
        {
            0x1F093AD3616075A5ULL, 0xC1DDB2F8A54440D3ULL, 0xFE4F04AFEBD84C43ULL, 0xA6006813649D529EULL, 
            0xBD5CD89374A934BAULL, 0xA0F6078C17099815ULL, 0x0B42D5667285862BULL, 0xC14211794BE68F3EULL, 
            0xA32F0CD52BDD7761ULL, 0xFFF916E4D4FF4C7AULL, 0x87489F0BA5084D29ULL, 0x1C95555F9CB193D0ULL, 
            0x0086B0AD68C6319FULL, 0xF96458B2E86DC289ULL, 0x5A688535D00C9A00ULL, 0x564D0DF3C2DA3EF6ULL, 
            0x78A2DC82CC5C1ED2ULL, 0xD2E6C852E57DD022ULL, 0x21ADEC38FEF849C6ULL, 0x663BA12C4038C394ULL, 
            0x968EE3144364CF32ULL, 0x3812CD68F6B7CEEFULL, 0xB3A12E43B1D13085ULL, 0x5C1B796AA43B5320ULL, 
            0x108F968A533A6E62ULL, 0x23B1E4604820CCAFULL, 0x1671AEB47DAF97A1ULL, 0xBDA23505CDB690FCULL, 
            0x24F04CAF91F297A1ULL, 0x243483E6BD97CE47ULL, 0x100161B79C5D2057ULL, 0xDC198F43F27D4439ULL
        },
        {
            0xE633E1E2DA2E5531ULL, 0xD7978E0FCA89E3B9ULL, 0x88904A196C31397AULL, 0xC122C0D0DEFB7BE6ULL, 
            0xF559E46879D6310EULL, 0x03D76F2B55FBD3CBULL, 0xE6EDBAC0920726BDULL, 0xB8BA21399B55DBB9ULL, 
            0x07B3A99DF9A4F515ULL, 0x26BEC71CFF656B9EULL, 0xE9CEBB259C4D9691ULL, 0x62DE57DFA2B5CD9EULL, 
            0x76F321A0705D43D3ULL, 0xC40265DE6D89A035ULL, 0x20D0027028B07D24ULL, 0x1FF3F5A627409AB1ULL, 
            0xABDAA436B1DDFCE0ULL, 0xE0B84476A38AD02CULL, 0xA6DA23D6D0DF9E90ULL, 0x7C38C8D41BF303CEULL, 
            0x7735EA7D3D322361ULL, 0xF647E39A2E7ED849ULL, 0xA3DE2F2514E347E0ULL, 0xD9CD7D36396C34B5ULL, 
            0x94C807851E5AE280ULL, 0x44AE4F72B4A665DEULL, 0x342293BE255E4AD5ULL, 0xAEB3398EECFD7FF3ULL, 
            0x2D53CDF66BAA1167ULL, 0x11929AD6911CFFFFULL, 0x69A427F4DCCFF106ULL, 0xF442A38FA4E2C948ULL
        },
        {
            0xE4ED345EB0D17D10ULL, 0x78B801F0A97E3AC5ULL, 0x6EA6787B0901E3F7ULL, 0x1FE22A618CEFA73BULL, 
            0x51EF093771105119ULL, 0xEB521B4C49DE015FULL, 0xE76E20641339ADFEULL, 0xF8D88EB1D786477AULL, 
            0x8B6E3764CCEEDF20ULL, 0xD640D4988FC5E950ULL, 0x79B94F56D9C01609ULL, 0x5179C0FE313CAE05ULL, 
            0xED11D8DA37612FB0ULL, 0x08153B3622717B3AULL, 0x06559882B6649A10ULL, 0xFA6B907ECF63765CULL, 
            0x653C869F8D057E81ULL, 0xE768FF24AAB69868ULL, 0x6B03FF7BE3D810E0ULL, 0x7B313AF7F4DBE801ULL, 
            0x9875636E9144CAFAULL, 0x5CF6763F7E8B6C9BULL, 0x9AC46237087483E7ULL, 0xA40D9DA7DCAF450CULL, 
            0xD1172847022B4E4AULL, 0xFAF131DCFEA24978ULL, 0x2A9D4C95350DC6C6ULL, 0x320A8649A2302BCCULL, 
            0x37BF9FA49A1D7794ULL, 0x38E6BC0D6CC32164ULL, 0xF2C1A4E9031FB193ULL, 0x84EBF44BE11614F5ULL
        }
    },
    {
        {
            0x2E7743393A4F9123ULL, 0x5FC63648DA57EF11ULL, 0x70C9E275C75E7817ULL, 0x618DDFEC9B6A9F8FULL, 
            0x2F3E0FFBE35CEADFULL, 0x2D35CD3A443E3A61ULL, 0xF6E9B8AB516A89F5ULL, 0x5893EDB40BCE00BDULL, 
            0xE5BF84F51E736908ULL, 0x889D16DEE8E2BB33ULL, 0xAF9965520CB87E4CULL, 0xA92545C231F698E5ULL, 
            0x5782F995AE261C4CULL, 0x101C035D68AE2B77ULL, 0xCF9754F60D1715F2ULL, 0x3EA9D0A329F519F6ULL, 
            0x7F3CDAA32B79A6C0ULL, 0x99E43FFBCF6B9D78ULL, 0x5CBB0D1312940B76ULL, 0x18D465F60D09CBE0ULL, 
            0x95AF072DEB6AEE2BULL, 0x57DDDA4456F69AA6ULL, 0xE07184B2A06CA9D4ULL, 0x3142CF3B4672FCC5ULL, 
            0xD6266C36FFF337FBULL, 0x1E807054975737E5ULL, 0x630BCA0605025D51ULL, 0xC382AB86B5108B8FULL, 
            0xA7BB7BB560C967A4ULL, 0x938B42E23B0EF5B6ULL, 0xF06DF4977696C44EULL, 0x960EC823021C66BBULL
        },
        {
            0xCD767FF7F90F5746ULL, 0xFE8F0C75C20DAF34ULL, 0x802625AE0936F9D8ULL, 0x230F3C9BEED11859ULL, 
            0xFDD0C34A983EDA3DULL, 0x38E9E3C5197C9323ULL, 0x685582FE2BF47442ULL, 0x51C93F2FCD380FC5ULL, 
            0x7C855578973E1111ULL, 0x3FE12CF18BE3116BULL, 0x34C21C07D36EDEBFULL, 0xF0370965FEAE9E26ULL, 
            0xF40CFE51FFF92F0CULL, 0x67BC0C3F370AED8FULL, 0x954E9B1EF58904A1ULL, 0xF41CBD0588256C59ULL, 
            0x5130BE8ED14072EFULL, 0x4C10F017128483E6ULL, 0x8A173B67F1209F90ULL, 0xE48F4826DB8A5718ULL, 
            0xAAE8AE0CBFCF0EA8ULL, 0xF1BAF116B46F8FB0ULL, 0x544EC86A2E24AF23ULL, 0xACE6EFCC9A8728A2ULL, 
            0xA1036A5187AFA92CULL, 0x79CC9EC533A179B1ULL, 0x436296F8D29E94F3ULL, 0x24B4F16E667B82AFULL, 
            0x9CE80A071438A5CDULL, 0x6EC72CDB32ACC65AULL, 0xAD91DF16CFAC00A8ULL, 0x8ECFC662E0957C05ULL
        },
        {
            0x8AB6B9195B60FC86ULL, 0x3B1A379CF3A726E3ULL, 0x4E6A66A5483FA17FULL, 0x34452110F08B689BULL, 
            0xFD4DD3C7B89C8057ULL, 0x802890821B096800ULL, 0x9A33319C3235D226ULL, 0x72A464D6290C0C65ULL, 
            0xB36CE00B91F4E5F5ULL, 0x4637AFD489D9E024ULL, 0x4B1E94E1420B2669ULL, 0x78242410B7A4B64BULL, 
            0x6C9F1773E46A7491ULL, 0xD097170CF7D85BEEULL, 0x108A196F3575212BULL, 0xD67E01301C8CC26BULL, 
            0x1FF8C6B5DBB1A495ULL, 0xF4DA528791BDDF6CULL, 0x816B6175EF1B7212ULL, 0xFC03A91ADB68615FULL, 
            0x1CA9CD3D798989D7ULL, 0xE50A20A58E90E3BCULL, 0xC044E1EC9150E2ADULL, 0xE8C846E6831EE9DBULL, 
            0x922337A68AC8D93DULL, 0x8E68ACF3D1DBFBE4ULL, 0x421CE364EF6A3BBAULL, 0x2A781F990058DBC3ULL, 
            0xDF60F8E1ED39E18CULL, 0x1D4B701087371729ULL, 0x2EBDEE8738EC4FEAULL, 0x7770BBC1E5E8429EULL
        },
        {
            0xEA666C7EC54228E8ULL, 0x14EC3B38A874A61CULL, 0x04016BA9BB5BDA9DULL, 0x165F95F43B7DAE3EULL, 
            0xBC4DE81BD394466CULL, 0x7A0E976DDE90B6E2ULL, 0x42B5232864D399D0ULL, 0x1A38501C6E50B241ULL, 
            0x30980361E7733EACULL, 0xFEEAFE5884DBE117ULL, 0xD545C0FC1E63BDD3ULL, 0x2B611699F087B92CULL, 
            0xCB62090831DCE742ULL, 0x8DB6FD43E39C8E6EULL, 0xF331394AC820DDD7ULL, 0x417B3B89DA182029ULL, 
            0x46734472D0B8E66AULL, 0x878DD8543034CF86ULL, 0x57893678CC3EF5D2ULL, 0x6EBFF0B0BF2260DBULL, 
            0xAEE9B26561ECBD69ULL, 0x853FF2AE14066294ULL, 0x44C6D8DE504983C6ULL, 0x080F56AD4286EAE7ULL, 
            0xBA9EA4BAB856C5AAULL, 0xE9591BD9200430FEULL, 0x0B33CC8E12C15CD4ULL, 0x045839AE297D8460ULL, 
            0x2ED91A3C535BD502ULL, 0x4483737697EA20BDULL, 0xC5A547FDAEEA2C11ULL, 0xBB08BCD76C6BA4E5ULL
        },
        {
            0xA0C2D744BC3D048DULL, 0x190CB41275AF294CULL, 0x69C46B7A77AFE17CULL, 0x7718673707606006ULL, 
            0xAFF3B2EA684E8F15ULL, 0x9CD9EB669DB0F754ULL, 0xC94057BD87799358ULL, 0x102600438B2AB2D0ULL, 
            0x39656F47BDEDB6F0ULL, 0xD89C40080BD6A2E4ULL, 0x863787278B6A967AULL, 0x460A1A2A2466E96EULL, 
            0x77E57ED7A646A09AULL, 0x1EE37AC2353FF98CULL, 0x3F619363E4D59608ULL, 0x3C6C301F77ED0C27ULL, 
            0x0C384501ED947234ULL, 0xD3E8FA8DBF7A1ED0ULL, 0x67D72D4A1C40B5EDULL, 0x2D5EBBE1E6E56E67ULL, 
            0x1F3A5BA4112567FAULL, 0x45050E555D3F16D4ULL, 0x0651DAEA5EF93E64ULL, 0x03D90AE9C72EA453ULL, 
            0x7FFB9BF350DFC356ULL, 0x951AC8E7034F1A5AULL, 0xD696CF9CC71ADF5FULL, 0xBA5DDF1ED797E210ULL, 
            0x8BCEFDCB1A025139ULL, 0xAE9D4A396618AB68ULL, 0x2AB7334AD9C53EBDULL, 0x7672B643E4E9A0F4ULL
        },
        {
            0x5743326B042FB8B6ULL, 0x4E77D0679654710AULL, 0xCAAB38E0E1C9F80DULL, 0x8164EE479C31BB56ULL, 
            0x076C2A8CC5A98772ULL, 0xA3406A6FC0FFE7CBULL, 0xA66A4ED59882779CULL, 0xAC3E528CEDC3C593ULL, 
            0x46EA87B0E5E14795ULL, 0xED3F52D368449DB6ULL, 0x1A4674227871532CULL, 0x32A02DD732EC9B20ULL, 
            0xCF27C217B9A9D1A3ULL, 0x5F2A3AA42AC92076ULL, 0xE1E0C3851B2C72BEULL, 0xEE613E0386C661D4ULL, 
            0xD06ABB488A992CC4ULL, 0x034C980E7D4AC912ULL, 0x6AF4CD6C155DC894ULL, 0xA8BDB1C20FFBE573ULL, 
            0x99C24F2B0C2207A7ULL, 0x55C116C3ED7E3008ULL, 0x710DE39D44C91F9AULL, 0x40A8B19C4A6DE863ULL, 
            0x8C5BBF2DE0528CC5ULL, 0x49D5F0F77AE3B235ULL, 0x73E230FFA1A95B59ULL, 0x559AD8241DE4FAE2ULL, 
            0x00993754F2526806ULL, 0x5900458EFAF65B1AULL, 0x8947757AF88616AEULL, 0x37BE8CF9E151E90EULL
        }
    },
    {
        {
            0x2EBE9C2B261AA9BAULL, 0xAD928D0BA2685C72ULL, 0x7AFBC957FEB9B0C2ULL, 0x98AF3A7946579A90ULL, 
            0xFA8FEE80F5B80FCFULL, 0xAC1597C0CB3F9F85ULL, 0x0E756A54B5502A86ULL, 0x6D11BD949083A94FULL, 
            0x59676FE96547B0FFULL, 0xA509D619D00724B6ULL, 0xDD53E75598409A13ULL, 0x9EBDCC56AF6D2221ULL, 
            0x1D9647633A0C1C35ULL, 0x20149A13A85B8286ULL, 0xD4A93E9AC22F25CCULL, 0x0155D58EADB63284ULL, 
            0x44318D313C7635B4ULL, 0xDBBFF809010AC0C0ULL, 0xF5F8BF7DD2433108ULL, 0x99E15C17DA17493DULL, 
            0xC6F0AC734E8843EFULL, 0x3BBD997BA69E3ACFULL, 0xFE44EC60FD8BF2A7ULL, 0xF4B9ACB5C4AB70F4ULL, 
            0x5077AD9E207B10BAULL, 0x06FFE6DD58CC0E00ULL, 0xD0F6FDD6D946B08AULL, 0x63CEEC4CF4170137ULL, 
            0x7E4C35F92DFBBF07ULL, 0x45B14F3CD0BAC4DEULL, 0x9264A3EB8F4EA2C3ULL, 0xA783A4AD9A4B1E0BULL
        },
        {
            0xD11AEA8D6FC04A1AULL, 0xBEB5418225887DF0ULL, 0x993D13696B211B4CULL, 0xA0A67E81DC8EFF94ULL, 
            0xD51BE30548381DC1ULL, 0x38B03FC60D4D6673ULL, 0x03426C56180F1A0DULL, 0x452273D1A53A5F51ULL, 
            0x79A51A63306B7F92ULL, 0x2470F1078A225DB5ULL, 0x3117E56432D9E94AULL, 0x7D4F9E387D47AF58ULL, 
            0x5A90F6D3AFBB232EULL, 0xA2EB8A50C0D2F46BULL, 0xFCB8E53AC852284BULL, 0xFA88C92FCD5C92CDULL, 
            0x6EC840A5F7307383ULL, 0x8D4A819658F090FFULL, 0x8BDC6D8BE51ACCAFULL, 0x652BCF00CAAFBCC4ULL, 
            0x9F1781855D079165ULL, 0xCD30CD859546ADDAULL, 0x1044379E880FE432ULL, 0xC39F2871B41BFBA3ULL, 
            0x3A4EAB9C631CDF1BULL, 0x2428E667DED410DFULL, 0x00AA5FEE1BE435C5ULL, 0xBF2CCB2B7D8CA1ECULL, 
            0x65BA645C71ABE683ULL, 0x54E4A793C9732FB9ULL, 0x5C31EC952211D8DAULL, 0x1E2D875E14EA2EDBULL
        },
        {
            0xE5AEE4FC1A95F6BEULL, 0xCA917F9147BEA0F1ULL, 0xE933B17F7603192DULL, 0x75A67A2D0D25B110ULL, 
            0xB9823352FBF8343CULL, 0xA4A1C2047FB29BA7ULL, 0x513D3CC765265464ULL, 0x41EBBA03B6765555ULL, 
            0xFFB6DC3D017A0818ULL, 0x06D681F19A075881ULL, 0xA05C2A02B562B200ULL, 0x1AF4BD693CDF26FFULL, 
            0x3DB97522E73FB421ULL, 0x77D9CAA8C5F87C19ULL, 0x5628C83D811021E4ULL, 0xEA670973281CF9EDULL, 
            0xE1F69339D02E65F5ULL, 0x87309051F464AFD4ULL, 0x448FF57309C7EBFCULL, 0x66A395D8A8BD88ABULL, 
            0x06952E0F0EA17FA9ULL, 0xEE55F1FDC7452B21ULL, 0x3FFBA1157C32AE0CULL, 0xF8CBEAAA79222F00ULL, 
            0xA89EB2C7B0D63D2FULL, 0x9D44A57E7F8CA14AULL, 0x5528874C91BC8EDDULL, 0x7A8B1204A34A7853ULL, 
            0x571DFBAF3F64C824ULL, 0xA25291A3F86A0344ULL, 0x1141B66D18DC873EULL, 0x9FF73500CA67326EULL
        },
        {
            0xC52F65F15F656BF1ULL, 0x65799AC5C97DE196ULL, 0xAC6CEFAE2A16C281ULL, 0x099E67AA37117EE7ULL, 
            0x111C19AAE4717B72ULL, 0x533F2942A54AAE85ULL, 0xC9A48EAF1CE56F3FULL, 0x53D24558CFA25713ULL, 
            0x97BCFAEAAB238961ULL, 0xCB3AAD3366654D9DULL, 0xB853458F4C110B9AULL, 0x4B7B6FE4DF77A513ULL, 
            0xC9E00C17D30276BDULL, 0x93102F8EC9C4150BULL, 0x20FC5252491B44F4ULL, 0x6A759A5AC90A10D1ULL, 
            0x31E50FB2B130DAB7ULL, 0x3B57B72D399A69E4ULL, 0x9F3E94ED5E51F28EULL, 0x0FB4DD37A1BE3C0FULL, 
            0xF1A2D93458707F60ULL, 0xECEF7E75DBA123ECULL, 0xDDE45C135DB10239ULL, 0x5E89A799BD858C78ULL, 
            0x2C2DEB2ABF22C963ULL, 0xEFEA300A461BE0B1ULL, 0x71C9B31209C59F99ULL, 0xEDDD8CCBE9D41F82ULL, 
            0x009D3044C46F148EULL, 0xA3881261650070C0ULL, 0x9D01A5FE5D5152F6ULL, 0x15CD1A4876E91014ULL
        },
        {
            0xE6F65066A320BBA0ULL, 0x837D029A1722FF2FULL, 0x2FC155907B8B9204ULL, 0x8DBD40551A9DCDAFULL, 
            0xEBE1C3D1052F1596ULL, 0xDF508CD802AE1225ULL, 0xB9E6CCB960E62BB3ULL, 0x726BC8FC6E9AF821ULL, 
            0xB080E7E2CED6A295ULL, 0x834101A6D846852FULL, 0xE8D70A3CF89A5B2EULL, 0xA0DB6D1745E21F7BULL, 
            0x93C5402A8E711561ULL, 0xC1FA756C218525FAULL, 0x40624C1DF1401487ULL, 0xFC8AD413941E1F37ULL, 
            0x659D654A70CBC4AEULL, 0x94240DCF2CC67D71ULL, 0xCF7D70982C15CE4CULL, 0xDB7210402B89FD5FULL, 
            0xD4428AD0A6033957ULL, 0x6B4DC92F4E72BF10ULL, 0x74728CCB68D4C47DULL, 0x1C93502F15F9C619ULL, 
            0x4CFF0A39F8B723D5ULL, 0x2BE8BA63097E1904ULL, 0x922B60B435B06075ULL, 0xA069ABD4DC9005D4ULL, 
            0x2D275C2D93B875EAULL, 0x6D83DFC6F543F152ULL, 0x864B8F06A2768E06ULL, 0xB909DC7FEC9223A8ULL
        },
        {
            0xF005DC1AF3163AB6ULL, 0xB10A5777EAF54FB0ULL, 0x3BEBEE227AF04700ULL, 0x7B446B47865FA634ULL, 
            0x5AFBB1750978BF9CULL, 0xFB218F0D9B877F65ULL, 0x8244DA7C343CA988ULL, 0xB65E928321349CE8ULL, 
            0xD7402AB5DF5A8AB0ULL, 0x66021C5C0614AD59ULL, 0x84625E9C9FA7E26AULL, 0xF1EF67718C7CB78FULL, 
            0xBCD3F9C8BB20CC7CULL, 0x43C668694AB4B78FULL, 0x91D44B9F3EB66B65ULL, 0x996F8F3DC0004A97ULL, 
            0x7CEF0C1B08E7D5E1ULL, 0x2A0031C27D89F3C1ULL, 0x6DF70227DC6C5D53ULL, 0x3D0F1775C385EBB8ULL, 
            0xC3A2A348A3759A0FULL, 0x16D55FA7125F2E26ULL, 0x78C9E179BEE55851ULL, 0xCB3E2833AEAC1306ULL, 
            0x8F60793DBEB65481ULL, 0x59C454E9202E3882ULL, 0xE3EE2B71E6E165C2ULL, 0x8303DD296648A0F1ULL, 
            0xF362978BC903558FULL, 0xF5E45B93C62FCD14ULL, 0x9A94DE33B979E840ULL, 0x9D806CECF0D16F64ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseGConstants = {
    0x3DB6405CD01F4509ULL,
    0x62AAC050CB3DAB17ULL,
    0x9F6E7C646422A40BULL,
    0x3DB6405CD01F4509ULL,
    0x62AAC050CB3DAB17ULL,
    0x9F6E7C646422A40BULL,
    0x640A0D510E40C3ABULL,
    0x35F8406EC7BAB885ULL,
    0xB5,
    0xBE,
    0xD3,
    0x43,
    0x8F,
    0xF3,
    0x07,
    0x2A
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseHSalts = {
    {
        {
            0xABF89623F3EB9EB5ULL, 0x0CA2AB6FDEE76D4AULL, 0xDADD0036DFB98CC5ULL, 0xD4BF22246EA40398ULL, 
            0xD5E8C1C2CBD8ACB0ULL, 0xF25F521B20B4C3A0ULL, 0xD2B49C5D52C7135CULL, 0xFF106FCB420F6D9DULL, 
            0x0DBB3308E51EF4B4ULL, 0xB534FC9398F4A4D3ULL, 0xA6E58124DF86A3BDULL, 0x3DA33D1F519473E9ULL, 
            0x0783F243C9B6243BULL, 0xED65F5178FEF2A95ULL, 0xC1A8D31EFBEB93E0ULL, 0xD3CF3F12DD7AD17AULL, 
            0x55A087C095E238A4ULL, 0xCCDF23CBAE3D9DD3ULL, 0x2C2D10F9295D076FULL, 0x229E341C4D145ADAULL, 
            0x029D7E37DEC207CBULL, 0xA4D31D3F7082053BULL, 0x2E65AE816117B3E3ULL, 0xACB300DBC93A83FBULL, 
            0xBE5B84EAAE34E9ABULL, 0xF09A9E08E693262EULL, 0x5177F0D33C88BE2DULL, 0x9C686F4EA4A1AE33ULL, 
            0xB5D4B38ADE50EB9DULL, 0x56090AE8DFA0A63EULL, 0xEC20F4A37F4D3517ULL, 0x7D0BC65C06CC3A36ULL
        },
        {
            0xD6C6F79F753D0D9CULL, 0xEC034EA2BE1BA54AULL, 0xD312E8B280B997C9ULL, 0x7226955A407B5188ULL, 
            0xF5E0A4E5E72CE359ULL, 0x3BAF91669DCB2B19ULL, 0xA1392518CD0AA10AULL, 0x8752328548799CF9ULL, 
            0xD6B643D0DAE1B653ULL, 0x75FC725BF07F449BULL, 0x004521ABD212F986ULL, 0xCB0B1B6C42B60A13ULL, 
            0xB0EB0CE61C1B86DFULL, 0x5FB9DF112088C114ULL, 0x04D847908CB3F36DULL, 0x4D141FAAB2397101ULL, 
            0x21C27D2176B19D9DULL, 0x2091E9C57E4EA816ULL, 0xE842C5885E327BD9ULL, 0x5A8E8917C3F91066ULL, 
            0xA599F3B40754095AULL, 0x964B08F7ED79D4CDULL, 0xA6AA3055FD148961ULL, 0x8BFA61C4A6FD7B52ULL, 
            0x1DA4C6B68AF370D6ULL, 0x800911401246D03CULL, 0x2D20D0ACDDE583E6ULL, 0x52EDCA02FFD0386EULL, 
            0x6BA51ADC110C01E0ULL, 0xC982EB7E436361FFULL, 0xE684AACB5EABBF54ULL, 0xECE88E66C2C59A4AULL
        },
        {
            0x037F64C06A92128EULL, 0x9E18393ECF3B3963ULL, 0x953DA2F8067FCAB9ULL, 0xE7D5AFFAA905F6FAULL, 
            0xC03ACDB2AA495BBFULL, 0x85C4DFFB2BF842CBULL, 0xDB6EDCF9F86E70B4ULL, 0xE615F3D48BAF7219ULL, 
            0xAC3316A639CC75C1ULL, 0x7A71D6C8420F6022ULL, 0xE1CE18921BDC48BDULL, 0x77F0CBEF0264FC05ULL, 
            0x9A6B6B5E48488F77ULL, 0x2C778FB8639C612AULL, 0x90AC0CF8F6919B88ULL, 0x7F03327A29733B32ULL, 
            0x39EE5D973F2D9879ULL, 0xDA6A14B06D4AFBC7ULL, 0x21D4E30B6A2B7128ULL, 0xB6D70C13800622D3ULL, 
            0x700ECBE21FF52A7AULL, 0x6917CD8A73A957D5ULL, 0x567930C989725A82ULL, 0xCE04649856560324ULL, 
            0x3FC9324BFA371829ULL, 0xE3AD7BB145FBA4E1ULL, 0x38957FF1AB1744AEULL, 0x437F0D16E083C6BDULL, 
            0x7170634DB1CE650CULL, 0x19CF446234BF5203ULL, 0xE4E940F1E2A6B88FULL, 0x30798F24FAA7C914ULL
        },
        {
            0x5EC7902AB7A0AA4AULL, 0x63AB2168BCA7F9B5ULL, 0x1F939A4FFDC6DBC8ULL, 0x66C6AE4CD0D312AFULL, 
            0x7EED2601BD99402AULL, 0xD042C3E55A124EEAULL, 0xD8076397B39A64B9ULL, 0x5FA0CC5C46301AF6ULL, 
            0x14A0BB4DA012E74CULL, 0x001802C950BEAD90ULL, 0x9660ACBB2BA6A954ULL, 0xA6469554488E9F7FULL, 
            0x936B8A137D7BD828ULL, 0xFFF3096E3F962FA6ULL, 0xC709D33919725827ULL, 0x2C0702E6F7015605ULL, 
            0x738975BF1DF91C6AULL, 0x77F3BB933067F0DEULL, 0x8DA7F1D70B78E130ULL, 0x93547725CDA45BF3ULL, 
            0xD2776BE08A2ACC25ULL, 0xB4BDE76DD16ADE97ULL, 0x970613D6AEE45A27ULL, 0x9927A9E15D84A243ULL, 
            0x762F15A6C977C4F2ULL, 0x0F378B8317FD465DULL, 0x439CF0A2B823875EULL, 0x20C7444EA6C6EFC1ULL, 
            0xEF3D1BFB04589951ULL, 0xAD1F6B3F2F24F22DULL, 0x22BDE75C0017ACD5ULL, 0xA470998E77EC8BFBULL
        },
        {
            0xE5487C57D2D5FB80ULL, 0xFA1F20D1E6037133ULL, 0xD0A402CA45BA4ED1ULL, 0x35C17FA7807E40DBULL, 
            0x00DB37394217E9D4ULL, 0x42C508B79F38D4B1ULL, 0xE6F21BDBB545578BULL, 0x1A8421FFC07C2532ULL, 
            0xC5523636CCD85D41ULL, 0x3174E2EC8EC5D549ULL, 0x8B356B37421D47B2ULL, 0x370A589123E371F5ULL, 
            0xD9045D7F82618FACULL, 0x9636633EF72443E6ULL, 0x27E9046CDF84BE47ULL, 0xFA26FCD70AE70EE7ULL, 
            0x7BEBDF0CA4B3C1D5ULL, 0x3028B3AEB8857DC2ULL, 0x5708016466BB7E0BULL, 0xC1AC5F6A118C1BE5ULL, 
            0x617C36AE36FBC4D8ULL, 0xE8E22193835D3E5DULL, 0x6A70F072CAF6964FULL, 0x745ECE2960A496FAULL, 
            0x99CA4C78C25CB417ULL, 0x2784C603B57484C4ULL, 0x2B816AEC71C4F796ULL, 0x9EEC2E1B52D6173DULL, 
            0x230AED5B437A6B11ULL, 0xE411526C7625BB98ULL, 0xC897A876881B45B3ULL, 0x24DA09BA321A1A03ULL
        },
        {
            0x00D1A4D9E6B54DC1ULL, 0x85450696F1869E5CULL, 0x0FD37D0DC56405FBULL, 0x22307FF7EC065A30ULL, 
            0xD53B9FFF5D2B8F4FULL, 0xDA4217DCFA5A80D5ULL, 0x467297CA50150F8BULL, 0x62BEBC560A034F07ULL, 
            0x69AED3475EA3EB43ULL, 0x107CD1AB525D09E5ULL, 0x892658DF1D47456FULL, 0x88F972A00A11C28AULL, 
            0x19FEA1702EEBFEB4ULL, 0x1C2CC1E0DFEFD645ULL, 0x4BF0861AF5B87F07ULL, 0x5EF6E44110D3FBCDULL, 
            0x32C1D22092F5E8FFULL, 0x2713E54933A85A6DULL, 0x6E924E2EBC04BD6CULL, 0xA3E3071B1D182757ULL, 
            0x0F6D0E9EC4E9D3A9ULL, 0x12874923C081F6D9ULL, 0x84D413555EA73085ULL, 0x2694C945BE7FBFACULL, 
            0x23CF8183188A29CBULL, 0xE51E39EF64D0246DULL, 0x82A0F2F0E9366853ULL, 0xE0FA5BD2B75459F3ULL, 
            0xD7D5D4A73AD0EE93ULL, 0x987DD022D85ECFFCULL, 0x51CEA00253FF4F2DULL, 0xC6E5A4CF940E625DULL
        }
    },
    {
        {
            0x963A516911B60F90ULL, 0x04C53FD6FE34D8BFULL, 0x8F8F224916D148F6ULL, 0x4999EBA2E24A64F6ULL, 
            0x5F82E641DD582A5AULL, 0x0B3030D501623693ULL, 0x073E322053D0BF8EULL, 0x2B3C5F05762F3BB5ULL, 
            0x26739CED1E17DC6DULL, 0x943D0E3ADE0BD1B1ULL, 0xC91C5C5CA4A6881BULL, 0xD86E800CA00380A8ULL, 
            0x2A7BB083C03B22EAULL, 0xDBEB07AB057CD3E8ULL, 0x9E469AE8DA59679CULL, 0x506E89F91D800BBEULL, 
            0x07344D271753BE7CULL, 0xF2C3BC363E6B72BFULL, 0xEA610FBF79388B46ULL, 0x26EA5F4B047E3061ULL, 
            0x9DF4976BA282955CULL, 0xB8E5222490C867F2ULL, 0x86E7A561B4A0227DULL, 0xAE13B85F812BDA59ULL, 
            0x78C054060387276BULL, 0xE8C2C965B8CD1DBDULL, 0x92AFED170EDFE5F8ULL, 0xB9CCAEBDA6759D97ULL, 
            0x52E1DE273508FA69ULL, 0xBF55E22D343DE00EULL, 0x89728E2E366511CBULL, 0x151BD2961E059696ULL
        },
        {
            0xE4F1218373C692A6ULL, 0xD5D95569CF0A6803ULL, 0xD5FA10035B101F48ULL, 0x2B28D0A13863D3B4ULL, 
            0x7AA9A59CC7069FB7ULL, 0xE452E211F19781D7ULL, 0x12683267136B9598ULL, 0x7AF26A36751230B7ULL, 
            0x2BB2DAF2B9AF31E5ULL, 0x2A3178323DE4CE83ULL, 0xC6713E68A6F09989ULL, 0x944693CDAF7BD42BULL, 
            0xD5E5814C148A000BULL, 0xB4A88D9DFE14933CULL, 0x9C47A2307344C0F1ULL, 0x194F4EB616DFB28FULL, 
            0x06774B109B6AF13DULL, 0x4294D8DC2F576FA3ULL, 0x79D16B2E849255A8ULL, 0x05D41C387A41E0EFULL, 
            0xD1E595D9898249E9ULL, 0x3B7173BAD6FD5662ULL, 0x9F3A5A9D2C5AD002ULL, 0x200729E0BC248EB7ULL, 
            0x72476C018C11E32AULL, 0x91182CEB316C8109ULL, 0xEC2247A0BF1C002AULL, 0x857857C2E04CF527ULL, 
            0xFDAAD20E5099316FULL, 0x9CB48382CEDB72EDULL, 0x4C2FC37A0EE7BD02ULL, 0x3CD7A6E4A4445F83ULL
        },
        {
            0xC60B226E8B9C9D1DULL, 0xA7E5240D3CA4745EULL, 0x9652A8599AE3342BULL, 0xC96B7A23F769123BULL, 
            0x610AEDCCD97C1050ULL, 0xE95CBB4D8C04544EULL, 0x021D23F908C2A523ULL, 0xD5363790F945DA15ULL, 
            0x1A5C195FA0C44723ULL, 0xCE07198BEA6C2E19ULL, 0xBDC0BB7957BF52A3ULL, 0xDA1C068F5AFBBE0EULL, 
            0x6FF8317E35006B1BULL, 0x9CE0E18CC9EA2DFEULL, 0x0B8B90669B454808ULL, 0x5CF43AFA3D27C98EULL, 
            0x844FBCA647F917F4ULL, 0x0FD506527569922DULL, 0x040E699C63EBD125ULL, 0x555DDB873B393D52ULL, 
            0x78FDF30F522E74F7ULL, 0x9BCBA46B9D7A4DA1ULL, 0x0F97C86A601DCFF1ULL, 0x51A79373CA64684EULL, 
            0xA5067A8D29368026ULL, 0x04E579371A668905ULL, 0xDBB625AA589FA8E1ULL, 0xC190C7E459ADC391ULL, 
            0x9F800A49E0221D05ULL, 0x6C43517665D76AE2ULL, 0x17DE5540C8C1399DULL, 0x57D5A4A96422BB92ULL
        },
        {
            0x63B8539406FEFCF1ULL, 0xED507310D9B97453ULL, 0x263D35703A4E9DDDULL, 0x0BDEAF4057EBAAA7ULL, 
            0x0D11C321B9F08C49ULL, 0x0C530D13918E0612ULL, 0x80F315D4837B3776ULL, 0x988A60CE8492A62FULL, 
            0xBE2DB7C27CE9FAB0ULL, 0xC8984A4A6B195667ULL, 0x3277641B168EBC9BULL, 0xB6C834ED6A019F20ULL, 
            0xF826CCA86C7EF977ULL, 0x41DA1C86E28B28DCULL, 0x2F05CDA4F0155AC0ULL, 0xF8F37C4789A559E4ULL, 
            0x460273C215E88030ULL, 0xE5DF37F5EB0D75FDULL, 0xBB889EA3A70EE92DULL, 0x4AD609CE067B2FC5ULL, 
            0x158AF5056913F049ULL, 0x85861AE44E6D77F4ULL, 0xA90648AC25F5A134ULL, 0xE7386D5AC991D730ULL, 
            0xCF1AA2C5D1CE908AULL, 0x66A7DF704F34D2A5ULL, 0x2B3962D4F805E637ULL, 0x4E18023A281DF703ULL, 
            0xD0CBF1C03A823EC3ULL, 0x0AC7B46074E2EEB0ULL, 0x1F500A79C4FA0E0EULL, 0x0C7B51364E07EFF9ULL
        },
        {
            0x5170651D18555648ULL, 0x09CEF619836AF5A9ULL, 0x8D51883A6B95D055ULL, 0x7CAB6C68F2948C33ULL, 
            0x74172C2A8CC0DD2DULL, 0x8E7D7630AA76A2FBULL, 0x81BF341AA80233C3ULL, 0x7DAC09BED0F03D9CULL, 
            0x2EC6DD427DDB1A51ULL, 0x24E108F93F6C0489ULL, 0xF4CCAA0716A17EF1ULL, 0x3E4B7DD7EF53A9B1ULL, 
            0x3684FC5B222ADBFEULL, 0x9090B791D810AF86ULL, 0x7FCDBCD38472B460ULL, 0xE59DEB66A31FCA32ULL, 
            0x1E923F2C2CB15D17ULL, 0x5AB89069F6922D8EULL, 0xE5DEBE3B05B270A2ULL, 0xBCD5F652A2F5A736ULL, 
            0x8F10B26E50264AECULL, 0x1EC0D7AE283038E9ULL, 0xBB77CA1B2F1F5399ULL, 0x377BCF27B21B8044ULL, 
            0x3D4291CC00741657ULL, 0x01DFE9A8DB4B6B20ULL, 0x798285D7A42AD3B9ULL, 0x70F416507410AF16ULL, 
            0x629F7D469C6674D1ULL, 0x6796BB96700838C4ULL, 0x97451D809346ECD2ULL, 0xC114A25C792BE02DULL
        },
        {
            0xA3FE6E922638F38AULL, 0xA41ECE43A03D81ACULL, 0xB11D612C9BFD4388ULL, 0x278A3FFC6B9B5C6CULL, 
            0xED3DE2A42AB780D2ULL, 0x59B00EFCA2767882ULL, 0xAB075B629948B833ULL, 0xAFCD8B7F62754899ULL, 
            0x2635806C30B3D511ULL, 0xA3D228A51C8584A0ULL, 0x25E2965431CEB73BULL, 0xE6A386173D22A005ULL, 
            0x56A0D2BA94A3584AULL, 0x534C4530DC3E5F17ULL, 0x40CCB8D6C1D2FBEBULL, 0x8F87E6D429CB67F1ULL, 
            0xA8C8D01F8D0C3BC9ULL, 0xD22EE752F7A6982DULL, 0xFF1B7CF7B29E7187ULL, 0x420F2E4CBE201D7CULL, 
            0x9B4CCA8541080346ULL, 0x649736C8693477F0ULL, 0xC7E14C75DF157991ULL, 0x079DBE68B28A7A71ULL, 
            0x6AD44F2AE69EE41FULL, 0x87A75CCD5780701CULL, 0x92A3E788FE0939A0ULL, 0xEE849A534482A03BULL, 
            0x2889A0214F91AA58ULL, 0x674B2ECAEFA8B8A7ULL, 0x4D6BB825FCAEE430ULL, 0x0FC846ADD3B5BD25ULL
        }
    },
    {
        {
            0xCCBBE356ECFE985CULL, 0xFA833335172F95DAULL, 0x83443AC4EF2CBF24ULL, 0xD75D9C195ADA76AEULL, 
            0xB1E2118476AF9394ULL, 0x416819A33AB5EEFCULL, 0xF1FB9804DC349D2CULL, 0x8DCE283835C17A22ULL, 
            0x918FC3CFC8024065ULL, 0xACDC9C02E48BB270ULL, 0x4F9BD70606E03245ULL, 0x46E46D157283774AULL, 
            0xB4F2501A904A6A10ULL, 0x604F1130CF724AE6ULL, 0x7E702D672270D381ULL, 0x543998DF72D5DECCULL, 
            0x55CCB089C1F3CBD6ULL, 0xCA170BC9988A8B76ULL, 0x854C0776B97E39E5ULL, 0x41D5AE5B1946D59AULL, 
            0x048BD1FCCEB4505FULL, 0x247209A4496BAC22ULL, 0x16952C50F856607DULL, 0x6B66F7A42E605879ULL, 
            0x3C565B1D00457BC4ULL, 0xBE374117BCBC4155ULL, 0xA7F5D6984CBDCF93ULL, 0xBEA85261B14F9D65ULL, 
            0x600247E954749B07ULL, 0x92CC2D1C2C18F021ULL, 0xFE6770AF44988D25ULL, 0x74CE7F8D606E6D19ULL
        },
        {
            0x47DD9E5FFC251E35ULL, 0xB1E170E3CBDB0A61ULL, 0x8EB2060008815976ULL, 0x837792FE5A93CB8CULL, 
            0xE61BCF6464531E31ULL, 0x32E05A45C8CB36C9ULL, 0xCDE28B6E6E8A505BULL, 0x62FDE89D0BDF4FBFULL, 
            0x62354FAB8F3C4618ULL, 0xC5BB1FC1D1B7C2D1ULL, 0x939F440A50104287ULL, 0xFE7702FEEC43C752ULL, 
            0x0BB14742B19D66EFULL, 0x89A6FB5D732AA087ULL, 0x5C80B3C4C2AA6033ULL, 0xAEAD475B05016086ULL, 
            0xD02BCE336581CB98ULL, 0x709E437CC4627CC7ULL, 0x39489E039B4EADFDULL, 0xCA4F7A62D2ED6EBBULL, 
            0x949D54B6888069F6ULL, 0xB2A74EB081092487ULL, 0x9E5E17DB0AF4EB55ULL, 0x7AC12CED96F351ECULL, 
            0x362088DF00CC4CC7ULL, 0xDEFE3EE31EA71311ULL, 0xB763F59C2F436271ULL, 0x39D0E005B7CDCC94ULL, 
            0xE7C32F75CD2A3F82ULL, 0xE4D01DA7438B95BAULL, 0x662FD8BA42C2B836ULL, 0xD406F6F4B395D740ULL
        },
        {
            0xB7A465202E9F23CEULL, 0xD38986B1E6215A85ULL, 0x2658910BF36AF28DULL, 0xF53621FC14A8A1F5ULL, 
            0xC91C21DF7E3D448DULL, 0x0F054E07486126E5ULL, 0xD5A4200249ADC341ULL, 0x85F20674D354ED7CULL, 
            0xC7C5E85A8E9DB8EBULL, 0xD381F2B4DE810DA1ULL, 0xA135D98A34711F26ULL, 0x3DA5AB7DA0C1B854ULL, 
            0x96FD359673CFA951ULL, 0xBDD6519268CFB9DDULL, 0xC4356529D24F388DULL, 0x91F8FFBF02A78D20ULL, 
            0xCC3C746C1FF4461DULL, 0x18A5463BFED2C2D7ULL, 0xB620C5935586B940ULL, 0x5634D78EAAF82BEDULL, 
            0xDDF371D966D16071ULL, 0x4DD07F6EFF4A9BEEULL, 0x2DFC6A642D8A5291ULL, 0xA718DA1027D35089ULL, 
            0xCF17946064D7A801ULL, 0x7B797C14BFAB53D7ULL, 0x85DF72FCDD01CEBCULL, 0x2C732F6073423EADULL, 
            0x41551715C37FF17EULL, 0xC20880269BDF5FEFULL, 0x66D95C3E8202E224ULL, 0xCBB0988F529C3FC3ULL
        },
        {
            0x8E034667FE06B069ULL, 0xBF2581CB173A1768ULL, 0x2ED2F4385A915115ULL, 0xEA511A427F0D3B57ULL, 
            0xC81DC6DA28474DF7ULL, 0x30CFA6BBF1074560ULL, 0xEAAF7DAACBCF4135ULL, 0xA7F942878E46B64FULL, 
            0x224AA933B15D1B4CULL, 0xE7CDADC211279414ULL, 0x43EA134F0EAB7632ULL, 0x4A22E2C6204B883FULL, 
            0xB3D7DC975B63042EULL, 0x378B31804CFB8920ULL, 0xB6CB997E6C7BA513ULL, 0x7FF46ADB3DB72872ULL, 
            0x2C6064D00DCD5363ULL, 0xDE348722FFB08871ULL, 0x8DA0119D0D310332ULL, 0xBD944CA1038677D4ULL, 
            0xE5C70417682615E2ULL, 0x46AD48B697B9E5A6ULL, 0xECAE5F651C9A2C13ULL, 0x3833D7314F9D6035ULL, 
            0x83B57715A7CC8FA2ULL, 0xF50F105A08B37A0BULL, 0x148AC021E01FC8F9ULL, 0xB46A086DBC5FC37CULL, 
            0xBC197837D01FF132ULL, 0x7C045546C3619E11ULL, 0x954265B85FEED3D9ULL, 0x5A3EA1E58434E4E4ULL
        },
        {
            0x6D3800C93CF8A77CULL, 0x9F1D278913033EFEULL, 0x4017C04BCF1FB8E2ULL, 0xED3268B583536C0BULL, 
            0x8486DEB477F6C62CULL, 0x0FAF31E70EC62497ULL, 0x3BDE09B7E7A66D6DULL, 0xAA667135B32859C6ULL, 
            0x351C6E3B3863C276ULL, 0x215A5DBB9A1309FFULL, 0x89157A437809F0C5ULL, 0xBF4D13E7CC280CAAULL, 
            0xEA6BBD8B61505883ULL, 0xF328185442DC6139ULL, 0xCE3375B3380B21C4ULL, 0x87FB6B55399FA217ULL, 
            0xE5675168F02FD490ULL, 0x4749D7E5E41DEF81ULL, 0x98C635EBABA45DD4ULL, 0x760C04301F2E2EC7ULL, 
            0x2C6821EA2970136FULL, 0xA7DF3B2100FC9E2BULL, 0x6A5F88B85DB2C811ULL, 0x150C7F2AAF1C69BFULL, 
            0x4FC81C7D479F3747ULL, 0x517E9217361B76DCULL, 0x77CE9FA608A4B2B7ULL, 0xF5A893F689EE444DULL, 
            0x6B80F0CF14631A5BULL, 0x5174111C965CC56FULL, 0x50A9351C645E038EULL, 0xA8AFA4645AD57F73ULL
        },
        {
            0xE738E00C64E9A7AAULL, 0xC6E9CE13439FD3F4ULL, 0xA634A6EAF7633E8BULL, 0x01E639910CC53409ULL, 
            0x0BD3E6DCBB118CADULL, 0x9B3429F7281A8D50ULL, 0xDF2EC9DF617925DCULL, 0x71E9B55C0EA66146ULL, 
            0xE0EAFDCF69CF5A87ULL, 0x7259CA57856BA98BULL, 0x5CFBC3FB5BAEB3CBULL, 0x94F0DD8734C64455ULL, 
            0x828755287423E519ULL, 0xAE04625B04074805ULL, 0x9C58F031ECB8BEEBULL, 0xA8BBA034C0A1FE62ULL, 
            0xB9004A970A1D3F78ULL, 0x09B85902F712E620ULL, 0x163F4323AAD53C3BULL, 0x66636B64EDC26DE1ULL, 
            0x6272942E59C5520EULL, 0xBADED6AFB3DDBF4CULL, 0xF0C623EB4FEFC158ULL, 0x13F04DDD886A0994ULL, 
            0x983BA21C1101EBFBULL, 0xD79F642703E0CA33ULL, 0x737E1F8A13AEB8B3ULL, 0x0CEA2B0D3CFFF8AEULL, 
            0x4E0CF98DDAC67B0CULL, 0x9BCCB246078685F9ULL, 0xB5F4CDD8E106AC55ULL, 0xEAF54210523B20D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseHConstants = {
    0xEAD58FB1806C4E22ULL,
    0x74D23F11EB67137CULL,
    0x6655915DFE88A50AULL,
    0xEAD58FB1806C4E22ULL,
    0x74D23F11EB67137CULL,
    0x6655915DFE88A50AULL,
    0x45FD9C8BBC0C332FULL,
    0x1901E805D9B545B2ULL,
    0x19,
    0xCD,
    0x5A,
    0x9A,
    0x06,
    0x59,
    0x61,
    0xDA
};

