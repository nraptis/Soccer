#include "TwistExpander_Soccer.hpp"
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

TwistExpander_Soccer::TwistExpander_Soccer()
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

void TwistExpander_Soccer::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15126414499355882577U;
        aCarry = 14878326163713366469U;
        aWandererA = 9690883388631335894U;
        aWandererB = 11540404947847122265U;
        aWandererC = 13967768592241405302U;
        aWandererD = 16053912676701327137U;
        aWandererE = 10520394537615737106U;
        aWandererF = 17618254507657499249U;
        aWandererG = 16835521064143078510U;
        aWandererH = 16423846742687093079U;
        aWandererI = 12617816812960939977U;
        aWandererJ = 9854861598882727744U;
        aWandererK = 9442795115046620154U;
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
    TwistExpander_Soccer_Arx aArx;
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
    TwistExpander_Soccer_Arx aKDF_A_BArx;
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
    TwistExpander_Soccer_Arx aKDF_A_CArx;
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
    TwistExpander_Soccer_Arx aKDF_A_DArx;
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

void TwistExpander_Soccer::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 11783654417958629481U;
        aCarry = 12240204086492988800U;
        aWandererA = 11290105390365630281U;
        aWandererB = 16966833374736452334U;
        aWandererC = 9346832708277812594U;
        aWandererD = 15139386319175239056U;
        aWandererE = 13157477752227640918U;
        aWandererF = 10070460998433509743U;
        aWandererG = 16465532487826892525U;
        aWandererH = 12565854924663184717U;
        aWandererI = 11444309532333238381U;
        aWandererJ = 9326568753445203457U;
        aWandererK = 9580948126905942475U;
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
    TwistExpander_Soccer_Arx aKDF_B_AArx;
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
    TwistExpander_Soccer_Arx aKDF_B_BArx;
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
    TwistExpander_Soccer_Arx aKDF_B_CArx;
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

void TwistExpander_Soccer::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneC);
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
    // KDF_B PhaseA invest aInvestLaneB (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseA invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    }
    // KDF_B PhaseB invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    }
    // KDF_B PhaseC invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneD (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    }
    // KDF_B PhaseD invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseE invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneE);
    }
    // KDF_B PhaseF invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneA (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    }
    // KDF_B PhaseG invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseH invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
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
    TwistExpander_Soccer_Arx aSeed_AArx;
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
    TwistExpander_Soccer_Arx aSeed_BArx;
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
    TwistExpander_Soccer_Arx aSeed_CArx;
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
    TwistExpander_Soccer_Arx aSeed_DArx;
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
    TwistExpander_Soccer_Arx aSeed_EArx;
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
    TwistExpander_Soccer_Arx aSeed_FArx;
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
    TwistExpander_Soccer_Arx aSeed_GArx;
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
    TwistExpander_Soccer_Arx aGrow_AArx;
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
    TwistExpander_Soccer_Arx aGrow_BArx;
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

void TwistExpander_Soccer::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Soccer::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Soccer_Arx aTwist_AArx;
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
    TwistExpander_Soccer_Arx aTwist_BArx;
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
    TwistExpander_Soccer_Arx aTwist_CArx;
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
    TwistExpander_Soccer_Arx aTwist_DArx;
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
        TwistExpander_Soccer_Arx aGrow_AArx;
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
        TwistExpander_Soccer_Arx aGrow_BArx;
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

