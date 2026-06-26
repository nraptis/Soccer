#include "TwistExpander_Boxing.hpp"
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

TwistExpander_Boxing::TwistExpander_Boxing()
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

void TwistExpander_Boxing::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15695370705539458533U;
        aCarry = 18081013021884422077U;
        aWandererA = 13540416783640993137U;
        aWandererB = 11108380898221077638U;
        aWandererC = 16773663110298846727U;
        aWandererD = 17051574481058224328U;
        aWandererE = 9545752564807128299U;
        aWandererF = 10959210015527251971U;
        aWandererG = 9526256796976535100U;
        aWandererH = 16672941903549104859U;
        aWandererI = 16893629645928859724U;
        aWandererJ = 16288730229531171046U;
        aWandererK = 14542198711026195973U;
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
    TwistExpander_Boxing_Arx aArx;
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
    TwistExpander_Boxing_Arx aKDF_A_BArx;
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
    TwistExpander_Boxing_Arx aKDF_A_CArx;
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
    TwistExpander_Boxing_Arx aKDF_A_DArx;
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

void TwistExpander_Boxing::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16741651878947775257U;
        aCarry = 11193248167010523532U;
        aWandererA = 15958059253689991663U;
        aWandererB = 12085428949219941179U;
        aWandererC = 13874155269615557087U;
        aWandererD = 17838953035918450573U;
        aWandererE = 15489902980887814722U;
        aWandererF = 13672576472306043392U;
        aWandererG = 13354450370663072613U;
        aWandererH = 12466047787268830737U;
        aWandererI = 9985682485456605465U;
        aWandererJ = 10618557070731595475U;
        aWandererK = 13883237537927205833U;
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
    TwistExpander_Boxing_Arx aKDF_B_AArx;
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
    TwistExpander_Boxing_Arx aKDF_B_BArx;
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
    TwistExpander_Boxing_Arx aKDF_B_CArx;
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

void TwistExpander_Boxing::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneH);
    }
    // KDF_B PhaseA invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseB invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneF);
    }
    // KDF_B PhaseC invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseD invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseE invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    }
    // KDF_B PhaseF invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseG invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    }
    // KDF_B PhaseH invest aInvestLaneA (end)
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
    TwistExpander_Boxing_Arx aSeed_AArx;
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
    TwistExpander_Boxing_Arx aSeed_BArx;
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
    TwistExpander_Boxing_Arx aSeed_CArx;
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
    TwistExpander_Boxing_Arx aSeed_DArx;
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
    TwistExpander_Boxing_Arx aSeed_EArx;
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
    TwistExpander_Boxing_Arx aSeed_FArx;
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
    TwistExpander_Boxing_Arx aSeed_GArx;
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
    TwistExpander_Boxing_Arx aGrow_AArx;
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
    TwistExpander_Boxing_Arx aGrow_BArx;
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

void TwistExpander_Boxing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Boxing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Boxing_Arx aTwist_AArx;
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
    TwistExpander_Boxing_Arx aTwist_BArx;
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
    TwistExpander_Boxing_Arx aTwist_CArx;
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
    TwistExpander_Boxing_Arx aTwist_DArx;
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
        TwistExpander_Boxing_Arx aGrow_AArx;
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
        TwistExpander_Boxing_Arx aGrow_BArx;
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

