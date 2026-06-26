#include "Soccer.hpp"
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

Soccer::Soccer()
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

void Soccer::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 12992674035657656885U;
        aCarry = 16784034660395752837U;
        aWandererA = 14372576444108270333U;
        aWandererB = 14215996628240814688U;
        aWandererC = 11430945018698972268U;
        aWandererD = 11229814661481550715U;
        aWandererE = 13931538219471598487U;
        aWandererF = 15535369088970682510U;
        aWandererG = 17949163725302605052U;
        aWandererH = 14911574985835760735U;
        aWandererI = 13625948280653851367U;
        aWandererJ = 9452187355988285443U;
        aWandererK = 18320094941401674587U;
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
    Soccer_Arx aArx;
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
    Soccer_Arx aKDF_A_BArx;
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
    Soccer_Arx aKDF_A_CArx;
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
    Soccer_Arx aKDF_A_DArx;
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

void Soccer::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 10135053690291050839U;
        aCarry = 17789252562168332088U;
        aWandererA = 11870703513129556434U;
        aWandererB = 17258036038988970437U;
        aWandererC = 13278410101958552644U;
        aWandererD = 10368717214210069172U;
        aWandererE = 13311599926096298055U;
        aWandererF = 15919084051581629977U;
        aWandererG = 16308746036510102855U;
        aWandererH = 12448337095457630940U;
        aWandererI = 12291569809923101308U;
        aWandererJ = 9958307306133578019U;
        aWandererK = 11699541997255157625U;
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
    Soccer_Arx aKDF_B_AArx;
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
    Soccer_Arx aKDF_B_BArx;
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
    Soccer_Arx aKDF_B_CArx;
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

void Soccer::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneH);
    }
    // KDF_B PhaseA invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneA);
    }
    // KDF_B PhaseB invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    }
    // KDF_B PhaseC invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneF);
    }
    // KDF_B PhaseD invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneE);
    }
    // KDF_B PhaseE invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseF invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseG invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneC (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseH invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
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
    Soccer_Arx aSeed_AArx;
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
    Soccer_Arx aSeed_BArx;
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
    Soccer_Arx aSeed_CArx;
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
    Soccer_Arx aSeed_DArx;
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
    Soccer_Arx aSeed_EArx;
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
    Soccer_Arx aSeed_FArx;
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
    Soccer_Arx aSeed_GArx;
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
    Soccer_Arx aGrow_AArx;
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
    Soccer_Arx aGrow_BArx;
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

void Soccer::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void Soccer::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    Soccer_Arx aTwist_AArx;
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
    Soccer_Arx aTwist_BArx;
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
    Soccer_Arx aTwist_CArx;
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
    Soccer_Arx aTwist_DArx;
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
        Soccer_Arx aGrow_AArx;
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
        Soccer_Arx aGrow_BArx;
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

