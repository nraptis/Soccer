#include "TwistExpander_Tennis.hpp"
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

TwistExpander_Tennis::TwistExpander_Tennis()
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

void TwistExpander_Tennis::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 17611647837919358009U;
        aCarry = 13495887179668073524U;
        aWandererA = 18251579572064913577U;
        aWandererB = 11274206051535672792U;
        aWandererC = 16175959090706550015U;
        aWandererD = 14294783597586212768U;
        aWandererE = 18398221513381890536U;
        aWandererF = 9662999896541455215U;
        aWandererG = 17493946650111375844U;
        aWandererH = 9228276157502032282U;
        aWandererI = 15970365058463550899U;
        aWandererJ = 15519419727272538257U;
        aWandererK = 12648748728207021846U;
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
    TwistExpander_Tennis_Arx aArx;
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
    TwistExpander_Tennis_Arx aKDF_A_BArx;
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
    TwistExpander_Tennis_Arx aKDF_A_CArx;
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
    TwistExpander_Tennis_Arx aKDF_A_DArx;
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

void TwistExpander_Tennis::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 15527181384701693855U;
        aCarry = 17119959959035245832U;
        aWandererA = 11267492676007505952U;
        aWandererB = 11861467189413277678U;
        aWandererC = 10275315497794178494U;
        aWandererD = 10939530045699215630U;
        aWandererE = 9534197818450782990U;
        aWandererF = 11926778266061211614U;
        aWandererG = 10510627769268585862U;
        aWandererH = 16623284927377092834U;
        aWandererI = 17457155386488767097U;
        aWandererJ = 11342560911360842906U;
        aWandererK = 16167387983994128296U;
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
    TwistExpander_Tennis_Arx aKDF_B_AArx;
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
    TwistExpander_Tennis_Arx aKDF_B_BArx;
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
    TwistExpander_Tennis_Arx aKDF_B_CArx;
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

void TwistExpander_Tennis::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneB);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneB (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseA invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    }
    // KDF_B PhaseB invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneH);
    }
    // KDF_B PhaseC invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneF);
    }
    // KDF_B PhaseD invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneE);
    }
    // KDF_B PhaseE invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    }
    // KDF_B PhaseF invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneA);
    }
    // KDF_B PhaseG invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneD (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneD);
    }
    // KDF_B PhaseH invest aInvestLaneD (end)
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
    TwistExpander_Tennis_Arx aSeed_AArx;
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
    TwistExpander_Tennis_Arx aSeed_BArx;
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
    TwistExpander_Tennis_Arx aSeed_CArx;
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
    TwistExpander_Tennis_Arx aSeed_DArx;
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
    TwistExpander_Tennis_Arx aSeed_EArx;
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
    TwistExpander_Tennis_Arx aSeed_FArx;
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
    TwistExpander_Tennis_Arx aSeed_GArx;
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
    TwistExpander_Tennis_Arx aGrow_AArx;
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
    TwistExpander_Tennis_Arx aGrow_BArx;
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

void TwistExpander_Tennis::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Tennis::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Tennis_Arx aTwist_AArx;
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
    TwistExpander_Tennis_Arx aTwist_BArx;
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
    TwistExpander_Tennis_Arx aTwist_CArx;
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
    TwistExpander_Tennis_Arx aTwist_DArx;
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
        TwistExpander_Tennis_Arx aGrow_AArx;
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
        TwistExpander_Tennis_Arx aGrow_BArx;
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

