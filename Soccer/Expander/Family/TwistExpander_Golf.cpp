#include "TwistExpander_Golf.hpp"
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

TwistExpander_Golf::TwistExpander_Golf()
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

void TwistExpander_Golf::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 18343676784560811445U;
        aCarry = 10854738756512015478U;
        aWandererA = 13758593937724995259U;
        aWandererB = 12864304123800046094U;
        aWandererC = 12367851907621309586U;
        aWandererD = 16403677922196256551U;
        aWandererE = 9896507401800141232U;
        aWandererF = 13847703128823413019U;
        aWandererG = 15697775772674921593U;
        aWandererH = 15225052841627954271U;
        aWandererI = 9590120382295942191U;
        aWandererJ = 13374883539762954958U;
        aWandererK = 16767988910353091710U;
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
    TwistExpander_Golf_Arx aArx;
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
    TwistExpander_Golf_Arx aKDF_A_BArx;
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
    TwistExpander_Golf_Arx aKDF_A_CArx;
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
    TwistExpander_Golf_Arx aKDF_A_DArx;
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

void TwistExpander_Golf::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 11771684458500474723U;
        aCarry = 13402468088382650788U;
        aWandererA = 12767997363413593804U;
        aWandererB = 14690861112984163556U;
        aWandererC = 9689931680225038680U;
        aWandererD = 11150246912041079986U;
        aWandererE = 10789922587006897535U;
        aWandererF = 18057256257805206026U;
        aWandererG = 13229946797838143727U;
        aWandererH = 9690239115093718311U;
        aWandererI = 18104545069282187920U;
        aWandererJ = 13684395532363256919U;
        aWandererK = 17722602651151287222U;
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
    TwistExpander_Golf_Arx aKDF_B_AArx;
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
    TwistExpander_Golf_Arx aKDF_B_BArx;
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
    TwistExpander_Golf_Arx aKDF_B_CArx;
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

void TwistExpander_Golf::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_Golf_Arx aSeed_AArx;
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
    TwistExpander_Golf_Arx aSeed_BArx;
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
    TwistExpander_Golf_Arx aSeed_CArx;
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
    TwistExpander_Golf_Arx aSeed_DArx;
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
    TwistExpander_Golf_Arx aSeed_EArx;
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
    TwistExpander_Golf_Arx aSeed_FArx;
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
    TwistExpander_Golf_Arx aSeed_GArx;
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

        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Golf_Arx aGrow_AArx;
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
    TwistExpander_Golf_Arx aGrow_BArx;
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

void TwistExpander_Golf::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Golf::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 13131500601979799258U;
        aCarry = 17053200493561743149U;
        aWandererA = 10498113976971194170U;
        aWandererB = 15700630570720337807U;
        aWandererC = 17909421760779903047U;
        aWandererD = 17000651354838892063U;
        aWandererE = 14049791028667777444U;
        aWandererF = 16879575392271253701U;
        aWandererG = 9816727932348090521U;
        aWandererH = 12741926420872805902U;
        aWandererI = 15259844667719550849U;
        aWandererJ = 14190512729409079833U;
        aWandererK = 14725115352412404529U;
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
    TwistExpander_Golf_Arx aTwist_AArx;
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
    TwistExpander_Golf_Arx aTwist_BArx;
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
    TwistExpander_Golf_Arx aTwist_CArx;
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
    TwistExpander_Golf_Arx aTwist_DArx;
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
        TwistExpander_Golf_Arx aGrow_AArx;
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
        TwistExpander_Golf_Arx aGrow_BArx;
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

