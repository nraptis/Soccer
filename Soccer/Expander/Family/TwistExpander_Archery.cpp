#include "TwistExpander_Archery.hpp"
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

TwistExpander_Archery::TwistExpander_Archery()
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

void TwistExpander_Archery::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
        aPrevious = 14018512822996973453U;
        aCarry = 17032721451980606999U;
        aWandererA = 14063664033270764432U;
        aWandererB = 9357016151708142340U;
        aWandererC = 17160676882857950533U;
        aWandererD = 12806646033907328157U;
        aWandererE = 13107175157044094419U;
        aWandererF = 17844791005003190993U;
        aWandererG = 9810198638519362935U;
        aWandererH = 10961348639019210902U;
        aWandererI = 13314143548097761971U;
        aWandererJ = 12343370994158465824U;
        aWandererK = 12694283081860680663U;
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
    TwistExpander_Archery_Arx aArx;
    aArx.KDF_A_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
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
    TwistExpander_Archery_Arx aKDF_A_BArx;
    aKDF_A_BArx.KDF_A_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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
    TwistExpander_Archery_Arx aKDF_A_CArx;
    aKDF_A_CArx.KDF_A_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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
    TwistExpander_Archery_Arx aKDF_A_DArx;
    aKDF_A_DArx.KDF_A_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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

void TwistExpander_Archery::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 18361186750879705589U;
        aCarry = 14346952312193912845U;
        aWandererA = 11872411617501171046U;
        aWandererB = 11755823622929935997U;
        aWandererC = 13825395226176373607U;
        aWandererD = 10333052734823830485U;
        aWandererE = 9991747317385082451U;
        aWandererF = 12855091367279497448U;
        aWandererG = 10748486680465969162U;
        aWandererH = 15439384014030787828U;
        aWandererI = 16760324640232150293U;
        aWandererJ = 11218231971944121313U;
        aWandererK = 12939618858755325250U;
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
    TwistExpander_Archery_Arx aKDF_B_AArx;
    aKDF_B_AArx.KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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
    TwistExpander_Archery_Arx aKDF_B_BArx;
    aKDF_B_BArx.KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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
    TwistExpander_Archery_Arx aKDF_B_CArx;
    aKDF_B_CArx.KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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

