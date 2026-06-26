#include "TwistExpander_Hockey.hpp"
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

TwistExpander_Hockey::TwistExpander_Hockey()
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

void TwistExpander_Hockey::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 12451063936288562582U;
        aCarry = 14776129258065795142U;
        aWandererA = 15700722401999994770U;
        aWandererB = 15304772235226027014U;
        aWandererC = 14918664195702995230U;
        aWandererD = 11403658495994709644U;
        aWandererE = 18103878186079001802U;
        aWandererF = 15286758995332991531U;
        aWandererG = 13741049363360214578U;
        aWandererH = 18168706923062645048U;
        aWandererI = 12719280409341571036U;
        aWandererJ = 14247889086360666505U;
        aWandererK = 10437056619041221795U;
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
    TwistExpander_Hockey_Arx aArx;
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
    TwistExpander_Hockey_Arx aKDF_A_BArx;
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
    TwistExpander_Hockey_Arx aKDF_A_CArx;
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
    TwistExpander_Hockey_Arx aKDF_A_DArx;
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

void TwistExpander_Hockey::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16799177473559157059U;
        aCarry = 11039180312826149042U;
        aWandererA = 12969701710498545317U;
        aWandererB = 14908967949674925864U;
        aWandererC = 12708404940520280779U;
        aWandererD = 10516900126869357068U;
        aWandererE = 17672837847013865082U;
        aWandererF = 16839547003317589606U;
        aWandererG = 9586234769664741202U;
        aWandererH = 12322714814124059420U;
        aWandererI = 15862743603148106763U;
        aWandererJ = 16557477383543549130U;
        aWandererK = 10349848858805613079U;
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
    TwistExpander_Hockey_Arx aKDF_B_AArx;
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
    TwistExpander_Hockey_Arx aKDF_B_BArx;
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
    TwistExpander_Hockey_Arx aKDF_B_CArx;
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

void TwistExpander_Hockey::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Hockey_Arx aSeed_AArx;
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
    TwistExpander_Hockey_Arx aSeed_BArx;
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
    TwistExpander_Hockey_Arx aSeed_CArx;
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
    TwistExpander_Hockey_Arx aSeed_DArx;
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
    TwistExpander_Hockey_Arx aSeed_EArx;
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
    TwistExpander_Hockey_Arx aSeed_FArx;
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
    TwistExpander_Hockey_Arx aSeed_GArx;
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

        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Hockey_Arx aGrow_AArx;
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
    TwistExpander_Hockey_Arx aGrow_BArx;
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

void TwistExpander_Hockey::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Hockey::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 11128606020556895789U;
        aCarry = 18415614835117832001U;
        aWandererA = 9678372662283433056U;
        aWandererB = 10645140479051204682U;
        aWandererC = 16500237374559505679U;
        aWandererD = 16681431755441052305U;
        aWandererE = 10963096049195735077U;
        aWandererF = 15184191783935447476U;
        aWandererG = 10821792973262129856U;
        aWandererH = 17971081976156737771U;
        aWandererI = 10496977556909044186U;
        aWandererJ = 18143170025214554781U;
        aWandererK = 17951476951488080266U;
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
    TwistExpander_Hockey_Arx aTwist_AArx;
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
    TwistExpander_Hockey_Arx aTwist_BArx;
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
    TwistExpander_Hockey_Arx aTwist_CArx;
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
    TwistExpander_Hockey_Arx aTwist_DArx;
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_Hockey_Arx aGrow_AArx;
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
        TwistExpander_Hockey_Arx aGrow_BArx;
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

