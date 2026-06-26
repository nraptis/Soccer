#include "TwistExpander_Karate.hpp"
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

TwistExpander_Karate::TwistExpander_Karate()
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

void TwistExpander_Karate::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15862742683204657963U;
        aCarry = 13980444383571391323U;
        aWandererA = 13407791913086776004U;
        aWandererB = 10288134426939822685U;
        aWandererC = 12118478613356068139U;
        aWandererD = 18412573986187252260U;
        aWandererE = 11743004426622183846U;
        aWandererF = 9260476313991981710U;
        aWandererG = 15395783771162015503U;
        aWandererH = 11148679049971759308U;
        aWandererI = 15277877574773185551U;
        aWandererJ = 10386466588328404868U;
        aWandererK = 11247191010943349667U;
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
    TwistExpander_Karate_Arx aArx;
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
    TwistExpander_Karate_Arx aKDF_A_BArx;
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
    TwistExpander_Karate_Arx aKDF_A_CArx;
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
    TwistExpander_Karate_Arx aKDF_A_DArx;
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

void TwistExpander_Karate::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 17118176464870367014U;
        aCarry = 17514511022155848514U;
        aWandererA = 14068932719220432254U;
        aWandererB = 14749661522595031245U;
        aWandererC = 13362447042003795296U;
        aWandererD = 16932929581513676207U;
        aWandererE = 17868734636478495381U;
        aWandererF = 15103648521437732070U;
        aWandererG = 9641666496880677929U;
        aWandererH = 14725381111568485522U;
        aWandererI = 17124098935275584801U;
        aWandererJ = 18314205346240316483U;
        aWandererK = 10953539947773499516U;
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
    TwistExpander_Karate_Arx aKDF_B_AArx;
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
    TwistExpander_Karate_Arx aKDF_B_BArx;
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
    TwistExpander_Karate_Arx aKDF_B_CArx;
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

void TwistExpander_Karate::Seed(TwistWorkSpace *pWorkSpace,
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
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    }
    // KDF_B PhaseA invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseB invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    }
    // KDF_B PhaseC invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseD invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseE invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneH (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseF invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneC);
    }
    // KDF_B PhaseG invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    }
    // KDF_B PhaseH invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
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
    TwistExpander_Karate_Arx aSeed_AArx;
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
    TwistExpander_Karate_Arx aSeed_BArx;
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
    TwistExpander_Karate_Arx aSeed_CArx;
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
    TwistExpander_Karate_Arx aSeed_DArx;
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
    TwistExpander_Karate_Arx aSeed_EArx;
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
    TwistExpander_Karate_Arx aSeed_FArx;
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
    TwistExpander_Karate_Arx aSeed_GArx;
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
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
    TwistExpander_Karate_Arx aGrow_AArx;
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
    TwistExpander_Karate_Arx aGrow_BArx;
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

void TwistExpander_Karate::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Karate::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Karate_Arx aTwist_AArx;
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
    TwistExpander_Karate_Arx aTwist_BArx;
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
    TwistExpander_Karate_Arx aTwist_CArx;
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
    TwistExpander_Karate_Arx aTwist_DArx;
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
        TwistExpander_Karate_Arx aGrow_AArx;
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
        TwistExpander_Karate_Arx aGrow_BArx;
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

