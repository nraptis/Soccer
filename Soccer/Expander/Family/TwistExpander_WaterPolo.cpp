#include "TwistExpander_WaterPolo.hpp"
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

TwistExpander_WaterPolo::TwistExpander_WaterPolo()
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

void TwistExpander_WaterPolo::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 10583593302543396985U;
        aCarry = 15783581420527581737U;
        aWandererA = 9686756186485713831U;
        aWandererB = 10276308897360305012U;
        aWandererC = 10793166776985071556U;
        aWandererD = 9263339500992967850U;
        aWandererE = 17699310051554625158U;
        aWandererF = 9906621094909396031U;
        aWandererG = 17074782971729862323U;
        aWandererH = 17403544095906722400U;
        aWandererI = 14903565653586430699U;
        aWandererJ = 17030928242641825802U;
        aWandererK = 16338404740265347457U;
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
    TwistExpander_WaterPolo_Arx aArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_BArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_CArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_DArx;
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

void TwistExpander_WaterPolo::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16084782291684343732U;
        aCarry = 14153251400475507070U;
        aWandererA = 13793938590265342705U;
        aWandererB = 13472364021156063523U;
        aWandererC = 16141835728798061371U;
        aWandererD = 18315451794701914146U;
        aWandererE = 14821698105025787780U;
        aWandererF = 14036560608624573047U;
        aWandererG = 14255350038576809729U;
        aWandererH = 9923592113705623376U;
        aWandererI = 12895518118804626888U;
        aWandererJ = 10209200904575399035U;
        aWandererK = 17726430762611442256U;
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
    TwistExpander_WaterPolo_Arx aKDF_B_AArx;
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
    TwistExpander_WaterPolo_Arx aKDF_B_BArx;
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
    TwistExpander_WaterPolo_Arx aKDF_B_CArx;
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

void TwistExpander_WaterPolo::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    }
    // KDF_B PhaseA invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseB invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    }
    // KDF_B PhaseC invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneD (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    }
    // KDF_B PhaseD invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    }
    // KDF_B PhaseE invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseF invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseG invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseH invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_WaterPolo_Arx aSeed_AArx;
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
    TwistExpander_WaterPolo_Arx aSeed_BArx;
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
    TwistExpander_WaterPolo_Arx aSeed_CArx;
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
    TwistExpander_WaterPolo_Arx aSeed_DArx;
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
    TwistExpander_WaterPolo_Arx aSeed_EArx;
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
    TwistExpander_WaterPolo_Arx aSeed_FArx;
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
    TwistExpander_WaterPolo_Arx aSeed_GArx;
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
    TwistExpander_WaterPolo_Arx aGrow_AArx;
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
    TwistExpander_WaterPolo_Arx aGrow_BArx;
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

void TwistExpander_WaterPolo::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_WaterPolo::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_WaterPolo_Arx aTwist_AArx;
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
    TwistExpander_WaterPolo_Arx aTwist_BArx;
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
    TwistExpander_WaterPolo_Arx aTwist_CArx;
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
    TwistExpander_WaterPolo_Arx aTwist_DArx;
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_WaterPolo_Arx aGrow_AArx;
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
        TwistExpander_WaterPolo_Arx aGrow_BArx;
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