void TwistExpander_Hockey::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 3 with offsets 2259U, 722U, 7264U, 1363U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2259U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 722U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7264U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1363U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 0 with offsets 7842U, 6821U, 818U, 4398U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7842U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6821U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 818U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4398U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 3017U, 7891U, 1175U, 7629U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3017U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7891U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1175U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7629U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 3, 2 with offsets 2234U, 1888U, 4552U, 4965U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2234U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1888U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4552U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4965U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 with offsets 667U, 963U, 5U, 1839U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 667U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 963U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1839U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 0, 1, 3 with offsets 89U, 1U, 1016U, 1584U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 89U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1584U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 1, 2 with offsets 1333U, 166U, 1399U, 866U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1333U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 166U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 866U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 3, 1 with offsets 1016U, 822U, 330U, 693U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 822U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 693U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 391U, 1314U, 195U, 635U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 391U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1314U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 195U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 635U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Hockey::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 1 with offsets 2899U, 6631U, 5104U, 2503U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2899U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6631U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5104U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2503U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 3, 2 with offsets 6582U, 1090U, 1090U, 7895U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1090U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1090U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7895U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 0 with offsets 982U, 7626U, 6766U, 1905U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 982U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7626U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6766U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1905U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 2, 3 with offsets 1920U, 744U, 6782U, 488U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1920U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 744U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6782U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 488U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4080U, 7411U, 7582U, 6002U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4080U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7411U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7582U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6002U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1029U, 28U, 149U, 1364U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1029U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 28U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 149U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1364U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1010U, 2007U, 116U, 198U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1010U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2007U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 198U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1599U, 1588U, 1291U, 952U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1599U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1588U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1291U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 952U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 932U, 1333U, 896U, 139U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 932U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1333U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 896U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 139U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 [0..<W_KEY]
        // offsets: 2024U, 1530U, 620U, 1708U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2024U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1530U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 620U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1708U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseASalts = {
    {
        {
            0x63EFCC63DB2BEF52ULL, 0x389AABDBD05B497FULL, 0x48EA21A5AA7FD285ULL, 0xE28D3A8F5EDAEB25ULL, 
            0xDFDA2004173E5782ULL, 0x462E33C38F40D1ECULL, 0xE21BC8FF8BF23F78ULL, 0x2760E0936FC7C257ULL, 
            0x0F539F5126177742ULL, 0x1A4E875E159641C5ULL, 0xA1542CC9A3AD5475ULL, 0x1E7875B5DA1E7D57ULL, 
            0x44B12A4724B7C38AULL, 0xA3F7E8F6BCFE8194ULL, 0x3BFC58E92E8E14E7ULL, 0x59A280F5F6BA4F3BULL, 
            0xA02138DDD9A29651ULL, 0x15B0FFCD238B2164ULL, 0xA255A5BD480806C5ULL, 0xC9064EA909BF57ABULL, 
            0xA7C41B0B767D229FULL, 0x11179ACBB62A5745ULL, 0x17484B6F61A1D2B1ULL, 0x6C15BAB0DBE9DA81ULL, 
            0x7B0E611832AC240DULL, 0x3C1E7713D9003174ULL, 0x186124D6238D4237ULL, 0x84F31F3748073A04ULL, 
            0x39C6EEAF2E13E296ULL, 0xBF2145B4FDA6B02EULL, 0x1AED43DE7FCA1E7CULL, 0x3E9BAD41E59E5BEBULL
        },
        {
            0x7C7C69F60F4BAAA3ULL, 0x0CC4BAF1770B1890ULL, 0xDB273CFA3FC20F74ULL, 0xCABDC88172EE487AULL, 
            0xB075078384B5AD3CULL, 0x23510EE9AF245E56ULL, 0x4DD1C412CE9F2600ULL, 0x7A9909D9D2CBAFEBULL, 
            0x2B8994BA4558ADCAULL, 0x34E880302EF55849ULL, 0x95CC04CE99CD67C2ULL, 0xFA73833709635C74ULL, 
            0xCB388C6918FEE04AULL, 0x105F69A9CD7DB2C7ULL, 0x75379E3492ECBE7AULL, 0xDB0633594109C797ULL, 
            0x19945A63B178D57FULL, 0x9A6B3B56B7800E76ULL, 0x6679BC17C87142E8ULL, 0x9B6533D3052502F9ULL, 
            0x1C3318B329FDEEF6ULL, 0x8EBC967668FD7BADULL, 0xF4104944E42EF3C4ULL, 0x3A0AD9E7CA1BE068ULL, 
            0x946B9AB4C373E596ULL, 0x1E3CB2E821EA000AULL, 0xD8833C7FEA3EE56BULL, 0x50F19D35EB40C2CDULL, 
            0xC1B8AB24625E5235ULL, 0x072C7D0129B018BBULL, 0x230AAA6740EC5DE1ULL, 0x6C1934CF73D4DA93ULL
        },
        {
            0xE7AC9604A1EED46CULL, 0x4F88664173D74569ULL, 0x3E398131DCE4F80CULL, 0xFDE9DE0DD6F58801ULL, 
            0x6A1F5272FCF7E962ULL, 0x97A4BB15FB7C1AA3ULL, 0x06DF3694BCD93FA4ULL, 0x85540BDB22DD8890ULL, 
            0x4AF1BF1290B5495DULL, 0x0CBDEA2065B1A8E9ULL, 0xBD6FBE9ED122A9C0ULL, 0x5A52BDEAD8518F5FULL, 
            0x7DC8F1687C2F8E1DULL, 0x9494D3CD0279E285ULL, 0xA0EC39F02901660FULL, 0x438BC9C3E9E7917BULL, 
            0xA5D7DA3BC99C331DULL, 0x6B15B7FC42B96C70ULL, 0x813B08830851384EULL, 0x1F7B21467FCB972AULL, 
            0x233D09A88345C84EULL, 0xFA4C6D2ED49C011AULL, 0xCBEC811BD1D46D80ULL, 0x6C647D19457F299FULL, 
            0x74EFE85AF7CC27F7ULL, 0x3B36E94842A681EAULL, 0x89D897B2803CC74EULL, 0x9FE2D3E2307A0DA7ULL, 
            0xA4D81C6F82BEE6DAULL, 0xD495BDA8EFF2C7DEULL, 0xD26F0CCB2B6DF8F1ULL, 0x4B7065E7EC77F857ULL
        },
        {
            0xFEE76A5832E041DDULL, 0xC8D78FE4C34FC702ULL, 0xBC9F3B9870FA5180ULL, 0x154AFE120D8DD7D1ULL, 
            0x5F4BDDEF6CF02BD5ULL, 0x77F916E7C6AC05C3ULL, 0xF3EB24444AE17EE4ULL, 0x789AF70D319EA0C3ULL, 
            0x6D3049496A5FE3D5ULL, 0xE6650A2BB0736DC3ULL, 0x294A1A61EE36BDA0ULL, 0x95200FC0ACE32A6BULL, 
            0xD326D182DD478867ULL, 0x4EF7B390C9284336ULL, 0xBF8CEA1BB6C499CBULL, 0x4E10D689AFC41BFCULL, 
            0x8B70EC0BB9D33E83ULL, 0x38FEF3261873A356ULL, 0x13835ACF69B76882ULL, 0xD267046AF4F71C2AULL, 
            0x52DA7704558C788CULL, 0x290CF91022F3BA77ULL, 0xF78E0B60ADC0C790ULL, 0xB16D408DAD4391BCULL, 
            0xD50F8E42E20062FBULL, 0x9A3B59FED745643BULL, 0x29BABD2A5E4D6BDCULL, 0x1D02DEEE65BD467BULL, 
            0x860F424AAE5DD13EULL, 0xAD5847EAB99FD6A0ULL, 0xBFCEB7ED9CEE58A6ULL, 0x500A800764139677ULL
        },
        {
            0x6E24E05BBAE943D6ULL, 0x6D4B1E40976FA1A2ULL, 0xACA407167D538B3BULL, 0x3D4649D49E94960EULL, 
            0xF38417AE5C778FB8ULL, 0xF395CBFD265AE17DULL, 0x236C2B599A659D6CULL, 0x847D4C1784821F1AULL, 
            0x98E282FA0CDE171DULL, 0x75F533892B38B35CULL, 0x69B098125469CAC4ULL, 0x8B98DDEC204802E2ULL, 
            0x7C2571170F1FDBFBULL, 0xE0BB92B2CAECCDEBULL, 0xD42560C3B960CF62ULL, 0x610E228FBB461ED0ULL, 
            0x036E0702F037369DULL, 0x6921426BA3039980ULL, 0xE27C56F38971A28DULL, 0xC8B33FAC23CFF55DULL, 
            0xEDC8612B20D233EEULL, 0xE021372F47917895ULL, 0x2A2AC7C2D5E9E668ULL, 0x2436C26F550E14B1ULL, 
            0x42443791D5084535ULL, 0xCAF4996EEE303353ULL, 0x39B92B539FD7101CULL, 0xB3B9C8F09A64A954ULL, 
            0x3FAB95CB91915BD7ULL, 0x47B1AADA3481009EULL, 0x9EEC50FC1CB0BC43ULL, 0xCBDF1EBD245043F7ULL
        },
        {
            0xF78F61F9BF39D8CDULL, 0x2CF58B926CA79BD0ULL, 0x37A2C64118825822ULL, 0xFA36B7AF3DD03B69ULL, 
            0x9102749413BF63F0ULL, 0x2209FE0A1D1EA72DULL, 0x30130858E0FA9577ULL, 0x0D7B8576281B1077ULL, 
            0xF0A6C69D0D901118ULL, 0x3DE8854ADE99AF19ULL, 0x9AE22F449C1B9366ULL, 0x040D5BDE1F9E7F4AULL, 
            0x77F76502BD8ED0A1ULL, 0x06B84C17040EFB67ULL, 0xA3D69EF91E621A8CULL, 0xC213C096BA12720AULL, 
            0x93E1F81B241FA359ULL, 0x6266794FE3A784FFULL, 0x7DE995204D7B7A0EULL, 0xB6286B0B80CDD781ULL, 
            0xEF8C70E54F489127ULL, 0x8DEF3F7A47DC0D3EULL, 0x173C72C8EEF81333ULL, 0xCEE4A380AC12FAF4ULL, 
            0xAC8742B18B86A44CULL, 0xD6115056CA709634ULL, 0xA4422B19B196EDB7ULL, 0x69EDB998EADC47F7ULL, 
            0x0F89FBF0C146303CULL, 0x7DCA634416D44A6AULL, 0xDD0F13DE70E5EC92ULL, 0xA929A51CB5239494ULL
        }
    },
    {
        {
            0xF4E5989A90DEBD63ULL, 0x30113908F76B9AA2ULL, 0xEAE9592E9F715B89ULL, 0x82E4ED237383E9E3ULL, 
            0xE37B528F8F2B7D16ULL, 0xF5BE24CF4932516AULL, 0x078396027D08DA40ULL, 0xDCEE3F3E0EF5E877ULL, 
            0xEBA3C22355EA8C76ULL, 0xDE6C02DD1C4CA5DFULL, 0xF96B6CB9A7788552ULL, 0x310ACB8223923483ULL, 
            0x98B5F2BA5C3CF443ULL, 0xB531E48597719DE2ULL, 0xB6E6E0E5F0C1492DULL, 0xC157DCE7C076D475ULL, 
            0x873CA9A93AD1043AULL, 0x9043480D9225EF3BULL, 0x488E737E7A32488AULL, 0xB2E986268D0890D9ULL, 
            0xC6BF25AE3BFCE139ULL, 0x85632C3A02BE1643ULL, 0x454EA68487EBB969ULL, 0xAE906ED555993F01ULL, 
            0x4486FB10E7B6C1F4ULL, 0x91B66D2A08498910ULL, 0x81494EBA3239F959ULL, 0xCFCAED6B4E97B404ULL, 
            0xEF51AFFC91D26B83ULL, 0x57DA4B124DEFBFC2ULL, 0xFD043133FF974568ULL, 0x2565ACC3D96ED6C2ULL
        },
        {
            0x916459517EABC1CCULL, 0x28174123CC728C84ULL, 0x8BE8CFCFC28E7448ULL, 0x4EEF2F57F6CAD252ULL, 
            0xF4A514D04430B50EULL, 0x931D8E0645CBC52CULL, 0x5C14E13F9EA7C37FULL, 0xF84776387C2AAD7FULL, 
            0x7E54B29CC2701EB8ULL, 0xD41BDBDB5B42389BULL, 0x1764EE7916F55208ULL, 0x83F7D597A5D95A0AULL, 
            0x27BF2A0A2EF9E1A7ULL, 0xF549D619A4D7768AULL, 0x389AEC6543F975A5ULL, 0x8F5CF2787567D609ULL, 
            0x875D88E1C5E811E5ULL, 0x0DCF8707A1A2BD54ULL, 0xA424AED44637F3EDULL, 0x38CEB926EA645A24ULL, 
            0xDB3722F44B6787EAULL, 0x9BB613824875A942ULL, 0x548A418636002515ULL, 0xCBE38045B8851960ULL, 
            0x3A092BCA7291336EULL, 0xB74A0948AB850C55ULL, 0xBC7EF87E350C674FULL, 0x61E74B6E9D9EA6D7ULL, 
            0xEB86FFB572A1EDBFULL, 0xFD49353D559239BBULL, 0xBDCE344306A00142ULL, 0x786836528F329D23ULL
        },
        {
            0x4F5ACE5E62272F59ULL, 0x41705284537A3653ULL, 0x27327399BF7AFCE0ULL, 0x6743FE68A7B192F3ULL, 
            0x5F164D3643848919ULL, 0x5D1305C2A380E027ULL, 0xDB4BC44CD4186827ULL, 0x161F333A55207E16ULL, 
            0xB6D3F0DB883C9AD5ULL, 0x59942056F1D861E9ULL, 0x8D826AC4482939E8ULL, 0x05DD5ED2AC166857ULL, 
            0x2187D03DE5EC419EULL, 0x0481B3A65EB0A81EULL, 0x3AA3C96103CBE141ULL, 0x435C921C91FAC569ULL, 
            0x6584F896176DAEA0ULL, 0xA11489A755F8D14FULL, 0xC8CE86E0FDCD9642ULL, 0x3AE269D2E2C5468EULL, 
            0x0318AA9C9E5FE7BBULL, 0x1237C3FB1AD07D59ULL, 0x8279CE9757D8188EULL, 0xEA03AB8577D206B0ULL, 
            0x6FC8834A5111A2F3ULL, 0x2A3166F1CD5968F9ULL, 0xC9A3981EF7C695FAULL, 0xC48027B4A8D7D9B4ULL, 
            0xE2AB904AC8821E69ULL, 0xDDC46278CB97EDCDULL, 0x4D3E95781ADF59CDULL, 0xB2A10F900B9C1E34ULL
        },
        {
            0x97CB93999F625C35ULL, 0x19FE50F5527072E8ULL, 0xB300DBE88DDD0243ULL, 0x54E92B766312AE4EULL, 
            0xF3EFF4F67BE137ACULL, 0x58DBF40F7B9FD60BULL, 0x7A2C50EE20A0EB8DULL, 0x7095D715A7DD95AEULL, 
            0x3569E3FBC5B5D38CULL, 0xE513137DFA03AFBDULL, 0x03CEBBE50B88D413ULL, 0x35DF37CEC42FA9FDULL, 
            0xF100702EA8FDDFA1ULL, 0x254FFFC0EC0F6705ULL, 0xEA76E73A9E6AF939ULL, 0x08509D575B6117D7ULL, 
            0x823AA47F33CD747FULL, 0x14C727502C69325BULL, 0xD2EF6075FA581B97ULL, 0x4880704521C7AC08ULL, 
            0xE579AE91ABCE12A0ULL, 0xBC8C0FF2DAF190F7ULL, 0x35D2E50883B05C66ULL, 0x390591F88A78E99EULL, 
            0x6FE1035AA28CBF4CULL, 0x6CF9810B357FDC31ULL, 0x59E3B1DE50D95D1CULL, 0x9FC33A18A052A4F5ULL, 
            0xD190EF83C7319D07ULL, 0xA9B4C799425FC8BCULL, 0xC502EEADE6B31249ULL, 0xD11FABCE24C1179FULL
        },
        {
            0x54976BF9AA2B8514ULL, 0xA4BEE946EBF2F745ULL, 0x09820B2786E9278DULL, 0x80D7F1E5D30CA1CDULL, 
            0xE74AFC6094E43AE9ULL, 0xBECC7102F0BD4BB4ULL, 0xBA6165960A4CA0AEULL, 0x2AC08930D4875D24ULL, 
            0x1550507E0C9A5D9CULL, 0xD2834B591534DD54ULL, 0x285C043C105F0C90ULL, 0x6ADAFEEF8DB79965ULL, 
            0x8EBD2DDF94C999E7ULL, 0x415AE554FC012D7DULL, 0x15B820E9FB904E07ULL, 0x8EF509EEF9C7F13AULL, 
            0xE6C97346323C34A2ULL, 0x8C5D9980665E92A3ULL, 0xCE5B0BAF64AD230AULL, 0xDAB8B15C0E21D0C4ULL, 
            0xDBC76C703083B1A8ULL, 0x22583BA7898B4EC8ULL, 0x2D66FAB8541E4226ULL, 0x493413A0A974777FULL, 
            0x3A8F108D6C464694ULL, 0x94D11A1634D46107ULL, 0x0A4043E1A027E50CULL, 0xC8B8A2DB5AEA89F8ULL, 
            0x251B13857FF7F7CEULL, 0x4C1F185463628CA4ULL, 0x02505EA39DCF3C7EULL, 0x850C73FAE141D3C0ULL
        },
        {
            0x9D43F757CF197BBEULL, 0xABDAB8AE1359F891ULL, 0xBD177C154E5812FCULL, 0xFBFB455557589E2EULL, 
            0x4B880A1803C8962AULL, 0x2B4BA5AC5865C435ULL, 0x0D9A771F460AAFDEULL, 0x9DF788B5D423FB76ULL, 
            0x46A7A1009F99CA2AULL, 0x6C029EA62CF29F1EULL, 0x5ECAA16979FF5FCEULL, 0xF91237FFE323094DULL, 
            0xD73D1122DC1EA2DCULL, 0xC25A562B4D745842ULL, 0x8988751B90BAE98BULL, 0x13E7E84EBAFDC9B5ULL, 
            0xD63C07BAE6A5C5CEULL, 0xC7C619866D371BCDULL, 0x8A73E1AA8768A6B6ULL, 0x505FEFE3AABA67CEULL, 
            0xB685B6764ADE9E10ULL, 0xA3858E4B73272500ULL, 0x23E2344C3FA77FBFULL, 0xF725E1419E6E0B5AULL, 
            0xBA7038AEBACBB67BULL, 0x39D3101EBCF61303ULL, 0x0E22D20983122020ULL, 0xA902DF86260D5DFFULL, 
            0x265057B74BE77596ULL, 0xB57C5A467BE8C25CULL, 0x063FB957474D4805ULL, 0x1E9F6F7E507A7F50ULL
        }
    },
    {
        {
            0x7DC5C3237FF231B9ULL, 0xDDE495FD5E8C34FFULL, 0x3EC5E2A2EED66A9EULL, 0x77CEEFADE9CA83CAULL, 
            0x4E401B4FAFD5EFC8ULL, 0x9953AD26FED52239ULL, 0x525B6614DA790DBEULL, 0xEACD93CD8D81AFE7ULL, 
            0x0DEF0B2C64369E4BULL, 0xFD7FC28ECD582799ULL, 0xD3B942A79469706CULL, 0xEAF4F5CDF3998BAEULL, 
            0xE3573F2652E7C11EULL, 0xC61789F633817DC1ULL, 0xC218EB330C5FA502ULL, 0x3EA74F5514ECE75FULL, 
            0x73ABC9717F516AB8ULL, 0xB8019BB2B66B531BULL, 0x58E27AC2C67CBAA5ULL, 0xAEFB5D2ACA2BBE38ULL, 
            0x75DCE47B369F11C7ULL, 0xC149DC5E0FE3D7FFULL, 0x73B28D1996999914ULL, 0x25B0A854C7E47DCDULL, 
            0x9155CE43093B3EF5ULL, 0xCC5345A5C10D3529ULL, 0xDBD45BBC308E1EE5ULL, 0xF5195297A4525E11ULL, 
            0x7ED64E449FE30711ULL, 0xBA2D57F642B1333EULL, 0x9F14B18C8CAD09BCULL, 0xF77ED3F97E4CB14AULL
        },
        {
            0xBEF43DE20C368B99ULL, 0xCC66A2C98B21AC32ULL, 0x92B3BBCC36BE3BD5ULL, 0xDC20F7B5F6F25F41ULL, 
            0x1B0874362EE777F1ULL, 0x21241A3260964AC2ULL, 0x93FC340680A1D220ULL, 0x1D1E21979FCACA5AULL, 
            0x349216E6D4176E7BULL, 0xF913EC43478FFF40ULL, 0x571619330F82E101ULL, 0xBFC882921DE2BA1CULL, 
            0x6EA5996E31049040ULL, 0x72C82D74B5B4AD33ULL, 0x88796AA6EC14AFAFULL, 0x3103BC07706622ABULL, 
            0xB3284024CD1E62F5ULL, 0xA0DABDF118DC6E5CULL, 0xCB65FCDD93B8CB0DULL, 0x731DC4D29466E74EULL, 
            0xB14838E36EBE6130ULL, 0x77B64414DED6F78EULL, 0x6B663A02AD6061A4ULL, 0x105A10582392D53FULL, 
            0x2B947369CB8D4B60ULL, 0x7EEA9B4F3BF35E6DULL, 0x05195BEE8270A2ABULL, 0x8756333EF4E97C80ULL, 
            0xEB28E6C0B036EA25ULL, 0xC7239600C0B6EC13ULL, 0xB2A868318B4EFE80ULL, 0x90D324150B42F782ULL
        },
        {
            0xD7887723146E2387ULL, 0x19B8C46DC8ABDC3EULL, 0xD08236B5F1B9F87EULL, 0xA6FD3DF694DCB025ULL, 
            0xEC4718178706FE24ULL, 0xC59552EA51293FF2ULL, 0xD30CB3BEE9F2D1B2ULL, 0x215FA83BBBB0E9A3ULL, 
            0xFF5099CDC5BA3579ULL, 0x8D8374B13B98D741ULL, 0xD084CA233DB90A8CULL, 0xC1573BE158CD4070ULL, 
            0x104943400A1F158FULL, 0xB16C72033710160BULL, 0xFE775943C8DB80C1ULL, 0xE5155D3F4A83F62EULL, 
            0xF1DF1EAA4CA8CB13ULL, 0x18AFCF4D275B5CCFULL, 0xF23522B74B7C13A5ULL, 0x28AF0067039890E2ULL, 
            0x31388DE5A7E69FD2ULL, 0xFE1AD5D9E42DB892ULL, 0xB4264BDF47B8AB2DULL, 0x8FBB3A136F3D7160ULL, 
            0xD5D4DB21BE48D275ULL, 0x6D02BF15382DF0C1ULL, 0x16B01E2DBEC80965ULL, 0x6AB0C965848C7DB6ULL, 
            0x6E231799CE3CC8BEULL, 0x664977446DE6E7D6ULL, 0x83E8751BB3EBE80CULL, 0xB4B4F5A84AEE432CULL
        },
        {
            0x59B72BD639F1B089ULL, 0x9467A66C7DF01282ULL, 0x2D5FAC70DF36C082ULL, 0xF2958738623AC27AULL, 
            0x267681A7C041AE25ULL, 0xCC9036264F7DCD3BULL, 0x1C38681AAC129520ULL, 0xA6E0AEB1D4C0BB3CULL, 
            0x4BDBD5C802022B1BULL, 0xEB131A9284D374B8ULL, 0x9596F824996B001BULL, 0x9519F5CD4BB27322ULL, 
            0xF7805E4B22CDEFC9ULL, 0xBA865F3CB71798E9ULL, 0xAB139B74102D6B90ULL, 0x3FC7C934A4ED0B69ULL, 
            0x51B353AD705C5251ULL, 0x6D71C02B88724F2EULL, 0xB8224D6E49D35BCCULL, 0xE1D3F9A6307A1FB1ULL, 
            0x77B941834672ED97ULL, 0x845178552DA50ACFULL, 0xFEEBFF17FD23E4F3ULL, 0x026F34D88915478EULL, 
            0xC1A57516C0D7503AULL, 0x652982EBECCF860BULL, 0xA25479FF9563E7F9ULL, 0x1E3DCBFAD03CB4DAULL, 
            0xB6B37957745DBACEULL, 0x8A03DF884EF8102AULL, 0xAC69BE418C1E83BBULL, 0xD2B8035084F2D434ULL
        },
        {
            0x216122E8F2F3E4BDULL, 0xC4A95CC2D801ECC8ULL, 0x13368A8DE721522FULL, 0x7A0050D958A381C3ULL, 
            0x84D3C02721F413BDULL, 0x538D113D91B05AF0ULL, 0xD856DCF917E12EFCULL, 0xC2CE4CC66CB057A9ULL, 
            0x34FCAEA11F000586ULL, 0x40F7B34CF42C44FCULL, 0x8F7F70A97A4EBE76ULL, 0xA81778F1A4BEF819ULL, 
            0xA89EEA5334F8CDE3ULL, 0x96123B6D6CB82071ULL, 0xA8E1586C0DB3BFA6ULL, 0xFC4D1FB2EB5EE7A5ULL, 
            0x7D5A2313DFB4754EULL, 0x09E33B837082DEABULL, 0x8241108D31EF8432ULL, 0xF15AFC4E1464A37BULL, 
            0x3AD59E8AC3E5A521ULL, 0x6C50D33A409D0FD4ULL, 0x37CCB73C0D00E8AFULL, 0x414DE54423ACD68AULL, 
            0x076491D5B76EBBA4ULL, 0xCB257C67E0F2FED2ULL, 0x55069DAFCE16860EULL, 0xD238394CD48406FFULL, 
            0xDDC3D5C13E07CD4AULL, 0x0873EA0F8354755DULL, 0x8BB93EEC179E0685ULL, 0x19140BDF7DEE2EDDULL
        },
        {
            0x7DDB99A66ED0A3F5ULL, 0x01E96B4667C60024ULL, 0xBDFBE1C51FB6CBA9ULL, 0xEEB6CE8E6C5A95B6ULL, 
            0xD4CEFE47B3C7EAA1ULL, 0x0BDA0D514703B071ULL, 0x47D991324F8F3EABULL, 0xD9FD42C896D3BE42ULL, 
            0x0B8291D02146C06DULL, 0x09B4D2631DC12CC2ULL, 0xA7375006C3E21B08ULL, 0x36B8E8E121D8A6D5ULL, 
            0x464CBB34495F3689ULL, 0xB9D1CDBDB073BC71ULL, 0x5C579916D709CDE6ULL, 0x41CDA1A72FCE105CULL, 
            0xE1AE8BD4DCD67A21ULL, 0xC8B149C310569496ULL, 0x4033C0D121281A55ULL, 0xBD54DBE8673FA081ULL, 
            0x219609384D1F19DCULL, 0x2C482C2D1FEDA4FEULL, 0x64BC0061A3767126ULL, 0x554B327AE9AC4710ULL, 
            0x2B4E9F79AA035F8AULL, 0x68BAFE92FCE30FC4ULL, 0x41BF095D8F3DBD8CULL, 0x4CB6E1DB8E9D688CULL, 
            0xAB91CB2E883BBC7FULL, 0x3390BA71AEF0358CULL, 0x8EB6E20B679D9854ULL, 0x6FB88230F1F547FAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseAConstants = {
    0x51E27C6A71F23208ULL,
    0x589E8C38B22182C2ULL,
    0x7ADA01810ACAB0B2ULL,
    0x51E27C6A71F23208ULL,
    0x589E8C38B22182C2ULL,
    0x7ADA01810ACAB0B2ULL,
    0x55612E4C7BC77B81ULL,
    0x53BC6638D03054C2ULL,
    0x03,
    0xBE,
    0x6A,
    0x4B,
    0x0C,
    0x7E,
    0xAD,
    0x0C
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseBSalts = {
    {
        {
            0x478C6264A56CF6A2ULL, 0xF16485EB1D8E533CULL, 0xCD5206E94518186CULL, 0x55A103385C551E49ULL, 
            0x24EA1ACF4AC0EB48ULL, 0x3C824AC8D010C865ULL, 0x1810FFDF4FE87259ULL, 0x51DEE8A005ACEE00ULL, 
            0xA3F217CE06F91D58ULL, 0x48890AD98F9FF4A9ULL, 0xE6F0764E237B4E87ULL, 0xAF280D1F2899F65AULL, 
            0x31D261EA6CCA1D2AULL, 0x0CC7669AFE5D11BDULL, 0x06A1FD85C579D4B1ULL, 0xC8048C9E1CF756F6ULL, 
            0x196E839B5BE0F7AAULL, 0x17A17F845EECD1C7ULL, 0x9A8F86E8628D75D0ULL, 0x91FB150974A28712ULL, 
            0x23BB0F3D894B5B57ULL, 0x2B6C868089BB90C2ULL, 0xE0D40C466D5ABC78ULL, 0x68827780F94DF9EAULL, 
            0x839BCDF92B1C3E00ULL, 0xCC4147636728A09AULL, 0x2386BD4A8077A459ULL, 0x53F0A2AC89D8B430ULL, 
            0xC8A5FEF9B122E3A6ULL, 0x9AAE7FF42C5ADDEEULL, 0xF6069617879BA025ULL, 0xF070038AD5D1EA49ULL
        },
        {
            0xD83308943C2BD23FULL, 0x549BA22185F41F43ULL, 0x996B330FDAB4F5F8ULL, 0x620103E8FE342868ULL, 
            0xDF8639E7E9B94CAAULL, 0xEEA4A4C1F25169D3ULL, 0x0A4304E798D33E82ULL, 0x313AE701686CEC94ULL, 
            0xA925E994450DA1BDULL, 0x5D5BBBAB9A4A81C6ULL, 0x3C0C49AB4E48D737ULL, 0xCD421091B3B80E06ULL, 
            0x229949864A058540ULL, 0x55954831E92EAAD3ULL, 0x1FC96BCE34E5D210ULL, 0x72321BD33A54E6F5ULL, 
            0x8A506FBA7154CA2CULL, 0x9E912B0345E35955ULL, 0x8C24496D6E29F635ULL, 0x3EDE25BD69DD9D9CULL, 
            0xB57A24FE11F1ED28ULL, 0xEE60958F838A52E0ULL, 0x1ECF11006D34F496ULL, 0x1E7A18D8F9D6263FULL, 
            0xF21DC903EC744252ULL, 0x523380D1EA2EF933ULL, 0xFB090016CCD6DA8CULL, 0xDD10CAD18EA6E630ULL, 
            0xFD31F2B4DFFFE80CULL, 0xC47792E81E10E37AULL, 0x1DADDE080B486410ULL, 0xEC1170C6C8248BC7ULL
        },
        {
            0x4CD0D81E12D64F53ULL, 0x0B35F297E6642492ULL, 0x4BAC76A736EE54B4ULL, 0xB08654025B6053BAULL, 
            0xA102F4D9CD3539B4ULL, 0xA9FC89B9B2554D22ULL, 0x1A2BBC7F7F06F591ULL, 0xB1CAC4CBBFAED2EEULL, 
            0x4B5BDF4521B4EAC2ULL, 0xF532792EA4FFEBB1ULL, 0x695D1D7396D6A712ULL, 0x252B700C04EC7202ULL, 
            0x90587F087629F344ULL, 0x43DB584002D6557DULL, 0xE30AEE3853AC8889ULL, 0x40A01BFB5FBCCE85ULL, 
            0x64C29F051992405FULL, 0xB887476DF4E49A9CULL, 0xA5BE77A137DD1D7BULL, 0x9C6C337E8A905D3AULL, 
            0x8C46AABF7C407788ULL, 0xCA9C98324D711375ULL, 0x4827F5748D13FE8BULL, 0xD3272F6573E0278DULL, 
            0x80E5BA7142DCA0CDULL, 0xBFBC4C5E5B1A22C6ULL, 0x6EBEED59838ADEFBULL, 0x7B49D15429233B5AULL, 
            0x2FD2B54EF8AC981AULL, 0xA04A2577CEC3E787ULL, 0x6D0C96BFBE3154B2ULL, 0xD23491996770BB7EULL
        },
        {
            0x370EB086E61E1061ULL, 0x284158B2E7FD0DE1ULL, 0xDAF8BBC4EA77A9CFULL, 0x98A15C76803D285CULL, 
            0xA1D64C6CB302BF8CULL, 0xDF52232B9382403CULL, 0xE543E99ACB42F027ULL, 0x71FC932C0BBECC9FULL, 
            0x25A8C37F6CBCC46AULL, 0xEA30929A8BF0053CULL, 0x05221C05B03B9E77ULL, 0x314669B5BAEA68BEULL, 
            0xCBE12A2D1E654A2EULL, 0xCEA74DF111683867ULL, 0xA2B932FF935AB48EULL, 0xE369FF9623D3E6E1ULL, 
            0x758A3098E36C5FD2ULL, 0xAA8DCA2509DCD1E6ULL, 0xFD1D2FF16E9957BAULL, 0x7B38522B618F0AF9ULL, 
            0x7C4761C548D6E003ULL, 0x9CD3D6FA42A204DFULL, 0x5678871E1B52251AULL, 0x60BF6A0E5DACD6E5ULL, 
            0xEAB0E251802526E7ULL, 0x202A708606C9D490ULL, 0xB195A0A84040FDD9ULL, 0x80924F479938A155ULL, 
            0x5A98A9C46227B6BBULL, 0x58AB881F25FB69C0ULL, 0x7D86E55478038D41ULL, 0xA772C439341B1611ULL
        },
        {
            0x88FBB02C32B3EDC9ULL, 0x8DD75E87E776D992ULL, 0x1874A5A174123370ULL, 0xD584BA02194B890EULL, 
            0x436DD008A733A441ULL, 0xAEFE36B7C31D946FULL, 0xA423D2B57CB25ABEULL, 0x46C65126598B1A04ULL, 
            0x1176B16EC7137FB1ULL, 0x76B24B980CAE0AA1ULL, 0x0C4E15568C5542DDULL, 0xAE21D3F8836FD39FULL, 
            0xC28E552C5168A778ULL, 0xE22E5C428A5381A0ULL, 0x27904EAA6EC2642CULL, 0xABCA63FAC0D8CAA1ULL, 
            0x8D3ED2E9C51F4530ULL, 0x442B225C5ED84B8AULL, 0x96F4AAEF560AC939ULL, 0xC016FFFFCE8F5471ULL, 
            0x6833C0894A904566ULL, 0x54EFD7E1ABB8B5CCULL, 0x53E64F8E341B4C27ULL, 0x1DDA62AB7F220171ULL, 
            0x7EFA196D693F6035ULL, 0xF5DC784EA6AF49BBULL, 0x02775D871C490336ULL, 0x0E5D88438737614CULL, 
            0x3F741F5E54CB1540ULL, 0xB792E3B575BB251DULL, 0xF2EFB0F5DC2240A1ULL, 0x536A1D79CF7FB9DBULL
        },
        {
            0x9D1F8DCB9BDEF449ULL, 0x11F8F4DF4E446435ULL, 0xB762212062A91477ULL, 0xFA68C427ED38D878ULL, 
            0x64EDE1DCAF327904ULL, 0xDE66C7989A5C58CFULL, 0x7AD89E971279953BULL, 0xF27C9BA7436A47EFULL, 
            0xEB9B314CC94DE4F4ULL, 0x56803B0C0DEFA9DEULL, 0xA41F63BDFFD56CD6ULL, 0x666739EB8C88799AULL, 
            0x6C2A1AA61B7E359CULL, 0x84201AA01E471471ULL, 0xD60A2A2DAC9C2759ULL, 0xAB0C2AACDF9BD371ULL, 
            0x85113AB73695E84DULL, 0x4A690172FA59BE05ULL, 0x260D5DB0970E0486ULL, 0x8E839DF1181AF527ULL, 
            0xDBB4DF152BAEAC1CULL, 0xEBB1C2F6027B8DFFULL, 0x63AEA2EA71420E13ULL, 0xCFEF5B17906F3500ULL, 
            0x700E374A4C13DE26ULL, 0x98BC0204B3491588ULL, 0x2DE9DD1D6EC60B89ULL, 0x7DE16DF54E3863EEULL, 
            0xFE17D0B127C888CBULL, 0xFE174251FB15C478ULL, 0xB2A95AF4F244C34AULL, 0xA2FC531F16DD873BULL
        }
    },
    {
        {
            0xA6BEF2FEA854FF55ULL, 0x467E386B8DDCACE4ULL, 0x8FDA6034EC6CBFBAULL, 0x664F3429D1EB5500ULL, 
            0xDD71AF4573531819ULL, 0xC183A4CE5379A84DULL, 0xE54C6223370C4740ULL, 0x5480919C7BAD07EAULL, 
            0x992BF39C07B68100ULL, 0x2CE2D1F13BC3A081ULL, 0x912FDB6085EF9891ULL, 0xF040D411549E4D9DULL, 
            0x1B2F4278C5B775D8ULL, 0x9B0C4E91776FDCA7ULL, 0x02B5CD93D86A11CDULL, 0xEE9373BC55EC0E2FULL, 
            0x8DB2FE3C74484C8AULL, 0x640E8A6FF14271A1ULL, 0x03CCEA1583570A5DULL, 0xA38787EDC5E4D7B4ULL, 
            0xA5B18BA509CA9AFFULL, 0x864D35C37B81DFAAULL, 0x5AF7EAA7470ACB21ULL, 0x0A7B142B8DCF9788ULL, 
            0x1423E710F4251F60ULL, 0x1B54DB03FDB7320CULL, 0xF687B095A8EEC61FULL, 0xDA4BD71801E64DBFULL, 
            0x000FA7D35FE1B1FEULL, 0x3809148EBC6BC7FCULL, 0x57D42F430A21724DULL, 0x21AAA4DBC961CD52ULL
        },
        {
            0x103B216D33208BF5ULL, 0xFA44BD057B6DBAF0ULL, 0x18A0CA079B15D9CFULL, 0x8BCD0E804BEB7FFFULL, 
            0x804D7B9CC4C4BC85ULL, 0x19C0960B770FEF23ULL, 0xA56E54ABBFA9D87BULL, 0x5CB97B12F20E22CFULL, 
            0xFD7D3E67FF5494EDULL, 0x6526890CF8309B14ULL, 0x1837D819057F4B46ULL, 0x964DB4EC2DCC561BULL, 
            0x1291FC39B88814DCULL, 0x5154D96FC7CBF1CEULL, 0xF63CA1799B11F3BDULL, 0x048C96C439682B94ULL, 
            0x6733C0C25A31E911ULL, 0x4637731661D9B159ULL, 0x1C0B77BE329538E6ULL, 0x412550CAA0083BBAULL, 
            0x56365188FEF66CA9ULL, 0x7F292541FE455AB9ULL, 0xD6B6AE3D38F8B68CULL, 0xF00AE40315D50E9FULL, 
            0x6F7A8A777FA942B6ULL, 0x8704F60E45EBB59AULL, 0x27660A624E1B4BC5ULL, 0x0281F9721DE11836ULL, 
            0x5876FF67D1463074ULL, 0xF5881FDCC1CC788FULL, 0x11B913D34EEE5BAEULL, 0x36181C5151627EB5ULL
        },
        {
            0xCF7BDB7D9743DC53ULL, 0x01C2787E22600942ULL, 0xACA0F23ED35A7AD4ULL, 0x563564E55F539990ULL, 
            0x96390D564D293A80ULL, 0x536F55217B670CC0ULL, 0xDCBFC0B61167CD24ULL, 0xF96E1686530E2CADULL, 
            0x9B06771AB6FF18DEULL, 0x002C08487F6B85FFULL, 0xF26F8889A805A7DCULL, 0x5E440612D028348EULL, 
            0xEBEDF6FBB58D8D71ULL, 0x474A6CA497062447ULL, 0xAC7CD6A1A2A8BD2EULL, 0x307460CF47695134ULL, 
            0xBCE757E4240003EAULL, 0x8A4D6532307D1FD4ULL, 0xA6962F3E9878065AULL, 0x624F70185C475EBDULL, 
            0x1449B9F2FB42E679ULL, 0x1DF6AA193872BFCEULL, 0x18653C345516F18BULL, 0xC167B7731092A23DULL, 
            0x9F09547251E53E29ULL, 0xCC724D8E683B0CD8ULL, 0x0BE97CAC5F9B5602ULL, 0xE30AB899471985F0ULL, 
            0x525A4E5C67857F49ULL, 0x2C98ED2C3F3B1239ULL, 0xBFE646227CD1E4F4ULL, 0x92DDF1BB0498BA72ULL
        },
        {
            0x843874E9650CC8C3ULL, 0x1573004FB42DB0ABULL, 0xCFC36BFE9E5AED55ULL, 0x9060FAC349F05D88ULL, 
            0x44E2A40F740CB7B1ULL, 0xA29F841B34E9FC90ULL, 0x705926E866765986ULL, 0x0C97D62A9BEAF40EULL, 
            0x7E16AC365D418EA4ULL, 0x80BB0F3EDDE9496DULL, 0x1F982041D274D1D2ULL, 0x90FD110FA616A21EULL, 
            0xD94865807399DFE6ULL, 0x74F80E2964B22722ULL, 0x3224FDB2EC352A03ULL, 0x8F639E23452320F0ULL, 
            0xEB105C910AF0E6E8ULL, 0x319EF6BF5A1F881CULL, 0x2FA4C79039FBFE14ULL, 0x2ABACDB1C130F4C6ULL, 
            0xBC79E89CDE3F9697ULL, 0x9A36F5B007429DDCULL, 0xE9D78925020C669CULL, 0x7F57ED635379D863ULL, 
            0x8B2E17C91FCF1C17ULL, 0x369796BA17C0A277ULL, 0x4A6D52A0579BE500ULL, 0xD8172E2CA47B1185ULL, 
            0x6A91241AC7F4D5B9ULL, 0xAABEFBE37FCBE616ULL, 0x2F351855B50EA5F3ULL, 0xEE1D0840B625210DULL
        },
        {
            0x5D3CFC7EC2DB98CEULL, 0x2066B518928EEC01ULL, 0x9DB86033AA2BB4A7ULL, 0xA59296FD4D213646ULL, 
            0xB6C457624698D2F1ULL, 0x705E84E648813934ULL, 0x90E0B3366CA83A86ULL, 0x609797A55E5E29E8ULL, 
            0x44A3C6C9E89E26B4ULL, 0x00A4EDEA4E2599EDULL, 0xC8D5B985CC08520EULL, 0x2B74CBD47B19F7CBULL, 
            0x319E41A8914FF367ULL, 0x28994A9EF201C7DCULL, 0x05A0C78AB4F47848ULL, 0xE74DF5F956C97D6DULL, 
            0x4A829FBC34E495C1ULL, 0xAB93B273D273FAA1ULL, 0x5C96E8AED2308381ULL, 0x502672C321036EACULL, 
            0x7B97D75B3559ED8FULL, 0xEDB17DB04E029C01ULL, 0x69A1E876862A6DF2ULL, 0x8872698DC0F0A590ULL, 
            0xE77D5A07041A1001ULL, 0xFFA2461023374193ULL, 0x3752233C38846F3BULL, 0x25F6FF0E46DCEBDFULL, 
            0xC85278C213F34EFBULL, 0x9E3699FE2AD35DCAULL, 0xAB48271EE22D5BFBULL, 0xF5D799D72B003556ULL
        },
        {
            0xEEAAA22A62D20348ULL, 0x03805D6EA5E37E04ULL, 0x99E958D5E3824AE7ULL, 0xFB18918CE4DA2210ULL, 
            0xB1E0366BD5EAFE70ULL, 0x5581ADF10F33EC58ULL, 0x768468F53589671AULL, 0x2D2A8A37B38D7602ULL, 
            0x3B63FC9572BAFEB2ULL, 0x565A7CD15B250ECFULL, 0xC29B0B7C8A67A5DBULL, 0x8188C919862B9818ULL, 
            0xA4255EA4F4D29F8CULL, 0x693850FEE9573AF4ULL, 0xF8336EECA6BF3746ULL, 0xA43ACDA8BAC16E7EULL, 
            0xE721676632236843ULL, 0x6B47B6D098161DBDULL, 0xE0F7C0154546FF04ULL, 0x6CCCE63D3446B6F3ULL, 
            0xF7049904706D8012ULL, 0xD0A6EA58CDEFF183ULL, 0x7F97731996D2636EULL, 0xF8CB77C3D20F598FULL, 
            0xD4935BA5391B8DABULL, 0xB28F19DBE9184667ULL, 0x6ADBA14433DB2472ULL, 0xA88A53357C2823A1ULL, 
            0x97B29CE5DB4D762BULL, 0x9E890F3FE1CF458AULL, 0x9CCD15B3A23F720BULL, 0xFE8365FFD1861B54ULL
        }
    },
    {
        {
            0xC67593C748853A24ULL, 0x162047FA7ABF5BC1ULL, 0x6C1A96B1766D5054ULL, 0x16579885233DCB28ULL, 
            0xCB5371A73A0C5BBEULL, 0x0DA636B77B0C3DD9ULL, 0x33256C55EC6D0FD5ULL, 0x3A9675C7DF30B2CCULL, 
            0xE863987E4AE2C13AULL, 0x79510E06B4EC0859ULL, 0xC6BD0B8D82FAD503ULL, 0x6B7777E182098341ULL, 
            0x51B806821DDFFCC2ULL, 0xE0E2454EF8FEDE41ULL, 0xD9B3F898B962E7A5ULL, 0x313260D0BDBA6641ULL, 
            0x1734F4649B4E887DULL, 0x3DC4631E8C8918E3ULL, 0xBACFD9C113713881ULL, 0xD4986B61045F6572ULL, 
            0xAE4D9CD06E8C6CD3ULL, 0x3101AD8BE093BF11ULL, 0x32AAA4A93B8FFC32ULL, 0xBF948FFBAC31D996ULL, 
            0x2E4E0FD8CCC4A29CULL, 0x2D93E6315840DCBAULL, 0x5AA12F41AF608010ULL, 0x32C9663992FA1EB0ULL, 
            0xEF0543BE7EC16B2CULL, 0xE50B5AC78B54DACEULL, 0xC30D9C5F51EA5DBDULL, 0xC4ACBE86EA14A376ULL
        },
        {
            0x86539BF54A8B7F41ULL, 0x70F683401162DC5CULL, 0x6A5CD4339A03AA90ULL, 0x27153B0285A7720EULL, 
            0x608737FCA4246574ULL, 0x87549CC8EB64196DULL, 0xB97866A22B48A937ULL, 0x70F018C7B50D2225ULL, 
            0xC3FCADC9AF858C49ULL, 0x341C792314EAE463ULL, 0x4B4D46BBFD28CC46ULL, 0x2FFA417BF9CC1293ULL, 
            0x45DE1BDF57C64FA2ULL, 0x0FB3BF8CC6F4072AULL, 0xF0FF1C40B7E25C30ULL, 0x0744E2A8F708CAC3ULL, 
            0x2F88C6C47F3EFF2AULL, 0x30B5C8430236E81BULL, 0x6BE2CFCD4F25ECF6ULL, 0xB8E9A76B78CF6A02ULL, 
            0x9A36F03D75CDD0EBULL, 0x9B115423E9573F37ULL, 0xBDEBEFE2458281B4ULL, 0xFB0E10587B4308EFULL, 
            0xBB2F02A5F1D1EC39ULL, 0x763DD5FFFE985A8BULL, 0x451E229E73015608ULL, 0x18EF7679880B24FBULL, 
            0xD39A793FB61BD32DULL, 0x282621F100104476ULL, 0x1775E5DA8CC05D00ULL, 0xF995C04FFD066B3EULL
        },
        {
            0xD4BEAA8002BE765CULL, 0x51404DAAD116B5C7ULL, 0x162648F82B2464E0ULL, 0xD5B96A36535A54D3ULL, 
            0x147DA5DB76BFA2E9ULL, 0x77AD8D25343BC732ULL, 0xCF23712406C708F4ULL, 0xD973A5E654072898ULL, 
            0xDAF45F35FF183782ULL, 0xB0FD2F81DE32B415ULL, 0x9336929B7A16CEACULL, 0xF924BD24D048A13AULL, 
            0xD8191FB081FE9BCAULL, 0x5DBB3725EED00E43ULL, 0xAA7985F9661E10A3ULL, 0xD693A8F1BD83FA0BULL, 
            0x193231D8AF66B6DBULL, 0x41F1B7D18701CBE7ULL, 0x09F1825B3D6C97ABULL, 0x7E9748263C904515ULL, 
            0xAF771E8A24B2CE0CULL, 0xF16CD8496D9AA67DULL, 0x9D7726ADBB93D7B1ULL, 0xC447B3BF56A205C3ULL, 
            0x4072B4646F3855FDULL, 0xCA8B4EBA2EBB01A0ULL, 0x47EDBE6F352F6CDFULL, 0xDC126CF32025B2C9ULL, 
            0x769013A17FE027E9ULL, 0x9CCA727995809953ULL, 0xA15CDBE9F827C53FULL, 0xCA33391BE947A18BULL
        },
        {
            0xBEE26CD9B0B06454ULL, 0x860670E3D0654AA1ULL, 0x3ADA76FFDB52DA71ULL, 0x1D2B0E654F598E5CULL, 
            0x7A4009316D31E170ULL, 0x533FD8513F8EF78DULL, 0xFE423A18DCB6D73EULL, 0x1C2EF7960363D262ULL, 
            0x672FC7326D9848A0ULL, 0xE9643560F10CCC5BULL, 0x47EFA4243D09BE93ULL, 0x188C6B3A27E0F57DULL, 
            0xDCA8FC6119549B83ULL, 0xB324F0753776E3B8ULL, 0x29A3A4FD53A1FD9DULL, 0xCFA5D834BCFA62C1ULL, 
            0xCA012130AD925758ULL, 0xF0008AE3F214AA54ULL, 0x2FD2F39AE19C8F34ULL, 0x2E86F2777ED0B91DULL, 
            0x7C152D8BCDA13131ULL, 0x6E26224370B94BFFULL, 0xA8EC5956D6344DA8ULL, 0xDA1B0AAAD9B63DD0ULL, 
            0x70111FED81588B1BULL, 0x296ECE6C181E652FULL, 0xF6EB2260D17D544BULL, 0x44384F797861EECAULL, 
            0xAB19DAA3E5A09979ULL, 0xB7B942350D66045FULL, 0x0DC7CBFFE68498A8ULL, 0x6FC47284B0BE8B40ULL
        },
        {
            0x377B05008AC9B4FBULL, 0x3EE3BC68184397CEULL, 0x37A998D7B5BA62E1ULL, 0x1C894BC81901302BULL, 
            0x5B0D94F0DCB85510ULL, 0x613FDBE366AAC46DULL, 0xBACD1ACC284775C2ULL, 0xD5E22740357266CCULL, 
            0x8D7EFE2DC201A573ULL, 0x7389854FB82683FCULL, 0xE5E3DBE62EB85C7FULL, 0x050427A97FBA6952ULL, 
            0x0F8D28E7E9CD9D43ULL, 0x78F539BA163095E8ULL, 0x9A75BF38FB22275FULL, 0x99AE7809C7C2E1D0ULL, 
            0x871B3C813C195F3AULL, 0xDB0A17C49B07AF01ULL, 0x83C5D995CA269FD6ULL, 0x2CD950341634C9CAULL, 
            0x795D0CD885DE5B35ULL, 0x53FE7E7C3C0A9C98ULL, 0x0F0893554CD596C0ULL, 0x89D2607AC4EE7C6DULL, 
            0x447D85DC38DE31E1ULL, 0xDA663D0E04548904ULL, 0x42657311EFEB5292ULL, 0x5E1A113E436E5BE8ULL, 
            0x7FEBC80B4F94F9B9ULL, 0x18AA6DB93A3D36D9ULL, 0x5215E5A5F14B0EB4ULL, 0xC74AE7E3335FF35BULL
        },
        {
            0x5FD48765C70B46ABULL, 0xE8A6ADD393E54826ULL, 0x7704C90D148DBE70ULL, 0x684E4C96E033D3D2ULL, 
            0x6E5A82C175E92269ULL, 0x41577F52CF1CB831ULL, 0x659FE76BC5264A71ULL, 0xD6D595812EC30A69ULL, 
            0xE87FDFC6D2F2D551ULL, 0x6F710A245D2697D9ULL, 0x18265AB9445C3F19ULL, 0x1F005FD1D3DA249FULL, 
            0x6A255F6587BE899DULL, 0xD349B1B92EEFBC83ULL, 0x3163999E0C4E9D73ULL, 0x4C40866D5B5404A8ULL, 
            0xD7070A1C839B809DULL, 0x3542A752B74D3E2EULL, 0xDE2D9A61E0083A99ULL, 0x4C9C6D8519B28E73ULL, 
            0x6E635EFC7D909E45ULL, 0x639679342596CFC9ULL, 0x2254F5205E04D9FBULL, 0x096D847A73C13E20ULL, 
            0xA54ADA54A2D507DEULL, 0xC0E00B3F770CDF48ULL, 0x6561FD699E11B6C6ULL, 0xDF824993F8CCBFA8ULL, 
            0x3890CE5B60F72C57ULL, 0x1315ABB05E2DF4B3ULL, 0xB525CDA915CEAFA7ULL, 0x8EDCC4A8903EF040ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseBConstants = {
    0xC865E379EADC713FULL,
    0xFD1C8CDB910B4E95ULL,
    0x7B1130D671797ACCULL,
    0xC865E379EADC713FULL,
    0xFD1C8CDB910B4E95ULL,
    0x7B1130D671797ACCULL,
    0x191ED457D7AE40BCULL,
    0x06CF0C061B8C9205ULL,
    0x72,
    0x61,
    0x48,
    0x35,
    0xE5,
    0x3F,
    0x1C,
    0x6F
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseCSalts = {
    {
        {
            0x7457513F13957CFCULL, 0x586A2109EB2B409AULL, 0xD602EBF6A2B38905ULL, 0x106CC3168681D1B6ULL, 
            0x26EFFE222979664EULL, 0x215B087B1F9D5D75ULL, 0x8AB3095E2C5E22FBULL, 0xE4E05F3863334A91ULL, 
            0x7DAB106061C396BDULL, 0x38C98F9E6BC05295ULL, 0xEB419458EE50B131ULL, 0x86A125404AEAE48DULL, 
            0x67B615C82A0BA710ULL, 0x2BE56D4B0BA9445AULL, 0x76606F77A0F3CE5CULL, 0x9733F540A8C56108ULL, 
            0x44288AC6F6A28DEBULL, 0x2CDABA1B031DBC68ULL, 0xDAD3411C8228EE47ULL, 0x1E638B4E79741C6DULL, 
            0x04F8D004B9A452DBULL, 0x0E23A036CC77B99DULL, 0xA994A824C78EFE50ULL, 0x15F3E9BB6C521B2FULL, 
            0x28F1B940217307A9ULL, 0x65EC2A2F9315AD2DULL, 0x47F153694DA196AFULL, 0x0084138E61AC7B6BULL, 
            0x07C53F2D78BE351CULL, 0x9FC484A6F1513369ULL, 0xE3A5F684B2265BBDULL, 0xBCBC0CD9AD7426F8ULL
        },
        {
            0x9430CCF424B06C40ULL, 0x3E22F55752524281ULL, 0x0FFC33CF3A03E1C9ULL, 0xC5D3BC7F8B019406ULL, 
            0x28231AD00E8B10A9ULL, 0xA84158AF8A22C52EULL, 0xAAC11743110B0E84ULL, 0xD37C2582C036A640ULL, 
            0xFC809A4221688B9BULL, 0x58560B37D0072162ULL, 0x6407981AE7BB2ADFULL, 0xC11A3179B74E0700ULL, 
            0x629F481786CA221EULL, 0x08BDF74E2CA4AED3ULL, 0x1346F7190742706CULL, 0x20FFD8D0312C00D2ULL, 
            0x2066825F0C9B4850ULL, 0xF73434DE93FAE2ADULL, 0x6B9E5F8FEF7AA585ULL, 0x3AF562C8818BB867ULL, 
            0x10996C6CF6322EA0ULL, 0x31AA3A8C2DE32E51ULL, 0x629C7C23007A3CDEULL, 0x995A0396C6FC8401ULL, 
            0x05FA09C3D374ABAFULL, 0x01AE3A81F6480060ULL, 0x719C2AA40DE1DC09ULL, 0xBEBA2B5B3E847AA7ULL, 
            0x95184FA0CDF29262ULL, 0x3856EC28CA806B8DULL, 0xE9F9B0BD9089C3DBULL, 0x15D463F6A66CCAE5ULL
        },
        {
            0x4D1DE8D7C2617FA5ULL, 0x9111D5F25C7F5073ULL, 0x8C2F64184A19CC34ULL, 0xE546169FC349AF2DULL, 
            0x517C576A366E3D4EULL, 0x4338B0DACCEE24CBULL, 0x5ED7B0B3306DA6F7ULL, 0x4166DA3398B7BEBDULL, 
            0x1712A8271CB9EE5AULL, 0x078A9AD72AC830B3ULL, 0x815BAD099688B582ULL, 0x0891240836A8EE2EULL, 
            0x4244B588BE98E379ULL, 0x75ACB9D1C1C58188ULL, 0xBD55C4755718700FULL, 0x8F8582E7EE3D88D8ULL, 
            0x283EDD7E2DEF9971ULL, 0x9E7DBB79E5A92AB6ULL, 0xE9C45BE38C2E48F7ULL, 0xE6236A939E4B0156ULL, 
            0x33B5A8273824C842ULL, 0x18267FC487C0340BULL, 0x0E2AAE68F3AD8AF3ULL, 0xEDE4C302A10DEE8FULL, 
            0xB99D18745798CCB8ULL, 0x2C0F64672D1EC57BULL, 0x55BDAB0214A149EDULL, 0x50962BE1AD58A7D8ULL, 
            0xEBC97B616991AAF4ULL, 0x72E7AF4B7089C39BULL, 0xE618411B049A4E2EULL, 0xBEF67954FA6FFD71ULL
        },
        {
            0x7ACC6E39D85FC632ULL, 0xB38F7E52E7604C47ULL, 0x43620F1906AE2961ULL, 0xD996994D29AB9AAAULL, 
            0x4831D0DE2237BC90ULL, 0xA5B9C64D1DE59496ULL, 0x258BBB1B1EA48A62ULL, 0x00115F82BA215FE8ULL, 
            0x784C5DEF1920B89BULL, 0xC47D23881D42D21AULL, 0x7A7C75BED41220C9ULL, 0xDEE6C2980B66FA94ULL, 
            0xFA53226B2300678DULL, 0x28F09EA77F791F9AULL, 0xC302CFF3572D8441ULL, 0x016FF1438ED86886ULL, 
            0x19C0156F66C55FD0ULL, 0x07D9DF0435AD2B33ULL, 0x3C6D89DD2CB7C3B0ULL, 0xBEAE4DE3C160A97EULL, 
            0xA0A7475811F4990AULL, 0xFCF069C8C3CB9DF6ULL, 0x381A511CD5E4E839ULL, 0xAB36D39C462176ECULL, 
            0x40B7241C7399D1ECULL, 0x40F5A2D24ADE0AA0ULL, 0x0906D2CC6FBEC272ULL, 0x581ECA906EB36A05ULL, 
            0x911AA4C1AEA11B7FULL, 0x51C33E112FF37F05ULL, 0xB32F7106531D1325ULL, 0x4DD44E23C57FEC78ULL
        },
        {
            0xA3E63F1D3F2F9C18ULL, 0x79EEECD1E7F121EAULL, 0xD94A0CA0950DC9D7ULL, 0x0B96581D948F60C6ULL, 
            0x6D37CE6A0CBDBFCEULL, 0x999C2342B43084ADULL, 0x94D36D418E32A94EULL, 0x9CA915D63845EFC6ULL, 
            0xFE373CC9C453DEDBULL, 0x5D14401096BEEFCFULL, 0x1B5C0581C290820AULL, 0x27F3EFFCD2D96037ULL, 
            0xDC899EAB7EF40607ULL, 0xAB11C90DA93D22ACULL, 0x23BA8127A814B2BEULL, 0x4660B001AA8482C7ULL, 
            0x6D4BAA52C4BC72E8ULL, 0x5ACDF1CF28700CEEULL, 0x97F9C48FC2DDF785ULL, 0xEADF70EDBE75A18BULL, 
            0x706905F57A974F73ULL, 0x15EAA33D1760CFA0ULL, 0x0C7A69A962C1F634ULL, 0xF410107183BBBC94ULL, 
            0xF929CB449381B823ULL, 0xA9C53457D81C062BULL, 0xEB3C3C9472E63120ULL, 0xA9049980B23B2E55ULL, 
            0x7B47E2E69DD1DE31ULL, 0x2ABC4AE972B99AE0ULL, 0xA1E3C003969D12F1ULL, 0x7FC375318F490458ULL
        },
        {
            0x652685F9A8BE582DULL, 0xD910A06DA56D4F8BULL, 0x2CD398440A12E15EULL, 0xDA3304F4D8F50545ULL, 
            0x283A02629F1D0300ULL, 0xF501476615B86138ULL, 0x67F14461CF206C65ULL, 0xFA95E85E654C205BULL, 
            0x2BB72471E59AE9E9ULL, 0xEA6B796E1B3C0923ULL, 0xA6E86CA578717E2DULL, 0xF1F9ABA0ACB5138AULL, 
            0x5CD86A75C088E9BAULL, 0x11A7892957249179ULL, 0xBE11D3015F1FAC0FULL, 0x84CB362C3ED244BEULL, 
            0x3E3DF50639B64B88ULL, 0xBC7928279D1507AEULL, 0x0105DEEED7D4FBDAULL, 0xC5DF6748209EC242ULL, 
            0x677DF2BF60252626ULL, 0xAAD4B582B6DC4CE2ULL, 0x3F7500664B00D2B6ULL, 0x4D86572BEFF38D47ULL, 
            0x9F7A9E0A565CE8F1ULL, 0x88844670251F4794ULL, 0x5C345CDF6F9A60DEULL, 0x54E1CBE972DA133CULL, 
            0xA7D8EB05E37E15FBULL, 0x12B980D8A1D4B24BULL, 0x6B7B576F0FCDF2CDULL, 0x751B27EE3E9D3202ULL
        }
    },
    {
        {
            0x95F0C9D8ABC8CA51ULL, 0x81B5AEE1A0E10B44ULL, 0x0AB710DAC981360EULL, 0x49314705367CDF45ULL, 
            0xFE7063B6B13A93F6ULL, 0x1A40C23D7C236642ULL, 0x51946E7C99EAD583ULL, 0xAF5EEE5E67879166ULL, 
            0x4CBD71CFDACA9CD9ULL, 0x8EE5ED87CB3EA7BCULL, 0x51191BB1091511E2ULL, 0xB42F96C73E489107ULL, 
            0xBB4E5041F7545E95ULL, 0xA1704A9A16C20963ULL, 0x145137B8D72197E3ULL, 0x642409A7E873F064ULL, 
            0x4762243B3F5D4662ULL, 0xA9C761688E6CEC82ULL, 0x27D667804EDB9951ULL, 0xE92F85BD25E18949ULL, 
            0x18AB544173800FFBULL, 0x8838D36AC29B9810ULL, 0xFC183EE962CAFF7FULL, 0xB1DD107ABE74E291ULL, 
            0xC35455700FAF0F71ULL, 0xC275EF70B6C88AA5ULL, 0xDE5D66966F93738EULL, 0x2B494F7171908593ULL, 
            0x3CF8AA315BC476C1ULL, 0xDB7375C745898E2DULL, 0xA36CD30D80CA1AECULL, 0x7FA7AD0F9085D543ULL
        },
        {
            0xE876746C2D67F770ULL, 0xBDDF1974F1BB0599ULL, 0xD9D14E95FCFCD60FULL, 0x26F526FDA264B475ULL, 
            0xB5F4E39351B8F06DULL, 0xD8B9FFF21EB5566FULL, 0xA731289E2835EC54ULL, 0x5251A05A1E19C6DBULL, 
            0x1A6E04FFA8C1DD4CULL, 0x7C05FE915657B6A2ULL, 0x04008B2E3F34256FULL, 0x461D0FBE067B76B3ULL, 
            0x4A13D90D4F937DCCULL, 0x7019BD37504D354AULL, 0x9DE539E599262D8EULL, 0x1CD79A7EA87D6704ULL, 
            0x374E4FF8BF9D96F6ULL, 0xDE05F0973E89B44EULL, 0xA5DDC85D35F7E1C6ULL, 0x573DB7CF08096ECAULL, 
            0x75EF96193E8068AFULL, 0x856339CB30429135ULL, 0x162D6D47F4C9E7CFULL, 0x836821467ED6FA52ULL, 
            0x03B03520A3977D39ULL, 0xF7EBFEEF0D2A387CULL, 0x721EADF4FA7D5661ULL, 0x8B2ED5149E218BA5ULL, 
            0x7ACBC1C75756B219ULL, 0xDA8D2D2D739D01BCULL, 0xE316D1B46A1CE5BFULL, 0xBBCE183C534BEB7CULL
        },
        {
            0xEBD227DF7BF2598BULL, 0x631D9BB5F703CB41ULL, 0xE0ECFF3A22721D32ULL, 0x695C534A546D0904ULL, 
            0x14FC2B9D81E5B647ULL, 0x9D7D9ED05B576C42ULL, 0x7F6291E8D6EE1D28ULL, 0x2ED077F22039D941ULL, 
            0xA1DA60CC33FF65DEULL, 0xBE739B8CFAF339DBULL, 0xF5320DF9343C3174ULL, 0x3215F7A4C1CA8619ULL, 
            0x0D78AD3FADE8E79FULL, 0xFEE0A24062621CBFULL, 0x163203999DDEB4D6ULL, 0xE6AE2AAE64EE46B2ULL, 
            0x5EDB2214EDCFB64FULL, 0x02A68F03880790DEULL, 0x1C32BE587D0CF69BULL, 0x2809E50CBD331964ULL, 
            0xCD22984B7F8128E0ULL, 0xC83423DCFD31CF17ULL, 0xF48632F9D5B83153ULL, 0x35109AB546D52CDEULL, 
            0x3BF7C40CF6EA0785ULL, 0x70C3AEC3E088C485ULL, 0x09D7138A2C0E847AULL, 0xCEDD79DA1985ABFAULL, 
            0xAE9476FA4CE70CDCULL, 0xD3BAB3E9EEFF1C33ULL, 0xCB9A2BBEC06D1779ULL, 0xF4422DB326D75038ULL
        },
        {
            0x7D1D2506385FF1CEULL, 0x8003F08D87BBEA55ULL, 0xB3DBAD96B7F28C55ULL, 0xCECB768A3EB5F593ULL, 
            0xF04371120F1DF8B8ULL, 0x4111C6DFB9172C2DULL, 0xA3BB83DFCA758D72ULL, 0x6FA59FF58399EBFCULL, 
            0x4092EBDA6CE419E0ULL, 0x84389BC2AD28F06DULL, 0x17491F53359E674FULL, 0x80D429EDE00D68F3ULL, 
            0xB4DD0860426A1E69ULL, 0x7B73AE1C1F73A57CULL, 0x1838C0FF256D05FCULL, 0x6D56EAB138C879D3ULL, 
            0x1D58D93CF11A647EULL, 0xFEFCEA37CE2E9EA7ULL, 0x9BAC76DF51F4D3CFULL, 0x0F5DE616F6CAB1E2ULL, 
            0x45C5C4DD0BDA199FULL, 0x35E6EB74AE48D850ULL, 0xD0CD658709EC0B57ULL, 0xDD9F66174C5D4D64ULL, 
            0x49D796348E2B47C2ULL, 0x0DA58A68C66FE90BULL, 0x8E338A862835B62BULL, 0xB77D22301208D957ULL, 
            0x52AF2A44FE297596ULL, 0xDB5787220FA84BD6ULL, 0x96482E00A2689439ULL, 0x8D3507CD0973D53CULL
        },
        {
            0x46A2DCB5DAFE6936ULL, 0x0E398406CABDF38DULL, 0xAF4F3433EC8CEAA6ULL, 0x35B795ED42B97963ULL, 
            0xC2329A795F31ED71ULL, 0x75E68F60F06C8295ULL, 0x0F0F301121E30889ULL, 0x4653297249E0F5E7ULL, 
            0x7544F57BFD1ACAC8ULL, 0xC3ED5B77F073A74BULL, 0x4F96F27EE8724AD6ULL, 0xCBA8856A276A1A1CULL, 
            0x414D6DDC16CC1438ULL, 0x2A4DF0F4E764042CULL, 0x58CED7CC38A97367ULL, 0x0899C3B0C4B660D0ULL, 
            0xA6BB8DA79A83BBDEULL, 0xC2FAECB72B0A3B3CULL, 0xD72F6328DE6DAEA1ULL, 0x7979B5933E43C9CDULL, 
            0x66F9FD3F1C247763ULL, 0x4F51869D35B147EBULL, 0x1A8AAB8D9A546E25ULL, 0xE7143C7D7C9BF80DULL, 
            0x809F0CDD9030677DULL, 0x682F8F29E819E29EULL, 0x2E41075703C6396BULL, 0x64D195A12189487EULL, 
            0x9F151108D9F4A7C7ULL, 0xB1F125088F494CCDULL, 0x6CCDC734AD715FCEULL, 0x8A4C20A1602713B2ULL
        },
        {
            0xB7CCDE99AA2001C6ULL, 0x6ED429F422469129ULL, 0x2F81EA1B04133E56ULL, 0xF67F17C5F3485F47ULL, 
            0xA6E571C46354BACDULL, 0xAF230E4855EC2896ULL, 0x7EA1B88D1500E1CDULL, 0xDEA4BFB844FBBA34ULL, 
            0x32D8ECC1E59ACE0AULL, 0x970CA64A421BC6EEULL, 0xD7E7FFAB20EA983FULL, 0xF9B8C10E72CC2FD3ULL, 
            0xE2D6656DA76867B1ULL, 0x37F1F3DE2DCEAF16ULL, 0xB1F0D0F8F5724004ULL, 0xCE2586D447DA1610ULL, 
            0xC7EF1B658BFD0F60ULL, 0xA905C5C8BB26B0BBULL, 0xC5560C24E97DF4D0ULL, 0x4D99236635B3C853ULL, 
            0xECE98D4B5DACC81AULL, 0x33AE3E8104E0BA99ULL, 0xABF71B4C9F50B3A8ULL, 0x55F424DA1264956EULL, 
            0xAF510866A232EC3BULL, 0xD1C5883151C40761ULL, 0xD157A4B7B48A29D3ULL, 0x413915D244E1CBF6ULL, 
            0xC1D506A1B49B18F0ULL, 0x5F25919DB4F4C3A6ULL, 0x644F7DF0C45441BEULL, 0xF15DE685A145C855ULL
        }
    },
    {
        {
            0x143F40539B0E0114ULL, 0x20734E3528CDC9E3ULL, 0x49E4D3E77C3E177AULL, 0xFA5A4AC0FB07C793ULL, 
            0x4BA6C1EEED52B66DULL, 0x0C50862AED31D96AULL, 0xE4A3C5190DDBF363ULL, 0x8B69F010448708B7ULL, 
            0x11F9FD4CB8761F8CULL, 0x875AB1091755E8C1ULL, 0xDACF11270576C304ULL, 0xB2985C4E266CD5F9ULL, 
            0xF92338CC12D68ACBULL, 0xBB54830E067EE0A4ULL, 0x99D8EC7F97C1380FULL, 0xCB04BC107E62DB20ULL, 
            0x3144B0340565CD11ULL, 0x7B82B97F335C415AULL, 0xB529768F534F7625ULL, 0x25FFC70D0B0970AEULL, 
            0x070A77EA431C6E39ULL, 0x28E9FDC7C3E2A3B5ULL, 0x3EB5A59B56BF74ABULL, 0x054E52F28D60D69BULL, 
            0x68BD138844DB4C9AULL, 0x920422C50A4D7A54ULL, 0x84BF6E1E1AD41D39ULL, 0x93C667000FB09C79ULL, 
            0xD622A6A6EE56A3B3ULL, 0x6FBD608F18BC8260ULL, 0x92E5AB47730DA5E6ULL, 0xCAAFCA6FDB7007B7ULL
        },
        {
            0x82E9F9DC4C0982FFULL, 0xA51DD807F36A0ACAULL, 0xE1FB63810DBE5C7DULL, 0x7C8E269FA5CFE0D7ULL, 
            0xBF43C9374620F457ULL, 0x26A0FD5E3C4E9760ULL, 0x50A07613B7BB5268ULL, 0x3F556E33D698AC1BULL, 
            0xA49906C474F2DA80ULL, 0xA3028EC4C5AFF84CULL, 0x665C8A0104D395DEULL, 0xD1BE7A94C61CD2D0ULL, 
            0x8601B80D6C78C8A3ULL, 0xE23DA1C3EDD01684ULL, 0xCC4208D8E6215D75ULL, 0xFDCE9CD68BDA1FA4ULL, 
            0x6917F9AC22DC3867ULL, 0xAABC5F4ED2FDB8FFULL, 0x0F8FC6F0CE64CC58ULL, 0x2A3B8659025D1747ULL, 
            0xDF05B5C8C4CF88A3ULL, 0x6C9EA2E514DFB78BULL, 0xC8A2E3EABBACCFCBULL, 0x82B4F7D722A238FEULL, 
            0x5FD27B8BB86C654BULL, 0xDF29D33EE151BF9EULL, 0xB968152EF51F148FULL, 0xF40F96230F6D5D9EULL, 
            0x5798173821C8C315ULL, 0xBC73D583A910C912ULL, 0x3BCA90889F628664ULL, 0x292BC06D64C83E83ULL
        },
        {
            0x0B136D08B3EF04FAULL, 0x9965698E7CA5A0E9ULL, 0xB78CD876899260E6ULL, 0xB6D36B84EFB2AB66ULL, 
            0x99C6A76AF51D5CEEULL, 0x897AC306D5019698ULL, 0x1F4397BCF39D40BBULL, 0x88CD14139CEF9B52ULL, 
            0x7AF5CBE2ED550A84ULL, 0x9FFB5045C42C795AULL, 0x44764CC23FE2234AULL, 0xD829ACA56D2BF066ULL, 
            0xBCB4A7A566D90B75ULL, 0x34954F02F3F702F7ULL, 0x9D91A43A921E98FCULL, 0xEADC7473E69EADDDULL, 
            0xE69F29B14614D0D6ULL, 0x0A4BF969E3535255ULL, 0xEF5FC5BB62380C72ULL, 0x35B67CB487FD32E7ULL, 
            0x29EC4EA90FEE8A4BULL, 0x149C4EF16ADE9FD2ULL, 0xFDE9BBAC2FA2B503ULL, 0xD1FC3DFC0C5368F6ULL, 
            0x1A995B6FF293A617ULL, 0xC091A5C38C0759A7ULL, 0x62616C8793DED547ULL, 0xBA6923966FBFE4E9ULL, 
            0x1F210652A3EC4735ULL, 0x74190DC24DCF4612ULL, 0x2796A7AAD72DD4D5ULL, 0xC8BB8C3CD6D53FD7ULL
        },
        {
            0xB51DE4E481801ECBULL, 0xFE23389E7213D3BFULL, 0x15A8279C44D707DAULL, 0x25B91BFE5DE8B1BDULL, 
            0x3202857CB0CF8FD8ULL, 0x6EF172312B826A0EULL, 0x0F4F58EA3249E59EULL, 0x653CEEFC9974B0D7ULL, 
            0x0F2436E389352A94ULL, 0x29175D13343B9D64ULL, 0x5D5B1A33ECA42BCCULL, 0x54D81966095DD101ULL, 
            0x57AD8C0F15F01254ULL, 0x07F4D25C63FFE2D9ULL, 0x98A39A1E8C1575CCULL, 0x7EC384A9C0FEF6BDULL, 
            0x355DF366532563E0ULL, 0x444ECF50558FFDDDULL, 0x7CD0B21F912F5661ULL, 0x5933C6AD131C1233ULL, 
            0x14A5E2C827B1EC98ULL, 0xD86F93E051A41213ULL, 0xB61E2E125AD4459DULL, 0xE6FF9DCD98DB3801ULL, 
            0x4AF297B941387C63ULL, 0xBC02948723FED36BULL, 0xA0D95D0568CAA73BULL, 0x92DF15572BD4E5D7ULL, 
            0x494221EAF5C09D6FULL, 0x235F297C093F85AEULL, 0x5FD58750F7C863FFULL, 0xC26044D03B232087ULL
        },
        {
            0x0017F4C2558B4049ULL, 0x2516A1F19E474893ULL, 0x6D8BBA028704D766ULL, 0x902B48DE6313CEBDULL, 
            0xA968C6242D4E82DAULL, 0xDD72FC0B44B7CA6AULL, 0xA9CD92A8C2DBA32AULL, 0x6681C9F94A25D843ULL, 
            0x02E04B2A4068B02CULL, 0x412F41F7F4882D8CULL, 0x95A432CD95358424ULL, 0xCBFF37301FE46BB7ULL, 
            0xD08FA97F672206F3ULL, 0x026FA6A62C76E301ULL, 0x28D34087364E87C1ULL, 0xCCD61C70D5C3026BULL, 
            0x4D8D9CC1A70EB4A4ULL, 0x0A1AD92EB50598D0ULL, 0x1689D08239716C49ULL, 0xD9D1B6A4A6FB6E33ULL, 
            0xAF960FABA77CA349ULL, 0x9EA920F3B9E5A5F3ULL, 0x07EA0B020C26BDDBULL, 0x5C13FDCFC490ECDFULL, 
            0x39CC48F970B3386AULL, 0x9C7AD0D8B279F24EULL, 0x8C6B5D6EFE1B6128ULL, 0xBF88382C8332522CULL, 
            0x06721D860924C633ULL, 0x68243038C20B1026ULL, 0xBCB9E6403EDF63E5ULL, 0x752972262258DB42ULL
        },
        {
            0x1CC50B96568F0FD1ULL, 0xD0D1728BE5109CD5ULL, 0x737A345D0D878F2EULL, 0x995EDF998C60F0A4ULL, 
            0x16EA66851F8FA33AULL, 0x316694820B2347ACULL, 0x3A4B5F6F6AB97971ULL, 0x74C1EADCC5513042ULL, 
            0x4C6B84E4C7BD4794ULL, 0xA8549FEE3D80C54FULL, 0x694AF0926EB7B034ULL, 0x27F884A0014FF2E7ULL, 
            0x65D11483D405136EULL, 0x8490E9077D08AF2EULL, 0xEFE22B9230393005ULL, 0x6881E8557C9639F3ULL, 
            0x79EF0A2BCB41282CULL, 0x1B4E37A9C89CA14EULL, 0xD730EF1EB585C338ULL, 0xADC694457DA50E12ULL, 
            0xFBCBA1EEA9FA7EFBULL, 0x8F97DC17CD0B1745ULL, 0x7A9AEF102098646FULL, 0xA6B073BF9B4C31F8ULL, 
            0xABE787B47ED35810ULL, 0x88A162FD139D1032ULL, 0x2AE1D943DDE61630ULL, 0x1B69F5CFA4DE6A4EULL, 
            0x0BA5249385576783ULL, 0xEBD869F81C6A13C0ULL, 0x42107F64DC9CE38DULL, 0xE65412F97B6E8C31ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseCConstants = {
    0x5A6ED26F8F19D7F9ULL,
    0x8F80F73E4DC571FEULL,
    0x8CBD1DA2338A6F34ULL,
    0x5A6ED26F8F19D7F9ULL,
    0x8F80F73E4DC571FEULL,
    0x8CBD1DA2338A6F34ULL,
    0xEB2EDF2A91CC1381ULL,
    0x3652C08B3661048EULL,
    0x5A,
    0x4D,
    0xC3,
    0x43,
    0x11,
    0x3C,
    0x73,
    0x79
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseDSalts = {
    {
        {
            0xFEBCBBD2CE9878DDULL, 0x8B3BC373DD4E4131ULL, 0xBBD3D210584BC865ULL, 0xC7D8FACFC8199FFFULL, 
            0x390DDF9926615954ULL, 0x1309260DA8E7121BULL, 0xFDA9EF98A28F6745ULL, 0xD7F73CD70D8FF163ULL, 
            0xC9C3975A254055DBULL, 0x501B6AE68026D32BULL, 0xB96DFF71B6F47912ULL, 0xBB41F9C7777BC999ULL, 
            0x374589D2F3382CDAULL, 0xB43B97B3E1BAAB22ULL, 0x936B380E7B05E2BDULL, 0x571B51A2E1966B91ULL, 
            0xD65D936F7139A217ULL, 0x7FE967856553FC16ULL, 0x5D6D499396C95777ULL, 0x1EC1CC50945A0654ULL, 
            0x5F5C46A6960F7079ULL, 0xF56E60B6C4A3BA3AULL, 0xBAFD1E93D261FFA0ULL, 0x1E9D3B217D926C17ULL, 
            0x87B14EC593AA943EULL, 0x68830901701DC7A0ULL, 0x049D4894A3D909AAULL, 0x3E280174269B0332ULL, 
            0x2C4953D7D7F8405CULL, 0xB1741BDC65B1A9BCULL, 0xC2CE30F16488BF75ULL, 0xD995201F6F45EFCEULL
        },
        {
            0x036E0C226373F9BCULL, 0x273A8308EBF84273ULL, 0x80BE87F3D7DF88C2ULL, 0x068569F113EC9679ULL, 
            0x15CDD6CCF65D9D9BULL, 0xE229DA3CD94870E0ULL, 0x5EF756691933880EULL, 0xD848446E8AFA5132ULL, 
            0x045ECCC60A65EC79ULL, 0x4A4D85C7279312F2ULL, 0xB16ED516C05D37F9ULL, 0x469D742474650D5EULL, 
            0x459A26C18C00D39DULL, 0xCE92B81C7F74BEF8ULL, 0x3096DD7218356FCCULL, 0x2E5E0465EFD4737DULL, 
            0xD6487D836E5B2C3EULL, 0x8B35B69B762001BFULL, 0xBF339E014689E1C7ULL, 0x0E9A4293AEE1EB65ULL, 
            0xB3501D98C9A14D2DULL, 0xFE37B7814365F1B1ULL, 0xA6437E1791889670ULL, 0x9DD1B08153C80C8DULL, 
            0x52604EC767F49614ULL, 0xF08FE15231B3A24AULL, 0x284D6693571A275EULL, 0x2E0116ECF8AF010CULL, 
            0x1B9F1082F72DB39EULL, 0x39467FD2B5E53B6AULL, 0xC95D014F387FE379ULL, 0x7029619D1AA614F8ULL
        },
        {
            0xB7B44B9AE33D33D7ULL, 0xBF07F5C749A538A9ULL, 0xC3820AC4F0464C9CULL, 0xC716FEBC12378E6AULL, 
            0xC5879FC476BBF2AEULL, 0x23D251162442C762ULL, 0x4B289A41DC548CA8ULL, 0x6C24737AF27D8531ULL, 
            0xC8ACCC6161749250ULL, 0xEE83C4F2FA43811AULL, 0xC789CF604A6519AFULL, 0xFB7F211B15F1C46EULL, 
            0x0C43348A961B0FCAULL, 0xD1C3AA4362F54FF9ULL, 0x3B308C6FC8490241ULL, 0xD64D3069D56B87F8ULL, 
            0x94148F14F02AAF4CULL, 0x5AC2401CF512FBD5ULL, 0xFAE737458D2C0676ULL, 0xC43EC5336307A88FULL, 
            0x672D3497770ADF7BULL, 0xCA10095A9D46855CULL, 0xFF025C690D2A3229ULL, 0xACC6A55E965EBEC9ULL, 
            0x1320F91A2D426003ULL, 0x7DAFF27F2DE550BAULL, 0xB4FFDE70A9EA7927ULL, 0xFD976FB3BA2B0BC4ULL, 
            0xFF7AC1476CB84A94ULL, 0x44C6E90C46705BE1ULL, 0x6A49EBCE63F5F9C7ULL, 0x29A88DA2EA2C2398ULL
        },
        {
            0x5922447B00876DA4ULL, 0x50A5C0C0A2934E74ULL, 0x967A61A2C55F0C09ULL, 0x20EA34F9C1A2E770ULL, 
            0xB919BE2D3D8C1DBAULL, 0x95300A4FAE89E988ULL, 0x68CF3247F8C0C170ULL, 0x60FC2DE6AEF42C11ULL, 
            0xCA8001D59FF9CC76ULL, 0x47748EB25C072F44ULL, 0x96AA08F0EDA85B3AULL, 0x044FABBEA4AB223CULL, 
            0xAA84E41CD27C8D91ULL, 0xAF6AF4B5F0E7FD8EULL, 0x6F39086A08563E36ULL, 0x6D4FE1B4AF30EFECULL, 
            0x56055F3FA4F31AA3ULL, 0xFDA830B294CC9E3BULL, 0x4C1E8ADBAC04F046ULL, 0xBD5F6CA11E9EF57CULL, 
            0x6144F075754C65DFULL, 0x622A979FA360666FULL, 0x0640BF0D6A460204ULL, 0x093123593E7499DEULL, 
            0x6B87FD175F768ABCULL, 0x21691DED12353365ULL, 0x8116D0DC2923E6CAULL, 0x6778A5F10DB119FBULL, 
            0x5ECFCF27B280E9E5ULL, 0x0F9657AC96EEE1D1ULL, 0xEA588D835E4D2C58ULL, 0xD229212BBE23DDAAULL
        },
        {
            0xF72291573F984F9AULL, 0x29813A38F8059D51ULL, 0x7E99B4D85F6435DDULL, 0xE98A5C4E86020707ULL, 
            0x6DEC055351133192ULL, 0x0DD64693E694D9DDULL, 0xCECDD29A51218B0DULL, 0xD50348D8E7D5EC40ULL, 
            0x6D048C29ABF39B1DULL, 0xFC97C1BB3C2623F2ULL, 0x09F2513F208621B4ULL, 0xD063BD4668FE10A2ULL, 
            0xE5853AD533D2268DULL, 0x04F3423AC5DBB6FCULL, 0xD943FC5617FCAD7DULL, 0xCFBE44AAE321F717ULL, 
            0x085044CFC320A907ULL, 0x1569430EE088A50FULL, 0xE70F5DCCCB1751C6ULL, 0xD3B7003EDE371637ULL, 
            0xF07AE73BD4D31C05ULL, 0x470F0982E95B4F98ULL, 0xC9A580CABC062950ULL, 0xC2A5FE83795CD7ECULL, 
            0xCCF26BE554B1967CULL, 0x6FAA661ACF14C5DCULL, 0x0F8E845DC2995CECULL, 0x35613A629BC4C7EAULL, 
            0x18A6665DC1541FBDULL, 0xA5A143C82601AEBEULL, 0x1D757E3B80F397B5ULL, 0x895A184CC2B3E199ULL
        },
        {
            0xAB0AFB667F308B1DULL, 0x97C940B407104907ULL, 0x19A41D86434B4458ULL, 0xD6F00057F40D7889ULL, 
            0xF0F88D40368B0720ULL, 0xF086BA037DD93706ULL, 0xC1A3B0A48451FA79ULL, 0x9E44F2FB016ACB69ULL, 
            0xEBCA6277F9EE3D99ULL, 0x187AFFFAF49278A4ULL, 0xA998023D51AA15BDULL, 0xFE1AD93CD3A41A70ULL, 
            0x73D1E59CA05764BEULL, 0x3DE8AE07081EC9B1ULL, 0x60AB6F2C4C489BC6ULL, 0x06A671B5BF686E90ULL, 
            0x5378A3B4E15F3E7FULL, 0x866353B3A207B2B9ULL, 0xACDA831E4BDDB750ULL, 0xDB1FB058738951F0ULL, 
            0x91C56245AA038E85ULL, 0xBF495A930E2DCB0FULL, 0x7A0CFF8483E179FFULL, 0x78387ECBDA8D2E0DULL, 
            0x00371F0709C89CE8ULL, 0xE1C7350C5E8E27E3ULL, 0xF1C9D31B3B5F900AULL, 0xC616D8F5EC9BA621ULL, 
            0xDC8527D51E907EA1ULL, 0x838EF48D871B44D5ULL, 0x74B5F7A549EDD720ULL, 0x2EA5796B102D84A3ULL
        }
    },
    {
        {
            0x650B231F548EB6BBULL, 0x76A50138D6657676ULL, 0x227F984B88FF8C31ULL, 0x3762FF991C436EECULL, 
            0xD7781C5FC0E411D9ULL, 0x1D5765F01CC06568ULL, 0xB9CF58EDA32AFCA0ULL, 0xCA7978BF54436CA0ULL, 
            0x795ED559166553BDULL, 0x2F149937CB4734FCULL, 0xD374874B685A4CE2ULL, 0x126F341CE0295051ULL, 
            0xF425C55D727E70FDULL, 0x52D3B2BA8109926DULL, 0xD00D5F3B42B056B0ULL, 0xAB01D5EF59E2711BULL, 
            0xFD143381C491C1A4ULL, 0x294769A8A59A5223ULL, 0xD669A9F5987E5860ULL, 0xEE6041BC29714862ULL, 
            0x3103E627AA64F06EULL, 0x7D28F98071B2EE44ULL, 0xC9FEA538C064AFB3ULL, 0x58835DF203E7F5D1ULL, 
            0x644ECC486F9D0EA0ULL, 0x5AF4A1CD50FC9E99ULL, 0xA07C6B19A7B9E32AULL, 0x52EF733AE937347DULL, 
            0xBA71AC3888F74BA9ULL, 0x5B183823684E6F98ULL, 0x8975882E129FE725ULL, 0x36F5A9ED43D94B3DULL
        },
        {
            0x3967AEE7CB2E3FE3ULL, 0x1F00D74867B7D72CULL, 0x69D820A850655E0FULL, 0xF1C154AC9A4F13BAULL, 
            0x0B2E9108D0CE51A4ULL, 0xE1208DA5897C4370ULL, 0x8749E81D722C05B5ULL, 0x077A917FE1B3A432ULL, 
            0xD84B56154AC9D1E3ULL, 0x9A7C665AB90055AAULL, 0x9EE47863C2667F0AULL, 0x263D5DA4C7DC50B9ULL, 
            0x6684FDFB96E48E30ULL, 0x211E9DA915C0E3FEULL, 0x1D5A1EE66DF9EE48ULL, 0x72F84E49E439BEFAULL, 
            0xFDCB9258242A91F5ULL, 0x99ADC1A628DEBE64ULL, 0xC1AB2CCEAA1AF82EULL, 0x1431E19A8AF037F6ULL, 
            0xC723A91EC3AC99A4ULL, 0x6A2104F6CBA5361BULL, 0x9E9D631DDB04F314ULL, 0xCD25B7174CF38D55ULL, 
            0x3C69987C062D5904ULL, 0xEF44246D2FD51422ULL, 0x61B5ABB1FA94EA22ULL, 0x7BEBEE1B71A1B3DFULL, 
            0x9BF8A9B6A514AF7EULL, 0x1423C428D80D9461ULL, 0x538D5F1E9C33A66BULL, 0x7502704F1D68ED34ULL
        },
        {
            0x536429C58B7501A1ULL, 0x13CCF30175846DDAULL, 0xE44C076278D31FE1ULL, 0x13AD9D471F024FD7ULL, 
            0x995905B453C98826ULL, 0x633DF3B48C0B2C0FULL, 0xE67F39334E0BD3FFULL, 0x395DDD2C396ED36DULL, 
            0xA1561F95ED2147CBULL, 0x5F0A218AC15D73E8ULL, 0x3F75A44223BB44B9ULL, 0x07AE71D1218951CBULL, 
            0x321E49828D341C23ULL, 0xFB5DDEE8887C81BFULL, 0x2B6EAAC8AC22CD10ULL, 0x18221F0F06A095BBULL, 
            0x726A2E5D9E56BBD7ULL, 0xDEA5CFA96275E49FULL, 0xB29B88664C798DF9ULL, 0xBC150D49ED5E843AULL, 
            0xE7077C305D0E4613ULL, 0xB27320EA8B1167A8ULL, 0x0ACF119E24E6891AULL, 0xB0AEDC110786DC3EULL, 
            0x2BD4DA92EE9370A7ULL, 0xCDDBD0C3800B3CEEULL, 0x9A61B7F4D93376A4ULL, 0x3488010DBB2ACDD3ULL, 
            0xB445DF4427A3674EULL, 0x1C0CA82F8E939125ULL, 0x5BF3547C197CBF7CULL, 0x95E9AA3D4BFF39FAULL
        },
        {
            0x5AAF1C29DA640BA2ULL, 0xFE5FBD99928551E2ULL, 0xC21117AAF6F4CBEAULL, 0x3B7DE9E6179C94C0ULL, 
            0x210D539A7CBFEE13ULL, 0x8249D1CDCB27C73DULL, 0xFA508C188857C0E3ULL, 0x7B385300549DDD4AULL, 
            0xC3C061E5170D8BE7ULL, 0xA88D3938CC21E1D6ULL, 0xBAA9186F78D60765ULL, 0x41DCD6BA48812017ULL, 
            0x173B0E2F3C653D4BULL, 0xEFE27D0E8FFBFDFBULL, 0x06FC8A052E11C313ULL, 0x881538D4DBF87D6CULL, 
            0xEAA3ED2B2F860CDCULL, 0x5D1988C7A7DDA1DAULL, 0x79E2EB26FD3AA903ULL, 0x7AED77F12FD7758BULL, 
            0x3DEFA0B7A99750EBULL, 0xF11852FBAEAE4976ULL, 0x03645379694A8904ULL, 0x2BA002AC377708B0ULL, 
            0xB2DC7D59F6C1CD4EULL, 0xBCA1C16063A2BBA5ULL, 0x1741AB702ED38CC6ULL, 0x85379BAF85E47D72ULL, 
            0x4AC5EEAF6DDF0A6AULL, 0x3C9FB2129235135BULL, 0x2DFEB2E6B7FF0A24ULL, 0x200FCC809EE3E720ULL
        },
        {
            0xC783867EB9620116ULL, 0x13068AECEB9E8712ULL, 0x3D3A8F760082AA07ULL, 0xA7A0D5F3BDFE83CEULL, 
            0x88AD963A15EAF83CULL, 0x12E939C2AD9174F9ULL, 0xF64DE9920D8BDE21ULL, 0x6F6FF4B4168E912FULL, 
            0xF8707456B04DE50DULL, 0x03A20B83563C45F5ULL, 0x7EF2A2710BADF3FDULL, 0xA3FECDCE2ACD19C5ULL, 
            0xD9CA3CDB8634D4D4ULL, 0xEB6773ED1D943522ULL, 0x2769C2FB906D14CDULL, 0x065E2888081EDB45ULL, 
            0x97C497CE44F1F6F0ULL, 0xABC8C8854B3504ABULL, 0xD537B5A833A2DBD7ULL, 0x8005F972F71E5670ULL, 
            0xDD510B4A22322FB9ULL, 0x90727E4F2F0824B8ULL, 0x478E873D201499A6ULL, 0x21DE870F04EE271BULL, 
            0xA659348E888944FEULL, 0xBD75A3BDBD28484FULL, 0xC2211A22B90A049BULL, 0x69F1A61DF649E02BULL, 
            0xAC65F100BE779DE4ULL, 0x1C1A8391CD2D92A1ULL, 0xAB05B0998881BDAFULL, 0x2B6E690CDBDC765BULL
        },
        {
            0x64CA10C0BE7D9191ULL, 0x39D307FC4D1E95A0ULL, 0x67FC6E503717BB3EULL, 0xAF8447C19349130BULL, 
            0x64377C23935735C2ULL, 0x6F0145B83C2B01F5ULL, 0xF95F17BAE99BF75BULL, 0xD77F703F659E85B4ULL, 
            0xC2692E16E8012B2BULL, 0x12E0F6368636F0CCULL, 0x5003B62BAD61D7DDULL, 0xB097F29F67A59152ULL, 
            0x460E4B3492D5CE64ULL, 0x433FE1422DD02A25ULL, 0x7E3083D77B25BE16ULL, 0x90C8B038B8D76989ULL, 
            0x22ECF90E20F5B576ULL, 0x1E8F3C36B9A11BDBULL, 0xE0EC2D20CD4F2254ULL, 0x5AA86A4993DD10ADULL, 
            0xCB1CF2C90C695EADULL, 0xEE1FFA3653284FCDULL, 0x08722A3E4FCA83E9ULL, 0x9CBC50DFEC593CC2ULL, 
            0x9D5D26A296E26A24ULL, 0xF12C7B4D782D5E84ULL, 0xF8D70FE1F1E0BA5EULL, 0x6EC12F5B803F34E5ULL, 
            0x0DD9B6268F906AEFULL, 0x4575B3845D22E6E8ULL, 0x33A32F60CB36F052ULL, 0xE94D50DAB0CAC0D1ULL
        }
    },
    {
        {
            0x20E5059C2196D53AULL, 0x36CE429A4BF0E51DULL, 0x0449E4D917FB45ADULL, 0xE060D1179F8122FDULL, 
            0x21C732EDED673C22ULL, 0x2BD476DC1E2FF1ABULL, 0xA28A4367CC769074ULL, 0x1F744AE4A2F9CD07ULL, 
            0x55F1239B03B45C26ULL, 0xC2128292C494C98BULL, 0xA223D9D1587118D5ULL, 0x7E9023A5025A8F18ULL, 
            0xE37B3CFD4105C951ULL, 0xE865683DFE01D8A7ULL, 0x7A76AD387FDA4B01ULL, 0xEDC78005BD4FE140ULL, 
            0xD6C4A1D955F4BDEBULL, 0x3D6D84D163018BDDULL, 0x6B2C5352DA0CAAA2ULL, 0xD7E70A643B01ECFEULL, 
            0xFAFC6120F7BACDC1ULL, 0xC8BE5D40DF4C5EF0ULL, 0x116342AC57EC89ABULL, 0x2C09DFC8889E0B7CULL, 
            0x729283B5084476E6ULL, 0x33B30F8B85EE76A1ULL, 0x1396195EA4C4D01EULL, 0xB922F704B7953421ULL, 
            0x87E5CBE793BC62ABULL, 0x513628D5332FD45AULL, 0xA9D9369308BCAAC8ULL, 0x5729135F035DDCAFULL
        },
        {
            0xD4BCAF52EA96BF43ULL, 0x56FA0B5C538C990DULL, 0xE097D95D06EA0A3AULL, 0x349018E39FDF5B35ULL, 
            0xB1FFA5D78360EE65ULL, 0xBCD133612C77DD55ULL, 0xDC1B93704204B419ULL, 0x7946CDC98D6E53C1ULL, 
            0x533E9AA488C31390ULL, 0x19792645B08FAC5FULL, 0x0FD79B9F465E843CULL, 0xC1C8CFD97878EB94ULL, 
            0x8CC48B4938DA3CABULL, 0x9842ABF3E1B6CDE1ULL, 0xB90DEEB360EAAE21ULL, 0x158413718D5D5429ULL, 
            0x979FF33A6ECF4A6FULL, 0x5B6083930D4A4C8CULL, 0xB1C3B07D3F69B969ULL, 0xB6650862896E0835ULL, 
            0x19B0CB2A383977EBULL, 0x265F7A25AAA0CA65ULL, 0xF3811363FE6CED29ULL, 0xA8750612CD840518ULL, 
            0xADF89338CD90AC91ULL, 0x55B6969CB1E27DDCULL, 0x253F9802E7E3FECAULL, 0xB866861ACDD4141FULL, 
            0x76751AB41F5DF2AAULL, 0xFC9B91616D743FCBULL, 0x6FB78D321958137EULL, 0x276B1D52E8ED6ED1ULL
        },
        {
            0x16BDA19603BAA7BCULL, 0x9C078EDACEC4FAB6ULL, 0xCF59AAEDC6DA053FULL, 0xCDF4C895FCD0373FULL, 
            0xCD626F809A419679ULL, 0x3D60B386763568D3ULL, 0x55788941817950A5ULL, 0x7C2D4456FB77E437ULL, 
            0x17C9F5AF17ABCE60ULL, 0x6AEBABEF3DA17766ULL, 0x6ED7CA09A0DCFFA9ULL, 0x8E9020D7E891E7D0ULL, 
            0xAC698EE4E6044EBEULL, 0x775ABF363C3D6D4FULL, 0xC8C069BDA7FEDF5DULL, 0x238BD49DE15CB06AULL, 
            0xECE7F93313DB4D8EULL, 0x9DEC8ED1A1781757ULL, 0xCABE1C36CB78FF78ULL, 0xBB6E9A14739C4E29ULL, 
            0x1ECEFFDBBD49D78BULL, 0x0A98E267ED93F6D7ULL, 0xCE4AFD9714498279ULL, 0x6DE0691E79978DC3ULL, 
            0xC73895DE91A7BF98ULL, 0xD09707059526C1AFULL, 0x87EC090154ACD324ULL, 0xC7E6F6A40D20A61AULL, 
            0x98FA5176F5121AA0ULL, 0x6953DCF4CBE22E1BULL, 0xC7EEB8778FD92C57ULL, 0x365C49FE7F537FE8ULL
        },
        {
            0x617A3FAEF18717E2ULL, 0xF95656D11432E162ULL, 0x3C470F29CB6CB59CULL, 0x8E440B910F3DA3A7ULL, 
            0x8D5D6A4B1E5E875DULL, 0xFD1D2644C990CAA4ULL, 0xE587C9951599C41DULL, 0xCB6E4DF88A659464ULL, 
            0x5C18A136E73E18D8ULL, 0xE69D225C5009E153ULL, 0x811DD02C8C70F068ULL, 0x20B155116F3A30DEULL, 
            0xA30BE68C272895FCULL, 0xFB24BD24FE2D06FBULL, 0x71FB15822DBF3C42ULL, 0xD541628A8ADEF3A0ULL, 
            0x78E9058F74FB4908ULL, 0x481F509064884142ULL, 0x99E44A762610E55DULL, 0x275B29A8283A62ADULL, 
            0xDDD953F30262F6D5ULL, 0x4D6C5BA465D716F3ULL, 0x465C82AA7B1095C8ULL, 0xCE136C4CDC5800F7ULL, 
            0xB252E23B288D527BULL, 0x6386BC5569304A70ULL, 0x44341A457E19EB3CULL, 0x87A9AE2368594948ULL, 
            0x673729A2AB1A91C8ULL, 0x56F72CA09195B852ULL, 0x7899648ACBB21CB9ULL, 0x8A6007BEFBC96BF3ULL
        },
        {
            0x06365E2B2277A981ULL, 0x88F43937D141BEA7ULL, 0x274BD66536CA7E57ULL, 0xF5B5CA5DDE38C873ULL, 
            0x4ED730A2FF4C4353ULL, 0x25417731FA32B4E6ULL, 0x8DBF90A5F1E81EE2ULL, 0xB4CA6D714EE2B7AAULL, 
            0xACF694E21D2EB3F5ULL, 0x4C6545899D116396ULL, 0x241E57E0F5C80D17ULL, 0x717485AF15FC2B9EULL, 
            0xADEE04B30072D7CDULL, 0xE236D08F9709F026ULL, 0x12A5B420B163C2E5ULL, 0x547F9903A21E1263ULL, 
            0x628D5D1EE273584EULL, 0xB97D7E830298E1E7ULL, 0x0268A718E249446BULL, 0xDAFFBE3A7B4B1D8BULL, 
            0x1C800235831BDE3EULL, 0xA68BCE324C177539ULL, 0x5845D3109455B1C5ULL, 0x8613F1FD78A06008ULL, 
            0xC96E9A9139DEEB3AULL, 0x3B5AB485A840C619ULL, 0xBA3AF31B7E31FE2CULL, 0x1C206C909A1D364BULL, 
            0xF5AED3B31C8A8F52ULL, 0xB8AB9F7BD7FC4927ULL, 0x5D641649A91172F2ULL, 0x95C7A71193ABB329ULL
        },
        {
            0x78ED2E69C2AB5EA6ULL, 0xAB484E5FD8B995F9ULL, 0xC0C81207D553486FULL, 0x38B2A217757DDE3BULL, 
            0xD71500F32D430B9CULL, 0x188C5DE9B6C2162AULL, 0xCDF324D902DDE28AULL, 0x33565EBD78EF9481ULL, 
            0xE26C0F6F96DC95DCULL, 0x619781A38BC81229ULL, 0xCA5381C9C5F4E51DULL, 0x0CD2E4E263615BBFULL, 
            0xA99ECBFB2147304EULL, 0xA8716FA338D8E298ULL, 0xE0649B9BFACC9E88ULL, 0xF36B2CE7CC9BBF7CULL, 
            0xE60E83184133F229ULL, 0xA77BE4D7FD0395B7ULL, 0xE2FC61D6F26473FCULL, 0xD22E1067A9AC1CF3ULL, 
            0x4633EA0E9C4BDBF5ULL, 0x9AD73B592BAC6C83ULL, 0xC56EF8A3B8074AD1ULL, 0x4F5CD11C36D9687AULL, 
            0x8ADDD2544F7542B0ULL, 0x0D14EB288E937CC0ULL, 0x483623315BEF9FD7ULL, 0xFBE02D6955C03A55ULL, 
            0xC3C052D295C034E4ULL, 0x8B014129AC320031ULL, 0x4F00380EEC54D4BCULL, 0x466E2311E57BD1EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseDConstants = {
    0xE3D0D38401FE3F0AULL,
    0x7E4CE230B7D98CB8ULL,
    0xC9ECB91735610943ULL,
    0xE3D0D38401FE3F0AULL,
    0x7E4CE230B7D98CB8ULL,
    0xC9ECB91735610943ULL,
    0xC70C3F9E756B0FD6ULL,
    0xFCABBB62234ED452ULL,
    0x70,
    0x51,
    0xA8,
    0x2E,
    0xEB,
    0x4F,
    0xCA,
    0x8F
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseESalts = {
    {
        {
            0xB137A8B666DD506DULL, 0x0A3581F3A23D7293ULL, 0xEFD7FD791A33036BULL, 0xBD9B346B270B6961ULL, 
            0x5766F305A485D5EDULL, 0x7785C5D97C0A9C7DULL, 0x4F0C132E45044881ULL, 0x126139DF783287F7ULL, 
            0x8FE76B6BDA3F6415ULL, 0xAB9DEE2E939AFB3DULL, 0x8653E9011FB9C6A1ULL, 0xE87C194F87E1A874ULL, 
            0x4212A9313BE06ABCULL, 0xDA58D1830ABE6576ULL, 0x43A9B4A9DF46AEE1ULL, 0x298DFE00E7EF0124ULL, 
            0x817C6D7B6F2AB2F6ULL, 0x44DAAA39EA579E5FULL, 0xC27BC1FD572B8708ULL, 0x838687BBABD37745ULL, 
            0x283A89BD09EB7966ULL, 0x1548CE138A8843F9ULL, 0xD20E3C8E0EBB9E6EULL, 0x05ABB5E1C0B65718ULL, 
            0x53123EEFA3A26C03ULL, 0xF9678AA7B57B7137ULL, 0x6BE34EA9DD78D71CULL, 0x16DC25BB4BBAD0D0ULL, 
            0x11F58A99D26F76BDULL, 0xDBE632365AACB14AULL, 0xBB82DD038DA57AF5ULL, 0x5AF4F96C8516F4EEULL
        },
        {
            0xDB9149711364B5F1ULL, 0xE98DBE2BFFDCB110ULL, 0x9B95247CEF4CB075ULL, 0x6C8912E6E36CAC9AULL, 
            0x774D745D0B5E9C92ULL, 0xA106DE1CE0C28F30ULL, 0x2FF3F5A5F9F87C83ULL, 0x5E628D46C2C7B26AULL, 
            0xD8CBE23EE9531DD0ULL, 0xB2E70D2BCE649996ULL, 0x5B7BC497E1EC2B21ULL, 0x36521133DFF2C495ULL, 
            0x8A093F05846464EBULL, 0xD9623F4E1A170E96ULL, 0xC5DA524E1AB10745ULL, 0xAEB20B872014C8A2ULL, 
            0x8E9DB8CD7E6560D7ULL, 0xF38D73B30C47374DULL, 0x8AAF1DF57DDF17B7ULL, 0xB7C44D28AB0B72DDULL, 
            0xA2850559DD263CFDULL, 0x4FC88CB849537544ULL, 0x032E1EE10368178FULL, 0x29A662AC9C2B8E1DULL, 
            0x0E8DB2562A7DE0ABULL, 0x55D05D71A72ED475ULL, 0x5A3B25346C3D8D05ULL, 0x67D1E6E51710468EULL, 
            0xA7359CD21E99B22DULL, 0x7B31418F7B926217ULL, 0xB444C7A506ED5FFAULL, 0x4848E49D19B72168ULL
        },
        {
            0xFF60D338DA5DA7A2ULL, 0x975EC358C9E247E3ULL, 0x8C4DCD083CED66BBULL, 0xC1EF60C79E6F71F3ULL, 
            0x9A7F9B2437D7B975ULL, 0xC5F7248A796B714CULL, 0x25D333375974ABF1ULL, 0x3C8AC38EEE63E736ULL, 
            0x962E7ED84E30BE30ULL, 0xDB818291AA5258B6ULL, 0xA8D5D0327E089660ULL, 0x05D8DB0509E665EEULL, 
            0x88144DE24F240C53ULL, 0xF470C2B7F814CB7EULL, 0x053A590BF720A50AULL, 0x279242E8B311833EULL, 
            0x3F519DB83EA1672BULL, 0xA9B192A790D18956ULL, 0xD1E156E0E8E708E7ULL, 0x2B2C448B424F4808ULL, 
            0x15F86587705AAC7AULL, 0x3B0E661C159E12CCULL, 0xAC1162C4224D5FFCULL, 0x9695B15335987201ULL, 
            0xBE055F2734AC387EULL, 0x29B2678D7E42DCABULL, 0x59591D633B10FD5DULL, 0xA14779E925E150F7ULL, 
            0xC4880F0EE0E823E7ULL, 0x5CCF8590A2F27F8BULL, 0x3C5A4B3CA3857ED3ULL, 0x541E90FC37A1D5D7ULL
        },
        {
            0xF8BF8CACBE9574E9ULL, 0xE7982F8142321AF2ULL, 0xD4B8E1E18112F8A9ULL, 0x893536CE9AB4647DULL, 
            0x0018824444B623B9ULL, 0x4A205457A943862EULL, 0xB62D907697034525ULL, 0x7F16D7573A978079ULL, 
            0x2C318BE909E7CD09ULL, 0x08C7F121E1261525ULL, 0xDD171ABD5C133523ULL, 0xACA95BDEEE22D1A7ULL, 
            0x1D71949DC05990E1ULL, 0x32A0FDAE79A29E92ULL, 0x7846D457C51ECE22ULL, 0xD92BFCA373EA11E9ULL, 
            0xFB8C62CFC878BA57ULL, 0xE93A3FFEF7BB564CULL, 0x96C0C44E3FDCBB5FULL, 0xDD4BB8085203B9ACULL, 
            0xC717E4276763ABCCULL, 0xFA5F2920E47AB908ULL, 0x7C15D8E4F71EF598ULL, 0xD65A8781C3FF1159ULL, 
            0x7F4E1C64472BD87BULL, 0x4C38B73337175556ULL, 0x0882825416C06340ULL, 0xAD5040F272817D11ULL, 
            0x3050C16F02A13966ULL, 0xE868202284D85188ULL, 0xACC16D9089BB10D3ULL, 0x8AD2D49D3FCA4E2FULL
        },
        {
            0x0F5B229B4CD2A0C1ULL, 0xB99B11496A8C2B5FULL, 0x0C91C444BA59D428ULL, 0xB955E9CF2152EB5CULL, 
            0x42EF920D0303FD7AULL, 0x169F9EB1DAAFAF33ULL, 0xA36336D921D561C2ULL, 0x1AB2E6C68A1BD97CULL, 
            0x56FD62AED89B9F7EULL, 0xA619A9989A240B1FULL, 0xB0F121C4AF4F495DULL, 0xFA68801C7B4F453EULL, 
            0xB02F2FA38A766401ULL, 0xA4E3B2855D997865ULL, 0xE35E80B211C1F40DULL, 0x53B4FF3E0DC2EDDDULL, 
            0x4D1EA9E78B2C8A38ULL, 0x34CCFEDB4AB8E73AULL, 0x69636ADEDE18392DULL, 0x11794DC8700A9EF9ULL, 
            0x0E88132EE6294D51ULL, 0xEDD5DAF7F1C800CFULL, 0x6158EA9921B54574ULL, 0x293683953FD947C5ULL, 
            0x5895D7E1197DDBDBULL, 0xE8A31161886F50BBULL, 0x7A0ABBA3260BD9E8ULL, 0xFD7D98AD2275AC38ULL, 
            0x6CE655091CC16F4EULL, 0xEB12434A471D37D7ULL, 0x759DC45180C05E22ULL, 0xF4F2EBF4BA8CE584ULL
        },
        {
            0xA093AAD22077069AULL, 0x8BAFA1939DDF9B56ULL, 0xF26AEA4F2F5145FAULL, 0x2444504A0B19D16CULL, 
            0x70DEB746A82403D2ULL, 0x5CF18D4B968BDED1ULL, 0x5E6C5C72F9546349ULL, 0x7A8D7066359E1FB5ULL, 
            0xC96F2DE37455F91FULL, 0x63B54CFE0CAAE8E8ULL, 0x0DDE60B2F60CD3EEULL, 0xC559DEEFE14C3728ULL, 
            0x3D9EDBB74E52E0B1ULL, 0x94E6E5CB72EC684BULL, 0xCB71026963D4880CULL, 0xA2A427EE992CD2C8ULL, 
            0x76A9374C1719E657ULL, 0xEB41CBF4056A123BULL, 0xAA6ED43F54620E9DULL, 0x82E5FF344EB3D275ULL, 
            0xD0FBE0F75459A9B7ULL, 0xE5D103C65F86AB2EULL, 0x63CBC20B330E5F97ULL, 0x36286E49D7BDA8C3ULL, 
            0xDE3808CBC716AD19ULL, 0xEC657E1176959DF4ULL, 0xFA19CF07CFCEFB6BULL, 0x1094E04717B2364FULL, 
            0xA0B0E2D7FFE5763DULL, 0x44B2FEED2F6C146BULL, 0xE2C491E5C53F1555ULL, 0xF7775CA107CA6AA7ULL
        }
    },
    {
        {
            0x4E6CD2271F3C91F8ULL, 0x7DB0ED32DCC1C887ULL, 0xEE45DF6E03D8FC4AULL, 0x243D194FBFD554D3ULL, 
            0x59ABE0CD37B1AD36ULL, 0x275FAE7B31A71301ULL, 0x4327EEF06C493FF1ULL, 0x9DA47AEFB85D1416ULL, 
            0xC68C6D7C7050F9FAULL, 0xAFCCBD9766126060ULL, 0xBFACADCB5A316364ULL, 0x33E3CC1A2A5A5E5BULL, 
            0x275970A831B884B7ULL, 0x5912A7EE4254C84BULL, 0xABA41230E61212CDULL, 0x9D091D402F6FABDDULL, 
            0x1CF891601F7C79A3ULL, 0x30B01D5D514E6EAEULL, 0xF882159A1E211D0BULL, 0x65345F3323B1D64BULL, 
            0x5F15FBEF54B02073ULL, 0xF52EB2A5C08193E4ULL, 0x5A0B5E3FBAF622C4ULL, 0x4CB52722B8E12105ULL, 
            0x52C2F15ABC63C46BULL, 0xF7DC30F473622122ULL, 0xCE01A29EEDD1C93FULL, 0x8E949833C4DD3F61ULL, 
            0xC63A72A2921B51DCULL, 0x04D0130FC783A715ULL, 0xDB8C48CCF1E9A0D3ULL, 0x0BC51B1E55F9D82AULL
        },
        {
            0xF47BB08D3D242E36ULL, 0x3C47E5629F67E1A2ULL, 0x80137B18073A28F3ULL, 0x63A1E4776F852DB9ULL, 
            0x3A3A020CCDBA07FBULL, 0xF79850BC5A4C3359ULL, 0x26F72AAC665DCBB5ULL, 0xA77711A57B3138D2ULL, 
            0x3E92E0459C4D691CULL, 0x418BE4E3BA95A05DULL, 0x0CB36C97C97E6CABULL, 0x9550247BC167A88FULL, 
            0xABB866F6A4B789F0ULL, 0x8AB05CDC488F851CULL, 0xE20DC0F6FE8DBB81ULL, 0x54072807F16501EAULL, 
            0x2295A8EFA8EEFE3AULL, 0x8D48DB30EAB9D578ULL, 0x7D8332CF6077E612ULL, 0xE01D10F7A321EBA1ULL, 
            0xE5C95938114E5B21ULL, 0x03A3E2962E097704ULL, 0x248D63EBD5F2775BULL, 0x085942FE62567DA0ULL, 
            0xCAADAD3092CA0274ULL, 0xEBDC95697682EA74ULL, 0x7E35458338FBA39AULL, 0x065F296C0331B38BULL, 
            0xB0E91A652E8C8473ULL, 0x57124F403D4DF7C5ULL, 0xF067205CF24CFD15ULL, 0xB57DFC2DABC2D13EULL
        },
        {
            0x9331CC2847653D06ULL, 0xC284AB0AD94DA86FULL, 0x6EB2CD34CA99ED08ULL, 0x699448FF29747465ULL, 
            0x584C403D111A6455ULL, 0x92A68F913656B277ULL, 0x822CB4C3CD45C7ECULL, 0xA2FC478CCCD78E2DULL, 
            0x634D8C62106237D4ULL, 0xA559737C27E60011ULL, 0x7D99E34530562ADBULL, 0x2E9DABEF397CF856ULL, 
            0x11D1811BB3FF10CDULL, 0xFC0972251BCAC5B2ULL, 0x755B5FA1B78A115FULL, 0xE08C54B7D41750B1ULL, 
            0xA0D80499F61CB6E0ULL, 0x8EFBB36D3402428DULL, 0xA373AA2AC93801C9ULL, 0x8CC0E9FCFE9AD389ULL, 
            0xA5FED9DDF47D5DE6ULL, 0x4E4CF22A9F5A689FULL, 0x2B3EF4261C12C08EULL, 0xD4639524AC6074EFULL, 
            0x34012791A79CC6D4ULL, 0xFE10F974E9257383ULL, 0x216C5A61A44C642BULL, 0xEF63DC1520C3190FULL, 
            0x37E350359F065459ULL, 0x9DB588B751781C31ULL, 0xF79C29A741371CE6ULL, 0x1A6939A51B07E15EULL
        },
        {
            0x31C84B13C8161554ULL, 0x83494A30F60F15D1ULL, 0xC33102B3B9E484FCULL, 0x496DE7AE9DA1653FULL, 
            0xA3F9BF3C5F0319ACULL, 0xCB8ADD865103071FULL, 0xC343BD397245D3FFULL, 0x06ADD37235BBD1FBULL, 
            0x3F713FE2727B18D9ULL, 0xB057AF96F1AD8E9CULL, 0xCA34EA222FB0FCCDULL, 0x0388B87C400C3BB2ULL, 
            0x73DAA90750D2B66CULL, 0xC553790AFC0578D2ULL, 0xC8236B4EF27CE53EULL, 0x89DE8465BC88EA22ULL, 
            0x8EF49A73A2B1FD63ULL, 0x7A894A2E768A2AD6ULL, 0x5389849C7FE078C8ULL, 0xA7F3F667243E2D6FULL, 
            0x50EFBCEFDAC27329ULL, 0x89F87F859D027ABBULL, 0x85624CDE90704B29ULL, 0xDA01DC01DFDED7F8ULL, 
            0x5082B5C64216F1EEULL, 0x0C2507CACD0E70DDULL, 0xF3F260D7120FB890ULL, 0x461C6658A49765FDULL, 
            0xFDA42BAA8A71DE5DULL, 0xC6BD8D4615EC089EULL, 0x6B6F9EEECB0A2BECULL, 0xF3961F4124315717ULL
        },
        {
            0x1ED3CB31B2B8B5CAULL, 0xEF1A704D8171695BULL, 0x7839C899CD297A51ULL, 0xB0838C9481F67C9CULL, 
            0x18A0DA1668F890D0ULL, 0x0C59E00FFFB760D7ULL, 0x3D954134E3793C66ULL, 0x60F99E4444FDD164ULL, 
            0x07719483E3BFE875ULL, 0x1D6CEC4F74186986ULL, 0x20A1662A4B09A5F6ULL, 0xBCDB6D09FBFA7AFAULL, 
            0x3A6C1C7A2FE68DA4ULL, 0xB13052C322768E9DULL, 0xF929B9A751C3A919ULL, 0x9A65969107EB26AFULL, 
            0x6FD2F5B635424701ULL, 0x64AE6EDCBBCD9BAAULL, 0xEB39F1E310156716ULL, 0x3517A03D22DAE4E0ULL, 
            0x6DAAB75D3D564846ULL, 0xFEEACA0AD5379E15ULL, 0xE6A7CD2F919857B7ULL, 0x1A8CC50E5E816E71ULL, 
            0x3301B95E590C6CEDULL, 0x7D89D69790423F6CULL, 0x313CD257D2CCC331ULL, 0xF0C441559C65A654ULL, 
            0xB6C0E355EE289D59ULL, 0x953064A50EA64F80ULL, 0xEB4588839466285FULL, 0x847394884880E0FAULL
        },
        {
            0x859EC6DEF24ABEDCULL, 0xD3D3A09587E17E82ULL, 0x7C48C18B8FF51E25ULL, 0x7CEB8ECE97B9E059ULL, 
            0x57E4EF56A478841FULL, 0x2A649B246196DCBCULL, 0x6D0A3BBC7CC0BF0EULL, 0x2671E371CD3FA6C7ULL, 
            0xD1D440E7C2D0CCEFULL, 0x77E650B493B66EBBULL, 0xB2B464B387AAE373ULL, 0xB12BAD16462F2AEBULL, 
            0x87E4D67D24EAE2F6ULL, 0x1155D7676160D275ULL, 0x48A545B3604685A9ULL, 0x028B1C8DEB42D8C2ULL, 
            0xE9761FFEE7521224ULL, 0xC90301827D3E1E57ULL, 0x3F0A93C380A7F28AULL, 0xC5C1C508165B04B4ULL, 
            0x6592189A9467A380ULL, 0x09E0838348BCA736ULL, 0x57689DC3224C0F92ULL, 0xC373ABB6C4A7EB91ULL, 
            0x0276038220BA9A12ULL, 0xC99D000FDDE0A626ULL, 0xA54A6569D81534EAULL, 0xA0609265625DF63FULL, 
            0x6EE3FA02B2ED7F48ULL, 0xC6B09032E51B9A77ULL, 0x23AC0AB2DAAF163FULL, 0x4319091C7F3F3BE5ULL
        }
    },
    {
        {
            0x0160846C955F6B66ULL, 0x5446AE9E2EA58905ULL, 0x94101E150A9049E9ULL, 0xB91DF8763E1DB17CULL, 
            0x162140E29C30CDB7ULL, 0xB7EC2935BC56F245ULL, 0xF819AB12F2D7790CULL, 0x6CF925B309F6FB59ULL, 
            0xDEC819FF2ED51389ULL, 0xA2F3FA0568E71D9FULL, 0xCB99CDA44BFB40ECULL, 0xE7BA35465B4B6AE5ULL, 
            0xB9D269E3EE29077DULL, 0x0A227FF37385511BULL, 0x0D719B7B1FCE3E0CULL, 0x2A1DE5B3342C3B0EULL, 
            0x8037960FA5747104ULL, 0x4B662E50FAC554A6ULL, 0x4CB1C1A88EEFFC12ULL, 0x9A64418082DE8638ULL, 
            0x3DB19A4E0FFFFDFEULL, 0x838BA8E2BE36B5B4ULL, 0xB6CE32EEC911D260ULL, 0xD8E27CD5294DEF8AULL, 
            0xE3499665778B16DDULL, 0x5050888CC96146D1ULL, 0xB3857270F26643CAULL, 0x4000F5B66E1872C5ULL, 
            0x3F8C3596F4D8F53DULL, 0xDC583CA42B8C169EULL, 0x050C7D8004D67FC8ULL, 0x5264091728024E36ULL
        },
        {
            0x758789443457722FULL, 0xE558E60F1C2F278EULL, 0x2B465077DF7FAB1CULL, 0x3DA25FB5FC5CD57FULL, 
            0xA27190A2DF5FE11CULL, 0xA7356F503F7E1F55ULL, 0x0978D4735FF9495EULL, 0xD528CA90364FF141ULL, 
            0xD3AEEFA7749A6287ULL, 0x47A8E7DA871CDBC0ULL, 0x8363BEDA8DD05BE1ULL, 0x63093DC9D62C93CCULL, 
            0xCD04C148609E21B4ULL, 0x407A8302E4312F80ULL, 0x2615453EEBDF4720ULL, 0x75969C81D9D87FE8ULL, 
            0x785F6D22F13C2489ULL, 0x598912F25A3B6139ULL, 0x509D2D9C4A91CBE0ULL, 0x47E81CBFCB2CF4C2ULL, 
            0xB1084DA9A520ECDDULL, 0x19D8EB6AAAEE5F1DULL, 0x95FCFB59EB8C0986ULL, 0x95E6E9C4C96BD355ULL, 
            0x84DCB24494A067DEULL, 0x5FE937CA69D07229ULL, 0x0604D95D3B6C7FA7ULL, 0x3891CAA17DB0ECB9ULL, 
            0x1340ED6FA4DA1108ULL, 0xC265A8AB5184F7F8ULL, 0xD4C159E8AB4DD08CULL, 0x40F0B651BAA0582AULL
        },
        {
            0x0C092D82E7AC1A3AULL, 0x98E494DEF70FFC33ULL, 0xA7FD21E54CAC16AFULL, 0x659049E78F061F8DULL, 
            0x65534C00D1A0CE26ULL, 0xBE0BB1445B57E010ULL, 0x15807050A7A617A9ULL, 0x3F86EDFB2A8E5F8CULL, 
            0xCDC83CBA04370958ULL, 0xFA2A44651DC2EE68ULL, 0xBE7CEB49BB137AACULL, 0xD14022643DE633D8ULL, 
            0xF6BE7C7CDE48D6F0ULL, 0xF8F0A0BE1A85EE0DULL, 0x974E994E9C44C8CBULL, 0xA6D486B43120D4D0ULL, 
            0xF576D084115945BCULL, 0x596632A28D4687ECULL, 0xC7613065FF71A65FULL, 0x3926FD91D0177186ULL, 
            0x9925137856D3ABD0ULL, 0x4D091AD51CDEC8E0ULL, 0xEE33CFAEA373DB23ULL, 0x934CA1118EBE38D5ULL, 
            0x9CE86AA6533D6B02ULL, 0xF20A8F29A7EC9488ULL, 0xD2F9990B0AE64DBAULL, 0xA2B8D2C9D155C924ULL, 
            0x269DAAB0D1AA1E95ULL, 0xBCA36CFFAB3FA471ULL, 0x89D93E46CCCDFAA8ULL, 0x786B22D2F62082A4ULL
        },
        {
            0x0BAAEC63625C2AAFULL, 0x5B2CEC0AF620FDE2ULL, 0x18A9002CEDACC7D8ULL, 0xED18DBB295CCAD4AULL, 
            0x0519F72990EB8ECEULL, 0xCFDB91703AE01F54ULL, 0x8FAA45FF62E0F8F7ULL, 0x39CBDEE45835C6D6ULL, 
            0x49DDFBFEF7149467ULL, 0xA8526D775DC51599ULL, 0xD8AADCE0DBBA2CF2ULL, 0x95E505AF048FBE12ULL, 
            0x794458E434F7830EULL, 0xF0EC4A38148FAA55ULL, 0x65C8E0050289D5E5ULL, 0x4590E241889826A0ULL, 
            0xE88F79682BB70A9BULL, 0x620006A2F2C9A310ULL, 0x2C5ABA7585AB3C28ULL, 0x7120862152E6FE37ULL, 
            0xAC11B8B246D29060ULL, 0x93540FE259D4F509ULL, 0x6E51392CD61392E7ULL, 0x15901416E2E0C935ULL, 
            0xC0FF2785EDEFE846ULL, 0xAAD8A0158AAC40CEULL, 0x34FA4406E18966EAULL, 0x14DFE2152E061C3BULL, 
            0xD760949FB4A6119DULL, 0x3BFF00686D852B3DULL, 0x6617BA6E209506FCULL, 0x668C710D6555130AULL
        },
        {
            0x9FA2DA0B83937466ULL, 0xADEB018C8E7FFB7FULL, 0x25CBFB0BDDAF248EULL, 0xBA940D7AF6558FC1ULL, 
            0x198D76546499FAE4ULL, 0xECDAA30DFD2ABF3DULL, 0x928F3EAD833D8529ULL, 0x1A1E862910E69039ULL, 
            0x64CD4642E6919A70ULL, 0x12CF23CD1A1873A9ULL, 0xDCA9E84F2B37EEA3ULL, 0x28B768FD7946661AULL, 
            0x0B16B4EAD340F9C4ULL, 0x368F58535353C6A4ULL, 0xFA1543CD50C18BD2ULL, 0xDF62B310A84CD279ULL, 
            0x8D5F84BF6B1EA389ULL, 0x9D7C0B441AD20414ULL, 0x97914A57143D78E1ULL, 0x09F01394621FC724ULL, 
            0xE861639284BA495AULL, 0x4AB07CC6FE9519D1ULL, 0xB7725F09482F17E0ULL, 0xA6D8CBAC1F9AD83DULL, 
            0x1DC78117F9405F80ULL, 0x01B2DB9813369BC7ULL, 0xB776056F7CEC5BC3ULL, 0xD6C62BAC59DB7B7FULL, 
            0x6642BA553FD34701ULL, 0x5A0F58BE3FF6D5B6ULL, 0xC68411149174254FULL, 0xC2DE22A7B1CC33B6ULL
        },
        {
            0x700428BFB01D8193ULL, 0xE050F5CD0C2ECA74ULL, 0x2B0754C912754FE7ULL, 0x58C10FF845E731A8ULL, 
            0xA9256CDF03F0FD55ULL, 0xDAEDD2D6E726F236ULL, 0xE917DD4381B848FEULL, 0x97DBD01857350B95ULL, 
            0x0530F1284544C804ULL, 0xD5F337D210AEC17CULL, 0x0462CD13BE32DAA0ULL, 0x4104CBCB08C78208ULL, 
            0x176062042B526D6CULL, 0xCE341FA5824767E5ULL, 0x0A52C734FFFF9598ULL, 0x67E364F172670879ULL, 
            0x7E8E5CF389337C2AULL, 0xF9A1BBA4313D7E79ULL, 0xB1D6EED8E71443FFULL, 0xA066045BCECD434DULL, 
            0xE3BEE54089CF7F15ULL, 0xDA054C71F0DBE1B5ULL, 0x2C9E66D26BE46000ULL, 0xEF1827501528443BULL, 
            0xB4601310D36E365AULL, 0x183D916F18EF7B54ULL, 0xE992F534E6B4000DULL, 0xC91974EB65BCD173ULL, 
            0xAEB4F041B7872912ULL, 0xA231F738A6F733AEULL, 0x7D32A39DF2610CF4ULL, 0xB1749606E809C7DBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseEConstants = {
    0x14838ACB859BC64DULL,
    0x891FE7D0AEFF8AFCULL,
    0xF34713854DE053A4ULL,
    0x14838ACB859BC64DULL,
    0x891FE7D0AEFF8AFCULL,
    0xF34713854DE053A4ULL,
    0x3D8121817D51A37AULL,
    0xD16206810CEF704AULL,
    0xCD,
    0xF9,
    0x8D,
    0x48,
    0xC7,
    0xFC,
    0x08,
    0xD5
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseFSalts = {
    {
        {
            0x8CC7E8FD9696C1A6ULL, 0x0A91C720C905FBF4ULL, 0x618EB4FE50B210F6ULL, 0xDC416CCF5B74BFF1ULL, 
            0x7C8538C136E7C5CCULL, 0xAD3F3484D2C34686ULL, 0xACF66A90048F6647ULL, 0x4F3E5A923EB06CF6ULL, 
            0x9DED3EF81536BA22ULL, 0xA9FF73707CB60D86ULL, 0x520B643F9A18C722ULL, 0x33DCC539799BF878ULL, 
            0x646D79631110D65DULL, 0x01C4215C25F64D95ULL, 0x4BB83318A85DA619ULL, 0xB07DBA4D460F392AULL, 
            0xB6B21996CB2CDD81ULL, 0xF1E3360602C7C5A2ULL, 0x4E921CD739671E8FULL, 0x98357031B806E25EULL, 
            0x574420F6FE7DD62FULL, 0x276D604CE9FEFBF2ULL, 0xE2B29F8446C870B9ULL, 0x0676214CE7570946ULL, 
            0x8C606947F1EA1F22ULL, 0xF2331C47FD95B32FULL, 0xF3D17DCB5C2C2AAAULL, 0x053669EE5A8D48B9ULL, 
            0x6776E46B1C9B45E4ULL, 0xF2819CF220C4F96DULL, 0xA75AB4E5B31401A0ULL, 0x4A5D594441E0B4F3ULL
        },
        {
            0x0A328E972DE77888ULL, 0xCDA41388E4670A2EULL, 0xFF804F29C86F2FC1ULL, 0xAECA6097CDD7435DULL, 
            0xBAE88D6F03F08003ULL, 0xF67C6BEBBFAEB551ULL, 0x48B405F616C657C1ULL, 0xA0109225306D89F0ULL, 
            0x63782187AA2C4BD8ULL, 0xDF1D443B6F16DCF8ULL, 0x808441C3B56CF8E7ULL, 0xFF547EAF1D90F70DULL, 
            0xBE4E1E035A5B9844ULL, 0x35853A7477B3BDF4ULL, 0xE6085376F792E3E0ULL, 0x50A3EC99AB63277DULL, 
            0xB2AB71684792BE33ULL, 0xB8041C640D9AD916ULL, 0xBE04678137A04433ULL, 0xEE48B1E02C142128ULL, 
            0x01E3CC124D1B1C1CULL, 0x161BCE8C97200AA6ULL, 0xD81F02BBA6A507FAULL, 0xBBC13EA7CC5C697EULL, 
            0x98A44799F6A80CF1ULL, 0x60EDEFF81A57D519ULL, 0xFB261550CF1C93DCULL, 0x0C906D93371EE006ULL, 
            0xA55F3298F682236DULL, 0x01F6EF067BD66900ULL, 0x3F156CED908F0F85ULL, 0x2F7C7AFFDD948701ULL
        },
        {
            0x432DA692EB81D476ULL, 0x110EE974C5BEF53FULL, 0xB21518A60CD2A765ULL, 0x8A09B6A769E794A0ULL, 
            0xCC7D58A8645953D6ULL, 0xC92707120AEB76A9ULL, 0x75D487378FF3B139ULL, 0xF7FC688897542166ULL, 
            0x6CA52B8C828FEA99ULL, 0x00870E6D2708682EULL, 0x19F7C50BC5502523ULL, 0x035679A0C03E6533ULL, 
            0xECC6C70165B5A61CULL, 0x0442D7D399CA7980ULL, 0x9D584B805F4F5671ULL, 0x7B74266907767A94ULL, 
            0x3524571D2D3880C9ULL, 0x6A0265455D51F6ECULL, 0x1FA1E8FF2A591333ULL, 0x16BB066B1C6EB22DULL, 
            0xB9B36A5BEA81BCF0ULL, 0x028A127C6D18D0BFULL, 0x93837B691F3A0C48ULL, 0x2C12B23D45D5DF3DULL, 
            0x5659C92710799C21ULL, 0x0A5B1F653EBB9248ULL, 0x6CFE652BBC7CED69ULL, 0x7662A74F4DAFB685ULL, 
            0x56AE321CD594A01BULL, 0xD96081E5317DCA29ULL, 0xAF8B5D7FE42EFD83ULL, 0x88D551C9BB65609FULL
        },
        {
            0x5ECC188D544EF645ULL, 0xB3196B2BDE58A3FEULL, 0xFDA30A3D9934A814ULL, 0x040CE924A3EB9BA9ULL, 
            0x7A3BA966A9FB3FEEULL, 0x4C5FB03CB4F50EBEULL, 0xC7837B9B0039CEFEULL, 0xEC10E97E082FCDE1ULL, 
            0x839B1276C02C8CCCULL, 0x20A433B8A9888BB9ULL, 0x263CAFC608E95E45ULL, 0x1A4E8E7AD62775EEULL, 
            0x7F1C6A975F9E2AF2ULL, 0x61AAF96013C4E005ULL, 0x20E782F0FB3183D5ULL, 0xAC2F5FE499EC9B26ULL, 
            0xD489FAF270903210ULL, 0x2DC902487DF13E2EULL, 0x93257A207820293DULL, 0xD4E01F1AED5F650FULL, 
            0x1E07C03D925D7607ULL, 0x18331446FB4374CBULL, 0xB0DB2B85711528EFULL, 0xBC5247BE53D98718ULL, 
            0x73831A44398BCA99ULL, 0x4D25F9FD18487C37ULL, 0x0B39392F70E5FB34ULL, 0x901618394B7829FCULL, 
            0x8700875BDAA27AC1ULL, 0x1097CC9DDADA2C02ULL, 0x0AA62DA8CB9AF6A9ULL, 0xAF6A6DF813C6DAE2ULL
        },
        {
            0x5C5FB64E14184DB0ULL, 0x39AB8DD5E01C6FB3ULL, 0x84D982568EE41486ULL, 0x2932424157FE80B8ULL, 
            0xC713799A6BAFA27EULL, 0x640129B7167C0E0FULL, 0x45D70C32E738880BULL, 0x3B17BEADC7BE7D4DULL, 
            0xB7C1B3707344204BULL, 0x3F7490426BE64277ULL, 0xD27BF9B64B18AC68ULL, 0xDF5D0818E76AC6D3ULL, 
            0xE36B096F02386D46ULL, 0x95DAD09B5B4B2EC0ULL, 0x9AEC7EB16708E21EULL, 0xE7FF0D00E4DBAA53ULL, 
            0x1F6B8BDBFB3279A7ULL, 0x7438B582C0DE8393ULL, 0x19A843EE54B8AEF6ULL, 0x6B810E678A3005D0ULL, 
            0x2F939015568AD3C1ULL, 0xD0C6CCAAB0E9CEF1ULL, 0x14EB2465573BBAF8ULL, 0x5D33C174301B0440ULL, 
            0xD4B395728E23C90DULL, 0x3AC9DD1D4E21636BULL, 0x5BACC4653F0AFAA9ULL, 0x4A9A58C3E5A46B13ULL, 
            0xF1017117E19AEB5AULL, 0xC46DE5717523A0C6ULL, 0xFC4C389BE000297BULL, 0xF1AE409C1615ABE4ULL
        },
        {
            0x7D82068E2C677CFFULL, 0xD261DCAB1B89BA24ULL, 0x41262A3403AA7D37ULL, 0x1B25494514D2B664ULL, 
            0xCD68E5E512B672E5ULL, 0x99119A0EFD889FE5ULL, 0x00BCD44DC60250E7ULL, 0x19EC0EB6BD754897ULL, 
            0x82D5D12809F63F17ULL, 0x17282693EB6D68B2ULL, 0x30318DF12A06671AULL, 0xA4893B37E3D5AC47ULL, 
            0x2EAC97542D8F6625ULL, 0x1CF7DA2F8BB79B60ULL, 0xD7FC002268A523BEULL, 0x74F34D7B342568D6ULL, 
            0x7EB6666206751969ULL, 0xDF9F4E14859FE626ULL, 0xCFCF7CED53212198ULL, 0xD2313ED5702BD77CULL, 
            0x46393C046BD21951ULL, 0xE67E42A5AD04B5A0ULL, 0x731579D5C971AD79ULL, 0xDF2729BEB50016DFULL, 
            0x8EC52EB95E9DA527ULL, 0x9AD7AAEAE063D91FULL, 0xF213ED77DEAC406CULL, 0x5AC8EED47E8FB8BFULL, 
            0x16915930F5418C39ULL, 0xF5EBB60BE98673F4ULL, 0x952CDBAB733D966AULL, 0xD62A1E03143D8879ULL
        }
    },
    {
        {
            0x18280D1C176C5CD4ULL, 0x5E36F0058D16C05BULL, 0x6B0800B09979B5AEULL, 0xCBB042F55A2437C5ULL, 
            0xA51907328167E6EDULL, 0x1828E72D99FCF72FULL, 0xF4B9323B1B1A76A8ULL, 0xEE547EAE00C4889AULL, 
            0x92114E8D756E0D64ULL, 0x200A4924410C385EULL, 0x9C99D9F8946DA05EULL, 0xB956A9E6931C9DD0ULL, 
            0x688C0170E0AD6D08ULL, 0xE6C13C2FDA3C4234ULL, 0xF9679D4AE4CF725CULL, 0x64500DBBBA5E0437ULL, 
            0x6BCBA18DF7D21D91ULL, 0xD48E9B3AAE25BA32ULL, 0x23C8727E0B3E6D29ULL, 0x832CB1615E5D215BULL, 
            0x5A974D0DBD89FFB1ULL, 0xE734FF4572CC47DBULL, 0xE433E197AA58208CULL, 0x2577E252198CA487ULL, 
            0x6185ADCF43DB2E63ULL, 0x2794B9E3405C36EBULL, 0x52D3CA0638AF502EULL, 0x28A8274014FA339BULL, 
            0x4FFE36F1C6AE7F16ULL, 0xEDA5A568396A3470ULL, 0xB8E3F99F57EC4579ULL, 0xCB29786F09025919ULL
        },
        {
            0x805A885FBAB74D69ULL, 0xE53ABE0D9EC84781ULL, 0x48653D15803298D8ULL, 0x32F48A22541C2462ULL, 
            0xFD0825C06D592B09ULL, 0xBF6D44FA767A4611ULL, 0x7578FA26D1FF79D1ULL, 0xF4C1EC33DC9F2549ULL, 
            0x8DCDD85E526F4E3BULL, 0x3178F5689C266CF2ULL, 0x0E9CE7CA40E71513ULL, 0x144B9EAE3B87D63FULL, 
            0xFE9B569DA8E7542CULL, 0x88D04A58935A786CULL, 0x22E0AD954706DD2BULL, 0xCC5456C23B5C90A3ULL, 
            0x0D37A42A1CFE8ED3ULL, 0x9A0A908AD0AC58A2ULL, 0x2E4D351B6621D36AULL, 0x48EBF7412AE0AD21ULL, 
            0xA568D9BE52A49430ULL, 0x87BB30F773B6B9BAULL, 0x11225803D2DADA40ULL, 0xED80315A55328852ULL, 
            0x4CB2D2D2805F6F92ULL, 0xAD171E8022D71481ULL, 0x603393114699085AULL, 0x7E1E1CB2291B4BBDULL, 
            0xA0B01F4DBBF1B9E0ULL, 0x3921D395124D2120ULL, 0xD5769D5EB23300BCULL, 0x05805B0C5B42CEEAULL
        },
        {
            0x7DC890D70701DD15ULL, 0x75EABC7124C74419ULL, 0xDCF13FC75E5A4688ULL, 0x7D806DC8C4BC0E5DULL, 
            0xB6BB1D11ACF4389AULL, 0xA4ED94092E1E942FULL, 0x768CC7676F59CB28ULL, 0xC1F41DEA2069FF69ULL, 
            0xA9BBD19547C71E66ULL, 0x9E18D2A06A57226AULL, 0x3B7E40990ED10F14ULL, 0x46A06C0DE65BF343ULL, 
            0x94781AC2EF1E4066ULL, 0x9E99F06AE1A626CAULL, 0xB664F8130A41D020ULL, 0x007403E92CD76B28ULL, 
            0xF3EF2BB3D77D25C9ULL, 0x63E20DE02DC395CEULL, 0xF2DB719EA9DD818BULL, 0x66761E5C90B1A0E7ULL, 
            0x0C89392991C8D6C9ULL, 0x252D92FA62B19912ULL, 0x3F0409CAEEE39146ULL, 0x9D3C381B7EB46396ULL, 
            0x12EF7731C668B074ULL, 0x8F93F7DDDE898144ULL, 0x1B71B83D3F77A046ULL, 0x7E46AB6F33BC5AC4ULL, 
            0x1B9DB54AB80B10EEULL, 0xA14049A7D78C6038ULL, 0x19098662FCE2842CULL, 0x77D0DE1B06A877B5ULL
        },
        {
            0x496EDAEE6D25D973ULL, 0xB579B0141C5891F0ULL, 0x35B6118B6EB918B2ULL, 0x621F2F2F4772BC72ULL, 
            0x9410BDEE2744DCC5ULL, 0xB36D3E5C199F54B1ULL, 0x4F8A2A2F28A1750EULL, 0x6C2870F46CF19004ULL, 
            0xF851068DD5D846DDULL, 0x874EFAD34C81D3CBULL, 0x04A1A938FEBE9928ULL, 0x9F74D31F5F96B82EULL, 
            0x2FEF0FC3B3ACB613ULL, 0x1D3BF565D0CF76EAULL, 0x237BAC7830F7268CULL, 0xC70557C2007377BEULL, 
            0xDEA9CDBCA4AAF734ULL, 0x8EEE7E314F98951EULL, 0x714D35FE8617C102ULL, 0x1BEC6C68D22A0E60ULL, 
            0x4CE74CCFAE16A133ULL, 0x9CA2A40DAA345FF5ULL, 0x6A9C81278CD87AC9ULL, 0xF8CC32FED1733D0DULL, 
            0x6EEF1BAFBCACB449ULL, 0x23BCB4DB09210ACAULL, 0xCD116E19F63574B9ULL, 0xBA3D7740D7DC647AULL, 
            0x41535B1A4444921CULL, 0x4E91E8FD627B683BULL, 0x312F1DCC99D69009ULL, 0xBCF784659F9A7CEDULL
        },
        {
            0xC2ECE8AE5BB54F23ULL, 0x0C8CA234154E299FULL, 0xE5D273B373257AADULL, 0xA6F952B3E693B53AULL, 
            0x73E79AB041AB2546ULL, 0xDB7E6385BF1434DAULL, 0x5C91CDCDC5F5BBBFULL, 0xF23E199821F8C0FDULL, 
            0xF3FF7E568597D915ULL, 0x4E6456B2104B9767ULL, 0x23A4D52CBB5D2AE7ULL, 0x2447AC0B226BD8A2ULL, 
            0xBAF5965F652A3E75ULL, 0x54D618CBC46DAA29ULL, 0x8E7D25C3A801BB0FULL, 0xEE8224EA0782ACC3ULL, 
            0xDBDD392F86BC34EEULL, 0x5A413BBF07972436ULL, 0xD9F1362FFD28DD26ULL, 0xFB51D7C8539BE708ULL, 
            0x27D37373FDEFE23BULL, 0x05220A50DE691400ULL, 0x535464336292BBFBULL, 0x13FAC1FDAEAEBE3CULL, 
            0x145E18D8F50C58DBULL, 0x55248592DB084FD7ULL, 0x175C855CF53A85F1ULL, 0x5C89C0F61345748EULL, 
            0x96516B56373B4E55ULL, 0x8F0F70FE7DADEEBEULL, 0x85AED6ED99DC8F26ULL, 0x17696EE21590AF9FULL
        },
        {
            0xA9E72C9A39AAAB17ULL, 0x78EC9B4E43923E66ULL, 0xC246596E685D9972ULL, 0x1AC3E0A9C01794D2ULL, 
            0x499FAC0451A892D0ULL, 0x0E5D074FC639DDEFULL, 0xA3CF1F3820EE5A6BULL, 0x9C2F9D14FE3BC7C6ULL, 
            0xC81094C7DE77BF58ULL, 0x9DEA19F3788E8940ULL, 0x64502AB935E3AB46ULL, 0x934B78296160D9E1ULL, 
            0xFEF08FE97A5EEA29ULL, 0xFECA1F3B1F687D51ULL, 0x07320854FE93932EULL, 0x7D4BE28FD8C3259FULL, 
            0x7451D29967D4827EULL, 0xD5975361583BC681ULL, 0x7D8AF3C689687EF5ULL, 0xE39310A98B9D66CFULL, 
            0x8C096B689C939643ULL, 0xCDF46AD0D90AE363ULL, 0x948ACF854C1A75BEULL, 0xD2DD926ADFF46E2AULL, 
            0x63FC73B9E6098260ULL, 0xDF02953F0E676193ULL, 0x13DC5857805804F0ULL, 0x3AE1A4475BD80B6CULL, 
            0xA6A631B548C0DEB6ULL, 0x0AA0B60056AACDAEULL, 0x2390A6B896FCEECCULL, 0x8A452D922205BFFFULL
        }
    },
    {
        {
            0x95C8622D9A0C4CACULL, 0x847E86DD8E05E26DULL, 0x363AB5030448A527ULL, 0xA4B8D96CE438210EULL, 
            0x2D0CC94705CB1A63ULL, 0xC48451202EF8083AULL, 0x91524716DD2D54B7ULL, 0x5CA9D97197BF8287ULL, 
            0xE9A11846FBE47D95ULL, 0x71DF2121F17FC9AAULL, 0x98DEEC078288889BULL, 0x91D351A9401AB396ULL, 
            0x755DE5C3D120C330ULL, 0x9C1AFFE5DA2AE21BULL, 0x2C0862D90A14A5BAULL, 0x8662DA2791F7038CULL, 
            0xC7F8C36400504B55ULL, 0x9962DB5491519537ULL, 0x17A3663EF3E9F926ULL, 0xDCBA08B1705FE4A5ULL, 
            0x45EEB04565D79953ULL, 0x5CD38BD6698DB5CAULL, 0xF9E885A359CFAADBULL, 0x77E494049D30A720ULL, 
            0x9D20B39EE17595E6ULL, 0xA944ADE68AEEB424ULL, 0x17058EA214354ECAULL, 0x74BF6C1205FFE160ULL, 
            0xB07C6920085F707BULL, 0x1208C2D4D9B30538ULL, 0x98200DB347C5F2F9ULL, 0x1974152B868BA492ULL
        },
        {
            0x434F08EBAF656FA2ULL, 0x7FBE9CAFF9D6F6AAULL, 0x4A1AC9DEBBB0FDF4ULL, 0x8AAD71ADFEC2ADD2ULL, 
            0xD52E8A819D74CC2FULL, 0xAD752D35AB9BFC32ULL, 0x60848A0A52C6CB4DULL, 0x2EF62C44073A72BFULL, 
            0x3F13575D8EBCAA0CULL, 0x8DEB8CFF003CE57CULL, 0x4C3DA5840BA12DD0ULL, 0x21773339C891E5ABULL, 
            0x6A271C6F145D88EAULL, 0x32DD8FFB457F06CFULL, 0xD6A4C225A7398C6EULL, 0xBE9CD5784E840378ULL, 
            0x934BD7B378E948CCULL, 0x140AD057F14C77DFULL, 0x608227F83C5763BDULL, 0x66AD274197B85C3FULL, 
            0xBA2CD2DF906347BBULL, 0x6F77C4FF410A89CDULL, 0xFF609CD9237DC125ULL, 0xA39F354023895927ULL, 
            0x64667DA713F498B7ULL, 0xB7C105D3DEE34E9AULL, 0x83FA2E93B2040904ULL, 0xDD74D6EC5311B7E3ULL, 
            0xFFEBC30FA5FBE22BULL, 0xF6BD4D64622681AEULL, 0xA82AE3D57FEBC5F4ULL, 0x47DAABE8F1C1F1B8ULL
        },
        {
            0x66F097A5F40B4F10ULL, 0x3D8159190C3BC2D7ULL, 0x09FA504BC287BE3DULL, 0xAA2BB52BF33C7650ULL, 
            0x7CB229D16EB167F1ULL, 0x09B1A127CB2F3B26ULL, 0x168D689045C9E48CULL, 0x47782FDC8FAF1917ULL, 
            0x2FFB5A4BC24B0DB7ULL, 0x556395C564A4D973ULL, 0x814EAFFF95B6B195ULL, 0xD4E8A0431227CB71ULL, 
            0x21701C9FDA8CEADDULL, 0x46019DC7D27C7D88ULL, 0xF379FB826B37A905ULL, 0x18D8598A563C1A37ULL, 
            0xFDD4DEB64F1967F6ULL, 0x5D589927B00193B8ULL, 0xEE816E36FA8085EDULL, 0x4BD8AF681D45E52DULL, 
            0x0264E4BC555D81F6ULL, 0x4CB4C1CDB5F9BC11ULL, 0xC4084D033A05BD56ULL, 0x8EDE4667C4170B73ULL, 
            0x76BDBF5FE47277BBULL, 0xAD2D17F9323AB5F1ULL, 0x2D47729CF64621FBULL, 0x86FD178F3C358910ULL, 
            0xCC103A02103BFCADULL, 0xD707694CA6C000B8ULL, 0x363EB89358D5BBB9ULL, 0xA845885ADA01CCC3ULL
        },
        {
            0x2B00C4EAF21BEDA8ULL, 0x829FF8C27751A508ULL, 0x8B043667594F9A6FULL, 0xBD10898B9859D92CULL, 
            0xA94643F3F3FD962BULL, 0xD561DD7C3B03A1ADULL, 0xB0E6516FDD427995ULL, 0xDD3740826FF678ABULL, 
            0xA6FD6790B4C70782ULL, 0x6D9083418093FEDAULL, 0xBC8D44B470C28B1CULL, 0x0D06D5BF1FB5C739ULL, 
            0x307D1FF14CF87F38ULL, 0xDA95A5A31ED271C2ULL, 0x179025CB8ACA61A4ULL, 0x500D2C46CBB6C44BULL, 
            0xC91C7263BD229A54ULL, 0x9C7088519A247E5CULL, 0x35007E50D6456209ULL, 0x0FF28D113B6E0925ULL, 
            0x08D091125623A947ULL, 0x7B9BF77A88D072E6ULL, 0xC0BC14067E3E1D27ULL, 0x07546B681323862CULL, 
            0xEA4726051E4179D7ULL, 0x73E466220C756850ULL, 0xAD287F4842309DC7ULL, 0xDEACF16705563E17ULL, 
            0x166EDA1B3941AAA4ULL, 0x03BDE93713ECD726ULL, 0xDC9ED855B0C75871ULL, 0x40513CA821B183A8ULL
        },
        {
            0xD40CA6293DCB938DULL, 0xFC4FC4CE35ADE005ULL, 0x40EA9A2756E49387ULL, 0xBD3892893E4A867DULL, 
            0x6744BA4ADCCA371BULL, 0xEB60E4C5AE8C8D52ULL, 0xA3AA8D9A04B19874ULL, 0xC77D322AC57A87CCULL, 
            0x73738ECAC292823FULL, 0x3171FA2CC4801347ULL, 0x3842414BA84BCB56ULL, 0xCE96F4D59D046DD5ULL, 
            0xCD81698F389FF492ULL, 0x36273AD066EED38BULL, 0x58763525CBA12274ULL, 0x51B451CEFC341C23ULL, 
            0xBA375B688632E2C4ULL, 0xA08BCA5C515F0412ULL, 0x4092F56851ED7554ULL, 0x08724BBD91799E34ULL, 
            0x298C8041C6EA2FA0ULL, 0x3F4BA08F49F42D95ULL, 0xD2EBD1CF2487EF77ULL, 0x682770FF9C20DF17ULL, 
            0x5C35A6EB96B8CFDBULL, 0xA1CF18BFE6436F92ULL, 0x051A31E25A10CFF8ULL, 0x382211F25EF6EDF2ULL, 
            0x49C6D8F47B136124ULL, 0xF66F5AF819B79B32ULL, 0xC2CBF5BC553A646EULL, 0xC6D1F0148A3B3697ULL
        },
        {
            0xD5FD9A82713C4CA0ULL, 0x0701D6AEE6B1269CULL, 0x69C410A92961AD55ULL, 0x6FF663D15DFBB812ULL, 
            0xD0E50C9090F0ECCBULL, 0x2E1576377279438FULL, 0x64F40F28A186633BULL, 0x1988216F00834EE1ULL, 
            0xFCC996AC75BA7AA5ULL, 0x83A96B81AF593131ULL, 0x18B9BB5C6C543EBBULL, 0xC77F3376569E43A6ULL, 
            0x80A2E87F5B58DD90ULL, 0x4720CDB94962B404ULL, 0xE5F0B79FCCD35F7DULL, 0xC818A4FAFCDAFE15ULL, 
            0x3923B15C414E8EF6ULL, 0xCE156C396893BB14ULL, 0x6272DFF48C93AEABULL, 0xB4A081EA2D41DAB9ULL, 
            0xC4800CA9A0501A9FULL, 0xF3013A8656A01F9DULL, 0xBA8B0051553AA94FULL, 0x0D890457360F9A9EULL, 
            0x64F3DFF1CED78CEAULL, 0x8B8B9DFD870398EFULL, 0x9DC76B3D556C1A25ULL, 0x4A4B0BD8582D0D45ULL, 
            0x78C7B03D71300BB9ULL, 0x1DE353AAA7B6A86CULL, 0xC041399E8F662885ULL, 0x00393796B53F0BD6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseFConstants = {
    0x54C80FCA20FBA189ULL,
    0x1CBAF38C92318B3BULL,
    0xBAA4AAC985ACD670ULL,
    0x54C80FCA20FBA189ULL,
    0x1CBAF38C92318B3BULL,
    0xBAA4AAC985ACD670ULL,
    0xF8B12989DEEB0B33ULL,
    0xB83AB3424FCF8970ULL,
    0xAA,
    0x44,
    0xE0,
    0x31,
    0x71,
    0x3D,
    0xD1,
    0x31
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseGSalts = {
    {
        {
            0xA5D2A76C5A45495BULL, 0x432859921575CC7BULL, 0x9A08FF59172AA868ULL, 0xDDAB23B56F5A21CBULL, 
            0xF495DF9B14FFB13CULL, 0xD3805BB847FB2BD9ULL, 0x37B67FCB75402045ULL, 0x605F742E77C8A855ULL, 
            0xAFD6386934653FCFULL, 0x937DDD1B6086D966ULL, 0x731CD613A2C8150EULL, 0xAC11354A72DF80A2ULL, 
            0x1FA7F1E372065F97ULL, 0xB76D6B2889B01F99ULL, 0xCB278ACA59DBC49FULL, 0x73EA5F28DE011C91ULL, 
            0x34E4F5E44F321613ULL, 0xAEC0CB32FE2BC2BDULL, 0xB0D13C5D68F048CEULL, 0xB0CC3335157AC7F7ULL, 
            0x0389A6017B6BC397ULL, 0x103224970411ACB8ULL, 0xA16A4A481FC0B1C4ULL, 0x7215DB1721CF9D34ULL, 
            0x61841ECD1D5C6FEAULL, 0x27A13F9706D5D027ULL, 0x5527597CDCCAEFB6ULL, 0x7A03787A583CD552ULL, 
            0xB92905D0743668C6ULL, 0xA844112323623E57ULL, 0xEA0AC4EC6F44114BULL, 0x30E82781BE5E4DE0ULL
        },
        {
            0x376AF4081F215684ULL, 0xEB6DF23C962AE097ULL, 0xF9C13B653BC99AC0ULL, 0x4951F17E246020A2ULL, 
            0xCF985CE51AF398B6ULL, 0x3C980BC4A0B433E2ULL, 0xB7355065F577641CULL, 0x659F0AE24EFB6E4BULL, 
            0x7ACECD1A371DC3C0ULL, 0x75A2FB8196630B43ULL, 0x4C6F44B73F74A1D5ULL, 0x9DBBA25AFA61271DULL, 
            0xC07E51F306A10839ULL, 0x500AC407AD3C5268ULL, 0xA79D0DD40F02C3F0ULL, 0x02A960313B7F9B16ULL, 
            0xE91258166FA6071CULL, 0x96B188E934149748ULL, 0x417EF0BD5886F1C0ULL, 0xD984DA958D444F9EULL, 
            0x662064BC3C2ACF6AULL, 0xED2BFE911E4B8BBAULL, 0x938D4C8E1A25F9E7ULL, 0xD44A82A939DBA5B2ULL, 
            0xDFDBDA1EC76519ACULL, 0x47F0BFA941FBD697ULL, 0x1AC10F7513F10071ULL, 0x1BDEB71F76B77046ULL, 
            0xD5763AB271F4A4A9ULL, 0x0CA56C5DDBFA97BFULL, 0x3F852F4B28D0996EULL, 0x85E477DE1640FD50ULL
        },
        {
            0x0004FDA7AF8BCFA8ULL, 0xCE8986A91E56BEAAULL, 0x4F834E86D53BEAD5ULL, 0xD96CF9423322F07DULL, 
            0x686088C7F4AB9F26ULL, 0xDA82278590B31DB6ULL, 0xA83BDA9F4B11D309ULL, 0x2AC06F31C58921B5ULL, 
            0xF55DA23676D7FF04ULL, 0x7093743183D5D65FULL, 0x1C4BEE6530029358ULL, 0x5A92A40BD605EC61ULL, 
            0xA88EA48B8D333266ULL, 0x662BBB938D47137CULL, 0x1EAC756B5DCC08C8ULL, 0xEF38329B6A387162ULL, 
            0xB5D835029089D3BFULL, 0x54A6CD83166AB3FFULL, 0x6DFCA364AAABF7FBULL, 0x29433EE247CCF6DFULL, 
            0xC44299FE4B5576B1ULL, 0x56FECA85F4331BD9ULL, 0x597A18B468E57693ULL, 0x28B2E7F617B34E72ULL, 
            0xCEAE1D1EB7047B12ULL, 0x5B84644D34A20D38ULL, 0x5A31B89A15D9509FULL, 0xEC62AC2A8DDDF5C6ULL, 
            0x9E127C39CC9EFD6BULL, 0x3D4262F1DD044DBCULL, 0x25DB063AE41C13E7ULL, 0x6CD5DB98B20FFA9CULL
        },
        {
            0x6BC2794057F7613DULL, 0x5243A9C864376C97ULL, 0xF7487B40BBD1DCD2ULL, 0x07F7947EC34CC0D5ULL, 
            0x12EA405E8B12399BULL, 0xAC4EDAA4508B3E82ULL, 0x71174CF5EA68F33BULL, 0x1CA2644904DD3512ULL, 
            0xC9306047F0D7B6B4ULL, 0x829F00EDE074FD21ULL, 0xE5855C112E151F55ULL, 0x5686F48C419C9FDDULL, 
            0xFC5EC4A4BA699114ULL, 0x1BBBE0A2D6297E1FULL, 0x7073BC3CE1A19FEDULL, 0x9275715110B8A4DAULL, 
            0x7C8262B7BAA2575DULL, 0x6E613A21E46406D2ULL, 0x222343E9A6D11A63ULL, 0x1EEE100F88F312DCULL, 
            0xA7F8A9FEBBB7E7BDULL, 0xF00A7D5CFE8BDD51ULL, 0x2CC422B2E62B6F04ULL, 0x8F3122FC7BB654E4ULL, 
            0xAEEAB20FB199A891ULL, 0x99FF7040ABEE196BULL, 0xC40809DE31986D27ULL, 0x66601BDAAC882655ULL, 
            0x9E2BE985C9CB6750ULL, 0x87A3CC3179476DA6ULL, 0x16D06695AFC29CAEULL, 0xAAA6411213E1B2E6ULL
        },
        {
            0xEF8DB6E14B8756DFULL, 0x5D2546D83372D047ULL, 0x087B3C005B1E9E42ULL, 0x8A85173FE5F63C14ULL, 
            0x5FDCBB377A545D8EULL, 0x5149BACC90038096ULL, 0x0A1C58D051601130ULL, 0xEB9B68A659A4BA7CULL, 
            0xF58E93C98352B844ULL, 0xCDDD4528F440CA60ULL, 0x7486E0B3E2D930BDULL, 0x5A648B998CE927C5ULL, 
            0x8BBC509ECFFEF785ULL, 0x2152B76B24F8608BULL, 0x96138A7D6DCF7ED8ULL, 0xC37E51228B476107ULL, 
            0x8C58E3F6E8A1BDDDULL, 0xE5EF4A4AF961C57FULL, 0x8FD5ADBDF24E81C3ULL, 0xE2AD1DAA41F834DEULL, 
            0x3407136B52C04316ULL, 0x40DBC5DABAEDC693ULL, 0x395393971BA30AADULL, 0xD94539EA2DA82100ULL, 
            0xD9305AB37C5B172DULL, 0x63001E28571AE027ULL, 0xC79BAB80C90B32D3ULL, 0x97B2D2C4DC1E3754ULL, 
            0x8C3D2C5AD22FA352ULL, 0xAB9489BD28C96918ULL, 0xF3A42E0E90D606D0ULL, 0x0A0DED180B5B231FULL
        },
        {
            0x1C5BC37B9E41B054ULL, 0x8529854DD8720801ULL, 0xBD40E553DB7C70E1ULL, 0x1802CC4E9DA01F3FULL, 
            0x4C71FEF1C75CC8DDULL, 0x639A8082EFDCEC9EULL, 0xB0251FAD161A9A7DULL, 0x2AC7A1DAB23FBAB3ULL, 
            0xB605BBE49781D8D4ULL, 0x8A1B5F9FFB37A017ULL, 0x477138F6CEADADB7ULL, 0x71967A6B31A69BA4ULL, 
            0x96DABBE319931A85ULL, 0xCBD2B9894A3D20C6ULL, 0x938BC090E04D7EE9ULL, 0x3C2A2A4687CE8D9BULL, 
            0x1D556662D241FFA3ULL, 0xC597E1AE1DB9D96CULL, 0x9F561D2212D479EFULL, 0x6BA8140895B8E0A7ULL, 
            0xEF51108B5644F9EBULL, 0x7ACA6D3D278A976FULL, 0x3E9E67015B3076CBULL, 0xCA9CAA49739F0929ULL, 
            0x9CA9AA4ACD29F63CULL, 0x4BEEDDBDEBA24114ULL, 0xBF1B939AF101F762ULL, 0x530B571CF1012667ULL, 
            0x1D9098B896E624E1ULL, 0xA03018E21BC7E4FAULL, 0xACA4A0AB24F58BD1ULL, 0x89AF1BE282445D5CULL
        }
    },
    {
        {
            0x7E1C01FF6829F233ULL, 0xE9155096CF226612ULL, 0x76B766536D898CFFULL, 0x5C788E83937C6A79ULL, 
            0x06CF07EEF7EA23AEULL, 0x40C8D5D639BEBC74ULL, 0x9139F2A1DA7C02B4ULL, 0x7120BBE330B94F58ULL, 
            0x9D63976CBAF2BC83ULL, 0xCE5FFF5986789478ULL, 0xD4A79B44255FDD8FULL, 0xC34B4D314FC6618AULL, 
            0x0B00E3FCC8F15530ULL, 0x597BB887F621189FULL, 0x9273921B97CD3541ULL, 0xCDC0B75EB7C58EC8ULL, 
            0xCAA07B2D798228CBULL, 0xC03CD218623071AFULL, 0x4034FBD118EFC717ULL, 0x378065556EA30F74ULL, 
            0x8B93FC4A7FDBB19BULL, 0x3B426F35D7B9B6DAULL, 0x5CA3C8F1D92F7D74ULL, 0xE7EF0AE75942F3B3ULL, 
            0x286847BD93B6679BULL, 0x3ED29ABF11A05B18ULL, 0xAA0AF91DDB3C948CULL, 0x9609AC62CABD4DCDULL, 
            0xA948CFDF5BEDD959ULL, 0xDBA1DFCB6C54D3BDULL, 0xE2588FB3A2810DE1ULL, 0x4FE3719611B903A3ULL
        },
        {
            0xA5BFDCFF01CCBCD1ULL, 0x028259DC0766B525ULL, 0xA8A269B1B1F66A18ULL, 0xB2B52253F4979257ULL, 
            0x8C43D6A9B94B342DULL, 0x278BAE79E9E84865ULL, 0xB677B8FACDC4B8F4ULL, 0x06522FCD33118A07ULL, 
            0x90D958A2B0728E2EULL, 0x88614F0F1789E71BULL, 0x9B6EA7575EEF51D3ULL, 0x03373C984174674DULL, 
            0xBF0E08FA73679573ULL, 0x78C9F2D660ECE76BULL, 0x29ECD007C9988420ULL, 0x9A80EAECD604196CULL, 
            0x1A64516791EA228EULL, 0xDABA3BF418225C2EULL, 0x25A9317A177D83F7ULL, 0x510F790FE86DCB4DULL, 
            0xF11AA79359125BEDULL, 0x33146F12B62CCF70ULL, 0xF6913FB61B0994EAULL, 0xA4C95E7707652523ULL, 
            0x9151CDF5FB1EB47FULL, 0x386C647DD6B04AE1ULL, 0x2B3277E07DE52ADAULL, 0xAA4BAD414B2C3419ULL, 
            0x3C47DD693D86219AULL, 0x43500E28AC3022D4ULL, 0x7C831E684F4FBC85ULL, 0x977FDECFA97FED0AULL
        },
        {
            0x8319FBACB19BE579ULL, 0xBAFA762B529F3E41ULL, 0x8D34A76C5BA14845ULL, 0xD085CBC21C6FD82EULL, 
            0xDEFB4C8F4F9E2A62ULL, 0xE26F3DE585FBC24BULL, 0x284DF8F89A70D1B4ULL, 0x213E262906697045ULL, 
            0xFF6AA8BD8A53825EULL, 0x0FEC12BB3D5F7E31ULL, 0x54E476DD0ACE18C9ULL, 0xCC1A65BC2C5A613FULL, 
            0x92638174BD6187ADULL, 0xF71F7188C053E49DULL, 0x9DDE7716AA87E18DULL, 0x17189BEEE5051260ULL, 
            0x753E7F05AFBAC7F1ULL, 0x77126455213D02CAULL, 0x18978CBA7C9D03F8ULL, 0xF33F1AA11944CF55ULL, 
            0x5F53ADC0661EB58CULL, 0x1F4A2FB921AE5077ULL, 0x2C693162617F2E75ULL, 0x638FBCD8945A2500ULL, 
            0x28C89453CD26133EULL, 0xC33FDA534C084B38ULL, 0x38890518DEBF605CULL, 0x9B80A635E71AAE1EULL, 
            0x3D7ACE74BF0E2BEEULL, 0x0E44A2470FFADA12ULL, 0xDF6F84E2B47C6789ULL, 0x62A12B514F31B8C7ULL
        },
        {
            0x82A1F3BC3C481F09ULL, 0xE37D27F5991C8AA8ULL, 0x50F96E7448CACCC7ULL, 0x150A991A544C9034ULL, 
            0x1B43D56109D8D0F3ULL, 0x3979C311A9B1D938ULL, 0x3AE321BDCF65D792ULL, 0xC223AA7F4CEB86F7ULL, 
            0x921F8F8C19D8419BULL, 0x36A898DB0116F240ULL, 0x4F810268A54FD12AULL, 0xFF2DE2970C6912F4ULL, 
            0x7AF9E08631A12042ULL, 0xE8454F51D5722E64ULL, 0xB5D2317C275F6CD8ULL, 0xC733EA471444F22EULL, 
            0x53EBB0F24FC570C3ULL, 0x04441B58B8C08F67ULL, 0xE7594D59B6871693ULL, 0x0088552900117AC8ULL, 
            0x74A759194940F1F7ULL, 0x6CEC232BADD189DBULL, 0x3B9E37777E7E5E29ULL, 0x85B161CF18267E59ULL, 
            0x95EF90BD12DAD93FULL, 0x3EB018E7986FA3E1ULL, 0xD2D8778548B96CD8ULL, 0x9ED63EF1264577FCULL, 
            0x242C3E0CBE93446AULL, 0x348738CA32064219ULL, 0xB12A4DCEEBFC692FULL, 0xCC7D5629C9E63A92ULL
        },
        {
            0x19CA2D951CC96F2CULL, 0x9C6B69FA090D94FEULL, 0xE0F658E43704DD96ULL, 0xA86E932440A0C230ULL, 
            0xC78F725E1E58E2CFULL, 0x466B38652E437F1DULL, 0x79254CC7060AC272ULL, 0xDECD1151C11B25A6ULL, 
            0x91ADBF3CFA10393FULL, 0xD6454FC2A686FDCAULL, 0x9116F9A61C338BFAULL, 0xC49AB773FBC25D72ULL, 
            0x5F661BC5CB617D84ULL, 0xBBEA53F311549638ULL, 0x67326EC8575271F4ULL, 0xB07BDC68B3AB8EAAULL, 
            0xC1D620BD96F94634ULL, 0x27160FA9909FAA57ULL, 0x39B0BE2EC66B85FAULL, 0x8BA54B007596B40CULL, 
            0x55F86E1FF4801898ULL, 0x9D203B17CF52578AULL, 0x1E5F656E1A7F5E99ULL, 0x5E0633AFA8FD374BULL, 
            0xE5C70684A692E9E1ULL, 0x531530984BED7915ULL, 0x3348E100644C778BULL, 0x38DD67BA29EA335EULL, 
            0xACDA9A7E558B6CC1ULL, 0xFBFDB3F0D01047C4ULL, 0x605262E77B371DF5ULL, 0xDCFD252D1957BE4CULL
        },
        {
            0x3B07180E54055DA2ULL, 0x9A9478ADC46CF211ULL, 0x1AAA93D956964467ULL, 0x747C100048545FAAULL, 
            0x0F3570C8ED92D7D4ULL, 0xB9FE70FD99E780BFULL, 0xE38B3C14F0EE060AULL, 0x35B9CE8A9C00AE80ULL, 
            0x3E4A95E503913362ULL, 0x6A5BF87252514B22ULL, 0x303BA92DF9656BCBULL, 0xC1906581753C8D68ULL, 
            0x2EEBCAA473B45AF3ULL, 0x7245DE51631B2DFFULL, 0x1E64AB910510DC86ULL, 0x111104E6C72CA0CAULL, 
            0x3C61046EEAE2476DULL, 0x658405BAD29ED98FULL, 0xC79B75589729A1D7ULL, 0xF53AD77D148D61EDULL, 
            0x25E407A403FB120EULL, 0x91B6F26CEC8E52D2ULL, 0xAED7025EE8C99FCFULL, 0xD5DA6F20C095D68CULL, 
            0x6762565BCCF0B4AEULL, 0xD19BB1BE240E8AC7ULL, 0x6FAF063B3CE7C453ULL, 0x35D8C6AB84F417F5ULL, 
            0xE1483485C5F95021ULL, 0x5368B0CDFDF4B41EULL, 0xCEFB768276FE537BULL, 0x551274C5A61ADDCEULL
        }
    },
    {
        {
            0x92D1771A718AF701ULL, 0x8669BD04CAF0631FULL, 0x60C1F11038E87DD8ULL, 0x65A72FD26C375CC2ULL, 
            0x0960DD275DDDD753ULL, 0x3AEBF048BC4522E4ULL, 0xB2C81572AF6F5B40ULL, 0x6E0658B9B1DBEA36ULL, 
            0x2A425383D2684EF2ULL, 0xCBE2D110FD999799ULL, 0x3DD4CB9AC376505BULL, 0x40557E95BBF5AF14ULL, 
            0x844D540F416E28A2ULL, 0x93626178443D42A9ULL, 0x4FD339B8810C24FAULL, 0xE1A43D0991D32907ULL, 
            0x0E2B557C35F89346ULL, 0x1E9D0CA62A831311ULL, 0x11FA060C2CA55FE0ULL, 0x2A61891ED51C26C1ULL, 
            0x806BF3D81523094DULL, 0x85EDBF07BD98DEE2ULL, 0x46CE58B65C1CCC0BULL, 0x4BBC4591827B8F94ULL, 
            0x2125E2203476615BULL, 0x1824D54AE3AD03F4ULL, 0xD455A31BB05AD013ULL, 0x1140B38EEA26CA5DULL, 
            0xACAE7C47E4E38445ULL, 0x056C8D06ACE5D4A5ULL, 0x52A4A81356960287ULL, 0xFE8B56CEC2D4FC58ULL
        },
        {
            0x1291B9A1CD95BE49ULL, 0x624F125153B411CCULL, 0xFFDB77E20E0A0417ULL, 0xCBE70BC7A58D22AAULL, 
            0x23C8102F1087D58EULL, 0x9AD5F2649D3A48EEULL, 0xBE1C220BF8988455ULL, 0x0D0AFADFAFBC2640ULL, 
            0x49678C83585D0FA2ULL, 0xD7F2C6246F3DA050ULL, 0xAE897F003A785AA9ULL, 0x20F9F12B14AF7ED5ULL, 
            0x9A94E2DC62AD24FEULL, 0xB06251B34C1A140FULL, 0x8787057F80F39392ULL, 0x8BFD40D329383435ULL, 
            0x7EF96E0300FA6397ULL, 0xB05724509FFA14F2ULL, 0xCF1313F097FB36FAULL, 0xB3C69358129B5942ULL, 
            0x1472F29578874D65ULL, 0x17DB6A85EF2A43FEULL, 0x0866C2E33B1AD81BULL, 0xC59B496FCC8D3268ULL, 
            0xAC88BC100E4E536BULL, 0xCDBCBBE3C135F289ULL, 0x3D698905CC61AB43ULL, 0x2730A4F984A35E1EULL, 
            0xDDEE43C0AB8A4919ULL, 0x5C231F3353154E2EULL, 0xFB95A7415F2857FBULL, 0x8152A48973DA1586ULL
        },
        {
            0xDFCD2222992E3853ULL, 0xB9DCC1BB5DB73CA8ULL, 0xA76E6FAD88B1C294ULL, 0x4E0F13DE365B77FDULL, 
            0x0857B8CBF0CFBCC9ULL, 0x7F7DF0CFB95D1793ULL, 0x3EA59F585876EDBBULL, 0x67D344AA298C267EULL, 
            0x8E06A9B60C27EC45ULL, 0x5C746448A1CA9580ULL, 0x6E5BC2854A5BA276ULL, 0x01CA5B02146D6FDDULL, 
            0xD63CDF1CB31C9043ULL, 0x86FE0B7F5D61BEE7ULL, 0xEFE1B8DB324B71C1ULL, 0x6622908BAB95E81AULL, 
            0x70438FF12EC24684ULL, 0x04F114B52CAB93DFULL, 0xB0AE9E8D7B1EC400ULL, 0x058E67EFB7B8C191ULL, 
            0xA4F49F0A5589938EULL, 0xCC63FEC64A0A3B26ULL, 0xD293AE02F56540D2ULL, 0x50985C8FA99167B4ULL, 
            0xF8273C668A2E5E1AULL, 0x7B3B8D28FBA1BBEDULL, 0x7921E69EC36DA2A0ULL, 0xB6C76E16E99144EFULL, 
            0x5BDD8FE24FC391ACULL, 0x0F281019D0D37EA6ULL, 0xE3238392A9667C32ULL, 0xA00965A93C57C440ULL
        },
        {
            0xE9FB8712478E0B47ULL, 0x7DDD5D1DEC1DA0EDULL, 0x0D059F9DACE52679ULL, 0xE57B298568F5868EULL, 
            0x6AF5D48832851DB8ULL, 0x150A2A53D40081F4ULL, 0x5154AA7B1179989BULL, 0x5BD61DDD1474E4ABULL, 
            0x26C4DE6D79AC7137ULL, 0xBF61DA04879C297CULL, 0x228CB7259CB57634ULL, 0xC7B217D3EDBC0E41ULL, 
            0xFDAE76BD292C063CULL, 0x0F974E0A1E41B1D9ULL, 0x45F87FF85458C8C4ULL, 0x1AFA1AB9BC1EA1F8ULL, 
            0x359F6F42EDB7E860ULL, 0x75C65400E9AF0E77ULL, 0x8DF94EAB47D7699FULL, 0xD2979E552A0ECE09ULL, 
            0x21AC44CC9278982AULL, 0x53F753AB02B47106ULL, 0x3B8862A9339515C5ULL, 0x989823C6293474C1ULL, 
            0x04BDB6C30AF34428ULL, 0xB3791948B5397807ULL, 0x1BBFADF7CAB857B4ULL, 0x66B59F107A0A46A0ULL, 
            0xDF84B77D3BB6D8F8ULL, 0xE1F5C805CC1A838EULL, 0xD44C64607A1DEE5CULL, 0x4B368115E8EF7E7FULL
        },
        {
            0x0D9743D9D71EE51AULL, 0x99BBF28C97C8907EULL, 0x58E81A52686853D3ULL, 0x3C55CDEF58817EC0ULL, 
            0xD50D4A9282D07F84ULL, 0xF3ABE3B5184EBF67ULL, 0x6F6140B3834DDDECULL, 0x90F6B4478D5DB33AULL, 
            0x3FD838C8EA915571ULL, 0x6191591A42FB4CBFULL, 0x6BFB9D93C0ADFCB3ULL, 0xD7C856918AC1361BULL, 
            0xAC33C6F877B67CD4ULL, 0x2B16EFEBA9B8556BULL, 0x9EEA6B5FD692778DULL, 0x7E3B59C97B3EFA99ULL, 
            0x8FE591EF9C631935ULL, 0xC3AD027F150EDC35ULL, 0xC0BF07747577F80BULL, 0xFB479EBD475B8C9AULL, 
            0xEC23B4D10BE4D726ULL, 0x9698C7EAD3F38C8CULL, 0xE9038ACA2FD10038ULL, 0xB2A1B9CBB47D29E4ULL, 
            0xFC693494448A7590ULL, 0x8B9D8FD8B5369174ULL, 0xE0ADADA8A69D7DC1ULL, 0x8EECD7B1AF5A779CULL, 
            0xED6EE1BA8D67DC1FULL, 0x3221334A6A965324ULL, 0x4FBF795275AB18BFULL, 0x3669EC7D5EC3B3CEULL
        },
        {
            0xA20AA42D0E0970B9ULL, 0x51A42A4000AF90DAULL, 0x06D8E7900735BB8AULL, 0x01C97E88F420CFAFULL, 
            0xD53C72331369114CULL, 0x0851D7CF225CDD0CULL, 0x14C4F2B235269A01ULL, 0xE17E2E285C5ACC64ULL, 
            0x1F816B588E1CCEAFULL, 0x52C0754D60101263ULL, 0x8D0700A5D8406810ULL, 0x477BE00B368313E5ULL, 
            0x2069954906270F9CULL, 0xCAFD57D0D1AB7CF2ULL, 0x5331A8E71673C31EULL, 0xDFF4AEE04E8726A1ULL, 
            0xE962AB678868BE80ULL, 0xC4F8660E782AAF88ULL, 0x4E3258283FA42060ULL, 0x9CB09AF55893A924ULL, 
            0x90F4FFC27D4DBD8BULL, 0x2ADB388FB81FF1D5ULL, 0x20477AABD4D50029ULL, 0x5C90FC52113AC87FULL, 
            0x204C41430F141EABULL, 0x4DB2ACF7FF8C8C9FULL, 0xABDA5CDB4481C41FULL, 0x153254A64DBD22A2ULL, 
            0x0A27DF8CFE6C9AC4ULL, 0x2E176215A52DB87FULL, 0x3AE7651C5FFE78C7ULL, 0x3D1626C8C781530AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseGConstants = {
    0x0AA4D963DE0A03EEULL,
    0x8FEDF404DA860B60ULL,
    0x9F3920A1E9D3D94CULL,
    0x0AA4D963DE0A03EEULL,
    0x8FEDF404DA860B60ULL,
    0x9F3920A1E9D3D94CULL,
    0xFE823035F986CBF6ULL,
    0xF5C78E560B6A1202ULL,
    0xCF,
    0x28,
    0x24,
    0x32,
    0x08,
    0xA7,
    0xD1,
    0xD0
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseHSalts = {
    {
        {
            0xEBFC027355142F04ULL, 0xF9DA3290F95B6E8DULL, 0xF7F9F4D87FA24BEBULL, 0xE411D54F65CB9ABCULL, 
            0x743834D58DC1A3EDULL, 0x05933B192C256E42ULL, 0x8FF09BC958C3DF69ULL, 0xD58AF5940AEE6BA7ULL, 
            0x39B8E25E1DDDE7B5ULL, 0x38A1D1F00ED09D1AULL, 0x82E38B3B7C6EE82BULL, 0x2A18A4BC50DC108CULL, 
            0xDEF492308C3F7EC9ULL, 0xEDDA521125AC8020ULL, 0xE4977E6C203AB974ULL, 0x4321E001C9FB3225ULL, 
            0xF0A48F66DF0323A7ULL, 0x05CAE0E38D3A0DB2ULL, 0xE79068BBC21C659AULL, 0xF7E96C03367BAFD8ULL, 
            0x4E6A81AED8BB8B2BULL, 0x359F722E1F0AC027ULL, 0x445A3A0120BCBB85ULL, 0x874E0D6D64704054ULL, 
            0xCDFB0DA06E0B263AULL, 0x71BA86EEB6D1FF62ULL, 0x1C2ECA4CB23B4153ULL, 0xF876E7A958C880FDULL, 
            0x8E4F2112CD9BDBF0ULL, 0x047F435E2B109973ULL, 0xCCE2149893483CACULL, 0x25C1EB2250928466ULL
        },
        {
            0xDEEFB583CC72043EULL, 0x066704CA14D04E9EULL, 0x9ED98DE6CB5F3644ULL, 0x786FE73E98F4C42DULL, 
            0x0431946F7C5D6D8BULL, 0x78C4876DB995483FULL, 0x43F5373657C48440ULL, 0x4EBA9552A267E8AAULL, 
            0x09F528D77AC0E31BULL, 0xC605F9CFCFDC1131ULL, 0xAF809E4A893B9636ULL, 0x925A95AA8790CBCEULL, 
            0x6E1F19F810A48A6DULL, 0x6617D4CCEF4D405DULL, 0xABCAB73B6697CBB1ULL, 0x2A2770511E2065A0ULL, 
            0x31D89395E4EEEF9EULL, 0x71222A4945C006C7ULL, 0x57DD15DCA2A45A58ULL, 0xF31D52340EFAA63FULL, 
            0x2F5A44B0109E9057ULL, 0x1BD2FCDDD822E024ULL, 0xF2E40D40DA95F872ULL, 0x61F21C3890402494ULL, 
            0x555F17A7695F9290ULL, 0x4927CE73B38578CAULL, 0x89C2C1F087520EE8ULL, 0x38AC56A008664490ULL, 
            0xB4320603349F283BULL, 0x24B152C4F4B0D05BULL, 0xF67C4C8D7CD7C9C2ULL, 0xF428D2A859963FE3ULL
        },
        {
            0x84CFCCFCAB4D12E9ULL, 0xA05A65F932A8ADBAULL, 0x49FDF5FF92188949ULL, 0x34ACBD1291BFE20BULL, 
            0x0F7D47B0CD53C153ULL, 0xCCFF690849A3518FULL, 0x2CE38AB0B49FE69EULL, 0x226B6CD46E5330D4ULL, 
            0x007938E927789DF0ULL, 0xB5250F1F47AEA7B4ULL, 0x4561F2F5B31D1DA2ULL, 0x35C1A1C5BF87CF8DULL, 
            0xC7FCFF0A9BD335BBULL, 0xB7E50C2BEEB91439ULL, 0xDA61AB9AA6AF2341ULL, 0x69F091D3B03944AFULL, 
            0xB45E12DEBAB0ED86ULL, 0xB8459ED846538D7DULL, 0x6772BC93799A3541ULL, 0xF29CFE48AB5E45FFULL, 
            0x1A539B49880421DAULL, 0x8649298FC7B7653EULL, 0xC0B861E99D87F1D0ULL, 0xA0135911DBBC302BULL, 
            0x7A035ED4D95FE0F2ULL, 0x1C793E1FE0BC28ADULL, 0x5F4AA286A64A8603ULL, 0xC6EF60AE4BD92232ULL, 
            0x0D5CF0079A8F75DAULL, 0x8127CAFDEF6BAF46ULL, 0xFDED4E6E31072620ULL, 0x6E6D18DA4E189D45ULL
        },
        {
            0xC10102422B3117C0ULL, 0x294E6A45E24D63AEULL, 0xF31D5AB0A0EEF48FULL, 0x458EE389FF47C172ULL, 
            0x0133792645DC10FCULL, 0xBC048827BEF3A1C4ULL, 0x46CA5B3D65CCBC3CULL, 0x236B9A57DA0DCBA9ULL, 
            0x0F42FBE9A75ED2D5ULL, 0xAE77304DAB45D4FBULL, 0x3DBEB3CD60B2ED24ULL, 0x7B69BADB66456CADULL, 
            0x3BA6B53B8FDEFF0EULL, 0x480022B9F3874693ULL, 0x1E5A7D8F302A38B6ULL, 0xE6407C62CE3305CBULL, 
            0xD4519FEE16C0C1A9ULL, 0x7985CC937F6A8015ULL, 0xF292ED39AD2BD8D8ULL, 0x005629FD124E3DF4ULL, 
            0xC6B63CFF2939B2B0ULL, 0xCC970C46E1E2C0EDULL, 0xA98B7C29317EFFD0ULL, 0x03C582149C712F6FULL, 
            0xC0477F108420681CULL, 0x1963EBF159F7C6E2ULL, 0x7CE10BA26DC1622DULL, 0x7CDE092C30B25DB2ULL, 
            0x5AD55BEA129307AFULL, 0x9D7F9A232B18CEC8ULL, 0xB0272877D942174DULL, 0x14CE39C496301B47ULL
        },
        {
            0xD7E0435F975E1F60ULL, 0xF870CFB67EEF527EULL, 0xD88C92837D790F0AULL, 0x958AB2B8ED8546D3ULL, 
            0x7B6817CD718B2DF1ULL, 0x40F8DAE46C0716C8ULL, 0x6C5D1D3752EB9FF0ULL, 0x146BCA97F71A69B2ULL, 
            0xA93FE25B19803937ULL, 0x08885553CF6852B7ULL, 0xDAD846B54696573DULL, 0x5A91379534C2975DULL, 
            0xCF409CD18C01CBF9ULL, 0xF816857BD7C33E58ULL, 0xD52966D08D40BE93ULL, 0x208C3CAB2490265FULL, 
            0xC29D1B09388D0D5DULL, 0xB197A0210DB6C3A6ULL, 0x03F99BBC98CABDE5ULL, 0x75308B09DDBC6C47ULL, 
            0x410084BFF6F6AA46ULL, 0xB99D644D53819C1BULL, 0x7BA283480DE538F3ULL, 0x16FDE22C214A1544ULL, 
            0xD3DF9E8779A99B30ULL, 0x670F6CAE84E119A9ULL, 0xD4DA6CAFAC19023AULL, 0x13EAF12A35E10CC1ULL, 
            0xB95B89079E094135ULL, 0xCAA7AD957965B34BULL, 0x4D3E98C9E87E405BULL, 0x7E90BF2C70E5948DULL
        },
        {
            0x343434BFAF363A59ULL, 0xDCAF0F0AC9CC9203ULL, 0x1AA45BE5E7E3FB6AULL, 0x86A5055068BF5F83ULL, 
            0xE4F09BAAB5D58506ULL, 0x5B2A3DEB08AD5E4AULL, 0x8D846CFEEF75B6E8ULL, 0xBEC8B759D1143317ULL, 
            0xBB17F4675D787964ULL, 0x11F876182C71DFC0ULL, 0x40EDFE98A60B082FULL, 0xAED1BEFDCD4A6552ULL, 
            0x1FF256A66598FD81ULL, 0x1F47BC17507D51FBULL, 0xC58F6835949EFC47ULL, 0xD8001E8B0E5A1A0BULL, 
            0x8674245C69A21994ULL, 0x6214FA688453F861ULL, 0x45C4152BD6308CBFULL, 0xA51A10D2E47CC7DAULL, 
            0x1E7B8E972696A65EULL, 0xF0283CF4A708C0D8ULL, 0x88862CEEA08CB551ULL, 0xB47679F068D9120CULL, 
            0xF687CBCB7190DFF4ULL, 0xC03B8C11223584C4ULL, 0x2155EEAC9C82358CULL, 0x0D5C18237D202D9FULL, 
            0x8D5DC09724FDA4C0ULL, 0x56D83AE62F471DCDULL, 0xF2FAF6D8D688D48DULL, 0xD9E904F607D37716ULL
        }
    },
    {
        {
            0x77E3C17760C0F43DULL, 0x90D22EF477963CC2ULL, 0xA398EE1287355588ULL, 0x2DA2A3996B0C5C59ULL, 
            0x9F3C79AB5EF92779ULL, 0x320ABEA1CFDC8762ULL, 0x43644E7F32B9127AULL, 0x8B6C868552EF575FULL, 
            0x49012BACE802687EULL, 0x8AAE0805131500C9ULL, 0x6B67F9335D66F602ULL, 0x34F48EF8DDE45F3AULL, 
            0xB23051248F0794E3ULL, 0x003461E2C923E01AULL, 0x5EB4CBC46132ABB9ULL, 0xFAFCA540FC7DA83FULL, 
            0x28A493030945424CULL, 0x5A90A607170A31F8ULL, 0xDAC9F9FB842DB40AULL, 0x1B70201828D49B0BULL, 
            0x79C79D9AB98DF84AULL, 0xA30E8772AA317D53ULL, 0x7F070A96FC28F80AULL, 0x6E56707FC74F4D80ULL, 
            0xB706E5917E33C2BEULL, 0x580B5D08F36FD2B9ULL, 0x2D96448713F72932ULL, 0xD058586B20F40B57ULL, 
            0x44314F87AF0346EAULL, 0x4F1014274F9C94E8ULL, 0xB7CD46EC341EC204ULL, 0x347871849746CF48ULL
        },
        {
            0x12BEB6A343E2D374ULL, 0x4A778823FCDCEE94ULL, 0x7368B8412299DD14ULL, 0xB3AEB8FE8AF96BA4ULL, 
            0x118088977D6AE6C8ULL, 0xA3C9B7BBCC5E3CDEULL, 0xBE8A95A1C60D0440ULL, 0x397291DA802D956CULL, 
            0x080E1267FAABB84AULL, 0xCA8A74B243A4D912ULL, 0x327708B7AF04E23CULL, 0xDDAAA4C48E4F56E8ULL, 
            0xA2D59CA09C73D066ULL, 0xF4C7BFD3AE00BFE3ULL, 0xA43469DDC007948EULL, 0xE11FFDC63291EF80ULL, 
            0x5445100B3F237105ULL, 0xE21791CB4DE9F315ULL, 0xFF811B33897B0A6AULL, 0x1AA7FBF005E3FC47ULL, 
            0x5E4622450183433EULL, 0xB164611EB4D3B921ULL, 0x35F338924D74E51CULL, 0x18EF75E8213D1CB7ULL, 
            0x2F0DD370EABDDCB1ULL, 0x274345232AA216BAULL, 0x7BCC5D7AF647852DULL, 0x5E2DD7E05163798AULL, 
            0xACF6F04613FB50BCULL, 0xCB1DA036F875C253ULL, 0xD70F32A80A066DF4ULL, 0x85093353369A35A1ULL
        },
        {
            0xBCB8E3BAD22B08DCULL, 0x684DE053C23410E6ULL, 0x2DDCFF5249E600E1ULL, 0xC1F4A80A5AEDED8CULL, 
            0x29F6C21E21D6AEEAULL, 0xC2EF0705FB1B2D6EULL, 0x0FE0EAA809932B9FULL, 0x4FEE742AE4A06A69ULL, 
            0x668F25EC9530FD55ULL, 0x2766A1754CF214B9ULL, 0xA36702254C592DF8ULL, 0x41096F0AA0C5AF22ULL, 
            0x46B40CE90FBC3E58ULL, 0xD2CE6117CBB16035ULL, 0x4D791B84024E6AF5ULL, 0xCFA3FBC719D5A229ULL, 
            0xF688611F37A8ADABULL, 0xD31FAF5686F6084BULL, 0xB24186A1202D00F1ULL, 0xD106F6F778906A65ULL, 
            0x5F83471215A0C39BULL, 0x277F5513E773BCE3ULL, 0x4B5B91FE4BEA6148ULL, 0x4D63D10E6B9F7044ULL, 
            0xE46E4B5539C89DA9ULL, 0x1FF90EEDF0C9AA18ULL, 0xF28E69594B4AFBF3ULL, 0x74951FB069EB07F1ULL, 
            0xAA0DF30DFF36B7DDULL, 0x1223A50F344FD15AULL, 0xE23EDB6D405AFAFAULL, 0xAB92B46418F6AB98ULL
        },
        {
            0xEBFAE2A6CBE51C43ULL, 0xFF14437513951B28ULL, 0x8BCDB222B517803DULL, 0xBF9139F0B653A38FULL, 
            0xBA5C323248030E1AULL, 0xEAF2860D1F2D2CD5ULL, 0xBE4B37267AFB3E33ULL, 0x1DE0AF12988BB28BULL, 
            0x165B5D30810FE977ULL, 0x8386B3BC1F0BF6B4ULL, 0xCA4460D22CFF0E0EULL, 0x2F78195AA89E404BULL, 
            0x82CA942DA73DDBB8ULL, 0xFE307EE1472A555CULL, 0x00C0AA553FE3D450ULL, 0xF5D029FD7459C505ULL, 
            0x767C9EC9D847B039ULL, 0xD61AEC21E560E9E9ULL, 0x64C8F7E865820541ULL, 0x2F7E9C3FF167E36DULL, 
            0x42B1C3E6D1374F61ULL, 0x2A63A57B7F63CA69ULL, 0x759A317A580F9D1BULL, 0xC1EB129E35986BBBULL, 
            0xFA28B57F067C6B7FULL, 0x76EF622F2AD04A39ULL, 0xEF9AD91503565EB6ULL, 0xC2847BF77AC8EDBBULL, 
            0x63E50BAD30EE6572ULL, 0x354F79B06944694DULL, 0x63C19BA5CC5ED1C6ULL, 0x1A08F4695B00879CULL
        },
        {
            0xA75176543EA28B4BULL, 0x42DFC48112B1F82BULL, 0x90A70C1FE9213813ULL, 0x754F09B4A61BDBCDULL, 
            0x5800B08561594A5BULL, 0xA3B31841944625ACULL, 0xF531BDCC87FD77F0ULL, 0x99DD8283CF49F645ULL, 
            0x6A2AB5734BD9E264ULL, 0x7484EA3734F04EE5ULL, 0x97F42BBD9D44D229ULL, 0xE18A4ED692523DF5ULL, 
            0xBE38778BB5CBDFD4ULL, 0x4494DEB67ACECDF4ULL, 0xDB552C2EB7E4E69FULL, 0x54E9422FA55F8942ULL, 
            0xE2DACAF8628EE7FCULL, 0x067EEE148E3B4B6BULL, 0x765F8FD7C0BB5BE0ULL, 0x0B4DFDB765495F89ULL, 
            0xD8D84587043EE653ULL, 0x5C4271E85EDCA1E7ULL, 0x654CD613F41F5ACCULL, 0x59BC8D900DB7ECD0ULL, 
            0xC8FDFF848B24C3D2ULL, 0xEA050A75926D4607ULL, 0xC552A07879EB1AD3ULL, 0x2AE0DB58476AAE53ULL, 
            0xBBBC57A4EBC97CC1ULL, 0x20048D5DF1FE6FE4ULL, 0xB43451DCFD54F5E9ULL, 0x4754156DEF3D959AULL
        },
        {
            0xAD319C17DF3361D9ULL, 0x373A20E154AB08B0ULL, 0x62F3C0B9D9F19970ULL, 0x93F46083DB9082C2ULL, 
            0x9F6722008AB6DA73ULL, 0xD19D9BD627CB0EC6ULL, 0xBB8BA0A56D70BD60ULL, 0x27B3ECF6DCEC2E8EULL, 
            0x669EEEAF6B0A4CD8ULL, 0x5663FE00564899CBULL, 0xEDF5BC70EDA4838EULL, 0x87FBE4FA741D4170ULL, 
            0xDCAB807E8BCD45CBULL, 0x29BB8962DECEC321ULL, 0x45DF07D2FE958B04ULL, 0x34528C5263756E1AULL, 
            0x4A101DB518BFD3B6ULL, 0x2E113C312726AD58ULL, 0x885B1CB816018239ULL, 0x8D3B8E86BCDD4FA5ULL, 
            0xD26AD8E0912423B0ULL, 0x773549D57151EF8FULL, 0x3EA3EE28E4F48520ULL, 0x5736E8CF162CECDCULL, 
            0xDC30457BEEA277CAULL, 0xA4B221EC4385445DULL, 0xB1A3F8F766E235ABULL, 0x50EFC8D4E105DFD9ULL, 
            0xC491A554A0B36DE6ULL, 0x6A98BB1125D35430ULL, 0x07A0EE876BCD0BC4ULL, 0x0B278A81CCE99B19ULL
        }
    },
    {
        {
            0x53499C9F09A3E32DULL, 0xD47EC7608C4EC931ULL, 0x899ED8863284E634ULL, 0xFB40BD395D192BF4ULL, 
            0x3C5CBA6469873000ULL, 0xB39F1F492BEF6B4EULL, 0x4ACD57A891B43DB2ULL, 0x46335CD3FEDB1739ULL, 
            0xDA64C079F5F42B14ULL, 0x52279F73937AA21DULL, 0xDE3843FDB22EE596ULL, 0x00CD02DA3CB8FB7EULL, 
            0x7589FE79FFD8A9BCULL, 0xBFD5A49D5C126857ULL, 0xDBF2E185BBF6257EULL, 0xAC72D2EFD194FBD2ULL, 
            0x5D732989CC95F426ULL, 0xA9F148C1A2CFB68DULL, 0xBCBCD3695CC0314CULL, 0xC78D54CCDC313628ULL, 
            0x568BEE4C6B2427F9ULL, 0x86FB32E4D056698DULL, 0x8BAFFCD17D04262FULL, 0xE5AE6EDAF6E84E35ULL, 
            0xA632D7FB1BB4FD73ULL, 0x988FEC0F77372D81ULL, 0xA526211CD18E7ECEULL, 0x8EEAC89EABE4CA9EULL, 
            0xDE22C341220A9514ULL, 0x8F297E13023FD67DULL, 0xE5393EA1234D8138ULL, 0x1CA84B3B2CF6430AULL
        },
        {
            0x8A5725C31309F541ULL, 0x07AB91DCF2C68BECULL, 0x2F58FD2A36248926ULL, 0x6018A70E31BCB680ULL, 
            0x4ED81B8FE630AAC5ULL, 0x54408939821A5C6BULL, 0xDCFB30212E6A931DULL, 0xD9610E1D9C1ED2B2ULL, 
            0xCD0D481F947A6815ULL, 0xEF2D1C537E95B907ULL, 0xBA8BC1E07E81EA73ULL, 0x7B2C73382586F5DAULL, 
            0x8E3F30D5A5D32EC0ULL, 0x291CA8F275580C0FULL, 0xECAD7D90FE61B90EULL, 0x7B1B8497FEB54D8DULL, 
            0x86AB42D88C6E25C2ULL, 0xBF674D32FFEC9A3CULL, 0x2AF3DCF1FFF7115CULL, 0x805411E4614829D1ULL, 
            0x4B41E8FB6AF5AED0ULL, 0x257E9EA04D74A70EULL, 0xFB275FDF7C738B5EULL, 0x85719C354C6619B3ULL, 
            0x38F687E80709D6B6ULL, 0x815B969017B29296ULL, 0xAB322FB3AF8EFA97ULL, 0x77EBED287A4D7F46ULL, 
            0xA8824167E4597DBCULL, 0xFF70DE1EC8C178A5ULL, 0x23BB8F15F22206A9ULL, 0x1F66F49382E2693CULL
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
            0xBD7028E7B6D808FCULL, 0x3C823D03F4CE57C5ULL, 0x54DDD4DAD70ADDB6ULL, 0x47C2C57842F09898ULL, 
            0x2258CE54D9BA70C9ULL, 0xCDF292B5951FA1D3ULL, 0x07D8D6718E3869DAULL, 0x96D14CBBD490E565ULL, 
            0x1AD5C898DE6AF3B5ULL, 0x6630EF121BF76AE3ULL, 0xC622C364A0C6FBCCULL, 0x63FD8458127AFE58ULL, 
            0x57719B8712C2A390ULL, 0x4937790A9C4B3267ULL, 0x27DD0BCD2B2C9B40ULL, 0x9D939737ECCFC8F6ULL, 
            0x1BD88823A73DE1C5ULL, 0x76E947DD55ADEA03ULL, 0x1E3C2D6ACC6D8AEBULL, 0x469A3FB6DEC3782DULL, 
            0xAC85B8EE63D2708CULL, 0xA7A1FBB704DA3C16ULL, 0xD1B8FC27924961EAULL, 0x24F3491725A0189FULL, 
            0xE89DF87B40429443ULL, 0x20F1AA749625FCEAULL, 0x2C9B1BA57500B2F4ULL, 0x2E03F2718F6D47D4ULL, 
            0x5E7A4D19A73B662BULL, 0xDCBC6B376585D224ULL, 0xA2383C32023B13C7ULL, 0x6F0981D3BB31ABC8ULL
        },
        {
            0x74267EEDA8E65762ULL, 0xEF8C778BA78C1180ULL, 0x4304F81DFF8E5E51ULL, 0xE5EB405E605C569CULL, 
            0x7F4FD460A3D7C908ULL, 0x2AA3A6B8FE4402B7ULL, 0x8D37274454C0CEFCULL, 0x5F0864AD92E4639FULL, 
            0xAE3FD4019C4C1ED4ULL, 0xCEC2A4CB41A2DBEBULL, 0x33C3601247ECB97AULL, 0xC06F359508C5BE45ULL, 
            0x47F301AA79196E67ULL, 0x74DE419F53A612C7ULL, 0xD6FC4CF9F8727A81ULL, 0x6FCD38F78BE152A1ULL, 
            0xFCB19B5FEEE7E124ULL, 0x44B60FB58057EBD8ULL, 0x1E7563F274B45FE8ULL, 0x10394FF8BB93C520ULL, 
            0x5CA71733213B820DULL, 0x72E1A79DE81DE786ULL, 0xC53C676CFFC7BCF3ULL, 0x68071005086F9088ULL, 
            0xC7E1A4A5485254C8ULL, 0x739CC6019A06E565ULL, 0x94142D1360E2DD6DULL, 0x28E5B2873CE44C44ULL, 
            0xF3A0F5F6EB00B42AULL, 0xAC490A4CE403978FULL, 0xBB621FCD2890F425ULL, 0xB36F26BF10F9E4C8ULL
        },
        {
            0x98B0A5A170E57D96ULL, 0x888750ADF156D2F7ULL, 0x09C748077ACB51E4ULL, 0x57FC4A1147E3A06AULL, 
            0xEB6318F0CEB1833FULL, 0x58009F78D69D9F22ULL, 0x109168A999EDF9B6ULL, 0x028CE8F31ECD91A1ULL, 
            0x9261311AD2A7D9B9ULL, 0x51ADA1B9BBCD9AB0ULL, 0x8771028ECA1D0E32ULL, 0x8D1D4C87D1CA2939ULL, 
            0xBF7ABFC3EF555BC7ULL, 0x4BFB568F8B16332AULL, 0x5992B06B2F8FE618ULL, 0xD4722F46E645EAD9ULL, 
            0x7DF43760B2F60E98ULL, 0x37D28CF9204C3DD7ULL, 0x4105630379F829EDULL, 0xB0E6B7FF7EA9408EULL, 
            0x18145F9D6CCA6DBFULL, 0x9C50BF5D8ED7E505ULL, 0xC62404B723EC7E2BULL, 0x9A1F4D14225625F8ULL, 
            0x101409575A195898ULL, 0x940B0B0500A7C6F6ULL, 0x813DAE63B48F181AULL, 0x7D8DA4CF26C4F24DULL, 
            0xF7D0AF3299D43348ULL, 0xC9F98368D8D2CBCCULL, 0xC3A0AE30DCB6E73EULL, 0xB5B4B0EF63D5F8EBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseHConstants = {
    0x2AE1A275CE839FB5ULL,
    0x44DE48BBAB1991B6ULL,
    0x49A4F58E6CBEA2F0ULL,
    0x2AE1A275CE839FB5ULL,
    0x44DE48BBAB1991B6ULL,
    0x49A4F58E6CBEA2F0ULL,
    0x289A0580BDB8D4D1ULL,
    0x4E7E2C85966358F4ULL,
    0x30,
    0xF7,
    0x8D,
    0x73,
    0xBF,
    0xEC,
    0x52,
    0x2B
};

