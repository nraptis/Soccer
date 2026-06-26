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
    std::memcpy(&mDomainBundleEphemeral, &mDomainBundleInbuilt, sizeof(mDomainBundleEphemeral));
}

void TwistExpander_PickleBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 16922591448971425256U;
        aCarry = 10113078555345013684U;
        aWandererA = 13841602610815986475U;
        aWandererB = 9997750448943587274U;
        aWandererC = 13093136035015251984U;
        aWandererD = 16560609358612028240U;
        aWandererE = 16212049122536930083U;
        aWandererF = 11368778134587273436U;
        aWandererG = 13381770523884747389U;
        aWandererH = 17158739892663755374U;
        aWandererI = 12257734482654235547U;
        aWandererJ = 14609622008661873199U;
        aWandererK = 14389386981433188506U;
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
    TwistExpander_PickleBall_Arx aArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_BArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_CArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_DArx;
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

void TwistExpander_PickleBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14725461395573765556U;
        aCarry = 11804053978116434530U;
        aWandererA = 14367108573526285349U;
        aWandererB = 10946824880502610968U;
        aWandererC = 9251680896358590123U;
        aWandererD = 12776792461632088258U;
        aWandererE = 11312600641070316038U;
        aWandererF = 10840465844990739396U;
        aWandererG = 13291623885393718983U;
        aWandererH = 17829426945743535618U;
        aWandererI = 12241300138238295923U;
        aWandererJ = 15967298825109153049U;
        aWandererK = 17443008127957529566U;
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
    TwistExpander_PickleBall_Arx aKDF_B_AArx;
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
    TwistExpander_PickleBall_Arx aKDF_B_BArx;
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
    TwistExpander_PickleBall_Arx aKDF_B_CArx;
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

void TwistExpander_PickleBall::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneB;
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    }
    // KDF_B PhaseA invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseB invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneE);
    }
    // KDF_B PhaseC invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseD invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneA (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    }
    // KDF_B PhaseE invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseF invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    }
    // KDF_B PhaseG invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseH invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
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
    TwistExpander_PickleBall_Arx aSeed_AArx;
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
    TwistExpander_PickleBall_Arx aSeed_BArx;
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
    TwistExpander_PickleBall_Arx aSeed_CArx;
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
    TwistExpander_PickleBall_Arx aSeed_DArx;
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
    TwistExpander_PickleBall_Arx aSeed_EArx;
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
    TwistExpander_PickleBall_Arx aSeed_FArx;
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
    TwistExpander_PickleBall_Arx aSeed_GArx;
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
    TwistExpander_PickleBall_Arx aGrow_AArx;
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
    TwistExpander_PickleBall_Arx aGrow_BArx;
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_PickleBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_PickleBall_Arx aTwist_AArx;
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
    TwistExpander_PickleBall_Arx aTwist_BArx;
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
    TwistExpander_PickleBall_Arx aTwist_CArx;
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
    TwistExpander_PickleBall_Arx aTwist_DArx;
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
        TwistExpander_PickleBall_Arx aGrow_AArx;
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
        TwistExpander_PickleBall_Arx aGrow_BArx;
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