void Soccer::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 1, 3 with offsets 7701U, 6426U, 20U, 7159U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7701U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6426U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 20U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 1 with offsets 6765U, 3796U, 2454U, 4370U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6765U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3796U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2454U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4370U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 2 with offsets 3551U, 308U, 5513U, 5827U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3551U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 308U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5513U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5827U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 0 with offsets 3006U, 2086U, 1749U, 360U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3006U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2086U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1749U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 360U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 with offsets 788U, 1951U, 1059U, 611U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 788U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1951U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1059U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 2, 3 with offsets 1594U, 1439U, 729U, 1780U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1594U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1439U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 729U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 1, 3, 0 with offsets 658U, 131U, 0U, 1955U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 658U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 131U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 0U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1955U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 2, 0 with offsets 1356U, 1593U, 649U, 1949U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1356U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1593U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 649U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1134U, 1206U, 1401U, 1410U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1134U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1206U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1401U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1410U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void Soccer::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 3, 1 with offsets 4683U, 1846U, 2908U, 3170U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1846U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2908U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3170U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 0 with offsets 4289U, 2867U, 7468U, 3644U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4289U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2867U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7468U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3644U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 3 with offsets 5532U, 4933U, 7784U, 5738U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5532U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4933U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7784U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5738U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 2 with offsets 6737U, 779U, 3971U, 1918U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6737U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 779U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3971U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1918U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1922U, 4509U, 1458U, 2368U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1922U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4509U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1458U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2368U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 2, 3 with offsets 502U, 2016U, 1492U, 439U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 502U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1492U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 439U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 1, 2 with offsets 1133U, 928U, 1841U, 1873U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1133U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 928U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1841U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1873U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 2, 3, 1 with offsets 1696U, 1626U, 1455U, 706U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1696U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1626U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1455U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 706U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 0, 1 with offsets 976U, 643U, 1415U, 1883U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 976U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 643U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1415U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1883U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1920U, 341U, 1872U, 1309U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1920U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 341U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1872U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1309U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet Soccer::kPhaseASalts = {
    {
        {
            0x466224379BB253EAULL, 0x4E9E1E28FB8231F6ULL, 0x3BDE4FD4DC25E500ULL, 0xA102E73443C3C957ULL, 
            0xF657F577E9889354ULL, 0xC30ADE85A03049B7ULL, 0xE06D04B0F637CD9FULL, 0x89631F71E7DFE490ULL, 
            0xF96184B00249A977ULL, 0x7FF1154F97BA6046ULL, 0x1FEDAF6AEBAC1422ULL, 0xA1BE0FE5AF8E702AULL, 
            0x57C02188E7C48B32ULL, 0x200A7D2F4D797556ULL, 0x05A84899FF859D68ULL, 0x7DF93163AB550155ULL, 
            0xE841EF487D02BD99ULL, 0xB4D5D1187BF94031ULL, 0xA86F8C9849C49BCDULL, 0x6D08735E34369E5AULL, 
            0xFD2DD076CD76EBE6ULL, 0xD140B9F4C4FA8946ULL, 0x4DD2DA34D796DB74ULL, 0x76108DD0706E252EULL, 
            0xF6D44094BA4FC374ULL, 0xAA9D9D9B58C0065DULL, 0x924180BECC7131B2ULL, 0xF7665C5585558E84ULL, 
            0x11E059833E0CC623ULL, 0xD0293137A48756FFULL, 0x2F76C061E53CD165ULL, 0x0701585691216C21ULL
        },
        {
            0xA0DE6509A07B2F36ULL, 0x7C52779A2A5F83B2ULL, 0x4011E5A1432279B4ULL, 0xCC49476A1C924D53ULL, 
            0x0E5BCDBDB5FB23D1ULL, 0xE1EF370F19D88427ULL, 0x1D0F0D1674C84DFEULL, 0x1DA5A121576CD76CULL, 
            0xEE8045EAC768D0D5ULL, 0x28A3B34C2484E934ULL, 0x449033B891D64ED7ULL, 0x15BC7E96681DE794ULL, 
            0x91EF863D884949E7ULL, 0x04B31789A62A1020ULL, 0xCA8E6403129AE3C6ULL, 0x11DD35506797AE7CULL, 
            0xDB14A1776B885598ULL, 0x013AF588038E5530ULL, 0xC72DD3863FE105EDULL, 0x8242B0089716E7EFULL, 
            0xA8DAC1AA45ADF9D3ULL, 0x81A515BFA16222C7ULL, 0xB4D248A4006A8A32ULL, 0xC3A5DB9533F73F82ULL, 
            0x9AB5BFBD9FDB2CE3ULL, 0x7058CE808905C64EULL, 0x37D576C2928DA73BULL, 0x1B491C48A0F03E54ULL, 
            0x50516667F5C59E06ULL, 0xFD0E777C37A82136ULL, 0xECE27248B73A66C4ULL, 0x8372117A328B5A28ULL
        },
        {
            0x86969411C0BB4AE9ULL, 0x721C0C771D3D189EULL, 0xAC4041DBF52CDA90ULL, 0xC0114EDDFF08F5FAULL, 
            0xD9911B2E52B1E02DULL, 0x45A73D18ED790921ULL, 0x146602B89848DAD1ULL, 0x4977B652C17DAB8DULL, 
            0xEEFD19CEB2C25743ULL, 0x7CCEC3A6BC043C61ULL, 0x7E52996370291F52ULL, 0x2B3DBF0CC9AB0944ULL, 
            0xCD0E1E241493C0A9ULL, 0x4A7746D9A28C88C4ULL, 0x0893ADB71F3A2C6FULL, 0x247708D26F4968A0ULL, 
            0xFD6B02D663784474ULL, 0x1FDFDED213FC4CADULL, 0x8D7B784ABB36AB26ULL, 0x2FFC1E554F898452ULL, 
            0x11BD5DA0AB8636DBULL, 0x5DEAAEC5FF17BB5CULL, 0x11FE74D1DA65A9C5ULL, 0x18AF8CF23B18A1C6ULL, 
            0x9082A12F86C37FD0ULL, 0x163C399DF3E11455ULL, 0xDB26CA637EFD7D1CULL, 0x4D4089B2CC92CBA8ULL, 
            0xEEC1D8A7643F9B9CULL, 0x844B29336E9BB84EULL, 0x964FE3C0A4E630C4ULL, 0x98B8F09858F65556ULL
        },
        {
            0x9149DEF5DC2DB14DULL, 0x499BDF9A251827EDULL, 0xCB0B1E78CC287AA4ULL, 0x672E05FE9D1D65E1ULL, 
            0x78502BABE8C420A0ULL, 0xE6D4B298E2ABFF60ULL, 0x2C9E0957B412F6D7ULL, 0xB10A073BB2F8A1A5ULL, 
            0x70300F564F2E54CFULL, 0xDFEC58677DFD8680ULL, 0x43FDAF4C8D76827AULL, 0xE54A3901BB93AA92ULL, 
            0xA15A2B2297A49693ULL, 0x58AAEC1EAFB43F8BULL, 0xBBA0FD3287C7E829ULL, 0x27599ACE09D13FBBULL, 
            0xC9ED914D9DBAB2BDULL, 0xD7EB53E01F828A28ULL, 0xBF8B5606212E411AULL, 0xA72CE30539FE4200ULL, 
            0x95D42BB1420AC34DULL, 0xE81C6D19A808F88CULL, 0x3BB7B0028A5B476CULL, 0x3C0BB4EBA731301BULL, 
            0xCC260023DCC9AEA6ULL, 0x77DB816659882ACFULL, 0x821BE6661785968DULL, 0x0DA74A865A85F123ULL, 
            0x3033D510C473BA7BULL, 0x40DDADFECEF42A2EULL, 0x563CAC77CD43A51EULL, 0x5E7EE7FAA7E738B3ULL
        },
        {
            0x7A096C1772004937ULL, 0x2221DD7A7A88EDACULL, 0xB8CDAB91A147F734ULL, 0x2F918AEFB1919D2EULL, 
            0xB6A2DB1965FE48C1ULL, 0xC8B856C573E5E38BULL, 0x90D9414AC1651A4AULL, 0xE1DD179BA64B18A3ULL, 
            0x95D5309BC9FD42B7ULL, 0x44B363DAEE386E36ULL, 0x85147C07F7F7D4BAULL, 0xCD66FCDD27EDEC2AULL, 
            0x214AFEE4613470CAULL, 0x6B3556FEBCC65290ULL, 0xE8DE0B238DD8913EULL, 0x2F9950B9BE42F49FULL, 
            0xD7C73657AA22F8B2ULL, 0xC82D5CEBEDAD115DULL, 0xB7089AE6E22C50B4ULL, 0xA14884E28FCF1ADEULL, 
            0x44761C71A88CAC0CULL, 0xC91DE1212AF14CB5ULL, 0x18D84CC2DB0552B3ULL, 0x27E712EFF34D4DEEULL, 
            0xE608D593C77A5F98ULL, 0x15FD7A1B518E0407ULL, 0x212262E54442198DULL, 0xA976C76AAACC4B0FULL, 
            0x1AD30BF37E4E5896ULL, 0x3AAFEF2F0D81062FULL, 0x498ACFBA63F864FAULL, 0xB34F1F5FE27D5359ULL
        },
        {
            0xAED605206A5BE7CBULL, 0x045948E8731BC41DULL, 0x7F6B1C2DCF2E5DEBULL, 0x315C9F0A0DF14802ULL, 
            0xFBB19D213F26AFF1ULL, 0xC2D1E84DA11E7847ULL, 0x7FCFB42A8EA22891ULL, 0x0DE764DBF083DF16ULL, 
            0x2264D12A2E82D937ULL, 0x256212F5087239DFULL, 0x78BD753B5A2DA12FULL, 0x734583A2B5DE86AEULL, 
            0x1BB930F951BC35B4ULL, 0x81F130CF4EA7133BULL, 0x9B7EED5AEC41F38BULL, 0xFA79417B08FB415DULL, 
            0x0737CC89F1A9EEF1ULL, 0x229F1E88B7F1D882ULL, 0x525B7A4D7625B8C2ULL, 0x79816E9D82958962ULL, 
            0x158196FD2B9BEF5CULL, 0x944F5112ABD7D403ULL, 0x4E2A11BD6854AA72ULL, 0x4F2A2ED3C0ADE86EULL, 
            0x4D884881E8D21583ULL, 0x1481AD284627192FULL, 0x130F2803EBE87AD7ULL, 0xA5B741DAD5D0FCD3ULL, 
            0xE94AB35391E52330ULL, 0x4C0BC5AE6311828CULL, 0x8CC34F674AF781B3ULL, 0x0FABF876565746ADULL
        }
    },
    {
        {
            0xA77364C456E0F232ULL, 0xB725B7D7BEF752F9ULL, 0xAA1048547E3D18C4ULL, 0x74D317A92077BC42ULL, 
            0x0B212A4EC1187C84ULL, 0x2A3D8E5CA237F2AFULL, 0x8A8DAD8BEEB4809EULL, 0xEA09AC9ECA5AA515ULL, 
            0x36AD07C5BDCD3B07ULL, 0xAD129D404CB02C15ULL, 0x3158B37A2DEC5C15ULL, 0x2434A7E5092C4E74ULL, 
            0x55AB695E860066B6ULL, 0x5F212858B1A5A2DEULL, 0x0D454D2F7622B77CULL, 0xA906CACEF256395AULL, 
            0xB5E4C31220553EEBULL, 0x751748B3DF758ECEULL, 0xC75D2470C5E6CDC6ULL, 0x8E447280CD095A94ULL, 
            0x89175BF750787734ULL, 0x5A156E274A180D2AULL, 0x14FB181749D650DCULL, 0xE552D52CBF1DA126ULL, 
            0xA2255D1C0A51D88FULL, 0x64B564233FECDADAULL, 0xDCB11F197A9075DAULL, 0xD107107AFE528BC2ULL, 
            0x2E0BBF3A018B7F15ULL, 0x6ADF7B0C1D3B549FULL, 0x0F1638B6CF471A06ULL, 0xF1BBB59B99F50B1AULL
        },
        {
            0x723BDAC6AE477A4BULL, 0x14B3546AA638433DULL, 0x152CE559BA5F7339ULL, 0x6153E9FB90D8C633ULL, 
            0xCA8813D98F0CC1D4ULL, 0x49293FE75AFC39FBULL, 0xC166CDEE3EDBB3BAULL, 0x68A3DBEF3E1D4A87ULL, 
            0x1E99501B501FF93EULL, 0xEABD27BBDE802ED1ULL, 0x1D9274DB98C39E54ULL, 0xB2E838DA922C0F2EULL, 
            0x456C90239057819EULL, 0x971170B9221D4164ULL, 0xD2F391FF82E143ABULL, 0x669E7643244C966AULL, 
            0x780A72EC518038E1ULL, 0x370C07EB0C0B797AULL, 0x411D0848AB5A0940ULL, 0x12E53747A46365F1ULL, 
            0xB33537A7807A2168ULL, 0xFBDC2ED137B24325ULL, 0x7D584FEA0505521EULL, 0xF318829FA956736AULL, 
            0x1A4AFCD19698AB72ULL, 0xFE976713A75CCABBULL, 0xAEC9AF14FC5A83B4ULL, 0x8E42910D922A858FULL, 
            0x7676FD72429817BBULL, 0x708991232A379A6DULL, 0x4570DF58837F67F7ULL, 0xB9D956394AA82D61ULL
        },
        {
            0x49200F233CA56B70ULL, 0x002CBDE6933AAB47ULL, 0xB9ED158D2CF912EDULL, 0x6636F49E3109EF2FULL, 
            0x5E9DEB833B9C2A35ULL, 0x5A02AF184C9860DFULL, 0xD5368B065CDF3813ULL, 0xD808749267A10F61ULL, 
            0x5ED3F43E31E4F6D3ULL, 0xA0848D22AF85B80BULL, 0xEDCF366B37B7B224ULL, 0xB1BC35570B8D4081ULL, 
            0x2B7DA03F85B2766CULL, 0xB26CD85F5FFF36A1ULL, 0x7F19179A31D7456DULL, 0xDDD3755A48BE0EFAULL, 
            0x17EAED4EAFF7F98BULL, 0xB9559341ACB0C1A5ULL, 0x9CA58CED513D60B7ULL, 0x0C4C4DA436F70DDAULL, 
            0x86BBAFA90EE2F9C4ULL, 0x8246A6BC20A2DCF1ULL, 0xAB4147EC9FA9E8FCULL, 0x8180277BB241DD1EULL, 
            0xF86863C75A298AE2ULL, 0x5DF15BAEEE7B77F3ULL, 0x4BD3DCA2EC6CAD76ULL, 0x7858B945A7B6257FULL, 
            0xC7540A331DA0DAFDULL, 0x5C6B4AE951E4FA0FULL, 0x3190F5372DE940EBULL, 0x931FAA0639D02D90ULL
        },
        {
            0x6892F1CC13686A7EULL, 0x43DAC8640920A6D4ULL, 0xBA1FF633B3BD835FULL, 0xAFD1BCD975D5EEE7ULL, 
            0x33F0D154FEC16198ULL, 0xDEFE92FDA0B634BCULL, 0x3B408CC3418CF77CULL, 0xCB6E2E99EB4A875EULL, 
            0xFE38656F77A5C5DBULL, 0x3BF371F0B8073A7AULL, 0x44B2EA4B7A8DB1DEULL, 0xADDDC6FB3E51F078ULL, 
            0xABE245832440053DULL, 0xBCEDA562EADFF26BULL, 0x29E04621477D1917ULL, 0xB367761890E128BAULL, 
            0xFD6EDECD8D85A29CULL, 0x6FDFC9892C8548F4ULL, 0xEC7DFAA4ED90FE3CULL, 0x7A09C41FCC0DF395ULL, 
            0xD8E2A63B8C5E0FE2ULL, 0xAC41F2ADDAA6E5FAULL, 0x41DC8C20E6323D9AULL, 0x49A2689E996C6702ULL, 
            0x99446C24FFC06952ULL, 0x40482D9C8269010FULL, 0x53EC70CD29642827ULL, 0x162B5F308FAD60B3ULL, 
            0xFC25CC4DFAFA7B54ULL, 0x4DE863705CD7A72CULL, 0xEEC22D5493251FBCULL, 0xEE87934C7B0FB82CULL
        },
        {
            0x9249FE237E7ABBBFULL, 0x49FD60807EAA6E8EULL, 0x9D18A6C9AC26B85FULL, 0xEE9F2DFE6B393BCBULL, 
            0x71A815E5E70D2CF3ULL, 0x1C0430659E9E71CBULL, 0xBCCDD1D2D537303EULL, 0x8A3E960B831340DDULL, 
            0x1B461A43E5C5A98AULL, 0x741BDDE053DAFAB3ULL, 0x8303F2FFD20565D2ULL, 0x2C49DCFB2B70F82BULL, 
            0x7786E4A5E56348C6ULL, 0x230241CC66B6A9A0ULL, 0xFD78AD58F9DCDD0BULL, 0xC0C9288DE438656AULL, 
            0x06F6549B85E0D4C8ULL, 0x0DCDBA83F26C7F1EULL, 0x486036C5FD8426FCULL, 0xA70E8E8FF26E06BBULL, 
            0x9883B17C6BE0C815ULL, 0x1CCAF33A2D67878FULL, 0xAD575305A63FB59EULL, 0x52D5FBD7B88DEC00ULL, 
            0x20D2C70ABA021A69ULL, 0x706F4A323D8BBE0BULL, 0x6B1D783A28DF2B5BULL, 0x147C4445C30F875EULL, 
            0x65BD02F3AFEC75E2ULL, 0x9E1D4057AD461EA8ULL, 0xD7935C6CB3D96A76ULL, 0xA74393CFF52523D9ULL
        },
        {
            0x9058511C1B1F4588ULL, 0xA31650A07C0AD23CULL, 0x0609C41705549515ULL, 0x3AFA5DA1AE3B2027ULL, 
            0x46C14CA89C75796AULL, 0x43EDA355C347DE7BULL, 0x434CE9FCFF6F0D26ULL, 0x8F35DD70DF6AA9DAULL, 
            0xC4DFE020F66393A0ULL, 0xE904EF73F7D3BDF9ULL, 0x612309E26E1E9CF6ULL, 0x035F474CDFFFBBBAULL, 
            0x691951C98B9AB7FCULL, 0x8CD90553CF421BB4ULL, 0xC989E9583814897EULL, 0x8AC868C453798F1AULL, 
            0xB648775B7DD14AFBULL, 0x2E9800CAAE1557E0ULL, 0xA89FA1C4C88EA4D2ULL, 0x3C55B844CF253400ULL, 
            0xF2E2FEB5952BEB5FULL, 0x567B5088E84D72DBULL, 0x8149E8000868B3D4ULL, 0xB40CF87E1A8FFB06ULL, 
            0x268D35B495E4B20AULL, 0x626D44165658EE46ULL, 0xEBD5463ECAE90892ULL, 0x9CE2F3E0A7875FB0ULL, 
            0xDBB1760DA9A7A927ULL, 0x86DB4418898B9229ULL, 0x1000A73EB6A88740ULL, 0xA5BB4D85EDC61C4FULL
        }
    },
    {
        {
            0x65D4B891768CEAECULL, 0x460028BF4E4CF01CULL, 0x75681B9A431869E0ULL, 0xBA5BB286C0BE6F29ULL, 
            0xB38DDEFB5B0CC339ULL, 0xCD633CE05EA512B9ULL, 0x37E1201EAD4C9EDBULL, 0x08B5031B7EE98085ULL, 
            0x3708E6F33AF06793ULL, 0x825E938C321A2FF8ULL, 0x2E32C3A18EEE925DULL, 0x8C12FF1983D89EEEULL, 
            0x907354FE54AF6379ULL, 0x61DDEC5F19FFEA88ULL, 0xFAC053D9143C4E0FULL, 0xCB5C3B6EDA355E7FULL, 
            0x23287536A75EBC0FULL, 0xE09E8F25B6DA47B2ULL, 0x62B65BB0B8A80CCAULL, 0x278DB35C61671214ULL, 
            0xFF85EB32FC18E0D1ULL, 0xCC9B2212460B872AULL, 0xBFA85CDD812F86ABULL, 0x4BA624A169F67860ULL, 
            0x06AA9E47A24C17B6ULL, 0x572F329E6D696136ULL, 0x9EFCEBAB95D9A981ULL, 0x545B10373F32CD12ULL, 
            0xCE25BAFA0509B974ULL, 0x80608FEF582BC7B6ULL, 0x4E8658BE3012F230ULL, 0x20909E613C57EA56ULL
        },
        {
            0xFF0B55F95806878EULL, 0xE6ACA09E2200A629ULL, 0x0A106DF6F5DCA6CAULL, 0x0BC1FD27AFCB6496ULL, 
            0xF7B11BE2794801BAULL, 0xD131B300C6224517ULL, 0x0EF3443D7BF14689ULL, 0xACBB76B987CABDBAULL, 
            0xF0A9E31295EEDC89ULL, 0x50BA429A3BED19E2ULL, 0x92D285016A15AFBEULL, 0x567F388E77C72F9EULL, 
            0x99C8845A40F1B8A1ULL, 0x095ECDA596507509ULL, 0x9651D424D55CAEA9ULL, 0xD2EDBC9B7E6A1025ULL, 
            0x4FE514246B4FDE8FULL, 0x50FB05D2E007CD3CULL, 0x55C6C615A545104BULL, 0x893485DE986A8315ULL, 
            0x0680109228DB15BDULL, 0x2BDA7374CDB017B9ULL, 0xF9928C0D186D6B03ULL, 0xE5B432D6CC7641D9ULL, 
            0x74F4110267F60479ULL, 0x915D10EED9296CB0ULL, 0x01BE7BB56B7CBA2DULL, 0xD7C84A13668F9105ULL, 
            0xE99D2E7ED3D5782EULL, 0x45D885119D733D39ULL, 0xC891AC7CC9C0584BULL, 0xD1130B031E2E6790ULL
        },
        {
            0x00C837481B98B51FULL, 0xA2BB3D6CE097F838ULL, 0xCC9D06D903377BC3ULL, 0x1DD3B3026F3FC6C0ULL, 
            0xAEF0F7820509AF2FULL, 0x06443D66936FCC3EULL, 0xED523F64E2A39496ULL, 0x815BC9333A6656D2ULL, 
            0xBB585C2AEC035E52ULL, 0xEE4A758E3FB4A977ULL, 0x5DCFF294F84325F8ULL, 0xE7519DA7215B2117ULL, 
            0x91145C1146A6DD9EULL, 0x4A9DAC762C7CD8B9ULL, 0x9A9F87DC670A4A70ULL, 0x3216B31F01903995ULL, 
            0x64AB5A79DD64E7A3ULL, 0x7FD1B4D44D161880ULL, 0x253BAF808EDDAF62ULL, 0x234FDE74861F1382ULL, 
            0x07BC688FEC80D89AULL, 0xB3ED51D4E56EAAD4ULL, 0xAD47662312B7CF8BULL, 0xDF54158639477F35ULL, 
            0xE9B3C13F6CF5316DULL, 0xBC06D36FB4A3566FULL, 0x098088C75451C1BEULL, 0x8FB59329DC50AFC2ULL, 
            0x8D0CF67718461AB6ULL, 0xAA209D9DA97BFA14ULL, 0x6F77B5C8919B3A95ULL, 0x213B21476F2B037BULL
        },
        {
            0x03B2BC27D939CF31ULL, 0xD7F16E68A435EAADULL, 0xC1C3C697A33A85EAULL, 0x61674AC9EC646DDDULL, 
            0x5C8A129E96D2AC51ULL, 0x41455536C36BC02FULL, 0x5C9511DA04B3BD77ULL, 0x5454B8C7F0D273A8ULL, 
            0xCD3C289F90C520ADULL, 0x385855B6136798EEULL, 0x2F9583E8BDC6D820ULL, 0xC0E59C510D06EB05ULL, 
            0x20F52DB13D4B2352ULL, 0xFFFF8AD6D82065AFULL, 0x45A09B5A4F2159F5ULL, 0x27230E3770DDFCBFULL, 
            0x1A368E258E08A89EULL, 0xD76349582C9C59BAULL, 0x12AB67D1982ACADBULL, 0x5A931254A887B07CULL, 
            0xC76E9C4446D6897FULL, 0x6CAC32B92D6AC825ULL, 0xE9CACC1E94A4D29FULL, 0xE17FCD20242DFB28ULL, 
            0x45E16B4BF6084299ULL, 0x0ACE4E61ED2CA8ADULL, 0x6E092FBA0FD67D32ULL, 0xB37CD4A00023705AULL, 
            0x661980C169765FE9ULL, 0xE630EE66616608B5ULL, 0x9CD4658BE6EB4CFEULL, 0x2016945340F4FF83ULL
        },
        {
            0x4168E17B2FB04E67ULL, 0x1AB0FD8583DAF0C2ULL, 0xD1388E03F4F4060FULL, 0xE6391D18D7ADB16AULL, 
            0xFA05B38622024289ULL, 0x21F70CF7DB2DD8A9ULL, 0xB5BDF40C5D3E78C5ULL, 0xE50C38278F2AC34CULL, 
            0x8E600C47091857E1ULL, 0x07258A011BD96C5EULL, 0xDA982B5CD7A7BEABULL, 0x71FE6054337CDD0DULL, 
            0x70573C43E4A70A29ULL, 0x670E4AC43FD3195EULL, 0x9A3E988D53CFF8E9ULL, 0x333F57099D1D7E90ULL, 
            0x3AD1B7BF293D6F74ULL, 0xFB0FC942F2E459BDULL, 0x6A51495CE58F9CD0ULL, 0xFB83657C80ADA2FDULL, 
            0x6016762F5D2DF0D5ULL, 0xEEFECD040F70AA74ULL, 0xCF6914D7ACCA80ADULL, 0x4DF54A17EF3AF18FULL, 
            0x00F79D5F929B2160ULL, 0x61CBA9A1F4EF6F42ULL, 0x0EB3F5257A56356BULL, 0xA919D96639CC2F7BULL, 
            0xD92ED0F29F10732DULL, 0xCA1CE3CC5DC222F7ULL, 0xDEC4AC871601DB75ULL, 0xAE6AF8FDD58F45E3ULL
        },
        {
            0xDCCB93B0442BCCC0ULL, 0xB20672900DC8B3DEULL, 0xF2462050C6AEE42EULL, 0x2A42FC2ACE07B3D0ULL, 
            0x2ADD70AAC914CFECULL, 0x47BE15EFBA9D7971ULL, 0x62F0AA8FE06152CAULL, 0xAE97BCD9268FB62EULL, 
            0xC63336C1D9AFDA89ULL, 0xAAA77F10482A8DB3ULL, 0xEC5F9AE8348B24BFULL, 0x093250055F7ABDB2ULL, 
            0x29C88F9B7A6EE29CULL, 0x9A4E80F8FD223E37ULL, 0x7296FD9BEEFF8D61ULL, 0xCAE230E6BB0FBBD4ULL, 
            0x5BBADAEC49B30A67ULL, 0xF8801171A8672AFEULL, 0xC2A03B06AACB5091ULL, 0x1B3A0F0760EED207ULL, 
            0x08255F942269B1B9ULL, 0x90681844B6B2D159ULL, 0x5A35A59B0E17DC6CULL, 0x88B0A1C2757A9C4FULL, 
            0xA3B37518A71DC9EEULL, 0x9E7AB8714D9C4DD7ULL, 0x1CA420C8B069BBDFULL, 0x51E7849B7DFAC068ULL, 
            0xBC8C3D7C13920B98ULL, 0xC6794FD41C5A5175ULL, 0x8C1B114B779EC2EDULL, 0xB5E2E85DBF10683BULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseAConstants = {
    0xE5A8C214A4A82CADULL,
    0xCCA61E2105DC8655ULL,
    0xF094B3588CEB1354ULL,
    0xE5A8C214A4A82CADULL,
    0xCCA61E2105DC8655ULL,
    0xF094B3588CEB1354ULL,
    0x71055459B0711388ULL,
    0x8DF991508BC37859ULL,
    0x33,
    0x15,
    0x12,
    0x59,
    0x2B,
    0x50,
    0xCF,
    0xAD
};

const TwistDomainSaltSet Soccer::kPhaseBSalts = {
    {
        {
            0xCE6DD369C4180305ULL, 0xC1A154EB1E579999ULL, 0x633038C642BA678CULL, 0x8ABC869FA03E1D03ULL, 
            0x2B2DEEB07733142AULL, 0xAE2B8B88F92E5941ULL, 0xF3DCCE22D1927692ULL, 0x18B06CDD5B952DEFULL, 
            0x73C0CEE38993288EULL, 0x824584CEFAF79E88ULL, 0x66181B884A4480ADULL, 0x526170AE992D3E07ULL, 
            0xD1B08A099D283693ULL, 0x660175E9A70F0764ULL, 0x080D341AD3CB5FACULL, 0xE2D70FA81C414CABULL, 
            0xC0255B3DFD7D8C49ULL, 0xFF1E83B274E0506FULL, 0x992754962EBFC3A8ULL, 0x3095EE63B6D8FFDAULL, 
            0xD3F7E77B80AF85F1ULL, 0x9B62AB5DF4FD1714ULL, 0x0FC8D94E4130A5FAULL, 0x394B7F1BD1AF52B7ULL, 
            0xD78303619383FE72ULL, 0x188B662E84B56605ULL, 0x5E66FCFEFB4BF824ULL, 0xE8170479E18C5F4CULL, 
            0x5C49218EEC75FAEEULL, 0xA284B7B8B45C086EULL, 0x3AAB135623590D92ULL, 0x0F853D87F172FE5EULL
        },
        {
            0xE6D4019D1B4AA8E8ULL, 0xC6DC4FF2A0C0279EULL, 0xF2B8C3CDD0708544ULL, 0x6A1D69E8E9D703A1ULL, 
            0x49DFD02EA2FFDEECULL, 0xEEDEE8C0055C445AULL, 0x68E714D5DC9933B4ULL, 0x7436C7321DDBAAF5ULL, 
            0xE4C153EC091D8735ULL, 0x74B23F9B4872CD6FULL, 0xE715BCC6FBB392B0ULL, 0x1366577A41451D53ULL, 
            0x654FF3FBA19E47D8ULL, 0x94A132366ADF186AULL, 0x2771C05EE6F0EA6FULL, 0xF30930AAC1528A79ULL, 
            0xF8AE2E47587231F4ULL, 0x54294805BB6A0E78ULL, 0xCA83D11E6E1FEE64ULL, 0xA429A22C571C64BBULL, 
            0xA11E8144CDEE06D2ULL, 0x329D5935D864E4F1ULL, 0x2A58A7284F2D2307ULL, 0xD5E9608550609AF0ULL, 
            0x11511B0E4546D3B1ULL, 0x8E60AB6712D273E0ULL, 0x167982674A0B29F9ULL, 0xD4F601158202585CULL, 
            0xA8FA2FC687C58021ULL, 0x123C32911AE8FF2FULL, 0x1201CF5CC585AB14ULL, 0x198027C4F0E086E5ULL
        },
        {
            0xBE1FD7683373D779ULL, 0x35C0814B901B18A2ULL, 0x196840E261345C8CULL, 0xC3C9B2EF58673613ULL, 
            0x41F9BEE9AC9428E5ULL, 0x68D00F398B3B7DFCULL, 0x77AE5AB487BCB1B4ULL, 0xA8EB8CDC00464971ULL, 
            0x8DB4AB4B5617E10DULL, 0x60709F7CDC6A65AEULL, 0xEC4813B9A119960EULL, 0x5C025EEAEC2C3DC4ULL, 
            0xAA2473CBF6B590A8ULL, 0x442527D37F5E1E91ULL, 0x4EB5C6EAB00C15B2ULL, 0x68D3EBC3E1F35003ULL, 
            0xFAF55A639ACC8156ULL, 0xDB2514D77A96DC0FULL, 0xF270BFB2ADD079F6ULL, 0x0ABC04D69AA57F12ULL, 
            0x8010BACFB51B19A7ULL, 0x45017E69A98E3363ULL, 0xE99C8407EC87007BULL, 0x40E41916CDE880E8ULL, 
            0x84533646E590643BULL, 0xB3C7EAC4D8FA8CC4ULL, 0x95A170FC30734988ULL, 0x675AF203FAF550B5ULL, 
            0x1F807125B4EA4C7AULL, 0xCB9F6C48C752C806ULL, 0xEB2A70366C7299FEULL, 0x912673D06AD5199FULL
        },
        {
            0x671C0C6122A37771ULL, 0xFA7C71744E31A7C7ULL, 0xCD800EEC10374EDDULL, 0x94A6E10AA5C1A5F9ULL, 
            0x68EBA86DA89F6D96ULL, 0xAEF9A9FB84B2AF52ULL, 0x2DC0147CBCAEC223ULL, 0x251DB3969BC77746ULL, 
            0xE95097FEC621A72CULL, 0xCA9339239923DC1CULL, 0xF92160871154F7A6ULL, 0x4660DB8D313ADF86ULL, 
            0xEDA43269C5C328A8ULL, 0xD97AEF07EA3DDC8AULL, 0xD0E74C16F88276BEULL, 0x4949271D4AB5FFACULL, 
            0x1E509D74FD02F899ULL, 0x1818051B6F96DC93ULL, 0xD2EAD540009346EDULL, 0x19447EF1634C0F32ULL, 
            0x1CA3DD53784FF32EULL, 0x813BDA1376A9B5C8ULL, 0x3C4DE872F1808C67ULL, 0x71941C33B03BA46CULL, 
            0x43E7C2C6D9596BB1ULL, 0x0B20424E42A220FFULL, 0xD95A5C43909637F2ULL, 0x909C321CD205BAE7ULL, 
            0xC380F5DF3C9C4BBAULL, 0xA55A09B1A0E87137ULL, 0xE21E30ECAFB35F00ULL, 0x40797D933EBB087CULL
        },
        {
            0x1146628EC30B7A35ULL, 0xF781530535193EBAULL, 0x0CB6EA53F4A24354ULL, 0x7F394A21A5AE8D0AULL, 
            0xC37F0A8BAB2791B2ULL, 0x666D7ACA1D263DE7ULL, 0xF78A64AEDE19AE95ULL, 0xC94E1A582F809E66ULL, 
            0x8CBB88FA046CB163ULL, 0x6D35B7E726278C5DULL, 0x56B3FED6B179FE56ULL, 0xB8BD489E37210EB2ULL, 
            0xE4670FFA3F8ADDC4ULL, 0x08A95BD8D14FA965ULL, 0xCBEE920654F46122ULL, 0x152203BE88148AA6ULL, 
            0x6C346FF66CC2E0A6ULL, 0x19E90232485B14E1ULL, 0x2B2893917CE4C680ULL, 0xA46B114F4295EC41ULL, 
            0x36D4B77F23B58720ULL, 0xB4CD79A18FC59874ULL, 0xC7A1747B073BEDF9ULL, 0x6E379A075FB0B457ULL, 
            0x3160D0BEBAEE6FF9ULL, 0xBD16DE112277A531ULL, 0xC7842BEEE10EF6B7ULL, 0x231248C6B080A95AULL, 
            0xEF7CB56215DEEB4BULL, 0xA5BDD952ACBBEC64ULL, 0x1D6419BCA9A5C1A8ULL, 0x4395EC05058A8F82ULL
        },
        {
            0x00A23A3C6D8F014CULL, 0x0F7E961699178884ULL, 0x884004FF011D6610ULL, 0x9FBC0FB4C65EF6CDULL, 
            0xABF3DEBF9916291FULL, 0x67C7B4E70E82AC79ULL, 0x75BE63740972EB39ULL, 0x71FEFCB5664B2B5DULL, 
            0x08EC8841330BE5E8ULL, 0xB21042D1DDB1F323ULL, 0x0166AA4815B65369ULL, 0xA69505B816CE8520ULL, 
            0x9F9D83CAB51254E9ULL, 0x97876AA21E4C546DULL, 0x73D59C71499D5615ULL, 0x7A5B3CC5799B869AULL, 
            0x67950807348303C4ULL, 0x81EC54FF3B36BE64ULL, 0x6201B96495CCF134ULL, 0x4D37EB048CDF5229ULL, 
            0x327423A3A08C8697ULL, 0x7DA262AC82429F07ULL, 0xB1FD2FCD7D9A0E35ULL, 0x55D14B68627706F2ULL, 
            0xD81717EF97FBB15AULL, 0x357153B1CF4F8049ULL, 0xE381868BC0830AEAULL, 0xAC0ADB321CC0601CULL, 
            0xACE5DE4489B1F633ULL, 0xD00AA161C1032355ULL, 0x0930B7A28EAC8F10ULL, 0x60741EED9DBD1111ULL
        }
    },
    {
        {
            0xDE2C7AE9E06524B8ULL, 0x3AF147997EAD4505ULL, 0x36C0AD89A9B8ACD3ULL, 0x6EF31FF6000372D5ULL, 
            0xC7C4F30E8581C57BULL, 0xB3C986654FF3EB32ULL, 0xD507D5B00DE890D6ULL, 0xE023DD155AD8964FULL, 
            0xA2DEBB1AA2AE69B2ULL, 0x2BED9AE9EEE74A2BULL, 0x057FDBD31E430C50ULL, 0xF64B445E71119B88ULL, 
            0xE6E56D22FA210BA6ULL, 0xFD691F9AA07AE04FULL, 0x83594EAD31753C43ULL, 0x3271DDE2228BF5D8ULL, 
            0x32DCEF4A7D608D0EULL, 0xB1A68029B673CA50ULL, 0x9F7019470E35DAE4ULL, 0x01855F82F2978419ULL, 
            0x04868B7F0E7B96C9ULL, 0xBF462C5A19D1519FULL, 0xBD01154952CF6A42ULL, 0xBBA50869D8E3D65DULL, 
            0x74F2BEC4732250ACULL, 0xD3C18FEE78B08607ULL, 0x19DF1FFBCE732761ULL, 0x6B95B04CA38E1C08ULL, 
            0xF317BCE01E500504ULL, 0xF02639E51D5E50B3ULL, 0x75E4DDC04C42BC49ULL, 0xFD20AAD94A34C4C5ULL
        },
        {
            0x6CD73AF53537242DULL, 0x921323261B37BD3FULL, 0xB5C92861FD529464ULL, 0x34A4A7FE8740BDC5ULL, 
            0x0A402D0946888938ULL, 0x19CC3543A20D737CULL, 0x4C0B922194FBBC59ULL, 0x4DFB5959E28B6888ULL, 
            0x3F835EA90A8DC0CFULL, 0x6AE1DE4F272EBA66ULL, 0x0E17045A85A55823ULL, 0x0E1675D36057F51FULL, 
            0xD72CF65F73860FD9ULL, 0x0385125AD51996FCULL, 0x1C81AA65DEDB63E8ULL, 0x13B1338D3C90E568ULL, 
            0x3F5470F3C0CCE510ULL, 0x1E2D7F3E40D0287DULL, 0xE69AD2E1162EAED2ULL, 0x3CDE7233514D1F02ULL, 
            0x34FBDCB0BC20A3F9ULL, 0x1F8B069945FE670EULL, 0x6B271F6B6A7F3A34ULL, 0xC067F731D56EAAC1ULL, 
            0x0348D1DD2E079F5CULL, 0xF0DEBB1F62922EECULL, 0xB53A712682DB2610ULL, 0x3345BA2EF8749012ULL, 
            0x720E9029975F9219ULL, 0x6FFD55D8CF619038ULL, 0x464A4D26DEBD3304ULL, 0x243728994C73C0BFULL
        },
        {
            0xA780039A0B1D8A46ULL, 0xB2EA52088AB07BE2ULL, 0x5B1D33E4B63A830DULL, 0x8E359EFEBDBFC613ULL, 
            0x34ED31B31E59363DULL, 0x4CDB42FF8851D655ULL, 0xF40943BB3881FF47ULL, 0x48CED5D60922610AULL, 
            0x75E115DB84B016CBULL, 0x3295BF0F8BDDB53AULL, 0xBDA816B5DC7DA9FFULL, 0x78D8B6028F0AF10FULL, 
            0x472C69E14740BEE3ULL, 0xE88F2CFC62C5ACB6ULL, 0x6CAE8FB8F74343B0ULL, 0x3E026A3E68E6C0BDULL, 
            0xB5A1D98B30EB0D8BULL, 0xC0E74D867FD89203ULL, 0xD03488A552A7BE5FULL, 0xDDBCFC560ACF1569ULL, 
            0xB6EB78E7021E4C37ULL, 0x6570E4FEA5B385C7ULL, 0x80C248C5EE6D8C46ULL, 0x295FAFBE228D8E32ULL, 
            0xF3706F258542AF9FULL, 0xEBE6ECD2E66C522EULL, 0x27CEA856F49A689EULL, 0xC894A5ACC3B737E2ULL, 
            0xE82764AA8E526A39ULL, 0xA6019C17001E3BD1ULL, 0xB58AF12C93E3CDFEULL, 0x92FEA5F084396A28ULL
        },
        {
            0xFB11BAD12AD36B10ULL, 0x4206BF17DE71608BULL, 0xE7284998C83A2339ULL, 0x59FD4BB4330C9ABEULL, 
            0x0B3420C410046765ULL, 0x526EC7C3E7754879ULL, 0x98CB891CC884B437ULL, 0x95CC4A343A722BF0ULL, 
            0x7BF81FDC6CF97CD3ULL, 0xDF98ABE1E71EF105ULL, 0x78FD27833ACEDAD4ULL, 0x4F6D3375AD6069E1ULL, 
            0x3823183673AF0603ULL, 0x7C1EAF0E4A5201E3ULL, 0x79CA513DE8D1D74AULL, 0x2B64A115D513AFA4ULL, 
            0x5DB1B033D1470E72ULL, 0xB01916FB501DFD98ULL, 0xB2B096B6FB7EC329ULL, 0x83F60CA8EAC50009ULL, 
            0xE15F307435BBC4E5ULL, 0x2A90FDC0768A2D9BULL, 0xD60B08C41C6F23C7ULL, 0x67074639E4650618ULL, 
            0x4740164A4593ED79ULL, 0x97AB35F5769B2370ULL, 0x6A161210AEA17AC1ULL, 0xC63CBDA393429D27ULL, 
            0x201CCC41CD08F105ULL, 0x44B0DAAA71D928E3ULL, 0x7EA51231ED7FD6B4ULL, 0x9CC7CFFC12026470ULL
        },
        {
            0xD38012FE914D17F0ULL, 0x80BCC33FDEC41C5DULL, 0xAB9DE3D5CBEA2BF5ULL, 0x24E1C24009B1E8F9ULL, 
            0xD3DD4693805DA00AULL, 0xFE26E76CCAE00038ULL, 0x1807488E0DB04972ULL, 0x18154AE2F5FD1486ULL, 
            0x86FF6FDC92EDAE89ULL, 0x252B5F62C6F6EC9FULL, 0xBC0060C660DBB277ULL, 0xCF4A42C2341EEE4FULL, 
            0x1743B0FB33512B2DULL, 0x9B9A64DB00D6070EULL, 0x07E58833BB59C1CEULL, 0x0F7DB6EA37BEFC35ULL, 
            0x1C46326D7D191488ULL, 0xE1857ED4C174130DULL, 0xAE93339D512F0E4EULL, 0x823EAECCB8550C64ULL, 
            0x0A6A7815C71B2A27ULL, 0xD78F6380B722E35FULL, 0x2EDF2702FAA38D4DULL, 0x11D953F5B368A3AAULL, 
            0x287FDC35A296BF9BULL, 0xD09EB94BDF6B88B4ULL, 0x76FD565106C0A984ULL, 0x61554B6A7BD9C985ULL, 
            0xEA065874B3F6DD65ULL, 0xA1C7115E10373D6CULL, 0xE8A01B8ACFDDDE7DULL, 0x0407905194CDD6E2ULL
        },
        {
            0x92FEE82666431968ULL, 0xD2C163FD09B5C0BCULL, 0xD2198B4B7632E26FULL, 0x9D9196B94CDCCBF1ULL, 
            0xB56ED9166D7C2CCDULL, 0xD030BEF37158008CULL, 0xF936B359B3B61A23ULL, 0xB58A55FF1EAC0DC9ULL, 
            0x0D5910DB21495A48ULL, 0x7090A1E1BBA8C291ULL, 0xDAFA28BB8F666862ULL, 0xFCD18E9DFA41F1AEULL, 
            0xCFFA28B63F7991C4ULL, 0xF9491DBC389349FBULL, 0x4546791F5B1AC3E5ULL, 0xD514C52DC0696523ULL, 
            0xD0EC110DD3314B4BULL, 0xF7E4B398C24C7E71ULL, 0xA7C85674A7BFCFC3ULL, 0xEDEE42210226203AULL, 
            0xF5C47AF6BDA412B7ULL, 0x5396D67F3C4AD693ULL, 0x2377F8C1879993B4ULL, 0xB55BD4296A47EF69ULL, 
            0x4AE1D6D5866FA0F2ULL, 0x3A4A2204F90D1AC2ULL, 0xFE63B6C628CE383AULL, 0x094A609360456369ULL, 
            0x6F09DE5FD85049F4ULL, 0xFFFC6385667B017BULL, 0x6815F0CFA5BC1AA6ULL, 0x5DEB5CB5B978764BULL
        }
    },
    {
        {
            0xDEC3279EF2F3531DULL, 0x58E57D4E5E7A50CBULL, 0xAB1E0DA2888FA48DULL, 0x09371B861CC0571FULL, 
            0x554E2CD7E4E70391ULL, 0xD551B16BEC7CFBCBULL, 0x6A73DD738C707445ULL, 0xC3B4F5948FEA0F6FULL, 
            0x97AEEFB238D94077ULL, 0x8B4C7D757E22016BULL, 0x5E7DB3FEC82556F4ULL, 0x5AE11E6B14C5D1DCULL, 
            0xB1C1EABCF4B95F06ULL, 0x4DDFA79027308782ULL, 0xB61E13CFE087CAB6ULL, 0x4EAE65925E72E79AULL, 
            0xC41A32C7FCA19421ULL, 0x1F4B12BCA7ABC37EULL, 0x8C19041AC0F780C3ULL, 0x632DCAE19DEC317BULL, 
            0x02CDE8556F436F27ULL, 0xC60642BE005ECB6FULL, 0xFEC348128EF068CCULL, 0x2234916A5A2F9495ULL, 
            0x9FE56D58F6983E7AULL, 0xF74BD5859FE12C69ULL, 0xF0317D0FAEF39345ULL, 0x7B82CA73CDB2D455ULL, 
            0x9E2F07D01F39058DULL, 0x3E183B83F5DADD00ULL, 0xF45DF21D35C92AD1ULL, 0x740E40A4019A6A6BULL
        },
        {
            0x3412B803D3924822ULL, 0xD36E9ED3942C1BCFULL, 0x38C2AEFF06B62431ULL, 0xAB109E6A0BAF9ADDULL, 
            0x2FDB8A5204B2ABEAULL, 0x0C11F5325BFB2B8DULL, 0xAFF1E1540F3C263BULL, 0xA5B5BF523AB382EDULL, 
            0x3781C950598162A6ULL, 0xF5792FCD7A2DC82DULL, 0x6C00B1CC2A9D2111ULL, 0x0B72FFA783F8E8EFULL, 
            0x00359C9EE07B8682ULL, 0xC9D5A024DE1FDC9CULL, 0xD82A681F5AC2DCFCULL, 0x1C779C0F03E14D5CULL, 
            0x7E163372CB693047ULL, 0x05DE22CBFE1BBB88ULL, 0x2A385D9AFB93B7D4ULL, 0x5E0F64C7D0A06227ULL, 
            0xDC56446585BF2C34ULL, 0xAE4DD50904313EB4ULL, 0xCA5C5DC5869E7D27ULL, 0x6B1BF181B4439DC6ULL, 
            0x95D1575C630E57CAULL, 0xAE1665640755E851ULL, 0xB93FDFD05C1EC1EDULL, 0xEA8F46AAF6B09F45ULL, 
            0x15E58964A2572765ULL, 0x573423FE4044C599ULL, 0xCA1E123ECAAA9A9AULL, 0x482869D3FC913DF2ULL
        },
        {
            0x43485A374A13B8AEULL, 0x66D7C78021AD43E6ULL, 0xBCBF05FF310F2B85ULL, 0x5C1B55FC921821C8ULL, 
            0xE63B383037367BA8ULL, 0x1942C845D6266987ULL, 0x9ABCABACF9A2B862ULL, 0x55A104B2AECECB5EULL, 
            0x26CBCFCF4A9F7D96ULL, 0x8A89F38C096FC99AULL, 0x41D3A66433E6F3FEULL, 0xF64AC066CFC03601ULL, 
            0xF53E3A8D188A45F6ULL, 0xF99C48EBE7EBD16DULL, 0xA06548293DD42CCFULL, 0x7CE4C357DEE6D807ULL, 
            0xCE7D7DB60BD49DD5ULL, 0xB90118335CDF74E9ULL, 0x1BFA35E2D1149CFEULL, 0x8570D1B76742EAEDULL, 
            0x2D28F19CD3104E04ULL, 0x1DBF2AD987A8299EULL, 0x6ABF46AD58BF0282ULL, 0xF5FA19EF7DAD8AF7ULL, 
            0x8020B4C01B752225ULL, 0xC24078525E20AC73ULL, 0xF29BABF519E77D06ULL, 0xCEBFB5725E9918ABULL, 
            0x60C70E318FECF9FFULL, 0x91197D84B65F5C12ULL, 0xE45098EB39F73515ULL, 0x432D121DBE84C6FDULL
        },
        {
            0x5B8291B3D25819C0ULL, 0x6EA19F43972F4561ULL, 0x1AAB66E824D7E5A8ULL, 0xE422389EBFC048E0ULL, 
            0xA2EA4ECD0A721413ULL, 0xB993B3B2CA611A92ULL, 0x9187682B600E4E64ULL, 0x213691A0D7917207ULL, 
            0x572A4798EE18C77CULL, 0x1C44CDB51920D290ULL, 0xC7F03D1166B0112EULL, 0x8003B89AC4BC773DULL, 
            0x10A269250B64E4EBULL, 0x3F0253BD76D9F2A4ULL, 0x831C809C1FCC47ADULL, 0xD18870E500965110ULL, 
            0x35292E541B3D3BBDULL, 0x0D42D617F9F20A87ULL, 0x4741F7C376BBF487ULL, 0x1F0AD31232FC2E76ULL, 
            0x6CE0534CCA6AB73AULL, 0x4FAA58CD08F43E1DULL, 0x68A6632D091219A5ULL, 0x135B92503F7B4FCDULL, 
            0x28206AB03F00BF74ULL, 0x43D23927B0E1578FULL, 0xBDF68798FAA01CB5ULL, 0x2FF2F825826A9BA9ULL, 
            0x8692680C89108FD3ULL, 0x464EFC087D71A031ULL, 0xE2F2E1E295EFB980ULL, 0x19F740698AA67ABDULL
        },
        {
            0x196ABBA27E579C18ULL, 0xD1E736DEB87D1DE9ULL, 0x5D76B24411A3E809ULL, 0x8A7FE1C9C977F5A9ULL, 
            0x511ECD4F6B6B7B69ULL, 0xB478F96406B3629BULL, 0x526B8C4F92282D32ULL, 0x7F5395CB3BF17C48ULL, 
            0x1E50F148B862A131ULL, 0x79882FE09B02E42FULL, 0x3FD1EE4FEC64256FULL, 0x37569391BB1A8D71ULL, 
            0x2C97C1B90624E54BULL, 0x5A77C585F1A3540AULL, 0xB9E791B7953FA446ULL, 0xBE26D25FFF82B588ULL, 
            0x2FA99E6882308959ULL, 0xF8F3FBD5E6B4D168ULL, 0x1465A3800A017737ULL, 0xE9FD0EF77C3F965CULL, 
            0x5CA4F923F0EEAB2DULL, 0x713BCA0EE1CD5494ULL, 0x4896C09DD27EE0AFULL, 0x6BD5DE2904D7149BULL, 
            0x2C442FBDBDEE061BULL, 0x2213F0464D24CCDEULL, 0xCD8B21516ADDFC1EULL, 0xA9D68BF3D35C1964ULL, 
            0xD90A812886143EEDULL, 0x7DC8ECBF78867C46ULL, 0xA20C1F6E097EE36CULL, 0x21E97C9B7C082812ULL
        },
        {
            0x46ABF0F58B6EA546ULL, 0xFAF8C19B6D1D2C1AULL, 0x742ABF663D1F7E9FULL, 0xD17F311798004696ULL, 
            0x81F9EC05A3AAD8A7ULL, 0x26EC19107A68880EULL, 0x068843A61B028421ULL, 0xB1BDD94C7716F6E1ULL, 
            0x35A6EBED441A0896ULL, 0xDB6CE19315DEDB2FULL, 0x3435A576F2594E5EULL, 0x7F2B4ED24A7157E9ULL, 
            0x6B999BACA39F6B3DULL, 0x96766F618148DB46ULL, 0x5E4357BC4B60BCB4ULL, 0xF4E7034A02016944ULL, 
            0xAC4C7CE4D0C163F8ULL, 0xE85ED6C293109FFCULL, 0x7EACB8F381DA0E7BULL, 0x5DF97D5D7E985D93ULL, 
            0x3694357D5BDBAA6EULL, 0x0CC6C3138E8526F7ULL, 0x5DDA32EDF0670EE1ULL, 0x277D41F5850BC959ULL, 
            0x51D253AE8478AEB6ULL, 0xD70523655C74A221ULL, 0x74E455F2EA2B964CULL, 0x0DF74E031B24B4C0ULL, 
            0x65BFC5599DA7CFBBULL, 0xF00A20FE40C037E9ULL, 0x94DEDA80EE95CA86ULL, 0x2C0EE2E047262A12ULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseBConstants = {
    0xBE539735CA2A2AC0ULL,
    0xA3AD53021124FD11ULL,
    0x2FF03A68E223BF0EULL,
    0xBE539735CA2A2AC0ULL,
    0xA3AD53021124FD11ULL,
    0x2FF03A68E223BF0EULL,
    0x391F16DAC8924735ULL,
    0x799AACA245752002ULL,
    0x53,
    0x0C,
    0x10,
    0x78,
    0xD0,
    0xA7,
    0x09,
    0x23
};

const TwistDomainSaltSet Soccer::kPhaseCSalts = {
    {
        {
            0xBAEDF0146013ED4FULL, 0xCD7AAE01CE0DA64BULL, 0x5FBD75630C7521FAULL, 0x3CD8A0AAECA35E61ULL, 
            0xE15DD67E0E0EF688ULL, 0x56B235962EE08401ULL, 0x469121FAE74F4DB3ULL, 0x985D80133980495FULL, 
            0x8794A87AEED0276AULL, 0x1BE46C49609E4101ULL, 0xF0D2E54C4C32587BULL, 0xEC7FED7CC580EE92ULL, 
            0x8DE61F5A0CCA476EULL, 0x090A3700B05A2871ULL, 0xBF4442E67A551ADEULL, 0x3BF90EAFB902FD04ULL, 
            0xD83BF35178FFF7A7ULL, 0xDC3F65D7B28451E2ULL, 0x1BCB8BCB4C4E739FULL, 0xB18E680ADF98E881ULL, 
            0x871AE642DAF863C6ULL, 0xDB0BC49E274B8D91ULL, 0x6A580D1A432218B0ULL, 0xE72418740E765985ULL, 
            0x1D509D714CF9DB2EULL, 0x165CDFC6F5A284E1ULL, 0x076FAB6D8EAA3A3EULL, 0xA543E75F0E5A9A32ULL, 
            0x59B7F0962429EC12ULL, 0xBE5267A9906D7779ULL, 0x52BDF7F4441E6BB9ULL, 0x388ACDCCAED295DCULL
        },
        {
            0xACAB38B8B02E5137ULL, 0x4B0E6AC1412AD822ULL, 0xE0926883AEB7A845ULL, 0x892A8219653AD251ULL, 
            0x7F59EC63653A2035ULL, 0xB712A67C1CBB4A7BULL, 0x8D5EA1B296E4F3F8ULL, 0xE7F8990E60230C6CULL, 
            0x3A84D9B5872ADA68ULL, 0xB3A6A29096E48539ULL, 0xE0DDA3FAAABFE3F7ULL, 0x3E174F669A4A7ED1ULL, 
            0xEFAA42DB49C3BFDFULL, 0x9122EC0D2E74E0C6ULL, 0xA114D8B0DEC9ED13ULL, 0x0E02B50AA247E938ULL, 
            0x4691AC749CF64455ULL, 0x8C8AA0889810FC2CULL, 0xB9B4C9E5E6404CF2ULL, 0xCAEAC3E9763184F7ULL, 
            0x0E7A510178595A93ULL, 0x66850EE92DE54A94ULL, 0x334B3EFF569E45B2ULL, 0x3022F8AAD0A31741ULL, 
            0x3A9AF7799512AEA0ULL, 0x2AF7A17185599C6CULL, 0x058631B8E1FB8B11ULL, 0xCF459531971BF177ULL, 
            0xAA50CFC257BC3C0EULL, 0xE0FBCDA2A6590A19ULL, 0xFE9F73DF4289C455ULL, 0xBBC8270CA67E6FA3ULL
        },
        {
            0x94ABB2BC6E903E86ULL, 0x95EB0A59743B8685ULL, 0x8C76212972DCA1A5ULL, 0x98A1A5C218E62E7FULL, 
            0x0FD88509A785F919ULL, 0x19E64426D0BA2BC3ULL, 0xFECDEEDA28B63896ULL, 0xA9A9DD16BB068F9EULL, 
            0x00F5C78A2AAF2888ULL, 0x003FC555C2350930ULL, 0x37BCBB7664B91D4DULL, 0x52FCDFA1BCBCC6F6ULL, 
            0xF6523F021F878332ULL, 0xE75993E241342C89ULL, 0x5CBEA132B0E11070ULL, 0xD2C97FB9F16573C1ULL, 
            0x1D064CC5E10EF0B0ULL, 0x123797341AB9BAE4ULL, 0xEBE8216F265F988FULL, 0x0A60077BDB34C235ULL, 
            0x89A18668601E9CF3ULL, 0x1558E4C0B58E87A8ULL, 0xF24227A1D0FFCC3FULL, 0xAF0E77006884DEB1ULL, 
            0xB26994851EA2E4C4ULL, 0xBE8D51C1880710CDULL, 0xA3A4D95F176C27D0ULL, 0xBE00CCFD7786A0BEULL, 
            0x914BC40194838DF1ULL, 0x1CDD1FB34C3FE321ULL, 0x09B15F24B29E3FE7ULL, 0xD8C09E57B9BF296AULL
        },
        {
            0xEABFC18858764977ULL, 0x1AAFAB6983A39D7EULL, 0xE9E6DC4BF01592E8ULL, 0x413B99FD36B82205ULL, 
            0x4BFAB994A63CD51AULL, 0xA86BFF9B84445C8EULL, 0xC02E20E3BE3533DFULL, 0x846F0449D65089AFULL, 
            0xEF96B178BD473FC5ULL, 0xE7254DE11E723BBCULL, 0x7A4733690F0558EAULL, 0x65FAD8F6D5C53764ULL, 
            0x9AC33D2D0301512AULL, 0x3B9D2CF295BB3071ULL, 0x782946DEAF1318BBULL, 0xF29132721CB47A43ULL, 
            0x1B008AC57D7191A1ULL, 0x079B937653A9E0A3ULL, 0xC32F6D328132288AULL, 0x76C6DF03ECEF32ADULL, 
            0x33EF582A5BB06401ULL, 0xB38016D9921FE5F7ULL, 0xE0FCFF96195DDA2DULL, 0x04E35822EA2F7ACEULL, 
            0x1296EBD6C4223EECULL, 0x99B7F15CC95F9B81ULL, 0xC55B2151D255B67AULL, 0x0DCF9883E3E1C676ULL, 
            0xFD54FBB74D9033A0ULL, 0x90510BA352114FDFULL, 0x510E1146C3861915ULL, 0xA402776A947FA742ULL
        },
        {
            0xA9D3E68DAD6173DFULL, 0x191D2AD09B60D8B9ULL, 0x87BEC364344A3908ULL, 0xC60D825671B7C137ULL, 
            0xE0BE52F48A4DAAC7ULL, 0x44C19629952D7862ULL, 0x636A8F46B4814EC8ULL, 0xDFC1CD636D30D7FBULL, 
            0x96197DB4EE9CF1E1ULL, 0xA2451A54048D5F02ULL, 0x3534F945DA8394E8ULL, 0x96B260721FE47ED2ULL, 
            0x6392560460E1AE86ULL, 0xB1112599503078D3ULL, 0x03947DB1A3198021ULL, 0x1DC6ED2567AB5488ULL, 
            0x64DFFB43F1BA00E5ULL, 0x1EFA1825B9E63862ULL, 0xA987B6DD93659084ULL, 0x504E2E7C73AFF1D0ULL, 
            0xB8112AABB90A6E09ULL, 0xA80B7DC034FD6E7FULL, 0x178EEC1CCF423FF6ULL, 0xBC1612E92AD8D2C9ULL, 
            0x83BD1FB207A2D4ABULL, 0xED4DC68D1889E3C7ULL, 0x7928EB81DB6F3EBFULL, 0xB53AE33E6DC878C5ULL, 
            0x894FBCA3C5665517ULL, 0xE832F18DD839AE4EULL, 0x846DED4535CF8F7EULL, 0x52C6A1AEFF3742E9ULL
        },
        {
            0x584269DC62CF1775ULL, 0x187C0F9C468A9BE9ULL, 0x85295FE9326C02A1ULL, 0xA4AC5D0B6E3F2F38ULL, 
            0x9D5B51B5ABF044FEULL, 0x01496EAD11A5EB71ULL, 0xC7238C7392FD53FCULL, 0xDCA0CBB3D8140066ULL, 
            0x0022ACB15EA2E99CULL, 0xABF65CCB658D240BULL, 0x8BF4200E8038AB39ULL, 0xC38D8E1D814766C6ULL, 
            0x403C8970EB88CD08ULL, 0xBEE90F9E61E82F6DULL, 0xD7AC8052322845EBULL, 0xECF78122112E31A4ULL, 
            0x8BFF437A08991D1CULL, 0xE457F2E8A18C3652ULL, 0x7C10FC68FB41F41DULL, 0xF45868D1B509AE12ULL, 
            0x5EA9D5AB4732D4E5ULL, 0xCB0B53F2FC739502ULL, 0x8D1F367F026069C7ULL, 0x86F26E3238A26894ULL, 
            0xC0485190F4092A62ULL, 0x509FA49539241ACAULL, 0xDDAE23714C64E1DEULL, 0x1B495C3150285140ULL, 
            0x8F6023086B6F23FFULL, 0x5D4937A235A3F76CULL, 0x9EE16B6DE15CBDE3ULL, 0x02F076210F2F71F4ULL
        }
    },
    {
        {
            0x3885EA756E868D74ULL, 0xA14BF2C7662926A5ULL, 0xD9228EF20B6D8D63ULL, 0xF66B0CF333275956ULL, 
            0x4EB46F59FE73C096ULL, 0x21C5F586D311B988ULL, 0x5DDF818BAA82A66BULL, 0xE917B83866E1BC12ULL, 
            0x167AFF27706AB7FFULL, 0x8BBA90CD13C8EA63ULL, 0x60A2B3FBF5ECE30DULL, 0x4FCE633ABEA1D8D6ULL, 
            0x85805F31CDBABE12ULL, 0x4F941D913F5ED840ULL, 0x5623FFE788490520ULL, 0xA514DE7ACA97E118ULL, 
            0x9D32E294A63F18CCULL, 0x0DAD98B4F817936DULL, 0xA22341FA3FA3B971ULL, 0x4783D9884E0EE2B6ULL, 
            0x5E4F7F15DDE2D8ACULL, 0x60845CAC8CB1270AULL, 0x02B53871DD4D4FD3ULL, 0x06131376ADDC791FULL, 
            0x30B8F4400EA25039ULL, 0x25D0F21B340A7EF7ULL, 0x745BA7171D147BC1ULL, 0x1540EEEFDB1CAA32ULL, 
            0xB18F95EE99E6900DULL, 0x29DE8FE24C3A02FBULL, 0xE63F431C730106ECULL, 0xCE38CBA8C8BBBFB5ULL
        },
        {
            0x714AE342B5E106E7ULL, 0x0341BD87D956CFDAULL, 0x30122403D97839E6ULL, 0xB38F432DC40F3135ULL, 
            0x79679DFE6398DD52ULL, 0x64972636FC10E534ULL, 0x49C7D412D603B522ULL, 0x168DF68AEA362895ULL, 
            0xBCD2DE9F787FA54EULL, 0xD5011141B2C3A288ULL, 0xE37C0901556F5844ULL, 0x5E635457806E4BF2ULL, 
            0x095E4D1A74822F39ULL, 0x969913758A8B2C8EULL, 0xA77DAE952249EF1AULL, 0x50EA2BF778761572ULL, 
            0x19D6C117BF6AE9DDULL, 0xE506622415741CABULL, 0x80BE534434C79F9BULL, 0x23451E4ACF4ACDA7ULL, 
            0x2EAC4F2BE5760C78ULL, 0x57B7E91EEC9696B4ULL, 0xF17F8613B4ECA156ULL, 0x25712A74B2BE63A0ULL, 
            0x4C223CA0562B0CCAULL, 0x684B0461DF364733ULL, 0xE3CC3CBFE8F919CCULL, 0x4AF9485DE7E0A674ULL, 
            0x008CDE3823930518ULL, 0xA2613DEB75F7E284ULL, 0x9F081628D1E90EF4ULL, 0x677A0219CF87CB82ULL
        },
        {
            0x27815B926E904420ULL, 0x0383B0EFAE2F06C4ULL, 0xC2CA859B971D31D4ULL, 0xCFB4E8D182ECD699ULL, 
            0xCD15105D77C9A654ULL, 0x5D58B117FD607DCAULL, 0x7B0B4FD11423BC4BULL, 0x7DECAF705797D20BULL, 
            0xE0560120074696C4ULL, 0x1A6DB3CFF4722A4CULL, 0x617FCAEE943D54ACULL, 0xAEC4331DDBE2D2E3ULL, 
            0x664C0ED203320B17ULL, 0x69AB0625E2B9CD1FULL, 0x4129056DF1068A52ULL, 0xC6280CCFBCC45A95ULL, 
            0x32D9EE94DF145E40ULL, 0xAF223CD988934AB1ULL, 0xAF1AB8BD007E000FULL, 0x6D22DF2D19160436ULL, 
            0x83DA8188B9B65973ULL, 0xFB62BC30759BD449ULL, 0x7CE7932B4F6E92E6ULL, 0x602A160B7FEF0A7AULL, 
            0x9F45DBEF0B87C824ULL, 0x56BC28564DC22DB5ULL, 0xEA1DFE6C07B8DD2CULL, 0xF5336C663E8F8072ULL, 
            0x261AAFC22ED5161AULL, 0xDBD3B67D5C647FA7ULL, 0xEA4F7D41DB9C5D5FULL, 0x5A499584B3606E58ULL
        },
        {
            0x34F5BBD120E3D302ULL, 0x322444F0A2A7F7F9ULL, 0xEEE00A7D1BCDD1C2ULL, 0x71C2F0560E4E20E4ULL, 
            0x7281C46D540F037EULL, 0x4F084BCD9FBCBD45ULL, 0x923DD0366843A9ACULL, 0x97D39AF3845033DFULL, 
            0x729D21FA93EC7596ULL, 0x6CCF54E26FF9E5D6ULL, 0xE02461678D553279ULL, 0x7ED420A7AC95DCBEULL, 
            0xE568F7DD232470A6ULL, 0x9A1F6B693E4EFFB5ULL, 0xD47CC41DAB4C693CULL, 0x588E37E25AFF05C9ULL, 
            0x02D1813B8CCBF852ULL, 0x03CB8A7974868A1FULL, 0xE6F0F9DC05797EEAULL, 0xCFBCBD327E548052ULL, 
            0x979964022C025827ULL, 0x6206B4602EFB5789ULL, 0x76CC79F2B2DFE0FBULL, 0x956C73F0B3DC3C80ULL, 
            0x7D586AF96AC9011AULL, 0x94881A7CCF8403EBULL, 0xDB592597966B4A17ULL, 0x118E16634F43E799ULL, 
            0x4A831220285E4881ULL, 0x622178ADAD859B18ULL, 0xE73CB9CC15BF7D95ULL, 0x09DA31B22AC80AECULL
        },
        {
            0x3001DFAFFCECA790ULL, 0x1EDDF4528C04E6D8ULL, 0xD2CE9653080FAFEAULL, 0x96BD894984413550ULL, 
            0x14AF0274D2DD0DB0ULL, 0x99522D216390C9CEULL, 0xA2ED49CD310DA102ULL, 0x835C5694BCCCB642ULL, 
            0xCC30A9C548651B43ULL, 0x3946502D4B55BA51ULL, 0x211B8CF8988371D6ULL, 0xE2273C7EB9A45DF6ULL, 
            0x2A17C3B03FA95EA5ULL, 0xBCA85057DFE58B96ULL, 0x7C1742C0814D5A25ULL, 0x29198F378FE552CFULL, 
            0x88E0B40913B77729ULL, 0x03F7FDD805FA0FD0ULL, 0x0929F9D7DC65220EULL, 0x219B1ECEC168B16DULL, 
            0x40BCF21A65BF5B8BULL, 0x4ED643A025ACA53EULL, 0xAB779838716A5EF4ULL, 0xD4FB3AE2DC598201ULL, 
            0xDE76084D781A7C7BULL, 0x35CF62A7AE959B4BULL, 0x16A0590B9D64722BULL, 0x331E8A4EFAEDAA81ULL, 
            0x43445D8D57213090ULL, 0x772FEF48C60AE28BULL, 0xE29043386FB30658ULL, 0x07DBD1C7DF870100ULL
        },
        {
            0x3499C9F1B67F978EULL, 0xB127823B3BF0E735ULL, 0x693F3E01C89EEFEEULL, 0xAABAC5574C43AD60ULL, 
            0xF8BC1BBE9D4B4FB9ULL, 0x04634965AB5AA156ULL, 0x5CF2DE0D75B1B98BULL, 0x63F11BA3E1BA31F4ULL, 
            0x115808D8273F6E27ULL, 0x339D2A219B1CC709ULL, 0xEA369AA1CFBE669BULL, 0xA022F0531A528E51ULL, 
            0xCC6B5B56ACAB84ECULL, 0x20136DBCB00419B8ULL, 0x11FC43547164FFEEULL, 0x3DA52F947ECE5B86ULL, 
            0x26563221CA187481ULL, 0xEE7A77D04549C78DULL, 0x7ADDC8BE99841811ULL, 0x670E3B9698278A9DULL, 
            0x80633ABC64057396ULL, 0xC5E5AE4872D404FEULL, 0x034D3816ADD425F0ULL, 0x8060EB95EAE2314BULL, 
            0x5582751A75C7A665ULL, 0xBF0E84C6A7BB294BULL, 0x23F2DA59673CF42EULL, 0x7223EDEA2AC5437DULL, 
            0x6B4DB1F002ABD732ULL, 0x12DC39B7AD87066CULL, 0x590C796283736CEEULL, 0xAB776BEA9C1FD91AULL
        }
    },
    {
        {
            0x140275569AE2FE18ULL, 0xF6D4848F4AF2895EULL, 0x69164B69002D0E4CULL, 0x82FEE1B3ED80A54CULL, 
            0x4E246CD91935311BULL, 0xDCBD795C3913C431ULL, 0x437A7D3EE7F0118EULL, 0xE68567B1CEABE1FBULL, 
            0xD6181716A5A182B9ULL, 0xB895A906DA4560E9ULL, 0x30DCECCD7FAA3903ULL, 0x8C02568B4FA7D021ULL, 
            0xDF590E54C4D4EEE3ULL, 0x81721186855F8D4BULL, 0x21FE9F03AD226B4CULL, 0xD49575CCA9743898ULL, 
            0x62556FB22746B9BBULL, 0x2A7503BA2B5FEC87ULL, 0xBF7DC62067FD2814ULL, 0x6F1DC6B6D07393DEULL, 
            0x382489102EB9FEE5ULL, 0xE26EFFB4B7C8758DULL, 0x4967D0E0912D83C1ULL, 0x28FEBF40F1A604EBULL, 
            0x62CEE28C784BE45FULL, 0xDC7E52BDCD5D06ACULL, 0x3DD69164F1BAA0F8ULL, 0x25FEB71EF6622E41ULL, 
            0x83FD0F1DBBD41E15ULL, 0x5AEF432071F30534ULL, 0x05AB8C5DEFB24F2EULL, 0x6450D9C8F349FE1FULL
        },
        {
            0x7C41299E35FF3BDDULL, 0x3C56D80FF66D083FULL, 0x94497262BC82BB52ULL, 0xB6AB77FA968B93C7ULL, 
            0x328D056A0D252441ULL, 0xF9F60C46C7D7820DULL, 0xCF5FE0A9317BBF91ULL, 0xECE918314635AD4DULL, 
            0x5430F1D6DE1AB2E3ULL, 0xBAAEC8A918448CAFULL, 0xE5B23E9DD4B574FBULL, 0x6DE8302C773203F5ULL, 
            0x3BF567AC3DB91679ULL, 0x3D0F3F9A4CB4EA59ULL, 0x045E0C7093132B2DULL, 0xD6D710720427FDEFULL, 
            0x3F958B08F370A9CCULL, 0xE2821D72E02406B8ULL, 0x4A62F9D9F3686DFCULL, 0x9C3B0D8B559B9DC7ULL, 
            0x4D15620C6220BF07ULL, 0xEE4431DA478FAF8BULL, 0x0A29D74058733BCDULL, 0x697FDF972ECF8DDCULL, 
            0x36A52CE7104FD20CULL, 0x1FDB49D518423829ULL, 0xD2381B9594B234AEULL, 0x6CC78AEB900AC3CBULL, 
            0x5E1C07FAF81A2D76ULL, 0xE35F427159A32CF9ULL, 0x1BB1CA7D7EABE367ULL, 0x4F1C0216A2907587ULL
        },
        {
            0xB6628A0345526DFBULL, 0x9D83E1AB1C9809F9ULL, 0xE84472D4F6FF78E8ULL, 0xF31F4F105BB062E0ULL, 
            0x3802A9C42AD93647ULL, 0xA9A24AE5AD545C60ULL, 0x792F68E2BAFFC190ULL, 0x7BBFA98E7D558DA4ULL, 
            0x8C37CADED70A25B8ULL, 0x7880DABFBBFDF361ULL, 0x21B209B6006563BAULL, 0xEBE63E22C74CDD95ULL, 
            0xB8349DBF34B889ACULL, 0xF58F2DCE95FD486FULL, 0x7F78712CEE8E1E2DULL, 0x49455E32D8DCB911ULL, 
            0x835DE920FBF3E881ULL, 0x66D154C2ABAB3E8AULL, 0x44826004DFE13BBFULL, 0xFAE7AEE1A128F5FCULL, 
            0x028AC22912385A65ULL, 0x6FBC90406D56DA9FULL, 0x3CA74D8ED8ECC3CBULL, 0x299B2003392BA44BULL, 
            0xF3917FF4313EC6F4ULL, 0x5DCFC359F976BE35ULL, 0x57D4589B650E2397ULL, 0x401F7AAE5050339EULL, 
            0x39E2076EFA086054ULL, 0x4A2BE3AA36F1A71AULL, 0xE5B8164157EF80FAULL, 0x7CF30DB0B9F3307DULL
        },
        {
            0x1D7ADCB72ECDB367ULL, 0x4B9F2BAD62022938ULL, 0x9E968B6983BCBE3DULL, 0xE11AE9F770DA98BCULL, 
            0x1D86ECFB508AA9B0ULL, 0xD59314C12E45A93CULL, 0x9CFB491C17952643ULL, 0xC8E98C91C27F2247ULL, 
            0x255D7A0308169758ULL, 0x72EDE20DD48996DEULL, 0xD6DFFF11811A92AFULL, 0xF15ECF9F5C7BE55CULL, 
            0x63699337FB40415EULL, 0x6CF7BA9FF877585CULL, 0x947EAA0C9DFE158AULL, 0x8DD9794A4D7A991EULL, 
            0x4B0F51AD7188EF60ULL, 0x4E084E5CBA603E46ULL, 0x0DB49509510FF59FULL, 0xFA50A0D5A7A0EFBFULL, 
            0xF271A0DEC87AEC8FULL, 0x830606D977BA8683ULL, 0x596E9D9981DC7F2AULL, 0x83AB077A83EA875DULL, 
            0xB6DAE10976635935ULL, 0xD7EFE8F85E15E9F6ULL, 0x0555423D8B9EFA1CULL, 0x93D1F71383016F96ULL, 
            0xFC42929A72A20218ULL, 0x378C7BA8C226C561ULL, 0x3AC96360489BFD15ULL, 0xFAA8D010397C8CD6ULL
        },
        {
            0x069E99E91F9706D6ULL, 0x4AC1F702D3E8897CULL, 0x57AFD04EC2864270ULL, 0xF3051F765392723EULL, 
            0x2A29A364E374F5A5ULL, 0xF661D5D21B6CCD9EULL, 0x828C78AC8DF26ED1ULL, 0xCFA01A60C2BB13F4ULL, 
            0xE163AA7E50507804ULL, 0xFF507B56D81200CFULL, 0xF86DF5A198C0A4F0ULL, 0xE28E697281FD1797ULL, 
            0x70C605FB92EFE045ULL, 0x9A20779F9139A077ULL, 0x6FDE8CF48C37417BULL, 0xA50D8DB27FFF8D56ULL, 
            0x4D28062F4528F344ULL, 0xC72CDCA48D23126EULL, 0xCDFFDD3CC7A0AB6DULL, 0xB051FE7CB6D39165ULL, 
            0x6052C0FA6AAB6F8FULL, 0xDA2C6758D99B6886ULL, 0x1334F7150690A855ULL, 0xB12649F39A246272ULL, 
            0x8D69D7962E5040D0ULL, 0xD429D68559E42206ULL, 0xB3D548F690E2E25FULL, 0x9D98F260D7F86FA2ULL, 
            0xC5BE10177C4E9500ULL, 0x29DF29F90F70B0BDULL, 0xBABBF2ACE516DBCDULL, 0x08B6578FC2350FC2ULL
        },
        {
            0xA9E604DC772F6B65ULL, 0xB7CC02530CC79A00ULL, 0x36CECFE18FF571DDULL, 0x39F12814CB50BDF7ULL, 
            0xBA23FFAB06499872ULL, 0x620F5B518B513038ULL, 0x14925184D0313CCAULL, 0x4E59BCEA5059DC4BULL, 
            0x9A97660DA6F18D9CULL, 0xDA867F58D0EA6493ULL, 0x50E234D34302D909ULL, 0x36756A03EB4B4DE9ULL, 
            0xD942EC6EDFD81511ULL, 0x6BE7E43B272FC1B3ULL, 0x40B433E1B25A06B9ULL, 0x577630652880F1C7ULL, 
            0x5402D0998B6553F0ULL, 0x09586A0AB2D8A124ULL, 0x4B1993D08950B77BULL, 0x1421AD70E0688141ULL, 
            0x05AFF15FC68C0758ULL, 0x65D903BC3073A6A0ULL, 0x2CDC33E5473AA40FULL, 0x28CB8403B1F4CDA8ULL, 
            0xCB980A9C2AAAA44CULL, 0x6FA82FBA30AC4FCDULL, 0x209F0346C93C0E96ULL, 0x0198BB2040431B46ULL, 
            0x517ADC7A6666B1F7ULL, 0x0D2173C27D86DE9AULL, 0x00BB21A056902687ULL, 0x3F69A6AB86FA8182ULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseCConstants = {
    0xB7D68152A787434CULL,
    0x9E632C76ED4BFB66ULL,
    0x0009A8C3261D10D6ULL,
    0xB7D68152A787434CULL,
    0x9E632C76ED4BFB66ULL,
    0x0009A8C3261D10D6ULL,
    0x34EE4C6366C0D817ULL,
    0xE5BE13051C661228ULL,
    0x96,
    0xF2,
    0x2B,
    0x39,
    0x0E,
    0x76,
    0x9D,
    0x56
};

const TwistDomainSaltSet Soccer::kPhaseDSalts = {
    {
        {
            0x0A8F7CBAED435470ULL, 0x4AA0E10F157D1DF6ULL, 0x2C92721D30122AD9ULL, 0x8699BEC7C8D005E0ULL, 
            0xBE374439A6FFF330ULL, 0x4F0CBC846F4CB06EULL, 0x6345971DCBE455D1ULL, 0x038F3A199F76B1E4ULL, 
            0x38AB7A8FB028CD30ULL, 0x0253B493C6B153CBULL, 0x3420202BEB0E955BULL, 0xAC6014C25BF2F69DULL, 
            0x1D8FABD662648362ULL, 0xDDA61E3BEF5C60D1ULL, 0x58CF1E16E9F0C068ULL, 0x252FA1B92CB77371ULL, 
            0x0150B841213FE7C5ULL, 0x7FCBFAEC364CF37AULL, 0x7A12E540E88FA7E5ULL, 0xA9449D633404E446ULL, 
            0xC576469087829198ULL, 0x882FB8DB5E0E3E8CULL, 0x1EC75987468B3711ULL, 0x5020525937DA300BULL, 
            0x07B8DA9541FEE7CFULL, 0x2EE5FD97A3948A92ULL, 0x445CAE14EBF67326ULL, 0xEA63A595A20FFA9FULL, 
            0x571F52D414D61F09ULL, 0xC941E186D8EC476CULL, 0x0CB82C6337D6047BULL, 0x1C485A2B53C5C34FULL
        },
        {
            0x4ECBEBA5039B3070ULL, 0x5ECCA066E22D25B4ULL, 0x216955EC68F71C36ULL, 0xD6EB6B9CD70A54D0ULL, 
            0x5CDE72D84E063F9FULL, 0x9095CF9E0363755AULL, 0xFC4925DA0ADBC5A5ULL, 0x3FA3663C2EAF5783ULL, 
            0x65A5E558857ED395ULL, 0x673F5152022D1706ULL, 0xA687DC078BFCD54EULL, 0x24B07DD82564AEA6ULL, 
            0xCE598B9276D6AC38ULL, 0x1DC9F0A2C5D8BA1BULL, 0xD8BA7FA6BB92DCDBULL, 0x190C2F309E60D531ULL, 
            0x8F972A8FE02BA114ULL, 0x93160B3FDC0E3D4FULL, 0x4DAA48896EB4FF8EULL, 0x5488AE1051EFA3E7ULL, 
            0x610A033B9B169BF8ULL, 0x5472B9225C042B29ULL, 0x44ABD328FD2F29CCULL, 0xF63C6A3E35702520ULL, 
            0x259BEF569943846EULL, 0xCAF993DA56AC0FBBULL, 0x1586540A88400835ULL, 0xCE96AA45919D9DEAULL, 
            0xCF40D2621687ED83ULL, 0x2F06B1B5BD3F8BB5ULL, 0x6F4BBE30558CA3D0ULL, 0x391C4A73E806A0F2ULL
        },
        {
            0x7D1E47F197C36C16ULL, 0x687B7B765AB6C096ULL, 0xBE84D4126FCD9D0BULL, 0x93CCCBCFA4A74E05ULL, 
            0xEE599A07B73A3275ULL, 0xAB435E1C7E2E87C4ULL, 0x89ADA47105D50782ULL, 0x9B4F78C6FC65BE88ULL, 
            0x33F863DB466787BBULL, 0xD3F0182BD45100ABULL, 0x78CA01A4100C43DCULL, 0xF4833BD507074024ULL, 
            0x92B07339225333E6ULL, 0xD1ADBDA68AF41E31ULL, 0x5830F0D86EC30C4BULL, 0xF0C6C5B0076B7415ULL, 
            0xC59317675BB3F395ULL, 0x0518E4257C860B87ULL, 0x6D3AA09B505B3546ULL, 0xCFD24788F3B3E973ULL, 
            0xB19E76DC25E9F6F1ULL, 0x142D900CA54A457AULL, 0x415A53ED46486C82ULL, 0xED959B7ED8FC6DDFULL, 
            0x7CD27FC1F195AB54ULL, 0x42437F56FAE0E1D2ULL, 0xBEC8E0327899406BULL, 0xD2C93E8EEFB05557ULL, 
            0xFC1021B63412D83DULL, 0xD7FD2175969C5018ULL, 0xBF162756138A8644ULL, 0xB606D372226655A2ULL
        },
        {
            0x78411FB6493FEF76ULL, 0xF5CB0B2C01FF2534ULL, 0x3B04072E456E3704ULL, 0xD5C151E1BAEF189BULL, 
            0x04EAA669EEECD53BULL, 0xAC1794832C1B3AE8ULL, 0xA703EBE32D2B626CULL, 0x602482E530F0BC38ULL, 
            0xFADA044F2C95E3C3ULL, 0x3CB02EDC911332A8ULL, 0x7E89664F43CAB07DULL, 0xF1CC80D1AD5EAA61ULL, 
            0x6CD96F07A7EED2D9ULL, 0x99CB39FB587A5D50ULL, 0x84A6FA68A1E6D61BULL, 0x0DC0F8E312AA0A6EULL, 
            0x796333254E1A7073ULL, 0x717F303583D8B762ULL, 0x5C4CDDF5CE968022ULL, 0x92C26EC1E815668DULL, 
            0x3FBB58FAFBE00300ULL, 0xD09EDBBA7C1E19B9ULL, 0x4121691236329429ULL, 0x8EAD57F8DCA0D123ULL, 
            0x9F360615BC841EADULL, 0xBC7BBE37864A09E2ULL, 0xAFC22AC95E2ECA7FULL, 0xF96F934C03EE36B4ULL, 
            0x62C3C5D3134503D9ULL, 0x8038543F0B62DED3ULL, 0xAA88F8C86083713BULL, 0xED61EC2592BCE24FULL
        },
        {
            0xCA403A3C435F0819ULL, 0x88921FF9D34C253EULL, 0x1B2FA68799AC5CF1ULL, 0x58C32B0FC4D9D6C3ULL, 
            0x195EDC2DAC197D6FULL, 0x9574F651DCBBE83BULL, 0x4106C79C767399F2ULL, 0x64AEFDADA9267380ULL, 
            0x2EC8CF7F2E483E64ULL, 0x903730E5D04D7BE4ULL, 0x48E9FABE26C32CD1ULL, 0x2235D1114E308759ULL, 
            0x52D0C51FA234DD43ULL, 0xFB8DFCC4DC07C14AULL, 0xC7C92F678320DE7AULL, 0xEBF30F30C84892BEULL, 
            0x5996130A811D7124ULL, 0x08868C1A2DAB7232ULL, 0xFC71C1751CABD9D9ULL, 0x85BC1605C2B14FE3ULL, 
            0x552C238EA1647A6BULL, 0xB5E4DF0E30758BA4ULL, 0xBE2C1C029340B9FBULL, 0x46BC1084524615A3ULL, 
            0x786BB3BF1EA284D3ULL, 0xE802E37566E6FFCDULL, 0xBA62F3B9DE03FCFFULL, 0xDB27103D1985E139ULL, 
            0x31E808D7676CCCD9ULL, 0x0753B0B125E37CF3ULL, 0x607C64FAEBA464C2ULL, 0x45F837BC9B7687B2ULL
        },
        {
            0xC93337228B9B29CEULL, 0x4BC1342E71586E3AULL, 0x5B0B6EE0A6B4CDE4ULL, 0x108B6A4B375D7780ULL, 
            0x10FCFA89DE310659ULL, 0x8226E7AC7DAB0689ULL, 0xDD8381A3F2989E43ULL, 0x89974529FAE7FC25ULL, 
            0x48EF63771E98078DULL, 0xF3A2A2B0B654DC9BULL, 0xA1D7FF6891B0BB0AULL, 0x528187689E1FE2E1ULL, 
            0x7C32800E9AC774B2ULL, 0x660C4C5B15AEB350ULL, 0x2C80200EAE58256AULL, 0x407D4B236080E8DBULL, 
            0x56D0310523633EBEULL, 0xE5E1B0FA8B04CBE4ULL, 0x84128C89D51EE902ULL, 0x5DD873BD081C7BB9ULL, 
            0xA2F8DB6C821558D4ULL, 0x2B8CAD6264EEE962ULL, 0x7F3BD3AC3C69D2E0ULL, 0x8521ABF540E539FEULL, 
            0x9FC61B3AC94B86E5ULL, 0x6188D5A10CC15997ULL, 0x9195E462A6B0134FULL, 0x25F2D5B0AD3F5CDBULL, 
            0xBC463D6D0FA53B61ULL, 0xC7F27530783119CDULL, 0x0F7306882BC81C45ULL, 0x4F5E31A5903BB115ULL
        }
    },
    {
        {
            0x5C97D92448F2C2D4ULL, 0xBEA1D18863E9D87AULL, 0x4181B8A1E4227526ULL, 0xE5987E45100A5C7FULL, 
            0xB22FAFF5BA96B5D6ULL, 0x3666C5D7B62C7859ULL, 0x45AB0AA827982798ULL, 0x3206E2D367F4BD97ULL, 
            0x979A3E60E25794ABULL, 0x8E527FA975A51225ULL, 0xAFEF3D54C43C803FULL, 0xE266F61C48323BEFULL, 
            0x33A8FEC1FC7B080FULL, 0xA43BFBC040F4279AULL, 0x354D7A590327030AULL, 0xCD57D8DC6DC84A53ULL, 
            0x5E5FF2412F4B087DULL, 0x41E1DC7EB4120009ULL, 0xC406AFE33C1FA3DDULL, 0x92789312296408D7ULL, 
            0x4298ABCE3CC3742AULL, 0x1F46DF63B7428C7AULL, 0xE86C022CC4693820ULL, 0x474C2C7824594860ULL, 
            0x4958498CAD8E0DA3ULL, 0x7A09F17D14104F18ULL, 0xCB4649CFCDF826B0ULL, 0xFF332592B66C7482ULL, 
            0xF7AAEDCA3CF33E3FULL, 0x5A117A948D4A8E43ULL, 0xC118BB4EF18E18ACULL, 0x4D38C13DBD473567ULL
        },
        {
            0x047163FA92F136E4ULL, 0x93F82DC2950852A9ULL, 0x8611A825ABA0116BULL, 0xA502790504F01F3BULL, 
            0x112435025ACB7FE7ULL, 0x74DCA181692CCE02ULL, 0x318BACF36A86EE88ULL, 0xEBDC511276CE54B3ULL, 
            0x610E16D0E2938C5EULL, 0x4617844584687C1CULL, 0x6DAC5A73E18F49CDULL, 0x3459CF9066E575CAULL, 
            0x7E6D851D218EF7D1ULL, 0x02B2BBBD4A14DBDEULL, 0xAB814570C96893BCULL, 0xA9163427551B0CA7ULL, 
            0x7448F5CFC16D99F9ULL, 0x538B1D813A401A67ULL, 0xB25FD40E38F7DA83ULL, 0x2251D41C0B1FA990ULL, 
            0x1E0119C65A6692C5ULL, 0xE269D6F30FF1D241ULL, 0xBCAA4A6B9DDC89F8ULL, 0x9CD9D7608FD801B0ULL, 
            0xE1A4E65676C57C71ULL, 0xECA84C7C25104705ULL, 0x68C9252769C51379ULL, 0xB7E88E0E51D88CC5ULL, 
            0xFEE83D825FBBC5D3ULL, 0x2549F12F1EDE7088ULL, 0xFA8352604159A184ULL, 0xF42EDC4CBE137305ULL
        },
        {
            0xDF038244F9C309E1ULL, 0x56F0D45815E5B0E5ULL, 0x26C2EC917999864CULL, 0x79B6F388326D4C0DULL, 
            0x2E5655BC858E4226ULL, 0xBD9E7BF15A28E7C1ULL, 0x33CDF371F6F5256CULL, 0xD0CA2191B264E94EULL, 
            0xD85EF20AB80224E2ULL, 0xFE12A651D23AA528ULL, 0x326A8006D11DE16DULL, 0xD3FF4CDD88592B32ULL, 
            0x967F70F8A8F0E6AAULL, 0x7912077F2F7E6C4CULL, 0x9F97DC934226031AULL, 0xE1E2C17C5CF3067DULL, 
            0xDB386A715EF0A8FEULL, 0x54260185970BDB16ULL, 0x8952F3E1EA743F5DULL, 0x5E99D1C7A53CCA69ULL, 
            0x842225A21410AB1BULL, 0xB847DB495D69EC85ULL, 0x64E7651503364450ULL, 0xD5619D5B10D7E540ULL, 
            0x575075DE998565A3ULL, 0x8F8E374AB48C58F7ULL, 0x2C7FA0D76B9A5E4DULL, 0x722606BBD22BCE5CULL, 
            0xEC8CC447F5609DEAULL, 0x978B9358104B0FE4ULL, 0x1CEE831508687ECAULL, 0x60D3A7471E3CB708ULL
        },
        {
            0xD70FD1E6D1130D62ULL, 0xC75B3E708C9B0896ULL, 0x4E278DC0EB71FBBEULL, 0xB6B18A2971833438ULL, 
            0x6565CD0C6ADF8EFAULL, 0x3C949BE1AE5DCCB7ULL, 0x02D4134F070C9510ULL, 0x1342F7F0C4D8000FULL, 
            0x617503E1FC1AD256ULL, 0xD38A82FAE3C863DCULL, 0x3AFA7F038C5CF5E6ULL, 0x078A61804123E575ULL, 
            0xAE4B7B3B81923C6FULL, 0x95749A5469E37F21ULL, 0x9A3373EB28C84CB4ULL, 0x5A68ABCDFF7373B9ULL, 
            0x456907DBB9ED0535ULL, 0x68DD8F337E6C351CULL, 0x2EBADE78E97E04E9ULL, 0x718AE831048F877CULL, 
            0xD79FC8600AA159ECULL, 0x4E5B2E02DB91B147ULL, 0x3F1268CCB49053DCULL, 0xC74B2A41CBDFF252ULL, 
            0x53AF05FFAF219A53ULL, 0x683A9B6871B8D241ULL, 0x771BBFC9CD476764ULL, 0x967CF375AAF49CEBULL, 
            0x37ECD94CAC7D1490ULL, 0x99D9EE36E55739BEULL, 0x438E53250E1DC1DBULL, 0x7FE80053980ADAE2ULL
        },
        {
            0x97895C6875CC3BA2ULL, 0x3D69C323ACDF0C1AULL, 0xD1965A8C4D15169CULL, 0xA8F8077C6643A055ULL, 
            0x6A5C3AD46A69FD27ULL, 0x9E14DBF4ECE6AA90ULL, 0x3AF62D8A5F72161CULL, 0x2A3E3B2DC5D81BA0ULL, 
            0xA471CF517F1C7A38ULL, 0x0EA08C598D073C26ULL, 0x08B2B0949541F3A5ULL, 0xBEAEF3950BA856BBULL, 
            0xBB4DCDEAEFF1FB4EULL, 0x4B92060B464CD7D7ULL, 0xEE6033C4A76C4874ULL, 0x25A0D3EA655550B3ULL, 
            0x44144F3C66B05149ULL, 0xE782B5EEA625CE3DULL, 0x4933E11A57348884ULL, 0x6DCDDE5A0B1AFBAEULL, 
            0xFDE9BFD552853F49ULL, 0x5A9CF64C1804467FULL, 0x7B2483218EFDB9A8ULL, 0xA964F2D976DBD318ULL, 
            0xF9EACE20FA51DF3DULL, 0x8F71B9BDF02C9A6EULL, 0xE057F098EC46BAA9ULL, 0xB079F1B0D20C30D3ULL, 
            0xE525CEC9A1225E66ULL, 0x5A2486D9412BF568ULL, 0xC4FAC4A3C79642DFULL, 0x4377F5F5DB9A394AULL
        },
        {
            0xA64DA208ADFE7B3CULL, 0x9E42C8954108F7C2ULL, 0x476366FC43D1EDB5ULL, 0x54380F1A87AB522BULL, 
            0xD34A99D7A4F932E6ULL, 0x1E5CE826919F0957ULL, 0x284820BB114D6A1FULL, 0xF6F7CA20BAEBE30DULL, 
            0xC2743F184E9F6439ULL, 0x2E21C89CAB9D5836ULL, 0xBCE50F2FF2DBF407ULL, 0x94BBB402CA23C6C4ULL, 
            0x6C9E8245DAC904A4ULL, 0xF318F77C21CA655CULL, 0x28F05E3B8B3B2FD0ULL, 0xD47A6CBABE729229ULL, 
            0x66AE23522EB3986AULL, 0x273970E50141610CULL, 0xFECE70E6C4D9293BULL, 0x268EBB28CDCFDE6FULL, 
            0x34E959F5F6483517ULL, 0x096FC56C9F929CE0ULL, 0x9C1EF91F6B1B6E29ULL, 0x6A222AA922BE554BULL, 
            0x0B0F2CC309DA701DULL, 0xF305D6C5A0D865C4ULL, 0x6E78A102A9B1ED8AULL, 0x14C818B11387C75DULL, 
            0xAE7F42E9B90EFD65ULL, 0x4A191CE0C5162C73ULL, 0x81224F37866C5B25ULL, 0xA7E9ABB674864AB1ULL
        }
    },
    {
        {
            0x0AB2FBFE64D8AF54ULL, 0x8A170863385BF8A3ULL, 0x2527A093B5E6B0D8ULL, 0x9B9B52D790408C2AULL, 
            0xA8F7A8738BAB8A35ULL, 0xBAA8CED512B09D28ULL, 0x51412D7BA5BDC6B6ULL, 0x655977B8D0D7E89AULL, 
            0xD7C84194611CC9B9ULL, 0xBFE06E0078E24243ULL, 0xDFA027C319D6B9ECULL, 0x5ED3083195BBFFB5ULL, 
            0x98E22DFBE178B2E7ULL, 0x721376123BA6B494ULL, 0x2764D9359FBFC08FULL, 0xB5CADC3F984AA676ULL, 
            0x6A7B05670E1E689CULL, 0xD0242E99F2DF8266ULL, 0xC466C0F64F283A57ULL, 0x965308924EE64C19ULL, 
            0xD48D2921B121063AULL, 0xBC0CF95E14D15FF3ULL, 0xFE16E4492E741857ULL, 0x0F2019E1A8D143ECULL, 
            0xAD3BA99C97F6B2CAULL, 0x2BEB808A4CBB70EBULL, 0xF9E7754C304DDE5FULL, 0x79558010FB040132ULL, 
            0x767A129F8AAB4045ULL, 0xBA7FADE76CDF2829ULL, 0xD56D1D831051E3E5ULL, 0xBA27224F14726E65ULL
        },
        {
            0x523FFC0952674A7CULL, 0x6BF8583C74DFFE92ULL, 0x31F124DE80E367BBULL, 0xC6747B94C913F093ULL, 
            0xADBB1C0E2FFEC08FULL, 0x520695AA22A14BC4ULL, 0xCD2FBFD34B9E9E2FULL, 0x4022E81FD54E0000ULL, 
            0xF150CA3097A58C49ULL, 0x2118FF1A9850AC5CULL, 0x18F5EC67ACE5FBF6ULL, 0xEE8CDCD67EB402B3ULL, 
            0xC142BA6666B5BD3DULL, 0x70825469A5DA936EULL, 0xB627D0FB33C4261DULL, 0x240D0CD65952E0BEULL, 
            0x064E66D8CF42C989ULL, 0xD16ECE1077CEA119ULL, 0x0F50240F4EB281CBULL, 0x37E30F8925455082ULL, 
            0x91F45401978E2CD4ULL, 0xCA664ADEF4D9CEF6ULL, 0xD348ABBF33486729ULL, 0x30DEA939A14BC046ULL, 
            0xA636F75F9B754B99ULL, 0x7C76071199A4E8E9ULL, 0xFA2B7C5145D0CDD6ULL, 0xE1BAB04DE3B89E1FULL, 
            0x6A3E1A5D0A1CF8B9ULL, 0x02291132D7ABB058ULL, 0xEB5D6F90974BE146ULL, 0x1A056BB03FF5CCF6ULL
        },
        {
            0x188F1AF7D45C2142ULL, 0xD5F5170AF8144915ULL, 0x364649DE4A94260EULL, 0x467FB5FEA9E7312FULL, 
            0x8D0FCEADDB2D8346ULL, 0x37FEB2567B595C23ULL, 0x791519BEB188D15FULL, 0xE1C81A40D51C99BFULL, 
            0xBC307D785064FB74ULL, 0x553AC52B2829BBFFULL, 0x139985A29CA04D29ULL, 0xB29C8331C539EFD8ULL, 
            0xCBE9F99EA96D8E20ULL, 0x05D451C019A2AFD9ULL, 0x47DF8747439DD880ULL, 0xC358B5B9E37D54D2ULL, 
            0xEEE3A598E779E483ULL, 0xA42C415BB6581BDDULL, 0x62802A65DD388F3BULL, 0xFA18EFB124A627F0ULL, 
            0x8E10174D317A2252ULL, 0x3CC2F59D03A68E0AULL, 0x5691444111916B40ULL, 0xE39030E245350966ULL, 
            0x54392D60671E5F2BULL, 0x81CFBCA26DCEE01AULL, 0x2DCD74CF8A4EA2A0ULL, 0xB15A111AA6BA99B5ULL, 
            0xBBD38BF623203E66ULL, 0x1C154D375633F556ULL, 0xAB5D4BBB7019060DULL, 0xFDF9FD7AAF5D82DBULL
        },
        {
            0xEE5959C445EC0639ULL, 0x4D39E2271198F1BFULL, 0x43A2CABD4B4305E8ULL, 0xF55A9F77FB4C702AULL, 
            0x18ECEB51DC93E358ULL, 0xB02EAAFFEDB2293BULL, 0x5181B2880754BC48ULL, 0x50667D3BF04E663FULL, 
            0xA05E217695043FE7ULL, 0x6A22A2994079607CULL, 0xF8572A4622D22067ULL, 0x665E6507402AF06DULL, 
            0x120A528C2375784CULL, 0xFF0BF14865F8A437ULL, 0x710F4F1C59E8BAD1ULL, 0x09AB4BA4DDDC2789ULL, 
            0xB39B4A58048AB384ULL, 0xA6FA22B98DAE249AULL, 0x8F4DDBCE4A9577C8ULL, 0xB95367D85CCC998BULL, 
            0x9FC00CC288E2F521ULL, 0xD83CF25F1C3E4588ULL, 0xD3EF980BD26DBE8AULL, 0x2393A10E559362BCULL, 
            0xC91A4F150AADC9C6ULL, 0x45BD560BB9C93818ULL, 0xCFA7C7467BE08B25ULL, 0x441687E37E1AF68FULL, 
            0xB19E329FE8B180CDULL, 0x4ADD9E1E1174A63EULL, 0x974BF53D39DDABBDULL, 0x6ADDD01030FD6E20ULL
        },
        {
            0xE5E167638CE91903ULL, 0x72EB25038BCB5BD1ULL, 0x43FB1C606F3BFA19ULL, 0xFA72F8A4BBE1777BULL, 
            0x021389FAE0B7E7F2ULL, 0x569E99A8BF5FBD01ULL, 0xAA1ABBE01D4E1FD3ULL, 0xD9948E82F5DA38A2ULL, 
            0x5AA8384E0A0BFBECULL, 0x8A179C1E6B669F9AULL, 0x71AF5D2C9A65C5C3ULL, 0xC801523D473F42EDULL, 
            0x09BF4C2BEA845173ULL, 0x4549D707C28D17A4ULL, 0x5420AE45DDFEE16DULL, 0x9C8A392E9C161AB2ULL, 
            0x640EEEF0C3EBEA3AULL, 0xDDE232FFFC8E8A2FULL, 0x19DB5D451DD171F8ULL, 0x28C80ED4665CAB41ULL, 
            0x8873D6BBEBE95976ULL, 0x992AB596B1ACBDF2ULL, 0x8D7EFFF7A66B1979ULL, 0xCF496795A45B98F9ULL, 
            0x183F2A9ECC2FB7A1ULL, 0x3B06F74E60C9B75BULL, 0x0D83618B5CD814D1ULL, 0x683FA4AA401D1509ULL, 
            0x7D65A977A43261B0ULL, 0x51FF1B531AE5B532ULL, 0xDB05B1A43D9D51A2ULL, 0x2B21749359646653ULL
        },
        {
            0x81142F041C7C3513ULL, 0x8705D0337648CF18ULL, 0xDF829560F4A19DFBULL, 0x7530FA280075EE45ULL, 
            0x6F118F6CBD1AECADULL, 0xCCA07A9566867047ULL, 0x11BA69042FFB8D69ULL, 0x08ABC145145D5E44ULL, 
            0x82DEDCA7FAD21820ULL, 0x95DCBFCD06145750ULL, 0xD063C6CA76086E21ULL, 0xA3426AA8BC84ACCAULL, 
            0x8FC8CCE949EC4E05ULL, 0x89CCA93C886256DCULL, 0x632DD44D88C06D69ULL, 0x5AD2FB7562A4167FULL, 
            0xB4DF182B86760452ULL, 0x2B2F01876275D3A7ULL, 0x42A240225195BD14ULL, 0xFC3653AB6C49D87CULL, 
            0xC1ECD3FA523EA0C9ULL, 0xA48B1CB6EC8F797FULL, 0xBD7BD4704E79F998ULL, 0x6053FFF31C833462ULL, 
            0xFC43677D9A10C569ULL, 0xC34F522CDAF6F7C4ULL, 0x12D08DD486F671A6ULL, 0x2C5048ED26456BC1ULL, 
            0x8F68606EC61011B0ULL, 0x05D10A7B8F149F2BULL, 0xF02B68E24AAC54E0ULL, 0x42F6D81B5F79C544ULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseDConstants = {
    0xBD325E19689F4E4DULL,
    0x093C226FEC90CFB2ULL,
    0x4B5B986756830F81ULL,
    0xBD325E19689F4E4DULL,
    0x093C226FEC90CFB2ULL,
    0x4B5B986756830F81ULL,
    0x0BC8A1B259B726D7ULL,
    0x63B56C77A2B752B3ULL,
    0x46,
    0x09,
    0x26,
    0x91,
    0x21,
    0xAF,
    0xB2,
    0xAE
};

const TwistDomainSaltSet Soccer::kPhaseESalts = {
    {
        {
            0xB76D6FD46EF12D04ULL, 0xAC3D68ABDF0743DCULL, 0x0E20DBA623ECD97FULL, 0xA826C43E59968E29ULL, 
            0xFE7C371128BDB82DULL, 0x855345568A6F82BDULL, 0x52597CEDACE80C7BULL, 0x1779EB6EB024365AULL, 
            0x08FEF6381AEE2449ULL, 0xC4BA460CCD9BC60FULL, 0x0B1F828DD0ADEE6CULL, 0xCF4343B9180469C2ULL, 
            0x0174E908E2495C0DULL, 0x3A3311E1A2A311F6ULL, 0xB38AFC86DA9E4A7AULL, 0xF4A2B67AFD6A3144ULL, 
            0x980E84966870DC65ULL, 0xBD02AC44FD25C284ULL, 0xDFB0AA2BCD2F6711ULL, 0x887C8A98C71A2A87ULL, 
            0x32BDAC3E4BF7A33BULL, 0x27E06846B0B79582ULL, 0x393AB3FA4AB0E90BULL, 0xA5215CB7A058E34CULL, 
            0x62DF1B4A1BD5EF80ULL, 0x7684BFCFFA746CE4ULL, 0x90CBD8BA88EBBBCCULL, 0xE62D2C331093EB6BULL, 
            0x6F2338989CAA08ABULL, 0x4C14037158CC1DAAULL, 0xDF9C3E655EB8E45DULL, 0x85A6F29651A88D3EULL
        },
        {
            0xC4B4532516DAD376ULL, 0x94715029466C67B2ULL, 0xB37574E42D1AE00EULL, 0x1B5CE1418EBDB05BULL, 
            0x274598CF9E3B6C85ULL, 0x86BD5C05510D0A03ULL, 0x9836B777DBF9E2EAULL, 0x4D9C846583523829ULL, 
            0x9E7D0253036C282AULL, 0xCA82C828A3E3E3E0ULL, 0xE7A493042D059805ULL, 0xFE5AA60B90433532ULL, 
            0xF5D6691886060993ULL, 0x274264CE9AAD2505ULL, 0x099557AC811406A1ULL, 0xF8F6B058C90263ADULL, 
            0x8028795C5C402874ULL, 0xF4D58389C9411C8EULL, 0xE381584E3B670207ULL, 0x74B1CB8D98771CC1ULL, 
            0x3724CD86FE61EA08ULL, 0x32EA994BD1626BF3ULL, 0x21EE330AE5298BB9ULL, 0x1508C695388AD0DDULL, 
            0xFF00D0C9D4BB0282ULL, 0xE8CC77168C2CFF49ULL, 0xE6B640D5166C6905ULL, 0x9A89BF32C1EE5D59ULL, 
            0xCFB35057AB3DBB6AULL, 0x4CDEE8A78EF7B9C9ULL, 0xBF78577790649316ULL, 0x81675F9AB35FC515ULL
        },
        {
            0x94BE79220CFEB77BULL, 0x2ED7261B065ADBEAULL, 0x796BF8C5E8D1E34FULL, 0xB0A63CFC4F413631ULL, 
            0x6618A5808D6161F7ULL, 0x97DA62993A4BC0BBULL, 0x714DB6A34AE3D00BULL, 0xB4CF96B2880733B8ULL, 
            0xB3E5D3DA3798B88BULL, 0x783C65A6D3DE91DCULL, 0x5D86036A36CC14B5ULL, 0x29C559B59AA721CDULL, 
            0x05909BB031698C92ULL, 0xC8CD751802D3284DULL, 0xC711FEEDC0AD95A5ULL, 0x8854758B3B94A2D7ULL, 
            0xE7EF5441150E2259ULL, 0xEF7A5612FD4A5C6CULL, 0x23087F018B787137ULL, 0x7BEDED428BFA48D1ULL, 
            0xE3F580E0477B005FULL, 0xF594AFB4F1018173ULL, 0x3BD99E0CFD1B0518ULL, 0x318C5FCEA6FA30C1ULL, 
            0x6B135A6F879B8BDAULL, 0x08197151CB9B70F9ULL, 0xED4116FDFBDE652FULL, 0x8ABACFAB7289CD7BULL, 
            0x97F995746D3F27EFULL, 0x53090CBFC9459735ULL, 0x17C41167097B2B94ULL, 0x2C0A463F83C57990ULL
        },
        {
            0x1520AA41EB8AF5F0ULL, 0x5BFC72F310B0FFCDULL, 0x6CE0B0E3E0CCE692ULL, 0xC0C928EBB013C849ULL, 
            0xBE896F953B6B122FULL, 0x000D7B6A0C81B5FBULL, 0xC954C139106BE260ULL, 0xE526C4C5EE237D22ULL, 
            0x1F896DB488982EB1ULL, 0xC46AE793D6F4E98BULL, 0xCD6E3167065FC237ULL, 0x9B64B57484A1ED74ULL, 
            0xF5EC4AB9CE90EBF3ULL, 0x598F4C52BFE01E97ULL, 0xEB05D565A8CFF3EBULL, 0x538F2A60CE9AC8AEULL, 
            0x566B71E9D0FB6761ULL, 0xF2D587BCA2CECEEAULL, 0xDA35399F4304EAF2ULL, 0x0698155023B5C3DAULL, 
            0x9F2CEF8932D26438ULL, 0x79042EC873FF3750ULL, 0x0B73084C6C0CD8E3ULL, 0x5551D8892D84F852ULL, 
            0xA6E1BD711E2AD24FULL, 0xB50331E43E8CC713ULL, 0xFA2030CD7A53C014ULL, 0x5D1107CF17F86569ULL, 
            0x31B6B27006C5F03BULL, 0x2328E40E18443991ULL, 0x8800B40401D156DEULL, 0x84D58E9F0F50DAF8ULL
        },
        {
            0x5D1F06ADFD4717F2ULL, 0x6A9FBA55574809CEULL, 0x409D470484FD97C6ULL, 0x6FF074EC7D78A1A4ULL, 
            0xC0B8887CDBA37D1EULL, 0xDE7710F2A039F787ULL, 0x4203CAA3F2C75D59ULL, 0xB2685454B9A9AC4AULL, 
            0x42DBD3CE6DCCBAD5ULL, 0x7440FF0D3DF36299ULL, 0x86FC865B4F17FED9ULL, 0x04C8B841D9641067ULL, 
            0x04D56B6C107BD529ULL, 0x4B4D250B98E4971EULL, 0xA6994228DDCAC267ULL, 0x53AF33293CB3C98DULL, 
            0x2257595936004626ULL, 0x52A25389115F08C8ULL, 0x3FD6F6808B43F31AULL, 0x1F8149BEEA763242ULL, 
            0x93B9A5AD44DF69EBULL, 0x7A515E6037E5E0FFULL, 0x0B8D7D29F5746038ULL, 0xD5250B96B434DBCEULL, 
            0xD4B86CDFB91C4839ULL, 0xCBD532F700B9B15EULL, 0x50985920CD1E6BC4ULL, 0x3474ECD0009B02CCULL, 
            0x6484B979796D0C07ULL, 0xE1E16C91B066C8CBULL, 0xDEDD1B7367958A03ULL, 0xD759EAE2AF626D07ULL
        },
        {
            0xC0E921A3B7A5A6D9ULL, 0x46DB353480A04FDEULL, 0x198132E211BE4C26ULL, 0xD9E82D036B96B36AULL, 
            0x216D87A6B47B0FC6ULL, 0xB91824C2F923AB29ULL, 0x57609873EBDDE1CBULL, 0xA692C101086783E7ULL, 
            0xEC0A15602F14ACA0ULL, 0x87B96AF6F21517A8ULL, 0x0499A8270026377EULL, 0xF8F236D9296C1E1DULL, 
            0x9CDCFBB14EF4D488ULL, 0x017056C931202433ULL, 0xD94CB170397CED60ULL, 0xEA9949298378A23FULL, 
            0x535D57BD40929BFEULL, 0x27DDDB36895AA381ULL, 0xBD4FB751B2EDD0DCULL, 0x471FA6058523B862ULL, 
            0xD887D79C8DE49EC0ULL, 0x7DE7B725048662F4ULL, 0x21A86D54848148B4ULL, 0xCDF35EE17A9ED691ULL, 
            0xDF835714B7024D58ULL, 0xF7BDA50A8D1A0E01ULL, 0x710FE0D3190C6B8CULL, 0xA89EE4067EA817B1ULL, 
            0xC0E7E6A827715033ULL, 0xF5EAF9DE01071B50ULL, 0x8A5E517258F56714ULL, 0x2B6FF7144BAD2BE2ULL
        }
    },
    {
        {
            0xFC42106DB96DEFCEULL, 0x04C5402048453372ULL, 0xF079740FF8F41317ULL, 0x6EFC8545BEFB2305ULL, 
            0x3B0879F8ECC0A8B3ULL, 0x4312568264BDF050ULL, 0x097080D17911A846ULL, 0x293805355DA4E431ULL, 
            0xCE0AF31665588C88ULL, 0x2D52364A00735183ULL, 0x342F3E14F3D48384ULL, 0x4FD10321D81941A0ULL, 
            0x3C313A6B3F2BFEB2ULL, 0x1DFDEBF2A738CFC0ULL, 0xA39A9FEFEA7BF592ULL, 0x54B61B038364BD5BULL, 
            0x31BA90A1E7A10C8FULL, 0x53FA2141C9A1F065ULL, 0x0F66920E9C54E595ULL, 0xFCF4E836CE00ABCBULL, 
            0x8FAB86FD0C195EBFULL, 0xF4F777F905F52C83ULL, 0xAB332641D19D4B29ULL, 0x877B6A0C26ED0CFAULL, 
            0x71752C6A1AFA4BF2ULL, 0x41A95F7AE2CEB85EULL, 0xB546A3A60991C03BULL, 0x7728D2D419050307ULL, 
            0xC6DFB9420D044BA0ULL, 0x2C6EFB7A83C2B020ULL, 0xC260D2117431F071ULL, 0xC22A8E731517BFA6ULL
        },
        {
            0x94E73B74103B1240ULL, 0x657C6FF18A794101ULL, 0xDA36693090B71947ULL, 0x302213A1F574DB46ULL, 
            0x3677CAE1E99A768FULL, 0xC6E5611AA6008111ULL, 0x51BA98BC60353C37ULL, 0x26E7AADA48BA7151ULL, 
            0xDFE95413A3879495ULL, 0x7AC9DD7EAACF9949ULL, 0xF1FED9C92E5E6509ULL, 0x3622E6B5B558B834ULL, 
            0xD6DA52F34AAA034AULL, 0x206DEF22AB8C5FAFULL, 0x59006F1D4C270F60ULL, 0x6FC382A9FE4E6A92ULL, 
            0x4ED31CA8E42FAA08ULL, 0x16B9F1C5AA9F9131ULL, 0x336ECE0D78F158D3ULL, 0x4962461950BB92F3ULL, 
            0xBD3BD76AAB0BFA6AULL, 0x95D32056528A3F5CULL, 0x83A60A1BB2E9E0DEULL, 0x1886F84B5319A7C4ULL, 
            0xFC3FD828A698E2F4ULL, 0xDECA149F9D68E65CULL, 0xB4D46E9DC77EF043ULL, 0x54D86CEFF9494E77ULL, 
            0x9A8871F97CBE3085ULL, 0x1D6B0B4617A05237ULL, 0x71CB6960ED354D3FULL, 0xB8F43D5BA57F5A97ULL
        },
        {
            0xC667385485567CBFULL, 0x832845A5D83C0990ULL, 0x855E0BD63AABC93AULL, 0xA9567A769CEBF720ULL, 
            0xAE1A6CF0FB71D339ULL, 0x265DAE7BBD1AA4A3ULL, 0xFE2D3CA2EF02F79DULL, 0x7E7421D412080A36ULL, 
            0x1452CE471E9F4990ULL, 0x6BBF59C51E177319ULL, 0xE5292105439E6330ULL, 0x894A89329DFF4A3FULL, 
            0x71BCFAD9F11DF45FULL, 0x1B1436BD3C4EA524ULL, 0xB3523B0B6EB3D1F7ULL, 0x818132C9DD8089EDULL, 
            0xFB3F868A025BFC28ULL, 0xE0F99CE0335325ABULL, 0xD04A01F21303EA12ULL, 0xB9D6EA4DA252EA10ULL, 
            0x9964051AC06EE19DULL, 0x1485F0B6F46EFD38ULL, 0x7E72995CE7C71348ULL, 0xA9435E22B99E307FULL, 
            0xD42D8CE4623E2118ULL, 0x88FF228471D5F986ULL, 0x5F79A50A6221CC25ULL, 0x80B5D2C5B738DFA6ULL, 
            0xC0F8D505E48AAEB1ULL, 0x3B0D9002CBCB88A6ULL, 0x0C5820D7023B850AULL, 0x46A1E271AB9306F5ULL
        },
        {
            0x54A0E3ED58D1BB35ULL, 0xB5B475CBCC0F5C6FULL, 0x25B255AB89BB8494ULL, 0xBFDD3345FB9361A7ULL, 
            0x2E51E8C033C6B5C0ULL, 0x3B441A84FFACC075ULL, 0x8371BFC2E750F2FFULL, 0x5F409491A6912AA6ULL, 
            0x22C4C7655D238F80ULL, 0xDBF1978589C9AEE2ULL, 0x6B2EB8B23B5A595BULL, 0x24DDA95801AEEBD0ULL, 
            0xAE06EA66A2300550ULL, 0xD1F360BD179BC17AULL, 0x229A89D48B86B343ULL, 0xE5F0A31A3AF43396ULL, 
            0xAD372C247E1F85DCULL, 0xC8EA65D427E4B384ULL, 0x513F6DBD249B0056ULL, 0x7B86E3786972036CULL, 
            0xCC06104401061EDEULL, 0x1A417EA4D1F29D82ULL, 0x418AD4091D91D4CCULL, 0x442159C294685CADULL, 
            0xADF34D6FAE0A97D1ULL, 0x11185583DC65642CULL, 0xE772A17134781F86ULL, 0x8EBF5755651587C8ULL, 
            0xA078B810F54A65B6ULL, 0x288AC664D0F55ACBULL, 0x9A98A7B95B71EB07ULL, 0x69A620AAC2994FCBULL
        },
        {
            0x3FE4724AE1E5968EULL, 0x6D5DC9620D59BD69ULL, 0x86526E2A1EF64153ULL, 0x67C0485A23726D5DULL, 
            0xD66D97CB45C1689CULL, 0x1578B315A3B57149ULL, 0x7B20CA93F953DD40ULL, 0xA60787F765D4CA7BULL, 
            0xBCDFD02BB25DADECULL, 0xB6D7D03C2E669AB0ULL, 0x4F84285806C244C3ULL, 0xE82711552594AB9DULL, 
            0xC4D8F8145A6780E1ULL, 0xF2AEFF7B7993AA73ULL, 0x197970C1573307F5ULL, 0xE66D20FB37346714ULL, 
            0x55DB8D2BAD8D1353ULL, 0xC924D84614E195E6ULL, 0x6DB3D493B9404E61ULL, 0x1A56F04F6CAB109CULL, 
            0xCF2BCAA75DB3954FULL, 0x006CB3C75C2A1744ULL, 0x670498D79B3E2830ULL, 0xF7834C8F2B6E7D76ULL, 
            0x22D84B91DA88F33DULL, 0xF5BD41F8694B6A23ULL, 0x49292E34E97D7270ULL, 0x0CD5157F9192B572ULL, 
            0xA0B8AA094BB09B0AULL, 0x13F834024CDE1FC4ULL, 0x6F9175DC1668CE86ULL, 0x1CF73E1EE5F883F5ULL
        },
        {
            0x31F0678E79920420ULL, 0xB11C3C1D3CCC9A84ULL, 0xD98792DEAC3FAA8DULL, 0x9C5AA21A5FAA037EULL, 
            0x1075F4711AE99C95ULL, 0x7C5B258BC3D33F70ULL, 0x7DBE4FF63CEC56CFULL, 0x53D1DC8E16094AE6ULL, 
            0x6910BCF9B9F7F2CDULL, 0x2FFB567D24F9B28FULL, 0x9CCB95E7AA99DB30ULL, 0xED41C07A95C70087ULL, 
            0x6895E3B39E0D585BULL, 0xCFAA9E3B185A2A14ULL, 0xEDFAB005A81479A9ULL, 0xDB86F9C8374C92B6ULL, 
            0x94D15B4520F33F0BULL, 0x27D9A00282C6463EULL, 0xBE5371A7CC88348AULL, 0xB35CC8285A480480ULL, 
            0xFFDC57DA00EE9EA3ULL, 0xB402E93E814A0DBFULL, 0x1FE1D53F8CB99B18ULL, 0xF6255124BAE0E793ULL, 
            0x83C5ACCC1236C513ULL, 0x5C895DF18B76BDD0ULL, 0xFB043AA3D7E4159FULL, 0x3D8E39906146DB5BULL, 
            0xA5F7AC8FE6AF3830ULL, 0x597E6FF54F1E246DULL, 0xD4266AD1157B513DULL, 0xFC21F6B8D0DD3B33ULL
        }
    },
    {
        {
            0x8537C5A8019BF49DULL, 0xEFED5C9B55F09424ULL, 0x8F2E1620B89D2044ULL, 0xB2C6FD37F4855EF9ULL, 
            0xF84B0538B5C50C4AULL, 0x2068B5A1A055428DULL, 0xFB3DB4C5900E5A01ULL, 0x2D0A399A43A25AEDULL, 
            0x9B5BB954047977FEULL, 0x7A9CDF26628B978BULL, 0x7721ACE6921AFE75ULL, 0xA81AFA6A02EEF94EULL, 
            0x83D48772E1B478F0ULL, 0xCB0C49CD26C70961ULL, 0x1A7D2E48BCB48C58ULL, 0xA753BF34BB597F35ULL, 
            0xC313994B171E16C3ULL, 0x9139A9AD4178F65CULL, 0x2666881CD8E72201ULL, 0xB5945A658FE60E42ULL, 
            0x70DBCC1B57511BEAULL, 0xF8D0B5BCA938E2F7ULL, 0x6A58E4BDB6150491ULL, 0x023EF6371A85F089ULL, 
            0xE66924DCFF304B36ULL, 0x6E944E17A359DC57ULL, 0x8871AD4447387964ULL, 0x34DD18ECFE36E0EAULL, 
            0xDD4E9A2EAC3E6292ULL, 0x37D3D6FE28CEDE44ULL, 0xE3D070F2BA1269A4ULL, 0x16FA19DA52F58801ULL
        },
        {
            0x45D685271A8B48A7ULL, 0xF02E635788D1D32DULL, 0xFA78F3FCCB7D9529ULL, 0x7F81B7BC831D13C8ULL, 
            0x465ABFBEB44F2011ULL, 0x385A70E280C73468ULL, 0xF0B2CB1081B43E3EULL, 0xC635B2E85047A1EEULL, 
            0x554A817403AFD468ULL, 0x1CBD67D04502958EULL, 0x972DA40375C1CC77ULL, 0xE7C6936CFE1C9792ULL, 
            0x35937BD448F3055EULL, 0xD9902D691EC03F86ULL, 0xFC2CD705DDF9FDF8ULL, 0x533C6B2ABCD21603ULL, 
            0x835A3867199EC99DULL, 0x0790B2199F77BBECULL, 0xA3DE6C6C3051C5C7ULL, 0x50F9C145515040BFULL, 
            0x2F3BC05CF1B607A3ULL, 0x714E71D0EB23B92CULL, 0x012B8883D7A9C2ECULL, 0xFF7675D6DAB16E25ULL, 
            0xB0E882CCF00C54E3ULL, 0x338947A97E77DAD4ULL, 0xE271F6BF51EDAFAEULL, 0xE6ACF9C3C47F34AAULL, 
            0x406863E0043EC249ULL, 0x852C771DB01C9761ULL, 0x185B231501C04666ULL, 0x5DA5F7CA2603E717ULL
        },
        {
            0x590570961A1BCE69ULL, 0xC46115393BDCDE1AULL, 0x7A915344A8F26EBCULL, 0x01ADCC7CDDB243D1ULL, 
            0xDF0686ABCA9ED082ULL, 0x45550672AFFA1DF0ULL, 0xB87B85AAADBE1367ULL, 0xB4EA1C2B0FEC8301ULL, 
            0x23D58F3916C98589ULL, 0x6EF76D0014ECBF47ULL, 0x42491D95F1E6EC59ULL, 0x20DF26BA0EED5A3DULL, 
            0x62DC438297A00BA6ULL, 0x5173F570326D9A43ULL, 0x7C6797629BDE9FD2ULL, 0xC8E18610FB674CA9ULL, 
            0xF2A9C62A7F03B7ECULL, 0x5839BA4EA3379E27ULL, 0x16F6BA0AFDB46098ULL, 0xD980D118DAD76262ULL, 
            0x148930BDC6013BA2ULL, 0xEA22736C77C20459ULL, 0x5EF94E2EDBF25EB8ULL, 0xF039D6BA548FA13CULL, 
            0x9200637F834E15C4ULL, 0x63EC0F0246F4C1B9ULL, 0x65D180DDFD008D9CULL, 0xEA0B83B786BBD2C2ULL, 
            0xC9BD7F0E8B22547AULL, 0xD01ABE047653029FULL, 0x4709DA719D2F5A55ULL, 0x0B2B78A9E06AEBA8ULL
        },
        {
            0xF3C9A936CCD1A277ULL, 0xC06F22F89013AF17ULL, 0x7AFDD02E4933030BULL, 0x4DEBF7A3E261B621ULL, 
            0x0510A3C10F61BB3AULL, 0x76CC7532E280EA98ULL, 0x2C386CACA67785E8ULL, 0xCE4A9DBF78255072ULL, 
            0x7721DB130DA7842DULL, 0x0E49D5FD70F44F20ULL, 0x2D9D751658CEED82ULL, 0x53D57B68890B7CE2ULL, 
            0x8E795AF23F721FE9ULL, 0x6330815ED4B7EFB2ULL, 0xB377F073274A4CD0ULL, 0x2478ADC834FB5C24ULL, 
            0x4E51A9732D8E5769ULL, 0xF1D59A70A39CFB62ULL, 0xA5278F73F5463A79ULL, 0xBFF420D95CA5A499ULL, 
            0xB2ED07187C3EFF4CULL, 0x5B3B0BEE8B4A60BDULL, 0x4490B693BD421F0AULL, 0xA760C20A99921E34ULL, 
            0x9A2C69984CBA8449ULL, 0x0281FC544DB310EDULL, 0xCCC86A7295F6E743ULL, 0x07107046F1D20DCAULL, 
            0x38B1D78AD94FD5E4ULL, 0x6519B8C231B30777ULL, 0x6559C7D65E405748ULL, 0xB03C7072AB9C7065ULL
        },
        {
            0x7DFF18B62BD05004ULL, 0x4B3E0A8C18B1913AULL, 0xBE7B1C93F2FCACE8ULL, 0xAA4BB3C72FCAA540ULL, 
            0xDD28D1D33D156FC3ULL, 0x7B5B548B66EEBD13ULL, 0x9C6EB7C9A21A941CULL, 0xF1AD65625D8E489CULL, 
            0xB212E325A70B4372ULL, 0x1BE8D6B7E0C9C020ULL, 0x8B0CF6D0549069FEULL, 0xB433C551653A2759ULL, 
            0xBED5E05D458A9665ULL, 0xAF7067885D5B9DAAULL, 0x6850D8CB9077FD09ULL, 0x7F8D617056FA1308ULL, 
            0x1A4774530AD2BAC4ULL, 0xABC46CB454D31ABDULL, 0x67FF895B25984917ULL, 0x846EEA320CFDA062ULL, 
            0xC2B319227385CD0DULL, 0xD29A932381A8614CULL, 0x7431B759565DEC1AULL, 0xD8AD801371EEDF74ULL, 
            0x3FCD29EEBB5ECBBAULL, 0x2C2C36C44258C6B0ULL, 0x43A0EA72F908F16DULL, 0x3F19CA6CDE436D99ULL, 
            0x3A505392AAA92F17ULL, 0xE4B4E77E51709C94ULL, 0xF12AF13C4FC92543ULL, 0x4CAEC73AAF5C6811ULL
        },
        {
            0x2B23D91016814D47ULL, 0x1E442DAF67D62C01ULL, 0xCAAB235E550EF2A1ULL, 0xE50F28BBE5BAEB1FULL, 
            0xC045EDC1DA8D16A2ULL, 0xF03B744CB5A77CC2ULL, 0x27643BC510BEC378ULL, 0xFC5873A5023DB381ULL, 
            0xE7F15C51F9B47B38ULL, 0x61DBE8454CF53504ULL, 0x1BF92338BF7288C4ULL, 0x940C20582C1E1AD5ULL, 
            0x587010B99A33977AULL, 0x13DDC0D907F304AFULL, 0x3662C4E00783C8CEULL, 0xE26515F71F80BED8ULL, 
            0x34AC9670295F201CULL, 0x33746742F567D3DAULL, 0x47080564C1B67F7BULL, 0x3359159E3604C989ULL, 
            0x0C9795EB07350EDAULL, 0x4DC816ED72C047CAULL, 0xC235E9679D1B3900ULL, 0xFCFD270AFB59C33FULL, 
            0xC170F119EB108920ULL, 0x0A5BB65803561AE6ULL, 0x9757ED29B1667EE3ULL, 0x2B85F6E878EE4EDCULL, 
            0x2A4878E3652C4A2EULL, 0x19C9BF0D4CA3970EULL, 0x7C5980771007AACCULL, 0x65DD6FCA21CD48CCULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseEConstants = {
    0xB495EF391525C74FULL,
    0x7876F985FD730AA3ULL,
    0x7731857943E2F826ULL,
    0xB495EF391525C74FULL,
    0x7876F985FD730AA3ULL,
    0x7731857943E2F826ULL,
    0x186C5ECCE5702BD6ULL,
    0x57DB62ACE63AD66BULL,
    0x23,
    0xA7,
    0xA7,
    0xAE,
    0x7D,
    0xC8,
    0x38,
    0xDF
};

const TwistDomainSaltSet Soccer::kPhaseFSalts = {
    {
        {
            0xB3469F15DB34970BULL, 0x976374BF5DC49D98ULL, 0x328D8072B58C8481ULL, 0xB1DAC4B8F59A4A42ULL, 
            0xCECB4927FD2238DBULL, 0x4AD131D3E6A9DF72ULL, 0x60035297E8129352ULL, 0xA8B3C2AEA9661B24ULL, 
            0x71F8BDB0254A8009ULL, 0xC84520710D5DD5BEULL, 0xE58D6C32F4916006ULL, 0xFF2F5DF42D6BB7D4ULL, 
            0xE4951AE28F5A4684ULL, 0x8E0D608445727D27ULL, 0x322B3BADB00260C6ULL, 0xACAB9AABDFA0EFC6ULL, 
            0x056B153C1EF9E4C4ULL, 0xA01F82BDBB55EE87ULL, 0xFCFD70DBC5E74B43ULL, 0x8CE35588FE0D54EDULL, 
            0x8AEA384A9B9C30ACULL, 0x38BC54828D2D91D9ULL, 0x96DDED0752EA9DEEULL, 0xC8CFF96192A7A5B4ULL, 
            0x7158CBF846845C6CULL, 0xC853B49295EAA7EDULL, 0x2F3C88414E175938ULL, 0xDE4FBF1727F216C0ULL, 
            0x268BD7033A71AC87ULL, 0xF37A4D70B0E98851ULL, 0x28BB7BD1F68D9BE5ULL, 0x44EC9624AFF04D4DULL
        },
        {
            0x274CE6C42F8B6473ULL, 0xF999C3BDA96AB70AULL, 0x80435D912024B650ULL, 0x80F04DF1FBA80E6EULL, 
            0xF4441FFE233DE314ULL, 0x4269C3BB1984741CULL, 0x1D6387A46657C0ABULL, 0xC7B8D3786FBC1488ULL, 
            0x4A628DC0A7E3CD4AULL, 0x61FFA31611AB38BCULL, 0x8DBAC69939B12CF1ULL, 0x6721F23A4670E0ADULL, 
            0x65587B1E42376FCFULL, 0x400DF41969CA184BULL, 0x0CD931FBDBB07FC2ULL, 0x8D786224CDC2C659ULL, 
            0xC9BC2521B7CC9673ULL, 0x29AF64434ECA234FULL, 0x3D99329E1F6B58CCULL, 0x9EA905E334B9D2EBULL, 
            0xB02A7B29D0C06BAAULL, 0xB7A19F4CED14FA47ULL, 0x525741A9BBDFECC7ULL, 0x4EFB96CBC72F2CA1ULL, 
            0x4BD011C51EFF3044ULL, 0xEDA93951E510A0CEULL, 0x4758C4A525EB0A7EULL, 0x081586A33CE37621ULL, 
            0x1621E9EC516D6F3BULL, 0xAD427CBB883F3CB9ULL, 0x4883A88561970112ULL, 0x88CBBB8CDCA9EA72ULL
        },
        {
            0x5BDA560D87FE59F7ULL, 0x0E2769D33EE2B7B8ULL, 0xEDE921D259C07F75ULL, 0x932F6350BCABC725ULL, 
            0xC027FB871D5C0587ULL, 0x0D3C0BC247196517ULL, 0x529E635E9CA6CF14ULL, 0x5D5A8FE04CD13151ULL, 
            0x837B7A466F79794FULL, 0x75DBDD4ABD64FAD6ULL, 0xC86E212E50504138ULL, 0x422F22F2B8F4EC23ULL, 
            0x3B6382645936AF44ULL, 0xE52C64EE709C4978ULL, 0xA036FAC147A9AE92ULL, 0x25B21F7A8D6C7A32ULL, 
            0x81CF55B31F896833ULL, 0x57BC4B07C82886E0ULL, 0xB9B8FFA22C8B16F8ULL, 0x3C2E80D11599511DULL, 
            0x9775775759AD60E2ULL, 0x08E65B3F76C16CBEULL, 0xBC6858DDC05332D8ULL, 0x5567BF7D2A6A9272ULL, 
            0x9293D855BA18EBA8ULL, 0xFEDE238845BF68B1ULL, 0xDB0BFF5FEC93BEF5ULL, 0xE2C52695B337F979ULL, 
            0x332B533248D0A571ULL, 0xEC34F3DC73D913B4ULL, 0x6BFA29BE3F643649ULL, 0x69AC0608F3E0250BULL
        },
        {
            0x0F9AA87776234748ULL, 0x0CA7076F79E2B2B7ULL, 0x2ADC1A4B2FBD5DF0ULL, 0xDDA2E04ADA049F71ULL, 
            0x1C1D59BFE8DFDDEEULL, 0xB4FCCC505B24D9D9ULL, 0x262C18B6F84EED77ULL, 0x51E0E739323EF7B1ULL, 
            0xD52AFC5EC13386E1ULL, 0x2D108323F15E7D8FULL, 0xEA8BB4E9D36C1425ULL, 0x6F49B9E0EC9B7E34ULL, 
            0x5579CC2962DAED4AULL, 0x77CE9B924AABEAB4ULL, 0x5CFEC2EC85885B47ULL, 0xB60867D33E4530B7ULL, 
            0x24A602228CA8882AULL, 0xEA85569D88244940ULL, 0x63B69C3744F46C50ULL, 0xA3C6CBC765B8CC85ULL, 
            0x6792948E05983E5EULL, 0x7A90AC28652187A7ULL, 0x9D8117CB813A687DULL, 0xB1F07EB11C374ADAULL, 
            0xCF25E3ABEAFD1EBDULL, 0xA6221702EA833112ULL, 0x3090F56B48721D09ULL, 0x177CD53AED9A0730ULL, 
            0x579AD0EB94F202F8ULL, 0x2A07CF2B5F4EEB37ULL, 0xA62ED339511B0B68ULL, 0x8583C90A8CC2EB7EULL
        },
        {
            0xAB46B3A2F8428D05ULL, 0x2EA9D89403B7257DULL, 0xC4200EF5BE8D7B02ULL, 0xED45313CBC9383F6ULL, 
            0x62EC9AB75802949CULL, 0xD03957EC06DA8E30ULL, 0x7B1BBB9847515968ULL, 0x76383888C4747D51ULL, 
            0x035A6E367589EAF6ULL, 0xC740FBD8BF22D77CULL, 0xBEB855D9A1C76EBEULL, 0xFD79BCD96ADFADF2ULL, 
            0xBFFA7FBD2B0D784DULL, 0xA692976A5CD0DCFBULL, 0xBF02DC5E3B17860EULL, 0xE45B19A5ACBD6589ULL, 
            0xD059988387CE0C0BULL, 0x0476D8495AC92E1DULL, 0xDB489E21D517B596ULL, 0x2073E7427FC9F269ULL, 
            0x9A96F61CDC470E6AULL, 0x92C7826729F1B6B0ULL, 0xC7C1E8BF64FAD818ULL, 0x77F40D18DED418B5ULL, 
            0x85E83FFDB51394AFULL, 0x9A7DE4404E5CC33EULL, 0x322D0F26BE5F553CULL, 0x048765407002960BULL, 
            0x67B1E2B97BDDC16DULL, 0x25AAA344FBBB39A7ULL, 0x88FD7BF0712FA516ULL, 0xEF19545F78722E5CULL
        },
        {
            0xDB357662A9D02CA4ULL, 0x748EA60DDDBE4727ULL, 0x527B8E552429E7A4ULL, 0xEDF21B7582E9A112ULL, 
            0x3477BEFD7762D4C4ULL, 0xDC534A0F00D19609ULL, 0x331FF510509D1E27ULL, 0x5F23FF62300B5DBEULL, 
            0x114003A70326A186ULL, 0xD6CCDF576B0D2AB2ULL, 0x62EC3EC492C86099ULL, 0x4DA5150E6344C323ULL, 
            0xB320C3B4C7A46B38ULL, 0x6BD97F9A664392BDULL, 0xDF81D812EC17085FULL, 0x6CC85CB3DF056DB2ULL, 
            0x891A51BD2B939F02ULL, 0x49CD2622DD021F3AULL, 0x69EFB4774ED42A48ULL, 0x1E8933457C35CFFAULL, 
            0xBE50168DF583ABD5ULL, 0x0DEA3D4106520B9BULL, 0x32AA53C9DD7201C2ULL, 0x0025ED10F4F3F2F2ULL, 
            0xC6B50A1F74850B48ULL, 0xDF6F51C2E1DFB2F1ULL, 0x94BD1D4DC210AF36ULL, 0x4FBE1582DC3858EEULL, 
            0xDED250C099AF9E95ULL, 0x65427A42B98CB2FCULL, 0x48CAD83A96A302BCULL, 0x0F4BDA1B44586EFEULL
        }
    },
    {
        {
            0xFD86A760D127CF90ULL, 0x55800031810AB778ULL, 0x42F4BB619C8D6991ULL, 0xC1623262ABCC9C9BULL, 
            0xAD03A79EC2009F20ULL, 0xF3B4EE771F91B7B0ULL, 0x87C27CE621792EFDULL, 0x90D0D1F158B41184ULL, 
            0x4D1D7DB5661C185EULL, 0x1C8B2982C5EEB815ULL, 0xCBA8576D54BBE82DULL, 0x556682E93EB45AF3ULL, 
            0x2EFC2E7CA876A54EULL, 0x27B60267B51C2BA8ULL, 0xADE05F94BDFA915CULL, 0x28D7BEE493386D38ULL, 
            0x07187FEA10B0FCA6ULL, 0x7EB2AA6004DA3E5BULL, 0x6AE9550EE1169CD2ULL, 0x8A09B38B784860B7ULL, 
            0x2332D9AD619AC552ULL, 0x34893F8F3EB4209EULL, 0xE53B433303DDE98CULL, 0xCEA2FDF841652145ULL, 
            0xAF48AA73F0C1EDE0ULL, 0xE424961411FD1EC5ULL, 0xE7C6B3B9D3690AD9ULL, 0x3BE0E6559B25DD5DULL, 
            0xE5060414B070B2F4ULL, 0x42BC74082A7120D6ULL, 0x8198B057415409A6ULL, 0x2E985D56C18209CEULL
        },
        {
            0x135868410EA36C95ULL, 0x706D39C9D4F5A907ULL, 0x942629002BAF77B9ULL, 0xD91477AAD5755D01ULL, 
            0x7C90F9AAB1B95273ULL, 0xD5673197D61E8400ULL, 0xE73B1CBEF11B1ED8ULL, 0xB2D0026D79155501ULL, 
            0xDDBD60E180F2A73BULL, 0x954495E6F0A967A6ULL, 0xBC88D1A89665A3F7ULL, 0xB1674E734E33640EULL, 
            0x4CB95FAF56512504ULL, 0xFAC20F8F78A1653AULL, 0x13EE69033FF9520AULL, 0x4FB9EEBC91288F51ULL, 
            0xF17D3213AA297126ULL, 0xA3418992BAA7138FULL, 0x6C9069CB2442E1A6ULL, 0x4F81F7EA1B50E7EEULL, 
            0xEC08EA61AEA55381ULL, 0x0847B680895FF027ULL, 0xA33001E4A4D9DC6CULL, 0x239E0EA744B38CD8ULL, 
            0x903065A585770510ULL, 0x307645B635CBC364ULL, 0x282F0F3EA8748FE1ULL, 0x48395938B16F7BD4ULL, 
            0x86A10E62586979ECULL, 0xE66779A3B79D28D9ULL, 0x1FA5871E145F5307ULL, 0x5DBDC7C1AFA2C314ULL
        },
        {
            0xA402BDF3BF0B723FULL, 0xC136D049468A90F6ULL, 0xF12AA500956BAF15ULL, 0x1BF445CEFE93398FULL, 
            0x1151EC0212217271ULL, 0xE31EE9DFB2CC45DCULL, 0xED60016C2E34CBEFULL, 0x22A2E14827E6C1ABULL, 
            0x8D42CD83E5A58FD8ULL, 0x166A11044088BA0BULL, 0x28EC51C3F3D3D21EULL, 0xFDF45C262774B551ULL, 
            0x17BF62CD0E0C05A8ULL, 0x0CC39EB6EBD564EFULL, 0x29E5EC255AE5B52BULL, 0xD7CC721B145B6472ULL, 
            0x99F97C560E5B25AFULL, 0xDBF765CE4540A994ULL, 0xAC69CB2421BBC092ULL, 0xB61BE3A2DF154018ULL, 
            0x994374686751FE7EULL, 0xAEB6A054EE45553AULL, 0x44A80F952E9DC38FULL, 0x3C2010DE5B9C274AULL, 
            0x38D89BDA77C5A10BULL, 0xF3D1AFE13BAAE00FULL, 0x54C548BD25E8FA95ULL, 0x633858A2F712A18DULL, 
            0xAA09C87FC8A44820ULL, 0xEE7E1DB733BB7FA4ULL, 0x7B9B3E84240F3686ULL, 0x1CFB29345A7ED984ULL
        },
        {
            0x8D0939727BC78758ULL, 0x7C65D737308BD953ULL, 0xBBC8E89EEBD50346ULL, 0x52E777C055911ACFULL, 
            0x978EF634549EC339ULL, 0x10CF52D0A8B269C8ULL, 0xBDD67DE666F920A5ULL, 0xCEE81582A2EBB253ULL, 
            0xE1641DE9D375DDB7ULL, 0x7BAB65F0EF64B2E2ULL, 0xE4BF540FDE6E45B1ULL, 0x6A13AACCE6A3F7CAULL, 
            0x1796FA68D2BD09D9ULL, 0x4D9764999A8E0CF1ULL, 0x7DE3CA91B91EAFAEULL, 0x426DCF230631E840ULL, 
            0x5130049542E327F8ULL, 0xED411B9C814A95F6ULL, 0xE0A6523FDB8E4604ULL, 0xBA40C06BDADAC247ULL, 
            0xC86C6D6EEC392637ULL, 0x3294238FF1939062ULL, 0x53058DAE334690F6ULL, 0x0B6DBF1C6495A5BEULL, 
            0xB70D5084CDA90DB0ULL, 0xCCEF547DE9A5C3B8ULL, 0x9B96E61B303A819FULL, 0xF0EEEFDAEFA5699FULL, 
            0x54D39DB0F29BBBF1ULL, 0xA93203B6C267D4F4ULL, 0xAC739A313E27319CULL, 0x43DEE30449EB6AEBULL
        },
        {
            0x3438D3CAD31FED98ULL, 0xF4EDCA44261E256FULL, 0x3D4A7703DE4BECC4ULL, 0x32C08A7AF3DED782ULL, 
            0xE91EF6796CF79B06ULL, 0x5AA0F6A7DFFEDD60ULL, 0xF472371EBC499E36ULL, 0x9443B1934094BED0ULL, 
            0x26B822D0C836A4E9ULL, 0xD496E786B2E2A719ULL, 0xCC092D4903A78D02ULL, 0xEDF48C3B0EA0C835ULL, 
            0x514CD86DB551B545ULL, 0xA38C260BFBD54A60ULL, 0x91E457456B5DA220ULL, 0xA49DDFD5FFB8482FULL, 
            0xF38E47B67DD22F85ULL, 0xA6118C874C856E4FULL, 0x94D91FFCD826521CULL, 0x74D57DB305ECADBDULL, 
            0x2AF27F8F394EB24BULL, 0xACE8F9BA7BD47B21ULL, 0xD40015CE0D169E90ULL, 0x7E628426F47A4994ULL, 
            0x75DA26A637838F04ULL, 0x9D87D4DCDEA6F4A1ULL, 0xB6EDD8AED597EE26ULL, 0x20142D7609681F3CULL, 
            0x732E931FFA4B3A07ULL, 0xE387351193713107ULL, 0xDFC764559DDF818CULL, 0x4033254CF91138C2ULL
        },
        {
            0x81D8E1862940927DULL, 0x470693753703B193ULL, 0x8CECB029C5B7EB76ULL, 0x0FB8005433835D01ULL, 
            0xA5E6DB591751764CULL, 0x235AECE152C0D50FULL, 0x6ACEAB651BB02102ULL, 0xA5F3CA607D0C0F1AULL, 
            0x8640ED8DEE5A05F0ULL, 0x8394CF98DEBDC2C8ULL, 0x273963C38F7D0AFBULL, 0xA0B483B57FE8714AULL, 
            0xD68031EDD4F08D25ULL, 0xFBDDC6BF81211C41ULL, 0x03AEB8B5B130AED4ULL, 0x30E7AEE597FAF51DULL, 
            0xB513316B406C876CULL, 0x74E6749B6C41081EULL, 0x5812C656B81BB580ULL, 0xDBB88FC02A55EEC7ULL, 
            0x116F66140BE33F87ULL, 0xBE51142B5F14A7C0ULL, 0x6546C4531EA8BD9FULL, 0xA5F35CAC1EDD3D2CULL, 
            0x71546936FC00B366ULL, 0xC3ED6871655B4175ULL, 0x0176A3B59F17262EULL, 0x50D1B801A3A29A67ULL, 
            0xAF7A3A04210920CFULL, 0x32DB59E1FEE85048ULL, 0x12546250F47C1FEAULL, 0x96B6F17A8733FD74ULL
        }
    },
    {
        {
            0x4B4B4E70D75BD0E4ULL, 0x5893838C14391628ULL, 0xEC575F88ECDC9CCDULL, 0xD914FEFFDD3B9143ULL, 
            0x3C8CFEBAD94462CDULL, 0x438A0B4690715DE5ULL, 0xDA4261DC7400FB09ULL, 0xBF8E59986D6DE369ULL, 
            0xBAB537D534DEF9BFULL, 0x719C7E6F56BA9067ULL, 0xD63B90543D97AF20ULL, 0x231531582D5B8F81ULL, 
            0x6984F8689260EA29ULL, 0x7D2D869C96F16128ULL, 0x404C7E50B52401A9ULL, 0xB7F447D6547DEAD2ULL, 
            0x6EB866651CF7FC8DULL, 0x9E0057F0FCAE73A5ULL, 0x67947FB626555C95ULL, 0x50FABD9BB4225E2FULL, 
            0x4D19338DE7BF5400ULL, 0x37B00875097FBAFCULL, 0x1736174E4BBFCAFDULL, 0xAAC54FAAA280EC59ULL, 
            0x251E75644ABB3F93ULL, 0xA9A67501D3FE0D6BULL, 0xE71CC002F139AC51ULL, 0x7B30ABCB57A429DBULL, 
            0xEFA8D6EF5CE044F3ULL, 0x2FA60F9FC0EC8CFBULL, 0x66289BF2A39D2798ULL, 0xF9C1DF70F5CC4A46ULL
        },
        {
            0xC34FB66431F624DBULL, 0xB1FFD783ACAEE8CBULL, 0x8A15964B60E4D8A6ULL, 0x366010AD075B823FULL, 
            0x8D026FAE25334C76ULL, 0x025E0973AD5011C0ULL, 0xF580E2618DD68554ULL, 0x28677FE289BD42FFULL, 
            0x6AE149774E0DC958ULL, 0x9E8A624CC8CDD367ULL, 0xC37C86DAD8DFA84EULL, 0x7CFCF43681196540ULL, 
            0x5A33C132AA09E677ULL, 0xAB03E27DEED7E1CDULL, 0x49D54600F18331DEULL, 0xBA7F92A5C156CA69ULL, 
            0xB349681AA53D9962ULL, 0x62AFD57667A0625CULL, 0x1A007734A308432BULL, 0xA4DEBD287249BAB5ULL, 
            0xC99B07ACC0397524ULL, 0x740E54E8A2728ABFULL, 0x7B9A3DB5B35DDFF6ULL, 0x9CFBE4D03657982AULL, 
            0x3B2ADFCED92597E9ULL, 0x27BE718653BC193FULL, 0xABBB58AA25E0F359ULL, 0x97072C831E2937CAULL, 
            0x20864E04BC94CE22ULL, 0x227FEF4388A87BBCULL, 0x09CDE5512705009DULL, 0x95CA68A546AE02E6ULL
        },
        {
            0x79E4AC3059CDDE11ULL, 0xF048CB3112239A4EULL, 0x6772EA4E73EDE144ULL, 0x71A04238E5616E8AULL, 
            0x8554DE83A3686EDEULL, 0x13FD557EF7072699ULL, 0xFD12F3776573CC1DULL, 0x48BBAA5C13192E26ULL, 
            0x84B415B9FABA6466ULL, 0x56982DACFDFA6F51ULL, 0xE3C7014350BFB385ULL, 0x73162FA7666461C8ULL, 
            0xF6A7AC5940E04D0FULL, 0x3B03BDACB0FCF1B0ULL, 0x63FEF4EADF8B9005ULL, 0x1E7107B01E99EBD3ULL, 
            0x28CCC88B221E574BULL, 0x1F10120A2C670679ULL, 0x0183DE4F6DC69CA5ULL, 0xD15FD7DB7F9CCAF6ULL, 
            0xAA7FD2830CE218F6ULL, 0x8D7DDECF029E9ACAULL, 0xD055BDC8090CFC86ULL, 0x3973BD50A6464CAAULL, 
            0x3E4CABEADE67630DULL, 0xF366FE319B62BB15ULL, 0xE234E2785C4F4B27ULL, 0xABB65C18F95FF4D3ULL, 
            0x4DD9573BD55BDD62ULL, 0xB3FAC87B4635D321ULL, 0x00FF78CCF74B9571ULL, 0xB5922BF2A12FF308ULL
        },
        {
            0xB59732AAB8DCDF6CULL, 0xE1897D4B504F1127ULL, 0x5116A375DDC62D6CULL, 0x74ADFFD0B94C0F6DULL, 
            0xF5123A09D4BE6C78ULL, 0x619E805416B352C7ULL, 0x987A1577019C8D69ULL, 0x03A4F23801F4AF8BULL, 
            0xDC8C403D3109DE9AULL, 0x8C567A1650920069ULL, 0xDE3F4AB2F2C1B47EULL, 0x35F4BAA606BB3E9EULL, 
            0x07F70DE4B1DB1398ULL, 0xFB6CD1144766299CULL, 0xB669FD8EB96954ABULL, 0x48EB236BA05ED977ULL, 
            0x0224D9876A17C5B8ULL, 0x0C5F38C15E105ED1ULL, 0xA7394F46A699D255ULL, 0xCE86CD3483F62149ULL, 
            0x7840116F9AE21A26ULL, 0xE9A01B02127A56EBULL, 0x5C479DF2023A0D68ULL, 0x349ABF61AF9CAD7CULL, 
            0x40F98AB8A1622F0FULL, 0x99802FEC5AC395B1ULL, 0xD8B7D3E543007521ULL, 0xBE2FC3D63CF617F9ULL, 
            0x67F7FD7DBCC8732EULL, 0x5B33ABDD8B2F59A8ULL, 0xBD508752736F72A0ULL, 0x45E3FF5F09FC0644ULL
        },
        {
            0x35D408E725ABE0C6ULL, 0x2451E9438391B8D1ULL, 0xBB88B9B1DB185972ULL, 0x0CB3DB6736B81F74ULL, 
            0x68B1D1C6AF3A8CD0ULL, 0x8F30E4F75FDB460AULL, 0x0783231ACE2DD840ULL, 0xA7EA4DDC3CBAAC7EULL, 
            0xCC08CD72DAB8F0FFULL, 0x0A926CFA8FAD4F00ULL, 0x73AA269769694013ULL, 0xA41E3F0FCDF649EBULL, 
            0x7511E9964004B77CULL, 0x8E171B45D7D8EC70ULL, 0x16566E67C2B75C1AULL, 0x509BFE36248E8614ULL, 
            0x079DFF4C9817B9D2ULL, 0x0AF762D01AB2FC2DULL, 0xEA2BB8AEB7D37666ULL, 0x226F4B1910FCBA25ULL, 
            0x379EDAC69221D69BULL, 0xBE9480A4CC74110BULL, 0x14BF61949ADA60CAULL, 0xA66F7E67AE3A03CAULL, 
            0x5B0CC0EE6CC48664ULL, 0xC45CBB43A90C10BAULL, 0x8E532B024886C577ULL, 0x40A5D7C4CC75C929ULL, 
            0x43989895160D10BDULL, 0xDD380A63230809EBULL, 0x287D4B5A4B520620ULL, 0x9A1ADC669055B7E7ULL
        },
        {
            0x35AF88F51E99B304ULL, 0x4C48B5C5AF463DDDULL, 0x1F5F0D06049B1705ULL, 0x1CC86A55E5FFBD93ULL, 
            0xBF99C92E5FBCA28FULL, 0x5254BC0C9D775E82ULL, 0xA525A00262CCAFCBULL, 0x0D12357EC1788E9AULL, 
            0xB39E4A288DC4D7C3ULL, 0xDD41C6FC65E681DFULL, 0x0DD4111517228D2FULL, 0x9E72865FFDFAE26CULL, 
            0x7AD7EFD52D72DF4DULL, 0x8E422FDB620DA036ULL, 0xADBB6C6B248EDF37ULL, 0xA23D4D1A2D0496DDULL, 
            0xE7FA8931A18D0009ULL, 0x74BE42EBAF55499EULL, 0x461AA959F8E635AFULL, 0xE31C0A746715B6D6ULL, 
            0x4859B52D8F814807ULL, 0x11A24A94711630C1ULL, 0xE6874096CFA44FAEULL, 0x03FF0888E0A3EE46ULL, 
            0xBF9BA900BB7E2222ULL, 0xFA3902387CFC53E4ULL, 0xAF32616FB792C3AFULL, 0xAF1B2E87613D9FFFULL, 
            0x66857DD3EF30F1FCULL, 0xF6037AF43A5D5C1CULL, 0x809CFC41A4F01EDCULL, 0xB8FEE77EC536E7B1ULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseFConstants = {
    0x6C3391D5C123E63DULL,
    0x290378EAFBA9D45EULL,
    0x997677F7D3E58D4BULL,
    0x6C3391D5C123E63DULL,
    0x290378EAFBA9D45EULL,
    0x997677F7D3E58D4BULL,
    0xE9A1982FB8DE5561ULL,
    0x3A3D820895B51F41ULL,
    0x5A,
    0xA9,
    0x48,
    0xBE,
    0x8A,
    0xE7,
    0x25,
    0xC1
};

const TwistDomainSaltSet Soccer::kPhaseGSalts = {
    {
        {
            0x05B5EDA71804805EULL, 0x3AB5166F8A02CD3CULL, 0xD57705AD24F39CC4ULL, 0x6DA71A8AACC7B5E4ULL, 
            0xE5BADA48FD4046FEULL, 0x024E25D513A98514ULL, 0x879B82C2B389178DULL, 0x443B681FE08CF93DULL, 
            0x35AB4B9A9E63ED3BULL, 0xD8EFBC146B740091ULL, 0x5A15E000924BBD87ULL, 0x6F7CD09F37FEFEA6ULL, 
            0xAF8DC33DECEE59CEULL, 0x79147FF46FBA9B27ULL, 0xEB25FDD18E6822B9ULL, 0xC171904D67583BD2ULL, 
            0x25B53AAF0919D814ULL, 0x735F6DB0D0BABBECULL, 0x51FF8B76C71D666BULL, 0x3EA17F8195473738ULL, 
            0x0F09EBD04AB95FBEULL, 0x1066367BAFCF9DF2ULL, 0x2D900B01F7712553ULL, 0x48A2FFE1E573C01DULL, 
            0x6753EFB40AF04ED6ULL, 0x20BB1D34FF6D57A2ULL, 0xC66547ACF9F8CB96ULL, 0xC8871D5612AE3E02ULL, 
            0x12A15DC4C1DCF5AEULL, 0x872D19F310DCFB41ULL, 0x439569E88FD96405ULL, 0xDD507BFE6BC54F61ULL
        },
        {
            0x9BC468105360DAA4ULL, 0xA73AEA14FAE31029ULL, 0x1F3882AE9943EC9EULL, 0x484AF0F967BF48DEULL, 
            0x75C5167EDDB29462ULL, 0x130EC325F989AF73ULL, 0x9A7D76854E164139ULL, 0x4884E6F892ED1995ULL, 
            0xFFCC68A992D5F887ULL, 0xAAE8DD4D14962413ULL, 0xDF4F6F66E396A833ULL, 0x406A2048CA15613BULL, 
            0xE375E45024B5038AULL, 0x66B0C3AE992A080BULL, 0xF6A6366BEAD8ACFBULL, 0xF6947F8A2E896C45ULL, 
            0x659699EF4D8D05B3ULL, 0x13EAFA2CA6F83AB0ULL, 0xBC17D6F5B706FC7BULL, 0x2ECD0820EA2C8F58ULL, 
            0x2D66D7AAD19D5D88ULL, 0x02BA361F70EEEC99ULL, 0xE543CC46531B73C9ULL, 0x8C90A4D13E63C331ULL, 
            0xCF1C901CA1066A9CULL, 0xC48D6A7D18B93133ULL, 0xCFCC804E2E9099A1ULL, 0x0352A74B67BBFF7EULL, 
            0xDF97DDFC38D5CA6DULL, 0x2CF1E412A3AB87E1ULL, 0xCDEDCF39697930FBULL, 0x3A414043B90882DFULL
        },
        {
            0x61024A6E1A977F59ULL, 0xF69E0A2AA5C2FBC6ULL, 0x06A49ACB8D3648A1ULL, 0x544B3E6623687E94ULL, 
            0x08249E0BDD5548D8ULL, 0xDAC77A1B59319809ULL, 0xDA9E6E0D04A0605EULL, 0xEC23C3AF72C18467ULL, 
            0x9820CC9C57560C4BULL, 0x7D0C6CE0D78B7AD3ULL, 0x96B29A14E9C9EF39ULL, 0x939F247D0BB57E9EULL, 
            0x4EF17D9D6C1ACA1FULL, 0xDA7A423E5609FF01ULL, 0x5B659797B779D47DULL, 0xA81258255123887CULL, 
            0x5EC3A8763501782CULL, 0x34B6C3174FB945EAULL, 0xCDD1DEACDE0A388BULL, 0xE71AF229A357D8A5ULL, 
            0xBBED658F4F95E572ULL, 0x518FF0C101AB7173ULL, 0xE811F15DAE0B5710ULL, 0x9CA547ABFB9985D4ULL, 
            0x33CDD61948CF9C76ULL, 0x659B3B12E52DD90DULL, 0x3D1DA7DF4129BE96ULL, 0xA972EDB51222D2F6ULL, 
            0x1EC44E27BBBC792FULL, 0x227815CBEF78599FULL, 0xE06EB0B4F159000FULL, 0xE89C46355DCF3694ULL
        },
        {
            0x54C2D035D720E909ULL, 0xAF446D7E11F1CE04ULL, 0xCDF95077B094636EULL, 0x9433FCC77ACFAF5EULL, 
            0x24DED8BE4D13A73BULL, 0x75AF09B65366EF23ULL, 0x27009CC517591F5BULL, 0xFAF40651583DE1AEULL, 
            0xC4AD1B64A977E69AULL, 0xD74AC4D89841C6EFULL, 0x28AECF3CBC35F9F5ULL, 0x3BD279904402CEABULL, 
            0xB521699853B05C14ULL, 0x849C04D3BE742220ULL, 0x3134C8535A431B1AULL, 0x3E893F17D10818E0ULL, 
            0x85269584BD037997ULL, 0xAED98B096845B778ULL, 0xAAEFACD85A71FF39ULL, 0x664EC60157AFE13AULL, 
            0x657E0B9478541A24ULL, 0xC8441E0C6212F622ULL, 0x8BDED763CFED49B6ULL, 0x9002F65DCE8AECB9ULL, 
            0x1B2485E632F3AF4DULL, 0xAEDCEBA028A43F33ULL, 0x0CB1F32EA1ECF17CULL, 0x67DB0F527FB241F0ULL, 
            0xA38B1B07BFC9A479ULL, 0x87EC32D37EB23EC8ULL, 0x193BF738180615FFULL, 0x285B67C9A4E19C6CULL
        },
        {
            0xA3E530C15754EB54ULL, 0x7E19D3D6D4769E98ULL, 0x62A484A34728003DULL, 0xC3168E7AC3242A23ULL, 
            0xAC7904E428CCDAACULL, 0x281845495882A89AULL, 0x07838C1AD077B9E6ULL, 0x43A2A24BF8B47E2DULL, 
            0xE32C94A1BCE5FF03ULL, 0x464F86C633B000D2ULL, 0xCF898252DBB90E73ULL, 0x69A973E5C812847BULL, 
            0x8E00454E7713CEC5ULL, 0x42F592A0E22FA7EEULL, 0xF0DB6064081A1C63ULL, 0x7294FC072E3E0429ULL, 
            0x4E5A4D4D065FD652ULL, 0x1CF179692EB7204DULL, 0x01DCB3AEB8BFDE07ULL, 0xFCADC931C324E35AULL, 
            0x54992F3A0B69452CULL, 0x96D05EAD8F1634A7ULL, 0x6D2669E0B9FADDB2ULL, 0x8068A7ACBF3ECE0FULL, 
            0xFD706704B8665E27ULL, 0x7D349AA96EC13E46ULL, 0x7C9B6E6A81123648ULL, 0x79294E528CFBE6F9ULL, 
            0xA60C2088065EC5F7ULL, 0x1C30D9950F853317ULL, 0xF2FACEDC3CCE596EULL, 0x16717A96D004478CULL
        },
        {
            0xCB65D52951463983ULL, 0xD4055020E26D9105ULL, 0x0ED400050F7328CDULL, 0x4C6FB37A710F3736ULL, 
            0x9D4E38237BB07F68ULL, 0xEBE64F859B7C1A55ULL, 0xE7308D97DEBDD685ULL, 0x8DCDAEF1F1260DC1ULL, 
            0xB90A3BA063B3606BULL, 0x6FA222631440CF0FULL, 0xC375906F6604BC31ULL, 0xD9EDA4C2B6C0C449ULL, 
            0xA0D2FCEC488CCD90ULL, 0x33ABB82ACEB14DEEULL, 0xED23F7D0D25B9274ULL, 0xF9682A1381CAD757ULL, 
            0xA6D8312807881402ULL, 0x45EF0BEBF749D8C9ULL, 0xE45142FCC728D9CFULL, 0xD7339158C9317EFDULL, 
            0x04E0F59352D548E0ULL, 0x413A71C79F5C78A0ULL, 0xACAFA4DC568CB73CULL, 0x00F41F5A179F0179ULL, 
            0x17611DC58E00E779ULL, 0xBB52F1BFD412643BULL, 0xBA357248720AC019ULL, 0x96ED6FDCB16C2125ULL, 
            0x3964518AF478C995ULL, 0x04689F21842743F8ULL, 0x529D245AA857E672ULL, 0x9EB0BD8745D3512BULL
        }
    },
    {
        {
            0xC127BCACE9148173ULL, 0x87F3D18D9E5B3139ULL, 0x73D653EC61CCEFD8ULL, 0x8A56C57668C8F55EULL, 
            0xCA444DECAF7D1E81ULL, 0x825824B228CD61CEULL, 0x7F3BF3C392B1E17CULL, 0xD28F1C9E257369A7ULL, 
            0x3789F408698FCDCCULL, 0x534E7B0873BBF26BULL, 0xCBB590C27704BB6FULL, 0xECD3CC003DA8E906ULL, 
            0x1A3A81153D57901AULL, 0x877BC15AC44EFC27ULL, 0xBAA39E37643A66A8ULL, 0xBE4835F858536B18ULL, 
            0x454F0805251D4F94ULL, 0xC3CD58E3C1F45A22ULL, 0x30EEDCFF9E225EE7ULL, 0x23D3E49E2DAE7B65ULL, 
            0x718A85A40F0EB475ULL, 0x68467EB8A6D0359CULL, 0xEB161D32FD9F9AE5ULL, 0x04FC0B1E45B93894ULL, 
            0xE7017C93A69143B1ULL, 0x51B3447CB1D3E59AULL, 0xAF90FE3807485AFFULL, 0xFB776D16F7A3512CULL, 
            0x73E376361C51434CULL, 0xC297AA09B419EBAFULL, 0x850D4C6907AF07A4ULL, 0x465C0EE5B60187E8ULL
        },
        {
            0x0CFB3A7216FF6492ULL, 0x331B68B89F2B0869ULL, 0x578B6F0546FAD18BULL, 0x20374EEAEA739B63ULL, 
            0x1A1A830598B7F09EULL, 0x4ABE9D2F86A36CB1ULL, 0x9E3EB31023240FC7ULL, 0x197E044755810EA5ULL, 
            0xA8F325DFADF9EC0AULL, 0x5945B755299CF167ULL, 0xFF5F22F4D3EB22EBULL, 0x57B48C2C23474F83ULL, 
            0x06E28156424FC49FULL, 0x9C38674911725C48ULL, 0xEE3A92FCB8FBA722ULL, 0xC43A8AB858A8A850ULL, 
            0x75FF541175712E00ULL, 0xFFB8260E816A39F2ULL, 0xD3052D6FE193333DULL, 0xE8B6214A056B31CCULL, 
            0x0F1AEBB65D8EA9E5ULL, 0xD2ED6739323C6659ULL, 0x9C6146EA12A90542ULL, 0xDA138F8CDF561E29ULL, 
            0x4D3350FBFA313EF8ULL, 0xAD8E36E88DF3E516ULL, 0x14153BD90D323905ULL, 0x574CC69021F7B8CCULL, 
            0xDC339F47110158B8ULL, 0x59D8A8B03D69AF3CULL, 0x589AE7EAFBFCAA3CULL, 0x7949388C2D7FE21EULL
        },
        {
            0x9319C5B6A4E422F7ULL, 0x5F0B0F10602DA2ACULL, 0x35DACB081B9A324DULL, 0x75A52FD927A36D14ULL, 
            0xD64BEC78B512FED9ULL, 0x9781DE33D4222154ULL, 0x3C157A62F7A555A9ULL, 0x4C5CFA8E948F6B3BULL, 
            0xD533C4A84B20BD9EULL, 0x3136CDA74BB13CA5ULL, 0x94F65E47A8E19DBBULL, 0x2405782C3F312897ULL, 
            0x18AED3DFF9F5AB45ULL, 0xB0D980920EFEFAEEULL, 0x5A0DA8B90EFF8FB4ULL, 0xCD6D3D4C682D8471ULL, 
            0xC1BDE8E277665514ULL, 0x6B3E636A1F8C02DBULL, 0xB3D375635B97FCB1ULL, 0x9033ADCA3BE3812FULL, 
            0x6F598F5F8C7F0CA5ULL, 0xE986EB210C09576CULL, 0x6F53F5519D3C2791ULL, 0xE548CCBCFA66C282ULL, 
            0x507F040CE8AB4562ULL, 0x2A664B80F6AEF75DULL, 0x9F84221BC37BCEE6ULL, 0xFDC1BAFA7B762C49ULL, 
            0xD2F97473F131C801ULL, 0x4AC7C30631EB0581ULL, 0xCA7116935A91FD3CULL, 0x90AA284FC2DA9780ULL
        },
        {
            0xE968E52C4CBF5A4AULL, 0xA29BDB76C5F95D8CULL, 0x5A1DC3A3F7AB5AE2ULL, 0xCC062AA9F91A8244ULL, 
            0xF3BEF57786941EF6ULL, 0x974D80747E3CEE0FULL, 0x525AE0C11EA52457ULL, 0xED1DF982B08D86FEULL, 
            0xE98A7100F8E87E49ULL, 0x546D9D190E28B54AULL, 0x8ED6A4A3E69734A5ULL, 0x0B445DAD51A51E6EULL, 
            0x24DCF1180BA9C92AULL, 0x6B697A3AA3DCD2C8ULL, 0x1D23657D33040513ULL, 0xF9829FD6D4A36D2EULL, 
            0xB5BB3AC5174DCA28ULL, 0x2DACE6B71BBC9E40ULL, 0x400134B2D057566EULL, 0x56291BB0C6458C25ULL, 
            0xC7FC49569AB5EC4FULL, 0xB7F2A6DE5BC54A9DULL, 0xEC58510825A46F54ULL, 0x6B300F21F3D8C25BULL, 
            0xB85E86E99A97EEC7ULL, 0xF13D4CDE421AC84EULL, 0xCE782DC1EFD1CE82ULL, 0x64AF9E920A02D5ABULL, 
            0x529402C1FF3BEE01ULL, 0x5198C6EC9A1378F3ULL, 0xA49E9B06816570F2ULL, 0x1B93E4FEC18B3F69ULL
        },
        {
            0x2E71FDFCF906D981ULL, 0x29587C1713C7524DULL, 0xCFE73CC67010B6A7ULL, 0x865504814195CDE5ULL, 
            0x24A4D2E410FC772CULL, 0x2374BD1682EA5738ULL, 0x05B9DFDFF4637968ULL, 0xCEFCDEDFE8F578D5ULL, 
            0xBEE00A80CDB1B389ULL, 0x6192395DE32FD9DDULL, 0x51D0D2F485752102ULL, 0xCCC25657F979A140ULL, 
            0x332CEEA11BA979B2ULL, 0x3ACAFDB7AE3D2F24ULL, 0x078BBE650F8A5293ULL, 0x88B85352DA0EC42FULL, 
            0x9FADC5F07F57D063ULL, 0x866981F52681DE77ULL, 0x9F8D36D851266F16ULL, 0x65AD30CE18B7C4DBULL, 
            0x784E944D4E05D455ULL, 0x8B9FC20FC018EC4CULL, 0x2C37FD4C797C0D9AULL, 0xDB22F021694C7EB4ULL, 
            0x1E48732CFD280114ULL, 0x2F1622A92DEAEA6CULL, 0xEA0D15A1F72BCD35ULL, 0x26FB4D4D6335FE99ULL, 
            0x19489752689B7D57ULL, 0xE13CFC177D935EC7ULL, 0x95CD9753770C4B13ULL, 0x78D25824A7D22E30ULL
        },
        {
            0xFBD107AB390ADB2BULL, 0xC8A28BFC0F64DCF6ULL, 0xB228A19E7F1695D0ULL, 0xDB2B0C9C3823DDA5ULL, 
            0x0870B5E5CB88D6C1ULL, 0xAAE68D017C111152ULL, 0x2D4D189D1EEA019AULL, 0x7745922888631F5AULL, 
            0x169D0351F1E15F3FULL, 0x0160A537F2D768A7ULL, 0x5F43DA73E742E357ULL, 0x877D1430CEA2FDE3ULL, 
            0x482E608371C0BD50ULL, 0xE227345BED197E7EULL, 0x21CCCBE758C989E1ULL, 0x7ACDC6E7647389BBULL, 
            0xFAD8DBE99B8A80A1ULL, 0xB4F4C3B2A772782FULL, 0xC19CFA31453F1FDBULL, 0x49E1A623FD664C80ULL, 
            0x2881385518C6BA61ULL, 0x2A9AE043F6AC1F05ULL, 0xE367B50068419E25ULL, 0xC7CE933300153BA1ULL, 
            0x38710CE05AC8E74CULL, 0x2F92A637D0770322ULL, 0xA640518BBDFCF709ULL, 0x9D87A8B943038447ULL, 
            0xB15299E33A1EC369ULL, 0xCA49397C44DD1FE4ULL, 0x3A6711DE2A199627ULL, 0x64183AA6AE10DD6BULL
        }
    },
    {
        {
            0xF6BB2501604BB58CULL, 0xD86A3DC43D23B8CCULL, 0xF2EAC987B2E8F5B6ULL, 0xB56340A8DEFC67AFULL, 
            0x1CF06F84003B2B16ULL, 0x3FDB5AFAC4C5C7A3ULL, 0xD6A86A3681D5CA3FULL, 0xA8A2342D204170A1ULL, 
            0x08F9E1E4158A5DB7ULL, 0x4775F5FF0D466027ULL, 0x0C38407C958FF29AULL, 0x4A535663153B1784ULL, 
            0x1E543BFB154B09E2ULL, 0xFE0D4FC0E70BA083ULL, 0xF23CE6839403EB2BULL, 0x3B216EE4975CCED9ULL, 
            0x4D2EE84F0AABAD44ULL, 0xA82784ED4EAB17EAULL, 0x30E95CF0A50BF038ULL, 0x3072226CBE983EBBULL, 
            0x6D0575D649898DF7ULL, 0xB654CCC15BACAFE0ULL, 0xDDAE164ABB951BEDULL, 0x342B16B5EE21861FULL, 
            0x2A33118C1638A7CDULL, 0x18E0D8DB58EC7D0FULL, 0x1EE22DF25615270DULL, 0xF84AFF9C448FB3E6ULL, 
            0xDD3E2EA5C613C9FEULL, 0xAC81070D5D952C73ULL, 0x1A68E5BA78D0DA78ULL, 0x454812E0953935D7ULL
        },
        {
            0x0E8F82D0EA918904ULL, 0x9B302E5414A8DDF0ULL, 0xE0D85A38431D2656ULL, 0xDA12F2F0FC2766ABULL, 
            0xF1304C5A3A9AC2CBULL, 0x3AE724853D7BFBA8ULL, 0x6F49BADF834F0984ULL, 0x06EBE12B22E9F3B0ULL, 
            0x2F41982CD9D3CCD6ULL, 0x449B21E6E3DBE123ULL, 0xFF39C61E19B98756ULL, 0x500CAEDB3DFF59C6ULL, 
            0x74C028B6AF33565AULL, 0x2CAFB96F961315E3ULL, 0xE2F7691A33F5C45CULL, 0xFCFCE35BE6B6766BULL, 
            0xF2669007A851841FULL, 0x72604698BA5F8AB1ULL, 0xDC449080B370C740ULL, 0x6A964608C7E888E1ULL, 
            0x343F7C9421290284ULL, 0xEB8EE094E8E69F97ULL, 0xE90C59D7EABEB816ULL, 0x2CF682F2F499EC7AULL, 
            0x7B288C3CDEA8565FULL, 0x346AF3CF39B2C34FULL, 0x5D12EFFBB49B71D9ULL, 0x0C7777CC947A12A6ULL, 
            0xEBB8469621B6DFB9ULL, 0x7ED09C089CAE916CULL, 0xB1302C9C13CDAAC7ULL, 0xE6FC6F5B857D164FULL
        },
        {
            0x8C2525759F6B2678ULL, 0xBF2CEA9AE0929597ULL, 0x459A050E4A87D880ULL, 0x88E79EAB0B710F82ULL, 
            0xEDEE71F83CA939BBULL, 0xC2364ABBC2A16C3CULL, 0xBE0451DF6AD8F8CBULL, 0x9F6CDB295BE07176ULL, 
            0x54C0B09AB6FE4734ULL, 0x99BF06697C492CBEULL, 0xDD0FEBE7A015B6ADULL, 0x3E2F2F4EEE9C9FE5ULL, 
            0x254768C5A842E9FFULL, 0x85F72AD2131AE4C2ULL, 0x3529D853156C5AEDULL, 0xC8B8E97F9DF1F543ULL, 
            0x764EAE4C7673B6EFULL, 0xF53897BAC0033BE0ULL, 0xC4D078C3DDBB419EULL, 0xF050DDDE7621BFEBULL, 
            0x6A624ED23955F9DEULL, 0x6A0D6C7C60A74A71ULL, 0x78DD6AC04749928EULL, 0xDB92722A905350A8ULL, 
            0x4B9964B8592B5761ULL, 0x6DAE80B44F959832ULL, 0x8D60F8D2EB51509EULL, 0x4CAD50D314AD2415ULL, 
            0xCDA96A88D2326AA6ULL, 0xFE497FF77D9B950DULL, 0x2CB4657C58A52DDEULL, 0x433980979BC9D937ULL
        },
        {
            0x01C22F77A0A2F15CULL, 0x742BE007CDDB50C5ULL, 0x44CDACF53A37DA55ULL, 0x420F97C425B66A5EULL, 
            0xE2995A429C63EADAULL, 0x0D25D891225D7974ULL, 0xFB7383EF3C579A44ULL, 0xBD1EC0E24E159C0EULL, 
            0xC2B81043B90F1BACULL, 0x3D7161839126CA8EULL, 0xE17003662702FE2FULL, 0xC1978AE7F8357D53ULL, 
            0x16AA7AC0B4BC9739ULL, 0xDC4BBC5C4714E845ULL, 0xAC1935C2276D6F81ULL, 0x6A6DDB88AFDC31A8ULL, 
            0x9B6CFF6268531000ULL, 0xD0CF70243AB9E194ULL, 0x78FB04C9A40905A4ULL, 0xBCFE186C7C38D8AEULL, 
            0x3EA068E66047DDF7ULL, 0xE9ADE17BF8DDC63AULL, 0xFD3E875EE2D14042ULL, 0xB3045D4B3B3EB39AULL, 
            0xC301697CC3953832ULL, 0xFB35EF78FA200CEDULL, 0xD544398173B3DF2EULL, 0x0C83F816C67BC469ULL, 
            0x45DD4CBF5A0B64D9ULL, 0x43F32CCBEF42BF4DULL, 0xC8B134A08693F828ULL, 0x67F69AD4C3CF63FEULL
        },
        {
            0x6AC1B5D8737EA8CCULL, 0x4C765B58E8713AB2ULL, 0x79859EC9CF88ADA9ULL, 0x17741175CE7A2970ULL, 
            0x3F429AF9B3350B8EULL, 0x6C2FD13C17C17A94ULL, 0xC8DC15E678CDF82AULL, 0x6FD7828224406CDAULL, 
            0x3F3E4A7620F7D32CULL, 0xA1C10D2753245F71ULL, 0xFC44E3C374489B3DULL, 0xF57A9C706606FF84ULL, 
            0xC36F47BA868BE916ULL, 0x150DB64A80A36C6EULL, 0xEF222C960268E7E6ULL, 0xB02998DBB695A5A6ULL, 
            0xB5AE0985CBDABC43ULL, 0x02FF978352199610ULL, 0xC5568D2C3E94EFA5ULL, 0x59624EC2C6DB81FBULL, 
            0x2A7AA67979CDFDF3ULL, 0xF680FCBBB77B6B3EULL, 0xA53E20335A79938DULL, 0x6AC99C762C0B9EE5ULL, 
            0xDF0ED13CB8F27EBAULL, 0x4E066EB3BB3B2E33ULL, 0xB9F36C759FC42311ULL, 0xEC2581ED9F24E9A3ULL, 
            0xC21EC1ECCF449B06ULL, 0x382BAFB728D7A2F8ULL, 0xC113EEE761D7D4C1ULL, 0xBE18F2875A6929F4ULL
        },
        {
            0x59EE3AFAF21931DCULL, 0x8F07866A1F118A40ULL, 0x729C4A1C814A4CF7ULL, 0xB0BE0769E199521BULL, 
            0x201DC970276CE3E4ULL, 0x8CFE0F3E0FB7AE5FULL, 0x2ACBF706B6037997ULL, 0xE899B3AEDFF7D90DULL, 
            0xEB550A5EBBF67815ULL, 0x2F8B8F176FDC7216ULL, 0xC151659ECA1A5322ULL, 0x731AC9288D45FF1CULL, 
            0x109CF2F2123A110AULL, 0x7594822387AB4D50ULL, 0x18E8FC6FB060CC07ULL, 0xFD4B662C4D2C9F36ULL, 
            0x653D5EC1E0B63DF6ULL, 0x282C440F1E842F32ULL, 0x985223E408331172ULL, 0xAB8D9BB2177884C4ULL, 
            0xC061196D3F8420F6ULL, 0xC94EDDD416579CA4ULL, 0xDF6E1CAF4C6BF5A3ULL, 0x770A28E52CA52457ULL, 
            0xAF224F3BFACFA30BULL, 0x69AD1DDCCEDFB723ULL, 0xCFD55FB2B562D4B2ULL, 0xA82CA3FA17487108ULL, 
            0x9FDB60EF170FAD98ULL, 0x08BB989222282646ULL, 0xA56AA621235DB5F1ULL, 0x457F018306FD93A0ULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseGConstants = {
    0x819642ED9EBBF2D0ULL,
    0xB7F4BFCE7D116D3CULL,
    0x6055BB088329F522ULL,
    0x819642ED9EBBF2D0ULL,
    0xB7F4BFCE7D116D3CULL,
    0x6055BB088329F522ULL,
    0xCB3510466155001EULL,
    0xE452C54052B0B39CULL,
    0xA1,
    0x8E,
    0x26,
    0xC7,
    0x83,
    0x01,
    0x03,
    0xA8
};

const TwistDomainSaltSet Soccer::kPhaseHSalts = {
    {
        {
            0xC2A5922288C8048BULL, 0x1151DDEA4B1EEA46ULL, 0x0D6F38015446AB63ULL, 0x3A9C036DB90137A0ULL, 
            0xAC8E288F54A2927AULL, 0x952C0D6ECD811BE7ULL, 0xC6281A81FB951AD0ULL, 0xDA41257FBC617D88ULL, 
            0xE3FAD13F7EF65972ULL, 0xF9ECDD9EB3D8907AULL, 0x58837917F23BB91BULL, 0xF58748FD8728A410ULL, 
            0x42136E608579BB62ULL, 0x4A494D3B480D1E0DULL, 0x1A299BCE97DA3510ULL, 0x5C2492CCFD0344A7ULL, 
            0x0ED8118066F81189ULL, 0x05D155112B851696ULL, 0xD037FB35AE8F4B2EULL, 0x5DD7A68399CF4125ULL, 
            0x3E3FE088A8E2B7A4ULL, 0x2F60B384AA4D844AULL, 0xE5BDD780C10655F3ULL, 0xF5A14D281EB8A9EDULL, 
            0x5C24A44E9C2700AEULL, 0x909B92A90CD62AC2ULL, 0x99C23B058479A825ULL, 0x4C97DABCF2BC04FCULL, 
            0xDFDFE4460C8390B9ULL, 0x3D90E784124792B4ULL, 0x188E34BC624AADC3ULL, 0x6DBF287C5E2FFCBCULL
        },
        {
            0xCDE5346BD81633F6ULL, 0x45EBB063B3BA4982ULL, 0x0859BF1EA53A5AACULL, 0x6B2958862ED794B7ULL, 
            0xD36933B5BC54BC92ULL, 0xBDF9B59F94B1EEFFULL, 0xDB0C8085CA333129ULL, 0x659035CA460D5DECULL, 
            0x158BC439A6D8F957ULL, 0xF64425A3A9B5C04DULL, 0xF3B52CE7855C5A01ULL, 0x4A90D95F43DA4EE5ULL, 
            0x11469A54247827F9ULL, 0x7B178FAF4B40CCEEULL, 0x49A2B91DEA542275ULL, 0x2FD37EC888EB34EDULL, 
            0x4C9CE1B08B2B5F21ULL, 0x8CC42F323E236957ULL, 0xFB5DB626E7D74D32ULL, 0x7153E6A63FC5C6CCULL, 
            0xA83B63C4148D56E0ULL, 0x3A5B541126B5D56BULL, 0xE0B4CF94CF4F32C3ULL, 0x29FEC117B5AC5954ULL, 
            0xB3E831EC7F147A38ULL, 0xB89BEE89503F9B6AULL, 0x8AEA743E3A20AC05ULL, 0x525750688A8C598DULL, 
            0xE1EA1C02EC09C925ULL, 0x80384586E7A6F136ULL, 0xFE2BD5C4F886996AULL, 0x79BABF8DE91E6004ULL
        },
        {
            0xDEE29B5C16610692ULL, 0x9EA0128E333B7833ULL, 0x5EFF5B9C57B35C9DULL, 0xDC95A65DB9732A3EULL, 
            0xF1EB7B7FD2DD9475ULL, 0xDE146A45070BE0D7ULL, 0x1415DD2E8C6D89EEULL, 0x66BA4FB6739EB676ULL, 
            0x490DE87A0FDD413EULL, 0x694EA1510E4C9D2CULL, 0xC6F57B12031B4586ULL, 0x6335C9205120D567ULL, 
            0x502B2F66D4918683ULL, 0xC52101A9B6C544FFULL, 0x30B5A020727A56E1ULL, 0xD07FAFB0A97467CFULL, 
            0xB694847723B19DCEULL, 0x7A83A5B713F18423ULL, 0xD9BFCA45705CDF04ULL, 0x2F125EFBB8797F78ULL, 
            0xE3EE3ABF6E0BEE48ULL, 0xD0E32AAA743DEBCCULL, 0x1838163FD5916B83ULL, 0x695CDDF7124CD728ULL, 
            0x8894556A31854C89ULL, 0x7B155D55BB7D20C8ULL, 0x706288D68463D7E2ULL, 0x4F0357A809D867DBULL, 
            0xAEEB332DF557A503ULL, 0xA50221CACEFA3A84ULL, 0x8B45EC7FDAA65BFAULL, 0x1E9669CAA3D0CA2DULL
        },
        {
            0xC228B1B03519100AULL, 0x124145B1401383F5ULL, 0xBEABD75A7AA4AC68ULL, 0xA672A2BCA6DB58C8ULL, 
            0x2798BC06B6E6F51BULL, 0x7DA9FC03102F52CAULL, 0x3D0DF779119FEBB2ULL, 0xDA789F1865C9A9DBULL, 
            0xA990B6AF22322724ULL, 0x554F01F63E61DE45ULL, 0xB102897CC0DC7ACCULL, 0xAA6F0F8712DFF636ULL, 
            0x9DBC56E00D81E380ULL, 0x30F1B648836C98A6ULL, 0x94A4F1CBA362004DULL, 0x3B95E8069E669DAAULL, 
            0xA0C1ADB5DF230626ULL, 0x86C5E5D19F1607B5ULL, 0x24E130E582722A9AULL, 0xFEB0D48A7F059172ULL, 
            0x00A67947F4664B7CULL, 0x3AD1943F94298EE4ULL, 0x36414F778F856D14ULL, 0x8D0E54947C3EEF7EULL, 
            0xFCD94A75F81C70F9ULL, 0x2F05D5B9863C36D9ULL, 0xB39F2FE5C9C0EB90ULL, 0x2AC27C950CE78134ULL, 
            0xAF84A006B621DCABULL, 0x1BCD38C8497C354CULL, 0x996587A7D65F5ED1ULL, 0x64CA4413217EEA0FULL
        },
        {
            0xFC63FFEB48C052FDULL, 0x1B49DB93FA7013FBULL, 0xD63D595B36070C1BULL, 0xFEC2C988DEDCDA1EULL, 
            0xA225D2538E7D6732ULL, 0x45E9D0F475EDD932ULL, 0x5EEC784C3FE063F8ULL, 0x5F7970DCE4D65C6EULL, 
            0xE82597D415179FC8ULL, 0xAC8BD2678F4FB3D5ULL, 0xBC94C740D0BD6C9FULL, 0x493A0E2548ADDF4BULL, 
            0x95D0629711EB669BULL, 0x7E020B1E869A8EC3ULL, 0xFBFD7A11F358D6B9ULL, 0xC2153AFEC090D7B6ULL, 
            0x431E265883E76196ULL, 0xC5996DC47F7D4D36ULL, 0xB43E18077410424FULL, 0xA205FAEF72812C82ULL, 
            0x418E2DAEB8642109ULL, 0x97543E36A680BBF0ULL, 0x892C87DE1131AA29ULL, 0x33DF720B2768F500ULL, 
            0x6917F481D839FA20ULL, 0x533EF21B6B923238ULL, 0x86BE56C5C11435FCULL, 0xDED0AD437E305D24ULL, 
            0xEFBA4B502AFE3D2EULL, 0x1AF8AA95E5A20B4AULL, 0x29F44C0F033AA02FULL, 0x617A192817992EFBULL
        },
        {
            0x99A918759A87030AULL, 0x5A4AB209FF8C93EDULL, 0xD1D00700284BDD51ULL, 0xBEE0943567396D6EULL, 
            0x0F12B9ED2A9B32FCULL, 0xABEA9FBAE9EDB8E7ULL, 0x9FC6530D7FFA2306ULL, 0xD1A23839BCD1E360ULL, 
            0x25D24102F31620DBULL, 0x696C2B0490043729ULL, 0xBC339AE0672376F2ULL, 0x234C2118DC919E15ULL, 
            0xBCF6632CA8CFDAC4ULL, 0xA3B1913BFED13855ULL, 0xB821C37E1DB342E8ULL, 0x0F7F2F269FD0B4F1ULL, 
            0xBEB9B87BFCA78654ULL, 0x46E333ED630D7DFDULL, 0x7364360E323384F5ULL, 0xCCEF261463C31E71ULL, 
            0x7B858894F81152B1ULL, 0x6462E6116B5E46BAULL, 0xB9658E402B1CBF94ULL, 0x497200BF278BAB9FULL, 
            0x88A5E0803F1632BFULL, 0x617AA02F52790DD1ULL, 0x18BE8167D13409DBULL, 0xB8745AF4C3BBA74AULL, 
            0xC5DA52F50664C326ULL, 0x83E817ED0F7502EFULL, 0x6ED8572199085A7AULL, 0x20F8FD30BB6101F5ULL
        }
    },
    {
        {
            0xC9C5C9999E46ED3EULL, 0xAF1CC15896F68A8FULL, 0x20957EBF0CE90ED8ULL, 0x04BA15132E1DE4C2ULL, 
            0x9895471C6EC9ED33ULL, 0xDAE896F14F074485ULL, 0x3BB897CEBC36973BULL, 0x1F036FE8C47975D0ULL, 
            0x9A40B8C8563508DCULL, 0x03A652760C4E5220ULL, 0xCE1DDEECD4147E84ULL, 0x736676A2E425E424ULL, 
            0x906AB3E82CB77F74ULL, 0x17E22CC71A2C2255ULL, 0xB05865C07C577920ULL, 0x86DB217A34AA4139ULL, 
            0xC7C3E19BB519FE1BULL, 0x70EE0B3EDF10E775ULL, 0xD9DD3ED26FE3A9C7ULL, 0xC82ECB0B79B2A2E9ULL, 
            0xFD9F9BF8010A4E8EULL, 0x768AC025B6CB9C59ULL, 0x1269A52C0BA1ADDFULL, 0x84F2CFE4DF61DF3BULL, 
            0xB7C252CE1AE4D5DDULL, 0xC8E4DDF00AA8AF1BULL, 0x1FC45D332AE9B2FFULL, 0x68F673BA5419B51AULL, 
            0xF58C4A79AB6C13E9ULL, 0xA810DEF64EF8EB8AULL, 0x208FDDFDA591AA65ULL, 0x4ECEE169FD0E011FULL
        },
        {
            0xD7026A90392F0AC6ULL, 0xE664C0E99DA2378EULL, 0xB405A21B6638A27EULL, 0x5BBB1B9AC7ADDC55ULL, 
            0x9CD39A53C8747C0EULL, 0x6FD53663FD26F089ULL, 0xCCD6D172DB39B499ULL, 0x61498410C39E4337ULL, 
            0x439F98D5BBED00B6ULL, 0xADA151BA7E913CF3ULL, 0xBD337D2FF68AD4B4ULL, 0xC701EB5A260EBB19ULL, 
            0xD7F6E38029FF59F5ULL, 0x5BD6201EDD466954ULL, 0x625BEB28FD9363BCULL, 0xE309D45842264B17ULL, 
            0x564D56898D1085FBULL, 0xE8D9C88A78E6EAEDULL, 0xB460FDE23D97F631ULL, 0x726465814A613A48ULL, 
            0xB1DE58E3BCDBAF0DULL, 0xDFF8EB613FE9D085ULL, 0x4051FC7CFBB57E95ULL, 0x56E1D3076EF87B5AULL, 
            0x086E2F296E66DC95ULL, 0x885B369B3047D94FULL, 0xF755C4DFB5081A72ULL, 0x058A170F4232A43CULL, 
            0xB065835425564C09ULL, 0xF66B0D1A5618F00DULL, 0xCCC3C6D7027CFDEAULL, 0x48454AA2E7DADA2AULL
        },
        {
            0x248D1FEDD2548C71ULL, 0x4FE9702FB480A60DULL, 0x851AB3C739E21606ULL, 0xDDB71E66D5FE53ECULL, 
            0x07A5A8E1CF9EFB55ULL, 0x1E94CB7733788DF7ULL, 0x75F2BA99EC27A500ULL, 0xA16E90317F587B80ULL, 
            0xDAB4DE5FC5660C41ULL, 0xD78D43441E11D46CULL, 0x4B7B933A4037E4FDULL, 0xA8F9B1B0AF0C22A7ULL, 
            0xE8F441A3B4BCB82DULL, 0x38FAC1A2267C8F81ULL, 0xA579E0BF2FF5EAF3ULL, 0xFA7AA7B88D4D1754ULL, 
            0x98DDADDF695F88E7ULL, 0x6AC16E5C7900D3A4ULL, 0xA89370FFB5A3BD84ULL, 0x20FF606DADCA25F1ULL, 
            0xE08EFA4BCEC27C1AULL, 0xCB921358FB95C670ULL, 0x0F48CAB461ABF25FULL, 0xF9A33217228DC50BULL, 
            0xD6F5E2F00D21169CULL, 0xD5500036AEC70F88ULL, 0x5264F4EED9AC7A8FULL, 0xC8691C61B9452521ULL, 
            0x26A0FB19FBB88317ULL, 0xF81AA5928E88EDB8ULL, 0x07DF5634E48CAAF0ULL, 0x7EB43A077CB82558ULL
        },
        {
            0xFAC5D14A9EC9BC64ULL, 0xBE838C9E44599758ULL, 0x8DE1F61F9D1B8E0FULL, 0xACB9751E98D64D00ULL, 
            0x7C78AB5DED9EA39AULL, 0x4B99FE87950ACE6BULL, 0x10A3E00B19803485ULL, 0xA2E87A2373FA6380ULL, 
            0xE5D734128B50995EULL, 0x3CDE25E0B8D828EFULL, 0x7FECAEFC35E23372ULL, 0xD2EAE8A09ADC7C9BULL, 
            0x1A0E78F311ABA8A5ULL, 0x823E8337DAC507CAULL, 0xAD4EC31BCE68F937ULL, 0x7509AFB032F0801FULL, 
            0x5D2A09E05F7BF416ULL, 0x76A0CCE316A1C726ULL, 0x3AA9E2A19A964C4DULL, 0x943DF8C87C8C4E56ULL, 
            0x3B9E978EACE9C58EULL, 0x5708FC7603B4BCB8ULL, 0xFD41A3C9073E8DB8ULL, 0x55B2D9CCAC8B2DC9ULL, 
            0x9D4BEEE997645431ULL, 0x7B848CC362BD1E5CULL, 0xA8B69F6F1AA385F8ULL, 0x2F1AB9ADB8A89BC1ULL, 
            0x1E9947C597491917ULL, 0x3B8901A1944546EDULL, 0x31A120D76F823D8CULL, 0xCA874741923703BEULL
        },
        {
            0x24FF1197E55CED28ULL, 0x7EB9A29DE6219C46ULL, 0xC217ADE18BADD1A1ULL, 0x6CD0A4B18C788977ULL, 
            0xF953833BCF369809ULL, 0x5C88AE2BCA5B6FA5ULL, 0x3335E324153EA50AULL, 0xDEC20F2A2A73BBCFULL, 
            0x7BE8D264344B82C2ULL, 0x42659C762660E2FAULL, 0x7DD32E13E0692FC4ULL, 0x6485915E28A36095ULL, 
            0xBE9651FF262D9BADULL, 0xDFE1811BAECDC722ULL, 0x9965EF0E20779CD2ULL, 0x43DDF2A48A62755FULL, 
            0x33E3ED685C8843A1ULL, 0x81049C62777AEC00ULL, 0x84D2BA0812F9A73FULL, 0xC8E85D8107434622ULL, 
            0x18371ED3E0F8AD5EULL, 0x099F1FB90D9E69D0ULL, 0x8299B32E08D5ACEBULL, 0x8A26A62BB3E12B0EULL, 
            0x3A7C63DD12EFA3B0ULL, 0x406A951548540D0EULL, 0xF8D311ADB622F3C8ULL, 0x61B2A138BD0C5091ULL, 
            0x252AFAE43920B14AULL, 0x2348CF4BB1147098ULL, 0xAF03090460BD64DEULL, 0x15E8E991FAC88712ULL
        },
        {
            0x04687ED4F9DBFC7DULL, 0x889B675896D2BA8CULL, 0xD706E3EAC4BBD7E5ULL, 0xFC94AF259022A9D7ULL, 
            0xC465ED6EE22E44A4ULL, 0x0AF5BAFFA042DFB9ULL, 0x6E5FBBB94C01405FULL, 0x77FA7528C9F332E7ULL, 
            0xB649073E5A371903ULL, 0xBCBFD2FA44D8162EULL, 0xE0F99E9F0515B9FEULL, 0xD9B09469A01DFD1BULL, 
            0xD80122CB6415E74FULL, 0xD2A6C2BD4DF25458ULL, 0x518FE1C892E11D53ULL, 0xCEEA324FC19B9143ULL, 
            0xF23CDDD6204EF2D7ULL, 0x4FB52A63CCA7E04EULL, 0x8C499C3BE8A98B91ULL, 0xD8349C316CF68664ULL, 
            0x498AAD947B8FA2EDULL, 0x3DE3A5AD5A539322ULL, 0xAFC1B94CBA259C0CULL, 0x0543F4BA3EE2D1E1ULL, 
            0x9E29195CAA9933A1ULL, 0x2F7DF58045D4336EULL, 0xBE4F2E2B5678792AULL, 0x394AFAB7C0A8CA09ULL, 
            0xF7A9B153DFD06D83ULL, 0x2260A571B2789B21ULL, 0xA63162AFE0886D5FULL, 0xF3B732A6104680DBULL
        }
    },
    {
        {
            0xD35E3D5CD948D4A3ULL, 0x8B9D4832774887B3ULL, 0x2BA84930D76DFCA0ULL, 0x4F3853F4983D9E4DULL, 
            0xEE99BE58233452FDULL, 0xE8F33B394ABC2A77ULL, 0x001DC124A7636040ULL, 0xDDCB521D37DBB8C9ULL, 
            0xE1A0C58801DFF055ULL, 0xDE1E0C7A814FB8A8ULL, 0x7E82EAEAC0242D75ULL, 0xB7E9551014DB4489ULL, 
            0x577FD5A9FB975765ULL, 0xD49109EE9369F8B2ULL, 0x928ACF932BDAA20EULL, 0xC0B231AB1EDD7D67ULL, 
            0xD1F1F639C05450E4ULL, 0xDEDD028EE6EBCEE0ULL, 0xC0934A0C2D3CC18EULL, 0xD605DD1F7BF98237ULL, 
            0x0164789D828953AFULL, 0x4BE5DC89CB6AE6CAULL, 0x3F89362E3E704409ULL, 0x53967BF666594B5DULL, 
            0x6C52AFAB1846564EULL, 0xCB04196D92538D1AULL, 0x3CF2DD26E03F515BULL, 0xC3E2A533A07F57A4ULL, 
            0x4771DE23BB40DB9BULL, 0x70939264C3ED6055ULL, 0x45CD5A6A955A295AULL, 0xF183BF68B52320BEULL
        },
        {
            0x9573C92C1A0A2552ULL, 0xA3424DA606552CCBULL, 0xAB7EB3EBAE63AF93ULL, 0x48A6FC988C63627BULL, 
            0x6807459DFF89952AULL, 0x8C1ABF670B3453B6ULL, 0x8A42FFD8C40256B8ULL, 0x3AB15001EEBAA675ULL, 
            0x2FCB9CE8BBD292D4ULL, 0x8FF5B21BB573CF38ULL, 0x2A3F32F4BEFBDBF6ULL, 0xC9247DDCBE08E29CULL, 
            0x0DBED9BF59570C8DULL, 0x4C5F8F483C455B08ULL, 0x1CBD2C8EC7DA555FULL, 0xF15F3222CAB41614ULL, 
            0xDF6A1BD1377AEBD4ULL, 0x5864941D58746EA7ULL, 0xF3E97E4C51759659ULL, 0x67E6CDB4F793C422ULL, 
            0x6C09A4FBFA6AC3B1ULL, 0x2F48155A08017502ULL, 0xE189FFA262BDF5FAULL, 0x807E8007A77CC452ULL, 
            0x47C908BF7660576DULL, 0xCA85120A026A4B37ULL, 0x1D07B72B84663D6CULL, 0x9D543E4D917A252EULL, 
            0x8BDF3992AD77A22AULL, 0x837D5C145AA8461CULL, 0x8E73495AFED11265ULL, 0x309CBE9280393FFBULL
        },
        {
            0x2478F57C979D650CULL, 0xF03129617AEDFAF0ULL, 0x302F86E7B4881D5EULL, 0x38B8D3783BB71B0FULL, 
            0x52F16F5C4D28FB87ULL, 0x3302BA98EA868710ULL, 0x4AE3A52F050D5364ULL, 0xED71EB1A6EF5B5BCULL, 
            0x00C95A94CCED142DULL, 0xE72C2D8DA99E35B3ULL, 0xA25B21C981F77696ULL, 0x52AC96D9D1648EB3ULL, 
            0xF327140879BDA3BDULL, 0xF9B0599735A74400ULL, 0xE5FBBDF0E3F670A3ULL, 0x08E8442887B7D4E5ULL, 
            0x43D2B321CD1F3B82ULL, 0xC9FEFF7BD1327531ULL, 0x861E3466304F32ECULL, 0x1A2DF812409A5C6FULL, 
            0x0D60F04F4CC4F470ULL, 0xB9AAAD582DA1E521ULL, 0xC70AB9C070EEAFBEULL, 0x3BE6C8B537FCC0FFULL, 
            0x3AFCEA1F4DC024AAULL, 0x6F0FD03319BD4B3DULL, 0xBBE585A3C106F13CULL, 0x2052D0F299549D9CULL, 
            0x13C6D92599EDA815ULL, 0xB76E725D72681BFDULL, 0x76072AF619F5F660ULL, 0x0BA5ED06FE0F54C5ULL
        },
        {
            0x727A58ACC351B81DULL, 0x2E9DE6C8BE621FB3ULL, 0x79D5A191C36C7964ULL, 0x52503A8A863779E0ULL, 
            0xF2D42E3E3526143CULL, 0x91EF7078EA1889ACULL, 0x123B34FE27896963ULL, 0xD90EA622F37D7821ULL, 
            0x51F50BAA4AD22EB1ULL, 0x91970A5860305517ULL, 0xC8D51BD6FC076CDAULL, 0x9FD265B6119E5BD1ULL, 
            0xC83BE62AFE2E7397ULL, 0x7D2A5812D8B12BBAULL, 0x34FA97A2857BF73EULL, 0xBA40F80133B9D93EULL, 
            0x334F29DA726DC658ULL, 0xBAE6B8C4B71827F3ULL, 0x0E2E0691E040A01BULL, 0x34EA0965AAAC6C67ULL, 
            0x080F820AB6FB5E89ULL, 0xD3B76C2BC665D434ULL, 0x229E9BBB4950D71EULL, 0x3A8F891C2E9378E4ULL, 
            0x68A7C1E67EC8F7FCULL, 0x6ACC909E34FDB804ULL, 0xB8D2A7A97740B0AEULL, 0x8A854828676893B3ULL, 
            0x489375B55C3DE854ULL, 0x5FEA71D417ABB548ULL, 0xEECF74FBADABA693ULL, 0xC88A572D621E8307ULL
        },
        {
            0x088C629C6DE8403AULL, 0xB2B08ECEACC525CEULL, 0x9E0999289A6957C5ULL, 0xBF2168362B9497FCULL, 
            0xD6E57EAAE02AB1DAULL, 0xFD898E299C116A06ULL, 0x3D86E28B4439B6F9ULL, 0x56A6B56396597B27ULL, 
            0xA208F44298262741ULL, 0xEE63F5516A9612AAULL, 0xFCF97E7036FED887ULL, 0x93AA39705E65358DULL, 
            0x0F5FC46FDE658833ULL, 0x5D19C8E4F46C703BULL, 0xCF6E91D22BA00053ULL, 0x7662AA44A554A1C9ULL, 
            0x3A85D6988EC35F0DULL, 0xBFD760B1D18EA983ULL, 0x690988FB835B2620ULL, 0xF5FB9194EC0CD7D6ULL, 
            0x0EDD18CFF48B4FC9ULL, 0x2E6B8A5B04A12F06ULL, 0x07305E617F417C2EULL, 0x4A2EB94C307E0D2CULL, 
            0x3F11502AE170BBEAULL, 0x2152C211E6662770ULL, 0xEF75CDBFB47762EEULL, 0x3FC76E88CDBE9EA3ULL, 
            0x7C65236D05E18590ULL, 0x62534785EB9D766EULL, 0x482AA618897E160FULL, 0x71A829E8058ED9D1ULL
        },
        {
            0xA73AA71D9D6A641CULL, 0xEB4AFBBCBF8F141AULL, 0x2A62BA02DA11A41AULL, 0xD4777B21BDBD4053ULL, 
            0x458994FFDC3E7750ULL, 0x23906CBB786A44C7ULL, 0x3231A12D54653A86ULL, 0xA4D3BD33F8DD46AEULL, 
            0x33AE95A83F4ED9EBULL, 0x2BD2AD67D63C4F5CULL, 0xBF96B1FB733C403FULL, 0x363489617968DCF9ULL, 
            0x162C21D51DA21DFCULL, 0x11B9EA5338DBB34AULL, 0xC51A93EB57C3D64AULL, 0xD58298E612CB766EULL, 
            0x0D5785DE632CDF73ULL, 0x1441996BB3621EA9ULL, 0x23EB6CC13BEE6F1CULL, 0x3D20C2F16A5D020CULL, 
            0x2F12766A7FA869D7ULL, 0x42F5770F11205167ULL, 0x1CC6B487D9ACC83EULL, 0xFF34E07907D04C0CULL, 
            0x79916A67C875EE56ULL, 0x89C8940B307C545DULL, 0x5360953CDDA56B65ULL, 0x85C54CC4C442A7C1ULL, 
            0x3F1EEDCC7C911A93ULL, 0x87F776F758AFF388ULL, 0x267D131459461ACEULL, 0x3CF8E230D64D4A60ULL
        }
    }
};

const TwistDomainConstants Soccer::kPhaseHConstants = {
    0xC89273861CF04830ULL,
    0xC89279A20F69DC88ULL,
    0x251832079DD68A52ULL,
    0xC89273861CF04830ULL,
    0xC89279A20F69DC88ULL,
    0x251832079DD68A52ULL,
    0x45DAF5AAFC27C478ULL,
    0x21746831F3A30769ULL,
    0xFB,
    0x36,
    0x1A,
    0x07,
    0x4F,
    0x8F,
    0x45,
    0x08
};