void TwistExpander_Soccer::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 1, 2 with offsets 2839U, 4772U, 1564U, 5469U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2839U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4772U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1564U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5469U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 3 with offsets 5589U, 5078U, 6026U, 1900U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5589U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5078U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6026U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1900U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 0 with offsets 6832U, 2183U, 3535U, 397U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6832U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2183U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3535U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 397U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 560U, 6575U, 3569U, 2342U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 560U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6575U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3569U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2342U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 with offsets 960U, 1871U, 1730U, 298U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1730U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 298U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 3, 2 with offsets 186U, 1501U, 59U, 1762U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 186U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1501U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 59U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1762U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 0, 1 with offsets 233U, 1450U, 83U, 7U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 233U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1450U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 83U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 3, 1 with offsets 426U, 1988U, 463U, 911U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 426U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1988U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 463U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 911U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1116U, 1899U, 1124U, 1316U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1116U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1899U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1124U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1316U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Soccer::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 1 with offsets 3461U, 5340U, 1461U, 879U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3461U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5340U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1461U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 879U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 2 with offsets 6701U, 1446U, 2079U, 5585U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6701U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1446U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2079U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5585U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 0 with offsets 2303U, 382U, 3127U, 2691U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2303U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 382U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3127U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2691U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 3 with offsets 2426U, 4354U, 1734U, 2135U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2426U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4354U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1734U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2135U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2221U, 1175U, 6043U, 5294U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2221U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1175U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6043U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5294U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 2, 1 with offsets 742U, 1827U, 277U, 96U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 742U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1827U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 277U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 96U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 2, 3 with offsets 757U, 414U, 1493U, 1728U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 757U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 414U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1493U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1728U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 0, 1, 3 with offsets 1565U, 717U, 659U, 22U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 717U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 659U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 22U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 2, 0 with offsets 31U, 576U, 1989U, 627U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 31U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 576U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1989U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 627U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 385U, 1849U, 1220U, 51U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 385U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1849U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1220U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 51U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseASalts = {
    {
        {
            0xEA646D39810D2CAFULL, 0x2CE8773255315CDFULL, 0x5F1D349E00C8B349ULL, 0x795428E720D48705ULL, 
            0x77DF73375CB7DCA1ULL, 0x870DB4748582B7D1ULL, 0xE1792EE8476516CFULL, 0x0E4530AE1A305545ULL, 
            0x78DC18F0C792C45FULL, 0x1F7633468BBEA61EULL, 0xC55DA3343DF4A30CULL, 0x3BE5801179F574EDULL, 
            0x14DE32EF402ED114ULL, 0xAC46973AAD1DE431ULL, 0xAE76107D70798532ULL, 0x8450CE03506517BBULL, 
            0xC3BCF4A569F18EB9ULL, 0x9207F4A44489DDAFULL, 0x708483CED7015AAAULL, 0x832C21BCC30A72B6ULL, 
            0x714761F96C67B597ULL, 0x2D73FD8FC32BAF79ULL, 0x53641A118C97BEEDULL, 0x62E201A99DD2D04CULL, 
            0x4BD80ABCA898273EULL, 0x1D44324C67F25400ULL, 0x496775402FE875BFULL, 0x4D3D34DCB7C2A1BBULL, 
            0x2B29414B4D99DCE2ULL, 0x52236D68B31F3B77ULL, 0xE9FED319B136D85EULL, 0x5B1D2515310B0DE9ULL
        },
        {
            0x9CA96B6F03384BC3ULL, 0xDF2A0FED5DCCA596ULL, 0x1BBDC9CC4AEE4359ULL, 0x0863B21306FB02B8ULL, 
            0xD1D7D1404A7FDA8BULL, 0x36D7FF37ADFEA3C1ULL, 0x2DEABAD275CE0840ULL, 0x7C8A5041A711EE09ULL, 
            0x3E314E320004DC77ULL, 0xBAACEE26C94CA120ULL, 0x766980E97B7CCC94ULL, 0x4D2E92977FF57D04ULL, 
            0x6DF24288DA088056ULL, 0x8AF172D9A32EF6F7ULL, 0x5AA18D6A10400C44ULL, 0x306148FD1708AFFAULL, 
            0x1D43B719490669D6ULL, 0xE3EB1B0D7639A3C9ULL, 0x63FB576DD120A5B8ULL, 0x2F738EAD9B75DA6AULL, 
            0x66B8AE498FE2B96FULL, 0x0484AD9102ACAC09ULL, 0x0AF15938C95748F7ULL, 0xD589B7A9253A583AULL, 
            0xD5D1E63612B35E1CULL, 0x23FE00F8B9CD91BCULL, 0x068B94296D76F31CULL, 0xC7BD6A11BD8B7846ULL, 
            0x2F93B46F488C62ECULL, 0x1FC26D2FBDB325F0ULL, 0xA03CDBAFB4B266C5ULL, 0x288CA3D1DD44B77AULL
        },
        {
            0x052197D651CDB71AULL, 0xCE0E71F24AD30766ULL, 0xA3D7BC3B2F983AA1ULL, 0x05A7E8FBAC4B3087ULL, 
            0xF9818948EDB9D7E9ULL, 0x63DF1714329383E5ULL, 0x938827994E5626E7ULL, 0xCB38CDE00A25C41CULL, 
            0x3E200E9860D72229ULL, 0xEB606F811335CEB8ULL, 0x3F3E6C22F62FDB77ULL, 0x37ABD14F3ED2B87CULL, 
            0xFE52DF1127BBE66FULL, 0x092B0D23A013A812ULL, 0xF54BE2F4A8546996ULL, 0xC3D771AC7043AD34ULL, 
            0x09160F11D1F58C21ULL, 0xBF3769F1A18FE780ULL, 0x6A6AD6900C2A5A33ULL, 0x0188159119A379D8ULL, 
            0x45F20AD4497C360DULL, 0xD7F6F4A93C16C8B7ULL, 0xF3EF9A8F051E8057ULL, 0xC41DF72DCF363B6DULL, 
            0x52C019F9F2B3303DULL, 0x6D4CB5A2E30E5649ULL, 0x88DAE25D7C0D293AULL, 0x8D0031820389CA2CULL, 
            0x5800B9261D745FCBULL, 0x94315DC8A3D9E192ULL, 0xA30266C8EFEF6018ULL, 0x29800464FC33ED91ULL
        },
        {
            0x62AE113D60CAE36EULL, 0x9124D2D4138AAEBAULL, 0x675D913364F88900ULL, 0x3B7A69BBEF5B6BEFULL, 
            0x2CB759F3AC4FC442ULL, 0xFC5BFAFA97CEBA3FULL, 0x64FE4EA24E9E0279ULL, 0x17E016B2C47382F4ULL, 
            0x14F78740F6836601ULL, 0x1770CAA1275CA28DULL, 0xD8A05BA4E66CCF68ULL, 0x83072F7191850AC6ULL, 
            0x9AF7773B3FE68EBFULL, 0xCAC842C9A5A94FB0ULL, 0x41BB8D0FA79348E5ULL, 0x5626C8909E290A3CULL, 
            0x97027C75C1D82C35ULL, 0x1D341E8A7C51007AULL, 0x460B646BF6C1F4FBULL, 0x5157FCF4F0917CD4ULL, 
            0xB0B6CF4B0FF2E482ULL, 0x57701DD0F1140A35ULL, 0xA8B08CE4A34E306EULL, 0xB52E61F12C0779B5ULL, 
            0x6CFFD785C6528434ULL, 0x58AA335EB6B84926ULL, 0x97BC5166D7CE8534ULL, 0xE7A29D489CA6CC67ULL, 
            0x2FCA360CB2F80CB6ULL, 0x18491F0297A7D9B2ULL, 0x9586A7EB2F038D0EULL, 0x066CA0920799875AULL
        },
        {
            0x98B8560BD71A7622ULL, 0xB4F8DB8997C4CD18ULL, 0xEEDF71C78411DA21ULL, 0x78FAB67AB66346FCULL, 
            0x96F3A035DEEE0B80ULL, 0xE6130531B364C06BULL, 0xFC0D8E12D6C9F2CFULL, 0xB76C2B2225E988E8ULL, 
            0xA1D877D7259A7E3CULL, 0xBBC848019B29A571ULL, 0x4BDD81CABBDFE1D8ULL, 0xDCBF3CEB719A3D56ULL, 
            0x507767569A5368B7ULL, 0xD4DE92435940E187ULL, 0xE65741D1D98E7DDAULL, 0x68F4FF2853503D17ULL, 
            0x8BC49B8E6B44E699ULL, 0x172C2AED928C9D65ULL, 0xC02F63BE10693301ULL, 0xC9AEDB85292335DCULL, 
            0x70E0A9980A2AC1D2ULL, 0x7E637B70EAA52B4FULL, 0xE9B1B7FB4C0E48D3ULL, 0x4458BAC0EF326FDCULL, 
            0xD36EF956F212676DULL, 0xBB50F3FF73B6D818ULL, 0x34F346BAC0D8F8D2ULL, 0xF5A35BBA489FBFD0ULL, 
            0xF685EB41386D96B5ULL, 0x3C1144695EAE72D3ULL, 0x923C7F3A418477AFULL, 0x0A4302204D010366ULL
        },
        {
            0xF2534BDBDD6EAA83ULL, 0xE4779A31C001F46FULL, 0x222912AA5A37FAC3ULL, 0xEDF0B97E9054A55CULL, 
            0xC87CD557C6679A12ULL, 0xD4C1C357560D135AULL, 0x2354B4E12C4915B5ULL, 0x3C64EB9849C8429EULL, 
            0x68C54CB37F51E1AEULL, 0x70BB13D55EF7B53DULL, 0x866958E68DE3C27EULL, 0x8E9AE69149440834ULL, 
            0x56CB01B8F0D55ECAULL, 0x9E4FABD108220357ULL, 0xB892B270A9B0C548ULL, 0x6A11CC62D6683BDDULL, 
            0x660D4EC1B0A7F3A5ULL, 0x6F1050B8937B341CULL, 0x78E8D5470EA2D0CFULL, 0xA9FDC5C9948F1138ULL, 
            0x8D17A80F53397508ULL, 0xB6EBFCBE03582F11ULL, 0x815311D5DDBF8775ULL, 0x538F99E89E9EB8E6ULL, 
            0x7034A860C02DA34AULL, 0x3ED6412DFB45F2C7ULL, 0xFAC39099881C6A72ULL, 0x8B2DCB1B34846C30ULL, 
            0xC567080CB398631DULL, 0x685370CB4674C279ULL, 0x38E9B9D34A28C23AULL, 0xE2F8E5936ECEF415ULL
        }
    },
    {
        {
            0x4862CA241A7F6F0AULL, 0x24493D3A1C417581ULL, 0x6BC3EAAE4D8E568BULL, 0xE67C05B97D2552BCULL, 
            0x6F53D64A5A255A19ULL, 0x2AF379615D9EDC1EULL, 0xA4C83450D6BE775CULL, 0x20246C27979363E8ULL, 
            0xCA773F2ABD92906FULL, 0x2949D45623BA1FA6ULL, 0xC16C87B483AC821AULL, 0x853B709C67B2ED88ULL, 
            0xFFF7A903B09A0D41ULL, 0xC57A726FC8F9D247ULL, 0x1A00B08FC9BDA24BULL, 0xB095AF88265AD8D9ULL, 
            0x5DC0A36F35B314BFULL, 0x460035B4E0758B37ULL, 0xE2451274293C4231ULL, 0x1742B78080BA57C9ULL, 
            0x6B2430A520FFD6A2ULL, 0xC7C6FF0ADE9654EEULL, 0x0AD2F39E9BCEB3E4ULL, 0x27B565B9CF2A8D01ULL, 
            0x00A7471D3D09B8BEULL, 0x332ECADA8DADBC82ULL, 0x01D89C00F310F98BULL, 0xD3EA5D6DCEB75C0EULL, 
            0x9AFBFBD92E567096ULL, 0x96F51BB6ED1B975AULL, 0x2B27596636794321ULL, 0x84756D0108764280ULL
        },
        {
            0x588158648460D6CDULL, 0xBF1A8AD54852E5A8ULL, 0xE75CF7778315AB7FULL, 0x4D38A4EE529A66BAULL, 
            0xA995CBB6886CDC55ULL, 0x5FAC6F192C01AD60ULL, 0x1A997E3AB437F31FULL, 0xBCED6814DDA5CEC8ULL, 
            0x34C9597B936C0228ULL, 0x1154038E98ADA888ULL, 0x6A7A64475797D6DBULL, 0x9E9A2F73F9B4A50CULL, 
            0xCEEF1435C3588310ULL, 0x048CAA4CAA26467DULL, 0xF6552A40F93DC79CULL, 0x1864221FB83E7A53ULL, 
            0xB2739B318035BC4DULL, 0xF9574805CDCBC53BULL, 0xBC20150E22758643ULL, 0x69FED874BD48F8AAULL, 
            0x3E31597AC8D78976ULL, 0x554A7FCBB6C2BED9ULL, 0xFD76F173D13A6E9AULL, 0x4038555DE471DB5DULL, 
            0x67E4A0F07621F111ULL, 0xB668DE341115E108ULL, 0xF456E6BBB61C1B0AULL, 0x32E966695751452DULL, 
            0xD72B1FE4FC58E7BAULL, 0xC2F1B1B21154A6B6ULL, 0x22002A9B38B75246ULL, 0xFE8180896B224532ULL
        },
        {
            0xD1BCE9CAAB6C4FB3ULL, 0xF386FBF58D84FD33ULL, 0x882793ACC30E14E7ULL, 0x784100050421C9A6ULL, 
            0x16427145EC1C9C38ULL, 0xBCABCE44C019C03CULL, 0x07009F9F5C876303ULL, 0x9B87278803535771ULL, 
            0x9638B15C0C3BA4A4ULL, 0x76C2371131E572E4ULL, 0x778681BD2FE48271ULL, 0x34406D147731AFA7ULL, 
            0xBE055F9D6E3851F9ULL, 0x9167603FF5416808ULL, 0x0E5E57B6FA421BCEULL, 0x9237815871ACD966ULL, 
            0x36E9F6479A23D2BFULL, 0x3684787950133365ULL, 0x3ED7808DBECD4DC8ULL, 0xC42DBE455654541CULL, 
            0xBEF408BE629C7F4DULL, 0xFB6CCD9811D8627FULL, 0x776AB7B03C429F80ULL, 0x6788C2F59AC487C3ULL, 
            0x23D7B95DB6F0CFC4ULL, 0x6B9BAFD7B8876D5AULL, 0xA6675581CD411544ULL, 0xD6E80F44C3B6ABB4ULL, 
            0xCEB0347175DC89A1ULL, 0x07DC96DF8CEE19EDULL, 0x49687D9DC6918C97ULL, 0xFEBF7267498D3D6AULL
        },
        {
            0x578B6CB16430BDDFULL, 0xDF77E17D63EC7278ULL, 0x6108F1FEC3C2F4E4ULL, 0x394B0A2C2C9A1CE5ULL, 
            0x17889D07B8F17465ULL, 0x7E979E6AFBA57516ULL, 0xCA138D4B76A4E037ULL, 0xC8D09E5C94E7528EULL, 
            0xD214459BEE7938A8ULL, 0xB1E6BBB5DD3CD8F5ULL, 0xE4A70F1E9DA748A5ULL, 0xF09206DDBF822271ULL, 
            0xB8E4F190F5066E49ULL, 0x00CE17F718799114ULL, 0xB5901A90AAFCDC81ULL, 0x7E547C30568CF651ULL, 
            0x718054A6A7A3971EULL, 0x57C79B1C3974A973ULL, 0xF5C5CBC230F95C1BULL, 0x1FBA5005781073F9ULL, 
            0xF6EDF2553C2CA5B9ULL, 0xFCB9E679DA9961EAULL, 0x3E696EC87EB86560ULL, 0xFB0B7D70F5642B09ULL, 
            0x00A4E0B798C3B71EULL, 0x0C4EA6AFE5533C72ULL, 0xA2ADD9B3E90DC922ULL, 0xDBC4E037ABF9BA26ULL, 
            0x4BAECF7E0A5D297BULL, 0x86B22311B310F279ULL, 0x682D190209388D7DULL, 0x0F2F22BA9A4C7913ULL
        },
        {
            0x2F48FE2F5901BD97ULL, 0x2300791A328B6ADAULL, 0x8FB05C41FB361E3EULL, 0xDB0FFA096C338A62ULL, 
            0xCEC61A079EA87F35ULL, 0xB852F20986128835ULL, 0x0BAD76D461816127ULL, 0x79B0BEF0C81C70C8ULL, 
            0xB33D9C101EE7FE8FULL, 0xF2F23D8F7D4D6ACBULL, 0x445E19A0E16B356AULL, 0x8B48B99D1ABD829EULL, 
            0xA3F8C51235C18DB9ULL, 0xC607264C1B69D589ULL, 0xD5AF045C8079E039ULL, 0xD3C414F2D49484DBULL, 
            0xCEDE3BB7EEEC91C1ULL, 0xAB252D0228578C8EULL, 0xC7B7F6EFC7D49A6CULL, 0x09CA9C93576DEC7AULL, 
            0xA8527A1D34FA9197ULL, 0x56EE55F9143E32BEULL, 0x79C3431B0E2D92E5ULL, 0x6472B9A1C14B338CULL, 
            0x16957E4F23A01A5AULL, 0x6AA53C4F02A2D0E8ULL, 0xE424562D72B90ABAULL, 0x6FDBC619C410FC28ULL, 
            0x5E48948A6901D400ULL, 0x33EFCF867DDFD4BAULL, 0x817F085BCCFF28EAULL, 0xDB6B81CE01E4BE09ULL
        },
        {
            0x9FB54AA8157FF516ULL, 0x9BBA87871451AAD6ULL, 0x8CCE22562E2EFB03ULL, 0x094AC972B28113D7ULL, 
            0x3B0280DB92E7A3C7ULL, 0x87B854356C7321E1ULL, 0x6EFD82960BF484A5ULL, 0x4CF0864E0D04D107ULL, 
            0x9EAAF3BFF977ECCBULL, 0xDF7356A6F674405CULL, 0xDCE8CE69BC152F79ULL, 0x498538B6B36A12EAULL, 
            0x83D24E21FF1480BCULL, 0xB9263B6BE065540CULL, 0xCBF00DB313150C8AULL, 0x345A5BB4BF83090DULL, 
            0x1632FAE431AC0C3AULL, 0x983035169272D010ULL, 0x6FE926C9D892265FULL, 0xD0B71A25E1DAB691ULL, 
            0xF9394BF3CE031D0CULL, 0x7D427C4AC876FF49ULL, 0x4B3442E3FFF873B7ULL, 0x26FB14D315084379ULL, 
            0xE0EB35B0317BC82BULL, 0x75F0EEA25183CA93ULL, 0x6C5DCB26BB45E56CULL, 0x479D067BC9464DF5ULL, 
            0x881075FC132FB3A4ULL, 0x84BE3960B0978FDDULL, 0xC47CBE99D5A4E214ULL, 0x3E095AF84B62F062ULL
        }
    },
    {
        {
            0xC977F5FA62923618ULL, 0xA9578435F33418ECULL, 0x238B6E9B3893D7E2ULL, 0xADB06B2026DF569DULL, 
            0x5F3A2822E1385F2FULL, 0xFDD4F6C0A915117BULL, 0x60E4CDDBB1ED79EAULL, 0xC6BF56318B67745FULL, 
            0xE5B686BE5EA1DCDDULL, 0x96226CE5D3B25A7DULL, 0x21CFBD2D8716872AULL, 0xC851AE9EB245401AULL, 
            0xF9BB7EB33711BEF9ULL, 0xF1B2275DD6EE7245ULL, 0xCE976E5C38E0340BULL, 0xB8932BC736FAF17FULL, 
            0x070F56898FA52FD6ULL, 0x36E70541E68B79AFULL, 0x88CBD391AFD74B54ULL, 0xD8DC202E6BCBF68EULL, 
            0x0E260C261237F01AULL, 0x8AEA178D996E0D53ULL, 0x8174364DB03131BCULL, 0xD620294D873657D6ULL, 
            0x2CD6708DA80FE436ULL, 0x0C82C80C99DEE845ULL, 0x1A5BEFA605BA6D01ULL, 0x82E73F1CF0A06F3CULL, 
            0x94C1A536960A4BE0ULL, 0x6746488C165CB8DAULL, 0x531214C8DE094070ULL, 0xDCB75751AD18A56CULL
        },
        {
            0x27F3E596D18AFB7BULL, 0xD7A3ECA30A622389ULL, 0xE5CDB6C24A9C387EULL, 0x5D47E155F6B41875ULL, 
            0x18359D9CB17AA96DULL, 0xE8A9B43D60E510D1ULL, 0xE1A89BED1F0A0754ULL, 0x7BDC34BA493B91FDULL, 
            0x7A8A4DF2AA7DA3E7ULL, 0xC9B921865A913088ULL, 0x2FA68358385D6ACCULL, 0xD9A03918164D3AC7ULL, 
            0xA7DC3BC7407264B8ULL, 0xBE59AED8264C3CE9ULL, 0xFD5904C1A049B23FULL, 0xF7C3CDD3FC7EE475ULL, 
            0x96979B7AABB417C7ULL, 0x8F035BB258804005ULL, 0x94D5163446E1E603ULL, 0x1F1829F4B94F7E38ULL, 
            0x5822C058D8283F99ULL, 0x9B408C1EFCF4DDE0ULL, 0xFBA191B0F19358D0ULL, 0x55991021121F1AE4ULL, 
            0x38A099D5ED6059A3ULL, 0x2105EF95695E07A9ULL, 0x8FE4F0C939E7FA75ULL, 0xA7618021B9F9A92FULL, 
            0x0E7A1DA18DF32FA6ULL, 0x612A67123A265A41ULL, 0x13AC2DCA6B3DBA06ULL, 0x0E94EA26A32763B5ULL
        },
        {
            0x904708D2A0577D73ULL, 0x08AA547EA8C59878ULL, 0xCC6CC3EEBC847CD1ULL, 0xBE8970E37ABAD3B6ULL, 
            0x376FF74765AF9AA2ULL, 0x7C3A1DE5BBE0EB9AULL, 0xDC8210520816783FULL, 0xEA82B4976CED0788ULL, 
            0x5F79A928D6DBA4A3ULL, 0x6067E7E35D94DC8AULL, 0xB7AA5647A6B2EDC1ULL, 0xD4882C2CBB0E2C2CULL, 
            0xD0E79F6ADAA235A9ULL, 0xB15446C31A95F604ULL, 0x3CBA765424FE0144ULL, 0xA5DEB2237727C6B8ULL, 
            0x6EC36001A3D5C946ULL, 0x4F53608B2DF38DB1ULL, 0x806CFC8B045F910CULL, 0x7236FB8581FDE426ULL, 
            0xBB258BBB3094818BULL, 0xF4754373E54F1D0AULL, 0x3D89DBDFF9E6A127ULL, 0x1AE512EBB242A415ULL, 
            0x8699B58319E0E30DULL, 0x3D12E6E8C421CB13ULL, 0x5C2591845F68FD58ULL, 0x028C6533246FF6F2ULL, 
            0x6406DFE98C3F2C1CULL, 0xF4A1E0BFEC2E58F0ULL, 0xD7E10405A5BDE208ULL, 0xF181E8AD8C44BE56ULL
        },
        {
            0xD567501D2A2D5214ULL, 0xC0E325B3A9BEEDF3ULL, 0x048C4B5F41D7A7AEULL, 0x40AF6D5D08CC2BDCULL, 
            0x81BB0B5C040B4490ULL, 0x73CCF3336C8C3DC2ULL, 0x4CF5C694DE3A2759ULL, 0x4628FAC4D30D0CECULL, 
            0xECD57699A1C900B0ULL, 0x1862F540D57B46E5ULL, 0xE5CB495145EADA8CULL, 0xB9B2196F95B2F6FEULL, 
            0x269EC3FBAF5C739DULL, 0x9132B573E47C3145ULL, 0x3FDDABCB3B862409ULL, 0xBA559F06AC0CFF72ULL, 
            0x37AF8F62008B1483ULL, 0x087BD7CF85864E84ULL, 0x181E2A9E55712E0FULL, 0x340FAF11150129B0ULL, 
            0xAC12E2AA8CAD3272ULL, 0xE2D255D205A970CDULL, 0xAFFE30BEC2D2F8ECULL, 0x2D7436E4C239FF2CULL, 
            0x99BEBBB68DF7572DULL, 0xEA83E95360E0B7EAULL, 0x968CC282B74730F6ULL, 0x6605B3FB487BDF70ULL, 
            0xD3BF71FE9529389EULL, 0x13E550141FED453EULL, 0x2A563D21DE35EA2BULL, 0x0247C9FBE4A21EE5ULL
        },
        {
            0xF7FA839F8E1E50C4ULL, 0x177EDD67D817B288ULL, 0x9D39FB3CAAEFB1D2ULL, 0x750BF92F2D812FABULL, 
            0x431FB96BE20891EAULL, 0xAC1219C0DB8FACA8ULL, 0x756D028A4DC70EC5ULL, 0x8D4C7AA019F3304BULL, 
            0x35737448A69624DCULL, 0x84DC74CA7AF551CEULL, 0x15201C3E95D6DBA3ULL, 0x3A2513E79BBD9E3EULL, 
            0xC1867D1385B7FFA9ULL, 0x747260D221E7D61FULL, 0x9C90F946976B0EE3ULL, 0x61BEA9ECEAD19E08ULL, 
            0xA82E20432C37A2D2ULL, 0x4EAACDB420F5E001ULL, 0x22D86CE0F99127E8ULL, 0x6C9665781A9E0C9DULL, 
            0xA24D800C9794951EULL, 0x4F62A5DA6C2E5871ULL, 0x94AFCF6EEA63D4A1ULL, 0xBA5C91ACE8847280ULL, 
            0x217964C7221DC279ULL, 0xEA7C87494D1CA43FULL, 0xA7165FF5C15321BAULL, 0xB25E8600F47D5731ULL, 
            0x17DDC015AC0337C6ULL, 0xD46B8F6A1FEB889BULL, 0xF497EA62BF35A50BULL, 0x4BA12B8A823CE573ULL
        },
        {
            0x61B7F01A05ACFF83ULL, 0xAEA3F1C78D92C86EULL, 0xE477690C8C2F3702ULL, 0x614DD935D5420DC8ULL, 
            0x3E5DBF538368A2F4ULL, 0x3A07CCF7A51F2BD6ULL, 0x2D0AFE685CB9AF89ULL, 0xA463D14EC39996E6ULL, 
            0xA3094DA869C2294DULL, 0xEFABCE4FE91E7F64ULL, 0xF23910561CE2C24CULL, 0x4797A01444249165ULL, 
            0xDD54DD077484AB8FULL, 0xB59B45E0EEDA5378ULL, 0x81CDBD6D3B18902AULL, 0x154270F4647A9B8FULL, 
            0x457FB5D71262FD8DULL, 0x0739CF455D8D4622ULL, 0x9EDE647492886382ULL, 0x672A612E0B3F87EFULL, 
            0x5B3A629133F0326DULL, 0x0D7904905E305C39ULL, 0xF40D2F965E1D2D2FULL, 0xC303CC4D1351CFD1ULL, 
            0x57FCF8C34C0CF3C5ULL, 0xBAA4ED5D2A157F04ULL, 0x12AB8B220C62607BULL, 0x35467D3F268D5D5BULL, 
            0x551F53A70AA6462CULL, 0x22FC8BEAE00D0162ULL, 0x4DFB0EA346BF1B00ULL, 0x085B09F300633BA1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseAConstants = {
    0x708591C250FCC1A1ULL,
    0xC499BEE16D4AA127ULL,
    0xC9C16A618524E0EFULL,
    0x708591C250FCC1A1ULL,
    0xC499BEE16D4AA127ULL,
    0xC9C16A618524E0EFULL,
    0x740FDC6594CB41A6ULL,
    0xB24B488CD43A140EULL,
    0x6F,
    0x1C,
    0xE4,
    0xE9,
    0xB6,
    0x21,
    0x90,
    0xE3
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseBSalts = {
    {
        {
            0x3B661C0A9F800FBCULL, 0x406F9380C2CA118DULL, 0x2468E57839312348ULL, 0xCD6A70163CFAFB45ULL, 
            0xF410D3F65615395FULL, 0x340F5048174D2BC4ULL, 0xD3639A4E8F887D9BULL, 0xFF082EC05922EC39ULL, 
            0x7425E57A73495834ULL, 0x61C49124B0157A55ULL, 0x42065DB9BB68D7B3ULL, 0xC1CDEA63C80EFFF1ULL, 
            0x5A17C860000E1B02ULL, 0xE278CE0DFA157295ULL, 0xDE6E6A7F26C15B25ULL, 0x02AE281B96218C36ULL, 
            0x2CE06EC0117DE099ULL, 0x729ED3C9AFD13CD6ULL, 0x2A2C77134CB6D77FULL, 0xAA1C8AA68FE66E3FULL, 
            0xF88CAED3C3FC30E4ULL, 0xC6B96C3C763FD64CULL, 0xFECE949CE794CF19ULL, 0xE6BB8E8D8C9DEC90ULL, 
            0x46D603CBB01724FFULL, 0xE5FAD3C92C6DE8F0ULL, 0xFB508F225F0FBE23ULL, 0xFA401BC71343395BULL, 
            0xD0A074BA6BBE7AA7ULL, 0x31B3DC075F09104EULL, 0xF68F6141298A4186ULL, 0x277B6EB36E6B0CB2ULL
        },
        {
            0x2D60E07DE3AB2682ULL, 0x51865F67B3ADF433ULL, 0x6C50DB2A2F2C50B7ULL, 0x565F6C6C909790A1ULL, 
            0xBF180CC3D9960ECBULL, 0x96A059989EB789D1ULL, 0x76565D969E4677C5ULL, 0x35332BB8C0CED9B2ULL, 
            0xF7B462ABD2C7C331ULL, 0xA84F29E16F3F747FULL, 0x217E0040E7774A10ULL, 0x49D5ACBBEF35EFD5ULL, 
            0x124C9E82DAD3D9B4ULL, 0xFF7F3665E428F260ULL, 0xEEE0C919A2DEF589ULL, 0xF4796A1C497AB89CULL, 
            0xA037931A5E2A151AULL, 0xDA113930A56C1909ULL, 0x194595036B89DE94ULL, 0x0B3F3BC441993F55ULL, 
            0x17DF4597BBCA9D33ULL, 0x65512AFE01A4F01FULL, 0xC2A3F6EBAE4336ACULL, 0x31DA6E55576CBFDAULL, 
            0xB31701F9F4352813ULL, 0xA4516FB9D4DE0F79ULL, 0x2A282621F7384E37ULL, 0xA1053EE24D921492ULL, 
            0xB3B258473A9E4E56ULL, 0x6CCFDC5889A585FEULL, 0x477BBE8750B6B83DULL, 0x8D1722342E26AEF2ULL
        },
        {
            0x71C3217156737120ULL, 0xDCBCFD6566C10071ULL, 0xEAE929918BFC1499ULL, 0xE9BFFDE831C59612ULL, 
            0x128613BBFD3A8D06ULL, 0x14DECF6C4BE0A1EEULL, 0xF5DFCF6D87E48E4CULL, 0x5DCE31DD5212F29EULL, 
            0x1566F5B841380238ULL, 0xCD42B1D96C81643AULL, 0x98ED4B3A25C1B577ULL, 0xF86AB4CFAC053F2BULL, 
            0xED17F9491EC0E1DDULL, 0xBDCB6CE27EF4B94AULL, 0xF53416C02A39BF72ULL, 0xEF8662E35CE24843ULL, 
            0x390F8E715600C52EULL, 0x1796C7BF64E49746ULL, 0xD9B6ACE859B22800ULL, 0x8D574E4C864DC90EULL, 
            0x73C211A9537DAFCFULL, 0xFCABF863C1905DB1ULL, 0xE1A70A1ABD0D7EA2ULL, 0x61430C1ADDBD857CULL, 
            0xB030F3D865BE4A65ULL, 0x4BD9F1CFED8AFF8AULL, 0x277A414FF2A34EC3ULL, 0xD8657F720452F50DULL, 
            0x986B0F2CF8655A19ULL, 0x9B0B5E74861788B3ULL, 0x15A6ABB012C21115ULL, 0x6D9470A412D65B8DULL
        },
        {
            0x951F6476B81DB9FFULL, 0xC8606F8D8202ACA8ULL, 0x13495B0A432461A6ULL, 0x447BBC6BAD3DE63FULL, 
            0x9FFBFEDFCD38D29FULL, 0x0AD92E43FA1CC01FULL, 0x36A56AB776609A6BULL, 0xDBC0C5F9DD1C87D3ULL, 
            0xE6EEFBA34A933CECULL, 0xF4E922F2EA80A48EULL, 0x4099EBB222797386ULL, 0x143D06FE2E459896ULL, 
            0x304C07F1B721C184ULL, 0xB56DBC1F74802038ULL, 0x34A46E469510B54BULL, 0x347B0A328721A209ULL, 
            0x137A82A0978C2D27ULL, 0xE32CAF4D5000CA12ULL, 0xE61485C128B4B9FAULL, 0x348EB8DF43307EA0ULL, 
            0x7D523E082BF28359ULL, 0x9C2558272A4FA40AULL, 0x4A7C95C1B10871BDULL, 0xDB2E25EC9A35C153ULL, 
            0xE2B9D32C346FEEACULL, 0x861143DD0BA6E523ULL, 0x4A3E03CE5032360BULL, 0x389F736583D0516CULL, 
            0x997518960F420F3EULL, 0x5234F4715F1FC2E5ULL, 0x190E0B4BC1D8D59BULL, 0xD1D367A6664254FEULL
        },
        {
            0xF1AA1C93BDEE3D8BULL, 0x01BBC99CD6416283ULL, 0x9C22E1B01967C7F7ULL, 0xCEA25D7AB097758DULL, 
            0xCA44F734BD69F2AEULL, 0xA1B69311F6A2E396ULL, 0x2CEA42448E24F846ULL, 0x30E693F26168D9D6ULL, 
            0x00C83264675114A1ULL, 0x3F0966D93B718936ULL, 0x31E3880DFAF917D9ULL, 0x9E16B6EF024D96DDULL, 
            0xF8B8B86D80C038E8ULL, 0xF1FEC1AAE9658701ULL, 0x2EF5F2AAAED38982ULL, 0x0D882254B19BC394ULL, 
            0x4AC0FB73B0D5F822ULL, 0x8FE02D7DB1F9E261ULL, 0x064E8199CE31FC87ULL, 0x2E75267E33416DDEULL, 
            0xC7B55CB026E81056ULL, 0xC869D57E0E4A6BD8ULL, 0x96D5274E08721342ULL, 0xEA3002D1F8E954A4ULL, 
            0xFE1E393372101268ULL, 0x94921E9125F1EC91ULL, 0xBD3CFFABEEB567F1ULL, 0x24865866150FA724ULL, 
            0x6A3571A990262E6BULL, 0xB42F6D2880C90ABBULL, 0x8C79F8198EAC80F6ULL, 0x63638D8CB1BB2513ULL
        },
        {
            0xEE71B6E45CB67AA5ULL, 0xD9C62F2AC5F1456AULL, 0xF0A3A291E20B52B6ULL, 0x3370F11ECB33820FULL, 
            0xD5FD20A64FBD37D6ULL, 0xEECEBBDA972C7A1CULL, 0xDAC7896322433862ULL, 0xD6FCC7D22AC3ACCDULL, 
            0xC08E690782194D71ULL, 0x761593C357F76FE4ULL, 0xAF57B3ABB7457070ULL, 0x519BA8AC74B555E3ULL, 
            0xE4CE88C301CF43B2ULL, 0x04CD434CB937DCCBULL, 0x25E345001A1206B5ULL, 0x0F1508735D7FC150ULL, 
            0xE68EFF95E1437605ULL, 0x56AA3C9F17F1EE43ULL, 0x625A1423F48C1D48ULL, 0x7A47A196B4D35329ULL, 
            0xD5655A606DEFFB74ULL, 0x7ADAB426DD053F69ULL, 0x6518C0E526979A49ULL, 0x923FBE5E0A90F14FULL, 
            0x11AEB8365AB29C62ULL, 0xDE08616E23CE41AFULL, 0xEBAE2D6CF9F9E7DBULL, 0x0AEEB9A7E285FD5DULL, 
            0x3C76A9B477A3A7E0ULL, 0x214A3713F537ADF1ULL, 0x117BD52108DB2553ULL, 0x52AE985EAAF35E0DULL
        }
    },
    {
        {
            0x647A129BA954B802ULL, 0x6E578D5125ED9ECDULL, 0x8731A833AD0FDB1FULL, 0x66394F0F9D9CD023ULL, 
            0x5444647800476590ULL, 0xDC346A66A03CA8B4ULL, 0x9672B7424C929369ULL, 0xC77AB65A0E7F6F39ULL, 
            0xA41689C35D790EB8ULL, 0x932E34C1CBFC386DULL, 0x46155AB16501796DULL, 0xF6EC20E34D335F43ULL, 
            0x47CD56ACC050DA3CULL, 0x967425DF6079376BULL, 0x4A1FD729F1749647ULL, 0x754127AD94FAD3F2ULL, 
            0x6F412FB0958284F9ULL, 0x570B3E2B7EE16C72ULL, 0x233BD9FEEBA1185AULL, 0xDBF9C66AB493369EULL, 
            0x3221AD5397EB1876ULL, 0x1E1B61B1ADCB1762ULL, 0x3FAF04591BBD1C18ULL, 0x3F613CD5C9966268ULL, 
            0xD5E293021670C509ULL, 0xC55219D132E044DCULL, 0x405B9130B1A54169ULL, 0x286BADFF9D8D82C0ULL, 
            0xA03CF6C52127AF30ULL, 0x5DE7E48809A5E20DULL, 0x027514978F4E041EULL, 0xAFD4AB9A2BD974D4ULL
        },
        {
            0xACBAF8372633AC56ULL, 0x8336A3E556FFF880ULL, 0x5FE25874C1470303ULL, 0xBC3B381705CBDE65ULL, 
            0x586A101D5AFDCE7BULL, 0xCCC18DBCCD537793ULL, 0x2C08E3B5CEB349FFULL, 0xAAA7F930CE56B59CULL, 
            0x463C1B3014D0E2BDULL, 0x4FAE3A2DE9D241BEULL, 0x383AC40FCD505FC6ULL, 0x0EED1663852474BBULL, 
            0xC149DCE62D625CEEULL, 0x0A6DAFD2C96ECE93ULL, 0xEC4D9661682EA1B1ULL, 0x759487A61FBB40ABULL, 
            0xDA873106358AF2B0ULL, 0x1726DD01020A94FFULL, 0xD62335995789AA50ULL, 0xDB955DD313FB1B2AULL, 
            0x1BCE01BC11B1697EULL, 0x9416D2D6D15AB5B5ULL, 0xB4FF2ED4B8B91C3BULL, 0xE40B029C958A2EA6ULL, 
            0x0D8EED6F03EDD97DULL, 0x8E33E99B13BF3E68ULL, 0x1B5340879BF7C379ULL, 0xAF5929F93FA86605ULL, 
            0x8549F8B6273270D5ULL, 0x277B50A5DB3F97CEULL, 0x2A9BD2E94AD74592ULL, 0xC195F2C000271D7CULL
        },
        {
            0x1178B2BCD3307ED5ULL, 0xABA7F7A50DFBDABFULL, 0x73B131A0AC856AE7ULL, 0x8D0D35E65EFE2CAFULL, 
            0x3EBCF8D0DC85CC15ULL, 0x7B599512E4A55111ULL, 0x5D63476543FC7082ULL, 0x2B528AC824210E52ULL, 
            0x47FA9FD271B24463ULL, 0xE3453982B049F09FULL, 0x64B8CF42E38325A3ULL, 0xA09D497331E36F83ULL, 
            0xB677D018A8C06C72ULL, 0x1775E435A89B51BAULL, 0x87F7F409A0DFAF5CULL, 0x0C389491FFDB5290ULL, 
            0xAD70025DB0391C81ULL, 0x5723F2D576B8D923ULL, 0x2C33B19065BB6586ULL, 0x0438FC0A778F845FULL, 
            0x75E19DCBF538CBD6ULL, 0x87FE04180BA9178FULL, 0x446445BB5348AFA1ULL, 0x2B7C0CEFDE83F1CEULL, 
            0xC3E2883562E4943DULL, 0xB296E2D58A250779ULL, 0x0BDA6C43E4BE6B84ULL, 0x81558D0E2F28870CULL, 
            0xCE18988735019C4EULL, 0x7483A40F96D3EC42ULL, 0x119EB9F3374A5D45ULL, 0x1B019F8C7807E331ULL
        },
        {
            0x499345853AD3197FULL, 0x767CD552AAADB9D1ULL, 0x00AF2EC40824FA04ULL, 0xEB38A6465C66776AULL, 
            0xCC5B25520157CE71ULL, 0x10D2C5899486D6D3ULL, 0x41839CCF48DF78BFULL, 0x5220B663D7E772AFULL, 
            0xB21E7CCC2628B4F9ULL, 0x0A1376C9389E8D43ULL, 0x430510CBBF57F1F8ULL, 0x22ED930B4513F4C0ULL, 
            0xD793249268193AD7ULL, 0x6DF4C8391172ED1CULL, 0x2A1ED413BACAA1DDULL, 0x2A1DFF9E4D5F29C3ULL, 
            0x7AFF3D5941B3AA5FULL, 0x6507E33F176AC763ULL, 0x18029857A662698DULL, 0xA4D5B2C5337E3370ULL, 
            0x43870AEEC9105C69ULL, 0x3079797B21E60E03ULL, 0xBC819088CEA95AD6ULL, 0x3E763135EAA5E8C4ULL, 
            0x6F3C92D6B103DA15ULL, 0xC6A32F8FBF45E4D5ULL, 0x214C1C5E7A4DF5C6ULL, 0x7D5C2D7D80E3855CULL, 
            0xBCE7B9BFE0C1D99AULL, 0xC31D2B1B5132CA12ULL, 0xF897597A98D85DC2ULL, 0x27E162BAA7174C90ULL
        },
        {
            0xA1A0909398AB3795ULL, 0x40570FA42D672FD5ULL, 0xC4978459B7449510ULL, 0x77DAAEB63247EF75ULL, 
            0xFB298B38C915F137ULL, 0xF7ADF8757374B3D2ULL, 0xD5255AE934A403D4ULL, 0x8DF346481F6C08DDULL, 
            0x73A27E254412F8F5ULL, 0x70800EACA2613AEEULL, 0x230F1CBE6EAB6C66ULL, 0x16B6C526BF089AF9ULL, 
            0xE8189743E4998C7FULL, 0xC2D7F3BCB0D7481AULL, 0x1A1B3EB7DBED9802ULL, 0x4F9B43689C12413BULL, 
            0xD57B17B9DC8AD465ULL, 0x5DE9044C5998F148ULL, 0xC325E3AA4153C9BFULL, 0x3BC55F0DD3E1A4DDULL, 
            0x8587538C214AF71EULL, 0x1E9C4ADEAA9751C0ULL, 0x6DE809EF0406C0EEULL, 0xEE8E31188AF9FCE0ULL, 
            0x1394CCF4264F175CULL, 0xD333403F3DF3746AULL, 0xC9BC88A40E9B07D9ULL, 0xE1F826F322D13C32ULL, 
            0xCD9BBF5AE14289C0ULL, 0x8EBC8E64D0EA7C9AULL, 0xCEC8710AE1CFA99AULL, 0x845074AF28199679ULL
        },
        {
            0xADB751D1F53E63B6ULL, 0xA0EE379420C80DE5ULL, 0xDE45DBCD3AB116EFULL, 0x1C9CD2F2E1CA8106ULL, 
            0xC520B8B9242F6B01ULL, 0x11483AA15BD2FBF7ULL, 0x058566097983F31CULL, 0xDF79873C82A493F4ULL, 
            0xF2A6F94C75DB1C89ULL, 0xB11AB8624FF44840ULL, 0xA350D7C6D43FC1CEULL, 0x448AFFCB95E48D10ULL, 
            0xFBEBC854405F2332ULL, 0x8D4393214CE96D70ULL, 0x8235CE29EE035C2FULL, 0xB01A9E155E7491BAULL, 
            0xAE9B5393B95FBA1BULL, 0x121B22A2AADD340FULL, 0xF57B49F55606FDB5ULL, 0x08592991C81AFD0EULL, 
            0xB8221ED9CE4BE866ULL, 0xC677428890515DE0ULL, 0x7F4A4CEC2C897B50ULL, 0x2597520BBD294DAFULL, 
            0x92B8B3A0B6B44739ULL, 0x52ACC480A099EECFULL, 0xD8387A949CA685E8ULL, 0x23F158D341231ED4ULL, 
            0x915F0CC0EA1A2C1DULL, 0x09BC559C03ED60C4ULL, 0xBFC56D9FCE3834A0ULL, 0x7BB35B7D0CFAFD87ULL
        }
    },
    {
        {
            0x74244D6703EB0AE9ULL, 0x82BA29DF2FAC2DBDULL, 0xB68A2397BFC2DBC3ULL, 0xA0F38E9AC116129AULL, 
            0x3BD09072EE5010B0ULL, 0x94BA447157985FDEULL, 0x7C5E40E9E1C745F0ULL, 0x151FE4D874C996A2ULL, 
            0x6122FD835A8A93ABULL, 0x9866D9F6B5545107ULL, 0xF054C9994C060E4FULL, 0x15FB20C9461F6CE5ULL, 
            0x4DA0E6DA5D2EEA9DULL, 0x397305E0A20D596EULL, 0x3715E9BC210ED985ULL, 0x31EF34B61E3A81FBULL, 
            0x3FE5FD747FB86175ULL, 0x5993849DD231D7B5ULL, 0xEEA419E024C9BE4DULL, 0x63F694C49B0C3F6EULL, 
            0xE78DCCA3470AFF21ULL, 0x1DD3F27EE7C7B9F6ULL, 0xBD7B0526233C400BULL, 0xD892D784F06AD3C7ULL, 
            0x3B54C0F0E6D60DE3ULL, 0x264465641F7F315FULL, 0x2346A18842FC418AULL, 0x7BB24F74FFB5671FULL, 
            0x5755B54359AF591CULL, 0x88B87BE6CE4CBF9EULL, 0xA4D71B86367CEE26ULL, 0xE2E5611D12C4BE78ULL
        },
        {
            0xABA46B0E3679A249ULL, 0x2FA2A763C2220A3DULL, 0xC1483D0912D7F9C3ULL, 0xCA427A869B358A81ULL, 
            0xE0609E518D755DE1ULL, 0x7BB7F0BF450C2804ULL, 0xB134B8F1E217BF6CULL, 0xBAC69432F629B607ULL, 
            0x15C6FBC110C07E50ULL, 0xF89ADF00FED03ACCULL, 0x1C34C23AC1DF57B8ULL, 0xB9ED757650A53ABFULL, 
            0x3828C438EE84123BULL, 0x9D11B19C4DA15C2FULL, 0x313E957DF361C4AFULL, 0x958E75F182963922ULL, 
            0x0268DDA298EB1A17ULL, 0xCFEDBD3108B58BEEULL, 0xECC1EAA406154A94ULL, 0xDFE56BD1F4088F88ULL, 
            0x86E5BEE8237DC308ULL, 0x5A7C6813715AE6C4ULL, 0xDABB0B690A007FFBULL, 0x031BDFF0758EF471ULL, 
            0xD00AF606CC48CEECULL, 0xD0E2FF02E100406DULL, 0xF875AC3AEA662BF8ULL, 0xAD66FD8F9136C639ULL, 
            0x0329CE500DD1B6CFULL, 0x8DE3D1542B333C95ULL, 0xD4CEF6787CC60B90ULL, 0x93A0BFC6011A6800ULL
        },
        {
            0xB1BAC201CAEFDAB5ULL, 0x7B07910FAA917241ULL, 0xB238C8509F8CD221ULL, 0x589BE727E45668B0ULL, 
            0x141C8D957288132AULL, 0x273F781CB7C0D400ULL, 0x5BC717FA145F7C3FULL, 0xB469F946C84FDB21ULL, 
            0x9801B696D5040776ULL, 0x4BF2FBCB443CFAF3ULL, 0x0E5315B39E51FDD0ULL, 0x3BAA2875C32BD906ULL, 
            0xA32A6A70B4984CCBULL, 0x5C618986BC57A15DULL, 0xE7127D6427663332ULL, 0x484B33BF8A127A0BULL, 
            0xC65007513291CD1FULL, 0x3A04DF014C56B18CULL, 0xBA0153546AA6BE47ULL, 0x4BA69425B72D293CULL, 
            0x5ADB53147D62500DULL, 0x13DE2DCE19E035D8ULL, 0x39D5C1E2682C5F6BULL, 0x6B2C6DD6702138FEULL, 
            0xC805D677A481436EULL, 0x3822D7F059E0B227ULL, 0x89C0AC3019F70721ULL, 0x54113E74599DCB09ULL, 
            0x089945A010CB3564ULL, 0x2199191ECCDBD533ULL, 0x75A5BDB02561A48AULL, 0xCEE2866C0E105CC1ULL
        },
        {
            0x598713FD07A0BF9AULL, 0x51989665CC8087D1ULL, 0x399C41B3ACB81C97ULL, 0x51711E385CE333E2ULL, 
            0x16194CA4338F5586ULL, 0x5BE3A8ACC2810A87ULL, 0x1368AFF922876966ULL, 0xCD5AE2D8134EBC63ULL, 
            0x4DC5E3A3DAA3D076ULL, 0x1000F631C9F62BD4ULL, 0x74E75A13818E8689ULL, 0xB5B977CAF6A4E6B3ULL, 
            0x5F72D9A22721C49BULL, 0x35D3390FA943CDFDULL, 0xC1AEAD1BBC5D354DULL, 0x29272AE1BCBB1801ULL, 
            0xAF7BE3E4CA481BCAULL, 0xC8317BB18FCC171FULL, 0x3E5DA26200F21D1CULL, 0x6D1DC66502A72AE4ULL, 
            0x1694712F23D34BD4ULL, 0x4EAEC7E5D646ED15ULL, 0x74D3ECDE07DAEED7ULL, 0x145007A2D2D5A702ULL, 
            0x15B49D5BDD24657DULL, 0x9A0F8E219E94C87CULL, 0x0FA49B716E6C6C15ULL, 0x2ED02C942D9BF5F7ULL, 
            0x3C0A3A8334378140ULL, 0x72C3C2FACA7295D7ULL, 0xDD221B4A38AC060BULL, 0x4A2800F27994B94DULL
        },
        {
            0x4E89D9B4E53CC479ULL, 0xA802CC01D1ABAC7EULL, 0x4E8BF7EF1F085363ULL, 0x96EB1FDCCE222241ULL, 
            0x44D82F37C442C498ULL, 0x1A19489B81504A73ULL, 0x1B932144E8794ED6ULL, 0xCA04BD6E858475D3ULL, 
            0xB575CFB309E66F9DULL, 0xF7049A6E0C92052DULL, 0xCE5CF36323E0D4D5ULL, 0x147C444B255906FFULL, 
            0x73F59A72984B48C8ULL, 0x93B3B9C235A0B648ULL, 0x73BAEBD8956052C2ULL, 0x51C9983568367669ULL, 
            0x431BB426891CFF04ULL, 0xBCE4BB1C8BC4BA37ULL, 0x67F4C8D33C72C42CULL, 0x7FF68E7B52714741ULL, 
            0xCF41D162B58FF5F2ULL, 0xE64A93EF019610D4ULL, 0xA1DD20287C843C86ULL, 0x3BD7BC93E5525690ULL, 
            0xA836C9CB7C2FE089ULL, 0xA94F18C0FEA1AF37ULL, 0x33B1EBCA52BB43B0ULL, 0x28E41B57F9920E7EULL, 
            0x64F730F0FC27A8CAULL, 0x043ACEEDACE8D7B7ULL, 0xC49C4227F941F4E5ULL, 0x7652298C860C6617ULL
        },
        {
            0xB3FEAE1E2669DED7ULL, 0x81F7C6139EF7F28EULL, 0xC8AC7E1694DF224AULL, 0x29B12FB6F481560AULL, 
            0x4C83F4B333626496ULL, 0x900DF46093216D03ULL, 0xF5FCBB28C20DE5FDULL, 0xE606A60669B68F38ULL, 
            0x840616FE5AE6C6EBULL, 0xC50E8ED1B5494548ULL, 0x4E3A9379CF44E0C1ULL, 0xD561DC948058BC7EULL, 
            0xF85054F8EFE8CC90ULL, 0x8CD6588AF180BF1AULL, 0xE322BC4F9B882F8BULL, 0x3602F6BC1AFC2310ULL, 
            0x8C7880C5DC78A985ULL, 0xE766540467BA0B79ULL, 0x427A10472A834B88ULL, 0x7D48C4C8F9885F4DULL, 
            0xC0D512265E4D0C87ULL, 0x1B7CC6D04AB926B8ULL, 0xCBFE87C214080E51ULL, 0x5124B4672E026BBEULL, 
            0x537944A4D1EF0C9CULL, 0xAECE27B9C94834C0ULL, 0xBD996379312E5996ULL, 0x4B4A1F03270BD550ULL, 
            0x7AE4BAA2B405D106ULL, 0xF3011B8D4A151FBEULL, 0x0085992F668D0A96ULL, 0x6CB8E929BD951C61ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseBConstants = {
    0x7FDADB98242C1CC3ULL,
    0x3DD5BBD9CBF37467ULL,
    0xA33B88D18B111B90ULL,
    0x7FDADB98242C1CC3ULL,
    0x3DD5BBD9CBF37467ULL,
    0xA33B88D18B111B90ULL,
    0xCE221DD787C5BE9BULL,
    0x762D77B4CC1DCCEAULL,
    0x17,
    0xF4,
    0x68,
    0x73,
    0x8D,
    0x99,
    0xB5,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseCSalts = {
    {
        {
            0x7DBDD93E626DAE18ULL, 0x97B936745C597EB2ULL, 0x8EC35744416475C1ULL, 0x13E7EA7C4E5577DEULL, 
            0x3B576D32065E1D62ULL, 0x6A6B891D096C026EULL, 0xEB08009F7AC09BC9ULL, 0x2D38C9E277B7C051ULL, 
            0xBA11749FA16D5FC8ULL, 0xB90951A460D64C15ULL, 0xF17C8E447BED0310ULL, 0xA74B278DFA7B2B09ULL, 
            0xECE7551890AB0017ULL, 0x11AA1681C0F2E156ULL, 0x2A8EAD6CE0A8827AULL, 0x368E8964F403146FULL, 
            0x9A6D4046DF413AF8ULL, 0x150D8C223121E17DULL, 0x8D64F51A92842F05ULL, 0xAA49637BC9CA6138ULL, 
            0x563B33D56BB321E2ULL, 0x76BC44CCEC42E087ULL, 0xDF5B065F1D127649ULL, 0x56AB7372B86A5FC9ULL, 
            0x4726BE4049CF768CULL, 0xC73949FDADF6301DULL, 0xBB5E00CA221D9827ULL, 0x8D55EA02BB2A7767ULL, 
            0xDD87AEEEF4B76E20ULL, 0x57753807696CFFA9ULL, 0xE5B422F742FE1B12ULL, 0x06E3947E6BF20814ULL
        },
        {
            0x0068345C13317FFBULL, 0x63CF92D40C2C34B9ULL, 0x849EA60522D75CE7ULL, 0xF68685DF34AC8991ULL, 
            0x184B683AC73F072DULL, 0x1C7C5406FF476E83ULL, 0x9A9D938DE05AED60ULL, 0x471BC4A3E5BB32FCULL, 
            0xFD13F4D012B19570ULL, 0xA2BC51D6A7564ED1ULL, 0x5646923FF1121756ULL, 0x294819EA35C10B74ULL, 
            0xE6336A668549AC52ULL, 0x36BBDBECB7F8CB4BULL, 0x05152C61A28092ECULL, 0x0D622FF6FC050535ULL, 
            0xF98D0C1C19A4D742ULL, 0xBDECA4FEDD7677E0ULL, 0xD6464C27A0D6CF2BULL, 0xD7C1B0E465EC8085ULL, 
            0x1D3655B1E930168BULL, 0x8E6623E2526C4D36ULL, 0xA09908E441F7FE23ULL, 0x85A0BBFBB800B954ULL, 
            0x3C301DC6F40FA3C1ULL, 0xA4539957F0989CBEULL, 0xF4E6105B8B2F5BE4ULL, 0x19B9C898FC38FA01ULL, 
            0xE06E1B5E4DF40BC0ULL, 0x6AEC75430A022B69ULL, 0x7FB69AB7E5C5AF41ULL, 0x53641DEC8C66E320ULL
        },
        {
            0xE1A1C4C82A46B5A7ULL, 0x5098538FE543D3EDULL, 0x755DE958FF592AEBULL, 0xAC38D7633B1C59B6ULL, 
            0x610F403E9316C12AULL, 0x2C5FFC611CE0BACEULL, 0xF382B4BF6DE74FD9ULL, 0x6A1F7456C62C81E5ULL, 
            0x8BAA120A0E764646ULL, 0x3F1570360AF6ED4AULL, 0x7ECA054EB471326EULL, 0xB0983C525D0E11B7ULL, 
            0x8F2228F9410DC47FULL, 0x7AB5C22A21CC5625ULL, 0x2F26917AFA7F63EBULL, 0xB608025587E8FBDCULL, 
            0xD4B9F731C235A089ULL, 0x02966D91F52E670FULL, 0xF1ED381A33D8DAA2ULL, 0x93997349CFD09E5BULL, 
            0xD592B1EE15AD14D7ULL, 0xFFC07F663C9134FCULL, 0xF231F7400C650FFFULL, 0xFD480F6939309F6AULL, 
            0xCF4449AADFE380ECULL, 0x4133CBCD6271478CULL, 0x08788706609ED2EFULL, 0x73D88FFD0B18E628ULL, 
            0x3EEBA9CDE7FF3190ULL, 0x1B8AFB3596759D37ULL, 0x3F71C7C16EC8819DULL, 0x479DC16EEBFB0ABBULL
        },
        {
            0x6468E12F6714829AULL, 0xA21E40F6E167BDA6ULL, 0x83F14AE20C160BB5ULL, 0x2155ADAA6D9E307FULL, 
            0x6F8D688F5E5CF518ULL, 0x8EA4B88B59686AB7ULL, 0x0486B7935767C8F4ULL, 0xBFC394180D33B063ULL, 
            0x8CBC6E60780E0598ULL, 0x53E9E4AE8044CC69ULL, 0x04E1460EE3E50000ULL, 0x1DC65F6B3D858F17ULL, 
            0xC81563DAAB56266BULL, 0x582E03F22823E2F1ULL, 0x1442868897D9B244ULL, 0xDD1C8BF3DF78C759ULL, 
            0x49040D5259CDBE1FULL, 0x1AC3A1CE77165CE9ULL, 0x2A4DC8018E8856E8ULL, 0x92043A5AFA215C90ULL, 
            0x632F8EA994DCEB2DULL, 0x8B12D6F1D91219CBULL, 0xD8457CC4C6433DD5ULL, 0x45CA8A95AF79974BULL, 
            0xD9ACCBB928FBDCDDULL, 0x98BAF73FAD956CF9ULL, 0x99BAC687081291F0ULL, 0x328E4D6FECE21409ULL, 
            0x1DC74EAD59B8CC6AULL, 0x987F25FE1B4B2C48ULL, 0x52C874FA0BEA1CACULL, 0x249FB2D12851C72BULL
        },
        {
            0x62AA3538F0C131BFULL, 0x6AD091B9833BB982ULL, 0x03DC8FB79C718ECAULL, 0x2E50F6309F8E1CA3ULL, 
            0xAAF7334751F36188ULL, 0x4D54E4E7222BCB73ULL, 0x32C88F3116C08303ULL, 0xE5587D97EA44E374ULL, 
            0x679A6E272E44D5AAULL, 0x04C7F24CCAABBEF0ULL, 0x6D4E852B294AD35EULL, 0xDAC0D61B0E3EF440ULL, 
            0x7437F09825D4C830ULL, 0x210CF5EC248DE4DAULL, 0x57A17AC8978C21D8ULL, 0x589B01208C70FB40ULL, 
            0x9BC9561429AB89C8ULL, 0x1596038D4B1C2741ULL, 0x306A0FD8552BCA64ULL, 0xEF860D4BE040F825ULL, 
            0x55BCACBC7293E58EULL, 0x1977B9729E193977ULL, 0x2EFD0CAEC5460062ULL, 0x4DF00B6CC14E52FBULL, 
            0xEFEA8CC5B1DBA326ULL, 0xED7423F2BBFDA105ULL, 0xAEF0BAA30AFB1A44ULL, 0x4C6E9E4568F2753AULL, 
            0x5A9C6D080D7A34A8ULL, 0x1F6FD13B7E7241EAULL, 0x4309C7E03DF61DEFULL, 0x6701E6A6E835717AULL
        },
        {
            0x6CE747BD0642B8E0ULL, 0xDF086DE5A58A7D81ULL, 0xD7B61B79785F2394ULL, 0x70A490EDB3A5C581ULL, 
            0xAB122526DAE68E34ULL, 0xF8301D87A5C83F30ULL, 0x06BC2981CAEAD694ULL, 0xEFD6D39D95A5F62DULL, 
            0x513EC7677481CD11ULL, 0x496A79FB43F665C2ULL, 0x7F9CB80A105B87B6ULL, 0x7B97ADD003F6722EULL, 
            0x78C12A8E03FBACADULL, 0x753A3E5DCFA63648ULL, 0x9CCF63A3ABCFA586ULL, 0x226F68568DB1D894ULL, 
            0x4176818126F1BF01ULL, 0xB377175D7C9E1959ULL, 0x9D8E0CC4A8EA6942ULL, 0x2F803B07B372E906ULL, 
            0xA331DA965BCDCD96ULL, 0xA84375B7EB882513ULL, 0xA0630C8AE3E10279ULL, 0xF5C043F9C9F18D33ULL, 
            0xF45A9DD4AAF0B695ULL, 0x9BFABF33B6A6071AULL, 0x24198558A2D5874EULL, 0x93BF3FAE646D0B6BULL, 
            0xF9CFCC973CA8A5E0ULL, 0xF9592AE658FDCCFEULL, 0x3090F88CA30622ECULL, 0xCE94FB7B64583107ULL
        }
    },
    {
        {
            0x49AA9B286E390147ULL, 0xD3C185FB193720E3ULL, 0x234BC857CEB3A9B2ULL, 0x1824968874A7DA69ULL, 
            0x5DD5088C691F30A2ULL, 0x18709898999F8689ULL, 0x4629EFEAFF022222ULL, 0x248F5400DD56D621ULL, 
            0xBE646632BCDEBFBFULL, 0xDD1BF3646A463BBDULL, 0xB694FC63147BA0B2ULL, 0xAABF6AC268D75BB1ULL, 
            0x8FEE17766A13426CULL, 0xCD1FEEB7FD40FBF6ULL, 0x28FFDB1436D87945ULL, 0x0325205D35A263FFULL, 
            0x378105A3D214A09EULL, 0xAFDB74D20880AE8EULL, 0x13DADC8D9D81340CULL, 0xD04987208C34B8ADULL, 
            0xCCE2354EFC17DC67ULL, 0x291F068D6430237EULL, 0x7EDD265442150AB3ULL, 0x39D61481BC57C8DEULL, 
            0xB0DE65C2616B7FBEULL, 0xDF562A9DDBEEF73DULL, 0xD6219A5FBC913361ULL, 0x38FA34901016D52CULL, 
            0xC4FACDB47192547BULL, 0xF8F9641F359AAAB5ULL, 0xDCF8C6E5DA616556ULL, 0xDD26197821DBA1DFULL
        },
        {
            0x50AD256A2E4D5C89ULL, 0x95AB111F09BD02E8ULL, 0x5552333731FC5227ULL, 0x5F117AB033D291D5ULL, 
            0x590EAFBED9DD5CC4ULL, 0xE36716921DBAFD3FULL, 0xFEBD249109CED013ULL, 0xAA66E96A0ED4A9B0ULL, 
            0x1E23620BFACDF87DULL, 0xE51A14550EF9BC18ULL, 0xC7803EE977FB2E33ULL, 0x0E8B421DA17BEA8DULL, 
            0x4602AE2447A9335DULL, 0xAF4B8ED9E00815EDULL, 0x1E06DFB1CD0245CBULL, 0x2DC89D4932E2F177ULL, 
            0xB7293554154EBF5DULL, 0x8D8BFDC3B88D7110ULL, 0x58856D5068B72A4CULL, 0x2D072799D58544CAULL, 
            0xDD08BAE9616446BFULL, 0xB8B494549002E2BAULL, 0x7CB37823ABFCD774ULL, 0x1F12254F721D6B4EULL, 
            0x0A44F48A4A748DB7ULL, 0x862B967BA6FA7CC9ULL, 0xAC728D8FC19C1B92ULL, 0x176193089281CE57ULL, 
            0x0E475A271A40D94FULL, 0x61DE9EACD5D11E60ULL, 0xB6E71B21DF14ED1DULL, 0xD74F9C5D3E4FA47BULL
        },
        {
            0x7009B1A4B556FFEEULL, 0xB7E44D33475AE6DAULL, 0x458480131BA10865ULL, 0xEAC8A6EFBFE6F8F4ULL, 
            0x80DD1E4ABA85B5F6ULL, 0x1FB57366D208D5CBULL, 0x0B1D2125D22E96CCULL, 0xBACA729346C7BA31ULL, 
            0x3374DA3C19BF7F56ULL, 0x02A3FABF36589D83ULL, 0x4439615BF23CC053ULL, 0x56F7F482ED2B11FAULL, 
            0xB4916946643380D9ULL, 0xFE73D5CA4EAF370AULL, 0x41327A9A86C1937BULL, 0x3370618B1E774692ULL, 
            0x2DFA5BE9550ABCE7ULL, 0xAFA74F7DB809B682ULL, 0x5E5E5E85B5E0C8E4ULL, 0x2E59FC57EC8393D9ULL, 
            0xE67B8473D9CE3DD2ULL, 0xD5A542E72BFEA947ULL, 0x642FE383D35E5349ULL, 0x53CD970F3818B5FAULL, 
            0x3C4C285D7E077B29ULL, 0x565CABB039A413BFULL, 0x92F57C73163E58BAULL, 0x07A031A6266FFD97ULL, 
            0x0FDA9805E3CBEA95ULL, 0xE2A2B2D0B171ABEBULL, 0xE026DE5E2F5AF4A5ULL, 0xA60C7F7910087577ULL
        },
        {
            0xF09D7BEF5E9C8445ULL, 0x49BC4BA5584EDEB2ULL, 0x4CCA9AA9DE6895DCULL, 0x9F1AAD1A501A514EULL, 
            0x0D8EF83275A198D0ULL, 0x6C735FD601517219ULL, 0x418ACCC948007C98ULL, 0x5674B4F1BECAB7CFULL, 
            0x6E4E9F521609593CULL, 0x137CF7E895D1F575ULL, 0x799816DE1704B2FDULL, 0x82F3144C1C75E220ULL, 
            0x265E582F0DE71FC1ULL, 0x37E72F93ADF94EAEULL, 0x0B520CA74E3DE07AULL, 0x3B3A4B48DFA3C3EBULL, 
            0x85AC04139BDA132AULL, 0xDCDA85EDB775AA13ULL, 0xFAEE010B05326691ULL, 0xE536C254C6A24A57ULL, 
            0x43A744762A158E9DULL, 0xACAE493F05AF176DULL, 0x29D090FD8FB45D87ULL, 0x257020BBB996C9B7ULL, 
            0x8758659406A65C82ULL, 0x1A93245D80C47453ULL, 0x29ED8E611D92FFACULL, 0xE02ED570C177BC38ULL, 
            0x78E60FD5707EDA5FULL, 0xC89ACF83DF59A9E1ULL, 0xA07E0240EA012749ULL, 0x349C998575B66FCCULL
        },
        {
            0x50AA74F329F615BFULL, 0x5BB6073C45363CC2ULL, 0x527A0A18E738FBF9ULL, 0x85267B193C073A92ULL, 
            0x71E629C57239BF3CULL, 0x937D36D209D20C0EULL, 0x0EA93C33840A7A08ULL, 0x16291938A9AB32A5ULL, 
            0x43FAA5A4750CB2D3ULL, 0x39B0C17E479D8D7AULL, 0x5F43AD6FC1296E3AULL, 0x8A32F367A29294A7ULL, 
            0x8D84D78D2E29814BULL, 0xB9106DA7E1A9F81FULL, 0x6FFFF4A6D5265006ULL, 0x26C8980296A37FD3ULL, 
            0x7967DC83D47EC86CULL, 0x1EBC5675BA574197ULL, 0x5D0E23DD42457F34ULL, 0x7C6594698312BA3CULL, 
            0xA35473601F376789ULL, 0x88B06F22CE32F46EULL, 0x5FE4F60E8144B971ULL, 0x60929022A73FB0D1ULL, 
            0x12BBBB79FAD96F2DULL, 0xA31E868702CAFB67ULL, 0xE1A873C5D4721F97ULL, 0x229C0DD51FAB7F4AULL, 
            0x2F028CF354C03D7EULL, 0xA740C7DE9D74E795ULL, 0xFF1D72247B0F4076ULL, 0xF29C07CBCEF21AE0ULL
        },
        {
            0x5F0836765092C9F8ULL, 0xDF8B9B7CEC3FE45BULL, 0x846C761C1426A829ULL, 0xEF3D8B520FBE99C8ULL, 
            0x1C329EC0E0092889ULL, 0xF132CD91B2CD1932ULL, 0x66141865BC68C097ULL, 0xC4DD8EA88D18E0C3ULL, 
            0x8D1660F7E32223E0ULL, 0xC6D9112B0765147CULL, 0xE7FF379947459215ULL, 0xC20DE4D761C42E1DULL, 
            0xBC275ACF1156E1F6ULL, 0x77188F63A1CD97DFULL, 0x761EA3450D43C619ULL, 0x55A0B7E77CA347B1ULL, 
            0xBB4DEE57094A2199ULL, 0x6E16D8A4E4E76679ULL, 0x1B58B0DFC2322D00ULL, 0xBBBED9AAB037C3D9ULL, 
            0xA521D5619D11C577ULL, 0x06668AD986B245F9ULL, 0x4821E1A226811D18ULL, 0xA8B6FD74C582240DULL, 
            0x99B6A1B2D7F08909ULL, 0x402E5110C684F116ULL, 0x9EC6017934473B44ULL, 0x3612C666C11B8518ULL, 
            0xBB046AC70D182F9FULL, 0xF0268CCAF027A7AFULL, 0xD7BB0B1CECB7AFBDULL, 0xF917F3D9BAAE01A3ULL
        }
    },
    {
        {
            0x68CF111AB587C516ULL, 0xD26BFCD87FA8540DULL, 0x31BE8F78F116EC3DULL, 0xBF28E07F3AD93E1FULL, 
            0x4B127B9576BEEFE0ULL, 0x872CEF27B27E12F8ULL, 0x91B8C3DCB7BB7180ULL, 0x0A2FD4C290E16772ULL, 
            0xCA02EB26FD22FC9EULL, 0xC1801506F5AFCEC8ULL, 0xA88DC351672FE19FULL, 0x4633963BC396C08EULL, 
            0xD089AA88161951C6ULL, 0x36217E2B603E572BULL, 0x566780B127CA76BFULL, 0x19563CD6E0E40871ULL, 
            0x9CA11700BD558D14ULL, 0x88233095F8D8AD2DULL, 0x941F68D0F2F95F86ULL, 0x2080846954F6523AULL, 
            0xEB0D5756AB63095EULL, 0xEDD17737F59AF31BULL, 0xC7ACA8A74A4D9914ULL, 0x1DB0BB4BFFC769C1ULL, 
            0x6D1F5E44722505E5ULL, 0x4985BC7A8E8F9A70ULL, 0xB605C2E8AE046069ULL, 0xDA8930F77C7ED11AULL, 
            0xF8C76105C79609E8ULL, 0x7247ED598099FF97ULL, 0x72B0D2F534B41456ULL, 0x7B87EC55EE4275D8ULL
        },
        {
            0x0CBB23A7B4628E25ULL, 0x2A37574ACBFCA14FULL, 0xC68DF3B281E4E6DDULL, 0xB5649AEE892FBF44ULL, 
            0xE3026994935CA6AAULL, 0x9AD329CC7F01D8BCULL, 0xF94A8F3FC0F840B1ULL, 0x3AD9EA67F388A5BDULL, 
            0x3D92BF6E0425DD08ULL, 0x8A4A279EB5B6BADBULL, 0x86D029632A01909EULL, 0x1EA558621FECFEF7ULL, 
            0x72D4EEB52387B70AULL, 0x154CE505C4800FA8ULL, 0xD935EA90587549DEULL, 0x47F63B45FF95CCE1ULL, 
            0x445FB2C5E63A95F7ULL, 0x214A2DCE1478ED97ULL, 0xCC6E594C614CDA04ULL, 0xBF68FD9DB6C4A4F1ULL, 
            0x6C4AFA4526AB6FB0ULL, 0x8F1DD228E40B8386ULL, 0x80F849CF81DA9A1DULL, 0xA3DDA081D64F1EE9ULL, 
            0xA7044E1DCFB3DB19ULL, 0xCC653FA58FC05ABCULL, 0xBB501CDC01B30420ULL, 0xF9191BD6980C164CULL, 
            0x32A87D8FF0EA4E85ULL, 0xE8E1EBCDBF4F11DDULL, 0x1E4FD58EFFCD0988ULL, 0xADA7879E52221451ULL
        },
        {
            0x61B21A5EFFEA98A6ULL, 0x35BCE6FA30F998B5ULL, 0xEBC3E22BAC756EC1ULL, 0xB35C50D464801D99ULL, 
            0xBBA0FFF89D9DC4A9ULL, 0xC305CAE81A9D94F0ULL, 0x8DF3AE3E1D9F976FULL, 0xCE7785A9A2D6C7C8ULL, 
            0x1C0002DDC0934F03ULL, 0x3C435FC1E6B70FB0ULL, 0x3B6CB056A095BF25ULL, 0x18CB136495949EECULL, 
            0xAC40D496F4485B47ULL, 0xC6774B5B36F6140EULL, 0xCEAF353120045E41ULL, 0x67D2D545801A2A64ULL, 
            0x688870A677A4B7EDULL, 0x294056B7DC19B2B0ULL, 0x880351E7F6285164ULL, 0x2E9B9B2DFE219239ULL, 
            0x06910B2CC3DDB497ULL, 0x360F74228A407805ULL, 0x587F89B0A1CCCB4CULL, 0xDE5C99EBCBECF374ULL, 
            0x3140DDEF04638E94ULL, 0x199DADE12E603808ULL, 0xC66E5BB5FEDBF869ULL, 0x8D34CBA498123D18ULL, 
            0x7803689FC221DF95ULL, 0x8B0BBA3864CD7A20ULL, 0xBF4406FC40533744ULL, 0xE968C2A1800766D4ULL
        },
        {
            0xBE14B6AC2DD41864ULL, 0x69BCCFC391EA7E99ULL, 0xCF2FA6952AFDCDFFULL, 0xD5BE8EBD455CD5F7ULL, 
            0xDCBEB23B5A6CC57BULL, 0xD27039510E325AE4ULL, 0xD6B06279DF946489ULL, 0x843FA6B4A4B37761ULL, 
            0xAE78FEA8025E1716ULL, 0xC7406307DB451273ULL, 0x5A7C4953098C14F1ULL, 0xAE40B2FB4F809F6BULL, 
            0xF83C8377CB0706B8ULL, 0x304FF51F0D5BB315ULL, 0xC9AA7CA0C9F1618CULL, 0x6029A4036B739BD5ULL, 
            0xB5F07FB0852A694EULL, 0x95EBB355D5A43C6BULL, 0x7CD86E81698586CBULL, 0x2B674A1FB48B8BEAULL, 
            0xA922A681B3E42AD7ULL, 0xBD49924E107F109CULL, 0xECD7222BF4F829E7ULL, 0x87A125CD20D9AD30ULL, 
            0x2F748B1921580E95ULL, 0x374B19FFAD090BE9ULL, 0xCE9B4BB56D9A68A9ULL, 0x7CFCC9F979157A47ULL, 
            0x9E3338A85BBAC760ULL, 0x42095E5B6FBA7F86ULL, 0x789ACD293A773530ULL, 0x4831582D15409969ULL
        },
        {
            0x7AC0AA4C30A17859ULL, 0xACB93E0D5CA74B61ULL, 0x242E3A78A116ECD3ULL, 0x81CC1C787DA9F2FEULL, 
            0x87B33DA5F397A1BCULL, 0xA857B483D12A366EULL, 0x94DC13CA33D78F71ULL, 0xECBA26444DFAEA1DULL, 
            0x33E895A2346193B2ULL, 0x6EE57CBEFFAFB5B7ULL, 0x46407FC77B62D69DULL, 0x5E15CE826CCE2999ULL, 
            0xE218F0E545B69BA5ULL, 0xAFCB31174A256C70ULL, 0x6D2AAC4A7D850298ULL, 0x799C91CC40192E60ULL, 
            0x6E1957BB76C0EA11ULL, 0x7EBE6259A581CE7BULL, 0x6A4336C59374D4FFULL, 0x015BEE951EA9B81AULL, 
            0xFCBC8A491F883067ULL, 0x252E342E7EEB4607ULL, 0xA54D8BF20369E651ULL, 0x6E42533394A8787BULL, 
            0xF1C2124B5549CBF4ULL, 0x1663C08E2FCA1B45ULL, 0x22EBD72F239ACBF5ULL, 0xA6AEEE4EBAB9E05CULL, 
            0x625510D2C67016F6ULL, 0xD93B1D0C48E8B7A2ULL, 0x626C75F41A42636DULL, 0xC6C0AD242AB649DAULL
        },
        {
            0x14B792F1E2961981ULL, 0xE0CBE1536360A84EULL, 0xA8978D39E3933DA3ULL, 0x102DA06E3C0DC2E1ULL, 
            0xB937D6C7AF7D6842ULL, 0xF339C30901696F06ULL, 0x8A68A507B92CE490ULL, 0x015594C0393B6D85ULL, 
            0xFDEF1FADCE34608AULL, 0xF5BAD923543B6B3CULL, 0x705982FF3A3CE0C3ULL, 0x21F3480B2ECD5A14ULL, 
            0x09207FDCA580338AULL, 0x9FCA978C18E1BD2DULL, 0xB22008BDBF399BDEULL, 0x24EF5ECB01A43AEBULL, 
            0xABEDA4B95131BD55ULL, 0x1C8B76B5E92A2505ULL, 0xC46CBBFD50B84482ULL, 0xEA280D82348FE9A7ULL, 
            0x7BD93BABBF8B14E5ULL, 0x4963FDE98EE5F1C2ULL, 0x4B37B4E3833B9148ULL, 0x8996FC36DD2199F3ULL, 
            0x4B19D8CF0B3852A7ULL, 0x7CD7FECAEC2884CAULL, 0xB821DBB4965F676CULL, 0x7C6170A464C69064ULL, 
            0x1B827FD79F832A94ULL, 0xCB5B510B598790FBULL, 0x08B7F49B5E354116ULL, 0xB733923DB1AD9430ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseCConstants = {
    0x1D1C2443983720C1ULL,
    0x48703B13309A8132ULL,
    0xFA83455C6580A42BULL,
    0x1D1C2443983720C1ULL,
    0x48703B13309A8132ULL,
    0xFA83455C6580A42BULL,
    0xBA6F3A1AAB5E4BC9ULL,
    0x1E5E9EC971E796B7ULL,
    0xE2,
    0x6C,
    0xA9,
    0x48,
    0xC1,
    0x7E,
    0x9B,
    0x1B
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseDSalts = {
    {
        {
            0x19542766CF2973D5ULL, 0x3DDA7E3A97300AA7ULL, 0xB397DFF746AE1009ULL, 0xC8F0D8AF3E00F3A5ULL, 
            0xBE0649EDA8AFC5ADULL, 0x8D774C663DB351E5ULL, 0xEC9ABE5DAE5DA9B1ULL, 0x6EE658284A701260ULL, 
            0x1BE20A90C2EB036EULL, 0xAE5B6AD691A1DE36ULL, 0xDFBB1218548F298BULL, 0x8E5AEC66EEEE74F1ULL, 
            0x53797EE394C70A0EULL, 0x437086583381AFFBULL, 0x962438D44DA1FA10ULL, 0x5A75E215416F2931ULL, 
            0xA9524096A70B8D08ULL, 0x388B42692A838BBAULL, 0xDCCADBEA2FC970DAULL, 0xAC9A0D5E3FC55AB8ULL, 
            0x1ED5797139BB5485ULL, 0xB012EA5D235DE594ULL, 0x3E819C6A038671DDULL, 0x7B4C62E9A060E8A9ULL, 
            0xB4B33464B7B9A5C0ULL, 0x274DCEDDB38A7CEDULL, 0x566C1ECCE3AAD66BULL, 0x1CA199B11749EF50ULL, 
            0xE7DEAA5686F2EED1ULL, 0x4124A1ADD69A16DEULL, 0xE3F6828897F73661ULL, 0xCC5CB383F6C4C89BULL
        },
        {
            0x3935C0FC8FB3CBD2ULL, 0x46A27414ECCA090AULL, 0xA84888C4DA14BF37ULL, 0x1377061EC980B7F9ULL, 
            0xBCEFB4D490A3E40FULL, 0x5223CA221835C4DBULL, 0x2FA0D33B43321232ULL, 0xBB667B7A1A6BEBE3ULL, 
            0xAF7552D70C038E4EULL, 0x75A00BD662DFFD63ULL, 0xD60E43544BA10BFCULL, 0xBB7D1742C194BEA2ULL, 
            0x168CA83A96D56FC6ULL, 0x528DDFE62104EBB6ULL, 0x086DB274D70B2858ULL, 0x5589F0187142B881ULL, 
            0x09BB844BAE508A9DULL, 0x246ADDA2B7FB8A32ULL, 0x52E8225EFAE3B403ULL, 0x384F29FD5B7F506BULL, 
            0xCE132B05E4267D1DULL, 0x23F7EEB42EAA4AD3ULL, 0x266A27DD69F38B92ULL, 0xBDC58F0F2D6D87FDULL, 
            0x504F1F6642B0CF01ULL, 0x1FF48DF1C94C39FCULL, 0xF92D7B73D7414369ULL, 0xC5059FB3F03E4E15ULL, 
            0x0877157D656E2C0FULL, 0x19C040D78A23885AULL, 0xF25A3476D5044805ULL, 0x825DD32DB17F1586ULL
        },
        {
            0xDE3DB3701A8FC034ULL, 0xF0AE672EB748544AULL, 0x5562522DC7236EF4ULL, 0x251BCF1008FCB834ULL, 
            0x51BC9C27E89DEC21ULL, 0x863EDEB4D62877A3ULL, 0xCDECACA28C2DE69EULL, 0x140C8E384DAF8B3AULL, 
            0x1BD9D5529D3FAE9CULL, 0x3C499E2688BDAB6EULL, 0x225D123F6CB31E5AULL, 0xBC1AC58C75E4063FULL, 
            0x1C737925098CF207ULL, 0x1907576BCB5A9644ULL, 0x2137461F4C83AAC8ULL, 0xAF9CF307D87F8E55ULL, 
            0xD89AB393203C5512ULL, 0xB592F1F4A903C5C6ULL, 0x23A1AEBB09366204ULL, 0x5A8E4DF6B04C6A2DULL, 
            0xAC8A77855B7B4DC6ULL, 0x7E064A63DE8E7A2FULL, 0x8F8CEE8EC38FE886ULL, 0x122C996F2540471DULL, 
            0xDE8367E12BACC98DULL, 0x01FBAB587D2EF997ULL, 0xC7B9D802DFAF0C13ULL, 0x94AD5E64B6D070BFULL, 
            0xE738477B893438AEULL, 0x1538DE64E9E62518ULL, 0xC32EC859AFA35AD0ULL, 0x683329E76755E41DULL
        },
        {
            0x0D429F1C94BE8375ULL, 0x8DA50E8367F342F0ULL, 0x24D86B829FD774B9ULL, 0x1A7CB8D4AA6926A5ULL, 
            0xD63B82C09BA6FCA6ULL, 0x93A2F0BBBFF0A97DULL, 0x098829F6475F9A94ULL, 0xB35B31E68392703FULL, 
            0x6E1237796D0AB425ULL, 0x79581D1780609654ULL, 0x0A5D01540235DB43ULL, 0xAFB6BD4A2A3C0A68ULL, 
            0xC4B95343065AFBCBULL, 0xF22CE712C58ED7B1ULL, 0xA61FE2898DCADACEULL, 0x78BC7D006DAE1058ULL, 
            0xB4E77328F111EBD2ULL, 0x41152908DBE43094ULL, 0xC333FE9BAC0A0FA2ULL, 0x4E359D6EC5CDCF7BULL, 
            0x6A22C71E87608044ULL, 0x1D0171437648ADEDULL, 0xBA9C8B87945BE364ULL, 0x626970790D3BA1F5ULL, 
            0xF9F2725CF58BD594ULL, 0x0C1CA9B88FF5437DULL, 0x688737EC2487F10FULL, 0xDBB9F60C27B3C641ULL, 
            0x4523E7598B7AFA58ULL, 0xC86F29AC07C32003ULL, 0x9AEC55B4DEEF7E22ULL, 0x48703618EDBCD79BULL
        },
        {
            0x8CBCA31C70618D14ULL, 0x6F20FD3E5C64D0A0ULL, 0x2D5F0D14B4B309A7ULL, 0x1845C0CACF1632B7ULL, 
            0x7134D5B28AF4D07AULL, 0x8752EEDFAB4C6EDFULL, 0x9CE17E620FD97599ULL, 0x6483CEF2BF6F37AFULL, 
            0xE7C10EB96F0406F7ULL, 0x34CD83C9367FBB1EULL, 0x68AFCB7235C0F558ULL, 0x2F3F2A6660582C84ULL, 
            0xF48D395A81E5D6B6ULL, 0x161964C1CE2F455DULL, 0xA11A07CCBB230851ULL, 0xB83E35BF585B13C6ULL, 
            0x37F6AB496D2D75F1ULL, 0xB47C1230349AE5E3ULL, 0xD0B263F2435017EDULL, 0xFA8396D71EB2CA7EULL, 
            0x0E8761D1E4FBAEC6ULL, 0x60DDBEA1F87071C7ULL, 0xEDC64B600A8CFB19ULL, 0x7B2FDE4115B689A4ULL, 
            0xA35134AFC7DBADDCULL, 0xD9B286993F2B714CULL, 0x73D8C726A8D8C896ULL, 0x32777E103D0D03DAULL, 
            0x17B6CA4AFDD589E6ULL, 0x225B74D06FA5B2EDULL, 0x68F081669F0A3A2AULL, 0x7D986F3665448B0EULL
        },
        {
            0x5FC49357AC8DD57FULL, 0xD418AD23261D2F58ULL, 0xE11850B91CC072F7ULL, 0x53D7C50B893ACF9FULL, 
            0x81DCF6BE8431B7B0ULL, 0xFE3F27D2E632A8B5ULL, 0x670AE7C34A6A0E89ULL, 0x5413A7CAB41B8E6EULL, 
            0xF727C91D30CDEA7BULL, 0x6360516812B3E3ACULL, 0x55B6911876F36625ULL, 0xAD176F20EDB0E29CULL, 
            0xDB6A67E13FDBF518ULL, 0x7AAD0F90C21376C4ULL, 0xDB6B79AED119E6FDULL, 0xDD1C9C8A78987A5FULL, 
            0x04B1E7CD550EACABULL, 0x62611E72ABB105F8ULL, 0x0F9FFC494ABBC5B2ULL, 0x5CBCBC001AA467E1ULL, 
            0xB55664876B8E3F2FULL, 0xCF8DE2776622A6AFULL, 0xD08B32BA6F455BF6ULL, 0x55634FCD20E99B56ULL, 
            0x4826FDF7AE9DD54AULL, 0x725131FD6ACEB0A7ULL, 0x9779B46AA31A65A4ULL, 0xC3F8377873BB9329ULL, 
            0x2CD69C1BFCEF4F59ULL, 0x8F1D23C8E7D0242BULL, 0x787E6E71E0588943ULL, 0xE7C1BDE36670830AULL
        }
    },
    {
        {
            0xD642637C5122E6EAULL, 0x5DF61BFD844F707CULL, 0x5DBEA81A37626729ULL, 0x43DC0048C097BB1BULL, 
            0x6DC903C92935FF19ULL, 0x9E491E25D97293ACULL, 0x2446D2FAF0C3A876ULL, 0x7B70BD438D1F079CULL, 
            0x96B21DC2A45B9515ULL, 0x3FC7B4E9C08E3F0DULL, 0x822169FB79672A0EULL, 0xE83162C01354825CULL, 
            0x9DF0D49CD383DA82ULL, 0x7A71CF6AEF9CA147ULL, 0xAF634243F17B23F5ULL, 0xB7003F2BC8E4F387ULL, 
            0x4D2E6BF63CE360DBULL, 0xA8F5F1ED33D3D6E3ULL, 0x98A3B4880A0C7CDBULL, 0x8597E97210695B1DULL, 
            0xEEDAE1D2E2DCC67CULL, 0xA9D24670AB15CF1EULL, 0xB16FBEC00BF9250BULL, 0xAD66326F72AE4CCAULL, 
            0x0B071015506ED809ULL, 0x98A1A1673E25695EULL, 0xE0EB5E0A666C90BBULL, 0x4811C18AB5D249F1ULL, 
            0x17C10641C1437A79ULL, 0x7B80875DFA6DE999ULL, 0xCD2952805FFC5425ULL, 0x0873C8D686606A2AULL
        },
        {
            0x2F4598E5D9D8464EULL, 0x03677A6395EB97E4ULL, 0x668E96EB9D2CD949ULL, 0x1315B07331CC53BDULL, 
            0x0452007A74EA82ECULL, 0x7EA91514A2B48664ULL, 0x5602887EEB11D9CBULL, 0x6648CD4A78B548A2ULL, 
            0xC1F558406F6F79E2ULL, 0x5FB604515BA923B5ULL, 0x12806D030E3FB86EULL, 0x3B67CBD61747F83FULL, 
            0xA58BA4D7AF0DEF57ULL, 0x9B5917EF1E0A4105ULL, 0xEB948C6D79389F14ULL, 0x15114A9B75B1A738ULL, 
            0xE65B6C3EF2BAD8C2ULL, 0x59D1EF5DD071CBBFULL, 0x2524EABBD9CC33ACULL, 0xE216D646D89800D0ULL, 
            0x0E3755A866168C88ULL, 0x49299E15F74A4555ULL, 0xDDA26BF4C8AA6395ULL, 0xB713644C0A8278EEULL, 
            0x9F373396684B471BULL, 0x0041A9767E0CDAD7ULL, 0x03439E4C0031165AULL, 0x5122D1DB8E4E379CULL, 
            0x152EE77298435A74ULL, 0xD8B2C125CEF0CF4EULL, 0x4F2FF6E41503450FULL, 0xF59882E7BF988DADULL
        },
        {
            0x56EF3FCE4F425655ULL, 0x41987CB5F5486411ULL, 0x85764FC529643D4AULL, 0x6227A0B7D5704DFCULL, 
            0x38564FDBD62D72E7ULL, 0xB87EE8EDA625CBEBULL, 0xC5C2E6AE40CC56B4ULL, 0xC5C66078029D7152ULL, 
            0x645866BF27BF7D5AULL, 0xAF957E216EBFA22DULL, 0x27489B3C214F053CULL, 0xF4CBE4E7B94A1E8FULL, 
            0x671300748445DBA0ULL, 0xA4415DC5616A8B08ULL, 0x50CA029D33A9761DULL, 0x7AF57B6CD3B05FE1ULL, 
            0xD897DFCCECEE09C7ULL, 0xE4C70B95F290E927ULL, 0x68B443902A55C69DULL, 0x8A44D75EE3B6B508ULL, 
            0x6A231600E6C59813ULL, 0x6DD351D5C5EAC892ULL, 0x156D6DEE9199D1E4ULL, 0x43A72047514705BCULL, 
            0x64DAD658A4ABB24AULL, 0x6DC88A120004C64EULL, 0xCB65896074108E07ULL, 0xE551696EA52B6BDFULL, 
            0xE7FBD94DA9CC1C2CULL, 0xD828AC6F80E518B6ULL, 0x3F3EFB32FBD9FC24ULL, 0x03861EE617B58716ULL
        },
        {
            0x30EF298C1774D8F4ULL, 0x6C2D3FD53B11FD0DULL, 0x848B4DD0C243BE4EULL, 0xDCAE690226BA3A05ULL, 
            0x9C6D00A343CA742FULL, 0x3F41D76294BAE2C5ULL, 0xF10F8803E2B3A034ULL, 0xCC85E05F675C6AA0ULL, 
            0x46F6767D383C7239ULL, 0xDFC1D0B0193AC694ULL, 0x94B95AD67A4EDB1BULL, 0x83A557F883793C8CULL, 
            0x22867DADA60230B4ULL, 0xBCCAFC7708790354ULL, 0xE8E4C33F25CBF3F2ULL, 0x89EF6BF500EF1335ULL, 
            0x6E15BAD821303452ULL, 0x18FD3277F969250FULL, 0xF3049C06E3558E27ULL, 0x8CE6E16A8462EAD1ULL, 
            0xEE73DC4FD69405DFULL, 0x0847968D6805F402ULL, 0x279923DB9C2A14B3ULL, 0x96E4996E3C6C20DBULL, 
            0x3286F111BC8DFC88ULL, 0xCF7DA22DE8FA9FA3ULL, 0x4C810F8705FCD424ULL, 0x6C0B6B17D01F4BA0ULL, 
            0xBBC456DEACA23926ULL, 0xE9497A43F41BE35BULL, 0x0F172CEEF4E29501ULL, 0x761F00E034BBF876ULL
        },
        {
            0x9AF940111013B3B9ULL, 0x672B6A774C228B86ULL, 0x48C6BEBE801EC09EULL, 0xA37DAE679819AC0CULL, 
            0xC8EC8646C2BA694BULL, 0x9A8214FAC21BFCAAULL, 0x15794A58FE4EE04EULL, 0x4DD714731A509B48ULL, 
            0x262AE7196D9EB01FULL, 0x11DFC35B015DBEECULL, 0x6B4A053F0DFDBE35ULL, 0xCFFB32FCD6EBEC67ULL, 
            0x87A30C276FFB0C16ULL, 0x5B142A350F42F425ULL, 0x66232017F6E9C294ULL, 0xA585BFBF4B159674ULL, 
            0x78798209411FF768ULL, 0x9599E369C6D41AA3ULL, 0x630860BEAAF2B3B2ULL, 0x08A7B8960E3B674FULL, 
            0x3490C85800A14D96ULL, 0xC161626A1F3D7329ULL, 0xF5378F6FC0230685ULL, 0x81BBC416963262ACULL, 
            0xEA2508A0A0DE0A9EULL, 0x04A35464EE617D39ULL, 0x9E1A6F6B76E188B6ULL, 0x5B4CD5C4807B54E8ULL, 
            0x4D5AADA9FA45065CULL, 0x6646AFEA3DA61BEEULL, 0x6799FDB46D38ADB5ULL, 0x9F3A845DCFC7CBCCULL
        },
        {
            0x9DF19BD8DB03AB8AULL, 0x54CA7384BDE87E62ULL, 0x85EB96167DF7AA1DULL, 0x9B56169C9E8F849DULL, 
            0x5F32FE6A20007FAAULL, 0x7CBDA1D3ECC33F63ULL, 0xA6FC663CBAC0A1A3ULL, 0x0E9E083D11050ABBULL, 
            0x5F5648150C10D28EULL, 0x9D0E731426BD3CFCULL, 0x514C437A9E3A5C67ULL, 0x886D0B6F6D86FE67ULL, 
            0x82752CA7E66BD081ULL, 0xB30D46D3CC48F14EULL, 0xE3CA512F223BF26DULL, 0x0694ED4FB136E3F8ULL, 
            0xB4C08FCB35A27F31ULL, 0x7D419E5B768C81B3ULL, 0x5F0271AFAAD31836ULL, 0x5DDD22C326A60B67ULL, 
            0x80DB50FD17D4C5E1ULL, 0x9F9280CDFA17BF87ULL, 0xBAF060ABC036559BULL, 0xE7F5FD669CC7D6A2ULL, 
            0x44DDFDB2D15BCCEAULL, 0xD2671575A4610A60ULL, 0x513A7681FB4BEDEEULL, 0xE59E68AF5E31633DULL, 
            0x36AA1CAC997D4E95ULL, 0x31305E16C0AA760CULL, 0xF761A65FA5785058ULL, 0xF0D199A7CCF975F1ULL
        }
    },
    {
        {
            0xC15AA40B0CD92935ULL, 0x949B65D648CBF644ULL, 0x54930D9A205F2480ULL, 0xD526F91F1B9F3120ULL, 
            0x7823D577AF464AC0ULL, 0xD7B5F84187A9B67BULL, 0xEE4061F72B9F53C1ULL, 0xB9EE12040165DA75ULL, 
            0x9DAF82E14B67DC5EULL, 0x69222E8700DDB6AFULL, 0x803DF0469C1BC77DULL, 0x640F5AC7B10A9900ULL, 
            0x0358CB67EAF759F3ULL, 0x5493E6775C8831ABULL, 0x53CC72C02D800E31ULL, 0xF56822C42E291D9FULL, 
            0xFA5ECE2F06BFCE0FULL, 0xD4D2698CA8844046ULL, 0x296F77A2FBCF759CULL, 0x85380316FA75A746ULL, 
            0x456DE84FAB38BFE4ULL, 0x6501E205710E4991ULL, 0x6CDF5CF6433137D7ULL, 0x96829B36123A4B6BULL, 
            0xBA8BE79412E82DB6ULL, 0x0194F421BEEB5AA2ULL, 0x4164390412B30891ULL, 0x5861999D9064739BULL, 
            0x4FD3D06E09897CBFULL, 0xA634E5DE429E9C81ULL, 0xFF6F30D66887B42DULL, 0x7F1FFF44E7690CB5ULL
        },
        {
            0x6674098A3C9A014DULL, 0xE71DF0C59BB9C96AULL, 0xD72B24277B12C770ULL, 0x09DBDC52D73B3B2BULL, 
            0x7C0C0E227B8C5560ULL, 0x64C45BFB8F54CB31ULL, 0x46F56C0170E1D181ULL, 0x1FE599A09A01BBB8ULL, 
            0xF8DBE7DA24EE118BULL, 0x961AB8CA7ED413A1ULL, 0x6F4FC3121322C4F0ULL, 0x84D45EB92F431104ULL, 
            0xF23EC01F8871E05AULL, 0x1EC232FFD2511A52ULL, 0x88FC45AC69D4737FULL, 0x9E8CC58DA0F04572ULL, 
            0xAD1018ADE95C13C6ULL, 0xFF681E52A82763A4ULL, 0xEE8A133543FC56B8ULL, 0x55B1A5F75DD23F9EULL, 
            0x6E7D004764650C1BULL, 0x60BE9F8BAB1B066DULL, 0xF42630111DCA5746ULL, 0x5244C839A621EF20ULL, 
            0x4DB66DBCF0D8AEFCULL, 0x5F679F876A398262ULL, 0x4F181647C4FB65B0ULL, 0xC3CE7359ACEFFDA5ULL, 
            0x026BE25E22F10D55ULL, 0xC35EB9581762C77CULL, 0xEB529F5C7CDC7A13ULL, 0xFD011FA3FD3B75FEULL
        },
        {
            0xC0F1A3EDDFA400BEULL, 0xAC666860C12807ABULL, 0x0B507EF7B335A217ULL, 0x149795E80B7B6E4AULL, 
            0xFD0E5FB1566CA04BULL, 0x2D69886315D42927ULL, 0x8C2AE3E7C11FF495ULL, 0xF69821CE255813B0ULL, 
            0x35D4F43A93047A40ULL, 0xEBB527BFAA1178E2ULL, 0x042A5ECBAEAF5401ULL, 0x63A52BEB1A901829ULL, 
            0x9753478DE827BFF2ULL, 0xC14B2AC365AF241BULL, 0xB9AAAF20997FF163ULL, 0x8A1F384BA6AD4EB4ULL, 
            0x2586C042A914A099ULL, 0xC7D9289BC86E9464ULL, 0x9A10B2045C7FB7C7ULL, 0x1FCCE4DF6CBCD654ULL, 
            0x17DDFA83CF24A8E7ULL, 0x568912595CCF977FULL, 0x11CCDF07972CCA79ULL, 0x3B00E9544636BA62ULL, 
            0x6DA1C65BD9E92388ULL, 0x0B8C99742DEB3090ULL, 0x768A79A853A769ACULL, 0x653E1D86CF138CF4ULL, 
            0x8F20F83B22375A8BULL, 0x83304C9648706BB0ULL, 0x932D1F38C4702790ULL, 0xC06C0C0469F21FA6ULL
        },
        {
            0x50A4BE061EB13FCBULL, 0x9AD190192ACEE525ULL, 0xAC402600D03BF7E7ULL, 0x4BB8522149C2C220ULL, 
            0x013FF9F242B1C857ULL, 0xD0182A493D3EF4AEULL, 0x42A4464CDEF1C5DAULL, 0x8EEABC8C18ABAB6EULL, 
            0xE9D79E1F2C7256F1ULL, 0x1BC123DF228A8DF4ULL, 0x25FCFDE641318470ULL, 0xD82C30EDB469BCD4ULL, 
            0xE20B2FC17E16D4D8ULL, 0x02E5A58FFD2F5944ULL, 0x9D0A39C8B5C60C66ULL, 0xDCAE7E9E5B85C74AULL, 
            0xDF3C310F48A22913ULL, 0xD02FE742EB149048ULL, 0x7A651EC483CAD02EULL, 0xD60EA34F5BE7DB36ULL, 
            0x014E91ECCD7FCDE0ULL, 0x1A6A5C4533BACA5BULL, 0x1A54C3C61FC12463ULL, 0x6F2BD17BD3DBA45FULL, 
            0x736032DF5B2D7ECBULL, 0x4AB16B1AD7D7D21FULL, 0xCB38DCAE205825F0ULL, 0x3EBA669D631297E3ULL, 
            0x5C08853CB25DC900ULL, 0x74687439EBE3F0C3ULL, 0x1DE3C10A3C1DDD6EULL, 0x7CB1D35872BF45C4ULL
        },
        {
            0x1BD3AAE67075E71FULL, 0xC663F8F4312F854CULL, 0xFDB7EB37029755AAULL, 0xCD7AB1D171B33D7DULL, 
            0xC5F16D84F1142DD8ULL, 0xECBE35856ADF713CULL, 0x7AE2D11E26CC83E4ULL, 0xE0D7F6D1B29381B7ULL, 
            0x08BCCC4A3633A04BULL, 0x6D084364814AAC9FULL, 0x7C54F1611F61BE6AULL, 0xF2AB8786F43EBDA7ULL, 
            0x7D24553ADE571AAFULL, 0x9D931C0560405810ULL, 0x91946E91D72A1020ULL, 0x41EA47959C8B89BCULL, 
            0x375D0A5473F4F7DCULL, 0x226C6FE3AC47149CULL, 0x2C40AFF6D973E3ABULL, 0xC6891F4865E5A4B6ULL, 
            0xEA89B04C1D26FB62ULL, 0xF7B115E7087BD8FFULL, 0x23B2B51CD0851C6FULL, 0xF0F440AB1DC8F917ULL, 
            0xDF110E53D2F0A000ULL, 0x8889791603FCE414ULL, 0xB83EDC61518E9F40ULL, 0x31F9906F4149FC72ULL, 
            0x4756B82846E1E201ULL, 0x120168D0F6EC9EAEULL, 0xDD56DDE0C716C051ULL, 0x9F43A614219ECF01ULL
        },
        {
            0x03195A605BF9B4BAULL, 0xC8E6272B10E19876ULL, 0xEE6125D856AEC981ULL, 0xAF483A6317D33C96ULL, 
            0xBAD272A0D8070A84ULL, 0x6C846D93E02506FEULL, 0x5B777A1159AA2129ULL, 0x79841D4DA5D8B74BULL, 
            0x6B2B504D8DAFF81BULL, 0xA4A87BEF365E59E3ULL, 0xB8AE2F985C2F2801ULL, 0x99E8D5D9C8397616ULL, 
            0xA3796F6D8586F3D1ULL, 0x1819C0FA0D73CA5EULL, 0xBFF1F9C2553016C0ULL, 0xF16CF522D4722EDEULL, 
            0x843813AD6297B69CULL, 0xB7AE0DDA334271DCULL, 0xC3459547BFDAF556ULL, 0xA13743F6BC1C7F9BULL, 
            0x5A88FFA1744E9491ULL, 0xB9DDC08B01BB1D47ULL, 0x2DB04408EF28CC72ULL, 0x689F474CF4314193ULL, 
            0x510665DAD9EBE4AFULL, 0xC4CD1E1E374582E8ULL, 0x5F899A31E2E98E3FULL, 0x807C08CBB2F9AE20ULL, 
            0xEB11DDA4872D653AULL, 0x6A8116DE23AE52DDULL, 0xBE1417AFA72CB500ULL, 0x48E0AF6B727520AAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseDConstants = {
    0x3911D3A37DF23CBFULL,
    0xAADAAEF6328B595BULL,
    0x6BB1BBD5C23E9520ULL,
    0x3911D3A37DF23CBFULL,
    0xAADAAEF6328B595BULL,
    0x6BB1BBD5C23E9520ULL,
    0x82A2CE0F7666145FULL,
    0x22C7E682A261CBCBULL,
    0x08,
    0x92,
    0x1C,
    0x7F,
    0x45,
    0x59,
    0xA2,
    0x3E
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseESalts = {
    {
        {
            0xDA453569A3FAB3DEULL, 0x02068084C13AAF73ULL, 0x35A0C9E3F2BF7C03ULL, 0x1BA4F4CE4E4BD05EULL, 
            0x69A401F1F9FD97A7ULL, 0xC396F56E705D5CB5ULL, 0xD3E7C052B24B7F84ULL, 0xA50623C6D99D4859ULL, 
            0xBF9919E471264C13ULL, 0x375FEB070AFE81B8ULL, 0xCFB9AFC1E1E3ADD8ULL, 0xF14CCCEAF717AFEDULL, 
            0x6C99D936255E50B8ULL, 0xA0E3A1A223D9B69DULL, 0xDA1195526088DC27ULL, 0xE4208C67F902245CULL, 
            0xAA434C7BF5D76995ULL, 0x04372716C48AE421ULL, 0x13711B8A45B2E8CFULL, 0x66D75999BD12E738ULL, 
            0x0B4403DD4CEE6022ULL, 0x97AF6BE3378F4B10ULL, 0xC06DDBE198E83242ULL, 0x71C301591C305996ULL, 
            0x0A9B75F268E7D615ULL, 0xA821B14BED08F0A8ULL, 0x3671CA87C7189A64ULL, 0x77B55F4D6183134FULL, 
            0xEA1C6B8DEE17DDB6ULL, 0xD2181F415F5B4630ULL, 0x63491A8BA078F0B8ULL, 0xB0AEFD57C06EA231ULL
        },
        {
            0x4D5681B0F41264EEULL, 0xA004957B9295EFCAULL, 0x67DE674317193202ULL, 0xD8B566530D47CF58ULL, 
            0xAEBE25881A745DFAULL, 0xC1881D094E6BA5B3ULL, 0xC4C55F1FE4715032ULL, 0x125762377D3B8643ULL, 
            0x195A00B55417E38AULL, 0x42EE4E9A07D2BEF3ULL, 0x5A1624FAB5F838CBULL, 0x7BC6DFD83AAA5142ULL, 
            0xD7C09C44DBD8DBAAULL, 0xD0D63227EB0C8C1AULL, 0x0E96ECF75313E60DULL, 0x049C47150BD38E9FULL, 
            0xC350705E2B80CF6DULL, 0x2245707D1027FBE6ULL, 0x3DABA36576B66AB3ULL, 0x91D988F2FAEAE57EULL, 
            0x0E1DA9B16FD1E09BULL, 0xE05F7A8961DA3483ULL, 0x6C12701BABCAC3CDULL, 0xF9255E372FA03C6FULL, 
            0x3D6D3360C2CAA66AULL, 0xF7FF20EECCB31A04ULL, 0x72C1CA964B322D62ULL, 0xE6E15E945011F550ULL, 
            0x44B27590316D9B23ULL, 0xBD3EC859F8F0ADF0ULL, 0x5EA16A796E060EAFULL, 0x1DA8D967D5D7A8E2ULL
        },
        {
            0x05BC9458513BF0DEULL, 0x4D444A2FA55ED0C5ULL, 0x65286A6B76E58DAEULL, 0x4D85259C633ECB32ULL, 
            0x9DFCC6CE3E64794CULL, 0x4182F76FB0147245ULL, 0xE9F4F9427C9D2001ULL, 0x1F9BA9527046F3CEULL, 
            0x68633F44C2F80FBBULL, 0xB671DB961EA19DFAULL, 0x0C6918F1EEFCCE8EULL, 0x1CFBBF445B653CB3ULL, 
            0x44CA045CA8958245ULL, 0x50ABF0FFB06995FEULL, 0x59742AA80812BE4FULL, 0x4BB50AB1F1AD40FEULL, 
            0xBAB892195B7D56DFULL, 0x20AAFDC2CDAD9745ULL, 0x226E3491F1D408C9ULL, 0xBABF265001D2AA46ULL, 
            0x8CDF171082D19A34ULL, 0x90E57625AAD4F21AULL, 0x7D1CE553C41D40C8ULL, 0x3485FDE1300484A9ULL, 
            0xF421648D8094747DULL, 0xE45CD4FE43CAE02EULL, 0x6AF15FE1F9DD8161ULL, 0x244588373D7CF84DULL, 
            0x62A91E61A98E6F78ULL, 0xABB304DBA64F986BULL, 0x50A390B69B0DD5E6ULL, 0xDF06902D4DE0C5D1ULL
        },
        {
            0x2106471ED282CD06ULL, 0x93092CDEFE3039C8ULL, 0xC883DB7EE9B954B2ULL, 0x63D90076437A525AULL, 
            0x39F75701B9F5D2A9ULL, 0x1F56B915AC47BC6EULL, 0x1112BB0ADC72B9A6ULL, 0xC9D65C6C919A73F6ULL, 
            0xF96095F9D8EDFC44ULL, 0xB6189FA956282E49ULL, 0xDD8971641F8EC54AULL, 0x5EB36FB0BDF34266ULL, 
            0xF10306BB8B9285BCULL, 0xE2B6F5E057EF8B58ULL, 0x760A1DE2C5BE0EE8ULL, 0x909EF069FA8EC0B5ULL, 
            0x617CC151120B37FFULL, 0x0B1CAAEFC76849DEULL, 0x84AC6A3566432264ULL, 0xA4972551ED8A2E08ULL, 
            0xAE81661517DD204FULL, 0x561EE44F697906B0ULL, 0x5C539E714BC55ED5ULL, 0x19D218F216BED50BULL, 
            0x54717E04AB9AF1BAULL, 0x1CF648B3FCBB51E6ULL, 0xA46FAA01D24B21D7ULL, 0x3008DCB1D61DB683ULL, 
            0xF70CE7FCA14A3D2CULL, 0x4B7B138777730AC3ULL, 0xF51CF63E8DFD4E09ULL, 0xF75967BDD884279CULL
        },
        {
            0x1071FA84DE74809AULL, 0x9CD24ADF04A5F263ULL, 0xD181720FE3332858ULL, 0x96DC550A14640F0AULL, 
            0x71FAD273F6813334ULL, 0x479C0F69CC8757C5ULL, 0x51BED2178DD1B24FULL, 0xB3A4AB9403E16139ULL, 
            0xA797DB8C58808BC6ULL, 0xAB71B32974E804EFULL, 0xA253F171E1CD9A4EULL, 0xB00AAD0947A9F748ULL, 
            0x6BE7F6E614281A91ULL, 0x584F2139DD974AF4ULL, 0xA0428906B5B49C14ULL, 0xB30B255A22AA5D42ULL, 
            0xE65EB16A3420DECBULL, 0xAB88E4685B3FBAB4ULL, 0x9AF40CD1AFE02938ULL, 0x1DB9F8B12991A97EULL, 
            0xFC1CBF08CD92DD32ULL, 0x34042F0AAC00B84CULL, 0x1A69A373F67117EBULL, 0x4111C8ACBAF61BB1ULL, 
            0x112BB4EBA0CF19DFULL, 0xB56F0A6A373CA4A7ULL, 0x617A64488B4623C1ULL, 0xD28D8A9745679DD4ULL, 
            0xB9EEA66290CB1357ULL, 0x1C02EC7BB51E2781ULL, 0x576240D4652B6355ULL, 0x1061520839D33874ULL
        },
        {
            0x692D48D8EE43929CULL, 0xEFE50EC7A0D26BA2ULL, 0xCEF45DD59EEA220BULL, 0x0B2430F20902B4B3ULL, 
            0x79248483AB1EA105ULL, 0x169C9F221546D266ULL, 0xBF2D90D750672B51ULL, 0x81F10A029A6C8B56ULL, 
            0xFAE01F0437B19252ULL, 0x83741185F58144DFULL, 0x2B8A9830459C5CCAULL, 0x4CF9281FABC16DB7ULL, 
            0x2A190D7B5C0D610EULL, 0x6382C8235DB31F15ULL, 0x800034E3866B3425ULL, 0xB8921736DC7DFA44ULL, 
            0xBF3D681932F048EDULL, 0x6B3C74DADF3DD51AULL, 0xF3B2523B28168B27ULL, 0xD024B8A799524412ULL, 
            0xB0103C479B230F90ULL, 0x593903C2A4E5AB55ULL, 0x7359E63218C3CC8FULL, 0x4C84068D677CD2AFULL, 
            0xAF4990656CBE00A8ULL, 0x98B79B6EB4BBFD6EULL, 0xE5D9C004D0D00611ULL, 0x937FC69BD30E037CULL, 
            0xDDDFB46CC3C3620CULL, 0x3D38321680ED50A5ULL, 0x64C5D2AB6223FEADULL, 0xE25D87DB681F936CULL
        }
    },
    {
        {
            0x75464D2EE6B7FC12ULL, 0x686D8431E4A08EFCULL, 0xF8882C07048B9877ULL, 0x5F4BEB68E1D82D91ULL, 
            0x37E0DFFA995C639FULL, 0xBBB6DD4862E4F57EULL, 0xF013CDB7A0BEB0D6ULL, 0x6BCDF0418B51162CULL, 
            0x06D7CAC78DE3D0EDULL, 0x5915EB655A186C14ULL, 0x81FF4CDA04BC37DEULL, 0x960F2C62DE597CAAULL, 
            0x2408F349E80827F5ULL, 0xAFDCF3740289DD04ULL, 0x4641C7D7FC19ADBEULL, 0xB166CCD301992DB7ULL, 
            0xDD501A305662DACDULL, 0x88FFBC975540495FULL, 0xF4A29184A5F2EC13ULL, 0xB94457503FD1D0F5ULL, 
            0x65F44DB161461906ULL, 0xF077140C96A38508ULL, 0xDF2327AB7A867266ULL, 0x6F0BCFA5B9A67D53ULL, 
            0x73CE75BEDAD6DABEULL, 0x38BF58DCEF1175F5ULL, 0xEFA023FD3BBA9864ULL, 0xB8CD3F4E966F29C2ULL, 
            0xD817B9006416F650ULL, 0x54E5291947DD593BULL, 0x8CF9D79E8CE6C61BULL, 0x99A4178D89FC5986ULL
        },
        {
            0x6563D90B2CA81750ULL, 0x8C299AF2BDADFD91ULL, 0xCAE61595D7EB057DULL, 0xBF727FF44E75CD4BULL, 
            0x26C3F32FAA18A0A4ULL, 0x5C51F403B7C4E093ULL, 0xB62A83F328E97D27ULL, 0x0D55B1134F44FC59ULL, 
            0xEDD12E0227B09F61ULL, 0x484898F7B8C2345DULL, 0xF3830399E75DF60FULL, 0xFD0A11CF21FF98ABULL, 
            0xB6699CA4D78A771FULL, 0xE5BE40444A291E08ULL, 0xA1D8D063AFB24268ULL, 0x11B5AA385FE0E64DULL, 
            0x9E5635F6372FFAFAULL, 0x3EDA4F81EF6A0591ULL, 0x1753E037CADA115BULL, 0x1C2C6EA3E88FBEC2ULL, 
            0xE9420364D9159543ULL, 0x978A23136A8A3C0AULL, 0x9588960021DBEDA6ULL, 0x8B83CC6C40EC955AULL, 
            0xC0213FC15A4054C6ULL, 0xF21497CF62307364ULL, 0x32F98B15E06518D3ULL, 0x41A55CE79F90B0AEULL, 
            0x99695ABD600EDEC0ULL, 0xDB775A80A014722BULL, 0xCA3E44F620140EBEULL, 0xD6FB3581BBA4BA6AULL
        },
        {
            0xA6B708A535C02C12ULL, 0x853F0A340F8E7FCEULL, 0x7C51D521B9FB459BULL, 0x9B71374027F8629BULL, 
            0xD129F037CD068020ULL, 0x5B6EF294B9192315ULL, 0xE83432BD70910EA8ULL, 0x1F3DE8EB95B29B67ULL, 
            0xA71D34BF310F97CBULL, 0x0D2CF0B685E0EE85ULL, 0x7B8889645F27A20EULL, 0xE0C25B4231506DACULL, 
            0xB67418F92F505292ULL, 0xDFE19E0B9E8E0698ULL, 0xE255E090241AC64DULL, 0xA16E71B68F5F7373ULL, 
            0x4F629479108EA12CULL, 0x76477A50BF59CD61ULL, 0x01A629FEA18990A0ULL, 0xB489CB207D197042ULL, 
            0x6EC0D71846754898ULL, 0xCFCD43BD78327E01ULL, 0x97A57E2BBC19F0CAULL, 0xD83CB0ACFCA905A5ULL, 
            0x7AD559C993462C57ULL, 0xD0C52B1040E9F634ULL, 0xADE85FA262C6624DULL, 0x4C9E2F42594D0C81ULL, 
            0x4FD57564B81191AFULL, 0x42F7C0BDDFCE46B2ULL, 0xAE2B63F1D699E179ULL, 0xAC0210AD586A7CBDULL
        },
        {
            0xD716C0AB4F51107FULL, 0xC0363975D88422C2ULL, 0x27E4229F593E3A88ULL, 0x8D2E922AC756BB54ULL, 
            0x4589C66257994BFBULL, 0x28C951519D6E571BULL, 0x8FE649DA3C102D24ULL, 0x173A98F45FE11673ULL, 
            0xED6B01C97CA12D30ULL, 0xD876B61B4273A8A0ULL, 0x9DBC97390330154AULL, 0x6069C55C24394A8EULL, 
            0xC32893ECDD78575FULL, 0x9B18117A2C76EEAAULL, 0x06D1FF25793A8CFDULL, 0x907774AE501D2406ULL, 
            0x9598CBC246A0C9B3ULL, 0xAE7EBA967C764B2FULL, 0x2D98EAFE6F4C95ABULL, 0x33AC1B7CA98DECB5ULL, 
            0xA288B084F4220180ULL, 0x08B710C91F29C9FEULL, 0xB409A7FCF8CF7BD2ULL, 0x52504B581DB9DECBULL, 
            0x194BEBF806B56AD6ULL, 0xB78444987733C622ULL, 0xDD342C3D7D1D5001ULL, 0xFABBE25309237896ULL, 
            0x077DA6F3DD8D9DBEULL, 0xC77CAE306C470D40ULL, 0x45106FE3E0BA959CULL, 0x6C32738F50F4BA26ULL
        },
        {
            0x9E87DB77C98F915BULL, 0xA451D26C6649CFF3ULL, 0x654115E47E6C507CULL, 0xD2EDBCA864FE6BAAULL, 
            0x4F87FF2DA77BE8C6ULL, 0xBD73AD9987DC8CB3ULL, 0xDE7473E69B74ED65ULL, 0x48BAA2E60A010015ULL, 
            0x6FD14A45C200DB1DULL, 0x98559898182E3F9BULL, 0xAF8584C769ED6D64ULL, 0x5EEE55E2965244F5ULL, 
            0x424DEC4F80C3471DULL, 0xA60BF99A6F2DE9DEULL, 0x28ED57A10731B31CULL, 0x3615E73451ED91E1ULL, 
            0x1746C9942BE78B4DULL, 0xB413AF633D0D14B2ULL, 0xDD5022FE4A362A88ULL, 0x015F248617FCA792ULL, 
            0x0CDD02EB1278D753ULL, 0xB53D3F455A0EDAAFULL, 0x412D165C1A4B6AF8ULL, 0xBCFA2DBF625FE8B0ULL, 
            0x869F35A527A5C2E7ULL, 0x13A6788127D34CC4ULL, 0x7E3115C0D4C2183DULL, 0x24E527B74893E5B6ULL, 
            0xFA4FF8543EF1BDDCULL, 0xF619AE653B8046C2ULL, 0xF368A01BF4A31716ULL, 0x24D55807A27A087EULL
        },
        {
            0xB7D14E7D18A6A2D7ULL, 0x3A1F6FC60CD5BC9CULL, 0xAAE3DADC8F7BA4B8ULL, 0x81D296A9E22AEB17ULL, 
            0xD70272A2D475A71DULL, 0xB72625636B675C56ULL, 0x334C1D2D0DA8C496ULL, 0x5B473FD0521024A9ULL, 
            0x438E34B8BFA2AA2FULL, 0xE7D7E26322568572ULL, 0xDE5D90F7716074B2ULL, 0x64CADF8C19DE1DD1ULL, 
            0xC487256EFF2A0101ULL, 0x0B524F2010D4E5A5ULL, 0xADE53D8BC3DD8A31ULL, 0xA1CF9230A2A9ABEAULL, 
            0xE3935F3BB95F8580ULL, 0xB8BDBC1651B1DC79ULL, 0xF15C5683AB407713ULL, 0x9E6386B365221AD6ULL, 
            0xB9D81E523C0E00C7ULL, 0x5E1764397241BCA8ULL, 0x9312C12EA5877869ULL, 0x860C10E530682646ULL, 
            0xD2636959C5339823ULL, 0xF364DCF1CB5290A4ULL, 0xE9985BFC5FD7C5C0ULL, 0xADFDCF01CCB7A21EULL, 
            0xB0134173A93A1A92ULL, 0xCC08FE55551F700AULL, 0x03CCB5E1110A44BAULL, 0x546A248EF8969E60ULL
        }
    },
    {
        {
            0xB7D51CF1E324F6DFULL, 0x3148A68C284E51A4ULL, 0x46D682728FDA1484ULL, 0xE46A78BBC510BA72ULL, 
            0xDC9817DB97A78A73ULL, 0x02933DFC6FADF9E8ULL, 0xC353A403693988AAULL, 0x6C9F39040EC1DC9BULL, 
            0x2A540B41041135E0ULL, 0x3BDDDE1BAF4DACD2ULL, 0xAA9678721E9C54EDULL, 0xAE576ECD23BDD4CCULL, 
            0x6E0D102A4E2AFDA0ULL, 0x6A5660DF40D31B93ULL, 0x1EDA8DA4B3603C81ULL, 0x8D601A4D0B9F3B92ULL, 
            0x381AFCA717D472CBULL, 0xE2629268D0AAC34DULL, 0x68D71EC5DC87CDE4ULL, 0x48C98CCDA67809C8ULL, 
            0x82FC5CED1C5A48FEULL, 0x8842E673B18706DAULL, 0x1E1A306818F7A336ULL, 0xC6C98DB209C8E56CULL, 
            0x6109B437D45BF000ULL, 0x36892ADFEEBC0B34ULL, 0xAB3598ED1C398708ULL, 0xE2F06A2B76EDC138ULL, 
            0xF5B8EA63EAC2FB5AULL, 0x0CA3F1EDE28690F6ULL, 0xB5B891EEF01B84D8ULL, 0xD56EFB3D87F43982ULL
        },
        {
            0x53FF7C06232E94E9ULL, 0x25AC8E5BDAE20B9DULL, 0x6D02DCA1B15CBB07ULL, 0x8C1FCB8FACFC5082ULL, 
            0xCDA1E06C12DFC569ULL, 0x4B109A6BF8507C5CULL, 0xF6352B6F9AD776CFULL, 0x4380B9D4EA41EDB5ULL, 
            0x59D10986FCE56736ULL, 0x2BBE304509318BFBULL, 0xFF670299005DDE67ULL, 0xDFE3DB4619C3B915ULL, 
            0xC7264530C0FC3976ULL, 0x038A33F988275B72ULL, 0x255450C8F6F6851AULL, 0x75CC8C0101B7D3DEULL, 
            0xC8FEBB2A50F00077ULL, 0x07C28CE53019F718ULL, 0x4668130148912EB3ULL, 0xFD9B0B9A9D00EF93ULL, 
            0xA4929DB481B1F216ULL, 0x4618446FEA996527ULL, 0xDAC85DA007A55A53ULL, 0x045BE22F817921F6ULL, 
            0xB0006D3329EC51D9ULL, 0x93F7B6DB3FB25EDEULL, 0x8A522DAC1ED8331DULL, 0x007CF1C640E0BC7BULL, 
            0x76E4512FC1EBA858ULL, 0x898F45499860D97AULL, 0xCA6C37FD21AF3D8FULL, 0x071C731DD65A2D7FULL
        },
        {
            0x26147DBA44F0AB0CULL, 0xE84C6BD3ACCF024CULL, 0x837EFFD00F2D43F4ULL, 0x41DD13AE5A2CCA14ULL, 
            0xBB86B17FF63377E4ULL, 0x8D731082CD1FE5EAULL, 0x7BD9DF36C030E597ULL, 0x17E43A4AE20CA9B1ULL, 
            0x5FBC912ADCB99414ULL, 0xA44052CE165482A9ULL, 0x8F250497860AA706ULL, 0x3F3BA23B9B13F6E1ULL, 
            0x47059431C0D196C3ULL, 0x6398852A7643E09AULL, 0x99EE5D67E73C31C8ULL, 0xE8E80339ED38DC80ULL, 
            0x8E8EB54550A88F5BULL, 0xF2F47669A1DA485CULL, 0xB68F8EA80A5E51C9ULL, 0x11B87EE8DBB8D4F8ULL, 
            0x0CE2D353C92855E2ULL, 0xAD43A3022A3F7670ULL, 0x66DB32C7AB770326ULL, 0xC223A512ED3B1DE7ULL, 
            0x514FA1CA88677D2CULL, 0x614C2686CDC2074AULL, 0x2C3E0A1A289B422FULL, 0x75748FECF78DCB75ULL, 
            0x025D737234FDD950ULL, 0xB007B792D75D89A7ULL, 0x0D2F59ABFD363A99ULL, 0x58A7EF55CAA3353FULL
        },
        {
            0x080A152335B925B3ULL, 0x722EB5EAFA133AB1ULL, 0xC76C39FC21EB2E59ULL, 0xA0F7845E39ACFF12ULL, 
            0x92561A337BB5DAD4ULL, 0x997E6663F992E796ULL, 0xD0F2D912F2F08257ULL, 0x0C058C75412309FBULL, 
            0xA6B5443D29E80A2DULL, 0x38FA015EEE8C5377ULL, 0x653B9974F3FC1F0DULL, 0x48854D8FB0383580ULL, 
            0x25D78C29A196B4C0ULL, 0xC072D837E13C2003ULL, 0x196EE8266871E517ULL, 0xE231A011B75F7CBAULL, 
            0x6937A2FC2876E77EULL, 0x5533B7255BAC0FE2ULL, 0x1FC56D3E9BE3761AULL, 0xCC4AB8D33B2D3B24ULL, 
            0x9527B4B0BBF63010ULL, 0x743390AC9ADECA17ULL, 0x609B5B1D6DD6BC47ULL, 0xF65E30381CCA09DCULL, 
            0x10CC6163C4487B87ULL, 0xC8C17E1A71D897BAULL, 0x9A1DB900B98F45B9ULL, 0x3858CFB6F51BC5A3ULL, 
            0xF3D5E847E7374B1DULL, 0xA9580F0B1432AC0BULL, 0x08FE5B601778A65BULL, 0x257207D48492394BULL
        },
        {
            0xF97979B067D5A472ULL, 0xF65A71401CF671ADULL, 0x97C5E2CBE5690B18ULL, 0x66B65792FD1D8B82ULL, 
            0x9DDAC8D196A5F849ULL, 0xB0010FD768BBA7ABULL, 0x7859B8ACA71AD86DULL, 0x786D74964DAC20B5ULL, 
            0xEE80D027BBCD03BBULL, 0xA95AC090423BC8C4ULL, 0xACB3B18363285122ULL, 0x4D475CF2ABF5BFDFULL, 
            0xB15FF0E2D6A67FB8ULL, 0x1FBE60636FD3A620ULL, 0x01AD094A78C5A542ULL, 0xF1BFB77B8EED7E06ULL, 
            0xF62C015FCDF0E832ULL, 0xB6E7AC42D3BDC60EULL, 0x77690E8C205F44BAULL, 0x2C14B24912F2CA89ULL, 
            0xC9749FF777C97D85ULL, 0x327C0272851BEA58ULL, 0x72C5A0D0B9E4FAFFULL, 0xBA49E6626B9AF0E5ULL, 
            0x916A888EC9549DB3ULL, 0x42CADEC4EE4299B8ULL, 0xE25EF1511D27F3FFULL, 0xC875960136CD1C73ULL, 
            0x115104CD6E02BBA0ULL, 0x999774A6B40871A3ULL, 0xE4224EE5ED18B42FULL, 0xFEF8122C310A6DABULL
        },
        {
            0xAB01A7C4A44275BAULL, 0x93FF3050BF166DDEULL, 0xC41C42759FCA733EULL, 0x25E9E794B7B2772EULL, 
            0xCFF81C236D251A10ULL, 0xD4678E0B7134B07AULL, 0xC33E581E2A63FB26ULL, 0x2B742976BD023471ULL, 
            0xE77C47A13B65F090ULL, 0xF3E52863F239FA5AULL, 0x32F138339A259127ULL, 0x0693D61136878298ULL, 
            0x11B85A2AC59601C7ULL, 0xAE53F77663C723C1ULL, 0xCFE9325F23137539ULL, 0xC317D4CA40069A30ULL, 
            0x7C3E2DE3C5DA44CCULL, 0x6D628D129B1F0191ULL, 0xCB375DC9E339DA61ULL, 0xA30DC094032E122CULL, 
            0x57DA956D59F25C02ULL, 0xA12612BFB87B558EULL, 0x21060E42CE0893CBULL, 0x46CA6C18E9E54E15ULL, 
            0xFC9DD3142FC881EDULL, 0xCE69B7D73D9B303DULL, 0x703B9149E6444BCEULL, 0x815172816A6D998EULL, 
            0x87B063A8A7111C1BULL, 0x483569D3F825120DULL, 0x91AC75DB0C435161ULL, 0xE3FC02FC31927AB7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseEConstants = {
    0x2E91397AFEE5A7B3ULL,
    0x28EE659F609D576BULL,
    0x12F6277B32724167ULL,
    0x2E91397AFEE5A7B3ULL,
    0x28EE659F609D576BULL,
    0x12F6277B32724167ULL,
    0xBE057B476ADBAF7FULL,
    0xAF3B451B8B47BC0CULL,
    0xF7,
    0x83,
    0x2C,
    0x0C,
    0xE7,
    0x07,
    0xE1,
    0x08
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseFSalts = {
    {
        {
            0xE379556D2B8F1551ULL, 0xD71364E2E4273276ULL, 0x057533C4BDCB8C6BULL, 0x94F60D35BCFCA71FULL, 
            0x5EF0EB39F1EA431FULL, 0xA662485C4F5D302CULL, 0x2A3D67B78959D1E3ULL, 0x69BCAE9B93B2E835ULL, 
            0x100860F38F366B04ULL, 0xDABE2D18807BC250ULL, 0xD1375C2D3F3C64DBULL, 0xD2D31FF995DA16DFULL, 
            0xF1F9AD27DA94A4D6ULL, 0xFCF4B1E026733E7FULL, 0x423B16C3CDDD78DCULL, 0xACBE45ECEE6527C4ULL, 
            0xDBFE0248B815F2A4ULL, 0x834A3D3E4BD2C92BULL, 0xEE758E001CBBD443ULL, 0xE7D223EEBAF466D7ULL, 
            0xCFEC1BD74BC5B420ULL, 0xAAFB29300C28301FULL, 0x277C5D68298D954AULL, 0xA6BF10F342582E7CULL, 
            0xB2928A6243DE5D63ULL, 0x96E4E21B12980F56ULL, 0x8D3C18EAF340AE6FULL, 0x7F73E4C0C127E74BULL, 
            0x43467868D603A71BULL, 0x6FA9B5B9E3D331D5ULL, 0xD448D44663E5377DULL, 0x9365C685A852D074ULL
        },
        {
            0x765E4A5FAD3894C6ULL, 0x805B1255003D9FBDULL, 0x3944BC154AD7C9C9ULL, 0xAA4F302F8D919D64ULL, 
            0x1B54571AA6D4CA17ULL, 0xCD4B6D64B625CBC8ULL, 0x5C0AD3E1BA283D83ULL, 0x76BEABCF381FF64FULL, 
            0xA6E2097FAC804D7AULL, 0xA08722B7437AB457ULL, 0x36E51695A3C24E16ULL, 0x8639436F60E13863ULL, 
            0x421FC3AE704A921DULL, 0x75F52F5843B79AE7ULL, 0xDB7F5E8A1F0C4592ULL, 0x654ABD411DAED335ULL, 
            0x60444D36F655271BULL, 0x8DAF6831D4EE4852ULL, 0x314C757DB6DC8030ULL, 0x3BF83BEA6366A201ULL, 
            0xFF5B021FDD774C40ULL, 0x7F6E0C6F0DF776D0ULL, 0x91E6AC42082883B9ULL, 0xA41169935F525F31ULL, 
            0xBB5B9E60F8273730ULL, 0x8A472E5C4F8E3010ULL, 0x3691FBC690F3743AULL, 0x397C2D5134EEE64BULL, 
            0x775C6301C6849B69ULL, 0x195C6976F4168454ULL, 0x8C7D9C0FA01CCA1AULL, 0xB85054D4BC6D1D6DULL
        },
        {
            0x38844A6C6E601B0BULL, 0xDFE7791CD5EEF783ULL, 0x914B53448608B548ULL, 0x1E3ECF99B5550BD8ULL, 
            0xD7E3EF41ED21AE4FULL, 0xB1C6FB4B7C039073ULL, 0xC82ECAA7C90E0D4CULL, 0x562D9FABB81BAAAEULL, 
            0x375C191C926BCB34ULL, 0xD0EB75E0E3B6E772ULL, 0x22D620E460232BCDULL, 0x254668A38EFCE5C6ULL, 
            0xF0BEB857AC751D0AULL, 0x41DADF34E319B28EULL, 0xA1C10DC10B0EE14FULL, 0xC771598F722A1C00ULL, 
            0x9B2DADDD5BC2802FULL, 0x0C669DCC5935F59AULL, 0x3AAEEDFB6825989BULL, 0xFAD9253523486086ULL, 
            0x70C36A4C4EBDCFD4ULL, 0xAAB2BDB9504F4A5DULL, 0x450B5A781B1B4772ULL, 0xB1ADBD104D50FFE3ULL, 
            0x5A5BB3D60831C7E6ULL, 0xE6E41FB68E344219ULL, 0x91B8A921DDF179EFULL, 0x8232EC04B7CC24E3ULL, 
            0x176800E5F5A973A7ULL, 0xE139287BB21F78FFULL, 0x7F4FAD79A5786F37ULL, 0xDE7CC838AB45F68FULL
        },
        {
            0xCEB5B47E64CDEF3DULL, 0x94DA9659BD477FFCULL, 0xCD057BEEFA5ADD9EULL, 0xF84B4EA730410257ULL, 
            0x7C7CFEA8D26E7C20ULL, 0x0472A9638FB98A44ULL, 0x7FC78D25CA2CBBEAULL, 0xD355E31C639644D6ULL, 
            0x5C35C1D05C7ED22EULL, 0x7936A881EA9CC130ULL, 0x839A2C1679CA5FA3ULL, 0xD2D18D4815D3B1BEULL, 
            0xDA2F5AA26DDAE073ULL, 0xA7E3B75806E5AF70ULL, 0x954E872E5793EFE0ULL, 0x79A9A2B49FDB1E17ULL, 
            0xABA896C917C3A3B1ULL, 0x40EA112C0F200B59ULL, 0x236BEB3541C81BC1ULL, 0x10A3623A0018AABBULL, 
            0x1A7A21A6A0584116ULL, 0x9EE6AD1EAD549962ULL, 0xC342837E27A80B07ULL, 0x05BD53ED1653C597ULL, 
            0x3E0FDCF4654E424CULL, 0x53E0E2C011789D2DULL, 0xD02C75AA017215D6ULL, 0x36A8C9B5349B48C7ULL, 
            0x336CA89CE1EFEF4AULL, 0x205289B771777508ULL, 0x9259B674EA4B2F6DULL, 0x96266BEE772D50E4ULL
        },
        {
            0x0010E11F8C7743E6ULL, 0x847B6C21D48A399BULL, 0xA56765AA68925C45ULL, 0xECB8113D889B5EAEULL, 
            0x7CCBD10D1A43059EULL, 0x5201B78322A5F526ULL, 0x4230F32D93A0C581ULL, 0x830B38115FB5DFA6ULL, 
            0x04FA1783F1EC23DAULL, 0x77A750D1FA4BDD89ULL, 0xDEC44E959269C863ULL, 0x0725923B28BDB0FBULL, 
            0xF263391A1D209837ULL, 0xBC500A56212A9E0CULL, 0xD34D7F936C83BE8EULL, 0x6A747BA8C246E4CDULL, 
            0x58DAE56FC8972EF5ULL, 0xCF0C59D231F2E874ULL, 0xF320046D76B17747ULL, 0xB12BDEF9810AB4EBULL, 
            0x876774334CBB0E4BULL, 0x330491CC6D6356B8ULL, 0x1FDCB4C489CA6566ULL, 0x9C16550A18A88ADFULL, 
            0xD94B14378C33C7FBULL, 0x4B877247D0B7AF31ULL, 0x73D733D6ADB92122ULL, 0x3226AA6CA2A4CA86ULL, 
            0x8CBCCDC05C8BD6C6ULL, 0x07A35C01AA43A28AULL, 0x356C1A0354741BB6ULL, 0xEC4D41C7DBCB70BBULL
        },
        {
            0xEEA7648C42781B67ULL, 0x5B31DD7E9A0653C5ULL, 0x9AE1DD57E00A0899ULL, 0x167EDFB9D5043D94ULL, 
            0xFBF1C390F52F4483ULL, 0x0DEEFB8DC44FF819ULL, 0x4093A2DD59170267ULL, 0x387E03AE128C9F2FULL, 
            0xE98AD4C9C1A248F3ULL, 0xB8EE3AA625379E55ULL, 0x2680F552F5F0A855ULL, 0xBAAC7E895FDD6B91ULL, 
            0x813546CD7F6C5C40ULL, 0x0644F1B451276BFCULL, 0x6A91A2C1EED88C8CULL, 0xCEFE91138BB11925ULL, 
            0x7606D7B2778B2D43ULL, 0x6523D1840F4D4F27ULL, 0x5F70C728CCCFC1B7ULL, 0x0DEDC3E676AC8A07ULL, 
            0xC9CBF5F52F2EB346ULL, 0x125A3CD25BB8CE84ULL, 0xA5B77DFD53A23D2CULL, 0xC260FF28A3C947BBULL, 
            0x9AB991E9D79188D8ULL, 0x979A3DB39472D576ULL, 0x00D6A85FD1423A1DULL, 0xED97018225095919ULL, 
            0x50C1F7EA6497DE60ULL, 0x00CBA9D721158894ULL, 0x09C3D0C84D8677E9ULL, 0xD52929EB98C7E49DULL
        }
    },
    {
        {
            0xA9D454C6ED9242BDULL, 0x2DBEBF007B685EFCULL, 0xFD0E209644999C0DULL, 0xD99CFFB3CA6CB346ULL, 
            0x1A70F4B349E18E97ULL, 0x2396FE488531E49DULL, 0xF70CFDACF0C8C90AULL, 0xA6541D6C486644B2ULL, 
            0x4E1C9A8E6E3ED8AEULL, 0x757E5B1BBFFE509FULL, 0xCE83EF0AFA0CDB11ULL, 0x4DCE58E5E952C87FULL, 
            0x0D948C19B580BA3DULL, 0xACA6866651635766ULL, 0x72E8EC547519F334ULL, 0x40631C78DDE25E89ULL, 
            0xA7490AA7D895F4FCULL, 0xD4A0C0F2DAA1DA25ULL, 0x458A08F2D785087EULL, 0xD04671BF64D2F523ULL, 
            0xAA422BDEC784FB5FULL, 0x734C18B3593D1A56ULL, 0xABDC4D7F5C3E7FBDULL, 0x1D066A0045F9AB03ULL, 
            0x10F4A600BCA91296ULL, 0xBDF2332A791768C9ULL, 0x234740B20E18BDEBULL, 0xD4CCE2ADE982F164ULL, 
            0xB4528C83CCE1C9DCULL, 0x966F82D37C431268ULL, 0x13A17599DF7AEF20ULL, 0x15E55D4CE8A4ABB1ULL
        },
        {
            0x2FEDCEEAE12A61F2ULL, 0x5E00515FAEE6E65EULL, 0x6D567EEC79CDA53AULL, 0x5ECBE99850304653ULL, 
            0x4246EA1096009581ULL, 0x1BBB50471F879A58ULL, 0xF00FD9D02BDE2033ULL, 0x7CF8AFFCDED8C499ULL, 
            0xCE572F633E1570E9ULL, 0x54381C6B9C2ED6B5ULL, 0xA1388A415424D0DDULL, 0xF14AF8E34984F0FCULL, 
            0x2403CACA0DE106CCULL, 0xB42F791B8FCC1311ULL, 0x21751C5CC5E1D314ULL, 0xBF686B3E7AB65C5DULL, 
            0x37D6FEA0F81353BEULL, 0x980EA780B85888BEULL, 0xC5B7582C19925CB0ULL, 0x58A0F82E85E897CDULL, 
            0x6A80714BEE096A15ULL, 0x1C9A02368CE677E1ULL, 0xC7B7AD4EC499EDDDULL, 0xD546DCFF07DB864EULL, 
            0x3E251EA5F3E47055ULL, 0x57155BCE39AFF903ULL, 0x613585E8E787B9ACULL, 0x94670BE926B800A6ULL, 
            0xB00CB1F176B32BA7ULL, 0x01FD7A2FBF3A10D5ULL, 0xB579548A872E953BULL, 0x857F2576E85D549FULL
        },
        {
            0x99DB95010FF6D1E0ULL, 0xC4EA9903236649C1ULL, 0xC5F056A4E51079D8ULL, 0x04B6CA1AA80A508BULL, 
            0x08F857A8EEA669F1ULL, 0xB510D5CCB40E450BULL, 0x01C0C1C6ABDD8A20ULL, 0x3F1022133B70DA2BULL, 
            0x327F835FBE1D125CULL, 0xA64CF5D342998C96ULL, 0xAA753BF4E5E1F1FCULL, 0xEC708F1D3AAF0352ULL, 
            0xEF0A8A5E702BE644ULL, 0x5134E906F67AED40ULL, 0xAA1F9BEB8F2D77D9ULL, 0xF7107F70135800A5ULL, 
            0x695CAF0D2992A847ULL, 0x0A57FFACBEB4EBB2ULL, 0xA56C5C7D1616471AULL, 0x11EA562A1CA0697DULL, 
            0x60C2A65436D9A60BULL, 0x3CD9F9007CF0F486ULL, 0xD8027FB0D899D5AFULL, 0x7618E44BD6B71F40ULL, 
            0xEF6374130AA03409ULL, 0x8D9168336971A187ULL, 0xE804C4A3156D1671ULL, 0xFD14DDD341EEDECEULL, 
            0x49738D3159BA03AFULL, 0x3BC1780F77DDED46ULL, 0xBB58FBFE6D9012C8ULL, 0x9DB0B4C01255164CULL
        },
        {
            0x060CC9E48DDECF64ULL, 0x7BC78267A3C0D806ULL, 0x9988C89E94591DA9ULL, 0xE1E403854A53D8DBULL, 
            0x4E055ADB52749C20ULL, 0x56705F580297D180ULL, 0x1CA1CD528D341C89ULL, 0x14EA579C36A3298BULL, 
            0x27CFE339DCA8D411ULL, 0x9EF71643BBC6894EULL, 0xF9052F03337FA786ULL, 0x3B8ABCC69A45DCDCULL, 
            0x577AB33BB5434C53ULL, 0x793E4FEB3BDCB92EULL, 0xE9C5E918BE9987C9ULL, 0xBE26E73037E1FB60ULL, 
            0x75494C80FDF75B4DULL, 0xE9E019BF4FD556FAULL, 0x912086148F85D37BULL, 0x08A2E3D6DA833295ULL, 
            0xDDEEEF7BFD45103DULL, 0x44C27BAA4C766621ULL, 0x7CDA43EC5685F1EAULL, 0x131C8574D564AF4DULL, 
            0xB329E797E503C741ULL, 0xACDB9AB1500FBB8AULL, 0xBB61CB26FE558D0EULL, 0x3CF40C29CAF00AD8ULL, 
            0x0636FAEA37440CE8ULL, 0x258DD560FA79FE73ULL, 0x9DB859D9D2B88868ULL, 0x52D9BEF1E778B160ULL
        },
        {
            0x6CE847B890BF11D2ULL, 0xDC92B69FFD063583ULL, 0xD6283178D84F1644ULL, 0xD6A9BEF6705130FBULL, 
            0x9BBEE7EDD314E595ULL, 0xE562A89DD7DFA3E6ULL, 0x1449F4CD5513DCDDULL, 0xAB4DFB1257400348ULL, 
            0xCAE8589792D2134FULL, 0x683A0896E6944FF2ULL, 0xBA009D1137F12CF2ULL, 0x871A13FBBAD29C55ULL, 
            0xBD39D056B78EBF92ULL, 0xAC9AB1433FD36D13ULL, 0x807F1C19C1799A7EULL, 0xA2235672339B8A85ULL, 
            0xF613524040E3455BULL, 0x156C3E77FC2E99ACULL, 0x1E32A64DCCD1626AULL, 0x5FD20B9C5FACC822ULL, 
            0x3220734C102AF7DEULL, 0xB95FEDB0C8228FCEULL, 0xE5A61661DE98E8CFULL, 0x70D7B4908ABFBA9CULL, 
            0x2A1C711C82BA2D97ULL, 0x66510FD0E95CBFF3ULL, 0xCB51D178D779BE56ULL, 0x80C0AF279A3519B5ULL, 
            0x36868A5A262F169FULL, 0xE4D622F098C6BE6FULL, 0xEF88CF29D83A0123ULL, 0xC14BBBE37907F583ULL
        },
        {
            0x2806FAA20CF6EE8AULL, 0xC5764A3CFBB5F25BULL, 0x85BF8DC4F0AA91CAULL, 0x0C8A215902546852ULL, 
            0x3B7DEF13E3683766ULL, 0xAA3E839D8C584D16ULL, 0xEBBB467D0BC93325ULL, 0x0C42C18F26826B6BULL, 
            0xBBD7439571F2B838ULL, 0x9ABA426B9F85F5BDULL, 0xB4685EDEEB76AE3BULL, 0x4CA9712D6AA15394ULL, 
            0xF2134B5B1A2B376FULL, 0x7F27E3D1C6FE7B8AULL, 0xDA3AC099A899D460ULL, 0xDAEBDF52A0C19BFCULL, 
            0x569372BCB5F6A7FAULL, 0xBF42C0FF41341D81ULL, 0x6CE3800883BC3047ULL, 0x67F07CA41D5D52C5ULL, 
            0xC706E9312D19D0F8ULL, 0x401338CFDE9CBB3DULL, 0x5226EC9083CF73EDULL, 0x2BF14FF12EAEDCC5ULL, 
            0xB7997B80F462AFA3ULL, 0x2109BD2A970581D7ULL, 0x3F49F46B99728735ULL, 0x9ADC86E8A1DCE739ULL, 
            0x63B0551763E74762ULL, 0xBADE636088CCD695ULL, 0xBD7BB97BE8A8A638ULL, 0x3EE2C4DCDD9F00BEULL
        }
    },
    {
        {
            0x5B302628011A3417ULL, 0x30F479AAB40C32F0ULL, 0xB8F92328D6B1272CULL, 0xA2795C44487470F8ULL, 
            0x8784EEB113E4A208ULL, 0x0241456C13BA7E48ULL, 0x55DDC94718BB15F1ULL, 0xA0B3282AD1CBAD56ULL, 
            0xC91E2CB120F57096ULL, 0x646652A681815140ULL, 0xF6DF1A97B76B97ACULL, 0x8D3DE5FD31FA684DULL, 
            0x1EEFA9BA06CDDDC5ULL, 0xFF823A19CEFACC6CULL, 0xD5525E576ADF9C96ULL, 0x1F06BAF5F4A2A888ULL, 
            0xE01F698B3FD2B78BULL, 0x88115444D9B4C223ULL, 0x1EE1D912A4123623ULL, 0x43D344E308E02266ULL, 
            0x69BE41E9B718AE3FULL, 0xB22B03E5A0BD098BULL, 0x5CB12A82EEF7604EULL, 0x77C00229FBAEFFF9ULL, 
            0xA867556D103FC891ULL, 0xFE6C9E33D6726151ULL, 0x0C698F8396D5C64FULL, 0x211EE4B22188E742ULL, 
            0xC69544C7C1DB0AEAULL, 0x0AF780A2BE5EF32CULL, 0x40CC81AF71DCA322ULL, 0xF94E62E0112101BAULL
        },
        {
            0x8D06CE5AB68F3FECULL, 0x3ADB9B677AD9CAF1ULL, 0x0052AEAC900314BCULL, 0x8EE06FE79533F8E3ULL, 
            0xBEC5F2BCCDFF0254ULL, 0xE6D7E66866255E1CULL, 0xE50FB7C7CB6610FDULL, 0xC7839574DED73D8DULL, 
            0x8F63F88AF125CA97ULL, 0xAB1FACDDB305F854ULL, 0x39212FB801A147DCULL, 0xBF75FADBB1BBE6E3ULL, 
            0x4B1639E1E4B11E4FULL, 0x068C88F7F42CCD3DULL, 0x6E25166291AD5928ULL, 0xE6AE7DE06F946DADULL, 
            0x7246C64AA2E6159CULL, 0xFFC1E592358C7208ULL, 0x65F052EBA5822955ULL, 0x7B240B0B50BBF317ULL, 
            0x27476561FA3F67F9ULL, 0x24E493F83745E8F3ULL, 0x088AB629B014E4BFULL, 0xA047D041AA948774ULL, 
            0xF1E70FC38D332810ULL, 0x4379113238F3E09BULL, 0xE83C914DFC751146ULL, 0x0ED3B31E298AF522ULL, 
            0x3C5CAFC8D58186F6ULL, 0x57815B6DDDE29943ULL, 0xBE972D1502CEBAD6ULL, 0xB7D3C801C4344817ULL
        },
        {
            0xCB0A8D392D5A6E13ULL, 0x51B745E43FA9CF46ULL, 0x019BCAD39355255DULL, 0xF727AB23960748ECULL, 
            0x56CD953A4EFF29CFULL, 0xC8AEE9AB038FA446ULL, 0x70601A086F79F468ULL, 0x2E978076B286BEC5ULL, 
            0xC0FAB29ABD61897AULL, 0x6939D34B2EF0CB75ULL, 0x6B2B5E7D9CE00284ULL, 0x37138E72A943C790ULL, 
            0xCD64C10443778766ULL, 0x118FC7D8AB2BCD56ULL, 0xF21C6896E6A7DA4CULL, 0x6BC81124FEDEE1E4ULL, 
            0x687B31C95361EB50ULL, 0xE180D1462F209707ULL, 0xF8E3E8D34AA5B452ULL, 0xC0EB6F6B582A226EULL, 
            0x382E29E77FA0DA8EULL, 0x3E60CC58E5AA431DULL, 0xB46D7C49CFBC968EULL, 0x368A34F755AD6648ULL, 
            0x85ADA2478850BC58ULL, 0xC45649AB3AFF1816ULL, 0xDC97707737DF4169ULL, 0xCBFE81FB9A43FFE7ULL, 
            0xB4DF94CE730F84A3ULL, 0xE15070B1BC8A7892ULL, 0xE72D40AB4A7DC798ULL, 0xB249FA5BA720532BULL
        },
        {
            0x1F6B7DF581D2995DULL, 0xB31C110902E0C2C6ULL, 0xEE898F3801B80D55ULL, 0xC25BDE976175A74BULL, 
            0x9E95F30EFFF9B290ULL, 0x24D655003673CDECULL, 0x3C262040E1EA4143ULL, 0xC5299FB7F16AE4EBULL, 
            0x1BF78072D3E33F37ULL, 0x7EDE3A91997A0CB1ULL, 0xC57E81C862E3B330ULL, 0xB81E1804CC676C51ULL, 
            0x3E8CDEBF0DFB0AE1ULL, 0x4DE1358A816DD76DULL, 0x1413B3D52B95F0DDULL, 0xF24F04B1BD57482EULL, 
            0x11D8C4B5C036CC0AULL, 0x12B3168BBE75BCC3ULL, 0xD5C59689DC522FB6ULL, 0x10B8462FD61766A3ULL, 
            0xCF25AAA1109584ABULL, 0x078D70F849A08025ULL, 0x3225B36EA1FEF952ULL, 0x3E484D7A1B64CE49ULL, 
            0xFACA642EFB3BE744ULL, 0xD839C8A0B4268991ULL, 0x6CB45A46F81C0AA4ULL, 0x4FDF93A8FF3FA212ULL, 
            0xC5E10B0E52F9A504ULL, 0x1923A636A5471BD6ULL, 0xFA2AFA581DD514BFULL, 0x169B71AA75433AEFULL
        },
        {
            0xF5D302B38B547780ULL, 0x8337B708F9F3BF0EULL, 0x85E67C493AA9D910ULL, 0x32B2C4D9485775C2ULL, 
            0xF104CFF8111DF4C6ULL, 0xB62E061575477EA9ULL, 0x606E53298A73799FULL, 0x11C232396AC98314ULL, 
            0x303163556BE2ECADULL, 0xE08D7C4069F49CB4ULL, 0x313FC94B210035EBULL, 0x020B41CF21B5083EULL, 
            0x767B089ABC8E8CBBULL, 0xB655132C12B0E099ULL, 0x7A93980D22703687ULL, 0x60DDBD2E39C07A97ULL, 
            0xF2A6AE8F054BA3AFULL, 0x5F59D86ECD1D800CULL, 0x07E63AA1234EC4DFULL, 0x966B2E72EDD7791DULL, 
            0x44BA3D6225E43ADFULL, 0xC3EB3F7801DA9786ULL, 0xA45CA1D2AE30FC73ULL, 0xFF273569D72A736CULL, 
            0x32DAE0F0221282A2ULL, 0xE3CBDCA84AAD03A4ULL, 0x7A5A9D12AE26BB27ULL, 0x1F523A4F27C4D8F9ULL, 
            0x59D6E03DC1E6A3D0ULL, 0xDC928FE55B358476ULL, 0xDD2CC0F6CD5A407EULL, 0x5B960F17D56C8336ULL
        },
        {
            0xF25B00326C5C9E8CULL, 0x00478A37D50E5D36ULL, 0x3ACAE751F82FC0E5ULL, 0x96C522A2DF098D67ULL, 
            0x4306691772524E33ULL, 0x268002EADF422AEDULL, 0xF28AAC0B6FE1EC01ULL, 0xD97DC7059C36ED4BULL, 
            0xD134E424B395BD68ULL, 0xB3A3E68B877D6DCEULL, 0xFF7F7B17963C118DULL, 0x979BBECEA0A4585EULL, 
            0x98607C037D05CBE5ULL, 0x99D55DA9CFC166D7ULL, 0x97D2EACAF04DC53BULL, 0xF19B7D921F4861C9ULL, 
            0x1CFFFEB926353B4CULL, 0xA8B1BB318438F0FFULL, 0x46244954791128ECULL, 0xD2FFF9CE3280DD43ULL, 
            0x20B66EA20F29B556ULL, 0x1CE15DF2F79AD5E4ULL, 0xB2833AEF2AB23D16ULL, 0xC4157C176919235CULL, 
            0x326B5F2834292A7DULL, 0xB98DECB969B66CDCULL, 0x5BD074BC7934E4F4ULL, 0x6DDA99F2F28DFCAAULL, 
            0xED9B0629A203F764ULL, 0x163EB03B660A5E60ULL, 0x58CA2CFB93080569ULL, 0x675F577E4EFA0D61ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseFConstants = {
    0x685A404C674DFBBFULL,
    0x26091883BF350A02ULL,
    0x99E6D055F6AB89D2ULL,
    0x685A404C674DFBBFULL,
    0x26091883BF350A02ULL,
    0x99E6D055F6AB89D2ULL,
    0xB6A6F5CBF08EE8ABULL,
    0x12B9AFBFCE007BBCULL,
    0xD5,
    0x3A,
    0x6E,
    0x32,
    0x0A,
    0xED,
    0xF1,
    0x70
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseGSalts = {
    {
        {
            0xE180F73AF77F6BC5ULL, 0xE6EC20B12D10F867ULL, 0x2ADC5BCD954E8CEBULL, 0xFEA7351C714B59DCULL, 
            0x62017FE2331A4825ULL, 0x2225BFEB0FE19C95ULL, 0x0B18175EB12F9C9AULL, 0xD18FBFC74C323147ULL, 
            0xD1A743C902027F54ULL, 0xB04323953BF01E94ULL, 0x9D34EC5C56330561ULL, 0x1C2BAABA837C5844ULL, 
            0x2A87CF5E4AA15F42ULL, 0xFE17CA59CFFDE63CULL, 0x56D5CB47E449F473ULL, 0xAA1125EA0FBEBD2FULL, 
            0xD4FCE3825980FCEDULL, 0xB45F5A0130A718A6ULL, 0x02D66A13ED91E6EEULL, 0x9C09AD2C759CC57CULL, 
            0x0E883E4943FAE73BULL, 0xB0D4F168ECFEF914ULL, 0xF9F686A6E187DA14ULL, 0xBCCBFBB17529ACF0ULL, 
            0x18D8843E5654747CULL, 0x5C933C3919D747EAULL, 0x0944357ECC431A7DULL, 0x514E691B50B7780FULL, 
            0x56A89705658695F4ULL, 0x0A740F6240C0BBD3ULL, 0xB74151E29059F859ULL, 0x78BDC327BE466236ULL
        },
        {
            0x6C05A50D2BB798D7ULL, 0x15957D6EDE4E68A5ULL, 0x9F5FF9C90614ACF9ULL, 0x7D4DE11676609829ULL, 
            0x58C2D82410A3622FULL, 0x3979095130F53CDEULL, 0xF84650619C9081ABULL, 0xAEAB6FE6E8A675D0ULL, 
            0x553AF790C82FBCAAULL, 0x9BFC7CBDCCA35B57ULL, 0xD601616438A63DB6ULL, 0x0055B27120741700ULL, 
            0x409C28E627BB2A3FULL, 0x03D5844B95CC964AULL, 0xFF0AB8E313F14020ULL, 0x6F8F8F5F8295584DULL, 
            0xBBE55EABEC52454BULL, 0x0AF0F256A96AF116ULL, 0x23325D2A0B9CD045ULL, 0xFFD6A85F12367BE8ULL, 
            0x6F4598FF79BB7E9AULL, 0x4A58865152400090ULL, 0x057005584FDC23ACULL, 0xD30AD93510CFDDACULL, 
            0x34C683113DEC1C07ULL, 0xE361448036B77D7FULL, 0xB5202B476BD99D91ULL, 0xE7586D798A32FD85ULL, 
            0x1835E4EC5D5B6CE4ULL, 0xBA3451C37788B1BDULL, 0xE721E2930B721DC4ULL, 0x34FEAD80165326D3ULL
        },
        {
            0x231E47F044B5A2FBULL, 0xD590DC8F937EA4D4ULL, 0x00294C9ED13D9625ULL, 0x01B3DC33A93A153BULL, 
            0x1A727EB810F64268ULL, 0x857AEB6D838CB848ULL, 0xB2C37CB9968A4A7AULL, 0x63719694F6A6529CULL, 
            0x095725B875726676ULL, 0x68A1A6A9643F4244ULL, 0x1E0011BAD906FDF6ULL, 0xA82406B8CF341717ULL, 
            0x95DEC30202D77312ULL, 0xCE3CDF4FC5A461EAULL, 0x09BA8C22E2925C09ULL, 0x3D587E42F2DF618AULL, 
            0xF02E87DA4210B929ULL, 0x086C0EC22977A01EULL, 0xF2C1D40EA724F971ULL, 0x98B4B64F3B1C82B6ULL, 
            0xE2F22650D778430BULL, 0x3B53300405816802ULL, 0xCA5AA3D4DA6AF9EFULL, 0x0D70CB7FC9E98905ULL, 
            0xA9B34747A91C63A1ULL, 0x1B628F95646E2A00ULL, 0x979C6845714A7673ULL, 0x89DCDE561D242762ULL, 
            0x4DAF86693C8F5FE2ULL, 0xCD51603C54F0A5B8ULL, 0x94AF78A9C0A4019FULL, 0xDFB26584602666E2ULL
        },
        {
            0xB44F0E899A6102F8ULL, 0xFF2E66360CB3EB07ULL, 0x1BABBF5601D97171ULL, 0x4B3D817BA933B326ULL, 
            0x04F500DA32248738ULL, 0xF089B40B5FBB43B4ULL, 0xCD749796E33BB9C0ULL, 0x097A008E2680D97EULL, 
            0x7559B096ECFAE9C7ULL, 0x117FF752BD4C8D24ULL, 0x3A4558103BE500E2ULL, 0xE63C5031D0BBE833ULL, 
            0xFC1C5A5F7952B41FULL, 0xD358621456C4B1E2ULL, 0x5F92E8A625EC772FULL, 0x1C9E9A7F52AF0722ULL, 
            0xF27FE87EF6DBF3E9ULL, 0x9D42530C53CBCD91ULL, 0x9373E7AA7E6FC364ULL, 0xA73B256D867665DDULL, 
            0x690E6A696B0CBD10ULL, 0xC18620CEE802F457ULL, 0xCA05AAB15BB40157ULL, 0x52A15B661DB98D12ULL, 
            0x8F18C84EB3AACE3CULL, 0xAB671E959FC3237BULL, 0x54A59DCDEBA73FFDULL, 0xBE0DBC8BEFEB924BULL, 
            0x61E77B3FF0753CA9ULL, 0x635255799D9BC75EULL, 0x8F499B58DFBF992AULL, 0x75EDF6A5F5777DF5ULL
        },
        {
            0x0DAFB371FA4D4BABULL, 0x2A8F2ACB629A7409ULL, 0x256BD99955D33A3BULL, 0x65669FE0DB1EC0D0ULL, 
            0x2B9437DE550DF4BCULL, 0x3CF2DF4E48FAC230ULL, 0x194A5C2EF3166DE7ULL, 0x6A5395A1EE9A2377ULL, 
            0x894D0CE7C1BF1DA6ULL, 0xE13D89CFEF7289DDULL, 0xAB50CA3E7676E7D3ULL, 0xA7318ECD9BE9E9A1ULL, 
            0x8A4872AD7313AAAFULL, 0x68D48E64C022D17DULL, 0xE11688017F010453ULL, 0x83296FB082C050C6ULL, 
            0xD3150DBA1143385AULL, 0x004D50A4C2331E81ULL, 0x0E9E4BE67B82A7B0ULL, 0x7EA1CF21B1E1781EULL, 
            0xD3DFB99B6CDFAD23ULL, 0x222B73F2171D274DULL, 0xA8EB41CD8B1A3090ULL, 0x5CDA5FEDF0829E89ULL, 
            0x6769C5C83923D418ULL, 0x311FF85AE7B5CAD4ULL, 0x10EAADA4C9D8B643ULL, 0x5F4D823490CD4656ULL, 
            0x9914C378A95EC3F1ULL, 0x2536C8CA56D06754ULL, 0xA2914DD338BD0113ULL, 0x786A329AA85F3DBDULL
        },
        {
            0xBE35E8632A63EEB6ULL, 0x949C5A183FE21C62ULL, 0xE1C7EE49AF3231C1ULL, 0x57E6F3ABEC57E848ULL, 
            0x75C2A35EE4DF58C6ULL, 0xD0B1E8D9EEB52650ULL, 0x24A61241DE55E2F3ULL, 0x5B2BA23E38755F00ULL, 
            0xC2DDCFCD13D5F8CAULL, 0xE5E10FE669644740ULL, 0x3B26B469539F9C35ULL, 0x1381B5405EAD295AULL, 
            0x98C230AFDD2841AFULL, 0x5A5138BC233850F0ULL, 0x352E5AA7C1BAE9FDULL, 0x94000EC1A82C3AA7ULL, 
            0xDD94950CD5CB01BBULL, 0xB5232408F69BA9E9ULL, 0xFCEB28476B14E2AAULL, 0xDB9534F42985573AULL, 
            0xE31AD4F0B6973CB6ULL, 0x37DC322196A24655ULL, 0x03AB2FC9B0C0EFB8ULL, 0xD9744B035ACEC7A7ULL, 
            0x6149CED9C61B4F07ULL, 0xE0FE18535EB1E2F7ULL, 0x310295AE5BC41733ULL, 0x65E8EBC4F6184738ULL, 
            0xCAB29C8CF59A1017ULL, 0x9D63451FA0733F48ULL, 0xC5D5396D83255684ULL, 0x6F1643088531232CULL
        }
    },
    {
        {
            0x3D9109ED84BC4739ULL, 0x792B22A87EF2BCD7ULL, 0x85E5EC0C407D0C57ULL, 0x835F7DE5899CFBB1ULL, 
            0xF53CEDED487BC9C4ULL, 0x572B141C291EA3D1ULL, 0xA44CC1D41FB328EFULL, 0xD362338DA74A6C8BULL, 
            0xAB317BDBABF9C1F6ULL, 0xEB42CAD8DB5EF2AEULL, 0xBE3B50AD1AC10F88ULL, 0xB5832B5B21A52F69ULL, 
            0x2B40C227C3F2AC02ULL, 0x6CE55493224303CAULL, 0xD976FFD35DED503EULL, 0x23C748A5B720972EULL, 
            0x3B3D4B5C0FEE0095ULL, 0x562298C0F3311499ULL, 0x6B95074C61A0F8C7ULL, 0x1C8754463E88E29BULL, 
            0x38F59E1B6990EF2EULL, 0x79722E17E80B97A3ULL, 0x76C6CC9C01694892ULL, 0xE379CD02D920190DULL, 
            0xB7DA70FF25C64328ULL, 0x63250FF1903859CCULL, 0x6FF5C102B2E189CDULL, 0x93C006E2FF804D51ULL, 
            0x23DC81468D063B1FULL, 0xEFB7BBB8CB997B3FULL, 0xE279E925ADFBBAFBULL, 0xCCE7470E5F2A63C4ULL
        },
        {
            0xEC1B8F7DA58F448FULL, 0x47A8737F48E999E1ULL, 0x1DBBC562F3ECC125ULL, 0x458F806228B7387BULL, 
            0x1BBF27B8B85DCC31ULL, 0xEB5A0FBEEC2942FFULL, 0x529804FBB5B14148ULL, 0x2CFCB165B77710F4ULL, 
            0x00B23C6366A6492DULL, 0xBB781491EAD0A4FAULL, 0x7DB4901E681E7045ULL, 0xFBE3601F14668397ULL, 
            0x8B74171BF3C2AB51ULL, 0x7311D634224D278CULL, 0xDC1F2DA0204CA073ULL, 0x7E7D557D23994E9DULL, 
            0xA7F53871712788F3ULL, 0xF790B857E4840EC8ULL, 0x48B98A04E7BB6E58ULL, 0xD5DB49AEA38519F3ULL, 
            0xCD40E7D27D8E8916ULL, 0x114603FA38A1B100ULL, 0x4BED2102C2774420ULL, 0x0970644FAFDDC650ULL, 
            0x6DFDC3B01FB9E80CULL, 0xADDB5145BE911EC4ULL, 0x10074D6869E76B31ULL, 0xE9442EE508857361ULL, 
            0xF8A83227A4E6B1E4ULL, 0x1DBC06584200B692ULL, 0xD578D44C43A37DDDULL, 0xCE9810A933FBE313ULL
        },
        {
            0xACC1A3122A86104EULL, 0xE8E06AC1C35B7A80ULL, 0x08636B4C79B14D87ULL, 0xD896CCAA030F2CDEULL, 
            0x872BE2A3CC26F4CEULL, 0x2E5AA2C9EB55BEA2ULL, 0x4D6E5D1D2BB48C72ULL, 0xE712E146044B61FBULL, 
            0x45912E3FDC579095ULL, 0x817298B4E13E75D4ULL, 0x363B2F8CF4BECBF6ULL, 0x64425735EC7203C6ULL, 
            0xE41DD80B92653578ULL, 0x6132682E1B3F48CBULL, 0x351471B31E252AFCULL, 0x5D40D3100F94357AULL, 
            0x86348A1D5072A5ABULL, 0xF43683FB112F77DEULL, 0x9AAE774BE159F223ULL, 0x01A4BC497D7F2E20ULL, 
            0x57F1FE751D9F8140ULL, 0x5731F6E0C623D444ULL, 0x8675613328BBC3CCULL, 0x7875C33F2B0FCE73ULL, 
            0xB05E463C221123CCULL, 0xEAD13FA232E2B14AULL, 0x610B4881D43C4409ULL, 0x14857290D989C8F7ULL, 
            0xA9BB3A64C6BDF8EBULL, 0x323F24F713C86EADULL, 0x96B33C792C64E4ADULL, 0x45F59E2D687AF70FULL
        },
        {
            0x75879913ADE8429BULL, 0xEEF7054D5458E8E1ULL, 0xA6E3E63A60D1EF14ULL, 0x6B1C5F32A009E45CULL, 
            0x4340F967CBD92314ULL, 0xE727B016184DD697ULL, 0x2D5FC63F765CC553ULL, 0x709B57AACAD88A37ULL, 
            0x6E3325E3D3140DBDULL, 0x284B39BFF021C59AULL, 0x3928C4A5A1B8F531ULL, 0xDA90588038160B5AULL, 
            0x717D3CEE5E86301BULL, 0x67A53E55419AA33CULL, 0xB1EAB8D1E647F683ULL, 0xD29C17BE569115ADULL, 
            0x73A5DB8CA3C73403ULL, 0xD0E80C91BF32F619ULL, 0xAA96505AE657AFF1ULL, 0x07A3E124070567DFULL, 
            0x6D008E4E40D80D49ULL, 0xD41207394750D4C6ULL, 0x2861639055533725ULL, 0x3138896BF2802B0BULL, 
            0x592608BB93E20098ULL, 0x0D2E79E508577B72ULL, 0x62F507A3822C7D69ULL, 0xF9051EEF100827A0ULL, 
            0x00A698AE157BB775ULL, 0xE9589B5B7A3637EBULL, 0x2ADEA2D3EEA6B916ULL, 0x43EA12EA080C75E4ULL
        },
        {
            0x7AAB9FDE565D4FCEULL, 0xA8FAF0B54FD5A2EAULL, 0x8C5E62AB27D380FDULL, 0x01F3D7D34C6D7406ULL, 
            0x2D65122077FBABBEULL, 0x9586B028FC39367DULL, 0x8DD719B5357B873BULL, 0x0F29994777859466ULL, 
            0x5673A7D0BFE1413FULL, 0x05B728ED14D3309BULL, 0x2977D8DAAED45BEBULL, 0xFDC37F99536D0DE0ULL, 
            0x7293349E00A8A521ULL, 0x864CBE7C30596D9CULL, 0x946DD0AEF39707A0ULL, 0xC217AB441E93D1A2ULL, 
            0xD6ECE8ABE0222070ULL, 0xA33491A3A58F3228ULL, 0x2A34B43D0EE26C2DULL, 0xC42AC2B2A650ECF3ULL, 
            0x24FF950ADF637E09ULL, 0x1D1DC3983EF52AF6ULL, 0x709F20AE7BFF730AULL, 0xE42E71B60CB41E80ULL, 
            0xCB28A6A32279A3FFULL, 0x2690228BE46CB136ULL, 0xB8B16AB6EE178F0EULL, 0xDA6A4D5F97FE9755ULL, 
            0xCF2EC79EF367CCCFULL, 0xF8FD0FD1019BEF92ULL, 0x70AAD2F14A6461EFULL, 0x7044AD276E0AF7FBULL
        },
        {
            0x6D0C43FE54C3C7C8ULL, 0x7BEC63583C7BDE02ULL, 0x4074772001F3E1A1ULL, 0xCC67AA573131535AULL, 
            0x4E2B439B10E951C7ULL, 0x1E56D29499AB330FULL, 0x74D4869E69E68988ULL, 0x2BF98A3DBAB123EDULL, 
            0xB2D8FF8D046768F3ULL, 0x80A48FE981819B55ULL, 0x36A9284BFDF684C5ULL, 0x47F50BFE2D312DB7ULL, 
            0xBB9454479515A1ABULL, 0x1B0F534C2D610992ULL, 0x03879196FCFBF996ULL, 0x8E70F9AD5D1D5F86ULL, 
            0x1FC4712E83ED6E1FULL, 0x0B6BD3E327D1471CULL, 0x8F3FF2C0CBB8749AULL, 0x2A7A046847ACFE42ULL, 
            0x0AE7D3A36CD25D5FULL, 0x0E9DFE7F5B413212ULL, 0x95EC954AAF1B7393ULL, 0xCE55115ADA29782AULL, 
            0x33E29882756ED4FBULL, 0x5BCC4A55A694CD13ULL, 0x1CABF65D428512A7ULL, 0xA19282CE7C5D3A65ULL, 
            0x33C785921C8E768BULL, 0x962B696634375FDDULL, 0xA51BDED94FEB8D31ULL, 0xB786E4A649C74858ULL
        }
    },
    {
        {
            0xA32162C35765DEF0ULL, 0xF6A3EDF472E5EB8EULL, 0x6ECA1D3477AA002CULL, 0x95E83D294EE0C661ULL, 
            0x732C113879EA3CBFULL, 0x5CD6CD8A8F7758BCULL, 0x1155E5D2A4703360ULL, 0xBC486FF0F3D64215ULL, 
            0x985E5CE7693E2B56ULL, 0x45241A591DE6D010ULL, 0xE1092383FEBBC3B8ULL, 0x3203AD045A14FC34ULL, 
            0x77D30CF9E2CD92D4ULL, 0xEDF0C21527816813ULL, 0xDD4C1BDE50F5C647ULL, 0x6A93D6632BF2CAD8ULL, 
            0xB917DB9511FC443BULL, 0x233D27DE4DD7EED9ULL, 0x81D12D10990738A9ULL, 0x5D3F3E4D0FAD1285ULL, 
            0xFFFEC7399AB1425CULL, 0x1F297A974E84A871ULL, 0x75CC9753A5A2F7D8ULL, 0xCD216051D008346DULL, 
            0xC6C471AD8CA7E0C2ULL, 0xF435905A94ADD8DBULL, 0x37F447DFE9436C2CULL, 0xA2E0AD6DD772403BULL, 
            0xC193522266932B33ULL, 0x2C7D22D250FF3B24ULL, 0xBE2DA5425BC940EFULL, 0x086AA3DE76720359ULL
        },
        {
            0x08A68DFBF9A3389AULL, 0x90068FD72D462428ULL, 0xF4EBE2F5C063AE1DULL, 0x15DF7AA5A827B2B5ULL, 
            0xDF3DD0D39FA51637ULL, 0xFA4EF29AB39693E5ULL, 0x9ECE40CD77ECEBB2ULL, 0x2DE19DAE5A3DE9BFULL, 
            0x197BE75C5EA653CEULL, 0x787DAF117CF3FD94ULL, 0xA69FE0BBCCAA43C0ULL, 0xBFB93D5C22B609BCULL, 
            0xD1186390BF9F09DFULL, 0x6E3A1717A20B2B76ULL, 0x0C92D121FEF5E9FBULL, 0x6D8101D1998B16F3ULL, 
            0xD782C5BBC471A00DULL, 0xB0994B8A94ACC930ULL, 0x1830E44478C8226BULL, 0xC48FCE31C807DE02ULL, 
            0x3983FF39B71B8584ULL, 0xA007604F17C28A28ULL, 0x7AE61B3F4811FB8AULL, 0x3057732FDBF9ED52ULL, 
            0xA979F0BCD902EC16ULL, 0x4C23C3A1DA804DDAULL, 0xC24DE4B75C422BD4ULL, 0xC7E4876D937DBA6FULL, 
            0x4688C0625AD169DFULL, 0xF68621C8EF754804ULL, 0x07283DD9A3A3B7D9ULL, 0xBEAF8B410ECBF118ULL
        },
        {
            0xDF95B9C9F4ABBEFCULL, 0xD840D719AC275225ULL, 0xFF09D24D7F78B848ULL, 0xF7CF8F744856AEEAULL, 
            0xD0FF8FA7B794E651ULL, 0x70B0A3FF7408D1DFULL, 0x6B2946A63D44FAE3ULL, 0xBAE1BE88B1B1E780ULL, 
            0xB5D370CB09477EE8ULL, 0x2A9EA2C13A299CF9ULL, 0x836F55CEE86897E8ULL, 0xCF117C1AE1868384ULL, 
            0x71B424F0308F39E9ULL, 0xCB0B75CFD39D3700ULL, 0x633C41721ACFC375ULL, 0x366137EC09613836ULL, 
            0x20623A74094470CDULL, 0x218E64CB25AE7B45ULL, 0x0CC5266251C7DDC5ULL, 0xF21DBF0A195983D8ULL, 
            0x4E1A1668691EFEA8ULL, 0xD0DBEDD07E95C725ULL, 0xED6A2EC73495033CULL, 0xA94FF7F82C854615ULL, 
            0x12AC78B51D96A819ULL, 0xAF6E6E24166E26BAULL, 0x89DA7852437BBD9FULL, 0xD5B3DDEE61A0CD5DULL, 
            0x5CFDC7BDD756D5B3ULL, 0xC8D1F43E5A0F7166ULL, 0x2BDD5CE3BD65447FULL, 0xA0E694DAE8873B6DULL
        },
        {
            0x4738FB7D9E0E4E75ULL, 0xECCC382F0BDA4E30ULL, 0xC0DAD25D61A2BA66ULL, 0x0AC93AF1298D259BULL, 
            0xA74732D315783276ULL, 0xC39E6FCF7397C76AULL, 0x97BC2F4A6EDA5E57ULL, 0x4C5773443B3B13D0ULL, 
            0x03402065191CD5D0ULL, 0xD5B6FA6C07D643EDULL, 0xE22AA1020B88C58CULL, 0xD4463DE15A648A87ULL, 
            0x73D97454633115CAULL, 0x9F9F63A4E61C4FDCULL, 0xD2F87DEA5707885CULL, 0xA1B4C5035E550D88ULL, 
            0x138D28466E1E1F72ULL, 0x01399E65BA09B56EULL, 0xD5FFD0C614479975ULL, 0x4F4EB4AE43BA1FC4ULL, 
            0xD6483DD0BB91C31BULL, 0xA7EEBBE28A10A126ULL, 0xC86C63F63894744FULL, 0xDE7A1E132DFA4FE5ULL, 
            0x443F19DBD7B31D67ULL, 0x729597E48FDC4093ULL, 0xE73949DC76C91C5FULL, 0x5A3E9906CEEACC52ULL, 
            0xF121D457EB7B4FAFULL, 0xA8C50099B572C773ULL, 0x5FD54C708E52860FULL, 0xD8AEA48B80EC53C7ULL
        },
        {
            0x4C5B6D9AA9AEC5DDULL, 0x1F8E14744130303FULL, 0xFA4D4F9C47AFDC1EULL, 0x23346B7BC31D5EC3ULL, 
            0x6700E2CE6BB92691ULL, 0xE93BA6DA04C13380ULL, 0xA6DF0B3198DF1D46ULL, 0x5F8B2DA44CF80A11ULL, 
            0x58C3DF4FD564BEB1ULL, 0x69C79CE31803A53DULL, 0xE6B66CC275E9EA2AULL, 0x077CF7E8B0E91038ULL, 
            0xC0C079EF4B77610EULL, 0x89CFB1CE35354F95ULL, 0xD4E0688E64D28ECEULL, 0x5466E99EAD1A65D5ULL, 
            0x9CECB823E16D01AFULL, 0x8877D1A6CCEFD2B7ULL, 0x33CA2420939A7FD3ULL, 0xB1ECF51C32867EDCULL, 
            0xAD29C240CF3ED6ECULL, 0xAD5F973F9F7BD4F2ULL, 0x807528A4567B39DEULL, 0x114EAFF9E6223163ULL, 
            0xDE2F8538A42F7F6CULL, 0x594568EECD5CCBEDULL, 0x77F900397DF6AD72ULL, 0x4C99BBFF26F5E6C1ULL, 
            0xEEE4E03C34D7897CULL, 0x29FF2E98E3A39F49ULL, 0x5FE0E3CA0292D073ULL, 0xAF1ECF04B974C534ULL
        },
        {
            0x15F6E55D1634CA40ULL, 0x4F4DDF79456BDF21ULL, 0x25B38230E711CE1AULL, 0xF6C09370EC00E03FULL, 
            0x8C410B36292397EBULL, 0x821231F75ACEA368ULL, 0x9AEFE53212DFCDDCULL, 0x0021F0B603B49F0AULL, 
            0xEBE4F4EEB619CF17ULL, 0xF7F5CE15BC556FC4ULL, 0xBED5B8D0FEF528BBULL, 0x890EA3A55603B092ULL, 
            0x443BA5215E0BB7A4ULL, 0xF62B3627A00B6D0AULL, 0x5D6E0AC96535A1EDULL, 0x56A089314B23CD78ULL, 
            0xC01319AA05D6DB3FULL, 0x33925CC60673494CULL, 0xDD6DC80DF6078BFFULL, 0x6A2BBAE3B8B30D22ULL, 
            0x4D6982A284D0B3A9ULL, 0x454A5052718F1EC7ULL, 0xE724A733B0C63651ULL, 0x7D5D5EFFDB1A556CULL, 
            0x9E89E04F0AB33BC2ULL, 0xDF90F3CBB82351D9ULL, 0x8210CE01472108E9ULL, 0x52B15ADC9C7AAF9CULL, 
            0x08125F4B2433975DULL, 0xA6A6A196B1587AFBULL, 0x5D1CE14D24C03BB2ULL, 0xC2D8725AAFD7AF9FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseGConstants = {
    0x7D679E41967B116AULL,
    0x4019A42E7AFA1DA3ULL,
    0xA9DD2E2A5572F405ULL,
    0x7D679E41967B116AULL,
    0x4019A42E7AFA1DA3ULL,
    0xA9DD2E2A5572F405ULL,
    0xF1911C74C60DF6EEULL,
    0xB1205F92AFC51AF7ULL,
    0xB5,
    0x06,
    0x35,
    0xC6,
    0xE8,
    0x16,
    0x0F,
    0x6E
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseHSalts = {
    {
        {
            0x83605D4EBC8059C8ULL, 0x82BE9DF5D06CE47EULL, 0xBA2FB5AF32884735ULL, 0xB05C3883B8A70B49ULL, 
            0x962A52357B12AACDULL, 0x40C9A7D3767D6E57ULL, 0xB6BB24E83E37DD1DULL, 0x8A568C4A8121A0EFULL, 
            0x25A50BD75773CFEDULL, 0x428DAB1FA36804E5ULL, 0x4995A4DF33800033ULL, 0x2B28FEBDE00CBB80ULL, 
            0x8CC0DE9ECD6958F8ULL, 0xCEFA983CC8B47517ULL, 0x91519AA5361D8CAAULL, 0xE7B51FE94A6D6667ULL, 
            0xD9CF01A7E3B99A55ULL, 0xC86F10460A8288F0ULL, 0x01A0F754DEB5FDB7ULL, 0x3963DD8809510235ULL, 
            0x39EDDF06825047D5ULL, 0x17A60B1EC479AC42ULL, 0x570C6AD1F5130567ULL, 0x9842C15FA50F176DULL, 
            0x7EA03BEC21448488ULL, 0x9589B69B3E01E5C3ULL, 0x2F6B374D7F47C669ULL, 0x6B35C3C7687E0BF0ULL, 
            0xBDE9E3AAFB9F64E6ULL, 0x6F2C14AC8CCC7C6EULL, 0xB427C1F0D42184A9ULL, 0x43E920938756CDD4ULL
        },
        {
            0x7FE57E8A91F2048FULL, 0xC36ED48BE5E0EC6CULL, 0x08417BE8494888A3ULL, 0x8DA4B2EC4C4463A7ULL, 
            0x614701736394EE08ULL, 0xFA427992DE858646ULL, 0x08C7516FCE0287E4ULL, 0x4C7BDE0B1F302948ULL, 
            0x807441F7239B2E60ULL, 0x6ACC761AF1EDBD09ULL, 0x904E0F79B4AEB3DEULL, 0xCD9DF20CC8A3B74AULL, 
            0xD37FAC7171D07AEEULL, 0x44615B36D7EE31C4ULL, 0xE8E68A76783BF065ULL, 0xCFED4827226A33BDULL, 
            0x8FFCDE3E44E22576ULL, 0x356E4BEDCE006C50ULL, 0x77EDC461343E6384ULL, 0x9B58370086A7C471ULL, 
            0xA9BD0244B47FB3DBULL, 0x6B59196CB1BC58AAULL, 0xDAF336FB785E881CULL, 0xB0124418F6AAAD7FULL, 
            0xAEAD7DAD93D0D26EULL, 0x0B559B1229AD0476ULL, 0x2AA774DEDF55A66AULL, 0x4922FF914EFE608CULL, 
            0x38FE9B01CABE4677ULL, 0xD890C6ACD93D55A7ULL, 0xEEF3A198A52D46E8ULL, 0xD311D32A3273C90BULL
        },
        {
            0x090CBCEF8A2D0313ULL, 0xD8D6C6220D00E49DULL, 0x8CB5F58DFDCC9ED5ULL, 0x4ED8E3BF97C364FEULL, 
            0x5029C3456DD43103ULL, 0x56CDAE2CF904C2F1ULL, 0xC9414FFDE24C4C5EULL, 0xBA835922B9DDE93EULL, 
            0x5E8FE8369D3898FCULL, 0x121080AF27FE78D9ULL, 0xA36369E148A5EA99ULL, 0x30BC5A66F952967AULL, 
            0x74C01404A81F983FULL, 0xB7D0BE64B43C4ED6ULL, 0x173051C714657E2FULL, 0x003FB5CDEE5B02D9ULL, 
            0xC207139006240EDAULL, 0xF29017370119BC69ULL, 0x476E16EA3CE82524ULL, 0x7A9C212B96F8269CULL, 
            0x6A533F3CEEF2C951ULL, 0x2825851171AF37B5ULL, 0x33D8F97C40998B91ULL, 0xF2E073977DC89367ULL, 
            0xE39AB01ED3EF9D64ULL, 0x1004D21190150D33ULL, 0x59B7CF06DEB8027FULL, 0x0F3D20E7E15DF2DAULL, 
            0x45C34BDE0A8A8581ULL, 0x5D9E3E8BFD03AF06ULL, 0x671C9EF768B663FDULL, 0x8E12749C485D11FCULL
        },
        {
            0xFA782C50BAF23083ULL, 0x3C77622662E2050AULL, 0x217A90F8E0636DAFULL, 0x15C49CAC7CF6CD2BULL, 
            0x607D6BE9DB15D2F8ULL, 0xE56F040795E92FCFULL, 0x0960D1AD5B039C0CULL, 0xFBEF9F49654E984EULL, 
            0x97F69DCF42EF5E54ULL, 0xEC63B6011AF52A83ULL, 0xF84382676FFEC301ULL, 0x833EA4CDE9F93875ULL, 
            0x29CD6CFFC74726CAULL, 0x3AB040C9710BA15EULL, 0x9FECAC93E487E25CULL, 0xC4D05E7D47D789FDULL, 
            0x118D60CE4F735FC4ULL, 0x8DA18D364BFA6658ULL, 0xEDA736455E8AD974ULL, 0x91E35C5044D54D0AULL, 
            0x94128EA45D0D2FE9ULL, 0x69ED6F74D076B697ULL, 0x9B0632B0174BA892ULL, 0x41465ED2ACBA102EULL, 
            0x77FCD3ABD13AA3A5ULL, 0xA774CD6CE67AB2F8ULL, 0x105A7385B4057B87ULL, 0xFA5BE4C7F04A881DULL, 
            0x79E82EFAD8ECCD8DULL, 0xD85C2B126A4986E5ULL, 0xB115CAB426116AD0ULL, 0x5249A111EC478380ULL
        },
        {
            0xF386FE60D397776EULL, 0x97C29CF982D12B37ULL, 0x16D6602CE59DCE18ULL, 0xBCB4C803A385B8CCULL, 
            0x6AE039CAE70CA2ABULL, 0xC4CB6234BCD7A206ULL, 0x1F47645236C40D0FULL, 0x08E03C82815ACA6EULL, 
            0x70CD228261550A92ULL, 0xC36E6DCCB52A364EULL, 0x6ABD2DB55172E8DBULL, 0xFBBD0ED2B4F8C882ULL, 
            0x3F3C59B3C9D78E7EULL, 0xD0D68CAEFBFEA104ULL, 0x7E2C72176F5DA238ULL, 0x3E7CBB642AF94C85ULL, 
            0xB883A55F10A5EA99ULL, 0x27DDC268536B3F43ULL, 0x94E22850C3B01D51ULL, 0x14990E0C37123218ULL, 
            0xE136C65683DD4ECFULL, 0x72115E33A1C102FBULL, 0x27AACF56E09ACBBBULL, 0x416298B6B375D020ULL, 
            0xF32C31856CFC4330ULL, 0x38F2831B9C8A4C5FULL, 0x32B2EBC0F196954EULL, 0xFF53ADD80F2E504CULL, 
            0x0575DB93DFA07898ULL, 0x07B61EF63164A3E8ULL, 0x0A1D08899989F6B0ULL, 0xD997FF48C0EC1326ULL
        },
        {
            0x4C20BA9D8F36B9BCULL, 0x5BE6F7FFCF3F6F8CULL, 0x830088054B445284ULL, 0xB3088846C318B54EULL, 
            0x98E37C10BDC98744ULL, 0xEE3C82199B65696BULL, 0xAA916A184479801BULL, 0x158664E8A26B12A1ULL, 
            0x62C1C29B257B1270ULL, 0x6E6FAF1D27AD362CULL, 0xB5C7207FB02B7654ULL, 0x56DED8F7D5DF476EULL, 
            0x858A999DC6E93A9CULL, 0x8B3EB8BEEB85E844ULL, 0x953EAEEC29D5885FULL, 0x7EC6CF58CBDB0CBAULL, 
            0x27C659A8CC660412ULL, 0xECCAB608B7784F23ULL, 0x698513B408E7F6B3ULL, 0xE2945DFC71A930CFULL, 
            0x745B303773A678FEULL, 0xA962C9B2964A7738ULL, 0xA7A11DEA2A83A9EEULL, 0xC10BF0ADCDC09687ULL, 
            0xD0497E83AA04EC6FULL, 0x4F87F8547F33DD9BULL, 0xC52EF418CA0FCD59ULL, 0xB740A20A6FF1B968ULL, 
            0x8176D4FF076B835BULL, 0x571CB50B262FD380ULL, 0x6DD18237D778C87BULL, 0x7C60E44551579B9DULL
        }
    },
    {
        {
            0x24D144E4C0CE8EE6ULL, 0x829BA7575CA09CD6ULL, 0x49C73CD584ADA2A6ULL, 0x03924A4095CD378DULL, 
            0x8FAD5AF31F358835ULL, 0xEF4E6F79EC202CB4ULL, 0x1B75A6D393E560BAULL, 0x1FE47A6CF4B52F1EULL, 
            0xC5EFE263D1CCE725ULL, 0xBFBAA0B8AA9AE3A9ULL, 0x7A0548714BC28ABDULL, 0x8B0D8FB677476FA6ULL, 
            0x0A0FA5620F899DAFULL, 0xDD7E7D82B1485ECAULL, 0x0312143E11CB1D96ULL, 0xDF30C3C7784FEE9DULL, 
            0x1CFD163112DB689DULL, 0x243C2ACBB3FD475AULL, 0x44A49903ADE97F8CULL, 0xCFA84E1819BBF1C7ULL, 
            0xB6105EA45987A61BULL, 0xC5A9BBBC3260F3A8ULL, 0xF04977B388DEC0BAULL, 0x370E5F98758E8C94ULL, 
            0xAF9009C3C3261362ULL, 0xAEAD1320D170A23EULL, 0x1902C30B8627B00AULL, 0x8A42B2E12CFB92F6ULL, 
            0xD9A924BB918753E4ULL, 0x8629EF011FB80D3DULL, 0xF53E4A46FE863484ULL, 0x4EAAEDE6409A16BFULL
        },
        {
            0x0EB6C65AFFE3422EULL, 0x446362F2B1EFE45DULL, 0x968272DB3E0826FFULL, 0xA1F33DF94BADAE37ULL, 
            0x590F1AF1CD4B2C45ULL, 0x59FD1B0E571D6C0EULL, 0xB51ADFF5FC977017ULL, 0x2261DCC25D35C78FULL, 
            0xBAF04CB9FFB92DE0ULL, 0xBC165F23F4BC4C03ULL, 0x9DCD2BD9EDD238D3ULL, 0x6D6A2A6A5E10356FULL, 
            0x82B017485311D1FBULL, 0x411381758041FE0EULL, 0x6BF695352676906FULL, 0x1DCB8E37226E5214ULL, 
            0x55F52285455FF27EULL, 0x2AE70D1CE44546ABULL, 0x5B8A276CAA124A49ULL, 0x508C5CBC9A9FABBDULL, 
            0x9FF495B386D743C6ULL, 0xDED4CD2E160AB54CULL, 0xBE60990C30E76C11ULL, 0x84D7539AA5B7ADEAULL, 
            0xB75B3FCB068FA633ULL, 0x324D6726EB0A0AECULL, 0x25FAF4AB0626D73CULL, 0xFEF021CD2C9E6768ULL, 
            0xDA407F9DD15857B5ULL, 0xEB73BE928B749994ULL, 0x1F9C5B4CEA836270ULL, 0x00CE99A5021B50ADULL
        },
        {
            0xFEB5D50A25C14461ULL, 0x03878BF82350B205ULL, 0xE3113017E9761D67ULL, 0x1A5C8D70B79800B0ULL, 
            0x90E2D6A5934290F6ULL, 0x789C8C305FD9A8EEULL, 0x13727446905EA4ABULL, 0x270B5BBBDE6BCF72ULL, 
            0xDF798C6F67DDA890ULL, 0xB90E4CD1D3EF0285ULL, 0x503A0746FA098FD3ULL, 0x26B6BED21E69A421ULL, 
            0x4B5732B539DBDBDDULL, 0x5A795B4454C275F3ULL, 0x366671A9C49C2206ULL, 0x0D03E1B902E88F76ULL, 
            0x192A2EEA70D7DED7ULL, 0x00AABF9E13F3C901ULL, 0x8B3CA2F1A1BFFFD1ULL, 0xDC6998C4BC38C311ULL, 
            0xFC66EFC44865E035ULL, 0xD0116AC0F7BCCEF6ULL, 0x87DF03D5CCCE0748ULL, 0x36ED91E158B0EEECULL, 
            0x701D6AE589AC3FFBULL, 0xCB1514E6ED6A38EFULL, 0xC116376A73FA305CULL, 0x0FB86F1FB490F873ULL, 
            0x03521CDF1DA2BB13ULL, 0x739173D2877D4EC9ULL, 0xB5F6BB94844DED54ULL, 0x7EEB003EF9871C12ULL
        },
        {
            0x4B46CEE6E8D72D7EULL, 0x9197B24920699496ULL, 0xDC4F731D5D7E5E91ULL, 0x9A99D60A84500016ULL, 
            0x93385776E843E52BULL, 0xDD84ABBB3CD0E1FDULL, 0x0DF842A386EE6460ULL, 0xDE78C28AF5A495F4ULL, 
            0xF29EDBAE9690BB7CULL, 0xA97079D3264BC7FBULL, 0x3F2B65C96CEEE29AULL, 0xAE9310E745641657ULL, 
            0x0B035E1DEA7337F0ULL, 0x4E3F9922EA63A3C0ULL, 0x0115A57D3D037F0CULL, 0x724E7716B63E97FBULL, 
            0x4BF6DB0F91B9FA4BULL, 0xB8F85A4C4B375FFFULL, 0x81F2CB12652278C3ULL, 0xC40176D0782A6E1FULL, 
            0xCAA15207EC9D0369ULL, 0x53087F460736D644ULL, 0x21262D1C74EDD780ULL, 0x6008121E9323F8B6ULL, 
            0x518C8FB01A9221C0ULL, 0x0B65845464FB5625ULL, 0x8A08CBE52696D192ULL, 0x6859AE93C22B9E38ULL, 
            0x1777A0750AAADF1BULL, 0x5249FCA9BE80FE0FULL, 0xDAA72E786DCDF2C8ULL, 0x245D86A0D432EDF1ULL
        },
        {
            0x14FC300932DFE63AULL, 0xC9A759C3E1A50DD7ULL, 0x6269374AAE15168FULL, 0x9A39C566CB15710FULL, 
            0x696A7D1EB9607A07ULL, 0x4E6B84A0D654DD12ULL, 0xEB58956C197961DCULL, 0x4876FA4B895C850BULL, 
            0x2728F81AD8A76282ULL, 0xE3AFA5D0C60883C3ULL, 0x53358ED98DA2109AULL, 0x53180CBFBB414E8BULL, 
            0x41C71EEF0F00C5FBULL, 0x0AB6E609D8071888ULL, 0xD4784DB4A9373063ULL, 0xA52E563EC8F50331ULL, 
            0x386FB517B3968362ULL, 0xF18FE3E0B422F61BULL, 0xB7B091775F187640ULL, 0x1D72692BF404AE7CULL, 
            0x1361FC313C30F315ULL, 0xAF89B84378ACB5A3ULL, 0xBEEBCA17D16C7B67ULL, 0xC38206F670FF6BD3ULL, 
            0xDD9E0A59D7579049ULL, 0x5275F26558C919E0ULL, 0xC2333C45BE5E30D8ULL, 0x6857A4174B6A72E1ULL, 
            0xCE10BB8B6D24537AULL, 0x142D500D4BD48F13ULL, 0xD4D789BFE54D3CD5ULL, 0x11BBC4E660B28FF1ULL
        },
        {
            0xC807206C753FACC3ULL, 0x2DB8DE056EEB3F12ULL, 0x3A2425707569AFC2ULL, 0x7B23FEA5C643F839ULL, 
            0x1239F674EA985DFAULL, 0x96BCE221E44888E3ULL, 0x7C9C9CAB686504E0ULL, 0xC7BB1DDCFABBD8E5ULL, 
            0x85351570C13A6A44ULL, 0x6CD9EB85AC5A4A9FULL, 0x3BAC9F8D701A2FBAULL, 0xF515F2D838E6F50DULL, 
            0x33C4969208E80190ULL, 0x52966575795F820BULL, 0x9159D54430D4FB0FULL, 0x31E669F34880E508ULL, 
            0x4FAD42ACB75B6119ULL, 0xAFEAA17F2484D1B7ULL, 0xE076E2AFB8628896ULL, 0x79FBDAF719117784ULL, 
            0x4F4ED4C98B7BB583ULL, 0x462EC040DEA01431ULL, 0xD049C41C2197CE24ULL, 0x7B7527434FDBF0D8ULL, 
            0x085C41BFB8426597ULL, 0xD5DB75D13BDC1666ULL, 0x94A848A2BE6C176FULL, 0x650C71D2E8FF87E4ULL, 
            0x66890CC005881049ULL, 0x6038133FE2CD3124ULL, 0x90DE0CE29AA86877ULL, 0x6C5F0F2C4F0176FFULL
        }
    },
    {
        {
            0xC787167EDF01CA1FULL, 0x2BB8D51D76CF9168ULL, 0x068B727D6031D19CULL, 0xCEE06ABBB36FE262ULL, 
            0x6082E45EF78B8946ULL, 0xA2AF4F20EA7F93D4ULL, 0xDB0F450B854BD1E3ULL, 0xA3346B8FD464A5A2ULL, 
            0xD6CFB9ECD45C8421ULL, 0x9237C67E97B7A047ULL, 0x86F124D8DAAF31E8ULL, 0xE6EC829CF06B65FBULL, 
            0x56690148B468FCF1ULL, 0x9DDB797B35E2CDFDULL, 0x9AD830293E0C744DULL, 0x3B513B7FE615AE36ULL, 
            0xC3D7666108BD9D8AULL, 0x18D625304560D5FAULL, 0x2E85223FBA7FFF01ULL, 0x19D486593D97CDDCULL, 
            0x8E8D4E45C8720CFBULL, 0x869E68B65C630BF3ULL, 0x6CEB13A6F8455CB0ULL, 0x9D4C99B5B80539F5ULL, 
            0x7964EF9A225BBFD4ULL, 0x69107B1B571C2912ULL, 0x7EDCD0BB1C861B07ULL, 0xEEEF508A1B6363D2ULL, 
            0x6B2C43790B20AE5CULL, 0xF784D6D923AD6E34ULL, 0x0B19317F9086B6CBULL, 0x4FF9F20CC3B0DC6CULL
        },
        {
            0xBCD6171AED51B4E9ULL, 0x8B2F4512F8DD53DDULL, 0x01830DA0836017DEULL, 0x998A178458AACD47ULL, 
            0xE2CF41B072ABD70CULL, 0x77189AF96BAFED0BULL, 0x59B4471B2E5BEB59ULL, 0xFB2DD6A3BEEB0007ULL, 
            0x0E233928F959474AULL, 0x50E21AA67C3D6536ULL, 0xE98A184288542D0DULL, 0x6A41237CD869D67DULL, 
            0x75F71A37A4FBE888ULL, 0x99F87CEA73F6A44FULL, 0xAA0F8DA5500BA4C7ULL, 0xDB643BB932D577D7ULL, 
            0xE59CE52E77376243ULL, 0xF40D4CEA105ADBD7ULL, 0xF28E79607B97EF46ULL, 0xE4D8BED23F9441BFULL, 
            0x7514FAC12D989139ULL, 0x0CEE210B6E9A97D4ULL, 0x7C61865ACFBE380CULL, 0x855F5E1B3A838142ULL, 
            0x02C96C0A6D5FCD89ULL, 0x97D90A9DE4A55B04ULL, 0x505C87CDAC776140ULL, 0xFFDA119D428882FFULL, 
            0x6FFBB346500664BEULL, 0x0C77A12B271EE0D3ULL, 0x721BEEB8D24439B2ULL, 0xFDC1655AE90517D3ULL
        },
        {
            0x7A37843D7A79E722ULL, 0xF1172E527660C662ULL, 0x31912699BBE5C3BEULL, 0x373D013C9B654889ULL, 
            0xB71B4A5AC2E54B08ULL, 0xDBCE57EA753F3713ULL, 0x1B88987B4A1C9B9CULL, 0xE1254BB317F31ACFULL, 
            0x62CEF5FEB3102AE3ULL, 0xDDD5605A1E843D2CULL, 0x3F5116E3B3889365ULL, 0x4837C76DD5094848ULL, 
            0x97A1D45B835E4F5FULL, 0xF0608732E41F3C10ULL, 0x5ACAC91FA9085AB0ULL, 0xFCF38324E11B7F53ULL, 
            0x4AEF572B2986787CULL, 0x9DBDDFE96595FEACULL, 0xFE79F48B3455C74DULL, 0x392B6C87CF66C5E2ULL, 
            0x22C154C4B4FB5058ULL, 0xA3BE41719D4317ECULL, 0x53385E0365013F50ULL, 0xECD244188BD13737ULL, 
            0x6413B6BFC7215C16ULL, 0x6EBBD18F42BFCA6DULL, 0xC7130C7ABF367646ULL, 0x72E36A27649C507BULL, 
            0xB47295DA1102D9A4ULL, 0x92764827048C21D8ULL, 0xE0FAF346BA7D543DULL, 0x64F38C77691B9F15ULL
        },
        {
            0xB2F512E694B0213CULL, 0x5402C16048A82158ULL, 0x10E26B676C13798FULL, 0xCA5885B30B62F764ULL, 
            0x4094C501F6078562ULL, 0x08BCB62E32612BF1ULL, 0x98635083806B2627ULL, 0x2BE5FCDF05E45AD7ULL, 
            0xC3EB8CA47DD02402ULL, 0xC9A675AA54E14CE9ULL, 0xB6B521563DEB8EDBULL, 0x142EF216061C5031ULL, 
            0x9576C129EB3451A9ULL, 0x368BBE2C15559286ULL, 0x62F84F7664629B7AULL, 0xB878768E9E4161DCULL, 
            0xAD816DFB0144CECAULL, 0x2C4E3A18B4467854ULL, 0xA72749AC3870702DULL, 0x4D04C7EAB38BE699ULL, 
            0x1ED8DFB15FE037E3ULL, 0x6C60EB97DBE6796FULL, 0x65CE231D2AFB5A31ULL, 0x0F2F2EC9138DA085ULL, 
            0x0FE456021689014EULL, 0x39C6A4F2C4F1A62BULL, 0x59FCDEE847D303F0ULL, 0xC5D463829FF24E12ULL, 
            0xDBB6DCBDC740E346ULL, 0xE6A1D4527E7FAEDDULL, 0x02E97E24F48BEA15ULL, 0xA06C8C2FAAE31CD8ULL
        },
        {
            0xA305E7CF1DE8B681ULL, 0xF47AA8850DAA73F5ULL, 0x6C1F86513A3F7F41ULL, 0x840DA29D33DF11E4ULL, 
            0xDEE65014AC3511A4ULL, 0xA29C48F4E4039D27ULL, 0x27444067D5D14094ULL, 0x75D92F13CE4CD639ULL, 
            0x9FBF3B9EC263ADC0ULL, 0x71BCE4EAE3A058B8ULL, 0x350463BE8FD9BB03ULL, 0xF1533A0F512EB4B6ULL, 
            0xF3E27AA9EE996DCFULL, 0x02B114C33F9BF5E9ULL, 0x7CD456D46CA4231EULL, 0xACC7871C7B43BEFDULL, 
            0xD92AF13FB51C1C8EULL, 0xBEB8F8E7A16FB48AULL, 0x07CE0DAF98CBFC87ULL, 0x6D83016772E8EBA2ULL, 
            0xF6E612D1BB01E2B5ULL, 0x0D0685A45BF0DF08ULL, 0x95A98E4001F6499BULL, 0xE9AEB90D1A7FB4DDULL, 
            0x9B446B22F02DD990ULL, 0x063E03267E3EB156ULL, 0x196D8F18B3AE8FEDULL, 0xAF37766AFFD7E309ULL, 
            0x9178398E756BECC6ULL, 0x6300569C41467227ULL, 0xEC659DCC27C79B18ULL, 0x8181BAACE5C7AE9FULL
        },
        {
            0xDD923490F2586769ULL, 0xFD276319959E4474ULL, 0xD1E0759C598F037CULL, 0xAD6F0DBC07E8594CULL, 
            0x0AE327634AC5959DULL, 0x6D127699DAB3CD72ULL, 0x9BC880868295C4F8ULL, 0x62CB9848963EAF60ULL, 
            0x49D63E7492E6BC68ULL, 0x26E437C9D3A1D95FULL, 0x9126368C47075AF3ULL, 0xBF0B2768C26C3F03ULL, 
            0x46B9AAEE0D211E57ULL, 0x9ABF52ED7732F6EFULL, 0x0CB6F3FA9051D173ULL, 0x076155733D096F83ULL, 
            0xCA09C2C0E2A30814ULL, 0xF712F6B2C2D0E640ULL, 0x2785EEDDBA222871ULL, 0xAF1F013649AE346DULL, 
            0x2B265CB17BA7FB71ULL, 0xA68755F1446B4D69ULL, 0x2A647C263593A6D9ULL, 0xBBDF3035B241C6A0ULL, 
            0x5D2DC172ED820464ULL, 0x14D6132B1ED38509ULL, 0xD30E8B684F087F3FULL, 0xC663AAEC71D96EC4ULL, 
            0x1D89182BB7BD040BULL, 0xC256FAE2C0C97162ULL, 0x5D4BBB7C76706870ULL, 0x5335B18C12BF1CA9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseHConstants = {
    0x124F2499B18C8940ULL,
    0xAA6EB95B33042B0CULL,
    0xFB6B236872005CB1ULL,
    0x124F2499B18C8940ULL,
    0xAA6EB95B33042B0CULL,
    0xFB6B236872005CB1ULL,
    0x218B76E31EDCA1E6ULL,
    0x2E5B5B01134D6FDAULL,
    0x04,
    0x3F,
    0xAD,
    0x21,
    0xBD,
    0x16,
    0xB7,
    0xEF
};