void TwistExpander_Archery::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr)) { return; }
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
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
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
    TwistExpander_Archery_Arx aSeed_AArx;
    aSeed_AArx.Seed_A(pWorkSpace,
                 pNonce,
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
    TwistExpander_Archery_Arx aSeed_BArx;
    aSeed_BArx.Seed_B(pWorkSpace,
                 pNonce,
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
    TwistExpander_Archery_Arx aSeed_CArx;
    aSeed_CArx.Seed_C(pWorkSpace,
                 pNonce,
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
    TwistExpander_Archery_Arx aSeed_DArx;
    aSeed_DArx.Seed_D(pWorkSpace,
                 pNonce,
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
    TwistExpander_Archery_Arx aSeed_EArx;
    aSeed_EArx.Seed_E(pWorkSpace,
                 pNonce,
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
    TwistExpander_Archery_Arx aSeed_FArx;
    aSeed_FArx.Seed_F(pWorkSpace,
                 pNonce,
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
    TwistExpander_Archery_Arx aSeed_GArx;
    aSeed_GArx.Seed_G(pWorkSpace,
                 pNonce,
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

        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Archery_Arx aGrow_AArx;
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
    TwistExpander_Archery_Arx aGrow_BArx;
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

void TwistExpander_Archery::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Archery::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    {
        aPrevious = 11500141064888793299U;
        aCarry = 17293248302966919201U;
        aWandererA = 10693721504959479914U;
        aWandererB = 17689831000012628648U;
        aWandererC = 16401329625773780501U;
        aWandererD = 10534901362724942485U;
        aWandererE = 10770434060302642600U;
        aWandererF = 11857242215584377111U;
        aWandererG = 17131914216250317628U;
        aWandererH = 16828115029521566336U;
        aWandererI = 12217737695913411336U;
        aWandererJ = 14717068314871390575U;
        aWandererK = 15061704998904743332U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Archery_Arx aTwist_AArx;
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
    TwistExpander_Archery_Arx aTwist_BArx;
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
    TwistExpander_Archery_Arx aTwist_CArx;
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
    TwistExpander_Archery_Arx aTwist_DArx;
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
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_Archery_Arx aGrow_AArx;
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
        TwistExpander_Archery_Arx aGrow_BArx;
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

void TwistExpander_Archery::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 3 with offsets 7033U, 1982U, 3864U, 3679U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7033U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1982U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3864U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3679U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 2, 0 with offsets 1756U, 4760U, 1386U, 1199U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1756U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4760U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1386U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1199U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 3, 1 with offsets 2449U, 7947U, 2004U, 5445U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2449U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7947U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2004U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5445U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 0, 2 with offsets 7318U, 8051U, 4069U, 7572U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7318U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8051U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4069U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7572U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 with offsets 1036U, 1315U, 817U, 1613U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1036U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1315U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1613U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 0, 1 with offsets 1316U, 207U, 1058U, 1207U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1316U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 207U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1058U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1207U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 3, 2 with offsets 731U, 1261U, 459U, 943U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 731U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1261U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 459U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 943U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 1694U, 1211U, 1580U, 1755U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1694U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1211U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1580U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1755U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1779U, 10U, 305U, 478U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1779U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 10U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 305U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 478U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Archery::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 3 with offsets 1440U, 5158U, 7329U, 1709U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1440U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5158U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7329U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1709U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 2, 0 with offsets 3685U, 5025U, 109U, 4531U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3685U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5025U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 109U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4531U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 0, 2 with offsets 2510U, 5177U, 7061U, 691U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2510U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5177U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7061U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 691U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 3, 1 with offsets 3652U, 6348U, 4683U, 5375U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3652U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6348U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5375U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7030U, 1636U, 1913U, 6915U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7030U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1636U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1913U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6915U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1903U, 907U, 1484U, 314U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1903U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 907U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1484U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 314U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1981U, 1347U, 1547U, 1992U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1981U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1347U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1547U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1992U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 49U, 1011U, 1561U, 1976U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 49U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1011U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1561U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1976U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 924U, 1729U, 840U, 1516U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 924U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1729U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 840U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1516U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 3, 2 [0..<W_KEY]
        // offsets: 1675U, 544U, 1004U, 1393U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1675U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 544U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1004U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1393U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Archery::kPhaseASalts = {
    {
        {
            0xCF69247609F7996AULL, 0x4D89308A202D4AD3ULL, 0x30C8EEA928B87027ULL, 0x257B00F4B0240EF3ULL, 
            0xB76BA316C1B37882ULL, 0xAFAD5C12D8BE8F73ULL, 0xA5196BCEE89AF418ULL, 0xB0B9EC3B5EABED90ULL, 
            0xD91CD6BC957C1A12ULL, 0x3412D354A995FB14ULL, 0x25370649151086DDULL, 0x1B903AC6ACD1D114ULL, 
            0xF483D5127C191CC5ULL, 0x7463845A09E69E6CULL, 0x211BBD7ED0A4D576ULL, 0xCEC144B0FFF41BC9ULL, 
            0x0E8A6450ECA585F2ULL, 0x8A8E0C40DAB68D7BULL, 0xBECBEBCA80184656ULL, 0x6FB7628768728AE9ULL, 
            0x1F000386571BD922ULL, 0x08FA4F52E9378991ULL, 0x53B97D3AC35E1785ULL, 0xF976A2EA071B7A3EULL, 
            0x045C92BA3A8E89F0ULL, 0x125316F86532A062ULL, 0x8EA4183839AE7CC0ULL, 0x82396011E335270AULL, 
            0x1E30A71E5D7EB944ULL, 0x954BE2FBEF9CCC64ULL, 0x79A2D31261D4973BULL, 0x827E4B87319119A3ULL
        },
        {
            0xF9BDA3B1BD47CBA5ULL, 0x1DBB02F7CAA7BD61ULL, 0xB695E33C89BDAD3CULL, 0xEA82F11A17150FD6ULL, 
            0xE0508D8D0CAF70E1ULL, 0x05100B354CE883D6ULL, 0xAD6B4CF0588904D7ULL, 0x3F0A80C0335AA311ULL, 
            0x0FD1FC5F9BC64FDDULL, 0xB9412AEC3011EF32ULL, 0xE1075E41913F301EULL, 0x7227F59C179E8994ULL, 
            0xD1A7C13EC82A30D0ULL, 0x83719C526864D50DULL, 0xDE5051F9A43B399EULL, 0x448D58B2787B2EC7ULL, 
            0x25BCA36C23C3F85CULL, 0x5F396D9F31F54A58ULL, 0x705414BBC7C267C2ULL, 0xD6D4A0872824A56FULL, 
            0xA9534D7A63AACA4AULL, 0x08827C440CC71105ULL, 0x19A67A9F3E5DAE88ULL, 0x003FE1516B8EF0D1ULL, 
            0x9B8EE2A35BF0822BULL, 0x21F99F8FCAE44547ULL, 0x0B8AC36425B1DAD1ULL, 0x3168DB4A77E1A02DULL, 
            0xF73485858BEECE6BULL, 0xD06B10D7CF038C48ULL, 0x8CEF5ACFC13CF09DULL, 0xC22D18100C4346A7ULL
        },
        {
            0xB4DFBB20D62C63DBULL, 0xB48482D3DB974474ULL, 0x4F540669802031F1ULL, 0x02B3FC6DB61644AFULL, 
            0xCFCDDA37DB957456ULL, 0x2275BFFA73371648ULL, 0x924F1E79EC40DFABULL, 0xFC25804F26E33543ULL, 
            0x266B38161706E298ULL, 0x16DF63B5DE236824ULL, 0x4B98B4E7AE36E042ULL, 0xCAE47CAAE6F9EF1EULL, 
            0x8C748399AF1F50D4ULL, 0xFD0A95024F1D7593ULL, 0x11684D788842BC57ULL, 0xFCA5C42075E6A67FULL, 
            0xED578A4057061DD4ULL, 0x0EB59019ACF22B73ULL, 0x7C7F4D143D547830ULL, 0x3E0AEEB170C6BD53ULL, 
            0x66A33E031FF3B6E5ULL, 0x339342869A82FE32ULL, 0x396A514D060F886DULL, 0x431D11AFB63A2DADULL, 
            0xB944059B85B70179ULL, 0x86CC43CE5BF521D0ULL, 0x64C44484E3331A5EULL, 0x60D0CE0A94F0FC4AULL, 
            0x6FBF0FD9C0D19E06ULL, 0x8A623AD579C0B960ULL, 0xCB3F2899FEAFA55FULL, 0xC3747424CF00ACC4ULL
        },
        {
            0x7263038AC4CA6DAEULL, 0x9D2E389027D8F5D6ULL, 0xF94AE8B0A595EE81ULL, 0x6AB480C7D6B0FCE1ULL, 
            0x44859127BACAC771ULL, 0x5DF78458FB440998ULL, 0x39D3D027FD9EA59BULL, 0x8B2D5EE89657BB69ULL, 
            0x5646164342546E69ULL, 0x94D31780F9B2053CULL, 0xFA17A87A9C4487ABULL, 0x472776D56C25BC02ULL, 
            0x81FC9C869F2758E0ULL, 0xBF3DFF0FEAD3112AULL, 0xD6C2569C16F33200ULL, 0x4C3D2E03679AD5E3ULL, 
            0x66054F77D67DB825ULL, 0xC0AC9F43D3CD5221ULL, 0x7BFBB384B1A46E25ULL, 0xF3931B6FA089F882ULL, 
            0xB4EF6D1DC4D678B3ULL, 0xFFA31A855EC9C195ULL, 0xCC2036AE85698F18ULL, 0x66EB68E1F4873733ULL, 
            0x7DF7BB3287747383ULL, 0x302E50856B8E06ACULL, 0xBDC9310FD9060D1CULL, 0x42FF92207D0A377EULL, 
            0x90DDBDF092D95B61ULL, 0xFD8A8DCB78EFD7A9ULL, 0xDE8EA8BE744547D6ULL, 0xB52D5EEBA016B9A7ULL
        },
        {
            0xEAE8487B85080829ULL, 0x85D14946CE8E5DFAULL, 0x56A898E05828CFF6ULL, 0xFD9193C7FEED03A6ULL, 
            0x87CD5DDE987A67AAULL, 0xD2A83FB5D4C2BDE0ULL, 0x0DD6446793E87A14ULL, 0xB61930CF8E6402ECULL, 
            0xC888E6D44CED59D4ULL, 0xFC948EE6521C8F40ULL, 0xA76A96E9FB9A28D7ULL, 0x717C1754958664E6ULL, 
            0x1FB9719AFC59C84EULL, 0x892604B3FD0D201AULL, 0x31C550FA13A3C6F9ULL, 0x6EE0CA6F1E1AE5C5ULL, 
            0xE45731AF8103F30DULL, 0x14497492745D5934ULL, 0xCA8D5781BE081B59ULL, 0x52B719DE0B2201FCULL, 
            0x7A22FAEBEF4639CBULL, 0x5E3990D8535C4908ULL, 0xFC1EF1FF1D94C8CDULL, 0x2F368F6141CBCE45ULL, 
            0xFAC43D5EE6C7DEF8ULL, 0x119328A02235144FULL, 0x230485CF179EAB6DULL, 0xECEA9931A31EE613ULL, 
            0xA4A239EF0464D75EULL, 0x66ABE8B13394B672ULL, 0x169DC26B65D86432ULL, 0xEEF0E87DBA81930AULL
        },
        {
            0x5CABB35CCEFB89D9ULL, 0x877B9D3F94934804ULL, 0x70F5D742517DA2BCULL, 0xCEDBD9D11771DB27ULL, 
            0x7BE6E1559352FC08ULL, 0xAD5C35CFB5AEB4FCULL, 0x54886E50DD4AE226ULL, 0x735E2E0AE965E568ULL, 
            0xF03F3E568C03DED7ULL, 0xB642E8397978BFD4ULL, 0xF8DA878C53534D21ULL, 0xDCABAFC7B6174DFCULL, 
            0x44E48C85646DE42BULL, 0xEE5428B117BB7F24ULL, 0x6075E7A54D3A8C0DULL, 0xAD2BE90A06BDD2AAULL, 
            0xA477AC51C8E25735ULL, 0x423E306DDA9C463DULL, 0x457F7BFB3D3901E4ULL, 0xEDF5E6F1A0D1E06DULL, 
            0xD0B0CA15CFE0E04BULL, 0xF28D81638D7B1446ULL, 0xD9C472E9071E2511ULL, 0xA10A623A2A7007F1ULL, 
            0xC45DFCEA98AF0CF3ULL, 0x50366932695312D3ULL, 0xB287A56511C42E52ULL, 0x7197AFE0A38BA854ULL, 
            0x97B44AC46B255641ULL, 0x85897AB2586236A5ULL, 0x4A0736AC0933DD29ULL, 0x196BF9A032E3A04FULL
        }
    },
    {
        {
            0xD8105A97AC5B869EULL, 0x9C8D2FEA4772466BULL, 0xCDE2610DBEC200D3ULL, 0x0069FAFA28246DDBULL, 
            0xEA8FE8552DBB71F8ULL, 0x3D27B6660ABADC3DULL, 0x3EBBF06119C6ED18ULL, 0x938FAC1079ED47D6ULL, 
            0x0BA3CBCA4C0DAD4EULL, 0x17671B32F151D83DULL, 0xC2B07DAC53658A37ULL, 0x78AA08BCAA1B5A8AULL, 
            0x248ABFD24B5354FEULL, 0xF434BBCBED68841CULL, 0xE198C6C3B2C9FCC5ULL, 0xD1689A5C70BB648BULL, 
            0x837CA2A8C106DED1ULL, 0x1D28C0C59A4F612EULL, 0xB0BAD2722FC4EB4AULL, 0xC1D7FEC4AD7D0E35ULL, 
            0x7A45D9B1D56C12E6ULL, 0x3E0BCA35CE20D31AULL, 0x5AE6250D64148856ULL, 0x15C74FFBBE24C7A7ULL, 
            0x799CA24AE9F0A07AULL, 0x9E2AA572C8E849D8ULL, 0xFBDF364C4980A3FDULL, 0x0EF3B9F6D444FC0DULL, 
            0xCFB5CCA0EA3FBA73ULL, 0x2E59F58B0AC83047ULL, 0xE08DC099E2B8330CULL, 0x57E33FED997DB8A3ULL
        },
        {
            0xA9B7E330755E367EULL, 0x6412D28954B83253ULL, 0x7BF1B1750D9EDF99ULL, 0x4086008BFF68B15AULL, 
            0xC898C64A11202CB9ULL, 0xEABC902FDC507068ULL, 0xBC481100A84DC272ULL, 0xCB6105DEFF68FA5DULL, 
            0x4E9A8AC149235693ULL, 0xEA1E509F0F852B1FULL, 0xBE69D2758E8181AFULL, 0xE754E4E4E6392ABCULL, 
            0x5C5CE0FD0CEC5386ULL, 0xDD2218CE62A3F314ULL, 0x884060112168B456ULL, 0x2BE721686475FD79ULL, 
            0x51AD11E7C4F89360ULL, 0x685651C03771A83CULL, 0xBB10D45700DFA7F5ULL, 0x29771FF7938471C9ULL, 
            0x004C923FE85C2637ULL, 0xCE8FC603A2722F0EULL, 0xB285A49DBB880177ULL, 0xD70D34C521BD60F8ULL, 
            0x6514E88049C2D929ULL, 0x051912D545744264ULL, 0x618801D178E978C8ULL, 0x293894CCAB20D814ULL, 
            0x9C833AF9FC9B5EC0ULL, 0x94406EA6BF3325B1ULL, 0xFA2667C8F641E711ULL, 0x864195A519B72B6EULL
        },
        {
            0x44E73EE6FDC529B0ULL, 0x9C72D68F1F45E0BCULL, 0x0090A2105E4FBFBAULL, 0xBCA7415EB119DF11ULL, 
            0x68490B6E05643BD8ULL, 0x5FB9EB4DB6F7A0FAULL, 0x5D5C7F8041976BBFULL, 0x332290B4FD1DB3BCULL, 
            0x587AE1425B78F059ULL, 0x1EF7E673DA960206ULL, 0x048F2757E92C4491ULL, 0x972C889C7185B179ULL, 
            0xEBA0856E1DA4ADE7ULL, 0xBD4B711545478B00ULL, 0x760A2A92804501E3ULL, 0x41C8C7365F4C59DDULL, 
            0x3F576B7A85C6E770ULL, 0x6E304BF23DC5C866ULL, 0xAF713A57B0AD3BA4ULL, 0x1C013EEE413FB363ULL, 
            0xFEDF089F64DB8D1CULL, 0xC634800BE4936E81ULL, 0x9F45173D41831F59ULL, 0x8F760D84A427E2B1ULL, 
            0x6203766C46564A0CULL, 0x05BE18044D923278ULL, 0x73C9BC196D6DB672ULL, 0x2C0AEF5BD65C7F58ULL, 
            0x2122174FD7A31588ULL, 0x91196790E55F7AE6ULL, 0x9AF0C75604F4B46DULL, 0x6963027634F2F4F3ULL
        },
        {
            0xDA2CE9871FDCDE7FULL, 0x3725D0C5AFB4B520ULL, 0x1A0082FD5B775CEFULL, 0x6B2FFAF73115D8ACULL, 
            0x6D61FAFB8F11F4FBULL, 0x67B1828EA834A8ECULL, 0x684A7A3B733FDF34ULL, 0xE52DFA78F2B132F3ULL, 
            0xF5F3D146EF37A959ULL, 0x99692A0441553B5DULL, 0x43C66A7344DAE6DFULL, 0xE92A2F20BBC6A95DULL, 
            0x59F5DBB35B91F018ULL, 0x15FE88AFDDDFB838ULL, 0x3D375B2CF3576C50ULL, 0x98CC01D9B18D3C5BULL, 
            0x8D263F43C02100D5ULL, 0xC5132114408208D1ULL, 0xB6E9BC134CDD3994ULL, 0x52F7B2947DB4BB55ULL, 
            0x02DBBD5E4D634874ULL, 0x9914D466213308D3ULL, 0x5AF1C1D53A907297ULL, 0xC0774F2449B74665ULL, 
            0xB95FBFD868434AB5ULL, 0x9CFEB936F07B9F6BULL, 0xF0D2836F245B5A76ULL, 0x6C2A2EC776492C86ULL, 
            0xB2AA632D3BFE7B08ULL, 0x903879FC5D466A66ULL, 0x78636BE4417E3646ULL, 0x4F0B02E74701F761ULL
        },
        {
            0x4D5FAD2109121B61ULL, 0xD0AB8F0E0AB4EC76ULL, 0x31F01BCD2A037AE3ULL, 0x328709BEBCE891D2ULL, 
            0x577232F9B932DD1FULL, 0x72AFF093E0E084EFULL, 0x08249C0FCD308A9BULL, 0xB93875C48875760CULL, 
            0xDB3B00D6AA5F8CFFULL, 0x5BEB27DA500F4F4DULL, 0x7946FC7D14FA6894ULL, 0xD1BBBA3D57BD75E5ULL, 
            0x936B9BBE2723FF01ULL, 0x39BCB47F9107494CULL, 0x9E402904D2DD3F71ULL, 0x3821FBED00566D4AULL, 
            0xBC1CDAEE9B07B024ULL, 0xFF7A66C10BFEEAA3ULL, 0x8A91DD9808AC1D12ULL, 0x3FF14C46AA7A76E4ULL, 
            0x2F237D9C73D29D6BULL, 0xE8209CAFE16F323DULL, 0xE84BB149B473CDCEULL, 0x8E24204D87818DCDULL, 
            0xDFEB150F17F5A48AULL, 0x6A1E127CB3B4123EULL, 0x933E2D19884F0E53ULL, 0xFAD350D8C41FC9FEULL, 
            0x666FE35C089AC440ULL, 0xA1BF3F0A605BE465ULL, 0xA69BC49A42E987AEULL, 0xBB80C0BDB4A9C211ULL
        },
        {
            0xCC19393DFC74D2E9ULL, 0x848164D429361663ULL, 0x04CF11EC9E2C3665ULL, 0x37B3F8CA00C965ABULL, 
            0x8447120AF81B0379ULL, 0x2C23A28DC88879F7ULL, 0x5BC2B516533868B2ULL, 0x3CF788369D60D177ULL, 
            0x13CC03827F90C2C0ULL, 0xD9F84685073B822EULL, 0xBC3659F955F1585CULL, 0x2DDA207C86CED646ULL, 
            0xD80EA60F841B2E43ULL, 0x747656F166DDA91EULL, 0x057F410ED947BD67ULL, 0x115F3CCCFA81578AULL, 
            0x46E9BF3898C3AA47ULL, 0x24B9C3EE214CCF07ULL, 0xB13B0916A8E24A94ULL, 0x20948BD674FE69D6ULL, 
            0xE30D90DE5064C376ULL, 0x3A07B39938205807ULL, 0x9294CEDBC4828EBDULL, 0x31C41E471C37FADFULL, 
            0x203F4214EB658BD2ULL, 0x62D347AF32AB8DF1ULL, 0x705BCDE0DE3BB2BCULL, 0x8D69746657F4D172ULL, 
            0xA67D9EF1182F7110ULL, 0xB3E914FA116EC364ULL, 0xA78660ED1EF0FEDEULL, 0x40422709112F137CULL
        }
    },
    {
        {
            0x10FE2025F958A8C6ULL, 0xC2CE39D57FDD5341ULL, 0x3D66A58B1A1F06ECULL, 0x6A7BD0A6183971F4ULL, 
            0x25A59EA5F300E3D8ULL, 0x592C3DFEDB2D11CDULL, 0xAA415154EDB18ED2ULL, 0x2E9D4658BEF4B32CULL, 
            0xFDB266FFA6AF67D3ULL, 0xFAC5C87C85F8FBA1ULL, 0x6A2564C9B3A106FEULL, 0x47A245B1420B0C67ULL, 
            0x0F3FD5BDB52B1745ULL, 0xF678B5CF89659E78ULL, 0xBC6C116687C6873FULL, 0xFB04237D838A3F82ULL, 
            0xCBC05075BF7B14A9ULL, 0xEA904D85E6FC97A4ULL, 0x68BF639D8D4CD5B0ULL, 0xFC65EAF297E98EA5ULL, 
            0xD0C91A299CFD8C38ULL, 0x7A22B03A5A501274ULL, 0xE3D080026174AF05ULL, 0x4B4455056AEA1339ULL, 
            0xE3A3975BCAE2C254ULL, 0x7AB3878B2BCA17AAULL, 0xE7603574112D0612ULL, 0x42D6A06AF9C69EC0ULL, 
            0x2066EA15FA626855ULL, 0xA2B8C041F77064E6ULL, 0x86BD9DDFFC25747DULL, 0x3CE8D27787EE224DULL
        },
        {
            0x0FBE25910D9A204CULL, 0x6C0908A0954B6B49ULL, 0x065EAB7B1E38832AULL, 0xA0F74C0096DAD086ULL, 
            0x1A2177164B2B81BFULL, 0x8F7A4C653F190B30ULL, 0x9982CCF8882F64A8ULL, 0xE6D0AD682B7179F0ULL, 
            0xF123CCE9B5720660ULL, 0x6FCEE2F0218E2DA7ULL, 0xA1E1DF80BFCF3F8FULL, 0x7ABA16F0DE074908ULL, 
            0xBB70F25D0BE384E8ULL, 0x14828A1D06671FF2ULL, 0x92C1538942078DDFULL, 0xAF166EAE9BCFD552ULL, 
            0xDBAEC8FF8F6AAB83ULL, 0x647E8BD59C4DF9F2ULL, 0x752C371E3FE613BCULL, 0xD93C51C41CF4986AULL, 
            0xBDC223C207EF5ABEULL, 0xC9FBDA84A1BF5CE6ULL, 0x65B2723D0D14081CULL, 0xAB2580253E9247C1ULL, 
            0x7A2A593EB78375E2ULL, 0xC0125AB4607A3B42ULL, 0xC97191FCA79EC8F0ULL, 0x3554EF294E697CCCULL, 
            0x55AD5A4F6A2A63D7ULL, 0xEBB4D664C4057421ULL, 0x16E6C1A97AED94C7ULL, 0xE4FAC4B9EC8D8D3CULL
        },
        {
            0xE52F267C8F4EF1D1ULL, 0x328C1FCC98142403ULL, 0x0CDD51137D6C2213ULL, 0x7F9E952B328E8800ULL, 
            0x482C007A44F879BDULL, 0xADBFDE870991F2C6ULL, 0x4BF3BBFA5E99EFF9ULL, 0x78E3394A357D2A1BULL, 
            0xEFE8FE391104D674ULL, 0xCF67B1B0855152F8ULL, 0x95AA37F7A66B559AULL, 0x715A8F91EECC3F5CULL, 
            0x6B12C2675CE36F7BULL, 0xB7FAF4E0197C53C9ULL, 0x77DCDC6AB5DF971BULL, 0xD792420CF053C595ULL, 
            0xAB709C82A8488CBCULL, 0x871C52328593AF61ULL, 0x762C8442C5BEE271ULL, 0x9B8E0F75476975A2ULL, 
            0x6182F40926674984ULL, 0x68293264FB50A7D3ULL, 0x5FD29CB72107B791ULL, 0xE1555920ADFF0443ULL, 
            0x9B7D5CD372A77AC3ULL, 0x4D880E1175B312FCULL, 0xF7867F296B645557ULL, 0xD8C7A913019BA16DULL, 
            0x412B9ED28C411E14ULL, 0x037703E0BB495BF4ULL, 0xDFA293D9D89DF4F5ULL, 0x116D7AB17FA6C557ULL
        },
        {
            0xED299FF3DCAA77F2ULL, 0x74B0A972716AC628ULL, 0xE6B5560235D26BB5ULL, 0x4E0E9AF3F6E34257ULL, 
            0xE96C065A68C7073AULL, 0x8B1EA444740E3620ULL, 0x213EB12F75CD45E6ULL, 0xB5D4AA04D4BB3966ULL, 
            0x7B3457AB50C1F253ULL, 0xD4DC814FD275DC52ULL, 0x7982510A08B84B1DULL, 0x06E8D97161034D2BULL, 
            0xF755EFC28D537A6AULL, 0x969229C86AF014A0ULL, 0x2057E9163D3386CBULL, 0x164BE7366FD3BB44ULL, 
            0x902E162448759952ULL, 0xC68AC5EB53435FB9ULL, 0x7206339A07254444ULL, 0x0384B6335F06D9D6ULL, 
            0x52E4E0B37692C6F0ULL, 0xC2C28802AAB39229ULL, 0x723D951DF3BE1874ULL, 0x4126098A2EC31870ULL, 
            0x9CE92F970F463A0DULL, 0x2D92403616F23B28ULL, 0x0A31E6A73B0B8B9CULL, 0x8EE8727E6C64CDB8ULL, 
            0x90FB77CA7205F257ULL, 0x25278FA35D7DB547ULL, 0x4E126541D4219F5BULL, 0x11AAB162E79FD02FULL
        },
        {
            0x176E942DA211F839ULL, 0x5253D7F9E911EEC3ULL, 0x1734D9475F18B813ULL, 0x6FE1B1B6FA945FD3ULL, 
            0x3F177C06022C7FE1ULL, 0x657C2A371119E298ULL, 0x267C17630A25569DULL, 0x4602E44429A88111ULL, 
            0xB7BE0CFB008B8678ULL, 0xB5AB0FC48912E0D1ULL, 0x3779961433682B1DULL, 0xCD620129467C770CULL, 
            0x54B368A240D4038CULL, 0xB38CBD5C4A4FE668ULL, 0x7F951F3A0F84CD95ULL, 0xD74470136E2AAE0CULL, 
            0x05DD9027386F069CULL, 0x2F41A8DA3231C0E4ULL, 0x8DFAA3239F133581ULL, 0xD4727576ED9F9037ULL, 
            0x430A4FA745A7F094ULL, 0xFD3E5E6AF8ED7A62ULL, 0xD9EF48B418D8D36BULL, 0xE56F7AB4707446FBULL, 
            0xD99CBDBC5F5E8A46ULL, 0x0BC6F8A98EA4F289ULL, 0x8CCFF0D94A424E9CULL, 0x04D60B7C06FCCD75ULL, 
            0x5625FFC49E8AC074ULL, 0xF18A04C64C10B2DBULL, 0x2E4F52D92D7FD345ULL, 0x3F00C213666B580FULL
        },
        {
            0xF779C1FB60B3849FULL, 0xF8C4334A84D88712ULL, 0x1C171C9A3ABD256FULL, 0xD7DEAE7484D351BFULL, 
            0xD4CC1FFA1F0737EAULL, 0x5C981AB28AC298C3ULL, 0x836C508C7A7F9EFEULL, 0x6FA1CA929E34A89BULL, 
            0xC567A4654BA04306ULL, 0xFD53A319008E56AAULL, 0x19406460729354D9ULL, 0x9CD55C7D2E161DBAULL, 
            0xA8D322A89131FD45ULL, 0x0254AB1D5EDBCC1AULL, 0x1BE1D9FC23AD0949ULL, 0x4C22FF1A52E9418FULL, 
            0x9FBD0B40AFF1C404ULL, 0x36AB3F9CAFA35291ULL, 0x70D65F03C925F37CULL, 0x53EA6E4D8695EEADULL, 
            0x31473AC17350CC14ULL, 0x747F3B7D470EE339ULL, 0xCFA8A0636D30C989ULL, 0xC61FFC6FDDF37399ULL, 
            0xC0DCBE3507C54B62ULL, 0xECCDB046A9AF4453ULL, 0x5FB90C0F2A89C624ULL, 0x5452A9FBF71FA377ULL, 
            0x7BC45071DFFF5FE8ULL, 0x59E0388F7B431DCCULL, 0x8C3E04C15B6B7A59ULL, 0x622B91130A5928B6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseAConstants = {
    0xB4E41A078CDAC8B9ULL,
    0x86B52A53407EB27DULL,
    0xAC07783C01D2E72AULL,
    0xB4E41A078CDAC8B9ULL,
    0x86B52A53407EB27DULL,
    0xAC07783C01D2E72AULL,
    0xB5BD6476AACFCED0ULL,
    0xE98CC85C9CDAC62BULL,
    0x51,
    0x75,
    0xA9,
    0x1F,
    0xA3,
    0x14,
    0xD4,
    0xAF
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseBSalts = {
    {
        {
            0xD7706C8487202A0FULL, 0x198C794280520B16ULL, 0x52F8BD662924E6BBULL, 0xD4990D1D7B2FAB21ULL, 
            0x5371B44E291DA513ULL, 0xC201818B836C6309ULL, 0x0614B3A98F6185E5ULL, 0xEEB299EAC7CBDBD1ULL, 
            0xB04EFA95E8042972ULL, 0x90C89E94234324E4ULL, 0x45AF1284BDB29F74ULL, 0xC91A9F9FB660DCC0ULL, 
            0xF45D56053078AB3CULL, 0x4C1D98DF35B4E9C6ULL, 0xE08EFF12444A9369ULL, 0xC51CDD183BD9BA7BULL, 
            0x785047B47EC660B8ULL, 0x5BCF455A06E087CFULL, 0xC97E96075B796189ULL, 0x86E1C65103AA3999ULL, 
            0xF95CC1F9D71B9368ULL, 0x4D61F6AFAA0807F8ULL, 0xA56D757FFFDD315AULL, 0xF013DD3419A4BCF4ULL, 
            0xB76D7436638DCCDBULL, 0x96C76D3893E9C906ULL, 0xDEE2517AAD7CF2CCULL, 0x5EF3F92D8700F0C6ULL, 
            0x56C08A351F7E4103ULL, 0x6BA0906344DEA6DAULL, 0x8C3B00ED16F55EDFULL, 0x20DB80187446CBDEULL
        },
        {
            0xA9991655CDFCB753ULL, 0x01C06089FDA16A1AULL, 0x0C90272E51DC41EDULL, 0x0F78037F4968BBD1ULL, 
            0xF83B1C5E45C83023ULL, 0x6B9371FF59E6F5F4ULL, 0x5546BAF728DD4AEDULL, 0xDA8094162C4DA5FEULL, 
            0x48E39D2298F1B062ULL, 0xCC8E13027602F2F4ULL, 0x7319C59A37111B0AULL, 0x3972DE5389422088ULL, 
            0xA8DF319CB0FB025BULL, 0x7B0381B9AFA23680ULL, 0x31703251C101B8DEULL, 0x0A3538CF9C765BB7ULL, 
            0xFE9897931612F899ULL, 0x38377E92BBAA9517ULL, 0x3F41ABDA07C0285AULL, 0x212127D649D1A203ULL, 
            0x76D8DB6E66326B19ULL, 0xC79581585834E3E5ULL, 0xAD321FAEC509A666ULL, 0xC563F1556EBD0A30ULL, 
            0x044803BFB17B62FFULL, 0xC5C8616849BD63EEULL, 0x349FE0C329E0CC8AULL, 0xC40FD9BFA1A161EFULL, 
            0x1F03E517CE432070ULL, 0xBA8632269B75AE5DULL, 0xB559D29AB686FBA4ULL, 0x71248F31FB5F6618ULL
        },
        {
            0x42A669E8593CCABBULL, 0x9853052133FCA011ULL, 0x26EFE0A4D10FFB89ULL, 0x8D939FE4E21144BCULL, 
            0x4D69BF331295C183ULL, 0xD5D792B4F4F2F575ULL, 0x59313B6C6D372A34ULL, 0xB7A7CAB4A0B3E7BAULL, 
            0xD5295D10956D3ED2ULL, 0x901C95C4E866C22BULL, 0x28F8AAB166FF21A1ULL, 0x6F060ACC7F7519B5ULL, 
            0x8197A4A873878938ULL, 0xD81C29DC95E4DB3BULL, 0xC2ABBE8299EE44CFULL, 0xFAD9274BABCD690AULL, 
            0x12F2E5DBE310BA93ULL, 0xF9EC51EC67297777ULL, 0xA1CD934A2FE40527ULL, 0xD86AE76523BF1340ULL, 
            0xD3E79A5508915D80ULL, 0x4543EF13AF948E96ULL, 0x2C8CE357B2C70667ULL, 0x4B24E11125952E59ULL, 
            0x920F88E73CBF9A15ULL, 0x7B4246484E98C2F7ULL, 0x1F53A274AECC5B3FULL, 0x3AA584F367F799A8ULL, 
            0xCDE3887FFDA6EF97ULL, 0x74F945D0A0A53A6EULL, 0xD8919FA658B44D57ULL, 0x7F32EEDD7B5980DCULL
        },
        {
            0x493F1FB3A40FBDABULL, 0xE9340EAB70FE04CEULL, 0x6B3FE5F1A624B302ULL, 0x3057AE499D4AACBBULL, 
            0x5F8109BB2DDAE240ULL, 0x611C42FCC5293580ULL, 0xD8917838335978B1ULL, 0x50E24D4F8F348A38ULL, 
            0x6C69A8935D0B51F2ULL, 0x777540DA46D84BC9ULL, 0x3842E5D535C9A6FBULL, 0x0589A3DBF2BF3A4AULL, 
            0x585C87966CB4E545ULL, 0xE56BC148F099E7F5ULL, 0xD4CB16EACBD08AA4ULL, 0x449456FD76EFD367ULL, 
            0xF3C469BFFD504B62ULL, 0x20CFE0E39221DA38ULL, 0xD02142AE7268F7D3ULL, 0xC2ADF90802B6535FULL, 
            0x04A536B7B30549F9ULL, 0x6C85FEAABDD55D2CULL, 0x0B07CA9D4748006EULL, 0xB5EBBFD5A038D9E3ULL, 
            0x84B05F560051A4C9ULL, 0x3424647B465C59CBULL, 0x0135B5B5079658E3ULL, 0x71A8677020579EF6ULL, 
            0xF295A177A77C967CULL, 0x021C20D4D839B893ULL, 0x01736DAE510E982CULL, 0xB64CAC3FD73A231FULL
        },
        {
            0x1066C6A81DF0708CULL, 0xF55731AD2C09C4ACULL, 0xA0AF342BA26532C9ULL, 0xECE8E9610F69F00CULL, 
            0x87C5FD5D8FE37215ULL, 0xEF2A5B8408BD4715ULL, 0x226DBC819B52264BULL, 0xA91DDAAE5F7547FCULL, 
            0x80E4FE04820143B0ULL, 0x9DC5881CF2281F90ULL, 0x522A28ED92045554ULL, 0x7E3D0F65823F8542ULL, 
            0x4C456C57EFC0C290ULL, 0x72EBB04C57A7EAFFULL, 0x3CEA17EF387036B8ULL, 0xDE798299BD3B41EBULL, 
            0xEEA39DD6D95660AAULL, 0xBDB0081483978C10ULL, 0xC34235CDB849B6F0ULL, 0xABA1F0F93328DAD8ULL, 
            0xAFA248AF0701690FULL, 0x41C205A4333107EEULL, 0x77C1D9BF72C571C5ULL, 0x42E4AC6A1277FF64ULL, 
            0xCBB6D25CC6C5975FULL, 0x3A6AF0B61D3958CDULL, 0xF7F5B13474031DB1ULL, 0xF4AB246BBEB99ECEULL, 
            0xEC484CA032CF536EULL, 0x99BF280A920CB513ULL, 0xFB174DEBE9F74EF2ULL, 0x77A16E2A93668401ULL
        },
        {
            0xE2B02BE672BF5570ULL, 0xBF05A7E4708C1E3DULL, 0xECBC2D78035BD1DEULL, 0x68ACCF236165818FULL, 
            0x705905E11AEDB6E0ULL, 0x91CF1605A5A8C715ULL, 0xE01D526A29A5DA38ULL, 0x3DB0FEC6F228D868ULL, 
            0x973D66CB9FCB4F7CULL, 0x9E5A2AC96F5DCE43ULL, 0xF40DE2E01936CFD3ULL, 0xAF4472B1D38A9E6DULL, 
            0x7E75FC01E5D86819ULL, 0x34C7E240B540443DULL, 0xFBC443BC7D03E70AULL, 0xE1CACE31C06A97EDULL, 
            0x3495B7FE626910B5ULL, 0x4C77321709BE36ABULL, 0x0E0CAB2030EB1A65ULL, 0xA7E3C04B7DB60F52ULL, 
            0x29BF83A2E7C84D72ULL, 0x1B435A61781D03EEULL, 0xC2FC170848DA86CEULL, 0x903B24E77B2C63A0ULL, 
            0x0F7551E3EC93C20BULL, 0xE7C0AAB5136F3BEAULL, 0x6A0AECDA6A41A9D9ULL, 0xD521B59A1FA24BDFULL, 
            0x2AC6052E05CE6899ULL, 0x15018CDCA58E9C35ULL, 0xEDD7224706F7F4EDULL, 0x9D961DBD3A04B387ULL
        }
    },
    {
        {
            0x0FDDB474021ADD37ULL, 0xEF5A04E48316F7A1ULL, 0x7E60D63E0F5BD1EFULL, 0x7CFB0887D98CCB3FULL, 
            0xAB3D50D56096142EULL, 0x68340B567E6643EAULL, 0x356E83F6F14ED919ULL, 0x1854EEE9427B7F65ULL, 
            0x29C906B9CB23EF6EULL, 0x959BB5618195B41EULL, 0xB8B61B3FA43BF8D3ULL, 0x8DEA10C905410FA1ULL, 
            0xB485920543211C7AULL, 0xBA581D121B24E6BFULL, 0x08C50870E0990811ULL, 0x10F7DEFB0C772B3AULL, 
            0x8A06342AEE9FB6BEULL, 0x6E5737604E5BA4E9ULL, 0x9F929F28B1A106CBULL, 0x7E8127B25BE289C4ULL, 
            0xDAB1DC65850FD2F3ULL, 0x060A54ABE8F78C89ULL, 0x69329E2A3791A4E5ULL, 0x7B186C6B8DC95ADCULL, 
            0x6FFC28A9F88F12EBULL, 0x8798DC9ECCD3633BULL, 0x6AA90E37E7ED5F0EULL, 0x58D92FAE4A207129ULL, 
            0xF77334A7B4C9A1B3ULL, 0xC113035B93417D66ULL, 0x14B65F247051E228ULL, 0xC9FAA5EF7AB06006ULL
        },
        {
            0xC9AD343F866EBA69ULL, 0x227564CCFCF2614FULL, 0x6B591DC01D892F73ULL, 0xF36BC2FC1A1CE8C5ULL, 
            0x02D4069AC4C577B4ULL, 0x1C54C6A899670AB4ULL, 0xA677228C693E0D5BULL, 0x12C023DB7E7C052AULL, 
            0x3DFF36124086B0B4ULL, 0x9406D32EE5A4A94BULL, 0x9E8F03F84B0E0BFFULL, 0x64A324E13902E19BULL, 
            0x0CC16073FF6E1840ULL, 0xBD40596279DA92D7ULL, 0xD7DC4FDB0B12B28AULL, 0x5DD89B8A231EC1A6ULL, 
            0xE3CA817B739F8357ULL, 0x498919C53CA41BD3ULL, 0x94C8E743A53C161DULL, 0xF4FF7A211A0EA363ULL, 
            0x127D8A1D5030955DULL, 0x1FD1F658A840B948ULL, 0x335E4A2EF6255570ULL, 0xAF710079C0FCACA8ULL, 
            0x8AAB4227B7CAD77CULL, 0xE11A2D76956ECBA2ULL, 0x335F19B8C6E045BFULL, 0x402BFB07A80F5E2FULL, 
            0xE9391ABDEA59ACF1ULL, 0x5B05FA693D9A594BULL, 0x6ACD100B5CCEC8F6ULL, 0x80F99953232090C5ULL
        },
        {
            0x36301D22C16EC1A2ULL, 0x066581CEC79F729DULL, 0xA31CC7FC4D491159ULL, 0x27A64391F862D341ULL, 
            0xCA2DFFFD13F12A57ULL, 0xCCEB8C9E30736DE3ULL, 0x60D62743EFA5668FULL, 0xB085867E74E250AEULL, 
            0xE0FB2D0E9E106CDCULL, 0x54DBD3A987EA984EULL, 0xBB2473660C04D922ULL, 0xC1C4E217415DD994ULL, 
            0xC4BE042245C4458EULL, 0x9631D26DF5CEF705ULL, 0x8818F7889ADAA56FULL, 0x34E7E1413AB41B01ULL, 
            0xB1A052FEAC379A7CULL, 0xDE8A038090F92C99ULL, 0x4D1256790C67EEE0ULL, 0x6D53372F56CBCF2DULL, 
            0x48272611E4961F2AULL, 0xCE61C1EA75F81A4CULL, 0x204BFD7809CA5EDFULL, 0x9FE5BBB56C04D8CBULL, 
            0x176A625A7989ED03ULL, 0xD3CAC22C501BD636ULL, 0x4D00227AC0B77FDBULL, 0x8A974BE9AD997322ULL, 
            0xBBDF5286A5CA3D08ULL, 0xD0A7322ECB2F399DULL, 0x761B94AF02A299A4ULL, 0x650BC8450D82DC9AULL
        },
        {
            0x87A02A019F28B188ULL, 0x07F9DFC9E05F4A07ULL, 0xF9C6985638BE685EULL, 0x0E7804B27773C470ULL, 
            0xAD86A90E7D2C0D24ULL, 0x54782B99F38AD94CULL, 0xAF6B89552786B9AAULL, 0xD3F6E16C32F5D3D7ULL, 
            0x299B93E7CCF1C0F0ULL, 0xFAE80363FE675371ULL, 0x8A66A0AFAF5B8D8CULL, 0xCA060EDEF92BFF16ULL, 
            0x2F2FF05B59C9D0AEULL, 0xB9614438312DC069ULL, 0x77EB64CFBBD9BBC6ULL, 0xB8793BA5AD05B092ULL, 
            0x68A58389E3794EE7ULL, 0x055A248CA83064FDULL, 0xF5ECA03AA6A15F97ULL, 0x2E78D4C001C97A4EULL, 
            0x96D9CD28C8FCF42DULL, 0x2AF64096FAA5C9B6ULL, 0xB37E8311E8AB8D09ULL, 0x52495087C73CE35BULL, 
            0x66CB130F0BEFBA71ULL, 0xF028FB5268489794ULL, 0x24E4E8118D4DDD48ULL, 0xBA7FA2DE69C1EC8BULL, 
            0xD329945257147006ULL, 0xB09A1BD872E81934ULL, 0x5771EC9A7B2E0C71ULL, 0xB2278EF3B4ABC7E8ULL
        },
        {
            0xD3FC52B8D61C3C49ULL, 0x847FD9E46FC61956ULL, 0x1C2FE9ED078D50E7ULL, 0xABDF7D3C2790E507ULL, 
            0x7C6851B0C886393CULL, 0x0D6A2CF64F67C8B3ULL, 0xAC92835B968CC4F5ULL, 0x95585DB699AE35A9ULL, 
            0xA6E9F5BCF7150F6BULL, 0x15B376412EF999C1ULL, 0xDEEE0B464543F95CULL, 0x2E33AF8FB2F98ACFULL, 
            0xBFEF33FA8E296FBEULL, 0xF718FB378FED9687ULL, 0x950431C3A0D38619ULL, 0x9B1C0BE35DC31660ULL, 
            0xA1C71E15C99C2371ULL, 0xD668452F9FA99646ULL, 0x102D3913857F5483ULL, 0xDEFD0CFD2CC75ECAULL, 
            0x29C3A78A2F3B0115ULL, 0x64C3498F72DD801AULL, 0x3F6194194E3FA831ULL, 0x6B39DD73DDB1793FULL, 
            0xA9C7C18701EB824AULL, 0xE52230E1F51B73F1ULL, 0x0D4F7F2954EE5C40ULL, 0x0763D36037169A5BULL, 
            0xD4BEE561E7C25F07ULL, 0x867C6226BE666A92ULL, 0xB7C193E8F8EB4A0FULL, 0xED9EDEB4D84EBCD3ULL
        },
        {
            0xCB6F578EBCDFBD02ULL, 0x50E36D5CC38B776EULL, 0x189F99F8AB05B009ULL, 0x050DBC8D1670FE43ULL, 
            0xF120FAC295749605ULL, 0x4A665841DC08B5C8ULL, 0x60FE6DB6B8F2D5A5ULL, 0xF4A94F84D24197F1ULL, 
            0xFF0B5D90D04F22FEULL, 0xA493D59A8A0149DEULL, 0xCBCD347A072ADEF3ULL, 0x1602DDA631526006ULL, 
            0x90E42AEEB5D3FCE0ULL, 0x66D2AB61BD9E17E8ULL, 0x437B5C7CF78C7C62ULL, 0x7A2E44E04CC8A968ULL, 
            0xA2F356FE9E61852DULL, 0x98EB799488B09A5FULL, 0xF07DF22D472DD5E8ULL, 0x8C097A149A6E2AC5ULL, 
            0x6E4D943640E8E7B6ULL, 0x506B24F4E612F4A6ULL, 0x898ADD51A256DA76ULL, 0x77F58DEAB40ED346ULL, 
            0xBCD05729E21CF5E3ULL, 0x576C55ACBCB04BC7ULL, 0x76EF616865456A31ULL, 0x26EEB3EF0AA0B5B3ULL, 
            0x029A523D393E9F31ULL, 0xC0FC824812C13BB4ULL, 0x2B04DA710063F387ULL, 0xF59FED4FD7BEE9E8ULL
        }
    },
    {
        {
            0x849EA5D49D55414FULL, 0x99D7AC0B693934E4ULL, 0xC05F2EBA1F54CB22ULL, 0x79C79788E6662421ULL, 
            0xA0CAB78234EA31F0ULL, 0x1B351B2B8F9D0786ULL, 0xF51E46A94801299FULL, 0x7018D7ED9604DBC8ULL, 
            0x0FFF92B1F5245ABFULL, 0x1CA71A334C902AF8ULL, 0x2AD58F45B67AAE07ULL, 0x2ECB2CC2C035C742ULL, 
            0xC4C69D6A39CA95A6ULL, 0x0B590CBBF47D6D4AULL, 0xC27AE6708071B18EULL, 0x64ADC485EDB2B2BEULL, 
            0x8435065E5CDB9AF0ULL, 0x66A79C2BD52B7551ULL, 0xBEE6D0B4906BA8A2ULL, 0x6BE3BFB25F2FDFDBULL, 
            0xA876EB73D7D0BB41ULL, 0x000090DBEA42AF46ULL, 0xAE70314AC427353CULL, 0x738B9D6799FF5245ULL, 
            0x2C9E23BA8773821EULL, 0xB1CCD05D87B290C9ULL, 0x77CA0FD33D93676FULL, 0x81EE5E0FC4B9B685ULL, 
            0x1371B5260570513AULL, 0x49E551B8BC64E265ULL, 0x1004308A7A61D307ULL, 0x074910F7CDE57A39ULL
        },
        {
            0xD29FEA0396F37F6EULL, 0xDB78E44B870EDB8CULL, 0x7A2BF3B31A2550E5ULL, 0x47B10C53E3D29D9AULL, 
            0xB8BC5A17F206E5CCULL, 0x2D24438F0A976685ULL, 0x6C059DEA69ECE194ULL, 0x768E725023685438ULL, 
            0xA19D6F2D56310083ULL, 0x38BBA1065CEB63BDULL, 0x7CEA18815B62E5A2ULL, 0xB1A7270518763BC6ULL, 
            0xBC9EAC116DA64F2CULL, 0x735C19E72C52C790ULL, 0x43268E4FCD9AA0ADULL, 0x451CBFBFEC64868FULL, 
            0x5CEF113DCD35E018ULL, 0x1271CC638EA618F9ULL, 0xA83DB4EC33AD13C2ULL, 0x89412083573067E9ULL, 
            0xC7B5B044CBAAB33EULL, 0x1DC6615743482CAEULL, 0xAD7F5A72F1419EF2ULL, 0xEAFADDB8897450E5ULL, 
            0x8BE3782467BBC6DAULL, 0x4B32FB45020D6F5FULL, 0x1542874945234DCFULL, 0xB500F8801C1BE098ULL, 
            0x3102D6481377C5F8ULL, 0x12FA5A25EC4ACA4EULL, 0x1516A413396C9015ULL, 0x2AA97CC9107735B9ULL
        },
        {
            0x4FAE7FA678A0A4FEULL, 0x2D70E7121A47DBA4ULL, 0x1CCD7A7C5D259BFFULL, 0xDA56C88A631997ABULL, 
            0xE9633B3D43D1E624ULL, 0x6512197A5E210C35ULL, 0x3DEDFBEAF774344EULL, 0x3DFF65585FEC807DULL, 
            0xCD9655029C78A262ULL, 0xD02056A2182A4C71ULL, 0x44FE193A4F3BCE2FULL, 0xFC81608BD3B572B2ULL, 
            0x376382A91E54D54AULL, 0x66812046CE9481B4ULL, 0x58D7E92D0DDAB2D8ULL, 0x2AE1E39942DBCF05ULL, 
            0x8D0F99B2C0BB4F22ULL, 0x43EB991F9F3C4DB5ULL, 0x8F71E8CEBCC44740ULL, 0x7D2D2F6760AB76D2ULL, 
            0xF72F2EE3112E5BE1ULL, 0xABFB4E018C8A4D4EULL, 0xDF3A2903250C16BAULL, 0x31D7F58D453EA869ULL, 
            0xB56447AF7FDE9E9FULL, 0x315F17F559E9EDE9ULL, 0x292A4FF024D873AEULL, 0xFD641C1031D7463DULL, 
            0x1A44920AB1693B7AULL, 0x337B44AEF273663DULL, 0x64FF78B726B444D1ULL, 0x98CE7865368AFFC9ULL
        },
        {
            0x820C95229B825C0EULL, 0x1C59B46C9B378144ULL, 0x4E1283185221637CULL, 0xFC388ED39C60D616ULL, 
            0x9964C81E496E4853ULL, 0x021B77045A7BE941ULL, 0x175ED757513A3AC0ULL, 0x30F23A3B2E9BEEA7ULL, 
            0x8816FA50BBD63D69ULL, 0x89CA16A35F5C548CULL, 0xBA630A5ED6AF6F10ULL, 0x8E25F0C2C135B484ULL, 
            0x8969540EBB3B2BC5ULL, 0x8EA0F3B2090A9747ULL, 0x9EFF55E15B581125ULL, 0x15345A38E937A80AULL, 
            0x9D3BB2B605D1EF37ULL, 0x9DBED9F471DD51B1ULL, 0xC31F1EE98D04A5EBULL, 0xA246AD3CE67409C3ULL, 
            0x9E2DDBDDA4028A16ULL, 0x03B357CF789535B7ULL, 0x536AD39A3DCB44CFULL, 0x425E4A231783DE5BULL, 
            0xF97DAE2E7B3E0086ULL, 0xFEFA52315BFDC1CDULL, 0xE7AB95AD0ADFFE8DULL, 0x7BC4AF0519334549ULL, 
            0xA0A1CD0B5198DDD0ULL, 0xF557F21A454A204DULL, 0xBD963792C95E2F6FULL, 0x7A9BEEE039E9DED4ULL
        },
        {
            0x2DF7A3B1FAF095DCULL, 0xE344186BBEE62310ULL, 0x14BEB4165CEF8ED4ULL, 0x04F952915831643DULL, 
            0xB822D1CD84F05D43ULL, 0x25A3527145C44BCFULL, 0x116920751FD8C256ULL, 0xDA9241E92A16ADD1ULL, 
            0x04BE110E96F6DD29ULL, 0xF31DD2722C9099E2ULL, 0xBF9931E33F2F0EB1ULL, 0x84166550FDDA3219ULL, 
            0xFECADC771DE4C140ULL, 0xA80C15A8B5F15C19ULL, 0xD7EF274E7A1530D7ULL, 0xA5A0ED238EF93C51ULL, 
            0x2745D33309695CE9ULL, 0x85DF30A3EB5DE25DULL, 0xF1F5B65EBBFB588DULL, 0x5F98E09C367DECB7ULL, 
            0xA7B1624A58AE6620ULL, 0x220A7BCBBDA74802ULL, 0x99A056A41C627BC1ULL, 0xEAA8AAC8E5466A13ULL, 
            0xF1CE4971E0CBC247ULL, 0x34BDEF10A6F5B5BAULL, 0x628A34C31534254EULL, 0xB21E0B800B690EA5ULL, 
            0x7D6A4871650577DFULL, 0x5FB71335A555B41DULL, 0xF5701216334C76ACULL, 0x2C62C95464CBD0D4ULL
        },
        {
            0x1D3C940C2A5468B7ULL, 0xA5ED2F8996E7D5DBULL, 0x0CC3B2AD1A7887E4ULL, 0xE3B2A6EF774A9E24ULL, 
            0x1686F627DE88D3F8ULL, 0xFD6203BE8A2E939EULL, 0x9E4F5BBE12D3F7FCULL, 0x92DAE713349F6FB9ULL, 
            0xC076D79B22328EBFULL, 0x2700FBDA6DF00178ULL, 0xC9C8A1C26C3629B4ULL, 0xD8B79D99ED7B1B80ULL, 
            0x72C1DC1BF0580F70ULL, 0x5337EFCCDAEAE582ULL, 0x6513D925F7B81825ULL, 0x7F1809E01346EA99ULL, 
            0x05714C603D43EE5DULL, 0x515324AA758B572DULL, 0xF35D2021103A96D7ULL, 0x22023CC4D90C0A14ULL, 
            0xB77F00E1E3D31822ULL, 0x5682726CE3B822B3ULL, 0x465FC46336291EC0ULL, 0xFF551690DDC1BA68ULL, 
            0x69BE8FEDDB2301F4ULL, 0xC4C1E3E51804BA47ULL, 0xD9F9ABDEC8CDC878ULL, 0x23ECB4DCF7C8E9E6ULL, 
            0x0D0FFB1E6774DB09ULL, 0x49BF2AAEFAE21718ULL, 0xEAA85371A5B4691DULL, 0x468979621D4305C3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseBConstants = {
    0x6353E9762A3502A3ULL,
    0xBF07CABEBC5D760DULL,
    0x82719654EB831D26ULL,
    0x6353E9762A3502A3ULL,
    0xBF07CABEBC5D760DULL,
    0x82719654EB831D26ULL,
    0x5B6ED4D7BBAE12B8ULL,
    0xCEED4414C6A397B6ULL,
    0x23,
    0x55,
    0xE0,
    0x77,
    0xFC,
    0x84,
    0xD2,
    0x7F
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseCSalts = {
    {
        {
            0xBD8605B4842BFD1AULL, 0x0BD716A4F76E5AEAULL, 0xB475FC3715EBA9C2ULL, 0x03A85B1F5191FD67ULL, 
            0x43EF0B7F3E69A024ULL, 0x68A6EF35552BB6FEULL, 0xFA7DAD85A7C7D574ULL, 0x304A69E041DEC172ULL, 
            0xFB5597E13211EB4DULL, 0x463FC20C8E0D4BF7ULL, 0x69DF5C82B2B1E6B3ULL, 0x64C44505F1477D32ULL, 
            0x5CB9428776BEF2B3ULL, 0x8C4FAF11C141B007ULL, 0xEE9399CBDFA72149ULL, 0xF3027C682614B5F1ULL, 
            0xE4756CCAEB4A8D09ULL, 0x505039E8DCC9830FULL, 0x6F402CBA2B77A673ULL, 0x1CE8D1CC35209092ULL, 
            0x6A007E51DB8E8354ULL, 0x3A0C92FE93828CD7ULL, 0x50FCF7CDDC3BDEB9ULL, 0x4760E04B466DBA1EULL, 
            0x2D239CE1F3C9F541ULL, 0x53B3338B06581C38ULL, 0x50A87E08C1D532F0ULL, 0x8DF60FE99DFC27AEULL, 
            0x54B6E73EE61DE618ULL, 0xF0ECC6658EE8A141ULL, 0xF9CA32B1BD7E10D7ULL, 0x20975D5718DFEB8EULL
        },
        {
            0x3A081799BCD7CAF1ULL, 0x8E0CBD9BF1D9D7F0ULL, 0x5A588D3DF835405EULL, 0x133848BB2EDD609FULL, 
            0xC5236F445E7D6566ULL, 0x3BC0343F7D02BFD1ULL, 0xE6CDE8E0F0F20E80ULL, 0x223968B79E7B081FULL, 
            0xFF25CBFA3C4AA6BBULL, 0x1899B870AC88D99BULL, 0xF022BCA3D6D7222DULL, 0xF8A4B89C08EBC615ULL, 
            0x0708DEB266AD2FDDULL, 0x0EF6F37084545947ULL, 0xFA2AD7B4DC7A780BULL, 0x180FA1C66C74191AULL, 
            0x4D6270981918FC4CULL, 0xB896017EB0DA008EULL, 0x5F5750E18B1475ABULL, 0xE154C0145709B095ULL, 
            0xB504BAF13E2606DBULL, 0x171325A5D93B8DAEULL, 0xF604C74D5A17A32FULL, 0x8108F36CFE2E59C4ULL, 
            0xEE1550D14E383825ULL, 0xF8CF6351383DBAF8ULL, 0x102C26F7E9E41131ULL, 0x953774A856308235ULL, 
            0x31650928F0784254ULL, 0xA8D5877EF8755142ULL, 0x5567F8D306457C47ULL, 0xEEA123689441529BULL
        },
        {
            0xCD36823FB0D29155ULL, 0xA6A1907C3701DA42ULL, 0xD31609E2E620FBA2ULL, 0xB07BBB3AC4FFE6CDULL, 
            0xFD954658E9FB12A1ULL, 0x39F3C8B63F35FE10ULL, 0xBC46906DB661C4EFULL, 0xFCFA08EDDBC82BA5ULL, 
            0x026CF0AC34204E94ULL, 0x81EABEDF1E3E7DB8ULL, 0xDD07CAE0DD4A4944ULL, 0xFBCB38B0B5403586ULL, 
            0x552A018AF91F2B81ULL, 0xE1DDF62142E59219ULL, 0x9ECA9E5CA0AC67D1ULL, 0xB9AD338CDD732395ULL, 
            0x49F2DBBB20E5E74FULL, 0x827B3CCB6F3E64B1ULL, 0x8DDF98D7FA2DE8A9ULL, 0x6EBDD9E75E3FBDE1ULL, 
            0xEA1743C68E80FA82ULL, 0x41EC29AB48C98F37ULL, 0x1BCE0FEE1B5FF3EBULL, 0xA29A5318005EB206ULL, 
            0xBAFCFBA05AE1278EULL, 0xD7CC0749CD60A519ULL, 0x91E578D276D85F3DULL, 0x6F51615F3B3B0AA5ULL, 
            0xDE051362C7CB992AULL, 0xB9F46AA7AEDA2195ULL, 0x573B10E5824D717DULL, 0x81D4F5B6CFF357F2ULL
        },
        {
            0x3317C35F7E8C982AULL, 0x6ADA624272C5BC84ULL, 0xBA85EFF6146207A4ULL, 0xF30319E550CE658DULL, 
            0xDB44F9D352D0095EULL, 0x986A8C58A6317000ULL, 0x3F86E42086BCBF8AULL, 0x29D49A4D96AF1453ULL, 
            0x0DCED11DC62EE8BEULL, 0xA428BB4217C9F714ULL, 0x7AF185700536B477ULL, 0x69D083C90E8B9A9DULL, 
            0xDBD8970F26F6B77DULL, 0x176F15A09BEACBA4ULL, 0x9EEC6F9095E08686ULL, 0x147FE3C9383498A5ULL, 
            0xCC13CA09712D2A92ULL, 0xF5FB5A9292509B14ULL, 0x432A50A00BD45C2EULL, 0xBD82C356F1B567DBULL, 
            0x2042892CCF4FC95AULL, 0x989427B3E6F3DDE0ULL, 0xE0497715854F460BULL, 0x24F70BC22141B74CULL, 
            0x7D0C0FB835758B2DULL, 0x13709CA579210884ULL, 0xD6FD4F169ACB7C7EULL, 0xF10120E8A162736DULL, 
            0x2940517512BBBAE4ULL, 0xC4BDEA5F115C3A05ULL, 0x53D8C03950D1CA83ULL, 0x6C18DB14AD469D11ULL
        },
        {
            0x31FA5F1DC3096AADULL, 0x66DC7FAC011C66DDULL, 0x90CB32BD40BB603CULL, 0x760152C7F1DFB008ULL, 
            0x552FF74DD8EB15E7ULL, 0x4F57FE4EDB6A06A3ULL, 0x1B43FAB473590B80ULL, 0x9F92052926E00BD3ULL, 
            0xEBB9A8F675901549ULL, 0x15C6E96763D0F7E0ULL, 0xF6865A65647714FBULL, 0x9EC3E44E034A8D7DULL, 
            0xB42917BD9C1AD0A0ULL, 0x4F97B5E0130ED8BCULL, 0x9F53755CF7C2BB6CULL, 0x2D2E85602C34C531ULL, 
            0x8A3D541B5BE0F59AULL, 0x60E2366E9F4AC27DULL, 0x8558D37AEDBF6A27ULL, 0xD33ED9C0F8019C71ULL, 
            0x9B2618EF86AFD739ULL, 0x4C19870B41B1D2BEULL, 0x708B6417AB2FAB2DULL, 0x91ABBC32AA442E22ULL, 
            0xB50276784185ACB9ULL, 0xE1676C79D1F1F45FULL, 0x713040D0E1BEAB35ULL, 0x54BB4607A898AA9FULL, 
            0x94AA73E6E8893038ULL, 0x8165AACC1B44820CULL, 0xD4C48CF2FDEEF1F3ULL, 0x17BAC0D71F2A34F3ULL
        },
        {
            0x338803675EF6F774ULL, 0x618397B2383BEC92ULL, 0x7BE98860FA65292BULL, 0xBB29F330E924CA29ULL, 
            0x73B56466D6B84B1CULL, 0x4080AE6B9F9DAE65ULL, 0x31991ECF4DB0A29CULL, 0x8085F1A0C63BE340ULL, 
            0x6A1A4AB6844544DDULL, 0x6FCA13D766A005B9ULL, 0x60CE574D9D2DC254ULL, 0x4B7AC439B56CEF6CULL, 
            0xC939D607075E6DA3ULL, 0x986D672E5AFB397DULL, 0x3A3040618FB1AC0EULL, 0x4CAD34749BB0BC42ULL, 
            0xBBEA69BAE2A72046ULL, 0xFFD8218DEDB13965ULL, 0x13CF508F06D1D97DULL, 0x7E2406E44AB902F2ULL, 
            0xF229197E4C0B99ADULL, 0xCA1C58A2E02E698BULL, 0x289CDD2F13F6BB36ULL, 0x4DA095A3B8B3EA73ULL, 
            0xE8ED044683FEB220ULL, 0xA90E19D5D4C9E17EULL, 0x9482F061CA7DF05EULL, 0xF62EF5D8B80C35BBULL, 
            0xE4E0FF6AD602EE42ULL, 0xAAD9F69BCB554477ULL, 0xEB6CD6E3E36379D2ULL, 0x8E4C1FD3DA448FC0ULL
        }
    },
    {
        {
            0x07D8225C3B3D4AC0ULL, 0x32426F6587F67EABULL, 0xA9C6F3A5649A61C8ULL, 0x497855897F583C08ULL, 
            0x0D13C6D356BA4EC1ULL, 0x664F3B4846175DD3ULL, 0x387312305B49DF68ULL, 0x3EB11C09EB42A381ULL, 
            0x3C2D246D1063CD17ULL, 0xE0D57D7081AAC5B4ULL, 0x474A41ADD4E80F62ULL, 0xF26791FA0C93A7BCULL, 
            0xC68099F93B61AEBFULL, 0x76FB01E2C3432C51ULL, 0x37BA8B886A3CD9B7ULL, 0x3AADA5F4255E0EDBULL, 
            0x548B4F67536124F7ULL, 0x70170742F0F64981ULL, 0x8A7598A029B98F5CULL, 0x5FF710A5305AA99BULL, 
            0x5039EF0828B8F366ULL, 0xC212A1511F881403ULL, 0x544B6C59A557A7ECULL, 0x4C780AC5C782B6EFULL, 
            0x797634F526FC35E5ULL, 0x88C136D35D26CC64ULL, 0xF443C72431D675F0ULL, 0x187C3C2B45A1467EULL, 
            0x19F155F95D50F97EULL, 0x10CC193B19C7289EULL, 0x7622A1A7E42F6025ULL, 0xFE33E9E7901B62EBULL
        },
        {
            0xA75FBFA1522B435FULL, 0x2E0F71F7DB0095FAULL, 0x36DB4AA5BE7A4929ULL, 0x5E13768EE0454D49ULL, 
            0xDA109C8DB29CCCCFULL, 0xBD676A184A4D9EB0ULL, 0x05115515F4BA67E5ULL, 0x4773C39AE2A4BE1CULL, 
            0xCD06D914FEB3740DULL, 0x4830E0FB0E3CCC84ULL, 0x6E1085C17C077D81ULL, 0xD791CC79F7CB18D0ULL, 
            0x6AB3526162EBC470ULL, 0x9E7B5B8D0F134454ULL, 0x43F991B12670DC99ULL, 0x0F04C7CE9B62F376ULL, 
            0x56A711FF8F6ECE07ULL, 0x28387314ACCB25A4ULL, 0x03C7E879879F395EULL, 0xA39DB7976A684E1AULL, 
            0xDDEF7789BB09B4BFULL, 0x8BA2C172D639F4ECULL, 0xB0FDEE9B9F60D8B3ULL, 0xE9E9867E8F0A8252ULL, 
            0xC323A07835D1B665ULL, 0xAA1097F6047B87A1ULL, 0x179325A081D00CB2ULL, 0x9DDCDA481F617318ULL, 
            0x300083307A45EF01ULL, 0xCF58D7467775B193ULL, 0xF778E76EA2F00357ULL, 0x097958AF034FFAB9ULL
        },
        {
            0xCDD61E12E66D9B64ULL, 0xD4AC6B60FA06B2B1ULL, 0x0F57EA126A894C4BULL, 0xBCD639DA0456EDC5ULL, 
            0x5F57B0404A9C3185ULL, 0x44CD053D1DC48776ULL, 0x4118E3F2CD3DAEE6ULL, 0x560CD26A9A5D4863ULL, 
            0x5D79FC1A16D10CC0ULL, 0xCF12A7954118A4C8ULL, 0x335FE90805AF4E0BULL, 0x899CBA2F3879F2C4ULL, 
            0xA3C80C8811773062ULL, 0xB7B162F0BF742CDEULL, 0xD08A59725ECD9306ULL, 0x258F75E1AEE2CFA9ULL, 
            0x534A62ABED842DE3ULL, 0xD6551DBD3046DC76ULL, 0xD0270135FD4927F1ULL, 0xF31305F8DCA74350ULL, 
            0xB8BA51D722AE9ECAULL, 0x60A9D07341A7B5F9ULL, 0xAF125EF4EA926CF7ULL, 0x975D8C9E4A826878ULL, 
            0x58DA10496D452BDCULL, 0x623CFDB8F14104E7ULL, 0x78B70A9207FFDA4DULL, 0xCAB344D382A9D533ULL, 
            0xB4CB174F80DF35FCULL, 0x5A4A8DF5B7A2FE33ULL, 0x522FB263C3897358ULL, 0x91CBE5F3A2D687DCULL
        },
        {
            0xC5EDAEDCA5B4BD4FULL, 0xF94AE9AC220E106CULL, 0xB773EC8FECC3766AULL, 0x7A2C78BE08660898ULL, 
            0x84B77EA0C3A94BD7ULL, 0x75A1B9A1CA312A67ULL, 0xDC151C499C1314C4ULL, 0x6566A072BA16AD81ULL, 
            0x3C09D762413D3A06ULL, 0x5FDC9040AA06AB1AULL, 0x75CC5F68F13BE54BULL, 0xEE3D53D55A99461EULL, 
            0x3F10A50AAC700C20ULL, 0x17BEE6868A410731ULL, 0x537CFC265FC03A06ULL, 0x2C6B1094FAD973B5ULL, 
            0x5C53586C5DEFD474ULL, 0xFE8B9E3DC77AD511ULL, 0x76512BCA9DF9DB2EULL, 0x2D40C83FB05FAA51ULL, 
            0xFDFC78C6F70942ADULL, 0x3D23EF36B90E1614ULL, 0x886523F8A3EC3713ULL, 0xAB27F3271FDC368BULL, 
            0x0FCE5B402140B418ULL, 0xEFD4E164D1415457ULL, 0xD1CD86647965DAD9ULL, 0xCDB5CA27A365F4EAULL, 
            0x7BCD2214C77083F9ULL, 0x228A59AEEA9B97DBULL, 0x63FE979FA5D7EF1AULL, 0xE038E793F99DDFADULL
        },
        {
            0xD55DDCA6343028A9ULL, 0x25825668A4E030BBULL, 0x2F02F8E3753A6168ULL, 0x81A8C0F37D5044A9ULL, 
            0x2E1841FED08C98EBULL, 0x768D3C2747F45B14ULL, 0x1D0455676656DBB4ULL, 0xE904FBC1294FDC0EULL, 
            0xA73038AE78013289ULL, 0x9FF14D4F02BC9937ULL, 0x6550DC3E0C8A9FBBULL, 0xAE493BFB35806E11ULL, 
            0x4C2A537DC4A91E5FULL, 0xF4CEE2FC1859A024ULL, 0xDE0171226EE39ED1ULL, 0xA5264110F1A9C7C2ULL, 
            0x7716D06865EBD725ULL, 0xC14F2785BC2036D1ULL, 0xB32BE7A0E9B15020ULL, 0x3D334FAB89C11D17ULL, 
            0x9BE0AB9E9803DFC8ULL, 0x6A582B805FC6818CULL, 0xE4593E61C185EB77ULL, 0x18174A2F481733EFULL, 
            0x6F115F229DCAE6A7ULL, 0xADA9DA955DABEA7DULL, 0x38DEFD99D1F2F44BULL, 0xD730461A7A992349ULL, 
            0x0FA1846E668172A3ULL, 0x3D7ED66BF2C91A3DULL, 0x62D2C74F0B6CDA89ULL, 0x288EE171571AC346ULL
        },
        {
            0x8E46C80C6A37A453ULL, 0x64C28D63EE0F05CAULL, 0xDE72E7B1D2533401ULL, 0x11B89F384C2E58DDULL, 
            0x704B7EEDD4EF98DFULL, 0x1DC175C6A8347BE4ULL, 0x28942C3F017C36A3ULL, 0xA8DA94CDE1D236B1ULL, 
            0x980771D37C32CA35ULL, 0xBE91382646EB8447ULL, 0xB888205B8485B670ULL, 0x9DAD963EE62F3648ULL, 
            0x4836C1CADC466B3FULL, 0x61993CB30D929F02ULL, 0xB67FE4C51166407FULL, 0x032A56ACFF8E2A20ULL, 
            0x3FBD3E39D30250CBULL, 0x85C62A525B8F3005ULL, 0x47F1FA68C1764818ULL, 0xAD83AC5E85B60DE4ULL, 
            0x2850542E7469B612ULL, 0x0DD3DF6C9C6C23FCULL, 0x150E1A3AC6D4337EULL, 0xD5C4055E611BB666ULL, 
            0x635A81E9FAAF2FECULL, 0xD489FC7D193D7257ULL, 0xC53D0EB47429E57AULL, 0x9AC6B0C09D1B4281ULL, 
            0x700349FE7622507DULL, 0x4C4E2C9C0EE407BBULL, 0xEC9981F2C7C9641BULL, 0x44D3538AD99077C5ULL
        }
    },
    {
        {
            0x53D9FA48621B3827ULL, 0x2F5DE5EFED65C303ULL, 0x7C6E391E6E30539FULL, 0x91B3132BCA408D3EULL, 
            0xB84088253952B5ABULL, 0xD9FBFD91DF2B8341ULL, 0xC0454DC31B01112EULL, 0xB68220314229E467ULL, 
            0xB05E3CF50626EF78ULL, 0x85E4115A12A0BAB5ULL, 0x022E98B94C91AD3EULL, 0x40B07E211ECF0E21ULL, 
            0x67C810B8858D2570ULL, 0x1CA791486F6F5623ULL, 0x0E1D696017FD9F3FULL, 0xF839DAA7F3281EC0ULL, 
            0x1D45C399ADA7FB21ULL, 0x6F9B82784BE5B77EULL, 0x5717E52B53EA2DD0ULL, 0x8B4B262217F5FEB7ULL, 
            0x4392014AE959B9E1ULL, 0xD681D19DADF9AA25ULL, 0x5382C48B7B08EFF6ULL, 0xF707B2CD28D12463ULL, 
            0x5468B1A5A0C1AD76ULL, 0xA08BABB9B751CEECULL, 0x9986AF5C291114B1ULL, 0x0CE730C1C82CB5B3ULL, 
            0xFE4DAA330056A632ULL, 0x789138841D49C5CAULL, 0x02A5D2886CC93D92ULL, 0xAB0E27E4B75946ADULL
        },
        {
            0x11E2BE7FE381DA2FULL, 0xC7C1F6E361D9AFEEULL, 0x28ACFDFCD9A00CA3ULL, 0x33492B91251317E5ULL, 
            0xA45BA01E8249EE9BULL, 0xD4F7C1CE7AF2145CULL, 0x0366C0F7511902FEULL, 0x356017755E04F22DULL, 
            0x47A454E3B0FFCEA9ULL, 0x1C944A7F50A8C99AULL, 0x1DA9FBFD1BA19E3FULL, 0x149B85E9531159AEULL, 
            0x21C664A8ADAECFCCULL, 0xE49E8E17AC86DD31ULL, 0xF46EBE5BDFF2776FULL, 0x79BBDBEEB7BE8220ULL, 
            0x891C7273290359F0ULL, 0xF0044158FDB36E02ULL, 0xF73D9AEEE686FD66ULL, 0xDC8FAADED9EEBA0EULL, 
            0xF9124F8389132775ULL, 0x7EA32DD753B0E8CFULL, 0x3BECF5818A0B86DCULL, 0x37227CE0D0871A06ULL, 
            0xFE1127D2C5950773ULL, 0xDF91663F16EF004EULL, 0xE6F5845D6A000CBDULL, 0xEDFE48D2D1E3E3C0ULL, 
            0x00C1C0F63F4BEAE7ULL, 0x9D9A0C47BF30AF70ULL, 0xF16402D41F06664EULL, 0x51FC9582A5BE068BULL
        },
        {
            0xAB7ABC79943A2505ULL, 0x777149BAEDA56701ULL, 0x0756287D61084FC9ULL, 0x044A0593F4BC2419ULL, 
            0x26B02FE1AE6BA9EDULL, 0x97BE178F09BD206FULL, 0x2E9D740DE7554A15ULL, 0x8E932CDFD1EFEB2DULL, 
            0x2FE815B2B91586BCULL, 0x74F450FF86FAEE6CULL, 0x67F23614E660EAFFULL, 0x34A1B0767346ACB5ULL, 
            0x1DC14D0185E31CA0ULL, 0x898C28D7BFD9AA96ULL, 0x3E51743D7F27A064ULL, 0xDFAB2CF541DD5B2BULL, 
            0xC03635018C0DACE2ULL, 0x98DFBF194BAAEBFCULL, 0xDB6523D246EACE65ULL, 0x509F9631A8D7F956ULL, 
            0x25D4BCA82BC1C44CULL, 0x87043785EA662E8AULL, 0x2D22AA80469A75FDULL, 0x158352B922C58DB7ULL, 
            0x9D6DE5AB17931C23ULL, 0xF1651EE3514E9CF9ULL, 0xEB03ADE1399925C2ULL, 0x526902F6FD29CF80ULL, 
            0x99E7737B97600FE5ULL, 0x8B9582EF5D319C60ULL, 0x24B03C5036ECA745ULL, 0x93547872C1C83437ULL
        },
        {
            0x32F991C5A65F620EULL, 0xB8574EEF1DAB7E16ULL, 0x86D33877D80CE3D4ULL, 0x8BE2F6B2DCFCDEA5ULL, 
            0x50231CF5D342AF13ULL, 0xD8372BD501B64E72ULL, 0x8B6F60388B91D7C3ULL, 0xA5C704A9D66AAA12ULL, 
            0xE8CD759753B72892ULL, 0x939F06D4770015C6ULL, 0x7150D1AFAB60FC59ULL, 0x3EF1D7E28C52FE37ULL, 
            0x7685FA75C32CCD16ULL, 0x61FA85D4D6F50DDBULL, 0xC86D8A42F91F8503ULL, 0x7C1830DEEFEA3A47ULL, 
            0x4F5C5B819D6D4E48ULL, 0x940E422D7CDF834AULL, 0xF6BD6DC0E21C03DDULL, 0x2F25D309CF64D9CBULL, 
            0xDB1B2E4D691BC321ULL, 0xC3236692D8CF9ADCULL, 0xC71332F2D4820430ULL, 0x5F75E9A7668648D2ULL, 
            0xA58A29867B1D206EULL, 0x4C7ED9DDDA7F1B43ULL, 0x8E63141EA66464F4ULL, 0xD7BD53BE359031D5ULL, 
            0xE3C8FF4EF053696DULL, 0x69B75D70DA6E7EC4ULL, 0x7E3C694787A9A480ULL, 0xBCC32FB30FAE3FBAULL
        },
        {
            0x48AACF01DE511A4BULL, 0xE025BF2037BEC8E6ULL, 0x9F9C7B0481D6F27AULL, 0x7CAA71DCD5E2DEA1ULL, 
            0x5471968B6B9F50D7ULL, 0x358497BB7F948384ULL, 0xB87B06023F0A5F72ULL, 0x1E803EF09D656DF3ULL, 
            0x9F0792FEA85B30ACULL, 0xA48A5F8E0FE92780ULL, 0xEC6EF6FC6DA74FECULL, 0xA613058DD35D34EAULL, 
            0x35A157FEDA47F51EULL, 0x926A9D49405F23ABULL, 0x43D10B70ABB520E0ULL, 0xDDAB72FF289FBA15ULL, 
            0x3D3EDC981DEC82E3ULL, 0x1EC8135643979822ULL, 0x32E335E9C4A23499ULL, 0xBDB615E94DCE7430ULL, 
            0x981C6D94439E0E8FULL, 0xB6BC4808678419E2ULL, 0xFD419D7332CB2317ULL, 0xEC98A35E3A3A7DB2ULL, 
            0x64591733D0879B0BULL, 0x93465CBF8C250280ULL, 0x4031E4ED4720F088ULL, 0x35876B81EDB1C1B6ULL, 
            0x3A068A3C02B1BC5CULL, 0x60FBD75B7B8FCAA0ULL, 0x964E0E474A892433ULL, 0x04F0927649AE165DULL
        },
        {
            0x87FBAE20D6F5D327ULL, 0x1B98D0AC56751DF4ULL, 0x4120CF857667A50AULL, 0x26306616E625BB91ULL, 
            0x0CC4EEC867C5AFD1ULL, 0x75497F25D690E830ULL, 0xA6217B6A0046B968ULL, 0x6682C71BB1E68000ULL, 
            0x827EE39F31F639AEULL, 0x8DD98A1C7F7FD069ULL, 0x74775A78FB4AD1B1ULL, 0x46A04B4711C0122DULL, 
            0x6F6C997DDB8DD0E4ULL, 0xB88494DC68C119E6ULL, 0xC2CAA64484425FFDULL, 0xA42EBE44D1249732ULL, 
            0x2B4668E3566A1D59ULL, 0xEAB183AFF7910B3AULL, 0x0E70B4905E24E699ULL, 0xB14F97E5D0E17190ULL, 
            0x0AEC14312250E681ULL, 0xF2B623C9F4D904E5ULL, 0x50325939DAD84924ULL, 0x435AE0E5674ED4E2ULL, 
            0x172CCAF77EA1C07FULL, 0x6FF31D1900A0817BULL, 0x967F5AF1D89C28FCULL, 0xB34C5FCCE9468882ULL, 
            0x3C0A6C53D709A597ULL, 0x0EC0750E26972A62ULL, 0x263413F45995B499ULL, 0xCCF4F2DE18E22BBCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseCConstants = {
    0x6665C6C04E5FC409ULL,
    0x0DD2791CB1D89B10ULL,
    0x71639BC1E003A650ULL,
    0x6665C6C04E5FC409ULL,
    0x0DD2791CB1D89B10ULL,
    0x71639BC1E003A650ULL,
    0x20DDF3D39AD78F86ULL,
    0xA4C6A9E05ECC2A2DULL,
    0xAC,
    0x20,
    0x69,
    0x82,
    0xD6,
    0x90,
    0x4C,
    0x92
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseDSalts = {
    {
        {
            0x9E23936A6F578119ULL, 0x5BEEE7176BD2087AULL, 0x8F86DBA49D060039ULL, 0x9F77FE081D179129ULL, 
            0x971605B1D738DF67ULL, 0xF5CC460CCE2C71E2ULL, 0xD3610A1F8BA62A91ULL, 0xC739F8605F7C18C8ULL, 
            0x232A5E1665765953ULL, 0x98F33A0923999FBEULL, 0x4382AEF52A5AF9C6ULL, 0x78915548B41B5BF3ULL, 
            0x9AAF7A521C786061ULL, 0xC7ECEA1BBD5F0744ULL, 0x799212B9EC2B0A07ULL, 0x5B5DD760BC92D0B5ULL, 
            0xEE64C9FAFDBF94FAULL, 0xFAA67B5CC5676780ULL, 0x3316E96388B677D2ULL, 0x60C2379F06EB1008ULL, 
            0xA3216D3A89528B40ULL, 0x56E7B9AD561EA5B3ULL, 0xA186289E429C8FEEULL, 0x10B9F58596288145ULL, 
            0xD160B275A628684DULL, 0x1BE66BD828C3065BULL, 0x1A482C057B8EFCD2ULL, 0xC87DE2412844C470ULL, 
            0x92DA9E26B3F4CD63ULL, 0x6C54B1EA9353F87EULL, 0x20CCC97D9908FA2CULL, 0xE7594835FCE18A5BULL
        },
        {
            0x7E521F745EC17F1FULL, 0xCF6FB1D8CBA24552ULL, 0x9AC79D33F60D7FD1ULL, 0x55BE38E127C28814ULL, 
            0xB1CBA97E0106B78CULL, 0x9865EC420FD25765ULL, 0x07CA5B9C9B6AD6D1ULL, 0x5D2538778BD025BCULL, 
            0xF0042DE055001509ULL, 0x2014E09DBC6A1421ULL, 0xAB932498CB678978ULL, 0x5172D3D1A7F693A1ULL, 
            0x0D5759DF4CA9D0EBULL, 0x1D290BFD1169EB60ULL, 0xD5582D35DF3D40F9ULL, 0x5A32B38C57412E73ULL, 
            0x3D1652A21F6B15BEULL, 0xCF4C4888913D1060ULL, 0xEF1DAB1D8B0BF2ACULL, 0x7BEB5AEE11BDF378ULL, 
            0x500F38C0231DC17EULL, 0xB0C2D40F0FF4D99DULL, 0xBB1B170F24AE57C7ULL, 0xEB334F8AA11B2146ULL, 
            0x7670FA826295E42FULL, 0xD8C639CB9B75790EULL, 0x1EE9418000C5AB42ULL, 0x03BDEFB3E0734462ULL, 
            0x04DF8740BD1D59D4ULL, 0x329FBB9D19800277ULL, 0x80806027EC200B49ULL, 0x17F429D572A90DD8ULL
        },
        {
            0x0E85C63DBA2944CBULL, 0x0135DCAEA3FB7BFAULL, 0x249FF592AEAAEB00ULL, 0x3C4312B4B9B00C36ULL, 
            0x148795B07564F016ULL, 0x1814F5E2FEBA95A6ULL, 0xB7CB65CA5E8D34C9ULL, 0xB89C9971FC1FBDB3ULL, 
            0xD22DDF63607C6533ULL, 0x98EE794413F1A630ULL, 0xBEB662065214112DULL, 0x71C5F30482519319ULL, 
            0x427ABFBCAAAFFC01ULL, 0x6E823B99E666A081ULL, 0x5F0FCC2CAEDC1059ULL, 0xA5E64E089F0E10FDULL, 
            0x5561B99CDCDF2243ULL, 0x843251741196984AULL, 0xD6A59581BEEEC0EFULL, 0x6B7601AE73C3902CULL, 
            0xAC5CA17B50F97144ULL, 0x94BE0A8D78C4CBEEULL, 0xD205375270B5DA5CULL, 0xA7B2E6DA2574459CULL, 
            0xCC88C84093570324ULL, 0x491957F969107E6FULL, 0xF63D31808E4D2C78ULL, 0xF0BC3B2488769101ULL, 
            0xF211C3821319823BULL, 0xECFC4374825D8AF2ULL, 0x82C9502693AAE84CULL, 0x84BED387CD966C0CULL
        },
        {
            0x04EB4AC9B73985B0ULL, 0x972CF54D43BAACE7ULL, 0x0C0FBD02E06CB03DULL, 0x80857642708490BCULL, 
            0x0A6757037AAE1556ULL, 0xA20AB7581F12927FULL, 0xB67EAD60F92F3EE9ULL, 0xAA052A6AD3134A35ULL, 
            0xE6D0EEC3F7B4B685ULL, 0x5D064C0292365B87ULL, 0x1A00688F6ADECFA7ULL, 0x79EDD5F13073F1E2ULL, 
            0x241793716D1DC63FULL, 0xC1EC6E85CD0B653EULL, 0x3F6C28A99D43A5EDULL, 0x5638963BE88C0706ULL, 
            0x078CAA3864C6BDB8ULL, 0x8649171A47E28C55ULL, 0x33CC729451CA0B9CULL, 0x0AA4523D14C17D76ULL, 
            0xC6E8FA34F3CE13B2ULL, 0x83855102D91116E6ULL, 0xF592B108FB91B0E2ULL, 0xAC41488A5CB6E01AULL, 
            0xFB8B9B1BC2130BCBULL, 0xBD553CBEEEFD2E12ULL, 0x7AC5138F750B6968ULL, 0x1B5B7640E769A490ULL, 
            0x1A9FEE401FDF25F6ULL, 0xCE83BA6811A2B281ULL, 0x952DB8855ABA3C1CULL, 0x99A7E5CA29F40554ULL
        },
        {
            0x3F30B28193318AADULL, 0x799B2967E950E169ULL, 0x6CA240C1EF97A4E7ULL, 0xDC5F97F0D383ABF1ULL, 
            0xB3C470799AB5FE78ULL, 0x170316A3E9829AFCULL, 0x3FCE350F53644D9AULL, 0x56D5115B92AD71AFULL, 
            0xDB151B024A278291ULL, 0x0BF2FE8801BFF6B0ULL, 0xEAA75EB05EF07FE1ULL, 0xC63F1BF98E2D4F54ULL, 
            0xA8F8E84AAF7375C9ULL, 0xC39ABA9CD8024247ULL, 0xE5173BDECB9329ABULL, 0x130111BB48B43C3AULL, 
            0x8711A0E07398AA48ULL, 0xEB774571FD977B4BULL, 0x8B8A08351DCF4BF8ULL, 0x254A44DD37937D71ULL, 
            0x3D521605E4E26D38ULL, 0x5BE7A0C86E21A109ULL, 0x3CE84FB3FBD1A45DULL, 0x4EB2E27C220A4E66ULL, 
            0x7DF5FB267D992C0EULL, 0x9D8A98A03092C9C2ULL, 0x3D66714B3DF20CECULL, 0xA0F36D300574E2EEULL, 
            0xFCF3D98070ED4D2BULL, 0xDC50E6ECC8F3AB06ULL, 0x05A574B379EAADCBULL, 0xB230FE3B16D85D7BULL
        },
        {
            0xA6145CF6721F531BULL, 0x398B0320300FD788ULL, 0x16144445446DDF8BULL, 0xB21B8860A82785FEULL, 
            0x045176347D20DEF5ULL, 0x49E6EBA51F67F39DULL, 0x14E16E684A0FC1BAULL, 0xAC8424ED3685E689ULL, 
            0x6F58E66C441A9D98ULL, 0x6932CD9B67DED69DULL, 0x5E92CD9939F1C1E6ULL, 0x0E37BE541AFCFEBBULL, 
            0xF697D11231883701ULL, 0x7A5BFD98E3FFB55DULL, 0xF8BE47C59903AFCEULL, 0xF5114E1E2DBFA789ULL, 
            0x6EF8890F02FE6D38ULL, 0x006958CA5F97E662ULL, 0x3ED94A9B4B19D3E7ULL, 0x011C5AA6E2BE99DCULL, 
            0x49F5FB62A84144E2ULL, 0x1BF01FCDFE2833BFULL, 0x0D9540AAE34872A0ULL, 0x0B85550F7F409A61ULL, 
            0x19A67A71465300CCULL, 0x2C78FC41CA025714ULL, 0x1963317C34E1B3FBULL, 0xDACF875044E9D4FFULL, 
            0xFF10FFB48E5B1234ULL, 0x3D015FF180476DBFULL, 0x450D3C721CBA7F37ULL, 0xF745725EE82C0A54ULL
        }
    },
    {
        {
            0x4299854CB3431D98ULL, 0xBC2F5CCF9D68D260ULL, 0xCBEC4979BB26CE96ULL, 0x22495069FAB9EDE1ULL, 
            0xDDE86F836399E9D5ULL, 0xABA022E4923E3BE3ULL, 0x08B49E302C82B2D0ULL, 0x663E496A25E74F0DULL, 
            0x4D69E9F022E6B4DDULL, 0x92E3C67FCF582DD1ULL, 0xBE3D3B97E2E89636ULL, 0xA55F57C82D89EBBDULL, 
            0x5A2B96DBA003A7EEULL, 0x6559CC7B44E71115ULL, 0x8682561856EAB35BULL, 0xEEA28C26B16C9438ULL, 
            0x78626D3BB643700CULL, 0xDEE47A14CD73E52FULL, 0xC97BE8A492BE5478ULL, 0x1E1F7B760D759519ULL, 
            0x84F95BAF29F2512BULL, 0x4F683453A65F1422ULL, 0x296A65A191B569D4ULL, 0x45FDA6FE495ACCD1ULL, 
            0xC31B21E590DD7484ULL, 0x89A1C14BFD9371A6ULL, 0xFFC2FDCED4C1E866ULL, 0x35BA6174A778131AULL, 
            0x6296EEAC6972C0E2ULL, 0x979AB5192D2D073EULL, 0x8F96C9E7749F3534ULL, 0x063A1CEC8F477FD3ULL
        },
        {
            0x32292D02204B6083ULL, 0xD4F1CD42C2134B72ULL, 0xC91AF731C11CA779ULL, 0xE8C6F59967153B73ULL, 
            0xCA3AF5DF9F87AEBEULL, 0x53B19252AF76CE0AULL, 0xB6BBB27C465901F0ULL, 0xDF49642A2D501B3DULL, 
            0x2A9ACB4B481BE3D0ULL, 0xA00099A77762C7FDULL, 0x01A01C43EB8DFA10ULL, 0x7B34F5F7A29983F6ULL, 
            0x396F7CA480DDD92FULL, 0x10BE8A9B2FF93D16ULL, 0x678C342DB05F0B73ULL, 0xB8E16D9422564CEBULL, 
            0xD12D9C610662337EULL, 0x2DAFC8C22048F189ULL, 0x628C5260F617AD18ULL, 0x295DC5BEF587DDCAULL, 
            0x8EC0D47CC1086261ULL, 0x9C259725AF88BB53ULL, 0x2D8392581FF1CC94ULL, 0xA904B3245695FB16ULL, 
            0x2E70DF821526F5C0ULL, 0x5B3CF07227BE026AULL, 0x35ECCEB0811BCFE6ULL, 0xE9DD2A41F542C13CULL, 
            0x3A0F410DB95A251AULL, 0xBE2389E756744D80ULL, 0x7BD2A0704EA8BDD2ULL, 0x8E63A6F53B99B6B4ULL
        },
        {
            0xB52D429D09DA253DULL, 0xEC57973920ADA058ULL, 0xE4555DD5C0A6A3BFULL, 0xE09A9EA6F0FE5537ULL, 
            0x4649BDFD225B0E27ULL, 0xBCF564A90317EE7BULL, 0xDD341DBE244FBB30ULL, 0x3C4082099AF3C571ULL, 
            0x09C7472C31836394ULL, 0x41DD8A2BB0911E5FULL, 0xD606A6D8E5AD1074ULL, 0xCBAD8193991FC8B5ULL, 
            0xB0BC4105DC29B40CULL, 0x758BBFDC13742FADULL, 0x43918EFE9A21093EULL, 0xF61A0D787352A0C9ULL, 
            0x00F718F2E5983025ULL, 0xE14562F88C8B04B5ULL, 0xA6183162982FDED8ULL, 0xD814BDFDF28A8A60ULL, 
            0x2AECE84E47742633ULL, 0xD8728548784DEDE3ULL, 0x9EABB2072A6FED60ULL, 0xB1652D6E2EABC6E7ULL, 
            0xFEE35D332EF88D26ULL, 0x77A81A42624A4A5CULL, 0xCEA901F04F6AF1E2ULL, 0xFFEEE7E7B18F4082ULL, 
            0xA8C167CA2CFD65BFULL, 0x7A4A6BD30C3B2CCBULL, 0xFE2F3D2216A78945ULL, 0x5BB2810029D40DEBULL
        },
        {
            0x2F8DBEC309C8E0F0ULL, 0x39373D4FA11688CEULL, 0x68304BD5C43C4F65ULL, 0xF4975D367B4E9CBDULL, 
            0x723F71DEBDB8AA89ULL, 0x4F67945D48EA6E55ULL, 0x27AC7D8D7795F48AULL, 0x6DAC7156D2CC4FD7ULL, 
            0x9C6EC6E16DE6D6EFULL, 0x89E2A8C149B6AA3BULL, 0xF33B0BFC0B13808DULL, 0x7F6608953990BD4FULL, 
            0x35D4D3E0EA10285FULL, 0x3B5D9E4E6FD07721ULL, 0x723A1A3B29EF2553ULL, 0x8916351E75363328ULL, 
            0x16D4D18144CE35CCULL, 0xF051A1B29EC4D1E3ULL, 0xF7D4F2FA58D10507ULL, 0x1C1736A2D58F0E36ULL, 
            0x6E90B021099BAAD6ULL, 0x0A89E52FD842094EULL, 0x6A290E780C0AED87ULL, 0x8BF22E86DC549943ULL, 
            0xA531D62B3041E03CULL, 0x6FCDCDF62D9D5CD1ULL, 0xBF19BE696FD36242ULL, 0x0885E39A0A8A0F56ULL, 
            0xFD338CDA01C6D0CCULL, 0x7ADBAD8342F7E859ULL, 0x1090EB216EB2E6F0ULL, 0x7FA2D440E7B4CF9FULL
        },
        {
            0x4CFA05AD97C3F4C3ULL, 0xA398EC3A7E979CEAULL, 0xAD518AAE80F1824FULL, 0xC0249EABEAD48446ULL, 
            0x65C5A41E541C27ADULL, 0x7C286A29DF66DE6FULL, 0x076596E5EB09F033ULL, 0x9F200F9320D14575ULL, 
            0xF8BD05F720A798BEULL, 0xBF3FD41F1D634317ULL, 0x00465B68979B9380ULL, 0x54F58AAF7DD10D93ULL, 
            0xBD487DDF335D9F40ULL, 0x2F28657D5E5562D0ULL, 0xB59262868EA2A0AAULL, 0x16FA889A0FFCF76CULL, 
            0x446A80BBD301E8A8ULL, 0xE4D7B1959526C61EULL, 0xED86AE242C2FF8AAULL, 0xC83E3840042F4DAEULL, 
            0xBD8591CCF09E6230ULL, 0xC3BEF488E899E18BULL, 0x54B66F60499DD25AULL, 0x1D749F8A2529E8F4ULL, 
            0xF80D3DFCB49B1FA7ULL, 0xE18E397829DE4E3EULL, 0xCA23B1040D9B0FE6ULL, 0x501EDA7E858DAAF6ULL, 
            0x7ABBC7BBA08B171DULL, 0x0F3D457D32EA5385ULL, 0xFB8CBCD3701C3691ULL, 0x0250C745C7929C55ULL
        },
        {
            0x51A1155EFC869D25ULL, 0x12AE21839E5783E7ULL, 0x53677F809C8A780BULL, 0xAE78938962136C91ULL, 
            0xFDE288389FDFE2C0ULL, 0x68DD8FD420C64D05ULL, 0xE470BF722EA637E9ULL, 0x2DE36DA93FFC306FULL, 
            0xA68F767E4BCBAC41ULL, 0xD4882426C054A679ULL, 0x828C980B3CD9A68CULL, 0x9BB1DB74F5C8E0CBULL, 
            0x3EDD072C32017995ULL, 0xE0FF18FAAC8368FCULL, 0xCDA55FF8193FF907ULL, 0x66C729FFA7876FAEULL, 
            0x44603762E4597BDFULL, 0x212F7EDA7F261AFAULL, 0x3F1CFA8BE0B51BD7ULL, 0x00AD0DAC8DF77D77ULL, 
            0xCABC2EBEE12065A1ULL, 0xF9AEDED9211575BFULL, 0xE465C9CA4D24E024ULL, 0x14BB3743B0C75397ULL, 
            0xD356DFA10C12B299ULL, 0x44AE2952F5B2C19EULL, 0x93F83181DF3E0A8DULL, 0xFBCB7897C5CD1900ULL, 
            0x4F889719A28E382CULL, 0xF436E02692213355ULL, 0xAF41C7E6416704F1ULL, 0x159EE79D02742A53ULL
        }
    },
    {
        {
            0x0E4A10C8605AB297ULL, 0xBC51A14170AF151AULL, 0x4CC5CFE1B6BF289BULL, 0x5A32A482499DC4C8ULL, 
            0x063C39BC6FCBA4B1ULL, 0xBEE080013C80FB2AULL, 0x57DD5003C0128C94ULL, 0xC75846E46520B631ULL, 
            0x1937684ED30BC049ULL, 0x2E8164E51C5309A4ULL, 0x90675B3E352D0831ULL, 0x6C4FD541FDF3550EULL, 
            0x71722D3803FFB46DULL, 0x05E43274BBB5DBDBULL, 0xC91697B475EB61D3ULL, 0x40A73CF720A0F6B5ULL, 
            0xA6B434C1D540D4DAULL, 0xF9628710E5C9D856ULL, 0xCB9E3B122D73D4C1ULL, 0x199932C1F1E83493ULL, 
            0x735077CC902657BFULL, 0x3095D246C2E45070ULL, 0xEDC3D8393BE8D7BDULL, 0x5FCC0ABE6B81812AULL, 
            0x8AB4F60E9EF4D4D6ULL, 0x9EC844F7EB095996ULL, 0xCFA4075F8B8C966DULL, 0xD070B7DA96DC21CFULL, 
            0x559538F3044CC3B5ULL, 0xAF3981DDFCDD5631ULL, 0x02328E9F30CD7C2CULL, 0x864053BBDBEDCCF7ULL
        },
        {
            0x9C2E3CDB0102AADAULL, 0x60CE1D022B92D8ACULL, 0x03449703E5C4292AULL, 0x902A717D5920DF9FULL, 
            0x058E27526E816FA4ULL, 0x05214DC4CE005723ULL, 0x14BFA847AE42D699ULL, 0xB2772B2485D30882ULL, 
            0x87DEA1D02312A334ULL, 0xE521239E5AAA45C3ULL, 0x2717786749EBE9DAULL, 0x9A53208BBCE38A8CULL, 
            0x52FB14E96C9B75C1ULL, 0x77AE20C3E35B87E8ULL, 0xD5D93C20EE101585ULL, 0xC283798D885E0200ULL, 
            0xE7610FBC994B3244ULL, 0x454EA407225AAAF1ULL, 0x9313DCDB87A3EBB1ULL, 0x6EC7FCA7AC0C7EDAULL, 
            0x5C12009A91896474ULL, 0x2E14AFC1BA78F6EEULL, 0x8A047C4225506DBAULL, 0x274520365BB1F4EAULL, 
            0xDD00B48FC04D85C1ULL, 0xC73DA8DA5C1D185CULL, 0x277B091CBE376D1DULL, 0xA89BB0C5FA112833ULL, 
            0x3D43AA7DD53B0A35ULL, 0x01E568E476182CA4ULL, 0x1A8DAA8AD68213D5ULL, 0x9B40C50B82FDD2E4ULL
        },
        {
            0x23838F4C98974DE1ULL, 0x4C8E7951043D004AULL, 0x3062590D8A7F5008ULL, 0x295E6FB19B0AFEF5ULL, 
            0x21FEFEF55364F345ULL, 0x5F4F8F7DD7BBF0AAULL, 0x2798AE41DB942AF3ULL, 0x3742F69FE9E76FA8ULL, 
            0x51FFBC3C1661A78AULL, 0x0811630DD1E03497ULL, 0x6A0B79F145070789ULL, 0xAA4B9792A9B5DE31ULL, 
            0x92E83886500033DEULL, 0xA3AFBA8A73BC4679ULL, 0xD9BFFDABD9AF28F2ULL, 0x923AD20DF9119844ULL, 
            0x85C67ED3DD024CBDULL, 0xEF806DD8D9A223C1ULL, 0xAD0D89BEAF33A07AULL, 0xC1CCA7AA265F1874ULL, 
            0x8863CAAC61E178BBULL, 0x77C9DE48F4B3A97AULL, 0x06EAE3177A1203B2ULL, 0x2CD151B1D07D85C5ULL, 
            0xE66E37792A4ACB97ULL, 0x351C4A0E90235DB8ULL, 0x8CF262FF2BFF45B8ULL, 0x7B3066A8E794B5F7ULL, 
            0xFA45BD47B017F892ULL, 0x15A972EEF0545DBAULL, 0x58C3F264D6F89F6FULL, 0x2ABA8CD0A8F8ED19ULL
        },
        {
            0xA35ED021452A5A9BULL, 0xA6CE7690B8C3532FULL, 0xB33DBA3566177C1FULL, 0x8AFECC2350DF3854ULL, 
            0x60B00663DC038201ULL, 0xD14B54B71BE28370ULL, 0xAB5DC1520065D228ULL, 0x0F57669D3D989814ULL, 
            0x6141D7E7C17687FEULL, 0xE2EEF7AB524E5556ULL, 0x1CA5A32C47BE52DCULL, 0x837440FF12FCFAC1ULL, 
            0x94047C3A46EEA1EBULL, 0xBC086111DB6528AFULL, 0x951988BE4F35F92AULL, 0x5446D07DED7BAB64ULL, 
            0xB23BCC67E8EE6214ULL, 0x627203F69A7ACC11ULL, 0x504EFD3DE07399A6ULL, 0x03ACA427FDD2B83CULL, 
            0x37E1EA4E77C0030FULL, 0xF3E593FB9333889DULL, 0x3BB19711F9FAC9ADULL, 0x9E914B1092077B1BULL, 
            0xEFD87D32C7D015B0ULL, 0x322C1D2F85201103ULL, 0x77E2EC4255D882DDULL, 0x43491FBB7AA611D7ULL, 
            0xAA6F4774EEB70D8DULL, 0xFE35E898E98A6DEEULL, 0x677CC49F68F03D5AULL, 0xCE55E6D780A3C59BULL
        },
        {
            0x779C71E96045D2FDULL, 0xE28DCCED5BDEF2C8ULL, 0xA988911A2A92E507ULL, 0x75B0860779D5CF82ULL, 
            0x2651605453CA7BA4ULL, 0xF2FC9BBE0D925833ULL, 0x37BA3BA571741E52ULL, 0xC24F6937A67AC498ULL, 
            0xF1429A15E17EC5C1ULL, 0x645CEE0BC8530143ULL, 0x6F03B0CBAD8542C1ULL, 0x521530E2363BA653ULL, 
            0x2A4409DD75B5F888ULL, 0x3D1534B197D291DBULL, 0xDB80A1C5032F9F97ULL, 0xC9404D52E05206E0ULL, 
            0xA124ADD074F78954ULL, 0x0B301568B8C59042ULL, 0x8E1BDE87AA422542ULL, 0x2BA3D11DBC923366ULL, 
            0x0308DC1157B648C3ULL, 0x8B33C94BEC5D863DULL, 0xA57000901DC5718CULL, 0x9F32480280D550A6ULL, 
            0x41DA4281F37C3B45ULL, 0x7B672AC3E0F821DEULL, 0x556B44D7E71D172CULL, 0x5DFCFA55D5F30363ULL, 
            0xEBB95FD574617540ULL, 0x318A4874D3E30D25ULL, 0xAD958260FB5D3BF4ULL, 0x67D5D10F2E395E97ULL
        },
        {
            0xF20782B90E729B6DULL, 0xA40AFEB1A413644BULL, 0xAA192DDAC1CDFC8CULL, 0xE1E6F2E79DACA2A8ULL, 
            0xDD99E0A8AF021064ULL, 0x01968D104F7BC560ULL, 0x2D4D84583BB52077ULL, 0x583193C77203C8AEULL, 
            0x5969FB8536B1D70BULL, 0x0A556CC158009390ULL, 0x816B390458CC102EULL, 0xF4BA708FB53AB775ULL, 
            0x2EB2C80A371B3EE0ULL, 0x26C58EA500D25477ULL, 0x363E9661AD32F158ULL, 0x8166D062702A947CULL, 
            0x68975F20FD8BA040ULL, 0x30AFAB684E019DFAULL, 0xCE17F365BB07B1FAULL, 0x02E12F2D0D5B478FULL, 
            0xE5812683AA89072EULL, 0x989BCD8514FCD542ULL, 0x1FB8A764E9C03479ULL, 0x7ABD659579744802ULL, 
            0x32B082114BE11343ULL, 0xC7F1BD075E1FEF76ULL, 0xB7BEE593281AA2DAULL, 0xF6F80EA0442B76E2ULL, 
            0x053279721F8131BBULL, 0x640C5D8FB1A919D1ULL, 0x1879B5EA6E570D0AULL, 0xD610685D6C3B5EACULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseDConstants = {
    0xEB01D8E2F6F49559ULL,
    0x7CEFAB892E951898ULL,
    0x3DCE956780E055C3ULL,
    0xEB01D8E2F6F49559ULL,
    0x7CEFAB892E951898ULL,
    0x3DCE956780E055C3ULL,
    0x154955F40CA28F3AULL,
    0xFE8595B6E7894665ULL,
    0x92,
    0xBB,
    0xAF,
    0xCC,
    0xD9,
    0xF2,
    0x42,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseESalts = {
    {
        {
            0x8D3D7E89D78FE0B0ULL, 0xF80DC226DC5C59AEULL, 0x88F730B3A754923CULL, 0xB9B25EC2C090ECB9ULL, 
            0xD1360ACB3592EC30ULL, 0x45856FF2A9065986ULL, 0x4D56366B948C07D2ULL, 0xAB18B9FF411CE113ULL, 
            0x674F97D4C0B68789ULL, 0xC9058AAF352969C2ULL, 0x90829638E8A37371ULL, 0xBCBCBA7540949197ULL, 
            0x6B413AB4AE1A9D93ULL, 0x6632A2BA64E8AFA4ULL, 0xDE73488EF3D70BE2ULL, 0x8905AE4118C7B2A3ULL, 
            0x591668AEAF610AEFULL, 0x150886EE3BB541AAULL, 0x70D124C59CCC9C3EULL, 0xCC1EF6BA016699C3ULL, 
            0x202B09B6ADD7E402ULL, 0xB4F8EF69B775FD45ULL, 0x66F6EB3CE2D2C301ULL, 0x2BB5A3785C50B71CULL, 
            0xF392DCA97FBA4E78ULL, 0xBCBD40472AE19826ULL, 0x55CEA4A13EFB5D78ULL, 0x576B49570019D985ULL, 
            0xFF22D96567ED1CDBULL, 0x5EEDF7CC4FC75E1DULL, 0xB89171874E910DFBULL, 0x3F36352C3EDFB833ULL
        },
        {
            0x13451DA7FAF42DB9ULL, 0x866EF52081BCBEACULL, 0xCFFC82E1A9DE984CULL, 0x3967C67D795B3988ULL, 
            0xE565515E3E829983ULL, 0x7B71EE3A63DA056DULL, 0x9878E5064F1AB5E5ULL, 0x5EED841C63AB42FEULL, 
            0x148C1F9888273354ULL, 0x48654E3CED83349DULL, 0xA075026B2EF83A23ULL, 0xD53A15B882F8B961ULL, 
            0xE355B5E92BE808AAULL, 0x703941E4B856014FULL, 0xA4208CC2608D429FULL, 0xCD37A882F74F7526ULL, 
            0x3B096B0181CA85F9ULL, 0x81D14B97304F6C6AULL, 0xA83F53454B6649B0ULL, 0x976AE5FAB3F0C130ULL, 
            0x4025EA49CC24AD27ULL, 0xE1BD80ECF329571BULL, 0xDDC443C04B82AF0AULL, 0x6A968834F285A0CEULL, 
            0xC6B1FACD32254FDEULL, 0x8E067C04D17CCA6FULL, 0xE731CC523E438828ULL, 0x654D8D895641FCDFULL, 
            0x34227357DA98F09EULL, 0x72BA4BF46D55AEEAULL, 0xA0D8BD9C20B3D1D9ULL, 0x7E493252105E6C2EULL
        },
        {
            0x6C849BACBCD8D4D0ULL, 0xBB179C4A165B1C9FULL, 0xDD9366BEA1C32844ULL, 0x1F546CFC9E56EA10ULL, 
            0xC2113D1857275156ULL, 0x1E6A31EBBF6305C5ULL, 0x9EC0B0CB35786094ULL, 0xABEAA29E0B504B75ULL, 
            0x60150E77844885D7ULL, 0x89785EA8209743D3ULL, 0x4D53847D516C1E28ULL, 0xCAACD88284CE06E2ULL, 
            0x8682E6542E4AD425ULL, 0x32FEDADD5CE18263ULL, 0x1164473D5FEA9D0AULL, 0x102D4358A4733365ULL, 
            0xE8DE46DC296F2D19ULL, 0x8A0683ED0B5A52E2ULL, 0xEB17BAABED5F7A11ULL, 0x311F8EEC53EE3517ULL, 
            0x9B7BE4AE5F502FD9ULL, 0x2A0B9CA938BB1796ULL, 0x877107074F857CECULL, 0x981B52391C617A78ULL, 
            0x8F413EEEBE4612F9ULL, 0xE8A3B0DEF86288F5ULL, 0x4A9B9AF59D68C100ULL, 0x86331A2A7BB186D4ULL, 
            0xB3115A8C4BD3A3A7ULL, 0x51084AB77680A637ULL, 0xA86D8849590716ABULL, 0x96402060B52DED1BULL
        },
        {
            0x5B88B0EF41F1EB34ULL, 0x76CB5C9D191558F0ULL, 0x0EBCE6E2B6CB7D81ULL, 0x1B7928E0E13F9C96ULL, 
            0xA52CE31A5928317AULL, 0x4352AEC870109A46ULL, 0xCF1FBE2333D60DFCULL, 0xC2439EB31428FF3BULL, 
            0x44C017FE698EBC01ULL, 0x935F375841CB4CF2ULL, 0x3084D3F6CF530E69ULL, 0xC088CD37DA88732FULL, 
            0x052DAD664728EC08ULL, 0x91BE0179DB800100ULL, 0x28E34D0AEEF62C8CULL, 0x829174B9CAEF7168ULL, 
            0x30A43F2B8D7B21A1ULL, 0x510C50672ECEFC3EULL, 0x959338FA6C6220BEULL, 0xAC49F7D62BAA4DAFULL, 
            0x01AAE407D6054E20ULL, 0xA5D6FEE0080E321CULL, 0x4C0498A9C9BC755EULL, 0xD5DACCE0AEEC6656ULL, 
            0x2CC54C108770DBB1ULL, 0xD5E141E76F3AB5A9ULL, 0x1FD16A7AA535B5BFULL, 0x9C657169DFF772EBULL, 
            0x435DDD1327F2EEFEULL, 0x138BBCC47EEF4DC7ULL, 0x254BBD4E22559F1BULL, 0x09C614B5933F043EULL
        },
        {
            0x4F3DC85534FF9C6EULL, 0x82AFFCCE79E60C7FULL, 0x995CDD27823F81F1ULL, 0x8BAD28B22C1C5E4DULL, 
            0xE3E53883EC444A35ULL, 0xD44C1D9B44D69C4DULL, 0xAF0E7FD0F553B56CULL, 0xC88EA28DD6C430D4ULL, 
            0x04858260E1B217A1ULL, 0xA7C61D93DDB43288ULL, 0x978863D42A1C6892ULL, 0xEB1CF5682254E25BULL, 
            0x36173F5DC1788C94ULL, 0xE2BC174230CD25FAULL, 0xBB25C0A7038835B3ULL, 0xA20D81F1CE1EA289ULL, 
            0x50B6BA362E93A584ULL, 0x1652D2B04913470EULL, 0x634AB5519E1905BEULL, 0x9BFC5C5A6FE5DB58ULL, 
            0x699A8FB2FC5F1BEFULL, 0x8D9ED1D2D211745FULL, 0x91AAF29C9D69A55DULL, 0x4FE934433B127379ULL, 
            0x3FA93121AC5290E8ULL, 0x2E265C21B5A85619ULL, 0xB58DB2D4D6586B73ULL, 0x7D4061AA4B66AD39ULL, 
            0x66BC4F05A166233FULL, 0x9586DCA4295D73D3ULL, 0xE202DA8F8CB4548FULL, 0x9EE15BDD204D80AFULL
        },
        {
            0x60B04FD0131EC348ULL, 0xB3EA04F6D6098693ULL, 0xFCF1CAEF3FB6A25CULL, 0x31B75A3BFD7A6CA5ULL, 
            0xDC421A5F225B1004ULL, 0xD768FFF5A9A61505ULL, 0x84693F1F2E7CFF60ULL, 0x0F28A720CA5C9244ULL, 
            0xE7ED368EF6A1ECFEULL, 0x2AC678D7151D8133ULL, 0xA0188D04F18A5616ULL, 0x63A9D0D8D2E2198FULL, 
            0x8F3A8147318FF22AULL, 0x3BA04D1FAF158F79ULL, 0x4C54C03D722A161BULL, 0x241AF1E457E6FDFBULL, 
            0xD818CEC60E5BE1F1ULL, 0xD2AE153533FDB78AULL, 0xB6D867306A393F6BULL, 0x76126196BA27DC9AULL, 
            0x3A49850034D11517ULL, 0xC83572E4F40C3992ULL, 0x05E71D3A0A2D0AFEULL, 0x9C6D49AD3EB61105ULL, 
            0xAE9F8B0E82F66007ULL, 0x045018A6AF0B0475ULL, 0x2111DFB688B96B79ULL, 0x5F6BDA37FDA12EEFULL, 
            0xBAB66FB6EB355BB0ULL, 0x6D587A7006CBA545ULL, 0x9F4BCB52D51DFFC7ULL, 0x9C2C04C451878B89ULL
        }
    },
    {
        {
            0xB1AFE99331BF9293ULL, 0xAB4B4A078A82C096ULL, 0x0B943D2A4D84F4B5ULL, 0x77B07E2F94BC1364ULL, 
            0xF2E3FF862832ADC7ULL, 0x86A2F242FBCC073DULL, 0xC1AE77EEDC773FAAULL, 0x55576402D90F3843ULL, 
            0xF49915D54D673EBEULL, 0x825BBBCBD778CEB2ULL, 0xE5FE224AC2D6D7E2ULL, 0xEBCFDF463E3B1EE5ULL, 
            0x8452911171F07CEDULL, 0x61689D53A2627F79ULL, 0x9771E352D8B9C17DULL, 0xB33EC2261B802F50ULL, 
            0x378494943FC3630BULL, 0x846F34DDA32FB682ULL, 0xF379A2FC8DB8F5D9ULL, 0x9D7D0208E5E78DA9ULL, 
            0x0DA50E990CFDCE3AULL, 0x7BA1FCD7F20216CAULL, 0xFE71916DD82195BFULL, 0xFC09CF350A895CB0ULL, 
            0xB45D0683FF2A5E5AULL, 0x91141D55B746E6ABULL, 0x1EB7B38D7C8D2891ULL, 0x66853100F085A038ULL, 
            0x75C7271FD1804979ULL, 0xCC1138D2F4C20DDEULL, 0x98CE4BE6AAC978DBULL, 0xCD1306EDC133AAF1ULL
        },
        {
            0x30E50A853813A791ULL, 0x3BC83919A5E084ABULL, 0xBC329C6AEF74CD45ULL, 0xEDDD09D1410716DAULL, 
            0xF326AE4C4FC77E2DULL, 0x020AEF6273793050ULL, 0x4C814CCA03CD71A9ULL, 0x65428BDCE12F2993ULL, 
            0xFD9E1DBFC70BBCBCULL, 0x7A7E8F825F61EC32ULL, 0xD1A287038E26331FULL, 0x19EAF1596E190FFBULL, 
            0xE7264B842CB81538ULL, 0xDEB20C30D1B4A46CULL, 0x2AE0308CD0AFFA42ULL, 0x6E55B8DAF71A1CFBULL, 
            0x2AD6720AE29583CDULL, 0xE1444FBDECA13808ULL, 0x7F94624E1A25FA73ULL, 0x38411A690379FAD9ULL, 
            0x92025AFEF54DB51FULL, 0x74D22E23B34DDFB1ULL, 0xBF2BC5A8B26C1B34ULL, 0x2D030FB40E6D6D08ULL, 
            0x8332512157CAF759ULL, 0x9468F9FC785B0F98ULL, 0x7A1BDA7A12C2A663ULL, 0xB8863A2184729FF7ULL, 
            0x01857F6DFD0C023AULL, 0xBE5C1EC8A4EFE580ULL, 0xFE3A087CA6EB4DF4ULL, 0x2FD6EEC39633CB8EULL
        },
        {
            0x57985A1A13569D27ULL, 0x8FEBACA1861D7861ULL, 0x59CBF48221CFEDA8ULL, 0x702B4E68FDEF804DULL, 
            0xC11A112C054FB8E0ULL, 0x948CDB37FC146867ULL, 0x0F9291464784F6E4ULL, 0x3F99478F12D16F95ULL, 
            0xF43EF2771A5BBD98ULL, 0x2A1E5E47B551CE06ULL, 0x02A4EA52B4D54D26ULL, 0x6A172F52B4E489BAULL, 
            0x1E9F3150FD6E4394ULL, 0xA0D226FA9A1C7958ULL, 0x8AF16A5DBD94A181ULL, 0x226AFD8025B48868ULL, 
            0x828FBD287D9C0EC2ULL, 0xB7D80600640E53C5ULL, 0x367750D4FE8F189BULL, 0x4F5771FD0D769FC1ULL, 
            0x3C059A78478668A2ULL, 0x7BD70A7E96392819ULL, 0x8698655BD2871F93ULL, 0x3B2F815EBC3676D6ULL, 
            0x6D535462DA588FD5ULL, 0x1E1DF7BDEEE3BD84ULL, 0x4E6A9B60C72857AFULL, 0x8046E4F1D2A0046EULL, 
            0x520FA53722C4D63CULL, 0x461F771AB765A87BULL, 0xD92013654F950961ULL, 0xCB77279EBCF7B447ULL
        },
        {
            0xCDDB7B30333CD0CAULL, 0xDFCEFF9A035B9443ULL, 0xCB92B448CFA5F95BULL, 0x58F8868578C87008ULL, 
            0xE6DD996CC74F999FULL, 0x9B70A50F2698B308ULL, 0xBAF410139D401259ULL, 0xEF049DBC4BC87F12ULL, 
            0xD56861A83AF38242ULL, 0xECFA3FC8C016EDADULL, 0x8081D307492501CCULL, 0x8B51D562B8E351DCULL, 
            0xE8F680D76C99B77BULL, 0x41E504CC2F6733E2ULL, 0x18BAFAC28F5B7BE1ULL, 0x2214D1967D55A902ULL, 
            0x40EE6C7A2427AC50ULL, 0xF298301293AA0E2BULL, 0xA62339ADD226701BULL, 0x48245B9A25140A82ULL, 
            0x33FAF8CA5771F9FEULL, 0x9CE4D5BD0A8DCB99ULL, 0x883B820942F9B0F2ULL, 0x5CAE3D38F4B28866ULL, 
            0x774DE5DFF504B5E6ULL, 0xAD2E3200ADE3FB7DULL, 0x175E0AEFE699FDF2ULL, 0x2C09EFFBE71D5002ULL, 
            0x36179772EEB6888CULL, 0xB66411B87560476BULL, 0x222406F378E071CEULL, 0x63C1CC0431AB77D0ULL
        },
        {
            0x04CFCAF0D8C59161ULL, 0x0381350A09C58B39ULL, 0x717309E0B2164354ULL, 0xE37F276E11E5DD2DULL, 
            0x5D80156DDD4CBA28ULL, 0x27F06A9091131CFEULL, 0xDF098AA14930AA0BULL, 0xD6F543CDC7888B99ULL, 
            0x402FF8EF017F9E55ULL, 0x7AF28388DAA13D1EULL, 0xF5537D7AAD2FEA73ULL, 0xDB506F91359771FBULL, 
            0xAA73F28F9ABAFFD8ULL, 0x05D6201E484743D4ULL, 0x6B44CF6A36DB5F59ULL, 0xAAFED66911BEA88EULL, 
            0x0786A7781C928494ULL, 0x043A5D8DD0BBC6AEULL, 0xBF342AAC128A1D9BULL, 0x16BE8F00D406FF00ULL, 
            0x1419E6E2F433F700ULL, 0xBFFF31F6B03CCE30ULL, 0x0D0F68878027DECDULL, 0xF8FE002DE3EDE289ULL, 
            0x8E313B67E497FB90ULL, 0x1B44D50E03355E80ULL, 0x08B9C3E0116FA160ULL, 0x4285FD8B29ABAAB0ULL, 
            0x15C67F1CB226EFA5ULL, 0xDF66994CAFDBCC6EULL, 0xFA795CA4DB02A189ULL, 0xAF895A4663BDAA98ULL
        },
        {
            0xDF3B324D943985C6ULL, 0xA0003FBB9F4966F3ULL, 0x4F61EDB3514BDE93ULL, 0xE8567A3C92D2F398ULL, 
            0x3A8FECEA7C132B46ULL, 0x069DC9EA8B438836ULL, 0x1AB7D2D88F0DB7E9ULL, 0x6BAFFF5E897148DAULL, 
            0x4B72AA950DAF0A82ULL, 0x35E7A0645DCEFE87ULL, 0x31C8604294604A8FULL, 0x34D05F5D158ECF70ULL, 
            0x7D36A2FA8BBA73E4ULL, 0x2B8C0974ECECFE22ULL, 0xF06D9B7B506B2F63ULL, 0x33C59FBD1402CEF2ULL, 
            0x620CBBFAEC9FF81CULL, 0xC7C682FC9179A9A3ULL, 0x4F7BAFC2C8095B09ULL, 0x0C383838FB355B8BULL, 
            0x0876E5D7C179812CULL, 0xF6B1E22E4148885FULL, 0x473529AD3BC34D41ULL, 0x8E19198AC29E3F18ULL, 
            0xFA4AA9594AE3E8C6ULL, 0xCEDB7621F9DA4B0CULL, 0xF55F30D25CE6B2EEULL, 0x43A5547CA14A19C2ULL, 
            0xE1DE3C7F9BE029D7ULL, 0xA7F310A1BED85F4FULL, 0xFE4A71358A9A7833ULL, 0x26AC5F648755E2A3ULL
        }
    },
    {
        {
            0x8AC5C8CB1B8CE4ABULL, 0xAEB8C8BEEE20B165ULL, 0xC69D24C4591582B7ULL, 0xC6B01D570CF92327ULL, 
            0x531916A88FDF5C5DULL, 0x664DD206F58F0B14ULL, 0x8971FE8F9FB8E54AULL, 0x56A6F1A8D9160582ULL, 
            0x75196D129AF90BB1ULL, 0xB357A744A6BF6FFEULL, 0xD4F5BD22AA74AD10ULL, 0x221FCD815E53652EULL, 
            0x0CC28F1563E1A62AULL, 0xD3F6FDF106A173C8ULL, 0xE026610913791BACULL, 0xE544A3B3A53DAA43ULL, 
            0xADA55551A55E9244ULL, 0x685BCCFD6A09A8E2ULL, 0x8F3C7A95B404C851ULL, 0xC157EF55667C5FA9ULL, 
            0xFE95BEB6AFBCD837ULL, 0x114B65FDCD9C1AE8ULL, 0xF9C32A1C12A0317CULL, 0x1CF345BE8543EF13ULL, 
            0x563A18C606D401BBULL, 0x4AB231CAECFD7BDDULL, 0x0849492FD6912574ULL, 0xCE0237628958BFAFULL, 
            0x69525238AC527BAEULL, 0x36A6811E70B41C76ULL, 0x72E1BED29ECCA919ULL, 0x0728EBD77FC532D1ULL
        },
        {
            0x6E3E40E23804768AULL, 0x15DB1C6994E3FE13ULL, 0x8FAF13DE22A8C3DFULL, 0xE22CBB4339583507ULL, 
            0xD33B1344A0F28569ULL, 0x0AAA71BEE0066ECFULL, 0x7971A57890B34EDDULL, 0xA9630C926D3BFA20ULL, 
            0xC95DA47A7EC19CBBULL, 0x4AEE7CE6AE048B15ULL, 0xCB1F48A3B51AF298ULL, 0x2778DE53E9E7AEE8ULL, 
            0xE556115D516369CDULL, 0xEFA52E3287C9234AULL, 0xDB83F74360C095BCULL, 0xB4FCE22802C4CEC4ULL, 
            0xC64FDA2957FEFF40ULL, 0xB9ABEC4D551BCCF2ULL, 0x34262F9C0E5F25ABULL, 0x0F52DFE74CAB679EULL, 
            0xF57C72846D0B2CAFULL, 0xC20EBC0E47A79D1DULL, 0xC7E2838CB2E180C3ULL, 0xCBD1E26B4017EDD5ULL, 
            0x7CFB5647D296535EULL, 0x40708FFEC1EF6DA9ULL, 0xA62DFDC71711DE96ULL, 0x5FB7B47357640408ULL, 
            0x4202822BE95DA8E6ULL, 0xB6E053E17BBF145AULL, 0xDB54B57C4951CF26ULL, 0x79E72EF96C670B09ULL
        },
        {
            0x0A54E30EB8868B8CULL, 0x4806779C27C91774ULL, 0x4C00365F15C08D87ULL, 0x179D7207FA986AA1ULL, 
            0xFFBD0B0DC5CDF9D0ULL, 0xAB8D4BECB4EF704CULL, 0x365747549172E321ULL, 0xE790FBB87E63BE21ULL, 
            0x693BABEDEF417E80ULL, 0xA4530477435668ADULL, 0x482C6026A2842E6CULL, 0x1383A3D0F606E4E0ULL, 
            0x4C0AAEE221292D51ULL, 0x09511AB9C4061729ULL, 0x8601F941351F1BDAULL, 0x6A5F19B8EBBE864CULL, 
            0x66BE13AE3E6B3BE1ULL, 0xA9AAE034FDDA7B58ULL, 0xD34CF1D071475205ULL, 0x70A100B4FBAAB6A5ULL, 
            0x81EFFEF9D92ED790ULL, 0xDE6B20FC43376126ULL, 0xD92A5FA3C5422640ULL, 0x2156EB270AE5BCC3ULL, 
            0x84C777371D0B19BAULL, 0x89FE8D68551B5F24ULL, 0x9CE26564D9506F3EULL, 0x76DF5C6DA33AB0A0ULL, 
            0x390CB701A7233B37ULL, 0xF244CEEA99EC2638ULL, 0x247A1BFF47039850ULL, 0x83F4EA792EADAA17ULL
        },
        {
            0x7BCFEEACE4AA3CADULL, 0x42D94C4D89116F18ULL, 0x3841B3682DB13FEAULL, 0xC36FE54358688065ULL, 
            0xFE23E563AB843E04ULL, 0x0EF6DF2527B9311BULL, 0x4215FF397FE23440ULL, 0x308D918F33317693ULL, 
            0x27165E41AB4B7CEDULL, 0x04F972E58D65E80EULL, 0xA3A64D5264F5960FULL, 0x32D694CE4930A884ULL, 
            0xB539F279701A29CFULL, 0x9A14C1DDA7057B58ULL, 0xA8E42C793A5D395AULL, 0x5F178B165830D06BULL, 
            0x8136E52A0095E635ULL, 0xBBF4957A6557C744ULL, 0x93867A0018FD3C62ULL, 0x9D3D4ACA13C22F96ULL, 
            0x0C67124BFB9B10D6ULL, 0x02E9E25263C26314ULL, 0x21DB8D99111894D5ULL, 0x8F72527B965E2C48ULL, 
            0xF2BE1CA07E94A6D2ULL, 0xDCD42A269A74BD45ULL, 0x45E973DE03DEEE96ULL, 0x2BAE64764733466DULL, 
            0xE5B17D19BDFB2F51ULL, 0x9BF096AAC0B37DBDULL, 0xAE8960DC2848CB8DULL, 0xB81700B05B1E4DB3ULL
        },
        {
            0x523A9018D31E35C7ULL, 0x97E997DF58A5857BULL, 0xD94D4ADB1FA5CC0BULL, 0x1DDD67295448D69DULL, 
            0x2AC9C8FE6AB1D2CBULL, 0x7D251557B9B21D66ULL, 0x605918BAECCE0122ULL, 0x6EBD9FF0B84A5162ULL, 
            0x463D948D044AAAC4ULL, 0x445541B6F5F41F92ULL, 0x40A6C45FEAEA9DAFULL, 0x730133DAC54E9181ULL, 
            0x2D89093F643BD742ULL, 0x442112E205894E40ULL, 0xE41F8FE5594E1DBFULL, 0xECF06F46B5D2A6C9ULL, 
            0x077316F30575B48FULL, 0xABF2CA220E2F931FULL, 0x459B299791DA92E0ULL, 0x0E9A0A8D94220F63ULL, 
            0xDC188902C2866A7DULL, 0x6E913286A05DDDFAULL, 0xF7361FD95F5570BEULL, 0x56477238209FE0DCULL, 
            0xDC126F85B85A1530ULL, 0x85AF9C71BC08295DULL, 0x44A3CF530FC44F05ULL, 0xF62A53841979FE2AULL, 
            0x016A3512340A3FD6ULL, 0xB2218EFE72D74CEEULL, 0x0A6EDA168331BB59ULL, 0x736604086A4138C1ULL
        },
        {
            0xE7C9BC55842E63BEULL, 0x7927F3BCDB796536ULL, 0x132691E74E03B53FULL, 0x010BD924F57FE41BULL, 
            0x34079255908A29ADULL, 0x94E949B9A2BE762DULL, 0xE1A17C3B1BBD57BFULL, 0x0349D35921717163ULL, 
            0x481AF90F60FF25ACULL, 0x0308FD0929A568FFULL, 0x30880742D3A0B50EULL, 0x9BC249B6BF157E6FULL, 
            0x8D0E5BC2FD0ED000ULL, 0xB669DD24E620F609ULL, 0x1406722B56987CECULL, 0x8FF8556D35018CBEULL, 
            0xC3DF0AE696BC0391ULL, 0x0ECF1212CF1B6EAAULL, 0x61A1A717E7D588CAULL, 0x2B93D92FFEF2F72EULL, 
            0xEBF8BF910C86B08BULL, 0xD1B618D60B3D5380ULL, 0xFD50766271D102C0ULL, 0xA7FB1D429FFEC493ULL, 
            0x3615C6D7D5D3D687ULL, 0xD86C4CAC65C48070ULL, 0xACAE2CDB3EC7C52FULL, 0x7837F6E31512D60EULL, 
            0x5124D871B266FC26ULL, 0xA36B0C9E267826B4ULL, 0x5F5297FBE2CA6861ULL, 0x9FF3F37A8E0B910CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseEConstants = {
    0x7F0C6014C216C1FBULL,
    0xF873267F044EB3AAULL,
    0xFB0123FD60C2C535ULL,
    0x7F0C6014C216C1FBULL,
    0xF873267F044EB3AAULL,
    0xFB0123FD60C2C535ULL,
    0xBDF36B7848FA0634ULL,
    0x8DE8850054D6581CULL,
    0x7D,
    0x67,
    0x35,
    0x4D,
    0xF9,
    0x29,
    0xC4,
    0xBE
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseFSalts = {
    {
        {
            0x20D538B27BD3148BULL, 0x7E401BCDC87629A7ULL, 0xC2D1EF02FDA1A32AULL, 0x92291F75DDF6ED69ULL, 
            0xD0CBB19EEBFE8FB6ULL, 0x79E614A7E5966F3EULL, 0x93F3CC372DB1F8E3ULL, 0x6E9FD78BAEDC8E97ULL, 
            0x818137D520B64956ULL, 0x91D9C93567349019ULL, 0x41B9A9D07A12EF8CULL, 0xC5346B39FAC4C15FULL, 
            0xC581D8FC880AD627ULL, 0x6C29408B6A1D0290ULL, 0x70729BDEF9FAC0D0ULL, 0xE10D2C3CFC5A9B41ULL, 
            0x0FE012C39BF0145BULL, 0x1E8ABCA39692E971ULL, 0xE607E42A70837CCDULL, 0x0859CB59B86F7210ULL, 
            0x27277A80209B9729ULL, 0x7A1C77C163ED45E5ULL, 0x1B86E76286085167ULL, 0x968EA5B12D08ED5EULL, 
            0x97A2B7A472F20F26ULL, 0x4024380B23660F72ULL, 0x934A914A8AEBAFA4ULL, 0xC64F36F1F4EC8389ULL, 
            0x704CD0852793C109ULL, 0x9912EE69E2DE43DBULL, 0xC511E7C474617875ULL, 0xA4B4C443046A5F40ULL
        },
        {
            0xA209882D308AD7BBULL, 0xBF9B88EFCE124BBAULL, 0x60836B155C0971BBULL, 0xB2B0AF862EDE59C1ULL, 
            0x30B39FDF08671C94ULL, 0x4B56CD3508D4F95EULL, 0x14591B6CE5FF6F57ULL, 0xE0A78E8308E6A4E8ULL, 
            0x5588CCC82A0A737DULL, 0x2B099D37EA4B8259ULL, 0xC873E942F2E19339ULL, 0xA27CEA5B94BD0215ULL, 
            0xBC65C278A673BF3BULL, 0xAFF664CEEBD56029ULL, 0xA241CE9C10C93C11ULL, 0xB4ED903A7A778D28ULL, 
            0xD9E80DFE6FF4947CULL, 0xD62DA41765E0B9D8ULL, 0xF059B374BEF9FADCULL, 0x2854A3405AB324EFULL, 
            0xCB897531E19CCD1BULL, 0x03EDC5D6877417EAULL, 0x477E03363F124475ULL, 0xE6A743DAE48C4FBCULL, 
            0xAC26729C5A362A1DULL, 0x2CD9D2A113CC9BFCULL, 0x8C1B421DEB9F0347ULL, 0xE3158BB12529691DULL, 
            0x9823914E2CF0D183ULL, 0xAF5CE878A819BA7BULL, 0x5CED23A5E28018A5ULL, 0x0FDA53B65A03BEA9ULL
        },
        {
            0x59357ED6B1C8417FULL, 0x3DE6236DC4B9D09EULL, 0x38CD2A572745724DULL, 0x7D8C287023F8A8B1ULL, 
            0x6E846972F0C73024ULL, 0x5F2355BB1ED1CA63ULL, 0x485EBCA97ACB682EULL, 0xC5D9C4D61167D1BEULL, 
            0xF3E1F9982F65DDF0ULL, 0x115C14B270E7A513ULL, 0x036194C4C3FD098CULL, 0xD1EC7B46B61856F7ULL, 
            0x4E504FF3C035CF31ULL, 0xF28F7C4D51615409ULL, 0xB9C3CBB61F729BABULL, 0x0F24DE86946E4A8BULL, 
            0xBD759E5D3C3C9879ULL, 0xFAEA76C108B31A23ULL, 0x341D0A564F65D249ULL, 0xE90E753979DF52EFULL, 
            0x7D1EF4C197055B48ULL, 0xDF5D18F74CB675ACULL, 0xC7C8F6E7E6EAD238ULL, 0xFE27C1347CFBAD53ULL, 
            0x021E798CBE230169ULL, 0x4177104E1D75F91CULL, 0x7B92822C0CD5E593ULL, 0x7D80DAAD140E47A7ULL, 
            0xF1AEF045F6E239CFULL, 0x0753E9B87FA2A5ECULL, 0x6D7A32EA0D4C1062ULL, 0x8CAC7DDBAD8581FAULL
        },
        {
            0xB6B680FCFBCDD83CULL, 0x88C25B3A1A25DA53ULL, 0xE81570920DF4BEBBULL, 0xF91D97BB9CA8FB22ULL, 
            0xCF723AA3DE721050ULL, 0xCEC6E9F5595FE1A3ULL, 0xCE2F766BD93E6F1AULL, 0x7E4144278E3C84B3ULL, 
            0xACB70DE24D51B29BULL, 0x613A662EB0C0334EULL, 0xB2C60C398CFBF3D5ULL, 0x23619DB8282EE816ULL, 
            0x4339C8F5068AAACAULL, 0x3935EB2101CC2FB2ULL, 0x8B17FB36B2BE4F95ULL, 0xC4C1340EDA9F25FCULL, 
            0x11A4EDA0D455E215ULL, 0x5B11041D1932A3ABULL, 0x6CF3B1E8E9C90109ULL, 0x85FB832E39017EA6ULL, 
            0x42A16C0710236C12ULL, 0x6F6C7F851F3C0FC4ULL, 0xE5C8CB21CFBE9465ULL, 0xF2EA245149C2E5F3ULL, 
            0x82D24B10CF4EE2CCULL, 0xE00210FB63501DDBULL, 0xF22CD6B9E142BD0CULL, 0xB70DF5F5E2DCABFBULL, 
            0x2D7C4CB62557BD69ULL, 0x2B9229DC57CB1A70ULL, 0xEF70E9894FAFADEEULL, 0xC776F4AF724949B0ULL
        },
        {
            0x5A038BF2F37C10CFULL, 0xA4056C837601A051ULL, 0x909A461B0A720507ULL, 0xAF8FEDB68A835FD7ULL, 
            0xFF34ECC941203463ULL, 0x30573543B20FA67BULL, 0x65CD53501EC45133ULL, 0xA08778E360996E82ULL, 
            0xA76AB515E865BC32ULL, 0x5196EE127A751EE0ULL, 0x0923CE833A3503D4ULL, 0xEA1CFF90ACF90AF4ULL, 
            0x65762B419D64346FULL, 0x48359D1243768217ULL, 0x0CA0DDADD11D6B4CULL, 0xCEE3B7CDB889AD6EULL, 
            0x59BA64BBFB98EADAULL, 0x0EF73430E82B09EFULL, 0x2AE89AF10A86CC26ULL, 0x40EE48C42AAC5BBDULL, 
            0x147079D1DEFC5BC4ULL, 0x189A84C87B2D73FCULL, 0x5A070DC02A9D20B7ULL, 0x839DE8ED7D763E52ULL, 
            0x2849A0F222269A60ULL, 0xE2886FC4042B5903ULL, 0x7E47E9D8B65F2862ULL, 0xC92297A4B5A873C5ULL, 
            0x9952C11533C7DC69ULL, 0x34967EB4AD840544ULL, 0x28786A4E5C38410AULL, 0xB119C1868F6F870FULL
        },
        {
            0x10F94F46177FBC90ULL, 0x04064568D4641773ULL, 0x28456D3DB1913ABEULL, 0x1D1EA396F7843450ULL, 
            0x8DDC1D1EC557F3EDULL, 0x087395DB9EC835EAULL, 0x7125FC8469327578ULL, 0xFFCB8F0D22B755B3ULL, 
            0x922C9A4CA32B07B7ULL, 0x746C5D4676B3A79CULL, 0xE79D35EA0BE04F68ULL, 0x0964367BC8235B05ULL, 
            0x54F6B95632690781ULL, 0xDA05AABDD291A8C8ULL, 0xA725AEBFFE291948ULL, 0x2BBF5B5277084E97ULL, 
            0xD66AFB2FECEB0C0EULL, 0x1C668254FA157DC6ULL, 0x8E3126FA4B30DD7AULL, 0xA305578D0E87AB47ULL, 
            0xE3CA4DA74307951EULL, 0x6EAFA021D9E661DFULL, 0x32F75F18058B68D5ULL, 0x58EB064594839280ULL, 
            0x8BC097CF2E13223CULL, 0xC99EC67ECAD9C170ULL, 0x17034DE5792FF99AULL, 0xDD63EBD4B905757FULL, 
            0xE7A5E6E3F961AA5EULL, 0x04E404DC4BB835E2ULL, 0x6BE2D35A05E4D6A5ULL, 0xA6B1FFBA5C7F3369ULL
        }
    },
    {
        {
            0xC5F633C74620FC7CULL, 0xF8F41233382B1940ULL, 0xC6EF27D157381A06ULL, 0x0DEC66F59D2DA4A4ULL, 
            0x117FB6E4235667C5ULL, 0xD4EE19F07193716FULL, 0xA065B608E4E48DF2ULL, 0xCC122A5B04C7417DULL, 
            0xC128504D4EB0195AULL, 0x304AF2B5DDDCAB78ULL, 0x2FEA3A308A3E35B3ULL, 0x1E06C426E9FFCA33ULL, 
            0x4353F244310D528DULL, 0xDC9F7D889B76B337ULL, 0xC6259AF4CFE9275FULL, 0x7A8B16A230BDD03FULL, 
            0x998053A4C520661FULL, 0x7955B3A3D1EC1A63ULL, 0x46F778D68685B481ULL, 0x975604F338DF2111ULL, 
            0x437397E8EFD72E1FULL, 0x43B8FC3DD24D1445ULL, 0xD27E66DE1DC02FB1ULL, 0x301A8BD7AC865118ULL, 
            0x2DA429B9CF9FAF6AULL, 0xE9C422F5AD4384ECULL, 0x0F74AAACE3CC9804ULL, 0x85F178F02B644342ULL, 
            0xB709914244B8161AULL, 0x37148632ECC56A1CULL, 0xE60630851F619398ULL, 0xF3B1C7DC2FA04AE9ULL
        },
        {
            0xE69920C114A41D3DULL, 0x09BD61950611D7C0ULL, 0x2D6F849DCB76A79FULL, 0xE111A20C7E9FEEB4ULL, 
            0x209B5F89214DA978ULL, 0x6CAADF533BBD86A2ULL, 0xEC0ADFE7F0429583ULL, 0x8047FF57DA7F6BBEULL, 
            0xED97F9AB0DA50600ULL, 0xD413BF131D2CF10EULL, 0x3A5A3C1C8FA1A67CULL, 0x6A7466084DCEED5CULL, 
            0xFBE5A3B207AF9F33ULL, 0xD4677B4338CDC076ULL, 0x332BB324DFD7A712ULL, 0x3242B3AC7F08A1A1ULL, 
            0x60CFFAFDC8123ACBULL, 0x750A8E73150310F2ULL, 0xBFABDAE229D6E3B2ULL, 0x628E40CA9526DCF8ULL, 
            0x71C4A9BFFC3F073CULL, 0xE8B4939A7B3CC203ULL, 0xDC43785D31D05C19ULL, 0xCF07010F1B2B7969ULL, 
            0x84E3CF9D9B74DC3FULL, 0xBB892122123CD2D4ULL, 0xA37E20EDC4D86BB4ULL, 0x11E1E7D17F6D9094ULL, 
            0x60A29D6C886F8B68ULL, 0xED93084C20210150ULL, 0xF4CCC4B9B4D518C3ULL, 0xFA7C5991C761493DULL
        },
        {
            0x79D6A4CA7B18D40AULL, 0x716A9F2646FBB00FULL, 0x5DF83F133DD95E0AULL, 0x254E0363EF0A35F5ULL, 
            0x86688CC0264F1DC5ULL, 0xE8E10FA91EC894B1ULL, 0xA7F4DAACCC768223ULL, 0xC5D701AF1B5327A8ULL, 
            0xD50AE905AA95C3EDULL, 0x241D2B0F473C7B12ULL, 0x4F0071DB1587506DULL, 0x02CC3201F4A628BCULL, 
            0x0078A2E538005A21ULL, 0x330BA5A2B8225887ULL, 0xE375616A3C37681BULL, 0x200A3965B954096BULL, 
            0xB4EAF1F9AA7ABF9FULL, 0xC17F0CA41222CF38ULL, 0xE4D4EC5FC60ADEB0ULL, 0xF8FBE76B0FBBC36CULL, 
            0x6AE7D18ACB6AD053ULL, 0x45701E5042F08B80ULL, 0xBF3CB372746E6BDDULL, 0xFE6A929D08EF85ECULL, 
            0x406084044DBED4AFULL, 0xA0F0876F6CDC6BEBULL, 0xBDD2173D32EF6C79ULL, 0x2C0CDBFBEAE71C77ULL, 
            0xCDAB68D2F45A29F7ULL, 0xEA45D428FF2EDE57ULL, 0x26E0C05EFB160487ULL, 0x916B9655BB7C1E4AULL
        },
        {
            0xC6C699063D197049ULL, 0x0015FEAE1880DDC7ULL, 0xCEF4CE8BCA8565E2ULL, 0x381D1C39C6447491ULL, 
            0xCD60F73AAEC3684EULL, 0x3433F08C5D7D0F6AULL, 0x072E2C25D54FD2A9ULL, 0x73AF609F6ED8BF72ULL, 
            0xB553F8149E7B547EULL, 0x2041007F1396F70DULL, 0xCBBFC1530AF194B1ULL, 0x15CDA49D9A9788B0ULL, 
            0xEC887D1F72ED6167ULL, 0xE29AB9311393AB64ULL, 0x40F6ABFC2C6F13B7ULL, 0xCC1255D04C8C95E1ULL, 
            0xC09049E09F17090EULL, 0x6E2586B699975D54ULL, 0xF029952103C57A38ULL, 0x0D6BD20DF34ADA31ULL, 
            0x1B49A2E1A5C526C4ULL, 0x0D5E1D47ACDA8AF3ULL, 0xF2D849AD844F61DCULL, 0xBA603AC9017FD8C7ULL, 
            0x60C04B8A9358D358ULL, 0x4CCFEA79796825CCULL, 0x8323FE8B65BCE84BULL, 0x292B1FEB929A759AULL, 
            0x77334BC4C2F1EC38ULL, 0xFE74F85511249B91ULL, 0xC343EB86A28A4704ULL, 0x84A5985831B9F91CULL
        },
        {
            0xD23E345652AF3D7CULL, 0x598AB8354DE1AFA7ULL, 0x840E81AE484B2FE3ULL, 0xAF3B1ABD7E9A0E03ULL, 
            0x6863DECFC5677EDFULL, 0x070E4802ED6AE6C9ULL, 0xE521D67064E9E8EEULL, 0xBAAA9A480106F7D5ULL, 
            0xE1F4FE40ED3B0726ULL, 0x9A055D504DAF311DULL, 0x9532D488A90DA65CULL, 0x9E46122321959C80ULL, 
            0xC1075ADAE28FB4C0ULL, 0x4877FF51661744C6ULL, 0xE913252FF15CACA6ULL, 0xDA15830408F00119ULL, 
            0xE33672C0D1FA98D4ULL, 0xADB65CD753FC9CE3ULL, 0xDD8D8D1DE489A1C6ULL, 0x108B90F7C263EEB3ULL, 
            0xD615865C6B4A5A08ULL, 0xFF241E34919E7A61ULL, 0x67AC359DCAD15E8FULL, 0xA14ADC6C4E092F7AULL, 
            0x27DB6DFD3150BD18ULL, 0x8FCA9DF51A31000EULL, 0x86CEE8FBDF4F45ACULL, 0xD29D1F52C196EE3DULL, 
            0x7968C1E328D4BAF2ULL, 0x59E3A38E2BB11E3CULL, 0x75513DA4F606E8ABULL, 0x697ECD30A6993FC6ULL
        },
        {
            0x1BBDEE364A8C33AAULL, 0x406924804337B504ULL, 0x8413CA3A06B11530ULL, 0xD0777B2CC8DA6156ULL, 
            0xD7A60CAA7E34CD0FULL, 0xB3B6B74425475FC5ULL, 0xFB9980EB8F6742B7ULL, 0xAE98E61348591E66ULL, 
            0x628364B59542F45FULL, 0x73E5F44738973C16ULL, 0x3AD13A548A622551ULL, 0xC3FD3F505EE688B7ULL, 
            0xF2216EBE359402F8ULL, 0x436DDB962AB6B5EEULL, 0xDE52E861A1AE16DFULL, 0x4D134784A7CAE1E5ULL, 
            0x73CE5633FB7844AFULL, 0x015F23533917FA3FULL, 0xB6CB8374C361D40AULL, 0x8016654A1CB63A24ULL, 
            0x749EFD6586D48E9BULL, 0xF5FB889F11B0941FULL, 0x14A814462397A68FULL, 0x98B3FF4947C28E31ULL, 
            0x908E497DAD61FAB7ULL, 0xCACE3EFBB85974FDULL, 0xC3EBA80B106772F3ULL, 0x34BB098E8D56B0EDULL, 
            0x40F466129E889C93ULL, 0x312D3CCF5D864F29ULL, 0xD558AF13B2C2C543ULL, 0x9E7DEAB5D09B2FCDULL
        }
    },
    {
        {
            0xF050600FFCF97799ULL, 0x345041E31E04BC04ULL, 0x03DE8D607A396184ULL, 0xF10003625857A472ULL, 
            0x871B9CDD08ACECB3ULL, 0x7FC312F23E0BB075ULL, 0x69B9474E141DF3C0ULL, 0xC000FA4EBCAD1FBFULL, 
            0x7A65F6C23491490DULL, 0x20C2BE9AC54A6DE6ULL, 0x4783A4A1A3F0C852ULL, 0x848BD893C48A8F85ULL, 
            0x3FD1EF175AADFB55ULL, 0xCBF98A5CF46326C5ULL, 0x97B2738EA040D31FULL, 0xEEAA4E2A869988B4ULL, 
            0x5C4F6BFE2BFE430DULL, 0xD0036384223BA9DBULL, 0x03ACD92FD545C8C2ULL, 0x2C5F6EB37C3CCB55ULL, 
            0xFAE1C3885B55D01EULL, 0x9F147BCC9B6F1199ULL, 0x7D2545DFAF316B73ULL, 0xB4B742921A20CDCBULL, 
            0x462D730C88ADC90EULL, 0xBB44E5023AE19018ULL, 0x1EABF9153E27CFD2ULL, 0xF60D6AACC583C2E7ULL, 
            0x00248ADA4A41F76EULL, 0x0D7102256E0A531AULL, 0xF3AF8517D911F294ULL, 0x8B231DD21ED5289CULL
        },
        {
            0x6CEC359038468E7DULL, 0xF0D88B57DC5A1613ULL, 0x5F36BC6C299BE75DULL, 0x528AD2D14C1D87B8ULL, 
            0x399E926F621F79F6ULL, 0x1A53FF948254EAB7ULL, 0x5649D1C5FF4DF5D3ULL, 0x93E581B98EED6A07ULL, 
            0x3471D4E49E9BA746ULL, 0xF439BE3135112180ULL, 0x2218761418EC15BAULL, 0x18F266BB4E326C30ULL, 
            0x3CCFF23FD0D033D4ULL, 0x0A0920494E21477EULL, 0xD3C55FEEBAE819D3ULL, 0x6511E76D44457E6BULL, 
            0xD5CA405F6EF9B5E1ULL, 0xB711F316347BD7E9ULL, 0xF0CC611657198917ULL, 0x60F9BC632D8B153EULL, 
            0x5200AE4B8ACA40D2ULL, 0xBF3D9396214E3EA5ULL, 0x8489BE6B9FD874C8ULL, 0x56F284A960BB59F5ULL, 
            0xD28A8C0C3744B3E5ULL, 0x6C4BB95393C76462ULL, 0x39B1DEC982162AF6ULL, 0xDC290C8F7D123544ULL, 
            0x83CBEA3544C222C2ULL, 0x6392FD86A527D841ULL, 0x06557FE30F799DB5ULL, 0x446B6FD7F622A7ACULL
        },
        {
            0x0D6A9FEE2FE1CEEAULL, 0x65B5EC12631A480EULL, 0x200B49BD9AED5189ULL, 0xF2045D13C2D7DA45ULL, 
            0x0C0B99E1BF399F9EULL, 0xFFF97BF6898C85CDULL, 0x53EF027242EBF041ULL, 0xEDF75A2B5835B950ULL, 
            0x8CFFAEE4F9F1C7DAULL, 0xAEC70A1108046CA3ULL, 0x8E114FC14A07A352ULL, 0x1A31653DEAACE8DFULL, 
            0x6AF084BA5FABDDD2ULL, 0x92452E7BCD0EE28CULL, 0x8CCC326DC7794C92ULL, 0x7B577EE047E3F0ECULL, 
            0xFFA9A24715BFE64BULL, 0x692FF93F7238CB7DULL, 0x8DF91C01AD9769A4ULL, 0x6E37BD956702AE8BULL, 
            0x76F2A6C36C7AF3BEULL, 0xE7D50A5AFD6F1368ULL, 0xC2116FBBB5A29F6CULL, 0xBE7525DD56797207ULL, 
            0x3D5F6A2DA6C5BABAULL, 0x72B18AEA0CF2C4CCULL, 0x0B73A11484F60DA8ULL, 0x34A460BD2771344AULL, 
            0xA1A9E4BBB1BDA039ULL, 0x913DBA479ED45464ULL, 0x1776FE361D7E6A8DULL, 0x806F8D6AA6FD9370ULL
        },
        {
            0xABD3168731C3CC2BULL, 0xED4AEA136C634DF4ULL, 0xC99157E5AC4FA42AULL, 0x60B6E8398B9D0358ULL, 
            0xE6ADF77326F021ACULL, 0x326A405E08A1F94EULL, 0x15A4AFDCE9912A20ULL, 0x4599274E5C56F9B0ULL, 
            0x40DCBFEA06B28C6EULL, 0xB276D7046D0E1229ULL, 0xDC69FD6340A3A751ULL, 0xA06BC0760400D0F5ULL, 
            0xD160F2AA7520AA38ULL, 0x2970EF82E355FF3CULL, 0x98EFBD0FCA2A1B8CULL, 0x432FF87CE822C84EULL, 
            0xE050222F5C80BDCCULL, 0xAF0A606FBCF55149ULL, 0x86DE9791A0DB5436ULL, 0x5CE9BE9DFFA35488ULL, 
            0xB9954B148F290CE8ULL, 0x83FB406999A50640ULL, 0x515FE278D10ED709ULL, 0xFD2B66BF6FA34D19ULL, 
            0x7E7385443C955A85ULL, 0xCF90CF8A9C68D2E1ULL, 0x5AD7D4EFACD0F0E7ULL, 0xD533A1348AFA619EULL, 
            0x95461CFA9B063FECULL, 0x5092884B74D29977ULL, 0x0C67B29755A28E12ULL, 0x75BD1ACF56B7FD9CULL
        },
        {
            0xB6559EA150E582BBULL, 0xCFDEB2CBF4FA5F3BULL, 0x5A640199EB8874EBULL, 0x4E8E16BC11DC14F0ULL, 
            0x60DD21F4AF4318D2ULL, 0x318B44096C29A833ULL, 0xD383B91232256CF4ULL, 0xB9E6BA7150CB8F1AULL, 
            0xD4B2BB6F97CF27AEULL, 0x997187DD0720735DULL, 0x9D90A2B5BE97A42FULL, 0x8E69F64399E2CE52ULL, 
            0x834214DF7154472AULL, 0x5056C9E5A7853549ULL, 0xE686F0CE69AB3C67ULL, 0xC770789EF04C3A56ULL, 
            0xFDCC0584326A638AULL, 0xA6F02FB89492CACFULL, 0x547DFE48066FD973ULL, 0x54ECB728A555D388ULL, 
            0xBA99E9FA3E2FF6E6ULL, 0x8F4F91444124FDEAULL, 0xE6E4934CB2951D2AULL, 0x5DCB469471B04687ULL, 
            0x56B676BA4C4A9205ULL, 0xC161504DCE1E8174ULL, 0x55BF9A42A2582630ULL, 0x7AD1DAD1E1080FE9ULL, 
            0x91119DE340BCE759ULL, 0xAA5DF5FF0C1FB141ULL, 0xBBB5A800F3BBF34BULL, 0xC515DD2148D923DAULL
        },
        {
            0xA5ACBBE22BA4465FULL, 0xD2112DE66367D551ULL, 0x4E43749B9DA75135ULL, 0x870EBBE41C96E1C3ULL, 
            0x3404492535EF6944ULL, 0x8C133B65E2106FDEULL, 0x7AEF4E8D1D81286AULL, 0x88F0322CAE5D099CULL, 
            0x305DADBBA286D56CULL, 0x15FC36B55E6AF3ACULL, 0x347F172CD9BE05C4ULL, 0x2375D52D815B025CULL, 
            0x26AB53817285C053ULL, 0x78FC94EE3ACA13E6ULL, 0xFA040EE644337817ULL, 0xB1D67718BF5F98DBULL, 
            0xAD7910888A13BBB0ULL, 0x83722D7289C83E85ULL, 0x892B40CC7256F680ULL, 0xB6850F81E4304E1EULL, 
            0x02D2F0CC2D2E834DULL, 0x69050720823BB5D2ULL, 0x24664E6C2BA344DFULL, 0x9785B509EF136B6EULL, 
            0x9B7C92F8C7B4BC64ULL, 0x778A2A04EE57138AULL, 0xE02816E0AFB1BD2DULL, 0x3988512E179057AAULL, 
            0xD47311E7E66DC7E2ULL, 0x4F79071E90A68BBEULL, 0xCC886D385A3A6E51ULL, 0xD8478095D24A4BF2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseFConstants = {
    0x410CAED0707A944DULL,
    0x814EDB45FAA41DDFULL,
    0xA58EEAC66814761EULL,
    0x410CAED0707A944DULL,
    0x814EDB45FAA41DDFULL,
    0xA58EEAC66814761EULL,
    0x35802FF7BCD4E989ULL,
    0x17D4B07E57D80773ULL,
    0x1D,
    0xAA,
    0x50,
    0xD2,
    0xD4,
    0x9F,
    0x4F,
    0xBD
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseGSalts = {
    {
        {
            0xBB320882CCF7B3E6ULL, 0x8C234618FAEC750BULL, 0x6D86130763E97C28ULL, 0x6BF3B8F653C2DF70ULL, 
            0x0C7527DED82E54E0ULL, 0x471C01118B13CBA2ULL, 0x81B269B4B1CAFF79ULL, 0xFEAE249B54017F7AULL, 
            0xC029E78065ECEDB4ULL, 0x8A55C47A343D5A99ULL, 0xE9634B2CADBA5AD4ULL, 0x8D404A0C41B0704AULL, 
            0x8BDB8A25E1384B37ULL, 0x5A737CBFA0D3773EULL, 0xB1D6B51A2D9543B2ULL, 0x1F26037CC849DCA6ULL, 
            0xA14FD67BB0F21A5AULL, 0x5C78564A462D2A95ULL, 0xFF424B548A181EF9ULL, 0xAC45D6A586EBC1CAULL, 
            0xC1A806A9C0F0B35BULL, 0x0D1392C9A7469E75ULL, 0xB8FCBB8D90E9689FULL, 0xC594A3A9452C478FULL, 
            0x84A369FF45493C90ULL, 0x8159233E9C5242CAULL, 0xDC58EE2CEF15AA7DULL, 0x0B4C14687DB05DA5ULL, 
            0x78306ED61A41618DULL, 0x62CABE9EAEAD7B18ULL, 0xDBF7E3F12BA52D38ULL, 0xBE9A84FD65741915ULL
        },
        {
            0x88F126DAE97B07CAULL, 0xD7E255D23CA6CB1EULL, 0xEA59BDE76A31768FULL, 0xBBF83BFD4F323E05ULL, 
            0x281EB8ED9F9DBF9DULL, 0xB6414B8792042F90ULL, 0xF9AE4229C4B42278ULL, 0x2A3A0D8287D68455ULL, 
            0x615A73FC3597F8BBULL, 0xCDF5E1383B2B84ECULL, 0xF24AB53A4C6C1C52ULL, 0x778D571EE18051CAULL, 
            0x6B6295612888ED39ULL, 0x761E1511191282CEULL, 0x74ED8011873B178CULL, 0x08C329DDF3DB53B1ULL, 
            0xFFB2C128EFA7043BULL, 0x5A1AF36FB4517DF8ULL, 0x9A70B621CA336CECULL, 0x8C976FEDC1E4B2D2ULL, 
            0x872277167E69F875ULL, 0xC365FB04007ADB72ULL, 0xCDB8AC0CBB7A3C9AULL, 0x3C4DE595E744D919ULL, 
            0xA46F3BD77BA87C32ULL, 0x38ED99901E0C958DULL, 0xC8A1CE73F8E15073ULL, 0xC0A1144A4E12DA13ULL, 
            0x36B6F40675400A65ULL, 0x9D03C76166D42482ULL, 0xB365C3A32C1131A4ULL, 0x3604B5AB9D74E90EULL
        },
        {
            0x05C54488C0BA6A4EULL, 0xF7C9E98A0D4AD352ULL, 0xB90632600548B02AULL, 0xB2F0EA3B440EB56EULL, 
            0xD0C54386DA1DC608ULL, 0x02432F19A855CCCDULL, 0x5547CE97D0888521ULL, 0x4C25B3A12EB67956ULL, 
            0xDA7BCB6AC5DCBC27ULL, 0xAE7E645731672076ULL, 0x37CB14C74AC25599ULL, 0xC43685D482FE0567ULL, 
            0xDC64CDD0B7838FC6ULL, 0x7C97270CBBFDF051ULL, 0xA0343940374DEA95ULL, 0xBF715FC00B527FB3ULL, 
            0x0AFB4059C1D1272AULL, 0xD6959F5F4C7A0514ULL, 0x61376A6DEBCC1EEBULL, 0xBEF2076FC3424BD9ULL, 
            0x8365582A1359DFD0ULL, 0xF8317D00816116F1ULL, 0x0C9829B788A83DA7ULL, 0x89065C88DFDC6181ULL, 
            0xFCBCF76D890625AFULL, 0x5D87786D86E5B150ULL, 0x2666C8915D2E68A9ULL, 0x3ADAA90B5640947EULL, 
            0xBE8B904BA030076DULL, 0xF9A5446ADAF12239ULL, 0xE9946BE0DE3F8202ULL, 0x52209E3E9EFE8F7CULL
        },
        {
            0xB928E2617405FE80ULL, 0x9D36A842B9BC84DCULL, 0xD1CFAB5AA551C856ULL, 0xD0BB8938CDFAF930ULL, 
            0x1C9E348A87E0409DULL, 0x8771B49CDA258CCBULL, 0x398DA2262BB3633BULL, 0x062EEBE8299A40C7ULL, 
            0x49944FDBC9F1D770ULL, 0x46909876E2EDFCA8ULL, 0xAE6F641752A32F86ULL, 0x2527F9510D01AC07ULL, 
            0x70BCF3773CED5874ULL, 0x423DE1EAE656463EULL, 0x46B77A0FBDB395B8ULL, 0x6A7A70D9A4F89004ULL, 
            0x539144769C36C812ULL, 0x0B898A3713129F04ULL, 0xA0A917CBFDC55F94ULL, 0xA1E3B9E97A05027CULL, 
            0x029C9EA09129C85BULL, 0x16ABE44036601D50ULL, 0xA9B26FE041592184ULL, 0x1DAD3F28D7E57512ULL, 
            0xA0F18BE0A6FC1512ULL, 0xA9416A4D4DFA1FA7ULL, 0xFA0662FC5100C396ULL, 0xCEF0F84C2498857CULL, 
            0x7B69C8DF92FFAD5DULL, 0xD6B6E91165267E95ULL, 0xF68B5A7F06AC2AF5ULL, 0xE6E9D47FEB88BC0EULL
        },
        {
            0x4DAA392D1EE9FB37ULL, 0x818674200B5BD678ULL, 0x9CE0D9B27D0DC1E2ULL, 0x526F4C48049DA919ULL, 
            0x59ECD089AE10B137ULL, 0xBCD4FD727A087C38ULL, 0x828386FC5A97733DULL, 0xD4990DCDBA2424C7ULL, 
            0x448CDD924F9369ECULL, 0xC5343B046697CECEULL, 0xBCCEDC22269CE355ULL, 0x6F4FAA3BA8B563A1ULL, 
            0x50267B7EC10063B1ULL, 0x651237E0F2F0C01FULL, 0xAB755B89AEBD5B2EULL, 0x8EF9170B610DF7CFULL, 
            0x5012607EFF22DDA4ULL, 0x7759F71BA1161446ULL, 0xBFAE967B82F5860EULL, 0x0E4D5B68EE09EFE4ULL, 
            0x62D6D2BABDF04D63ULL, 0x6644D3671104DE97ULL, 0xF3BF41661EB98A3BULL, 0xB08840B93D240AFFULL, 
            0xF8E6A382AADB9317ULL, 0xEE247DCE4FDE65B0ULL, 0x11D49FD6DA74E6ACULL, 0x31A6C856D75F0BBCULL, 
            0x3DB0B6CAF5C7587FULL, 0x9DEDE825DBAA56AFULL, 0x21757AAC304B3778ULL, 0x65B172923078D162ULL
        },
        {
            0x5E1DEC307E7F51CBULL, 0xB94C067BBC0E6248ULL, 0xC077B85AE5C1D379ULL, 0x6098BAED5EB0CCF2ULL, 
            0x8A08D80759D54356ULL, 0xD1857FF5627D8961ULL, 0x2F3023EE91722DB9ULL, 0x35C64EC351A1541CULL, 
            0x1C44AB2631E6418BULL, 0x778E4B23B330B641ULL, 0x3D48ABE6E077BB36ULL, 0x7B027AD3C8CE898FULL, 
            0x3990A70C75041EFCULL, 0x350C014CBC34DCA7ULL, 0xB2D296B3A7A14387ULL, 0xFBCC23420553174FULL, 
            0x4132080118F491B3ULL, 0xA970D5EA988615BFULL, 0xEC9BF082E21853EDULL, 0x66E8D727658B9035ULL, 
            0xEEBA48DE966AEA5FULL, 0x2B4D6B680F78D28FULL, 0xA8033D0F69FFF3B6ULL, 0xCD887829866C0DB8ULL, 
            0x75E83399338E2C49ULL, 0xB49B5FB4E96EFDDCULL, 0x65973CBA4FD5EA68ULL, 0x8BAFEC617E39FB3BULL, 
            0xF09507A8B46E7E5CULL, 0xCA402CF3B2EC6560ULL, 0x1C6946BDD7B42897ULL, 0xD060EA56D3E72B6DULL
        }
    },
    {
        {
            0x94AD409AED733A49ULL, 0x3E2EA440596A019DULL, 0x1B33C4D107E43134ULL, 0x8DB6817B1501F685ULL, 
            0x881B204D4E3E0388ULL, 0xCA87A09073B4E07CULL, 0xA567875E54D93600ULL, 0x83602DE80AA7C467ULL, 
            0xFF061368E6033469ULL, 0x1AF9FE030E1F86DEULL, 0x59782D8C219F6BB7ULL, 0xEEFB01A13F68BA97ULL, 
            0x93A8064182205E67ULL, 0xBBEF023D634451A4ULL, 0xA1265E9D689CF57DULL, 0x8B6B98BA52C22444ULL, 
            0xAB4ACEA092100EB2ULL, 0x97D823C36FFC029DULL, 0xC59C2F90E378FC57ULL, 0xE54B7B7BFDF5171DULL, 
            0xA7FC633C0A12D489ULL, 0x9E172AA7A904B226ULL, 0x88B7142B4C17B23DULL, 0x11F5B1EA10A258DAULL, 
            0xF293B47DD9829F0CULL, 0x67DFD57EF9E86456ULL, 0xA4AE379BCA83C7D9ULL, 0x2A4A3B0BE1930AC3ULL, 
            0x32D9C5A9052FC258ULL, 0x7B7577AEA5F140A9ULL, 0xE20B45217E90CE67ULL, 0x20F8E41C512470C4ULL
        },
        {
            0x1968D8725734EBC7ULL, 0xB645DE2E0E132947ULL, 0x3DC662478E76D756ULL, 0x7CE320B3EAF899D5ULL, 
            0x34E9911B3B26F9ACULL, 0xE9129BAF569BE30CULL, 0xB4F76E1690373B17ULL, 0xA556D05D30B37383ULL, 
            0xE70E87CCDF428868ULL, 0xFBD3F32FD6C3CEE8ULL, 0x4633C259213F8A52ULL, 0xEB571666D6028119ULL, 
            0x3AD218A6553D28E6ULL, 0x9000462F8BDAA74AULL, 0x5F134FAE815E8A62ULL, 0xC39E65C11A3CABD4ULL, 
            0xE59133B841A57D3CULL, 0xAD5ADFCF61B01797ULL, 0x08161A4EFE9C03ACULL, 0x1F6BE91E4DF5057EULL, 
            0xB54CE04878109DDFULL, 0xCC840C8E05E81E06ULL, 0xB5E4443E3792BAA4ULL, 0x4BAC9F06ECCEB11BULL, 
            0xAFD6BBF2F8D3A5B0ULL, 0xD17466424228FC45ULL, 0xBC74F36D6A7CA308ULL, 0xFFE87C920CEC4E9EULL, 
            0xB0E87E7469C1CBA9ULL, 0x49C8F2A4CB768D7EULL, 0x270390466F0000D0ULL, 0xBEBBFEA845F80B11ULL
        },
        {
            0xF1915F170761DC7DULL, 0x53875F2E441FECA5ULL, 0x6BC1F3C879ACB943ULL, 0xF3DA80DB94E5EAD6ULL, 
            0x017F1871E8CB5841ULL, 0x65F55EA50B25D0C9ULL, 0xD924C4E11F8CB553ULL, 0x8B16A0CDD4A6241DULL, 
            0x195BB78F179EA29EULL, 0xCBFF7155A3C9FC9AULL, 0xE74E9A975525643BULL, 0x02B4A667D49BBC36ULL, 
            0x4C4139F3A2504734ULL, 0x51F00AE207D3869EULL, 0x97005F100F782114ULL, 0xE83992FCF0C46CFEULL, 
            0xD341B0929D2B1700ULL, 0x53FFC2CB077A67A0ULL, 0xE237424BFC616958ULL, 0x5DD170CBD3EE2121ULL, 
            0x17560932E59A47E7ULL, 0xC4E170A81B44E96BULL, 0x7661055CCD7DAD1BULL, 0xB466D561ECAA4171ULL, 
            0x043DA4AE96B6E4ACULL, 0xA637128ED66812DDULL, 0x47F7279138E680EFULL, 0x00F0ADA1CA1BB752ULL, 
            0xAF6D90B176449677ULL, 0xC5C4E9340890F284ULL, 0xF0590DE782A8026BULL, 0xCE31CDAA905EAF02ULL
        },
        {
            0x46D5CE0798CDD26EULL, 0x7647CEE4F8A51A83ULL, 0x9EDFFDECCD4FC511ULL, 0x1C700793BFECD256ULL, 
            0x33F5EAD27D02D9C1ULL, 0xF9F20D9AE0884DE0ULL, 0x2C2BD4DFDD713C60ULL, 0xAB31CEA03D3DD66AULL, 
            0x4FBD00C5F54BB2DAULL, 0xF7E5271767BBD211ULL, 0x60CFFC22C84DA85AULL, 0x91E895D5E78D34E5ULL, 
            0x7865D49AA94F5DCCULL, 0x1656DE0F3721F408ULL, 0x8FD7E1FC594848CCULL, 0x69EFC6615149AA04ULL, 
            0x2248814ED29D0723ULL, 0x015C1EEC08853BA8ULL, 0xAEBEE15D5E4760C7ULL, 0x81B5F8029E00030EULL, 
            0x2960C6C20FBEF74DULL, 0xA2818FFFB43271A6ULL, 0xE5E25C2BD94AF509ULL, 0x2262883588749423ULL, 
            0x6203CE8942699453ULL, 0x6F29411C1ADE899CULL, 0x8272F513E7D7B0DEULL, 0xC0F2DB0713DE84D1ULL, 
            0x0BEC717ECA0C1D83ULL, 0xFE1A109ABB505669ULL, 0x5AA0BDC8D3533B36ULL, 0x321481823DB0F504ULL
        },
        {
            0xA9B10A41A8547359ULL, 0xA9BFEF13C6703C85ULL, 0x36DA8CFB6DFEE335ULL, 0xF6ED920A292C349EULL, 
            0x44D59105E6B56DC4ULL, 0x418E133BB9A3B2F9ULL, 0x1E02630D50E74E44ULL, 0x64C22CBB820230F2ULL, 
            0x742AB3C25CB2C58BULL, 0xA5E5E8D42D4BA3AEULL, 0xC8B651AD612ED855ULL, 0x280B1D37C590167EULL, 
            0xAD14E04BE6F91364ULL, 0xF094C6B22EC1C9F9ULL, 0xE11ACE80B3EBF389ULL, 0x801EE699599CD1DEULL, 
            0xA0A7A203EB40D713ULL, 0xA82E1A33DA04697DULL, 0x93B7E5542618E175ULL, 0xB878F3FE5F66B01FULL, 
            0x1288C444F039EE43ULL, 0xEB78AE2FC03613D7ULL, 0x6146F83EB2C09922ULL, 0x5E20878CF7DD1B55ULL, 
            0x17972FDF255FF523ULL, 0x7D91A9A150365AC5ULL, 0x32D1496D7A18DAC4ULL, 0x6D1655C073848E22ULL, 
            0xCE68667A3C7CABCDULL, 0x0FAE8ECC1CD963AEULL, 0x02F835969227D16BULL, 0xA1EC8366AC295B73ULL
        },
        {
            0x0850C8A28204F0A1ULL, 0xCC0F6994B57ADA2CULL, 0xD9DD8A838D5B51DEULL, 0x926EF178926135AEULL, 
            0xA85C5AC8A2595D61ULL, 0x79A09C593EAB2246ULL, 0x3C58203EA199D7CCULL, 0xBB877B99CAD3C59CULL, 
            0xA221171C963CDFBEULL, 0xC0B49C33EB4FFEE9ULL, 0x24D6A61EACA3BACAULL, 0xCDFB48C3AC105088ULL, 
            0xFD5AD2AF2AEDF8C4ULL, 0x07D0CCD464F43BF8ULL, 0x98481D07AAAF22C1ULL, 0xFF7244B6EFDF39BEULL, 
            0x6C4034F04D090C81ULL, 0x4D6C62572593142DULL, 0xE2FC11217520ABC8ULL, 0x279F2802AE27D7ABULL, 
            0x892D051046833F88ULL, 0x7AB7EBFA35FBAACFULL, 0x18D521A9002A86B2ULL, 0xE231165A6F40D1B9ULL, 
            0x9865C6DE16627786ULL, 0x73F798394027480AULL, 0x5D2260D90017291EULL, 0x0A6AB74BEB318DE8ULL, 
            0xD6631DA5DE2D8C00ULL, 0x2A925FF3E7C53091ULL, 0xF527D90206B77B36ULL, 0x23C0E3B0A9829846ULL
        }
    },
    {
        {
            0x4B60F843E4914C9CULL, 0x90B1112DEC7C0FCFULL, 0xFC538594417E7555ULL, 0x11FD1AF371B32D6AULL, 
            0x9A373327191BEF0CULL, 0x0F12F914A9A9E13AULL, 0x92E4E377682F2340ULL, 0x656F79D09B70A410ULL, 
            0x9402B2F338AAE7C6ULL, 0x6B88D7E74C590839ULL, 0xA2FC46047ABD473DULL, 0x603025EBF5CE6BB7ULL, 
            0x6D79CC56E28E0BB7ULL, 0x9894BEC0C9885612ULL, 0x728912E48A81A5B2ULL, 0x67EBF909EE6E67A9ULL, 
            0x8A2A12DF2EC85DD1ULL, 0xDDC9F09F7F918627ULL, 0x4D028D4DEC57E8BAULL, 0xD27A7ED3BBE36EA4ULL, 
            0x9A3DF72CC95169AFULL, 0x8D19AB13A80542A4ULL, 0x6181B3FDA963261FULL, 0xB50B8C5C79B8E2DCULL, 
            0x243348E0857D290EULL, 0x52F665C1EF5A67FEULL, 0xC6E10228E5A828F5ULL, 0x68C52B0C46B83E7DULL, 
            0x19C71CE37A4203E1ULL, 0xB57BB9DDD0BC7CDBULL, 0x24AE06C9564F7010ULL, 0xAD56BF8418390DAFULL
        },
        {
            0x4F8C3E0D088D1606ULL, 0x9721930B7B897AF3ULL, 0xE75AC01EFC9F3C95ULL, 0x48CD982F9D6AD969ULL, 
            0x5C9F0E3C2037905FULL, 0x591785BD14220A46ULL, 0x75E2DB9E07E86CBDULL, 0x91FF881E5A3D3067ULL, 
            0x7C94DD41624FEB32ULL, 0x91AC4CCBFE41F528ULL, 0xA858476E0356D208ULL, 0xE740419F5C0D8D19ULL, 
            0x40473DD118DC24D4ULL, 0x4F0DD7F07B195A35ULL, 0xA924486BF383AB85ULL, 0xCD99561A46AD86CBULL, 
            0xADA06937D2035232ULL, 0xA80987A1244921B9ULL, 0x33D8B15C40ED13DCULL, 0x9C6396AD70536015ULL, 
            0x3A19F118EDD5D430ULL, 0x712B8E1F1C1F6B14ULL, 0x9891FF016C7A1F82ULL, 0x4F5B88727CCA3D0CULL, 
            0x0138F73334C17FD1ULL, 0xE3CAF886E22BFCE0ULL, 0x6CBB86646B4B99F9ULL, 0x11584663F9614A6CULL, 
            0x6AD4C75DF00BFE53ULL, 0x001E2995ED88CE24ULL, 0x2DCC6D72B401643DULL, 0x8C9EB33B78189C92ULL
        },
        {
            0xDAC01A0BCCAA204FULL, 0xE243691053F9E840ULL, 0x958A898CAF7663A2ULL, 0xE9B9646A201CDD2CULL, 
            0xE9FDC1EBEA2EFB25ULL, 0x7BA0669FC8401772ULL, 0x6E03BFFD073B7AB7ULL, 0x9ED861AE6756E99DULL, 
            0x278E023D001C0BCEULL, 0x4B25DF1373017CA7ULL, 0xA9B78B5AFDBD16B9ULL, 0xFA52D1A734D66BA7ULL, 
            0xC32B44CAD747FD46ULL, 0x86F7AD8446BB206EULL, 0x2EB2F2ADD3FB147AULL, 0x23ED459CED0E03EFULL, 
            0x58329F111271C926ULL, 0xE46504D9DECE1A06ULL, 0xB0AC067F3589192DULL, 0x904E8F6F3B02DD9FULL, 
            0x90F5BCCBF3E618FFULL, 0x0DF649A73352C6DCULL, 0x6CD4A4BFDA7BD09BULL, 0x66385E9DF119A690ULL, 
            0x54B97211D0251744ULL, 0xD92BF3BBE69F771EULL, 0x28E64E5CF33AB2F3ULL, 0x1471BAEEAE49279EULL, 
            0xF6578F3818DDEE2BULL, 0x0CB2F5CA990DDC67ULL, 0x69F54794461CDC31ULL, 0xDC676D2800E00634ULL
        },
        {
            0x81AADC3D1F04CCF5ULL, 0x41AE4ACFD6DF18FAULL, 0x26DBD8B29D501BCAULL, 0x4E748427478FACACULL, 
            0xD78B72867BF030BDULL, 0x581A0B70FC460E55ULL, 0xD1153673E6FEB9CFULL, 0xBA9B279E69FA6E6CULL, 
            0x692CD6A4434C8250ULL, 0xF1D69F92F4D9CC10ULL, 0x204C6EDBA3732D68ULL, 0x502F8A24828C5ABAULL, 
            0xFE06109A5E22D121ULL, 0x24D2AA582A0D72E9ULL, 0xBD240F716A5E7B8CULL, 0x51E0F83D47A53B3DULL, 
            0x26990B51AB0BB109ULL, 0x5F43C8FA6F9B9503ULL, 0x39EFF0F7D727BDB7ULL, 0xF0E0A2A175107F55ULL, 
            0x3F58EF862D534569ULL, 0x44179A4DB3E97291ULL, 0xB00F7FC011AF37B2ULL, 0x1D1AF9BDDA6EFFF5ULL, 
            0x3A718BAC6801EEF9ULL, 0xE44643EC455D9649ULL, 0x730616EC0EEB4845ULL, 0xD9D38B9FBC1F8CDFULL, 
            0xE2F8368A235F9D27ULL, 0x329BE067A5AECA25ULL, 0xA58A26D7AE5C2DAAULL, 0x00B09473217C7675ULL
        },
        {
            0x97675DFB2F6DF208ULL, 0x55CFEB2931CD3B6BULL, 0x99E97411FE48838DULL, 0xC756966C1C780A37ULL, 
            0xE52A4326325E92CEULL, 0x35858BF96FF9408CULL, 0xF81BCEBAC011E347ULL, 0x05F9C8C0D21D3037ULL, 
            0x5A5FE7F50A29D1CAULL, 0x8EDF940E8ACC92EAULL, 0x42FA328AD520DCCCULL, 0x6204B8B39141D25CULL, 
            0xAB4BE35D9CAAB131ULL, 0xA5B093921497304CULL, 0xA9E50AE93E23C791ULL, 0x1A9D6FD2012E9278ULL, 
            0x90FDBA0D46800F29ULL, 0xB3E8CC9CB9C0895EULL, 0xE7E2E43CA509CCFAULL, 0x698A1AE792ED410DULL, 
            0xC203DF63841A05D7ULL, 0x30B4243B68827DB8ULL, 0x2E00F5790E9EC8F1ULL, 0x94CD1C1B034B0996ULL, 
            0x17C7259C8C88C502ULL, 0x8675494F04D74B1AULL, 0x792F17315935DDB5ULL, 0x5ACFB6D46F55BBF0ULL, 
            0x79194E2F61F55CDEULL, 0xCBEA898A77C1B434ULL, 0x9F6A2257AB525121ULL, 0x94ADD6AAE66E7D80ULL
        },
        {
            0xB7E62CA2A340DA1EULL, 0xD30F102B8D6BD72FULL, 0x062861D3B09D9052ULL, 0x2311E438D86A9FFAULL, 
            0x40D6D06389DAA4E1ULL, 0x2005C70D9E9AEA7AULL, 0x6ADD2723904B20F0ULL, 0x6DDE135C67EE2BB1ULL, 
            0x5FD24B6144A65626ULL, 0x54BFEBC87EFBD3E0ULL, 0x8E7AE786BC21D48BULL, 0xB795C2EA1E03C730ULL, 
            0xCFC15F860CC954C8ULL, 0xEF75342E2C5F2040ULL, 0xD95625C792955EAAULL, 0x688D07BE071964A3ULL, 
            0x3444DA63B73E93AFULL, 0xB747105360DF70ADULL, 0x9A80960164A62C30ULL, 0x6708CBCB18C8AC66ULL, 
            0x77D9F3C408DFB572ULL, 0x4632803BDDF4CCF7ULL, 0xD6348775CD42ABC3ULL, 0x18362556A94C5E80ULL, 
            0xBE52BDB267560DA1ULL, 0xAEF732460F773B95ULL, 0x5FA444D716C11087ULL, 0xF89BEA554B57601BULL, 
            0x616598249AC9092CULL, 0x452C82F6C5B32AAAULL, 0xEE9C8BC15BA5EE3CULL, 0x99F7C299E7BF580EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseGConstants = {
    0x1AB999503ECC9281ULL,
    0xB9E7B34DE7E850C5ULL,
    0xF21EAFDB79AA42E4ULL,
    0x1AB999503ECC9281ULL,
    0xB9E7B34DE7E850C5ULL,
    0xF21EAFDB79AA42E4ULL,
    0x3A4BCF615221CD00ULL,
    0x6C340AFD4FC98875ULL,
    0x13,
    0xE6,
    0x4D,
    0x59,
    0xFB,
    0xE6,
    0x22,
    0x21
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseHSalts = {
    {
        {
            0x72E1E72F9289CEECULL, 0x9F2CB5C7BA91CDECULL, 0xC77C522B2D3E2ECDULL, 0xFDEB3EA7F04CB062ULL, 
            0x8A1D32E72B4D00D5ULL, 0xC1AA2020A37A8504ULL, 0x33525C3235A6D42DULL, 0x985216B99FD2B328ULL, 
            0x3B3385C225BC6EF0ULL, 0xBC27DFD3C08B21FCULL, 0x32B9C1D4E6AD9936ULL, 0x1E916EB832CFA7C5ULL, 
            0x3827873F65D55C88ULL, 0x45130361A13CDEADULL, 0x4FDCF533E10B158EULL, 0xB347F48DA272C4C4ULL, 
            0xF594F37B2D71D466ULL, 0xA0CD98C01494506FULL, 0xA5F75F2A49997925ULL, 0xE7851253259A5DD9ULL, 
            0x94B38CA1DAF1DF2AULL, 0x8A8008B95E67554CULL, 0xE4CE6890D984E9B6ULL, 0xF7CEFCF0994F845BULL, 
            0x8A380D2389438581ULL, 0x7BEA928261F4B8E6ULL, 0xB47CD99F29F6E091ULL, 0x1189491DE0F587FAULL, 
            0xDDBE70D50AC99867ULL, 0xC5A41E4FC38F3766ULL, 0xE6C72A571C858EA7ULL, 0x7EFB69AED2DA86E7ULL
        },
        {
            0x08D958D2A3C3D3E4ULL, 0xF9021FF60B54C00AULL, 0xA883DA0E8577D4ABULL, 0x9A715AF60E8A28DFULL, 
            0x486B738D3CDD3860ULL, 0x42E1F317C314A57AULL, 0xD3B2C20280BF2649ULL, 0xFBB362B868E71C97ULL, 
            0xCDF5C9EBD67E915FULL, 0x629E1141526D32ECULL, 0x42BAC856BC6A03C8ULL, 0xA42BEA89EDAFDD81ULL, 
            0x04CE04BCD1117817ULL, 0xF42445213774FE14ULL, 0x9C447C99BD058F21ULL, 0xABFF1C49FED56472ULL, 
            0x7DF45143D5CE9709ULL, 0x0559C79CEF622AB0ULL, 0x6BF2BA86F2058C15ULL, 0xAEB2DAAA574A7C69ULL, 
            0x1074CD5442AB3884ULL, 0x68082929AB9D3B73ULL, 0xDB1B479C2492CCBFULL, 0xDB354BD4D703D771ULL, 
            0xFB7BC6915140198AULL, 0x160E8B975CB3D399ULL, 0xFC93B568BBDCA3BAULL, 0x1D8A9F24218C3979ULL, 
            0x1C17E488EDEA730EULL, 0xC8668A99EBC89B23ULL, 0xCD0A2896340772B7ULL, 0x2653AFA71D27F3B1ULL
        },
        {
            0x9226977304DEC29EULL, 0x95C89A023A27FA3BULL, 0xDBDC6AC046524FEBULL, 0x24B373568BE6AACFULL, 
            0x72D0181C53338B67ULL, 0x960A15467EA9F621ULL, 0x8153CF4310BD3251ULL, 0x57FDA091AE58603CULL, 
            0x34964BB1DE5AB153ULL, 0xAEFF5FFA5D63659DULL, 0x52396228C52C7704ULL, 0xFEA6578499129A1FULL, 
            0x011E24C3E086ACFCULL, 0x0A5ADACA4D052491ULL, 0xCC75F917646211E9ULL, 0x75B00E8BB59B3BADULL, 
            0x76D95C59DC1CDF1CULL, 0xF02A86A22153F6BDULL, 0x85E7C2B92D2031B0ULL, 0x05285A411EE02B2EULL, 
            0x04495A7B7F788D82ULL, 0x530B4939D795798DULL, 0xFE625E0FC5FDDA51ULL, 0x337A1C3F38B81BB7ULL, 
            0xB2F5EA2B95EBE3C6ULL, 0x75FBEE6B6EEA20DCULL, 0xDE95467B459C85E0ULL, 0xC23BDDCDC3FA5DCEULL, 
            0x00B547BC160C0B27ULL, 0xC179C461EB3B04CFULL, 0x1D9EAEC9DA21A4B0ULL, 0x09F2DBA3CC59537CULL
        },
        {
            0x9240783BCE99714FULL, 0x2AEC2F85285D1ADCULL, 0x72AFDA60B9F8DD49ULL, 0x0456D8709966C593ULL, 
            0x6BAB2D1ED74E43D5ULL, 0x9D17A4D43BE69D10ULL, 0x8F7E6ECE8933D519ULL, 0xB1827043E17911F6ULL, 
            0x1426BE155CE3528FULL, 0xD44D5967DB1CF932ULL, 0xCFE64037D6C8CBD7ULL, 0x45367BF2813D9143ULL, 
            0xDF97C815F14BDE93ULL, 0x0406E56C072B6DDEULL, 0xE160C17A1E6DC4C2ULL, 0xE911DAA9867657A9ULL, 
            0x1F28CE34FFCBB3E4ULL, 0x0CD2E2F180CCE2AAULL, 0xBDD025A26FFE7EE1ULL, 0xFCD3748E955B6F28ULL, 
            0x1EB959816B83589FULL, 0xFD9BE0C8CA4AF57CULL, 0xDD06368D41AC6F7DULL, 0xADB428517C61477FULL, 
            0x41FBBBF5E5B441DCULL, 0x5D60793362AF8688ULL, 0xD96A95F8C2220E27ULL, 0xE7FDC93551DA80EAULL, 
            0xA6181F828786B0C4ULL, 0x32A503FC367CB35DULL, 0x5E85A37830792DC4ULL, 0x0F59F22702E8CECCULL
        },
        {
            0x9C0089F2ED05CEC0ULL, 0xF5E1FCE4B3174F81ULL, 0x963FE5C19C1F2F4FULL, 0x2152B9D5512A5542ULL, 
            0xD661337DB311B00BULL, 0x5111941EDE6A16CDULL, 0xA803C445B56D2350ULL, 0x1DD7469586607BEAULL, 
            0x86F48E67CBB9639DULL, 0xFDF78EA1B9EA47F0ULL, 0xEA529FED254D5C63ULL, 0xE848D1AC39BB727EULL, 
            0x102E0D8A843EA5ECULL, 0xE798F3099F1411C4ULL, 0x426E906D9FBC9A03ULL, 0xF8EF1249B92D2115ULL, 
            0xB2D99A3095C5D2ABULL, 0x8E169553A2F12270ULL, 0xDE06656E2BF6F3DAULL, 0xE54BB0C2CA8D0E93ULL, 
            0x5F7BD103EE1F8FA3ULL, 0xEB8B71698B07E308ULL, 0x53970AB41DB11926ULL, 0x33390879C9451A0FULL, 
            0x1DBDA188B08208DAULL, 0x71CAE3C113CD4272ULL, 0xDF7AE40B14016402ULL, 0x2B68E996F578E990ULL, 
            0x5CA2B8F02BCE28DAULL, 0xA65BF80DFA4A77A5ULL, 0xDAA413EE4587B15AULL, 0x5FBAE99BB2B77CD6ULL
        },
        {
            0x36EC73DD023FA7C5ULL, 0x2DBEE1B5FBCDA55FULL, 0x6186BFE8664888BAULL, 0xDE4287C378398434ULL, 
            0xE194A234113E40E4ULL, 0xEBA0F1E1FD0CE583ULL, 0x69EFDD0507EAD1B1ULL, 0x6D5568D0F9014C04ULL, 
            0x6EC6932726C5B4AAULL, 0xDB0D33147632BCC2ULL, 0x98E1103838D49065ULL, 0xF9F4BC20C29724CFULL, 
            0xB922D388C8569773ULL, 0x29A73C09D35AFDF8ULL, 0xD2ECF02DED78F13EULL, 0x8F7D1B31B08B7456ULL, 
            0x606EBB70ED2E0BECULL, 0x7CA6575FF4D5CF3DULL, 0x0B51A5B053583AC9ULL, 0xD5E08260802429F1ULL, 
            0x281BA33B6917F2F8ULL, 0x97DCADE7A21D3745ULL, 0x045416CC0ADC37DBULL, 0xC62F2C9B14209E44ULL, 
            0x83CEA133C12EC809ULL, 0x6272E0E63E043C74ULL, 0x67B01264CB1923CEULL, 0xCFB8588720B1D85DULL, 
            0x66E40D7FE965873FULL, 0xB9FB13A4920CE70BULL, 0xC34F345F869F0168ULL, 0x45B41A9A89289FF2ULL
        }
    },
    {
        {
            0xECBDCAEFACA1DF34ULL, 0x5198A00231B82283ULL, 0x5C003CD6FC8BB698ULL, 0xD263A8E94FF67EF3ULL, 
            0x2C50D2DAC3F5A135ULL, 0x97EEC4E4B4FD33CFULL, 0x9F65FD5E7007D6F3ULL, 0x6D03872B4200B74DULL, 
            0xD26035AB7D3AE2B8ULL, 0x0A9C65368B029076ULL, 0xB39F14B49E1D4756ULL, 0x6132CFE2A8B37085ULL, 
            0x9E9D9079EA63C70BULL, 0x128EB3ED5841B8FCULL, 0xDF7D2C49C337E672ULL, 0x5A41F52F05C6F629ULL, 
            0xC2112DDF81AD6A8EULL, 0xC765483131F42BAFULL, 0x26149A2B496CC334ULL, 0x771415894AA8B7D1ULL, 
            0x9146D8B9E99632F9ULL, 0xBEA4D445B3F11A20ULL, 0x2DC9EDBB9E9CF867ULL, 0x93B4B889853FB70BULL, 
            0x4F2219A0BF270C10ULL, 0xBA23FC3018213010ULL, 0x9EE83A3A657B6AC2ULL, 0x4EB1286B21994E41ULL, 
            0xDD525F62FB4527DBULL, 0x180AC2C63804501CULL, 0xBF86FFE41C74CB96ULL, 0x0EDFD4359E9C10E3ULL
        },
        {
            0x49D1A813CC6D39C2ULL, 0xE28B4CE6AA791722ULL, 0x4ABC83802E817550ULL, 0x196F1B89EF75CAD8ULL, 
            0x7B030777EDB22C88ULL, 0x94450AD0AC04B773ULL, 0xB6B2AC73D1FBB090ULL, 0xB45D5839C7281C97ULL, 
            0xAF454EA17A30C5C1ULL, 0x7E8171CDFCD57EE3ULL, 0x973BE90FBC8BECBEULL, 0xAB049B1F49EA4F9AULL, 
            0x9E953B5D6A388096ULL, 0xFEF2153FE066BE08ULL, 0xB1A7E4E2B77275C8ULL, 0xD912D418A23E7102ULL, 
            0x93235CFAD64E9D2EULL, 0xB7E3CB37BE1E7C57ULL, 0xBAE79DDA2421549FULL, 0xE0AC313CD5B03918ULL, 
            0x8EE50E543CE361CDULL, 0xC257D3EA6F296372ULL, 0x8AE85E7292556F3BULL, 0xAEA1050847E69804ULL, 
            0x1B11016537DED6A3ULL, 0x524FAEA3D5A71BE6ULL, 0x5AB9D48576C49AECULL, 0x9487A11969C77831ULL, 
            0xB02CBAD079B56A70ULL, 0xC5788FFED8E0C4DFULL, 0xF772BF55B468088EULL, 0xEBC312BBE8D342C1ULL
        },
        {
            0x05E10F27F1D260DDULL, 0x2AA9581FE71E9327ULL, 0xEE082BDE2F77BB78ULL, 0x05EBFF0E44644496ULL, 
            0xC665C683CC3A79B3ULL, 0xEB354B09641DBCCCULL, 0x67379A1D588AC06DULL, 0xFD0AE9B2035AFD7DULL, 
            0x524693EBB47F0F38ULL, 0x213B18744BBA7A3FULL, 0x213C3BF52B49CC58ULL, 0xE70CAE8EE98A0B80ULL, 
            0x0CB4B318F8D2DF90ULL, 0x554FB3178896DAEFULL, 0x3DADE89E16E4F871ULL, 0x0543CB2C9974ADA2ULL, 
            0x976B22E3B53F95E7ULL, 0x0C6721A9B152B0DFULL, 0x0230B536BE2F52A4ULL, 0x3F16AD4578F8271FULL, 
            0x228D59521219B7EBULL, 0xA5ED283C306FA1E4ULL, 0xE8BDF4963D2982A2ULL, 0x2DB591DB66961618ULL, 
            0x71BA0DA539007F03ULL, 0xCFC96A128D5B12D1ULL, 0x212AB12592ABC402ULL, 0x272A97EE4F99229BULL, 
            0xEF19A702B8408853ULL, 0x5B9B42C457D8578FULL, 0x6954F6CECDC973ABULL, 0x74AA49B91E6F612EULL
        },
        {
            0x9456DA100C2B6E5AULL, 0xCFAED1E70AAE3A9EULL, 0x7D2602583EADA124ULL, 0x002D473FB8633B6CULL, 
            0x7FA5FE0A7037CCCAULL, 0xA4DDB32EC330BF69ULL, 0xC4CFBC564A878DF8ULL, 0x93E748C13D8036DDULL, 
            0xFC5C7A8647C2D81AULL, 0x86D3050F6D4F48D8ULL, 0x199CE4BA7428467EULL, 0xEB50FD372F000345ULL, 
            0x950AD5D358EE030EULL, 0x88AD8F66AF007370ULL, 0x01772950BA649255ULL, 0x14BFAD26B5552C01ULL, 
            0xC2D7C4B9964DB638ULL, 0x364A7C5C06C8CF62ULL, 0x93AC779A2DD605F9ULL, 0x1DD65B80DB6DAD87ULL, 
            0xF0C1C4708F22D4E1ULL, 0xE741561995360E13ULL, 0xBDD920011F887FAEULL, 0x0268333514D2316DULL, 
            0x42D37383905C0E62ULL, 0x66CC3D91D74E90EBULL, 0x265DFA775DEE0EF5ULL, 0x64D6CD2FB585E986ULL, 
            0x6647347CA58237C1ULL, 0x55B762D445D28601ULL, 0x322FD6276119CC3BULL, 0x8D2C0815BB66911AULL
        },
        {
            0xE04004E3A2B48809ULL, 0x0A4841F39D6540A2ULL, 0xB73439BCFA81B3ABULL, 0x5C6229F4CEEB1AA7ULL, 
            0x1C4AA87A3D1195F7ULL, 0x0019049F90AAC795ULL, 0xCBA7070A87F3FCE6ULL, 0x3231E85DC0D56E6BULL, 
            0x07CA8C79D9FEFF0BULL, 0xA4E4C2153F56A247ULL, 0xB560EDBA395F11A2ULL, 0x4B7E720C7BB01E43ULL, 
            0x9F86DA875D705D0BULL, 0xCCC875FD8977A7FBULL, 0x2A9E550443E4F920ULL, 0x4139C72672EDDD0BULL, 
            0x530D1631A48FC282ULL, 0xDF7776D24D37EFE1ULL, 0x5F39341DD6C850F4ULL, 0x0098816CF7D8E1FCULL, 
            0x2C2F53B56E22D832ULL, 0x77C388815A45A4BBULL, 0x3C6D7EDEA8B2A587ULL, 0x1B6517FF3CEA10A8ULL, 
            0x518859AB3E0874BFULL, 0x162AA758C0545E54ULL, 0xE0426CDBCA5CC914ULL, 0xCE57EA8070145EC9ULL, 
            0x3B7FF39C8F954086ULL, 0xC4FF7531E2E841DEULL, 0x75E636E78BD6873DULL, 0x952B1953330BABDAULL
        },
        {
            0x6D4CEEBB19C41087ULL, 0x018E44CCB17CFD6DULL, 0xC2B273C7A4005360ULL, 0x85CD3B29C38FB48BULL, 
            0x74AB0A123850B4FEULL, 0x2134BE0C8A21E8E0ULL, 0xE771D25DA6FC49F1ULL, 0x2B7DF6CAA3B6E37FULL, 
            0xFCEE60921EA72523ULL, 0x3F7E8EC96BF8F56DULL, 0x45C90CEA7A4B041BULL, 0x1094C6735CADB4EDULL, 
            0xB5C59671AD33E546ULL, 0xD9AC4223CF9F675DULL, 0x8D1120BBB8B24A4EULL, 0x9146490B9DB1B728ULL, 
            0x659B7EA0E0CCFD67ULL, 0x07C7B204C5714FF4ULL, 0x6B66E9A0B94BF9CBULL, 0x9F0CD80166E06E6BULL, 
            0xFBCA4D71DBC2FCCDULL, 0xD40D943C2D91BC54ULL, 0xB4A13F7BD76E47B4ULL, 0xBDC1D1D7F4831B47ULL, 
            0x751A9769F3B9F91AULL, 0x967D8F19878CDC92ULL, 0x21BF7FA395E36E3DULL, 0x943948B264A240A2ULL, 
            0xA7E782D04213B961ULL, 0x0664E7FE0F7287EAULL, 0xD83E3CC32E24DD65ULL, 0xA58E7A53CF98BA36ULL
        }
    },
    {
        {
            0xFA03E91BFDA37F92ULL, 0x293D48D86AF1CBBFULL, 0x4015D7A34B4D9CC7ULL, 0x4978B57774FB8232ULL, 
            0x159F74417F34DF56ULL, 0x5C96BC104023523AULL, 0x20D23A201F7DE3E9ULL, 0xAA75524396E16133ULL, 
            0xE1A5FCA2A7B78054ULL, 0x87DA89A346023192ULL, 0x1EFE9D3EA5FDC85FULL, 0x5B4CACC31FA2FC77ULL, 
            0xF4514D9D0063B137ULL, 0xB321D42422387FF5ULL, 0x5C234F97389A10D4ULL, 0x581D07F8620378BFULL, 
            0xE47BF599A9AB17DAULL, 0xDC5C4E19E5F63BD6ULL, 0x8E1807788A5C8648ULL, 0xEA155A8D0F80710EULL, 
            0xBD0358832B3C7576ULL, 0x4416E533A030F7E9ULL, 0x9702BC7FFA1AC83DULL, 0x367E5D61C6B00CB2ULL, 
            0x59BC03AC24C9B9EDULL, 0x2B053119CF05BBD1ULL, 0x2D59F87AD7CC9B94ULL, 0x8ED868066DDF9083ULL, 
            0x6D421889A051FB96ULL, 0x16EA91C05F7A2ECBULL, 0x1368527EDE334D0FULL, 0x6B90DC05ED26FC80ULL
        },
        {
            0xB4EB96961C75D315ULL, 0x9504C05BED5279BBULL, 0x70534F426ACC7A2AULL, 0x57559DC858FF9069ULL, 
            0x6FE83CEB317A3AEBULL, 0x740DA41B152F4AF9ULL, 0xF84CC8EBFE4BE9B1ULL, 0xC71EE4A785865359ULL, 
            0xF3776CAB8963E128ULL, 0x563D914D1B2FB412ULL, 0x7D4E64AB9A7DC2DAULL, 0x9F01853382311504ULL, 
            0x688A266D890F67D1ULL, 0xA917BB5A8D58AAA0ULL, 0xACD66505BE5C0FC9ULL, 0x6A274012F7F2F1B8ULL, 
            0xEE9572E5AFE69492ULL, 0x1101DC0278237F1CULL, 0xE9B7A06870F2F8D0ULL, 0x2A591CEAD85920C8ULL, 
            0x3C6986260D8CCB3DULL, 0x4E04355C1281371DULL, 0x12D086F943AAA6EBULL, 0x2BCC09EFE931DB1EULL, 
            0xC39A5369FE9DF226ULL, 0xC2D6F2163DC50533ULL, 0xEB531951D143CB88ULL, 0x296D2413C50992D3ULL, 
            0x38D27D8AD3183832ULL, 0x02841BA808AEC8CFULL, 0x6AEA891B46EEDD16ULL, 0x041B6E239AB27B2AULL
        },
        {
            0x5F157537402C60D4ULL, 0x79F7D5A37AF81188ULL, 0x7924B6C2BC4E36D6ULL, 0x26E7E2EC5DF41616ULL, 
            0xD4F9E02971153586ULL, 0xF4ECD1BB42A0E0D6ULL, 0xC7D49DC38591C100ULL, 0xD2E1A28858D1B6BFULL, 
            0x1FC5580BFB0DFB0CULL, 0x16AA9F3D2EA28EF3ULL, 0xF3634B1726CC4BFBULL, 0x27851A02F71A87FAULL, 
            0x4FE6D4884CD56FC5ULL, 0xA02AAE2B4149FCB2ULL, 0x5AC6B155F2574873ULL, 0xE62133B0D80DCB02ULL, 
            0xB771CCE77F9653C1ULL, 0x4877784500B58D24ULL, 0x8326487CD604F53BULL, 0x6A0E9591A901F2C8ULL, 
            0xA62FC60B77E5EDADULL, 0x339CBAA1126E223DULL, 0x05336E88F5FB3EA5ULL, 0xEF117D86185EF742ULL, 
            0x7AE35B8612A6BFE8ULL, 0x6853FF9402828567ULL, 0x389E0EF80D60B64CULL, 0x66B6FB9D07D09695ULL, 
            0xCDB27540DE34DC58ULL, 0xB06DA8EF605C7E9CULL, 0x636EDCAD1E6E8673ULL, 0x2269A5A227A6F904ULL
        },
        {
            0x2E7E0390A27CA906ULL, 0x75E888A45C1A5415ULL, 0x856FADFDEB33459AULL, 0x8018C739A5550701ULL, 
            0x244A09719E98AE4DULL, 0x0B1630C6B5762CC1ULL, 0xA9D7CCE1D6EF3437ULL, 0xC75FE74ABD8F38EDULL, 
            0xB17AAA9A3160355BULL, 0xE946E45E13680477ULL, 0xB14C0D1D7E40E474ULL, 0x234D09E2651FF209ULL, 
            0x872D68938DD21DC1ULL, 0xB325A3E7935F2C49ULL, 0xD88C320EAC769B37ULL, 0x1FDBD28FF281C78EULL, 
            0xC28C021E10403FC3ULL, 0x4D2E4E577D35046DULL, 0x5C51916C6C486D3EULL, 0xB4041E180E6DBEE7ULL, 
            0x73D705851FFCEAF5ULL, 0x5FAD7A12FAEA7F22ULL, 0x539199E1C249AEB1ULL, 0xD69F3E6621DFDCD5ULL, 
            0x6F76E00137841396ULL, 0xEEA9902D8D3B4965ULL, 0xC84D8A79FAA048F6ULL, 0x99DBF756DE667E4AULL, 
            0x9300EFD017C6BD9AULL, 0x557AD84C05A085C0ULL, 0x570759BF16AA2F28ULL, 0x7C2C3F5214BA56DBULL
        },
        {
            0x659E5A50958CB4E7ULL, 0xC3D5F2008B32934CULL, 0xC60229E2223250D8ULL, 0xE3A282D1209B2DFBULL, 
            0xBD4C3773DC9ACF3BULL, 0x26A51B6BFC6620F0ULL, 0x02A3E5ADB7FC3A2FULL, 0x3F2F0290C17C4C04ULL, 
            0xD57B51A99DF1E837ULL, 0x3B2859A53EDAE40CULL, 0x50B9210E8F2EFD0EULL, 0xCA83F02701A7FE06ULL, 
            0xD04FAD2FFE2A2B8DULL, 0xFB7292A5D8DAEDFCULL, 0x36CF22C63A67070DULL, 0xE576EB93277E8980ULL, 
            0x345FAFEBC6C071CFULL, 0xFF5D43B9F0BC3E0AULL, 0x47133F7F0AE82E59ULL, 0xB35A8EBBBEAA2272ULL, 
            0x09A53C9AEF0E09D5ULL, 0x70CFF4858786FAEEULL, 0xEE72F2F5E233D8B5ULL, 0x8AEB6C441A64B794ULL, 
            0x3EE209EDAD298A3FULL, 0x1511D4B4508CCF32ULL, 0x5A5F80C50C478F78ULL, 0xA50CDDCF933CF5F3ULL, 
            0x8CBD0CDB71F34A57ULL, 0x2C8E8B9A765D0FDDULL, 0xDA023DA94C0B4890ULL, 0x12211FEBE0FC2CADULL
        },
        {
            0x5E1759A6093369ACULL, 0xE1AF1F2B884EDC6EULL, 0x8FD36FD1E2844BB0ULL, 0x39F0B83E8E0E3AF1ULL, 
            0x4AF0057B50819077ULL, 0x553B2FE0D583620AULL, 0x4CB11B9A96050157ULL, 0x4D72835A8B7334D5ULL, 
            0xC393CBD369577CEEULL, 0x6FB06277307E6136ULL, 0x293EC04C42741BADULL, 0xA280BF1CFA5EA64BULL, 
            0xEA3C593E3B562F51ULL, 0x7A3DBD4600E9D246ULL, 0x42848323BF3AE0DBULL, 0xF24CB69331E88DACULL, 
            0xE103CF59F6D4F6BEULL, 0xB0984C9473A1B02CULL, 0x8223066A829F99BFULL, 0xDF55EB729350571CULL, 
            0x69097E805A14817AULL, 0xB1EB2A86187512ACULL, 0x1A66AD3F4FA1188CULL, 0x4586B87FCF628262ULL, 
            0x2A9A3BFBFD16C510ULL, 0x6CEDC4C1CE9017A3ULL, 0x660B259BB5620D55ULL, 0x7C896B201DCC013AULL, 
            0xC8049F9F3DA257B3ULL, 0x08918BA54580E86CULL, 0x376CC2446746339FULL, 0x7E3CDA3CEB8FB4BAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseHConstants = {
    0x794D04F29A95CD31ULL,
    0x5894EED9AB3867F3ULL,
    0x729346A7C7CE817DULL,
    0x794D04F29A95CD31ULL,
    0x5894EED9AB3867F3ULL,
    0x729346A7C7CE817DULL,
    0x957F5FEE7A15DC3DULL,
    0x0B3F1ADBE31401E9ULL,
    0xB5,
    0xF6,
    0x4D,
    0x2B,
    0x0F,
    0xF8,
    0xA4,
    0xA9
};

