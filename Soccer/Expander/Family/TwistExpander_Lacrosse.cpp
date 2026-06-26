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
        aPrevious = 15171832341642037677U;
        aCarry = 10583135479380866842U;
        aWandererA = 14785762814139922621U;
        aWandererB = 10378189279203976295U;
        aWandererC = 12988468514327134074U;
        aWandererD = 10793696228609994758U;
        aWandererE = 14622028863830180325U;
        aWandererF = 14394085995505754779U;
        aWandererG = 10706865925862990376U;
        aWandererH = 11794081128820244967U;
        aWandererI = 11892130255034975152U;
        aWandererJ = 18349094026830572162U;
        aWandererK = 10722119693899614463U;
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
    TwistExpander_Lacrosse_Arx aArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_BArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_CArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_DArx;
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

void TwistExpander_Lacrosse::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 17501379041912672455U;
        aCarry = 17714431945934213104U;
        aWandererA = 13127869961695035565U;
        aWandererB = 13192364397519824397U;
        aWandererC = 12176377745324808482U;
        aWandererD = 10292809510864473448U;
        aWandererE = 12090892040614665890U;
        aWandererF = 11426912818728970165U;
        aWandererG = 15220380357712052647U;
        aWandererH = 16619361453525856480U;
        aWandererI = 11040736803741196046U;
        aWandererJ = 16116584765313373074U;
        aWandererK = 9925815995921097963U;
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
    TwistExpander_Lacrosse_Arx aKDF_B_AArx;
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
    TwistExpander_Lacrosse_Arx aKDF_B_BArx;
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
    TwistExpander_Lacrosse_Arx aKDF_B_CArx;
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