void TwistExpander_WaterPolo::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 2 with offsets 1953U, 3878U, 1250U, 3023U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1953U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3878U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1250U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3023U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 2, 1 with offsets 735U, 794U, 636U, 611U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 735U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 794U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 636U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 0 with offsets 4193U, 424U, 2465U, 3622U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4193U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 424U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2465U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3622U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 1, 3 with offsets 579U, 120U, 7839U, 2848U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 579U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 120U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7839U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2848U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 with offsets 1477U, 707U, 612U, 186U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1477U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 707U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 612U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 186U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 1940U, 514U, 727U, 230U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1940U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 514U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 727U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 230U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 1, 2 with offsets 2014U, 727U, 1388U, 1612U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2014U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 727U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1388U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1612U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 1, 2 with offsets 354U, 210U, 1067U, 1024U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 210U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1067U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1024U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1954U, 940U, 1078U, 1534U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1954U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 940U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1078U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1534U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_WaterPolo::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 1 with offsets 154U, 4572U, 2497U, 939U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 154U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4572U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2497U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 939U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 2, 3 with offsets 5877U, 1153U, 7678U, 4228U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5877U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1153U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7678U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4228U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 2 with offsets 918U, 6666U, 5430U, 2604U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 918U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6666U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5430U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2604U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 0 with offsets 1056U, 423U, 1207U, 446U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1056U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 423U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1207U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 446U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6499U, 327U, 7238U, 3572U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6499U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 327U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7238U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3572U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 1, 0, 3 with offsets 819U, 1442U, 1460U, 762U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 819U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1442U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1460U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 762U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 3, 2, 0 with offsets 1984U, 1327U, 636U, 828U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1327U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 636U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 828U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 2, 0, 3 with offsets 141U, 1214U, 1770U, 1111U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 141U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1214U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1770U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1111U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 0, 2 with offsets 26U, 1756U, 1429U, 906U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1756U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1429U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 906U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1239U, 1520U, 857U, 150U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1239U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1520U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 857U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 150U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseASalts = {
    {
        {
            0x59F26CCAB82CB09EULL, 0xE674FD0952940B57ULL, 0x42A9CB0656B8833FULL, 0xC22AABCB6C0BD86AULL, 
            0x75CB0744B2056C55ULL, 0x8FC12786E67CC349ULL, 0x516068D95C62DDE4ULL, 0xF43461740CC900FFULL, 
            0x913A0182560D55C6ULL, 0x6D8B35A690C63FF6ULL, 0x133D07D90DC66DEBULL, 0x2789CCF2A439F6A1ULL, 
            0xB9582DB47E55AABDULL, 0x57E379FE45D2BC5EULL, 0x2FCCD2494B596439ULL, 0xF0CC4DF5D8934C32ULL, 
            0xEFFC78737D819267ULL, 0x5F45B0464205189CULL, 0xA0045A19BC979916ULL, 0x8CE365DAEC3E2D9EULL, 
            0x56F0666EACE452CAULL, 0x31BE50EB682A521AULL, 0x60007AFC9D4FE9D0ULL, 0x4182961AE75D667CULL, 
            0x67E4C1DC562F3153ULL, 0xA728B3D8B9735B90ULL, 0xD14AF73961CE2872ULL, 0xF37E65E5DADBA02AULL, 
            0x155A9B9E51775736ULL, 0xCA8323C49CE43414ULL, 0x6D6979E430B09247ULL, 0x5AA93CFBD51FCF70ULL
        },
        {
            0x20BF8069E2BAADC7ULL, 0x06363F843B3F7139ULL, 0x35466CD91C2C5D8AULL, 0x8934331FD29C52F5ULL, 
            0xDBC87805D92FB50FULL, 0xFE27666B5C3E0D08ULL, 0xE2D55003D3D7C6BAULL, 0x527C8E60B29492BCULL, 
            0x7C689245BC0D8509ULL, 0x5757C653BF0540C1ULL, 0x35E7C3BD5ACD3054ULL, 0x2BFA2F058BFA8147ULL, 
            0xC5A14235EA5D8817ULL, 0x3304F7FFC6E12881ULL, 0x6619196E541BF876ULL, 0x9CCA2324044431B8ULL, 
            0x9980E2F507A3DDC3ULL, 0x4E08700605D96497ULL, 0xE0E878A40CF8C678ULL, 0xF2ACE7F26B1E1C65ULL, 
            0x8BD2D33AD5CEB0A3ULL, 0x7BDA22084E978972ULL, 0xDDEBA1E9C0C7F01CULL, 0x3226F3A5D94F4803ULL, 
            0x0EE8A33C61C4D108ULL, 0x7E27F419494E2FEFULL, 0x2C57721F345D8C26ULL, 0x594A994746ED296DULL, 
            0x6E0BEE3418DDABC0ULL, 0x564304FB76B2EFC4ULL, 0x415F3F73514ABB52ULL, 0x7AB238C3368CCFDCULL
        },
        {
            0xF533B833BC0333C8ULL, 0x779461AB9B9506B6ULL, 0x3683C6DAB6B7C96DULL, 0x4B6FE1D84188B7CFULL, 
            0x07F924D01743AAC8ULL, 0xCB370D0518AF9662ULL, 0xA4DD4E56A57F16BBULL, 0xF7A5103706A212A4ULL, 
            0x6F88FEB5674F64A4ULL, 0xCDC2BE36DFF13059ULL, 0x81AFFE17E44A4987ULL, 0xE896DF0F10DD18C3ULL, 
            0x16B85409FCFF731EULL, 0x237ECE0A86106D7FULL, 0xEBA708C10A9E4408ULL, 0x6A2D27D1A30657A9ULL, 
            0x9BBC9DF1289A8A95ULL, 0x885C091706DB5A47ULL, 0xEC4CC7756C74CB1BULL, 0x9571830651EA5F96ULL, 
            0x6080B8DC58B3910FULL, 0xA5FBC266F6C36AC2ULL, 0x945E45997F98B95EULL, 0x81DAB3805AC025D5ULL, 
            0x6CBE143517819426ULL, 0x2768CB2C71B413A2ULL, 0xA98C1D4D3E435086ULL, 0x6C0D26CC3157BBDEULL, 
            0xAC03DE75B8840358ULL, 0xA65D464620D7F818ULL, 0x504F7F34C1ADDEA5ULL, 0x400137FA22AB8FA7ULL
        },
        {
            0xD1D98AACB6E1577EULL, 0x46F168FC5382B0EDULL, 0xD3FEA0731CADE203ULL, 0x855D66E6EC7C94B1ULL, 
            0xEAA70D1359840A0DULL, 0xC6F46919E4B0BACDULL, 0xB745C525CC471352ULL, 0xE132D72DC3EAC920ULL, 
            0x59BAF84CDD74ADD3ULL, 0x715B2B3FD1AC0671ULL, 0x62C4719F080BB282ULL, 0xAB14A2417C124DB4ULL, 
            0x00314E31361173EFULL, 0x8642A06165C5C950ULL, 0x9665D8C68D5BFF06ULL, 0x53D3DE0D1BFCBC85ULL, 
            0x0B99D81C8F3D8AC8ULL, 0xF515D27485177DCEULL, 0x558F306A4C3F8691ULL, 0x49967B9365871262ULL, 
            0xC51A80FB9C1E7971ULL, 0x46775D603CD21F16ULL, 0x39282B094FD61540ULL, 0x86A366FBDF6415C8ULL, 
            0xB13305C41705735BULL, 0x7810909C73E229AAULL, 0xE8E76F536010D7FEULL, 0xE6E9807D53DC2A5FULL, 
            0x4273965DAA11A6BEULL, 0x15DF07BDE1C0035EULL, 0x29D00F66B221A021ULL, 0x053F0CA076205C18ULL
        },
        {
            0x93006C8EF1117657ULL, 0xC29073D9A0D5A11DULL, 0x359C5B9BE9DCEB83ULL, 0x441D817CA4B0D75EULL, 
            0x9033B7CE0724C9D7ULL, 0x5D9AFB58BC877BD9ULL, 0x13973E639643345EULL, 0x5F95F0F5BB5BB4D7ULL, 
            0x3A3C725374F4F4A4ULL, 0xC3AD6212C00A6AD6ULL, 0xC423A92E882C4696ULL, 0x6B5FD9CA37CC7A71ULL, 
            0xE1A3D1D1EB7E4DF7ULL, 0xDB6D00320A98AE8DULL, 0xB85DD41B210D12CFULL, 0xADCF00D3F11DBE61ULL, 
            0x5CE8CCC5B1A9DC58ULL, 0xEF56CB87B7C1D7F9ULL, 0x68E933355B6FD4BAULL, 0xA95785A704776EEAULL, 
            0x271BC5F1EC861B62ULL, 0x4FADAF2B85558C7EULL, 0x41BF3DD8E74FE92AULL, 0x6C50869A8A7954F5ULL, 
            0xFF7B7FB6621C5FCEULL, 0x9838F5394538AC5AULL, 0xD38051AA78CBD72CULL, 0xC580E376C7C61014ULL, 
            0x5EE9CB2019E8719FULL, 0x15C470E97FE31B8CULL, 0x6442C510F5713B3DULL, 0x7D54BC474C593853ULL
        },
        {
            0xE5A99CADF8596CE9ULL, 0x80D78A5170FB7FB4ULL, 0x39973D55642C4902ULL, 0x25718B83356BAD81ULL, 
            0x423D77375B0C6804ULL, 0x40B5B2309C81F994ULL, 0x9C9E629AF3830190ULL, 0xDEA24E2176C2C914ULL, 
            0x7673328E71FB95B7ULL, 0x46E319B827A296A5ULL, 0x75E626D731B7FFB9ULL, 0xFCD4F72126A6F7D5ULL, 
            0xFE6C99484D98760FULL, 0xC4FDD5B5298D9049ULL, 0x568FFBB8B1328706ULL, 0xCBAE17A2D411EB98ULL, 
            0x62B8E8D3A27A2B8AULL, 0x6C62412AA7CE3491ULL, 0x2454F20FB5F57AADULL, 0xE396BA991D854CBEULL, 
            0xAA7F2999D001A093ULL, 0x87B2CD606F18E995ULL, 0x425E20D87559B069ULL, 0x7824D94BBCFF2DE1ULL, 
            0xEB21E9A378B81117ULL, 0x21E4A289514E8B22ULL, 0x96D8C4547A3E3CB1ULL, 0x60337F70293F3DAAULL, 
            0x41097A6338233C44ULL, 0x5E9D9F437B8B9649ULL, 0xDB3F30E58E20E5F4ULL, 0xEAB517B3E9CCEE84ULL
        }
    },
    {
        {
            0x17C6FBC725BE9E63ULL, 0x8ED9BB43C0F38469ULL, 0x2FB206274DFDB67CULL, 0x062263D9AEBB8F39ULL, 
            0xF9AD2E010B05457FULL, 0xF634DD7294A96740ULL, 0xA3E16AF12711C7E7ULL, 0x61481469CF5FDD5BULL, 
            0x34D666D129242384ULL, 0x82C88FE94ED449CAULL, 0x1FBCC50F25B900F2ULL, 0x760E059846AB5385ULL, 
            0xD0BB76EE766B0078ULL, 0x93D907BBC1876D44ULL, 0x024779BB4578DCD7ULL, 0xB3C2A139685DFB1EULL, 
            0x5BDA59C202B65E12ULL, 0x2503DA88930B931AULL, 0x5551058FE6E3229EULL, 0x65456ACA7D1CDB0FULL, 
            0x75C6201F194D4B30ULL, 0x826CFAE45F3F9CF7ULL, 0x1EBBDD9C9F68CEFAULL, 0xFDDA2B828A59E51BULL, 
            0x7B16F1A281C635DFULL, 0xC3A84634A90D9A0EULL, 0x89AB0986E954B0CFULL, 0xFCFBDD78044A105EULL, 
            0xCF653C29B6C4C16EULL, 0x7063DB12D3433B6BULL, 0xDA63E79E6BD8C937ULL, 0x9B2BE7C5239DAE56ULL
        },
        {
            0xF006F3455031B21CULL, 0x4944142519AB6FBAULL, 0x6F237CD3E6F2C47CULL, 0x8290A8E300216C46ULL, 
            0x61F6FB40268B2C5AULL, 0x12056EED9DFF6A98ULL, 0x8F5355C0680BDFF0ULL, 0x2260C4C9096B4511ULL, 
            0xD81E629CE7CBFD7EULL, 0xB877567ED78E02D3ULL, 0x21E3DA801D73B939ULL, 0xEF289455B5C6FC0FULL, 
            0xCD22BD528C5CD339ULL, 0x83B1641FF6187D8AULL, 0x242878AD27DA992FULL, 0xA707C658936D0F67ULL, 
            0x39A1AFC5D94F9A16ULL, 0xA5E2B5C5B7B1A5DCULL, 0xD5252FCBADC00CC9ULL, 0xF4730A7E461D5D17ULL, 
            0x8213E505912AF8FAULL, 0xB95FF81F3799E25FULL, 0x77D4F84E9880CD23ULL, 0xA75AEBA7AEB90F4DULL, 
            0xB4D4275C75E9007DULL, 0xEA41A9670AF7E216ULL, 0xB606D95584E6B90EULL, 0xC4D9E60FDBC92456ULL, 
            0x7362D35EE1F44633ULL, 0x2D0FC2349CE16EFAULL, 0x24BC42AE315543C5ULL, 0x59D1AAA68C443EDCULL
        },
        {
            0x1D4DD6789A2F0252ULL, 0x167BEB61CDEEE753ULL, 0x00DD5741F49631C5ULL, 0xB10844CBA10223FFULL, 
            0x3877E46150E97A7BULL, 0x17C8E0847A334A4EULL, 0xA0F103192F18D2E6ULL, 0x750A04714D5E0060ULL, 
            0xEF24E8CE6A93E6EDULL, 0x7316DB89F50D065DULL, 0xA9C83BCB48152121ULL, 0xCCADBC86FEE6EB38ULL, 
            0x3C03175746B5E3BBULL, 0x929633AA7CE0A8C1ULL, 0xF839B19A107C66DFULL, 0xA7BB3D8801505330ULL, 
            0x6C3B019B09CEC249ULL, 0xB77943117BE95D50ULL, 0x61ABC983E203C55DULL, 0xCD2CE78A7EC175D9ULL, 
            0xAEB107F52A5A6D7AULL, 0xA0E72DFF3DDDAB71ULL, 0xE301D360D33F9536ULL, 0xC1F688DD372B4615ULL, 
            0xB9CBBF76085E671AULL, 0x38FE0C3F3836C691ULL, 0xA80CC56D5888757FULL, 0x69CDC67E479173CFULL, 
            0x5E00506BE553C2E9ULL, 0x195A494FDC391A4CULL, 0x3AC2ECB625A6F92DULL, 0x559D95727F36A789ULL
        },
        {
            0x05019B1C38C3110CULL, 0x105FA1AB3DDCE490ULL, 0x7C373FC6D00D0A7BULL, 0x8B9ED0944D11AB21ULL, 
            0x2C6F611C1CD0DE62ULL, 0x9666EA5B7911691AULL, 0xA7CCBD079AAE419BULL, 0x098A7FB0C18E9F25ULL, 
            0xA4ACFB1DF8157848ULL, 0xF60EE9E9E64E9373ULL, 0x5F969EE4572E5829ULL, 0xEDB2D626B0FF8603ULL, 
            0xB0515FA738D8F657ULL, 0x268593A2B6A9AF7EULL, 0x326808101D8AB34FULL, 0x3FBF88D022F32520ULL, 
            0xBF4C22C363D7CE14ULL, 0x54D5B58032BAED31ULL, 0x9AB9C13779D8F158ULL, 0xF0E3116E3750565DULL, 
            0x35D5AD3FB028EBA2ULL, 0xF7EB181E401C86E2ULL, 0x907ABD513AD0BF9FULL, 0x38C41D505F7134CDULL, 
            0x6EE1A2089A6AB3F0ULL, 0x01F1968360094A88ULL, 0x3CD48265DF9EC82DULL, 0x71768AB692830A2DULL, 
            0xCDEB047702C228D8ULL, 0xC3B357A7C18DA191ULL, 0xE891ECD5028BC192ULL, 0x54446244DB388081ULL
        },
        {
            0xAC8C96C6C89FF78DULL, 0xBE4CCD0789E5F63BULL, 0x69F5D91EA17D6957ULL, 0x20E1BAD1DB159323ULL, 
            0x5144B698C77ECCE6ULL, 0xDF80D1B237D1DA7BULL, 0x0A18CE681AC4E0B5ULL, 0x5434178993E1818DULL, 
            0x954BF26C612A9A1AULL, 0x369756B1320FD5F5ULL, 0xE286EEC459100194ULL, 0x4C57498C42F8F15BULL, 
            0xB0DEF13FF1A108E3ULL, 0x4EA03142AE75BFF7ULL, 0x0F727D601B3D3B5EULL, 0x4B9AD63EA9F33CBAULL, 
            0x0460B8980D955250ULL, 0x740D5968CE486869ULL, 0x91CFEA8E42108E24ULL, 0x3A17C414DB10A870ULL, 
            0x9EEDBE3E46D83BB5ULL, 0xA7A27ED23BEFAB7AULL, 0x7A60E17C000D625CULL, 0xE6FFA9F006BACCF4ULL, 
            0x3939F1EC9EC8EC46ULL, 0x9DAFF76AA5289790ULL, 0x18F30D3AF6406AE4ULL, 0x2F17404E1840897CULL, 
            0x14BD26E91AF77C37ULL, 0xBF1FF56A3A9AE5F0ULL, 0x07D701F857FAD088ULL, 0x2292E5B3E1D14F2FULL
        },
        {
            0x853E901D86F66581ULL, 0x409A541EB2A51B74ULL, 0x5297A9A80E02B908ULL, 0xEB9DE636AA2C240DULL, 
            0x4C8C023A6E21AB4AULL, 0xD1F580F24E0CBD24ULL, 0xF9906D1A4BCE6F45ULL, 0x105C2FCD1785E142ULL, 
            0xC5F061925F13F479ULL, 0x7F0EF4A195A4FA68ULL, 0x065DEB52EB99E74BULL, 0x77F302B47A8E3206ULL, 
            0x65C90EB80DA463D9ULL, 0x698174939E8DDFA7ULL, 0x89436144E888B705ULL, 0xBC1AD08284168CFCULL, 
            0x6B9E54CD0C80F59BULL, 0x963DE2D8FDF79DCDULL, 0x5CDBC032DA4C769FULL, 0x9DC9B22D040A6374ULL, 
            0x294ACC64F38F14F9ULL, 0x442AF48492FE72CFULL, 0x0399EA663E156755ULL, 0x03A21FE95C646DCEULL, 
            0xAF00CAED93B45E91ULL, 0xFAA207F29CACCEDEULL, 0xBD4E58D3FB34342DULL, 0xF291B2C8A85EB42DULL, 
            0x12F92214BCDADCF9ULL, 0x867DC58934ECA3A4ULL, 0x7CB3D074697504DEULL, 0x972A47087C174AAEULL
        }
    },
    {
        {
            0xDD59D17036F46562ULL, 0xF01282FB936C5D1DULL, 0xFB51DF798DB66384ULL, 0x0DD5FA0B57D59B87ULL, 
            0x57E75AE974548537ULL, 0x89A7BFC38CFCE99CULL, 0x458E15EEE73EE104ULL, 0x6C6922DA5E8EE7B5ULL, 
            0xC07709CD8520E45DULL, 0xB35892872969A2F8ULL, 0xFDB431FA3D5A2AB8ULL, 0xEB22BEEA40791140ULL, 
            0x1E1A12A29256D14BULL, 0x921041263B6A86B8ULL, 0x03B862474F67F777ULL, 0x392C7E6578889633ULL, 
            0xE8D42E29BD5099DEULL, 0x0C05A3F28B582D0BULL, 0x4D9C66A739C98DF4ULL, 0x7724014557B28045ULL, 
            0x11937AEB1FBC8B9FULL, 0x05DC44061B559A64ULL, 0x80E1C6B410CC3E37ULL, 0x22BD5E842924B056ULL, 
            0xD4E5E3A5F96F4D83ULL, 0xCF3DC01FABD3B8D6ULL, 0xDD64F9A2DECAB616ULL, 0x02758FB10E2A32EFULL, 
            0xB13E4590AA487382ULL, 0x04FEBB3E68DAE707ULL, 0xCE8EE810C06A73C9ULL, 0x3F631CAF95016CCBULL
        },
        {
            0x7095BEE1BD2193D6ULL, 0xDE0A665947AC93C0ULL, 0x7CE9F0A7C6104543ULL, 0x14EBA5A02F82E4FCULL, 
            0x021970965E414EE1ULL, 0x903289D3C456D67DULL, 0x0CC2C6F48FCF4A6AULL, 0xA0C02672729630C2ULL, 
            0x8A68C9A9387E28E2ULL, 0x9266A30093526E34ULL, 0x88F8A02336A94DF0ULL, 0x100DC33FE101ABA4ULL, 
            0x34CB66E527D881E1ULL, 0x49F02D404F2F790AULL, 0xF414D59CCF9C424AULL, 0x0FDF77C516A5C473ULL, 
            0x672029C96E6D0142ULL, 0x7BB5DCF707FA354BULL, 0x905804EB5AFC433AULL, 0xD69335FB120385BDULL, 
            0x74C9637F668140BCULL, 0x658C7DFE20AFCE98ULL, 0x00FB0E9B2F0F3CD0ULL, 0x2DE214B034DCE001ULL, 
            0xC7D172E50AD45414ULL, 0x86367640F40134CFULL, 0x21DEC70782C80C3EULL, 0x1F2AB93C9D2E785BULL, 
            0x461455257D04D0C7ULL, 0xDAECCC0672EB1931ULL, 0xF9C619897B41C8BAULL, 0x3CB8DA869229D0A0ULL
        },
        {
            0x5417EA570E4A846CULL, 0xB9F5C6B024F17308ULL, 0x74931C2A133AB509ULL, 0x9068FEFAF4C4383AULL, 
            0xF82AE62C372F722DULL, 0xED897216F4708294ULL, 0x6DF3E7DBB8F216C4ULL, 0x515271D345DF4F28ULL, 
            0x53FE097C1D39F459ULL, 0x44C25343525A9D36ULL, 0x2AC12A6792DF44B1ULL, 0x2430B07F3AA4F073ULL, 
            0x6FB460F6F148666BULL, 0xD17705CCC660618CULL, 0xDB379AD5186084D7ULL, 0xB27119342E5E2FD5ULL, 
            0xF12834F99EED16C2ULL, 0x32C29C8812DF8982ULL, 0x4CBA2B463D17FB7AULL, 0x96FA42F48D1C5A53ULL, 
            0x47B5FF15D689AAEBULL, 0x3151D3AF217B3170ULL, 0x7460E7A2B93A0E16ULL, 0x8B52A88DDFBF3BAEULL, 
            0xA606D5C4CF6BF52BULL, 0x7965D42D920B9AB1ULL, 0x289548B1585F3395ULL, 0xD2BEE4AD683B9B21ULL, 
            0x60323C7280CDD3C5ULL, 0x2AD718B406963085ULL, 0x75FCD07E51BF963DULL, 0xBF84E68E5189F5D0ULL
        },
        {
            0x116D3B9E871DBFFDULL, 0x86C26414BB63BD7AULL, 0x5760E56524457089ULL, 0xAA9F177799ED08A8ULL, 
            0xFF0635A0186AB9ACULL, 0xABC8C7FC7FA9DB74ULL, 0x4DD04170AE3AA2B7ULL, 0x7AAEF37B6523BC05ULL, 
            0x1C153B15CF56AC43ULL, 0x37227B107A4E6571ULL, 0xA4B67C5ADC849AF8ULL, 0x51FA9C01772A8910ULL, 
            0x81ECB2D754629B5FULL, 0xE73031948AC8B852ULL, 0x34A0CE743D6E9164ULL, 0xABC8AE5A97B78E29ULL, 
            0x3122F8539B02CE3CULL, 0xBB0EE56D18C8CF80ULL, 0x62F31AAEAD080C66ULL, 0xF3C47F6317163CB7ULL, 
            0xFFF770C533C6E342ULL, 0xAE778F146F9D4614ULL, 0x6F746EA363B2D9D6ULL, 0x42D1B8E10C3F4BAAULL, 
            0x68918D5EAE7CB6DDULL, 0x552ECD030ADD8091ULL, 0x9453CC52FC726349ULL, 0xA8AAB891020C6CECULL, 
            0x6ED0230ADCB1EC17ULL, 0xA120927292ED2FC2ULL, 0x000EFC932B3AF77CULL, 0x3CC17C6D9C152F8BULL
        },
        {
            0x0249FBDC05F4CD33ULL, 0xA2BE52ECA7D36437ULL, 0x22F38A579F5A02EEULL, 0x4E6580E9F656126EULL, 
            0xCA22EFF22CBEEB82ULL, 0x1BBB7897127F5842ULL, 0x8373F752039702A5ULL, 0x14D5A2357F665935ULL, 
            0x101F6AE871E899EBULL, 0x3FD9DF082FE5A2A5ULL, 0x5462255E4F3CDA0FULL, 0xE79F39A50BEBB106ULL, 
            0x5B642D7BB154051DULL, 0x0BF64623B8E8639BULL, 0x6933D886834FA911ULL, 0xD14F7F85B1898BE1ULL, 
            0x761AA351B92A6BD5ULL, 0xBD57A0C428F76680ULL, 0x52463491064603F1ULL, 0xD479752FAF66ABCEULL, 
            0x6E238BC71E44D0F0ULL, 0xCF082DD46C2D1013ULL, 0xD2176FC2DEBC9E44ULL, 0xFC067E8E81CC8DF3ULL, 
            0x6ECB81B750385F69ULL, 0xB559C91B7C4ACCEBULL, 0xB5AF13A1D62BFE3BULL, 0x603765F44F6C5BC7ULL, 
            0xF1C5D73CF07B17D6ULL, 0x3AAE0F95970EB3E0ULL, 0x0A45FE2EB75B7F75ULL, 0x0DE8B0FB4DD6020DULL
        },
        {
            0x1ABAA713EF79048BULL, 0x4A7E8CBE85E2E850ULL, 0x3F0CCC053EEC46FFULL, 0x60FA912383A36101ULL, 
            0xA334C9F59A48F2CCULL, 0xC3C70D4CA900A57DULL, 0xE817F3BDB122E103ULL, 0x2FB79DC9FB1EB2FBULL, 
            0x5F99AFC368367833ULL, 0x02A364C9518838EAULL, 0x90A0E7C996F31566ULL, 0x471C1F0A31920016ULL, 
            0x29E2B3814A9024F1ULL, 0x6563EC9B5D406D4DULL, 0x389725AFE0D2AE41ULL, 0x67B2CADFC28B2E76ULL, 
            0xBF56A6A8448A1047ULL, 0xD0510813AAC4DFCEULL, 0x06EF14C6557278E8ULL, 0x9EC7A161CE6AD170ULL, 
            0xC940E4930CADF4AAULL, 0xC529EA7794948E19ULL, 0xB70F9F4365FA9E50ULL, 0x197E94DACFF74B2FULL, 
            0x47866B83754F47D0ULL, 0x803321222CE4D8EDULL, 0xA9F09CDDA5173EE1ULL, 0x1BE057D2F3E76A10ULL, 
            0xD3D0FA3B8FAD1EEEULL, 0x1A7B5D43F4A0054BULL, 0xB5F879CB6A627AEBULL, 0xBBCE12405F467471ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseAConstants = {
    0xB5C733477FD8D7DAULL,
    0x005AA8DD1BB7AE7FULL,
    0xBD25824C052FAE7AULL,
    0xB5C733477FD8D7DAULL,
    0x005AA8DD1BB7AE7FULL,
    0xBD25824C052FAE7AULL,
    0xBEEF9ABDD7F4E8FFULL,
    0xF2EDD770CB0CE5E1ULL,
    0xAF,
    0xDB,
    0x24,
    0x33,
    0x50,
    0x3D,
    0xEF,
    0x52
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseBSalts = {
    {
        {
            0xE074121374008A8DULL, 0x390BD79617335FB2ULL, 0x0646E2F00D368F87ULL, 0x7EC7CCF8A29F5FCBULL, 
            0x95D6CBF12A8704DCULL, 0x43008F3169F4168DULL, 0xC4310079249445C5ULL, 0xC2245B98516B5232ULL, 
            0x4D50F4A9A966C2A7ULL, 0x699F159F4769B665ULL, 0xAE26B5B9D15FCC36ULL, 0x940B95F83B28E9E4ULL, 
            0x78233971C8A0AA39ULL, 0xAA6BDDBED36AB9ABULL, 0xE1AFE22BE156BD78ULL, 0xAF18E09E44FD5640ULL, 
            0x8AE53AA5EC5F5509ULL, 0x3BC00F3398F0D7B5ULL, 0xFB6D873C421EFEB0ULL, 0x711CE736AA31BF8CULL, 
            0xDA4ACE24B063B6C7ULL, 0x87DD57CD0621AB6EULL, 0x5C3F9E495F8673A7ULL, 0xFEC6986EBDA69BC1ULL, 
            0xA4657356533FFE05ULL, 0x1C517EB8656F4878ULL, 0xC2A8364756BE5EB6ULL, 0xD5BFE4AF7ECB460EULL, 
            0x893348F6E63DB871ULL, 0xF7F6146FF038EFE1ULL, 0xD9307754D83A586AULL, 0xA76A6E41E1E31B67ULL
        },
        {
            0xD639D4B834105E46ULL, 0x0730DCA19982E377ULL, 0x893933E61B620501ULL, 0x46F983DA1C6ABCBCULL, 
            0x99C384E6D2489943ULL, 0xCF773598DD9A3554ULL, 0x1470D2A74E866D75ULL, 0x43D2DF0233447C8BULL, 
            0x06FBDDE3AFF98C56ULL, 0xA878A0F8FF887353ULL, 0x977A2F6AA1DE41CFULL, 0xB5E28EA05718B934ULL, 
            0x5FA746D1E178BC3CULL, 0x08A9D934C1B893C1ULL, 0xD61753A89F5ADBF2ULL, 0x0020B063FC3A6059ULL, 
            0x5E37208A94378691ULL, 0xDD01E3E13270F5A4ULL, 0x28385B1FEBA08F76ULL, 0x6F982402C934C9FEULL, 
            0xB44CBBF305084150ULL, 0x84F1B3E3880B7D93ULL, 0x1E08B06BC13E20C4ULL, 0x2AEB5DD6D4EDD7CAULL, 
            0x6673A7F2C6BD5D73ULL, 0x705B0F20FF1078EAULL, 0xAB365DA924E20D17ULL, 0x5377160BC771153FULL, 
            0xF88ECDE2E9FA25F1ULL, 0x8FE9788B00FB2707ULL, 0xE9E6C09B04463895ULL, 0x1FA74D3885858C98ULL
        },
        {
            0xAD3F0930AF882C17ULL, 0x897BC39CA0F9534DULL, 0x8FBF772C007F408EULL, 0x881419C6D16F15ECULL, 
            0xC988AA295246EEDBULL, 0x754FEB05875A3187ULL, 0xB768095C13B5B9B1ULL, 0xD99A0034A41C08BEULL, 
            0x1A69A4A1154BA0BCULL, 0x239D18663B9287CEULL, 0x543030E0CF629393ULL, 0x1152088781C14FEAULL, 
            0xC9A39E09893DF06BULL, 0x2E5D86B6704E2686ULL, 0xB2BBAF47014D0D3AULL, 0xE0CF30ED111C347CULL, 
            0x67FF2F4839980CBBULL, 0x19FC9700036313FAULL, 0xCB783D9A901EC835ULL, 0x0DBDCD619F79F891ULL, 
            0xC7D83F97E06C2367ULL, 0xE24D96A2FA42D971ULL, 0xB894142C2391C468ULL, 0x9FA8C3948DC9CA93ULL, 
            0xACBD4F0057F9D185ULL, 0x821781DD9853829DULL, 0xF7F3D207BDF641DFULL, 0xB0144BC20108C44CULL, 
            0xF63BED484FF7AF8AULL, 0xC27077D0237CE46CULL, 0xDA5E715F38F030B1ULL, 0x7F1564D0A29F7440ULL
        },
        {
            0xD1D0ADB66D6070C5ULL, 0x1AF886FAD0DDDBE0ULL, 0x951A0CF7A4D23B5CULL, 0x76E8A1BB0B73ECCAULL, 
            0xDB6DE6062385D6E9ULL, 0xF1892A4B7B87D76FULL, 0xAE0924F01C863E62ULL, 0xEB058508C65E8CACULL, 
            0x2FEC655676F223A5ULL, 0xACD47322A410B368ULL, 0x57FA525C381DCF5FULL, 0xEB0DABD27DC34BEDULL, 
            0x28387955C74B12D2ULL, 0xC3F946EFAF3CA5B1ULL, 0x7393830123BD97C2ULL, 0x21877C366875001BULL, 
            0xC1480F52BD04B8D0ULL, 0xBF19A88645722B5FULL, 0x0FF937CF25A698F5ULL, 0xE621C652B099C601ULL, 
            0xD9D2E1E00E782D69ULL, 0xC11045E95D2A0618ULL, 0xA32FA26409B61C8EULL, 0x416A6438E20D6DD6ULL, 
            0x4D85258F304F0AC2ULL, 0x3E467B388170B517ULL, 0x1E0AC28752AD7AB9ULL, 0x76C81A9FA71D40AFULL, 
            0x7BA447CFCDABD9DAULL, 0x7C5E08DB3694765AULL, 0xFDBE1738BAF12846ULL, 0x835DB64A85CA1D0BULL
        },
        {
            0x6CE8F2C90A86DBB2ULL, 0x59BBE07B3985BB5BULL, 0x8CB7D85FB4DBD6EBULL, 0xD6F0594BD818ACADULL, 
            0x2000DF22BE5ADBFFULL, 0x41AF58EDCA32CE33ULL, 0xE3EE1D355C72D808ULL, 0xB5E2BBDE4A58EF9FULL, 
            0x819C4A7C9B9AA8CAULL, 0x37A5717AC89E12BDULL, 0xBB8FE01B0AB65C8BULL, 0x158CC1396A16B1B7ULL, 
            0xCD9C8D265F5E720BULL, 0x19BA910FC1E67F0BULL, 0x09D52488FD4E0FDEULL, 0x1B454E9F932270AAULL, 
            0xFA95451A22CBC252ULL, 0x4088611427629BA1ULL, 0x7B709AF598CF6FB1ULL, 0xBCAF177EB1960E19ULL, 
            0xBC6489C78F928F92ULL, 0x1B2D8F030B6F63E9ULL, 0x63ECDF7E25F5571FULL, 0x51A6F87E29EDD6CCULL, 
            0x3C705138D5E077A5ULL, 0x2F605A7B7EA7D441ULL, 0x8A14EE26408C64F4ULL, 0x95CED55652B21330ULL, 
            0x1CECF65642658A74ULL, 0x44728195AC2D5955ULL, 0xD4CB11F40DF16B91ULL, 0x5475CB80C4C9A1F7ULL
        },
        {
            0x5F950D1856FC66F1ULL, 0x7F3E588790090AABULL, 0x984B19DFDBB8B23DULL, 0x3648EF2A8F51AA93ULL, 
            0x3EF6FE98B845D735ULL, 0x7D3E1C4363E5B8F2ULL, 0x4E01226E405D0B4EULL, 0x9AC119DBB07167B3ULL, 
            0xD7473C685900ED9BULL, 0xA733CAF07C9258BCULL, 0x181234F42D2672FCULL, 0xF83781ACF2C54432ULL, 
            0xB2A90321FAEE6C0BULL, 0x28BCEFF37050A145ULL, 0xF64D2A42E0935DDEULL, 0x7FC7FB658B0478FBULL, 
            0x25FC2842E9299E0DULL, 0x9FB1EA212F81053FULL, 0x89DDDB7C0AFF7640ULL, 0x7F40BF8502D91318ULL, 
            0xC6A3C551D8DA3171ULL, 0x1EEC8083A122908DULL, 0x4264979336873BC2ULL, 0x85AC7806A6E218B7ULL, 
            0x5214254F61991A83ULL, 0x989A4399DD938C30ULL, 0x8FAAA039B764A778ULL, 0x55BD51FAA5B633F6ULL, 
            0x3963FC34442F4A29ULL, 0x87EF2AD6DAFF4965ULL, 0x6D42F89311ADD4E7ULL, 0xC6EFD38EB27E3DE1ULL
        }
    },
    {
        {
            0x2BDFFDDA981D1B9BULL, 0x2C850E01F39805C7ULL, 0x8F1FCEAFFC2E81D2ULL, 0xFE5DE20050B7BC1CULL, 
            0xC25BBAB40D725AECULL, 0x28DACFF46B924761ULL, 0x92A129D7C27B4B95ULL, 0x801E85CD1200AA6EULL, 
            0xBE6196E341C680BBULL, 0x680718F835D7156AULL, 0xD46CA078A0FDEAB2ULL, 0x663832644B71760DULL, 
            0x839A129B8FF33EBFULL, 0x939CB22207BBA214ULL, 0x3C30224E777C3FF0ULL, 0x1EFD4387CC95CC27ULL, 
            0x05994A3565CE3A94ULL, 0x114B4A30D91A8155ULL, 0x99012BBD0D679EB6ULL, 0x9F6AEF8AE677B7EBULL, 
            0x0D06983867463061ULL, 0x308B24DE766598A7ULL, 0xD7ED3275C13267E1ULL, 0xC46E03C776D02D4CULL, 
            0xEDE04456B7DD1A8FULL, 0xFCBD4C95800DD808ULL, 0x1ABC4AC0A043607DULL, 0xA01C64D098E9FB5CULL, 
            0xA55F3D6BEA954936ULL, 0xDE88EFDB14B63C50ULL, 0xC459C12E881DC2C3ULL, 0x98032E397030C105ULL
        },
        {
            0x5C2DEB27D8F2547EULL, 0x9C4AE549FD3874C2ULL, 0x403A47400530727BULL, 0x268B11359845424BULL, 
            0x1E87251DF4067876ULL, 0x780000AB0D12DC45ULL, 0xF5578AF62C24ECA3ULL, 0xFC6BF43B1512E0EEULL, 
            0xBC7A2BCC2FF0690DULL, 0x3884688F4FB8C0D2ULL, 0x4851D9E8917AE358ULL, 0xC5497A8BB14BD90DULL, 
            0xC542C489CB84C5D8ULL, 0xEC6EA5E51C3060F5ULL, 0xE00C7B0FEF1F8A4EULL, 0x75D965D616148756ULL, 
            0x118EBFE421E09A9AULL, 0x47DE831288BBAECFULL, 0xB6D54655B0F23D47ULL, 0xB59BC17C32C0D807ULL, 
            0x1BE372D07F1B763CULL, 0x3B4C9A1D9A1D3CC2ULL, 0x616B0B45F6A876D3ULL, 0xEFB31B08C3486331ULL, 
            0x153F4B3BB2E72A1FULL, 0xD7628EF9332F6ABCULL, 0xB3CF8575C8E47FFBULL, 0x2672A3BC86EB9CC5ULL, 
            0x2DEF9F81B6C3DADCULL, 0xD7B0F726C2541781ULL, 0x715A8797BF51415CULL, 0xFCDBD52F7DB0C835ULL
        },
        {
            0x99F2AADC96DC1C0EULL, 0x5F6B2BC1985BCFC5ULL, 0xDF6BF783015BA467ULL, 0xAB2BD429BAB2380DULL, 
            0xC8E7195D7A8DE082ULL, 0xC1954FF83F48224EULL, 0x10A707C2076A1ECBULL, 0x1772557AA681B1AAULL, 
            0x62E5EFE50F371940ULL, 0xF4FF0C5CB551C009ULL, 0x2BFF4B5A2090884FULL, 0x97BD406071716240ULL, 
            0x656266D327618BD5ULL, 0xC55D1E93F133664EULL, 0xA51401B353CF8FE8ULL, 0x50FE1FB57216DBB7ULL, 
            0xCAC7D8BCE788E2A9ULL, 0x56C3629E54B3D741ULL, 0x4AA97C10736894CAULL, 0xDF3C1DC9DCB9E282ULL, 
            0xFFFF4DB1699C7CABULL, 0x8F7997997314C087ULL, 0x90D8D97439599AB4ULL, 0x5B7089553697E6C4ULL, 
            0x99A64307F4FDE1E1ULL, 0x42D53782EA0B0F38ULL, 0x8CDF135D761789DDULL, 0xFB28C38052CC41B2ULL, 
            0x23C419EE1EEA4C8FULL, 0x744CEDF162A73231ULL, 0xD9B7B150F6D11A16ULL, 0x5D621ACB6ADBBB5EULL
        },
        {
            0x21937E04044C7147ULL, 0xD8CD75B265CE646FULL, 0x8D82E5D974F7FF13ULL, 0x4DCFC47D71C0FA2CULL, 
            0xDAFC0C323AD33D01ULL, 0x421F41970D3F77DDULL, 0x602A37FF8B19AE11ULL, 0x68DA9EFDEEBADF15ULL, 
            0x8F52D01995C64F9FULL, 0x7F3ADE6967CA26DFULL, 0xC6F6CFB56A2FEC9FULL, 0xFEE35A9CA884C44BULL, 
            0xE9125300B468ECF8ULL, 0x0791FEC49D4B2F3AULL, 0xE561A1FE13654845ULL, 0x995F60AE1F153840ULL, 
            0x274FC5A31981742BULL, 0x86CACD8E89C43A79ULL, 0xF3DEC0132FC6A773ULL, 0x68D2757935CC5DD4ULL, 
            0x220C36FCC4F5B705ULL, 0xC5FEBDFBCF5E0B83ULL, 0x111F90849B84CB1DULL, 0x9230CE1DCA038741ULL, 
            0x675A86F4FD7E367DULL, 0x5F29DBBEC91829FDULL, 0x0F887F24015F7FEDULL, 0xC87B44D256CB8A84ULL, 
            0x5F382B207AB69BA5ULL, 0x536B6D303075D125ULL, 0x4B1F77687AE75D6BULL, 0x4C40AB371627F844ULL
        },
        {
            0x818AA79B8FF6255DULL, 0xE12ACFD32EE91791ULL, 0xF915D42D7CE79721ULL, 0x3109886B5DA8BD7FULL, 
            0x588760FADAD68FADULL, 0xCB49EE44D48393A9ULL, 0xF6CAE6B6D2518CB1ULL, 0x99ACE49365DBED65ULL, 
            0x7F8182848BC343A0ULL, 0x1E07E88EBE22F814ULL, 0xD6CA532B00E57F75ULL, 0xEB37751374451C49ULL, 
            0x192DA1FCE347B969ULL, 0x15BDB8BC270FFDAAULL, 0xF806A5B05662E781ULL, 0x00B3B0AF3BA3B525ULL, 
            0x4076A601B8021108ULL, 0xB1F3C314429D0404ULL, 0xBBCC980B7F29E47FULL, 0x5836612E10103BE2ULL, 
            0x63CC0D611C112017ULL, 0x101C5A7AE2C5C1ABULL, 0xEE5508DF0E3C9CE7ULL, 0x8905321AA5AFF1E4ULL, 
            0xE7169EE3BC1F60C8ULL, 0x0EBD399C9DD6C0DAULL, 0xFD28D3945BE48F99ULL, 0x44BE1E8574F26F9BULL, 
            0xC8BF80ADB131ED49ULL, 0xB93C02C3635FE917ULL, 0x9853E90A99EC97C3ULL, 0x1FB8118A9669AD5DULL
        },
        {
            0x641B5A355D816E8BULL, 0x0CF731E3E55C68D4ULL, 0x81A71169E761071AULL, 0x2545622F8C228977ULL, 
            0xE8753D6EEA37E599ULL, 0xE3C2B71DEEDB2483ULL, 0x3E9FB8B46B080D52ULL, 0x1B81A64CF39FDFBCULL, 
            0x4D8F236B211E5B8AULL, 0x1EB30C43F5E48ADDULL, 0xEBAA67EB7D6B98E9ULL, 0x5BBE54604C05E20BULL, 
            0x3F2DC217D68052F2ULL, 0xEEE6B4B487D8DAD4ULL, 0xCA6E83E9EE1D3976ULL, 0xD832A693C43F9C8CULL, 
            0xC416967B8DECE99AULL, 0x0BDF6C5BB7A600A4ULL, 0x61D107BC07AAED87ULL, 0x8EA2BEB1224D4971ULL, 
            0x64BC1D259D4ED3AFULL, 0xB724E9E5D13805F1ULL, 0x4E19B849A5FEEE96ULL, 0x4B6925A20C49E80AULL, 
            0xACE3B829CB332DFFULL, 0x7A758A4D09701D8AULL, 0x04160D3225138515ULL, 0xB151E8887C8F1271ULL, 
            0x984CF87E7059F258ULL, 0x19029EC4C0F30A46ULL, 0x43FCB0BB97B0F12EULL, 0xB91A388E4BBEDB36ULL
        }
    },
    {
        {
            0xBEB075B5E0A51B10ULL, 0x28B1FC6F6712CF64ULL, 0x8F43FEF9BBC581BEULL, 0x971B9CD4488B1239ULL, 
            0x9E1597D9C1E9F6B8ULL, 0xCCB5BCD6EDD5D7F2ULL, 0x7649841FC4B87710ULL, 0xC7629A24C72DD8BCULL, 
            0x0B9A46F57FDC395FULL, 0xFCD8F0ED51866EB8ULL, 0x7ADF502325014B67ULL, 0x791E87F072740EA5ULL, 
            0xA209D6FEFE63E21CULL, 0xCB0EB83023927E40ULL, 0x67F93B49BDE1A9A4ULL, 0x692F424958D6F5F2ULL, 
            0x1EDBA3BAC9BF88D4ULL, 0x742E4136F4CAE1A8ULL, 0x7C34E24641F55C82ULL, 0xDF88808CD3FA808DULL, 
            0xABB296C1A0E51A47ULL, 0x10D4144BC3779EF1ULL, 0x2154F7022DF118F3ULL, 0xA691B8B5E2B2F4FEULL, 
            0x20E678DBA4102EE7ULL, 0x4E47266AD6C08DBAULL, 0x2F7010134E3BB0CEULL, 0xB0CC0847D0511A70ULL, 
            0x45EBF33BD2ACE577ULL, 0xCA1C4466AD6EDF42ULL, 0x22CBDC0508BCA6D3ULL, 0x804803FA2E0FC766ULL
        },
        {
            0x671D06ADDD7B9AE8ULL, 0x2D0542B1DEE4F888ULL, 0xBAB655EC15F80AF8ULL, 0xCAD6EFB8BFCF3EC2ULL, 
            0xCDA325E985B15416ULL, 0xE6A36C781C2C8984ULL, 0x78A9CE060D3E57C9ULL, 0xB49184AC19343E9FULL, 
            0xBE8B24013E5A8DEAULL, 0xC54757A260BAF7B9ULL, 0xCA70ACEA76064F9AULL, 0xE4202B383F2AF37FULL, 
            0x5F35E976BE9C78B0ULL, 0x7A7A5EB5FB6D91B0ULL, 0x08A06005828867F2ULL, 0x4776C94906A16AFCULL, 
            0x5C1A912A01446309ULL, 0x6235C1F597453B48ULL, 0x722B2EA4BE4B2692ULL, 0x401AB366622F7FF9ULL, 
            0xCFA5F8DBB224E50AULL, 0x2A20E703ECFB7B08ULL, 0xAB1D2F78655E81DCULL, 0x9A4B302E8A9AD93AULL, 
            0xA0AE39C7206ED733ULL, 0x6115E0A96B8D885EULL, 0x26E89926B40A7788ULL, 0x90052660F1AF8BDAULL, 
            0x3AFCA4B5E1250DAAULL, 0x5D33BDF2656810B5ULL, 0x12C9306C3BD13D03ULL, 0xFB27680BB7264330ULL
        },
        {
            0x2CF1EB417324F5C3ULL, 0xC679D1005A0745A9ULL, 0xA58F416109457E04ULL, 0xD496A90D0A6C7B4BULL, 
            0xE61D4EB68E46C3B6ULL, 0xBE391A6D0BD77580ULL, 0x3B187D624BB5C7FFULL, 0x597B3C532BCFA9EAULL, 
            0x172DC7FE351E05F6ULL, 0x28243D9201C43092ULL, 0x724A239258F5F710ULL, 0x83CAC24D47E50012ULL, 
            0x087BE02FB55D8EDCULL, 0x9187FF74F97E0858ULL, 0x28040021F4635293ULL, 0x1C918B8836AEC97FULL, 
            0x669D7EA6DEC518D0ULL, 0xD2CBE25AA0D36338ULL, 0x0A1CF57810A96A25ULL, 0x3D4026FDA0A7D663ULL, 
            0x0D1031698564D86AULL, 0x4BC855EBDED9CD67ULL, 0xA7C124CC71DF0F68ULL, 0xD553836E1E2BA49EULL, 
            0xED9175FBABA922BAULL, 0x0A4D4B0A7542A38CULL, 0x38A00E550BA0404AULL, 0xD78581293B61ADD3ULL, 
            0xB61F01EA02A82CA3ULL, 0x4D30F7A51F120985ULL, 0x6039DF60209FD18AULL, 0x3AC95D7504246902ULL
        },
        {
            0x0B4870308AD1469AULL, 0xCB8DDD8D2C710E6DULL, 0xC339B903AD68521FULL, 0xF6252C463FD35496ULL, 
            0xBA4DBBB042084B16ULL, 0x21CF4339A03B3454ULL, 0xD780338E1C1ADAE1ULL, 0xD5EA2E8E9698957BULL, 
            0xEF2B246FB85D1704ULL, 0xE531C416671113CAULL, 0xDC3DE31240DAAF54ULL, 0xC6407E013903391BULL, 
            0x7B5FBBB25A3026C3ULL, 0xB333AF8313667EA0ULL, 0x196E5B695F96BC08ULL, 0xA604970AD6B4F0B4ULL, 
            0x124E3DAE8A370E6DULL, 0xE5155963B98DCE97ULL, 0x2B4AD759D7B032C8ULL, 0x5463162E755BED8DULL, 
            0x5475C5EF74725933ULL, 0x94119BE36D85DC8EULL, 0x6ACDAFCD6FC7FF2DULL, 0x707B0B83AF727D63ULL, 
            0x81641E048B68543CULL, 0x7A11714CC0D59AB2ULL, 0x28164033519CD83AULL, 0x5D815EFFDC5CE464ULL, 
            0x859E17340F50B1E4ULL, 0xFC23D4CEBA1B8645ULL, 0xB3EC51B1BB62A797ULL, 0xD06269DF5CE9C823ULL
        },
        {
            0x76F97D37984850BFULL, 0x41DA112E74424232ULL, 0x603DD40F035760F2ULL, 0xDF30CA1485A68FDDULL, 
            0xC3BB908FA4242F52ULL, 0x9E7998384316EF47ULL, 0x568DB3CFA4D78125ULL, 0x45201E8C805C660DULL, 
            0xDE0CC395C04CF653ULL, 0x0BCA95610C9AEB47ULL, 0xFDF9187EC7383969ULL, 0x1E6548C0DA55480EULL, 
            0x2F27D53DB784595FULL, 0xC719952DED7EB159ULL, 0x18E4A57BBBBF8F32ULL, 0x6E77E8891451490DULL, 
            0x1B8C3960B794B6DEULL, 0xA1EC6586FE51D727ULL, 0x07D649D2DC0EEF19ULL, 0xA0A8F82C3BC3E9E8ULL, 
            0x4CDB9C8E93D89DD3ULL, 0x24D48ECF4861B77FULL, 0x3B8086E6BEB57A4AULL, 0x7EBA06544EC0011BULL, 
            0x8C347889A62229D9ULL, 0x8A71FEBB387C938BULL, 0xF1CEC5066F23CA65ULL, 0x23BB75DFCC992B17ULL, 
            0x14CB713242E13761ULL, 0xC027A0F4415BDFDCULL, 0x8729283A948AFC37ULL, 0x855CBE2B6B089D8BULL
        },
        {
            0x3F8E6432BD314E13ULL, 0x7BEE86FFD93EB4C2ULL, 0x8BAE154A1C9B94DFULL, 0x164E1F93241F6722ULL, 
            0x48A9A19421CAC604ULL, 0x3707E0111C418D64ULL, 0xBE8B441BDBEE3CF7ULL, 0xFD386EACD7387E6DULL, 
            0x5B6E384A73268E78ULL, 0x7F0EC8B89850160AULL, 0x1EC0B3B7CEB90C56ULL, 0x3EAA0E1ADBBC1E97ULL, 
            0x965AD7EE19BA1D29ULL, 0x23133E23A5CD6C5CULL, 0x5EBEED56B584D568ULL, 0x2CE43AD678827560ULL, 
            0x3BFE7B5C87045317ULL, 0x8C8A1C0695F8CC01ULL, 0x8BBE53888724C4FBULL, 0xC6FA07F078718E09ULL, 
            0x5FA4BBF44F7B6CE1ULL, 0x9ED03B0B118AA0D4ULL, 0x80D99D0716C65F3BULL, 0x3566E2525C7F110BULL, 
            0x44708AFF15A62428ULL, 0xB1B54BEE19EB552AULL, 0x8317606A66D61E04ULL, 0x7EA6DF4F101B815DULL, 
            0xE390D67D26992045ULL, 0x762274070DD383FDULL, 0xFD35D212552EC15AULL, 0x5C0C68191A6BB51CULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseBConstants = {
    0x49FD8AF8E0B6AC62ULL,
    0x71D82B5466902938ULL,
    0x312521E11CABAD32ULL,
    0x49FD8AF8E0B6AC62ULL,
    0x71D82B5466902938ULL,
    0x312521E11CABAD32ULL,
    0x7C2EB4942217B2B0ULL,
    0x47BB721C675C24BAULL,
    0x5A,
    0xBD,
    0x7D,
    0xF6,
    0x3A,
    0x10,
    0x10,
    0x66
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseCSalts = {
    {
        {
            0x288D98DDDB157351ULL, 0x020CB015598EBD21ULL, 0x1B4936E54631862BULL, 0x9D671D853D6C9F4FULL, 
            0x6D0EE08ED964CBF4ULL, 0x93A731D7014C7F7AULL, 0x8E331C64E0289A65ULL, 0x741DF5ABD3A9098CULL, 
            0x3C01A7712C3665D7ULL, 0x81AF794BA9000FC2ULL, 0x553BB0692FE337D0ULL, 0x20C757D22FFE938BULL, 
            0x416B2902C2C4F517ULL, 0xCB541502906C1547ULL, 0x20E35EDB24DE5990ULL, 0xE2E5C2054047CBC0ULL, 
            0xD98DD234E27138B0ULL, 0x2403D766CF2AA8BCULL, 0x5B0E7FB6E23BB373ULL, 0x6268FEB3A5710715ULL, 
            0x6B9C90F13E5E451AULL, 0x687ED91B85B246EDULL, 0x44F1751D168BA2A8ULL, 0x6F5C528612704DC4ULL, 
            0x721978F07C468C08ULL, 0x3782788A1E4EA8F7ULL, 0xB0D5F79DFC20603AULL, 0x8072A41021F38C2FULL, 
            0x57E56F86EAEF4BC5ULL, 0x4B93BFE6B3BA62E2ULL, 0x64004BEE7F5EE837ULL, 0xAFA3AA87ED807B95ULL
        },
        {
            0x13647FCE3E0B47D1ULL, 0x4B4591DF25D4A28DULL, 0x1FED7E5550E71E99ULL, 0xCF5B99F67DE89A00ULL, 
            0xEC1D7FA9CA0551A4ULL, 0x30A50AA89CB499FCULL, 0x4C1C5CCEA6B30A53ULL, 0xF2D0C7DA59150C5AULL, 
            0x8E40078C23246A7DULL, 0x661708C36B0D808EULL, 0xB947D9AF8C1021C3ULL, 0x38FFDAC550BDE3EBULL, 
            0x5F2323FF2C5AD7D9ULL, 0x7CA90CBCC4AD1F32ULL, 0xC58BCD429588C54AULL, 0xC3D658786876370BULL, 
            0x5E5EF136CA5CB15BULL, 0x79C3B3D6FC2F843AULL, 0x1B83E533AD507FD0ULL, 0x91EF2CC700999C13ULL, 
            0x368AF644A3548DAEULL, 0xBED82AC8DE674D34ULL, 0xCCB23F416DFB06F4ULL, 0x2D84484E9E977BCBULL, 
            0x7E8292037706193BULL, 0xFED86D5C465CB18FULL, 0x69D89586D15A9664ULL, 0xDDBE6F73AF6E3263ULL, 
            0x0E1436EA27E73476ULL, 0x34A219AB1E8314F1ULL, 0x812730550960C47BULL, 0x95DFE9BDCB89965AULL
        },
        {
            0xA748CEFE89A242BBULL, 0xFFF97906B060B4B7ULL, 0x098CE7F85E383886ULL, 0xFDD4C6D8291F72A3ULL, 
            0xE4C92C3A1BE19F08ULL, 0x74900E09F32CE96CULL, 0x475C9C7EA8CF6A98ULL, 0x801EBD8FEDD4F7DBULL, 
            0x5129F1C8D431D470ULL, 0x41DF09E539AFACB6ULL, 0x21A103506B019FF3ULL, 0x0ADC34A4E990EA65ULL, 
            0x76EBACDD731AAF99ULL, 0x8D9C5369053277C1ULL, 0x71CEA7B62709D61DULL, 0x7862E842A57ADEA6ULL, 
            0x1E1074F7CE37DEE1ULL, 0xB34390FEC86E9513ULL, 0x19D9891B76D7E2F7ULL, 0x5E1ED8E3348A3787ULL, 
            0xCC9DE3D385EF0D48ULL, 0x2A6B6291FB558F87ULL, 0x3D33CE58EEE32370ULL, 0xD9FE1E1CB0A6A05BULL, 
            0x5D4861BBF7CC600BULL, 0xCE938DB0A24B6F31ULL, 0x6B91EADD360A4DCBULL, 0x17E6089182589084ULL, 
            0x185B302BE92CCAE3ULL, 0x88344ABBFC5D397BULL, 0x42BB5BBB19A066DAULL, 0xF95DAF1795835FCBULL
        },
        {
            0xAE985337AB969FF0ULL, 0xD5861A97634DBDE8ULL, 0xF0A33801307EE333ULL, 0x25E181922168B7FEULL, 
            0xECE4829660C893EBULL, 0x8C84BF474022C0CDULL, 0x0B1DA18446D76F8CULL, 0x9EBAD8B4B7CE7999ULL, 
            0x49629901C43D9D83ULL, 0x91665717CD881FD4ULL, 0xAA5795EA4AF83BDCULL, 0x9BB4F39EA50DC693ULL, 
            0x4116293FEB6625A2ULL, 0xBAE03C0C7BE30736ULL, 0x752311F962B806ACULL, 0x4B2FF0BDBBE745F0ULL, 
            0xD646DD8EDDE1D1E4ULL, 0x8AA007590AC59CE5ULL, 0x5A1B45FD2BA4B451ULL, 0xF82D929045BAB028ULL, 
            0x19BBAEB051A7DBE5ULL, 0xB6D8E2145D2CC8CDULL, 0xBC72877B7D92CD2DULL, 0x8CDCC4955B5B6DB6ULL, 
            0x0CFA3EFDA0E027D6ULL, 0x06A6646C2E769DD8ULL, 0x0FAC474049A13C51ULL, 0x6C42188ACBA0BF5DULL, 
            0x92560361F1AB30FEULL, 0x410B32284209A7FBULL, 0xAEADB29754FD5F2BULL, 0x4B9B55345B393E33ULL
        },
        {
            0xB67117E4319C1C12ULL, 0xF4CB2C5A3583E904ULL, 0x72D9D8E593FF3EB2ULL, 0x0BE15C53B47B5B8AULL, 
            0xABF55A52E00D6241ULL, 0x0EDAB1DFA64B7614ULL, 0x858CE0116AB67E3AULL, 0x47957683DA2187D8ULL, 
            0x64EC14F7CDB904EEULL, 0x9EBBFA4B38D9400DULL, 0xAAAE7F4C1F51E416ULL, 0xDBA0CAEF9D26C5CCULL, 
            0xB0AC191E41E08B36ULL, 0xF7B8C93B16A43608ULL, 0x4D48C76B3B41AD3BULL, 0x7E3E242CE0A033CBULL, 
            0xCB333D2F674BE7C5ULL, 0x84F7E48DD46B0303ULL, 0x558099C0DE1FA15FULL, 0x409070CB58587A76ULL, 
            0xFF7EAC8203A096EEULL, 0x20E71BB921E7CDD4ULL, 0x2A98660A9B9FD38FULL, 0x0CBBF34218336E0FULL, 
            0x2294FAAB5225117AULL, 0x593C0BD3622A1C77ULL, 0xCE1718A7D7837C7DULL, 0x4F25232C9820CD4FULL, 
            0x756A87609CA2CE84ULL, 0x816AEF0269032BB3ULL, 0x54D8D695E673A8D6ULL, 0xC931206181B8F109ULL
        },
        {
            0x2DB5C4742C42032FULL, 0xB0D8F5CC58267C3DULL, 0x3A7ECA84F5C34C2CULL, 0xEAA7B8B23BFFF2F0ULL, 
            0xA97AAF373FC7FBD3ULL, 0xEADAD5CF00D6C400ULL, 0x34D82D0F02407FBAULL, 0x8981C7DD7879B253ULL, 
            0x6D8FCF4B1A2272E9ULL, 0xD20A20A83F14B931ULL, 0xEF6B3A9D0B0B222EULL, 0x9DCB79A946610807ULL, 
            0x5B506DBBED70FAECULL, 0xDCBEEB0261B3CC36ULL, 0x1DC2F46E8C0AA02AULL, 0xDCF823C5025A5A2DULL, 
            0xFFC8AC6B942B115AULL, 0x000A1E0348491AD6ULL, 0x95BC06F0AB00D7CCULL, 0x1DA1A58E456CE964ULL, 
            0x9DB6F27901A37CD8ULL, 0xBDAC524C424AB981ULL, 0x5C963A5F9D5F1B85ULL, 0xD0FECBBA7DC66595ULL, 
            0x7287A385768E13EEULL, 0xB5167B5D5F2DB91CULL, 0x4076D5C450758F7AULL, 0x264A8CFFF5C9883BULL, 
            0xDC93D2197E24B511ULL, 0xF920D75CAE08D808ULL, 0xB68318F551A82ABDULL, 0xB31C77331A189787ULL
        }
    },
    {
        {
            0x5F609C03BC0E9634ULL, 0x68BC366A8F4A02CDULL, 0xC638A69BC25615D2ULL, 0x5244AE1BCDBE1713ULL, 
            0x6E36994BB2CC37A0ULL, 0x3C74CEA7B422DC9CULL, 0xCA54516B3D363375ULL, 0x1ECDC42F9768AE09ULL, 
            0x64E378112932DE5DULL, 0x4C9C10EC6384C97AULL, 0xCC041C3050C0DC2CULL, 0x6142A3AA2A7D46C6ULL, 
            0x507E5C573D373986ULL, 0x0A44DE3891A0A3D9ULL, 0x69FC0D4EA19A50C9ULL, 0xD8197B01429271DEULL, 
            0x00F318F20AAB435FULL, 0x46405DCA4EE4FE52ULL, 0x4126CACBE6B3E914ULL, 0x1CAEFE83AB80F347ULL, 
            0x9008577A7BE34C03ULL, 0xC6F22DE3FF444A7CULL, 0xEDE68C81251E6C6EULL, 0x66CD249BDF1FC98CULL, 
            0xC80A0416AF5F1187ULL, 0xDA8954FDAB7F8416ULL, 0x368DE56BB1429547ULL, 0x56282B6408CDEBA1ULL, 
            0xBEE78398B131C4D5ULL, 0xAF6C0CFBAA7F83B3ULL, 0x93011C593551AA9AULL, 0x8FCF5CC027465380ULL
        },
        {
            0x65A55266AC1FC87BULL, 0x082EAE500BF7858BULL, 0xF294A5496CF8CA45ULL, 0x63395A979D42D323ULL, 
            0xFE60624F51112AD0ULL, 0xB33BFE9BFF517229ULL, 0x8FC0AD08C71A895EULL, 0x2E177BEC276578DFULL, 
            0x6B9B019692ECABF3ULL, 0x8AC290E350EDCB75ULL, 0x18DA60124F6EAD31ULL, 0x5B4702D8A67F7E39ULL, 
            0x8B15BDC0F46910B6ULL, 0x51C71415DFDC102DULL, 0xC7A8C878A3732A7CULL, 0x956856B94BC7001BULL, 
            0x5478F22708CB4896ULL, 0x1222CE4556E37F97ULL, 0xD29A0DF8097DC8C1ULL, 0x787249085C8E4D34ULL, 
            0xAE4BEA1ED90E7EA0ULL, 0x8629FE68E599E4D2ULL, 0x420BE31B843F8022ULL, 0x540F43768765BC47ULL, 
            0x707BC7F48C97AD11ULL, 0xD0B7A2BBA164E6B7ULL, 0x4CE303027ECE3C95ULL, 0x65E8B2B6A7DE3F42ULL, 
            0xD84D94BD3CBD704BULL, 0xEF03E3309916FD26ULL, 0x2B91D155A3C81AF3ULL, 0xBA5EB63CC4E0C0F4ULL
        },
        {
            0xAC24E07238BF5C83ULL, 0x008094EBD4C09692ULL, 0xD8BAC2B94B9C0A77ULL, 0x961A906F15ABF1DCULL, 
            0xD7C1C1F221B819F8ULL, 0x1653EE7FEC42E32EULL, 0xC6BF2FFE540D4C32ULL, 0x98068D8C2154C2D6ULL, 
            0x166C4396E343463DULL, 0xDDA0141BEF28E6ACULL, 0xFC6022B1C1CAC901ULL, 0x4C25AA803519F6F6ULL, 
            0x89581F232D764B81ULL, 0xA53F9A87146B728AULL, 0x5154976397048564ULL, 0xA82692F9BD9DDBEEULL, 
            0x7B9301E9EFFFDD31ULL, 0x94549B69B0861CB1ULL, 0x011B77ECD9D75F08ULL, 0xD055287683521DBFULL, 
            0x04F6B78311B01D35ULL, 0x556C936AFA465351ULL, 0x127E5108E11272A2ULL, 0x59826BFA62A45525ULL, 
            0x4A650B2C7EBB82ECULL, 0x3D5A5054F3AF7B5EULL, 0x8765511C63AF90C7ULL, 0x38AC3BF644F31057ULL, 
            0x4E05C9CCFC491DFCULL, 0xE5F0B81E28A80CC8ULL, 0x460DA53BDB61698EULL, 0x8304FA71D71D2633ULL
        },
        {
            0xF423A3245D5AA2D8ULL, 0x9322BDBF33BC7336ULL, 0xEE2C9981FC234B3EULL, 0xB072CB83288B94E4ULL, 
            0x302E5D327B1E0441ULL, 0x138DD6FAAA7BF210ULL, 0xF57D6BFBA8E3EB10ULL, 0xA1D15DFD2304EAD2ULL, 
            0x5BBCDF47EB5C26E8ULL, 0x36197628683E48BFULL, 0x87751893C3135EC3ULL, 0x1F068850CEDEAA30ULL, 
            0x1463C07E1F1FDDECULL, 0x8A44016EC4CEDEB1ULL, 0x7F5FCB328C86902EULL, 0xB635E77CF82B5697ULL, 
            0x4DA63B3553000C85ULL, 0x5AC36C3F4463D0AFULL, 0x9A96FAEA54B1A8E0ULL, 0x09603913545FAB42ULL, 
            0x7194EFD781128142ULL, 0xFBD8DDD9D1000739ULL, 0x5C7261AAE39F777CULL, 0x2296943CD552CD55ULL, 
            0x8923A45272EAD6F3ULL, 0x9A5C41FFB6B028A0ULL, 0x4CFF5584CE60EF68ULL, 0xA95035E544AA0519ULL, 
            0xA5F4E39DF96F6690ULL, 0x189744E26D42A8E8ULL, 0xF261DA76FDDDEE18ULL, 0xE74D23916F3DF287ULL
        },
        {
            0xB9B0CB16AB5CCBACULL, 0xD477E78BB437E7CCULL, 0x669827F26B69710FULL, 0x0B2CCFBA3BF66A19ULL, 
            0xD1CE18DA9E022443ULL, 0xC5F7CF9EE7A40A9FULL, 0xC323AD5A275D7A43ULL, 0x1833DC096B787738ULL, 
            0xEE45CE84E1463BE3ULL, 0xAB19D2C13F3805DEULL, 0x00F570205E0E8E71ULL, 0x2D2EB883AA4C4E39ULL, 
            0x147F662822014BF7ULL, 0x006BE92B1178CD0BULL, 0x0FC2A804944B36C3ULL, 0xC446D27A6F55708AULL, 
            0x7C91B8AA8D825AFDULL, 0x1E596A211CE4D8FDULL, 0x14099662EF5B3980ULL, 0xD179ABF433C5BCDEULL, 
            0x1FFF27C7D1F51566ULL, 0x9BE501D1825EB104ULL, 0x67C1B4285354EF68ULL, 0x4DE60E20D88EDD94ULL, 
            0xAD7532F559894B66ULL, 0xC2956EFE28ECE363ULL, 0x62A174CB3E17E167ULL, 0xA3AEFB03FD85C39AULL, 
            0xD8CD70D784A2735AULL, 0x127993CD58C04881ULL, 0xD15CA186364313D2ULL, 0xC963E5E428ECD916ULL
        },
        {
            0x0AECBE0C9154FE92ULL, 0x8593FBF274364AF7ULL, 0xFA1CCE3D3D3412ADULL, 0x6BD9D850F6BCBCEAULL, 
            0x9910FC03CABAFC80ULL, 0xDBA3B8C22649762FULL, 0x34EBC5C07B2F6673ULL, 0x423F4AB6EA41C616ULL, 
            0x55C5BB46DF1C5CE3ULL, 0xA1826D3FECA30737ULL, 0xBDDFFF46D59C782BULL, 0x28E95606512A105DULL, 
            0x2EF38FD62F41DDA1ULL, 0x919577A7BF44BDDEULL, 0x61B6563E3D3131C2ULL, 0x81FFB3C5744DB1EDULL, 
            0x23C950120CACEA15ULL, 0x411C3143962955E4ULL, 0x3CF304649EBDE489ULL, 0xABC14488788DF33CULL, 
            0xB8D579E123C87163ULL, 0x90C87C06F4E054F0ULL, 0x8E3928000BF3C596ULL, 0x71700BEBDF79BFD0ULL, 
            0x63531AE962131361ULL, 0x30DF5256D0012412ULL, 0xCBC2B17BE1DD4C09ULL, 0x619AA5CA8F48A350ULL, 
            0x710A031933F0A44DULL, 0x3C900873C16D802EULL, 0x6BEEBC86B26E25D8ULL, 0xFC6BB09B23AA8504ULL
        }
    },
    {
        {
            0x3256A0F8931D0072ULL, 0x9E244CA2A1D7B7D2ULL, 0xABB2A09468F56D9DULL, 0xDF4C4DF952236571ULL, 
            0x310EE7907D8C58CFULL, 0xF977B4A1085A0102ULL, 0x139AF08F191B0453ULL, 0xBE4CA8B067543092ULL, 
            0xFC36A638B99077F8ULL, 0xE3944054A81E3A70ULL, 0xCD2FEB47FF9517C9ULL, 0x91B2783517E3BB93ULL, 
            0x4247D7CF7E16C360ULL, 0x735C59E7DE80C8EFULL, 0x030CA74ED7B3EE00ULL, 0x0C5782F9DD459930ULL, 
            0x53CA5C5DF9ED3A6BULL, 0x8AFBC90EAA71B35EULL, 0xC5F1617427F0B748ULL, 0xBA5155CA021E944CULL, 
            0x522317CFC9B513F0ULL, 0x3C46D7097D2E0BD1ULL, 0x728C576FC75B1B4CULL, 0xBE432E7079517BFCULL, 
            0xD0FB6C48F7BF3F51ULL, 0xCC89D6F41A936A39ULL, 0xD717FCE354BF4F6EULL, 0xC4DED80ED69C31DEULL, 
            0xB3594E9F8E3ECDFAULL, 0x7C0E98F51E6134F9ULL, 0xDF5DF847C65C7704ULL, 0xC79C42EBC109332CULL
        },
        {
            0x169580D8C39609B2ULL, 0x64C9DEFD4AC6DA86ULL, 0xA9FC3D88CE765190ULL, 0xE31A9D5C94E8289FULL, 
            0xF5B8C41A8425960BULL, 0xF218D11A97DE6914ULL, 0x4F11B0C50B6EC8B0ULL, 0x7679ED73953D55F4ULL, 
            0x38F1F912EF47747BULL, 0x08A35572C3C87E20ULL, 0x3EC73B3393455DC3ULL, 0x5158AE38F0594C10ULL, 
            0x86AA837F4A19252AULL, 0x01813602D422A23FULL, 0x1F6C5AECCE1D32FCULL, 0xEBD762F5184DF803ULL, 
            0x496DCA14DE4C1363ULL, 0xC35C633A46D86207ULL, 0xE5A5A9A5A106C9BDULL, 0x07F91E59D57A2E44ULL, 
            0x0224C4C3DD28D06EULL, 0x0498000D70747DFDULL, 0x04A927E3A1A2D0D7ULL, 0x7DCE54F95209F8FAULL, 
            0x58A720D62540C8E3ULL, 0x27479D45E21DEF79ULL, 0xEB097C04C000A9E7ULL, 0x217F572E07C1FC50ULL, 
            0xFA8C6F00586E4023ULL, 0x49C5A186D2DC86DCULL, 0xCAD8D19DEF426491ULL, 0x6C4F64A92F87CBB8ULL
        },
        {
            0x46924555FF3ED540ULL, 0x6426AEEEC8C5825BULL, 0xBE9631B90B49F063ULL, 0xF031FA567440BAF8ULL, 
            0x4A18C33FE6707A34ULL, 0x6FB6D6B9EE13C309ULL, 0x743856A1DA86631BULL, 0x28A81D6230045F53ULL, 
            0x5DCF542601A6B524ULL, 0xDBDAE732D197AAF2ULL, 0xA1619157B06FE7B1ULL, 0xEAA10EDC7ED3047EULL, 
            0x3F8AFB25293F8BBDULL, 0xC91BFE0D97629E2CULL, 0x488FE9C5BB9118E2ULL, 0xC6B4FDED8B43993AULL, 
            0x1CB85EB08325B796ULL, 0x743F61E36D2AA7BBULL, 0xB84A42D4AE609EF9ULL, 0xB12EFB549B658AF7ULL, 
            0x1D39C942766FB4C2ULL, 0xFD36CC75887BA9F5ULL, 0x9097D9C5987A00F9ULL, 0xF8DB2D487DB1C08AULL, 
            0x4632F0D8DD6A1010ULL, 0x3E05A56083DC41FDULL, 0xCB1780894A23A788ULL, 0x4D5C942D6692B478ULL, 
            0xCBEE255BF2DBD319ULL, 0x20C9BD076AA8EB56ULL, 0x9A36F2F3109C2DF5ULL, 0x844B5DEF3192A05EULL
        },
        {
            0xAA92DACDAFB8E3A0ULL, 0x0016CEAAB10B4B03ULL, 0x3F8E950F7A99B9D6ULL, 0x9BFD05523D0C90E9ULL, 
            0x412EA2A19718E512ULL, 0x6FA673647D05E470ULL, 0x5EA0B0515C54E5B8ULL, 0x4236328FCF48F26DULL, 
            0x7C48FE9C11D3986CULL, 0xF323590DFA9BD937ULL, 0x218FE7EA452636C1ULL, 0x50D59115075D0394ULL, 
            0xE5CCACF0CD34B0F5ULL, 0xE6C3F7BFB700C21BULL, 0xBAA7EDA81B3EF30FULL, 0x03A3EF54A9686C69ULL, 
            0xFA9F3BBC96117C22ULL, 0xBBA6500F74780293ULL, 0x13D592FFB26D31CCULL, 0xDD53C80746215CF9ULL, 
            0x3CDB8DA4B9E5421BULL, 0x2A864121871AC69BULL, 0x210FEC6F06BACDC4ULL, 0x257503E4C63160E3ULL, 
            0x5531C04E555A6672ULL, 0x0AD51984E0BE5C76ULL, 0x01A511596AF06751ULL, 0xF3086063E698426EULL, 
            0x8C2F425AF1B6A09DULL, 0x18B25778CAD3AA1DULL, 0x196403588AE3B27AULL, 0x853E32802C99EF95ULL
        },
        {
            0x5A227A985A425C4FULL, 0x5E3A1B9B551497BDULL, 0x5180759290D5296FULL, 0xEE316953CE1823F5ULL, 
            0xAFBB833D771DDE55ULL, 0x861995DF10A2AC42ULL, 0x773F4B4C9786ADADULL, 0xA5C0B958C629A274ULL, 
            0x850931817E7B76EFULL, 0xEB8D76ED6B82BA74ULL, 0x7BB58D85F0A12BA1ULL, 0xDCCAE298CAA04F8BULL, 
            0x00FFA0F0159A74D6ULL, 0x7C3F8488F3FC8825ULL, 0xAA531DD5B4787226ULL, 0xF091DD470B72435FULL, 
            0x73F9536D368B146EULL, 0x3FFA273576D6B9B7ULL, 0x7AAC8B10DB8FC0BDULL, 0x61F1A0A42FA54B80ULL, 
            0x0FDDE108391E2C44ULL, 0x06712110B2C46887ULL, 0x19F67A6B2D887768ULL, 0x68F85632A6BBAD7CULL, 
            0x45F5A3DD34052D4FULL, 0x1AD4263873A16053ULL, 0xED5D710B5A75F846ULL, 0x277062F3064C0BD5ULL, 
            0xADE807638A0422F7ULL, 0x408F4D299A69507EULL, 0x4C5945CFE694DB6AULL, 0x03683F2B15533A49ULL
        },
        {
            0x76310B31610EDEC9ULL, 0x3CB745DACB3CF9EBULL, 0x80EB6EE1DE6A6ABFULL, 0x24BCEF6D8DBE9064ULL, 
            0x27C4C7CA1F900D72ULL, 0xB48FD78562E778E4ULL, 0x5A36C3CF028BC57BULL, 0xF59E9CB90A133CC3ULL, 
            0xFCCFAA3F34493DA5ULL, 0x0A3282F53F5751EDULL, 0x5B5A7022AD8EF041ULL, 0x79C406AF4111BA64ULL, 
            0x7E3BEF9CE95B567FULL, 0x31A15CEF9701586BULL, 0x812AC2690E92683FULL, 0xBE3802B65350F672ULL, 
            0xCC1331D91FA2C9C5ULL, 0x02075C0171BF080DULL, 0x28A8F9BAB890C713ULL, 0x95F26B2FA0ABC567ULL, 
            0x9DEFC7BF3741F328ULL, 0x0C95D340EE843A18ULL, 0x4AB49D081B2B416EULL, 0x5B26054D7C362527ULL, 
            0xD66EEAE237795B52ULL, 0xD789368E5D86442CULL, 0x787D25C0514962E9ULL, 0x3D21EEC1D5E54010ULL, 
            0xFAD3C25494D8F6A2ULL, 0x9B41F36DA8D8CADFULL, 0x4C173115C6022572ULL, 0xC73A6FA553D8E5F3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseCConstants = {
    0xBB3E5D7FDAF6436FULL,
    0x9E7A211AF558A0ECULL,
    0x4ABE201C496B0C03ULL,
    0xBB3E5D7FDAF6436FULL,
    0x9E7A211AF558A0ECULL,
    0x4ABE201C496B0C03ULL,
    0xE4F0CDE91F9DB92AULL,
    0x071883C7E3261628ULL,
    0xB4,
    0x9D,
    0xB1,
    0xBA,
    0x90,
    0x15,
    0xEC,
    0x9D
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseDSalts = {
    {
        {
            0xF73F0BBCAAC998DDULL, 0xCC9059E68B036877ULL, 0x052DB8F25EDF2AC3ULL, 0x0A180CF5D064D020ULL, 
            0xCAB9FFB195E82815ULL, 0xF55E419D6289CA62ULL, 0xC770A9A43ABD4A1FULL, 0x0591BEF3F2420F6FULL, 
            0x04A17020B84855D5ULL, 0xFC76710C94723EBAULL, 0x3143032BDB7F5E8EULL, 0xA32FE60092095784ULL, 
            0xEAFA8204605B4CC4ULL, 0x3F95D4886801E46FULL, 0x64FA76C5F201EBCBULL, 0x0DED72853C9BD6E6ULL, 
            0x2D2623D4FAF7AD3AULL, 0xFBF355014944C1F2ULL, 0x7188342C6E9B77EDULL, 0x7FD363DAAD57B8A6ULL, 
            0xAFB93ED5E68F1B8EULL, 0x8099DCBCC816F582ULL, 0x15AE56F2F8E734CBULL, 0x42F788A3E8C683B8ULL, 
            0x615B32880799EF28ULL, 0x071A3E8A58555E8BULL, 0x7FFBB304DAE28FF4ULL, 0x1EEECA794D50737AULL, 
            0xD89C3B9DF825AB6DULL, 0xE5D36D37A4E98D28ULL, 0x6F35F817289FB629ULL, 0x5BC2E3944E80A803ULL
        },
        {
            0x9B7CA22830ED106EULL, 0xB156CAA396BA4200ULL, 0x1AE46B4E89A796BAULL, 0xBA7939A2B3EE011EULL, 
            0x76FA1BDE2C597647ULL, 0x0EC8AC337D2C4811ULL, 0xEB1E4D8CE3D6378FULL, 0x606A025A56396FECULL, 
            0xEE55BED0A752438DULL, 0x9BDA9BC17AC9769EULL, 0xBCE4A798DD0B1F0EULL, 0xD8EB7714FE50BAEAULL, 
            0xB1A2A471822AB3DDULL, 0xD7D487F38C067AB8ULL, 0xF9B79459C37ED05DULL, 0x526115ADD3C0A0F3ULL, 
            0xB5FC0DDC55B45CE9ULL, 0x283209DDF9558120ULL, 0x3D536726C5B31547ULL, 0x87CEDAF8C6E34D4FULL, 
            0xA3BC774A88A46922ULL, 0x5039D81B0A0B0778ULL, 0x84B298A3D4A58B6CULL, 0x0ABA21F00D530E79ULL, 
            0x54E2638863AE20FDULL, 0xB5DC8386E0334EBBULL, 0x3BC8E3C13EA8B69EULL, 0xC5C3FF136A218C06ULL, 
            0xD7E445136FF39ED2ULL, 0x52D10D9CC11599D9ULL, 0x1745B5937860E1D8ULL, 0x47D31814B3698936ULL
        },
        {
            0xCA6B127D9947DC59ULL, 0xD6362B831C01C169ULL, 0xA49DF27E637B8917ULL, 0x2F2B03BA5E91E8A7ULL, 
            0xD68AD298E80CC40FULL, 0xC57C11C978511655ULL, 0x8F74B190D711974BULL, 0x6F0CD760738B72B4ULL, 
            0xF383AFBCBF02BD7BULL, 0x1AFEE16094DBEED2ULL, 0xFC9F0F9FD5DA7E6FULL, 0xAEA5D5DC648246B1ULL, 
            0x4CC1C511DFA8890AULL, 0x44ADB4B9D919FA64ULL, 0x5A3BE49625334E72ULL, 0x27B3E066C56904D1ULL, 
            0x07A60E6649604CD1ULL, 0x03E5605273C72483ULL, 0x07A6483FCC269423ULL, 0x9F3952CDCD1708DDULL, 
            0xD36AB4CA7FDB4853ULL, 0xA463181B3B82129AULL, 0x114A872B6DD267FAULL, 0x51DADDBA300B21DFULL, 
            0xDB099F04AE1AEE9AULL, 0xAF2CDA207C93F0C1ULL, 0xE41C0A40B877831AULL, 0xEB0D4377846336CEULL, 
            0xE2BA8A7E4FDC253CULL, 0xBEE0FF7AB9B20E35ULL, 0xCBA029C1CA51640CULL, 0x8D9001BB7665812FULL
        },
        {
            0xAE090F99C6F6308EULL, 0x5185CF4B26A0071EULL, 0x4BCA21170344A9D4ULL, 0x6E609A0A61C6B5D1ULL, 
            0x48804A01CA7B2E18ULL, 0xE23461A25580B020ULL, 0xEE223625C34100E0ULL, 0x4B62A79449F1C49FULL, 
            0xFBD138F8B83191D2ULL, 0x6B18E30FE48FA3D6ULL, 0xA65E173B3BEC5E59ULL, 0x11C2AD77AB89B8B4ULL, 
            0x12605A4707E42619ULL, 0xC6AF3272C95BD639ULL, 0xC60B076B7344A0C8ULL, 0x9A84FBE84DC6BED0ULL, 
            0xDD68248D75F2EBF9ULL, 0x5C8D0680036CA650ULL, 0xF218DF9217439F47ULL, 0xF45C3F01293B5997ULL, 
            0x0D29F73F4940A579ULL, 0x368C57F426A62C22ULL, 0xAAD37EDB7D5E6386ULL, 0xD7694EBDC3B6D65EULL, 
            0xEB0B94916E76074DULL, 0xA40628F7831E6594ULL, 0x906C7936C2A957E5ULL, 0x39D97D30D1748E88ULL, 
            0x0573364A68336448ULL, 0x30DFC4523F7D82CFULL, 0x43CA2D54B346846AULL, 0x7A4D6507BD8C690EULL
        },
        {
            0x0B4FA8DCE6EAB86CULL, 0x9D6BB98D2FEB7536ULL, 0xE13135E470E0AFF3ULL, 0xE22626799B02D453ULL, 
            0x95A248C65CD151FFULL, 0xC7C520BD1C9C5D12ULL, 0xAB439C6587E5A867ULL, 0xAD7C12A7A3F22B99ULL, 
            0x0241D373CB535238ULL, 0xAA990DA970D32F7AULL, 0x1CBB3876003577D8ULL, 0x52B7F9D2DEDF2A9DULL, 
            0x253D105AA27B49DFULL, 0x9CC806906518373AULL, 0x546BC344BF912262ULL, 0xF124CCC761911665ULL, 
            0x400A7E017615B4B0ULL, 0x148229E534319F0FULL, 0x3CFAF54122341FFFULL, 0xE7A9906AAD2EABF4ULL, 
            0x5CAC1A83FA7FD84EULL, 0x19695B335644E7B2ULL, 0x5F4B7BEF6C14B618ULL, 0xADEEA604F3036479ULL, 
            0x708377CEC647E1E1ULL, 0xE9F50A28B70A0B56ULL, 0xB341408B0FA19D26ULL, 0x4FBB804268309B2DULL, 
            0x984F294C03F870D1ULL, 0xBDC60C119D07BB14ULL, 0x6DA4A96BF47F123BULL, 0x92C7637DBE4A83C0ULL
        },
        {
            0x08362FFF7658F33FULL, 0xC657E5A904BE5894ULL, 0xCE4A9DEA0DC872FBULL, 0x733F5FB3DE9310A4ULL, 
            0xD974A32B638F8C58ULL, 0xD8350372E25D8161ULL, 0xCA7D391BF4FFCE4BULL, 0x2D0DF5D2A7C109F0ULL, 
            0xC14221678E396E3EULL, 0xB87BDDD6AB4DB600ULL, 0xCADAD9F55BF302DDULL, 0xDC630F1740337E75ULL, 
            0x2ADC9F40FD1B5A69ULL, 0x66D7CA1679AE6DEAULL, 0xDE8223702DD5C45EULL, 0x4D4EFF7FC5344AB6ULL, 
            0xF317548176A00942ULL, 0xDEB2005F904B9451ULL, 0x15E51741CD8EF8AEULL, 0x02C2557053B6DB76ULL, 
            0x8246527FEE7E3241ULL, 0x625543B904F1ADE5ULL, 0x6B20C4562E3BAD46ULL, 0x6052764DA350DC40ULL, 
            0xF3B1E55736088F68ULL, 0x3554D1FC6CDEA412ULL, 0xFC52FC672E0BE99CULL, 0x92B105BF18FFC31CULL, 
            0x7154949597A7F096ULL, 0x8DCC58B21D516F3AULL, 0xD724B93FFB7854CEULL, 0xE320AEA3B85ACFA6ULL
        }
    },
    {
        {
            0x4F63D798192E0C69ULL, 0x8B0D9A8DA2FB8E56ULL, 0x323DD97AAE591B96ULL, 0xFC7603260DB36F5BULL, 
            0x39289E5CBC3A2BDDULL, 0x000957D14F639049ULL, 0x674B7AFE69C83EF1ULL, 0x176C8BB81C56AA4DULL, 
            0xFB30FDC4B6BDA343ULL, 0xFD235FA09572A766ULL, 0x81CF1F30FE67A9BAULL, 0x6991605725C81355ULL, 
            0xAF999C65AFBA52DFULL, 0xE043F1F087E2410DULL, 0xBB31A80C24885917ULL, 0x0685910F7F878DC0ULL, 
            0xF9937E9A287D3830ULL, 0x647FD61C4CB46145ULL, 0x2D7E83F1B21C16C6ULL, 0xF79B2AE94D195B53ULL, 
            0x72569EA823DB6A6AULL, 0x5FB4D015EF525543ULL, 0xA2BD533C3173A71CULL, 0x12C081540C7A93FFULL, 
            0x96157E371FB76CB3ULL, 0x3CA87C8F505D4C37ULL, 0x3D60A1490B0BB706ULL, 0x8AD3A1458A8361E7ULL, 
            0x6CBF35B0097ED5C7ULL, 0xD320AA440FAB557FULL, 0x7DA4ACE1DB006E3FULL, 0x4C4DB140F860A0EDULL
        },
        {
            0xC6E53AF2F6281BABULL, 0xF3C91137A3C9CA2AULL, 0x62C60351EE80BE35ULL, 0xFF0BEA0757D6FF82ULL, 
            0x0D4F937C8820D4ADULL, 0xE7881504A8CD866FULL, 0xB001A33D6915F68FULL, 0xBDD416CA6824ED2BULL, 
            0x983BBCA302C5D243ULL, 0xE310274C9B38705DULL, 0xD42D6351C32695D1ULL, 0x7D532B954231A369ULL, 
            0x922C9FE6E9DBD218ULL, 0xBA1F15D347C27216ULL, 0xA1734889E7156789ULL, 0x5DB65852FCA044C5ULL, 
            0x751A6C9BEEA47C38ULL, 0x6191FA1496951F49ULL, 0xC48835E3E71B2FDBULL, 0x77A171820576F040ULL, 
            0x18BEDFD0603B90D6ULL, 0x7849D35CAA7A2D3EULL, 0xDC0BD0A0B429B2CCULL, 0x1E6F3D8D87AC11AAULL, 
            0x07BF7E2704BF5FC4ULL, 0x07A6F4AE136B6F84ULL, 0x91E0608D31469C67ULL, 0xF1D85BC07B2A8F57ULL, 
            0x6B763493229A52E5ULL, 0x068FD8FACEAAF950ULL, 0x5D9F953D6E8F7E24ULL, 0x31724AE4CCF1B170ULL
        },
        {
            0x5737BDA85662DE96ULL, 0x89A6C1B33F1D5781ULL, 0xA97D04F3F1E0A20EULL, 0xDB71177814778DA0ULL, 
            0xA5CC445D943536ACULL, 0x40F8B324FB5BCE3EULL, 0x32EF016ED2B96223ULL, 0xB6388516066CE7CBULL, 
            0x170CBDDBCD96DE9AULL, 0x8C515D409F7107C1ULL, 0xE8924DC37E4FC0BEULL, 0x035338A98ADD1CC0ULL, 
            0x44365AF888426646ULL, 0x6B48E99EA2C77C40ULL, 0x9026AD4DD421C308ULL, 0x5851E9D62A473D11ULL, 
            0xE9D8A44B63E3B69CULL, 0x66C9A59EB015D84EULL, 0x85B3344B0C227E05ULL, 0x402B05CD8345D5DEULL, 
            0x5EA83F8F4D592ECEULL, 0x76D193475DA0AE5CULL, 0xB87077636BBE8AF6ULL, 0x90FBB3F5AAE84EEDULL, 
            0x98B20499B46BF402ULL, 0x1B14C6D6FE381D86ULL, 0xDB969FA55DFC5AE8ULL, 0xB4A2F8E90436010DULL, 
            0x9F33EAF770A07AC8ULL, 0x3E73DC20F3C1C44AULL, 0x2930A67D620BF264ULL, 0x8E2733C1DAF41D83ULL
        },
        {
            0xEA72FE75944CD089ULL, 0x9EE4F278930CDC2FULL, 0xE9C7C4E8E5824857ULL, 0x003F2B818FAC8C0FULL, 
            0x6BF620486CFA1C04ULL, 0x029EF77B04534D6EULL, 0x6483D6606BDD4D39ULL, 0x74FBF98356ACC2E5ULL, 
            0x0B9905B38DF79D7AULL, 0xDB4B0389E92ACD7DULL, 0xB9156C526BDC4E0DULL, 0x3982D017F315BE2BULL, 
            0xFBDB377D13BE7745ULL, 0x6B3E97CB872549A9ULL, 0x80C3F8763449F4DCULL, 0x5BF3F32B14CBA965ULL, 
            0x796389AAA36569D4ULL, 0x1E6B7DC55091C476ULL, 0x9F1E04AC18F8D0E1ULL, 0xF6A0FA56DB1DCDCCULL, 
            0xEE628D8419ABBE16ULL, 0x9A2A031F226F8F2EULL, 0x3434502B8487ED8BULL, 0x9CCF0E2259478D99ULL, 
            0x3C829E1B6C7F42B4ULL, 0x9E04F9A585911F76ULL, 0x7A4492820D439606ULL, 0x30AA4023ED7A9912ULL, 
            0xA5EFC68D202CFCFCULL, 0xDEE687FBBE075C4DULL, 0x3D05DD1755244F2FULL, 0xED05D343D31FA095ULL
        },
        {
            0x4AF3B5D6A6C5FC9FULL, 0x613B15CE99DB9735ULL, 0x68F313D6501B5B00ULL, 0xA63177A595856E0EULL, 
            0x1E96EA9F0DC03AF6ULL, 0x5BE9F81BDB9A9AC4ULL, 0x9FEA6CFE48CE8183ULL, 0xCCBAF63E88007FB8ULL, 
            0xD0BE6F85853E9085ULL, 0x9CD86D92E61AA9FBULL, 0xF538F5BFBE259679ULL, 0xAE53E301C8BA56BAULL, 
            0xB20971C4FB838490ULL, 0xF010AC317FDB8E60ULL, 0xB16591A725F3EC99ULL, 0xE076BA44833A364EULL, 
            0x6B7538A32C7BFE37ULL, 0x7F6643B9EC546D1EULL, 0x9A3F160E7845265FULL, 0x4D65569D05087A93ULL, 
            0xDC76FA7BB47CAE89ULL, 0x3BB4580F1357D318ULL, 0x947375717BA521ACULL, 0x05EC043B3A1C541EULL, 
            0xE2BDE8C498E9B6CCULL, 0x55BB08F9F1B3C508ULL, 0xA1FD961669612379ULL, 0x7E8692D1C39C47F2ULL, 
            0x1F6ABA3047D22044ULL, 0x8DAD9608E87FE2E9ULL, 0x7D56B7B86C2F9848ULL, 0xC3D9E3061450F2B9ULL
        },
        {
            0x5A3C700838ECB030ULL, 0xB32A9BC7FBD99B7AULL, 0xC5F56DE33E9AC400ULL, 0xB3E7BB9FF027713CULL, 
            0xCA1BC89802AE1895ULL, 0x366052FBA95AEF16ULL, 0x28111FE5F49839CFULL, 0x8635ABC863D1774EULL, 
            0xF6AF6F1C31D28E66ULL, 0x8B565529BE22B3CDULL, 0xEFFC33E2BA550001ULL, 0x5E64B52D7F78664AULL, 
            0xEFF3612489896E8FULL, 0xED15B67B73F55A5DULL, 0x12EF578A6EF1179BULL, 0x65539B71734B1FECULL, 
            0x784604B741D66A11ULL, 0x1421938B36F89CDBULL, 0xC50451A29EFDB2F6ULL, 0x047FE9DE36A63441ULL, 
            0xF42A8ECBE603EEB2ULL, 0xADA6A6D52299C36CULL, 0x39534A010C56E257ULL, 0x9B41FD05723E06D0ULL, 
            0x272190242F348D60ULL, 0xDC15628DE27C2020ULL, 0x6DB2513B1FEECE67ULL, 0xB09F490F7FAE1663ULL, 
            0x12FFF63A89E9B573ULL, 0x9E3CA54846032322ULL, 0xB544A947CF8096E6ULL, 0x2BE63577BCDD7AA6ULL
        }
    },
    {
        {
            0x2C7ED4DACC47050BULL, 0x180ACE9C09058726ULL, 0x3437638410ED59E8ULL, 0x96C0B41A528ADC6FULL, 
            0xF577C7B5011BEF8AULL, 0xAE0A8F666A6180D9ULL, 0x94BE8EB6D6AE8F84ULL, 0xE73B2AF46D9FE1FAULL, 
            0xBC001E9C3A2BA179ULL, 0xE6C10E43A6413F6FULL, 0xF985E27839C321B9ULL, 0x93140B5FCD3E528FULL, 
            0xB10A9BD5A2BDEE9DULL, 0x72EF4088297F23BDULL, 0xE5ECE803CBD06ABEULL, 0x257DB3B8FEA2CDC9ULL, 
            0x6F5F7A589EAA8B15ULL, 0x1EAE3BF8BDE54857ULL, 0xC1BF68BE3E295284ULL, 0x6AE6C19EF035FE11ULL, 
            0x92677F58584D41F6ULL, 0x1E3A005BD9D29C86ULL, 0x103EB7C6DDA9CA51ULL, 0xD4F3A6E2048EAB8FULL, 
            0xB83E6AE2237D94C3ULL, 0xF60AACA4930F4045ULL, 0xCDFF461A40601C62ULL, 0xC3330DE119AF28B3ULL, 
            0x7EB0CECB54125902ULL, 0xC93CC98CF6ED2CFCULL, 0x81A04E4E57C90518ULL, 0x08F73602C8298FC3ULL
        },
        {
            0xB6CA288907E02DADULL, 0xBBE51062CEBE49F3ULL, 0x635BA2FA9201F9A0ULL, 0xE1FFD7B731CDD52CULL, 
            0x97EFE6BCA144E805ULL, 0xF494EEF081C57E04ULL, 0xB4F8A337FF4DB569ULL, 0x64F5F9D4C25BA5E2ULL, 
            0x8ED961CF37A3D7B5ULL, 0xAD9E0EF4ACFEEE15ULL, 0xE9EBA3F6A95F3337ULL, 0xEAEBB80456042278ULL, 
            0xAAA49F63DE327BDDULL, 0x31D9DB98D624BDA0ULL, 0xA408A4C90F116762ULL, 0xFF27B3DA8EB639A1ULL, 
            0xC5EAF64EF04404BEULL, 0x33F5F77AB47A40D5ULL, 0xEAADF77E07B47200ULL, 0x3BAC1CBFF64D2986ULL, 
            0xBA153DCABA0EED91ULL, 0x25447E0ABCA2E879ULL, 0x6B1D37C308357010ULL, 0x8758AAA56D4B655AULL, 
            0xCDF2A2E5922AB55AULL, 0xDA91925ED81DA8B9ULL, 0x77406CBFE4B36539ULL, 0xB0AD4EA970DFCF8EULL, 
            0xADCCF928A055B687ULL, 0xE6ED7A6553203C87ULL, 0xD2F73350A9B65FD8ULL, 0xA7493B545BCA0CD6ULL
        },
        {
            0xAFE20108E5843143ULL, 0x6A148C485FB11841ULL, 0x12E9138F2964D219ULL, 0x8EF8BA48710D0B11ULL, 
            0x8D06ECBF7970CBA1ULL, 0xBB7CAD03A10FE4B3ULL, 0x2C2D097797616115ULL, 0x5477B4DF59BD92E1ULL, 
            0x3213CDF772CEA273ULL, 0xA129424A8A6EFABCULL, 0x09A344CBD67C182AULL, 0xE534CB0B0A0CE51CULL, 
            0x56D20A3F2C5043CDULL, 0x4D72FB38B9F649EBULL, 0x526BCF3DE20980CBULL, 0x357478265BF1CC87ULL, 
            0xB0328594E1784BC6ULL, 0xC85869B8BA3780F0ULL, 0x2130501436C9B729ULL, 0xCFE7AB3A2402139BULL, 
            0x0F9FDAF1C4F84614ULL, 0xCE81E34C3CFA9CA1ULL, 0x3A1F31C894A962E8ULL, 0xBC1DC4EE5195E405ULL, 
            0xA46ED4D3673BB82CULL, 0x71860238BA4D58B9ULL, 0x5671279ECFA2A0C4ULL, 0xA90CD3F9D0E78CB7ULL, 
            0x1B0E224FB0E0C9F4ULL, 0x6A0A7F4100C6799CULL, 0xE311A0FEDB839410ULL, 0xFF906A271865789CULL
        },
        {
            0xEF25563A52067552ULL, 0x495813FDBF37C236ULL, 0x3165FA50CC896886ULL, 0xE4835307FB82BA09ULL, 
            0xB289741836A31F7DULL, 0x5B9AE293C740D3D6ULL, 0x45424BFEC17AC157ULL, 0x742DE4DD15CFE257ULL, 
            0x1023148F2B370EC2ULL, 0xCFB1821EAD3B10EBULL, 0x1D8B0DB08A65AF91ULL, 0xCC4689AC83004478ULL, 
            0xF96B4EB3D1FA0F25ULL, 0x822AE1F046533527ULL, 0xD89A31833E7E09C1ULL, 0xA6A44B1DA3419046ULL, 
            0x814A85D0F980870FULL, 0x92D8AD931AC9D867ULL, 0x4400C307138411DFULL, 0x1B5D650814562B96ULL, 
            0xE0B702181A5035F0ULL, 0x937A7707E76477B9ULL, 0xC0C10D1441F1C4B7ULL, 0x08360EC9373F3B61ULL, 
            0xDC560B0BAC9D5DD5ULL, 0xC34A88DA11FF0A0AULL, 0xA22F17944C6C8FB9ULL, 0xFC5B96BAD7FA0724ULL, 
            0xD1A2066D9235950BULL, 0x057ED0EAF9831018ULL, 0x13E0127A1CD533A1ULL, 0x6049EA10FDF0A2E4ULL
        },
        {
            0x7EE1BD9A521DB001ULL, 0x722FD6C959617C57ULL, 0xAE8D5A2D5B03FBB1ULL, 0xB9DA8BF5EA9D5D36ULL, 
            0x08C524D87FC1A313ULL, 0xD60B4CC9FD5E09D2ULL, 0x1896B8EA073BE967ULL, 0x1DF9A6F9199A4BCBULL, 
            0x9C9DD67490C4F170ULL, 0xF256F0E6D3E70FA9ULL, 0xB9DDD203F54DF2B9ULL, 0x886DBA2FC5C07D66ULL, 
            0x2CAC65CC08B31F45ULL, 0x0026B665026D679EULL, 0xA2029378AE5971B0ULL, 0x68B86E67653BA7E1ULL, 
            0xCB2358C40FA05D2BULL, 0xB97EF1569666907EULL, 0xB76D88142CB1E067ULL, 0xCE238BFB1323C3BDULL, 
            0x687596239CF596B7ULL, 0x39150504F9A82D54ULL, 0xC0417378CC456FB0ULL, 0x6BB9EEC3D9982A13ULL, 
            0x5502B2922E87B071ULL, 0xA9AE334EA5CA931CULL, 0x3B1F5A33E4E64297ULL, 0xB1248805EF48BA65ULL, 
            0xCD25589676D5C1D4ULL, 0x31B508841A94F74CULL, 0x8869D42F4385B01CULL, 0x33C9AC2B305BA97AULL
        },
        {
            0x6AD012F71473E3DDULL, 0xA20B7E4BCB8EF022ULL, 0x120D9998A1FBE78EULL, 0x66BF51ECFA5A9565ULL, 
            0x58852400CFB9C9C1ULL, 0x08277284ECC8C542ULL, 0x4558D50AC936B9DFULL, 0x0474E141DE60E07CULL, 
            0xEF4BFD2804E9207CULL, 0x47CF1BFAAAAFBA00ULL, 0xC0058763FD322275ULL, 0x0F7D19E85CFEB895ULL, 
            0x72FFA4564015CFFEULL, 0xB06EE06F6D591E04ULL, 0x9541D108ED4310E8ULL, 0xC600D604A40648DDULL, 
            0xF6296B4A2009B5E7ULL, 0x0E5D3297BDD32A47ULL, 0x9104C5642501CF6FULL, 0xEF13ED39ACE4658EULL, 
            0x177EFB7C308B106BULL, 0x959617CD1BEF15D7ULL, 0xC46766025649F47CULL, 0xD1331BDF05E1BCD1ULL, 
            0x3A390D10015D3CA4ULL, 0x6A22FB90D06A254BULL, 0x69B660E20D455DADULL, 0x321052946F32143FULL, 
            0x1A5D1E06046BCCF6ULL, 0x762E99136CE3DCECULL, 0x034B6A45FDF0EDAEULL, 0xBBB3B425663EB8A1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseDConstants = {
    0x4CA81A15C7F7F17AULL,
    0x5EE927FD01978635ULL,
    0xC538E1F0ECA9773CULL,
    0x4CA81A15C7F7F17AULL,
    0x5EE927FD01978635ULL,
    0xC538E1F0ECA9773CULL,
    0x56486F638ADE9175ULL,
    0xD7DDB73ACD677E14ULL,
    0x9A,
    0xA0,
    0xD9,
    0xC0,
    0xE8,
    0x01,
    0xC7,
    0x93
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseESalts = {
    {
        {
            0xB7A009D0DACFEA13ULL, 0x2AE09C25CC857C73ULL, 0xD32844B4AB26AAAEULL, 0xD356AE41EFF9F27EULL, 
            0x969785649F2C0115ULL, 0x44FE5D377AF7A45DULL, 0x92B9C006D456A0D7ULL, 0x0820D1D07F885B40ULL, 
            0x7A188C8D4A337378ULL, 0xA0E8B24E6405B011ULL, 0x663D63C691641F30ULL, 0x1310B45C423E5F1DULL, 
            0xBE3BA4B1115D057AULL, 0xC2BF71DC4D221FFAULL, 0x1519DDFAD09106EDULL, 0x45B9CA831624FD98ULL, 
            0x95D75ABD0BBC2436ULL, 0x60460580334C192CULL, 0xA0406976048D0528ULL, 0x19F44FC35E4B6F23ULL, 
            0x0B2EB7D06442D29AULL, 0xE055E7D96B9CCDFFULL, 0xAC700DBE9F87B2DEULL, 0x7473A3DACF39A12AULL, 
            0x0B51826589E6F89DULL, 0x1B428DC05F057DE0ULL, 0x8143E23482A421B4ULL, 0xE3F803ADC83FEA13ULL, 
            0x628877A793C89772ULL, 0xF2B7BEF5BED8FEA7ULL, 0x1C5728362610B21AULL, 0xBBBE3E48D63E8D5CULL
        },
        {
            0x7AC89D4E2B53A6FCULL, 0x2CE25E775E0EA1AFULL, 0xA5D7C4C765B3E63CULL, 0x23D3EC4764A0A75AULL, 
            0x969177FE5FAB8F5FULL, 0x8E3277B05C62978CULL, 0xA1D0D64903FE39CEULL, 0xAA71BA117394B357ULL, 
            0xB703DC5AC5375D40ULL, 0x9753630E82E77EBAULL, 0x6273C03E87465B57ULL, 0xEF07F083A56F6B5AULL, 
            0x7042595C7C28AA11ULL, 0x3F435089E88EE270ULL, 0x5081710A585EF59BULL, 0xE1EED7B636052981ULL, 
            0x683ABE616C1B137FULL, 0x9B8533E4536E0FE0ULL, 0xB0A0941F2BE4B1CAULL, 0xC63E95F3319A9DB5ULL, 
            0x287B4105774E47FFULL, 0xE0C7D0CEFF529178ULL, 0xA59BF6659087FF6AULL, 0x03060C7C11ABCDAFULL, 
            0x9B8B8C3C041DAB1DULL, 0x0F511E09E15C1858ULL, 0xC13F10766A936C18ULL, 0xB35BCF463CC01E8EULL, 
            0x31AA5DA449FD25FBULL, 0xA48D0B2C2AFAAAE5ULL, 0x00B12A1B76AC2BF6ULL, 0xD8270B29FD35731BULL
        },
        {
            0x6DBC3CFE67B2CA13ULL, 0x200AE58A4B6165B9ULL, 0x89B5B2FF51479306ULL, 0xE69816B2EAB7E76EULL, 
            0x8D95C5D20DF1D457ULL, 0xE48DA662321DB47CULL, 0xFF27F9901A76810BULL, 0x52E39B2AD4B98728ULL, 
            0x624D457BD2B23DDFULL, 0x2D49FBB3B3764F35ULL, 0xC36051FB53C4CCA9ULL, 0x9ED0805464D95739ULL, 
            0x600E32F59C47ACD5ULL, 0x00AFFE1CB944569CULL, 0x39B56D34EDB42A66ULL, 0x945BC12681AE16BDULL, 
            0x41B72EFA02597529ULL, 0xACBA117F0E0098A7ULL, 0xBB8DAACD9E123BC4ULL, 0x4F57656CEA4F7D7BULL, 
            0xE513BC3CD12B1D29ULL, 0x368AEC4544974FEAULL, 0x81798DDF63C2AC34ULL, 0x2AF778B9EA312913ULL, 
            0x17D1DE10524AA3B9ULL, 0x5E9A40B2F4E81EF8ULL, 0xC8EAD2E0B8C178AAULL, 0xD17D8DD11D5C793DULL, 
            0xC5AFB2988FA7A39EULL, 0xCC49CCA528334FB1ULL, 0x020E5EAF17C6D62EULL, 0x5F2EC7CB5C7835C5ULL
        },
        {
            0x67CEE0E8B596E772ULL, 0x3AC26E3634ABF1C0ULL, 0xCC7F82E0C3485446ULL, 0x30166FA42981B15BULL, 
            0x34C14331B335AFA0ULL, 0x1631B4FF0C39BA4CULL, 0xEEFF936CE6076F2DULL, 0x15461AEF5BF1870BULL, 
            0xE301B55C06F82930ULL, 0x9FFC5B04F13BB76FULL, 0xC6C6012AC5434B8BULL, 0x9030DA5694169AE2ULL, 
            0x5C5292E1EB41728BULL, 0xCEB783612AEA33C8ULL, 0x1F0242B087A2ECFBULL, 0x16F1C42FF5DA4668ULL, 
            0x5FC6AAB3F0582C42ULL, 0xC3B7F217E4B4838EULL, 0x19C724D9F987A429ULL, 0x9436ABA617F72D03ULL, 
            0x1D9FA2DCC5D19262ULL, 0x0B739A8FA38C79AEULL, 0xBDFAC1C86F6C3F0EULL, 0x46A1D27EADBC419DULL, 
            0x4C01C8CA55D9720DULL, 0x2C450D394C60B748ULL, 0xEC061C0621F1BF5AULL, 0xB79C259E87AF1CC6ULL, 
            0x9BAEFCA2606A7A2BULL, 0x18E91F7914177F24ULL, 0x5E313160315C547EULL, 0x6D5E339DEC8DC414ULL
        },
        {
            0x076C6BBA361C7653ULL, 0x7EF8202931CE974EULL, 0x4E9FAD7D78E54FCCULL, 0xB34A74E82610097DULL, 
            0x3AFB25D3ABB43AC8ULL, 0x738E4DCF4EAF967CULL, 0xF7F3F7B85A467430ULL, 0x5C07EF7CBF0000A9ULL, 
            0x506EE3DDCE4FDDA2ULL, 0x32C81550A710A366ULL, 0xFF0E74AF9D8DDEA9ULL, 0x926E0A6AC399B06CULL, 
            0x755844C5E99136CAULL, 0xBBA1B3F25F0CB53DULL, 0x558CEBB63DE14FCDULL, 0x3FDDE98ABE54728FULL, 
            0xD26A013D404BE3C2ULL, 0xA16E2B2949AFBFB3ULL, 0x21ADCEACD997A54FULL, 0x3D19C4E26047732FULL, 
            0x219888981AC3752EULL, 0x3E950289399395F6ULL, 0xEB125F2D96AAF57EULL, 0xC273224D53540908ULL, 
            0x96687574C55737A9ULL, 0x3D793B6FB37C7EADULL, 0x19E9CE9595176725ULL, 0x772B55857437452AULL, 
            0x2E39309F5443A299ULL, 0xE042BCF7A26BB38FULL, 0xD05081FE8FE85F0FULL, 0x06164933F710F5A5ULL
        },
        {
            0x20E475B51D6A7ABAULL, 0x73F13B1B90F397F1ULL, 0x2F2EE8212D7197B9ULL, 0xFA917F4F5A195C8EULL, 
            0xB5A285E49D60E151ULL, 0xF0948C5260191803ULL, 0x13DF101E8E008904ULL, 0x27D99D0D896EA0E6ULL, 
            0x7F6FBDC632E9DBA1ULL, 0x53151308C84A856DULL, 0x23FB376B07763D70ULL, 0x83D8CFD34B891040ULL, 
            0xD9E941D6AE027646ULL, 0x2727DDBA46610AAAULL, 0x3B34E90253801A11ULL, 0x965BD9FE01C196C1ULL, 
            0x6600399EC973270FULL, 0x8739F556D55E6DBEULL, 0x304215829BAEDA80ULL, 0x2E825C5D431C88A1ULL, 
            0x13576A9AAA2445FBULL, 0xB87AA17AE77D2859ULL, 0x0C94ABFB85409A46ULL, 0x0EF1DB5814355556ULL, 
            0xB7FE0AC17DCD8D59ULL, 0xE565940AB12E88D3ULL, 0xA4A856E54D267ADAULL, 0x142C96B0378DA337ULL, 
            0x6BBFC7BDC56AFBB4ULL, 0xB8CDCFE926B1B8CBULL, 0xDF583687E2B1845CULL, 0x6A6774E3C8D68A70ULL
        }
    },
    {
        {
            0x8BA7DD27CB8FFE9DULL, 0x18B0A5F7E77E55E7ULL, 0xCC28EAD6CF85EACAULL, 0x287DE5D480C66BF1ULL, 
            0xA365F7B6B39AF8D8ULL, 0x3FB4B50B273C26ADULL, 0x96C33E65CCE3EA7FULL, 0xAED3460EECFD1D48ULL, 
            0x54CAEA7245BEF36FULL, 0xE10AF4FBD2713142ULL, 0xC53CD674BAC8231DULL, 0x46A1F9330E2A4C5AULL, 
            0xF9D99A5DC29D003DULL, 0x9B57AB08B690F0EAULL, 0x139B5C2BD1B4D9A4ULL, 0x3AC221D3ADC507EBULL, 
            0x37A4F8073538D1F5ULL, 0x2109F50624E41929ULL, 0x219CCB683B40ED25ULL, 0xBB44950E9747D40EULL, 
            0xAC98885749D315D8ULL, 0x7A4931F368364D42ULL, 0x0A40385A753CCFA7ULL, 0xA7BB8CF373D0BDBAULL, 
            0xEAAF4501699E6CF1ULL, 0x6CC81D2CD6D0F816ULL, 0x5F606916086EF347ULL, 0xD2B16203F84B1EC0ULL, 
            0xC543481D24BE1BFAULL, 0xCC9678B1A3B2E781ULL, 0x4A38F44066715ADEULL, 0x91E47CE413DB702FULL
        },
        {
            0x0960B2C1484BDB25ULL, 0xD299E2345D7AB288ULL, 0x0C670FFAE79563D3ULL, 0x64CB4C67CA1EDD06ULL, 
            0x2838618B0BA3774DULL, 0x7DE811E990629FD7ULL, 0xBA23E6049C471BEBULL, 0x013C87F565C3829DULL, 
            0xEBDA67EE112FF1F3ULL, 0x5A68AE65CDDC839DULL, 0xBA28283E96F9DE17ULL, 0x7A8FFA5E7A69A6A4ULL, 
            0x35A4E02ED18D6514ULL, 0xB165324CB7AA74A6ULL, 0xCC32E9D54786C1D2ULL, 0x0EBC8C98F5758593ULL, 
            0x847A3E4E238E4384ULL, 0x884FBD0E8742B82DULL, 0x3048B22335FFEB01ULL, 0x834083200897C008ULL, 
            0x8DB739945BF37E50ULL, 0xCEB4C0512C83D67DULL, 0x180EE62F2AB8B8A3ULL, 0x170B8902FA36E578ULL, 
            0xA14F38A80EDAB8ECULL, 0x4B186C06B96257D1ULL, 0xC7F9682DF041C160ULL, 0xFFCCC4C73F4D3E9FULL, 
            0x77F016DEAD8C7928ULL, 0xD05D039AE0A34280ULL, 0xCBE94B226B49627CULL, 0xD38E64CC8CD804EFULL
        },
        {
            0xE09E4AE54B5072C8ULL, 0x42AFE4F223F7D170ULL, 0xDD5CAA52ED491D27ULL, 0x03D8338F5D6708D3ULL, 
            0x65D6E4925EF9B3EDULL, 0x1DF7EFE7FA56A3CBULL, 0x270744B6C87598D5ULL, 0x3F59411A165DDD1DULL, 
            0xE0B8539413FFA880ULL, 0xA47A0B876D5B43B7ULL, 0x369001F50AAE9E02ULL, 0x42C950BF53FE415DULL, 
            0xC435DA79DB482E77ULL, 0xEE54D71CB2A49F6CULL, 0x2B7656CD4AE28A68ULL, 0x9C181B6586E2D708ULL, 
            0xCCF4521076D42ED9ULL, 0x085A3B5FA6967D80ULL, 0xC1E35C7DBCA58C72ULL, 0x48F475C71349D7D1ULL, 
            0xC34FE37D19007856ULL, 0xB042B6C35EC743C6ULL, 0xDC5277FDB8D74618ULL, 0xE3F5537BA36A5BF7ULL, 
            0x4186B5EDF75089A6ULL, 0xFF9501D4E007E08BULL, 0xC6D5E7E742474006ULL, 0x9E1959D788983B1AULL, 
            0x232D5F444DE211ACULL, 0x85BABDCAB13E2545ULL, 0xC7CAFF682409514DULL, 0x6752F781BB1AD5B0ULL
        },
        {
            0xD069BEFE6B5134FEULL, 0xB572CDB7AFB06CFDULL, 0x3200D4E2C5898930ULL, 0xD842B1DF710D5107ULL, 
            0xFDC2D619F04F03F0ULL, 0xFC4F6FD16BDE505BULL, 0xEBA3BC79FF569CD0ULL, 0xD5654BE8FDA99B15ULL, 
            0x113B6E6CDD301B57ULL, 0x8CFCB526841D6EB7ULL, 0x63ED5DCF47646628ULL, 0xEF4113FE476A50F3ULL, 
            0x6BE9B657BB753572ULL, 0x560272A938EE9C86ULL, 0x9C88720547B52287ULL, 0xC52C0526AFBD894FULL, 
            0x39B55EAAD38202A2ULL, 0x87436C34417FD1C0ULL, 0x665CA17D1FA918FEULL, 0x26F2F2A6D6501C8EULL, 
            0xB803E8AD4DF8AAA1ULL, 0x0DBF58AEBC6D98AAULL, 0xC0B516991FAD443FULL, 0xC7E573E951323140ULL, 
            0xD27310740B7B49B3ULL, 0x33DFDB9B6D68013BULL, 0xEBF79A5CBC243174ULL, 0xE6147803B53FB96EULL, 
            0xF7AD5140884F5D89ULL, 0xAA48326E919ABDBEULL, 0x8C1786C593180FB9ULL, 0xF49C6F8E258D8782ULL
        },
        {
            0xE47472B4F4F20CC1ULL, 0xAE50EC6C41B27A2AULL, 0x49643EC5FF1934A9ULL, 0x3D6D7AED085F9673ULL, 
            0xA164A32A405B5616ULL, 0x84E6C2C9FD7A2463ULL, 0xA9F5684498837449ULL, 0x3AB2F6CD610B6C36ULL, 
            0x038B87D009ED3526ULL, 0xEF2AA6E083C166A9ULL, 0x3E6B4D843242C3BDULL, 0x4771717D4673F5BBULL, 
            0xFBF5573E3DE10EABULL, 0x71F276B53A610BDCULL, 0x85B6B4DC7C478FB3ULL, 0xA5E267A2F8EDE534ULL, 
            0x1F44FA721ED9B005ULL, 0x34FA9CB533CA96C5ULL, 0xFF176009A56A6E43ULL, 0x18D70C5B06E76F27ULL, 
            0x1F7EBB4784E05CFAULL, 0x7C468C17879BC6A6ULL, 0x8B9794CEC193A822ULL, 0xC4563858A963C178ULL, 
            0xD691FEF7B6BA367BULL, 0x983596A8BB966BCEULL, 0x5C9A46EE2BC9CA66ULL, 0xD8FBFD45DE3BA9DCULL, 
            0x140FB190EE8781F4ULL, 0x513B58E6340DA5CCULL, 0x2833D7FE76F0490FULL, 0x61FC036CC26BE70FULL
        },
        {
            0x51EE09BC143D56E4ULL, 0x7163E704C77EC9D6ULL, 0x71CD366872A2C77FULL, 0xD2CA2861A4EB5E96ULL, 
            0x599EB3BC2F83EDC2ULL, 0xE62A96A0B8857D67ULL, 0x54BA28339C728D57ULL, 0x489A4B01FA74579EULL, 
            0x89227960556B88C3ULL, 0x144F5B7E5679F764ULL, 0x16FFFF18DE1339C3ULL, 0x65E04E8644EADD37ULL, 
            0xBAB747400F1CB4BAULL, 0x7A8BF9518203405BULL, 0x31B65FA34E5DDBF6ULL, 0x783C59885E2CB5B9ULL, 
            0x08F146A0A24989E1ULL, 0x54231B018FF89E8DULL, 0x889D9DB3603690BDULL, 0x5288EA9A155EEE00ULL, 
            0xB0384F1BE98298CCULL, 0xDB1A0FE25B8402E7ULL, 0x37D587D165EEB99EULL, 0x4C6E92AE33723109ULL, 
            0x61B59CB7EE53F5D8ULL, 0x34826CF547C0818DULL, 0x3101AD21AE5066C2ULL, 0x6E21113EB3AC1B5AULL, 
            0x4C29B87C021AD884ULL, 0x16843ED840472BDCULL, 0x91BDB2DDBA616A4EULL, 0x34FE456AFDED5FDBULL
        }
    },
    {
        {
            0xC6F651B1BA8E24D8ULL, 0xA3C16609A161E7B1ULL, 0xC48DCBDA846E743BULL, 0xBD4E684B9C1F10E2ULL, 
            0x11A68FB9F74F5D61ULL, 0xA45E6F85DAFE5DAEULL, 0x4FF98A5F06C6C6A0ULL, 0xF1FAD08624E788DFULL, 
            0xA0357E09DEA27AFFULL, 0x8B693159EE28B6F4ULL, 0x6AB8FB72D65BFB13ULL, 0xC7E66F86F2BB0A0BULL, 
            0xA847B9E090F6242EULL, 0xB4BDB67AF3C5FD7AULL, 0x2B49F3B0977DD703ULL, 0xB98FB7D2EA3DAD20ULL, 
            0xD39B4D373CC25999ULL, 0xFD542238781D60B4ULL, 0x2604E770869BF325ULL, 0x9EF4FEDD789CDFF0ULL, 
            0x3635FC039E39B2E5ULL, 0x5EB65747330368ECULL, 0x901AAC64765B12C5ULL, 0xCB6E084F15E33447ULL, 
            0xB50D3AD5DD82B90DULL, 0x574CC6C33507FA0BULL, 0xBE086D0910AC33B4ULL, 0xE4928EB82B701BFEULL, 
            0x2A5D0F8EE4B6804FULL, 0xD6091373137FC3D4ULL, 0x5842767AED7A5986ULL, 0x25DB0450E71E4D01ULL
        },
        {
            0x1FCD03F3CD1CE461ULL, 0xD1CE535DD4AAAB5FULL, 0x13499C3146C4154EULL, 0x01C822F07777AEA1ULL, 
            0x7BDB57802645800EULL, 0x5B7E035499361F45ULL, 0xC0EA37408E182EA9ULL, 0xF38284DE451522A2ULL, 
            0x207C691C849F14F1ULL, 0x1D99882566D838B1ULL, 0x4148021EFC9909D4ULL, 0x78C9639BD1CDEC5EULL, 
            0x9B7E82CC1E70038EULL, 0x85A82438C99968E9ULL, 0x49EE53C66A50E893ULL, 0x14BFCC47324993E7ULL, 
            0x320B35652E50DB85ULL, 0x832B4B1A2CC5C3DEULL, 0x67018D4FB1FE3CE6ULL, 0xC30FB3B67384D25AULL, 
            0xDFEAA59C96201DF0ULL, 0x36C87CD1A6400AFAULL, 0xD2EF785292044280ULL, 0xD96498C8C1A0FCE1ULL, 
            0xD03851F6DD59E5C8ULL, 0xC2E67105154AC9DDULL, 0xA7C5DEB80E3A9942ULL, 0xECFFCAD7E5F7D4B4ULL, 
            0x3FAFB2D09B84FB58ULL, 0x76CC91E3E0FAE4EEULL, 0xA891683BAD7E653EULL, 0xB94DECBA2DD86991ULL
        },
        {
            0x68D5BDEBB26B0EE4ULL, 0xBDC6315BA58171F9ULL, 0xEBDF9DDA614A50D4ULL, 0xAE080DDD258D7405ULL, 
            0x97689A6D053707D3ULL, 0x0D668A330090E0EEULL, 0x7D8025E19D71AAB9ULL, 0xD5C581BE73F323A9ULL, 
            0xFE58E4234C87A55BULL, 0xF68B203D51A67558ULL, 0x8E815E2AF273CB6DULL, 0x77A1EA11B05D7E53ULL, 
            0x7E148434B0BB1DECULL, 0xB1EE1F013A879022ULL, 0x49E5A1319670DD0DULL, 0xD13EC83AD099DCAAULL, 
            0x2C0127F25B667E49ULL, 0xA301A923DB8DBB6EULL, 0x9523A29B78FDB1E5ULL, 0x4A681E6ED775B08FULL, 
            0x7419FB88D0F27D33ULL, 0x8EAA6DE56E9A2218ULL, 0x5E155623AAFF8B23ULL, 0x00A0DD7E1039D56AULL, 
            0x11CB70C87637FDEEULL, 0xFF3C511CB005C757ULL, 0x4E91A8B7CA4D3170ULL, 0x3AE55359FE3915FFULL, 
            0x5FC4A3114A90F6FCULL, 0x2F73679F505DF810ULL, 0x99346850FEE385B2ULL, 0xE79340E90F355538ULL
        },
        {
            0x3567C80034C10037ULL, 0x7A0683A608D53D6AULL, 0x01506FE47B2E4E25ULL, 0xEB6BFDDB5733A1F1ULL, 
            0x389D4C418BC12F18ULL, 0x07E50DBC7374B5F0ULL, 0xD61B742CF208B560ULL, 0xC276C97DB5582254ULL, 
            0xCA86E76BF99E4CBBULL, 0x2D5E1CC175345F92ULL, 0x853390926BDB6231ULL, 0xBB28F38CB8ED6627ULL, 
            0xBCBDF936A22289E3ULL, 0xE7647932BD4E9432ULL, 0xA8C09F5112ACEBD1ULL, 0xA428E8FE2D1660C7ULL, 
            0x949AC1D40D8D92EEULL, 0xD81EFAF6DF7F19D3ULL, 0x1545FCF1AEA5DFCAULL, 0x78D74272F3A4BE2CULL, 
            0x0877E9451E318912ULL, 0x5BD898BFDD10A471ULL, 0xC32979974A661A4CULL, 0xCF562D987E60B36BULL, 
            0xFA57C2EA9ADEC51EULL, 0xFB235F6AC77AD42CULL, 0x79446604D7E79CAFULL, 0x7EA8EF71AFD2DBC2ULL, 
            0x53411BF0C5569D2BULL, 0x230053790239251BULL, 0x9446976301B2FD47ULL, 0x6A202A4F220D877BULL
        },
        {
            0xB0D23081D2855F25ULL, 0x4789AAED6EB4EB5FULL, 0x37AA1C0A37A5F056ULL, 0xF4D1DA5A5A6A7D50ULL, 
            0x50A9D14F50EB2894ULL, 0xFA05427D5CD213E0ULL, 0xD7BED2F2CE46A9C6ULL, 0x822D4770876E4463ULL, 
            0x5002B6D2CBD88C84ULL, 0xBF4AAD128C95A5A4ULL, 0xDE999E1D75616BF1ULL, 0x55924C7A1CF53E00ULL, 
            0xBA94F3F5AED4053AULL, 0x1C1F8AA9525CF4CBULL, 0x659410D37F8D7B54ULL, 0x2E78EE6FE8C1027DULL, 
            0x237EA216341478FAULL, 0xA252763E34996F12ULL, 0x4724E217DB75BBD8ULL, 0x7069ABD4AF719179ULL, 
            0x2EA2C0D1FCA463BBULL, 0x27BB09821C9E2387ULL, 0x293299D7F012EEF6ULL, 0xCE2F01CC2C4DECB3ULL, 
            0xC665E8E11400CF9BULL, 0x4C15CAAD41CB74E9ULL, 0x721348FCE4AB8511ULL, 0x03E62BD8374137AEULL, 
            0x2B7E7097111C9D3EULL, 0x912DABC1150C710BULL, 0x786EF766700CD80CULL, 0x3DEDD9BCE5BC3381ULL
        },
        {
            0x45236B3D7A713C2FULL, 0xE8F68B755B0AA2B7ULL, 0xB4B5A22EE1AD3358ULL, 0xAAAA0A7E3C0ADFD2ULL, 
            0x35DD3883CB5B1324ULL, 0x2DD7F29C308B6130ULL, 0x5BDDB243D7BD6D37ULL, 0xDC72D13E0385FD3EULL, 
            0xB364FD694313BFBDULL, 0x9A5E5073D4E70353ULL, 0xEE6009E3A9966482ULL, 0xB17E1DAF7A77B84FULL, 
            0x60B2A8EF17E56B5AULL, 0x70B5DD6BB2C2F7EEULL, 0x849DAA3D290B1912ULL, 0x66E0F7754999E470ULL, 
            0xCFFC717DBAAB3AD2ULL, 0xDDCA98E9C596A829ULL, 0xE04438D565BF021AULL, 0xC28F09531C4F7D0CULL, 
            0x6FA700744D8AB334ULL, 0xE369C4F4E051126AULL, 0x0F7C24527C8DD36AULL, 0xB2C225584CD67542ULL, 
            0x1D995685D7B273D9ULL, 0xBD45B91051C74E7DULL, 0x865F52407BFB7662ULL, 0x6A9D7E80B75B0C82ULL, 
            0x00BF790AD119234DULL, 0xD53DE162532E5015ULL, 0x618D35F589E62E0EULL, 0xF148B1C30B3AA26DULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseEConstants = {
    0x98075EB533DEF82BULL,
    0x0AB059FBA426D51CULL,
    0xA6DFF57DA3F2C851ULL,
    0x98075EB533DEF82BULL,
    0x0AB059FBA426D51CULL,
    0xA6DFF57DA3F2C851ULL,
    0xDD94F660874C83E4ULL,
    0x5E6FDCE3386558B3ULL,
    0xBD,
    0x4B,
    0xD8,
    0x83,
    0x28,
    0x56,
    0x34,
    0xC3
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseFSalts = {
    {
        {
            0x7AB0532FD8EAF96DULL, 0xB30A89A539C2D9B5ULL, 0x704A4F6C4601618EULL, 0xD6867F4AF28C49CCULL, 
            0x76E0B0D76742A9EAULL, 0xEF5FA32549213E91ULL, 0xBB1DB000E8A4AAA4ULL, 0xC4FDC32748D6D660ULL, 
            0xB99F32F32CEAE9E9ULL, 0x7F068D9CD11496BDULL, 0xDA6F574BA077B244ULL, 0xAC73EF883AE6512AULL, 
            0x5C12A7114A7C3BA7ULL, 0x7B552DB9383DA058ULL, 0x3FAE7E1556E09EC1ULL, 0xA16E13F4AB598BD9ULL, 
            0x9A477E763BF7829FULL, 0x0984085FA28F8D71ULL, 0xB68C2AD695B3D04AULL, 0xFE2C3B22FDC05458ULL, 
            0xF1C05B6F27AA97FDULL, 0x8FED505FB726C40DULL, 0xB228103EE9A9DE49ULL, 0x5DFB7BA547F52BA2ULL, 
            0x191CA1BC9F3B75B9ULL, 0xDB2A58F0834D84D5ULL, 0x3D63185D0DECAEAAULL, 0xD968B4C5559DB88CULL, 
            0x1EA4B5C9D73EA28CULL, 0x022DA2199CC69523ULL, 0x0ED4AE02CD728B20ULL, 0xD1CE3473E00B17E0ULL
        },
        {
            0xAB0BB328702008EFULL, 0x009517D0C18FC02CULL, 0x00E6C28D0D285FE7ULL, 0xDB56C766F94B80F5ULL, 
            0xB979B31A30A5F448ULL, 0xAA08B348D623EAC5ULL, 0x867784BC0EDF53DBULL, 0xF708C6A6B1F76BC3ULL, 
            0x4C04415BF1902BC8ULL, 0x6AFF8F9E9F0503FDULL, 0x197B7C536034AE4EULL, 0x8EF148788B2C9D6FULL, 
            0x4AEE0E9C120D8168ULL, 0xA5AEEEE500F3EC46ULL, 0xF41C7BE6AC36DD21ULL, 0x8AA7519D4075E52DULL, 
            0x64471DB6654F99B8ULL, 0xFACF4051D4FB0FF3ULL, 0x333758A5031B84DCULL, 0x1246669B0A4D9F20ULL, 
            0x8CA7B7856840EC0EULL, 0xD8C921EEF1FCAF05ULL, 0x4EB44B08B869EC9FULL, 0xF0717CB3D76D4FF5ULL, 
            0x95BA57D32123CBE6ULL, 0x368C895720EA08FBULL, 0x257B8799E0A1B10FULL, 0x45F02B4BE3A68A9FULL, 
            0xF6915D47D764D414ULL, 0x15D91DDEAA9DC26BULL, 0x27C5C4DCEE928FF2ULL, 0x483EA2FD033CB27DULL
        },
        {
            0x7B60978FA5A5828CULL, 0x96C2989C89A98AB0ULL, 0x28CA681E4EDFA2ACULL, 0xD54DADF99F7E9123ULL, 
            0x7EAC721AEF68EAB0ULL, 0xEFB4A5D8CFE5EF91ULL, 0xF956D8DDD6EBA8B8ULL, 0xABF080A0DE3FAB47ULL, 
            0x380DA182D0AC34C3ULL, 0x9CDAA8DA73B83789ULL, 0x2FE64E5F2DC18C45ULL, 0x8804F5EF3BDCD024ULL, 
            0xA9897199EB5AAC45ULL, 0xC8F1959DCB82CF34ULL, 0x2A07C6FCBEC81FFDULL, 0xE473A188DE9990A6ULL, 
            0x9DBA84D2B8C19817ULL, 0xF0804941A6119291ULL, 0x65F609ABADC619C0ULL, 0x323FA8B57E2F1E11ULL, 
            0x28F6BE085F11AE78ULL, 0xE8717B676B0373D4ULL, 0x8D79188A4ACA5FE2ULL, 0x96C36FA0FBF95332ULL, 
            0x1377EC5D96A043D4ULL, 0x4BF51F4657AF4F16ULL, 0xEBBB8D028173F9DAULL, 0x13936295635EB997ULL, 
            0xEC9FF9CC7BF96388ULL, 0xA6B542AD37613D2CULL, 0x59175CFADB9C9720ULL, 0x4BF6C801B3006A0FULL
        },
        {
            0x52C668304335DC1BULL, 0x210ED46E254CE480ULL, 0x00BBF99D7302C57DULL, 0x360123C0A46E47C9ULL, 
            0x34B3BA154D154058ULL, 0x6ED50B3B839698E6ULL, 0x8D58886C02CAE7E1ULL, 0x3DB0BF8F90D2E96DULL, 
            0x07D1C724AD99ECD3ULL, 0x7D23327641DB6EECULL, 0x8A5540E038EB83AEULL, 0xF236362A7CA82852ULL, 
            0xE44E6985954C85C0ULL, 0x20561866C9319650ULL, 0xC62F6D2DD3296745ULL, 0x9593AA7C0C8DACD2ULL, 
            0x3D085AAB5E6375EDULL, 0x41ABD444A06FA81BULL, 0x43116DED3848F81CULL, 0xD9F925F7359974B9ULL, 
            0x45FEDCF724F139CBULL, 0x89ECF5FF4A1C7E29ULL, 0xFB71CA5FF0B2A459ULL, 0x300D697CAA1C2D16ULL, 
            0x3F970D1BE97F5165ULL, 0x3B59711ECCD52F58ULL, 0xA865A52F5F2817A7ULL, 0x52A84CD38822377BULL, 
            0x85FE8EDD45918474ULL, 0x7F9804CC57207175ULL, 0x2D28C95BC83DD357ULL, 0x3B047A5350D106D6ULL
        },
        {
            0xBCDEEDFE16D80777ULL, 0x78A27E36E2841B23ULL, 0x82519ADC8FE14458ULL, 0xFA0007ECD685867FULL, 
            0x0B3C7D5AB3745009ULL, 0xDCDF89C9A33E443DULL, 0x1224008F01D9A2BEULL, 0x8368A467564A399EULL, 
            0x80EC48C141DC3EB6ULL, 0x956C82D2B11E9245ULL, 0xF31542364ED987BAULL, 0xC4277A76863C7C90ULL, 
            0x2B3D7BAFA4C590F3ULL, 0x76AA26D8BF3186D7ULL, 0x7919129CBDF60733ULL, 0x2ECAAC2B0E0F647BULL, 
            0xFBD3E1E1D226B162ULL, 0xC42608CC21A774BAULL, 0x951F292720FDF1B4ULL, 0x909B3FDC56A10C40ULL, 
            0xFCC673B48288E2ABULL, 0x30B248E51E8484A4ULL, 0x7E17FCCF11743367ULL, 0xA7FB93576C468ED1ULL, 
            0x6E401F087B142121ULL, 0x3B2026419DC4A26FULL, 0xCD55A4657431A1D4ULL, 0xC4E14DE272533962ULL, 
            0x83B87B41F27F4506ULL, 0xE9681227D9F7E13DULL, 0xEE9A0CE4F984634EULL, 0xDA9D506AF2A91747ULL
        },
        {
            0xB2DA193EAF9D3502ULL, 0x3BE4DF917E57910DULL, 0x97D1563E8D06EC37ULL, 0xC3E58E13D072E1EFULL, 
            0x33927315BC19FD68ULL, 0x5866CD8C583E723CULL, 0xCE2D60B6AC211D4FULL, 0xEDB1CDBE0507207DULL, 
            0xE4D11B9AB69E1BF3ULL, 0xB3E8187EFF534007ULL, 0xDA36746905239802ULL, 0x62570BA9D9BD25E9ULL, 
            0x21B4E91A4D224F57ULL, 0x05DFE09BE1973C78ULL, 0x87567328F28F0B5FULL, 0x1C61CADC5CE748F4ULL, 
            0x911B7D8A1D3A6F59ULL, 0x919F3039775C1968ULL, 0x0CFE766F5C90A1FBULL, 0xE7931874E2793703ULL, 
            0xF9D7571B6DD6DEAFULL, 0x05BEB56160CC7EA2ULL, 0x0E7BEA0E95D2FE66ULL, 0xF282C1409039D809ULL, 
            0xD41A03C3E52B9BA0ULL, 0x7EBE4C5182B7D63AULL, 0xE1E9A153789164B6ULL, 0x2E3189AF75D77AA1ULL, 
            0x4394CF64B420F7D6ULL, 0xEFE9BA3A018371B4ULL, 0xAEBFAB138799904CULL, 0xDC92842F18988682ULL
        }
    },
    {
        {
            0x3AEBBE88810C2873ULL, 0xBD4F6CE0EC6B0C16ULL, 0xE95853910E321BCBULL, 0x7206ED202CBDA507ULL, 
            0x3BB83C92E90DA484ULL, 0x8CAB2E6F522C99F5ULL, 0x7646CA61E94FAACEULL, 0x67B7385C610FAC9EULL, 
            0xBEC07FB1643C3881ULL, 0xA647D2C401C9637BULL, 0x77B0263963071185ULL, 0x4F5019C0B2717D02ULL, 
            0x7ABA0C05E8F87429ULL, 0x28F3EC24483ADACFULL, 0xE7C1F6F47967EFD7ULL, 0x6056B45A6FFB7192ULL, 
            0xC318403EE3E22355ULL, 0x03A716B5C8B3B088ULL, 0x2D33534FAE7E4A08ULL, 0x6DB8B8E548FFD401ULL, 
            0xC115DA4062958F8DULL, 0xA053722B52B6EED1ULL, 0xF1D2BA719FA562C6ULL, 0xA9BF2C8BAF862237ULL, 
            0x2607DA34889E7FD7ULL, 0xAFEB9F41A1E4EF6BULL, 0x7BD685CAA86A3014ULL, 0x1A37F75D4110DFFDULL, 
            0x45BEB7F3C0CC27C2ULL, 0xB3EBBC47B51F7A5EULL, 0xFCC693F41682FAE1ULL, 0x9AFAEA6B843DFC86ULL
        },
        {
            0xA8A5582F0E1936C6ULL, 0x194FB8050DBFC115ULL, 0x652DF2EF9694C3EFULL, 0xDF6D23A28CDF0B0AULL, 
            0xD325C3447A3B8274ULL, 0x6489A9386BF817DEULL, 0x3EC57EB0C3A867F4ULL, 0xDC4918F5D9D6EF8FULL, 
            0x839E067D4C25E1E7ULL, 0x446D0E0A361B6CF6ULL, 0xB85F357C1FE073E5ULL, 0x466A6AD57DA33AE1ULL, 
            0x5FD5846A14EE5A3DULL, 0xDEE197E185491FE1ULL, 0xAFEE48C64AF2D51EULL, 0xABBC4B3E81E48336ULL, 
            0x8210099C25FB902AULL, 0x72D23416DC10CEDBULL, 0x48B24C1F324EBEA2ULL, 0xE5FC8C487993F513ULL, 
            0x76BA1E4DFEC79B8EULL, 0x2D0C1199F03C3383ULL, 0x477A783EB86898EBULL, 0x1D4FEAB6ED7AD283ULL, 
            0x72F52075F25D4A3FULL, 0x5784981AF3B0E5F1ULL, 0xAD1B4659F4A2C35AULL, 0x09114D1C52323D2FULL, 
            0x6F00DA1A1BE19927ULL, 0xB11307597F92482CULL, 0xD4F9E15F0B7FF6FCULL, 0xDFE2AB6490843828ULL
        },
        {
            0x4CA3DFA1BF1E4FF8ULL, 0xB55F589DAFC9467EULL, 0x3A8E544AA6CF85E4ULL, 0xF35CEA9C0FE40169ULL, 
            0x86EE9E5EE576CC28ULL, 0x89182B04652FF1F4ULL, 0xE07B9F3F4E025F16ULL, 0xB09126C1B4306C23ULL, 
            0x50738252ABBBB9A4ULL, 0x7344FFCC1691CEBBULL, 0x796A377EF62F9500ULL, 0xAB518458F3865800ULL, 
            0xEF8C2C743824F939ULL, 0xDF85F8E92E77B76EULL, 0x2AFBDF225EBA2A0CULL, 0x680DA46E285982A4ULL, 
            0xF252F52350AF3599ULL, 0xDFFBDF53D104BB79ULL, 0x71FFBA3445D381F0ULL, 0xC62D34BC8F388AFFULL, 
            0xA20268972044B667ULL, 0x2297C58BD2E98BD2ULL, 0x7F900F9549F25455ULL, 0x4012904D5E28C63EULL, 
            0xA87CF222EFD3EE02ULL, 0xD654EE232D8D37F0ULL, 0x5C46B1090539332BULL, 0xD935FA4E0485D212ULL, 
            0x374858E2866933C6ULL, 0xD892EF6605DC2468ULL, 0x6A86A0E11C5B2642ULL, 0x36F5D4DE4541C7C7ULL
        },
        {
            0x86A7E11880DFBF0EULL, 0x73AA740BF36893EBULL, 0xF9AE6FDED23523F5ULL, 0xE8B1D4D70C0DC105ULL, 
            0xE006F029BB30BF0EULL, 0xA6FCD96C439331DBULL, 0x52B30929BD60E7F6ULL, 0xADAB389DFCBF4D82ULL, 
            0x55219F0984ACBC7AULL, 0x4AFEC263D8B47FA5ULL, 0xE1F61C9A7DF446D2ULL, 0xF05A4BE0FF570F5DULL, 
            0x709440C450AEA4D9ULL, 0x8C20FFC2EA1085D1ULL, 0x4AE4879F27378BBAULL, 0x191F4E3807100E81ULL, 
            0xA017EBCF889D2FBAULL, 0xB4482B6EA7D5286CULL, 0x91A2821117D1FCD5ULL, 0x4904B2F9AFDD3923ULL, 
            0x72628442881678E6ULL, 0x8C3BC8F8D36C1709ULL, 0x75D9330E9C9B1B13ULL, 0x422DE04D52EDB3A6ULL, 
            0x89B94E2B3671CA56ULL, 0x06736892047BA1ECULL, 0x072E6502F409877AULL, 0xDA84CAC1CF3888ADULL, 
            0xC8E8F03C0F9C02EBULL, 0x76A805E34C839640ULL, 0x421FDFB47DDEE452ULL, 0x40DB72AFD02C9EE4ULL
        },
        {
            0x18D965048CF3970BULL, 0x44A3D80B915E22CAULL, 0x92A3F7B21E6F3A49ULL, 0x9133015AEEAFD4F4ULL, 
            0x39F91F70CC5091A1ULL, 0xCDFD13CA222C4945ULL, 0xF08BE16EB93F9EEEULL, 0x64C2942745FB3E60ULL, 
            0x46A152864EA1463CULL, 0x6C4108151A118361ULL, 0xE5D973C8043C3A0AULL, 0x46898621FCEED77EULL, 
            0x498F794E43202EC0ULL, 0x16333E046FE1150BULL, 0xA1A9ACBD5113AABDULL, 0x9AEDC9B978F9B489ULL, 
            0x8DE357E59D31820FULL, 0xCCD8804284E1AA27ULL, 0xCC1583068EDF7078ULL, 0x78B7FEB53AB8E19CULL, 
            0xFD1EFC9E1AC5C003ULL, 0x631E6E295D9443CFULL, 0x2D4455F684787892ULL, 0x24DD315BC8C61CA9ULL, 
            0x7D37CFB35C8DB01EULL, 0xFC971D4F3CFF13C1ULL, 0xC17C912BE6AA9BAAULL, 0x32E5D5E0A20F7F99ULL, 
            0xBFA4D409B12F79D4ULL, 0x815C2C27DE6A792EULL, 0xDF75D3D96EAD1C4CULL, 0x20073424CAAA2C40ULL
        },
        {
            0xB01650724CA350BAULL, 0x2462A6845056E90BULL, 0x7BD50C613E557A50ULL, 0x0C63CBDD6E71EC45ULL, 
            0x80D89F12678D0A76ULL, 0xCC8AFAC7DACC6B71ULL, 0x1FDBE8F2A87BE3EFULL, 0x4F4308FD3193038BULL, 
            0x537E1168FA9EB624ULL, 0x1F62BA83510333F6ULL, 0x23345357B907AF93ULL, 0xE5B4A02086B4CBD1ULL, 
            0x7E6C7AE12510FB3AULL, 0x0DA27B126B20BD18ULL, 0xEC494FE61F4A40F0ULL, 0x22CC2FE08C29FF67ULL, 
            0xADE62CA7CB6650B5ULL, 0x45026750184BF447ULL, 0xB9D873B0DB26F948ULL, 0xBF9F368B6B96C8F6ULL, 
            0xC0FF042F2DFA3159ULL, 0x01582572371A4FC1ULL, 0x11E031A53D2D2CC8ULL, 0x3C473978CF0A6E7DULL, 
            0x0D9A260CF97AC2A5ULL, 0x236AA5BCB641EA57ULL, 0x22E2E0E967465BDBULL, 0x619A40303F824439ULL, 
            0xB72C9013C1597FBEULL, 0x4A43B33A9443C2F0ULL, 0x9306BF418A6722A8ULL, 0xB040BDB7DD3DF097ULL
        }
    },
    {
        {
            0x065FF31679839DE2ULL, 0x7359AA6B2B39C5ECULL, 0xD5B9D3B24BF4A10EULL, 0xDBDAE429F1742223ULL, 
            0xF1ACD0714A80FE96ULL, 0x4BA4572BA41542F0ULL, 0x41EF801F48559B8EULL, 0x65AA456608959EB9ULL, 
            0x7A8D52DB7DC6F768ULL, 0x2AD577312BEE43E6ULL, 0x7C6A49AE1E36ABA5ULL, 0xF9492C3CB672B242ULL, 
            0xC84DC55E3A723710ULL, 0x06DEE2061D6D7ED2ULL, 0x0C41D42E12D92755ULL, 0x176CE3F385A452F7ULL, 
            0x913308987F222ADAULL, 0x50B2609F32720CDEULL, 0x6A2D3B2BF9FD5E71ULL, 0xEA6E41CD90A3A647ULL, 
            0xF25781BA07456E41ULL, 0x5003E43B8CFA6930ULL, 0x110D9FF41FCC9F94ULL, 0xC401CC733860C1BAULL, 
            0xFC376E0EA5EB6DEAULL, 0xFCDEF0E46516877CULL, 0x970F20680BD59477ULL, 0x3F07F1FA576DFBF4ULL, 
            0x53C353FA0A2560F7ULL, 0x0616C2ACBEA0DD22ULL, 0x518CC0FD0F1E2730ULL, 0x968DF5D10981890FULL
        },
        {
            0x11242145871E77A5ULL, 0x6B9A04164FFC59E5ULL, 0x797CB792A8AE1C75ULL, 0xE08E09F87783D028ULL, 
            0x9A685088043B4E1CULL, 0x80286E27671EA51FULL, 0xB305C36207FCA1F5ULL, 0xE905E2044DBCAEEEULL, 
            0xBEBCC8097D46120BULL, 0x5C3E791390AA6889ULL, 0x0E2AE9F1331C980EULL, 0xE9E70186B16D48B5ULL, 
            0xF8E46C86BED21FC5ULL, 0x2DFF57C71B9B43D3ULL, 0x6D330BC70F334D3CULL, 0x3D6D84861B938698ULL, 
            0x9C8302C1F3DDC4E1ULL, 0x3B3B0252B77CD6C3ULL, 0xA832D3C02A465880ULL, 0x5D243E9816C8EFC4ULL, 
            0x34F419D2A3F3B628ULL, 0x71E8296934E299FEULL, 0xBA8C73F72FD64813ULL, 0xA9B24BCEAAB38EBAULL, 
            0x4D4B93FE6CBB00BBULL, 0x803BBB4A23D77A34ULL, 0xA30B99A875A8F2BDULL, 0x36119799A683DF91ULL, 
            0x55F0C320C3E31729ULL, 0x1D9B674F6681416BULL, 0x58D6731D5DAD5D6AULL, 0x772A0115F20E0ADCULL
        },
        {
            0x396684B8DD68AC22ULL, 0x506C318C91C6024AULL, 0x2DE0E2320D24FAFFULL, 0xDD5A06F040EC3B93ULL, 
            0x2A664FCB286717FDULL, 0x9AD1FE16EE45FE5EULL, 0x8AADCFD2123A7331ULL, 0x79615F07455AF091ULL, 
            0x253F5E91BB51D543ULL, 0xEEFF1277504C405EULL, 0x3D18712646188448ULL, 0x43476DE8D505C71BULL, 
            0xD97B7E9CFF52DAA0ULL, 0xB017BA3878547352ULL, 0xBBB39A28E8A56B06ULL, 0x4D4F25FCFAD469FFULL, 
            0x7FB99554FF2BA883ULL, 0x862E94DA476751CEULL, 0x9157A6F473F91F1EULL, 0x7ED817D988D57FD9ULL, 
            0x3D71195DC2E33294ULL, 0x6542A48E0F783117ULL, 0xEE9F895A3BAC5815ULL, 0xC84F1981BF7272ACULL, 
            0x87522D2F36BF7FCEULL, 0x034618107ABDB963ULL, 0xC821578E49524282ULL, 0xD9E406EC2908A874ULL, 
            0xE4A63FF4879D5C23ULL, 0xA8A28D5B6D321D16ULL, 0x8B8AF46F8E3ECC19ULL, 0x5A328507972B5BF1ULL
        },
        {
            0x8E68C71993FEB3DAULL, 0x4F55CB6D7206A45CULL, 0x429BD47C297B0EB4ULL, 0x751615C0C9E1023BULL, 
            0x9E55558EDE100810ULL, 0xADC2D0083F540580ULL, 0xF09D21787487AF15ULL, 0x4EF49A7EB2F7F4FFULL, 
            0xDEBCCE83AF6DE8DCULL, 0x01545EEA68146C80ULL, 0x8CE4EE669ACD6687ULL, 0x6F64081947A3CB63ULL, 
            0x272B9C669DF4543FULL, 0x3F76B381C088CC07ULL, 0x86C48B366376EC4BULL, 0xCBF1574972285F97ULL, 
            0xFCF443804065D534ULL, 0x85A0B25595D881F4ULL, 0xA6DCE924D542DBD6ULL, 0xA537217A9FA044E6ULL, 
            0x836A791C5D1AC208ULL, 0xE8023430CA43E9A7ULL, 0x73F7E52CC00F3C97ULL, 0x5AAB6C03B9646F43ULL, 
            0xC1B6AEA241304399ULL, 0x6C0878BFF9F0224AULL, 0xCA137268009C33B6ULL, 0xE1833F814A16CB33ULL, 
            0x6657616B53C908FBULL, 0xA29667DF483B37F6ULL, 0xE8A280C859011DE2ULL, 0xB821927D561B8403ULL
        },
        {
            0x075CED8E50A3133DULL, 0x704ADA84B9B3C44AULL, 0x6BB736E3A6899445ULL, 0xAE21F651BB70668EULL, 
            0x3BBF6A4D4A7F2829ULL, 0x53F2EADDC651CE2EULL, 0x588926B11E2A29FBULL, 0x41276E2214DD58B5ULL, 
            0x0BFFF9269A9F8A53ULL, 0x296188E504E5D5D6ULL, 0x5AEA61E727D89886ULL, 0x6A86079EFDF35BDCULL, 
            0x9E6841F98718B9A7ULL, 0x1B30DDEA91E81B2CULL, 0xB2DF76FC9E5E939BULL, 0x59572E4DA8071B95ULL, 
            0x01E04C9538AD9077ULL, 0x0ABF5E32552ED7E6ULL, 0x6F4C4991CCA72325ULL, 0x678847CC3AAF2E8CULL, 
            0xE095F2E4BAEF9065ULL, 0x341162BE05B47E08ULL, 0x639821E1ED647224ULL, 0x872F945A9B611517ULL, 
            0x04C8D56EC54FD21EULL, 0x830849C0F65195B3ULL, 0x2D470CAE641992AEULL, 0x205F8F96554ACBEDULL, 
            0x37670826D394A469ULL, 0x8FEB63659866BBEFULL, 0xF41738E526D940F9ULL, 0xAAC8217DB6A111DEULL
        },
        {
            0x3882E412F7742CE5ULL, 0xB7655F770BB49232ULL, 0xE418A3E98EE7FD19ULL, 0xE2A9A8FC478CB432ULL, 
            0x0B61DCC686DA8C25ULL, 0xF26FFEAF8100152FULL, 0xE1FF422E32F8B059ULL, 0x299B4C83DC628200ULL, 
            0xFCCD522F4AB821FDULL, 0xF08CD992B64B1FD2ULL, 0xA406D99FBAA20825ULL, 0x602F45120174A6F5ULL, 
            0x299C21150BF203A1ULL, 0xAB972F004FCBEE64ULL, 0xCF875F4009E582CEULL, 0xDF676B6FBCE87895ULL, 
            0x6CD472489682F02BULL, 0xAEBDD0E7BCB417E6ULL, 0x79CA9EB412A15A9CULL, 0x86039AB4C1836863ULL, 
            0x666AD776A2DE065DULL, 0xA61E7BA0422E7175ULL, 0x7F006C5ACAA7E997ULL, 0xB7D3D4A023C7A276ULL, 
            0x0E24969030978AA1ULL, 0x7797292C164276F4ULL, 0x25984CB748E2EB8DULL, 0xA6F1D4DCA54F7C56ULL, 
            0x946B07DD19262BFAULL, 0x56953D3FF0E2B50CULL, 0x2A46DC1EC0260462ULL, 0x6BC5212347DC768DULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseFConstants = {
    0x31EDC00DE875449DULL,
    0x0FFACFBB2B1F4FC2ULL,
    0xBB8D707BF2FBCA95ULL,
    0x31EDC00DE875449DULL,
    0x0FFACFBB2B1F4FC2ULL,
    0xBB8D707BF2FBCA95ULL,
    0x191071230364BB9DULL,
    0x2325B05AC282FC97ULL,
    0x39,
    0xF3,
    0x13,
    0x9A,
    0x25,
    0x1E,
    0xAD,
    0x3A
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseGSalts = {
    {
        {
            0x0F53FC4E3EED231FULL, 0x27621963B6C2B749ULL, 0xC9238C6E3542FCB4ULL, 0x35E5C03DFEC6D3FEULL, 
            0x156408219C43771BULL, 0x46DA9D950057B5EEULL, 0x5099751F6C8F46A1ULL, 0x5AC92C7BDABEAD5AULL, 
            0xECCD0872CDD774B1ULL, 0x7C2FEB3EB20A4A59ULL, 0x3E101634056C16ACULL, 0x564512BDF91C6FF6ULL, 
            0x4F9266BB32FC8F2AULL, 0xE9E3322BAAFAC481ULL, 0xF862DC6AF51B7EAAULL, 0x3E795DF289807ED9ULL, 
            0xDC895F22F19C36DDULL, 0xB2B80B8DD6CB554FULL, 0x80E52C4595D0A23CULL, 0x85A6A9A73B8B1B14ULL, 
            0x7674B4649B126FCCULL, 0x415F8EB9FDBBDA77ULL, 0x9F328DD947B3CEF0ULL, 0x6865332031E77080ULL, 
            0x6841CCD6B833F570ULL, 0x20A34EED3D18ACC4ULL, 0xAA0167D9E827B132ULL, 0xFC71EDE89B39B09DULL, 
            0xB0DAF356E5E69FC3ULL, 0x92BDF36298F4F412ULL, 0x08B1E875486C1C1AULL, 0x203ABFF024DEDCB2ULL
        },
        {
            0x029F52A7C6F71B58ULL, 0xF641FAC18C0F07A6ULL, 0xE448AAEEADA7F5D2ULL, 0xD021A91A24C22F55ULL, 
            0xD94332B7738EA76DULL, 0x5D1A700A519AAFA6ULL, 0xDB34594800308F55ULL, 0x0AACDB9DB63AA49AULL, 
            0xF472C30E223633C9ULL, 0xECF8167A5D8D0175ULL, 0xEC6680A0C88A7EE9ULL, 0x46DCAD16B87A39C1ULL, 
            0x6961C438FB308F17ULL, 0xCBD6E5F001B08A2FULL, 0xE19A9C2CD891A6BCULL, 0x049E321E29082445ULL, 
            0x78F3F0394C39DC37ULL, 0xA8DC06CBAB950F17ULL, 0xC5BFEEB6B19294B7ULL, 0xAFC3EB2E44BBC536ULL, 
            0x4692EE7D0B2C99DFULL, 0xFB4C61CBD32E963BULL, 0x76A1DC5FE856198CULL, 0xCF80024805B111B3ULL, 
            0xA97AA57F898C9534ULL, 0x97FB9B44AC6B2406ULL, 0x0A47191E896113FDULL, 0xDFBA04735276B689ULL, 
            0xB7F5ECE7BE601E26ULL, 0x0CE793104C0FD9D7ULL, 0x504B2B13E7AD587CULL, 0x95581A0564FAEAF0ULL
        },
        {
            0x359984037D3C3807ULL, 0xF9CA89F8990404E5ULL, 0x921DA0B60EE3B584ULL, 0x6A43CFDD696D8B4EULL, 
            0xFB79C7323E07C8CBULL, 0xAA01C4BA4A9C8B34ULL, 0xF5D3DB7E7B4B8A10ULL, 0xD3033E0191389B02ULL, 
            0xFE84BB0BDD26105EULL, 0x7212AB076DCFC9C7ULL, 0x21A326D66E110AB7ULL, 0x6582AE1BC18E716DULL, 
            0xECFBE8811E8ABE49ULL, 0x9561D0690ABD123BULL, 0x1446C3C0BD669E49ULL, 0x2ECE07EDEA6147BBULL, 
            0x09AC11E99DF05056ULL, 0x70D10018EAD021FAULL, 0xC3C50AA78E1871CFULL, 0xD0BD09FDA3A7358BULL, 
            0x66ADC58EA226D08AULL, 0x3CA0A27A03CB5A32ULL, 0x3144016A0B2F6A52ULL, 0x816603A0B0C60213ULL, 
            0xBF11E2593EE6DBBEULL, 0x30926342AB3A1DFBULL, 0x5AD8CEC4FD7ABB7AULL, 0xC230ECD0D881FFDFULL, 
            0x016C3F0BF7A2F7B6ULL, 0x6CC14DA089803B1DULL, 0x9626CF0F0D66D7F1ULL, 0x1611EEF9EB396AC0ULL
        },
        {
            0x52FD233CD6E4F6A2ULL, 0x536F91A1FBCE67E8ULL, 0x59025BA127A0467CULL, 0x2F4D69FC91CEA1B7ULL, 
            0x188E08C77C86BF7DULL, 0xAA75833548B9313EULL, 0x4B02E4BB85C8F28BULL, 0x806EE27D2ABD9A68ULL, 
            0x3293238066F9214BULL, 0x717BB9E52455E0D2ULL, 0x98884EC627D5292BULL, 0x1314C112B3E92F4EULL, 
            0x22CD8FED2353B832ULL, 0xA82F872DEFC2C5D5ULL, 0x1AA0C7CFF562CC38ULL, 0x9598848875E18082ULL, 
            0x4B9316374F58975DULL, 0x98459968707CFFFAULL, 0xF2F77ADE8A75843EULL, 0x65E18CEDAF5CC885ULL, 
            0x7CC9F8B2C47AD588ULL, 0xE56B3A09B21D75FBULL, 0xFF10F6EF52F27CC9ULL, 0x4C1B7310332BFEE7ULL, 
            0x7E0BE016A56FE50BULL, 0x46EC803C7A92C6B9ULL, 0x6652ADBA97679F30ULL, 0x266185FADA7EC00FULL, 
            0xB8D3E618995DFBE4ULL, 0x11381B08243E06D3ULL, 0xE692D0F90F6A0FA9ULL, 0xFD3233CE9078B4C6ULL
        },
        {
            0xB084A3F5E0D8AC8BULL, 0x514396CF5EFB6FE8ULL, 0x3F37AFB45B6EB046ULL, 0x00ED91D22E012E80ULL, 
            0xE909EDA95153BE53ULL, 0xE6048CC59AEF783AULL, 0xAE56F61FBB6B621AULL, 0x713831E0D2221A15ULL, 
            0x178463638E53485CULL, 0x82AE160D9CC83A98ULL, 0x543BCE4C3E5EA153ULL, 0x3C5785536C3A2FE7ULL, 
            0x91F916F2C610AC70ULL, 0x6CD88D3CB05DD78CULL, 0x7D4F63C0A1453A51ULL, 0x627E88533629218DULL, 
            0x475D053D7F5DDCD8ULL, 0xEB34430D9E72B7CAULL, 0xB93559CE321901FAULL, 0x0DA21ED1F4C6528CULL, 
            0x2A6B014810535723ULL, 0x9952377345CCA9F5ULL, 0x273FEE5639F7AB0DULL, 0xDD7A6E3A59C905F5ULL, 
            0xCC7E90BEB9062B6BULL, 0x300340F13B3A9440ULL, 0x53401622662796E7ULL, 0x8F22621E1B266A20ULL, 
            0x59323B26DF7F49D0ULL, 0xA3F96052C1AD1CB4ULL, 0xB6006F2483B61D4AULL, 0x4FBF26681B841680ULL
        },
        {
            0x3D5019FD4A9F3769ULL, 0x5AF6EEA158E01693ULL, 0x6A8A136BC92B5487ULL, 0x12DD7F5397E00606ULL, 
            0x66B17C2DE1B561E6ULL, 0xF93BA3FFB51E30BFULL, 0x55C5853783295B59ULL, 0x3A5E373A3BB27171ULL, 
            0x39F6C6C9A36BF355ULL, 0xFDA83B4F09F6E5EBULL, 0x8F4D4F3441B099EFULL, 0x4E980FD5D8FB1F89ULL, 
            0x9861F43A1559E13DULL, 0x77B32A5964B8159DULL, 0x7EF3DC742A63AD47ULL, 0xB94E3220371B434DULL, 
            0x2E05CD9D2A588142ULL, 0x1C4E0770AA2718FEULL, 0x15803F98580B94E2ULL, 0x357A051FB2ECB6AFULL, 
            0x4FF4AD08BF8F5530ULL, 0xAAED49F91C7EB50DULL, 0xBBA3E2A92A884C61ULL, 0x903D0894C0056D0AULL, 
            0xE1221DCCA1B96FA4ULL, 0x7350278704AB37D5ULL, 0xEB1424B0AD91E4B3ULL, 0xC985E5B1FC2645EBULL, 
            0xB1BEB13CE45E3270ULL, 0x006440AD21036766ULL, 0xCC94297119B38160ULL, 0xD7A00A991FFFCA69ULL
        }
    },
    {
        {
            0x77E761B428E74E46ULL, 0x54D9FF56B4148065ULL, 0x798FD7FA0D0EE376ULL, 0xA07ACE4EC6E60AAFULL, 
            0xEFA9B0E2AD0293B6ULL, 0x6712708DE1B41C7CULL, 0x243F73F48307040BULL, 0x571619373570E884ULL, 
            0x1A678C6EE82948A4ULL, 0xD021EF52959D7088ULL, 0x2239662F20D31923ULL, 0x3FCAC8A2822BB547ULL, 
            0x8798F76A341721AAULL, 0xAD805BC31C2287BDULL, 0x1E9BF3782A8A7BE0ULL, 0xF4FBDAE6EA220A97ULL, 
            0x3B10FDC972AC2692ULL, 0x349A39F4D05F9E4DULL, 0xBCB4EA663AE345AEULL, 0x29CFD943892F560FULL, 
            0xF15BC48EF3BAB0EFULL, 0x0DD0C0C2533F17BDULL, 0x60B3B8453229924CULL, 0xD56387493AEF5374ULL, 
            0x15B6ED46F7793EBDULL, 0x6852AF46558AC8B3ULL, 0x85447C4551211EF4ULL, 0x3C8A0C0385B2D307ULL, 
            0x8909CBC345AF9986ULL, 0xB392C8F73D424FBBULL, 0x9CC9A2F99F4EA5C8ULL, 0xD633B2920898A2DEULL
        },
        {
            0xC13D0D163DD7B2A1ULL, 0xC0F632AEAFBBCCF0ULL, 0xF09813FDB2E5E1F6ULL, 0x18AE27435A6B1424ULL, 
            0x225FCE031CD2090FULL, 0x1641523C008E4F70ULL, 0xE0E1759CD19501C0ULL, 0xC9F34593114035B5ULL, 
            0xE9547C1C1CDF62C9ULL, 0x6CD2482D34B68BFBULL, 0x5D3A3D74308E669EULL, 0x3CEAEE7416E1D70CULL, 
            0x36E67EB768D645EAULL, 0xE73D5D8A01B351E0ULL, 0xCC84F7216C534B95ULL, 0x1674395D209D6CD9ULL, 
            0xEC3339C1E8999F5DULL, 0x4492B8C29EC1A87FULL, 0xFBD95BDB4D6E1BC8ULL, 0x8F9C1AF1644AEFC9ULL, 
            0xE199F29292EA93E1ULL, 0x4616E4C36DC2F222ULL, 0xF47E73E20060954CULL, 0x09D569E04D09ECC7ULL, 
            0x294F9AE70771B9C7ULL, 0x35E6FC57EF9012F3ULL, 0xC2027C99FF5D4DC4ULL, 0xC1A38165034C6C35ULL, 
            0xD919F258ED6CD03FULL, 0xEB5D7E43D70C4294ULL, 0xB3586F88C16D06F0ULL, 0x7331D65515E42C19ULL
        },
        {
            0x904AF462EEC94A75ULL, 0x31631F1B33051D0FULL, 0x0DF78932BC03DDE2ULL, 0x83513238A39DFEEEULL, 
            0xFAAD6BA8C2405A97ULL, 0x85976A600398DABAULL, 0xBBEA6D8774CB1E68ULL, 0x943C1C6DA2211434ULL, 
            0xD84FFC03A37AE000ULL, 0xC00A9B2FC619E1AEULL, 0x2CFCBFD7B13A198BULL, 0x74C1CD06E6A141A1ULL, 
            0xC0A7BD58F3B22CDDULL, 0x2274FBDF27D9F435ULL, 0xCC6AEB1D51E9E163ULL, 0x4FDB3AD7E8F3452BULL, 
            0x8EC7E6682721446EULL, 0xB55425935EAB7DAAULL, 0x6CBAF75DD9C1BF64ULL, 0xBB69A46953DA0B95ULL, 
            0x05CF1D75A638B0F2ULL, 0x91EB30B613A0852EULL, 0x96A1D984BF77F09EULL, 0xC7CF63CC18CD760CULL, 
            0x9A67EA9910DD781AULL, 0xB1CD933AEB5580AFULL, 0x63B5F5539D4A2A45ULL, 0x188B0A27367EBDBEULL, 
            0x99865717F9A618F4ULL, 0x5FFD458E6F0CB137ULL, 0x5C9D009683B2D65BULL, 0xE441A60405FA28F9ULL
        },
        {
            0x30EBC9C5AE48429DULL, 0x6CBC6772674C5C9AULL, 0xB4E297BCE55E9478ULL, 0xAFC0CBB446AFC245ULL, 
            0x244E6A6C3233866FULL, 0x7AA519587387F5AFULL, 0x13AF66BB7379CD4EULL, 0x5D067AF1DF9DF49EULL, 
            0x0EA4612C48CA2FADULL, 0xB31BB99F19ADED12ULL, 0xCA5FE4146D72E73CULL, 0x4C107973E7C42617ULL, 
            0x4D2747A0488D3053ULL, 0x8229D27486073237ULL, 0xAEF3606881CD799CULL, 0xBA85AC3DBE8705D9ULL, 
            0xE3A02D82738A4FACULL, 0x009F7E4FD76BBB59ULL, 0x0F75A064650DD140ULL, 0x90D5AED3B60A3B2DULL, 
            0x8E509715CF73A3B1ULL, 0x1362FA3CEC57D67CULL, 0x700FAB2866AC1691ULL, 0xFF8D0084F0158472ULL, 
            0x0DCDF69BA67A5BD5ULL, 0x41F4493011F3F808ULL, 0x02BD4BB38D399C9EULL, 0x1A5EB81E50D0276EULL, 
            0x7ADC81FB64B53324ULL, 0xBA91E491390FE9E2ULL, 0xE2C537E49F4383ABULL, 0x797BF4FE3C86C724ULL
        },
        {
            0xDCF345EA91356941ULL, 0xD7DE0FC93336F70AULL, 0x1C1DDE4436A35433ULL, 0xF3AD7BB0526572C5ULL, 
            0x599691AFC68BA041ULL, 0x3DC104FAF1504AB0ULL, 0x6F5456BFAF859684ULL, 0xDCFA662E05F2F402ULL, 
            0x6A9D2389E40BA5DFULL, 0x0C93A1349C0AD51BULL, 0x89D1D9BD962DA526ULL, 0xB4AE08D3545C8A8BULL, 
            0x317104796BCBC571ULL, 0xB163DB6F1993BDAEULL, 0x07B1F4D3098D6CC4ULL, 0xE559035A0BFDD1B0ULL, 
            0xEF3A4340DB38CE50ULL, 0xDD9D556350853732ULL, 0xE4FCFC6DBBB8457EULL, 0xE36F4AE953F29FC9ULL, 
            0x3E41CA6599DDE734ULL, 0x7C5DB872D5DD0EAEULL, 0x4C281D0AB4752FEFULL, 0xE1EBE10FFE4192AAULL, 
            0x55093B60D57B14AFULL, 0xAA83F6501DBA489AULL, 0x32302AB9CDCF8AB0ULL, 0x9AB5A0A53BC57D3EULL, 
            0x38896399CAC9FE10ULL, 0xCB0CB865F0E5BF6DULL, 0x779078B5E2DB99DEULL, 0x6F48266DA5A60668ULL
        },
        {
            0x3D6848226C58AF78ULL, 0x91B4F9EFDB0C7885ULL, 0x8C94021DD37204DBULL, 0xA32528F81F35BC98ULL, 
            0x554AB3D0015F1FD2ULL, 0x46C95E883194AF4DULL, 0xD681312C00BF6339ULL, 0xBC49543030BF5EBFULL, 
            0xCDC8826B6A99C3FDULL, 0x3A541B1241E1F6A7ULL, 0xFAA3C3C8F86E4EA6ULL, 0x7C5EA8E17C30261AULL, 
            0x2020B1DBBE8935D9ULL, 0x27E4A0C9F2031200ULL, 0x7788F9E5842056DDULL, 0xF968F79B720E350AULL, 
            0xCB3A400F8C65631DULL, 0x5BEA7066ADAECADEULL, 0xD674646C4690A1B6ULL, 0x801EB6C1483243DCULL, 
            0xF6B473202234ED39ULL, 0x5CD096D352002956ULL, 0x9B2A8A95EFDAFEF3ULL, 0x60F0B5B2E126D54EULL, 
            0x76DA2ED289A65002ULL, 0xCBE6D4C4297AE35EULL, 0x0BD97FCA1D9843A2ULL, 0x58FD8C7ECE9B4208ULL, 
            0xEDAD85B819716658ULL, 0x2A76F3EB1C9DBB13ULL, 0x5814D6C68A539AF4ULL, 0xE3AA452113BE47CCULL
        }
    },
    {
        {
            0x489466BBD48332EBULL, 0xD17A56358236867DULL, 0xA730F80E841D81B7ULL, 0xB99DB30F77D806AEULL, 
            0xE42050B0EB875382ULL, 0x35FD107E5355621AULL, 0x4DC4B664B708E135ULL, 0x0395A96687D07FFDULL, 
            0x277B468CE7A983D7ULL, 0x16DEDF2CC2A8653FULL, 0x5193DDE0132887FCULL, 0xF48B9468A727BD42ULL, 
            0x9BE599D216DAE23AULL, 0x60893F03B20812A0ULL, 0x2BF420EE5BF79AEAULL, 0x6EB49ECE4FC6679EULL, 
            0xFD15067D96FDA5F0ULL, 0x15DF3ED18CA77219ULL, 0x3C3B120CB258582DULL, 0xF9F7BBCA5923B234ULL, 
            0xA87F9E17AFC8B29AULL, 0xC438DDA289D22B4FULL, 0xF6F79D6DD074D264ULL, 0xBC227000EF442197ULL, 
            0xD5C513924CC1BB13ULL, 0x7822339695826393ULL, 0xC272B3D376F04780ULL, 0x5DB4BE03C13E8529ULL, 
            0x31CAC67EE6B903A8ULL, 0xC152E759CF69AD40ULL, 0x64D405A0D3F702BBULL, 0x895B122A301276CEULL
        },
        {
            0x2F5B5C5246D46403ULL, 0x23A377FAE9AC79B7ULL, 0x30E607E4C4CC57D6ULL, 0x7806C384D6B9E167ULL, 
            0xC6BC81982EC4E25FULL, 0x60DD295D7DCC7D2CULL, 0x6D74C68308805AEEULL, 0x73F9F8D66AB0ABBBULL, 
            0x38229F6259743FB4ULL, 0xD1D7B482B72B7EDEULL, 0x6AA35EBE24010113ULL, 0x0508DCF003F75575ULL, 
            0x25E88C62050D5777ULL, 0xEA099DDBEC7BEB3CULL, 0x8A768CA8C3B8BF89ULL, 0x113FE52FDA6EE8F1ULL, 
            0x85371A6DC8F7EF86ULL, 0x2D2009AB4D7D57F3ULL, 0x87C31578BB64DEB2ULL, 0x4116C48B7576D27FULL, 
            0x856B1F4DD58347CFULL, 0xF09AC5E80209DBCBULL, 0x80FAA721A51069D7ULL, 0xFA97225E698A4C7AULL, 
            0xBEB30D3B90AC6ABCULL, 0xA649306D1122EDD1ULL, 0x916A05F473302B55ULL, 0x7F579F145F5A789BULL, 
            0xCF78456A606DAAACULL, 0xD468EAAAC236E1DBULL, 0x3DC7F79B93B63E62ULL, 0xEE401894C6E718E5ULL
        },
        {
            0x32BE486D936EF1A0ULL, 0xD0E7B6E7408C0A0CULL, 0x829B9AFCC834EAE4ULL, 0xC0BCFA06120DEF6DULL, 
            0xF9FAC545C7288BBEULL, 0xF35D014986F48894ULL, 0x981BBA5022E07DA4ULL, 0x5BF884B10CB5D98FULL, 
            0x6E20547D48CB3B55ULL, 0x80317A0C794DE5B9ULL, 0x44B4E7FCBC529527ULL, 0x6B4336A1E6B253BAULL, 
            0x8C9368A3EA15C6C6ULL, 0x6F5445EF4DA5C244ULL, 0xA88E72D3F40F8126ULL, 0x3BDAD5CC73A175F9ULL, 
            0x01667DD321652EADULL, 0x364FAD8889FDD12AULL, 0xA7C95925DA63069EULL, 0x9808422947ACC486ULL, 
            0xE28730748453AB6AULL, 0x68AA4B4ED77717F0ULL, 0x0D9F9D78A321578CULL, 0x1A958D66C03AEAEBULL, 
            0x05A906E35F1D74B4ULL, 0xE27A7566FEC2E06FULL, 0xF088C646DC300A63ULL, 0xA184A770C22AA589ULL, 
            0x1A049C36EB6913DEULL, 0x1FA9ECEDA7E76C5AULL, 0xCA12DD246742E190ULL, 0x1FA86753CA440EE2ULL
        },
        {
            0x1DFCD24BAA1482DCULL, 0x9540BFBE4C7FBC38ULL, 0x68B8EAED9AF8AE71ULL, 0xC0A581B7ACB7481BULL, 
            0xF5E93650B459D82AULL, 0xEAADD9E7B0926C92ULL, 0xCA922FADA3165D75ULL, 0x74DCDF8A20B22FE5ULL, 
            0xFF718AB9A6FBFCCDULL, 0x7A6615D43D826E7CULL, 0xFE565ACE13375EC0ULL, 0xF72E76365CDD729FULL, 
            0xAE7BCE43BE4A399DULL, 0xD8BB92C4EFBB2174ULL, 0x6711FC41D29CCB7CULL, 0x85D7F957FBDE747CULL, 
            0xB4CB4CC098EFAA4FULL, 0xE00B979146125FEBULL, 0x89A77A780CC107E1ULL, 0xF53A81308E1B1600ULL, 
            0xB069ABCD629979D3ULL, 0xCDE8CF6384BB78F8ULL, 0x8836D923BBCC5BB6ULL, 0x2187C34DD87CA1BFULL, 
            0x1382AE4D6790A21BULL, 0xCE5CB0CD07BEBA42ULL, 0x3EB26710F2CD7754ULL, 0x5434F1F9CDEF40F1ULL, 
            0xFA6FFCE94BC0EA90ULL, 0x3ED26A6D65A93595ULL, 0x0D83B12BA1E42E22ULL, 0x9B440DFDB4DF9343ULL
        },
        {
            0x0677E5EE3E167765ULL, 0x5A1FE6E5258EB75DULL, 0x24CA3396C2E32271ULL, 0xD6599377AABDF67BULL, 
            0x494762B4B30193B8ULL, 0x3B25A5EE21C5FEEDULL, 0xE58EFEB2DE6D3A90ULL, 0xC4F856B21062DB6DULL, 
            0x0BA09A456757C7E2ULL, 0xFDE11D68A9B0C171ULL, 0xBB6D0E0036868A16ULL, 0xD036A466B8F46211ULL, 
            0xBDB51D3B3A982211ULL, 0xEAEE6576ECA09611ULL, 0x625B6013C28C87F3ULL, 0x30CAD1740EA2370DULL, 
            0xFAF3AA5A1545444CULL, 0xC9561B58E0A10BD7ULL, 0xACEB6826A1F4374DULL, 0x96C20271A7B033AAULL, 
            0x591A5967555D362DULL, 0x4D30283EA1315649ULL, 0x6EF19B537F670389ULL, 0xB4D3FB4C6C39DBCEULL, 
            0xB90CCB5073489489ULL, 0xABB159419AD27330ULL, 0x3701742DFB46956AULL, 0x3F08DDADF24DA4CFULL, 
            0x111FB1DBCCC48B39ULL, 0xBEE331E684530B15ULL, 0xAF6C22961B9EF2F5ULL, 0xEE00D0A968A4DF73ULL
        },
        {
            0xCFAD69C76D175BC0ULL, 0x301C27360E6DDBC0ULL, 0x9C60EC653827C8AEULL, 0x5DE8AA158DE8FAC6ULL, 
            0xF49D332C21E39FBAULL, 0xA9EFC68603A4E678ULL, 0x93ADC9FA8DB47D98ULL, 0xF532F346BD80C096ULL, 
            0xA82721D3411766C7ULL, 0x920A2448F882D435ULL, 0xB75AD58EB69CE1A7ULL, 0x32C5C76AB5DB81D7ULL, 
            0xCA148B7686040E04ULL, 0x19CB9AEDC7FE140EULL, 0xE75A3A9E015FB4A4ULL, 0x69F769A36D64FDF6ULL, 
            0x098B266FC36782E2ULL, 0x0F045C15866A89DFULL, 0xC6197F0233356065ULL, 0xF292B5378D1F661EULL, 
            0xD9B574C2D9A7D12AULL, 0xD9B5DE2536B301E5ULL, 0xB19F04F9694094DDULL, 0x0A9BA06A1986A36CULL, 
            0x9CA8B76089039905ULL, 0xA5A43C3A3C8816C7ULL, 0xB60878593212A2CAULL, 0x529BAC2D4977C5E7ULL, 
            0x8923B77CC31F6B14ULL, 0x0599665300C5D1E9ULL, 0x3CC84302BE82DA04ULL, 0x61297555063270ACULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseGConstants = {
    0x43AF81AEFA2C231CULL,
    0x834FBA1339EEED52ULL,
    0xF396BB6E7C6B115EULL,
    0x43AF81AEFA2C231CULL,
    0x834FBA1339EEED52ULL,
    0xF396BB6E7C6B115EULL,
    0x6E14B2EC0682AD4DULL,
    0x7B56525A09E411F9ULL,
    0xF3,
    0x63,
    0xA8,
    0xBD,
    0xAB,
    0xA5,
    0xA5,
    0xBD
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseHSalts = {
    {
        {
            0x1E86BC95C11572C4ULL, 0xCE118C3A6BD41BB2ULL, 0xF9A4958E55EC42CEULL, 0x709974BC0ECE0FF4ULL, 
            0xDAA66B16E863DBB4ULL, 0xC77BB34A80A9C478ULL, 0xEA170984218B7E7BULL, 0x0FFC6FF11FF4B4E6ULL, 
            0xF9CB934E0626446FULL, 0xC79FC37A5AE25F00ULL, 0x07BA1289F6715B8EULL, 0xFF1DE1154B2CC886ULL, 
            0x99A4CDDDD6300BE4ULL, 0x1153FED23D8D2006ULL, 0xB476CFE7F99CF800ULL, 0x1C5FD5F128CC952FULL, 
            0x7641296EC44A8739ULL, 0x7620302EA77FA684ULL, 0x0AD0ED297FF1BCC6ULL, 0x86BF646CB599CBD5ULL, 
            0x6BCD6208AC61489BULL, 0x78912947BB859B76ULL, 0xDA3C22FC1ECC4E61ULL, 0xB84555572AB9535CULL, 
            0xACB076857705FA59ULL, 0xECD33B00813C9BEBULL, 0x2AA5CB5162D358C5ULL, 0x75DB5BCDCA33D7BBULL, 
            0xB75F586B86E885E4ULL, 0xBED46CF1844DB1AAULL, 0xF9C8298FC4C59B79ULL, 0x372B020F7FDD1BB8ULL
        },
        {
            0x6119C97523448E15ULL, 0x2BF7F6781BDA8985ULL, 0x1D181A35A64BA9C4ULL, 0xF034C2244CA236D1ULL, 
            0xB0AAA14D511A5F70ULL, 0x5AD6D594E6A55AB5ULL, 0x168AB158FB6BD9C2ULL, 0xD5267C6B3D3E1F65ULL, 
            0x70D197218849E355ULL, 0x556F62A97B047C29ULL, 0xD2AFE1266750B737ULL, 0x3E37CB29FB6AB49BULL, 
            0x673248D12079E9E6ULL, 0xD9704CC4A3A579C6ULL, 0xEC94B303A3E98BCDULL, 0xB0C896F01A6A1F6DULL, 
            0x94F0858324C858DEULL, 0x36E3815A1BFE3BB6ULL, 0x4205C4EE46BCCEC6ULL, 0xFCE5AC52543EADDEULL, 
            0x4C7526C3EC1E3653ULL, 0x3E80B1916102E244ULL, 0x10119480F7B41846ULL, 0xF0074142D44386C4ULL, 
            0x18D306FCEED23E12ULL, 0xC35EDC8716284102ULL, 0x382EF3D62E6B2BFDULL, 0xFDFC93D72F2D50BDULL, 
            0x587A1614F1B8D3DAULL, 0x57E9A84569094C0DULL, 0xDFA7490EF8F7B466ULL, 0x5952B5038530419DULL
        },
        {
            0x5290CD3DDAAE53F8ULL, 0xEE353DCB1DDF68ECULL, 0xAF452B1E4177FCACULL, 0x5E25584078E148D9ULL, 
            0xE39837C2F8069CCEULL, 0xA5F3DCA9F4A083A6ULL, 0xDE66D7530ADE65AAULL, 0x057A8147925509F6ULL, 
            0xDE6DF887EE2D1518ULL, 0x43A9364915867E5CULL, 0x7E8B73E6016B85A3ULL, 0x144FDF8D358395CBULL, 
            0xBB6389DEF815A79BULL, 0x7C9F6BFD530913B2ULL, 0x053698C9447AC30AULL, 0x2E3C3038D066BB49ULL, 
            0x58C9332109FDD8B3ULL, 0x0C1015EBFE8DCFE3ULL, 0x6AD1F95B61735F5EULL, 0x401186BFE67D50EAULL, 
            0x2BB0856DD331E779ULL, 0xCAEAFAFDB8DECC8CULL, 0x93C2242548B8EEE8ULL, 0x87355FB8C9F9F9C2ULL, 
            0xBDD39069703D744BULL, 0x6E007D0A4FB3C2CEULL, 0x20CF494B606165EFULL, 0xFC8828E56D0E54E8ULL, 
            0xDE206C1997F5BB3BULL, 0x45C3689DB023C6DEULL, 0x2E5274A214B99CE4ULL, 0x4695AD4E17121628ULL
        },
        {
            0x1541639672F5DD9CULL, 0x8C5C6F89E1E62C11ULL, 0x82F6F74D927A984FULL, 0xAB82442537EA7C9FULL, 
            0x706CB30E38A9007DULL, 0x434A9321CE96EE1CULL, 0x372C664A60166C2CULL, 0x10125D825E6B4203ULL, 
            0x71B8FDD51083D7B8ULL, 0x08D8451177DE1C25ULL, 0x8D2F87234AA9048CULL, 0x72FEF7BC1F925840ULL, 
            0xD12C43317CD15CEBULL, 0x3BB5B89643F1DE08ULL, 0x2D90ACBBD084F917ULL, 0xA59B504EEDC18156ULL, 
            0x37ADFD7E5909DCBEULL, 0xEDD7CA690CB343C3ULL, 0x69A5BE2C0051BDB9ULL, 0xC06E91D41317A50BULL, 
            0xE4B45AF0B189B633ULL, 0x3A1CA45884309649ULL, 0x5E156A56C6BF277CULL, 0x261B4A581063BC51ULL, 
            0xC75CBC265AB3B61EULL, 0x2F8664D304F082B6ULL, 0x7D7A2389C2CB4701ULL, 0x124B4F5DE95D4B23ULL, 
            0x7A46E6DCA2D69D1CULL, 0xC900AFB76A2154C5ULL, 0x90C56A60843245B4ULL, 0xAD3B95CF6977EFAFULL
        },
        {
            0x7D73343CCC6B6873ULL, 0x5EA00CE73C41C0ABULL, 0xB20DD5CF421DCDD1ULL, 0xBFA22867C2767AB4ULL, 
            0x8C3B784933D2D9BAULL, 0x739610F3F8394DCCULL, 0x0D17B779699C6A70ULL, 0xCEF7CC4DB63CAB2FULL, 
            0x8CBF497E8B9E08A8ULL, 0x26170AE078ABA2A3ULL, 0xA276F2BC9010D8B7ULL, 0x96B720144F040C24ULL, 
            0x6964D238B6513A6EULL, 0x513C98502EF1E31CULL, 0x734FC9C7A70BCAD1ULL, 0xA1059305F87A4268ULL, 
            0xF295657BA3537D9EULL, 0x4FC558F8B479EB8BULL, 0x9ED3C03C8CE84BCBULL, 0x4FF818AD8EA46129ULL, 
            0x2BE2A9076333E403ULL, 0x0F5910061EAB17BBULL, 0x5C1C46A6693677A4ULL, 0x66505A2C05EA703DULL, 
            0x8D0155249FB369ADULL, 0x13B16A1987F4C9C2ULL, 0xC4FF62F7FF1CFFB1ULL, 0x2F08693443DCC645ULL, 
            0xAAF55119AE8F2214ULL, 0x32D56F32E365CB57ULL, 0x67C21736A3118270ULL, 0xCB6F1BE58C2F623FULL
        },
        {
            0xCF032FDE3A56C081ULL, 0x680C6F63A5DB886BULL, 0x4D3EF6232148C445ULL, 0x142CD1874EDE6246ULL, 
            0xE5336E9537AB37B6ULL, 0x435D304AF40C4173ULL, 0xCBA5D89089F2DA7CULL, 0x543504F1309ADE49ULL, 
            0xB66A81DA321D000DULL, 0x89C5DBF4C1A590BDULL, 0x6A15087D26A1C507ULL, 0x9D40B7C5B85C9526ULL, 
            0xEB63F8856CA1FC44ULL, 0x189F33D8FDD1DBC8ULL, 0x59F8E83434F962A1ULL, 0x85D3310DB755313FULL, 
            0x6D1E18B0109F4106ULL, 0x7679194000D13B18ULL, 0xA8FA184BE8F6D259ULL, 0xCA736F2030431A45ULL, 
            0x9AE0F0140C053FD1ULL, 0x9EA89B86353DCE89ULL, 0xE90E5D18CC1DD3DAULL, 0x0A26F86282467380ULL, 
            0xAAFB0B33D3CE933BULL, 0xFAD0867B7740CBFDULL, 0xB7D1B3A8895871AEULL, 0x67B9B05E95557D9FULL, 
            0x1B110F16911C9DF9ULL, 0x26A20558AB59CDA0ULL, 0xDD721D048FF85B98ULL, 0xC3A8EC842B047D18ULL
        }
    },
    {
        {
            0xCD33DCF2CA98C638ULL, 0x14C6B578364BAF9DULL, 0x54550C21540FA169ULL, 0x142750B3C5A365E9ULL, 
            0x1BB60C464692F9DAULL, 0xAFE1B3F38FF910B5ULL, 0x948BFF8730C15066ULL, 0x4E5A28319151A341ULL, 
            0xE40D1380AFBB7A3DULL, 0x51C8E3AFCAA0E9DFULL, 0x051E3B00031CBECCULL, 0x1EB95790A7A7A83AULL, 
            0xF84B73D92704EE6AULL, 0x26BA300FC53B622DULL, 0x15818187FA8BBA0DULL, 0xC7026827A02B771BULL, 
            0x44148E160D0B696AULL, 0x49269153A06637B8ULL, 0x6744F35E4792B09EULL, 0xED09882E86E730D4ULL, 
            0xD583135F44EB2318ULL, 0xBB17CBA1723045ADULL, 0xCB082602A9EDBC28ULL, 0x9BF15ED0C93A6387ULL, 
            0x46CF1A403F3B4A95ULL, 0x9662B8B7405A6E1EULL, 0xCA9FC6196047989DULL, 0x6A52E7B34DD662DAULL, 
            0xA98B5F88365416D8ULL, 0x5447114835A24ED0ULL, 0xB1A59CA9D40FEBCDULL, 0x4C80211689EAF5C7ULL
        },
        {
            0xCBA1F5EF4B2B59C6ULL, 0xF1664615912BF93EULL, 0x39B0BF74C00E9E5DULL, 0xC9E12622DFEECC1FULL, 
            0x6C7F1B5E27A05713ULL, 0x52CBD912A6D8CF36ULL, 0x13337166B9BBD7ABULL, 0x139052AA0A1B52D0ULL, 
            0x750A763BC33D0EF2ULL, 0xD369C9E35309D5F3ULL, 0x641BDDFAB5112610ULL, 0xC5D81E6D2DC6BD65ULL, 
            0x7A2F2703FAA091BCULL, 0xA19435A6AD9B91CCULL, 0x2AC94174F3F450EDULL, 0xC2886F1445CFDB59ULL, 
            0x64988B525515BCEBULL, 0xFD3BC60AF0281BA0ULL, 0xF4CAA551E53BA7EBULL, 0x1D7F3BCA804E95B4ULL, 
            0x1294E13989410A2DULL, 0x5354F58F5B4DBB3DULL, 0x09A7DD5D2390C0A4ULL, 0x5C99B5F79E531D81ULL, 
            0x34A607F8D18060B7ULL, 0xCA418659081C5CFAULL, 0xAFEA5566E5F91483ULL, 0xC2672EABB8268DD7ULL, 
            0x01D65B0D9BDD89DAULL, 0xB36530291D97B33BULL, 0x2A8102F730542F41ULL, 0x2CADA40DEE4CB7B3ULL
        },
        {
            0xE34834506F65012CULL, 0xF0D75673FACC7D71ULL, 0x517BB9A1234F2FF3ULL, 0x86127A4092B40C9CULL, 
            0x0ACD34090BDC05A0ULL, 0xAB512576270E8BF7ULL, 0xB73A2E241540DC1BULL, 0x38CEB824C6DE2368ULL, 
            0x1C6B351D64A65D26ULL, 0xED3FC5468651FADBULL, 0xF3A9901DAD368453ULL, 0x4BAFF220A191D266ULL, 
            0x9589BEA4D9A6F98DULL, 0x4E179032BFA6001CULL, 0x18C122D06E4121D9ULL, 0x9F60EDA8D1AADDB0ULL, 
            0xAF504E7223A3F82BULL, 0xE67B4AB8DA1A4E0DULL, 0x5D0018D4240BA162ULL, 0x9068BA98AEFBB0E1ULL, 
            0x8C5C838F9008C81AULL, 0x38F17AD07BA3C5A3ULL, 0xAA39239A8C6F7221ULL, 0x8016DFCC1FFB7961ULL, 
            0x4F6070ECE4F2350CULL, 0x168D250186D160E0ULL, 0x809F88841DBB7154ULL, 0xCE3C2314BD915C3BULL, 
            0xF0AC422C964D3C6FULL, 0x1445D284BFCEA9E6ULL, 0xB938CFF3F595EAC1ULL, 0x0F916D12BC10B7EFULL
        },
        {
            0x25D8AB3FF1412ABEULL, 0x4F8680DEADCCFE63ULL, 0x8C72A35BEC2ED7D9ULL, 0x90B5EEE01EDC48A6ULL, 
            0xB48C38D6924B6324ULL, 0x270CF28A7C1742CCULL, 0xA4A6CAD501EBAC87ULL, 0x177020FAE2002E55ULL, 
            0x6293D03FEB5AB841ULL, 0xC9C4CED042486991ULL, 0x9A6BF70A284C7FE9ULL, 0x3BB707D1E4AC482EULL, 
            0xAB19020B7052BEA2ULL, 0x799BC10E4A9271F9ULL, 0xBE5BF6E0E5128662ULL, 0x2824681BB80393BCULL, 
            0xD86A0FCFA468C68EULL, 0x132A2C2B29FF61D8ULL, 0xED9EBE9710E71F8DULL, 0x021A741D5D191137ULL, 
            0xED90FA3545EC334DULL, 0x9EC070A4EF73EA88ULL, 0xAAD41CE961B7B8E1ULL, 0xFF76B56B6F72298DULL, 
            0x2B2ED4578B8F7C30ULL, 0x76105AD1E948C7F7ULL, 0x4B21E56CE244CDA7ULL, 0xE969A1C3E55AC43DULL, 
            0x4E59B5F48BB973E5ULL, 0x0F3FBAF89F9B0515ULL, 0x26BE2C4ACA9E9368ULL, 0x97AF8CA6FED14A82ULL
        },
        {
            0x4685D0DD1691486BULL, 0x071EF5F23C1AC7C8ULL, 0x94024EAA1FBDC5CBULL, 0x01787586F021C78EULL, 
            0x145935AF313EF3B7ULL, 0x0C6C977A0D21E6F9ULL, 0xB0C6E06E43F20B00ULL, 0xF4424A2F8BD28A66ULL, 
            0x0E7A6AF2BB87F6B1ULL, 0x3736F0AB8BBBE152ULL, 0x39D61F5FFBDC76E5ULL, 0xDA43BF0F633A0D1FULL, 
            0x2ED6E9407570C19AULL, 0x8A1013A9563980E2ULL, 0x3EF96DDFC13EC8CAULL, 0x2857CB316A1ED195ULL, 
            0xC1A6551777FB8A62ULL, 0x4F1381912E86CD97ULL, 0x83DE315C5428468DULL, 0x81C583AB90B22746ULL, 
            0x364D34919CB3964DULL, 0xC688D9359D802B73ULL, 0x0F5F85618E3B4C38ULL, 0x4EA7EB755FF9865BULL, 
            0x5D435232D03950DFULL, 0x562035E1FBA270B4ULL, 0x9E05C63DDE9D1BD6ULL, 0x935A06C4434F2F43ULL, 
            0x10FEB3B97508EAC7ULL, 0xDE27B875AA87028BULL, 0x36DEAF30BCA4F925ULL, 0xA10975D58BA95C73ULL
        },
        {
            0xE3520A7F74994499ULL, 0xEC0640717F4D0A8DULL, 0x2B1DDFBC33BE3D41ULL, 0x5F0A4F9244FBC0B0ULL, 
            0x499DE479BFFC32A7ULL, 0xB7DA956A230887E0ULL, 0x8CDF9FB5DB44BBF2ULL, 0x02BD9C4399CD6DE2ULL, 
            0x35500230517FE822ULL, 0x3D5CBDC85C1B5683ULL, 0xE2842770D34476BFULL, 0x591A437838C828E7ULL, 
            0x706F2047C99A2A15ULL, 0xD65CE40B3D3BB52CULL, 0xDA37A88FFBCB20DEULL, 0xD7FF7AC2C0B3C97AULL, 
            0xC32E985363CC02F5ULL, 0x6C230CE01299B3BFULL, 0x2ED738C37CD66027ULL, 0x6788068E3996D3DAULL, 
            0x164D35929756A607ULL, 0xB38CDF505B5AD354ULL, 0x88B9E1B1B9948D1EULL, 0xB86CBE0265EB332EULL, 
            0x0EE364E8444B248DULL, 0xAAEE9EEF3493D7ADULL, 0x9A38CC78102F1095ULL, 0xA41561743EAE8F49ULL, 
            0x39AC8C67DDD24E07ULL, 0xFB1F9C0FC8C57F4EULL, 0x6F9453F848ABCB3DULL, 0xCF6FA72D41D59948ULL
        }
    },
    {
        {
            0x18CCA4C0BD8BA902ULL, 0x2B0C2EF50EAD2854ULL, 0x72AF76FC3D98C61DULL, 0xE5D52B6EEF8863B2ULL, 
            0x409D8EA02EE8F1A7ULL, 0x4DEA18B82D23EF8DULL, 0x523F79969821BA38ULL, 0xF9333D861AD01E55ULL, 
            0x3C46FBDB018333F2ULL, 0x88365F731C09BDDAULL, 0x8105BF954AC34B8FULL, 0x6BC0E73E60B84F66ULL, 
            0x6EA3AB4A4BC218BFULL, 0x5F09860BD0EA1A7BULL, 0x222F0CC6E5144CDFULL, 0xE9C0EB28B0A494C2ULL, 
            0xC6A6FDD793DE7FC0ULL, 0x6EDA0AB68F1E5835ULL, 0xE6F7E5BA1996B07CULL, 0x9E2E027D285F6BF2ULL, 
            0xC7FB4D4CD7FCC821ULL, 0x6662F4C113E0D912ULL, 0xFFA246CA64212EDCULL, 0x568DF0066DEBC9B6ULL, 
            0xB937AA831C75B2D4ULL, 0xBBAD2D124C37C83AULL, 0x31418F38F42475C2ULL, 0xE986E04B8C3968A9ULL, 
            0xF92FD4836DAC5F0BULL, 0xD2F91CEC5022B94CULL, 0xD270377172C51F6CULL, 0xA82D8D99236662F2ULL
        },
        {
            0x015FF347F085F4FDULL, 0x31DAAC43EFC6C1C9ULL, 0xBB4322D80000AC67ULL, 0xC01F4A8AB70E1682ULL, 
            0x7C9D8D8C94C1B7F2ULL, 0xCA33D5F2FF198D70ULL, 0x61FCE2D159553B12ULL, 0x7634C5AB54042FD7ULL, 
            0x70DB8F431E686AF3ULL, 0x493DB2049E4CA64EULL, 0x1807FE437DA023FBULL, 0x02AF91374D6CD684ULL, 
            0x4096709E4090516DULL, 0x12D0A7D05DE2DF54ULL, 0xEF4DEC5E37E0196EULL, 0x7657D975724D7D71ULL, 
            0x15359CD175B6B271ULL, 0x673702B90BF51E2DULL, 0x30A944957A87FDB5ULL, 0x19AAE623A04ED2C3ULL, 
            0x87A7B7E406206567ULL, 0x4C4EF9DE493FA00AULL, 0xD898BC4EB1751349ULL, 0x3EBFE0A7CFD581DBULL, 
            0x8841AE573AC48CCFULL, 0xFAFD4AA915432753ULL, 0x7D2B361AFA0432A6ULL, 0x41ACF0C33EC1A963ULL, 
            0xDF309C4029CBBA82ULL, 0xC17D73004105631CULL, 0x163BAAE1BD510208ULL, 0x0F28FB9B98DB3086ULL
        },
        {
            0xDB41E99F0E413EB8ULL, 0x64CBAC81F9EF200EULL, 0x0198737613974595ULL, 0xDA6F33AF041EEF97ULL, 
            0x59077F9ED8FE0C94ULL, 0x8B8E6467AE45E924ULL, 0xACF5CA938345EFD9ULL, 0x368669E5874D8F22ULL, 
            0xDF143C62C2A181B7ULL, 0xBCDA0C23BCD15ED5ULL, 0xC7415F46C870F793ULL, 0xB05BB0D9D54AA0D7ULL, 
            0x9189BA56C3117205ULL, 0xA367C0035055BF62ULL, 0x2FD36919EBEC6CEBULL, 0x7E1F6E5292B684B9ULL, 
            0x0B806C4B683D3ECEULL, 0xC25F99C9F8A821C6ULL, 0x281FD2DE01C827EEULL, 0xAA4158F3B70A5531ULL, 
            0x22409515B699633CULL, 0x209EB416AA3F10BCULL, 0x5847EB805F4FF0BEULL, 0x14B8A347D6DCC3FDULL, 
            0x1E43FF7CF18E13BAULL, 0xA00C43F71BA143CBULL, 0x1DD1E19AC2439288ULL, 0x085E9DC13B5A9362ULL, 
            0xCC84D48FDC29401DULL, 0x6378AA10121DBF22ULL, 0x19EDD857E28B0619ULL, 0xBFDA5E495D3B6D90ULL
        },
        {
            0x0610E9438BDA5AB7ULL, 0xD41815A6B3EC0BB8ULL, 0xD287841CBAD87DC6ULL, 0x0BE5D8F5EDE2AD42ULL, 
            0x9865B3865204480FULL, 0x0CD2432311C2B99CULL, 0xA33F17C9D0F71E22ULL, 0x6A55D72730FC8F94ULL, 
            0x1AD8F59FBC84E0F2ULL, 0x82359D9EE7BC9961ULL, 0xE0A3D13718FF8CCCULL, 0x7C4719152400E742ULL, 
            0xFF7F99C1D85D31E5ULL, 0x2FBDEACA5FDD3BB9ULL, 0x10C91D49ABA5B4DBULL, 0xC52C0457379CCBD0ULL, 
            0x31550CA531D99EF5ULL, 0xDED1BB6BA7183C51ULL, 0x84DC86D7A9943F70ULL, 0xD7FC686C814B8154ULL, 
            0xC4C04531B156C8FBULL, 0xD8A842430C41338FULL, 0x928F6C79C0D76572ULL, 0x64A109F0D05111E2ULL, 
            0xBC3F1F0B7237C961ULL, 0x490A752814EFF17FULL, 0x708959159C951AF6ULL, 0xCB8242D05310294CULL, 
            0xFFB2D6E73381D3BFULL, 0xD64C8B257B4159B9ULL, 0x6E103DB5912F20AFULL, 0x7AD1C86FFFCF7AB4ULL
        },
        {
            0x8102F5EF99AF26D3ULL, 0xF74010524D52F2E2ULL, 0x1427A038AA36839BULL, 0x857BD49A1FC55459ULL, 
            0xD34224124692B4A4ULL, 0x612D581F260DD2BBULL, 0x5D2F4DB3AF90ED97ULL, 0xB800359AF0CE84B4ULL, 
            0x546AF89100377F1BULL, 0xF640CE2E650D5AB3ULL, 0x68C4F0B67D927A30ULL, 0xD56F402C88481AD1ULL, 
            0x62DB0E66ACF016DCULL, 0xB694B05EB8C6A065ULL, 0x13C0F4BE25FB1452ULL, 0xEE0DED86710A4A86ULL, 
            0x0469E8AAF505A00DULL, 0x2A8D4B9CD33C8208ULL, 0xF47C614630D9A351ULL, 0x7A0ACF8D2577DC8EULL, 
            0xB60EA749EDCBD7A6ULL, 0x585CED2AC66CB992ULL, 0xBB4D2B9E8A5A909FULL, 0xBA35314CA143732EULL, 
            0x45C3BF22E66025C8ULL, 0xA55E76ECF4F42388ULL, 0x99A43A43D1229E2DULL, 0xC089A2A5F1748FBFULL, 
            0x21F4A758155FA242ULL, 0xC96F29A361438876ULL, 0xE3A6CE529D535487ULL, 0xD5345CAF36D02420ULL
        },
        {
            0x21C46FB9B4ADC79BULL, 0xBE05C89BFF5D2FBBULL, 0x99CCD41EEE82E0D5ULL, 0x1C14DF54BEC1FF70ULL, 
            0xA7851192EC4A650EULL, 0x606F8DD7880091DEULL, 0x63C5AFB14C647C5EULL, 0x9E11E97233D12BA9ULL, 
            0x48525E92AAD2E072ULL, 0xC46B05EF3E7C7144ULL, 0xF138DED99CBF5240ULL, 0xD978165AC35BEA66ULL, 
            0xF9A3B0A2B65C2BA8ULL, 0x48B717A4AF989C2FULL, 0x63A9AB698E5DD553ULL, 0x6602E9FEB8A12772ULL, 
            0x8BEE402473635EBEULL, 0xA9D7584395F5928AULL, 0x49A39736F21976B7ULL, 0x346285EB0E459ABFULL, 
            0x5670F20DBCC922C7ULL, 0xE954DB4F92CAB634ULL, 0x13CB731040FAA373ULL, 0xEA36B2BFA9D730C7ULL, 
            0x898B30362C94C3C2ULL, 0x32D1AEA999C1BC2FULL, 0xDB3FF4843088BCD2ULL, 0x6238101ABBC83E8BULL, 
            0x3EADAE6485C367DAULL, 0x219003447DECDB57ULL, 0xE83276AD9ED49969ULL, 0x7D6EDE210B1D94FCULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseHConstants = {
    0xD6682C31637661F8ULL,
    0x585C57D90200C305ULL,
    0x36B2BBF56CEDF0A3ULL,
    0xD6682C31637661F8ULL,
    0x585C57D90200C305ULL,
    0x36B2BBF56CEDF0A3ULL,
    0x5EA40F7D3B1D0B93ULL,
    0xFDE65782C47092DDULL,
    0xA0,
    0x3C,
    0x05,
    0x0C,
    0xBF,
    0xD4,
    0xDB,
    0xD4
};