void TwistExpander_Golf::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 0, 3 with offsets 1545U, 1413U, 5536U, 927U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1545U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1413U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5536U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 927U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 3, 1 with offsets 5038U, 6615U, 1062U, 1564U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5038U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6615U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1062U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1564U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 1, 0 with offsets 2739U, 3674U, 7881U, 7664U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2739U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3674U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7881U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7664U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 2 with offsets 6677U, 2796U, 4359U, 2416U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6677U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2796U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4359U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2416U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 with offsets 1757U, 1263U, 54U, 974U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1757U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 54U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 974U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 0, 3 with offsets 943U, 86U, 447U, 1408U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 86U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 447U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 1475U, 522U, 1035U, 745U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 522U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1035U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 0, 2 with offsets 1722U, 174U, 1682U, 3U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1722U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1682U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 921U, 1052U, 334U, 589U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 921U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1052U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 334U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 589U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Golf::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 0, 2 with offsets 8169U, 2276U, 2515U, 248U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8169U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2276U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2515U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 248U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 3, 1 with offsets 7689U, 5986U, 6239U, 3099U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7689U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5986U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6239U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3099U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 0 with offsets 7341U, 5882U, 947U, 2011U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7341U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5882U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 947U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2011U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 3 with offsets 6857U, 1783U, 7960U, 5841U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6857U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1783U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7960U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5841U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6326U, 2642U, 6177U, 5433U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6326U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2642U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6177U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5433U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1544U, 426U, 1957U, 1813U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1544U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 426U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1957U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1813U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1552U, 1910U, 1227U, 1434U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1552U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1910U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1227U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1434U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 142U, 1754U, 1948U, 1437U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 142U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1754U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1948U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1437U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1497U, 2034U, 754U, 532U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1497U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 2034U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 754U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 532U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 133U, 1592U, 1558U, 545U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 133U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1592U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1558U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 545U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Golf::kPhaseASalts = {
    {
        {
            0xD8122EA004666A2DULL, 0xC57895F89ACFD744ULL, 0x154BDBBF664F7850ULL, 0xF6B0D4281E03E776ULL, 
            0x79303198C146CFA7ULL, 0xFF97DD92AE861AA8ULL, 0x65E7C70551FE2455ULL, 0xB9243E29E08ACACBULL, 
            0x66B836742B6AA6A5ULL, 0x6266DACB9CFDBAA7ULL, 0x4ED3BC48B8A3CFB5ULL, 0xD08EDCF812DABFDDULL, 
            0x0D6A9EB7EB612B23ULL, 0x79BEC32C7A1D9127ULL, 0x0409E7FE9B6C3317ULL, 0x8FF2DA4423763698ULL, 
            0xF69CE0F319E589E9ULL, 0xD452A4A47B455B6EULL, 0x486409BA9D4AFBAEULL, 0x66F7D5EDA16A796AULL, 
            0x9F07876C846C04BFULL, 0x6CB84EC6C749A243ULL, 0xEDFEAD35A80A432FULL, 0x404C4914019EFBAFULL, 
            0xA5403777BCB07494ULL, 0xC0FF5D52FB17DE92ULL, 0xA85675616C0E8B6FULL, 0x5C0FA7395153D37EULL, 
            0xE6B48B968DD48044ULL, 0x7F45541E79289FE6ULL, 0x994A023C4948A965ULL, 0xFE7ABCF08ABA1247ULL
        },
        {
            0xA7D772C406929FF6ULL, 0x3A516FAB482F17E2ULL, 0xEAD047B86FD8B8E2ULL, 0xFA8FFB9AE79EAE0FULL, 
            0x6A0E61C1EB298549ULL, 0x7C68A89C415C4EBBULL, 0xE9402DF747EB7E75ULL, 0xC05BBA53E7A60911ULL, 
            0xE717D2A81966452DULL, 0x70364461DA2C6F4DULL, 0x6B756EA0E2525C45ULL, 0x48FFCB596C38D1DAULL, 
            0x99060CFAB75E766EULL, 0xD531792A97C2549CULL, 0x6F437633C3DA86C3ULL, 0xAB008A96865F9A9BULL, 
            0xBF4C53C499B6F7E2ULL, 0xC4245F82DF09AAF3ULL, 0x901E34DD22F43756ULL, 0xEF813AFDB7D6CC6CULL, 
            0x8F3598479A4E0691ULL, 0x86AF81F8BBF36783ULL, 0x379B08D12C3BCD0DULL, 0x15350366D36BEB04ULL, 
            0x3784A26C99A09C07ULL, 0x6A4C9B11D37DC999ULL, 0x66B944BEAA747348ULL, 0xB26D80E40326F83BULL, 
            0xF96A14B9A46BD5B5ULL, 0x8D9645C5183DF6F8ULL, 0x1A804FFDE5CF1FF0ULL, 0x106998E9AD9ADB70ULL
        },
        {
            0xBE725C5C183B6042ULL, 0x7E63C75B515BB5A5ULL, 0x6C6C26C48857D8F6ULL, 0xE181BFF4B741E0E4ULL, 
            0x796ADE12503AE0E4ULL, 0x9255185EA9CEA77FULL, 0x3C7CF45BA55CAC3EULL, 0xA03BCAF6F103B341ULL, 
            0x33A5CCF671DCFEE8ULL, 0x346724F660D8D6D1ULL, 0xC2FC1D80913222CFULL, 0xC868425595C5FD70ULL, 
            0x6BA71025613A552CULL, 0x9C8E2BD8BF4F8AAAULL, 0xC0930B9997F2ECF5ULL, 0x46C3493D20BA50F5ULL, 
            0xF89EFE83AEFFE832ULL, 0x789C189AF6193E25ULL, 0x28BB5571F2665F0AULL, 0x8EB286D3015DB850ULL, 
            0x1AE680FA6E9DE577ULL, 0x459105342A3B4E66ULL, 0xF1DEF6D810F42B81ULL, 0xD6118EB4B30FB968ULL, 
            0x7BD5289DE88F8AB3ULL, 0x0D36348B0ED3B6FBULL, 0xDB3D8AA6987DC0C0ULL, 0xDFFF93AF44DE6514ULL, 
            0x43B54C3324EFC903ULL, 0xC8F2238DE6FEDCF8ULL, 0xEB90A2FF3D5A338AULL, 0x4110F18C520A96C9ULL
        },
        {
            0x9DEAE1448B172AD7ULL, 0xC8CA13F7A52F57C2ULL, 0xD535B1F89D448287ULL, 0xED3158FA927DC7F0ULL, 
            0x81BC0498B593DE6AULL, 0x7F932870A0C15E14ULL, 0xAD2DA7E048626DADULL, 0x2E9EA87A61676028ULL, 
            0xCF70CEF34C25F044ULL, 0xEBFB0874ADEB5A6CULL, 0xD1374680EBC0ABDEULL, 0xEC72322061916F65ULL, 
            0x91B635BDF03EF1C8ULL, 0x511F36A4FD7DD51BULL, 0x281D4604AD941240ULL, 0x7091C528B821E0D7ULL, 
            0x14342C65A66733F6ULL, 0x07FDAEDFC9111CE5ULL, 0x2B6620E0C1C5D701ULL, 0xDB944A671C851078ULL, 
            0x7559DEDDBC87908BULL, 0xD913CC66183D396FULL, 0x6162301D4EF53F59ULL, 0xB8ED3BF7992E59CCULL, 
            0xF2ABC167BFC82922ULL, 0x201D9B7F7C0274BAULL, 0x1AB0DC9318CFABBDULL, 0xB01923FEF4AC7A55ULL, 
            0xBB1DC5145BFF7F52ULL, 0xD34B78ED5AC80C32ULL, 0x6946539528F3BA18ULL, 0x23B7AC12D54C4F3DULL
        },
        {
            0xF4007FD731B62500ULL, 0xB4EF295CB68C80B9ULL, 0xD9117ED4BD7BC90AULL, 0xAD4073118AE4C0DCULL, 
            0x29A6787C5147B577ULL, 0xD0069CF93F77D36AULL, 0x9EB5FAD84C59C3A5ULL, 0xAE33A0206E34E300ULL, 
            0xEC3AF1A356F6B81CULL, 0x0ECE5A4109073326ULL, 0xA6DAA9C3AA3A4026ULL, 0xFE78CDCF39A4BCBAULL, 
            0x64D43BB093050073ULL, 0x62C7F9DBB2F33605ULL, 0x4A7FE0084A02E211ULL, 0x0DC94062F66A582DULL, 
            0x846E9373ED2D3DA3ULL, 0x8436752939B20F8AULL, 0x1F12CE40C59B5CCAULL, 0x73546F794D279C9FULL, 
            0x00A8B1DA796C04A9ULL, 0xC11BE890CA9F0358ULL, 0x73B2B0867D65C048ULL, 0xD66F647240605D3BULL, 
            0xE83FE5E76DE83AD6ULL, 0xDA99ED81D5C725ECULL, 0xB0BA4766C4236831ULL, 0x07FE6A73C4090981ULL, 
            0x51124083C4EF5CD7ULL, 0x656E8B849BC1D395ULL, 0xCA6A6C8369426B7EULL, 0x2E326D5A57C87108ULL
        },
        {
            0x63A90EBA256E0748ULL, 0xC6AFF626DBCA4B4FULL, 0x548751B3C9FF27BBULL, 0x9F77B8FAF2E4EFDAULL, 
            0xC360EE72CC5F23A4ULL, 0x97577E9AA8DE7A8BULL, 0xC789F37EF504222CULL, 0x09C3F5CF39B54356ULL, 
            0xF77EE473E68E5888ULL, 0xDB9D64B5AD88F213ULL, 0xF34446E0FCEA3EADULL, 0xC4175928B30533F2ULL, 
            0x597FCDE6C2BE5780ULL, 0x2D4BEF493B3D5A97ULL, 0x0EAAD5C889907719ULL, 0x03EDF847C5252F52ULL, 
            0x08818F2F685C25A0ULL, 0x119CD3057A8B9114ULL, 0x2EA97303906091D8ULL, 0x937D59205B741867ULL, 
            0xE349F1941A93CBE4ULL, 0x68BD2BA2979CEADEULL, 0x24FA0D5A6D516487ULL, 0xDA7D724DA8DC8880ULL, 
            0x6B8333AAC7C96354ULL, 0x7191DB6F8739C3E9ULL, 0xFB1DB906668BB727ULL, 0xFB145548917FCC72ULL, 
            0x3A3C7BE98DA65924ULL, 0x3283F31975C6687AULL, 0x634638513A6A2628ULL, 0x4EB7EA7668B16C0EULL
        }
    },
    {
        {
            0xE3D7228E693201C5ULL, 0x53B67822486A4BB1ULL, 0xB76AD0C2F54F6C66ULL, 0x99CFD3DB746A76CCULL, 
            0x20F13D306406B0BAULL, 0xD62C757AA7CAB22DULL, 0x64104403937DBFD8ULL, 0xDB6FAAB54DCB5588ULL, 
            0xBE1CF8CE09579E52ULL, 0xDAD21EE06847719BULL, 0x4A7A2A150793C6D2ULL, 0xA17F7AA4660DDB7BULL, 
            0xD12D35CC59A49D11ULL, 0xFD8ADFF32DFBDEEAULL, 0xE7B9CD67DC7186A4ULL, 0x08D3E88F6FB16AA5ULL, 
            0xFCFB2553CA694146ULL, 0xD4255726F41171D6ULL, 0x57C493CBD68466C5ULL, 0x5CFA72E6E8BC892CULL, 
            0xEAA5443CB891B91CULL, 0x3C38AB2819C42CD1ULL, 0x58CAC0622E1FCAF1ULL, 0x837EBB06601FA6CEULL, 
            0x35EE06720BBD27E6ULL, 0xD2698F1E254F1F3EULL, 0x3FF77928DE19A277ULL, 0x88AA09ED9CF2AC42ULL, 
            0x2920973755E78457ULL, 0x4FAB6054F37EF2F3ULL, 0x05F2DC0AE76BB320ULL, 0x9DEDF16B2713CE40ULL
        },
        {
            0x7DE836FB31F151B9ULL, 0x38E61EE0C8E1640BULL, 0x0B0B250C67C10526ULL, 0xA8355B229DA314ADULL, 
            0xCB5D58CA3C40D787ULL, 0xB7D293FF8EBC273AULL, 0xA95D4464BD7D553AULL, 0xFEBA137E1EEF1293ULL, 
            0x72CB81C41BBF1E07ULL, 0x46E98ED6A15E8B20ULL, 0xEC1F8CC3ABB73EC7ULL, 0xC7E606DEBF8CB580ULL, 
            0xE8A05C7FE39A279AULL, 0xB6C93CAAC83E2BD7ULL, 0x7A6006CBBF418B6EULL, 0xEB998106C9167D19ULL, 
            0x85FCA41225C6868EULL, 0x67F7F7E47E2BC118ULL, 0xCFE41F02BE2FFDFAULL, 0xE45890802FFB8272ULL, 
            0x6C1E045F95367660ULL, 0xDFA4830EE3D6A6B2ULL, 0xFD489D26BBE3391DULL, 0x62F482D5C4968021ULL, 
            0xF6259780DE3C5299ULL, 0x7D4330747CFD2ABFULL, 0xA7D60BFFDD0592D1ULL, 0x3F6C48EDE7752AC4ULL, 
            0xB21AB75A476D8BE5ULL, 0x75950568F575A666ULL, 0x64E8D931C60D0D32ULL, 0x943239F15B8BA2D2ULL
        },
        {
            0x1319BBE1971D7882ULL, 0xD7A52B47C3832A25ULL, 0xD3F76A6772E8FE19ULL, 0x5304717B420FEA5CULL, 
            0x128BC05E8F7E2844ULL, 0x97414B11B62F672EULL, 0x80E164226DA1BDC8ULL, 0x434E091984417994ULL, 
            0xFC0559528986E412ULL, 0x0EC0281B66886B15ULL, 0x649CEECC56A64AD1ULL, 0xDB84DA77A2E623F4ULL, 
            0xFB05F04A5AA7696FULL, 0xB61DC5D3654DD225ULL, 0xEE9081DCB9E5830BULL, 0xE81E9F64BB401BBEULL, 
            0xC234876B540962EEULL, 0x5AC5D38BCD7FF2C8ULL, 0xF9FF996F644A53CAULL, 0x55D0AE21913A6BBEULL, 
            0x577A3BFB6B3408A6ULL, 0xA88D514C60D07969ULL, 0xCC7357FE9910A901ULL, 0x6C4EE0A38729A9E5ULL, 
            0xED20735DA28E79ACULL, 0x5A2C5660D7712D87ULL, 0x32B7B8CD4F80D0B2ULL, 0x743EC1EC6C79AFE3ULL, 
            0xE40453F10D9EF920ULL, 0x11D2B4C2BA66372CULL, 0x439A7D14F8CCFFAEULL, 0x6BAD949B3A731BF5ULL
        },
        {
            0xA77ECB7091BE7884ULL, 0x83BE90C22627A8E6ULL, 0x871984D2E6ACABAEULL, 0xD593F94887A9207EULL, 
            0x424F649681373427ULL, 0x9263A9FF2E337355ULL, 0x1A8A5A877004D990ULL, 0x90B25B8643A116AAULL, 
            0x8D80370758C54DA5ULL, 0xFD5923C5004B6989ULL, 0xF93C03B3F1358DF2ULL, 0x5C16C1D827430214ULL, 
            0x5DDF352AF08B2B79ULL, 0x1FC0AF64AE3314E5ULL, 0x21A53228579D2C08ULL, 0xEEEF2B48F29E893CULL, 
            0xD99D606638D8CD3CULL, 0xE08C4D3C2516006FULL, 0x7331C3B5DF62F806ULL, 0x9A796FF42949B512ULL, 
            0x031742F4F2841933ULL, 0x9820B5413BE4BD97ULL, 0x89FBE130878C310DULL, 0x711AAAEE6033066CULL, 
            0x859EB66C3A43E137ULL, 0x118ADC26696B64FBULL, 0x04C1598A9EEA8DCEULL, 0x9B353BB67D3AF198ULL, 
            0xF4FDFEF0D27A7C7AULL, 0x0EB6EB406AABE134ULL, 0xEE9B6FB61B1D8651ULL, 0x0BA2BEC35B5A7DDFULL
        },
        {
            0x6808E31B8EF860C2ULL, 0xE5D0D2F1BED9B6F3ULL, 0x298294F2CA0F1712ULL, 0x7F2344B382EFB244ULL, 
            0x32148E5E19F35EABULL, 0xE450787307F99A11ULL, 0xB732A21FA5702878ULL, 0xCD62694436777E95ULL, 
            0xD16E34DE6B79F8CFULL, 0xD80FC8A337C42C6AULL, 0x8E7EA040918F2448ULL, 0xE153BEA8D9FB8EE1ULL, 
            0x96C04C1FFFCE0CDDULL, 0xEE72672D829DEB78ULL, 0x25B0556D6CE16B34ULL, 0x5DC6AE1B04F16434ULL, 
            0xFAB441CDABA6EC00ULL, 0xC1B35F6A1A4BF49FULL, 0xC83F83F4152A439AULL, 0x26AD6D1173622C14ULL, 
            0x9AE50EE78B72110BULL, 0x6692435911AE3D58ULL, 0x5D518A1012E47CEFULL, 0x33E6A9898DD97D01ULL, 
            0x2FEFAC897C8D5226ULL, 0x436CA688F1885353ULL, 0x482F0DE65667FC3CULL, 0x60F58DF9ED7F7E24ULL, 
            0xCFB10284F8EAC877ULL, 0xBA797E6564882331ULL, 0xF813453BB199A56BULL, 0xCF558CFDFBA0C20AULL
        },
        {
            0x73AD9EC09E2380D0ULL, 0x9671B264867E45BFULL, 0xE67DF976224768EEULL, 0x2B9D83EC4C6ADC72ULL, 
            0xA4E88D1F422668B6ULL, 0xF0E8772CB13B2738ULL, 0xE06AB326D95C5955ULL, 0x2E20655AEF6AE6EFULL, 
            0xEFE9B2B1BED8AC6FULL, 0x6821AB837414485FULL, 0xE103EE1BF5EF0890ULL, 0x2918605AA210FE0CULL, 
            0xB10D4D28FFD29574ULL, 0x1A2D1D153C894539ULL, 0xC2020F9842DB558FULL, 0xF2394817E06DA249ULL, 
            0x0BD918767EF4FE6BULL, 0xDE4C4B245C01126CULL, 0x369E1D240BE9BEACULL, 0x9D69A980032C2F61ULL, 
            0xE30934CB7E9C4F1DULL, 0x883DF27F094EA8D9ULL, 0x8BB811A748D64BA4ULL, 0xC19C336BF121990FULL, 
            0x1547AF4FB9B5A57AULL, 0x8871B83B9F7CDBFEULL, 0x6D002549C58C45EBULL, 0x43DD7AC73C96E715ULL, 
            0x055A4E351B354684ULL, 0x963AE1EB94A51B1CULL, 0xDFA5AF557BA949EDULL, 0xC4CD0A8856785321ULL
        }
    },
    {
        {
            0x325AFCA5277F725BULL, 0x8CF0FB8D52EA2859ULL, 0x3568B69A4999FA1CULL, 0x4D68863D70039524ULL, 
            0x25508DFCC12244E2ULL, 0xFE8774A86880FDD8ULL, 0xF60B931FB32467E2ULL, 0x2267C691FF91637EULL, 
            0x223578B89A0421A0ULL, 0xC0AB5A27123E24B0ULL, 0x9B69D5F24D99C739ULL, 0x477F40C10937D1C5ULL, 
            0x6BBBE3A561E9C9B6ULL, 0xF63F182499A442C9ULL, 0xA5F976F1FB6BCE97ULL, 0x8A9FD6FF9EA6E409ULL, 
            0x7F2729427AF3AB12ULL, 0x3D48F9B5A65F4CF2ULL, 0xF7BFBC97FB9BF32EULL, 0x63378CA51A9D3C35ULL, 
            0xEA1D8C900E5FA233ULL, 0x73A022E960A893D0ULL, 0x7666EBFEC4B5AE9FULL, 0x97D9E74A7BD81A0BULL, 
            0xAC3867F4B8DD56BFULL, 0xC1D85BA1A9F7E427ULL, 0xDB854520B4593253ULL, 0x5E5584B2F846D1B8ULL, 
            0x209F1645FB349BFEULL, 0x3EAD2B3606F03EBCULL, 0x391EB5EB11905F60ULL, 0xAE9A0C01C9AD4EBFULL
        },
        {
            0xAEA060D47FF75664ULL, 0xD5F6D01D605B0483ULL, 0x450CD0991BE7AE39ULL, 0x8D50094B15CF646CULL, 
            0x87FE8F84E12A6653ULL, 0x144E0E2C5A42A7C0ULL, 0x8F73833BFA12D81AULL, 0x31CB66BCDAF6F039ULL, 
            0xC8102A7C03501FB1ULL, 0x5DFF3CDAE4D98248ULL, 0x524443D6FA279974ULL, 0x492FD3D642342010ULL, 
            0xA21E897D7C04277AULL, 0x5C4F0F155BC3811FULL, 0x18B25853E6685C57ULL, 0x0F338AB5280EBBA6ULL, 
            0x36C6710E2B1670A2ULL, 0x6B25407DC16C957CULL, 0x9FA1F4CF66091158ULL, 0x180850463A418C22ULL, 
            0xF718FD3C4D949482ULL, 0xCD86DA39A99F19C9ULL, 0xD70BE7E7061AE2FBULL, 0xA514B98740638E7FULL, 
            0x8DA3951EADC47BDBULL, 0x01DD7EFF24F7FFB5ULL, 0x0BC0D30E7626D9C2ULL, 0x81424FD674A2B282ULL, 
            0x3DC40A93BCFE081DULL, 0x38EC88BF54CA6741ULL, 0x0D91F2BF94EB4B23ULL, 0x3723EE1600235E93ULL
        },
        {
            0xA4A4778A12B06593ULL, 0x2617B516FDD2AE68ULL, 0xC985F4E6B9BE6C5DULL, 0x5AFB8A7BB81811CBULL, 
            0x8159617DD5102E25ULL, 0x2120390FA9542E0DULL, 0x99E1ECCC756FB50CULL, 0xFF75F5412E38F63AULL, 
            0xF2F150B37ADDBF50ULL, 0x4744E25486025BF8ULL, 0x516F1D414E88D877ULL, 0x5EE5F293ECB7CAB9ULL, 
            0x3027BDB356E4056CULL, 0x93B62373A6017008ULL, 0xA58083F88CC6AFCFULL, 0xBDD5A5F669980451ULL, 
            0xD8D153E278EA099BULL, 0x2773AE3CF1734265ULL, 0x547CA8A0F40FE803ULL, 0xBEE194A7C38938A1ULL, 
            0x0BB3FE8B6F0094EDULL, 0x209DB86AB8457903ULL, 0x0644FBEB9461E5ABULL, 0x4C64D95EA234801BULL, 
            0x3E480267CF1ECD73ULL, 0x2102DE2A274DF180ULL, 0x4C7BC53BFF7D8D9CULL, 0xD479B1C1A8A9E81AULL, 
            0xFE307444B9899573ULL, 0xDD0CA172E154CD1AULL, 0xBBCF0CD2EBA1943FULL, 0xD55668E6C1CCDFE7ULL
        },
        {
            0xC9CDFCDC4F0CF67DULL, 0x17D5EAA91C58F977ULL, 0x1B84037B341FD72BULL, 0x44B3CA24048E3493ULL, 
            0x0094E335C2B32EE1ULL, 0xD90AE8B91F4187D5ULL, 0x65C4CADE406ABBC7ULL, 0x2259D20E7C7D30C4ULL, 
            0x6BD47D5ED0DB604DULL, 0xA10084F846FF4DAEULL, 0xAB24F75495F4CB60ULL, 0x5041DFF6546BEA62ULL, 
            0xBCE07324D4DEC0BFULL, 0x99461E1D3F58EB12ULL, 0x4CD109DF0E596414ULL, 0xEB44CA931D800841ULL, 
            0x4A43F67FFB2B4059ULL, 0xCE4C74E5A10BDBB5ULL, 0x950C804CDBFD65B9ULL, 0x0E9D8F5F3313F73CULL, 
            0x06597DB3D43D120DULL, 0x63F501AB92EF9327ULL, 0xE786196B56C9A84CULL, 0xA8CBBFD3CA306E76ULL, 
            0xD8C2CD2067C75C08ULL, 0xB9CD18A89599D179ULL, 0xEDB9BA21149285F0ULL, 0x37F7FA87B4C91FA0ULL, 
            0x7EB98659E1FB3DC5ULL, 0xADCDB572F973EE5AULL, 0x941D98C262DBE778ULL, 0x9D887B4B88CB77C9ULL
        },
        {
            0xCEECCF989EBE57ECULL, 0x78EEF45FBEF19634ULL, 0xE26CE5B7DF9671F2ULL, 0x860F4DCC87AAA760ULL, 
            0xF3C65E1110D833D8ULL, 0xE7C39853F15055CEULL, 0x5FE2EFF0822383A8ULL, 0x97F1B58FFACBB29BULL, 
            0x32F109B85E67EDAFULL, 0x11215D3CAFAF4E17ULL, 0xA300BB0DFEB38C28ULL, 0xE38BAF9591DFB7B3ULL, 
            0x57F58A7CDB7EDA57ULL, 0x81652BECB5C6358FULL, 0x226423C782F12DFAULL, 0x0864FF9808AF4386ULL, 
            0xD62F70B8CE06B114ULL, 0x563121F55EF08DE9ULL, 0x493574ED3E5729F9ULL, 0xC726122B8F3A479EULL, 
            0xCCBA888CAA34E585ULL, 0xC37726C4FAF7B819ULL, 0x0BC2540DC3242CA1ULL, 0x6AFCBB21987022D8ULL, 
            0x7CA804C2DFB43D01ULL, 0xBE895702A45D8799ULL, 0x336CBA46A894E3A5ULL, 0x1272688C75080CEFULL, 
            0xBB733F10A4AB7F06ULL, 0x7398121E9347C0BDULL, 0x18CCE645B5147CC5ULL, 0xE98402715DA2028EULL
        },
        {
            0xA061E17197AE5651ULL, 0xDDFA3467916A76D3ULL, 0x04BDE8B6F525E726ULL, 0x233652EE17143868ULL, 
            0x56AE9B453EAB5D42ULL, 0xF307565E0B40C397ULL, 0xC45ED6B0A7187326ULL, 0xA7087AA358349F40ULL, 
            0x3888BFC364C071A6ULL, 0x5C17E09CD193C651ULL, 0x07EE3AF8C8906752ULL, 0x7DE02927E6C9F597ULL, 
            0xAB070A9EFDC77079ULL, 0x91044EDE016A68ECULL, 0x5714CEEF019A72C2ULL, 0x7FA102CBD323EDADULL, 
            0x3B4F233258F8921BULL, 0x4FDAA825A624B9FCULL, 0x836C2FE0794E1A05ULL, 0xFC61D201FB7CCFCDULL, 
            0x91CF09B58FDF9103ULL, 0xA37C54B54FF2E980ULL, 0xFCA905A21072CE6FULL, 0x9CCAF68974D48FE3ULL, 
            0xB3F9B460D29C7161ULL, 0xA9554DF71255A683ULL, 0xB6F7EC0579D0A086ULL, 0x347D2F4302735575ULL, 
            0x4F1C3CAFFC415366ULL, 0x0D33B82A33EF3174ULL, 0x5EEB27AF8D74EFC2ULL, 0xEA1CF1483EBD74E1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseAConstants = {
    0xBD7AE8C8FE0CDD89ULL,
    0x243EB59FCAE2AAE9ULL,
    0xA397082C68D76366ULL,
    0xBD7AE8C8FE0CDD89ULL,
    0x243EB59FCAE2AAE9ULL,
    0xA397082C68D76366ULL,
    0x30D6DA9D0352A7B7ULL,
    0x1C1DB2703C57F3D7ULL,
    0x89,
    0x2D,
    0xA5,
    0x01,
    0x4F,
    0xFC,
    0x58,
    0x78
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseBSalts = {
    {
        {
            0x7D9CA10F8937A43DULL, 0xB1C840420029D9C1ULL, 0xEFD41BBF7EE89F86ULL, 0x9075063CEA95DDF3ULL, 
            0x98E6D064B93A350FULL, 0x186F8D04130EC1DFULL, 0xFA16BDEF151C7F06ULL, 0x182060AFC041E38AULL, 
            0xE573F6DED0D59916ULL, 0x29B0352340335C8DULL, 0x874D4F3F38DB9DABULL, 0xECE6D8019A5AAD83ULL, 
            0xADEE925F82B7EE3BULL, 0xACBA1FA5EB42D72BULL, 0x1E7BAC1536808665ULL, 0xBD1449872E69358EULL, 
            0x8C33951881FE5FF9ULL, 0x3F857DC7AC8D52B5ULL, 0xEBD2038539E9C85EULL, 0x47079041AD23F0C2ULL, 
            0x7A7D0A83C5AA21DAULL, 0x2B3DA03CEDB5B164ULL, 0x3817C87A1E5E6C4CULL, 0x1DB09F7CA4B2D0DBULL, 
            0x1FB53F5EA153A165ULL, 0xE8D9C3EFABE20BC6ULL, 0x54375C26496446C6ULL, 0x345C6F07ABEC4AA6ULL, 
            0x148956B5FF9028CCULL, 0xBC687115DAD2AF7BULL, 0x3EB5942703013377ULL, 0x0E318D9163021A07ULL
        },
        {
            0x6C4D7668F554B77CULL, 0x5831DFEE9BA9089BULL, 0xE92C5EF622CF3FCBULL, 0x867C0D932972C6A0ULL, 
            0x47842CC9FFF06F11ULL, 0x4822999CDA4E88FCULL, 0xDBEAE7D280832F78ULL, 0x9EE91912ECF4875DULL, 
            0x0F2BB75F1B41B1B2ULL, 0xE160CC83EC57C69BULL, 0xBC627FF718A8A7C0ULL, 0x71B05FB87EC57C18ULL, 
            0xCAA912755F7C8C91ULL, 0xCDC27A326B0D200EULL, 0xE767C6E51E1E2AAAULL, 0xC61502E3FD16EA28ULL, 
            0x7DF81306EF6A538FULL, 0x7AC9D2837C46BB81ULL, 0xD02E05B8BC014700ULL, 0x6971E065F0A6BCE3ULL, 
            0x9740645F9C39B4EAULL, 0xFBE1FEC02071F4D4ULL, 0x9CB9819DC8BFDDA4ULL, 0x0C8DF39F144E7D04ULL, 
            0x3E9B456D1A37C4CFULL, 0x74AA2B169BBED237ULL, 0x43BA8A2048C4AC9AULL, 0x7785EFB2470C5CC3ULL, 
            0x78D0ABCB30D306A9ULL, 0x72B0429A02B273F7ULL, 0x6D75FF6EF2263B1CULL, 0xD1F3F27686CE6749ULL
        },
        {
            0x72075BF710A4ED25ULL, 0x97FA24A66D47A367ULL, 0x0A6364D336797D8CULL, 0x2C7A98E2A84093F5ULL, 
            0x43B64A673965BD83ULL, 0x0909896946ED0847ULL, 0xE42FBA5FF484914CULL, 0xC1CC68E9FC53C217ULL, 
            0x8A56F3FDFD80D400ULL, 0xA35D512DB487711EULL, 0x867AE9615545CD16ULL, 0x7B83EFA6333158B9ULL, 
            0x14215FA6A949F691ULL, 0xA798516BEBFC46FCULL, 0xDD27142EB6AB9262ULL, 0x03EF1ABB89518786ULL, 
            0x360E0A47AE31BE9BULL, 0x23D970205AE20966ULL, 0xE88A3CF02E0D7299ULL, 0x436127BD63AF9C84ULL, 
            0x81D61B9B86527F36ULL, 0xE2343F7126F94775ULL, 0xF10AE40086D0AB39ULL, 0x4C11E42D034D26BBULL, 
            0xC0B99D2545EA0262ULL, 0x7CD2D59732D0D5D0ULL, 0xF54E7D5863CC36C9ULL, 0x741F031856582EB4ULL, 
            0xC5BB797156E40A12ULL, 0xD3D54C2FE6408B42ULL, 0xC2C4C270EE003097ULL, 0xD10C012FF3554914ULL
        },
        {
            0x98BE892D757CFEE2ULL, 0x5C59B858A0D8DD3BULL, 0xB47A810C9ECA9984ULL, 0x10D19459206E5BC7ULL, 
            0x472B405C7103604DULL, 0x0D13AA3D2E15C69DULL, 0xFD2455DCC50A78A6ULL, 0x1AFD2A3378CC909FULL, 
            0x824B983CF5F7C266ULL, 0x5154357B8FD228BEULL, 0x66EEAC094395B6CCULL, 0x86C9974945AFBB3BULL, 
            0x33937E8A508F4B62ULL, 0x9F2861F123DBE29DULL, 0x4EB40C430414397AULL, 0x4CA306B9DA05D0EFULL, 
            0xDD224EF58E000F8BULL, 0x49D21840667510A1ULL, 0x7ADE0006E0A7295BULL, 0x869C069337BCB973ULL, 
            0x3FBD153E1A755437ULL, 0xA1AC8880CE9F93F1ULL, 0xFA90D0565652FD9AULL, 0xA1512C5072D08BFFULL, 
            0x15D57A2A7E2BAB8DULL, 0x44455846F7BF368DULL, 0x445522FF48E0969BULL, 0x9ABB652B291D81DFULL, 
            0xEB32442A836A1FBFULL, 0xA43579C54D1F831DULL, 0x47E5A69C982C7D37ULL, 0x6804FAEB05EDF375ULL
        },
        {
            0x7F90F3D0CAD77EC9ULL, 0x9DAD4271C73C35DBULL, 0xE5484A96935CD923ULL, 0xF6441D37E75F2D8EULL, 
            0x29FFCE4B63B733AAULL, 0x58DC5151C2E9AB2AULL, 0x3B6959F9B1CAD481ULL, 0x01301E21146BA146ULL, 
            0x12236145CC147785ULL, 0x559DBA4D2039ED4EULL, 0x1D4A3C7EA2A074ECULL, 0xD8BBFC453238DA04ULL, 
            0x6B79505C334E9788ULL, 0x574E9A52883ADAE1ULL, 0x66F8BF3B7D1FBFD7ULL, 0x62929CA30539C866ULL, 
            0x0F0108515B8CB65CULL, 0x9DA277EFE3BB3D01ULL, 0x8253DB5DC461E936ULL, 0x2C753EB80D26DBE9ULL, 
            0x143DF3ECEAC00BCAULL, 0x384A6386CEA7E056ULL, 0x57B2F90DA1A3C265ULL, 0x02F39EB1AE8D489FULL, 
            0x564186B93DFE3203ULL, 0x19D5A82FC58ABEF0ULL, 0x07F74AAD400CC34CULL, 0xD58959D5C43BEAF2ULL, 
            0x25D2F27339447C7EULL, 0xC3138B8FF03152F6ULL, 0xF1148E686E074F3BULL, 0xF2937EFA79E24C77ULL
        },
        {
            0x98248B8C7D563D89ULL, 0x79C0792960D19F18ULL, 0xFF48CD58A9D15CA0ULL, 0xE874FCF213EA6292ULL, 
            0x41E7E97E64F3A530ULL, 0x970665C6EBD06291ULL, 0xB8CB57D00C5731FAULL, 0x53B0C3918AB724C8ULL, 
            0xF53EDEA1124A97CFULL, 0xAC5D0DA03CF30337ULL, 0xF585167203D7571CULL, 0xCB52F1CFB3915362ULL, 
            0x6218790D4161628CULL, 0x30D7179DF1D9D24BULL, 0xFFBC6DB08FE40651ULL, 0x3BF845F914AAEBB3ULL, 
            0x478F67D009A0D0EEULL, 0x45237856B0294184ULL, 0xDCBE31559DE02155ULL, 0x72464CA4431FB3C9ULL, 
            0xD97559CC49B12315ULL, 0xB24F1C324AFC0819ULL, 0xF7D40E0075F09818ULL, 0xA58FD677350FAF27ULL, 
            0x418D96C166A90E35ULL, 0x6A0FB01C3E8F30F9ULL, 0x2AFEFE964236037DULL, 0x174838325620A54BULL, 
            0x038402FCC3534B70ULL, 0xE5205565A7F956ECULL, 0xBDD65DD83C9218C8ULL, 0x1F2FC044D38C27DEULL
        }
    },
    {
        {
            0xF1CD6E4523D55660ULL, 0x47FEFD5949022015ULL, 0x65F54880CEFC2A60ULL, 0x44938F8604DCED3FULL, 
            0xA4950EA9F870979CULL, 0x3F53AD4C564820D9ULL, 0x0E373E0AAD61A5A6ULL, 0x3E5CDC203F6557D1ULL, 
            0x2841FE95829041A1ULL, 0x56C818BA56090905ULL, 0x2C22FD1111045CB4ULL, 0x2F1FCBC277FCEEB3ULL, 
            0x0C73A111193E519DULL, 0xB7E5FC5B2A0FFE49ULL, 0xD8F2C654426A1B3CULL, 0x0BAFAC82C7ABE1F7ULL, 
            0x48A05689B914957FULL, 0x588164AA98811EEEULL, 0x96C96B579CA203EDULL, 0x3966E1FC871A943CULL, 
            0x29386A6B48BC08A1ULL, 0x1248CBE2C63BBBACULL, 0x3EFFFEE6CB1358D8ULL, 0xFA353E63651E0FABULL, 
            0xD926721E413B9BF2ULL, 0x7B9DDB8C250CE959ULL, 0xCDCD20E17D7490EBULL, 0xBF207B856AF5C34EULL, 
            0x93462970CF7B1EE7ULL, 0xD9BBAD780DCCAFE5ULL, 0xCA2BB29518BBF3F7ULL, 0x59EDAD537126CE8DULL
        },
        {
            0xC8BE840D779DA20EULL, 0x5AB9944904B2DEFFULL, 0xFA13A891E02E755BULL, 0xA692EEC7C888504EULL, 
            0x59CA4429195E85E3ULL, 0xA106D4D649C267B7ULL, 0x384963D7209B37C4ULL, 0xE85F55DE596FED38ULL, 
            0x464DC9281E198285ULL, 0x8E663EFC17CC6019ULL, 0x0A3DC5AE9017F0DAULL, 0xD39A93A1CBBC297CULL, 
            0x6D8C758D9072F757ULL, 0x0CC14D5E497BECE6ULL, 0x3432AEDE5EF7B514ULL, 0xC206856EDADD14C2ULL, 
            0x85D0C8BC8F977CD2ULL, 0xA0B69247E89CD8ABULL, 0x3A377A3F750E729EULL, 0x1BD64010027922B8ULL, 
            0x0F68A8737F977E70ULL, 0x24B3F22921593EA7ULL, 0x11DBE4587C4D923EULL, 0x3A0F5DB31969E15EULL, 
            0xBA448A45CCB06E27ULL, 0x4B1441B6CDB14E37ULL, 0x45B7B648F9D43467ULL, 0x1BDD7118AFA8DF4CULL, 
            0xEF6DD27B1FBEEA90ULL, 0x01DE1AE88BC0D9B8ULL, 0x04CC885DFB4F14C4ULL, 0x700917DE54BF05C3ULL
        },
        {
            0x84C5A0D9C2AC890AULL, 0x465F701D7288B0A3ULL, 0x69E04E0D6BD2A772ULL, 0xCE4E2B3F4833DF3EULL, 
            0xC012C2AAF1DA1FEFULL, 0x9166F7895D77CCBDULL, 0x9B8BD6EB62A04AD9ULL, 0x41E91E359CBD98A3ULL, 
            0x10BC0BF674934923ULL, 0x52E83DDA82491FD8ULL, 0xBE32A55049A1E09BULL, 0xDE9CA3A01789C851ULL, 
            0x827998ACD4BD532BULL, 0xB03AFBCEC1DA3E0DULL, 0xFBE1BF02CA3D220CULL, 0xEDD4A3AE5EBEECBDULL, 
            0x01F32688108AE958ULL, 0x43199F572B5E72BBULL, 0x922C3AC850F53643ULL, 0x89560BA1B771F9DCULL, 
            0xBE8EF06754E8E50CULL, 0xC03420D02CB036E4ULL, 0x84AF2CE5CD14E389ULL, 0x7CAB134EDBD52387ULL, 
            0x65F139CB0F8E3B00ULL, 0x69AA66EE93C4D68CULL, 0xE2E68D3867542BF6ULL, 0x8AFB1EAA13A04C97ULL, 
            0xFA6C070F874B1689ULL, 0x7E669925492658A6ULL, 0xBA6B14BCB7C9B3D8ULL, 0x3898A547A49EC565ULL
        },
        {
            0x0BD04DA86E933AF5ULL, 0xC4989F31730B43F4ULL, 0x2350525B2DC6EE24ULL, 0x258D9CACE26BEA16ULL, 
            0x33BFFB9139B58A6AULL, 0x6D671D800D0DAEE7ULL, 0x30C16015641B3F1AULL, 0x5537077F0E6BFD83ULL, 
            0x277596C3ACB56C2EULL, 0xC68A95CDEA84DAF0ULL, 0x5D468DC87E5C442CULL, 0x4B76AC8582A79E57ULL, 
            0xAA85A925A637D041ULL, 0xC43E02DA6D33188FULL, 0x748E01378938A985ULL, 0x061A0B762B76A824ULL, 
            0xF270C9E2959CD5EDULL, 0xC1C35FDC4D94CC18ULL, 0x2EF6CCAA1D2B4382ULL, 0x4112C9742826A94CULL, 
            0xBFC579AB4E4CC927ULL, 0x126A937A3B07F51AULL, 0xFA5209A1C9EF8916ULL, 0x381DF17F9541A57FULL, 
            0xD07F561D0FCC6FEAULL, 0x2F0F41A589027A1CULL, 0x7434DD62714AC663ULL, 0xF825F0E5F9B49248ULL, 
            0xA2187D646705E725ULL, 0x86E701242D5AAD32ULL, 0x31F56F29564120B4ULL, 0x672A71610A9CF8DBULL
        },
        {
            0xB7553E08F7BDDEBDULL, 0xB3C66FFE68655244ULL, 0x87C3A39A4600612AULL, 0x1CE017FD571CEB8DULL, 
            0x25A7EBE54FEA58E5ULL, 0x775C0EBC0C878C14ULL, 0xA1450CA420F63B92ULL, 0x43E7D7758D908E23ULL, 
            0xADCCAC440EF8CBD2ULL, 0x731A3975CEB2E081ULL, 0xE816614BD81AD824ULL, 0x3CF1921576E43231ULL, 
            0xB07E058C94A2491BULL, 0x1A9A59EE41876A07ULL, 0xFA40B544D4DC8336ULL, 0x4C3AA76D5A13310AULL, 
            0x0CA826C9AF91320FULL, 0xD608CD1D97EA4716ULL, 0x5809864BB407F238ULL, 0xB3682DDBE8507271ULL, 
            0x20133B82D9102E66ULL, 0x0C58EEEEDC18EA54ULL, 0xDAEBA0365F66025EULL, 0x31ECC7BCC731C874ULL, 
            0x60760022F6B98BA8ULL, 0x3253FDEB3CD76B82ULL, 0x61077441A6FF3DF5ULL, 0xDC873857876DFC95ULL, 
            0xC3D68090FC26353FULL, 0x4B8ADA4F75F3EF62ULL, 0x0512BED09D257E60ULL, 0x11B51A08EC0CEC02ULL
        },
        {
            0xC4BC705C3DA0098CULL, 0x4F06106CFDE5378CULL, 0xCBC3220CBC378FB9ULL, 0x24699EAB7568D54EULL, 
            0x9320C98907C79C7AULL, 0x272E5544950CC1D0ULL, 0x030C5C46BAB477C5ULL, 0xBBC68F08B95F39D3ULL, 
            0x2CAC241728E4D3BEULL, 0x4EC93E856D5361DEULL, 0xE95817C72340B4D5ULL, 0x018A05B245AEBE04ULL, 
            0xF35FDB34A1DA3F67ULL, 0x52A1D080143F2FBAULL, 0x1EA6CED27894FDD7ULL, 0x2B9036035F61ED07ULL, 
            0x69DC1A577EB9802BULL, 0xC9163EB043C72826ULL, 0xC74988B325C7C254ULL, 0xFE284C94A6D2227EULL, 
            0x9BAA0930D77CB5E4ULL, 0x53D1596FD2337451ULL, 0xE38AE14485A1E67BULL, 0x934A201C2DEB9136ULL, 
            0x1548AB6FD8E07D64ULL, 0x64020C6251EC3C11ULL, 0xA579716D016ABB37ULL, 0x2609E0C5941292B4ULL, 
            0x6F8AD0BE518AE681ULL, 0x9D388AC2E2FD90FAULL, 0x95936CF7A7E5E6B7ULL, 0x1891E3E1823F14B0ULL
        }
    },
    {
        {
            0xEE3F4B7C187715E9ULL, 0x84A03D91E8FDC3F1ULL, 0x476A63302ECB8606ULL, 0x429B99E93632802CULL, 
            0xCB838BF17C2A8CDEULL, 0xAD468006D6003369ULL, 0x202E971688972EA3ULL, 0xE29A84EC25631EABULL, 
            0x9183DC307718D83FULL, 0xB4F9C56363F4E9BAULL, 0x7B7DF09526BC9252ULL, 0x2DF1337C59B18A22ULL, 
            0xA9B539F003AE0975ULL, 0x3BF695BE7E59AB24ULL, 0x27274E4FFEB5A7D3ULL, 0x7F845E01FC419FAEULL, 
            0x97B321539866F38FULL, 0x5228437E6D8D67C6ULL, 0x0265F04D200FDA58ULL, 0x0781F34E94ACBF4FULL, 
            0x46FA8498830DDF30ULL, 0xB2446E4FDFF550CCULL, 0x971FAB3E77671D4DULL, 0x1FE0BA04A04C26B2ULL, 
            0x8D6E28C8091996ABULL, 0xE275ED9584B29BBCULL, 0xF256F08EB68690E0ULL, 0x331F4EC86F72B7E3ULL, 
            0x2A898623EB66EBA2ULL, 0x505F89662F0BFB27ULL, 0xB808A4D3E002EB94ULL, 0x8FF157D07D57583EULL
        },
        {
            0x69503974AC22A08DULL, 0x929660B3696C08F4ULL, 0x2668A3BA314F0596ULL, 0x65492F6BA95D39A1ULL, 
            0x6A73E0099E6FE803ULL, 0x22D3CAFACD23745FULL, 0x8EAC0FA303FFE9ADULL, 0x20F1E7E70F5399CFULL, 
            0xB2ADC8AE2B4E2295ULL, 0x21C383466C561F61ULL, 0x6B2140B4A26993F9ULL, 0xDBA04E2FB41A2F9BULL, 
            0x7797BAAD6DFFCBDFULL, 0xC69E85DA794D768FULL, 0xB7F5B3FD5C78D84AULL, 0x15E518A27ED44AEAULL, 
            0xBB10E74D52DDC486ULL, 0x53A5F601E0AAE0DAULL, 0x8D12A07B5B5A1694ULL, 0xC67EA29DCEFCCA7BULL, 
            0x5EBC6B58E0D48906ULL, 0x537CD272437EFE5EULL, 0x569689A94C9E91E9ULL, 0x8663A10DEFB2DA3AULL, 
            0x1AD2E727C895923AULL, 0x75F9CF976BC41C1CULL, 0x191ADC61E564B99EULL, 0x906B298B7CA89030ULL, 
            0x27921547FDEE57C0ULL, 0x7CF3B29F21AC993FULL, 0xF8DD1EC4D556A369ULL, 0x0FBCB2CDB8F89C86ULL
        },
        {
            0x914FA094DA11D981ULL, 0xB358417138C53D16ULL, 0x700A5DA04A2CD1E1ULL, 0x9610365DACCC01C4ULL, 
            0x363774719A018E7EULL, 0x89C59AFCC9CAA5E6ULL, 0x4164557E2D045619ULL, 0x2ED7EA4822F0404FULL, 
            0x48F02CEEE06A17C7ULL, 0xE65992B5E54B522EULL, 0xEC137F4883063CBCULL, 0x3FE942D5AFB808BFULL, 
            0xCBBCECC4F31D4760ULL, 0xF070DE7BA4A45865ULL, 0x56A372C857D57B54ULL, 0xF7CB62A5EF209EFAULL, 
            0x121DB856A79531A3ULL, 0x8262D3B31660BA27ULL, 0x71848F7E8A3240E0ULL, 0xE45BC32DD08D925CULL, 
            0x91F41C2F1E55AA8AULL, 0x26BE4DCD389209F5ULL, 0x1F43B0F3CCE60EE7ULL, 0xD21FA3BFDAF04694ULL, 
            0x4B2B90086670C85FULL, 0x362B1FD15A4FF877ULL, 0x637FDABC064FA574ULL, 0x1E92B4B23BD0BC4DULL, 
            0x01DD46D379E2F10BULL, 0x3AA11594E784F516ULL, 0x321AC7C8E3BC910BULL, 0xA11A69E752FDA0E3ULL
        },
        {
            0xEAACA92181032E53ULL, 0xD43D8F71429BE4EAULL, 0x1A33913BE3C03AD0ULL, 0xBD0F6E083B49F759ULL, 
            0xA1A46DA35295500AULL, 0xDA64CF47309E0222ULL, 0x79ED4A81C530822FULL, 0xB403747B8B1FBBC7ULL, 
            0x7F62E471A4AD54E7ULL, 0x814688ADA94859C3ULL, 0xCD6B66AE2B5FC992ULL, 0xA913F81A9690B20AULL, 
            0x251CC0F6245FD34FULL, 0x43126407046255BFULL, 0xACB042ADDF4AD289ULL, 0xEDF13702DD8795F7ULL, 
            0x46DA65180A8E7FF6ULL, 0xD2BA3AF2097CEAD0ULL, 0xD93D085AA1F9B4B5ULL, 0xE8A770403525D93AULL, 
            0x732BA36F1C06197EULL, 0xF99318763EAB8BE3ULL, 0x0FF92C9B1F65BCA1ULL, 0x7D5C7169FD813BB5ULL, 
            0xDC06F03919EA48C9ULL, 0xE2BA46BBBD9B1FB1ULL, 0xCA3E724EA83E583FULL, 0x759BDAC9193DA2A7ULL, 
            0x5926B68055D36B1BULL, 0x0407747C400BC26CULL, 0x8E232A9263BBD4B2ULL, 0xC5F50951B2649CC3ULL
        },
        {
            0x4532FE6D74634A63ULL, 0x4A67AB813F0AEF2FULL, 0x8756E0CAD3FA1E2FULL, 0xC1B9E2894AE8EE2AULL, 
            0x6B674F8F4E42EE3BULL, 0x4883D2D563E22783ULL, 0x7258C25C7FD021A1ULL, 0x1D9AA902B01DDBB8ULL, 
            0x064FA149AFE77746ULL, 0xA575F1CF5B7B8D25ULL, 0xE12B8FBAD96979B2ULL, 0x72A5BDD93579B0DCULL, 
            0x3AB7107B6717FCF0ULL, 0xF3329E49ECF6AB1EULL, 0x8E412E86EE68E2A6ULL, 0x3B9462C49F29DA65ULL, 
            0x48DB4D53CC8A9693ULL, 0x3A08F8D6B02D1B93ULL, 0x45B1FE60B0FE570FULL, 0x29395BEE45992EE5ULL, 
            0xFC1A24907C1E5DDAULL, 0x1DE6B1C137C23CB3ULL, 0xFD5B28DE1AC18A6BULL, 0x225A958BBFA4466EULL, 
            0x27542FD18AA50A1CULL, 0x02C1FCBEE25AB4D8ULL, 0x9065B9D543EDCC13ULL, 0xCF979EB3CF40EA79ULL, 
            0xB7EAFB1DEF6A0DD9ULL, 0xC0FB63079E2DDE25ULL, 0xE10FE328131A255FULL, 0x1401A5D475B2FE65ULL
        },
        {
            0xA528976FE5E137E6ULL, 0x568429FEE23C890BULL, 0x70F6137FB68D23B1ULL, 0x30E5990164B03977ULL, 
            0x586FA23D123BC33CULL, 0x8EFD71C565A6992AULL, 0x7BDD3C39B3F95F89ULL, 0xE77FCE1F146925B0ULL, 
            0x6F6895FCDD219768ULL, 0x6CB2B8F6354DA8FAULL, 0x0F1A5235B13CC20EULL, 0x23360B4D5CF0F88FULL, 
            0xB97E2218D38A7313ULL, 0xA27751899DD099BDULL, 0x781E5FD10DC751A3ULL, 0x7E47D3B5A41CE170ULL, 
            0x28AC4A8937B4968CULL, 0xA4094E93E1E89962ULL, 0xC4861A0B34881804ULL, 0x667349DD68B110E5ULL, 
            0xD246AD4F27F1C867ULL, 0xABA025D94F4D964EULL, 0x4A6C919F48281A99ULL, 0x75F6C04E224AC16FULL, 
            0xF25004C5F1570C78ULL, 0x652C6F37113F67DAULL, 0x88185D0A2FF007CEULL, 0x3F275735C3520C06ULL, 
            0xBCFAA45C961E56ECULL, 0xF428DA2ABE68B97DULL, 0x0F887339A921A4B6ULL, 0x415FB2398F0B4833ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseBConstants = {
    0x9DF37FEBD2EB346EULL,
    0xDD1BDBB899E82F60ULL,
    0x0C068E4599D63159ULL,
    0x9DF37FEBD2EB346EULL,
    0xDD1BDBB899E82F60ULL,
    0x0C068E4599D63159ULL,
    0x625DD04D7DA759ECULL,
    0xB33838565E0F0B4AULL,
    0x9F,
    0x93,
    0x62,
    0x3E,
    0xC2,
    0xEB,
    0xA0,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseCSalts = {
    {
        {
            0x63A73AA937E4AA61ULL, 0xD762EF930C0EDF1CULL, 0x02D1FA6B2AA2D4CAULL, 0x6B9E345C002E57F0ULL, 
            0x568A816A0B3EABCFULL, 0x309B853AB44B6AF5ULL, 0xAC00784017066F9DULL, 0x4A91F6F5F26648FDULL, 
            0x05A0786113B36D2BULL, 0xFBC87D0A429E8D11ULL, 0x67F14D2EC22AC7E2ULL, 0x2AB115F5FD318F8AULL, 
            0x00FA9F07EC54DE3EULL, 0x7221FFCC450BC8F8ULL, 0x4C0222FA20574B1BULL, 0x81D38AEBEBC39E3DULL, 
            0x238A70B6231AEB14ULL, 0x2ABDC054DEA7D2C3ULL, 0x092FB229AACFADFCULL, 0x66C950439CBF202EULL, 
            0x1FB3A19FDA9C1968ULL, 0x359929CC1F98EBC7ULL, 0x122A0F3B2623C70AULL, 0x8A6A02217247E213ULL, 
            0xBE5EE6D00635A0ADULL, 0x2978E7278C14D8F4ULL, 0x7DD696C7B849D088ULL, 0x01C79E9576F8DD66ULL, 
            0x4522B560C33CD7F1ULL, 0x26EFDAE979B6AE1CULL, 0x7613C0C4A962DFF5ULL, 0x6CB862DE919E4A25ULL
        },
        {
            0x9FE8E26C44EDC69AULL, 0xA314C293BDE436ACULL, 0x593EB9F785918CB6ULL, 0x5F2559A2EA286735ULL, 
            0x4A7F3B6C13764B60ULL, 0x9B882B5A64769310ULL, 0xF912D2D43640E63EULL, 0xE34DEF6C16A9A1DAULL, 
            0x2F61463E5FED015BULL, 0x98BA088CB18FCD27ULL, 0x594CC86FB1AD0AE0ULL, 0x0DC1FF54B57A32B5ULL, 
            0x92EF3AA0C573DB16ULL, 0x6C2CEC097055B53AULL, 0xC806842E1D70AC39ULL, 0xDDC2A12A313FBCA5ULL, 
            0x38628D3DBA94BB55ULL, 0xB118B7FA9EE71E60ULL, 0xE5B175D640659D94ULL, 0x3F81FFDF591168BEULL, 
            0x37B5C5F4AAD90765ULL, 0x30BA47A5E1C04196ULL, 0xD31C11EFF4F96EA1ULL, 0xA47D3CE096B500C4ULL, 
            0x91F26C6E9F00FCA1ULL, 0x84DF18B94631192EULL, 0x401CCA967035F215ULL, 0x9B622E309F443279ULL, 
            0xE93180E6E1C49833ULL, 0x51C35D097DC955D0ULL, 0xE6D744879B3D6F4BULL, 0xC4327104C96B1779ULL
        },
        {
            0x551CDB31548DA251ULL, 0x3FF994A7A2388C14ULL, 0xF4C396F22BA6D9ACULL, 0x94EB444DC60BCB4BULL, 
            0x9DCB3464E86FF32BULL, 0x993679765C71D733ULL, 0x81E589D2F9B35199ULL, 0x8EA0B0D59C1EC1D8ULL, 
            0x1ABE42B7E31B3D06ULL, 0x03604961F9EA2C1FULL, 0x2436A18E91728E75ULL, 0x324F1FF7ABA501D7ULL, 
            0xC2F8BDC5692B533BULL, 0x6921C35405B39AA1ULL, 0xC154E4C65756881FULL, 0xD4DE9D8AA12A1A1FULL, 
            0xCBD76CFA938FDAC7ULL, 0xA9A85553DF0DF814ULL, 0xACA372FDD04CDE76ULL, 0x839A011E213814C2ULL, 
            0xC230F5A0752960C2ULL, 0x3D822388D6908D3FULL, 0xE0BF7EE65E906269ULL, 0x2ED8F15C8A18F7A3ULL, 
            0x38B109EFE5CA35A1ULL, 0xB85A20EE856D0A25ULL, 0x5AC6A95B7DB7587FULL, 0x20635D54266C8ABBULL, 
            0x5561F8BD3F4384CDULL, 0x7A9E1727749DB0D2ULL, 0xE0F6FBF270A5F36EULL, 0xE13205B8715CCB58ULL
        },
        {
            0x9100D40BF2C5E474ULL, 0x007173BCDAF2F178ULL, 0x6F5E29230D74D106ULL, 0xBC2D1902396E80BBULL, 
            0x948EFD526A31F009ULL, 0xB785A6CAAE400C21ULL, 0xB1E18E8F6A42D5C9ULL, 0x7AAD9342742B6C41ULL, 
            0x06E0FDD7218084FBULL, 0x38CF890622B84092ULL, 0x12B24EAA05833690ULL, 0xA105002CB44B83CCULL, 
            0x473373120EC71D48ULL, 0x21CB5F400752231DULL, 0x85234C81993AD565ULL, 0xBC31648DF77EE0DFULL, 
            0x029D6BB70A8E3ED2ULL, 0x3F783EFDA2D26E03ULL, 0x89AB7C0715B24D0EULL, 0x21419B79B3AE2009ULL, 
            0x24F0B592642A0E32ULL, 0x6CF6414CCEBCE874ULL, 0x4555C56FD9D7E480ULL, 0x96D39C13984C1D28ULL, 
            0x997AD9D0C058813BULL, 0x2D269562F0BDBCD4ULL, 0x95D4CADF9E91B46BULL, 0x03CAD544B8DF5913ULL, 
            0xAEB2F035D06F2156ULL, 0x24424713424BDA6CULL, 0x2994F2474FEE977EULL, 0xC39D0DB053EE4BECULL
        },
        {
            0x6CCFFB96D09947B2ULL, 0x857697179370DA31ULL, 0x7FD42C26D5572BABULL, 0xF90F565F1C759C79ULL, 
            0xB4D5F76635DC9AF8ULL, 0x5C63C44FFF138D34ULL, 0xFF969F84179F452DULL, 0x646FEE1A8676BED3ULL, 
            0xF90E3038D8D3E363ULL, 0x661034441EA049C0ULL, 0xC564EB30FEB1346EULL, 0x04B094B83EBA3E29ULL, 
            0x75AD59CE59708DF7ULL, 0x673D81E94535F839ULL, 0x2AD645D96EE9EFDEULL, 0xC83FCF42CCE9B9E0ULL, 
            0xDF6D1B89A41BEAD1ULL, 0x0B8FA597FCE5C3D9ULL, 0xF2B012340074FCB6ULL, 0x04987702DBA366E6ULL, 
            0xE9521886A01A21F1ULL, 0x9E8620D7FE91063DULL, 0x57B29ABA1206D719ULL, 0x44589406A2131D92ULL, 
            0x0EF7AB4B905A5B08ULL, 0x35C33B5E9E2A2805ULL, 0x4C08DEC36D3D195BULL, 0x6910CEE9789772EBULL, 
            0xABB678E6D8028094ULL, 0xE1FC3F02CE9B5605ULL, 0x95003C1D1AE4F314ULL, 0x165DBE4EF1345490ULL
        },
        {
            0x5BA685ECC141E096ULL, 0x76D93D4AF85C1BE7ULL, 0x2CA020B7E01D78E1ULL, 0x8A7FB11B6899E2B5ULL, 
            0xD3B6E3D4127E52BAULL, 0x65BE79DE47A73253ULL, 0x7B6C5C5EB4F048A4ULL, 0x693C83B82CA65B17ULL, 
            0x13F427549684289AULL, 0xAABD304ECDE862BEULL, 0x837528DC60E9355AULL, 0x2B9B6AD62A308C31ULL, 
            0x7AF4A1EE559E67EEULL, 0x458FD037FA4BCC6CULL, 0x5A7A326B483B6985ULL, 0x17CBC65F42E9F25BULL, 
            0x1C1C8CA7491C8054ULL, 0xEBE5780DDDC056FFULL, 0xCF69FEF5DB076300ULL, 0xF62639889333BC31ULL, 
            0x6A4B03BB1AB8A538ULL, 0xB725EA9E8139818EULL, 0x064CEABA0F0D7CF7ULL, 0xA6F90F62DECE7C54ULL, 
            0x6541098F6849371FULL, 0x9B42FD7052DF1C14ULL, 0x2535F9ABFEB43C84ULL, 0x47F68F7978948576ULL, 
            0x7EAE8904B195B5C9ULL, 0x9C89BEF6BC482B0AULL, 0xFD8C6A8EEAFAC32FULL, 0xB3D730EE5975FBFDULL
        }
    },
    {
        {
            0x7E76F347A620CDF3ULL, 0xDCAF268DD0489A70ULL, 0xF90890F525A1BF57ULL, 0x954B9EDB42FA8D97ULL, 
            0x691A4CE59B01033BULL, 0x0929232E4B685392ULL, 0x42AF5D2BECBDAC9BULL, 0x264FC11E0906AC1AULL, 
            0x331C505707BA10F7ULL, 0x9C0E76FC667E8569ULL, 0x62D99B80D0F2FAD8ULL, 0x5F2A5D2236467A32ULL, 
            0x16BB439330699FE8ULL, 0x0E0CE124AA6A8923ULL, 0x458D0E070B2E25B5ULL, 0x8CEABAC4E2E3A69AULL, 
            0x75B9521AB41C7DC0ULL, 0xA8B1153512075819ULL, 0x3B87F4680001BFA2ULL, 0x90A59E1D79104670ULL, 
            0x793D6DD08C29BD41ULL, 0x34759E10FCE557A7ULL, 0xE92B17FBED2C34C9ULL, 0x996B8D6D435E035EULL, 
            0x603797872AD0D051ULL, 0xBF22F6E1533279D4ULL, 0xD2B15792878E3FDFULL, 0x623DF1DB67C97985ULL, 
            0x29BB02FC72ED7B1BULL, 0xA87259AB7E4AB969ULL, 0x8BD6F09621D013EEULL, 0x93EF5E90BBA3DE41ULL
        },
        {
            0xEE3ED270A10641CAULL, 0x3AE14D9DB1F17567ULL, 0xB09D3AE1B092CDF9ULL, 0xABAE9E80F6203274ULL, 
            0xC9320D70F0DB32E8ULL, 0x4FE3309A86E00C8BULL, 0x8E5E72A2E4721727ULL, 0xCD7D22FB3AE719A6ULL, 
            0xCB808BDD231CF0E9ULL, 0xA99206C3FBCF2CECULL, 0x08203EA9D15DC2EEULL, 0x7673EE7927E42079ULL, 
            0x04BEC3950EBDCA77ULL, 0x9FDA8EBAF98D5A6AULL, 0x441466E5A5F2E2FEULL, 0x368F5CF96564B7B3ULL, 
            0x498F3836D84D4FC1ULL, 0x69D1F4457FECE65CULL, 0x012FFF2B3713CC48ULL, 0xF4CCBA274AFE66D2ULL, 
            0x0E2259999A5F6AA1ULL, 0xF1B73E36B84F314FULL, 0x8DBA0A05963D1C92ULL, 0x8745A1A335AA079EULL, 
            0x53CBE77912475202ULL, 0x8336D74E0DD5F1DEULL, 0xF1ADBDE142F1F4BCULL, 0xA56850AE1848B9DEULL, 
            0xB6D6186D1E560A05ULL, 0x861A297F8B1BE1FEULL, 0x5034175EB76390E6ULL, 0x7D0F9193351A43D7ULL
        },
        {
            0x8F1DBC2F86D02769ULL, 0x208DEBDE7E37B411ULL, 0xD8A7F2ACA6A1C626ULL, 0x3652486DAC0FFC68ULL, 
            0xFFF869CB70134928ULL, 0x1BA2DFB39BC0FF8EULL, 0x902DD16BC98E9397ULL, 0xE8D81AD90D2D2BE2ULL, 
            0x728AFA37B96897E1ULL, 0x44D6FAFBC6F57F92ULL, 0x9DCE922C2B05042EULL, 0x7E872EB49AED4B1FULL, 
            0xAC5FA6CFDA81A9E3ULL, 0xB225D723BBCDFAB2ULL, 0x5A8DDF67B86966A1ULL, 0xEA7E5F4EB9CDDCE0ULL, 
            0xA90531C4C5A50427ULL, 0x5423CB385551EC55ULL, 0x2DA8A855E38A8E71ULL, 0x1ACBCEEB2D2AAC59ULL, 
            0x73013575DDD4BFCEULL, 0xF94F401EF247FA31ULL, 0xDAF7FADF57E5DEFBULL, 0xA737B9EB8840CD7EULL, 
            0xECD4BFB098349335ULL, 0xCB445D863B183727ULL, 0x3E9DF7DE69F5DC8FULL, 0x1A35088DDACEE1CDULL, 
            0x29A206C42EB20A2BULL, 0x204E07BB6540992AULL, 0x8CE4BDA44779C2E0ULL, 0x87B722754207D50EULL
        },
        {
            0xEBF883C5668B4901ULL, 0x86F121506F2B9BECULL, 0xBF684ADF1AD8402DULL, 0xBFEDF2AE43D79136ULL, 
            0xCAC9DDDD23C10E7EULL, 0x37AC4CA1FAEDC4F8ULL, 0xD756D0B01A68C692ULL, 0x71CF113F0B24EDDEULL, 
            0x59D15C2C980E270EULL, 0xAA4F70997647CEB4ULL, 0x51C1D12B01EF23D2ULL, 0xAC694EC1318CA3DDULL, 
            0x57345C4003D5CF31ULL, 0xB8672607EA6C123BULL, 0x586F262FB6D6B65CULL, 0xBC98876D7FF215C0ULL, 
            0x8FE0751FBE5D2B0EULL, 0x5EFC51E64987128EULL, 0xD914595659483533ULL, 0x9AECB9C6A94C512CULL, 
            0xCC47B80120E5FA5CULL, 0xC43390DF2E3A2124ULL, 0x6D181808D719A4C2ULL, 0x279B6F5298602FB5ULL, 
            0x43C4815A0B4893F0ULL, 0xD63E0283F0A6A5A3ULL, 0x27FD36ABAF09EC93ULL, 0x684218FB844CAA50ULL, 
            0xEEE0C1B61B389B6BULL, 0x5526B1F3946E50F2ULL, 0xFD64EBA75403353FULL, 0x29B8A94EC0C3ADE7ULL
        },
        {
            0x9825DB8E0E9ABF88ULL, 0x65291D9A7DCF5CBDULL, 0xB2D050B67E63F361ULL, 0x83242E92487D9ECFULL, 
            0x6A51CD79EF061A06ULL, 0xD2CB797744524CB0ULL, 0x274DC3C21F9680A1ULL, 0xC5BD5E8E79D82399ULL, 
            0x40E0922FF42C17D1ULL, 0xB162E9A990CC1C17ULL, 0x9DFD4EE79CF124A5ULL, 0xCCFE7F240F241936ULL, 
            0xBF7B9BE0536C7342ULL, 0x6F612415620306FCULL, 0x42B00BCA1CC9BBE1ULL, 0x1154C48EE499CB26ULL, 
            0x856DA909A79F4DFAULL, 0x321018EE3E309023ULL, 0xFDB967C643E24F83ULL, 0xC24CDE6302FD1908ULL, 
            0xA4E91A7A198ECC18ULL, 0x2D0733763B4A7B73ULL, 0x29B603AB6D9A8DE9ULL, 0x723023991EFED1EAULL, 
            0xBDE6FECA821E28DEULL, 0xFC4D25F2C641508FULL, 0x78A329B3EF97EE2FULL, 0x179E81D9CD19764CULL, 
            0xFE8754F5FC89635FULL, 0xE6A16DEEEFCC46BEULL, 0xA27311B95A3896FDULL, 0x13841DA4D878F8C7ULL
        },
        {
            0x03FCFE28178274E0ULL, 0x345E870A09E0B91CULL, 0x7AD032929AE04250ULL, 0x9A05412484692939ULL, 
            0x5E604AAD1874DDF0ULL, 0x7A0F8DDEF883E62AULL, 0xA773D7BD5A9EFD40ULL, 0xF00EB326856408F5ULL, 
            0x8CF2D66D19A344C7ULL, 0x80FE9B508F67DC04ULL, 0x234EFFAA491B5A6EULL, 0x8670C2B9D1BCCDD7ULL, 
            0x939EC0F7F249B0BFULL, 0x077B43CE352B8FBDULL, 0x124A5ABF21FD7C59ULL, 0xFC492E1267C92895ULL, 
            0x4ADDB31A4F956E81ULL, 0x4FBA4C0B87D06B46ULL, 0xFAB5CE535EACF52CULL, 0xBAC229266D3AE7A1ULL, 
            0x8D24ED5A4EF11B2DULL, 0xD359DFDB4A70596BULL, 0x2FB89D8BFD0396F0ULL, 0x33E82E86E10BD257ULL, 
            0x963E36B6A3088A62ULL, 0x8BBA98BED738F675ULL, 0xA8733DFDD5B102D7ULL, 0x54EB6932D19BD3F3ULL, 
            0x71CD1ED5B411F0BAULL, 0x538783BF48561E17ULL, 0x17A9E197D0C5785FULL, 0x170F3E592F188CB7ULL
        }
    },
    {
        {
            0xFB428DDA6AF74296ULL, 0x6631D2BF167D01D3ULL, 0x8F40B9984BF52CDEULL, 0xDF59552C89000047ULL, 
            0x915F00294F8EACD9ULL, 0x12096CDC4F3998B5ULL, 0xBCAFF550999C0409ULL, 0xF156A40718B04488ULL, 
            0x1787F7721DB8A829ULL, 0x2574B81A9038B47DULL, 0x9F1875B4CEF1D059ULL, 0x92950BE213AF68C6ULL, 
            0x81A7336792CFC1D9ULL, 0x67BD47E0725B30EBULL, 0x73DA06CBD8C2B038ULL, 0x5A2A2950386FAFA5ULL, 
            0x1049944FCBDB8407ULL, 0xC72B916670CE87B2ULL, 0x9C079691970F1DE9ULL, 0x1D33BD5EBF2DCC33ULL, 
            0x246DC929EA6CEFEDULL, 0x998F419FBE19075BULL, 0xB0727426D4D8F7E6ULL, 0xB5E4060F9EA03688ULL, 
            0xCA75992D40781569ULL, 0x2E8DA706A06EEABAULL, 0x59CCC2CF0FCA85F3ULL, 0x0999B3CA61FC79A7ULL, 
            0x4EF5E80942BE6B0CULL, 0xA529E4420140BCDFULL, 0xCFE33CF4FE28649EULL, 0xCBE2080D973CAF33ULL
        },
        {
            0x3ABAF6A2F192F24CULL, 0x508F1F9D0248D6D4ULL, 0x819FED00A3D08B59ULL, 0xA790AA25F34AA50DULL, 
            0xE133ACFEDF02E0E3ULL, 0xBD7459D2038D2BF6ULL, 0xB41563360423EA0FULL, 0x5D37585280B972BDULL, 
            0x0F150B4253E545DBULL, 0x7CB28012CA5DC063ULL, 0x5D9BE36668754842ULL, 0xA66BC6F7F1DACF8DULL, 
            0xB2247FB424547CABULL, 0x92C2FB263DBFB656ULL, 0x86BE0E84BFAD2BA6ULL, 0x05B1AA569C234FD6ULL, 
            0x8A220F3C894A3965ULL, 0x072F2E46C44716E0ULL, 0xECF2351511D5AA65ULL, 0x3E072CA6F3B98DEDULL, 
            0x9ACD53BD0B4FA42DULL, 0xA961CFF1C68AB833ULL, 0x52DAF7ED7BE76210ULL, 0xB8AB9316930B0CD2ULL, 
            0x131DDEAAC17446C2ULL, 0x74D7FF7F77730FEFULL, 0xDF6991220707E0D1ULL, 0x1B47953081F67601ULL, 
            0x6CACE67258E70121ULL, 0x54D8841960924018ULL, 0xEC0ACA745AF5FE51ULL, 0x4CF58B3224C3D415ULL
        },
        {
            0x8F7C3CFA35207495ULL, 0x0B26537DDF4D88D5ULL, 0xD8161C57AC34A3BEULL, 0x463A2DE56C074362ULL, 
            0x85A16379D589876AULL, 0x6B1C7F151D03D5F3ULL, 0x754D031F2D73C6DEULL, 0x01F2442258AC204EULL, 
            0x080C52965280274AULL, 0x748032EDD3E31B2CULL, 0x3A3618D1B618F1FCULL, 0x4701F2C432BC2DF2ULL, 
            0x664AF9B659238A2EULL, 0x8CA90B6A0E94525AULL, 0x98AB76BBB296BDCFULL, 0xF9DAF71DF78B1FBDULL, 
            0x921F4163C7ACB481ULL, 0x861D01F7938EC471ULL, 0x95850025384D9212ULL, 0x08B790C9BC8F9B9BULL, 
            0xC3DFCB6F9359F2DCULL, 0x60D52A13E96958D6ULL, 0x4739883DBF408443ULL, 0x5995ABE8B39B0F07ULL, 
            0xEB4EB0A923F22366ULL, 0x639B15EC3485559FULL, 0x7535911E208D747FULL, 0x890CE5406F8B5CD2ULL, 
            0xDFC963ED8423267BULL, 0x2260BE8EDF62F241ULL, 0x880D21CC105DDFDAULL, 0x0027E9DF5B9185CEULL
        },
        {
            0xA6CB3418296DF7A1ULL, 0x9C36047975845477ULL, 0xB749942869B33C3FULL, 0xDE0DBE83D76AEFE2ULL, 
            0xA410CB6ECF970CA0ULL, 0x479147FBF8670DA5ULL, 0xC02D9B084E33053AULL, 0x39210FC9D721CDEAULL, 
            0x8CD04AB76AF9F682ULL, 0x105D6AC68F9B1C08ULL, 0x04246EFB9E32DDDAULL, 0xF48F7C3CF11BA846ULL, 
            0x3999C7600487E845ULL, 0xDC936FD6ACC9DF9AULL, 0xD0941E035BE428FDULL, 0x4E2266DCFCABE0E8ULL, 
            0xB030EC94F628DC2CULL, 0x7C497C7016085D81ULL, 0xFE2076CD8E1AB89BULL, 0x82AD98C5F832390BULL, 
            0x8C7B44A2E5ED05B6ULL, 0x460D15295D1D0AA9ULL, 0x732D940F800003FDULL, 0x26283E38C0221BB0ULL, 
            0xD3D3A1DB5B633841ULL, 0x377401C9C906E6EAULL, 0xE5D28C962F87777DULL, 0xEF8D788698F0614AULL, 
            0x912B758098B56071ULL, 0x24E5E07DB7C24E98ULL, 0x1386C4F2AFAFADDAULL, 0xC5FD217C4CA154D5ULL
        },
        {
            0x90E3DFAF76E1FCC6ULL, 0x947DFB0DA1426355ULL, 0xE64F137F38C5AE04ULL, 0xB1EEAC3AF1832E8AULL, 
            0xDE89796C74DD9D6EULL, 0xF50EF1F8E4776492ULL, 0x73EA1C9ABB72BBB9ULL, 0x93ABBE14EFB0178EULL, 
            0xCBFBC8D48F559F70ULL, 0x411C3A5DCA021A1CULL, 0xF22D68DAC6C783F0ULL, 0xE2CA97EDFD4AE635ULL, 
            0x0B14717CAAD51CB9ULL, 0x918754B57B2E05F9ULL, 0x2356A42D7F1D7564ULL, 0x919FFB2551231AB1ULL, 
            0x6C65B090AE8783C6ULL, 0xF9A5F396161BBFEDULL, 0x4065F8980E840D31ULL, 0xF5FC464838F39901ULL, 
            0xB0666F248433EF85ULL, 0x780F04D726429E10ULL, 0x45B0B44132953166ULL, 0x0A672A721C354564ULL, 
            0x0233680ECEC84F93ULL, 0x24D040DFCCEF541AULL, 0xDFAAE84D2D610239ULL, 0x7DE4DA9AB225A58AULL, 
            0x97133DD61FD3CACBULL, 0x5FFA1C47180920B5ULL, 0x6707DADE14137AD1ULL, 0x4E4E7F2D26D6AE7DULL
        },
        {
            0xCA2F837A41268FF8ULL, 0x5167019A67BB8687ULL, 0xB4556244B6866788ULL, 0xCB1140A5D5631CBBULL, 
            0x752B625BAB740946ULL, 0xC39DA7819413D85CULL, 0x47F71BD2C610E2E3ULL, 0x03AB1733D7451163ULL, 
            0x9E1A162B141552D4ULL, 0x7D4F4E13E4B14DA4ULL, 0x9CED3DB6E78D7C03ULL, 0x97DB9F739251924AULL, 
            0x695781D720F52704ULL, 0x080CC4F301BD3BEAULL, 0xF0B0134335F4B9BBULL, 0x1D11E21491CEEBE0ULL, 
            0x3B848BF6C90D4452ULL, 0xBCA8489864DEB465ULL, 0x169F87B64444239DULL, 0x6302172CE2ED7F69ULL, 
            0x2FF037CF46F22C3EULL, 0xB6FEC480698F713FULL, 0xEBA156619865BD7BULL, 0x45283B18558BC2F2ULL, 
            0x66D5B6A9349E9063ULL, 0x5BE42D1DAB084BE5ULL, 0x00423968968A7C05ULL, 0xC8C486F55C3A9AD2ULL, 
            0xA588CC3DAF947BD8ULL, 0xA2A03CF15AB845D0ULL, 0x19A4EAF097D89420ULL, 0x22CAF831EDB47F27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseCConstants = {
    0xF06AB8F050C51523ULL,
    0x06E9BF7B0DC9516AULL,
    0xE747B5F9467297FCULL,
    0xF06AB8F050C51523ULL,
    0x06E9BF7B0DC9516AULL,
    0xE747B5F9467297FCULL,
    0x8A55CFB901E68B0FULL,
    0x5C6271B619CFDA95ULL,
    0xE9,
    0xA9,
    0x69,
    0x96,
    0xB6,
    0x8A,
    0x31,
    0x31
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseDSalts = {
    {
        {
            0xD33819BEF6F8EA66ULL, 0x8421BE6D1DB4E1F7ULL, 0x9B520FC2FC25F74BULL, 0xCC909ED9D6BEE889ULL, 
            0x8F9A44A877C9486EULL, 0x1A8ECB1C9A1C6476ULL, 0xDFCC8CF43C5F1F9AULL, 0x6BF6FEEB97DF58DFULL, 
            0x53372C9415C83444ULL, 0x1CAA1FBB340C24D9ULL, 0x3B5672E465B3C2A9ULL, 0xC41B1CC34370B899ULL, 
            0xDDDA8E1982DEB248ULL, 0xDC2C6FEF86EE24F0ULL, 0x9D26B1BC9C949C57ULL, 0x68E509517033955DULL, 
            0xF8C85063ECAFCABEULL, 0x28770583DCBECEE2ULL, 0xE5EC121EFE4B1A6FULL, 0xD26ED9B9076CB5A2ULL, 
            0xC3EE328302CD25F6ULL, 0x8B95326879E46252ULL, 0xFCF3C632F117D767ULL, 0x485BC72E631170F1ULL, 
            0xBCD9D03A085B5E74ULL, 0xDF68B734656920F1ULL, 0xABF5E90EE205D6C8ULL, 0x3A4E8FF74E406CE2ULL, 
            0x8496EC19FB0CEFF8ULL, 0x5A0863A3A73A73CCULL, 0xF51DF6AE0C6A57A4ULL, 0x1839E2AB0FD5637AULL
        },
        {
            0x74547FDD7778D379ULL, 0xE70C2F4E78AAC8BEULL, 0x3080A57710558B1BULL, 0x67CEA40FEDA355C1ULL, 
            0xF1ED3F54A8532B91ULL, 0xDE35D9D3BB195050ULL, 0x9160C6FB90BDA201ULL, 0x2C970DBB29CCEF2BULL, 
            0xBAA352A1BF365A23ULL, 0xADEF23401C8CA458ULL, 0x58B59DB352AC3D6BULL, 0x113E79DAA8F739CFULL, 
            0xBB8C6FD6F15296E2ULL, 0xDE7A5338D01FC72EULL, 0x53C98D2A3A11D3F8ULL, 0xD6B66083470333F5ULL, 
            0xDB1225B3E8CA6672ULL, 0x2EDF4AFA3FEB3A9DULL, 0x8865FDB9C128FD07ULL, 0x4230D7634F3C52E8ULL, 
            0xC933DEC27BE19F91ULL, 0xA61B39A4AA4D1331ULL, 0x6AF15A5BFBF29932ULL, 0x52AEEFAADCD5B19CULL, 
            0x08D7D814B83F1F96ULL, 0xE4E2DCED7F65B70AULL, 0xE28F1E7F066C9068ULL, 0xAB4F700F449C32EDULL, 
            0x392D57C5E6BEBA8DULL, 0x7D721A8742F752E2ULL, 0x0517FA3879642E48ULL, 0x77CF7651B4E2E6DFULL
        },
        {
            0xE59E5EFC5BF5F48EULL, 0x9197DAE76D1889BDULL, 0x84B8250D7B6652A7ULL, 0x643F88D77FD9C260ULL, 
            0x1DF9C623D3C1DC85ULL, 0xDDDD277E91FE71E9ULL, 0x8CC59F8641C0271AULL, 0xDC8B78DB85A042F3ULL, 
            0x2EF363C99279FE06ULL, 0x8B5C8C93B2B7A35BULL, 0x9F0FFD4D4D0569CBULL, 0x720DFABC9BF4AC75ULL, 
            0xDE58ECF9125542EBULL, 0x562644F012E1FB0AULL, 0x5FEADD96BAC68A24ULL, 0xA5F41E480DE7548FULL, 
            0x3486FFDC8D65D9A3ULL, 0x6A09E2B2E3AAC032ULL, 0x73E9200414370822ULL, 0x283616B2B65964BFULL, 
            0x45653D0FE5454B1CULL, 0xC7CF754B9DDE2961ULL, 0xECF6E1ED4FBA74ADULL, 0xAED574F8412DDACAULL, 
            0xC25FCE5CB6D83E5CULL, 0x35DA2A3193314704ULL, 0x659EB6F625060554ULL, 0xC3DA30ABE87ED68CULL, 
            0xC4EE7E67C0A6F75FULL, 0x285206FA1920F053ULL, 0x3EF5146390EDA57BULL, 0x9BF3B3AE5537B59FULL
        },
        {
            0xA9EE6EEFBBBED1F2ULL, 0x5A1E3324F4314A91ULL, 0x45C8B94CD675B56EULL, 0x74509F195A3F8393ULL, 
            0x755927084C92F16AULL, 0x6B82B63A73BAB3D3ULL, 0x2BC29914DC8978DAULL, 0x8CA4F9319D9FDF50ULL, 
            0x477E1E3C36A9FC84ULL, 0xF8837F23D0DF64EDULL, 0xE5C80A22F1C5D4A8ULL, 0xF8D62C8D6D8DFF69ULL, 
            0x5330CD2D616D0C3EULL, 0x288BF47DA16433EEULL, 0x27534EE238C11E1CULL, 0x6DE02E8530F0556DULL, 
            0xFC6AE6E8DDAFE4C1ULL, 0x14162F26BB699926ULL, 0xF04DB239206D09D6ULL, 0x4815C4633E8FF122ULL, 
            0x1F4CDE2C83416F33ULL, 0x88CF493CAAECBF52ULL, 0x5C7302D3E4B1868AULL, 0xEDDF6066FE516982ULL, 
            0xC0DC0C0FB23CF435ULL, 0x4053C56D8A824B63ULL, 0x225999B6906FA751ULL, 0x5BB541BF0942EB55ULL, 
            0xF44140E8D5E6F642ULL, 0x26F2D26462C47872ULL, 0xCD64A35F1A0A89D0ULL, 0x97C464421D032FE8ULL
        },
        {
            0xADD3263701C6A82EULL, 0x5EFFA3CA1C16B92EULL, 0x660C6AE7FBC8576CULL, 0x77557C33EB19EB10ULL, 
            0xA091E128D4CD8D78ULL, 0x74A20999CF226A10ULL, 0x9CB908ED554253D1ULL, 0x584AEBD5C1565AFFULL, 
            0x5FAE84E2E52D9D2DULL, 0xBACFDA4FFB568B0FULL, 0xEE6DAFD2C0403D47ULL, 0x7656421FCDD54F94ULL, 
            0x19BF5AD519F40925ULL, 0xE1FBE22C8C1AFE83ULL, 0xD26FE8ED41B00994ULL, 0x455A3F2A469BA3C3ULL, 
            0x337605F8D0062C57ULL, 0x2ED547E0241A8514ULL, 0xE9ADC14C1D14ACCEULL, 0x241D814DFAB984D5ULL, 
            0x68274F169CC3BFD0ULL, 0x254E6D32B204DF0AULL, 0xEE2C5AE79CB0296BULL, 0xFEB65EF1863D5A64ULL, 
            0xFBD264CBC83437C3ULL, 0xB485B621973C5E01ULL, 0x178865D9287DB596ULL, 0xEDF7313037B233B1ULL, 
            0xFA3EDDE67DA0C103ULL, 0x564625866D6A5407ULL, 0x72C97286E79042EAULL, 0x2273CE58CDBB9365ULL
        },
        {
            0x2295675607DD32C7ULL, 0x85D6DC9FB6F76D91ULL, 0x3D84437EB8538108ULL, 0xF836962C97E757ACULL, 
            0x8F302689B96ADB0DULL, 0x31BF673B477D6D77ULL, 0x0C5751A1E8347AF8ULL, 0xEFDAFA77708A8806ULL, 
            0x3117E4ABF4419FC9ULL, 0x1EC4392B6C57BD6CULL, 0x1F9DCF1402103BB9ULL, 0x1C2123A0F617CA61ULL, 
            0xE8E6228A99240BAAULL, 0x128A7B8C7A6518BDULL, 0xC64552AD82087731ULL, 0x0E617E889E9236E8ULL, 
            0xB4E561E43CB6099BULL, 0xE13921A1DDA85312ULL, 0xED321830364A1C29ULL, 0x1E7EA62CCCBF9409ULL, 
            0xDE4EAEE04896F346ULL, 0x4667DD84116EF6CBULL, 0x9CCDEEA417806553ULL, 0xDEC7DB8F40583FA4ULL, 
            0x80CE7AC97D8D21C2ULL, 0x8348B1D2177172D1ULL, 0x36A2D917D14259F8ULL, 0xA2B99F2189DC5DF1ULL, 
            0x304999501E22071CULL, 0x8E0D2CB1DDD0AB21ULL, 0xC93A5EB16DB928B3ULL, 0x92B90F7456B6FAB7ULL
        }
    },
    {
        {
            0xA0E83015AF6C6CEDULL, 0x66D534EB0444BBA7ULL, 0x931E50C884AB2C35ULL, 0x079269501F94BFA1ULL, 
            0x1573CF9127D80872ULL, 0xC8FDD5FE58902492ULL, 0x50000FBC6939D8D6ULL, 0xCE0182A7ADDB73A8ULL, 
            0x53C2038127EE4214ULL, 0x670DF30318AA6142ULL, 0x7B1E3B55C7DE0E08ULL, 0x6E978052E7BFCA37ULL, 
            0x82A193E44D5A8625ULL, 0x35CD0A2F7E9B465CULL, 0x8CA110BA9205185EULL, 0xE713C53E638A043AULL, 
            0xCABC9B4C221AF3F2ULL, 0x9C2BF5388E39AB0DULL, 0x6450364EC4CF589AULL, 0x59AC48B8F70EBDD7ULL, 
            0xE11973FD3DD8A929ULL, 0x65F213026402735CULL, 0x1B5B6B10699418FDULL, 0xC06F50C925C3BDCFULL, 
            0xCB9B6E4C81BF0917ULL, 0xC281FBC15A1C0DB5ULL, 0xA670EA9054625AA9ULL, 0x796AD78BE3E528BEULL, 
            0xCD76CE7D350C9DDAULL, 0x1E9C121FB2AAF1F1ULL, 0x781EF110677B7490ULL, 0x642B69B629AF500CULL
        },
        {
            0x6E1D5154EA6A5F60ULL, 0x8CE8722503F40EB6ULL, 0x647F8AC2A1373957ULL, 0x52CBEA9613BB6AC3ULL, 
            0x75AB09E3C7F8CB66ULL, 0x6B38F761D1E002FDULL, 0x0B06E8C42435241FULL, 0x4B3D19B2F2ECC624ULL, 
            0x0E5911A6227F061FULL, 0x2AF48FBAE1FF42EDULL, 0xFEA292105C7B146DULL, 0x09D113AF9E4C085DULL, 
            0x40E0D5C5A7F5934AULL, 0x2EE7643973BA06CCULL, 0x81ADFC1FE16C7C67ULL, 0x0E772DA0E4F9F59BULL, 
            0xCA69C9F443F9F351ULL, 0x936B6DBB44C44524ULL, 0xB5AA049BC312E7B9ULL, 0x78D29A7742B3040BULL, 
            0xA91DBA1D72355932ULL, 0x887813F86ED08000ULL, 0xA3DB7568AEA54CFCULL, 0xECC09375E5669BA0ULL, 
            0x5C8FD4C457CA7FE3ULL, 0xF0F8A985C0272BE3ULL, 0xD04DC60BD2C170FBULL, 0xD11600E5704073F1ULL, 
            0x77AEE35C2BCB3145ULL, 0x07604A4BE2ECF843ULL, 0x118178793CEF40E9ULL, 0xC8E339FF1499025FULL
        },
        {
            0x691029468966E2B7ULL, 0x4601886ADA820E3FULL, 0x6399570C94FC1F11ULL, 0xECA897F77803BC58ULL, 
            0x8627307C3D99F2F5ULL, 0xBD0755261170EBB5ULL, 0xF6A9DC0266BA2778ULL, 0x5E8588D508CD87DBULL, 
            0xE369242AEAE52F8BULL, 0x343AA8DADB4D6FEDULL, 0xB184DD64093B18FDULL, 0x10F950A5EE7F0545ULL, 
            0x5AEA55EA0FF948BFULL, 0x3DDFE9CA8D18439CULL, 0xBD38090ED6810031ULL, 0x62F3FFDDECAD5993ULL, 
            0xE90AFE9CCB57BF30ULL, 0x4A4D60D6E1B6E7D7ULL, 0x6BAD47B476B13711ULL, 0x83A1B98951B41E66ULL, 
            0xF63EADE5ABFD0A23ULL, 0x46EE1029D752FD70ULL, 0x59A3901807270A86ULL, 0xEF11FBCE8B18C803ULL, 
            0x46B13B19D9BF5A82ULL, 0x19C3D355B44697BDULL, 0x607FDCD269FF0595ULL, 0x94DBFC8977EC37C7ULL, 
            0xF0E2785DF3F1704CULL, 0xB56943031287FF2DULL, 0x0E66C8EA271320F9ULL, 0xB8F74C3F7113B6E3ULL
        },
        {
            0x3BDF65A6A2EE8083ULL, 0x4383CA26B0C586B4ULL, 0xA9579DA52210C704ULL, 0xE3ECC2A5B845DCF0ULL, 
            0x9E9A7D3BC9968DB9ULL, 0x4841B437B2891607ULL, 0x069B6A83AADB2294ULL, 0xDADA5F5D5BE319C9ULL, 
            0x87E9FD842DA206F7ULL, 0x1B7F1D00A7A4BE57ULL, 0x2CAC5E53FE9389AEULL, 0x53F842A7B79F6B74ULL, 
            0xE0DDDA47B77B9772ULL, 0x2AD0AD2762266874ULL, 0x2419654BF50BD7AEULL, 0xE38E7CA346FF405EULL, 
            0x4E0E57DCCEB1B52CULL, 0xA0CE9C34DC15BA7AULL, 0xFACA1C6BC4D8C5EAULL, 0x40B9C82BD8334A5FULL, 
            0x16ADAC20BDFFD315ULL, 0x847DA0115A377FF8ULL, 0xAFFF2E8DC31F2D2FULL, 0x5EDD69F794443D7FULL, 
            0x6ABCD984B7CAB5D0ULL, 0x5877D3006F8AEE8AULL, 0x09C7AD7FF2449B5DULL, 0x6EA1BBE3F366BC1DULL, 
            0xDC11B5FAA5DECD63ULL, 0x4362DD74A86744D4ULL, 0x062F266DA48398F0ULL, 0x26C2D40757E8880DULL
        },
        {
            0x5BC64A3DAE185681ULL, 0x49988C95613C4B17ULL, 0x9D7722C5D8596766ULL, 0x3F7EF10C8651CDA7ULL, 
            0x29C5CC64FB7D3D46ULL, 0x07A14E8B00A1B21FULL, 0x29D09380ED5EE0BDULL, 0xCCF2031BD3B443FDULL, 
            0xE9BB9668DC1C4975ULL, 0xC636D70C9C174D6DULL, 0xB0C9039B528F38C1ULL, 0xEDE28E38C151B684ULL, 
            0x2FB5A2AD6F0AF211ULL, 0x7A55B6AA49A471EAULL, 0x8382CD5E77022418ULL, 0xB41CCAE7817CB5D6ULL, 
            0x099649C655ACF710ULL, 0xAEA193980D90F133ULL, 0x97539515CFC879A7ULL, 0x1F46D8E9CF02109CULL, 
            0x900CF7BC3EF9CDD1ULL, 0xFCEED169DCA86CDCULL, 0x81B3A25405B54E2CULL, 0x01B2D82834813CF7ULL, 
            0xB60D1C4CD5EFB4DAULL, 0xE0C9F81ECEFD2601ULL, 0x5902D81922492E61ULL, 0x231E005B2C801588ULL, 
            0x48C29CF9910BC628ULL, 0xA589199CA9D36D8BULL, 0x568A1B030D0F105BULL, 0xADE968C6A401E376ULL
        },
        {
            0xDF8BD91E988122D5ULL, 0x30DE4B3F7FF5D002ULL, 0xBBE70F9E22997814ULL, 0xA38320D127FFF7F0ULL, 
            0xC347432544613C42ULL, 0xBA55B25DAF5A6FB3ULL, 0x16B1F404F919894FULL, 0xCCC1FC80A7798F64ULL, 
            0x8CEA3CD717BBDCB9ULL, 0xD972E1F5BB942353ULL, 0x5392B39A9DF0F1EAULL, 0x1C6E0A333CE9D6B0ULL, 
            0x83E05498746B1B27ULL, 0xC64C39225C5041E9ULL, 0x5406AB520755CFAAULL, 0x0ACD907B2F96A96EULL, 
            0xC71FB3DADE45F683ULL, 0x729EDEEE539A2014ULL, 0x74178FFC08D28776ULL, 0x6C603BD4C544F794ULL, 
            0xB11BCA3D81DF4FF3ULL, 0xE1AA4D621F3E5220ULL, 0xF7CB2383B9F3C5F1ULL, 0x9FFE47505B12B69AULL, 
            0x55313D422CF5F25CULL, 0x5430F5EDB7E665EFULL, 0x92D1739A4F6C13CFULL, 0x2D73BAFBD87F981CULL, 
            0x6495ECCE5B61A882ULL, 0x3AC3DFD2363DE4FBULL, 0xD2C9120C7FED30B0ULL, 0x889BDC65E953CD23ULL
        }
    },
    {
        {
            0x11365CF02D457AC7ULL, 0xA7C0956FD4AD71A7ULL, 0x3B19E7261688DB59ULL, 0xD3CE0ECF5492B44DULL, 
            0x8FD259C99A03F4ACULL, 0xDB6CB7BEB4254BC5ULL, 0xF560DEEE6E11FFF1ULL, 0xA7F44CFF15BBA2FEULL, 
            0xF879401B5C8F5170ULL, 0x3A11E14E5690503BULL, 0xA3941F5E73F2EBC4ULL, 0x355F8E74698276B0ULL, 
            0x7DC97AC83A166264ULL, 0xCF89525EF8C8DECFULL, 0x43F5DFC7645CF71BULL, 0x392F9E33707137EDULL, 
            0x2A918CBB9B5377E4ULL, 0xFD19E2BAFB8860D2ULL, 0x92C6B28EB6BB3174ULL, 0xF955E52D89698B5DULL, 
            0x3D727B723616204AULL, 0x3EA871ED89E64CB3ULL, 0xD1687E39131A8CFFULL, 0xA5440D038509E989ULL, 
            0x4B2F7D48F2643F0CULL, 0x1A7AEC1B8D360907ULL, 0x72E9D1597DB897E2ULL, 0x47EAA22817867B0EULL, 
            0x5D9BCF6B2953ECE8ULL, 0x54AE4EB1DFEA9410ULL, 0x968FEA6348A45BFEULL, 0x45EE8BCD7D5365B8ULL
        },
        {
            0x4ECF7C98C224B017ULL, 0xA5864D6E24563175ULL, 0x0F0376FF58CBCC50ULL, 0x7CF710629C7B485EULL, 
            0xA07ACB02DBD5EAFEULL, 0xA266A6071EA40BB1ULL, 0x6DCB790885308035ULL, 0x127960F9B1E33964ULL, 
            0xF49B0049600A386CULL, 0x01DD98DD4B4991BFULL, 0x74B9448620C24356ULL, 0xBE5274E433FC39EDULL, 
            0xD280EC9A99C3091AULL, 0x622CABF5F429C988ULL, 0x14D54EDCA73B15AFULL, 0x1D524B521E002F48ULL, 
            0x840D24DAD7BA0448ULL, 0x6A518A942E09A7DFULL, 0x5841EE2D4741401DULL, 0x147A4415836C16E6ULL, 
            0xD7381A29AF7B8ED2ULL, 0x2BB13672827629EFULL, 0x11A35403BAAB1CF3ULL, 0x66E6211E8C3C02ABULL, 
            0x835408777B02A44EULL, 0xF7ED8DB048ED6300ULL, 0x668A4ABC5C3DFDFDULL, 0x1A020DA4CA1822E4ULL, 
            0xC34B6B39113D3C26ULL, 0x7A35C3AF30C9506EULL, 0x8883F284B0439A02ULL, 0x9F98D7C6ABB6FAD3ULL
        },
        {
            0xBA59B37D99971E2CULL, 0x1F34F42BF57B4FC5ULL, 0xC783BFF496C7F8BCULL, 0x43E45946D32EBB14ULL, 
            0x99AF2A3436DDE13FULL, 0x8AD32F9EE04B461BULL, 0x4BFAFDCC8FD91DF4ULL, 0xB870F0A7FA2D733DULL, 
            0xE6764FB74E3FD1DCULL, 0xEFE4CCA2AC19433BULL, 0x8D58C64B500EBE2BULL, 0x21E69E331C7F604FULL, 
            0xC0D41D04AD1A3E0CULL, 0x6C1A58FB210289B7ULL, 0xDA3678175D64E955ULL, 0xF06B1A00A824DA76ULL, 
            0xB8FFFC9EE0E35A8EULL, 0xDE2119C78CDC7C03ULL, 0xAB771E48C8FDCDD6ULL, 0xA6DF9A4ADDDFFF45ULL, 
            0x4EDDEFD13E4AF2C0ULL, 0x746566BEE012EC1DULL, 0x92A710567A20228AULL, 0x2B4105AB5A535FBBULL, 
            0x55E483B184EF4470ULL, 0x01D39FAA755FEE00ULL, 0x971CE80CDABFAF0FULL, 0x31B33B96A25882D9ULL, 
            0x7004E5A832E0E450ULL, 0x4275DD691E9A5CD7ULL, 0x9351EACFAD094A2EULL, 0xD9951061A7C3C40FULL
        },
        {
            0x23E64DBEFA01AE01ULL, 0x6090142AA6860CB9ULL, 0x3460DEC0E0EE3F86ULL, 0xC72038869E188315ULL, 
            0xC652507E827FAE05ULL, 0xDB25B8E497D8E465ULL, 0x7D81A43D8AA08A9BULL, 0x052A5E387CC9C97BULL, 
            0x778741778DAC6F31ULL, 0x9BF0C60281265D8AULL, 0x4BB75E9BB66E11E8ULL, 0x70C41889FFD69949ULL, 
            0x65C76D080120EDB0ULL, 0x7009B2FBEFD0BAB7ULL, 0x749F580FE2BE8C98ULL, 0x9FDE113F833BD22BULL, 
            0x0C092BF0F63441A9ULL, 0xDDB2F90931C7F85EULL, 0x7F40773E94F483F8ULL, 0x3A9EF8164C162A51ULL, 
            0x8355D157B0EC8EC7ULL, 0xEE8A764B0CE75E6BULL, 0x319ED19160993D3CULL, 0x7C429C62D58A4C64ULL, 
            0xFAF9BE5C490CB972ULL, 0xF881F9CFF90EE7AAULL, 0x817529E42865BA60ULL, 0x566024CE9A1E2182ULL, 
            0x7AE2600D35EF9BC4ULL, 0x42C2A0743727B777ULL, 0xE7AB754564D9CEA3ULL, 0x9F0B3428763647A7ULL
        },
        {
            0x1899401FDC352142ULL, 0xAAEA72790D290DCFULL, 0x26267298CAF57D37ULL, 0x8C1F2C87D64D105CULL, 
            0x1B8F1AFE038BA7B2ULL, 0x59470751B6FA5906ULL, 0xC40A0E14CDCC9EEDULL, 0x48FB73E945B38D89ULL, 
            0x4E0B27F595EBA992ULL, 0xB12AFB798F8FAD36ULL, 0x134435EC9A2DA41EULL, 0xD4BEF8B61BB62048ULL, 
            0x1FC7BB6BB94C6769ULL, 0x4EBBDAF7E574CE8CULL, 0x7517AB84AD7B26DEULL, 0x7DBA0110918F0E42ULL, 
            0xFC0F7B82BA448C92ULL, 0x29D2F854B149AE51ULL, 0x2CF7BC698AAA19FFULL, 0x339CEDCB8B4AA0D7ULL, 
            0xD3954D44FA6FAC7CULL, 0x6C93B0BD3A7E7633ULL, 0xF9CC7A30F90CE9FEULL, 0x9AEC6677F793D7A9ULL, 
            0x2D53EED0C46B4C76ULL, 0x0BED58E7B297B367ULL, 0x7C1AF6441FBC2BA1ULL, 0x0A29F9D3A2617FAFULL, 
            0x966224B793825391ULL, 0x820662B3DB21E807ULL, 0x2CE3AD84F986FBBFULL, 0x393E5C200777FB2DULL
        },
        {
            0x50CBFB7632E22B20ULL, 0xBFC3728C8C1A09BAULL, 0x10BBD3B116170656ULL, 0x976121E6B6D66B5CULL, 
            0x0F4EACA98F5C9499ULL, 0x65B7AE5106A9A6D0ULL, 0x1E8A62D0A3AF051DULL, 0xBFAB63E9F42C5553ULL, 
            0xF545292485F3C2C3ULL, 0x274F38C4554EC0A9ULL, 0x20C8FB5586D0F717ULL, 0x930964B1051DE6E5ULL, 
            0x7FBE894D7E78E40EULL, 0x05FEFE54B9B74BC6ULL, 0xB982D755EAD5C82FULL, 0xBAE0E758CD16CD44ULL, 
            0x93F1C97CF95E4A40ULL, 0xEF2F3B924AEBC828ULL, 0xD80CA06BEDDE3841ULL, 0x77386F0B8CB8F034ULL, 
            0xE2B21E7E17912166ULL, 0x86DF8740680087D8ULL, 0x06B66902E6D278C8ULL, 0x84E6EAEB0E7CFDC5ULL, 
            0x006DE9F37E618AD6ULL, 0x94E9004F4AA57AA1ULL, 0x4328EA993E8936FAULL, 0x9D30EC95C2FE890FULL, 
            0xCAE38F6CA5903549ULL, 0xFBD504D04AF0B760ULL, 0x5022211885F6F05AULL, 0xC94B75B0B0F7B809ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseDConstants = {
    0x8C22821194FC656AULL,
    0x75C07C02F4E3E706ULL,
    0xAB80A37B4A3F6C47ULL,
    0x8C22821194FC656AULL,
    0x75C07C02F4E3E706ULL,
    0xAB80A37B4A3F6C47ULL,
    0xCCB4E1C078ABC602ULL,
    0x2F8E556B3C100A21ULL,
    0x2A,
    0xF9,
    0x75,
    0xB6,
    0xC0,
    0x92,
    0x8F,
    0xE9
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseESalts = {
    {
        {
            0x8ECC82F15EB0D509ULL, 0x3BBC63B93629D746ULL, 0x19B38054F6878B45ULL, 0xC677C808D79E1457ULL, 
            0x5963A12A794B7049ULL, 0xD69157E0C4F27E60ULL, 0xCE5FDB942FC34EC2ULL, 0x3B558EFE96E52896ULL, 
            0xCF3DCB9E439FD199ULL, 0x003B3A3C2974D6A2ULL, 0x70D14A3A0E0F67B0ULL, 0x6A48D55DE13E09F8ULL, 
            0xF7405CB6F12A7C24ULL, 0xD8B88FEDCDDBD9DFULL, 0x7BAE3E4A011822A0ULL, 0x2E7195E8D81CF8CAULL, 
            0xEF886A71436C4435ULL, 0xF2285A3B230CBFE6ULL, 0xBBCA50CFFF704175ULL, 0x3242585A9198DFBBULL, 
            0x1D838149A7EBE300ULL, 0x505697BFBBCEFBC5ULL, 0x98CF120699692E0AULL, 0x01A8D1EFD84F6B55ULL, 
            0x422738AF1AFAB0CCULL, 0xC2F29D2558C7A01BULL, 0x2613509E23F0545AULL, 0x653CEC691FF3D09AULL, 
            0xA6651F4B7D358CE1ULL, 0x3D3DC94925B7E703ULL, 0xFAC6AEEAA7316BFCULL, 0x82E52957CEB6746BULL
        },
        {
            0x79EA86E1F6B8F05FULL, 0x01EA41CC0A23F316ULL, 0x4F3C6E4E6C801DF0ULL, 0xBC3C5DCC1F72EE72ULL, 
            0x96D221FA4D2EF004ULL, 0x49E9FF941C95DD35ULL, 0x9B2694F010FDD624ULL, 0x48E900D086DFB023ULL, 
            0x7B3F75835312ACB4ULL, 0x75FC007073BCF32FULL, 0xC245215DF1600012ULL, 0xF38D4EB363F96F82ULL, 
            0x360F8541AA1560FDULL, 0x9C007E77EF55D023ULL, 0x08A44CAD4205C55DULL, 0xD0D62FD58AE080D7ULL, 
            0xD652FCEE76326440ULL, 0x336DAE5913145399ULL, 0x3C858170A25CA7C7ULL, 0x1F59A78943AE3607ULL, 
            0x96D3ECA3742708CAULL, 0xD3451441B9848BCAULL, 0xED51E7563F9B04BDULL, 0x887D95BAD87A38DFULL, 
            0x281D74E712861290ULL, 0xE18BB9B23CED8DA8ULL, 0x36EFFE80D6DFDA6DULL, 0x2A1E62FA7DFBAD83ULL, 
            0xFA0AA1C08324CDB0ULL, 0xBC995F5E8D06BF38ULL, 0xE556C4E2E8DDEA6FULL, 0x2205186E9AA55391ULL
        },
        {
            0x7B6A7A5DCE0664EAULL, 0x681000055D44FE2AULL, 0x580D63FD209FC114ULL, 0xA25DDA3A90A9B3E2ULL, 
            0xAEAE68423DDFCD73ULL, 0x1B70780B798863BDULL, 0xF30D4665AB948F30ULL, 0xD9ADC7025AFD447AULL, 
            0x38C0902504157EC5ULL, 0xCF9194D212C05242ULL, 0xBC81C1A21082175CULL, 0xBEBC3900796B95DAULL, 
            0x32C808EFD85AE3CCULL, 0x705F449B8E3621F6ULL, 0xD9D2E830CEF2FCE9ULL, 0x9ED9245D332A546BULL, 
            0x447F364DC63B6CFDULL, 0xA082CC2F648D18BDULL, 0xBC38CA8DB923BDF5ULL, 0xA0A82299CA69D4CEULL, 
            0x41EB646FD8B9C56EULL, 0x5327315B788BDB72ULL, 0x455C4ADA6BA1BA3AULL, 0x41E72DB524A4D7ABULL, 
            0x1959AD18D75763F5ULL, 0x74170E68EB59F42BULL, 0xEF4A290459E8D384ULL, 0xCA4522FD687DD8D5ULL, 
            0xB354B51B1FBCEEE1ULL, 0xD44EEAEF4839A8EDULL, 0x9F61BE2FA9D6E865ULL, 0x0785D4F103CF0BF9ULL
        },
        {
            0xAAD5728FB7891C4BULL, 0x282EBE5F7A9137B9ULL, 0x96DECF66F35D67FFULL, 0x68A56121E133A92AULL, 
            0x8C73586C4C68569DULL, 0xEF4D07E03CC22A51ULL, 0x746569F14F2BFE6AULL, 0x3C2579BE7F099504ULL, 
            0xE82176F42AB80E75ULL, 0xAFAD5848AFBDAC1AULL, 0x12B18DB342EEB32DULL, 0x49993C6350F1D00FULL, 
            0xF511599E5D7C8825ULL, 0x4C323CCB1F10EAB5ULL, 0x38E762CB9A4A6C9CULL, 0x1BC31157C3FC66D0ULL, 
            0x6A0668F2731909E7ULL, 0xC295A7D79B950BA1ULL, 0x7159C75F5759F7B9ULL, 0xAF4349AEF65BFC5AULL, 
            0xC686A0DC02EAE05AULL, 0xC3763B099FA7CB2CULL, 0x1B75E416CC51CE52ULL, 0xD7343B82847CB3D7ULL, 
            0x35D3A24F0BE50D4CULL, 0x34877673295115B2ULL, 0x712D127D21A254E5ULL, 0x798504F48FB102A7ULL, 
            0xB0B367F486943956ULL, 0xC43248129D958643ULL, 0x5F1344AF99ED8050ULL, 0x60A215FA9FE1AB63ULL
        },
        {
            0x5093B4DB1778C4DAULL, 0xCC6F8171A1B97B66ULL, 0x5498811A51401493ULL, 0x1F5A001EDAB99336ULL, 
            0x555CD514C78DBAADULL, 0x047616738063FCB4ULL, 0x89F7F027AEC29F48ULL, 0x67D91CA62383C65FULL, 
            0x815C23319D613160ULL, 0x2FC9D564774EF8EBULL, 0xB6A552B44ABFBAD6ULL, 0x1969B9956C7001D9ULL, 
            0x2D13ACEA8D6BD6DFULL, 0x9F593E59CF848B2BULL, 0x2B86F1B8F8722473ULL, 0x92EA3F64C1510748ULL, 
            0xF6C6E80EBBD5E959ULL, 0xBBECFC6F5B0A4395ULL, 0x123FB65F05893972ULL, 0x65C077116D3EFCD1ULL, 
            0x3CBB82915C7AC724ULL, 0xC26E3F066B9FDF0AULL, 0x8B2F50950D6493E4ULL, 0xDEFBD13BD7D7E137ULL, 
            0xFFFB813DB5A8D944ULL, 0x6461594CA5601CF6ULL, 0x7558D5A23683E4BBULL, 0xB8268C39D8E3ED0BULL, 
            0xF00898D9EDFF4367ULL, 0xC7107D77B1ABE87EULL, 0x3CA3EE7DC238F360ULL, 0x7A64EB492741E336ULL
        },
        {
            0x10C71912AE0ACE7CULL, 0x7895F34031C9414FULL, 0x2596337568034E1BULL, 0xC20E727C9F8D9FC6ULL, 
            0x6C745A372AA7B11FULL, 0x29A790907B21FDE8ULL, 0x1F046B5E206EF41AULL, 0x41C6EE5C6B17FC51ULL, 
            0xFA84F1D28A758F3AULL, 0x362879E6432B8B1EULL, 0x1497461E3F9FF2C2ULL, 0x7F60009163E27D62ULL, 
            0x2164D1C134FA4A27ULL, 0x0942FD52FAE414BBULL, 0x1CBC8E0409E4B347ULL, 0xC90FB5C71D33F6E3ULL, 
            0xC0347DAB7DAB7C30ULL, 0xBCFF5758D1E4A7B0ULL, 0x1C41D3DE405704F7ULL, 0x4F94A5F7F5DB564CULL, 
            0x871E4B1C291FDBC1ULL, 0x47E43A836864C879ULL, 0x1C74541D2E29EB03ULL, 0xA69D657CC7819C49ULL, 
            0x5330CC7BA160B1B0ULL, 0x23EFB42DF65FD10AULL, 0xD8F8CBC066FEBE39ULL, 0x4F8E830D84DD42FFULL, 
            0x51D9BD5997E9D5A6ULL, 0xDA3B84ED5C55873CULL, 0x3B1537043CF057CDULL, 0x76B3BAC4085B85A7ULL
        }
    },
    {
        {
            0x6C2D30A62858E621ULL, 0x2F35E89C9B897B8CULL, 0x8103AF5E40B615B1ULL, 0x7CC76CA60A7DD414ULL, 
            0x7D5FD2A8D4DAFD9CULL, 0x16692DA9180ABC71ULL, 0x2EB99E0D2FEBEABAULL, 0xDBD5CB5D285C5A8AULL, 
            0x483074090195F9C8ULL, 0x575606011F1B4B6DULL, 0xEE572E60EDBF858FULL, 0x2F50157635503649ULL, 
            0x57F9A608058F05FBULL, 0xAD399294D0C68A3CULL, 0xFB473168A0C1A844ULL, 0x7392A2E3B3A625B9ULL, 
            0xAE911BE5775041F8ULL, 0x055FD8016749F9CCULL, 0x28C8397447701E4CULL, 0xF826480ECC0FAD40ULL, 
            0x4E5F3BC2D6E2A147ULL, 0x01B19A2C5BA0B080ULL, 0x219BA98DADE1A407ULL, 0x97EC5A07D812E477ULL, 
            0x013F90C2F1FF4789ULL, 0xD1BBD32EC607C48CULL, 0x0CDD7C3EF1D1FAEEULL, 0x7D99B80EF4EE3437ULL, 
            0xF1A1BCF5E5276FD1ULL, 0xCAAD843E93175451ULL, 0x0D544EE052B4D883ULL, 0x04BF766858A1FDB3ULL
        },
        {
            0xD1B112B1212ECCC8ULL, 0xC7827B5ADE3AED14ULL, 0xF53FA14EB56897ECULL, 0x9AC6B637045F84B2ULL, 
            0x0C73A19869540F93ULL, 0x0423C2FE560DD296ULL, 0xBB4D52F8192AD108ULL, 0x815DD89D5DE4A4D1ULL, 
            0xBF759A3C95BE3372ULL, 0x9276E5FB9662AB0AULL, 0x0D99B15CABCF7D6DULL, 0x80E6F55BEEC797E6ULL, 
            0xA855C12FDFACA44BULL, 0x19E828A672E49BEEULL, 0xE3F80299EB4E4154ULL, 0x30146C9E74B42968ULL, 
            0x4C2F3F79261AB698ULL, 0x24DD7D244D972808ULL, 0x46D727C83B11FC0BULL, 0x2FB3B6F92D596D00ULL, 
            0x138CB047A2CFA092ULL, 0x1CBBF65334EDA781ULL, 0xC5CEC3B64C1DCECCULL, 0x63EC062ED8A82BE3ULL, 
            0x3CCDEC1477AF9932ULL, 0xEAC1EAA6929D6876ULL, 0xAB346F133184D9C0ULL, 0x6A43583DB23C9484ULL, 
            0x14C78116E97004E6ULL, 0x4A5AE2B4C3BF2DCDULL, 0xF598B3D8ED01B5BFULL, 0x7A93B06A049D72A2ULL
        },
        {
            0xE4F72A5E6D5C84ACULL, 0x517CF8443933BB6DULL, 0xEEF09585A747479FULL, 0x3DD946E9866BA02BULL, 
            0xA2CA3769A28FF377ULL, 0xCCE92417B7012376ULL, 0x05903208BFF19D23ULL, 0xD6D86DCC1FF957B3ULL, 
            0xCC985A0F7919DF23ULL, 0x0DDC643A815C4E1AULL, 0xD6DC36E26000569AULL, 0xDE29083697D994F1ULL, 
            0xD7A6A204C95DE838ULL, 0x1D29ADB59C0CAE66ULL, 0x378E3D19136DA5ABULL, 0x0D6E24B79CEDDB8BULL, 
            0xBC8FC863E05101C5ULL, 0x2AF0AAF8366FAEDEULL, 0xF64F1E7954A6A377ULL, 0x59558B0F6549D6F1ULL, 
            0xEFB0FB16882F36F1ULL, 0x60891097F1566708ULL, 0x879E248D83918B3AULL, 0x2A95A70A840870DEULL, 
            0xFB670B48FCFD3D8CULL, 0xD770053C7C831CE0ULL, 0x29B6EE4340BAB09AULL, 0xD234B80339514F17ULL, 
            0x3F5DFB87763FA975ULL, 0xB7A1D829ED9A3BBEULL, 0x44ACA1F015A42CBFULL, 0xA2D8C74556D82541ULL
        },
        {
            0xE521A7BA98505143ULL, 0x45D49F7C5C0FD80BULL, 0x57D86AAD109BF662ULL, 0xDA743D6E69A4BECAULL, 
            0xBA56047EE0DB1BF1ULL, 0xF78A1F3B11AE01D7ULL, 0x970A001DB670C44DULL, 0xB5975C630F9A65AEULL, 
            0x8606084301AC0BD0ULL, 0xFF5B546E8EC89397ULL, 0x2A42D22994652734ULL, 0x9915C3DC85AE7FB3ULL, 
            0x9E286E9D2700F391ULL, 0x69B90256D732F054ULL, 0x8C4844F23BDA14C2ULL, 0x9A0261A9179154FBULL, 
            0x66953E717089F0A1ULL, 0xE9854B2BE10FFB04ULL, 0xCA38CC3B2E57BF21ULL, 0x83624FE1BD3F8623ULL, 
            0x9C1142A7C44781C5ULL, 0xA856A86B678AE82DULL, 0xF908A6FB33744E9EULL, 0xFE658FA67F8DD7B3ULL, 
            0x230AD5756556BBFFULL, 0x47B0E35DDFD66C9AULL, 0x352A9D6B30577DF9ULL, 0xF0D4A42F71721F18ULL, 
            0x463DEC6D0AA11C2DULL, 0x08B86B3705C174B9ULL, 0xD3DDFEAE4B941EA4ULL, 0xC7AF20F8950CDCACULL
        },
        {
            0xDC9AE17F9677BF87ULL, 0xDA20C645BE8B600DULL, 0x2331B48B1B1D56A2ULL, 0x6B6DCA4FF48258AAULL, 
            0xF12ABBF6060271DEULL, 0x0BDF046CCD41C6D7ULL, 0x9279DFBBBE9E16FBULL, 0xDEFE81F4E5583E9DULL, 
            0x2F5B235746D17ACFULL, 0x5D5781CC952ABBEAULL, 0xB3921BE170EF58CDULL, 0x9BEF53F2A13C2EEEULL, 
            0x58E50500D412178BULL, 0xBA5349BA37A8908EULL, 0xBBFD2F5CF4FE1046ULL, 0x579D0D8E821FC231ULL, 
            0x625C2B1C34079587ULL, 0x296050549B0B5B9CULL, 0x02C1F5F95674DADBULL, 0x88E4A397618D8C3BULL, 
            0x73ECBE80780D2B40ULL, 0x10B149826A6BFD46ULL, 0xB00E6C0FB70705C3ULL, 0xB888F4F4D2A91A88ULL, 
            0x3FADC41E83D1E3ECULL, 0x8E1010C48CC90363ULL, 0xF7300A9D4DB107B4ULL, 0xCBC5AA620988FFE7ULL, 
            0x8EFD8636FEF2A173ULL, 0x1FAADB187FA065ACULL, 0x1DFBF6B7FCF7D7E9ULL, 0x43242263CA2EB632ULL
        },
        {
            0x6AE38034276032A4ULL, 0x8BCEF8CA70F34220ULL, 0x79B2DBBD1DCC3B75ULL, 0x1534F3338285C1E3ULL, 
            0xA894ED27320C01B9ULL, 0xB3B810AE8EF3218BULL, 0xBB7F3AF366A20232ULL, 0xB396CC8DF109C9B2ULL, 
            0xF473B48E5537CDA4ULL, 0x22118D458550A67FULL, 0x6F8AB1479B15E7A2ULL, 0x0097AF230E50FF07ULL, 
            0x4D4E41B680FDBB0AULL, 0xEC9ECCAA1810B9CCULL, 0x3540AE982A79025EULL, 0x509BCE87D933A1BEULL, 
            0xE61F918568ADD54EULL, 0x2E16D16832750D7AULL, 0x5BA3A904748FEB35ULL, 0xB24799BB5089E6DFULL, 
            0xA3210CF045D2826CULL, 0x75251A2EA6F27BE6ULL, 0x3FC82398C2160B7EULL, 0x1007F8A45AA16802ULL, 
            0x166BB035C6B4D9ABULL, 0xF26760EBC5D8E560ULL, 0xBDDB10D67CCB3251ULL, 0xEAFEE4E545B8052AULL, 
            0x20686607852C8EC8ULL, 0x4E9CD62F619189C9ULL, 0x4E2819DD538DCEE3ULL, 0xCADF61B3D2A628FEULL
        }
    },
    {
        {
            0x6923BA854C96AA06ULL, 0xA402AA61C2696A18ULL, 0xBA3310C94C40C24DULL, 0xBCA59F1A208A8CDDULL, 
            0x017601E0793FE429ULL, 0x9829BBA9A25EC5D1ULL, 0x3663A068D5B2F4FDULL, 0x92B061B58DF46E9EULL, 
            0x45288031B031D4B1ULL, 0xEC4C9E0521E14A33ULL, 0x0573F4FCC21F0D9FULL, 0xE9C1E70CCB93B196ULL, 
            0x3469AB160258319EULL, 0x0E1D036A8569DA8CULL, 0xE9EACD69665F5530ULL, 0x3642F083DF9C4014ULL, 
            0xC23331103583AAC6ULL, 0xD80A6D51B299C096ULL, 0x20E39DE3BB6BE357ULL, 0xF54CFEC1913175E1ULL, 
            0x3F58BEE46C1F844BULL, 0x16A0660EC5A7DFF6ULL, 0x360842EF22812F1AULL, 0xFB1094DC32150F59ULL, 
            0x7E931C36F4620EA6ULL, 0x0C9B50928E990F54ULL, 0x45132AA767F77908ULL, 0x7BC6C213E2BE7459ULL, 
            0x381EB2C0FBE97E28ULL, 0xFB8EA648FB83FE4DULL, 0x35045E7E6FF2BFC7ULL, 0x70F57D39DE2F173EULL
        },
        {
            0x34C68FBE310EBE58ULL, 0x298D9DC65F2481FCULL, 0xB2910628716A7DF8ULL, 0x3D7C388F1EF69F6CULL, 
            0xE0D5681A4B733E5CULL, 0x1B7754E28B55F1F1ULL, 0xC0A6F7BFB9FB49DEULL, 0x725CA63387CE60D3ULL, 
            0xC27FE0B30796DACAULL, 0x885D488C9AFDE619ULL, 0x5C01DC7905E74484ULL, 0xC6DF1F67A83729F2ULL, 
            0xACE238A34E36EB58ULL, 0xF668DEF9799AC0F1ULL, 0x7E1B155D8E1EDCDDULL, 0xFAD29BEACEBA04A2ULL, 
            0x1784DDDF4B79381BULL, 0x08CE497774147336ULL, 0xD6C4DC2F1A68543DULL, 0xFA4D3B71F9BF5970ULL, 
            0x04F1078DFB20B6AAULL, 0x8708099AD7839F64ULL, 0x900BF3B13236DB1FULL, 0x7F9A0DAE46F1BF9DULL, 
            0x0F7D584FC1834E53ULL, 0x0576FFE95243606DULL, 0x23E2B63F62D5D3FBULL, 0x259FDDAEAED7595FULL, 
            0xCEBAAF292B86725AULL, 0xA9366B3AC4C6F5B1ULL, 0x5E4AC29EAD24E40CULL, 0x2D8CACB2BEBEAE52ULL
        },
        {
            0xB5C90A9835DB1CF8ULL, 0x641A7A61212A8D4AULL, 0xF6C4DD5DC3C336ADULL, 0x3ACE4F248836E292ULL, 
            0x4B7B85DCD2B0816DULL, 0xCED8E2AAE9D3D9BAULL, 0xE80007468325D552ULL, 0x12A35CEFE5A5CBACULL, 
            0x835EF54B209815DAULL, 0x206C336B1BE6B0E3ULL, 0xB43E1817FE998B91ULL, 0x5597AEAFEF99B73CULL, 
            0xECD75160A9497C49ULL, 0x2EB6D6E000403EA9ULL, 0xD027F5C12C6C2B03ULL, 0xCE90CF7D348E4007ULL, 
            0xEED4D233D9EEBB0BULL, 0xCB63E351222CE446ULL, 0x2C897114C840758AULL, 0xE4E7EB4DD5115A88ULL, 
            0xD7BD67DEE7C389EDULL, 0x99AA82B11AFC0A07ULL, 0x7DB611D47EA01041ULL, 0x5CED18D9CA7B5F22ULL, 
            0x0B825F530B322A38ULL, 0x4588A19CFD9CCA91ULL, 0x338039A4925BDD8DULL, 0x9287094630B08F1FULL, 
            0x25388689DA9D0615ULL, 0x64BDB17860C4C828ULL, 0x29D8B9C30B11D35AULL, 0xC4C0DE0FF095433BULL
        },
        {
            0x80F9E5501CA2640BULL, 0xEA040D08CE7F6FB3ULL, 0x52933670A73B3241ULL, 0xD8503107FAA97E56ULL, 
            0xF3542BDDDF6CCA11ULL, 0xFECFD5170F13AAF4ULL, 0xF3A86AF76413DAA0ULL, 0x9D8E360B4F9F03F4ULL, 
            0xDC4E34281B360EB7ULL, 0x67C3E6A880982DC0ULL, 0x7FBF31A6184B6A1FULL, 0xEB65E2AA2E47D2B9ULL, 
            0xD8A4A7A1C75C57FCULL, 0x33190DFD746A7BA8ULL, 0x2A646F69006C0787ULL, 0x9AF8C80ED84020B8ULL, 
            0x81AFACFC31E419CAULL, 0x5E927D00A4F7192EULL, 0x91971A3A85A84467ULL, 0x3769EDAB46535163ULL, 
            0xBC1A09ED75538202ULL, 0xA8187D2B1DCD2A3DULL, 0x143363F12701266FULL, 0x08322B8E5CF5C7D4ULL, 
            0xCF4112F9BDA90746ULL, 0x4E2AC07A0880C0ACULL, 0x0A1B56D958F0DFC9ULL, 0xAE822DC0CDC217C6ULL, 
            0x743F0BB5ABB76184ULL, 0xE32F3CBFEDBE7079ULL, 0xE806A05BA2172254ULL, 0x9B10D2245D542A2DULL
        },
        {
            0x81A9EB27A781B608ULL, 0xC30CEBBB3A5D105DULL, 0xDAE19F1465EE1C6EULL, 0xA66E8C62116D317CULL, 
            0x8900E4EE5F3227FAULL, 0x51CAD153E4D75FE5ULL, 0xF1FFEE6BF107B9A9ULL, 0xB53FB36FAEE1313BULL, 
            0xD1E5876420BB662EULL, 0x7C4C5FDE4D04C555ULL, 0x1AA345368437F4ADULL, 0x69B6EA6B3C61D1F1ULL, 
            0xE0D00200918B5632ULL, 0x8367C01F0C533DE7ULL, 0xB76F58E05DE4C805ULL, 0x966EDE311B0E4D63ULL, 
            0xCF1FA0692BA4C60EULL, 0xA92C67AF1053B924ULL, 0xDE22757284D2C4FFULL, 0x149D9427FB52E5A9ULL, 
            0x5E741330CED619CDULL, 0x1BFF1C4E488C339CULL, 0x54BC0DF31D0A13AEULL, 0xE4249699890EF7DCULL, 
            0xC65AD2A308EC6E0DULL, 0x256FF697899B5B2AULL, 0xA55DC3CFF562BEDAULL, 0xA050B564BB63B528ULL, 
            0xEF87B5551487E630ULL, 0x6C9126E6A8BDFF96ULL, 0xBB270976AC52D326ULL, 0xCD7C5DADBE8989E0ULL
        },
        {
            0xEE2A046EF2E37F8AULL, 0x20B14FEE0D17035FULL, 0xC2DB36D6A36AE823ULL, 0x6FAA6397376EA78DULL, 
            0x221A448A736C443EULL, 0xBEC1337916830FC1ULL, 0x608CA81E86F86374ULL, 0x6C3D11B91D7004E3ULL, 
            0x50DB86BCF69CA568ULL, 0x2DCD399BB5223842ULL, 0xBE37B0294E01D2B8ULL, 0x899A4B348E165F50ULL, 
            0x6DB7C2AE3D6B53F9ULL, 0x63E5431BEF2DC937ULL, 0xCE3B82305DBA3B74ULL, 0x3E8DBA29E15C6466ULL, 
            0x93DE7D3AD3EEC9B1ULL, 0x379B58B7D455A028ULL, 0x5D3FDBE2D707C56FULL, 0x13951A2A0EE8D288ULL, 
            0x9CC4910415CDCFABULL, 0x4F835F98506CB011ULL, 0xC4825BB8E8D0F273ULL, 0x3D912819BDFC5D37ULL, 
            0x395D6EAE3B937CB1ULL, 0xF2541CED656AB06AULL, 0x3BF9B6A675404CC8ULL, 0x81949A1E73B0BF0EULL, 
            0xF5A258A293288F4CULL, 0x6B9439DFE3276C26ULL, 0x23686DBCF719459FULL, 0xFF0800C075DBDA96ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseEConstants = {
    0x91AD5F450479CCE6ULL,
    0x76D040E84DDF80B9ULL,
    0x65D9A3044D8E8CA6ULL,
    0x91AD5F450479CCE6ULL,
    0x76D040E84DDF80B9ULL,
    0x65D9A3044D8E8CA6ULL,
    0x6E45D6F7B5B9918FULL,
    0xB088287184F8ADB9ULL,
    0x6D,
    0x1E,
    0xBB,
    0xA6,
    0xC3,
    0x3A,
    0xCE,
    0x81
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseFSalts = {
    {
        {
            0x741555527F859699ULL, 0xC1EAD08AE83979C5ULL, 0x2271FD0B9BEB73B2ULL, 0xBD1F7483174D6A52ULL, 
            0x284639E7DD7664DEULL, 0x6D972A9CCD845235ULL, 0x08F2E79281EDCB00ULL, 0xF5E244013CD67E90ULL, 
            0xEEE5C0EE48E56F3DULL, 0xD51898F1ACC54CF4ULL, 0x8C8531668AFA6EDAULL, 0x48D152529E52BD5CULL, 
            0x2581BA27EF6B1CFEULL, 0xE4148E4B14F4BC61ULL, 0x0C7BAA8B9A7CB552ULL, 0x638A35A2E66C937EULL, 
            0x7C842B6D465E7A5EULL, 0x7A72549F6AFD0C15ULL, 0xD739D6A13825BB4DULL, 0x9BF2B3324ED5BAEBULL, 
            0xDBE9D7DC50099F8AULL, 0x7C70876AB88A727DULL, 0x7BD1A0EC5669DF88ULL, 0xF862871C9E955E24ULL, 
            0x1F7E0826E498D7C4ULL, 0x3CCE7A9DE4854665ULL, 0xDCEBD4D29F24D4B0ULL, 0x9B3E574487A7F4C3ULL, 
            0x42D8FC2E22B712B5ULL, 0x5E9F1AEDE1D31CA9ULL, 0x8643BBCA677F60F6ULL, 0xD13EE74232DE02EBULL
        },
        {
            0xA8E6665782FFB249ULL, 0xD250411813738043ULL, 0x9C0ACB5E5C506119ULL, 0x6D11EDBE8C2EF281ULL, 
            0x5484CD5F2DD68A3EULL, 0x73D5FF5B45B69AA8ULL, 0x1FAE9ED63DAD3D3BULL, 0xBEF0EC3D589EA77DULL, 
            0x17FB52BE189CF93DULL, 0x7B8DB1C47EE7284AULL, 0x7495F28FDC9F8478ULL, 0xDF771CE0D2E52678ULL, 
            0xBC74BE3E60F8AE0DULL, 0x4FFAADCA6900DEDEULL, 0x8A8EE80A641BE0A5ULL, 0xB2C7DD0A01909069ULL, 
            0xAD12E30F795A2EC2ULL, 0x08E3034701F61CBCULL, 0xC2EFC45A6603766CULL, 0x6C1C711890CA9BEFULL, 
            0x77B8325E183B113AULL, 0x9269CFE278A0F39BULL, 0xFFABF953139033CFULL, 0x7CBAE1D3347A9A8BULL, 
            0x491CB312B460E47BULL, 0xCCE8FB197DF2D1E3ULL, 0x4A4EF06CD7766DD2ULL, 0x955779F454DF4B4BULL, 
            0x0FD496F0F97C9541ULL, 0xA3F12AEB46CC1986ULL, 0x74D34520E5C12B24ULL, 0x065BD1333D3E8443ULL
        },
        {
            0xE891FC84E96D4E63ULL, 0x6AD3797F46DBBDCFULL, 0xC6EFDBD001F58678ULL, 0x727B2CE053B8DCEDULL, 
            0x95FD9D011945E083ULL, 0xA8E00D73A4AC725BULL, 0x5E6FB72D5CBAD741ULL, 0x9BA67C32FB6F4D09ULL, 
            0xE8B3BE4873218960ULL, 0xBC107EEBBCE3A36FULL, 0xEA79B784A4EA0FE9ULL, 0x94CBF1177A7C6E43ULL, 
            0x10902D0A2ED12C57ULL, 0x2FFD12CFA050B821ULL, 0xD9F4505EAB745409ULL, 0x402DB176ABD2980DULL, 
            0xCC42412484EACBF0ULL, 0x0E872277597EA824ULL, 0xDEB0A55A28F9CAC6ULL, 0xB28ED1A0D1C831ADULL, 
            0xCDE02599AE1A9D4DULL, 0xD455D4EF30B13C54ULL, 0x7520CD04CA9C1504ULL, 0x805F3D23AC711034ULL, 
            0x207BB1DD60E46D88ULL, 0x9EC994A1E954EBEAULL, 0x93BA23ABEEEE05E0ULL, 0x9C8A88C5960D015CULL, 
            0x3061505BB79BD35AULL, 0xFB3428371144020EULL, 0xBB0C2B72C8CDBDEDULL, 0x3AE9673F529DB627ULL
        },
        {
            0xABF6DC14FC86C818ULL, 0x2E940074A4BFE55EULL, 0xD13ECC8948FD55FBULL, 0x1366F175569F55F9ULL, 
            0x29CB0C9D8878A2E6ULL, 0xFB9E1986D0DECC77ULL, 0x82764BE6967475C1ULL, 0x16CD641D682D9D25ULL, 
            0x60C975DC0083BD12ULL, 0x2229B4E2B43DD17BULL, 0x70B4F45718448B8EULL, 0x931AE415C0AE9CAAULL, 
            0x5B9B544E9288AE4BULL, 0x9BE6C9FA5271534CULL, 0x69F96AF7BE65009CULL, 0x3D15970BD61FDE27ULL, 
            0xFB921045D840BEABULL, 0x8DA5727F52D1B117ULL, 0x34C18C50ECD1B72EULL, 0x4B7315B6EE022BB9ULL, 
            0x0889E643A346F7E5ULL, 0xA2EF3A52E4867E47ULL, 0xBCA8FA6B52BF98D8ULL, 0xD72BE56913952314ULL, 
            0x687F879E06F481F0ULL, 0x2AE5E1DDBCF45731ULL, 0x2731062EBAB785B8ULL, 0x945D6F7E1259CC48ULL, 
            0xE5EAEC3F58A15810ULL, 0x6010DBA2209B2F37ULL, 0x7CD6C0CC1A6B94D5ULL, 0x207E77901BF41F12ULL
        },
        {
            0x55B5A8A3B0A605F6ULL, 0xE7B81B0C54566A90ULL, 0x9BB51A8BCF1357E5ULL, 0x8977176DB7989FE2ULL, 
            0xEB9F8D5FD604152DULL, 0x12E1E167C2C1BB8CULL, 0xA56B61F4E8A6ADA9ULL, 0x0AC71A35645C5FCFULL, 
            0x3E9AE95957679A53ULL, 0xDF5BD1711CAF4609ULL, 0x0C3D0A1320313AD6ULL, 0xA55E3777F68E1388ULL, 
            0xB5B828F3C0DE7D5CULL, 0x4D98F8CF06194DA0ULL, 0x04795ED1C0F4BA27ULL, 0xA9A83B456B17E74AULL, 
            0xB6A3B2F29FCB3AB4ULL, 0x97080FE806D38EEDULL, 0x1A8EDBEF72099433ULL, 0x38E1E949C75C8F71ULL, 
            0xF18F947693BE8814ULL, 0x757287B601327EB0ULL, 0x69B0DD6D9AD33BD5ULL, 0xBB85E884EF6801C9ULL, 
            0x379DE107A46BF3BBULL, 0xBBEDF3599A33505EULL, 0x6156CC42B545ED4CULL, 0xEB2F2CD99B2B29ADULL, 
            0x1585BF3B88AEE454ULL, 0x8802BCA8A9DC1ED3ULL, 0x436209932C5A86F6ULL, 0xAC04BF41DA36AE08ULL
        },
        {
            0x8E81F43360BC5C4FULL, 0xAA41B487C0D97C88ULL, 0x8D3013FA6E74C086ULL, 0x895C917F1A3DBC95ULL, 
            0x36EA914D7A2C112AULL, 0xA2608DBF2B974E36ULL, 0x717A806D00DCB322ULL, 0x69B3E9AA0BC3F1B9ULL, 
            0x5DD3648269A58A96ULL, 0xF9646D7F582816EAULL, 0xC8A467B6648BC466ULL, 0x43E924BA7BAE7FC2ULL, 
            0x6F72B4F4C3BC0FC1ULL, 0x4FD3DFED542DCE66ULL, 0x85428E406721AF9FULL, 0x4A8FF81B867440F4ULL, 
            0x29C3147D4A2DC6C3ULL, 0xF2DAC6CFCB207E09ULL, 0xE5E61E55B74DD11DULL, 0xF39DB006096BDE2BULL, 
            0xD49497145AD3FB7AULL, 0x2E69B1A94A56DFCCULL, 0x10493FE5B21E7776ULL, 0x959117A346713BE9ULL, 
            0xD8A9FA7B8AA0019DULL, 0x7A4D757610BD2650ULL, 0xA272F99C99F77EE9ULL, 0xB63C16A0F814EDA4ULL, 
            0x916CDE59BFC33E05ULL, 0x55544350B3B617A8ULL, 0x6E614A80E46AE513ULL, 0x33F059C0D96A17C4ULL
        }
    },
    {
        {
            0x5C0E2D48A98A6853ULL, 0x3F6ACA82949403ABULL, 0x85AFC0FA937DDBB8ULL, 0x9B2DC1FEFA1FE80FULL, 
            0x15B05176CCE53BBDULL, 0x24B548AD580CCF72ULL, 0xBF0E5026C17D3525ULL, 0xF36E5515C3051FD8ULL, 
            0x481C05A0057B294FULL, 0x0A359601E8544988ULL, 0x7F45957372810783ULL, 0x1591715EDE4B5D6EULL, 
            0x04CD1D31034723F5ULL, 0xF65E7406224FEFE1ULL, 0x94B818CB61432AA8ULL, 0x9115CA265FD9D735ULL, 
            0xB7809912E10C6044ULL, 0xB31937054E664454ULL, 0xD2434C623CA0C40AULL, 0x289F902B2A095651ULL, 
            0x8278B03E56DA57C4ULL, 0xA948E3F79FE98CBEULL, 0xFE8FF5C50A9F4C12ULL, 0xDB0A510F441A661AULL, 
            0xEE8AD8A135C1C37BULL, 0xA15DF17470B84E0AULL, 0xBC9966FA4DD56EA7ULL, 0x03D71DB72D1E82C5ULL, 
            0x149494F36E0992C7ULL, 0xCB6922734098BC3EULL, 0xBB22C0E55BDE2CB3ULL, 0x08CF9D636A9995ECULL
        },
        {
            0x1DD3838E4F00838CULL, 0xE847B814A158DBC2ULL, 0xF86AC6EF32BE5D82ULL, 0x408CE9B2100201EDULL, 
            0xE261F091FFF3E104ULL, 0x31628037E95EAD2CULL, 0x640CD201FBB422BEULL, 0xAE462C6025E4364CULL, 
            0xB56C2760535C72D1ULL, 0x77F435745CB500D5ULL, 0xD13A09C21836962FULL, 0x6AA158342C5A59E9ULL, 
            0x934B95869DAD87F4ULL, 0x6BA5592582BF8793ULL, 0xBA0FDF92DC0666FDULL, 0x463798D289BC259CULL, 
            0x53DB0874911DAB22ULL, 0x9CC277338DC18D67ULL, 0x2B575766E1949F19ULL, 0x407E41935C60928CULL, 
            0x0722010125CB112AULL, 0x714C150E7F01DB65ULL, 0x6C4BE4416700162BULL, 0x5A57755EB3288125ULL, 
            0xE021BD16A25F8670ULL, 0x07CF1166D1A6A39AULL, 0x1AB99D154B9D36FBULL, 0x3313AB73AD5CE12BULL, 
            0xCED3318F2B6C08C2ULL, 0x3310692D5FF3835DULL, 0x0C0B1F5BC812CC39ULL, 0x1C47098F1BC274B5ULL
        },
        {
            0x979C288803910341ULL, 0xDD2EFB7CAAADF374ULL, 0x8F9DB984FE7BE801ULL, 0x232E2CF3C4AFE23AULL, 
            0x89CFDABFF4DF1ECAULL, 0xA37E50E1AFA17B3CULL, 0x605E182B0EF7B3F4ULL, 0x13DDD63FB13DBD60ULL, 
            0xB803D333FEEF7349ULL, 0x3884C0CA7D3D4E1DULL, 0xAA60B686A7EE807EULL, 0x7BF5E0D56B008F54ULL, 
            0x0E8B74D9E55A4BDFULL, 0x236B250FB770DF59ULL, 0x27F6FDC6D5061754ULL, 0xDF4C9217D05B8F29ULL, 
            0x2CA45E1E783BA3E0ULL, 0x5918BF40558D9297ULL, 0xECFD9CC42BC73842ULL, 0x2C561AD97B7B9AC4ULL, 
            0xCBB11773F73CAF97ULL, 0x1F4682537EADF6C7ULL, 0xE7B13A36126227CBULL, 0xF32895C7735C4C5BULL, 
            0x9D7073028E98F4B6ULL, 0xCD17894384A79C80ULL, 0x3EF41AD2CAD05CCDULL, 0xC1495E42BF962B6BULL, 
            0xB44173DB046D66B7ULL, 0x020640807471221CULL, 0xA458B2A312C7E2B8ULL, 0xBA57FFD5B768F104ULL
        },
        {
            0x6FFE7210EC60D77CULL, 0x2588806295B542DEULL, 0xD9081DAFD567CBE7ULL, 0x3A516F6F366A7D39ULL, 
            0x223379CBAECD2FD8ULL, 0x56384DE8F2A18F23ULL, 0xF02146BBFD03034FULL, 0xC32D5885CB097CADULL, 
            0x85C3844B844B4E90ULL, 0x70F1C925EBADAE8FULL, 0xB07142B49E4DDBF9ULL, 0x4192BFC887B07577ULL, 
            0x4408AACCC4DD60E4ULL, 0x77D7598BACC00F50ULL, 0xB9AF49144706D01FULL, 0x64837D44EDBC6222ULL, 
            0x635F3180EEF0F1E5ULL, 0x7A7D92CDFC1204A0ULL, 0xD8002D46433D6A2CULL, 0xD98852E0CEA5F0CCULL, 
            0x695043CC8DF5CFECULL, 0xE9B4E98744F7718AULL, 0xDC5AC4C984F33BB1ULL, 0x6A48D4A2765926F8ULL, 
            0x078445A3BFA108F5ULL, 0x643B79D3696FC04BULL, 0x325F64A6C564AFC4ULL, 0xFE0AFEE7BA9A835BULL, 
            0x9873580A6523C883ULL, 0xF340B852A454AC10ULL, 0xB522BC951BB65B29ULL, 0xA6B7A37FAEA0879BULL
        },
        {
            0xC058F490D2D593B9ULL, 0xA34131BD4415A499ULL, 0xCD06670DB3683407ULL, 0xA9153FC727DBF424ULL, 
            0x237C739FC4C396BAULL, 0xB7CBBC4E989A0B21ULL, 0xC3F7078092A6B53DULL, 0x66A62F31D9A7BB08ULL, 
            0x84B857C573BD9335ULL, 0xF9A0AB162252D642ULL, 0x309656CB4134FF69ULL, 0x7AE5387526D629F4ULL, 
            0x95D731DA0BE96DC0ULL, 0x78DE145E96B4B529ULL, 0xF48ED1B03A23CF21ULL, 0x7E2253270A84604BULL, 
            0x50E28FF65F95E567ULL, 0x29EDB25B40F107EBULL, 0xC12CF8E8A58FE101ULL, 0x65D6A21355DE323CULL, 
            0x2063B49C530E5A44ULL, 0x8FFB54D045CC94E6ULL, 0x27A0A5367B97323DULL, 0x07F9CE51552075DEULL, 
            0x6AC26A3463FF1499ULL, 0xFE772666B2A2B2A2ULL, 0x46F691167A9F31EBULL, 0x9395EB055936E833ULL, 
            0xF8379E984D0EAAC2ULL, 0x7C924EB6D921FFF6ULL, 0x7A006C3D457F704AULL, 0x5EAD60801426CA60ULL
        },
        {
            0x292D1302F8CC3E85ULL, 0x3A1E1C6BB8B692CAULL, 0x97E5108986FEB149ULL, 0x3A35BCC49B043641ULL, 
            0xA909BFAA29430EF5ULL, 0x964D4CD00A103741ULL, 0xCAC1E8CEEAA01D4FULL, 0x70DABB8FCE1697FBULL, 
            0x8EF38BE1E9F2D7D5ULL, 0x3AA6DE8742747FD1ULL, 0xF25C9186BCCA3DC7ULL, 0xFE8D83864A99487DULL, 
            0xCD84FF8F13FB2BFAULL, 0x0603D314F5E99F68ULL, 0xFE8566448FC8DD4AULL, 0x104F727B3747B48CULL, 
            0x3F74D29820EA5228ULL, 0x6856F9D8E58BBE0FULL, 0xA83C13FA8858AF7EULL, 0xE5AD06D6A58C88B5ULL, 
            0x8613959BA874F7D2ULL, 0xE70D06A58C357A05ULL, 0x5B2928493EB4A457ULL, 0x9B8ADA9A1374577FULL, 
            0x3E27F4BAB69ADE9AULL, 0x58543B12FD5C7AFDULL, 0xCBC0B29A07647033ULL, 0xB19E6431709F69A8ULL, 
            0xC82CB2DD4F286FC7ULL, 0xAA600CA418D843DCULL, 0x4CF0C894F4D05529ULL, 0xDEEF011DBAD22A44ULL
        }
    },
    {
        {
            0xFB47BA8E4F49DB8FULL, 0x4E55D64FC9F1D24FULL, 0xF8A44DE11A86650EULL, 0x3B080A63F66933A9ULL, 
            0x5FF51E9E6B275F01ULL, 0xB9DEF0A1033B9161ULL, 0x17C91FA53F361BAAULL, 0xD4C607481809A26AULL, 
            0xF31145F2F0A68088ULL, 0x2E769BCE8BD67871ULL, 0x82D3B1C36FEDFAD3ULL, 0xC6711BC8FE66A97AULL, 
            0x0BCBA113FFF20DEBULL, 0x414484AE825318CAULL, 0xBFC92EC77B6E1CF0ULL, 0xB673F155CE07853DULL, 
            0x02C6EEC15CEB3BC2ULL, 0x979455A497CB225CULL, 0x0B6CFB603EEF14BBULL, 0x78ABD5204E417FE1ULL, 
            0x6E88A68F32B1B612ULL, 0x57D664D9F8532130ULL, 0xC433D66E4559D00EULL, 0xAADE7FD43DA125FEULL, 
            0xC5B36A606C9A115FULL, 0x58A7077CCC24547AULL, 0x8EE653A839B7F920ULL, 0xB0020B964B7242BAULL, 
            0xF81E3D937A7E1BF6ULL, 0xA27359B03F02BCE6ULL, 0x6587BEC939568767ULL, 0xDB5191CA0387E73AULL
        },
        {
            0x68BC0A7318B86354ULL, 0xCFBB3E134F579FFCULL, 0x48CFF18A0F72D598ULL, 0xCF7F9A02758B5313ULL, 
            0xACA5C5CAFB0D2D6CULL, 0x3F1BC88BD591A476ULL, 0x43F1294740912019ULL, 0x73A2F963F77F407FULL, 
            0xCEA701632C2FE602ULL, 0xB9D777C66F842302ULL, 0x6611E3083508710AULL, 0x8342171975D130D7ULL, 
            0xAD31B3C107642AE6ULL, 0xF17987A07CD9FACBULL, 0x27A3AEC50D4D89CCULL, 0xB84CB5B152714E31ULL, 
            0x6AFCB3C3794E5FB2ULL, 0x77B6859344C00407ULL, 0x1C137F497289BB8DULL, 0x9BC6DDAC6D447FD4ULL, 
            0x7A15641581D71FC0ULL, 0x37E55C7937BF901EULL, 0xEFF55DA8236AC9F6ULL, 0x1B59A1037DF8B711ULL, 
            0x9A04B207AC86669DULL, 0xAEBE341C7DD9988BULL, 0x095604DB28A7BEC8ULL, 0x544C25352B8AC175ULL, 
            0xCD1DA270B41A1413ULL, 0x664E55627FD6CE56ULL, 0xB9A7096C750E31ACULL, 0xCFF8C2FF1D901CE8ULL
        },
        {
            0x2A8F5B4E4C8E7FAEULL, 0xE9AFD60DB78CDB4EULL, 0xD804829361EDA32BULL, 0x39F7B702D44B2E00ULL, 
            0x52EE3F88E77F333CULL, 0xDE39F6DB3DF8C86CULL, 0x0E5A4049487A7153ULL, 0xD316D68987969619ULL, 
            0x68A91D982C72D17AULL, 0x1444F67213824946ULL, 0xEA89E05B091C8E87ULL, 0x60C2670D8C0E5465ULL, 
            0x56CE244CEEC591A4ULL, 0x2D2EA6238938F35CULL, 0xFC1B6E243BD4A657ULL, 0x2D1B9D6E9E4506E9ULL, 
            0x7C18F84F62B7A300ULL, 0x8176F655AB96C37CULL, 0x0DD300C621591281ULL, 0x6F12D82C6325529FULL, 
            0x85773061345156B0ULL, 0x556D4321821A0D97ULL, 0x52FA813646EABD6EULL, 0x6C1B904D35B16675ULL, 
            0xC22B6265696E7663ULL, 0xFBAD8D31B218ACB6ULL, 0x9C467F08ECEFB5BFULL, 0x63543E2CDB9449E9ULL, 
            0xB4F66BE4416C0BF2ULL, 0x7029ACDFACEE8B4AULL, 0xE399C68B0F3279EEULL, 0xEEAB887D59EA59ADULL
        },
        {
            0x30A52D0905BFC314ULL, 0xD8FF80D5AE96B49FULL, 0xD15FD0A7AA901927ULL, 0xF3E2A92572D281F7ULL, 
            0xF694C837CAD7BEFAULL, 0x7BFF3CCD492B4F17ULL, 0x60822C0C8DC75E35ULL, 0x11BF88663E1A9371ULL, 
            0xBA979B5C8171ABE2ULL, 0x0648DEFC24FA6E33ULL, 0xC6A87F988DD4A1DDULL, 0x79065A97006901FBULL, 
            0x66396D1D8C280DFDULL, 0xDE0A1D9FABB3DDE8ULL, 0x36E5FA8A593417C9ULL, 0x833B3369C29FA923ULL, 
            0xA1B1DCA44112DBFEULL, 0x6BE3BBF095E55015ULL, 0x4B56637D112B108AULL, 0x97D6C29C53809E26ULL, 
            0xC4DC9C1FD2E9FE67ULL, 0x05880A858949A9ACULL, 0x3B4E671478BB36EBULL, 0x52A54789E4007E89ULL, 
            0xE3125784A3F972A7ULL, 0x0EFDB3E926F48BDEULL, 0x7C378EA3F12D3689ULL, 0x290206D481DC4AC1ULL, 
            0x222F3881A62BC12DULL, 0x631C1A2EC948EEEEULL, 0x53EDEFCF8D3EB6B9ULL, 0xAF1B46D1ED63F0BDULL
        },
        {
            0x8CA13721FD713A83ULL, 0x212B0F634FB671F4ULL, 0x70EC3E0E2F2F0943ULL, 0xD12E3259EA198683ULL, 
            0x0CD3A53CB5D9B107ULL, 0xE699751D6B8B0772ULL, 0x519767F9EB229397ULL, 0x6834FA290997A9EFULL, 
            0x9D3AF0E2427F03FAULL, 0x730279580C33942CULL, 0x21EC1D207BF9D9F2ULL, 0x788447B178846909ULL, 
            0x6EEA4F4C1115DB59ULL, 0x40986FA006B30D44ULL, 0x6389FF3E24878D67ULL, 0xE2B136F5E522287BULL, 
            0x049E6A496287E3B7ULL, 0x425F6E1E348825A5ULL, 0x57E940FC8F9B422BULL, 0xC20AF60A5445BB37ULL, 
            0xAB65401E6BEE012FULL, 0xF1DF631F5984D738ULL, 0xF20FA0BC6D0BFA8BULL, 0x2E6697ADA83CCFF1ULL, 
            0x72B51D3B3E376B12ULL, 0x1C8B0E886B00B2F2ULL, 0xC74B5825DD71CA32ULL, 0x91F5C56FF4C03032ULL, 
            0xB6EED8E3147DAF01ULL, 0xC75A1D71CB5DD608ULL, 0xE5702629E7260EB1ULL, 0x5B49389DA675CFB6ULL
        },
        {
            0x9A466F283AA4C55CULL, 0x9C9C69575FF78517ULL, 0x6F47F44CFF78D7CDULL, 0xD2F5104284896058ULL, 
            0x763FC427F0D389F7ULL, 0xA9B7734743E1786BULL, 0x3FF49ED5BD9F523FULL, 0x09D0A0B4700C7483ULL, 
            0xDB0DC1E866E126DBULL, 0x4B020E6ADDBC5BCBULL, 0x1D642F5AD137F8A3ULL, 0x7E28C86FFAA33B34ULL, 
            0x39A429F7F1DDFBE4ULL, 0x991264FEC90AE801ULL, 0x818CB3857F000875ULL, 0xF244F7B3E4799AC6ULL, 
            0x1EE3F0556BE81F30ULL, 0x4BBB17660C1BAB90ULL, 0xA1A9B85886B50387ULL, 0x8B2B06C0AB22DF8BULL, 
            0xFB7E0E602FF37807ULL, 0x1D078730D9589962ULL, 0x6CA9D80322F677E9ULL, 0x2502E2ADD4A293BCULL, 
            0x2CC9F0A4EA9BF748ULL, 0xF7D0EBD7F865EFF6ULL, 0x283E51F0774073CFULL, 0xF26E65C065588B58ULL, 
            0x6ECD1B4EE6F31D92ULL, 0x10CAC3E791F13659ULL, 0x319585833B0E777AULL, 0xE20DBE5083A509CBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseFConstants = {
    0x8593709F6B3748F1ULL,
    0x30CEB004CC6D4B47ULL,
    0x4EFA9790080CA3A4ULL,
    0x8593709F6B3748F1ULL,
    0x30CEB004CC6D4B47ULL,
    0x4EFA9790080CA3A4ULL,
    0x0DC271B82E8B2CA4ULL,
    0xBF769966A3251CE7ULL,
    0x23,
    0x8B,
    0x84,
    0x0B,
    0xA3,
    0x0D,
    0xEF,
    0x6A
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseGSalts = {
    {
        {
            0x3184AB1E0F5BBE80ULL, 0x2E66751A978B4A1EULL, 0x3CEBA63525073586ULL, 0x6765740020C51335ULL, 
            0x66BA8CB0439AB1D0ULL, 0x7074AD1C4C3FCB8DULL, 0x499FDA391CB30767ULL, 0xBD5FBC130DF269B4ULL, 
            0x37AFA43FCB259376ULL, 0x09E9C77694ADA14DULL, 0x68C9C80BD2F11C79ULL, 0xD33C80E01166D130ULL, 
            0xC1CFFCD23362DB0FULL, 0x8EAB148F0D1768F0ULL, 0x2CAADB1ECCE015AAULL, 0x9011EC94389A52C3ULL, 
            0xB8F79996FF9A9531ULL, 0x7DBE029C60084C75ULL, 0xD59CC75EC4760AFCULL, 0x7E2BD74244E7DD23ULL, 
            0xAF16D1ADA1EF17D7ULL, 0x09D09AF4B5CC460AULL, 0x104565E0D31DB0F2ULL, 0xEF28F84E777CC79CULL, 
            0x94E77C9B42C31915ULL, 0x99F3B3937AA5A525ULL, 0x0F8E0526F56BBBD5ULL, 0x5F82404361E48926ULL, 
            0xE9DC013434CFD0FDULL, 0x9A95265BDD424C74ULL, 0xFEA89ECA6A4EC17EULL, 0xB027FE165669B907ULL
        },
        {
            0x624852FA37CCC743ULL, 0x1F01BC1DCE4D6151ULL, 0xCEE273928B3E7A4FULL, 0xD161DEEDE8BC46EBULL, 
            0x9707377EA486DBCAULL, 0x0A558171C86F8CD8ULL, 0xBF5484A5B0F03B62ULL, 0x282B2763CD02629CULL, 
            0xA3A00EC20B036E66ULL, 0x911298C33D5F267CULL, 0xF4C0E95BDAB5A53AULL, 0xCD0B473437299D86ULL, 
            0x33263FE11AE8EC5BULL, 0x92FEF6D83189E80FULL, 0x191CF43E83173E82ULL, 0xF8960A1E00696669ULL, 
            0xF28A412AF6200533ULL, 0x1ED9836AB19E0135ULL, 0xFEFCE32BF111D420ULL, 0xF495B42D14CAAF7DULL, 
            0x47D0409BA624F379ULL, 0x6C9232069B8C1795ULL, 0x65C8316A2EFE96B8ULL, 0xE708B80E86C6A75AULL, 
            0x894A8A80C0F20ED9ULL, 0x20C0B09083776A39ULL, 0x95998FAE2BB3E593ULL, 0x1837324C8776DE62ULL, 
            0x101FD6D8AA56FBC6ULL, 0xE85293000494593EULL, 0x88D7BF6F0F52DEB9ULL, 0x7BD4006D65A07F16ULL
        },
        {
            0x827926E4F9E24A44ULL, 0xCDA3EFBE775EBD22ULL, 0x083A06C3ECF600C2ULL, 0x23B63345FFF61963ULL, 
            0xBBFE61EC1F5997D4ULL, 0xE98923C248DA92CEULL, 0xD935DAB375F144FFULL, 0xB30D53FABBA63E36ULL, 
            0x43DC17282568A5F2ULL, 0xBE5D3E561895DC43ULL, 0x51B514DB2F7A64EDULL, 0x861C6AA1939968C7ULL, 
            0x0B139AC2E5E6867BULL, 0x7259902A6399F32AULL, 0xA2D5B89F8B12E61DULL, 0xF1A09D9679F1DD5AULL, 
            0x00FECF89FE9919F5ULL, 0x08D0D6F76ED84E9FULL, 0x899AA5E47A131789ULL, 0x360DADE35BA32540ULL, 
            0x832F9F4284711C40ULL, 0x0A6619F79098733AULL, 0xFD3CBFAFF0514297ULL, 0x8DD3A5D1F6291AEAULL, 
            0xEA7982F90D97DA30ULL, 0xBDA7FB1268528E1EULL, 0x4C83AC1E36C48899ULL, 0x74049163955140A9ULL, 
            0x99DF0809729AA06EULL, 0x6E320429CB6102C4ULL, 0x12D1726EA9023B53ULL, 0x6AF3D6D1EC9BD52FULL
        },
        {
            0x5202D06A183904A1ULL, 0x30DB17EC318F434FULL, 0x0742CC2807A22DE7ULL, 0x18F686C822A193C4ULL, 
            0x1B68FC588755DBD5ULL, 0x6910E6B4BBC9A812ULL, 0x4848174B077F0787ULL, 0x474B7D8F2B3E886BULL, 
            0x602D0675DDAC3D5EULL, 0xE8CC3A7C98BDDF93ULL, 0x007B95613A6AE744ULL, 0x30DDB2319AA996F4ULL, 
            0x65209058BDABCB4DULL, 0x4AE449050F9F81EBULL, 0x75CEFC805F89FF62ULL, 0xA17A703F9DC7F8C2ULL, 
            0x20E13DC505EEDC6AULL, 0xE8F6770FDD595BA7ULL, 0x076A7908E794E203ULL, 0x209760DBE100E1D2ULL, 
            0x0DE9EE14D779163EULL, 0xD4C7250C9C379E3CULL, 0x729BB01D1F0B8076ULL, 0xD7848290483798D0ULL, 
            0xE16D1B180565C746ULL, 0x227970788870E213ULL, 0xAA9E9261B6F678B7ULL, 0x90C21C3889B60EF0ULL, 
            0x07553E7562B1A72EULL, 0x222813B98F43527BULL, 0x2EC72BDB8756E488ULL, 0x7B3609A27EC39882ULL
        },
        {
            0x0415708F391656E4ULL, 0xDA8E34D00285F08BULL, 0x97849ACEA52E500BULL, 0x4AA9FA016A93734CULL, 
            0x2B9AD2CE1340B77CULL, 0xF207B53E59121E56ULL, 0xF7563C88656A0DFFULL, 0xAF9F8A7514938ED7ULL, 
            0x09EE8CA0AC79B20AULL, 0x31F48F25AAB21CA9ULL, 0x767975DD0E133651ULL, 0xF54A05D500B4AEB9ULL, 
            0xCAF5F83E89ECE5CEULL, 0xF3F75BC5A3597B28ULL, 0xAD4EFE55A0D26F1FULL, 0xAFE002BFA28DC491ULL, 
            0xFCA81C0D29146752ULL, 0x76D0A5DAB822C83DULL, 0x8740D118B3A07839ULL, 0xE909F790E738B004ULL, 
            0xA46738BE01A61122ULL, 0x5CBFD5A964E30255ULL, 0xBD6FFB3499D352DAULL, 0xE530808EAD1893BCULL, 
            0xC4DAE356A9702773ULL, 0xB11FE952B021647DULL, 0xF1F371284C1AFCD1ULL, 0xB642B10946648087ULL, 
            0x8CA080DE3CB5B464ULL, 0xDA1A9930CBD5EAE4ULL, 0xC3D735F80DDD22FBULL, 0x4D43E056CB336351ULL
        },
        {
            0x40A018E60624226EULL, 0x56811730D4850969ULL, 0xDCF8D894C80A39B5ULL, 0x4424206892CEBE08ULL, 
            0x516277A036D699DAULL, 0x24E6BCDAF9D87485ULL, 0x6CB6A1EA751EA6A7ULL, 0x4DE1E6EEE02E33B2ULL, 
            0x6A74CA9DA2E4557EULL, 0x2230F3DEB27D8F74ULL, 0xF21F24AC60F30853ULL, 0x1D6CC0DA938FCFC4ULL, 
            0xCD061FC0FC068524ULL, 0xA7E0F79D5610D0AEULL, 0x43623C705260A955ULL, 0x043FFC3A1CA7932DULL, 
            0x9B2AF788251B0853ULL, 0xA48326C4728841A9ULL, 0x7E4E38760EA333A9ULL, 0xC30BE4A9DD45DEA9ULL, 
            0x31035B19AC41B357ULL, 0xAFB98D0EAB4BF912ULL, 0x692B06516FCD821EULL, 0x5F5CC45197C17138ULL, 
            0x17E4003607C1E1C3ULL, 0xED8C2F16A0571E16ULL, 0x26C24C387B209DF1ULL, 0x57520910FB8D8B76ULL, 
            0xAE0EC6E617B8143EULL, 0x671E065360FD9D51ULL, 0xE191A0A60E46A7D7ULL, 0x88221A318FE62612ULL
        }
    },
    {
        {
            0x286238FC1020ECE6ULL, 0xB801AB8AC172D22CULL, 0x35817BA476913E9DULL, 0xFEE1DEA596D4456AULL, 
            0x51A01E937F6BF455ULL, 0x77E50DA2CDA02F92ULL, 0x92ED01BE544A0DDEULL, 0x7D17CB12215E088FULL, 
            0x73680945860065BEULL, 0x6D504BFDC1C3894FULL, 0xD725AC938AD9431FULL, 0x1675308A94F4968AULL, 
            0x0AA05C336B37888FULL, 0x04F736955DD15124ULL, 0x703AF160ED1F668CULL, 0x699C23D3BAD945CAULL, 
            0xE10F88CFD71CD1C0ULL, 0x396E1248057433F8ULL, 0x26E06F191550AF8AULL, 0x13D207251DA785D8ULL, 
            0xE0B1423E82A7CB88ULL, 0x0DBFAF6E1D5ADC61ULL, 0x93EFCDE13880366EULL, 0xEB4E6AAB425778FCULL, 
            0x77899DFC926598A4ULL, 0x7322D65CC54B1E4DULL, 0xAAFF65FB386FC7EBULL, 0xCA9B04B1E0D095FFULL, 
            0xDDA9748CBF2035F1ULL, 0x93D3F13417858E10ULL, 0xF7DB73C3F1CF37DBULL, 0x1A379DDB86CF6135ULL
        },
        {
            0x206780D9C869E262ULL, 0x9FB156F89416355EULL, 0xCACF5C9DE8C70812ULL, 0x7B93989D94EDEBE0ULL, 
            0xDDEFA104A191F82AULL, 0x99ED076252537C4BULL, 0x3F8BFBC2C955E863ULL, 0x955BCCE3E9A15360ULL, 
            0x122F75A36869A2F2ULL, 0x3542DB2FB57672C2ULL, 0x72C0041CC63B01E9ULL, 0x9B8715DD4CD7CBE9ULL, 
            0x06E96B1E59C32886ULL, 0xAA505CD281032EF1ULL, 0x95EC649F678F3DFBULL, 0x390C46C8D6A0D04CULL, 
            0xE1ECA3CB2FB84FEBULL, 0x8D4EAC0E4BC76407ULL, 0xE3EAE6FCE7211437ULL, 0xF496205391C4612AULL, 
            0xB6177688A9535B72ULL, 0x3DA687C0BDAD7F3AULL, 0x9B0DA8FF88AB6FB0ULL, 0x3E0725BE6AA946F9ULL, 
            0x038D76B7A925741EULL, 0x25B7FB844223934DULL, 0xF7021D93BBFC5410ULL, 0xBC0B0FBD497C74E1ULL, 
            0xBE59492E9B5FDDCBULL, 0x46C8F0B8D3FCD6B8ULL, 0x2B04FC7CA4511F56ULL, 0x096618F4263148B8ULL
        },
        {
            0x1FA155DDB256EBA5ULL, 0xC8402C6BC61A5971ULL, 0xDABE05A0100FB0B1ULL, 0x01001EACA777B50EULL, 
            0xC7E03B0EC9EFB08EULL, 0x5F71505EE2F2711BULL, 0x72FE8A6549C89548ULL, 0xDF8EF994097B8211ULL, 
            0xDBD00C1BCFC3164FULL, 0x14B8B524A130E624ULL, 0x55A1B9B7B6917735ULL, 0x0BD21F673E9B3829ULL, 
            0x5A69086DD72C0472ULL, 0x7D9010CC71D8A4F7ULL, 0x8559D03E855EDCD1ULL, 0x8035C30F7A6E8EC8ULL, 
            0xD12005A56DD121BDULL, 0x15E6BEAE7612D315ULL, 0xE8D1EC5B4B271390ULL, 0x643D188B2B23389AULL, 
            0x67BE2568E156171EULL, 0x80BCC1A74C2F988EULL, 0x196A010D9C9A5213ULL, 0x9A13D6E02B12F676ULL, 
            0xC4FD1106B18DCA7AULL, 0x731A13BD93418B5DULL, 0x28207C02EAC2D033ULL, 0x44C650F7D1DF8CA8ULL, 
            0x1191BA028AA5B89EULL, 0xA0D5100EC0E0A718ULL, 0x1269C441C6DA69B2ULL, 0x34ACBC38FAAD0EBBULL
        },
        {
            0x1FF0590286407DDDULL, 0xA0D62AF8FADBD217ULL, 0x53E95D222D02FB04ULL, 0x5C85AB1E0D3AC17FULL, 
            0xE87000C97C374C4FULL, 0xEF1ED5981A08C00EULL, 0xA3E844B840AD57AEULL, 0x9D494C6C691BB654ULL, 
            0xF9ADF0DB1372BDABULL, 0xBD4E24178B8D89E8ULL, 0xB37B4452B08EFB91ULL, 0xEAE547E7457B77B0ULL, 
            0x5A6681CEB35D37FFULL, 0x2D081D61C4A1EA89ULL, 0x0F66367B39499B5FULL, 0xFD6B62B8D6D32C97ULL, 
            0x9595F4FDB3683DFFULL, 0x2E2842086A5C6FDFULL, 0xA5890A61EE28333EULL, 0x2E81305EC8F8261AULL, 
            0x86145716D95D1FD0ULL, 0xE7BC398EF9AECDFDULL, 0x296C8D6462AAF9D9ULL, 0xFA7A300837ABDC67ULL, 
            0xD910F1584EF163F2ULL, 0x5D1DDB8E02A24089ULL, 0x777818764C412749ULL, 0x9B1145B0EF0234B8ULL, 
            0x73EBC689B720C443ULL, 0xAC6805B54958E5EAULL, 0x1FE6DFCFE5EBE098ULL, 0xB767A1BA6F6F2284ULL
        },
        {
            0x22E4468315A0A361ULL, 0x9BBF46951CEFB5BFULL, 0x70DC17CA37284D76ULL, 0x306843B33EAE01CAULL, 
            0x8A9CB6CC1F5C90B4ULL, 0xF1EC6945CD28B8F7ULL, 0xE4B9C1877F255ACDULL, 0xF06F187B96E379AFULL, 
            0xDF04BFE791197ADFULL, 0xFC8867AA3F3DC4C3ULL, 0xC0B74C6DF888C333ULL, 0xC64989038A98CD69ULL, 
            0x5D52305494886558ULL, 0x9A5419E3E13671C3ULL, 0x8A4DE7145346442BULL, 0x934C2F55A707920EULL, 
            0x2B1764D8409DBA4FULL, 0xED2A316361B49E14ULL, 0x19B255F08768D344ULL, 0xF88720045FB20E0BULL, 
            0x6EEBD340AE5D80A6ULL, 0x4DE28EC44E38331BULL, 0xDF75C85BC79E463AULL, 0x0FC90E4F0613513BULL, 
            0x66A51AE07F53AE22ULL, 0xA1167C1C075C7426ULL, 0x748B9C190DCE619DULL, 0x9AF088684A773F10ULL, 
            0xCAE6A5BEC4AC4559ULL, 0x739A496B56F2407DULL, 0x59902B588D2711B9ULL, 0x50D6F28884199F84ULL
        },
        {
            0x8063DC5B69AF1A3AULL, 0x9D813BEDAA039A56ULL, 0x41E8BEB091187878ULL, 0x20807882A50BCE1BULL, 
            0xE8840A0952FB14C8ULL, 0xA6798A54C59B4BB9ULL, 0x71225560089BAB21ULL, 0x490F17734236A5BAULL, 
            0xD42AD6BA95B461DFULL, 0x1220210DD36BF416ULL, 0xB514AA754D02D777ULL, 0x88EE231745A43C4DULL, 
            0x6258D4B9C0BD85E3ULL, 0x5A90C6997EE17862ULL, 0x8145A95DE298327FULL, 0x05790218FE3FE5E9ULL, 
            0x2959B8CD5E9A6587ULL, 0x8000F2BB5CBBF7D9ULL, 0x121CB0C6D530B94DULL, 0xBD0A1A3CFA3169B5ULL, 
            0xE24C6824B0D00B59ULL, 0x18F7E733600F25DDULL, 0x032F46F274957BBEULL, 0xED80256126669861ULL, 
            0x8BD0CDB6763BBAAFULL, 0x5DF39C81CADA7079ULL, 0x012769091FA53F46ULL, 0x22853497C4C7BF5DULL, 
            0xAC277EA5C71DF19CULL, 0x44F95856CC0C3169ULL, 0xCBC1E8BC9A8A7DADULL, 0xB4F2D85F9F3A5DF3ULL
        }
    },
    {
        {
            0xB9C6325DBFE370ACULL, 0xD804263913A015F8ULL, 0xDE20AEDBBB0A06AAULL, 0xE9F30937258ABCFAULL, 
            0xF242E9200FF50DC9ULL, 0x4176CDC1A40AD4BEULL, 0xC49C5CF1CC491272ULL, 0x9895677816155BCEULL, 
            0x6ACFDBF03A8CDE4CULL, 0xEE5889CD40D1499CULL, 0xFB310CA7CF07FB90ULL, 0xDC6EA4DB56912D26ULL, 
            0x2E99DD25CD0E561AULL, 0xBBC1600E69B4F7EEULL, 0x2B335A686030ED73ULL, 0x869D541EDFE0E19EULL, 
            0xFB7AB306AB471B86ULL, 0x4772DC9A88DE8F03ULL, 0x7B4F81D492AAEA5EULL, 0x74ACF633661D3172ULL, 
            0xE9289D5ABEDF9730ULL, 0x44B49FBC830620D4ULL, 0x62CFB00F9E8557F3ULL, 0xEA42E435D98B59BCULL, 
            0x4B55AF3EAB4C27C8ULL, 0xD4F5B69FA473DFA4ULL, 0xEC3BD1D4D2D43A8DULL, 0x295BBD150DF1480CULL, 
            0x8A185E88FFA45FFFULL, 0x52D9EE7A97AEC405ULL, 0x51E09DC9E8609694ULL, 0x04F726E13415C7A4ULL
        },
        {
            0x0D18E1D54E62F247ULL, 0x9AEE1A15328A7789ULL, 0xBE566BDC314E1A53ULL, 0x93EA2471DEEFF6B9ULL, 
            0xC5DF61538A53E7DBULL, 0xEA61FD0329E04D9EULL, 0xEF829F9DDA1EACB6ULL, 0xB19B6F19F091B7DCULL, 
            0x8D814A8786B7DDD6ULL, 0x5DCC0B6982656E5EULL, 0x7F1B36E109357017ULL, 0x3EFE81A7A20FB362ULL, 
            0xD84FFA734FBF6015ULL, 0xE41203BDE3C05670ULL, 0x027D29FE167AC941ULL, 0x4C186C58214837F4ULL, 
            0x0669AB5D97559C36ULL, 0xE11FA3976F438059ULL, 0x565721C126153EF0ULL, 0xBD1B038C5095A88AULL, 
            0x19821C5BB721F5CCULL, 0x62D6A5E7235D950AULL, 0xF46DE31C1DA92075ULL, 0xE682AA1E1FD0709BULL, 
            0x55AC8389EC35A591ULL, 0xB75EDC2182AA3A22ULL, 0x868D03B939B348E5ULL, 0xF4E95CAB8E72AB9AULL, 
            0x75640F90C3831139ULL, 0xF6146F127595ABDFULL, 0x9802AB4BB42847CFULL, 0x148DD8DC5C057522ULL
        },
        {
            0x65C780415820D817ULL, 0x78487F39A24CAE94ULL, 0xAFE28B5949CA7531ULL, 0xE13EB926612505E3ULL, 
            0xBF689F118459B882ULL, 0x97496C2B5C9565C5ULL, 0xFF4D2192E6E18C5BULL, 0x82E47F726CFC85F4ULL, 
            0x5C14FD666B17B162ULL, 0x4DA7BD6FD7DF5B0CULL, 0xFECE774C12335803ULL, 0x575763E8843B358CULL, 
            0xAA0CA4FCC96F54D3ULL, 0x90490841A0042E20ULL, 0xBE39C37456B6D290ULL, 0xC3D84BDBE1A731D2ULL, 
            0x884AEFA9D6B7D1A2ULL, 0xECA564FC65E4A21BULL, 0xC1CCE84E86FA79DDULL, 0xC5A211A530CC3EA8ULL, 
            0x0BEE1005CAF75464ULL, 0xC8DE65CD131A8653ULL, 0xB45A05F43D4E1087ULL, 0xB39199BA16D874E4ULL, 
            0xA2327A81B8F7381CULL, 0xD577512FA152ABFDULL, 0x41B1B7AE729E7E33ULL, 0x8CC23D4C9E7B2E36ULL, 
            0x51A2E3602D7F55BAULL, 0xC5819CEFF3137A2CULL, 0x84F16CF38CDC2414ULL, 0xA5E5339C0021B882ULL
        },
        {
            0xDB5E905DA8F1B0D7ULL, 0xC7026221823FDDF1ULL, 0xCA429F1E87B5AA42ULL, 0x4C65E66E8A46B1A0ULL, 
            0xF3A200E34B79A5B0ULL, 0x792087E3013FF660ULL, 0x3B034D7FE3D6ED0EULL, 0x3EF173F023EAD09BULL, 
            0xB049D7926104DF72ULL, 0xBCDF307692E4395BULL, 0x483B079E77D8F22EULL, 0x88DA15DE91E930DEULL, 
            0x4A999FE96C8B0946ULL, 0x9182AFFC6110F421ULL, 0xAE2CE3E7B46CF08CULL, 0xE7A1BAB472FF1860ULL, 
            0x54667447C667D34CULL, 0xE4FCEB360302E2C5ULL, 0xB78BAC23FA6C9C1CULL, 0x4E342C644EEC1245ULL, 
            0xFC45F6AF6BFD5641ULL, 0x31C318DC6DB36FCBULL, 0xC5557F601DBF3961ULL, 0xBEBA02DB7BF1777FULL, 
            0xFB8A35452274392DULL, 0xE2AF64985B77EDB9ULL, 0x02A646A7A1A63294ULL, 0x60406166379A1056ULL, 
            0x93DB0AFE0B7789B5ULL, 0xEC7FB4CF57050805ULL, 0x0328DBA97681375AULL, 0xBC9FEC30B6A1E21CULL
        },
        {
            0x5C919D764266DC54ULL, 0x5CA5CCC217FECCBEULL, 0x14B8064FAA90B0FEULL, 0x54B3728F18BFE71FULL, 
            0xCEBB68EB0755239FULL, 0xC8B2A4D86033F50CULL, 0x325A95D6519E9950ULL, 0x7CF0703A1BDC15B5ULL, 
            0x2CB1EF9352A2BC51ULL, 0x408DBC69E1059A53ULL, 0x7276E8D59B21484EULL, 0xB7F75354A10EBB18ULL, 
            0xD459FE7ACE9CB071ULL, 0xC81249D6326F36E3ULL, 0x6BBDA15C14A34D07ULL, 0x945E2E4033C85951ULL, 
            0xD0B5B7653BEFCEABULL, 0xC79273DBF289F3AEULL, 0x49DA2817F9765476ULL, 0x838CDB86F2DDE277ULL, 
            0x0DD3663025501AC7ULL, 0x752F6A2F626DFB12ULL, 0xF4C5F729C71A5FDFULL, 0x0B030441572A827EULL, 
            0x46C6591A5920F453ULL, 0x94DB1E630E26F585ULL, 0x55D7AA1DA6CB30CEULL, 0x44642C7917ECBFCAULL, 
            0xCBCE974E1870005CULL, 0xB8A006B1D601910FULL, 0x1F15BC9009F978DCULL, 0x37C343F89A8C88ADULL
        },
        {
            0x7076CF5104B3F422ULL, 0xFE884183BA871256ULL, 0x6E0F3DDDDEC2616BULL, 0x0ACE96E43816C510ULL, 
            0x97DF449892C38230ULL, 0xB128948C2F0426C9ULL, 0x8FADFE182264DF40ULL, 0x56D1FD4292BF6388ULL, 
            0x7BF40B490D80A210ULL, 0xC45CBED81F82DC25ULL, 0x55C0B228D3A7611BULL, 0xB69980417C06259EULL, 
            0x23EE12329E8AC1A8ULL, 0x87AE76C9C5FDA13BULL, 0xDF6D1DA74AD6C0A8ULL, 0x90A3052BB9E7475AULL, 
            0xC62F32E3FD4FC23BULL, 0x3A4E82FE4DADAF50ULL, 0x2D090DE3DCA45B33ULL, 0x9966AFDA7DA78A62ULL, 
            0x3B60721A7EE737FAULL, 0x20F78DAC4D005430ULL, 0xB8E85366C40A0745ULL, 0xA113B21589E53C49ULL, 
            0x7F5707C27BA4261EULL, 0x8886C8816B5C3508ULL, 0xC68CE3FD6892FD08ULL, 0xDFCEB658C0A9B60DULL, 
            0x9B0A6299ECA1F65CULL, 0xB809B76D78B96519ULL, 0xFC87EA5B9C6F6FA6ULL, 0x6EFE70C6137A8E25ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseGConstants = {
    0x52A0B1B642678EDDULL,
    0x0E93E3059787893DULL,
    0x04C6D575404FEE27ULL,
    0x52A0B1B642678EDDULL,
    0x0E93E3059787893DULL,
    0x04C6D575404FEE27ULL,
    0xCAB1AAF822BBA8C7ULL,
    0x9F691072763EDA85ULL,
    0x9C,
    0x9B,
    0xF5,
    0xA4,
    0xA5,
    0xB5,
    0x31,
    0x82
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseHSalts = {
    {
        {
            0x76FDBB49D0DAA5FCULL, 0xD9DE9BC420296080ULL, 0xFE95270F1008452CULL, 0x71E56FD8913D08B7ULL, 
            0x7A2BF5817A682B40ULL, 0xB4779DBA684C3C9CULL, 0x9B4E80BD1E4E1F04ULL, 0x1B6D5355D32A32B5ULL, 
            0xECD13990B7326477ULL, 0x12287D9BAD5C3CC3ULL, 0xF19B14E0A94DAB71ULL, 0x53AE77F4441B3D48ULL, 
            0x62C36CE6BDBC18CEULL, 0x17FA9D679C828F4FULL, 0x4C7F20719521A6D4ULL, 0x5BC00A0AD6D65656ULL, 
            0x6A109DB118E3D700ULL, 0x9C4CD6014C026B38ULL, 0x0D729E7EA6160306ULL, 0x858835E07BC801ECULL, 
            0xA03864ABAF61337AULL, 0x469D8F12C5086DFEULL, 0x7EC93B09F5CF2EA5ULL, 0xEE232B7546CAAFBDULL, 
            0xFE205F02FA21E740ULL, 0xDBBA37A395F20E67ULL, 0x0B7AA87695C082FDULL, 0xBB5DA364BAFB1742ULL, 
            0x16E1DF7AF258CA77ULL, 0x6F269EDDA3B7E3F4ULL, 0xDDF52997F788EFF4ULL, 0x417EBCC40CB15C97ULL
        },
        {
            0xB483BD6650F99BE1ULL, 0x5E9F3F393D6F5B1DULL, 0xF69659FBF3522E96ULL, 0x140DA0A485EB21F5ULL, 
            0x1A0FCC1F0FC06284ULL, 0x9797BD49BB614386ULL, 0xF746805F6AEFBB6EULL, 0x3B83ECD71A2894C5ULL, 
            0x767292A0C3BAB762ULL, 0x628B68A0DB95BAD5ULL, 0x9055A39554E5DA10ULL, 0x4CB016803D0086C8ULL, 
            0x5EA1415EAC7EE84DULL, 0x448418E606A2D00CULL, 0x9FE61E77A0580820ULL, 0x50980AF805111E68ULL, 
            0x9B08CC1AA09556A0ULL, 0x5A1B45D4FD45B795ULL, 0x6A592396F4D0BE43ULL, 0x29463BA1A3BF8039ULL, 
            0x01DF45AAD4F5DADBULL, 0xF6B9B3F28F979991ULL, 0xC3545CE1E5CAB1A6ULL, 0x66215AA76FDB8E28ULL, 
            0x13474CBB196F0F23ULL, 0xDEA66FB7301E9E40ULL, 0xF5100D859921E870ULL, 0x6623F57277FFBE22ULL, 
            0xD0F9B55A7E554525ULL, 0x2BC2962D4FAE32EBULL, 0x70367F6C172E7C74ULL, 0x1479BACCE0D15FE5ULL
        },
        {
            0xA2A166DACAC35CA3ULL, 0x79EC17AA73731900ULL, 0xE8631FD93100ADC9ULL, 0xDFB5DC2063EC733CULL, 
            0xC23E305CA09AFDB3ULL, 0xBBC244A3FA7849BFULL, 0x1A50D4501179C940ULL, 0xFFAD44BF95D23F18ULL, 
            0x63E6A9F7FA259720ULL, 0xC2B06227A90F49CFULL, 0x999972D92495B483ULL, 0x6FC9C9FD99A98F0BULL, 
            0xD8044C89877FD841ULL, 0xD66FE08B7FBB2D48ULL, 0xCEB22F2733452B8EULL, 0x08A91BD333E5255AULL, 
            0x294439080EAEBB38ULL, 0x0021C6D3C237FAB9ULL, 0x2EFC567C764A5E16ULL, 0xDA0F73EABA7F04E6ULL, 
            0xAEDE3D25CAE87FD4ULL, 0x252E36A062A72386ULL, 0x1EE18981BF7F6B1BULL, 0xF7D0EDDA33D1EC7EULL, 
            0x6687F458F5F80077ULL, 0xB5D5BAEAD506DDFDULL, 0x0A0CC8F894639CDCULL, 0x304D0FCDC4B4E1E1ULL, 
            0x3247AA933838CCDBULL, 0x676EDD2A4EDD7234ULL, 0xF44ACA96B5FCBBABULL, 0x2CA6924E7A78E0FDULL
        },
        {
            0x53D8109A9089CCEEULL, 0xFC8BD7EB7FC1DAB8ULL, 0x56A94372C8133B68ULL, 0xDA2C171DF4FA2859ULL, 
            0x0828807112EF2697ULL, 0x71A7DD4BD6A31DEDULL, 0x7AFD9FC7F563F76EULL, 0x1EC4BCB7597EBBC5ULL, 
            0x56FB9F9890E55792ULL, 0x9E4E2C8E8F22C1AEULL, 0x7DBC550078FA7096ULL, 0xA6921E372EF621F9ULL, 
            0x946B14E2A92F1E3AULL, 0xAA621041FCC73AA2ULL, 0x804AFA6BAC64FE76ULL, 0x19A0A73236C30472ULL, 
            0xDFF8340DE5D83939ULL, 0xB74421D95A887EFBULL, 0x5EEBA103FB5AE5B8ULL, 0x3033248BC6AE2CBAULL, 
            0x0169D6E31F0BC44BULL, 0x52F09BCF0AEDB764ULL, 0xDDB64C33C10D402FULL, 0xE8DEF90C58E4600CULL, 
            0x71081EAB715313A3ULL, 0x6EE8CFD86D951395ULL, 0x59AF39AEADBCC00EULL, 0x2D98A4630A75B89EULL, 
            0x7198F11EB5263EAFULL, 0xF423F5E528886BECULL, 0x841488EA412B4A3CULL, 0x15EED0B6AD5FB172ULL
        },
        {
            0x241A6E3A81473DDEULL, 0xCC344BEAED34BBFFULL, 0x8D7803D48F1E97FEULL, 0xD141E2098773ABFAULL, 
            0xC9FDD30FB0E53AB1ULL, 0xDA77CCFFE684B0DAULL, 0x6EF50AF0D79E8D51ULL, 0x5973BE330790D67AULL, 
            0x047A8B73C89C015AULL, 0xFB45ED494E19420EULL, 0x0C3FD906ED752976ULL, 0x328DFFF3DE42D387ULL, 
            0xBF3D618074A0D42BULL, 0x535315F25AD5A14CULL, 0x7D2CB4EED1CF6D4FULL, 0x514B68D2098EEF9BULL, 
            0xF9D983388F01BFAAULL, 0x87FFB3E2F8F2F74DULL, 0x92E6C6367973F38DULL, 0x5EA60BB4E11BD6AEULL, 
            0x3F7A7F426BE878BEULL, 0x2C3CA5DF35332AD4ULL, 0x5BBDA8B07379FF05ULL, 0x7AEE29B620B53D82ULL, 
            0x336B33E3C35DF9A9ULL, 0xC10AC683C4D065C5ULL, 0xC647A101413B8DDAULL, 0xB343CCAAD9828E31ULL, 
            0xA0665750CB5598FAULL, 0xAC309E163EF7543AULL, 0x370912669EE8D8E5ULL, 0x9469E053ACAE77B9ULL
        },
        {
            0xBE6D8F5ABAECD8C3ULL, 0x9895B79AA7253F41ULL, 0x040DB35B6DEBA4ACULL, 0xEFD9C4C4F43E4EBCULL, 
            0x9146B4AC0363CF17ULL, 0xFA078615CCAF0C7EULL, 0x2A21936706E395A8ULL, 0x3F6919BB9E612FA6ULL, 
            0x9C3C04451383BC50ULL, 0xB1BB35FDEC5DAB87ULL, 0xFA62D9B5BA5EC649ULL, 0xD4D39EA2C3698074ULL, 
            0x361AA112E12F1EEAULL, 0x2E6DF13D04ED9473ULL, 0x5B10501771DB74C8ULL, 0x91AD198C3D7553B7ULL, 
            0xF26D5243CE3C6B4FULL, 0x6B0A0B2D7CC97C3CULL, 0x3522D4EA4EC82676ULL, 0xA8184AAA44FF7820ULL, 
            0x010CB7BB6279F3EDULL, 0xE1A0FB55183291E7ULL, 0xA12C00E97008ED2BULL, 0x976988C2810C78AEULL, 
            0x735A1A99B86AE2C0ULL, 0x849A02EF8F078048ULL, 0x56DC66EE55C76515ULL, 0xF324C0F520419CE7ULL, 
            0xDCB7DA862B018532ULL, 0xCED49113D1C98768ULL, 0x3893CCC90EBC4E09ULL, 0x1DC32B338E64D53EULL
        }
    },
    {
        {
            0x35009398CDF02435ULL, 0xC22D3B4E45246D63ULL, 0x4E9039DA9034650DULL, 0x9103830E6C84F901ULL, 
            0x5FCB1DC3D74596D3ULL, 0x0094E6D49E490E23ULL, 0x350BB12A62860A38ULL, 0x4C215C17D2E895FFULL, 
            0x6D3D93EE635DE634ULL, 0x71ADA9D566E8DE0BULL, 0xCA35F2E2EAFC8A75ULL, 0x64DDE530ECAC6AA7ULL, 
            0xA62FA076D9EE6AFDULL, 0x9B17258C481CB84FULL, 0x37B02E89B2A5F221ULL, 0xBA868DF807881D9DULL, 
            0x23E9DF2EC62C7307ULL, 0x8D5B571B834CA0B1ULL, 0xF114A2DD2E4C9CFAULL, 0xC7603297C8704795ULL, 
            0x3090F9FE89B01801ULL, 0xA04DC80B5E81144BULL, 0x66BC9D560E7F28D2ULL, 0x2CA3439E722349F3ULL, 
            0x8C6648711E79CC80ULL, 0xE25DFE0FC24DFD01ULL, 0xE222BFC22E868FB1ULL, 0x112FB8FF27F3CECAULL, 
            0x67425321F7FC7217ULL, 0xE5C10EDFE0A4097BULL, 0x4D5E48257A53649CULL, 0x5804110079F34977ULL
        },
        {
            0x080BD16FED764CBCULL, 0xD556388EE4FA0E0CULL, 0x998084186E88C865ULL, 0xEDDA47766478F1FCULL, 
            0xF17BA5B6D96574B8ULL, 0x395EF58135B6E33EULL, 0x6F7BB2A2969FE841ULL, 0xD5FCCBF9BEFC847EULL, 
            0x40AAED74502736F3ULL, 0x84C8BC9BCDE8C227ULL, 0x9362E450AD62A155ULL, 0x4FAC583203574C7DULL, 
            0x81954E6E7C5B357CULL, 0x12370D7C6588E5B4ULL, 0xC0C81F449FCAB0A1ULL, 0x78A3AFAB00E77E93ULL, 
            0x4C3E483C3296D096ULL, 0xF5B1659E1E2068B8ULL, 0x148270FA28B5AA9FULL, 0x9E875DF94F004CDCULL, 
            0x36E204D5BC90CF37ULL, 0x754FE81A31BE4265ULL, 0xC6F0BBCDFAA17339ULL, 0xEB8A72F69C65981AULL, 
            0x8643F7DCBA79DE53ULL, 0x56B15AA708AF59D7ULL, 0xA3244A67E508F957ULL, 0x360B62D4825B4345ULL, 
            0xE1A7088D8C27CFC8ULL, 0xCF9C1038A3751A60ULL, 0xBD0A53A536839DB6ULL, 0x72ED4883070C621DULL
        },
        {
            0x486C5B2064EDED90ULL, 0x70D0B85A5B6C7573ULL, 0x2BD6E6F789DC23DCULL, 0xEAC7799335513B54ULL, 
            0x3C614B9176241C05ULL, 0x0C2CF43BDC4E2B0AULL, 0xFDF19A9504C59D5CULL, 0xAB8D7F563C28E303ULL, 
            0x96B1712853D6CCB6ULL, 0x8C3AAF9C25D03C47ULL, 0x445CB62B97E93DDBULL, 0xD628EBDF6E1860B6ULL, 
            0x237E786ECDD9B1D3ULL, 0x2C7225DC3AAAE1C8ULL, 0x763A88038820501CULL, 0xFE311CEF0ED3893FULL, 
            0x03EDDE825AD17D6DULL, 0x798DAB15D13139CAULL, 0x4306595E9877DBE1ULL, 0x4683B40618A536F5ULL, 
            0x7CD2A8FD0E02DDC5ULL, 0xE76A6C33E32BF8BDULL, 0x7A0F52F4CBD726CDULL, 0x72D36D3803BBF716ULL, 
            0xD97AC24AC4F11015ULL, 0x07452C7FDF3285BFULL, 0x19DE08C398676B89ULL, 0x06FBD1395A3CEF41ULL, 
            0xB8F6CAEBECAF69D4ULL, 0x607F0E7D4AFA9B6AULL, 0x51AF311BDC21D334ULL, 0xE6B28726E34AA691ULL
        },
        {
            0x28680CB654A09D6BULL, 0xEDF2868F9CB65352ULL, 0x2685FBE868C83045ULL, 0xEA598D48272F0EB6ULL, 
            0x73396396B45A993BULL, 0x59748C99E0D22592ULL, 0xDBED952A12F5EE43ULL, 0x7B0CFB58635F9F73ULL, 
            0x024A3F01CBE29F40ULL, 0x27F625285D0D8D60ULL, 0x7BFB4602E52732D4ULL, 0x6278007D81EF4A4CULL, 
            0x7E8209667A560151ULL, 0x7AE1496598C523C8ULL, 0xC33E2EBCB21FAD24ULL, 0xFD2437E5A1A2FB29ULL, 
            0xD4D222EC1E43D052ULL, 0xDBD88C8A2ED56876ULL, 0x8BD3EF620E67D682ULL, 0x2D811148C7676747ULL, 
            0xF522F5DF5B6AAB3BULL, 0x223587E52E450702ULL, 0xC6B198B1125F4FB4ULL, 0xFF506AC25FBA8166ULL, 
            0x3428C468900A1CE2ULL, 0xB887E10A2CE84E3CULL, 0x25D307327FBE3218ULL, 0xF0DA8614F58CD1C1ULL, 
            0xCA8D0B78733775EBULL, 0x9FBC7AB9E48C8A30ULL, 0x668C6F9B97F143EFULL, 0x50B94836891D20CFULL
        },
        {
            0xE64B5FD5F33B26B6ULL, 0x0A170FE0596ADDC6ULL, 0x244DF2BD62F1F11DULL, 0x7E844755FBE6141BULL, 
            0x468348A29CD47EBDULL, 0xFFCFB4C08EBE6D59ULL, 0x7E2335D6D994B3CAULL, 0xFCF8176EE039D88DULL, 
            0xEA72E23013940E15ULL, 0xAD25EE8DF073E7D7ULL, 0x87149EF28C3D80FFULL, 0x9427141AB53D1184ULL, 
            0xEA432D9D7F0A8B1CULL, 0x9380D0B083FEFD0EULL, 0xEA51F33C58B1D9A3ULL, 0x483AD81C1EE27081ULL, 
            0x449A04E48E78471EULL, 0x5B0168DE13EE1C2DULL, 0x3D199F6C49626CC6ULL, 0xBB7240148379EEA9ULL, 
            0xA9E7F6E135C04548ULL, 0x91BB710F177AE099ULL, 0x4093B2F7D422AD3EULL, 0x0F819C94A4F50F54ULL, 
            0xFBF888CC046A2DB2ULL, 0x80B926497C6D3DAFULL, 0x085A55DE9A2E63F3ULL, 0xB529448CBD9852ECULL, 
            0x5527952F2A409D0FULL, 0xBA9F62178AE60FBFULL, 0xC154F6D929548C17ULL, 0x2B9AE9A278AE707EULL
        },
        {
            0xAEFFBE54CF3F09D0ULL, 0x8B9B7D9072E39422ULL, 0xC07E6E13F45176A7ULL, 0xB987877E670685E1ULL, 
            0x2F0CF81E51468D70ULL, 0x9E0A6A5D2CA3DF85ULL, 0x616C36F5A117CCEDULL, 0xAF0F67A8208F6328ULL, 
            0x0A830BEF54E8852CULL, 0xE436BFE6A0EC0770ULL, 0xB77EBF61BE860D88ULL, 0x4020C4B42E121B2BULL, 
            0x4EA0FA1AEFD5D4E1ULL, 0xCCA0F1097BC0CFE7ULL, 0xBC01192A447C6A12ULL, 0x9EFDD9299EA36EECULL, 
            0x1F7CC18300B4B89AULL, 0x284BA1DFB88CC36BULL, 0xEC10B64967C32952ULL, 0x610F6E0DF5D62D88ULL, 
            0x21BF3BED290DBA3FULL, 0xDF4D5A51DEA99508ULL, 0x66BBB730010130C2ULL, 0xF8E08687EB58BE59ULL, 
            0x4D3D034D7A021425ULL, 0xE72AD73E402F57DCULL, 0x3929CFEEFA3683E7ULL, 0x292DA92194BA812DULL, 
            0x2E9A0CEA1AB95582ULL, 0x070B0C860FD30B27ULL, 0x8539709F16415555ULL, 0x99DB893332340730ULL
        }
    },
    {
        {
            0xA9BF5825A4A5B9BEULL, 0x7CF794D9E86123FCULL, 0x365F513D96B02E2DULL, 0xC84399FC567E1146ULL, 
            0x68DD284AFA3F6E8DULL, 0xD10BF3942D3530DBULL, 0x464F81444B88FB3EULL, 0x7A5FA2A336152D34ULL, 
            0xC3C55DF8DC5F2C64ULL, 0xB66C0C73C448A7B9ULL, 0x898AA6FFA37DCCF4ULL, 0x9A8319D708ED282DULL, 
            0x7D4E4CB71CA997D5ULL, 0x0EFA9F364F360148ULL, 0x5D2A429E864ACAE1ULL, 0x2D698A4DF1C52AFCULL, 
            0xEFD0D43C0739357CULL, 0xBA79BFDA5CEBB449ULL, 0x34E8BCB7D2D8D30FULL, 0xC7121E2BF7BDE0AEULL, 
            0xF4DA15D9F045ADDBULL, 0x5122F6D266E53697ULL, 0x091BBD960566F910ULL, 0x7743E72DA714F38BULL, 
            0xBF5CDA053C11A880ULL, 0x06770CE6050B2605ULL, 0x2E815CA72A41019EULL, 0xDAF915A94243FA45ULL, 
            0x84F8C9FE07134443ULL, 0xD864B8C711850F0FULL, 0x0DA80F3BEF686A22ULL, 0x86A35D830AF6DFE3ULL
        },
        {
            0x53386ECCA4C7E28EULL, 0x0C5CF6FD0358175EULL, 0xAEE09621F62A7F2FULL, 0x974CEBE9B3373BBCULL, 
            0x9AA5E46F4EE9B642ULL, 0x7C0489946822EAF8ULL, 0x98C90D9AFBF56145ULL, 0x3A078EFEB00CE423ULL, 
            0xCEDAEC72631EDB3AULL, 0xA14CBA7D01DAA256ULL, 0x9A62F58BBACAE4DBULL, 0x01DDC72F49453F51ULL, 
            0xE4D50C3294B9615BULL, 0xA3EC0F315333AA5BULL, 0xD523D0F316A29A53ULL, 0x1080AB44229D40CCULL, 
            0x63184C603757120CULL, 0xF0DD5524D936879BULL, 0x692815A0A53A5381ULL, 0xD3B560A92D821CFDULL, 
            0x7E85066DE9D37470ULL, 0xD65307CF88C89C56ULL, 0x637FF2085F5A4293ULL, 0x7B6CD08729A4F6DCULL, 
            0xFAD6E9C86C4D2013ULL, 0x64C3AB69F530196AULL, 0x7DBA2DF4B7D52506ULL, 0xB8D04B3F94CEDF63ULL, 
            0x1FB34C530E7F0D26ULL, 0x4E6847D4763A6211ULL, 0xADE24C375195DF1CULL, 0x1E54F62DE7FF76D7ULL
        },
        {
            0x5F2D93D22D15DD2CULL, 0x782378BE9A259DA9ULL, 0x9B4B8C32583D72D7ULL, 0x5A5932AD93A3D8C4ULL, 
            0x1D9478F1F67EBE54ULL, 0xCB6AC8C0538E6F11ULL, 0x0013BB78AD26F127ULL, 0xA552673735EE3EFEULL, 
            0xF8D9202BFEF12332ULL, 0x7BAF0C5569F1B956ULL, 0x4D33B351FE7C1BCEULL, 0x68A300D47B284EDFULL, 
            0x2799FF1459678ED9ULL, 0x0941370EEB9B7141ULL, 0xF6BE7D5B075622D8ULL, 0x44F4702734FC8673ULL, 
            0x969C16D929518E2FULL, 0xD5A6B78E9361E890ULL, 0xF72FCF6FDB26AF7CULL, 0xE8A906ACBA8E78BDULL, 
            0x19668AB232604BBDULL, 0xF22A13C5F44EDE55ULL, 0xA9D28EAB5EB86955ULL, 0x455B6A51B240F0CAULL, 
            0xF61D371F436AEF76ULL, 0xAFBB2ADED1B9FD85ULL, 0x7EAAF73196EB1D69ULL, 0x5164AA03B4E3A917ULL, 
            0x2DAEDF2280F2B1D1ULL, 0x3FEEC3054E0DFC59ULL, 0x6B598AE93C287BDDULL, 0xED610ED7BBD53B59ULL
        },
        {
            0xED94E35BDCA72C38ULL, 0x6BCCF417EB855490ULL, 0x7DEFD169353433FBULL, 0xFCE69E950B577DADULL, 
            0x56F58401BF7CE192ULL, 0xD263BAC8A674BFC5ULL, 0x3807F5E3736D4904ULL, 0xE321425330D65EB5ULL, 
            0x17292337B8A66116ULL, 0x15AC43D6D1850406ULL, 0xC2DF961E52C92BFFULL, 0xB6DA83B02DE23B1DULL, 
            0x8FEC4770E480F7D3ULL, 0x40547F9C6FBBA8A5ULL, 0xEF4394B8374C9425ULL, 0x8D3539654D1A806EULL, 
            0xDCBA3BC2BAE28245ULL, 0x680C27BE29DC24FEULL, 0x3219F9F4CDE25DB9ULL, 0x651929CE8DD62EECULL, 
            0x1858CB33A6D36C9EULL, 0xEF15D33D14F6D50EULL, 0x0DD5FECD84DF2522ULL, 0xFE4FF4995B3FCBA3ULL, 
            0xC8C08D24B62ABDEAULL, 0xF99EDCEC756922F9ULL, 0x66DC06BA0873C41EULL, 0x736749AB3DA95C5EULL, 
            0xCCF3EF0ABE1C3247ULL, 0x37C4FC1B3DBA72EAULL, 0x64A7BB37DF887453ULL, 0x2DBE7FC3D1FD4412ULL
        },
        {
            0xBD02D3D6D6198CACULL, 0xF8754ECA114ADF6AULL, 0x4004771630D41CAAULL, 0x849688045024C414ULL, 
            0xDB0A78097C7C50D7ULL, 0x747FB0D3DD771DBDULL, 0x3D0CB0EC2A9059A9ULL, 0x36E213FF61A559A8ULL, 
            0x0EB5634D43BF4D86ULL, 0x7405E86387448B86ULL, 0xC2BBD5ACA900FF1BULL, 0x67229F1597A1D859ULL, 
            0x2898D0CF56583FB7ULL, 0x10B7761E4B5EA3D3ULL, 0x880140CC25496D51ULL, 0x1DB28FFBC5C0654EULL, 
            0x6E3E293C8B0350A7ULL, 0xBFE6922637D61EFAULL, 0x1A1D17BB6D06E412ULL, 0x059C20B466F9C5BBULL, 
            0x2996C22FC03FE731ULL, 0x7BFAB88E715094EBULL, 0x7675AD7402D6104AULL, 0xF729B95BC763F143ULL, 
            0x4ECD176CA933227FULL, 0x0494B1C5DC44EF2FULL, 0x6CC4EB19FA5CB923ULL, 0xED6D25F8DA98C983ULL, 
            0x058D4184AEEFDE69ULL, 0x4B13E1A7913DBB9BULL, 0xF60A736BBA348753ULL, 0x9C5C6B1E78EAA5DCULL
        },
        {
            0xBD7B9372BC2A3767ULL, 0x37360D72EC24BEC7ULL, 0x1CC964880B94FAFBULL, 0x808EE0CFAEEF02D4ULL, 
            0x17EA080F15EE3A4BULL, 0x932126A6B7C27745ULL, 0xDBC1E1E720637277ULL, 0x8774DF2CD90ACE99ULL, 
            0x51870373C9E09533ULL, 0x11792D96BC75258DULL, 0x4F303DCC919761B5ULL, 0xBB93257753FBA933ULL, 
            0x8897E73F89044D5DULL, 0x195498D88B24B22EULL, 0x2B78993C7D7DB8ABULL, 0xF1721B54A3F12CB3ULL, 
            0xAFD0DB950C944908ULL, 0xFDAEA1333A0A69B5ULL, 0x559DB9A78F8D3F09ULL, 0xE727E6A54A15C751ULL, 
            0xF5DCBCD247D9FA4FULL, 0x62BACC245724E53FULL, 0xB452F0BCA4B8CDADULL, 0x83C422F83B4450CBULL, 
            0x413503C6D486E9ECULL, 0xD245273237DC2FCCULL, 0x984AD4DF1240C546ULL, 0xE103A00B7084A011ULL, 
            0x9FFF22490D6E62A0ULL, 0xE907CDE70792A532ULL, 0x763059082C4A2D55ULL, 0x34AEEC7013AD0A80ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseHConstants = {
    0x2D828976ED784C3AULL,
    0x71F19B6388EA3115ULL,
    0xC317BCF6A27AC8CCULL,
    0x2D828976ED784C3AULL,
    0x71F19B6388EA3115ULL,
    0xC317BCF6A27AC8CCULL,
    0xBAA7942F95EFB522ULL,
    0x11AB3594DDD06681ULL,
    0x70,
    0xF3,
    0x14,
    0xED,
    0xB3,
    0xAB,
    0xCA,
    0x6A
};

