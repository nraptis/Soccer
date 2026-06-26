#include "TwistExpander_BasketBall.hpp"
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

TwistExpander_BasketBall::TwistExpander_BasketBall()
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

void TwistExpander_BasketBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9631314148926489226U;
        aCarry = 11207381926265459142U;
        aWandererA = 14278734980689718536U;
        aWandererB = 12233259434856537171U;
        aWandererC = 16177891874656362864U;
        aWandererD = 17583172711747288094U;
        aWandererE = 13916941503328149021U;
        aWandererF = 16546649808616058740U;
        aWandererG = 14776619228586772427U;
        aWandererH = 15094309650558736230U;
        aWandererI = 13018417025388724299U;
        aWandererJ = 17621762720681838802U;
        aWandererK = 10365522107932880481U;
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
    TwistExpander_BasketBall_Arx aArx;
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
    TwistExpander_BasketBall_Arx aKDF_A_BArx;
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
    TwistExpander_BasketBall_Arx aKDF_A_CArx;
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
    TwistExpander_BasketBall_Arx aKDF_A_DArx;
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

void TwistExpander_BasketBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 17467913961479564368U;
        aCarry = 16677374227105872207U;
        aWandererA = 17110533269274310407U;
        aWandererB = 9847974209702393988U;
        aWandererC = 17654343175669413120U;
        aWandererD = 16150236822074289867U;
        aWandererE = 17388464711020300763U;
        aWandererF = 11161951065007776388U;
        aWandererG = 10901719246903629482U;
        aWandererH = 9807517311494844558U;
        aWandererI = 16840128705056165462U;
        aWandererJ = 12368355961766760555U;
        aWandererK = 12447292771839333250U;
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
    TwistExpander_BasketBall_Arx aKDF_B_AArx;
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
    TwistExpander_BasketBall_Arx aKDF_B_BArx;
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
    TwistExpander_BasketBall_Arx aKDF_B_CArx;
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

void TwistExpander_BasketBall::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneH (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseA invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseB invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseC invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneD (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    }
    // KDF_B PhaseD invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseE invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneA);
    }
    // KDF_B PhaseF invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseG invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseH invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_BasketBall_Arx aSeed_AArx;
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
    TwistExpander_BasketBall_Arx aSeed_BArx;
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
    TwistExpander_BasketBall_Arx aSeed_CArx;
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
    TwistExpander_BasketBall_Arx aSeed_DArx;
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
    TwistExpander_BasketBall_Arx aSeed_EArx;
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
    TwistExpander_BasketBall_Arx aSeed_FArx;
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
    TwistExpander_BasketBall_Arx aSeed_GArx;
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
    TwistExpander_BasketBall_Arx aGrow_AArx;
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
    TwistExpander_BasketBall_Arx aGrow_BArx;
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

void TwistExpander_BasketBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_BasketBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_BasketBall_Arx aTwist_AArx;
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
    TwistExpander_BasketBall_Arx aTwist_BArx;
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
    TwistExpander_BasketBall_Arx aTwist_CArx;
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
    TwistExpander_BasketBall_Arx aTwist_DArx;
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_BasketBall_Arx aGrow_AArx;
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
        TwistExpander_BasketBall_Arx aGrow_BArx;
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