void TwistExpander_Tennis::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 2 with offsets 7384U, 2398U, 6170U, 1011U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7384U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2398U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6170U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1011U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 0 with offsets 6097U, 183U, 7656U, 7620U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6097U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 183U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7656U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7620U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 1 with offsets 3791U, 6047U, 3219U, 7488U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3791U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6047U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3219U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7488U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 1, 3 with offsets 7337U, 4422U, 2977U, 1622U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7337U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4422U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2977U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1622U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 1576U, 594U, 782U, 1515U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1576U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 594U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 782U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1515U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 0, 3 with offsets 1986U, 1359U, 275U, 654U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1986U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1359U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 275U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 654U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 3, 0 with offsets 1594U, 868U, 628U, 497U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1594U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 868U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 628U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 497U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 1, 3 with offsets 1873U, 1654U, 1847U, 1738U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1873U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1654U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1847U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1738U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 165U, 1611U, 344U, 1961U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 165U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1611U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 344U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1961U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Tennis::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 3 with offsets 6097U, 5949U, 6544U, 2778U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6097U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5949U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6544U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2778U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 2 with offsets 62U, 6507U, 1934U, 7671U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 62U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6507U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1934U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7671U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 1 with offsets 3215U, 7603U, 6336U, 5513U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3215U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7603U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6336U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5513U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 1, 0 with offsets 5830U, 1127U, 5687U, 2762U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5830U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1127U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5687U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2762U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2568U, 2602U, 5058U, 1974U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2568U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2602U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5058U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1974U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 0, 1 with offsets 1602U, 1789U, 148U, 1242U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1602U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1789U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 148U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1242U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 2, 3 with offsets 829U, 917U, 1266U, 1560U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 829U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 917U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1266U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1560U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 1, 0 with offsets 391U, 1636U, 87U, 760U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 391U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1636U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 87U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 760U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 1, 2 with offsets 1150U, 1515U, 1981U, 1017U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1515U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1981U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1017U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 726U, 1963U, 1677U, 2037U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 726U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1963U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1677U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2037U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseASalts = {
    {
        {
            0x7EFA50220545D153ULL, 0x84E422C8132094B3ULL, 0x75593107BC1F33E0ULL, 0xC9F7651CE1F92962ULL, 
            0xC908A2CAE1313F47ULL, 0x8D88B1A76CA2C8F0ULL, 0x804B63E8EFEF04D6ULL, 0xC9C753ED2B4A14F5ULL, 
            0xB0F79F02C5EFE6B2ULL, 0x91D25AD784AB23AFULL, 0x46B5268A764F0814ULL, 0xD224E90DBE841756ULL, 
            0xC416071057F6519AULL, 0xF9A75933E4934FBBULL, 0x4385DA8F87CD2958ULL, 0x4B7A7AE3EEDBF104ULL, 
            0x021798BCD8F443FEULL, 0xA753B67BEFBC851BULL, 0x21CC6A29219D58ADULL, 0x123752FE7591FA3BULL, 
            0x1269A0BE41AD8A50ULL, 0x6EFAF3C9373B664BULL, 0x7ED03151AFBEBC7AULL, 0x5BD765EC9DE32BACULL, 
            0x001DB41BD19588E1ULL, 0xADE263AC95FC5428ULL, 0xB2AC1F1283780FC9ULL, 0x9CD76BAE7806011DULL, 
            0xB8920BA0EF5044BBULL, 0xE290BB8F86FFD1D4ULL, 0x339C7B0C20435D7AULL, 0x0E24AA1BEFEAF4EBULL
        },
        {
            0x2D43831480DD5CECULL, 0x75EE3F0D82BB457FULL, 0x813AC23DF9C1AA8BULL, 0x182E7B678AD5AB38ULL, 
            0x39FE8072D88A3DE6ULL, 0xDF2E22818F04B53DULL, 0x0D8A0E5ABCFBE402ULL, 0x505D775A24DFDC95ULL, 
            0xBAA310D04EAF5C6FULL, 0x066DF124E0522C26ULL, 0xD5A071C217A42FC5ULL, 0x9AA54704A89BDDF3ULL, 
            0x643AB0ECF80B60BBULL, 0x35A6451B602FDF63ULL, 0x5B2BF0C74883DD83ULL, 0x493C7675FD54BC14ULL, 
            0x2B0FCCFEAEF646AEULL, 0x85E774895D96059DULL, 0xC6B72466D61E4ABCULL, 0xBA3A59EB18967D9BULL, 
            0xA40775A9A8F6317CULL, 0xE068EEF63F37B02BULL, 0xD520F006227F4C98ULL, 0x5DFCAAF527240337ULL, 
            0xBE1A4CF20782D254ULL, 0x61183BC04201A07EULL, 0x4A6053C9091B7D5DULL, 0x2E3031A28366243BULL, 
            0x0C2E74731E1435EFULL, 0x9825A8953F599B26ULL, 0x1B51C54D9C095AAAULL, 0x900226356A06F22CULL
        },
        {
            0x42B5CE0818885F07ULL, 0xFAFFC2F96911D547ULL, 0x833D72FC9DE66B25ULL, 0x0135C1EB864A2F4EULL, 
            0x9775F87F68A9C3BFULL, 0x92F2B39E8A821C79ULL, 0x42F84C02490EC754ULL, 0xDDEE3AB1F95E6971ULL, 
            0x91D006C62C4CFAD5ULL, 0x31C54F2B2D0F270EULL, 0x185F6191C3F62A2DULL, 0x0D2562E175E03736ULL, 
            0xFA9EAC75C93DA479ULL, 0x51D6C5B866861A11ULL, 0x5254BF6513C5EBFCULL, 0x4466B84FDA918B81ULL, 
            0x6900E343FA506286ULL, 0x0066DC335006C6D4ULL, 0xBDAD067AE55F2F2CULL, 0x11D204C1BE8BC8D1ULL, 
            0x2B327A8EC10234AEULL, 0xF8FBA3CE914DB8B6ULL, 0xC7FE315B911348FEULL, 0x58D531A25E2B6A9FULL, 
            0xB8F3723C85D182B1ULL, 0x0A9B6B02CB908078ULL, 0x1BA1C902695B5129ULL, 0x23B09C2B264D2153ULL, 
            0x44355529D11D3CC7ULL, 0x3ABED2A39DA1DC55ULL, 0xDEF11CAF40C17CBAULL, 0xA8A69DDB31F88BE8ULL
        },
        {
            0xEE105A6417903259ULL, 0x3D5D6F9D6A83A142ULL, 0x3F366AD8E68C72F9ULL, 0x130016CA0FE6D3F3ULL, 
            0xB2F70F49B058A3D1ULL, 0x7EDE38CD1B7F85BDULL, 0x4D4DB25BB3176725ULL, 0x4E3F8AE7960995E8ULL, 
            0x873446BA6A1DE3B6ULL, 0x5B4EB26B7A54CA80ULL, 0x4790E0254ABD9A85ULL, 0x534CB062943FF8A1ULL, 
            0x39AAA6BEFB32C03FULL, 0xAFCAC87456126522ULL, 0xA3BADA74EA05285DULL, 0xAB0A069AEB25DD8EULL, 
            0x676375E0E8371B76ULL, 0xFEC2F37A34100C81ULL, 0xDD61966EA9A6BD63ULL, 0x6578E5390120E7D2ULL, 
            0xD205B9BAC0311C25ULL, 0xB19962BC4E27E736ULL, 0x145E2A001DD805AFULL, 0x7335E6203DBE3DC4ULL, 
            0x46D01D1141CB5626ULL, 0x09149557DEEAAB16ULL, 0xB661A26A89321BCCULL, 0xADD3EE984558CF21ULL, 
            0xF01258388FF2F786ULL, 0x791AD6212217CE52ULL, 0xF91135DFB4878C76ULL, 0xDC96B882291100CAULL
        },
        {
            0x1012B123D2C37D81ULL, 0xBB2267764F3E53B4ULL, 0xC413BED3656EF7CEULL, 0x49C3BD5326EBD725ULL, 
            0xB8220621567354BBULL, 0x50C1EDF86AA7F78BULL, 0x2CAC43B75DA77B75ULL, 0x8FDBCFC6AB975CE5ULL, 
            0x7488A0ECDB618340ULL, 0x4E26A07EA1C9FCB0ULL, 0xD56562E428B0F718ULL, 0x0E6D1E3C9EE30B00ULL, 
            0x153D1A975EB7150CULL, 0x8933B0099581AE00ULL, 0xC29E6E83AC9485C3ULL, 0x2CBD2F9DFE46873AULL, 
            0xE54FAD69CC5F9086ULL, 0x94CD636F1563A2A3ULL, 0xAC618A165DC7B58FULL, 0xD75D7BB016906FADULL, 
            0x3DE6732F9279438AULL, 0xF8A09E5AAA41454AULL, 0xA6CD647B0BB4BFC8ULL, 0x58D6093F2D17D54CULL, 
            0x4845242E545C4A96ULL, 0x38232074AEB92D34ULL, 0x77804EC45C2F0756ULL, 0x3524CF566DC7B4A2ULL, 
            0x5FDE22EB676EC22CULL, 0xB6D2002E9243E9CCULL, 0xFA11F1E53469CC23ULL, 0x44DC4CA5B5E4DE6DULL
        },
        {
            0x3112F16CA3507EAAULL, 0xD280E69654F56108ULL, 0xD837C654CBEB6461ULL, 0xA2592CB8F9BA441DULL, 
            0xE345C8E098CBDED2ULL, 0x0893CFFE08AC0D3CULL, 0xEAA6C3E7FADE3266ULL, 0x6994048B066FD5CFULL, 
            0x851FE2D9A1B37F45ULL, 0x6E49F44BCEA20A39ULL, 0x6539AE28D860D7A3ULL, 0x0B8069599FD6EA6DULL, 
            0xFF798CA1B8287BD4ULL, 0xAD6CB9230D057D00ULL, 0x33A68CBA1758A041ULL, 0x68778E58A9472536ULL, 
            0xE0977D8D0D3E1BBDULL, 0xD284AA38B4717000ULL, 0x7579FEBCA19B436DULL, 0x4EA0B641ED4BC87FULL, 
            0x49A160EDB04C38F4ULL, 0xE8BA2F8B9C73BD18ULL, 0xEFA5C6731BCA64D8ULL, 0xC85F1A055C30F6C9ULL, 
            0x6A0E45B84C008E75ULL, 0x5EB3C211BFFA2053ULL, 0xCDBB1ED0100FDE71ULL, 0x66374762BC3D717CULL, 
            0x3522415F8CDDC865ULL, 0x48F6733B36314D32ULL, 0x3A0B8A5A41882CADULL, 0xBAE09B3CC9AEBEFCULL
        }
    },
    {
        {
            0x9D3D821CAA42DC7BULL, 0x79BD113C65725321ULL, 0x2E6CB5BE362B7D88ULL, 0xF867B1E7040AEF32ULL, 
            0x86D9E462F8446792ULL, 0xB1810F3B2FB83BBDULL, 0xBBE9905A8817461BULL, 0x35D74234E497C794ULL, 
            0xD1AE69B685762DC9ULL, 0x5090AA1214C639AEULL, 0x6A669EA645675395ULL, 0x333C4114B403B5C8ULL, 
            0x546F12ACA7146E2BULL, 0x6F40F7F1D86E1856ULL, 0x7C34AE1E11241EADULL, 0x6E82DE4C810A9D9FULL, 
            0x40F446ED0F4A4669ULL, 0x828F70D0642FC426ULL, 0x31A0F08AA9037BB4ULL, 0xA33A2CF2367D05A6ULL, 
            0x6932B1D8F6AB4DDFULL, 0x8905F762B61FD156ULL, 0xE614E19DB5AA5A72ULL, 0xF4DF2E95866B94FBULL, 
            0xA84EAD134446A63FULL, 0x7BFC966E823B5BE3ULL, 0xC0EC1F9F3EE0E3FBULL, 0xBAEE7CBD01492EA2ULL, 
            0x2A18B0734F66660BULL, 0xB5EE6BF37EFFED8BULL, 0x41E47D0E3AC2A22BULL, 0x5D39E0858870B75BULL
        },
        {
            0x683A2643F2FB103DULL, 0x68B7BBFEA759B36DULL, 0xF67D4E36BC3A87D5ULL, 0x428CEEE751E8BD0AULL, 
            0x9E7B72187D45E0C1ULL, 0x01955FC6211874BBULL, 0xD94287AF76CFAB99ULL, 0x25968A64BD81CE4FULL, 
            0x553FA9BEEF44FCA0ULL, 0x22467E13778FE66EULL, 0xD2FF499E023061C0ULL, 0x0CD659814F06D976ULL, 
            0x5A59F2FE5C39CA19ULL, 0x09EA477E8767AAC2ULL, 0x6BF85F98C24AC6A8ULL, 0x2B2682A690DFD01FULL, 
            0x2E25A605B22BE0E7ULL, 0xA511B5088516A760ULL, 0x5118B034A252160FULL, 0x1029EAB58099A4C5ULL, 
            0xF5D79A13F76D1288ULL, 0xD4DF193E22335D4EULL, 0x73713E3455313262ULL, 0xFF488C8A4B5B13E5ULL, 
            0x93FDBA5ED6EEF573ULL, 0xD130DB3607D57442ULL, 0x3D6C240F7DDCBDE0ULL, 0x6FF2719D1A912F75ULL, 
            0x76E2ADB5CB6F5952ULL, 0x438787D88C424257ULL, 0x6E828BB72161E93DULL, 0x9E95C462C9C85FDAULL
        },
        {
            0x73629AEDDEF19A98ULL, 0x8FB90D44FAAE120DULL, 0x60DE9495D5010AA0ULL, 0x830FC7011441D427ULL, 
            0x6FF52ECA314D9F8FULL, 0x0D2C1A0C70883ECDULL, 0x2C37137E731D413AULL, 0xF60A552D05DB1282ULL, 
            0xF8BCC6D6037FE278ULL, 0x895D73B61EAF9382ULL, 0xC5FFD937C78D8E08ULL, 0x2C4BB881E02E55D2ULL, 
            0x543D975223F34224ULL, 0x4AEB795667C02E46ULL, 0x44017398704F93F5ULL, 0x5DAFF2E77463DF8EULL, 
            0x446A65D4985F1196ULL, 0xB9678A13875482D9ULL, 0x2743809F5AA76527ULL, 0x323E415DA75ED4AAULL, 
            0x67543DAA4AD99730ULL, 0x655157BF3E878A85ULL, 0xF71C0E6F1C8FAC43ULL, 0x00E13E7061C4396BULL, 
            0xD8194FBAB4221576ULL, 0x05BF4039B4D97C9BULL, 0xB04476E88D791DE4ULL, 0x1A3E9BE035E26BC7ULL, 
            0xC37A11D6A0025104ULL, 0x060D72902F5BC408ULL, 0x25226C26931E73EFULL, 0xC5FBCCC4059CC8BBULL
        },
        {
            0xDD7269036F45533AULL, 0x9FFC38C1F7FBF6FDULL, 0x461BD9D30BAE6B3BULL, 0xF4811DB9CA98E3D3ULL, 
            0x80ECC2B5D38FF2E4ULL, 0x97AF6721BCCE4186ULL, 0xC2EF582DE2A25E94ULL, 0x324D51E4546E4C6CULL, 
            0x9D1ED10EBFB601F2ULL, 0xDAFB1BE4F6C3C170ULL, 0x393133FC25D4E3CFULL, 0x6BC4FCD67C51C9CDULL, 
            0x1F063E56B1437ADFULL, 0xF88B8F75507D7B12ULL, 0x8728A262F6A5B19BULL, 0x522B3A9E847B66ACULL, 
            0xE1F472AEC6DC40FBULL, 0xE03DCDAC967B9F00ULL, 0x955501CA52D1A75CULL, 0x78A70ACE65C0DAC7ULL, 
            0x58640085FF816E5EULL, 0x94368574D8E67423ULL, 0xCAC1A5883B5556BAULL, 0x35AD79414D2D6501ULL, 
            0xF5F742BA293C3E04ULL, 0xD2487F671FEC8CC6ULL, 0xC67D6E139A161AE4ULL, 0x08BD07FB3E28BDC4ULL, 
            0x6B849F9E2459505AULL, 0x67ACBE0F683E68FFULL, 0x841742675F21A8DBULL, 0x07D41CA526722A0EULL
        },
        {
            0x171D785933E94BDBULL, 0xB9A4BD87447DC6AEULL, 0xAB382F0624251742ULL, 0x366A244D5F4C0972ULL, 
            0xFAC4307B86F23A49ULL, 0x35B8DFA4A72C6C43ULL, 0x273544757EDF8D25ULL, 0x1E9C6D67DE652360ULL, 
            0x33D9DB7ECE5FFE06ULL, 0xBE02CC24DCEAA981ULL, 0xA94D2D27D431F414ULL, 0xF45AD21E85AB9B6DULL, 
            0x9D8A910FC59EF2C1ULL, 0x31B17ECE2F59521DULL, 0x74D3D539A534C6A6ULL, 0xC6EBBE4C4B477DF8ULL, 
            0x971865D3F998D861ULL, 0x24257B2861F2D7DEULL, 0xA2F93D7503358280ULL, 0x7DA2611B6E6C5F5BULL, 
            0x00D7662E4FFC212BULL, 0xB319912DB39199A0ULL, 0x5275B9907433921CULL, 0x01F7F773884F67FDULL, 
            0xE7F6752DACFC0187ULL, 0xAF6F841A0B258AEBULL, 0x8110D55C8EB7A7D9ULL, 0xADBD31671B881DCBULL, 
            0x87B3D8151A75DFB3ULL, 0xA177EECBBEFAC91DULL, 0x7AC49AE8BB9B2FCBULL, 0x266B015FEFCBEDC2ULL
        },
        {
            0x6CE0C311613E9C02ULL, 0x966466174E388F51ULL, 0x2FA6F45D031338F4ULL, 0xF4A32DFDB2E9B013ULL, 
            0x63D48B695CD5A7BBULL, 0x765BF79ECE714C92ULL, 0x1895FA26F9FFDB96ULL, 0x366DEAE4C941591EULL, 
            0x788298E751BE08A8ULL, 0x86E593712E41232BULL, 0x869A2F1FC17AD22CULL, 0xF6187704BB7DC705ULL, 
            0x929F8BE00D215BF7ULL, 0xD5EA919FA0E3E7F9ULL, 0x331DE511BFE77676ULL, 0x9417C826EA66DD40ULL, 
            0xFD73DF5410D5588FULL, 0xCF0A0711A2368DD4ULL, 0xC8E4D56BF4B9D55FULL, 0x51905AC45748C433ULL, 
            0x87FC408BD9FB25E7ULL, 0xD57FDF0DF9D8CAD6ULL, 0x22114684DDBAA49AULL, 0x1743B3BB6F43E9F1ULL, 
            0x0DA12D666814FD3EULL, 0xE2ABD11FC7A4CECDULL, 0x1BA72DC8C0B8EFC0ULL, 0xC7C00BDBCDC64218ULL, 
            0x506B40D7ADE1651CULL, 0xCCB8201970A9D528ULL, 0xCAB2A9D6B72AF1A6ULL, 0xC7692CD860A87517ULL
        }
    },
    {
        {
            0xD04B385A211F929BULL, 0x86908EE5546EC65DULL, 0x5E6E2CD09260E64EULL, 0x2EA9CEED0C633954ULL, 
            0x572F72004A7D92F6ULL, 0xBA43735028974ED4ULL, 0xB781D9ED4CA63245ULL, 0x83BA209FBF63487BULL, 
            0x52A0B784014BFDF9ULL, 0x47B0F8A51D21F78BULL, 0xAF867356564583ADULL, 0x5FBF1B66AF9444AAULL, 
            0x3EF8B64608EB3711ULL, 0x53CF1569C70E7593ULL, 0x27620F9351B0785CULL, 0xAFD931766CC3DEB2ULL, 
            0x47E55F93C1611F0AULL, 0x03586B10FCEF091DULL, 0x8BF0FFD47485CECEULL, 0xEE0D9B269515703DULL, 
            0x5D51C78687E21745ULL, 0xE10B06BF2CA20983ULL, 0x8DF1119F3E5C3289ULL, 0x63D168A91BD84890ULL, 
            0x1BEBB9FD5AB1D13FULL, 0x116778475DD2C788ULL, 0x23CC6AFCC92801C6ULL, 0x0BC6F121D64F5B8DULL, 
            0xD858334868C0BBEFULL, 0xBDD6F360DFC564FDULL, 0x4704CDC74AD41CB7ULL, 0xD3BA9BF898856EAEULL
        },
        {
            0x8972B0BE6228C934ULL, 0xB78EA0EAD4D456CEULL, 0x48855A11181B460EULL, 0x48E58708D2110232ULL, 
            0x1F7F254A3A8956EEULL, 0x9B810627D6B57F24ULL, 0x245F44E37FE59499ULL, 0x3FDF531E0CEACE59ULL, 
            0xA1B7CCBB75D8AF11ULL, 0x1DEECD9A3C86F038ULL, 0xC1AB748613D3C344ULL, 0x43A4246A596B9EC4ULL, 
            0x873E92B0F0BA1823ULL, 0xC89B94C0813921A2ULL, 0xB44258FD7FD80F11ULL, 0x6CA4E26A63D722D5ULL, 
            0x2E8A37953239D9CEULL, 0xC79306EDB785675CULL, 0x3D198C7CDAD37226ULL, 0xC1B9F4464F0EA065ULL, 
            0x902C7F308CFBC127ULL, 0x2DDBFC1E51B30552ULL, 0x9CF6B47D438F4573ULL, 0x2B88C38426950E9BULL, 
            0xA15C794C7AB23EC5ULL, 0x65FD41E7FE75F288ULL, 0x5280407A17DDBF4CULL, 0x2754AAD6CF71E1AAULL, 
            0x409FF3A8EF87AE59ULL, 0xAA3AF60CD22CABD2ULL, 0x73EBFBEB88F5F2C6ULL, 0xA62D9EE6D27AADCAULL
        },
        {
            0x6851B8C8C612DD6BULL, 0x386C67453F3CDC6CULL, 0x640E3D3B059C7DB9ULL, 0xE30998F1FAF65CE5ULL, 
            0x6DBD8B44E81D096CULL, 0xF87EFA0D863F0B89ULL, 0x8C921E89991D43D3ULL, 0xB0D5D512B7E29EC1ULL, 
            0xA402D38F5A3E5122ULL, 0x185C62DE7D4C3567ULL, 0xDB5D8ACAA549B80DULL, 0x86283D1DA4B4C6EDULL, 
            0x662056C84CD0D034ULL, 0xA25120A81FDC10C7ULL, 0x7D2AD5DC8E1E28E6ULL, 0x576440BC5120AA9BULL, 
            0xFA077D98269548C0ULL, 0x5BA2B9E539F8C28CULL, 0x6CD2EBE885C8084AULL, 0x19BB133034443A7EULL, 
            0x58245C5723E63B3FULL, 0x4FD0D33BF6CC88AFULL, 0x83F91F297263432FULL, 0xF60C84724FE40C6DULL, 
            0xCDCAE307E7151312ULL, 0xBC657D205709077EULL, 0x9ED6875EFCF18B60ULL, 0x85AC6FE08ADA38DBULL, 
            0xEBC41DF9504F5FCAULL, 0xC6A086CFF15911BCULL, 0xDDF67DE83FC639D2ULL, 0x7613D571E7D29090ULL
        },
        {
            0xA066D3BDA27EF903ULL, 0x512653BE5D73CFC9ULL, 0xD466F7B9382FA6B5ULL, 0x2D9293CBD14CD58EULL, 
            0x9BBBF64EE90C122BULL, 0x5ECE42480CB4CA19ULL, 0xDC579A52283791FAULL, 0x04E2C3BCA84F20C5ULL, 
            0x7D743EF40965DB54ULL, 0xADACBA3B89209129ULL, 0x7A7C5AE2981AC786ULL, 0x497FEB07A233EAD8ULL, 
            0x9DB33CD663472937ULL, 0x41105E0A91542B65ULL, 0x05F28DDF0F645CE9ULL, 0xF2B4842D85BA4512ULL, 
            0x777A9EBB3E113C45ULL, 0xD9B6DE8EFA74BC9AULL, 0x575E9FBD6F1A09B4ULL, 0xE121A7B21FBD89E5ULL, 
            0xDAF552E0468CCBB4ULL, 0xAAD4188C633FBCC1ULL, 0x98E68A388FC9F7F4ULL, 0xB46B9BC7CF64226EULL, 
            0xAA772E6497704313ULL, 0x3FC532D070DE0FE2ULL, 0x4FEB6ED529572BEFULL, 0x083F6AC4B154CD5FULL, 
            0x91577666781B3D40ULL, 0x5D985C71C2E92AE5ULL, 0x1F6A0D9510026578ULL, 0x6724129F4E9CF8AEULL
        },
        {
            0x75FECAFA91EAE1EAULL, 0x8AF22141396C4101ULL, 0x2CEA7EE3E9510CA7ULL, 0xDB6781F74FFBB126ULL, 
            0x02B7C366C194B4CDULL, 0x30B804F8F31F8620ULL, 0x54F6E5913C313DB9ULL, 0x99C1F84BA75AF2FDULL, 
            0x0F55E09988F7AB2BULL, 0xA73DAD8D623E03AAULL, 0x891C585CC8318157ULL, 0xB6E5312A445CCF7DULL, 
            0xE6FB9391BA29A309ULL, 0x79EC0428FC356793ULL, 0x6E3D2BAD91D9C29DULL, 0xE573440CDCCB64CEULL, 
            0xC92E5B5A82D766AEULL, 0x754029A228CD15F8ULL, 0xADB6C4B03E54EAACULL, 0x249880D690E339EFULL, 
            0x18422EAFD601D437ULL, 0x9BBB1B7538E8E3F0ULL, 0xB14682F73671ECA4ULL, 0x05811F4329F1A443ULL, 
            0x90DDAFBF8B39F177ULL, 0x531CDDE000BC5517ULL, 0xED15206FEA9B145EULL, 0xB56DCBCF9DC78866ULL, 
            0x5EF01EC4AED74B3CULL, 0x8F1E6ED821FE546DULL, 0x56603ABDC37680B4ULL, 0x5EB92ABC349CF7C3ULL
        },
        {
            0x98D965F887E837D5ULL, 0x4FEE20909C410A5EULL, 0xBFCAF8A5C15022C4ULL, 0x32A5A437AEB0ABDDULL, 
            0x05E684A963760AC8ULL, 0xAF91D1FED68921BFULL, 0x670617BA09AADCC8ULL, 0x1E04A214CF0DFD37ULL, 
            0x5DE86B562DB5F2B4ULL, 0x1F5FF0C1E88D6267ULL, 0x4E165F684B22B017ULL, 0xDDFEB65E31296CAAULL, 
            0x2B96257B46563958ULL, 0xCCEDAD45E21DF039ULL, 0x86CBA8FDFA0F325EULL, 0xC70647B8398D0235ULL, 
            0xEB4BF48D337CE7FCULL, 0xAF06B4C1E3555984ULL, 0xDAE10700B0898FF1ULL, 0xC356BD8B2AA5D0A3ULL, 
            0x4D8B4AF061A32DB9ULL, 0xA37778A5446B8441ULL, 0x2858CD75D5F8E2CEULL, 0x6FEB307A4C551DB9ULL, 
            0xA4C4A063B907A773ULL, 0x426BEB2EEDED27E4ULL, 0xDBBC77F6E3837965ULL, 0x456EA23042E87616ULL, 
            0x3EA3527D227AF26CULL, 0x34DFE2A0259C797AULL, 0x12976405A830108AULL, 0x2D42A32775079B78ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseAConstants = {
    0x1BC3551E1B22C181ULL,
    0x11AF6C425B9EF979ULL,
    0x04E00CC96B3FBBCCULL,
    0x1BC3551E1B22C181ULL,
    0x11AF6C425B9EF979ULL,
    0x04E00CC96B3FBBCCULL,
    0x76074EEBCBDC1DE2ULL,
    0x921BE749502631F3ULL,
    0xD2,
    0x6D,
    0xB4,
    0x84,
    0x44,
    0xD9,
    0x87,
    0xDC
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseBSalts = {
    {
        {
            0x542EEB5847350053ULL, 0x36C1AD9746C84CD9ULL, 0x462CB724C445116DULL, 0xD50B2B0F141F3ABAULL, 
            0x313DCA828CB7116BULL, 0x4FCB3D688B174615ULL, 0x6530D47C9626BE26ULL, 0x6BF5E8B69F976C96ULL, 
            0xB1D28FDA0D9B2F78ULL, 0x70A1FEDD05E810FAULL, 0xE3BDAD71CD9FD165ULL, 0xAA7A08960A32BE2FULL, 
            0xA126E4866F67840BULL, 0x5CAB1788B487EC4BULL, 0xE85824A84474772CULL, 0xBB862F2CBF1F7313ULL, 
            0x040ACDFF0CC3A303ULL, 0x8256EB8A30697995ULL, 0xEF210C075A0B902FULL, 0x772C48674A7A2EFFULL, 
            0xB088E3C9EF3BFE37ULL, 0x8458EC1CB848454AULL, 0x6420200B2B1F39BFULL, 0xA1AC029BD669706CULL, 
            0x9F1CEB31E4F4625CULL, 0x9D3F7BC7ABA55513ULL, 0x852D862DDFC9D535ULL, 0xA1E630D7FD6F2352ULL, 
            0x9BBB89F801C3A138ULL, 0xC9FC1C72524F54F4ULL, 0x4CC347454B29F4ACULL, 0x2884A691A8292FC1ULL
        },
        {
            0x2F920731E5FEC154ULL, 0xAA9D8FCD5240A19AULL, 0x7F33E39B0F1DAC4BULL, 0x47F43BC1E6221238ULL, 
            0xED0E9CD468AF85DEULL, 0x79C0A605AAF2D059ULL, 0xC52F64ED0283F9DBULL, 0xF5CE277E350C37B3ULL, 
            0xFC8658A71FF176A8ULL, 0x36027B862D2C7BC6ULL, 0x3DA63EA75F23528CULL, 0xFCF626183FD0AFDFULL, 
            0x5D3DE6DD2B4EE81BULL, 0xC93D7E31949C9586ULL, 0xBAF8478E1F1630C1ULL, 0x7BC87411464E341CULL, 
            0x722ECBF08E4F73C4ULL, 0xEA30E38B9B397A00ULL, 0x83D335E72FAC303AULL, 0xD382891424C18EFFULL, 
            0x27A85B281E174694ULL, 0x435BF04F05FCBA18ULL, 0x8327876CC20E7BC0ULL, 0x2A44C482E5A9E0FFULL, 
            0xEDF79646B7FE51D5ULL, 0x5352C3940040854AULL, 0xDB1FF66062E78FFCULL, 0x1C45CEC1872D2FDEULL, 
            0x7372229E378FF730ULL, 0x049295D6D5E09A7FULL, 0xD8F2D9CAEA8876CBULL, 0xC91518A05D3158F7ULL
        },
        {
            0x8C84EF17965A359EULL, 0x54ED71971163F8F3ULL, 0xB6E9512251FAD0E5ULL, 0xF75049A74F58C36EULL, 
            0xE5CE01234CEC1833ULL, 0x532DD123E3027373ULL, 0x528D95948E1B1E64ULL, 0x199445476DB5A51AULL, 
            0xD1067EE80712D352ULL, 0x2F77060914C0C9E3ULL, 0xF230098A75315E93ULL, 0x980D317E3F05A691ULL, 
            0x4AF289B18684CC51ULL, 0x9C1729059B2171F5ULL, 0x04442BCAE7549E3BULL, 0xDE2C6446503C3476ULL, 
            0xA9D13FBA79E7B31BULL, 0x3D3926C416B39EF7ULL, 0x2DF5E219C6B598F0ULL, 0xAAC51F245013976AULL, 
            0x693E37BCC19FDD73ULL, 0xE53F97E16C34FE35ULL, 0x1B278C2F2BAFB2C2ULL, 0x2B406ED8065663A0ULL, 
            0x13A5C93280A3A542ULL, 0xCE7F383F7ACBC788ULL, 0x7E5D8A1DEAFC6F67ULL, 0xCBD7E1691E274A85ULL, 
            0xA20642A9F344B03CULL, 0x9BC698F801F7715AULL, 0x010E025294644E04ULL, 0x67D94C7DD37CF5A3ULL
        },
        {
            0x64518B4A7C2DA9E7ULL, 0xBB793A8A8324D5B6ULL, 0xE6E4087009F3FA99ULL, 0x3006EFAC963B4F0BULL, 
            0x46AB0A8A8D78A9F3ULL, 0xFE41905413428E48ULL, 0xD8EACD7FCF9AA645ULL, 0xB897F351159974FBULL, 
            0x9F849F6A91545797ULL, 0x7F2A69B5206B3ADDULL, 0x7E99AF9F648649DEULL, 0xC67C6B827C2CFED9ULL, 
            0x0F8CC007A9161306ULL, 0xB31ADDC524345CBFULL, 0x6CDDB9F1D7B6FF25ULL, 0x39C29DD6B4186233ULL, 
            0x4A75FDD5A68C24DAULL, 0x14711A563EB244D2ULL, 0xC5887C5094DCF9E8ULL, 0x49D71D194BB2BD9EULL, 
            0x9068425264521C0DULL, 0xBD9A25488F938596ULL, 0x409655FC266F6F41ULL, 0x3A4F588161DAD9FDULL, 
            0x1E3D2F3BC69943AFULL, 0x56C604BDC215E4D4ULL, 0x610C42705891F3C3ULL, 0xE861F0BE0D4BC773ULL, 
            0x3699F73B466A77DEULL, 0x2113E3DA167C71DFULL, 0x8AD7B784087BF5CBULL, 0xDD6202E18A7C13C2ULL
        },
        {
            0x02037731A9207749ULL, 0xF9DCDBE6BC47DD7EULL, 0xF09E422178E72DE7ULL, 0xADF014AC8B365605ULL, 
            0xB87A410A6B22F993ULL, 0x96B173EE82779FF3ULL, 0x5E7571B7792CDAFFULL, 0xE95B7365DDDE9B0AULL, 
            0x9E8E7BCA653BC8B8ULL, 0x55FB84FF53DB1285ULL, 0xD737362A24B431E0ULL, 0x8AEF5215157BB8FCULL, 
            0x1BE0AFEE0C4049BFULL, 0x8BC09B17EC34E72BULL, 0x73605C510E919C20ULL, 0x3A39225461951DE9ULL, 
            0x9BB409B68D3BA1EDULL, 0xAA71CC13A721BC99ULL, 0xA62A57925FDAF5BBULL, 0xBE74730DA2F507FFULL, 
            0xE567DC95DC70D4BDULL, 0x04A0B50FB9A7F8EBULL, 0xBBE2A51FC1BCEF81ULL, 0x17CBB411EC5ACE09ULL, 
            0xAFFEEC32B7E88E9FULL, 0x12ABFAB78DA630C4ULL, 0xD6E7DE76C100238BULL, 0x79E901B6267CFB52ULL, 
            0x08460DAAED0EA9A6ULL, 0x3A75E66F7B5B8A7EULL, 0x3B2D2ABCA3713D30ULL, 0xB0C7B2E8023CC30EULL
        },
        {
            0x1C8B87E4A03174E0ULL, 0x1267ECC669F2A87DULL, 0xF62CFA093BB51957ULL, 0xCD13494F11E2B2AFULL, 
            0xBD9220CBA3DD60A7ULL, 0xEF556F03C1D49433ULL, 0x20F7A6885E2C9632ULL, 0x358BFB595C497A0CULL, 
            0x12B0CF9FF02D8411ULL, 0x278B7D75D02FA36DULL, 0xB01BB5828FD7DB75ULL, 0x25044BEC5A5F31ECULL, 
            0xDB93EC15B6BD1333ULL, 0x6C063C51491A13DCULL, 0xEC046F0549C2DE0EULL, 0xC7C114CC4A25B7D1ULL, 
            0xFECD5496375F4D6BULL, 0xE7BDE34FD07FF675ULL, 0x3A306F7A9A42EB81ULL, 0x0B57993AAC80ECF7ULL, 
            0xEE6AF481FD29BA2AULL, 0xF806E2EB838317D1ULL, 0x7D561AAF2F492C79ULL, 0x7EF48C82CAC2E17FULL, 
            0xC8FBF90C35B6A3C4ULL, 0xB52819414630608DULL, 0x8414EDEE5B2EB0F0ULL, 0xDDDAAAF8649B22FBULL, 
            0x2F715872AD849E55ULL, 0xF66EE9D31EF1B692ULL, 0x7D9679A1366AE70FULL, 0xC3099A42501410A6ULL
        }
    },
    {
        {
            0x8D1CC83AA81974C5ULL, 0xE346B61FC6E1C2FEULL, 0x3A8E60470CEDE7CBULL, 0xB0F021E60EEDA63FULL, 
            0xAF535B919EB6FC26ULL, 0x1D068D068F0757B1ULL, 0x103328B0D09DC0E9ULL, 0x571F7DED49A35F86ULL, 
            0x0B45B5BB2A48D117ULL, 0x06A30E74A3FC6997ULL, 0x9B28DA8484DF48E7ULL, 0x76D84F7C4AB86AB3ULL, 
            0xEFA486C922919244ULL, 0x4A6102338DF1D755ULL, 0x9B9FA582589CCE52ULL, 0x2F37F5FCA0CE5D86ULL, 
            0x65EDFC3D0BF749BFULL, 0x05E48E1DD5289A0DULL, 0x2915BB533943504EULL, 0x35D2F475ADD7F425ULL, 
            0x37796D965D29C8E4ULL, 0x1971C17C50016D31ULL, 0x7ECBF721CB7BA173ULL, 0x299F09729D5DCFD9ULL, 
            0x52DF5CFE5148CE27ULL, 0x3BDC8371D2F8A209ULL, 0x5C18E6F97AB1AB8AULL, 0xA4BB82CE1AB47987ULL, 
            0x4A508BC50A88BC3DULL, 0x33D1BA6DD90B8540ULL, 0x171A35C8CF9BAEDAULL, 0x82C3CE357703F118ULL
        },
        {
            0xBDA361E335F4AB11ULL, 0x8C5B13716C2EEE24ULL, 0x7E96EEE1BC4ADA39ULL, 0xE533CAFE8FD76453ULL, 
            0xE0A1C439436AEF5CULL, 0x0BA7303E7B630792ULL, 0xC2002134A744068BULL, 0x600D0B4CBE84F53DULL, 
            0x4DDF952077A08010ULL, 0xAE7B6AC765F6861BULL, 0x06012D065522F333ULL, 0x9397604E2EFFDA72ULL, 
            0xB4CD376D9CB03AADULL, 0x7A0F34057A49616EULL, 0xF6D539FE764499E3ULL, 0x65446111C61A543DULL, 
            0x45FD46AAAE49CB13ULL, 0xCDEB57B7D9333F3FULL, 0x114F41E43773BFD4ULL, 0x85B5A096DFDC97E4ULL, 
            0x9F024D2C06611513ULL, 0xE41BBB896DD788FFULL, 0x02E7B6EE84BE716FULL, 0x17CF468D28C53FD4ULL, 
            0x4F53C915DE4462A5ULL, 0x68B0FCBB193F2DD7ULL, 0xEC8AD76B855ED069ULL, 0xE8FF544BE4C4FDBAULL, 
            0x1074FAEBA2FA1B81ULL, 0xB2AE9B06D40C5882ULL, 0x15EC4B5E0B099A28ULL, 0x55BE0923DD25F426ULL
        },
        {
            0x86B62524936CBFCFULL, 0x30B536B24A7CF980ULL, 0x47AFABA0A721CEA6ULL, 0x274BEE01A90548FBULL, 
            0x631D6E32723B88A7ULL, 0x5BE45C34A035A085ULL, 0xD3CCF51B7528D30BULL, 0xC27917C747162F4FULL, 
            0xBDF69976FA7C15FAULL, 0x89F8C8F086907855ULL, 0x790585AAA158ADF0ULL, 0xEF27150F92C87E2CULL, 
            0x72AE26DD9E8D1E80ULL, 0xDC69C95BF25C6301ULL, 0xE0689C54A74F1DE0ULL, 0x77504733FA262D30ULL, 
            0xBA05C995B466380CULL, 0x226A7C55F1FC2DF5ULL, 0x150B0F3AF79908ECULL, 0x109919A058A8157BULL, 
            0xC7C7A5AF6D7DC89EULL, 0x0EC0A95C84937489ULL, 0xC055911527FFCFBFULL, 0x93AABE5DBC4B3C93ULL, 
            0x4A56B939C031D403ULL, 0xA6D034B1CCAC0F61ULL, 0xF82FF294E23A4277ULL, 0x623C6435FE84CB6CULL, 
            0xCCFD9B7492FA70B1ULL, 0xF9BD0B3B71E8DD8CULL, 0xD391E26AD7E57555ULL, 0x661A2DA8CDAD733FULL
        },
        {
            0xAFBD7CD5F6F224E7ULL, 0x96DDF708B42102DFULL, 0x7FD24E9AA764D069ULL, 0x8FBCEB37505BC1CDULL, 
            0x653E4433ECEB4F77ULL, 0xDF4B52121A6E7096ULL, 0x3D42F70771C42BCFULL, 0x1110B313637F7C55ULL, 
            0xF994B665ED9B2CC4ULL, 0xE5BFBE52E7D3D33FULL, 0x1FA39A03549B42B4ULL, 0x84AAC9608619E3B8ULL, 
            0xF5E2F497F22AE30DULL, 0x2CABD3F0276D51F2ULL, 0x3CC740C8FAD0C0CEULL, 0x3049AB30091D24A5ULL, 
            0x3306610BFBB83A29ULL, 0xC98A308EB9184A85ULL, 0x294496D894AB4B34ULL, 0xCDED9705721F160CULL, 
            0x2AC883F6380831FAULL, 0x5B90C085C665AF49ULL, 0x63CF0A913C7D97B0ULL, 0x12E093EB534B8E87ULL, 
            0x043E3B5FC1507F98ULL, 0xE227A4094C1FDA58ULL, 0x730BCAA2B1458F7DULL, 0x4B85CC4854A7D0BBULL, 
            0x989AD5DFBF92FB3FULL, 0xB97383F39C649239ULL, 0xCB015FAAE31B17CEULL, 0x7A92125BC2B7B6ABULL
        },
        {
            0x3FA82C4326EA747AULL, 0xF80D25E40ECF7B77ULL, 0x087696E754F830D4ULL, 0x7630FF548C1AB11FULL, 
            0x9DDCFA1BB3115C5BULL, 0x6B1203151E782262ULL, 0xE39C4E40077BF8B6ULL, 0x488D3C2D42403320ULL, 
            0x1F1888F24240690BULL, 0x9A7425849F06A5CEULL, 0x743A4A9FB9BFE613ULL, 0x05253E66CB92FFA8ULL, 
            0xB420F13A92035A19ULL, 0x35262EAB49D5841FULL, 0x4640F9FE69451067ULL, 0xA96ED60BDB9EBAA6ULL, 
            0xDDDBE8B91AA9033EULL, 0xE2EA4B06D1834945ULL, 0x190D67B464AD6901ULL, 0x373A6D474C59B97DULL, 
            0x3C317DD99404C130ULL, 0x8D78A5D73590E696ULL, 0xC40E7779A5FFF211ULL, 0xF578A15EAD293363ULL, 
            0x13075C79A76ADA7AULL, 0xF0944C15B05D0D67ULL, 0x45F9E9B78E2DA58CULL, 0x526554C26FAF4108ULL, 
            0x647AB562051CF8ACULL, 0x130B445020C9491BULL, 0xA28092C1F63B9C77ULL, 0xBBFA173537CFD883ULL
        },
        {
            0x2ACBBB0A3BFDBBA0ULL, 0x17BCEF31BEA03E5EULL, 0xA46694933D63B12FULL, 0xC2A3D141B0D3D3DEULL, 
            0x4AFD6F6D8EBA83A8ULL, 0xA175A393F551C304ULL, 0x48C7FDF4CC35FB64ULL, 0x0E1BCC123D74C4EEULL, 
            0x58F34B6FA3034DA4ULL, 0xF2B9C3DA654FD6E6ULL, 0xF08391EA25B41E17ULL, 0x3F28EEF025C96E5DULL, 
            0xF352FDFED23FF064ULL, 0xFC8B52AD88F081F6ULL, 0x6CBFF3FEE5089C10ULL, 0x41DB16F7205E6D4AULL, 
            0xBC996BDA3FEDD94AULL, 0xEFA1812653CECA8CULL, 0x210BEC0BC7B271E9ULL, 0x40C4F6B5E914FB58ULL, 
            0x22ADCCA6D689D767ULL, 0x71A7D061B91DFA3AULL, 0x5466533C6881E7ACULL, 0x60441178656C0C64ULL, 
            0x08F46AA3F75D748CULL, 0x81AD1D2928F00172ULL, 0xA90BCEFCE3CA162EULL, 0x9EFFA23150A6729BULL, 
            0xF14C2D5B1512C05BULL, 0x7D84158A7D650D77ULL, 0x1C85EDC12959DB17ULL, 0x1F1A285E67496384ULL
        }
    },
    {
        {
            0xD6DCBA7BF61C8AF9ULL, 0x29707B9027EC61F2ULL, 0xD52BD86968E88760ULL, 0xF012F749B969C7BFULL, 
            0x49D815A45428A1D1ULL, 0x50B4A412DC43E558ULL, 0x78F4B2BA9B9E4297ULL, 0xB092757922F0AD50ULL, 
            0x402E3FA0384C7724ULL, 0xDA8B2BF6C74FC20BULL, 0x74DFCE405CCB7B3DULL, 0xF1B88F95DC6A99DBULL, 
            0x9664680DBE3656BEULL, 0xF69A31F6767BA52EULL, 0xC94C2080A4EB1828ULL, 0xC4554848C86792ECULL, 
            0x2BF90A8474DDCB6DULL, 0xA692240C7F5C8234ULL, 0xBAAC47B96F8FB4F3ULL, 0xE9BA824BB282328AULL, 
            0x29CC52781608F61AULL, 0xB20BB90C9425F3A4ULL, 0xFFC1ED8322C71E57ULL, 0xA2B65542A7E3BF43ULL, 
            0xCCF2FE5CE2DF06F8ULL, 0xDC94739E2D42C466ULL, 0xE9E19FD1969EC4BEULL, 0x0F76E79B26B9869FULL, 
            0xF58DE86E9DDC3B04ULL, 0xC9E7CFA9007FA715ULL, 0x901F5CE4BDF940B3ULL, 0xA6FCD953CA6D4552ULL
        },
        {
            0x9F538333BB7BB207ULL, 0xFFE95C640E945E54ULL, 0x5055263FC94FD470ULL, 0x2C33C199AD792A40ULL, 
            0x5FDAF1B3465B9A06ULL, 0x74A62B729B87FAFEULL, 0xCC1294213E5245A8ULL, 0xEE1D3ABB85C60106ULL, 
            0xE67FA33E216D9399ULL, 0x7EA573B4690D9F5DULL, 0x348E11FF818EAB7AULL, 0x7D7EACEF3B0403B3ULL, 
            0x769D172F22E8891CULL, 0x57549382F9824B4FULL, 0x218618A0CEAF7387ULL, 0xC7A81811FFDFEF55ULL, 
            0x5E96EC63F4B24ACEULL, 0xD15CB1263999C3EBULL, 0xE63A6A68D0ADB280ULL, 0x844F08E4657F39B6ULL, 
            0x4947AC0AB5F65FEAULL, 0x6E6F6701D3F7FD2EULL, 0xEC701896FFB83806ULL, 0xA1862D8B25541249ULL, 
            0xAC489EC4FC02C8A2ULL, 0xA7D4C3D93B3597A2ULL, 0x89D95AEC7DEE9ED3ULL, 0xB7A128F3D569F185ULL, 
            0x6662DF019B747A25ULL, 0x3777800250BD87D5ULL, 0x08DAB8B19C759A14ULL, 0x1AFF0FA2BA9F00B9ULL
        },
        {
            0x34C5086BD56D84B4ULL, 0x376A5EFEF965EF54ULL, 0xB8EAA0AFE6382426ULL, 0x555B9FEA9477BEFDULL, 
            0x68B4C8F9BFEE331CULL, 0x853A481859F86110ULL, 0x4C99140A80DB079EULL, 0x2779761E6023FF6BULL, 
            0x1300F66CD8BDC723ULL, 0x37B70205B349631DULL, 0x55CF4FAC3485DED6ULL, 0xC676598FF817F5D1ULL, 
            0x7865F04B734F7559ULL, 0x89455A5D9B98CF71ULL, 0x576E8A4CCE9C1E65ULL, 0xDE3DB0996D3B83BBULL, 
            0x2A706F1A90E3B266ULL, 0x1A748DEC72B8310FULL, 0x23F2A9ED906A5B3AULL, 0x0C26D58FEFCC6F61ULL, 
            0x88F46840FD7A4236ULL, 0x9C702F7A8A7FB230ULL, 0xC5B618C195774E2DULL, 0xB97540AADC01AEA2ULL, 
            0x675EC846377C011DULL, 0xE19924F873BDF48BULL, 0xA67506834F3EF003ULL, 0x165FE8FD84AA9B24ULL, 
            0x6413B6FC1EA229C5ULL, 0xF396FD1D4F8953DBULL, 0x976BABEB4F818511ULL, 0x84C54FFC16804AF0ULL
        },
        {
            0x2B9215D5CF2AEF18ULL, 0xF994451966650B72ULL, 0xAAB5A1F454262B94ULL, 0xBBB752687C7AF492ULL, 
            0x38E028D99F1CBBE4ULL, 0xCF9C8139FF3EDB39ULL, 0x598F0562ECE1D5F9ULL, 0xB5B3F06078DE4F93ULL, 
            0xF6C6AC7D4BF1A346ULL, 0x1967F30532FFC793ULL, 0xD1AC33387A3DBF95ULL, 0x967A7ABE5B6F36EBULL, 
            0xB0529CD4EF7D9BE1ULL, 0x178797EA4129F120ULL, 0x8C6936ABD1BBC92FULL, 0xCA033AA4DC302186ULL, 
            0x17B19EDB24CF6973ULL, 0xB0C0DA9B1937E5DDULL, 0xB925C71184C1A127ULL, 0x7C8AB642D6D3FF0EULL, 
            0xDF34C51B1175C18DULL, 0xBDA64F314E9E3749ULL, 0x746FF4F1E674464CULL, 0x9FA5F54FE7352A73ULL, 
            0xBE84541BE1107236ULL, 0x5EEB6EA72722E9B4ULL, 0xEBB129C11CE68854ULL, 0x4B08C7ECFFED8C1CULL, 
            0xD53DFC3DDE3ECCE9ULL, 0xA24271A3BD095B6FULL, 0x6EE5E4F97A6639A0ULL, 0x4053023AE4C7DACEULL
        },
        {
            0x925154DBDCB1AE80ULL, 0x07423B61B076BC5FULL, 0xC75FA6C2D9963BDBULL, 0xE68795F14274AB25ULL, 
            0xB7B0CF4A6EFB6E01ULL, 0x767FB8F32B90BE34ULL, 0xF1C49B42B5E65251ULL, 0x9D99CE38E6496773ULL, 
            0xDD8EF6102A06D580ULL, 0xCA11D4DC38DB2E60ULL, 0xD562E190ACDF3F9BULL, 0x4A671C3A4C0927DFULL, 
            0x6231F1CA785851CDULL, 0x4FE95AA926510F33ULL, 0x37DFD99A254F9673ULL, 0x42114F8289B71D39ULL, 
            0xAFE54FD375ACE551ULL, 0x3B93307374240C5FULL, 0xB1F51D38C17376B8ULL, 0x5FD52215DFB47E19ULL, 
            0x730E5DDFAE2A2A09ULL, 0x4B27C0B59FE58A71ULL, 0xBA3BA95DD037CB9CULL, 0xC3610131CAA8B61EULL, 
            0x36FDEFA992802E93ULL, 0x7833B4DBE6AE5056ULL, 0x10719C00AF5B248BULL, 0x3C10C61E26875620ULL, 
            0x21B5D260D77B2F20ULL, 0x0E20E0A691BAB10CULL, 0xCE83677B7D403A88ULL, 0x68B5875A7C57C3F5ULL
        },
        {
            0x35457EED65D546DDULL, 0xCA1ADB772218669EULL, 0xD5411176C434EDA2ULL, 0xA1478D0F2FC48214ULL, 
            0xF783D193911FA19BULL, 0x656C54E36E8430E1ULL, 0x830316B5B7127EA3ULL, 0x5B3054B2D98BE9D8ULL, 
            0x6EE43D7ED853B470ULL, 0x913A619C1B19DC20ULL, 0xCF0222DA2F862BA0ULL, 0x8E5D143F46FE6702ULL, 
            0x1B8BB28778CFED9FULL, 0xDBAD37228D737D6FULL, 0x2DCDD0992F7D7684ULL, 0xFBD1556E04473690ULL, 
            0xEFB0445C8728CAAEULL, 0xAB85294E9948DCFFULL, 0x9C15E41C60AB0995ULL, 0xCB593EB21F79D4E9ULL, 
            0xCD16B6F5EECA30F5ULL, 0xC7FC3B7CD5D9ED58ULL, 0x07ACBD8673781AC6ULL, 0x8F802E705B71545AULL, 
            0x1CDB996735BFCE92ULL, 0x4210AFE58EB68988ULL, 0x219E759222269839ULL, 0x47EDE44BCF338927ULL, 
            0x7A118A98058420A5ULL, 0x3CF912313F89CCD8ULL, 0xD059A5A32F8DF71EULL, 0x91CE7A5A5CE70766ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseBConstants = {
    0xDA13B730A9808ADDULL,
    0x323C2DD1A3C48DDEULL,
    0x391DC69CCFDA67C0ULL,
    0xDA13B730A9808ADDULL,
    0x323C2DD1A3C48DDEULL,
    0x391DC69CCFDA67C0ULL,
    0x628F9F0157E9EAD4ULL,
    0x20D36CFCC5A74D96ULL,
    0x81,
    0x28,
    0x7D,
    0x8E,
    0x23,
    0x1D,
    0x83,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseCSalts = {
    {
        {
            0x039E321E00258098ULL, 0x4587E3A73C086829ULL, 0x2273D6551D1D2D38ULL, 0x6F47F72B79EE6C26ULL, 
            0xDE9D0FB115FA13BDULL, 0xAE0EAB15B4B3B675ULL, 0xD794AB8D5FEB3837ULL, 0xEDBF455E9DED26A8ULL, 
            0x2FE76AF6B9667A6FULL, 0x031EBED2EDA131EEULL, 0x2E8CA341E9842E5CULL, 0x62517D926953C3CDULL, 
            0x4BCB014BE816CF3AULL, 0x189629B7A1B51F5EULL, 0xA1BF4AC8ADBE86C0ULL, 0xC85657ADE1EE1074ULL, 
            0x7748D2EB3D9EF88BULL, 0x21BBB2D871342C7BULL, 0x1E6E17A0AB6EC682ULL, 0xEB0068E40A6C1B79ULL, 
            0xDA190AE8C0E8263FULL, 0x682027D9039726CBULL, 0x5AD85B22689AA862ULL, 0x7715BB8B6AD47F41ULL, 
            0x10F29A82A8EDBDE1ULL, 0x9FB574782D03D08EULL, 0x596B975EB0863BD3ULL, 0x3AA08E1EA399DEB5ULL, 
            0xC556F743931E3D6BULL, 0x6CC10FB2E09DEB6BULL, 0x542144958827C2F5ULL, 0xEC88EF2AF3A45104ULL
        },
        {
            0x773ED9B591EC02E0ULL, 0x5D0965B58450B26BULL, 0x2B9A0456EE3ADDECULL, 0xDE8F855C06419FB7ULL, 
            0x21DFA69FFDEEB64FULL, 0x7371F7A5F8FFC933ULL, 0x4922B5109D008EEDULL, 0x74820091B06FEB5BULL, 
            0xF528332572B016F3ULL, 0x00C1DE73CE776921ULL, 0xCD832BA57370CE7EULL, 0x63B2C65D2C1B294FULL, 
            0x3CF732585AF78626ULL, 0x6037250DD298D513ULL, 0x05761AFFA54CEC58ULL, 0x02AEDBB2232F486FULL, 
            0x35A5280F32233B9EULL, 0x78B5E81CE6656167ULL, 0x25F499821066211DULL, 0x30A3628C57870D59ULL, 
            0x9BF559DBB4D13F8DULL, 0xBB71EA56F96E8868ULL, 0x918DAB9BCB408957ULL, 0xBBC3C51D60CC8118ULL, 
            0x826D8B5BC62BFAA4ULL, 0xE02B9C40ABF1175DULL, 0x2198ECB6BBE12756ULL, 0x2946FCC7411C89F7ULL, 
            0xD6BABE621BE5B6ECULL, 0x177B2B6CABA75C3BULL, 0xEB33B46037E748B0ULL, 0x7E0BFE847B881029ULL
        },
        {
            0xE77ACE50B1F9FA59ULL, 0xAE325F45B420E40AULL, 0xC53872EC85859160ULL, 0x099F1DE5BA926044ULL, 
            0x280A5093D7C4FDE4ULL, 0x9BA7E4F32C7E1CF9ULL, 0x5CCEF17F844161A0ULL, 0x86B9B0ADB8FCE423ULL, 
            0xE5E96AA76BC0F859ULL, 0x835DFC12FF5FCF32ULL, 0x21B68CA825A8974FULL, 0x7B440C8882F99609ULL, 
            0xA3E244DAA6C629E4ULL, 0x7387F843CB3CC62FULL, 0x98E646CAC77F9905ULL, 0x35CD97D5233EC077ULL, 
            0x8E1F1B581AD50BACULL, 0xB56BF7CD30EE73A1ULL, 0x9A7C8145B47E2B8EULL, 0x28AC2445B2F13F16ULL, 
            0xF01CC776A4D4FBB5ULL, 0x3DA191204844A38EULL, 0x17FC3E4D52468415ULL, 0xD1D4C295386D3D20ULL, 
            0xE74878EE3B9FCDB6ULL, 0x3BCA0F7EBC556F4BULL, 0xCE87DAA91F517BF1ULL, 0x5317AF249B6A37DAULL, 
            0xEE769D5CD8B77FDCULL, 0xF735883E13932979ULL, 0x4C09114BEFFF46ACULL, 0x876132B42B362ADCULL
        },
        {
            0xF81CF90E6495D645ULL, 0x8771FDC768D84856ULL, 0xDF203C776FAA1B40ULL, 0xF086C4F986831947ULL, 
            0x583DE5B5BA904A21ULL, 0x204F9FDBD7ED4A94ULL, 0x08CE2FEAE8115340ULL, 0x7DD0CB544DB3B26DULL, 
            0xB9FA41FD5B95AC30ULL, 0x3648B8F40805447DULL, 0xC568607B77E7BC75ULL, 0x8226EF97BEA043E9ULL, 
            0xF8CA2423F4DAD946ULL, 0x397FDD189E943D44ULL, 0x7553C4E4E55EF58EULL, 0xFF3CA965D24DEC8EULL, 
            0x8ED9C77DBBE768FFULL, 0x51890F46DFB0E0E7ULL, 0xC9207E84E5551E15ULL, 0x922127E07CFF9542ULL, 
            0xF163E4881DE5E6ABULL, 0x1A8D2BEC6E895C97ULL, 0x6625A88C66F45490ULL, 0xD708A848AA1EFE4BULL, 
            0xF4944DD90DF1BF6CULL, 0x8C37770D48620643ULL, 0x09C2FE00E6FDBA5EULL, 0xED796FDC70EE2897ULL, 
            0x16BE75472C65E1D7ULL, 0x4D123CB064FB0C89ULL, 0xEDDDD919E65297D7ULL, 0xFA37A1B2CBEAC2F8ULL
        },
        {
            0xF7ABC88BD78FEE2FULL, 0x13214DE15CD11E06ULL, 0x4E04A68BA35A5370ULL, 0xFAA9C79DBD5D5794ULL, 
            0x816D257799158CC5ULL, 0x57B129BCF6659704ULL, 0xC6F3CF2F693C7630ULL, 0x1AC255CFF44A24AAULL, 
            0xA500051E49DA090BULL, 0xDD814AAEE0FA56D5ULL, 0xC9F8D9C011E8EDD6ULL, 0x74413AC8A5167985ULL, 
            0xE55BFBD24C5B808FULL, 0xA25FA003BFD2945EULL, 0xC370A74FF1E26B23ULL, 0xA0F7ABE8F7441D4AULL, 
            0x0A83F8F5E0A420D5ULL, 0x5AED8EA39A9787A7ULL, 0x34B05AECE8C3CC3EULL, 0x44E47E15C105378BULL, 
            0xB7079CF4EB264563ULL, 0xA936548664290A0BULL, 0x32803A8FEFD0E554ULL, 0x812624B959728345ULL, 
            0x90C7D47EFF17BE31ULL, 0x9106DB6A782012C3ULL, 0xD360CD758753386BULL, 0xA3FEE47139DD7FD4ULL, 
            0x498FFAE389A0E9A5ULL, 0x70CA088E86D07660ULL, 0xAA56338CFFA5B9D3ULL, 0x1E37CF94D9F0F3BBULL
        },
        {
            0x778469A65F590135ULL, 0xB695ABC8E398CD11ULL, 0x3189A0290317B725ULL, 0x8225CFDE02AB2A7BULL, 
            0x47EFDEB190619AE7ULL, 0xF46E56F994C48A4EULL, 0x8503768898626EC6ULL, 0x1B194B16B0707DB9ULL, 
            0xCE2D8157D9654E71ULL, 0x78874DC8900C67DDULL, 0x0640821D9C82C289ULL, 0x62793C6CCAD183BEULL, 
            0xE7B001DCD3243C31ULL, 0x03677C21B3509520ULL, 0x7091D6AD1609BCCDULL, 0xD6575DF77ADD5AD5ULL, 
            0xD63B55050ADFADD6ULL, 0xAC0F3363B2239C00ULL, 0xAACDEC1C1457350AULL, 0x4BAB0F3A3924FEE6ULL, 
            0xE53FFEE4423924A5ULL, 0x297E4D9AFA1DD97AULL, 0x14AF3AC5DB4FF7D0ULL, 0x883A4811E3EAF860ULL, 
            0x24393B17FE8D51E2ULL, 0x23B2F650CF089827ULL, 0xF3EB4883D5688434ULL, 0xCB9124FD9A949254ULL, 
            0x8B7503E9664F740CULL, 0x70D8F80243249F1DULL, 0x6AD20F6070AD43FDULL, 0xC81D1217B3C76945ULL
        }
    },
    {
        {
            0xE412DF685A86D541ULL, 0x4F5CF653FD9FA150ULL, 0xF18624CCAFEEF557ULL, 0x4D1538CE41962E9CULL, 
            0x52D2C0618DFF565AULL, 0xD270D35E41989857ULL, 0xAC790594E6A49198ULL, 0x39171F3FC40CACA0ULL, 
            0x75239F3686831A55ULL, 0x57E9FC5A982B71FCULL, 0xAAACEA2D8D86CE4FULL, 0xC004584C30AEBB62ULL, 
            0xF5736EE96CC45E05ULL, 0x74DEE9C9A2AA324CULL, 0xFB80D3693084D771ULL, 0xC192222CB56E851DULL, 
            0xEABBB153D060CF99ULL, 0x9CEFE14FD0C6FA25ULL, 0xE12CD48A8DF8F7C1ULL, 0xC6FDA73CD28AAAC2ULL, 
            0xC5EF2DD5D9F919F8ULL, 0xB039542DB18E2100ULL, 0x436778346FD04825ULL, 0xCCF6D95D6AE17F97ULL, 
            0x5AC38AD4393FE8FFULL, 0xFDF8D11DF9E649F1ULL, 0xB7D484EC5F8500E5ULL, 0x191957ACBC518766ULL, 
            0xBA3D0C94C7626C8CULL, 0xB73FB301E7F88AA3ULL, 0x5688388D5D60585CULL, 0xE4BB8723337F8CDEULL
        },
        {
            0x7849765AB1F25291ULL, 0xA490AC3DC61A0906ULL, 0x6935B38D292558DCULL, 0xA2C4C183E08834DFULL, 
            0x617F59EB3E77B859ULL, 0x3F483562CFFD9270ULL, 0x3DDAAE92BC7EAFDFULL, 0xEC4FCF3E110155EFULL, 
            0x2691E4461B8F7A22ULL, 0xB0E302D00BB599AFULL, 0x2311200D59A42B30ULL, 0x6B2E4EC1064015E7ULL, 
            0x149298B4586A4C44ULL, 0x47471A726A2AD8D9ULL, 0xA023076DCDCBB781ULL, 0x1B59249EC738CFEBULL, 
            0x87AEB44112DC214AULL, 0x574D5536FB8A5CE9ULL, 0xA2EADD489F69294CULL, 0x0BC15FF51D87BED6ULL, 
            0x0CB27665750F973AULL, 0xD00DD151C643ED6CULL, 0xCEF0B1BC1FC8903EULL, 0xBAF5F65E1E31D4DFULL, 
            0x0D67F1E384192309ULL, 0x45615D60C302DC99ULL, 0x040A840E1D51B745ULL, 0xA23E63EDB2488D0FULL, 
            0x6CD3B5203231191EULL, 0xDCF8066BB4652E5FULL, 0xA2EA025655904A0AULL, 0x5342F1F99AC60A8CULL
        },
        {
            0x01A14B9C884AD6A5ULL, 0x478FFE0F527A115BULL, 0xB6B75370CADB72DBULL, 0xF165FC5341EC9D3CULL, 
            0x7CC2286B04E6FC59ULL, 0x9E9262E4AB6F1FFEULL, 0x8C4036FB83088609ULL, 0xCB963464E52C9131ULL, 
            0x8B366E5CF68F1E64ULL, 0x5B107692A2E10BD7ULL, 0xDB1C4B7DA73B3AFAULL, 0xAD828769448CF1D6ULL, 
            0xA75D985DCB763351ULL, 0xD868B4BD3CE16F27ULL, 0xE89C33E27F9F2FD3ULL, 0x3245911E8C822CB8ULL, 
            0xC8954094B89C8A47ULL, 0x96116D7995F19215ULL, 0xB9F901AD71FD1C6EULL, 0x3CD485C1C3A81EC8ULL, 
            0xAE5B9AC7B6E7806AULL, 0xB51F130FB3EA4742ULL, 0x7F109F0D0274A640ULL, 0x5A57696952E8705DULL, 
            0x1A73F3AA35D64C8DULL, 0x56A064494D0BDE37ULL, 0x0C8C271EBA4636CFULL, 0x3151E7BC94AC527AULL, 
            0x1FCCDC08E1C75A73ULL, 0x2A70026DA91EEFE4ULL, 0x86FC5A45E9F98C32ULL, 0xD56FAA8E6A8591B2ULL
        },
        {
            0x93803572528DA452ULL, 0x7FFE49CA0079C218ULL, 0xDB700C70BCCDA2F2ULL, 0xABE64650B3ABB57AULL, 
            0xFF199710FB5ECC28ULL, 0x9715CC854722F709ULL, 0x7CF9EE685CC8C562ULL, 0x847E6F0590C5AB54ULL, 
            0x9629EE240756D341ULL, 0x6093FE98A748E056ULL, 0xEB9D15749296773BULL, 0x233ADAF875CCC4C6ULL, 
            0xC1612AA52C3C2952ULL, 0xC0F6050AC3F12B0CULL, 0x4E6BA49705CBC34CULL, 0x0B0EFB3D43CF2183ULL, 
            0x4666C3D6EABB772DULL, 0x825A3721151E69DDULL, 0x4872891F44101800ULL, 0xA4A0BD2D4FE9053EULL, 
            0xFB281DABAF735C4DULL, 0x05F912568854AABEULL, 0x09CE92A48D2D588FULL, 0xCADFBB88DA7A267AULL, 
            0xA4EB802A2B3E1789ULL, 0xCD48C0C277CCF254ULL, 0x89781CB51CADD8D1ULL, 0x97E48DC642C5B08CULL, 
            0x440173C5EE5BD5E0ULL, 0x647F9062DA947A18ULL, 0xA89DE249B37DDB8BULL, 0x17F15541776BF49BULL
        },
        {
            0x39DCD39EB655FCF2ULL, 0xA539E57A2B785765ULL, 0x235A6E7C2D6C5912ULL, 0x222F6EF7B7F2CE3DULL, 
            0x00FDEDAA2008BB8DULL, 0xD07F7B29D1B8A703ULL, 0xB8D8BC0B59385F90ULL, 0xE10974C7D1911922ULL, 
            0x21DA21A60ACD37E3ULL, 0xD273FAFFE3BDC318ULL, 0x9AFD7111AD0C882CULL, 0x09FEFBC05D524D76ULL, 
            0x43C2C08C1A2FB61BULL, 0xD72066246DC3C37DULL, 0x12B5A8073AD95284ULL, 0x17CD5631615811ACULL, 
            0x8C7DC688608B1D52ULL, 0xB044A4F2255039CEULL, 0x430477CBB027397EULL, 0x984771196CEA36ACULL, 
            0xF19A055E1D5CF0C9ULL, 0x5784FE971ECAD8B3ULL, 0x80690CE487CFEFA3ULL, 0x83CD003316234874ULL, 
            0x17DC6F65FDDC57E7ULL, 0xE3C3D1FB2C48E528ULL, 0x1452830D9CC8D4BBULL, 0xA80B314DD941BBEBULL, 
            0x19EC2246F90F4E5DULL, 0xE6F9642EC1797A12ULL, 0x09BD3B52C1478AC8ULL, 0x38B1BABBA916C537ULL
        },
        {
            0x1FE8E00D6EADFB38ULL, 0x0BB4A1BF60F5FD03ULL, 0x33ECE39C183B8121ULL, 0x2251D45766C5BE1EULL, 
            0x626AD501CBDEF0ECULL, 0x2425FD3D8CFF1541ULL, 0x33842E616D0B2EBDULL, 0xC783C3BCDFCF503CULL, 
            0x3EEB58618D0D276AULL, 0xD1E123E85216361CULL, 0xE4D0F2A44766ADD7ULL, 0xD1344806663A9B5BULL, 
            0xE79057AC50623E4AULL, 0x4ED4283F65D8F13AULL, 0x160EC5BBF9AD8D73ULL, 0x8AEF6BBC53343BDDULL, 
            0x75A6A4DF962C00AFULL, 0xEE9E76D215A43C45ULL, 0x240C6166F4ACE3BCULL, 0xEE2F8DE3303CE4F6ULL, 
            0xDC371B3E622EB0DAULL, 0x86038CCA8C4512B9ULL, 0x70780995CF586DB5ULL, 0x0D324BDE56A970CEULL, 
            0xD8097409FA324EABULL, 0x2406078043E7D72AULL, 0x98322857E75E9E85ULL, 0x2B7E0DAEC8421ED2ULL, 
            0xF42F701B48C68D6AULL, 0x1406D43F4DE157FDULL, 0xDCFC67E8B057081EULL, 0x2E05E50844D96129ULL
        }
    },
    {
        {
            0xC94D282F574A23FCULL, 0x5CA9EDA0D9D53E1BULL, 0x2CB84E5B3CAACA57ULL, 0x40E4E9B8DA0B2889ULL, 
            0x1293E17F8C5921ACULL, 0xB65A6427F374951FULL, 0x70C662DE0798DA11ULL, 0xDB84F0564688AD44ULL, 
            0xFE33AA8CC40444A1ULL, 0x1E13D9FC2E621FE0ULL, 0x5C571DD185858D30ULL, 0x5749BA0BBDE30D63ULL, 
            0x82B1750A36C7D513ULL, 0xC4DE34A231B94C31ULL, 0x16DE5928C9CB3F2AULL, 0x9C9152F985C207A5ULL, 
            0x1711632CD9B102B0ULL, 0xC41652CA943C4665ULL, 0x56D0260421F96269ULL, 0xF4EACB5BD2721C0CULL, 
            0xB7DCC3EDE579E2A6ULL, 0x0AD56138E1DC019BULL, 0x688AFA5BE364095FULL, 0x5AADE9F071D3F632ULL, 
            0xCD0F64FA3CB26A08ULL, 0x4D39FC1C4A0E6BCBULL, 0xE25561FAB123A0D2ULL, 0x19FCB82832DB8A6AULL, 
            0xCA0FCE3286BC7021ULL, 0x98BDF7ACB5F682A4ULL, 0xED5A4EA44EF7F23CULL, 0xCD1FD62953D03F9AULL
        },
        {
            0x383B15805091CA46ULL, 0x4132997BDBBFC257ULL, 0xF3EB9EA788BCDB95ULL, 0xB5E3255FBE18B8B9ULL, 
            0x50118FFE8F1797FBULL, 0x8E670D2BCC1640D8ULL, 0x1673B738D6C04EEEULL, 0x0A805A76686EC578ULL, 
            0xBB8D24591DED94DDULL, 0x4209B5BA95CC543CULL, 0x536A98FB7FA50FE9ULL, 0xAFE0A263F78248B6ULL, 
            0x2389DE1A0B2BEB4FULL, 0x2F1E7322E5779DE9ULL, 0x9256D52C6030682FULL, 0x9AAD119D11C817CBULL, 
            0xBC356DDEF1CD8785ULL, 0x665D323543D9CEA9ULL, 0x994D3F72C43433ACULL, 0xE2FA05A272F7C71FULL, 
            0xA1198A6501BD9E33ULL, 0x5AFC485654B66C4AULL, 0xA37EC6D5A859AD68ULL, 0xF954527AA085C559ULL, 
            0x13694F70A050C61AULL, 0xCC58B543C29B4C38ULL, 0xF318F103DB661AE6ULL, 0xD73962A69E500884ULL, 
            0xF57ED7339C0CC56CULL, 0x8D6E3CBB069FAF62ULL, 0x894BAF26A906C658ULL, 0x49C26E0615145EE5ULL
        },
        {
            0xCD0A66576F22F298ULL, 0x963AC4E913E462C3ULL, 0x03D0E0061B35FA1AULL, 0x23AA0BB4934A45A8ULL, 
            0xB44E5EEC2FAFE2F1ULL, 0x81D25DAB46FABCC2ULL, 0x14AFF88AA2DF519CULL, 0xC2E0652B0A27A47AULL, 
            0x38D14BE0DE0CA03BULL, 0x174A6D1383B638A6ULL, 0x7CD952F253293BBCULL, 0xB24B3055133C714FULL, 
            0x98AA4D23ECF59677ULL, 0x6B37A177E1BBEF11ULL, 0x5F93519A7B69D017ULL, 0xE76E337FBB8B4478ULL, 
            0xF6DE8F89D1E1DF0BULL, 0x279FEF9179948091ULL, 0x1A702D61FE397944ULL, 0xC35EC5E3A69C43A8ULL, 
            0x230199925655129FULL, 0x73B0B8951743196EULL, 0xF73D1CA939AAF092ULL, 0x7115F36C8DBDC967ULL, 
            0xAEFB5D3254BAE6B3ULL, 0x1D16FF47EB3D9A39ULL, 0x8A6DE18E9E84A7E5ULL, 0x0672A989FEB02E4DULL, 
            0x5C029195CDCBA598ULL, 0xADA9A0AE05E09B91ULL, 0x4DF3D229B15E9678ULL, 0xE4196A91693DBD84ULL
        },
        {
            0x781C2704F1FC566EULL, 0x8A1B2E8271D156E8ULL, 0x1CFF144ADCE91331ULL, 0xDF9727D3EF333ECEULL, 
            0xDA27859C83BC88DCULL, 0xB16DC1D859D02D01ULL, 0x18932829DA756CCAULL, 0xCFCBE89EAA73CA78ULL, 
            0xDEBB02D581686683ULL, 0x62D75847DB24F525ULL, 0x5CCFC8BC67EBC3F5ULL, 0xC6209251D002B374ULL, 
            0x71C3F30E49685377ULL, 0x2999EA352E3FD20CULL, 0x04523CD69B7474BBULL, 0x7439C6430BCBC3C3ULL, 
            0xD68D71C82FCE71C0ULL, 0x06992DA69A57199AULL, 0x02C97F9FB0949295ULL, 0xA4970516FB213516ULL, 
            0x1C1BC968391DD8A8ULL, 0x2FD4A80ECA4DCDB3ULL, 0x5DFDD1E5AB596532ULL, 0x9E917672893B73F2ULL, 
            0xCAE580142C1C5706ULL, 0x4EFB5720BED845E8ULL, 0x875E0694A94AF831ULL, 0x5A6D34D80CE458F0ULL, 
            0xBE420435613289D0ULL, 0xE99A041232A5917BULL, 0x54D8C6B59BE8D9DAULL, 0x0D3C5098C556E5AEULL
        },
        {
            0xA5F2433F9306E997ULL, 0x16F8E33F96584B6BULL, 0x0B5E6C85948A4545ULL, 0xB2440F1D91FED796ULL, 
            0x48F86545B81A16C7ULL, 0xF6883EB429831F31ULL, 0xCB8B0C09A1282AF1ULL, 0x817445378790E919ULL, 
            0xCCD29346DE3F114DULL, 0x8B372496DCCF4B1EULL, 0x6932F04762EA0651ULL, 0xEC497495E8553CB7ULL, 
            0x2073323EB3C5D2FCULL, 0xC739B5E33B3F6591ULL, 0xF42D5B4A790348F0ULL, 0xA7EBA068973D2C87ULL, 
            0xE1E2F546674216DCULL, 0x833C320820E09546ULL, 0x1D320BC4195F97DDULL, 0x7F001C68FE0E99A1ULL, 
            0x51BC101B46D9625AULL, 0xA624E187C4304C23ULL, 0xE48467CF8E3953FFULL, 0xA5D587E1D0373670ULL, 
            0xD2B756FC6FF28030ULL, 0xFA3C713B7AC37E77ULL, 0x9D612D969C08ED0CULL, 0xFF7538369208E3EFULL, 
            0xCCABFA116C03F321ULL, 0xA9F0C5AFAD8024ACULL, 0xB9D289A3A9355259ULL, 0xB25E2FAB86CBCB18ULL
        },
        {
            0x9AA0BF7D60B41D3AULL, 0x2E0C30B0424766EEULL, 0x91F6AB6064F8DF33ULL, 0x6563B2872383B041ULL, 
            0x687B879323E9ED25ULL, 0x3A733EC88B8DCA84ULL, 0xC0DBE6D5A41EDB94ULL, 0x2851D9A9D9EEA592ULL, 
            0x65D336884112B9E9ULL, 0x8009B3FCDCCA8260ULL, 0x7E05CD816D77840EULL, 0xF94DEEC89C0C0BDDULL, 
            0x3FC339CBFA78B38AULL, 0x6C55572A15BAED44ULL, 0x7A29B48618852D13ULL, 0x7D28CD9346C2CFDDULL, 
            0x0ABDC11860CD44DDULL, 0xEF8A4180703ED193ULL, 0xE797E6A0A3750A1EULL, 0x55A304280190438AULL, 
            0xEFF69A3D31971D47ULL, 0xBE580C6E297B640DULL, 0x09BD6E20D8AB4F37ULL, 0xE39F1E508658806DULL, 
            0x3C249614FE8704ECULL, 0xCEB3934FDBA547B8ULL, 0x955BBC1CF02FBBEEULL, 0x20F241A1DFBD7A58ULL, 
            0xD14B4FE8BE4B60B5ULL, 0xDECF3B3EF5CE123EULL, 0xC1DBE9CFD2735282ULL, 0x901D00D5602D7D13ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseCConstants = {
    0x1EF8962170EF73C9ULL,
    0x5BD02FF914916034ULL,
    0x70CBB1FE5927F84EULL,
    0x1EF8962170EF73C9ULL,
    0x5BD02FF914916034ULL,
    0x70CBB1FE5927F84EULL,
    0x8C0BBBA4935DDB9EULL,
    0x9F5BE08E7FC16039ULL,
    0x0F,
    0x99,
    0xB2,
    0x0B,
    0xFB,
    0x72,
    0xD3,
    0xD4
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseDSalts = {
    {
        {
            0x41B5C1D0D04C8A2CULL, 0x85B2BA1667193670ULL, 0x81B62260A69170CEULL, 0xFA50C19B8F123A99ULL, 
            0x69692439E0BD626EULL, 0x7A3465B6297A539AULL, 0xB41F778C008673C7ULL, 0x5E874AD5D425FBE7ULL, 
            0x81471F8464EF5CE0ULL, 0x4AC62CBF52458BF5ULL, 0xA1421C08FBFAC1A3ULL, 0xDF8EEA31940A323EULL, 
            0x979E562971D4F640ULL, 0x082DFC418A51470DULL, 0x8981384254A80AC3ULL, 0xDEA00E32C18C4E8DULL, 
            0x23001C3530B9E91DULL, 0x8FDF910365F124C3ULL, 0xBEA424937CEC4D7CULL, 0x1305C8FD686C88C9ULL, 
            0x5FA8038D13CCAB9FULL, 0xA0A2D4ECF83579FEULL, 0x46BDD465F7201093ULL, 0x024FB1B3970435EEULL, 
            0x8FD1755395C3E4A3ULL, 0xFBC17EF74E76B3FEULL, 0xA29E0E5079C2AB78ULL, 0x32CA5E0D5A401916ULL, 
            0xFC38B61F2434A3C9ULL, 0x6A1AEAE3050D8BDFULL, 0xB6EE259DEDD6C804ULL, 0x798F3E1D841D2CF2ULL
        },
        {
            0x51347951E02653A6ULL, 0xD925C827D59C6D05ULL, 0xC3D88DDF144D7F94ULL, 0xC24EBC925254A5C4ULL, 
            0x5C7C495449F3271DULL, 0x27E404FD259123D7ULL, 0xC577738353FAFEE4ULL, 0xED86C18E305131B1ULL, 
            0x7BA0F5B8DD78DABFULL, 0xC95B4A36C02ADB90ULL, 0x02D36EFADCB15B2FULL, 0x6486D505B507D038ULL, 
            0x5B83973E5D66417FULL, 0x20C268F6BB96B7EAULL, 0x0A12B4E2D320227AULL, 0x1EF3032F1E40E35BULL, 
            0x2BBF82AFE75996B8ULL, 0x3D578D74800639F9ULL, 0xCB0DDC4EBE4A2166ULL, 0xCE96DDE339ED1C15ULL, 
            0x104C939B092F4922ULL, 0x1A0A2B05E76FDDA0ULL, 0xA9B9AF7C04E63626ULL, 0x7D68CF5AA58A3CE2ULL, 
            0x38C938308C4F03E5ULL, 0x76B98E38F08DF850ULL, 0x19D8A6601091727FULL, 0x21F33520075FB986ULL, 
            0x8060F15F57142839ULL, 0xE273CD9B609C29F4ULL, 0xCEC11D37703A8332ULL, 0x5A593FE5C15D3836ULL
        },
        {
            0x0E22F571E6FCD138ULL, 0x6AC6C985BEF9862DULL, 0xF5EFB679C9AC8031ULL, 0x452E212DC6D4C306ULL, 
            0x0C09D9067A86B33DULL, 0x0466FAD3A81AB336ULL, 0xF0AF0794C0A2572DULL, 0x6083E21B67E5C9B1ULL, 
            0xD681EA9F0D875528ULL, 0x4494629F0DAD81C1ULL, 0xD3A9CF331ECAF572ULL, 0xBD89918F68E1E846ULL, 
            0xE34665DF233EBF30ULL, 0xD9394CB2AA75437DULL, 0xD5D809CDE4C39447ULL, 0x627DDF3415A530E8ULL, 
            0x2A741A5D21C195F8ULL, 0x227FA98505504AD2ULL, 0xD7809AECF5E43C85ULL, 0xBAC3A34BF7F20DA3ULL, 
            0x061C716A3C21E0BAULL, 0x8F214ABA4F810363ULL, 0xA6E7AF76F8F9E943ULL, 0xD51E066C30D9E788ULL, 
            0x52B4EDB16327C8A6ULL, 0x50379211F6FD79D4ULL, 0xCEB8B825C8527591ULL, 0x3F76E4D60AAA8B14ULL, 
            0xB52C9BECC12737CDULL, 0x28E924F8985EBAF4ULL, 0x38763687CBEF56C3ULL, 0xF7C69DC8BA1B4106ULL
        },
        {
            0x53F8EFBD054BC32BULL, 0xD59E904228AF3055ULL, 0xAAB5DF66B00CF306ULL, 0x38C7722164924239ULL, 
            0x8CC23A184B3256AEULL, 0x2BFE72E7F841DFC2ULL, 0x0A676191C48681B8ULL, 0xB9C78112D0D28EE0ULL, 
            0xABD9D73B10DA753BULL, 0xB6994FC57157F04DULL, 0x5DB021DD7BA63545ULL, 0x54922E656D860A6AULL, 
            0xBD2C0C8409B5ADFCULL, 0xDB199AAAA8B4404FULL, 0xEEFB0D2375DB5C8CULL, 0xBFA9EE80ADFF31A0ULL, 
            0x7CC6661A62BC4DE4ULL, 0x62E03CE7F705A0A8ULL, 0x3A7970A750504B4AULL, 0x766A8B10595D63B1ULL, 
            0xDB8A915B341D0B82ULL, 0x1D40091AF1D7C99DULL, 0xF44651F49B778DAEULL, 0x1DF3F59BB42B0324ULL, 
            0xC434003193E406F7ULL, 0x98490E51B70969FBULL, 0x1A4296FC6BE9887BULL, 0x595B92463C3F3B77ULL, 
            0x0E70DC096C63DD0AULL, 0x47695EACA39DDD93ULL, 0x3C72A78C7FE004CAULL, 0x16C479FE44C75F0DULL
        },
        {
            0x008AF8E1429FECAEULL, 0xB0788ECAD7EA1E62ULL, 0x166063CF098FAEAAULL, 0x620B9DE7D1C39B50ULL, 
            0xC67A83E27DB3A1F3ULL, 0x3A8DA0E3AB1C2333ULL, 0xAC549FF13766C896ULL, 0xBF3D06FEA7F51C7FULL, 
            0xBB2C456D6ED61DBDULL, 0x9F711C769579ACBAULL, 0xCDC7EA18A3A0A404ULL, 0xE4FC8F44D6348432ULL, 
            0x8A80FF33CBF03697ULL, 0x1DD1113B8A39DA51ULL, 0xBFEE8310B3824522ULL, 0x8746D3F9AF300E01ULL, 
            0xB76A3C662BC41121ULL, 0x5441D900A79D27CAULL, 0x8AAF5FF9780E3451ULL, 0x0D053172EB330C8EULL, 
            0xF912FCA46684DAF4ULL, 0x4A8DDFC9C521A361ULL, 0xA3A163370B6BE436ULL, 0xFCCC4306116A7335ULL, 
            0xF3C0E3DE88808A54ULL, 0xFFC586F280BAD17BULL, 0xD01F0D2BF7354B4FULL, 0x2A57B6949B6D2D06ULL, 
            0xF52916E3037E88EFULL, 0x1E0BEE84B03D9D02ULL, 0x95655D3B2AEF1EF2ULL, 0xC2B1092076EE3253ULL
        },
        {
            0x8DD134DD471921D0ULL, 0xFECC4F5DE16F7E59ULL, 0x7232C0F206EAA156ULL, 0x85F34D7C1BF6B632ULL, 
            0x90586EFE93F98B2DULL, 0x9BE2A68EAD77C10FULL, 0x2561345EF294AF04ULL, 0xE21CDE97EE65CAB5ULL, 
            0xFDB3B2FBB598CA77ULL, 0xF28086D56C9FDA7CULL, 0x2290386023258FBCULL, 0x8753A2F2D76F8C29ULL, 
            0x1BD984CCA9166DE4ULL, 0x43270197CBF9A518ULL, 0x69CB4C8D50ECA29CULL, 0x7762F80FF70F9C7EULL, 
            0xEFD537A03FCD7681ULL, 0x73B87EB0B33CDD6DULL, 0x788F09B39018D223ULL, 0x7B5E930572B16ABBULL, 
            0x45CDB071B4E04699ULL, 0x642C0433DC8133D0ULL, 0x4656E6D290B634B5ULL, 0xC14DF7F7930906DAULL, 
            0x3C45E09D7035061AULL, 0x7BCF854AFD882FEFULL, 0x3217078FEE3B56ACULL, 0x611D9580A7169D99ULL, 
            0xF0682CA96C317252ULL, 0xEF1BB77D5A379047ULL, 0x0C6398439BAF5674ULL, 0x7FFF5300F3DC33D0ULL
        }
    },
    {
        {
            0x8676FAFCCEC98CDBULL, 0x81C3E1178E7F2D1AULL, 0x1EC079EC03AF6C80ULL, 0x758979BD8ED55D28ULL, 
            0x62C4444202995652ULL, 0xEC3EF93A327720C7ULL, 0xACA43A0501FC7F62ULL, 0xE9A5E436EAD007E6ULL, 
            0x97C94E7F5307C0C9ULL, 0x60A130D470448DB4ULL, 0x6F12A81B5013A482ULL, 0x7B09ED42E8C4D33CULL, 
            0x13A580F84200EF81ULL, 0xDFECF19A9EE57A80ULL, 0xEFEE30830B4EA929ULL, 0x40931379BC2E43C1ULL, 
            0x31204430995B006CULL, 0x3ED18D6F2290EB83ULL, 0xE0CC75EF7EEA663FULL, 0x037359957EB6A0ADULL, 
            0x4C13B93598627718ULL, 0xD86E965747D4804CULL, 0xF4194A999D654EC6ULL, 0xF888B8B78B3F211EULL, 
            0x0F1231267B80160AULL, 0x5CB087B1570A74B0ULL, 0x855037FBEFC88B21ULL, 0x64B3478C55BE0D9EULL, 
            0xD392EEC5AF967FDAULL, 0x0C3FEB472CE4B16DULL, 0x28ADC462F446CCFFULL, 0x050E3F0A3A1FD3A5ULL
        },
        {
            0xAC153F1A864704FEULL, 0x6CEDF4C0703874F9ULL, 0xA3C1094ACAAC7FEEULL, 0x6C6D76EFBC2700A5ULL, 
            0x13752430F9284BEBULL, 0xD48994CD8BB9421BULL, 0xB2328E797DF62086ULL, 0x3C6B99E4CDBBCD9BULL, 
            0x4E6187FB597EFF4CULL, 0xC4C47DCC44425487ULL, 0x5779563D27BDAACCULL, 0xF23ED31552B3E08FULL, 
            0xF9C2425BB3515BC8ULL, 0x1DD5CEB979739101ULL, 0xE902D22DB835E957ULL, 0xEE318E6C0A956480ULL, 
            0x13442E1A75EF6F58ULL, 0x748EBFE2B4FAA650ULL, 0xDA95088B50CC9687ULL, 0xB03FE89963A4AC24ULL, 
            0xDF2470389C3EFAA7ULL, 0x69C3C4DEDE6269F6ULL, 0x45BA6D064C6C9D45ULL, 0xD0632998B1A0D78BULL, 
            0xF6FB33B2BAF7CFCBULL, 0x76732D1A880B0A07ULL, 0x5E0AC95F378927C5ULL, 0xA59E1026313D80A3ULL, 
            0x2B8E33F5A0291B9EULL, 0x96BFC5D2DAB6B8F1ULL, 0x0ED53DF68B621E05ULL, 0xD29C7CACD00CBBE4ULL
        },
        {
            0x87C2684F50BADF25ULL, 0x081881B43CD76BE0ULL, 0x9A6BE4BED4C31653ULL, 0x7CDC6FFC4801C8BDULL, 
            0xCA4E574DD1B5502FULL, 0x2C091F5CD53E48EDULL, 0x8BD72EF505702CF4ULL, 0xE61C4C8584D0C0F2ULL, 
            0xBB99354EE6E7C2BFULL, 0xA571C3EE54FD9386ULL, 0xF761BB9A7C4CCA2EULL, 0x586171F98D2149B0ULL, 
            0xA889F1E92B21ABF3ULL, 0x9B57F0A0CB4E3B9AULL, 0xC95D4E24037EED3DULL, 0xF3D9EEBC8933627CULL, 
            0xFB81290452AF249DULL, 0xDC2CB632AC46D9EBULL, 0xD8B5EF8756F51571ULL, 0x021F8ABBF69D8373ULL, 
            0xC17AFE975EAAD1ADULL, 0x5673FD7184A67D00ULL, 0x89B1BBB59FE44086ULL, 0x10ECD24E786B1063ULL, 
            0x4EFF3D3E9724C0FDULL, 0xA9A885F3DD8A80AFULL, 0x4767C7795F801066ULL, 0xABF0F2B0D9290A9AULL, 
            0xD0581B1771947BBCULL, 0xAB28FB1B1DA51D24ULL, 0x6688EF958D2ADA72ULL, 0x28BEB4BFC9861D85ULL
        },
        {
            0x713DA1CA13D2F1EFULL, 0x140F4ACED6598B9FULL, 0x03A0B06CE9B28448ULL, 0x7E47B7F66FF84C83ULL, 
            0xC7744568DBB1F87EULL, 0xB72473A78872FA51ULL, 0x66D197F651191929ULL, 0x6B3B6A32EDC41FAAULL, 
            0x788823B53CF44AA1ULL, 0x1788AB6153941E81ULL, 0x366B86C0C94B2D1FULL, 0xA6FAFC2B81847C0AULL, 
            0xF1750065069BA8E6ULL, 0x6A90E0B72AA9A23DULL, 0xF3E8F95A6CE7EC6BULL, 0xD6DFC14D0E39F136ULL, 
            0x86C14797C2F9E1BDULL, 0xB75868D77DA5D56CULL, 0x18BB0E01187B5C90ULL, 0x828CEF9FE015B4A5ULL, 
            0x15FA12C29213D617ULL, 0x338EB07D9AAFFC81ULL, 0xF3043CD1741D8E4AULL, 0x9B8CC95FAE0CB29DULL, 
            0x65D77B33A50236C0ULL, 0x0789FD5D0474DDD9ULL, 0x81E7704E952BB4F8ULL, 0xB963AFFAA5905F6FULL, 
            0x8DBF7B8803F12D8DULL, 0x89B2FA52C075F9A1ULL, 0xD8308B3795D18A9CULL, 0xB0AFF9E50BED2E55ULL
        },
        {
            0xD87F05841EB0715AULL, 0x7C95891E0D6276CCULL, 0xED80CC86EDE93640ULL, 0xE1BDA329BECA3F22ULL, 
            0x3CBC370B29295F9EULL, 0x5946CC70AAF3F3F2ULL, 0x6ADC2711C2DDAFACULL, 0x602593ADC6233E09ULL, 
            0x90EE8AF3E892FA56ULL, 0xBA62C7707B35374EULL, 0xDFC7C9EE41479B71ULL, 0x63C024610EE3C768ULL, 
            0x7812B7F733C068C7ULL, 0x54F253F61D24C064ULL, 0x9A20B23C386075A3ULL, 0x31F875BFF2AEB7F8ULL, 
            0x167EECEBF3B06576ULL, 0xA90539DF5669AB3AULL, 0x4B4FAF273DF69289ULL, 0x5E2F7F735F65F04DULL, 
            0x43B559CAA31D17E9ULL, 0x0A5E8C273144CBD1ULL, 0x8C583D7EB44FF802ULL, 0xC3F74D787252BF9CULL, 
            0xA77C5E117BC73F8CULL, 0x86BCF7AF98396CC4ULL, 0xA24B50ABB282C39FULL, 0x9A88BB4262FC7051ULL, 
            0x195C23B4BA206A4FULL, 0x42185CFDFF123F8DULL, 0xDFDE2C27E65A4CE3ULL, 0x7542E77885A28FEDULL
        },
        {
            0x513B2FEB07733E54ULL, 0x5A75668F34C0C7AAULL, 0x976203587B750C27ULL, 0xA92FF074B3E8DEA5ULL, 
            0x4AE11296467F83C8ULL, 0x0244D346C6C166F9ULL, 0xC3A4B6303B16B09FULL, 0x871F57FE1A261065ULL, 
            0x6A1027ABB9365CBBULL, 0x546CBE046BD9A038ULL, 0x64C3E990B74AB8A0ULL, 0x38F7AB88DF0A4239ULL, 
            0xADE8B84102299DFEULL, 0x0C5533B3095086E5ULL, 0xE2F87B69272EC26FULL, 0xAC76AE1F633B3713ULL, 
            0xD4DEE43F715D377EULL, 0x975615D555C74380ULL, 0xA773A4B7AA1B303AULL, 0x93B7C29248A724E8ULL, 
            0xA88B829F7107474DULL, 0x8F9B5F58C23ECD0DULL, 0x993387CA7F07BD9EULL, 0x5BD42942320E71BEULL, 
            0x66FF79AAEFB53F5FULL, 0x380030B404215836ULL, 0xC2B4E0C966122646ULL, 0x70E4E7C973F5A0C2ULL, 
            0x6C3319E1D1DE4EAEULL, 0xCAB3601B9BE6135EULL, 0x1C3A57820E9770B6ULL, 0xB286A2329D4397CCULL
        }
    },
    {
        {
            0x5B8A27FC06C2F151ULL, 0x6D4D535455C7CC97ULL, 0xD7E4CB351327C8EFULL, 0x71493386400AB157ULL, 
            0xCB32DCCDB7AFD51EULL, 0x3B6B2F70051EF8A8ULL, 0x02A0355A703EDA6DULL, 0x651241B17530BE78ULL, 
            0xE255FE5A2B5245B1ULL, 0x665AD5CAF4A1EEB0ULL, 0x76182635AC8E5573ULL, 0x539D4ADEAEE48E61ULL, 
            0x073DC9E35ACC8FBFULL, 0xDDC546725843D133ULL, 0xB779C135E1BFF8A0ULL, 0xFFF6D01FD5D2756BULL, 
            0x7605BF08BAB7F0A4ULL, 0x5DEDAE2B2AEE85DBULL, 0x968A3D6E2EE7C174ULL, 0x931BD90D850C58AFULL, 
            0x63D86FD4F72A7538ULL, 0x26CB90932A59485CULL, 0x96BEDEEAD4A0A5CBULL, 0x742FB98C3CC917C0ULL, 
            0xD1164D223B82BE9BULL, 0x28883A10A396DD8FULL, 0x7E1062E11A05D2E9ULL, 0x34BEC9C1B23970A1ULL, 
            0x4D414EB889AC538BULL, 0x1790D9CE92629C48ULL, 0xD1461AD91DA7BD1FULL, 0x8B068D73CFB3BBAEULL
        },
        {
            0x7ACF94C98FD49160ULL, 0x0AE057169AED729FULL, 0x700815D560C994AAULL, 0x3F944914CA732C96ULL, 
            0x75C37F9164D2113AULL, 0x8DF6C8E23AF934F9ULL, 0x69E13AD40435AEA4ULL, 0x91D1BE75DB038DFAULL, 
            0x7AA840E56B628709ULL, 0x90F95DA9212EB224ULL, 0x69D1D04206934E08ULL, 0xF2ECB438797CEE23ULL, 
            0x8A267B4CEC076FC5ULL, 0x1E73C0D011D021EEULL, 0xB2C9F2E731BC996FULL, 0x1A667707417A9656ULL, 
            0x054EF267028309FBULL, 0xDB16B4989E29950CULL, 0x7690232A53A8EF4AULL, 0xDBB9C801F6CFB243ULL, 
            0xE59AF2EF259C0EEDULL, 0x5A8AEA13DE657263ULL, 0xAB04F67AB40AC97EULL, 0x0BC220790756E0BCULL, 
            0x47240D79665BF128ULL, 0x7161E1217DB5A62EULL, 0x8BC076BE8BB964EBULL, 0x124DAC6CAD5C59A0ULL, 
            0xEBFECE3D51303F94ULL, 0xC92B8D4732EFA5A2ULL, 0xB5E449E919A3D7F6ULL, 0xA78381BEC27548DFULL
        },
        {
            0xF3BF3BEB1B948E96ULL, 0x62CB2632CF55DD56ULL, 0x07C7FD8237B9D1BBULL, 0x7367CA33B25CDF00ULL, 
            0x08A3DC433F33CEF3ULL, 0x5CE277CA21C5D076ULL, 0x086181E500CCA3E4ULL, 0xB58D836F1FA95C2DULL, 
            0x0C20C551412E56F2ULL, 0x3B1A5BDD7700D2C8ULL, 0x9B967ECB1FD8FCC3ULL, 0x12C68F558E3D8F8FULL, 
            0x6DF5AC93126EDFA8ULL, 0x784AE3ED78444F3EULL, 0x123AF5479BF00D21ULL, 0x7FCB342858ADFC50ULL, 
            0x7B88E2847AF4EDFEULL, 0x1EB2084C216F31E4ULL, 0x0FFC7A312C9DF4F3ULL, 0xFC8228C9E2FFD2DEULL, 
            0xD22E9F66FBBCFF8BULL, 0x1582DB0293AD27BDULL, 0xCCF019562CD89FEEULL, 0xB8054ED1A9957FB4ULL, 
            0xF58369B875047BDAULL, 0x172DA706FF84E79AULL, 0x84CA23475402D8F1ULL, 0xB94A2C38EF70C8EAULL, 
            0x24F7350EEB51A8A0ULL, 0xFA09F3B2EB796065ULL, 0x286E5BC2D8260162ULL, 0xF246C19292CE58A2ULL
        },
        {
            0x91CF013D3FB55A33ULL, 0x8FA3BA45C77AC014ULL, 0x6BF0FB7E227C0383ULL, 0xA8BAE83386592652ULL, 
            0x82EEEEBD7A3CB92FULL, 0x7CA9F0269DDCC341ULL, 0xE2161F7C9A4E05EEULL, 0x99566DB96EB71D37ULL, 
            0xD99B5A383A06D947ULL, 0x0DF3D8B313B2E0F4ULL, 0x2BA4D94359B26C1DULL, 0xCCFD912EBE7AE070ULL, 
            0x52FA232D46FA86ECULL, 0xDF62E8E3C0626C30ULL, 0x97B70F6AFC69E775ULL, 0x0DA3CF71BC8B8930ULL, 
            0x54BF71D0EF0E49B4ULL, 0xC2599BCBF556D6A3ULL, 0x8080AF5860C145D7ULL, 0xDCE19FA7E8AA8E1AULL, 
            0xDD7A9CDEBD578514ULL, 0xEE7ABCBA7315FC3FULL, 0x911093E22DC90C2EULL, 0xBCA18D0834646AB4ULL, 
            0x0FB26F567BB4BBF8ULL, 0x0FAF2814DDC09D70ULL, 0x683A846108FCE87EULL, 0x62F09ABD3C09EF68ULL, 
            0x02378FFAC02809E1ULL, 0xFF25C6DF9BA4F4A8ULL, 0x265737A2727F1751ULL, 0x716D7258341EE1CBULL
        },
        {
            0xFB58B06ABABF5A61ULL, 0x304FB899A1263044ULL, 0x69A0F9F95193D14EULL, 0xCEEE818FBF495E17ULL, 
            0xA3228F9472286F23ULL, 0x610EDB37188147EBULL, 0x35E141179B7FA7FDULL, 0xE85A7EEBC2F5C892ULL, 
            0xC6CA6AC04D810EE0ULL, 0xD4754DCD719D47F2ULL, 0x08C1CA40CEF94285ULL, 0x1B44C9733DEFBC21ULL, 
            0xF416CBA15485295CULL, 0xF4B3494508802BBAULL, 0xB5934ADC2A81BB31ULL, 0x5A9F740F00BEDECBULL, 
            0xE556F9D3C37F7EB5ULL, 0x375F59E7ED7DAD36ULL, 0xA908D242505351A3ULL, 0x43727B4BBBEE4799ULL, 
            0x834930141492D199ULL, 0x88A8DCFEC059749EULL, 0xDB347FD17648E4F2ULL, 0x05751D1E5F7753CBULL, 
            0xBC312BB9E06C0C5EULL, 0x6443E2BB23271FCDULL, 0xB6925646BB90C058ULL, 0x6FB9E0ACC13694BCULL, 
            0xCD102964B6323C56ULL, 0x83D60A78D4782758ULL, 0x0B12E786AED3FBAAULL, 0xA396296BE4781DEDULL
        },
        {
            0x614F501D40F2511AULL, 0x4B51D4683CD4F53AULL, 0x3F5FAB0E1CFEAB7AULL, 0x9F3BAD441DA3888EULL, 
            0xD33E28BE2B0FE9E2ULL, 0x3F039AF1DE6106EAULL, 0xA84C6DB03036B294ULL, 0xA2402E0E7E28EBF8ULL, 
            0x95903262584D59B4ULL, 0x402EE5F3116B0B47ULL, 0x8ED3F522DD05C333ULL, 0x7D8CBEBF7644CECCULL, 
            0xE10EF8B63A2772B1ULL, 0x9256D6A41473E171ULL, 0x837FEDF15B85FB73ULL, 0x6AA72483BC6800C2ULL, 
            0x3D4B1C7418031C8DULL, 0xAF2173EF4379B336ULL, 0x6B450CC5B66A0A04ULL, 0x3B103F0B55F65FA7ULL, 
            0x5E8DE7D38436133BULL, 0x429F5E4F68DB059DULL, 0xE8B1FDC3A62BD124ULL, 0x036229E4522CA422ULL, 
            0x5604C861A76EE4EDULL, 0xC5D368D3D08AB999ULL, 0xF52ADD501AE81FD7ULL, 0x888536325BF25C97ULL, 
            0x415273C759938059ULL, 0xDAC4C87661A4F8B2ULL, 0x0A5EDC161829DDDDULL, 0xD4967FAFD93B2ACFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseDConstants = {
    0x87F9DDCD89E90915ULL,
    0xEA4388DF8B39BC9AULL,
    0x97A812F79FC3AC9CULL,
    0x87F9DDCD89E90915ULL,
    0xEA4388DF8B39BC9AULL,
    0x97A812F79FC3AC9CULL,
    0x73DD473BCDB92342ULL,
    0x9A11737510FFE210ULL,
    0xCB,
    0x48,
    0x49,
    0x5E,
    0x33,
    0xE9,
    0x35,
    0xA7
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseESalts = {
    {
        {
            0xEB9957866F71B689ULL, 0x22EAA5D07C7F53F4ULL, 0xC7741958959FBEBAULL, 0x111096BFFD630EBEULL, 
            0x5FB5A645142D623BULL, 0x98D85EA2D631F752ULL, 0xACF02663644C0577ULL, 0x8CD79962B2CDD35CULL, 
            0xF2F58FCBA898CE86ULL, 0xB7B90B5CEC93EE23ULL, 0x60E44BD42C63B057ULL, 0x0DC194C5765C6CC9ULL, 
            0x702247C10E321DF1ULL, 0x2B89BA4B27B7E2ECULL, 0x92F30A3A9766AFE7ULL, 0xBBAA75358CE1BEEEULL, 
            0x7A8F2EACC5C23264ULL, 0xFBD066B347D81009ULL, 0x30F5A708D7695DC8ULL, 0x19C8C98B61622BE1ULL, 
            0x30199BF5380EFDFAULL, 0x4AEE48E56814608AULL, 0xBD586431B7ADF291ULL, 0x2094BB3A1C8570E8ULL, 
            0x97383B08AB4E882FULL, 0x9353BAC64CF3648AULL, 0x75D3C1B2339CC956ULL, 0x9891CE00E34D8CEEULL, 
            0xFAFF2ED0B0676136ULL, 0x00A01944FD24499CULL, 0xCD02B2176149634BULL, 0x2FC25F8A089E9C09ULL
        },
        {
            0x0707C16F1E7E2D24ULL, 0x87B4FD52B0BBB2DCULL, 0x8AB6CD2D8B79B6C3ULL, 0xECB382F35F7A803DULL, 
            0x2E2DCF4205997CADULL, 0x1A2034FBA2D52995ULL, 0xE2D7E0FF524B33A0ULL, 0x116A8C08C54E4EA7ULL, 
            0x41A1FAF554846E12ULL, 0xBA3431AB7D0F97F6ULL, 0x227E0D151CC31694ULL, 0x077679821F1E1E34ULL, 
            0x442618931DA31000ULL, 0xED062E36E4EE2C36ULL, 0xC8B46B28E8DB8D15ULL, 0xB403C8642A019C93ULL, 
            0x2FA917AEAACE0A61ULL, 0x32482F7072421371ULL, 0x3833EA693D2EF1D4ULL, 0xB280DC94A90DD6B0ULL, 
            0xDEEEBFB6DDFA0561ULL, 0x01AEABCA363E490EULL, 0xBD82E3633E6EF4E6ULL, 0xDCFF9150AE51465BULL, 
            0xE1CF6A42C3C5D49AULL, 0x81641DB3E576A1B2ULL, 0xE37970AF2DFC3E45ULL, 0x96BD5DFD358EA023ULL, 
            0x47AEB5AC97E89AE4ULL, 0x3F6BFA150DE5C463ULL, 0x2261F6C463E0B45DULL, 0x87155376F88A67EAULL
        },
        {
            0x3077BE5A65B017F9ULL, 0x2899E842B548ED4AULL, 0x4528DCA7CC8AC921ULL, 0x30B95D2B659441ACULL, 
            0x445939C91561D8FAULL, 0x209B1714317C9F6CULL, 0xF4C192E13B548DD5ULL, 0xDA2E66AB0B5F8F55ULL, 
            0x332E6E7BF489DD82ULL, 0xAD43C2C2A5C15A70ULL, 0x094B4E59A815D5EDULL, 0x9996586E64A40E3CULL, 
            0xC6C1B042511FB334ULL, 0x9C4BDEB68CD02A91ULL, 0x1BFB63336D89A781ULL, 0xCE05B88E4C960FBFULL, 
            0xCBA884279854EDFCULL, 0x989AAB91ECC072E6ULL, 0x46336A39CA348473ULL, 0xB0958661A6460C46ULL, 
            0xF80585F91861E104ULL, 0x4D43A71685F00431ULL, 0x38BBBE19994342CFULL, 0xF205C59FB98314FAULL, 
            0xDC92CF8D527199A2ULL, 0x7465956ABFBA2C11ULL, 0xD44E55D14C99CC8CULL, 0x069B36C7F609F1ECULL, 
            0x3692AA2799B3530FULL, 0xCA6543202579F4EAULL, 0x420AFEDB4045A5A1ULL, 0xE022846BAC107BF5ULL
        },
        {
            0xDA614254BD504A77ULL, 0xB9E5BDE060DA8747ULL, 0x005F40266679662EULL, 0x9866A13F3C04D09BULL, 
            0x5B86FECC861C4D9AULL, 0x320183851C297736ULL, 0xDAC09C6262838488ULL, 0xA6A29D1DE5590B8CULL, 
            0x05F0CE4E3CB5EB74ULL, 0x54DC8A68786CECDBULL, 0x2F44237C7E8DDA5BULL, 0x6BEDDCB3B29AE6EDULL, 
            0xB883739AFC3DF611ULL, 0x3CA410DAE120F1E2ULL, 0x2E854A1557A1B2ABULL, 0xB3A4F226A6C13F91ULL, 
            0xEC3919FF526FB4E2ULL, 0xEE2B7B5CA1B4974DULL, 0x0FA5BCBB0A6EEA3AULL, 0x68E22B25E41BE812ULL, 
            0x5DA6D22F8C7D75B9ULL, 0x5AE8BC7AAD49E41FULL, 0xA84CA8DF2A6624A4ULL, 0xD0B368B55567C84CULL, 
            0xD0AF0BBE23A1E89BULL, 0x4BFD2B8862687657ULL, 0xECA450CDD80FB2C6ULL, 0x4B7D78A385582FE6ULL, 
            0x348B5C49AB224C32ULL, 0xCC5B88E01E61BBDCULL, 0xEFA699D3514CC2C3ULL, 0x178D907641A299EBULL
        },
        {
            0xB5540D5CCA45EF94ULL, 0xEAF855173C917786ULL, 0xA5735620AABD4F65ULL, 0x4D16356CBB8CA8C1ULL, 
            0x1D08B8A25B446248ULL, 0x63C770FD06246557ULL, 0xC803FBB261A8B176ULL, 0x4D455B1207D210C4ULL, 
            0x6FD23D6492777941ULL, 0x81CD53FEFAF9809BULL, 0xCFDF0D75FEF34E59ULL, 0xC5441C12678F8C5FULL, 
            0x33F117D99448F7BDULL, 0x192E326116625DFCULL, 0x1B5FB05298C2941CULL, 0xFD80A58A0A2682BBULL, 
            0x67C17C7B4B37077DULL, 0xD84824D4B4A39E1CULL, 0x9E29C64AB159BADAULL, 0xB713D94CAF00923FULL, 
            0x07714EBF024C8F9CULL, 0xAC601F8682B0C788ULL, 0x55CBDC42014832F3ULL, 0x539661CE23832DF3ULL, 
            0x943375D151242FB0ULL, 0x0F5D90DD551E7A5DULL, 0x986A01670A0F4664ULL, 0x4CDD44903E32892EULL, 
            0x390DE69C3FBCE2FDULL, 0xF72831456CE5C41DULL, 0xEC5A827F5C056427ULL, 0x7AD2FC744973E489ULL
        },
        {
            0x4799E4AD789196C6ULL, 0x220F6FDEA97A1C07ULL, 0xC2E1FDC74530266DULL, 0x84F7C59925F00314ULL, 
            0x31F8EE0A75B3252CULL, 0x62E137DAA9CEF01BULL, 0x5152A9105810CA22ULL, 0x974EE71D56D4FDEFULL, 
            0xFAFE77CC5F827840ULL, 0x1AA69BEC5DB08350ULL, 0x99E7D71B0419308FULL, 0xDE5AAD9FCAD7C53FULL, 
            0x59D3F37495304634ULL, 0x20DFD4098742F939ULL, 0x39FF449290F0FDFDULL, 0xA84EA554D40EF3A3ULL, 
            0x8B647D44CE258F50ULL, 0xA45AAB93EF2F6D70ULL, 0xBDD9232473134F2CULL, 0x40807E6449D3FE2AULL, 
            0xC62F474EBE8C7C6CULL, 0xA93E1C6011CF4D26ULL, 0x3DA79B871063543FULL, 0x31131D15CE17D2D5ULL, 
            0x0A017DB027CF2617ULL, 0x4EB246AB4DF163C8ULL, 0x4B1C1C41189E63EDULL, 0x4A2C27014491B944ULL, 
            0x3DE6C77FF312AE55ULL, 0x6F92CEBF61540B9EULL, 0x4615BB97245A4BE3ULL, 0xEE51742A82152894ULL
        }
    },
    {
        {
            0xCE7C43E1ACC46EB5ULL, 0x080E1563046AD49CULL, 0x8D208A1A36B4F65AULL, 0x3148EAC68C1FAABBULL, 
            0x932BA696DC1CD347ULL, 0xDF121ECEB3CE084AULL, 0x58867B0C9449C4C9ULL, 0xE3C453BF381D6D01ULL, 
            0xB9EAF4D6308D03E9ULL, 0xC41796676CA4BA76ULL, 0x8FF64A7C0F8365BEULL, 0xB0FCCE108645513DULL, 
            0xB2AEA33DED3AFEEAULL, 0xDBCB07CA3C1E00B1ULL, 0x6F7C11391CE7A03EULL, 0x93ECD05A31152465ULL, 
            0xF6B666815DDEF2F0ULL, 0xD95E12D32E8946A6ULL, 0x24A4E1126FF6FAB0ULL, 0x1AAEF6451166418BULL, 
            0x6B06E9CB2B542DF3ULL, 0x74A2DC5F0F78F58FULL, 0x12C579DE14A94D9DULL, 0x14CF438A780BA475ULL, 
            0x4A560479742BA07DULL, 0xD6BAC393C073DE5FULL, 0x0D7E208308BFFBE8ULL, 0xAB83BAF7C5199861ULL, 
            0xE0609E80BE80D7E4ULL, 0xFF281091C113B20CULL, 0xF3FE883FCFB8F4C6ULL, 0xB6044443021383D9ULL
        },
        {
            0x528E75EF5C5964DEULL, 0x3DCA8E4340BC4F5FULL, 0xC1DA88B7AE0238F4ULL, 0xBCBDE4675DC18029ULL, 
            0xF51A1BD3799714C5ULL, 0xDC1450E8C6845236ULL, 0xA9576837CF19CFA9ULL, 0x747F2C7F59BCAC1BULL, 
            0xEDD79B6A203FADDBULL, 0xAF08A98B591AA8DAULL, 0xCFFFAC90AD6BD21CULL, 0x7500D4FB1EC23A34ULL, 
            0x64F19CDFA46F1658ULL, 0x40420F17E2853CD5ULL, 0x3ADA091A83DEB0CBULL, 0xC1F5C513913233BDULL, 
            0xB4291B120CBB312AULL, 0x019A9B72B44C901CULL, 0x7A87643116EE17DAULL, 0x3DC77A3992DEEBCFULL, 
            0xD1D9823215B87470ULL, 0xEBE2F395933AFD54ULL, 0x801A6EF6EF68D776ULL, 0x89BFE051C97F3322ULL, 
            0x158D28B098DC7F3EULL, 0x1715B22B1AB8031EULL, 0x0573302C8D483F3CULL, 0x925E81A44286ECD2ULL, 
            0x42D7AD1B5A30859DULL, 0x53C4147C2EC3EC46ULL, 0xF430CEC7C0A2B043ULL, 0xA93DB99A31E310BAULL
        },
        {
            0x782027AAE113330EULL, 0x48DDD52FB2B80E24ULL, 0x4076292D581522BCULL, 0x90933AECF0F5D20CULL, 
            0xAAA9CA26EF388016ULL, 0x9AF95CD7DFED1324ULL, 0x8A26377D6FAF8F72ULL, 0x249F50C8B9A805A8ULL, 
            0xFA6C9B8CADF942A7ULL, 0x87EC49F02F52BB94ULL, 0xA7D9D710C3B3E8EAULL, 0xF072AC61EA9F7943ULL, 
            0xDEEF152120EF64B2ULL, 0x6A3EE78C260FB1FFULL, 0xF2958F3F74289E69ULL, 0x46108BFA2F6A252BULL, 
            0x7DF2D8C42D969D19ULL, 0x6F6303AD0F174D1AULL, 0xCEBE95E56F3A5580ULL, 0x4BF755FE768C44EDULL, 
            0x34E62138D66F1D8DULL, 0x1789B99A12FED623ULL, 0x8F62CD2D5DF8A5DDULL, 0x84DD2962C45DF423ULL, 
            0xEC5413851EDF1EBFULL, 0x74A39F0BAAABA9C1ULL, 0x120B7C1E101483ACULL, 0x7230D50ACBD63374ULL, 
            0x0B405B75A9E57A5AULL, 0x05242B1B3C406DDAULL, 0x57434C0BA5B408B1ULL, 0xF738A2C09BB4A28EULL
        },
        {
            0x1768331C51E3B175ULL, 0x13CB9EDAC294A2DBULL, 0x44A41184A003F2F3ULL, 0x468DC616147645E9ULL, 
            0x00D2106691F4829BULL, 0x9C33D2F3BDF58D9DULL, 0xA09CDE06FDF57744ULL, 0x0BDD45E9DC54B14EULL, 
            0x98949333D9A8EA30ULL, 0x6E34B5599B17C6D7ULL, 0xA5463B8152ECF6B6ULL, 0xA1F41A6F2E193DD6ULL, 
            0xCE7DC68B0882512EULL, 0x58CAB41F3FED3E68ULL, 0xC80A76EA3A90724BULL, 0xE37D15179946198DULL, 
            0xE916191C27E29E1FULL, 0xC675057A9792872DULL, 0xA4F4E32B0B4EE547ULL, 0xB496185F6C2D71C5ULL, 
            0x706F0E0E9E9ECA6CULL, 0x84EBDA0CFBD77D33ULL, 0x3AD0833F3253343AULL, 0xE2CCDB9E0FECFC26ULL, 
            0x5F13AE052ABC4EDAULL, 0x23341E953E31CB97ULL, 0xC0D3C82B654E387CULL, 0x6D72572384552B03ULL, 
            0x25AC8AE61055FF7CULL, 0x822DD75490E8E813ULL, 0xA63BD254C6C0CAE0ULL, 0x098A16B3060CE820ULL
        },
        {
            0xBF73FDEF1C1AF27EULL, 0x25B139B5772FA81DULL, 0xBB452237C1CC16ECULL, 0x38144E1BA1ECDC3AULL, 
            0x55920DF575D658C6ULL, 0x571077365759F8A8ULL, 0x8DDA32AA0A4AC7FEULL, 0x92A2BEC866FAAD3CULL, 
            0x417BBDABA8A7581EULL, 0x7CE429674375A0F7ULL, 0x4A06EC9A610CD8F5ULL, 0x46E288CA7AE292F9ULL, 
            0xDDDE83CDC7AD90AAULL, 0xDCF372B4EC1AA72FULL, 0x3C97FF85B3357613ULL, 0x6B4D873419677893ULL, 
            0x512FEC31FFDEB010ULL, 0xB8BB186F43513207ULL, 0x559CD6A6F73D5720ULL, 0x979B26847EA6CAFAULL, 
            0x891521096FF73343ULL, 0xC06C810617F42507ULL, 0x3E5E71F09E0C5A47ULL, 0x0AD6B62FB10BFBCBULL, 
            0xBD67B8581C063836ULL, 0x35429275022E610DULL, 0xD382EE58525488C3ULL, 0x04A37FBAD352C154ULL, 
            0xB486A68040CC17B5ULL, 0x8E48C3EECAA7233AULL, 0x217204D4770A3641ULL, 0xA8FC1B11A7729521ULL
        },
        {
            0xE9D949AD3F9B8DCDULL, 0xC9185C86F2CEEF57ULL, 0x142F6C1A45A0D352ULL, 0x53E01C0D18462479ULL, 
            0xCE7C95C9BDD5210EULL, 0x8525C8E04AC69755ULL, 0x4063B9282A1FD654ULL, 0x2AD66D39F0DC9792ULL, 
            0xD8B2322B20943FA3ULL, 0x5F74F144BA52569BULL, 0x3C2544856610F307ULL, 0x21794465881915D9ULL, 
            0x60D553A8710F240AULL, 0xD52ACB1180289C4AULL, 0xB37D814A8ABABB03ULL, 0x2A2ECF0726A61CB7ULL, 
            0x11EBDB5DA6B12A0FULL, 0x79B0B3B7A282F787ULL, 0xB321A190D0631828ULL, 0x8B3ACE54F6477EAFULL, 
            0x45F33324CBA5F7C8ULL, 0x6655FABDC4B8A39EULL, 0x902FC581475FB28AULL, 0xC9A7E43CE244C7FFULL, 
            0x336CACCDCF9248C7ULL, 0xEEE964F903E76E80ULL, 0xDD19421C960A9462ULL, 0xBA60040123579AE9ULL, 
            0x2256F1C9CCB14FC2ULL, 0xB7C7B93048A8E65DULL, 0x009F261A31A0C693ULL, 0xC19BD89CDA54BAD9ULL
        }
    },
    {
        {
            0x03756F0CFA66ECDFULL, 0x10EDF1EF7741C1E4ULL, 0xF7627B9F4B0D5D82ULL, 0xBD8F22064C25558DULL, 
            0x833D472D039D54E7ULL, 0x98FE2FF5BEE27758ULL, 0x8A5EFDE984666E04ULL, 0x95250D1384FF0B33ULL, 
            0x2008AA1F87E7C7DAULL, 0xBFCEBE048A005070ULL, 0x3BDDA27096FC4C2AULL, 0x5F8D4A7D7226F35CULL, 
            0x97ED6345C864867FULL, 0x31B6F655A8D95749ULL, 0x1E22348D3A86C112ULL, 0x117925CC9E3D5A14ULL, 
            0xD23FBD1B0A4A5F4DULL, 0x9D18FE8527F6E38AULL, 0x2292B622D1B4AC37ULL, 0xFD66D71061C46209ULL, 
            0xD43A22879A996EDFULL, 0xE247439C2A5928C6ULL, 0xE9A2E80A6B8C3F8AULL, 0xF10BAFDEE06B6776ULL, 
            0x6492C16E7F34F4B8ULL, 0x9A42EA0F90FF1DDBULL, 0x852EB567E97C6F32ULL, 0x550DFDD1E937EAB4ULL, 
            0x415E6B726CEE6911ULL, 0x0D71714C9C244720ULL, 0xC7D5A11D5E08FEE6ULL, 0xC580B759ECD6CDE1ULL
        },
        {
            0xA3F15A348CDAE18AULL, 0xACB55D03A1992A54ULL, 0x6DA94C67B6A2A740ULL, 0x43D52A86D0ADB7BDULL, 
            0x7AA5DC39803EECD9ULL, 0xD8F6D35AE3CC0F89ULL, 0x943C143D6ABD735FULL, 0x5EA536A39D7688CAULL, 
            0x61DDAF654551B24FULL, 0x103483B838800404ULL, 0xB68CDAB35262C9C2ULL, 0x2EA10C029EADB6D5ULL, 
            0x36B532E7866484FCULL, 0x390160267B5B8564ULL, 0xD8EB9F08D0D16E1FULL, 0x5416A8C13734AD14ULL, 
            0x6A28EFD77D647F3DULL, 0xDB103FDC5FAB6565ULL, 0x074D8ABBE4F30E54ULL, 0x5330F3B1F6F3EF8FULL, 
            0xA6AEC97262922587ULL, 0x81A1033B98D737CBULL, 0x65A225C56861E0FFULL, 0x1645028A9E60645BULL, 
            0xFC1E63C227F290DCULL, 0x665C43EC706EEBF3ULL, 0xD16C80FC797936E4ULL, 0x00E2EB5F7B5A5534ULL, 
            0x87EE9F2FAC1B630EULL, 0xA640A441300607B6ULL, 0x18C85CE2939F43F0ULL, 0x1C1DD52CB2E8C521ULL
        },
        {
            0x575D103CD0739089ULL, 0x5FEB861C6830B550ULL, 0xC1244EC4ABC23B75ULL, 0x6694762E50623DBCULL, 
            0x7D6240DD769DD905ULL, 0xADBC4D9549595F50ULL, 0x5EF46951E081843CULL, 0xE8A1D37FC228E362ULL, 
            0xEC84BE71764207E2ULL, 0x84D5476AE58CC520ULL, 0x65D93D62D090A3C9ULL, 0xB1987EEBF890E0F3ULL, 
            0x198CCB464857501EULL, 0xF44FFB1C66CB7C1EULL, 0xCFB6F3E9166F94A8ULL, 0xDEBE7B56653AC781ULL, 
            0x9E0719EA49BA48B3ULL, 0x5626F39E1C27C3D3ULL, 0xF4E842ED6BAB8C91ULL, 0x27C13DE3EA26428DULL, 
            0xABD4F11C6EA68315ULL, 0x9C8784822D1E9788ULL, 0x994E9885907B2183ULL, 0x2DCB947827C998FCULL, 
            0x495AB9226B65514DULL, 0xE46EDF84A5076645ULL, 0x39D6DFF75D4AD0ECULL, 0xC4AC57DD1DBA40A6ULL, 
            0x11E05D70EFDBA693ULL, 0x9FD6F8B44C3D6257ULL, 0x57718E6670F5CC79ULL, 0x2B8E2DE2122E91E6ULL
        },
        {
            0x1586AAEACA965CFCULL, 0x9D2A77A2DD6E4B05ULL, 0x1154D35F4A094D97ULL, 0x3B7037D222C0AB50ULL, 
            0x35F129F3AB686504ULL, 0xE7B26C2A859A7097ULL, 0x273F3E09EA046A32ULL, 0x890452202CA90342ULL, 
            0xE8D030A0E830427CULL, 0x1CB42C6B4E247B17ULL, 0x01E2B4A7C3111BE3ULL, 0x4460959661BA9F05ULL, 
            0x51FA9D8E15B55216ULL, 0x2BE071F1BB99FC7BULL, 0x657E1262F225A075ULL, 0x5F12DBD27F2D57DDULL, 
            0x0EEE633686625EAAULL, 0x60FBCC9970EBF895ULL, 0x5F342F4970ECD321ULL, 0xFC0D605188089A05ULL, 
            0x6A886D776B29C328ULL, 0xE7854490A2C0CDDCULL, 0x29BB30D247662144ULL, 0xA2D900176BBFA647ULL, 
            0xECA3387072DF645FULL, 0x25646DDA12EF8611ULL, 0xA415E08A7290C36EULL, 0x05D4A76C6C1DF868ULL, 
            0x729ACF7F8CF35A36ULL, 0x9C0942DE060F759BULL, 0x3DCBF5162D1903CCULL, 0x920B17D1D24DF61FULL
        },
        {
            0xA1FD92DA48FEC21EULL, 0xAAB026A1D4751F2FULL, 0xBE688D58C9B4A888ULL, 0xB74A796CC9F5DFF6ULL, 
            0x84D0E48FED166608ULL, 0xD94EC07ECD556BF7ULL, 0xD0379B173CC85FCFULL, 0xB03ECE1FBD378F45ULL, 
            0xA43040686113A1A9ULL, 0xD0E343D018F308ECULL, 0x1F23C2A4835E51FFULL, 0xD78CDEF12036497EULL, 
            0x2F52AB35621B1D72ULL, 0xDD1F5CDA146134E0ULL, 0xE2572A4F676F086AULL, 0xF4E01752C8C4C70DULL, 
            0xD0A7E67F5890EB57ULL, 0x2CA62AD3434CE803ULL, 0x193F64EF9352E837ULL, 0x640E0ED200C9BC84ULL, 
            0x78D029F8A9C85EF4ULL, 0x73344829F57C08ECULL, 0x72D336D4EEE60A49ULL, 0x3CA9201030B8E5D5ULL, 
            0x75FFFCA82667DEE8ULL, 0x4C883D1CEDACE832ULL, 0x38E5ABAFCFA90718ULL, 0x19330E0F5EB05E7BULL, 
            0x9D0B238910982D7DULL, 0x642AAA5473D3AE1CULL, 0xBDDE0D383BE457F5ULL, 0x9FD65B6189FF77A0ULL
        },
        {
            0xC68E27B6A9F31A5AULL, 0x4E9DFA8E16DE2B18ULL, 0x227D431458299516ULL, 0x6E60C7EFB40CA791ULL, 
            0xBD102DA08C2406A3ULL, 0xD7AB2F578DF81AFFULL, 0x787157E3A8E6EB65ULL, 0xE494423DB3DF3BDBULL, 
            0x576C8B37673C782CULL, 0xBF412AD219DFD49FULL, 0x265286B56A84345AULL, 0x18A9383976552025ULL, 
            0x8B1D181E1054D75AULL, 0x1FF0E59096DAB347ULL, 0xBB63EF070237CABEULL, 0x3EE9014408CC5E05ULL, 
            0x1BCD7D2D53856B9DULL, 0xFF0FC120785BB4B0ULL, 0x409B92133CFC83A2ULL, 0xF068D4B775E9638EULL, 
            0xDCDBF5A6B70FF485ULL, 0xC1362B71F750A733ULL, 0xCDFFA574255FE76BULL, 0x9739ADEBCF1F9F18ULL, 
            0xADCFC46D1767D3ABULL, 0xD459ED720F97C183ULL, 0x28ABC4877F295E21ULL, 0x2E008A81FF37758DULL, 
            0x84D603AEB16666D7ULL, 0x94820828D897044EULL, 0x0444A4D5DBADA242ULL, 0x81FFFE895FE20627ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseEConstants = {
    0xBE898C8FBC368FF7ULL,
    0x2E6B34460B9D8B43ULL,
    0x4BB0AAF65A914412ULL,
    0xBE898C8FBC368FF7ULL,
    0x2E6B34460B9D8B43ULL,
    0x4BB0AAF65A914412ULL,
    0x629CE56415CFB0FDULL,
    0xE0FB1B60E7B0737EULL,
    0x67,
    0xB8,
    0xF1,
    0x44,
    0xE6,
    0x03,
    0x54,
    0x88
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseFSalts = {
    {
        {
            0xF03AE4A18837E20FULL, 0x2216D99EE6CF7D05ULL, 0x035C5DC7E0A6F143ULL, 0xBAD631D08AB905EDULL, 
            0x2EE58B844DECAB8BULL, 0x754F08CCFFD6B942ULL, 0x6DF8DA460D5F193BULL, 0xB18FA8925A1D1C4AULL, 
            0x05EF92DD157142D8ULL, 0x6AF667E51709561AULL, 0xED3B945EE879FEC3ULL, 0x56AAA4CF23958E3EULL, 
            0x32ACCF1933BD652FULL, 0x732891C6B9A2E2FFULL, 0x1EA78DC55561C11FULL, 0xC001F3A6CDA5442FULL, 
            0x9E2C16A5F2F1FB7CULL, 0x8ABBB4FE8AAD9F5DULL, 0x6AAE1D30447EC9E4ULL, 0xA719096CBD98C009ULL, 
            0x638C6DAC529F9DB8ULL, 0xA03CB2AAB0CF33E1ULL, 0x8788BB966722DB2EULL, 0x2149CFE7E84AAD05ULL, 
            0x7DC87BFD5D5F261BULL, 0x8C9EF590F31A9F0CULL, 0x9730965967C556D0ULL, 0xFD2AC74F844FAB9BULL, 
            0x760D120C1BDF43CAULL, 0x088A17D45E9B2D45ULL, 0xE4B4D241AE69AFC3ULL, 0xC995CF181EB84F9EULL
        },
        {
            0x55840AF5C0C4815AULL, 0x98A98EF02C9070BBULL, 0xCA9A2F7D2D0B1650ULL, 0xBAD90A7F12320C56ULL, 
            0xAC360C67DC7DA45DULL, 0x81CE873D3068DA7CULL, 0x38F335933A104196ULL, 0x6E5C58DE808A20BDULL, 
            0x2939B1C1077B7965ULL, 0x1AC7A542BC8BBABBULL, 0x8EA7DE58131D2D3BULL, 0xF8F857A1E03F616FULL, 
            0x3C11F37784303127ULL, 0x6AC7D85017E1A829ULL, 0x1E763F985CE59510ULL, 0xA55534D1B188ECE2ULL, 
            0xB1F898B9D46DC4E9ULL, 0x1D204C2440BD49FDULL, 0xEFFB6D795D1CD6FBULL, 0x43BE7A14DE3A7218ULL, 
            0x1C0DE2129F3F1835ULL, 0x5558F31D95ABDD71ULL, 0xE8FDF0A3C0A587C1ULL, 0x8694D137B2C9B4ACULL, 
            0xBD7C7202D9F61985ULL, 0x45EF22876E1FE9C5ULL, 0x556C5DDDBC1393AFULL, 0x4C64C209728B9F9BULL, 
            0xBDE3210BC589105DULL, 0xAB497CE2A0A71258ULL, 0x44BB36AE0AC9C499ULL, 0x86111A3D87288042ULL
        },
        {
            0xC1CE98EEF3290878ULL, 0xC7CD21F44DF3CCABULL, 0xDE7BAF6101C59D04ULL, 0x52216A56DD741145ULL, 
            0xB5432B6A45867CB8ULL, 0x705C4BC0B1543745ULL, 0x8582CCBF153C1171ULL, 0xFD5036B0EDB4E03FULL, 
            0xEAB35FACECB83544ULL, 0xE106D710692E29A7ULL, 0x7F9B66EC4392E63CULL, 0xF4F07594AF905F1DULL, 
            0x46DA28E5B789FEE2ULL, 0xFD91EA4D931B8C6DULL, 0x7F24A6062DB8A49AULL, 0xB9B0AAAB0CA7CFD9ULL, 
            0x30E13FD0ACD0423FULL, 0x949456B12AE9B188ULL, 0xC65873235AEF2C37ULL, 0xFFC39F3D0A6E5AD8ULL, 
            0x25B0985C7C83D14CULL, 0x5998964E9EC34E70ULL, 0x8206A33E767B2A27ULL, 0x98D4CE4DEABEE954ULL, 
            0x60ED0346816831D3ULL, 0xA8DF42EF16A8EF15ULL, 0xE28C979309F64C8DULL, 0x858B2B560B12846CULL, 
            0x52E91277205E8CE9ULL, 0x15BAF6B256A87600ULL, 0x4CFDE9014487DAA3ULL, 0xB3663F8ECB895630ULL
        },
        {
            0x6E56F5CAA52F150DULL, 0x6D8D9E791D680D9FULL, 0x99DAE8FAB7F8C8A2ULL, 0x3A7DFBDCAC8AF746ULL, 
            0xA2C0DF28F8F03A93ULL, 0xAE66FA5BB3A18773ULL, 0x3749A7FA434D052EULL, 0x0A02559178351F16ULL, 
            0x4A950412D84CACC3ULL, 0x84656EBF40B6283AULL, 0xED4D55F7AEE06312ULL, 0xEB8053F77B6798E2ULL, 
            0x54F1CA7498C290E3ULL, 0x8AF990BF2196ECBEULL, 0x4E0F2F54269910C7ULL, 0x04AD3165CC76E592ULL, 
            0x25D11FC4F5A32752ULL, 0xB74F5775E44B781CULL, 0xF8FB82220CCFCC3EULL, 0x914C7A755E46D749ULL, 
            0x17045C7DA402AF74ULL, 0x4665240986AD7E62ULL, 0x31586A71AD01B31CULL, 0xB29DE9852818D567ULL, 
            0x85D1767AFCAC9090ULL, 0x6B277BACF95ECEE9ULL, 0x5A31DA5107BD0454ULL, 0x52DC52A92A0B26A4ULL, 
            0x60ADAC304022928AULL, 0x29EE70E4B904A5A7ULL, 0x60D528AB4390F80CULL, 0xEE77F6B49FFC691DULL
        },
        {
            0x154F42F8557D3326ULL, 0xEF7CEE145F44FCAAULL, 0x6ECC1CA55CA8464CULL, 0xF4F1CCEC4CEE414FULL, 
            0x93DF9DD9F8F87B99ULL, 0xD86F32F9A7E0C8E7ULL, 0x911FE815E2E407A0ULL, 0xF0B3C58F5B9E3CB1ULL, 
            0x4108927B4B5B23EAULL, 0xE154C328B511991BULL, 0x1E078C9E50B9AC7AULL, 0xE0457128614510C2ULL, 
            0x3B3B48BE938214B1ULL, 0x793A48C28E3B86A5ULL, 0xF91F2654E95058C3ULL, 0x964391B0F21BD8DEULL, 
            0x227A0CF49CBC2736ULL, 0xB5393D714EC6132CULL, 0x957E6DC1775282A1ULL, 0xD84E524C9D93CA8FULL, 
            0xE721985D5E56606AULL, 0x1E0DD757038C2163ULL, 0x254B2BD0F9447C69ULL, 0xBD7B8E5FC0B9ACA1ULL, 
            0x395A1A2D083D034CULL, 0x19EC6D85C1C580C4ULL, 0x878146B5172D27CAULL, 0x7409B0C76F2FAC73ULL, 
            0x2B77A70452A04527ULL, 0x6E92FA316D9AEF9CULL, 0x8649BDAA44BD736DULL, 0x586FBA15F038F1B1ULL
        },
        {
            0x87B0E1746208961EULL, 0xA36505C9D97A4C24ULL, 0x747DBF1972883199ULL, 0xE67023E579767265ULL, 
            0x25B5118AB40EEA18ULL, 0x791BA1CB83B17CF1ULL, 0xC683F9C93FDEE787ULL, 0x82AD324FE02456E2ULL, 
            0x4A758CB5FE3CC52AULL, 0xA1227F1DEB213E51ULL, 0xA8642858BDD83CBFULL, 0x29E8058058F4B4AEULL, 
            0x7B139688E9B68313ULL, 0xCE397A4DF43321F5ULL, 0xF9C11E098033610EULL, 0x9A8A9FA9F0ABA48EULL, 
            0xF6A5C5AC40B6B572ULL, 0x1F47DE3804C0D027ULL, 0x772A9AC0A6963F01ULL, 0xFC65CC3595B3B6F3ULL, 
            0x7E430AAAB66364C6ULL, 0x20F938E5087334FBULL, 0x850688D074E05C39ULL, 0x001967C8EC6BE740ULL, 
            0x06E4BA06880C77D4ULL, 0x4A36DB14AAB8869AULL, 0x65AEC85323E81F81ULL, 0xE3FE320786226394ULL, 
            0x23C1D019B2387BEAULL, 0x27CF782EE650BEBBULL, 0x74852F7460FF6F1CULL, 0x7DBE982BFDB143DBULL
        }
    },
    {
        {
            0x1F2C2ECC96186C7FULL, 0x2D2F8E3B16A655E9ULL, 0x7C9163730BB0959FULL, 0xDF4F39CF33880921ULL, 
            0xCAE0A3202AB46DDEULL, 0x14630DDCD39F9C23ULL, 0x525800B0DD789FFBULL, 0x004C702CC41356D4ULL, 
            0x0839F736BDF3F0B5ULL, 0x3B84560A4ED0324EULL, 0x7954E490A2859D71ULL, 0xD798C0DDE75963C5ULL, 
            0xD7D505D0179F298EULL, 0x9D7C6289FEC1A50DULL, 0x03D391414AFB33D5ULL, 0x6A71BE3CB6E2952AULL, 
            0x7C1EF19490B01531ULL, 0x8004E88378499879ULL, 0x6EA4B8E8200B6601ULL, 0xF102563C06AF2EC8ULL, 
            0x9D624097171C5443ULL, 0x9DFA6EA005DDEBA0ULL, 0xE736D9A478AA43BCULL, 0x47340D7E8816EC04ULL, 
            0x5BBB0B93CBBEFB91ULL, 0x015038146C96A636ULL, 0x2B5EACA46C5B0638ULL, 0x452A2F47B5D24C03ULL, 
            0xB86AF55124609F8BULL, 0xBF6D92454D3BF359ULL, 0x27BCC2446993F00DULL, 0xE9E81E550B3F630AULL
        },
        {
            0xA909709187E27A34ULL, 0x107350256FB5A0E1ULL, 0x444C796559D5F698ULL, 0xFEAF9A8A19C9CB29ULL, 
            0xC9070DCBE34BB07FULL, 0x261BC82865389FF1ULL, 0x2254E1BC4AD343CCULL, 0xD0070617EAE757CFULL, 
            0x46AAF7CF0A5D5CACULL, 0xB24E52117FB1EAC8ULL, 0x823578389DDE663EULL, 0x2C7C450560406842ULL, 
            0xDF63C978E67F6395ULL, 0x36A29EF0292CE384ULL, 0x635078F63091A3B9ULL, 0x384CD54C3E693F48ULL, 
            0xB141A447C601DFB2ULL, 0x84A4E65591AA2191ULL, 0x67AD7927B9C1AE6EULL, 0xDC52C51C3D476407ULL, 
            0xA83F0C2BCBA2E361ULL, 0x2151E5D8A7EE5EEFULL, 0x1132E9ED8E7EE2E3ULL, 0xC520AE839CEB619AULL, 
            0x853BC9F33EE2AA92ULL, 0x10DE8B7B64E8779EULL, 0xBD7ED0170137446CULL, 0xD6F1A8F29CC10E75ULL, 
            0xBC9A5E7BB87BF485ULL, 0x65D6EEBDF187E23AULL, 0x5D5C2AF4147D9C6BULL, 0x8C233449EB274177ULL
        },
        {
            0x9C80FD7239687F51ULL, 0xD2B304A907C7080FULL, 0xE770DE36C6692DA8ULL, 0x1AC16A70FC8595DFULL, 
            0x2DE49553600DAAD3ULL, 0x6729F21B383C091AULL, 0xB08FC388B54A6C89ULL, 0x91DCA65E30CB21F6ULL, 
            0x8881F883D151AF59ULL, 0x6545A2D807F49169ULL, 0xBC9689023EC44C98ULL, 0x52AC0CBE85E84465ULL, 
            0xD0EE1EE0B3805BA5ULL, 0x72801B7C7179824EULL, 0xF94EAD1A15F8FB39ULL, 0x43C7C8A7C585D9FCULL, 
            0xA37E33C081160833ULL, 0x1D94CCB1B90730A9ULL, 0xAA13FC8E374A2489ULL, 0x74EA152AB73B93B9ULL, 
            0xE331EDDD29BF65D2ULL, 0x5D8D86BF76E1E7F4ULL, 0x57294F8D0BE24B34ULL, 0xD45EC8E247CDDB7BULL, 
            0x2B0AC1D3D5BC123BULL, 0x7C1310A2C110F418ULL, 0xBEA41014E0754796ULL, 0xCEB229F246AB6B28ULL, 
            0xFF71B8F96FBA2203ULL, 0xE68D8C83D0CF6041ULL, 0x1B05D330FBB4BCC1ULL, 0x9DA97B14D29AB988ULL
        },
        {
            0x41CFB69DFFE3413FULL, 0xE7A58B3373AD0F5FULL, 0x66B2FEAB1D7A1E41ULL, 0x20CE544F7BC6295AULL, 
            0x653E4C461184A496ULL, 0xBE1D0D5270FAD397ULL, 0xA9CD321CE37CE449ULL, 0xD6774CBC01B75029ULL, 
            0xA26EEFE18CD98C17ULL, 0xBDA1507447F61375ULL, 0xCFE5BB73328ABFB2ULL, 0xA1822C63121ACE03ULL, 
            0x9384503EAF996455ULL, 0x96EC7D96E252EAE1ULL, 0x5A4325D264263804ULL, 0x60491679B24E746AULL, 
            0xBE8F942923A9AFD7ULL, 0xB9A032809FB7BAA4ULL, 0xFC4DAE11475FC042ULL, 0x863DCF828F6D9312ULL, 
            0xB824BBDEAFE87930ULL, 0x59607B36603F8688ULL, 0x73513678FB63CE0EULL, 0xB1AC18A1239A0A80ULL, 
            0x38AD8D368AA3D54EULL, 0x027B034690240891ULL, 0x9865A7072EAF267DULL, 0x8E0D8E53A19D258FULL, 
            0x8DFA9E6A82661993ULL, 0xAF2E52BF2822BBD8ULL, 0x620C11B14971B197ULL, 0xC5BFB2FB0B07FFA6ULL
        },
        {
            0x1E58A643F6D0D5EAULL, 0x7F1A7709DE70DBC6ULL, 0x436EEE499A6D4643ULL, 0x21D3429BB22002FAULL, 
            0x239326205B3B2D47ULL, 0x4D6BF3E6057512FEULL, 0xEE41062D614D9905ULL, 0x9858325844BD4419ULL, 
            0x6C93E3C840A62382ULL, 0x508F4A7DBD505010ULL, 0x4317AF176897C133ULL, 0x7DC6FAF1458017F5ULL, 
            0xF2914C5D22FC9329ULL, 0x87F9EB12AB4B42EFULL, 0xCFACB4E905EEB95DULL, 0x7830543FA2059E14ULL, 
            0x69C2615D7C0DBA21ULL, 0x44A0A5CC2D2607CCULL, 0xE35C25C84FA075A0ULL, 0xE4818B462356AC73ULL, 
            0xFC52C4F10C1F1E82ULL, 0x9ECD4DB67DAAB499ULL, 0xC6636AA66916FE6CULL, 0x368E15882DBA0740ULL, 
            0xC25547A6B1BEC89CULL, 0x2CC54ECAA32C001EULL, 0xA7AB0C358BB2021FULL, 0xCA5149C218774AC1ULL, 
            0x34FAF889C2E8B02CULL, 0x6DC1EC528B1360BFULL, 0xADD140AC5D52DD93ULL, 0x43280137A8B2A0DCULL
        },
        {
            0x137A91510338419CULL, 0xD8FA6253BF25B903ULL, 0xA98D7E605FF26E58ULL, 0xB8E9F2CC2A9804CAULL, 
            0xD63AAB5D60FBADC1ULL, 0x2ACCE2A744DEFD88ULL, 0x3F20E6DD70BFA3D8ULL, 0x1C73F9E5D7578790ULL, 
            0xC8C13C49640B59BBULL, 0x3DF3592F7D6D9743ULL, 0xEBC3FAF859A242A9ULL, 0x5C1B953D856A8039ULL, 
            0x4A9DCF13A76CDACEULL, 0xA72C60C5433436D2ULL, 0x6A448CD3F88DC9F9ULL, 0x8084EA926AAAD39EULL, 
            0x8B306D56DFFF6C26ULL, 0x4B4917B05D98AABBULL, 0x1BB1683EA7EAE3BAULL, 0xAE2D6C50E68F6471ULL, 
            0x0AAB2E9AA3EC746DULL, 0xF83CAF2F0DD95166ULL, 0x4DF471BA09C087ADULL, 0xB1878507C343CE75ULL, 
            0xB0BBF7E6A7B72F7DULL, 0x770857AFC9479A53ULL, 0x77524E362D5F2661ULL, 0xF919366BADC729A8ULL, 
            0x4441E61F67FC31E8ULL, 0x5F10A46AA64BD954ULL, 0x18DD655F02386BA5ULL, 0x89F017EA010DBF00ULL
        }
    },
    {
        {
            0xA1E77B5902320810ULL, 0xC27C74433A1ADEC4ULL, 0x04152D84457E79D6ULL, 0x16B10FABF75D2F6AULL, 
            0xF01D3D32369F4744ULL, 0xA63AAFBB908267ECULL, 0x2EA0270EB94C107DULL, 0x9610D3E0C4F46E88ULL, 
            0x0D26F836E9A8A98FULL, 0xD656CDD85DFEE30BULL, 0x118FE4B0B693617FULL, 0x55A67F3134206831ULL, 
            0x96D7C8D669C141F2ULL, 0xE7C05E6C49928586ULL, 0x652E1FA113AE0CACULL, 0xBC4F054ACD2B6021ULL, 
            0x71E3B03D325485D3ULL, 0x64A60326D4E66CD2ULL, 0x8AB9A251F48AE7F4ULL, 0xFD10D5F0525BDA79ULL, 
            0x2516A79DA7378D2CULL, 0x354C5A30D82DBD3CULL, 0x6F5B605424A001C6ULL, 0x605DA9A1A6118F4BULL, 
            0x7129CB2F5F80F479ULL, 0x532F69F28EC15996ULL, 0xBCFEFAC2E3C581A7ULL, 0xAF8D28D7EA26F6D1ULL, 
            0x6624F0D4CCA50F13ULL, 0x6D2CEB7BD9E913AEULL, 0xA8D5CDE4FF880D38ULL, 0xE3289AE343D17415ULL
        },
        {
            0xCE991B4232FEE400ULL, 0x85B2AA834B9E684FULL, 0xABCFB8D896133344ULL, 0x714FE950C19CEE4CULL, 
            0x359C3CA7AC48D7C3ULL, 0x3F59F26FA541A10FULL, 0x1850FBA03B3A1D98ULL, 0x0B41C55CE3B744C8ULL, 
            0x3442106A429D33A4ULL, 0x8AF4260ED85EA652ULL, 0xCE4DB13B4DBA4C32ULL, 0xCFB0060DE4BAE38BULL, 
            0x89D0AB015C03AD7FULL, 0x04C2FB81DF39AFC2ULL, 0xA9562080E1503EFDULL, 0x050B2B92E3B82FB0ULL, 
            0x39D57684B6F1A005ULL, 0x011706928545C3B6ULL, 0x3E81E7A09C58EBE7ULL, 0x4DA0F1F8BB32F8D7ULL, 
            0x93A80728CE453887ULL, 0x72E66B4977B32C5BULL, 0x5E143B1EFE6C3FFFULL, 0xFD199D1CF9B07AB3ULL, 
            0x6329E744CD78DEEBULL, 0x4E6869F0989AAE0DULL, 0xD3FEE31253358ECDULL, 0x3AE90C3CA116AE7EULL, 
            0xDEA358A06016A8ACULL, 0xFF340140E76538B7ULL, 0x981D409A5736E263ULL, 0x3E91E07F1B80845DULL
        },
        {
            0xB83C275EDE442BFCULL, 0x7173FB49D3627C2FULL, 0x1DCA891EDE636C90ULL, 0x0E7E19D934D66785ULL, 
            0x16D7FCAB65C66D13ULL, 0xD0C5BC849C5549E7ULL, 0xD853F4150E9C69DDULL, 0x264B7D4970CB05D2ULL, 
            0x89FB7782E1CF1E2DULL, 0x0C2A6BD6B34A845EULL, 0x38CB42B0CC026014ULL, 0x6DF67C3D1AACA268ULL, 
            0xB1FF6C6E7D073EFFULL, 0xD1496AA7D9CF3A9EULL, 0x6576A955224DADBBULL, 0xC294CCB1E5240926ULL, 
            0xC0BD21FAA1544FC0ULL, 0xCAF92048D4E12C72ULL, 0xD226B0AECF5E55B6ULL, 0xEEB5EA0C6428E58DULL, 
            0x1DB6E27E52BDE34CULL, 0x1A69B53743E3479CULL, 0x79875D2569FD9357ULL, 0xC0C85F68461E830EULL, 
            0x8F3CF96B29FC02B7ULL, 0x78967B74C9A26991ULL, 0x28E470EA460060EDULL, 0x7D575C5C414BF006ULL, 
            0xA6F428444AABBF8CULL, 0xCCBC6B0747B39A28ULL, 0xCA51B2C3E8027C96ULL, 0xFFD3A232E68CD701ULL
        },
        {
            0xA192F89678679DD7ULL, 0xC91D92FC4584F22EULL, 0x4F0B6A8A0697690DULL, 0xDBA0110C0C618185ULL, 
            0xA39F9896C753248AULL, 0x9661C3E2B2D4A822ULL, 0x17B9EF9301C9A0A4ULL, 0xBCAF9457FA852599ULL, 
            0x27453A97495D5DAAULL, 0x1A0CB59E6BF24226ULL, 0xB0809F9688DD2891ULL, 0xBADB05B3707DF7E9ULL, 
            0x15F0D7E19F16E971ULL, 0x2C4EE06E172CCB70ULL, 0xB7FDFC0FCA7B16C0ULL, 0x4A812778A8165CAEULL, 
            0x0461C331A530F9F1ULL, 0xADE4963A9753981FULL, 0x22132FB386F98A2EULL, 0x6BE216B7BE0B2743ULL, 
            0x989E03C205AAC401ULL, 0xC6422A037FB912B5ULL, 0xA712B3C97BC46BF3ULL, 0x00FF9342B3E93016ULL, 
            0x8FFF9D8A584B3535ULL, 0xEF6C809B4BB1A410ULL, 0x606167A64D2F5657ULL, 0xEFA450A02D1EF930ULL, 
            0xBEB1729672CCB6B8ULL, 0xD9626762B9A8B323ULL, 0x833665A3D89D4D2DULL, 0x2C11DEE00CA46F8EULL
        },
        {
            0xD6DF2FA2AC408DF4ULL, 0xDA1045CE326734FCULL, 0x0E77A79A5B7D8BD0ULL, 0x5E7E610098D46BBAULL, 
            0x8159FA7F1A3F7460ULL, 0x2F75BB454D316841ULL, 0xAFA888E92A3FDB09ULL, 0x805E6510ACFAFA48ULL, 
            0x4C1A54A411F1E3E3ULL, 0x1B201980FA71C6D4ULL, 0x3E04D03A1B4FA146ULL, 0x4EDD5E90597DC85EULL, 
            0x44BF4E7143F91B1BULL, 0xAC105E9DE687D99DULL, 0xA50F772C4E6BA6E0ULL, 0x1724D00903FF60D0ULL, 
            0x94D4A128CE16AFE7ULL, 0xCF6E8DFB307EA0E5ULL, 0x75201BE625B4F76DULL, 0xEF3BE3A86D38F79DULL, 
            0xFA7B97AFBCD6EFE1ULL, 0x6BB8245ADDCC9D9AULL, 0xC086D481F08A7ED3ULL, 0x928D0DB7A615A7CEULL, 
            0x5001FF40044891C2ULL, 0x13947104F65E6ED4ULL, 0x3939EC36D044DD4DULL, 0x6F73A704B222A460ULL, 
            0xCC88310C103118DEULL, 0xC3C5D961AD47184AULL, 0xEA9A4662AD0BC946ULL, 0x88BA217D0A9F8082ULL
        },
        {
            0x882A24AA8632EEA9ULL, 0x36A58B9DC6FBC023ULL, 0x3FAC2813D4822FC1ULL, 0xA268868E11F1B117ULL, 
            0x3C88EED59B423FCBULL, 0x2413C003E70776B4ULL, 0xCC0D51D91ED8FBA2ULL, 0x6702B355A446AD5FULL, 
            0x1C2240E0BB34BDC5ULL, 0x9331F552D823C1A0ULL, 0x4AF9BFECE591F81FULL, 0x7C5E76B2AD9833D9ULL, 
            0x4CAAA128590B6BB5ULL, 0x4FD0CC485072BA41ULL, 0x661DB6F6FBF8E6C9ULL, 0x9255527951995930ULL, 
            0x4469030904472AE7ULL, 0x640B478208B8DB6FULL, 0xA20E3D0AD01E3F4DULL, 0xBE3697181610B7CFULL, 
            0xE83BEA0629AB0855ULL, 0x6B3C830AAC0C025FULL, 0xDD103D7BAD041C59ULL, 0xE1F889C3E0C9A6E2ULL, 
            0x94B59E341481ADD9ULL, 0x92E2C4567F635DF8ULL, 0x62D3B4ADB00063E1ULL, 0x2891B960FF0180B2ULL, 
            0x84D1BBB410E4D001ULL, 0x1CCF3D1AEEC21588ULL, 0xAAA95B03A07F5AB2ULL, 0xEF8477D8AB488397ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseFConstants = {
    0x3315EF7928D1C028ULL,
    0x731C4B86CF8488DAULL,
    0x5A150238788DCB47ULL,
    0x3315EF7928D1C028ULL,
    0x731C4B86CF8488DAULL,
    0x5A150238788DCB47ULL,
    0x68F34C5AE85A5199ULL,
    0x1298F720D87675ABULL,
    0xE7,
    0xF0,
    0xD6,
    0x5A,
    0x58,
    0xED,
    0x4E,
    0x2A
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseGSalts = {
    {
        {
            0x2FF9565B99ED9E49ULL, 0xB300CB7D49C42E53ULL, 0x8304F5FD2022DBF3ULL, 0x5E9FD74FA70CF35BULL, 
            0x9C751F9641EA5DDDULL, 0x09E81FF1446EA77DULL, 0x8CA46427D34BD6D8ULL, 0x159E2F58C06F7565ULL, 
            0xA9CF2336C6F8CD75ULL, 0x6D3C8FAD0F4D6C8BULL, 0x62AF0A6F6619DD35ULL, 0x5F559174501D55E3ULL, 
            0x72623069D35F716CULL, 0xCE9A80F41CECABF0ULL, 0xD1308943BA748011ULL, 0x2CED71725E67A02CULL, 
            0x4A98D49E92C0C2D6ULL, 0xE7273A919278D80FULL, 0x7A57175CDC190E32ULL, 0x200D56019D4F05F5ULL, 
            0x8D56267783235FE6ULL, 0xBBBFC80D50381343ULL, 0x2E75E63AF436D2F2ULL, 0xE6E721F05B29A2A8ULL, 
            0xE7B03A4E1123267CULL, 0x4AD94012221AB99DULL, 0xB054FEE59E7CDEC9ULL, 0x40BE9DD89ECAD6A6ULL, 
            0x5621FC415888A584ULL, 0xB673A10BD14F2169ULL, 0x2A3BAF61E5042F6FULL, 0x2061503B5CEB3D09ULL
        },
        {
            0xF6BC3A446CE3D1DEULL, 0x632C35C49CE1BD51ULL, 0x1ECF17D2ACAAC6ABULL, 0x7F93D19C6857980FULL, 
            0xE64C762B82092DDEULL, 0x986975E459CFB3ADULL, 0xFD9F021DD4DD531FULL, 0x7A6178BE911BDCEAULL, 
            0xD77B79FF278C7D97ULL, 0x360D44ABCEFBEE77ULL, 0x4E9E7FBB291B2804ULL, 0x4349367CC756DA6CULL, 
            0x26EB23CB14E6B893ULL, 0x05A694E5C87D865AULL, 0x322872087C1E0295ULL, 0x319619DA0CCA675AULL, 
            0x3BE93F3C5FB1D594ULL, 0x9EC710294FD656DCULL, 0x91263A2F2E6840E0ULL, 0x9A3FA7CC2BC1E52AULL, 
            0x90EAE9322A5CF10AULL, 0x3C7CEF14DBCC41FEULL, 0xCD8F599D94BED0C4ULL, 0x9FD2FCC5A684EFE7ULL, 
            0xCC97995BBA1235DAULL, 0xEE7D186F52D00C57ULL, 0xD66C0EB1F4583CA3ULL, 0x6B2C79C47308D1EEULL, 
            0x4A569A689595DD52ULL, 0x4135F131E560DECFULL, 0x938AB3C74F9C2FF9ULL, 0xF9805EB11B9530BFULL
        },
        {
            0x866B1549F0083057ULL, 0x241C55B78079ED6BULL, 0x8D1A6238E5E8FFA4ULL, 0x56497A7C7E843C41ULL, 
            0xBEEC612E66DCE95DULL, 0x21F17C984C6F6525ULL, 0x2FDED86D726E532BULL, 0x915FCEED4C062ECCULL, 
            0x9668B55796A6420DULL, 0xAFD3B91E00338AAFULL, 0x2DE7DA0F693417B6ULL, 0x3942D81C2232310DULL, 
            0x66EE7B4FEB767CD2ULL, 0xD0B35FF71F09FA94ULL, 0x24817E18FAAAAE26ULL, 0x85495A015D1D02F7ULL, 
            0x5183AF3B33BC468AULL, 0xDF16FE12AD3F8FF5ULL, 0x4A0ACCCAC238D5A4ULL, 0x15364C823A512729ULL, 
            0xABB00CFCBAE3DC39ULL, 0x91F742D145817B91ULL, 0x2D501D7AB2FDE0CCULL, 0x17C647AB8AAEC2D2ULL, 
            0x0A7A92BE1D0955CEULL, 0xB5865FC57012EEF2ULL, 0x9E310AAE6559FBDFULL, 0x951856C9F5C4E56DULL, 
            0x99A3D0E92F0486C3ULL, 0xA8B9862FA46653E0ULL, 0x4D0531BB16B38531ULL, 0x5ADF63D58CFC6FABULL
        },
        {
            0xE7119363CB30A57EULL, 0xC373993299DB99F7ULL, 0xC025609F8CE1DD56ULL, 0x51443B462F434D99ULL, 
            0x5D9A1C1945F2D693ULL, 0x28C36BEF8E3E8A37ULL, 0x3EA03A4898BCEE27ULL, 0x06BB5EF457529661ULL, 
            0xBA1C15C777E402D2ULL, 0x63F88830BA3ADEAFULL, 0x6B6548A564C34F73ULL, 0xD82F973EDDC48072ULL, 
            0xAC38DBD2F8028C50ULL, 0xD0DE2D4A0AD52EA5ULL, 0x17519BFEA70A2262ULL, 0xB7059B85351A1553ULL, 
            0x2BC9259E66418F1DULL, 0x1C34DDFB048243EBULL, 0x7E1E39067F88E0BBULL, 0xD6C1C0A3515D0654ULL, 
            0xDC595B1D31CA4C5DULL, 0xD6FC8DA1A6445519ULL, 0x1CFD0DEC37D3589AULL, 0x3C56AE0515C68D40ULL, 
            0xBB1FF38B11DB7D65ULL, 0x3D4F2E90BCC0921BULL, 0xCFBDEB43A945E5D1ULL, 0xFB94CF639CC553A4ULL, 
            0x58DD93DBCFA8066BULL, 0x97820EB8FAE08C1CULL, 0x7F1726B91BE204FBULL, 0xA497E50EB73625DFULL
        },
        {
            0xB4CE41ABD253C61AULL, 0x566B02E15EAD7941ULL, 0xC8A1F5240A7827B1ULL, 0xFA972CE40FC91B0AULL, 
            0xF7DB7F6851E78FC1ULL, 0x444348F9D00C789EULL, 0x479F6DFEA3CACF00ULL, 0x2A2553B0D5F4EAB4ULL, 
            0xEC35546EB90AF328ULL, 0xB7332142473B6601ULL, 0x80F1A550585076FEULL, 0xF60C237D78AC3863ULL, 
            0x7BB654AB2DE08E61ULL, 0xA35A6D51F1D3FB37ULL, 0x0B8F9FBC3B20C6FCULL, 0xD5938E7E57F77D82ULL, 
            0x63A0FE13EBF0EC3AULL, 0x23625F3E955599E3ULL, 0x89BD3802727FB475ULL, 0x0E35738184A776B8ULL, 
            0xC4A1B41A59EF0098ULL, 0x2A905E4F1DB791C8ULL, 0x3F4C859F0A48D51DULL, 0x7A88D1780F71B2E6ULL, 
            0x0E9BF3D00355AC53ULL, 0xE6FE9A4232BD6F02ULL, 0xCEA1925FCF1533F0ULL, 0x484C94D118C0867FULL, 
            0x15A77EDBD4C5EB78ULL, 0xD523BA4A6920EDA9ULL, 0x26D1D0562241D2A6ULL, 0xC9AEB1827DB982F1ULL
        },
        {
            0xD6EFBECF2E371D0DULL, 0x3E550EDFE1E4B664ULL, 0x79389A0AC1F55E09ULL, 0x6D9D825EFE3DF831ULL, 
            0x719E887180E21999ULL, 0x9B04D667296EF9DCULL, 0x269A09933CE2AFDEULL, 0xFC65721912CCA57DULL, 
            0xBC37BF64C8265099ULL, 0x3AFB9022F609B6C6ULL, 0xF19E5241535F2004ULL, 0x090703CEC7B90229ULL, 
            0xEF599F6D8539E970ULL, 0x63B065134AC4905DULL, 0x33B872DEDCD50234ULL, 0x904D83BE76017F5DULL, 
            0xC012E7961705142FULL, 0xE91034F26CDED186ULL, 0xAC036D30BD2A3F4BULL, 0xA1498BE637E12A54ULL, 
            0x0794668EF23D5DABULL, 0x64E69323865A72C4ULL, 0xC19CAECB54EE9CEEULL, 0x19DFD9412B65D42AULL, 
            0x0B685495B31AEB66ULL, 0x22A5FD7470F752A9ULL, 0x1827CA5B4D760DD9ULL, 0xD41FF6FF1749983BULL, 
            0x25071663CA6C12F6ULL, 0xF8293C8BF84FBD9CULL, 0x641BE76D261CFC34ULL, 0x1486D14B7AD08E4FULL
        }
    },
    {
        {
            0xD2BF8CA18C8FE24EULL, 0xDB0E8481511D3B9EULL, 0xB819B0819FBA8238ULL, 0xB888218994A92A4AULL, 
            0xE667430D4C4C17A5ULL, 0x182163528FD0C9DCULL, 0xC71B99F6A37916F1ULL, 0x6CC9DF03E7A9D228ULL, 
            0xF711D2D8D6AD8D64ULL, 0xCD10E826BB55EE0CULL, 0xE694675BA9DE8B33ULL, 0xDFDB1DA095D7FC70ULL, 
            0xB2DA5D338FBA92B5ULL, 0x8913F051EFEB62B5ULL, 0x768E549D9F7938DBULL, 0xA90AC351395B8B8CULL, 
            0xC9C175ACB25F8264ULL, 0x1A6A65585D59A6FFULL, 0xC1AFBD203D0137D5ULL, 0x7862EF348411A5CAULL, 
            0x1DB38393CCD97BCFULL, 0x9955A65FF1AF8050ULL, 0x892D4020C62B1EECULL, 0x0921A623BA9B3525ULL, 
            0x4177787A8B0A3711ULL, 0x09CC418D2CF77181ULL, 0x8F20C0B04DA9AD6EULL, 0xA1D1EBA67356E7E6ULL, 
            0x0ACF35D4914103E8ULL, 0xA1A2DDF07CE69530ULL, 0x73A5516D15624859ULL, 0xEC296A13D6083ED0ULL
        },
        {
            0xD08E65AC862BFC58ULL, 0x419662ACE6FE8FC0ULL, 0x3EFB1B6FB05E110BULL, 0x5B4784AA3C30C62CULL, 
            0x971AE6D0637B8DEDULL, 0xBC93D95326CCEE0BULL, 0xAFB35B625EAB924EULL, 0xDF58D1B7B5F93F1FULL, 
            0xB8A412E05FDE39F1ULL, 0x00A882B62D5D24E4ULL, 0x0C80582412FCA006ULL, 0x3AC965D14F452DD4ULL, 
            0x65945AAB12B823BDULL, 0xB4028133E04AE30BULL, 0x9AD631FA015C028AULL, 0x65002FBF8A95C948ULL, 
            0x10C7E98E3B734DD5ULL, 0xD94F5DCEB339754EULL, 0xC9F91F48CBF60CBAULL, 0x8F74EBB827CE77B4ULL, 
            0x945141C456ACF795ULL, 0x161FAC61FD37C241ULL, 0x664CFD303745BEE1ULL, 0xA8C242D866800060ULL, 
            0x9C77EC251C3A6F5CULL, 0xB59AF4F525FB2493ULL, 0x9BD9F443AFF1F4BEULL, 0x97BDA2D7F68686DCULL, 
            0xEE8DB1313D947887ULL, 0xEE98B08E6CA8454FULL, 0x7FF7E25F7EAADD3DULL, 0x81D57605D5755F35ULL
        },
        {
            0xDC73C2A487FEDEEEULL, 0x92DC56893A2E7519ULL, 0xFDB11588D77D9B14ULL, 0x38CAE93909710DF0ULL, 
            0xAA2B35A7831DF2DEULL, 0xAEC6F050289FAB4DULL, 0xE015F9C1199A67E0ULL, 0x79E6C5A9428E48EBULL, 
            0x4C60B495A34C0205ULL, 0xBE0A5EFA2E5F89F6ULL, 0xA54A6ECBD5D99B2DULL, 0x633E63411BD0684DULL, 
            0xDB0D150E6755C1A3ULL, 0x882D071CEFE7847CULL, 0xDE84E394E8D89D69ULL, 0x89FE2173A55E6568ULL, 
            0x0099708E3FF17859ULL, 0xFD14988083387849ULL, 0x665C3A1E89B22D92ULL, 0xEE4E15F19613DFF5ULL, 
            0x285BD9E3C012D0FEULL, 0x97CC84DC2187E82DULL, 0x3A39A94042D01219ULL, 0x369151D3B1A195BBULL, 
            0x3FB2274C2A3B4CE3ULL, 0x804665A7C13F0B81ULL, 0xBC630576A8E4CB6CULL, 0xB719A82ED5F17073ULL, 
            0xEE4A2456CB61B632ULL, 0x75648F29D73B3D58ULL, 0xA1E878F2C32EACC8ULL, 0xD520177B3BDBA626ULL
        },
        {
            0x741D73D3B671C286ULL, 0xEA09E78BFEFF9F3FULL, 0x4C1EB447409572F5ULL, 0x5ABAC07D812A6B4EULL, 
            0x128F293432995859ULL, 0x2E4EC8621BC1E0D7ULL, 0x6AE965643D89EFEAULL, 0xE03FEAD353865E6EULL, 
            0x2FE9EB59DD143B2AULL, 0x224D7EFF6195A8B0ULL, 0x657F94D9EC52A17DULL, 0x46CA4E69F6AAEA8DULL, 
            0xDE3D359195699DFFULL, 0xC32706118F181E97ULL, 0x60CF89C6EF80487BULL, 0xC1D0A8B426847A37ULL, 
            0xEA0E24EF6899618DULL, 0xC59C0C7727278A2DULL, 0x616DDDD96ADD40C7ULL, 0xA2A11F9126189929ULL, 
            0x169F3E911AD795FCULL, 0x8EF7B00FE9125F01ULL, 0xDF568D22ED7CF467ULL, 0xADDA0EFD9E823AC5ULL, 
            0xB7E305D14C3090A8ULL, 0x7FB64665F748826BULL, 0x2AA75AECA9F8F45EULL, 0xE35D7979BAC8EDBFULL, 
            0xA528C97106228895ULL, 0xB61717DD91D6E423ULL, 0xC2C872A7AC303DB3ULL, 0x92CC1D334DE7C414ULL
        },
        {
            0x03161EF9F3394FF3ULL, 0xE86A86E6218797CBULL, 0x8926BACE3F052529ULL, 0xC6E8D7E66F84A6E4ULL, 
            0x8C6148EDAE7FEF38ULL, 0x1803FC9411E4DC7BULL, 0x0A8B10C44AAE6A0BULL, 0x42A8A0776DB94870ULL, 
            0xE1608BE7498BD73DULL, 0x1D157E9DABDEA328ULL, 0xF891982C24054E58ULL, 0x8CE967A8315D9908ULL, 
            0x6CC261D4C236CD12ULL, 0x94B1A0142A4ED367ULL, 0x2F73449BA8112D4EULL, 0xD0ABF2B5A70AD98DULL, 
            0x8CB0D352068A2C43ULL, 0x9CB48979A00C257BULL, 0x70EFC3ED89C2649CULL, 0x5B6C0204A1E98A52ULL, 
            0x24D8196A6266DE9DULL, 0x6CE1E56D80C789CEULL, 0x5EA7E894BF6658AEULL, 0xBFC19DFEB4363579ULL, 
            0xD41C59BE7CF2E324ULL, 0x29930F4ACA38E711ULL, 0x73B5FF1475B327E7ULL, 0x014D4F0592EF8BFEULL, 
            0x5EF7A9F8FD6866E6ULL, 0xA08BD924A465B837ULL, 0x221B85D9441172DDULL, 0x526114614F0776B1ULL
        },
        {
            0x3A8D35CE8AF97B70ULL, 0x421FB0A3614D345FULL, 0x8E6D387F0FDF7C3FULL, 0x22253DA6FB889B46ULL, 
            0x7B2B2D6AB9716F43ULL, 0x9069ADE0EB0BDD92ULL, 0xC7366B07866C4FD5ULL, 0x27F3974E4D98E360ULL, 
            0x5EF5A0F248B084D1ULL, 0x99A17A68C425AC82ULL, 0x4024EA782AFCD948ULL, 0xF6D0197A4BE1558AULL, 
            0x648338E7E230AA41ULL, 0x0F4496F09F1B5DBDULL, 0xCA425F53CFF9055FULL, 0x4C5CAF235A2B3E00ULL, 
            0xE29DA5CD8E9FF202ULL, 0xC52F34320CC06472ULL, 0xB3846A5BA62F20C9ULL, 0x003C60851414548BULL, 
            0xF18179B6ABD5CB4DULL, 0xEC590C5FD507C14BULL, 0x58FE25CC5E2C1BC1ULL, 0xD5BFFF4B9052FF4BULL, 
            0x5ABD88EDB0221A08ULL, 0xC48515465ED8FAF2ULL, 0x06CA67FF20544ABFULL, 0xDB78DE7BBC56E142ULL, 
            0x449DE81868DFA75CULL, 0x5E554873D65C6343ULL, 0x78861689E1600E9CULL, 0xE6F7B6933AA7D872ULL
        }
    },
    {
        {
            0xE08A2D1EC51BAF22ULL, 0x4C2CDA20EDBA2900ULL, 0xB0B44581FC1F8B88ULL, 0x07B77D323424701AULL, 
            0x7319F546161CFAD0ULL, 0x671F8CB821E6B6C6ULL, 0x5ABD517AB702E9ADULL, 0x8E80D4D32A6544F4ULL, 
            0xBD75A825E4BDACC1ULL, 0x3534792674F74E75ULL, 0xC4E205675D2E80AFULL, 0x7D367E4F3AB491C3ULL, 
            0x3AF3C548C46A9A54ULL, 0x40B6897707E00090ULL, 0x93DA2DD649CA4EE4ULL, 0x2F14A949F00357AEULL, 
            0x07F06A808AC8201EULL, 0x0E0904A9EC21AB1CULL, 0x97DCF348EDC851FBULL, 0x035968ED5E4EA227ULL, 
            0x302913B35BCF28ADULL, 0x8873402F27732644ULL, 0x96D10A6F53D73015ULL, 0x734F3FD74C3257F2ULL, 
            0x681EE3EFB8FB04B7ULL, 0xED124B27C76191C9ULL, 0xEE8F13BFF4C06738ULL, 0x38BC9B394EF1FCC8ULL, 
            0xDAB5969A0D0E58E5ULL, 0xE2BB8861B563DE7FULL, 0x3073ADFB7370988FULL, 0xEA68C831D797A954ULL
        },
        {
            0x109FC4DD4599D68EULL, 0x5505007188E88766ULL, 0x4289F0454EE94D4CULL, 0xCF673CFFC9707D83ULL, 
            0xC0B5C053325C9FFCULL, 0x9778A46C46D250FCULL, 0xB09F28798194D6BEULL, 0xE7269E05252CBE0BULL, 
            0x4D56B3E69E8D8B29ULL, 0xADDFF3CC92C078D2ULL, 0xE77729951F8F2D8DULL, 0x11C64403B82FE082ULL, 
            0x447B80981EAEF7FBULL, 0xCFF7915AFF85157EULL, 0x344E1733AB15298DULL, 0x33BBC9296B751C6CULL, 
            0xE9355771A07DCAE0ULL, 0x2E469E3ABEDA3A34ULL, 0x206D15202E76EF1DULL, 0xFCEE1BCEB215EC55ULL, 
            0x8161D420B86839F7ULL, 0x8F61B6300C40CCC4ULL, 0xE23F202FDB38D69EULL, 0x03EDF70F7EE4A7D5ULL, 
            0x2319757D871BEF6CULL, 0xACBDF90EE1D04357ULL, 0xC1DDBA38C9078D3BULL, 0x199D3E670310665EULL, 
            0x88AAA207D792DA8AULL, 0xD99DDA12609FC86CULL, 0xD054C440B446B790ULL, 0x9E65EA5E9896A912ULL
        },
        {
            0x577FBE197BBDC8D9ULL, 0x4AC93F3ECBEC62FAULL, 0x4CB5119FD686AE4AULL, 0x6CA7531150FAD807ULL, 
            0xCBBE4F6BFFC24038ULL, 0x1BC3CB53A3E78D1EULL, 0xFBE82CC376D33B38ULL, 0x227443EC045A40D7ULL, 
            0x13FD03872675D22FULL, 0x36D7207B38EF3B26ULL, 0x87F2B2AD1631FB17ULL, 0x6D1A3214196FA08BULL, 
            0x493405CBDACDAA2BULL, 0xC41C9CCF1A8ACB4EULL, 0x53E71E06A7977E8DULL, 0xC749B77F740C8F48ULL, 
            0x79461EEBD8A9CC19ULL, 0xAB9D716B63AD1308ULL, 0x1EB9B5C60E8D91C1ULL, 0x51BEF555EF282C84ULL, 
            0x1691DD82D5871F78ULL, 0xB50DB58A41D8D565ULL, 0x22B366A6B508993AULL, 0x6D2767B631B3E331ULL, 
            0xA663BE8A1B1BD08AULL, 0x4DDDB5F01F791195ULL, 0xF649817CCBE4249FULL, 0xB74AA72B9FFCA9ABULL, 
            0xE0AA991189DF3E64ULL, 0xA6A824523ABBB180ULL, 0xF2EAC9736E8CAF71ULL, 0x2E2C18ECE860CB01ULL
        },
        {
            0xEB982AF4B94FBC27ULL, 0x649E92C80FFC8AD2ULL, 0x9CDBAFB59CE1EC8EULL, 0x7FDC50F9E273D0B5ULL, 
            0xB9A61FEE0643A3CCULL, 0x6746BB450BB1483AULL, 0x6DB8E68A40E94EBBULL, 0x72873E4BAADA47FEULL, 
            0x57EACBBDCE8FFE7EULL, 0x73C00821CE4930D6ULL, 0x957B5D32BE64703FULL, 0xCCC5B7AB653E6529ULL, 
            0x24C5067E6F861CC4ULL, 0x621A63DD0E2FA6CBULL, 0xD86439B93EA3DA22ULL, 0x58068D1AD65E7E1BULL, 
            0x1ACFE77D1D9EA35DULL, 0x7BBF054F171825A5ULL, 0xD572C3D6781D20E5ULL, 0x4A74BFEF6BB03F8CULL, 
            0x552A303D490B8CE4ULL, 0xB700EBEC88FFF9B6ULL, 0x9A9DA023D3F45DB3ULL, 0x889AE70063D49461ULL, 
            0x60950DF9C3FA02CBULL, 0x7F0BFA39E4684AEBULL, 0xAAF749CDD013AA36ULL, 0x363D11EAF098F55FULL, 
            0xAEA857F3DA873293ULL, 0xA933C97B51688CA0ULL, 0x8DA171C80E785CA9ULL, 0x021DF7C6CC4BAD55ULL
        },
        {
            0x9EAC2202439D3199ULL, 0x4C730A38A261D57FULL, 0xED868BC6411F75D6ULL, 0xB58464CBE8ED88AEULL, 
            0xD705CF312BEC8224ULL, 0xCCBE24AA6E081866ULL, 0xFD5372B32E253042ULL, 0xEFE04CAD92F8FAB2ULL, 
            0xD66ECCBA250BCAABULL, 0xEDFCDA3881C06B68ULL, 0xC456AB6332945EA5ULL, 0xDD80AEA0DAC83BACULL, 
            0xA86C02055529B155ULL, 0x971123B98F532412ULL, 0x49D83D5C5353DE09ULL, 0x8E0927E36B210344ULL, 
            0x59755A1A45242945ULL, 0x651D1DEB3853E7B1ULL, 0x9C59267335C946EEULL, 0x429B2BCF6187CD8BULL, 
            0xF4169D6BBB4DEF22ULL, 0xE83E7065F1BE6FCAULL, 0xF1EEE58FA459808BULL, 0x25A6DC940FE0D6CBULL, 
            0xCFC31457AE9A5518ULL, 0x17C50676FA137C5DULL, 0x69D24912C710D388ULL, 0x4473B9184B093099ULL, 
            0xD9FC8407E9E3889EULL, 0xD08681B93FE323EFULL, 0xFD6E1E06FF270BCAULL, 0x03E3AA9139D8ADB8ULL
        },
        {
            0x8F831B0033ED8DDFULL, 0xF20E8B35E45EC856ULL, 0x9CAE95C02A84D436ULL, 0x4ADD7C4F91742B18ULL, 
            0x07DF7F934D5EB858ULL, 0xA350ED62EDF8DE7EULL, 0x95A2E4A19C12169EULL, 0x69E5A9AF7FECB213ULL, 
            0x695EA4355CA48D33ULL, 0x0D70580E6BB8ED13ULL, 0x7E632D0B5CA15D4DULL, 0x113498EE60825955ULL, 
            0x42209EBFC83F87A6ULL, 0xCA8E105129973151ULL, 0xF2C9846102894A74ULL, 0xEEBF4122187B4CE1ULL, 
            0xD8F63D112AAD3293ULL, 0x7C442B96EA57F2D9ULL, 0xE9ABEB4A407D153EULL, 0x10443E5DD6767930ULL, 
            0xA9C46BEC8AF565D9ULL, 0x9586B9C28C1F4077ULL, 0x81261C162AD1994FULL, 0x79ED27C6362F7CE1ULL, 
            0x10A5BCEB9CD25899ULL, 0x3E87BEC24F86E09FULL, 0x87B55D04C482D0B6ULL, 0x157B40C652892CA9ULL, 
            0x33FD8DABBBA49CE0ULL, 0x2B8AE4F96075DB2AULL, 0x27E852E43B2F6718ULL, 0xD6AC0CC7AA6D909FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseGConstants = {
    0xFEAEE86107A69169ULL,
    0x223E2632322CE7C0ULL,
    0x029AE92774874453ULL,
    0xFEAEE86107A69169ULL,
    0x223E2632322CE7C0ULL,
    0x029AE92774874453ULL,
    0x467CD855E5878391ULL,
    0xA10B8462892C5674ULL,
    0x94,
    0xC7,
    0xC6,
    0x1C,
    0x53,
    0xB9,
    0x9D,
    0xD0
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseHSalts = {
    {
        {
            0x2E64CDAB98D7899FULL, 0xC84DA8367A2BB29DULL, 0x80105CB1B48968DCULL, 0x5B20F48E8DAD7BB7ULL, 
            0x9B4F8396E76467E2ULL, 0x5E0C22A1ACDE9BD4ULL, 0x2C1307446B640919ULL, 0xFDAB9E00598FDEFCULL, 
            0x519E7C638B35B10EULL, 0x1C2A1B79A5FE7E38ULL, 0xE4271B1A52DF24E1ULL, 0xFDE51FB3B85B9477ULL, 
            0x390B1002CD7AC2E7ULL, 0x0521BC2FFB06B4EEULL, 0x3AF4B47D06FAD756ULL, 0x33D2A132400E37B0ULL, 
            0x9E4446C6AB5DF84FULL, 0xA80BC8E7028BD3DFULL, 0xD74E2D743F9D4BB2ULL, 0x3631D4D0D4EA193CULL, 
            0xBF20B3B0E7E2EE14ULL, 0xFF44A89ED7F9A6BBULL, 0x9074C374F484B5F0ULL, 0x1382279106C370BFULL, 
            0x9716204336395E54ULL, 0x0F10A2ACFEC985EBULL, 0xB4DE05D613B4624CULL, 0xEC3779130C3EF584ULL, 
            0x1DC1D88E2FC44B52ULL, 0xE057ED711C353DFAULL, 0x079C710A9769E47DULL, 0xD138CDF415728CBDULL
        },
        {
            0x3A858F1384DF9F71ULL, 0x5A1F5E3D9B1108A8ULL, 0x03FE6E713CADF030ULL, 0x6372E10D05A9C1E0ULL, 
            0x866D6699FB46843FULL, 0x8DE830E4D6457586ULL, 0x9A7EB58120DE0D83ULL, 0x365233137EC44F6FULL, 
            0x027BCEBFBBD1CBACULL, 0x8576588BC99C8D25ULL, 0xE1B92162FC62BC38ULL, 0x37A947C2457ACB50ULL, 
            0x8C01CBE1D537BF6AULL, 0xE66DA1F2CC273D75ULL, 0xF787E5036097396DULL, 0x586A5B08F4196283ULL, 
            0xF8B618B6E680BBE1ULL, 0x3361B0A79B3C28DBULL, 0x119BE5DF3DC00DFCULL, 0xCF87DB5410CB8A5DULL, 
            0xE7CADA7B70050246ULL, 0x6C5213DC6352E3D2ULL, 0x924F9213E8FE76CDULL, 0x5E7F1A92D6CA00C5ULL, 
            0x8AA74FA9DE24649DULL, 0x876D9EECB5B54BF8ULL, 0x53592453C34005DBULL, 0xC7D8929946D4D221ULL, 
            0x37BE33D47254E67EULL, 0xC9476244D09F5C5CULL, 0xCDBBEAA795DF1BDAULL, 0x41E103021987C121ULL
        },
        {
            0x53270E5C8E15D643ULL, 0x0E7AEF047A69A2A3ULL, 0x99F86757BAEAD5CAULL, 0x1182220519CBBF57ULL, 
            0x5C8FFB31917787E0ULL, 0x2CCC31CAAFFFA3C9ULL, 0x3F29E591F6B5C9EEULL, 0x14CC8BA19859944DULL, 
            0xA52A7BF0F71067EFULL, 0xDF5DF22E5211FD5DULL, 0xF46D0D2B2F173836ULL, 0xFDFC71F36BD3EAC8ULL, 
            0x70AE6FD1A4CDE4C6ULL, 0x31FA34E52A79F918ULL, 0x094D2456E07E1175ULL, 0x4012BA250E11989BULL, 
            0x87DCBB1843B3E5C6ULL, 0x97FD14D03A2BAE61ULL, 0xB513F7CDE1C54609ULL, 0x76160253259A7199ULL, 
            0xA678E2EE32C802D7ULL, 0xB38EA8A8FDD55E7DULL, 0x2627A05605E4E530ULL, 0x4FB8A599ADAB9B7EULL, 
            0x37AB10A6B24A718CULL, 0x3012B5EC2CE652D7ULL, 0x4979EA0266EB9A84ULL, 0x0E9B06A6B0DA49FAULL, 
            0xD5CE73714527F17FULL, 0x0B35258CC6A9606BULL, 0xDF5FC7D20D575B5FULL, 0x76BEE826A596B8EBULL
        },
        {
            0xA99330F2A480476BULL, 0x0906D6C617D4DDA1ULL, 0xBD6FF8C045968ADCULL, 0xB476CF3F02AA806FULL, 
            0x2B545AD4A7E52591ULL, 0xC67C96FB968F789DULL, 0xDB2A19494FD20A59ULL, 0x1BEA3037DF37E62AULL, 
            0xF350E749D66FF025ULL, 0x36339E467451D991ULL, 0x5D2EBE519B33F6AFULL, 0xA748CD6864728F19ULL, 
            0xBBA0B52CAEB83E2EULL, 0x0E93E48777A140B1ULL, 0xFEFE2B5762C4FB76ULL, 0xAC54A93F4D499495ULL, 
            0x2FD9F66128A7804FULL, 0x082DC14865156E9AULL, 0x8C2A40AFD8F5ED1BULL, 0xA645EE9EBC229D2FULL, 
            0x08D93EB97137E99BULL, 0x9D2F54AC9923CD2DULL, 0xA84998DD51886D35ULL, 0xC5887CB861CB354AULL, 
            0x4364F6FCBA691CDAULL, 0xAE4E5D587A2CAA60ULL, 0xD25F8DE5FA522D57ULL, 0xC6F97E2279C7E37CULL, 
            0x267BD7A757187BD4ULL, 0x3388422F2DD646CAULL, 0x9DA528A74E5D28FBULL, 0xD49192D5890A6006ULL
        },
        {
            0x3C7513840E67A7D3ULL, 0x377144BB2923C1D2ULL, 0x3CC9876FF0ECCE7EULL, 0x809BE57F6BE9981BULL, 
            0xAEB6E624741DD888ULL, 0xC6C205BD7BF5E9D5ULL, 0x14EFA90B361DB22EULL, 0x5E23805DB8E3CA5CULL, 
            0xB12592D10539DFDFULL, 0xA75D307876F9AF71ULL, 0xAB625275FE8495E4ULL, 0xFE1EA2696303579BULL, 
            0x7AD82209ED9C83BCULL, 0x79EB3E4D62A5AC52ULL, 0xF616B6C7DCEC05A9ULL, 0xB3DBCC38C4F5BF6CULL, 
            0x01E5EE8E9E5B095FULL, 0x67A12BB064375B05ULL, 0x6A07FB397C7FA8ABULL, 0xADCC2A5DDDA42460ULL, 
            0xE1843CD598A88E1EULL, 0xB0815FA3BC2B68A4ULL, 0x86508E044D4C312DULL, 0xC198D184726721F5ULL, 
            0x976B3CA3F04069A3ULL, 0x370ED91CFBE69223ULL, 0xAD4FF3F81A2EB3ABULL, 0x1E6D460F2BD07003ULL, 
            0x6D96CD33135430B8ULL, 0x62203E51DB739913ULL, 0x3727B3F2567CA7AEULL, 0xB83677FA49914A67ULL
        },
        {
            0x29580C0624DEB710ULL, 0x337CE96D34405F1BULL, 0x7D9428019297D4E1ULL, 0x545A98DA52F29F26ULL, 
            0x9998E3013B12A34CULL, 0x50B8B2CB1B09A8A8ULL, 0x6A0B2A40A822CBF6ULL, 0xFD39D20C927E3790ULL, 
            0xE48E23D56ADDCE4AULL, 0x78E00602272A789CULL, 0xF23E816626D9630DULL, 0xB3E5B555CEF71159ULL, 
            0xAB603BC77710498BULL, 0x894C8A0C39B4ABE3ULL, 0xE03104706BE4A31BULL, 0x472097AE279429E1ULL, 
            0x05432A24A147D0D2ULL, 0x82A0AA18D6473F8BULL, 0xB9FE63136E26BCC2ULL, 0x9E0C443CD7DAF47CULL, 
            0x9A86F94EE3DBA5ADULL, 0x05C7428F3B083C27ULL, 0x50401C342D427068ULL, 0x658B5B185DD725FEULL, 
            0x5FAEEF92C11F6611ULL, 0x2E855B21572A4B52ULL, 0x0B3BDAB495945E89ULL, 0xF3E7F10ACFA62032ULL, 
            0x523F627A0260FC31ULL, 0x92240F9899D9349EULL, 0xDF487C9626DAA94EULL, 0x1AF46F75571F2F04ULL
        }
    },
    {
        {
            0xA44ACE2A75FDC967ULL, 0xEAFCEF199AD3D75FULL, 0xBE98093F59637192ULL, 0xACAE19AE34D78C7FULL, 
            0x73B7195437FC8892ULL, 0x49E4156E5D634A3AULL, 0x6A11BC33DC50374FULL, 0x631486014B865839ULL, 
            0x1733C71EADF1F757ULL, 0x526334427C1E23EAULL, 0x62D9358B92236C79ULL, 0x9E6416DB470D7AD6ULL, 
            0x196B334815B86A51ULL, 0xC1EBBABD3BF8B788ULL, 0xC58A311E3A352E67ULL, 0x220C777299A281A9ULL, 
            0x93C1AA1292465AC3ULL, 0x58CC90AAFE0C8512ULL, 0x8F254935C7E9C193ULL, 0xE7911320927CE033ULL, 
            0xC0ACE91EE8066320ULL, 0x35CCE16D712E13DFULL, 0x878CC0F62C08DE86ULL, 0x5ADB888E9A2AA003ULL, 
            0xE18FDB51D0865336ULL, 0x70FD91BC47C358E1ULL, 0xC9BB24F9170E1241ULL, 0xA61DF94CEEA8E300ULL, 
            0x933490949174FF47ULL, 0x3CC63F1D463B8923ULL, 0x56FB91E438C847D3ULL, 0xE2CF8A0757DB9748ULL
        },
        {
            0x49613B0F36495F4DULL, 0xF71C11FDFEB123E5ULL, 0x41058EBE3FF51E84ULL, 0x543D536CA58687C0ULL, 
            0x36E0A04E2E50B4F2ULL, 0xFBCB57F0570146D4ULL, 0xFF1B0ACC1D384948ULL, 0xB93142DD83A3411CULL, 
            0xD5B346277742083DULL, 0x58EEFF784205E9A0ULL, 0xF6F7AE5B817F6280ULL, 0x91979A4D3329775AULL, 
            0xCA528EF6E869F62FULL, 0x6B581B193438E448ULL, 0x21A7AECD7A48345CULL, 0x12D6C4EEA2AC2C58ULL, 
            0xA32969BE2531DEA4ULL, 0x2750BDED082C8499ULL, 0x555096505CBB68B0ULL, 0x5B29C5BAF9215954ULL, 
            0x6BF708451EC6354BULL, 0x96ED8453C64F0720ULL, 0x840F70BCA1B2C2ECULL, 0xFE517E3B3E6F4169ULL, 
            0x9AFF1CCA69D94DD0ULL, 0x330A32730650F061ULL, 0x083865E9483EC9EEULL, 0x9A3F2E6A8C940040ULL, 
            0xB4E8580838470205ULL, 0x01470B4C9240EF47ULL, 0xB7BE728B228877C7ULL, 0x749DA59CBE1D50EBULL
        },
        {
            0x6B5FEE5924134C4CULL, 0x1B61F998DCB3D077ULL, 0x990CA850D8194079ULL, 0xFB8B1400D8E2347AULL, 
            0x5FA963C97CE69766ULL, 0x1F9F1254C411D7CAULL, 0x08E8C271C8CEF557ULL, 0xFD82A6C83FBAC32CULL, 
            0x23633472D04E0C85ULL, 0xFE8BD0E81BD59361ULL, 0x6C3DA4905A6F21DEULL, 0x36725AB0A8AD0A10ULL, 
            0x71F5B623B57400EDULL, 0x9F61A8047A053453ULL, 0x8A18999EDA9A7EE8ULL, 0x8566C127816BD41DULL, 
            0xDE32BEC16649C39EULL, 0xB550D6AF37328B52ULL, 0x059FF3ECB4E65E4BULL, 0x30FA6813987B91EBULL, 
            0x9AF67731C08AEB59ULL, 0x7B9FA948244701E9ULL, 0x84A571C130043B6DULL, 0xAEFB32EEC56C6A91ULL, 
            0xB553968014FF4D6FULL, 0xE6E3AF918B4CF133ULL, 0x0EBF67A8A63660BCULL, 0xEBAD2A6CD596B5A5ULL, 
            0x546EFDDCFA2C7A48ULL, 0x24B6D6EBB88471E6ULL, 0x91AC456B63FC1A29ULL, 0xAE4D541FDAACEC31ULL
        },
        {
            0x3110F7B6E8F796B1ULL, 0x8DECA0FD42BA5CEBULL, 0x938636967EE33E33ULL, 0xF92F64E469549393ULL, 
            0x9056A9B623BDD5DDULL, 0x5E9E40BA46516908ULL, 0x04BB40CD7888B39FULL, 0x172C2A62D32D16A2ULL, 
            0x8D911A9FD527C9D6ULL, 0xA8053BE7051621A3ULL, 0xD96471FC3623F360ULL, 0xD3DD00659FAB82CFULL, 
            0xD6E72E6B476C115EULL, 0xFEA45E33334E0075ULL, 0x4649BE21FBC4AEF3ULL, 0x857BD857003192AFULL, 
            0xA96188A5754589D8ULL, 0xFE5769A57824EE1AULL, 0x64732A54A49FAC24ULL, 0x585849EC4323BBECULL, 
            0xE2E05C838013AB29ULL, 0x2714FB524E1F38F6ULL, 0x20671C8B7B914852ULL, 0x7833D2127549E811ULL, 
            0x0BE8995B15FA3D0EULL, 0x798D2F57370A408DULL, 0x575BE6EF285F753BULL, 0xECAC103A77AE5FB3ULL, 
            0xCE3AAAAA6E06DE55ULL, 0xF9B66421ADD3956CULL, 0x8B53DD036D046346ULL, 0x559E7448730CE676ULL
        },
        {
            0x03D3392BE79FCEC0ULL, 0x9C67B4DA35D56232ULL, 0x049D82D725E66852ULL, 0x07BA845149BB7BA5ULL, 
            0x478B61E24DCD0EB2ULL, 0xE929D2D30A0C25EBULL, 0xA9B6AE2532BFF443ULL, 0x8AA36B138F1778F3ULL, 
            0xF06AA2C1F693D093ULL, 0xB1C521025066E93FULL, 0x554BE1C586701B19ULL, 0xF014F7DCF9E63ABBULL, 
            0xBB592DFC73A1FA30ULL, 0x9518947EC3ABD1D9ULL, 0x033B086047DFE961ULL, 0xBD80E6D34AF85F6CULL, 
            0x66387A35CA45B694ULL, 0xB2F7F63D453A3F9AULL, 0xEEFAAAF687D3C133ULL, 0x7055F5F48CC0CF3DULL, 
            0x9CA9F0EDEAF8A030ULL, 0xC3D9A74DA6099468ULL, 0x3C24E4CB9C447721ULL, 0xE000C7FF8DDFA739ULL, 
            0x0EDAD33CEBA7DF73ULL, 0x5965A24F2CD159F2ULL, 0x1D9C441BC460049DULL, 0x61AEBE0CD83F1453ULL, 
            0x5EDBB2CA05F0C471ULL, 0x332BF406B61D9E63ULL, 0xC1C3EE9D02640809ULL, 0x52E4A48466C3AB9FULL
        },
        {
            0x9582E348BCB2F6DBULL, 0xB9781685BF1F157DULL, 0x358D414F18CCBC58ULL, 0x7685C98C2EB232B8ULL, 
            0xED457F8FB1F435C8ULL, 0xE42E6C041D3D52B1ULL, 0x6DC30782EC53C5BBULL, 0x0DD4F3FF04E60BD9ULL, 
            0xD695428DACDFA694ULL, 0x2D709B9031D52F07ULL, 0xE28B1A7F08A58081ULL, 0x767475B845E7C880ULL, 
            0x25A501CBEA896EE8ULL, 0xBCE96743D1EB464BULL, 0xA1AF369A37DE5F1FULL, 0xFA39D070D5BCD76FULL, 
            0x9C0853D6EF62A326ULL, 0x586F5C80AD0F6B08ULL, 0x0EC0F70B391184FCULL, 0xC81B31B3A52183CCULL, 
            0xE51AAC871F14BCB1ULL, 0x1D4FDD29FB14B562ULL, 0x06435015842C0254ULL, 0x3B1BCBE512045E64ULL, 
            0xE763250087BC6C49ULL, 0x3923ED08668D3F3BULL, 0x98C8C9D154A0DB1AULL, 0x42EC1DE6DD825D56ULL, 
            0xC9B204E22E52D7CAULL, 0x5D42B01EC4DBDC13ULL, 0x5D0AB8C0C3833A7BULL, 0x9D7F2F065DB4FC38ULL
        }
    },
    {
        {
            0x6811080B5456A62AULL, 0xE276801B98C9DF44ULL, 0x14D3D6CAD376D9F9ULL, 0xD2B0D18A38DA8C71ULL, 
            0xC55B04B20A1A353FULL, 0xAC77F99603154217ULL, 0xAC38D9CC3F686B73ULL, 0x1686E350638799DAULL, 
            0xA216594B08EA915DULL, 0x408B19C826C9552FULL, 0xB4084B84EC2EF0A9ULL, 0xC5BB7B687C56FDB6ULL, 
            0x54354760029F538EULL, 0x15A6D978BFF3C8EAULL, 0xF24EF68FEF81E9FDULL, 0x355EF39C2017679EULL, 
            0x559DE271379B84E7ULL, 0xC9AF9910CC6822DBULL, 0x981529B046122EFDULL, 0x80BD4D1E66CDD287ULL, 
            0xE8029EFDD5C77B54ULL, 0x3B01FCA4F0B70EA9ULL, 0x2B753BB17196FE50ULL, 0x3F87AB13B4D83A22ULL, 
            0xB824695016E02F9CULL, 0x022E49CB61B43641ULL, 0x888FF047FC8BED70ULL, 0x9095D4C09AEFD02EULL, 
            0x1F2E0B98AF0933A1ULL, 0x2C71117F808602C4ULL, 0x333D27CC93BD2970ULL, 0x8A68772330B68064ULL
        },
        {
            0x24250D2895007CA7ULL, 0x059E3B3808E3CE8AULL, 0x39D4C0F79D497AD6ULL, 0xE02B69D90929D734ULL, 
            0x1650EB851D014547ULL, 0xD100427300E96FE2ULL, 0x73EF0DFEA408D23BULL, 0x1DB460D307DACF3AULL, 
            0x3120EA19A2B0DC7FULL, 0xC4AFC350FC9BBF32ULL, 0xD59ADE10A6EBB16DULL, 0xBBF98A7E301C057BULL, 
            0x17099DB31DE15ADBULL, 0xE19DDBE1214F61C1ULL, 0x4B8C0F641376E0BFULL, 0xD488FF92E9579221ULL, 
            0x1B2ED1350C9A4C61ULL, 0x6799AE2B6BC9BC5CULL, 0x56F980057484D951ULL, 0xF1ED38BE18990392ULL, 
            0x80F68FC38DD5217FULL, 0x1072B69991E2588DULL, 0x5E3C2B544A432BDEULL, 0x37EA7928923D08CCULL, 
            0x5617D5622069BAC5ULL, 0x09853CE8ABA612A8ULL, 0x49539B01A9422203ULL, 0x8B1C2850F1047BEFULL, 
            0xFD9CBA635E7383D1ULL, 0x093E6552D65BED63ULL, 0xF21AD210367F4FC9ULL, 0xC796A2B65BBD5FFBULL
        },
        {
            0xB929D0DAA257DDD3ULL, 0x09C396240166B3B5ULL, 0x1DA472BDAAA44D55ULL, 0xD483FC9B244D6C83ULL, 
            0x02E49E081632CA2FULL, 0xE61FBCDD6C374A0CULL, 0x471F7FC64C85FCECULL, 0xDFDC9749470EDCBBULL, 
            0x8DF865F3449D49A0ULL, 0x844EEFF3915A0BBBULL, 0xDA4F637B49A6D784ULL, 0x451B8E38091B56D3ULL, 
            0xD682112FD12991E0ULL, 0x2365013F1275CEDFULL, 0xD24CCDC5752857AAULL, 0xBE172E1698BA33BBULL, 
            0x3B40F4623B1A212AULL, 0xDDA50D1D21FA4F9CULL, 0xFD482DB6BACD3B39ULL, 0xC84E129C2A668386ULL, 
            0x4065C265915C5D1FULL, 0x3842845DDA6CC99BULL, 0x5B945CAEC3B84E31ULL, 0x7E242C2789168FB7ULL, 
            0xC79F6E1E6D4F1274ULL, 0x6284531128961053ULL, 0xB9C5B6C1596FC40DULL, 0x9377F5A0F82F20CAULL, 
            0xB9ABA0EAF8B788DFULL, 0x4D36A045BD10D267ULL, 0x8F7120AF3BC399A1ULL, 0x7926FD7A915FE5F0ULL
        },
        {
            0x91E9BB83C67B5E47ULL, 0xE8C293F0C80A5975ULL, 0x5A64A712CD654D33ULL, 0x461C4E493881EB8CULL, 
            0x3EC8A1CC0BA5C5C9ULL, 0x155D781C0F1CE650ULL, 0x12888BE0F8930E0FULL, 0x6A0FED82DF4B29E4ULL, 
            0x0251D492079606B4ULL, 0x01E2851F73569CCFULL, 0x051BE17979E7E084ULL, 0xA2447E5933AB34AFULL, 
            0xAE8D2B8F5A4A0BBDULL, 0xA6F62A00FF4274D1ULL, 0x416126418C090F7FULL, 0xB4DE8A4B6030D5E8ULL, 
            0xEEE6A4554B783E59ULL, 0x696743CCD96877E4ULL, 0xB6B876ED1FD6BD2DULL, 0xB9281F0B9B4F5E2DULL, 
            0xFC7345BB494B065DULL, 0xE8CB4CA9DB641FE4ULL, 0xD57C7CA14DCC13AEULL, 0xC6922F0C1EB4C8AEULL, 
            0x6FEA5D8F9F1D3C21ULL, 0x9E1060453FD4F91FULL, 0x9EB58700A770BD35ULL, 0x2EAC8EE93DB69C79ULL, 
            0xE90E175CAC54EFE1ULL, 0x46D11232836E67CFULL, 0x936227C38A7CF4B5ULL, 0xDDE9441318EDE7ACULL
        },
        {
            0x5AC6A36793A2B003ULL, 0x8BAB3534F5BCC397ULL, 0x61B27847ADF96297ULL, 0x3B087E7C8479C48CULL, 
            0xC8FD013B279631CEULL, 0x6577949F9AF0A7A0ULL, 0xA9EFA0795DCE3317ULL, 0xBDCE063970C6C381ULL, 
            0x1ADFB5B6887F944AULL, 0x055B33A5173F6CE1ULL, 0x51FC0304684A1451ULL, 0x07F6DC27492F821AULL, 
            0x24F9A6AAD43AD98EULL, 0xEB8D9A419D1F9B56ULL, 0x6C634C9ADE78C504ULL, 0x9DD8EC822661DE64ULL, 
            0x94848CF480025EC8ULL, 0xC9710D906A35258FULL, 0x3336BE16C7F2CFE4ULL, 0xB6974F75F4893847ULL, 
            0xB8287025EC814143ULL, 0xE5DC41733FC02667ULL, 0xA4DEDB9E7E5893D3ULL, 0x823C177937447924ULL, 
            0xE1768C1146445CC4ULL, 0x706F9A12E47190AEULL, 0xA78DE7EF4E1B155BULL, 0x309AA81E2DDDFAA2ULL, 
            0x6792E24BDA3FC451ULL, 0xA1350CD9A00532E1ULL, 0x8A51F1D8BC30C329ULL, 0x5067DDC9BD26B67CULL
        },
        {
            0x31F72F6EC985109EULL, 0x7B0B9AD071A190A9ULL, 0xDDD4E70FC81EE7AFULL, 0xC13D0CBAFD523AD1ULL, 
            0xDA95911506ECAABFULL, 0x4BD13DF4D46E2C86ULL, 0x8CAC210DA5FC5F6FULL, 0x235B27B9CA7DF302ULL, 
            0xA29763D8BDFDFDA8ULL, 0xA39D63B784D80C65ULL, 0xDAEE713BABA9C5D9ULL, 0x572016C29F03EC64ULL, 
            0xAA2A79A6F10C760DULL, 0xF2D6AD64851424FCULL, 0x891F74B943686860ULL, 0xFAAA661F8F0B25C4ULL, 
            0xAE51E141222CA315ULL, 0x5927A374D19A613CULL, 0x17E7A4B4DAD7CA8FULL, 0x8E9793C0D2D8BEA9ULL, 
            0x0C6C016DF74BBB4EULL, 0xEE37E3DD69781525ULL, 0x2E47A6C7ED7B86FDULL, 0xC8541C54EB9E4D78ULL, 
            0x07481668518EB8F5ULL, 0x133B181ABE72ADF8ULL, 0xB25CC4667936949EULL, 0x7C8B54A2C57367EEULL, 
            0xC970819DC2ECE0D4ULL, 0xBA57771E71B42F8CULL, 0x71328C27445A3E56ULL, 0xC1DC9A715BAFCBC4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseHConstants = {
    0xF5BB7B5B1C79EB73ULL,
    0x9BBD187AAAFE81BDULL,
    0x0008C3017670FA9FULL,
    0xF5BB7B5B1C79EB73ULL,
    0x9BBD187AAAFE81BDULL,
    0x0008C3017670FA9FULL,
    0x6A3767D7847DF493ULL,
    0x012383D76BFAD737ULL,
    0xBE,
    0x85,
    0xA6,
    0xE5,
    0x7C,
    0x1E,
    0x4B,
    0x22
};