void TwistExpander_Karate::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 3, 2, 0, 2 with offsets 3383U, 2331U, 7915U, 2357U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3383U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2331U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7915U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2357U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 2, 3 with offsets 6386U, 4586U, 7160U, 6509U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6386U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4586U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7160U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6509U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 3, 0 with offsets 2809U, 6119U, 4427U, 170U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2809U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6119U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4427U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 170U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 1 with offsets 2188U, 5559U, 5149U, 206U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2188U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5559U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5149U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 with offsets 1080U, 912U, 1353U, 1242U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1080U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 912U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1242U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 2, 3 with offsets 997U, 1504U, 342U, 1362U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 997U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1504U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 342U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1362U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 2, 0 with offsets 120U, 1261U, 1035U, 709U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 120U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1261U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1035U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 709U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 1, 0, 2 with offsets 439U, 1229U, 361U, 955U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1229U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 361U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 955U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 642U, 969U, 1428U, 94U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 642U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 969U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1428U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 94U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Karate::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 2 with offsets 6860U, 2607U, 7583U, 8010U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6860U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2607U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7583U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8010U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 1, 3 with offsets 5085U, 5404U, 2165U, 2507U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5085U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5404U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2165U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2507U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 0, 1 with offsets 2565U, 4757U, 7476U, 1081U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2565U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4757U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7476U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1081U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 0 with offsets 7760U, 4292U, 1007U, 7993U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7760U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4292U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1007U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7993U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4215U, 5389U, 5924U, 6557U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4215U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5389U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5924U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6557U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 2, 0, 3 with offsets 1508U, 1981U, 416U, 820U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1508U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1981U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 416U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 820U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 3, 2 with offsets 862U, 1350U, 1949U, 609U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 862U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1350U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 609U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 3, 2 with offsets 409U, 1252U, 1077U, 532U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 409U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1252U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1077U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 532U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 2, 1 with offsets 620U, 1565U, 1988U, 116U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 620U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1988U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1010U, 1934U, 219U, 1728U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1010U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1934U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 219U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1728U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Karate::kPhaseASalts = {
    {
        {
            0x6760F4899F4DF101ULL, 0xEC35ED5A9B3159DDULL, 0x1254854166F43833ULL, 0x502CA7808984A98DULL, 
            0xCDF7F4511B46B528ULL, 0xD33D629C2D9804EAULL, 0xC03B282432066C3DULL, 0xF87746A9B395A625ULL, 
            0x5831E21AD2C6E6B1ULL, 0x65DB4E84075327CCULL, 0xBC816C074EEE7057ULL, 0xBAACD65AFF4C7AFDULL, 
            0xA8EE2A25359455A4ULL, 0x510274AB3CF7941CULL, 0x7CCD17DB93EE901BULL, 0xB0C71333000521E9ULL, 
            0xB95B0146021C99C2ULL, 0xE30279B4086B12DFULL, 0xDAF890B5BF5FDF04ULL, 0x1C30669DC231C5A4ULL, 
            0x9ABD8BD3AC1EE929ULL, 0x0E3A4DF1CED099D2ULL, 0x13C1F98DC533819EULL, 0x900414F84D11FC0DULL, 
            0xBA10AFD586052748ULL, 0xFDAF4DE18A8B339EULL, 0x37B1741A18A3D906ULL, 0x55DC89CA37D5DC5DULL, 
            0x00290147A61E24A9ULL, 0x9ECAB6B394ABFA07ULL, 0xC6AC59256DFDAA54ULL, 0xB1CDCD3B3E572B18ULL
        },
        {
            0xC0EBE0D283CF666CULL, 0x8AFDD63E2C7F2165ULL, 0xE0004240CDBFDCCFULL, 0x1F19F61D5556837CULL, 
            0x5930806D876A159CULL, 0x8D9D299DDEFAC3E6ULL, 0x7A98E8B8C4BF938BULL, 0xC3413C72912B96E7ULL, 
            0xC34C1ADDF95EC991ULL, 0x341E2D30521835D6ULL, 0x56913F2A5CC37C3DULL, 0x4D8BFECC8B0288C8ULL, 
            0x25C78CFF42B63771ULL, 0x2E9AAE72772D6AE7ULL, 0xDCC04D6248CC49D7ULL, 0xDA935D71BED3DF8AULL, 
            0xBC11D5737C33DF11ULL, 0x8194B12A58F61869ULL, 0xAAAC38B263F7443EULL, 0xAF10652F4F552327ULL, 
            0x4C8F5E089DFFD376ULL, 0x7D18E53A3FC847A6ULL, 0x200F73094F0A52E8ULL, 0x281651069A0A424DULL, 
            0x6E70EB22CDDFE1F4ULL, 0x2E8A4093E1C4383BULL, 0x5F7E97891BB9528CULL, 0x8B32EF5A20F09E97ULL, 
            0x686D05CD3F3B06ABULL, 0x7B2CCA20BE95D351ULL, 0x962B84C0852AA372ULL, 0xA3C592924F624F01ULL
        },
        {
            0x9B19C6E2510DCD3CULL, 0x611D5B1BAD463A87ULL, 0xD5C055E7FC97AE79ULL, 0x7A4C685876C7BD32ULL, 
            0x5ED0BE71D36301B0ULL, 0xC72296EDFA2647D3ULL, 0x8FF76CFEDB663F10ULL, 0x01150FF095A5B66EULL, 
            0x1D0F451E2F22E865ULL, 0x08FED7F497FE6AF7ULL, 0x528C33F98826BA60ULL, 0x3C43B1B7A04AA051ULL, 
            0xDC375E5817840F5FULL, 0x4FE44AAAFB20899FULL, 0x6C83E374763451D7ULL, 0x7A90DB6CACE1D9A8ULL, 
            0xE2A02AF7811B11A1ULL, 0x37DFB18C4C909B3BULL, 0x0A6B3D954700B87DULL, 0x12EC79AB186A6E0EULL, 
            0x7F94B0EAB496CF5AULL, 0x89E010B414215236ULL, 0x05742A6FBB002B9BULL, 0xC9CB308D45BC7572ULL, 
            0xB46E29D543E5212DULL, 0xB6A3A0D385E7DF9FULL, 0xF36710A87C4A100AULL, 0xAEDE75D809F92F92ULL, 
            0x4A06513D8C75FE19ULL, 0xD209BF6501A7A5E3ULL, 0x32CB094CF151C072ULL, 0x6CC7AD4BC3B0BCDBULL
        },
        {
            0xD7FD05A292D799ABULL, 0x9BEEE9290C718BE2ULL, 0x699E368EBB76B1B9ULL, 0x0BAF7EB05683D0D2ULL, 
            0x91C8F36D6878FCD2ULL, 0x0CFFDF4C00C46D8DULL, 0x974EF2C407672338ULL, 0x8930DCDD11FB2C3BULL, 
            0xA188E1B2F5929CFAULL, 0x1E2F36908F1F5464ULL, 0xC35CF1418A58C927ULL, 0x3CBA7B98B8945733ULL, 
            0x9EF3861206BF3609ULL, 0x1E3BEC12A2FE4F68ULL, 0x73A8BF1046249176ULL, 0xDF7F3CF4B43FBCDEULL, 
            0x3C12CB32EEC02D03ULL, 0x77E02977800A5BCAULL, 0x72CB468FD86E9C9BULL, 0xB202534CD66D344FULL, 
            0x2C30CF9883F3A709ULL, 0x1B397B0EBB67FC70ULL, 0xFE9FC3F163020F40ULL, 0xF41B4568D9FA7D25ULL, 
            0x2A24D5FBD13B3B07ULL, 0x05F04593AFA2E0F1ULL, 0x51CA95CE0ED566A2ULL, 0xB5E251467B42695AULL, 
            0x02A8564668C8C6A8ULL, 0x8E631E26A4F5DD8EULL, 0x9DE5E6EFB143DFB6ULL, 0x311ED9E07A3F796BULL
        },
        {
            0xB23979EDD76D20E2ULL, 0x3BE2ED56228395A2ULL, 0xD2AC4146142C9DC7ULL, 0x9A27715C4FF241D7ULL, 
            0x50446C419D0FC77FULL, 0x211D8155E5290E26ULL, 0x1509E771286150EDULL, 0x45C6022DD66A2143ULL, 
            0x33850469FB4C2A45ULL, 0xDD236032977DD133ULL, 0xE5F4972264535C11ULL, 0x184AB2CEC4BE98F9ULL, 
            0x74317E5193F994E4ULL, 0xB88B0D0E67A2DFC1ULL, 0x614A5DE32132C7B2ULL, 0x7847A541069C743FULL, 
            0x61E046C9F9A787A9ULL, 0x637FC3CB74896BADULL, 0xC5C55A445148CC5DULL, 0x32B67174231DF664ULL, 
            0x3F06BD93684A81FBULL, 0x8305E770868C72B4ULL, 0x7BFE3BEE1E8ABF10ULL, 0x630773140FF05FB7ULL, 
            0xC594B4BC72C3A6F8ULL, 0xEED91CABF2F9C903ULL, 0x3E14C0928FDDD923ULL, 0x1208E7F50ABD21B8ULL, 
            0x6B24F45BCD87BDC2ULL, 0x9B3F3E07CFEAB5EFULL, 0x2A43FFC529C6FBDCULL, 0x372FC37AEF51F658ULL
        },
        {
            0x82B9E2398EB1B5BCULL, 0x3B7BBC8372E0443BULL, 0x3E2F0B6B6CEE9E86ULL, 0xEB34DA895DCD2724ULL, 
            0x52AC68513D2DE110ULL, 0xDA0AE8B89C969312ULL, 0x4504195699096270ULL, 0x912EFA255FC0D774ULL, 
            0xD7FD07E8FEA402A6ULL, 0x0136591BB810D820ULL, 0x655F84D9410D5B1DULL, 0x55BB54433EF1F7D6ULL, 
            0x8F80E7C214AB4C73ULL, 0x56C268E63423D46AULL, 0x908BCE14C201642AULL, 0x290D8413AF68E00BULL, 
            0x8095DAE568C97F53ULL, 0xBC4BD90250B2960DULL, 0x3F767F03C0F72132ULL, 0x982532A330E4A668ULL, 
            0xB5C6608FA4B35233ULL, 0xB719A55DE52CDE2EULL, 0x9C9AA8ADF69279E8ULL, 0xE4EC4B2A5382C195ULL, 
            0xBD6266390F09034AULL, 0x38C82D022AEA1AA6ULL, 0xD4AB2B7B8B2254AFULL, 0xC478C69861CAA8A2ULL, 
            0xA222A47F535D492EULL, 0x7A44466F93C5F128ULL, 0xDCEEC7529ECEF5DCULL, 0xD64752D5B2A0CB71ULL
        }
    },
    {
        {
            0x79DA7E7F625B5129ULL, 0x4FB59AEBC2A3A94AULL, 0x2D54C2674EAD98ABULL, 0x63C938A5C31E4699ULL, 
            0x6AFC1A44FCDEEAD0ULL, 0xC28C1A63AC7054EAULL, 0xA25749278BBD1F11ULL, 0x182F50208FFF5AACULL, 
            0xA02B2206E71E75A2ULL, 0x3672F2427081D7FFULL, 0x593E6FFC06A47B8CULL, 0xEBDF602AA3545DACULL, 
            0xDE7B41842F28A273ULL, 0x5D423AC30132419DULL, 0x3187EDC6780F8639ULL, 0x030C93968A579B88ULL, 
            0x23B777AD728EFB7EULL, 0x777B36DABE5AA1FDULL, 0xDA0B22D638415A3AULL, 0x15AD7A2D8EA74C35ULL, 
            0x5FB5630CD8644557ULL, 0x97805B7ABBFF1097ULL, 0x9D4E8ED978EC79CAULL, 0x30C23871D1B9BA8DULL, 
            0x6F8652C1A5974E99ULL, 0xA9ED1E32C5EC330EULL, 0x3A6530BD072E5951ULL, 0x5A104A155671CDD5ULL, 
            0xD4BEFBBCDCB8DE9AULL, 0xD5D645EEF029206AULL, 0x54A3A9338E90B537ULL, 0x3AB2112C99ED2114ULL
        },
        {
            0x9BA641D0F6507FA6ULL, 0x4E3A3DB1FA0D3A4EULL, 0xA6EA77B29744FD4BULL, 0x8C5D4103F7A99636ULL, 
            0x2778496B1296A9AFULL, 0x8D86EFB6B64B07F4ULL, 0x0F9EFBECB19F29FFULL, 0xEE3520CD06CC156FULL, 
            0x20947BFA087CF651ULL, 0xCE364C3AB2DA1DE3ULL, 0x3DAB4862351337A1ULL, 0x501012201A3723AAULL, 
            0x2C3A5BE0B5F2566FULL, 0xC19051238C22BF67ULL, 0xE787D29E3F34A0DEULL, 0x16D2C125BBA80C58ULL, 
            0xD33C5B51F10F02CFULL, 0x5C44DD9EB3437FF2ULL, 0x6818B28EDE7CC730ULL, 0x14980E8177598231ULL, 
            0x7A09B9B485145F4CULL, 0xDE30220238C4FB3BULL, 0x77F8E43EF44163BBULL, 0xEFA522FBCDF20EDEULL, 
            0x4F25579EC73D473DULL, 0x0A86422913B128D2ULL, 0x277A0E22028CCC78ULL, 0xCA1CF8C45B5F4F0EULL, 
            0x6010854A1C65FD51ULL, 0x63C0B3592B77706DULL, 0x0F71E9218D58C3C3ULL, 0x4764DE75C42CE9A6ULL
        },
        {
            0xE8F39AA49E4CDCB3ULL, 0xCDD902C7DA1EDA1FULL, 0xB7F676EF31F02894ULL, 0x275629335ED0BD1DULL, 
            0x25ACD39A1199D99CULL, 0xEC48FD008ED21093ULL, 0xBB142246841C98BCULL, 0x4CE098C61AADA883ULL, 
            0xE742374A27769B73ULL, 0x83912E82CD19BC7AULL, 0xA5B507365B432262ULL, 0x532B4806C661EF7CULL, 
            0x02DC576AF209443FULL, 0xBEBF9DE3AEBE6D24ULL, 0xDBD02E7FEDF6C6F7ULL, 0x5C0CA06A28512414ULL, 
            0xA4150194DC05CA5DULL, 0x7E4396731A23867FULL, 0x706E606789B9577BULL, 0x723DD9E6FCA5FBA6ULL, 
            0x793CC5E3489A0131ULL, 0x8CA844344C52AEBBULL, 0x5BB6485B709576C3ULL, 0x93E5093FCAF9B6FFULL, 
            0xB5B8CAB3B8FDBE38ULL, 0x0D39E453E1557899ULL, 0x00692F0622BCA135ULL, 0x86BC9F869E5192D6ULL, 
            0xFCBED3760EAEE81BULL, 0xE312C1F033196FFBULL, 0xA8F9D784F657B423ULL, 0x7A9B5AA4CFECFEE5ULL
        },
        {
            0xCF321929F675FC37ULL, 0xED93B013D7EE329FULL, 0x8883BEFAC21218E5ULL, 0x627CB18FD83CABCBULL, 
            0x60ED0FFD385BCF42ULL, 0x8B0A122DB24CD25BULL, 0x98D029FA008E0B1BULL, 0x0D3A0ACE5ECFAF1BULL, 
            0xEDD666411C1B5AB2ULL, 0x4D01ADB06DC6A2F8ULL, 0x582ABF2B2CF07966ULL, 0x362ABA632BB1EC2EULL, 
            0x7E4D7C55B238C82DULL, 0xBE4C427F9CD2A16DULL, 0x45D25D41C9EC24F1ULL, 0x854C6BD432438C24ULL, 
            0xE733162055DBC962ULL, 0x6D4E4F4DF5E737D7ULL, 0xB6894AF1C808A7F4ULL, 0x480E35D7A6A792EDULL, 
            0x8B8B295345A274A2ULL, 0xCDE4EC0A95EB36F7ULL, 0x3CE37C41D60BB5F6ULL, 0x8247C8EDA812F707ULL, 
            0x8804CF27AE05B8D7ULL, 0xA8D71D9DBE97AA4FULL, 0x66C3194EACFBE488ULL, 0x990C3EAC922D7088ULL, 
            0x9C96B94C7DFE185EULL, 0x37ED42F7A0C3ECA7ULL, 0x4FE993350761114AULL, 0xCA2142C3714840AFULL
        },
        {
            0x89627489E4B3861DULL, 0x13FD50BCABD7BE7EULL, 0x0187FD52439D391FULL, 0xE295D00B3E754C95ULL, 
            0x3D0A641337C379EDULL, 0xCFBB748A5B55789FULL, 0xDBF8F6C94EAFA63EULL, 0xA5B5623B557D3AF4ULL, 
            0xB2C17C16D4958719ULL, 0x03BBF523A627D4F6ULL, 0xD00143BB9524F202ULL, 0xF9125278DE2202BBULL, 
            0x2A78664B1BFF19A2ULL, 0x59E9970A80841858ULL, 0xBB9F21DE68952E71ULL, 0x962BEA85FA219523ULL, 
            0x7ADA69BA944CC40AULL, 0xF2B0134271BEE14FULL, 0x48C30B2B1A09F0BBULL, 0xE25D6D4979F22B1FULL, 
            0xCDC97E47E2D28C76ULL, 0xC235EAB3D9ED485EULL, 0xC1B63166BE50AB1DULL, 0xD8B6FAA9CCBED3C6ULL, 
            0x5ABA22CC42A2EF3AULL, 0x2F9F0F8F725D348FULL, 0x277BAC48F279BC7BULL, 0x707B175A74537549ULL, 
            0x9E3E867B5DCC3FF8ULL, 0x0FB54C360F3327E6ULL, 0x767646FE0F79370EULL, 0x38FA7052FFACF743ULL
        },
        {
            0x24A332336A00FB7CULL, 0xA092F3EF57A95B39ULL, 0xBAB599622016090AULL, 0x41DCA6AC1A0DB044ULL, 
            0x5AC4A24C2419C63BULL, 0x9C17B6E006CC0B87ULL, 0x3856DE511CEDEC2DULL, 0xAC822DDFABE10637ULL, 
            0xA82C2DE0588325F1ULL, 0x4659D5FE7346A0DCULL, 0x3159CA8337EA8559ULL, 0x1498B050C7359862ULL, 
            0x9609C493E1D29BBFULL, 0xA6AD209BC0016D4FULL, 0x2DF273A4B146740EULL, 0x2643D5471B51FF34ULL, 
            0x30EE15A66EF36B21ULL, 0x381BD6C4D9A5427DULL, 0x062C8C5BF88EF459ULL, 0x5D5BBDC25C093BCFULL, 
            0x78E47653B371116EULL, 0xCDB45DEA8A9BD4B4ULL, 0x1E249473F00FAE28ULL, 0xF2B2E226D485C97BULL, 
            0x801467A89812803FULL, 0x406B408D0B8FEA90ULL, 0x74018428BA84EFE6ULL, 0xFBFDA5554B63E20EULL, 
            0x604BA3F3DA70D035ULL, 0xFF292C0BCF8871DBULL, 0xDFEF65C238D7493FULL, 0x8F513EEDEBD6BD32ULL
        }
    },
    {
        {
            0x250D1EF9E4AD355EULL, 0x4F72566A854271C6ULL, 0xED1711421BCFEC8BULL, 0xC8302E99F5E9EEE6ULL, 
            0x462F6E459774BAA2ULL, 0xE16C53E614870BCEULL, 0x59C9283DD9136E22ULL, 0x6D553CD2AB6C8B10ULL, 
            0x3587A893ECEA5BA3ULL, 0xB16991B5C7C4E206ULL, 0xF1736A98465A7D03ULL, 0x1AB9A95B206E81C2ULL, 
            0x471C2992782C1BF5ULL, 0x3CCC55603F944B5AULL, 0xB68FCCE5BB94C3AEULL, 0xEF6351F766089BB6ULL, 
            0x0A2A51990EA5C823ULL, 0x0EB1402D083B57CCULL, 0x0EBA93212032613FULL, 0x356C6EF46A840F4AULL, 
            0x9E7D2666CA6CC232ULL, 0x726665A9F3D1B0DAULL, 0x9A23697F94412934ULL, 0xD3BD513A4C8629F7ULL, 
            0xE179ACA4176FB265ULL, 0x8E970F5A7C584B71ULL, 0x4504EABE93693628ULL, 0x62E41834C957615EULL, 
            0x093E049A825D74B0ULL, 0xA149660EC65F93D7ULL, 0x3E41404A7F03BA11ULL, 0xE6D08CC0721DE90CULL
        },
        {
            0x0E051000DA3EDBB2ULL, 0xCA449E01DE1A8AFDULL, 0x3EF6DFD3BEBB8544ULL, 0xC594B290FF63900EULL, 
            0x619968F654417DF4ULL, 0x1ADCA39F5C1C3428ULL, 0xFE5019FC5EF28079ULL, 0x690974C834498466ULL, 
            0x77707EDE5AD61F9AULL, 0xD0D9D9C4B0118DFDULL, 0x59D3E9106B1EEFECULL, 0xE87DCFDC313CF966ULL, 
            0x7DA1B5CABF3C4B40ULL, 0x88908CE3ED376643ULL, 0x5CB631F5099DE453ULL, 0xAC7924846AB24C63ULL, 
            0xDBB960DE90E7BD9CULL, 0x54C4B913964A36F5ULL, 0x8E13D88F647BEAB3ULL, 0x5FF55C9C2DA75D12ULL, 
            0x54C86E3A650F013CULL, 0x25A985CC3A7D339CULL, 0xA103FD60310499ACULL, 0xE157DFF74F519984ULL, 
            0x6C86E9FAE6BBA2FEULL, 0x1E15736428860818ULL, 0xBFA8F97D70F4FA32ULL, 0x05D59D97D1881729ULL, 
            0x8084593F5FD0A0C9ULL, 0x9237840238FCDC4AULL, 0xEB6C2329BF994891ULL, 0x1721568381368814ULL
        },
        {
            0x6CCCB9BCF21E882DULL, 0x739FE71852776786ULL, 0x430377664789DE00ULL, 0x904F9BCA0B59BF55ULL, 
            0x7D9597AE5F95BC55ULL, 0x8D738844E92B8F31ULL, 0x160B2830A0831244ULL, 0x4AA1BDFC844BE3C6ULL, 
            0x3A1B10CEAFA0B118ULL, 0xFF7A557128C80D39ULL, 0xA7375D9CFBBE3D99ULL, 0x92A5D481E15430FDULL, 
            0x216F21A8988A58FEULL, 0x6D8547BC3307AE45ULL, 0x1822497D2630E0B7ULL, 0x381B85F7B06A1F98ULL, 
            0xF749D641A28F6224ULL, 0xFC791725AF3B79B3ULL, 0xCD5A0C3A4D4A2E18ULL, 0xDC94A85EC4AECD11ULL, 
            0xCB67F882BCB5096FULL, 0xF5950D01CDBA6F0EULL, 0x4FB8D529FE0899F6ULL, 0xC70358ABE4BBF2CDULL, 
            0xCBD9FDAD6701D453ULL, 0xCD57CC2D41A777D6ULL, 0x243E410DFC03FE68ULL, 0x6349C637D782077FULL, 
            0x3BD2B4373BA89E5EULL, 0x9C90A9C22828C63AULL, 0xB450AD4784FAF4B6ULL, 0xCF583263F692DE71ULL
        },
        {
            0x6DF121A582FD277DULL, 0x4C821725BA4EE37DULL, 0x2A377DC00A3AD70DULL, 0x29C414CC9E086DA5ULL, 
            0x37D12A967B52BC5EULL, 0x9F9B8A1026976B19ULL, 0x0EDA667DA2CC6C8FULL, 0x965BCE2A99B5D054ULL, 
            0x9BC27D8C0FB1E28BULL, 0x781ED16CF2E878A7ULL, 0xE6D809603061E957ULL, 0xB0EDCB6B6F012F3CULL, 
            0xF6637EC9B8350A47ULL, 0x836D2D8B3E3FE7EAULL, 0x5B0A4B46E1335CA2ULL, 0xE1E216C39D0E18FDULL, 
            0x45122E64F875EB7EULL, 0x2B8F0CDB339B7A96ULL, 0x247AACE9590FF9DAULL, 0x65621F9DE429ABA9ULL, 
            0x5A72DEBDEFE356AFULL, 0xE269C1FC63826D04ULL, 0x8A4934C27D19367AULL, 0x58C5F2F9DF4F17E6ULL, 
            0x63A03B5D4BDD3FEDULL, 0x5430806C32CAE502ULL, 0xEA9BFE2CAC5526BEULL, 0xCC3DE649EC33FD15ULL, 
            0x574318F2A80B1A46ULL, 0xA1BDEAB3FA164089ULL, 0x788A03BE55239639ULL, 0x0A7B2E635946E5C8ULL
        },
        {
            0xA3F490D98A2C0EE9ULL, 0x4FDA40587F1EDA35ULL, 0xF3DCE9B9D02FBC6DULL, 0xCD9E4B90E3D68D1EULL, 
            0x8E2C7A7595136F22ULL, 0x2EDD5B323CDC3E30ULL, 0x37B314068632057CULL, 0x225574517C184BC1ULL, 
            0x3882F4175C0E35F7ULL, 0xCA5532A9EEB1C879ULL, 0x6F3C959B75C5F044ULL, 0xCEBAA1EF32E7EE82ULL, 
            0xBF054E342F6E1EB5ULL, 0xCCC6A0140AB948A4ULL, 0x7698FF0ED2CFA823ULL, 0x7CDB4E82A95D87D5ULL, 
            0xB020A460418CC160ULL, 0x74B5931F46478A07ULL, 0xDE8FFC2A6603BCC8ULL, 0x9FE28981C7EC5521ULL, 
            0x40B0A90C824AA076ULL, 0x795D3789B9BAE236ULL, 0x260F4D5CB7D4FEA4ULL, 0x28E675CC05D47FF7ULL, 
            0x33B5D232753F2846ULL, 0xA595305E557FDD1EULL, 0xEF0847DDC1223118ULL, 0x5EDA7CD5B3563187ULL, 
            0xFC86BD6F8F76B12BULL, 0x59449878FF47F931ULL, 0x5B62F8E4A1FEDC1AULL, 0x3484E4328750A13AULL
        },
        {
            0x1F029B68F16EB073ULL, 0xB8BDC30F7A063F99ULL, 0xE2CDB5D941F4A4E2ULL, 0x6BE83AE0EA0BC91AULL, 
            0x20C0AB3BE16BC7D4ULL, 0x5B5B5D93FEB95EEAULL, 0xDD722A3C9389CDD4ULL, 0x3A513C957611D6DEULL, 
            0xC6FAC128B53BE5E7ULL, 0xEC9A1524F7D8EB1EULL, 0x1D8DDDB52C4425F7ULL, 0xA55AE5E107B71EF3ULL, 
            0xB0871577DF54D143ULL, 0x0ED8D4006FC0498AULL, 0xFCB931AA41ABE2A2ULL, 0x7CFF0BA3B52E4224ULL, 
            0xFC97A0FA47E29F5DULL, 0xB02B7107053E7CDBULL, 0x9F9A6623C6D0C269ULL, 0xB92984478F6FF284ULL, 
            0x8AAEAFB25599D4FCULL, 0xCB54889411C4D230ULL, 0x234AFF8ED8E2D345ULL, 0x9C8AB1288FA9B1C7ULL, 
            0x40B6C56317CF4041ULL, 0xE00DAD838B72DD10ULL, 0x6BC893BBD420DD5BULL, 0x81F422EECA581A00ULL, 
            0xC4FEA9733707A006ULL, 0xADAF42DAAB74EBEBULL, 0x1B999EE2B431A3E1ULL, 0x34DE1A7D9C998479ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseAConstants = {
    0x55820C888C278B3FULL,
    0x6A600A2F6294B273ULL,
    0xB8909D04ED4DD4F6ULL,
    0x55820C888C278B3FULL,
    0x6A600A2F6294B273ULL,
    0xB8909D04ED4DD4F6ULL,
    0x8ADBE40A10251890ULL,
    0x46E41E6B3BED21FBULL,
    0xF2,
    0x7A,
    0x8F,
    0xDE,
    0x14,
    0xE2,
    0x37,
    0x51
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseBSalts = {
    {
        {
            0xAE7E9273344086E2ULL, 0xCBF5F256F541D11DULL, 0xDBD9754A5094C25BULL, 0x4F119A8B8E541715ULL, 
            0x6AA8E038C2E51A93ULL, 0x6B7867CB65B99FB4ULL, 0x78D8CBEE206760A0ULL, 0xB21975704982ECA4ULL, 
            0x295A99AD6DBC8631ULL, 0xFF0BCCDD1925EF13ULL, 0xA038843B436F52BCULL, 0xC35160B9B367D249ULL, 
            0x8BEC041A42EED8A6ULL, 0x49BC01F6AE700E79ULL, 0xE92E78932BBA5131ULL, 0x641B729A433484C4ULL, 
            0xBE4731C38FD46ADBULL, 0x8A5B06876DA70FC9ULL, 0x42513FAA95DCC000ULL, 0xAD7482A1EF9898DAULL, 
            0xCEBCDCACD8566FA2ULL, 0xC138E0FCEF16DD82ULL, 0x8A8A29CED0A8EF94ULL, 0xD3A2464AAB335ECFULL, 
            0x6B20901EA0B96D05ULL, 0x10D86166A9CB6E26ULL, 0x3BC6BF8C2BAD59BEULL, 0x9CB2019EE9AEF09AULL, 
            0x9644DA188E1A9CD1ULL, 0xBB520441C3626B76ULL, 0xF1768E1C9B508C2BULL, 0x097A464015FD8ACAULL
        },
        {
            0x3D413975531EA106ULL, 0x25C2CC945AC2C7F3ULL, 0x66310E8218AED9B2ULL, 0x0D1A6EAD97316784ULL, 
            0x8F1EED0E1CBECA8EULL, 0x34736F503DB8FBC4ULL, 0xDCE9BF7EDD60C770ULL, 0x945E4C197D7998C2ULL, 
            0x0EB98E1838579846ULL, 0x60CFF55EA6708CB1ULL, 0x1201813DDDA11D3AULL, 0xBECEF82DB8916FDAULL, 
            0x9BBB242DFA1CFA40ULL, 0x6BAF552BDD675FC5ULL, 0x587D87B9283B0AACULL, 0xFB0C6EDFF769CFE7ULL, 
            0xE086EBCB29B6EEDBULL, 0x63646EFE2B01814AULL, 0x55A94FD179B343ADULL, 0xEF853849FD90EAD0ULL, 
            0x43CA195D877E26F0ULL, 0x4510C29D1E85215AULL, 0xE4259AB627E8CC60ULL, 0x1996360CF37AEA0BULL, 
            0xCC85A647A95A1664ULL, 0xA528129AF14F7AF1ULL, 0xE14F05DCE039971BULL, 0x88B3D2E740A38EC1ULL, 
            0x8AD35E8A99A97E22ULL, 0x3AB752C3A605E8B4ULL, 0x00BD570BD0273077ULL, 0x986BAC8D90F18904ULL
        },
        {
            0x5E828AA80214131DULL, 0xD301D5F32AD4EC7CULL, 0x07E7BE62DF1C78D4ULL, 0x444E5F18C4309AB4ULL, 
            0xBE4F5F2ECD1D7B75ULL, 0x439B7EBEB1E5319DULL, 0x56B8FD3E0F4E750FULL, 0x7580426A7BEBDA36ULL, 
            0xD2489983EA882B57ULL, 0xB921E36F62154357ULL, 0x43EB2B89C5AE849DULL, 0x67A66E2A40744AB3ULL, 
            0xC5B32AD070E17838ULL, 0x82E5C433248E524FULL, 0xD4AA54A20B9172A0ULL, 0x7B38C227497016E4ULL, 
            0x629943538705B971ULL, 0x846419EAE4912C1BULL, 0x7990EC562008ECBFULL, 0x64E5E7E3E97C76F5ULL, 
            0xE4634700007994A1ULL, 0x0043E579B22272C4ULL, 0x8BE1BC0891125F30ULL, 0xF57F813F82EA035DULL, 
            0x07E72FFB7C8B06F0ULL, 0x3D030A4DACB4DC00ULL, 0xF40A3F582060C064ULL, 0x8AD4F06D7BA56AC9ULL, 
            0x1D095B482847B7E7ULL, 0x08BAC0D3D844A79BULL, 0xCEA529862264EEE9ULL, 0x6694D5BBF1FB41B7ULL
        },
        {
            0x1B9B36D2CCA805B7ULL, 0xE31BA25448BCF1F3ULL, 0xCB4AE7E1374C8EA1ULL, 0x064405FD4D68B1C8ULL, 
            0x1FE2722EF03E195CULL, 0x41E02C12C538E4D2ULL, 0xAC39399C6239A27FULL, 0xE8859B71A90E3B60ULL, 
            0x8CEC5A44EB2A8F6CULL, 0x07C8EE253D0BBFF6ULL, 0xC350CAF486B4F75DULL, 0x788DC5E1B2015855ULL, 
            0xC447C52E8BC812B5ULL, 0xA11F31546D609832ULL, 0xD711B064A1A3798BULL, 0xE306CBD7C54C0CECULL, 
            0x0309A3F6FD4F918BULL, 0x199BA92FD2B540E4ULL, 0x5ADB4EDFCA2D1976ULL, 0x5322E842759C90BAULL, 
            0xD382F1FA596C7389ULL, 0xFF9056A6F6219583ULL, 0x6A0609BE5A195A18ULL, 0x00164A74D5F66C0FULL, 
            0xFE628E6A54538006ULL, 0x8B90728789C209ADULL, 0xB58FC08218178FD5ULL, 0x7BC8429DA0785A4DULL, 
            0x88277BED35AF7E5BULL, 0x3538C99BC0ACA156ULL, 0x7567D5C2EA37458CULL, 0xD28972F903079978ULL
        },
        {
            0xB17A792525221CC1ULL, 0xFCBD5BBB9E11F7CEULL, 0xE37509AA27024B6DULL, 0x87E4D2D69DD304B8ULL, 
            0xD68F68DC02CA9F97ULL, 0xAFF03977860113D2ULL, 0xD5CAEEF3918E99B3ULL, 0xC21E179043258BFCULL, 
            0xCB3C3CD2B8765344ULL, 0x9BFC8D2653B2E068ULL, 0xA7D38F71428FAD91ULL, 0x597D36443926880DULL, 
            0x0C0138698A68E700ULL, 0x925E1D1135A34D93ULL, 0x0E23F5AFAEC52F4BULL, 0x61B01D3426BE0C1CULL, 
            0xDCD1850824907CF9ULL, 0x90E771A905D10102ULL, 0x355101D998380BDDULL, 0xF778D42AE1F73703ULL, 
            0x7A46435DEAB71EA7ULL, 0x089B8E7CDBBAE9B0ULL, 0x69CBAF0328D7335BULL, 0x9FA7D58B97644A26ULL, 
            0xB4963E33B4EE1AB9ULL, 0xF08ABD154E0D1B12ULL, 0x4270ECDF8BA56B97ULL, 0xCC18E4CFD5B47015ULL, 
            0x6E1B61C27AB2B656ULL, 0x5CC1C725F5C876A4ULL, 0xEAC60D91A537B021ULL, 0x30CEDF212C752FFAULL
        },
        {
            0xBEC9407A7944A317ULL, 0x166AC625E096FD9BULL, 0xD5E40A538E82CFCFULL, 0x34AA133A9AFDF2EBULL, 
            0xFB62A514C4DE0B08ULL, 0xAA4CB2731BC147F7ULL, 0xC5297CF4C412444BULL, 0xA73A5F630EAEB6EBULL, 
            0xF0694406BEEAECE8ULL, 0xF107D04236FE76E7ULL, 0x0A2DDCCB5BF0BB92ULL, 0x108CC2E46E896420ULL, 
            0x033740BE95E036BDULL, 0x59B6EEDE609E57DCULL, 0x884ACBAB88EB8AD6ULL, 0xCA5CDF2093398FC2ULL, 
            0xB4C63DA5D41E0344ULL, 0xC04883FEF0D0F4B7ULL, 0xAE5B2BA766965EE1ULL, 0xEF1C8497EDCE82CEULL, 
            0x353D22492DAC9224ULL, 0xD46FC811F113014FULL, 0xBB362DDF6E2E0236ULL, 0x85E8E57037286827ULL, 
            0xDD416D4542C38CB4ULL, 0xCF3A95C6B0F33637ULL, 0xEF571D83789E81B0ULL, 0xC4716ED167E5BE2BULL, 
            0x86464B038C0405DFULL, 0x6A85070B53AEC225ULL, 0x2F2D126337E08470ULL, 0x9F7EB552EB856886ULL
        }
    },
    {
        {
            0xB918A07239015FBCULL, 0x170C22DB08D44D69ULL, 0x798CF0B1739D6262ULL, 0xAC04089F04D895E2ULL, 
            0xD473E7006037C2B9ULL, 0x0C2248C5466D3025ULL, 0xCDD2DECDFC3B7E36ULL, 0x1E1B32B6E665AA72ULL, 
            0x3AB6989FFBDD0B56ULL, 0x01AD36C5273BEE01ULL, 0xDF5E07BE4F710FD4ULL, 0x5D12F04851A841C3ULL, 
            0x92326B32B849AD1BULL, 0xE50E271562EA5135ULL, 0x1AE1BC194851D9B1ULL, 0xC14EC06F8DD8455FULL, 
            0xEA6BB383E6E93CEDULL, 0x26576D7BA2F843DCULL, 0x7E23EFA13C4D4FB2ULL, 0xE3A65B20432DE732ULL, 
            0x188641F5932BAB6CULL, 0x274406317717F5B8ULL, 0xEE37F196390FA90EULL, 0xDB12CE8ACD038723ULL, 
            0x31023D8DAB6629A0ULL, 0x1E2DF6B34115A48CULL, 0xB4CC62CD0177C4E7ULL, 0xE5D2F96B6C789945ULL, 
            0xB8321837B0C1D380ULL, 0x56F4AD23FE8E97B4ULL, 0xEA46A6F4ACD740E5ULL, 0xF0414A55FE738216ULL
        },
        {
            0x249F0FBE0B1A6169ULL, 0x8A1B8D5CD6B0BDC9ULL, 0xDC435D18A762D9C9ULL, 0x2CFDB67263405694ULL, 
            0xE917E2229BF8AA34ULL, 0xE6F0FDDFA455326AULL, 0x927F98C83C32D739ULL, 0x83247798EA25A330ULL, 
            0xFF91AAC21911A208ULL, 0x4FAC5E5F1216C5E5ULL, 0xF1D72B989DB4B161ULL, 0xE7855EFAB9484910ULL, 
            0x34F0CD44DF9E26BAULL, 0x0F624BAABB9FFEA1ULL, 0xB18B443C44F9CF75ULL, 0xAC1C956BB8F28574ULL, 
            0x7E4BC53E95D585C2ULL, 0x0FA3CA0F76137591ULL, 0x15DD35E4D9F3E42FULL, 0x8D4348C0A1DA28D7ULL, 
            0xF99F953A67C8C20CULL, 0x77AFD5C4F9ACE1E0ULL, 0x1F72CF9EE974063EULL, 0x4B5EB37644ED407CULL, 
            0x90F26B8A902C2B18ULL, 0x30ECDDE9E9721F5FULL, 0x88C077380120E352ULL, 0x714239EA856E45C9ULL, 
            0xB6841AFA0A4B7B2CULL, 0x0F506397B65AB6AEULL, 0x493FCF74505BFAECULL, 0x49F982CB987790B7ULL
        },
        {
            0x8E58BEB6C5A7177FULL, 0xA496AAAA2D2B7419ULL, 0x4F1D55AB610A8A1DULL, 0xA4A007F0423EE70DULL, 
            0x58C299254856E8B3ULL, 0x20337A610C65773DULL, 0x778A81B330E08DD2ULL, 0x39D8EEA8323A8D2BULL, 
            0x8F9BD27A48FCD603ULL, 0xB592969E76583BDDULL, 0x06A744FDBFEF6118ULL, 0xF9B637613C66602FULL, 
            0xF0D39ECF66888F40ULL, 0x075A6130B9FB1B3EULL, 0x4443778E27AE8F8FULL, 0xE2455F8CEABCC54FULL, 
            0x461F08E790EB58C5ULL, 0x5AB22ADBC5C50500ULL, 0x50C57528DD87DE9AULL, 0xE4CF94B6FA88A3E0ULL, 
            0x93B2301F33A2304BULL, 0xBA5F6A4F48B336BDULL, 0xCFEB144AF4C0A2BFULL, 0x8621B803847211DDULL, 
            0xCA56DEF51A727632ULL, 0x4F9A66CCAF6B00A3ULL, 0x0CE43D3EDADE25DBULL, 0x85CA320051C384ACULL, 
            0x8D4968C3701C7DA3ULL, 0x74D87320D7F33E76ULL, 0x3129EDFBA441AF1DULL, 0x20317423A0A66A42ULL
        },
        {
            0xE40CD20663E9F9D8ULL, 0x1B0CCC2BB04F46B4ULL, 0x0E55104682A259F2ULL, 0x581ECCA4840A1C29ULL, 
            0xC46E619C957072A3ULL, 0x0448D898DD1914E9ULL, 0xB76741F3F366D42DULL, 0x331160FED8129100ULL, 
            0xA6B44ED28FA5836CULL, 0x47D9C0EC3E65FFB8ULL, 0xB8415DC79EE4F09AULL, 0x541191532978DD3FULL, 
            0xB6CC8D02C5FB0E92ULL, 0x1A4FCE1231421838ULL, 0xAD27AEFC764F5402ULL, 0x475DC988254B3778ULL, 
            0x5099756C0D4EB447ULL, 0x9C38526A8216D9CCULL, 0x6258E590E00913A3ULL, 0xBD8C66946BD50C8BULL, 
            0xC415FBDC5685F3DEULL, 0xB41BC3B8080E53C6ULL, 0x5808AF17EBF93E4AULL, 0x049D28554DE8FA85ULL, 
            0xEFC9380EB66FD806ULL, 0x5AD0049C9AD79A45ULL, 0xDC673BDC4DA2F01CULL, 0x8A8C84A155F612D5ULL, 
            0x1949E18702EA0118ULL, 0xED1B2A2E83FB1A7EULL, 0x0DD0C921155D618FULL, 0x727C726354464305ULL
        },
        {
            0x655B91E91C488CF6ULL, 0x016A63E132153878ULL, 0xAA81226F85BAA7D2ULL, 0x4859B82DB9574371ULL, 
            0xE54F8361AA86B76BULL, 0x76DC2D88A1A0165CULL, 0xB994443C3168591AULL, 0xAB7BF96D229D4766ULL, 
            0xF4CF13680626F836ULL, 0x880D3F926B2568ADULL, 0xF1FF7C6CDE56CF3FULL, 0xA1444B5CCFC8D6DFULL, 
            0x64AF22630316D038ULL, 0xEDD27F03DBB9F966ULL, 0x9B8491C01B642E43ULL, 0x7031FB86B4BD5F8CULL, 
            0x8284AA6A53B90A09ULL, 0xCD0F685CE5F516FEULL, 0x7032240B32E98E52ULL, 0xFA57EF4C611C4CDAULL, 
            0x09A63B6ECB35CF29ULL, 0x6127E7669A8E904EULL, 0x02638150DB442A1CULL, 0xED65DAA3867A45A7ULL, 
            0xD6C674AC01DBD8ACULL, 0xE76CCD500F285808ULL, 0x7113AC4CFD973D69ULL, 0x18EB94396A6E5B07ULL, 
            0x5DC4F39AF1CA2398ULL, 0x71B09C8E033ADD05ULL, 0xCE30608155263D14ULL, 0x19CD1764C838C37EULL
        },
        {
            0x4B07A558EE074B52ULL, 0x238C37021F792816ULL, 0x0B371310BE24A0DAULL, 0x2F1FA3F567CF82D4ULL, 
            0x9115B559E3D2B136ULL, 0x96FB46173CBEAAEDULL, 0xDC889E6AE85C64CCULL, 0x5074C94A16FDF98CULL, 
            0xAAB81077D25203DEULL, 0xC8BE9C2D466783CCULL, 0x115DB3E2168D0AFDULL, 0xC8E0245F8829E814ULL, 
            0x92F124DDD0C3098CULL, 0x7744E0CFE2D8BB18ULL, 0x70DF70A7E07C52EAULL, 0xADE21969414D217BULL, 
            0x32A9E958C18DE91AULL, 0x9275A3F7E0B7DC5FULL, 0x7239FB3310516852ULL, 0xB18D87B1B3F230A9ULL, 
            0x8ADA8E60AA80FC95ULL, 0xAD2420F3FFCC7215ULL, 0xC775E2BA99B44717ULL, 0x1B8F762638F24BB6ULL, 
            0x54744C43088CD2F6ULL, 0xBEA32B53B76AFBE5ULL, 0x3B37866B694EE263ULL, 0xC1F79EA477872DB6ULL, 
            0xAF432687C7FF62C0ULL, 0x5B4B33D6D0B6AD4AULL, 0x89B3FB7C583093D8ULL, 0xE9C121C531D47667ULL
        }
    },
    {
        {
            0xABBF8A0F439EEDDEULL, 0xE322ADC3B3CC52E3ULL, 0xEC482C17CEBEF2CEULL, 0x9A57A039310E3A2FULL, 
            0xF95715C62051948BULL, 0x7AB25D4CD07EF3ABULL, 0x452E7B5B4D3FD99CULL, 0x03AC0877F0F1EEB8ULL, 
            0x4A94DEAF836B39D6ULL, 0x81D528292C2B2D04ULL, 0x01D5C874E2A2A7E9ULL, 0x479444580D96A032ULL, 
            0xAAC226920BED2188ULL, 0x45DE5D2407F558D2ULL, 0xE7CD6D4C5119807CULL, 0x06B6E98008433C3EULL, 
            0xA1940AED7EFF366EULL, 0xAF9EB95821BFFE28ULL, 0x00E246990BCAE450ULL, 0xB26809DFF028CF3FULL, 
            0xA482F8CBF4B5E0A4ULL, 0xBFD04F2983ACE762ULL, 0xE8420943AF02AEA1ULL, 0x32F87A857D21E51AULL, 
            0xC0A44480A1E38288ULL, 0x95159E97664A87FBULL, 0x7F4B8EC9F0CAF337ULL, 0x9E841686C2BA37C8ULL, 
            0xE0BB6B02F60E87D0ULL, 0x5B6356FF02EB4B8AULL, 0x012F51DE83F7D997ULL, 0x0A40D9DFBCFF14F6ULL
        },
        {
            0x2992404A84A0C7BAULL, 0x8CD407B18B403267ULL, 0x324FDDE171EEDF9DULL, 0x82D2C17F2CF55B6BULL, 
            0x58BB91D93B43C9A7ULL, 0x74B525FB3A96BCFCULL, 0x00961396F7CA5822ULL, 0x85F40D60D914EC9CULL, 
            0x67DE129E4B11AAF8ULL, 0xC74083A814F84E66ULL, 0xB8287ED4B484D842ULL, 0x97D744DE0764FCF1ULL, 
            0xB22F30A782A27307ULL, 0x8C293C9984A9B895ULL, 0xAF49E7EB40B408B4ULL, 0x18B03ADD8C767B83ULL, 
            0xA295E3B796AD2B21ULL, 0xF9C8B5E77E333827ULL, 0x9D3DFFE76896F5ABULL, 0x16A8F3C50B654DC6ULL, 
            0x8FA09C3133C2135EULL, 0x6045AF4BFEE4E42CULL, 0x06508616A4C7A172ULL, 0xDCD17A994E753FB3ULL, 
            0x69593699A1335CE2ULL, 0x44FAF75D56245FBFULL, 0xEC6BF72E61D6C709ULL, 0xC3242D19F56CAE3BULL, 
            0x108D1601F20D9209ULL, 0xDD0A7A53280636D0ULL, 0xD25CF5F256B103FAULL, 0x3F7705DD824787F3ULL
        },
        {
            0xFCB83959026D6BFBULL, 0x0C73D41B3766749FULL, 0x6C8B6459B0A581A0ULL, 0xA6BC919BEA137C4EULL, 
            0x6E334158EAED02E8ULL, 0x187D9113FE2BC2C2ULL, 0x21DAF89854F80FFDULL, 0x8EC9409CB8D7567BULL, 
            0xF2F8340E535E3CC3ULL, 0x091FFD6126579DF4ULL, 0x57D47EAF3ABB07CAULL, 0xBD31DD06368169A2ULL, 
            0xC98F53D100FCCC3AULL, 0x3552AABA25CD87B9ULL, 0x9B7EF2FE37924E45ULL, 0x7C839FB214C5EE4CULL, 
            0x58B9F15AEB946D2FULL, 0x8DDF1E949C9FFC50ULL, 0x8961FA91A8FDF473ULL, 0x4104C4B146E0599AULL, 
            0x78E2F24DBAD85EB4ULL, 0xCB89BA50FD40566DULL, 0xC15C6262A8B352F0ULL, 0x577A6BE291BF9110ULL, 
            0x016692ED58D730DEULL, 0x9DF0C14D9D5C2F9DULL, 0x935C0EB8DF568E81ULL, 0x31C417065332A270ULL, 
            0x1BCA353F25A40CB3ULL, 0x5BDC9D98E94918C6ULL, 0xB1AA36AEAD287F19ULL, 0xCD20685961C16398ULL
        },
        {
            0xC3FFFCB299EBEF29ULL, 0x0E9D25588CF6ECE1ULL, 0xE7910DE0884DA3D6ULL, 0x8112187A3DDF7C22ULL, 
            0x49CD6D3F1169CDCBULL, 0xBC679D4E07690B83ULL, 0x2ABA22C3EC417984ULL, 0xDB9301E7C8938833ULL, 
            0x5C0B7EB89EAC49E6ULL, 0x4B7C42D0DB9FEEAEULL, 0x25F5829CB04CA045ULL, 0x18E185302289B671ULL, 
            0xAB10635637451227ULL, 0xA61DA8B59059DA97ULL, 0xE31FA8183BE5D39DULL, 0xBECD5F23FEC36635ULL, 
            0x619F09C3968B1AE4ULL, 0x49DEE797D6888195ULL, 0x7019DACAE6A17E6BULL, 0x445D678F1EB72F19ULL, 
            0x07E7AA281F59A7DCULL, 0x0AF7497CF77A3087ULL, 0x883700DDE552D77EULL, 0xFAAEEE0EA7C0836BULL, 
            0x167DDB266AE37FD3ULL, 0x6218AE0E9E9E335AULL, 0xB22B717A42866AD1ULL, 0xC4A6D8907B3DBC07ULL, 
            0x18938BB6AEFD4A1FULL, 0xBB39220DCD479EDCULL, 0xAFA1AF42C85B92D5ULL, 0x2E1DDBB025DD9F9CULL
        },
        {
            0x73F382BBBE93DF2CULL, 0x7A01C7273FAB9694ULL, 0x4A4704A9B38EB80AULL, 0x16FC2F20A109CA91ULL, 
            0x7FA74798D02AE109ULL, 0x08287AA5532D3BAAULL, 0x3C898FA1A7B4DB23ULL, 0xF698BF689176E644ULL, 
            0x8BFFE9CC7F89E523ULL, 0xED6DBA12CFEB4B00ULL, 0xD046594B2DC5D598ULL, 0x1F1DDDF2797408E8ULL, 
            0x41F61074030860DAULL, 0xD28C5B0261E77D54ULL, 0xC9B8AAD776375349ULL, 0xDE45592C9B62A8FBULL, 
            0xFBB75C47A582AC50ULL, 0x83899EFBAA8AC4D8ULL, 0xA27F6FB5D38E5D20ULL, 0x74D6F111F94153EDULL, 
            0x3BDAC81261939E45ULL, 0xEDA603E0E4116E77ULL, 0x817A1F8EAEB5AE28ULL, 0x6D4B39BD6098D283ULL, 
            0xB81DFF93082A9B0DULL, 0x102BBCEAC024696FULL, 0x8527BCAB10CF1151ULL, 0x23FD82BBEE86F24FULL, 
            0x38D41C98BE223A23ULL, 0x8563D6637B28C27FULL, 0x2849E3EB3185060DULL, 0x0411EE696F04E4DAULL
        },
        {
            0xA6A2CB697C6E653FULL, 0x4177F85610109AB3ULL, 0x6AF4D4F38EA6C244ULL, 0x1AF6DE234D00BEC2ULL, 
            0x452568BFBA70B61DULL, 0x32AE92C82BAF6897ULL, 0xC4B5E13FDA892B62ULL, 0x2EE8AFC65C24DC4CULL, 
            0xA68AFF233E78C243ULL, 0x294226A2FD56A32BULL, 0xC37115B2087CABE0ULL, 0xDE64438244FCD46BULL, 
            0xE4C88D0613ECF5B6ULL, 0x946700F797151564ULL, 0x91FBF29A60EC4E9CULL, 0xC46235D48BB5FC06ULL, 
            0xF723B2EC15AF27B0ULL, 0xFCEF548E97D1A249ULL, 0xEB98AFB391ED0BB1ULL, 0x38BDDCA828C434A4ULL, 
            0x69BCA5CB7CBE8018ULL, 0x8468924413502352ULL, 0xDE6EB33986562DFDULL, 0xF93A7CFDE1402456ULL, 
            0x1773804478108AB4ULL, 0xF880FA527535CBB2ULL, 0x621B2E8C1496F0E4ULL, 0x16304E4462F72737ULL, 
            0x3ED54824F5AA5A41ULL, 0x54440E5DA482E475ULL, 0x7447B6C4E92F5BE8ULL, 0xE74F0E22B31E2B71ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseBConstants = {
    0xF6DF8B0D997D3F52ULL,
    0x51424D6EAECB81A9ULL,
    0x9DBE6FB4B4537061ULL,
    0xF6DF8B0D997D3F52ULL,
    0x51424D6EAECB81A9ULL,
    0x9DBE6FB4B4537061ULL,
    0x82ABF620D56E346DULL,
    0xA9E9EFDAE3D1C27DULL,
    0x9B,
    0x6B,
    0x67,
    0xBF,
    0x81,
    0x71,
    0x19,
    0x6B
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseCSalts = {
    {
        {
            0x750ECFCF10363B6CULL, 0x2F3A10B24BA39CE7ULL, 0x2827269F2CC45C22ULL, 0xF9495F2695F23487ULL, 
            0x8AB31E9DE1F5F140ULL, 0x1A649AD724C83575ULL, 0x928FE2AC77C3D97AULL, 0x0D213D5BDDE5DBE7ULL, 
            0xF3FF725800678F53ULL, 0xF1BAAE682F5836D8ULL, 0x0BF2B5632A1F7A11ULL, 0xB7E6114BFB5B64B6ULL, 
            0xAE3B627D42428257ULL, 0x57AB2FD5F27B90F0ULL, 0x610B967F0F792A68ULL, 0x61E4AFBF2153733FULL, 
            0x218BAB810A740D7CULL, 0x1BC8252EE4B03807ULL, 0x20C0FB9234F1F4E9ULL, 0x0972390046CC774CULL, 
            0x0B5A570D932EB87DULL, 0x4E3FAC2D7C9DA1E6ULL, 0x8F4F39717C12DABEULL, 0x05D25FB6800D03A3ULL, 
            0xEA9F53B0D7B1D509ULL, 0xE1C9D89BC5EC7B90ULL, 0x87AC60401158A3E4ULL, 0x88A80C5A1ED73904ULL, 
            0x20004EDCB20C18DDULL, 0xD45AC193A6BC2FCEULL, 0x3F1D896E8C30586FULL, 0xCBD56208EC79E64DULL
        },
        {
            0xB29B1639B0D755A2ULL, 0x3F8ED598D933AB34ULL, 0x33525EAFCB0C37C7ULL, 0x80C313EA63B0323CULL, 
            0xB52C0A54DA631782ULL, 0x934C205B1ABA9DA7ULL, 0x85AC69CD92058F7FULL, 0x9CFE978E4ECEF9EFULL, 
            0xB425AA055EE4315FULL, 0xF155FAB374E26ECFULL, 0x63041572A53C40F4ULL, 0x16F53729D32D91ABULL, 
            0xBBFFC5D5931921E8ULL, 0x3B5CFF2E45F25867ULL, 0x58147C561413C0BAULL, 0x1874D1B11932E178ULL, 
            0xB4ACDCDA208369ACULL, 0xA623BE8B4264F7AFULL, 0xFC81233BCFC049DEULL, 0x4C57DFD0EF52CAEFULL, 
            0x515A693AEC630721ULL, 0xD639219A1FE0D156ULL, 0xD12A16AD821D3833ULL, 0xD36970FB659D562EULL, 
            0xA333209B844FBC98ULL, 0xCEF2197B464CC63FULL, 0xCB50CECF702C1C7DULL, 0xB0728BB5A32FB123ULL, 
            0xAC8598542589E97EULL, 0xC06285889A39953CULL, 0xC83F6CFA21E3A7A3ULL, 0x7449C3F855815346ULL
        },
        {
            0x4F4A5E2C1DE1F6E7ULL, 0x86249C691A50AD0AULL, 0x70B702FA136DF11CULL, 0x3C177C27ED599910ULL, 
            0x57D648CDD127EABEULL, 0xA8680945A4A6F945ULL, 0xFB384F169CC956EBULL, 0x22348A638A8CBB9EULL, 
            0x0554E1485E31F9B1ULL, 0xF3FACC64F1E483FAULL, 0x3A4D5FB7B16D2C45ULL, 0x9180F8FF38996592ULL, 
            0x044B966E1C19FCBDULL, 0xF750127B6F410889ULL, 0x6B09D7A87A4C3725ULL, 0x777CB57FC7A2BE17ULL, 
            0xE082752113500F7DULL, 0x40F16CC1B8D62976ULL, 0xA58E0F2D349C591CULL, 0x581408F149857E35ULL, 
            0xB8723D6225535772ULL, 0x563803ACBF6DDE6EULL, 0x3F63D931E1363544ULL, 0xFA7722B4DDED3A89ULL, 
            0x353C8C0370D43C12ULL, 0xD0A0C652C523D0A8ULL, 0xD2F74000A1B98EABULL, 0x098F11A15D4E2F5FULL, 
            0x1358CB638704DD3EULL, 0xC2AE611AE2C2835BULL, 0x22BCEF1B32CE8E60ULL, 0x8B87FA9020BAA2FAULL
        },
        {
            0xD19996F6EC07E88CULL, 0x3DC3C9D8C8762A06ULL, 0x33799B72A004C91AULL, 0x85FFAD576AB22EDAULL, 
            0x9A15C6F767A6E3B9ULL, 0x1D4703F75D6472C3ULL, 0xFED53A58662D1FBAULL, 0xB46C76513088EE8DULL, 
            0x467BAA66528E2ED8ULL, 0xB6E470139FF3BDD5ULL, 0x384FE4EEA30F7404ULL, 0xBE198DBAF1CB1C20ULL, 
            0x745C66F49F73157BULL, 0xEB112E7C8BB9C173ULL, 0x689520F0EF1DC70DULL, 0x2CB1858B2429502AULL, 
            0xB5D9C867DEAA7789ULL, 0xA11C52B9977207B9ULL, 0x4E3A55C397A89C3EULL, 0x7BCC684AF600742BULL, 
            0xAE7DD506A88B76B2ULL, 0xC20BE0DA87F2C83EULL, 0x50AFF064F9F7E1A7ULL, 0x2575009D5AF8CBD6ULL, 
            0x61B0FBD9F61B8E47ULL, 0xCCAC99AF823E31CDULL, 0x3A9675DE737FD2FBULL, 0x5DF0011CDF927D70ULL, 
            0xCAF2AB0787FAC56FULL, 0x564AB2205F911D9EULL, 0xC5BE0185E1D4EEA8ULL, 0xD5F2BEAB468E6F52ULL
        },
        {
            0xFDAD9EE494FADCF6ULL, 0x8CAEF05767E908A8ULL, 0xBD1FD41EF6F9198BULL, 0x71F2F40C4F684388ULL, 
            0x29FBE67406D8E84CULL, 0x6661DF2E3841D0A8ULL, 0xC5EF20A2DEAE108AULL, 0x2246C41719E7F12AULL, 
            0xB3E6B1F650E543D2ULL, 0x8BE098A69595A5BFULL, 0x56CC7580D96A8F17ULL, 0x053C11A5863AE93FULL, 
            0xAED96EBC08CB9FE5ULL, 0x58E8952DC418C812ULL, 0x0308F89906B31C47ULL, 0x096BD3B2631B33D4ULL, 
            0x76A7875841D353F5ULL, 0xAB09230AE15030F5ULL, 0xF05707972679A18FULL, 0x295D6C0158B2D166ULL, 
            0x6A88A87E85895CDBULL, 0x84D12AB8F864D24CULL, 0x4EAC19EF42E85E4AULL, 0x825EFC92A8504A8AULL, 
            0xCB1C3064096FCD1FULL, 0x9FC629253ED65F43ULL, 0xB4501CE436B5C9CBULL, 0x60B5CE886FF803A3ULL, 
            0xBB37985A11E64287ULL, 0xD826688A41104FFAULL, 0xDD306D6EAF3A96E9ULL, 0x40E4C92AAC48BA81ULL
        },
        {
            0x3C0D8A4E5E65FE8BULL, 0xC77B9412E83CAD54ULL, 0x7336964426897786ULL, 0xFF531223A4876B38ULL, 
            0x3C1784202B521E68ULL, 0xE3F950F84994382CULL, 0x04859FBC10D25BE7ULL, 0x0AC30152A066B768ULL, 
            0x03A0A10186F18C6DULL, 0x40C53408F5B7FE68ULL, 0x134BB48EEB64485EULL, 0x9DEAC6D3F9FAFDB9ULL, 
            0x212E01D4760E2E5BULL, 0x875E56B2031C7821ULL, 0x4F60EB3853867507ULL, 0x811E0B8A05EDD93CULL, 
            0x42A5853C09C2108BULL, 0xD480248FF622619FULL, 0x1FD403D213216620ULL, 0xA6EC11C6004BC569ULL, 
            0xE9A278D42694B7A8ULL, 0xE8E05155EC302583ULL, 0xEC6CE32800907E8CULL, 0xE83411A30C1269C9ULL, 
            0x5150C10FA82B8DFFULL, 0x5D49DFA4E81A8209ULL, 0x5A1AB31FEF882C24ULL, 0xA829D1695DA4BAB4ULL, 
            0x562A71B868455ADAULL, 0x4A6C042C33DFF194ULL, 0x2EA3FDE49730B2A4ULL, 0x80342E358FB8BD3CULL
        }
    },
    {
        {
            0xEBF71C008EBD90EAULL, 0x100B03866DF5D5AAULL, 0x8818FB86A529FDC9ULL, 0xE0B2828AE3A1A292ULL, 
            0x12548F32FC1583F2ULL, 0x9AA8A998B8CE5664ULL, 0x2BA518466D7A170FULL, 0xB28FC39B0B3E73F3ULL, 
            0xBCC71E5570E8A216ULL, 0x4D75952A7A90132BULL, 0x0712C8135A884B54ULL, 0x0F62B4F79BAFCB32ULL, 
            0xF17B8A6306E0A676ULL, 0x1836EB0812EB0597ULL, 0x5D80C752C973A5ADULL, 0x6960D87A23D42ED5ULL, 
            0xE6AD4850E58ECF86ULL, 0xAA101807AC6676F1ULL, 0x0A156D2A71B88C4CULL, 0xF56AA7733339DF54ULL, 
            0xE1EAEBEAE66E5352ULL, 0xA227D9C93F27CAADULL, 0x8A1B54F0E6C30D34ULL, 0xE8BEC45358642504ULL, 
            0xBAF36EF4ACC86B27ULL, 0x54577C25B7FCB0DDULL, 0xE91DB9EB8B19C6ECULL, 0xD999A50B60099CA8ULL, 
            0x6FB8CCEFD7176DA6ULL, 0xF6E09BBB3EC710A7ULL, 0x9EAF140934115520ULL, 0xBE0DE704530F6166ULL
        },
        {
            0xA8850D846F3F4F63ULL, 0xA3FC7E141C8980D4ULL, 0x008BDBBA1029264AULL, 0x3E7BCDD40A1CB077ULL, 
            0x7A178B730F2CF6B7ULL, 0xE0AE1C41E9A225C9ULL, 0x8129DA19A3FC13A5ULL, 0xDB54E6AF0B2EB2ECULL, 
            0xA8F64146BA9E369CULL, 0xF1A73ED8F9C7C035ULL, 0xB5BFD6710893689FULL, 0xB1905CA149DF2CC3ULL, 
            0x96E85A220F32DDE3ULL, 0x33118C2324332F2DULL, 0x4035A926F8C8AA00ULL, 0x21F1B1C446F39507ULL, 
            0x0ADA745C95A1F97FULL, 0x452285C157951074ULL, 0xE3A5A1886B166A06ULL, 0xD181F372DF895B4AULL, 
            0xB60CA03FA67C92FEULL, 0x0F4F72A2D57A2642ULL, 0x5BF4E6A0C80A98E5ULL, 0x6CDEAEFE35C2D12BULL, 
            0x9AE81B1BFFE3624DULL, 0xFDA383F2F5750702ULL, 0x446ECE844429EBFEULL, 0x5C33D191A2D453B6ULL, 
            0xDB4CC291F2D99D53ULL, 0x9594565F144D2D65ULL, 0x50221B867BC66D0AULL, 0x401F79FD454D6131ULL
        },
        {
            0x742F08A2B489FBF6ULL, 0x25F1926EC9831714ULL, 0x6D227D60234EFC7DULL, 0x12A27A6BF0C95F95ULL, 
            0x6223DB72CFF6C4B2ULL, 0x808C3819FD7FE027ULL, 0x4338C5C78C91F872ULL, 0x4B7A7B04ACA934A5ULL, 
            0xBA07EC817ABBF5E8ULL, 0x8EA4DDF4022BA720ULL, 0x04D90CC7F188AACBULL, 0xC4C4F2164153DDD8ULL, 
            0x0DDDF58C71F79D10ULL, 0x4DDB94FAED4F7314ULL, 0xBBE3A9DB3A6FF94FULL, 0x3038E36C5F246CA3ULL, 
            0x36E99A7BA7B5E317ULL, 0x547479E1125CAAD1ULL, 0x9307A4A90F9DAC8EULL, 0xC8C4C0446387416CULL, 
            0xD610ABDE18002D4BULL, 0x0D2BAFE141E6446BULL, 0xC4F95613235B0394ULL, 0x055A1CF359ABA16CULL, 
            0xD4F5EBA547908D70ULL, 0x1DFCC0410697F0D3ULL, 0x6708990C8D6D644FULL, 0xF74B017C52722CCCULL, 
            0xFA3C5B73DDEFD3C6ULL, 0x3501B28EFE23B597ULL, 0x9429CDAF1FB545A2ULL, 0x3ADCCB4AF93F2A15ULL
        },
        {
            0x0BFE2DC84A758562ULL, 0xEC168FEDEB3C7BB4ULL, 0x8D730475FF668354ULL, 0xA2F790EB034213D1ULL, 
            0x0319FC09B82C53D8ULL, 0x2C162F65E882AF27ULL, 0xD55E2A5819CE5ACBULL, 0x2DDE0EC1D56C8AA8ULL, 
            0xA86443511B711DABULL, 0x5D0EF3B473A2086DULL, 0x268376C17DD15F19ULL, 0x87D051336EFE5157ULL, 
            0x0348AFFB0EFE18A8ULL, 0xCFB8CE1957168BBAULL, 0x2F0B1A3F00BFEF23ULL, 0x1C871D950B534AAEULL, 
            0x34AF0C7378EF641EULL, 0x6F48FFBB6E131558ULL, 0x15A5C1B58E9A718DULL, 0x81BA622C10ACD409ULL, 
            0x91C0F538672463ACULL, 0xA25DFCE5508129BEULL, 0x32530DD745C597D2ULL, 0x96C95F7B515A6BA9ULL, 
            0xC7ECBBAD585138CBULL, 0xFE2703C444997947ULL, 0xBA346B5DED25B469ULL, 0x7E29840BEC390D16ULL, 
            0xCF2684B9E80D97E6ULL, 0x28C17A030B21221BULL, 0xBAAF006F26A7054FULL, 0xC40747CCBDEEB91DULL
        },
        {
            0x21E8C2BFA9BE181DULL, 0x64D4E667A3B7BCD0ULL, 0x9FB491A93DEA1644ULL, 0x9B003DEC68C6B41DULL, 
            0xB5BCDCCE767C92CCULL, 0x2F0437FB9ACB90D9ULL, 0xD33453A54D3FBE66ULL, 0x524A78A586F7F1BCULL, 
            0x7FEB4A707E3EE76BULL, 0xF441445E069C3C64ULL, 0x1C7AA322B8D685F3ULL, 0xE55716F426402064ULL, 
            0xDF1DB24E5EAC6B38ULL, 0x65BC5488E4338259ULL, 0xB0BE952A308BEF9DULL, 0xAD40CD631BAA0F36ULL, 
            0x6A9492A95619B714ULL, 0x4B173E91AB7A0193ULL, 0x3F6E94537DC3C6F7ULL, 0xABD21FD2F48CCA99ULL, 
            0x00ED77197BBFF799ULL, 0x48D50CB55CF538A9ULL, 0x4D08A95ED12479E9ULL, 0xE184DDEFE4376508ULL, 
            0x8D67DAF9D645789CULL, 0xBFDC9123B8865510ULL, 0x3E08E52F24342D83ULL, 0x7E69A32B54546C84ULL, 
            0xDEA40ACD2EB9D31AULL, 0x80F2DCB77A6F2761ULL, 0x120262BC83AED91CULL, 0x8FD1E428B94C7EEFULL
        },
        {
            0xE5D921172742B5B7ULL, 0xFF17C4873203D408ULL, 0x751AE2A09E5A1154ULL, 0x858FC6C00B3561AFULL, 
            0x120C0E35C010F2CEULL, 0xD46543BC7C02AC0AULL, 0x32ACA5C29026914EULL, 0xA24C3ADB9E8FAC70ULL, 
            0x8D30D1ED1BDAD038ULL, 0x94FD2B3A89DF87A8ULL, 0xC5CA234B382D15B3ULL, 0x73FB49852BE09004ULL, 
            0x6C7ADA9F31BB43EAULL, 0x3831B2F9675C2852ULL, 0x5DA20AFF024831C4ULL, 0xBAE0F0A6A5EC7C5BULL, 
            0xDE613CE1F896D1F9ULL, 0x546BC4E90A7EDECAULL, 0x2A2D4709A9C662ADULL, 0x75EC3B0E9C73E403ULL, 
            0x273EBD3E5D517FF8ULL, 0xA3A439E8F4AF9B75ULL, 0x1E265746B3B5EDC2ULL, 0x0F709E2C0AEB6A75ULL, 
            0xB241EC3E2E1C8380ULL, 0x04070B1F0F712F4DULL, 0xAF63B377BBD457CBULL, 0xD891AEBE309CD142ULL, 
            0x4B6ED8197913877CULL, 0x133758A5A4DDB4F3ULL, 0x6EE6182F2E98302BULL, 0x3BB70DB1E8120B69ULL
        }
    },
    {
        {
            0x2774FDA3D5A73152ULL, 0xB7B17ED71FDD584AULL, 0xFBBF0535F51F556EULL, 0xDEA0B19973F3F6CCULL, 
            0xEB322F6391E74946ULL, 0x6C244C51C5C62711ULL, 0x01742919A7BE7C49ULL, 0xC1D041D163E4FC31ULL, 
            0xD6458047E2A038DCULL, 0x1FC334AEB812B661ULL, 0x2E43D6B5AC69627CULL, 0x84CF50E0767CB264ULL, 
            0x2355F8FC8DEC127EULL, 0xE6DBC75BD831576CULL, 0x45F4E0D817B7C041ULL, 0x4875E0E3ABD1BCC6ULL, 
            0x1F1164293C07172EULL, 0xD5F017B1230E8FFAULL, 0xEE52AF9E5D16DE12ULL, 0xDA67434B5577D5A8ULL, 
            0xCBFCE8715EDC587DULL, 0x4479C74C615D2AEBULL, 0xC03D70FCE5D91D0FULL, 0x1862E543B58D3B2AULL, 
            0xCB01B614B425E882ULL, 0x3F9BD647C8424224ULL, 0x9E4C89FABA1CEAF6ULL, 0x4D18C480B6E33D32ULL, 
            0x1FC8B9BDF3E1731DULL, 0xC8603E554BBAB1DCULL, 0x1913CE1A97B220A5ULL, 0xF9C24BE3ED558C52ULL
        },
        {
            0x523B772EB1EC3B66ULL, 0x6302B204CB7E1340ULL, 0xD25CF7C5E561BFA3ULL, 0xFC698DB71CE6BEA8ULL, 
            0x0B75354E2E71EFD8ULL, 0xA17694D678C10361ULL, 0xDDDCC4447AA2A360ULL, 0xFBD00CADFDC24F1EULL, 
            0xF02D999863A36D31ULL, 0xDCF4D086EA208ED9ULL, 0xCE4775D7330693A8ULL, 0xFC1724CDEF28B860ULL, 
            0xA8498CDF6B4C944FULL, 0xD8347A3A4CE85F84ULL, 0x0129407DFA658F93ULL, 0x9B2DEE47F2724389ULL, 
            0x995435705A6A6368ULL, 0xE0E71380CB7BF4C8ULL, 0x3A40B69C4EED140AULL, 0x2FFE7A9B5E026BD1ULL, 
            0xA86ADC93E7F61AE9ULL, 0x924A865CBADCF963ULL, 0x7A24C36D75C15083ULL, 0x2D44D78DA3E9823AULL, 
            0x824E6560C6159CB2ULL, 0x89B60950B754457AULL, 0x8B52910084FCA693ULL, 0xAA6BCA93ED6B12E9ULL, 
            0x224F90A88B2E5C33ULL, 0x4AF105BAC98DC4F9ULL, 0x51B965EC28528F3FULL, 0x4F5EB8D661C251B6ULL
        },
        {
            0xC10B3EBD680A247FULL, 0xB5700452E77C5B4FULL, 0x8908D83275731824ULL, 0x29B43F835FBF577EULL, 
            0x54210A4E77D04E51ULL, 0xB6224FD3BE45DCB3ULL, 0xF1F1BF732925EC3EULL, 0x4F06BE5671D70745ULL, 
            0x5FE6AAB6C6EF2C17ULL, 0x04EF0833DAC3657AULL, 0x365D9F92444FAAC3ULL, 0xD2CFF7E31EC9489AULL, 
            0x24E2656A694BECB4ULL, 0x22D98B3CED7D6B2CULL, 0xD35A34ED3B437D65ULL, 0x46EA16C8192EC548ULL, 
            0x8D0A4ED56232B950ULL, 0x041FC9540E3B6543ULL, 0x677E0317FB5666E6ULL, 0x44A486ECA391D984ULL, 
            0x9B5818BEEE05050AULL, 0x0C74E7591C05809BULL, 0x860C9709FF6291E8ULL, 0x860110029A77D924ULL, 
            0x7DBDA25566C09907ULL, 0xD261B202606AE1BCULL, 0x5792FE02974A1E26ULL, 0x9358BF3F5D6B7740ULL, 
            0xF4D72A38D37002E5ULL, 0x924FAA33815775FCULL, 0xDF26367FD46339AAULL, 0xC7FA0E4D968F255EULL
        },
        {
            0x0AC2B93B09163623ULL, 0x46678071A45DEBF6ULL, 0x0F3CD8B0E53A8D35ULL, 0xEC17D77FB67DD519ULL, 
            0xC67C4C46A4656AE8ULL, 0xF5180BD9DA753B5CULL, 0x2611466D4E73056DULL, 0x5FCE458C043150BCULL, 
            0xBE169448D2B08316ULL, 0xB620FE76F44D9527ULL, 0x08A59B9E7C00AC61ULL, 0xF52974527D9E36C4ULL, 
            0xEC26DBB410718054ULL, 0x34BB80F60298BF4BULL, 0x7B71C297037668EFULL, 0x2ADC5DA09C0C7A80ULL, 
            0x027A2E1DF733CF87ULL, 0xC2AB2D389E64E094ULL, 0x70D8A98838CC64ADULL, 0xAE881C50BB5B5EB1ULL, 
            0xA395FCCB0A10572FULL, 0x10242582ECC0D56FULL, 0xB6B3D1DFBE9C0DB4ULL, 0xAF089B6F1A686440ULL, 
            0xA86877E080CC0CC8ULL, 0xCB94326BE499148FULL, 0xCEB4A43F544C0C96ULL, 0xE8CF07863D610892ULL, 
            0x556A0D4E0CE59CC3ULL, 0xECFDBEF8708660C2ULL, 0x8084E3DF2E7E7323ULL, 0xB3298435A63ADA1EULL
        },
        {
            0x186DC4C9EE136550ULL, 0xC7C45623DFCBAA06ULL, 0xD77E3ADBF30F43B7ULL, 0x95798549AF89F51BULL, 
            0x265D2DFA83276444ULL, 0x9F43CF4BF12E4F9BULL, 0x108AC35CF417E031ULL, 0xA0A5F2F06CE94CDDULL, 
            0x9C8315F570AF8A4CULL, 0x8843900D4C0DE8AFULL, 0x354F310951686852ULL, 0xDC848C82F8E36E37ULL, 
            0xAB0DF1239835EF0BULL, 0xBD4BE398CEB505CCULL, 0x00777B734247FBD7ULL, 0x6662C610F8F02F58ULL, 
            0x40A31895EC9005CAULL, 0x39CF023BBFB31149ULL, 0x871EBF4DAB06FE76ULL, 0x89CC4DA90C44E146ULL, 
            0x82EF9CD52BCA0333ULL, 0x7CF09D526878555EULL, 0x37FA1A123F0BF965ULL, 0xE2F9EBB4B6201350ULL, 
            0xF438DC0E7624D959ULL, 0x3D36E2E58854723EULL, 0x1695325ADDF6095EULL, 0x8CA8FC8E09ED9E2BULL, 
            0x5D1B726A1FB4F29AULL, 0xD6E06AE98E4928F4ULL, 0xB61EA1431AE95838ULL, 0x4B5C31FD3C17DF11ULL
        },
        {
            0xCE68B27E2405B221ULL, 0x4D0E04EBC5E41FA6ULL, 0x2E3424251F3D691AULL, 0x0FEE798A03683418ULL, 
            0xA5E7CBCA101AF1A4ULL, 0x1E2566B38744C148ULL, 0x2B38CEE818D28908ULL, 0x5EF93F98A99B42FEULL, 
            0x539ED7F2C04BE04BULL, 0x323106F572674859ULL, 0x5F9E8A63CDF6B757ULL, 0x6CF0FDB638316444ULL, 
            0x8C80407A2E363026ULL, 0xDBA808158EECD2F4ULL, 0xD4359B0870C9CE33ULL, 0x5939059BB3E75B07ULL, 
            0xE6425265CA2AB4A2ULL, 0x35ED62595462A6FFULL, 0x457B87063C59C0E5ULL, 0xD325FD21DF30A4D0ULL, 
            0x5E8A75350BE501EFULL, 0x1B044FB42D809DBDULL, 0x8099D5B8067200B8ULL, 0xF7F4C3071D18B42FULL, 
            0x8298ECFE02EDC711ULL, 0xF2ECC08079B19E04ULL, 0x9618A5C7450C8D8DULL, 0xB19634A0F1C6E1B7ULL, 
            0xCC8DBA701ADA0806ULL, 0xE909725D82719619ULL, 0x206B933B9FA7EF42ULL, 0xCDC32D59F945F87CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseCConstants = {
    0xEEF3203318B2A5BEULL,
    0x07B3A4521376208FULL,
    0x8D1E247DCB35EFDFULL,
    0xEEF3203318B2A5BEULL,
    0x07B3A4521376208FULL,
    0x8D1E247DCB35EFDFULL,
    0x03CFE0F383CD1109ULL,
    0xC76959F8F66780F4ULL,
    0x94,
    0x4D,
    0x24,
    0x06,
    0x7F,
    0x7E,
    0xEB,
    0x26
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseDSalts = {
    {
        {
            0x313BF5DD14857EBCULL, 0x787F414306D5A77AULL, 0xFBBD45E4456BC60EULL, 0x99DB9BD4AA740BA4ULL, 
            0xCEFA1D2C74D40CBAULL, 0x3D9B3E3696A4A751ULL, 0x034EAA18C3042571ULL, 0x37C06956EC145144ULL, 
            0x3D90CF3F7A6234A4ULL, 0x17EC7B33927E10EAULL, 0x9765F557EB5FF767ULL, 0x9A148C250D962EC1ULL, 
            0x69CEF3588A8978A4ULL, 0x3FC5B23EAE3EFF75ULL, 0x43DBB171D38AA141ULL, 0x1F521DD1DBA6B629ULL, 
            0x3E1D3DBDF7486911ULL, 0xC65894CCEC3EE3C6ULL, 0x75EC593B09CB3FADULL, 0xEA18C205046ED0A4ULL, 
            0x39D01BB460E458CBULL, 0x354CFE284864E84AULL, 0x2A511F4D795B53C2ULL, 0xD6B4513C2745B1FDULL, 
            0xCD9A948ECCDBEDDCULL, 0x7CD9AF57EBEC1046ULL, 0x4B63C415E0762971ULL, 0xE084FFF3B8784966ULL, 
            0xBCBF18CAE89A5B01ULL, 0xB8A8E1B8BB9D5414ULL, 0x9009F7898FAF6BE3ULL, 0xE1664599A00810FBULL
        },
        {
            0x5D9C8717C372F169ULL, 0x881B04BD75FDD290ULL, 0x8BAB71E41F0F7A11ULL, 0x14A4AC42AA00CFBBULL, 
            0x222BE4114CA6748BULL, 0xA5BDA2824AE879A2ULL, 0x7076405616AA8476ULL, 0x37461BCC1BA836F9ULL, 
            0xCF74A2DE7CCD35B4ULL, 0x00E22AE820981358ULL, 0x01E04B1F9E7641A9ULL, 0x8CCBEE2D6FAC17CCULL, 
            0x4A7AD1941F860977ULL, 0x43A5FE55A54C6237ULL, 0xAA34DC5854EA39AFULL, 0x55E9992D7E0AE934ULL, 
            0x257B3755954F61EFULL, 0x84B4D8B3A11D56E1ULL, 0x52A170F8882909EAULL, 0xF7C834BE5EFEC127ULL, 
            0x5760020BBC7A99BCULL, 0x0BD50BB5593F4642ULL, 0xBD3CA70DEE8D5C73ULL, 0xED818C815567E193ULL, 
            0x50ED28A920EFC5C0ULL, 0x4ED6EED6863AA177ULL, 0x97AE63277E1D82EFULL, 0x1CFC2D6E67697869ULL, 
            0xE9E8CF0DC65CE7B2ULL, 0xC896F89D97B8AE03ULL, 0x957ECF8BEB83FF79ULL, 0x0D71B9EADAA46894ULL
        },
        {
            0x25AC5233DAB0C206ULL, 0x46FA082D56F5EC7AULL, 0x73AEA25FD6BC9EDDULL, 0xECB28569105198C6ULL, 
            0x6D148ADD105334F6ULL, 0x522EEB400F63BE6BULL, 0xBDA04741E29937D5ULL, 0xB2A2E8824E5E8FC5ULL, 
            0x74BE5C769F62053AULL, 0xC614DAFE994EDE5DULL, 0x37EBEA37B1785678ULL, 0xCB5EFFBA84A46D87ULL, 
            0xD25FBAE3B2CBF485ULL, 0xB8A5B6878DF8C63DULL, 0x2E963E6E2796B1A5ULL, 0x030D0349AC8E765CULL, 
            0x068360ABFFD48B8BULL, 0xA2AE7E0DA5EC6428ULL, 0x70B5AB9012129CB2ULL, 0xDDA13701FC1A895BULL, 
            0xEB99DB29840418F4ULL, 0xA536D0BE7EC0D4AEULL, 0x4BFBCAD208C63B62ULL, 0x60C78AE6C8CD881FULL, 
            0x57D6482F2326C753ULL, 0x3869BD26D4EE31A4ULL, 0x5D56900DB6A5925DULL, 0xAE26CCB42E31DB00ULL, 
            0xB562F097045C2719ULL, 0xB14BC9C9DAF950C1ULL, 0x37328A6AEB2F2436ULL, 0x6ACE195BB114B2C1ULL
        },
        {
            0x2F13A9C06E1AC711ULL, 0xA9E3D20ACDEAB49FULL, 0x9125FC8C2DE5B33FULL, 0xC36BEB38CD9F766FULL, 
            0x8730C38E8C9D80E5ULL, 0x14084E158DF0A7F3ULL, 0xDC81EBB0F3BA4B95ULL, 0x6857631BDF51A413ULL, 
            0x8CBCCDD9F89FFBEBULL, 0xF3F68D3A239D8178ULL, 0x40A5B3E81660304DULL, 0x99581176AC02BB3BULL, 
            0xD259FD2CAB2D9B9BULL, 0x0C4340D9859A69FAULL, 0x0126B1850D11DD57ULL, 0xD7A8AB68E6FFB632ULL, 
            0x4673C1DF74BD7FE2ULL, 0x9B16DE688B881138ULL, 0x9C3D12AD4A4D8566ULL, 0x64511C01DBC15A31ULL, 
            0x8AB4B2B8873259A3ULL, 0xCC14A41B1D0B0E75ULL, 0xD08806BE5C0A622BULL, 0xD285A21E3DF015ABULL, 
            0x5DD275B416F50295ULL, 0x8810076316032FC4ULL, 0x479FFAE02C49F300ULL, 0xEF16BDE38F3873EEULL, 
            0x47FBA512FC103998ULL, 0x0C15B48AAD6095F3ULL, 0x68A114E4EE068DC4ULL, 0xC8082CA1B332F628ULL
        },
        {
            0x421ED1B0268E8889ULL, 0xF5AEFF73AE79D591ULL, 0x125C29F965F6356BULL, 0xBE28692131CC86ABULL, 
            0x11F2D8E3D695D050ULL, 0xE7D7486033505009ULL, 0xB781E20564526FACULL, 0xB081848C516E8FE1ULL, 
            0x91E7221197AD6E7AULL, 0x341FE2B234579FA2ULL, 0x5509F89A8EEFC929ULL, 0x27327768F7DC04C2ULL, 
            0xDEEB7F23BFA6CDE4ULL, 0x6A401BA75FF315BFULL, 0x258F6441D28C6CD7ULL, 0x9D6B21B3F8AB45DAULL, 
            0xEDEA72C3A89704A2ULL, 0xF812D5B0061E60BAULL, 0x402D7CC74683A066ULL, 0x2E549FA1D2E56139ULL, 
            0xC78950AB72191115ULL, 0x230AE980C45515D9ULL, 0xBD020C2414066890ULL, 0x9D03CCEA49C008DDULL, 
            0x7DCB673CAE3C0DBFULL, 0x08652F74493A32D7ULL, 0x0926D7D7040088CBULL, 0xF661CD8870EC0595ULL, 
            0x2B4C6A82CB727684ULL, 0x1F789C22C026AD1FULL, 0x7A3F3564C9013349ULL, 0xFC6534F7C92098F9ULL
        },
        {
            0x50E66A364B37424DULL, 0x53F0204A15DB805BULL, 0xB97ECFB554A2B9AEULL, 0x86E5DF011E858C5EULL, 
            0xAA3FDA7BA2A34BEAULL, 0x5FE29143A1F03B72ULL, 0x1EA5490D98603049ULL, 0x8B70C70162E7487BULL, 
            0x7CADD5B146AC3F0FULL, 0x1ADA1FCA05DEF422ULL, 0xBA5EA1EEDFBCBE2EULL, 0xD6A9AFF5C4307D0CULL, 
            0xBB1579C2678E36B2ULL, 0xB53E25E57E40C225ULL, 0xBD4004437C64288CULL, 0xF9E0CC49443808E8ULL, 
            0xEEFF13C463F9E768ULL, 0xB35CA3A23EF47BC6ULL, 0xA3DBCE2AD89E07BFULL, 0x57400E018DB610D4ULL, 
            0xC23C07948848297EULL, 0x2641E55CCB1C6C4EULL, 0x1CC4BF7B696772FDULL, 0xE6890ED436DEB4F7ULL, 
            0x69807C01B542774BULL, 0x11EC5FAAF9ABFC2DULL, 0xB0CAB6CDE3E5A09EULL, 0xF8E41FFA33CCF369ULL, 
            0x3C385E6941EC923DULL, 0xD4FA9BB3DB2EB57FULL, 0xC49D79B4FE5946C5ULL, 0x4F8D12CA0751050FULL
        }
    },
    {
        {
            0x2F9AE1F58B8E16ABULL, 0x6EFE5FC11125D50EULL, 0xDB8CDFC37AEAC1B7ULL, 0x01616CA5B78CAF26ULL, 
            0xEE877B6187D9A03CULL, 0x776CCC662DF75E2CULL, 0xDC6691D63246DCC3ULL, 0x9DCE1D8A56AEE29FULL, 
            0x9495C2C6FEB2C6F5ULL, 0xB3D968193B318441ULL, 0xB95865D7E52DD4ABULL, 0x58230E109ACBDD21ULL, 
            0x963D5500E180BEC8ULL, 0xDC457F66EB920927ULL, 0x9BD13E5B7C5C0968ULL, 0x5E2ABFA92C186AB6ULL, 
            0xB55D0A0069BEF12CULL, 0x1A04A4D04B37AB81ULL, 0xE07C672FC68B3975ULL, 0x0DCF3EC8C490235FULL, 
            0x5C3CD92AE5869851ULL, 0xBAB71CD1CF8340ECULL, 0x3087B31148C2D94AULL, 0x171CEEC841EDD0C0ULL, 
            0x6AC76F4A12EF3E9FULL, 0xED984B2F0BF72E9DULL, 0x2214935111BDB4BCULL, 0x1A259692D1B0AB1BULL, 
            0xB405712F4350FCCCULL, 0x04AF61F46090A8D1ULL, 0xC85741E7262AFD9AULL, 0x21283CE880F507ECULL
        },
        {
            0x579C0351B5FDE2E1ULL, 0x1BF5331DA1C6EEA7ULL, 0xA17E1B0111D6B8BDULL, 0x24324071646ADD92ULL, 
            0xA903BE81AB5B270FULL, 0xDA618C0020C865ACULL, 0x0A93034DAA585D75ULL, 0xE29AAA00F9447751ULL, 
            0x5AD5BDC4788231C9ULL, 0x7FAEB9F81EA6FF1DULL, 0xE743CB8AA44D2050ULL, 0x5B3EC314FC2A4EAAULL, 
            0x694AD518D6DAF9E2ULL, 0x08E84C09FCFDD330ULL, 0x841FBD0F3DA0FAD3ULL, 0x87CDB025FB3562A9ULL, 
            0xB47BBC38FA724A88ULL, 0xF69CBA721DA6B501ULL, 0x032187CF288813BCULL, 0x38D2F80F83D02AC9ULL, 
            0x6B695D420B120BB9ULL, 0xBB69778AF987C75BULL, 0x11F06E22745815FDULL, 0xD1BD28749CAF8281ULL, 
            0xD00C89D804A36A47ULL, 0x91F9F06C450F10CDULL, 0x8970E935BDB7E2B4ULL, 0xDDA2BFB8FD585399ULL, 
            0x52B8EDF22928F14EULL, 0x9102FB07ACD5A1AAULL, 0x675CB4D926893726ULL, 0x5A25AD9D7A191D6BULL
        },
        {
            0xC17828685EF9BEBEULL, 0x73ABD332925D9A3AULL, 0x7177637AE53A0344ULL, 0x08C9EADD24C0D366ULL, 
            0xE9C2DCF90E279BCEULL, 0x6BAC7B11D1EEC7ACULL, 0xEF2A678C0A56F8DEULL, 0xCD6F650EF522846CULL, 
            0xB8CE33512633583CULL, 0x4C9603A99C989268ULL, 0x13502FC150BB070CULL, 0x71C5CE1CC81912E4ULL, 
            0xD0B40C98A4428F8AULL, 0xC5321B0FBBA68744ULL, 0xF0F261C8E1C6BCBFULL, 0x57E7D1A5AED9A2DCULL, 
            0x1EB6969BD0DBE2DFULL, 0x6530FA848AFD4B76ULL, 0x397311596DEEE79EULL, 0xE230AE50D7325E44ULL, 
            0x8233A6EF874F9B50ULL, 0xB0961888DED148C9ULL, 0x26DF588DC1274C70ULL, 0x6990208527CC89E1ULL, 
            0xF5207120E0BA5DF2ULL, 0xC1B36DD0891346B0ULL, 0x33D1B5D412D5FDD1ULL, 0xECE9D9211288927EULL, 
            0xC21D8351B647E41CULL, 0x327436B1578D24ABULL, 0x6DA5B885F20D0DEAULL, 0xF8A8F682CFD46C08ULL
        },
        {
            0x4F8F25D8ECB14509ULL, 0x707311EE20D636D1ULL, 0xB0E18E83B3A73C28ULL, 0x712F97942DB28F5FULL, 
            0x093A979C1CD1C3DFULL, 0xBD8C1E59F45A9BF4ULL, 0x992B0302E1931EF3ULL, 0x50458A524E6AF30AULL, 
            0x462A0A3C40274981ULL, 0xEF8B17E00C15C524ULL, 0x57EADC75E65DE1D5ULL, 0x3DB78BFB87494E42ULL, 
            0x2363510EACFB1E16ULL, 0xCAD94115217763A4ULL, 0xE1BD0FF7E3FA20E2ULL, 0x9FA470A6E354246CULL, 
            0x17953D8CE6582942ULL, 0x1C2F9747B1FCB1E4ULL, 0xED8702BC6523ED32ULL, 0xC59405001597473CULL, 
            0xEF3833BB12F73C83ULL, 0xF0544CFFBCA0535CULL, 0xFB98EE5AE4543C41ULL, 0x1A410263F70B2E5CULL, 
            0xD268D8CD69478BD7ULL, 0x285D7E31057A5978ULL, 0xBBAAEBCDC4599755ULL, 0x85C568E4BAF0A29CULL, 
            0x214C2F6A4ED2D773ULL, 0x5A28F598C9605E4EULL, 0x8F59AF201FC857BDULL, 0x5761B1F8589C2289ULL
        },
        {
            0x5596B3616C7A759BULL, 0xE345110ADF6563BDULL, 0xB34A77EEB9AFCB34ULL, 0xC533ADAF0F567319ULL, 
            0x63B9CBE403EED37DULL, 0x04772C53B54DF8FFULL, 0x351163CD6702F243ULL, 0x24039FC206C82E43ULL, 
            0xCDE8E20DF439CAD2ULL, 0xE0D3D04D0864C88DULL, 0xABFE76080264DC43ULL, 0xC2F2EB65BBCC2C29ULL, 
            0xD5941A3A0B6E710AULL, 0xB7B228473B475FA8ULL, 0x2C435C11A4D18C60ULL, 0x81BA62EBDF1A5A1BULL, 
            0x00107437710335CFULL, 0x73420C6EB56ED6E6ULL, 0x63664023AF600C57ULL, 0x75861639F67971CFULL, 
            0x1A046B28FC2D6BC7ULL, 0x9CD1F82CFD854828ULL, 0x030A2335441AE4ADULL, 0xDB6DA5585CDB78C5ULL, 
            0xC3C127A0E701DB36ULL, 0xFCDC2FF088F99CCDULL, 0x8A01EB8DD62D522FULL, 0x0057A5A8486316DBULL, 
            0xC920AAB63DA4D046ULL, 0x89BAD5CE509DBDF3ULL, 0xD75D8913AC9D2462ULL, 0xEC4F111D8E9B7697ULL
        },
        {
            0x9D008D63CC7FB678ULL, 0xA7E984CA3033FADEULL, 0x0F125E5DDAB3BF04ULL, 0xFF05523933BE05AFULL, 
            0x7F4FC3498786C07CULL, 0xF92C4641EF5F58A1ULL, 0x35C2C4B70779AFA7ULL, 0x756516E9A5051B7BULL, 
            0x2CEA20882198E941ULL, 0xE76ABABFE5955197ULL, 0xF403028EB032DBB8ULL, 0x5E3F193DFD62DD2AULL, 
            0xCE8D1339E509BA5BULL, 0xD9BD9D4461FF8B62ULL, 0x39852C9DC026A9CAULL, 0xBEB97FAF635617B2ULL, 
            0x4D85AFA4F890B9E6ULL, 0x1E9E8B23F0666483ULL, 0xBE870528EAFEE38FULL, 0x2D5BD75ED06751BFULL, 
            0x9F18E0317830817FULL, 0x669D3750E4E6BF31ULL, 0x9AAB04F4A54B606BULL, 0x4F77E3D1A69320C0ULL, 
            0x24647614D0DC30A3ULL, 0x2A8E182D0DC6FB53ULL, 0x767332A777978498ULL, 0xF6F30756C9BFEE73ULL, 
            0x04871B160E5D318AULL, 0x17AA558ED5669294ULL, 0xEBE68D9CEE8361BDULL, 0x9E87CD87ACCBACE6ULL
        }
    },
    {
        {
            0xC1B0BDF37FE2CCF5ULL, 0x896854EF90695EF4ULL, 0xC6DBF5CA4C3330DFULL, 0xE006B3B9DF230C24ULL, 
            0x19B9F4530541D59AULL, 0xBE3B4BDF07CB1492ULL, 0xE461E79276734133ULL, 0x72E641EFA79EA0DFULL, 
            0xF72378CFF3FC8126ULL, 0xF341EB6529709AAEULL, 0xCEB490A7267EF001ULL, 0x26771861E29FA799ULL, 
            0x0BFF9A708A1775EFULL, 0x1180CE6F34A6AE4AULL, 0xC32776864BF5DD2CULL, 0xD284B64487AFC187ULL, 
            0xD4A88D033C26572FULL, 0xB4F7719B360EA9B6ULL, 0x2032E4F49EFD3435ULL, 0xF24F982DBABAF6FFULL, 
            0x227698483506280AULL, 0x029C7C05D5C53C96ULL, 0x909F7417892177EDULL, 0xAC6EA579840E582AULL, 
            0x87FFC022FCA51672ULL, 0xA84C07D917374D47ULL, 0xA0DF3E31B09DB40AULL, 0x07B68543A73E8349ULL, 
            0x253C7702B09444F5ULL, 0x00A1F746CA6728E4ULL, 0x71E4B91A1D803CE7ULL, 0x29CF3233E5AF79B3ULL
        },
        {
            0x9DF34508FEDEBC1DULL, 0xD422AF03CA950CD3ULL, 0xD9CEAA9437E7EE4BULL, 0x883F55A6D80CB86AULL, 
            0x4DE17ADE8D572C5BULL, 0xE153EC926B0CFC54ULL, 0x78FEBA548FAC736DULL, 0x7CCAA9BDB15665B5ULL, 
            0x362FB5C752117393ULL, 0x9105D73EC183F842ULL, 0xE216B1ACEAC7580CULL, 0x2F84153B12FEA808ULL, 
            0x52FFBD4E98CD39EDULL, 0x84BC5E3D48206CBFULL, 0x79AC1CD5443B23E9ULL, 0x1ECF982F1A29706DULL, 
            0xFB402D9A054DB8FBULL, 0xC9C91743379CF4F7ULL, 0x45B3F67B90059CB7ULL, 0xC2449E4F686911CEULL, 
            0x8FCD1D8AC65C4E0CULL, 0x3B1F45C34E4AAE3CULL, 0xBD9F48D3FE69BA4AULL, 0xA71FFE5E001590F4ULL, 
            0x264EF271C9B5D582ULL, 0x1FED92C1D28E8C2DULL, 0x8E05D07F54F9B117ULL, 0xA1F9B9C737A6BCD0ULL, 
            0x8077C51BD99D2075ULL, 0x404C88FA1FA8FA32ULL, 0xD874DB9C2F86FE83ULL, 0xCD09999039EDE49DULL
        },
        {
            0xFCAC9056A9789F6EULL, 0x38D78C6EAE6859FAULL, 0x7F450FDC33736F99ULL, 0xE739A11CE98D9F70ULL, 
            0x463B631D44EE7337ULL, 0xAB0B7922DB2AAE0EULL, 0xAE0C389AFAF3AD9FULL, 0x432ED97C03FE568AULL, 
            0xDAC53F6BA63E7B7FULL, 0xE3303F1A25BE9278ULL, 0xF1319C2AC15C87E8ULL, 0x52C9088F2089DED7ULL, 
            0xE7676F227F3D2453ULL, 0xE7AE849496A59F84ULL, 0x974E3C266507F1ADULL, 0x15C034B429D700FAULL, 
            0xEECC4FB34F9FEF69ULL, 0x933353A78E5021D8ULL, 0x30F8088615CF2C5EULL, 0xE4827D3BA5E2FDA3ULL, 
            0x8304F23FF693DFBCULL, 0xCB067C60B9EC9531ULL, 0x217ACC9951F060E1ULL, 0x2942AEE1DED46D3CULL, 
            0xA678E89EE8D7625AULL, 0xA8F615D0B35FF81BULL, 0xC783C227E08CFD51ULL, 0x159F81C88D80DD73ULL, 
            0xCC0FE1830CAD8EFFULL, 0x24E561A07FD0A9FEULL, 0x5A11326E8E82043EULL, 0x982FBB7883D11C3BULL
        },
        {
            0xA2244627407CF30CULL, 0x25E4F7A4015B5C95ULL, 0xAC64ED3BB92B562BULL, 0xCB25FA97A24693F8ULL, 
            0xCC6DFB77B0E72969ULL, 0xF348E598F3D499D8ULL, 0x62A4F4B14190C023ULL, 0x5909D9F1870983A9ULL, 
            0xDAB4AD9EC002FDA0ULL, 0xAD8099158BD57FABULL, 0x522CC698B0586E15ULL, 0x8AA57EE36D9C829CULL, 
            0x5129FCA306F003EEULL, 0x6CDC83B4FE2845CDULL, 0x49B1D6507D3025CDULL, 0x537A2A0838017D64ULL, 
            0x405229187F16F712ULL, 0x035DC2FC744B481BULL, 0x791102D02ABF2D8EULL, 0x396C27C2A46C54C6ULL, 
            0x66A65AC65B3AA573ULL, 0xA929A2700FE818A8ULL, 0xE0A24566B90B7720ULL, 0x86B02510ABD85721ULL, 
            0xC68E5D6AC82A784FULL, 0x52FFDC88A9C7C531ULL, 0x461CEC318E333C3EULL, 0x6F304F72A693DC62ULL, 
            0x5E3B3F69F4094C68ULL, 0x42EC880FC395D127ULL, 0xE62255F7E1DBBC33ULL, 0x5A8DAB8D90230B3FULL
        },
        {
            0x387699C8035F4027ULL, 0xB10132BF54ACBFB4ULL, 0x2919C101CA192D05ULL, 0xC75DC4D0838BBAC6ULL, 
            0x75618255BC32F560ULL, 0x4B5D314D5653A11AULL, 0xB170D4FBA49DBF06ULL, 0x18FE0AD6EF2AC066ULL, 
            0x2B84524D838FE4B8ULL, 0xFC0AF4D44C6F2464ULL, 0x4A567F01CA3CCF10ULL, 0x48CC9DD95757939AULL, 
            0x2F760A265158E04BULL, 0x094DA20DEE94D887ULL, 0x7960F2359C205684ULL, 0xE31A3605CBA5BD11ULL, 
            0xCDA79DFB7461F625ULL, 0x928DD32BB6A5DA86ULL, 0x0A3A0914D82E898BULL, 0x82381EBDF2DB6E88ULL, 
            0x0C368498394D5394ULL, 0x62AAE109AF2B64BCULL, 0x6FFE04B23E38EF47ULL, 0x1F82067150009587ULL, 
            0x0EBD2BFC0B7E3F0DULL, 0xFE8070A94A76A506ULL, 0x059B71659463F2BBULL, 0x39917561F8D5F590ULL, 
            0x6A4264E06E69340DULL, 0x4D44D8FDCC55BF43ULL, 0x35778940D8264EA1ULL, 0x0B785DFDE6F26047ULL
        },
        {
            0xFCB42A9B1414C591ULL, 0x264C4332976F4375ULL, 0x2177C590F987F4B6ULL, 0x000BEB2A99D0881DULL, 
            0x264B29B2AB33F5DDULL, 0xE422489B9D120762ULL, 0x2CF927152C1A8B5AULL, 0xAA28C3FDB8D1D812ULL, 
            0x15824DF25BF6D5CFULL, 0x2724412C14D73186ULL, 0x50F1842D291EA5C2ULL, 0xB50B717BB6A5527CULL, 
            0xA8ADFF82F1111183ULL, 0x69C17B91A540FB90ULL, 0x36956C6A202173EAULL, 0x6343276D3E8FA64EULL, 
            0x3B92865BC8997C8FULL, 0x43EB1184C50D596AULL, 0x8BE3F7C1FEE01AB0ULL, 0xDBE1BDABAF011CFAULL, 
            0x9A7D63B33935B49DULL, 0xD10335AE50565FA4ULL, 0xC85B10AB40B1AF1BULL, 0xC21E9DCAEF805371ULL, 
            0x95631AD1A66254ABULL, 0x4E8A37A956D6CCDDULL, 0x64827A29E1FD99A0ULL, 0x31F1D629BD01D46DULL, 
            0x6F864E912ABA289AULL, 0xC02C53F27851BAFEULL, 0xAF4E7EB1C359D821ULL, 0x3BE9A2C80D5AC47AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseDConstants = {
    0xD091EC15F1194B1CULL,
    0x794D5CB4FA91E09BULL,
    0xBB007434DEB54022ULL,
    0xD091EC15F1194B1CULL,
    0x794D5CB4FA91E09BULL,
    0xBB007434DEB54022ULL,
    0xD612B5A764EE807DULL,
    0xD5B4FC0456A4B466ULL,
    0x58,
    0x06,
    0x8A,
    0xBE,
    0x59,
    0xFF,
    0x39,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseESalts = {
    {
        {
            0xE66C5B746BABF67FULL, 0x3EAD03891D580B05ULL, 0xA816E28943614277ULL, 0x2487655405E7B213ULL, 
            0xC18592DD3ED64F14ULL, 0x0AF975745F77464BULL, 0x018831C662DE0396ULL, 0xC50AEB139592E8BCULL, 
            0x7390CEDDC6B4B0D3ULL, 0x42698A896A29C2D8ULL, 0xD17C0823767F7BAFULL, 0x9692732D307AFC65ULL, 
            0x779283FAB6F6B5BDULL, 0x076B44010CD6346BULL, 0x8970DB8F05249E93ULL, 0x7D7E7951281A07D4ULL, 
            0xDB0CCF20F7D32E8EULL, 0x581C83C03657AA66ULL, 0xAC8FD075D5425A7FULL, 0x03C4B84A092B3CC4ULL, 
            0x08375EB741C9E3F5ULL, 0xF7395CF34B4B4A31ULL, 0x28179C30932FA218ULL, 0x214BFBA039218D1EULL, 
            0x5DBC306D18215E93ULL, 0xC5539F6847C28C0CULL, 0xD689557629F6854EULL, 0xB382EA71F32902B9ULL, 
            0x68F6ABAE02B2A310ULL, 0x3F336DBF18D45F8CULL, 0xCD6E71CD65C5FA94ULL, 0xAE9AC5E68D2C9F40ULL
        },
        {
            0x5245ACAA70ADA595ULL, 0x312818B42101E210ULL, 0x01FB692C6EED5D5DULL, 0x69C5437E598203D0ULL, 
            0x1F3CE69162495D32ULL, 0x12A87D6BC923F2B8ULL, 0xBC0552E474F13BD4ULL, 0xEBA614BC86E2FD1DULL, 
            0x817DE2F64FF1DE4EULL, 0x2D827BCBD424FF1AULL, 0xC8DB70445FA0A338ULL, 0x49C0972CD5911239ULL, 
            0xAD1D66BE9BBF84E0ULL, 0x324A18E657C0DDD8ULL, 0xF959C78FD2E6D07DULL, 0xF811169B08D35ABCULL, 
            0x35F99EB47C6BA649ULL, 0xBB0377C50E766C14ULL, 0xDA24C4BA33A0380CULL, 0xAE412E34C8A90EF9ULL, 
            0xA0B968B408E6532AULL, 0xF0C97AD99811A8DEULL, 0x477C1648B3BBA507ULL, 0x6415F0CC96D5DB45ULL, 
            0x0423564C065C268AULL, 0xE49B504CCBEC6633ULL, 0xB9ABB38DA40404BFULL, 0xE3D6BE99A01BD620ULL, 
            0x293B5E72192EDB86ULL, 0xD2C92A487C2B3D6BULL, 0x6D731912D346C8C5ULL, 0x32BACFB39FC72645ULL
        },
        {
            0x088A796DD9CDA527ULL, 0x0C805F2F0BBA6E61ULL, 0xE633E56D6E706E09ULL, 0xB0DFA750A034306DULL, 
            0xF12A3400BE087C9BULL, 0xAD7D39C245034A58ULL, 0x03EF167470215151ULL, 0x1E9760665CBDB0ACULL, 
            0xD38027A7B0F2A9D7ULL, 0xCB8398E33FA3CF97ULL, 0x62CFE670240EC668ULL, 0x4CE18C21A655574FULL, 
            0x63E20D482F334F4EULL, 0xEC0C7EA1C42D84CFULL, 0xCCD71FB922670C57ULL, 0xC2BE7A1CF207BDEBULL, 
            0x2D713FAAF54FDCDCULL, 0xDAA86E0140DA6B05ULL, 0x88669731C8BC84DAULL, 0xDB236F04FE3AF2A7ULL, 
            0xEBA1B7B3F0268EBEULL, 0xAFA4F22F68C56707ULL, 0xB9BCFB3F23A65A75ULL, 0x55358FA7AF347A41ULL, 
            0x45665BA3BE4F0416ULL, 0x5F9D75DA31E84C24ULL, 0x72D16466D1B4A899ULL, 0x4B8BDA438CC719DFULL, 
            0x99B0FA1672F31D2EULL, 0xA81A920391552968ULL, 0x7648719580AD7342ULL, 0xE7B885588C54F983ULL
        },
        {
            0xC0C9D3F034609077ULL, 0xDD40E8EA416564F5ULL, 0xBA7FF6E6B5872613ULL, 0x49BFF23E8ECB01C6ULL, 
            0xF15500FE9304F674ULL, 0xE1E9153DA15FE37BULL, 0xD2600F39B90D5521ULL, 0x95B654BBF7D4C812ULL, 
            0xC8712438EF4F9383ULL, 0xD87A80BCB71DDEB8ULL, 0x80EB4013DD44E16FULL, 0xB4017E3FE82DBFCDULL, 
            0x890E227D20515851ULL, 0x5A716D7E2D64FCB6ULL, 0xA7ADAD8FD2A665DCULL, 0xBB0A60AF0A3F2BEFULL, 
            0xBAF505E30929C733ULL, 0xC3C6FE549C61730BULL, 0xF05EB66C06FF2E86ULL, 0x22C376C18F5C3F99ULL, 
            0x804B159EB5BF7C54ULL, 0xB9418E06ECCAEF41ULL, 0x4AEAB326338E49E7ULL, 0x18164A3248CC8908ULL, 
            0x0324E3F5FCC661CEULL, 0x20660EAE9E01F85AULL, 0xDCBC28F074FC0721ULL, 0xFBF820B59D49EEC0ULL, 
            0x39AD45384D26A9EFULL, 0xF876F662FF6BAB39ULL, 0xDF4CD85A609B55FAULL, 0xBAA0EEF196A3B5C6ULL
        },
        {
            0x64F3EA325A7B1558ULL, 0x4E66C9220D43B21BULL, 0xB5FA383B38E16BC3ULL, 0x2A6CE5B0709C5E07ULL, 
            0xD859A8139BA5FAFCULL, 0x9CF6B8293E3226C0ULL, 0x6591CF5E2ECED396ULL, 0x68494EC2733E0C74ULL, 
            0x3D68D74932D7F010ULL, 0x0564B7E4854FC948ULL, 0x5D16D03E6963E72AULL, 0x56C81C3C76CE870CULL, 
            0x11CF56EC56337B61ULL, 0x871566F1CE5120F8ULL, 0xB0CED3FDA1AF14EEULL, 0xF9E47F64B4A4F14EULL, 
            0xD13ABE4E031378D4ULL, 0x65E32D01C99F3099ULL, 0xEBF56C233CD027D1ULL, 0xFBC87A802BF76BA5ULL, 
            0x50761BBE718A5676ULL, 0x26A40C470789FEE8ULL, 0x4E96EFE4D4347BDEULL, 0x5B662847E30DE4A1ULL, 
            0x1792C508F0EDA6DBULL, 0x52709D93543D2F1CULL, 0x0846F1ABF36572E6ULL, 0x73FBE6E954581239ULL, 
            0x9C1E16FB8A3E88EAULL, 0x943DF61F456CC217ULL, 0x11831C9BA8AF85AEULL, 0x75E08D8AC5671236ULL
        },
        {
            0x1CB90FB01D1F326BULL, 0xC7EC1169C1499450ULL, 0x99FE97A8D554775DULL, 0x489AC7FFD2337EAAULL, 
            0x286F30DD3BE3FF1CULL, 0xC075131EC994A74EULL, 0x44B45B74A348377FULL, 0xB3F05019946C567FULL, 
            0x8C54D23D6C7C652DULL, 0x95DB94C08C729ABAULL, 0x0F9DB6A326B5E0C7ULL, 0x7902866ECE5042D7ULL, 
            0x67727D466D89C55BULL, 0x27D793CB3FC2D293ULL, 0xD9806FD774FE5CE0ULL, 0x3382997DBBF8A16EULL, 
            0x7021B87C2BB32E3CULL, 0x04AA2B2BAD58EA1EULL, 0x7EB1A3A4DB465D1AULL, 0xD1766F4E639DCACDULL, 
            0xD67699BFEB78BEB6ULL, 0x0B2D82A447D8A59BULL, 0xAB8D7CF5437770ADULL, 0x29A79C6159E62C69ULL, 
            0x82EE226D961635C9ULL, 0x2DED3838E8F89397ULL, 0xE375C97822FCD8FBULL, 0x5BC188A46F5AB1F0ULL, 
            0x55C6DA100B558E09ULL, 0xC75D15C4E78E5CECULL, 0x43CDB0FB8BAB21AFULL, 0x2404968BAD9B9221ULL
        }
    },
    {
        {
            0xE75C845236FC44C9ULL, 0xD2D187F49178187DULL, 0xD25FCF11B1CC58B5ULL, 0x7AD6774227DD0D8CULL, 
            0xD017825F886A26FAULL, 0x2059B645B0791324ULL, 0xFC9E81A835108E93ULL, 0x96E52ECFA6B5314AULL, 
            0xF6176EC8F956CE4AULL, 0x29997F50DDC6AA3DULL, 0x48C4463094CA6F51ULL, 0x901C17694BF49631ULL, 
            0x17E309339EACAC27ULL, 0xE5C666F128D99D5BULL, 0x4970D25D12E359A4ULL, 0x49125175B826D4C5ULL, 
            0xF2659C307D09676DULL, 0xC84297116D54C807ULL, 0x3B04CBF6BDA49311ULL, 0x03C739A1D8DE0631ULL, 
            0x77777FF17CF84387ULL, 0x1080262A47E10147ULL, 0x536B5BF4144079E5ULL, 0x152DAD8022E2DCD5ULL, 
            0x86A035D1FD8BC5B5ULL, 0x8BA54C430B88A890ULL, 0x8FF2CCA3E69B5BD8ULL, 0x316036E82971B0C3ULL, 
            0xC6F55BDCD37C8755ULL, 0x005BC4DF031BD306ULL, 0x3420E6C2334E9F4EULL, 0x059B9F05BA21FA87ULL
        },
        {
            0xD0EFD8A09598F907ULL, 0x1BDF4793E452F55DULL, 0x37BB8C31ADA594A0ULL, 0xFB83D15D8DAD9D9BULL, 
            0xD97813D83F20242FULL, 0x62D4C2DF97A300AFULL, 0xB6861460A86612A4ULL, 0x3E15B8C7C61F32CAULL, 
            0xA8250AEF063FF2ABULL, 0xC5C0C15DEDEA488EULL, 0x28EF738B2ADEA870ULL, 0x6674CD9364C5B14CULL, 
            0x0429822A417DEC48ULL, 0xD55EFA2BCE16695EULL, 0xB4356BE7B00AB714ULL, 0x5839CE7FBFF7F9EEULL, 
            0x17B946B97AC75297ULL, 0xB0C73C639E1B610EULL, 0x5B5665233DBB120EULL, 0xBCC79CA04C49908AULL, 
            0x935FEB03FB503383ULL, 0x1E2C858E9F47BF3DULL, 0xEB192BE64CD71199ULL, 0xDA711AB596584E84ULL, 
            0xC87C275C3898DDBAULL, 0x118FAC6D392FE661ULL, 0x0BC4BE13A1DCB544ULL, 0xB8638A9DD9745BA3ULL, 
            0xAF00DF5566C3D616ULL, 0x4F0DCB72CCA32B91ULL, 0xD4CBFFDFA44B53DEULL, 0x9D44BD62419F2BC9ULL
        },
        {
            0xC5C8E7F83FF5A1A0ULL, 0x3CDF14041BE52BAEULL, 0x6ADB79B3564834C4ULL, 0x33CEC9C49844AA42ULL, 
            0x082730FAB9CF0E1EULL, 0xC55B013F6C99D220ULL, 0x9723B3F1263D1847ULL, 0xC37C74D7A39AD3A2ULL, 
            0x07EFA2CBADAF708FULL, 0x9C738D704013F9ADULL, 0x51FB301AC7ACF424ULL, 0x0FEEDF215586A81EULL, 
            0xBAB5DC49A046D3ACULL, 0x5F3BEF671C967A92ULL, 0xCBFF32BC1AACC239ULL, 0xD2ADDB9E39828B2FULL, 
            0xC579CD3EC650605BULL, 0x836B249BD43825D4ULL, 0x147CE7BF71EB6B7AULL, 0x2E63AA0B1BC0416BULL, 
            0x1016E050934227A8ULL, 0xB37C836BC61E9AF0ULL, 0x4439E1BE4AF9FB8DULL, 0xD810EF800E26F249ULL, 
            0xDBCCC61546E9E351ULL, 0xC454B84D3A813985ULL, 0x28EEC70D01907ED3ULL, 0xA50121EA592EFFE4ULL, 
            0x74C11F43FB0F3192ULL, 0xB2E56BF09D3B0953ULL, 0x12B9A75EBF20F804ULL, 0x13ABB10ED212685EULL
        },
        {
            0x4CAFFA1F86FCE32EULL, 0x86628BB44EDA2FB6ULL, 0x34CAA56D0795A926ULL, 0x68E8A334F1585FAAULL, 
            0xF762EA8680144FD7ULL, 0x89F2DE3020A036D8ULL, 0x27610D36A24658B4ULL, 0xB6201B179A716DA7ULL, 
            0xEFCEFCD7B4EC0D1CULL, 0x84ACE55EC63A0E62ULL, 0x3F2621F3537F8BA9ULL, 0x8D30298A9C3BDB22ULL, 
            0xDB60EA26EB92210DULL, 0x11C8F4B814D4F8F3ULL, 0xC21F659FE9CA915AULL, 0xBDD1F4AF0F86588AULL, 
            0xDF0B454AE0242F49ULL, 0xEE83DDD78FB05A7CULL, 0x339C205508213D3FULL, 0x2CDE2A022D725D64ULL, 
            0xF882E3EB273EA21BULL, 0x9FE8474EB08960A7ULL, 0x8F276BD7B7AE158BULL, 0xB1E7B14F63509059ULL, 
            0xCA65C0807E80ADEBULL, 0xA8478CE5C255F505ULL, 0x2C6290089254E7E8ULL, 0xF212BE3A0ECD5153ULL, 
            0xD6AA214674C08024ULL, 0xF15BD6F2A279F69CULL, 0xF5797D2C0F554D84ULL, 0x16E2D9FC536B6548ULL
        },
        {
            0xB905FE230F9BE371ULL, 0xD130A05692246E48ULL, 0x1CAC711FCA6355F6ULL, 0xAA2051494DE0C7FFULL, 
            0x8633E29EFED90A2DULL, 0x67C169F6F304928DULL, 0xBE631E434D3F14E0ULL, 0x298FEBB91193DA67ULL, 
            0xD2E5FB0C3155DCF0ULL, 0xF81FED3ABE16C870ULL, 0x87EB27F1614442B4ULL, 0x02FBAEE5D66DCF5BULL, 
            0x059AAEEE628CAEF0ULL, 0x38CEB50EB964C9C3ULL, 0x39EF962E562CEF3FULL, 0x56BFD51E014FE158ULL, 
            0xBC9FCFF82EA36E25ULL, 0x256C21609B062B96ULL, 0x45AB65468899C192ULL, 0xA06C722D7639A2FEULL, 
            0x85FA5E60B0C4FCA9ULL, 0x54123F214A452ADCULL, 0x1DDEDE7DC0FC1C53ULL, 0x21863AF622778D62ULL, 
            0x0219D7A45C356ADFULL, 0x052E2E13617DF1E6ULL, 0x08DB0CA526C498E6ULL, 0xC00E3645AF0A789FULL, 
            0x13F5558CFDC1F1A7ULL, 0x9B2CDC1A0F64D377ULL, 0xDFDDD52F45A1C18BULL, 0x67DBD38200BC7455ULL
        },
        {
            0x06037374C45C168CULL, 0x89B7A2EFBCFB303FULL, 0x11A3C73AAF758CCFULL, 0x4A8B496C0B952F1AULL, 
            0x5710F1579BFB205CULL, 0x311C4A9175641842ULL, 0x272F72323B83D163ULL, 0xBD8330239606AF9FULL, 
            0x937527EB0C594966ULL, 0x603DA255EA92D206ULL, 0x6818BD8E56198D20ULL, 0x1BBDAF3C015BAB73ULL, 
            0x27DA376CB602B7E2ULL, 0xF9976F8BCC93A3F2ULL, 0x37527DEDCA7D35C4ULL, 0xC3687597AE4C33A4ULL, 
            0x7854A5AB0C1DAEA8ULL, 0x97C2ED06D11EED7EULL, 0x8C36B39701B599DEULL, 0x059B05B5C91173E4ULL, 
            0xCDF39C3F82CB6859ULL, 0x218B1C273325252BULL, 0xB4898318984A276BULL, 0x672DC6B68ED913CAULL, 
            0xC4D926765A6C91C2ULL, 0x39AB2C7D4A0DB820ULL, 0x02B9668B99859A91ULL, 0x608AE8F6B6CE1EE8ULL, 
            0xA6F749049A43A85DULL, 0x90447E75B85D1716ULL, 0x7B2F2D6D28817255ULL, 0xDA4E2CA57ED7B784ULL
        }
    },
    {
        {
            0xCBA53E8CC096EDC3ULL, 0xBB3D4AA69A58B449ULL, 0x950DC0C0678D0C30ULL, 0x465BDF16A47EF46DULL, 
            0x5804961156815F7CULL, 0x1715C7E00E67DC32ULL, 0x9FBDF09C0CE65F69ULL, 0x41D600DEF3FC89E7ULL, 
            0x991029636A562385ULL, 0xFEA177AA1B72B4A3ULL, 0x8B58F3DA28D581A9ULL, 0x85ABB3E5A2EA24A1ULL, 
            0x525B10B34F408013ULL, 0x305B0BA0698BFE7CULL, 0x0F34763BA31992FDULL, 0x09D68DC4F55F1D82ULL, 
            0x5DA6B25F269644CDULL, 0xA7A51A8CF585C6C6ULL, 0xE26FBDD583555248ULL, 0x4ECB1A36AEBF3C0FULL, 
            0xF14720C17C617321ULL, 0xCAA81DEE8CA1125BULL, 0xAA27B20051368D6DULL, 0x8480D33FC71AA45CULL, 
            0xF16C07724A8885FCULL, 0x01475977D25A353DULL, 0xF1B38EB6B865C59FULL, 0xFD3C9380C86DF79AULL, 
            0xB21CCEAB0B96E0FEULL, 0x22C8A088825169D2ULL, 0xAF0875F421C7AE42ULL, 0x6FFE812E97CCAC3EULL
        },
        {
            0xF49BE7C4719D2F8EULL, 0x4C38B45D41557902ULL, 0x67B29E174D355210ULL, 0xE0986E71EECF9637ULL, 
            0x4317D815BE3FFCD9ULL, 0xACAB37D7FA226D74ULL, 0xC79CF0E54482077DULL, 0x39602A1219CB257AULL, 
            0xEDA7E80B02774ABAULL, 0xC1578617F3F2C374ULL, 0xC8A77DF9910E9884ULL, 0x185E951405CD12C4ULL, 
            0x99C809FC4E02D5C2ULL, 0xE1620986A928111FULL, 0xA8734A0D80BF6AABULL, 0x6C8822643E94C0D3ULL, 
            0x4F5C5DD8C1971488ULL, 0x4EFEBA6EC84F2F53ULL, 0x2F87A894CC61B993ULL, 0xE67962648E453854ULL, 
            0x5A77C0DE49711D5FULL, 0x00C73EBB7503AFCBULL, 0xAB4F7AEE2EEB44ABULL, 0xFCE009F7EADB8DF3ULL, 
            0xE11DFD2F6BB0EAEAULL, 0x1C5C6B0AE4C3E993ULL, 0x53C3729CDECD87B3ULL, 0x9776B5C8BD072F87ULL, 
            0xA7E829FAE63D8AEBULL, 0xE1F37D60B4B74698ULL, 0x81A233A5FC78C98DULL, 0xE6BE4FB84A4C061CULL
        },
        {
            0xC6854C4D97246E16ULL, 0x965E6C06632FFE4DULL, 0xF67EC76FEF88170CULL, 0x0507E3F798DBE5BCULL, 
            0x997B51D889BDF095ULL, 0xE80025F6A93B7BA0ULL, 0xA1F6AEDCCC6A0074ULL, 0x12D02798EA027C1AULL, 
            0x7A500B99E1513608ULL, 0x0722DA50B3ADB37EULL, 0x72252104A330314FULL, 0x8B09C1EEDD825BE1ULL, 
            0x4A3FF92A5A36A8D4ULL, 0xD9F2DD239D295D54ULL, 0x5EE494B3D4D77CCAULL, 0x20C01ECA2EA3CDE0ULL, 
            0x788B54ED29D8F2A3ULL, 0x71F3E68DE014CA03ULL, 0x529CC892A4AD751CULL, 0x867021C7D86E8EB1ULL, 
            0x118597C8397ED913ULL, 0xA68496F25B1FCA92ULL, 0x87E2A61C170D7FB5ULL, 0x8536E7E746757AC5ULL, 
            0x6DE448D9C7F98DECULL, 0x652021660086EA6CULL, 0x241BE52F84BDDE41ULL, 0xEAF8C5689075C0AEULL, 
            0x545646D7D19960A3ULL, 0xCD27F04C992175CFULL, 0xAD29E1C09AAA1E27ULL, 0x12509AE57DE107A1ULL
        },
        {
            0x41C6ADB560A12B0AULL, 0xEAC44A4650E46DDDULL, 0x05BDAA3BB9841B60ULL, 0x7D1BEFC7F6F6D621ULL, 
            0x25A6A8BB8A3B44C0ULL, 0x94AD9A72F5F4302BULL, 0xDBA3BFB3F0C38098ULL, 0xD09FB688161E07EAULL, 
            0xCED9BC8DE8EBCC3FULL, 0x189700D5D67662D0ULL, 0x6932650CD279F8AAULL, 0xEF9CCF3C605DFB09ULL, 
            0xD6F088A6DE3E245FULL, 0xF181B71327476C0FULL, 0x7A87894FCE96FB15ULL, 0x17755FF57DF98B81ULL, 
            0x814248D42105A042ULL, 0xAD32B22BBDFCA197ULL, 0x9FA5E1087C717D0AULL, 0xF2AE8FF1A462C785ULL, 
            0x7CF61548B518C9EEULL, 0x9D0E1B2938734D55ULL, 0x974E50937003E016ULL, 0x4920BDA3E657F513ULL, 
            0x9662BA46D7B2AE97ULL, 0x5FFCD208EEF17589ULL, 0x8FA95892277B931DULL, 0xA7E8A783E51669FAULL, 
            0x386E74AA9BD47C78ULL, 0x84D5A65EDADCF884ULL, 0xD6A6BA08701D9A4DULL, 0x8FE672A168B553E1ULL
        },
        {
            0x0E3E4D726E5986F9ULL, 0xA2413A7E6717F67AULL, 0xBE4A627F14FD8AE6ULL, 0x5C836C92F95E38F9ULL, 
            0x42D88E6997A99FC7ULL, 0x720A331FBE99E842ULL, 0xE2651573AE3D86CBULL, 0xF19C1ED607C5B229ULL, 
            0xC2E04D86416F6F39ULL, 0xF7B15652C7B5AA1EULL, 0xE97F4DCC8670F865ULL, 0xDCE1FA8CD53A1CECULL, 
            0x64D962BBDC207711ULL, 0xE2F3C3EBC53D1954ULL, 0x29D61A217A2408C4ULL, 0xE21255BFA04D36E4ULL, 
            0xDEF541D174EAE6DFULL, 0x6F5B2F908E1537E8ULL, 0xBFA54CA5666A2D80ULL, 0x1A11AEDCE7C78A95ULL, 
            0xCB73B8E0019482E2ULL, 0xC13F6F4143B22C5EULL, 0x591F18ACEFC3E38DULL, 0x7965F3D0099A67F9ULL, 
            0x15CA79D0F5ED7CE3ULL, 0x1B0AA5F16D2A52BCULL, 0xFCED28FDACD8D820ULL, 0x476DF4634784FB31ULL, 
            0x8E6C82BDA32A07FCULL, 0xE5DF24F8F8EDE889ULL, 0xC480D965254159E6ULL, 0x5C17D83AF23D6CAAULL
        },
        {
            0xF85FCA0458A8A27AULL, 0xC748F959D44A2757ULL, 0x0A08D38AA7A3DC03ULL, 0x9584CEC1DE5A26BDULL, 
            0x0FAD0C705BDEEF49ULL, 0x3DA76F7C0598C221ULL, 0xC03142A1054958F3ULL, 0xB32E36DBFB9DAA69ULL, 
            0x9F868DB9DC043573ULL, 0x4B8AC89D4FABAD43ULL, 0x8D7C18C9ED1F7316ULL, 0xE63612FCE0244C6AULL, 
            0x2C96AF7CDA5D4087ULL, 0x692A35ED6B7886F7ULL, 0x49CD697B059733E3ULL, 0x5678484AFFFC6691ULL, 
            0x3CAA2F78B0486D10ULL, 0x3359323E5E00FD62ULL, 0x3D509895EC69C539ULL, 0x9066783716AB26A8ULL, 
            0xCEAE2FD5353A661CULL, 0x56C392AE3C1CF344ULL, 0x38694B509FD8E504ULL, 0xE7044F4F6B73DB99ULL, 
            0x0BFE87FC9F0023A3ULL, 0xCC86FC9BA3E71A2FULL, 0x6C4F91E7661C35DCULL, 0x3469E4B6AE3D9847ULL, 
            0x49DD9D1F10A7084BULL, 0xE9FFC7A4182EF92AULL, 0x93942B92E7BC0B50ULL, 0xC2C94221F81E8717ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseEConstants = {
    0x9AD3CB81BD52EF84ULL,
    0xB966D706F416E360ULL,
    0xAE9F73025ED39AE9ULL,
    0x9AD3CB81BD52EF84ULL,
    0xB966D706F416E360ULL,
    0xAE9F73025ED39AE9ULL,
    0x6B254954B36EDE65ULL,
    0xBFCA1E9A0B5F6C39ULL,
    0xEF,
    0x11,
    0x16,
    0x31,
    0x5B,
    0xC6,
    0x14,
    0xBF
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseFSalts = {
    {
        {
            0xB7810DAE61591332ULL, 0xDDB2F56D81E51CFBULL, 0x9FC2105916AAFFCFULL, 0xFBA8FF947EA22398ULL, 
            0x3477097BDCDEFCC0ULL, 0x9B77A60C3AAE54C9ULL, 0xE35AADBC5AD4B86FULL, 0xEA20FE3F2F05DAE8ULL, 
            0x7E3C53C2833B941AULL, 0xD9A86F8B9B0748AFULL, 0xE8683AE8D22FEBCDULL, 0x886D0961C3520349ULL, 
            0x0414855A612818FBULL, 0x9C3DCEE3E276358DULL, 0x457839A94945AD03ULL, 0x169CB1437205B1DAULL, 
            0x3793784ED3E30D9EULL, 0x8A8756241F28045CULL, 0x577784BBA9A93384ULL, 0x52AD49C1973A0631ULL, 
            0x7526AD08A3D2F9FAULL, 0x28626345DF6D57CFULL, 0x939616D69BB69B54ULL, 0xA0CA944E5D223065ULL, 
            0xF0A82A16CAE73AA4ULL, 0x8007FC63E378818FULL, 0x743CFB45E4EB393BULL, 0x430319F9F1392B51ULL, 
            0x95F7AB266D6761BDULL, 0x28C8524141026F57ULL, 0xBC4669DF5C69EF9DULL, 0x2C252DAA4C063DCFULL
        },
        {
            0x729FB5AA573BB8BBULL, 0x23B90DFE5EE7F793ULL, 0x98BE3538CBA2F824ULL, 0x45441848F12F1647ULL, 
            0x743A86724F5BC893ULL, 0xA6CFB990317A370AULL, 0x0F5E0E61B6027472ULL, 0x920ED6FC36ADB627ULL, 
            0x6D1546A68D323289ULL, 0x059E0E9DC5CECD49ULL, 0xB6D6C9B89F03E764ULL, 0x2BF9A3F52E96B426ULL, 
            0x11F4E72859221D87ULL, 0xA2661CC80C7691D1ULL, 0x66A3728085DAFC8AULL, 0xCB262958CDE6A0F9ULL, 
            0x3E678F65211F7E2FULL, 0x1149B775DA3DDDB4ULL, 0xD412D49F68C2F535ULL, 0xEC5C190005978BC0ULL, 
            0x3FF96C1B5EB456C7ULL, 0x0DEC2592636F134EULL, 0x9A6F495BD793B9A1ULL, 0xCEFABFF2F7CBC615ULL, 
            0xA5C0D48EFA1BEE38ULL, 0x829929A5CAA598F8ULL, 0x00A92CDA035663A5ULL, 0xAF132E90FAD904BDULL, 
            0xE4A795C5F6406B46ULL, 0x798534BDAD7A59E1ULL, 0x072A1D8B09AF1853ULL, 0x0DA72E0E356F8065ULL
        },
        {
            0xEB0969204FD9D30EULL, 0xBAEAB7E09BEB8D6FULL, 0x9DD89723D88BA7D8ULL, 0xD4A7F7AE9EDB3AF8ULL, 
            0x577407AF659B5262ULL, 0x92E55D409CBB8E4AULL, 0x0691FF80FC770993ULL, 0x84CD9F971640F19AULL, 
            0x88588B0BE5960075ULL, 0x56C5544929167FFFULL, 0x5365AE8F4D4F2F7EULL, 0xC16DDDE3CDBAF975ULL, 
            0x167CA69661D55F57ULL, 0x2DDCAC9BCF02E3E1ULL, 0x145BD357D84D6EC9ULL, 0x4584CFFF81B0F169ULL, 
            0x97F6CA1DE279FE64ULL, 0x8076B71287325049ULL, 0x58C07413EC78A467ULL, 0x0F0E82B96ABEAA4BULL, 
            0x3E738175A6477A9AULL, 0xE8DC0DAAEDFE168FULL, 0x06B9A8FA638E6C9DULL, 0xF8C1C75FA168BC34ULL, 
            0x5282592D67F1E806ULL, 0xBA132948D5BE7350ULL, 0x0BEB213A67C0E5A1ULL, 0x86D28963577B67ABULL, 
            0x290CE41C4AC99C35ULL, 0xA0400F3B80EAEAC8ULL, 0xDD523AE89FC98823ULL, 0xCBAFDE494A39D77AULL
        },
        {
            0xA2964ABDDB3F471EULL, 0x038D64919D113FB3ULL, 0x03AE1C3A8066289EULL, 0xBFB602B1A9E30B75ULL, 
            0xAA93D852BB5D0399ULL, 0xB8A6E2A8B3BEDAA7ULL, 0x9FFA1F0D833CFB1EULL, 0x985D6A9D980935B4ULL, 
            0x6BF527F5C06D6D86ULL, 0x0B9251282EDAF3E5ULL, 0x7161942DE72E0593ULL, 0x84EDF74EF611DD1DULL, 
            0xC89DCF6343C1076AULL, 0x5C3353A7D996A43EULL, 0xE3C2C0DC7ABFED10ULL, 0x08367CD0752E238DULL, 
            0x4DA25C9EFD20CEA8ULL, 0xD249E45B6E8F6B91ULL, 0xDB0E2FEBCB234174ULL, 0xA38918505D790943ULL, 
            0xC1141B53FC897FA9ULL, 0x370BA3ADB49449D2ULL, 0x787C46A9A9821759ULL, 0xC7CFF4DDED9D5FAAULL, 
            0x366DD6E5B1EE98ACULL, 0xB1CB4ABFF4B7C5C3ULL, 0x408AAAC967F97559ULL, 0x36181C70346309EDULL, 
            0x6C7E2C4C14986A21ULL, 0x7C05223A3141C9B0ULL, 0x8A3678301804AA24ULL, 0x4C90F1A58AECBB6DULL
        },
        {
            0x2716E9974AAE8952ULL, 0x53E27F5DB36B908FULL, 0x703E2E76BDCF1CB1ULL, 0x9F7977913EF17DE6ULL, 
            0x1A10A39C8E5B17BEULL, 0x07EC36B9ACBCF2CEULL, 0x3FEED17467F81116ULL, 0x44F99C8985AE6DD5ULL, 
            0x4213DFAF26BB4FDCULL, 0x4956331E434CBD3AULL, 0xEB7B4A692822E036ULL, 0xA48236BE5157D128ULL, 
            0x8F8084DF27B2CB39ULL, 0x1E87C82D877A9621ULL, 0x9B33A08813B27A4CULL, 0x6D99207D05833540ULL, 
            0x40A9FFC601BAE28FULL, 0xA3770922B30D1225ULL, 0xC9B1A1111682C283ULL, 0x574EF11398A2E00CULL, 
            0x0C89776FFBB22175ULL, 0x3F5ECE26531E757FULL, 0x88636087B4CCC9ACULL, 0x9E82B66B43A9159EULL, 
            0x90F803EC16A57EE0ULL, 0xE6856EADDC49EC47ULL, 0x62EA073751387024ULL, 0xB01FD01B6D5E51F5ULL, 
            0x4BA9E8763D88F1DDULL, 0xCC608795DA53445DULL, 0xABD71032F04B3A49ULL, 0xA204BA2A0A1F8C58ULL
        },
        {
            0x4D2A7FDD177CA574ULL, 0x1F25D13630BD928DULL, 0x38D9C92BBCD0F859ULL, 0xF0C52FEA43B0863EULL, 
            0x803A569D2E2D8239ULL, 0x891A97F029830356ULL, 0x0B1CA322481C434CULL, 0x291132D72BF95E26ULL, 
            0x007B2F655223AD81ULL, 0xCEDE9A0C44C9A3D3ULL, 0x87D8A9E189852FE8ULL, 0xD4335C9B0E3D9B50ULL, 
            0x17F0C50A2620AAC1ULL, 0x7CCCCF1921D97908ULL, 0xC0372E1DAC6A84BEULL, 0xC7A1A43D984F6AA4ULL, 
            0xE87AE6F9658CB694ULL, 0xE6429477B0AE6A3DULL, 0xE8B4E68EDA2310F9ULL, 0x854DF13BD5CAA2EFULL, 
            0xEDA5BA164B88B098ULL, 0x96EDFE69209CF8E2ULL, 0x2FC9B70D497042AFULL, 0x2922C2760E318D3FULL, 
            0xCEE42FC50B408942ULL, 0x7E885CD12AB9365FULL, 0x316B212558BF9F64ULL, 0xEFDA09A93180BA9AULL, 
            0x406ECE977A36EF98ULL, 0xC9371AB1EC036449ULL, 0xB8F4C80DFF883DE1ULL, 0xE10711DB8F89138CULL
        }
    },
    {
        {
            0x7DABA60B97493504ULL, 0x39E6F4383B206FB5ULL, 0xBBE05AF2F6F7CCC9ULL, 0x130B5F499045531DULL, 
            0x46672E7FBB3898EFULL, 0xDB621C51026A72E2ULL, 0xF9AD64A80E59FDFFULL, 0x1EC6ABF8A37085DAULL, 
            0x33942E8BFF98A61BULL, 0xE93D5BAEE757A5B5ULL, 0xCDDE4784FD691F3CULL, 0x7411209C767D42FAULL, 
            0xF60319C8865B99B9ULL, 0xD18D1B907BDD7176ULL, 0x86C004BA888C84A5ULL, 0x92B71DD0BCC9764FULL, 
            0xEF6358A243A8B9E8ULL, 0x3BD86D223723B26EULL, 0x9FFC509C65506062ULL, 0x0ED6A59DF0242B7AULL, 
            0x661A89D34B311D94ULL, 0x8C3AAEF32DCD3F31ULL, 0xBFE6467F1D158BA2ULL, 0x41C83BE1BCF5E209ULL, 
            0x56859EEE1E044CCCULL, 0xFA68ADCBC7C865A3ULL, 0x5E16B93D0C6FCD9CULL, 0x820E09E763D942F9ULL, 
            0x3FC9B4CE504A75CFULL, 0xCFEB9C9BDDD33EADULL, 0xE988800A80EE4DF7ULL, 0xFB86A6034A63CE29ULL
        },
        {
            0xF7134E85E24AF0ECULL, 0x88D46AF4531ED1BBULL, 0x51A2A1A5F6C02D23ULL, 0x8838E49A6FC7CABDULL, 
            0xD38AFA98680760DCULL, 0xA9EDF901E8993367ULL, 0x2999A7FEB14F0726ULL, 0xE9B280A7C4DC5FBEULL, 
            0x2BB142D518F157B1ULL, 0x2DBBA638BCA56705ULL, 0xAF9A6685F27D2D7FULL, 0x6E9292C180061510ULL, 
            0xE22C91867EAB582CULL, 0x6778077349610D08ULL, 0x453AAD13E1E31873ULL, 0x270C4B88AE8193B0ULL, 
            0xA3695C6C3B48362FULL, 0x99CDE81D0DE70005ULL, 0xC86680A9CDD65534ULL, 0x95145C8CA3002D0AULL, 
            0x1B417FF0A2F40812ULL, 0xF3FD19F052AA29B1ULL, 0x4FD7CABFE755850BULL, 0xA325E92FF26A9746ULL, 
            0xB4C2DB2E50691A3AULL, 0x8C447D36AD227419ULL, 0x0C830EBBD85BC5F3ULL, 0xE8282AC6331EBC49ULL, 
            0x13DE35A9D789EF52ULL, 0x16E750442EDE2405ULL, 0xC350F377C143C019ULL, 0x24DAC2908A6F5C6BULL
        },
        {
            0x0BD6F2A96752EAD8ULL, 0xC6FDB5933D9B941CULL, 0x50A76271392CF78EULL, 0xC3129BDB68AF5D28ULL, 
            0x90A4956952781E9DULL, 0xCD5135255E709BEFULL, 0xD0EA2A194E243B59ULL, 0x396C27FE3A25AB5EULL, 
            0x8279CE9DC537B5A1ULL, 0xE2215665036FDAB4ULL, 0x64E24F7251784325ULL, 0x1A6D96EFBFA3B065ULL, 
            0x61A862E12BF1BBB2ULL, 0xEB5848E8961AAA62ULL, 0x241516C9DA62F099ULL, 0x7B3BC9CEE79B7E56ULL, 
            0x91186F2CEB6183B2ULL, 0x278596CD2E467699ULL, 0xABE075ABDC66CC88ULL, 0x7C77306EE823D62FULL, 
            0x9D219B2E013F0293ULL, 0xD1A8A033F432F484ULL, 0xAA6B566B4526B65BULL, 0x3704729239A9BABBULL, 
            0x243B87F14FFD70BFULL, 0x675F7A50834A8595ULL, 0xDDA645DD5EAC0959ULL, 0xCCD3B52E38D30C8DULL, 
            0xF639C55990F7503FULL, 0xC091A7C4F38ACD58ULL, 0xD8B443B7261D66D4ULL, 0x2E13FD4705E33518ULL
        },
        {
            0x66BC4ABD5692B87BULL, 0x9768752A64641BD0ULL, 0xF4086700F1336D3FULL, 0x4CE42CAD2CCDE9EBULL, 
            0x39D8041A010B4B51ULL, 0x23EE881BEE919399ULL, 0x9A575D844C19B386ULL, 0x20C32D9B7E359CE4ULL, 
            0x77ED47497B8D438DULL, 0xEF6CEA446ABAF24DULL, 0x0C7CEA152492700AULL, 0xE6ACE673ADEC2A6CULL, 
            0x6F8CAD87ED7F2641ULL, 0xABBF2B7E2F5A23F1ULL, 0x712D94E18D2A2FB5ULL, 0x6ACFC05A2DB125DBULL, 
            0x596215A78BB9E71AULL, 0xF7D4AEE0D418A32FULL, 0x81B0151B7D82FBD4ULL, 0xFF07BB7CEFF87D86ULL, 
            0xDBFE12BAC47698A0ULL, 0x6CDAA611840C5E5FULL, 0xD2B6BC60B4CA40CFULL, 0xC0CE91A188690DBFULL, 
            0x9D00E175475A9E1EULL, 0x700484BF989AB6AAULL, 0x2A359E0EDDDAEC32ULL, 0x5B2FC6ABC9AB6A36ULL, 
            0x7A2D355992CC8172ULL, 0x877A77FAEF62DEDEULL, 0xEA2AA4A4926D5840ULL, 0x714079CC275EB718ULL
        },
        {
            0x26A9E1962854BCDEULL, 0x3002703D780AB3A4ULL, 0x23345652D0DB88D1ULL, 0x96E67B01D1B54A80ULL, 
            0xCBB242F603012365ULL, 0x7F0A35D37553675FULL, 0xE8585304A1068997ULL, 0x2C4DFCCF76D79B40ULL, 
            0xF22A4CC403314D9AULL, 0xA535B3399DBBECCCULL, 0x2304B23AF1748889ULL, 0xEC7A4E9729D46B45ULL, 
            0xF0A33A34190CF19DULL, 0x5C307FEC1C63701DULL, 0x354BF889B3535538ULL, 0x85851A77166D33D2ULL, 
            0x9FB81185D45C2D50ULL, 0x9658F7EACFCBB8C1ULL, 0xCA9DB8E77102FFAFULL, 0x5D40F278F9D020A9ULL, 
            0xB34F6155D726C14EULL, 0x8DC76E2502CF8226ULL, 0x077BFA2EC90D7800ULL, 0x8F1138D1545E4BBDULL, 
            0x29E3C634F775B23EULL, 0x458B2BF1A8464B41ULL, 0x4E3B4FB0C0934DF3ULL, 0x8E73208393F1C3DAULL, 
            0x05D2BE1C0D427484ULL, 0xDD17072C3BC8F93FULL, 0x3C727DDAF4514629ULL, 0x3B4B239A8C5315C1ULL
        },
        {
            0x75C56242AFCE96B4ULL, 0x3D421984D2F93D98ULL, 0xAA649F59FDFD5A1AULL, 0x9C1C66C0656189A0ULL, 
            0x20DEE64039E8205FULL, 0x70212C53412256C3ULL, 0xBDD7063D2ADC2508ULL, 0x815727284C128B3DULL, 
            0x3452641E9BC71E85ULL, 0xF041B7749292E554ULL, 0xA628134BAE4DBAABULL, 0x48030D435C2AAE25ULL, 
            0x545B85E2E14CDB96ULL, 0x5BED35426AE0CE66ULL, 0xD52FF6C4E781C7EEULL, 0xE2660247525B4F26ULL, 
            0x3335D1EF59449428ULL, 0xC4C0D8CCACB15607ULL, 0x65BEDB3645D70CCAULL, 0x94EAB4DDCAEAE0B7ULL, 
            0xEB8D06D49F688402ULL, 0xE1CDFB3D335B0D8BULL, 0x2B9255C6FB66B0CCULL, 0xF5745D76C8826606ULL, 
            0xD8987B1CEE727257ULL, 0x1130F7FB79099BDBULL, 0x92384F733753B984ULL, 0xCA6426EF39EAC3E5ULL, 
            0x1BF0C67C4D04F7F0ULL, 0xBF5F89059BF95D9BULL, 0x42DD4ACD43649D6AULL, 0x794C564AD20B7F2BULL
        }
    },
    {
        {
            0xACA34A5F2ADB3D1FULL, 0x26FAAF626F331082ULL, 0x2A818727C17E63F5ULL, 0x39215713BF654889ULL, 
            0xFF669B7557673C33ULL, 0xF360A6B31D467F8AULL, 0x7BCC6B10396F1E01ULL, 0xD1CF91E179B982B7ULL, 
            0x25B2E7E3E5E90D92ULL, 0xFF1D6DF6A8EAD8DEULL, 0x38696E8A0E27DCC9ULL, 0xB683DBA2EBAB2C04ULL, 
            0x069F7673701AF028ULL, 0x1FFD0D2482C4A830ULL, 0x2F440C7C4EA05D30ULL, 0x9E01090BA82AD31FULL, 
            0xCC3BFCDF48516491ULL, 0xF44A36AFFA3535BEULL, 0xFC4C11F6F3069773ULL, 0x4B59AEDDBA684B8AULL, 
            0xCB67479466250EE3ULL, 0x895B4EE15192A4EBULL, 0x9B45184CB07D4A9BULL, 0x753AB21D4E7726DFULL, 
            0x3B63EC3B4B368910ULL, 0xB66AEFBF4E39EFF5ULL, 0xCDB7D49778F996D3ULL, 0x7980C3A3410D7A01ULL, 
            0x7D1163A362E50B00ULL, 0xC94164158B08ED50ULL, 0x6BF54B0F7BD83FA9ULL, 0x7547F1DB08340149ULL
        },
        {
            0xCD3BFE634719FEECULL, 0x0892AE7AA3323BEFULL, 0x7527D5544A135804ULL, 0x638378D3EC931450ULL, 
            0xB8D72006BEA2B9E1ULL, 0xB783EE1CFB225404ULL, 0x33F99003BD928D65ULL, 0x834A389C152EA033ULL, 
            0x497035F203006486ULL, 0x47886BA7EAAED955ULL, 0x00B894412195BA26ULL, 0x42D1E540515D650CULL, 
            0x75DEE88BDEFC356AULL, 0x257609A36662228DULL, 0xC0FA0902EEDCE94DULL, 0x19259A4338EA1845ULL, 
            0xB39A3AB658B75723ULL, 0xAAC4267DDCCE5773ULL, 0x1A42C14D1E739C85ULL, 0xA0487939B63810D8ULL, 
            0xDDD951405EE0DE18ULL, 0x60CE06EA3F9BECC1ULL, 0x7A717AD61DEC5F0EULL, 0xF8B2CAE91C58A3DDULL, 
            0xBA288FC35CC4C1B0ULL, 0xD5194A6C838A514FULL, 0xA4EB5B50EE807C26ULL, 0x7395671802C52F04ULL, 
            0x61368E32A5B9860FULL, 0x191495B581243EB6ULL, 0x744F0C388556250AULL, 0xB5132154BC7DD59AULL
        },
        {
            0xF7C13EC2F0AE953EULL, 0xB8B041A9A2FC650EULL, 0xEBD8B23AB0AF6130ULL, 0xB7BA16C9BB28A234ULL, 
            0xADEB23EDA3DEE9D5ULL, 0x9C34B7843CCCCBD5ULL, 0xAB4532210F138684ULL, 0x96A2B9635CA0107BULL, 
            0x4609AECC1BD47A3CULL, 0x5BBEE91CA3BE53E1ULL, 0xB6CCB5E7FB071796ULL, 0xC2FCE2F73B457FB4ULL, 
            0xCB5369848108B834ULL, 0xFB0406F83D1DF838ULL, 0x9C340031267688F2ULL, 0x49A986AE179A853BULL, 
            0x14BA97CD928FCE2DULL, 0x0B530061BF7C8274ULL, 0x063184C914A92F35ULL, 0x44812B2BE68A8799ULL, 
            0x942CA01763922263ULL, 0x4FF348BC77820806ULL, 0x5AE8B9E8C5F62A24ULL, 0xBB17D993BA38D011ULL, 
            0xE64ECBA919E9DFFDULL, 0xE6C4D7E5966EC0ACULL, 0xF38518F1BF2406E6ULL, 0x8F4FB999FDE4CA7FULL, 
            0xD9A6D8669DC6B878ULL, 0x68437E1125CAA967ULL, 0x974A0E2DB91CC46AULL, 0xFDB740126FCAE6CBULL
        },
        {
            0x96BE2E96D9C79871ULL, 0x5F5E5165BCA3B78AULL, 0x99698A02B6562B86ULL, 0x8949484432CD41DCULL, 
            0x43238E370093FA78ULL, 0xB8B637FBD81390DEULL, 0x2D3253E3F349F9A4ULL, 0x6EC289F244CBB280ULL, 
            0xC026B007AE9F5EA3ULL, 0x9A9BBE4367FA81B0ULL, 0x652EE17B79454BC9ULL, 0x8F45BD83CBE64F8AULL, 
            0xD4DA520578022177ULL, 0x59FEC6FA1F98BC68ULL, 0x2898A58F6E8F26C9ULL, 0xA06EB0074F9C652DULL, 
            0xC47132AEE48FE68AULL, 0xE2E1049F81E4C80BULL, 0x8A6D30A231C23C1EULL, 0x0185A96BA600D734ULL, 
            0x554012CFADFEC3B0ULL, 0xECBC2972526672A6ULL, 0x1B942E2E538D67A5ULL, 0x5ECA489D5A3B7235ULL, 
            0xD497647EE03431EFULL, 0x42056F99DF06EAFCULL, 0x72885D5A7F6C387FULL, 0x8B7AF58F9C671109ULL, 
            0x3D8682BA67C2A242ULL, 0x918283AA8489CBB9ULL, 0xAD69BA19D65F9FE2ULL, 0x7075ED68A6856420ULL
        },
        {
            0x772D8F8EEB483A54ULL, 0x7A05311D40B6ABB1ULL, 0x4DC2439A6650C856ULL, 0x07C158C782D07FCAULL, 
            0x96BB387CE56A2930ULL, 0xD869637A68CDAFDDULL, 0xB767A754BE47E457ULL, 0xC43B35E23D666742ULL, 
            0x74C6EDCD0A6A25C7ULL, 0xF162D8695EEA4393ULL, 0xE7E247DBFCC01616ULL, 0x5C0A99BCCAA6AFF5ULL, 
            0x0FE3727E03824270ULL, 0x9179ACB48E42B0ECULL, 0xA3B15A360C8E2156ULL, 0x21E1123D66E061C2ULL, 
            0x17738CA065CF1534ULL, 0xB5833DFE5EA6BBA0ULL, 0x6C07A25DA25EAB80ULL, 0x1931F9D10A3974B8ULL, 
            0x5DAD97216462BF0CULL, 0x0F0AE16E2659B5DAULL, 0x421828FF067D5D77ULL, 0x2732316D39B70687ULL, 
            0x01380EC23161C9B2ULL, 0x016BB5734B9A3DA3ULL, 0x9069F6D595ED7785ULL, 0x6BB109E6BBB08880ULL, 
            0x9601AA25158EC99DULL, 0x4E0646647B9330DCULL, 0x292778E2D50E6BEBULL, 0x134911EA47D59E09ULL
        },
        {
            0x273AE567C5669BB9ULL, 0xA674FA6532C0DD78ULL, 0x669500E7E4B87D6EULL, 0x98E6DB3806AB41CDULL, 
            0xECCF53DC8AF101F7ULL, 0x32739EF760769A7BULL, 0x34FECD5D8C0B70B4ULL, 0x1B4683E7720C6F9AULL, 
            0xAF99E4BED6000BE4ULL, 0xDD7797D666DDF3E8ULL, 0xCF5385B8F43AE3E1ULL, 0x1910D057097597E8ULL, 
            0x7E6738784D67AC16ULL, 0x38996BAB7F407663ULL, 0x32A9B4B9ED46D561ULL, 0x64C8AD1C4F8317C9ULL, 
            0x7A698B582941F490ULL, 0x28425C05A20DBFB5ULL, 0xBB3DE9D85A30E3F7ULL, 0xD3B7C6BBDE58622AULL, 
            0x20D7FC341681A95DULL, 0x177BBA7100A42EC1ULL, 0x708AF0D347D4CAF3ULL, 0x81E64FB94CE3FF5EULL, 
            0x3329DE1BDD39BA16ULL, 0x9288C0D730FA265EULL, 0xF74B3FF936A0DC8CULL, 0xB7703512CCC5E4C0ULL, 
            0xCDC7AB7058CA67E3ULL, 0x454657FA3E6748EFULL, 0xEAD5F407942F4D59ULL, 0x344C243BFA6E2FA9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseFConstants = {
    0x303C515EFAB34163ULL,
    0xB004771AE3DD7E78ULL,
    0xEC3B9D7C8C9FAA98ULL,
    0x303C515EFAB34163ULL,
    0xB004771AE3DD7E78ULL,
    0xEC3B9D7C8C9FAA98ULL,
    0x3B6E7E56B70B99E9ULL,
    0x4CD8F241198F6C4FULL,
    0x0E,
    0xEF,
    0xB4,
    0x30,
    0x3E,
    0x5A,
    0xBA,
    0xEB
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseGSalts = {
    {
        {
            0x10F0ABE3F3A4E51DULL, 0xA3DA26D38968AC8EULL, 0x4B197E664F53AE17ULL, 0xD99B2A24C2E34D33ULL, 
            0xEABE14197D46B1C6ULL, 0x80E29FA0CF16F0F9ULL, 0x4B9A8A8B7D7D94F5ULL, 0xCAB49FF227335EF2ULL, 
            0x9010973F59BC1EC2ULL, 0x7BE279A89E966BCCULL, 0x3BB1648175461F96ULL, 0xF56476B0F3264A86ULL, 
            0xC5F25FF5718262CDULL, 0x183077608F9A2497ULL, 0x74D3CEB922055D9AULL, 0x0C775969B00C2FE5ULL, 
            0xCA3BAF0B15947F53ULL, 0x0BF503848FDE235CULL, 0x803396231D533493ULL, 0x7D10A509DC91E8AAULL, 
            0xD4F6AA2184BFBDC9ULL, 0xEE2A021CE69361C7ULL, 0x18189EABA2A89289ULL, 0xFDB41EA5B2CF6245ULL, 
            0x3662A188891FCEA6ULL, 0x78F7893E8C95BD84ULL, 0xFB70D67D807119FFULL, 0x80BDCBDEFAB40401ULL, 
            0x166154B5F8226E2BULL, 0x4EF44267F49E73F5ULL, 0x4824CE1F6B3E4FA9ULL, 0xCA20611AF8FD7F09ULL
        },
        {
            0x071A5ED11E1D5A33ULL, 0x31ABB5C2D4D9F100ULL, 0xAAEDAA2536120378ULL, 0x0DC8C013CCAF2E43ULL, 
            0xC8A5285F4E4FADFEULL, 0x91E8FA1F55537F65ULL, 0x02C59643F0C5AC5DULL, 0x2964A9CF869DE19CULL, 
            0x81D92DF959913E55ULL, 0xC1B3EF0B7B4F5906ULL, 0x9B6E7D8B99C2C46BULL, 0x8256472C16D4D1A4ULL, 
            0x0E7590B76D949530ULL, 0x6CB865B4E286AA75ULL, 0x9CB89A2B61332AB2ULL, 0x6A1234AD46BE8098ULL, 
            0x63BA2BB7BA11F464ULL, 0xE583BD4427DDD251ULL, 0xC71A77E6872950F2ULL, 0xCAC2C489131A8CAFULL, 
            0xABDDAE97EB050F02ULL, 0xB478981D4234B83FULL, 0x6A687AE730E398EBULL, 0x12C09B0654001391ULL, 
            0xCF6676ADE6BE912DULL, 0x15DC499486C419A1ULL, 0xFCBBB3DE5BA421B4ULL, 0xBC6AB73D64B01D2AULL, 
            0xF5FE329E5CFA6D4AULL, 0xE13F7D15E23E841FULL, 0x09A81EA3FBED739BULL, 0xCFD9F5DFE04A4552ULL
        },
        {
            0x6FC57374AA82CF9AULL, 0x29935F80F2828393ULL, 0x7C0EC3F0964A9C2CULL, 0x34CE9D8FFE69F9E8ULL, 
            0xB0DB59523360E35DULL, 0x3C2B96FD52445734ULL, 0x2B7D04052A26F6D2ULL, 0xF931B93033271F6EULL, 
            0x80C1A560D37111C4ULL, 0x70803E1F05402B37ULL, 0x27E86C1930A6E212ULL, 0x757C64AA32FE7D28ULL, 
            0xE5FD40FEA1538777ULL, 0x4EF58D57D67FDE82ULL, 0xD9A19549B95D640AULL, 0x565281F018F64FD9ULL, 
            0x0B380386BCE07871ULL, 0xD70EC4D7DF837626ULL, 0x4DE329016498D764ULL, 0x5F0852D62E50F7F9ULL, 
            0x87B760AAA5713261ULL, 0x242094D07DDE0527ULL, 0x266D5596B30D77B1ULL, 0x2871F29487E4C8C8ULL, 
            0xCF9059058BB58314ULL, 0xD952D4C01A5D0C14ULL, 0x5C51BC511CA2E242ULL, 0xEE23D9F73177EF06ULL, 
            0x8B00763A2A4E7DDAULL, 0x2D4F1164FA1550BCULL, 0x00797F6B754B5B37ULL, 0xF029299930B9AA5FULL
        },
        {
            0x7D6EB919CE07B798ULL, 0x7300C82EB5F1970EULL, 0x219B67A2AA800795ULL, 0x2A21C182DC77DCA8ULL, 
            0xF5B4832B5AA942D3ULL, 0x878581C56E484CB5ULL, 0x289E25E97B8847B9ULL, 0xC397C5488565AEC2ULL, 
            0xB6A00BEAF6E3D6D9ULL, 0x1805B807EC4BE1EFULL, 0xDC4BAA6804DFC133ULL, 0xB73AE8BB1E911DEAULL, 
            0xEFB38C87E9F841F0ULL, 0x3801A17E43482C90ULL, 0x56E102BF298DEE71ULL, 0x3BB2A3FE6C27627DULL, 
            0x3FFB9B5336CF408CULL, 0xF4D2301000C005C9ULL, 0x1C080E1DA2155306ULL, 0x167141452BB26228ULL, 
            0xA84AD34E2FF3C923ULL, 0x922C8AA67EAEC114ULL, 0x8A1D6C1C268089E1ULL, 0x1E7E4BAC99F2772EULL, 
            0x5F51BB49EDE8197EULL, 0x3EA47F353E41A712ULL, 0xF7AC17936B4ED042ULL, 0x513A3B626DAB0FCCULL, 
            0x55474D1D8C9B655FULL, 0xC9AE75017667C939ULL, 0x455231212CB29A52ULL, 0x3E8F2EEEB9045D5EULL
        },
        {
            0x4E43C8EDFEC93023ULL, 0x797BF4CDD7EEA6E7ULL, 0x3DCC4656C23EFA2AULL, 0xCD9D5028D118D6C4ULL, 
            0xC01F4664AF351073ULL, 0xD5AB10377CEC5E1CULL, 0x565F08F053C802C9ULL, 0x16328AB587F6ADC9ULL, 
            0x79A69B738BE2A6E8ULL, 0x96E71ACA345874E5ULL, 0xA3FA5F83AC604A7DULL, 0x8BA58FFAAF19E6C4ULL, 
            0x5DC86CDBD3250F65ULL, 0xCC76CD3A6FBFEC5BULL, 0x227E77668A5C6C81ULL, 0x562A13941DA704F8ULL, 
            0xEC6DF43E87460455ULL, 0x5391DDE0E577524DULL, 0xFF0915DBF29F3C33ULL, 0x13845E3355F75998ULL, 
            0x6408E3AD3625B839ULL, 0xF9D64C726A526862ULL, 0xB46D88C147553018ULL, 0x6934612F45632426ULL, 
            0xD1374F9998BA4A4DULL, 0x59EC1B966EB3EC34ULL, 0x8E5E043D3AD0485FULL, 0x288BEA8DAEE549DDULL, 
            0xC083883C5ECF9371ULL, 0x68BC4ADAFE257C1AULL, 0x86FE15367E550418ULL, 0x686894F99516575FULL
        },
        {
            0x9094FB8E8EAB70D0ULL, 0x54F63D23ED5EA29FULL, 0xA9AF05856A05569CULL, 0xECE362CB77F546F5ULL, 
            0x8E6756FAC62AB765ULL, 0x66E6068E09F5D351ULL, 0xC7410B5B091389A3ULL, 0xB5E016B8BE26D514ULL, 
            0x30D6CEEBF5C04439ULL, 0xBF2732774A2DACF9ULL, 0x26D5F8AF8B30929EULL, 0xEB339503275DCA5EULL, 
            0x491282F6D8263E46ULL, 0xD883BAA8E63D4570ULL, 0xFF03C144D812A1C4ULL, 0x91A06686A929F1FBULL, 
            0x988394F27EFF7944ULL, 0xA3BCFA0658EAD569ULL, 0xA47858D50BD5EB51ULL, 0x8B896E12FB8FDA67ULL, 
            0x5BF004176583BF2BULL, 0xEA811AF0B153751AULL, 0x194B13EDEB6AD6FDULL, 0xB602AA6BD7347F76ULL, 
            0x4B9E52B3D3CA31A3ULL, 0xBB3908BBF14EB670ULL, 0x17B058A88EE8EA4FULL, 0x567C794B34D355CEULL, 
            0x1D5303CE84798D9CULL, 0x324DBDCE86E25036ULL, 0x6E330E487252F84EULL, 0x2C3E5E9FA3309159ULL
        }
    },
    {
        {
            0x2CB4D4C66713BA4DULL, 0x583B6874D2F42614ULL, 0x78E663BF06BAD377ULL, 0x0937B272CC8F9B75ULL, 
            0x9D3E9229A811D340ULL, 0xC17836D7D9429DEBULL, 0x4EB09CB16AA2FD2FULL, 0x153B2B31110645F8ULL, 
            0x0C04DDA7AA92373AULL, 0x2B67E1B884077D60ULL, 0x537148CD8E3B9446ULL, 0xAE07191ED6B4F93AULL, 
            0x67395C62D20BF2FEULL, 0x9FD25AA91046D29DULL, 0xD049CF3A79817D98ULL, 0x156F5F9B134D5FB5ULL, 
            0x56CD5C374900DB8CULL, 0xC714E724146B6F96ULL, 0x65321EEE1899C69BULL, 0xF18169CEE2FE0EE0ULL, 
            0x58FC6ADD80159080ULL, 0x72ACF4A06C979151ULL, 0x616B523256556BCFULL, 0x635BA7E3E7EB9729ULL, 
            0xE882B9BF305C2CA0ULL, 0xC5B6BF3B5E23CC83ULL, 0x6213A401CB4DB2B6ULL, 0x0BDCF2CA7E84B015ULL, 
            0xC1A53ED7C5E27801ULL, 0x4D56BE19C963782AULL, 0xD3B3634612F83660ULL, 0x678BB03F0910C58CULL
        },
        {
            0xF6EB64724730A975ULL, 0x4E28134FC05EA26FULL, 0xC66A4AA9CE82DC49ULL, 0xB070D0F4074330CCULL, 
            0x039100088DE6646BULL, 0x4C369CF648AA5E8EULL, 0x28B30C71C0B4EBDBULL, 0xAF9F9A49C7B3A232ULL, 
            0x82DCADDC4C4091CDULL, 0x18BDFC14EB1CE331ULL, 0xA8E89DC3BE892967ULL, 0xD3B63AE7FE4EDA68ULL, 
            0x7A6204EEF5D2BCDCULL, 0xDD64676E87BB5B28ULL, 0x2FAA486A83C76FC9ULL, 0x1DEDBC36E5030F6DULL, 
            0x0B0EF24FB328E92CULL, 0x84C51AFDD87FD702ULL, 0x6FEA4279FD0153ADULL, 0x10237B6BFB649807ULL, 
            0x153D895817BEC6D9ULL, 0xBE46832F76EB2F6FULL, 0x9490EE158BE0AEC6ULL, 0xD73F039AAD284826ULL, 
            0x8371D42D972FAAA9ULL, 0x7506FD2E3E925232ULL, 0x6C57FD5458176265ULL, 0x465026EB20C08307ULL, 
            0x97C04D26B88EF282ULL, 0x10D6FD961570EDE3ULL, 0xAEB335B1E376B29FULL, 0xF59333BD8F2A56C4ULL
        },
        {
            0x03D94ABB91CF79FFULL, 0x15C799660808088EULL, 0xBA7514199712227DULL, 0xF6385A4CCB82286DULL, 
            0xDB2A2466F3E202B9ULL, 0xAA9ADC224FE1E7B7ULL, 0x00094818BE283494ULL, 0xBAB62A2B6E724776ULL, 
            0x6B6F08BAEAF0829FULL, 0x896348F6B83AFC72ULL, 0xB5A274F0FD2F2376ULL, 0x27FB980EF2C4B7D2ULL, 
            0x2F738B0745D6056BULL, 0xAE88BA3534CCD52FULL, 0xDFB357F25C6B6C08ULL, 0x670ACBAD3D304AABULL, 
            0x0768F803E7B173DCULL, 0xF832EF61D1D57747ULL, 0x7CDCBE434457DCFAULL, 0x68E498A8DD6DE7D8ULL, 
            0xA4AFE0CF13C05AAFULL, 0x9F10D792BE7FE423ULL, 0x4D53D168B1CD472CULL, 0x8F1CAAD3200AA7FEULL, 
            0x88045067D2B9F1C5ULL, 0x40CC58589279FB91ULL, 0x5480FA0F41215708ULL, 0x0D16120CA618DAE5ULL, 
            0xB989E571971F3E0DULL, 0xBAA88AF72DBD524DULL, 0x716E7F2B11C8DFF4ULL, 0xFD24E88CB3964E3BULL
        },
        {
            0x9164500B835D67DEULL, 0xC1FD05398BD68590ULL, 0x6B5F0A8CEEF4B9D7ULL, 0x18E874E7FFF8A691ULL, 
            0x47F50BA6F50E031EULL, 0x32E8F94E872DD077ULL, 0x40590374ECEEEE26ULL, 0x2BEA16DEAE342F28ULL, 
            0x43AB2B7588ABFEE5ULL, 0x2BBB550D0D0909F2ULL, 0x6EC7633418AF1B09ULL, 0xD21CC33AC3E9FD0DULL, 
            0xA28DD142CF343408ULL, 0x9D9740279FE08870ULL, 0x561E278D33E2DB8BULL, 0xAB27DF645EEEFA4DULL, 
            0x72ACB4FBBE39C386ULL, 0x701C69376C75B563ULL, 0x23259910B50A5924ULL, 0xEE812037F28620B8ULL, 
            0xDAC5C34618668BC7ULL, 0xEB6EEDC71EEC486DULL, 0x566D8E081D2194F9ULL, 0xA518FC419F9B2861ULL, 
            0xA364DAE9463AB8E0ULL, 0x1573B742A9B41C34ULL, 0xE8ADDA084FE5778BULL, 0xE544D67FBF8F071DULL, 
            0x192F35A983E1FBBAULL, 0xB295C861A9EB172BULL, 0x1991F0865370DF08ULL, 0x4132274125CE7F5CULL
        },
        {
            0xE3A74C374E94C961ULL, 0xF85A8512C46A7110ULL, 0x4B1AF4CBC3DF9D21ULL, 0x172A27B92AF0EB79ULL, 
            0x1CAF029472BBDACDULL, 0x9E90E96855881817ULL, 0x810A249C2579CB03ULL, 0x36AD3AF3DFE027A4ULL, 
            0x0899E986EBABD3D9ULL, 0x736D411B5F5D208CULL, 0x51C0EB0B8A529AE3ULL, 0xC4165D2BC52838B5ULL, 
            0x970415055F4DDE55ULL, 0xF1AF1AAA5DBDC66EULL, 0x3D4593D625EFB28BULL, 0x5959A99B9B94849EULL, 
            0x5A5E40426294B30EULL, 0x1FC6F4167FA60B02ULL, 0xDC22CB1A0EB31406ULL, 0x6A92FCD13B5B566FULL, 
            0xF0EB60D502364FEDULL, 0x14332E7737A3C3C0ULL, 0x7D183A80978B8D69ULL, 0x0AC53E6D8F2CEC7AULL, 
            0x0677076F704BE21AULL, 0x96B1C5390515D8F2ULL, 0x90D7FB6AF0EAF6BFULL, 0x0FBAD76DE4FABDADULL, 
            0x1F75ADFB47764AC6ULL, 0xD66D8EE3378DA477ULL, 0x5F01824C86E0E8B8ULL, 0x2E58C3E6059E213EULL
        },
        {
            0x9C1CB59F21A7D34FULL, 0x2B815747D22A365BULL, 0x12AC5E74B60F500EULL, 0x6BF905B552106201ULL, 
            0x17A395AA3097A3EAULL, 0xAF57F7DC52E5DEA9ULL, 0x201B0DB5B2CE7CE9ULL, 0x4EDB39719B6EE495ULL, 
            0x606C6AFA19D40523ULL, 0x5528D4A389E6218BULL, 0x92ED32AE0F61BF8CULL, 0xCE35458AF0719D54ULL, 
            0x9F3F060EE8479327ULL, 0x10C3AFD815C7ECD5ULL, 0xF66BAAB6F8B1DBEFULL, 0x4A42A3C6B434215AULL, 
            0x6D5FC79ABEE6791EULL, 0x07418EC504CEB464ULL, 0x1C71CA552505EDF1ULL, 0x48DF26E8DA249A86ULL, 
            0x43A0DD5E2B7D2300ULL, 0x43784DE0D82523C1ULL, 0xF2DAFCF2F3582CAFULL, 0x90297CFFB387BC0EULL, 
            0x7C57C4091ECAF3A5ULL, 0x2744FA71EC361BD1ULL, 0x26BD4DE0F96E10EDULL, 0x681DC350777F7DA1ULL, 
            0x4CA5FB7CA5589A5EULL, 0x9380AEE75BEE1D0CULL, 0xEA23F794B9FDCA45ULL, 0x40012667894B9F66ULL
        }
    },
    {
        {
            0x79DFC59E42BD081BULL, 0x4C1D90B95DF5CA17ULL, 0x90B74247247196CCULL, 0x3E9B48683B94F2E6ULL, 
            0xE8D31A5404C8FCE9ULL, 0xF5B489DB68AA1862ULL, 0x2EC57AABD785C5CFULL, 0x898B7B6C50169BE5ULL, 
            0x38B451ED3C231905ULL, 0x81C02B45A2E78D59ULL, 0x1C31C2B278B2D78EULL, 0x4558A349B4296C17ULL, 
            0x2DFEA372A370E31EULL, 0xBC7F1AFCB97A77AFULL, 0x5D25E2DBDC834024ULL, 0x8C7C7EC38CE16141ULL, 
            0x62405B4A91B881BDULL, 0x0DB99538774C64E9ULL, 0xD507E5A515BA0B60ULL, 0xA2B6675BE4F315A2ULL, 
            0x0E687E919AC6083DULL, 0x3193D0C0CD0C3322ULL, 0xC7E414A6B9D4F398ULL, 0x0BB2C18759BAF2DAULL, 
            0x57BBD341C4B499AFULL, 0x5488FD384305B59FULL, 0xCE5F85D796CB0D7EULL, 0x49A095BE77E87806ULL, 
            0xD7E220B448575E88ULL, 0xA0BCCEC927AB9626ULL, 0x2DC72051D6263838ULL, 0x80C4E6BDA25EDAEDULL
        },
        {
            0x991679592D946795ULL, 0x224616551D9B383BULL, 0x8A17BC34DEC1E599ULL, 0xAA9167B5EF82B410ULL, 
            0x0E04DFE16A818114ULL, 0x88AB7BBD929982B9ULL, 0x20080BA45808CB03ULL, 0xE70F99378EE60560ULL, 
            0xC0D0ACC7A5C88C51ULL, 0x0E52F8142EC442EEULL, 0x4EEACC1696D3E17FULL, 0x9A852C16D28C0817ULL, 
            0x1C77D7FD95325A57ULL, 0x8EE988F9089D0481ULL, 0x64FFCAB601DF2543ULL, 0xBB582F8C429CBDFDULL, 
            0x46F1807BB9A80FF8ULL, 0x3E80DE3A99493D21ULL, 0x2C25FC808068248BULL, 0x21D97266FB56099DULL, 
            0xE76C171C1F27016EULL, 0x17ACD40908108A7BULL, 0x56EF026C772D39F3ULL, 0xE0B87ECB31710E50ULL, 
            0x1871F54115AD35CDULL, 0x76B8AAC8C9F7239BULL, 0x121BA6A4C7855C09ULL, 0x0836FF9797822A71ULL, 
            0x7CAA608FC4783AE0ULL, 0xEAA3D6A82FA71C13ULL, 0x9C914FE62A92EB2CULL, 0xFD30EA99ED703872ULL
        },
        {
            0xD0DA0BCB8948269CULL, 0xA11420002C34C64EULL, 0xB2B735DB7EE1C8CEULL, 0x71B20B53B1E9968CULL, 
            0x1F9AE019EF35F45DULL, 0xB4316B25A3D601C9ULL, 0x733A86D26C6013CFULL, 0x97B5D274D4DF6076ULL, 
            0xAD870D624A9E6B82ULL, 0xAA98CA91DCA2C674ULL, 0xFB0AFE7C8BB59A89ULL, 0x2311162F85E749B2ULL, 
            0x7013E36B819A1EF4ULL, 0xDD1E87D12921C921ULL, 0x98D732C13231C19AULL, 0x95B8A39EAA404D4BULL, 
            0xECB05884600F724CULL, 0x0D2737CFD1AA7A49ULL, 0x954F1C6A2BC64DEBULL, 0x53EF38C037C1205FULL, 
            0x21F9C12A6D733A3EULL, 0x08CBE0DFA801BE22ULL, 0x1B723F22ABA81875ULL, 0x57A2FB2E2C35BA7BULL, 
            0x5EA005C45B332298ULL, 0xB32BE3EF81A0F87CULL, 0x68238AE6F4461565ULL, 0xA5D769DDE072372CULL, 
            0x6B12AD26CFF204FAULL, 0xC0E105B801D6DCDAULL, 0x08AC1569AE477B77ULL, 0x287F1C9F0CDE7D0AULL
        },
        {
            0x5FD17694E1EB8D8CULL, 0xC6B35932FC25F4F4ULL, 0xD4BB257A9818D022ULL, 0x2AC03E22215794F1ULL, 
            0xBA6EE0A695F9CDCDULL, 0x08157B41EFB5E962ULL, 0xA55F4301455C8A8BULL, 0xF3C435494E143142ULL, 
            0x4D8D867375D42B32ULL, 0x5A4A0649752AE7EDULL, 0x789E7460B487859FULL, 0xE83139A2A8D57CBDULL, 
            0x63902F78E6A1A9EFULL, 0xDC2DD84A3D28AD1DULL, 0xA009E6F5FEFB84E8ULL, 0xBC0785641AAD1756ULL, 
            0x3855936830A9DD04ULL, 0x841AD8E0925E56CCULL, 0x19786DB199F213A3ULL, 0x79ED0AF61DA3D137ULL, 
            0x476616A83FA768BBULL, 0x10189C7929040A37ULL, 0x59166275A89D06CAULL, 0xF3C95538C5F1021BULL, 
            0xAE8B8625AF0D1D26ULL, 0xD520EA842E6BE426ULL, 0xC8C0879F2E7FC41BULL, 0xE705B9017E239990ULL, 
            0x613F2232F798549CULL, 0x6A934BFCC3A0CF20ULL, 0xD90B243964E1CCD0ULL, 0x81462C2334F3AEA8ULL
        },
        {
            0xB68ABE64FAFBC4B4ULL, 0xA63D3ECB6D58A085ULL, 0x1EFAB713C926B12BULL, 0x7C1031CEC3B56D35ULL, 
            0xC9B70CAA187044E4ULL, 0x05C7466E34A4B699ULL, 0x538C9DA543B29EB7ULL, 0x5153E48A20399C8AULL, 
            0x816382D0A98CA2E1ULL, 0x39480F6668D20972ULL, 0xA1B7CB15F9025575ULL, 0x3929A89EEC963130ULL, 
            0x0B5FC3216F858C4CULL, 0x609480F568000993ULL, 0xEE181F4375D87F2CULL, 0xDAC7D48FA79FD2F8ULL, 
            0x940BDD30A91E142DULL, 0x2BF39A67B86DC18FULL, 0xC04EEE19C97FF19FULL, 0xB174C914A37F0DF8ULL, 
            0x22C58E5F9C8BF969ULL, 0xD22F2C76D9A712F5ULL, 0xFDC31AAC8938572CULL, 0x849018AE1CF1170FULL, 
            0x99956E90AAC1238EULL, 0x0FB4C2F47AAC13E5ULL, 0xCF7A3A2A01A40B81ULL, 0x6CB7A20DC7422A8EULL, 
            0xD7AFABF6BBB46451ULL, 0x687A8DCF35530A5BULL, 0x050C134FF9092A44ULL, 0xB2B920CF4519DE7AULL
        },
        {
            0x42F1FE66DF8D894AULL, 0x274A6B79E171490FULL, 0x5FA778B35B9E0431ULL, 0xBE93D4E43B29AFADULL, 
            0xC6D65A9FECA24B1CULL, 0x4F8B50C6BC00BB61ULL, 0xDE0E46C6BC1B8408ULL, 0xA4541A92090FE536ULL, 
            0xDC0E4D993D470DFAULL, 0x8E5AFD1DF2964872ULL, 0x960139AF57CA6502ULL, 0x6623C5A638A13F14ULL, 
            0xFCB4439A953CE01CULL, 0xAA5111886EDC4A3DULL, 0x1587DA73FAD528F6ULL, 0xB3FE7512BA8875CAULL, 
            0x515EE2D602F3E964ULL, 0xD23F2C6EFB0AD2CCULL, 0x5A5F6852CED9CF23ULL, 0xB624EF2286932985ULL, 
            0xA9610FC27AF4E8B3ULL, 0x581DB29833408F68ULL, 0x5C93E34950AC859AULL, 0x201D4F967D4FC64BULL, 
            0x2334CACC9C602377ULL, 0xF43A88E31906F98BULL, 0xD26AD5610BD3B6C0ULL, 0xC31EA30BDAE363F9ULL, 
            0x4199A1EB6AC454E1ULL, 0xFE3614EBE7D7FBE8ULL, 0x8B034EF754AB0DB9ULL, 0xC0DF1B8DD0ED91FDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseGConstants = {
    0xAFC9514A0D8483BBULL,
    0x20433B5C4FF12144ULL,
    0xB25E1E8FD1D13B84ULL,
    0xAFC9514A0D8483BBULL,
    0x20433B5C4FF12144ULL,
    0xB25E1E8FD1D13B84ULL,
    0x4B95262097058CC2ULL,
    0xB640B771241FF920ULL,
    0xE9,
    0xB3,
    0xBA,
    0x20,
    0x41,
    0xBF,
    0xF0,
    0xE2
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseHSalts = {
    {
        {
            0xE5027B510319D387ULL, 0xBCA4DD4CE21A7D39ULL, 0xDA4DB4BF1E21BFB1ULL, 0x83F434E69165CCDBULL, 
            0xE3DD5A42F37EB1E5ULL, 0x853981B13E5DF508ULL, 0x2EDCE2AEF7100011ULL, 0x02A8BC32209AE415ULL, 
            0xC0EDBB73E67D7A67ULL, 0x0F3FCF9BAE3CB3E1ULL, 0xC94258C083F409BEULL, 0x98E43B06DEBE231EULL, 
            0x6FABB537AB05C824ULL, 0x7B22D0AB295CEFB5ULL, 0x4ABDF959FEDF3D50ULL, 0x46FF712EAD227071ULL, 
            0xF2F4FA1E4EC12DDCULL, 0xDEDF12AAC8043F4BULL, 0xD7403F6E8894CEE9ULL, 0x74D94439584987BBULL, 
            0xEF87E61EF3FBAF12ULL, 0x9FDC68E6AD8A11FDULL, 0x7297B3CC278A81F6ULL, 0xD1D3C6CE6CE0DD1BULL, 
            0x3F251CD22B0F0D7AULL, 0x306A4AFA786B6F45ULL, 0x334987501EEC67BDULL, 0xDDE897891F9942ABULL, 
            0x8CEDBBDFFC2E9B26ULL, 0x43D56E7B603F9748ULL, 0xFF6FDC8C407720D7ULL, 0xE6B1BE2B6BABE26AULL
        },
        {
            0xC41DC4C01D1ADE67ULL, 0x01DEC46B56DF786DULL, 0xF1E0B4C2AB84D62CULL, 0xCFF09238F4396F19ULL, 
            0xCA143C550644DBEEULL, 0xFD3599C5576C6F21ULL, 0x70210E42905D70D6ULL, 0x22377BE58B54B5AFULL, 
            0x56601B14CB6D90AFULL, 0x20DBCD85A026CBC7ULL, 0xEACFFB5CC59E7A88ULL, 0xA975C1178354CC91ULL, 
            0xB1BA956C1CFCF65AULL, 0x280E6AC2BF648BAEULL, 0xEC4B52EAC3E816CBULL, 0x76A3CFA3B5937ED9ULL, 
            0xDE1E7339142DC852ULL, 0x752334C0B0ECB4A8ULL, 0x4E73B97869B3A3DAULL, 0x8D21A39CC187C65AULL, 
            0x7A6982275E910DA2ULL, 0x62CA6005933E0843ULL, 0xC7D3913463725F05ULL, 0x753F6CF7FD16798DULL, 
            0x08748534DA576A7AULL, 0x6B0C4DDA836991BEULL, 0x951F4DD131E351F3ULL, 0xD1EA761B298B2EBDULL, 
            0xCC4AA74C307E0074ULL, 0xBC1ADC2C6C6AA270ULL, 0x99AA8CC767EBDEFFULL, 0x76EE1FB18A524435ULL
        },
        {
            0xB11F8B523DCF4632ULL, 0x690072F7B74D6EE8ULL, 0x44FC8FD788D1FB38ULL, 0x0585A559FE8ED5EBULL, 
            0x97E1C24A4C5FFAC6ULL, 0xA7589D3B90100BF0ULL, 0x14776586E7A28E07ULL, 0xDEF5BBB7D0DBE264ULL, 
            0x12672B255D7D77D7ULL, 0xC858756406C6C7B1ULL, 0xC3BF7852833693A6ULL, 0x9FACE30630913170ULL, 
            0x08B64F3411D3E958ULL, 0x72E7ECEF0AD876F3ULL, 0x4F2E1E85FDC62793ULL, 0x75E6BF6E80EE0051ULL, 
            0x21EC0A3387466CA6ULL, 0x521FB65245BB1F38ULL, 0xF5D848C185680305ULL, 0xF4B5D59AA5B482E1ULL, 
            0xD2CB60B7B898F5C7ULL, 0x09D405A28CEBE6D6ULL, 0x04DF59BB78FA271BULL, 0x5877904E84D153C3ULL, 
            0xB120BAD32168D991ULL, 0xB3DBE7BAF42DA81EULL, 0xDBB819EF1310F8A3ULL, 0x02F46C1552E8068AULL, 
            0x9D068B01AA44669DULL, 0x459E78E1788C9B13ULL, 0xF0ED3B90724A4862ULL, 0x2A7BD72A68785452ULL
        },
        {
            0x1298E0C38CD25463ULL, 0x2BF2AEC053B2B04CULL, 0xD09159939F257E6BULL, 0xC28458F1426D116FULL, 
            0xE00E7A86B7CE6590ULL, 0x947D97C6B3FE0A7AULL, 0x4CC05F00F04FBE37ULL, 0x1787AE5B51918DEBULL, 
            0x09778534BB20D726ULL, 0xB5617F4B19F611ADULL, 0x41CA421CB881ABF7ULL, 0x2A5E935889C3FC6FULL, 
            0x3F9532EC30C4A738ULL, 0xD2F65918D075E49FULL, 0x6FC6EA8402263364ULL, 0xE73AC38EE25B6EB6ULL, 
            0x013A4F6E5583E5A8ULL, 0x78F307B2BC842239ULL, 0x01CBF0C1D91DF596ULL, 0x2D5399AB082B67B4ULL, 
            0x083B8270C626B37DULL, 0x723E9254C82B3541ULL, 0xE530845DE9E08644ULL, 0x04D887A3FC6AACA9ULL, 
            0x553DC548946BC97AULL, 0xE78EEE0402C05E74ULL, 0xD6FF21FD61263FD2ULL, 0xECB71DFD2096AE7EULL, 
            0xFB152D9ABE7CACE7ULL, 0x40229EC0F3A9F74DULL, 0x4907CBA9E0A4A2C3ULL, 0x0695619D8794BBBBULL
        },
        {
            0xEE562280D32092E0ULL, 0xA445BD01FCDBA250ULL, 0x98152E73B93D21D6ULL, 0xEFF5590E709866CDULL, 
            0x22E0CC36A5486B34ULL, 0xBFA3E409DFE3EBD6ULL, 0x7640A04F8A80581CULL, 0x0BA9E4BA161AA466ULL, 
            0xEAF1072B134AA928ULL, 0xE970EE59CFD4D17DULL, 0xB07BAAAE263289B8ULL, 0xE926381E06239314ULL, 
            0x23065661FA3B3553ULL, 0x378CC61BF9C2BF73ULL, 0x9DF7ABCFE537F198ULL, 0x20142F24C4681D91ULL, 
            0xDE5DAEE5A4E04408ULL, 0xD84A878EA69C1976ULL, 0x8F55E6D19BAC2F3FULL, 0xE8EF7154AC8ACDB8ULL, 
            0xBC7D326C86A78064ULL, 0x9855BC3CD44B2238ULL, 0x212DF634C8264B52ULL, 0x694A487C8A797E61ULL, 
            0xA1E57E7940A469FEULL, 0x0B2FC8DF5B605B44ULL, 0xD9B89B1B88B5939AULL, 0xC52A36D329EAC915ULL, 
            0x8BFDED60B77F97CEULL, 0xAC4449BC655C74DBULL, 0xEB651B47F43BEDDDULL, 0x934AACAE0287DDE0ULL
        },
        {
            0x205F3B27A845B8E9ULL, 0x9804C549AB2594D3ULL, 0xA14D6A0C2390F39CULL, 0x0EEBCD749934C8B1ULL, 
            0x009048882D3E3529ULL, 0xFEC4E5F7E06BAEACULL, 0x84BF18066F2E8F6FULL, 0x20C20074B6485431ULL, 
            0x72616A582F3C1A3DULL, 0x7505CFEBAAF57394ULL, 0xA221E61F6AAF5B23ULL, 0xF52B0BA6AE3842C9ULL, 
            0x2F865E0926B6BDA7ULL, 0x429DBBADB47677A3ULL, 0x477A5363EE40C4B1ULL, 0x648647F3AD9B2E84ULL, 
            0x075018863ED48384ULL, 0x0C1EFDDFDA073FAAULL, 0x6996F2B36D8BBC6BULL, 0x0C8E60793606C684ULL, 
            0x73A3109557D1F25EULL, 0x89C47643DEB25051ULL, 0xE23C9C76E320C092ULL, 0x4444B6D95B3B8349ULL, 
            0x29BB4F1451490616ULL, 0xD0BDA443DB261049ULL, 0x4515920D5191743BULL, 0x1865B672FCF0A37EULL, 
            0xE0807DDB239832F8ULL, 0xA7FC7DCA98E8F280ULL, 0x6163F502348BE430ULL, 0x3AD2511E308D9582ULL
        }
    },
    {
        {
            0x49E229CFABCE68DFULL, 0x0594323E5598264EULL, 0x13E3BFE7D2CBA12AULL, 0xD1F0E17B567EC202ULL, 
            0x64D211E576B6BE77ULL, 0x29D4DC02325EEB2CULL, 0x6DC06066586F7ED4ULL, 0x0188F6DAB7C6F4F6ULL, 
            0xE7881EE9CBA5D39AULL, 0x51C57A8F1D097B90ULL, 0xF48EB87CDAA81070ULL, 0x972FB94F663FF68AULL, 
            0x63F8AAB27EE9E704ULL, 0xDEADA9A74358AE85ULL, 0xF76F95A245B69298ULL, 0xD71B9B5E6DEE4B61ULL, 
            0x57642EC27CD35E62ULL, 0xFA84FA05F5EAF896ULL, 0x162A01B2600173CEULL, 0xB3D19D01307B5123ULL, 
            0xC52BC2D558C882F6ULL, 0x236AE66DEAC5AD12ULL, 0x7337CF2A171CC29DULL, 0x8B3E2E94AA7893C7ULL, 
            0x982CEB2AEFA98BF1ULL, 0xA20AF0AF7637B2BBULL, 0xFD8CBACE9BB40987ULL, 0x54712C505FE97DB9ULL, 
            0x175FB1EA0118F80AULL, 0xA3556F55983BDCDFULL, 0x78B89FDDDCA7BDF9ULL, 0xC085811D7EC10AC2ULL
        },
        {
            0xAD63CCB74CF49DD1ULL, 0x4F8BB10F275425C4ULL, 0x775CFFB3220FE48FULL, 0x5AE57BC67EE13D78ULL, 
            0xA410DCAA19995332ULL, 0xA2AF21CEE5B4E0F2ULL, 0xB6BA8E014F568F10ULL, 0x9205EA6F800366B9ULL, 
            0xAB5304752017DBCAULL, 0x70C745F61F7F4465ULL, 0x70713C878186D790ULL, 0xA30345CB3E450B94ULL, 
            0x7121EF8791738B38ULL, 0xF1175A6DD8515196ULL, 0x800F23F90700E3C5ULL, 0x3BB31516056B0D00ULL, 
            0x3210DC1F12BF2C31ULL, 0x2D78E18728870EBAULL, 0x4D013BCAB78AED93ULL, 0x5CE5F8EF3540F6FBULL, 
            0x89036EFF4435101EULL, 0xA16194862568198CULL, 0xD7E06CC4123719F7ULL, 0x4EAC416EFB0C5658ULL, 
            0x7428430B7186DC8AULL, 0x766D4FE46CACD12FULL, 0x0EF798C54F1616C8ULL, 0xB446F14DC8A038E2ULL, 
            0xBB3BBEF088AF2EAFULL, 0xD2036BC3C16AFFC2ULL, 0xA1EE334B81F1924EULL, 0xA713C05507AB557BULL
        },
        {
            0x202EB4E9B9DC9084ULL, 0x20F83EB84CEE01BCULL, 0x76CE368B227BD6D9ULL, 0xDA76A363C37488EEULL, 
            0x2E92B36075F0B9F7ULL, 0xB5C4B77C39275977ULL, 0x14B2985CEB5676A6ULL, 0x7919989D9019B803ULL, 
            0x8C517738587D9632ULL, 0xDC294F1586924058ULL, 0xC1555B8119BB1D94ULL, 0xDA4D820D522FFB8EULL, 
            0xF7DB17B3CD2BE095ULL, 0xD32E64EC0E359D6FULL, 0xC4FC503D170AE834ULL, 0x8C41D34D24973886ULL, 
            0x6B15F1FF1B3078F2ULL, 0x0758EC85BD670E75ULL, 0x827BB5F517384EF6ULL, 0x7C78FF3436DCD9A0ULL, 
            0x9AC1887CA01432DDULL, 0x2D2E461773131716ULL, 0x8E6D77EE2CB17F55ULL, 0x33D27DDAA8786328ULL, 
            0x2F1BAE3A0BCFAB30ULL, 0x5A40E1CFF49DB6F3ULL, 0xFAE5986A07261EF2ULL, 0xF579529F778AA96DULL, 
            0x85E0942B476E73BAULL, 0x3C653C4310EE7EB1ULL, 0x604E14D5221794BFULL, 0xE45B6A75BBC97043ULL
        },
        {
            0xC8ED8B0E717BDD2DULL, 0xC2A01A5051A51CABULL, 0x0278E07780AF24C9ULL, 0x896E848E7A0D4436ULL, 
            0x7B5ABAC89EBD0BB5ULL, 0xD912ECAFBB23429BULL, 0x97081536B66CFEE7ULL, 0xF2520F7ED370F02EULL, 
            0x49EBD0F9E67BA4D1ULL, 0xEB40235A22282B01ULL, 0x269A55DDCEBC62DEULL, 0x68AF2EF4BE161CD4ULL, 
            0x24F917B3DC85281FULL, 0x6E5C3C8577D3F7FBULL, 0xD513E2E349FBC956ULL, 0x199BD03372FE6081ULL, 
            0xFC4D558A7DDF3B36ULL, 0x569E3654ADD50E59ULL, 0x2C0E02B9932A27FEULL, 0xD8B002B1810CA5D5ULL, 
            0xA386E581AC8E75FAULL, 0x61508792F36ECF19ULL, 0x2B727BD22494E778ULL, 0xBA60BB3B9ECC0CB5ULL, 
            0xA61FDD55DD20D2FBULL, 0x2899FC8C40A47923ULL, 0x05D9E4E9F19C38E6ULL, 0xAB309851385A3D16ULL, 
            0xE7F83032FB5EF1B1ULL, 0x93689178CCB9FA13ULL, 0x317AA43552887EDDULL, 0x66297FA4B173175CULL
        },
        {
            0x8A9B9247E3A8B211ULL, 0x7353174F6E5CD5DEULL, 0xDCD7E261AE3349EAULL, 0xBB8F3725F5350F21ULL, 
            0xF1FB7C5C728C5FE2ULL, 0xC306D952DCB233B1ULL, 0xB2C22026D9830B95ULL, 0x38FD51DE4AF050ABULL, 
            0xAFFA2B9449D674BFULL, 0x0F4279F69A390318ULL, 0xB798A326B1ADFC51ULL, 0xA4CEF3FA0EB02E16ULL, 
            0x32A85B38FB6E0F9BULL, 0xC4239D9C6B5CE256ULL, 0x08A70080762A1A94ULL, 0x025E1C269E874969ULL, 
            0x383E3B750487BD9DULL, 0x74974DE4DD657662ULL, 0x0049D5D50D58898AULL, 0xC1116FCD1E8A8525ULL, 
            0x01DA9D8B8E5B1148ULL, 0xDBC6834ECD9A7DF0ULL, 0x12AC5C27BF45F15DULL, 0x9A9B746AAA7BC315ULL, 
            0x069B6183773459FAULL, 0x36AFA5043C9ECB87ULL, 0xEDAB13C10E8C56E4ULL, 0x8137B5F36B0E2DC5ULL, 
            0x0713CF7F68425978ULL, 0x19F867AEF11A3B50ULL, 0xC690DF3C3F760772ULL, 0x513291991795CA88ULL
        },
        {
            0x2229DBE0F2CFB49FULL, 0x1FE0D3F01724B921ULL, 0x94C30DA6C9B1FD68ULL, 0x9EBE2D14D768360AULL, 
            0xFE454D5A3A70A540ULL, 0x6CB00FF6C5DA9AA2ULL, 0x8A8CEF23E3B045B3ULL, 0xE26B28C1B092B185ULL, 
            0x5B1C009639F5B709ULL, 0x9AFC716D26F83E2BULL, 0x3C436BB1E2F62C7EULL, 0x629D4256CC289B3CULL, 
            0xA7E9595F01AEC708ULL, 0x6572DD7B28D277A5ULL, 0x5D7E64F929D27E62ULL, 0x038B07077638D97CULL, 
            0xD6EECA797B929395ULL, 0x9FC2353203AA2FDCULL, 0x58A22A64D58DAA1BULL, 0xC83A460C018F16D6ULL, 
            0x4123CF9635348E8DULL, 0xDEBC24C725ADFBB0ULL, 0xEB2989EFDE920B5CULL, 0x8055B7A3F341C5B5ULL, 
            0x7ED9D4AA45E4D496ULL, 0x303A38E25E26252AULL, 0xBC24C360C7B6F1B1ULL, 0x5C218234600DAFE6ULL, 
            0x7F158A707442F834ULL, 0x41E8A2F6C5761D5DULL, 0x172412485E23528DULL, 0xE4EAC418B9D00914ULL
        }
    },
    {
        {
            0x907C545AE956E456ULL, 0x682B13BA7F2F2493ULL, 0x4E67A017D1668DDAULL, 0xEC41B5038BE0D2BCULL, 
            0xF9F86051CB4383C6ULL, 0x11740E0D21F035C9ULL, 0xEF6384A2EE91C5F8ULL, 0x737834841C394177ULL, 
            0x27C12E6F563E3DE0ULL, 0x25C6D982D94D4FE8ULL, 0xB04199B020024396ULL, 0xAEC072A0681B97E2ULL, 
            0x9816AECED8EAA259ULL, 0xF39DF9BFFA63603FULL, 0xBFD79E8B4E0F2A57ULL, 0x7DE6D3BEA9D72652ULL, 
            0xAF1AE328A11EFE01ULL, 0xDFE3791F0B9606C4ULL, 0x5BDFEC8EDCBE8F31ULL, 0xEFA03C78B370E5C5ULL, 
            0x2844567AAE13307EULL, 0x7C8F71246D1DF9E3ULL, 0x7713C8C2926F386EULL, 0xA57B237D3A83E04AULL, 
            0x46B238AF569C6412ULL, 0x4DF0A7812BB6BAC6ULL, 0xA13791193ED895D9ULL, 0x025E9C044E1C3464ULL, 
            0xDF2C09537D4BE5CBULL, 0x3A589B3FD6875145ULL, 0xCBAE10D20E632DB1ULL, 0x89FF49C0C9C43015ULL
        },
        {
            0xBE0B4F4A698725D1ULL, 0xF39A282C4A9F4F59ULL, 0x73803014864E593BULL, 0xFFBD0B8FF8F4E24AULL, 
            0x1D8CC09384BE0472ULL, 0xAD14555352B28C66ULL, 0x7E7BE4C6482C69AAULL, 0xEB8ED40501B85C27ULL, 
            0x15F67CF40B1D926BULL, 0xF63FF1B2F80F3174ULL, 0xA7BEC8F5F1AB8025ULL, 0x1C371B4533E4601AULL, 
            0xCA2DE0C2E0EAA4D7ULL, 0x94085250AC4BAED0ULL, 0xD9259CA05401D6BBULL, 0xE474EF2EB62741C6ULL, 
            0x1AB8BAA2CF0C3BC9ULL, 0x9C8A54B8B63C2E26ULL, 0x445A62C6EE50DD54ULL, 0x0FCB2BEC65D6C697ULL, 
            0x862954ABEDF7F40EULL, 0x54E0718C55A7D74CULL, 0x377854F210A74BF8ULL, 0x8FD94C94CF8F8DBEULL, 
            0x3170C2C5F863019AULL, 0x8CC6D094872FE501ULL, 0x39511DB015466975ULL, 0x4EF795980E8EE83BULL, 
            0x4B658DCEF82D5E9FULL, 0x61AC49ED4B1E430DULL, 0x4367C57C67AD1D69ULL, 0x61C13A8F0032707AULL
        },
        {
            0xB2E5F21FBCAE7361ULL, 0xAD9AC1DC2AC30360ULL, 0x20F537BD933EA838ULL, 0x37C48BCBA99E19AAULL, 
            0x7A4E758D74F04BC4ULL, 0xA85C7F618823FBC2ULL, 0x8C890F2E2BE299EEULL, 0x2D38432FB8497910ULL, 
            0xB3EF533B7D792B6FULL, 0xF9A0AF80F421B7F5ULL, 0xA7CC889D5B7FD0D1ULL, 0xECDD3E96D4662418ULL, 
            0x228CBA70F180057AULL, 0x2B015C0B53CD0F86ULL, 0x9AEE59995C69F417ULL, 0x293ED1DB787E3E76ULL, 
            0x1804C5E836985178ULL, 0xC6ACF5922EC6AEE7ULL, 0xF719D6817886A4DAULL, 0xEDDDEEA501FBC0F7ULL, 
            0x5F3DA61BFB76A5FEULL, 0xB601FCF5644BA711ULL, 0x0C5A45E014F0CC7AULL, 0x24CD0E392C9F9DAAULL, 
            0x0B38E10E24A60C25ULL, 0x1C3E8CE48D759CABULL, 0xF5247650B0322C2FULL, 0xCE842222CA9DF535ULL, 
            0xD18FE6CF2225B9DAULL, 0x533AF8C4F87FB152ULL, 0xD65B2133C046BD91ULL, 0x95AE72B4F960EA91ULL
        },
        {
            0x3105D8737675296CULL, 0xBA2C2C2E1B121776ULL, 0x5837B998F4B9647FULL, 0xF60EA4D4623DD4B8ULL, 
            0x73068A627E5D2F50ULL, 0x0F0A47BDEF799EBEULL, 0x3473D8EE4E3F7328ULL, 0x8E36925BEB00037AULL, 
            0xD00903645D71E1E0ULL, 0xDEDCC9908EFB5DE3ULL, 0x7A64874B5555FB55ULL, 0xED9AAA03CDAAC2D2ULL, 
            0xA0834AEA7050AB5EULL, 0x40398B722FDB926CULL, 0x346AD692850E96CFULL, 0x91118684E202836FULL, 
            0x93057038BCE87A35ULL, 0xB01962ACB020809FULL, 0xEC745F5C9C99EDA1ULL, 0x60C81EC58CC04A58ULL, 
            0xB53CDC308F54D1DAULL, 0xC89F7C7CA7ECE0A8ULL, 0x091236FB013B8E12ULL, 0x5D4991CFB1933D2BULL, 
            0xDF153FDFAC445A80ULL, 0xB957B368D21792DBULL, 0x7103C84C4CD6F1E9ULL, 0x9B45BF42F87F6B16ULL, 
            0x6AD548B8C909A213ULL, 0x2BFDF6EC8AA6E526ULL, 0xA52ABE38B2C0483DULL, 0x6AFB3DC9C7DACC84ULL
        },
        {
            0xD0C64ACFAD0B86BCULL, 0x072033254FB7556FULL, 0x5962FD110E50A661ULL, 0x2D7444F6D02607F8ULL, 
            0xBB3FD681DAE63C6EULL, 0xAA34C7F6ED6ED7DEULL, 0xFA29B9A7D4863F77ULL, 0xF9C177931FBE1787ULL, 
            0xD02893FA12900CDCULL, 0x6A8B4D40CAFEF793ULL, 0xD7D8B7D318AFF2D3ULL, 0x4635169EB55B2226ULL, 
            0xE86F9668D79D0EFBULL, 0x0508945CF47A5E68ULL, 0xFF21E390332C4D0EULL, 0x74A24E7AF6DAD697ULL, 
            0x1C8F7BED365DF463ULL, 0x501FDDF3124673DDULL, 0x73DE402E86A8BAB4ULL, 0xE54DBE8912243AF4ULL, 
            0xFA606DE20F1EBE8AULL, 0x1EAAB2231B9482E9ULL, 0x9B6591CDCADBC47AULL, 0x61913780F81C8BB8ULL, 
            0x626D537CFEEF25B0ULL, 0x98BF212E8A4731DFULL, 0x5C21988F94C03D1BULL, 0xB6FE694795313DACULL, 
            0xCAC09E91E387B9E0ULL, 0x829E42E45BC6FD86ULL, 0xA7B9CFB1B760C9DBULL, 0x0A7CFAC725986E24ULL
        },
        {
            0x1A9D6132C87E91D0ULL, 0xAEFE308D74DAE0ADULL, 0xC0674784808E2FF2ULL, 0x81CCD4D6C69F2015ULL, 
            0x3EA55CA107E7E623ULL, 0xA1D26AA8B8451F26ULL, 0xCAF59618CD32C5FEULL, 0x03517F1DB9C4E634ULL, 
            0x8FCFD10B67552F02ULL, 0x30D5FA97CEB0D540ULL, 0xE197F784BEB615E3ULL, 0x89E445F12D161D77ULL, 
            0x84E2FBD9B19E3705ULL, 0x2010EAFB1FD72500ULL, 0x32D62B0CC208926BULL, 0x284855D56CC5EAA3ULL, 
            0xB7814C1477D9C54EULL, 0x347D60E10CCA484FULL, 0x97ADF02981218599ULL, 0x6A3273AE99BB87FFULL, 
            0x695883B2BA03F758ULL, 0xA460292775CA43F3ULL, 0x28C42C2557C8BCB1ULL, 0x76A10BC044EDE3DAULL, 
            0x3DA1424A72A39CBEULL, 0x2266EF0486B9ED8FULL, 0xC1D28BD43C5AFA7BULL, 0x15A1F0153B2C3287ULL, 
            0x613DF47ED09299D2ULL, 0x092210A184A883E6ULL, 0xB077410CF245B44BULL, 0x70898F165BA62418ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseHConstants = {
    0x8517E927893EA9EAULL,
    0xE61EC8FBA6B7EE3EULL,
    0xE59C45BF5C0D387AULL,
    0x8517E927893EA9EAULL,
    0xE61EC8FBA6B7EE3EULL,
    0xE59C45BF5C0D387AULL,
    0xDF6584D07B20E063ULL,
    0xBB2DFED1D55CA071ULL,
    0x7E,
    0x99,
    0xA0,
    0x20,
    0xCF,
    0xCD,
    0x26,
    0x7E
};

