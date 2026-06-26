#include "TwistExpander_Rugby.hpp"
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

TwistExpander_Rugby::TwistExpander_Rugby()
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

void TwistExpander_Rugby::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9936742785490349730U;
        aCarry = 12739948137455626593U;
        aWandererA = 10558267691533260019U;
        aWandererB = 15321251607188081063U;
        aWandererC = 14045771017966856773U;
        aWandererD = 11748595447321656806U;
        aWandererE = 16583021787920905067U;
        aWandererF = 13999617708728831284U;
        aWandererG = 18026739037477279341U;
        aWandererH = 14615619184843234327U;
        aWandererI = 13756218346686600897U;
        aWandererJ = 14302201233298425916U;
        aWandererK = 14636266506932996271U;
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
    TwistExpander_Rugby_Arx aArx;
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
    TwistExpander_Rugby_Arx aKDF_A_BArx;
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
    TwistExpander_Rugby_Arx aKDF_A_CArx;
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
    TwistExpander_Rugby_Arx aKDF_A_DArx;
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

void TwistExpander_Rugby::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12799566059855484111U;
        aCarry = 11363406579860062404U;
        aWandererA = 17381341845807740120U;
        aWandererB = 10741107214143325755U;
        aWandererC = 9888438699376688191U;
        aWandererD = 12639888246181583940U;
        aWandererE = 13582244409395437082U;
        aWandererF = 9746277830956820735U;
        aWandererG = 11539971950425170631U;
        aWandererH = 13786290982089331869U;
        aWandererI = 18157495024266090086U;
        aWandererJ = 16311395495577602253U;
        aWandererK = 16024134519291759383U;
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
    TwistExpander_Rugby_Arx aKDF_B_AArx;
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
    TwistExpander_Rugby_Arx aKDF_B_BArx;
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
    TwistExpander_Rugby_Arx aKDF_B_CArx;
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

void TwistExpander_Rugby::Seed(TwistWorkSpace *pWorkSpace,
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
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseA invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseB invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneE);
    }
    // KDF_B PhaseC invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneA (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneA);
    }
    // KDF_B PhaseD invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    }
    // KDF_B PhaseE invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseF invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneC);
    }
    // KDF_B PhaseG invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneD (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseH invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_Rugby_Arx aSeed_AArx;
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
    TwistExpander_Rugby_Arx aSeed_BArx;
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
    TwistExpander_Rugby_Arx aSeed_CArx;
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
    TwistExpander_Rugby_Arx aSeed_DArx;
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
    TwistExpander_Rugby_Arx aSeed_EArx;
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
    TwistExpander_Rugby_Arx aSeed_FArx;
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
    TwistExpander_Rugby_Arx aSeed_GArx;
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
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
    TwistExpander_Rugby_Arx aGrow_AArx;
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
    TwistExpander_Rugby_Arx aGrow_BArx;
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

void TwistExpander_Rugby::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Rugby::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rugby_Arx aTwist_AArx;
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
    TwistExpander_Rugby_Arx aTwist_BArx;
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
    TwistExpander_Rugby_Arx aTwist_CArx;
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
    TwistExpander_Rugby_Arx aTwist_DArx;
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
        TwistExpander_Rugby_Arx aGrow_AArx;
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
        TwistExpander_Rugby_Arx aGrow_BArx;
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