void TwistExpander_PickleBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 1, 3 with offsets 6009U, 1862U, 197U, 529U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6009U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1862U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 197U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 529U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 0 with offsets 8030U, 4223U, 2396U, 630U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8030U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4223U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 630U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 0, 1 with offsets 6880U, 7532U, 4239U, 4842U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6880U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7532U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4239U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4842U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 2 with offsets 8025U, 2487U, 2184U, 7958U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8025U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2487U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2184U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7958U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 468U, 584U, 1883U, 158U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 468U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 584U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1883U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 158U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 2, 0 with offsets 92U, 627U, 1492U, 733U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 627U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1492U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 733U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 1, 2 with offsets 1535U, 201U, 1885U, 256U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1535U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 201U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1885U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 256U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 911U, 1810U, 790U, 1192U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 911U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1810U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1192U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 2003U, 623U, 4U, 676U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2003U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 623U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 4U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 676U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PickleBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 0 with offsets 2907U, 7650U, 3103U, 3469U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2907U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7650U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3103U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3469U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 3 with offsets 810U, 5209U, 5236U, 1444U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 810U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5209U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5236U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 2 with offsets 7349U, 993U, 8174U, 4902U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7349U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8174U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4902U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 2, 1 with offsets 5683U, 6973U, 4961U, 1039U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6973U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4961U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7928U, 7836U, 1375U, 5046U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7928U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7836U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1375U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5046U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 2, 1 with offsets 72U, 2026U, 960U, 1217U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 72U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2026U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1217U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 0, 1, 3 with offsets 629U, 1328U, 1624U, 1359U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 629U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1328U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1359U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 1, 3, 0 with offsets 1005U, 1419U, 415U, 18U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1419U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 415U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 18U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 1, 2 with offsets 1260U, 818U, 173U, 878U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1260U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 818U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 878U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 299U, 1983U, 1707U, 1103U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 299U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1983U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1707U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1103U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseASalts = {
    {
        {
            0x85A0F50EE895A3C4ULL, 0x5FF15C0A3499B80CULL, 0x18B2A8C68300E11EULL, 0xA32AC2A5FF87024BULL, 
            0x156483A30D85273BULL, 0x63261C2F91F3F1AAULL, 0xA74AF113368633B4ULL, 0xED1B31CE09CC691CULL, 
            0x27971F413934731EULL, 0xF765EF69109C58ADULL, 0xCD1ED06A302F4A66ULL, 0x9177BB4FEC2696B5ULL, 
            0xB2C0E82804675463ULL, 0x39FAC10E5F461813ULL, 0xC0B98C5DDD7A949FULL, 0xDF7DE0E506E62705ULL, 
            0xBC0591E3420D3B99ULL, 0xD3FAF7A7D2B329FDULL, 0xFFDF65B6E571FA1FULL, 0x9A269EAAFE038619ULL, 
            0x8507B9B2A0D996CFULL, 0x57E25A779E0F761DULL, 0x9CCE457E6C2D4E4EULL, 0xDDCFDA6AFD37A876ULL, 
            0x7CE6D7B803F975A3ULL, 0x46EF2C438FC57B4FULL, 0x556BA91EFD2605AAULL, 0x0133AC044190E4FBULL, 
            0x5205F6CF97619C7DULL, 0x27C6B9920551F119ULL, 0x9B5D0FDF5DDD2FE9ULL, 0x1A0A3B4B5A13EE02ULL
        },
        {
            0x1CE296223D5AD513ULL, 0x5FA4B89102FFAE88ULL, 0xD67A33D4F1C99EEBULL, 0x89A831AE08CC1C5CULL, 
            0xE64B4FB91BC0409CULL, 0xAB0A9863FB38D8FDULL, 0x570E410BC99525F8ULL, 0xA2B84B2E60330D0CULL, 
            0x87A71ED7FBCF7D00ULL, 0xA463ACC302509450ULL, 0xC1C1F338060DB858ULL, 0x8210268FF03AD004ULL, 
            0x5ADF33CE4D550B06ULL, 0xBE44CE98AFFB8090ULL, 0x21EB6320D5D541C8ULL, 0xAA7B4EFD6F9D1777ULL, 
            0x2871B67D5DB765D7ULL, 0x5D080BBA57A3A8BCULL, 0xD65E8DA4C9730FB2ULL, 0x3840D353E2447023ULL, 
            0xF2D2CD593836DD50ULL, 0x2B1241902F8A6C75ULL, 0xCCFDA155252C720CULL, 0x33896FD1180F095DULL, 
            0x5D4A16E9C8BBC54BULL, 0x5FD8D9A3FD86C249ULL, 0xAC635E5C3AC11D25ULL, 0x7293FA03EB1E7D10ULL, 
            0x218615CADA8A4B2CULL, 0xB4FF70B0D3493C57ULL, 0xC4419332DABA7FCFULL, 0xA34E5CA635F24990ULL
        },
        {
            0xAAC3F2B70A0247CCULL, 0xDD6FC7ADAF060D2FULL, 0x3A6D30C9B05543F7ULL, 0xA4BD1561A56050ABULL, 
            0xCC6FDB9B8B60F5A5ULL, 0x2931E8CB7C468EBAULL, 0x1CA994F3F0982D37ULL, 0x085E8DB78DDEA520ULL, 
            0xC51887AA2B564018ULL, 0x0C0F8239C01BE65DULL, 0x9328D082C1226DD1ULL, 0x8273A43148DA8420ULL, 
            0x50AF0A56639B9905ULL, 0x7D1DF01FF8DA6ABDULL, 0x45D5F59742ED0FB6ULL, 0x64E1567E972BF39CULL, 
            0xC7168FB4CDCB2215ULL, 0xCE3EAEA80BB10E81ULL, 0xA467E0196B20C5F5ULL, 0x97C09175D11CE94BULL, 
            0xED3B0D7175629169ULL, 0x127F977A7EAB0AABULL, 0x5DE10DC56BD86E6EULL, 0x24542DC58085D6B3ULL, 
            0xBEC502896FBCED3CULL, 0x155319DF7461979AULL, 0xA21D4745279AE283ULL, 0xAC59EB014F353BCFULL, 
            0xC6488CAB0A7E3CE4ULL, 0x0C7A12FF44F9EE71ULL, 0x897430650300013BULL, 0x54FFDFE72EBFBECAULL
        },
        {
            0x968619F95D448004ULL, 0xE078A6CC852FA1A3ULL, 0x3777CFE6E70F2570ULL, 0x763B991213E1DF49ULL, 
            0xE5D68714C73080DDULL, 0xB5ECFC3E8137A9AEULL, 0x7DE9A555C445227AULL, 0xDBF28D4C74279AEAULL, 
            0x9A8EBDD3338FDCC1ULL, 0xD6F81AE62EB61D6AULL, 0x0C01CF0B0CAF0936ULL, 0x2FFFF1BB83E9236EULL, 
            0x1D8FAFE7EF312CAEULL, 0xFD6FB86746111AD0ULL, 0x9FAC10462D5FE8C0ULL, 0x6E81E72F31BD04B0ULL, 
            0x68DBF3F9F9F10D88ULL, 0x559D81CBFB805FEAULL, 0xCC734EF460157A62ULL, 0x731B1D6CBB0F2512ULL, 
            0xFD7B6A4D41894FF8ULL, 0x7171FBA1F3A6EDFCULL, 0xAAF3A138120A68CAULL, 0x7A9506EF3BCE862CULL, 
            0x6EB69E8AFDB9BA6FULL, 0xE062904C97B59CB1ULL, 0x816AFBEE6BFBE35BULL, 0x9F3923CB96E73725ULL, 
            0x10D6BD1CAD980ECAULL, 0x5527BEA6CE1B03A1ULL, 0x98041497D5700254ULL, 0xF9BEA2EBF494861CULL
        },
        {
            0x3295A4F7BCD9366AULL, 0x59DEE72D03600260ULL, 0x8CC9371C7176C722ULL, 0x42B9E9D3EF0E351AULL, 
            0xA200F94E044212B5ULL, 0x4CF02B88AE956E3FULL, 0x3713E209C9DEF52FULL, 0xF36D453494B7C5B4ULL, 
            0x4BA4DCDAB98B75CFULL, 0x51E3A4E6DDAE4BCDULL, 0xC5771CEDDF1D9BFAULL, 0x07FA800B02A9CF8EULL, 
            0x3A76D529ADC02A4CULL, 0xBCD5028825352001ULL, 0x405A7549D1C2F7FAULL, 0x8CADAB645F29C1D1ULL, 
            0xAF1CF6D6A39668DEULL, 0x79926602452969DCULL, 0x52CADE3C7E320D73ULL, 0x7E30D5C8A6400D05ULL, 
            0x3590412E3CE46C89ULL, 0xECFE3ECC29379BB6ULL, 0xD34B20BFE911B724ULL, 0x162C54C8FD1254CFULL, 
            0xA0B2190860263ACCULL, 0x144D40D89333DA35ULL, 0xF166F94801E814E1ULL, 0x8AD439E48124585AULL, 
            0x3DB2151675F3A5EBULL, 0xF2C0254B67A5F256ULL, 0x3787B49125E67B63ULL, 0x4A43D7E8D3F45E4CULL
        },
        {
            0xB3C181CF553B1E85ULL, 0x5A4D2DC9A5A22487ULL, 0xEEE81A877F177392ULL, 0x230A175AAF412E6DULL, 
            0x85524149BAD360ACULL, 0xEE06B45EE3D32416ULL, 0xACFB7A04A845685AULL, 0x582D20731DFD9C15ULL, 
            0x35F884D8E17A1D5AULL, 0x853A1491E601C9DCULL, 0xA90471147C6D1ABBULL, 0x49D66416A4C02FDEULL, 
            0x7B03D8EF02CFBA4BULL, 0xFF4A125145EE267EULL, 0x0716E5BABB4B9230ULL, 0xD5565CFB6DF12D8FULL, 
            0x8CE6F26EFEC41197ULL, 0xCDFDA43542066FB5ULL, 0x43CD05E08C7BCD27ULL, 0xC61CA08234784B98ULL, 
            0xDA5D90581767AF4DULL, 0xA755ED8A9578D104ULL, 0x4618B9CA4C85DCC4ULL, 0x69D328394DE71052ULL, 
            0x58A613B2E408DBBCULL, 0xF0EB23A425700E8BULL, 0xDA314C02906FF6FDULL, 0x4AEC18C7924FB7E0ULL, 
            0x422C78757F3D6554ULL, 0x823BECB0BABB2183ULL, 0x8CD412A5CDD370BDULL, 0x4936B7A8EBA287FEULL
        }
    },
    {
        {
            0xB38C768CA749387FULL, 0x668A4CA419F083A4ULL, 0x73134C7CD5124FACULL, 0xBE4158A015F9ECC8ULL, 
            0x5D058D5000E21827ULL, 0x39C82E51144955ECULL, 0xBF00F8F3557B3975ULL, 0x813987B6743CE030ULL, 
            0x3CB1CB3CFF428E52ULL, 0x75CCC935C80B2214ULL, 0xB3AC8A9ED064F012ULL, 0x141B9AA4B6093886ULL, 
            0x644F2FD2B8E05CA5ULL, 0x9280AC90613954C5ULL, 0xC8A9D6B154821DF1ULL, 0x1D17B2C1173370FCULL, 
            0x9D9708A8B57D9740ULL, 0x65EBCD39A7BFA962ULL, 0xE1D656EA489A1E86ULL, 0xC0813E5379FD73A4ULL, 
            0x77839F44F7865BCFULL, 0x40243B18018F001DULL, 0x474BEEFB13831E31ULL, 0x7363C5EFCE64E3DAULL, 
            0x59314441F59976E0ULL, 0x27D87463A7293291ULL, 0x7E1C913DB4DD9F9FULL, 0xCAAC7BC2F004A3EDULL, 
            0x9A21BDC1BA62A448ULL, 0x0298D74CF588BF07ULL, 0x36A3F3625BBA82D7ULL, 0x1D6F3139C8527AE4ULL
        },
        {
            0xED3041F777775075ULL, 0x5AEEDFC1F42D265CULL, 0xF14D15F1CD811CA9ULL, 0x219D4798F0D74277ULL, 
            0x686F5357D555A8B6ULL, 0xF5635F957784F87BULL, 0xAC0A12FB223306E3ULL, 0x6A288ABBF44DFFE9ULL, 
            0xBF72036241B9D70CULL, 0x75FFF71E68A0E63EULL, 0xB994A8DABEAFB7F6ULL, 0x73C1AA2E32BDF917ULL, 
            0x101A9F51B688BAF2ULL, 0xED16F57958FB1CB4ULL, 0xE07BA6E5A5BAC0BCULL, 0x7D40F382F5D886F9ULL, 
            0xFCDA7C6C4E5FF05DULL, 0x85A8464549E56422ULL, 0xE071560AA020FBB6ULL, 0xAE40F64142EA26B2ULL, 
            0x085BA27DC9F4CA1AULL, 0x3A461A9D0B657B7AULL, 0x703F1CB77E2D3E54ULL, 0xE87160C484937295ULL, 
            0x8B235F763871AA26ULL, 0x6C5108E41222B825ULL, 0x0A2A3C26C25A7004ULL, 0x7C10C4C578DE26C5ULL, 
            0xF01F8EE65B513471ULL, 0x7390B35A91DD1719ULL, 0xDDC195A22F015EC2ULL, 0xF33E9A8A45F8306AULL
        },
        {
            0x112419EA680A7A9CULL, 0x47E3D9D93134313EULL, 0xA921A3D45591E5CDULL, 0xECED79D492AAF1E5ULL, 
            0x4E295C16C625076FULL, 0xFF9C97912421F552ULL, 0x286712A7E448639AULL, 0x1684C5CD2814E75DULL, 
            0xFC1D62F7C75C083CULL, 0x36BD4FFF3DDCEFF3ULL, 0x34303B6DEE102E7EULL, 0x76DCB86B9BA3E904ULL, 
            0x9ED831396AC8AE8CULL, 0x2EC8CA5075E61A2EULL, 0x926B0965097C282BULL, 0x7794BEEC2092D9CBULL, 
            0x70B58BAF74CB8DFFULL, 0xB5BAF25799ADA9C9ULL, 0xB5DC527079BC1268ULL, 0xEFE97DD314595F99ULL, 
            0x7B77D93C70976FACULL, 0xCE29064CD531F7B6ULL, 0x9453915345FFBF93ULL, 0xBE2CD0A44A1C9997ULL, 
            0x9C66512CBD551B32ULL, 0x45275CAEC882FD0BULL, 0x1A72565598003CF9ULL, 0x8353DB85FBB7C999ULL, 
            0x2E9531955DAE63ECULL, 0xE168266D6BA0690DULL, 0x4182FB66E40DEEA9ULL, 0x0563C433BEBF88A2ULL
        },
        {
            0xB0F8E46F88617328ULL, 0x46C3D7A39A9E33A6ULL, 0x92B084DC4141F1B3ULL, 0x79CC4B3EB8873BDAULL, 
            0x70607941583E73ADULL, 0x6882947B742C2DCBULL, 0x8FD82EE3859CB428ULL, 0xFCAF04C7EBF6FD15ULL, 
            0xD66619F1FD1E662BULL, 0x01AAD78A2EC7D8D9ULL, 0x34454A8839C72B9FULL, 0xABCDDAF947EEE78BULL, 
            0xDFDAA71FFA2C167FULL, 0xCB0C5C414642909EULL, 0x470D6DCDB22AC3ECULL, 0xAE37341280C56915ULL, 
            0x11BD06D3EED64A6BULL, 0xF0310AEDFCD2A310ULL, 0xC62CB20E937DDCDEULL, 0x5BDF76056B0DFFF9ULL, 
            0x24FC4763E3A58679ULL, 0xD385158368F31C34ULL, 0xB4D74CB2E9BC6103ULL, 0x5B0EA95EEB70BBBEULL, 
            0x85D4008F8922FC0EULL, 0xEA058FAEDAFBDBFAULL, 0xDB92530BB825E43EULL, 0xC201273EF0324E48ULL, 
            0xA94DE9FE3E06B6D8ULL, 0xB8EA82D3979BB612ULL, 0xCA667A22020A1DD3ULL, 0x1740705122318586ULL
        },
        {
            0xB77164A78F3748F9ULL, 0x69B9FF9DBDE5982BULL, 0x6DF459B4DC1A2F1CULL, 0x36870AB86C83F1A8ULL, 
            0xF9FAB04E37312857ULL, 0x63091D2C22E7A508ULL, 0x7E6A206BB9789ED4ULL, 0xD6E64B48A9AF543EULL, 
            0x584FAFEC82779B00ULL, 0xAD7DE78EE3CC53BAULL, 0x83A14F288411139EULL, 0xEEFAE98ACAB24EC0ULL, 
            0x4E5A0947601340D8ULL, 0xF8F4481738BA6261ULL, 0xA5F12D25C1ED3940ULL, 0xED03CF1EF3EF7CABULL, 
            0x60407FBC2A72ED91ULL, 0xC6DA11FC8AD24A24ULL, 0x431E51350BD21210ULL, 0x89A8758AA58C44B1ULL, 
            0xAA519F4C3D7DD2FBULL, 0x20E85D437A698999ULL, 0x7992804F9754D09FULL, 0x4C803DEFFD366702ULL, 
            0xAD0EDFB3D842E669ULL, 0xA3BBBDBD1BFC5D70ULL, 0x89C1CC99A8BC5566ULL, 0x191B1596894381C1ULL, 
            0x1A3463EF6E26093AULL, 0x5DA943AE2DA5F4C5ULL, 0x32CE1F5585748B22ULL, 0xD86BBB5050774329ULL
        },
        {
            0xBB067EB35551AE15ULL, 0xDF7535B8178E10FEULL, 0x990C1827558261C6ULL, 0x103FC313117E8F1BULL, 
            0xA129D614F1AB3835ULL, 0x356A012D045E2D2FULL, 0xC0E632ABB5FE7014ULL, 0xBEDB27AF169A3498ULL, 
            0xEE2B6AE9C4DA79ACULL, 0xABC2757E593521B7ULL, 0x9BCFF4F3C2797337ULL, 0xA6ADBD6DCF34127BULL, 
            0xC013ED049C288F2CULL, 0x201999914F263EF3ULL, 0x1588F2095C2B744DULL, 0xDDDB7A0025149B9FULL, 
            0x3E2AD092EA5C91F9ULL, 0x8FB81D05B61B0DBDULL, 0xF9F749B7EFE8207EULL, 0x099EE04F867E4ECBULL, 
            0xDEE2C07FD147F505ULL, 0x360E1F1D0B0B8887ULL, 0x2ABA53EBF7EAAC7FULL, 0xF487871BBF197402ULL, 
            0x787F94B6D6963274ULL, 0xAF99AFA969A00060ULL, 0x9E0BEFA1A30A3DBEULL, 0x3C040D70EFE25CDBULL, 
            0xA07D98C0C92794F7ULL, 0xADD44B6DC7A28A6DULL, 0x659E90F89A881F50ULL, 0x08A7E84F9972B04FULL
        }
    },
    {
        {
            0xC6152549E64972CAULL, 0x3D9651960C0216F4ULL, 0x0ED3196C99D87E67ULL, 0x841C4F73FC65EA9FULL, 
            0x13810C8051AF852CULL, 0x28075A636A4715A9ULL, 0x38E9094DAF241044ULL, 0x885A756A07A34F61ULL, 
            0x2EEA47DB927CEC06ULL, 0x65FAF22AB4A7D5A9ULL, 0x55A7F488E91482EBULL, 0xF36B0D07B1AA43B2ULL, 
            0xD049BF287F41CE88ULL, 0x71CAE351D6427E5AULL, 0x581E4B1F77898C90ULL, 0x884E61DC50B7206AULL, 
            0x9934A6D2914EB41FULL, 0xC0E779C104037B6AULL, 0xFC11E2E5919042F7ULL, 0xA9427888CB38F36CULL, 
            0x458B5B8B9FA5CA29ULL, 0x930C02D490EDF9D5ULL, 0xF3F4ACE99AA9D89CULL, 0x39308DE159D64575ULL, 
            0x2B25923036E362BDULL, 0x8588398CFD14E3A6ULL, 0x45DA9FF02FAABCDAULL, 0xA2D59940DDA1B71BULL, 
            0x4F5BE395B531EDF7ULL, 0xEB5331958D1A96C8ULL, 0x7915AD4F8B686A37ULL, 0xD6B860ECDD52A6F1ULL
        },
        {
            0xD29628D0C47E04E4ULL, 0xB44CCBF62B51FCAEULL, 0xBC61AD11BF595BBBULL, 0xB773EB3F1B6E3A85ULL, 
            0x8B1134A6069A4802ULL, 0x6776AB65234BD846ULL, 0xC86C12B60E49AF3BULL, 0xF1B4EE3F1E59C4FBULL, 
            0x5C9A494EF44CAD12ULL, 0x55856F0691848C2FULL, 0x5774C417E6FCAD71ULL, 0xFB3447C8942C1D15ULL, 
            0xA73838E2661DB62CULL, 0x0485A590C135BCB0ULL, 0x705C2E31D24FD212ULL, 0x637BE9882272397FULL, 
            0xFA6C007D19CF8051ULL, 0xD894B164134181B5ULL, 0xC8510023EADB3A19ULL, 0x86DA8718C85937C6ULL, 
            0x01C2040AFB5667BBULL, 0xDAA4DBA4124969EAULL, 0x75AE927D75B48266ULL, 0xA4B8919734B2A164ULL, 
            0x92E03E1EB75C384CULL, 0xF2730DC759BD9B47ULL, 0x354ABE1A00C8653BULL, 0xEFC50401B2DFB921ULL, 
            0x81E3574B857A875EULL, 0xBE9BD8277863D675ULL, 0xC7C87CCCCA1E80ACULL, 0xC6FD976AC0772804ULL
        },
        {
            0x2390FD78D902D771ULL, 0x0FE06ABAF3CF0973ULL, 0x30A1F198488F767CULL, 0xCC7BED28455AF667ULL, 
            0x6B625F90E28D987FULL, 0x0F67DE1416BB63C9ULL, 0xDC6C83974A9E2808ULL, 0x2F05E12980186E5CULL, 
            0x9F610DEF4CAA92C8ULL, 0x016DF84A092734A8ULL, 0x1B6D1FF00B20FA73ULL, 0x9852E58AB5221D3CULL, 
            0xB31887B46EE9F275ULL, 0x440320386753860FULL, 0xAE8C5A3DA6101EA4ULL, 0x8FC365B64BE876C5ULL, 
            0x744555089FCBA8ACULL, 0x0D84FD87C90551B9ULL, 0x3F990B7096DE42C8ULL, 0x2BA3F9754F54E752ULL, 
            0x966530B5BC0BB202ULL, 0xA6827B2C73FA241EULL, 0x3D764B9E4595E93FULL, 0x42352E4442D62AC3ULL, 
            0xAD4EAFFF8F797CE6ULL, 0x75F6A788FBCDF9B8ULL, 0x9070B5158C379321ULL, 0x229E85FDF3865CA1ULL, 
            0x37F741706B7989BAULL, 0xCD02B9B7B51F1BC1ULL, 0xAE349D5A3B2209C6ULL, 0x5E85ABED5D59F50CULL
        },
        {
            0x45BFC5972803DC52ULL, 0x271DFE87487BB8E6ULL, 0xA81CF916A2EF3C89ULL, 0x6FB014E05CB18435ULL, 
            0xBCB522137F57903BULL, 0xE0A0514EB37D81F0ULL, 0xB36CBCD449E04958ULL, 0xFF3DEAB0DFF6EB0BULL, 
            0x3AEB2DB16F67CBB8ULL, 0x3866980ED675D603ULL, 0x168FD7162E3FABF0ULL, 0x13F34C79EB5B2098ULL, 
            0x134BFCA1C278B76CULL, 0x2434369C3D41D359ULL, 0x3876E1135DDA97FCULL, 0xE2784A4E6397CF92ULL, 
            0x7BB711FB619359F5ULL, 0x7DE65CAA35B61E05ULL, 0xD15B802833791469ULL, 0x936B42981A3DBBEFULL, 
            0xC03DEC83A71EC9E5ULL, 0x7D6DD6B6D30DB24CULL, 0xB5840576956158D9ULL, 0x70816181133FF4ECULL, 
            0x83498D06A6DE96A4ULL, 0xC824D948A357CA4CULL, 0x89CB918A56AF0A71ULL, 0x2F806DE6CE686878ULL, 
            0x1F584747B98A0481ULL, 0xDF757644A7679227ULL, 0x04F4E07786024AAAULL, 0xAD65CA8FB9F031DDULL
        },
        {
            0xDFF261254FC86840ULL, 0xB80C89A2069C9A78ULL, 0xE364A3AA99220963ULL, 0x7AAC89C0F81EDE0EULL, 
            0x50518B742BF527F2ULL, 0x3564014A3F28FF1EULL, 0x84D012D09AC709F9ULL, 0xDFACA064D92383EDULL, 
            0xB4C56A0650B5464FULL, 0xE20EA33503602DC6ULL, 0x1B64778513EE581CULL, 0xB1504F6B298062C8ULL, 
            0x5D526E38388B3FB6ULL, 0x6EBAFAF040DADF19ULL, 0x919D1D66887175E8ULL, 0x66427A43B7676936ULL, 
            0x56AA38C316355E06ULL, 0xC19A5E23B5AD6780ULL, 0xAC88CF8F9B9B5291ULL, 0x28AE41F28BAD1C62ULL, 
            0x72D0D42750C84838ULL, 0x97956BB10655A711ULL, 0xC24A46EF90356F78ULL, 0xE97ACE4CF111A20DULL, 
            0x948F448EAACCC281ULL, 0x18935161B1B68B17ULL, 0x2CD0196F29C42494ULL, 0xB860C12F76F2D79BULL, 
            0x555287392AE06426ULL, 0x793899066F8DB7FAULL, 0x34AD3FAE21BA0F45ULL, 0xAE61B50462209E10ULL
        },
        {
            0x2F7525362071D81CULL, 0xE2A3219BD7BB29ADULL, 0xC9608D09804D9B42ULL, 0xA459FBB82AB69EA2ULL, 
            0xA46249645DFCCA05ULL, 0xF9FB210A7D0C0145ULL, 0xC531FAD2A9E3E543ULL, 0x4FF782F833A43B03ULL, 
            0x8B5456F6C70FEAD2ULL, 0xC163A3B268200528ULL, 0x3A9D176BD0FA9BEFULL, 0x5A86942492459221ULL, 
            0xB4A6BC7DE744FF66ULL, 0x858C107A84B333B2ULL, 0x4D73C907FC1E738DULL, 0xDD854619CBEE465BULL, 
            0x33841C2B50D65759ULL, 0x169D57A3874CC359ULL, 0x7B798D83323090D8ULL, 0xF0D5A35A79B2D4F7ULL, 
            0x90E34DFDE7F2A0F9ULL, 0x84667C338A3EDA25ULL, 0x22D7349B049AE394ULL, 0x4E276926471276D8ULL, 
            0x84684A84678086E8ULL, 0xB074DCA5472399A9ULL, 0xCC09E74C8F05BE87ULL, 0x8CD2580F614E04FBULL, 
            0x41F5A5145B316CBEULL, 0x7A4E38FC49779406ULL, 0x98F56783174C161EULL, 0xD4361CDEA1A31078ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseAConstants = {
    0xB3B6128C30DA65DCULL,
    0x123400D230F6F647ULL,
    0x247E1452BADBE21DULL,
    0xB3B6128C30DA65DCULL,
    0x123400D230F6F647ULL,
    0x247E1452BADBE21DULL,
    0xE3DE021BFF18A2E9ULL,
    0x52BE94C006A12128ULL,
    0xA5,
    0xF2,
    0xFE,
    0x9F,
    0xDD,
    0x39,
    0xFE,
    0x93
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseBSalts = {
    {
        {
            0x9AEB73F7A1448316ULL, 0xFBABB93621220DE8ULL, 0x08E40487811085EBULL, 0x7EDE9463A9A8C59AULL, 
            0xEB7AB0FC89CF4581ULL, 0x17CD75C3AB4608AEULL, 0xED7B1966474FDD43ULL, 0xEC06D0F8B62F21AAULL, 
            0xD3B4A014E529E7DFULL, 0xE6F82EB1B1B90FB5ULL, 0x2779DE5FD0C38AB9ULL, 0x80DDD41BF34F2635ULL, 
            0x213466329D902B8EULL, 0x318CA54672F64FAFULL, 0xCFB3977BE7538D43ULL, 0xBF19612D0AFFE5FAULL, 
            0xAAD7DDB747FC206FULL, 0x7CB48C4147BD4406ULL, 0xD9E67244C9E8F0F2ULL, 0x6F0F600EA1E7EC4EULL, 
            0xF6CC151F27D097B3ULL, 0x1A726C46298060C4ULL, 0x3007106F274C63F1ULL, 0x332AFC33FA28B711ULL, 
            0x19D1F580F3F3C68EULL, 0xEB887EEA5A83E828ULL, 0xA9743A1C4F12CD72ULL, 0xAEE8F8F6816A262AULL, 
            0x10C5BACE3316C623ULL, 0x60D953D022AC7C28ULL, 0x33BBEBBA1D5AEB66ULL, 0xCADC15E85CB27C5BULL
        },
        {
            0x8B2A0E987E9CA91CULL, 0x57E17CF3C59C1067ULL, 0xE620FE388C62C529ULL, 0x363A69373AB2A2B1ULL, 
            0x4D156F1D590A77D2ULL, 0x6D427764E3896037ULL, 0xEE25D40449198830ULL, 0xC4A67E48C71604ADULL, 
            0x5A8BE3E84D9D1028ULL, 0x173B3793904FD4F4ULL, 0x5F065A26EB49AB98ULL, 0xADD4D6E45982F3C9ULL, 
            0xDF1CC13DE766A8CCULL, 0x1AFF0B98699D603FULL, 0x11B770AC80D32081ULL, 0x51CC738D731DF291ULL, 
            0x4A20A6ED797CD726ULL, 0x2392933AC5E4BD2CULL, 0xB157890E30F693DEULL, 0x08585919ECF05506ULL, 
            0xD3C543F3A1531177ULL, 0x4B7E6A3FEE19F18FULL, 0xB0E06CD342533085ULL, 0xF2F40FC2317222EFULL, 
            0x535BA3CD2604E8CEULL, 0x72494018BE11A173ULL, 0x3C5F3EA0B09A870CULL, 0x18D035E05D9B6315ULL, 
            0xB4FEE21948988923ULL, 0x419C9183E9A30BDCULL, 0x01DDF08FC95A47FFULL, 0xE46512D812D56982ULL
        },
        {
            0x936A92E69A3A763AULL, 0x643A01EEC06D9E19ULL, 0x9CAA5AE2BA72AA6AULL, 0x4616554BF9D301F9ULL, 
            0x1F7FA6700C6B6988ULL, 0xE7EBAF6D06D91B90ULL, 0x28BC24F2D6DA5E09ULL, 0x949FF8A87949AFC7ULL, 
            0x1C53DE7151E27349ULL, 0x10DC1D774F8E789AULL, 0x273C1C81EB8E72AFULL, 0xE889E2479EF352E1ULL, 
            0x8CC54E5BFFBDBFBDULL, 0x5F90792FB75E51B1ULL, 0xC7AB25572CB3EB1EULL, 0x7106F47A5B1CF0B7ULL, 
            0x7B5CD73A5D6B7BB8ULL, 0x2696CB8B7E1C496DULL, 0xF39D8FB84167925FULL, 0x33BBB66C4FC26288ULL, 
            0x351CE41DEB962938ULL, 0x339CF8A3149464FDULL, 0x7B6B6F49F7688BC3ULL, 0xDCDD53656200C0EFULL, 
            0x7BB32D4FD21CB40AULL, 0x265F953B92118B16ULL, 0x5AE5F464AF881E4AULL, 0xA90A338D70286CB7ULL, 
            0xC1983EFE8616F44EULL, 0xE582A00023763DB6ULL, 0xE2AC076EDEBEE477ULL, 0x004F9AE6A077C7ABULL
        },
        {
            0x94B1E2C5A24B557DULL, 0x6CD95648F0723551ULL, 0x780CF56A08A4B8D2ULL, 0x148B5079A73C0CD3ULL, 
            0xC1A76BE6B67DD272ULL, 0x0D420C17EE1880BFULL, 0xA9A4CE33BB1ADEC1ULL, 0x613CF7CDC6CB9E65ULL, 
            0x8022720C95118B6CULL, 0xDEF9EC0D6E2CCF74ULL, 0x18FA97D9C56E15D9ULL, 0xF1A75F5CC04734E9ULL, 
            0xBEAE9FCEC23FB4CEULL, 0x44EDF8DBA03EA912ULL, 0x46F654A81EFA486BULL, 0xC899A2556FF6E96AULL, 
            0x56B8F53B99C44A64ULL, 0xB321A0E444673A46ULL, 0xA7A3D91FB9AF11C2ULL, 0xC91E8D271FA5E243ULL, 
            0x0DB24EE8E55E9BABULL, 0x103605E87667ECDDULL, 0x62D3FEB442C92D76ULL, 0x0C79EB20DC339383ULL, 
            0x1FBA7D4D45E97C00ULL, 0xC23BFE4BB4C85927ULL, 0x9D1669202282931EULL, 0x0DB4246994C33F3AULL, 
            0x0AF37217A2D2757EULL, 0x90B2F3485213A9F4ULL, 0x51E01842555AAEF8ULL, 0xE0EE5AAFFB97F0C1ULL
        },
        {
            0x968049CDDAFDA59AULL, 0xEA9055D9A1B17581ULL, 0xE35D451D568394ABULL, 0x8D3B1B121B51C838ULL, 
            0x4CE71DB4CD879FEDULL, 0x18148DAE0D996C21ULL, 0x741BD98FE6B96052ULL, 0x4AEAC81053CD9CE7ULL, 
            0x16347E79437B157BULL, 0x414A5341D7989A27ULL, 0x0B130CF603F05CBDULL, 0x44BDE6583AA163EFULL, 
            0x340F997D37C0347BULL, 0x4D62C59BF0C9776EULL, 0x9F4C3703AEDCBB63ULL, 0x0E49B1535ED55CFAULL, 
            0x997E85412E8EAFD7ULL, 0xC59A59EFF34DFF8BULL, 0xF14222F45D75CF33ULL, 0x254D019F81F4BAA2ULL, 
            0x2CFF6AC57A3267F2ULL, 0x4C5C2E0C6D0B96D3ULL, 0x85AD35A7B5281B4CULL, 0xD0CF11B0B2D2B420ULL, 
            0x10EBA5AC66DEE7A5ULL, 0x4DF203718F663AAFULL, 0x1687F028575722BFULL, 0x878BEE6F90252EB0ULL, 
            0x8628C0B758EA861BULL, 0xE65AB2D65C56651BULL, 0xB781D18A1A8CAF55ULL, 0x503D8A04715DD26AULL
        },
        {
            0xAE347C78A66F719DULL, 0x75D9D46CD4B5F0F1ULL, 0x50078560F8CD1977ULL, 0x569E4175382E252EULL, 
            0x978B0F9907462129ULL, 0x00F2A5C171ECC3A6ULL, 0x07C9CCC477F8C0E7ULL, 0xAFB5C2F843980F5EULL, 
            0xAADA0D3A04138707ULL, 0x6ECA1086AE931E56ULL, 0x96EAB3777439A761ULL, 0xB034BAA1CC174118ULL, 
            0xE762C99F0A181B56ULL, 0x6D1AA4A64ED41A3FULL, 0x77BACE09AC657120ULL, 0x690EC15F8F829709ULL, 
            0xE758667C33E45CDAULL, 0x4B49DE7E08B84EB4ULL, 0x56A6DD9B0C81F706ULL, 0x0F6B35A49FE2DE0FULL, 
            0x2867F88487560566ULL, 0x3D9F577D6BA66743ULL, 0x3380C149681A0F46ULL, 0xF2762307E4A2F30CULL, 
            0xE8806F214E65CAC3ULL, 0x5FD1815D1CD0751EULL, 0x219C9909E28BAFBDULL, 0xE8D5BB4C66C3D4B5ULL, 
            0x9827FD3063E165F7ULL, 0x24C0330216D120A4ULL, 0xDC03D4939DF64E4BULL, 0x475E73BF86344FF3ULL
        }
    },
    {
        {
            0x58533B1DB3F9E993ULL, 0xCFD296226A79485AULL, 0x4E7FF609B06D2064ULL, 0x517CD1643A06305BULL, 
            0x9A77BE29D1758BE9ULL, 0x267D40103069FD9AULL, 0x24772141EF4568B2ULL, 0x4D30419A3C0297EEULL, 
            0xCE5298BF8A580A9CULL, 0xDF1405C29D78B75CULL, 0x7DF6532170FB3013ULL, 0x7F87A6037EC3D5DDULL, 
            0xD38A73A2226D63C6ULL, 0x0547BFA7ACB1DB95ULL, 0x05B4BDAA4356A48DULL, 0x898AA66E3142612FULL, 
            0xAB87BD0A7AB65CD5ULL, 0x975344FB83828332ULL, 0x50B41C1E188D75DAULL, 0x9A0FCA8A5005C04DULL, 
            0x1316CB67C52A9B57ULL, 0xC2F72D85587A70E6ULL, 0xA11E464315401332ULL, 0xD183F56AA0949319ULL, 
            0xB798A8582D3E79E6ULL, 0x9C009689614C239AULL, 0x42A7F9B6D591461DULL, 0xF01D3BDC742E8B9EULL, 
            0xF3EAEE94D307D53BULL, 0x8CB438A131CE6469ULL, 0x2FEDA561FA6B6D52ULL, 0x73DD5F9DE8D3EBECULL
        },
        {
            0xEDA7D46C00E51C72ULL, 0xE29CB8911027BDA6ULL, 0xF5DFC256D7193FCCULL, 0x9BC85DBB17AF9344ULL, 
            0x3198FA5BAC7EC2BFULL, 0x56DBCF6932A3D77DULL, 0xD98E041DACFE4966ULL, 0x8A996AC145CCD3C6ULL, 
            0xA350924DE91FCA0DULL, 0x1DD15A1DE525523DULL, 0x23C5104B0E42F5F5ULL, 0x3849300293B36EE7ULL, 
            0x75F76DD89DE82708ULL, 0x09845C10970FEA87ULL, 0x977FDC27801F6AA2ULL, 0xDADC402B60A6014FULL, 
            0x1B2EE48F298C8D3AULL, 0xA0417CCECB3C5727ULL, 0xDE8DA3EB9465E7DDULL, 0x330A1825C14067D2ULL, 
            0x452FB56E798762D3ULL, 0x7CD462585EE8C33BULL, 0x17860CC2C4E6EBD4ULL, 0xF740F395126CD8F9ULL, 
            0x41E44CE17CDACC61ULL, 0xB451BA4C5B79FEA8ULL, 0xD7FD1DF4ED34E429ULL, 0xF25AC094080F4ECBULL, 
            0x0EB3302828F047C0ULL, 0x03101C9AF31A84B7ULL, 0x6A98E32B2FFA11AAULL, 0x09EB443EE2B13FCAULL
        },
        {
            0xDE0B62F192765648ULL, 0x092BCDF5E97D2A1CULL, 0x7CA147A99C2AF084ULL, 0x34BF625ABF8618BCULL, 
            0x17B8CF54884D8600ULL, 0x5DA7565F3EEF530AULL, 0xC02105DA151E22BCULL, 0xE621FCCA7084926CULL, 
            0xD7109A637CDC10D9ULL, 0x273B98447347C00DULL, 0x103B34F0223A63C0ULL, 0xF3C2268645096304ULL, 
            0x1F50F42BC011EB2FULL, 0xD5287FDC5F9A94ACULL, 0x31C25576F4B89521ULL, 0xFDA57695E1E202E4ULL, 
            0x541FCFA5EEF5191BULL, 0x9A8168E93AFF79B3ULL, 0x40BCADDBF8AAA744ULL, 0x14256F85395C45F1ULL, 
            0x31794D91033069A6ULL, 0xAD5078A3C22372E2ULL, 0x93A5B6C8F9818CD0ULL, 0x866975D15C9D5FCFULL, 
            0xB651FF21EB59F0C5ULL, 0xCC01C9A398ED110EULL, 0x6A1436AF1DC93E72ULL, 0x556C7970BF5D7A87ULL, 
            0xD0A3EAF480BE3600ULL, 0x2ACA21115202B75BULL, 0x1D6F41A710A5B213ULL, 0x2D61AFD549CD94D8ULL
        },
        {
            0xF86D2EFC399484F2ULL, 0xE6355B160570A16CULL, 0xDC481B9827FA7893ULL, 0xC56755859DBF5741ULL, 
            0x0530761D48F11791ULL, 0x4A2321174731C1E3ULL, 0xF9F4D809F2E5884AULL, 0x9383595A4507C11DULL, 
            0x4A1089E1E8DE0C03ULL, 0xBFB129CB961AE96FULL, 0x9427064EEE7B0FE3ULL, 0x5DE7491115554181ULL, 
            0x58B1A1CF6F0C6156ULL, 0x0B4D33F307F8BE95ULL, 0x5437EC59E4F4D7E5ULL, 0x39CC6C84AD08B931ULL, 
            0x4340DCCA61F3FC7AULL, 0xE3FFAC77F066A5EFULL, 0x561BFB9DE47B3A66ULL, 0x0055C6EF51C40754ULL, 
            0xE113965BABB649C3ULL, 0xC8BB318F1DD51C6DULL, 0x0483C74AA32DEDCAULL, 0x91566C2D8823BB8BULL, 
            0x7693029BE502C626ULL, 0x6C09589CC13B3D38ULL, 0x5F9E2FBDD814D491ULL, 0x50AD5F91607ED982ULL, 
            0x92D5BF8790834717ULL, 0x3EBF8E0A78A96CBCULL, 0x8828658FF6400459ULL, 0xF48DAD36B87D9BC1ULL
        },
        {
            0xC67CC56203FBCCF7ULL, 0x9145ADD36EC9EBE9ULL, 0xC0DAFC02B8B30E2DULL, 0x55DF9B0F53848FCCULL, 
            0x40FEE623F1AE1E6AULL, 0x094073EC77F2A2DDULL, 0x94B008395EAA76CAULL, 0x90E8565F7505B376ULL, 
            0x26F57E514727D194ULL, 0x823DF54A37C3B6F4ULL, 0xF2646DE3D483A0C5ULL, 0x9E453F9CC8C245E3ULL, 
            0xCEFA3F24A29517E9ULL, 0x62AEA2E6BE1A518DULL, 0x6CD6376B77F73446ULL, 0x414417CBA232296CULL, 
            0xD261E54B998CCE00ULL, 0xCF4A9BADAE078DCEULL, 0x688EB6FDCE85A72FULL, 0xC68D3405281B850FULL, 
            0x1257C217D8F77580ULL, 0x54E2A1A84C72F3F7ULL, 0xB9ABE4748267AE94ULL, 0xDACC01262BE0749FULL, 
            0xDA413444706F47A3ULL, 0x789A00667FF39962ULL, 0x4126565A8CCD23FAULL, 0xAD1B89761353D506ULL, 
            0xC2A1B7EF79C53AF1ULL, 0x335F466C5BEBD822ULL, 0x5C29B32E46B130C8ULL, 0x8AE6EBBE29B9B21AULL
        },
        {
            0x16EB5803B3784BB0ULL, 0x609D3E6DDABA808EULL, 0x7DF2EE71CA78EAAAULL, 0x3CB961FC4BB9ACD6ULL, 
            0x1188168AB7BA43ACULL, 0x57E8954ADCC76E22ULL, 0x1F1EF8D15E7716C7ULL, 0xACBEC1FB8170D2A1ULL, 
            0xEE01E1E44DD873BFULL, 0x5E88066A691E2490ULL, 0xEC354E7900CD9955ULL, 0xBFA28D1176988D2AULL, 
            0x58AD6A550305E601ULL, 0x15CA020444D6FB13ULL, 0xB9734E0B5D1262A2ULL, 0xFBC0C953342F91F9ULL, 
            0x6067B0A4171D93A5ULL, 0x1616372FCE98ADC3ULL, 0x6FEBA01106FEF547ULL, 0x683C3EBD309A9950ULL, 
            0xF210E5404855C6C9ULL, 0x86A3A267EB047FFBULL, 0x7E2DAB95579797B5ULL, 0x05C4618E5826132CULL, 
            0xED1DC74A02C6E6A3ULL, 0x88373EC110299458ULL, 0xBC91D922C9B35F18ULL, 0x7C8FFBC1A84C5B2CULL, 
            0xB8E2E51209934F3BULL, 0x90045733DFF60F9AULL, 0x74D2E0F272B8C6FEULL, 0x4337185433C9573CULL
        }
    },
    {
        {
            0xB7F9CD40CA515155ULL, 0x011DF374E6AEDCE4ULL, 0x8D9B2084AECBF2ABULL, 0x3DC4D235178AE4FAULL, 
            0x1E1FB95362E35E5BULL, 0x122E563CA54A867CULL, 0x3C286424CD82064CULL, 0x516A3D109ECFD067ULL, 
            0x6791B8AC53E369C6ULL, 0x7B33C26900B3DCD0ULL, 0x410543759681338FULL, 0x05566A84AFDAAC9AULL, 
            0x98B3ECE2005E7980ULL, 0x444583100A506E4BULL, 0x86B7B8C1C36952DFULL, 0x3A3DBD2A203401DDULL, 
            0xF5AFA8260531720FULL, 0x56C52692B6803EBFULL, 0x11D1D23F982B42C8ULL, 0x1378CB673A4C3D2AULL, 
            0x8E90C731E15F5154ULL, 0xA1A9C91899E3DD29ULL, 0x9C2E0029B7540D12ULL, 0x5B9CB9C71FD244A2ULL, 
            0x957404AB524DC1B3ULL, 0x3B4A29C1F89B40DDULL, 0x244E52BF55CBECC5ULL, 0xF84DC614369E249BULL, 
            0x5E9D2F3F8A5C0F6DULL, 0xF819F767C7D5730EULL, 0x62B215238F442FFDULL, 0x3A498C019F9F9498ULL
        },
        {
            0x0EB0226D8D95733FULL, 0x361BA395E13DD741ULL, 0x36F608C1B5B1C5C8ULL, 0xDBE3383282773888ULL, 
            0x87C54D76C8CDE1CDULL, 0x602501C68F0C7E23ULL, 0x53F9DCCAB057970BULL, 0xFE452FC24666FEE5ULL, 
            0x40BFF25E4E9C7CF9ULL, 0x838F6CA499F0946FULL, 0xF31FC19400A03B26ULL, 0xD3C3CB3E82639276ULL, 
            0x1EC559DE71D73182ULL, 0xCAFD5A25ACE1CEAAULL, 0x03068792868461B3ULL, 0xD2D5B36EAB789511ULL, 
            0xFAC51BA9E4A43FBDULL, 0xE0BE3E767F2C35B7ULL, 0x7072299B11CA7F28ULL, 0x29281846C82C3D26ULL, 
            0x0C9769BF63FFDDC6ULL, 0xE8E3961AD0B215A7ULL, 0x549844D806B3418DULL, 0x29D1F0D6F4FDF829ULL, 
            0xFB308650F23A137AULL, 0xAC2C6EB47422A273ULL, 0x3FBAF4D5EF5AC721ULL, 0x2EE4B70BC6AD7345ULL, 
            0x0D58F49E0DA570B8ULL, 0x0CFD8E4894633646ULL, 0xD991AEC7B70868F2ULL, 0x34C4B901E3007FA6ULL
        },
        {
            0x7E92434FCD90A471ULL, 0xB5E2363D728E9122ULL, 0x06F9F75FD3FCCF99ULL, 0xC8EBD8CD6602B29BULL, 
            0xF88A28F49D57FF0DULL, 0xECCD7284856FD4F7ULL, 0x9959F3F483294D0DULL, 0x3668C6BB3CB5C5F2ULL, 
            0x9D704951DC42BA91ULL, 0x7E5D7E5A9D6146FFULL, 0x19B29FB95C7A722EULL, 0xF6194833CD000C48ULL, 
            0xF1B14EFA18699F49ULL, 0x023BFEC8D67B714BULL, 0x5FFC924D1AA1BADFULL, 0x0003503C11E2AB48ULL, 
            0xBAF49E0DEAEB654BULL, 0x0BB6AA3F0C14D944ULL, 0xE9182E37265F2676ULL, 0x469D06D8A30F17E9ULL, 
            0x819DCCEADEC3CC22ULL, 0x1989B7A8467D37C8ULL, 0xD955D9F426CD7EB5ULL, 0x7354967DA8215FF6ULL, 
            0x2DD24BF84F37FF0BULL, 0x840B1AA9C146D0CFULL, 0xB08A482BE32A0323ULL, 0x29B4E5A5A7DE9A02ULL, 
            0x41E99F60D66D717AULL, 0x793D8E9208FF1E8BULL, 0xD61FBEED38A13263ULL, 0x6229011EF9DA196CULL
        },
        {
            0xBE7C5D5A66FC092AULL, 0xAFE0249712311F76ULL, 0x6DA0CCD40FE4EF64ULL, 0x760ED7B2E6DECA62ULL, 
            0xA580A4DE6198CEE0ULL, 0xA84CB8BC3C312D52ULL, 0x7EFE689BD17723ACULL, 0x6008FD71107C1642ULL, 
            0xB492511458CF24F1ULL, 0x8818637F33EEF3F5ULL, 0xC8E3C4E7A68693D6ULL, 0x29482A1DAB3C7AA2ULL, 
            0x52E3901F01EA2CC7ULL, 0xAA6FCBA9430E1442ULL, 0x2589AC656293127CULL, 0xC6B624B1C7C3CD37ULL, 
            0x37BF9C0F9769FD3DULL, 0x0ABEB1AAF24209F4ULL, 0x73D746AABD6950F1ULL, 0x1D1B431A5037D79DULL, 
            0x7132BB051BEB18BBULL, 0xC90F8B621B39FE7BULL, 0xDDA04E6C7BC8A020ULL, 0xE140ACE7DEED4194ULL, 
            0x52FF64BC63545C52ULL, 0x9DB5CEC64A500333ULL, 0x3B5148C6FD885D2EULL, 0x3344EABD755EF44FULL, 
            0xB024B12E94A5582EULL, 0xE3E4063C909F6614ULL, 0x41BB10416D3DC827ULL, 0xB39D6BFF8C9A4609ULL
        },
        {
            0xC2F03CB84C4D354CULL, 0x7FADC9A4B851DD7FULL, 0xE0909948720E0CA8ULL, 0x4303BE3B3B4F20A3ULL, 
            0xE697E11E05735CBAULL, 0x023D226DF14711EEULL, 0x2D0E2DBE8215539DULL, 0xEFBDCD8C52B36FA2ULL, 
            0x2AD65C72B8E5A6EDULL, 0x0FF0142C1AB1AB31ULL, 0x8072A6CD701563E1ULL, 0x5B295122D480F838ULL, 
            0x4FCDCDC58D45FB02ULL, 0x4E47B35177FC1B86ULL, 0x90FDB38E07FEC28BULL, 0xF4B832864061D41BULL, 
            0x125711B70416ED9DULL, 0x10B7243638FE3CF3ULL, 0xF5F5A51AFFDA7293ULL, 0x140265BD1C50874BULL, 
            0xEEC12B606326E922ULL, 0x632AA6F919CD3C1FULL, 0xFC58E5819CFB0F64ULL, 0xB5B1ECAC6C5001FDULL, 
            0xCE5C476C3D9C0CE3ULL, 0x8CC3D6D0B4FAB8D5ULL, 0x8439AA728A73167EULL, 0x3B23AFEA6E52B39DULL, 
            0x057B7B11905001CCULL, 0x8FF46D3B3F5910E3ULL, 0x1EE44F7C5EF40FB4ULL, 0x72C475B17FB55223ULL
        },
        {
            0x927A0D6C35986308ULL, 0xB983AB7087A8523BULL, 0x45E6D2BD74062556ULL, 0x07B45520EBFC03E4ULL, 
            0xF305DE8C4EE359E4ULL, 0xC64A84E6F47FB4AAULL, 0x79604885E205CA6CULL, 0x9B5EB31BC80CC94BULL, 
            0xE7ACF8F53D56FDD7ULL, 0xADB72769EBD4B828ULL, 0xF96DC55BDA314E8DULL, 0x95B862CE3598F1FDULL, 
            0x4CB52C4852336970ULL, 0x3BD2E41B8B7C9C40ULL, 0x7F366685BB3DA12AULL, 0x6709A4FD00E803C6ULL, 
            0x00AA762752CCB308ULL, 0x90BC8A388699B1FCULL, 0xBE47218DE57AF13DULL, 0x39A2546C73A05748ULL, 
            0x1C2A3AA4E5FFF268ULL, 0x3C50E4A0411FFF79ULL, 0x0E4458787579D529ULL, 0x943BEF69EC1D732AULL, 
            0x503F0F9ED0212259ULL, 0xA47E932465753FCAULL, 0x422FDABD45A1010FULL, 0x42BF5CF6970E2437ULL, 
            0x5CE535890605192CULL, 0x07CB4B129BF2850DULL, 0xDE1CB413A9C42C4CULL, 0x93AD219D62026DF9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseBConstants = {
    0x86D440C0D9B3187AULL,
    0xA4E3908D901B816FULL,
    0x5F743FE61FEF7709ULL,
    0x86D440C0D9B3187AULL,
    0xA4E3908D901B816FULL,
    0x5F743FE61FEF7709ULL,
    0xE0825E559E4A1331ULL,
    0xCCC6697306AE42C1ULL,
    0xA1,
    0x48,
    0x40,
    0x8F,
    0x5A,
    0xA6,
    0xFC,
    0x1B
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseCSalts = {
    {
        {
            0x126D238D4D7CC151ULL, 0xC1AC0D37E160CE50ULL, 0xD5D42FA314B6EF6CULL, 0xC2474223CD60C747ULL, 
            0xEE1552419D0555A7ULL, 0xFE91F354D411B658ULL, 0x39F3E007A5B06486ULL, 0xA7DA99930DF446E4ULL, 
            0xA111B2F8F0C0C5FCULL, 0xD4A03721FA6F46D3ULL, 0xB2B18ED820735E68ULL, 0x4941B1106B809C2DULL, 
            0x4D06A78FE7E81ACEULL, 0x061F70AF1F2EED7FULL, 0x2FD56E5899A8DBE9ULL, 0x94A824DFF0B7BC1BULL, 
            0x53827638AEDBB08BULL, 0x777164B49B50CE3BULL, 0xB604B5AC0ECF2F62ULL, 0x545E9D00B6C14D02ULL, 
            0xBA053FEE34F30BD6ULL, 0x5DDA539415853135ULL, 0x73DE93828C667CB5ULL, 0xFBA689C28EB2F07EULL, 
            0xEA3737B0D59240ADULL, 0x5D745418E1E4B3E7ULL, 0xAE51818A5311EAA3ULL, 0x7227EA69EB3B2A50ULL, 
            0x9AFF37D1F5C460ADULL, 0xDE0A68213A881158ULL, 0xE13C644CBCF57B42ULL, 0xDE04375C7C7B4CC0ULL
        },
        {
            0xA17A212C568600C0ULL, 0xF6B4747BC95BC643ULL, 0x60415586B8EC3ECAULL, 0x50A9CDBA95CDFC4EULL, 
            0x269FDA59F589983FULL, 0xA4597A242574509FULL, 0x99EF58D2A5010281ULL, 0x31A3221DDEA56ECBULL, 
            0xFCD32F4CF8C74C20ULL, 0x3E1DC7034F5458E7ULL, 0x046D5431794421ADULL, 0x5D9E6C41137DF5D1ULL, 
            0x83A3A9C26A20374FULL, 0x2532C46DBF37A0B1ULL, 0x2897AF1B6A8C870CULL, 0x4CB6E3F8935DB951ULL, 
            0xAA0A769F6DA54401ULL, 0x5DF8DD154DB7E483ULL, 0x5ED460C926F80E61ULL, 0x142E8ED168AFA18DULL, 
            0xA4604F69CAF34D5FULL, 0x75AD7ACED862C583ULL, 0xB7301110E2FB1D6DULL, 0x7071DF3E3B5806C1ULL, 
            0x8A7C8F5FD5DCF144ULL, 0x97B10B98B4E64B33ULL, 0x73DA978DFC00B35CULL, 0xA99D049142A1DC43ULL, 
            0x4042F3CCABE152AAULL, 0x5CF8FD7F63759C06ULL, 0x12B10DDA2D1EC21BULL, 0xE7499F3EF2AA51EEULL
        },
        {
            0xA31B039A186C49CDULL, 0xCAA3C3A16A6E093CULL, 0xB577BC21732441F9ULL, 0x404E6F9D55CC2790ULL, 
            0x8B070E193C9D52C6ULL, 0xA1FD48051EFFCA84ULL, 0xB0A9432A2604BA64ULL, 0xB12241A72ECB8448ULL, 
            0x78B261D0A4B00EA3ULL, 0xBF3C2EA6878B47D6ULL, 0xF1429EFE4BB53392ULL, 0x025B2C0D449996BFULL, 
            0xE2395D38C917D2DDULL, 0x9D48C606BE678892ULL, 0xEF571C7458588741ULL, 0xC5CA15989A16D377ULL, 
            0xF732C323CCC3C5D9ULL, 0xB69D522C257C23E7ULL, 0x1F48A03F96926701ULL, 0x20CDD118A4572555ULL, 
            0xB3BD59E1BB2B1F20ULL, 0x5F468D7F620CEC72ULL, 0x70405BF5196AC2E9ULL, 0xA5E4EAE8F8F3FDE2ULL, 
            0x5FF8670F73E8883CULL, 0xE5969699A8150920ULL, 0xEC140515EA11F11AULL, 0xAB865AAA5C1E664AULL, 
            0xF052005BA8BF5EEAULL, 0xE4B178A252BE5D77ULL, 0x9535EB7763D0EC03ULL, 0xE88CCF7008865CADULL
        },
        {
            0xACB39E1F3239EDECULL, 0x0FA873D9A53C4555ULL, 0x28D688A4150B8CEFULL, 0x14612A291A9FD2D2ULL, 
            0x8213D824C9A21D16ULL, 0xD55AC0B3A6D3AF03ULL, 0xB8511A4593592A66ULL, 0x769F8C110C89A640ULL, 
            0x256E7FD231AC90D0ULL, 0x4CC1160334694BCDULL, 0x8945A57EB7D530C0ULL, 0xD8209F98D98B4011ULL, 
            0x93027122B289A261ULL, 0xDE15B710E25B2109ULL, 0xBAE143D4DF8791AAULL, 0x847F310441D66317ULL, 
            0xC2F0968D64FD9A59ULL, 0x14A83CAF8D74424EULL, 0x29EF292EE9946303ULL, 0xE9F31D37167C2549ULL, 
            0x593BF385A9E0DCC9ULL, 0x801CB6D8D3141F84ULL, 0x664F4175B312E07EULL, 0xF21B889E970C48F5ULL, 
            0xA0A40A4DFF4B8DD0ULL, 0x1DFB27BD0C5E4305ULL, 0xB0737E2EEEF82EF2ULL, 0xC4A9DC678FD0AF16ULL, 
            0x72CF0ED7FAC2A1BDULL, 0x5CD1010A77B789FBULL, 0xAEF08AE5DF426848ULL, 0x6F27191EBCB15505ULL
        },
        {
            0x9F0E022314D33217ULL, 0x20027794A684B944ULL, 0x72F98E64E083166DULL, 0x65708714FB3C9A73ULL, 
            0x3475BE2532AA5297ULL, 0xF58D80AAE8FB951DULL, 0xEF7A30E72C17F4F5ULL, 0x53F6949C03406839ULL, 
            0x990ACAFCD0ADA663ULL, 0x4ABD18171C362F6DULL, 0xEB171D2A3735A54DULL, 0x6FAA8D20CB16562BULL, 
            0x819B6D63135E1717ULL, 0xB0CBFF37C9593989ULL, 0xA4A0352430C76107ULL, 0x1C39384817F5DCBFULL, 
            0x86BCA2809F0F189FULL, 0x97E40287A01C673CULL, 0x152B4B8F22699521ULL, 0x30D18C75DE7AA576ULL, 
            0x1D9177716D36227BULL, 0x5423F8FF6742969CULL, 0x518E7E9C8C2412BCULL, 0xA18D5D7790497E1FULL, 
            0x49E4FD62C3AEB0E8ULL, 0x85D2BA63CCFE5B52ULL, 0x16E61D4FDDB3894BULL, 0xEE1BB81D1CD78E07ULL, 
            0x384A9A8E58995B6EULL, 0xBC1669CA05CEE38AULL, 0x475EFF8A2BBD2520ULL, 0x383C61BD6A438F64ULL
        },
        {
            0x42E16F8E2D1BC787ULL, 0xCA2E10FF1DA76290ULL, 0x134C7BCC058DCCD2ULL, 0x77CCAD6A6A62271FULL, 
            0x3362806234ABB5ACULL, 0x89243F72CFA73203ULL, 0x53C3BB911F7120E4ULL, 0x973EB93FC4579FE7ULL, 
            0xD19EF5121BED61C5ULL, 0x7FE4FF55099D6E80ULL, 0xD17934E11833CCD5ULL, 0x34A8C1563BDCFB50ULL, 
            0x790A69C1968E0B15ULL, 0xF608A2AA5D31AD49ULL, 0x084596AF790D6B8CULL, 0xE7600CAE7B9AA588ULL, 
            0xEBDF60713F7294B1ULL, 0xAAB3D8C27DBEB5A8ULL, 0xED4BFCCCC7AD237EULL, 0x517C69DB4353FFA1ULL, 
            0x9BD71A8217F5B7C7ULL, 0xE4DADC7D8AC57E49ULL, 0x66A0DC5E8C9C32FDULL, 0x1CCC84486AD86DFCULL, 
            0x3C0B71F00539E5EFULL, 0xD3EE908B25577E5BULL, 0x8F06CCEAE2F01117ULL, 0xA590EF5AE4F3A31AULL, 
            0x7302CAAC99EF8769ULL, 0x85EFB92C3E1E1D36ULL, 0x44F6AF67D1D19C87ULL, 0x2DA1DED42793FB5AULL
        }
    },
    {
        {
            0x290D1C75A981E458ULL, 0xAE70951DF6395647ULL, 0x0A9D6E14AC100BF7ULL, 0x1908E04DD96F3406ULL, 
            0x4F67685578ED7DE2ULL, 0x716D251BAC0A72B5ULL, 0xAF5CC20DF994E379ULL, 0xB45E9EAC51005307ULL, 
            0x6F323E350E3C4666ULL, 0x7F28498EBF4078AEULL, 0xC86495D59A4EA3ABULL, 0x5743522B9EE38678ULL, 
            0x96FC200C0BC6D3C1ULL, 0x52C11E71CC305541ULL, 0x4D8BECF2A64F2507ULL, 0x06415ADD03BE5E23ULL, 
            0xB777708D10EC8E9FULL, 0x4217B46D6C5E1D6DULL, 0x08748266B472C60EULL, 0xE5DF501282FCEFD6ULL, 
            0x7EC1D0BD27106225ULL, 0xCC8F76C30BC15377ULL, 0xC420E6C3836F7E9CULL, 0x48FF12E9CF1AB2DCULL, 
            0xEB46CA44481B9C73ULL, 0xE1FD88B6FFEA12F0ULL, 0x0FE2B7CA18C3C9A9ULL, 0xA7C41EDFFDE1F79FULL, 
            0xE01EAB9CD77B1F1BULL, 0xB24E878FC4A134ECULL, 0xFBA348CC4B5F749EULL, 0xE3DF683A0899CEE9ULL
        },
        {
            0x0A3C645FA7826A8CULL, 0x52B5218A7E33C31EULL, 0x791F1697045910F8ULL, 0xDA84651484B68D81ULL, 
            0xD2F8F9FD0DA5BDCAULL, 0x13CBF9FE359E0851ULL, 0x8EDCB06463EB436FULL, 0x0B8C7F564AD34914ULL, 
            0xBDC3A2159600C6A0ULL, 0xE8A1F470496F7CC2ULL, 0xF84EC05EB9085864ULL, 0xEFCC3189B7210EF2ULL, 
            0x9A9E3ED9755180EDULL, 0x9252C9633B18AD4CULL, 0xB01F4203AC251631ULL, 0x624A8F9D62CE27FAULL, 
            0x2A5CEC1779ED1A65ULL, 0x8ADF75E4BED1004DULL, 0x6BC9A90D144C8A34ULL, 0xFFF2823F29F74BB6ULL, 
            0xC45137D87486D6BBULL, 0x94C8D0519D5D3082ULL, 0xD9F772F388A72F86ULL, 0x6F47737B8FAB7AB3ULL, 
            0x26D31FCB2A1C9978ULL, 0x88C778219221AB01ULL, 0x1CA1045418B2B90BULL, 0x630F5CAE30B8E46CULL, 
            0x93B8433E8F6DF123ULL, 0x29C54FF896862EB1ULL, 0xA0B0CD5622B4E30DULL, 0x266DDE196FB04BB4ULL
        },
        {
            0x1C2C7141B7E5C70AULL, 0xABAA3F08880C487FULL, 0x8E88232ACE585473ULL, 0xF103CBA9C07D0BF8ULL, 
            0xD93E772F85B2B58AULL, 0xFECDC59A3D746E98ULL, 0xCF275083F8C57101ULL, 0x83B64EA03918258EULL, 
            0x75B78EF532647700ULL, 0xE1B25998E2E8B335ULL, 0xA6674DB888E69D6DULL, 0xDBB4D51FC693919FULL, 
            0xDB44DBD6752CB178ULL, 0x6D74D19F6291ADBAULL, 0x2D9DC35151641F2FULL, 0xC80EDF24DC5A1F48ULL, 
            0x4089637CA767F8CEULL, 0x42B7BCF9CBE99B26ULL, 0x4061BDE1A79E3E5FULL, 0x7AA7B48B2EBFBB08ULL, 
            0xB1D330EBFEF42C1FULL, 0x8EEC0C336705710FULL, 0x7AAB6E5F67B217DAULL, 0x08A5DB0D6DA237FCULL, 
            0x1A83D06FB2E3C4C7ULL, 0x0274B4E4B396FC29ULL, 0x6AA751235982BA0DULL, 0x88FD8AD7320538A6ULL, 
            0x885EF2D5FD4D12BAULL, 0x70E7DEDD4F40115FULL, 0xEA27BAA2644F7F69ULL, 0x56A7A46778E0E79DULL
        },
        {
            0xA6F7E9742CB05C34ULL, 0xDD7C67B499C3C255ULL, 0x5E006FFA1ED7700EULL, 0x47A2F38644E7011AULL, 
            0xA12AF9759DEB03E6ULL, 0x2B72191867299BEBULL, 0x6D6CAA15323D5C3FULL, 0x025AC9218ADB61E7ULL, 
            0xC706BED38FFF4694ULL, 0xB829F42B30F317FCULL, 0x5270C7361E58739CULL, 0x4BC36AF75F8818D0ULL, 
            0x9C27092002096EFEULL, 0x522872ED1A431790ULL, 0x78C59BBABB1A87ACULL, 0xE6020AF94D3B5939ULL, 
            0xE500E996EA772489ULL, 0x1E7AF05D7117F59EULL, 0x9062B5611E829BA6ULL, 0x9CD9F26186687BEBULL, 
            0xF3748B8D3C1631A9ULL, 0x2A878F3E261E86ABULL, 0xE67F622F9BC3B386ULL, 0xA8E5F5B3FFD99913ULL, 
            0x9BD12FAC90465E97ULL, 0x430CA505E0934DAFULL, 0xEEED6E78EB5897A8ULL, 0x211794098BF0E022ULL, 
            0x8B0E94C0828D5A93ULL, 0xC0F2CA3A04377C61ULL, 0x1339578FB8B651DBULL, 0xC424C5C99836BF33ULL
        },
        {
            0xD1DAAA49220A1672ULL, 0xAD2257F3B0DFCC1AULL, 0x6FB7E27FF9317FD9ULL, 0x61B1B87814F79E26ULL, 
            0x58BD91A7BAF2B4ABULL, 0xBD1B0085F91A5B94ULL, 0xD6AB6C8A1321B125ULL, 0x6BEED2BA15A27D06ULL, 
            0xC089EBF36289F668ULL, 0xCFED98BC73807ED6ULL, 0x0DE36F3F6FD93843ULL, 0x4E302E23051D35D3ULL, 
            0x3351B360C98B036BULL, 0x90E4F6D62BC41CC4ULL, 0x512F2FC38D47547DULL, 0xAF7A98BDFD53F203ULL, 
            0xDD6B0ABA0702E84EULL, 0xAEA7BCD0FC810C62ULL, 0xC17DC153F3F0F5A6ULL, 0x442D2C0A887AEC95ULL, 
            0x6BFB96823197F3E6ULL, 0x876FB92D5023ADCCULL, 0xC1D805A68EBD986AULL, 0x6D9FA3A53F5B7AB0ULL, 
            0x84BC2122DE9A2A15ULL, 0xE6E9FFE31585A218ULL, 0x4ABD8F16CEF613B0ULL, 0x1186BA8BC6469B5EULL, 
            0x0A03E3309D054DE6ULL, 0xF694F1363C6B22CDULL, 0xA87A712CC663146FULL, 0x04C970ED77468188ULL
        },
        {
            0xA57ADBF3799C2CC3ULL, 0x1EA2F0CDE0CFA054ULL, 0x0D4E46439F648126ULL, 0x41CECD96AAAA1224ULL, 
            0x3CA492DC69A2E81DULL, 0x52AC0AC7FDEFDB6BULL, 0x08F7E591AE6ED706ULL, 0x7E840EEE60EE50CEULL, 
            0xBAD02E09B0E393C6ULL, 0x7881CA4AD1135E09ULL, 0x5F4C638403920543ULL, 0x47FF9693190B631BULL, 
            0x5ECCD9AEA3F1ED9FULL, 0xB2646E0E922B1BE2ULL, 0xC5B3EB41D16955F6ULL, 0x69F7DF47B6BFAED3ULL, 
            0x07920B558D0DEE44ULL, 0x240686440A992797ULL, 0x3ED969E8675A1B5AULL, 0x598CDE2655436F3DULL, 
            0x40F0550BEF440E58ULL, 0x06EA4E84EA3D7939ULL, 0x248E768F1A0BCB5CULL, 0xC1D13918380F7018ULL, 
            0x57FDDD25EE519FC3ULL, 0x3AD1404B143E2D68ULL, 0x2A60C1D4F63D45ECULL, 0x35E81A39C88123CCULL, 
            0x12F50AA1A4994CAEULL, 0x9E0B72DA394E8A87ULL, 0x883208FF83B1C34DULL, 0x795622C2DF8F404EULL
        }
    },
    {
        {
            0x0CCF7E101F0AF8CFULL, 0x4CB4F66660D9CB5AULL, 0x549819B303E3C114ULL, 0xAB012665C3708E34ULL, 
            0x3171BB368F93ADFAULL, 0x8DAF5FD2DFEC23E8ULL, 0x315F61D6AD6C79A2ULL, 0x52B02BF538852909ULL, 
            0xBF63D26514A921F3ULL, 0x13F6F81D8EBAA98BULL, 0x1308DDA0C09B31FAULL, 0xD3052FE34233DD15ULL, 
            0xDF9D9049652223B2ULL, 0xAB7ED5B50C5881D1ULL, 0xA2C0F1075D4792A4ULL, 0xE9779C3F228C3BF9ULL, 
            0x682EEDB59CE52C29ULL, 0xD599D79092CF3811ULL, 0x3E2605071F33E490ULL, 0x56C67EC9783F8D7BULL, 
            0x887A286F9FFD84FEULL, 0x4E2A54AA05A2D519ULL, 0x39C845811E044B7BULL, 0xAF0880DB7769AE81ULL, 
            0x7AEC58769477366BULL, 0xD821F44EDB6C1C89ULL, 0x9E2090AF0BBA6FB5ULL, 0xF7AE420195F82661ULL, 
            0xEDDA74DB2F09738DULL, 0xDD84CE16E9FEA821ULL, 0xD3A2A890AA5185C2ULL, 0x1D6AFFFFF8F9FA0EULL
        },
        {
            0x33B68332021535E6ULL, 0x74B8D4F1FC1CE3F4ULL, 0xF35F18922E560FF3ULL, 0xB97741D96F0D4DE5ULL, 
            0xBF232465239B8771ULL, 0x49A2F9A958E6A0B5ULL, 0x01F197CC7ACCDD61ULL, 0x2A3EA65DB5126818ULL, 
            0x2782A4B3B1C0CA02ULL, 0x6CB9175C25439A2FULL, 0x7FDC9820A4744F41ULL, 0x9CE8F0462E262606ULL, 
            0x8BD9AD6C172ECD0EULL, 0x908F61A1985783BAULL, 0xCD0797F6A6E0B911ULL, 0xC2502F918180BC36ULL, 
            0x8264E3F545A5B673ULL, 0xF6D87D751BCEDAB6ULL, 0xEBC1FCD07287DBF1ULL, 0xADFF725DBA4A7B29ULL, 
            0xFA1F479034C48324ULL, 0xB474AB1D4184B19FULL, 0x7E114676F9CC6B7CULL, 0x19BACB3E870301BCULL, 
            0x8C302F4D941D80C6ULL, 0x20F80D1AC660BFC5ULL, 0xEB691D0595BD32A5ULL, 0x147905205B392A06ULL, 
            0xB1BB6F588BF2AE5BULL, 0x3822C770FDAB7DA7ULL, 0x0E2153F667B2E2F9ULL, 0x9B7B7882D35462C2ULL
        },
        {
            0xD6F723980FE66E06ULL, 0x6158F5DC2B491BC3ULL, 0x747B87E5D54156D4ULL, 0x0794738B786D0339ULL, 
            0x7755FB29EF89BED6ULL, 0x6D6121B9A4B8A421ULL, 0x6DEEB7630F96B755ULL, 0xB2A41F88E19F887EULL, 
            0x8423A4D02A957806ULL, 0x56A871B6CE70BB90ULL, 0x171636664B32FD07ULL, 0x2526655F06519B97ULL, 
            0x2BE56F5C12C6EE01ULL, 0xD742E9653D083A9CULL, 0x2547E225EDEA09C7ULL, 0xEB27E2457B9843F1ULL, 
            0xA522DF7B2125ED3EULL, 0xB0EF48DE36D91DE6ULL, 0x0E5FBE9D3BFDE374ULL, 0x747BFDBBDD8B2483ULL, 
            0xE9E0790804051871ULL, 0xEAB19C73A82E41F1ULL, 0x5187A7DD7DC66963ULL, 0x426DBB8B7FB45E43ULL, 
            0x8EAB62D7E492639EULL, 0x3367EF70A0A8D7F6ULL, 0xB0D6B90D892771D7ULL, 0xAC03CC77ADC8BE64ULL, 
            0xBD0A6E462106D86DULL, 0xF119FFC6E18BF979ULL, 0x54659C40CFAA011DULL, 0x96C14F379F14F582ULL
        },
        {
            0xF823F1AD7D3EDD48ULL, 0xD7C927C9848372AAULL, 0x82405E6E4053EBFCULL, 0xB49B98265C959500ULL, 
            0xF8A57FA2A6B411CDULL, 0x655C29394DD59035ULL, 0xD28713CFD549728BULL, 0x103E3F4B8E1DC431ULL, 
            0xABC961B874BB3FEBULL, 0xB4C83EFC309D82DAULL, 0xF094794688257030ULL, 0xBE0C1599D6D27156ULL, 
            0x56692895BF3294BAULL, 0x560F80C44A5CA6EDULL, 0x2DE225012ED9AFF1ULL, 0xFB9048BE2CD786F1ULL, 
            0x533C2E3C7B81DBDFULL, 0x8008C9748053AEE7ULL, 0x0DC374A984DD43CEULL, 0x78CF6063680BF3CFULL, 
            0xDA6FEF04A57DE947ULL, 0x3B208513812F04DBULL, 0x3B92F39E0D697B1DULL, 0x89919A3638CB4ED3ULL, 
            0x710C7C45F672C40CULL, 0xD357D914B0EAE61DULL, 0x711FE0AE37C1F65BULL, 0x2282C96A04EBA0A7ULL, 
            0xFE82A50CC1F6CCA4ULL, 0x0F4F70C5F94BF491ULL, 0xA0875DD69E63E2ABULL, 0x151556265EEACFCAULL
        },
        {
            0x8C046B89DFEA4F17ULL, 0x7B5A7535CF0CEBF2ULL, 0xA4D985548F59B681ULL, 0x4B971667C94DC6F9ULL, 
            0xDB97AD9DBDB90FB1ULL, 0xB8DB38D42CD8D02DULL, 0xF81A1DE3E2151486ULL, 0x1D5C3AE2A9D5B949ULL, 
            0x1CFC24A9E3A4383CULL, 0x17B16243A9FB53BDULL, 0x6DD89B2AB2D7CF57ULL, 0xB32DC109AA965329ULL, 
            0x32803A7FE794BBDCULL, 0x1A16F57B590CAF4AULL, 0x86A9A656121695BDULL, 0xF3775CCF2BA080A1ULL, 
            0x70273BF5C10FEAF1ULL, 0x46AA76F558E53C55ULL, 0xAE5CDEA1DF61B462ULL, 0x6363CC77C35B1961ULL, 
            0x16DFD01C1310CE03ULL, 0x3A6842EBF3D586F0ULL, 0x539AC5F8DFE80E2FULL, 0xB3162A815F9971B7ULL, 
            0x0BF3EC0F9BDD2694ULL, 0x9DE3693E4AF73075ULL, 0x3E069878970A7DF9ULL, 0x353A4C8A1F64D23EULL, 
            0x8DEA2BA834002292ULL, 0x8C2CCC84E3976AB8ULL, 0x50BAB70B5DD191C5ULL, 0x8952B8C9288C0985ULL
        },
        {
            0x22C00CC960516F40ULL, 0xAC2361E8997CFD1DULL, 0xE601C3085BBD84C0ULL, 0xDAC78DBE513FF722ULL, 
            0x85C455663FE06071ULL, 0xD3E8F6C2C0AE9644ULL, 0xC87FA134CF9C4E75ULL, 0x9453F10372DF8717ULL, 
            0xAE11E8AE943FBA34ULL, 0xFD7866B60F0128F5ULL, 0x1332D4AF19C0AE36ULL, 0xE80EA33D3482246FULL, 
            0xD1148FBAF426DF87ULL, 0xC27B8B89D9B0B7FBULL, 0xFA432296F8494FE0ULL, 0xD820C336DA823EFFULL, 
            0x07EE1E0F7E9C70D8ULL, 0x7843CF10585A8129ULL, 0x36377ED7A4377857ULL, 0x7B2BA550AFA23D03ULL, 
            0x5098BD40E7A96ACEULL, 0xF13E6C91548D48AAULL, 0xAAB10E907B1D2D10ULL, 0xF37122B8B66D98A2ULL, 
            0x24EF99C3E864C650ULL, 0xCFC850CC0612DFA7ULL, 0xF0BEF2896422E084ULL, 0x63B5586E8F883DC0ULL, 
            0x895C472315D6E82FULL, 0xCEDF103B8F31E5D7ULL, 0x4B82F2127E879D1CULL, 0x7B9E07975F9D88A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseCConstants = {
    0xF0709CCADB9B4E86ULL,
    0x88C5988974A6EB55ULL,
    0x9B273EC6D81E0608ULL,
    0xF0709CCADB9B4E86ULL,
    0x88C5988974A6EB55ULL,
    0x9B273EC6D81E0608ULL,
    0x05A2AE577DBC47EAULL,
    0x68A546AF7550D44DULL,
    0x2B,
    0x18,
    0x5F,
    0x2F,
    0xF2,
    0x5A,
    0xA7,
    0x87
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseDSalts = {
    {
        {
            0x865551DEFF241905ULL, 0xFA5FD6339B811DA6ULL, 0x0B2C2854C4A5C124ULL, 0x0E933C453FC0ACA3ULL, 
            0xFDC6CB252B4AEC68ULL, 0xF0AD03168CB04B78ULL, 0x599EC75C6C17AE57ULL, 0x821C4F3687577735ULL, 
            0xFF95EECA21A52DA6ULL, 0x255B0DA7F82089A4ULL, 0x66AFCC693C60897FULL, 0x43172C82E115CAECULL, 
            0x552EE43CEAA6179FULL, 0x94137E4A7DD645FFULL, 0x2EA17F61CF24C528ULL, 0xE40E50918A4D60B0ULL, 
            0x931DC26CD6CF45DDULL, 0xA3B096FED6D4C15BULL, 0x09F3F49FE85FDF6AULL, 0x694922D142235CB4ULL, 
            0xC201D5D0F758387BULL, 0x217D17D9F10F58A6ULL, 0xC11A238CBF8F6F32ULL, 0x7284091D743DE498ULL, 
            0x64F83F641DBBC718ULL, 0x480629684C9B285BULL, 0x9476362CD970A4A4ULL, 0x8CB4F110DF61F760ULL, 
            0xBF4955E0B711DA22ULL, 0xF359549C07259749ULL, 0xD60D992367B8C69EULL, 0x417E9C3617E00E22ULL
        },
        {
            0xD31F2195498EE62CULL, 0x7B62D80B39442D3FULL, 0xBE488768D196625EULL, 0xC1AF48EF891E5B04ULL, 
            0x364B87701CAA36A4ULL, 0x7E3FC09CB30EDB43ULL, 0x715D8D2E4D35BCA7ULL, 0xA4545F78BB4662A8ULL, 
            0x2EDE41F850C646D6ULL, 0xCF999A8AAB74411CULL, 0x482AD691999810F1ULL, 0xA3D637938C4855C9ULL, 
            0xF15ED81822E4387BULL, 0xDCF4EDA254B6B148ULL, 0x7720A3D13007ED0AULL, 0xDF281D7C2FC65F77ULL, 
            0x8368967AD3CACA39ULL, 0xB75CBCA97137B4F8ULL, 0x6F70D1CC8E450045ULL, 0xB056DA3547AC50D2ULL, 
            0x50233D304CF215CAULL, 0x97DA6800D956873FULL, 0x58340F202AA071ADULL, 0x2FF4C54973CB22C9ULL, 
            0x752D44DE5113058BULL, 0x9FC0BE2FE473CB1AULL, 0xE8ADAC29214A45F5ULL, 0xA620D558D87C31F8ULL, 
            0xD2DEC446BBEBA1DDULL, 0x914FBFC5722704E7ULL, 0xB415F94CADF4866BULL, 0x703FF471A73AD2B9ULL
        },
        {
            0xCDE1519B58ADD6AAULL, 0x6BEAA524AC946B34ULL, 0x5A095A3A5A4D8A5BULL, 0xBA987FC857D37101ULL, 
            0x7425EFA83AC6CDA6ULL, 0x0767972CAB11BCB6ULL, 0xEE7A443156DFD066ULL, 0x1DB540D350D7D7D7ULL, 
            0x5B428F9AFD752566ULL, 0xA537FFF8201AB601ULL, 0xA1E5FC97EDC812BBULL, 0x8B2C4822DBF20235ULL, 
            0xA80E1E024334B537ULL, 0x3B18F9F417965A5FULL, 0xABABD027ABA4A196ULL, 0x3AC2694FE044BAA2ULL, 
            0xBC1986665E52DAF8ULL, 0x2FF598E0EE705FFBULL, 0x38FC9B215A67A532ULL, 0x52B70072A94BB5A2ULL, 
            0x50E57B1FD3A1FF07ULL, 0xDA17188E525BC23EULL, 0xDA3E412328D94627ULL, 0x73CCA12A27A7E229ULL, 
            0x4CF002CCE6AE6B56ULL, 0x168CF7B6EE3F8A75ULL, 0xA162223A4A6487B2ULL, 0x8101D541A1215356ULL, 
            0x625EA2BB14683692ULL, 0x94C0293747D3809DULL, 0xE5A33E330DD72450ULL, 0x53FB3CD95F015D14ULL
        },
        {
            0x1C9C4F29B8097A17ULL, 0x5CE625E9D76A1435ULL, 0xC4A8E550E96F9E54ULL, 0xCAA416054638F647ULL, 
            0x9AAECFB14A6D27CCULL, 0x10006CF300123322ULL, 0xE98DF9A5B933E32FULL, 0x25978DDA79A6239DULL, 
            0x5EE347BFB8D5FD9BULL, 0xE2BAB0950ED1DCF5ULL, 0x62289FD181770499ULL, 0xD9051328B866EBF9ULL, 
            0xC72EA6D46A072083ULL, 0x351BF02E62E7AF1FULL, 0x81A428EE578DFC97ULL, 0x1B1C76FF17744572ULL, 
            0x7AC74BA8990E0C90ULL, 0x25A065A57723DD3EULL, 0x8D5D2ADDCCFB59BEULL, 0x941636B234BF6FBEULL, 
            0x35018A17AE4B1A92ULL, 0x877DE15F08190B3EULL, 0x784CCEDA4F969000ULL, 0x0CB4805B5DF63665ULL, 
            0xCCB3BB019E548FBFULL, 0x4E2D6430274699ECULL, 0xA90EA5B50237F346ULL, 0x0D15652963401491ULL, 
            0xE6356C1CE5A123C4ULL, 0xFA2C7F5055A8226CULL, 0x568414DB9EBC81FDULL, 0xA9F8937A3450C0CDULL
        },
        {
            0x22988062FD658424ULL, 0x2B09F78496C8EE8AULL, 0x83F5CC317DBC674EULL, 0xA48B0980EAF123C4ULL, 
            0x06FC230AB1C47DDCULL, 0x0236705510E6EA55ULL, 0xB19F62BDB9E830ACULL, 0x134BE34ED57289C8ULL, 
            0x020EA6CEA6F2F360ULL, 0x3426AB37E9B7D9CCULL, 0x6B5B551B6A0A9F83ULL, 0x1F7D4C5AE5AE439AULL, 
            0xA2FEB11AA10553FDULL, 0xB3CA8593D30A8780ULL, 0x13A674DCCA61ABA6ULL, 0xFAF3A2677E4FC536ULL, 
            0xCBBD2F79AFB54B14ULL, 0xB21ECB6EF2A9C384ULL, 0x1A4A38AA97DA3959ULL, 0x02F06E61AAEBFB10ULL, 
            0xB2134F631EDF3BFBULL, 0xC8859B3C63E1CDF7ULL, 0x27DB4DE0EB4A66CBULL, 0x245546AEBDF77FF6ULL, 
            0xAC2ACF5C80F8F979ULL, 0x28C2CDB6B71C4A7BULL, 0x7760040BF4C249DEULL, 0x86BC13225822EE52ULL, 
            0xC260E0FADB07F178ULL, 0x7BFCF1B0F1973F8AULL, 0xC7CD858AF3AD486BULL, 0xF5F089A644897EA6ULL
        },
        {
            0x500CFBDA810D58B3ULL, 0x8F521B853BB0A971ULL, 0x0787546F616812E0ULL, 0xAC004A4511D93297ULL, 
            0x2D5C4FE766E7BF23ULL, 0x18D7EF8D87FBE639ULL, 0x61EB5F8A014E89A6ULL, 0x5B28D409684BFAEDULL, 
            0x42CFFE02E49861C1ULL, 0xACA01D56C09E8AE9ULL, 0x629E357383313739ULL, 0xBA558F033B1F2F05ULL, 
            0xCFBB3DC297FA8340ULL, 0xC35798284D801D4AULL, 0xE6AEA6790E95C0D0ULL, 0x257148AA08D22682ULL, 
            0x09EEAA4DEAC120B8ULL, 0xDD1A8DF97187A8C9ULL, 0x85AED0BD1A4DE100ULL, 0x9B03C62B3B3CFB80ULL, 
            0xBB4273BD4B075EA5ULL, 0x14581A6560C298F3ULL, 0xFBB44B7DBFAFE4B6ULL, 0x97FAF4C439855FB2ULL, 
            0x14AF44E383441743ULL, 0xA9DF3461BCF44993ULL, 0xBED96FAEBA611CE3ULL, 0xE88BBAF5768BEAADULL, 
            0xFADA00AD3DB91C81ULL, 0xE294862074939CFAULL, 0x4113A4BEA8F6C405ULL, 0xE895292CA863548DULL
        }
    },
    {
        {
            0x62AB2BCBEB0A7841ULL, 0x734A125DBFB45DEAULL, 0xDB36BDF7D619E965ULL, 0xF71C80C5E1561087ULL, 
            0x0EA7C083408ED687ULL, 0xA67768FB4ADD5F3CULL, 0x2C0385C7F88A06EEULL, 0xB0BE7E509F740169ULL, 
            0x0B464CD1DDA0FB78ULL, 0x1F7D8F7F84A3134EULL, 0x1CA4728D0FFE0C7CULL, 0x4A4224E5027FFD7FULL, 
            0x2BA382DBCDFD0528ULL, 0x599DE9179349EA06ULL, 0xAF2BF8A5D9B41D29ULL, 0x38FF3FE64E666B65ULL, 
            0xC1BB723C0853D85CULL, 0x17FE6D9822BB13CFULL, 0x39496FD6DC46E818ULL, 0x21B0D673BD150609ULL, 
            0x04AEE06887DB9AE8ULL, 0xCECF76240E1F0796ULL, 0x837272CFEF3C29C2ULL, 0xF4DEE855EEDE8391ULL, 
            0x393D66264E97E5CDULL, 0x1289DE8636B11888ULL, 0x89A3DF35AD6E40FEULL, 0x6E88592766C76EC3ULL, 
            0x1FF75805168F44F2ULL, 0x6051640815859086ULL, 0x77D8549771ADD167ULL, 0x580F6D6358FA96FAULL
        },
        {
            0x6F57EBC9296751C4ULL, 0x481D802C2068F59BULL, 0x98F2B09E753ECD13ULL, 0x265E733F8DE4190BULL, 
            0xAB4058E5853EA285ULL, 0xB9AA4C2E01EC2AF7ULL, 0xAC9450AEE3721772ULL, 0x6A67964217894C88ULL, 
            0x40896BFF4F60E444ULL, 0xE85D83E322332048ULL, 0x65720C9C267E9DC8ULL, 0x98222457942E9B6DULL, 
            0x2168F35A4D57042DULL, 0xF6C922C44954E30BULL, 0x83A96B3A2643850DULL, 0x67968D2E05F187DDULL, 
            0x4477ECB05E00CA0EULL, 0x7A7B5BA09F87554BULL, 0x257B7F72158E2444ULL, 0xDE326452CFD1B0DBULL, 
            0x58EC543EF8964765ULL, 0xA6AA59F37D37F686ULL, 0xA457841BFFF259F8ULL, 0x58651C5E2D13DC7EULL, 
            0x113E3BDAE3A6E9C1ULL, 0x2DED9653858A0C12ULL, 0xB476F40F3C977498ULL, 0x39EB8829C587C243ULL, 
            0xF8718EFBBE69B5F1ULL, 0x444A18D3F9602445ULL, 0xFC1EF2CAA6128AF1ULL, 0x1A9A60B95D9A6647ULL
        },
        {
            0x2FF0FCD8D0DEDB1BULL, 0x58ABF6FE3F0674D4ULL, 0x273BC149665AC75BULL, 0x6B2CB54E4587D158ULL, 
            0x6D9F4BDC12713D1AULL, 0x2210249F14A7EBFEULL, 0xA7F3F46D569E6EDCULL, 0x716D13C2D459C8A2ULL, 
            0x2E1C0DFCA6DBBA8BULL, 0x59AA962A87EEC625ULL, 0x2A33300D6724B534ULL, 0xB6FB4173F2A421BFULL, 
            0x958B14E3A51FE506ULL, 0x1DAE380C5DFCC146ULL, 0x7AFEBC53DC95D405ULL, 0xF6D4E781F1D123E5ULL, 
            0xAC8FA8233573BECFULL, 0x7566949818AF3111ULL, 0x30C31E57FA9B6D7AULL, 0x6A4FF5DD0FAD9849ULL, 
            0x8934BA90784782BCULL, 0xA1D7EEFF45DCD05FULL, 0xC6AB16DDDC85AAA5ULL, 0x4C7983DDEC696B5FULL, 
            0x8EE08333EB5D1348ULL, 0x483CA41E5BF27777ULL, 0x731898BCD97FAE1FULL, 0xCEA03F6C88D02222ULL, 
            0x606CEFD15E7253D9ULL, 0x5AE8D967B2AAA61CULL, 0x8BD2B5A7A9D1B692ULL, 0xA1400864FD5E8A30ULL
        },
        {
            0x433C3EB50404597FULL, 0x6A46A8BB78AA7E83ULL, 0xE61BBBB1BD252D6AULL, 0xBBF85A337EC8B67CULL, 
            0xF070625EC009677EULL, 0x78FA586BDEBFA604ULL, 0x7FE3AE05CA423FC0ULL, 0x9F671B0459DF2634ULL, 
            0x5643D0682B7A0020ULL, 0xD108F790B4FF5E4BULL, 0x114E717FE12D2B66ULL, 0xCB36A299D0E6798BULL, 
            0x390DB117AF555F4DULL, 0x3B336ACE892DB431ULL, 0x1540FA7B15AB00B4ULL, 0xCA392E5239E26662ULL, 
            0xCDC876CEAD4E442CULL, 0x8DB7CBB966B6F3E9ULL, 0x56A3BC621269A4DDULL, 0xAFC8CF15F7B7F92FULL, 
            0x9B8B9B6D20567C53ULL, 0x1F49F9260DF138ECULL, 0xE02168815907EE45ULL, 0x55EA8E80A5C24A56ULL, 
            0xAA5530851F878958ULL, 0xAD7A81F6ADD8F280ULL, 0xEB3A6FB40B9AAF7FULL, 0xA09E6BB48C1381F2ULL, 
            0x1C2F47BEF33FDA84ULL, 0xD9C295C73D9D9584ULL, 0x09069664A40B830DULL, 0x487AEBE910FDA5D3ULL
        },
        {
            0x42A1B140FC6BA672ULL, 0x24C5850FF0560D75ULL, 0x592BF097A6859D76ULL, 0x0A4AE1726F614F94ULL, 
            0xFEBF920E833C1C09ULL, 0xB33F3AD611B7EBABULL, 0x992AC2D4FFC552D4ULL, 0x7DABCECD79097A0FULL, 
            0xE1DBD0376D01B69DULL, 0x97AAEA096A360410ULL, 0x03B184D07171CC53ULL, 0xC96B2A303A1126FFULL, 
            0x181B3964BBA218C3ULL, 0xFA9380EB6E2449C3ULL, 0xD190A3A11BB689E0ULL, 0x33B7DF23AAFA7D60ULL, 
            0x5BEF3DEE62DC5A9AULL, 0x20B39B85CDD184BCULL, 0x97AEB88BCD74B529ULL, 0xA512184119E99E6CULL, 
            0xAB7C3DDBD3CDFFA5ULL, 0xBADA9CBCAD9A7005ULL, 0x798C90E5B64948B7ULL, 0xBDEEE701F5712CD3ULL, 
            0x60A37BFE5CC40054ULL, 0x7F954833C47A00EEULL, 0xF82AA693E7103628ULL, 0x8A9BC69AFE8F23B1ULL, 
            0x381615D3F2CAAB52ULL, 0x2A437C3AF9C6E91BULL, 0x4744583CD4CDF700ULL, 0xD0FB7B617AC81B89ULL
        },
        {
            0xF8F1D525B22CB130ULL, 0x5080062F279D3F84ULL, 0x796D389EEAFC4106ULL, 0x92FDB7FCEEC9C75BULL, 
            0xEC0641B3D5249D5EULL, 0xD3AE0FEFCFDC6C10ULL, 0x2EC021299D014D9AULL, 0x450F536AF496324AULL, 
            0x16166A37A8E19A46ULL, 0x808DAABC8FA7AF20ULL, 0x73961798DF364D85ULL, 0xCCDD92C7022CF305ULL, 
            0x26CE847CFD742522ULL, 0x1D77FD184E7F545AULL, 0xA95A67E98881F071ULL, 0x08A978BA7E4D975AULL, 
            0x924DF3236AD2664CULL, 0x8AA36FC23D9E8666ULL, 0x6BE990EEA51030BEULL, 0xDCBF59FB6736A815ULL, 
            0x8EA4941B50C8A2B8ULL, 0x2D3CD61E6B5823C0ULL, 0xFC762F1FD5339DD7ULL, 0xA721A162D00455BAULL, 
            0x38D0010102EC3254ULL, 0x6D690ADFCBCDF4ECULL, 0xC980AE7A2EBDBD60ULL, 0x488F5D0E374200FEULL, 
            0xC91AA139331B80CEULL, 0x0611D68BCC69F104ULL, 0x22E9965FBC8C862DULL, 0x3F75CF5BB5660385ULL
        }
    },
    {
        {
            0x01D5E29936224DF1ULL, 0xDA413E16B27E5AB3ULL, 0xC69F0EC08FF2B635ULL, 0x651BBD7BD8149E8EULL, 
            0xAE8245994101FC3AULL, 0xB094FD473CE11B29ULL, 0xE8C4D6F2853EBDC0ULL, 0xA7158AB9B4BD96E4ULL, 
            0x4A2A80E0D2384A3BULL, 0x22D59493FACDF1CFULL, 0xCAC44D9554B88291ULL, 0xE9C2DE1BA47F1CA0ULL, 
            0xC1501E6816EB1789ULL, 0xE19196DD70D17C57ULL, 0xFF64F4F92AAFE792ULL, 0x0E5112D12202F9B5ULL, 
            0xD4CAFE9DE991FFA3ULL, 0x411CFA1ED0E30123ULL, 0x3C7728E8E5CC0018ULL, 0x2B756750E26A7F10ULL, 
            0xD4895071CEB6151DULL, 0xDB1FDB69F4C7A15AULL, 0x9A61FA0E538ACC2AULL, 0x2B1A97373DC8E3F9ULL, 
            0x391CF3064C75E029ULL, 0x147B33C8C52E07A2ULL, 0x2CE8181930FC7164ULL, 0x88FD29C01B7F919BULL, 
            0x94CF2380EC33890DULL, 0x490F676331CBD82CULL, 0xD54F7C69B2F81435ULL, 0xBDF28E1F2AAB5214ULL
        },
        {
            0xC270DB4D69240C1AULL, 0x330D3D325459030EULL, 0x4CA5999D5154672FULL, 0x8662E4096408B9CAULL, 
            0x31F19A5AF2E82CF2ULL, 0x8A74AE03D0331B85ULL, 0xFA5357634B13979FULL, 0x63F7DAD3936288E8ULL, 
            0x571F4466B8242D1BULL, 0xB26C470B4033CF78ULL, 0x5D1FFF17A855F7CFULL, 0x84125F764D6A7821ULL, 
            0x1FFAB7FD9F686C43ULL, 0x22F2B354B7E74633ULL, 0x56CF39BA0E3F8342ULL, 0x2A84FF299135F430ULL, 
            0xF48278E6ACD08F41ULL, 0xC5B4F9BE8BC1A014ULL, 0x63E473CBA20AFB39ULL, 0x444517C08AE897B7ULL, 
            0x66398CD076321BB1ULL, 0xA0F3BC9C2FE40FB5ULL, 0xAC00BDEED72440F8ULL, 0xEF9780989DD9A00DULL, 
            0xD3BDE5D5CA15667DULL, 0x68C4DC7BEE2E83F4ULL, 0x85444F1BF0400E02ULL, 0x98FB2237772298FBULL, 
            0x6F7D858882622B15ULL, 0x60E99A97E77B7A5AULL, 0x9F040CC088DDFFA9ULL, 0x50AEB4BF9AB98DA9ULL
        },
        {
            0x408355D9E450A96EULL, 0x0BE39D2347E1F1C5ULL, 0x3F96FE79A2AAAF28ULL, 0x29773A03CD6B550BULL, 
            0x2688ACD6721B078FULL, 0x1956A7637BF0F14CULL, 0xA67205D2F39F2F42ULL, 0x90E48577B8F41884ULL, 
            0x4E483E97DE9ABEDBULL, 0x8A8F95E7CBF4E069ULL, 0xBEBD7F3F9BBDEF4AULL, 0x4C9E1F96B3FFEC39ULL, 
            0x9AAFABE8E046D7BFULL, 0xD90B7007D3391125ULL, 0x8FCC33D674F93CA2ULL, 0xD2C191B5085AFCBEULL, 
            0xA7D66CB9ECFF93A1ULL, 0x2FD02E2D263EC81CULL, 0x69DDD9F40611DCB2ULL, 0x511F894FB4917472ULL, 
            0x0D0E5D52A82DCDD5ULL, 0x617FB4A3A49A8140ULL, 0xEE7EB7613F4E139FULL, 0xAB536B288F4DA50CULL, 
            0x63EF4CC47759A1E4ULL, 0x800B307DB33E6967ULL, 0x08B2D3E5AC03C7EFULL, 0x55C692DB558B7BC7ULL, 
            0x3B48778787A01002ULL, 0x22E9671E115DCE3DULL, 0x529FE8FDD78723A1ULL, 0x2DBA303A22360D9EULL
        },
        {
            0xB8162B8A3ECF0836ULL, 0x5E6F5F0FE52237EBULL, 0x54856DB21F680D95ULL, 0x5C4656F221071C3FULL, 
            0x6BF10CE5FD6B46BCULL, 0x281D79E7CBA0D43EULL, 0x33D55519E6EE6159ULL, 0xDCDAB0787E3D5B15ULL, 
            0xCF98AA01BD91F8C0ULL, 0xD34BAAAB76A1F62FULL, 0xA0C18297B3285EBFULL, 0x81DFFBDC1CAF248BULL, 
            0xBEC84B47B060E226ULL, 0x5FDAC5F1A06B65D3ULL, 0x89C56D80068D5DF8ULL, 0xD555E49988BEBBB5ULL, 
            0x8B70382D4E9E1608ULL, 0x2BDEB2550BF55798ULL, 0x10E5735C63D8758AULL, 0x562AE6F5B31D7E11ULL, 
            0x42BCFDE3910FD11BULL, 0x0D977FDF71B74446ULL, 0x7A413B0A497D6EE1ULL, 0xD1A3E8A79272B278ULL, 
            0x37AE5F66314F4A9BULL, 0x14DFC8B2FD38647EULL, 0xA13AC3A91AC0370DULL, 0x67CF5FE2F04B3827ULL, 
            0xB7EC90802C0B5DE5ULL, 0x381B4F1726BC89A4ULL, 0x5FAF53A89554283CULL, 0xDE2CA2DE9CFA6382ULL
        },
        {
            0xC0D351EC3229F1CFULL, 0x9E6734F356128F7BULL, 0x0C30676E6A312E15ULL, 0x89C247B4DB5FE83CULL, 
            0xF88830D3116C88ADULL, 0x997082C5864AE872ULL, 0x37305A9A5C6A07F4ULL, 0x553FB5526C0B978DULL, 
            0x64738AA4C5C4A690ULL, 0xDFA6C04A6C7508DCULL, 0x954E65AFB56D21B3ULL, 0x8F9EF85A38F7C59EULL, 
            0x587C96D59884F942ULL, 0x6D3C0F5BF63A46B9ULL, 0x9D1065432A133D74ULL, 0x342A84FA7E4E485CULL, 
            0x096E81282A8C400BULL, 0x930333C26A4D3E9FULL, 0x991C582871EE146CULL, 0x94993F97B707A74FULL, 
            0xE65B5E18E534889FULL, 0x2345D6A2751AD4DDULL, 0xC25C02349E05DB3AULL, 0xC0C6CB379118C6D9ULL, 
            0x044B1A125CFD9B68ULL, 0xF0513D7DD94474A7ULL, 0xCD752F058FB565BFULL, 0x455070864E075232ULL, 
            0xBC24C710A6F75473ULL, 0x6CE0AF4271CD2AF7ULL, 0x96FC8114F97B6C2DULL, 0x31BF66522BAA895FULL
        },
        {
            0x0941B38197A1B720ULL, 0x0F0849AD2DB594CFULL, 0x6BF024F4D69FBABAULL, 0x7B5A0E27216876FFULL, 
            0x8E7ED956CB80C538ULL, 0x2543719A11D3ED9CULL, 0x25B3C7FBD1315170ULL, 0xD8BB5DAD35F0CFA8ULL, 
            0x6AAECE9B9223FBBEULL, 0x9C2EF609BC576AEEULL, 0x6A537160B458F8F7ULL, 0x595D00747E5EA52EULL, 
            0xA21C879AD8C1259EULL, 0xE224E8350ACE2E48ULL, 0x7075CFF7A35E6EB9ULL, 0xA2C392271BD3691FULL, 
            0xFE5BF82728264322ULL, 0x9C39A891E70BAB44ULL, 0x9942F83C56B896A0ULL, 0x2BD11C35B164E035ULL, 
            0xB42062FCF6F8F114ULL, 0x747DBCF55F767FB2ULL, 0xA05DB7EB2F7D7287ULL, 0xA40DB8C8B0655A03ULL, 
            0x9BC9D303E93E98C2ULL, 0x39A6B093AF01D6A5ULL, 0x5693B2444E5F0AFCULL, 0x05F9A4A363859445ULL, 
            0x7847E864206CCAE8ULL, 0x30137351CC0A185EULL, 0x0CC43776830B8687ULL, 0x4FDCD207A6F39118ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseDConstants = {
    0x521B6D5D2AA51AE5ULL,
    0x9B230EB6681FA3F3ULL,
    0xAAE54B9833CA0863ULL,
    0x521B6D5D2AA51AE5ULL,
    0x9B230EB6681FA3F3ULL,
    0xAAE54B9833CA0863ULL,
    0x55D3D9109FADF81EULL,
    0x67642EC25DE6A2B7ULL,
    0x1A,
    0xA6,
    0x7E,
    0xF6,
    0xC5,
    0x76,
    0x46,
    0x69
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseESalts = {
    {
        {
            0xA4012803BA84989BULL, 0x10F8E397B5758031ULL, 0x9E13930F7F86DBC4ULL, 0xBC0C8E7D5289897BULL, 
            0x91EEBF4AB2E401CAULL, 0xA4137D1EE6A829B1ULL, 0x5CB21B10EEAE83A3ULL, 0x6DCD1EEE0DEAFCB9ULL, 
            0x15D1F5DB06FF8F6FULL, 0x5F61A94BD0149A2BULL, 0x16205A8C97ACE39BULL, 0xDF667882A951D2B2ULL, 
            0xF33CE58732853DD2ULL, 0xD99CBD2B12718EEEULL, 0x1C0CF82A2613D423ULL, 0x26EBC0345E0E715AULL, 
            0xDD47C99EF31DB1BCULL, 0xA296B85E22FA4AE6ULL, 0x6FDC75BE3878ED97ULL, 0x29AEC202D3E30498ULL, 
            0x5035D45DBB18D7D6ULL, 0xA2AF9BCF497C10D7ULL, 0x1A175A06F01749C4ULL, 0x4C52FA2C37882356ULL, 
            0x808E4F82EAA6DDECULL, 0x52EA9D0FEFAC38FCULL, 0xC76A1BB9238CA710ULL, 0xFEA0FD18B2AE08CDULL, 
            0xD8EE0DE988ED2087ULL, 0xA157E6DDFDB2FE81ULL, 0x52236C0E1F67777DULL, 0x823A358CC3910B19ULL
        },
        {
            0x2E3E2894280318B4ULL, 0xAB1BD3087BA80363ULL, 0x67AEB9D0027AD54CULL, 0xD09676762C3F29A0ULL, 
            0xEB81E9C2CF4D9F64ULL, 0x5AB1B291DB1AB966ULL, 0xF3647D1CAC964324ULL, 0xAF632C447471F4A8ULL, 
            0xA3B69706BFA1C296ULL, 0x014796BAE7A4EE88ULL, 0x17259A751F80759EULL, 0xBD44F0EA71411A26ULL, 
            0x0E1ADB7A36744AFCULL, 0xBD5E02B659DE95F3ULL, 0xC2C3785797FC80EBULL, 0x9514A9520535A132ULL, 
            0x6D06372C75F27045ULL, 0x8518D7766BB710B7ULL, 0xCC223AA7A87CE29CULL, 0x50012AF1C4CCEAAAULL, 
            0x8D4FAF66BF3A8E2CULL, 0xEDD03A4810E4384DULL, 0x480F4160E7B3B2B5ULL, 0x4800170122829F72ULL, 
            0x70A68CE6604DDFCEULL, 0x4E92957D24DB6F8CULL, 0xFF8756E04DCE5E0CULL, 0xBB6235A53D971BA3ULL, 
            0x213938F804643ED4ULL, 0xC6FC5DE6E379A7EDULL, 0xF1197E9ACD367E66ULL, 0x050DF43517698742ULL
        },
        {
            0x339EAD277B978A0AULL, 0xF86436817FB369FCULL, 0x9982AB8499ED0E17ULL, 0xC8125416DEE29015ULL, 
            0x66D5DCBB6DA0A461ULL, 0xADE391DA58FAFF96ULL, 0xD1BE0E74E1AC0705ULL, 0xF2A486DC2626275EULL, 
            0xBD14ECB53102EC71ULL, 0x45C5F827DDF5A1B5ULL, 0xD31E1ED10EE08572ULL, 0xE1C0FB5730A8B9DCULL, 
            0x52E9179E163E9805ULL, 0x4AAC9DE1715F219CULL, 0xD588B0AB62B82F79ULL, 0x3CE15E1A2A863290ULL, 
            0x09C2D314944FD82FULL, 0x82AB114F18E68AC2ULL, 0xD83DAD5B88EEDDE4ULL, 0x8A4E4737340A4156ULL, 
            0x2224CC292BE18897ULL, 0x439F21C0788CA0C5ULL, 0x28A54171B0149F0BULL, 0xDF85B87C3DAFF34CULL, 
            0xC5BBA7E657DB562FULL, 0xC3CCB2E66C24B90AULL, 0xB53814A316368434ULL, 0x4CC5C6E9D07CF123ULL, 
            0xBA66194AFB450ADAULL, 0x62ED8DA88C8CC0A3ULL, 0x56D0329E0D8A7AF1ULL, 0xD34889B0DEBFC0E5ULL
        },
        {
            0x01E363B6E7450F57ULL, 0xEE851BBE5350C7ABULL, 0x2D261E1EAF1D379AULL, 0x9C69A8F9386D8BFFULL, 
            0xCD1C4367EF52E886ULL, 0x5384420947A9329DULL, 0x2B3B706FA1B3F9F4ULL, 0x4584CF51F3320539ULL, 
            0x5987CE288B49A783ULL, 0x1FB0F422D9988D09ULL, 0x414AB55D549C0720ULL, 0x8F63FCF30BEB5EF6ULL, 
            0x0A77E4DC3106E610ULL, 0x7E97D263E3D578DAULL, 0xFA7D50F8EEEEB4A8ULL, 0x2F26A0257639A9F8ULL, 
            0x3BB816C2185F13B4ULL, 0xF6FCCAC4807125E9ULL, 0x8A43E4D0479D7A97ULL, 0x06454687B2316FA9ULL, 
            0x7D8820430ED542E4ULL, 0x8739114486971929ULL, 0xBBD5FC49D4DEB16DULL, 0x92B62556EA8441F3ULL, 
            0x6D1D7759EB5D8C10ULL, 0x748966CCA0A72215ULL, 0xDDAA555A04E2945AULL, 0xE01EBE9198D3EB27ULL, 
            0xF50EA2B723062C67ULL, 0x2223B4E2E0DB9215ULL, 0x1A877DA842ECA658ULL, 0xB11B37479534AEF6ULL
        },
        {
            0xB169EDB2FAAA8B6BULL, 0x74F5DFA43DF1EA5AULL, 0x637F20156871C0FAULL, 0x5F53EF981456CA0CULL, 
            0x217568771EF4E247ULL, 0xF8E710B943062800ULL, 0x547B374EEE36C434ULL, 0x0D9EC0CC99F73B3CULL, 
            0x4A5591CBC4A1E915ULL, 0x83F18851A859A5A5ULL, 0x6C48B897E36F86E9ULL, 0x27317A35E7A2B96BULL, 
            0x2F52F05F94C9E039ULL, 0xAC13525D2C6B47C4ULL, 0xE7A7D6D69E3DD6B3ULL, 0x3A209F04B123FF89ULL, 
            0xDB5FD0D8A9BBC39BULL, 0xD634CC3FB5D1D0A4ULL, 0xE6E61FFE363D6412ULL, 0xE6EC789BA11EEC40ULL, 
            0x8FB7E948B475294DULL, 0x99A1742C2D5C4185ULL, 0xDD725D595F8332DDULL, 0x75503BB5C58BBDD7ULL, 
            0x35B78FC8CA29E99CULL, 0x602E102B50CE8E3EULL, 0x8F64547295D0C8B7ULL, 0x8DDD47F6CC503B71ULL, 
            0xF60B2CE170BADAB7ULL, 0x4E74A5A1979AAD15ULL, 0x337117EFA67C0EC1ULL, 0x316CDD1855973C66ULL
        },
        {
            0xAD22A2A38821F596ULL, 0xBBA72138C0DBE61CULL, 0xBCEB121DA34450AFULL, 0xB6FD92D750A177ADULL, 
            0x3CBD21A1129273D3ULL, 0x929BCC417AB3EB13ULL, 0x1EC238E67C60FF48ULL, 0x82CA572211513102ULL, 
            0xADCC675C12DB20C1ULL, 0x9DA83F9965407451ULL, 0xAD1ED24D080CE974ULL, 0x83AF95F70225E4C8ULL, 
            0x91DCFC50F1D1F8A3ULL, 0x67A132F9DD8A367AULL, 0xCC95DC929BF99A9BULL, 0xDF6AE09F6D9ACCFCULL, 
            0x8E1D704A1CAC2DF3ULL, 0xB9E284B37AB08808ULL, 0x7E94CE9374EA98E0ULL, 0xCA02292BA9F38C0EULL, 
            0x5B72C9E3EA45B6C5ULL, 0xF123F77EB871BD9BULL, 0x61511E05DC9E5E4CULL, 0x08556F58135F1DB9ULL, 
            0x823E2E4AEDFEEA5AULL, 0x8195448EBC71CF26ULL, 0xC4D779E182B4311BULL, 0x55A23B0C46AC523DULL, 
            0x6923CBAA46B28AA2ULL, 0xB3F91EB2E3A41A27ULL, 0x94DC0DE5AB42D22AULL, 0x74230D7EF0DAB9C9ULL
        }
    },
    {
        {
            0x8162C5235253BC18ULL, 0xEDD0665F62FDB1D1ULL, 0x0177ADBAE63F1B87ULL, 0x0A66562E56B0B031ULL, 
            0xE5046D9AB068342CULL, 0x0E90948A3B9D1533ULL, 0x91FD15482E6CEE61ULL, 0xD7DA9D2876F67FF3ULL, 
            0xDD88F49915DEF3FFULL, 0x4006FCBF414ABD79ULL, 0xC1411832A38867E3ULL, 0x40FE754E79F871EEULL, 
            0x65E77D229142CEDDULL, 0x52B2A3DBCF14579FULL, 0x62FA0DC52A094617ULL, 0xBB232AE36373ACA4ULL, 
            0x5BDF21422AE2ADFEULL, 0x3BB30B23506430E7ULL, 0x35D64BCAEEE8DF19ULL, 0x2EAB6C76BB5D1893ULL, 
            0x776C83189800BEB9ULL, 0x409C8241BE42E183ULL, 0x1372B08B66A30313ULL, 0xD80BFDDF2787CEF2ULL, 
            0x43423EA2AFBFB396ULL, 0xF11A0399CE06E452ULL, 0xFD309156EF9BCE3DULL, 0xAD35F83D635A6F4AULL, 
            0x2EF7D286A775A370ULL, 0x1DF846130DDB8336ULL, 0xEADF129A71CE35C3ULL, 0x2C8D5BBF89FA6DDFULL
        },
        {
            0x37957CE0AE3282B0ULL, 0x94A0759E36462F6DULL, 0xBF2B2D8E7ACD449DULL, 0xC165A0A9EB4F8A01ULL, 
            0x5A8C9FD0CD87B401ULL, 0x2C760CDAF76FD024ULL, 0xC62252B6B6DAAF5BULL, 0x63DA9DC717F6DC84ULL, 
            0x5F1A0B423D7C2FE2ULL, 0xB79047725C07164DULL, 0x98C4AE800C43D736ULL, 0x64F1925C361198CEULL, 
            0x0B341DD8B83BCCC1ULL, 0x64774B3E9745B35BULL, 0xBB04D53AA83B2FA3ULL, 0xD73430C9685E813CULL, 
            0x0C79FB4ADF85EF03ULL, 0x038424EAA23E68FEULL, 0x74FB43F0FD54E654ULL, 0x85D8B70D40FC8243ULL, 
            0xB15E19EC672D53EEULL, 0x8FD6D77F20892501ULL, 0xF2CD2E8B5ABDAE6DULL, 0xAF78BF7F4672BF86ULL, 
            0x16399121CEA4B448ULL, 0x62CC58F39D402622ULL, 0xC324941D4AD310BBULL, 0x3D0BA018A4C3257BULL, 
            0x3DE1380B7DE014D1ULL, 0x8ADF5D7C0527FE15ULL, 0xDAF385C517BDCA52ULL, 0x40D27FF19BB483E1ULL
        },
        {
            0xC96ED6B8C9B86D53ULL, 0x19D625A6F3844DEBULL, 0x84605C8A37BEFB16ULL, 0xCD4EFEF333116F2BULL, 
            0x4A8A845A6383C873ULL, 0x3AB9593DB6E40F65ULL, 0xB6966C62E425B07FULL, 0x157BEB116585840AULL, 
            0x01FD1132BC32453DULL, 0x25FAC97B43547138ULL, 0xF9FC0480DF99B23EULL, 0x5353A7AE1ACB80FDULL, 
            0xE5A64588DB46B04EULL, 0x86FD26D65B16E7E3ULL, 0xF955B075F5087295ULL, 0xADE4E2C6B537099DULL, 
            0x46674AD8E2A57D44ULL, 0x7D7B1D0D1FF997B6ULL, 0xB7F9C13C672B6CF9ULL, 0xC1365ED8ECC8AFB8ULL, 
            0xA689200FBA606250ULL, 0xDF2AE07627F6BC9BULL, 0xA45875DF5604D729ULL, 0xBE5ABE2E618C9AB9ULL, 
            0xD883B3BA4D372E2EULL, 0x0CF5108018622DA7ULL, 0x27358C55C750D102ULL, 0x0D0B737678CBB307ULL, 
            0x4AE4DCAC8CC616A2ULL, 0xA2A155EAD46E874CULL, 0xC40F6E7DCFE5DFFDULL, 0x29125CE853C86210ULL
        },
        {
            0x8A393C186EBEE3C5ULL, 0xF1413309567F064AULL, 0xD9A6A8271328687AULL, 0xEC5A44AB2EB486C9ULL, 
            0x5BF7F5A4E24C7155ULL, 0x445C6AFB94C1BEF5ULL, 0x6A4936BAE4B4CC6EULL, 0x9F35089C0178DD82ULL, 
            0xDCBBC6C0C3E0FD91ULL, 0x25C35D093D0CE8E1ULL, 0xB32D49F3BBA67E6FULL, 0xF0A39934349347ACULL, 
            0xA633475FE9B91D45ULL, 0x63593C2B99962CA5ULL, 0xCE5FF7E6B843BBB6ULL, 0x0E00CF23C73892E7ULL, 
            0x9D4D8F308CB0F558ULL, 0x651903DCD90363F1ULL, 0xF14803E5288D7D1EULL, 0xBE761663F8021BB3ULL, 
            0xADBF7B1A611598C2ULL, 0x6A9C045F6569DF78ULL, 0x34B28A13F8F6F85CULL, 0x5ABFE99CE3E07646ULL, 
            0x2F8DE74535AB4449ULL, 0x575D742C26F32068ULL, 0x6649BB28F70F7347ULL, 0x7394781C38EF6508ULL, 
            0xA7A15D923CC62835ULL, 0xA6282A434B735789ULL, 0xDD7B85423070A831ULL, 0xB851D582AA1CEC5FULL
        },
        {
            0x5E1EEEAE6A125B2AULL, 0xFC6E674DA373FBF9ULL, 0x3C9D2CF7C3536FBDULL, 0x928D6DC0990EBE13ULL, 
            0x3A2D67FB237BE769ULL, 0x1A0BF6902E51B1EAULL, 0x6E2E70A4AA042A28ULL, 0xA6D82C712FAD07DFULL, 
            0x21848A37019B8779ULL, 0x917ACEA9CFAA3429ULL, 0xFFF58AF82DE8EB6AULL, 0x89F53939A1F34E86ULL, 
            0xCBF7670710676889ULL, 0xAB39BEFB5DEEED2AULL, 0x4DC5BF6EDEC86144ULL, 0xE5A1797B60E15A88ULL, 
            0xFD015C3ABEC80DFFULL, 0xF74494A479423254ULL, 0xF791A7151164644FULL, 0x71E750FC0C9219EDULL, 
            0x448340711D4606E0ULL, 0x4510FDBDFAC8095CULL, 0xCD9D7F030BEE6EF0ULL, 0xD7463EE30C2B1B8BULL, 
            0x6B729134604E4668ULL, 0x0B3F57085D8C7684ULL, 0x4848137DE3E0BEEAULL, 0x944CACE4782B5644ULL, 
            0x14D48F1CB596DBC5ULL, 0xFA7D02F8E1FC77C4ULL, 0x3619996213A897D8ULL, 0xC112C50B6221CEC7ULL
        },
        {
            0xD37E1255BE46858DULL, 0x9DB01ED130140437ULL, 0xF2AEB19D375AF830ULL, 0x66A099982FEC8CA9ULL, 
            0x35AA2377D7F563B0ULL, 0x15C140B2652946C0ULL, 0xC1CEA9D50DD34C67ULL, 0x1E6C0C618CA8ED86ULL, 
            0x3DE4729ED99A7D97ULL, 0x0B74B1DC8496D7F1ULL, 0xEB6EEBB363D430B6ULL, 0xA3D8F2AF3AB8DF31ULL, 
            0xAB67D341EF45E623ULL, 0x14CFC9B0B9A22F8EULL, 0x65C460B6FCBDD3F0ULL, 0x8FF06340A7E7A4EFULL, 
            0x17D3F10AF6B4C136ULL, 0x76C12F7AE4749455ULL, 0x07CB766957FB4982ULL, 0xE1E68363362FFCF1ULL, 
            0xA32410E96C2763ADULL, 0xD0D62ACBD9C76CDEULL, 0xFD73BBA858F47238ULL, 0xB1494703E6D2740AULL, 
            0x95E841A40410B058ULL, 0xEA5E87125756CB30ULL, 0xAE63D16896BDDA8EULL, 0x26B3FF784BC5051BULL, 
            0xD1CC243B9E2279D2ULL, 0x3E125FE89D3312CFULL, 0x9B7F455D1FC7EE61ULL, 0xC89C32EDA114631DULL
        }
    },
    {
        {
            0xED50991250484A10ULL, 0x3F1B06081FB499C7ULL, 0x6F4B9D53D97FA042ULL, 0xF3E3987137BB22A4ULL, 
            0x628253BD1BB1B263ULL, 0xB77D4DC3DDE0259EULL, 0xFB4902FF693923ABULL, 0x11450E86DF723284ULL, 
            0x89AE5E0B3C62B76DULL, 0xDEC6BF9A0977034FULL, 0x3558C028EDAE797CULL, 0xA34A0840D664F715ULL, 
            0x397537FCBED473C1ULL, 0x8C41A40FAE6B1CD0ULL, 0x076CDA0C6A05D6FDULL, 0x653A40A104F22BDEULL, 
            0xAE5AB89B29999B71ULL, 0x8FFAED006E9B4051ULL, 0x1641D50ADC99DC0AULL, 0x3C8E703BD57DF7B3ULL, 
            0x998F31F98F0BFFC4ULL, 0xAF0BDA40E02B64CAULL, 0x6F007E5719B36C46ULL, 0xBA68553B43E23485ULL, 
            0x8FD85E25922AFC32ULL, 0xA1733DDE7CC178FBULL, 0x97296255E35CB515ULL, 0x5BFA6D56CBB21A50ULL, 
            0x4434E40672E67AF4ULL, 0x04C1C8F2EBF3F15DULL, 0xE85D5320E726153FULL, 0xDFEBA61397C777B6ULL
        },
        {
            0xB2A42E725B2A5112ULL, 0x9E3EA7EBCCF9579DULL, 0x2565D9AF262065CAULL, 0x1E03DFE7FEB3A298ULL, 
            0x3BE73CFB4461B1D8ULL, 0xF25AA874798B5A32ULL, 0xA48D43F429F472CFULL, 0x9862044EB81CE849ULL, 
            0x4E0ADE129B523A13ULL, 0x34E6CE67200A757EULL, 0x7CDEADC01CAA857EULL, 0x3A44661A9771FE0EULL, 
            0x77DD51C42AAE856AULL, 0x8A6F3A9FFC2D31F5ULL, 0x18278D8A392FFCA6ULL, 0x74B597B3D463965CULL, 
            0x3ABD9DC90ADD0AB0ULL, 0x592DA3CC174C6814ULL, 0x2A4D6357945EC089ULL, 0xA198C6904F9F999CULL, 
            0x2C1DFB0C781B8484ULL, 0x1D1090F727D879FBULL, 0x4BE12E8EB03CE766ULL, 0x5FB6876FE31EEB78ULL, 
            0x5044AE402D67DA01ULL, 0x2ADD88404CC59436ULL, 0x81905751330DA6B7ULL, 0xA594C17D5EC33949ULL, 
            0x90D2D4391574ABC8ULL, 0x3691A0A1E1A0F792ULL, 0xA92BF485AAE95B19ULL, 0xD5B67ACE245ACE88ULL
        },
        {
            0x7D8C031594F1D2F6ULL, 0xC8DBA2742E998AD7ULL, 0x1809C3F5ED8CEC71ULL, 0x86B73AF30ACC4632ULL, 
            0xC32BD4C20AD23FFBULL, 0x0487DC1FA2D65A19ULL, 0x62CE07C24AEDA3EFULL, 0x6C1839922BD17D73ULL, 
            0x7A972F2588E0F2D8ULL, 0x97C67CF791FAED7EULL, 0x019FDE6D59970272ULL, 0xDAB7EA4BACE129ABULL, 
            0x2D6410DD638B468EULL, 0x95710B7B725B9099ULL, 0x1B94A322A1A4F261ULL, 0x3811994DF6F44D38ULL, 
            0xF077B31A2FA1DD3EULL, 0x15B680919C31669CULL, 0x3094CC70CB9F00F2ULL, 0xFBB534C6E801E1E0ULL, 
            0xCE9C29252AB91401ULL, 0xC306DC42DDAAD5FDULL, 0x7BDAD752A3E86763ULL, 0x704E658CF373A361ULL, 
            0x3E343C94C537BB7EULL, 0x6CE47C8744E06118ULL, 0x9060924DAF20F0DBULL, 0x28262FF9820DAF75ULL, 
            0x1F7CF9BA7477346DULL, 0xC4BBE8CFFF5F46E4ULL, 0x06A75BE02A7EB38CULL, 0xF9BDC2BDFD35A0EDULL
        },
        {
            0xBEC2EA5B8519DC15ULL, 0x626CF7B4D06C3FC2ULL, 0x511BBDD128D7CDE6ULL, 0x3E1CE469CA366CF2ULL, 
            0xD03C1BE3775BC564ULL, 0x1E5B98670AFCCEEFULL, 0xA23F7645C26088DAULL, 0xDC784592234C33F0ULL, 
            0x3C3D5B130C4FC8E8ULL, 0x2C676B95A45428E1ULL, 0xA14E0E5B7BBD0127ULL, 0x8CD718E076F273A8ULL, 
            0x5B790921EAD34101ULL, 0x0AF1CCFAA7FD68E8ULL, 0x664F99AF7BFE2C7AULL, 0x21C61ECAA199B6B8ULL, 
            0x4EB5473E676B5AE2ULL, 0xDE2F2F6546F61265ULL, 0xB29BE009EE8D8C74ULL, 0x7243643FC248FBEEULL, 
            0x3F3E3FA995F153AAULL, 0x546E9B0A9BB28BB0ULL, 0x9070F433C96579C7ULL, 0x9990A3BDDC01282BULL, 
            0x6BC2C39360997082ULL, 0x9BAD760E88FEF350ULL, 0x160A62560DF06FB9ULL, 0x1923DE69D7E69BB6ULL, 
            0xD6347E89042225EDULL, 0xC4126892ED665C70ULL, 0x4D0FD7E39F480569ULL, 0x9F059C9F1AE6A407ULL
        },
        {
            0xAFBEF54F4408B76AULL, 0xC30EE40B5187159AULL, 0x70D97806D50CB541ULL, 0x69DD8EF1EA6AD936ULL, 
            0x5BCB4D0BC10E906EULL, 0xC79D4B78EE0618BFULL, 0xF93F6CB49338A341ULL, 0x3CB272352EAAEB4DULL, 
            0x5B54B9B1CE317A3FULL, 0x50C558278AEC3A5BULL, 0x1D5A39F71428EDBBULL, 0x50B807C095DBDADDULL, 
            0x2CF158963FF3E8D6ULL, 0x112E959F6EEDD8F7ULL, 0x871B74C35F0E54C1ULL, 0x079EDD9A30380708ULL, 
            0x2849281ABFE84B85ULL, 0xE5E5FEE3E9F3586AULL, 0xF7F396CD0872B98EULL, 0xDD6623579A68E8F4ULL, 
            0x7848C8B7CEE841A8ULL, 0xFD701B473AD81E05ULL, 0xD23DECDB5FB2AD28ULL, 0xCD7402294670E99DULL, 
            0x03CACB18D01362F9ULL, 0x3056DE1198E71175ULL, 0x036647F267141E6BULL, 0x2AADAB3DD654CE1EULL, 
            0x0ED13D006BDFE09DULL, 0x030285BA2F897BF9ULL, 0x660AE62A08723367ULL, 0x6B37CEB52121692EULL
        },
        {
            0xECDDFA9A588E9824ULL, 0x726338579CC2E541ULL, 0xCBD8A4FB0E52C9CDULL, 0xB256AE21419894D5ULL, 
            0xAEF77C2AB6A0DC5CULL, 0xC052D5B9AD1EEAA5ULL, 0xB58459B9D87AE0B0ULL, 0x9BA3B39A5D54AF67ULL, 
            0xE13B5CAE5FDC6936ULL, 0x52EFD1F4E26C2A54ULL, 0x7922D714C5A9B16DULL, 0xEB6FF8061331AFBBULL, 
            0xF9AFE21BDBC21C4FULL, 0x300E2AF1EAD7F1A3ULL, 0x51AF13D831BE50D9ULL, 0xC36E79FD995A745EULL, 
            0x3E71241B52F2D8F3ULL, 0x78F471313D829B77ULL, 0xE9D35618DA400026ULL, 0x95E64FBC62F016DBULL, 
            0xD277456106A1FD24ULL, 0xF5D3E1D0279DB8F8ULL, 0x9BF61EFD7EC7FBE6ULL, 0xD0C1D55BA75FA19BULL, 
            0x4240583FACF82265ULL, 0x0C110F5DF7D0552FULL, 0xC57E0D672889C38BULL, 0x6F684128791A3702ULL, 
            0xF157FB05134C3004ULL, 0x197AFEEF089DF02CULL, 0xAD211E1DA9CE750EULL, 0x6E98FD9591075B91ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseEConstants = {
    0x977E97699EDAFFEEULL,
    0x28DCD5A348CB7777ULL,
    0x9307C25E680409ACULL,
    0x977E97699EDAFFEEULL,
    0x28DCD5A348CB7777ULL,
    0x9307C25E680409ACULL,
    0x4AC8092E1ED5F345ULL,
    0xE58B7B4451A56908ULL,
    0x51,
    0x5B,
    0x9A,
    0xFC,
    0xEA,
    0x9E,
    0x70,
    0xCD
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseFSalts = {
    {
        {
            0xF701C77191E03958ULL, 0x825ECB3E678D1B2CULL, 0x99AD9EC6A5CF3F22ULL, 0x0C66F2A014B2B87DULL, 
            0x8D57F71B6504A017ULL, 0xA77B2341C74A42BFULL, 0x08623911E8A13A57ULL, 0x78B5E6D22C557E89ULL, 
            0x83A51B5A6C0780C4ULL, 0xE1EE4147B28C32E8ULL, 0xC78F41B4FE0FAA1BULL, 0x66EB28C4874195D5ULL, 
            0x34992C2564E83E8CULL, 0x9341080880D4CF10ULL, 0xE3CC2E525AC7C322ULL, 0x4F6542E0782178BDULL, 
            0x8875DD41D05A730EULL, 0x9B498B3534A6C0BFULL, 0xF93AD7E8A9F8721AULL, 0xF0B62F822035ED7CULL, 
            0xB26F5B8B1FA71F4CULL, 0xB9E8A7489CD98C4DULL, 0x783C26F3A1F3C2ECULL, 0xFBB8A848BFF56AC3ULL, 
            0x29D8A80CA7180597ULL, 0xF77637E8000D65E5ULL, 0x720B7DE7CABCB260ULL, 0xD76B268FA802E429ULL, 
            0x93FC9965259F4D6DULL, 0x9D8EFFA25249B4C6ULL, 0x3EBD73BB51CF3979ULL, 0x3FB797AC01F1DDB5ULL
        },
        {
            0xA449A0BA85E5F738ULL, 0xF0B02CC4203AE55CULL, 0xCB6EFD2E11EABA80ULL, 0x2E168222BB74AEE2ULL, 
            0xDFEEF85467A1B1F4ULL, 0x35BE005BB352CEB9ULL, 0x139DB4734D03B0BDULL, 0x65EBC7DA33F27633ULL, 
            0xA43A3D00E7E00BD1ULL, 0x70F29552BE20B908ULL, 0x881C6A2AD273908FULL, 0x675F55C8964AA264ULL, 
            0xBF16C46473427525ULL, 0xBF3DD8F09F1F4D7DULL, 0xFC287AB06DB622E0ULL, 0x67B70EBC6A9D4271ULL, 
            0x4300CC9EF6C7B0E4ULL, 0x87AE8C7DC6D18AB1ULL, 0x8BD44BC052ED4DADULL, 0xBE5AADC17A5F42E5ULL, 
            0x032AEA41FA66222BULL, 0x276BF47F62B0317AULL, 0x3D57F4D3457935E3ULL, 0x9A4D10F35832AD1FULL, 
            0x87536A83AD58FC8FULL, 0x6452C662523FFA88ULL, 0x7DBA57E949771D78ULL, 0x3BF73FA6E98BF805ULL, 
            0xCD6F10445D01B4BBULL, 0x3109EBD0AE95AD60ULL, 0x3112BE7C9EA1DFE5ULL, 0x126BF48650CEFCC8ULL
        },
        {
            0x88916EDA42360C3FULL, 0x5D4AC5DAC6C61F70ULL, 0x62D1E64AC7AA3CAFULL, 0xE927FC087CCBF3FEULL, 
            0x43D7CE7C5AE10F3FULL, 0x31310EA2C8C6269EULL, 0x9E8E48ACFD24F276ULL, 0xDFED272E5555CC14ULL, 
            0xD930D1EE175F3B22ULL, 0x6A3CBBA1A91B0E7DULL, 0x1384C7B5970E24C6ULL, 0x4032D118ECF59570ULL, 
            0xE6A4D0A73AB23265ULL, 0xACE5EA4821DE24FFULL, 0x884DDBFC0B73556FULL, 0x441231AD19A708AEULL, 
            0x2F6565B081E1DE9DULL, 0xD2D7C77A85735343ULL, 0xD2C1F06EE8611EF9ULL, 0xBFA7518724CFD131ULL, 
            0x6762E98AFA5F48FFULL, 0xB5AC60700BF7C6F6ULL, 0xC53880E6A9D8351FULL, 0x4A4E2206CF3BA3D1ULL, 
            0x9AA65FB9D20017BDULL, 0x115C4A02273BE9FAULL, 0xF591D00A91D3E3DEULL, 0xBE2F51D9ED6864BBULL, 
            0x8E98C489C38F759BULL, 0xD7C0EB2EE9CEA18AULL, 0x10F730386CB661A4ULL, 0xF66272DF2783E4B3ULL
        },
        {
            0xA4E4DDC81734DDF4ULL, 0xA57354175D9D8869ULL, 0xC0994B1912D514C9ULL, 0x5C2564A18044914BULL, 
            0x335D193E29D0FEC0ULL, 0xC3190548A1EE1469ULL, 0xF2D5CC42BD77CBDBULL, 0xECE307F8C9C192FEULL, 
            0x1085A30E5567C25DULL, 0x342391ABAB714E3CULL, 0xC89328C76480C47BULL, 0x6E696628813D0251ULL, 
            0x6BB3647F3C40F7BFULL, 0x46FE86E0B4F090BBULL, 0x9FC3141095A64436ULL, 0x7A2E90E6B4194764ULL, 
            0x6D2D279AA458ECF8ULL, 0x1B15718701F473F6ULL, 0x0FCD5C6D3FB5DEF6ULL, 0x5CEE53439F077ED3ULL, 
            0xE5D43B50A260EE26ULL, 0xD74206854DEFBC67ULL, 0x78959098C23E8BF4ULL, 0x436177A72C9FF9A1ULL, 
            0xC3F598CC5DD68E6EULL, 0x5D89624BA6061130ULL, 0x05084CD2E2805C2EULL, 0xC37653A637C14BCCULL, 
            0x739CA14507BDD506ULL, 0xEBD11778104607BFULL, 0x1A2ADB14032B82A4ULL, 0x3FE524E93FAC35FAULL
        },
        {
            0x911162E002A5689FULL, 0x01C5DED2C06FE6D6ULL, 0xAF9E28371D3DE3CCULL, 0x5980A463DA62CDB7ULL, 
            0x172AC8949BF790C4ULL, 0xBB595E5F219C4F57ULL, 0xBE79FBD59AC038EEULL, 0x5D928EA71D121ABEULL, 
            0xA7E9D8E6030E98F6ULL, 0xA3C41DF6890593C6ULL, 0x3E765BAD715A8CBBULL, 0xD2A7B94D3696054EULL, 
            0x4C56AB06AE7AE1E4ULL, 0xDEFC9812DF1F9895ULL, 0xD903FAB2FB080D5CULL, 0x9079E1DAD9A74642ULL, 
            0x8636F2C31C958753ULL, 0x098B2C20AC943792ULL, 0xE64A34B3110C23C2ULL, 0x948DE85DAB78D364ULL, 
            0x66D4DD7A1336CFAEULL, 0x38F5F6169672FF76ULL, 0x0B3521B12EFB6FE3ULL, 0x80B3351CE1B07121ULL, 
            0x9A34E7151A6422B4ULL, 0x7BF61E498AE83064ULL, 0xB9D21A261D3C93AFULL, 0x2FF77DA17EB86816ULL, 
            0xCBD9FA5063F5D332ULL, 0x98EA3539CE0F3CB7ULL, 0x88DD325921BB36A8ULL, 0x06936C0C33D3DC41ULL
        },
        {
            0x632BE39822EF2011ULL, 0x1294C2153690E237ULL, 0x641B408DF8842EB5ULL, 0x4AFBBF50F214B483ULL, 
            0x45FFDC17978E8D2CULL, 0x03A711BCAAE15C58ULL, 0x702D426CC0031C28ULL, 0xA9445034ADA06B41ULL, 
            0xCAD4C71F0639058BULL, 0x5C7819743467C553ULL, 0xB27E448B1C315740ULL, 0xF9958ADDC6ED4CBFULL, 
            0xFA68F9D53627E326ULL, 0x26403359BCC75805ULL, 0xEFE3D9DF9EAE14B4ULL, 0x68EF6EB0EAC4B538ULL, 
            0x64D77C60180750FDULL, 0x2AC23F3E0DC6537AULL, 0x4E8B15B6C608E4FAULL, 0x554EBA02D71A8940ULL, 
            0xBF9A7F3AB14013E0ULL, 0xC1EDA60043457501ULL, 0x61CC7D7BF3C482F4ULL, 0xCB33A8E8E5FBCC6FULL, 
            0x842B99842C83F09CULL, 0x1D0579800D726E6CULL, 0xFE5F07F19EC07903ULL, 0xC345B5E624261200ULL, 
            0x18A4053A3B5332AEULL, 0x9530A09DFD282E74ULL, 0x9B36E15C437884F0ULL, 0x2EE6FCFEC7305590ULL
        }
    },
    {
        {
            0xE5AD3BE59CFBE0E2ULL, 0x0EFE1E49C6FCEFFEULL, 0xEB3B6B3152E8B1EBULL, 0xE4C6635E6E943801ULL, 
            0xEC8C5348771B0478ULL, 0x6AF8B5D7EB8059F2ULL, 0x3B07C2C9DAA2196CULL, 0x6209A472D355B3E5ULL, 
            0xD644545CC9FEF429ULL, 0xEA8521027CA2C7C1ULL, 0xD913DCE9A0A79684ULL, 0x63A8891C23BE973BULL, 
            0xB82AF832FFC649ECULL, 0x08EDB619D8E8F3FDULL, 0x0BD31BDF802E1628ULL, 0xB53084FD36E44753ULL, 
            0x5CA3B5DEB0C45956ULL, 0x10E509132CE8FD05ULL, 0x5C7CFBD0D56BE0AFULL, 0xA0C1687CCA386800ULL, 
            0x705BC7BBCFBC6A85ULL, 0xB374D7036A4F804DULL, 0x8951B2AD8CAE6428ULL, 0x0B76D287C8FA3B71ULL, 
            0x9C6D70AD1622DA71ULL, 0x089E05C8F8DCFD18ULL, 0xBC9B58BC26059C54ULL, 0x48FCF30EE17302D7ULL, 
            0x11323A9DA4459DACULL, 0x345C2DBC1AF5D7A9ULL, 0x3883599E9CD81924ULL, 0x3C1D678710D03E26ULL
        },
        {
            0xC0376277CEA45476ULL, 0xD2A21C5A9C62536AULL, 0xF1FAAD22600A8991ULL, 0x91D3124A2E05C45DULL, 
            0xD5ECAE335E098B36ULL, 0x2AE56B0F19436990ULL, 0x13F24CA75643A82CULL, 0xF676BFFB28E28BFEULL, 
            0x01EB89EB27C75C72ULL, 0xDC980C9883DD2956ULL, 0x44C0DE70AB9E860DULL, 0x5D5B2C354C1A8A6EULL, 
            0x436C4B1D0C4741A2ULL, 0x6D7851B7303EAABFULL, 0x200FAC24B509D302ULL, 0x5DCB0E83A9F5BEB1ULL, 
            0xCAF0BBC150BAFB3AULL, 0x8D8CE80A4C1711D3ULL, 0x9B006F70ABF6541BULL, 0xC632D2124242506FULL, 
            0xFDB69CE65B048E52ULL, 0x5C2DC8873A0D07B9ULL, 0xD777D7650BCC1C0FULL, 0x5D5BD08E999E848FULL, 
            0xC59F6A30F8B289E1ULL, 0x0CAB4AC04F1929A0ULL, 0x987257C12AEC2F33ULL, 0xB6BE7CF0BAD0C8C5ULL, 
            0xD7DA463A0D792E54ULL, 0xA6D8D05ED45081DAULL, 0xFC103840D741B7A6ULL, 0x77D3A2C4E1330E8BULL
        },
        {
            0x2B69E898557B39DEULL, 0x0D9AD4AE63C891DCULL, 0x03BEC25F768AC100ULL, 0x922EEB2C8B295DC9ULL, 
            0xE51243CA253D05D3ULL, 0x93A5A76C70CFF3A6ULL, 0xEDE6323A08D79DE8ULL, 0x93CCF85F28213BC9ULL, 
            0xCA6A9D80BBCEDCB2ULL, 0x17EB65EA86C1BD20ULL, 0x96AFDFA701A84BE8ULL, 0x0C9E2B0BB2856D23ULL, 
            0xB0DD7E83F9FB5EA4ULL, 0x8BDD6F70F1471F2BULL, 0x5F319043B7D8BDEFULL, 0xB371CBB6983E9153ULL, 
            0x7DB1F47A4C7C67D6ULL, 0x7340A0AD289D1B38ULL, 0x453B23BE6E87731DULL, 0x3680DEF43679D240ULL, 
            0xD05CD05FB51DEAA6ULL, 0x63DDA662F214F39FULL, 0xDB990897CB331289ULL, 0x2F7F44164FF32FC8ULL, 
            0x6A6073D8FC948BCCULL, 0x4864F63FAFDCAF86ULL, 0x9EF378ACD749545DULL, 0x423BFACBABF2DA25ULL, 
            0x639792C5130CCC69ULL, 0xD0AA71C4E90CCE2BULL, 0xF534E33626152025ULL, 0x661283663CC3A5DEULL
        },
        {
            0x948494412AA79616ULL, 0x6B55BF17F9CB8EB1ULL, 0x554B856405240420ULL, 0x44C8164A9E93991AULL, 
            0xB581F879776AAC60ULL, 0x7DFAE4ADC702BF92ULL, 0x4F6BB90526EBEB73ULL, 0xC57CFC5312C6562DULL, 
            0x146B1B6070B8877FULL, 0x58F53739D67860C0ULL, 0xA3674F96D28C9B2FULL, 0x9C32266EE7FE5B27ULL, 
            0xADF38FC03618A368ULL, 0x69B1B3DBBF270DA7ULL, 0x085B61E611CDB978ULL, 0xD245217C23682F8FULL, 
            0xEF4C8BC3040E9241ULL, 0xDA65C714E92BACEAULL, 0x8DE9B55585BA3C37ULL, 0x7F00E14091441E4AULL, 
            0x48CB5D7FFEA62CE1ULL, 0x81D0EA90B58A53D2ULL, 0x4A97FF9B37C22A99ULL, 0xBBF80206AC94231DULL, 
            0xE74420C566DEE928ULL, 0xF7126392BEB5EB6CULL, 0xADAF00F54F960D85ULL, 0x77DD716F9DE2E399ULL, 
            0x6AA59DB4627ECF4FULL, 0x081CD03193A4A93BULL, 0x1192D5A4D54E1507ULL, 0xDC754853EA9DC82EULL
        },
        {
            0x09C9C5C4B2720B25ULL, 0x7CD5F6919EC0B0BEULL, 0x01CE595A96E2ABE9ULL, 0x4D0517829209B040ULL, 
            0xC5146F5C68641BA0ULL, 0x10D25D9B9256787FULL, 0x27B7F82E72E6C0B4ULL, 0xED1829C52E60F548ULL, 
            0xBC294898C9E4F137ULL, 0x889A68E30DB9D302ULL, 0x72277024DE8B08FDULL, 0x433A06C9E3F6B05DULL, 
            0xC37396324CE9231EULL, 0x139221CAED476F3BULL, 0xA21A6D73559D8AC6ULL, 0xB3E0A44506EA124CULL, 
            0x82C8D5B000615D0BULL, 0x75626AC5EE3E21BAULL, 0xF0D76E2E11965C24ULL, 0x41C74A2DEFC1EEDBULL, 
            0xF655B3F43732D278ULL, 0xE42389A5537432E0ULL, 0x2F640344B5B53F02ULL, 0x9B995B355E53CA6AULL, 
            0xB6C991C49785AF4FULL, 0x54DE41BA1E912EA9ULL, 0x049BCE32168B3A1EULL, 0x76996CBB8DD38352ULL, 
            0xEDB6845DC654AB55ULL, 0x701D091EF7C69CC4ULL, 0x5BFB1BE24A2C1558ULL, 0x7E988749EEFA8BEFULL
        },
        {
            0x989E7A0C30DF1EE9ULL, 0x4E6AEA98FA53118AULL, 0xB43208287E0C2BE6ULL, 0xDEDE39BA6FA4FE4DULL, 
            0xF2383AD8CEDB6F8FULL, 0x583A892351E2FE50ULL, 0xF43B2D55E0E1E756ULL, 0x21D572E969F29DDBULL, 
            0xA9368A8E3776C919ULL, 0x17CCAC51EACF00B2ULL, 0x1390D0275FA989C4ULL, 0x624511AC0F78480DULL, 
            0x4082FE16B88E9D48ULL, 0x2C85741D1E2ECA20ULL, 0x8C59B978A082AA41ULL, 0x57EDFCE5A1E82C19ULL, 
            0x9446FA44D4E64412ULL, 0x97B75D89F78A6DF7ULL, 0xC580F61633B4629AULL, 0x71C70B2028876A2FULL, 
            0x76EAAFD03E951885ULL, 0x2BF4676609251EF0ULL, 0xD30AE00D5BD44A92ULL, 0x68298EE8139A54C2ULL, 
            0xB723590AB6864B82ULL, 0x555731B24D26EEFCULL, 0x42545DB155057DA6ULL, 0x37728DCB39097F6DULL, 
            0x9FEFB6A2B0E814E5ULL, 0xE3C29D67E72F5DD9ULL, 0x3684D0E4EA1A1EF6ULL, 0x8C6B245C99CEE6C3ULL
        }
    },
    {
        {
            0x3110A1C9AFB21303ULL, 0x9EFBE83DA38C28E3ULL, 0x28D52A32947B4631ULL, 0xF242BB4FF52F934EULL, 
            0x483487A32EFD4BD1ULL, 0xBA0B86FBE9B363A2ULL, 0x47DF32A55A6B88B7ULL, 0x797F3DB3380A286BULL, 
            0xD88C7677E2DF7A22ULL, 0x97E8F81782FCCF4FULL, 0x6492E82AE9A360CFULL, 0x1354E8BBE35F1537ULL, 
            0xEA3E725A0FE5CF7BULL, 0xE0C814B83CA59BF9ULL, 0xA24F0E07E80A8165ULL, 0x4A655673D65FCDE8ULL, 
            0xA8327A95F546DF7FULL, 0x67C8F1A1A567DB6CULL, 0x556E022CC2990CE5ULL, 0xE179B013B79E2E2DULL, 
            0x473150269564912BULL, 0x7CD2CE4C74FA7485ULL, 0x756E6A0B046AF4ECULL, 0x75FB0AEB0DB087FFULL, 
            0xE886ED4B21A67371ULL, 0xBA6CB0EAF6613295ULL, 0x0758E541D33B94FCULL, 0x02429B08B23ED858ULL, 
            0xD1127C55DAA5C388ULL, 0xB0FB4285347AC9ABULL, 0xBA697DBB1220CB95ULL, 0xD1A991017553F0E0ULL
        },
        {
            0x486EF9CD18F381D7ULL, 0xD55FA20083A1BEA1ULL, 0x8CA29B7D31D2FDF7ULL, 0xB5A2F54E2DC32D29ULL, 
            0x3C4880EB42C14020ULL, 0xBF8535E19323BE5AULL, 0x815A8AF199810C1EULL, 0xF882E153F9A1172FULL, 
            0xCF0E1DA7392A72DDULL, 0x34D21545466DD652ULL, 0x18FFCCDCA3ED971CULL, 0x76548510D40F1035ULL, 
            0xBEEB0D06AFCA7659ULL, 0x996350D067993413ULL, 0xAC36D6001955E445ULL, 0xCB3A880D600E9548ULL, 
            0x28DE0578B794D74CULL, 0x042AC456E3850124ULL, 0x2757E2E0283D7417ULL, 0x32688BB57A0E7D28ULL, 
            0xF4442D86A98104E6ULL, 0x686B1C738122F5D1ULL, 0xAAF48E68CAE014C5ULL, 0xC4A9B1E4D2EFBB5CULL, 
            0x452F1574A133D4BDULL, 0xA5F4A4E9F5176095ULL, 0xB761E0CA2982F2B4ULL, 0x3C85D0A136F0B534ULL, 
            0xB8078712BDD204EAULL, 0xBCB4C764E0C94231ULL, 0xB8E31500D2D26410ULL, 0xC5570804079180C1ULL
        },
        {
            0x6FAC1D16D4F293FCULL, 0xEB8341634A88760AULL, 0x43619662A30CEF9DULL, 0x20A432DD482A9806ULL, 
            0xE5DA990BB2FC62F0ULL, 0xA83558894291A1F4ULL, 0x04AF151A5D905189ULL, 0x6A085FB0E1D9E240ULL, 
            0xAE6CDF989A0183A3ULL, 0xA9E63F6D1954BF20ULL, 0x4D944D31C812CD98ULL, 0xAD86ED417E87B5CCULL, 
            0x41C0C8D9C5EA8318ULL, 0x9836C1CDD3662506ULL, 0x5AA74610D5161271ULL, 0xE0198E4A803B4A41ULL, 
            0x8EE8E0684636FD2CULL, 0xB790D76B202D6CE8ULL, 0x97B9BA3390689D8CULL, 0x697651AB6D4E2D2EULL, 
            0xED30C4A9E918B847ULL, 0xC337253A08FF39FEULL, 0x9877EDAA0902984FULL, 0x0473C177C475276BULL, 
            0x0E06BA7F9736860BULL, 0x7544DDC87BC7C2CAULL, 0x65B357251B91F1A5ULL, 0x3A77A01311564013ULL, 
            0xAD982483172C75ABULL, 0x3F774F0718ABF893ULL, 0x10B70AFC7E93504AULL, 0x4E39F0AF36B5AD36ULL
        },
        {
            0x0BC1823F4AF784BCULL, 0x0C6B32387FDC2985ULL, 0x63915CDF96397684ULL, 0xFFC3BB1134A610F2ULL, 
            0x3EF0B328B4BB808DULL, 0x821A806F777F8C41ULL, 0xB925BBA6F0960DA9ULL, 0x5AF1F05BF02F22DFULL, 
            0x518CE8FD620AB2ACULL, 0x7D2FFDF32D633E5AULL, 0xF9CBB9E2F8CD9624ULL, 0x565BB4F8D7A9214FULL, 
            0x93C3168713025656ULL, 0x1251618FBE8F3B32ULL, 0xAC8576A1173B9654ULL, 0xE36B0D1676AF5DADULL, 
            0x267127CE1DB36F7CULL, 0xCD0F6B91E2151783ULL, 0x529FFE29DE465747ULL, 0x907369D232539068ULL, 
            0x250863DCE97D4143ULL, 0x699808229601C12DULL, 0x77488726A977FDF6ULL, 0xB1CC8D5292C8AC2EULL, 
            0x3E87212190DCBCBDULL, 0x2602998CDA731049ULL, 0xF4E90C99AEEEB94BULL, 0x3C9985895E6C869BULL, 
            0xAC7FD38EDA96BC27ULL, 0x1844830B0A1759D3ULL, 0x65BEAC14D858B264ULL, 0x5280599CB005AD0BULL
        },
        {
            0x6F4B1B4D52653A6CULL, 0xF026335CCA7E762DULL, 0x1A3F999112445104ULL, 0x0E40E147ED9CAD9CULL, 
            0xF0220AAD02448B1CULL, 0x341B9B4216E78EFCULL, 0x82A574E0EEF569BDULL, 0xBC2126BA7A015061ULL, 
            0x1F66D9FB7FAB17C0ULL, 0xDBB50BEE591F3543ULL, 0x485C6DE889C5AB75ULL, 0xC04E6B16D4035AE7ULL, 
            0x0305DD6692AA953BULL, 0x1C9D677664BB00B4ULL, 0x49E500F3DA7CB0C6ULL, 0xD4374242001AC232ULL, 
            0x4A1DD018BBE3D86FULL, 0xACF6A96439B390A5ULL, 0xAEE8311B821DAA1DULL, 0x6A0A221997E89E8CULL, 
            0xA69C31CE15D88173ULL, 0xD9E85A9E659B0C04ULL, 0xFDC6CAD8949A05F3ULL, 0xEAFCEDEC91A412F7ULL, 
            0x81F66AE037EF0629ULL, 0xD51BF39F7B99D01BULL, 0xCC7A052CBB540812ULL, 0x2FB3CAD4038F118CULL, 
            0x1A712AC735AF13A5ULL, 0x1BA83BF7269227E1ULL, 0xF502F9A9AA9B1DB1ULL, 0xB80F75A47AC04F75ULL
        },
        {
            0x06BF07C3DB7B0913ULL, 0x6B7103A53146B000ULL, 0x0150238A3D6D216DULL, 0xDAB8D11D88A90646ULL, 
            0x90CDD47E437275ADULL, 0xDB8C95E7E4250491ULL, 0x5A293E0982315860ULL, 0x7DC91EE4C342C840ULL, 
            0x3F423A843AF1E755ULL, 0x1F6E4F14F0AB7793ULL, 0x5EC9FBCAE1B73B87ULL, 0x18F670779220AF03ULL, 
            0xEACFAF6A2997E6E3ULL, 0x899E9BC5CF664367ULL, 0xAD3D96D69F1CCFF5ULL, 0xDCC36B80CED52FF8ULL, 
            0xAC7D31DDB652907BULL, 0x852426CDCB957285ULL, 0x927316C96CDE48DFULL, 0x97B2A40F3EBA01AEULL, 
            0x40463285B9F6186CULL, 0xB1E69DF42ADEC644ULL, 0xBCA73D705690AF1CULL, 0x769C6867C04E65A9ULL, 
            0x5519C5F1EFB418EFULL, 0xBCD98D182716FC60ULL, 0x43757E3F8D862781ULL, 0x2C4F4AA11C8367EEULL, 
            0xFF99990173ABFE88ULL, 0x264423FBAA56D123ULL, 0x1CDDF0B6BF0E002CULL, 0x9650484B31EDBE60ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseFConstants = {
    0x4610D8D5526F19C7ULL,
    0xD5FB0BCA45FB4FF2ULL,
    0xE6628BA7EA1A73E2ULL,
    0x4610D8D5526F19C7ULL,
    0xD5FB0BCA45FB4FF2ULL,
    0xE6628BA7EA1A73E2ULL,
    0xC600529B3F5F6FDEULL,
    0x254C07905948953BULL,
    0x3A,
    0x06,
    0x98,
    0xF2,
    0x91,
    0xC9,
    0x13,
    0xD3
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseGSalts = {
    {
        {
            0xAA747E44DC90D33DULL, 0x3D43F1E2D174E7DBULL, 0xD0CA4F2C84D7321AULL, 0x3934ADE2C7F14728ULL, 
            0xA282DBF99C358F39ULL, 0x8C3337FF42CD1396ULL, 0x7ED298762A4B615FULL, 0x4754DF51F39E4DD4ULL, 
            0x432FCE5115B682A3ULL, 0x34B9891BD35DC396ULL, 0x5DC47E40119CCB74ULL, 0x475F519719364202ULL, 
            0xF8B0D501369B3BB6ULL, 0x4F11B172EBF6DA81ULL, 0x0F044D8855B501FCULL, 0x0C19B9F01E365BD2ULL, 
            0x3879511A688E30E7ULL, 0xDDDB9AB128B87CBAULL, 0xA10F2BCE2851A5AFULL, 0x4616A2E9CEC35EBBULL, 
            0xD98CDA5E6BF32AB1ULL, 0x0AF20B32E940A677ULL, 0xC4C36AB1417D53E2ULL, 0x8ACEC70EDA679074ULL, 
            0x68EBE302C9D0F6B1ULL, 0x697977D15DE7AE18ULL, 0x136505156A4260CBULL, 0x6CB670ED31F44897ULL, 
            0xBC33B122142156BCULL, 0xF3E7839149FCC4ACULL, 0x04497496B5002950ULL, 0x829FEA075DA240CAULL
        },
        {
            0x4274564D8E5241CCULL, 0x31E3C8D56E2FE87BULL, 0xCE0F6181F4E8F66DULL, 0xD00D8AB97C0C9933ULL, 
            0x6857236722DB98BBULL, 0x023841062C935BE8ULL, 0xC278BEE468CDD51EULL, 0xCFCE2D6C15493E35ULL, 
            0xD4F20F89840E5276ULL, 0xB42EBE67D9418090ULL, 0xE99AD338E639B7E1ULL, 0xDF5154F8B3B7AB25ULL, 
            0xA020540BB24BE26AULL, 0xCEA8B8F99E7A45B3ULL, 0x32D0618EB5F29920ULL, 0x2B6D8A4BA6B3FA1AULL, 
            0x45BEE3D5C8DD62C8ULL, 0x5E67518F8A51183EULL, 0xF1D7C5C72F2EB743ULL, 0x7314D07C76767772ULL, 
            0xAA2C0FF72AF3D8DFULL, 0x83FAE9969567DA35ULL, 0x5E3ACCDBFE8106C5ULL, 0x148BEFE84B258659ULL, 
            0xF7AD7630ADCA1005ULL, 0x7213063D66DB9FA6ULL, 0xA38D136266F7E254ULL, 0x5D8F2D84BB5E4E16ULL, 
            0x5FE78D0275510757ULL, 0x72628249E87803C8ULL, 0x879E62FDBA366648ULL, 0x90D47F18B24188E8ULL
        },
        {
            0xE5BED21344704BAAULL, 0x91998618428BDA47ULL, 0xFB42F3B809DAC520ULL, 0x35E58680B0F73490ULL, 
            0x69ED3B45E4CBC0EEULL, 0x00E111C1926962BBULL, 0x66EBC082C2946314ULL, 0x4BB8B74FBABBE3CCULL, 
            0xB657257EC9877E1FULL, 0xEA4D5A467E4BB682ULL, 0x96CE0049BC54219DULL, 0x74DBA577A19B5262ULL, 
            0x796B608CA59397F5ULL, 0xD8C29933F639039BULL, 0xB74DD520CE4B2A4EULL, 0x3D843DB1E2926AB4ULL, 
            0x6702B1E1CC6D420FULL, 0x6A204991EB4CB31BULL, 0x270B076ED6F9B2F6ULL, 0x4B584BC14498AB9DULL, 
            0x5F35A5DE03D2B04AULL, 0x83316EC78CD50D60ULL, 0xBDD553C4AE1B56ABULL, 0xC434A22D4D8BC152ULL, 
            0x7E5586A484EFAA75ULL, 0x7C6A71A816FF6640ULL, 0x190BD8456C498C2EULL, 0x7C544D2DDD8E305FULL, 
            0x4BBD7342C423191BULL, 0x00FF8BC8552558F1ULL, 0x02BF06047C17ECF3ULL, 0xC5A9037803545D95ULL
        },
        {
            0x8BFE79C9524C26AAULL, 0x79DD0AD62D715396ULL, 0xCA237938C2958AB7ULL, 0xE7A9BB4B005458FBULL, 
            0x814D544CB59E7C91ULL, 0x56324252463D5EB3ULL, 0xAD079CE6FE09B4F9ULL, 0x2F891D6724F426C3ULL, 
            0x15548E68EC2F33A5ULL, 0x8054F85BA7E019A7ULL, 0x598916AF7F3B9086ULL, 0xE68D19B74E39A97BULL, 
            0xAF38828A3C94CCAAULL, 0xDE5F04EAEEE05993ULL, 0xB29929CC0F04F505ULL, 0x1C31233B5DB49264ULL, 
            0x89FB02A8394BB031ULL, 0xB64741A0B1D605DDULL, 0x56D17257B58B7565ULL, 0x635AB8690A20C70BULL, 
            0xEDB43EEF4D1C57B3ULL, 0x62DE2FF5EAF8EF31ULL, 0x326555CF1783D3B8ULL, 0x72E9FDD5002F1EFAULL, 
            0x20E60ACAB25D2A5BULL, 0xB41615FB996224DBULL, 0x3B6ACA2022103733ULL, 0x068713BBC57887DEULL, 
            0xE51E09E5F9A2A3B7ULL, 0xA9DEC40A63538A94ULL, 0x9A0DAE1159D0E3ACULL, 0x03BF952BA3E73EDBULL
        },
        {
            0xC2555703C1292C8BULL, 0xDFA4FA059188B1F4ULL, 0x94515DC4051CB3DCULL, 0xF60F88983F01F090ULL, 
            0x26988DEDFDEB7968ULL, 0x7DAB9A78E1215E76ULL, 0xC18F522D111C45F7ULL, 0x472CAB1A7AF2A29BULL, 
            0xB0DD85CF8AF79C98ULL, 0x7CAE7045206DA182ULL, 0x7B9EF2D3C24371F3ULL, 0x7E6B7E5D2EE43EF9ULL, 
            0x66C3A423EE6F831AULL, 0x9C2BDFAE22ECA555ULL, 0x0C3F32A6C97EA729ULL, 0x74D6488D28DAEF08ULL, 
            0x701EA5E93BD254BEULL, 0x603C326A99EBC484ULL, 0x5C3770DC44589992ULL, 0xD5B9D1A40411F3E3ULL, 
            0xB0B89C5B2D8FF4E6ULL, 0x0883DD87F9C69DC4ULL, 0xF7FA0F6354074BE7ULL, 0xEC047DF1A40DF0ABULL, 
            0x39B22E645C9F5292ULL, 0x8A9AB70632E4B8FAULL, 0xE52B2729965D131EULL, 0xAB22C60DC590A117ULL, 
            0x1159B3AF08CE8246ULL, 0x8FB240CE1F3FA688ULL, 0x3E57FA0ECF21AE46ULL, 0x88E75F7575FDE32EULL
        },
        {
            0x0007DA45DE5E931BULL, 0x80C1CECA190AE8BAULL, 0x639C2D8C8246A893ULL, 0xA576627175118E95ULL, 
            0x828695AF889A9FABULL, 0x72F4E7DE56629E8AULL, 0xCEDAFA65F34B32C2ULL, 0xC6EE2106757F5E41ULL, 
            0x789A6E095686A8E0ULL, 0x7B7CB699413EC753ULL, 0x45E5A3865794B11BULL, 0xB54CB51812585112ULL, 
            0x50E6AEA07E74E70CULL, 0xA6689D36C2EC77E2ULL, 0xBDBD5595FB1D53CEULL, 0xA71FA41ACB08731FULL, 
            0xD9C0FDD0620B179FULL, 0x67375C09FE470525ULL, 0x1362E5B4D65506C0ULL, 0x9D9E16B22232D154ULL, 
            0xD358A8B52C304C06ULL, 0x48C69B7B9241DD04ULL, 0x2DE6FB316285A0BCULL, 0xB9C05DFF816E8C8BULL, 
            0xC35528EA0242165AULL, 0x97BDEAD3FFEDE73AULL, 0x191A03BFD248D3CBULL, 0xB03C1967034CD069ULL, 
            0x37F6DC18FCBCF5A8ULL, 0xF4485D302D2B5C07ULL, 0xBAEE20D13BDF038DULL, 0x761F7DA070E88D47ULL
        }
    },
    {
        {
            0xF75C54A6CF2CC9EAULL, 0xE501C212AA632CB1ULL, 0x232B94BF9E2B84E9ULL, 0x9D69C2E4DA0D2365ULL, 
            0x37E2C172A3E46E83ULL, 0x9FE35FC4DD71E835ULL, 0xC0FEA3435425E8B2ULL, 0x3EC9AEE7D4D2FBBEULL, 
            0xA2527722752204A2ULL, 0x68E360D6C912D1EBULL, 0x19D8F1BBE3685789ULL, 0x136279CEB725E51BULL, 
            0x732153FA5F42EC05ULL, 0xC187A3983EF3DB64ULL, 0xFB5B2592FC2DE570ULL, 0x15169C04E4CCA320ULL, 
            0xD5EC40D947391BFFULL, 0xAEF8EEC376FDB7EEULL, 0x4690FE8EB01BBD1BULL, 0x35CC9D535FB7188DULL, 
            0xA96F12DF94BE1FBCULL, 0x9066B55F7A5512EDULL, 0xFECC52A5C49C0BC7ULL, 0xC4E50F693E352498ULL, 
            0x488E946B74ACCE71ULL, 0x653FD36DFDA97DDBULL, 0x67793C7397FDE23CULL, 0xF246098676C4B9A4ULL, 
            0xA64EDE006E10B6F1ULL, 0x8E363751607A0959ULL, 0xD70FEECC6D24BCBDULL, 0xD2FF5A8DA7DC80D8ULL
        },
        {
            0xCB50A74415E7AFF1ULL, 0xD8AA44156FED78F6ULL, 0x5B85F7EC09B0B07FULL, 0x7B51FAFFACE92C80ULL, 
            0x9212D60DA0ADD8E9ULL, 0x0CE8B9198BCE5975ULL, 0xFCF0121182F33058ULL, 0x62CC3C93407B5912ULL, 
            0x31639806FC43705DULL, 0xF306E26336B6599FULL, 0x9CECA259A1F6FE4FULL, 0xB4C455AE230AA096ULL, 
            0x8A23C0000F85E894ULL, 0x34293F189ED97A14ULL, 0x424002D4BDFA3F45ULL, 0xBC430064F84A7E98ULL, 
            0x472D4508BAA9086CULL, 0x99A838F46301D112ULL, 0x6AF5D4035B8AE40CULL, 0x1B37E2456FFD8F69ULL, 
            0x07673709368CD973ULL, 0xB7CB0039F308B94CULL, 0x52749BA956E9CA79ULL, 0x7959A701D50C6C62ULL, 
            0xD2E30522E7C9F059ULL, 0xD84FD09209CFFAA1ULL, 0xF79F51AA4E4E511DULL, 0x7256A993D4C5553FULL, 
            0xFAF9F7C95CD07F6FULL, 0xC2F9B89B99D1DE79ULL, 0x7D0225DD9E42C785ULL, 0xB182297C60000D37ULL
        },
        {
            0x7D209040AEB9D050ULL, 0x1572A8CF8EF74DB1ULL, 0x741448F134853593ULL, 0xF39F158E969F2799ULL, 
            0x5A88F9342B006C1FULL, 0x77CD8BD971953557ULL, 0x2CE61F9586552E2DULL, 0x621C267C4C5C092CULL, 
            0x96AE38571276E9F0ULL, 0x1BEC0C0A81D1D958ULL, 0x1A5492F83606819BULL, 0xE8A021FFEC7840E6ULL, 
            0xBCEC8441C89E78F0ULL, 0x2A20CF9F39137EB4ULL, 0x8F37559138C55499ULL, 0x3199DA1A62B58599ULL, 
            0x1659840B8BB23C86ULL, 0x9C6C2EA926D0595EULL, 0xED7DD4F6D762E4ECULL, 0x8BC35ACAC68559BAULL, 
            0xB47DF0BDF72417D7ULL, 0xB43FA399E16ECC1CULL, 0x5301AFA9AB4F7B43ULL, 0x0D512D28EF9F3C39ULL, 
            0xDBDFA729E3B89B4DULL, 0xFA7DD51460C09042ULL, 0xCD659528C6316183ULL, 0xC79E10C283D7D085ULL, 
            0xCD69C442D7B16739ULL, 0x3144D1DBBB59AEDCULL, 0x998FCAD124BDD917ULL, 0xAAA0AA3EFE95EB23ULL
        },
        {
            0x507E7A90595C67E9ULL, 0x4C1B643DC0B80D7AULL, 0xB63CAA17D8E912BEULL, 0xD66EC427B4335718ULL, 
            0xF3EBB85F4FFC6F42ULL, 0x3885A37485E48952ULL, 0xF426B1C819EE4465ULL, 0x8068FCC0198AC857ULL, 
            0x6CF0CD4F1FF55682ULL, 0x7CD48C81C99C097EULL, 0xFC58456B2B3C68BCULL, 0x10235B0DDA0F067DULL, 
            0xABCCCF9BFE54A97DULL, 0xBF0E62094E54790BULL, 0x2E616E6A6FF68DF7ULL, 0x12B0560E3D87BEB1ULL, 
            0xE6B0F811960A1BF7ULL, 0x101E31B4787280F2ULL, 0x213FA6888F097485ULL, 0xEE40580D267751ACULL, 
            0x02D1DF3148E01D2AULL, 0x8332EEB2E3A9B546ULL, 0x169E22F75084DF69ULL, 0xCC2885D3558842B6ULL, 
            0x5A70DDD144C79331ULL, 0xECBD97AA57454423ULL, 0x52B1AF085887FAA5ULL, 0x404E01DE9DA8BC7CULL, 
            0x2B6A27C330519997ULL, 0x56F13E44328BC22BULL, 0xD0332DBDB41F1ABCULL, 0x2C86C709D2E93408ULL
        },
        {
            0xD1B6957782096462ULL, 0x367943EEBCBE3E32ULL, 0xE62FDBCF6445A209ULL, 0xC56EA99FC841D4CEULL, 
            0xB1EE7D656DD1728AULL, 0xF3D76CDCA613D28EULL, 0xDECA82A6CD0F78E9ULL, 0x0CD0AA700E9D0D7FULL, 
            0xB97AF80745F310CBULL, 0x4F616D8CAF5EAD49ULL, 0x83193B7B700F20F3ULL, 0xBE18D89C19EB7575ULL, 
            0x362C1BAD468B8BCAULL, 0x3EE0DD3597FE9318ULL, 0x280F0000E8FB953DULL, 0xCBE3B07630BCEA42ULL, 
            0xEB42663414573E4DULL, 0xB852AEDF0DAC6B3AULL, 0xD314B13E0A75C3F8ULL, 0x9FA1441274EEAF5FULL, 
            0x88E8B27151AC555DULL, 0x94D235930035CC98ULL, 0xEB5FDB0D91D9E0C1ULL, 0xC6CBEDFC18499E3EULL, 
            0xE37D6C155CB0A7A9ULL, 0x0C5D0D6307D7B148ULL, 0xAD0B63D46BA2FF13ULL, 0xD1A7F4CCE0C81D70ULL, 
            0x944DF5F98AF603C9ULL, 0x185FD40F7BE4224BULL, 0x17A40CA2B07EBBA4ULL, 0xBE07EF01C36EB91EULL
        },
        {
            0x5CE808393A783827ULL, 0x2C98FE47673B1FB6ULL, 0xB3796543B05B11D3ULL, 0x4545EA7B87670317ULL, 
            0x0D94FD4DB9CA3BBBULL, 0x04956F09EC8F89FFULL, 0xBCD23FE63287A95BULL, 0xF9F7946A5D06E81DULL, 
            0xBEF7AF596141FC77ULL, 0xAC60BAC65ABCBBEBULL, 0x19FAEA56CE20C99EULL, 0x4C2770C6BFE427F2ULL, 
            0x8BABAF262321A405ULL, 0x5242702EC0BFB895ULL, 0x39B3D8136E7C08A6ULL, 0x08C426C566A113ABULL, 
            0xD9265582B9374513ULL, 0xE7173168069CEFACULL, 0x4D256B213A19DB97ULL, 0xCCB67ABC1AFD1A10ULL, 
            0x39F96D24D7CF0A52ULL, 0xEC609F86376C62CEULL, 0x86F77722F456CF61ULL, 0x7D0CFA486E80FAEEULL, 
            0x025FC1FDF37D76C2ULL, 0x7DF5F6CA9740DC99ULL, 0xA65CC8774B60C855ULL, 0x914CD438B2EB7177ULL, 
            0xCD4DBD60649E364BULL, 0xAFE548990DD3C555ULL, 0xB2F6747823E1AE81ULL, 0xB004ABC4D7E9AA95ULL
        }
    },
    {
        {
            0xEBE7C4411848C083ULL, 0x43BB9EBF0C141E75ULL, 0xDB2B8A1E0FDDE20EULL, 0x4CB6EBC5FA1565C6ULL, 
            0x75EDE24D9AE72B88ULL, 0x15953DAAF2C176D3ULL, 0x46154894113AEF10ULL, 0x14C86BF3B7349A01ULL, 
            0xC6E803A8BA3C093FULL, 0x353B529843F6E333ULL, 0xAE2D508C90F9FEDCULL, 0xAF0871E2610C361DULL, 
            0x73E0139D4F855CF4ULL, 0xCBACDCA7E1D54DF0ULL, 0x5217BE3EECBEF403ULL, 0x5FD8B8A284550AA8ULL, 
            0x5F6953FFBB867E18ULL, 0xB872E99703734168ULL, 0x5EE9F432D1B619F8ULL, 0x6DE91EA12E9E0AF3ULL, 
            0x6098A5DFFB441A45ULL, 0x79D8EEF68D81B5F0ULL, 0x090E149B1819C40AULL, 0xF5A7A5EA9CA6D909ULL, 
            0x92355A67D263428DULL, 0xBE6FF50BB022C2A0ULL, 0xCF1567CFBF566B2EULL, 0xF4D674CD9EA7BF23ULL, 
            0xC174E1ECEACBFCD8ULL, 0xD221BFC6177DA5BEULL, 0xCC9088F6300F7B86ULL, 0x7C30AC6F1DCF2AE8ULL
        },
        {
            0x213C74181B1164A7ULL, 0x92B863B9A72632C8ULL, 0x1152AC74DFBB5341ULL, 0x4D4807402B48A728ULL, 
            0x49907FD86C60A985ULL, 0x8AEA542657FD9B92ULL, 0xFB8E258F5EB58A2FULL, 0x493EF299FDBA8A02ULL, 
            0xFF3BD6E5DE64421FULL, 0x2D917AAF5871FCFBULL, 0xDDED84C5B956C954ULL, 0x5237DF7F674BFC2FULL, 
            0x83E99A8F7DA40C11ULL, 0xAD4C7A260C80C912ULL, 0xF4664B620D8E9D67ULL, 0x15166517CE4451B0ULL, 
            0x9B8218091D3F7068ULL, 0x60AF01ABE2B358CBULL, 0xD9732A0D82E8885EULL, 0xBF514662DEB49DE1ULL, 
            0x9E0E7CDF4B84D266ULL, 0xC6813C7E8BCB3A21ULL, 0x8125328D210EE3B2ULL, 0x0A86475EEDFCCA21ULL, 
            0x9CA5E08B926DD440ULL, 0xCD06A1F734B84ECEULL, 0xFB260B5318CEAB71ULL, 0x8FD2E64FB26ED526ULL, 
            0x6E84EC780F7476FEULL, 0x97D535F6AC1AA58EULL, 0x6160FF1896F58956ULL, 0x608C2DB836B87DF4ULL
        },
        {
            0x211CEC634EECCC46ULL, 0x7359F3A2272E2B1FULL, 0xAB3904FDE9020A85ULL, 0xC06E3E6D0BED65C5ULL, 
            0xFD6D98234E31C323ULL, 0x36B319562C8BF961ULL, 0x1529B474CB457AE3ULL, 0x5F5F9F746A87DBE7ULL, 
            0xF07E52F4046A94B4ULL, 0xC2B17C990D8AFBEEULL, 0x5E3E1CA4EBA20836ULL, 0x8B16A728804B444AULL, 
            0x01ABE6D8172C605CULL, 0xFD8F1EF25AE47D06ULL, 0xC8F17238062139AAULL, 0x29DD244EE8150C63ULL, 
            0xF6D80D9FA35FEB2CULL, 0x0038C210FD8ABE70ULL, 0x87BCCA45662E04F6ULL, 0xC2B09DBAC498B7F1ULL, 
            0x6B2668C29ECAA632ULL, 0x53EA1C94EE24173AULL, 0x995A5DB7A2F69186ULL, 0x69E98DD1B89C576DULL, 
            0x80E5A873E1AD8A14ULL, 0x3AA5A106551191FFULL, 0xE8268794F32450A2ULL, 0xD028FC281A788D92ULL, 
            0xF3AA88B99CB7DE93ULL, 0xEE0DACAB2FB668A2ULL, 0x01AB949686865E9CULL, 0xC8C431B0431D88D4ULL
        },
        {
            0xE0777079DB570879ULL, 0x5D1F282F3E1B2EEDULL, 0x28D2C28CA26AFA59ULL, 0xA5688C756416F7F5ULL, 
            0x85506A84A4722780ULL, 0x6852B3EAEAFF0A0EULL, 0xAF17A46DE8DEF9FBULL, 0x55643BFF515E4D09ULL, 
            0x13BB454A89A911A0ULL, 0x53FB8E1E36491FC5ULL, 0x58FD92080FCD380EULL, 0xDD8114D20BFBB7A3ULL, 
            0x139AA588775B1401ULL, 0xDC820FBD484FA199ULL, 0xC63C089B85CFADE2ULL, 0x81609F84BBCAAB23ULL, 
            0xB42C3E692E1DBBDCULL, 0x2CD9BC6C6BFADCC7ULL, 0x554BE31BA6856EDAULL, 0xAA337DACE0758DB5ULL, 
            0x0D50EC7474F3B437ULL, 0x21FA8D4991C82DCBULL, 0x078C5A59B1B55634ULL, 0x7B74A5177D5DCB7DULL, 
            0xFFB1A55DF04A2916ULL, 0x87B65B573418E6F5ULL, 0xB68792F87F7CEB7CULL, 0x75A279E0ED038EF5ULL, 
            0x93594FA59B511337ULL, 0x855E42BA0610A5F2ULL, 0xE67D6726B647488DULL, 0x1CD2F6BE2B7926C7ULL
        },
        {
            0x5B2BA4A7FA5D5798ULL, 0x602E9C3D624F6569ULL, 0xCB4057FCF5017BABULL, 0xA7B3B8B2B59D25EBULL, 
            0x6A1B7C6291ECE36CULL, 0xB9C340702B623713ULL, 0x7AC21206234D2D70ULL, 0x7415900F77731FF6ULL, 
            0x32CE56C661D69A7AULL, 0x0BF600FC0440BDF3ULL, 0x2F743A08E78A6A87ULL, 0x44C03F411A233514ULL, 
            0x1E29BCD0869A8464ULL, 0xDCD874C8257AC397ULL, 0xB748CCFC40710899ULL, 0xB8B4D81FC54170EEULL, 
            0x9013EF58664D4E14ULL, 0x69A984FEEB998D83ULL, 0xF51A549A5E136341ULL, 0x8E6A9C5C1DB6CF68ULL, 
            0xA73B0ADC41728632ULL, 0xD452274E3BDDB89BULL, 0x08F35BD536C37B9BULL, 0x18B4CA10F0FECC84ULL, 
            0xF29E0E48781A82BEULL, 0x55FA25F802E5C32FULL, 0x4DC60794B73D563DULL, 0x893E25A315CE2236ULL, 
            0x466C8C176D421453ULL, 0x88B61FF5AC0A0626ULL, 0xB6A5C5029BEBCC79ULL, 0x4DAD8F0FFC12F97BULL
        },
        {
            0x14A159ABC1A5674EULL, 0x7555E5D401DDDBDFULL, 0x73ECB2B43F3857DFULL, 0x884509B8F6E6C13EULL, 
            0x2184CEEC2C6CB533ULL, 0x77453B31BCFAD3B1ULL, 0x74CCE2EB57C259D1ULL, 0xBC41612227FE005CULL, 
            0xC1A7BA0B44BC94BBULL, 0xA31DF482C093C8D6ULL, 0xDDCE6B1321CEFC3DULL, 0xA42EE0419312E9A0ULL, 
            0xB1B4F65F133CB668ULL, 0x9C1F2E1CBDD5C8BFULL, 0xDB72F6D5A17481D9ULL, 0x3C9901316A2A978FULL, 
            0xE48B5C51C66680C0ULL, 0xF2BAAFFD29A6541FULL, 0x5D482A96037B49F6ULL, 0x22DCA7AB8601972AULL, 
            0x5C295D9A52431DF9ULL, 0x067FAFED9653FA82ULL, 0x61637E636F8C1436ULL, 0x7E710E21D2B25C2EULL, 
            0x5ADAC2C34D5CAF6EULL, 0x70FBB2CC09770CFAULL, 0xA5628DE477F1BEF0ULL, 0x0603C3DE7E0D83B1ULL, 
            0xC89936C1A32AC530ULL, 0xEDD83F8E23292BBDULL, 0xC602929F1A7FE2F7ULL, 0x8DA9616CE83E03C8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseGConstants = {
    0x14D10DBE402BB68BULL,
    0xAF2C4E2508B5010BULL,
    0x5F2BE7816318B4ABULL,
    0x14D10DBE402BB68BULL,
    0xAF2C4E2508B5010BULL,
    0x5F2BE7816318B4ABULL,
    0xDC66FEEF5A9AC88AULL,
    0x32F27FB96DBC623DULL,
    0x54,
    0x08,
    0x08,
    0x36,
    0x39,
    0xA8,
    0x1B,
    0x82
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseHSalts = {
    {
        {
            0x960BA215B096F606ULL, 0x56652C1A629E4D4CULL, 0x88DF0DA6F96EA0F2ULL, 0xD6F8744FF8F3E183ULL, 
            0x8DDA502E0AED5892ULL, 0x9D7A9D9C84F79FBBULL, 0x39828A842F543D9BULL, 0x34A581621D326E84ULL, 
            0xB0051410560B0915ULL, 0x2F7C604A188CBE02ULL, 0xDABCBB66F01CC586ULL, 0x67B441E1FD6E9CA6ULL, 
            0xCF50170A8C6BEED8ULL, 0x788978D6727DE9CAULL, 0xBDB6B98081E28793ULL, 0x42841233A372F2CCULL, 
            0x3F338B804C50EB11ULL, 0x899A4776AE0EE6A4ULL, 0xE1EF18C5497BBF80ULL, 0x1EE7EAE7A9582774ULL, 
            0xC8ECA493BA62D695ULL, 0x3C1C88953E6CC7BEULL, 0x2A3D26F80C37E3D1ULL, 0xDD0F458AF2BEE34EULL, 
            0x185F0CB9CA6324E1ULL, 0x4E664CA06794FFF9ULL, 0x8FA6C9E8D0AFDAEAULL, 0xB59A75B2D7CD050AULL, 
            0xEC78F02A4890BDC0ULL, 0xB2ADC58AE474C019ULL, 0x12565FE5141DB19BULL, 0xBCDF58E639CA89BAULL
        },
        {
            0x7E68DB2FDB22BBEAULL, 0x84A0083C2A1849DCULL, 0x02847E2C02C8E2AEULL, 0x99B6F734C5E2B716ULL, 
            0x99B9A5F18BE60649ULL, 0x18CF74A274E5F348ULL, 0x8B398F86AA3948BFULL, 0x03AC400178AAD78DULL, 
            0x5EA71C76ED9E2032ULL, 0xE6F246A2026E7A01ULL, 0xBD0253A6CE9DC01CULL, 0x41482BA3E16077FBULL, 
            0x1664C9A60B1E7A25ULL, 0x28C8169C7CA93017ULL, 0xFC35E06EF275AF29ULL, 0xA12865C240641297ULL, 
            0xFC98C69B17ECC13BULL, 0x9C6DD207DD770B70ULL, 0x06CCF98344EA2BD0ULL, 0x8FF2B241A4C04B9BULL, 
            0xC7C59DC323E880FEULL, 0x4103B04C8E7926B5ULL, 0xEE6FE974F409306EULL, 0x9AC45C0863F7E050ULL, 
            0xC0157858EA482870ULL, 0x2DF30F3F2827BFD6ULL, 0xF4B774FC6E34B37FULL, 0x4ED15252658CBD26ULL, 
            0x178AA60651989CA1ULL, 0xBCF011499B2D082EULL, 0x9F7E18F69D0EE125ULL, 0xB3A247B71C689421ULL
        },
        {
            0x6007107853FAA69DULL, 0x70C5D981F3542D38ULL, 0x88B43ACF10C48652ULL, 0x780EA5DDA1576155ULL, 
            0xCBAF7C98F2C538E8ULL, 0xE780EDBFA7DCD88DULL, 0x9981C33E1493E53AULL, 0xAA3B110891821DDDULL, 
            0xCA4D8F283959005EULL, 0xF410648A069D8062ULL, 0x2C68CC8D5747D4BFULL, 0xFC0E359234C4A86BULL, 
            0x2870CB3A864BCB95ULL, 0x4A80A8588889539BULL, 0x19C187FEDCCBAF58ULL, 0x1431B4B7378BAF1DULL, 
            0xA2492522B51A21A5ULL, 0xE14250882A7D4675ULL, 0xA373EA757AC0A7BDULL, 0x60EC33C6D631990DULL, 
            0x3C0740AA0053AB9BULL, 0x05F33CD1903FFAC4ULL, 0x93758FD9915B8377ULL, 0x7558B6401BE38618ULL, 
            0x60E4400478E029AEULL, 0x60407089F0F26383ULL, 0x4E59316BEC597DB7ULL, 0xBD7CDEA1758247E1ULL, 
            0x28B30F06FBB1D1F4ULL, 0x654A1E13129570F7ULL, 0xC5FE3EA26AC295B1ULL, 0xE26A008E81CA1737ULL
        },
        {
            0x2D0A15DD94EC110EULL, 0x03EC7953AF798014ULL, 0x577F7DBD5075F567ULL, 0x11E0BA70FBBE3E4FULL, 
            0x005D5314C8607155ULL, 0xF36FAE085F2844A8ULL, 0x2B7A8048DF6D3030ULL, 0x01C7448CAF9094DAULL, 
            0x115BDC880B4457ADULL, 0x9BB2016CD60CD723ULL, 0x6B7C7150258660E6ULL, 0x7569F91B486D3957ULL, 
            0xE260020E44EA7A36ULL, 0xCB6A88EE81796338ULL, 0x6631D920ADCC1851ULL, 0x8882819587AD9B46ULL, 
            0xF6F4B46DF7B0D0E5ULL, 0x0D8323556D1A661DULL, 0x65C10A1A30431883ULL, 0x5B318226652CA807ULL, 
            0xEA583A7A2EF58582ULL, 0x0FFB482C9BA7E7ECULL, 0x042AE78D6538FB1FULL, 0x75F41BA16D664758ULL, 
            0x3FAF9B50627898A0ULL, 0x37E86F94809B0223ULL, 0x89310DC63C16D2AFULL, 0xA4B36D5228DA63CEULL, 
            0x4383A9C313705F0CULL, 0xB8D6E42E658A2B8BULL, 0x1A66A30412A71759ULL, 0xEEBB9EBBB2213528ULL
        },
        {
            0x7804FFDC21E33CB6ULL, 0xC1AD78C122B0FF13ULL, 0x65A561DCA6FF6C0BULL, 0x8DA9A24D9E24428AULL, 
            0x5513F55860FD13E1ULL, 0xB9FB3C04908E9567ULL, 0xE731072628991954ULL, 0xAEFFA9E446256675ULL, 
            0x063462263DCEEC62ULL, 0xF689E6B0984DAFF3ULL, 0x3C3A8F3A36FF0BC2ULL, 0x4C85C33AA384218AULL, 
            0xAB22622542583BE7ULL, 0x4F653B1AF3713EE1ULL, 0xEE833833CAA345BDULL, 0x0EDF3C934A9DE8E9ULL, 
            0xE9A5D4EB01025855ULL, 0x9F648ECAEBFC526FULL, 0xC7740220ADB34044ULL, 0xCEE85FFA2FDC241FULL, 
            0x7F22B5BE76885854ULL, 0xB1D9130870E7F902ULL, 0x0D6A8407D66F95B6ULL, 0xAEBEB91B26B0F9AAULL, 
            0x62CAEB36708C4963ULL, 0x3498CF0011B28A8AULL, 0x54DA886DA04B4651ULL, 0x64165A56964AB88CULL, 
            0x72F9E3C7BD1C038CULL, 0xA93FC80D32F7BA0CULL, 0x60FCFF9EC624E342ULL, 0x40B58460A0933720ULL
        },
        {
            0x8F3177C8A5BA25DDULL, 0x027C05B2E16D87CBULL, 0xBDFA84585A250232ULL, 0x40FEB14FFB8B9EC6ULL, 
            0x67020E7DD0734D90ULL, 0x6AF91BF06774664BULL, 0x215724CAF2FA6377ULL, 0x054C0C9EECCBDA15ULL, 
            0x9506B458C6A37EC4ULL, 0x3C31945BA9B9BAC6ULL, 0xD6A01D3289202282ULL, 0x0402DB17B9438303ULL, 
            0x2108DA5AC379FC5AULL, 0x6B14A40FA2612786ULL, 0xEAEE4C4C9694F253ULL, 0xF7C647DB02190460ULL, 
            0x355176644DC6C6F7ULL, 0xCA60AF83124D4C59ULL, 0x7B8F22A270DCEBD2ULL, 0x2AC0213E6C4C4613ULL, 
            0x68DB6B80E5A0D4B8ULL, 0xF8B4CA5C93F1B784ULL, 0x4EA80FC3F9E3D0A8ULL, 0xCC8E3913C476F197ULL, 
            0x88DB85E6E5CBDFF4ULL, 0x5DE1B58CBF7D813DULL, 0x161D9919A794FB4BULL, 0x2A571F4F616C125EULL, 
            0xA49885380397D1D0ULL, 0x0C7D118429936684ULL, 0xEF891D478078CF25ULL, 0xB9AFBAED90A6B21BULL
        }
    },
    {
        {
            0xF0BB246C8A898535ULL, 0xD57A0A467C571015ULL, 0xA6464BEF44443B47ULL, 0x810426D20F2CAE09ULL, 
            0xE905282823E7A4CFULL, 0xC455E88178774F78ULL, 0x54B4D7974C6540DBULL, 0x5DA42711EF57B840ULL, 
            0x93779E17C7DC8CBFULL, 0x2DE92C071645EF12ULL, 0x1B54D7FC8BBF6929ULL, 0x6215048E5DCE8290ULL, 
            0xDED1A00BD670446DULL, 0x2A3B19875E3EC7F0ULL, 0xABE7C6624338CABDULL, 0xDEFDF85E05F33DDAULL, 
            0xFAF6649BD6E62E58ULL, 0xD28D27170AB325A0ULL, 0x49CF49F368C19336ULL, 0x1BF253EB2E1760F1ULL, 
            0xFFEB2B5D36A0C4C2ULL, 0x0E082573455C196DULL, 0x1B529CC15814A9DFULL, 0x1712FC6D6516A4BBULL, 
            0xD40164F831029717ULL, 0xDA6BED16B0C4051EULL, 0xEFE8C27CA81E1FABULL, 0xA42DE5A09459185FULL, 
            0x8C50B13B7232C200ULL, 0x9ED7E7987E06A1DBULL, 0xEEA7C8BE05B3DCA1ULL, 0x1C2DA89AE0B2AC94ULL
        },
        {
            0x5F3385A7D75E91D1ULL, 0x82B23DC5B90C44BFULL, 0xFF010C9E54C393D4ULL, 0x0BBBD5BE215BDE4BULL, 
            0x407CCF7BFD7B865FULL, 0xC56A7006FCAC8450ULL, 0xC6F37FE7892BB562ULL, 0xFC665E85C1F2DB1BULL, 
            0xA9B9BEF0226F91B1ULL, 0xE877B0F69E132412ULL, 0x1466AF34F7AD20AEULL, 0x5C6EEFB070F7F00BULL, 
            0xC00004B98962B674ULL, 0x4E199CB7F6CA2543ULL, 0x8D0EA60669417ACBULL, 0x6B3335BD6C5C68B3ULL, 
            0xEA612A5A240CF2B4ULL, 0xFB8C67FA023F9310ULL, 0x2A7F8E5C5C2F60DBULL, 0xA9BB80EC366C89D0ULL, 
            0x81C357CBB64EC947ULL, 0x89591387FDDA3D13ULL, 0x0AF34A290E3E32A5ULL, 0xEA431C99E43ADA6FULL, 
            0x250C51303D64186AULL, 0x1F9F30AFE58A579DULL, 0xB82C30E31DC371A4ULL, 0x43B544463F98BA38ULL, 
            0x1432396846E4E317ULL, 0xD09004B40CCC02C7ULL, 0xD991D88BFE7292F8ULL, 0x6A6AA6BFE21E5561ULL
        },
        {
            0x20D7E73F529B3EA1ULL, 0x27B0A733C82A5D58ULL, 0x8EB031494F899AF6ULL, 0x357ECC57D31CF69AULL, 
            0x404AA720F2797644ULL, 0x34D6A0A3301C936AULL, 0xD36F654B0DE43E49ULL, 0x413CFD4759EDFE41ULL, 
            0x609BBEE9455FCBDCULL, 0x4AFDCE47A5E4A2E3ULL, 0x121465CBEC7BBB2EULL, 0x63C319369D4BE4AAULL, 
            0x5CA6023D1EF72DE4ULL, 0x5068CBA5910788DFULL, 0x8102FD47FE639C93ULL, 0x0B53534F3FBABAFEULL, 
            0x80FCD15440FCCF79ULL, 0xC11303AE0F52123DULL, 0xE502E6B0FC02D2F1ULL, 0x931FE8E7CFFE1D35ULL, 
            0xA89B6917F06B93C1ULL, 0xD3FAAA809A2028E8ULL, 0x54020F6EC2392B49ULL, 0x0C6A06CC6206C398ULL, 
            0x1474966680CE0B37ULL, 0x4FACE2D7754BFB7EULL, 0x8B05978902555EDAULL, 0xC00E7D2850255245ULL, 
            0xF3B4CF76B1BC28B2ULL, 0xC272A55D85C8DE78ULL, 0x9FE9E39E0C053C5BULL, 0x0AE61D6C4FF03E25ULL
        },
        {
            0x47F9DA9B2C943A38ULL, 0x5A477A61199EB888ULL, 0x4195A7DD4A47A29AULL, 0xAE31A0822D73752EULL, 
            0xD8F2BB8C6F2241FAULL, 0xA0AE4ABD7B404871ULL, 0x972AEDD4D5F26157ULL, 0xDA23D4D4D79BA14DULL, 
            0x6B98CEC7425F4336ULL, 0x4EA986DF566970CFULL, 0x535C5623D90CE503ULL, 0x4DD77FE388CEE1B9ULL, 
            0x52F34F88914C08A2ULL, 0xE9719AD947918C5CULL, 0x2703E479B1211660ULL, 0x6EBBC1F786782383ULL, 
            0x6D1C8BC72D7088FEULL, 0xAD16AF03DD41ED13ULL, 0x8E295E0A0F4DAAC0ULL, 0x38EB6E928188FB0AULL, 
            0xCD99DCD925C0F3C8ULL, 0x2F9923C1AFD7C3FAULL, 0x01D2CA1087EEFE4FULL, 0x6D0636FF65CE48FAULL, 
            0x621E777E877819B0ULL, 0x5D0D0EA1B8462FA6ULL, 0xD23D77BC9FCF87D8ULL, 0x4FBD22D2BDB1ED24ULL, 
            0x4C6F8A81EEDB1300ULL, 0x686B336BCDCE0513ULL, 0xEA8E6FBC94D0A4EAULL, 0x8D98D1BACB5CD9F5ULL
        },
        {
            0x0F7DFCEACB3CCF82ULL, 0x455AB9E4EC6C36BBULL, 0xA0A467010E417865ULL, 0x11E6B425F7A91CE8ULL, 
            0x8C54524054BC204AULL, 0x95788E12A030C322ULL, 0x8CA20ACE68EBE534ULL, 0xC8A58704DCDC7A77ULL, 
            0xCF46EC88EC0550A2ULL, 0xBA25FF951D268421ULL, 0x618CD238B8F4CD4CULL, 0xC3B0492974846F3CULL, 
            0x15D532D37AD3888BULL, 0x119E109C8CD3913DULL, 0x5ADD8A5285312C1FULL, 0x807E70E40B9081D6ULL, 
            0x29CBAF19534E1777ULL, 0xEB3387D067BB02B3ULL, 0xB7DE531A081E25C2ULL, 0xF114D5DA07761B52ULL, 
            0xD19A2AD8CADAE914ULL, 0x0E532908177355DAULL, 0xA05FD6DC61804E06ULL, 0x39CBC65091C10D9FULL, 
            0xE38EB24713888775ULL, 0xA4E63048F99F048DULL, 0x4589966733EDA54BULL, 0x45AA243713641A19ULL, 
            0x3EA9297B0F8770BDULL, 0x68FCEDD4EB6B15CDULL, 0xEFDB377CABE72E4CULL, 0xFCB972079091F646ULL
        },
        {
            0xD3F7CED101C0083CULL, 0xFE46E4DBA9567AF2ULL, 0x7C98128AF92C4B29ULL, 0x34448EB2CAC12B8FULL, 
            0x4A76210EAACCC8D6ULL, 0x086FC58E5DDC4706ULL, 0xB145B1B0657B2581ULL, 0xAB70F5854D451618ULL, 
            0x6E031D81EDCC5E8DULL, 0x32A1D785DD2DBFFAULL, 0x4C4098DD3F1BC9DDULL, 0xB85FBDBF7520CDE2ULL, 
            0xBE341BBFC504F7F4ULL, 0x5BD243EDDF2E6900ULL, 0xBC90A20301A48295ULL, 0xD5E358A768365C5DULL, 
            0xCD74E446DEB6C750ULL, 0x492B220FB36130BBULL, 0x4558B3AF74C7143AULL, 0x7D1212CF1540DEBAULL, 
            0x5AEED257D04A32CFULL, 0xDE81B21F0EE0898AULL, 0x7D0E4DA9B3415079ULL, 0x9B1088FB2941BD31ULL, 
            0xAD8EBE4FD2B6E309ULL, 0x5BBADDF8C59BE197ULL, 0xF50CE4CD83348DE6ULL, 0xE42202F41EA8E493ULL, 
            0x1768C20364182585ULL, 0x48E933703FDDC4A5ULL, 0xFE1E9363752AC495ULL, 0xE2BEA3693BA02AF2ULL
        }
    },
    {
        {
            0x0452752B20D2875BULL, 0xB94341569B18ACD3ULL, 0xC1A55B54CCA0C24DULL, 0x28B030EBC12B74C8ULL, 
            0xAF4D0962C0D3926AULL, 0x94E0106214984C69ULL, 0x7ECA47AEDAE76402ULL, 0x5FFA954C8615F0EDULL, 
            0xF243993FC39547FFULL, 0x25B9DF154ECDF7BDULL, 0x23C3F034941052BFULL, 0x3E9AF4A9544A387DULL, 
            0x84511A802D14409DULL, 0x27E2F4D69A3F3FFEULL, 0xA78CE21DBF09F79CULL, 0x00C4279F45178C42ULL, 
            0x0507C83ED7F65AAEULL, 0xD70B1F8DB67EDB87ULL, 0x5720D4DD2E9DCEC1ULL, 0xE69B3BCCC1CE4D4BULL, 
            0x7EC8405DA09885A6ULL, 0x4CB05D86DCBA3D13ULL, 0xF7DAF6CF142245B2ULL, 0xBFA323E72519F305ULL, 
            0x77AF09601C778DA3ULL, 0x4A98F6F47AC201D8ULL, 0xF6D450D4E342539EULL, 0x81463EE56BDF54DEULL, 
            0x5F025D8F598E2783ULL, 0xFC7D1D1E1B78E5E3ULL, 0xFEBEB7640EA7F8FBULL, 0xB2325C701DFE1D84ULL
        },
        {
            0xC16AF401695BC646ULL, 0x8C0F2B8D537D6081ULL, 0xD66D3161320269B4ULL, 0xEE7827ED2CC2A53BULL, 
            0x99B822F198E0D944ULL, 0x6E793A6169858416ULL, 0x806E9E32553BA47DULL, 0x5A25E9954A25DF83ULL, 
            0x8D6D16510CFF730AULL, 0x1BAE463E21733C3AULL, 0x9B6E5F6D0CBBAC37ULL, 0xF73CD2E6B9D5F4D5ULL, 
            0x7826BB5E81CD4CFDULL, 0x7A13A69F6088F15BULL, 0x9B6D6105D8293218ULL, 0xA2C9CBEDCEC087A9ULL, 
            0x6595F665C441B666ULL, 0x741D54DB81968C69ULL, 0x54039B54A5FAE909ULL, 0xCC143A394BCAD137ULL, 
            0x6508767215D1560AULL, 0x71BE7BA7033EF5A8ULL, 0x42EB68DD8A61D743ULL, 0xD1F7270AB9EC429DULL, 
            0x7896D8F57D5EDADEULL, 0x62C0F1E52002B20CULL, 0xFBB7ECFD58F38237ULL, 0x99200A4E79FBD789ULL, 
            0x82C08F977B20D95FULL, 0x29B248ECF8964851ULL, 0xD06567D8A8A8AB96ULL, 0xF4620BC9CC1A140CULL
        },
        {
            0x0E6122F8BFDD1FFAULL, 0x81FF97642D97FCFCULL, 0x55E13C784D129F50ULL, 0x62C582CB601575DDULL, 
            0x20A46DEE6509209BULL, 0x1DBD799E92EFB26CULL, 0x07CC84ACC2B86D33ULL, 0x7314D74A81E924E1ULL, 
            0x4E2239CF719584B0ULL, 0xFF925FB1BA112720ULL, 0x42E659BFC34DAC9DULL, 0x6504780A13DB313BULL, 
            0xE7C193D917934AC0ULL, 0x4CE955CF727E4CA0ULL, 0x830720E7BBD44A56ULL, 0xDEC646DDC385DAA3ULL, 
            0x6F268D272E56165EULL, 0x5FFF1D8C64F0593CULL, 0x736963510B9D8304ULL, 0x9356D0726D04849CULL, 
            0xA20829B9FDF00906ULL, 0xD4DBFEEDFD26B014ULL, 0x2C59EEDB30C41767ULL, 0xB2B9398320E075E0ULL, 
            0x5B1F558DDE24A133ULL, 0x3E9D259BF4E966FEULL, 0x19AA53E0AF09E0E6ULL, 0x9D4042903C0A2170ULL, 
            0x0FF90113279A5D49ULL, 0xAB71EF37C025BD80ULL, 0x516ABF19CFFBDBE6ULL, 0x4E771CACEFC7B9B5ULL
        },
        {
            0xB592D44122E24286ULL, 0xF9EBBF3CD96CBD7FULL, 0xBDF1298776928376ULL, 0xE477DB8BF0691449ULL, 
            0xB694F955877DA571ULL, 0x6398F2BF46C2510FULL, 0x27D252CAD1CA38A3ULL, 0x0D8807784A1BA4B7ULL, 
            0xCB0888573775320FULL, 0xB8B223B07AB5E0BCULL, 0x64F2A15698262C26ULL, 0x2E5F11281247916EULL, 
            0x5C4FF4811E4D1D42ULL, 0x7141DF12D91BF17AULL, 0x33725D75E141A833ULL, 0x4D2B85EF14705761ULL, 
            0xF131954ED8014D98ULL, 0x2D873A26F0A125EDULL, 0x3EEDB566C19FF5A1ULL, 0xE8B3140CCA2740D7ULL, 
            0x08F8980DD869818FULL, 0xF0E411B4C8D8664CULL, 0xC05153446B39D884ULL, 0xEC0DDC70993396B8ULL, 
            0xDB988BDBC49BC422ULL, 0xE40A67A101083EA6ULL, 0x937A40EBA7B729B9ULL, 0x7B9F539D0BAFA0C4ULL, 
            0xAA729F1733107755ULL, 0xF6172497657E6752ULL, 0xCBD9F5E7C29CAF94ULL, 0x2D6B44FE21D0AAFDULL
        },
        {
            0xAD9244100671C661ULL, 0xF89E3D7CE0F63007ULL, 0x7C832C3C2641BCFEULL, 0x1B9E0B767792EFA0ULL, 
            0x85FCB151A191B2D4ULL, 0x076971296FBCA17AULL, 0x8FB774E782C10D5FULL, 0x4988961F46A096C8ULL, 
            0x03EAC5BD7E998345ULL, 0xDB642B87FA39A990ULL, 0x8280CFF404F125A6ULL, 0xA60EA21E84F16DA9ULL, 
            0x32FD995BD27FDD92ULL, 0x2647B88783F8F38DULL, 0x39E72883A0E037ACULL, 0xC99A9DD8F89A86F5ULL, 
            0x77884BC6D28AB48BULL, 0xEFDEF8F1A81505BDULL, 0x794F43C60EFAC1D9ULL, 0x2A407425F0EE0F6EULL, 
            0xA5392250D4688A32ULL, 0xE96ADC1A5A10DB3AULL, 0x4185E6A5330C1E38ULL, 0xB38AB088A713E63EULL, 
            0xF4D197435902F75AULL, 0xC35708D23D3AAB5DULL, 0x967E6D0C07B7CAD2ULL, 0xF9D6C1DA7EF5E696ULL, 
            0xB58402989B2E9DFCULL, 0x39678B4A11175DB3ULL, 0xF053BBEE9E439A84ULL, 0xD7177B5F7EB3B340ULL
        },
        {
            0x4057F5A76F6A6E0CULL, 0xC81E5E4422F94F7DULL, 0x8C40112F97A28B6BULL, 0x21D9C1397EF5227FULL, 
            0x099C14B627655BD9ULL, 0xF9BA2715008A536AULL, 0xB6CF9D496399ABDCULL, 0x3030B443BEE0FF8CULL, 
            0x5C8A081CAF62DA4FULL, 0x199C21234E23864CULL, 0xA2AFC28524D4C6C3ULL, 0xC5C6FEC7A61D5D62ULL, 
            0xC2292D4B74CD8EC1ULL, 0x2062FE2731EFAB19ULL, 0x7C795A2E88DBF24AULL, 0x6711B6D2B1B9C5F1ULL, 
            0x18F009A4644AE708ULL, 0x9F63CCBC0E9B1849ULL, 0x785E797DC9CB6ACEULL, 0x5192A6536AF77E0BULL, 
            0xD94126B25220F1E0ULL, 0x91CDC7004406AB32ULL, 0x3DB39074B67E242DULL, 0xDB2958E3B378B67EULL, 
            0xCA7A1CCB654BE8EFULL, 0x0A836502C5B9A580ULL, 0x45D371F45C7C3904ULL, 0xF99287617DD0FCC6ULL, 
            0x8C4D736E9E2FF9CCULL, 0xA65F9566AB589B86ULL, 0x6C46EF965A20DB74ULL, 0x5D30E5EC857091FBULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseHConstants = {
    0x9BA5E7D52687B982ULL,
    0xC9B9D44105C82046ULL,
    0x09559DF93B0B515BULL,
    0x9BA5E7D52687B982ULL,
    0xC9B9D44105C82046ULL,
    0x09559DF93B0B515BULL,
    0xEEAF1F2A62B35380ULL,
    0x5AAD23AE79CB1612ULL,
    0xA8,
    0x49,
    0x20,
    0x5D,
    0x23,
    0x7E,
    0x2D,
    0x6E
};