void TwistExpander_BasketBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 0, 1 with offsets 5005U, 2369U, 4920U, 2992U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5005U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2369U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4920U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2992U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 1, 2 with offsets 236U, 7551U, 6949U, 8097U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 236U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7551U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6949U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8097U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 0 with offsets 590U, 8081U, 6027U, 2628U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 590U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8081U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6027U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2628U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 3 with offsets 2400U, 1715U, 1260U, 1995U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2400U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1715U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1260U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1995U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 with offsets 307U, 914U, 536U, 1189U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 307U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 914U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 536U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1189U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 542U, 699U, 1571U, 1383U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 542U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 699U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1571U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1383U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 1, 3 with offsets 1233U, 516U, 597U, 1543U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1233U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 516U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 597U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 3, 1 with offsets 651U, 692U, 1732U, 839U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 651U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 692U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1732U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 839U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 424U, 846U, 632U, 1800U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 424U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 846U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 632U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1800U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BasketBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 1, 0 with offsets 5889U, 2999U, 1319U, 5656U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5889U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2999U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1319U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5656U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 2 with offsets 718U, 2135U, 6347U, 3432U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 718U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2135U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6347U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3432U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 3 with offsets 5723U, 1491U, 731U, 6557U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5723U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1491U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 731U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6557U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 1 with offsets 2699U, 7334U, 4953U, 8059U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2699U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7334U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4953U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3691U, 1011U, 6010U, 4496U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3691U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1011U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6010U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4496U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 3, 1, 0 with offsets 200U, 1189U, 338U, 915U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 200U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1189U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 338U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 3, 2 with offsets 480U, 893U, 1977U, 786U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 480U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1977U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 786U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 2, 3, 1 with offsets 1257U, 1256U, 1702U, 241U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1257U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1256U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1702U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 2, 3 with offsets 392U, 388U, 818U, 471U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 392U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 388U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 818U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 471U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 2027U, 1719U, 1188U, 882U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2027U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1719U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1188U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 882U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseASalts = {
    {
        {
            0x27D196737D6AEFE6ULL, 0x7B308295B8752E7CULL, 0x13EA7F86B2276263ULL, 0x8355187913CA3DD6ULL, 
            0x3522EB7B290C0CECULL, 0xBC0E54883FC32726ULL, 0x0DCEF43959030AC8ULL, 0x08BB2788A0E37FC0ULL, 
            0xDD91EE7E636AF49FULL, 0x00E969879B1C4DA0ULL, 0x38053363D1086A19ULL, 0x7AFB4725E2E24A29ULL, 
            0xF5E396D566E3C37DULL, 0xEBC7DCD70492C2CFULL, 0xD063FC1BAF75E3BBULL, 0x671B630DC5C75B57ULL, 
            0x0FCA08D7AE30C61DULL, 0xC98626FE10854B69ULL, 0xEC751AEA5AD27268ULL, 0xAA50430E9428074FULL, 
            0xBC42C5E1C7C983A9ULL, 0xD3BDE7D224A3C076ULL, 0x038389B959755552ULL, 0xFF584D2B568E527EULL, 
            0x00D8A5A1A7F82F9AULL, 0xF76CB32A12DA2686ULL, 0x84FC62F4F2B2B83BULL, 0x361FB7109233BDC4ULL, 
            0x155D6985B934CD20ULL, 0x027CB0BAFDFA3A37ULL, 0xEA527F525378E061ULL, 0xDEE512E74A210D69ULL
        },
        {
            0x3093A56ED1485D37ULL, 0xEFC46AEF2BB12508ULL, 0x8F0AC474E5BB53D7ULL, 0xE252DAD24083DDC2ULL, 
            0x8D7FE88224C74CE2ULL, 0x646982CFB23CA130ULL, 0xF117567016F5B02AULL, 0xDAD79D9F761BB2D7ULL, 
            0xA8014A17BE5AB976ULL, 0x564AF2A3813085EAULL, 0xA738BB2F3359B796ULL, 0x5F4737605E0734B4ULL, 
            0xB03A1AB9AD74B1ACULL, 0xE395431463D451D7ULL, 0x84A6D4D76659C953ULL, 0x83C6124443F699CFULL, 
            0xDD1BC4DFAA40C6E7ULL, 0xB59A066A892E4C43ULL, 0x31D31C88D51C1CD7ULL, 0xEE0040C6BE0F0DF4ULL, 
            0xE93CEA4206615A78ULL, 0x1395F74C2A13C5ABULL, 0x2603B2B85E6A1FFDULL, 0x11DFA03F29088342ULL, 
            0x3F64442DCA196269ULL, 0x3F7652D20210C44CULL, 0xC826711A2E14A56DULL, 0x90B4318373F8B2B7ULL, 
            0x89E5285FD7B14CC2ULL, 0x9E19B48B587AAC6DULL, 0x8A1DDFE5BE556385ULL, 0x3EA6EAFA04C63923ULL
        },
        {
            0xA0B02EBD9B88C30DULL, 0x620312DC760F6FE0ULL, 0x1F4749DE5C0648F2ULL, 0x5433D81EEDD4F31FULL, 
            0xEFAADD838A406B6AULL, 0x0A13350E849BB687ULL, 0x96FC7A9FF8EC7A58ULL, 0x795105F6B6DADF0BULL, 
            0x82371A98A601D1A7ULL, 0x9C534CD615EA2063ULL, 0x12832936E229F626ULL, 0x2F53DA80CC1493CAULL, 
            0xFC3A646F901A6517ULL, 0xF4369C2876C82BD7ULL, 0xEBD66B7FA74E2646ULL, 0x6DCED6E9C387443EULL, 
            0xD47D2173D2E40E54ULL, 0x89FD988FE7628031ULL, 0xF9A564E2821A5DDFULL, 0x7E63592EEABC76A9ULL, 
            0xBAD595BCE622274DULL, 0x291D3F74F16B2525ULL, 0x7D1221A460E524B5ULL, 0xD9DF0E1D11BCDDB2ULL, 
            0xE2F5E9A2DE865CE9ULL, 0xBA20C45DF7818D5CULL, 0x223CE4E0F7BBEFF7ULL, 0xD9F59838B8A71E6AULL, 
            0xEA18C63C7846B645ULL, 0xDAC3FB5924F2ACCDULL, 0x3BC80EDA0BA3261BULL, 0x20C97E311558D9AEULL
        },
        {
            0xE85D7994517770B4ULL, 0x6ABB20FDABB31C8EULL, 0x4922AFF8A829940DULL, 0xF014E43CB84E999DULL, 
            0x2780361428B09513ULL, 0x5E130A48C56B7B7FULL, 0x9D36FB1563C7AF64ULL, 0x6E9028D0CD656E6CULL, 
            0x12416E926EB26963ULL, 0x74818D632A1B8045ULL, 0xC3050559C599789DULL, 0xC3E2A45E5F407F1DULL, 
            0x133D8480F8E79EBCULL, 0xEC4808C7B67743E2ULL, 0xABB2E4ADDF28C359ULL, 0x7E7C96C8C453978FULL, 
            0x5F1981B873C4A680ULL, 0x56AAEF3E5D7DD8BFULL, 0x5009C1ADE407B1D4ULL, 0xB804C2D7EDCEEF02ULL, 
            0x2A25D95C7E665495ULL, 0x253C74F143A8958EULL, 0x35C2563E676D1123ULL, 0x493D182E8D46CEDDULL, 
            0xD26CAE7805DCC159ULL, 0xAA8244558B42A4F5ULL, 0xDE7A8CF30A38B96AULL, 0xCDA8FCC2F8B009EEULL, 
            0x3EABD693997F2CBFULL, 0xCEB18E2042283008ULL, 0x06AA13B858662777ULL, 0xD2E04C836C2EAA6CULL
        },
        {
            0xB51AC305002DAFE8ULL, 0x2B412AACB4584500ULL, 0x1BF62D24156CB608ULL, 0x8C62E0E4468A8F4EULL, 
            0xD2152CE8F5FAA501ULL, 0x0B7B02D79A143FC7ULL, 0x2D8EAC659385E7E2ULL, 0x4138C30A4A26CCF2ULL, 
            0x6E8FAEC31765294AULL, 0x6F3E47A6DC0255C4ULL, 0xC073374943A942E2ULL, 0x85288FAB6746BB02ULL, 
            0xE190D69DA42CF0EEULL, 0x31C5C60757A38E0AULL, 0x6AAB50CBBF7207EAULL, 0x194F06506C3FC2FCULL, 
            0x2502AF4E57989E08ULL, 0xA52B24749627219FULL, 0xC37CAC59A7105EEFULL, 0x6893E909B1A2718AULL, 
            0xAF6A5FB36CB0B0F5ULL, 0x5E5B78CC32A1422DULL, 0x5734159AD2715754ULL, 0x2434CCF463FC3BC9ULL, 
            0x2B995E48949B5513ULL, 0x161F4FF4B9FAFE03ULL, 0x9EAECAED89A12F6BULL, 0x32DE807594C93EB2ULL, 
            0x29FAD69E8209995FULL, 0xFAA17797B8588837ULL, 0x142672950CBD3BBDULL, 0xA4827AB96B90A1B8ULL
        },
        {
            0x51789D7C36576D13ULL, 0xA98EAC3DA4D43FE3ULL, 0xB73F90009550BF71ULL, 0x9FDFA3F6D231DD10ULL, 
            0x54F9120D0F2438F8ULL, 0xF1197C7EE54C2B0EULL, 0x5E77A406C6891748ULL, 0x0D2EEE861C24F81AULL, 
            0x3915174B7BB673FDULL, 0xBEA6F7C2388796E4ULL, 0xAF5DF9AF2387264FULL, 0x74CB10F5F5896985ULL, 
            0xC2D03B215C3E6730ULL, 0x3F415F28BA09CE1AULL, 0xBBEC78D48D69C083ULL, 0x77B239398FD3B5AAULL, 
            0x42C7BF54B39D709AULL, 0xB0D13B02CA146A77ULL, 0xDD56E011E9AA2D3FULL, 0x588CA135A9C3AF2EULL, 
            0xCF5EA7DD5E2E95AFULL, 0xBD9E1957A80371B3ULL, 0x73ABFCD91687EB53ULL, 0x76FBE9359EE9D386ULL, 
            0x97B59404677E0FF8ULL, 0x01077D8386FFE680ULL, 0x62A5CE4BAD52ECA2ULL, 0xC7C297B99C7147A7ULL, 
            0x6E17C33B3F8F9122ULL, 0xCD22A38F85FE5621ULL, 0xFB9086701D404F5DULL, 0xB2EEB64B5938CE2EULL
        }
    },
    {
        {
            0x385F87C4CB892D41ULL, 0x23677FF860368E94ULL, 0xD3C7B2BB6AD9FCD4ULL, 0x31001A17627615C4ULL, 
            0xFD67916CBC7B4A1AULL, 0xD6DCE75B92B7B4D9ULL, 0x1C7D777B870E7377ULL, 0xDCCEA9933A6C6ADCULL, 
            0x12FDC2239EB2E642ULL, 0x5E4DEEB022E348BDULL, 0x99535710DCC6D257ULL, 0xEE37A2BA7832B57BULL, 
            0x76954DA300B5143BULL, 0x4CDE7DEE939D0980ULL, 0xDE535394DE21E66EULL, 0x5DDAA9DFCD1CE4D4ULL, 
            0x8F51C661CFB4292CULL, 0xEE6DD04F16B20EECULL, 0x1D590A20BA584AF7ULL, 0x14DBD638D6704662ULL, 
            0x04F2AF3B12A4BDB0ULL, 0xCC107CC6C24D014CULL, 0x7912959CE0972404ULL, 0xE8FA9B40180D26A6ULL, 
            0x0967954FEDB69F42ULL, 0xA0D733C03F343E26ULL, 0x154E1A9170C90247ULL, 0x525ECFD998F6FF7FULL, 
            0xA1344A42A5861089ULL, 0x7A3776A0826CB2F1ULL, 0xEEF65EFB7610EB2BULL, 0x11FF55A33164B83FULL
        },
        {
            0x67FB0183B91B665EULL, 0xA7640AC0503FF970ULL, 0xF5D6AF4AAEBDDF5DULL, 0xCFF56DA10A04608AULL, 
            0x41341175DB88276BULL, 0x4F3DD34F5BA5094CULL, 0xF239C14A5E7459D9ULL, 0xC340CF0AA3EC7430ULL, 
            0xB6E98004D75CD8CBULL, 0xAA0330A05FE7E730ULL, 0x93B03B581EDE74BEULL, 0x4126A0CF7BBA0C86ULL, 
            0x1D02F6004F4867E8ULL, 0x3F73B123FAF6CB93ULL, 0xD50C159B7299995EULL, 0xA64C83649E195B2CULL, 
            0xAD6673560CA0EC2DULL, 0x0C3F866BB793071BULL, 0x492CADAEB1FB4E6DULL, 0x425AB75C47F66649ULL, 
            0x0E8F7A42897C17F0ULL, 0xB4A4C148C53C6A94ULL, 0xD4D05599B06AE73DULL, 0x97F64EB91B31E560ULL, 
            0xA5DCA997DF6DCA66ULL, 0x42D0AF0F999DD078ULL, 0xACE1EDCA57C4EBE0ULL, 0x302736CBE955D642ULL, 
            0xFA339827C4DD7B1AULL, 0xF48373282718AD7BULL, 0xE1D197B8A772493EULL, 0xACB1070B6B78E643ULL
        },
        {
            0x747367DF64C55AECULL, 0xEC67196CA8DA191CULL, 0x416F7C60B92B9E45ULL, 0x10B5891679178B93ULL, 
            0x286B530902769D26ULL, 0x290AF7A8B087A64EULL, 0x45B34DBBB2B50200ULL, 0xC1BF9042D02A189AULL, 
            0x74B75B8D07EF1180ULL, 0xC51005658E6D9A07ULL, 0x3F4DDF624E7A8BF9ULL, 0xB9482859F622D1ACULL, 
            0xBB4FE0E71346EE4DULL, 0x4B6F8BB301819ED6ULL, 0x0042C41B4F3D85A4ULL, 0x4C5C4F6EF0154AA7ULL, 
            0x05D6D0CBBB78562FULL, 0xF7C9310BF81D1F0AULL, 0x469B312B27D5E7E3ULL, 0x584C97ED89BFEE95ULL, 
            0x6969932317643F63ULL, 0x7D944EC25573B904ULL, 0x54BC68C1A1E04EEBULL, 0xF5759A64462AA003ULL, 
            0x7CD2BA51103D60FFULL, 0xA10B230D4FFC9257ULL, 0x99760E022DF910D5ULL, 0x3B7EFD1E026D4F2EULL, 
            0x94DB23265B18D345ULL, 0x5C1E77B8F7DD6CE1ULL, 0x2C8AA3EC92C57B03ULL, 0x6602253D259B3712ULL
        },
        {
            0x4E226F9675797F39ULL, 0x084532577E8945A0ULL, 0x3133DAC25C8120BFULL, 0x4B81A5A297A77C0DULL, 
            0xB224388EE6BA2AC7ULL, 0x0E2D362A49648C65ULL, 0xAC7AA2F719D807E6ULL, 0xCBB43BDB8F3F7F71ULL, 
            0x02E4B38E74FC55A4ULL, 0xA6E4E2C66B2C0C95ULL, 0xC3E82120EEDB129EULL, 0x46A1EF6C4E5DA543ULL, 
            0xE9DCA4F73F2D68A1ULL, 0x3501EDF267231939ULL, 0x389552A65A9E47F3ULL, 0x60A70E6D51522120ULL, 
            0x654ECE6F4E0E75A3ULL, 0x02CB07BE41EC9E0BULL, 0x7246F6B9F88679C4ULL, 0xF530A20D48858010ULL, 
            0x8A0081941D6E4E9CULL, 0x1912AACF730A2871ULL, 0x6F4636862B8A09BFULL, 0x3FA0960FB856A2ADULL, 
            0xB98499CB710E6843ULL, 0x78BD475AAADFB8CDULL, 0x9E0EF077C1F4EE2BULL, 0x8636400FE9B212B4ULL, 
            0x459A08D9160A454FULL, 0x816F5750EAAA9AD6ULL, 0x45E590C73E260F2FULL, 0x6032D7198ADDA689ULL
        },
        {
            0x5FC72DB659AA91B8ULL, 0x637B499D12DA804FULL, 0xF45CD4EFB4AE5171ULL, 0x5ACD7670ECCEBCDEULL, 
            0xAFDE91FBBD1394BFULL, 0x6C746CC73B9A74DFULL, 0x658C225CAC6B9A61ULL, 0x09D794F1F9FC5191ULL, 
            0xC3A62D95EEF5D8F6ULL, 0xE1B642655CACE42EULL, 0x092F77C00039E4A0ULL, 0xD0A675BA116E1E81ULL, 
            0xEBA697EBDD3C7462ULL, 0x556414F0CB74315CULL, 0xD70EFB514AF63C68ULL, 0xD4F79E59444792F8ULL, 
            0x882EAF4A3B828E47ULL, 0x188A3C62DADDBF8DULL, 0x64F361A8A23E694FULL, 0xF4089344905CD15CULL, 
            0x1150538961665468ULL, 0x1EB87CAFCE2D8A95ULL, 0x776E702579B701E3ULL, 0x2670F193D67C2263ULL, 
            0x42D259DF6FCCB8CFULL, 0x171C475E72B9D07FULL, 0xFC2516DFF52E04BDULL, 0x835529C5B64248C3ULL, 
            0x3B470259ACB77D9BULL, 0x05EF571B73ABE1B6ULL, 0x00963F19A4AB7604ULL, 0x14F035BC9A587BE3ULL
        },
        {
            0x4ED9DEB098E6DB31ULL, 0x03CC78DD536A8278ULL, 0x96CBD8E669D6AB7FULL, 0xC553590B325712D7ULL, 
            0x309ADAC816A96EBDULL, 0x51BC6803B1C2EF2BULL, 0xEB5E3F72D2CCAC85ULL, 0xAE7CE33698332D01ULL, 
            0xB5930451741271C4ULL, 0xADE8472397E2500EULL, 0x43903645D62AE89DULL, 0x847E2F88A53EB02AULL, 
            0xE4842C0B4635A5CBULL, 0xC70CF638902B9681ULL, 0xB0E1F4FAD7F5EC1FULL, 0x333B16E79FF0FF5EULL, 
            0x958C3CC99D7395CFULL, 0xF9FC5CDFCE9C6C49ULL, 0x2BA7D916F9B88E77ULL, 0x6995D71BEF315B63ULL, 
            0x53FB3C84EA7B286BULL, 0x107A1B587B302E44ULL, 0xD7CA70790FFA5516ULL, 0x245B6A0B04E7ACCFULL, 
            0x8A6D5BDB8D7908BFULL, 0xB2ADD1789D773020ULL, 0x1155FE0CB5067952ULL, 0xFFBE10AF7220CEC4ULL, 
            0xBD683F44519CEF74ULL, 0x6EE2024566081037ULL, 0x21D9F2F8231F4695ULL, 0x10DFD1AA24456995ULL
        }
    },
    {
        {
            0x37FE99C133BF7996ULL, 0xB12B461FEA8C55DAULL, 0xF03A964466D49DA8ULL, 0x829D4301D469350CULL, 
            0x9743D6DA91209514ULL, 0xFA0FF7DA08FD9B1AULL, 0xE6F6E94C3CA2859AULL, 0xA6A354FC9FDBC1B5ULL, 
            0x230F526EA1666A9AULL, 0xAB99897912F5D79DULL, 0x9AE2843FAB0476B7ULL, 0xC38C8B510503094AULL, 
            0xD7EA8C624660986BULL, 0xF14A9D9617FEA4EEULL, 0xBE9A4FFAC71C883FULL, 0xCCFAAB7CBCAA23C8ULL, 
            0xBC8CA7B637198938ULL, 0xD3066BCBB16C8536ULL, 0xA744AD7A853B5FC4ULL, 0xC5DFBF8048AF8B0DULL, 
            0x992D8B9FDB1F8473ULL, 0xB0E58AC6AA6FE32AULL, 0xE1B68136AE2DBFD3ULL, 0xBA0814033174FDECULL, 
            0x334AD60065C7BF82ULL, 0x56FCCD86DC1CF199ULL, 0xD5BD94EE7AA4F77EULL, 0xBA45C18F6B8B8B42ULL, 
            0xBC115955AABDD3FEULL, 0x3DB25516E9061CB6ULL, 0xCB4B9CED3659B4EBULL, 0xF1F0FD472671B897ULL
        },
        {
            0xA8FD477FDD74C24EULL, 0x5DF834D7F2E08169ULL, 0xAEE6A8C1777C86D9ULL, 0x2CA214CB8DFE246AULL, 
            0x060563ABB69F9C43ULL, 0xD81A46BF69AFD5C9ULL, 0x7A615AD32E559326ULL, 0xCADB43EABAC95A54ULL, 
            0x3C9D77B58C8E1DCDULL, 0xBB0F02261B872D49ULL, 0xA5AAE9F907877AD1ULL, 0x12E38A8C500A3227ULL, 
            0x842AB733F142CC37ULL, 0x117D467CDE6CE80CULL, 0xB6FB25499EB4E811ULL, 0xBB45FDE16627F3E6ULL, 
            0x88CB6818CA5C747CULL, 0x107D0C935969B2FCULL, 0x783EF946D4211ADBULL, 0xE453C428165147BDULL, 
            0x44A2EE4B06169968ULL, 0x48E37D963EC81ED4ULL, 0x1BE6C6039FF1A58BULL, 0xFCB3FF05BF1B5DB3ULL, 
            0xAC86B3BCCF23CF3BULL, 0x8E5770D89CCB3E1BULL, 0x8E5E959B99002BFAULL, 0xF1FC8D13AA2D46E4ULL, 
            0xEE0CD31B5DCDA16AULL, 0x23B7EA2DFB84DEDDULL, 0x56D4A9F5B91B4B8AULL, 0x3A8387F456796897ULL
        },
        {
            0x5AE5E67500A7E2B0ULL, 0x39B778DB9BB8554CULL, 0x7BE5441E1F287319ULL, 0x7E9F4D5289DC3A3AULL, 
            0x47634E7FB27E99B8ULL, 0x07C4E4D3A6210649ULL, 0x53D2568EED493047ULL, 0x9093CE3AE4A1C70DULL, 
            0xF02A4E40AB663893ULL, 0x988A27802436C8E2ULL, 0xAE4DECA47C149B90ULL, 0x19D74B09A53E2B08ULL, 
            0x97C833FD0C33C229ULL, 0x9DC992DB9AF30315ULL, 0x5B967A7FEAF15D36ULL, 0xB36CA921EDF26E5AULL, 
            0xE3A6622F54CC025FULL, 0xD10DAA718D989D06ULL, 0xC67E5D28370DAC47ULL, 0x449EFC9B0124F4FEULL, 
            0x8E3D601DF6B9C2E4ULL, 0x12806A939788C16AULL, 0x54895866D3243E78ULL, 0xE24D945FA035FF23ULL, 
            0x8FD0F56C6182CF57ULL, 0x4BC7B40BA18B605FULL, 0x2422D9EA2BD86A6FULL, 0xD7B74065600A060FULL, 
            0x3229D03A0640EC80ULL, 0xE4B31B5E9E0D4BF7ULL, 0x2DD7D038D7BEC6D3ULL, 0xAA1E21B6A61B72DFULL
        },
        {
            0xC21337CA9BFDFBE0ULL, 0x155E98EABC14805EULL, 0xEB96910B1A5604DBULL, 0x998B62411A4CF6D6ULL, 
            0x012B7B1956AB9C3DULL, 0x8013C70F0F2276B6ULL, 0x69C9A35432CD52D5ULL, 0xE3ED6C6FA2FCD8ECULL, 
            0x0925E8316371EA8BULL, 0xBE7569525D573B53ULL, 0x9B599255F6090830ULL, 0x7237DC9B4A9386FAULL, 
            0xC7D1399BBDC4B491ULL, 0x8C1ECBF7164372E6ULL, 0x2085AF653F272E41ULL, 0x08E217D6E05C2289ULL, 
            0x3BD5FA23B1D8EA50ULL, 0x67B4C0271EB1C820ULL, 0x8B1BB1DD9D47F8B2ULL, 0x7459A1F53895C326ULL, 
            0x148CCAAEFAA499E1ULL, 0x2287B8C644F9D98FULL, 0xB06712E3740762C0ULL, 0x32BED4F88FEBB0C6ULL, 
            0x9C51F9EF79F91EF9ULL, 0xE570F5ED4EE67332ULL, 0xAB669DF344D7D87CULL, 0x514E8FE29A652D66ULL, 
            0xDA0D1E758D93E64BULL, 0x9C2E5EF17E896CDAULL, 0xA8EC439F5CB17B50ULL, 0x556E3401D825F587ULL
        },
        {
            0x2F52B02694849981ULL, 0xBD3711DF27259242ULL, 0xD24BA377F696C8F2ULL, 0x49D505D80D9E3B66ULL, 
            0x25E39CA850329E7EULL, 0xED16AAAE6CD7AC3CULL, 0x851356E64409F06EULL, 0x3C8A553B28457D76ULL, 
            0x89C2C7546BBFC5B5ULL, 0x0D126FE6A11C5906ULL, 0xEB4871834B2584C0ULL, 0x0AE658AE5AB6A555ULL, 
            0xCB8C093828BA9193ULL, 0xCCE450D11EA99C3DULL, 0xB9A446AF11F9D961ULL, 0xA5DD4A222400EC20ULL, 
            0x17B113EC79817173ULL, 0x6DE84525386516D4ULL, 0x8CA3031A423A7486ULL, 0x118732ADEAFDB988ULL, 
            0x9CCAC19936740E15ULL, 0x7C7AD35FC94EAD59ULL, 0xB83A20C4995D9D7FULL, 0x53E9C44FE2D76875ULL, 
            0x88AECBDE54EAFF2FULL, 0xBFF64B26DEF4C344ULL, 0xEC738D6915D38DE5ULL, 0x85ED893D2C67644FULL, 
            0xE6F91F03F6B33B54ULL, 0x58A235282C18949BULL, 0x8B0CDBFC01F0C380ULL, 0x7E8A47FB80BD0364ULL
        },
        {
            0x5FA397E75E654334ULL, 0x5016FF3828FD08ABULL, 0x7F33C3285FA73FAAULL, 0xA585CCB1FDD1204EULL, 
            0xDFF8A2BE8CF82A83ULL, 0xE8BA3F03A925A9DBULL, 0x1291EE319B2D4B30ULL, 0xFA4736C00A2D2FFCULL, 
            0xA3A5AE5E5E16CC98ULL, 0xB39420CC77840134ULL, 0xD13893B90BE457B5ULL, 0xDD2586CD4FB30CC6ULL, 
            0x2C6C2FF3A776457EULL, 0x9842B237FF11F97DULL, 0x4074C32D345E4C25ULL, 0xCB7DC95A8D896896ULL, 
            0xAC4B7A45DACA5167ULL, 0x396A8D4EF4D8183EULL, 0xAA496FA02F2E327EULL, 0x351EF7381CE13FB9ULL, 
            0xD77BDD14B28FC851ULL, 0x44BC9C8D1AF7F567ULL, 0xE6E3F28E487A4B8DULL, 0x792C558919D37659ULL, 
            0x103E1B3203DCC3CCULL, 0xCA1CE12A2EDBE547ULL, 0xECD1F948DDBDAB35ULL, 0x683848AC2933C965ULL, 
            0xB899992475865815ULL, 0x7CCC20E3753CD164ULL, 0x83191014001FBBA2ULL, 0x0F86C67B42BCE696ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseAConstants = {
    0xA6BB39C51BF82C38ULL,
    0xF372C22B3AA7F250ULL,
    0x797A0E54EDF43B63ULL,
    0xA6BB39C51BF82C38ULL,
    0xF372C22B3AA7F250ULL,
    0x797A0E54EDF43B63ULL,
    0x74B7D3630A562AD3ULL,
    0xD5D9C7AD6025759DULL,
    0xC5,
    0x8C,
    0xDE,
    0x0F,
    0xEC,
    0x27,
    0xC1,
    0x64
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseBSalts = {
    {
        {
            0xD4D831BB0FC70E86ULL, 0xC626F88B4775050CULL, 0xEA72893652CAAF27ULL, 0x4640A021A207C146ULL, 
            0x6C0628AD8DD61455ULL, 0x788535A262D355B5ULL, 0xC021D98967675916ULL, 0xAA7AFF412DD75DF0ULL, 
            0x141D3D8D015136B8ULL, 0x20500F9CAD5302B2ULL, 0xFE5B02D306E0C68EULL, 0x7FF49C2F4ADFF926ULL, 
            0xED2D89A735E335A6ULL, 0x93BEF6C42125A895ULL, 0xFFF69121F6E8762DULL, 0x5996DD3AB27442DFULL, 
            0x7543B440FC69B6CFULL, 0x711E363F0822686AULL, 0x596B3625D6AAF793ULL, 0x8338CA173FFFF9B0ULL, 
            0x25A1FCD67902D0A0ULL, 0xB1AE950040584AE4ULL, 0x84B6E65414674579ULL, 0x7569DE42AC76FE04ULL, 
            0x91A38E10C2FE37D6ULL, 0x658CF1DDD078E1C3ULL, 0xAFA378A71A7DF39FULL, 0x325976FCF4289FACULL, 
            0xC49C9699D6A70819ULL, 0xC7142DDA505C49EEULL, 0xE2AA85F47D7FBDCBULL, 0x4F1D8B5252067306ULL
        },
        {
            0x999BEEC1032B7A76ULL, 0xA6E362BCED2FA3E6ULL, 0x62411CABB3E140DCULL, 0x714928F73DDABA6DULL, 
            0xC2DD173A7B3B446FULL, 0xE83C84799A7E3403ULL, 0x5701AA595D0618C0ULL, 0xC3FE552A3045BDAFULL, 
            0x4DD98D36CC1D283DULL, 0x94D5C564A1C41E42ULL, 0x371A57961216598EULL, 0x8B924337D1585782ULL, 
            0xB178A2739A3BA458ULL, 0xDF0AF98B1F3FDE66ULL, 0x4D6622E58980B21AULL, 0x7320AB220DD2AFC6ULL, 
            0x296C08B186AC2ADAULL, 0x00D0174FF2F8E7E6ULL, 0x5866C6A192621924ULL, 0xFC53775EAA741BC2ULL, 
            0x610070AC3387193EULL, 0x6B2F22563911FB93ULL, 0xC7282C970663DF84ULL, 0x94E0BE0A7B6AEF76ULL, 
            0xB7FE25B61E0918A4ULL, 0xC4864DBB1D5109A9ULL, 0x7909C376D97FF6ADULL, 0x7416A6C94B5B66EDULL, 
            0x64CE775EE22A09B5ULL, 0xAA911AF62BA2FC4DULL, 0xE2CDEA1838AB6C01ULL, 0x71F3EED1BDA5481EULL
        },
        {
            0x390C4EC4567D0DFAULL, 0x1E4AFD79EBF0F440ULL, 0xE13F2831FA824A7FULL, 0xC03D3D1588EB2BD7ULL, 
            0xBF61C98E5BC0E198ULL, 0x32EEE4A98FC0D317ULL, 0x9804FA10807662EFULL, 0x0AFE2F51DF510762ULL, 
            0xDF5574CEFC3970A5ULL, 0xCBE0DC0A9A3CDFBEULL, 0x5C1254C71CE8F0A0ULL, 0x230CCE9374BB364EULL, 
            0xEE6432DC63F5F331ULL, 0x229F200211F2C52BULL, 0x1AA5E1018F6AFE72ULL, 0xA8930A101B99F69DULL, 
            0x2374D77DD7DC3E47ULL, 0xC3B5C39BAB7878A5ULL, 0xE6E152263BCA99E0ULL, 0x141399ECF7492038ULL, 
            0x5AC870C0EB81EA01ULL, 0xE2F3933854775A44ULL, 0xBC72E901CADBCA96ULL, 0x6F3BC37D6F5CE6F9ULL, 
            0x58CD95F09FC418CEULL, 0x1C40384EC92162F3ULL, 0x272F7C48CC6C8DB5ULL, 0x75732ABAC105A331ULL, 
            0xAEACB0922A3EAA5BULL, 0xE4F71ABF9B80933EULL, 0xE73895265A1967B1ULL, 0xEEA1893B63B506D4ULL
        },
        {
            0xE7E76B2B4F269D7EULL, 0x6ADD1086F95CE560ULL, 0x8433F51A34FAA8C6ULL, 0xEBFE905F9D3A7434ULL, 
            0x4127585C65603B89ULL, 0x48DC8B5B0BFFC9D2ULL, 0xD4BCA0A8BA69D41AULL, 0x5A90CECDF6B1BAF7ULL, 
            0xC4D2C2AA7CE11D0AULL, 0x6173D33CE2DDF7C4ULL, 0xAA5D032449C24574ULL, 0x50690D5325AF2090ULL, 
            0x1B0A72446721D397ULL, 0x0FB523609793888DULL, 0xC459B63012BC3306ULL, 0xEBF69D982D9DAB8EULL, 
            0xC2754D8C2BAC6FCEULL, 0x86CB257F7D472035ULL, 0x8DDD53A244A4124CULL, 0x7E44B687F4B748A1ULL, 
            0x7B3FCDD54417ADF0ULL, 0xC67EEE2CEED89CD8ULL, 0x778ECE80EABE9809ULL, 0x51A42784E4CA49E2ULL, 
            0x66182CB188DAC075ULL, 0x218251AC7B354535ULL, 0xC70C3903BCDC724FULL, 0x4E3FA088F5AC8DDAULL, 
            0x7CBF3DCEFD692007ULL, 0x68FE52539EF01CADULL, 0x3C23A5A883E69EA6ULL, 0xE214A0813173F801ULL
        },
        {
            0x6FC586CEB69C93A4ULL, 0x8955A3E9EF3AAD3CULL, 0xE14171F464E94226ULL, 0xFE9050F6F61D6FD1ULL, 
            0xB721A001CC834421ULL, 0x35D08184ECB4CC2AULL, 0xB339C1B7F51AD294ULL, 0xD73ABAB38F1BC3B1ULL, 
            0x89F01EE399EDDDB5ULL, 0x50886330FC0391EAULL, 0x58E0E07442E7FE9DULL, 0x8B0C627155D32AADULL, 
            0xCCC9AE84AA7C5257ULL, 0x57ACD01EFF8A1E31ULL, 0x4864A65092664BC2ULL, 0x66C4546332F2034CULL, 
            0x6DA47A5F2FA1AC6BULL, 0x89F94F4C9085EC3FULL, 0xE61B7C7CAB750015ULL, 0x8AF39A9DE4F17F0DULL, 
            0x95C671C6E59BF60FULL, 0x147C9749FC035C31ULL, 0x516B9C7D6CE6EAE2ULL, 0x3B2FF9CA36FCD720ULL, 
            0xCB64FE9AA79E0C0AULL, 0xB63C5E5953B025F8ULL, 0x7871E9D0AD9974F4ULL, 0x26C857BF13209F0AULL, 
            0x58B5FE1BC1CCAEDCULL, 0xC12649D93769B51FULL, 0xC9FEDC5114B41247ULL, 0x82AEF2B6F578D182ULL
        },
        {
            0x7B2FDAE01F194388ULL, 0x2876207B9F9F5585ULL, 0xAA36911212DF68AAULL, 0x9D1F2A126AFDF909ULL, 
            0xDC213A87A99573BEULL, 0x847BA01073BC9F64ULL, 0x115B95643D1F8CC8ULL, 0x6F1830C32D5DE193ULL, 
            0xB9DEFFB41829B925ULL, 0xB2B52967B3EB3DAAULL, 0x163CCCCA1668AA7AULL, 0x90502A7CCB69B904ULL, 
            0x777FE06B8892BAB4ULL, 0x18D73F4AD5F2289FULL, 0x996DB343FBE13D85ULL, 0xE9C0C1F348D3C5C2ULL, 
            0x1213A787208EF7FDULL, 0x853A5CBC07898F41ULL, 0x454A2E4C0C016483ULL, 0x10401A0B959A4E79ULL, 
            0x4AACC255534ED764ULL, 0x67F4F66F406EDAD2ULL, 0xEE460D372F58C1ABULL, 0x21E04C532864A5BCULL, 
            0xBE1CA1F8CD9AB332ULL, 0xFAB05850FF298C78ULL, 0x641588B0C97873A6ULL, 0x0726E92192055E35ULL, 
            0x68B7E75D0FC97E09ULL, 0x5F23101A909D8FCEULL, 0x4DA6AC992D711E2FULL, 0xAAD96588BC0929B1ULL
        }
    },
    {
        {
            0xF992BF78D135A9E7ULL, 0x7F3B20459A5E9A33ULL, 0x3E43E23DBEDF6053ULL, 0x365C3D45B2D7ECA6ULL, 
            0xBB0C153953008C44ULL, 0x1834544D55A8D6F5ULL, 0x49B5FFEEBCF3AC6CULL, 0xB24CDFF15E3D6653ULL, 
            0x22A83F7F2624DF35ULL, 0x3339877FE2A47939ULL, 0xB00C4E1185364009ULL, 0xA2094CC3F6FECAB0ULL, 
            0xCA2CA3068DA2A603ULL, 0x6E09D676BBBCAAD8ULL, 0x4E5B5C4A4C597453ULL, 0x3597E581ADC74A1FULL, 
            0xF1EC9DCBFD074A7FULL, 0x3E0EF2723900FF58ULL, 0x04785AF1D74F9F57ULL, 0xD268DD8CF1CC7332ULL, 
            0xBBF1DAFB2BFB3292ULL, 0xC2D406A5FC3F724FULL, 0xB48BF4261C7E0AE0ULL, 0x663166BF961C4CB6ULL, 
            0x4FE2B4A7BD642128ULL, 0xA238A912AE32E46DULL, 0x879FF5ACED495F20ULL, 0xF83E13677AE80D87ULL, 
            0xE75A3E60801EAEE4ULL, 0x2B5B94BFE652C15BULL, 0x264163F184601819ULL, 0x2F396EC388F709BEULL
        },
        {
            0x6148BC8AA2D117D1ULL, 0x6913ECEE48FD70F0ULL, 0xF74B8A8ACCEA07BAULL, 0xB457472798DB09A4ULL, 
            0xE470019FCDF1C376ULL, 0xEC404D1FE7D641B1ULL, 0xD0F3486D0F0E5223ULL, 0x45CF85B157F05395ULL, 
            0x863A4406F7A93D14ULL, 0x7395F3BA6A469B02ULL, 0xC06F2009982B8B93ULL, 0xBB143350AD12E282ULL, 
            0xB20AA3CA7430B0EDULL, 0xAB9A3C430282BED8ULL, 0xE004999D4CCFD3E7ULL, 0xF2F1D77C0F0ABA52ULL, 
            0x25AEF69404B461D1ULL, 0x5D1003C415E187AAULL, 0x059C708AB27671E8ULL, 0xA6AB1D681F9C3D22ULL, 
            0x3FDEEACDE8512636ULL, 0xA1DA6F87A6D69710ULL, 0x895D60F8E8D123E9ULL, 0x5C0A0DA0478493AEULL, 
            0x8072CCDEF1EA17ADULL, 0x6D73D7BF850C6554ULL, 0x574FAB803EB75C4AULL, 0x707CBD8BF33ECDF1ULL, 
            0x91202C53C296050FULL, 0x64A8A74452A51814ULL, 0xFE0E926DA7639576ULL, 0x7DF3BACFD6B43890ULL
        },
        {
            0x320BCF4E59620360ULL, 0x3509B8171310AE2EULL, 0x2AA354CA8E0AE5CFULL, 0xED749987D912325DULL, 
            0x7348426E0DEF12B5ULL, 0x7806DFCC4A1EA0A1ULL, 0x956EFF13D37F7D65ULL, 0xE7BF531128E7B0B6ULL, 
            0xA8C8722869D9FDF9ULL, 0x4AE623379CAFFE30ULL, 0x376AE1714F8AA0CDULL, 0x687719212C10AD4CULL, 
            0xECEDA4944ED815C4ULL, 0x6DBDC0156EC8D789ULL, 0xE5097E58BDD7CB5FULL, 0x01417832AE29B4ACULL, 
            0xC4BA177B3DAD6059ULL, 0xD3C46733A780CE99ULL, 0x7738F7CB5756E712ULL, 0xA70399004DF2DAD1ULL, 
            0x92A82B8643376121ULL, 0xC4865DEB15DC2C8FULL, 0xB0E33F51649525A4ULL, 0x461CCBF21D8A3AE5ULL, 
            0x6F25FF523D592D31ULL, 0xDEC75219DB4867BBULL, 0x9FE441ED62B5B77EULL, 0x50D48925BD700CCFULL, 
            0xDAD0F8EE38275740ULL, 0xB0C63ABB1CEB9C54ULL, 0x22AE9B5CFF099CADULL, 0x2B1D29E71067FF68ULL
        },
        {
            0x512FDD6AED8D86CDULL, 0x861D797FEF5E0673ULL, 0x0CC6914CA2B0451EULL, 0x45497935790C266DULL, 
            0xEA9BDDE949453B6BULL, 0x18945A1FEC82B6F4ULL, 0x7A1374AA64FBBE26ULL, 0x93BA179A4650E17FULL, 
            0x982F604732A71F4CULL, 0x92A71F09AD62A12CULL, 0x859119B70F5CFDD7ULL, 0x15CA1FF2DEEB0B27ULL, 
            0x05C7223949BDE8A3ULL, 0x2D85ADB310B5158BULL, 0xB0A0421220D6BE0CULL, 0x536CC63E249345ECULL, 
            0xAC6BE1BEA3FE253CULL, 0x35FA23FA1751EC33ULL, 0x28B08C1B8FB3D102ULL, 0x5701E496A3ADA3D9ULL, 
            0xF689A009B259F622ULL, 0xC8EF2C1586DD2A92ULL, 0x6B927AB34C501B19ULL, 0x965742434A747E33ULL, 
            0x9AA069BF96FFE19DULL, 0xF3D000B8D0D5980AULL, 0xDFFD2E02FEFD6E96ULL, 0xF931E3FBF41A1B2AULL, 
            0x92F592948DE509E8ULL, 0x3FD23FA777C50601ULL, 0x9BA7E52E34967363ULL, 0xD5A3DA0709C16DC0ULL
        },
        {
            0xB6FC3ACF43568CFFULL, 0x5739CB5FCEA9DC64ULL, 0x706E5DD58E83A7C1ULL, 0x0C4F09DB7D79A1CAULL, 
            0x9EF04CF291708E41ULL, 0x78ADA2A4797CE128ULL, 0xD8570B611829B47BULL, 0x96FAA3C32AFF84DBULL, 
            0x6B145C2EE935A7BDULL, 0x0D9FD4066EC373ABULL, 0xE608435802FBC86BULL, 0xE4953114B5FC602DULL, 
            0xE3328DBA1BDA8CA0ULL, 0x27BE2290D44E6981ULL, 0xC0A955BF16AC335DULL, 0x798074D6769A8311ULL, 
            0x1B8FF1FD8FE058A9ULL, 0x5D5BFF0E6C0E6430ULL, 0xB23E49EAF0FB7272ULL, 0x2F242453D1453408ULL, 
            0xF03D8F2731C9CCAFULL, 0x17CC079BCE706F0AULL, 0x186F72111B4B4E05ULL, 0x46487438E1938B7DULL, 
            0xF633BF2F9719D5A7ULL, 0x356430B81D94F4F4ULL, 0x5859DAA8F321BDD3ULL, 0x1878F9542BDB682FULL, 
            0x846BEF0D115BF8F7ULL, 0x73418F713BBEC707ULL, 0x908F80211ADA8702ULL, 0x39FCCFAF85F5AC2AULL
        },
        {
            0x9D3C553F4CCA0504ULL, 0xFF43502B94B00AC1ULL, 0x6A55FE8FBE3D96A4ULL, 0xD5AE0DEEDBB6A024ULL, 
            0x3F3D6E859BD16611ULL, 0xC964013FE95640C2ULL, 0x445A951051F3D55AULL, 0xC924F82E2945449FULL, 
            0xD5AE07F6FD1D62E5ULL, 0x37DA77A97147DAAAULL, 0x8C56E1C988A28BC4ULL, 0x8ECB9B5B0AFB7DC3ULL, 
            0x18BA54057B370A05ULL, 0xAD5C6B4F46331B94ULL, 0xC71FAD5CF1129780ULL, 0x4CAAE672DBE5562CULL, 
            0x05B91DA80EC2C8EDULL, 0xF6EAD9381335F122ULL, 0x208572F34D40ACB8ULL, 0xFB643D753177DA74ULL, 
            0xE15AF9282037C555ULL, 0xAC942944CBFBE5CAULL, 0x3A10B325337925C9ULL, 0xA75EDE8016A702EAULL, 
            0x64BF9879254C3872ULL, 0xD2799AA731C87497ULL, 0x7C54D198D8F435EDULL, 0x452A927304678F14ULL, 
            0x1847BAA66A80AE5CULL, 0xCE875CA9410F66F6ULL, 0x065B28913D571C0EULL, 0x268432DEC78372FCULL
        }
    },
    {
        {
            0x268B33C46A365C77ULL, 0xB9BD6D3A1D595C20ULL, 0xE8A553E2DC2B44D1ULL, 0x5E7469111DB31614ULL, 
            0x40440A41C67860BDULL, 0xA9F36F1F598881A6ULL, 0x23DE5CE4E5A2F19EULL, 0x149754834D6E9654ULL, 
            0xFCFCF512E4FB786FULL, 0xC16F0CB029597C51ULL, 0x02CE11CAB766DF58ULL, 0x5218B67EAFFEFB34ULL, 
            0x5B72A2C3C58F3A1EULL, 0x1106AD07E0A04444ULL, 0x1DE60B59DE3800E7ULL, 0x84BADBFA887F9E66ULL, 
            0x2BF4C84BF9FCEE99ULL, 0xE76E0046E16BD75DULL, 0x76EBBBA0BE5DBBD7ULL, 0xEF8AF52F522DFB4AULL, 
            0x9C3493C5C874AAEEULL, 0x3F3E7CFCFD8ADB79ULL, 0xD58DA664119631C9ULL, 0xEE4836A3B24943CDULL, 
            0x8D5BEDCEC2CA099FULL, 0x865AA24E73B3879DULL, 0xB254081B5D607F35ULL, 0x937D83F0A0972582ULL, 
            0x08DEF98C2E7E9434ULL, 0x67E72742CD0AC8B7ULL, 0x1B6E8758CBAD0558ULL, 0x115B0094BD5BBA25ULL
        },
        {
            0xFF602D49D0DC0D9AULL, 0x94019327539020CCULL, 0xC22D77CD0CDBBF10ULL, 0xF0FA4D88E1B6D533ULL, 
            0x75B1A7651A2F77C4ULL, 0x5485CCD1FC631234ULL, 0x79099C5194CD934AULL, 0x238F70514577B7B0ULL, 
            0x8B7818ECEFCE7262ULL, 0xA43F154BB3D750FEULL, 0x90440D4268F1B3EEULL, 0xD6EAA5779C3B3079ULL, 
            0xE2610CEC56F0D49DULL, 0xC184D8913347FF4CULL, 0x7E1E9E1559816065ULL, 0xC42DAFDEAC1E4E0FULL, 
            0xD811886C5D9D1350ULL, 0x92C6A604BA811FB5ULL, 0xCB342F83AE73EEF9ULL, 0x1A70663CACF96380ULL, 
            0x0CFB20F5A4C46447ULL, 0x976078E80159CA59ULL, 0xB56D9A0F12DAD82BULL, 0x75B3DDEAFA7FD886ULL, 
            0x86F851FD263BF08BULL, 0x3CC4427A9A86DB7DULL, 0xAADFE8B6FF3BC9E7ULL, 0xE1CB454213FB9B58ULL, 
            0x3448F59C9D7BA2B6ULL, 0xADE63EB7345E5B47ULL, 0x834F23937EFDAB1BULL, 0x88052FA89DDB15F1ULL
        },
        {
            0xBB2FA36540ECC181ULL, 0x79AD0BF7BB64F7EEULL, 0x61DB7B98DCCE1028ULL, 0x8121ED849ECCA407ULL, 
            0xCCA13C65FC9396D9ULL, 0xE31FB819E4F0A46EULL, 0x50F7E9BB91667D32ULL, 0x13ED6CAB54572B6EULL, 
            0xCD365A27441E988BULL, 0xCEBBFA0D6143B603ULL, 0x6BF0E5ED53A9BF94ULL, 0xC3F41366460D6A7BULL, 
            0x5AB64FBEDAEBB4B0ULL, 0x365473F972A95AA9ULL, 0xFA76504021A6B162ULL, 0xAC16AD5E7A7EAFF6ULL, 
            0xD7C291678AEDF54AULL, 0x621C3B2DD49FB9D0ULL, 0x7BE75EC18ECAB9E9ULL, 0x0EDF75EF28D28D0EULL, 
            0xC7144D81BA2F4041ULL, 0x16B62F72A385F467ULL, 0xD64188E2666DE706ULL, 0x46B9BC5B02C2D9B5ULL, 
            0x01372D2E0C6752ADULL, 0xE9481FE32AD17561ULL, 0xEC1B75849663DB06ULL, 0xB891602C71B500F5ULL, 
            0xA1B39149CA93C8B8ULL, 0xD8B471B4DDEC15EBULL, 0x9DC11DACEB5A4FAEULL, 0x2C70EA15778227FFULL
        },
        {
            0x7C50E088D65986AAULL, 0xF7417B30DF09A42BULL, 0x726002486DF715EFULL, 0x117F48C343940664ULL, 
            0x4EBB1AFA80740EBCULL, 0x524B38AB70F10DC1ULL, 0x62520D1940A6D189ULL, 0xFB6E42892335AEFCULL, 
            0x0944E5156624D41DULL, 0x92E72036590008FDULL, 0x8C40C51BA9F6EAB3ULL, 0x6371F8B10D4D3E78ULL, 
            0x635DCAF13B7FCC11ULL, 0xD41D2C67B0B4A61EULL, 0xCB1BD91AEAC41DABULL, 0xECEE2383DF48E647ULL, 
            0x4A8517DCDD474906ULL, 0xDEC55EC5AA8D7979ULL, 0x519EFA27DA5C35CCULL, 0x0CD91BF8B9F6F40BULL, 
            0xEE6EA59CC8879190ULL, 0x30B09912D8A569C8ULL, 0x8E26A3B28637063CULL, 0x7D302E098B21FB03ULL, 
            0x29ECA56EF5D5A7CAULL, 0x59C5C630BBFD39BDULL, 0x227AEEE41316AC78ULL, 0x3B3F9B800AA763FFULL, 
            0x41EE833990F3B570ULL, 0xF3113A15407AC1C4ULL, 0xBED48DF7C5258121ULL, 0x669DCC30D407FAB5ULL
        },
        {
            0x37104C0F96F52613ULL, 0x60B28C23588C7679ULL, 0x312141BF386B0067ULL, 0x037DA301FF687C53ULL, 
            0x3B99B9255B6D8DC7ULL, 0xEF64663AB17D6098ULL, 0x2EE3CCC4CB5A27AEULL, 0xB0696E50683094AFULL, 
            0x330F5742011EAE83ULL, 0x321991E3A0E46CECULL, 0x59D2657B850C7A57ULL, 0x3C3E2D4C4B1D643FULL, 
            0x6A194AB1D610D64EULL, 0x91378547212D1B52ULL, 0x3FD301A40C4CF90FULL, 0x3E57395045AA12D1ULL, 
            0x7E18322E44524A5FULL, 0x2CC265DBE39F7E88ULL, 0x3FBC173E4F078F1FULL, 0x151E2F1127D7D142ULL, 
            0x4B142B8C5DEA082CULL, 0xF6F6C913AC52D8B2ULL, 0x9EB057532F7AAEA2ULL, 0xAF08D398C5A4B9F0ULL, 
            0xFBE6E431BE0F08FEULL, 0xF1165348E08B029CULL, 0xCD72D1E654AB5377ULL, 0x26F86C741BD161A9ULL, 
            0x4176FD6C854E2D50ULL, 0xDE8ED22B1900FC76ULL, 0xE53306E99BD244D3ULL, 0x564F7A0AF6D0AC40ULL
        },
        {
            0x45F95143D029A91EULL, 0xE65E2AF1620A83B3ULL, 0xCF7E0E1BBDA9799FULL, 0x21CC30C8F54DA870ULL, 
            0x4AE04B405F115C2AULL, 0xEAEF863C22FD4B13ULL, 0x3EFD56A8248DA514ULL, 0xD18CA789D7480D02ULL, 
            0x930002B5A2F77C58ULL, 0x2787D6FA342F0A03ULL, 0x1B5D8608B2F677BBULL, 0x459D23C8615E2A1EULL, 
            0x396C295CB00A68EDULL, 0x441F8D9DC2ABA3CCULL, 0x25D411A368DB79DCULL, 0xFC6AB469049100A7ULL, 
            0x9C7F97768DEAE132ULL, 0xADEB5BF902D4A1A3ULL, 0xBAF9E0502FB323F3ULL, 0xCD1F1F4E4D98F089ULL, 
            0xBB93C1676D631309ULL, 0xD0C864D591D9B29AULL, 0x5077B27BE68100F5ULL, 0xA6BA5FF95A4D446CULL, 
            0x52B48C87685B5D57ULL, 0xBF02B40B8F7D16E2ULL, 0xDE300B775CEB8A5FULL, 0xDCEF9EDF277A95DBULL, 
            0xBEC15AAEE338DB04ULL, 0xD82086AE10BDA34EULL, 0x65A0FC0B41D8EA8EULL, 0x3579E976A9B03849ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseBConstants = {
    0x1AE8A5676826AD6DULL,
    0x914854619AB57D88ULL,
    0x1F6D72946EDE9C14ULL,
    0x1AE8A5676826AD6DULL,
    0x914854619AB57D88ULL,
    0x1F6D72946EDE9C14ULL,
    0x456867889DBD49C9ULL,
    0xA8A25A19CF7FF0C9ULL,
    0x45,
    0xDD,
    0x2C,
    0x3C,
    0xFC,
    0x1B,
    0xF8,
    0x6B
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseCSalts = {
    {
        {
            0xBE55D45CF8A6AFB6ULL, 0xDDA212FFBF3ECCFDULL, 0x92BAD4F49759E84EULL, 0xD2F21BF718AA9F48ULL, 
            0xCDD8A6D02BCEF5F9ULL, 0xD7DDA0EA4A2C77D7ULL, 0x6293CDC86027C610ULL, 0x58C854355D402C8DULL, 
            0x60E07F984AF2FAFDULL, 0xFF546A0A7A5F843BULL, 0x80503480E086E3F0ULL, 0x9790A6B81239295BULL, 
            0x6A2187C4371A1B6BULL, 0x06CC5B0F558C7E50ULL, 0x1AA210F86E124EB2ULL, 0x0ADBB93636B07D22ULL, 
            0x3BBA8CC33CB72EEBULL, 0x523C95E6D9245409ULL, 0x2F7E639B00AEC57EULL, 0x5F0AB647DB78D6F5ULL, 
            0xD1E1FEFE436D6463ULL, 0xD730864138176B1EULL, 0x0DC3C01523227899ULL, 0xF930F489E464DBCAULL, 
            0xE0C38BA17B4EEABEULL, 0xE747EE923886DBD4ULL, 0x576904C353FFAC3BULL, 0x016398EED4AE2102ULL, 
            0x1212C4746FA7101AULL, 0x829CE5FCE4EB835EULL, 0x2CE9EBCD0AB50900ULL, 0xC632804283828750ULL
        },
        {
            0xAB86542996E07380ULL, 0xFC235FFF2DCEE637ULL, 0x007AB81866B9C151ULL, 0x3803B7C7BFB7DB76ULL, 
            0xFD77696B955F58E0ULL, 0x44E9FF88332D1D9DULL, 0xEBBA9573D7F65C46ULL, 0x4D4101999E470855ULL, 
            0xF813BBF9953202F1ULL, 0x2E2AF6462862F118ULL, 0x614D738D09373500ULL, 0x37566AA9BC32634EULL, 
            0x3820E98F2E7A4F75ULL, 0x98CE599F88D4F0C9ULL, 0x6903EE8A8116BAF8ULL, 0xD7A1735579BDDD94ULL, 
            0x3241A41A9D87AF99ULL, 0x740DD43F1C0CCA49ULL, 0xF04E94DBBDEAE1FEULL, 0xD740854B3BF6C289ULL, 
            0x0204A0C72FEF80FEULL, 0x67DA62CCE90482F9ULL, 0x5AE42B08C25E5E39ULL, 0xA80F0A2D470B8E79ULL, 
            0xE8429B3B247595C8ULL, 0x1F9BB6D047A4615FULL, 0xE7A33E8F35E6B6ECULL, 0x2578403528E67A5AULL, 
            0x77193E17AACA5DCDULL, 0x431453B6574CD6E5ULL, 0x3C7C584D47A8F293ULL, 0x0BAFAB76F486A7E6ULL
        },
        {
            0x94223E3F5096E26AULL, 0x82576943E9D21BECULL, 0xECA86C1CB0D73FC4ULL, 0x8C39D567A999B0AFULL, 
            0x033B6A1BC6822E09ULL, 0x129BFA792F717CF5ULL, 0x209971EB51173717ULL, 0x8E4CE15421C6C967ULL, 
            0xAA76455CB1EB4F09ULL, 0xDAA838384670FCC1ULL, 0xD6B35A120470758CULL, 0xB1C6450A46B63A9FULL, 
            0xCBFA87C73A2082D7ULL, 0x92D1A2E55B1ABD96ULL, 0xDF95EB9AAC34CF6DULL, 0xF1F54DDF16DB405AULL, 
            0x1E3AA4F6C03C4D4DULL, 0x22FBC54CF44D74D9ULL, 0x0EB4CB6164E44833ULL, 0x4F54428407EFE69EULL, 
            0xD6F780423B136A50ULL, 0x493A740E814531B1ULL, 0xB7B294D640F6B6EDULL, 0x63E2CE97A26866EAULL, 
            0x8122780AC2DF972AULL, 0x01B103E799E69A14ULL, 0xF79CB2AEC9238C56ULL, 0xB416E7352ADDE1D2ULL, 
            0x54457E0EE156E067ULL, 0x4C67F8581D86BA35ULL, 0x86E00FBCEBA66DCDULL, 0x574FD62BDC72A951ULL
        },
        {
            0x27117F941F4BFE10ULL, 0xC6015A2BE95A2A20ULL, 0xE0566FA9CDC15F93ULL, 0x4ACEB7842149AAFDULL, 
            0x5C955EF4C2E2855CULL, 0xA6C8D3B66A93DDCFULL, 0x7BC7E91BE04CB9BEULL, 0x026B5452E4C3C5A9ULL, 
            0xE679B3799222548DULL, 0x4955BD88AEA73875ULL, 0x1E6D2FC18AE64196ULL, 0x8212247071F13B5AULL, 
            0x0E39E9B14B51290AULL, 0x4FADBF94A323921BULL, 0x522C5D04E81EE751ULL, 0xA9235D74DE649905ULL, 
            0xD8BC591804867846ULL, 0x495C45CD4B9D718BULL, 0x0D7638CB243FE717ULL, 0x912D386FA1B3C23BULL, 
            0x027DAE5B712F11B9ULL, 0x840947CB97F228C5ULL, 0x52C19E65A95618A3ULL, 0x3A845D75557F8EADULL, 
            0xC6148662D3000048ULL, 0x9FF043F62217EBC1ULL, 0xCE382AE85E5772FFULL, 0x6B04A724A1C90141ULL, 
            0x8DDED68677B79C7AULL, 0xE27A614E7ABDAEC7ULL, 0xE78CA87E5E4B0F2BULL, 0x25E9A5186E390BB0ULL
        },
        {
            0x25B8DBBD5E801203ULL, 0x4BB5611BC601B968ULL, 0x57CD0BA9D37620A0ULL, 0xBD3E6067D4B21FC4ULL, 
            0xB38758A41834CF6BULL, 0xA0373D88E11C366EULL, 0x0C582F32BB3FFD85ULL, 0x736EFE6ED687B5A6ULL, 
            0xFF17C4EBCD1E323AULL, 0x3FD27AFD3F9E05BEULL, 0xB212DDFCE8D67B29ULL, 0xF085B3F1CAB49693ULL, 
            0x722639F22D38CD5BULL, 0xF38920B587457B52ULL, 0x1CF67513802424CCULL, 0x20330098B16ED449ULL, 
            0x8390C02931ED842EULL, 0x03F03C65D8A17179ULL, 0x9A66F8AA4981F7D3ULL, 0xFB247527A780F269ULL, 
            0xA32912B5E914BBF9ULL, 0x93F4248383371CD9ULL, 0x2B437F4444469AB6ULL, 0xD3140DC93F5FA6A1ULL, 
            0x310275F4EB9DF70FULL, 0x9A61CAB73276FEE4ULL, 0x53122D4609D8AD2DULL, 0xC4DE58FDAE94318BULL, 
            0xEFDA889F2917F308ULL, 0x97B00B645DA3F619ULL, 0x7185C567BF218911ULL, 0x087DFE2195F40E80ULL
        },
        {
            0xB8F3348CE4D4EF7AULL, 0x9D1D8A1DBFB53D9CULL, 0xB35746B1C388B17FULL, 0x7B407F7064386831ULL, 
            0x30B0489AA8803536ULL, 0x41E4C474FAA79606ULL, 0xFC6702F31B8169F8ULL, 0xC7F4ABBE4044E6EAULL, 
            0xE8F359D4F64F83C4ULL, 0x83C78EC36E94C20AULL, 0x7E8ED0F58A5DBC27ULL, 0x0DB2E8A2DF430D85ULL, 
            0x6E67CB1FC8C646AAULL, 0x64FBADF45F919459ULL, 0xC50A9943AD4BB32DULL, 0x95E57081E1E3EC8DULL, 
            0x136E4E4444E21FD5ULL, 0x504E729631F8757FULL, 0x1550C2C3417686C5ULL, 0x70E956FB7AF6EA70ULL, 
            0x79DC290E42500555ULL, 0x06860E99218C78A7ULL, 0x597D8B4854A6E948ULL, 0xD72F4026E7661563ULL, 
            0xC34C67D320DBE860ULL, 0x11ED37226954F3E2ULL, 0xB28F604875D27A68ULL, 0x9E60E35DD18E75C9ULL, 
            0xA280D8C8CB0EB9DDULL, 0xEBD242466688EB2AULL, 0xE89E57155C35EE0EULL, 0x92815F8FA129E70AULL
        }
    },
    {
        {
            0x9BCF83BD9C065524ULL, 0x207E9522990C144FULL, 0x35B1F3974CFADA14ULL, 0xE43B790EE9CCE507ULL, 
            0xB98EE0B01B0B0026ULL, 0xA912268C303593B0ULL, 0xC6D9A9AEC51D10A4ULL, 0x0F6A2E8CF57E8677ULL, 
            0x5CB2151A33A61DA7ULL, 0x5FB1E431E7470FE2ULL, 0xC82FF942D8DD95DBULL, 0xA700ADB599B3E93FULL, 
            0x50828A2A57E6053CULL, 0x807CC23A6DA31CF3ULL, 0x0F4E0455F831DE54ULL, 0x5D49D2C1C152DB28ULL, 
            0x41E3470C67CECCCEULL, 0xA894E04F0B034638ULL, 0x887C5A95A0ADCE8AULL, 0x98C622974DE647B7ULL, 
            0xB0C83BDBD5250896ULL, 0xCDCD629D1ABC0A72ULL, 0x07891952921D0908ULL, 0xA128536E0F55E9BBULL, 
            0x41BB15FDB739FFA7ULL, 0xAAED3E8E59A306EBULL, 0x7ECBE23123E104D9ULL, 0xE0B78359E408BA4CULL, 
            0x20441D9A8B3B963AULL, 0xDB2A8430D2C284E7ULL, 0xF623F9B9CC11A096ULL, 0x3D815D7F357B7FC9ULL
        },
        {
            0xF3708A5DDB105C27ULL, 0x92747D71A198129FULL, 0xDBDBF71EC806A648ULL, 0x980C0D88BDBDA2ACULL, 
            0xEC0F4AD73620B2EEULL, 0x2BD98A9CBF489D04ULL, 0x5D8B5B23DB3C5F75ULL, 0xEC5405103FFB0842ULL, 
            0x53D4797BB3750EE0ULL, 0x7B40872819ACA89FULL, 0x529C4BC2788C549AULL, 0x8EDB67D2DCFF910DULL, 
            0x701C99FA56BC89C0ULL, 0xC554EDD4FAECCB00ULL, 0x1810FC6D7F0D5029ULL, 0x1A4A99C9231A25F3ULL, 
            0x97805A667FFC11F5ULL, 0xED47960ACC006E7BULL, 0x0AEE9D9FBBC38992ULL, 0xF737C0D1A5038F8AULL, 
            0xFB44CD2157A091C8ULL, 0xF76C14CC7033805BULL, 0xC7D72C4F0968D453ULL, 0xF316701BB3E0B7BCULL, 
            0x9651EA9B5D2FA03BULL, 0x42A913C0FC9658DBULL, 0x1F1EBB00429D628DULL, 0x17EBBCAA520E4834ULL, 
            0x0E8F85D8C27E960FULL, 0x7B8072BDB2E7CADBULL, 0x5D4394FFE4A72777ULL, 0x08C2DB04B40C5367ULL
        },
        {
            0xB72BB0A99294407AULL, 0xB98FCD42D94F28D0ULL, 0xA6D4CB812B3C8016ULL, 0x4C05A0AF39FBD170ULL, 
            0x5739F7ECA102CD21ULL, 0xE84DAEA672F4F3F5ULL, 0xB662145B0C8F806BULL, 0x4359AB027FAA7363ULL, 
            0x80853572AA742F6DULL, 0xF5669EC1EFCA56D5ULL, 0x970FACAE6AA4666EULL, 0x1DD907CC4B1581AAULL, 
            0xEF89F8CB04384C2FULL, 0x2B271D0CE658B66FULL, 0x92CBA4CE6CB7933FULL, 0x83BB42646189D2C4ULL, 
            0xBA939D03AF6A58CBULL, 0x10E7291FB07F9A87ULL, 0x62E7076E094AFDE0ULL, 0xAC5B8492838D96E0ULL, 
            0x7F762E0D759B9D65ULL, 0xC0C34FBBB01CB324ULL, 0xDD0004AEAE77BDC7ULL, 0x86877F342CE62351ULL, 
            0xEC8A598B91044A0EULL, 0xC45EE8725B6875B7ULL, 0x459807C35E33F621ULL, 0x0AA686A319D209DAULL, 
            0xC4CE46C17D41D4B6ULL, 0xB299FF71AF0A31F2ULL, 0x8C27C156C42D2444ULL, 0xC83E964CE94C8DADULL
        },
        {
            0xA1D1641286211E4FULL, 0x35A5BC01C19D973BULL, 0xB89F3CC9AEC7FE4EULL, 0x0E0529AAA1A1CFBFULL, 
            0x2670177192CAA165ULL, 0x1FF3B65C352DB3D9ULL, 0xA6F5318A71F149CCULL, 0x35E9C2517BA7B2C6ULL, 
            0x71C49F3EB48BAE06ULL, 0xB9A5D3A4355F86E8ULL, 0x15FACDC9174F9049ULL, 0x05DA9547F3668F25ULL, 
            0x28CED72D76D35492ULL, 0x494E279899E46BB7ULL, 0x8E9A421B3660B58AULL, 0x38BE861D86D160DBULL, 
            0x1143EE144A74B663ULL, 0x40DA229F02381D4FULL, 0x9ACC3CF523E540DAULL, 0x8604D55ADFFE4DF0ULL, 
            0xA9D3A383D485B4D9ULL, 0xA8FC85094BAC917FULL, 0x28DF01769E74AFB2ULL, 0xD11C6CA191FAF988ULL, 
            0xF52EA6954447FBD8ULL, 0xCF96F93FF73AA553ULL, 0x56347C0E0EE2FE46ULL, 0x7C0C20BDB5AAAB2AULL, 
            0x92C4895811D3697BULL, 0xB5651D5C0F07840BULL, 0x4B4301A631674589ULL, 0x44F5D3FB110EA74AULL
        },
        {
            0x9413C08C3BF10E6EULL, 0xB9ED2CAE4D0D1AEEULL, 0x37C784FAE12BC198ULL, 0xBA9691FB3A7EB6A6ULL, 
            0x0BADE8CEB438D5C4ULL, 0x70400B00B2091186ULL, 0x9ABBAEE1B8D526F5ULL, 0x6E052C1BEF8EFD75ULL, 
            0x3A57F45456C1BB76ULL, 0xAC7CBA3BD5C1DE53ULL, 0x437ACD34FBE07755ULL, 0xC68052AFE415B9CAULL, 
            0x00FDBB02D544ACEAULL, 0x064E304866DBFA53ULL, 0xC583E0E4FE71D1C3ULL, 0x19355B9A3AE9E329ULL, 
            0xDC5F6CA268C03E80ULL, 0xC4B518E769AB2713ULL, 0xFB479823FD66F31CULL, 0x0B18C568A5E51A02ULL, 
            0xA7E4E711A5D91AF0ULL, 0x9A024F6AC5908A78ULL, 0x32A132C7361065CDULL, 0x20CBEEF911AB0F86ULL, 
            0xA2EBDCB434DB0BC9ULL, 0x847927F52DDE144EULL, 0xA8EAA9A2D5C0DCB1ULL, 0x002C27B1F67FE4C5ULL, 
            0xA4AF26FED68C2680ULL, 0x10601766F478992FULL, 0xBA5B7A6482AC132CULL, 0x41E170FB02468000ULL
        },
        {
            0x2274013C64561DBBULL, 0x59B91E12DBCCF210ULL, 0x3B52D6C0A653F517ULL, 0x71AFAFF0D56BD8C8ULL, 
            0x5E6F17F7B5C80674ULL, 0x85AEB22CD906BA4BULL, 0x5A044676F8846D02ULL, 0x8FB60DC1F50F9220ULL, 
            0x5A0A081F15BE5332ULL, 0x075671B80452E45BULL, 0xF9289F64A7948FB5ULL, 0xDDAE2DB1D9BE896CULL, 
            0xB2E6ED809A174E3EULL, 0x8310A5C734878071ULL, 0xF5C3095797392C67ULL, 0x2A504F40AA5CD7EDULL, 
            0xED31DDD8E298F14AULL, 0xF68A52096F090777ULL, 0x48D426172934A48DULL, 0x0EDBC963F542A3B1ULL, 
            0xC29EAE20586CBF29ULL, 0x781FF81E3FE1C423ULL, 0x3BDF225E391B8C4AULL, 0xF062224966573717ULL, 
            0x8712C0E610B9E978ULL, 0x27566F3F813C693EULL, 0xD25125A626A86D53ULL, 0x46E8B0E2FC5F1224ULL, 
            0x27152E4F19B43768ULL, 0xA65CCB8827B4E729ULL, 0xD856706F41BFDB55ULL, 0x58C501B556AF73E9ULL
        }
    },
    {
        {
            0x675FA2CC9E346857ULL, 0x5B8629ECE2D2D923ULL, 0xA9D09BBC3CABD402ULL, 0xAA104C404CC6E874ULL, 
            0x0226E0B9F841E634ULL, 0x97FDA1C1C929A786ULL, 0x19EB672675A0D6E6ULL, 0x15E69D7D3C104D96ULL, 
            0xB0EE9041957DD151ULL, 0xCFC26C42008CB238ULL, 0x5DF4F699EB3002E7ULL, 0xD94BA00F649BD646ULL, 
            0x3AB55D4F7F6C38BBULL, 0x9AE0F4AF4E330315ULL, 0x37F02263913637F8ULL, 0x40C1BEAF29D58E8EULL, 
            0x9BE45702A6721A7CULL, 0x221ACAEFEE2BEF3DULL, 0x5CCDB931E102DB26ULL, 0x15B9991E42FB50D3ULL, 
            0xD534650F142F17CBULL, 0xD0C0F479D8BBAAE5ULL, 0xC1AAB51FEF6E5BB9ULL, 0xF12D7B9BCB8F9AF5ULL, 
            0x111677D58EF481A2ULL, 0x0B0EE7634BADC338ULL, 0xA7F69DDD97D10002ULL, 0xDCF49536486E36A2ULL, 
            0x1BA5BF1055BCB473ULL, 0xCA64636DE7448445ULL, 0xD34FFAC84AC98856ULL, 0xCF8D42F883FED9BBULL
        },
        {
            0xF59E312FDA1CB33EULL, 0x73E5950614DBAFB9ULL, 0x08B45C24265EC284ULL, 0x73815BF2355A0C3CULL, 
            0x3AB62F5F1A9C1AAFULL, 0xCDEB34D689BED80EULL, 0x6C75225FB0C8B011ULL, 0x65E5DF3897344A64ULL, 
            0xAA6CCA050380FCAAULL, 0x75D6F7B6AC084824ULL, 0x16A2A635A333A6B2ULL, 0x39E8DF5EC69922A9ULL, 
            0x5B6387CD8C470AD1ULL, 0x0E9179298573516AULL, 0x53F22B9EFCF31231ULL, 0xB813F51925945075ULL, 
            0xA5B4F818342D9849ULL, 0xFCD393D15EF7D2CEULL, 0x13E7706D9384A50DULL, 0x691823409C7AF435ULL, 
            0x7359A9B2EE59418DULL, 0xBBB6E8BEE26404C3ULL, 0x44C4796E9A266A46ULL, 0xDB8A3124C1CE5B27ULL, 
            0x8E52D6E8018EBF40ULL, 0x57855B79A26785C7ULL, 0x91320E4BCC02892DULL, 0xB4D236F023F46514ULL, 
            0xC6867362ECA70FD5ULL, 0x37F0F487B8041AD8ULL, 0x608F7B95BDDA5BCEULL, 0x56383D646FF97670ULL
        },
        {
            0xC129DCE2CCD5C828ULL, 0x593AA3D648415EE0ULL, 0xA68E6818E05CEC8FULL, 0x9B4D61C787141331ULL, 
            0x5670771F87D1AD3BULL, 0x0EED29B46FAE9C8AULL, 0x5B8AFC6C62004E85ULL, 0x6FB3DF5803940E1CULL, 
            0x5FF53A28F37A470EULL, 0x58FF32CC45B3699AULL, 0xC58FB6372B5771E9ULL, 0x8F1889E859B8EBDEULL, 
            0xF656C251A71F5D24ULL, 0x063A83CE461E2EF2ULL, 0xACFF87D508B411A2ULL, 0xD6ADE20120384012ULL, 
            0x4B6F306E0D3A7405ULL, 0x5AF7FFA78530A9DFULL, 0x0D14806E66F35B1DULL, 0x418EDDE4B3834DEBULL, 
            0x72858E081E5932C0ULL, 0x89368262687206C3ULL, 0x2366CA246F423526ULL, 0x09C46284B032B7DBULL, 
            0x8ACFB1B5B205C405ULL, 0x63B110EC990D94C8ULL, 0xB450F7151954D075ULL, 0x8C2644A0BDCCD25BULL, 
            0x6CE7D63DBA71BC9CULL, 0xCF7A7444C9163CECULL, 0x072001B9F6FEBC1CULL, 0x33CE01E132A3337DULL
        },
        {
            0x17F3AE86BC789D57ULL, 0x36D3544F60389949ULL, 0xD4B17C45E73D1357ULL, 0x4185BBD81D293FE5ULL, 
            0x3D74B05A75CE372BULL, 0x265DBA3D6EADF828ULL, 0x61BA47F34B0BDD56ULL, 0xD9DE29DB865323A2ULL, 
            0x0C2798BBD6CF694AULL, 0x6914308F820DDDDEULL, 0xFC4A7522D8010A10ULL, 0x78B99E174005D26BULL, 
            0x0ECCBB11B757DEB9ULL, 0x66C936E9BBA0591DULL, 0x0397E05C987EDFF2ULL, 0x81D8BAE6E4D9875DULL, 
            0xC339F718F614D2C0ULL, 0xCF67E0E7F77094B0ULL, 0x42838DB7CAA46229ULL, 0xEE8B6A74F945A7ACULL, 
            0xC5FB7069C868B44BULL, 0xE6AAD37B8710D432ULL, 0x4F618E943C08898BULL, 0xDD50CFAAFFEF70EDULL, 
            0xCC88311417481467ULL, 0xAA3BF7E18D551E0DULL, 0x3B9E9696D7354545ULL, 0x00B31B141897DCA6ULL, 
            0xB4DD8EBDA0778E99ULL, 0x5F4FFAD9FA468FC8ULL, 0x93F5C8087384A58CULL, 0xF26A9371B5DF5B23ULL
        },
        {
            0xB8382E33173521F1ULL, 0x17EC01B952D97D03ULL, 0xD9CEC6716DDC22FCULL, 0x29642AE6E288A6DEULL, 
            0x9294B1BB5E73EB62ULL, 0xBDEA3A57B212FF59ULL, 0x204BC31475A4BEEFULL, 0xFE28151CDD68DC07ULL, 
            0x5BC099E6EAC8E86CULL, 0x4578FF5DF6B82375ULL, 0xBD3822442CEB6B2CULL, 0xACAA4C7CAA1EF10DULL, 
            0x49DA35A91A4109B6ULL, 0xD16260F774273228ULL, 0x9736168C9EB3CB07ULL, 0xD18EFDA36B342AC4ULL, 
            0xA99006FD2656834FULL, 0x7BF1AB916397C2A8ULL, 0xCCA3E4203D0B40F8ULL, 0xA90FE2E1D9A9CCD2ULL, 
            0x37B3131D03C14725ULL, 0x45862CC1CB2C77CFULL, 0x9A076DD9556712A3ULL, 0xAE1E742688098846ULL, 
            0x5F5119C32BE788B0ULL, 0x0E90B08C00E68B23ULL, 0xD985CA83707F4968ULL, 0x9268F961E81BB444ULL, 
            0xA6DFD75D251F73ACULL, 0x7CEC1B028CB7A5CFULL, 0x6E9D3780BCC07653ULL, 0x7B79FC291683AD42ULL
        },
        {
            0x1543B2CB5F93705CULL, 0x12A520B37D2716D6ULL, 0x4894951D604D1D70ULL, 0x7C6AC199CC5DBF44ULL, 
            0xBEAAA6A444FCAA00ULL, 0x582F4A388C124D79ULL, 0x0B9BA44D2A057F39ULL, 0xEF1D943DA2B232A6ULL, 
            0xC7022FB00BC52689ULL, 0x17580C4BB62DAFEFULL, 0x0C99FBCEFFAB81EBULL, 0xA123672C8248A253ULL, 
            0x19E2383F0617A31FULL, 0xF9E379C1C2C3B236ULL, 0x4DCF2EF34736465BULL, 0xB1544BBEAEE5EC45ULL, 
            0x6AE865478536A346ULL, 0x881D199C6EDCD6C9ULL, 0xC3820335E2F571DCULL, 0xAA945CE30EBE6AB9ULL, 
            0x1431E3F066E6FC67ULL, 0x6F5EEB76B620F1D8ULL, 0xB6F25DFE19225B1BULL, 0x30F32EB1B97883B6ULL, 
            0x9B8622C64DAF5EE7ULL, 0x40B0E78F0E3839C7ULL, 0xB0B77CFD173459E6ULL, 0x18EF2510279EF2DCULL, 
            0xE1B9ACE46741F91AULL, 0x51DDF30B4CEC0D87ULL, 0xD63534696080752FULL, 0x381EA4A813EE75CAULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseCConstants = {
    0xC41B73B687E4912FULL,
    0x101AECE2D348EE27ULL,
    0x11E91796EDB4942EULL,
    0xC41B73B687E4912FULL,
    0x101AECE2D348EE27ULL,
    0x11E91796EDB4942EULL,
    0x862B51E59EA997DBULL,
    0x849D4CA774A53DA9ULL,
    0x26,
    0x34,
    0x8F,
    0xE4,
    0xE2,
    0x21,
    0xC1,
    0x46
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseDSalts = {
    {
        {
            0x02025BD3EFBD341EULL, 0x92CA0143F9277467ULL, 0x3EF94031749E2A38ULL, 0x2E9D95C9026E0040ULL, 
            0x0B09CC6E9DEECEC4ULL, 0x146A030E4AAD1CA3ULL, 0x33179B6BF4D17A58ULL, 0xCB21CBF60FBD3EA2ULL, 
            0x02FFF4E47C5D5DA2ULL, 0x3C08C5E58DC54A20ULL, 0x33DBE21774490A8DULL, 0x4102B42FD1C3956DULL, 
            0x8CA95CCA5CB792A6ULL, 0x74EDFFB86FC543FCULL, 0x05A4CABE61587BF6ULL, 0x085983731797FBF2ULL, 
            0x04BDDC54038D8203ULL, 0x574C671E7947D9F0ULL, 0x6D0D472A43AA57B7ULL, 0xD0203861484B3A20ULL, 
            0xE8A188DECC2BB2C4ULL, 0xE4D00F959A622B3CULL, 0x635626618EDB7922ULL, 0xB52F906311820CCDULL, 
            0x2C758B52E232264DULL, 0x699EC798F1428ECEULL, 0x4EADAF9B14E65C82ULL, 0xE3B0A44FA8BC87CAULL, 
            0x59DE2D5166DC9CF9ULL, 0xC248D4966A7A56C5ULL, 0x9AE6CC69A093E663ULL, 0xEE58800BF2F39806ULL
        },
        {
            0x2F33ED2DEE9A7975ULL, 0x1CFD176C4238ED7CULL, 0x6D0CE500D1418320ULL, 0xB45E0EB518426051ULL, 
            0xCA5F3C032D545534ULL, 0xAAAEA001CD52544CULL, 0x43F6FB22B7A23F59ULL, 0x677E9D2664E45B18ULL, 
            0x1725ABC8244625EDULL, 0x866926E8BF321699ULL, 0x20DFCF379822C582ULL, 0x36A58FAC00170F9FULL, 
            0xF6C3387BFB7A0AA4ULL, 0xB6619E0359330853ULL, 0xACE91BE69E358B2CULL, 0x08D4A55608B1AD7EULL, 
            0xB22937986E97990FULL, 0x04BA8AF6E56F3F4FULL, 0xE47305C7DC44F822ULL, 0x2FCF60A3F136A62AULL, 
            0x366578A322712F3FULL, 0xCEBC9461F481D1F2ULL, 0xC9073F5DBC1EB4B7ULL, 0xDCDAD539091A7CD8ULL, 
            0x0ACFF68C7A175F7EULL, 0x0D5F07E854FF4BBCULL, 0x3CFEE464A2AD8475ULL, 0x556C7A4080257158ULL, 
            0xE63BD84BFD56B4F6ULL, 0x767810CA9B0C414FULL, 0xA2F67746C1207452ULL, 0x8B603F2D54CF5D3EULL
        },
        {
            0x7FB9B06E69724896ULL, 0x38EF5606FEA7650EULL, 0x893CCA03132C62D5ULL, 0x7EFB660F70F29543ULL, 
            0xA532F3A5C02FDC9BULL, 0x987EC5A8DF4B2673ULL, 0x04F8F5CA0C48B891ULL, 0x7BF2A4DE26F2C442ULL, 
            0x1281EA31AD1D77FCULL, 0x140E0784B0218CD4ULL, 0xCF70F90F78D8528FULL, 0xC2FABC069F9EF72EULL, 
            0x5BFBC6EDBF9267B3ULL, 0x202E64A499ABE9D0ULL, 0x354916B10B00EE85ULL, 0xC36937EB6C50BDA6ULL, 
            0xB6B7CCAB054F4D44ULL, 0xEFBDF7158A8FA030ULL, 0xBC937A73471F8BD2ULL, 0x17E69472E222BDAEULL, 
            0x06E30D8ED3CA33DEULL, 0xBE344DEC4DB61556ULL, 0xDB9403CE8B927AE7ULL, 0x797A5C09BC660D77ULL, 
            0xA5B9AAC3E3DA9F6AULL, 0x64CF71075DB5BFC7ULL, 0x7EB9F82C8607DE5BULL, 0x2990B3E954437DD8ULL, 
            0x26AA158118B69642ULL, 0xA542931A848B7E38ULL, 0x9A4F9B24315AB596ULL, 0x607AFA9D0E5E7E1FULL
        },
        {
            0x497B060FE4F7C589ULL, 0xFD3D00C22D72A632ULL, 0xB7A6EA48334F09DFULL, 0x7DF3E8EA1CB1C1D5ULL, 
            0x41C7EF7D9D5FE4C0ULL, 0x5C638FA6228673AEULL, 0x74CBB37A64795DCFULL, 0xD7D385D74F3A4924ULL, 
            0x48D41C6801DDECEBULL, 0x2D023000CF53A4A8ULL, 0xE76E0230CC03C0B2ULL, 0x245E0E1262F9B3EDULL, 
            0xC2E04E296C2E8CD7ULL, 0xBD3E60BD4702798AULL, 0xF38DBA25FE94F25CULL, 0xC324A3FB8E5E82BEULL, 
            0xF1C11AAB823A438CULL, 0x3988A5E2A88BB6F6ULL, 0xB8D61579FEB97FE9ULL, 0xB44CC8AAD1348316ULL, 
            0xD0FF98C8ECFB4936ULL, 0x0856E6C5D61CF21EULL, 0x9B006FAE926F5420ULL, 0x42F9BB089C8871C9ULL, 
            0xB1E2230500653CDFULL, 0xD2B7348D657EBAE2ULL, 0xD066322A8870282AULL, 0x66BFD23B6BAFD9FBULL, 
            0xEC01F5C9B387C5A3ULL, 0x523461EF40A1D1E9ULL, 0x9B811F7D0A668A79ULL, 0x97683FB2C4A3495AULL
        },
        {
            0xF7E35CE6D75B9E8DULL, 0x933B41715677BF72ULL, 0x37B3B411AC08AE69ULL, 0x5B9AB98A3F0DAF53ULL, 
            0x80E3B41988B5889AULL, 0xDF4692442781887BULL, 0xEDDFDD8CA4B0EC23ULL, 0x47C467253B60B447ULL, 
            0x77622507830F1C14ULL, 0xBD199C1D571A328FULL, 0xC35A2232266D7AE6ULL, 0x975E1FBA9BDC5CF9ULL, 
            0x13F9B2210EC89CB0ULL, 0x78169579237F2E80ULL, 0x6240815F4FE54AD9ULL, 0xFDFEA57E5516E96EULL, 
            0x233E3ABE39B6AD9AULL, 0x08EA504E755D32DBULL, 0xA428A5937BC01A2EULL, 0x934CCF5210F7E38AULL, 
            0x89319C189F090C8BULL, 0x05F891A2F3915F41ULL, 0x08E7D3DDC79049AAULL, 0x115CE2DFF808E83AULL, 
            0x373B1ECE1DA7158AULL, 0x6B808D2D1E37E4D7ULL, 0xA17F1B6035FFBD1EULL, 0x44E9CBC1682EC932ULL, 
            0xF7093FB1F41E3801ULL, 0x91EF32EF9ED6072EULL, 0x962258210E15CFEFULL, 0xB218D89EA2D1D9E3ULL
        },
        {
            0x8097D7C976B37CFFULL, 0x608F6AF75EFB4B7BULL, 0x6EA644FB41B3E2C6ULL, 0xCAC91C8E52E81545ULL, 
            0xDEA47D2F67F472BEULL, 0xA75BDD5F7E4FC0C9ULL, 0xB41304D049496FBDULL, 0x7C8553B68E1C0DF5ULL, 
            0x5EB83E0DEAA040B7ULL, 0xD524DB81418A5510ULL, 0xB3D0D45301490063ULL, 0x39E4625BEBADD75DULL, 
            0xAA3D8FBB9FEAD3B9ULL, 0xD8BC5830C1B33255ULL, 0xD46786707AE2CD96ULL, 0x500331C06C0F082FULL, 
            0x8DA2C79B53FB8895ULL, 0x06BC5AA0CE4548BCULL, 0x3926355F3D873399ULL, 0x24245ECE74110EA9ULL, 
            0x17EECE17AD02937CULL, 0x3EB8D4FC4233AB12ULL, 0x19A67E22635C2196ULL, 0xC892BDBAE94C8584ULL, 
            0x18C930E12F5811A7ULL, 0x5E682C9A302D97CEULL, 0x4BC48136F294F686ULL, 0x15155CC5290A7D89ULL, 
            0x671C4722D07386F2ULL, 0x6F99695EBC61FBA0ULL, 0x0ADA623CE175876EULL, 0x885BEAAB5C5C1A3BULL
        }
    },
    {
        {
            0x67D8658AE1709BF0ULL, 0xD5E584B3515DA444ULL, 0x1854B9EF51288DB4ULL, 0x33F3B67306DCEA5DULL, 
            0x7084E4383990C47AULL, 0x01EADBEBB4FB80CFULL, 0xD86C9F1C1301DFB4ULL, 0xE87C9D46B2391DC5ULL, 
            0x0BB03486CA47646EULL, 0x15A2736E4716000FULL, 0x320EDB8AF760D84EULL, 0xF7ADF48A705297F7ULL, 
            0xDF38DC5FCF516DB3ULL, 0x03F174569688BAC8ULL, 0x1C842349B8484840ULL, 0x7F3D0F04791B7D1EULL, 
            0xB9091F0EE7B867CFULL, 0xDAF24CA287ABAB3CULL, 0x9267F24B68A433B6ULL, 0xC4C13D10B4F3BA64ULL, 
            0xA2D8DB1178E4A36FULL, 0xEED158263E73822BULL, 0x9D6C8D38D4B67F26ULL, 0x4BAF18382FB9E22EULL, 
            0x610C1E02173CFCCEULL, 0xFC37442DFBE85796ULL, 0xA38008DE3158251AULL, 0x6A3FE6298EADBD74ULL, 
            0xBD75EF2D62CB3FE2ULL, 0x77FB795485D6CD40ULL, 0xDA6C714753E974EDULL, 0x5B4D735A3798C0F7ULL
        },
        {
            0x2FA726F8922D8A09ULL, 0x81969ABD467CE64CULL, 0x1577177CF78C6668ULL, 0x61CF70A82DEB3785ULL, 
            0xCA190C8DDE68FEA6ULL, 0xFAF4EE8145A5424CULL, 0x421C48CB5633CCE2ULL, 0x6F57733A1C65368CULL, 
            0x0F353F511F4CD991ULL, 0x824D2494E3ADDA2CULL, 0xF343B8334ED43E37ULL, 0xB729C45258C0374CULL, 
            0x96B135E6A7D3EC37ULL, 0x355A77AA8C0479A4ULL, 0xE0CB8058A839B104ULL, 0x45856060723871F4ULL, 
            0x312F248435F4A77AULL, 0xA921EB65C6C9924CULL, 0x3E0EA0CDCA09F3D4ULL, 0x76C53611249328D3ULL, 
            0xF7A7AA3E64888FCFULL, 0xD5F30F7A33EC4472ULL, 0x2C251396DB3DDAB1ULL, 0x230B3AAAC348AC45ULL, 
            0x609FCB83F4834D9BULL, 0x4BD7B0DFD117A887ULL, 0xD61FE10FA8090CD3ULL, 0x24AB16B0FE1F019CULL, 
            0x9D7701F42B4ABFEEULL, 0xADF9BA32E9370095ULL, 0x3FC9E59027ED6052ULL, 0xC6269B5E702EC66FULL
        },
        {
            0x1D6951264E891086ULL, 0xDEB1EA9306D804DDULL, 0xC557C93BA0C75679ULL, 0x7901561BDE6DD3F8ULL, 
            0x40629701FA3C7944ULL, 0x4E1505C9F23F76BAULL, 0xBD7956FA831B8FF2ULL, 0xD7121A9C5C773536ULL, 
            0x8D9793E113BDB94FULL, 0xB976AD2068B6E3D5ULL, 0x2D8F6426F4811036ULL, 0xC10B3FACC9ED9178ULL, 
            0x68BF24FD9979CA87ULL, 0x01212F4E86CDE344ULL, 0xCD2EA4CCAB72ABF4ULL, 0x640037124FC74BD8ULL, 
            0x8FE8D3F39CEE2C6CULL, 0xBA031316378A39CAULL, 0xEA413989192DECE6ULL, 0xC83577D791689AA1ULL, 
            0xB8BCF1FD4B75D304ULL, 0xF3D75E922D569770ULL, 0xCBEA4735B11D77B5ULL, 0x9C5F1E545ACB2B53ULL, 
            0x02C961B45FC8C573ULL, 0xEB630A00B342E7EDULL, 0x402522DED7E14AE9ULL, 0xBE73ACB9A0474126ULL, 
            0xD7C098A3552CB644ULL, 0xA28CD80500BCF938ULL, 0x58DDD4DFD4E9509AULL, 0x92D93669C67D4BBDULL
        },
        {
            0x6B1D1FC528383F52ULL, 0x52BE3CD73AEFB451ULL, 0x615B04EC5CAFBE3FULL, 0x17C76AFD61BF429DULL, 
            0x3551C53E7C284907ULL, 0x0F5794C208B0B9EFULL, 0x82FCC43C9EBA6688ULL, 0x70D102D3CABC6F94ULL, 
            0x2254C575EC986298ULL, 0xE51A1FE872428655ULL, 0x53C05714F6CF202EULL, 0x5B76B42B7EDC16BFULL, 
            0x0D50036616A2385FULL, 0xB42EABE99552EACFULL, 0x578AF64C77727329ULL, 0x6905071C1DF41279ULL, 
            0xFEA18F62F958E8C3ULL, 0x9040E87766F30D85ULL, 0xA090893FDC9D1DE4ULL, 0x24B1ABD398C33C68ULL, 
            0xDF5BEB816A13433CULL, 0x67CCF4F72A856F41ULL, 0x2291F85F81BB6AB9ULL, 0x909B042204454C83ULL, 
            0x7434034A61DF6DC9ULL, 0xBE2C4B526C412C04ULL, 0x101BE8386889D3A8ULL, 0x297732D34F498E10ULL, 
            0x57CA9475699BB5B3ULL, 0x5616152AB9F3359AULL, 0x763CC983938012A8ULL, 0x978883504DECBBB4ULL
        },
        {
            0x48071C2385AE61D9ULL, 0xA004869BD0C6D5A9ULL, 0x4225C22471023501ULL, 0x96E08CFD1FEDAA99ULL, 
            0xB4A60C459646FE88ULL, 0x8BFC71096BC9F431ULL, 0x75D8BC29CF5F92A3ULL, 0x554DFEA1A1A7E2D7ULL, 
            0xFDE33DF0BF9A917BULL, 0x8162437F736FE0C0ULL, 0x203F7BDC3D8D66F6ULL, 0xBE8D1176FF3F0E1CULL, 
            0x603138F99E406FB4ULL, 0xC862B72BFA2E5659ULL, 0x8C429132D17E7833ULL, 0xA63E1484AEAF8301ULL, 
            0x919FD3D93CEF1939ULL, 0x89BBF7078D0B122AULL, 0x878ABEF2B0A5B13EULL, 0x08DA36446D46C568ULL, 
            0xBCBEC1C48ECFC84FULL, 0x6619FC699B71C873ULL, 0x9DCF1FB9E508B301ULL, 0x007A6A8D5BE62CC5ULL, 
            0xEEBC7BA7F96C445DULL, 0x92477BE371431E26ULL, 0x99F76CC33AC369A2ULL, 0x887F930684670C00ULL, 
            0x3CD20341882C7A9DULL, 0xE1C075913F120CACULL, 0xB962A1AFB6B97FE2ULL, 0x596122DFDCA43361ULL
        },
        {
            0x962A9FE08D718DBCULL, 0x7E25AD74DA7363FAULL, 0x6BE398769221CBB7ULL, 0xB166922C8DFCBBB4ULL, 
            0x294B26C3BB2C6976ULL, 0x9F0C34D99093B3EDULL, 0xE696E7236D26BBDEULL, 0xAC9B2EB5EF34EEFDULL, 
            0xDFD7EFA58035B558ULL, 0x61F011DE04B1AD40ULL, 0x6D7A0F428AC8C175ULL, 0x7A6BF6ED98B9923DULL, 
            0x4501D93AFE67C17AULL, 0x6EBA949888E5D309ULL, 0xEB529C35E85B4FF4ULL, 0x5198013D42A8E5D1ULL, 
            0x11C25AC755B0F589ULL, 0x0A9AC6422C71A162ULL, 0xBA689E8FBF6D27D1ULL, 0xA346EE3836EB530EULL, 
            0x28A7C4D5EBB35528ULL, 0x00C181E4268D9E72ULL, 0x9A0868008BE8203EULL, 0x7CB947201AD5BEE9ULL, 
            0x6D12F9DDF19DB6F2ULL, 0x9B8BCDCA008B8A19ULL, 0xE2109E2D6D021B24ULL, 0xDAD112DE63FED3AFULL, 
            0xE0D6D183447AB5A3ULL, 0x9361A00B06FFF4DFULL, 0x5CD6BF28D547A240ULL, 0xED3A4F30EBC8A7D2ULL
        }
    },
    {
        {
            0x6CF952084F7D5D9DULL, 0xFFC99E69D23DDE8EULL, 0x39457D2370576B69ULL, 0x1C3F7E4A213B8A68ULL, 
            0x8BAF3E74B47C6CF9ULL, 0xA2D248339A08B982ULL, 0x6A23A7F0002308C1ULL, 0xA8F8929BA60099F2ULL, 
            0x5EBD06A85981DBD0ULL, 0xDE986ED754A3B929ULL, 0x4043C81CFDA6E3FAULL, 0x0A27CC6D605D2A4DULL, 
            0xC0372EA03AD1D546ULL, 0x68BFD1EC78795200ULL, 0x6F6A4CE45372AEB3ULL, 0xE02EBA93CC7F6E60ULL, 
            0x0D63F2D6CE8C5E05ULL, 0xB2DD47159196FDBFULL, 0x90FB776B028E8857ULL, 0xB31392EC44F6A015ULL, 
            0xBDE1222280EDE566ULL, 0x595AC4A67DCB64B4ULL, 0x688F5516121897FEULL, 0x725154329D043467ULL, 
            0x26C800818EA70A5FULL, 0x4E16E45DDE8BFE1EULL, 0x6C03F6A36DAD775CULL, 0x0269DC08E21A764DULL, 
            0x973933F127E49406ULL, 0x05E9C9353AAAD9C3ULL, 0x9E9A7BFE442D9CB5ULL, 0xC3BBFE16CBDEA06AULL
        },
        {
            0x82C811C7ACA471C0ULL, 0xB1F48CB03764C4EFULL, 0xC291ABDA40A65282ULL, 0xDA045CA024D2DF53ULL, 
            0x6C46A0E9F4E4F2E4ULL, 0x7B5B55C3ED862DA6ULL, 0x9FE7F6C1C9A8CBBAULL, 0xD955CA0D68580250ULL, 
            0xBA57BCD83965A27CULL, 0x4DCAB71B4A20B8BDULL, 0x55DFEE00C9382CC4ULL, 0xFCD9E0EE0781B623ULL, 
            0xA3276539A50F5482ULL, 0xC7119AE479C196F9ULL, 0xE73AC4BCBAEA5E5FULL, 0x07769A6E6DEAE346ULL, 
            0xEBBBD70E717BAA09ULL, 0xCC1E7A2DA55DC5C9ULL, 0x1C2BC925551CE53CULL, 0xF8B911A53B01FF93ULL, 
            0x5E21CDE285D2C199ULL, 0x880C9CE428D71F4EULL, 0x683B501C2398E1E7ULL, 0x8185AE647E53BA86ULL, 
            0x9F76F8777B2B24E0ULL, 0x0A78958D764FBEE4ULL, 0xFBE91EBB96B435F9ULL, 0x2B4AAFC5AF7EB14EULL, 
            0x2CE4C9BF8054D0B9ULL, 0x09776336AB58ECE6ULL, 0xB20053332ACC8A74ULL, 0xF590FA7C2207EC7DULL
        },
        {
            0xC9D5801282FD460BULL, 0x6951A61C7A43EEA5ULL, 0x91604C8C8274D032ULL, 0xF998932998E84047ULL, 
            0xEE21EF67D8C9BFFDULL, 0xD1382B602EBFBA85ULL, 0xCD97A47070E9192DULL, 0xF29A906DADCEDB58ULL, 
            0x8615630C7889819EULL, 0x4AC81FFC87DCA9CAULL, 0x451276326DF5FEB5ULL, 0xFFE87DF7B733D212ULL, 
            0x317C1366FB70E1EDULL, 0x80A8CC9E2C7847ECULL, 0xDDF5ED1E160F2AEBULL, 0x64044E6D504A82D9ULL, 
            0x28529A603118533AULL, 0xC92E79BCCEE41DA8ULL, 0xD58FFAC1712052CAULL, 0xDFF98044990F077AULL, 
            0x1BE0B49C69B8AA67ULL, 0xC961B28C9C3038B8ULL, 0x16895043AF741804ULL, 0x8253BE2043662B95ULL, 
            0xA52E50DB511E7B77ULL, 0xAC57AA7FE407B7A0ULL, 0x20A9687F74511657ULL, 0xCB672E040A6EF3F4ULL, 
            0x04B7C1F685B3E489ULL, 0xF175256F3FA6B345ULL, 0x42C1E242018FDEC6ULL, 0x78A719429F5E1B75ULL
        },
        {
            0xD618A6F4CB0FEBB9ULL, 0x63A77D3CB4F8FCEDULL, 0x3C157C29C0A2047CULL, 0x19B8C0DF3F048595ULL, 
            0x5964D7C82DB71168ULL, 0x2F4E7903304707EBULL, 0x387D6049BB07E03BULL, 0x1C99A2E0F93374CAULL, 
            0xB1C9412AE54B7D5AULL, 0xD75184B50982D08DULL, 0xD5B824185165AFE1ULL, 0xE55C7B79E6A0E621ULL, 
            0x5088FC8A8E19630AULL, 0xF859CBAF0779FA9BULL, 0x3AA6C5AEE96F6D11ULL, 0x885CE7D86E41064DULL, 
            0x159CB0C869254EB6ULL, 0x5B1122486CCB80ABULL, 0xFE8CB97C3BDB7E1EULL, 0x12971998C9DDC7F0ULL, 
            0x7C2C2FA6200B7CB3ULL, 0xF64BDE8AC8B865FBULL, 0x2B2BC779F77A7644ULL, 0x8E8636FB36882CD8ULL, 
            0x253232F81D6BE40DULL, 0xA590F9B7B4F3CDF0ULL, 0x8B3A353B3BADF0BFULL, 0x12D69E95B0DAE651ULL, 
            0x0067C3E624F066B1ULL, 0xC10630834A7B4B9CULL, 0x273B615F5FF7EE9AULL, 0x98AEE21630EA9AC1ULL
        },
        {
            0xEB6615DD8A31364EULL, 0x163ACFC2301EF014ULL, 0xA45AF06FD82F11ECULL, 0x2B4268F870E5A6F8ULL, 
            0xAC818F5235704521ULL, 0xE43F86796B7F035DULL, 0xECED0B157F1A20C6ULL, 0x6EF8AA933ED6DCD7ULL, 
            0x8B0D3DB6369201ACULL, 0x35AB546ECC9B7A07ULL, 0x928D1E09D892E2E5ULL, 0xBAEE8AFA47FA0FBFULL, 
            0x544CAEC747F3EFF3ULL, 0xF88B0AE0DCA7713AULL, 0x4F006F755E5F359AULL, 0x5D3621D09C33B61DULL, 
            0x0381BA6BD679E066ULL, 0x0024BEE3AE7B317DULL, 0xC7826EFBF10D0E3EULL, 0xC2B7898A5D3808B7ULL, 
            0x424482C2CF52219EULL, 0x65A309A37D996B53ULL, 0x899822509FEB354CULL, 0x7BC247D1CD08C172ULL, 
            0x3D4D63AF0A9592BEULL, 0xA26F0A58E2D7BDDCULL, 0xCF496B42C171B763ULL, 0x1CE00BDEF454FA37ULL, 
            0x75832DE61EF9D804ULL, 0x5A74039C8E4C5CC9ULL, 0xDDF96AAC0676E605ULL, 0xD70A60B533CD6D18ULL
        },
        {
            0x6833F088A9800A7EULL, 0xD4E7751973BEDDFDULL, 0xB78F776D06BE7473ULL, 0x2C6BC73ADECEDDDAULL, 
            0x1149D6FDE7F02ADAULL, 0x719F76A955B15A03ULL, 0xC781483F9C935685ULL, 0xA4EFED3E3BE679C4ULL, 
            0x166A158CF6C6F543ULL, 0x9B7FB526BD72A05AULL, 0xE1755D81889A4D35ULL, 0x23D2B40C5337DD85ULL, 
            0x37D7FC09EFDA8CABULL, 0x828FC61F2E5DBE21ULL, 0xE4724CE7B4E860C9ULL, 0x8949049E6232549EULL, 
            0xD0FAB6F749F93F49ULL, 0x4695D5153873570AULL, 0xBA7A98086137129DULL, 0x49BF18EE2F5ABE37ULL, 
            0x64CF015E03243818ULL, 0x793C352456FA5CC0ULL, 0x573BDFBFF40990CBULL, 0x70FE909D497C0284ULL, 
            0x24AF0C7D121F965FULL, 0xE7D7897ABE8DBF5DULL, 0x7E68F65DDC183C89ULL, 0x11D1C892253C53D2ULL, 
            0xC6E5AF48138A5F87ULL, 0xF9575C54364AB166ULL, 0xB9ABAF69F54BF4B2ULL, 0x3B33356D415DF18EULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseDConstants = {
    0xD9562D0889FE924DULL,
    0xD4C3B51876FF3ABAULL,
    0x3905057D54B18344ULL,
    0xD9562D0889FE924DULL,
    0xD4C3B51876FF3ABAULL,
    0x3905057D54B18344ULL,
    0xFFF42430AB6656CBULL,
    0xD64B2C34FDA91470ULL,
    0x01,
    0x9B,
    0x6B,
    0x6B,
    0x26,
    0x58,
    0xCC,
    0x70
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseESalts = {
    {
        {
            0x052E9D7EE447B5D7ULL, 0x264AE75438A2D0A3ULL, 0xAAF753A2E6988CA0ULL, 0x9C512959EBBA7ABBULL, 
            0xF12CAEC0D40B0732ULL, 0x0B8BBD555FD47F58ULL, 0xDC1E846A6727D891ULL, 0xDECD53A936F67920ULL, 
            0x05281458852909B2ULL, 0xA51039B5C9BBEEFCULL, 0xC543607EB39C519EULL, 0xC87A42E24D560797ULL, 
            0x8EECE7C3650CB7CEULL, 0x1B5DCBFE74F1916DULL, 0xB9913E830112BE3BULL, 0xA7CD7476F640A440ULL, 
            0xD7F3D8EF72E5BC84ULL, 0xF7C4F8C665DEBFACULL, 0xD7C7F05E7D087C39ULL, 0x920EED1DD5DFF9D0ULL, 
            0x2F98EE4E39CEFFCDULL, 0x4E4409E2815FE4E3ULL, 0x87C9DF43DF4C04CAULL, 0x2EC3C698F9B7E3C3ULL, 
            0x13C884DC0ADECC44ULL, 0xFAD385D5F7C8F84FULL, 0x0B8B54225F0933BAULL, 0x2F45CF764A237782ULL, 
            0x338E3452F31BF3DFULL, 0x63098BD57E3804EDULL, 0x0E8FC9AEAAB0F4DEULL, 0xFC22DBF8403CA3EFULL
        },
        {
            0x8D04213D60FE14B4ULL, 0x914E6FB3B0AFD4B2ULL, 0x64AD8780469860A8ULL, 0x5D2152EF3834BAC7ULL, 
            0x630A6C44C9E335A0ULL, 0xBE3552DF4844FF63ULL, 0x9A149FAACC27DAF5ULL, 0xB59467B8F0C183ADULL, 
            0x9671F5F6CFFFB494ULL, 0xF83620CE74194A4EULL, 0xC96BF724F197B2BAULL, 0x426DE8D7731CE3CEULL, 
            0x1E50F235784F9893ULL, 0x406D2CAB03DCD46AULL, 0xC087CC773053DB50ULL, 0x88D0A83AA327239FULL, 
            0x8F2D482E50CD62BEULL, 0x62E8EED5A95535DAULL, 0x1884427F3BDDCA4AULL, 0x4D6C5567415685DDULL, 
            0x1534A5F41771AD2EULL, 0xBBF38B4B4F9890D1ULL, 0x0A4BC43E5CBE94EDULL, 0x2F2CEAF9485AA3EFULL, 
            0xD3300707AB225B94ULL, 0x91076E329F730FA7ULL, 0x8628074C4A5F523AULL, 0xCAA8289A9126D69AULL, 
            0x185540B15BC9638AULL, 0xAEBBC29C10E50AFAULL, 0x70B3EB3BA5DE6393ULL, 0x19F80863383C2EDCULL
        },
        {
            0x6CF8ADEB7450592EULL, 0x7B1890BCFF2379EEULL, 0x19FBEBE0F4881459ULL, 0x2B1F279474E4ECA8ULL, 
            0x1E78D8E00A99845FULL, 0x07CC477DAF211851ULL, 0x20D25E10B39F10DEULL, 0x1B4C6841D8009371ULL, 
            0x3854784D729C9843ULL, 0x62B6BE3F5E15BA67ULL, 0x19BDEB478C72B7D7ULL, 0x6EA3399D3C1EFAA1ULL, 
            0x8E9C0FB6CB4AFF87ULL, 0x5CC066C29FB57924ULL, 0x3A6EF3D6ECD9EFE9ULL, 0xFFDA4F34C5FCEA0CULL, 
            0x3A25ACB44DBF934FULL, 0x79539E30B8BAAE87ULL, 0x45DF7BF3ED89A83FULL, 0x506560F5F29070A2ULL, 
            0x4435933E9729616CULL, 0x15ABD913AE9E0217ULL, 0x6E5F75AC34005469ULL, 0xE30F1B18681DFAF5ULL, 
            0x5EFB1E093B67EA5FULL, 0x3CDA6FD5BBEDDB44ULL, 0xD9D5865C158146E3ULL, 0xD5D07FA216CB2D04ULL, 
            0x06C122583D25DFBDULL, 0xC1DC63726779199EULL, 0x8C7A09F596990FADULL, 0x9D2C2AE97CBC73F7ULL
        },
        {
            0x46FE72880A709D0DULL, 0xFD76B69EFBCF6054ULL, 0x528F38A8514788C7ULL, 0x71961DAD4B1F8EF3ULL, 
            0xB7F275AA0A83E383ULL, 0x3F004D3F1A1FBC11ULL, 0xE19CF6CD2F1CA3FDULL, 0xB357588671573331ULL, 
            0x83D23B199E0026F9ULL, 0x5AC6C40B56A3B073ULL, 0xC202A7FCED2D3B6CULL, 0xA94D3762E76773D4ULL, 
            0xE86D019BDB1CAC86ULL, 0x69BA43840D92205AULL, 0x231B73FBB9C6D11CULL, 0x25304AD7028910CEULL, 
            0xE88D0617EEA3B21EULL, 0x0F35B7C2167D47F8ULL, 0x7BDFC99E23AE61F6ULL, 0xF33C517B2D984408ULL, 
            0x05EF1573DDB03842ULL, 0x34EF3279564DB930ULL, 0xF899FE328487C642ULL, 0x5C2F58777F17526BULL, 
            0x5A5F23A171383C1CULL, 0xC1EFD012ED622869ULL, 0xB82A5E6D1F2534EFULL, 0x95BA6817D5F93C4CULL, 
            0x9C133B14B93A6330ULL, 0xFA456BE7A5FDA3BCULL, 0x48E267DE09D4B08DULL, 0x38866568DC4CA92EULL
        },
        {
            0x0C921E5CE3FEB738ULL, 0xA2CF0EB8DC17A11DULL, 0xF9B79CBCB22D1E95ULL, 0x03D3F7F2BA6C3B28ULL, 
            0xD6496F56479FA2C3ULL, 0x84BAA48992C6FE93ULL, 0x49E4A40FE6C2B7A4ULL, 0x9F7E6A4C557EE6FEULL, 
            0xBFF88BD85D3AEF15ULL, 0xCF25FD8144D355C7ULL, 0x34966DCA656B0114ULL, 0x293FCDB51314D06BULL, 
            0x494A3E64EAE07E05ULL, 0xDAE46557DDCD76DEULL, 0x5722B7694E8E05ACULL, 0x2F681284AEFDEA84ULL, 
            0x9D92CB9BD583997BULL, 0xF19F95D12DDCD2FCULL, 0xC020D46774361FF4ULL, 0x972EDDDF09E8E523ULL, 
            0xDA7BD0FF1A59B962ULL, 0x5A1FAC49A33C6068ULL, 0xDD2075BE88921BA1ULL, 0x10148506268591DAULL, 
            0x7A560D658ED3BF50ULL, 0xC9C44E37508252A0ULL, 0x67177092BBCA3ACCULL, 0xFC27F5C19C172245ULL, 
            0x5B091E2644695F68ULL, 0xE8E2423ABCA9D066ULL, 0xC3FCB0D5003F9A22ULL, 0x08EB0880B349D175ULL
        },
        {
            0xD2291C68E42DD2BFULL, 0xFA06B60F1E768C17ULL, 0x1CFC9EBBAA507E2FULL, 0x2A86007B4384AE35ULL, 
            0x04AB7FDCA64A9E94ULL, 0xA03D98ECFB814D3CULL, 0x70537471A3282B41ULL, 0xFFA7E111B86E9CF1ULL, 
            0x66ADD7F50A5F0A96ULL, 0xAC33B4FFB76BB670ULL, 0x3C3E41ADB3A70B13ULL, 0x3EF30CF0375F1324ULL, 
            0x5D5714EA59D920B2ULL, 0xBB7666B32119D5ABULL, 0x9A0247034F5D0D1DULL, 0xA7DD6025E403B0D5ULL, 
            0xCD30ADC07D7757AAULL, 0x03D6EF4324C7206EULL, 0x821FC0E75E7DDA3EULL, 0x2E381E319D7D10F7ULL, 
            0xCCCDB2445C76D75FULL, 0x2410DBCA07011FBBULL, 0x2532AA2BE57684C0ULL, 0xB4EFC5137099E1F9ULL, 
            0xC8CA92307FAF7454ULL, 0xE3DD9D54ECC6AB23ULL, 0x47D8E32206DC4DCBULL, 0xF6893043118088F1ULL, 
            0x9E6E519CEB1366ABULL, 0xFECDE8C9F05A5B6FULL, 0x2FEC8357264E7132ULL, 0x1364F39324B8CAB9ULL
        }
    },
    {
        {
            0xD405458F326417F4ULL, 0xDFD401AD254DAB29ULL, 0xDE6296EE97726004ULL, 0x4728C85BA9541A38ULL, 
            0x2A7D3C9646BD0185ULL, 0xD086423A0343B311ULL, 0x897C1AE640A7151DULL, 0x50F51D5EB38C8F25ULL, 
            0xEB5A6BCAAA9FA7E9ULL, 0x46B99AB16B5E2934ULL, 0x198F158C55376BA3ULL, 0x2C8849DAB43D7555ULL, 
            0x21FA0FDD410A612EULL, 0x895A96C0F4792D9AULL, 0xF57851C30A8B6AB9ULL, 0xB7A7D5A89EA6B411ULL, 
            0x8A7EDEDE24464650ULL, 0xBCC9A1734FE6D855ULL, 0x061D9F40A3C897A5ULL, 0x493BA2B586E368D1ULL, 
            0x3C85C0C2A890F351ULL, 0x5AEC436D97EB429BULL, 0xA35259DDE206F3D6ULL, 0x8EE757A0E466C345ULL, 
            0x4E459631C839CE9DULL, 0xB1B1B7D65C752D4AULL, 0x3CB0F0609852BD18ULL, 0x46396EFFE9E1FAD6ULL, 
            0x9C944DDE616EFAF9ULL, 0x2B3B671A4A1E1A71ULL, 0x304252EBEAE485DDULL, 0xA625839347E970E9ULL
        },
        {
            0xDC6A94E2D2063684ULL, 0xC44EF986999A9C69ULL, 0x7D8E6EF7D20B1957ULL, 0x4924D3140ECD0AC0ULL, 
            0x8F47890B8870AAD0ULL, 0x20C0FC22EF53940EULL, 0x4F74D3969964FD49ULL, 0x0D9F2761A59A399DULL, 
            0x84DD821E7B484D80ULL, 0xFEF75D88C35E1AF3ULL, 0xC4984866FDAC14EDULL, 0x4FA1BCB6E57F75D7ULL, 
            0x1791ED66887A181CULL, 0xCD2ECFBE5E169B47ULL, 0xBFBE920F374F102AULL, 0xD9F61324AFCB83F4ULL, 
            0xBF7586A2D4A39FDBULL, 0xDD06D16EE4546B62ULL, 0x65671C575E9FD606ULL, 0xFE86E45A78F029D4ULL, 
            0x509D6114B15A6E8FULL, 0x848971C54170EADEULL, 0xAD0AFD89E6555453ULL, 0x3A10943AE75C69EBULL, 
            0xF4AA13056B0A035EULL, 0x425E7EB3A6420C7DULL, 0x65D6C149B5337833ULL, 0x1C131C64E453B91CULL, 
            0x6AD07F324F0F582CULL, 0xE2119466403D93AEULL, 0xC950AAA92BD1477CULL, 0xA8920184E267C62BULL
        },
        {
            0xAD0427278FF0D0EAULL, 0x3758AE1E912EEF8DULL, 0x5BFA445A1FDDF412ULL, 0x186F413819D55638ULL, 
            0xA32CD85FC17C7913ULL, 0xD2A25B69262BF1B7ULL, 0x8E9AC9858D0D0A36ULL, 0xB33242549942DD89ULL, 
            0x7776EE86FEE6987AULL, 0xB3731F128808B689ULL, 0x7400CCB7CCFC658DULL, 0xB55199052F55281CULL, 
            0xAD90C28643051C90ULL, 0x10A450A7B8BC87A1ULL, 0xF08FE75757F1F12DULL, 0x22FCEE309FCA5E9EULL, 
            0x3DBAFCB0A3F7D103ULL, 0xC07D0171C714E973ULL, 0xA0FDC7BB32CB9D0FULL, 0x336A13710EE91C1BULL, 
            0x7CE8889AE504E88EULL, 0x8420FCFA36235D3AULL, 0x72141BCAD521A2A9ULL, 0x473FEA2A54036AD5ULL, 
            0x1E6688561710E25DULL, 0xB8BC75A6B22F3D75ULL, 0x753D2AF9FA3B4F41ULL, 0x9A484EBBF0BBAC85ULL, 
            0x56A2079C5EA2216AULL, 0x3527DBB4CFAFD5C8ULL, 0x10B0AA492B741473ULL, 0xFE940D1CD8FF7781ULL
        },
        {
            0x176C70CB04232DE4ULL, 0xC76F378403D6BD66ULL, 0x817DA780459FD3ABULL, 0x2BF017D3F76EAC4BULL, 
            0xF0004D0229B04E93ULL, 0xD09F8ED9B1018F4FULL, 0xD5348B9A9BE896C1ULL, 0x5044CAB9A3AB655DULL, 
            0x18B8EBCE31E8D32CULL, 0x252A828EEAAB20ADULL, 0x764BD63E32878867ULL, 0xDEDE8D7CE7482AC1ULL, 
            0x7899E449D66C6D0EULL, 0xE9A428B6A0241C83ULL, 0x66202B5D292BBAB0ULL, 0x582554B890971D87ULL, 
            0xE786CD67EBEFB1F4ULL, 0x8AA790BCE17558ACULL, 0xF866FE6EDDB9E682ULL, 0x7BC6CFB7F8C5AC36ULL, 
            0x36C103D0F17EDD02ULL, 0xF80D855122ED52E8ULL, 0x09A6B095F31CDA56ULL, 0x95A5F2108C549F65ULL, 
            0x72BEABDAD7412404ULL, 0x9AB000ED629E321FULL, 0x47A9C30A30D7979AULL, 0xCE586F45EB221CE9ULL, 
            0x1042D43D0CD122BDULL, 0x11443150147BB4B0ULL, 0x70891A8DCC12DEBDULL, 0xDE9C3E7170824E6BULL
        },
        {
            0xEE13F92C21D8E366ULL, 0x5AB2ABFCA4494D32ULL, 0x67B3E118D7F94953ULL, 0x62921435DE4AC072ULL, 
            0x8E6B83876E691A1FULL, 0xE387C02225385C9BULL, 0x786AB13C4AC951B3ULL, 0xF2BB22DC72225389ULL, 
            0xF968FDA48D510272ULL, 0x49C0E8CF3B36FC03ULL, 0x087389B4B6BEAC03ULL, 0x557660D7E349DEE1ULL, 
            0xD41E6B5A372FBF7BULL, 0xA19FF517C47B7D7AULL, 0x02E7FDE592C0DEB4ULL, 0x03554F39108CE757ULL, 
            0x65381AC16DE57BE4ULL, 0x88B52B7C8F0BFA74ULL, 0x0B2BDEE4004414E1ULL, 0xFEFBDAD01EF4E2DDULL, 
            0x4D2B07D028405D0BULL, 0xDC5EC86B2700659FULL, 0x471B4BB1519F3E5CULL, 0x23E187CAD3FD0FF2ULL, 
            0x0E504DA24D7EDE3FULL, 0x1559483104C3CCC5ULL, 0x57C7F9A17AED9BABULL, 0x010DE3F76A11F06CULL, 
            0x58CA1A88139BEF44ULL, 0x9E903A2C2A4B16F6ULL, 0xACB7DBC216872F2DULL, 0x57C3E1195696FD08ULL
        },
        {
            0x883B0937FC6FBEF9ULL, 0x1E3EE0BE620F1D0EULL, 0x7E7AA77FCCB23BF5ULL, 0x8D19E98A8E6CF1B4ULL, 
            0x90B9241C053CED46ULL, 0x2E1DC80309C0B7FDULL, 0x374316A44B6DFE82ULL, 0x329827EB5603BD7DULL, 
            0xEC61994806E42963ULL, 0x7EFA03CE3374EB0AULL, 0x85173ED6B9EDB06EULL, 0xDC8CB4FC1162EB2FULL, 
            0x2559ADEE4678FBCAULL, 0x5AF8679549BD58ADULL, 0xF94E7357EDC66F8CULL, 0x9A79E87BE9EA9385ULL, 
            0x074917DD668FD763ULL, 0x534E8DA0C0E04F3BULL, 0x014B6D77328B73FBULL, 0xF43329FB8A057985ULL, 
            0xBCEF0B2E4F01B31CULL, 0x3ED1C64F624BB2B2ULL, 0x82E856EA838C7E6BULL, 0x740BA4DA6535D124ULL, 
            0xE948F852D7C27931ULL, 0xE36CB56E3C53BFFDULL, 0x7897CEAEFB74635CULL, 0xFCB1C5B6B0541DBDULL, 
            0x5E5392C278A4F463ULL, 0x9E17D77B720CB927ULL, 0xE3BBF0B7527C5D95ULL, 0x6307099D798374FEULL
        }
    },
    {
        {
            0x95DE1D7549F008B8ULL, 0xE974C17B95E6F933ULL, 0x1DB56DA94435FE9EULL, 0xCD94E2404B1B8D0FULL, 
            0x4F45EEBCFFB17666ULL, 0x55CF6B7D5E9D88B2ULL, 0x95E7BBB38A69821FULL, 0xD53FF9366C83E5F1ULL, 
            0x161174CE7A9841EAULL, 0x3C4556F07E2BAEA4ULL, 0x2F0F3721D06D3522ULL, 0x33298BD5CF0DBC01ULL, 
            0x52DCCCC326051355ULL, 0xA1F6E5AD8F1FE608ULL, 0x12BDEFE37A3B0C00ULL, 0xD9279D44121BC139ULL, 
            0x383C0A5B2A57AE86ULL, 0x670313B7062266C1ULL, 0x98D261117D2F9B59ULL, 0x0BE0E1FC98135584ULL, 
            0xD99AEF581B237362ULL, 0x07A64BCA9CB6B320ULL, 0xAFA060BBC6E3DF60ULL, 0x8F3F5CA01CAECC63ULL, 
            0x5B80E47E345CD81AULL, 0xE3236774C88D43A3ULL, 0x5C489C8C47B1E733ULL, 0x62A27E17F3B0150EULL, 
            0xB51D742E40AB630CULL, 0x9EDA3F7CD43364AFULL, 0xD0118A893D85E319ULL, 0x478E14D1B4ECBD88ULL
        },
        {
            0x3D55E0F327FD9E38ULL, 0x8BCED4B347602F95ULL, 0x73130FBB240BF08EULL, 0x36C9D358F0587956ULL, 
            0xE0F0F27C93D1BFC6ULL, 0xBB4B9DABF83B8FCAULL, 0xD319BE24F9BFEFEBULL, 0xA12007F037A43F7BULL, 
            0x16BDAB0CC2F7D0BFULL, 0x58627B024E1BF7D9ULL, 0xF06AC5F140BDB760ULL, 0x9A6B90AE23C311A8ULL, 
            0x2070C02417FF8CDEULL, 0xFA96E1818CE7EA45ULL, 0x60A456D6810C4BF2ULL, 0x9B2D98E2863936A8ULL, 
            0xD8BBBDB83446D1E1ULL, 0x34B150FD96FB4A89ULL, 0xA03C9F8811442EA5ULL, 0x9F7D8A584573EEB8ULL, 
            0xDDDD5DC1120707F3ULL, 0x9281C8C0DDEFF14BULL, 0x50E002490BFB75C3ULL, 0x14E03CD95313D497ULL, 
            0xEBA73F92031210BAULL, 0x12BEA2019290A535ULL, 0x34E5B3078CDF8485ULL, 0x2750F64040450D14ULL, 
            0x6AAAC00CBB0892D5ULL, 0xAD3632A6B415E454ULL, 0x8C92B7F799E03F91ULL, 0xACA770FA307ED6B0ULL
        },
        {
            0xCCA65E6AEE8FF201ULL, 0x3159356B7371A08CULL, 0x736D8CF5ED4F47FBULL, 0xD6902D3C2C776358ULL, 
            0x9C326761D2213D17ULL, 0xCFD564415A33D8DFULL, 0xD524454FD72B2E27ULL, 0x00BA61393491998DULL, 
            0xF011AD1814042541ULL, 0x168E3DF8B10FDF0CULL, 0x5694E1C30B1FEE4EULL, 0xE76D1327E3442E1CULL, 
            0x2D9627068DD8BB35ULL, 0x00258F1CEFE88753ULL, 0xA05FC19EFEF91676ULL, 0xF5B72A7DE6D209D1ULL, 
            0x4944042ACC021E4DULL, 0xE4C1BCD96BDE9921ULL, 0x57F0E6062448C09FULL, 0x080216CB06C0C164ULL, 
            0x10FD83BB8D1F2EA6ULL, 0x72AF20E7E126133BULL, 0x4EE8ACEB2EEC2C25ULL, 0x6F621933E9EECA33ULL, 
            0x5352EADCBE513B81ULL, 0x7A31D746698FE496ULL, 0xFF8C9615CCF266AAULL, 0x230D16042631A748ULL, 
            0x99277A3CEB9191B5ULL, 0x299A14DC45E84943ULL, 0x1AC2E2DCF0F57FE2ULL, 0x6FEA70E8BC9A36A4ULL
        },
        {
            0x6201F218073DB1A5ULL, 0xFE755828C8C13C4FULL, 0x179ADA257C7FA58FULL, 0x521195EE1E6AC175ULL, 
            0xD6D7443171814D1EULL, 0x42B046EE7D72A8ECULL, 0x2C8D6465AF686A7BULL, 0xEC20022AFD585BD2ULL, 
            0x49776C10DAC33D11ULL, 0xBB861B2F97E7AE73ULL, 0x24DBAA06388E7A70ULL, 0xD23AC72BC509500EULL, 
            0xE9C6F4FC59844D83ULL, 0x2F2FB2C59CA37A57ULL, 0x3CC3976ECB699297ULL, 0x64744870633D6AF1ULL, 
            0x2A5CAE94C8310F94ULL, 0x9B6BEC17EED64B6DULL, 0xD447C5846CEE30E2ULL, 0x945D2BF6881B7575ULL, 
            0x2701C770611A159EULL, 0x8812AA1660188DBCULL, 0xAD5744876B494E51ULL, 0x805B7CEDC192D1F8ULL, 
            0x2DD6AEA4C85C6FB4ULL, 0xB843D1DF8E454A4CULL, 0x7797F0C4F2DA074EULL, 0xCAC90B5473584428ULL, 
            0x90A96F1361B7F5CAULL, 0xDE58984F0B35BC9AULL, 0x3DEDF63939AB5263ULL, 0x9B93305F7A4B2C45ULL
        },
        {
            0x7D256C284EEB12A0ULL, 0xBC2EAEB6CDE8D193ULL, 0x3F0D1631EAC292DCULL, 0x8986808F98231DF5ULL, 
            0xF72437ED0FB005C2ULL, 0x4D5F3ABE9E06F4BFULL, 0x1DEBBEA86C7A97ABULL, 0x63DB19C3D2404189ULL, 
            0x7BA908721B9DD84FULL, 0xDD0D58BA6885E117ULL, 0x06E7351A262DC205ULL, 0x2E4824EAEC377FD1ULL, 
            0xDFA33C739411F4A4ULL, 0x8F024C4EF6B4A171ULL, 0xD61A01D6E355BAD1ULL, 0x81FFD917049B4FA6ULL, 
            0x55CF7DFF77397A1BULL, 0x78DFFA5A95A69F9AULL, 0x7E2ACF0AA300BC4AULL, 0x78921750B7D69F2DULL, 
            0x78AB60261815955EULL, 0xBCB869F08EBA9C86ULL, 0x22F741005331DDFAULL, 0x01E369DCA0A53DCFULL, 
            0xA0646C9BE8391733ULL, 0x937A12FDDB6BC83EULL, 0xF792DB2750B7A015ULL, 0x6F55A3EE886598F9ULL, 
            0xE591761B5CAB6B32ULL, 0xF214DEE80CA02B91ULL, 0x72CBF571A9BA5F70ULL, 0xF732A5CF529F02ADULL
        },
        {
            0xFDFA8AAD29C30AF1ULL, 0x5944F5773BAC6BE1ULL, 0x74FCF25F213EFA08ULL, 0x2D7E85676BF9C7C1ULL, 
            0xBD30F849EF0193AFULL, 0x0A8335B607D4EC79ULL, 0xB780539D98DBDE10ULL, 0xD53B278C716AE9E5ULL, 
            0x85A09AFC38733021ULL, 0x7B9BB8C1BBB296CAULL, 0x08E514F7EF89F342ULL, 0xB87547FA9AD11D2AULL, 
            0x08D59A556AACB128ULL, 0x77FF0AB6660DDDE4ULL, 0x622523AF9B663452ULL, 0x1476434AD28E0D69ULL, 
            0xAFF2ED88C6D03A36ULL, 0x28B1995BD001481BULL, 0x275A0DBCBD871223ULL, 0x8218FA1FBE8571F0ULL, 
            0x8580CF6DB5B7288FULL, 0x06787D96A3A23712ULL, 0xCBFB27D4A5D7C4A6ULL, 0xC0F42DE423812ECFULL, 
            0xCD714EF194C41862ULL, 0x97FF5B3712B55BB5ULL, 0x144B6C4D380FB14DULL, 0xA625AAE6A9D75D14ULL, 
            0x012CD6D8CAE61FD6ULL, 0xE0C0F98A6DBD3629ULL, 0xBC4D4CEB427723FAULL, 0xEE1BBFB0558D5AE1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseEConstants = {
    0x62B5D19AB27315C6ULL,
    0xE734B6C9E0A8E251ULL,
    0xA0D2E7ADEC03B333ULL,
    0x62B5D19AB27315C6ULL,
    0xE734B6C9E0A8E251ULL,
    0xA0D2E7ADEC03B333ULL,
    0x341B986D8C9AE450ULL,
    0x07B1AB3C56D8B62DULL,
    0x6C,
    0xA5,
    0x26,
    0x3A,
    0x3E,
    0xE8,
    0xD0,
    0xB2
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseFSalts = {
    {
        {
            0x9FFFB513EB9DD418ULL, 0xFBB9EAB79826CF47ULL, 0x8E250E899ABCC5FEULL, 0xD53FE5FFE8B0A2C7ULL, 
            0x7B479F82A151A7A4ULL, 0x65EB50821C951336ULL, 0xC1BEB3D998FC8FE4ULL, 0xB6EC785DE46D599AULL, 
            0x874D00C15F2CB74EULL, 0x91D8216F5449669CULL, 0xFD925455FF2D5BF6ULL, 0x1422E25BB01EC189ULL, 
            0x5825372B03DAD3B3ULL, 0x9BD99961DAC5974EULL, 0x2832D9004DAA70A8ULL, 0xBEB9958EAFBD97C7ULL, 
            0x4131B3ACF12388E1ULL, 0xB5492196FF8B3EDAULL, 0x9A7D15302C47745DULL, 0xEDF66CC92E0D025EULL, 
            0x3CA8B5DCBED7F253ULL, 0x7D1F1B182AC9BF08ULL, 0x601BB551360481E4ULL, 0xE5C932635F3BFCF8ULL, 
            0x48BC0AF30B5DE2D2ULL, 0xDC37277545838FE8ULL, 0xC2BCC0767F2053BEULL, 0xA9FA8EA5C9C79C7CULL, 
            0x2AAD94E05A60171FULL, 0x55AD26B7FECE667EULL, 0x5DC0C697E1F53C62ULL, 0x51CE3935F3FD5210ULL
        },
        {
            0x8B47E9F41290D2BEULL, 0xFBC3E6298164C132ULL, 0xA4E22215E7F32B87ULL, 0x38AD470BB4B8DBB8ULL, 
            0x4B9E74D0F81531F7ULL, 0x2BF6BFF34160B14DULL, 0x78B43356BCE33103ULL, 0x6061FFC36B21516BULL, 
            0x00B17E958A1D739FULL, 0x2B4D0A0F9D30C4C1ULL, 0x0F2BEEB3D397D1B1ULL, 0x9BD31D553E95C6DDULL, 
            0x51F3ED1B031A762EULL, 0xFC8CCFC9FD88FA8EULL, 0x14A76ACE499B0231ULL, 0x5B5199C19FB7FAB0ULL, 
            0x0308F3D3D0D327A8ULL, 0x7BA7EB9618FFE829ULL, 0x5B6C93B43A87706EULL, 0x32732C6018D16AE6ULL, 
            0xFB734B02DE2D0AB4ULL, 0x25C4845F4E2E7A92ULL, 0x36886C7DE37AAB81ULL, 0xF6092A0ABD3FD687ULL, 
            0x357D7F4C1F39AEB4ULL, 0xA0057DACF5E44C33ULL, 0x35401659AECADE43ULL, 0xFB9DEA6721B630F8ULL, 
            0x382CEB3E04A4EF50ULL, 0xF45BEBCEAA71B07AULL, 0x68E7313A3D188081ULL, 0x2333B5FC69841478ULL
        },
        {
            0x271DBB6A9CAE2A68ULL, 0xC8CCE94621AD7B11ULL, 0x064D80D1A699AE61ULL, 0xC63A1BE8034E6EE7ULL, 
            0xEBB581FAD0384221ULL, 0x96BD96B95ECD1921ULL, 0xD78B707AE438508FULL, 0xED4E5D9D5F378CA3ULL, 
            0xE11807944EE815CEULL, 0xD4F4A8A12227A05EULL, 0x1B476779148B6368ULL, 0x5A100CD53BDDAFA3ULL, 
            0x013A5C2F0394B3E0ULL, 0x430E0E196F355D2CULL, 0xA9D6D98BAD4517F5ULL, 0xD9E837675F9A9064ULL, 
            0x2A24E81D4CFE0003ULL, 0x48F4B359BFCEF588ULL, 0x51452FAE7BEC60ADULL, 0xF610950B02F3EE89ULL, 
            0xF3D03E42E705D110ULL, 0x76554C61F42ABB6CULL, 0x4B830A3B8108046FULL, 0xB2863BEFFFBD2802ULL, 
            0x141CB640E6994187ULL, 0x9F83BB331A61687DULL, 0x125DD50F2E9D2E56ULL, 0x6A5F932E834AC911ULL, 
            0x5B0C0C3FA9EB6289ULL, 0x30E0D178221D973AULL, 0xDFB2B14F2F096619ULL, 0x471939FBBCDFE1BBULL
        },
        {
            0x7558F4FAB35CB81CULL, 0x5992B742D3264B60ULL, 0x6948D0ECA7AC7FABULL, 0x525E530C3B766BA7ULL, 
            0xB18EE39B447FCC03ULL, 0x4A6860C84EFB4336ULL, 0x33F4669518CF3D8BULL, 0x42CF25D4C8852CC0ULL, 
            0x11B0FED79F2ACB4CULL, 0xF83BEFDA6AB3A92AULL, 0x34A8E11B79C456C3ULL, 0x97C165EB3B132DD9ULL, 
            0xE50165FCEA121DF8ULL, 0x411D6FB8E4AA6149ULL, 0x24E3292BAF130722ULL, 0x6B37302C8496EEE4ULL, 
            0x3B21A38A1D0F1E4CULL, 0x7C0484D1D3CE3064ULL, 0xB0E987C7DF326E4AULL, 0xECE549DD353CA820ULL, 
            0xFA5348E334C4ED47ULL, 0xC97DDF5D5266E4B8ULL, 0xD081F2B70D1A741AULL, 0x2C78CD3764571CCEULL, 
            0x56D4A315A4C3B5BBULL, 0x7CB62DE4168A0E47ULL, 0x74A323A228883039ULL, 0x55E3B9793AE1D135ULL, 
            0xCD3AA14776B30DA7ULL, 0x970B5F3C288C79ADULL, 0xBBC5CECDD24FE7BDULL, 0xF0A476D01F8C2FBAULL
        },
        {
            0xC4C86BA5355A1EE0ULL, 0x66CF9FF5CEE7A4EAULL, 0x119C2467010BB226ULL, 0x3DD76D8A35360D99ULL, 
            0xBA036565DD9E9787ULL, 0xA6A459A5D71770E6ULL, 0x55AC83BF602EF177ULL, 0x5BBA17A63D75CF62ULL, 
            0xB36B4EEF57CCC87FULL, 0xFB47146439AA3B23ULL, 0xD1CC4660150BD482ULL, 0xED2F36F84A60976AULL, 
            0xE5F37D37F038A4F2ULL, 0x2AFBC66328DA9A29ULL, 0x2E8C95518763EB19ULL, 0x34378BF5106DECFBULL, 
            0xE17C8C39A4E6297CULL, 0x28E7F6A66EAABC0FULL, 0xAE2DCA51A2A70E4CULL, 0xB669B68E6EA40AC0ULL, 
            0x2B3E767462E5508DULL, 0x21327A47DDA709B5ULL, 0x70087798C652F92FULL, 0x5925B39E040A9967ULL, 
            0x7E8CB7D2C0A882B6ULL, 0x414201ADA8CF8935ULL, 0x98178CB5F52BA1C7ULL, 0x3821D6EF31B8EF1BULL, 
            0x1573E33B43E13881ULL, 0x0B00DA75F1FBDA9AULL, 0x5F1BEB1C4E96DF75ULL, 0x1FE662C264267445ULL
        },
        {
            0x68AD50D9B0CA7D18ULL, 0x77032B2C478C2979ULL, 0xAE488219C9CF2A1FULL, 0x2D059A292534DC39ULL, 
            0x41431E814A22553AULL, 0x65B624445281105FULL, 0x0F9723C711C6202BULL, 0x5033C3254312516AULL, 
            0x13FD63550FEBEDABULL, 0x24DB6EB84E58FA17ULL, 0x065AE3EE91F26F33ULL, 0xFEBBB2A07DABF310ULL, 
            0x8AE83883999348F2ULL, 0xBFBDF1452A7A9909ULL, 0x5E1701CCA8303627ULL, 0x2A47C155925D801DULL, 
            0x188B77A046876A70ULL, 0x1D2260F70F8EE145ULL, 0xE8DB552B95C6A91EULL, 0x017F24F995E9AA72ULL, 
            0x2F845BF3A9AB916CULL, 0xCF28F02BC0021644ULL, 0x014EFC517FFE0F4DULL, 0x1611B0A97E664D37ULL, 
            0x3C09FC6E2C9F4BBFULL, 0x601665EF9950BFBEULL, 0x257F05ED319118F4ULL, 0x6D5F54458C3119D8ULL, 
            0xA0B874BC07E62AA7ULL, 0x17F0A1E11DFE9DC5ULL, 0xC6C70DD0A7FD6020ULL, 0xC8FDFDCF25782B08ULL
        }
    },
    {
        {
            0xE6E673CD5B61BFB4ULL, 0x69D399A180940DDAULL, 0x8C44C75480389539ULL, 0x56ADE4025DFACB10ULL, 
            0x1BC5BE50FA3EFACEULL, 0x0219BB2865BE6766ULL, 0x165CA0FBEEAF178AULL, 0x903A8E0B6C504FF1ULL, 
            0x066783B83C63DE0CULL, 0x77A8BB71AF37A5C7ULL, 0x50B2A3AC7F8B7629ULL, 0x9D12D85EE9E79298ULL, 
            0xE7CA8FA070DD7023ULL, 0x0FD1C9E714061D1DULL, 0x3314C697E0397524ULL, 0xB350358418CC3F62ULL, 
            0x42C4C739525B1080ULL, 0x5050D92723134818ULL, 0x2829DDDF55EF718AULL, 0x95444094420824D9ULL, 
            0x4CA1692454D37F04ULL, 0xECA24E7FB97A2BD5ULL, 0x9393DA7112948CC3ULL, 0x0CBC5576AE3EEAD0ULL, 
            0xF361192F8CEC5078ULL, 0x83A26ADCDFBDD0BFULL, 0x081E1D39306A7EC8ULL, 0xB5431D58AC81C006ULL, 
            0xFF92D3E5FA7C7969ULL, 0xE0DDC34D54C2647AULL, 0x89AF04E533E8B526ULL, 0x42870097E98C0DF8ULL
        },
        {
            0x300C410838663D4EULL, 0xEE6151BFEB065029ULL, 0x0543898EE6FF2695ULL, 0x9479A60E1A95963AULL, 
            0xAB7D82D6463DB36EULL, 0xCC0C1CF4706372F4ULL, 0x74F805BE1A6841E8ULL, 0xAFC18644A1F8AD0CULL, 
            0x5122E85B8A8AE9DEULL, 0xFF49D9CC3685A46AULL, 0xD2C1D50AAC9CEAC0ULL, 0xCE5C41111828B648ULL, 
            0x574AE70D507FF040ULL, 0x2379A332130F633DULL, 0x6CF326AFE5707199ULL, 0x61545AFFB099E100ULL, 
            0x8B6661FB5E278ACAULL, 0xCA961102395FDACFULL, 0xD38D0905A1312B8AULL, 0x2848CAA2BA2BCD29ULL, 
            0xD48CCE98B5EE5797ULL, 0x3456962FAF3E7EDCULL, 0x72B90DA4279D0971ULL, 0xB3C94C930DB06228ULL, 
            0x54754730D57D8A02ULL, 0x2506475260850A55ULL, 0x7870DA404C0167BBULL, 0x944B76C575B4DAF5ULL, 
            0xD85BF2E26663CEECULL, 0xFABAAA76602B0C50ULL, 0xAB04EBD69471C640ULL, 0x75C0C9DB8753E1A9ULL
        },
        {
            0x663A2746327FECD6ULL, 0xBEA79EDF4E3CA9BBULL, 0x99912330AD7EE719ULL, 0x88B82C021D5E6C18ULL, 
            0x9F4275380A9586B2ULL, 0x9BCDFACA90FDC1FBULL, 0x4EC33777D4D4E785ULL, 0xB177838E51A5760DULL, 
            0xC4EC81F55B8E14FDULL, 0x70F7CCE5CD79A49CULL, 0x6FB35361F544DF78ULL, 0x5A409F2ED86D0ECAULL, 
            0x238297EA2F83EAE4ULL, 0x437DE11F59172940ULL, 0xCB57C06675720A3BULL, 0x3C12149A3C443AC9ULL, 
            0xFE4F84137B2AB540ULL, 0x2BABDA2E6E529B0BULL, 0x1AA7291902C0720AULL, 0xA1A1516ABAD37D6BULL, 
            0x57BC2F6D61B37E1CULL, 0xCB5A9B42E93AC5C6ULL, 0xB45105B112683547ULL, 0x254FAECD468548C7ULL, 
            0xEBDA0A66A3ABEB99ULL, 0xCCCDC809FC453AA4ULL, 0xD060C8F686BF229EULL, 0x3A47897C8FDC0C11ULL, 
            0x635335C395466E50ULL, 0x65ED5CF14198AB30ULL, 0xF39C7DD0116D4915ULL, 0x44B00586C13AC8C8ULL
        },
        {
            0x0511CEF759936C1BULL, 0x6444B3210D9DBE6AULL, 0x932826FDB511D125ULL, 0xD4530DE5D09298B5ULL, 
            0x5F62EA0EFCDE675FULL, 0xF61DF43821F6FFEDULL, 0x8E01A7EB46C01BCAULL, 0x6908E7833A0F6A9EULL, 
            0x6EA7E18224DAD5BAULL, 0x5707C7CB5EDFCE37ULL, 0xC076B701A7435210ULL, 0x512EA201F4D59826ULL, 
            0xA64679E6BF5A1BA4ULL, 0x5F5DD5D693010C4FULL, 0x4FD1092AE11D0BB0ULL, 0xF9A9CCEDD9B3338BULL, 
            0xF8B09206A579C5B1ULL, 0x20C29D3B773C11FBULL, 0x785B646E4D77F6D2ULL, 0xBFDA8B3EE3FEE09FULL, 
            0x2E1C76EBB3CA20FFULL, 0x9672ABCFA887CD10ULL, 0x5273D6778802640EULL, 0xE9A09C236439E23BULL, 
            0x1919A2DD683E85F7ULL, 0x118E7DF801AFCFC4ULL, 0xC0D258B16DDA36DFULL, 0xF455C37514CC7D62ULL, 
            0xC686C48A54FE3B34ULL, 0x91B19C8F607C50AAULL, 0x6A40352CE3CD73F6ULL, 0x1D18E78283639648ULL
        },
        {
            0x3AA1FA8E1C570A6EULL, 0x6ED1B5DBE2E704BEULL, 0x0814FB51536C236FULL, 0xA534D0722C17BB65ULL, 
            0xED183111FB292339ULL, 0x70F25E905C8D04D9ULL, 0xA2676E15496A22CAULL, 0xB8033717BCEB0AB3ULL, 
            0x10F507864CF7F71EULL, 0x950684DCDA0E8B34ULL, 0x8235826FE7ADC2B3ULL, 0x12B43F5D2E504206ULL, 
            0x5CDAC81CA0BFF1CEULL, 0xBC4FC9950761976AULL, 0x233F1B362C619178ULL, 0xBA6F3E0B93768F59ULL, 
            0x745FAA172A5AF5CDULL, 0x67CF85935B3D6E58ULL, 0x10D3599D2874C440ULL, 0x872D08EBC77519F3ULL, 
            0x4C3E52E9C9456655ULL, 0x77AB8C6A3D84E6E9ULL, 0x80653B7CEDD866F6ULL, 0x79AEC97E32002275ULL, 
            0x965FDB1396F363F0ULL, 0xD5CAA3BCB24F1919ULL, 0x205CB6DC2BB82662ULL, 0x984FF9A35B3FA1CBULL, 
            0x4FEBE449285490AFULL, 0xF70B76DF878A9E61ULL, 0xA039E0AAA69653CDULL, 0x9278C0792B692CDDULL
        },
        {
            0xB6A78F0C306D83E1ULL, 0x501FD4F4E20C664CULL, 0x6BF8FAD6203ED545ULL, 0x5AEE701E31E22A62ULL, 
            0x0455E9B9E3E87ABEULL, 0xDD9D02B2621E8621ULL, 0x34D015EF3EA841CDULL, 0x80F8E29B4401A5ECULL, 
            0xB795F07B33E4B444ULL, 0x78A829717A4F5D9CULL, 0x995A071C5203DA28ULL, 0x893FCB9D8CC153E4ULL, 
            0x99E28EFE17059D0AULL, 0x7EB0910A1484BBF4ULL, 0x589D48EB231F956CULL, 0x6C717C0E62C78FAEULL, 
            0x0CEEEC7FFA9A3B0BULL, 0x60C71BCBD60262C8ULL, 0x470E8B70CEA0EB64ULL, 0x12C9417ABD1A69A8ULL, 
            0x93156C20535A9B63ULL, 0x60D7A6970C88EAB3ULL, 0x3613658254B5269CULL, 0xAC0B0ABF48B25228ULL, 
            0x39B63A024CB32777ULL, 0x5F90A2FE2D845B51ULL, 0xA73C1CEA50F86451ULL, 0xD2B74B500A5A040DULL, 
            0x990E831C3156712DULL, 0x2D1A018CB6FC09B1ULL, 0xE53D2F1C3C95EFECULL, 0xF3881EBD5799DA3FULL
        }
    },
    {
        {
            0x0FF22B4CC5480EC5ULL, 0x89D359C7F2B26611ULL, 0x514CA627F8E2E553ULL, 0x33A6A14AC09F7A8AULL, 
            0x64C9E57DAA61B697ULL, 0x0980712C403FB03EULL, 0xA91BBEBD017E5CC7ULL, 0x2F1CA6052A0CA7F6ULL, 
            0xA88025D3B756E285ULL, 0xAD8A6F00431E755AULL, 0x95EF4E1E1A0972B5ULL, 0x02212C729EDC7B84ULL, 
            0x603B8AE492C91BF7ULL, 0x7938D7C7166C27EFULL, 0xF4A741961E881D53ULL, 0xC63F03D5B5C0ACB0ULL, 
            0x45EDA86F5D4A77B2ULL, 0x2F6A57C21EBBD2C6ULL, 0xD7C7C0AD218ABD52ULL, 0x191426D29BD1D2EAULL, 
            0x7FAF58992AE8907FULL, 0xAB59474EBBCBA452ULL, 0xF833C45BFCA73613ULL, 0x3C25D2263CEE6515ULL, 
            0xF981C80DDC57697DULL, 0xE6F30E19CCB8E6F6ULL, 0xD8399B66E28ECC6DULL, 0x7660A78614D97D21ULL, 
            0x0AF0B83096593C57ULL, 0xB18217D7F6C315C5ULL, 0xEA03A1AA3C0D8918ULL, 0x28581E47BF6E448BULL
        },
        {
            0x54EB3063C4F9289EULL, 0x0F4A15259DE40D09ULL, 0xC44B90312DB0C3C4ULL, 0x1E901CCD2A452D47ULL, 
            0x0EE0A1BF14A9A1C0ULL, 0xD8FB648021E6D9B3ULL, 0xBFB250256406824CULL, 0xEDEF87E2CA97753FULL, 
            0x5270C1039A12E8B9ULL, 0xA56CADE9A9F18C90ULL, 0x89BD968840DB6CF7ULL, 0xE7F2626EF2916418ULL, 
            0x6608443C373959C3ULL, 0xCC4BF48C3CDC2522ULL, 0x5CC8846CF76AEE9CULL, 0xADE292DB4C570E12ULL, 
            0x416D679F94C0BE76ULL, 0xACB5B14573008ADEULL, 0x5FC180B5094B5E08ULL, 0x54192761871B893FULL, 
            0x38BB72983B5FA1C8ULL, 0x395F461043B461D6ULL, 0x2054C17F74AF6E3AULL, 0xB172FF56444768DCULL, 
            0xA98D73E7B1A6C7F3ULL, 0xCF0683932A11330AULL, 0xECD9DEC098A9E414ULL, 0x094E05E0C793410EULL, 
            0x6DA20266C587C953ULL, 0x13BF980089B05531ULL, 0x312E0D5A10FAB681ULL, 0x8A246C3458124A99ULL
        },
        {
            0x3D78C272350D364AULL, 0x28FFE96FB001DA6DULL, 0x9A3B71ECCA219463ULL, 0x3D0E69EC8D073B11ULL, 
            0x4B84CFF1F65CA472ULL, 0xDE705BCEBADCECF4ULL, 0x51A99216855E52E9ULL, 0xB4F868608E766077ULL, 
            0x7515BB92336DE7D9ULL, 0x45194DE977B431EFULL, 0x22A6F15348981570ULL, 0x47DC52CC72C0587CULL, 
            0xC7611BE654E7A192ULL, 0x61BA0B3C7902B41AULL, 0xC1903ACC1A421FF2ULL, 0x82BE3707FC0B7FB2ULL, 
            0x0BFA619966EE50F5ULL, 0x04639445A95B97A3ULL, 0xA8C5249ED321715CULL, 0x8D40172819D00850ULL, 
            0xEDE2F54C8C2CCC3EULL, 0x262A46A8720A2FC9ULL, 0x292E64C1C3012B07ULL, 0x82A961BC50AD5899ULL, 
            0xBCED1839792B060CULL, 0x0187BBD0D8F6338DULL, 0xDF669351697F5ACBULL, 0xF4E58416599464C6ULL, 
            0xEAAF0ECEE8E132D4ULL, 0x682FED288F2CAD15ULL, 0x8F62BCE1D27B0294ULL, 0x3A124F7826C05DE0ULL
        },
        {
            0xBE8D560886352638ULL, 0x4A43360CD476DD72ULL, 0xDF8685F5DA119936ULL, 0x7590594D8DE56B60ULL, 
            0x40954098B9000548ULL, 0x802617D386725D11ULL, 0x26ADD03C5A6DF013ULL, 0xDE5311A4C1926499ULL, 
            0xA798A1FBB6AAAB6CULL, 0xD18D45017207CCA4ULL, 0x8F6A2995114EE0E3ULL, 0x3045CF8FB5CB6F96ULL, 
            0xEA80125B65B0ED84ULL, 0x4F6AB8EE234F51A6ULL, 0xB2170675F1765754ULL, 0xE1FA004DC9F9B370ULL, 
            0xF44B3535055D2CBFULL, 0xE257AC950B04C3DDULL, 0xCBD5C538C381DFF3ULL, 0x31B9FFB0957C924AULL, 
            0x6062499BBBB29C70ULL, 0x5195F0F66EE58895ULL, 0x9BAAFF0E655D49A2ULL, 0x8F64E329297D0816ULL, 
            0x301225B74C7B23AFULL, 0x42A5D992776EC9FFULL, 0xE951F5BA5E161EC3ULL, 0x5808C5FE5404B04CULL, 
            0x1423773AA19BE383ULL, 0x31CAAECB14F4D2B1ULL, 0x21FEB5DEEBAE1ACDULL, 0x27D4E5A86218A213ULL
        },
        {
            0x2D7FE1E747375EA2ULL, 0x0C53A2E2EC4F01E5ULL, 0x013EBA1972CB51FAULL, 0x073EF9B8CA82014FULL, 
            0xA7CE110C6EDC319FULL, 0x4519DDCF7A110AD9ULL, 0x025E96B8C45C82E8ULL, 0x0BC87BD8027D8E62ULL, 
            0xF6626A962D85257AULL, 0x14DB50C85D92F305ULL, 0xCAEDA18B581F254CULL, 0x4A589538D768D42CULL, 
            0xB17DE15E067626D2ULL, 0x19514F78C681F05FULL, 0x882CD916921F76F3ULL, 0xAD07E81E99951A6CULL, 
            0xC4E051AD7972C00DULL, 0x96B040F314752182ULL, 0x650A468B1D01AA5DULL, 0xEE573504F5E488C9ULL, 
            0xE94C8BE8F9577D00ULL, 0xD89D5F4892F95BCCULL, 0x69594A60905D6718ULL, 0xC2466E50997D638CULL, 
            0x62816B4E5694B1A1ULL, 0xB4B0348E78C2F092ULL, 0x45CC8FF804BC228FULL, 0x454005213A6C1DD3ULL, 
            0x8CDFF2977297DB29ULL, 0x375C2F122C46B3B5ULL, 0x4F431536BD6D7B36ULL, 0xB57FEC57ADAC43A0ULL
        },
        {
            0x0ECC9E082DFF57C4ULL, 0xAD001FA8225F63C8ULL, 0x1F1A3909179E2665ULL, 0x41F6E1134F2B83C6ULL, 
            0x48F83DCDDC95EECDULL, 0xE391748CE245A475ULL, 0x47CA7F7FD67B873AULL, 0x276C8960412C52CCULL, 
            0x6AB33480D1B7A4ABULL, 0xFEF9B107E90C262FULL, 0xBD91DC61D31AD2C4ULL, 0x7E45C40A60EF1BB9ULL, 
            0xEC61C4ACABFAAF59ULL, 0x505DF4192286F568ULL, 0xC57A880FC50A34C2ULL, 0xF8EE7C6BD78CA42EULL, 
            0xB175E0BAAA4BE3E2ULL, 0x49430A56E43A22ACULL, 0x157778EC5934C780ULL, 0xAF30A5B5FFA7D6D2ULL, 
            0xCCF1A33D2E5D7975ULL, 0x172F2C73AF23C41EULL, 0x2755FF356F3C1C72ULL, 0x3351FFEC7F76208BULL, 
            0x8C48238AE15455FBULL, 0x087EF0C5B2776A0DULL, 0x43B1FBFEC050CE6CULL, 0xE40C0852BA323A7BULL, 
            0x49DF6950798B14FDULL, 0x42B1F303405AC0F1ULL, 0xE5927350BE72B9D9ULL, 0x3A72A667CCAD41C5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseFConstants = {
    0x6A003A9035BD4CBCULL,
    0x8A7173A3A9CBE115ULL,
    0x7AE9506070747E4EULL,
    0x6A003A9035BD4CBCULL,
    0x8A7173A3A9CBE115ULL,
    0x7AE9506070747E4EULL,
    0xEFFB3176CD48BA4BULL,
    0xB860A8D5B787F280ULL,
    0x9A,
    0x4B,
    0x68,
    0xD9,
    0xC3,
    0x14,
    0x97,
    0x5A
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseGSalts = {
    {
        {
            0x1FDB0B737F06C929ULL, 0xA745DE83CC80DAC5ULL, 0xA83E3EBA6C309B0BULL, 0xD369AA04A58A628FULL, 
            0x80CAD6FE29D70E97ULL, 0xBAE356D04F3FA212ULL, 0x9FDD4BB3A1822F51ULL, 0xDD834886BEE5EC64ULL, 
            0x17F449A4B05CD11FULL, 0x20B8E8B97397A7DFULL, 0x17722D371EF53DDBULL, 0x25C1857E72C119DAULL, 
            0xDD51581B8656574CULL, 0x87DA1A00EC751DA4ULL, 0x4D5162B9311536DDULL, 0x52C7E3D9367F4B45ULL, 
            0x1E7C814C3DF68E8EULL, 0xAC259AB098365FA1ULL, 0xABD4F83F438592D2ULL, 0x051A112259633A4FULL, 
            0x554882149D76ABAFULL, 0x07144DF0F46C6E94ULL, 0xFBC70D33E32DEC14ULL, 0x71B32E8643804B7EULL, 
            0x991932CBBC78516CULL, 0x08AD1C7F88AC3EA1ULL, 0xB3F60785B5C0FA66ULL, 0x2439652A8258B1B4ULL, 
            0xDC3FBC28E08D6250ULL, 0x320357760EFAAA90ULL, 0x5B3CF8E012DFC34BULL, 0x7B724E4FC0D16329ULL
        },
        {
            0xAA96638CC8495C7FULL, 0x12B5DC811E2221FAULL, 0x7AA39F2694E9AA8DULL, 0x587B307AEB00CAA6ULL, 
            0x24BD7699DE9322A6ULL, 0x96807E21679B0374ULL, 0x81936958BD8586A4ULL, 0x5A6143F98F20E838ULL, 
            0x17D6FEF1C26C2C2FULL, 0x99BE933A82247231ULL, 0xFA47E9721AAD2A49ULL, 0x1CE7AB054C607846ULL, 
            0xC725BD0B41A02497ULL, 0x8A2ED5432E6BA567ULL, 0x4EA47B2515CC2353ULL, 0x5D9440360C7A05C0ULL, 
            0xCE01D2E8DAB7C91FULL, 0x81791C4F3EB3BAB4ULL, 0x6EE055E8EEC167B3ULL, 0x5FB71548BB8FD390ULL, 
            0x5F264B6AD6E2270FULL, 0xA9D3AD8A78FF00D6ULL, 0x2D5D52C5C1E615F9ULL, 0x8151DA7804D122F5ULL, 
            0xF186422C785392E2ULL, 0x02D832F71DDDF547ULL, 0x7038A396A8F0B802ULL, 0x25A440B63E4A2D17ULL, 
            0x23114C2D695360A3ULL, 0xBB33F7B2DFB268F3ULL, 0x08A0262939569DCBULL, 0x8FA2D7722BABB50AULL
        },
        {
            0x904F9C17CB1F879EULL, 0x329D486E2976EACAULL, 0x0DA55363EFDA5B7FULL, 0x8817EEB6AC9ACA23ULL, 
            0x16EDBDA62E1B6E39ULL, 0x8B27C7CFAEC314E7ULL, 0x2FC519ABF87F1C3CULL, 0xC4947DB4474BA884ULL, 
            0x1D481D49A8484B25ULL, 0xFC004ACF0F5ABCA4ULL, 0xBDF8FC0AD026B5B7ULL, 0x280336562F2BC7F5ULL, 
            0x76446932CF26BCA1ULL, 0x436FC7F2692D81FAULL, 0x0E8DAF4F1FE4CC28ULL, 0xAE6164206E79F247ULL, 
            0x496002FD7618106FULL, 0x3590D0233A44B81FULL, 0xE73C16EA87429CDCULL, 0x2163358741925FF9ULL, 
            0x9E2A638F6B2557B8ULL, 0x48DA1757958A2987ULL, 0x8C673023D7A5E57DULL, 0x1BD705F26502333CULL, 
            0x65E1D406CFBF7183ULL, 0xC539D03BC556A8FBULL, 0x8BFA154F9C611015ULL, 0x05866C509EA8E4E1ULL, 
            0x8A472B89667C72C6ULL, 0xA0A3580560CF5311ULL, 0x3864C9597DE0344EULL, 0xEF710FD7480080FCULL
        },
        {
            0xD51393537FBAD90DULL, 0xBA9BD3F26258C614ULL, 0x36C736E61100FDEEULL, 0xFC5825D5E87EC51AULL, 
            0x9D35B3B403113258ULL, 0x979D0959EB9FAFFDULL, 0xDAD43916D9FBDC97ULL, 0x6F89F5BAEC0D5D43ULL, 
            0x5D7009CFCBE4E8C2ULL, 0x3FFA1A681503D3CFULL, 0xD8D2F2AE875CEAA2ULL, 0xB9615E61929EA45DULL, 
            0x16B73520B9CBC714ULL, 0xD109C4CA9159441BULL, 0x24F18E75A70AAAE7ULL, 0xD10B283AFE6B58A8ULL, 
            0x617CAF9AACC008A7ULL, 0xF853628620230F8FULL, 0x4BF9CA758B13A8C1ULL, 0x4539F3F20AD138C1ULL, 
            0x52B2B2CCC3513355ULL, 0x4E289C681EE8608EULL, 0x145C682F0591CF2BULL, 0x4089AFED32C34FBCULL, 
            0x561C655073EF2375ULL, 0x73B7A9E253D7DE91ULL, 0xF5D4BDD094BEF494ULL, 0xD5D956C0C1C6DF3AULL, 
            0xBF0620CA1C1DF42EULL, 0xCAFCEC50913937EDULL, 0xBD5F0741E6F41A0EULL, 0xD14AB6761AD8B91BULL
        },
        {
            0x197CD5963F20B9EBULL, 0x2D00784637F7B704ULL, 0xD8B4A518D418DC9DULL, 0x0C1BCD84CA81F04CULL, 
            0x47C404C9D63632B1ULL, 0xD0DE311074976DABULL, 0xE27C0AD86AAFFAB3ULL, 0x6792FC9423821224ULL, 
            0x404627C7CC838A40ULL, 0xD6B6FF92AFFF2B44ULL, 0x67E6E62E44611AEAULL, 0x497DEF340F427874ULL, 
            0xEF2159E6DCF2B6ADULL, 0xF62A0EBC07A69BA0ULL, 0x9FF0635F40E1C5E2ULL, 0xCE393DF01B15CA0DULL, 
            0x7369F468EFB92914ULL, 0x527B280110A1C959ULL, 0x311AFCE6A3F89A6CULL, 0xC024FA63213859ECULL, 
            0x0249D7E02D3A4ACFULL, 0xF19A8F731478E1B5ULL, 0xCCD6E435AF9AC72FULL, 0x53965BDB421E3F1DULL, 
            0xF0032B171142A663ULL, 0x4E2FDC4B9548F512ULL, 0xC0CB1F1D65F863A6ULL, 0x947490A17A850D9FULL, 
            0x595D584D9D3EDF66ULL, 0x30B19BA7E5707D02ULL, 0x80164CBDAE0EC7FDULL, 0x4D0334B51D20D812ULL
        },
        {
            0xD23EF04B714730DBULL, 0x58C4C3332FE35E86ULL, 0x482352C965FAE6E2ULL, 0x1926E76A9D09E92CULL, 
            0x635ACFF2B43169BCULL, 0x860D443F0EAD3218ULL, 0xF250004F9670D85EULL, 0xD48FB00534B3B481ULL, 
            0x754B55928D6AC495ULL, 0xCB89E8AFE39E7A80ULL, 0x2989C8288DD21220ULL, 0x877A3809CC066840ULL, 
            0x12CAF72CAE5E96F6ULL, 0xF7BDBD0312CC6FA7ULL, 0x8B9C4C1EA4D53EEDULL, 0x1C87624CCB14B91DULL, 
            0x63D4BDEE6BD95000ULL, 0x81DEA98F5A739200ULL, 0x36F57B4D6EFA6B7DULL, 0x5A708FFD5743F66AULL, 
            0xBB22FDD9D36719F9ULL, 0x76521145DA40D79EULL, 0x3E6B6EADA448F537ULL, 0x6C49001BBCEC0E98ULL, 
            0x728FFE2D7C14DB9AULL, 0x0007A6F96278D4C6ULL, 0x3E908624D0D247FAULL, 0x1E9EB934D2CEC39CULL, 
            0xF2BF5F797FE23515ULL, 0x3E3BD28340B4FE5CULL, 0x117DA930B615BE0FULL, 0x9111655D18D5772CULL
        }
    },
    {
        {
            0x83A78CE61A7F3FDCULL, 0x20B50CD47B2F9980ULL, 0x61A2DB7BD20DE091ULL, 0x083E11489D91DEB1ULL, 
            0xA55301B5CB72B163ULL, 0x78018DE7ED484548ULL, 0xC24C09F5077D04D2ULL, 0x643B142C0DE65D5EULL, 
            0x60B8A88ACBCAD7AFULL, 0x92DB2F6A67E7E784ULL, 0x55E2A2E6C2D60126ULL, 0x09F1B5FCDA72FB45ULL, 
            0xB4DBE6C2CB3A12F7ULL, 0x84BAD7FAFFB3B7BBULL, 0x1957AC5F150320B2ULL, 0xE04A26EFC08E9A52ULL, 
            0x912BE73B7D3FBC42ULL, 0x4E50008C0A6799EAULL, 0x696CB3AEAE76FC1DULL, 0x2DE9FBAAB73859CFULL, 
            0xD13C9025E63ED07BULL, 0xAF6BA9BCB8B24E07ULL, 0x5A6BA98E97B9BC52ULL, 0x5FEAB10F54C48A13ULL, 
            0x8D3DC259E98E4160ULL, 0x0F97217D233F6B52ULL, 0xC73AFCB55DFF734FULL, 0x508C39DED46BC5F8ULL, 
            0x7D771BA17DE3A4EEULL, 0xD2FD693D145AD37AULL, 0x3F32BD056ABFEA71ULL, 0xE9FA630F9ACBFCD3ULL
        },
        {
            0x0BC291B98DB41108ULL, 0xF1FE006792FAE3F5ULL, 0xD05EAE8466FE9C54ULL, 0x20047406486E5642ULL, 
            0x01D4AD7954279743ULL, 0xE59107A99B8EAA84ULL, 0x31DA8BDCC51E88D2ULL, 0x58A38E83713C1375ULL, 
            0xF96D8D2A5DE951C7ULL, 0xA6CB8A3D28458F67ULL, 0x2074053D8CD94CEBULL, 0x3AB17CC74B6A0C7AULL, 
            0x528120B109C19D6AULL, 0x526E157EAF80FA4BULL, 0x4AC2080EEF947FD4ULL, 0xE4E9912235C4FB05ULL, 
            0x55678AE4EF6B4CFAULL, 0x1A4D671A28E3940CULL, 0x836AD21C965C8E07ULL, 0xF4EE27021422817CULL, 
            0x924C014C1CC9E27BULL, 0x0C1CAA923C59889DULL, 0xB74734CAA57E35C1ULL, 0x49A3667215ED448CULL, 
            0x92EB4A98A4B3F98FULL, 0x41BEAA8FA3E1BD12ULL, 0x26C581E3A4F8FA9AULL, 0xAD51FE5FCC6C8054ULL, 
            0x6AEF44D80C6D40A7ULL, 0x99663667BA45CC4AULL, 0x8D3099CC091A2BBDULL, 0xB4C966789B9D8135ULL
        },
        {
            0x2B3CE145052ADEF8ULL, 0x87471613FC4E49FFULL, 0x9B359A7355E94746ULL, 0x8706576605FD429BULL, 
            0x49ABE5BED34B703FULL, 0xA9F609A304ACDBD3ULL, 0xB420D536CF120E46ULL, 0xCEA747354DBF4D21ULL, 
            0x86493125587CD299ULL, 0x73A210A13ADCAC60ULL, 0x43EE9F94A6FF0E9DULL, 0xE636FDD7936D45CFULL, 
            0xF729131478B26A73ULL, 0xFEDEB3A6A6B7B65DULL, 0x88FAAA72B4A47067ULL, 0x426C11F2CCA41025ULL, 
            0x5969ED015C4012EAULL, 0xE43A4F39BB88AD25ULL, 0x1645BB3D48ED8842ULL, 0x7F0578CCDEAFE39FULL, 
            0x2EA7E1C6A500D23EULL, 0xB5BE23F4EE50CCF9ULL, 0xB0A83C4F10EF057DULL, 0x0FBAC3073D8A8360ULL, 
            0xA7FEE0BF0803FB0FULL, 0xD2EC7DDC4A1C1EBFULL, 0x8ABDD1AED95E99A2ULL, 0xABA08EA77F0D5772ULL, 
            0xA3C180ED399ACE6BULL, 0x3A3912E538DC7CA0ULL, 0x57572AD3B1B5286BULL, 0x4B596B96A0377453ULL
        },
        {
            0x169D1D8ECF060226ULL, 0x99325A7CAC6C831EULL, 0x29E3075316CEBB70ULL, 0x252E95AFB62FE431ULL, 
            0xBFE7E4416053949DULL, 0x062E25D54D6FD933ULL, 0x202324363F6D9636ULL, 0x1B9F01A2D499F398ULL, 
            0x5F9948A0716E26E6ULL, 0x596C8186F810A090ULL, 0xBCFCBED3CC991BC9ULL, 0xA8C8C226725A3541ULL, 
            0x985C43AFB88CA7F9ULL, 0x5499E0C7C4136F84ULL, 0x6B4438CE3F2957E3ULL, 0x601766B03AE7AF41ULL, 
            0x5FE4CB7D0BA295F7ULL, 0x17CABAAF84257D56ULL, 0x4A9A300DF4D831D4ULL, 0x64CE695C50602B02ULL, 
            0x608277C4AF60C4CFULL, 0x5FE0DD005CA192E4ULL, 0xCAC24381325B6EC0ULL, 0x68A48FE9BF6E1B58ULL, 
            0xB2BD748DBF878566ULL, 0x88F22A4944820D38ULL, 0x903D439B88995821ULL, 0xD8CE559F9A97D9A8ULL, 
            0x9BE010F59EA2D305ULL, 0x797320F5EB9B4C14ULL, 0x8E87BA9AAFC8315AULL, 0x76481AA83F62965CULL
        },
        {
            0x95F5DEB95ADB21B7ULL, 0x6E72774F61F4D2A1ULL, 0x1BD1D472EAF427C3ULL, 0x823AA50CAF1CA580ULL, 
            0x5ED9E3A5E4735E89ULL, 0x8997E273589730FFULL, 0xC9C4827DE306F34CULL, 0x9BAF9539D5697813ULL, 
            0x77B70ADD00D6B743ULL, 0xD7E9114A1A8DDF98ULL, 0xF493E79FDD915F13ULL, 0xDBC9088131CDC901ULL, 
            0xC9D05B7EB346B73CULL, 0x23A461F342CE3D82ULL, 0x4EEE68B7D8929313ULL, 0x5DC6BAFCBF538BC8ULL, 
            0xF4E17C6480B21042ULL, 0x1FE1D9F57BE43E99ULL, 0x4B4B2F672155CA6CULL, 0xC03CBAA37B99ED74ULL, 
            0xF44A632E5661EE9FULL, 0x07874EE6E8EEF928ULL, 0x75C504B7F3153A61ULL, 0xB8F4BF620AEB1F74ULL, 
            0x4804F4E359BE7583ULL, 0x1D4D5C642F0601FCULL, 0xDC337FDF2311C9BAULL, 0x4600E772A9B44FBAULL, 
            0x310981AE970FA407ULL, 0x8FF2AF96A05797DBULL, 0x1303E2566F031C6DULL, 0x0030826875B359A0ULL
        },
        {
            0xEAF5E861BB4122E6ULL, 0xDEB377260C25002DULL, 0x907F2C00B5A5D7FCULL, 0x94DE16244F41EF92ULL, 
            0x5DD2EB04A2D52844ULL, 0x9B2FEB61BA1ECC9EULL, 0x56B16CB16E028F2DULL, 0x09DB3E3A94DD91DEULL, 
            0x6D329C063A82ED3BULL, 0x4E61B4039F7156EAULL, 0x21829F8ABDD2D066ULL, 0x860339A56F886787ULL, 
            0x72840701914F8234ULL, 0xC0CCD213FC22F1F1ULL, 0xD44FF83C9F449649ULL, 0x1288F91B9A9C0476ULL, 
            0xF449F05EB58FFD12ULL, 0x0DDF0AF88088A977ULL, 0xE5CA137059516BB3ULL, 0xABA01392E776738DULL, 
            0x07ECCB663C297CC7ULL, 0x8346EE5B35686B85ULL, 0x3AF55AC075F88D1DULL, 0x775D82ECC62C4370ULL, 
            0x48D65D46A9343F36ULL, 0x8609EC7F133B2DF6ULL, 0x10E430E76FF8DDEBULL, 0x1BA4FE0C071C09A4ULL, 
            0x513D023DE7D1D3E9ULL, 0x5B1EB26E487FD5ADULL, 0x29823B2CBCB2677AULL, 0xB4DFB2B3F27AF42DULL
        }
    },
    {
        {
            0x90EA33E4AF9F89D0ULL, 0x34706783DF9FFBFCULL, 0x7368780CCF8DA0E7ULL, 0xFD1BCB9516350571ULL, 
            0x65C8003A1C2E798FULL, 0x7FC7B957C81FD435ULL, 0x3F2B298A8A86F42FULL, 0x56BC5DF264969F09ULL, 
            0x0DAAB0CDC52B5B37ULL, 0x9EAD83947A7D1542ULL, 0x7107ED35BCDDA14DULL, 0xBA059A9AA152ED06ULL, 
            0xC7DDE8CF1835571AULL, 0x1FFCF0945E8B7F0BULL, 0x27148ACA4FB789ADULL, 0x25AC6E70446EAF28ULL, 
            0x49AAD0A5AC9AD0FEULL, 0x5CAF008E87083529ULL, 0xAD5009EF4515C065ULL, 0xF821A2A5E1A3486BULL, 
            0x4D71DD42C466D825ULL, 0xBC783A6F95485F0BULL, 0xE4817F1F7A482A24ULL, 0x042C78F40FDB0EDFULL, 
            0xFB91A820B20A6890ULL, 0x92062407A6EBDE1CULL, 0xA34EE0ACE5E17566ULL, 0xBF3E10D844719A32ULL, 
            0x16601F72A475E5D5ULL, 0x254155363ED0DF14ULL, 0x0118823AA2F1DD7EULL, 0xD6ACD50A8ED0403CULL
        },
        {
            0x77D55FE2F8FBA4FCULL, 0x2A8094661F12DF67ULL, 0x7E98C06C770F8F68ULL, 0x878678C13109755BULL, 
            0xD85A051941FA877EULL, 0x8120FE9456EEFA46ULL, 0xAB0F80E3E48AE921ULL, 0x8F521DD5F7D9907FULL, 
            0x206E46A88F803B84ULL, 0x5CD0A6B3BBCCDE05ULL, 0xCD15B0F4BFD88B57ULL, 0x28A7F691C34CDE2EULL, 
            0x73E8886AC370C8EBULL, 0x399355D520129242ULL, 0x02F30BAD7E48E9D5ULL, 0xCC04ACB165BAA412ULL, 
            0x19631BD27599F186ULL, 0x6EB8098219A94068ULL, 0xE1750406587102A4ULL, 0x70551DA2820683CBULL, 
            0x03A2BBB0E6874107ULL, 0xCA652B1F801D222BULL, 0x5A839E7C145426D1ULL, 0xC48BAB67CC8308E2ULL, 
            0x97F1A20D42D39F5FULL, 0xDC7A24DD3BC7DAEDULL, 0x093E65AA72195C94ULL, 0x9642A3043A10814DULL, 
            0x9601D9265213CA15ULL, 0x72C699629DA7696DULL, 0xE63020B850A2602DULL, 0x4F7A4FE8AC87AFAFULL
        },
        {
            0x7188AC804447DBDCULL, 0xD5D2528B6D7BE734ULL, 0x51ADEDAE0EDA2556ULL, 0x492302CE9B65C974ULL, 
            0xBE17202EA05921C8ULL, 0xC9AB6A418BD1FA4EULL, 0x5E0B9D275999320CULL, 0x5E294F3FA18C3AE5ULL, 
            0x9B891D3F50BB6F66ULL, 0x65DC88E7DC3E9234ULL, 0x22D76BE1C254F017ULL, 0x176DB54DC2F57202ULL, 
            0x15B1065E503E90D6ULL, 0x6C39271F447FC216ULL, 0xED6202F13EFD4A55ULL, 0x4378A28D4D25DFD1ULL, 
            0xD90563D0EE20B095ULL, 0x1F7CFDAD3AFA37CEULL, 0xBD97CFD3C9E362C6ULL, 0x5A76C35593CBC0A8ULL, 
            0x961F22C456287C23ULL, 0x413B1EE36BE922FDULL, 0x5086733314435A9EULL, 0x5F9B9BE64B666078ULL, 
            0xF2A8BF19BAF97757ULL, 0x61884AF06CAE9B29ULL, 0xAC2BD5B9BB4EB25BULL, 0xF646823A59F944F2ULL, 
            0xEFDCE714F7E6990CULL, 0x9636DCDA9CC4638AULL, 0xDF75591E5C1BB7B2ULL, 0xB32A3D288A452E80ULL
        },
        {
            0xF78F0AD61714055FULL, 0x9645E68F77664EBEULL, 0x1A983495631EE8C6ULL, 0x61355356B3620CE0ULL, 
            0x72E308F0CA1C4468ULL, 0x7183FB0F4B2F10FAULL, 0x4DD459D4B8AA60C5ULL, 0x57E6F8CBF9D666A9ULL, 
            0xC9E30A23BF9E21AEULL, 0x3B20CCCBDECAEAE9ULL, 0x7906F44BE7082A05ULL, 0xD276D92D64778482ULL, 
            0xE2A9DA6D2D94554FULL, 0xB021B3EEFCF95DC2ULL, 0x59A88CA3AAD7A6BEULL, 0xC1D456BA84F596E5ULL, 
            0xAA78B80EFF56F48AULL, 0xE7479CE436C05D9BULL, 0x2EACA8B75F9339D4ULL, 0xBA37A7379BBBD0B3ULL, 
            0xAB3F8E47D3B3A0ABULL, 0x344D1BB678B97DF3ULL, 0xEA66E985471AD329ULL, 0x5EB3CFE4DC15FD5FULL, 
            0x8E445111B1B052A9ULL, 0x997D7B0935EBE030ULL, 0x42F634B1A97C5344ULL, 0x8F436AD7E11D234FULL, 
            0xB77687880BCEF544ULL, 0x2A18B22C4BC7768EULL, 0xBD174DF830B96488ULL, 0x26F75D18788FC7EFULL
        },
        {
            0xDBFB1184A2429401ULL, 0x87B52E625136D771ULL, 0x6FC45F10A719B4E8ULL, 0xC4B977CADC2F71EAULL, 
            0x2F3086BBEFA81E3DULL, 0xC756D46F1FDB0361ULL, 0x0EB8EE79845C9976ULL, 0x716BC0A4F33A2E7AULL, 
            0x81E4CBAA1483BD12ULL, 0x0D505C01305D178BULL, 0x0F8F920AA5DDC5FAULL, 0x98B35F7A66668187ULL, 
            0xA9214163578C070AULL, 0x51D2759827712079ULL, 0xA21A668F06307E94ULL, 0xEA279786A1F822CCULL, 
            0x9F92991BBB659F15ULL, 0x5C442A7900EC01D3ULL, 0xA8A73BA1255DC148ULL, 0x1DE6B99FDDD457E1ULL, 
            0xAF3ED4E2146CD4EEULL, 0xE0FA23CDA74D5DA5ULL, 0x7C53F2BCB11B325DULL, 0x6ED4A29866AC3BE4ULL, 
            0x4DEDAA7D1A5E21ADULL, 0xCBAABE777A825F3DULL, 0x6CED81BE0C9262B4ULL, 0xDF0227B4CC566CC6ULL, 
            0x11679CC53026FF2EULL, 0x3E4C229122BBCC34ULL, 0xAD323796708178BCULL, 0xC62B934FA9E41381ULL
        },
        {
            0xD9C609E1C01BE68AULL, 0xFF9D00846C9F2474ULL, 0x213B4E6EDBBBB461ULL, 0xB1B0C42D5C05E523ULL, 
            0x52AD2F351E7903E4ULL, 0xBDB0B8C42ECEC29FULL, 0xE5DA8A14EB209FA1ULL, 0xDDAE4B00CF1732B6ULL, 
            0x9311CEC9A0D3D16AULL, 0x1DEF5018328A9D98ULL, 0xB1A582949FF0B328ULL, 0x9CABF17B32D6F664ULL, 
            0x03FC850331FC176CULL, 0x6F650E30F5C5953AULL, 0x8EBDA4E787A1C977ULL, 0x33CD05A40EDC5544ULL, 
            0xD88B1E41E84CAC46ULL, 0x4D80585FECBE04D9ULL, 0x100FD7F28A3AEF0CULL, 0xBFFF8BCCAD8F1331ULL, 
            0xE5D2C451567A0F08ULL, 0x36AE24DD9CB08DF6ULL, 0xF6923254DB9D56E4ULL, 0xD921D968900D7025ULL, 
            0x9FD8BE021EBAAB62ULL, 0x9D116D8BE4B1F0BCULL, 0xE9CF4784CB83D4C6ULL, 0x8D49E3DD1C004486ULL, 
            0x2A8AFA1AA634996CULL, 0xE85D360D37C8D23BULL, 0x8C1D1A43E1B138F2ULL, 0x54E34D4D17AA48C5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseGConstants = {
    0x3C7C3845FA9EC864ULL,
    0x48852AE243B2012DULL,
    0xBB78937BB4087EC0ULL,
    0x3C7C3845FA9EC864ULL,
    0x48852AE243B2012DULL,
    0xBB78937BB4087EC0ULL,
    0x9B601476B96E78CAULL,
    0xF0B9B68C196FF62DULL,
    0x62,
    0x2D,
    0x87,
    0xD9,
    0xB3,
    0x63,
    0x36,
    0x31
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseHSalts = {
    {
        {
            0xA42488F1BA2F595FULL, 0xF6C1B6EA2A925CA4ULL, 0xC2F47DE44EDEF19EULL, 0xA83D3AD682A0C5EEULL, 
            0x43B0F59071396129ULL, 0xBF277D79AE823A2DULL, 0xB62FEF8F3A66731EULL, 0x917E2807157D7378ULL, 
            0x77B8D5D6C5798057ULL, 0x29D0A711B768EAD2ULL, 0xDACF3A2A081F804BULL, 0xF73C94646BA6CBF8ULL, 
            0xA886B0FBF47E872CULL, 0xACD8C74AB963B9E9ULL, 0x8482B4F4340AB7ABULL, 0x54899B73F5A12BA3ULL, 
            0x95B7C30257E3C4CFULL, 0xD4AD225B3BA6D6F8ULL, 0xE8D1B41E5F039B7CULL, 0x76E909B9C7CD8AB3ULL, 
            0xF591ABB76586B80CULL, 0x4920838A93972D57ULL, 0xD294F15AAAAF142DULL, 0xA7DDF43B25113D5EULL, 
            0xA7685EF4282CE8F3ULL, 0x58043887C0733CF4ULL, 0x8768DA9F64ECB26FULL, 0xE039B547C49F6877ULL, 
            0xFD4B07EE29984579ULL, 0x28D270DC6A69D55FULL, 0x297D8E6411ECAA83ULL, 0x29251219BB18945BULL
        },
        {
            0xD252010E60436C98ULL, 0xAAABFD1CF9EE6766ULL, 0xA769A2B5AD7B0D04ULL, 0x64A3B315B67770B8ULL, 
            0x3D5E0858F7031285ULL, 0xB8051376E5A0D279ULL, 0xEB268DCB44BA412CULL, 0x2728731E04DEE981ULL, 
            0xC09E03CB346527EFULL, 0xE9B13B85780EB826ULL, 0x7CD244D35A0D0CF1ULL, 0xE1EB9EE0DD97B3EDULL, 
            0x52AD968205FA90CBULL, 0x20F82880422DAA08ULL, 0x203914C7343E407EULL, 0xCAD89DB487A3EF6CULL, 
            0x4AFAAB3E7068DEC2ULL, 0x2329E55380AB4D61ULL, 0x21F8A5DDAB63AE1CULL, 0xB2455F9B58D7B789ULL, 
            0x3FDC52DAD649CEC4ULL, 0xA4ADC4E22F5F71B8ULL, 0xE741BC5D718DC5DFULL, 0x22723E2B7BC40824ULL, 
            0x29C2D1268AAFAA0CULL, 0x71EFB9A22CCAC008ULL, 0x54478CB945D59737ULL, 0xBDE410D7AF535B27ULL, 
            0x91711AE5CA1DD7E7ULL, 0x8434944615E1A316ULL, 0x38AC399BB892C9FFULL, 0x8188FA52C5B8CDADULL
        },
        {
            0x90F8004D9A44EE79ULL, 0x2303954B0F0EB762ULL, 0x30E368D676954448ULL, 0xAEFEA7DF9F69BA78ULL, 
            0xD5DDF80CEEB685E1ULL, 0x5497A8EEF057250DULL, 0xA676F19D5E07F721ULL, 0x9C010405E2AC8F82ULL, 
            0xDFEE804068BFF062ULL, 0x82151DE2D9B4BA89ULL, 0x3E9612A512C0041AULL, 0xF80FF3886F01025EULL, 
            0xD114A5C33F5BBEEEULL, 0x7092F24CC72D2E1AULL, 0x93F7CB002C2516E3ULL, 0x1B653C82B207AEF6ULL, 
            0xF38A0BD4EAAE8274ULL, 0xA255CBA7C7EBABF6ULL, 0x839D29E94F518AA3ULL, 0x470347C1F782F0F9ULL, 
            0x45AB5CF2827BF309ULL, 0x1D96652141D0B58CULL, 0x67F2FF14C82DF221ULL, 0xC86F2FE2AB0B7341ULL, 
            0x8F400FE2F3718A3DULL, 0xEEB0677B0548C667ULL, 0x653E0890869EBB35ULL, 0x487B069F87EC0C7AULL, 
            0xD52F1B677BA6E757ULL, 0xE44945A449476F47ULL, 0x2329EFBEA4E77C6FULL, 0x3C8F9A860A67C44FULL
        },
        {
            0xF98765BDF0AB049CULL, 0x90EFFBD28B4FF1D9ULL, 0xFE6EC29DFB9F0A7FULL, 0xF97D74FEBEE69B46ULL, 
            0x7C989517296131CAULL, 0xE12467DA8E9A8710ULL, 0x594CC22BF3926811ULL, 0x28DAC364C33968A4ULL, 
            0x2EFD822308B79B9BULL, 0x736C1D8B829D27FCULL, 0xF37B49B6B73D98BDULL, 0xB911C8C7E3ADD529ULL, 
            0x5E83DFAE2E138B50ULL, 0x7969E71E41B71BCDULL, 0xC65BC99C4BDEF53EULL, 0xEA9A2795A1FCF8AFULL, 
            0x47843DA7DFD11979ULL, 0xA585FC361C58493AULL, 0x22F16775644553CFULL, 0xEECB3184C0F543F3ULL, 
            0x5A44AFFA8C397B65ULL, 0xC8606ED24CC931F8ULL, 0x15C5C784B7E7D47AULL, 0x48F588039AEA8B58ULL, 
            0xCE8638EF3258261EULL, 0x892A211E81A2B58BULL, 0xE76F7AFE258B4A30ULL, 0x58BC553BF9581368ULL, 
            0x33AFB9D4EE649914ULL, 0x6A634EA50B1AF25AULL, 0x78CDD6DAD5B34C88ULL, 0xF07F288AA4B2E98BULL
        },
        {
            0x960688E4F1FDA655ULL, 0x30355D9262F9D682ULL, 0xD0317D3C5D850C8DULL, 0xFF878CB27C500348ULL, 
            0xFE0C404F05188187ULL, 0xA612E8F4E45981A7ULL, 0x2F0238A7FFD6908AULL, 0x603F78826014F926ULL, 
            0x53CC899528A25260ULL, 0xBAF358B0E9025F5FULL, 0x94F169B4FF88CE4CULL, 0x9EAB9581426A654FULL, 
            0xD405054BEA6D60E1ULL, 0x3A742E0ABA9F7A0CULL, 0xE6FEFA32ACDE4525ULL, 0x234A1E12874275B3ULL, 
            0x69F921990D3B6497ULL, 0xFF27F1A703685A97ULL, 0x60F23AE516E23856ULL, 0x4C729D38D45DA485ULL, 
            0xA80E90EFFBD82A53ULL, 0x760150ED97EA0DA9ULL, 0xC696C50407F4154EULL, 0x50DEB3F32E6F75CEULL, 
            0x17AEA87287CC9AF9ULL, 0x9BA76A5E0333E20BULL, 0x6D86EE25DAEA0EAAULL, 0xD739E2161873768AULL, 
            0x404D374522705488ULL, 0x43E6831E31D8A076ULL, 0xBA371AAFF26C5BE8ULL, 0x97B60E345BC96328ULL
        },
        {
            0xC439DAD42547CE82ULL, 0x4A9B88DCE299BD4EULL, 0xBE842E55B9935900ULL, 0xC3B00CDD0989A203ULL, 
            0xE0AA092F3002ACBDULL, 0x1F691C8E8AF8D433ULL, 0x696C92C14CB2E820ULL, 0xBF92CF9FC70C1F76ULL, 
            0xC122BF5E0F2AB25AULL, 0xC88ABF1DEC8CBDADULL, 0x12F9D99E9F0D5E84ULL, 0xA6BD8C77C3534B2FULL, 
            0x62B62B0871827A81ULL, 0xFE5CDF290939A024ULL, 0x7962AF5FD78054ADULL, 0xCED5F0BB84712349ULL, 
            0x43A57A710E6913D7ULL, 0xB2A896793523B8D9ULL, 0xEE1D071550540B1EULL, 0x967E8A74A9EF5C6BULL, 
            0x94F72CB4035EF552ULL, 0xA2B98CC235A08C9FULL, 0x9F58593AA79B8491ULL, 0xC7C844C6C5D3CBD4ULL, 
            0xE8F78AEA01C4AC99ULL, 0x96566D2FA0B0F9E8ULL, 0x05B6F40CA865D1B9ULL, 0x823C8F731F45A4ACULL, 
            0x932559F3687C409EULL, 0x6EAAE206E238570BULL, 0xB65BDC808E477702ULL, 0xE9B3D6D8BAF183DEULL
        }
    },
    {
        {
            0xB12F80D600411A1FULL, 0xB35AD41F4CE3DD86ULL, 0x660D3AD21EBE9FCBULL, 0xC88E57BD52BBCCB1ULL, 
            0x240A5710B52A7743ULL, 0xC54C72E141E46F5CULL, 0xAE3E3FA6C25B5F4CULL, 0xECC3EE2A1992F0ACULL, 
            0x284C266182992AA2ULL, 0xCF4225C10E9EAA54ULL, 0x26DC269D2D9868C5ULL, 0xA44205207347182AULL, 
            0x100D1444C3AC6E6FULL, 0x76A31C613700B953ULL, 0xFCDE1FF784FAB838ULL, 0x197271F8ECAB7DC3ULL, 
            0xA99EAED61E6912C7ULL, 0x07D47E4F16563B89ULL, 0x9EB492AAE9859F59ULL, 0x62DC64CF60331C5AULL, 
            0xE6D184FC1DBDC107ULL, 0xF9930686F7D601E6ULL, 0xBC8CBB9B82D72E91ULL, 0x78FA00F69222764DULL, 
            0x4E91ED2A8769B603ULL, 0x4F27366B38EA3731ULL, 0x40588EB7C9C718ABULL, 0xDC0A52249116C8E4ULL, 
            0x852085E15F1A0FF1ULL, 0x18690612288FBE16ULL, 0x39E29F29A3BBBD9AULL, 0xE920332C31687A8EULL
        },
        {
            0x686CB1479892D922ULL, 0x8E62F1F15F694897ULL, 0x85F7B687957DAB3DULL, 0x24F8D2679823C4C6ULL, 
            0xCED4670C9B307F16ULL, 0x3E57933E58BD81BEULL, 0x5A7962281308814CULL, 0x25FEC717542E85F5ULL, 
            0x101F4230CF65B176ULL, 0xA7FE2DD4F36B15B1ULL, 0xEDE736EF623D4919ULL, 0xED577B2DE09FC021ULL, 
            0xA7BDFD7C22BECD5BULL, 0x489461D6CDDCBBD6ULL, 0x4087239EE97E772BULL, 0x3606E63AFAABB816ULL, 
            0x0D68F808DC5D9670ULL, 0xDFC42B1095511DD6ULL, 0x60713DD649173836ULL, 0x9B95ECBF6AB4C316ULL, 
            0x424C6180B6D645CFULL, 0x02F1B8D2F8B89850ULL, 0x6D18CF58AB7568F4ULL, 0x68E4A5B7B6E3261AULL, 
            0xDD6A228727ECB035ULL, 0x4FC95F1B9B9DDC67ULL, 0xEF20B1C8889C3613ULL, 0xD5268B85B7F1875BULL, 
            0xD5923AD7432A279FULL, 0x751560277D788F23ULL, 0xF9B80A8202DA8113ULL, 0xAEC9004D23422AC7ULL
        },
        {
            0xD37410F19E5FC781ULL, 0xF7AAE29289B9C523ULL, 0x9B4817153C1B9E5EULL, 0x59419084263F769BULL, 
            0xD1C1D60817867406ULL, 0x02CF6A53A1DA84C6ULL, 0x2C90E23B8C3FF933ULL, 0x3A9DC20B3BA3DCE3ULL, 
            0xC62A15E696D703A4ULL, 0x3FC8C2D8454C525EULL, 0x7D5CE678BDD520F2ULL, 0xDEFF538E8C11ABADULL, 
            0xAC523B1B9335C818ULL, 0xB2D18EFD7A5A50F4ULL, 0x24CD44EA7356E3B4ULL, 0x402042DFA42371DCULL, 
            0x80BC1C1800BB0A3BULL, 0xB8F1725599C0927EULL, 0xC5271B6EEBF136F6ULL, 0x3D0F858AF9B40733ULL, 
            0x38DCE6C84F8606F1ULL, 0x39F3E4EAF5A59008ULL, 0x53B2BFA51C10BB73ULL, 0xD55151D4181EDBB6ULL, 
            0xF81FB60A40F4B97EULL, 0x99DB52D15D62058AULL, 0x412C518015168179ULL, 0xF53B52C036853BABULL, 
            0x68D19901272655F9ULL, 0xBC299A9B56C1652DULL, 0xC1D165C0BF674B7DULL, 0x917A055FC039EFC7ULL
        },
        {
            0x3A7C10817CB084FFULL, 0x7BF4257CBB9B0EB3ULL, 0x7ECE9FE648D40E27ULL, 0x0176AA3BB9BB301AULL, 
            0xA28652A7649F057DULL, 0x003248D997AEF9CBULL, 0x1EEE96542F25FDA5ULL, 0x81DA6890FCD2190EULL, 
            0x8A917BEB63A8B87FULL, 0x4ABB50A751F62032ULL, 0xA0EF19293D8EDC7CULL, 0x9B0F18490F71AE7AULL, 
            0x15AAFFE68DCF11C4ULL, 0x8C39D4B01366FF84ULL, 0xF8CE9887A917A7DEULL, 0x2E95DF8E961D1473ULL, 
            0xD384DBE9E685502EULL, 0x1D8EFD3D90C97BE3ULL, 0xF8DD7F7ECE47ED01ULL, 0xBF5094A60CB22422ULL, 
            0x6D0034613AE48FD5ULL, 0x0E5807771346F49EULL, 0x8AD0B34233109172ULL, 0x7B45629851CE7C14ULL, 
            0x89D346A229CEE45EULL, 0xBD18725542EB933DULL, 0xC18ED8EAC1A0FF8BULL, 0xFFF340E77FE1EC8CULL, 
            0x3AB837A577715DA1ULL, 0xE2ABF98BD14B5F80ULL, 0x5BE6C925499E9C3CULL, 0x1596C9EA3EDCEE51ULL
        },
        {
            0x684A50690F88702DULL, 0xE94B31BB10D51CB2ULL, 0xD2065B19078396B0ULL, 0x0FE5A77C2221DD6CULL, 
            0xC804F67E939B1D6AULL, 0x74C165EFB2BDCDAAULL, 0x51753B8530587935ULL, 0xA09A859657230F7FULL, 
            0xE2C8AD1415FA24BAULL, 0xBAC4E36B04F3F59BULL, 0xF3FC71AFEA302173ULL, 0xBA21ADDD72F93E94ULL, 
            0x81B4392A86FC1AC9ULL, 0xE708E5FAC081373EULL, 0x8BAAB7CA718D2128ULL, 0x7E1AE8F84977B3BAULL, 
            0xF78969B8669F1458ULL, 0x2C9332E3C25D7CF6ULL, 0x5BCB52881F045D16ULL, 0x54DC6F178DE41239ULL, 
            0x637DF2AB97927411ULL, 0x1F0D8E82FC414E7CULL, 0xDE76FAE072FF1591ULL, 0x21B415CD07268F9FULL, 
            0xF725E6AAA05526A4ULL, 0xD9A7D2FCE7CBDA88ULL, 0xA9A5674799798572ULL, 0x4F6059C4E6826D4DULL, 
            0xA3424150DFEF4195ULL, 0xEB55BBCA0E940BC3ULL, 0x51D849370FBA857CULL, 0x43A267C0F2F16602ULL
        },
        {
            0x6D9D87F6AF3C5F52ULL, 0xD24CE83AF50E17DFULL, 0xCEF32C55E869CEB9ULL, 0x1E1E4168B0188772ULL, 
            0xD7A7DD95ED37EF01ULL, 0x377F469B9A1AB929ULL, 0x57611EA70A1FA2B3ULL, 0xF3D59E18BE23AD84ULL, 
            0x4EF7DFDA8C4D6F61ULL, 0x3D3BEAFC3228758EULL, 0x3AA835D004723864ULL, 0xC3310850E5272A57ULL, 
            0xF9BC3C8562329449ULL, 0x05E53F38D7809FD6ULL, 0x058B501155CFC74CULL, 0xBDB52EDAC7D9F809ULL, 
            0x9158F08AD770B828ULL, 0x26DE6E40C590E376ULL, 0x6F51ED4DA157FCFBULL, 0x52889329784CA426ULL, 
            0xB89597CFD6E1AE20ULL, 0xF869D600B0382B9BULL, 0xE57F9B159475EBD7ULL, 0x870ED0E520945DBEULL, 
            0x662EB1DED3874229ULL, 0x3867732BB4D3D890ULL, 0xE005AC065E177867ULL, 0x1750A50A8CFE984FULL, 
            0x9913E9623BF9F86CULL, 0x1737E42438F03955ULL, 0xD326389EFF54F9D0ULL, 0x83BDADBBFE176BDEULL
        }
    },
    {
        {
            0x4DCC4DA688AF7AE0ULL, 0x9E7C698279DED617ULL, 0x3388F34E9139016DULL, 0xA04A8E9941C46294ULL, 
            0x25C1731A595CA059ULL, 0x3BB062C009B23EF1ULL, 0xBCA33441D885BCA6ULL, 0x46465176EA05533AULL, 
            0xFA6515D0729108E8ULL, 0xD0DBA7397EA08794ULL, 0x93212C9E226D2D27ULL, 0x87C5494ABA0D0905ULL, 
            0x6195FDBC16820C00ULL, 0x604B69511C4E7474ULL, 0xD9D58F0C39705C70ULL, 0xAA1A891075B5E497ULL, 
            0xB158105404029A0CULL, 0x4E837E125EE12024ULL, 0xA2C6C0396B8393ABULL, 0x0D3DC15E18558A9DULL, 
            0x5291B058CFEFCAE7ULL, 0x8F3F5F656FB76804ULL, 0x4D0E0DDA32EBD8F1ULL, 0xB82553A706945235ULL, 
            0xFB9621CCC6895165ULL, 0x046F91EE32224954ULL, 0x57251D0881EF1415ULL, 0x0C50BD8F6ABA1FCBULL, 
            0xE52BB8B26ACADE6BULL, 0x3ADCDE4409CAF27EULL, 0xC04A8CA0680AE8D2ULL, 0xD3E50F1ACC1FDF05ULL
        },
        {
            0x2576EBABF40BCC87ULL, 0xC444741D54113003ULL, 0xF440844437F170DCULL, 0x6C92FAA74133C101ULL, 
            0x6861C0A11C6D5AF7ULL, 0x7391BB52743B7C5EULL, 0xE89133C7215CC576ULL, 0xD974BDD785A1B65EULL, 
            0x2A0F1EF8FED0DF32ULL, 0x5A369A328F76B21BULL, 0x48E85108E9BCD170ULL, 0xCAEDB0668AB4AAEAULL, 
            0x1F715534A109CD6DULL, 0x3F74EA1F68F794D1ULL, 0x3C456C82FA267454ULL, 0x71869E8591A1A6D9ULL, 
            0x5809DC190E2F0DCBULL, 0x9BB1018E7D53F179ULL, 0x74CB12B953E612D8ULL, 0x0734D3F0A4BB12C1ULL, 
            0x312B052102241B35ULL, 0xE414D0BBC18D8927ULL, 0xF2E5F7C79956873EULL, 0xA92DEDE7E5A38D32ULL, 
            0x7BFB308C0CC0133DULL, 0xE2DF9832BEE6DFD4ULL, 0x58E5CDA231D1E245ULL, 0xB9210777CDDABEB5ULL, 
            0x7ED779A7F532E2B6ULL, 0xDA518D0D7F848F73ULL, 0xF6C742FC45C0CE15ULL, 0x4E843121323D4683ULL
        },
        {
            0x0940B0CC242382A6ULL, 0xAF44425B3F12D9C4ULL, 0x97A2546C6D5E3F9CULL, 0x44E1DC583BB4FDE6ULL, 
            0x1F5F4944D0E0E459ULL, 0x1D40DE2BE31CC17AULL, 0xD5F331F83F16DF21ULL, 0x46D634D01E759BC4ULL, 
            0x49DD2CCE85782A18ULL, 0x6E4D0BE0A1B041F1ULL, 0xF68DA1DF353A86BAULL, 0x7A949C88FEF66815ULL, 
            0xB59A809507CCA7C5ULL, 0xAF29D37ED64AC81DULL, 0xCF2EEFFE0060E8C4ULL, 0x3622074EB0F88BCBULL, 
            0x567231BB97472A71ULL, 0xCC3A44839043ECDDULL, 0x6CBB485C593FAD4BULL, 0xC81009E11D1B3524ULL, 
            0xCBCD012FDCFD7423ULL, 0x4632543E5BF130AFULL, 0x580B128724821E33ULL, 0x99A3B9FEBF8D2EE2ULL, 
            0x9D1E30092FE7E06AULL, 0x32CD2BB98A9871D8ULL, 0x201AD1AF1F66395DULL, 0x0889DE8423C974D3ULL, 
            0x070FEA01DA580F92ULL, 0x2931078C477EE03AULL, 0x3455D503DCAD3128ULL, 0xB495065222FCB3F3ULL
        },
        {
            0x96A485C0E310668EULL, 0x3F3273FCAE0B0633ULL, 0x1181BDD2BAD4CE8FULL, 0xE530790ABAE2F590ULL, 
            0xE0AFEC1204114303ULL, 0xB89B60EC7C436F64ULL, 0xACA9217E8A874F31ULL, 0xA1852057745966A6ULL, 
            0x6317918CBC25C66EULL, 0x7AA1A1708DA1884EULL, 0x05A985D5ED934A91ULL, 0xFEBCEE86137C1C0DULL, 
            0xACA54CFCB2495729ULL, 0x02BD811B45A752AEULL, 0xDFC68559ABE79AAFULL, 0xC1F99C9473AFBDB6ULL, 
            0x353B59DF33918BB2ULL, 0x4C38870ADB5FB079ULL, 0x8BBF191AAA2C8E05ULL, 0xFE8FB573F8A7CC82ULL, 
            0x80661E4436C35386ULL, 0x27E5614CD79DB288ULL, 0x0C737EFE23D587ACULL, 0x7C5ABA9E5E19D1F8ULL, 
            0xEC43C98F2704A7F0ULL, 0xBA0E695027831A68ULL, 0x64C9C9673B0E3677ULL, 0x332653D29E2F56B1ULL, 
            0xE590C1F528900DDCULL, 0x2D920AABAD92C356ULL, 0xBD0009B02C27C0C6ULL, 0xE35AA85DFB3964BBULL
        },
        {
            0xA73D4482EBD22274ULL, 0x69D060BA94EB9915ULL, 0x77B3A0FD318A72E9ULL, 0x2604815BCD07B2E1ULL, 
            0xE2B3592803714375ULL, 0xCA9561F079A89EC8ULL, 0x532808079A42FEE3ULL, 0xDD018C481D3FF40EULL, 
            0xE2D5B7526D498873ULL, 0x07805B2FE86C84F7ULL, 0xDA7613D8EBB865F3ULL, 0x8889EA95F8919C74ULL, 
            0x9E81A39FD2B68B41ULL, 0xA53BE69EE700446CULL, 0x26DB7E9CA9198870ULL, 0x453998834D0BCAAEULL, 
            0xF07685124348D7DEULL, 0x3B38983B7AA49912ULL, 0xE467EA0C3EC081DCULL, 0xAC3761ADE91F7E13ULL, 
            0xA0DFF70F6448AAC5ULL, 0x995D2B59EA205460ULL, 0xAF4DAA2B33BC6B63ULL, 0xEF7385AE12A4D940ULL, 
            0x41373900E95573D7ULL, 0xEC985181625EB1A5ULL, 0x74102D1EB67FAE23ULL, 0x54AD08FCFAC61027ULL, 
            0xE1F48AA3C986FF89ULL, 0xE05C2533248BA580ULL, 0x0D5501A5D1FD06A8ULL, 0x5CD98968330446D7ULL
        },
        {
            0x904763AD14611787ULL, 0xCF1903CC678426C0ULL, 0xF867E9715DD45A39ULL, 0x373FFF85BD6EBB11ULL, 
            0xBB08021167120EA0ULL, 0xF43F980629356258ULL, 0xBC055C7412F369F4ULL, 0x5B90A91DD5ADE355ULL, 
            0x44E9E78E0DAAADFDULL, 0x9821F21F9C6412B1ULL, 0x5A55F4FE4B75FA57ULL, 0x819049137D3FF267ULL, 
            0x3C45D30D2A2FF9A8ULL, 0xAD807205EA0B536FULL, 0x0E33E0BC827C1CA5ULL, 0x1B3FA6899B2C6799ULL, 
            0x4E5719C4D8D1CC40ULL, 0x8564483F82473003ULL, 0xA118BEDE24236FDEULL, 0x846A97C67A4B6516ULL, 
            0xDFB6E12841F2AE7BULL, 0x8C9D77FAAAD5BCEAULL, 0xF95AFD2CD3EC4BE9ULL, 0xC8DCA4590D20909CULL, 
            0x6FF81FBEBB9463A5ULL, 0x219FCFF29BE0F222ULL, 0x74E21CBF9198E0CBULL, 0xCBF18EF13D4BE474ULL, 
            0xC16F83FEC6D5EC4FULL, 0x21F1ADD25390D535ULL, 0x686C693DD2C50B8BULL, 0xC082F0C5265BC956ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseHConstants = {
    0x910AF2D57A3B3271ULL,
    0x88B22AC64CD846C0ULL,
    0xF40401F597CC9E51ULL,
    0x910AF2D57A3B3271ULL,
    0x88B22AC64CD846C0ULL,
    0xF40401F597CC9E51ULL,
    0xFF2D766DDFB1CB05ULL,
    0x3B1F7A360CA308D4ULL,
    0xE1,
    0x27,
    0x06,
    0x27,
    0xFB,
    0xEA,
    0x0F,
    0x38
};