void TwistExpander_Rugby::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 1, 3, 0, 1 with offsets 1284U, 3183U, 1071U, 3874U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1284U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3183U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1071U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3874U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 0 with offsets 1415U, 2177U, 5043U, 7632U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1415U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2177U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5043U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7632U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 3, 2 with offsets 6320U, 6301U, 7576U, 6613U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6320U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6301U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7576U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6613U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 3 with offsets 5054U, 238U, 382U, 1415U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5054U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 238U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 382U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1415U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 1808U, 817U, 844U, 639U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1808U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 844U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 639U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 1451U, 14U, 1070U, 1748U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1451U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 14U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1070U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1748U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 1, 0 with offsets 1496U, 1802U, 1057U, 243U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1496U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1802U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1057U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 243U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 96U, 2009U, 311U, 1833U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 96U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2009U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 311U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1833U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1412U, 676U, 691U, 1180U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1412U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 676U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 691U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1180U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Rugby::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 1 with offsets 5623U, 1588U, 166U, 5951U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5623U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1588U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 166U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5951U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 3 with offsets 548U, 4824U, 5838U, 2636U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 548U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4824U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5838U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2636U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 2 with offsets 2160U, 1486U, 7157U, 5825U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2160U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1486U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7157U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5825U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 0 with offsets 2320U, 7742U, 3053U, 4436U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2320U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7742U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3053U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4436U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6662U, 2771U, 526U, 7024U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6662U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2771U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 526U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7024U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 2, 1 with offsets 128U, 238U, 623U, 780U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 238U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 2, 1 with offsets 169U, 1523U, 1803U, 1490U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 169U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1523U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1490U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 2, 1 with offsets 431U, 685U, 1818U, 1895U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 685U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1818U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1895U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 2, 0, 3 with offsets 1681U, 87U, 1995U, 1504U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1681U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 87U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1995U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1504U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 912U, 1491U, 598U, 1058U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 912U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1491U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 598U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1058U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseASalts = {
    {
        {
            0x86D2260BFC66E32EULL, 0x17F301DFD05F6DEDULL, 0xFF5FB0777125F2B7ULL, 0xAE8AF575A8CA0CA0ULL, 
            0x81DE7A28CC71F576ULL, 0x474FECD0EE3A30A7ULL, 0x483625CB4557E1DCULL, 0x85D7388D26BFDBFAULL, 
            0x3099CE28063FF41EULL, 0xE1B68DF366CDABAAULL, 0xB5F1EC0FE2BB441AULL, 0x2D2BBB956ED81C07ULL, 
            0x37053A40538648A5ULL, 0x6E6E400F7384806DULL, 0xE2F86BC6D44B8336ULL, 0xCC39C9096EEEACC3ULL, 
            0x810DF16435C29B0BULL, 0x30F491F0144D0E25ULL, 0xFF890C414CD7EAB4ULL, 0xF419367E0EF99AB2ULL, 
            0xFE6CDC49D19CF8EAULL, 0xB44DE89E14B1D239ULL, 0xF83007D9B5E54C40ULL, 0xEFD9B58B71ABE2E3ULL, 
            0x17F2C74CAFB4D99FULL, 0x3857BAD1F105343BULL, 0x5D3106E8EAED9810ULL, 0x55945D53B46C4A45ULL, 
            0x68F3B79D70B98A49ULL, 0xEF4827B86FAD35D4ULL, 0x9A86C12F923AED9DULL, 0x6CD3F029E5E4B6FAULL
        },
        {
            0x8F0244A645E332F9ULL, 0xD8C7F0FAC364FB77ULL, 0xEBBD5C813AB244E3ULL, 0xD72282C015A24338ULL, 
            0xE6047046DF925693ULL, 0xFB7101DE6CEF8EC5ULL, 0x78CBDB992A9F2BA0ULL, 0xA68555AB1DF5A7CCULL, 
            0xC54C03EA26D13040ULL, 0x085ABF6275521E6FULL, 0x7C7400DB960AC8EFULL, 0x1089ACCA8C6DCBE9ULL, 
            0x6096356352844EE8ULL, 0xB4F13DBDD8D36169ULL, 0x7351CE85F945AAF8ULL, 0x2F373C2371000909ULL, 
            0x1606812B135CEF64ULL, 0x689AE4C0D8F3317AULL, 0xD4B4630ED9C2255AULL, 0xA6AC8910B6F41D15ULL, 
            0xCC138650F9396EEDULL, 0x4FE15CF90EFA2701ULL, 0xE924F25D628F4912ULL, 0x15A0B56C81A47DF4ULL, 
            0x27364C0F0F549FEEULL, 0x7CEE18850F1AB628ULL, 0xACBE9CA606AA7174ULL, 0x0EE250050C63B08EULL, 
            0x5FA129463F4D206BULL, 0x6D95A780F6957FC2ULL, 0x0E1098F31F6ECE75ULL, 0x9317DD9DC3254AB1ULL
        },
        {
            0x942F405B7D6D769EULL, 0xFA3F235CDBEDBC65ULL, 0x5EC20C34FB07E794ULL, 0x4270EE62AC7F8397ULL, 
            0xC983E05AFF7C8DD5ULL, 0xA766CD15C0DD7DEAULL, 0x9F197FA2D8FC3209ULL, 0x5320122FFBF3A3AFULL, 
            0x848B7DD6032204C1ULL, 0x272E23BDAFFE349FULL, 0x8123F37D7E1A91D0ULL, 0x61C5BFD461296713ULL, 
            0x30C7562417A5CE5DULL, 0xFF082B49F3CE4570ULL, 0x062B5011E488696DULL, 0xB2EEA562BACE718CULL, 
            0xC674BD553DEB4104ULL, 0x6E850AECBC833AF6ULL, 0x723DB97CF28E042BULL, 0x67889273B44F7CC4ULL, 
            0xD15258BC9B30358CULL, 0xDD5267EA002DA047ULL, 0x872CC3542950ED1DULL, 0xEAF607166A560D1FULL, 
            0xEF9338495F2E86EBULL, 0xC1EE07BB59B54355ULL, 0x1EF668673A8DF42BULL, 0xB0B9ACCAD71CAE93ULL, 
            0x2CA4596F2EF4E5A1ULL, 0x4EA1A0F6C6283AABULL, 0xB4052FF964DC380AULL, 0x16046128F18FFF7CULL
        },
        {
            0x57535B81F38325C1ULL, 0xAFCDA275122F9EFAULL, 0xBC1970E97202EAC7ULL, 0x0B6BCCA1FE39B1F3ULL, 
            0x6451B9DFB0AA0910ULL, 0x226B245830FA5D89ULL, 0x6E3D197704FD5A9DULL, 0x1AB6C6E20E48A76DULL, 
            0x5B145249DB96E292ULL, 0x931EA4F2264E3478ULL, 0x5BD7C954DDF675D7ULL, 0x697378C7B99E4933ULL, 
            0x11FDB013A6CC2505ULL, 0x11CF71B50241B23CULL, 0x0D005DFBD7379419ULL, 0x4C202414CA42B315ULL, 
            0x39117C797961F3ECULL, 0x4B37C24173AC7703ULL, 0x5604685C8A605604ULL, 0xB22CD8B3BA8B47F0ULL, 
            0x910048B4EAF349C1ULL, 0x0EAAC3D46B219B61ULL, 0xA3C0B7CBF98BF23EULL, 0xAE0BF2420916F0C5ULL, 
            0x20D835733FD4B0B2ULL, 0x19EABAF19D1BE629ULL, 0xEE01466FCDF89B0BULL, 0x6306618264FD5532ULL, 
            0xA1B5B51EF9008839ULL, 0x21AFF87877B93E40ULL, 0xC464D2197C97D92BULL, 0xD615E84987EF3166ULL
        },
        {
            0x318752EDE2A5D7F6ULL, 0xD141B65B011E3446ULL, 0x28A2AA0DF26774EDULL, 0x0A0CD672DCC7AA1AULL, 
            0x0F810810327F410BULL, 0xF8A3B5BE00C02CABULL, 0x924AEBBA2C2D1BFDULL, 0x1D2953B6A653A3BFULL, 
            0xD1DFDE4754D8B0E6ULL, 0x4BD926153DAE9CC7ULL, 0x1296E96EEBCA9C86ULL, 0x4CDDD5BB78247E71ULL, 
            0xD4A749B4D31648F7ULL, 0xE173BD936C0D3483ULL, 0xA78E58E93640299CULL, 0x0227F23E3221D623ULL, 
            0x4D4B35C61B5BEB66ULL, 0xACBC520F85BF1F03ULL, 0x3142679711613EFFULL, 0x4D951CD810564353ULL, 
            0x4DC9C12FFFBB0F6EULL, 0xD84C2AB5DAD74538ULL, 0xC32E1D3719B62CD5ULL, 0x2CD28A8B679451D4ULL, 
            0xC4BDA72343F6D77CULL, 0xA97DA26400FA420AULL, 0x30812F8EBF3DAD1BULL, 0xC4D3D4776D10083FULL, 
            0x8591DD61BBD086E3ULL, 0x21BBDEF01867999CULL, 0x5CA1E55CB735ABB3ULL, 0xADB4B534B65322B4ULL
        },
        {
            0x8EFD4CC289E3C348ULL, 0x70B7265E978D34E8ULL, 0x0BB9784B36B9073BULL, 0x3CA3E19034F6ADC8ULL, 
            0x9455DD084BC5C391ULL, 0x9115B5789A4054A1ULL, 0x43A9EEEF13E42C0FULL, 0xAD1738C32238512DULL, 
            0x07916E632A3BA4FEULL, 0xACAE1F0E14EE92BBULL, 0xE2C2753AB95154B2ULL, 0xDE341C49194EA239ULL, 
            0xD355AD0DAECC0E8AULL, 0xBF32D567DC7B75B8ULL, 0x0C6C570797690117ULL, 0x48F7A0E541651D8AULL, 
            0xC83810CE8FBABB51ULL, 0x54DF2758C94E39D5ULL, 0xA021EAF3A8CAD6DAULL, 0x796801D98A70EA9AULL, 
            0x0C1BF489FB67EC26ULL, 0xB94C0D810A4C6FBDULL, 0x81D65EBD4232A355ULL, 0x326ED0C532C6F098ULL, 
            0x6B314D69D85A816BULL, 0x15AD1E7DB75F177CULL, 0x57319B057D2C1D6AULL, 0x8CA95D7E778A5529ULL, 
            0x4BB709774C93EA99ULL, 0x43355AA5F1BBB662ULL, 0x606F4617B68456AFULL, 0xD4553C78226F2777ULL
        }
    },
    {
        {
            0x0E6938CF0C2D7BC9ULL, 0xB9B3F2E4F32FE9A4ULL, 0x300A996B5D6199CCULL, 0x7CEF1DD3C94FA02DULL, 
            0x00CCCA66F082044EULL, 0x19739D8A6A929274ULL, 0x3EA129996460E5E3ULL, 0x142AD98DA33B91EDULL, 
            0x9E310B5369332E0DULL, 0x0C8F8EC59A9945FCULL, 0xB2772C460E8FE61EULL, 0x18E6EEA22B0493CCULL, 
            0xA25E0F1A1926C5E3ULL, 0xF3110F9B7F11BA49ULL, 0x3BA91B1C310EB01BULL, 0xE91FAAAA1C399133ULL, 
            0xE1F673979B5E1691ULL, 0x60F59176D5ACB1DDULL, 0xEFA643C80BA2A0ACULL, 0x5C2F4670D1A42FFCULL, 
            0xF41E4C58854F305CULL, 0x65AD8A7D699B2247ULL, 0x234E97CA2024B7B2ULL, 0x851BCF70EFCCD8D3ULL, 
            0x806EE1D101F7D811ULL, 0x342B9C8193AA30CAULL, 0xFF09C690805AD2CEULL, 0x177825F8FD93A471ULL, 
            0xC7B4CA8DB5C2669DULL, 0x6407A548E0828ECEULL, 0xFD2E112E875CE270ULL, 0x5A34D6750FAECFBFULL
        },
        {
            0xFD655A92B9C31E70ULL, 0xA4C3EF124D397B39ULL, 0x1B6C3E9F148A44B1ULL, 0x79B8E2347C7587D9ULL, 
            0xA83532AA2E3D5356ULL, 0xE818D17AEC539F46ULL, 0x4BB4326265B50C4FULL, 0xAA63040DDB2B5944ULL, 
            0xB99F9E74D1ABF455ULL, 0xFEA783488C49B69DULL, 0x86A83DA3E3B0D58EULL, 0x923D223FB7FC6AC9ULL, 
            0x3234A5EBF7B8FE18ULL, 0x53FFA6457FCDE6E5ULL, 0xBFEC1848EA8F9486ULL, 0x9F1852D5CCBD82E0ULL, 
            0x3E94920B658C89D0ULL, 0xFB3AB4D9E934E3A2ULL, 0xFE1D547F78A751D2ULL, 0xFFE299BD873F6EB2ULL, 
            0xF9C17ED2A1A3A0FFULL, 0xCC4BF827DE2DE2CFULL, 0xD000062D80603558ULL, 0x3B351D696A5949E7ULL, 
            0xE79931DF51CEAE74ULL, 0x589E7C0928FA7FC9ULL, 0xF1E911C6C9515305ULL, 0x75C0441666AC151EULL, 
            0x13DECFD612CD743BULL, 0x77B29363C59985FCULL, 0xE277B20D244F565FULL, 0xA478B68184CB4E15ULL
        },
        {
            0x70CA938EFA393CF1ULL, 0x5DC7D0178B3FF6F8ULL, 0x0936CC6A6F17C4ADULL, 0xB5D8F9C4EB1D8456ULL, 
            0xD3076E548087497DULL, 0x53B04B69EC1A0D11ULL, 0xE5D892411E310811ULL, 0x327FD0FDC4A0E684ULL, 
            0xCD3D4FE764C698DEULL, 0xE8F9B5942009B688ULL, 0xED184102356DC0E8ULL, 0x88BFF521D6347FB2ULL, 
            0xB8024CE3A5E106A2ULL, 0x4F2B9B40976AADF2ULL, 0x150376F339EC300CULL, 0xFA00474E37FFFBBAULL, 
            0xC790045C3561FA77ULL, 0x8821FB58692D33A6ULL, 0x648F082B58D3618FULL, 0x615A0D5B055E8272ULL, 
            0x7F089E123037EC46ULL, 0x3D3FB838320A0030ULL, 0xB605FF14A03E9157ULL, 0x9A1594CAFE303C49ULL, 
            0x52A9AA2CFFBD0AE8ULL, 0x2D5C2BBFEF482146ULL, 0x9F259A44E10519BEULL, 0x4B3B71EB0877E2E0ULL, 
            0x0B341146A7CC92A6ULL, 0xD013516A1FD1C806ULL, 0x0EBC56C45005A5D5ULL, 0xAC37A47B2B692A64ULL
        },
        {
            0xE2CB127C36334D19ULL, 0x46956E887EF6BE1CULL, 0x2828B8E251795704ULL, 0x5AA98F0E7057EBC2ULL, 
            0x7E1FA36D7F276943ULL, 0x257F4B1FC269403AULL, 0x75B258E109D80A8CULL, 0x247FEE1D77F7D3F0ULL, 
            0xBC34F71CFFC4D200ULL, 0x24A9A468262C3BDDULL, 0xD59F767FE42747DAULL, 0x549AA7566B6BB128ULL, 
            0xE3A13E14DC25E8A9ULL, 0x8A7A2DE111AC32ABULL, 0xA2CAB929552E904DULL, 0x75340B8D31EDD207ULL, 
            0xF03ADAA28300754DULL, 0x0071DCC6B640B5DEULL, 0xCAEFDC091FD4950AULL, 0x7DD192B995E06CAEULL, 
            0x499D82738597E013ULL, 0x41F6B01FED937BA3ULL, 0x44D9182A92492843ULL, 0x61B7CF92EF5D69BAULL, 
            0xBBE5657E22281F41ULL, 0x9F1D6712E294241FULL, 0x724BAB93694E6365ULL, 0x612A2C0A3FE03A3EULL, 
            0x50AA94147112291EULL, 0x512D0869E8A6C576ULL, 0xB68D3806A48F051EULL, 0x5EDF8B58B264A440ULL
        },
        {
            0x095A1E4F91BB2B9FULL, 0x44DA03C47A5E6FCEULL, 0x9E21973DEB0E9494ULL, 0xCA51FF00B67A8B1EULL, 
            0x3061FBEDD5D58D61ULL, 0x8EA962AD1920D169ULL, 0xFA2E487A46E26793ULL, 0x22093C47E84367FBULL, 
            0x36DC33102A30CAB5ULL, 0xC5DEB7686E14DD9AULL, 0xF6F16FB71E90909BULL, 0xE3F77979BB99C763ULL, 
            0x10CE3EFF58A446B0ULL, 0x13DFD6910D8F60E5ULL, 0x52DCB12EAF48E4B7ULL, 0xD939288A1961E68DULL, 
            0xE17B58CEBB8C19F5ULL, 0x3B540EDFDAA1B850ULL, 0xF150316DCE3710F0ULL, 0x37B55508EBD2E67EULL, 
            0x6A1DEEBCD4847729ULL, 0x3AA39D1403ECDEECULL, 0xA971A6A4B5C4D4E2ULL, 0xD36624BCFB462CFAULL, 
            0x0E76EEDAE960BA35ULL, 0xE6BF486287D239FBULL, 0xFCAFADC749B805CEULL, 0x16D815EBDA0F578EULL, 
            0x2719676D493A76E8ULL, 0xB70A4A9443C8253AULL, 0xC5B17A76B1EE2635ULL, 0x67319A099E9FC9D3ULL
        },
        {
            0x9514AA617327DC9EULL, 0x1DDE2A7C366B4A96ULL, 0xEBA915371970175FULL, 0x1806FFAEB8BD42B5ULL, 
            0x41D949B3372F59B5ULL, 0xFCDCF68DDC4C9BF3ULL, 0xDB07D0D31CE71B61ULL, 0xF0D6F15E77753B4CULL, 
            0xC6F40C72809DF939ULL, 0xF21A1AC73BB682EDULL, 0x88C9E5BBF860A4FEULL, 0xE81447F83E4D5F5EULL, 
            0xD1E4451990324EF8ULL, 0x49DE8A7077EA3029ULL, 0x9EE11A9F558BDCFCULL, 0x4D0735E004E12180ULL, 
            0x5D215ED6ED35C07BULL, 0xA9AEBCCB76483A81ULL, 0xCEEED43C50D84B28ULL, 0x14275794861EA491ULL, 
            0x689876E14E286DB0ULL, 0x81F173A04B690284ULL, 0xF9CFA06E4493A11AULL, 0xAA30FCE646C457A1ULL, 
            0x159B0C8DBF7552D9ULL, 0xBF8843AAA5833F75ULL, 0x6BBB2FCB041A3482ULL, 0x8180625EEBA70700ULL, 
            0x0D785DD62914DF7AULL, 0x4BF225980840E472ULL, 0x793C8A427EB2EC8CULL, 0x7C9E3CB51224C666ULL
        }
    },
    {
        {
            0x22D464513EB4D92EULL, 0x32E98652F0EA3712ULL, 0x403E5BE7D5BD3147ULL, 0xBE07664864D4B05CULL, 
            0x2D0590F51EF20840ULL, 0x63D46B4870765EE3ULL, 0x39E5AE9932BDC45EULL, 0xC3A896C487706813ULL, 
            0x443192A1E4A2A711ULL, 0xE85C66BDF436E08EULL, 0xDA00D1D23831648CULL, 0xDC6388C6FE42247AULL, 
            0xC527E57031045A10ULL, 0x96A4E4533130489FULL, 0x9F666C18F454E359ULL, 0x1A80098461EC6186ULL, 
            0x03BF9154D4A29CC9ULL, 0x01E115D39D8F0645ULL, 0xADB820C1DCA6293EULL, 0xE5497EAC6C991A17ULL, 
            0x04772842A5B2D586ULL, 0xC84B40409C4BF7F4ULL, 0x56344DB76FA6C836ULL, 0xE24FBF32E6CB6545ULL, 
            0xC1F89BA42A8A1874ULL, 0xC3E39B8952FEE7B6ULL, 0xB4C61B1AC901A9A5ULL, 0xAE7FBBB73916E5EAULL, 
            0x311338DF282EF801ULL, 0x21491B1990BCFF2FULL, 0x59A10126CDAE8FECULL, 0xB469FFB3F56C5BBCULL
        },
        {
            0x455FAFA54F772192ULL, 0x7593CAE86CA87EF3ULL, 0x10A331996AB50D12ULL, 0x5C60B1C1B41FBE0FULL, 
            0x40BCF87957F7ED93ULL, 0x326C40EA1CCA4BF5ULL, 0x6450D98EED37D46BULL, 0x36CFC8AD72047120ULL, 
            0x3832E2C939231901ULL, 0x0616E39C55AF9F9DULL, 0x4010B033275925F3ULL, 0xC946B50419FB8E6BULL, 
            0x61637CD259E63B1FULL, 0xCFDBDC3369B75148ULL, 0xF3E9B124EFF025B2ULL, 0xB1DED13469037D18ULL, 
            0xAF6CCA351C63F71FULL, 0x2F5049C1FCEA5816ULL, 0x6A6EC11DE4A64226ULL, 0xD88FFB5BB4B3BFE0ULL, 
            0x0975CCA94F9A0E50ULL, 0xBEDAF77609AA08D7ULL, 0xCF15EE7644618716ULL, 0x73446C8434A1469EULL, 
            0x3657703C04D1DE94ULL, 0xFE00415030A71F39ULL, 0x7BB358BC2176F64DULL, 0xF9D930879C08C811ULL, 
            0x6984C2F5FCE9D579ULL, 0x2622D577EDCD604AULL, 0x3CE550F99E640426ULL, 0x55147A1D9B3B668DULL
        },
        {
            0x22B53323878807C7ULL, 0x8BDF92F4587AEC39ULL, 0xDAF00CD0F83FEA64ULL, 0x23D8760AABE07EF1ULL, 
            0x48623185853E5782ULL, 0xD16478F78159C4D8ULL, 0x0DD5BF3C5A0F8822ULL, 0x5054C9A18976AC2BULL, 
            0x92C462A13A3C2AC3ULL, 0xB04B43434C7E6853ULL, 0x0CAB0FEE16581A77ULL, 0x8DEC1E473C80FCB9ULL, 
            0x6C9ED9CAA87F4F77ULL, 0x4D51E7AADAA5E58BULL, 0x89DA7BFBD3D378C1ULL, 0xF68BF196C19EC5E0ULL, 
            0x39DC508F754E2921ULL, 0x3255021D9A0D4EABULL, 0x495A0B8DF5F35A23ULL, 0xEEF35A0D49D79A06ULL, 
            0x9068B35B26275C9DULL, 0xA6C19E2CD3B72141ULL, 0x997998EAF76E3F89ULL, 0x21C8795192B75769ULL, 
            0x1099A37FC5575ACEULL, 0x66551FFF0B7024F7ULL, 0x9CB093845543F5EAULL, 0x10EB7BFCEFC192F6ULL, 
            0x6E67EACF91A2EA30ULL, 0x9D3E35A341790F89ULL, 0xCDA2557F82A5DCA7ULL, 0x271F5964478F9899ULL
        },
        {
            0xCFDC4B872417499AULL, 0x620E25CEBE1768D5ULL, 0x4921C79F203766E8ULL, 0xAD36302493F7EA16ULL, 
            0xF104556160CE56B9ULL, 0xEDCBEED360D9848AULL, 0x60F26A0005C3B627ULL, 0xA3E2A601A4003F66ULL, 
            0x00B666DEDEB04E43ULL, 0x01D4A5E64FD8922FULL, 0x45633288AAE913F9ULL, 0x8EE264C42A3049BDULL, 
            0x6D0D81216F3F140AULL, 0x86660C4F1EFC5E9FULL, 0xCFCB993C527F50EBULL, 0x8BA3EC7F3A48A9EAULL, 
            0x24A558B2FDE8FDB1ULL, 0x46D68E7517BBB2ABULL, 0xC8BA01DDA09AE35AULL, 0xA0F9F08418739215ULL, 
            0x52DA142FABEB4817ULL, 0x31D74430E87A69BDULL, 0xB9B13F942FAB7352ULL, 0x0E7E9F41E7BAC026ULL, 
            0x4871CB871F50979EULL, 0xFD577150C964A82DULL, 0x890108BC5D8E21D3ULL, 0x111C33673A6C6096ULL, 
            0x1A10EABA9FD87E49ULL, 0x0202E12D90FFE971ULL, 0x23F7D300857F5C8EULL, 0x1A000FE8C816157DULL
        },
        {
            0x899A79841D814CE1ULL, 0x44B35B1A4532B29EULL, 0x7492A30CCE398A0FULL, 0xF3797868365B753CULL, 
            0x422039288401F1E1ULL, 0xECC2C56243A4E0BDULL, 0x4B4198ED768D5658ULL, 0xF0065546175DD7E9ULL, 
            0xD57740FE6F76DD73ULL, 0x1A7B80D5C5992438ULL, 0x4CB0E0D93390A314ULL, 0xF3E7B9AE639BEEB0ULL, 
            0x248BD658629666B3ULL, 0xA8764B551AE5A00DULL, 0xECBF6A60F7A3BB83ULL, 0x96200E9E697219D2ULL, 
            0x5FF02A1A879F97B4ULL, 0x5955D7B3A3E86A75ULL, 0xA63EEC4BDEFAEF69ULL, 0x41D4740C52BC221BULL, 
            0x64D00D027207B16AULL, 0x015E18058B9D7C15ULL, 0x5492BBE18ADCF5C4ULL, 0x7DB50AFD71159038ULL, 
            0x3C0DF91894E47ACBULL, 0x562428375A14A542ULL, 0xD0A63034BFADB36EULL, 0x9A260DBDADA14C7EULL, 
            0xA7DBF068427952AEULL, 0x1AF78264171A294CULL, 0x7C2A20EEC7C9922DULL, 0x94903BB13298FD72ULL
        },
        {
            0x3D0BDA15151B0EC3ULL, 0x18F7020BE411B96BULL, 0xD3F30E873ADF81D8ULL, 0xCE9FA54B25719E9DULL, 
            0xC14CB755A8C0B37EULL, 0xFC778601A9BFBCC6ULL, 0x4C38F3AFC47D236EULL, 0x0DE5AD37506C63C4ULL, 
            0x6EA60C0D2E9CAF03ULL, 0xAF96ED8F22F49DADULL, 0xA59349F8E72DA258ULL, 0x91AC2E09C862DF6BULL, 
            0x375AB18E05F0EBE2ULL, 0x4873FD03A9B428C4ULL, 0x1FD3E51FE65D3315ULL, 0xCC6BFA13BE4CE4A7ULL, 
            0x63082C599B4261C8ULL, 0x500BE6C0558C32C3ULL, 0xD01177B6AAA57A98ULL, 0x40F338651B9D8E92ULL, 
            0x287EA86D3D65286AULL, 0x9262A9BAF7C86628ULL, 0xD665F39D4BAECF3CULL, 0x8838DAAC3D8A5174ULL, 
            0x51F9441FCD00A07AULL, 0x00FE42F05ADD23E5ULL, 0xD603A112F18F6459ULL, 0x4FF682CC364CA15CULL, 
            0x46D68D7797FE2854ULL, 0x711C803B491591BBULL, 0xD27B3B57336C9A5AULL, 0xC5310B67F1F15CF9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseAConstants = {
    0xEFBB4ACCDF73FD2CULL,
    0xCD05BE270B61745AULL,
    0x8A9C72949CFD02DCULL,
    0xEFBB4ACCDF73FD2CULL,
    0xCD05BE270B61745AULL,
    0x8A9C72949CFD02DCULL,
    0x9E25493D56857013ULL,
    0xAE9976461AFD6CADULL,
    0x40,
    0x4C,
    0xEF,
    0xFE,
    0x64,
    0x8F,
    0x27,
    0xBC
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseBSalts = {
    {
        {
            0x5AABD768FFDBBC5DULL, 0x1C1EBA20ACC73381ULL, 0x17B75931704D0BF0ULL, 0x009B59B996F182F7ULL, 
            0xFDAB81B11E7D4F15ULL, 0x26CE0E36100DE606ULL, 0x956B8C8CD7A02F6AULL, 0x6F63B0A8F195CA92ULL, 
            0xA213915CE593189BULL, 0x3AF7CEE0FF3C471CULL, 0xC3CB9D63DE06A0FFULL, 0x1F49166E52C1EEA7ULL, 
            0x98CCE5A85CDCB916ULL, 0x641E5984207E225DULL, 0x7BB649423F3E9051ULL, 0x5F89722C5EBBC9A3ULL, 
            0x89AB2CE39D9430E8ULL, 0xBEF7A448775A2F7CULL, 0xDEA0725DDBE25C98ULL, 0x1028B7AFD63488E0ULL, 
            0xB8DE008A69DE61C0ULL, 0xCCFA5C6AC1122E63ULL, 0xD400A5C5899D34B8ULL, 0xF0553846D3906CE5ULL, 
            0x522850568B88970EULL, 0xD26E8F3B6FA78B5DULL, 0x14FB4A570E66FAF1ULL, 0x35AA6F3C61FEE753ULL, 
            0x20EEFAD17A4E4F97ULL, 0xE312AB0BA0A537C7ULL, 0x5F7C2379067AC791ULL, 0xCDA2208933A75823ULL
        },
        {
            0x6A0BDA186EE06920ULL, 0x61013E4CD126F9FCULL, 0xC352D56BBD6D445EULL, 0x083494F2AD65E022ULL, 
            0x7594C344B58AF3A8ULL, 0xA303B88330E99654ULL, 0x98F5033976A76C06ULL, 0xE79725917C119319ULL, 
            0xAC73F06D7B28E298ULL, 0xC44654928D786CB5ULL, 0x3A2B1EA9C1786326ULL, 0x0EFC45B33AE5403DULL, 
            0xE270BD862D73F1B9ULL, 0x889D44246DA16733ULL, 0x19559B721744EA67ULL, 0x64DC2BF5C7E0F041ULL, 
            0x0710D100AB2B99DEULL, 0xC2B63F780633437AULL, 0x0030BFA6F48462A4ULL, 0x896D7C9EFE9D3C4CULL, 
            0x4CCE06D35D25D975ULL, 0x36BF4316F18145E4ULL, 0x29C8FCFEFAC47C21ULL, 0x747CCA2DFE462242ULL, 
            0x2E86347BE11D9217ULL, 0x30A1957E9847A0E6ULL, 0x26A8BE8EB68F9C27ULL, 0xDBD126B73B388C2DULL, 
            0xA53C393BDF870411ULL, 0x72AEE9A2347C850AULL, 0xDE3A776AE4343847ULL, 0x17B67A9F839DE3B6ULL
        },
        {
            0xFB8898576EA27A22ULL, 0x4AD1127C193F1C87ULL, 0xD2C9D698F84A050CULL, 0xD87777C52CD52631ULL, 
            0x507255EA8128827AULL, 0xBE0F2016F18A81E5ULL, 0x3B89998AEC6922C4ULL, 0x1A9FA6484D2A4E32ULL, 
            0xD11BF4013D9EC692ULL, 0xB9F48F00BB48FC90ULL, 0xE439D376B54DC1C4ULL, 0x6943F72EA27FE35DULL, 
            0x84F72928417BD762ULL, 0x7DBC30A35A169BA3ULL, 0x74018F629901E2EFULL, 0x77D0615A83B845C1ULL, 
            0xDC81272B17F473C8ULL, 0xC87490BB949D653CULL, 0x99249BA33FFE3C92ULL, 0x990DA88BA4DCDA86ULL, 
            0x5A4991BB097465B0ULL, 0x9F0D6457BE771103ULL, 0xB4F1A81E8766AEEEULL, 0x9813119C11EC67DAULL, 
            0xA763BE282C3CAA54ULL, 0xA8BD8BB20FAAB149ULL, 0x63272F8B393CEE5FULL, 0x4889DB64C4B2A94FULL, 
            0x1D0F330F00E6F0C5ULL, 0xD86F1A90F846FD13ULL, 0x6BE17157B142FFBCULL, 0xC6BACB96CF7544BCULL
        },
        {
            0x6F7E593D74A2B8A0ULL, 0xE69D8A901A2F53CDULL, 0xEF36D532DA27D65DULL, 0x07DD043C6C0359B0ULL, 
            0x0A9BC1F56FCC906BULL, 0x013E26DC092A9A8FULL, 0xADA82811E8B6CFCFULL, 0x64B2269064D3563EULL, 
            0x26F266E10DB79472ULL, 0xA633C41183A4C21CULL, 0x6EE4B6E96D2D4E9CULL, 0x9FF537D5D346F4BFULL, 
            0xF3551FA5DEC50134ULL, 0x11FD223D5CDB24B3ULL, 0xD4C3D2947628E0B8ULL, 0x0A475BED427A019CULL, 
            0xEF10BAE7E031B7ACULL, 0x712D951FE73B6EB0ULL, 0x4F4AA6BEEBCA3300ULL, 0x5C398202BABE27C8ULL, 
            0x5B396A0B6FF62980ULL, 0x63FE9C934DB69F74ULL, 0x918CE272A5C2D404ULL, 0x3AC9D2BE925E2330ULL, 
            0xD564F15882A9FA1BULL, 0xE11EB33055B26A5DULL, 0x9A4F0CB11AFE9F6AULL, 0xF4BB6AB7F5DA84B6ULL, 
            0x024098523AC19744ULL, 0x3D60E4A21A1E7516ULL, 0x61CFD1432FE83700ULL, 0xAA1BC8F823DDB7AEULL
        },
        {
            0x1FCC05E1F72EDE1FULL, 0x804D4B5E0767CB79ULL, 0x80456D7E3BD8B5D6ULL, 0x9176E12A338BF6C9ULL, 
            0xD26EECB529135DC4ULL, 0xFFB1F6EA0BDC3B49ULL, 0x63599373A96BBDCBULL, 0x89233C78E23F880FULL, 
            0x7DF55C42D8C0FD28ULL, 0x0263DD2E7EF249D8ULL, 0x43959BFC4A18CB59ULL, 0x0DB0F2AD55705643ULL, 
            0xF0F2B734BA5C4C42ULL, 0x8EEDEFEA3CBFF387ULL, 0x1B466FF788B11C51ULL, 0x52C0A2C82EE1E042ULL, 
            0x16D2F3F9DDFDB43DULL, 0x47B9EE62506679E8ULL, 0xFBAD0ADBC3CCA7FEULL, 0x28ACBF4B962C679EULL, 
            0x3A357D5EAE1A86DEULL, 0xFD20D4089AA37789ULL, 0x76C9E7C7BDA10F77ULL, 0x8C1C07F9228D83A7ULL, 
            0x408ADD28CF2735A8ULL, 0x1718CC49D7872EA6ULL, 0x3427E3D18D001094ULL, 0x28F2B1D093ECD9FEULL, 
            0xD9BEBF269862295DULL, 0xBFA9B4B7BD365A4AULL, 0xF1A8BC0ACA490DC5ULL, 0xF61A8C7B73D027C0ULL
        },
        {
            0x261AAAD49D57CC9BULL, 0x6D861FE47E8FBB5BULL, 0xCA870738CB355B07ULL, 0xC176AA8CA901A18AULL, 
            0x3787E572B8BE716DULL, 0x6FD7456EDD01C383ULL, 0x157EB7F968A17231ULL, 0x8B29726CF4535050ULL, 
            0x1B0D02E374EC2626ULL, 0xA4934E6C05B02A8FULL, 0x1DEF8FBFCF46F800ULL, 0x636232332D0239BBULL, 
            0xF1120399BBBAB838ULL, 0xD0F18230820F720CULL, 0x31F5C0D5B17959AEULL, 0x95BCCCBFF06546B9ULL, 
            0x32995B5B13E4E617ULL, 0x9CFF550F62C21E55ULL, 0x476C4603FF6A9BD7ULL, 0x3EAFE2DC4E46C0B5ULL, 
            0xA8ED16D876F955B4ULL, 0xF39F2BF469974CBBULL, 0xF45B6A7F96C63A9DULL, 0xF0B261E31818B58DULL, 
            0x95A36C211322A8F3ULL, 0x3D91B6B4B033E376ULL, 0x517BD9BCA6437A60ULL, 0xDB36639FEA163917ULL, 
            0xC8DFE26B532711ADULL, 0xCABC94CACC1BDDFFULL, 0x9F98B8BEE1AC892EULL, 0x2B452B0CD2D4476DULL
        }
    },
    {
        {
            0xB3082CD7CF197A0FULL, 0xE82D7C4D50BD535DULL, 0x24C7390C6A8FAF95ULL, 0xC77DCC7D296235C0ULL, 
            0x2D8EF9C8BBEAC955ULL, 0x8C677881F0B3E8CEULL, 0xA9508E8C5E592319ULL, 0xD31804BECE375143ULL, 
            0xEAFA40262E191DD6ULL, 0x2187ADB1D10ABE6DULL, 0x98A0C183EF33B7DBULL, 0x151B41B71BEE6A2BULL, 
            0xA413F037ECD0E861ULL, 0x2D224090F76C88FBULL, 0xA35BEFBC621A4C8CULL, 0xB5193292166D6510ULL, 
            0xB0CB22181E607F51ULL, 0xAC8A78821FA4A08DULL, 0x5FA151DFA095C76EULL, 0x37E85F9B5D4DC547ULL, 
            0x62FE90A86CE1D801ULL, 0xACFB4D0198C965D7ULL, 0xEED671E484209463ULL, 0x2BD968ABCF288E00ULL, 
            0xA1C83CC5B9863F80ULL, 0x000151A28D91AA7BULL, 0xCCC62C85FD6A62ECULL, 0xD9180793D1AF90BBULL, 
            0x08A79E9B8DAA321BULL, 0x06E7CFDC5064E466ULL, 0xFB4B350B63177C28ULL, 0x9FB93687B954D598ULL
        },
        {
            0x8EA1F1DE052BA196ULL, 0x8A76142BE3984D9BULL, 0x9EB3F9155739E5E7ULL, 0xC07800A0023B8921ULL, 
            0x654AAD46CC0C64A3ULL, 0xA5339B00793B0FECULL, 0x4AC212771021D39BULL, 0xE4A63722030833DAULL, 
            0x829B78BA50ABB2C6ULL, 0x25C87513A08F1DB3ULL, 0x7B117751FECEFD3BULL, 0x242F9D06EBA9E349ULL, 
            0xF4F0D2CC5CE1B2C6ULL, 0x7710642227CD2FF4ULL, 0x9AF725562DAE237DULL, 0x220410C0A8D839AEULL, 
            0xBF957E227FC2289FULL, 0x027201939C33BEC4ULL, 0x11C89F0E8F4351EFULL, 0x9F0AAA708DCDE199ULL, 
            0x1F693DA0824F9632ULL, 0x75C5D2556C04D768ULL, 0xE3D87429E7A7E6DBULL, 0xD1FEE4781026C4DCULL, 
            0x2CEE633904EF7ECFULL, 0x81E5EBD7FA18A55BULL, 0xE6B0D09C75758F8EULL, 0xC390266ED69C14A9ULL, 
            0x102A063D699E8D8EULL, 0x5A83811211E1E198ULL, 0x3F590F6AEFBDC6F4ULL, 0x4A670C7C21206F08ULL
        },
        {
            0x70F6137910BAD5DEULL, 0x8149BAA565708985ULL, 0x253DBD821AE44EB8ULL, 0x4804AB13D2AD7719ULL, 
            0x410FE4805FC1A53AULL, 0x12E872A3E0364AB1ULL, 0x58B2221A0171466FULL, 0xC6035ADC3EA81250ULL, 
            0x2F21EE6A3E1457FCULL, 0x90978241858BA770ULL, 0x54E1D8C2BC5FE0ACULL, 0xF434D25B45DA93F9ULL, 
            0x437743BECED6D278ULL, 0x55C9FBB4E12F85A1ULL, 0xC39E3A83407FD555ULL, 0xC50E555558214801ULL, 
            0x56EDE6994287AE6BULL, 0xB595DA818B65A5A6ULL, 0xC4EF533FBDB3586CULL, 0x2DB84ED2C7C0FE6EULL, 
            0x84CE35FB0C409186ULL, 0x249735E994FBDCACULL, 0x58BE51FE338FC1DEULL, 0x8317C3F294E5E289ULL, 
            0x49F196889CF7BCF3ULL, 0x81950866BA5C335FULL, 0x75E4CF4EE19730BAULL, 0x648970DD44A994D4ULL, 
            0xEC5B66E4BCB8A221ULL, 0x139FE28701271D29ULL, 0xF9489DE90FD8352AULL, 0x7344FE8D8F2183F6ULL
        },
        {
            0x11BF817E642E436EULL, 0x26D3B637B1678106ULL, 0xBE2C7E9D658848E8ULL, 0x70BA938F97F00492ULL, 
            0x160134FACC2B25A6ULL, 0x98E1778533940B18ULL, 0xC1D444B844088C02ULL, 0x1E73E74F2CF04AE0ULL, 
            0x5BA5C14B0F5CF894ULL, 0x510E6B3BD33F575BULL, 0xEFA6B9A9ADB76C36ULL, 0xDFAA74E66A1F1CB4ULL, 
            0x9161BC7DE0BE3BD4ULL, 0x6DFE99DC9B393B38ULL, 0xE1C4828B5AE88C20ULL, 0xB1D63086AFF9197EULL, 
            0xBABD8E6488416578ULL, 0xB16BCED85A4DDBFBULL, 0xEC5BE30257DE4666ULL, 0x884F00C249C5E211ULL, 
            0x5E0B9424BEFF477AULL, 0x10A82C72D5C3EA0FULL, 0xE2ABAF70C364E24DULL, 0xE62FE72CB21A4387ULL, 
            0x4FBEC50EA429A35FULL, 0x55DFF0C228EC7507ULL, 0x5E470766BB7E7E6AULL, 0x94AA855A786CB86DULL, 
            0x8A85E0DE2029FB17ULL, 0x602407020721943BULL, 0x2D52E850C7255AA8ULL, 0xB28E33AF05151176ULL
        },
        {
            0xF4FA9E4CC5CD7A9DULL, 0xF6D2BE41F9B7BD1DULL, 0x6D24198AD35A05EDULL, 0xBD727FCCF4966255ULL, 
            0xF8D7EC65BD2D5E1AULL, 0xEA154F636063C6CEULL, 0x7A7DDB19D1F338B3ULL, 0x9E2482C518B3D063ULL, 
            0x0DA8F3FBF70CE4DBULL, 0x21ACC6D426465746ULL, 0x800166535C288F68ULL, 0x7440BC8A4565B766ULL, 
            0x8538EA1A724DBB4AULL, 0xE0ECD5F3791AAB49ULL, 0xDEBF5E3E7E134A77ULL, 0x919EF6CC2B7010C0ULL, 
            0x4FD4ABDB64D2DA14ULL, 0xCCFE5F65D2902786ULL, 0xA38523B83434A923ULL, 0x1F91A8A44EF9EC03ULL, 
            0xDC50E6FB43EE9B68ULL, 0x7737ABE257071DF6ULL, 0xFB102267BCB0D928ULL, 0x319E6D35BE7CB191ULL, 
            0x6CD574A18A80136AULL, 0x4D59780FA9FE27F4ULL, 0xDB6C7C9E4563F35DULL, 0x456A6C85CFA5CC52ULL, 
            0x2E91B4D037554B6DULL, 0x5DF30A09D9F11DAAULL, 0xC66877D28DCAEEA0ULL, 0x9B4F31BFB48FDE2BULL
        },
        {
            0x35060FA01EDC5C7FULL, 0x3A1A6A6C77AE2E3EULL, 0x23B7990E8AB9EBA5ULL, 0x45DFDA67186C05E6ULL, 
            0xDABB72A384E5A253ULL, 0xD1780AFDDFAA089FULL, 0xA9CC0D128FEF11E1ULL, 0xDCD39530EC418C92ULL, 
            0xFECAFF84F3B846AFULL, 0xFB33732ED111B722ULL, 0x571550698231A0BCULL, 0xBDCA26B2AA112D36ULL, 
            0x335D96D960315215ULL, 0x805292A3C3329D85ULL, 0x310957AA288F74A6ULL, 0x7DFD78A453D8F9F3ULL, 
            0x262B2A82465AD3DFULL, 0x439B48137580D2E4ULL, 0x5F01DC26AC932BF4ULL, 0x9531C88AFF137A4AULL, 
            0x68D2F7F37FA2C406ULL, 0x16008D786C6DA300ULL, 0x6177CA43DECC926EULL, 0xA5A32E2AADB56987ULL, 
            0xFF100446A2360A3CULL, 0xF079C65FDCFACA5AULL, 0x0D028372E8EFCFD3ULL, 0x4221DC2E90524C55ULL, 
            0x9ACA3E18648A27F9ULL, 0x5B25863C0050B3A2ULL, 0x600154F6B12296E3ULL, 0x0609A5E998196DC9ULL
        }
    },
    {
        {
            0xB7FB00D2E0FA5FB3ULL, 0x2D308B316DBF7603ULL, 0xBC9675B1FB8A9191ULL, 0xD19EB5E8EFD508C4ULL, 
            0x10F87F1F82BE2901ULL, 0x94EECF061C345244ULL, 0x830CA6D248620D7FULL, 0x0024CC523A05543FULL, 
            0x5A527477D1486A31ULL, 0xF69895888FAE3877ULL, 0xF93C1CADBB3F5D22ULL, 0x6EA8A538D953AAB1ULL, 
            0x44F8C3F1AE660CE4ULL, 0x51AE6752322969E9ULL, 0x49E25CCB7DCEF2EFULL, 0xC9AE408E71EB2600ULL, 
            0x66654D85DAD19345ULL, 0xB3DBEAE3CD63746EULL, 0x5322D6C90E163ACEULL, 0x0178DD9511FDAF0FULL, 
            0xAF4B5A5C419DABFFULL, 0x34DDD9CD5C797AF1ULL, 0x32ED80B083FD849EULL, 0x622AA0953461F0B8ULL, 
            0x4BCAFD911DD2CCB1ULL, 0x46CD36BFB9F40A1AULL, 0x611332C973F2B11EULL, 0xF71C50AE6897B9D5ULL, 
            0xA02C473F11DA6243ULL, 0xBBD5F429BDA31EF0ULL, 0x0F29E5F4E69C9738ULL, 0x1C2413370403FF3AULL
        },
        {
            0xF79C83C8050CF5B5ULL, 0x8C4B6CAA9820A2D2ULL, 0x3D1FC9CDCEBB5286ULL, 0x49DB71720E3A6FC0ULL, 
            0x4F0C114446BCF026ULL, 0x48392A837DBB5A90ULL, 0xC2B478C35700E1C3ULL, 0xB0A4037F8CC93145ULL, 
            0x0E95E900B4CD368EULL, 0xA1C361BBC287351CULL, 0x6163E2EEC320D428ULL, 0xC1267A00E912105DULL, 
            0xCBDE47849F791A0EULL, 0xC59848961133529CULL, 0x325AFEC2A66C1A35ULL, 0xBC6DBC870DDC54E0ULL, 
            0x3D8B60C91D065671ULL, 0xCC9C27834AD42584ULL, 0x4F0C79E5837645AEULL, 0x8FA6B6FC2FA94F6AULL, 
            0x37BEDFB1FAAF3059ULL, 0x7EE5BA36DEC5B4F9ULL, 0x4908EE83A7A8E89BULL, 0x5CE6687CBE1E7EEAULL, 
            0xECD637D7F0881C3CULL, 0x3B356BE3509B6D89ULL, 0x5A8BB1A58FADF0ABULL, 0x14D8A81167D79FF0ULL, 
            0x45054C6D6E09590AULL, 0xBEE4018454D05951ULL, 0x6EF4B6FB46238471ULL, 0x8C741777A3CD7409ULL
        },
        {
            0xF865EA15D3BB8DB2ULL, 0x012BB331393BCDF2ULL, 0xE0003FEC11A260C0ULL, 0x9B7AE3F9C43D4C45ULL, 
            0xE6B6BD93A3FF8594ULL, 0x6A95ACFE3744318EULL, 0xA21D5A3883CEEEB7ULL, 0x357BF381094D3C25ULL, 
            0x3497E14652F92105ULL, 0x6C1D03F647CE9AA1ULL, 0xFC6B2223150D552BULL, 0x720BF6274B44B811ULL, 
            0xE63A99EECF464CA8ULL, 0x4281C4AC17D272B9ULL, 0xF70FDF16FC1BCE90ULL, 0xFE76B465DF6F2C57ULL, 
            0x5AAC524B51EC7555ULL, 0x428642D72BCC7A58ULL, 0xE7A3C173AB0A518DULL, 0xE944DEA8808BEC4DULL, 
            0x6728A6961A6C6CB8ULL, 0x5B9D3B031448417CULL, 0x0182E86B549B4CBBULL, 0x49CACB5B0F98C448ULL, 
            0x76DD3B36599DC6EAULL, 0x14990FA969CEDDE1ULL, 0x73D4A3B00D47ED81ULL, 0x898171B111E85BD6ULL, 
            0x0D9AD0537F89DB0EULL, 0x3DDB3E963AF31B60ULL, 0x9E89C5F92AB3C6C2ULL, 0x8AE51BDD5ED5CC00ULL
        },
        {
            0xD3D6D4155FB0B62FULL, 0x8F656D75D0D3ABDDULL, 0xE4641F706051BEF7ULL, 0xB94F505DA851FEE4ULL, 
            0x0EF124282B3DE71DULL, 0x7582C883E0441034ULL, 0xA0D94C4DC50CBA5AULL, 0xD3A77304653B2034ULL, 
            0xFD65EDA46B58D7C3ULL, 0xE2F02428DA615344ULL, 0xF79DD35BDB0B6E2DULL, 0x0C60AD59C44DE6E5ULL, 
            0x42A6EADCD4AB4BFBULL, 0xB1C0E51CCBD7DC1AULL, 0x98337B21EA99BB11ULL, 0x0A89BE81D0466F45ULL, 
            0xFAD95D1184A02DD1ULL, 0x7D7037EF95B3627AULL, 0xB3226DEDD633697DULL, 0x941BB10EBFD888B6ULL, 
            0x2011CE8428EB2C9BULL, 0x70963E362BD9E36CULL, 0x0ABE81561A3B3F7FULL, 0x525CD464B0A48CCEULL, 
            0xE06F86EC0126A699ULL, 0x3E780E93E007374FULL, 0x466EABED840A4782ULL, 0xC93E824462BF4FA9ULL, 
            0x40FA582CEE2B64F1ULL, 0xE223F8AD6324CF31ULL, 0xB52E819FE1DFECCEULL, 0x83FF5458D812B3DEULL
        },
        {
            0xF8AEF28C474D98F6ULL, 0x1CBDC403C2425430ULL, 0x27C955A8E7AA56D6ULL, 0xB02AF9CB0F4DFFB9ULL, 
            0x4D0978A4ECA11B80ULL, 0x2D60D2A30702714AULL, 0x5BA71EF2E22DD519ULL, 0xBA7311F87D57FF0EULL, 
            0x8E3C0F331AFFA98BULL, 0x3FCBB1928CAFCCB8ULL, 0x5F29F362CBD066FBULL, 0xA455EED3BC5D4090ULL, 
            0xD38B83CA46213B97ULL, 0x190AAF24ADF46A3FULL, 0xA4F1BD0FC7422D38ULL, 0x58CCFC1C0084806FULL, 
            0xC584DCA5AA233302ULL, 0x2A2878B821FB7D82ULL, 0x33C5FBB47D86C89AULL, 0xE263478F91D83B3CULL, 
            0xDD9AD3953C32C365ULL, 0xEB99A6556180CB8CULL, 0x1BA3308900D53302ULL, 0x266F82886F98F2D4ULL, 
            0xC9E37C4B565F943CULL, 0x4AECCB2C88866FBDULL, 0x9CFAADE04942AEAFULL, 0xDD559F020CC8BF0BULL, 
            0x52938ED446E14BE4ULL, 0xD95D983A202AE4C2ULL, 0x79F40C552B764156ULL, 0x118FF67CC09F6DF9ULL
        },
        {
            0xF82459B517FE895EULL, 0x1CE46BF390416497ULL, 0xCDAC68E42339888FULL, 0xC68FBCE59035FEBBULL, 
            0xC10D3379C399DF7BULL, 0xFDBB61098231BDCBULL, 0x2CC0F0BBEF6E89DBULL, 0x567A54DEE2826626ULL, 
            0x5B1DC8EBF6BC4E01ULL, 0xF6746D3D00A4F0ABULL, 0xE226F0EEE713B149ULL, 0x01A51C64F0CA70B9ULL, 
            0xC66402C67BB614B6ULL, 0x84DA4686905FB65AULL, 0xCFFB1161695DEB6FULL, 0x5E1DFFBF89AD4675ULL, 
            0x9E8E0261814934DFULL, 0x71FAA4C725F46C34ULL, 0x716131685C9CDEDAULL, 0xAF5B27871B26CF55ULL, 
            0xB701B806D0138448ULL, 0xC93A49B082DB26F1ULL, 0x0E0C03D9C9D1CFC9ULL, 0xE732FAFCD04D0607ULL, 
            0xD6A324200798F249ULL, 0x91C8261E29814125ULL, 0x4AB9904C81DE9D6EULL, 0xB4A4AC481BFE02FFULL, 
            0x157313313CA1C1BCULL, 0x1D0E6601578665A7ULL, 0x7EDA4FDED1BC8C7CULL, 0x4D8F9F5252FF8AFFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseBConstants = {
    0xDD3CDFD2D7C2A18CULL,
    0x4CF3023E59D05707ULL,
    0x90AA93EFD16E58D8ULL,
    0xDD3CDFD2D7C2A18CULL,
    0x4CF3023E59D05707ULL,
    0x90AA93EFD16E58D8ULL,
    0xF080AC0E4D5AA9F9ULL,
    0x1C2D5ECDF5DAA3CDULL,
    0x18,
    0x37,
    0x61,
    0x4F,
    0x69,
    0x9D,
    0xDF,
    0x06
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseCSalts = {
    {
        {
            0x8735EC7E7E401293ULL, 0x90F91F674ABC05F2ULL, 0x7631766BDC3169F5ULL, 0x782DE8F9892A0475ULL, 
            0x6EF1DD7645625221ULL, 0x5680A0236F09919CULL, 0x7D45198110A09A6FULL, 0x3D5E595DA2CF341AULL, 
            0xFC45E91392E9B373ULL, 0xA6FFC52C7D7C00D8ULL, 0x5D0C3B17C711DED3ULL, 0xAA00ECEE2F60FA48ULL, 
            0x5015360686A22ABAULL, 0xA911EF8349F01EFFULL, 0x69107E1D40395D63ULL, 0x5A82FB4752A47670ULL, 
            0x21BBB000AE7B1F90ULL, 0xFB93780A1D8D7D1AULL, 0x59B735861E7579C0ULL, 0xF3F5FE84EF5F6547ULL, 
            0xEB61B6B9D3470345ULL, 0x04C2EEB4B74EDE57ULL, 0xF2AF0998AB475691ULL, 0xC2167FB9F014B518ULL, 
            0x432CB4C209AE87F9ULL, 0xE26EE3FEB2D3362FULL, 0xFD5BD4A40CCE2FD9ULL, 0x044F2F3E384306DEULL, 
            0x9A14548CFF2B1AC7ULL, 0xF0EB7E1271F4A7A2ULL, 0x968EAC4C9ED47A66ULL, 0x81BC09A96FD565D3ULL
        },
        {
            0x8FD6D10C0C49F4F7ULL, 0xDD7D14FD0D89AA53ULL, 0xC00BB05B93DC7A25ULL, 0xCB8868AF944FEBE7ULL, 
            0xFA0654802EDA4116ULL, 0x36395A826869C43CULL, 0x0D46FEB48B3F5EABULL, 0x7F629EEE4FE46E7BULL, 
            0x3D659D7773D8E571ULL, 0x1C66D9B7169B35E2ULL, 0x70A3C43B8D5FA0D3ULL, 0x119F254948F8DCA9ULL, 
            0x918F567F39F047F5ULL, 0xEABAF157AE27AC02ULL, 0xF2646811D224EABEULL, 0xDA46353BF4A2791EULL, 
            0xFE7FFDF4830EEA5FULL, 0xC23CE6ED15645581ULL, 0x916B7350EAA249E4ULL, 0x6AF1958C2E2D488DULL, 
            0xF095B1D44CBDBD4CULL, 0x618BB12740CE3F68ULL, 0x69653F80D13A10DCULL, 0xDBACD977FD1AABE9ULL, 
            0x9036FFBD76A657FCULL, 0x84F24A0E548FA98FULL, 0xBE41B8E50475FC82ULL, 0x9CF517B53CB44237ULL, 
            0xB6891F1DEB5F9542ULL, 0xD94349812567E8A5ULL, 0xC2EA6ECAC1D125C4ULL, 0xC471D039570B9FEFULL
        },
        {
            0x145B8A08B59AF5E0ULL, 0xA3E9DB3886B18307ULL, 0x12B88C4172EA20BFULL, 0x73C061EAA1F78B4BULL, 
            0x7CD8F6C77D84A743ULL, 0x349FCA2F58C6A736ULL, 0xA6776B5CDFBD7BC4ULL, 0xC0618F347C7B91C9ULL, 
            0x27925405B38ADE52ULL, 0x07C477F48E95DE0AULL, 0x3F0C549114E63E9CULL, 0xC1D7F224BCF736BBULL, 
            0x2098F52A9E4E08DEULL, 0x528E56610EB7607FULL, 0x7E77EE32AE87D962ULL, 0x3E4C9D4A043E8957ULL, 
            0x5646BAD034A9D720ULL, 0xA3FA2876219AC129ULL, 0x02C5110D736C249AULL, 0xF3B0FFAEE7E2270AULL, 
            0x78604FF9B9681FE1ULL, 0xE0ACB30B7C4C4D78ULL, 0xB6574BA7F52B3E80ULL, 0xA5579D022B639263ULL, 
            0xA17FDCC8A8251F24ULL, 0xB9A2F3BDDFEC9B5FULL, 0x7E0D19DEDFAFE552ULL, 0x56AECA14F3245003ULL, 
            0x6D87FC2AEDBBA4E3ULL, 0xB022B467FE6AFCADULL, 0x8797A79403E202CBULL, 0x64C9192BF41341DBULL
        },
        {
            0x589631081340854CULL, 0xB913D66EAF05F4B5ULL, 0x07EE1D2A5850DDADULL, 0xC0C1ECC171B65E7FULL, 
            0xF9943D1B361C2914ULL, 0xC704D0CB96D27CEBULL, 0x1E7F098E96F26578ULL, 0xFE993B0F88C068A0ULL, 
            0x52EEFBF5E3A8FB85ULL, 0x305A582F8E78D74CULL, 0xFE81D99A7CB0F835ULL, 0x56A322C1386588D1ULL, 
            0x2F37F2FE8710843AULL, 0xE3E9F3BA3B803BA4ULL, 0xF3BCC5A43229CA58ULL, 0xDC690E158996BE38ULL, 
            0x4540C30438461DC7ULL, 0x274F24E57658CAAEULL, 0x2C2AC681EBF8F74CULL, 0x8E1207504A01F357ULL, 
            0x590DA89A8DCDC342ULL, 0x9E4160E22FB71741ULL, 0xCB6662FABD9B9C76ULL, 0xFBEF2CF0014A6F02ULL, 
            0xF087A4E02FA53199ULL, 0x7AC7798F19711094ULL, 0x0AA4B0B838FA1BA3ULL, 0x5F043D7DB7991256ULL, 
            0x5071F1097B49E35DULL, 0xB77C456FD235BFA3ULL, 0x5E57208603EDAE77ULL, 0xA1F9AEDF1F52F79CULL
        },
        {
            0x57B0467B3AEAB8A0ULL, 0xC105DAA0E29F2F7EULL, 0x925FCF85AF957836ULL, 0xE3D6F9E3492301C3ULL, 
            0x100383C2FA4151F1ULL, 0x55FD9A773D54813DULL, 0x6BACED6188C59244ULL, 0x364A40EED1BE49F1ULL, 
            0xBF512FA548F9D574ULL, 0x8532CF7F40E1806BULL, 0x4D35E2CB8C2DCF82ULL, 0x161F6D9CBF54DAB4ULL, 
            0x0BD3F17AEA679290ULL, 0x8D7E188E23FF2F9EULL, 0x9119F0E4F1F94A93ULL, 0x02C10F153CFC7599ULL, 
            0x2B10DD992A484C32ULL, 0x7CD67A4427D86BC6ULL, 0x3AAAC241855F0C09ULL, 0xF25D1BF8D27F40ECULL, 
            0x5D7042A4BA6BB324ULL, 0xF119BFD7B1D1437AULL, 0x2EB7549DD8F16CB2ULL, 0xE5C9D69DD948CFA4ULL, 
            0xA94A49308A1695BBULL, 0xC48E292FB3A6923AULL, 0x1443983691B6B645ULL, 0x226F4E9B63FF4152ULL, 
            0x80FF620C788F61AEULL, 0xD10D5795B3F04B66ULL, 0xBF756106760A32C7ULL, 0x2C7D68AA53332947ULL
        },
        {
            0x299298330419B3B4ULL, 0xA7220ACF03DC2243ULL, 0x317B900203CB24A2ULL, 0xF9353C3CD215DA88ULL, 
            0x27985AD360179091ULL, 0xA3EE49B888EBA201ULL, 0x3018A2BD8D31495DULL, 0x3E26ECF4B6010F4FULL, 
            0x7DA1FE8E9B78C3A8ULL, 0x6675663F7232F428ULL, 0xD417EF055255BF13ULL, 0xC8AF61D6E2B1EF1DULL, 
            0x3E04F43E6F06785BULL, 0x395C105FEEE8845FULL, 0x1D2F5678B14381BEULL, 0x15046FE62A03C3F2ULL, 
            0xCCBA4DA375C58E46ULL, 0x712F88997DE01280ULL, 0x9C910B1193EA03C7ULL, 0x87B11F3FC6CA6021ULL, 
            0x48C19AC32A823AD1ULL, 0xB6024B1819069862ULL, 0x2B9A4BC636E61C99ULL, 0x5A9F1C40392B8DBCULL, 
            0x3324E17D7964AB4AULL, 0xB41796738A7948EFULL, 0x22AB6FEEA600F58FULL, 0x901DF97FAB281507ULL, 
            0xA7CC63D0879FAA95ULL, 0x12A48EDC741AFD88ULL, 0x499CE7BCB5B1961BULL, 0xDB641E14E2C7BA7AULL
        }
    },
    {
        {
            0xD7F2948B9126BF52ULL, 0x7052A0C33EAE4ECBULL, 0x7B63338ECA52004CULL, 0xECE3255835154C73ULL, 
            0x5A950C19F9982A86ULL, 0x416EE427121F6B29ULL, 0xFAD4F3443B74D744ULL, 0xEBDBC7C7B2756FC7ULL, 
            0x1DC61ADF9C692816ULL, 0x1545F0CDED6BD1F7ULL, 0x3012AF2BDDA47941ULL, 0x4EAFC34AB23792B7ULL, 
            0xB3524E819DD927A3ULL, 0x030A691D4EDA7DD7ULL, 0x3AA984505A1FCBCEULL, 0x7641670AA8B8BAB5ULL, 
            0xDE6CA60BADA654E5ULL, 0xCC972FEF85EB5903ULL, 0x37EE47FE274E74CBULL, 0xE6F0DB31E11D2A77ULL, 
            0xD795DAC5EC158292ULL, 0x71462B0058D5C442ULL, 0xBF55A1445EB71DB0ULL, 0xD4A8217D1B1F1C8DULL, 
            0x292BE8704129DBFFULL, 0x406CD530995D858AULL, 0xBE9437896AAC21BAULL, 0xCD0E6B9A43E7071FULL, 
            0x8D183444C777707CULL, 0xD7F73347BE495B24ULL, 0xC2D0D3F20A012D0CULL, 0x99E261D8F4527639ULL
        },
        {
            0xF6DDF23BD6CF3648ULL, 0x40BFBF5C1A964590ULL, 0x468A32E51A6A2435ULL, 0xCFBA38E0A7BC0B3DULL, 
            0x420FB426E373AE31ULL, 0x672142B5F13FA837ULL, 0xA05A327F6DA3C79DULL, 0x196C9F9D866EB919ULL, 
            0x4BB9BCD7C41C650BULL, 0x9D14927FA3B52092ULL, 0x4213D14B342E695DULL, 0x0857AF795F8441CDULL, 
            0x14653E63B5C46033ULL, 0x95E0AFE22F012650ULL, 0x72F8EB8AF56710B9ULL, 0x2BD5648117728399ULL, 
            0x1B3EB4E7F48AAA97ULL, 0x1DECC64D72C0ED06ULL, 0xE90A8DCDDD3318C7ULL, 0x65A78D63D8428FD1ULL, 
            0x0A0F7EDA6E07E3E7ULL, 0xEC694F9C7D7CA22EULL, 0x833496CFBEF56514ULL, 0x187D3B0F8F5214ABULL, 
            0x76DB63E1B4BB70A0ULL, 0xD315A9D6F1FEE483ULL, 0x2A1C6F30E67D58B5ULL, 0x1F804AD7820ED591ULL, 
            0xA79622F2FF9D3479ULL, 0x132196C169E84E31ULL, 0xD5ACD572E27BC648ULL, 0x334F042D0B0A542FULL
        },
        {
            0xC7C5846ED4B2C087ULL, 0xDBD2AD0EB387E78FULL, 0x7D9715F52F05BF1CULL, 0x51A644F81523EF9AULL, 
            0x0633515306777E56ULL, 0x6D0C16A653347932ULL, 0x48225BB8D81E92EEULL, 0xB434DD3609CA9884ULL, 
            0xC76C51782DBD9E00ULL, 0xEEC990ADFB7F0BB9ULL, 0x0279F4BFA43F710BULL, 0x3BFFDCD35625D4BBULL, 
            0xB45A133837552E33ULL, 0x1BB5F87D1767E735ULL, 0xDC58D1AB89443DA5ULL, 0xE17082528FDA06F3ULL, 
            0x7C084CAA9CA55014ULL, 0xA855A8F683DE7BADULL, 0x7C89F18E7790188AULL, 0x184BC0C939A370FBULL, 
            0x1C88606633567652ULL, 0xD5E52A4CF60ECF01ULL, 0x7AF947F25B0A44CCULL, 0x619836EE28BEF6B7ULL, 
            0x93B17E4EAAD60230ULL, 0x9B64BB47D4B8789BULL, 0x81896B8BDD7B6DE0ULL, 0x25A4E2F0CA8CB4E3ULL, 
            0xEDFB9E6EA48062BBULL, 0x21FE712D6E103CBBULL, 0xE4172097E97D1912ULL, 0xD0905ED444AC7002ULL
        },
        {
            0xA37DD2C30C660140ULL, 0x1D0942D505CD58A6ULL, 0x3C2B4767E4BE0374ULL, 0x71BB155A6C1617F4ULL, 
            0x1C0C70EC9C2BEBDDULL, 0xC826F3E934B80E61ULL, 0x6746AF8A586A49B6ULL, 0x337248DBA304DF27ULL, 
            0x1650A463B95D1E1BULL, 0x40791DEF351E130DULL, 0x331385528C54F469ULL, 0x8FCB3AFDD54974ABULL, 
            0x0EBFEDCB6FB8E02BULL, 0xBEA6304EFE21AF53ULL, 0xCC5B4F200A92D9A1ULL, 0xB33A22CE17FD0C57ULL, 
            0xA816ADD34A9FD42DULL, 0x7ABF4E40E908F0FEULL, 0x06D12C30F7BEF131ULL, 0xE1382918C395995FULL, 
            0x4AC812FF10AFCCF6ULL, 0x4B092DECD8C0008EULL, 0x9D54523BBA9CE681ULL, 0x7AF278319EEB4314ULL, 
            0xE712822243155FB0ULL, 0x4189952C3BB42A45ULL, 0xA0C2463143818A27ULL, 0x105B3ECDC15E384DULL, 
            0x7CAF0C69847E93AEULL, 0xEF0E9953334E2730ULL, 0xDDF3EC965D76ED37ULL, 0x8984DDE0F3A040CFULL
        },
        {
            0x05C6F85540DF7A44ULL, 0xFF1E0B46074553F0ULL, 0xD438624E0C3DC7C3ULL, 0x963C99888EE5DC39ULL, 
            0x38C6BC2AB1A653EAULL, 0xD4E5B93397253E5DULL, 0xDFE00698C5486A3DULL, 0x00A70E1CD34D7290ULL, 
            0xCB47631F10CBA676ULL, 0xF8E5A297BC7A023DULL, 0x9609AC499BD17159ULL, 0x2AF206F22866C3DDULL, 
            0xACA7C9898BF6B6BEULL, 0x3BD067705701D33EULL, 0xFD6EEE3FC19DD1F6ULL, 0xE0D77324757FF340ULL, 
            0xFD214393DDE5A174ULL, 0xB8465B54ECBBF327ULL, 0xFBCB1726B945B440ULL, 0xD1997FFD3D2F58B9ULL, 
            0x552CEDA42C540246ULL, 0xEC234ECA8218CE96ULL, 0x7D779B8BBE62A5C6ULL, 0xD81D87B57F91C52FULL, 
            0xDD50F06F40D3FA20ULL, 0x1093649573B7634AULL, 0xCCC34E9674C22051ULL, 0x4E0C8873898AFFD7ULL, 
            0xD3E19C3604767C09ULL, 0xABF5183A859D1012ULL, 0x279FCF53912E3818ULL, 0x3977CC25BDD4FFC9ULL
        },
        {
            0x4E5230ECDCE3CA68ULL, 0xE1980236E3711949ULL, 0x7CA1AA78B4B6DEDAULL, 0x454EA990BF38906DULL, 
            0x7D83016C605FE530ULL, 0x3F0DA409F711FBFEULL, 0x0B560BBD5D92D2B6ULL, 0xE48447EF05933687ULL, 
            0x235EDA6D7DF8B3FCULL, 0x84EC2A4C3A23C229ULL, 0xECBD6BB8BEAECBCDULL, 0x9B30C8CCAFE33C1DULL, 
            0xB3897334C9ABEDF1ULL, 0x279BCB979A5EB4D9ULL, 0x564B13FF929DD5F8ULL, 0xA520410893F71D96ULL, 
            0x33B6EF9B6154352EULL, 0x06ED4CBB0D74FED5ULL, 0xB10A42A01484C034ULL, 0x3A615208A1ACBEF4ULL, 
            0xD0F58338375AAC86ULL, 0x8A8C1C13913A7D83ULL, 0x243DB6B9F6C2F894ULL, 0x4F4F7510E9DAE131ULL, 
            0xBBBC9D798DF4453CULL, 0x7C68E2CFE5446860ULL, 0xC856B35D8A8AAB63ULL, 0xC48EBADD89E14556ULL, 
            0xA25284FC3040D471ULL, 0xBB9CEA8034FAD5D8ULL, 0x47D890769EA14501ULL, 0xF4B06DFB41D7C842ULL
        }
    },
    {
        {
            0x263AD656CF925574ULL, 0x8F3F452EE9547408ULL, 0x73A94E072C9C476AULL, 0x3D179B6CF2D12AA1ULL, 
            0x90B3C9181EF05F7CULL, 0x657B979862EBC557ULL, 0xAAC382EA71987F94ULL, 0x5B864C9BE9C3752FULL, 
            0x42032C52EA9E9836ULL, 0xB5C4E471047A480AULL, 0xB698E9B5A1EE7DF9ULL, 0x3FEC8FEDE1574773ULL, 
            0x587C0D532931EBB4ULL, 0xA3090A98BA447A49ULL, 0x7C934A1A8458A83BULL, 0x14E6316D17C2CE96ULL, 
            0x9860892B51D069E9ULL, 0x8A0C85120BFAB146ULL, 0xC7FFA9A718A843B8ULL, 0x2785630A35EA5F7FULL, 
            0x5ADDC3C97A682365ULL, 0x13C73ED2C588816CULL, 0x3FE7CFD60B6B0487ULL, 0x7BC13AE0F5FEDB98ULL, 
            0x7294E27C285EA760ULL, 0x61E219805117DDDCULL, 0xF41D88C807194885ULL, 0xD90D7CA64DA2B19EULL, 
            0x7AAB80AB43337FD5ULL, 0x1DAAD2903E4DA955ULL, 0xE0664D4ABB3B3B5EULL, 0x0311E3BB8CA45429ULL
        },
        {
            0x7406904D9F2D5F8DULL, 0x1582E16447457DD3ULL, 0xE3AB66358112C171ULL, 0x9307CB16D1BB2997ULL, 
            0xAEB786DDD461E202ULL, 0x4FB5B4A185CC37DEULL, 0xCFB776FDFEA89D7BULL, 0xCC1D10E12AED6397ULL, 
            0xBEB53CCE8613EF66ULL, 0x163B9360DD5CA2C9ULL, 0x2EBDDAA784284998ULL, 0xABFB40A24F6527E4ULL, 
            0x0CEE00DDA9C325DDULL, 0xEEF2ADB15774EEAAULL, 0x9684C3A2B6843880ULL, 0xDD22A50F74796D62ULL, 
            0xB9B0595F02684E93ULL, 0xAE7DA6F445055CF3ULL, 0x2B9DA079A1C339E9ULL, 0x8E14B82490585AA5ULL, 
            0xEF9D20DD15246B40ULL, 0x90B6A19A2710DB26ULL, 0x9F1D240275810402ULL, 0xE51309FB2F972DC1ULL, 
            0x9736A7E52BB90547ULL, 0x74D7E1172D2585F0ULL, 0x4D32E58B6B0EA5ADULL, 0xEE280F7AFF18F30AULL, 
            0xDE1D5E3014CC6C3CULL, 0x5E211CB667661E5EULL, 0x7B9C3BAF2AE849CDULL, 0x6247FB55A0918CC5ULL
        },
        {
            0x3249300C0E1CEDDDULL, 0x6282822FB84A6A00ULL, 0x1F4B3D156533332FULL, 0xD5B1FFBF48F3CE9EULL, 
            0x5846F3DD6EA9DA05ULL, 0x40898DF6E72143E1ULL, 0xAAF980AD4ECC5603ULL, 0xC62BAFCD2F9ECF25ULL, 
            0x598614C5A22B2141ULL, 0x5340A581FFC2E4A7ULL, 0x8CC589835C0EFE9BULL, 0x5462270E24C19E96ULL, 
            0x386B637A0A3F6576ULL, 0xC74F1F9FD2694EEDULL, 0x6BA6E61ED2C460F1ULL, 0x275F2F6E7D94848EULL, 
            0x4B566E0A8F0880BEULL, 0x61A62403867B2CE7ULL, 0x6D7C6326664106C9ULL, 0x92E11168FD2C2AD3ULL, 
            0x99AF32680F2945ABULL, 0xE3525ACA563F6B01ULL, 0x2E2F9927A72C8FF8ULL, 0x820FFF5AA2D268C7ULL, 
            0x22A15E169CFB5145ULL, 0x0FD6ED6E4EBDB6BEULL, 0xE944DF135309AA24ULL, 0x1D53A7050E7FD2EBULL, 
            0x188E5C7C6E93E840ULL, 0x369FE0856E442080ULL, 0x217369CF4B40BF05ULL, 0xC270183E3504AAA6ULL
        },
        {
            0x7DEF6DE3C249240BULL, 0xABAB06A4415EA75AULL, 0x1AD35869141E3B11ULL, 0x2B69287A31B10FF7ULL, 
            0xE33BA784387BDC97ULL, 0x692FE1E55BFD5514ULL, 0x40C9320266826944ULL, 0xF4ED4032524E3925ULL, 
            0x9D78D4E1D58F7A93ULL, 0x1E2B0B19B9C95A10ULL, 0x5679CA8B60A65DD7ULL, 0xD5B16E2B4A919B1FULL, 
            0xF85D2E20DC0AD1ACULL, 0x7C81EEE10882EC83ULL, 0x3667658D5C3362D1ULL, 0x1406AA029E9B58FAULL, 
            0x698737AFBD594C7FULL, 0xBEB692AB98883A47ULL, 0x77124AFE3B3C0568ULL, 0x42379F4643EB133BULL, 
            0x73DCA0BB5C276B74ULL, 0x3EEF886B26EA2849ULL, 0x92E0882DDB2EDD7CULL, 0x439A2B5085E5A719ULL, 
            0x05DAFC3B0DF9377CULL, 0xF00D0614A164A47FULL, 0x14340F184883ED69ULL, 0x09A59D045C757F37ULL, 
            0x7420A20CDEA6CABEULL, 0xE0FEAC36D83D01C9ULL, 0x28C2B4DA9C1E5021ULL, 0x79E820337A418F39ULL
        },
        {
            0xF80BED1742687B1DULL, 0xF34175585CD607E9ULL, 0x791CD56B1936135FULL, 0x75A79A08DD96FD2AULL, 
            0xFC38CA273152589CULL, 0xC021818F5B981584ULL, 0xD943FC5A4AA431E7ULL, 0xAF09780270301103ULL, 
            0x12D9A0BF4D69F4EEULL, 0x64D2D1A89A77C130ULL, 0xB0F6B8E6D031D73BULL, 0xD9609FA838F6316CULL, 
            0x780F677F7A33CDF9ULL, 0xD894B648ACC459E5ULL, 0x0A30B947BA35D86EULL, 0xAEA2A26770B5BC76ULL, 
            0x1EFD50F761CE5566ULL, 0x0647607F04E4C7FEULL, 0xAC77485A24CDB9ACULL, 0x77D0574A0E15BF23ULL, 
            0xCE83E0D42A2BDB45ULL, 0x1545DE60F8C48BC1ULL, 0x3806B07ED5815266ULL, 0xF955EC5033B8D203ULL, 
            0xF15B85EA5CD430ECULL, 0x0CD52A637E28A093ULL, 0x171927509AC74DD0ULL, 0x59601299B6001CCFULL, 
            0x6A1E34C8E52E376EULL, 0xECEEF6531AF52341ULL, 0xB918D7C6B0F16D93ULL, 0xDA19198F3D0ED4A9ULL
        },
        {
            0xA8E28920929108EDULL, 0x974F2B18BB25F93EULL, 0x1C7EACBF37720830ULL, 0x2513AD7FCFE025F7ULL, 
            0x1C098666F01A11C1ULL, 0xFAA748A0440C810AULL, 0x00FE061CA4727D31ULL, 0x412BB91907160E0BULL, 
            0x7447C3FF156B09F9ULL, 0xBA72812381EB98DCULL, 0xD91E372BEA05C8B2ULL, 0x5E4A04DCEB0ECE2FULL, 
            0xB13C3AFB20C04ED9ULL, 0xE532AF2F28B37EA0ULL, 0xC0D18E12A7799108ULL, 0x335CFB033BCD7A69ULL, 
            0x5260EDA764FD3F2AULL, 0xEF75932BD146CE0EULL, 0x055DF53984FB1067ULL, 0x61932E9B9EE0E64CULL, 
            0xF2A2738655751A09ULL, 0x7999FA427EAFFAB7ULL, 0xC05CB61A67F047E9ULL, 0x8C171FAFFD492CA0ULL, 
            0x87B439B555C3A786ULL, 0x8ABFA3C9F3A5B070ULL, 0xA70041E1CF7C4DB6ULL, 0x2F4AEB152D56303BULL, 
            0x9293DEAE7974226CULL, 0x8E8CF18A7EB0EE30ULL, 0x1DF71DD2B7548271ULL, 0xFBCBC4FE10B1C6E0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseCConstants = {
    0x2EB08DA6F7C346A5ULL,
    0xFB62DCE3DD2DA393ULL,
    0x92612DF29BAB0C25ULL,
    0x2EB08DA6F7C346A5ULL,
    0xFB62DCE3DD2DA393ULL,
    0x92612DF29BAB0C25ULL,
    0xBCADF5FD5112D5ABULL,
    0xBEF532E8C90F7500ULL,
    0x0F,
    0x18,
    0xF5,
    0x29,
    0x72,
    0xE5,
    0xD8,
    0x03
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseDSalts = {
    {
        {
            0x174BADA2ED58AC8AULL, 0x9F52E5EACE975740ULL, 0xB7D2FD2D2EF44FD1ULL, 0x2A8E7E0375778518ULL, 
            0x5A38C29D54FE10AEULL, 0x3A0649241AE9CFE8ULL, 0xAAD1B1C8490FA2ABULL, 0x91B3B299BF1774F6ULL, 
            0xA53887D425A40213ULL, 0x4EDF6E441C4C661CULL, 0xC7DE09E6114BBB76ULL, 0x66F74E10D351F804ULL, 
            0x632DAE5C6F0123A5ULL, 0xB9513222EB73B88AULL, 0x89E7458FDB1FE078ULL, 0x3E9EF6D0080A06AAULL, 
            0xB6D5ACD7F98BDD9EULL, 0x0611889F55A5EB71ULL, 0x4F9B1C35493CABE4ULL, 0x618F676800275EE8ULL, 
            0x590C141A2192C8ABULL, 0x55A25C52EF098A1AULL, 0xBDBD2B910EA00B1DULL, 0x07321CFE22D83403ULL, 
            0xF21802FA85D962DDULL, 0xF2D7CA14A338FBDEULL, 0x78336E7BA470B5ADULL, 0x465FE7B2C6C2DF76ULL, 
            0x7DD0D5837DED6E36ULL, 0x9F61E89F6D0FE1F1ULL, 0xD27CAF2A02229659ULL, 0x11194B2320CDA611ULL
        },
        {
            0x2768FB503A7FB0F2ULL, 0xA04942AF93EF4641ULL, 0x86BD4EE47C2B6F19ULL, 0x608021CAC9ECAF81ULL, 
            0x5A345BE9675EF59EULL, 0xC1437FA189799C7DULL, 0x9FFDF371F3CFB670ULL, 0x046F516C12457434ULL, 
            0x33BB6CCA85F49319ULL, 0xAB39E09BD31E8A8BULL, 0x3EB9EACEFE324D50ULL, 0x974748B96D4CEE35ULL, 
            0xC76E6A4AB6D56630ULL, 0xEEA815845159FFE8ULL, 0x3A02963BD523652DULL, 0x04F76B485819B696ULL, 
            0x65CBD3E6AA20B23DULL, 0x43061E408C56D280ULL, 0xE73FDE1C52A45066ULL, 0x1993C53A52FC3912ULL, 
            0xDB78F893313F15F8ULL, 0x9A1E98FA4E49D710ULL, 0x8804908CCC454928ULL, 0x71992F32F503CA2CULL, 
            0x0DE1F59BFFBE5CABULL, 0x582BA22F5C725276ULL, 0x660898601B718825ULL, 0xAEAD2443F0432D6CULL, 
            0x256869DE2564347CULL, 0x67D88FE348FEF71FULL, 0x15567ADAA8C3DAD2ULL, 0xE9CCADA1CB45125BULL
        },
        {
            0xD4AD5AF79B074B26ULL, 0xD5D28919E71D9DECULL, 0x2BFF9633B6A053FFULL, 0xC3F88F3DEE7ED745ULL, 
            0x186E81358B0D415EULL, 0x995124340AADD540ULL, 0x7A9C304F96546673ULL, 0x188A659226A2F611ULL, 
            0x9866EF6BE8A61A59ULL, 0x207E80F3530A0CA3ULL, 0x84CD11B39142E4BEULL, 0x964830EE3720D84DULL, 
            0xF47759D8485469AFULL, 0x31CB4D44DE4F342FULL, 0x3A95929B6CA5DDE6ULL, 0x45D549013F813A7DULL, 
            0x05A1237D15A80B24ULL, 0x0FB559B0A886A264ULL, 0xED07343664024DA5ULL, 0x5D2CC4BA2C466E88ULL, 
            0x4D8435BF4530DE83ULL, 0x39FD78CF3D77CD11ULL, 0xE469F4EE4126FE8AULL, 0x8F5A0C8E83EA7804ULL, 
            0x63F42A3BAE1DB74CULL, 0x76D341C6D305CDAAULL, 0xB52C4AD88CC9FB75ULL, 0xD97D6F34E053C3F2ULL, 
            0xEA0862927CDF364BULL, 0xAE6A2118180DDD58ULL, 0x88CB63A513BDDF07ULL, 0xC8B84807B07B9A47ULL
        },
        {
            0xE60D8E04B673A52FULL, 0xB44B0DB56046AD08ULL, 0x7C68D7F57957E0A7ULL, 0xDFF26EF0EC8F1B11ULL, 
            0x853825BE9B71C8EFULL, 0x0CEAD442728A9B64ULL, 0xBB64C178E7E360EDULL, 0xDEF0EAF74E8E9F35ULL, 
            0x401A780EC5831F92ULL, 0xCEC2B001AA83180BULL, 0xDDCF7BEC0EF7F726ULL, 0x87DA8ED1DD822467ULL, 
            0xDE2241E04F1718F6ULL, 0xA7D14A6701C86D7DULL, 0x738B21E4FFBFF134ULL, 0x053B0CDFC8316838ULL, 
            0x371D41E7827DC4E3ULL, 0x8DFCFC290E0B6994ULL, 0xC4FE15B54FE8D881ULL, 0x8E5C4C5FDC097AFAULL, 
            0x44C0C22E8C8949F9ULL, 0xE9376BB73552FB9FULL, 0x06F16073EDEC7B21ULL, 0x551A8D4801997BB4ULL, 
            0x2FF8C4B2B783F83CULL, 0x1E64303C1398D5DCULL, 0xE3B7CDD611FB1B98ULL, 0x1EA589062C96EE62ULL, 
            0xC2CD0D2C96E977DCULL, 0xC9D674A2CA399266ULL, 0x66C897C7A29B9598ULL, 0x22BE1994FF8CF298ULL
        },
        {
            0x8A274458EA9AD859ULL, 0xA6566256E3433E46ULL, 0x128B42461748C63EULL, 0x0EC50AEE97808E91ULL, 
            0xC14C6C744ACA2919ULL, 0x9AE027B9B27DEC37ULL, 0x4632BAD2F92397FDULL, 0x9253F7976AC4DC9EULL, 
            0xB24630F5B4B8C120ULL, 0x568DC8C64A76C74BULL, 0xC0899EAEEEF32B66ULL, 0x099276412BE06BCDULL, 
            0x58F85BE6D4655D12ULL, 0x92F0CBADBD8D1E79ULL, 0x66FAFB6A1058BC7EULL, 0x93C144EA6BE48150ULL, 
            0x69E1339661B3DCFEULL, 0x23566D5F79E707E7ULL, 0x3B97774F8D9F1ABDULL, 0x093878EF3C38521FULL, 
            0x1D002DF611CF60C0ULL, 0x41729BB0C6FABF71ULL, 0x379CA319391F84F2ULL, 0xDC517B6393663FFEULL, 
            0x6CEBBC2E7F13D068ULL, 0x599D466909ECD676ULL, 0x493FFED08FDDE2AEULL, 0x68C2971A01F753BCULL, 
            0x256946D4E025BD55ULL, 0xE76130F8809FF72AULL, 0x81CFA8C6B1E206FAULL, 0x3B53CC6EFDA03952ULL
        },
        {
            0x8F6AB76692CA1B0AULL, 0x0410B9A467607C59ULL, 0x58769BD2DE1527C7ULL, 0xFADACD1E60490F86ULL, 
            0xA62ACD4FD30A6C9BULL, 0x40118DFFFC497E38ULL, 0xF887B89FB5D62490ULL, 0xC8C1792EF8FA6787ULL, 
            0x395F4FACBF57E178ULL, 0xDDC2796602ADF6B1ULL, 0xF3C9E61AB0911780ULL, 0x3B925F85E758276CULL, 
            0x5E36A224112E05ADULL, 0x96BDEEBE92104289ULL, 0x2A40079BFDA8BC1DULL, 0x16036FE4E3E5366BULL, 
            0x14AB8EC2FFE806CEULL, 0x3BD9C22317BAF92CULL, 0x953D33D0D91197EDULL, 0x5EEDA5CA03EB979EULL, 
            0xBBF72419E82F8E4FULL, 0x95C57506BF22B097ULL, 0x6D645B9F980D73E6ULL, 0xD5EC537178F39415ULL, 
            0x70DA52858D396766ULL, 0xF15514FEAA17E197ULL, 0x6184CDA56F02FDE9ULL, 0x0AECFFFEABC2CE76ULL, 
            0xFDEDC9B07AD7CC6DULL, 0x209E292B0C375357ULL, 0x461C0EAA02D9D020ULL, 0x7A0D8A3EEB1CDDA2ULL
        }
    },
    {
        {
            0xDBE4C5B308C6E6F6ULL, 0x25A8A35FF55F4710ULL, 0x19E304045C593360ULL, 0x642C2896A4D3C5FDULL, 
            0x18A561C946A99F25ULL, 0x04E243845AD9FA53ULL, 0xD288E645FC029218ULL, 0xFEDFE9D730478A6EULL, 
            0x09D64A957AD4CC73ULL, 0x26E779FEBCC64951ULL, 0x5777A3FF7405C536ULL, 0x77957EE84A96DDE5ULL, 
            0x1E7111669239E1C6ULL, 0x9724A89E68562022ULL, 0xF841C76D1FBDC2A4ULL, 0x0B9553D11BE8660BULL, 
            0x76C78C36F68ACF5CULL, 0x521AB4B2C9328B7AULL, 0x864160EA3DFA3915ULL, 0x7D15F9A3B5CC4526ULL, 
            0xD5E9709F7C7329CAULL, 0x4960B192D4DFA584ULL, 0xEE23E9090CD95B56ULL, 0xB764E78081931E65ULL, 
            0xDD987A02CD842524ULL, 0xB683694F002E5249ULL, 0x7AB9E9D46C87A4AAULL, 0xDD791899760F9998ULL, 
            0x3E045B96CFFBA462ULL, 0x9F0C4C0EDE69DB5CULL, 0x00A9AB502089F2D9ULL, 0x3F0070ABC8553DE1ULL
        },
        {
            0x686D186BE0D9AE0EULL, 0xE9D617429804734FULL, 0x146A31EA984BECDAULL, 0xCBBA50A2B8CE5CD2ULL, 
            0xDF4FE5DBDCEDE4C6ULL, 0x3C447C4CB0AFEDACULL, 0x0B41138164DB8E5AULL, 0x12088C72E00C8542ULL, 
            0xF7E00AE2FF9DECE1ULL, 0xF511010A288EFF84ULL, 0x6E63A9304BB76DEEULL, 0xA43FA587FC18E390ULL, 
            0x22873EC3DAC59CDDULL, 0xB570A449BE1A41C2ULL, 0x6BE5EC5BBECF77FDULL, 0x0E536F8393E44A8BULL, 
            0xE9B3097583F7A5D6ULL, 0x350DF1F53DC2937CULL, 0xACB0B50FC3A5D74CULL, 0xA6A9AF7B0B4879A1ULL, 
            0xEB3065EDAFB1F90DULL, 0x71302B9F1F762CBEULL, 0x07BC7C5F2C2D8792ULL, 0xBE7D277CD6BE89B9ULL, 
            0xCECD83820FA7B466ULL, 0x3043D8C4030A5605ULL, 0x101362F00DFDBD6AULL, 0x9F94A1E2874D0F29ULL, 
            0x894008586405AA59ULL, 0xE63E70A8165A8BE9ULL, 0xE810248D987F4589ULL, 0xD51826AAB07B4637ULL
        },
        {
            0xE5051B3CC29836F2ULL, 0x79AA9913F2A332D8ULL, 0xB56ED4F63FFC83AFULL, 0xBB14187F18710743ULL, 
            0x35F49CA2052602A8ULL, 0x2412DD40C744CED8ULL, 0x0A47F26F088824F9ULL, 0xC0B110DAD69DE162ULL, 
            0xE6575126419C6E72ULL, 0x10FC7E8C6734C672ULL, 0xAFC3D50B8D3572CCULL, 0x50E6B815ADD9677FULL, 
            0x27864FDD249B1AD0ULL, 0xD0AABACD525C0263ULL, 0x3BDE8A10D0EB3E3AULL, 0xA8841E134A5F6933ULL, 
            0x25C950D1F5CB9C91ULL, 0xF55128E557A6CBD9ULL, 0x3AED9F04BA173689ULL, 0x2A7FAE984C275AD5ULL, 
            0x2CC5A3B8570897A8ULL, 0x4B50FEB9E50DBA5CULL, 0x780959444AAF7599ULL, 0x7A0C9C3177A9962BULL, 
            0x6BC4B8AE240CC27AULL, 0x6BB3786325D38FD6ULL, 0x5773DC9DA5FC6216ULL, 0xBEBD807B44B73F95ULL, 
            0x1A00AD083203E259ULL, 0xAE86CF2995534FBEULL, 0x0C0541F9F7CAEA98ULL, 0x4438329721EAE66BULL
        },
        {
            0x39BF455672FCE567ULL, 0x022048D33AC6757BULL, 0xCB6358EDF40C650DULL, 0x551279DDEB77A360ULL, 
            0x92B5D13B520EDF0DULL, 0x74D0044FC3AC4908ULL, 0x7E3BF203FE21D4D5ULL, 0x38A447642710B440ULL, 
            0x347877491B72D8B7ULL, 0x1FC95A187ED147D3ULL, 0x95697001365E3297ULL, 0x4EAC6115013714B0ULL, 
            0x25028C8A72C39429ULL, 0xAE6172B095D2B92DULL, 0x0294FBAE03BA17E3ULL, 0xD27EB8F8D633FEEAULL, 
            0x3A194BA3E5105C96ULL, 0xA182400921A2757EULL, 0xF682EB0CD47D25DEULL, 0x64664813D3CF4115ULL, 
            0x253899EC28E15431ULL, 0xB2E9D480D8BDE12AULL, 0xA3E61EF730E7CE0AULL, 0x001AF8A4C8C37D88ULL, 
            0xEE302A8E0D392693ULL, 0x6A22172A57E46BE4ULL, 0x6DF0119B0A26C3CFULL, 0x30A9A1044CF4F88DULL, 
            0x0497051A374C8209ULL, 0x2803DC0DF71B5664ULL, 0x34C602A00E7A4BD9ULL, 0x5E4E8A51CA749B76ULL
        },
        {
            0xF90CFCE0E2C7305BULL, 0x35122503350E822DULL, 0x02C663FAF7197A1AULL, 0x092F93D592F9FF6EULL, 
            0x152F6B8C4B7B1878ULL, 0x864312CBC25672E8ULL, 0x1976FC3189178DD9ULL, 0xB4837531C9CE7F00ULL, 
            0xBF8BF0C8188A0D74ULL, 0xC09E84562E051F1BULL, 0x2365AC6C9F704ECAULL, 0xE112FFE982F70BAEULL, 
            0x6E8D5414A935FBB8ULL, 0x75DEACC06E0C3B28ULL, 0xEBCAFEA572371489ULL, 0x737FCEB8B627698FULL, 
            0x8783BDBE264F15A9ULL, 0xF641A1071F027E7AULL, 0x4C8EFDBB47AF189CULL, 0xBC4860A789B4EB66ULL, 
            0x82BD48348A93738DULL, 0xBC05A803B070AF42ULL, 0x9B53DBFC9B575A51ULL, 0x2785C209780F2310ULL, 
            0x0BABBD913212A76DULL, 0x036B76C88BDDB4F9ULL, 0x72BB232A98CC5C4CULL, 0x768635DA87BABABDULL, 
            0x2B8005B5460B19D2ULL, 0x0F28543B895A77FFULL, 0x6ACC241261032667ULL, 0x2A374220148BFA30ULL
        },
        {
            0x4ACE05825C66D85BULL, 0x96E307826489E4D1ULL, 0x9F5342164A6072A2ULL, 0xDC9A2E4445EBAED0ULL, 
            0x39DC1AB08B5F902CULL, 0xC1BAE8C2F4BC7C5FULL, 0x8D8081284865525EULL, 0x4D797C985DFE1E81ULL, 
            0x6F1B091F9948F6F8ULL, 0x373891DECB138CCBULL, 0x72BC02EF01C42730ULL, 0x4B502B7BF92047E9ULL, 
            0xA2BF13E6AAB1FA3EULL, 0xF3DD6C3ED74AE7B4ULL, 0x1AE693EC41EDB102ULL, 0x266F7F0C6EE1A9E4ULL, 
            0x6C01819D50E5496BULL, 0xE2EE46AD0801C585ULL, 0x5570ECB2CA94D7EEULL, 0x632A990E71A9E8C7ULL, 
            0x9CCA8A64409A5803ULL, 0x362B3A99AB57ED24ULL, 0x0C9FF95B2B852751ULL, 0xC5D4528693F5A07DULL, 
            0x1F8C9420C36B17EEULL, 0xFA787FBD9B5021CEULL, 0xF573C91AB55FE125ULL, 0xDDC8D3CB26567761ULL, 
            0xA0729A6902147BCEULL, 0x1A715FCB75A2B2A3ULL, 0xDBB88AA1B0D75C85ULL, 0x7657AFF8DA1F1383ULL
        }
    },
    {
        {
            0xEBD85BACEC3E52F7ULL, 0x2C079BCE23A1D869ULL, 0xEF18C1014491DB18ULL, 0x2A7754A644B5D49AULL, 
            0x2CF36452DED29F58ULL, 0xCFF6D36EC8FDC78DULL, 0x736701B3598A03A5ULL, 0xF790BD53C16915D0ULL, 
            0x55E839F3A36519D4ULL, 0x6A128E8253736C32ULL, 0x28914291519B9F39ULL, 0xF1E3660ECE2BDF3CULL, 
            0xB2DF5D0535F98BEDULL, 0x22095F47377614CFULL, 0xC5DC39A22E1CB182ULL, 0x3871255FB182C953ULL, 
            0xB6065993EA9F54A3ULL, 0xB9523436FD289CC1ULL, 0xBE8CD2D5972CBFD2ULL, 0x264AD25F8BFED5F7ULL, 
            0x8035595E1CD47F09ULL, 0x9A4061E5559D82CDULL, 0x8B0555F3A0D0E4F4ULL, 0x5660981922D5BF26ULL, 
            0x8EFB3B096A7C876BULL, 0x30C028FC0EB69E6FULL, 0xECE966CF62C010C0ULL, 0xDBC6385873208C19ULL, 
            0x8FC0861E0FA0D58BULL, 0xF73BEFB9E73F0586ULL, 0xF3064AF7D1DAE790ULL, 0x6F6CE4FAEF7D4903ULL
        },
        {
            0xF676F7878FBC63DDULL, 0xC35ABDB5D7480C9AULL, 0x429A4C87BE33812EULL, 0x636C92883798FBE2ULL, 
            0x3DBF28116A1B2FA5ULL, 0xEBB1C86CFCB699D6ULL, 0x7C36D31F141F0DCAULL, 0x401D0CD6938557A0ULL, 
            0xDF53B2D1EC333E45ULL, 0xEE6AB6BB96C983C6ULL, 0x88A6B15352E528E8ULL, 0x50843BFCC544D7CFULL, 
            0xCFE6E9F880AB7F09ULL, 0xE3D9B8475CB034DDULL, 0x35C2CDEB28B3BEA9ULL, 0xD2534FF7E045CB9BULL, 
            0xB639BD5FD96C2BBBULL, 0x2DA4B0CF435CB04EULL, 0xDA3082CF1EA20A1AULL, 0x8D7B7132554EBEE7ULL, 
            0xD1A94F14D2EF78A2ULL, 0x41D9B14495C0B1D5ULL, 0x2D3D21BD5D0B7F63ULL, 0xE3A7313E9C87103EULL, 
            0x5D8FF4A330B31206ULL, 0x9BCE902BAEFBFD79ULL, 0x257365797E843CD5ULL, 0xB7DF205476E98C9DULL, 
            0x5A493318360CF711ULL, 0x48CC02B2EEE75F05ULL, 0x26C004877D872DCBULL, 0xE123A58B0937A6C6ULL
        },
        {
            0x30CC35CBA97C83F8ULL, 0xD69FE4ED5712AC7DULL, 0xEB1D77CAF0891530ULL, 0x9BBFF3384BFE8A2CULL, 
            0xD8CFF12A2013A77EULL, 0xF39279CBC3776257ULL, 0x52638EEFD94AB17FULL, 0x661D206F3A9813E5ULL, 
            0xE1796BA783D6452EULL, 0x12C2A60A3EF46716ULL, 0xF6B6648C9716D91BULL, 0xD4E0BBCE4A73705AULL, 
            0x25B51FAA60A7B5AFULL, 0x54B21DAE87B44452ULL, 0xFC1C79FEB10437AEULL, 0x0FD2DA7C7DA08639ULL, 
            0xD22EB908B95187C6ULL, 0xA79DAE3AEEDCC3C1ULL, 0x9E208B1A94DDAF90ULL, 0x2F37212C303DE39DULL, 
            0xD08270B9BA36003FULL, 0x454CE94014856178ULL, 0x017CC8DCD6C93563ULL, 0x362E1F30E87ECA5EULL, 
            0x8D698B1087FF29F7ULL, 0xDB3CC65874E7C787ULL, 0xE684755F7254BED9ULL, 0x377EC746EED234ADULL, 
            0x15DA9C089DC6E852ULL, 0x42A45E77542C6C73ULL, 0x26ACB0BD05B51591ULL, 0x632B3E5B630D404FULL
        },
        {
            0xF192E32C29176FA9ULL, 0x7D8FFD8A5F1BF64CULL, 0x549040F48108F31DULL, 0xAF8CF09343F6B2CDULL, 
            0xB94FB767426E18FCULL, 0x74C7233F7B023192ULL, 0x358D2ECC70BAD09DULL, 0x055552C197D32B74ULL, 
            0xFF09C8C721AFA6D1ULL, 0x27707B9625EF5ADDULL, 0x15CDCA96DDF0AEDBULL, 0x11F5DEF1D0FFCD79ULL, 
            0x312C0517249A23C3ULL, 0xC7C907C11557F44EULL, 0xEEB6B18399999088ULL, 0xBF8520A5B59E698CULL, 
            0x96C6031C5E642FA0ULL, 0x1D2FBA8EB61A1D5CULL, 0xDB4475311C87D27FULL, 0x619795BB02D84CAFULL, 
            0xAA8FA54B81E5BDCAULL, 0x0E6221B9F4666AB0ULL, 0xF4CCB7DEEBB6B2C6ULL, 0x034C4E6955FE20AAULL, 
            0x3EF48EE257D65F92ULL, 0xE07EAEBD40F26991ULL, 0x3E8E21F36DC7E837ULL, 0x70F84D452111E5EBULL, 
            0x12DFAC9B3110B159ULL, 0xD0413CCC03299991ULL, 0xF1250164F81E3A3CULL, 0xEF6E9019937E972DULL
        },
        {
            0x8F2B0B1828A8E9F2ULL, 0x7F8C63A2A742C71EULL, 0x43104B744D8C5E09ULL, 0xB604178F012B819AULL, 
            0x1A8D9B4F8E9A457DULL, 0xF37208FEBAD54A07ULL, 0x8DA68934EAF9BFAFULL, 0x50B4E72F7449C031ULL, 
            0x66AAA67531243C0AULL, 0x93E98189B9B90308ULL, 0xC51A46ED4B1A0F2BULL, 0x07F1D3F82B813A05ULL, 
            0xE08530CD261248FEULL, 0x7CE351CCEA7DBF61ULL, 0x29053D508B294081ULL, 0x44BC8B607CFB98AEULL, 
            0x54AAB3CFC75C5937ULL, 0x35E765DBCBC726CDULL, 0xC2F025E532AEEC26ULL, 0xD383AC673D583F15ULL, 
            0x53D5CDF66836775CULL, 0x376A24F62EC38E1BULL, 0x2F4E71DD378EC0BFULL, 0x58E8CBEA6C7D64C6ULL, 
            0x73F2B71FBB302CB2ULL, 0xA60A3418757ECE24ULL, 0x688360B6ADDECAA2ULL, 0x3EF7752B5DF9713FULL, 
            0x74C339D342D72A1EULL, 0x358B1F0D7DB48E45ULL, 0x7950C7DA1B9AAB2AULL, 0x0F7D0E364D77EA80ULL
        },
        {
            0xC26AA1ACC0FC2705ULL, 0xACD8BB79C463DDDFULL, 0x9E8EC47ADF60C53EULL, 0x2D80166E4F7F1A57ULL, 
            0xEF3BCD48EB2B45ABULL, 0x5CB33207C1792F75ULL, 0xD45A045E4F6BD835ULL, 0xAF0766986C354F08ULL, 
            0x3F3D1B98C497EE54ULL, 0xBEB9AFE6985DDC75ULL, 0x7B0B9D3EF36F3CF0ULL, 0x89AA61471C964806ULL, 
            0x47B5B9D6CAF30ADFULL, 0x0E14CAA9F64AE356ULL, 0xA04CF53F1A61F3FBULL, 0x0ACBFB9F1708783BULL, 
            0xFF8AE96F882FD9F2ULL, 0xD863EDB8EFE41BFDULL, 0x4204827F0AAA468CULL, 0x42354DE2791FEAA0ULL, 
            0xDFB41B2E5C0271B9ULL, 0xF472456260FABF4FULL, 0x2FAAC1E3B8F61388ULL, 0xF29D78FB37166424ULL, 
            0x2D98C10B8560DDB4ULL, 0xD3E0454E4C1F6A1AULL, 0x96C6DE2D6F09C2F7ULL, 0x65F0CF630D49DC03ULL, 
            0xC9A93B710D7D8901ULL, 0x32A48CDCE7FB90D9ULL, 0xDB32A084C96B971FULL, 0x88FA64B38C1757CBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseDConstants = {
    0x39CD22EB70C6B1DFULL,
    0xFD04B62221EA5322ULL,
    0xBCEF20955489422BULL,
    0x39CD22EB70C6B1DFULL,
    0xFD04B62221EA5322ULL,
    0xBCEF20955489422BULL,
    0x8E68A8B35A15B2A5ULL,
    0x9DB7A439A145C3E3ULL,
    0x77,
    0xA7,
    0x56,
    0xAB,
    0xAA,
    0x36,
    0x65,
    0x1C
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseESalts = {
    {
        {
            0xDDFBBEE59F36FECDULL, 0xC8FEC80230FBF4C7ULL, 0x044FE86408E503C1ULL, 0xF8CF891E21DEDE90ULL, 
            0x0295AA512BC98F7FULL, 0x134071D1B8DDFE91ULL, 0x01D6F12F0C16A6BEULL, 0x7B65358E662DFC8BULL, 
            0xB9DA62C414C5B4CCULL, 0xFF2BEC41F1FBBC2DULL, 0x268BF96F7E6C98CDULL, 0xC99088EF19BD5199ULL, 
            0x39684F85EDB21B48ULL, 0xC1A5041BEABA6282ULL, 0x0256F505D8F3D39DULL, 0xEEF5E75EC9161123ULL, 
            0x463FF35E6B1F2722ULL, 0x77B18D6C6CEDAE84ULL, 0x6F16A70B87D6A0E1ULL, 0x49DA3EA63466D6B7ULL, 
            0xA7EE22B1913C9BC1ULL, 0xABDC91F8B08DAED6ULL, 0x664AB5CCACA38D49ULL, 0x14B003E3B89922EFULL, 
            0xF41C12CC282ED5ADULL, 0x4968FF15B88486A9ULL, 0x03731BA544D1E476ULL, 0x7BCC2F3299082A9BULL, 
            0xFDCA4B966A43A1B7ULL, 0x99FB1E309EDE2C1CULL, 0x206CF4F2AA05DB2DULL, 0xE2886D53E321B4B1ULL
        },
        {
            0x3653BDF6A9544D4FULL, 0xF3EC50784E267B00ULL, 0x2CA7080B64831E40ULL, 0x46A7558C67A54785ULL, 
            0xC5273ADF44894AAFULL, 0xE90153CDAC7E384CULL, 0xE04C4A86985920F2ULL, 0xF009E4232BE48DF6ULL, 
            0xB7C43B36639E468EULL, 0x57F6BB4F962CF947ULL, 0x26F717C97379F86AULL, 0xA01FA51AB3ED4F4CULL, 
            0x75DAF684D5EDEA16ULL, 0x0E72344FFBD1A575ULL, 0xCD8A22CB23D042B9ULL, 0xC779DD86A6D6DCEBULL, 
            0x0A1FBC3D4032BDB7ULL, 0xF9A07CF0CB532DC0ULL, 0x5754D05B6683584BULL, 0x1DD43FD434D1A82CULL, 
            0xDD396D10A8222143ULL, 0x9F13CBDAF558FC0BULL, 0x4325E5D041E5A73AULL, 0x6A651056955EF514ULL, 
            0xC6BE245BD823D5EAULL, 0xF5AFBD0CF211F7ABULL, 0xEAB9DC6009ADD72EULL, 0x68A43AEC99BCCCAAULL, 
            0x3F14B47B1C5796CCULL, 0x26E3E5832405A207ULL, 0xD90DABE4987AA571ULL, 0xBB526C4C5BDF82B5ULL
        },
        {
            0xB7A374F2C50D8656ULL, 0x511336AC1E10D2F1ULL, 0x8CB1CDF71A4142DEULL, 0xF8ECB9C7AC23C46EULL, 
            0x113B0E206B2139BDULL, 0x06D2515AB9ED848CULL, 0x4DB1AE580804C725ULL, 0x13EB6C00076E0A1DULL, 
            0x1B01313630DE0381ULL, 0xC1DAA5E2E3F32DE9ULL, 0xDA724005AD9BB9E0ULL, 0xB55D3D8F6434F35AULL, 
            0x4423478DA8C6CCC8ULL, 0xB7B8323F4AF3E61AULL, 0x84E0F2730F095801ULL, 0x4B4E3B9871BC6CA1ULL, 
            0xC25AAB7A868B4E33ULL, 0x7F57DC9629BE1EC4ULL, 0x832F8EE2962453EAULL, 0x36DB3C87B9807D47ULL, 
            0x33C877C98D6D3405ULL, 0x4A1EE839E9CFD5C1ULL, 0xC6D007F866920314ULL, 0x3F3B2D72A8934977ULL, 
            0x710CDFFD78A64856ULL, 0x24D5D8660E6A45F4ULL, 0x0AFE8FDBC2694150ULL, 0x66A187E38E3BA980ULL, 
            0x20137083C07D56E5ULL, 0xA0939EC4A9C34464ULL, 0x9A903205895DD7A8ULL, 0x8AA8A8448878DEFFULL
        },
        {
            0x13BEC2A8BD808FDDULL, 0x86763775BA189438ULL, 0xF5BAF11DFD9ECDE8ULL, 0x94041F1CAED619F1ULL, 
            0xF206779CEAB9B436ULL, 0xE326A024C61D9B01ULL, 0x67FDC6E2A640CDE7ULL, 0x2416A671057600E1ULL, 
            0xAF8DBA78315EC404ULL, 0x6E1E47F978DD7BA2ULL, 0xE344D1124D529173ULL, 0x963325D399772C16ULL, 
            0x947C8B236021C8D2ULL, 0xDBCFD5BDD8C05F6CULL, 0x6539FB8B1F439EFBULL, 0x6BBC36D996CD5D62ULL, 
            0x9711454DD44C3117ULL, 0x5408CE6767FB124BULL, 0x3D710020CAA9819EULL, 0x1D3493253B27AEB4ULL, 
            0x711B39E6DBA2A339ULL, 0x211B2E0948E382F5ULL, 0xE36D24EA4D73AF9AULL, 0x3E6C9ECF0EFB8CA3ULL, 
            0xC1E84D609F4A31B7ULL, 0x7564473C506DC31FULL, 0x05833C2A0DF75CB2ULL, 0x5B35BCE68ED8BC7EULL, 
            0x3678DC9D37629578ULL, 0xE7716AD452F2B9DDULL, 0xF4379887D5EB678CULL, 0xB68FA48CE2F65FBDULL
        },
        {
            0x9F5A54170410FD7FULL, 0x79980F3E5F7E86CEULL, 0xED072A13245627A1ULL, 0x0304DA1C61D14FEFULL, 
            0x0A609F64936A260CULL, 0x3CF6ADBD78C7B953ULL, 0x7BD031CF11269893ULL, 0x81EEF56F1F9C602AULL, 
            0xBA65631ABD7B1B89ULL, 0xC2D116ABF4CBC046ULL, 0x30A293AE53B5A171ULL, 0x9232C5B193BB4CC9ULL, 
            0x6ED9552C81B80E35ULL, 0x5C37D9E2CAD34B0CULL, 0x075591DBFD763E3FULL, 0xD7C164E4B0D3C849ULL, 
            0x2EE2B9A141924D5FULL, 0x1A9DF5D679844FBAULL, 0x6257A48BAA66B998ULL, 0xEBFC38C2626A6277ULL, 
            0x34C2DD68240E6CD3ULL, 0xAD32F19343B5F020ULL, 0x49091F3957434520ULL, 0x5D8F5419C677D93BULL, 
            0xC10440C216C72FE9ULL, 0x6DC6EEA286CC4698ULL, 0xCE9EC6BD398B2412ULL, 0x5E21123E90E10A51ULL, 
            0x1CB75816F36E5E4CULL, 0x8F2C3BACEE868727ULL, 0x7B349DD9ADB721C6ULL, 0x67F0381156C96776ULL
        },
        {
            0xDA4471A4BF42BF04ULL, 0x4728461C9D804501ULL, 0x6467E90FA9056E03ULL, 0x77107D230B739F5AULL, 
            0x35D62EF1E762C62EULL, 0xEC1989D8A47E8FB5ULL, 0x8F2C53F7D0CEE4E0ULL, 0xE1F64CD3E18A567BULL, 
            0xAB22C5FE18FCC1AEULL, 0x6F76A9483A8E16D9ULL, 0x120E0F0603E3A25AULL, 0xE8E58B6D8AF7FC31ULL, 
            0x315735C1FCB69CB4ULL, 0xD5AD59AF6C8058DCULL, 0x422629FA71C2F8E1ULL, 0x98C516B3C93C9654ULL, 
            0x24728C1E6674C741ULL, 0x4D2AA01527FC3CD9ULL, 0xB10A9257A21B0740ULL, 0xDFBF2E232C9A3418ULL, 
            0x88DECD85BB7EF3B7ULL, 0xA95676DD4B3E4292ULL, 0xD342AFDD4A62B9B7ULL, 0x833FEF0A83347507ULL, 
            0x0767A998D559E1B3ULL, 0x6FD3A022841F1103ULL, 0x9C825D63C5623392ULL, 0xDC51BDC42439C5FCULL, 
            0xC152EC384EFD86D8ULL, 0x60935B6124713B18ULL, 0xF067D1C244F61CE8ULL, 0xB5217772AF24E679ULL
        }
    },
    {
        {
            0x517A1E6AAE6B813EULL, 0x24EF56C6CE6BE5B7ULL, 0xBBD4C215B34A6F60ULL, 0xAAF1DB9F2573A87CULL, 
            0xC94CC8283AC6D3DCULL, 0x3CABFB9E9CAB1809ULL, 0xF1897E6B9CAA35DDULL, 0x676DC4B1D3D0C527ULL, 
            0x820A0119012EF810ULL, 0x8100E89550180AABULL, 0x1C4C5CA1AEDEB94BULL, 0x0181B8E1D7FA08B8ULL, 
            0xE2154E6CBC608989ULL, 0x3E820DC67EA1EEACULL, 0x8C765DCE48ED0032ULL, 0x5D85D66DC4AE3326ULL, 
            0x7C497EAAD343C8DCULL, 0x519F3C1D930E7AF3ULL, 0x5BAAD3F6866C0B1BULL, 0x96F789787407EDC8ULL, 
            0xC6F1A989CC146FCCULL, 0xAA976F464C407BA5ULL, 0x3C1B8D128D6D2635ULL, 0x79F9971331449881ULL, 
            0xB4B83EB36D2EA1A4ULL, 0xA85E99E27B324C64ULL, 0xC7AE3BEBE1EE8EE7ULL, 0x444F325ADE8C14B4ULL, 
            0x17DC8C872215BABEULL, 0xB7F0BE12C2CD72E1ULL, 0x8156DE5F7DFFC242ULL, 0xA993224314B16C34ULL
        },
        {
            0x1DAFF0A9279BF456ULL, 0xAA85B330BA256C53ULL, 0x32E4552ADD601D6FULL, 0x2705F0A818D36FC1ULL, 
            0xD6C1AAD3583ABF5AULL, 0x34B5B53CCDDFED97ULL, 0x0C10B1FEE1A7218AULL, 0xBD9D607B4634BD41ULL, 
            0x178DBBD182C193BFULL, 0x4405BAB2D532D685ULL, 0xB9F7C50B3064971BULL, 0xFC9080684AC7E8D4ULL, 
            0x69CA4E87960256E6ULL, 0x20B28CC4EBC40AC4ULL, 0x84634C1A9D65D5B5ULL, 0x601E35F167CE7086ULL, 
            0x3FE8D43146B70AC7ULL, 0x9AE71BB4B24434A6ULL, 0x3AF16170C8477A8BULL, 0x0ADF5C49B781D5CFULL, 
            0x6BD0B712B7157365ULL, 0x957676A2E490DC77ULL, 0x1A2DA1DAFE8C961BULL, 0x78DD8326975DB155ULL, 
            0x992E19BA584DA45CULL, 0xCD9A5FD4D0EA8A25ULL, 0xC13056C9FB9F8C7DULL, 0xB56F3C8149105EB4ULL, 
            0x8A53A1EF087D1700ULL, 0x99447FACAC29A1B1ULL, 0xA7CA217D30FE4C62ULL, 0x3CDEA88ADFD0E4F1ULL
        },
        {
            0x458C5F516B8ABDD6ULL, 0xF4424872A20E2838ULL, 0x88FBFA4C81E5718FULL, 0xEE710941C7286315ULL, 
            0xBAD1FEE5F90B29FEULL, 0x2E9AF7D770F6EAECULL, 0x5A976DFD420340D8ULL, 0x3EC28C46543081DEULL, 
            0x5A21843DE4356B6BULL, 0x8653E9CE4B9B4A6FULL, 0x889A885386D2A4B1ULL, 0xF39808C2C32CEC74ULL, 
            0xFEE01873808D9F6DULL, 0xF1D34237E71DE9F7ULL, 0x709D5FFCB61129F6ULL, 0xA00FB7AD3F9C797FULL, 
            0xE36AD40F71A00C61ULL, 0xD194D58D9FEB8857ULL, 0x3B64D392790E1F8CULL, 0x9EBA6B24062E8FADULL, 
            0x63ED0F0FAE2333F1ULL, 0x8B97708382917AC9ULL, 0xD884AB9D317B2DB0ULL, 0xFA7BC041076BCAA7ULL, 
            0x06883A477BA6A193ULL, 0x05FCDAFCC048416BULL, 0xE7E98169EC3D67D9ULL, 0x04F2B3079C168F75ULL, 
            0xE94091DB3E345084ULL, 0x8F5B10FEF37A65F0ULL, 0xC3732BEB9D7B7AA9ULL, 0x4EBC22F9D364868BULL
        },
        {
            0xC310B0CE0CD51E57ULL, 0x5CC33EBD1A9047A0ULL, 0x3136A776063CA123ULL, 0x8F3BBDD9B6EAFA59ULL, 
            0x5B2731A4FF71A09DULL, 0xF85D3FC50FD5AEF3ULL, 0xFAF557243E33D186ULL, 0xED74DF2B64246DF6ULL, 
            0x177A41CDF77D3D94ULL, 0x9652EEAF010BCD54ULL, 0xBA35780A91452FCEULL, 0x0B26F757967B0107ULL, 
            0xDE68737EB74E668FULL, 0xDE6AC7B744F763E8ULL, 0x35F059596517FA1AULL, 0x1F56DD5AA4A977C8ULL, 
            0xC281C43CDC154049ULL, 0xDE4328125B0B71C4ULL, 0x0DA54DD3CEBF3A61ULL, 0x6497254EF8E8455EULL, 
            0x94544CA62556344DULL, 0x2C33CB750C04A926ULL, 0x19D7300590C41282ULL, 0x9A698F804528C347ULL, 
            0xFB48BAF65903B1EFULL, 0x9AD6EF06678C2907ULL, 0xCA287CA210D74A9AULL, 0xF5DD7ECA69FF788CULL, 
            0x4D960C78212BED91ULL, 0x2C47EF2EAAF87906ULL, 0x958082FD4365FD87ULL, 0x3713404C972E0404ULL
        },
        {
            0x0A9E5C0A11103263ULL, 0x0EAE4CCE6C4C2385ULL, 0x94C9FA3864F76EF5ULL, 0xAB68026F3463A358ULL, 
            0x556B861160986DD8ULL, 0x8F662E3A87AA1211ULL, 0xAC2FA74D987D85BBULL, 0x0AB911ADBEDD1B39ULL, 
            0xBB5E06BD84A226C5ULL, 0x2D0F81C0960658D0ULL, 0x0881D5A3D4A50874ULL, 0xA4B618CC44B6CF34ULL, 
            0xFAD84377C9D3910DULL, 0xCC8ED69F1C71F596ULL, 0x2FED2FDD77EA6407ULL, 0x7BC290A2EA242A6CULL, 
            0xA344D4217B97589BULL, 0xFF9AE5C7D5429AABULL, 0xF9746BC50CB393FBULL, 0x022BA50DCC48F472ULL, 
            0x937026295874B2A5ULL, 0x14C2126074EDAD2EULL, 0x12F9F4630F3F1F9FULL, 0xDAEDFD8F015DB867ULL, 
            0xD3D7BDD51FE30953ULL, 0x1AF7646775607BF6ULL, 0x72CEE63E7C85E3BCULL, 0x04859BCEA684378EULL, 
            0xC88354201D879B64ULL, 0x2FB019B3D2F8D938ULL, 0xD8E91FB3A8BAA61EULL, 0xE42B90638F12ED00ULL
        },
        {
            0xFB5FF68B95331D01ULL, 0x51036C7E3F9ABA1EULL, 0x895C4C550194B9CBULL, 0xB0456956D66E0727ULL, 
            0x90B7EEACF6359F44ULL, 0x17A4CD4321BAA40BULL, 0xC44239AEE7636295ULL, 0xC2400C10C73CF593ULL, 
            0xADEEDC6A027D5AD9ULL, 0xD78A2ABF84642B7DULL, 0x526A22BE45A7A67FULL, 0xDFC91AD0AC0986F4ULL, 
            0x30506BBCA58AC753ULL, 0xC684DE5DA1EF04A9ULL, 0xEB8E7D748E631EDBULL, 0x606B9242CE39EF90ULL, 
            0xA2687987F7471371ULL, 0x9E49C12DC5927BECULL, 0x87324E3BBA15D2B9ULL, 0x4047905C8048D5DBULL, 
            0xAB2A0A3BDB189EF5ULL, 0x4F85B546869401E5ULL, 0xDE18A2EDD4091A08ULL, 0xDEC62AA94A128E15ULL, 
            0x1ABA7890C5993DBCULL, 0x41D858974C60ABB8ULL, 0x298CBBAEFC3E8668ULL, 0x65F2D0C7A4E6F66DULL, 
            0xC4449F8B8F201652ULL, 0xE0A0014A4CC6259FULL, 0xD27607FAC1A8A592ULL, 0x01628A471A57C41AULL
        }
    },
    {
        {
            0x399ECE32EA81A41CULL, 0x31EF21DDC1E11A02ULL, 0xC332940C985108C4ULL, 0xC92189644FE06CA9ULL, 
            0xA500756163380A2DULL, 0x085309C5325A8C1DULL, 0x9F2E4D81FA93BB4BULL, 0x11BE6D1F95044FC1ULL, 
            0x35CD34C1A0598250ULL, 0x77FA3107625EF68AULL, 0xD8B171EF583E0665ULL, 0xF135866BCC143B1DULL, 
            0x1B026D7EFE5567F7ULL, 0x4BC5354CDC5E2FD8ULL, 0x38E1F13062384979ULL, 0x8AC60117942889C3ULL, 
            0xC03809C3D9CF2FF7ULL, 0x79E5BCF68D62F8B7ULL, 0x052FE99EEC7EE63DULL, 0x15A3925FCE3E5FFEULL, 
            0x4C1523CF5F9AA306ULL, 0x791217E2CE707347ULL, 0x81CF1924D69EEBACULL, 0x4ADC20E8D53DFF21ULL, 
            0xE53BBF976C0C7970ULL, 0x480862852FFF9125ULL, 0x51FF6454DB181D2BULL, 0xBDD13B5A355460DBULL, 
            0xD48707A4BB571764ULL, 0xC565230D15C2DFAAULL, 0x75D61CBA15C73B3FULL, 0x0A3D6C661840AAE5ULL
        },
        {
            0xA336313C21190392ULL, 0xDB33F58070B33B3DULL, 0xD96B22E941E59311ULL, 0x0E896111C316EDE1ULL, 
            0xD55B9791F3799244ULL, 0xA480DFA9B751C1ACULL, 0x3C48DDADA9CFC7ECULL, 0x4DAE08DF2C4EA491ULL, 
            0xE71CBD64C47A75A7ULL, 0x990C1C3419AE33DFULL, 0x203C36DA163D2FE8ULL, 0x6D39ACA2EB415BA2ULL, 
            0x6187A3A9D7486F4AULL, 0x33A9F70B527135C1ULL, 0xA5939DA196F060A1ULL, 0xC3C0BEE8E3252D78ULL, 
            0x64EAA1BC6A8DFBC9ULL, 0x460C0C777EB1BE17ULL, 0x121FA21470F80D5FULL, 0x8C9E03057ED2B649ULL, 
            0xB2BF727EF45ED70CULL, 0x6C546D41D7D26404ULL, 0xE1DDC6CC61226914ULL, 0x8C092071C5791415ULL, 
            0xAEAFBF518105770CULL, 0x5D0945EF6CC73A1BULL, 0x271E4AA150149163ULL, 0x73EB7BBA07592463ULL, 
            0x84D6BC513753E766ULL, 0x0D9A3D70A76672C4ULL, 0x3505C0CB0A7368ADULL, 0x4CE4090F305484BAULL
        },
        {
            0x94C46FFF0AC706B9ULL, 0x4B7933FABF3B6408ULL, 0x88B84013D4AF49F3ULL, 0x100EF2949948CEF1ULL, 
            0x73EF0DEDE8D8BA72ULL, 0xBE2C079E16F3BC01ULL, 0x25B78E6AA17B689CULL, 0xFE9D6C1207189834ULL, 
            0x692025BA978D35DBULL, 0x4431E1B6A2599B17ULL, 0xEF02F19EF77963A6ULL, 0xB11F28B8E28AEB01ULL, 
            0xCFD2A21F8AE3F67BULL, 0xF242171E0C8DFFFEULL, 0xA00372D1D1022F32ULL, 0x59AD1B1F306AA41AULL, 
            0xAF6BB61E9CB1A7DDULL, 0x5324919485AF6E26ULL, 0x2A35CBDB4222F07EULL, 0x297FE847DC7C6C36ULL, 
            0x1B2341DEBCEFC4B4ULL, 0x1236191D41619104ULL, 0x05B7B510A94DF69FULL, 0x067FFFE9FDFC3F6AULL, 
            0x67FA332AE14AE166ULL, 0x950A12158AC031ADULL, 0xB64D08EE21130B28ULL, 0x45D0668E92BD29CDULL, 
            0x2408119CBE618307ULL, 0xEF801879737E5B97ULL, 0xC1311D5B835EC99FULL, 0xA59DE92F16090745ULL
        },
        {
            0xB6AFD8A6B8BE48FBULL, 0xA5313472CD51B585ULL, 0x705F9A4950061E47ULL, 0x6C5F283982319B27ULL, 
            0x995D6FF1B9E10319ULL, 0xF19877D21502AACDULL, 0x05DA1FF50372B4FEULL, 0xC2470FFC2B4A4FE8ULL, 
            0x1FD689774502A555ULL, 0x8959CAC0626D3DB9ULL, 0x44953FA8588C73EBULL, 0x4BC922CA40E397F0ULL, 
            0xAE402C5837255D8FULL, 0x1C6F6643BEAE6327ULL, 0xB1F54B2B62D68D4CULL, 0xDC78B5046BBD6F20ULL, 
            0xCB057FED2198A351ULL, 0x759EF0485C0BC482ULL, 0xC2B1AFD0CD9E94DEULL, 0x18B5865320D1486BULL, 
            0x6C4790CDA1B3664CULL, 0xA9D47578D853D1E4ULL, 0xE4E5973BB5F01EE5ULL, 0x494F872F63FB6E4EULL, 
            0x6263A4EF4440B716ULL, 0x369470FECC55CB2AULL, 0xB79B87CE671A021DULL, 0x129C66D8AD887A7FULL, 
            0xB1D7D78097D9BCC7ULL, 0x607F081954EF2ADAULL, 0xDBEF02F79AE8F28AULL, 0x2AFF57BDF056B207ULL
        },
        {
            0x09E450C9A80AF37FULL, 0x1F20A867EFDA0F07ULL, 0x37AA6015CCEF679DULL, 0x6D1CD7A5D77CB7ABULL, 
            0x69A31EE13BABBB23ULL, 0x15B02B38D7255F18ULL, 0xF4DD0085CEF654DAULL, 0x1367DE5AF430381FULL, 
            0xC3BB870A6EAA88B4ULL, 0xB1D99E955A7FAD28ULL, 0xC8C049CAB5218EC6ULL, 0x35AC1A319ECF3671ULL, 
            0x72ED3CE664239CAFULL, 0xEAD6BFC686476DC2ULL, 0xE97B8D453F23A13EULL, 0xEB8195CAE61FB708ULL, 
            0x374429D610F0F717ULL, 0x81AC9BEEE6334E25ULL, 0xE4A9FCFDA0A3F305ULL, 0xB345FE994472E013ULL, 
            0x0F6A7CB225E1E4F1ULL, 0xE52921FA79245604ULL, 0x4B09F6276512F41BULL, 0x8869F092F64D5B73ULL, 
            0x58E02ACC5FB005CFULL, 0x079AA9653BC5E7B8ULL, 0x715F8AB0AFD7CDDEULL, 0xFA731A1D9ADA755CULL, 
            0xF91595FFC7623AB0ULL, 0xE0D375E6A0AB748BULL, 0xA001FF5EACB4085EULL, 0x276846B080D7E70EULL
        },
        {
            0x95F826EC6E23EEDEULL, 0x0C0B9043F3ED2BF1ULL, 0x973CC0B9E92F89C0ULL, 0x7FF82A05E0552ED7ULL, 
            0xE73819FFF4EF7934ULL, 0x22EB3BA427E03A65ULL, 0xE9A1A889E22592A2ULL, 0x53A9155D0BE9C7A3ULL, 
            0x20DD8959B573CA96ULL, 0x7B953330A733103EULL, 0x5298DB3A4A7F630DULL, 0xB66A9C0FCC1187C4ULL, 
            0x93689F451FEE2A52ULL, 0x066996F7FF4A44AEULL, 0x78318D74D80CE014ULL, 0x6B9C706A3B5A15F1ULL, 
            0xF08338B4E774450CULL, 0xFF5AEE66D04A4680ULL, 0x5888B206A7070C68ULL, 0x3A8EAA274200C220ULL, 
            0x004F1890E654AA24ULL, 0xFD3F5FC35725035CULL, 0xBE9882C6AB419AD9ULL, 0xBF5D768D47424392ULL, 
            0x585ADA15F7EE31CDULL, 0xA74FE2F25709EA57ULL, 0xC972E5FEB4ABB268ULL, 0x90FB96BBC8B37528ULL, 
            0x70AB2D6B0A1838D9ULL, 0x2F479CD5A105B40DULL, 0x48F2F138CD3E09A9ULL, 0x302E8CF40A2A836FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseEConstants = {
    0x7903E484E13A527EULL,
    0x31251C8464613AE7ULL,
    0xB7E36187D4F92579ULL,
    0x7903E484E13A527EULL,
    0x31251C8464613AE7ULL,
    0xB7E36187D4F92579ULL,
    0xA6FE3338730E124EULL,
    0x591B0B2513E2444FULL,
    0x2B,
    0x03,
    0xD5,
    0x9F,
    0x7C,
    0xDA,
    0x11,
    0x1B
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseFSalts = {
    {
        {
            0x2ADB54091D778868ULL, 0xA72A5FD9B31D8E39ULL, 0x973FE056FF05D9A3ULL, 0x6D29F993A6E130AEULL, 
            0x939B767B836DD116ULL, 0x896D50A7DEFC9DEEULL, 0x0CC2581844A3FE46ULL, 0x55B9175205A954F0ULL, 
            0xEE085CD81113234FULL, 0xFB0ABF05947B690AULL, 0x7E352A0AA7C8E1B2ULL, 0x8A9999A35A525850ULL, 
            0x4C565D9362C6E1B5ULL, 0x0D451409F6AF0EF3ULL, 0xC5C8D3C8857DD3CDULL, 0xB2CB996BE3C76BCCULL, 
            0x771B783A3D28641EULL, 0xAEB9719F1F27C8F8ULL, 0x854F352D39429D1EULL, 0xD545CBF2C927880EULL, 
            0x80330421ADCE3391ULL, 0xAD007CA17292E5DAULL, 0x54E1073581FA9444ULL, 0xE2D1823A1EC037D0ULL, 
            0x4F06638A4F5F0BB1ULL, 0x977459064C6F32AFULL, 0x8DC7DD602018F188ULL, 0x40D967CEBD5DA8E6ULL, 
            0x387410481D20891AULL, 0xDC4AAA2ADC9F7CF7ULL, 0xB07F6CDD1CA866FCULL, 0xBE9862AF8F2A55E1ULL
        },
        {
            0xDC54BF584E992361ULL, 0xB76E9FC1B16677E2ULL, 0x89E2EDBEBEC4D6E6ULL, 0xA82AAB50930558ADULL, 
            0xA5B7A26DC0CC5769ULL, 0xC15C1EC569E13E09ULL, 0xDBBFF75C557A0AEDULL, 0x4E746FE2AA13B69CULL, 
            0x393D696FA180C609ULL, 0x0E9445E738B20655ULL, 0xE9F27938417A3EE8ULL, 0xE4CF53A5DE7E31CDULL, 
            0x280267988E926461ULL, 0x7A71BC5F4B70434DULL, 0x553A7B5D6ADBC07DULL, 0xF4DA02D01A926D3AULL, 
            0x56AAD2DDC5E13770ULL, 0xB5C9A519996E88C2ULL, 0xED0DAE83DFF22429ULL, 0xD761227171BCBF6BULL, 
            0xC7FE99E63D81B891ULL, 0x606677074D7BE084ULL, 0x9C801A08DDD36C7BULL, 0xA2AC374C50545BA2ULL, 
            0x7C267DE7D8EDBC5AULL, 0x9005B89E982E8ABCULL, 0xE68ABAFB95607E35ULL, 0x455BA34DC7E6D4FDULL, 
            0x39B76D139F64E58DULL, 0x2CCF40BB38B8634DULL, 0x7669C9F4E5FBA358ULL, 0x03EAB348050B3D4AULL
        },
        {
            0x9F4144AD72EBF101ULL, 0x1B70E0CCC8A3903AULL, 0x80EF8B2C203CEA84ULL, 0xC987DB8158566318ULL, 
            0xC325D4274D649420ULL, 0x6DEFB5A743FDF472ULL, 0xC9F3BA5A7F549071ULL, 0x93DC78E5E67D4B26ULL, 
            0xE15B90BD68C39389ULL, 0xB170DD2D61CB86DEULL, 0x79153A5B1456E365ULL, 0xD4CED7CF8A22FE95ULL, 
            0x3015C5C32D7E1B44ULL, 0x3236A013F4F1DCA6ULL, 0x92063B06E354F6E9ULL, 0xF94EFB38FF0973D2ULL, 
            0xE7FBCAC1713DF288ULL, 0x710865D5E95C3585ULL, 0xC0EA400AC529BAAAULL, 0xAE6169D52AEA69ACULL, 
            0x47C2FBA3276CC8B2ULL, 0xFB8B291D1965DC69ULL, 0xDF2BA5B03AA7CA5CULL, 0xA41B35C437384793ULL, 
            0x80569564175F8E38ULL, 0x503AA315326BC21AULL, 0x7A457D72ED664DC6ULL, 0xBCD9783DE59FEE94ULL, 
            0x497822811383FF31ULL, 0x36D854BA2B410A64ULL, 0x6A50CF28E116A20AULL, 0x0C3A8683BFD208E8ULL
        },
        {
            0xCFC0C34717DD8685ULL, 0x0DCFB687E91CDCC1ULL, 0x21E47521B5498BEFULL, 0xC033B8A613260DD1ULL, 
            0x2378039C0FB9C014ULL, 0x30A939EB674F3E6CULL, 0xBD12542819DC5815ULL, 0x2BB0AF356FE7D6E6ULL, 
            0x34ECCEE4CB06B19FULL, 0xA72AC20804677ABCULL, 0x114246CB762A84A2ULL, 0x59C823066D680110ULL, 
            0xC1719A3B7DC4F27CULL, 0xC2BC4293A77DCF74ULL, 0x3053C7C7FFAAD40EULL, 0xF02E256A1305A48BULL, 
            0xA331D20685A05718ULL, 0x183E6B5E41697EABULL, 0xC45BCB34E377E26FULL, 0xAF1692A92964FEF8ULL, 
            0xB0D9CCA69EE28A47ULL, 0xBA101B8EDA80CA37ULL, 0x99ABF8A4C8F12506ULL, 0xBF7C60D089218043ULL, 
            0xFDE94A2C4BFBBA2FULL, 0x3217414B93A87EA3ULL, 0x26CEC4CEC355680CULL, 0x30E1E3E506C81FFFULL, 
            0xBB06F7935B392FB7ULL, 0x4C146128B19906FFULL, 0x855CB0DBAAEE6D6AULL, 0xA37FDEEAC9A6C641ULL
        },
        {
            0x13DDCC9041426473ULL, 0x9B7B5181B42628F7ULL, 0xC22F6C71243C6F8EULL, 0xCDD5146B574BF48FULL, 
            0x407541C0B41177CAULL, 0xCE78C5085FBF575CULL, 0x725282C8C244D7B6ULL, 0x93686DF975AD3AEBULL, 
            0x303B9959D391E92AULL, 0xBC063F06620B103FULL, 0xB52ADD54C60E6243ULL, 0x77326A876CA6A0BCULL, 
            0x9C07B1FAFC0FFC41ULL, 0xF1B421507D1E2C50ULL, 0xEF974787ADEBAA5EULL, 0xD07591CD772EC32EULL, 
            0x5DF4C890A333F7B9ULL, 0x1DA9FBEC0B95D88BULL, 0x8E709F316D82D11DULL, 0xA27B5A8DD761C234ULL, 
            0x9F3547E19F220851ULL, 0x124FEC56E2EB87FEULL, 0x1F63AC2FF175D91EULL, 0x9AE38AAFF5EB4970ULL, 
            0xA308ECBF02DF1802ULL, 0xF427D2560A935D13ULL, 0x7F114F466EA8E823ULL, 0x1876CD1164EB3F70ULL, 
            0x199DCC5A99FF5AC1ULL, 0x8C2831CAEDB8B8D9ULL, 0xFB8D0FED85ABC58AULL, 0xFEE235D9ABCE2B67ULL
        },
        {
            0xB51773B7BD69F376ULL, 0x232AAF133358A586ULL, 0xB30B808A43F4A779ULL, 0xF614C1FF617B1D43ULL, 
            0x5AE4BF6C442E604BULL, 0xB8FB3268AE47FA1AULL, 0xC907AD3868E4BB7AULL, 0xB0E686F216393B5CULL, 
            0x21E5BB3062985D6EULL, 0xA7BF9776658EF8E4ULL, 0xB8B5DDB24CCAAD5AULL, 0xFE30A433D95B859EULL, 
            0x5C9C83B5F2464091ULL, 0x19C064E33F109A47ULL, 0xB974CDF52088FA82ULL, 0x32EBADDF7E162C42ULL, 
            0xF3DF12F0A586317FULL, 0xB7D4008D55712240ULL, 0xCDF7A20F9326FFB3ULL, 0xF08D04D1356F2DCFULL, 
            0x7ADCCE21E35A7390ULL, 0xCE7CDBDD95A91933ULL, 0xA737195AE5636B7FULL, 0x46261FEC924DC945ULL, 
            0x455FBB88733E0963ULL, 0x1D9101C5E8951940ULL, 0x4A6F52F0ED8F6D3DULL, 0x51D040853A4B88B9ULL, 
            0x6C99F5E1B6A64AC5ULL, 0xB8405B05E83B9622ULL, 0xF0441A507A2152A5ULL, 0xCD00B2F607CCEDD8ULL
        }
    },
    {
        {
            0x6EA312E64AAA486BULL, 0xDE0D7379F109593FULL, 0x9FBEAAC29C60A06DULL, 0x2541B8FB59CF9B14ULL, 
            0xD42A7D3206DE3256ULL, 0x67AB1E731EF7C269ULL, 0x3E4E2544933A83FEULL, 0xF78989E96A9ABAC2ULL, 
            0x20998976B73F1BFFULL, 0x768E9DA2EC78BE97ULL, 0x5F218FC0DD3F4DAFULL, 0x2B77D3E8279EB20FULL, 
            0xD225A75FB4ACC9D4ULL, 0x9ADD541638F7A241ULL, 0xE9A0D8B362AD2D03ULL, 0x35988AFD8180BCB8ULL, 
            0x7B79F1166B5D252CULL, 0x9ECC4490B008932CULL, 0x7766B6F3E8EFD13AULL, 0x6B73580ACA40844FULL, 
            0xFFE807E593AB15B4ULL, 0x00D57E893BAB2608ULL, 0x9BB7F9CF2638126CULL, 0x82366556A48F9780ULL, 
            0x07A2630990DEA26AULL, 0x8F1AD460C8367FB5ULL, 0x370EB93E1430AE22ULL, 0x7AEEC854F4990013ULL, 
            0x43B15B77FDFF1323ULL, 0x3772FA9400722954ULL, 0x997FA0B39A74EAC0ULL, 0x1D09C95CAD3E2BFDULL
        },
        {
            0xC85CDB94202B8AF8ULL, 0x1AD2E461ED67AEFCULL, 0x20C08C5FCD63BD02ULL, 0xD46625EF24D5776DULL, 
            0x2F415EAE1DE72881ULL, 0x41AE8D87D3BC9FA0ULL, 0xF4334AFFE4E17179ULL, 0x6CDF601570E01931ULL, 
            0x6060009A01337FC5ULL, 0x80BE23BA857153B9ULL, 0x9BA1C45F703CE801ULL, 0xA15CE7CE54708C8AULL, 
            0xA16735D69956CE6EULL, 0xBFBAD0ABE8762D39ULL, 0xFB417E0B8D7D3B72ULL, 0xD2382C66758C0913ULL, 
            0x3A4BC4FF967A5A96ULL, 0x483432657FDFFD5DULL, 0x5CBF670ADFE52889ULL, 0xF73CAF8C3E9281A6ULL, 
            0xA4C4BFDFD597880AULL, 0xBCE8FA66D99C6E9FULL, 0x55E26B6C82B5E4F6ULL, 0x62A70A94C881831CULL, 
            0x51371F4FF2A4156AULL, 0xA14A395F92C1E173ULL, 0xD598D514F8102990ULL, 0x33BFDCCFE2D9D65EULL, 
            0x63052F8626FA3213ULL, 0x8FA3EB63E1DFDBE3ULL, 0x6EAF549ED12B2B6EULL, 0xA4A2BFA4C7959D6DULL
        },
        {
            0x235CFE99F09B0256ULL, 0xFD640FEE41F74DD2ULL, 0xEA01AFEBBA95786DULL, 0x6767869C89A705E2ULL, 
            0x814A59E6C1AC3E04ULL, 0x7C3CFB67A05A6657ULL, 0xA7F3562754BD2858ULL, 0x2F33D0057E9F50F7ULL, 
            0xC6E33DD06E6CEF3DULL, 0x761F4B67C84A7108ULL, 0xB59CCCC90D10341FULL, 0x8DAE7B12E372222DULL, 
            0x16CE8E4885354DB9ULL, 0xC5CAF85F3C38B42CULL, 0xDA5D1DD0CB47B611ULL, 0x28EF92FEBB86E1FCULL, 
            0x5D29F38DBDE4A2A5ULL, 0xBC2ED2DF55932EEFULL, 0x89ED0324960D794EULL, 0xA254F3535AAC141CULL, 
            0x936F4B97A93E0100ULL, 0x89018F1B77951E20ULL, 0xB5CEC91BA58D52E2ULL, 0xED43253965AB2C44ULL, 
            0xE2ED3018D69A263BULL, 0xBD46A79331C8618AULL, 0xD069B3B0CEC29A05ULL, 0xF7469E9EB8866476ULL, 
            0x4FF7F7C308F0C340ULL, 0x8EF1B8D473635C5EULL, 0x71905FE42A344F61ULL, 0x2D244204A8237B79ULL
        },
        {
            0xB1F158DE1FA51E5AULL, 0x049B06E580CA2333ULL, 0xE6C0F169A8266FA0ULL, 0xFA0EE6EEE436E254ULL, 
            0xD75CCEC7840B972EULL, 0xF58C5FEC115F7FFCULL, 0x652EE0FB99C0E495ULL, 0xA55683AAFC7B5781ULL, 
            0xBB899164CB2F185DULL, 0xCF111917C746E42DULL, 0x09E92AF7C6142398ULL, 0x4A8F997723E7AA1FULL, 
            0x8BEBD2E33F1B8FD8ULL, 0x7EFC66A4E320E699ULL, 0xA60688AEDD2742DAULL, 0xFB7CDE660BCA6A90ULL, 
            0xE4BA3F20DD1960CCULL, 0xA69261A8EC61645FULL, 0x5D8D1E98F742AB01ULL, 0xBE161C498F42D554ULL, 
            0xA9762A60534EE9BDULL, 0x59C51152EB6B4CA3ULL, 0x5B094B8659A38291ULL, 0x08992597A578CBEEULL, 
            0xE7D1BE933B7BFC33ULL, 0xE79B66FE2441C71DULL, 0x7B783BC12DA38237ULL, 0xAEA55199FA67426BULL, 
            0xE50E0AA598ED3742ULL, 0x88A207828FD59ADCULL, 0x2398A4D3EF1F452BULL, 0x0ED505AD0F30C72FULL
        },
        {
            0x6A5C0AB3E48E54CEULL, 0x79D6600F2DE6CB36ULL, 0xE7E67697A1802064ULL, 0x4B7E932349F43910ULL, 
            0x925B23F7FBF5B507ULL, 0x2BB2E43DFA5C693CULL, 0x327AC5DF33E78A3DULL, 0x5557240AE5610C63ULL, 
            0x3EFCF9AFC8EEF1A4ULL, 0xB1CB7740FD86D624ULL, 0x88397E15B956A254ULL, 0x3065324032220A3BULL, 
            0x6F267686707B622BULL, 0x3E0A457D906D668FULL, 0x4BC1664F51E78B95ULL, 0x62C8D7761FE60551ULL, 
            0x105E41D80F54BED5ULL, 0x21EB08A73B65FEA7ULL, 0xF201701ACC0AB87CULL, 0xFA37500E7D691264ULL, 
            0xA9B68A27C7E525E7ULL, 0x8B73F44532AA1316ULL, 0x0F1AE0311AD51F8BULL, 0x659E193F6F165CA9ULL, 
            0x92EAC9CA536FCDA7ULL, 0x9A0672D550F1AA7CULL, 0xC5702ACF3D4A916BULL, 0xD9BE21E0BB32FFB4ULL, 
            0x196FBCD8593D4CC7ULL, 0xD90C646861BBAC21ULL, 0x8454D18C02F43DC0ULL, 0xF6C324B85242758AULL
        },
        {
            0xE6F254E2BD25FDD9ULL, 0xC3483F850E4D5919ULL, 0x9AC0EEDF9CCBAAE2ULL, 0x03424519F247C1B7ULL, 
            0x68C3DBE972383776ULL, 0xDAA8D89DC06CE6A1ULL, 0x714EEEAFA831912CULL, 0x0BF6A9EDD1AED5A7ULL, 
            0xC0014440CE7741A1ULL, 0x3693221C3EADFCE1ULL, 0xBFD00A7467ACBC2EULL, 0x686969D49189F5B8ULL, 
            0xB48B3FDD1003C853ULL, 0xD4804DF2D403B92EULL, 0x822D1560C06F0548ULL, 0xE01358473E5822BAULL, 
            0x5C2E1DB42722C4EBULL, 0x0F94CADE437EBA2CULL, 0x1AF034B8B285FF12ULL, 0xC3FF91DF0BC63156ULL, 
            0x72FBBDC0DD6AFB81ULL, 0x00C5573C83C10A1EULL, 0x67957A58A1E11D74ULL, 0x1EE347062D9302D1ULL, 
            0x1F340D815CB892ECULL, 0xCC5A7AE9BA730112ULL, 0x25263E3EE7CE9180ULL, 0xF9423FD2BF362537ULL, 
            0x1A0F51151FE5D203ULL, 0x8C141053263D05C6ULL, 0x86E6E1F0F6FC72B2ULL, 0x03153D98674E5B55ULL
        }
    },
    {
        {
            0x08C96983CBA46ADFULL, 0xE5C0E807C031EECCULL, 0x299856CFDF037C7BULL, 0xB813A1EC924D9CBEULL, 
            0x0E6291ACF46CDC9DULL, 0x7196440B7B7EFAF9ULL, 0xDA2FA27EC6B967E6ULL, 0xD80CB3DFB5A7D887ULL, 
            0xC0C04B726E4F1033ULL, 0xF452480E57F6940CULL, 0x401FF24602A5461FULL, 0xCBF5AE604493BDCAULL, 
            0x1A8484F34D7E347CULL, 0x7CEA51C83936284CULL, 0x0E0847782AADFC76ULL, 0x00641C0B457082A3ULL, 
            0x8D763B50D543504DULL, 0x37A69FF6D02A56B1ULL, 0x2798BD15326465FFULL, 0xFB5A235D7A090442ULL, 
            0xB10D07AE17100546ULL, 0x9C659BD870F792B8ULL, 0x1BE0D7747B53740AULL, 0x422704B143AB9193ULL, 
            0x9079DFB943F75382ULL, 0x535B00448A5FF498ULL, 0xE5C40B6E181D2426ULL, 0xD64E4448AA523704ULL, 
            0xB1549C5759E2492AULL, 0xE70AA1A6D6389C91ULL, 0xA8BFED5F5B43AF31ULL, 0x704D097AEAA07109ULL
        },
        {
            0xE37F5B69899FB3FAULL, 0xCC320223EACC67BAULL, 0x17F1694EFA99C8B6ULL, 0x9C8F9BC343220083ULL, 
            0x24A6EB3E2726EA8DULL, 0x24841F92977F3EAFULL, 0xB1FEF0F48F29358AULL, 0xFC6AE3B38ACE7052ULL, 
            0x9EA773A3A6AC62B4ULL, 0xCD570A780B0D820CULL, 0x0CC8A8E8F0AE7933ULL, 0xAF9B7089D5038E81ULL, 
            0x452DD90DA3CF2C80ULL, 0xB788F0F456F0EE98ULL, 0x069BAA263FFE535FULL, 0xFE094E620FB0A7ACULL, 
            0xC026D49D6DBF2E69ULL, 0x248C12C31826EE59ULL, 0x76516E8B1EAD4DFBULL, 0xF2D558C3A4E0D4FBULL, 
            0x3D2EB5840BD13BDAULL, 0x9551CB7262BF23B4ULL, 0x0E6E3A1455B2C922ULL, 0x0744DC92A553F708ULL, 
            0x245BA5764755D248ULL, 0xE2F896643200DF23ULL, 0x6A0A623FA5786FFBULL, 0x1CFFE44669BCFCFFULL, 
            0x4AEF96EA42F42477ULL, 0xE9031A888F1C6CC0ULL, 0x78C62FD739B90476ULL, 0x4DBF32C88DA014C2ULL
        },
        {
            0xA47323D53FB53DC2ULL, 0x26AD677359DAB929ULL, 0x37247BC88091588DULL, 0xA69AE8F19BFF9261ULL, 
            0xEF638BCAAA3A4A70ULL, 0xEB7B0D8EF784D76EULL, 0xEABEE851FC55CF8BULL, 0x040493E4D3A239E0ULL, 
            0xEFCE1151808F031EULL, 0xD27226C8F6A0C8F6ULL, 0x174F3D71B85060F3ULL, 0x8E664039FD403FCAULL, 
            0x7E4B77DBB8F5108BULL, 0x663438970C0EEB22ULL, 0xBD6C63A38F82280EULL, 0x1AD31AF99681E069ULL, 
            0x72A05BFCC9047CADULL, 0x905EC541CD9017C5ULL, 0x11B6045332411381ULL, 0x3BF4F9854C2A5C60ULL, 
            0x970351360A80F5B5ULL, 0x28BA44C18C429D37ULL, 0xCBFA4AF983427357ULL, 0xD7C53372431D0FD7ULL, 
            0x4794C1D13A845F28ULL, 0x70AD69F99EDBFE2FULL, 0x37896534EFAA7C97ULL, 0x56EE8083101A773AULL, 
            0x5CE355C657DBC08CULL, 0x7181FA8AE318BE20ULL, 0x13A3B882447E44E1ULL, 0x7586375088030CF6ULL
        },
        {
            0x659DCE00C797441FULL, 0x596AC245CC7168B4ULL, 0xC32CE88826610E32ULL, 0x19D69E9A2F2409F9ULL, 
            0x64DED8A820CF6661ULL, 0x5058EC75D56FF785ULL, 0x9D92385BEF642C9FULL, 0xD4B0680939A3D2AFULL, 
            0xBD9837A648EBFBA8ULL, 0x57315A87927B93D4ULL, 0x8BCB04C4E5063038ULL, 0xA344FA3E9AA2D847ULL, 
            0xBAD2AC8F8140F539ULL, 0x15E9F7A86C53F424ULL, 0x8E166CF56828F2FAULL, 0xF09E0BAFE3D2548EULL, 
            0x4F8D44F7701FAF5AULL, 0xCA48BBC6CA8F6633ULL, 0x1F059581D4ACD816ULL, 0xB1FF1BC808FF00EBULL, 
            0x5EB8B2EA34423709ULL, 0xA60DC337885A7E6CULL, 0xC8B8E4E23C42F6ACULL, 0x3A67785C8E5DD6CBULL, 
            0x2D6A5FE29FBB5DECULL, 0xA5C688809DF8EE5CULL, 0x8941838A9686F894ULL, 0xAADFA3E6A8542330ULL, 
            0xFE71BCC13733BB22ULL, 0xBE3F0E505300D03AULL, 0xF04B3DD3BA93AD5BULL, 0x79FCCA93BCA4FAFCULL
        },
        {
            0x81D9DE3246EA74C3ULL, 0x2FE03FEDAF276EF8ULL, 0x15B11366D3F291C9ULL, 0xB64AEE8B524C49DFULL, 
            0x5FB268ECE0A16115ULL, 0x8E41325E22C88E5FULL, 0xF852BDDD8B7CABBFULL, 0x6AB37C6466062290ULL, 
            0x3D4C4A876B8AF86FULL, 0x1278C8894C8A7E99ULL, 0x144087F938BB9014ULL, 0xC4BFBD5F31478E9DULL, 
            0x86EE8E266EB5A44BULL, 0x9B4FB07173103CF1ULL, 0xF5FD034B1C28970BULL, 0x888F8A54D57F71DAULL, 
            0xF007B3BFF22D1EFAULL, 0x0B6AE6776F25456DULL, 0x189F4B4085908B66ULL, 0x544F8AF2DC08267AULL, 
            0x21296978CB35B07FULL, 0xB240ED0707B1C531ULL, 0x146D93FFBE09192DULL, 0xACE7442FF2166118ULL, 
            0x58826B972F4752FCULL, 0xCC28E80668A8D78CULL, 0x774DE0A44DA5F715ULL, 0xD579B7F779AB4B1DULL, 
            0x128F8758E49E6823ULL, 0x28E2B17DA5C6CB2FULL, 0xF43BE44D237F02F0ULL, 0x3F496330AAFAF8B1ULL
        },
        {
            0x3EA9131113B55CC5ULL, 0xB00001F5EF95817AULL, 0xE0CB23550A41ED68ULL, 0x389828F6FF7FAE66ULL, 
            0x4094EDB7C12D8594ULL, 0x2A2528F2179457ECULL, 0x36334235D28CD56EULL, 0x322BC7898F65C20DULL, 
            0x01826A504F52021AULL, 0x02C3797B7A558245ULL, 0xC3CD53B9758350A1ULL, 0xC0D07AEDECD71BD1ULL, 
            0x103FE7B33DE12C20ULL, 0x71C7E41D242BE762ULL, 0x0D2B12220669BE71ULL, 0x1A89C87B235CE3F7ULL, 
            0x4377D5301F329EA5ULL, 0x18B5E12BD0F4ED81ULL, 0xAEFAA669B4EB2196ULL, 0x0A9B0289E1446514ULL, 
            0xFB5655C1E3478BD3ULL, 0x4E88C840A4A341B0ULL, 0xDA7F125A380A0758ULL, 0x5B96CC7248D0AC77ULL, 
            0xD1244D776FA353CDULL, 0xF457FEAC6FEADD75ULL, 0x203A5555B490023DULL, 0x6735137617A8FF3CULL, 
            0x9E0151AE817F9DD3ULL, 0xCAAAB3A433743684ULL, 0xAE7F089C0F4107DEULL, 0x922697CFCB0C8AA7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseFConstants = {
    0x3FA4337A99965855ULL,
    0x40CF22B8A5AE2D61ULL,
    0xCE394D7554A92129ULL,
    0x3FA4337A99965855ULL,
    0x40CF22B8A5AE2D61ULL,
    0xCE394D7554A92129ULL,
    0x31DDCC970C081113ULL,
    0x11D8EE6D75C487CFULL,
    0x17,
    0x68,
    0x9C,
    0x84,
    0x14,
    0x24,
    0x6F,
    0xF4
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseGSalts = {
    {
        {
            0x80FFB64477B194D2ULL, 0xD78F20D086B24E34ULL, 0xA5B93896F90941ABULL, 0x0F6BE9641A1A2083ULL, 
            0x07C8F0E3E9EBF990ULL, 0x26535A2BF98048E5ULL, 0xB8E09E844BC52C46ULL, 0x2EBED94CE11BC836ULL, 
            0x3AFE08DDA952C980ULL, 0x22EE90FDB158B2EFULL, 0x75BE69C11F615467ULL, 0x770AA2B53AEBA66EULL, 
            0xE31ED9B52D09983EULL, 0x0D17A3C937426E0BULL, 0xCE76BABAA7914D80ULL, 0x34F0173490DB12E3ULL, 
            0xF69DDD3BB8ECBA57ULL, 0x6A2B6CA02E0D7DD1ULL, 0x5B3147391335638AULL, 0xFA2624291F1AE736ULL, 
            0x587D1448D3BB1C32ULL, 0x4ECC29661810B319ULL, 0x3680C7520C362786ULL, 0xA2B03DA941CB35ACULL, 
            0x46BD2CFFA05F3C38ULL, 0xCE52204FB3244504ULL, 0x1303D16C0D01F7F9ULL, 0x1F6872F061611793ULL, 
            0x2D35AF3A9D0ED63BULL, 0xB5148AC78728C63BULL, 0x35A8597571868B18ULL, 0x17A60408A9CACE20ULL
        },
        {
            0x564F0C8CBFB28DA2ULL, 0x5D44F2DA1DB0D61EULL, 0xFD87707341B4972FULL, 0x42339946014AEA5AULL, 
            0x3F1480579437891BULL, 0xB84137DD4ED84E04ULL, 0x469039C330666C43ULL, 0xDF28EDF38137BCA9ULL, 
            0x624CB7C8211EE7ADULL, 0x0501916267C89719ULL, 0x7F34B2C33162F952ULL, 0x7E1DF0184DD989BAULL, 
            0x49C7C96FD995AA89ULL, 0xF027FA72ECA69030ULL, 0x28A2CD4874568CBAULL, 0xF9070A3CE8AA7A27ULL, 
            0xD9A3574DD1F350ECULL, 0xB5C58B81A6DC058FULL, 0xC4F7995D0D61BAB3ULL, 0x445909D3CDF97A3CULL, 
            0x10A5DD34E6CE4E7BULL, 0x713859D3343BDA69ULL, 0x986F238E12B49ACDULL, 0xA69A244242C08FECULL, 
            0x89C5D2D498650C8CULL, 0x3E7829E29FA4F26FULL, 0x87E95872438E88EFULL, 0x49F7E324FC24D5D6ULL, 
            0xD876F8A3544FA5A7ULL, 0x7CD3B6857F98F204ULL, 0x1C4D8259840C8BFAULL, 0x3E4283DC5F6C1347ULL
        },
        {
            0x97FFC5204C143A13ULL, 0xF0CF9E044E2D25D9ULL, 0xD7B54D630E404221ULL, 0x443E0EF032B66703ULL, 
            0x08D39ECAC0DDDB42ULL, 0x96AEC9432EA39A18ULL, 0xA0FEA390D03C1BDDULL, 0x5274227B7D6527BCULL, 
            0x00E9F5FABE8572CFULL, 0x02913F38F71C00D3ULL, 0x453A61A90B511C12ULL, 0xECF748288D820228ULL, 
            0xE49265FCAA2A6ADFULL, 0xCD94E44B81C7B239ULL, 0x26009712C9C2EFBCULL, 0xA2B19E21549DA7A5ULL, 
            0xFF9CFA4CAF6007D9ULL, 0x79E1EC9324C40004ULL, 0xF868FC6CEDE4CA1AULL, 0x8A66EBDDC432B9F1ULL, 
            0xA7C5205F23522277ULL, 0x4EAB274141C83FFCULL, 0x76E9819DE6599761ULL, 0x412A1FF967FD2860ULL, 
            0x06CECF3515DEA43DULL, 0xF1E67C56D6577595ULL, 0x8017D339C3B06479ULL, 0x4A7562C748F89281ULL, 
            0x65E79AFE2FC82010ULL, 0x1695CC3039A39820ULL, 0xD0C67862A017D90DULL, 0x64779A1DACB580CAULL
        },
        {
            0xFC0E4CA3F5078A4FULL, 0x8D3765DAC939C077ULL, 0x0CF8BC0172333D33ULL, 0xF1E4FEB10F62345AULL, 
            0x76E84C190B447130ULL, 0x0F634B3E710D7247ULL, 0x58287429A8CC722EULL, 0xECAEF08BE6A0DED1ULL, 
            0xB7EF6A6B7995F9DBULL, 0x91D0CE3C3C8B93C7ULL, 0x6E8D7E44A4F2A430ULL, 0x8E43685158F25B63ULL, 
            0xEBB128DBD9BF1554ULL, 0xCBC72243584598D3ULL, 0x3ADAD4C7572B698FULL, 0x1D3C090A171DF89EULL, 
            0x34D13EC78967E6E7ULL, 0x5205EE0AD55F41C1ULL, 0xD9C064CF5E119678ULL, 0xE853DC96E7BEB68BULL, 
            0xDA7EE54D0E838D6DULL, 0x435C873B38FC107CULL, 0xEAAA6BBBE33C6E16ULL, 0x56D7C1C582C5B6F1ULL, 
            0x32E3F19703BDE8FAULL, 0xB7CD3D9715973CA6ULL, 0x9D3D7723FE6E5AC3ULL, 0x03B36CD8CE40A47AULL, 
            0xB6CBA97E53D23129ULL, 0x83BF25282067FE7AULL, 0xFBE5FDFDE5AC0094ULL, 0xF1E1CFED74782F4CULL
        },
        {
            0x68EE65202B224BDAULL, 0xD1BAD94DCA07D835ULL, 0xAF10C4A9E294830DULL, 0x940BF0FF7864B2BDULL, 
            0x67D295F2F47376F6ULL, 0x74962E1562E4EDCBULL, 0x3F4EF1302CC481A9ULL, 0xA7E580CBE688A7B5ULL, 
            0xD321BD6D4F5E0871ULL, 0x8A72DA28E90A33ECULL, 0x09C48F0C00599D09ULL, 0x5BE0AA726ED89938ULL, 
            0x410DB512BB931554ULL, 0xA15D441A127A65AFULL, 0xD0B1E66B46F7FE20ULL, 0x805B5CF0DF8D5100ULL, 
            0x0EEBFD494B18CFB6ULL, 0x152FDFFC5E622D2BULL, 0xF2DBC0261FF05AAFULL, 0x5C9B90B488C10616ULL, 
            0x2559453417E6F239ULL, 0x7469E81CA6C4FB97ULL, 0xEB101C8B2D10EEF9ULL, 0xCDB927D6D9762B0DULL, 
            0x1D1E2F06FF31B8B0ULL, 0x1DFCD554B6E7CE4DULL, 0xB7A2DF42F5A4526FULL, 0xA246B3915D1ABC54ULL, 
            0x9203FEB0F3E89169ULL, 0x86656917F6965ECBULL, 0xC5F7D075241357AEULL, 0xFFA49E4C768E5B86ULL
        },
        {
            0xB75175386A3A1788ULL, 0xD816C73B7D2B27EBULL, 0xCDB0AAEA2DB4615DULL, 0x637699C2CA22BB37ULL, 
            0x22215E40A654AF7BULL, 0x0B31824FE725CC31ULL, 0x09C7295FA48BBB9DULL, 0x5DBAC26B45FC484FULL, 
            0x0B7843E590F7EA2BULL, 0x9B2F977B1C646168ULL, 0x27181CE5368D168AULL, 0x5EAB00B9B3C8F8E5ULL, 
            0x8AA70CDDA50B1E46ULL, 0x81BF54ADF9FF1F31ULL, 0xEC3F7D89D67A1B44ULL, 0x54EE1502527075A3ULL, 
            0x714E5091D5AF3AD3ULL, 0xFE08F88A00E7F130ULL, 0x438F03DB63A70213ULL, 0x59500CC41EBFFD1DULL, 
            0x720AE0ADB9824E91ULL, 0x0C504B66E24CC691ULL, 0xDF25ABDB43B5F715ULL, 0x67250B81E127D107ULL, 
            0x7C155718EACBC307ULL, 0xD4CB54A73E1C38FBULL, 0x502DAD9A5F0FF17FULL, 0xA17F1BEB7F1D1924ULL, 
            0x4F2D26BE231981F9ULL, 0x240D2216FF402B5CULL, 0x9B383BA95EAD523AULL, 0x2ECFF37C07A89281ULL
        }
    },
    {
        {
            0xFA0E2B2BD7D8EC51ULL, 0x02D5E75A271CD96EULL, 0x194B2A3252C25BF2ULL, 0xC518A0D180A16107ULL, 
            0x9935D9FA097B3E0FULL, 0x77512DF58B970D23ULL, 0xA1670BFDAA15B2FDULL, 0x16EFC59AC87FC046ULL, 
            0x9E1A1DD70CBB691EULL, 0x00340935CC676478ULL, 0x1D30321714F5877BULL, 0x0CE7B7DE2DB00438ULL, 
            0xEA758238A0CA8BF7ULL, 0xED1C18AD6765A1A4ULL, 0x392B82C347345BECULL, 0x34C8F275A74D709BULL, 
            0x8AA65914364655F0ULL, 0x6A99571377FE67CCULL, 0x99F251692827D4FBULL, 0x89CD6C5C47900FD7ULL, 
            0xB810B47E8BF25C86ULL, 0x52C6443D9D5AC945ULL, 0xC128B3D0921626EDULL, 0xB33C03CDA8BE3182ULL, 
            0x92AAB6983FFFFEF3ULL, 0x9038343E26D5DF77ULL, 0x36AE376486C53582ULL, 0x2ACD90CC7277F35CULL, 
            0xEA6905DD2C57BF25ULL, 0xBB1CBB4B76160F48ULL, 0x9DA1E5108472CC27ULL, 0xFC8284ED3342B8D7ULL
        },
        {
            0x67062F9E4114FA56ULL, 0x51EE13537DCED067ULL, 0xB6D94FD2EFA414DCULL, 0x1253C62034B9EA83ULL, 
            0x410BD312DDEECB0AULL, 0x8A73F3550248654EULL, 0xBBFCD748A0D91721ULL, 0x06734C5448D5F580ULL, 
            0xCF9ED241404CFC22ULL, 0xFB95AAD6038084C4ULL, 0xAEC729BA866E7C3AULL, 0xA3D7037A6C0B3261ULL, 
            0x230F9CB29692EF09ULL, 0xC92D34D23017ED2DULL, 0x4D780839E350D050ULL, 0xCAF57F783CF3DA48ULL, 
            0x852A69EB5A9D0021ULL, 0xD48C9A51E105160AULL, 0xE263537B5E4CF0F6ULL, 0x2FC1A6CE086FF279ULL, 
            0x18FD0323A97C433AULL, 0xBA0313093CB8BA0AULL, 0x4F9EE85DE3BD307CULL, 0xD2CC7631B9EF525EULL, 
            0xABC0B70162673ECBULL, 0x91722FE6E0E84363ULL, 0xA85FF50AB4E076F1ULL, 0x257C5B611CA67317ULL, 
            0xE9B28E71D62D5274ULL, 0xCA2C443072C648CFULL, 0xB94C0B73C2823319ULL, 0xCBC76757BF564C5BULL
        },
        {
            0xA6345CF518777B93ULL, 0x36A9F4C0EE1619DFULL, 0x4369203F476A4B08ULL, 0x1F6A34ED619AFCEAULL, 
            0x847D035B9D070672ULL, 0x7814892023F865A1ULL, 0xB601D0951E2CDB46ULL, 0xEAC1E10045980B0EULL, 
            0x66D19731BBD6919AULL, 0xC3EFF7D69571FF20ULL, 0x49682F6F0B6EC433ULL, 0xB084C36BED412EE0ULL, 
            0x325D32A88CB22BEEULL, 0x2FE23929D649B819ULL, 0x91EDC7356072BF00ULL, 0x31F56133DF98A9C6ULL, 
            0x804495218CC8EBEBULL, 0x439F4F693DBB480EULL, 0xEC66DA54E4F09A23ULL, 0x1DD32AB55D52AC81ULL, 
            0xEF27BAFB82375F75ULL, 0x0165197703526C35ULL, 0x48EA41A106462749ULL, 0x68E839D4DF7C67CEULL, 
            0x3449DF5A9669E4E0ULL, 0x12B3763EFC70E9B5ULL, 0x08F1E86499C2AE57ULL, 0x9F539A18D3D74F70ULL, 
            0x905F57DF6814F3ABULL, 0x0DB2431D8073236EULL, 0x7667F014F9499886ULL, 0xA0B3B6B067B5B76EULL
        },
        {
            0x78D1170CAD647144ULL, 0xBA7AF51363163EA8ULL, 0xE500B08AA4A67AECULL, 0x3E800AF1EB59D670ULL, 
            0x9712EF9F13AE5118ULL, 0x8AE4754CAF824CA8ULL, 0xE6AC7C22C2B4DBC6ULL, 0x6D84D785AB66FD30ULL, 
            0xB291F553C0CCA377ULL, 0x05769E928FE06CF2ULL, 0x457E38848996C80EULL, 0xFB76CBB1BABEE8D2ULL, 
            0x99727DAD41EB0230ULL, 0xF8CE34F52DB65AD8ULL, 0x043FCDB62A6A88E3ULL, 0x8CB11D0578B58CE8ULL, 
            0x19993DE0183C30BBULL, 0x784BE480AA5236E6ULL, 0x41425AC375C90152ULL, 0x57338016C8E5ACF7ULL, 
            0x0C5DB535E7D41258ULL, 0x741A848CF860830BULL, 0xF858FF5139AFDB16ULL, 0x28B0B70C19C5E0DCULL, 
            0x18E88655F8FA616FULL, 0x43FCEC96070CF1A6ULL, 0xB8C5D28021F4EB52ULL, 0x1B3D1C99EEEDA39FULL, 
            0x7338BE9E3A66CC6CULL, 0xFFE8B30C9D24DB6DULL, 0x4ABBF84CE4667412ULL, 0x79506232FF834B59ULL
        },
        {
            0x7BBEB2E355B6F0A8ULL, 0x2E4609048823E7D9ULL, 0x57309B9AACCBDF3CULL, 0xC5D1E20731EF5DC6ULL, 
            0xE736EF106476A505ULL, 0xABD606BE37F6B819ULL, 0xA0A36544E3EB423CULL, 0xD0CADDC1AEA6E105ULL, 
            0xDFAB986A92219A26ULL, 0xC7556407ECE3A598ULL, 0x69107F069867A75EULL, 0xCC496FA4483CADCFULL, 
            0x556389778DAF73BBULL, 0x3980FE6F400753ADULL, 0x22D6A3B4E84AF6C7ULL, 0x1B68BAAA7413CC56ULL, 
            0x3E91CCB28925EA71ULL, 0x876D3EDF958402A1ULL, 0xAB26836C3A81A7CFULL, 0x0C54AA3D648C5C5AULL, 
            0x82434ABB5C3CA3A7ULL, 0xAB282C7DD0B92F25ULL, 0x4231185C54054A7FULL, 0x136C6FAFE0000739ULL, 
            0x5AFBFF476EBAC392ULL, 0xA722371022AC7E40ULL, 0xC7C1CCF4FA8401ABULL, 0xB98DCF54300C58C9ULL, 
            0xEBC39A52CAA5F074ULL, 0x1D9EAEED67D8E9DDULL, 0xF049BD6C96C20103ULL, 0x1249152137B84633ULL
        },
        {
            0xBC1E7A7ED425D3C2ULL, 0x3D73EF02E0785CC2ULL, 0x885F016F2B636CE3ULL, 0x690DB481EDDE1FBBULL, 
            0xD0D12619F06559CEULL, 0xDFAAD7C772B2F08EULL, 0xDFBEE7E9F368EBC5ULL, 0x81E784C9ABE40BD2ULL, 
            0x36D863C2D9E2ECDAULL, 0xB8AD285BE889A60FULL, 0x965D9A22D266DF41ULL, 0xCE8DD953B4C4ACD4ULL, 
            0x12EAA95A0B714681ULL, 0x0DDB06D37D1977D1ULL, 0x20211C7FE1C67730ULL, 0x6F7725087605383FULL, 
            0xB4872745B1A86DD2ULL, 0xD1ED08AF4AD4C155ULL, 0x230D5F8F3E701EBDULL, 0xE0647204CB150BF4ULL, 
            0xCD26F60F26605023ULL, 0x78751A9F26EAFC56ULL, 0x746C92BE938EF869ULL, 0x51944A858EFD29EAULL, 
            0x3F3014E05EC8AEEBULL, 0x96B39D2B2DB92496ULL, 0x5971DC0B26E9A621ULL, 0x79AF58D6BA361BF9ULL, 
            0x18FB6BB0BAC2CBC0ULL, 0x00D58D0C4CE8A60FULL, 0x5222FA6083785452ULL, 0xFF548898ED6FF9DDULL
        }
    },
    {
        {
            0x1A86AE79C8A73846ULL, 0xE1901C404199CFCBULL, 0x41D9F59FD6088878ULL, 0xB4F5680FBA48F2C5ULL, 
            0xD4D54020CFFE3880ULL, 0x8BCEFE1A3BF12DF8ULL, 0x6B8F1302DFE9852FULL, 0xFE174359A4013688ULL, 
            0x7BDDD3C202CBE95CULL, 0xE952D772A963CBDAULL, 0x7A0A3E6BBF6CB310ULL, 0xF9CE8B037A115C0DULL, 
            0xBDB117417D8AE9E4ULL, 0x2B2DC68F31E773A8ULL, 0xDFF54B5BA69C0E83ULL, 0x8CEF245B976A06FDULL, 
            0xAA1833EC69C86BF7ULL, 0x5D836F5F16917AE1ULL, 0x9CEAFBB7F0EEDA3BULL, 0xAFEF2341E78B457CULL, 
            0x9C9996C6F5EB7E25ULL, 0x08349106057E89EBULL, 0xD8A76E7753282FBAULL, 0xCE7E95C36BD14167ULL, 
            0xEE637A029B96B21EULL, 0x7FDEFC02EBD0177AULL, 0xEC57EAA840ABEC20ULL, 0xE7F9484878978DC7ULL, 
            0x182A521D0DC6A521ULL, 0xB1A9829283A415A1ULL, 0x3A9483BC1A71C319ULL, 0xC25BAB6CEBC3E2A3ULL
        },
        {
            0x9A833F1C1EAF183EULL, 0x63924EB967E40F1BULL, 0x0A5B258D7187F995ULL, 0xB60E26F301E6D051ULL, 
            0xAED30A3F44658367ULL, 0xAF22D60FC15405EBULL, 0xEECE97ACA15A676AULL, 0xFCFF138DB9C688CBULL, 
            0x1DDC23E13D62E187ULL, 0x464FA6B237570198ULL, 0xACA21521B1EC084CULL, 0xC0DD0CAA41D515ECULL, 
            0xF39A67B22AB3332FULL, 0xAE0D5543BE8EF3C0ULL, 0x505210D64C9C15C5ULL, 0x92421ADD7B16BF20ULL, 
            0x37C06209DDB39E29ULL, 0xE3A6B002BDC0B7E1ULL, 0x2D1BC353A5E7836CULL, 0x0DD2D9CAA048A9EAULL, 
            0xE34D0F0D5E141023ULL, 0xF1C29E0264AA1FAAULL, 0x9E334CEB878EAF9FULL, 0x56AD549ED8F3AA09ULL, 
            0x3F88303360B4E649ULL, 0x1D140B6259C77327ULL, 0x6EEDB772DE27424EULL, 0x7BEF44D9F780EB4BULL, 
            0xC2C4466584FCC7DAULL, 0x8D2415CE6C74384DULL, 0x82E82D5BD3DB2116ULL, 0x35D51DFF471140E1ULL
        },
        {
            0xE6190B5C735CC66BULL, 0x33AAFC93B27F74F0ULL, 0xF4F3E2B5DAE47B4DULL, 0x376954CEC4CD5C13ULL, 
            0xDC226F30547CD7A5ULL, 0x03A3EE8CE97508D6ULL, 0xF0B27220CC9A8E44ULL, 0x35C9AB13A1EB57E4ULL, 
            0x89883E46CBED88C4ULL, 0x8B9BE8A930112E6AULL, 0x729A2B89E8FF2376ULL, 0x20993746E9F1EC38ULL, 
            0xC2AA1AE36AE1848EULL, 0x2B062259D5AF370EULL, 0x4630F59C80ACB6E8ULL, 0xFC07A9D36123056BULL, 
            0x681E9E3CB33634BCULL, 0xAB31440E82C98E9EULL, 0xA0BC1BEBDA23C736ULL, 0x1A74CFA68C2A6C48ULL, 
            0xBE1684AC589C2FD8ULL, 0x058BA9AEFE376F25ULL, 0x79F96F961D8D2866ULL, 0x55EE71B1EFBBBC92ULL, 
            0x23E692288316EDD2ULL, 0xAA88570A77B204DAULL, 0xEAE30D63CC651627ULL, 0x4D2FB3B636506E72ULL, 
            0xD503790F81D50F98ULL, 0xE041BFD92E5E4B62ULL, 0xC375E8A6FB9214A4ULL, 0x061FA7AA8B7C5E9BULL
        },
        {
            0x3FE0267F9E621B5CULL, 0x7944D63DB4D967FBULL, 0x3D69F44BC30FFE94ULL, 0x448DE5E41CD0FC01ULL, 
            0x55C2D2DF78F31521ULL, 0x9365FAE9AD8E917DULL, 0x22E04943A7991A7DULL, 0xE964D2BB79E42093ULL, 
            0xA378EB77DBF16FC4ULL, 0x36C82BCBCFCC2A60ULL, 0x869EA2F62EBD5FA6ULL, 0x5F511F1D36457F92ULL, 
            0x576D436AE5829860ULL, 0x396B4DE984E62307ULL, 0x6E89FC7EB904BF01ULL, 0x886C01282E4E4205ULL, 
            0x0A54509500CD0E08ULL, 0xAC8547FB2FE144A6ULL, 0x63F661A1EFF0F842ULL, 0x682985783E2E187DULL, 
            0x3BB058A1A8E2D5D2ULL, 0xD27A717116D85561ULL, 0x2ADD172528F9A2D4ULL, 0x1BF238CD2F1C865BULL, 
            0xAC102814D0AD73CDULL, 0x7A4EB441F73A3160ULL, 0x339D5F4528AC8F99ULL, 0x12AA8040475063CFULL, 
            0x9AFC030E61FAC026ULL, 0x45B4DA0628D08A72ULL, 0x29DF6740F7F6FC38ULL, 0xB8951548BDA12126ULL
        },
        {
            0xA75CB4785B7E7DEBULL, 0x0B65986BF888CB7AULL, 0xF3177546C27C50F4ULL, 0x9E52E4EC9B1E2109ULL, 
            0x134A24F08BDC6D98ULL, 0xA828F7F81B8BF74BULL, 0x9828E8726B0DE2C7ULL, 0x3DAF97B0FC55025BULL, 
            0xD63ACDFC7A154B3CULL, 0x9C46DCDD561834FFULL, 0x01DEC63B3F26CC1FULL, 0x5843F62A684FB065ULL, 
            0xB3E748274A4EE7D6ULL, 0xB95161F51FE7DE1AULL, 0xB3CF3181765803FBULL, 0x7F8AC19BDD3B7910ULL, 
            0x7EC9E455B5745992ULL, 0x7B49E5B623BEEE9EULL, 0xD22CF8CCE6AD2F74ULL, 0x9B56835319BF426CULL, 
            0xFA6CE86C65A51C0EULL, 0xC998A753EDC4E529ULL, 0xF1AB580E0472028DULL, 0xEC424354B7548E9EULL, 
            0x358EE3444D6E3DD1ULL, 0xBC3334E63FA3F0E5ULL, 0x1BACAEA63D0FAFC9ULL, 0xF39DD98C42D29EA7ULL, 
            0xF0E6A325844F8749ULL, 0xFD1D4DBED3258E54ULL, 0xFA6DD26D8695E330ULL, 0xBF597D5E936085BCULL
        },
        {
            0x2FD0EF7390ABC1C1ULL, 0x1E85684FADBB611BULL, 0x2065C3F0B8DA6588ULL, 0x5D502033DB015632ULL, 
            0x4B09C41CD057A405ULL, 0xED3A7991CED11962ULL, 0x08D588B2F459F9A1ULL, 0x16A56D3EB865C576ULL, 
            0xBEF12BF7CF102D93ULL, 0xB64B43B6C4686172ULL, 0xCF7D6DBA7113D254ULL, 0x4279C93A16A20CEFULL, 
            0x8D9DFC5CC1B070E2ULL, 0xE2EF07A89597C158ULL, 0x724BDA429BB04B51ULL, 0xCAFFB1E8666FB0B6ULL, 
            0x5B2007913AE511D0ULL, 0x6BF2DAD1989E2B55ULL, 0x051768880FF95717ULL, 0xEE55C1800CC616FCULL, 
            0xAD0FA943809F3D37ULL, 0x3583CDE3CA079E94ULL, 0x1CA6A7CB201C5C12ULL, 0x6664E4D5BE655C39ULL, 
            0x559DC217649E4D32ULL, 0xFB6144878D7DA3C6ULL, 0x4AD17383886E4DD6ULL, 0x5D3680977D15D137ULL, 
            0xF2C11F049F89064FULL, 0x50CA3555133AF09FULL, 0x0E0888289CF68000ULL, 0x31EFA075CFADF676ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseGConstants = {
    0x10D2E85129BB4AB3ULL,
    0x18E2FC2F9EC3372EULL,
    0xF1DFAFFAA9D82C45ULL,
    0x10D2E85129BB4AB3ULL,
    0x18E2FC2F9EC3372EULL,
    0xF1DFAFFAA9D82C45ULL,
    0xE0978FB27CC0A586ULL,
    0x26582D53C0D0B346ULL,
    0x97,
    0x57,
    0xE9,
    0x44,
    0x96,
    0x7C,
    0x8C,
    0x51
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseHSalts = {
    {
        {
            0xE4978FAC49F47E96ULL, 0xC516EB92156457F9ULL, 0xB7A00B3E5B956691ULL, 0xCB4A05C0CE9BAE7DULL, 
            0xF0F6B7D9E8D8D8D7ULL, 0x123C44CFBB1F5EC8ULL, 0x568A8CFECD6DAEC4ULL, 0x5C73AECB8101DE39ULL, 
            0x232036ED030F1B63ULL, 0x82B90EEA36AA3270ULL, 0x041E8949E8893C87ULL, 0x898CECE9C24C5D18ULL, 
            0x6FBD567F7DE72D9AULL, 0x21330CA5BC3B62A0ULL, 0x7D4249FAB08FC21CULL, 0xC224DDC0913E4DA9ULL, 
            0x49E005F4766E6A80ULL, 0x543BF3800DD0CB42ULL, 0xF02F42EF97C203D2ULL, 0x5D400C687A030299ULL, 
            0xE64B45EAE822F685ULL, 0x3C2B70DF4FF8CB0DULL, 0x04706C54E8B9FDA3ULL, 0x06A0094D63EF064FULL, 
            0xBB689E22D3301146ULL, 0xEE6470F31D2A3DC7ULL, 0x5FDC172E781ED9D2ULL, 0xAD2B691E61868251ULL, 
            0x3847A5BA93E0FAB3ULL, 0x3CF738DF77F9741CULL, 0x7B4F63C647535836ULL, 0xFC84CF56BFB41A4BULL
        },
        {
            0xE7766A91CD9EF211ULL, 0xE6383CC82D55D9E0ULL, 0xECC6C37AA37325F2ULL, 0x958E61BCCAA99A09ULL, 
            0x7F919837368C1E3FULL, 0xC881C33F08566781ULL, 0x4CA855B76E9F2DE8ULL, 0x1E3C3ED0ECCD58B3ULL, 
            0x0A91A1EF795CFDCEULL, 0x9AA3971FBA48D45DULL, 0x6B66A2CA4A1713EEULL, 0xDD230DD49E1A0475ULL, 
            0x666E3D23EBA492BAULL, 0x948F5879F3C4CD27ULL, 0x05644A306601EF81ULL, 0x1BAD65D63F2AA292ULL, 
            0xA3A022B2AEC34C1EULL, 0xEB94871A2D57104CULL, 0x846B379FE3E2447FULL, 0x6ED4BD9F9875BC1AULL, 
            0x5504C3BB8873F0B2ULL, 0xF08E75319B394953ULL, 0x368322E4AEB70EDAULL, 0xF4926F3955331E1DULL, 
            0x0B45C5281B6D7518ULL, 0xAF12868B1DF312F8ULL, 0x3D1D2EC23E023BB2ULL, 0x7172426404442FC0ULL, 
            0x4CF7DE5CBECFD65AULL, 0xB57E431AC5D26555ULL, 0x2ED7B8CE2AB2A4E4ULL, 0x06759D63B45F5F69ULL
        },
        {
            0x1DCEA51CFC83A415ULL, 0x903BCE7D6F3BB722ULL, 0xEEBF947A12538861ULL, 0x574C2259B17B799BULL, 
            0xD8D45AA875C39804ULL, 0x281854183398DB39ULL, 0x76E764097ACDE0D2ULL, 0x89C54DCF39DF7673ULL, 
            0x793078D4F31692D8ULL, 0x5E94EAE1E861DA26ULL, 0xBE08B56CF488D0C7ULL, 0xFFB5C3183A2C7B8FULL, 
            0x8B084119DEF12A43ULL, 0xE54EA9E8D273B8E3ULL, 0x9CA02D5FDC37D831ULL, 0xA51772985D2F5693ULL, 
            0x46D3794AC15F5888ULL, 0x85E05ED869CC1E36ULL, 0xD5867F8F0CA4C2DBULL, 0xB7D1093FFEA47DB3ULL, 
            0x83CAF77755F04D2AULL, 0x52B76CD54033B226ULL, 0xEBE9FC8E8A59E542ULL, 0xA3B7C635BDA5FCD1ULL, 
            0x025836A78FE8C888ULL, 0x26813D35B4441C51ULL, 0xF28BBF8E8D343C62ULL, 0x606E5DBE9BBF1DE4ULL, 
            0x80DF392444F4541DULL, 0x2B93364EE0D647FAULL, 0x2D2B64E957E18A0AULL, 0xA4C662981D98EA25ULL
        },
        {
            0x0623D81F729B7DF1ULL, 0x1A4976CBD4F18BD9ULL, 0x97E0B43DE0DBDD7BULL, 0xB16AA001838BC600ULL, 
            0xE41252BB6EEA28C9ULL, 0x5BDC29A4D41D3C05ULL, 0xADDC1E838826220BULL, 0x9A317379D9BDC280ULL, 
            0x48B48D1B2AAA9D51ULL, 0x3DBB41E22DAA0786ULL, 0x2C4C986A66BE373FULL, 0x2E54A13AA6A6C932ULL, 
            0xF3FE40F6435F6555ULL, 0xC870C8A759FAE772ULL, 0x0CF321CF33507E0DULL, 0xDB7156756EA74098ULL, 
            0x078D1EDD0277B2BBULL, 0xA57D688205972052ULL, 0x92FD9DE2BF3D3ACCULL, 0xAA3270707A2F5471ULL, 
            0xC4793F7EFD0D2520ULL, 0x2BBC0162CA0C3493ULL, 0x38E7D63DD47EC678ULL, 0xEDCDDF50B048A9B7ULL, 
            0xBB27E199DAC4DA7EULL, 0x7CA89A8F618B7AD4ULL, 0xE5A63459EA19AC91ULL, 0xF8182F42ECBEF568ULL, 
            0x066E19799CE16A29ULL, 0xBD96B08743747E01ULL, 0xB3EFEDDD53EC57D5ULL, 0x01E00A89D090C261ULL
        },
        {
            0x872AF8F5EC68F4E1ULL, 0xB63BB0617794AFDCULL, 0xC8C21A82C47292C2ULL, 0xC67E2C369FE658BCULL, 
            0x01E1336AD06A2B53ULL, 0xA752D2C3CE69FDBDULL, 0x2755323584F6FDC8ULL, 0x333155FEA0057DF0ULL, 
            0x7B0D5474298E82BBULL, 0x4E251BEA597DB94DULL, 0x8E5134FFA583D670ULL, 0x5FEAA7DFAD5F6247ULL, 
            0x614E63CC32889B23ULL, 0xB1621F9E76F62EC8ULL, 0xD8EB75F1278895B2ULL, 0x048135390F318A70ULL, 
            0x22CAEB13ED6180CEULL, 0x019FCE70B21C2316ULL, 0x1F437DD2DCAEB086ULL, 0x91B5644A66C46CE9ULL, 
            0xB4BD3E8D408BDA7DULL, 0xD0FF9045DA8CC98BULL, 0x3B63A4B3C68CDA63ULL, 0x5D809F9E255CA7A0ULL, 
            0xC7E1A03A63FFBFAEULL, 0x0BBE0E57E806AF52ULL, 0x67490FA3EFA55CFDULL, 0x7B71AD826399ACDAULL, 
            0xFFD78F122C2994B6ULL, 0xE2D5B3B44D74921DULL, 0x13DB147A8B72E92AULL, 0x4BA5A165F8797393ULL
        },
        {
            0x0F0A778C19E6E053ULL, 0xB400F6FEAC78EFC0ULL, 0x37AF46B7F737BAF0ULL, 0x1E2ACFCE4742B56FULL, 
            0x3100EB87A5B5E620ULL, 0xF4247F4B9DEF65D2ULL, 0xEC84898E9BAA49E8ULL, 0xE25191430C8A9E0BULL, 
            0x9D6C7BCBA76A9EA9ULL, 0x20FD55433C99BB65ULL, 0xB8CA1762AF1725BBULL, 0xB2643479D2AD7599ULL, 
            0x4F84ABFC550B14D4ULL, 0x29256EE02BADEB76ULL, 0x3709A83083A9905EULL, 0xCFEA76A34591ADEBULL, 
            0x3DA4A4FCFDA74090ULL, 0x39097FC097AAA99AULL, 0x536BF4AA2A39673DULL, 0x7AA2ECEE5FE052BDULL, 
            0x7232856994EF91D2ULL, 0x6FF08682CE627CC6ULL, 0x422C15648ACA6369ULL, 0xBD5CBF0A89560564ULL, 
            0x1B10D3214330EB5CULL, 0x2213CE4276D36401ULL, 0x9805137CBB9569DBULL, 0x35D1D5EAC76CFF9BULL, 
            0x46E7226857B05406ULL, 0xACFCBE2940273301ULL, 0x212649BF78C28990ULL, 0x6BBFF054FA1AFD62ULL
        }
    },
    {
        {
            0xEE361B87432FC1BBULL, 0x828D927B857697EAULL, 0xE65744F98F2C87A6ULL, 0xAAC2163B3E5AEFFBULL, 
            0x5B3CCD72149D8169ULL, 0x7D545E38BA523112ULL, 0xF50295CD88D42E98ULL, 0xE4B6B12813A18296ULL, 
            0x373CFC037C44D161ULL, 0xB27A451B8617E82AULL, 0x822F62298E033A85ULL, 0xDAF3ADA49FFC557FULL, 
            0xE24B7448D5E7A47EULL, 0xA700FE584F7FF0B8ULL, 0x8D0713D493D53C5DULL, 0xBCA4166C76F30402ULL, 
            0xF5DFE39261357B47ULL, 0x4913FDA62BB5ABDEULL, 0xCFA2718464C6816AULL, 0x655EC89C82C28DC0ULL, 
            0xCB01B21C3EA32DBDULL, 0xEC363881359DBF7DULL, 0x890F93C354017469ULL, 0x7710161D33664D8CULL, 
            0x8E149015E1961D94ULL, 0x41EC58DDD44EF918ULL, 0x311C51314D1CBCB0ULL, 0x4DD69CF2E8925CB3ULL, 
            0x259B88DC0DFC561BULL, 0x7AA5EFCF0FE0EAACULL, 0x2DFE880663864AB7ULL, 0xD67A5F47E2D8564FULL
        },
        {
            0xD88FFAAAEAB34645ULL, 0xC326F09EB5065783ULL, 0x317021DE505BCD1EULL, 0xEDC4FBD8BD3D4501ULL, 
            0x2D1A7CCF5AEA21FEULL, 0x455DE84A1E085C4AULL, 0xCE605ADC0D695813ULL, 0xA1A0D43782BD65CAULL, 
            0xA8655B9B1F02E230ULL, 0xD848926C87A16D80ULL, 0xA94BF505FB52F7BBULL, 0x8C9950E3F6E06609ULL, 
            0x468A23FC04ED91F2ULL, 0x416D8C73AF0446FAULL, 0xF5864CD9B5198A7FULL, 0x6A0604D66961CC2CULL, 
            0x87AD3B7A1658CEE7ULL, 0xA5A636E78CD891E6ULL, 0xA70AAD334506C8FBULL, 0x2642D6A9D210ACA0ULL, 
            0x9E7A45EF1FAF932DULL, 0x9CB2DFC49AF087F6ULL, 0x2034D0EE3ADBF9B9ULL, 0x7B05CACA71400A7AULL, 
            0x9D9AA02E07F2CD75ULL, 0xBBA397505360FC67ULL, 0xD421D39685280793ULL, 0x2DA5C06E296CFE25ULL, 
            0xD00B0002FA66AF9DULL, 0x48A7FDACDAF58FEEULL, 0x940F6A3BD8439C91ULL, 0x177EC8B9A8F15CACULL
        },
        {
            0xC52A616BDD8C036CULL, 0xD95A9A56846D2961ULL, 0x5BED2A88D37467BCULL, 0x336B3E161FBE4CE3ULL, 
            0xC18FC6FB6923ABBCULL, 0x0A4193F03FC0978AULL, 0x887A0DB4B0CA5769ULL, 0x46618C5588668306ULL, 
            0x73F47D513CC4922AULL, 0x25D9361FB5509359ULL, 0xBF4FF381F8AAB5E8ULL, 0x311C2671CB0FD657ULL, 
            0x0861425D81778160ULL, 0xE28E3A3C0FFB5304ULL, 0x78AB2ABE667CA2DAULL, 0x65E2A8765290A2ECULL, 
            0x2B30FB4312D61D75ULL, 0xFAD12D5406420710ULL, 0xDE1CFAB2B40A2F29ULL, 0x70D61AB9D011A734ULL, 
            0xA507883328EA55D4ULL, 0x97E7F0AC0F97B187ULL, 0xD202603749B61E81ULL, 0xD0DED7B0E0DFD35FULL, 
            0x85B3B14D8E7AF4B1ULL, 0x5C5F0A85744FBDDCULL, 0x1A488EB3997BA4D7ULL, 0x0074E139EC0EA708ULL, 
            0x5F5B641F9F6B52F0ULL, 0x5C94C20CEE15843CULL, 0x30BC9B5A17715C01ULL, 0x005EB906FA27687AULL
        },
        {
            0x872D8DDE38D77EE6ULL, 0xB7708949C562A74BULL, 0xD01CA05158037F0DULL, 0x4CCED1F75EB6F027ULL, 
            0xD5E0EB9FC34E8377ULL, 0x3954C66448EFC4A9ULL, 0xDF20FC01A6D62A94ULL, 0x9631844F86EE7211ULL, 
            0xEEBC8CEEB8054F5CULL, 0x5CD5A105B9CD3FC1ULL, 0x4D8A3E9D2EEA6FC7ULL, 0x5AFE1F61C7F6CF7AULL, 
            0x62DCC248F26FE98EULL, 0x39E96FC095C7D9FAULL, 0xD1A7A968AD435E48ULL, 0x114DCBEE6B577875ULL, 
            0x072E2FCA803A4C1AULL, 0x30A5DC83F1186CFBULL, 0x611FB01258BB3FCAULL, 0x38686E8DA2210552ULL, 
            0x2FE9D7F156B1CF1FULL, 0x66CB887C2A927C89ULL, 0x32010734663BE1FBULL, 0xC5EC7920AE057FB1ULL, 
            0x18643B7D92590435ULL, 0xBDA5B31D0924AB60ULL, 0x290B8E002C955890ULL, 0x7AB4970FBA83137CULL, 
            0xB0C8440D605A792BULL, 0x8CB8173EDF1A23F5ULL, 0xC41C7EF40D90B754ULL, 0xC30C922A23808D6AULL
        },
        {
            0x86F6A56877694BFCULL, 0x098C232DF0380AC8ULL, 0x6BF1A31044D85DF4ULL, 0x350EF0E226FF97C6ULL, 
            0x53E97E06DAC5F23BULL, 0xD7FECC907A9D9D0AULL, 0x8C978F523AEA4D36ULL, 0x37E86A5710A474BAULL, 
            0x7DC25FB9CFC93469ULL, 0xBEA1B4470A98DE23ULL, 0xAF6E5B926E757028ULL, 0x912E18D4C9598AC4ULL, 
            0x66B5FEFBAA2D834BULL, 0x4FD084FDC905DAA3ULL, 0x994E4AFF00ABF1FBULL, 0x844815113A342CA6ULL, 
            0x85C64364E9032027ULL, 0x5D6C455CE4D77FBAULL, 0x94CF367FA12B7B91ULL, 0x96CE61829A193C05ULL, 
            0x4820C2DC4DB5ED8BULL, 0x8FDFFA1612671DD1ULL, 0x8665A4870CA2058BULL, 0x6166BAE50A35935EULL, 
            0x6E55623DEDCCD75CULL, 0xC87FD906A31EDFF0ULL, 0x321DB30DB11C6EFAULL, 0x8FD90904FF90F2F4ULL, 
            0xC5976E18AD7B5069ULL, 0x04359B3BABA83797ULL, 0x2AAD9BCC39FAB4D8ULL, 0x5EEAE107B5526DA6ULL
        },
        {
            0x7E1652AA990898E0ULL, 0x5A9EFF88B72E4140ULL, 0x2F1CBECF7008BF9EULL, 0x06583FE8E8784B1FULL, 
            0x728E0C0248E7E742ULL, 0x7DCB6C7866081FC0ULL, 0xB47709351FC62529ULL, 0x8D9B35B61EE9D297ULL, 
            0x66E06B157796E17BULL, 0x0BE31891117E31E1ULL, 0x397DAC975799EE96ULL, 0x06A41A116CC72A2AULL, 
            0xE82603834F7B9BCEULL, 0xDC9CC65669E05037ULL, 0x5E006D5993173DD7ULL, 0x880BD88A4580CAD6ULL, 
            0x00FAC51267A26101ULL, 0x53BEBDE44D7C24A3ULL, 0x04F1DC3919A5FC31ULL, 0x52206397F972BFF3ULL, 
            0xDD5C388F3D55B300ULL, 0xAE280B418DCD6468ULL, 0xBEB3009E30E5CBCFULL, 0x8549D1CC7E6F8C7AULL, 
            0x76C8A045427C2D77ULL, 0xD716C9D58D4B0B56ULL, 0x559A4C52148BF7B6ULL, 0xE811F6D0CBFDE754ULL, 
            0x95E011E61B80A163ULL, 0xB1BFADD3C9B4DACBULL, 0xF535820334B1B305ULL, 0xA385D574EA9A5DCAULL
        }
    },
    {
        {
            0xEF2FB30D568F3814ULL, 0xB16C5E21BF4DB337ULL, 0xC3C57455BF422565ULL, 0x7D50FB0E7E9E6AA4ULL, 
            0x51E179E0A5B7EB4FULL, 0xDA290F7D26CBE3B9ULL, 0x63F53725F52EC545ULL, 0x97552ADCED614B51ULL, 
            0x4F4C626BAB163E8CULL, 0xC4EBADDA41A3D642ULL, 0xF68D212DF91A5D4FULL, 0x890B1F3543FD8237ULL, 
            0x5918A55D58C99517ULL, 0x12F62861C696870FULL, 0xFE805162EB95D11DULL, 0x9FB1BFC7EA32AB49ULL, 
            0x4333792A391B123BULL, 0xFBE6B5F08DBE48C9ULL, 0x3B56EA6F5E6F102EULL, 0x872A462BE27AD6A3ULL, 
            0x04BD43CF4EA61DB5ULL, 0xB71E8481387E44DDULL, 0xF537EAF48F68CFC1ULL, 0xC4D9A9F29267787FULL, 
            0x599BAAC054E473A8ULL, 0xFECCB0A0F47B4025ULL, 0xBFD73C72C6F40AFBULL, 0x0A6C1B769A4BB19AULL, 
            0x714FAF9421C3EA58ULL, 0xEEE7426B0CC3927CULL, 0x7D48A363953B1A0EULL, 0x242CFACDCB26FD99ULL
        },
        {
            0x3EE71FDB8E45084CULL, 0xF2CA1BA6D6EEDDD1ULL, 0xD6B4947C3BBCC10DULL, 0x160824333785BA54ULL, 
            0xD62AF7B17249EE9CULL, 0x18DA9F956D3C45ECULL, 0xEECEC59A6D70BDADULL, 0x11B9AEF5F9D41F3CULL, 
            0xFCA1FDC9DE8D2C21ULL, 0x48DB4205A9365400ULL, 0x3DE8C42D905E3A05ULL, 0x113B51A238FC2D0EULL, 
            0xFEEB831EF09D5048ULL, 0x957AE6267E25AE77ULL, 0x1235C17CD6B14963ULL, 0x7E5E375A34146600ULL, 
            0x6C3552470EE5733AULL, 0x987887334D08B58BULL, 0x39F433C08FB87D51ULL, 0x3DBA977F458235B4ULL, 
            0x1EE00CA79448B807ULL, 0xAB1150E2BEDD0214ULL, 0x814C756B4B76F6B6ULL, 0xE14B6A479BFAC978ULL, 
            0x68FE0AEF2E5BC59CULL, 0xFE30C659937E2488ULL, 0x2EA5B88D860E0222ULL, 0x017225C711C2857AULL, 
            0xF0BFAC12F51D6D18ULL, 0xB2B1822D188F7FF3ULL, 0x1C5D0F891D26CC0AULL, 0x8397C655EC69C049ULL
        },
        {
            0x52BB8DBB0A920B7EULL, 0x4163716AB38C3C9BULL, 0x59CE153A4BCE4E4FULL, 0xC6613B77C018BBD5ULL, 
            0x380E7FD4F7EA63E4ULL, 0x773DC06225186342ULL, 0x6FF9C08DA404224DULL, 0x28F42E33E9359DC2ULL, 
            0x62B8DC0537104952ULL, 0x175B9E3B83A62DBDULL, 0xF2ED93EB22623552ULL, 0x4577B80C0739381FULL, 
            0xAA72F00A0A97C7B3ULL, 0x5A3BB190BC40B1F8ULL, 0xFCF0FA3FAEC4AFF4ULL, 0xB52A172960055517ULL, 
            0xA175D26C1AAE082EULL, 0x68DD36BB6F5822E6ULL, 0x178A75A28B6F607CULL, 0xD915FC512BD53201ULL, 
            0x1C42F6B393BCAC9CULL, 0x13FEA94AB08D69FEULL, 0x88979D4DA8F43C85ULL, 0x2072D5FEC7C67B14ULL, 
            0x4A9301690C8B4B18ULL, 0xD0D9C7D98F311FD2ULL, 0xDEF6C14B049823FEULL, 0xA8EA14A3271208EDULL, 
            0xB8ABB3BDF0C6071CULL, 0x65480CABE8421A66ULL, 0x8687739EE9FEFA78ULL, 0xE7B683F12A2E495AULL
        },
        {
            0x7B9BB31D94785B0BULL, 0xDD43A59FF200FA5FULL, 0x0B69AE51D3E16448ULL, 0x983C7AB764FD02CBULL, 
            0x04AE36188F94184EULL, 0x176BFDABDAFC1E50ULL, 0x0B5706D7AB3B12B6ULL, 0x5B52F752850DD94CULL, 
            0xC40EF07BFDD1F9ABULL, 0xBFED984C0DBF0D72ULL, 0x06B67FCF7A643095ULL, 0x6F36C4F6FFADEA9EULL, 
            0x545601FD7CE5B2F4ULL, 0xC454C242B43D0269ULL, 0xA1C7D3C632440197ULL, 0x75CBAA762318F30BULL, 
            0x04B16A49F8D0D6FCULL, 0x45F92EDB6C09DA3DULL, 0x6E24767B57749314ULL, 0x096AB04BF67BFF66ULL, 
            0x31220992CBBB0735ULL, 0x7CD91251A9043629ULL, 0x6E82C8709172DED0ULL, 0x59A0E23E62F05D1FULL, 
            0x900E644107DF9F45ULL, 0x3A4E0C6977D08B9DULL, 0x75169A87F5FC4E03ULL, 0xB097039AC2ED3714ULL, 
            0x9AA475DFE2BE2E06ULL, 0x4EF3AB09EB3E9792ULL, 0xA271B1613E9E3D0EULL, 0x46957EA950B4BBBFULL
        },
        {
            0x4A0A98A3F83CC375ULL, 0xBA3B20CA20DA629BULL, 0x838A0B1AE23ADA49ULL, 0xD7F05D41832920B9ULL, 
            0x53FC34E280954406ULL, 0x3092F36053B82F5FULL, 0x5888EA1AC464C7A1ULL, 0xB1004B55CD3AEE09ULL, 
            0x4D317C1C6B97FA29ULL, 0xCF0484DEA702D5E7ULL, 0xE067344E0E759714ULL, 0x753EA79D691918D8ULL, 
            0xB72F9A33AE417BA2ULL, 0x5BF77C7ABEF1B6A0ULL, 0xD5A9FDA5EDA9C7DCULL, 0x31D544B1CD2AA3EEULL, 
            0xE5A8A6C5A9E11B71ULL, 0xA3B9BCD50E52B6FBULL, 0xB03F2D341D15C27FULL, 0x1961B1C6BE77C61AULL, 
            0x63F7B116B7091832ULL, 0xE34BE1B96462D114ULL, 0x5070FF945CED7C11ULL, 0x7C1245D3DDAE47EEULL, 
            0x5015070A16A2CEB1ULL, 0x35ED1EE10C203A87ULL, 0xD8A9C4BFF409423CULL, 0x0074AAC3C4BA1B9AULL, 
            0x8AC3BF6D9FCB734AULL, 0x3DA77EEFF86BDBB5ULL, 0xBCA763E4BDDCCC2AULL, 0x45528DC8BE84EB94ULL
        },
        {
            0x46A240A69F75162CULL, 0x6FD67BCE7893E817ULL, 0x54BD149ECD27EDEAULL, 0x5F3FF1EAB7E9E8ABULL, 
            0xCF30956E5C6C3004ULL, 0x80F4337C34DF9112ULL, 0x170984DC5EB4E127ULL, 0x79F81328075FAB9DULL, 
            0x367D104A2DE65940ULL, 0xC6FFCBB7C4E2687EULL, 0x40523D7D7EA8FE76ULL, 0xFB52511CE81028BAULL, 
            0x50B49377C294FD36ULL, 0x77EB42D786707CC4ULL, 0xC4B13A07DE8AE851ULL, 0x824713C01BADB77FULL, 
            0x9DDEBC74B263D3DBULL, 0x20E8114F32C360A7ULL, 0xF6DA4F33B5F7B28EULL, 0xCA3F1D5887F05EE5ULL, 
            0x4D10FA50F61E6F68ULL, 0x5C5777946C8B0DC0ULL, 0x7D669907B879920FULL, 0x0E07F09AD182D920ULL, 
            0x91F7313EDCACB747ULL, 0xB1ADB8D141EC47D1ULL, 0x9F53CAF02F50A8F2ULL, 0x6B6F7AD2E2D06C9FULL, 
            0x36E76D0D9AD73AEBULL, 0x4C27654F9A7D684AULL, 0x971A91AEDE6472CCULL, 0x006C11710EB4B17AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseHConstants = {
    0xAB8919672C287DABULL,
    0x1424D2704DEF0643ULL,
    0x1F69DAA7A299618DULL,
    0xAB8919672C287DABULL,
    0x1424D2704DEF0643ULL,
    0x1F69DAA7A299618DULL,
    0x9C32AE53827ACF89ULL,
    0x13FAB906F7813B38ULL,
    0x05,
    0xD1,
    0xD0,
    0xB4,
    0x32,
    0x1B,
    0xB6,
    0x40
};