void TwistExpander_Lacrosse::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneH (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneH);
    }
    // KDF_B PhaseA invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseB invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneE);
    }
    // KDF_B PhaseC invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    }
    // KDF_B PhaseD invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneB);
    }
    // KDF_B PhaseE invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneD (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    }
    // KDF_B PhaseF invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseG invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneF (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    }
    // KDF_B PhaseH invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
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
    TwistExpander_Lacrosse_Arx aSeed_AArx;
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
    TwistExpander_Lacrosse_Arx aSeed_BArx;
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
    TwistExpander_Lacrosse_Arx aSeed_CArx;
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
    TwistExpander_Lacrosse_Arx aSeed_DArx;
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
    TwistExpander_Lacrosse_Arx aSeed_EArx;
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
    TwistExpander_Lacrosse_Arx aSeed_FArx;
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
    TwistExpander_Lacrosse_Arx aSeed_GArx;
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
    TwistExpander_Lacrosse_Arx aGrow_AArx;
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
    TwistExpander_Lacrosse_Arx aGrow_BArx;
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Lacrosse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Lacrosse_Arx aTwist_AArx;
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
    TwistExpander_Lacrosse_Arx aTwist_BArx;
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
    TwistExpander_Lacrosse_Arx aTwist_CArx;
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
    TwistExpander_Lacrosse_Arx aTwist_DArx;
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
        TwistExpander_Lacrosse_Arx aGrow_AArx;
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
        TwistExpander_Lacrosse_Arx aGrow_BArx;
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
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 2 with offsets 1U, 2811U, 6321U, 5988U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2811U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6321U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5988U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 8022U, 1239U, 5452U, 2414U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8022U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1239U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5452U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2414U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 3696U, 4495U, 2793U, 7809U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3696U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4495U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2793U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7809U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 1, 3 with offsets 6302U, 1866U, 7307U, 3857U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6302U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1866U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7307U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3857U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 714U, 1776U, 1368U, 1996U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1776U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1368U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1996U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 3, 2, 0 with offsets 1456U, 302U, 1827U, 296U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1456U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 302U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1827U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 2, 3 with offsets 1785U, 358U, 504U, 1997U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1785U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 358U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 504U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1997U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 640U, 1979U, 647U, 966U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 640U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1979U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 647U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 966U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1390U, 975U, 1352U, 1758U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1390U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 975U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1352U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1758U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 0 with offsets 1582U, 3295U, 7004U, 6744U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3295U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7004U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6744U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 3 with offsets 7638U, 5934U, 6333U, 5666U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7638U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5934U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6333U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5666U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 1 with offsets 2328U, 4780U, 232U, 5865U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2328U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4780U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 232U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5865U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 2 with offsets 5219U, 3335U, 4689U, 5425U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5219U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3335U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4689U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5425U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3219U, 2449U, 6077U, 5657U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3219U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2449U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6077U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5657U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 2, 0 with offsets 204U, 230U, 1095U, 1800U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 204U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 230U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1095U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1800U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 0, 2 with offsets 1424U, 431U, 775U, 2031U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1424U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 775U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2031U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 1, 2 with offsets 886U, 1296U, 1797U, 1248U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 886U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1797U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1248U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 3, 2 with offsets 1452U, 445U, 129U, 1359U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1452U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 445U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 129U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1359U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 169U, 441U, 1432U, 936U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 169U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 441U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1432U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 936U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseASalts = {
    {
        {
            0xF17F3A676FBC0F87ULL, 0x8BBEEEB943B55E1AULL, 0xDE839673A7E920C7ULL, 0x198811D387A333CBULL, 
            0x011316817A939176ULL, 0xD5F1EBDF5C5879B4ULL, 0x9A84596FBA5D79B1ULL, 0x3D64B7FC20C5CCCFULL, 
            0x1CEF6B464E89F61FULL, 0x513E0A44E0F8CBA2ULL, 0x602C1E643321A6D5ULL, 0xE8CAFF87A3890ED2ULL, 
            0xF4B5DE7463FD33CCULL, 0xF7ED7277856BF6BAULL, 0xD830A65967241C77ULL, 0x8F8CF4BE546CD73BULL, 
            0xDDB43A39D552778EULL, 0xFF34A3636184F092ULL, 0xA9EB034089FC50D1ULL, 0x628EA051EDDF76B1ULL, 
            0xA5AB90ACC693BBA6ULL, 0x1F5CE2D41F434E49ULL, 0x4BAB0BD8C75322B9ULL, 0x07F790545E0A4870ULL, 
            0x20EA526F6B80C972ULL, 0xA79F2605367222E4ULL, 0xDEAF246514AFD86EULL, 0x22E5DE14875BA3E6ULL, 
            0xB438284E55F1B9EFULL, 0xD3D81A6649A76C53ULL, 0x1D8FA0AE22C0C436ULL, 0xBE5E45D35D5A8D36ULL
        },
        {
            0x17AA3A176D3FF264ULL, 0xCD4EBDB3372BA129ULL, 0xB00618BA3F44FAADULL, 0x0C4197782FB9E415ULL, 
            0xB6A77465E0932647ULL, 0x8D3DB95D2AB77205ULL, 0xFBBFD6157BE015A5ULL, 0x2ADB310C359DAE3FULL, 
            0x8D0D5B589FBA2422ULL, 0xDE169CCF70A34312ULL, 0xAB3536AF70CC2543ULL, 0x80D740CF2F002548ULL, 
            0xA2CE3005D31389A1ULL, 0xDBC5D776B4DC8950ULL, 0x1D6F1B874B40A9F9ULL, 0x0FB0E690F32E4844ULL, 
            0x7A2129386B43B7A0ULL, 0xB1D1BE9E355AA785ULL, 0x50139E1BF8B9180FULL, 0x813C1108F896F24AULL, 
            0xBF189B542FBD343FULL, 0x5711D2FCF8C7B46BULL, 0xE9BB0CFC81E9C8A2ULL, 0x0165D040F19F3AFFULL, 
            0xD7B6BFAB34010947ULL, 0x34D41D71144AAADCULL, 0x2CA80EAF2204DFF9ULL, 0x3424E5BECDB64CCFULL, 
            0x47CF0BDC0CD20E5FULL, 0x2FB8956EA9EF65CEULL, 0x33E8BD759C55627EULL, 0x4081C6FC319F4FFEULL
        },
        {
            0xE5F2D30579163FEFULL, 0xD8343D9E74C3B3ECULL, 0x1CFE135B8C4F7001ULL, 0xAE7F0A08AF96E52AULL, 
            0x15586B19A819121DULL, 0x42DA0F6D20BD56E7ULL, 0x8F988F43092CD2D3ULL, 0x5CC6952F0DC7C502ULL, 
            0x899C98B8E1C71AAFULL, 0xEDF44822AEE6BD76ULL, 0x2FBB86215362FA0CULL, 0xB59A8F139D7F1085ULL, 
            0x2782F0C839FFFE9BULL, 0x847ED7F7F7A2FB56ULL, 0xE8324680E5CE4E4BULL, 0x0B8C2BB2375CB294ULL, 
            0x87F7EAA76A1F62A7ULL, 0x723AEBC7C0527448ULL, 0xF8705499C6A0B37DULL, 0x5944B78BFFA5DD08ULL, 
            0xE6C5E98C637C327DULL, 0x6D32E13A6D07A7E7ULL, 0xF8A263814BD0A79CULL, 0x9B34E7B57D739B0CULL, 
            0x3BA09827A8F320F7ULL, 0xA365D19DC3DE8FD3ULL, 0x2E573E7B016D6A13ULL, 0x09232F580956A44BULL, 
            0x4523EB1911EA9319ULL, 0x63393FD0A026A77CULL, 0xC8405E58A5AA9DBBULL, 0xDECA806191BDD83FULL
        },
        {
            0x6EA18B89CB481888ULL, 0x19A5547096A997EFULL, 0x4497F13DEAAABC56ULL, 0xC53C4896D55E3FBEULL, 
            0x3F10286D1684C022ULL, 0x121B71F37EDE5891ULL, 0x4B903768403171C6ULL, 0x5E9FBDC5701FE3AFULL, 
            0x2B1877D8DE5174D0ULL, 0x2DF1E9920461E6B9ULL, 0x0E60C0ABFAC78C38ULL, 0xF7832486EA77B517ULL, 
            0xB49DA3577119562DULL, 0x7E9A40A5208CC135ULL, 0xBFCC9953FC59A15CULL, 0x8DEC2A8EE1D8607EULL, 
            0xB7D40273570FDF38ULL, 0xE404E5E20D95D5A3ULL, 0x9B50FB4EB95B20BBULL, 0x0E2936099A8C5FD9ULL, 
            0xB5AFF4651CBC2CFEULL, 0xB9260A5513151664ULL, 0x080BCDBFD3E40553ULL, 0xBF3D08CF7D471425ULL, 
            0xDA6E7C77EDB24B6CULL, 0x3F6FD62AD37846ECULL, 0x61FFFF3440C381DFULL, 0xA8AB8F16FC412A6FULL, 
            0x584BB82F63055C69ULL, 0x7EAD156DCD98D876ULL, 0x2E2D5AA71A449092ULL, 0xC776B84548E3DEADULL
        },
        {
            0x592DEBDB0F4C35BFULL, 0x65BD07223B8EB0A7ULL, 0x37EC3DD97F101A86ULL, 0x1A09F4ED5DE4FDC4ULL, 
            0x760C069B21BACB49ULL, 0x71E6A9B8560034BDULL, 0xB429BB4F8BF47B3DULL, 0xD809213FEE958C17ULL, 
            0x4446191DF5C84C97ULL, 0x407FA1690F403752ULL, 0xF17F44DA1E69C08AULL, 0x7BD38B4B48F1E415ULL, 
            0xA10C58680F898294ULL, 0x1BA15C9A78BCD86DULL, 0xCA50F368851C4C75ULL, 0x261662344158714CULL, 
            0xE76DFDE1EAC66500ULL, 0xE543C75CC4A28B36ULL, 0x445492AE791431DDULL, 0x8DEE1D607CAE494AULL, 
            0x1274593794003C8DULL, 0x62C43AA5CCB2AED6ULL, 0x04236C433C48F47BULL, 0x99548DEE080E9ECBULL, 
            0x04754E13CA363858ULL, 0xA2FDC34BD80176FCULL, 0xA25B89073448DF34ULL, 0x7FB5C04864D97ABCULL, 
            0x2D94C59DBE9A009EULL, 0x26483A297E8A10CFULL, 0x51254424CBC960A3ULL, 0xE33F009ECD44064FULL
        },
        {
            0x453341A4EEC8C215ULL, 0x0099FE6688BB2236ULL, 0xD4BD3BD36064E97DULL, 0x6C9310AADC845590ULL, 
            0xA3342110359E399EULL, 0x098FDFBFDA7F9AE4ULL, 0xF7FC1C8F259C8314ULL, 0x50177AFB5958CEB8ULL, 
            0xB7A9BCDE5688437CULL, 0x4755D8D04EF3A453ULL, 0x5E15D8B33600853AULL, 0x4D47BFAE53C5CA1FULL, 
            0x0DC72FB596C5F784ULL, 0x2EB396D92BCA1565ULL, 0xD08170E1D56DA24FULL, 0x57213EB62DF776A6ULL, 
            0x04FAB40208A5863AULL, 0x0D33C35A09529D7AULL, 0x76985F871ED74756ULL, 0xD84822EE1CF91BA2ULL, 
            0x94B7E368054CA06EULL, 0xED02838722177059ULL, 0x10D538F11B958069ULL, 0x97D9EA05D1A53C37ULL, 
            0x13FC4CA54A91C10EULL, 0xCE72B27372D1B74FULL, 0x48E022DEE611F70DULL, 0xB8ACECF533AE06FFULL, 
            0x607B4B5CCC67A596ULL, 0x143049AC94C96BBBULL, 0x6A31DEDD969E2E75ULL, 0x0AF64E3A4EA479F3ULL
        }
    },
    {
        {
            0x17D01145F1FE6438ULL, 0x4D3079E34125D12EULL, 0x1C151BB2CD83425CULL, 0xCDD532F769672F48ULL, 
            0x1F1AF9FC575BA13BULL, 0x40A350F8047D30E4ULL, 0x072901184E72ED46ULL, 0x85D907289EEFCD8FULL, 
            0x925A2BEF9B545409ULL, 0x3D3BC13B1CD9178EULL, 0x70BC98460C443B41ULL, 0x8ACBFF3DE0A69450ULL, 
            0x9576AB7FA797DF3FULL, 0xD1CD5C3B2DE64EFEULL, 0x8D0E26D898B76EA4ULL, 0xD0EDD36129E30258ULL, 
            0xEA2D6F2F4FCCF91DULL, 0x0FFE4C502F21FC3DULL, 0x1A1E7017CC9F594CULL, 0xE89CA6A9351279A3ULL, 
            0x645519F44021ACE6ULL, 0x9851BD63F72B1DA9ULL, 0x57AB1C051C870707ULL, 0x20C4C9118805F121ULL, 
            0xCBF0399D0EEE8233ULL, 0x1BB23436F0D901CFULL, 0x05AB2D6E56EB677AULL, 0xF7644DD8A988AC67ULL, 
            0xAE91ED1A01E67BA1ULL, 0x0FB1BB2E2EA76FCAULL, 0x7F446E40532D1C4FULL, 0x43CA06E4CA3B1927ULL
        },
        {
            0x0C145600E2FD41D6ULL, 0x3215B45C01D0893AULL, 0xAC71CB04E2CBA56BULL, 0x96A5D7483419AA5DULL, 
            0x387153F6F52B7FA6ULL, 0x656E0473669FD461ULL, 0x85E444743C1204ECULL, 0x0A2690E28CC2FCFDULL, 
            0x81DEB231AEDC4CC6ULL, 0x3290CC04E24F1514ULL, 0xF28F9599F9B1D9C7ULL, 0x6463AFB0FD5E870DULL, 
            0xB33CE1FC01442574ULL, 0x39CD6C654B3D9D5FULL, 0x64FBFB2849E12DFFULL, 0x58453172C2EE25E3ULL, 
            0xE67CB3096216CE94ULL, 0x565A40E67124430EULL, 0x6BC8CBDBEC315DCFULL, 0x8A9C02733CAECAF7ULL, 
            0xB3DB1A54278994A4ULL, 0xE81EF689BADE0801ULL, 0x66C2AC447CEFEFB5ULL, 0x1BA6969ED82A4A4FULL, 
            0x9156488B64EDD574ULL, 0x2DD718CC4581D794ULL, 0x2AEA3FA101AFF459ULL, 0x373C858EC99E21CCULL, 
            0x7FDEC427553051ECULL, 0xE3E1BF2F42A02B28ULL, 0x273F83C33AB490C7ULL, 0x939E1E230A163335ULL
        },
        {
            0xDB51BCF54F97ACE3ULL, 0x77AC494895ACF2D2ULL, 0x35C50A1431D7E969ULL, 0xC69F362A6D875F16ULL, 
            0xA580870468CE97BDULL, 0xEB0BA8F4EBCC9441ULL, 0x080BBA8BB02CD65AULL, 0x8A8B2AF84BB3C92EULL, 
            0x0A0868F27B2EEE38ULL, 0x16C6384363F14CF6ULL, 0x15369E4F7D0FF23BULL, 0x8EF890F0068814B8ULL, 
            0x1E276B1FFC63BD1CULL, 0x5DBA691B8AA6CC2AULL, 0xF0DEDFF0E7C40EAEULL, 0xE756340FBA4C1AE0ULL, 
            0x92B81CA77CAB9C7CULL, 0xC72C67DB2300D39DULL, 0x09A74448E4112AE6ULL, 0x758287D5AE14E505ULL, 
            0x43D8C5EA09770B57ULL, 0x53EEEB0E59BACDB2ULL, 0x6B52D34A05155C68ULL, 0x7CB56AE62D1F99A9ULL, 
            0x03432A4124959931ULL, 0x91E77A5B2CE58F5EULL, 0x5E129186246B50A3ULL, 0x3BCB547FD24FF302ULL, 
            0x279A3CA7D0ACF11BULL, 0x8F20F663F0D88893ULL, 0x5A2F659D26DFA31FULL, 0x4A16BD04F3FDDD61ULL
        },
        {
            0xE5DEFB520A5DB4FDULL, 0x643B1399C8E96129ULL, 0x6307487FAEC01FE2ULL, 0x70DE6449A2B42A79ULL, 
            0xBBA98AEF0EF4DF53ULL, 0xB70A6B81ECF91539ULL, 0x08694D795B0DD844ULL, 0x90E7B8295753B805ULL, 
            0x78945263987950EFULL, 0x179DE888EB4CCE80ULL, 0x965B0F0AE0344A7BULL, 0x68A2AB7CAC323C57ULL, 
            0xF86DAA44B30F5C5CULL, 0xD4861D7393BEE3B9ULL, 0x62706AA4E4535F24ULL, 0x718AD4944E44DB39ULL, 
            0x118A3BFEB8939922ULL, 0x728F1ACB756F6C70ULL, 0xF462D08B768F2E3AULL, 0xDEC3575716E34210ULL, 
            0xD4DC00970856E9AEULL, 0x8A84D2DCF1C4EDC5ULL, 0xDC40B48E4B694966ULL, 0x39B692C648476BDEULL, 
            0x7AB67ED383E31BCFULL, 0x2CD0D13B1597F365ULL, 0x776A62FC5178C16DULL, 0x218CF1E97C2AFB5FULL, 
            0x1E3CD0AF6998DF9EULL, 0xFA9D54CDB6CF5689ULL, 0x8AE9B9C1293C6A9BULL, 0xBB0C7C4BD62A5AA9ULL
        },
        {
            0x42C100EDDF84C3D9ULL, 0x179A9F00B78AD915ULL, 0x4DFA69EF820FCB6FULL, 0x0B6B77D38EDA62BDULL, 
            0x0150C151CDEEC899ULL, 0xFC30D01D0F6685B2ULL, 0x4A621F86FF84E395ULL, 0xFF62D6FF594A713BULL, 
            0xFE4E2C8D265E7AAAULL, 0xD73E45F047ED62D9ULL, 0xEF061D9A3370F74DULL, 0x2934B1A85C589571ULL, 
            0x090BFA4898F4B42DULL, 0x47146C72AA632798ULL, 0x3B16DE75690D541CULL, 0x6A913338B5CA5792ULL, 
            0x6514B427F1896FE4ULL, 0x9A19EB3D432ADD4CULL, 0x70DCFA9BE4605509ULL, 0x3F57BCD55CEFE13CULL, 
            0xA2217FC17294CC6FULL, 0xA53222D66D16799BULL, 0x4EC881ACD89AD8DCULL, 0x44E6EBB65A8728BFULL, 
            0x2705D7204B9553C6ULL, 0x525224122FADC700ULL, 0x85996794C151D905ULL, 0x812D96C78EF9D738ULL, 
            0x482CE8CE81FD6AB1ULL, 0x4F52648A14ACE859ULL, 0x62ACFD107DC2CE80ULL, 0xF2DC3C2A6ADDC112ULL
        },
        {
            0x2263FD2EB575F519ULL, 0x2521D86BB070FC18ULL, 0xE5660DCADE719ADFULL, 0xCB8C7AD25C311067ULL, 
            0x950349C7C58C60CAULL, 0x5A8FCD26DBA8F5D3ULL, 0x81649062FBEF270AULL, 0x951E622A27C55FE7ULL, 
            0x64663B1AEA240873ULL, 0x6DEEE4272811CB6FULL, 0xC4803E828C8FF8E5ULL, 0xBFD36EB9545A2197ULL, 
            0x8FBA2FF073C77175ULL, 0x80FB76D806EDE752ULL, 0x37138215172E63F6ULL, 0xD4A89C14C3F6B84FULL, 
            0xDBA44380C45AB379ULL, 0x1D3E73FA0406B51AULL, 0x6956F67F08F0D4E7ULL, 0x373E60DDB05B3C74ULL, 
            0xB73C2A58C5AF2114ULL, 0x7C90A2F87A58A9D6ULL, 0x293E1EDD3EF0A746ULL, 0xB830F13F559FDB1CULL, 
            0x121C7FE13EE2943CULL, 0x4229FF15BE2F462BULL, 0xE156392048F5D126ULL, 0x325F973A91242CB5ULL, 
            0xA88BD8F5DF61AC55ULL, 0x26FFAE1B85336E4CULL, 0x392BE6914D647002ULL, 0xD750F6AC2AC5A69EULL
        }
    },
    {
        {
            0x39E68F96E07155D6ULL, 0x1CC5043E4D52F314ULL, 0x95B6BB3F932CBF9EULL, 0x33F8FB498D7A50CDULL, 
            0x67BBB3CEC05A5687ULL, 0x964144621084D0FEULL, 0x5650FEEBB9CF3DE2ULL, 0x6F232B682AFCD701ULL, 
            0x2B729A1DA208AC0AULL, 0x7A430A1C1F0D57C4ULL, 0x8AE7EF9ECB175D9BULL, 0xAA545574BA295953ULL, 
            0x6449AB73C366FAA0ULL, 0x5ED883E8B0AD90CFULL, 0x8263E37C2883B026ULL, 0x53516E0FBA9D98A4ULL, 
            0xABC0CD299988C473ULL, 0x47BBF5D90D3D61B4ULL, 0x77AF496C8F7102E0ULL, 0xD71AA7FB891761A0ULL, 
            0x09C7496EB38312C5ULL, 0x317AB7DE066DADC5ULL, 0xB59D7000821171ACULL, 0x787F0A40A026005FULL, 
            0x43DB931714B85FB1ULL, 0x2EAF3BF28922C7A6ULL, 0xE4C4AFEE6037A6B9ULL, 0x0CFBD4CDBBC97A63ULL, 
            0xCA77E9D0E351C479ULL, 0x7B16D65200508EC5ULL, 0x32CEA3E45AD62435ULL, 0xAA37135987CC5DC8ULL
        },
        {
            0x5FA3F27CB2A2D975ULL, 0x211FF82B50452373ULL, 0xCACA5C280EC2D5A2ULL, 0x25AD30ACC1856A03ULL, 
            0xE325A05B918B5DB7ULL, 0x61DF8B96EEAA6315ULL, 0x45BBB209921617B5ULL, 0xC587EAC74BD71EB2ULL, 
            0xE1AC36395311DE5AULL, 0xECBF8E665DFF9DABULL, 0x7D2EBAF2B7E60B2EULL, 0x617A492FD969FB95ULL, 
            0x708ADA2ED6BAA7BFULL, 0x73FF68DE637A1989ULL, 0x0FC84AB0738413F0ULL, 0x025B1757738E8231ULL, 
            0x5854A480E5DD9089ULL, 0x87040108847F683AULL, 0xEDEF0AC773B1FCCBULL, 0x05B7485998D3794EULL, 
            0x5BFD2F8BA6E5541AULL, 0x2825F87ECCE49A15ULL, 0xCA84F480965E9D1BULL, 0x970EEE8DA21BE888ULL, 
            0x7095B953DBFEC473ULL, 0xAE27DABCC35B80BEULL, 0xCCC03E8269781ED1ULL, 0x27CAECD360574921ULL, 
            0x98D8C4B2EC46CD4BULL, 0xAB9D0EEC97330EE1ULL, 0x4060C165FFA47B97ULL, 0x22421D8399860C36ULL
        },
        {
            0x93D55EDA576CD7F8ULL, 0xA3FE902C0B763383ULL, 0xFA8AC12A3E426CD3ULL, 0x71BBE4C8E0B089C1ULL, 
            0x8989793EB15E7892ULL, 0xD94C41DB4C7D3449ULL, 0x76B0E7A630A1B45AULL, 0x14B503B62FB359C1ULL, 
            0xC5415551BFF434D3ULL, 0xBC79A5500FF39A67ULL, 0x8D5EFFD7F1DCC28BULL, 0xF6ACFA4E54EA3B0EULL, 
            0x56FA42A0D4F10DE3ULL, 0xE29FB5510742F0F7ULL, 0x415431722E447671ULL, 0xAA21DB83911D4F2FULL, 
            0xB10DDD88FB62B87AULL, 0xA58B1649BE843D07ULL, 0x742088F408ACEA73ULL, 0x15D27B673AD15A62ULL, 
            0xCCE7698C851AAF41ULL, 0x17C0D19E861CB16FULL, 0xDF8C9DD1E86E66E7ULL, 0xA8ED726938ABA3FBULL, 
            0x1360ADAD8D8187F7ULL, 0x28A515B2A54E1995ULL, 0xBDA1D9FFC684BE7FULL, 0x0D7F2E8B55349BB6ULL, 
            0x6D280DAFEBAED525ULL, 0x9196356C424DA8DAULL, 0x768BC0429075A0B7ULL, 0xF11D935D66B4A21FULL
        },
        {
            0x4B484ACF072B4BF5ULL, 0x696A99065128DAD1ULL, 0xA907F8623BAAAA86ULL, 0x4B7986C3C8D845EAULL, 
            0xEAA549262C242120ULL, 0x9C4B134CD5C86F2DULL, 0xE5945FFEF92DF200ULL, 0xFDA983383793A899ULL, 
            0x3576CCCCE655735BULL, 0x79DA45AFDCAB35A9ULL, 0x6E6EFC5B08A13330ULL, 0xBE443C1EDE2B5506ULL, 
            0xFCA38EDA41E243D7ULL, 0xFA73EC5C3763546EULL, 0x355616AB963F6393ULL, 0x47F3B03C93BFA5B1ULL, 
            0x95CF3E999ADF3AECULL, 0x0079350479900111ULL, 0x66967E7347052890ULL, 0x49245A56875B246FULL, 
            0x7F3F0D7A6A31709EULL, 0x16BF626B4B58C084ULL, 0xDBFB2B9858EE84B1ULL, 0xA803C53662D52CD4ULL, 
            0xADB1F7551770B85CULL, 0x22D5F4C731A38A78ULL, 0x9EDC9D2BA44625B2ULL, 0xDFFA8FF264EC83F0ULL, 
            0x441EEF5E0A62FD40ULL, 0xA4863137AC50FCB1ULL, 0x0460CF8D3DDDDCA5ULL, 0x40FD678D1CADCB3EULL
        },
        {
            0x175ECC157A1312FEULL, 0x380FDC042D76EBB9ULL, 0x2BDCF39B55F681A2ULL, 0x4CC67EF89C51D7CDULL, 
            0xA0CFE281FC2952E5ULL, 0xEEBF958330A7E3C0ULL, 0x4CC0F786EAE39F9BULL, 0x12D27A3E352FC611ULL, 
            0x9A4B935E8FFC8F9FULL, 0xFFAB3D315CD6ADB1ULL, 0x5A9845ED3C8BEC4CULL, 0xCF2E4FD47FCFE8C7ULL, 
            0x6E5811B1ED5ED868ULL, 0x6A4373482C4B8093ULL, 0x35FF05B507DF112DULL, 0x41237793C9204918ULL, 
            0x9903E1B1232F254BULL, 0xB8C001B87EF40663ULL, 0xBE9F69D8519D3F97ULL, 0x4E05248C9258B711ULL, 
            0x67A07F2271BDA2BCULL, 0x007F0D97DA9ECE03ULL, 0xAD76EB441430E008ULL, 0xE8D758F2E1F448E8ULL, 
            0xFF15BA2E341BAF2AULL, 0xB5305CA482800D13ULL, 0x81F94C5FA008A42EULL, 0x520E1CB697C2E81DULL, 
            0xDC83DF950C20493EULL, 0xFC96E06B3D64861AULL, 0xBD2EB27B3AAE43A6ULL, 0xDA7756291BF61906ULL
        },
        {
            0xE9EFCD01C2111CA1ULL, 0x9AC1A3E6F0016EECULL, 0x581BED99B300A766ULL, 0xF742966906F3E018ULL, 
            0x313E151B306C67D1ULL, 0x4E3A71B4924919EEULL, 0x9D06EC1F6CA642ECULL, 0x555BF8BBBE981D7EULL, 
            0x028971A89044E4FCULL, 0x28CA2FE30C0A611BULL, 0xB9590759E7081D90ULL, 0x04003503877059B7ULL, 
            0x45DE9F543826AEF0ULL, 0x5AD69A2930EFB6D4ULL, 0xD5796F48AB6B02AEULL, 0x2FD2AA39A02361DCULL, 
            0xD58DE37C655F30E7ULL, 0xA7B971EB66503281ULL, 0x18681D1FFC924FCFULL, 0x3045AD9446B2BF68ULL, 
            0x3D4C29AADAE3D8BDULL, 0x1D93632E0E5A0F52ULL, 0x6FE0F78BD1CBED01ULL, 0xB97259ABD2E0813DULL, 
            0xA43AE24EFFFF76F3ULL, 0xEAED8B26C30A0319ULL, 0x475B174D4E7E5678ULL, 0x72BAE39E84A18B81ULL, 
            0x0049CA3214D6950EULL, 0x3C6F29B8E6E9CFDEULL, 0xF08CBF283BA25C1DULL, 0x0375EA8ED11DFF73ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseAConstants = {
    0x8D64C9C1C0156058ULL,
    0x094AA5A04E240A99ULL,
    0x2D6A8091EA42FEBDULL,
    0x8D64C9C1C0156058ULL,
    0x094AA5A04E240A99ULL,
    0x2D6A8091EA42FEBDULL,
    0x6360FC972E7D11C0ULL,
    0xD13B6109C39E950BULL,
    0x1E,
    0x5D,
    0xD2,
    0xD3,
    0x8F,
    0x56,
    0x60,
    0x61
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseBSalts = {
    {
        {
            0x35167EFE648192B2ULL, 0xAEE57D41BFFB45FAULL, 0xEE5383D70AB35234ULL, 0xDD58FDA88C5B86BAULL, 
            0xA5F7C9C825D1FD2EULL, 0x4C3186B169189A3AULL, 0x0F3B25EFAA064B68ULL, 0x5C0D9ABDDD3CC91CULL, 
            0x3CE0246296B0EA38ULL, 0x74F1E9E5069BD5B3ULL, 0x929C420EF911DF6AULL, 0x254C286CF0FE5409ULL, 
            0x196D3A9887C04D05ULL, 0x83EC9A74DBF666C7ULL, 0x66E272588B04DCB0ULL, 0x8270F269EB8F2609ULL, 
            0xBD60344720EA9A8DULL, 0x96CC819FFA37C35BULL, 0x780CFFB3BEC0B183ULL, 0x0BB6721193A9082BULL, 
            0xD197C39B8EC37231ULL, 0x9454D92667D8644AULL, 0xA43CD433E59AB38AULL, 0x07A82624711108A9ULL, 
            0x74ACB61BDF3D8EB4ULL, 0x2FF8833362AC44B4ULL, 0x9180EE7070519FE5ULL, 0x7389690DEAA54104ULL, 
            0x51229B27A90914C0ULL, 0xA72E40AD054BE5F5ULL, 0x632BC4D0D9262CE8ULL, 0x36C8B7A0B6394741ULL
        },
        {
            0xCDFE63A3FE6ABBA5ULL, 0x514202C3F59107B4ULL, 0x316CE89D5ADA47AEULL, 0xE7AC8B163414BC4CULL, 
            0xD9473A14F3D827C1ULL, 0xFE009B1E92AC5905ULL, 0x5CF0D0AAAF4FB340ULL, 0x215BDABF52488D55ULL, 
            0xDF4C46194208AAB9ULL, 0x0E180E13C65AE9B3ULL, 0x20DAB899F2BB24DAULL, 0xBD04583B6C5FD6F3ULL, 
            0x21F63D735549EA46ULL, 0xFDECA646C253CE49ULL, 0x9F7D7709140AA45FULL, 0xA99866680814F4A9ULL, 
            0x1BD0CE250F4A7819ULL, 0xCD9FBAE8013A3B1DULL, 0xDD9A5F7122118241ULL, 0xE8CE59D9A1F413D9ULL, 
            0x6142BF167DF61BBDULL, 0xE3F7B5C429F7C752ULL, 0x95F3EFE7741F4DD4ULL, 0x84415C32785D17B5ULL, 
            0x49896AC65F824528ULL, 0xE4C8E993350537D2ULL, 0x3521CFFE187142E1ULL, 0x621F9131BAEF9CC8ULL, 
            0x8210911F1BD99C71ULL, 0x29A730BE187BE054ULL, 0xA8AAD782B785F77BULL, 0x749D8EDCB4532270ULL
        },
        {
            0x95E4EA58947B17DDULL, 0xE59947E50A504699ULL, 0xA854788EA555DD21ULL, 0x61EC7A5F1A8BF26FULL, 
            0xF507720969E73BF6ULL, 0x5E67CC24A54074BAULL, 0xA0A03D2A49A7E9BCULL, 0xDBBF9DECD0590756ULL, 
            0x29B81A9D09421647ULL, 0xE43C5F64D6E84851ULL, 0x082FEACDBB4CB5FDULL, 0x0AB8E52E068C3C94ULL, 
            0x0E50F627EBBEC4E0ULL, 0x092F48E8F9DB597CULL, 0x0F130BF512C45EE0ULL, 0x5ABF4C9A3D4E1112ULL, 
            0xF83A087BA551F714ULL, 0x3501C3D292E21083ULL, 0xC348AC23823C889CULL, 0x27812B5F90FCF1A6ULL, 
            0xAB43F4865CCA09DAULL, 0x7B03B6352913D5F2ULL, 0xB0950A57F1825035ULL, 0x4D1A77732C6DABECULL, 
            0x9385C6D0167BD064ULL, 0xFD32A92525110592ULL, 0x3D3234686901D3ECULL, 0x827F9D3F3FA9D396ULL, 
            0xACF9133FCF218265ULL, 0x149D5926ABBAEF92ULL, 0x6F0DA9985EA6BADCULL, 0xA5AA0F7EE2A596BFULL
        },
        {
            0x3497F1F72A9913EBULL, 0x209AA649ED7CA803ULL, 0x4D06D081705FD997ULL, 0xB6D61EFC53343A25ULL, 
            0xBC4E2FE34C25E915ULL, 0xBE96708F94795C1DULL, 0x2B7851E163728DE6ULL, 0x6689CF3CB71378ADULL, 
            0xDFCD93422EA1BA67ULL, 0xAEABE4F3B595D545ULL, 0xE9E430B6810ABD8AULL, 0x4F0D4A6B35383200ULL, 
            0x9B1837AEB16CC5B9ULL, 0x6B46428EADC76B84ULL, 0x73FF8B1E2C317CF8ULL, 0x9C61A14BE31A5C0FULL, 
            0xB5E65F0FBAFF632DULL, 0xA683A97F40F0D60CULL, 0x16B1E383F49F206CULL, 0xFD487AF830B263DBULL, 
            0x862A0924BFBE381DULL, 0xF5CF6E5746F7772EULL, 0x95E2CE608E1B3ACEULL, 0xF06E31286D25E451ULL, 
            0xED5EE7AE528D1E38ULL, 0x1C5F001F796DB360ULL, 0xACA7A01A2942097BULL, 0x33AB6B7A215D4714ULL, 
            0x6481C19E1719630BULL, 0x7BD418503A3D3973ULL, 0xF0CB8CCA9733EAACULL, 0xDDF29823E390C4E3ULL
        },
        {
            0x4B4AD6EE4F7FB39AULL, 0x8974F4AE92D25DCEULL, 0xE8D0A89DABBFDD1DULL, 0x620E4D905A4564C7ULL, 
            0xFEDD1F35ABE970E5ULL, 0x3F673A5B30AE9BC6ULL, 0x4D98B5FE531DD5B7ULL, 0xD1EAA8DCD780179BULL, 
            0x7157CFF2EDF0F839ULL, 0xFC62C4C5E045A74BULL, 0xBFA507C9D8862AA9ULL, 0x75F0EED89E85BD54ULL, 
            0x93B14FB171CD9B87ULL, 0x5827BBAA23D654BDULL, 0x87488DFEB008E794ULL, 0xF66A63B006B9BB85ULL, 
            0xF9DB4B3A5E313844ULL, 0xE11401C26ED0012AULL, 0xD52B918E238D4B2BULL, 0x9620071A1CF2A58FULL, 
            0x49251C8830CD14CAULL, 0x7EFA3B3A4D3B0191ULL, 0x067EF3EEB8568FF3ULL, 0xD6989CD08848DDB8ULL, 
            0x62746E32A3C9A331ULL, 0xED81A2798EB94C9DULL, 0x1A7BBF2098B283AAULL, 0x913CF0BDB80806EEULL, 
            0xDC609ACD42CC2648ULL, 0x20F13B9138637C6AULL, 0x387B8ACC730A11ACULL, 0xD32A2542F46DE990ULL
        },
        {
            0xEBA4DAF67C065FC7ULL, 0x561B22E89008E887ULL, 0x660C9EF7D135957FULL, 0xAD61A582AA0EF2FCULL, 
            0x81E90644E641A625ULL, 0x5D41D8E5ACAACCC1ULL, 0x6CB8E060B1046768ULL, 0xB0F1ECB4EA6CE8EFULL, 
            0x83EB2721B4288CFFULL, 0x83C950DE5AD2B6EAULL, 0x388248EAE4E2B9D3ULL, 0xB2984D72F7B6D962ULL, 
            0x5E73FEE44068F9B1ULL, 0xAC1FAC7C4723E215ULL, 0x5DB6FD55EAE8C56DULL, 0xD6128AB650555E13ULL, 
            0xF721E178BE6546E5ULL, 0xE04BBE47C948ABDEULL, 0x364D83462E385033ULL, 0x5DC6551921EA3D11ULL, 
            0x552063ED5CD29170ULL, 0x840F9E0D17BDB83DULL, 0xD77C3481AE1C75EDULL, 0xCBE7DB9756A82F09ULL, 
            0x20754EDF5EE166C5ULL, 0x228778A3219FD5CFULL, 0xB67A55195049E49BULL, 0x4248685B6C86630AULL, 
            0xD77A1B5E36DC31A9ULL, 0x928E8465D0BA71DCULL, 0xF557D2DB38B4804DULL, 0x6FA1FF2A1C5E4D32ULL
        }
    },
    {
        {
            0x58267E5519C7F2F0ULL, 0x994426A4B9010047ULL, 0xAF4085D969565330ULL, 0xA3374A386816B5D1ULL, 
            0xCC974065D69D83B7ULL, 0x6DB930227DFE35ECULL, 0x8CE6105058060390ULL, 0x3AB10BC8A4409FEAULL, 
            0x1D1C36A10D5A6C3EULL, 0x5AF31B07105CBC9AULL, 0x68106F09C1E0B225ULL, 0x58C8D7ACAA7B1810ULL, 
            0xCC0881496EF5E21BULL, 0xCF810E3AE239E989ULL, 0x73C1CCB273C6DD87ULL, 0x547206771DF36EB2ULL, 
            0xD1F67275C7A1F046ULL, 0xD9CD039C5746CF96ULL, 0xAE443ECC6E3B321BULL, 0x675C54771D9ECCF3ULL, 
            0xE64FA86BB8329EABULL, 0x4D41C3374679FA7AULL, 0x240F0832E79631FEULL, 0xE58AFC2223CA079BULL, 
            0xBE31ED38E37F1F4FULL, 0x5523A4C1EE4220ECULL, 0x05C62136B5C158DEULL, 0x05387BDAA7E88C16ULL, 
            0xAD3503BF3D20BBC9ULL, 0x22F9AF48DCA24B97ULL, 0x0EE9D00217189326ULL, 0xA4DBD74606E3D061ULL
        },
        {
            0xA83FAB36EC0CCA57ULL, 0x051EA61511267CADULL, 0x6ADBDD42527998DDULL, 0xC8DFEFEA3860B7D8ULL, 
            0xE46475D010E4DC3FULL, 0x54F178D8CE920519ULL, 0x9A9D77C9C04AD39BULL, 0xAAF2D214EEBB963EULL, 
            0xE60364870FF584B6ULL, 0xAAE3B1A790909587ULL, 0x368C6B2D116AA691ULL, 0x8FD8BB84C1F5BDB8ULL, 
            0xCDAFC6CF99B1CADFULL, 0x2EA7A130098BE5E8ULL, 0x010520CCC87D7586ULL, 0x9269F02FFFA2AF16ULL, 
            0x6C11F12CF9776DCDULL, 0xB2A764BFB1D7ADB1ULL, 0x3536D09E5374579AULL, 0x44E53FF34CA17760ULL, 
            0xE8EAEC64B4AE1736ULL, 0x8BA8AAB27C277ADEULL, 0xECA9525CE77B6161ULL, 0xE89F943E13E81E89ULL, 
            0x3F8F2A87B073646CULL, 0x50E500A530FC8630ULL, 0x6F0601B673B618B4ULL, 0xD11F9313DDBEDC47ULL, 
            0xC97DA3A14F1149A1ULL, 0x4ADD79259839113AULL, 0xADD82B2EF4EE1FAAULL, 0xD86B11D94F19AD4FULL
        },
        {
            0xE6ECE14CE1D7C4F2ULL, 0x5FBF084B80104103ULL, 0xF13986E37E2CB6F0ULL, 0x643BD90EB734DBD5ULL, 
            0x487AB2D579504CCBULL, 0x757ED651C5A9DBE3ULL, 0x7192F081DE9994B2ULL, 0x10F068BB6D0892A9ULL, 
            0x452C28F7820C722AULL, 0x7092EBE004725DD6ULL, 0xA410A0E298497B5BULL, 0x2AF2FC364F1A5243ULL, 
            0x02F4FFDA34D78301ULL, 0xB2231FB136D40874ULL, 0x41A8F01501F9AFDAULL, 0x486455DAFB893F1AULL, 
            0x22BF0CA3AC998513ULL, 0x46463BA87F8A630FULL, 0xA1DEB7F6CC36226AULL, 0x9E2284A2C8B5CB51ULL, 
            0x6866B02C568CA9DBULL, 0x0E7318EB16C73DFCULL, 0x6C11A798CF0C1BBFULL, 0xD16121DBF54C7038ULL, 
            0x811C4CEEA8089191ULL, 0x995AF9F4643957A0ULL, 0x9DDDDFEA492727F8ULL, 0x87BBA5E023CD4A48ULL, 
            0xAECC835F1445CF7AULL, 0x04264B07CBCB2F40ULL, 0xE1FBCE72B49C38DFULL, 0xACE75F0098942BFFULL
        },
        {
            0x8B2BB16E72557469ULL, 0x5CBC558437FF8538ULL, 0x0C2632A84B90F551ULL, 0x7CBC9D75DC3EF077ULL, 
            0xA2E91BE8FE109B53ULL, 0x0569F74BD6D924CBULL, 0xBDFF70CE98D87313ULL, 0x0C5F9E02D3ACA19BULL, 
            0x30A3F78DE91C99FFULL, 0x2C0475DF4913E8C8ULL, 0x58F589D25A1C4C63ULL, 0xAFCB8623438BD5DEULL, 
            0x753EBC17FEACB610ULL, 0x746DC0BD654F9E8CULL, 0x9F81AF78B27D07EAULL, 0xA0814B3B31A79280ULL, 
            0xBB80B6BD8D95B50AULL, 0xC12ACC00A5E0FE90ULL, 0x760E521AF5AB955DULL, 0xF816204CAF89FCCBULL, 
            0x883C13372F4982DEULL, 0xDC30023FE73A8039ULL, 0x757F980131FA3F57ULL, 0xCA59E984BC527729ULL, 
            0x483A90375538CC45ULL, 0x43F074A227EEAEBAULL, 0x0511F783B6E526FDULL, 0xF9328842FAAB3B81ULL, 
            0xF2A05FBB7BA66154ULL, 0xA20D7AD15E4B7728ULL, 0x171B43BC0E7D3E44ULL, 0x2AE64F819FC45268ULL
        },
        {
            0x96FDB37E2D29A214ULL, 0x5AFF3D8EACF96BA4ULL, 0x5C240B93C56FBC63ULL, 0x6D6DB0E78F30E165ULL, 
            0xD59B202DF6EDA568ULL, 0xF18ECC732A49C77DULL, 0xE610061D5A872F2DULL, 0xB7420F9E626A474FULL, 
            0x5F512262B7CADD1DULL, 0xC0D58E7A77A4E3CEULL, 0x6F43871CC23F366CULL, 0xBBE8ADD21E552E8DULL, 
            0xD49807EB05413EFBULL, 0x81C0503D392B6DB4ULL, 0x9764035DBDC24E4DULL, 0xEA3D8C691BA54ABCULL, 
            0xAB4FA9E94EBC4861ULL, 0xE41F160FA31FD3CFULL, 0x52B2DF49C228AE54ULL, 0x881945D9F1E31A67ULL, 
            0xCB6E84820C2083A3ULL, 0x95278E21AC7D172CULL, 0x0A016F8CC304EA5DULL, 0x4F8C33FA2E24EE9FULL, 
            0x22FAA08B6E5FA154ULL, 0x05915439C72EE43AULL, 0xF394F6C4FF252F15ULL, 0x5F8C299FBDD51182ULL, 
            0xB89FB23C70FAE07AULL, 0x441F5D91FEB74C6AULL, 0xFAD2B46BA8F02D41ULL, 0x8E37DAEC101EA9ABULL
        },
        {
            0x48CB7B144AE70890ULL, 0x0511CC9D10B0D262ULL, 0x66C566B33FF02226ULL, 0x3D5038F574F366BCULL, 
            0xF5015489B27E67B0ULL, 0x4BB37515E9A5249BULL, 0xAD2DF743306DC8D9ULL, 0x3518FD5C3A12B9D5ULL, 
            0x832B720A86F23838ULL, 0xDE09CDA9334B7A0BULL, 0x284197853213E71EULL, 0xB64D51FA9FEFCF0AULL, 
            0xF3B66CA8DB91C2F4ULL, 0x62DD452EAB4DC71FULL, 0x01363E6F61238092ULL, 0xB95EFAC83BAB6AF8ULL, 
            0x177B6460DF3755DBULL, 0x3B4141A18CAF5E96ULL, 0xD30940F48309192BULL, 0x3B69900E5A2DC27BULL, 
            0x778655FD68A01628ULL, 0x59B4586919BF1564ULL, 0xC6F30FE2EABC0E02ULL, 0xA777D58C4AD33D4BULL, 
            0xC9A9F862770FA4DBULL, 0x28B7F681738A9927ULL, 0x6D5E174630E45E70ULL, 0x051F75AF86E2EDA1ULL, 
            0x753806F32E71F0C5ULL, 0x68FA5DD0DEE40592ULL, 0xB259045F7106131EULL, 0x7412227DA22A97D4ULL
        }
    },
    {
        {
            0xD1118A50ACD8AA98ULL, 0x296B9078AEF05595ULL, 0x07213E82752B2F10ULL, 0x1686A17D84405CF2ULL, 
            0xC4F5C165DE646749ULL, 0xB885CCFE9555D2F5ULL, 0xB9996530F62CC9F9ULL, 0x6D041951AE2D0DECULL, 
            0xE438E67FF5F2B34FULL, 0x2A1028EDB591CE83ULL, 0xC2D5DFE7EE360EA6ULL, 0xB2C537A350078527ULL, 
            0xA27206710B6DA54AULL, 0x7545177C5E6EC114ULL, 0x04103FA7815D0362ULL, 0x4F0DBBB507702DDFULL, 
            0x0DEEA550AD98D0F6ULL, 0x477475486C191EE6ULL, 0x1B2B41B1E3D55040ULL, 0x4AD52B63D54A8986ULL, 
            0x9606B222D020E5E8ULL, 0x1F49EB4EB13CE580ULL, 0x64E53951B8515812ULL, 0xAE1EF2DD640A6536ULL, 
            0x4D8999CE0B50B953ULL, 0x9981C1CA91C85C9DULL, 0xC835FD388CD78971ULL, 0xDD1C6D2EE38877ABULL, 
            0x75259718EF0FDFA9ULL, 0x5E5F530F2BA775EFULL, 0xC4F808330759B179ULL, 0x42A9F4B3D86CDC77ULL
        },
        {
            0xA5E2B9106935D1D7ULL, 0x725DDF7AB7FEAEC6ULL, 0xC39FCB8B49C228ACULL, 0x2623910740A3B2EFULL, 
            0xCC8144523DB9A801ULL, 0x81BC0E15E710FDE1ULL, 0x32841DA9CC3DEC62ULL, 0x21F1F2280266A420ULL, 
            0x9BF8C5E791412808ULL, 0x8EC754B99B5C057FULL, 0x50428360BB36A7DCULL, 0xC2E8699EA561AC6AULL, 
            0x8A193A1F41588CDEULL, 0xDB0E521CF54338B7ULL, 0x70356EEA4751A589ULL, 0x85C48F241F3D1D11ULL, 
            0xA4357A26C3982C66ULL, 0xB9A64967C5F120A1ULL, 0xEEE1FC474139F15DULL, 0x80D7EE826DA753B6ULL, 
            0x9D712B5B959809E3ULL, 0x2354B7B39DB728ABULL, 0x303E54EB5939AF3AULL, 0x010316680EF5DB7DULL, 
            0x8C738D74E78F1D70ULL, 0x04870D1E738F8882ULL, 0x2C8AC4C15F309E15ULL, 0xA896EB2FA1EBC97EULL, 
            0x94EF8849CDA7BA82ULL, 0x6FD601080EFDDE25ULL, 0xDD521B93249FCCA5ULL, 0xE02D9DA14F656958ULL
        },
        {
            0x2056C53886B187FAULL, 0x251E81ED275E9E29ULL, 0xA6CE3C1682A4DF4FULL, 0x576D8DD48096839FULL, 
            0x696ECBA5F620158DULL, 0x46F918E657AC7031ULL, 0x9E5ED46A9305169FULL, 0xB6D15517F270B9B1ULL, 
            0xCD2A7803B3A1ACE9ULL, 0xBD3FFCC8B73889AAULL, 0x6810619BAC31A3BAULL, 0xFEFAFE748B627890ULL, 
            0xD615C86CE4D7E85DULL, 0xEEDE57847E9133ADULL, 0x86A9740A30A0B6BCULL, 0x828293CB52AD1EDAULL, 
            0x8ABBB860DC569AAAULL, 0x87CC36BE364D9146ULL, 0x3A86E85C2EC85A0AULL, 0x750698D4C34306E3ULL, 
            0xA95B09043260E88AULL, 0xD1EEEB48D94E96D8ULL, 0x60CA60890BE92B53ULL, 0xB40106CE6338D2F0ULL, 
            0xE384032DD27C8FB0ULL, 0x322284BA3DC61C0EULL, 0xE95CDA7E8D7F6C9AULL, 0x7D51E38F7B3622B2ULL, 
            0xB6743E4A685D1EE3ULL, 0x09E5ECD0E5CA381FULL, 0xA197243F972F577FULL, 0x6CA28DA9C665D48DULL
        },
        {
            0xF6E8E0EC1813458EULL, 0xFB1C78D9A2A12B98ULL, 0x3F7679E73438E8ABULL, 0xAEBAD48252932125ULL, 
            0xCC915F41D1294BE1ULL, 0xD0B8CAC66E8DB6CDULL, 0xD0AEB9609D18ABA2ULL, 0x314A1C527E6FBCABULL, 
            0x6EE5C1F8B441522FULL, 0x5A2E909B8085E410ULL, 0xBDCCD7CFE755E86AULL, 0xDB7EFB35AB183E69ULL, 
            0x8630703A359CA77EULL, 0x6D03B6DEAAA2512AULL, 0x2F18207CF1E38DEEULL, 0x84775AC5CBB590B2ULL, 
            0x843E8BDBF43F72F7ULL, 0x658E75EEDE15C17DULL, 0x4C5DD8F33490E2DFULL, 0x656E13CACFD15767ULL, 
            0xA8505338D4214FD8ULL, 0xB9BB827A6D4B9223ULL, 0x926E67A3CDEFA937ULL, 0xF7B95DDDCD88DAD8ULL, 
            0x71E30F08FEB4ED11ULL, 0xB5AF6C42F0218833ULL, 0x0FBEA4EA899A842EULL, 0x65B401A90D1D8C3EULL, 
            0xBB12F056737C0B38ULL, 0x5A661BDB77A0B2CAULL, 0x5F8F4174B0B9E2EDULL, 0x583239650AA06C7AULL
        },
        {
            0x290A39152EE1048DULL, 0x6123132AA81B2095ULL, 0xB6489D3909456B98ULL, 0x9438FB22E273140EULL, 
            0x62DF3A61900F6011ULL, 0x96C8D319CB0F71DCULL, 0xEAB72E9F5D88FB1AULL, 0x2168B0D65B0C1BA8ULL, 
            0x06DA806B95E96739ULL, 0x0440045A56A584FBULL, 0x9482F02E204FDEFBULL, 0xD434EEF902D40C22ULL, 
            0x39D6AD9E59AACADDULL, 0x7545D75FAF48AF7DULL, 0x7E5C51BBAD40D202ULL, 0x543B5ED539B6216DULL, 
            0xBA42A463ABAC10B7ULL, 0x9965F06B6A6B5767ULL, 0xDADAAB25AA832C9EULL, 0x0B668D1E6A439C33ULL, 
            0x437999E92260FFACULL, 0xE17DAEF4AED08E9BULL, 0x123D0DBBDD7B474BULL, 0x0514DC6D7DCEEC23ULL, 
            0x043FC6B64548A6C1ULL, 0x16CA631D79DDE76AULL, 0x9D7D151922AF27CDULL, 0xBF0471AA1E45DE84ULL, 
            0x845EA1570E1891A7ULL, 0xCE81DF9786FC9E61ULL, 0xFDA32CF0AB94C4EFULL, 0x1B064AB1FA6F35CEULL
        },
        {
            0x5D2DF6B4BEFEE56AULL, 0x304A68848B068F97ULL, 0x13C6F7A453F6EE3CULL, 0xDF1293CAC5044C45ULL, 
            0x507DACCB64CB8BA8ULL, 0xE616733E6770F951ULL, 0x857245D3D48ABD4FULL, 0x0BFD314FC33D7CE0ULL, 
            0x86D7EAF52B2A8C2AULL, 0xB128468098FD878AULL, 0x3388D7311C861E1FULL, 0x2FE8512F80D7401DULL, 
            0xF3420348EB20CA42ULL, 0x2FA8F61A4FA86C7CULL, 0xC7C4B2A7A36CE189ULL, 0x4BE25E8DBD8BCD42ULL, 
            0x2F258C7349E63C14ULL, 0x7FDD3B51EAC52D31ULL, 0x63D2D0D201CFC97AULL, 0x5CB429FE9A6A662DULL, 
            0x51FA6B055BA5DDFAULL, 0x1D0DDA12B9FEF9C8ULL, 0x0F642A47BA8216C8ULL, 0xCED5EB066C407BC4ULL, 
            0x68945F69D5307837ULL, 0x59383B9BD46BCE80ULL, 0xB8A4875CFCC1E980ULL, 0xE978316A2219349AULL, 
            0x1F8CD04B2D01FF35ULL, 0xF416D7465DA7F01CULL, 0x25E08BD5B218EDB3ULL, 0x0DE94599157CC275ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseBConstants = {
    0x0D6FF7883B2D93B7ULL,
    0xF0DF37EC3EAC466EULL,
    0x05F20770F4DA4DF6ULL,
    0x0D6FF7883B2D93B7ULL,
    0xF0DF37EC3EAC466EULL,
    0x05F20770F4DA4DF6ULL,
    0xC0CB4BDECF3B9C55ULL,
    0x7E747EF0548FEFBBULL,
    0x73,
    0x46,
    0x2C,
    0x43,
    0xBC,
    0x38,
    0x04,
    0x9A
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseCSalts = {
    {
        {
            0xFE1CEDFE0EC8CB0BULL, 0x7F161569554F7EEEULL, 0x0E734143A4255AB9ULL, 0xAFA591E9F3DD0DB2ULL, 
            0xFFF2491CFFCBBE06ULL, 0x5A8D81C3299F6D97ULL, 0xA2C0BFE51F06B6E9ULL, 0xBAB4D2A636670E1DULL, 
            0x889F020C43E3FDD6ULL, 0x560ADA47122B7C44ULL, 0x1E3152449CAA2ADFULL, 0x11325F7BAB109E8CULL, 
            0x44E7A395997BC341ULL, 0x5EF125DF7935880EULL, 0x672AAC0497FA2AF4ULL, 0x86E2E0B31BC6D588ULL, 
            0xCAE17D4006EA14E3ULL, 0xF3C5CB5A7646D850ULL, 0x440BA37DBC55379AULL, 0xC9F72168BB5A400EULL, 
            0xCDB25657195F5BCBULL, 0x9458C5A6C621A96AULL, 0x0741B7D8694A6279ULL, 0x101BCFA521EE3614ULL, 
            0x4AA130D686F10341ULL, 0xB0E20C70F49897EFULL, 0x51740AE16AF6ED73ULL, 0x5380D97B222FD530ULL, 
            0x3E29180BE546FF94ULL, 0xA50A5D0CE1352695ULL, 0xBE61A0E34959E246ULL, 0x8BD34FECFF7C407CULL
        },
        {
            0xEEBA36DDCCD3309EULL, 0x8CF65647C8FAF604ULL, 0xCB3DDA63339FE49DULL, 0x179ECC2F2FFFCCE3ULL, 
            0xED5BA9E39C3643BDULL, 0x7C9E8E80BF48565EULL, 0x091EAD17D3D45559ULL, 0x2F521B342D88CED3ULL, 
            0x7FD43E5EB195BD46ULL, 0xC0C2AAD245B844B5ULL, 0xD85F0962DE55EDA1ULL, 0x88ABF1970A260978ULL, 
            0x4830C4E27E0B1E6FULL, 0x44EF37735EAC2155ULL, 0xD8AC563A99D24C60ULL, 0xA4A23D9D2E1929ABULL, 
            0xBCD2E05872961FBAULL, 0x205FA923BF8C5858ULL, 0x7562E85CAB6FE4A7ULL, 0x62ECA172360EA48FULL, 
            0x75FADF30D2CEC8EBULL, 0x144C1438E76300C2ULL, 0x5987CAE5A1C68C00ULL, 0x10F19BD5E88320EFULL, 
            0x445F5BA7BE509B54ULL, 0x35886C19224BED1BULL, 0x7FE6D92C53F1ADF1ULL, 0xBADA7119C2BEB10FULL, 
            0x00FF22FAD3BDE878ULL, 0x0F18D20F38B32403ULL, 0xD7F56738021B4F55ULL, 0x4A6F73BAA9935383ULL
        },
        {
            0x5CB7111C88CACF91ULL, 0x37FA01BD3844F599ULL, 0x33CEF288DF3F025EULL, 0x408F2D215181226CULL, 
            0xCEBFF356135DA491ULL, 0x7C9043ED57497730ULL, 0x0758F9DB9B3F9C6BULL, 0xABF4B11AF2B6F28EULL, 
            0x40769BEB09494801ULL, 0xB3F878FD3B076E37ULL, 0xF9F175D36F59E813ULL, 0xEB0CC311CAD1900BULL, 
            0xB87C9F7E759BB3ACULL, 0x76A03E034663E8CCULL, 0xB00486BB4FFC8A53ULL, 0x4F1BA41AE80AE1AAULL, 
            0x91ED205533CE8373ULL, 0x5D474FBF917FF2EEULL, 0x4E09B247E90D74A2ULL, 0x49D4B3E65F4959EBULL, 
            0x1C007D497B2CE06BULL, 0x6338167276A9696BULL, 0xA3F8DBB6576D4FE2ULL, 0x430DEFBDBA7D64DAULL, 
            0xA071DECA14EEA9AFULL, 0x1AE0880411C93BE5ULL, 0xA7090DE16E70584CULL, 0xE68AEAB45D33D179ULL, 
            0x6CC450AC825DE192ULL, 0x50BB76203966905CULL, 0x2B04A1023437A6DEULL, 0xF31A88D2C4190640ULL
        },
        {
            0x21CAA9E7B6BDB1BAULL, 0xB09A7A0E0D32E6E9ULL, 0x47BD069E57712E80ULL, 0x9DAE71EB66524BF8ULL, 
            0xDB49741FF1A8BC04ULL, 0x6E379EB4268A2373ULL, 0xB75748D7EA91F8C3ULL, 0xC3AE4CB0167B40CCULL, 
            0xE05DC46491405721ULL, 0xCBA2C2DC96484CB7ULL, 0x503834DC26C21FBCULL, 0x4BD89DE0C2441C98ULL, 
            0x0DCCEB3B9B4A195CULL, 0xA40DA012798BF7A8ULL, 0xB2FCD09285956DF8ULL, 0xD5255DD2B6314D7BULL, 
            0x4EE6BC13441AAAC4ULL, 0x5F48A86841168E84ULL, 0x3FFDF631F94FE1DBULL, 0xD9211D9E3A96E569ULL, 
            0x406E5317794EC211ULL, 0x3F1B8494B50AC8B8ULL, 0x6099F2530D06307AULL, 0x11DAF5C6D00BAEE4ULL, 
            0xE2CB65664A742542ULL, 0x804B8C6DF81F3266ULL, 0x04DE786EC3D05738ULL, 0x45D4C71E32B898D2ULL, 
            0x2BEB21B3EF28AD9EULL, 0xA89F7F1030881A69ULL, 0xF41C32642C844316ULL, 0xF606E50F14D51D37ULL
        },
        {
            0x278A5BF2FDE53234ULL, 0x1666447C8ADCE8C3ULL, 0x3F6CC2A43D56EB11ULL, 0x12A4E9F719A08F3FULL, 
            0x6A526C30916039AEULL, 0x93F5FBC97414D107ULL, 0x5B8189A7427FB8BBULL, 0x49FE722F2F9BC05AULL, 
            0xDE0A9FD349978615ULL, 0x3AE9B071CD89F2FCULL, 0x64C044F694472A1CULL, 0x3540E46143ACFCC5ULL, 
            0x132579990DFBFF70ULL, 0x7ADC1C7E5DD341B5ULL, 0x53D01FF6C3E044CBULL, 0x2EF40DF1AF5C7370ULL, 
            0x0CBFEE1ECF77F0F9ULL, 0xF770B55DF71FFB15ULL, 0x12A6B177314F3952ULL, 0x58A55307283774D7ULL, 
            0x7235085ABC59F2F2ULL, 0xA9D1598028170969ULL, 0xF22694EE8D60B4D3ULL, 0x25800B0DBCBCD2B1ULL, 
            0x964EEBFC4B16B78CULL, 0x7D32DD04F5783B6EULL, 0x94A5146CA8871086ULL, 0xDE35C2FF4AAE27C1ULL, 
            0xFD4134E0D7BAAC97ULL, 0x2BDCF1484F69CC12ULL, 0xC2752765A2B8663DULL, 0xBAFEB00B1656C0BBULL
        },
        {
            0x50DE46AD4B1A88AFULL, 0x159C987E7B454A5CULL, 0x9C5164D9988365ACULL, 0x9A7DE7E939F53658ULL, 
            0x5B5EFDE1434434FBULL, 0x8C7C3C2BF3508AEFULL, 0xBBF5944BC59C8C5CULL, 0x9FAB10A8FD247D83ULL, 
            0xA9E92DECEA087321ULL, 0xFD0E6F98B8DAD326ULL, 0x1DE6BC87B8F33A74ULL, 0x64D3DC0E3B8FBCB8ULL, 
            0xEE8C85E7BE0A8228ULL, 0xBA1CF959290A9B06ULL, 0xCE70D7E35768CA11ULL, 0xE395EE215DECE36CULL, 
            0xEA082BEF0FEC02CCULL, 0x442D0612F4194C66ULL, 0x63517915FB6C75F6ULL, 0x044104ADF15A6B79ULL, 
            0x87F3CFD464F87F6CULL, 0x26F6DDF54D6A4F07ULL, 0x9F1CAF63F047C934ULL, 0x93763E207AA3FA14ULL, 
            0x7697413A35AE9FC2ULL, 0x2F40B7B84B5F9270ULL, 0xE5D9E42098AF4AC8ULL, 0x1982CE99B64ECB29ULL, 
            0xB7C316C96B9FFB6CULL, 0x5A3D77399D89554EULL, 0x14774C76F2820720ULL, 0x6A0554D59167DB2DULL
        }
    },
    {
        {
            0xAE6F61FCFB8CA1A6ULL, 0x449D9D759457D93CULL, 0xD0E0E7498DF9059EULL, 0x63EE7D6558B1840DULL, 
            0xEF24153C5FD7F65CULL, 0x042E6FD7FE63C307ULL, 0x7C6D3EF4CB498AF7ULL, 0xA7067EAE43623F6EULL, 
            0x251EC586053B274FULL, 0x3783BA6D3CCDB3ABULL, 0x5D046D4F2C00DD91ULL, 0x2B0B98852F72632BULL, 
            0x73E513D5A11ACE1DULL, 0xD5B3EB0F4A74AAD8ULL, 0x229BA01BDDE1E5BDULL, 0x153C987C30FE2F3DULL, 
            0x26521E82FCACD381ULL, 0x70D0793204F91305ULL, 0xB0C5E2239EE19360ULL, 0x1CF4A264B33D57A7ULL, 
            0x761D0165265FBA0DULL, 0xDE02350CE17C2D38ULL, 0x5D346CF1C4F8A1B5ULL, 0x8BEDF971B2B0317CULL, 
            0x7476E4528B94619DULL, 0xDE3B06D72BC83C04ULL, 0x09D6B74B7D2AAC3AULL, 0x74515CB1CC7CA133ULL, 
            0x507CA002F13CB07BULL, 0x272C04F8DBE419FBULL, 0x051979B52DB13E18ULL, 0xDEDEC4A76BC5870BULL
        },
        {
            0x751A2BEFE9230D3EULL, 0xE03BA55EE62BBEF1ULL, 0xFB254E6BEB07F0B1ULL, 0x1FC665F587550846ULL, 
            0x17305B50B32D1CCDULL, 0xEEDEF58D6A619127ULL, 0xC6B9458C7F9C5219ULL, 0xE952E7F796727FB8ULL, 
            0x2F3DC44D71B0C76FULL, 0x39988324C1043FF9ULL, 0x4AB344199CB8D258ULL, 0x2FC0CE95288F4D6EULL, 
            0x845537ED0E081A18ULL, 0xDEA5880E9B233C73ULL, 0x22FA740E7B200518ULL, 0xF513A2EFCBD84028ULL, 
            0xE6823BDE4CF0F964ULL, 0xCF82D608479FF302ULL, 0x89C0C2A5A839DE88ULL, 0x6A0FB85DAFF72A48ULL, 
            0xC215588452B906B8ULL, 0x2936314B70792F3DULL, 0xB8F9F5188A6193F6ULL, 0xCBFD76195E9EC7F4ULL, 
            0x2871A3C150C6937EULL, 0x4A96F3982B928169ULL, 0xD9B8BF45EBA40F1BULL, 0x5BC2E1A1EB77B6B5ULL, 
            0xD02A33875CD46425ULL, 0xC0440EE9214BDE38ULL, 0x326510B4D495D7ACULL, 0x1E09C0E76EBCAB21ULL
        },
        {
            0x06D783D6A2275FD8ULL, 0x41D044C2B4F8F64BULL, 0x505CF79C92F5B461ULL, 0xEDF47E24710F2F80ULL, 
            0x8ACA0387064500EAULL, 0xF30BBB9D9397484EULL, 0x23B7A1431F658B4AULL, 0x236A9584E2BA4A2AULL, 
            0x00D50B4D78D7B87DULL, 0xFAE55C61068409C0ULL, 0xFD5216B25B85CF3CULL, 0x1BC78AAF28C34A0BULL, 
            0xCB1D67ED8EF3054CULL, 0x040DA5B3ACE8CAB6ULL, 0x6A67C659C2E641A3ULL, 0xF5B5184A2C43211DULL, 
            0xF643D862D9DC7B89ULL, 0xA9CD639E99DE5A1FULL, 0x86BB102D3D2A3A26ULL, 0x43B024E6E4C560E9ULL, 
            0x13000AE00250BF2DULL, 0x1F671E169AD3093AULL, 0x4A0FB27DBA2CB146ULL, 0xD43DA3E0D29F63DEULL, 
            0x0BD8777EE777FB89ULL, 0x30896771DD53327FULL, 0x35ED38DD6D650F4EULL, 0xCF1DF4DC685B4943ULL, 
            0x5A2DD78442D173D7ULL, 0x969FFE9E9209DCAEULL, 0x2FAC525330075B82ULL, 0x208D887F3E628A03ULL
        },
        {
            0xD325C8BE7E48ED36ULL, 0xE58421DBF78BB0CFULL, 0x6A91A75F176D2254ULL, 0xF6F67CBEA0D19A4EULL, 
            0x56E1CB7E2DFCDA99ULL, 0x0C5D54781AD0A6FAULL, 0x1CD7A57E489AC47CULL, 0xFE662132B30164E2ULL, 
            0xD0847DFDA47213A4ULL, 0xB3B0982CC8455EA9ULL, 0x821CC5B310379945ULL, 0xBE371A758A6B650BULL, 
            0x569B42D8D5CC23CFULL, 0x8196D4770DFE2A4FULL, 0xFBD37B0AAF1F6AE6ULL, 0x2BF65F4EA4D34D63ULL, 
            0x4C948117784D5EF5ULL, 0x0472262DE51754DDULL, 0xF1343A609EEA8A29ULL, 0xA1B3D8B78CF57EF8ULL, 
            0x48613A3827C4FB9EULL, 0xE2D5AA1EE578D477ULL, 0x302A09A241138BDDULL, 0xC3EDD1C48FBA46E3ULL, 
            0x15E9F1DD3A528874ULL, 0x3851736E7909BD65ULL, 0x81323971EB122689ULL, 0xFAD4037142FD456BULL, 
            0x6C7515C6CB326070ULL, 0xA255162B4FF3BFF0ULL, 0x3FAE93BDE87B08DFULL, 0xC0DFA0182846A9A1ULL
        },
        {
            0xBDD7770686F4483EULL, 0xBC09F574D54C6879ULL, 0xE161ECED3BE532BBULL, 0x4103FF947F05E9CCULL, 
            0xDF974E91D69E7F4BULL, 0x6D2601C50151E013ULL, 0x8D9644AEF33537ADULL, 0xE30F870739059FD9ULL, 
            0x50095CD35F040D50ULL, 0x13ECA227208B91F3ULL, 0xCC675F19017BD20BULL, 0x3552F3F6E5D9E482ULL, 
            0xD357CBE77D16BF24ULL, 0xA945A94CC0229596ULL, 0x64E352D5C0827ECAULL, 0x0DD67E169267F442ULL, 
            0x5ECFD814D24EA77CULL, 0x5094B5342CE0EA35ULL, 0xA7E81D7620A38C38ULL, 0xB73E202504A9F089ULL, 
            0xD89A5264CB01DB1CULL, 0xC817BDD188257EEAULL, 0x440FF2B5F0B8570BULL, 0xECD165797467F0A5ULL, 
            0xBAA0A89394AF938FULL, 0x3342EAF92B895273ULL, 0x396D4A0404D10AE4ULL, 0xE0DFC9021061F064ULL, 
            0x80C14AD6218BFCB6ULL, 0xB003EF235FFB5873ULL, 0x76C40351869B9118ULL, 0x2C7062C291FC1C3BULL
        },
        {
            0x2AA7AC7D705959B0ULL, 0x0F1A9A2C0E05ACA2ULL, 0x3F2314C39A840A4CULL, 0x115154A28F78BAA6ULL, 
            0x86EBFE80DF99A0F4ULL, 0x8631B2E5BD9FF369ULL, 0x1A6462318E47DA18ULL, 0x1712288B8CC6DBF2ULL, 
            0xAFF6AC1BF0C60171ULL, 0x8483FEE652F68308ULL, 0x9CB8BA8ED60B2B8EULL, 0x36918293001D626DULL, 
            0x8C04780239CB683EULL, 0xF10829F2C8FBF3AFULL, 0x3C3B3D9A4F720433ULL, 0xDCF2459E912CE7D3ULL, 
            0x5DEA435291C47380ULL, 0xFDD13A02698C02CDULL, 0x051C031E98FC2B23ULL, 0x36D8DCA0E5F387DEULL, 
            0xC9ED0D4F638FB0FBULL, 0x86CFE182F93F191DULL, 0xC3FADDCAC8E08F88ULL, 0xF8A72819A27C8349ULL, 
            0x564A852BD7703F96ULL, 0xECF6D67BC1162BF5ULL, 0x99D37288BDA12987ULL, 0xB3E4B3339284AAE7ULL, 
            0x1A85FD76C6B01C0BULL, 0x5E194E170E07C076ULL, 0x7967EC4672633899ULL, 0x759EF4D503259A8AULL
        }
    },
    {
        {
            0x0D3B131A615BF11CULL, 0x7978727E1FD5859FULL, 0xCC6E391C72932D41ULL, 0x2931414B61B44051ULL, 
            0xBDF9F02A594E891AULL, 0xE89B6767E3E1470DULL, 0xFC61B6A0ADFD290EULL, 0xCB7BE5125DFE8799ULL, 
            0x7BF49C40F75CD72DULL, 0x535BEF452590A750ULL, 0xDF485D491537BA59ULL, 0x950F986BB23432A4ULL, 
            0x5053774D454BCC7CULL, 0xBFA02C5738AD0814ULL, 0xA65C6A58D22B4F9CULL, 0x02F22E554B1EA93CULL, 
            0xCD890D611F6F300BULL, 0x705410DFD59ACE5FULL, 0xC4071E2F205791EEULL, 0xD92F73AD1178EEB4ULL, 
            0x0BA90356DA65A0AFULL, 0xF97B12F2907AEA61ULL, 0x665C483D696C7E3DULL, 0x7E1C474F3DF90C40ULL, 
            0x2CE5E3F0D4397F78ULL, 0xC68F2006A451CD85ULL, 0x16F86F5701FBC5D9ULL, 0x659A46DB457BC373ULL, 
            0xAD240825DEA68A60ULL, 0xB1EF9B11CE5EE079ULL, 0x00CDA9EDE20EA4F3ULL, 0x8E996A108DCD00E8ULL
        },
        {
            0xAB469369B861F1A4ULL, 0xC25BC8543F41EFB6ULL, 0x6E3F866A1202DFEEULL, 0x7C98BDF7373D9E93ULL, 
            0x7B87D900558E9F50ULL, 0x681AF744A72E4913ULL, 0xC6893ED464A6F5ABULL, 0xAA972B5524402E76ULL, 
            0x724F935BCFF3E403ULL, 0x345F56791E961CB7ULL, 0xCDE01569CEBF5CF5ULL, 0xA8500281FC96EAA7ULL, 
            0x2590EABAEB674B94ULL, 0x245A02A80FC9F6CBULL, 0x08F6F3823A64CABDULL, 0x86297EC6F453D6C0ULL, 
            0x64159FF629160E4DULL, 0xAF8A4D7E2C113EE0ULL, 0xA85D3F5E7FE7E392ULL, 0xF2C1E6FEEFC14D62ULL, 
            0xAC05C73FC3CAE127ULL, 0xFD1F2F97F55D1054ULL, 0xA588E317CB511D53ULL, 0xE2C0FEC5978B757DULL, 
            0xC153A733E53C98F6ULL, 0x1007EB4D37D53FCEULL, 0x32FA755484BD9B5DULL, 0x3E5C0F54455A7367ULL, 
            0x86637A4257776E00ULL, 0x3DE8223D3029593EULL, 0xD0055A6FE407FA89ULL, 0xD70C7D633440A55CULL
        },
        {
            0x515F0BBF704CB5CCULL, 0x8BF41D901EA94989ULL, 0x44A8286A033C08F2ULL, 0x980B9AC109E2FC09ULL, 
            0xB6FBAE0474DFCFF3ULL, 0x6C6DA48AD6A12433ULL, 0xB47747E3EC832EF5ULL, 0x01B71E48798630EAULL, 
            0x5FE3033003C8A820ULL, 0x3DB53DFBAAB14F58ULL, 0xBB4A4D4AFCE4AF25ULL, 0xA41DF81B8F597DBAULL, 
            0xA810924C5E1AFEA1ULL, 0xB0FB1EF1EDB20CA3ULL, 0x819B950760D883A3ULL, 0x707FAA9E70974D16ULL, 
            0x29FA715382CEF66AULL, 0xF5118030C45A4628ULL, 0xAB8751B2F7825207ULL, 0x620F1DC6D39A8B14ULL, 
            0xC425C30CD5A1DE22ULL, 0x66C9811B08EA1365ULL, 0xF3B9BD656181D7E6ULL, 0xF7207822AB6F0BE7ULL, 
            0x95870B3DFA4FBDB8ULL, 0xD545DC6EF610FA74ULL, 0x15EAE6DC8943D5C2ULL, 0x7E6CA05C2F2108EEULL, 
            0x3FB21DA27F0BD5B8ULL, 0x3040C3BC10F41971ULL, 0x376B916D22FA493EULL, 0x4476686B1540FCADULL
        },
        {
            0xD37EC161C63C1A4DULL, 0x4A0583D48B1E3479ULL, 0x1DB0F87C6E21ACA5ULL, 0x461BA25724DE2977ULL, 
            0xE69B6C197FDC27D7ULL, 0xA49C985C7DABC6EDULL, 0x71BF4059D5D98FD9ULL, 0x2B84A21B5CF84276ULL, 
            0xF589FEA45C597365ULL, 0xE181EC22D3DB0935ULL, 0x78645C1095184459ULL, 0x6C15174D5DD58D15ULL, 
            0xC625D3FEF816DFFCULL, 0xF0FDF69B1333E3ABULL, 0x0AC8B64BC6488D3EULL, 0xC966793327341717ULL, 
            0x4B235B938EB99B12ULL, 0x4EBACE3C44A4CD14ULL, 0x11AF4B7D8D96B1D1ULL, 0x3D0EB17055623A54ULL, 
            0xB1DDCCC49D22A4F6ULL, 0x6B93B55BF797D13FULL, 0x8E69C536BAD8BC2AULL, 0x978364FB61C89764ULL, 
            0x31618B07CDF2318EULL, 0x02BF75721E9FF27EULL, 0x2F0049212E61D3E6ULL, 0x1B39D981F7CA45F3ULL, 
            0x5A9FC81FDAC2166BULL, 0x05D94FE470992990ULL, 0xB2CB4818C6DCD951ULL, 0x87C3966E33851B4FULL
        },
        {
            0x792B3AAFAB5C5F6BULL, 0x2C924F69EBC9D7FFULL, 0xB01D7129924B1B79ULL, 0xED9A1D00E87B74CCULL, 
            0xBE692682993222DBULL, 0x4111EF3A5DAEB7E2ULL, 0x7443CE804DA4450EULL, 0x1D5339E77ACC5FD0ULL, 
            0x6B708F1D97092B18ULL, 0xC1E1640C0521383FULL, 0x48858145CDED7A39ULL, 0x0126BD7E99E0FA41ULL, 
            0x874EEEF5EA23B898ULL, 0xF9B48E70B4539D29ULL, 0x118448DF6279E763ULL, 0x51B7037DBFCED7FBULL, 
            0xB88BCF144597DC1BULL, 0x4FC3A7F86E756E8DULL, 0x217A139BC8798D38ULL, 0x8734708A0D97CA5BULL, 
            0x554115ED0071AEACULL, 0x55AC0CEE9A99B653ULL, 0xB9F2EE197E284AA5ULL, 0xFBDED7730D7B6907ULL, 
            0x206D7585CFC091C5ULL, 0x1CB0CE2E03D1CDCDULL, 0x3DC70D2C64AB2A48ULL, 0x8CA854E1DE47564FULL, 
            0xC24063514879DA0BULL, 0xD85AC300723E6415ULL, 0xB19A14F2CAB64AA4ULL, 0x2C79254C96E85351ULL
        },
        {
            0xC0920B72EA95E271ULL, 0xD876C192A62810FFULL, 0x229FA921B5E0E2B7ULL, 0xDEC451AD2FF2C8C6ULL, 
            0xE06978EA4000F4BBULL, 0x91246CF346DEF73EULL, 0x861DB56A3F7DB307ULL, 0x550172B5DCD36159ULL, 
            0xB555823C40FD7742ULL, 0x4CF4C11522A65946ULL, 0xF0CD1F3C0386A163ULL, 0x1FDC4FDBD1F8A239ULL, 
            0xB9954F75640685E7ULL, 0x7CE7F69E48A5BF7CULL, 0xB67F696B3F1807BBULL, 0x0449FF956B2FA773ULL, 
            0x427FFCA9E5D344B0ULL, 0xE99F00446B7C4B35ULL, 0xCA32DA4104A59544ULL, 0x6BEBB4D58D99BA6AULL, 
            0xD1289FD732783CDFULL, 0x710856ABC8BF94A9ULL, 0xC64A117B6DA64688ULL, 0x70FEB6F67080A151ULL, 
            0x193BE7CF98159FA2ULL, 0x850C4BCA28E99CC3ULL, 0xF0E083EA6DF9AF2CULL, 0x72428414DC9682E8ULL, 
            0x1E22DF6B3A312DA2ULL, 0x466FAD1C6BD03223ULL, 0x0E70AAD6C0C781B4ULL, 0x9169EC4DA600B78AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseCConstants = {
    0x2EA79BF73D6F8DFBULL,
    0xA3A844990388181EULL,
    0x55E5E269959EF03FULL,
    0x2EA79BF73D6F8DFBULL,
    0xA3A844990388181EULL,
    0x55E5E269959EF03FULL,
    0xE37167EF474635EEULL,
    0xC124E033C5B0A572ULL,
    0xD4,
    0x30,
    0x06,
    0xCE,
    0xBF,
    0xF3,
    0x2B,
    0x28
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseDSalts = {
    {
        {
            0xD872F53DD4745ABFULL, 0xC3E2BE5F1AE2926DULL, 0xC3D70D94A877A021ULL, 0xFF4682D3EFD99D4AULL, 
            0xA70A273C2F3240C0ULL, 0x095115F8F6D8D1E6ULL, 0x06864E567B0C90CAULL, 0xE5EE480B9278D134ULL, 
            0xA32B969C05AEBDD5ULL, 0x2AB10642F0C73716ULL, 0x0963EC84CCDFB07FULL, 0x77D0FA3AAD0682B6ULL, 
            0x2D1942E05EC9500EULL, 0x5B0C65D1F6B0C3AFULL, 0x41981A32A6B1C825ULL, 0x057A2B2C6A0236F9ULL, 
            0x3E06DECE7D7BADEBULL, 0x59C22C08D6B18DDBULL, 0xEF8858FAC3E94995ULL, 0x5FE7E3F9C0DD70A7ULL, 
            0x91FFCE20F725C517ULL, 0x2BB1EF11D5EB9B9FULL, 0x3B4924D638F9D6AAULL, 0x2C684E1991E43911ULL, 
            0xAB59608F06DB17AAULL, 0x6E7C5101D2ECEF67ULL, 0xBD9E155E9D564F28ULL, 0xC75D04FB92A634F6ULL, 
            0x71C0441AD6577888ULL, 0x517655D29834E3C2ULL, 0x0A76C58A0552533CULL, 0xEB49F278EBC45A75ULL
        },
        {
            0xB7FAEF27EA1EAF1DULL, 0x56671B7891E0F859ULL, 0x066945DCF66C0757ULL, 0x4B9D8095292C03C3ULL, 
            0xFD4BB64E043C7307ULL, 0x5168A8615C3F0D5FULL, 0xF39B65E9F23C4C63ULL, 0x21EB7CB7F9F63B7FULL, 
            0xFA05834A49FDF954ULL, 0xE844A525AB353C4DULL, 0x7637F6C825B8B260ULL, 0x1FBBCD12E25E4BCAULL, 
            0x81D4A604236DDA75ULL, 0x0C28F9CE39BDFAB2ULL, 0x92FC0899A3AA9E08ULL, 0x000A81C223C1E190ULL, 
            0x0035BB057CAB4910ULL, 0x6971DD9134FA140DULL, 0xBE9627AAB35A556EULL, 0x4629CC23B5451103ULL, 
            0x8ADC885899E198DBULL, 0xBA52EDF9C767A448ULL, 0xC38A38EF661A76B2ULL, 0xD601DF27A58C8A5AULL, 
            0xB89AB371D38E13BFULL, 0xB1457A0CBD5F6990ULL, 0x285F8D3BF86D3ACAULL, 0xB7634E4B27F12DC2ULL, 
            0x23F5294B93A8FAEFULL, 0x937EC59724366426ULL, 0xA658288A0E5119F1ULL, 0xB02692055A083412ULL
        },
        {
            0x9436E14922319BB0ULL, 0x2AA8A59F9E49E070ULL, 0xBBFDB00DC74B353AULL, 0xCC79BCAB932D968DULL, 
            0x341AFD5F88DD13A1ULL, 0x42EF52A380081A0DULL, 0x26E490A275E3809CULL, 0x0CA5B1FCADB8C0A0ULL, 
            0x77BC53B08845FE1AULL, 0xF0AE34809C04B9D7ULL, 0x3C895CFB18FE3340ULL, 0xD9EEF88DBBC4FA80ULL, 
            0x4543AF2DD50A6F51ULL, 0x5394744B4AD8B864ULL, 0xD14EA0716373F47EULL, 0x01731AB0FF4EF795ULL, 
            0xF76F596A6D840B87ULL, 0x0AF783B3413FF534ULL, 0x6836C7BAE9F65117ULL, 0x74692C6A56B6DFDDULL, 
            0x96A22EE513844023ULL, 0x2FBDBCB370354931ULL, 0x7B0F959E01326D4FULL, 0xA3EE2F745FFE2E14ULL, 
            0x9E6E7872CB33D725ULL, 0xBA660D9D1C91710EULL, 0x9709A11C82EE6F5BULL, 0xF47BC201B5A97B9EULL, 
            0xE2580AF72F2A3231ULL, 0x10967B27C4D6F3D3ULL, 0xC9E3897816E2DF34ULL, 0x9D4C5D0CB02EDE18ULL
        },
        {
            0xE3564E5FC903E112ULL, 0xC50BC7CBAF36036CULL, 0x17A13BE5CCCB754EULL, 0x45D0F9601C9597CCULL, 
            0x25EAC31B9267138AULL, 0x3359C0C5C004F03FULL, 0xF2C2FC2CDD346092ULL, 0x431008DDD47CD172ULL, 
            0x3406D7FDFCCB1480ULL, 0xB53FAFAE4C389B97ULL, 0x5508AFF0E2B61DA1ULL, 0xFEE5C7241F5CCB51ULL, 
            0x8F68B10A2B473F2BULL, 0x6F4B52DECB105751ULL, 0x9D915A273A7D1E9DULL, 0xD1E2A3EC4486C3C9ULL, 
            0xCF7ABE6EAC33F937ULL, 0xB76C7E36E9D9767DULL, 0xB12B2248FE78F8AAULL, 0x518C7636C8771B55ULL, 
            0xF11CF017FA4102E1ULL, 0xA078B4C3CC02BFEFULL, 0x64A4A7321744CED9ULL, 0xC271C73ABE1A2870ULL, 
            0x9BB2F26363BF09FDULL, 0x8B96258F1FD60B5DULL, 0x94E2513B5899D2CCULL, 0x1AC65E541DE8991EULL, 
            0x3FF4D18C3D7E6AACULL, 0xD44F7E10C2F19FD1ULL, 0x41CA60522467F224ULL, 0x426F8D923003CD7EULL
        },
        {
            0x1F49D733E89C347BULL, 0x9EF480E01C0CD22BULL, 0xB384D73499755464ULL, 0x8E5FA3E23E1B16C4ULL, 
            0xF7193BB601431ECCULL, 0x192407B9F0786AEAULL, 0x09D0F8F035E4CE6AULL, 0xA5C8758E3202207BULL, 
            0x7449B6FEB1879DECULL, 0x6B0D9A9C087F3AE3ULL, 0x22F0D39CBDA9954FULL, 0x101CC87597081DC6ULL, 
            0xEB02D52328CF4DABULL, 0xC148C6E61505EA11ULL, 0x1AB68204837ED571ULL, 0x85785C958289EDFCULL, 
            0x40798788600CDB00ULL, 0xEEC7556DEFDF3B3AULL, 0xA3570A630D5E7ED9ULL, 0x1422AC6E0F6A70E9ULL, 
            0xA8B156E9E06386C8ULL, 0xC738A4BD67C411EBULL, 0x135F7CAB27541409ULL, 0x9607466DAEE3EE75ULL, 
            0xA9F221F323C2A37FULL, 0x11E5AEACB7DD5A50ULL, 0x1A47ADDC4D60ADF5ULL, 0xAF10C65660EDFC6DULL, 
            0xC47D443F5F7C4BEBULL, 0x61FB52E434DA6BA2ULL, 0x87557951B7555923ULL, 0x9BFF257E9AECEFBFULL
        },
        {
            0x27F0C9723F1B817EULL, 0x3FD15C6766ED7133ULL, 0xCB4C123F04EB9096ULL, 0x97685C8B87FDD80CULL, 
            0x535D38FFFC7D1974ULL, 0x1AE4BC23FE4FB64CULL, 0x686CDCD5B042F2D7ULL, 0xABBA92C9F0697E20ULL, 
            0xFE346B68D79CEEC4ULL, 0x2CFBD265157E4FDEULL, 0x0ABDCAA9827E41FAULL, 0x0DB1FCADEA34A200ULL, 
            0xB70CFC14C43F33A2ULL, 0x47F15DC62D58897CULL, 0x47201B95C3E0622CULL, 0x5B92264DF194A09DULL, 
            0xC3A35151BE21D6B7ULL, 0xFC8FECFC0091954AULL, 0xB86EB515089E0796ULL, 0xDFD522A22AC14190ULL, 
            0x58033DD5424EC416ULL, 0x168E909495424F02ULL, 0x00D58E07E40E26CAULL, 0x864463FFC601AC76ULL, 
            0x0181DB007736A042ULL, 0x08B23F6EF9694237ULL, 0xAD52494C6F9509CBULL, 0x5E89034DCB7A7822ULL, 
            0x3D0A19E0ADD875F9ULL, 0xDF5F70CA4922CB99ULL, 0x9012F3FB6DB3C096ULL, 0x8A1F87460B91CB96ULL
        }
    },
    {
        {
            0x4E6C7F8A6C98A9EFULL, 0x972245FD14CF0DECULL, 0x9DA2A1AE16F39AA6ULL, 0xEACE1525B52D1685ULL, 
            0x8F6801549F67C1F0ULL, 0x91DA952F73500CA6ULL, 0x30B3CF6F7EE4E9A4ULL, 0x0ACDCABF70724CC0ULL, 
            0xDBDE04174A27F57BULL, 0xE5C863D85CA3A889ULL, 0x48AF127FCF1CD2A7ULL, 0x800F84AEEDAB4E2AULL, 
            0x14D04A409ED986A5ULL, 0x5033A3F6306792F6ULL, 0xB38F77230C2930ECULL, 0x8CDF6DF35C32D172ULL, 
            0x5AEA2BA2A7DCD0FCULL, 0xDA296D29267713EEULL, 0xD6621BC832B40F25ULL, 0x15FC90A19A177430ULL, 
            0xB4E93123A2081B83ULL, 0x8D71364E762D4DFBULL, 0x6A8D0C57F5F4FD20ULL, 0x07A3F39589317FEDULL, 
            0x3E71F0B6646B84C5ULL, 0x8446A2B14BF553CAULL, 0xAACC5EBDF12A26B1ULL, 0xDBA28DAFF5D64265ULL, 
            0xE44E9A0AFCC2851FULL, 0x7D97AAE02185370CULL, 0x9294FAAF87481D85ULL, 0xF565D3ABE94D6B5DULL
        },
        {
            0x94E85B2CAB529B20ULL, 0x4414D509F4564E3AULL, 0x63CED92A4A07389EULL, 0xF52CCE8763469217ULL, 
            0xD67948D3E93C899AULL, 0xBB904C2FD62EA5C0ULL, 0x05E0D11F60005CA8ULL, 0xC7E23DA25602E7B7ULL, 
            0x35FBC84D573CB6D4ULL, 0xC686863C5AF70B75ULL, 0xBA3B81CA90155780ULL, 0x8F1B65352014AC46ULL, 
            0x8DC724D00118292FULL, 0x0244EE6611BE5407ULL, 0x58CCDF4A10D102A1ULL, 0xE74BD3D736E6C6C9ULL, 
            0x04911017CC7CE19CULL, 0xB423A391920BC125ULL, 0x63D447DF07EAD14FULL, 0xC4605C0E9420F369ULL, 
            0x3014EA13C3300DE3ULL, 0x688F7A5F756F5205ULL, 0xEE24FBBC39D6557BULL, 0x62C0D47892E3CEB6ULL, 
            0x064F0569229CBCA4ULL, 0xF6AF1E906A4A04E2ULL, 0x6FA8C309E96183DBULL, 0xFA8A42F7314E9D6CULL, 
            0x32355D03A5C10307ULL, 0x40D7BDAA7B494F99ULL, 0xF28D35B268B4B4CEULL, 0x81BAB5E25FB6788CULL
        },
        {
            0x9EA6AA4DF2B2FE4FULL, 0x162BC50DCF55279EULL, 0xBF361339B4DF869DULL, 0x2A39AA7B045F045CULL, 
            0x6925F9F773C8B87DULL, 0x228D2CECF944D4BEULL, 0xB07574E2DDDE1333ULL, 0x6A692A8A42A9A7EAULL, 
            0x1170F7049686905EULL, 0x338EE413D4154DB5ULL, 0x48F2519CA1B4BE99ULL, 0x52AD2CD03EDDEEC8ULL, 
            0x1F9EC8235DF18D51ULL, 0xC170D6EA459CF7F3ULL, 0xBEA339885D61C772ULL, 0x562A6E0BB6BC98B8ULL, 
            0x23A84029C6B2D880ULL, 0xC4A4DE857B31DC98ULL, 0x866A91E5CDBBB4E1ULL, 0xF9B76C45B5022AA5ULL, 
            0x64AA76DB76B3F2D5ULL, 0x751A9450FDF1F562ULL, 0x2158CBDA7FB6E335ULL, 0x1C590CDD5643C5E2ULL, 
            0xD1560453DCD0D9FFULL, 0x667E22FF3600A2BFULL, 0x27AD3BBB65331FAEULL, 0x51CEC7C1AFD20F0BULL, 
            0xB6A60A122B040578ULL, 0xCE6674338832E23FULL, 0xB32404FE13204361ULL, 0xACF82D47997CB9EBULL
        },
        {
            0x12D3C4BA25B50C00ULL, 0x7E5796C92B005708ULL, 0x154BB02CBE3A1FB1ULL, 0x9DBE057631C6CAEAULL, 
            0xA92BC4BC1DC1C863ULL, 0x35FD0FAA4F977974ULL, 0x842717D6B14D6059ULL, 0xA8369A78CE63D038ULL, 
            0xCC273B19102AFFBCULL, 0x743BE6CAF8783927ULL, 0x8227C45879EB0AA0ULL, 0x4191494B704DE63CULL, 
            0xF6DD5C8A4D91D141ULL, 0x807DDB77445A8570ULL, 0x8CA88D10ED5FD461ULL, 0xD766065BA4F0437AULL, 
            0x3D58549BEA21BECCULL, 0x0D4365E6DB162845ULL, 0xF1DA4F90F0E3ED62ULL, 0x5CCDB23327C1456EULL, 
            0xF9D6D5B561347C28ULL, 0x5EC8E35500F934E7ULL, 0xECDF87F04076894BULL, 0xFA7CF2CE98A42EFCULL, 
            0x655369C4B8D68EAEULL, 0x8CCAE3C2215B66CDULL, 0xD364BC95E94DA509ULL, 0x37D6506153E7D7F9ULL, 
            0x90A01A48A3A3EE9AULL, 0x0B449EE7A08F196FULL, 0x29EBFC442071A197ULL, 0x552FE62D36F1A466ULL
        },
        {
            0x9963C7DFA7E5C430ULL, 0xC0D0B6540D3C7E49ULL, 0x29251965B25CEEADULL, 0x6317A41DE64171E9ULL, 
            0x16B53C87489BE2C5ULL, 0x4B9477137629C16FULL, 0x69B27F9FD82EBF8FULL, 0xE3CCF1EB4CB30C9BULL, 
            0x60660458D6A7A220ULL, 0x64F151A68F8D7A4CULL, 0x8905C9A30B9CC981ULL, 0x518C189BB950FCD9ULL, 
            0x5E631D4E40AD04E1ULL, 0x2760D80FE067518CULL, 0x2283F3132A4BB3DBULL, 0x76CB5470E79EC32FULL, 
            0x4889BEFAA8C27668ULL, 0xAD37C098D305E43FULL, 0x632481F32A1EB4ADULL, 0xD9D58726FB7B056AULL, 
            0x3D29DBC6A7BF0947ULL, 0x86F1DD33ADFC4BE2ULL, 0x1D1FFFFD12006A12ULL, 0x0D7B3AF05E4C556FULL, 
            0x99BC65A48722F678ULL, 0xD760AA7811C70482ULL, 0x969D9381703F9F09ULL, 0xD1432E4631799F72ULL, 
            0xCE58E6CFBB58056CULL, 0x413F5CAF25C23BB6ULL, 0x688D4A67CD814C49ULL, 0x7BBBDF55B3EC6627ULL
        },
        {
            0x19E4369A7B78014AULL, 0x024073B071C90CEAULL, 0x2FD3B25F3800CA68ULL, 0x43D6EA80020DB5ABULL, 
            0x113F70C06C2BBA02ULL, 0xB88EF4E0D23456D5ULL, 0x111D5369D526A7CCULL, 0x98E31EF26D4E9B68ULL, 
            0x926B77FE2BECB918ULL, 0x6224B7F63C39F6B8ULL, 0x259654B7D540BB3EULL, 0xFE96F2E73336EAC8ULL, 
            0x9D70F91A141DA4EEULL, 0x2CC55D839A714706ULL, 0xE4E325575AA146CDULL, 0x0A9A8F1FAA982862ULL, 
            0x4EE2BEFB7BC9536BULL, 0xCF0D6A6986CCC4A1ULL, 0x87CC254C9C56A681ULL, 0x31AFCCE4DF29BB5CULL, 
            0x50C7BF2942F97A47ULL, 0xEC660B124AD6B870ULL, 0x4985CC4F73A8BAF9ULL, 0x4761D8AB37D15B78ULL, 
            0xEE100A29761F4310ULL, 0x95C403BEBE61C6F2ULL, 0xB6BD28A881B9C342ULL, 0x81323A518D59ABE1ULL, 
            0x652C1932FCFC50F7ULL, 0x1B0E9C8A00DCFEA6ULL, 0xA50DE8A8447B6F84ULL, 0x2A84DD759A75F5A5ULL
        }
    },
    {
        {
            0x66A6FBF51BEB5228ULL, 0xCFE09B1E4ADA3A42ULL, 0xB05B2929F1C50253ULL, 0xEED59C8CFEBD0BE2ULL, 
            0xB0FB57CCF5371145ULL, 0x3881F6F3C7BA6E53ULL, 0xC289D6C9FA822B54ULL, 0x9691B2CFE8047972ULL, 
            0x7C6AE9D850040864ULL, 0xAD6C5AC8F091F8F0ULL, 0x5FB00D9DC742E56EULL, 0x6C0D4E5A351CB9C0ULL, 
            0xA362349E49F00F74ULL, 0xAAF1C81443204261ULL, 0x864D8D0DA4D74F5CULL, 0x4107FC55C2730323ULL, 
            0x165FD86B15B737DBULL, 0x87D4B760A1AC8624ULL, 0x8DDED0176AC1398FULL, 0x92A77D1AE842C58CULL, 
            0x50CF4584D44B335DULL, 0xFDAE50D064B200BFULL, 0x5031C6B7B55B6A95ULL, 0x03AC8967FEA28CFBULL, 
            0x6ADEB2BA334E25EEULL, 0xF4A940D873C54F06ULL, 0x3BC5FAEAC81B2182ULL, 0x8FDB6330B08F6EEEULL, 
            0x7416A06507258DB7ULL, 0x398F9BECE3AE17B3ULL, 0x39FBD1DC3AB15F9DULL, 0x8CC5B9A51FD41F16ULL
        },
        {
            0x1036AE88CD9012AFULL, 0xAC0343D14C3C9166ULL, 0xD46943CCE1E7B2E7ULL, 0x73F88BC2D6C76D32ULL, 
            0xFBB657413C1E5A49ULL, 0x464F542D0BDBD436ULL, 0xB61752F996D55FF2ULL, 0xF366B6A08AD4E259ULL, 
            0xDED9926D1AF316F1ULL, 0x541E4B636D6103B8ULL, 0xF39ABF4E872F0020ULL, 0x798FEF3188C7CA9EULL, 
            0x97F04E579D71237EULL, 0xA3317FF9BFD57D13ULL, 0x30EC1A9DF6E57737ULL, 0xE27102E3EF78CD1EULL, 
            0xF7EBDB60A6C42169ULL, 0xCECB0ABBFCC66F84ULL, 0xD415642FB35ADBBEULL, 0x8625A13230BB7E5BULL, 
            0xD87718E7A22E8B44ULL, 0xB1B8715F9F5ECAC6ULL, 0x57F92868195DA19CULL, 0x9AB4A8F4E6BF08D1ULL, 
            0xDF45E5D0D19D4F60ULL, 0x4E81A7713B31FFE6ULL, 0xE059B9F6FFB30F5CULL, 0x72397C6505E22BE8ULL, 
            0xC6867571C83E3E9EULL, 0x16359D27241DC17DULL, 0xB00D34460938A846ULL, 0xCF3159BD163F366DULL
        },
        {
            0x80076EDFE5D9A66EULL, 0x549B1DCC030398C4ULL, 0x08DE7EFC8BB53C09ULL, 0xCA2E95E3F6B46EF6ULL, 
            0xF1AA6D1CD091869CULL, 0xA1FDE0DC6EC97AD9ULL, 0xE074EE876CD057C3ULL, 0xB0BD359DAD889EEDULL, 
            0xF44B12E0E7551671ULL, 0x7A8DD10183F94540ULL, 0x363FB75A287C394DULL, 0xB1A0FD7B637E7156ULL, 
            0xD64FA73341C8A270ULL, 0x7EB4CFB9141BE7B2ULL, 0x4F38E59776CEAA65ULL, 0x5581D3388D6A82C5ULL, 
            0xA6D30AA95FFBAA09ULL, 0xF6B975E6C6646A69ULL, 0xF69165338FBACDEEULL, 0xA3B0B6B43D015064ULL, 
            0xA12E64DCE613A875ULL, 0xE7732877E37DCDAEULL, 0xB2232B2114EC9E86ULL, 0xB00608DEA40B2A3CULL, 
            0xC0908126AB72CFC7ULL, 0x123EDCD1EEA9E73FULL, 0x906E71147E30709DULL, 0x5484D653905856F5ULL, 
            0x078358ECA17DFD18ULL, 0x23837B647204E7A5ULL, 0x845E259E0C33A01FULL, 0x1D2F8382498BC898ULL
        },
        {
            0x57A59B5965A46E26ULL, 0xF55290A05176C73AULL, 0xB1AF1238DCCB6DD6ULL, 0xAB235C3A2B01E795ULL, 
            0xC1CD30AD6F06CA4BULL, 0x5BFDDABA29EB257CULL, 0xA38BD498415B0AEEULL, 0xE6D4123B65AAB2BBULL, 
            0x371E7E1BBB098CBCULL, 0x783D7BEDFCF5C60BULL, 0xF2F1BC60D2CC3811ULL, 0xFE22EFD4EADBD4E6ULL, 
            0x85E34BA26335C216ULL, 0xEECF5D0DD914AEA1ULL, 0xC303ADEF0A932A3DULL, 0x7C7E59AFB1247DF9ULL, 
            0x55B561D80D6EB55AULL, 0xE29843737D9D0926ULL, 0x1BCE7A92A30B7378ULL, 0x2F53069525C7A88FULL, 
            0x82D9F2F52F117D2DULL, 0x1A9607F701309755ULL, 0x8FC0595C9794CBDDULL, 0x18374BF4C73D5184ULL, 
            0x2872EC67B43EBEC5ULL, 0x61EC348E65FDB05DULL, 0xED3369AAE547D85EULL, 0x2108C266F555FDB6ULL, 
            0x6FBA14FF1A1C8219ULL, 0x860AF68C5EE4A446ULL, 0x75799D128D10D592ULL, 0xE79E103944DF90EAULL
        },
        {
            0x1E6A227921080EA2ULL, 0x349EB14D3B029437ULL, 0x07FDB588A7CD19B0ULL, 0x764717A4DD49664CULL, 
            0x48CADE98400DCDE2ULL, 0xE393ADC21AE86052ULL, 0xD0DC95FE56075EAFULL, 0x7C5AFDC994D3450DULL, 
            0x27A78249360060E6ULL, 0xA390F5C1525D4D90ULL, 0xD65DFEBAF61488AEULL, 0x1BD7D0667C39D63BULL, 
            0xE616EC0C8703EEA6ULL, 0x8E94F084CD388E11ULL, 0x9E4E1DAC9C264785ULL, 0xECDCB9491627B8B6ULL, 
            0x30458F65CF39F79FULL, 0x241BA867F390A033ULL, 0x59D4C6F933DD7FD5ULL, 0xC327EAAD7C0CEE36ULL, 
            0x617D5ECF62493219ULL, 0x03D6A9548F2AEF52ULL, 0x0A907DCC74B429DCULL, 0x79AEF8C8F371D061ULL, 
            0x70F37E6B28FF2CBFULL, 0xC8CC76391A2EB8E1ULL, 0x59173AFB468E5C22ULL, 0x35D9458ACF0CD529ULL, 
            0x2206085A925715EEULL, 0x9401122592E1BEE0ULL, 0x1751C8BC951B56EDULL, 0x09D5AF05C5B4431AULL
        },
        {
            0x9B22DE3C63A5FF84ULL, 0xF7C57C8389AED58DULL, 0x790D1A0591AC772DULL, 0x4B0013BD9BB3F481ULL, 
            0x2328CE9E1B27FF12ULL, 0x6110B0EE60062A18ULL, 0xCC2A9CE8AA908447ULL, 0x60C156FB457498E9ULL, 
            0x76B1328FA374EB3BULL, 0x2B1D7133ED5FB538ULL, 0x1F3A9DDDC7EC6D8AULL, 0xC359352981164C55ULL, 
            0xFB04400E9B5C5E2BULL, 0x206E3DED0EF7C4FCULL, 0xEE63129832F1D922ULL, 0x75CC4B707BD87E1FULL, 
            0x8C4007549C3EC166ULL, 0x34AA3B27A46CD11AULL, 0x8CA158BFD2490E7BULL, 0xE8E9AEBABC4BDD9DULL, 
            0x893D9FA0ED8D48BCULL, 0xED8EFD9B8547CF7BULL, 0x1FB27733CBE1A45EULL, 0x52BA6474882644FDULL, 
            0xD4C23F4E13DD755FULL, 0xC3D0F461853E57C5ULL, 0xD55F07E63F9B6BEFULL, 0x808ADD9BDAEBB6CBULL, 
            0x1AFB4DF8479CACE1ULL, 0x88FB5CB8C8A23079ULL, 0x0D6EAF72F754C6DCULL, 0x5E052FFC88BFF548ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseDConstants = {
    0x085795F0F7B21885ULL,
    0x4403341E9A7E37BDULL,
    0x203E8C750B6F8496ULL,
    0x085795F0F7B21885ULL,
    0x4403341E9A7E37BDULL,
    0x203E8C750B6F8496ULL,
    0xECEEB4DD119AAEE9ULL,
    0x6BCF6FE70FC79ADBULL,
    0x0D,
    0x60,
    0xB0,
    0x56,
    0x96,
    0xE4,
    0xD6,
    0xDB
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseESalts = {
    {
        {
            0x55DDAEDD1D57E1E3ULL, 0x2A1C50C1851CB427ULL, 0xD51E43FE340B4068ULL, 0x07BB003D9CB4DB73ULL, 
            0x6AFE85C750FEEBA2ULL, 0x1C9D91AD52EC7F2DULL, 0xBAF8A4B0344D5F8FULL, 0x3CF34B7D5783ADC7ULL, 
            0x9E91CA876BC54AC2ULL, 0xD493F9A5ED8F0541ULL, 0x5579FEE4869BA3DCULL, 0xADD073089F8F5388ULL, 
            0x7BDC31BD09007774ULL, 0x31966250F6C755CAULL, 0xFB17169B70923C7BULL, 0x4CC21FF903C82ECAULL, 
            0xE3992C52CC4303C4ULL, 0x62F2018ECA0B5FA1ULL, 0x5E115FF00F994D7BULL, 0x442EFD4731D2A9BFULL, 
            0x6FE2FA9CC36AC278ULL, 0x87878A56168A6B85ULL, 0x78EFD5090ACD36EFULL, 0x47B2DDFE7CEA894BULL, 
            0x4E35BD2079BA94A4ULL, 0x4DA0B0D4158630D3ULL, 0x80D16E39251C0D58ULL, 0xAA0470D9746F2106ULL, 
            0xDCC9F7BBFA710E06ULL, 0x8AF4BD8CDB473B7AULL, 0xE2A3C665AE27F5B2ULL, 0x68ECEE557B8536A7ULL
        },
        {
            0xC9CF2B8BF394488FULL, 0xED7449876FC96786ULL, 0x2CD7FB19C6989802ULL, 0x4F8B1AB6FC744D4AULL, 
            0x30B404D9CE453494ULL, 0xE305561F18189EF6ULL, 0x3EB060923AAFDAADULL, 0xFF9D7F685B0AB6A6ULL, 
            0x8858DBCE312505E9ULL, 0x948F86D993D81423ULL, 0x23B9765E9B2E7DDBULL, 0xF16E68DDC9D14A6FULL, 
            0xEFD0BA85C643F321ULL, 0x42EE6756D24A8FE8ULL, 0x6D0BA9C6B90DDEFDULL, 0x083CF9B529A85BE9ULL, 
            0xF88614588A367D35ULL, 0x231A85170336B006ULL, 0x3E8EA0C0373697F2ULL, 0xA76FE058FB65742EULL, 
            0x4958B8D30F60333DULL, 0xD6D846D705209806ULL, 0x665828888435A7EEULL, 0x10C4E11DBBDD5CCFULL, 
            0xD26EDC9CA504ED06ULL, 0x3293876678F93112ULL, 0x5AD1F18AFF3EA794ULL, 0x563464524FEDBE6EULL, 
            0x7F34C95539ABD0F2ULL, 0x62C4FC02F1AB0287ULL, 0xC6D132C2E145AB81ULL, 0x4A2BB54A8594BABBULL
        },
        {
            0xFFF8E30F570553CAULL, 0x58B5A19628EC9643ULL, 0xE604E7233A1FEEADULL, 0xFD10163ED73C5032ULL, 
            0xCF1163821D3A169FULL, 0x8B654251D56C784CULL, 0x4682A440559D2BE8ULL, 0xF689157069BDD53AULL, 
            0xBFFA97E0BAE3D216ULL, 0xC1EC642194BA1CDDULL, 0xB66AB14042A58DD9ULL, 0xCF426E6AAA4F4346ULL, 
            0x97CA40800BC35E98ULL, 0x3FC794878F7D1F39ULL, 0x5E903814FC9E130DULL, 0x327340177A9B53BAULL, 
            0x84B484D689A18C7CULL, 0x157B18D2A0AE8B4BULL, 0x51C779BBEDFC7A32ULL, 0xA06A7B794ADC30E9ULL, 
            0xBBA4F8873215D520ULL, 0xF4ADCBB8736BEAB7ULL, 0xEF0A9E4E5B72A71DULL, 0xD96F31FED9065E48ULL, 
            0x35C0E9E899E091D5ULL, 0x2021522B917A2845ULL, 0x9F55B2C0328D6AC7ULL, 0x7C1F5BA2C92EE412ULL, 
            0x6F1FC93D18502575ULL, 0x1188505F18A93293ULL, 0x34F6538571065F1BULL, 0xB4E38DFAADED6FAEULL
        },
        {
            0x92DF50756E97577AULL, 0xBAE5A30872B9E437ULL, 0x3C646C1757ED30BAULL, 0xF61015DD57B763A0ULL, 
            0x828F824917FF087AULL, 0x6EE02354FF18AB88ULL, 0x0A13ED6711B5FB98ULL, 0x4C38695297B2CD6EULL, 
            0x29FA4AF1A8F1D948ULL, 0xF3BDA827A87BD8E3ULL, 0x4FAE569323019EBDULL, 0x6C422EEAE6792ABCULL, 
            0x3238013D689FB053ULL, 0x8FDE2184F8848537ULL, 0x719012433A0C8153ULL, 0xB16BA3050877AE03ULL, 
            0xCE0A53227AF797E6ULL, 0x0456E55DE5CE4095ULL, 0xC795CF8416DB6E15ULL, 0x96B7BEBEC97EA488ULL, 
            0x4AC4B4E63A19CE7CULL, 0xB350FF431B1571F7ULL, 0xFF98A9513B82B760ULL, 0x804A6A3D784F571AULL, 
            0x57FA97B85260ECD6ULL, 0xE9BC3F0803145CF8ULL, 0x28D06D66FB21899BULL, 0xB868C0C193695DAFULL, 
            0x137E2820A699F701ULL, 0x621A7AD47433C217ULL, 0xA77625D88056EF7FULL, 0x64A8C45180A80160ULL
        },
        {
            0xEAEB73AE70B09029ULL, 0xF0095BB144E57F13ULL, 0x066FDB88DADC0C33ULL, 0xEFBA5EBE13AF42F3ULL, 
            0xF49EBC13B3DFC05FULL, 0x04E70E9EC99AE3B6ULL, 0x37BB99BD601233E3ULL, 0xF8F2F3CD1508AF6CULL, 
            0xAD8E1AFEE17850B1ULL, 0xD0B333E41AD57889ULL, 0xF023A710035D67E5ULL, 0xEBF6435EE67E7CE7ULL, 
            0x7BBAB36F9E8E1FBFULL, 0x64D8D390BDA3EADDULL, 0x2190DE4BFE52B8B7ULL, 0xEC2AD4CB700222ADULL, 
            0xB3F10DD00C4B3990ULL, 0x3F69E9E0AE89B1D2ULL, 0x9A93A9EA7B6EA5EEULL, 0x7403912BC648ACC1ULL, 
            0xAED08CE7EE8AFD8BULL, 0xF2888E9497D8A1EFULL, 0xF8FFE44F3004716AULL, 0x39893AEC76316160ULL, 
            0xDC6EAD724A72A952ULL, 0xA6377BC4F6CB8414ULL, 0xF772886DC4B1B27EULL, 0xF6F0F83BC544F8B9ULL, 
            0xC8194F10B19C6E4AULL, 0x8380025624E012A0ULL, 0xAD8FC7E03E92AABFULL, 0x7440EB8824190918ULL
        },
        {
            0xAA33587E1FA427F7ULL, 0x8BA20B024B871B6FULL, 0x6011CD8716764105ULL, 0xB4CBB87C89459E8CULL, 
            0x1A82946054643972ULL, 0x787D2A9EC93F76AEULL, 0xE91751E2BF72BB73ULL, 0x9B6B4A68C545DF91ULL, 
            0x91D74A618E87E7DCULL, 0xFE995DE4D6B0C327ULL, 0xE36B9E0ACDE8168DULL, 0x8F70640683395B20ULL, 
            0xA3591C2D5FEAA45FULL, 0x8F2DDA005899B72DULL, 0xE21A57BD577131E8ULL, 0x5A8D59CF6D0C82CEULL, 
            0x05AAFD4CEA4C0EE9ULL, 0x46133C66FD291267ULL, 0xA4812749B6C7B747ULL, 0xAECA9A65F8F738AFULL, 
            0xB79E40898DC022E7ULL, 0xC67DB4023915228FULL, 0x6A67B3C7A7C3E966ULL, 0xDC77DF441D288105ULL, 
            0xBDA9E5D3281563C3ULL, 0xB1FEB66014897A3FULL, 0xB32D43451D1EB395ULL, 0x974C85128188411AULL, 
            0x641662A4935A702DULL, 0xEA6CCD69B4660839ULL, 0xF61CE4DE980728A0ULL, 0x9BFCED86A202E9FBULL
        }
    },
    {
        {
            0x20810A9D17DD6AE9ULL, 0xBF64749DEC685EEBULL, 0xF2E1CB2E3F6E0E80ULL, 0x7F443AFA080FEBD6ULL, 
            0xA056CDC83A2A15E0ULL, 0x217A1AE42AE7B245ULL, 0x37FE83B011315794ULL, 0xD7FC475970E79EA7ULL, 
            0xD65D68B74D6321C5ULL, 0x691D07B2ACA55E39ULL, 0x415C462E704EA620ULL, 0x4F698D33CF35E410ULL, 
            0x286339E2E38F664CULL, 0x829111B377337857ULL, 0xB4C60D21B571783CULL, 0x9562E7192743B545ULL, 
            0x656E55E23EA25F54ULL, 0x8E14F09DB1DAB10AULL, 0x2C6CF49C96A49DFAULL, 0x3CBE13BCF5D2C3B5ULL, 
            0x91DB2C726472D411ULL, 0xA09B99D1223868DDULL, 0xCD053F075E8A32C8ULL, 0x9D55DCE5CC1A8F9FULL, 
            0xAF8986B6D147DAA9ULL, 0xD5B0EF998097A829ULL, 0x6D5D44E6CDC65C05ULL, 0xF9E6F26802346060ULL, 
            0x4E98F76AE8D14122ULL, 0x665C6166FC01BDA4ULL, 0x0BFC1EAD991F673AULL, 0xB5595EA7CA8806BCULL
        },
        {
            0x6D5CD463CB8E08C9ULL, 0xAB09CB4F4EF60D35ULL, 0xA81ADEA948DFE70EULL, 0xAC77C807E48C2467ULL, 
            0xB78276F5E364BD33ULL, 0x96B9FAF357316CE7ULL, 0x4E7DB813E3A423E4ULL, 0x03793310F210E3D5ULL, 
            0xB332C142FA74A0ABULL, 0x37697447DD27FA85ULL, 0x0C2FDE2F35103C15ULL, 0xEBB0B273A393EAD3ULL, 
            0xFBAB52CDEAC5FBBCULL, 0xF507356CDC705BD4ULL, 0x9F06A269B678BCADULL, 0x48487ABC83052D65ULL, 
            0x296DE0CFE6ACCAFBULL, 0xFE52EA89C234B558ULL, 0x096366D7679ECB18ULL, 0x2D31D3F8F8E10581ULL, 
            0xEB97E7E9214B810AULL, 0x8108D456BF0221ABULL, 0xBE6D04C5FCEC2FE9ULL, 0x47C6526F0231DE89ULL, 
            0x6DBEB6162F9F3022ULL, 0x6D5EF724B738C57CULL, 0xE960939C69680DAEULL, 0x6238DF53B66ABC6DULL, 
            0x982FD3A66D50B1C1ULL, 0xD6A5C304EE6535D6ULL, 0x38AC470DEB9D92EEULL, 0xEA53F64892295C10ULL
        },
        {
            0x4F203D29EB3AEB78ULL, 0x8B692568D9A5BC32ULL, 0xC3CDD0DB5952DD10ULL, 0x7A79CC8FA227CD56ULL, 
            0xCDAA101753214985ULL, 0xB1E831FE50120A91ULL, 0xB59AE07E518073D1ULL, 0xDB96B79CF7FC824FULL, 
            0x607E324F8A081EE8ULL, 0xB0787D3E8CD43070ULL, 0xF3B07FFF52005742ULL, 0x6E0CE02D0406FB32ULL, 
            0xAE8E760FC1803FB2ULL, 0x0551B9A772FB3135ULL, 0x9F1FE7BEC491D560ULL, 0x7AD0EE0D1CB7E493ULL, 
            0x772AE3214FBC27DBULL, 0xC6563CDEDAB6D49AULL, 0x80A45A1E8B51BCFAULL, 0x327A531AF2BF6625ULL, 
            0xC4DE73AFCD93692FULL, 0x5DE69C7779956ED4ULL, 0xB7D9A849AD1127B9ULL, 0xA7320EAFAE698985ULL, 
            0xA14A96895F0CFACCULL, 0x6DDA9981FBDD11B9ULL, 0xFA3E787E34F19BF7ULL, 0x691A7910EA3764AAULL, 
            0x934F3F8648F58968ULL, 0xCA91DB29DB64D7B3ULL, 0x48E80F43A75B2A1BULL, 0xE2EE7AFB832ED666ULL
        },
        {
            0x07FCD4D6ACF295ADULL, 0xB315A4B3BF6BA57EULL, 0x48CC433B7F336C8BULL, 0xEB74D2724CB00581ULL, 
            0x3E7A99766B377A47ULL, 0x640E65F88EFE150BULL, 0xB83460BB38704A9EULL, 0x862B63D3C090C843ULL, 
            0x2178020E32F884ABULL, 0x03E33E93B60ECEF4ULL, 0xAA63E7A00D1C6B9FULL, 0x070A0F38DCE3E13FULL, 
            0x05DDC33E33D270FBULL, 0xBBDEDA49DCFC49B7ULL, 0xFCC85710CC1E009BULL, 0xAB655B270BC10B9CULL, 
            0x956904FAE5EB797CULL, 0xB8958AFE51A1C82AULL, 0x14DBC37203219613ULL, 0x406C5B5E48263FDEULL, 
            0x371C3DAFDDE9290CULL, 0xA1614F2BB0838766ULL, 0xA459892833FE13D7ULL, 0xF9B216643260C99FULL, 
            0xE47755B935CCD482ULL, 0x3BF8C014D424D918ULL, 0xC01401352C49E2A3ULL, 0x37CCFFBCC4217415ULL, 
            0x226739332705938BULL, 0x4419D3900A458D22ULL, 0x50C76BF5EF957AADULL, 0x69606F116CCFBA69ULL
        },
        {
            0x1524FBC31E999A40ULL, 0xFF2C42D196CCE364ULL, 0x15290DCC2AEB9856ULL, 0x3B5C5AB2E84F89ADULL, 
            0xC5729F2A70B3EF7DULL, 0xA8F1D38A01FF3CB4ULL, 0xD5C48BE0C680D0ACULL, 0xE080D99B47A165C4ULL, 
            0x20575402FAB2FC33ULL, 0x55240958C9F7869EULL, 0xBCE297C2D955E616ULL, 0x30AF700D62148ADEULL, 
            0x621A907BC2B5CB5EULL, 0xB5F9FDADBCF5D290ULL, 0x9DA1FEEACBA2EA2AULL, 0xA572D07C0B29342EULL, 
            0xAA754BDBA7069EA0ULL, 0x1634C82532B275A1ULL, 0xE46C54E72DE59786ULL, 0x77ACC1276CB6ECD7ULL, 
            0xB313484F63B07322ULL, 0xAD310E00344CDD2EULL, 0x20B960A3573C7E49ULL, 0x7987EDC54D555D18ULL, 
            0x22EB19A8FD5AB1F2ULL, 0x7CB98D1F6CF095C5ULL, 0x341EB4C0DDBB6E64ULL, 0x77F91F371325F6E7ULL, 
            0x0E7D5F28C5BF0838ULL, 0x287D2A14D12B8C77ULL, 0x7910A10410D4B514ULL, 0x664D8A1765591033ULL
        },
        {
            0x9E36C96F3B259B85ULL, 0xD4A6EB5E0C6A749FULL, 0xA4D21D024006EA38ULL, 0xBC5891AED7611F4DULL, 
            0xA6D1CF9E8DCF867DULL, 0xA4225008638DE78FULL, 0x86C7D5EA44DF2A18ULL, 0x5480D241EC5A3617ULL, 
            0x6C0E865F178DB387ULL, 0x377A5E399773757EULL, 0x9B88C3D31F8AD643ULL, 0x523FD8377A00E826ULL, 
            0xE6A7F0FF79CD848BULL, 0x7EC471A3D9D0A61EULL, 0xDE1B922BCE052221ULL, 0xA45E78D3A91BE319ULL, 
            0xDBF02E42748C513CULL, 0xB88CE9FE8C8765FAULL, 0xB7E0063159E41AC4ULL, 0x76FBA91D36B3090DULL, 
            0x6B346E56AE4623E3ULL, 0x842D0F1C012824DCULL, 0xBB755631679D795FULL, 0xD257C2064BF33B2DULL, 
            0x4936C28E53C68056ULL, 0x1B86A9B7A09F92A8ULL, 0xC0BA46462CD700FEULL, 0x4F97DF3991E5E900ULL, 
            0xE9738EFBB463A046ULL, 0xDCBCC218DBB7A656ULL, 0xFE7D7310253DF25AULL, 0x0D366059008A6D41ULL
        }
    },
    {
        {
            0x97D9422053DAAE45ULL, 0xC480EABBBCBC891FULL, 0xE5F7F2ADDB2EE4BAULL, 0x5B5957B76F30AEB3ULL, 
            0x2CE42682C8233B8AULL, 0xCDE3F6A5031B74B3ULL, 0xBC0D905A3939CBF6ULL, 0x58EBFDDF9C221855ULL, 
            0x64DE5908CAA48DF7ULL, 0x41F678DC14725F7BULL, 0x73AD8054D27F4CB4ULL, 0x35882DEEB44D049AULL, 
            0xF30AD075BDB17105ULL, 0xB132BF9868A58B77ULL, 0x614739050ADA0C46ULL, 0x35BE1C81541F512CULL, 
            0x99BD648042DF134EULL, 0x29D5DCD1238BA9D7ULL, 0x0A58B497E5CAB483ULL, 0x04ACD0843F6E83C3ULL, 
            0x55D572DB02D5E36AULL, 0x5654121A3A75A7D7ULL, 0x445992409B9ECAFAULL, 0x6FCF49A9F2EAAA12ULL, 
            0x3762E67C02500E94ULL, 0x05BDB5457B7C6512ULL, 0x8DA0451636E59BB2ULL, 0xF213B5D853D6AE32ULL, 
            0x1013B347E22E3219ULL, 0x8403416BFC7CFC96ULL, 0x00AA9BA3D4548A5EULL, 0xE9DBA7392467C73AULL
        },
        {
            0x217CD811AE3E21F5ULL, 0x9CE4F18109F750D3ULL, 0xAA8C637033D16FFEULL, 0x4518CA876D1FDB41ULL, 
            0xF17EEF91FFDD3159ULL, 0xD6877F40F64C1310ULL, 0x5D9A3BCB27C0610EULL, 0x44A3B3AEDBBFECF3ULL, 
            0x640FEE6083F18AF1ULL, 0x22CE663AC1DC554AULL, 0x2539CA54167137E9ULL, 0x392E84FAF7D3ED42ULL, 
            0x9559020023F521C0ULL, 0xCC315A1D2A1AAD37ULL, 0xFC9A15FDA8BAB991ULL, 0xDDFC130158B282F0ULL, 
            0xF9EFA418680302C3ULL, 0x344A4FB002A32EA3ULL, 0xC7F0ED7D359F4959ULL, 0x00004D998AB50245ULL, 
            0x61C1945ADEA4BADDULL, 0x9EF5D6DDE7B33888ULL, 0xFC4667B4DF0F8453ULL, 0xA15EC2D9868A8332ULL, 
            0x279E48CA3B44F677ULL, 0x58B0EEBEF7BAA18FULL, 0xBAC154FFD9B27883ULL, 0x29E45757DC1E8F6AULL, 
            0x59EEAB9C5C492F8DULL, 0xA206B9BA1BEE1D27ULL, 0x0522CFE25F180914ULL, 0x9142C74085870F10ULL
        },
        {
            0x41985F14DA7D9E6CULL, 0xEEC25E6A2B9F4DA5ULL, 0xE488DE50A5889A43ULL, 0x6965CA2AE957A974ULL, 
            0x92C08149D3D05D7CULL, 0xA0CC42F42E6CBB4AULL, 0xDC2E48B6139BB68EULL, 0xF9194E6DD7C488A3ULL, 
            0xF50EAF81E4063579ULL, 0x3DBC0A0F9F080A94ULL, 0xD529BA7E5643B992ULL, 0x893175B47F8AA030ULL, 
            0x33777C4FDE957C3CULL, 0x7FDCBB14F39EE34AULL, 0x33892B221F3C981CULL, 0x715E901831994761ULL, 
            0x4FD737A02FB82666ULL, 0xCBA918CD59334C63ULL, 0x86AA18D0047A1B34ULL, 0x8EA43F755905189CULL, 
            0x8557637AA9A1AA93ULL, 0x5C66060E8796A6ECULL, 0xAAB5448F83DB2DF5ULL, 0x2B99FA1748277BC0ULL, 
            0xBAD6173538D10022ULL, 0x6A57A83E66C41E02ULL, 0xD7CBB2D637CD3FEAULL, 0xFE3D6BC5CFDC4F60ULL, 
            0x5A56F478B3C1D840ULL, 0x9D64369A84B1F936ULL, 0xD7582798375FE59EULL, 0xE89FE72DC0F8BF46ULL
        },
        {
            0x3868DF130EFC4541ULL, 0x1820120061CDB71AULL, 0x52059828C4B8DFC6ULL, 0xB83F9C41711AE8C3ULL, 
            0x1FD1EA68EC1B91D8ULL, 0x44503662C9EED61EULL, 0xC3A47D737AFBE99BULL, 0xCEFAD7138122ACE3ULL, 
            0x9738AF2B36743EC3ULL, 0x8A6C2C7341E2BDB2ULL, 0x9F44F27F96BC0D63ULL, 0x260D19E9A080BE26ULL, 
            0xCD169639426FD249ULL, 0x62BE20D612D0DB56ULL, 0x1D0EEA7971E4D451ULL, 0xF2EB98035A654A3EULL, 
            0xFEF38738A8633EAEULL, 0xFE0A29ACF81EE834ULL, 0x232A4FD29D041605ULL, 0x48AF3D6E9B923F94ULL, 
            0xD0D852B19C4B5FBCULL, 0x4A40999DE9A803AAULL, 0xC31CF1671AED2608ULL, 0x5BBC615CCAAC25A4ULL, 
            0x58C3246E5852217BULL, 0x8FFD18EB1E89629BULL, 0x8380E99E9CDE13D2ULL, 0x03E87C5EABC76249ULL, 
            0x8E389D8224D5F8E7ULL, 0xDE90B5E2EFC2EB17ULL, 0x324517BABC849556ULL, 0x47301368F19D18A6ULL
        },
        {
            0xE2E0028700275C1DULL, 0x5A17B7A51F8882B7ULL, 0xF339F2BE63A5ED31ULL, 0x3BE2EA76301F5107ULL, 
            0xC4314DEB8D8A7960ULL, 0x75F037C02A66440CULL, 0x5F998D8206179EFEULL, 0x831F502EE670F6F6ULL, 
            0x1380B73D1AF0640DULL, 0xD5A8EDFA932E15CCULL, 0x618DCA76306F1E24ULL, 0xB3D97EE5F7710273ULL, 
            0x3C9CFD1ED58B3744ULL, 0xFD22DF6EC22D7083ULL, 0xAFD4F103DB99B7D8ULL, 0x0F0977DE85F80599ULL, 
            0x50DAC48EC301A9EBULL, 0xC3DC68AAB7A9E26EULL, 0x9F3ABD4ADDB96DA2ULL, 0x6629714ECFD79C86ULL, 
            0x22CD5CA23B929972ULL, 0xFB37E7EEAA1E440DULL, 0xB80CBF9AEDF23BC8ULL, 0x1E5592AA39060676ULL, 
            0xD8079C9707273D83ULL, 0x56589D54C502A999ULL, 0x695BAB89CD8BC231ULL, 0x6744F1178E38DC7FULL, 
            0x08D95E84A61330AAULL, 0xC8F0A301FAB6DB10ULL, 0xDC34B9A3845FBE71ULL, 0xBAFE23A29EBFCA08ULL
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

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseEConstants = {
    0x3B249EA5A1B1AB34ULL,
    0x1EA685E9FD57834DULL,
    0xA545B574CE3610A4ULL,
    0x3B249EA5A1B1AB34ULL,
    0x1EA685E9FD57834DULL,
    0xA545B574CE3610A4ULL,
    0xB05E5092BF46F56CULL,
    0x5D96552ED7532F37ULL,
    0x4C,
    0x41,
    0x21,
    0x83,
    0x53,
    0xA4,
    0x48,
    0xAE
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseFSalts = {
    {
        {
            0xE342BDC4F4DC8CC5ULL, 0x1E2480932CC828B4ULL, 0xB7E8CA5DF85F6791ULL, 0x3535BD0361A967A7ULL, 
            0x70937BB46C595DC6ULL, 0x1C2E5731CDF8F9D5ULL, 0x58F525D0CFE902D0ULL, 0xBCF61DBD2F73EE5CULL, 
            0x827990268E7A2BE2ULL, 0xDD36DCAD1B9FAC86ULL, 0x8FD62B4C186A2511ULL, 0x30484F64891545ADULL, 
            0x7AF5949A8E09DFE4ULL, 0x897D3E1FCC0FBCF7ULL, 0x28D08914BC0BF110ULL, 0xBC624834FD708B18ULL, 
            0x4842DFACC506DEC1ULL, 0x4A4BBB94AD97242FULL, 0xD1DFDFCFAEBF5A4FULL, 0x90A29A3F305C0582ULL, 
            0x6A8552E9EBFAD438ULL, 0xFDA12EFD33ECC4B5ULL, 0x08257AFF3A8F2F9BULL, 0x5D6C53AF80876D72ULL, 
            0xBBCEC36F0A7B7849ULL, 0xD7130C15C4F072A7ULL, 0x7CCF13CDADE14395ULL, 0xAD8D5BCE8CFD1FC5ULL, 
            0x07A66AD54F6CAE1CULL, 0x50B0F16C24FD2597ULL, 0x17EEACE5D79721DBULL, 0xF82D62A8DE40EE83ULL
        },
        {
            0xCF6D2487B4CF976AULL, 0x98AF1E9306E521D4ULL, 0x36AC1AA81E48CDFDULL, 0x9EEE46B729C5ECF5ULL, 
            0x30B989845152F4B3ULL, 0xCE9BCB8E417C08F9ULL, 0xF91DB9115C5BA129ULL, 0x27D7B711B07C39B7ULL, 
            0xE5EBFCBD34F2188AULL, 0xB9F8AA1421390B48ULL, 0xA546D35B2CEAA762ULL, 0xC8B37057E50EDDBFULL, 
            0x690CDAC261C55702ULL, 0x6EC26798F6472482ULL, 0x01A3880F607BD7D9ULL, 0xCFDC310947BA8576ULL, 
            0x3AC2844F7D5587BEULL, 0x3A32359E9D80F056ULL, 0xA1D8D6C47699A01AULL, 0xF0611ACA09E8E1FBULL, 
            0x2673358679050256ULL, 0xAB80535645C0D4B6ULL, 0xEE9C548BA2B0B34AULL, 0x31CAA926E73BDADCULL, 
            0xBEF725CCBBB8BF81ULL, 0xD0D289BA110F72FAULL, 0xCCA4817A5EE09370ULL, 0x7D34FA6473922AA4ULL, 
            0x715C1DF602E13D9FULL, 0x148A3ACA82E4933CULL, 0x7C084CD3F5E1D94BULL, 0x6DFBB48CB7994EEEULL
        },
        {
            0xBC53C84DAA0AB34CULL, 0x478B88DBF3B31DB8ULL, 0x3212CCF46DB7DA10ULL, 0xE5425E2DF8AE1B8CULL, 
            0x5438F1361ADB948CULL, 0xCC2D98432258D856ULL, 0xB1F9BADF6E5B3C55ULL, 0xD672BA8F075B4B3DULL, 
            0xA50790573138739FULL, 0xD597354108765FC6ULL, 0x1AF209BD2D2B32B8ULL, 0xBE53319CF5E8F34AULL, 
            0xEEBACAD4A16CCC3BULL, 0xE5F697E2E86AFDE1ULL, 0xFA55033028176ED9ULL, 0xC4A1A1E6A4A18B15ULL, 
            0xD8B9B7E786FFD888ULL, 0x3B07FB09087FA8E4ULL, 0x11EE7E5E5BEE48CBULL, 0xC0D944BE71DB620BULL, 
            0x54798D844EB714EDULL, 0x9A26780A0DB19A7FULL, 0x78F6FBE64D497341ULL, 0x1168C1FACA692AFBULL, 
            0xBFE7EA2935DB5B1DULL, 0x5615688CDDB8641FULL, 0x15860326EEF7B2F2ULL, 0x4EA9FE3BFC0F43FBULL, 
            0xB9B5E43636674202ULL, 0xB6B5345BB2920EC7ULL, 0xEB87BB7D297B8C92ULL, 0xBD52AA8F960B48A7ULL
        },
        {
            0x9DE12CD1D1F2ED15ULL, 0xF34E3632FE06C4F5ULL, 0x1D2467285BC07313ULL, 0xCD11898A24788CBFULL, 
            0xD25F82A9B73A6F35ULL, 0x2091C65940546310ULL, 0x3BA1DDC31BDEAAD6ULL, 0xC9BE1FC207BCC0E7ULL, 
            0x883A4D9D43C3A1C3ULL, 0xD7A2E96CD8E32F76ULL, 0x095543EC2D485E8CULL, 0xE3E47372E87CE3E8ULL, 
            0x5BFEA47569C0B003ULL, 0x9BF751ED8ED26064ULL, 0xCA05D55B6425DFC6ULL, 0x640012EFC87B6D88ULL, 
            0xB256BCEEFD4DD7D8ULL, 0x452490E86935BAC2ULL, 0xA5FFD7E02D4DECBCULL, 0x008742F5F77ADBA1ULL, 
            0xD592EC5294A02CA9ULL, 0x69EAF2C12A3F73F8ULL, 0x95997B2F78B61A5DULL, 0xDC24E3AD1086F42CULL, 
            0x300C9CE42237F208ULL, 0x680C093BFC9B6048ULL, 0x53B840B92930C939ULL, 0x644EED0C8C5C63F7ULL, 
            0x48D7D8F3312F789AULL, 0xD2A971C9B7147F0AULL, 0xD5CB641929F9F9D3ULL, 0xC4420DAD357DF2DDULL
        },
        {
            0xA8CB516142E7E1BEULL, 0xF39A22CD24345087ULL, 0x5BBB6A80386CD5E7ULL, 0x00101FA89DEFFB57ULL, 
            0x6AAF13ED9F49134AULL, 0x528A5860F991E242ULL, 0x159F50C8C0C25BE4ULL, 0x3106A03E986D2D15ULL, 
            0x091BF271C95C996AULL, 0x3EBF195C6926A67BULL, 0x17DA559FFA530436ULL, 0x366FEB1DF4C3B4AFULL, 
            0x1C8236E585AA9A56ULL, 0x996BFBD36590E82BULL, 0xA7BC5E2FD91E79F8ULL, 0x6D771FA3D94A7C2DULL, 
            0x26FE138E94B9FA54ULL, 0x8EEF44699D239B65ULL, 0xC740D3D4EFB224D4ULL, 0x1C1A323E7A688F4FULL, 
            0xCFCA8C4F2457C7B2ULL, 0x100A78E81C46BB32ULL, 0x1FB48BE93B83CDE3ULL, 0xB18BAD223277E7FBULL, 
            0x8DFD9E303BBFF683ULL, 0x1BE6EF5C4DCCDAE9ULL, 0x653F15BC86042C3BULL, 0x3C0FE1E7656AB836ULL, 
            0x90FE16D77F61EEB3ULL, 0x7B81611DD03FB859ULL, 0x35713342346D4374ULL, 0xA764E1213DF0917BULL
        },
        {
            0xAAED278252071E05ULL, 0x89AB1FF0DEFC646DULL, 0x7AF9399986F18A2EULL, 0x548D010D0A4C269CULL, 
            0x37052CC76BD28049ULL, 0xE4B78DD6B6C877F7ULL, 0xC8DB3A8B692CB28CULL, 0xC24357B5300A7343ULL, 
            0xB2644F426D01AADBULL, 0x87E5EF397EB6C845ULL, 0x4584F0CF58CDD20AULL, 0x1627E37E4DB61354ULL, 
            0x5DFFB9B6AE406D49ULL, 0x81F2A833C35072E2ULL, 0x65E8A5C30B272263ULL, 0x1653EFA68DFF9891ULL, 
            0x1EF05B4188C23B82ULL, 0xF850BF68BD5298C6ULL, 0x6592DD2728C0366CULL, 0x28E6F53FC15F965CULL, 
            0x04BC8548B84B94A4ULL, 0x70D9FDC5BDA93012ULL, 0x2928057DD983DF62ULL, 0x48181E807F1AF5ADULL, 
            0x5B25A9679F8DB205ULL, 0xFB59CE83D69BD7CEULL, 0x8972C162C6FFEE90ULL, 0xBFDA3A3B08290CBBULL, 
            0x54A9371AE9738803ULL, 0x578629543D40D32DULL, 0xB7F2D36711D568CAULL, 0x4BAB6F74DDCAE208ULL
        }
    },
    {
        {
            0xF310009E40A50623ULL, 0xCF02872AF8803AB4ULL, 0xEA41D0B9C092E776ULL, 0x44FF1B4D93565234ULL, 
            0x347EF5FA7065447FULL, 0x3D3C5ED3C1986E85ULL, 0xE9453A3E30A0CE44ULL, 0x9EBEB3E01E930128ULL, 
            0x0C4FDF285AB6DDAAULL, 0x1FCE703239B63168ULL, 0xE57797A8784B3FDEULL, 0x7D4F1AE44803AFD2ULL, 
            0x047726D29825FB43ULL, 0x31F7D76375062832ULL, 0xE5C00074D71F04E1ULL, 0xC2104780A905E19AULL, 
            0xF7490AA29860C2ECULL, 0x30D89CF862BDA5D9ULL, 0x54FB9A150E18D51EULL, 0x0D92E1BF971BC30FULL, 
            0x2CE9DF1F25DCCC0FULL, 0xC658058866618DADULL, 0x41D4804FD3F07CA0ULL, 0x1953D4E3C934587FULL, 
            0x5BD3F2DED6FE78CDULL, 0x2ED9BBAC3AB9FC25ULL, 0x043F770BDA3D6830ULL, 0xFE37BAF7490A9872ULL, 
            0x5C00C243E6692572ULL, 0xE5CC6D9861A7E8A9ULL, 0x072FCC2DA2C8DB82ULL, 0x4F1F432EFA5AD09BULL
        },
        {
            0xCADFC2A0DEFFD8A8ULL, 0x9A95D4774B60E461ULL, 0x0EEF185779D1B829ULL, 0x78E7BD459A929754ULL, 
            0x0252212FC4B2A729ULL, 0xC85A2448C8F7998EULL, 0x5B82001904891657ULL, 0x7E4B618D6D448BB1ULL, 
            0x1D1A7AA955ED6B12ULL, 0x589372BCE614F88DULL, 0xB2606EC2C366FF23ULL, 0xF5D743827F4FA909ULL, 
            0x4D6055755BBB91F5ULL, 0xCCA5A7A94DD61E3FULL, 0x853E282339B10EE2ULL, 0x0A9A09ED046854DEULL, 
            0xC21F2C072ABB5DB3ULL, 0x1379430C30B4238BULL, 0x13E9DB14939B94BEULL, 0x73F23911433B987AULL, 
            0xD312729B4A0150CAULL, 0xC288BFC31A7F92CCULL, 0x12C3EE88154EDE62ULL, 0x1A0857F8B8AC7C86ULL, 
            0x0A1B8A4EBBFDE2D3ULL, 0xA887AED4EB008F5DULL, 0x0D4E9E799AA7FA01ULL, 0x85B4F517D78813ACULL, 
            0x5E98D11DD155217DULL, 0xD093EF7FBB56CB92ULL, 0x9DBA8EADB49C2247ULL, 0x91AA1AA9E7F05DE5ULL
        },
        {
            0x91047FA1EB46D87CULL, 0x8BBFC6A06902A5E1ULL, 0x9B300D28939804FFULL, 0x2DA2EB6299D81286ULL, 
            0xF373AC07F66D9358ULL, 0x94F69A2820124C53ULL, 0x6D2D6143DBA5CE10ULL, 0x0390BCFF896FE187ULL, 
            0x6039F153B3A263E0ULL, 0x78646EE4611B3322ULL, 0x7A292038D77AF475ULL, 0xBC01AC6A0170CE74ULL, 
            0xFF11D94FE4698899ULL, 0x3E14963719F96CD6ULL, 0x51B277687819E86AULL, 0x665A6A8E45372ACBULL, 
            0x39F4852094005168ULL, 0x57130475BC618EE1ULL, 0x18E28F68694F25A6ULL, 0x44944DD68ABC2D49ULL, 
            0x9741533BA01CD27FULL, 0x5DE570F81C340307ULL, 0xBB0C2664872BDDB5ULL, 0x51114C31F29207A1ULL, 
            0x0C81CC4CB90E6E9AULL, 0x8E596A8048E8D21AULL, 0x31214376B2CDF087ULL, 0xCBB0091B8399ED54ULL, 
            0x5CE28A7FF51EC86DULL, 0xC30F7B6023AD5F62ULL, 0xEECA92043CBFB071ULL, 0xCA49DD31E674159AULL
        },
        {
            0x19DEB2A279048049ULL, 0x548D39FB6E91734AULL, 0xDD86C3D2971565D8ULL, 0x3967EC50B6EBDB85ULL, 
            0x1F7C0714652902E7ULL, 0x21C8EA895E1F050BULL, 0xD7AC7B0F8BE19B4BULL, 0xC468F09C8FF6ED3CULL, 
            0x16B506F3665237D1ULL, 0x3ACE015C8F2A9027ULL, 0x81C55C5E92A0B1D6ULL, 0x1D402D5DD127EFF1ULL, 
            0x653A370F1DF71D9DULL, 0xFD7ADBF64D95BF72ULL, 0x7BEC682BCF259656ULL, 0x127D896E3D3DB389ULL, 
            0xBE62B1EA3C841C6BULL, 0x2242C75EC306BCA7ULL, 0xF062C6F90C9B3FB3ULL, 0xB4144AED9F890CF9ULL, 
            0xF376A7122F5A4212ULL, 0x724638CA221A06D9ULL, 0xCF80316FF077204DULL, 0x822963FFCFF6C6C7ULL, 
            0x02F8C8FF920DBA3BULL, 0xE70A5306AB93BC76ULL, 0xF0C0C39BC122E993ULL, 0xE90238F1A32AAC66ULL, 
            0xB14F021951AE1C5BULL, 0xCA7E86C220C63D3BULL, 0x6798C0F3BA51953DULL, 0x979F042D7AB6A2E0ULL
        },
        {
            0xDCA761AC9B3B1175ULL, 0xDB544B572C8519C2ULL, 0x98BD479D422496AEULL, 0x43A86E8989AD9557ULL, 
            0x3F43679753959789ULL, 0x685B8CD3EBFBF3BEULL, 0xC78658E8C0411135ULL, 0xBAF505E2060F291AULL, 
            0x9C72B8DA43DE3BD5ULL, 0x3F87CB4C2EC749E1ULL, 0xFBF57198139A417EULL, 0x23BD43391E6AF550ULL, 
            0x27586989F90A811AULL, 0x04B9D0EBA913555BULL, 0x30B3892711E9916AULL, 0xA39B728EF61B2BB3ULL, 
            0xBC48D158A5192F24ULL, 0xFF2D417623BCF68DULL, 0x734FBF1E67968FADULL, 0xFE337D9AB8451342ULL, 
            0xEE02B264E7408514ULL, 0x2568D77738E219BFULL, 0xE98A37AF680B7CA3ULL, 0x5E159870DAC94A41ULL, 
            0xF7BF7EE765D31050ULL, 0x0F0A9408FAC32F08ULL, 0xF93BF05E5B2236BAULL, 0xA7A2B23794EF8B54ULL, 
            0xC635E8BE43B10146ULL, 0xA5E686AA3C39246AULL, 0x713D2350DF7B5383ULL, 0xD52BC6ED5688BB83ULL
        },
        {
            0x2CB21E760A898E2FULL, 0xBE5CB6DCA81DC2F1ULL, 0xDDFF31BDCE9135BCULL, 0xD82945B04409BB41ULL, 
            0x6CFF9DBB436BD953ULL, 0xC927177E69D1D135ULL, 0xA1A0DDD8AD70B11CULL, 0x2F0DDA8EADAD749EULL, 
            0x7B98F2D551130068ULL, 0x01DC219CC62F32FAULL, 0x33D57714B9A86441ULL, 0xF042C636F2B20B8CULL, 
            0x7FEAC9D50B9B2665ULL, 0xE3FADF3456769548ULL, 0x9B9E62D7303E2005ULL, 0xAE391A935C12321FULL, 
            0xB6AC521D5B4CB4F6ULL, 0x2ACA086CB44303C2ULL, 0xD9473BF5F66254FAULL, 0x4196B7E8E8B93C1EULL, 
            0x15D1FEC0A6C1AF9EULL, 0xF0FD8C8D52904589ULL, 0xCC7B46EBC9513C61ULL, 0x50898BD1D90D6A21ULL, 
            0x38EAC95F52D844D8ULL, 0x6650AA904B445BBBULL, 0xF2220A70067492E9ULL, 0xCAC2FB4458CD94D8ULL, 
            0x49B1A12A8ACE7ACEULL, 0x0057348E3319B052ULL, 0xF353DBA03524E1F4ULL, 0xCB6BDEBFBDCEDDDDULL
        }
    },
    {
        {
            0x9D1B1872AC166B72ULL, 0xC01DE85305B9CD31ULL, 0x0E522A107DDB3BCCULL, 0xD25A31906B8BD111ULL, 
            0x367F07417496F121ULL, 0x30E655E81AF67E09ULL, 0x8A2CE6C2078F5EE5ULL, 0xD7AB8538F6D4C575ULL, 
            0x4C66BF1F4355C1FBULL, 0x44BAF1F71DC9A1DBULL, 0x6D05EC2AC85AA5CEULL, 0xB9F96DFE9D818672ULL, 
            0x6C78AF044347D425ULL, 0xD5672D18C46207CDULL, 0xAFD8EC24877C33BFULL, 0x2F14A4D4FFA8E50FULL, 
            0x8D7F3AD7E5E3F259ULL, 0x46CB017FE223376EULL, 0xE239962FA5EB589AULL, 0xB4B0CD46EF9A3BB6ULL, 
            0x648ACACA6901221DULL, 0x93B37259043EE2A2ULL, 0xA9D9CCE4DFBCA764ULL, 0x3A9E1ED0F6D90C62ULL, 
            0x6D06D9FD5B9C0729ULL, 0x94D5FE059BD8CAEDULL, 0x083E01FC2F8B8552ULL, 0xDD31139CEB8FD0FAULL, 
            0xE3D1EF9D8A488220ULL, 0x0010A35EF7696054ULL, 0xB58AA734F31D096FULL, 0xD00C3CC0324AE594ULL
        },
        {
            0xC3844E53901F6C86ULL, 0xB89ED6BE2C3566D3ULL, 0x5A27EAE31D518D0DULL, 0x408E8844A9B59C21ULL, 
            0x78F81A56456F27E6ULL, 0x52CCC8DE416012B3ULL, 0xDEBD38D7300B57F3ULL, 0x403783C270C9A189ULL, 
            0x577044A4CB81BF5DULL, 0x66B71FD66DFE768DULL, 0xADEC9C9F6D55543AULL, 0x8EB6198FAF5FA308ULL, 
            0x74F8F13D91DAB02EULL, 0xBEB8D6F463E21483ULL, 0x81F42A9F45C59EC3ULL, 0x20587C1EEB098252ULL, 
            0xDF20A34226944BAEULL, 0x63428C5BBBB51595ULL, 0xCA37FC6CF9ED5413ULL, 0x5CE6C1E2F6954F24ULL, 
            0xB8E4DBA64009048AULL, 0x2655F41B0360FE3DULL, 0x48D895567373CA02ULL, 0x71EDFE6F326DB91FULL, 
            0xED81ECA4536F5D55ULL, 0xBC89F1D64094F9F1ULL, 0x2185B2435401959BULL, 0x2BAF4D32B4B3F116ULL, 
            0xC4C62030013BB9E5ULL, 0xE21393924E9231F4ULL, 0xBB357C868FD1E38BULL, 0xF47872166624328AULL
        },
        {
            0xFF8C0E516A9E9250ULL, 0x722397234DC0D44DULL, 0x8A66BC3CA115B437ULL, 0x8F0A0ABB0AE5E252ULL, 
            0xE39525A9F96E3827ULL, 0x64F73A2B6425A810ULL, 0x6F53915A32474E94ULL, 0x348BA7EC71DE00A9ULL, 
            0xD79C3EF2986E410AULL, 0x75C48B3D5C0175C2ULL, 0x16D097E3B5328717ULL, 0x5FDA428063807A88ULL, 
            0x154E933391EA9A62ULL, 0xE91D84923CA2D844ULL, 0xE7C1CE5204C18725ULL, 0x03FB50C44BE9A6F6ULL, 
            0x57848DD50E2B7A50ULL, 0x95FAE3568C48EE28ULL, 0x90E94F858EC4529CULL, 0xCF73F89EC8A7854DULL, 
            0xF7E251DDA0C211B7ULL, 0x00A0A582698C32CCULL, 0x4834B723550B3323ULL, 0x6CCBA15E4E25BF22ULL, 
            0x5F38818874BF4EC8ULL, 0x2D4CF4C85ABC3124ULL, 0x6C4A392BB84D675CULL, 0x7427F142D93CB71DULL, 
            0x0713C42FDBEF2ECBULL, 0xCA47229412D36D73ULL, 0x5842662E7B83D26DULL, 0x63429D73D6553776ULL
        },
        {
            0x8FBDE5B4CD5F8287ULL, 0x9EC57DF940429240ULL, 0xDB4FD6EDB38DFA34ULL, 0xEFAA52D98B73DAD4ULL, 
            0xC9D022B05BEC990CULL, 0x3C5F895D94A60316ULL, 0x4C0D62FF71F0CC09ULL, 0x6303245F4EC648EDULL, 
            0x2C24048893B17DC6ULL, 0xD315201A13A94723ULL, 0x322F8A48D05BA471ULL, 0xA1705D9F8C8B7BFEULL, 
            0x2D3DE6BD5166A2C4ULL, 0x09A7E15C9539E4A7ULL, 0x36DF3121C0E05D0AULL, 0x90143EF181F64FC8ULL, 
            0x339D107C57E08FFAULL, 0xBE458A5C881266D8ULL, 0xAAD8FDE91BEA2220ULL, 0xCABB37283A9415EEULL, 
            0xBE02FC0F0D2EEC7EULL, 0x7779EE029AD193E6ULL, 0x92093019FB4CC229ULL, 0x36865C5BB2ECAAD5ULL, 
            0xA318836B035EBE10ULL, 0xBC46BDD956846FE1ULL, 0xC70B14BE6E7BEE7DULL, 0xF98E0B69CC27B16DULL, 
            0x23CDFF291778ED14ULL, 0x84F27F798286F1E7ULL, 0x1AD60EABCB2B8A6CULL, 0x91933FAD0F0F4633ULL
        },
        {
            0x261784444A883E89ULL, 0xEE66A391E50721F9ULL, 0x567A4083FDEA84F3ULL, 0x04022608385633A1ULL, 
            0x827B5FAC13BADAFBULL, 0xF0CDD04DFFA0ED7CULL, 0x7E34449F99CD7762ULL, 0xC982CC6A5F09AF33ULL, 
            0xC89B21C21C8CAEE4ULL, 0x3F11389CE882305FULL, 0x137F5E092EB92411ULL, 0xE7B2F02071674858ULL, 
            0xF2BD1F236313989FULL, 0xDFA5D43BFE9A7B59ULL, 0xC82C794FDA3B0411ULL, 0x128A3F4FECC9A4DAULL, 
            0x29EC5FEA3F77CF5DULL, 0xB131F8C9F8E9E0A9ULL, 0x0E373D4D915A4B34ULL, 0x9EDAF8A848716CA5ULL, 
            0xADD5809C7B91B5F6ULL, 0x1CD93690C9A118D2ULL, 0x0B5CA20414141018ULL, 0xAD1B99E225AC5E4EULL, 
            0x17A8802486797FBFULL, 0x9048B2A89FB1BDCEULL, 0xDFDC2C8FCD360C07ULL, 0xE484EE9DBC278B6CULL, 
            0x52489DAB7CB108BEULL, 0x429D96C0A15DCE00ULL, 0x25EFB1DD75626368ULL, 0xF1F4E74C23DF1795ULL
        },
        {
            0x86956BE3369BB422ULL, 0xD83CD2CE60D5563FULL, 0xDD8EE38560698477ULL, 0x12FAFD2EE3572A9EULL, 
            0xA4DFE36556E9AEE5ULL, 0x68D430114500E9D0ULL, 0x08F3895B5BD5B932ULL, 0x55F1E8C06CAB25CCULL, 
            0x026E4F321A104155ULL, 0x60403E696A55BD35ULL, 0xDA9CAFDE7CC1A09AULL, 0x2D4739E523D2E759ULL, 
            0x4A831C65FF7943BEULL, 0x02D680FF0A5F18D4ULL, 0x85BD969E34C311D7ULL, 0x5C6482DCE5C77315ULL, 
            0x67969490E6D524A2ULL, 0x30936134F4D86D32ULL, 0xC9FD738361999DD4ULL, 0xC11075E6B6E5E8F0ULL, 
            0x7AA00D5809705F44ULL, 0xCA5747007A56A291ULL, 0x3AC383D088632F66ULL, 0xA323D1F069ADC93AULL, 
            0x9EA7F09D56A96A61ULL, 0xFE71EF64E179B03FULL, 0x20984429E5E835AEULL, 0x302315DCD618439FULL, 
            0x5F68A35EA272BE2AULL, 0x70F9FF021A700D8CULL, 0x46633EDFA84CE404ULL, 0xB5C77E4FD884EF9AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseFConstants = {
    0x36851EBB73622ED6ULL,
    0x02C12BB32754326CULL,
    0x0608CEE5A7E59CB4ULL,
    0x36851EBB73622ED6ULL,
    0x02C12BB32754326CULL,
    0x0608CEE5A7E59CB4ULL,
    0x21854FFBAC25A2C7ULL,
    0x6C7D76AA507FE436ULL,
    0x81,
    0x84,
    0x8B,
    0x49,
    0x4B,
    0x33,
    0x2C,
    0x22
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseGSalts = {
    {
        {
            0xCC46076B818F6419ULL, 0xE94011967B9B3F31ULL, 0x0B27F6E9D0A80FBFULL, 0x3EDE484C0C032303ULL, 
            0x5BC1956EC833B25AULL, 0x7D03F31FE7EBCDA1ULL, 0x31248D55CD298407ULL, 0x8223C93680B64637ULL, 
            0x18AE10B25D8BEE5EULL, 0x9CAEAD909A252529ULL, 0x477294919426149EULL, 0x03FE3E0F85DAB15CULL, 
            0x123AFD5AF01F75C5ULL, 0x483FADFE003F0BE4ULL, 0xCBDE43C36615CE8DULL, 0x453919988C596EA4ULL, 
            0xC2ADA2A688AC9D24ULL, 0xB69371F77F601BD5ULL, 0x219928F7E0FD5591ULL, 0x0B9539CFADB87693ULL, 
            0x625E0871BD799A87ULL, 0x80B0DC69C39EC060ULL, 0xF140E42BECF22F79ULL, 0x5784D4CE60B14046ULL, 
            0x8E80C2880DACD30DULL, 0x76A0BE357C693D6BULL, 0x7AE4A3510EB7D4EDULL, 0x50A5B66966A2CC38ULL, 
            0xD00D6845DDC602CEULL, 0x982A001C74B89D58ULL, 0x7D85EE7DFB11B08CULL, 0x7EA64F4E40F5BDEDULL
        },
        {
            0x5793381870D9DF6AULL, 0x61E9DAB5C5FF1DE9ULL, 0x191D3AD60D3632E3ULL, 0xC24A06C7CB12FDA9ULL, 
            0x5050A20AEAF175B4ULL, 0xB58F99351B6FA1A6ULL, 0xCCD6966F38447B19ULL, 0xBEDAB70954E601BFULL, 
            0x0E98109DA50D0DD3ULL, 0xAF5EC178B29AEBE9ULL, 0x738F63AE64E508BCULL, 0x1503F2C1AF796002ULL, 
            0xAD7EEEEE9C6B03E3ULL, 0xB28218034EAE247CULL, 0xCEC301EF0C3A9857ULL, 0xE06E737918F5AB28ULL, 
            0xFF83AC71D696389DULL, 0xCF1EC7B8B25FCB5CULL, 0x8440B94ED1DA71A8ULL, 0x1B1A0DDE9116CD0CULL, 
            0x3C3000F3A11B253FULL, 0xE4F461B00208514FULL, 0xA4B8E401C6F92057ULL, 0x49F27BAFAB1F8A57ULL, 
            0x3433699A205AA63DULL, 0x6D32B47B4ED1833CULL, 0xA1DEFBE1D2A154CAULL, 0xA0A942B16961925BULL, 
            0xADFFF61B729F7ED7ULL, 0xBA09B30C82A55BD1ULL, 0x4C85539D48137D85ULL, 0x8FFC1FB8E42806D2ULL
        },
        {
            0x69812CC2CEF2255CULL, 0x922DC0F33A1A538AULL, 0xD4BAAA70E487C5ACULL, 0x850F1C1601B8E152ULL, 
            0x2E2CB682C632431FULL, 0x060F2F55D61B0509ULL, 0xAF16EEE60892C0F6ULL, 0x5E314B250BFF8D26ULL, 
            0x8721AF7A8D359D30ULL, 0x10DAA0616DBFC0C0ULL, 0xE6D43720048935B8ULL, 0xD3CEF5092B5D29B5ULL, 
            0xBA1642B99E4EF3F0ULL, 0x4267F5EBEC3B8070ULL, 0xB5DBAD36AD7BBF7DULL, 0xC60787BCA67CD204ULL, 
            0xB3769D5A2EB76F07ULL, 0x7E8EAEA251F7CABEULL, 0x0C271EEE407BAF2EULL, 0xFAAFCB69CA8A3E3AULL, 
            0x560C78140D4217DDULL, 0x9660566B46F18B17ULL, 0x60644095E25AFC9CULL, 0xD63A072BA961C017ULL, 
            0x892ED6311EDDAB50ULL, 0xB7F7BF99D6954972ULL, 0xAA9F15202025E7ABULL, 0x61E6B46268BCD5A0ULL, 
            0xD8B9186A5C7E7ECFULL, 0x7DA3E075795E5573ULL, 0x1C7E7A45DF6A7EABULL, 0x661C5D22E39F803CULL
        },
        {
            0xFB3B1656991205BCULL, 0x119B143A41A862C7ULL, 0xED9CA15D868426A1ULL, 0x67196C5F5652AF2CULL, 
            0xD63A07870526E8C6ULL, 0x23CF9DC51398AEEAULL, 0xAA1E418AEFF28743ULL, 0x1A88AC27058EBD47ULL, 
            0x945258E28CF0D58AULL, 0xD86F75B647DED43DULL, 0x982F78427275C59DULL, 0xEF5CE25D40924416ULL, 
            0xB19E3D7B711E1EE5ULL, 0x9B95592E55EA83BCULL, 0x9997A14F7D533194ULL, 0x1E551549E93605F4ULL, 
            0x13AE975FC2127E7CULL, 0x8AC717D1A5CC642CULL, 0xBB6F6D0DEA9999D3ULL, 0xAF9B293B612A4018ULL, 
            0x3585B971A0CCA8B3ULL, 0x39285DB278FDBC32ULL, 0xC2FE22849903A182ULL, 0xEF974B728A17C845ULL, 
            0xE03271054DC5BC01ULL, 0x0846BDD13DF9290FULL, 0xEAA28B814B9B921CULL, 0x41CCEC98034D94D5ULL, 
            0x8B7F8BB5F093D1B6ULL, 0xA9F3046046D98AC2ULL, 0xD46A7CAA28EA5327ULL, 0xF5EAA4CFAD537487ULL
        },
        {
            0x57018AA5939E5B8AULL, 0xD13834C7C54009EDULL, 0x3A487125C2A8362CULL, 0x9B284CD3ADD34B1EULL, 
            0x39B5D068C3CA547CULL, 0xA1C6D8B17694253AULL, 0x0AE4A25E1C6AD9DDULL, 0xE60F3C671DA14B7CULL, 
            0x890794AA7DAC98B8ULL, 0x9823E8822795CD83ULL, 0x6E73953DBC113564ULL, 0xCAA3116120A563C9ULL, 
            0x0C9C22D6D4B296D6ULL, 0xCB7E47986E9560CEULL, 0x04259BB8DCB294F6ULL, 0xDE25867AA6D60D62ULL, 
            0xB9461A590E602D2EULL, 0x35153201AAA6E4BDULL, 0x2BB95C34F0384653ULL, 0x9DE9D6328087C5C3ULL, 
            0xEEAB721091B3B7ACULL, 0xE098091C088C0608ULL, 0x1C7496E3FE8858DDULL, 0xBC3B84D6DA36BC86ULL, 
            0x5B39148055B35C60ULL, 0x1AD3324839618E40ULL, 0x856B7A90C200310EULL, 0x0EAB263E5D4D2C85ULL, 
            0x2A0DA085A589176DULL, 0xE131E959ECB56BCCULL, 0x316C597B20D97BC3ULL, 0x5EBA670CEEC047C2ULL
        },
        {
            0x6237F04DA30E2375ULL, 0x5B5A0A63C5DCF2A7ULL, 0x72D241B68A245B07ULL, 0x106CF372B562916FULL, 
            0x4DF6C7D9227C0521ULL, 0xC34E81EA929AAE75ULL, 0x989B28AF2C76C71BULL, 0x0AA1990CCE525076ULL, 
            0x1196B881B17F3BC4ULL, 0x19828CBA9D1F137FULL, 0x674A03AAE6E872D4ULL, 0xEA146683BC91D99BULL, 
            0x438CAB852F3F694DULL, 0xA03F1C58CCD8F99DULL, 0x8EB252936B05B6D1ULL, 0xE29193073FE32BE1ULL, 
            0xBA502DEFE6C05DA9ULL, 0xFE614A1F66A9AE93ULL, 0xA244AF4E43AF9D00ULL, 0x837AB0A0B9E39DE6ULL, 
            0x12D8C241565E2F13ULL, 0x850FCE687BF3E3D5ULL, 0x38E042CAAE0C23DCULL, 0x14703C71AB1CD1EEULL, 
            0xD0BEE6378AA75C27ULL, 0xE53A5B7C8380C6C9ULL, 0x0879E0CEF8E654A4ULL, 0x1C5E029DE0B53CC2ULL, 
            0xBF5689F43D02213DULL, 0xD0676B6049FF86C9ULL, 0xA4614186F8DE037AULL, 0xB46C09872129CA55ULL
        }
    },
    {
        {
            0xC2E1A61ABE3409F6ULL, 0x7F030A0FC3B6CFFDULL, 0x95E8A72B24F6C2B4ULL, 0xDE708E1B09FC48A3ULL, 
            0xE7E3F6534C4E02B8ULL, 0xB7B1F31803C3A22DULL, 0xAD39282D2028F676ULL, 0xE7660ABFAF14AF05ULL, 
            0x0CE7C975C168EECEULL, 0x889D6AF437982CBAULL, 0x0E9D2F7A3199CEB1ULL, 0x4BEE35A2225114DDULL, 
            0xC3013EB16F41EB83ULL, 0x6B2B67250DF91DCBULL, 0xE071849739211D5CULL, 0x8C11E33AC22DA4D3ULL, 
            0x54762A9B03E7662CULL, 0x7DC02A6BCDAC42CFULL, 0xB0176B47A336A0DDULL, 0xA3A9C07364C6CCECULL, 
            0x7ACA89930F7884B0ULL, 0x76E75A1E0FCE6B34ULL, 0x242D7CA969EAA800ULL, 0xB5061A59F364EF42ULL, 
            0x0E890AAC99D895C9ULL, 0x968025E34B91FB81ULL, 0xFEDE64288E9B97D0ULL, 0xFBEAF9F9994A12B4ULL, 
            0x21E6903234DB6379ULL, 0x384F69AE65246FCAULL, 0x3B58495B5E1C7F48ULL, 0x2FD2A1060E84AA20ULL
        },
        {
            0x392D5D5C708B2AD1ULL, 0x1787FB171379BBF9ULL, 0x2A999ECEC7E30825ULL, 0x32D642B47274F65DULL, 
            0xDB2A8FCBD734D8CDULL, 0x75A6682C52ED7C26ULL, 0xDB37B67C0C35F2BEULL, 0x1B049ECDFD242AAAULL, 
            0xD0B67180EE6629E8ULL, 0x0E71104FC35066B3ULL, 0xAAA0D91263C89206ULL, 0xC933C1D2C7E151ADULL, 
            0xF1C7C504005EA65FULL, 0xCC608567BBB9E173ULL, 0x210EF7103C550ABFULL, 0x6214DB7C2F0DEAA5ULL, 
            0xAC0EE3316ACAB1D0ULL, 0xD35CD7220D86CEF9ULL, 0x6E79A83186E47047ULL, 0x83F13D18E78DE497ULL, 
            0xDE4C0CF1448E8808ULL, 0x982F47555B07B34BULL, 0x99D780BEBF6626D9ULL, 0x9A519CC85CCC2E80ULL, 
            0x0649F194699F15ABULL, 0x5CEE37160B7302DCULL, 0xEB6F4D22B69C0A9BULL, 0xB1140B278A5530E7ULL, 
            0x4A710CC5C12AA47CULL, 0x66D0D97431D5B274ULL, 0xD3C6BCD00FC5B38BULL, 0xD2CB2B920D8711AAULL
        },
        {
            0xED35A977A5ECD0CAULL, 0xADDF71E65C9E6C4EULL, 0x5B92189EDB73755EULL, 0xEF2ED315295775F5ULL, 
            0xF94A9FDEBC2E0E79ULL, 0x05CFDF093CADD764ULL, 0x200CEAC277E663F5ULL, 0x910BAF8D65D4738AULL, 
            0x001286AAE48B0E61ULL, 0xB09B66FD451F31D1ULL, 0xA78614E5CCC2370DULL, 0x8656D162668EC8AEULL, 
            0x45E8AD9E7F41D6D0ULL, 0x08295CC22BF090E7ULL, 0x60D63C753F1C6D71ULL, 0xCFA16380891222C9ULL, 
            0xDC6FDBD03BF9FE48ULL, 0xF8AAA648B9C94DE7ULL, 0x6D47B574FD789A5CULL, 0x3B2DF41DF28ED85FULL, 
            0xEE4EA2A9348CCD3DULL, 0x948D3760EB7DD10DULL, 0x37E4D2415997EC33ULL, 0xF142FBB12A354D17ULL, 
            0x829CBF3DDCCEC457ULL, 0x0011D3EA56C221CAULL, 0x12CAD3CE0A51B54BULL, 0xC602582458EC88FDULL, 
            0xC9C2240B12ACD898ULL, 0x96C0F73790B42A4EULL, 0x6E1C6A8483FB0B5DULL, 0xC56C66BB1ED61D36ULL
        },
        {
            0xE3780257E8819E1BULL, 0x255CA7E1BA67244AULL, 0x804517F7520C7531ULL, 0x87590E39E39DD2BCULL, 
            0xCAE623AB4F8AE388ULL, 0xB97126AD4B121C9BULL, 0xE744CAAB7C663299ULL, 0x3722886D3F40F006ULL, 
            0x396026AB1707F4E2ULL, 0x337F96A29DAC72BAULL, 0x8375AE94359358D5ULL, 0x12F176F8CF9F324DULL, 
            0x8388384317DA46A3ULL, 0x2082CD34F0B90CA2ULL, 0x70A1BA0A62853F6FULL, 0xC453EE54B3205DABULL, 
            0x1A97612FF7367F0CULL, 0xD64F736CF9AE752FULL, 0x8BD12190F1075A4EULL, 0x65C987EBEE5D0DE1ULL, 
            0x6CD4B7CE6AF52D43ULL, 0x5455D219F5D9B1B3ULL, 0x5CADFA591292789DULL, 0x2A94DB080001A937ULL, 
            0x2FC9A3302307F592ULL, 0x15ED43CB45B1CC58ULL, 0xA07165F0E757DDF1ULL, 0x5DC0668449E09739ULL, 
            0x3E0D50B439D1F12BULL, 0x2D209DA4F833B973ULL, 0x00684933CB234CB7ULL, 0x7863AE7B2B8485F7ULL
        },
        {
            0x73FD6F851C650989ULL, 0xFEC655AD7389731FULL, 0x63D7AED93B1237C0ULL, 0xFAEC7646D7A0F48AULL, 
            0x2172083E80ED08C6ULL, 0x4ED96FD1263AE61BULL, 0x31B2BDDA5DF1663EULL, 0x9411C06BF34A8A0BULL, 
            0xB2CEE2BBCB59053DULL, 0x31946A498E8F9DA5ULL, 0x39384AB071A216EEULL, 0x0D0AAE45E2D7F209ULL, 
            0x347B86DE1C7AAEC7ULL, 0x583CC52D7B5D0D28ULL, 0x56BD72C81F858F79ULL, 0x099E38C440348380ULL, 
            0x87E50090E66FC293ULL, 0xCBDCCA60C4F642C9ULL, 0x23E6701075ACEDD4ULL, 0x3CFFF8EA01C962C0ULL, 
            0x5A93856C7DD5275CULL, 0x0C0AC9A3816A68D1ULL, 0xC3CC685F0518F455ULL, 0x76BF341B3C8C5515ULL, 
            0xF0609C9A9DC2BE3AULL, 0x854C2723252B4FE8ULL, 0x68AC7C15F94501A5ULL, 0xC32ED2BF75F64E83ULL, 
            0x9EEF39660F512890ULL, 0x3007AB96B46589EBULL, 0xC73419261235B982ULL, 0x0EBF9DB33C39ADD2ULL
        },
        {
            0x57A7DFC90053A0DEULL, 0x1941295C3111135AULL, 0x7D4E467532FF226DULL, 0x6DE81C31D2AF0F0CULL, 
            0xBE9F8F7D908B92D0ULL, 0x1AC82588E6490FEEULL, 0x37BDBD15F093B1B7ULL, 0x8E4BF2274938C26BULL, 
            0x80DB7B3D84C00FF8ULL, 0x41855E9771796D53ULL, 0x819425078161801FULL, 0xF96D360C0B32E704ULL, 
            0x4F34254EB439D61EULL, 0x5B338AF8056240C0ULL, 0x763C5D380899926AULL, 0x33F07AFE4850659DULL, 
            0x1F86A5C5A6019665ULL, 0xAE4422BA8A0911F5ULL, 0x5A5CEC449AFE7298ULL, 0xBB4362C6D9BCD5F8ULL, 
            0xAF54F60E85AEA568ULL, 0x76038C35E128F276ULL, 0xB3878358B7C45511ULL, 0x8C9B8E92F977A7BDULL, 
            0xDA97E4437B6ADD9DULL, 0xBAA5556721C938E2ULL, 0x1BB135FDAE9C0C4CULL, 0x17EF5C6F4CF93C39ULL, 
            0xE46E405A883C9B86ULL, 0xF24D064D9EAF97E4ULL, 0xB700ABE65CF1AB88ULL, 0xB7D7021E1B33E86CULL
        }
    },
    {
        {
            0x0C0B760867D95D4DULL, 0xB7031CEE0398E837ULL, 0x56B068175278F760ULL, 0x2EBF5862C79312E9ULL, 
            0xA86D49508F9ABEC3ULL, 0xFA4C71EC6C15518BULL, 0x483A361126C80B48ULL, 0x14E26D513965344FULL, 
            0x18ADDEC42F2CAC29ULL, 0xF666BA96D25B57F2ULL, 0x35EA1598C556B3D2ULL, 0xE0C3065FB6B1F949ULL, 
            0xA302C2863B9D40F8ULL, 0x36F94347A3A58C9AULL, 0xECE79EB9AA0B19F9ULL, 0xE4AC24040EF5BC92ULL, 
            0xEFCFE2D926C13B39ULL, 0x1D2A45BA05BF7179ULL, 0x8727A34697A26321ULL, 0x2FDAE2756EB1443DULL, 
            0x885E16AC6BCF235EULL, 0x3ED0C39DC5FCEE45ULL, 0xDCFC5B9DEDD5703EULL, 0x28B3E9C1BDFB8562ULL, 
            0x5378976BCCDF8916ULL, 0x4E25C738FF050CCCULL, 0xC82DC274A81CBC83ULL, 0x49D9404912891BE0ULL, 
            0x4509CBFE7BF53CA8ULL, 0xEF0083AD675BE56FULL, 0xF692C7A7D47F3579ULL, 0x89CEFF4F465AF229ULL
        },
        {
            0x5AF81C2DDD337F3EULL, 0xF80C551B35BFF9DFULL, 0xDAEF2B722A8445F0ULL, 0xF41C0140EAFAB914ULL, 
            0xBF64C73572782229ULL, 0xFCC621464AF9D019ULL, 0x552E51EBBA42FE82ULL, 0x461D11C9936E13C7ULL, 
            0xF83BC9A92742311EULL, 0xAAA185824B1C856BULL, 0x6C43BCCA72F75006ULL, 0xD9E364DFA2AC4E9FULL, 
            0x40B79F57BCBA7183ULL, 0x802C9BB5CC271599ULL, 0xCC885312FC474E1DULL, 0x91125912796ECC60ULL, 
            0x6E5370AEB9105439ULL, 0x1E1B872A7AE59743ULL, 0x322D9A1D4CD4F230ULL, 0x83694BFF645DD52CULL, 
            0x05AB9B1A44DAF40DULL, 0x0318EDDC0FBCFD51ULL, 0x7949A88977A171F7ULL, 0x1E951B465B570998ULL, 
            0xB9FC8BE072B8FB33ULL, 0xD1DF4118CF362464ULL, 0x338D14BC0B03CCD9ULL, 0xE6314A23521B8871ULL, 
            0xBB09E4E9FF727E50ULL, 0x432BAD855BC00045ULL, 0x8614B620E33ECE17ULL, 0xB2D8AA80BC3ABEBCULL
        },
        {
            0xD54EF186E6D7975BULL, 0x446BDDC5309FB5FBULL, 0x0C5AB87814C5BCC1ULL, 0xDFFB1206FC8FEF96ULL, 
            0x301028ED03A778E2ULL, 0xE262C78956ED9460ULL, 0xC80EEDCD9A980D20ULL, 0xECA5CC3DD013D1F5ULL, 
            0x162848AAFA0C4475ULL, 0x8B02EEA2DA1A1F72ULL, 0x24FC35F4011D6C1CULL, 0x7580946652633D76ULL, 
            0x6B238927602F233DULL, 0xBDAD9BBC844F873AULL, 0xEC4C83DC4626E8CEULL, 0xFCE51426A799CD3EULL, 
            0x7CE7DF79ACB2D366ULL, 0xDAE5BA3591E32918ULL, 0x642A3860A8E0CE22ULL, 0x3BC6FFD29DE5DCBFULL, 
            0x516C42351720A984ULL, 0xB1A8958ADD8BFEA2ULL, 0x7BE367A6CECDA653ULL, 0xEE804321E79AAAF9ULL, 
            0xD339F95D7946EA32ULL, 0x6FDBBDB90C946EACULL, 0x6CD861A2E14E4D6BULL, 0xF16A0776194C1C0FULL, 
            0x7F3CDA1669202542ULL, 0x32EB676CBCBB2BD2ULL, 0x44A902D61FD8594CULL, 0xB6EBEB608E901E5CULL
        },
        {
            0xF9A9F3069A194976ULL, 0x0B52D98B6535F468ULL, 0x393ED8BDABF88CD7ULL, 0xD1D4175E35610C5AULL, 
            0xD182EE357CDA7E7EULL, 0xE82984EBFADE7EC7ULL, 0xD580D2FBB036FB1BULL, 0xF4AEA6C4A11190F3ULL, 
            0xB96C7D63B6B4866FULL, 0xA6880496CD719D26ULL, 0x77D0D5A57F585715ULL, 0x59F49F841F69CF48ULL, 
            0x9D1927B977E3A64CULL, 0x5421D4EC1AEEF0A0ULL, 0xF5AE57C60184BBABULL, 0x2AFCCC0505D11D02ULL, 
            0xB36D08CA1EBAB9E5ULL, 0x7786D049061AA4B5ULL, 0xE1247C677038223CULL, 0x2D738C8E19D6F121ULL, 
            0x7D22D7013A7D041DULL, 0x66402E481BC8011FULL, 0xD2F0AC5E9C23A511ULL, 0x17DAF45464248A93ULL, 
            0x8694B659BC73949AULL, 0xC52D2666085DB31BULL, 0x90D3918874F59A85ULL, 0x35BB26AB32488B1FULL, 
            0x2D1C3AB4B9AFE014ULL, 0x62516392C90E2A90ULL, 0x875C996754B1C1D4ULL, 0xFEBE7D686A2C3872ULL
        },
        {
            0x1901CBFC5D539066ULL, 0xA4B0C936F26E89D4ULL, 0x0057537A2AD6915EULL, 0xC85C9011FE70617EULL, 
            0x4779A860E602F41BULL, 0x1F6DC9B05EE5F8D2ULL, 0xDF5E1A34A89D029FULL, 0x6EE776860245D41BULL, 
            0xB63EF834567CBC66ULL, 0xB3D51360828C4AF5ULL, 0x4169C0610AC8EB62ULL, 0x4CC55E691852F306ULL, 
            0xA011EA30033F5BE5ULL, 0x9948AF68B17CFEB1ULL, 0xBA7963CC71F9F152ULL, 0xCC26C3C4211CFB3FULL, 
            0xFBF2B35863060F3CULL, 0xDDB9CECE059256C9ULL, 0xB2BD6CB27D916E6EULL, 0xBDF2E1885A5CAE6EULL, 
            0xD66851ECF95319A8ULL, 0x5B28CB2B6142C0AAULL, 0xC65E76181B83E074ULL, 0x48334EAFCA6B4F28ULL, 
            0xC443D049A827B2DEULL, 0xACC121D16D39DB98ULL, 0x4EB4F131E124877BULL, 0xA797892A35891AE5ULL, 
            0xB0A12768DAC54292ULL, 0x22934A9EF6CF2584ULL, 0x21F9DA19FB114117ULL, 0xC8F785DDD167D9C9ULL
        },
        {
            0xF388ADADC3006C84ULL, 0xC7D6D49A77A8EB15ULL, 0xA5A8A37680D2E46AULL, 0x710819EA05E96125ULL, 
            0xEDEB6943BE569555ULL, 0xBBB8B6EE76933EBFULL, 0x631254E29542234AULL, 0x53115B520E987833ULL, 
            0xD57006A049E6CAE2ULL, 0xB5B679EAA953A6CCULL, 0x7ECFC4292838C607ULL, 0xADE5D8781EC93B44ULL, 
            0x5596C14EC15CA040ULL, 0x178950008EE58A07ULL, 0x5C2951305CCBB59CULL, 0x2227C5043C9780E4ULL, 
            0xCB01D171DCBE6DC0ULL, 0x702A2C67BDA93707ULL, 0x6A326FD3EB894BE9ULL, 0xAD2ADB137CB6564DULL, 
            0x830755BFDB181F17ULL, 0x39A1E4B13D1F35F7ULL, 0x64C4CF75C8EF4F8DULL, 0x54C1AD41A5C822EBULL, 
            0x422ED19D787169F7ULL, 0x2967B286999E85C2ULL, 0x79E8F2D8333125F0ULL, 0x506C258485983D33ULL, 
            0x0D80DEA70241678DULL, 0xCDDD287237C560A6ULL, 0xB53CB18C9C3AC636ULL, 0x87BE812A2F13645AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseGConstants = {
    0x42FE6FA3A60A5D00ULL,
    0xC7628BB683E164B0ULL,
    0xE81BAF84229982D5ULL,
    0x42FE6FA3A60A5D00ULL,
    0xC7628BB683E164B0ULL,
    0xE81BAF84229982D5ULL,
    0x0FC6C1E31945C2CAULL,
    0xA6780666B727CC68ULL,
    0x7C,
    0x93,
    0x91,
    0x31,
    0x06,
    0xBA,
    0x53,
    0x5C
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseHSalts = {
    {
        {
            0xEE418556FE5284FDULL, 0xA13A2FB2CC8050A4ULL, 0xB931A925DCAA401EULL, 0x092F75165C574934ULL, 
            0xA91274C139A8FF67ULL, 0xBC7DA37F4BC5F0C8ULL, 0xB8DCFF49281127AEULL, 0xB418A33B10AF9AA4ULL, 
            0xB31833460CEA869EULL, 0x201723CD4B3870F5ULL, 0xF0926040900845A1ULL, 0x73B04AF3CD63E25DULL, 
            0xF0430C86AAD60F42ULL, 0x0C9E24386D7D3552ULL, 0xA49D6CC757F8CBFFULL, 0x51D5B210F7869227ULL, 
            0xD40095E68C8B1BAAULL, 0x9785F70DC376F1DEULL, 0x740065AF10916C45ULL, 0x517BBA8ED2E851E8ULL, 
            0x7D88DD404F0A4B43ULL, 0x87219BB2F33C8C44ULL, 0x9BC4E87DEF4D4CDEULL, 0x16689E404C9C839BULL, 
            0xB9DBF1498A7BFCE4ULL, 0x9ACC0F5A6079260CULL, 0x3064CF2D64A3AEB4ULL, 0xC9FFAC70501B5D9BULL, 
            0x17EBDBA7CCEFEB66ULL, 0x779A47385D310727ULL, 0x80131731CD2A54CDULL, 0xBE5046F1BB97F0DDULL
        },
        {
            0x92DD86B5997769C3ULL, 0xDE4754A52B2270C5ULL, 0x3BE5B2DA2E2FF6E9ULL, 0xEF25CD1FD0417D20ULL, 
            0x9D19A09EE9A03542ULL, 0xCB127B7930635A0BULL, 0x62CC0C7A24701E2BULL, 0xF01962BE42867B59ULL, 
            0xA09C8B041DE5A20FULL, 0xC7650D3A207BFB2EULL, 0xAD4ECD84AFF647B1ULL, 0x599EBFDC1F631E48ULL, 
            0xF4C64100233AFB4BULL, 0x6E647352BA57F405ULL, 0xAC30C3455133A57BULL, 0xC6981839554960ABULL, 
            0x9DEE26E3648FF74CULL, 0xA4AD5056C956D4D5ULL, 0x9070A1C015382F26ULL, 0x7957B39A6EA3C3A3ULL, 
            0x3C26DCCB92C4788BULL, 0xF3A6A3DD2E354BDFULL, 0x9062BE99266C6A1EULL, 0x7069CA4FD00C9339ULL, 
            0x819F82287206CEDAULL, 0xDBA673B785F46DCBULL, 0xD307F2E781C3E0E2ULL, 0x6A8358E4708AC729ULL, 
            0xF849AA52EF45A2CDULL, 0x782D380AD072AF5EULL, 0xE881716B67702ACFULL, 0x31BC21D5CBDF6B8EULL
        },
        {
            0x99C5D7E767035C0CULL, 0x46F1AFACF1C69291ULL, 0xECA4FAED91CDBC20ULL, 0xCBAF2FBFBE77426BULL, 
            0xCCF926371C7E0734ULL, 0x36465785FF5BB809ULL, 0x19E7CF1CAD01083CULL, 0x24766A21A2E87D20ULL, 
            0x136487005DF3A7A8ULL, 0x3E7211F798F79E5DULL, 0x22DFEFED0DDB7259ULL, 0x372944AB6061B146ULL, 
            0x9F5438F0408A4DAAULL, 0xB2FF0E97907664CDULL, 0xBB1EADF139A625BAULL, 0x5080D1FE768132D7ULL, 
            0x8121F996FE76D262ULL, 0x9064344DB579E70EULL, 0xF010E05EFB7F92D4ULL, 0x3ECFB55F8DC50E93ULL, 
            0xDAA4174105A26E1FULL, 0xAADBD84B3360A2D8ULL, 0x997C7B523B149573ULL, 0x1811D58F8E384816ULL, 
            0xBEF075E86C4D6946ULL, 0x40CC7A5CDF432BFCULL, 0xE3A3D17BCD34B187ULL, 0x39D06E6C92EA0E4AULL, 
            0x8023852E8DC9C2F0ULL, 0x46BB4C1ADFFBF52BULL, 0x331F75842F141D13ULL, 0x42A35A4CC7896736ULL
        },
        {
            0x0452F8D19D4635EEULL, 0xF02D4654C6B2989BULL, 0x7047902567B69D79ULL, 0x6D4E2257EEA3D8B3ULL, 
            0xD35846FC38AFFB15ULL, 0x9F4699B084B4C96BULL, 0x573EE9D8FD050DBEULL, 0xD3C8EFE3A968C14DULL, 
            0x3BDCE8B410F05108ULL, 0xBC889EB61DFB0369ULL, 0x255B4E341C3A5EF4ULL, 0x70B02891CB3DC115ULL, 
            0xA2CCFA450DD5C38FULL, 0x91AC25D97ACE4D45ULL, 0xCB184B1AC7ECBFBAULL, 0x08649074028EF905ULL, 
            0xDBE3F44166117855ULL, 0x7B74525DB3183752ULL, 0xE71CB26F7F0AC337ULL, 0x31E7CCE93F6CC2F3ULL, 
            0xF53D8700C74461D6ULL, 0xB04A5AA24B42EE4EULL, 0x42799FC9209B8CE4ULL, 0x7424442025AF3548ULL, 
            0x9979552048D673D0ULL, 0x3ACD6A605BA989A0ULL, 0x81C7CDD44FD13CAFULL, 0xBE24A0C8F6A27C3FULL, 
            0x6E31D1A4FA90C5D0ULL, 0xA912805FEB54FED2ULL, 0x9B62341F2F74E7B5ULL, 0x8A209919A7649E0BULL
        },
        {
            0xE055D4292F6D3FC6ULL, 0x7CC8092D0A44915DULL, 0x16EEC7A20158DAB6ULL, 0xE4E0D63B38AAC9C1ULL, 
            0x95EABA8EAF43031DULL, 0xA3FA0DC5D05A0173ULL, 0x3ECD954A261C0E4BULL, 0x3B4F58D391959944ULL, 
            0x5EDF43FEBCC1E7ADULL, 0x7A114E9532A247C2ULL, 0x53DB4452616F58E6ULL, 0x0CECA39E11DEF96BULL, 
            0x603E14C79486C1E2ULL, 0x05821CF48E35146EULL, 0x60C107A17712113EULL, 0x06A9D507103C7845ULL, 
            0x26F29C358727E3A6ULL, 0xB48FA9E3E055FF4DULL, 0x6BC091B466719C10ULL, 0xB88C73E621132CEFULL, 
            0x6EDA4E8F70D03B67ULL, 0xE124D6B233E81E69ULL, 0xE54450D030E0474BULL, 0x37604F21F3EF08C4ULL, 
            0x564C820AE4254EF5ULL, 0x489E4F4C8BDBEF6AULL, 0x9E0CFD64BCD94D11ULL, 0xE819EE66580B089AULL, 
            0x92BD99329EF06A6EULL, 0x775B8877AFA55D29ULL, 0xEF7D38888B440D66ULL, 0x5C3C50F8F2704BFAULL
        },
        {
            0x197ECE6809073B1EULL, 0xF99A3D4FEEF82F06ULL, 0x121C242823C04112ULL, 0xEA65B6C0C2116A2FULL, 
            0xCCA2285F3E19638FULL, 0x1AF00863C4BA5693ULL, 0x6CDE8F22F66F542CULL, 0xB261A15F61C6A420ULL, 
            0x7B5E7F4CA8EF8CA5ULL, 0xDA90FBB7EC8130B2ULL, 0x86F7D145E3A23B49ULL, 0xA86DC233173B23FCULL, 
            0x824A4B762F4C4E3EULL, 0xA39E545B8482EFB4ULL, 0x835C1C2A7EE8A992ULL, 0xFA2B6C58E05DE6E3ULL, 
            0xB1307B4D52BD1054ULL, 0x19B7151524A478D7ULL, 0x808B4D976368E48BULL, 0x59307455E87D57ABULL, 
            0x8CAA9DD45656212DULL, 0x533CA70A9357A82FULL, 0xF994CE75A11E67C6ULL, 0x185263AD0A196FC2ULL, 
            0x31E4857D6ACEB9F2ULL, 0x52A7239ADF9E7728ULL, 0xA87DDA1097F16FDFULL, 0x7AF0EE6335C2FCDBULL, 
            0x2BC597A734EF0600ULL, 0x4551EF1BF2EED9DFULL, 0x7F7208621A25CD33ULL, 0x30BD50D8F66A145EULL
        }
    },
    {
        {
            0xF715E27E61AAF533ULL, 0xAA19A5666065505BULL, 0xCACEB8E51D9D6688ULL, 0xECA38EEA1838224EULL, 
            0x725D077C44ACFA86ULL, 0x758FF65AA3BDF3D3ULL, 0x33888AB40B3EE4B4ULL, 0x31DA999D150A42B5ULL, 
            0xDE81F6C5620D886CULL, 0x1B0C168031B991FFULL, 0xF7379A64C8732FFFULL, 0x9A84F0D177EB854DULL, 
            0xACC794A5FA32DE50ULL, 0xF457D47827C48FAFULL, 0xA6D9D333527E2017ULL, 0x3DD415E3FC7B64C1ULL, 
            0xDAC1C7F72EB25029ULL, 0xD0B71E70F50F6D97ULL, 0xEC13926E637AB374ULL, 0xBF51775EDCCA8167ULL, 
            0x346B54ECD844D3B8ULL, 0x9A625BDCD73268D4ULL, 0x2640F9672DC61170ULL, 0xEC8972F7CFC4CCD6ULL, 
            0x6D98BB1C556C1119ULL, 0xD513DA154E4AABE3ULL, 0x0A21C8A964573F1BULL, 0x4035390FE2C176A9ULL, 
            0xE8A0E1BB4966AA9CULL, 0xFFC52624E0AC933AULL, 0xF88230388B14D361ULL, 0x6A83D819931C86A8ULL
        },
        {
            0x17709ED148CCF8D2ULL, 0x00D70A2C21A05185ULL, 0x939EF4C3194D6A36ULL, 0x61885A3A454CCEA7ULL, 
            0xAB5E1E4A0AFFB433ULL, 0xBE2C3FF8C20565CCULL, 0xF7B140D6F0E9FFAEULL, 0xB93855771F2FDF4DULL, 
            0x7B305136BA164A11ULL, 0x6168323BB194A0B8ULL, 0x1F6DD920D25199FCULL, 0x6A6D54B318DEE750ULL, 
            0x8684EB94E9DE578EULL, 0xEC65C1247C2EB49FULL, 0xDA68C053247EB72EULL, 0xD7526472FAC252FBULL, 
            0x44D1B601844074E1ULL, 0x2E518A8D959F9734ULL, 0x6DA6DC44CAC3D29CULL, 0xA5B3DDA3B6521CBCULL, 
            0x9A00ADC7C319084BULL, 0x4AA4AE8F5C6CFDEEULL, 0x8AC5487A344FC16CULL, 0xEF37A4DFCD87255AULL, 
            0x27FC6E55F886AAA9ULL, 0x5AD81EC8CDF69FC0ULL, 0x1D02709B46396177ULL, 0xE70958244569C801ULL, 
            0x348740E62C46D96AULL, 0xA51AA98897F90F7FULL, 0x9BFF9AB8FDDCBE23ULL, 0x360D45EFD098DA07ULL
        },
        {
            0x6C4813AFE1229F78ULL, 0xECF4230C731F22FFULL, 0x22E59EDA2F86586CULL, 0xDD3B2C77DA43FF8EULL, 
            0xD6100FA9F212BAC6ULL, 0x14BD14033AB1560AULL, 0x364F254DF2CDEE42ULL, 0xFBE37AC0EA58A611ULL, 
            0x227944E01B5C5595ULL, 0x5732D1AA385FA3E2ULL, 0x3BC3300253B11292ULL, 0x85778E3ACEBB439BULL, 
            0x78C7D6E9102C27B3ULL, 0xE3AA68A77AE146CAULL, 0xC65AB847E415D751ULL, 0x198AA1F92DB188ADULL, 
            0x930B71047A8CFF37ULL, 0x0DB539D3927122BFULL, 0xAC4644FB5B2BB665ULL, 0x82D68D6BAB5E4794ULL, 
            0xAE72B7754B7AC757ULL, 0x8529777005C5DE91ULL, 0x6AF1876E9C0B9FAAULL, 0x24212174EC527CBBULL, 
            0xE64736F9D4FBD74EULL, 0x68E7C17612ACC0B6ULL, 0xB10F298978B71172ULL, 0x211A7BA6BC159790ULL, 
            0x949A5662AD5FF8AEULL, 0x4A9F73AE508CCE0EULL, 0x656162D8CB8EE006ULL, 0xEFF4DC5A2523D643ULL
        },
        {
            0x4A077FE4DFA2AC7AULL, 0xB3F8FC70323F56DAULL, 0x7ECD02F7870CD551ULL, 0x96CAF965B3733D05ULL, 
            0x8B061A2353599C34ULL, 0x97BCF98D7E9E7782ULL, 0xEA534052F0036B6AULL, 0xA70799010121500CULL, 
            0x7582E758E391A9B0ULL, 0x63430A72E8BD46C0ULL, 0x706BE036981BCDE7ULL, 0x7038449F71F5BC88ULL, 
            0x2F7C67972D5585B5ULL, 0x8C8A0A1DCF41953AULL, 0x817C804E884C334AULL, 0x76FB006A71D31D82ULL, 
            0x45377ADE3F51E669ULL, 0x15EB388FBC55D9B5ULL, 0x2CE2874665E1AC86ULL, 0x51427D670196BDBCULL, 
            0x76F07AE3DFBAD1A8ULL, 0xBD52C3F30032D9EBULL, 0x04D8FAD33AA6857CULL, 0x6665407144444FEBULL, 
            0x90FFBB42C800F779ULL, 0xEA7D5D13D72C7AD3ULL, 0xD630D57F3D49F2A0ULL, 0x06FE7FFED028D9C9ULL, 
            0x81A721789C71B871ULL, 0xFDE76E0AFE402B57ULL, 0x83F21F7F36FD1965ULL, 0xCF7FC4F8B92CACF7ULL
        },
        {
            0xDC8E768CE722A362ULL, 0xD033CA9A5B22909BULL, 0xE208C553FA9F6FFDULL, 0xB2DE52C5B39A4BE4ULL, 
            0xDEF80BE8208EA4B7ULL, 0x2A2FFCE2A78D46C6ULL, 0x484302E4F3DD820BULL, 0x8128357E10877EF9ULL, 
            0x66ACD1F19A16C4ECULL, 0xCE633D6CE142433CULL, 0xB73F259C47F25196ULL, 0x3E229EBEA45D3A0DULL, 
            0xA4C3ED93799270EDULL, 0x98C9DA35222015AAULL, 0xA0A9B289DF71DAFBULL, 0x9870EF668B3D5B82ULL, 
            0xB1E7B7B5BCC3E5BBULL, 0x908758726C9CC292ULL, 0x70AACB8302655543ULL, 0xE5AAD65C8902ED93ULL, 
            0x3537598510C50F13ULL, 0x2E8881C74FAFA468ULL, 0x3725A08AE6EA29EBULL, 0xB3E2AED106AB85D4ULL, 
            0x3A0A17D8524DDE90ULL, 0x9C77C38DD5E567A1ULL, 0x841E977AE1EFB440ULL, 0x2C063DC59BE8271EULL, 
            0x91BBD3B5B3D743E7ULL, 0xE86275262C4BEDC3ULL, 0x35878126EC79F0D4ULL, 0xBF804745AE2498A2ULL
        },
        {
            0x2F2B316ADFDE76ABULL, 0x8D987647BB410A65ULL, 0x92676DD087379C00ULL, 0x3E4CBE43CA35F3A4ULL, 
            0x157EEBDF9D9313C0ULL, 0xE9C95028A079D83EULL, 0xC926AAE5A819F9FDULL, 0x7DB90550712077ABULL, 
            0x2343B7B42B7A61A3ULL, 0x7C683FC11683844BULL, 0x8C08C1670D0D1699ULL, 0xDD0C896F8FD7BF2EULL, 
            0x389EB8F08C20F12CULL, 0x974A3C9717F46589ULL, 0xC4D7B5B900308FEBULL, 0xE076329DA05611DDULL, 
            0x8FB24F05D2A02031ULL, 0xDF5B53B505D3A787ULL, 0x5078FED88EE5C67BULL, 0x753B8823E7609502ULL, 
            0xCBD3C60EED01E396ULL, 0xD722687F368EAF03ULL, 0xE03407E4E009D7C4ULL, 0x501AD8531A40069CULL, 
            0xF85A9C0FB4C15AD9ULL, 0x0F86A0BC40AD26DBULL, 0xCF6BFBAAD6167E35ULL, 0xD715A466DB60AFCFULL, 
            0x56A42AD245C4C425ULL, 0xA5D4EF7C3330F500ULL, 0xF6E454F50F25DB6DULL, 0x825D5854712686B7ULL
        }
    },
    {
        {
            0x8AAC95ED68E5581CULL, 0xD9F7B9B7C3129B1CULL, 0xD4CD2E0F2A4C816BULL, 0xD2F2E2C82801F906ULL, 
            0x501E3F7FFF881BDAULL, 0xCAA2E2F3CD9082BAULL, 0xD82C7BF2635ED17AULL, 0x47949664A48C8CFEULL, 
            0x188D1FE5A16E9970ULL, 0x66C66D4312FD1D45ULL, 0x95C5AF5D5A416F21ULL, 0x07F9B23A03361F94ULL, 
            0x763B80D6813005EAULL, 0x6591B6CB6129BA2BULL, 0x402202F77DC0A746ULL, 0x2A6186C337449E7FULL, 
            0xF842985CE2187CDBULL, 0x738F4D99FAA39F2CULL, 0xD42B43A392E20048ULL, 0xA05DCF76C61ED2E3ULL, 
            0x967F81D6D3894B52ULL, 0x919F8C6EB67FDAC5ULL, 0xF0D0A1176A302B64ULL, 0x57C894E5D409F3A7ULL, 
            0x7E5235C7C3027747ULL, 0xBCDEEC2CA328A3C1ULL, 0x4622B3699BE8EC2BULL, 0x771FB1A86BAFEB48ULL, 
            0xB27119BD1131E603ULL, 0x814FEBA4213A3124ULL, 0x3AEBB08410325601ULL, 0x7B94FB71EC3A3F3BULL
        },
        {
            0x3430A27419E08C82ULL, 0xE0730081547C0C27ULL, 0xA2F5D04ADF356964ULL, 0x57B7F4AA30B37038ULL, 
            0x0DFED83FBE8E3901ULL, 0xC53F059677FB10AFULL, 0x10BEDACA5ACFC1C6ULL, 0x2A5B49808C7EF668ULL, 
            0xF822F0B5E0D453FBULL, 0x591C3D2AC122B768ULL, 0x6B3DF9BA39339C8CULL, 0xF06EC3C03E5BD047ULL, 
            0xFC18501DF1B4DA3BULL, 0xE8C1AB3803AD5D26ULL, 0x1D3618BFB08486B1ULL, 0x6C9872A7B18FADF1ULL, 
            0x4908703361184AC2ULL, 0x5E04470943F49833ULL, 0x01888D3FCFC9B540ULL, 0x307841CA2EA93FE0ULL, 
            0xF820C64645769340ULL, 0x3C34E77078472246ULL, 0x4F3D1CA9CA86B371ULL, 0xE3EA36FCC4AA3215ULL, 
            0x3F30E5FE5698F32FULL, 0xB365E4213202DCDFULL, 0x43616BA9687214B7ULL, 0x83F90B41663AA9CEULL, 
            0x71A6F6AB3FBDBCBDULL, 0x306688C4F85F85A5ULL, 0xC34EAA24ABDCDD99ULL, 0x58DDA098C774A05AULL
        },
        {
            0x68BCB58F1A118ED0ULL, 0xCA89EA49533A3670ULL, 0x1107A46B9C8A3BBCULL, 0x31537C28A83672AEULL, 
            0xB9AF480337E4321CULL, 0x9C4B87C3D54E1524ULL, 0xE3C4598C4FB09CAFULL, 0x2CD6D3F79B0A3782ULL, 
            0x7C7637CD2F883338ULL, 0x0704E5193FD87818ULL, 0x145CF3A4505D0BB6ULL, 0xB85E50B1AB4E3D9FULL, 
            0x6FC9556CEAD765F8ULL, 0xB8FEA8962136444EULL, 0xA9A7FA123EB3FDD4ULL, 0xDBE323E2619FC23CULL, 
            0x3B8E022F4E945F05ULL, 0xD086E394AE6D3B22ULL, 0x618A76F04AA62243ULL, 0xCF17D4CADA0F6EE5ULL, 
            0x8F3221AA10B18E25ULL, 0xF54D6A2F9A8944D2ULL, 0x8298C6A458EDBF8EULL, 0xEDD16909A3741A35ULL, 
            0x800D90AE1ADE942EULL, 0xF3863A884FDFB7F4ULL, 0xDBCDAB8498BEBF3BULL, 0x03F58ED399157F8DULL, 
            0x794B8C2571007280ULL, 0xFC46500EB02E0CB3ULL, 0x767465A97589D6B1ULL, 0x7D33F32ED91DFED2ULL
        },
        {
            0xFD2222D328BD87A3ULL, 0x3954B5E718820EB9ULL, 0x2F1C3129E57709B8ULL, 0x47E10C6A37ACCA35ULL, 
            0xDC2AE82485D34558ULL, 0x6DBCD6DE5F46D3B4ULL, 0x5F092D82386C9F36ULL, 0xE6F287DF786AE2D7ULL, 
            0xB0EF5F210FAD43B5ULL, 0xC563CDEED6A7BD2CULL, 0x1B7C7791ED1ACE70ULL, 0x2FFE6E7994FE5F3AULL, 
            0xBCDCC4FA07073142ULL, 0x7C4C4077DA58D79FULL, 0x4954F1759724C46FULL, 0xC4F13B1BF2DF36F8ULL, 
            0x2F50FEAD380C8E21ULL, 0x19CFD4659230A877ULL, 0xD6165AA16E233B8BULL, 0x2B42314D6AF72815ULL, 
            0xD619249BF86E4BAFULL, 0xB61C9BFA5C46D9D8ULL, 0x3F1A0623E5692FBBULL, 0x011C8F3CC5C671BFULL, 
            0x9C2A9BC3487BA24DULL, 0xBDB0D694E58A94E2ULL, 0x761634D58ED8D3DDULL, 0x12657493F35D55D8ULL, 
            0x113BE260E9FA9CB6ULL, 0xBBA7D7159AF703ADULL, 0x2DC682C6F395C232ULL, 0x698CF58F31DAE03DULL
        },
        {
            0x6301909DAC8E0F62ULL, 0x09AD4FE6809B48CAULL, 0x84142392F0F11B1DULL, 0x7A5FD042399D5D38ULL, 
            0x29E14886C3C2C8C2ULL, 0xBE9739E5042204A8ULL, 0x4B708DBE810FEDE9ULL, 0xDD2CA0F02B8EC0E4ULL, 
            0xEA536018B1691CC5ULL, 0xC5BAE6114F3A5648ULL, 0x772FBF6C7B4762D8ULL, 0x57DC48A814B88C2FULL, 
            0x731D921D0D69A0B8ULL, 0x6F479C9C75A97A6BULL, 0xD59AED839AEAED6DULL, 0xF5F55B0CCE13F226ULL, 
            0xDD6E07E78B88E62EULL, 0xF84618E0D4595BD2ULL, 0x18CAD0CE2A62B31BULL, 0x4941510969A4ADA6ULL, 
            0x0A92B4198B1B6624ULL, 0x986EEDC00AFC1953ULL, 0x8D61B13209492D32ULL, 0x471E6FCC63432FFAULL, 
            0x16CED428BC2DED20ULL, 0x3A65B1F8E2232D54ULL, 0xADEB8289BDFDD906ULL, 0x2BF4A858B85F107EULL, 
            0xD50F0F582426384EULL, 0x8E9A2E03C742F20BULL, 0x36C8E7F1EC63EDA3ULL, 0x8C3082260E1D73E8ULL
        },
        {
            0x49C3E5F5BC7B5F1BULL, 0x1B42C9F3576A12E3ULL, 0xF93726756A9E16ABULL, 0xB6E8479275B8154BULL, 
            0x865A1942DEE5CB72ULL, 0xB6986B6A71C47306ULL, 0x764C37D87F1E9750ULL, 0x1E0FC17B6CB79231ULL, 
            0xF5AB114F535389A9ULL, 0x0731DEB4885B9808ULL, 0x8F65180D66B4575FULL, 0xBF467DBBD28CFBD4ULL, 
            0x4461906867443718ULL, 0x68C9B835CDB6FB0EULL, 0x4D76E7B29F33FDD3ULL, 0xF868565F92F3B07CULL, 
            0x22993C3D991A3617ULL, 0x53293D106CBB4BD6ULL, 0x67BF700529D92B1AULL, 0xB8E31A8D10303F73ULL, 
            0x7D585CA49F9C36E9ULL, 0x72C7BD75F887A1F1ULL, 0x2761B1DD48AEDD7BULL, 0x9A9DA75C5398DCE1ULL, 
            0xCB141643AF97A8B4ULL, 0x2112481DB961F0E6ULL, 0xE39DD318AEE068D7ULL, 0x35D20136772C345BULL, 
            0x4BA00FD808F082C4ULL, 0xD064A466F700ADEAULL, 0x69325A03F9B1BF05ULL, 0xD5581C5E0D761AF5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseHConstants = {
    0xC7EC2579385F1160ULL,
    0x3480CB2BED5A0DF2ULL,
    0xE14134828B0FDC9CULL,
    0xC7EC2579385F1160ULL,
    0x3480CB2BED5A0DF2ULL,
    0xE14134828B0FDC9CULL,
    0xA012D28E7A36F6F3ULL,
    0xCF0322D20C903A62ULL,
    0xBD,
    0x64,
    0x73,
    0xE8,
    0x9E,
    0x47,
    0x8C,
    0x90
};