void TwistExpander_Boxing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 3 with offsets 6157U, 4536U, 4204U, 5661U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6157U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4536U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4204U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5661U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 0 with offsets 5179U, 5882U, 371U, 5077U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5179U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5882U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 371U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5077U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 1 with offsets 6179U, 1041U, 3254U, 5168U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6179U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1041U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3254U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5168U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 2 with offsets 1693U, 6533U, 7847U, 7895U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1693U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6533U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7847U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7895U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 1754U, 576U, 1469U, 1083U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1754U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 576U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1469U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 0, 1 with offsets 432U, 1450U, 95U, 586U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 432U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1450U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 95U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 586U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 1, 3 with offsets 297U, 817U, 288U, 676U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 297U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 288U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 676U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 3, 0 with offsets 1243U, 1403U, 1265U, 71U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1243U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1403U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1265U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1355U, 1572U, 1464U, 1261U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1355U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1572U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1464U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1261U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Boxing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 3 with offsets 147U, 4410U, 1692U, 3266U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 147U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4410U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1692U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3266U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 0 with offsets 1223U, 1155U, 1529U, 5376U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1223U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1155U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1529U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5376U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 2 with offsets 855U, 7196U, 2687U, 3805U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 855U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7196U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2687U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3805U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 2, 1 with offsets 3528U, 993U, 7651U, 4499U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3528U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7651U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4499U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4493U, 4964U, 6995U, 184U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4493U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4964U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6995U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 184U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 0, 1, 3 with offsets 62U, 2007U, 175U, 1919U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 62U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2007U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 175U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1919U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 3, 0, 2 with offsets 77U, 2007U, 521U, 659U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 77U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2007U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 659U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 0, 1, 3 with offsets 297U, 1743U, 1386U, 1743U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 297U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1743U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1743U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 0, 1 with offsets 990U, 912U, 1729U, 1959U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 990U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 912U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1729U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1959U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1394U, 681U, 1639U, 235U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1394U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 681U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1639U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 235U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseASalts = {
    {
        {
            0xB08CC8274F714B1DULL, 0xECCEB07584D31F60ULL, 0x9FDA9F130728C77FULL, 0xF73EEA37AD57FB06ULL, 
            0xF8B4FD6DBD004037ULL, 0xF844E6CCB73F8A00ULL, 0xF448CE23EFD06EB9ULL, 0x2C9B9FA3D130A2E3ULL, 
            0xEF40232BCA2554B0ULL, 0x0819CBBA614135CFULL, 0x880B6B87AEF31CB2ULL, 0x20E1E92493C786FFULL, 
            0xD14D8DC8D5BF7E27ULL, 0x2A0228E30212DA55ULL, 0x9A0A1BD10756521CULL, 0xC309A4866C1DDE2BULL, 
            0x87E068A282AA51A3ULL, 0xE2A2A7DBA01EE74EULL, 0x83D5F71DF11BAC9FULL, 0x08AA23223075B8CAULL, 
            0xE51D41B3599316C7ULL, 0x222BB3B72433F165ULL, 0xED5DB26177362405ULL, 0x0CA5705ADE0D5AC7ULL, 
            0x4A66329C5F6BCD27ULL, 0xC5BFD48DDD19AEB1ULL, 0x4236B6156B43DC81ULL, 0x35F552EDC0704710ULL, 
            0x88BFBD7F1A005EF1ULL, 0x8923D2D20ED0D459ULL, 0xD9B77970BC2B0829ULL, 0xDCB52698196622EEULL
        },
        {
            0x5264EA18756B51B6ULL, 0x9FC5A25EA57EC0A1ULL, 0x3A80FA7D6C33F913ULL, 0x3151E208066067C8ULL, 
            0x45FB6816EC1029BEULL, 0xF50ABA4505ADF986ULL, 0xC97DD5201C039D2BULL, 0x6FFECF27ACA7C9D6ULL, 
            0x1383ACB20C5B68C8ULL, 0x570AEEE5A3DBB29BULL, 0x2EC455D44E8FE5F3ULL, 0x5B6961E973E8A9C2ULL, 
            0xEACA0C6349411E23ULL, 0x760A95035FF256A4ULL, 0xA01641CE9C8447CBULL, 0x21B59BD5AD288F27ULL, 
            0x5E4EFF150B8C658CULL, 0x6B19070FFDBF2C83ULL, 0xD4403EC41DA83472ULL, 0xE2D4EFF05302A46FULL, 
            0x772607E94152A943ULL, 0x9C0F2A43933247DFULL, 0x5229E2DABED01E08ULL, 0xA3E749E4EABD5F9BULL, 
            0xBDAA8A8D381D57A3ULL, 0x055F2F4A4DF862AFULL, 0x7E5BEB4551B25648ULL, 0x4AD8C93AC6F905CDULL, 
            0x37B80EBAAAB192F6ULL, 0x5BF008A16F7D6119ULL, 0x5658E83F03FFD69FULL, 0xE3889CEFAD653ACDULL
        },
        {
            0x33FD8A939922B7CBULL, 0xA9585FA5EA875D35ULL, 0x1179760B01FFA503ULL, 0xF6C88835F7E3DE02ULL, 
            0x4879DF55C15EC332ULL, 0xADE4AACC1939B6B9ULL, 0x5D45216425813357ULL, 0xA56BADF7A5D5050BULL, 
            0x13EAF01B10FF811EULL, 0x72BD085B0F583E79ULL, 0x379BFD7B0D3BCBE8ULL, 0xD31D2E27C90D8E5DULL, 
            0xA5F0D197EE5780D8ULL, 0xCC8982E4C89682A7ULL, 0xA7CBAE14B6BEC157ULL, 0x7B457AA6DE515F43ULL, 
            0x6F3E5FB7FB73E396ULL, 0xE6FE4B64F6AB66E0ULL, 0xB0DCD183A3CD73E8ULL, 0x7F68CB9D17ED3B76ULL, 
            0x3CC0957D6C0BBB7CULL, 0x607FBE5AF5F474D2ULL, 0x184B4F081BEAD3F2ULL, 0xDA6C0998636021DAULL, 
            0x9BD90B3C04AAD3DDULL, 0xF0F3E2857D44D2C2ULL, 0xD9C7565F8BE8EDA0ULL, 0x628A257651889EEEULL, 
            0xA413ADB2B13F76CFULL, 0x259ED1E4946BF7C1ULL, 0x7CFA8B75FA5AB3FDULL, 0xB79A1C80371C6D8EULL
        },
        {
            0xB296E1D00FF59410ULL, 0xC67B46ABE168E5C2ULL, 0xE30F911129EABFD8ULL, 0xEE33C2BB08CF1B4DULL, 
            0x7D7148E43B8814DEULL, 0xB3CE0E3DC433BAFFULL, 0xF5B0AF5E38D5A693ULL, 0xA294A62FE23AB735ULL, 
            0xADA8B92969339D8AULL, 0x71B263761BEC3910ULL, 0x9EC77E1DC52FC568ULL, 0x5382457ED6C9FD15ULL, 
            0x4FED299257CB0957ULL, 0x52A6BEC9BC5914C0ULL, 0xB8E274A23AC1B220ULL, 0x8150F130A7F2D20FULL, 
            0xA840E087731486B3ULL, 0xD59A18779CFBE696ULL, 0x0A547BA0D766ABC8ULL, 0xB9645FDD60B11DC8ULL, 
            0x67E03E424E46FA29ULL, 0xC72A37E8FE22E9F5ULL, 0x67BE097FD1117F19ULL, 0x27EADF534CB8C11AULL, 
            0x0D7D0614A0DC6ABCULL, 0x1A9A442C3959751FULL, 0x6B09FE62A8DDFCBEULL, 0xDDAA9706D5BCC467ULL, 
            0xCDBEC7D309D26BBBULL, 0xB98354B0A45595B3ULL, 0xE426370684DFFEDBULL, 0xC2BF788BC8D526F2ULL
        },
        {
            0x3F6395678D62A587ULL, 0x3E4ACE21C772E034ULL, 0x43924C7396F341A0ULL, 0xA6FE1D875D5B7D2EULL, 
            0x8BF7683EFE1691A3ULL, 0x7BC02E6D316AA92EULL, 0x62202A4BCF91C1C7ULL, 0x04CF7784203775C4ULL, 
            0x54E000DE0BF294B9ULL, 0x82D745757113CABDULL, 0xE505FC80C1D574C4ULL, 0x405A64503532EE4BULL, 
            0xB3B137837B3B045FULL, 0x4B67F5C59ABD18F7ULL, 0x301484992B8C902FULL, 0xC61E8D8EAAC54576ULL, 
            0x885CFB2D2A57E544ULL, 0xD569C60C07356119ULL, 0x50CC16630956F7A8ULL, 0x0481CB1E2963C15FULL, 
            0x159C2C3598AC6442ULL, 0x678F1627454B23C1ULL, 0x80701C8C03D1C580ULL, 0x86C5470984BC6D8DULL, 
            0x4A3E8BA4E70D570CULL, 0x977E4345869A9553ULL, 0xBF9BA6D042985115ULL, 0xBB892975E60BA0AFULL, 
            0xEBDAE97D3A3147CFULL, 0x7CA99557A4A9B303ULL, 0x12E95177775A515FULL, 0x4E6EE834A08B536CULL
        },
        {
            0xEE47D87A33670082ULL, 0x50F98E3B6612C14CULL, 0xC957DBBF9FAEBFF6ULL, 0x2DA27CF3A2374294ULL, 
            0x80F3E33482C2D73EULL, 0xFFF56D25F3C829E4ULL, 0x37DFDF911A35E788ULL, 0xF36DC8F3F254F02AULL, 
            0xF6CFC3EAAB8A5084ULL, 0x109E66AEA59C77DBULL, 0x5EDE635FD8B4D141ULL, 0x3AE1FF4E035BB55CULL, 
            0xE985B83AE41681F4ULL, 0xC027798949822C8CULL, 0x08159861AC3FDDCDULL, 0xD6AD41DFDC4A8EA1ULL, 
            0x8CE8F28272C895F3ULL, 0x34023FEB6EED4900ULL, 0x1B2FCE93D3EB8729ULL, 0xAF4453E0E4EE6D75ULL, 
            0xA9BDEFD1A4D9C479ULL, 0xD9476CFAD8A1E5EFULL, 0x704FC87E9E8CE14FULL, 0xA96A15BC37379729ULL, 
            0xF29DEA85C8DFE362ULL, 0x5B215536AA75525CULL, 0x61096734CA71AA5EULL, 0xA5BF21543C99AD7DULL, 
            0xFEEF2C46FFDD8510ULL, 0x31512971779FFD05ULL, 0x4F3FC4E3981C2C4EULL, 0x39E0B30B41E3176CULL
        }
    },
    {
        {
            0x9BC7B92EB9DBB21CULL, 0x4A423D5338EEB4BDULL, 0x6A3C2860D4EC633BULL, 0x2149314C0CA07E57ULL, 
            0xF89CFA91395AB02AULL, 0x4986BA3CB57E6A4EULL, 0x87D962F4F217BDF8ULL, 0x3E9DDC9363241F94ULL, 
            0x468F198E3CEA3CE0ULL, 0x4308B06CB836E9F8ULL, 0xA169A50797F4763CULL, 0x440682C5D1BBE3F5ULL, 
            0xD11FC062B922FA2EULL, 0x98C5962A9E922CCFULL, 0x89427C2CBB1FF8C9ULL, 0x62956A27DB9F1B5CULL, 
            0xCE21B6E7FA003B3CULL, 0xCFAF8A56B37B9839ULL, 0x8C64FC937DA527C9ULL, 0xDD2A4ECB297EB562ULL, 
            0x1A79871F5FA5AD11ULL, 0x4EA2BBCACA454997ULL, 0x1B1DA4C6844271DFULL, 0x3DCE2724BFFEABE1ULL, 
            0x243E739E5D598FB6ULL, 0xA6D2CEFAD2E5CD07ULL, 0x052317C54F63140AULL, 0xB0C33459BEFF9315ULL, 
            0x0B23A92D1DD55E31ULL, 0x54EBC72BCAA3622FULL, 0xB855E5A6388462C0ULL, 0x6C5B7E3A1F3878B9ULL
        },
        {
            0x9051E673DED64BA6ULL, 0x1A185334A7537381ULL, 0xA7354F8831BAD4B5ULL, 0xA69012705B3953A6ULL, 
            0xFCE60ABBA5730670ULL, 0x7C2CDEFB8EE0850DULL, 0x1B19CE132CBBF300ULL, 0x29785E9C24AF68E4ULL, 
            0xF0E80890528E0F80ULL, 0xBFD144C333B55408ULL, 0x97FE62A256D8DF42ULL, 0xBE929EC6381808EDULL, 
            0xA69A507AE8180EE2ULL, 0x3593D9612D1CA455ULL, 0x95EBDC584B7B727DULL, 0x2E1AAA4C183B510CULL, 
            0x1C3EB9EDC7D200A4ULL, 0x39BE4B38E235AC34ULL, 0x826FA184705EBF29ULL, 0x328C53EE43AB481BULL, 
            0x4679164BB0A48049ULL, 0xB8063128611D8237ULL, 0xD7D2C371547C7623ULL, 0xCD2AC00D0E5CB87FULL, 
            0x5535D33EFB9ED501ULL, 0xBF48FDB901C81BBEULL, 0x5D20E8EB135A26BDULL, 0x64D253F02FA2C739ULL, 
            0xD2C48ACF72AB9310ULL, 0xCAE0612E064C62FDULL, 0x8CBA7B469A6ADA55ULL, 0x966500DBD7AB932AULL
        },
        {
            0xD771BA28C57A8946ULL, 0xDEF8247B46802613ULL, 0x058B5D4D64BD19EFULL, 0xB19705E78647B226ULL, 
            0x99B21C01F5DF08CAULL, 0xA6AE755A2E3B0918ULL, 0xD111FE53F296A527ULL, 0xF571FAFA7E77FC82ULL, 
            0x90DC9722EC651475ULL, 0x572705043F5C2517ULL, 0x4B4E761E4251A187ULL, 0x34F90990FC959F45ULL, 
            0x03A42B3516F25D82ULL, 0xCEF9586237405F81ULL, 0x8BFD5AD64FC046DDULL, 0x25BAE6CEAEB481DBULL, 
            0xC105808BA8C598C0ULL, 0x9545F8BEA05BE28CULL, 0x554BB4DAFAEB95DFULL, 0x66360DDB8350BD63ULL, 
            0xBBB0D6B7AF89E202ULL, 0x0B7338B9B45EE093ULL, 0x64D09D75B7D43038ULL, 0xE725A3A1AF455880ULL, 
            0xBCF536B2139B6EBDULL, 0x049F8D9A2551E773ULL, 0x40B126420A79B11CULL, 0x24F4A4C4A2519C5CULL, 
            0xD7B7B84A0141F405ULL, 0x9A52B8B5BA844165ULL, 0x3C6AC28B1301DBA9ULL, 0x1D0F3DE84C601CCAULL
        },
        {
            0x52AEFB7B65E753A3ULL, 0x9C7C6D8F786186F0ULL, 0xA70672DCD67378CCULL, 0x7C5EA56043D74138ULL, 
            0x0F249C21C9F315E3ULL, 0xD7394EE20AA11D47ULL, 0xAAD301516C63D028ULL, 0x37C6CA90785B483CULL, 
            0x1DF9D9557C2F1D88ULL, 0x2C80B3C182B5C2FDULL, 0x15664559BECEB71CULL, 0xF7EF59367717BD77ULL, 
            0x7E05B5B6825BFB95ULL, 0x3C005587F5F5B70CULL, 0xB5792D309D7B8595ULL, 0xD7A7C4BBCE7DC095ULL, 
            0xCBABF529C6FEF0B6ULL, 0xA93FAAD4695AE482ULL, 0x9F324490635F130CULL, 0xEFB471755B76DC03ULL, 
            0xEA33C5AF7546A8A4ULL, 0xDDFCF8955445E0E2ULL, 0xC6A741F4724E229DULL, 0x933A767F54048206ULL, 
            0xB98BB18EA5BBC5BEULL, 0xACB991F7FF15DA45ULL, 0x4B36436D1FB8CE80ULL, 0x949F54F388E1488DULL, 
            0xECB5D8554CF39871ULL, 0xAA00B85A1EFDD446ULL, 0x81C7B1060B71D1C6ULL, 0x0A37340D488AAA27ULL
        },
        {
            0x617546A108245BBBULL, 0xDA1471A38789A633ULL, 0x785BB72001A05A77ULL, 0x720ED28837623682ULL, 
            0xBFFF282E60501922ULL, 0x6EFA4E2082208BACULL, 0x47E82B97DA52DD12ULL, 0x3DE68597C5F60A39ULL, 
            0xF1A3B46832CE710AULL, 0xDBBDFD45FCAB84AFULL, 0x7D78C7941AA3CDAEULL, 0x973EB8152EA2D41BULL, 
            0xC54DAF65A57F1741ULL, 0x8A7032A945140573ULL, 0x11B304F3D7197D25ULL, 0x728A9F337025D98BULL, 
            0x6B1EB3AAF49ED6FDULL, 0x77043ADC69F9F0B8ULL, 0x0B2561F4C46D0202ULL, 0x2D509D95F694B282ULL, 
            0x92B4BADDF8EAAAA7ULL, 0x17C86336C2C36D80ULL, 0x97F950C278ABB69AULL, 0x615EE8AAB89BBD30ULL, 
            0x564C6C19B18DB750ULL, 0xC35FC6AA548085AAULL, 0x581F353FAB1228AAULL, 0x0E4CBBD036694E36ULL, 
            0x313E27C9F9C3AF34ULL, 0x032EEC4D739DA481ULL, 0xC00EF9084815D1ACULL, 0x3B31D37BFA375536ULL
        },
        {
            0x79EB3145A4E3D790ULL, 0xF4345B12D04523CEULL, 0xDF1A7F0B68960872ULL, 0x9D3C263D7E5FB855ULL, 
            0xA353AA0527C7F5BAULL, 0x1F024F19E80E9420ULL, 0x4C087978400F8B50ULL, 0x1A76EA3E769D597FULL, 
            0xA49714C0D65997DEULL, 0xFE7F53C50BED574CULL, 0xA440580687F4F42AULL, 0x760A651EACB1DAD3ULL, 
            0xEACFD5E081DA60B2ULL, 0x7B1D23325B87E551ULL, 0xD4DFFAB555E40823ULL, 0x3D385FA253BED262ULL, 
            0x2C87C9426034AADCULL, 0xB5E40B1290EE6BDFULL, 0x0791EF35DEBD3BFEULL, 0xC50E4C43DAB1928DULL, 
            0x4BFA16A54431B6C9ULL, 0x51BC65FFBC0E9630ULL, 0x5A8378D21EF57EFCULL, 0x325C55266334C090ULL, 
            0x4F98E3ADCA743728ULL, 0xEDFAE84ADBA3ABF1ULL, 0x1387EBCBFF64D703ULL, 0x33B390E2A3A21E2FULL, 
            0xD2A79C7E6F60DAFBULL, 0x211404A35922616BULL, 0x2301F08896D9FC1CULL, 0x64CFB4CC79888976ULL
        }
    },
    {
        {
            0x0E463342C3914734ULL, 0x65CA68A8A4A8750DULL, 0xE7D2ADF4CAB9345FULL, 0xBAB5D725CD0F997BULL, 
            0x78614203E0CB737EULL, 0xCA6EE3C24BFE87CEULL, 0x09D35234DBB30C15ULL, 0x6E1A854B3C15E05EULL, 
            0xAF822AF7E8D175FFULL, 0x3F1EEE93379F7749ULL, 0x6CC05B5FAF801FF2ULL, 0xD05DA1812DC793FEULL, 
            0x49E98CAA7BE94ED3ULL, 0x7DFBCC6BC7486570ULL, 0x74E764CC4563EDAAULL, 0x3BB4B45D9787F91AULL, 
            0x15D701A39855D16BULL, 0xE377494D670A35F9ULL, 0xF65F0957FEEC4E92ULL, 0x22EF0A14DC70ADB9ULL, 
            0x5ADCC2EBBBEFE127ULL, 0x8261C903ADFA8201ULL, 0x20D92FD0A88810EFULL, 0xA423F76F3D52DBECULL, 
            0x5C438FAA605957CBULL, 0x77C96BA3B257E559ULL, 0x501E7336028B8034ULL, 0xE6CC9D08DE5BF0A6ULL, 
            0x00A39EAE838FFEF2ULL, 0x05B4F085EAE8AB97ULL, 0xE00307B32BB68E1AULL, 0x1B7FA8C21897FECFULL
        },
        {
            0xEF6A9DCF17F7DC6CULL, 0x58B167837C2FD56EULL, 0xBBED534DD1275607ULL, 0x253F2C1278D22389ULL, 
            0x711CFA6D912223FEULL, 0x716130946347BE55ULL, 0x461D9434ABB598C0ULL, 0x6C09B8F525EC50B5ULL, 
            0xF59A0DCC6229B0B8ULL, 0xF199D0E01D2B637AULL, 0xA6EED646D2E28085ULL, 0x28E0964AB6351EBAULL, 
            0xCA9BB6DBE3AF9BEDULL, 0x8926844699A0C812ULL, 0x38B6FFC98D1F3086ULL, 0xEE17C9A9BCB29FA6ULL, 
            0x83FA85FECAEB8267ULL, 0x7836D650B6EF6F7BULL, 0x53860685AB388615ULL, 0xA29BA7E8BAC2019CULL, 
            0xDBF5FDDA722C1447ULL, 0xA02CF221286A3769ULL, 0x05527C88B0A2AC1FULL, 0xE10F44A96176CC67ULL, 
            0xFA2C11E7EEDB7832ULL, 0x739EE40C0327B4D2ULL, 0xA9F2B7E7E5B2EB12ULL, 0xE31031DF2387BCAEULL, 
            0x6C11E8F21BB80554ULL, 0xBA816E2F2E21480CULL, 0xA20DE766DA3D1533ULL, 0xAB9EBBF304448951ULL
        },
        {
            0x4DEFD24FADD6921AULL, 0x14ED875CE69B7A5DULL, 0x65564721A54EE7E2ULL, 0xFD136304A9337B81ULL, 
            0x340ECCB3CD64A68FULL, 0xED9D1CFAA11FF04FULL, 0x7D487E6721BFADA5ULL, 0xE953B6E447E17172ULL, 
            0xBBF165ABB9465FE6ULL, 0xB2306168A09A0313ULL, 0x356435C1C6E6281DULL, 0xE026580FB38CC2A9ULL, 
            0xCAE2EA5501BEC386ULL, 0x13F1512C511ED522ULL, 0x0785DDBCE56FCCF3ULL, 0xF8E019333708571AULL, 
            0xE672D89DCE7366F5ULL, 0x8ADEC5DFE3CCFC4BULL, 0x3B2FDF3FEA60E8EBULL, 0xDFD9DA89EEC166B8ULL, 
            0xA2EBE30765193A83ULL, 0xF4905CC772364F23ULL, 0x265F204294B3F29AULL, 0xB16B4D046855BC15ULL, 
            0x9D191E69E179721CULL, 0xB32A99B8A16E5E54ULL, 0x885921DC1E568612ULL, 0x6CB01A5535BC9DFFULL, 
            0x5F1DED5EF78B9DEEULL, 0xC6A6BD2E5BFF4906ULL, 0x796C106E53DBD825ULL, 0x26C81876FA3F875AULL
        },
        {
            0xF5ADCB99C82C2FEDULL, 0xFE999DF5B483D5F7ULL, 0x198E262B82485711ULL, 0x162F29040D12698FULL, 
            0xE22D0C27A335FA14ULL, 0x886AEC7D68BEE65EULL, 0xD67F50B28559468FULL, 0x2AC0C12140BA4D63ULL, 
            0x2EA46F8287CC5F28ULL, 0xE074349E5BE0F783ULL, 0xA012E99CAD7C8A53ULL, 0xC11F69174866789BULL, 
            0xC42DAEC66098A103ULL, 0x880E3B54EF351BC5ULL, 0xB476D6280F93DF79ULL, 0x322C3492FC90D48CULL, 
            0x03042431A300CD15ULL, 0x126E46C48595A9C1ULL, 0xE917C75302B3CCFEULL, 0x9C70FB66C255CC07ULL, 
            0xB522E97434CDD2EAULL, 0xC2E1F49191A4871CULL, 0x809837DA5EC36A4AULL, 0x090BC2A5543FF57BULL, 
            0x00657CA83EF660C1ULL, 0xA4AF7B0DF064EF3CULL, 0x94BD9A9835E772F6ULL, 0x78748F03650A28D5ULL, 
            0xEA51FE669039166DULL, 0x6846984D53014A5BULL, 0x7F0A76E7A2C9B632ULL, 0x735E631938334B9DULL
        },
        {
            0x2AD8DF135E69C01AULL, 0x98C04CD499A3B7CAULL, 0x4061A924B4696436ULL, 0xFB76E38B6CBA21ECULL, 
            0xA77EDE78069EB21DULL, 0x161969F7489F5A78ULL, 0xD4CA40C9FAF77CD6ULL, 0x87BCBC0E6DA20621ULL, 
            0xC0A796AAC7ED50E1ULL, 0x49C0B458F01A6F6CULL, 0x8435D583968AE4F7ULL, 0x9502301E245B9D56ULL, 
            0xA2EF817D4861300EULL, 0x86C4BCF40CA4096EULL, 0x1E751D15F0C11F2DULL, 0xEC8A4F7B56AA853AULL, 
            0x706481D52C1D50C8ULL, 0x3A509E32BCC30254ULL, 0xE47F5A033E1E9C9FULL, 0x032F5695BD30C75CULL, 
            0xF0D6717D1568B99EULL, 0x80E4C1D91B81E244ULL, 0x220A813249364C74ULL, 0x1632F4FF3F52B729ULL, 
            0x6F379C4A2EB912FBULL, 0xCD94164E27093739ULL, 0x66D322922A89E156ULL, 0xC59DA089069E0A7DULL, 
            0x40CDD2E9945F11F0ULL, 0x7613A2597A98010FULL, 0x1524BB2B7568155EULL, 0x1B11A1D6D2D159B8ULL
        },
        {
            0xFC155A9C098217AFULL, 0xF46D831F410524F2ULL, 0x523708727A39D062ULL, 0xABDD386BE736F05EULL, 
            0x09F03EFFAACE80DDULL, 0x53CB4041CAC56A0CULL, 0x50C5C85F2314064FULL, 0x956A496EC96BA86EULL, 
            0x218E0C63933B056DULL, 0xA1CA91A1CE7A0272ULL, 0xA1538C71CCBC2BC4ULL, 0xAE2EA0368A876CEBULL, 
            0x89A13A7609CC976FULL, 0x398B9060EB39FEBFULL, 0xFA56E1A0CA0D251EULL, 0x95FC099D6027A741ULL, 
            0x79DE381C2270E1DEULL, 0x605FEA9C83F2F336ULL, 0x04C65F639ECC4010ULL, 0x1F6EC8D80DFE32A4ULL, 
            0xD9D27AE7665383E5ULL, 0x53FC2F69520F71D1ULL, 0x948807DFC4D6D22AULL, 0x26FDAB6FACD276ACULL, 
            0xEAC94E50A83DF22FULL, 0xA717EFA8512D956FULL, 0x77433921C8036570ULL, 0xD17D68069D99104CULL, 
            0x5ACDE441CAA132BAULL, 0x6CF48DB2BC87CD31ULL, 0x0AB54D0DABE538BEULL, 0x223A19A410DB8347ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseAConstants = {
    0xF46EB246672B1800ULL,
    0x703F8298CFADF03FULL,
    0x161029FC3C8D02DFULL,
    0xF46EB246672B1800ULL,
    0x703F8298CFADF03FULL,
    0x161029FC3C8D02DFULL,
    0x1AC37ACAF12080A3ULL,
    0x0D8BED924A349F6BULL,
    0x5B,
    0x76,
    0xFE,
    0x8B,
    0xE1,
    0x53,
    0xF0,
    0x64
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseBSalts = {
    {
        {
            0xE5B9207FAD1C11EBULL, 0xB2BFB93C9ACEA048ULL, 0x37DB3390564A6244ULL, 0xCD09C4E12F9CFFA8ULL, 
            0x171633D99C6CE2ABULL, 0x70370ADAEDB0999DULL, 0x0978419625567187ULL, 0x0CC97B18C4EF570EULL, 
            0xCA48EB3DA33DF1E1ULL, 0x717CAB4A436DF437ULL, 0xC0F9F22575EDE695ULL, 0xA8B297D17DFAEFF0ULL, 
            0xF953DB1BEA10D1FFULL, 0xAF87647B447A358FULL, 0x20255D433F68E8C9ULL, 0x38382A96E685A68FULL, 
            0x6E8E042FE13E9879ULL, 0x6360BEC7F64446F1ULL, 0x00DC1F485218F877ULL, 0x087BAE5D6A57E962ULL, 
            0xE84D9E0BCD75EBA2ULL, 0xF915D7C4A04182DAULL, 0x8975721A8CADE8BEULL, 0x4339FF3F55EB0D1DULL, 
            0xBFEDE1F5A4653148ULL, 0xEA3390C74B438487ULL, 0xD778C2479CCE83A6ULL, 0x52F0225E70C832ABULL, 
            0x520E8D063A5F1461ULL, 0xB6F7081024359FCFULL, 0x5A39767DAC6C8CDCULL, 0x5D2621EBE6F140DBULL
        },
        {
            0x2F2C1B570F202AE8ULL, 0x430C30F39C5E3639ULL, 0xF8D2CED19521C73DULL, 0x6D27901E6C8D33ECULL, 
            0xB9F7D12532C5C443ULL, 0x702A2D5177097DD3ULL, 0xD3A050994558FF63ULL, 0x6134B84C3921304EULL, 
            0x5894864E74A4233AULL, 0x23B9FFDF6506A912ULL, 0x0F1BC06BCDFEBC4EULL, 0xD64910AE67C59B42ULL, 
            0x15414BF82BC7EFC5ULL, 0x1D6542A93721B4DBULL, 0x577479714624E894ULL, 0x1A5714CF3B61CC61ULL, 
            0xFD04ECF5BAD7C55CULL, 0x04416A19240EF67EULL, 0x8B6A58FE34C2E532ULL, 0x7E0744A8BBEF42A0ULL, 
            0xDE61CFA76707C6C5ULL, 0x8FA50C50D55A9BC9ULL, 0x3CFE78F2FB7CC0D8ULL, 0x652E07D064B92AE9ULL, 
            0x4574EE0C86D07025ULL, 0x9336D9595F692F0BULL, 0xB206D17C3920AC10ULL, 0xB84EFF341AE8AD05ULL, 
            0xFA5849D706D447B4ULL, 0x965BF44A40080AE8ULL, 0x9DD9571AB289B4D3ULL, 0x9A1B5487CDD4A7E8ULL
        },
        {
            0x7FED3889EE539B87ULL, 0xE06B6C1884853B2CULL, 0x1C0CB9E373B23159ULL, 0x6E5372998C5AEDB3ULL, 
            0xD5BE857EC30DDD37ULL, 0xF6115AC83D804BE8ULL, 0x222BC540696E6869ULL, 0xE841E6FEF8A7F209ULL, 
            0xCEB6812C4B3841BAULL, 0xA3CFA46B734281B6ULL, 0xEBF00FB46AFBBCC3ULL, 0xC4605DF89A0277D5ULL, 
            0x677CF1945B66227AULL, 0x435215AD8BDFB67EULL, 0x9E23A06FD5FB14BEULL, 0xE38A7D23E3763E46ULL, 
            0x9D26C929105F57F1ULL, 0x468A889797C1DBFAULL, 0xC5900CCB504F8499ULL, 0x81059E2EC3973DF1ULL, 
            0x08B921051D5584FBULL, 0x20614548D222D069ULL, 0x68311C04A37E7920ULL, 0x0F9D70A1B3793A2DULL, 
            0x374200842458778FULL, 0xB7F8AA9633FF3BBAULL, 0x23C2B9DFFFECE318ULL, 0x45B15AC92D3E0E7CULL, 
            0x1B6DEE5643E8CF0DULL, 0x68A61CDBB2E32880ULL, 0x72FA86957251CEB0ULL, 0xF37263F18B7B5CF6ULL
        },
        {
            0xE815E78C740FC32AULL, 0x63971596DD33F1C8ULL, 0xE4C7EF265709E639ULL, 0x580681EE9983E9D6ULL, 
            0x048591E309C958D5ULL, 0xAB97A11C6E69B07EULL, 0x2263D6126DA09F2DULL, 0x6CF252FB7526F143ULL, 
            0x033C5CF5953B06A1ULL, 0x585C30FC4D839930ULL, 0xC3EF627252C7C6CBULL, 0xBF7E08B57DEE16D0ULL, 
            0x2AFDA054BFE1CBDCULL, 0x5790EA9A0B58C346ULL, 0x4DC54A903007817EULL, 0xD75FADE8833A7C45ULL, 
            0x0AFBCB82CD776EC1ULL, 0x661AC37BDBA08C46ULL, 0x8399678F11F36535ULL, 0x46ECEBD9E5857492ULL, 
            0xD65C48EBD8AB2011ULL, 0x7B603C8675F3BB2EULL, 0x47C81B55F29E86A8ULL, 0x0245BB01EC0F4B82ULL, 
            0x0E24178C2ADF0019ULL, 0x7E4013BB1FB254ACULL, 0x999BDAA3D59BBD96ULL, 0x4D8850E1E15773C3ULL, 
            0x440947B7B710AB37ULL, 0x5FE6594523F63FC7ULL, 0x910C6B12AF9C7232ULL, 0xB1DF5E46920A7E4CULL
        },
        {
            0xDA632685C7C2F8BFULL, 0xF030099D11BD8EB7ULL, 0xECF0E1CD27FF758DULL, 0x205E0422F56CC19DULL, 
            0x450FA8D7239893C7ULL, 0xB25F75B0EAF1621DULL, 0x48627948E907FE18ULL, 0x1BA8B8C928584C85ULL, 
            0x0868E87C2C91E1EAULL, 0xD9E40BE8A7A330B1ULL, 0xA119DB03F6CFA80CULL, 0x52F8EDB12612BAACULL, 
            0x98B9694635F7D038ULL, 0x45A29C8ECFF1EB65ULL, 0x6945CB6933BE1412ULL, 0xEE582D075B12A1C9ULL, 
            0x2E4F480602618AC9ULL, 0x62EFEBEE93250407ULL, 0xAC1FF0D897208E6EULL, 0x0EA39C02A9B48FA5ULL, 
            0x3A08C717C48DC59AULL, 0xF45F0862D2544200ULL, 0x6AA9B8E540FB2738ULL, 0x419996A7F3810936ULL, 
            0x981549D245C3705EULL, 0xB77DD90FE6201469ULL, 0xDE6273DBDCDF0014ULL, 0xD1F0EABA11CE5342ULL, 
            0x6F40EE0551463161ULL, 0x1628FF6D00161952ULL, 0x4F6208484C19FF82ULL, 0x90C13D71E8A946D5ULL
        },
        {
            0x9759E7E5CB4ACEB7ULL, 0x49932826A8E0F3D5ULL, 0x274C8A83816B3D50ULL, 0x181ACC533512F38FULL, 
            0x266506E1E2081FFCULL, 0x983F1BA676E5FBC7ULL, 0x67DF205B7705FE2FULL, 0x7B9797B9CBEB5DCBULL, 
            0x7D41B9847E10EE4FULL, 0x4E9FC8FC984436DDULL, 0x37783BFE5C9D4445ULL, 0xE56B44B1438F1CBAULL, 
            0xBD33A3FC60AB3ED8ULL, 0x3649CFB1B6232864ULL, 0xF23429BCA655E743ULL, 0x5D1AD5581FA2E2CBULL, 
            0xC23ED48E58705C06ULL, 0x616942A1ED2FD5BBULL, 0x49816EE2B904B8F7ULL, 0x9F728C687A2FAAF6ULL, 
            0x27A5608C9185880BULL, 0x5BB58DA5C059951AULL, 0xF3A95A587B7C195CULL, 0x728365472066FE98ULL, 
            0x7EC4BFA4178BC8D1ULL, 0x5F2E4CD6EFDA51ADULL, 0xA9D3B097E2722A98ULL, 0xA9CFAA1C31A54A75ULL, 
            0x9EE227EFDD6000E0ULL, 0x584CB97F4987E6F6ULL, 0x7237705EEB5C59C1ULL, 0x211024A0674BBAABULL
        }
    },
    {
        {
            0x9A40FB730D80AA71ULL, 0x66D9F087C2279F0BULL, 0x2E2ACAEEFBE28FABULL, 0xE14B2038875912A1ULL, 
            0xFF947CCA11499B25ULL, 0xAE9C9E5DEB61A789ULL, 0x1B9E17A415D85384ULL, 0x5634DB1CD61B7984ULL, 
            0xEC54F01B03C47D61ULL, 0x6674A06574EAA856ULL, 0xD8539DCF0539F24DULL, 0xE8DDA449AF95B87AULL, 
            0x87C1367A4395D9E2ULL, 0xF40E2FBBF2AE3462ULL, 0x8647A11DB52442AAULL, 0x04B7407C6C63A1D1ULL, 
            0x94334DBD5A909DBBULL, 0x873F50400C94C7E2ULL, 0x4ABB9EDB50885FBCULL, 0x14D298AD787375A2ULL, 
            0x3B589F588DCDEB88ULL, 0x483C905792F66CC4ULL, 0xC479881D2590BF03ULL, 0xEB72B16D4DD2D3E0ULL, 
            0x17C4C3232B67EE8EULL, 0xCE643DFC10AB1F3DULL, 0x492C9531D2CDFF28ULL, 0xB29AAA7451E32713ULL, 
            0xC85FB32DD3FF6E05ULL, 0xA39ECC66A91AFCD6ULL, 0x7F57B92AE65FF502ULL, 0x9528232FDECD2460ULL
        },
        {
            0xBF6202CBA65316BBULL, 0x77ABDE33E88569D1ULL, 0xBDFA14041384477EULL, 0xCE01B728A2F7E3B1ULL, 
            0xDC253547612F5E00ULL, 0x74835ADC3DFD52F4ULL, 0x0B1D1248CF4EBD6EULL, 0x9C65ADEB314E254DULL, 
            0xCB71A555F47BE94DULL, 0xC6A1BBC9CDC35CB1ULL, 0x192CBA4093A925CBULL, 0xF6CF384696DD2629ULL, 
            0x47DD3733717E31C1ULL, 0xE2277CC184FDCB8FULL, 0x15195EB4928A0934ULL, 0x9ACAE1B19044DC14ULL, 
            0x3D8D1ACFD3D6FD53ULL, 0x7A1020BEF358C5E9ULL, 0x584C67C029F90D53ULL, 0x9AC3457A8BFAA97AULL, 
            0x4201A287FCF3B638ULL, 0x00E017D70459C9FEULL, 0xF50D2AF0F1225A02ULL, 0xEBF057B077AA5D7CULL, 
            0x54D18BEE1692600BULL, 0x5AD1F5C40E012DF9ULL, 0x9D9AD52769A2DEEAULL, 0x6744B09DAC70A284ULL, 
            0x31C5E8618819B96AULL, 0x7176A2C84C7F570CULL, 0x1D76E523BB1EB5C0ULL, 0x63FB13E1913BE099ULL
        },
        {
            0xB76CB5D5FE5CCB16ULL, 0x0670FB9896272241ULL, 0xEB23E7B258E6387CULL, 0xED9FB7FFFBCB86E9ULL, 
            0x6A832C7A1DEAAFB3ULL, 0x60CD11EA9FFF3292ULL, 0x13C23B8AF7E3385CULL, 0x0D21C4BFB36210C4ULL, 
            0x67658A97F54B8184ULL, 0xEFAE30C022D5425BULL, 0xB10C3B67237B726BULL, 0xE67DF10D5DB93BECULL, 
            0x1DF7CE114C042119ULL, 0xEF8509F426814B8DULL, 0x712D9F646F2E38B2ULL, 0xA9DCFCD40007DB72ULL, 
            0x3EC5EC82A6E80705ULL, 0x2EDC4A4000FB1C7BULL, 0x2F534FC860BEC195ULL, 0x6F20B570B385C10DULL, 
            0xD5EA963D42E826F9ULL, 0xFCF8074D187B23CDULL, 0x3D64706E3EACE8C6ULL, 0x642C45FF2C807785ULL, 
            0x24DCE17ACDE6762DULL, 0x7FC47048CEAD680CULL, 0x9335C9FE951ACCEAULL, 0x17B4B11BE3F10B5DULL, 
            0x10787A4634B95D5FULL, 0x92623C1AF2F83D06ULL, 0x9C7FE21DBFCE9A41ULL, 0x22C822B2A4335E60ULL
        },
        {
            0x1B2F535133B875EFULL, 0x436B1F7B00D238D2ULL, 0x93590917DF9EBF5CULL, 0x58DB2BCD8A247CB7ULL, 
            0xD2E1CDF6F0DB5B05ULL, 0xD8620F361288B6E9ULL, 0x2104A02F026B7DA3ULL, 0x673CBE5519C7DCDEULL, 
            0xEC1DB9D9840FAE44ULL, 0xA50E57DEE40A80A6ULL, 0xCA82BA3CDF2EDB6FULL, 0x9B453B6B7A69FBCBULL, 
            0xEC2BEEDAA43317EEULL, 0x7FAE906939D7FC0DULL, 0xC0D8936FE5589B4BULL, 0xDDD3CD0071EC283AULL, 
            0xE2AD394E007351ADULL, 0xD920AA309933489BULL, 0x775C7915AA6A13B9ULL, 0x228A50E33D2D97EEULL, 
            0xDFE7AA9CB571B2B7ULL, 0xA3E194F94B2C61BDULL, 0x489EAECA48FFEE6CULL, 0xB30416FC6B459C26ULL, 
            0xB734CD3DEF00D997ULL, 0xDE65E88A1B830354ULL, 0x917A7A7DA2F1DE66ULL, 0xAC60539F727C2C4AULL, 
            0xCCBACB561D4EE4C6ULL, 0x06497A92DEE758F9ULL, 0x72BE9C8AEB535FAFULL, 0x6B2A586307F5AB93ULL
        },
        {
            0xFD73C25713C20792ULL, 0x536C294F916F977CULL, 0x79D586A090F69337ULL, 0x99EF97343E562611ULL, 
            0x20A06F0AF437773CULL, 0x187F05D01D914EEBULL, 0xB0AEC56C9AAB2A6DULL, 0x6DFE10D8A84428D8ULL, 
            0x088B1B83D9295EAEULL, 0x4D097BA5601B8B39ULL, 0x066E5C7A260E8782ULL, 0x38346A60FBE27B5AULL, 
            0xE3629E88DC6B6423ULL, 0x7C86B7316B624260ULL, 0x0DDAF1B43061F270ULL, 0x3F297D852F89D5CAULL, 
            0x7B218982C2E9A2DDULL, 0x751438B0E65E5E8AULL, 0x92AC6612C28A4CF1ULL, 0x4E74381562BF8425ULL, 
            0xBA884C690A31BFAFULL, 0x8A130365D0DF247FULL, 0xDE662FFA78152EADULL, 0xA7B6AE93B68F11E0ULL, 
            0xBF8A910D00058536ULL, 0x4B2FDCA9E2461DEBULL, 0x6F6A0B9DA45C3D4AULL, 0xAD4730AD7E87BF2CULL, 
            0x163A8EB28EA9D331ULL, 0xDE8CADB3E9940561ULL, 0xAEFF2C1A6C5E2B7EULL, 0xC41F655D98C2BF00ULL
        },
        {
            0x21A13CB6463D5489ULL, 0x14660EADDAA3F429ULL, 0xBFADDAA51F3653A4ULL, 0x61350D1B05BF9850ULL, 
            0x36EBE7E2FD383BA4ULL, 0xD6C7B75D56C4B771ULL, 0x83D4900BAE6FC2C2ULL, 0xEF44F52288261FF7ULL, 
            0x088BB2EC0443B7D4ULL, 0x93E1C9509405B5CFULL, 0x7A09B8E9D7D656C4ULL, 0x9E65D4AF5BB01D6BULL, 
            0x4F3CC1495CDFA159ULL, 0xE89E6AEBE67F73CCULL, 0xA3026BECACA641E1ULL, 0x32FF420F0B954FADULL, 
            0x25FAF673B6C8E028ULL, 0x04047D36A0020C67ULL, 0xC00B1205161FAE75ULL, 0xAB94C80D5D009B38ULL, 
            0xE6BD016B08F6A321ULL, 0xF6EEEE0DA47B743AULL, 0xC2D7DB596D663CF9ULL, 0x58A15C86F0A1C425ULL, 
            0x39827889FF3434F9ULL, 0x0FDD4A3339C8E1C5ULL, 0xF5B9BF4F45A1FEDFULL, 0x2A1E2AEDCDB65855ULL, 
            0xE277A6DF22064771ULL, 0x12E3971D523C9768ULL, 0xC008F096A3171E6AULL, 0x1969A5A20361ACA6ULL
        }
    },
    {
        {
            0x89ED10FFC88E28FDULL, 0x19B5EC06D981C17CULL, 0xAB777A569AA619E1ULL, 0xB850200A0CE3030CULL, 
            0xA897D5438751CE4CULL, 0x9A130559DDB8587AULL, 0x1E610A1D2E723152ULL, 0xB77E106B8641BDEFULL, 
            0x7C5146AF736D6BFBULL, 0x92D37ECED8904717ULL, 0xAC0D5E4C71F3A5C8ULL, 0xFB5C0924A8C4C809ULL, 
            0xDE0981DAECFD720AULL, 0x4E731A68D5BC9264ULL, 0xB38410FEB3CF5BA7ULL, 0x9A9953551B52A632ULL, 
            0x9277F661A5FC95C4ULL, 0xEC8955A10CD3A64EULL, 0x3B0A679E96787B26ULL, 0x44A28E06A9EA45C9ULL, 
            0x069FA3373A674137ULL, 0x27576AF0B78A8423ULL, 0xB085B6D4EB648142ULL, 0x044FCC2B80FA4558ULL, 
            0xA62A9C56F28CC446ULL, 0x23DC3DB83D06F521ULL, 0x5E1A8C238185F3B3ULL, 0x3F0B100194C50A1BULL, 
            0x2623D2F1BBCF2980ULL, 0x5C118BB265BF9E9CULL, 0x8B1FE5E0143F7CECULL, 0x4FD3F1A2BDB77D9FULL
        },
        {
            0xA97D7455B111AE8CULL, 0x02D94B66D1164E40ULL, 0x28EA027C9DF52108ULL, 0xEA47541BFF6BE3DBULL, 
            0x3561C7C8B8C83516ULL, 0x529142DBBD775B66ULL, 0x8B0DA1504992FC8CULL, 0x13A58790F204EB19ULL, 
            0x6BC901B9F181BBD5ULL, 0xA6258F9299C6BDBDULL, 0x4BDAD2CA4852E46AULL, 0x7C1225964E238435ULL, 
            0xA84EC7DED3279F0AULL, 0xAB85665482E47177ULL, 0xECB3F42AD088B0B5ULL, 0x0A86784CD8CDCCA2ULL, 
            0x9B7D1C352E8684F9ULL, 0x97B63B74001DF5FDULL, 0x42C6A536D6C50D9DULL, 0x1504AABBE223A246ULL, 
            0x60029C8D13AF2A37ULL, 0x6CC4389105435D0EULL, 0xEEBC03161AB82D45ULL, 0x664CE342B4251CEEULL, 
            0x144AF0A86A1C2D25ULL, 0x92C9C9C7FA463AB2ULL, 0x20FE77077E694831ULL, 0xDE157294DFBCBC20ULL, 
            0xE1BF9EB0FED087E0ULL, 0xA26F856EE9A69163ULL, 0x4772690391F84C47ULL, 0x898946647EC8F1C9ULL
        },
        {
            0xBC0F3E4F5288022EULL, 0x242BB88FB4EDF9E3ULL, 0x539E36AD1B1AC0F4ULL, 0xD4E6B832FEB96CE0ULL, 
            0xCC19DAF6480F0DF2ULL, 0x778BEDD797F69098ULL, 0xAE1689430203BB6CULL, 0xB2E4D126799A7FBFULL, 
            0xC1625A12C00F7B64ULL, 0x0E658C71B756C9E6ULL, 0x79F208524C860ED2ULL, 0x0D809E4E043459A1ULL, 
            0x0F8758D242C7F31BULL, 0x5EC8EE0F73876EF8ULL, 0xDF8896321601A8EDULL, 0x5B97B663763F9E4EULL, 
            0x39C5E6FAF09DA4FDULL, 0x1FFC8A1FE1B6E2A3ULL, 0xFBE520ABF86A4533ULL, 0xC5D33D9659B1D17AULL, 
            0xF0AF2CA7A747A369ULL, 0x30D97EF9784A9D2FULL, 0x84C387AC50BFB6F9ULL, 0x19FB6ED9D6C0165BULL, 
            0x651E2F2D99832C30ULL, 0xAF79C680BFF8E756ULL, 0xA3A6170F99B49CB7ULL, 0x1208FF0623B3EAF0ULL, 
            0x9DAA151117429739ULL, 0x10DB68EA2817C6BFULL, 0xC820E669A2058B19ULL, 0x1CA8A0BADC4FA420ULL
        },
        {
            0x678622FBC76CDAE9ULL, 0x9B5909FD6B4E8A7AULL, 0x256CD4DADD8D261BULL, 0xCA01E30DD92E5D5EULL, 
            0xF383BD4D0B729889ULL, 0x36CCBD96EF69E0EDULL, 0xD983E7E3B488EB1EULL, 0xFE50216EBF380397ULL, 
            0x00EA1A7DD265E4BFULL, 0xFEF660DE6C9511FEULL, 0xFB9AFFB0B3BBBF0BULL, 0x4CFFA66393D9D288ULL, 
            0x796F5A5276E5BC5CULL, 0x12943E7699361BE5ULL, 0xBA81E73884873263ULL, 0x3FAC7CE8D2C60333ULL, 
            0x8D2B036F9304CEF1ULL, 0x73F54567CA3F1745ULL, 0x60F6E73617CA2DA9ULL, 0x3C34E822E6522DACULL, 
            0xF1C06FE134B09C21ULL, 0x74379EEB3AD485D3ULL, 0xDCE5281B6183C8F1ULL, 0x3B2AF23B48B6D950ULL, 
            0xC68072AC1A9BF48AULL, 0x39DF5D7A5576E08DULL, 0xC550C8994F63D963ULL, 0xA019C92BAFEBFD27ULL, 
            0x4FE199407E76A050ULL, 0xA9864ADDF0FAEF6CULL, 0x8A1EB5F168C6ABA9ULL, 0x3967C0DC3FA6F0B4ULL
        },
        {
            0xC6B44A904183F1D3ULL, 0x76EB1CA41EB922DCULL, 0xDDE5A4F88B65A7B6ULL, 0xA57E87F3DE03A3FBULL, 
            0xE0BB7F76B0199E47ULL, 0x49234D9667665EE5ULL, 0x4B1ED7621902567CULL, 0x910A606757DB35E5ULL, 
            0x35576B292E9D9B00ULL, 0xD85AF0A022FFC813ULL, 0xA923A894577CD89EULL, 0xAC61F23F1A392940ULL, 
            0x4906A1F7DA6C5AACULL, 0xB06E993AB5A4227BULL, 0x135288D92D783F79ULL, 0xA58CCF417DA4B42AULL, 
            0x66C567EE875F527BULL, 0x63259DE47D16E32EULL, 0x0BA72712CFD3C2FDULL, 0xAE8A5210988B305FULL, 
            0x711A664B79C504CCULL, 0xF07DE980BAC3E5F2ULL, 0x830C44FDB12FBCB3ULL, 0xD5594464CC4021F8ULL, 
            0x78BF6EF654995E6DULL, 0x914D9D8FE67836AFULL, 0x4B0D8077106FEE0AULL, 0x62A87A2D79D71B2FULL, 
            0x643564CBF7C577E1ULL, 0xF73299636324BF04ULL, 0xF15846598B4EF942ULL, 0x17A89ECEC504AD79ULL
        },
        {
            0xA8A252A5115F3947ULL, 0x16E0604C3F9B6EDEULL, 0xFF7C45F61938DEA8ULL, 0x9108DFCB3ACCE035ULL, 
            0xF90D4FA37CEA30E8ULL, 0xBD40C5EBD8FABDA1ULL, 0xFEEF9A1FA7160900ULL, 0xBF089CF2A7D61C04ULL, 
            0xED0FBCFA8B938D4FULL, 0x345073320A8EF2B7ULL, 0x972034FEE1D243BBULL, 0xB0BB86C11AAC10C9ULL, 
            0xFF4169E2E97BCB27ULL, 0x1D4C45CE5657054CULL, 0x903DEF5AD90A74F6ULL, 0x1A71B66E5486F512ULL, 
            0x7EA94DDD62572704ULL, 0xF1F2B6A7269FD762ULL, 0xC9153A9EB6B47DF0ULL, 0x8ECFD5441ACD99B1ULL, 
            0xC6A67A7764E107C5ULL, 0x578132842A671243ULL, 0x7837A1B7C1329810ULL, 0xE6D98C975F7A7883ULL, 
            0x42615543BFAD124FULL, 0x040411943D5A411EULL, 0x901C9B558404B050ULL, 0x7C8A06976629EC60ULL, 
            0x2EBC4EA1A4212CDFULL, 0x51351E55B7852392ULL, 0x5C44A5C0DC273BADULL, 0xDD7372977CD2540BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseBConstants = {
    0x7E73BA9FB3DB5A3CULL,
    0x4C9BF5A8D5AD13DEULL,
    0x6C22BB599B88546DULL,
    0x7E73BA9FB3DB5A3CULL,
    0x4C9BF5A8D5AD13DEULL,
    0x6C22BB599B88546DULL,
    0x952A50C1FE770F73ULL,
    0x920FC891FDAD87ECULL,
    0xCE,
    0x82,
    0xF0,
    0x80,
    0xC2,
    0xA4,
    0x17,
    0x39
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseCSalts = {
    {
        {
            0x33C20CBF65E66FC4ULL, 0xD0EF62EA03B6E433ULL, 0x0AAF4B4395B04FFBULL, 0x8C88CDF344A0ECB0ULL, 
            0x39BFF92B54935071ULL, 0xB28F3895FABE35A7ULL, 0xE1FA53AD08E623A6ULL, 0x0E338D0CBE6C953AULL, 
            0xEC2D380DF5D1444BULL, 0x35AAA2B60C86414AULL, 0x9C0A5805CEB6A80EULL, 0x9DBF952662674683ULL, 
            0x63DDC199995795B1ULL, 0x35935349446F3E94ULL, 0x7CE16284A64E7AFDULL, 0xC700859CD8900CE7ULL, 
            0x16D8525B8DB76B49ULL, 0xBF88D9503E48DDB5ULL, 0x42BBBC102776E58AULL, 0x69DB0EF7A82095A3ULL, 
            0xE1A43506167FFA4CULL, 0x2BF7322D78ADF4C9ULL, 0x2AE8069702BAB78EULL, 0x63AAA9EB7AC9E728ULL, 
            0x70BEE353DAE75313ULL, 0xE0049AD5D473C800ULL, 0x273D50B407C810D2ULL, 0x2442D258AB406666ULL, 
            0x943C4D3656446FE5ULL, 0x9E5D664866A842AAULL, 0x1FB8761315EC76BCULL, 0xF34FA4346B5365FBULL
        },
        {
            0xDE134CE86C94F8B3ULL, 0xE1119A5A2D3F3E65ULL, 0xCD6CE0F2195E1A90ULL, 0xA9EC460E36CEBE42ULL, 
            0x216870E74AE705B0ULL, 0xF9153587FC53773BULL, 0xE4969EE8A6686742ULL, 0xCB5734BAF4449EB7ULL, 
            0x139D460834F14C02ULL, 0xE9BEBD0B73616CBBULL, 0x18AE62E981E03793ULL, 0x101B4A859434A86AULL, 
            0x38A4A0164ED50978ULL, 0x54CEADA7E27ACCDAULL, 0xDF83616B26F3A08CULL, 0x91958D648EB4408CULL, 
            0x6928EDCB24050A80ULL, 0x18038A93F55C8B5CULL, 0x5B3DA931BF3FBD4DULL, 0x2C39DAD2F2A8E93FULL, 
            0xF0F782B83AA91285ULL, 0xE5BB92E25DA348AAULL, 0x02A8F8FD54AAA9C9ULL, 0x586D741BD3346F0DULL, 
            0x72EC3612A9DA3DA4ULL, 0x8A6DC779B40647D1ULL, 0x1555A6FA7BBF27AEULL, 0xA4A2AD3384BEDFF2ULL, 
            0x25277CBE2279C500ULL, 0xA126E9120DAAD3D4ULL, 0xFB36CAD6CDBCE3C9ULL, 0xD23584C1EE6E3CCAULL
        },
        {
            0x2A630FE4FE424F57ULL, 0x6954C3C095147687ULL, 0x657C01CFB22A1545ULL, 0x9FB9BC930CF90345ULL, 
            0x01AC5F01EDE74665ULL, 0xD21445326FB01E4DULL, 0xF6DE4113A20C685CULL, 0x2CB6084F71738371ULL, 
            0x902995CD89B3BB15ULL, 0xBFD1BF41B040D51CULL, 0xABDE770AF9035BEAULL, 0xD1AD5E15B18C407DULL, 
            0xB656E406F65E2F68ULL, 0xA76AB4B12B063732ULL, 0x462182A451E37719ULL, 0x9A37401508694E99ULL, 
            0xAF8D1298D50A374EULL, 0x242EC6668640FF80ULL, 0xC99C35C272480468ULL, 0x4F16A4A330F81683ULL, 
            0xAFDCAE91175CB0FCULL, 0x07F0159DD2875C92ULL, 0x32D6EC1D97BB7945ULL, 0x52A6E26772C88A09ULL, 
            0x3BFDA56CDCCA7FF3ULL, 0x2A7D4A636A3E64A1ULL, 0xE4EA0599C7AE7075ULL, 0x956103B2B05D432AULL, 
            0xC1BCB6AF7666E22BULL, 0xF9BE144702872876ULL, 0x9BE9B2D006D9DE45ULL, 0xC21338BCEC20C127ULL
        },
        {
            0xC5D06285E0A902D2ULL, 0x0BFF23E8FDDB2652ULL, 0xB6D9CED65DA02E20ULL, 0x6BC79FEF03B73A22ULL, 
            0x5827388E641685C7ULL, 0x76EBE3CBE28179BCULL, 0x6B6851E5BCA2B239ULL, 0x5F0FF2D20AFFB2BAULL, 
            0x92435BE1DD1212F2ULL, 0x228060D3C646B65BULL, 0x0D6A61B20FB28D16ULL, 0x8F9EB9536A2C49BAULL, 
            0x1F8A6D7DE793E155ULL, 0x953F2DD52323BD25ULL, 0xC5C9E7B64E2F8799ULL, 0x563650CFDA1D3EB3ULL, 
            0x1A0488831758D270ULL, 0x1DE52051BF7C8F3DULL, 0x1B2E83B1E3EBC724ULL, 0xE90C4FB85E1779C9ULL, 
            0x61F855E8D787CE09ULL, 0x35E455DBC1D7841CULL, 0xDF110C3A7CA26C36ULL, 0x9FAA14DF8DC104F6ULL, 
            0x134C10FCDA7BDB3AULL, 0xBDA794CDB8AC1477ULL, 0xF7A99B532C0D6A8EULL, 0x523C3C1F0E25BD54ULL, 
            0xF6EC8F47555837A5ULL, 0x696C9551223587ACULL, 0xAAEFE9FF85AFBB48ULL, 0xF08835A7D27E370BULL
        },
        {
            0x344E01DDE3CDF659ULL, 0xD06DBC0CB042FED3ULL, 0xEB043181715747C3ULL, 0x070623907EDF0D8AULL, 
            0x56625390482204A1ULL, 0xCD4CB29FB97583EDULL, 0x16C63D8B7B3D097AULL, 0x6493D4FA5A6EF141ULL, 
            0x29E4F26324EC7780ULL, 0x620C9266E47CD69AULL, 0x57CA6A012D79C9A2ULL, 0x1932404D4C24228CULL, 
            0x871E267318DCAEEDULL, 0xE776D8BE913BC4D0ULL, 0x411BC134EC54068FULL, 0x345FE8D7C59A94C8ULL, 
            0x3EA634177245182BULL, 0xA87D4C07393B99B8ULL, 0x3B3E43C265EBFB30ULL, 0x33F58BDF003B947EULL, 
            0x10A506E71A5CBA3AULL, 0x1B3043E4DC34D1F7ULL, 0xA7920FBFC3A7E398ULL, 0xFBEDCF0A205C456DULL, 
            0xF30ADE502B975551ULL, 0x86456D1D195CE041ULL, 0x06EE467A9EA27405ULL, 0x6BD802D73EF5140DULL, 
            0x2AE5DD7172364EAAULL, 0xB9F7D7D504F64F0FULL, 0xFE640055487912F3ULL, 0x19A4B4D3606816C4ULL
        },
        {
            0x5E44377D194FD33FULL, 0x12CCF138A92333F0ULL, 0xC56289BC4212841BULL, 0x700A44C4B8AA1DFBULL, 
            0x14C71BABD3E33580ULL, 0x6E38EE5D07A12B5FULL, 0x589CDCDD4C7E41EBULL, 0x51CCF554EFC6FC61ULL, 
            0x99AAF7623517D06FULL, 0x098A1FD45C461965ULL, 0xBFFC707A4A73B58EULL, 0xA8BDD6558D6687A6ULL, 
            0x2399E88384ED2583ULL, 0x1A9AE2ED1A81556FULL, 0x3CD742340CE513CEULL, 0xB589DFD54DF154A9ULL, 
            0x5107D0A0BA87DF6AULL, 0x820B4458E920213AULL, 0x74705AF02743FF07ULL, 0x19E9D8273B01BED6ULL, 
            0xE261BEE4E615EC58ULL, 0x53803DF3BF7A9C5EULL, 0xF8B27A03E7CF9E16ULL, 0xAE30BC77160453D1ULL, 
            0xB2E27120A8263E1CULL, 0xC0E96C0CD5C9A235ULL, 0xDA0847E10517A760ULL, 0xFE22331B737AB58FULL, 
            0xB6DE769D87A7F510ULL, 0x3BC2213AC353693EULL, 0xB1E4119D2998A7C6ULL, 0xA9A24E4B2636BAF4ULL
        }
    },
    {
        {
            0x709450B8E98CD045ULL, 0x3E91C62B710BE119ULL, 0x039C69E614E5C874ULL, 0x726C15A8DF5E24DBULL, 
            0x42A133F78D16927DULL, 0x899A54728FB88CFAULL, 0x1B312C0E2C6D01D7ULL, 0x0B372CBB75981380ULL, 
            0xCE96386E67976B90ULL, 0x0F8FDF6076504F9DULL, 0x4185BBE24C3E138BULL, 0x8A502837DCF785FFULL, 
            0x070CAAD68332C06AULL, 0x7A7B885F0AA3B1BDULL, 0xB4A542548A82C8F5ULL, 0xC036A7B286FAF997ULL, 
            0xC4C856C2BC37A06CULL, 0xD9896A720B201703ULL, 0x80495505009F2A09ULL, 0xA6885F0A1A7316A2ULL, 
            0x94537B24C26A5378ULL, 0x00E78C265AB3B207ULL, 0x34EE1B73AD4B11A8ULL, 0xBFC9F249D20187BAULL, 
            0x5897F339B6F71288ULL, 0x37FBBE97DFDB6907ULL, 0x43EE0C660F0EB0AFULL, 0xD70C3877F0641577ULL, 
            0x2574898258CA026EULL, 0x807EE6C237A27890ULL, 0x26F9C65E4FE58D13ULL, 0x49F7D329D0A628F9ULL
        },
        {
            0x00F26FF0E5DCAB64ULL, 0x44A4ADD43413FD35ULL, 0x940A2487572CBC44ULL, 0xB12FC0090C43945DULL, 
            0x97D54C6FBDF65DFCULL, 0x8954348328673A20ULL, 0x89287F41FBAABB81ULL, 0x4B520D41E51E4D79ULL, 
            0xECA93E22FE909EEAULL, 0x0D7CC461E537B58EULL, 0x08DDAE8065506D95ULL, 0xBF7B6D24CE056609ULL, 
            0x8AF903C40BB31CD5ULL, 0xC7EBC8FD6380DEF1ULL, 0xC69BFCEA448B1E74ULL, 0x6D8B5A533BEFC334ULL, 
            0x3780805E4E2590B5ULL, 0xC72E9FB0B7579879ULL, 0xE3B5669EB403AF05ULL, 0x57CA7795C93B4993ULL, 
            0xC806F9DB8E3D60A0ULL, 0xE6E39E647D5B41AAULL, 0x351F86A40F5E9C2FULL, 0x01DADD7EFAE2F9BEULL, 
            0xE316CC0C4D9A2D5BULL, 0x6A4FAA54B26E7780ULL, 0xE13E98B6BEB01EF6ULL, 0x54613450F7F9044EULL, 
            0xB07C4462DB7B9479ULL, 0xF13CFE0A39EF4D0DULL, 0xE9176471D233A28BULL, 0xDA2502E7E81435FBULL
        },
        {
            0x1324718030E8DBE2ULL, 0x4331478AD980B355ULL, 0x3B4812CA5C55D199ULL, 0xF879A32EE4D99A39ULL, 
            0xD89B20F2F6F56F9EULL, 0x095D5C474E124CB5ULL, 0xB03C6FE1D3332453ULL, 0x2C78165BCBA828E4ULL, 
            0x8EC4BB4DB59255E2ULL, 0xDB762258128889E0ULL, 0x463D2C45EDC9F143ULL, 0x2B02AA4588F0F1CDULL, 
            0x03919C36D7394E9EULL, 0xD610CAE223F6BFBCULL, 0xE875D50AB5553A91ULL, 0xDECC8BCAD774E0D1ULL, 
            0x066DC012DF61D2D6ULL, 0xA4E7BDD9611143A0ULL, 0x7165E813B3EF6C4FULL, 0x0F6D8092CCC531D2ULL, 
            0x1C3CE4F1C3E62791ULL, 0xF9C1FEF80762EE94ULL, 0x31F4756E55005851ULL, 0x29ABABC7DEEC6506ULL, 
            0x16127093C83E159BULL, 0xCB764E75DBB587F5ULL, 0x8E2FA20DE5D9932DULL, 0x6DD1CA371B614B4EULL, 
            0x4BCB17BEB9A4F844ULL, 0x5AB46099284BA0F5ULL, 0xC3085C78D43415B8ULL, 0x6FE36D36235EB283ULL
        },
        {
            0xF836F0B6C1CEBBCEULL, 0xA1A5CA77CF05D1FAULL, 0xF3DD9B2443ED0732ULL, 0x60C0C5A498DD4A5DULL, 
            0xD9269D4FDC87EAC7ULL, 0x5808A1290294D41CULL, 0xE7255E073A60C69EULL, 0xF4A5EB06BC544316ULL, 
            0x293A94D1A4259C25ULL, 0x4A0C8186874D2224ULL, 0x3752E70903E88F6DULL, 0xD560BAFB867D82B3ULL, 
            0x30A0B6A252832EE8ULL, 0x6DA50136C604BFC2ULL, 0x27992B9A98739C38ULL, 0x9FAEED1A6C1313BDULL, 
            0xD6F95D7CC7AC3CE9ULL, 0x6EA7894C2663D58BULL, 0xF0C35B2FB4E230F2ULL, 0x54C9F40706E56C42ULL, 
            0x2B24F67A37456B91ULL, 0xF1782D69DF53ABFCULL, 0x9F767811F47BBC6AULL, 0x357A56D2948511A5ULL, 
            0x3996E8B64DD19FABULL, 0xF7CD81F3F0C165EEULL, 0x1561659D680AB05CULL, 0xF24133969263A2C1ULL, 
            0x51709CAED7EE2D0FULL, 0xB1195E8C8F0A00B7ULL, 0x73F201359E1DF399ULL, 0xF5DCBF425ACE85CAULL
        },
        {
            0x4B9F7A3E39941B1CULL, 0x5C8FF063068A88EAULL, 0x705D214648155D15ULL, 0x9E88497656040A5DULL, 
            0xF5A00CE7E4A9E9FCULL, 0x4D8888A7A0468852ULL, 0x8D929E3E916A7DE9ULL, 0x9709734FC317F0F6ULL, 
            0x98107D923A9EE2D6ULL, 0x12884A4B21B8F36BULL, 0x4263FE94326DCA4CULL, 0x59135A6EA60E4C44ULL, 
            0x8022AEF2F969E005ULL, 0x911B941051307AD0ULL, 0x35B74C45F25A04E5ULL, 0x2BB7214894CABF8FULL, 
            0x02C0888DC57E83CBULL, 0x8AB9C87D6BA8EBE4ULL, 0xFC61BC704CDDBA82ULL, 0xDDF8035CC3DF0431ULL, 
            0x7AAABA4455D2F8F1ULL, 0x6E6A1BFF21EB07C8ULL, 0x73E52DFC0832A072ULL, 0x41FB2B0F9C98D5CAULL, 
            0x0C9B9C8DD48DD7E8ULL, 0x6246D6D100296949ULL, 0x1781CEDAC364DEA2ULL, 0x687381F2AE35921BULL, 
            0x2E2DEB685746B659ULL, 0xA402D8905AC2730DULL, 0x50BE872FB90DBB2AULL, 0x70316A7329B76486ULL
        },
        {
            0xE0942A51ACFE3EE8ULL, 0x1DB5609EF8D482B1ULL, 0x3A78EF4E38B7E86EULL, 0xD381E386AD3BCBEBULL, 
            0xEC29EF211A761D47ULL, 0x93DA55DD4CCB8BFBULL, 0xF2B9828ADD8AA4D1ULL, 0x7ED8587E9E498F6AULL, 
            0x0773AD6AE240F008ULL, 0x53E1C5914B6E3715ULL, 0x21150F86E76D53B4ULL, 0x557F5C7B61F80813ULL, 
            0x2830CB294D6E2962ULL, 0x2753B72DADD0B4A1ULL, 0x7A6C4E57A227E1EEULL, 0x06B79C00986720D6ULL, 
            0x0D32222F921C074DULL, 0xE0FC380091139D3AULL, 0x1177DAF667C61CEBULL, 0xE78CBCAE84775512ULL, 
            0xF63D2BC07B26148AULL, 0x31B306D927BBDF9BULL, 0x5661312E0EEEC6D7ULL, 0x6E6A00BE23EEFE41ULL, 
            0x1EB2448B4FCEF68EULL, 0x4F903ACD7C3A4DF2ULL, 0xEB1263B0CAC3848CULL, 0x7A39D9299BEC2C27ULL, 
            0x85947FDD90D9FE30ULL, 0x980C843ADC8517ADULL, 0x8C090AC21579E051ULL, 0x0388412DAD789D8AULL
        }
    },
    {
        {
            0x0B50A969FEA1BA1EULL, 0x5D358B8D15E894D8ULL, 0x2947CD84CBFEF9DAULL, 0x876971D88ECB8DA1ULL, 
            0xB56D46043BEF5254ULL, 0xF542910EEB36D63AULL, 0x31579320D723DD08ULL, 0xDD70AEDF44B94FB1ULL, 
            0xDDC5E27EEE1EF4A2ULL, 0x8C06C24154920B47ULL, 0x7C345C78D6EF5C9AULL, 0x26BBCF58309A21DBULL, 
            0x9747CF9D2F8119C1ULL, 0x55205A36D76B4AFAULL, 0xA23445A570E3089CULL, 0x8A7AA258B0F20F76ULL, 
            0x53303363213E3580ULL, 0x96B78B511877D73AULL, 0x4A085DF3B0B06A8DULL, 0xF004ED482ED3A7C3ULL, 
            0xACF88B08CF4E1E35ULL, 0x79D2881D0D45ED6DULL, 0x944074212614B835ULL, 0xBEC8B291BDE3A8EBULL, 
            0x025EDDDF6E5D5C02ULL, 0xE66F46156E23637AULL, 0xAD073ED36E356C64ULL, 0x9ED0788F346533FFULL, 
            0x0A70DE8CB6C4792EULL, 0x524B189BB42D2E69ULL, 0x78012249C583134CULL, 0x413F3BCE9D8F875BULL
        },
        {
            0xDE7D2CCD1F1BA900ULL, 0x4F2D777D985BA06DULL, 0xD580CD23F4136A53ULL, 0x1DDCED41485EF46AULL, 
            0x263A2B02CE71CD2AULL, 0xBA30BCAA23A26DCFULL, 0xDF02C1CEA17561DAULL, 0x30ACAEBEF6DE69FFULL, 
            0x79251ABF624B6794ULL, 0x800568F1A5CD2CE7ULL, 0x54B4F123C499613FULL, 0x81FDBA5AA163C82FULL, 
            0xBD988DB5764A6973ULL, 0x945674F1444CA8D4ULL, 0xB54E5C89FE59658EULL, 0x9AFDC33B1DAC4905ULL, 
            0x62F64216B8E0B4EBULL, 0xB4FE49B0A4AD15FFULL, 0x709C69A97B50621FULL, 0x2236075D46BAAD0BULL, 
            0xC23D19F9F9817ADCULL, 0x3BC39FD1A7EDC753ULL, 0x3471D5B7F49DB90DULL, 0x6994C09B30428300ULL, 
            0x6C2CA1F3135C25D5ULL, 0x39831D1052CB0CE2ULL, 0x98F00638A4FF4472ULL, 0xC0AC1C3893B06A07ULL, 
            0xD047A4705264196AULL, 0x51E933AEDA43D2ABULL, 0xFB7FF90E5EAE4670ULL, 0x49B68E819072F90AULL
        },
        {
            0x25FCB6D3CC4A28A5ULL, 0x42A2D877C28D410BULL, 0x1E56D3E879928815ULL, 0x65C9CD062F081D9EULL, 
            0x035912218E16954CULL, 0xBF578024FDC9D06AULL, 0x16CD600679FA8BA6ULL, 0xC26F3E71CCACF805ULL, 
            0x73CD68F1801379CCULL, 0xE24DACB094DB8E7AULL, 0xBA779417C1854758ULL, 0x25915444C2D85274ULL, 
            0xADAC3D598F8DD59FULL, 0x4A4F950BD460B0E8ULL, 0x0E596BCBEE645615ULL, 0xA1D0C8A81E05F9F0ULL, 
            0xA2D932DAF145D6FBULL, 0xE29DE1560677FBA7ULL, 0x666982EE80DC2854ULL, 0xD5BFD77070BB0D83ULL, 
            0x0E49F6FD56470589ULL, 0x7B78781837F5F0A9ULL, 0x8380A63D1E9107B3ULL, 0x8539AC6FF8E307DCULL, 
            0xE0727D4019170EE8ULL, 0xEA4AA3A13DA95C73ULL, 0x50C70A00E0EA7A99ULL, 0xCA334CA7D7315981ULL, 
            0x420241B1FF9C1B70ULL, 0x9B0F8F22746CC33FULL, 0xE2C731EAEBAF8179ULL, 0xB88168A29FA23F1BULL
        },
        {
            0x511768A8DE4DE2A7ULL, 0x4C57585785C7E659ULL, 0x7FA2CA7E1798FF87ULL, 0x9F8A920240D29F30ULL, 
            0x0D04A747EA080782ULL, 0x120B122B6FFEDA96ULL, 0x6358BEE11D05151DULL, 0x2636772B68963C3AULL, 
            0xE5F36FCC9A81FF80ULL, 0xC87C77D631501625ULL, 0xD23B4440993820B7ULL, 0x7898BD4A7571017EULL, 
            0x85D62F77646FB867ULL, 0x5E5D960C0A0AE82AULL, 0xEA305545D3D49B14ULL, 0xDF71DF23092D8B4AULL, 
            0xF2F11DB62410577DULL, 0x70AC5D604344074DULL, 0xEEF03E7DD326C91CULL, 0xDCCA48D92D0BDAC8ULL, 
            0x2803979C206280F2ULL, 0xCF020F86B07EC938ULL, 0x39A5332396121E29ULL, 0x232EB500C67394A1ULL, 
            0xD57434FD0DA4816BULL, 0xC33D7A09E0A94C68ULL, 0x425A7CB9658A5B5AULL, 0x742FA5D192229BF7ULL, 
            0xD070DD7567D794E9ULL, 0xC0871271C7DA68D1ULL, 0x34B04EF036CD8B91ULL, 0x3D0D904A3000A14DULL
        },
        {
            0x8D639FD5DAD25E69ULL, 0x6E2D6E777C98A75CULL, 0x8A0D24B2D633E6ABULL, 0x812937BAE37F1B2BULL, 
            0x9F3B730553B317B0ULL, 0x3BD41B08A71E683BULL, 0x2A7D1CD61EF07793ULL, 0x4F73D50B44B565A2ULL, 
            0x257443F0EF681550ULL, 0xE368FCF2BAB0FF5CULL, 0x47C938841A164DA4ULL, 0xFB7F06E9477210E8ULL, 
            0xE86E94EDEFCAD1C4ULL, 0xDD6BC11A39A45506ULL, 0x9021A5F4EB697800ULL, 0x929715ABEA1EC936ULL, 
            0x524E3D071C272A3CULL, 0x5B7E72EF936CF191ULL, 0x45F5768E32AB74C3ULL, 0x47186F67BAA2266EULL, 
            0xCE3E9777C3575B6DULL, 0xBF9425AE541F77C9ULL, 0xB59A3311B7239FD0ULL, 0x5EE5717CF1D891C9ULL, 
            0x9C47F7C30BB8C00FULL, 0x679DDD8B8DE45CF8ULL, 0xD8EA7FF69A9E7A95ULL, 0xEC5587F001D328A2ULL, 
            0x30B9D69CB70A9B93ULL, 0x9709F503EDE746D9ULL, 0x0ACC1C96CCCF59DFULL, 0x77824A50230D757FULL
        },
        {
            0xF644F7F78D6720EFULL, 0xF7F08B0132AB2356ULL, 0x7B562B01A032C3CFULL, 0x6090595D89CD4104ULL, 
            0x5ADDC69AE8AD533DULL, 0x97D046A93D1A076DULL, 0x3AF647391E104BCBULL, 0x0D7BD498899717C5ULL, 
            0x07BDD9B329BCE6A4ULL, 0x71CCC96DD25890C6ULL, 0x975E18BC6ADDF600ULL, 0xF8D02EB7627ABFF8ULL, 
            0xE00B5B2A884153AAULL, 0xA91174849DE7E58EULL, 0x0B2E4130F1830C38ULL, 0x4013C3A06DEBC642ULL, 
            0x18CE0EE8C494A4C4ULL, 0x52864988604AAF65ULL, 0x529F4ECCAC078AB9ULL, 0x6E3062C08343EC4BULL, 
            0xB6E43DD50EF09252ULL, 0x6386E8DCE2FABB4BULL, 0x7A62431A54550A5EULL, 0x74419F8A92976996ULL, 
            0x965F0B3DDF217A0AULL, 0x4D490071BDB5AD93ULL, 0xE5F06DE721F984DCULL, 0x4CF016B4AD81F1F0ULL, 
            0xFAB43D8D0881A956ULL, 0x9F575D4CBF1ADAC4ULL, 0x839AB6662116CFA3ULL, 0xDB399898B3A07FAEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseCConstants = {
    0xE91E14D0D1265536ULL,
    0x33F059876123E1F4ULL,
    0xD5EF5DA9C1FA6080ULL,
    0xE91E14D0D1265536ULL,
    0x33F059876123E1F4ULL,
    0xD5EF5DA9C1FA6080ULL,
    0x0B0B647EC5210EDBULL,
    0x3FD53DD7F987D1AAULL,
    0xB5,
    0xE6,
    0xFD,
    0x74,
    0x08,
    0x57,
    0x4C,
    0xA2
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseDSalts = {
    {
        {
            0x105D77FBE1763FE7ULL, 0x3820E6609912003FULL, 0x5BE7A361BDD7F830ULL, 0xDABD6A8829F66C16ULL, 
            0xD9C0A85C8B090F05ULL, 0x9DBFE20DFA088FBAULL, 0xE312D0E081858556ULL, 0xB84A15686B3D4BBCULL, 
            0x63464D6D95092C76ULL, 0x1457D92F185D1DEBULL, 0xD0D3B155C0E00E2BULL, 0x088506918366E925ULL, 
            0x645C503900474A9DULL, 0xAFE7731FED13CB0CULL, 0x7A44AACCE5291B43ULL, 0x137DB4129B7F7F5FULL, 
            0x6CC62E07D0968C29ULL, 0xD3C916FB275244A4ULL, 0xFC4220B19CBAF614ULL, 0xE00E06DA39E59E20ULL, 
            0x8808833F26CF8706ULL, 0xF83E82A8212AD14BULL, 0xAF962CF8B0614122ULL, 0x25C6B0392DF50F56ULL, 
            0xCA1285ABFB9D1BEFULL, 0x57BA6C953D728BF2ULL, 0x2A28A80408E63D27ULL, 0x5D524A86219E247AULL, 
            0x202D1CB4659C4E2DULL, 0x93C6AB3A76824255ULL, 0x9839E6BAC72159A0ULL, 0x96B3AA926CCDB6FBULL
        },
        {
            0xD4ACF73C8F666BAFULL, 0x54B1F2088D33C41FULL, 0xAAB39C07A6582B0AULL, 0x38D4AD11F5189299ULL, 
            0x6D4A5BB6F6A957D5ULL, 0x23CAE754560B2454ULL, 0x989E0BF9A7F33386ULL, 0x1A3DCC2366767432ULL, 
            0x297203A64C575EB4ULL, 0x3D010BA57C5641E9ULL, 0xFEBE72C5F55B3DC1ULL, 0xA816E5E4A57710ACULL, 
            0xD9A3064B179CFBF6ULL, 0x18786271DB4C0A9EULL, 0xC8A065F8D4FD8701ULL, 0xFA8CC76A84D9AF99ULL, 
            0xAC84DAD6170ECA86ULL, 0xD15AF9A2ECA7D444ULL, 0xF1B02FD887C71C9DULL, 0xA686B1F42F76389AULL, 
            0xB90E5E38DE81B722ULL, 0x1B705656A120136FULL, 0x3DA727B9D081FD94ULL, 0x26C34F4F721106ACULL, 
            0xB3A8F97AD6C2732AULL, 0xEAC3A401EC778CF3ULL, 0x0DAF615CC73DC7AFULL, 0x9B7099037B640E29ULL, 
            0x0CD1E94132DAB1A2ULL, 0xE2AE97F52C114D92ULL, 0x2AE5CDF4A95AE78BULL, 0xF3757AD02627F9CCULL
        },
        {
            0x610C7D93CD2E7D31ULL, 0x519268D49E07CA95ULL, 0xADAD69A336187A2FULL, 0x743B8CB32DC79B88ULL, 
            0x7BA9CEDC5E364CD6ULL, 0xE70B3C63CFAD4E04ULL, 0xA3A32CCDF828157EULL, 0x87E0FFED3AD7BC04ULL, 
            0xE2822A4CE16F13B6ULL, 0xE70BB58562D0D2DDULL, 0x3B65D88B593B32C4ULL, 0x69C8D469AE90524DULL, 
            0x7AD8A00928E9E9BBULL, 0x7FE8902BD8680DC9ULL, 0x70FC767983885CE5ULL, 0x76D89D8814C69CD1ULL, 
            0x63562A3B5CE072E0ULL, 0x3D9C6F396FE1826BULL, 0x0D4EB21218CE1B83ULL, 0x52021F340EB3F814ULL, 
            0xC58DD98BAF202751ULL, 0x49FC3D425DFA09CDULL, 0x185DB696A95B2051ULL, 0xC416F1AD38D4A48AULL, 
            0x7E0E56A6575B3408ULL, 0x2FE2294A3ED2745AULL, 0xC4755DC3BD4B8A56ULL, 0x157D90621020C630ULL, 
            0x95819A5A72D95859ULL, 0x61117146B2F0A263ULL, 0x301C8BABC394F8FBULL, 0x6771375BD5F7DBF5ULL
        },
        {
            0x8B1E2F34FF44BCB7ULL, 0x2A7EA92E6C918246ULL, 0x00B4BAAD5227EAFCULL, 0x098B46EA3A3D5CD3ULL, 
            0x67C35EBCDE082D56ULL, 0x3BF2D73EEBE31DE1ULL, 0x2C6B0DE8EB5A563CULL, 0x9AFF00212F21672EULL, 
            0x078980E42433458BULL, 0x5B158565DB75D273ULL, 0x3536DDB8E1FACF1CULL, 0x491D34DC756417ACULL, 
            0x43EF88086ED7E792ULL, 0x3852D6A1756354EBULL, 0xEF991560E564A484ULL, 0xA61BDC74BD97547FULL, 
            0xC6943DB2EEE65135ULL, 0x0CF6B36E58E3BD37ULL, 0x8246BDC2CBE92371ULL, 0xA250FA47F86CFE2CULL, 
            0x4ECC09A6912EE5D9ULL, 0x74653D8728BAF631ULL, 0xC53500BF7DF3F386ULL, 0xC3DC6C49A970E16DULL, 
            0x49EE5C6182792465ULL, 0xD244D62EF4CD1856ULL, 0xA53F7F1BE1E3E41FULL, 0xD90F4ACF7DCB1B89ULL, 
            0x7B9F1506959A5647ULL, 0xF28DB5704B1DF1F9ULL, 0xB4727E84DEDDEF2FULL, 0x641E6BEAD74C1850ULL
        },
        {
            0xAEE6454D5CB3F564ULL, 0x4EBCD948457BC60AULL, 0x0A74A29D716F1EAEULL, 0x7A596B9151ED0199ULL, 
            0xB344D4BEFBF47ACDULL, 0xEEA90D5200E77BD3ULL, 0xB916053DD4C62C2FULL, 0xDBA87C72670BB52CULL, 
            0x433C66FD8DFED155ULL, 0x1C3E28F3D48ACE61ULL, 0xD29466E6BA379092ULL, 0x599E776CC928324AULL, 
            0xD8DAA8888E20897CULL, 0x5111B4CCBB828C79ULL, 0x2F0C8B40705C0928ULL, 0x5C0FF08A3A7E79BDULL, 
            0x7FABAC610D479553ULL, 0x8C12F799D61F1E7DULL, 0xCE08A053F0FBA9B9ULL, 0x0F662EDDC76DFB7FULL, 
            0x718BB6289D1546DBULL, 0xC038E8923A724DC8ULL, 0x5E8CB98CA0D57689ULL, 0x725B90A8467E7372ULL, 
            0x0ADA2E92550C6BEAULL, 0x0DCD4A14808EC94EULL, 0x96DFB4EC63A77169ULL, 0x8AB2908EDC9298C8ULL, 
            0x132A683FD0AF7795ULL, 0xAE523A6F8D0003F1ULL, 0x7541F650FF8CF9A1ULL, 0x84C6687AD5497530ULL
        },
        {
            0x22A2C055EE86B4C5ULL, 0x7F68764438B87EFEULL, 0x1571762273FCDE20ULL, 0x3D443B63EDAD2F2EULL, 
            0x0B06465626086117ULL, 0xD40732C509FCFC4DULL, 0x38BEE2452B96E48FULL, 0x486851DC4C9A2F1BULL, 
            0x0ABB23877CEB83FCULL, 0x082DD5E10C3F581BULL, 0xE3A3A2F0321993EAULL, 0xFAD99BBCDA510B20ULL, 
            0x99DA774CD20C4EC0ULL, 0xF975386D2F55E257ULL, 0xD4BC11209C218019ULL, 0x23DDDAB273FD98ECULL, 
            0x42E03A860E2CCF2EULL, 0x20B2EA391B6D7186ULL, 0x8A8E65049D7DF6BEULL, 0x3E86A049B7983528ULL, 
            0x34D1A339BB9D7D8FULL, 0x3C5BB8C8BC7BE6F8ULL, 0xBF22C6083BFECD1EULL, 0xBD3267D3CBF766F9ULL, 
            0x276FCB30BBD2BD80ULL, 0x9D7FB3F676D30FFDULL, 0xE83B7EABD833750AULL, 0x440D2E2F0793FE4BULL, 
            0x3EF8BBE513A8278CULL, 0xF77B803AFCC9781AULL, 0x7EEB5121BACDE6B9ULL, 0x600B1F77E4E2195DULL
        }
    },
    {
        {
            0x2161C5C3979CA59FULL, 0x56BFF585E900E321ULL, 0xFD7B1EB746E7959AULL, 0xCA7F696AF447E387ULL, 
            0x511A0B0B5246E2D6ULL, 0x1D06FB27C925B2CEULL, 0x202EA104C507F87BULL, 0xA967012FF34B5513ULL, 
            0xBB34F45074347E51ULL, 0x3730F64C34D9385FULL, 0xC15BB932E590A957ULL, 0x9864056D80418721ULL, 
            0x3DFE367288386660ULL, 0xE319D45333A14E5EULL, 0x3B9BE126896BAA9FULL, 0xE74C6454FC6C4893ULL, 
            0xE091BBD6C2703CFAULL, 0xCD583BCE1F4CCC32ULL, 0x40EC830606FF931CULL, 0xB90C1B13B9B3CA65ULL, 
            0x8D196D77BFF1B3D9ULL, 0xA2E1229767E5340AULL, 0xF1C58170A33289D8ULL, 0x39DE22746CEA843BULL, 
            0xDA3494AB33A91212ULL, 0xAB780221481E3794ULL, 0x34CBE587984FE64EULL, 0xC5EB0A48C2CF269CULL, 
            0xB09B987B5E26084FULL, 0xE3B717C6CA777FC7ULL, 0xADED6439FD116C66ULL, 0x56E3D5650324D1B8ULL
        },
        {
            0xED77A31B1CC84055ULL, 0x4D45B2CF89A6BB57ULL, 0xB9BAE6C34421ACD4ULL, 0x52D6AF0974CE1391ULL, 
            0x7BA7AB183DCA27A5ULL, 0x9B5AF488693DDE6BULL, 0x57DFC1037C6721FAULL, 0x5D133880ED53B38EULL, 
            0x390ABDCFCE8EEA5AULL, 0x151B9DD26215DB1CULL, 0x526AA171D0F78ECEULL, 0xBA5DBE9D2E52B20CULL, 
            0x0B9783FD9104006DULL, 0x9B07A64F9633262AULL, 0x21EB6FE032AA06F9ULL, 0xA86495847DE05BAFULL, 
            0xE69910BD206C9378ULL, 0x908BF71FBE50C522ULL, 0x703A93231A2DB086ULL, 0x240DFA3B5C5FC127ULL, 
            0x7CA0EE6032CBA82DULL, 0xC01A31EB40BB0D8FULL, 0x0355CE365B22660CULL, 0x1038783D4DAC1A88ULL, 
            0x51A3B6547D30B282ULL, 0xE70B0BB934D5C927ULL, 0xB1C9986B8C897AF4ULL, 0xD0A8113DCBA2E3B2ULL, 
            0x84C02C9255D7C746ULL, 0x6E0315BE9E3EB4E8ULL, 0x0EC4E4082584E34AULL, 0xD1FBF9F479B751DFULL
        },
        {
            0x8939BCAF72E32FD8ULL, 0xDB8696B3058345F7ULL, 0x076E4C6D586F4C40ULL, 0xBC27C41DA4CE8111ULL, 
            0x7879BD572A76F3C0ULL, 0x42F8DA8C08F19154ULL, 0x9783920B313C6EFCULL, 0x34A0C5090C06BD9CULL, 
            0xB39EA49E78202DA6ULL, 0x028B448DF3E9F35EULL, 0x9195A53221AB50C7ULL, 0xEBD6D25462F63283ULL, 
            0x9B30D7FD035B3EFFULL, 0xF59DA70FA9C90ACAULL, 0x3EF4A860DC8C732DULL, 0xF948755DE812FCE2ULL, 
            0x0310A144A4C0DFDDULL, 0x893F75DE85A8E515ULL, 0xB2BD7F6855EA76DCULL, 0x532A8217DB79B839ULL, 
            0xEE574E81241BD916ULL, 0xA368E8449631F824ULL, 0x56587840407648CDULL, 0xE030E7989861F63CULL, 
            0xC30685BF40036C2DULL, 0x3F0C9CDDD8D82E8CULL, 0x99C6A38BF9A9F93EULL, 0xD477195A5D59A959ULL, 
            0x06E336A46393FD90ULL, 0x4D0C2212BA4FE745ULL, 0x06090EEE5AA991F5ULL, 0xF21DFED381CD7BE6ULL
        },
        {
            0xF9F060CC4A3A13D8ULL, 0xF1954A1C33040D21ULL, 0x00452529FC512084ULL, 0x38286BD36F3F88C3ULL, 
            0xF93FA6A9A68CE159ULL, 0x8F2A8C0257D6991FULL, 0x5F107D335AD5FA22ULL, 0x34E5F616A1286196ULL, 
            0xA632B288219DD102ULL, 0x33DA4F0A4A8C75A2ULL, 0x7A0388955322CBECULL, 0x03F708D84FE41243ULL, 
            0x4A40C33A22F26A93ULL, 0xB84EA922DCC4925BULL, 0x380183328B281E6AULL, 0x1294C768778F8C17ULL, 
            0xEFB1F3D599845040ULL, 0x5600D4B2CE0258F0ULL, 0xB2ED1A76C867B4A7ULL, 0xB454F7B67C87E792ULL, 
            0x1D26B20A44B9776BULL, 0x5497EB7897B9FAD3ULL, 0x363A7F9DCFBB76B0ULL, 0xDA03DCF9BED103A5ULL, 
            0x460E27C67120BED3ULL, 0xC69229696A0F2EC9ULL, 0x121FE39CD1586024ULL, 0x3F21DE04D9A552DBULL, 
            0x6C6D0A01034C3827ULL, 0x95D635DF70EA3F56ULL, 0x66533DE040746182ULL, 0xDC9769125A3DCC49ULL
        },
        {
            0x69D4E0A46C5B1BDFULL, 0xF4C788F467C5E3D7ULL, 0x77C8BCBD3F943509ULL, 0x8FE4442C5613D94BULL, 
            0x7F5DBDA408C4910BULL, 0xC700673892984AA3ULL, 0x3C989FA7B3E58F16ULL, 0x6C5DEBFB83DE9BE2ULL, 
            0xAAC7417D00D5842EULL, 0xE9F172A4AE17D6F5ULL, 0x399ECCDA071A957DULL, 0xBF4E82ABE6BEB0B7ULL, 
            0xEF3C5DA2BE1BC81CULL, 0xB4CCD9803FA4750CULL, 0x23DCDC6A2BCD68ADULL, 0x8198C85FCAFB01A7ULL, 
            0x01D2CFA55162EA84ULL, 0x9DFE757B1C3DAA8EULL, 0x18F6CB1B03044DD8ULL, 0x3DCC2F131BAD65E7ULL, 
            0x5D93E8D347CDC205ULL, 0x4AFB29A858D1F0C7ULL, 0xCA3EFB742834BA83ULL, 0x2CD2D5C93D1A7CDCULL, 
            0x6D977BD10E3F6A9FULL, 0x3E76FE63D2527C74ULL, 0x200967C54B3AEC07ULL, 0x5EF76B268FFD13B8ULL, 
            0x0A254EBAAB029A8EULL, 0x361F167237F9545FULL, 0x9C45310BE19DD6BFULL, 0xD4AF23E98DCC4FEEULL
        },
        {
            0x8E0F74BB35ABD0E9ULL, 0x9D323A08768C6DDDULL, 0xF775D12FA1D571A8ULL, 0x08F36C0D06A6C954ULL, 
            0x86A21A1B18A9EE67ULL, 0x706138D8FD0A2B74ULL, 0x7C984FAA57DC5BDAULL, 0x93DC1E886DE07CB2ULL, 
            0x317E3DA8B1C06735ULL, 0x27351B727B32086AULL, 0xF689F3A3B270799AULL, 0x42ED624C32558C3FULL, 
            0x383C96B34C4AAA79ULL, 0x62CE1C5131E1180FULL, 0x26AFBAA6A41202D1ULL, 0x4238D01A53F14EA4ULL, 
            0xF827DF0BDA4DEC82ULL, 0xE5BB8AD558C01475ULL, 0x1D3111D708B94098ULL, 0x411B3AF3E43F41ACULL, 
            0xAE712826FF897B96ULL, 0xF58D0A11F4BE899FULL, 0xED2028424A0621EEULL, 0x836A50173E09EB6EULL, 
            0x8D669294164B4C25ULL, 0x16E8D7B735ECDC1CULL, 0xE88F479BD98E0A7AULL, 0xFBC8C39333D9EF4FULL, 
            0x31FD8FE9EE1EA031ULL, 0xDD60F5D7EA698B94ULL, 0x830F68DE622DF617ULL, 0xBFDCBD7E633D23D2ULL
        }
    },
    {
        {
            0x3B7B41DE68B2E65EULL, 0x232133D53565141AULL, 0xE2A4ECB329FC270BULL, 0xA0E7B29399A221C5ULL, 
            0x042415006CCDE5E1ULL, 0x0047DDBBD06A5DE5ULL, 0x2CF07DCA431C86FFULL, 0x905318A314CEE2E2ULL, 
            0xF7703862D146366AULL, 0x3D916ECB00B093FEULL, 0x1EB20F26593FB962ULL, 0x9BEA3204A61AF5F2ULL, 
            0x2671516C88EA849BULL, 0x88518686FD86DFF8ULL, 0x8C12AAA21C2B8500ULL, 0xECD93BFC333A60DFULL, 
            0xC996720CD136C8EFULL, 0xBCA28518EA877360ULL, 0x286846FE5CA1A103ULL, 0x36D29EAA79EC44F3ULL, 
            0x8843DEB8EEC2193AULL, 0x9BCC81FAE16C1290ULL, 0x6858D984667779F6ULL, 0x715C80E4571CC0FCULL, 
            0xDAC1509BBBCDA223ULL, 0x8A90719BBCEC94B1ULL, 0x40A8933E15EE41C2ULL, 0x2E3845B4695422DDULL, 
            0xC4D976E120832DE4ULL, 0x87FA2FB5CAE41543ULL, 0x57100DDB2BE5A0C4ULL, 0x29A7AC5A924E6B64ULL
        },
        {
            0x5EC3FF1D1BA0F39AULL, 0xD5336EC7436AAEEDULL, 0xBABAD443B6D8C4C5ULL, 0xC625BD6F4ECB210CULL, 
            0x3A25D4C0DFE5C430ULL, 0x9C7C3009F35C50EAULL, 0x619E6162C68B1780ULL, 0xB5C0AD2072559D02ULL, 
            0x12B79C6334CB6D02ULL, 0x0092AA032319B536ULL, 0x88648FBCCA9B0A3AULL, 0xDA34E81EEB97C791ULL, 
            0xA4890C32BA9F40DEULL, 0x43F6010431548B27ULL, 0x745AB885B561E5AFULL, 0x045BDB453F213721ULL, 
            0xA848948F7D161207ULL, 0x34C4BD2B8E877E00ULL, 0x32C1FF649D44EF99ULL, 0xB9222FBB8489FB58ULL, 
            0x5A6710290BD2964AULL, 0xA30A1CA8C2E92693ULL, 0xA9F24F5D4AAC4786ULL, 0x9B5ED6476BFD9950ULL, 
            0xA50F9F476E1AE27EULL, 0x64C6027EA19E2E42ULL, 0x4E99B9EC84EBB5F8ULL, 0xD5C870F3DA546838ULL, 
            0xE72E78267DEA44BCULL, 0x3AA91418B12AE226ULL, 0xD0D193F3699A6833ULL, 0xE6929EB77EF1C191ULL
        },
        {
            0x938F63AF0153524DULL, 0x2B8140D60D99F0A4ULL, 0x15BEC3B21DAF022BULL, 0xD585E16C002F011FULL, 
            0xF804A15E86CA4E33ULL, 0xA4FFEA4917A175CAULL, 0x673CFD8A2E650A67ULL, 0x0B5F442E8BB5AE68ULL, 
            0xEE5EB970CD670EEFULL, 0x57A3B23D8A5B2202ULL, 0xA866950884606A84ULL, 0xEB9310D9479494AAULL, 
            0x513F0078E3754380ULL, 0x072041865497B332ULL, 0x7071A74BDF676A00ULL, 0x35DF6AFBEDA9CE97ULL, 
            0xF90E3A8B5585A153ULL, 0x7E2FA98E298FC7F8ULL, 0x00078B52C549B445ULL, 0xE3A3FC44FE68E404ULL, 
            0x3F3C128A4C140EF2ULL, 0x87BD6A2068EC7B20ULL, 0x3011619E30E6B360ULL, 0x1427369FEBC4105EULL, 
            0x92115C1E4C4C995CULL, 0x2DF08ED2DA2E48F1ULL, 0xC2BFA79ED43408E8ULL, 0x1303F291384C5947ULL, 
            0xDF8BE72AC4C8C34FULL, 0xA8EDC0FB44E7916AULL, 0x53EF0D3A3CA99F78ULL, 0x274634EC34A8FF2EULL
        },
        {
            0xA6D934799DC2DB5FULL, 0x657CA83FF0168F2EULL, 0xBF62FC35AC619C2AULL, 0x9E286E12F77EC202ULL, 
            0x4523A5522F1FBBBBULL, 0xDBC69C0D4FD5603FULL, 0x781BB55617D5FABAULL, 0xE97D074CF35F196CULL, 
            0xA611B20F47C5AEA4ULL, 0x6B432359930A8C60ULL, 0xF82ABA23AB3D50D7ULL, 0x91B9909511582096ULL, 
            0x7CD5032DE5B0CD7AULL, 0x872CA49C4560B4DFULL, 0x0F6424547046A5AAULL, 0x618888B10A9C2229ULL, 
            0x99190A8425459D6FULL, 0xCE11CB7690293640ULL, 0x02B7FCA5F7F36F28ULL, 0x511D33C9962B2014ULL, 
            0xF8C5D2678A538352ULL, 0xB1F57ACF8E4A581AULL, 0x81F646E99EA27507ULL, 0x2DACDB95E5C82F91ULL, 
            0xE80168BB1B42EEAFULL, 0x5827A2BBF95A2A7BULL, 0x3B3F753748D20649ULL, 0x23FC6C42A64636B7ULL, 
            0x0FA3BB38A3127336ULL, 0x4DA0F2FEF317E67DULL, 0xFB0F088284B5E4CCULL, 0x43DDFAC4C5DA628DULL
        },
        {
            0x2EC001055DAC9158ULL, 0x3D932E87D546DD03ULL, 0x7AAF3DCF5A8206C6ULL, 0xF4738C22BE4FCF5DULL, 
            0xCBCBB6DEBB477451ULL, 0xB9FBE2AEE45DCBDFULL, 0xDB39C37F5864C93EULL, 0xE94806727EA5DF9DULL, 
            0x366A268EF27E44B2ULL, 0x13D27033238ABE96ULL, 0x1E5F908FCADA2DDAULL, 0x3E964A10C1FD6580ULL, 
            0x337B39FE342A7D38ULL, 0xBE9FEB3DA2AF9F76ULL, 0xB998DA7460A1325FULL, 0x7E8D51A4479CAB0DULL, 
            0x75394A6F0510AC39ULL, 0x8F4FA66B70545DF5ULL, 0x7D0B99465A55AACEULL, 0xE814BF3A35B847B8ULL, 
            0x6095B0C76437AC6FULL, 0x4CCE5750C03772F7ULL, 0xBDF952DD991FCB28ULL, 0x6A29F6323A34C072ULL, 
            0x9F267176E943D654ULL, 0xFE628AAF803D65E3ULL, 0x619E2776A4CAE9C6ULL, 0xDA6176C814F6CDA8ULL, 
            0xA78B9173DA948193ULL, 0x19AADC3A4276DBD1ULL, 0xC73792A877C3F318ULL, 0x5B01D47509FAE2CEULL
        },
        {
            0x40E3D958D0DEEEFAULL, 0x4CC60251D4D44CBDULL, 0xA9F1420602E73FEFULL, 0x71DF8EFC8556CAA5ULL, 
            0x91B6AEC527D2E580ULL, 0x8DD353E101BBF21DULL, 0x77396AD7434FA769ULL, 0xCCBD9211E4759841ULL, 
            0x33220E202DFB0432ULL, 0xF0D4BB1A8F0CEA0FULL, 0x29248A4CA41E3489ULL, 0x4819DE8C81EBF5CAULL, 
            0x10EC937117089DF5ULL, 0xD52F1B7F44038DDEULL, 0x3DA8AC9AA006219AULL, 0x82DDFBB9EBEDFF1FULL, 
            0x430EB2F3D3BE082AULL, 0x2BD6FB88046C5A4AULL, 0x1335EED8239730BDULL, 0x6BED30B04B54FA39ULL, 
            0xFF548BDD84485E36ULL, 0xC0B48DFE78CEC4ABULL, 0x9959893643CE473BULL, 0x9688E37806E3EDC9ULL, 
            0x6C841E506C338362ULL, 0xD7A9A99DA352E792ULL, 0x8AAD714E2EC62BDFULL, 0x6DF8FE813286AA6FULL, 
            0x2204F817B5F46910ULL, 0xE9E000AA7BCF9C02ULL, 0xA2133F39D65087D2ULL, 0x9A79968055E79876ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseDConstants = {
    0x00477663FA68F26DULL,
    0x74A126A8AB5BADA5ULL,
    0x1288B0B6FDC2B9F7ULL,
    0x00477663FA68F26DULL,
    0x74A126A8AB5BADA5ULL,
    0x1288B0B6FDC2B9F7ULL,
    0x8CEF4DEFCBE35421ULL,
    0xAF7C3805139B9597ULL,
    0xBA,
    0x0D,
    0x62,
    0x8D,
    0x85,
    0xC1,
    0x13,
    0x90
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseESalts = {
    {
        {
            0xEDEB28828C44A53CULL, 0x136472A33DE6BCFAULL, 0x67E47466059403ABULL, 0xD04C2CF33CE33053ULL, 
            0xCE03B6DCD00475F7ULL, 0x6AE4462B32B8AEF6ULL, 0x95494F7B5530C0D8ULL, 0xFD129F793769CBC3ULL, 
            0xE87F6BB158E98358ULL, 0x3DF2A6F72C6F234FULL, 0x165BB0E0CD362D5AULL, 0x74252355794DEF43ULL, 
            0x508B308E388EBD32ULL, 0x39C1FDE0B8CC0726ULL, 0x1A53ED5C0848F47EULL, 0xEE53E6A0F91F6319ULL, 
            0x6898ECFAD82E6024ULL, 0xC844C48207E08095ULL, 0x35BA7786B286FF60ULL, 0xA51AD260AC06DD87ULL, 
            0x2584F5629C25F0D7ULL, 0x164A4A74DE0AF6F8ULL, 0x85331476B1A34CBFULL, 0x9971CB65F2E0A6A7ULL, 
            0x839F935D144C38C5ULL, 0x32AA5847E293069BULL, 0x302EEF3FF4CF77D9ULL, 0xE5C2A3D0A62B870BULL, 
            0xBA79A0E59A2C363AULL, 0x87BA03A60BDB36AFULL, 0x646737CAF24CF798ULL, 0xA90B1B13250B0CB5ULL
        },
        {
            0x390F5C0194A4EE14ULL, 0x5BBE49768838F6DAULL, 0x36CFDCEEF99C16F3ULL, 0xDE65A9012833AAD8ULL, 
            0xCD69F7C2C0C20402ULL, 0xB644B2DCB697843AULL, 0xDF7006FB48203A23ULL, 0x27C410F639E765E8ULL, 
            0x8BEF965375C5AB6CULL, 0x03F8381B03895D59ULL, 0x882ABE314E2A7F26ULL, 0x833418B2B9F44D46ULL, 
            0x6CCD3B6027E0910AULL, 0xDB724B1F788269F3ULL, 0xD25D699201B6F61AULL, 0x8F1F365B4FEAB0D0ULL, 
            0x1CC62BF8316B83B3ULL, 0xDAFB0ED1927CDCF8ULL, 0x080B2C892C334739ULL, 0xBA2009D32F16402CULL, 
            0x6FAE95A1691615A2ULL, 0xB11E481C8E325AFDULL, 0x933F9439B23D8C2AULL, 0x3AFE8A2DD77E9F49ULL, 
            0x5270DB4C95243D69ULL, 0x360581C7C1B7B27FULL, 0x327CCD801EA38C05ULL, 0x60D7E4CA93DB5100ULL, 
            0xEDE3C69225F74E85ULL, 0xC3E1B6143EEAF60AULL, 0x4E26A5326AF6E1A5ULL, 0x23CC26B0C3D9C8A1ULL
        },
        {
            0xE4B1E5DAF8E40BC6ULL, 0x94A523340DFFCEBEULL, 0xEF1939B51B9CC2E2ULL, 0xD4AE920C7A43618CULL, 
            0x7AF69E481EEC3C71ULL, 0xA0030F2209614090ULL, 0x0E1D5A14B4DC2A07ULL, 0xEAAFFFF1E7A093B2ULL, 
            0x2D748666573B8439ULL, 0x54E6E4BD06D378A2ULL, 0x89EFD77FD2079C27ULL, 0x2194775163277A10ULL, 
            0x8B5F66D23D7331C2ULL, 0xC4AAD765FBCFD5FFULL, 0x825AC03AEC05A2C6ULL, 0xA343ACC08CAD05F2ULL, 
            0xB16D099333F725FAULL, 0xB98A6AC906AF35C1ULL, 0x12288E5E98A5092AULL, 0x4066166B446A45EAULL, 
            0xB9035998D06965C2ULL, 0x7DB0D1ED467C0DB5ULL, 0x493ED39671CC26A5ULL, 0x5B2B6D15824F4515ULL, 
            0x78497DC79CCBF1F4ULL, 0xF928D0B0346C3A2EULL, 0x8EB2DA8DE9ACE5F8ULL, 0xA8C39AA8C5E7E498ULL, 
            0x5ED643E2883FFF18ULL, 0x1A6EE59345DBD28BULL, 0xE093037FF591ABFCULL, 0x323552DAB8D119B3ULL
        },
        {
            0xF9FB22EF08AE29B8ULL, 0xAF3F885961DDACDDULL, 0xD4C77829F17620BFULL, 0x7AE4A1282E5FDE77ULL, 
            0xA06FBC3022BCF9F4ULL, 0x275E536B99E27694ULL, 0x857E0F28B0EFFC2AULL, 0x0E8D9DAFA99CAF3AULL, 
            0x2BD9EA1B4A5D20D2ULL, 0xF1F554215E3BD41CULL, 0x2F1830FCD15D21A5ULL, 0x463EEF89685C3A43ULL, 
            0x7A2A462BB7096833ULL, 0x99F2506B1376A781ULL, 0x0111E19D45512CA3ULL, 0x96C302B9EDEFFF5BULL, 
            0x7459C9F4E5733CB0ULL, 0xF60FB23B870DABFFULL, 0xE74C22F7BAEA2654ULL, 0xB71E184F60021CEBULL, 
            0x7FD2FD861214AC8DULL, 0xA1200C157E2DCEEDULL, 0x0E00B09B29F1C5D2ULL, 0xDED9A539DAFF2E08ULL, 
            0x619EFEADD5F5AFD8ULL, 0xF8DB09B5D1F0CC41ULL, 0x066FDA500E73CF13ULL, 0x60FEE175A6174907ULL, 
            0xB1ACD8B9375D1A64ULL, 0x328376679FCA4433ULL, 0xEC8B4123061101A8ULL, 0x5B3E0A64AEF37BA9ULL
        },
        {
            0x7B20693FE6209ACAULL, 0x08EE7EC01CF8214AULL, 0xA08CC443553A9147ULL, 0xD5830D8CAE00AD1EULL, 
            0x19E9B6D73E156A22ULL, 0xC17BC02A9E4338C2ULL, 0x17F5D5FE50BDEB81ULL, 0x46C89BD337993D9BULL, 
            0x78A7A8D0FF2A69A9ULL, 0xF19EA8F078E3253CULL, 0x3766874648CDBCF7ULL, 0xDA07EF9C30A65362ULL, 
            0x0089E3078FB0C104ULL, 0xCCD4D9265B6FC037ULL, 0x7EB6274F5DB23CB0ULL, 0x4F1371A161CBCCE0ULL, 
            0x94A79E05F4CB9054ULL, 0xF94AC7AA7EB526E9ULL, 0xB61A63B970CF2C09ULL, 0x0050B5DCEC9E0AC9ULL, 
            0xF4874A11FAD0BA4DULL, 0x2C9BA15B62D011C4ULL, 0x128E75BEA714B01EULL, 0x9851B297ED4A21C5ULL, 
            0x4AB972735B7128ECULL, 0x870BEF2696365D45ULL, 0x65D73FB5590B6428ULL, 0x43BC851AFAC8F10BULL, 
            0x0062C8407F61CE11ULL, 0xB9ECAF1096A08922ULL, 0x366D81E96BAB8033ULL, 0x4C2E5AB82E049502ULL
        },
        {
            0xE848E179AC22ADFCULL, 0xF235E720A7FBD61EULL, 0xF8EF86064B81C0ABULL, 0x930D0FFBB417B03CULL, 
            0x36310695B132BB34ULL, 0xF331EA23FA755C52ULL, 0x38723A1CD022A46AULL, 0x1514490CC4496780ULL, 
            0x0A2266B73D1C3FEEULL, 0x238BF14FE579DDF1ULL, 0x304F17505AFD87BEULL, 0x5CF8ECC7C2208D13ULL, 
            0x0BCA4264FF8CE023ULL, 0xA9C8E9D57B3A347FULL, 0x9FCEDC963E3F5388ULL, 0x8867FC10D89D206DULL, 
            0xA071ABF371B7CC0BULL, 0x0799989A2EBD3B02ULL, 0x2AF23D2C9E85F3FBULL, 0x856CD56CEDCFEA82ULL, 
            0x3F9CB2DBD491C1A9ULL, 0xDA2A96EED4D7013AULL, 0x3792F6A2BD58AFFEULL, 0x3EEC0AE65EB295AEULL, 
            0xA912BD7A7CC84FAEULL, 0xCDEF797544B3F1DDULL, 0x10B99F3A59903AF0ULL, 0x37146290B5AC9913ULL, 
            0x14C41CA08D2B053EULL, 0x11643F8A728E5743ULL, 0xACBF4DD05DF4B685ULL, 0x52B5B7C4BC4BFAB2ULL
        }
    },
    {
        {
            0xA8814FDEDEB19B7AULL, 0x38D97F075EA179E0ULL, 0xC8CD232DF9779C2BULL, 0xC34A061E85AEB611ULL, 
            0x502925E26DCFF0A2ULL, 0x367455D6FCCB0C58ULL, 0x563FB2AEF83F82E9ULL, 0xF56FBC971113A175ULL, 
            0x5BD5BDCDAD69FBBBULL, 0xF68798A5D38596E3ULL, 0x2DD9EEF55C7A406DULL, 0x454619A3DD132AA2ULL, 
            0xF3A8A0D54FC0A200ULL, 0x58EC0A1524C47031ULL, 0xF571482D38DED892ULL, 0x43FFACEEA2CCF676ULL, 
            0xBE8793B1B20347C3ULL, 0x14634376C8DB5CA4ULL, 0x227ACCCD9693EF86ULL, 0x47B9727161656988ULL, 
            0xFC47DA8D3DB6ECDDULL, 0x2B52B8176428CE2EULL, 0xD76F9AF2C7415859ULL, 0x7DDD89DC8E82FACFULL, 
            0xCDB0C6177CCCE605ULL, 0xF6F131645DF93C49ULL, 0x9EDE9B27DE6DFBC3ULL, 0x5D801B845929677AULL, 
            0xA6E1F26D00C6D6A8ULL, 0x293F3CDAF4BE268EULL, 0x097A216F2507AB43ULL, 0x40039C885461A28DULL
        },
        {
            0x99B236150AB145C8ULL, 0xD4C0DE724B51ED1DULL, 0xED3DC8F0839D4044ULL, 0x88D45840BEA309CEULL, 
            0x72312A46DDEF2136ULL, 0x18B82C22EC93C03CULL, 0x48E0B8005266ED41ULL, 0x1AA80A55F32C4DEFULL, 
            0x31C6763882099072ULL, 0xE9D4302D09A16DADULL, 0xDA94B780CEF231F2ULL, 0xD04F4B64E60CE02DULL, 
            0x967EBBC89F3E9093ULL, 0x2F03285B6F6B226EULL, 0xF9BC48F5526B8D71ULL, 0x250FCDEEEB88819AULL, 
            0x9753C71B0E84FAF7ULL, 0x0559E91FC4A0BBE7ULL, 0xA26EF8712A7CD285ULL, 0x39C83AA84B3555ABULL, 
            0x8419FBEDBC1D74AFULL, 0xF61ECB2DA92742C7ULL, 0x52704D414B31A541ULL, 0x8784F18E45CD2BABULL, 
            0xC326DD857959A895ULL, 0x7C2AA1687CAE0C21ULL, 0x0C96E6E8A9DF85C0ULL, 0x77D5B479DF8225FDULL, 
            0xFB7FFF1B37F23D56ULL, 0xFD19457762E71798ULL, 0xBF22BC3DCE758CCDULL, 0xF927093040A8ECF7ULL
        },
        {
            0xBE35158AB625D979ULL, 0xF7DFD278A001E234ULL, 0x1AEEF53E28A85FE6ULL, 0x96DCAF10379DC802ULL, 
            0x89333088031AEE76ULL, 0xAC06E6869BD18044ULL, 0xB12500872B2A8908ULL, 0xFEC92919E5E044C3ULL, 
            0xB90095CC03810B26ULL, 0xB33FAD5C907A2985ULL, 0x0A283F98A32825BCULL, 0x02F280D6116674F0ULL, 
            0x7C751251ED0F2E89ULL, 0xA9E303FF04B47157ULL, 0x4677259DB7D458D4ULL, 0x57074167181FD757ULL, 
            0x49194DAB4FFD3708ULL, 0x3A5EE14EB29ED013ULL, 0x08EF4F445CB0E43DULL, 0x587FC8C05FCB041AULL, 
            0xF5A98BF03FCBBCA0ULL, 0x478A275D2A353CB9ULL, 0xCE4D56F16681069BULL, 0xC85B576B77A40232ULL, 
            0x487E909E8BEA6096ULL, 0xC88334C4B67B6353ULL, 0xCA16335F8E4E1A87ULL, 0x4F8D36E70BFD71E1ULL, 
            0x1C693EC7280C894CULL, 0xA59CDCE6235F9708ULL, 0xE2210DE251D8D191ULL, 0xEDD2515DC8952157ULL
        },
        {
            0x976EDD9FB56D921FULL, 0x270365FE51C54824ULL, 0xE87D074C465AC541ULL, 0x2850FEE5D57E45B4ULL, 
            0xC13579DD424C19EBULL, 0x01DB295DE1E696D8ULL, 0x5A43FAABA09126F9ULL, 0x32A54EA2F2F18DA3ULL, 
            0x9B77838D5233B0D0ULL, 0xDFE9A4BB7E40E22CULL, 0x2CE609166ABEB7B1ULL, 0x27780B3243825E33ULL, 
            0xC566B5E936DF51F8ULL, 0xFC1990164EEAF336ULL, 0x81054BD010B5DB73ULL, 0x9D607547D186C428ULL, 
            0xBAF43FD30A8FFF1EULL, 0x3621B6CB030E70B0ULL, 0xC080AAAAE2D9C176ULL, 0x6832546E173774D3ULL, 
            0x3088EC981268056BULL, 0x5E4007BB512779EEULL, 0x5DFEF799637A771AULL, 0x768961E350759A1EULL, 
            0x9AF4FBF21D3FDCE9ULL, 0x10A99D98A0E91627ULL, 0xCB5CBC2DE528DF92ULL, 0xD5790CCBFCB7A50AULL, 
            0x2F75C03022322702ULL, 0x8B996DD59C341A11ULL, 0x2BD62E4891190717ULL, 0xBADEBB697AAC0DCDULL
        },
        {
            0xA24BEA1E8E7A1E61ULL, 0x1E9384B2CD9149F0ULL, 0xBECC755731E04AA1ULL, 0x8F1C4C31D1AA81EEULL, 
            0x592F6B316C8FCA08ULL, 0x7AE5792F9C3BE612ULL, 0xE46041E5F5238881ULL, 0xFC8104C0A66FE18EULL, 
            0xD7DC6119A483241FULL, 0x350D4A51C4395139ULL, 0xBC890A84297E8760ULL, 0x2D10957721006835ULL, 
            0x0743448ED56A562FULL, 0x76F32788962CE520ULL, 0xE578DD12141EE503ULL, 0x1E3202BCC1BFE417ULL, 
            0x4266528CDB5EEAACULL, 0x7EAB1B0F73D639B4ULL, 0xFBDD84E01C770495ULL, 0xCCBF7E92F8D5705DULL, 
            0xAD4CA7424A38FA95ULL, 0xD4A18F171EC7CD46ULL, 0x75402F3116DECD07ULL, 0xAB4B53B6E63FA58DULL, 
            0xCE81B2980D88F06EULL, 0x02C7100138024AEBULL, 0xFE325ECD81F11262ULL, 0xE432ED671EFEE07EULL, 
            0x63CE19BAC4388E4EULL, 0x321890FBF9B4C990ULL, 0x6DD1D9EE83DF1E65ULL, 0x6CFD63DAAB81D2D7ULL
        },
        {
            0x1C08D57B47128E34ULL, 0x0C264A3F7443F40EULL, 0xBA8034E36610E485ULL, 0x83D8E723E501F63AULL, 
            0x256058C9AC8F72B2ULL, 0x248B45BF6D20062CULL, 0x295D7833DCCB7E9AULL, 0x11E328F0B223DAB8ULL, 
            0x6B62B4E75845E417ULL, 0x566930F27BEE7EB8ULL, 0xED470747A57372D5ULL, 0xDD2AD30DDFB9FC3CULL, 
            0xFE6010A043D879B8ULL, 0xE729277136D27ECDULL, 0xAD2F5C04CC546F99ULL, 0x26E0618FD974062DULL, 
            0x2EF4721E9C4E4F47ULL, 0xEACA86C95310FA94ULL, 0x29807D9D3BE5EFD3ULL, 0xF13AD16D04C0026BULL, 
            0x403BE73F47810395ULL, 0x0F1F11C71B13597CULL, 0xB47666B844EEC9EAULL, 0xE8ECBFA069BA6C99ULL, 
            0x63E429CB398F8389ULL, 0xFAA053726B14F089ULL, 0x99CC8E2728A3EE37ULL, 0x08DFEDEAA38ADB04ULL, 
            0xA70BD9D68F4404D9ULL, 0x47853ACED377E5C8ULL, 0xE1AC1AD75D44DC33ULL, 0xEDD5DA49D77062C8ULL
        }
    },
    {
        {
            0x4B3CA6C1BFB45690ULL, 0x7DED3E767C5BE3B0ULL, 0x1E9443313A7112AFULL, 0xCCAE9CAC88207FE3ULL, 
            0x6D760FB5D95D7C92ULL, 0x86E0198EBE529665ULL, 0x5B3395D31FEABCBFULL, 0x0EF7BD558B07F52BULL, 
            0x7C8028B620DBFD97ULL, 0x6DE6DC9DA0442137ULL, 0x872047103A679C63ULL, 0x64F0F5B2B1FE330DULL, 
            0x078267983219CD2FULL, 0xB9EA784094A5C24AULL, 0x78BD11AED178AC90ULL, 0x64AD74DB9087DCFEULL, 
            0x5F8E15243AB60851ULL, 0xF8B9A5C1A69EE46CULL, 0xAACBE29F6C98340EULL, 0x9B52D7B423AAC262ULL, 
            0xAB4079E289BD243EULL, 0xF37FA369810F8C7FULL, 0x3C068E7A07C28DFBULL, 0xDF3495FD6A6E24DDULL, 
            0x12BEC4B56345510CULL, 0xF3FC168E580B5E5CULL, 0x56338908EF239E8AULL, 0x577AA15121FC1C50ULL, 
            0x68B0A240E52BBAE6ULL, 0x2DD58DAD15A0A4CEULL, 0x6A93FB770DA93E36ULL, 0x1397668459314709ULL
        },
        {
            0xDEA216982376452DULL, 0x659EB03B581C9C69ULL, 0x4CF493D17DB20E39ULL, 0x750B6A6692314362ULL, 
            0xA5BF575C0515BA58ULL, 0x2DC0ABCA667186AEULL, 0x8FA6FAD6350123A4ULL, 0xBB21D3500181E178ULL, 
            0x38BB0773D1CA4B91ULL, 0x07DC13AE54130842ULL, 0x06810A5551CE5629ULL, 0x7A31E866F68AD199ULL, 
            0xDB58AC12327A1853ULL, 0x60499DC7796DC060ULL, 0x515BE18FBD37EAE6ULL, 0x664B6A5E1E481B99ULL, 
            0x0FDCA82B4134EB25ULL, 0xD0CD7851E8D08E1AULL, 0x970E1072A3C086F0ULL, 0x4E978BFB8D26B9F9ULL, 
            0x6F59A56382781FFCULL, 0x01655891462780F7ULL, 0xFB9C4A4B98097219ULL, 0x59913D384C50E1BFULL, 
            0xAA9D56DEFD6D5AD3ULL, 0x02BE642F5A3CFF86ULL, 0xB3F13936357D756DULL, 0x4637A24C24B8FB84ULL, 
            0xE6D5806490B4E719ULL, 0x503A51AF985CCF4CULL, 0x78E94E3F872F22A5ULL, 0x71ADD4AB4EDB2D2DULL
        },
        {
            0xC24ACE2C88CAA680ULL, 0x48FDB40BF6CEC54DULL, 0xDD23D912A9671F57ULL, 0xA3B96433ED8A4E83ULL, 
            0x24CEB7F4A7D9CF5BULL, 0x1BB1D3486E1324BFULL, 0x5F9CF5D86BC26FF9ULL, 0x8CF5891922F51D50ULL, 
            0xF439CB88A4490415ULL, 0xDA811053A37EBA4AULL, 0xA059F1D7D19DAD15ULL, 0x5A20C7472C30D6E8ULL, 
            0x6BC8B8EBD8B670A4ULL, 0x81258C57A8CCFDBBULL, 0x245FCAF351B6FDB0ULL, 0x780A700366029339ULL, 
            0x76523D97B44BD6E5ULL, 0x59CF29FE537C1E36ULL, 0x595057B9742F75D0ULL, 0x291D6A13331E6951ULL, 
            0x49F4905C93A75AC9ULL, 0x10CA2711D3B77BE8ULL, 0x941F3163ED8DF408ULL, 0x3112498640FDB3D4ULL, 
            0xF4117B392BF1D5D3ULL, 0x93809A884D29D061ULL, 0xB976BC5D0922DDA1ULL, 0xFD9D3DFAC947EAC4ULL, 
            0x931934FB0EFED7EFULL, 0x75686525A47FA887ULL, 0x95FC58C5CB550DD0ULL, 0x99E78E7DD1A25D12ULL
        },
        {
            0xB77B7EC64AA64650ULL, 0x6D5A19E7817D2BD1ULL, 0xDA86B4B65A444D6EULL, 0xC9BECE099C515AB3ULL, 
            0xCE7606E478E5BC68ULL, 0x60AFF4847C623241ULL, 0xE06E43861B3622CEULL, 0x148E912F817339FEULL, 
            0x7E9F0AD924FA0BCEULL, 0xB26B36E44746B5EFULL, 0x3980DE1CAD850548ULL, 0xA55B8C065AB4E722ULL, 
            0x0C5D583F76939270ULL, 0xE8CCFF77F3F7BE86ULL, 0x0C7E25E02EA2C395ULL, 0x17D4A95132DB3C30ULL, 
            0xA77EC77238101119ULL, 0x8ADD824EF38C50DBULL, 0x4E0A38C25AC61032ULL, 0x5E74D2B09E44D984ULL, 
            0x4A507F898B6BD2EFULL, 0x8ACE15EF4C3F0EE1ULL, 0xFC51BE7D6107A303ULL, 0xC880419665B346D5ULL, 
            0x2FB40F56AD67E9C6ULL, 0x9D74312DFEAF30A4ULL, 0x7C37B2112DCE9264ULL, 0xDA37589C198B53B0ULL, 
            0xB3C6D2669F023BAFULL, 0xC6546EB194D7FB90ULL, 0x98D2BFAF80461900ULL, 0x73390B3866CEE19FULL
        },
        {
            0x9B66A1BA63EA3A89ULL, 0xBC92B84C2BB23D18ULL, 0x52272019D0A1A30AULL, 0x21C2DF7C41537925ULL, 
            0x5D9D4C427094DEE0ULL, 0xF4CF8BE095257F83ULL, 0xD3100BA4F36E2689ULL, 0xBE988804E89B3E22ULL, 
            0x8FC06B79921C5514ULL, 0x3F669D4E3A833704ULL, 0xF3F8C3B91D9FA4C3ULL, 0xD9E088C149D654F2ULL, 
            0x1DE13A569D4293B0ULL, 0x78BB04724ABE3643ULL, 0xD1D93F8172960B4EULL, 0x1D00A58C4085775DULL, 
            0xEE7721160390F277ULL, 0x28921881DF9AEF7AULL, 0x820B68EAC6D80CF3ULL, 0x21E10F4BAB5EE87DULL, 
            0xB6E3DA7ED9185C2EULL, 0x87C8429517E83526ULL, 0x3C12C8DCAC2DD874ULL, 0xCEDB1C8F57C3B271ULL, 
            0x2113D6011673FE10ULL, 0x144B5C1A9FE6BD07ULL, 0xF75FF395CDB58B42ULL, 0x7F8458035EC14381ULL, 
            0x98B2D48B62396DD3ULL, 0x402BDFC74D7B5766ULL, 0x312608CCAAFBCBD5ULL, 0x6CDBA3685A2C82FBULL
        },
        {
            0xB5E73EE595D82E13ULL, 0xD7EC4ED5584C6A8AULL, 0x8841ABC0966D0A33ULL, 0xB60EB27DEB901D18ULL, 
            0xD7732C931F301396ULL, 0x1345D53394B45ABAULL, 0x97911FB5781B73F2ULL, 0x3D2897E59A986588ULL, 
            0xB9C0F5D56F8A5E98ULL, 0x1A7894EBA8FA445AULL, 0x611EC68611E28899ULL, 0x2DB0DEAC9BC01C82ULL, 
            0xE06E219F060C38F5ULL, 0x695E0813DB9C01FFULL, 0x72E78C6C65DDDB4CULL, 0x05527E8D9544AFE4ULL, 
            0x399852B364AA923BULL, 0x24083FC9E4BF37D1ULL, 0xFA41C98DD1604ED5ULL, 0xE4DEF8B9DB54F070ULL, 
            0xFC2C0F25AD61CAA5ULL, 0xE672DC0E284FB8EEULL, 0xDCED493BE3093E79ULL, 0xC5E0BF1C3B187F26ULL, 
            0xCB82BFA65D934B95ULL, 0xB426C6D609AA5449ULL, 0x86CBC3EE39A9BF68ULL, 0x82BEF202E8D3C3FBULL, 
            0x46D7B001ADA3C1DDULL, 0xF6E20961CE8F0B73ULL, 0xCF9CA184A1066239ULL, 0x6170D292AAE1A33FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseEConstants = {
    0x9B480459F0272E87ULL,
    0x21BD5AFA73BF978AULL,
    0x1D1F5A4416672121ULL,
    0x9B480459F0272E87ULL,
    0x21BD5AFA73BF978AULL,
    0x1D1F5A4416672121ULL,
    0x6075A177D351D3A5ULL,
    0x4B35EF63C08A35A5ULL,
    0xE4,
    0x95,
    0x4D,
    0x39,
    0xD0,
    0xA4,
    0x4E,
    0xB2
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseFSalts = {
    {
        {
            0xCD989078F8B56EBBULL, 0xAC1299488AC90078ULL, 0xBF79AF3F6C1A71D2ULL, 0x7F31BE04F23F7F24ULL, 
            0x1039848C01B129EBULL, 0xA0B776CE5617E782ULL, 0xE76DC5275BD9921AULL, 0xA217690ED4850176ULL, 
            0x7AAE5B6C2904CF6BULL, 0x7D677C493A414B06ULL, 0x780277F6AFA91961ULL, 0xFF8B5965FCB2F54FULL, 
            0x88E393B7006B9D5CULL, 0x906B7B4169126B4CULL, 0x0E336956DC6B413FULL, 0xAA04FA19678FEAC3ULL, 
            0x1A74DBF8E895B860ULL, 0x928431063A086B22ULL, 0xFED75F1BD82C824FULL, 0xFA4CB3A2174938AAULL, 
            0x52ED19C5744AB762ULL, 0x2ABFE2227450AE85ULL, 0x4020AB8FF66883A3ULL, 0xAE7F6EBD363C4F69ULL, 
            0x0B9EFA3F9B972924ULL, 0x944E98368EDA9DE7ULL, 0xD0BEC055F0636B73ULL, 0xDF8634D1B1AE0A62ULL, 
            0x242242116DE53E2DULL, 0xFA95F727190C6448ULL, 0x7D6A0CAF9C842C3BULL, 0x48E12CA38BA45F50ULL
        },
        {
            0xDE520C9D2279A510ULL, 0xAC4A882EE771542AULL, 0xE545D6AD04C9E8AFULL, 0xD95FA3272759E688ULL, 
            0x1C549208A8EC1EDDULL, 0xF8ED902D059B347BULL, 0x6A3C4DA8F317581EULL, 0xB89A2BDB18EAB730ULL, 
            0x173EF7E78CA2D28AULL, 0xD218F738D4061954ULL, 0x0F477D7A3D378900ULL, 0x318310AEA40F17F3ULL, 
            0x2E13D1916616B7E3ULL, 0x732962E883C7B6AAULL, 0x6BB95186553664D0ULL, 0x7E1195F6194687C7ULL, 
            0xC21D1E687DDCA6D1ULL, 0x1D4F4F4053F25B2DULL, 0xBE7AEF0160610E94ULL, 0xA89F0E5C7E6C8285ULL, 
            0x69F37FDF6B58CEF0ULL, 0x5C9F80C856A5DFDEULL, 0x9B0A12CF37F44153ULL, 0x66263D5480870207ULL, 
            0x9666FF9DEE82D26FULL, 0xB5CAEA6181893408ULL, 0x6B135CB3B0276181ULL, 0x007BBD8B10481E01ULL, 
            0xD086D98BF36B922DULL, 0x98EB5122496A002CULL, 0xEB2415C99461D44BULL, 0x0F2C1BD132C67FC1ULL
        },
        {
            0xCB561E855C41D272ULL, 0xFFED5FE12C573040ULL, 0xA44C765FCEB06C2EULL, 0x3028EA5640D5E1AAULL, 
            0xAE59F59C4DA4A918ULL, 0x42B181C5AD39F859ULL, 0xABBA26A7CDA35ABAULL, 0x33F7C8ED23DFF659ULL, 
            0xC0606E0CDBBD8CEEULL, 0x3E9781BE32065167ULL, 0x43E3C74A26FB5754ULL, 0x027A8B96023879BEULL, 
            0xFE64A6DF69E7D6EDULL, 0x5FEDF4809EF4EDD3ULL, 0x8E18533B47EB3335ULL, 0x08E9999624CFA744ULL, 
            0x2C31822C7BA9D053ULL, 0x9A51A0DEC9D96ABCULL, 0x566128054C08C866ULL, 0xA4AA0BBA7232791FULL, 
            0xBE920431F706AADFULL, 0xFE5194899FC8F651ULL, 0xFDAED054FAE9B4D7ULL, 0xCDE72A87C70CB650ULL, 
            0xAB5881E3028ADEE1ULL, 0xA57C5AA9DF9C30FBULL, 0x7188ECAAAC49406DULL, 0x1FEEB497F4AD9E1DULL, 
            0xFF56FA0F56E92FBDULL, 0xAE059CED99B2DD99ULL, 0x8C91DC6C18059DFAULL, 0x126ABB2DDADED039ULL
        },
        {
            0x5EDA1F82620F1D51ULL, 0xAEC12657E5FEA1BAULL, 0x54B9BE267C7CC17BULL, 0xED9D2EE728AE3E05ULL, 
            0xA49922DD4CA2069AULL, 0x8EABADD2A957AA38ULL, 0x54F66EF718512C0FULL, 0x66B7125CF0897B2DULL, 
            0x3ECFDF7DD31DD543ULL, 0x2D26B9AD72FC4D03ULL, 0xF3660222CA1CD835ULL, 0xF6A200C4A1824917ULL, 
            0x77CBE884AFBA366EULL, 0x93DF113E63F2C96DULL, 0x304965C1A7CDFAC6ULL, 0x7DC8E9D419421FFAULL, 
            0x9260CB90B70CAE66ULL, 0x9416B3D980DEFF85ULL, 0xA56E89286BD7EB62ULL, 0x79028666D3F580ECULL, 
            0x375196E25FA46537ULL, 0x5327F50CA1AFB249ULL, 0x817315E55FB7F537ULL, 0x76C13FD62EF8D4DCULL, 
            0xA8AB802D6F9679ABULL, 0x651ADD5286641AC5ULL, 0x6771AE4F71D351ACULL, 0x0575EB7ED2DBF114ULL, 
            0xD14DE771C692F876ULL, 0xF62D87EFB23C0745ULL, 0xEC56D5D592DC9F89ULL, 0xD978455F992BB1D8ULL
        },
        {
            0x9E120A842B254565ULL, 0xFC657CF192CA2C13ULL, 0x629C9939D6A6793BULL, 0x380232D278054089ULL, 
            0x3AFD3F62E0EB9EAAULL, 0xF3B228589BEF986BULL, 0x9E1331FD351267AAULL, 0xB89E8D3FAD803074ULL, 
            0xD4EAF0555C7D39A5ULL, 0x6FA3108573C1CB17ULL, 0x5D71F492B0170E65ULL, 0x7245F316AD45BA99ULL, 
            0xBEED5FBC28368506ULL, 0x819CB876A3A80035ULL, 0x432689D9DFA45D3DULL, 0xA8343C3AF8AEBBDFULL, 
            0x3CFFAEC74D6ED742ULL, 0x410A6425576E1801ULL, 0x952C4F4B1E688499ULL, 0xC26E092C802F316BULL, 
            0x447F2ADC08FD5889ULL, 0x21A7B2A49F254976ULL, 0xD446C348DFF0EACCULL, 0xE48012582609FE92ULL, 
            0x7BC994598FEC2B00ULL, 0xE996BCD219EC21DDULL, 0x6EF717C585E0E78AULL, 0x7D1E8A7657BE8412ULL, 
            0x880551CC80988726ULL, 0x11FA1B591615CABBULL, 0x16E70187F6FD2EC5ULL, 0x2DBE1678A3247216ULL
        },
        {
            0xC9784B91AEB6330CULL, 0x21F8322ACBA9AA01ULL, 0x9A48205CAEB2F233ULL, 0x05DCB5D420FFA75DULL, 
            0xED86A9F3972B72EEULL, 0x9F3069B4C71241B7ULL, 0x8E41F66625B423CCULL, 0x918939C1C64E4C7EULL, 
            0x19D800F4326C5766ULL, 0x0F09172880337199ULL, 0xF8D3AD8D427A63C0ULL, 0x34DFA351855861CDULL, 
            0x364835E705D60AB4ULL, 0x8100D567BB0BB36BULL, 0x6EFE4B49BECEEB63ULL, 0x7391BE56613A7892ULL, 
            0x2C395AE04D6C81D0ULL, 0x452E266FD9B6F243ULL, 0x34E091B0FF6A59F7ULL, 0xF527C87171F01BAEULL, 
            0x1D1CE9AAA13E4871ULL, 0xE84DC2343C5C8852ULL, 0x3D2987155B323120ULL, 0x6476F2E863134ABFULL, 
            0x7A3CCEE2A1BCA357ULL, 0xAC13337C54D9DF0BULL, 0x50408CF2FFDA085DULL, 0x7B13D9019AEB0FB0ULL, 
            0x7AB81EA75B5EA2AAULL, 0x88736AEB7F535B63ULL, 0xE1B40A25925183AAULL, 0x667F67E3B4A575E2ULL
        }
    },
    {
        {
            0xF06AE2AAAC518683ULL, 0xE7F1E3CF3AEEB2BAULL, 0xC0BF7F56694D2003ULL, 0x44053A6B64D26AE7ULL, 
            0xC08DE13E2EF1D978ULL, 0xC7024184DD2E6A67ULL, 0xB4722D1B5E245F7FULL, 0x859456CD2BEA5D52ULL, 
            0x1AE97E1A532B5B9AULL, 0x3752D8BBDA5DFCBDULL, 0x75B78147DFC24FCFULL, 0x0BF6A42D93BFC5E8ULL, 
            0x08B74CA8190CD8FAULL, 0xCF1A9857744E3A25ULL, 0x147823812410BF50ULL, 0x45DEBFEE296F2E0EULL, 
            0x87349703FFB6E8EBULL, 0xEDAC9B70DC71EB2AULL, 0x489411AD3F90DD2BULL, 0xDA2D52EBF1C52621ULL, 
            0x12C32EB56EB0A31CULL, 0x205DF71C64F4D96DULL, 0x417509D6CF54B6EBULL, 0x7BD482ED08274AB0ULL, 
            0xB999586E38A1221FULL, 0xA016C7BD32DA9445ULL, 0xD81688F452109CC2ULL, 0x61F41EBA5CB65BAFULL, 
            0x61AE31412D00A45EULL, 0x3123F0597CA857EDULL, 0xD74D5A609EA2F6E0ULL, 0xC0AF1D5532E2DBFFULL
        },
        {
            0x1F14BBF153D77376ULL, 0x09E9A05384812A8CULL, 0xD59ACEE73EE5B0ECULL, 0xD1B6021BC600DDE1ULL, 
            0x976B0AD8BF172FDAULL, 0xE6CADB455AF42C7AULL, 0xF8CEF852EA61547BULL, 0x99BF879D529C5513ULL, 
            0x2A865E4D72792E9BULL, 0x53E447C7A7E77745ULL, 0x02A30959BF2C37F9ULL, 0xBD7BCCD84337931FULL, 
            0xBC0BAD4F4CD27E2BULL, 0xDBF1B32D51A3576DULL, 0x9AF94590AE8C3268ULL, 0x367D73AAE4DE78CCULL, 
            0xD92D2DFC25AFEDB8ULL, 0x722484C8C071DD86ULL, 0x50B19F1E9286FACAULL, 0xAB486A53D610465BULL, 
            0xD5811AB77D673789ULL, 0x5981C718DF75E844ULL, 0x9563F08935DA68FDULL, 0xBB07D628B960D70BULL, 
            0x93875FF28250F9DEULL, 0x3B6C53E1D2C65C5AULL, 0x4FA4273533081A50ULL, 0xB59A53A333D6F928ULL, 
            0x366EF6BC4CA385FCULL, 0xC176A55FF6A16323ULL, 0xF07F178C1A81F17CULL, 0xADABD037D2AFAF94ULL
        },
        {
            0xBF7D6AB81E7AE2A1ULL, 0x63B85114A8AE48D9ULL, 0xF0092E173DF6BD49ULL, 0x611B46AB8AEA087EULL, 
            0xF8096AB0C8410894ULL, 0xF81D3F3B2665B5D0ULL, 0x5579B8EA019E4E7EULL, 0x9B4D9DF71940352BULL, 
            0x403847CABF5A3FA0ULL, 0x40A574442A2B396AULL, 0xD437F2F347053CFFULL, 0xC6522B299BD095BEULL, 
            0xEBFD7C30AF0A5E19ULL, 0xF6E61A5B114056BBULL, 0x59CB57459B426782ULL, 0x7BA4237A0A72AC4BULL, 
            0x827E850C68339B9CULL, 0x8A1A047105FDB4FDULL, 0x9788EB03DE2A408CULL, 0x5E432EBEF15B45A3ULL, 
            0xDCB9F16412265C5BULL, 0xAB3D3BAAECEBE042ULL, 0x157FF02F7049649FULL, 0x3672E81EB16EDEB3ULL, 
            0x7D21F027A4F9AE21ULL, 0x71703FD03AC03A93ULL, 0x802585E6E9D41DFAULL, 0x1A7FCBF6582371A0ULL, 
            0x722A0A79726AC71DULL, 0x18B1F5691151F21CULL, 0x9163F76879C8D0B5ULL, 0xFB9E7E822026133CULL
        },
        {
            0xF0544DC56A8F034CULL, 0xB8BA81EA7826CBF7ULL, 0x76043513EEF8C945ULL, 0x3A61B1F4F312F3C3ULL, 
            0x22B645B4E7BBB5D0ULL, 0x1224F2EEF2BC05EBULL, 0xDB7C09D383A4623FULL, 0xA602302EB731A779ULL, 
            0x298EA605E9239A0EULL, 0xAB6A2BE8255F5CCAULL, 0x00D890A0900810FEULL, 0x5BCFD5D56D635FE7ULL, 
            0x6857369FC3338B8AULL, 0x3A1DD3309E4F4DFCULL, 0x0104144412BD83EDULL, 0xCF6B081DDABF9269ULL, 
            0xFE44AC6CB671B5D0ULL, 0xB32ADB352670E12DULL, 0x88EF210E0EA70B66ULL, 0xC51C619D431505D3ULL, 
            0x5E3C3AFA86778DECULL, 0x3D3B16A4981A42EEULL, 0x2B10AFDBF373B3FEULL, 0xB894E94B7FC7BF4CULL, 
            0x0E129046985B4B64ULL, 0xB196A2FB941A6290ULL, 0x8967D2E5F77F3A2AULL, 0xDA36F21F04F6D005ULL, 
            0xC1C49349304B8D1AULL, 0xD27505818C52ED28ULL, 0x119FC20C95B4DA45ULL, 0xEFAC428774D999B9ULL
        },
        {
            0x6D0B667854A35B2CULL, 0x5C4C4EADB3ACADE7ULL, 0xD1E68B283DBD8106ULL, 0xC636DCD328C55688ULL, 
            0xAFDCC7EC79AADA9DULL, 0xC74BF7C1F927BC17ULL, 0x4C536F4D04755ADFULL, 0xA6BC751EB48F95E2ULL, 
            0x8FFE765D37ADCEDFULL, 0xCE3D492560BF7127ULL, 0x88A96647FBF08315ULL, 0xFBEBE1B37E3FCBBCULL, 
            0x2A2964A8186A38B6ULL, 0x42FA858DF7A5CB18ULL, 0x50F5B65E89890085ULL, 0x2A0E4232E50A8FB8ULL, 
            0x299F597C831AA8F2ULL, 0x0953323D971F19E6ULL, 0x9CA224BD23DC6D6AULL, 0x276920162E4463D2ULL, 
            0x552EB21D36B7CA33ULL, 0x412BCA46689BE399ULL, 0x89ECA37AAF317AB4ULL, 0x4E43E940673E6475ULL, 
            0x875311D562404925ULL, 0x5DE4D0E6578C509DULL, 0x1A71038C30992A92ULL, 0xBA2039F3E42A90EEULL, 
            0x2ED8F1E91D8F6F3EULL, 0xAC05DBF7678E30C2ULL, 0xFCDE9C2FD14E700DULL, 0x9C7F4AC57EC2936CULL
        },
        {
            0x0B8CD5C07C8AA822ULL, 0xFEC18BFAE720D40AULL, 0x24EAF90D084E64F4ULL, 0xF91053321B0C9712ULL, 
            0x9A7F13D1559F41BBULL, 0xA53A0EEB76078106ULL, 0x25AD8ABC6BAB77FEULL, 0x67227D6FF9C8F9E0ULL, 
            0x88F692ECB2E34ED7ULL, 0xC94E0376D1A6FF2FULL, 0x65C2F45E09248BBEULL, 0x1E6A00D97BC09D4FULL, 
            0x16057D776D9FCDF8ULL, 0xFDC3FA8D21F37310ULL, 0x692D1684E352D7FBULL, 0x485E8F0863F650B7ULL, 
            0x8F52A3DD509DC086ULL, 0x0B34C1F9735956F1ULL, 0x617089D47BE4B504ULL, 0x4A4566945178266BULL, 
            0xCE0A738076F1631BULL, 0xA5654A9B9AE45966ULL, 0xFBCD32B985D91CE2ULL, 0x7F0C942B4AF6C0EAULL, 
            0xD41BB7475F253F6AULL, 0x1647EAE0173E5678ULL, 0xD22453AEC56451BCULL, 0x85C5373DEDE26282ULL, 
            0x5D1A79059D9DD639ULL, 0xC1796D38A00BC3C5ULL, 0x7750326BDE42EB25ULL, 0xEF4D168D22B100E3ULL
        }
    },
    {
        {
            0xD9E244F0C9E53DE4ULL, 0x46CFBD50E504ECBEULL, 0xF81A982561A48675ULL, 0xD8EF775ABBDFF380ULL, 
            0xBE5F99750AA10CB7ULL, 0xF064F50EA6ED216CULL, 0x2ADCB4EDB143A4F3ULL, 0x8952DB7B1DFFB89BULL, 
            0x3AA2E21DEE6C3766ULL, 0x79F2624AC5F4D498ULL, 0x6DFC69583A9C0468ULL, 0xDE4705B19C409336ULL, 
            0x7BC5C7FF9C896EB4ULL, 0x565589D594D24FAEULL, 0xB0110E8AD0C0D81BULL, 0x17D00623FA15EF1DULL, 
            0x6C7D9F077E485BF9ULL, 0x2B1AB4EA72DBBA1CULL, 0x007F19A3CC3A4E4DULL, 0x42E722A94C692E3DULL, 
            0x3537B425AC169243ULL, 0x3BC6079C92D78A99ULL, 0xD59B1FDAD85DF4F2ULL, 0xADC33085BA7244A5ULL, 
            0x46414D083ED0AF06ULL, 0xF30A9384BFE6F3E8ULL, 0x4FEE3A720A5FD306ULL, 0x760007D86CD99A11ULL, 
            0x26EAB619A3A65710ULL, 0x91E8F8FA48658E41ULL, 0x6DE0882450EB0255ULL, 0x907E113904C7875CULL
        },
        {
            0xF2BA7087C88B0445ULL, 0x0DE9DC8878C9D62AULL, 0x8EB723A66E232D21ULL, 0x78E53ED2109FCE80ULL, 
            0x15C7F9B67A2367D1ULL, 0x0B6B1C5AAE4050B6ULL, 0xC0AEBEFC98BF2154ULL, 0x5A23EB47E33E27DDULL, 
            0xD26924665C339323ULL, 0x8D4DA23AF1A99E35ULL, 0x77D34BD86AE7EE7EULL, 0x6D3FC98BE169E823ULL, 
            0xDDF79E277F35052DULL, 0xDCA1496EDFF92268ULL, 0xFE9D8CBE32ACF35EULL, 0x7AACE73E44AF098FULL, 
            0xAE7F77A14147D3F6ULL, 0x0064F32A6E2978D7ULL, 0x572BD77C65CDC79AULL, 0x137BD299AE0FFAA6ULL, 
            0x49A9729C85B66F80ULL, 0x17BF843DCA1C1604ULL, 0x9E72E43836908C6BULL, 0xF577BC3C505DF907ULL, 
            0x2A11A0E82D0ED233ULL, 0x3E34B5EB0771C992ULL, 0x6653F13367FE0DBEULL, 0xA94291426FC02FBFULL, 
            0xB3D9CA9C8EB0FAC3ULL, 0xD356977B00E75EBAULL, 0xEDA2D2926D81AC56ULL, 0x4F5BF617F8FDDF79ULL
        },
        {
            0x0D43B82BBBA5D649ULL, 0x0CC17AB76B99DD50ULL, 0x0409BDC3E5CEDCB6ULL, 0xA5431F4BCB81C0B7ULL, 
            0xCD6967AF78CCFE88ULL, 0x75B2240ED8D8A4F8ULL, 0x58897E4B6F0337E8ULL, 0xAA0F2104AE450FFAULL, 
            0xBDD4E1DB2B6350AEULL, 0x346A0BE9253F03C2ULL, 0x4AD83ED222F1DDEDULL, 0x83E3659F11B172C4ULL, 
            0x5AF1C29A272571CCULL, 0xA74EB81EAF2DE385ULL, 0x9FD3BE2D50CA5074ULL, 0x3883EC2919859418ULL, 
            0x4F45DDE7D038157EULL, 0xF54287A7F198C7EAULL, 0x8FF807A142687BE2ULL, 0x87E6EC3E2762BDA6ULL, 
            0x0FBC236A320CF672ULL, 0x20B36E10BF8B7164ULL, 0x677A70C0EEBE0F3FULL, 0xF5F198F0557D2A05ULL, 
            0xB3BCE2DA1601E769ULL, 0xF8421779EE6C0584ULL, 0xDD2112C2CD170953ULL, 0xB1B1C61AD8DB225AULL, 
            0x2BC96F319603100CULL, 0xF135DE47EE014885ULL, 0xDE089A15FC8EEF37ULL, 0xE0E4923CB733AB1DULL
        },
        {
            0xDB5A5F7ACAEC3A8EULL, 0x473C122724041BCDULL, 0xFD56B344AF9CA2B2ULL, 0xE3A727EB3733754DULL, 
            0x584381376B6552A3ULL, 0x2065F477A87353A3ULL, 0x8E618F12DECFF276ULL, 0xC05B730E9C0EF419ULL, 
            0x5A623789638C2CE3ULL, 0x1362E3C39D7BA9C5ULL, 0xB6A6C4D9BEB179BAULL, 0xBF09C12783B1DDF3ULL, 
            0xA3E494F9DE482473ULL, 0x7675CE4903611730ULL, 0x43235FC79B94DE3AULL, 0x0F0112FE1CE8C075ULL, 
            0xA1BE66BFBAD3E393ULL, 0xD85A08C22DC3959BULL, 0xA4D268D55E129C44ULL, 0x34C6B0E31E85B9CAULL, 
            0xB299C45978640333ULL, 0x0A9D7E7734947E8AULL, 0x6C83EE3889286451ULL, 0x5BE9B8608E5FE9C0ULL, 
            0xE212877C50A76028ULL, 0x77BA1FBFFC77FF42ULL, 0x3DF25ACB668B58CAULL, 0x8979691C284D879AULL, 
            0x9D5F7882A6B4A9C1ULL, 0x9E2B162F00CBACF2ULL, 0x6ECBDC184F207815ULL, 0xA7DC6D8B01C50D76ULL
        },
        {
            0x6EBDF9540DBB1BC0ULL, 0x8B91E90537DAC0BAULL, 0x97D054B2AD8AA045ULL, 0xCD3D306F45FC2D2AULL, 
            0xEA01317600530036ULL, 0xD2C1EB2FE13304B9ULL, 0x228604B33E15D1B0ULL, 0x6E076CC94CF23153ULL, 
            0xB7EEDB913D52655CULL, 0x8CC5E0319502DB0DULL, 0xD03142A08AD863D9ULL, 0x88B5E02FF388A902ULL, 
            0xAF30D1F063A48C2DULL, 0xABD311E69FEDB580ULL, 0xB2E312BEE34131F6ULL, 0x82CADFC13AC1CE86ULL, 
            0xF3CB621F1603A0FCULL, 0x627C7ABD85DFB0FDULL, 0x0045CCAA7C3FEEE3ULL, 0x7F3BB43FBBD8A05CULL, 
            0x2467B540FEC034EEULL, 0xBBB5FBE3102408DCULL, 0xC6922E2F710C7290ULL, 0xB03AB8C82C38473AULL, 
            0x39D5E66544C3CE39ULL, 0x17E8190726B9EC41ULL, 0x8BD173F340D946BEULL, 0x35D0E3937F95D4E9ULL, 
            0xC19721E9CD93331FULL, 0xDFB50033EEA73CBCULL, 0x956C13110EB344E6ULL, 0x567EAEB89C832A29ULL
        },
        {
            0x57EB0B1291D9AEC8ULL, 0x3FCCB18C86BB4BD1ULL, 0x36918A4E2DE56FCAULL, 0x870D779AF09D61DFULL, 
            0x68AA2763D7AF2A3AULL, 0x1A77623DD5FEA5D0ULL, 0x2E99740166899B43ULL, 0x3F09BFB0635D35D4ULL, 
            0x41EF1549512975CAULL, 0xA91DD0D522C1BEB8ULL, 0x1AB30720929F823BULL, 0x2B20D5CB17074891ULL, 
            0x14950F46457622FFULL, 0x5B7D4CB6CA224115ULL, 0x0973181663194CF0ULL, 0x5C47164BEC604C75ULL, 
            0x5F6838D301363DE0ULL, 0x16271863C6B10A23ULL, 0x7074FA33D3F6654FULL, 0xCB29C8468EBCF913ULL, 
            0x542AB142FEAEA675ULL, 0x32BB9FE31111D20CULL, 0xFE7663A3B08EC0A4ULL, 0x2132B42587063896ULL, 
            0x75E1158461C35DD5ULL, 0xC3A8FD85820CDFE5ULL, 0x2A4615111F784788ULL, 0xA7990A1D5DCDBD7BULL, 
            0x8BC095A83F6E99C8ULL, 0x6ED875C63C075259ULL, 0x3E178E26BCD81D5AULL, 0x5337829A858DC82EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseFConstants = {
    0x547BF45D0816CE57ULL,
    0x305EA881AE8AEF4CULL,
    0x49671249FFE4EF17ULL,
    0x547BF45D0816CE57ULL,
    0x305EA881AE8AEF4CULL,
    0x49671249FFE4EF17ULL,
    0x855CA8BAF915A187ULL,
    0xDD9092B6E7B8519DULL,
    0xB5,
    0x9D,
    0x2F,
    0xC3,
    0x77,
    0x30,
    0xD0,
    0x7A
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseGSalts = {
    {
        {
            0x5193DE4A27EAEF0FULL, 0xA4A83E57997E6C03ULL, 0x3B0283553DA78600ULL, 0x3A1AC1172E7E8BA0ULL, 
            0x5F28AF6A56E7FFBFULL, 0x9530CC924FB6C898ULL, 0xFFC7CCE2B9CAA2CDULL, 0x3BED9C3858755C3CULL, 
            0xD5180A4D4E8477CFULL, 0xB390F4458A0EA3FBULL, 0xDF5BCF73485C2B13ULL, 0x73B5FE01A2AEAD80ULL, 
            0x5A19B784767EFEA9ULL, 0x435725FE73CC4CF2ULL, 0x5FF1522E995290F7ULL, 0xD0C01690C172BC08ULL, 
            0xB7D23B0B2C08502EULL, 0x0F91BC0626D77381ULL, 0xF945FB21E4B21E7EULL, 0x0723680DF0772514ULL, 
            0xA8860C039747DD58ULL, 0x11FC8C2FC5C62525ULL, 0xA636F2329E6D2DD9ULL, 0x44BBEC18EFE4F54FULL, 
            0xCA5A8D07C1F22C7DULL, 0x7AAF5D1CA16D4AF5ULL, 0x3E9920D12098293CULL, 0x6895316C23BF5B74ULL, 
            0xFEAF199D0239C536ULL, 0x90B261E63158A46EULL, 0x7D0B241CB6161C34ULL, 0xFA69EE505E1F0271ULL
        },
        {
            0x4E4390C8B69A98F1ULL, 0x66988A1E1F2CF2B3ULL, 0x1E907BEE46BDEE6DULL, 0x0C9A4D06E7A503F7ULL, 
            0xBF486BA89C7E2B4BULL, 0x8C029BEE35361567ULL, 0x1F80C12403666641ULL, 0x5335F80C8A267679ULL, 
            0x700A8E10AF2990ABULL, 0x5D579B4A20D1872AULL, 0xE42359081B94CC21ULL, 0xFB5F77E5F4F0E5AFULL, 
            0x9A849D9C91FF50D0ULL, 0xA11DF595A808A139ULL, 0xFCA21AEA5A299106ULL, 0x509D0E31583467A4ULL, 
            0x159AD3F270BF1311ULL, 0xEEFA8F2337CDD811ULL, 0x89DE603DF3565C31ULL, 0x595BC0172FFCF651ULL, 
            0x5A96ADDB50B1B399ULL, 0xA80B2FA3A105877AULL, 0x70911B8768990CE3ULL, 0x105A5E4D912776BDULL, 
            0x7D1BFF3ED5CCED2BULL, 0x460E04FB8F1ED0D9ULL, 0x70C635F2F6FA2B9EULL, 0x4D084AF2C4EE3D47ULL, 
            0xF280FCEE9144BE74ULL, 0x9F7EBAC0177F4713ULL, 0x9930279C731F7CC4ULL, 0x06B8F2529BC121C9ULL
        },
        {
            0x537B24D9DD48788EULL, 0x64127CBC7D7DBA0BULL, 0x09D89C858D6EBA29ULL, 0x743E147010C4595DULL, 
            0xCD436965D066D802ULL, 0xDA68EC8701B73369ULL, 0x73F7BFF5A0D679A1ULL, 0xB9C7484CA273A5C3ULL, 
            0x514D659C10729AA1ULL, 0x2EAE2651715ADB67ULL, 0x010B25D6B9E60ECEULL, 0x72721A7DF7681B4BULL, 
            0x64F1C0C74BB927D3ULL, 0x86A48879ED4366F8ULL, 0x5C2CC3983259C433ULL, 0xF42C59BA19DCE26DULL, 
            0x82697AAEB87BD6AEULL, 0xB25F561528E31636ULL, 0xD270A7182927D8E4ULL, 0x4EE9EFCEF81E8E9FULL, 
            0x9A9B08C593EF3FF8ULL, 0x9859BFC8070A1CAAULL, 0x544574DB66215FD4ULL, 0x8B1F9325A15410DEULL, 
            0x8CCF67752B3F4B43ULL, 0xAEFC245C9ADF1D75ULL, 0x1AECE62882085009ULL, 0xD93CA5EEC541432EULL, 
            0xFCE88ADA70D01254ULL, 0xE8534D07FE2AE826ULL, 0x8BD65A4E04D3FD4AULL, 0xCD91B13AF4FF8137ULL
        },
        {
            0xA3A7141A1386B5A5ULL, 0x322119E7C07514D2ULL, 0xF921927DCA40260FULL, 0x23E731D55CF5DC7EULL, 
            0xBAEB19E95386272DULL, 0x24AB41E9CAFED4E7ULL, 0x8E00BB72FA79BC30ULL, 0x32C9B5AFCD33D59AULL, 
            0x7470C0E76211A32CULL, 0x940C7066A5D2DFAFULL, 0x88E40251F5736DEBULL, 0xEE92B32E93CCF171ULL, 
            0x93CCCBF85DD3566EULL, 0xA1AA3B7195665047ULL, 0xDFA7355BC19D89D2ULL, 0xAD91B8CE1C42AD7BULL, 
            0xD9094B3714EF4286ULL, 0xD1148F2AEBD6B93BULL, 0x81FFDEC9CF1188F7ULL, 0x6083CE4EB4601E13ULL, 
            0xA55A6F5E8E8FFD4FULL, 0xBC01E49F885BB089ULL, 0x7C89EA1E25245A44ULL, 0xBEB8F70350516B76ULL, 
            0x0DD68FC226670A73ULL, 0x62DB1A3BD0B95EFEULL, 0x72A52FAA61F022F6ULL, 0x02730A5EDDFDBDE5ULL, 
            0x24E556611BAC209BULL, 0xFE8E1D8E8250BE94ULL, 0xD1524A9E6959E5AAULL, 0xBA2EA83D3AD78F06ULL
        },
        {
            0xAABA5530B2FD6883ULL, 0x49042D4F9E810AFCULL, 0x72F8CDE0DB717E55ULL, 0x169868683F81722BULL, 
            0xB7B707FCDB6191A3ULL, 0x0DEC1A5044AB7DA1ULL, 0x2A315E1EE5C4D7F5ULL, 0xAC4464CBE8A17750ULL, 
            0x73128AF438CBC8DFULL, 0x6EE55117C79DC3F5ULL, 0x80391651CF9E8609ULL, 0xD77808613ACC65AAULL, 
            0x0593994C0268E24CULL, 0x414D2AE08AD332DCULL, 0xD465B19CE5AA0047ULL, 0xBAB85ED227BF069CULL, 
            0xD7B00E95AB6A478DULL, 0xC79C0A25B68F1518ULL, 0x0F4B8D78C1BAC560ULL, 0x313688C3FA37E722ULL, 
            0x80ED8BA8DCF6B2FEULL, 0xD2749ABFF4FA4CECULL, 0xEE5C1851A7A3EFDCULL, 0x70C8C7D5DFE50349ULL, 
            0xB4C9EFEADEBD9436ULL, 0x507BDEA62459E6BCULL, 0xFFAB15C82F63532FULL, 0x7CD6FD2632325A01ULL, 
            0xE2ED0107D495F270ULL, 0xE4571DE02EB09DA6ULL, 0xD100DF054A727F19ULL, 0xFC7810451068D3AFULL
        },
        {
            0xDAB6787494F42363ULL, 0xF55A5C45E2953186ULL, 0x073CB5186F3CE4E5ULL, 0x589CEBDA79D24905ULL, 
            0x167D225AF12C5BDCULL, 0x988A5C43526B0436ULL, 0x9CB8E8B0E961511BULL, 0x6A1DA492E38E830CULL, 
            0x67864128959C3BD4ULL, 0xCD9ABCB98C8D3D7DULL, 0x6FF7BB9A5446C772ULL, 0x2055B19140E640C9ULL, 
            0x560EA3723A19D9FEULL, 0xCA6E446C3D0B9A44ULL, 0x3D84E773B9ADD196ULL, 0x8AAE6D434AB5224AULL, 
            0x6C0A61B7B4D5B898ULL, 0xEC816AEFE54625CAULL, 0x14103C3C5524B77DULL, 0x4F8F4690E5504EB8ULL, 
            0x7CC23620207053A5ULL, 0x0FBCAEBDC86C8CF3ULL, 0x1C1A6265687AA10EULL, 0x96225181E06388D5ULL, 
            0xEF77A4349744559FULL, 0x5B7666EDCB0EC374ULL, 0x382888FD89942E89ULL, 0x7023E6C7FDCABF36ULL, 
            0x46138BEC902A76B6ULL, 0x0F9324D18C564460ULL, 0xE47BE24728D7D5E7ULL, 0xEE786E178D72A639ULL
        }
    },
    {
        {
            0x7EC379339A9684ADULL, 0x3FE6A654A1BA4A8BULL, 0x15321A65919FFB9AULL, 0x0B883D5842806575ULL, 
            0x9800394739C56433ULL, 0xAE7CED87AB9C1CB6ULL, 0xCC45BAF03580A90DULL, 0xA5281082D00EFB72ULL, 
            0x6167DBFDCB28C557ULL, 0x66617D85B7DB8740ULL, 0x7DF4CC6B451822BDULL, 0x6A51B843C27ADB92ULL, 
            0x45EE247F7F0C7E1FULL, 0xE006ED999B42AE2FULL, 0xBDF502956CC39E0DULL, 0xACF5FBC4884B9B53ULL, 
            0x75D0C0EC33FBB850ULL, 0x4077D29421ADD8CEULL, 0x650D0100EDC5E45BULL, 0xAF95C12E3F32AF75ULL, 
            0x806C5817E0FA9B93ULL, 0x0B19408C59960448ULL, 0x36A8EB9EB591A9DAULL, 0x7A10B59A1D7EFE59ULL, 
            0xED4DD9F8D2209140ULL, 0x890ED2C6E0B3F56AULL, 0x6B7E21A23966BF7FULL, 0xFE0B08E4C4F4BFC1ULL, 
            0xF33B800ADF137CFAULL, 0xE7AA4D45B9553AA6ULL, 0x80FBCD41538F5619ULL, 0x1C9AE445B07E6733ULL
        },
        {
            0x5DE910102B5E42E4ULL, 0xF4E715D11015A887ULL, 0xB29A5259A5086452ULL, 0x3E43DBF82A317BB6ULL, 
            0x816ECFCA7C8046F6ULL, 0xD5C53C833AE1A746ULL, 0x51E75956003A5E75ULL, 0x5BB5816648D709D5ULL, 
            0x94BF3AA76C78F4A8ULL, 0x55E84618B11509E5ULL, 0x2F6341916AAC84C0ULL, 0x2FBDDADDB0B67F93ULL, 
            0xD32B6883EA06C478ULL, 0x7D6593685F88FA70ULL, 0x56594000AC3D9554ULL, 0x009F07F04E3DC648ULL, 
            0x7F38F4067D4E636CULL, 0xA0D827D40FF671FEULL, 0xFF74B6F603A33D1CULL, 0xCD33A2C839DBCFFEULL, 
            0x619BB0EF3BBBC944ULL, 0xDBB756F604C5AC56ULL, 0xBF133E9BBD58DEA5ULL, 0xFBB24993D4EBF92DULL, 
            0x2777659119F61120ULL, 0xCB99E1EC4EEBED15ULL, 0xB0E5467D00B89AEDULL, 0x9E32040DAAC3087EULL, 
            0x655CE1626C4D4629ULL, 0xE426EA926FF1CBC4ULL, 0x5C79E4E97B991621ULL, 0xAE0CCA73C03B80D4ULL
        },
        {
            0x13078F40DE86ADE6ULL, 0x90B8EFFFC8CBE11BULL, 0xCC5AD0454E1A2DF6ULL, 0xB32E17501B4D279EULL, 
            0xEA27A3A01F04701DULL, 0xC4939964E4103BE7ULL, 0xE03B77C7091CA2FCULL, 0x61A1E076B8F203FFULL, 
            0x183F7B760CD6B70DULL, 0x9E0B24ABFA428928ULL, 0x60D1EB57471EC91CULL, 0x29F99C096CD94F73ULL, 
            0xE7E5F2FB86BC099DULL, 0xAD71A42875934260ULL, 0xFDE56B7A6725967FULL, 0xA6FA8A79D3AB0724ULL, 
            0x859D1312BBF4A220ULL, 0xDB752E14D9CB526EULL, 0x3A1550EBE0133819ULL, 0x9A419AED845E5044ULL, 
            0x94D089B29D993C4EULL, 0x7A927B2C48740B68ULL, 0xC7171973F2F6F9A9ULL, 0xA1314CC3C3E1F3E4ULL, 
            0xFE5FFA9DC0960460ULL, 0x6D6A266F1AFFBE47ULL, 0x8DD7DFA2311A64BBULL, 0x585F9BD816756CF3ULL, 
            0x82C4CE7E160D7182ULL, 0x525AAB649A91D81FULL, 0x02256EB1D5044D54ULL, 0x589E0237B76D2CBEULL
        },
        {
            0xCE1820D33351C60AULL, 0x393931B9930582B6ULL, 0x6A9A9147B91E6429ULL, 0xBA34D3AFA956A4C7ULL, 
            0x37E7DA3FB4E5191EULL, 0x29E1FC99AE76DFDCULL, 0xFE4FE860DBE2D29EULL, 0x07CC9AF7B2EB97AEULL, 
            0x58353ABF12C4211DULL, 0x2E1B4F4F861F9F7FULL, 0x1A2567A01DA86754ULL, 0x1F952FCDDAF10232ULL, 
            0x038EF6E619ECC94CULL, 0xA76A66DF074C1BBBULL, 0xCEBA4E28D45A3C88ULL, 0x458B5D6F1054AE39ULL, 
            0x8F90E7AA5618FAC5ULL, 0xD4C8C4930D09132EULL, 0xBF8702C116586C69ULL, 0x7D7992BA44FA61DFULL, 
            0xFFE58DB65BB86FD7ULL, 0x355801B09DB6D08EULL, 0x02626AA1817C06E0ULL, 0xCA96A5A894B92A56ULL, 
            0x149C1081656EC37DULL, 0xCA1A002BB5AFD295ULL, 0xC6B4C95CC01DB31DULL, 0x3431628D4EA64E80ULL, 
            0x703DC5680167BD0FULL, 0x97CE553F6FBA08EFULL, 0xACF4C046A8346B76ULL, 0xD756D6C9C24FC969ULL
        },
        {
            0x99451E618F8E2054ULL, 0x16D7B2F1DA260F09ULL, 0xD9C4CF4767E8DF89ULL, 0x54938DB45152492FULL, 
            0xDAFDC2BC63671B47ULL, 0x09874877A31B4616ULL, 0x1BBF95C45407ED15ULL, 0x5DB42E67920B9AF1ULL, 
            0xABD9B52344DAE875ULL, 0x45275708B887D339ULL, 0x18C9C60A5C3D4B44ULL, 0xFB1DDD11A61CD890ULL, 
            0xFF6B3FB3AFC080DCULL, 0x070A6A96576865B3ULL, 0xB2B38283E0766FACULL, 0x6D1531BA6F829DF6ULL, 
            0xCE36502AFDEF1126ULL, 0x0038F3EABD61F157ULL, 0xC612941C3C0421B0ULL, 0xD00C66B81491A0FDULL, 
            0x03280D17B7DE7BE2ULL, 0x0C35F2AD63F93E66ULL, 0xCD701F955C48E4B1ULL, 0x3B86FE8CBC155BB7ULL, 
            0x344DD15E47EE31A3ULL, 0x831F209BE0876AF8ULL, 0x84310D5483089989ULL, 0x7863D73EC1F8A851ULL, 
            0xD2D6FA2EE8AF226AULL, 0x0741FCE38E4BDB55ULL, 0x7AB2DA792A8DB564ULL, 0x19D66C31C8B80B26ULL
        },
        {
            0x6A3D037F9A8F193AULL, 0xC208D94B1A25C238ULL, 0xDDCB4C000D52D6E4ULL, 0xCBA374642CCF84DBULL, 
            0x58DBB9E9984B5DE8ULL, 0x657FE76D4576F699ULL, 0xB82F5B58E3507AECULL, 0x05868C1CDC5DD3D7ULL, 
            0xEE485358F71824C9ULL, 0xB0E9D8FBF21F9233ULL, 0x39583E2E04C2AA9FULL, 0x768ECF08FCB646CEULL, 
            0xC28660DB8B363F43ULL, 0xC8905A3205426CE0ULL, 0x5668FC970B0B695FULL, 0xF479F4FD114B6699ULL, 
            0x2DD01596BD7B0E0DULL, 0xDA27098864C7FBDDULL, 0xF155D6A16728CF87ULL, 0x1B0758295F1A3187ULL, 
            0x8610AACEF21E85F6ULL, 0x775A9EF94C791AD5ULL, 0x6BADD3B99414890AULL, 0x33C0550548296CD1ULL, 
            0x0CAA8F7EB945AB1AULL, 0xE18C726A1C0FF216ULL, 0x0354BE670C9A288EULL, 0x457788FD84F1F3F2ULL, 
            0x7D030EBBE14CE0FDULL, 0xC5654AC8FE22C336ULL, 0x672C63C016F44595ULL, 0x42E0C629015FC162ULL
        }
    },
    {
        {
            0xDB3936D698D5FA0CULL, 0x0401471CBC664336ULL, 0x250EBE785F529D9FULL, 0x0137417822A6676FULL, 
            0x29F0245E8FB81848ULL, 0x7571FD28368BEDE8ULL, 0xC7275CA80ADE789FULL, 0xE77FB1284644A0A2ULL, 
            0x302B9DDCDCD24C21ULL, 0x79095E1986C33E75ULL, 0xAFF54420C763EE4FULL, 0xB284EEA661168D02ULL, 
            0x78B1202583D69DD0ULL, 0xD55F85DD0C395806ULL, 0x52BFFCCFF807F4B1ULL, 0xA12DC8304F7EA4C0ULL, 
            0x5D4540A8CD58A9A6ULL, 0xDDCAC4133A02B3FCULL, 0x8E985F0CD9F9FD35ULL, 0x1CEF5F8392FF0B79ULL, 
            0x57FAF5882D3AD952ULL, 0xCECAD005A7C738CDULL, 0x14C3F3E3752AAFC2ULL, 0xCDD16976B32AF77DULL, 
            0xA320C33FC92A0AC6ULL, 0xF22DBBB4D5F1F233ULL, 0xD29BAC0D3A9BE8EBULL, 0xB8ECF478A6798BB3ULL, 
            0x3B4E9B40AB8FD686ULL, 0x4BAF0B6E324CE32BULL, 0x43803F81BBD00526ULL, 0xEDE33DCA0A8927F8ULL
        },
        {
            0x16883D53EF9FEEB3ULL, 0x2E5AC00EA05A3D64ULL, 0x509DE50D94817DC2ULL, 0x899F701EAB133502ULL, 
            0xDDAD71C97D9081BBULL, 0x2B0FFF2EC29A4CC5ULL, 0x29CB766D5D0E4CF1ULL, 0x77D46CAE81F02EECULL, 
            0x5B0840CF0A597F3CULL, 0x7F4349460124AC2DULL, 0x573E2B700BDEF792ULL, 0xB139123EE2D2F9A6ULL, 
            0xF1F57E85541B4745ULL, 0x4E837CB382715059ULL, 0xC3ED512D8755F062ULL, 0xE4863B1567B0CB84ULL, 
            0x84471593A2511B1FULL, 0x4E490DD72E38A9FAULL, 0x08000E8E4B4CBD42ULL, 0x6677CAC7BD20D6AAULL, 
            0xE8607E37D0397449ULL, 0x0595625C01FC95EAULL, 0x98550BBE4E22666FULL, 0xCB623C7E86B345B5ULL, 
            0x37A364F2E2B2C905ULL, 0x8342F894BEB8EE22ULL, 0xFB5C75BC109D9305ULL, 0xE9A15E9E78501195ULL, 
            0xC787E0F657E4138BULL, 0x13E60235B2A5C86BULL, 0xC6043FC140BF9BD8ULL, 0xC5B6F0099E9D0AD9ULL
        },
        {
            0xAEB95ABF023DC3A7ULL, 0x1B6262A44D0B5DB9ULL, 0x59EBEB1E64EC4B46ULL, 0xCB5597492E1DEC4DULL, 
            0x4AD727FC0D133ADDULL, 0x8A39123FB93DFD08ULL, 0x2A977CCC6AED8D8EULL, 0x417DB51364C01B45ULL, 
            0x38B3E55F0FD70C07ULL, 0x68CA1E3154199CFAULL, 0xF3631CF4DFDF5F44ULL, 0x59F0ED38DA6C99D0ULL, 
            0x5EABDB3754B68EABULL, 0x7348CD17C7ED5079ULL, 0x51C59EC881EAE0D1ULL, 0x78AD2393F15E12E3ULL, 
            0x69486B013FE400C4ULL, 0xD05DE56E04D6D717ULL, 0x0B90F4CF7DD7B7C0ULL, 0xCFF554BD101CC8C7ULL, 
            0x74DF17DA173BFF55ULL, 0x87FB4B2EE0D00262ULL, 0x5C4A58F988D89C5BULL, 0xD213CD4493C3495EULL, 
            0x89148C5884C1C182ULL, 0x494C9132E84085EBULL, 0x3F9E04307F33BC87ULL, 0x7B8A9F8834B67897ULL, 
            0xAD6874CCAEF04467ULL, 0xCB7267F84A59775DULL, 0x201CE5A1A9B72C9FULL, 0x67C603A6B9F12091ULL
        },
        {
            0x09385330148586ADULL, 0x61825D37D3E982B5ULL, 0xA22B9B78B2B74619ULL, 0x837996B637AD24CAULL, 
            0xC14F7248AFCD91D7ULL, 0x3E91E96D13AA7170ULL, 0xBEF91C5A0D24F14BULL, 0xB86666569579DD96ULL, 
            0x3F38ED1AE797ADBCULL, 0x93DCFDE0261B17E4ULL, 0xE1E7DEF9192964C6ULL, 0xBCB78FD3E06FDD29ULL, 
            0x2128BE48432D1263ULL, 0x3487E754129CB006ULL, 0x7B9FE572B08A30E1ULL, 0x0DCB90BC58400C05ULL, 
            0x74C324B04519143CULL, 0x4E889442A6CEA37AULL, 0xBDD36DAD4A885770ULL, 0x625A7A7C6FA79117ULL, 
            0xCE3EBD92FAE633BBULL, 0x470EC7FC012377EFULL, 0xBA27048124280512ULL, 0x4E7B504AF0E4D6BAULL, 
            0x078BC97D503EFC3DULL, 0xB485E4300B1CF639ULL, 0x224970AE3FBD49E0ULL, 0x727872FB9F2D73CDULL, 
            0x81E97479676E4AD4ULL, 0x0627146216662D4AULL, 0xF6C069ED101E0E9DULL, 0x6327ECD2851C7677ULL
        },
        {
            0x6CDB6A142AEEBD0FULL, 0xDCB25A962DD3C866ULL, 0x769BD4AF46E8A645ULL, 0x3DA2519EE4D22DACULL, 
            0xDAA02BEB5E5C3895ULL, 0xDFA769051055ECAFULL, 0xE880CDF1F391D9B2ULL, 0x7B82D31D032B44C3ULL, 
            0x4AE5434D401ACC42ULL, 0xF1ECADCDBB83F0EFULL, 0x2C8016CEA5C11105ULL, 0x3086FE54A85C07A2ULL, 
            0x6B69A86BB59B199DULL, 0x72A3337F8206CF78ULL, 0x55F97ABD4C69E64AULL, 0x048D7A300FA8E0CBULL, 
            0x54E29D6415AA9C8EULL, 0x3E5F3B6B6AD81E85ULL, 0x1A84A84E0652F665ULL, 0x07BBA12C2FE27C9CULL, 
            0x6DA31FFA4884F19AULL, 0x2EB428A324E4990CULL, 0xE0D378CF6DA75E76ULL, 0xBDA55D3FA14C20C5ULL, 
            0x3E34A7DE62ABD8B3ULL, 0x291BD8AFFD1BACEBULL, 0xE7F47FE83440ECE1ULL, 0x3A39AE3972AF452BULL, 
            0xAACD0F69A26D0E42ULL, 0xEE8100BF28F967E5ULL, 0x05D018A19AA2A4CAULL, 0x47F8B58D82BB5C85ULL
        },
        {
            0x5E52DB40268D8179ULL, 0x485ABCC9FD5DCDB1ULL, 0x8610D6C38CD96370ULL, 0x67940A044F8C1422ULL, 
            0xE159C369DFF9EE01ULL, 0x3C26FE78CB67F52CULL, 0xB0268A78AEF5FD48ULL, 0x46D9720894DE642AULL, 
            0xA1435B66DFED9995ULL, 0x1ED7278BFB4F26C5ULL, 0xDB3F5C98C3971F89ULL, 0x55A13A678FF7FCA9ULL, 
            0x44BB260B171E9E28ULL, 0xC26654D80C7DB20AULL, 0x69DC308FF22FAC22ULL, 0x213520208CB7E655ULL, 
            0x90BD2F1AC5C85DDCULL, 0xA2FA380EC0833F89ULL, 0xAA242FF7D85C96BAULL, 0xE03392A32E70E255ULL, 
            0x380664CBDD17C0FEULL, 0xCD403D44788CD630ULL, 0xA7D009BC9ED48559ULL, 0xE5D7ACAC4B735428ULL, 
            0xA9CFD35610CFE8F1ULL, 0x70DE89F6C806BD74ULL, 0x1E5DAC99D32464CCULL, 0xC7DEAD35DED08913ULL, 
            0xF910A5226EACA4B7ULL, 0xE424B21223EEE544ULL, 0x21282283C7B232BDULL, 0x52EFB49F6F8B17EBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseGConstants = {
    0x4E542E4D4A54D40CULL,
    0x60F45BC2136C0D68ULL,
    0x6A7870D786777280ULL,
    0x4E542E4D4A54D40CULL,
    0x60F45BC2136C0D68ULL,
    0x6A7870D786777280ULL,
    0x883FEF1AFF4394EBULL,
    0xC3CCC2134B143B19ULL,
    0x92,
    0x78,
    0x93,
    0xD1,
    0x79,
    0x96,
    0x8B,
    0xB3
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseHSalts = {
    {
        {
            0x54FAD7D56D7BD46BULL, 0x7D2C489135961F84ULL, 0x269A10D698F92AFBULL, 0xB9EAD286DEA43509ULL, 
            0xE46248D6F6FBC951ULL, 0xE3707C5FF31FDC82ULL, 0x313319BF16E2CDBFULL, 0xB2A6448AA375B22AULL, 
            0x69298788377F9AE9ULL, 0x5D82EC4AF4EB9B55ULL, 0x85CA6F99C178AAF4ULL, 0x343C8BE7A6879621ULL, 
            0x50686889026BBA4EULL, 0xB7C7BCABCBE9E944ULL, 0x67E7762D780758ABULL, 0x9F1CB359162EDAC3ULL, 
            0x254D2157E9D92D77ULL, 0x520D7276A644545EULL, 0x84DBE5D6AF185199ULL, 0x7FB02CFD7C64C88EULL, 
            0x2703DA8573866F23ULL, 0x9AA073E490156C90ULL, 0x1F1A92B8B0FD14F6ULL, 0x58DF6AE0C2D44E67ULL, 
            0xC6ADB14ACA601C2EULL, 0x8AB2F5AEE7F11130ULL, 0x6B73B0DA24BCABC7ULL, 0x79F00BCB18188771ULL, 
            0x08DC5587017E90D3ULL, 0xB2FF24E804B008E1ULL, 0xF570CA8466A46D76ULL, 0x1A4C37878BD09492ULL
        },
        {
            0x801A5912A3959178ULL, 0x85E441478539F9C2ULL, 0x5295A43AF4F97F8DULL, 0x415756D8E5BB5278ULL, 
            0xE247C7A2D59437E6ULL, 0x0CF43EB22B13CF85ULL, 0x7FE8D43D3CCBD47DULL, 0xDA2AFB3FC136F5ABULL, 
            0xF7CC0C93D7B8D857ULL, 0x3DDFEF7F8EFCDCF3ULL, 0xA2B5F076FAAC1311ULL, 0x7CDC2E06BAB3F2CEULL, 
            0x31E97AC127026ED5ULL, 0xD058E1756B5DD920ULL, 0x903BFCB51CC3B225ULL, 0xD3D73CE9BF275536ULL, 
            0x044E4F51E9F0EACEULL, 0x89F97C81DFDF7243ULL, 0x2B8B47E925495F38ULL, 0xDC8BE38719DE68B7ULL, 
            0x2FDB805B02747C16ULL, 0x7BE4D6CADF27FD5FULL, 0xAFA573ACE695540EULL, 0xE0B4FC88A180AA46ULL, 
            0xEB3F011AB7409D04ULL, 0xE21B8D59D6CD27D9ULL, 0x0F254782E639B3ACULL, 0x349C98D7088690FEULL, 
            0x6F137E559F549FA5ULL, 0x4F3DA1A8C73C4020ULL, 0x761634A151AA9575ULL, 0x1D84E442DF034516ULL
        },
        {
            0x17195D3639762029ULL, 0x9D5DC53B76135FF7ULL, 0x3FD8AFC460AEE913ULL, 0xDF6184D2BB823034ULL, 
            0x52F662FA8E55736BULL, 0x6DCE49B9FCF0C027ULL, 0xA9A7D7E90437E0E3ULL, 0x261687530A853778ULL, 
            0x63E77894F41DF51DULL, 0x9A4BA2236CA63000ULL, 0x0E457F82A4B54641ULL, 0x00332418A4922244ULL, 
            0xC52148713E2EF87DULL, 0xBBC5EEAE01B1E243ULL, 0x31066330E29678E6ULL, 0xB1E06C2ADBA88148ULL, 
            0x9944D1029C162697ULL, 0xBF1E831DB31D8EC5ULL, 0x5431BA67EFA3A7B1ULL, 0xB251DC724B1BCAA6ULL, 
            0x8B2D2579F9170557ULL, 0x957189625782EE95ULL, 0x8FD0966E6C76FF06ULL, 0x96EABB8CAEEB901EULL, 
            0xE9FF5E22762583BAULL, 0xCFCC1D99BE132EA7ULL, 0xF61F9B6C22BFD4DBULL, 0x64E089610A840203ULL, 
            0x421F0807945702D0ULL, 0xC5A3F0D87B6DBF32ULL, 0xFA65C8B9A8DECE26ULL, 0x8A896303CB868505ULL
        },
        {
            0xBB9087ED87B82698ULL, 0x62B88FAF444C1B43ULL, 0x00D0020CDC31FEB6ULL, 0x706C253D3585CAE9ULL, 
            0xF52E6B1DC1C55C29ULL, 0xAB699047F5CED4EFULL, 0x01D631000BC4CA97ULL, 0x38F24EE03FE069B9ULL, 
            0x3B39AA02D9AF8430ULL, 0xF71629FDCC3DF862ULL, 0x13722399BF16E11CULL, 0x65BA39BEA34084A6ULL, 
            0xFF2E7D758C4F1DECULL, 0xCFA42BD4512DC41AULL, 0xF06EE4E9C2EE50E7ULL, 0x5D7D89F59412F007ULL, 
            0x61BB2DC9157C15DAULL, 0x855272A2B1845C61ULL, 0x4A9ABBC798DE7579ULL, 0x1933AF89C79E58E1ULL, 
            0x23DE24F20EF69A1DULL, 0xE863678536A0B1EFULL, 0xB358A5A08B46C899ULL, 0xDC70720B6A4415FBULL, 
            0x5B15F617C4D0519AULL, 0x356D772AFEB21A01ULL, 0x9A304BE6A7E45FF1ULL, 0x25FAA9BCFDF69663ULL, 
            0x7020D4B3FA42DB4CULL, 0x8CCC054E413EC6F9ULL, 0x0C2690568805DB03ULL, 0xD1EDE575F494BBB2ULL
        },
        {
            0x41B5EA956C84585EULL, 0xB5C6A6248F3F41BAULL, 0xC3E14A2C8792462BULL, 0x60551A13AFF0974DULL, 
            0x6CB049F75E4427F3ULL, 0xF2028A23A3F9EC8CULL, 0x1B08BD1BD8BF9471ULL, 0x8E699E9546202A39ULL, 
            0x08C7E591A8D33054ULL, 0x9DCC57B2077446C5ULL, 0xDF53ADCDB39C4FDEULL, 0x20DBCCB13449EB35ULL, 
            0x90DD17F11BE17978ULL, 0x5DED38A2EA39384BULL, 0xE02CA5CB31EBDBC5ULL, 0x91CC80F72590EFB0ULL, 
            0x594BF544FCCBB43FULL, 0x527D8357698216EAULL, 0x39EC93C98BA5F570ULL, 0x39650EAC53060E6BULL, 
            0x58DB28A042277288ULL, 0x394CB4C8823A2F6EULL, 0x46EF7394B2F302C3ULL, 0x4DF13AD950894229ULL, 
            0xA5C7B8FA5DFBEB14ULL, 0xC04EA211287B0F4AULL, 0xC9505B84CBFC58CDULL, 0xCF1AC966E20FEA08ULL, 
            0x9B974B18A15956C4ULL, 0x3BB67118058A1879ULL, 0xB7F72BE37E6207FAULL, 0x0C0B600D4CBE07F3ULL
        },
        {
            0xD6A34B1B09728DF5ULL, 0x30445CC743E15BE6ULL, 0xBD268ACE0F8EC269ULL, 0xECCE4EBA265E2A58ULL, 
            0x399620A55DF39E5FULL, 0x6136FB4E3B41087EULL, 0x6DBDE917060BC848ULL, 0xBE389A167A6EEC08ULL, 
            0xE398C9FB0AD64719ULL, 0x138D146F768CBCA9ULL, 0xE4EECAD72FC84160ULL, 0xACA0C6C801AF2459ULL, 
            0x59063B602BF4779DULL, 0xBB107C1FF8FACD90ULL, 0x4F46023D24CF29E0ULL, 0x102BAC889B155DBBULL, 
            0x88B4F7ADE868C8E3ULL, 0x3FB1203DEA7D5E64ULL, 0x59DFB8F068D20CA7ULL, 0xE09B26B025350122ULL, 
            0xEC1924A40748D643ULL, 0x3F9EED565027A220ULL, 0xDDC39611DB88DBDCULL, 0x945EE5958E98E2A8ULL, 
            0x5889564E4D8E154DULL, 0xE0709A2AD441CA20ULL, 0x9623AFD718321157ULL, 0x9C8FEAA96C1BB8EFULL, 
            0x24D7109146BD44CAULL, 0xC15F400E1A9C041FULL, 0xEB95A329D8052459ULL, 0x85505E681709D1E0ULL
        }
    },
    {
        {
            0xF96D57D6B924F2C9ULL, 0x320E04F5ADCF1B64ULL, 0x45D0221E0F4A5858ULL, 0xCB0D5D9AE91A571AULL, 
            0xD42082EEC3EDB44FULL, 0x8B35B164E059DD90ULL, 0xD76010310E84CE5EULL, 0xFF944C121E8BDC2DULL, 
            0x78A87AEBD36E7A6DULL, 0xF5C7ADA5D5C05887ULL, 0xD488ED993D51C579ULL, 0x0961904DF99AB15BULL, 
            0xC2893C387A9623BEULL, 0xE86FE603914B79F3ULL, 0xC176B674C8E29C25ULL, 0x3C6287A81D4350CBULL, 
            0x7D2F00296CB7BD79ULL, 0x516E656DA95C180AULL, 0x5CBD3240B2E3807AULL, 0xB2DDA78E2BB493E6ULL, 
            0xF80908E2A619EFF2ULL, 0x67A1DA3228FAF78EULL, 0x11C5702D3F163312ULL, 0xD8C2C93B2CD2F108ULL, 
            0xC3DF6F94DA77F316ULL, 0xDA1F67E4FDCF8BB3ULL, 0x2267D602F292A623ULL, 0xC0F712785B2117CCULL, 
            0xF314308A8295E9C8ULL, 0xAD96D2499611328CULL, 0x7D563DFEF591AEE2ULL, 0xC6A21827C227D81CULL
        },
        {
            0x482E6FE917B3BA20ULL, 0xC8AEB45E78DC044EULL, 0x27C25E87983F3DC4ULL, 0x5D56840E6C773035ULL, 
            0x0E6FBF62B09D3B57ULL, 0x84DA767503BAFAF0ULL, 0x11B87246461D30EBULL, 0x08D282EF4B44EC13ULL, 
            0xCDFD3FAA2558A066ULL, 0x938A29834D7C4DE7ULL, 0xDE74A6EA73A07341ULL, 0xED4FA0F0CCBC359EULL, 
            0xCF460D15DE1878D7ULL, 0xB64BB7DCDFE2FC4DULL, 0x9E278938D3348533ULL, 0xD5852E7503900F5AULL, 
            0xD02B2E45F96A5832ULL, 0x4BAFE43BF69674F1ULL, 0x64656EC53362E1E4ULL, 0xE00104B087C4AD99ULL, 
            0x92C5DF35ED9EF771ULL, 0x8158CD39FC8E84BAULL, 0x37F510B5995CB5C5ULL, 0x1B41594F25D50BDDULL, 
            0xF1D7E1D00F93B516ULL, 0x6C9E73188B5A9ACAULL, 0x9C8F07EA89770F22ULL, 0xF838026242CAC345ULL, 
            0xBE625D8679F896D0ULL, 0x5685F816D41C638EULL, 0xA7313F686FF38471ULL, 0xACEF9A83658D4662ULL
        },
        {
            0x013EE958013B85A8ULL, 0x9F1B6F6D60B6D4D9ULL, 0x54E51891A2DF3EABULL, 0x852093549E71F4F0ULL, 
            0xEC77B0D87F2EDF00ULL, 0xFD82BFC5B9246A4EULL, 0xE7D11EE9BD601A7FULL, 0x23DFED1F03476FF1ULL, 
            0x409BEC62F0E96F9DULL, 0x631F32D41C35FEE3ULL, 0x6F128FF3ED7DB2D1ULL, 0xB5680371920B1D8EULL, 
            0xED878BFE23DDE07CULL, 0xFB45897F4C8443EAULL, 0x65CD5B0FE3E1221DULL, 0xA63B2B77D178F52EULL, 
            0xE522E1E58BA4668FULL, 0x591358341C6E5A54ULL, 0xCAC1DA48027041F5ULL, 0xA9A91A6FF1AF5C28ULL, 
            0x638595F64C15CC41ULL, 0x2AEFAD3779D8ACE4ULL, 0x759DECFC201F9A40ULL, 0xF3953C74B6E12679ULL, 
            0x7FF69DB4A12DA1E1ULL, 0x5365AB2019F59B14ULL, 0xF50489511D37E23CULL, 0xEAEF5ED48A40FBB2ULL, 
            0x5BFEB7589D8EA68AULL, 0x98176AB35FE73488ULL, 0x3D3EDAE03B354A78ULL, 0x8F2E8EA0E31750B6ULL
        },
        {
            0x7FF4685DD043B4C4ULL, 0xE4248F932E624423ULL, 0xCCD0D6CAAB0C7D84ULL, 0x85E4B938E93BE468ULL, 
            0xE8DFD166494EC3DCULL, 0xD54A69EABD16EB15ULL, 0xBB8F42F873C89E72ULL, 0x8FFEBCE8324E89E7ULL, 
            0xE711FF72788C7C66ULL, 0x1F0F5C21825BB2D8ULL, 0xD21BF0C6EC50227DULL, 0x12AFD724B4CF7C2BULL, 
            0xF559CD466956ACA9ULL, 0xF06C1A0FEB305865ULL, 0x3CE5EE67362A70F5ULL, 0x46B52CD1C2EF80DEULL, 
            0xC1090878D555DBBDULL, 0x87E260DE038D00EBULL, 0x61FA04A706C0EE82ULL, 0x84865C908E3AB847ULL, 
            0x594F57FC7503FD18ULL, 0x2B51FC0BC6CFE5A5ULL, 0x61F6E5D3DCC55A4AULL, 0xF39D9C59A4FB9DEAULL, 
            0x65271D7A028FDBE3ULL, 0x16FBF4CC9AF62323ULL, 0xC1E5602D51F9CB34ULL, 0x3495EC8423C3CFDEULL, 
            0x1152664E5C399CA9ULL, 0xA25F69B0EF09E2FCULL, 0x3497F75E6463BC0EULL, 0x7A8CB01C2FFE778BULL
        },
        {
            0x7DBD175AE2CC0F4CULL, 0x8BF8BBCB8181160CULL, 0xC8340B12C10208E2ULL, 0x07FBF6F265BCF3BFULL, 
            0xC3FB93FA2BBA9471ULL, 0xC70E0A8B59112E41ULL, 0x570371DF537CF122ULL, 0x7616F22D6479D9A3ULL, 
            0x78F2B5270C974B9EULL, 0x0C211DDC1EB2EAF5ULL, 0x3C9F60D4D5C64088ULL, 0x4D0EDC8E8C893FDEULL, 
            0x4E53F0A5F78525E0ULL, 0xF75DB868057087ECULL, 0x466AEF5790B40038ULL, 0xE9167FCEE25DF1A5ULL, 
            0x7C1160507FE6ABC4ULL, 0x782999E4644691E1ULL, 0xF303C0CD00A48F0FULL, 0xDF14F6EAEA0ED65BULL, 
            0xB6E53713C09C1F7BULL, 0x51BCD8EE2C8F7D31ULL, 0x29CB63AE292F2A3EULL, 0x844C606A6D31EEBEULL, 
            0x13674EFDEA3B4B1BULL, 0x472F156DE0E79C3EULL, 0x9F7CE1025A370DB9ULL, 0xE1991A6209A8160CULL, 
            0x91DC98B6A843308AULL, 0xC4EDF9EE6BF8E3A0ULL, 0x967F869E1E3865A9ULL, 0x8230E4A05D40EDCEULL
        },
        {
            0x00E33FC11D8DAE6CULL, 0xDF841DED3E3BEDA6ULL, 0x215DE96D35F14CB7ULL, 0x9ABEE447DF5164C7ULL, 
            0x05B7647779A0C6D3ULL, 0x820058720BF6D879ULL, 0xF7DD6D59870BC496ULL, 0x81E0414068910086ULL, 
            0xB595AC8E4B208DCFULL, 0x3E45D39425BF0A6FULL, 0x0ADE62CA6BC752BAULL, 0xEAA897ADB7BD9D5CULL, 
            0x8FC7DDC139C99FACULL, 0x08704C9AC1580439ULL, 0x75CC245D37338DBAULL, 0xC93666DA82E52787ULL, 
            0xF55EB7F5F16CD0BFULL, 0xE518978F0B317DECULL, 0x7474F5C84BAAAE6CULL, 0x1911907D223B8396ULL, 
            0x0E9947B904592B4BULL, 0xF852D4CE9E26309EULL, 0x2E4FFD9EFA99294EULL, 0xFA8B11631B643B6AULL, 
            0x6D4A985C1D65663CULL, 0x83CF9AD7CF69B95AULL, 0xA1BAA71B65516AC3ULL, 0x8C07A7C11F45822DULL, 
            0x3B95B1D2F0F989E9ULL, 0xB5BB20E87BF7E319ULL, 0xE339E7679255B4A3ULL, 0x5596D54804A7B58BULL
        }
    },
    {
        {
            0xA807EB95BD646C5BULL, 0xF0065825CB3D4A92ULL, 0x3E06089C5C617B0BULL, 0x67E30194121E79E2ULL, 
            0x523C5068E28A339DULL, 0x24EFC725384B9C92ULL, 0x70EBC138FD63984DULL, 0xEBDEDB5ACB4D2E64ULL, 
            0x43C8CBD8BDE8D6C0ULL, 0x8F15B1F228606B14ULL, 0x1C9C1DEA05D59505ULL, 0xD4A0DB95AAFD0D67ULL, 
            0x5511B270355CB00FULL, 0x9F04A84ADCB58606ULL, 0x8798C510071EEA27ULL, 0xBE1B58F1D0762C47ULL, 
            0xB124F6961B86DD4EULL, 0x6CE4E4B39F3ED2EDULL, 0xC482DEAC1BF89AD4ULL, 0x0A66B0D4F98CBFF8ULL, 
            0x5A2E5EE7491D935CULL, 0x75385F7B50202B26ULL, 0xD4D3505D436FC6FBULL, 0xE47A8DDAC2D5CD4BULL, 
            0xFD7EB1C3661F305EULL, 0xBE12770939A718FBULL, 0x0F9A011F65D0382CULL, 0xCFEAD66900322E0AULL, 
            0x5E0E649483A4D0CCULL, 0xD2379A56815B2681ULL, 0x62580C1DBA582E02ULL, 0x9B89AB50BF74238CULL
        },
        {
            0xBF1CC234AE59C8B3ULL, 0x45BB0D225E61B33DULL, 0xFB4069B5C1A81AAFULL, 0x9E70A36AE30D6B60ULL, 
            0x5CD083C167A56CBEULL, 0xE420AF91C39D3412ULL, 0x8908E4FF4982C559ULL, 0x2E77D7FCEF4CEF0BULL, 
            0x15DD2D7E6247D628ULL, 0x639D80D86E09EA99ULL, 0xFCD292E4CEB08826ULL, 0x84703279065E2B07ULL, 
            0x3D93D7C81EC9BA7BULL, 0x802E2F124EB7D289ULL, 0x1C528ECB3ACD0511ULL, 0xF1A87EA924DAAF09ULL, 
            0x36C26DA11606C2B6ULL, 0x0698EE4F485F0296ULL, 0x0660BC5A9BE9EF93ULL, 0x8D1A96633CB04FF3ULL, 
            0x0A06FC78EC9FA148ULL, 0xF5E8BB9EB8D343D1ULL, 0x610B99A91B641835ULL, 0x645013133C1BC7F3ULL, 
            0xE9D5A14E8FE5EFB6ULL, 0x19F1275A076996A1ULL, 0xAE50A8A5EB2DD617ULL, 0x52CB528600CB7D85ULL, 
            0x57B6D65B98A7FFDAULL, 0x4F281426E5588663ULL, 0xCCB8F394EEB21FBFULL, 0x03DA5C346E22FE01ULL
        },
        {
            0x0965420A413DA700ULL, 0xDC17DC5983175A24ULL, 0x89ACEBFC82E6DBA9ULL, 0xDBDA288D90401B30ULL, 
            0xCC9CB33028ADD292ULL, 0x663D5A56BE410F60ULL, 0xC985FD939851FFA5ULL, 0x63E187011C176590ULL, 
            0xDDCEE00022F2C1EBULL, 0x4ED3EC7DAA1376D0ULL, 0x4211D64CB3F5F09BULL, 0x99FB06A141897350ULL, 
            0x0D080641C684395DULL, 0x18257FE43F46CE20ULL, 0x5CF88DAC906FB158ULL, 0xCD7B4A49BB7F5EFFULL, 
            0xA97934B2DF96FCC9ULL, 0x4D818F2D3223F90BULL, 0x75BEACF6C53F5A6CULL, 0x12C9E2D36CB9D979ULL, 
            0x9BE9BE94E086FC56ULL, 0x093835A1999E0274ULL, 0x71EB99882F5C4D8CULL, 0x7BFCCB83F04F23DBULL, 
            0xAC21D0A94CDB7473ULL, 0x61170C31BFCA8247ULL, 0xAF6C687E6784D763ULL, 0xAF69D344A4FF0AF2ULL, 
            0xE3D4CD82EDE684D3ULL, 0x510677AE821C36D6ULL, 0x3E7BF325F6001A28ULL, 0xB07D5E484B6E0B78ULL
        },
        {
            0x13D620F4106612F8ULL, 0x766F4C641B27F7BCULL, 0x04F8D252DD29B69CULL, 0x483B103D9D08E77EULL, 
            0x30861B8FFA459BB4ULL, 0x5E148003114C99D6ULL, 0xC11D7BB73F6EA903ULL, 0x51060CCCFF04E816ULL, 
            0x3FB87C60E6BDF9C5ULL, 0xD1F7E068D5391FD9ULL, 0xD28227B2C901AF23ULL, 0x872293DCFCB8014DULL, 
            0x79D4A27F703A6263ULL, 0xAE24ACCDBAF408B5ULL, 0x2E5F821D7596A0EDULL, 0x1A9645185DD312CBULL, 
            0x1C5F16A5B9E18EB5ULL, 0x12F4628D48F02AFCULL, 0x33AEB6BB83574B85ULL, 0xF6C4D8FFBD9071DFULL, 
            0xBE2AA2F7B63B64BAULL, 0xD8D480E050BC93EFULL, 0x2DF2CA81082982A2ULL, 0x7512223F8D6F2B5DULL, 
            0xB1ACD52C36EE083FULL, 0x09AF115A44B8EBA3ULL, 0x1C45E665FCB57E11ULL, 0x4ABCE2DA7DB35F7CULL, 
            0x2E0E0417182F8D53ULL, 0x026C666E84DCE489ULL, 0x2D345CD53AD64E32ULL, 0xB5AF6FF8C04E1F7CULL
        },
        {
            0x954DAF51E795AECBULL, 0xE5B01A4D528587D0ULL, 0xC7B0E43E45AF6FD5ULL, 0x8E21FF12DA3E4489ULL, 
            0xA06958FF1870D11CULL, 0x409E5AC93AA526CBULL, 0x85AF62B2C8ED4B50ULL, 0xC03B022A6C45172EULL, 
            0xB22C2F1AD7BD0B12ULL, 0x606FCECA12F4A6F6ULL, 0xAA45D6362CC8F7C3ULL, 0xC2321D716EAEDAA9ULL, 
            0x1D181655D84A58F0ULL, 0x35030D887717FFAAULL, 0x3FA5E608A41432ADULL, 0x39DD7217769EFCF0ULL, 
            0x7DB977797282EE4CULL, 0x352A9A88B98702C2ULL, 0xE34459C89B137E3DULL, 0x5F1F201EE0B130C0ULL, 
            0x77C0039DFD594892ULL, 0x3A3B599373FA834AULL, 0x48DC60AB3BC21637ULL, 0x521C5E0E3831A13FULL, 
            0x5821CE0D813E3C05ULL, 0x674A56664DA160C8ULL, 0x8D61B7B4A1D7B16EULL, 0xA63E6C6B5977D259ULL, 
            0x724ED0BAB0B0DD40ULL, 0x6DA25C4E7FA72BF7ULL, 0xB33911CF547C5E49ULL, 0x9A5FA2957F0C1212ULL
        },
        {
            0xF00D995B04B07514ULL, 0x4649EE72558CF5FBULL, 0x9D20D67B5351A174ULL, 0x4E846F6429502FCEULL, 
            0xDBD8B624C0B88BEAULL, 0x37C0FBA6C7439838ULL, 0x93DDE0EBF4EC634EULL, 0x82781204352123EBULL, 
            0x00DB771B2D7F9D87ULL, 0x0F3DC3B56AC4757BULL, 0x52D6BFEEA173B475ULL, 0x54AC0A5D1DC9898FULL, 
            0xF1673DD35E946DDDULL, 0xCFA68C0D66B28CF3ULL, 0x2B12CDD7E74F9911ULL, 0xE85037AC735F1B2DULL, 
            0x4752580A63A9C3DDULL, 0x6D951600B7DC7CF9ULL, 0xC5F6809AE583DB7FULL, 0x44C556D8453ADA7FULL, 
            0xC88D6B580CEBC423ULL, 0xE47C2C8FC94D1869ULL, 0xB8D2ACD36EAF4722ULL, 0x6DF363EFE6709CB1ULL, 
            0x35445303F8BC3D64ULL, 0x90F6FF037F266511ULL, 0x6E275BDFB87B8C50ULL, 0x20C458E7855F4288ULL, 
            0x7448C875D406B0DCULL, 0xE52AFAE70732F9A5ULL, 0x65CDA277A5569938ULL, 0x1EA351A0E39733EFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseHConstants = {
    0xA3A63ADAD3175CADULL,
    0x6EB05C49253F55E0ULL,
    0x441E489E01B2232DULL,
    0xA3A63ADAD3175CADULL,
    0x6EB05C49253F55E0ULL,
    0x441E489E01B2232DULL,
    0x3A322FF0C239CC8FULL,
    0x190EA80D8EC899A4ULL,
    0xDA,
    0xF3,
    0x15,
    0x93,
    0xC1,
    0xA8,
    0x7D,
    0xCE
};

