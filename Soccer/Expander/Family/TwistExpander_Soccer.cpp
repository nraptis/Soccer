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
        aPrevious = 9603869977183047609U;
        aCarry = 10753341821299800253U;
        aWandererA = 10407227409427765061U;
        aWandererB = 13898333725019944191U;
        aWandererC = 11525917406982298839U;
        aWandererD = 11317971607807887681U;
        aWandererE = 17726683678517509879U;
        aWandererF = 17699732124915759522U;
        aWandererG = 10828591477880621101U;
        aWandererH = 17765668422721622965U;
        aWandererI = 16154683077229432490U;
        aWandererJ = 10084657212429760516U;
        aWandererK = 11310602552735299503U;
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
    TwistExpander_Soccer_Arx aKDF_A_BArx;
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
    TwistExpander_Soccer_Arx aKDF_A_CArx;
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
    TwistExpander_Soccer_Arx aKDF_A_DArx;
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
        aPrevious = 17857259253034916835U;
        aCarry = 11735726693459649671U;
        aWandererA = 16997805559013403430U;
        aWandererB = 13893740475768432350U;
        aWandererC = 15143718227179936367U;
        aWandererD = 15945706564526725380U;
        aWandererE = 9774887297693637973U;
        aWandererF = 16631213764348095984U;
        aWandererG = 10757075835076919473U;
        aWandererH = 15800840884928111599U;
        aWandererI = 9654500540230897659U;
        aWandererJ = 12051596358934222724U;
        aWandererK = 12322062902218339247U;
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
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_Soccer_Arx aSeed_AArx;
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
    TwistExpander_Soccer_Arx aSeed_BArx;
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
    TwistExpander_Soccer_Arx aSeed_CArx;
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
    TwistExpander_Soccer_Arx aSeed_DArx;
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
    TwistExpander_Soccer_Arx aSeed_EArx;
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
    TwistExpander_Soccer_Arx aSeed_FArx;
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
    TwistExpander_Soccer_Arx aSeed_GArx;
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
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
    {
        aPrevious = 17731790484125220099U;
        aCarry = 12612560693868908399U;
        aWandererA = 16308899391573093790U;
        aWandererB = 14374657532539723020U;
        aWandererC = 13861328099063953035U;
        aWandererD = 15950700520655218075U;
        aWandererE = 9273479873598934330U;
        aWandererF = 17445696473758814042U;
        aWandererG = 16919582825862541566U;
        aWandererH = 15704308422341366949U;
        aWandererI = 15635269007195538863U;
        aWandererJ = 15157983115611162710U;
        aWandererK = 14485784102816890612U;
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
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 0, 3 with offsets 2299U, 6806U, 6095U, 5159U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2299U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6806U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6095U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5159U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 0 with offsets 4092U, 7043U, 3884U, 4818U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4092U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7043U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3884U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4818U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 1 with offsets 4768U, 2837U, 6637U, 5403U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4768U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2837U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6637U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5403U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 3, 2 with offsets 6697U, 2251U, 4858U, 3548U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6697U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2251U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4858U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3548U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 with offsets 1644U, 616U, 733U, 37U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1644U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 616U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 733U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 37U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 202U, 787U, 1209U, 1251U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 202U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 787U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1209U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 1423U, 1849U, 514U, 1312U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1423U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 514U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1312U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 0, 3, 2 with offsets 221U, 1324U, 438U, 2038U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 221U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1324U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 438U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2038U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1354U, 920U, 1372U, 1018U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1354U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 920U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1372U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1018U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 2 with offsets 7273U, 6825U, 5460U, 6221U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7273U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6825U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5460U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6221U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 3 with offsets 8054U, 3475U, 953U, 7314U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8054U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3475U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 953U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7314U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 1, 0 with offsets 461U, 939U, 584U, 3788U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 461U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 939U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 584U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3788U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 1 with offsets 5542U, 3173U, 2952U, 5155U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5542U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3173U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2952U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5155U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4895U, 5474U, 6463U, 4799U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4895U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5474U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6463U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4799U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 840U, 1632U, 1268U, 1820U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 840U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1632U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1268U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1820U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 327U, 1283U, 2007U, 205U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 327U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1283U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2007U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 37U, 1183U, 215U, 496U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 37U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1183U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 215U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 496U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 106U, 660U, 1714U, 1556U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 106U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 660U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 1826U, 1090U, 1580U, 1631U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1090U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1580U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1631U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseASalts = {
    {
        {
            0xFF74E260D77EF79DULL, 0xC38A6DC5D6B602BBULL, 0xB3CA7EB5216CEBDCULL, 0x8569201266344E4EULL, 
            0xF8D0A220DD7D9B18ULL, 0x625E64A33D97ED6CULL, 0x1E469C6E0B0F0728ULL, 0x201DF9956E6A663FULL, 
            0xB6EA8EE3B7BEEED0ULL, 0x3ED20235BF599D59ULL, 0x7A0DD2D755431376ULL, 0x50D3BC8B9AE74228ULL, 
            0x7923E968863FFEAFULL, 0xEBFACC1F801DEB88ULL, 0x68416C26C08D4FBAULL, 0x5F11F9431D77C958ULL, 
            0x31EC35FC993F0CA9ULL, 0xC225BF8E7A70A4B6ULL, 0xE8DB52F14A3FB25DULL, 0x36A7C87770A64166ULL, 
            0xAE08D65B5B37885BULL, 0x4AC145A352A1EB41ULL, 0x45A303666294AE44ULL, 0x0974CE45E36AFD87ULL, 
            0x05DDF39538FAC0D6ULL, 0x1D6AA3CAA4037A6BULL, 0xE7D77E78F8040240ULL, 0x0FA9C50F373A217AULL, 
            0xCE8CD9477A70D161ULL, 0x7223EA67DAF1BD1EULL, 0xAE4C564D5B73DC79ULL, 0x7D983F60B381F31FULL
        },
        {
            0xC70668815BF95330ULL, 0xA7204BC946DFB3DAULL, 0xB8E4B756E3F946BEULL, 0x04319AB1F9B9F814ULL, 
            0xFA70E370B8BFD60CULL, 0x8F8CB97338E68105ULL, 0x60616709C20BDA07ULL, 0x4C7D0D3793DACEC1ULL, 
            0xF881BAD82753217DULL, 0x57A3E69B59D76D55ULL, 0xA4CF6FC861680546ULL, 0x8CB65FB024A91BCAULL, 
            0xF0E560DCD1735C4CULL, 0xF16EB8A0C9761148ULL, 0xD0DB7AC314CA6228ULL, 0xCAEED443B5142C7DULL, 
            0x95F51C1210FC34C4ULL, 0x235DFFE3CB5BD1C0ULL, 0x4387F3CB9E0F4656ULL, 0x18C0526501CC333EULL, 
            0x879B3D087EA635DFULL, 0x934EDC175FFF9E68ULL, 0x4E39C674695E484FULL, 0xF7BE7A2D4A41FF88ULL, 
            0x358F218FCEDEEF5AULL, 0x0C5AAFF4D21916E3ULL, 0x3F067FDB8D85BD09ULL, 0x997D1E33DA2AA34CULL, 
            0x6B69035373A51737ULL, 0x42AE38C1F5BDE997ULL, 0x34A2C40B0CC762DAULL, 0xADD19A07EA33825CULL
        },
        {
            0xDC3CD7140310E1D6ULL, 0x8B127CE80EFE7F5AULL, 0xCBA3079ACD893F70ULL, 0xA65F9FC815F81327ULL, 
            0x8935821EA6031B25ULL, 0xD2565D2A75FB3BB9ULL, 0x64704ADCC973E013ULL, 0x65E66B33AB1CDB66ULL, 
            0x63A121EDA169539DULL, 0xB11FD5FEDE8A6EDAULL, 0x5ABE9CCEE0A7D5CDULL, 0xF873D75986DD72E4ULL, 
            0x36C2FB4EA08B5120ULL, 0x5ECEDE3EAE047B1EULL, 0x57B9EDB52C2D86CCULL, 0x4A7F30557F1ABC75ULL, 
            0xACD2F7A88B7F175CULL, 0x45E56C22A0A79DADULL, 0x9EE1AE82FCFC11E2ULL, 0x0678575FEC59C087ULL, 
            0x2A25F9125BC16682ULL, 0x6C527E5E0807D45CULL, 0xAF743851268A9F9DULL, 0xBA74856155EA621FULL, 
            0x36AB6EEEDBEB2288ULL, 0x0801874378674FC3ULL, 0x8955513EFDBC69F3ULL, 0xB1A7DB11F821F1E2ULL, 
            0xF92478A08B4BCC88ULL, 0x50608FD6400F4D00ULL, 0x507C7F1A322C422AULL, 0x865F6D7064EAC72AULL
        },
        {
            0x1928E253F4D80356ULL, 0x4758ABC2CE951B35ULL, 0x07053C8908A5AEACULL, 0x2C7503398998B9B1ULL, 
            0xBE870118B8AAFCB6ULL, 0x577397B18F675A87ULL, 0xFB77E3DEEDAD4EE6ULL, 0x28D0C19F2268104EULL, 
            0xB516B0837EB52FE7ULL, 0x6B0C56D7C4F3AE42ULL, 0x77CA2E3EFD5EADD2ULL, 0x81AFA704880587C7ULL, 
            0x8A51F2A45F557D47ULL, 0x5D11D548A0995037ULL, 0x8CB0C2CA5177266AULL, 0xAD6E0A551637E802ULL, 
            0x5A3D31817A92579DULL, 0xB89F2FE447E3D9D5ULL, 0xA20B9323D92D6F78ULL, 0x813C299BA146AD90ULL, 
            0x68C9294AB8F9FD70ULL, 0x2BCC5862CAE37A94ULL, 0x35F80B4999FCEC1FULL, 0x48143EE00E3C314DULL, 
            0xC44837BE1D2955F8ULL, 0xC3614DCE013A1ACFULL, 0xFF5C0881DEBDCE54ULL, 0xB7E91AE13555A576ULL, 
            0xCBFEA2EF2CB12667ULL, 0x0A68C6FBBB8F854AULL, 0x3F57729CD24C5AF2ULL, 0x6FDDE4268127BA44ULL
        },
        {
            0x6A217D2077D601D6ULL, 0xF0F9449918D32200ULL, 0x75C2B82C0C7AC112ULL, 0xE48588EFB4542945ULL, 
            0x305081C43DB05D20ULL, 0xF269C55F612244D5ULL, 0xC27F1744130BB6C1ULL, 0xB0B38CD5B2E3DFAEULL, 
            0x38068AB1608F8C44ULL, 0x0C80F89D25CF3FA5ULL, 0x426164B9C4054BB2ULL, 0x59402844DF48495DULL, 
            0x935B4140C2BE01DFULL, 0xFA3B1C72537D65B9ULL, 0x134231EE0ED09925ULL, 0x5F8F68C195746B5EULL, 
            0x968D0480A36865EBULL, 0x48C763EED0A1547DULL, 0x0095AF968B5646A2ULL, 0x0B1990A97F953651ULL, 
            0xA4CA58BD4E4E7A92ULL, 0x75E6BC026ECE8B5EULL, 0x68B2B2E85F74E8C5ULL, 0x03B96945207A64BBULL, 
            0xFB54E6AF7DBD4D07ULL, 0x198C9EFC31F471C9ULL, 0x98E300FDDA916A81ULL, 0x97784750A524453DULL, 
            0x200843201716AAD2ULL, 0x7DDB3BEC981D9347ULL, 0x88508948CB37B116ULL, 0xAC9D36339E364CBAULL
        },
        {
            0xFC8F46128ADDEB05ULL, 0x4F6CAA252B2F0AADULL, 0xBEE81A60D3C64A5BULL, 0x7A1E2DE9A12BFA07ULL, 
            0xF9E96F073FF739FAULL, 0x158B897CDB6F1D8AULL, 0x81D377E790668248ULL, 0x0610CEFEF97B540DULL, 
            0x3B55DBA27968511CULL, 0x3E0B11317C345A0BULL, 0xF347300E076AFEEEULL, 0x4649201315E4AF81ULL, 
            0x7967F62E33AF19D8ULL, 0x883E4AB770180051ULL, 0xFFBA7EE1C489D599ULL, 0xC541492126AF053AULL, 
            0x717385FB8D3C1D44ULL, 0x4144EC0E06697156ULL, 0x75D74F0FA068C1E5ULL, 0xF039E4105C517F0DULL, 
            0xA295674220F4522BULL, 0xF07D4545A023A810ULL, 0xECB57835709F0CB2ULL, 0x94B100200EEDBA1FULL, 
            0x4974D6CFB45B6A0EULL, 0xFCF142E5CAF0D9C9ULL, 0x9C190C049456A3A8ULL, 0x995D7383F13E284AULL, 
            0x767A76ACE84C379CULL, 0xC6C265913DF5E022ULL, 0x2106CE3F42FD9A48ULL, 0x61236E3CA16D9C66ULL
        }
    },
    {
        {
            0x3B83FFE195CA7EF8ULL, 0x95D77AA849278F51ULL, 0xA86FEBFEF3FED07CULL, 0x76F89CCE76CEF626ULL, 
            0xD45F94BE06676AC1ULL, 0xE14CF484B3A95297ULL, 0x1FE8E3C34674019DULL, 0x74D54FBE022153ACULL, 
            0x51D919DDE815877EULL, 0xD699B93359F531AAULL, 0x192FE51AC335562AULL, 0xEB681ED68E12B434ULL, 
            0x38FD4AC9CBDACE7BULL, 0x09EEC7D0BE93DF86ULL, 0x76B3C90E5F8C4C85ULL, 0xF22FB61BD7434214ULL, 
            0x39683DD90548935AULL, 0x79770D055DC4BA30ULL, 0xDA5354FE558BA448ULL, 0x14F231340B14CE3AULL, 
            0x9DF8CEE943A32FDCULL, 0x797C6C9842F17B36ULL, 0x6E27ADEFE956687CULL, 0xAFF7438B13848292ULL, 
            0xCE5405C6A17F95FEULL, 0x4DD5F04A9CCDFA40ULL, 0xDE5FF2A97C68A684ULL, 0x4BB9C1459A020D61ULL, 
            0xEC3B2E99209EF16DULL, 0x227EDEB70F6781C4ULL, 0x5C950A9131DAC9E4ULL, 0xE0FB94490538363EULL
        },
        {
            0xEA13E654961ABB49ULL, 0x02913FB0B18075A9ULL, 0x039EA84FDF68C138ULL, 0x7544632F7CCF10E5ULL, 
            0x4B00713C4D47F3E0ULL, 0x00C0111082DFB6B7ULL, 0xDCEBD0438B5E6880ULL, 0x0233E9069483B289ULL, 
            0xEC214F3778B7D4C2ULL, 0xFC63613516D5566AULL, 0x52323229A6CB4078ULL, 0xA3A8A70507CCC449ULL, 
            0x5887FDAD06FB66EEULL, 0xC1A031E4E0CE13B7ULL, 0x8DA08CA29299C8A1ULL, 0x2F9F38175D8334C3ULL, 
            0x14980102F60C7A01ULL, 0x6105C85EBA0BCDC3ULL, 0x64AC445C0D166101ULL, 0x07BC13274A2B61F4ULL, 
            0x14DA654986605849ULL, 0x0D8CB72C8AE71931ULL, 0x911E217BD50A97CCULL, 0x2C0FC7E19BB41A68ULL, 
            0x95D256F836F54FDBULL, 0x453BEEC6A8A8380AULL, 0xA8CF47A1526EA4C0ULL, 0x41B90E0887337CBBULL, 
            0x24219D64A6490A28ULL, 0xEC5DBD48970334FAULL, 0x20763DF6777EA9A9ULL, 0x9D78FD9572695D1AULL
        },
        {
            0xAB2DFF35C27013D2ULL, 0x54CDDA83DB0364AAULL, 0x1A5931ABF4F45BD9ULL, 0x7EB1F719811348A1ULL, 
            0x328B56C9C5D8C8BEULL, 0xCC725A04ADD2D9F9ULL, 0xE63A655FA0BFEBDBULL, 0x51E65BC6D33CD18EULL, 
            0x8BF4F903C4DD48D1ULL, 0xA956651A27D83289ULL, 0x71A0F2EEF734F7E3ULL, 0xD271F307CC69B7C9ULL, 
            0xD2707E3AFEDFF38FULL, 0xA3BFC15BBC7F97BEULL, 0x7539EC53325D9D23ULL, 0x85FA1DD40CBD2383ULL, 
            0xC2640604860845CBULL, 0x3C331AEBC793033DULL, 0x126989226EA5B3BFULL, 0x3C16F1C43FDF3082ULL, 
            0x2401A3C6E11CD8A6ULL, 0x20E6A43CD1C3510CULL, 0xB096268F299B60F1ULL, 0xA10C9E2AE2BE8E8EULL, 
            0x4D9C01CC1740E5EAULL, 0x2902577750C665FDULL, 0xAD94F13703A32317ULL, 0x7C232224571DCB32ULL, 
            0xE97CC12D2A792B28ULL, 0xFB12847B3853A3B6ULL, 0xA7EE011E2A813984ULL, 0xD15148D1E93F814DULL
        },
        {
            0xF890F785E8E49725ULL, 0xC0115C6DA9CD68FAULL, 0x11EF35A3042F053FULL, 0xB369B8AE1A5297E8ULL, 
            0xB5330D8164247C3BULL, 0x77D5929A2E5B30F6ULL, 0x766F8088355941D7ULL, 0x0E71E81AD32440EBULL, 
            0x414EF25080C17A89ULL, 0xD1D865ACA225E0ABULL, 0x565FE370475C4F25ULL, 0x4529ADCB65DCA150ULL, 
            0x5B2C81D862763DD1ULL, 0x2CAD64ED0BA99000ULL, 0x677AD539D87918F0ULL, 0x899DF22EEFB89B26ULL, 
            0xAA6F297F6CDC9477ULL, 0xCBFD7FFCDAC808FBULL, 0x86D125EB8002C25EULL, 0xE222AA25B7B2E0A3ULL, 
            0xF5C5EACFF0753193ULL, 0xEA7364CB1E0A0436ULL, 0x90056DD0E9B93FDCULL, 0xFF9943FDA10E6750ULL, 
            0x807448D1B033C979ULL, 0x9436E02875297F20ULL, 0x69CADA85D264609DULL, 0xA8CDBE12D72965ADULL, 
            0x7FD5D87F799EFB32ULL, 0x4100EECD3E7E4646ULL, 0x41F64BB5FDB27E35ULL, 0x0C5B7336F9A32054ULL
        },
        {
            0xFC8236BD9AA1E17AULL, 0xA2ACE9F0DBC15043ULL, 0x337EF6C7CE9853B2ULL, 0xF38FD20F99D82FBCULL, 
            0x18FCE129335DD012ULL, 0x9F0EEB7BDD4916A5ULL, 0x08877C212830F87AULL, 0xC7DD18E61F439193ULL, 
            0x2E7687E7EBF0E0ABULL, 0x1FD39C8DB32867B3ULL, 0x76F9F4DCB823353EULL, 0xC42403DBDA059C88ULL, 
            0x98EF946A16E49B57ULL, 0x28D2BDB72275E2CEULL, 0x8EE7F25A2D3F54A8ULL, 0xD1B4609C2A721C75ULL, 
            0x824ADB574025527BULL, 0x841EE3CA2D3C8D40ULL, 0xEDF18C86DA96BC5DULL, 0xB54DE30CBAD77237ULL, 
            0x65D53BF5C8111989ULL, 0xDA048BA0E9FD5062ULL, 0x749F07DF2DE0EFCDULL, 0xECC5A0FE4E66E85FULL, 
            0xCE5A2900AD2B4461ULL, 0xD7C371D142E20442ULL, 0x7AA4466EE2506C13ULL, 0x9CCAB97E519CCE5AULL, 
            0xD1D4F1890C82DA1EULL, 0x37C169FDB5E76734ULL, 0x2E6C5BDE41235BFCULL, 0x28347121ED8FA50CULL
        },
        {
            0xF33CC955525B8013ULL, 0x80A55B0FB6074DB9ULL, 0xC9158BE0164ECF21ULL, 0xDCE5933BDB98B861ULL, 
            0x2CBA2D609B4032A7ULL, 0x815A20A115FDB3EDULL, 0xC076906C80249924ULL, 0x8D9D5F05DABD39F7ULL, 
            0x32015B178BC08585ULL, 0x52F6361F514125E5ULL, 0x1A3A39D7C3F4C42AULL, 0xF2B9FFA8B5DDB878ULL, 
            0x75F06A2660596425ULL, 0xC315A26819FC8F44ULL, 0x5249AAFBA4EB466BULL, 0xBAF9CCCDC8EF6E72ULL, 
            0xCEFDA03C3DA1B042ULL, 0x1D797DDDBAD5EA93ULL, 0x74614882B4D414D1ULL, 0xBEC085479EBEB798ULL, 
            0xA97579A15E96A7EAULL, 0xF3FB3979707D7391ULL, 0x15F81369B25082AEULL, 0x4C4E150D44C8A2D4ULL, 
            0x5A71CC98FE9D486BULL, 0xA16D71769A54FEA8ULL, 0xD76EDB3630E56840ULL, 0x3D2DA03342ADA774ULL, 
            0x056D034FFC296534ULL, 0x6677E4B0B3762869ULL, 0x7F2ED0526CAFD00FULL, 0x332F54B4C27A5A43ULL
        }
    },
    {
        {
            0xC7DDEA0D16F53E7BULL, 0x91B7F46F933760C7ULL, 0xBC0B5ED64F52ED6EULL, 0x995BB50EB64BEAE8ULL, 
            0x010F11E2F2A38FF2ULL, 0x7814BD9D3B7C12D7ULL, 0xB2FF708D84F0F4E4ULL, 0x726407F6CDF6548DULL, 
            0x7E041EC852AD5C88ULL, 0xC924B2232A50AAEFULL, 0xF47CA638FD8DD208ULL, 0x003A619DDF4DBB76ULL, 
            0x97342B19045C0B9BULL, 0x66145F60DC89E683ULL, 0xF8DC9DD062FD48BDULL, 0x209B0033B48E06BAULL, 
            0xEEE807F32F1E44C5ULL, 0xCAC154B44EAD5D33ULL, 0x93897A7FD20A7EBBULL, 0xD3EDF8B0BC60E942ULL, 
            0xCBB8518DA08DC11BULL, 0x3346E768CA518A19ULL, 0x5C876BA55DFD1D6BULL, 0x287F3C40CBAC21B7ULL, 
            0x7D6CD8B8D92D1ADAULL, 0xDDE03069E2941F64ULL, 0xEEB0FEB9A8365284ULL, 0x09B46789FC09B768ULL, 
            0x133334C349E47246ULL, 0xB8AD116764689DC2ULL, 0xF0577FB78784CDBCULL, 0xFE2E379A2AA47AD4ULL
        },
        {
            0xAE2DA4114A93262EULL, 0x81273BB4788CC7A4ULL, 0xDDF8AF09FF5F44E2ULL, 0xA569ADCFCDB5191BULL, 
            0x26C7BA4900C6D35CULL, 0x11C7158753E356ADULL, 0x5649F288369857FBULL, 0x2D98A3820490743DULL, 
            0xEE1C00FACCC7CD22ULL, 0x191A74A853C53981ULL, 0x9053F35AB236EA9AULL, 0x67B23DA05B687AD3ULL, 
            0x8B7DEEE3CBC80633ULL, 0xB266BBC71B3023C3ULL, 0x73EC5FDE82875A7AULL, 0xDC32A0A1DBACDC88ULL, 
            0xC6DC38D93BE0D584ULL, 0xF26673D051180BE6ULL, 0xB3F8814FA78EA3F0ULL, 0x549E87D9BD7F73F4ULL, 
            0x8DBFB6F6AE913765ULL, 0xBDD99C113BC87C07ULL, 0x66E600386E71BDE2ULL, 0x73FB58144294DD4CULL, 
            0x4C01A3FCD5FB9AE3ULL, 0xBA5C52AC08C2F4AFULL, 0x12B33B89E132CB4DULL, 0xAECBA0D78D5C7FC7ULL, 
            0xDD4D72AE51A14F43ULL, 0xC641A27C6EB69327ULL, 0xA6B6E62C62D3318BULL, 0x068278FAA3AB65C5ULL
        },
        {
            0xA264EE4AC00167ACULL, 0xD59D0967A49C0319ULL, 0xB01FD4E8921D1915ULL, 0xD2F77F0258F9F70DULL, 
            0x0626BE30673C65A5ULL, 0x5A33B1F10DDA7C6BULL, 0x10CB1E66C0EC9B02ULL, 0xBF492ACB36027083ULL, 
            0x7D855000F12BDCF8ULL, 0xFE8F3C194EE0FD0AULL, 0xFDBB75013602664AULL, 0xA6BB59156734E15EULL, 
            0x2CAFAF47162AE88BULL, 0x21FEA5E36F9443E8ULL, 0x7A50A26495776942ULL, 0xF8ADDD51A78EC22BULL, 
            0xF2204C5A5A77FF1DULL, 0x7D44ED8BFCA15C7EULL, 0xB4892D590E8885B3ULL, 0x2319E0C20C49D3A8ULL, 
            0xD15C1F2F24B4292FULL, 0xD3853BFC7C4B0C4FULL, 0x9F25705BB63FEE8FULL, 0x708EEAAD53FAE605ULL, 
            0xF9908243A91547E2ULL, 0x7FCF6F68FE767BF1ULL, 0x9A883668127BD224ULL, 0x1C3E73AC7E3E1896ULL, 
            0x77E0D46F706A7353ULL, 0x9D5CB364948724F8ULL, 0xB965D13BDF751C04ULL, 0xF7BBD668E17AF3ADULL
        },
        {
            0x977A32DE99B7D6AAULL, 0xAE00B123937E4E94ULL, 0xAE97086D29151ADCULL, 0x4C10A82B83B3732FULL, 
            0xAAD94799CC8ED7AAULL, 0xBA5580F9E778F12DULL, 0x0C560454388AF033ULL, 0x72DE154E0FB8B4F2ULL, 
            0xDB27C87E632719ACULL, 0x7E32F6DBCF8E8006ULL, 0x32913536AAC64A44ULL, 0xB167BCA8FAABA43BULL, 
            0xE098630D1A6B12CBULL, 0x1E2BC34FA636CFFBULL, 0x71455669E5FA9959ULL, 0xEDCEDCDBA3D253C9ULL, 
            0x19F2C598B8ADF202ULL, 0x91A95934F832A075ULL, 0xAE84FEE126BF772BULL, 0x0342FDD4ABE9137EULL, 
            0x6DBB8868A28ECC93ULL, 0x9B54AEB59E85854FULL, 0x19E5983E390E6071ULL, 0xAC8CA9032FCB4DC4ULL, 
            0x2011F9C71938FDFEULL, 0xB1F562409894F8FEULL, 0x2AFB1FAE8A76F8A5ULL, 0x586B49E5710C9B4EULL, 
            0x6AFC5BA8F7457982ULL, 0xA75ADB30F249EE2AULL, 0x63D8EB4FFD01574FULL, 0x7ACEB3444EDA2BFAULL
        },
        {
            0x713E9483DE7F6FE4ULL, 0xE530A3F12939827CULL, 0xD61B1EDB16F84FF5ULL, 0xE91131F5522A340CULL, 
            0x7B38F565F4C5C870ULL, 0x7C76F7D36C8A8008ULL, 0xD76C751DF7977A94ULL, 0x156C54AACFF9AF00ULL, 
            0x4F44672363137963ULL, 0xD021A10777B9016EULL, 0x7D3FC64E083CC98DULL, 0x7D28E60201A52E2DULL, 
            0x8DAD8027474F5070ULL, 0x3D9F1E01BE76E8E2ULL, 0x8277EBC1D32153ECULL, 0x454C94A6152F9A37ULL, 
            0x459D907A99A74D61ULL, 0xB3A99A83645810F9ULL, 0x266C01D275E02A78ULL, 0x087F53C1E50E240BULL, 
            0xEF404565DAF38EECULL, 0x1460DE4E696B9612ULL, 0x5FBD37FEAD752502ULL, 0x92035B8E0890668FULL, 
            0x05C5B747753C94CCULL, 0x957F468F51BD7739ULL, 0x346E0A3E55E9B277ULL, 0xD92745BB2A9901C0ULL, 
            0x2AEA8128122DEC70ULL, 0xC31D12FCD7FFE1BFULL, 0x35394CC20E3C28CCULL, 0x396CC86BE3D430F4ULL
        },
        {
            0xB49E0401651A8F47ULL, 0xE67B72329735AE14ULL, 0x12ABECFACAF4C16AULL, 0xA9D2F0D000C643AAULL, 
            0x02B9A3C77397454CULL, 0x56BB4AA1B77EB134ULL, 0x0C559A3645C40CE2ULL, 0x84EA401FE0160D13ULL, 
            0x87824120B49165AFULL, 0x1EEF97E44DA80FC5ULL, 0xF5EAE8A84AFA5FBEULL, 0x434FE160A2A00610ULL, 
            0x57B18E9D00CF9CB5ULL, 0x23964C1B77B74A8BULL, 0x71BAF49900AFA6B3ULL, 0x3517FFAAF1F40995ULL, 
            0x7E971E2A0185DA29ULL, 0x405E18B759AC7B60ULL, 0xE3FCDB36B2B37C94ULL, 0xBAC36225550CD525ULL, 
            0xA4FF773B366D1C4EULL, 0x839B1D58607C7EE7ULL, 0xBFC65764EDA439D6ULL, 0x98767BD138764096ULL, 
            0xD91336965FEAD5F2ULL, 0x1BA2CA655CD0283AULL, 0x0CB2532530CD752BULL, 0xD84879D71E2B2881ULL, 
            0x02F93E7807A33E16ULL, 0xE01BC3F92CB4F106ULL, 0x22E4B70F7956AE27ULL, 0x0D398C3D8E4CA9B7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseAConstants = {
    0xB87ECB7FEE0E684BULL,
    0x66878898D336ECD2ULL,
    0xAD59EAECA449FF45ULL,
    0xB87ECB7FEE0E684BULL,
    0x66878898D336ECD2ULL,
    0xAD59EAECA449FF45ULL,
    0xF47D0AC7799CFF20ULL,
    0x7E2C6DE157A85F8FULL,
    0x4B,
    0xA0,
    0x8F,
    0x47,
    0x58,
    0x2F,
    0xC6,
    0xD5
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseBSalts = {
    {
        {
            0x8003AFBCE88385D1ULL, 0xA639F98D534AE364ULL, 0x83FFD2D99C05082DULL, 0x1294F5CD0BC06836ULL, 
            0x9CFA4421D45FCC28ULL, 0x19D1E42388FF7350ULL, 0x6BB7C24D2998D573ULL, 0xE113427F845EC70EULL, 
            0x3A4C3B38FA24EDF0ULL, 0xFEB92F770A7172C2ULL, 0xF280C62676E6D507ULL, 0x438803C54023A4E7ULL, 
            0xAC2E490A4BBEADF9ULL, 0x4D49CB0A5DBD0316ULL, 0xFA5BA266BDC33667ULL, 0x2EBD93B2EAEC07D3ULL, 
            0x7424DC34B32B310BULL, 0x3A08B6F0031A6D2BULL, 0x7FF6FEFC78D6FC2DULL, 0xEFB1AE17D8B70871ULL, 
            0xFA1C9675B7914DF9ULL, 0x1D764606AD48881EULL, 0x316C36DB73DD6985ULL, 0x02A80EEE6A61B55AULL, 
            0x25AC510BC033E2EAULL, 0xE0018BB57654C3C4ULL, 0x9ABAF7301608FCB7ULL, 0xF670C84FDC8C08C3ULL, 
            0x3C6199E1A1BF23E3ULL, 0x70F5DFB918F98F35ULL, 0x6535AE630B7C0E5EULL, 0x9206343172D58537ULL
        },
        {
            0x19ACF2FE0F1151DEULL, 0x3130A56918FF1CD8ULL, 0x5701CB07AC5F59BBULL, 0x71A046F2C2291C9BULL, 
            0x7AC9D9FAB226FD62ULL, 0x8341C200E609B1F5ULL, 0xF792DB085164579FULL, 0x72E0AFF7422A03C5ULL, 
            0x99EE139DF93789AAULL, 0xFE0B83183827C69DULL, 0x77ECB85382FBA12DULL, 0x5B1090C08BEFACC4ULL, 
            0x11FEDFE4794E4AB7ULL, 0xE9A733FB3CE8D528ULL, 0xAF53F97F5AF732E6ULL, 0x033F8736EC2E4DBEULL, 
            0xAC8935E2EDFE95E2ULL, 0xB216FFC201F618AAULL, 0xC01CA803D98C5B63ULL, 0x1DB06B35D434C864ULL, 
            0x6FE0E17CCB75F91DULL, 0x4C86558CF908687AULL, 0x08C5C7C02045BA12ULL, 0x0E68A15264C2EF2FULL, 
            0x974E7B28870097E4ULL, 0x060CF2F6D95DCD4DULL, 0xAC717C45809F71DCULL, 0xF470980AB480E9F3ULL, 
            0x5E072D9F568C269BULL, 0xFC4D80CDDBAB66BCULL, 0x83095BB12660D215ULL, 0x53A23823BE03A6A6ULL
        },
        {
            0x868043D85C2D10E3ULL, 0x01E29AA0CBE5109CULL, 0xAC1DE8C5770FB9A5ULL, 0x226CA113EE280241ULL, 
            0x6603A88C9CFE528BULL, 0x9DA5686256A88C1CULL, 0x67E810396C3438D2ULL, 0xA06BCD017A483CBAULL, 
            0xEE5FCDDD028AA8F3ULL, 0x2689A74CFA00DEE6ULL, 0x3C91C448E8DBF207ULL, 0x81F3250670227B50ULL, 
            0xED37CFD88ACA9BF3ULL, 0xB547E0F837F6152FULL, 0xF2D8F05545C1A0EDULL, 0x9EC4837D38AE02D6ULL, 
            0xDA65E02B0EE0445CULL, 0x895B8AC5D7BBB32BULL, 0xDE93D207E5B3F7C4ULL, 0x9A73A25B86923810ULL, 
            0xC4152A590A9646A9ULL, 0x50335BEE8F68BCDBULL, 0xC8A299573E1BEF20ULL, 0x2438F7E95720BD90ULL, 
            0x116D3F2F5432447BULL, 0xD372AADE6CBF8C25ULL, 0xCD6768D39CF41377ULL, 0x1E750FD82B350895ULL, 
            0x316F966BB508707FULL, 0x061426A0C7D3B90AULL, 0x03A8FA8DF7EEB13EULL, 0x9E9B65BA98B08A5EULL
        },
        {
            0x7E699B1491DE77C0ULL, 0xEF9AB4FEE7912286ULL, 0x9F879438DD141F88ULL, 0x3C994E39A16C67C8ULL, 
            0xE14E0BCEE3F0BD14ULL, 0x19E9675800FBA9DFULL, 0xCAF15C23B69328F6ULL, 0xC41C22D83955D0EFULL, 
            0xC7134984EFD7A9C4ULL, 0xC459C37244AEE8C1ULL, 0xE79BE252E22A0A93ULL, 0x574712B7EC46B21DULL, 
            0xAD5C7493B4FCD56FULL, 0x70E94BA28B107724ULL, 0x0F015BACE47AB0AEULL, 0xE57FD7D1CE1EF2A3ULL, 
            0x2ECE8C71BEC485A6ULL, 0x722FFDF48B1BE7A7ULL, 0x0776B854727C1989ULL, 0x55B7CACB6615B096ULL, 
            0xE23F46DD08D00A28ULL, 0x940BAF7AF562A2EBULL, 0xD16E3DFB42AC8385ULL, 0x8406198288178DF6ULL, 
            0x548B83FA2CE87541ULL, 0x66964C15055FB8EFULL, 0x335D5D03E9673642ULL, 0x1DE0C5D519F2E7C4ULL, 
            0xE734DFCECC800BB6ULL, 0x20F2396601C20302ULL, 0x9923081AE0D716CCULL, 0x085C674230FA604BULL
        },
        {
            0x922007214AF1A4E8ULL, 0xF80EE7F8F891C99BULL, 0xE39134933F9449B7ULL, 0x93FD3A1F99A4B431ULL, 
            0x9C8DDD2DC77059AFULL, 0xFED494B23F33617EULL, 0xABCBFBA66452F1A8ULL, 0x4570383452CB2C67ULL, 
            0xA4AA7939DF7D1DCBULL, 0xDED124F9682F42DDULL, 0x179C0983329F2EEEULL, 0x1C376EE2A63C46F7ULL, 
            0x3D29360BCCACE944ULL, 0x2B14C0F29F164D05ULL, 0xBA0C17E0347FBE9DULL, 0x86D77476E6C6A1C1ULL, 
            0xE3FCBFB685A64090ULL, 0x48B6BA2DF232A134ULL, 0xCEC139717263B544ULL, 0x91B707C6234C2FF7ULL, 
            0x68309E72D943E9E5ULL, 0x0236DC9D75FDB5ACULL, 0x7BEC54F7A9E63C8DULL, 0xCD7F0A2470513186ULL, 
            0x6E30A72CC155EBCFULL, 0xD43A0BFA128A65EBULL, 0xBC9F176A009B8A7CULL, 0xDA3597EAFA3204EEULL, 
            0x836BCAB6A3D692A0ULL, 0xE6C498D7B4837834ULL, 0x1A67EA95CB3F9FDFULL, 0x86A09E7AFA9E9F77ULL
        },
        {
            0x8A42C1A55AF4402AULL, 0x1A88EF9B0D3395A2ULL, 0x8800A66B9B3A7331ULL, 0xDF896C8FB077F089ULL, 
            0x7DC4744B13D62563ULL, 0x8A5C895B3BEB2631ULL, 0x7E1522B7840BE39FULL, 0x21D829E0D65509B3ULL, 
            0xCF25F0FB75CD4CABULL, 0x16A9980BDB379B4FULL, 0x4C2FDC26CD567B8CULL, 0xB91C17706A8488A8ULL, 
            0x015E7E9F1BEBC4EEULL, 0xA98C8DDC3D81FEC5ULL, 0x0CC70A449EBA1368ULL, 0x24DC2CECE227387BULL, 
            0xE8C63173EF443869ULL, 0xAB30A17D4906BA6FULL, 0xF401B896E472C0A9ULL, 0x37E8CC6ADE3FEFE6ULL, 
            0x496C3D46C566178AULL, 0xA3F065031112CD7BULL, 0x53D1DD29603F8D11ULL, 0xC1033B8CC309351EULL, 
            0x05BA4DB2ED3F49B4ULL, 0x8C7C29FAD5668594ULL, 0x0FB71A38C1F5E7C9ULL, 0x234AA7FFFF83AB60ULL, 
            0x7568B5B4E3BC7997ULL, 0xBBA54A34E187B262ULL, 0xA22997467490DDEBULL, 0xB963F17E1D2C33FCULL
        }
    },
    {
        {
            0x610D75A63398F34BULL, 0xF2C624A5FE888F27ULL, 0xCF9B7B9D65984914ULL, 0xB7003629451EA720ULL, 
            0xCB443C39F79769E1ULL, 0x420C9F4A30A0DFB0ULL, 0xC93C849A1DAC6E9CULL, 0x57B11E28A13EAC5DULL, 
            0x0B0E9C977BDFB911ULL, 0x4345D46C79521A00ULL, 0x2613232EC2729451ULL, 0xFBBDECBD413B4880ULL, 
            0xB065798F00433BC3ULL, 0x657B472FEF5D6B64ULL, 0x3A54D09D2B29FDFBULL, 0x56673C4ACF3CC02FULL, 
            0xDD437E7322798259ULL, 0x0A8A4ADD380CEEDDULL, 0xDB9710A63BA9BA00ULL, 0xA43B75472A41FCCAULL, 
            0x3BE43F2BDB608149ULL, 0xF01A18A424FF3CBBULL, 0x909B772D93243DA9ULL, 0xB5B12810AC24EAB4ULL, 
            0xFEEBFFAEFC14AFCEULL, 0x97363BFBA6BFE0F8ULL, 0x22E33BF6CCEE90F9ULL, 0x808E66E310A7C3C8ULL, 
            0xF8D8BFD46FFEC07EULL, 0xC80F32E988C36603ULL, 0x76D301CF8C49EE72ULL, 0xD284CDCFB50E4EA9ULL
        },
        {
            0x1AE25A6E79E5ADBBULL, 0xB63163DD31C86809ULL, 0xD9502FE0FA5A30C8ULL, 0xCBB32C2AE6F748D8ULL, 
            0x20FA51E3922B43D7ULL, 0x5D35AF86D0EBF2DEULL, 0x856F0631F145EB21ULL, 0x85F3C55BB027BA13ULL, 
            0x473A624B305A874FULL, 0x1348942621F3D4A7ULL, 0xB05E39987CA8BF12ULL, 0xD472E170B51B4F76ULL, 
            0x25A952BE74CD46C0ULL, 0xD4F04DC0A409E20AULL, 0x238B62EC94A7686CULL, 0x2A2C2DCDCF3C282EULL, 
            0xF1CE7445F8BF1D16ULL, 0x1B085E3E7C0C487CULL, 0xDB242F4A0ADE05E1ULL, 0x9551B38FF6EE60A8ULL, 
            0xE7DE9BD88E00EABCULL, 0xA31F112F5691F83CULL, 0xB62CB22D69D46770ULL, 0xEFD7F7718ACF9393ULL, 
            0x80553A0158A8D8C5ULL, 0x8B96C7736745C1A0ULL, 0x2791A047FBD08DFFULL, 0x4B34D35B3735B192ULL, 
            0x62E92FC992967388ULL, 0xDFBFEEF5710BFF01ULL, 0xAD2CDAFEB425AABEULL, 0x24ECD2463DD5097FULL
        },
        {
            0x74D4672EFFC0A479ULL, 0xD18353ACD262A2BDULL, 0x19F7C78C4F4A5017ULL, 0xB917F106A96B2C65ULL, 
            0x103403BCDE365D81ULL, 0x77379CBF115BA4A2ULL, 0x01BCDAC2482E184AULL, 0x48158E781BAF7922ULL, 
            0x0C5C4AEB48D905B7ULL, 0xE0920C61FE75A7E9ULL, 0xCF493D6F644E8228ULL, 0xEDECEFF68135A78DULL, 
            0xBC4A1A01A9B04BB7ULL, 0x149197AAEE1D11AEULL, 0x3C25494475CC34C9ULL, 0x98DD31C3E45958EBULL, 
            0x89FC06112CDC52DAULL, 0xD993309C00241FF8ULL, 0x054E7B89E47B3DCEULL, 0x114DC3A1B1BD13DBULL, 
            0xD11868735B092C52ULL, 0xCD2BF2217C6C0F29ULL, 0x7C8A20A0590F060FULL, 0x91D0A10FDAF1624AULL, 
            0xECBFD136F09C72D6ULL, 0x71B9FABE70E49B2FULL, 0x5F4C533A4A280015ULL, 0x8A4BFA938E4C2461ULL, 
            0x0BA6A8EA52652482ULL, 0x225972463B0B962CULL, 0x221F1E27BCF9622EULL, 0x06C005C9229E1960ULL
        },
        {
            0x24B601994C4EA590ULL, 0xC43D7426E98E3EF4ULL, 0x66117D465B83861EULL, 0xDD6FD3D5369A3966ULL, 
            0x8C1ED8C41FBCDBBBULL, 0x78138B82EAE682D3ULL, 0x181DB82978E20A28ULL, 0x1C81890EB7814119ULL, 
            0x33E838D2EDA72FCEULL, 0x6FB7BF747BCC8243ULL, 0x474F0CCCF691F02EULL, 0x0D5EABB1E244D03DULL, 
            0x4658FEACF99606C0ULL, 0x795E90BC98673C04ULL, 0xA4C5C0FF63F02FF7ULL, 0xFBDF087A504BB3EDULL, 
            0x1D0EDD2DEC9F8BD1ULL, 0x18BC19DB6C6E203CULL, 0x2AEB3A0BCB86685AULL, 0xB861486806D88A17ULL, 
            0x52AEEE9D393C192AULL, 0x283DD6BDFE967D84ULL, 0x3DD52753A7281AA0ULL, 0x2F879C88CAC9E9CEULL, 
            0x815C81B6E16FBBD7ULL, 0xBED9BEBFC0FAB9B4ULL, 0x76CA072186FE6BA7ULL, 0x2616FEF94BE9E203ULL, 
            0x34E6EE17378657F3ULL, 0xA64965D80076C114ULL, 0x1E7FAECF9D9E5650ULL, 0x4378E770C5106B01ULL
        },
        {
            0xC2D11D91440F544AULL, 0x8B0A0D1938D48DCAULL, 0x5CA790A8135C7F51ULL, 0x70607B796DEF006EULL, 
            0x8C76FFBD43957C30ULL, 0x027F2DF74D52E673ULL, 0x79B5F391C355A9CFULL, 0xB7C9D9EB59D36D75ULL, 
            0xBD8DD5F0C8E2C424ULL, 0xB8E104C53F4A349BULL, 0xAC170780CFFE41EFULL, 0xFD38E2953CBB3AEBULL, 
            0x6AFAF741A3F4FA60ULL, 0xE55092D40FBAE194ULL, 0xF65F4824E2309B0DULL, 0xC306EE0603A30213ULL, 
            0xAE887E4A188C7685ULL, 0x72CBB258F19833AEULL, 0xC5BDA5C9E2D89BE5ULL, 0x5D1A63B9CE893612ULL, 
            0xE8934511E13EA996ULL, 0x74B15DEF997C8F4AULL, 0x3C7934F871C5D769ULL, 0xA3B2514B9B32242FULL, 
            0xFDD15799F9590B88ULL, 0x0EAE02AEC92C923DULL, 0xEC4A32A2F57A5324ULL, 0x4704C29F37A36CC3ULL, 
            0x370DA9E5C18473BDULL, 0xC3FED5526ECC067CULL, 0x2F3D0B823CB4322AULL, 0x5466534E8052A7CAULL
        },
        {
            0x81417007067732C5ULL, 0x3D4ECBCF50AE01B6ULL, 0x4472DB7231CF45B7ULL, 0x350E329695B06F80ULL, 
            0x1F7D0E52C6A7F85DULL, 0x62EB59225EE60AC1ULL, 0x62F1548F204D9B15ULL, 0x0D5A3CF9A19C3426ULL, 
            0xDAB576770C032479ULL, 0x831DD71C252A8337ULL, 0x39D776EDDC196DADULL, 0xC553F6EDC012AF67ULL, 
            0xB91EB30969E0B0FAULL, 0xB2359F8BA95C3721ULL, 0x158F411CF58CB1C0ULL, 0x6269CA82E86B1516ULL, 
            0xCD8BFE90E23A1A97ULL, 0x61286D7441F77BBAULL, 0xC0F1F39E53ABCD1BULL, 0xB46733D6E611AC4FULL, 
            0xD558C41B3FF2E0D6ULL, 0xFC2CFE2A21518BACULL, 0xD0B41429A5549472ULL, 0x9CF9FCBB62313F55ULL, 
            0xDC0FCB8794252C59ULL, 0x0BDDBFA8CA82E714ULL, 0x73BBF08DEE32ACADULL, 0xD38D66D48FD01D4BULL, 
            0x75A74BEED8CA5FABULL, 0x4EEA5D84581BC951ULL, 0x3CB459B79FDE5DDCULL, 0xEEF67551EE920A69ULL
        }
    },
    {
        {
            0x52116CDFD8B10BDDULL, 0x72CB93ABBD093A07ULL, 0xF448795B434D9B08ULL, 0x26113136907D3875ULL, 
            0x3B7DE21CCEC74976ULL, 0x02D4A1E77B8AB9B2ULL, 0x2BF7237ED9FF0EB6ULL, 0x4D96182C40D44C29ULL, 
            0x42DF115780B146A7ULL, 0x356A8C520C7FAA59ULL, 0x2793B15BEE66661EULL, 0xE882EBF6ADA6DA3EULL, 
            0xCD6FCC7DB5D1EDDFULL, 0xDBEA161DF9AD17C8ULL, 0x2F4FA5CC0685EFB0ULL, 0x7AA15F8EE58D62FCULL, 
            0x5977A766199B87EBULL, 0x27850CC71829658CULL, 0x431D1C92C6E3F70AULL, 0xA12771F3034021C9ULL, 
            0x76DED4EF23BDB5D0ULL, 0xE1FB81D1C00AAD61ULL, 0x61B4111962731A34ULL, 0xD380EB933BE21307ULL, 
            0xB866EA554555235CULL, 0xDCC7904E5F7ECE62ULL, 0x088206CF0EA0449CULL, 0xE09B134518674802ULL, 
            0xFE0C1383CFFF685DULL, 0x97DBF33E36660B5DULL, 0x789C768E33FAEE3AULL, 0x8848D7AB8A6DF72BULL
        },
        {
            0xCE0951D83E78D1BCULL, 0x99D9FF1DAAED2ADAULL, 0xEB2B55DB6A76512AULL, 0x89993B5482727E36ULL, 
            0x2D2A02E4FC25FF15ULL, 0xF835156D83C1E9C1ULL, 0x286D750A782FE246ULL, 0x2423C7C632947160ULL, 
            0x9261FEEECF6979E1ULL, 0x29DC5DB58184BB87ULL, 0xA1DABC52C05146E8ULL, 0xA3952AD62A7AC06CULL, 
            0xD2C1DEAA92776B82ULL, 0xAA6D186B069B21FAULL, 0x6EE717F9701ACD72ULL, 0xD0E9634FD5D40F0EULL, 
            0x6B4F22D1B9D5A930ULL, 0x64B181F23B0C02E5ULL, 0x38410165F2344B5BULL, 0x8C573187DEAF33CCULL, 
            0x1DE22D49117A08FCULL, 0x01206E6C0A866D38ULL, 0xDDA0286D535ADCF7ULL, 0xF2E7315D44F593DBULL, 
            0xEB88BB45BAA88FBCULL, 0x3DCC91894B169BB1ULL, 0x9CB6AA840F476899ULL, 0x9CDBFBC2DE270208ULL, 
            0x2BB5E256502145C4ULL, 0xB6472E6204CD2804ULL, 0xA6D9B0309C72B40AULL, 0xA98111D472DF576EULL
        },
        {
            0x842A849487973B37ULL, 0x42BD1C7ADF8F8F1BULL, 0xC760D386B18977D3ULL, 0x4E94009A51B4A68FULL, 
            0x9321A1694752DCACULL, 0x58FE25280762ED76ULL, 0xFB0939F3EA088A5DULL, 0xB1DBE9C5609FD076ULL, 
            0xE285939A8FEB86A1ULL, 0x717839096DD623BCULL, 0xDC8BD9F9152030ABULL, 0x0B5BA1D6A2DAB88CULL, 
            0x2B86D1284E931B98ULL, 0x240C2A40C85AB517ULL, 0xF73B9FF19A67177EULL, 0xB880E4B3E0C59DC3ULL, 
            0xEC5235C5F02CE645ULL, 0x305568A916FB5E09ULL, 0x460F706460A04917ULL, 0xEA28DB9E2E8A3B44ULL, 
            0xF2A895F2324226DCULL, 0x5FB45B2CB8726E55ULL, 0xEA406368C3A14C46ULL, 0x4D56458174E06093ULL, 
            0x16D2FD4B87B227D0ULL, 0x84DC2D6C5A505C23ULL, 0x866B7D07013C9E24ULL, 0x25875C14E8AE59A6ULL, 
            0xB84F8F0FC01A72D1ULL, 0xB810DB03E083D5A8ULL, 0xE09D4CDE5647B151ULL, 0x036C2D6D524C919EULL
        },
        {
            0xD24D0624075470CEULL, 0xA46A7D4EC9400344ULL, 0xAE03F883C5C81436ULL, 0x3917712B74B34DFEULL, 
            0x330E6F672D127BE0ULL, 0x0B3D05C076523E71ULL, 0x33FE8273B9A0EF0AULL, 0x0E8758FC8E8830D1ULL, 
            0x2766B1316AC19966ULL, 0xA73A1CA6B6FBAE2FULL, 0xF08017E702B18336ULL, 0xCEF8627B600B2F93ULL, 
            0x4BE76691A325A272ULL, 0x65F56794EEE0D862ULL, 0x977C04F35875403FULL, 0x92059EACF52F8751ULL, 
            0xD42A19B1641A219FULL, 0x5DFB704A9023C489ULL, 0x697670D38424766DULL, 0xC47D73B8CA398995ULL, 
            0xF4C640A3603700D6ULL, 0x8859978F6D7AD061ULL, 0xBA4EB92C9B03878AULL, 0xD1EBAF540FEC78B5ULL, 
            0x09D74DAEAB44FE6AULL, 0x02A9986479D4DF4DULL, 0x290A69F5F8BE2177ULL, 0xE9F07805EAC63C3EULL, 
            0x8E7665652E621A3DULL, 0x4232541493C9062CULL, 0xF789CE909359BA34ULL, 0x36173E8013AA5DF2ULL
        },
        {
            0x48864330F0C7C59EULL, 0xBC583105AAAB7954ULL, 0x33B7424B93211437ULL, 0x885F656CE4F444B9ULL, 
            0xD8CA00757C3563ABULL, 0xB7644A1E7DB39C8CULL, 0x23C7FE9213D54FC4ULL, 0x8BFD696987EF88ABULL, 
            0x8926E8961FA59D44ULL, 0x67AC5C064B3469F5ULL, 0x929B383C0FEC17E7ULL, 0x5F3D778FCCEE8944ULL, 
            0x20EC5FFCBF8E2A85ULL, 0x374E26CD3E4C3C84ULL, 0x8D6171ECFAD98FE9ULL, 0xB761023FF1B24A85ULL, 
            0x97DB6861523EEFBBULL, 0xA46AC84900A4766FULL, 0xACF32C6C0FB4667FULL, 0x53C43E9C603C8830ULL, 
            0x2D6C175F846BEA75ULL, 0xBA44AF5349B25873ULL, 0xBF2B397DBC5E91AAULL, 0x444FE9012FBFC8E7ULL, 
            0x4CAD5BBE7EA84042ULL, 0x3903DF9AB904D4CAULL, 0xCE565639E233B1F0ULL, 0x5B62CF4E3EE7CF83ULL, 
            0xA8CE40F48A3AD46CULL, 0x3C031A4C75CCDB05ULL, 0x769926E6E1609D55ULL, 0x4B637F59EAEFE027ULL
        },
        {
            0x648EAADF93E613C3ULL, 0x2E42444C1C576ED6ULL, 0x9769DF610A559682ULL, 0xCCC55A2C92601CEBULL, 
            0xEDB6F43F941EBE77ULL, 0xBEAF84458A8F36F7ULL, 0x02A3CA2432B728D1ULL, 0xEA760A7E8C73508CULL, 
            0xA4B49F7531FDDF37ULL, 0x9EC78987B969C247ULL, 0xAC43AA23F16B5B78ULL, 0x776747AAB6948E11ULL, 
            0xDDD6D3392552E9A6ULL, 0x834F15B7ED5E4DD4ULL, 0x725B74504E502689ULL, 0xA346E386524E65D3ULL, 
            0xEF99FD5E790F3E4AULL, 0x340C2C96EA381E8CULL, 0x28D98F3EDDAFD4F4ULL, 0xB202F299EB28F9F8ULL, 
            0x93DBD0E9D06C316FULL, 0x3AFD5794E2455419ULL, 0x61B25C851E8248B3ULL, 0x462416E6731EFE9BULL, 
            0xEE14B9ACFBC77DE3ULL, 0xDF86D6D5B4BDFB0CULL, 0x3537D5F714E4F992ULL, 0x0596BCE9ADDA6942ULL, 
            0x6B26DB2A86785293ULL, 0x58FFCBEB01EA6B4CULL, 0x08723978CE66D3A6ULL, 0xA70D02EE176784B3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseBConstants = {
    0x364573C5D196D77FULL,
    0x2646D59661D2B0BDULL,
    0x485AF7A9F8B638CCULL,
    0x364573C5D196D77FULL,
    0x2646D59661D2B0BDULL,
    0x485AF7A9F8B638CCULL,
    0x3BD3DED7B824DE1AULL,
    0xB4BE3B03C7795C21ULL,
    0x3A,
    0xF7,
    0xA1,
    0xB1,
    0xFC,
    0xFE,
    0x50,
    0xA4
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseCSalts = {
    {
        {
            0xB5191878BBEE3661ULL, 0x739AA8D0C674AE58ULL, 0x5931F65FD9AB2D97ULL, 0x2A2A740E994A9128ULL, 
            0xF0176ECBBEAB12CBULL, 0x0EF5623783D08717ULL, 0x4C113A523FA78884ULL, 0xFD24A6C20372DA15ULL, 
            0xC5C44D7254F49855ULL, 0x12F924F1AF021997ULL, 0x2BA4878C1D28A243ULL, 0x83CA8754AE5A61ABULL, 
            0x5BD61D45AC25F7F8ULL, 0x46632BD5849307D3ULL, 0x553F6EF9511B6B23ULL, 0x5467EE37616EB700ULL, 
            0x7D0FC1FE45ECFBF1ULL, 0x161367DE9E1C14C1ULL, 0xABD77E16416EF213ULL, 0x316F296262B5E57EULL, 
            0x3D59229F56F680D7ULL, 0x2D067A9BE98D8791ULL, 0x73478CE84859F308ULL, 0x0DA97B46F8FE312EULL, 
            0x5EB8404275368CC4ULL, 0x4656CB97C2F4D5A0ULL, 0xBC8ED7DC14C3911BULL, 0x9346E26BA642FB0FULL, 
            0x8C1463718E70E6D9ULL, 0x8FE44BA35BDDE84CULL, 0x1500448A1063CC59ULL, 0xF0B2A8A08300AF30ULL
        },
        {
            0xC197C2F0C12675B2ULL, 0x29AB0C2132E1E420ULL, 0x6EF9B6816E400122ULL, 0x2852BF06800A6250ULL, 
            0x0C40EFCF780DDCF8ULL, 0xFFCBA0F3B3589E83ULL, 0x14527E2E011D6013ULL, 0x02D1D2E8B3B96DBEULL, 
            0x51F9E79E17C30E72ULL, 0x0D6D5F480AB9AB29ULL, 0xFE546F85A289460CULL, 0x704ECD827498EDEBULL, 
            0x9C8255994312AA86ULL, 0x9894CA45040F7796ULL, 0x8DE55D745E5D1741ULL, 0xA8C22A3F98978A1BULL, 
            0x2DF2EAEBA8CE055BULL, 0x1F33CE847FC2C4DDULL, 0x24496AD0173DCD07ULL, 0x1BF12B1C30398F07ULL, 
            0x6425374054E60A60ULL, 0x115804F4D78B00DFULL, 0xE1F1B735B1F0692BULL, 0xA5DFB40E276C6A29ULL, 
            0x2C655FB196143400ULL, 0xC5D89AA317D4D3D9ULL, 0xCD7CC5CE6550157EULL, 0x8AA9814F0DBB940FULL, 
            0x4E1913297DEDCF3BULL, 0x84F2C61CC4047CD4ULL, 0xC6522FDC6BD72789ULL, 0x43D4FAC071FDA6EDULL
        },
        {
            0xAA4342245FD014B2ULL, 0xA76DB9C7C84DE6A9ULL, 0x2FC7BDBA8B384AE6ULL, 0x610375A6E3466953ULL, 
            0xD9F334F01C8332C0ULL, 0xFD39305BED4270BDULL, 0xF3E87361BF0C7A19ULL, 0x7FBDF772EA912144ULL, 
            0xAD4F938121DEF3C4ULL, 0x99A2A0AA47763366ULL, 0x7939A1F5912D7F35ULL, 0xE1C1BBF0A4C1719FULL, 
            0xEA0D14FD361CD12DULL, 0x61DAFC4F3707CB19ULL, 0x5FC1DBB2C827FF5BULL, 0x6F010C64C610650CULL, 
            0xA0A16D07695FC6DFULL, 0x14405AFC2885187CULL, 0xDFB33EF0D745A0AAULL, 0xC75042D7224B6AFFULL, 
            0xE9FE4E6D551848D3ULL, 0x9DDBC9F6BBD41933ULL, 0x752D0B3D69A31AA9ULL, 0x7BB2FA41AA92BEE4ULL, 
            0xF9080620E2F93DF5ULL, 0x32600B337A3D09EEULL, 0xAD1226DDB37B3C2DULL, 0x3FB322D9F8C80E9FULL, 
            0xDFB6D06D1E246D05ULL, 0x94A7C3157B742A9BULL, 0x95E34AE6098F1BC6ULL, 0x5C1977F5A1CCC6D7ULL
        },
        {
            0x2A0B5D4DF8C1C4E5ULL, 0x7FF004086B1C7587ULL, 0xE417E0F413B5E6C7ULL, 0x0989E049D9C3D790ULL, 
            0xD408AE89B28CE11FULL, 0xFBBC64E65DD626EDULL, 0xDB5CAF9C0D3C4E71ULL, 0xB790329B67D43FF6ULL, 
            0x40BA102320822FC5ULL, 0x64974A9E795A8ED8ULL, 0xDC48FA2731A1BB26ULL, 0x841BC28F34998289ULL, 
            0xDB98380ED965D17EULL, 0xCFAA3F42B52A8357ULL, 0xD395D4E60D685F10ULL, 0xC6C81EA271A52409ULL, 
            0xC354239A01C8DAF0ULL, 0x02EC9826F30B701CULL, 0x1FFD2D0C848050E1ULL, 0x7C4669982CFC9B4BULL, 
            0x112310B09D1AFA18ULL, 0x44889D1D97C1CA7CULL, 0xBB8B1AAB8DE44A0CULL, 0x8FF23A6C754C784BULL, 
            0x46D32B91F62CE7AEULL, 0x76D03CB35486B7D2ULL, 0x02EA6A90B57EF267ULL, 0xC07EC238A444133AULL, 
            0x2B9FBF0277ABD6A2ULL, 0xE6D6A1988C4CC367ULL, 0xD146A426748C8FB9ULL, 0xBED4CA22844A41DDULL
        },
        {
            0xABCFAF7E29F1F4BCULL, 0x5E4EA6A6A208CC56ULL, 0x42832BF8AB393819ULL, 0xF1652AAF0B55EBF7ULL, 
            0x3781E8A36B58D6D8ULL, 0x959D12676A9716D4ULL, 0xCAA161C3067A72D8ULL, 0xD2ABD2C1E18F6E4EULL, 
            0x16AD7844884DDE45ULL, 0x8A8473D7A86E6092ULL, 0xC763232B2A92D5D2ULL, 0x081079B2D0F54F76ULL, 
            0x51B1041221A064C7ULL, 0x2C0F7B8F88A159B0ULL, 0x728A7940B6608E8DULL, 0x789F74527D2DF974ULL, 
            0x0268D636563E1181ULL, 0x5901CAF0ADE69D67ULL, 0xAAC2458A37597353ULL, 0x97A81A27B684B206ULL, 
            0xCDD973867C2108F9ULL, 0xE4B45AB5B4B2909EULL, 0xDA07E2535B661316ULL, 0xA7FF449F17DF31E8ULL, 
            0x3B602BF8BD207AB7ULL, 0xDFA38B2E693E7323ULL, 0x712B73D90271301FULL, 0xE3D48EF9F8D10D08ULL, 
            0xFD37F44B71421D58ULL, 0x58D3F0DAF4C5EC49ULL, 0xB1D012F498863001ULL, 0xFB5F845424B6F2D1ULL
        },
        {
            0x6C07A2F7F1C331B4ULL, 0xED8AA22197D8C3ABULL, 0xFBBCF63D1512A601ULL, 0xB489167803975A60ULL, 
            0x69810AD90C33179CULL, 0x03DFA392A3EE98CAULL, 0xA4D2C8ED35A4EC02ULL, 0x13D17A75EA992123ULL, 
            0x3F38556BA88BA4FCULL, 0x02C2D970DCB22823ULL, 0x36CA1045412A1656ULL, 0x696F12404C176D03ULL, 
            0x1DC0646387F66B53ULL, 0x34FDF7A162E9094AULL, 0xD75C2F6C9430BD2EULL, 0x33214719545960AFULL, 
            0xFE60034DA2C6EB79ULL, 0x680799D1CC4A4CAAULL, 0x4EBEBA24665C08E4ULL, 0xACF5BF0B62F148BAULL, 
            0x2B38EA0288CE883DULL, 0xF9C9CD2DFD04934FULL, 0x35DAE3AE1E09E4A1ULL, 0xF7295ED2ED98C38FULL, 
            0x6228F80F6DE37BF8ULL, 0x28547851A0A72994ULL, 0xB2EFC6DFCC026E2CULL, 0x54DE9D3D2AE1D7CDULL, 
            0x553B7111DEB2A68DULL, 0x3F7CCC24A023F838ULL, 0xC13081DEB933A3BDULL, 0x5BB871353FB3C93DULL
        }
    },
    {
        {
            0x60BC28CDC8536F4BULL, 0x1F4566D03B76C0CDULL, 0xFF34EE6EED0BE2CBULL, 0x47AB6B7085203928ULL, 
            0xB745A2E53735BAF7ULL, 0x4C1E895F05E11402ULL, 0x7D3431ED15D04613ULL, 0x2535F7E2B29C0916ULL, 
            0xA114321E3831947FULL, 0x7CBE4880D377CF86ULL, 0xBD48A03E3DC17A9DULL, 0xD477F380489CAAA3ULL, 
            0x595BEFC4309A4C61ULL, 0xE511AF64D337BF38ULL, 0xA667FE05A9BCE3BFULL, 0x3A7A123C2FA467F1ULL, 
            0xAD95A4CB150B43B9ULL, 0x1004944AE7DD6E83ULL, 0xD0F641C28859ADFDULL, 0x23132E0B8BA09C9BULL, 
            0x56B59B589B3B94D9ULL, 0xCD25E119DBF5D45EULL, 0x617161BFB9A97861ULL, 0x8954529ACF5117B6ULL, 
            0x8F47494623953C34ULL, 0xB671BF02CC3C82B4ULL, 0x98CAAE84D518E4B0ULL, 0x8C7EBE5078883EF3ULL, 
            0xE33AE6799539E4AAULL, 0x5CBEC479452E19B0ULL, 0x550A1141052270BAULL, 0x4A0AFC160F506A46ULL
        },
        {
            0xFF86DC02D4A8909CULL, 0x2E32036634B4F221ULL, 0xFD04631F7B59300BULL, 0xFCE04E85EBE7543BULL, 
            0xE2F3732127B6317EULL, 0xE11EF9B51D15C364ULL, 0x501F0A242955E1DAULL, 0x673DB091C2EF091FULL, 
            0x5E1CA3E89C3E7764ULL, 0x72CA212C9F3BF347ULL, 0x74C98DF45E79AA8EULL, 0xE57ACC40C0D6507EULL, 
            0x526F8E793BE08E7BULL, 0x410A825E0CEA40A5ULL, 0xC4C7476F1B221EBEULL, 0x35287AFE74491DD1ULL, 
            0x636E98266FEC6EA7ULL, 0xFEE51A29E9D0B8D6ULL, 0x86C71047B6D0C57CULL, 0x5CCAD45F901F8803ULL, 
            0xA30F1E042B6C77F0ULL, 0x753352BB7F1DA48FULL, 0x7894FFAC9B359F73ULL, 0x7E3426EB0EF8C1EBULL, 
            0x563153D5982AEC2BULL, 0xDC6351EDB3D2F33AULL, 0x29B985FA620A8041ULL, 0xE96611C70272B828ULL, 
            0xB3B0698B030B052DULL, 0xC6790CC3EDBE549BULL, 0x715C18F7E75A5464ULL, 0xAB32E8AAD3D42905ULL
        },
        {
            0x01A4827910474CB3ULL, 0xCF2E87AF31DA66D0ULL, 0xDBC2859DE43E6B09ULL, 0xD0647C387908C469ULL, 
            0x2CC42E2BF9DBD877ULL, 0x3A6D1C6EF2139A95ULL, 0x29D48084EF0800FFULL, 0x37F8B0D27425EF8EULL, 
            0xB8F390D047C73848ULL, 0xEAC9ED89C38D1B91ULL, 0xFD6C629CBBB4F54BULL, 0xA773C7C36945D002ULL, 
            0xF8BBAAC9E092C1E3ULL, 0xF8B1728C46B4CB49ULL, 0xC20AF278E2A3DAAEULL, 0xD8F131A68C1A80B3ULL, 
            0xBD19A6DC031A8573ULL, 0x12E2B856C178FF33ULL, 0x670AA6C7650243F9ULL, 0xEA84F78D14B48081ULL, 
            0xC6C7A546FC6CCDBBULL, 0xB8900516769CF652ULL, 0x2A8A590F74DD7B5DULL, 0xACE218FCD2FAE652ULL, 
            0xD4659E476EA32912ULL, 0xA4EBEB575C1CB0A1ULL, 0x8147C6FD9C66ADB5ULL, 0xDD9AE8A6788E0496ULL, 
            0x9336ED70D5CC3616ULL, 0xF198E27FDAC6DF16ULL, 0x0218DD6F711DA62EULL, 0x055E90F21011DF0FULL
        },
        {
            0x6F2B59DF69682C15ULL, 0xE2EDAF45E139E0E7ULL, 0x5064FAAE2ECF632FULL, 0x2614144067F4C2DAULL, 
            0xD5B1F5BA21E7798DULL, 0xF3F82B5134C1EC1FULL, 0xCAA7CBF781948430ULL, 0x85C6379B01D2F1D9ULL, 
            0x6198FB3A2DD798E0ULL, 0xD67B9CDEB042324BULL, 0x3AC38541EAEA6D80ULL, 0x96DDADB009BCDE01ULL, 
            0xC393090189987278ULL, 0xA4BE520FF7F44FCBULL, 0x2DCB452B27925441ULL, 0x982CFDA409E5F655ULL, 
            0x6EAAA9076C69FBFDULL, 0x6FA3C9A3C4786E52ULL, 0xDABFBDCCAF3963C1ULL, 0x78C194F9F62712F9ULL, 
            0x736EF1A5F2ADA79CULL, 0x02C116AF350604AAULL, 0x388400832192E326ULL, 0xB2D24A0DA0D53557ULL, 
            0xF06A8A27AE21968CULL, 0x435BAAC02A66C5EEULL, 0x01607CEC455BFDD7ULL, 0x292B1DD6617A9A1FULL, 
            0xBDB9820F9794AF58ULL, 0x548065C8BA837681ULL, 0x635C4D429D273272ULL, 0xAF5F51809DEE8C8AULL
        },
        {
            0x9B264F61FD90A2EDULL, 0xA63EA97E6A8CFFB6ULL, 0x6CA1CF8682A9A849ULL, 0xA055E33C2C1E03CDULL, 
            0x0E942D2984C1EEA8ULL, 0x95E8B36AC2F35D49ULL, 0xE10FE103043EBCE7ULL, 0x975ED53FC2B17DE3ULL, 
            0x5101EF61B644DBDDULL, 0xAF3A06BEE0F1F768ULL, 0x823B066F6E53214AULL, 0x9EDDB22072812DB1ULL, 
            0x56FAECC3AF1602EEULL, 0x62308FBC927DD0C1ULL, 0xB1BDFD172171A563ULL, 0x3E5FA5B2BB1CC6C5ULL, 
            0xE7DADC38EB1CCF89ULL, 0xEFE0585B36D3D513ULL, 0x48EF3888C80204FAULL, 0xD708E503168B6970ULL, 
            0x153622580FB454D0ULL, 0x220D019B7EB0893EULL, 0x973890191E2B9A7FULL, 0x597D9AF5ACFD675AULL, 
            0xD75DEDA2FB28820FULL, 0x88C73F47DE98592EULL, 0x48A15975DA1387EEULL, 0xF42DAC8244CD0168ULL, 
            0x97F964D7D6866952ULL, 0x05E3255F4D7E015AULL, 0xE610924889032042ULL, 0x1A2B82139D8F1F2FULL
        },
        {
            0xE09D2B53A12693D7ULL, 0x5F35C98E261C7B17ULL, 0x4DCDA4FCAC889928ULL, 0x4E6A7154A12C9BC9ULL, 
            0xA435E1ECF07B0103ULL, 0xD76E2E4F7DA9308FULL, 0xB26BA3FBA33BC50DULL, 0x8812E00B2A203016ULL, 
            0x3459B275B8E59018ULL, 0x489364351623050FULL, 0x0B0D5748BC6F760AULL, 0xA9219D472D317428ULL, 
            0xF20CC6C675DF38CEULL, 0xDC71BAB110D20AE6ULL, 0x4D9D7FB7D40D674BULL, 0x581B683D134CB4BDULL, 
            0x0C537FA13116B031ULL, 0xA5A0FBF2AEB262BDULL, 0xE0BD275320ABA55BULL, 0xB5256BA038914C25ULL, 
            0x7B1F15A569EF96F2ULL, 0xFAA226F38E937699ULL, 0xCB124F41250D0F1FULL, 0xDC772D0EC6EC1165ULL, 
            0xDF38953D2A5BBFFBULL, 0x856904EDA6D38D26ULL, 0x920F8780B25BF574ULL, 0x6C528E13758126D6ULL, 
            0xD8DD0EFBAB077B9CULL, 0x7027B952FAFA542BULL, 0x8792F5738BEAF5D5ULL, 0xCAF19CE159BF2CD4ULL
        }
    },
    {
        {
            0xAD3B08D172B28095ULL, 0x3DE52423959E97CEULL, 0x8CBD720A657AC5BDULL, 0x7DE8809363982760ULL, 
            0x54010379951DA637ULL, 0x55A6812D743107CAULL, 0x532F7745ADD4FF2BULL, 0x2C32DDF37F84DF6DULL, 
            0xC01FE209A74C49B8ULL, 0xCEC4BD5C99BEA842ULL, 0xC1C02EA49C2848B8ULL, 0x3ED44E20D6D3D820ULL, 
            0xBBD45A2AE6FAB2B8ULL, 0x10E8B53643161CAEULL, 0xE5519634D0CB6A41ULL, 0xD02DF03B896DE6C1ULL, 
            0xFAC4DC398E54D03DULL, 0xB9D37027BC82D31EULL, 0xA5E9B6321125C2F0ULL, 0x16A290BF94F3B52AULL, 
            0x5564B7624777C1BDULL, 0x22FE14D184AA9EBDULL, 0xE40CF67DE126A699ULL, 0x7875D20901932143ULL, 
            0x92C75644F2EB671EULL, 0x1D6DC3025D01D790ULL, 0x741A3600061449C9ULL, 0xDF44C8FF9B10BA7EULL, 
            0x8CD310B1F14E1126ULL, 0x420765E65063D938ULL, 0xC0ADB2DE125A5C12ULL, 0x27909B52171CC3D1ULL
        },
        {
            0xF59D73516C6E7132ULL, 0x13D944D0503F7C42ULL, 0xBC329B995804DE9DULL, 0xCC3B7707BFB95E46ULL, 
            0xBC7B7E266BBBCC2AULL, 0x698038690B7F0D02ULL, 0x4A3E57C3477C9C81ULL, 0xB19DCC72CA5144D5ULL, 
            0xFF2F1BC6417BB5C9ULL, 0x9C4A02049D82941BULL, 0x1B03B1B13E71DEA8ULL, 0x736DB8399B1FEF82ULL, 
            0x7349AC52D5EF0DB0ULL, 0x5359DA13B7D27391ULL, 0xB59604F25CE80440ULL, 0x03A55F1BE1D0D352ULL, 
            0x469474CC72E2F82AULL, 0xA6904B6C97E4DF6FULL, 0x1D186CB3C15CE930ULL, 0x53B4DEECAD27B9C8ULL, 
            0x68D24331156C849AULL, 0xA63A5B5209200181ULL, 0x905AC84F9D9C76CFULL, 0x05CEA3C230E55CACULL, 
            0x45A1BCBAABBE519EULL, 0xAEF0ACA803096F75ULL, 0xDAA3CB7D9C12A8DDULL, 0xF8A07D3B90488048ULL, 
            0xDB5E48B08FF758F0ULL, 0xD551F83B5FB3598CULL, 0xC1C498E25471458AULL, 0xCC34D6685B4A8846ULL
        },
        {
            0xDCCDF4BD684968C9ULL, 0x73B2EF27DF930D71ULL, 0xB8747E69DC7011FCULL, 0x159C3598AE91C83BULL, 
            0xDD1B813F2BEDE120ULL, 0xA601EE8B17C1A1B5ULL, 0x842EF7435A299C81ULL, 0x794440B56FE2F180ULL, 
            0x179211748C6A949EULL, 0x9C1AD51159561242ULL, 0x6FC5001E7B76BDDDULL, 0x223D642D926E8492ULL, 
            0x6E752E4575BDBCCCULL, 0xA2C15762B80D2893ULL, 0xD1FF7A033D60ACB8ULL, 0xEBD1ADC7777436FEULL, 
            0x7D6581344AF2CBA3ULL, 0xCB64FD063D2B08B4ULL, 0xAB045A8B9453B007ULL, 0x61B64EAD8CE11B61ULL, 
            0xEDBA6051DD317C27ULL, 0x336BDFFE22FFC83FULL, 0x9DE96319FB9DA360ULL, 0x1FC07847AE0E3654ULL, 
            0x16E8A58732EEC433ULL, 0xABAD60DED20C06FBULL, 0x97305A42E6DC355BULL, 0x26A60A4C7EFE12B2ULL, 
            0x7664A7DE6A1614DCULL, 0x1F3FCEC2A2263EABULL, 0x58A41AE00B64F9FEULL, 0xEF5FCB396F750271ULL
        },
        {
            0xA4158228005D8968ULL, 0x8FAC3D3601EFC482ULL, 0x9F9CB90C5500AFE9ULL, 0x4BC90BFF9A656362ULL, 
            0xA57B4DCF779748F9ULL, 0xB8BF64CF1F136B09ULL, 0xDBB75ECEBA35E589ULL, 0xB602D7C255F14465ULL, 
            0x18D0E5C5271E9B24ULL, 0x62D7AFDFC561164BULL, 0x4A98AB57207BCDAEULL, 0x19E34DED35BFD0C8ULL, 
            0xDBB439768E7CB448ULL, 0x00CA7564089E022DULL, 0x545F95CCE9B36017ULL, 0xE886783D8FA0AC8FULL, 
            0xE71559B2FD8385F2ULL, 0x61BD33502915A463ULL, 0x40CCCD5B030455ADULL, 0x6EB5AD3AF81FB11EULL, 
            0x575F16656957409BULL, 0x5F3C721054E78C6DULL, 0x0F4B85C4E9BD68BBULL, 0x5572F00ABA17B4BFULL, 
            0x8E623F49B9AB8BE1ULL, 0x8A04729B568F2279ULL, 0x9C28315447D4F09DULL, 0xE79B6338E2F1F7A4ULL, 
            0x6DF6C1BABE0CB4F3ULL, 0x4D2BCB74438101ACULL, 0x6F33183FC0DCA28EULL, 0x58F54BCB09E5DEFBULL
        },
        {
            0x8F427E5425E3DD1EULL, 0x7F2384E2D6605B31ULL, 0xA4F17405CD8ADC0CULL, 0xE66B44A5B401808AULL, 
            0x45CE32E6CE2FC08CULL, 0x6164B0546A82E111ULL, 0xB57CB65B97950569ULL, 0xD9A690E65EF99AF9ULL, 
            0x41583BBB140711DEULL, 0xA87FBC6E6949CEE1ULL, 0x688A4E6FA51546B9ULL, 0x56F4B7B66CFCBEC6ULL, 
            0xCACAB345945CCBB8ULL, 0x83601E114C789F6BULL, 0x7B99EA8A5B31D410ULL, 0x2838AC5A698F81C0ULL, 
            0xFBC208C3C04BF3E5ULL, 0x1046DCE479BA6FE7ULL, 0x437626DC29BDD64AULL, 0xCB2C2FF6409C7268ULL, 
            0xF15C16AD3169349DULL, 0x2E32FDB75E1A9B7BULL, 0xC00028B98E1A7E8FULL, 0x52BFD13A7FB3DA7CULL, 
            0x6578D7BD66F00900ULL, 0x1EE07C21CF8DA16FULL, 0x0983E474DF0A7C7DULL, 0x6E7BAC36D7F6EBE3ULL, 
            0x8C766069A1177078ULL, 0xDBB87E6C107115CAULL, 0xC98BEB292D0DEB36ULL, 0x08D40025F066DFCEULL
        },
        {
            0xBC454761874AF327ULL, 0x8677074B4DCA4E78ULL, 0x041A261F579F65F5ULL, 0x51B9C611AEFCA7E2ULL, 
            0x5C455B814AE52099ULL, 0x04F8AE8A246ACECEULL, 0xADFF6962EC526706ULL, 0x1A255F75E82C1E87ULL, 
            0x36A02A5685E7894FULL, 0x2F967A6A54D855CDULL, 0x26C26B3C6685CD73ULL, 0x491898C4D39274DAULL, 
            0x6A58E09D6BF4AF5DULL, 0x4647C3574EBF7638ULL, 0x5AD99D20DC064276ULL, 0x818DB17DC0167F13ULL, 
            0x079C6A2226EE9F0DULL, 0x17257F97B7075D7BULL, 0x548B10A30D39406CULL, 0x89DCB52F0B62E3D0ULL, 
            0x76421C8B2F433C8DULL, 0xCAD66304898EF196ULL, 0x732A4CFA9C298D3CULL, 0x8E56AF837268BFE0ULL, 
            0xB892F867EB4729CFULL, 0x84CE866CFD0A79E9ULL, 0xA004B80071951546ULL, 0x4D9AD0A1E0F0C2DCULL, 
            0xCD63D6994D4A90A7ULL, 0x32748D70555BE0F9ULL, 0x0AB4D3EDE2C8A395ULL, 0xCEB90A3A13B6798DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseCConstants = {
    0x4267C83B42775E98ULL,
    0xF1119557BCC517D7ULL,
    0xACAB725142AB7579ULL,
    0x4267C83B42775E98ULL,
    0xF1119557BCC517D7ULL,
    0xACAB725142AB7579ULL,
    0x198D87F3847C1372ULL,
    0xAA947C13E13DBD8DULL,
    0x61,
    0xA0,
    0x9C,
    0x39,
    0xF0,
    0x89,
    0x67,
    0xA2
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseDSalts = {
    {
        {
            0x103B48CFC5508594ULL, 0x0AE6DC7990745F73ULL, 0x24444355DCD3A817ULL, 0x734A1CBE9C3DC50DULL, 
            0x158AE898B5F0E943ULL, 0x28BD4DAA65468E56ULL, 0xA332B8FE533F759FULL, 0x0657D430AF03F003ULL, 
            0xBACB46819673E071ULL, 0x5DE863D81EF181D4ULL, 0x628628239A51604EULL, 0x28261E7F0C026828ULL, 
            0x0CEF60E48DD02562ULL, 0x8C21B42DEDB92D9FULL, 0x705A50FF4CEA71A7ULL, 0x4FD23724C9992F54ULL, 
            0x8F04C9D456B33DA8ULL, 0x0EB7A07827096B30ULL, 0x3DBFBF3F26ABDAD4ULL, 0x50897BB2E5147DBEULL, 
            0x8D995FDB08995864ULL, 0xFE1F9CA84D51A204ULL, 0x3C57E441167334E4ULL, 0x4ACDBB341DD5B6E9ULL, 
            0xA5F0E70E4DA6E92CULL, 0x3A297D94790ADC8FULL, 0x4C1395963597CD55ULL, 0xA781498732A6D83AULL, 
            0xB5D4AD3A99908308ULL, 0x4EEF8C6166A7DBF2ULL, 0xC1538890EEBEABF2ULL, 0xB585160FA5829A98ULL
        },
        {
            0xD63510B26AB13CDDULL, 0x4E5379F56188E717ULL, 0xA9CEE966BDF3B8ABULL, 0x9B6B8F2C37D19C65ULL, 
            0x716B66C45E459C4BULL, 0xBAD744E3E19B4DB3ULL, 0x2C5515E27659C856ULL, 0xAE80BA8A9E4070EAULL, 
            0xF381CA4B7C993AE6ULL, 0xA24E76563E60DEEDULL, 0xB3DFB0409E3426ADULL, 0x9943F9106CE4FA94ULL, 
            0x64D5AA72E921A2AFULL, 0x6381199F03D4E4B5ULL, 0xB7A3D685421258F8ULL, 0x065618E7F9D9CF9FULL, 
            0x4210E8E71D683910ULL, 0xC5988B34CF1F083AULL, 0x8719C8B1F2204189ULL, 0x92F81250AF4A88C0ULL, 
            0xB64FC5F796B9C69BULL, 0xEE9A2E632EDBFD60ULL, 0xA77FD1778F4B2187ULL, 0x147BD826F561060CULL, 
            0xF70AA3A4EE057195ULL, 0x7FE4FED35DC2D2A2ULL, 0xEADE7D804A992414ULL, 0xF73C477015372A0CULL, 
            0x9B06E060810FFD49ULL, 0xAF9FE1A89C0C5568ULL, 0x869BBFDDCFC92D3EULL, 0xFFC1A58FC1E73772ULL
        },
        {
            0xD8B19AA921A6FF10ULL, 0x12D9FBF77474DD78ULL, 0x02BEC8902D41F23DULL, 0xCA6B2CA28700D393ULL, 
            0x15A3D7447AFF05E6ULL, 0x5D24E1C0D133C18DULL, 0xEF793AB0DD61AC82ULL, 0xFD7268A49913CC48ULL, 
            0x55D68706075AED61ULL, 0x143BDE39F4832358ULL, 0xF8FEEAAD46157679ULL, 0x10BD34497F224783ULL, 
            0xE68B3D5EECF74762ULL, 0x110F52F35D7D63FFULL, 0x94C3DE4B5C5D77DCULL, 0x38D7D4C2843ACD67ULL, 
            0x1A7711371358FF30ULL, 0x5869E22E3DCED1BDULL, 0x2A98C225F23D4017ULL, 0x3A9EAF176129ADE4ULL, 
            0xDCC3E378B3508C98ULL, 0x3DDE6475E59B8C0CULL, 0x36C31420E2346476ULL, 0xBA3ED9225B8E579DULL, 
            0x1A8BECF401D8FA15ULL, 0x2D207E70B6A9D765ULL, 0xA575612881704550ULL, 0x1A92AECBF8D7C929ULL, 
            0x4847D58D114EE5BBULL, 0x6288E738F7D5F517ULL, 0x15CAF4AA0F3EE284ULL, 0xB39F1740474851B4ULL
        },
        {
            0x3649AFD1DB52E640ULL, 0x36E5F8D1D1A390DDULL, 0x89E30B9D3BD14C92ULL, 0x713099208683B7FDULL, 
            0xCA048F67C5A91EE4ULL, 0x2CAC69269934EE36ULL, 0xBB5B4E210F4C8A40ULL, 0x8990FE631EA9D09CULL, 
            0xC278577AD600E405ULL, 0x57D82FB6AF4CC82FULL, 0x36F2860FA6B39F54ULL, 0xF218FA2E20EFC917ULL, 
            0x83914C7DC6AAF77CULL, 0x1C40AF88A37FEDB0ULL, 0xCE3AE54E98A90378ULL, 0x3FFCD773AE7EA563ULL, 
            0x345C99A274C74ED6ULL, 0xF61EF719D330B841ULL, 0x2ED4F9E2146E3109ULL, 0x48C220A03C43B4C4ULL, 
            0xC79DB9B3C785BDE0ULL, 0xCC40023F88B46677ULL, 0xB95C1F459F94B8E9ULL, 0x9988BEED9192B3C0ULL, 
            0x7462A1865634D2F7ULL, 0x9095ACCEC9A3E3A9ULL, 0x7FE7570720F8F82FULL, 0x1D90A3B9A8BE4BB7ULL, 
            0x79B28F96DFFCDB53ULL, 0x842E66125DEB4824ULL, 0x730D62E65F96198BULL, 0xFAF9554404C965A6ULL
        },
        {
            0x4E01FB9A611D42BCULL, 0x00E3D3D10D616B4CULL, 0xA91EB4BB61CDB54BULL, 0x1EE7E34912C6707CULL, 
            0x45289045BD044116ULL, 0x636D43F36C51F7C4ULL, 0x1DA509A3CDEB5491ULL, 0x145D5CBF7A9CE6BAULL, 
            0xF2F22D3847D69D69ULL, 0x72F7C83B2BF24596ULL, 0x8A9C8DBFE23B3307ULL, 0xBA156062964BB1BFULL, 
            0x52914C5F1B1E1C25ULL, 0xD53AC38BDF50F285ULL, 0x5BBDF90DAD71AB7BULL, 0xD1769AB42A1356E5ULL, 
            0x08546FFA1DA6841BULL, 0x6EE949280438DC7FULL, 0x80C761D2C1AF7A6FULL, 0x956D289C47BA3405ULL, 
            0x34AA5B184AAD49A8ULL, 0xF3E429071762C237ULL, 0x3C1612324BFDB7C1ULL, 0x85A187F000A73AC6ULL, 
            0xE72815814D90D3F8ULL, 0x50987AAF20EF18B9ULL, 0xECF553CB69D3C43CULL, 0xCEDFCF42E577DF50ULL, 
            0x079D37966EEB9F54ULL, 0x0FFAEBE8F4713094ULL, 0x14A0B82E4DF113BEULL, 0x556F6594DC9C3246ULL
        },
        {
            0xE68D3FF281BDEC9CULL, 0x7043F11842157822ULL, 0x89ED301AF467B351ULL, 0x81A9FB9B7055ACF6ULL, 
            0xABCB965E788306F1ULL, 0xA3DDAE8434A40485ULL, 0x52EE76D860BADEE8ULL, 0xE093861766B99358ULL, 
            0xF49F7AE03C22C25FULL, 0x246E790867A52695ULL, 0x2ADA778009E75DF9ULL, 0x39011A15B2A2204FULL, 
            0x4B200E398654D289ULL, 0x46B9A0558A3F1A74ULL, 0x65CE464399021476ULL, 0x23652CAAB75B64EFULL, 
            0x18A8F36C25FD14BBULL, 0x9C554F450F543AD1ULL, 0xC3B6EBB449BC1B62ULL, 0xC7E3C25F310B29ACULL, 
            0x8D182EE70DBF955DULL, 0xDF28E427FD6C3581ULL, 0xB224AF01FA46B138ULL, 0x82F11A7739A81550ULL, 
            0x2415F4FF5E8552F6ULL, 0x0F1466E12ADC42DBULL, 0x42FF6BFCE0636D8BULL, 0x74F77721168A4357ULL, 
            0x2DBC76E4CF76D6E5ULL, 0xA3CA8A1DACDF130AULL, 0xCE809BA38DA6E930ULL, 0x04440DA487AAFF4DULL
        }
    },
    {
        {
            0xCE418AA7DFC662D7ULL, 0xDD53C73184541FFBULL, 0x907244057B713B7AULL, 0x8C5AC9EB8288C613ULL, 
            0xB232254370DAF9B1ULL, 0xA17F3839F3419514ULL, 0x1D267CD940132607ULL, 0x41632003ADFB39F6ULL, 
            0x3CF4326B10CE9311ULL, 0x2D778A92B983388FULL, 0xD3F18B6321DB8D40ULL, 0x092B06D97CCE3EC3ULL, 
            0xFD786D706560AB19ULL, 0x807E8046C946C1C3ULL, 0x75EE641DB59E66A4ULL, 0x268D9078973F7E31ULL, 
            0xD134313E4288D0E1ULL, 0x6F4FCDED7E3033FBULL, 0x75823F182E0361B9ULL, 0x5F3583D5E541C301ULL, 
            0xD77B751E95F1BDFCULL, 0xB5179B2A819BE290ULL, 0x5752F4EEEF1A9C70ULL, 0x38C7324CE83A9E7DULL, 
            0x67AEFAA5DF8C64E9ULL, 0x565B88009A646FD2ULL, 0x65A4AC99BD60F04FULL, 0xC5797AD4B23EF572ULL, 
            0xE2018C38B87ECF03ULL, 0xEED9350E920364E3ULL, 0xC6F458A97E8B963FULL, 0x7CEBBDB8B3D814A5ULL
        },
        {
            0x5F7DA4AECF6444AEULL, 0x9C393470DF910031ULL, 0xF954219F311E35C8ULL, 0x4D1EC9D66BCE8447ULL, 
            0xED50E654A8425A82ULL, 0x44C86A352BF43FEBULL, 0xF0E40192D4C0A409ULL, 0x652B0B07F299BF51ULL, 
            0x3F840ED2B8E50BBAULL, 0x42817426BCB9605DULL, 0x9699A4EE1F414D5EULL, 0x7209A7553DE0BC12ULL, 
            0x41B4DEDA5B5B3376ULL, 0x568A4EA1E80BDD47ULL, 0x568B0A6E248CC8A4ULL, 0xE16463EC2AA4AF7DULL, 
            0x9890F6E7C15BA89EULL, 0x2BB8BB01AE06F24DULL, 0xB2B085FBD5C8493BULL, 0x4BF0CB328E1F3ED1ULL, 
            0xA3EAA388F2164604ULL, 0x3A95E96D9739BCCDULL, 0xB05F9670E7B08044ULL, 0x77B9EAD78FCF52B8ULL, 
            0x6C2F1E9E5024DB07ULL, 0x306A6661F9D7D102ULL, 0x143CA2016CEDCE6DULL, 0x8EFB0138BB0F5367ULL, 
            0x425EF2081F913336ULL, 0x478F59B17DAD9C2BULL, 0xF92906EE5F7E8816ULL, 0xB1BE882C5C72DF37ULL
        },
        {
            0x85F4112FAB6198ABULL, 0xD62538240D5596A6ULL, 0x38EA1812203874DCULL, 0x08F707172A933AA0ULL, 
            0xD4028D9F6CB25AF2ULL, 0x04D7EE8E2531A7C3ULL, 0xE332AFDC62469C62ULL, 0xAE586C01BFE3F657ULL, 
            0xC08644247EA8886BULL, 0x2ACBF1E99B00E717ULL, 0x9379AE021C54CCA3ULL, 0x598B8BAD7BE54C6AULL, 
            0x73F775FF137B2498ULL, 0x844D26434713FBECULL, 0x64544A8FC319CCE4ULL, 0xD557959B593439D0ULL, 
            0xBC9C06D15B8163B3ULL, 0x86FC62324C3C593DULL, 0xCBE1D37A7C418AB2ULL, 0xA00F780F2FB9D61DULL, 
            0x3AFEE1FA3744694EULL, 0x1B61313D81D30EC9ULL, 0xC4B5DC0F65894D53ULL, 0x0A8E535432F803C8ULL, 
            0x2995D0717FF94BABULL, 0xCA1B522336FBDB5AULL, 0x2FD7476A47F3215BULL, 0x10B74D7F2F3DE6E7ULL, 
            0xC9D2AE2CC8CDCEA4ULL, 0x7115F4105264DBFEULL, 0x97DE398C359FE8A9ULL, 0xEA197BDF5AAC27E2ULL
        },
        {
            0x80760291F0F29434ULL, 0xB7D40CE89522B1F5ULL, 0xD2579D97AB57A740ULL, 0x501D9C879818FDD8ULL, 
            0x11F854704C4DE9F2ULL, 0xE1F0E39AF130C773ULL, 0x91EEE5B8573ED506ULL, 0xA7430D98E99D7897ULL, 
            0x176C132A121EFE53ULL, 0x3D4DDABA3608CF70ULL, 0xE2C4C5CDF0F039A2ULL, 0xA0C465570ED03F28ULL, 
            0xF58619C33031DB17ULL, 0x930CC5DFEAD70DB8ULL, 0x47620D173866200FULL, 0xBE79085F90EED9FBULL, 
            0x8C860A41B14AB94DULL, 0x2B1E029AFC8C2B80ULL, 0x77A3C704D946CC21ULL, 0xDA02008521CEFBD6ULL, 
            0xB36CF90959B967FCULL, 0xB0D298FF864C2C6AULL, 0xAFC52B258676BA72ULL, 0x2DC31CA20F48FC05ULL, 
            0x5025B56EA452981FULL, 0x7EC51817860DAFE3ULL, 0x32EAB37A5708FA21ULL, 0xC92916F5B9B96443ULL, 
            0x9C6F3B31FE38653EULL, 0x13322D993ED697B0ULL, 0x57630D5FF0DF55DAULL, 0xE3E08E710D5F0F3CULL
        },
        {
            0xA97D95BBD3599EEAULL, 0x68B05551A6764220ULL, 0xEE2B44D2F9A0E771ULL, 0xBE35401E2A8B4B57ULL, 
            0x0F8418A0CD4C5C7BULL, 0x665049A43A1D223CULL, 0xCCE8CB43D7750DB7ULL, 0x1B7D887913B38B63ULL, 
            0xE4CE6B257B86D1B8ULL, 0x38A85FD4B9FEE828ULL, 0xF4DB77873C69F013ULL, 0xDD818B82C8B6B520ULL, 
            0xA7AFE5DC7D6EC64BULL, 0x77FD4F63107DB8F9ULL, 0x176F6917B43790CAULL, 0x3AC83DE7B16D0BAFULL, 
            0x8A1169F3630CE4D9ULL, 0xD4B28B291FA4F2E0ULL, 0x0326AA990F12AEEBULL, 0xFADD612294CFC077ULL, 
            0x889A4AC6BB0295F3ULL, 0xAFE789D7471930C1ULL, 0xFE8F2F8A624194AFULL, 0xD4997385D58ABEF3ULL, 
            0x32B6A8D74165BB5FULL, 0x29DDD5E8263DD335ULL, 0xB44C394716D5DADAULL, 0x23ED84C0F5F4EBC5ULL, 
            0x7BB68FE7606EAFF3ULL, 0xD98CF772F8B712FDULL, 0xB2E902C4809D0414ULL, 0x03D0F59BBFE60120ULL
        },
        {
            0xB80AA50EDBDFDC41ULL, 0xC277ED629EFE57F7ULL, 0x19B8C975176D03BAULL, 0x9DF8F260718A51AAULL, 
            0xE73C5CFE461B480BULL, 0x84245AC657868038ULL, 0xDCFE4D4F3A2837BEULL, 0xD9810EDE9443267FULL, 
            0x09B2C9C16CAE6FB1ULL, 0x4CC48E37A744F801ULL, 0xFB3D60B9DF6254B4ULL, 0xED9448B3EE4CE0E9ULL, 
            0x8AB6A57C6DF31B3FULL, 0xE3082B8DFC8AE66DULL, 0x82664C56D21DD250ULL, 0x6CE25EC0D72C70CDULL, 
            0x4D73ECCA767BD982ULL, 0x88A20546BFAA7E11ULL, 0xEB600DC317A26257ULL, 0xB30985EE638DA51AULL, 
            0x2B64B8A9CD1C3DFFULL, 0x846AFC032F925A93ULL, 0x62C1A128CFDC284FULL, 0xF3CEE42571EA0AE6ULL, 
            0x152877860EED4D3AULL, 0xEE9C91458873FB5CULL, 0xAFD006A73F3B6530ULL, 0x7FAACB956F38C913ULL, 
            0xCCF0AAC19671E83EULL, 0x4BEBF2E9C7F25BE8ULL, 0x405910114FD23F59ULL, 0xD8597717445D6673ULL
        }
    },
    {
        {
            0x37AE29720E1ABEE4ULL, 0xF72B072E087451CFULL, 0x79C763775A997B8CULL, 0x9D7876C21466741EULL, 
            0x0503EA53B4B5ECA3ULL, 0x975C59D0D9359DC4ULL, 0xC497B5CA58B6CD57ULL, 0x8D5C45AD42FAB954ULL, 
            0xEB451C8FFF829730ULL, 0x55DB6AD50AED79FFULL, 0x425BFFA30593D40FULL, 0xCA40DFF7DA4DB25EULL, 
            0x36E8BBBFE6186AB3ULL, 0x90F393ACE4BC3216ULL, 0x21DF18CAF3D27130ULL, 0xD0771EE728FBA29AULL, 
            0x31FD18C04B849FD9ULL, 0x9EAFA25B51F40A59ULL, 0x5E1BA7F161B21744ULL, 0xE74CCFEE8AF5558AULL, 
            0x3EB19DDF6937F904ULL, 0x475E83B35677EE64ULL, 0x1D8407B41559501CULL, 0xA88002119E24477BULL, 
            0x986BCC2C49A760AEULL, 0x91A27F8DCE5F4CECULL, 0x727041D3384C3520ULL, 0x14708A7050EF8D75ULL, 
            0x5544C7751A0F7A76ULL, 0x6B95145B3862E4EFULL, 0x1AE325DE8697C3A2ULL, 0xAC09B2321DCE8220ULL
        },
        {
            0x3BABD7313F84CC0BULL, 0xE700475898BF02F3ULL, 0x75297A38E93C292DULL, 0xCA58C25011B3D951ULL, 
            0xD3F1D2E349C6877FULL, 0x903F5B2914A6FA04ULL, 0xE3B7C02A0347C882ULL, 0x2FF71809495120DCULL, 
            0xAE835E47D2F7456AULL, 0x6BA6BA54AE75E4DCULL, 0x9D22F20E83C6EE71ULL, 0xDF444148A260F4D1ULL, 
            0x5B009278EA4FFFA3ULL, 0x01E1A2CAC57C72D3ULL, 0x3344889972616011ULL, 0x55B7C51FF17E1CF4ULL, 
            0x55B3B4E6FF768709ULL, 0x2F46DA15ABDFD377ULL, 0x6D356836070084C0ULL, 0xECEFE52C8724CC85ULL, 
            0x1386469EFA2CD739ULL, 0x370EE5852AB482EBULL, 0x01C69C22701F835DULL, 0x53CD487E2C3AC9E5ULL, 
            0x41464D81EB54EAC6ULL, 0xC226332EB99425ADULL, 0x92D1341ACE3FF4F5ULL, 0x35872324F57450E8ULL, 
            0xEABBC7404A087742ULL, 0xE843515E80DA2195ULL, 0x978A7E74C9A61E1EULL, 0xC61CB37C7190FC8DULL
        },
        {
            0xA39E9CE94FA96516ULL, 0x1D51196747E16E71ULL, 0x20D80012F670EFC1ULL, 0xE75157E5C9D95058ULL, 
            0xB666ED05EC835EE2ULL, 0x27FBC3974BB0D170ULL, 0x3BE8478D2E6AB87CULL, 0x44389DEEEC36CA25ULL, 
            0x2398AC830D0B7C8FULL, 0xD9052B50329A0A31ULL, 0x99EC973D6B36D359ULL, 0x9EDA0590E6DE324EULL, 
            0xFE6EB9A49C4DA589ULL, 0xA6E5CA59B0133E3EULL, 0xFC81F52737548920ULL, 0xE4446E0317379961ULL, 
            0x91C263A5DFBEFFFAULL, 0xC1AE61019632012AULL, 0xD7D93D59F9F20D57ULL, 0xF2132693A1A39B42ULL, 
            0x04DDBCDE4EF8BE56ULL, 0xAC0F30C7AB169719ULL, 0x3B137416F0FE1D45ULL, 0xAE9A9E9F008462C0ULL, 
            0x007EA805B5B394C7ULL, 0x67AEF5C3D5A8F376ULL, 0x3D0956A240FDE0B6ULL, 0x1CBF3143A31F5014ULL, 
            0xD436381AF8AFC549ULL, 0x775D68A7927B6FD7ULL, 0xE8B8F09A17889E94ULL, 0x9F95F761C9022393ULL
        },
        {
            0x5A0A0E1F180E7E38ULL, 0x60B66498BF888D9EULL, 0xA8B00E918E90D9CCULL, 0x59F491EAF561E48FULL, 
            0x87686229A6AC2FCFULL, 0xACAD7E12DD188D5DULL, 0x5B30E7E45D11FE6BULL, 0xEEE4B8FF3AF343FEULL, 
            0xE82AABF04BE516FCULL, 0x3C0A2E68EFBC16B0ULL, 0xA6F20D853373CA1BULL, 0x3B25536917FE0807ULL, 
            0x8528C6ABD8B9CBACULL, 0x43F09D6BC50B94ABULL, 0x428F026556D3C220ULL, 0xA43600FB94B9A021ULL, 
            0x66227D2B62CE9F63ULL, 0x14F3193665DAD2E5ULL, 0x3C90708C8E4D5BBEULL, 0x8210A86BE86421F4ULL, 
            0xFEDFA9CC817C549CULL, 0x44971BE6D450F941ULL, 0x4C6052F5301E7703ULL, 0x1DD5245E2C51456DULL, 
            0x525BA7789CA279D4ULL, 0xB821943CBCD2E1CBULL, 0x7B827DA43230075BULL, 0x7472C8B5C3FBD888ULL, 
            0xAF29810A26B10FC9ULL, 0x3BAB802AA14CFD5BULL, 0x4F912121232899AEULL, 0xFB49BA88F1BA21EFULL
        },
        {
            0x2B401CDD3E90C528ULL, 0x35792E59FC9D5613ULL, 0x8C85A768C0BDF7BBULL, 0xE82F7703F6F20AE1ULL, 
            0x393E3A4AE4054C75ULL, 0x9E811C449F8ECFF3ULL, 0x624F79F2A194F196ULL, 0xAA38FCB92BBF6CBAULL, 
            0x821F625866F72AD5ULL, 0xE9CFD4B8C99C5B2FULL, 0xDF1A29C3D9889FD8ULL, 0xBA759B9A3CC82641ULL, 
            0x6CBA8391591B9731ULL, 0x3F776B6B52BEB4BFULL, 0xF30F092A81A4B1E7ULL, 0xE5DDE1FE35D68396ULL, 
            0x2D85039091996419ULL, 0x2D3F081472E42077ULL, 0xECFA320E60AE1124ULL, 0xE165BC04B64C0531ULL, 
            0xBBF92860A3964110ULL, 0x8EF900CFD5A81F43ULL, 0xBE48680D3D73FF2CULL, 0x1C406462EC40200AULL, 
            0xC8A8335D7BFB5C18ULL, 0xB076A95BDC5C429DULL, 0xC62D15472F4FB2C5ULL, 0x9002944A582D3557ULL, 
            0xE8787FF8AF37477CULL, 0x9166CCD9A6080843ULL, 0xB600B49086715E65ULL, 0xEE200029F085E32AULL
        },
        {
            0xD0424DBF54F27170ULL, 0xC7B601498C85D32DULL, 0x250FBDB4FAC58DC4ULL, 0x3C6E1FAD0862C9BFULL, 
            0x80E711D70E5454D8ULL, 0x2423452DCC814752ULL, 0xABF8F6C9534F54F5ULL, 0xEFDF7277CE3A0902ULL, 
            0xAD18384F72C6BA35ULL, 0x79F6B535A63F86D8ULL, 0xB329A2B06DC3D385ULL, 0x572619494701ECB2ULL, 
            0x74E8672FCB941504ULL, 0x94122DCC9F6A3B91ULL, 0xE4087A1B3C1B697CULL, 0x65BE90A23F9998D7ULL, 
            0x4AAD19B0675282A9ULL, 0x920004BAE8484007ULL, 0x254A343378513BCDULL, 0x5AFF08E95B31ED6FULL, 
            0xB44BE47A7689ECD3ULL, 0x1821CDDE21DE2C69ULL, 0xDDBB9EA276AFBEF8ULL, 0x35DE59D12F77815FULL, 
            0x5274360CEBA25BA4ULL, 0x185C83EB52224E30ULL, 0x75C909CEBE80776BULL, 0xCDF1CD1A7C858F18ULL, 
            0xE1A9E3FE1AAF5921ULL, 0x2B0CDDD09D93B187ULL, 0xF61A3AB129A14B32ULL, 0xBD37F093FE14F7F2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseDConstants = {
    0x758956364DB42F4EULL,
    0xEE7DC4EB9F97DA7FULL,
    0x51B3DFEF4654377AULL,
    0x758956364DB42F4EULL,
    0xEE7DC4EB9F97DA7FULL,
    0x51B3DFEF4654377AULL,
    0x7EDC63B18F7ADB4BULL,
    0x28122A2BA6161671ULL,
    0x8C,
    0xF2,
    0x64,
    0x5B,
    0xDB,
    0x98,
    0x38,
    0x29
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseESalts = {
    {
        {
            0x6D6B59803E2B1102ULL, 0xA325B3A96F290F06ULL, 0xA9D17C32FE16C648ULL, 0x58EAA28E958D1F60ULL, 
            0x1270F926954C2EBAULL, 0x6B63101A442E8F09ULL, 0xE5B651AA5D7F7485ULL, 0x773842182858EB39ULL, 
            0xD1AE50F10ACB893BULL, 0x5B32D57ABD111EF3ULL, 0xFA1D2F74EE135ABDULL, 0x2F8B0B83E75FB17BULL, 
            0xEAC96B7110A15671ULL, 0x3CCC7FBDEAA68741ULL, 0x1B8EA7D692679924ULL, 0xF4EBF03281CCEDD0ULL, 
            0xF99DFA23812A2F41ULL, 0xCB4AF4D92D73D5C1ULL, 0x41F5FE3FFAC832DCULL, 0xE69FF0DE52ACE958ULL, 
            0x593319FC8B79DEC3ULL, 0x6FA9BCDFC8D9DD2FULL, 0x83A13077F2DF4DB2ULL, 0x708EA7E809EA85BCULL, 
            0x5A86B2D6FB18A1F9ULL, 0x8F25BC256A536084ULL, 0x21572351C7AF5175ULL, 0x21E8D17D0DD67E62ULL, 
            0xBC62D5A21BE955C1ULL, 0x9B6EDCADE92780A8ULL, 0x8DFD2E0A9C3C6C85ULL, 0x99AE796D1B82FE94ULL
        },
        {
            0x1203B79070516895ULL, 0x59BA9FD9C832AFE9ULL, 0x0AF4AA2A048E5947ULL, 0x48B98B5073FB5F15ULL, 
            0x4F756A2D293E6F3DULL, 0xC10FAB8DFC0E039EULL, 0x73621E90CC307FE4ULL, 0x7EA3735ECED2A0B4ULL, 
            0xA0171E298280AC5BULL, 0xF6C7BC65D6A9F130ULL, 0x1571BEDB9999A8BEULL, 0x598C345945BC2579ULL, 
            0xA567BE26D08A9996ULL, 0xD314A88F70C5FB91ULL, 0x9217473A0AE88694ULL, 0xC229A90ACA7872EDULL, 
            0xAF864ABFCDC5C714ULL, 0x61C4311C34E88151ULL, 0xFA1BBC47D81EBAB1ULL, 0xD755DD3C4C9237D3ULL, 
            0x201904674902FFB8ULL, 0x333AD1F8FE55A6AFULL, 0xD83397FB021805DAULL, 0xB5153334C5D14E4FULL, 
            0xC0B81AC4F1432DCEULL, 0xFC4AD780A50E576FULL, 0x8194DF8360B80708ULL, 0xA34E34CCC548E3B6ULL, 
            0x4354E1F9D08487F8ULL, 0x968250B45ABCE18AULL, 0x5A6F6BC4B561BAA8ULL, 0x3FFCB64B75DEC03EULL
        },
        {
            0x9477A856D51AB397ULL, 0x235C9ECB719531E3ULL, 0x3EDD082250E67785ULL, 0xDA6BBCAE41FD237DULL, 
            0xCB629B3C07D4BF29ULL, 0xE8B6A3168874A2BBULL, 0x70E5425E4EE42F0BULL, 0xBD692B15F8CB28FFULL, 
            0x9ECD0F3C715B799DULL, 0xFBF090FE54576F70ULL, 0x805DFBD86A1C09B9ULL, 0x8E8716D943E07791ULL, 
            0xC223E2C436181B67ULL, 0x673F3A14137C2043ULL, 0x9AC3352C4C43B260ULL, 0x44AF0784CBED04EFULL, 
            0xB105BD12E09734ECULL, 0xCC544041B4B8B1ABULL, 0x864B2AD0519040A9ULL, 0xA0848210FCAAF2FEULL, 
            0x3CEE98F8D3C0B661ULL, 0xCA55A3377EB1F3FCULL, 0xB77AF0DF8AC6BB94ULL, 0xA0730045FCCE01FEULL, 
            0xA87FE4AAE3661C54ULL, 0x21CC69895D64C9BBULL, 0x378955DF7D0AA4E4ULL, 0x1E12FE134EB98C16ULL, 
            0x9194241844788461ULL, 0xB6DA5BA9831E47BEULL, 0x24EB802F4AFA2EBCULL, 0xEBA876CBB53ED94FULL
        },
        {
            0xB1E5A6E90E305124ULL, 0x389919EAB5B2A146ULL, 0x1A739183E4C2C6DFULL, 0x0D4EE29C34C2045BULL, 
            0x380742428220777CULL, 0xFBC3DCAF8A673D1DULL, 0xEACC263B3A3330ECULL, 0x420DCFFF98600AE8ULL, 
            0xE5A1610EEC307BB3ULL, 0x93C8EF0AE5DAE6A9ULL, 0xEA1905CF37EAD0B8ULL, 0xB0FD8CDD6E26A62CULL, 
            0x95D35A85FE32CB97ULL, 0x99054C273E8E8C46ULL, 0x50A5DB4D29573B5DULL, 0x71C19370A4BAB1CDULL, 
            0xCE44A41D9142FDE4ULL, 0xB4EEB16E3446FFC2ULL, 0xB144B31B72ED532FULL, 0x34CA937159C2FAC4ULL, 
            0x523127A56A17D2AEULL, 0xB0947C19E50CA800ULL, 0x64AA4C6DD73BB2EEULL, 0xE271F4A86BE444D0ULL, 
            0xFB87CFE75CD68005ULL, 0x1FC0C2C9F25A7E60ULL, 0x83302710DEDC3D49ULL, 0x4C535116B0D7D36CULL, 
            0x9C7FE9E5A920DDCDULL, 0x828DB6844D8C2C03ULL, 0x17DD73C1457DF6B7ULL, 0xDFE13A285CC2D0E6ULL
        },
        {
            0x22D0188CCA847CE7ULL, 0x7C2515C070FBBA69ULL, 0x0B108F7CF5C6E085ULL, 0x7B16706ED56D5E81ULL, 
            0x6D2008B09EB4678AULL, 0xFFD934C083F0254CULL, 0x35BFE8AFA2E2E01BULL, 0xE56011F30CFEB943ULL, 
            0x096B452BA1B5324DULL, 0x614C7A603D936219ULL, 0x4D45765941B91C83ULL, 0x1CEBD0C1E4B9E98CULL, 
            0xF973679C8C0DCBD2ULL, 0xB3EA0422DEB8E0A5ULL, 0xFADBDE6B277F4D39ULL, 0xDFEDF598FB5467F0ULL, 
            0x45A3D2BF25BD9FEBULL, 0x673F34BE6F95A254ULL, 0x036A31ECC0FD912AULL, 0x2567E99848590127ULL, 
            0xF0E33CD0B482134FULL, 0xBE39857099155B39ULL, 0x78C2D7718343B335ULL, 0x5564D1AA171BC55FULL, 
            0x67AA70186642A5D5ULL, 0x8A654C88C2539AB3ULL, 0x03028CD388406466ULL, 0x4779AF84DE2CC0FBULL, 
            0x3A09B2BD20B93C3CULL, 0x4A1D3C0926345605ULL, 0x628CC76117A72105ULL, 0x5EA549CE1218DD9EULL
        },
        {
            0xA090219350845A3EULL, 0xC832579A21550E67ULL, 0x2426EABEF390D643ULL, 0xD2DFA6716935ABA3ULL, 
            0xBFB01814D406CBE5ULL, 0x9EB079B981D882C4ULL, 0x59D8C0C6855B5389ULL, 0x6AEEE87E12381B80ULL, 
            0xFBED5BE2B0AF697DULL, 0x078F0AFD1054543CULL, 0x6A927C366061126CULL, 0xEFA6CB9EF0E064CBULL, 
            0x276CB8A008F45BF5ULL, 0x2AEA17F03A8CA800ULL, 0xC57190D7E66954C2ULL, 0x1D623FDF62C2E4D9ULL, 
            0x3DEB9C272C2FA23FULL, 0x3CB7C226AD83C67DULL, 0xC871B07D21C52EDEULL, 0x3A10727F186F21DDULL, 
            0xBB87F6361ABB629BULL, 0x122728A479F2B2D6ULL, 0xF633D93A5AF34537ULL, 0xBBED9DE59FDACD58ULL, 
            0xA95A5824C7CD0DF9ULL, 0x385849C157206D31ULL, 0x5D6293A9DDD23C20ULL, 0xAFC29D22EEA9EB5EULL, 
            0x33F381418531F875ULL, 0xEC0B0DC39CC7AE4EULL, 0xA236050AC2F3D70DULL, 0xDE7CA7BDA73FDF39ULL
        }
    },
    {
        {
            0x4563F403B1459733ULL, 0x67B6949A11DB8125ULL, 0x4B576BF474D338AAULL, 0x4F4978E6C081A4B2ULL, 
            0xF41ADF005BFD1529ULL, 0x37D92446B7F37FBAULL, 0x5B559E8D05277A18ULL, 0xEB4142E03B15C6DFULL, 
            0x9105E424CCB3CC44ULL, 0x9EFFDF3256493796ULL, 0x49AF8656566A4835ULL, 0x80D8CBF94730C4A0ULL, 
            0x4E29358A261A6855ULL, 0xF0E7F487C73B0D4DULL, 0x4D90E3EA6011A9BFULL, 0xFB593CED9E8DD85DULL, 
            0xB074D551DDA8A772ULL, 0x8E52CFEC9F0D894BULL, 0xF387A4C20FC97FC6ULL, 0x94A9CD3AA5368708ULL, 
            0x5E3D63C992DA5E8FULL, 0x59F33B279547F3F9ULL, 0x2D896EA10617DD01ULL, 0xB184C8690A3A58D7ULL, 
            0xDFADD6EEEC24D8A2ULL, 0x0F71C8B3A19CB385ULL, 0x5E0A6509D6B380A0ULL, 0x602A351A2922540FULL, 
            0x82945B4C104F2247ULL, 0xDBD5790E5590AD68ULL, 0x61F56616F053D2F8ULL, 0x10BE47E64358F603ULL
        },
        {
            0xD94A89D78D8DA86DULL, 0xDCA004BB5B56137BULL, 0xEF55E1D774A692E0ULL, 0x2A5DCF715CF6441FULL, 
            0xA29DDA1588F86FBFULL, 0x0A1D8FE1BDC98972ULL, 0xD97E9D653353B820ULL, 0x2E821F43D992A00CULL, 
            0x7DEC934FB0DB5684ULL, 0xA0DF335D2DE66445ULL, 0xE84FE7FE8A28AF32ULL, 0xB3DC1BEE56E39709ULL, 
            0x9DAC59CDD835E23BULL, 0xFFB6D3A34F1F3CB1ULL, 0x4DC0A89DE077E857ULL, 0x8BD39DB1A91D7BEEULL, 
            0xD166934EEB2A85B6ULL, 0xE34A1F8B95B88B58ULL, 0xBD1C30F9E7A04A4AULL, 0xDCA313985678448AULL, 
            0xD32889C99918C894ULL, 0x69212DD3BB197A72ULL, 0x537E4EC9F09CE57CULL, 0xDF0BFD3978203D9BULL, 
            0x6F69A297E89B468FULL, 0x113336C1BA8D21A9ULL, 0xA1E11EE86FF0FBE0ULL, 0x7C7B210E1BB780A3ULL, 
            0xDD21B8B1BA8EBF1EULL, 0x5E7671115D866EFEULL, 0x26BA9F29FEA87426ULL, 0x0A69FB2CE4C351C4ULL
        },
        {
            0x684F2FF10367F469ULL, 0x33C3EBB2A8A391E5ULL, 0xC09E96E799974F64ULL, 0x1DDC379AE270DE1AULL, 
            0xD5EF30CA19EF94D4ULL, 0x23058CBB6234627BULL, 0xACB672DCC56372A8ULL, 0x5BCA8A208B7E0583ULL, 
            0x3B9579D0E6CF2475ULL, 0x3522A47FA3F30090ULL, 0xA363E066C42DAC33ULL, 0x272A9A0EFDE428C4ULL, 
            0xE952E696F443E0E1ULL, 0xC21927E70EE54A1DULL, 0x488C9357BD4750F3ULL, 0x9927FFB1765784F7ULL, 
            0x6BFD713CACECA949ULL, 0xFB35A4D0E043B122ULL, 0xBA153E0166D902CBULL, 0x8CDE9F8585826054ULL, 
            0xADA29707B66DB129ULL, 0x252F908835EF5325ULL, 0x276884514B91BB0BULL, 0x98D685354CAE1A89ULL, 
            0xFF8ED44E0ECFFBF1ULL, 0xF37EDD5ABC6C7A10ULL, 0x7EBF52AEDC2D062DULL, 0xE1EFE772FEE272EDULL, 
            0x3464C95A2438529EULL, 0x464B6D09D9C3AE4CULL, 0x503FDE70993AC329ULL, 0x6AAAA0C91FAF1ADBULL
        },
        {
            0xEEE269701C52D1ACULL, 0x74CA5B5AC52CBC0EULL, 0x0220998207C88AB7ULL, 0xA84A734E05553453ULL, 
            0xB93A16F01A44112FULL, 0xA9583AAD0DB6AA6CULL, 0x023F0796CBAEDE9AULL, 0xEC531865E811AEADULL, 
            0xDCB38C9EF02E4BB1ULL, 0xF53AD1E623C407BCULL, 0x763DE16CFA8A6ABDULL, 0xADE763FE63E31EE2ULL, 
            0xE7BA8E55B8C38968ULL, 0x1038A4DA9010847BULL, 0xE483103C68F3659AULL, 0x6BCFA2096FD70C43ULL, 
            0x61F6AF334F42E86CULL, 0x98A67DB5F8837CB5ULL, 0x7B6296382BFCDEDDULL, 0xEBE4806F6105CF22ULL, 
            0x5C71B9CF1DE67B50ULL, 0xE75AB99C4DA5CDAFULL, 0x3CFA20030E9D2A6BULL, 0x91730990FA18ADACULL, 
            0xFE96999DC87396EDULL, 0xE783E8F8AF6E56E8ULL, 0x0E7CDD6AD51ABFF0ULL, 0x0EFC96E9CB2F15A3ULL, 
            0x3BCCC51D04CE362EULL, 0x6A8311857B1B1E10ULL, 0xA9F45CCB4244D0D3ULL, 0x21D2E4543A557527ULL
        },
        {
            0xF095DA5FD6787CDEULL, 0x00FBA6C06392A9AFULL, 0xA99F0B2E4A9589D9ULL, 0xF9A50CD170881FE0ULL, 
            0xC37B9C0F32A1737FULL, 0x546B1AC02E795C26ULL, 0x0238BDA1543BBB14ULL, 0x97A35CFDE03C1DF5ULL, 
            0x2136F86DCF61E48DULL, 0x0C3C0A31A5379D71ULL, 0x0DCAD42CDF8B3DD1ULL, 0x359AA1D1D9975DB0ULL, 
            0xA7AA3F68285996E6ULL, 0x62799491407D0451ULL, 0xD4B02F2D08869AB0ULL, 0xDE2B088E16D7B0CAULL, 
            0x575138E44C43BFFFULL, 0x3BA71FA5059ECBCCULL, 0xFEE53583B6CB5DFBULL, 0xECFED5CA96DC83B9ULL, 
            0x5A565795A2A9A180ULL, 0xA93B5CEB79828147ULL, 0x3C4C8119F5C5BA9BULL, 0x103F8E7D13616B94ULL, 
            0xE0358E9BC05CB01AULL, 0x11EB736572DFC3D9ULL, 0x3ED16CC20841A44CULL, 0xEB615379AB5F21F5ULL, 
            0x0D21E2A56D600413ULL, 0xA65FA6D753F614F5ULL, 0x467BDD4247368A0BULL, 0x2069A8837B37CA9CULL
        },
        {
            0x27182CA4FECDF797ULL, 0xE50EE656075F0E0AULL, 0x36AFDC9286647051ULL, 0xD83ADF09CC086F78ULL, 
            0xECD7ACDBDE9C50FEULL, 0xD76CD4816C400233ULL, 0x59F6C93B634262A6ULL, 0xEDCA49A62912DE7AULL, 
            0x01C7651D7FB5AC0EULL, 0xCAC3949C80497F62ULL, 0x57248A1CCD1EB3C8ULL, 0x4257EEFB583C4E28ULL, 
            0xA4B4FFA789D21CC8ULL, 0xF42D2BB779DDDF17ULL, 0x3CC5C698E5DC5BDBULL, 0x0F11CFDF33713770ULL, 
            0x1835C743E358EFCFULL, 0x585CE34D33412D66ULL, 0x5CBC9D2060EE5CC4ULL, 0xB9DE60E30B8F7E6EULL, 
            0x219BE0E8AA889C73ULL, 0x887667CF97742948ULL, 0x827F754187E372F6ULL, 0xC47DBFF180CCD9D1ULL, 
            0x995180565E3061C1ULL, 0xBEF2C45F2B5B24E8ULL, 0xED62C6C40FC98B36ULL, 0x3E1503AA4630D8BEULL, 
            0xAF742272C16CE7C5ULL, 0x2C27014931158071ULL, 0x78F166D832455929ULL, 0x97167CD0840360C2ULL
        }
    },
    {
        {
            0x06D6F53AF79A824EULL, 0x110CEFAEDA837266ULL, 0x3D18DC4B37B3ED8CULL, 0x7D7BDBFF06791DFAULL, 
            0xE880BDFDBF8E3273ULL, 0x5108C37E75713D7BULL, 0xEEC864D6CC01B3D5ULL, 0xFAA5E565D4DF24ABULL, 
            0x38FD8973D5EA2E9BULL, 0xC1A7388B27BA0653ULL, 0xF90D4C798737514BULL, 0x902173EC5909E935ULL, 
            0x71641C8E16744B4BULL, 0x5F1E87C75FB49137ULL, 0xACCF8B743CED1EC2ULL, 0xBB690041B0A360F7ULL, 
            0x0733AD363931E540ULL, 0x63524739FEC5B8E0ULL, 0x094E876C833A42F3ULL, 0x55FC3F517A885715ULL, 
            0x0BF7A1E6208D2134ULL, 0x37742983A59EF0F0ULL, 0x1D415EE62BC259EAULL, 0x6D53CDE1F15C0012ULL, 
            0x0FA5820A1917A651ULL, 0x0F9F4A9BB511CF64ULL, 0x73252A48C2AE2556ULL, 0x07325A682B92ED0CULL, 
            0x2DD040BB61AB0D3AULL, 0xAE4CF2EC59CBBC8AULL, 0x900E5C300BB648FCULL, 0x949420B19ADBBE31ULL
        },
        {
            0xA69725EF23652F47ULL, 0xE2B47D5CAE9129C1ULL, 0xFB4A03773DC14AAEULL, 0x7B453D92DD43A0E6ULL, 
            0xEF13BEE8C1AAF4DBULL, 0x605E1F720BC6D75AULL, 0x12274E107D1110B1ULL, 0x0B3EDBBFE790FD42ULL, 
            0x6EF39435D34EE7F9ULL, 0x11859A6E6ADFF876ULL, 0x83BBC1EBFDD7CCB1ULL, 0x937E21C08CC902CDULL, 
            0x33C085EA498A7C2AULL, 0x89C176A20606DA01ULL, 0x13102B58838586DAULL, 0xDFA3E047297D4F38ULL, 
            0x58FD9C7CB48D68F5ULL, 0x2D037DD19FB0C480ULL, 0x21289A9F0D3B0D38ULL, 0xB7035355B2CAF624ULL, 
            0xFB8537D59ED8AD02ULL, 0xE9CFC271A2553D4FULL, 0x21E5DE7EC173E9C4ULL, 0xA010240198EE5C7BULL, 
            0x8CAFCD0DE9554D66ULL, 0xCDE442C52445E728ULL, 0xC5F382F31F391E4EULL, 0x827C9A640C650770ULL, 
            0xD4451B0B7F6AA448ULL, 0xF8A059AB0EAFAA02ULL, 0x28A365F971D0039BULL, 0x9A5CE329FC033106ULL
        },
        {
            0x37A8694386A1E22EULL, 0x7D84AECF3226834FULL, 0xD4A4E49D44A3943FULL, 0x17F9027A896333B9ULL, 
            0x760529A942665EA6ULL, 0xCDBBD7104218FB9EULL, 0x241F4A9582711A2EULL, 0x868193F08C0757B4ULL, 
            0xE6A387249E21E9CCULL, 0x7B8056DED02D5A6DULL, 0x9A82A97F0CED5653ULL, 0x3AF55076E1CBAECBULL, 
            0x0752834134CE871EULL, 0x78CF247566E96A25ULL, 0x7B99A85A6D9E709AULL, 0xFF669F8A35508C26ULL, 
            0x5BB2367F55FB400BULL, 0xB470767A640BCD17ULL, 0x9D6006407AFD566CULL, 0xBC7E877C35D8DEB5ULL, 
            0x310FBB11626DA242ULL, 0xDF583092B14D1365ULL, 0x2EAF60A31EE27A70ULL, 0x753F9AFA59802F13ULL, 
            0xE1ADDBCDC98D118FULL, 0x3D60167F7E033704ULL, 0x9162DCD2052B39D0ULL, 0xEDD8182813F20759ULL, 
            0x0F19AF4430F39D73ULL, 0x89F6C19D8494FACFULL, 0x4475C1B8A51E782FULL, 0xD777907DD7AA567FULL
        },
        {
            0x3518948CA46C17E9ULL, 0x3E46EBAFB1926A2FULL, 0x24B27A524BB04D0BULL, 0x33FC76DA605E5A1FULL, 
            0x50E7870BF0849387ULL, 0xA380D429A836FE64ULL, 0x0B29E51B18A6DFF2ULL, 0x519ECDFA53D2C9CCULL, 
            0xE7A1951A0F68E213ULL, 0xAF0DBB6284E9D139ULL, 0xC6330D81E8324E36ULL, 0x97F6E7A37D66A9B1ULL, 
            0xA4C3C36D5E95149DULL, 0x9E1C310ADCDED473ULL, 0xC76FC983354879F1ULL, 0x0BF4141AA23ABB39ULL, 
            0x973B6CC2B2C53378ULL, 0xDBF073009EF5E7A4ULL, 0x4C8EE8425DDC8C2CULL, 0xB9395D777E74D2CAULL, 
            0x3F7D4933A33026E2ULL, 0x0D3C1C38FE826144ULL, 0x01881A15EB6FB8A7ULL, 0x7271D2EE30B32A1DULL, 
            0xE688746AF9DAB5C7ULL, 0x9594C2CCA3BA9F12ULL, 0x234149D6760559E5ULL, 0xCCDCB638F6A41151ULL, 
            0x82781582C82ED1D9ULL, 0xAA4D234D4CF7DB29ULL, 0x7A721FB25F11F20BULL, 0x9D1A3E46191D650FULL
        },
        {
            0x8861FD3A1E63B054ULL, 0xB9E8CB5A21607A11ULL, 0x2A58A08E8AE3D31DULL, 0x9661A1477FADA013ULL, 
            0x4346187B2F37762DULL, 0x0883442000079F12ULL, 0x4E146FB04FA28BA5ULL, 0x371D4270E3765BDEULL, 
            0xCEC40BC6FA10DC07ULL, 0xF3939BDDEE3C621DULL, 0x7B8923F754C25F67ULL, 0x6DD9A969A958C141ULL, 
            0xCAB95D32DD61CC15ULL, 0x286BACF708583CCDULL, 0xAA00503CFF09CDEBULL, 0x2FA13CB1FBAC82CDULL, 
            0xAD31EDEA54446670ULL, 0x78CBFF9615293B06ULL, 0x6B3E895F535DDC71ULL, 0xCB3FCF0FC507DDC1ULL, 
            0x22F4345DFE880723ULL, 0x18D1CA427F6A474CULL, 0x8740125E99CAE262ULL, 0x1FCA475B441318F0ULL, 
            0x95586B1F15871CA5ULL, 0x4F77453DF7C5F47AULL, 0x018EDD8A52656888ULL, 0x933D5AA663D6D7E9ULL, 
            0x96FA3AADB5787359ULL, 0xEDADAF19D63AD051ULL, 0x18CA8F0E403058EBULL, 0x64387B9B350E5AEDULL
        },
        {
            0xF6AFF12F079D62F1ULL, 0xAEF1384F65A9886EULL, 0x4ACE8E72499E0075ULL, 0x932BC4BDC3AC6595ULL, 
            0xCB861D7D634BE48DULL, 0x93B159B4C4434115ULL, 0x3F5B8AFD55742332ULL, 0x482B30D30335BDDCULL, 
            0xDD7757F0E8AB0629ULL, 0x737CD65AB08F62AEULL, 0xAE7E42CACD4CB813ULL, 0xA83A8ED12E239143ULL, 
            0x0C7544A5656A85CBULL, 0x825A6EA7FC97BBFEULL, 0x3794C14A6950C107ULL, 0xF934B65EA3E4286CULL, 
            0x2DB8EF0464C65822ULL, 0xAAD246D6066B619EULL, 0x4B2BE1B231010263ULL, 0xB056A333FCE05C33ULL, 
            0x9E8EEDE7DC72DB62ULL, 0xF08CFB2A7D34FF8AULL, 0x42ED951BDBCD9AE9ULL, 0xF91DA7511783C9C6ULL, 
            0x688FEB60A8DB5BCEULL, 0x6E4761F2240380D6ULL, 0x7FFBC184E605873CULL, 0x2623036D650DCDACULL, 
            0x7514136457A2BB59ULL, 0xA0B18863E8CDA738ULL, 0xDC7DB4CD1DE94676ULL, 0x80B92B20B59F52BBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseEConstants = {
    0xD98BF3F70D311B3CULL,
    0xE02422CE684FBD5FULL,
    0x638B45FD04401297ULL,
    0xD98BF3F70D311B3CULL,
    0xE02422CE684FBD5FULL,
    0x638B45FD04401297ULL,
    0x64767B569A8B0348ULL,
    0xB45F4354ADC91E6EULL,
    0xC2,
    0x7A,
    0x16,
    0x8A,
    0x34,
    0x99,
    0x10,
    0xE5
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseFSalts = {
    {
        {
            0x79CE5648BD3457BBULL, 0xEC23A4315B7A215EULL, 0x7E1417B8F6D4E236ULL, 0x5A28FE59E06261F8ULL, 
            0x76ADD86FF68790EAULL, 0xAF085AEF7A4BDBADULL, 0x83BB6CBF0D2D4537ULL, 0x34709944F8B6F42FULL, 
            0x7585FFAA412CCA72ULL, 0x18DFE4F3BA63455AULL, 0x67F67443334A057EULL, 0xB9D8CE9EA40ED81FULL, 
            0x13154CD51B3936D1ULL, 0x940F84D975D47CB2ULL, 0x37CE49C9FCE5B4FBULL, 0x21440A02C997D155ULL, 
            0x1C3E10DBA116E30AULL, 0x80FE56A707426FE2ULL, 0x4E5AEEAC928E9F99ULL, 0xD3977061DF4EE684ULL, 
            0xAEDA5534F1B0940FULL, 0x131C625FFED05717ULL, 0x0418C57AD7C43118ULL, 0xA0992E685BA3D9D5ULL, 
            0x4042D37F195E8B13ULL, 0x0A1ECFAEEFAB94EBULL, 0xC9337EC9EA406F4DULL, 0x3BCB9174F411A2F1ULL, 
            0x7B7223B568C0AE9FULL, 0x3D60E348077AEEFFULL, 0x3F52515B656054EFULL, 0x1AA0CCC4DD666EEBULL
        },
        {
            0x83927E1ACD104608ULL, 0x9F50A164ACAFA4CBULL, 0x958D47B18ABD7ACFULL, 0x06B7887FA7B0289CULL, 
            0xD9AF1068557D6B38ULL, 0xB9AB663C506F4008ULL, 0x48BFB5F49D654F14ULL, 0xA3DD38F0109843C0ULL, 
            0x5CF6A84A548377F1ULL, 0xFD6A924BEAE80E3FULL, 0x0CBB55169DF4DA81ULL, 0x7BD26D837C8CD468ULL, 
            0x559CC8534A97B770ULL, 0x0C4027C6C1F8B569ULL, 0x4FD52B33604B6536ULL, 0xAEFA33119E1423C6ULL, 
            0x8177DA299F40151BULL, 0x6563D7BFF01029A3ULL, 0xC1D4C5DDE397F998ULL, 0x881FAA01B05BDE7BULL, 
            0x27771D87AFF086EEULL, 0x473852F109922BB5ULL, 0x9290F92551A530FDULL, 0x3583C8542ABBEC4CULL, 
            0xE1A3FCFB63CE1468ULL, 0x840DA95D658DB7C2ULL, 0xB43ED69A55AD359AULL, 0x04140AA5C93582F4ULL, 
            0xF72AD1766557104BULL, 0xF9414580D1B4ADD1ULL, 0x75D6DBBEDF9D9CF0ULL, 0xBB23D9B01360C11DULL
        },
        {
            0x90E261C2C314029FULL, 0x492F2D1246730C4FULL, 0x646B037E5EB660ACULL, 0x09577F659686A062ULL, 
            0xE2E4D1E2928FC24EULL, 0x2F181EC989423B3CULL, 0x4D95E0F2C8FD8E77ULL, 0x637EF23E879A8DA8ULL, 
            0xD41A814A8FA323BDULL, 0xB6B264A9F69C9BC4ULL, 0xFB24C93779CBA265ULL, 0x2ADF41C5414C5510ULL, 
            0x05A5C9CAC99281B0ULL, 0x2B0A0510F74BB339ULL, 0x7DE5BD9B7C880A97ULL, 0xA8B20B93D6640272ULL, 
            0xAB44C3122AA0C260ULL, 0x1888DB1BD161B783ULL, 0x79225D666B4EB3A5ULL, 0x1FC92374681A09EDULL, 
            0x20E5788D3659BFEBULL, 0x33972BDC19124A75ULL, 0x63730C1BE1311472ULL, 0xD152056752DC60DDULL, 
            0x4A61C5B01B613A7FULL, 0x4EA7B5BD24EAEC8CULL, 0xE47A4E61783C23B2ULL, 0x5899834EF983AA79ULL, 
            0xA8BD3A11A092A1B6ULL, 0xE066F3D1C2E467A2ULL, 0x539FFB7AE91CB72EULL, 0x6DDA0FDF15AA9C15ULL
        },
        {
            0x75438CA0AFC5164FULL, 0x7E80E2F5D5750CBFULL, 0x70322F4FBB31387DULL, 0x24E2121D99EFA7A8ULL, 
            0x090C08B7EAA4A3D0ULL, 0x4679B664853BA69BULL, 0x10289EFC3E650D62ULL, 0xC416C3DB5E7CDF1AULL, 
            0x52CF3EEA0078813EULL, 0x277F3CC758595284ULL, 0x616F2A5A416E1366ULL, 0x810C1CA4BA510B2FULL, 
            0xBBA08D3B3BB1CF22ULL, 0x8256C7E15F335747ULL, 0x4642CD15D9FEDD80ULL, 0xE1FB0A28DA36DA9EULL, 
            0x385D8308AD2288FCULL, 0x53FEC4A06F4E5644ULL, 0x217B8769DE04F4F5ULL, 0x243A55AC7DB5BEB6ULL, 
            0xDCB7691B8F3EEE3BULL, 0x120E5DE3619C6956ULL, 0xE151F73C8A568CAFULL, 0x5C4035A3D790FCDFULL, 
            0x1FCF9F4395B5510FULL, 0x83B77202BBD9C7D7ULL, 0x2DD93E6B446A273CULL, 0x4DCAF719193756B1ULL, 
            0xEE20E8FCE934EABAULL, 0xC68D2982015DF795ULL, 0x66BD1CA322C24ED8ULL, 0x7175119A20795248ULL
        },
        {
            0xAD0D4F112F1E76A9ULL, 0x9263ABBFBF150835ULL, 0x88AB552FBD354327ULL, 0xC1EA5042878D8DF2ULL, 
            0xA0DE8188E659A84AULL, 0x0E2326128C5EC60EULL, 0x956D7ECB567A86ADULL, 0x11F4E31E69489389ULL, 
            0x9474529152B73790ULL, 0xCD91A804B3E73235ULL, 0x95200B8EF7C50CD4ULL, 0x719A63F09EA499D3ULL, 
            0xC38957DF5228F614ULL, 0x276B9011C00C2A88ULL, 0x05076F0261332C2EULL, 0x79EC551009883FC7ULL, 
            0x33ADD1996A085F60ULL, 0xA544545FA7844F15ULL, 0x457E734D15C0D296ULL, 0x8F2E2101C94B44E8ULL, 
            0x7D5EE7DBB04CB713ULL, 0x589D3C9D31251E7BULL, 0x7A32841511C940EDULL, 0xE581ECE6C91A3253ULL, 
            0xF4D2B60F87DE783AULL, 0x20F5A42A795B50DBULL, 0xFB3E5CE0B4818801ULL, 0xE1F456746CFFC2AFULL, 
            0x08B94A32D74F7521ULL, 0xBA756F4CF9E7C54FULL, 0xB6A162F8D205880DULL, 0xD5B81FB55040D82AULL
        },
        {
            0xCC2377140ADA3C47ULL, 0xBBA464F59ADD4CEEULL, 0x569E08648214052DULL, 0x62418D2E63BCBF42ULL, 
            0xA129F2C0B013D4C4ULL, 0x5A0294237A2BFC23ULL, 0x94DFF184B7E30004ULL, 0x47F00B401BB9BF6BULL, 
            0xFDB7DE4F67E77616ULL, 0x852DEFB97118C171ULL, 0xF2B44F1FF65CACE0ULL, 0x0A0D5E2333A0E0B3ULL, 
            0x10847CC96CC867B6ULL, 0xC4122DC8EAAB74B3ULL, 0x3F1622FFB21ECF70ULL, 0xE32B7818553ACB20ULL, 
            0xC3A850C27B03D26CULL, 0x3EB32E6CEF13A65BULL, 0x80D265D5BE1D4F75ULL, 0x222BF1478C143C6AULL, 
            0x1ED24E3570EB8B87ULL, 0x40F4A4EFB7D4201FULL, 0x6D1475A16CB1D374ULL, 0x584884540B5DC542ULL, 
            0xA059988E8AB65CDBULL, 0x77B0A8D0E3AE344FULL, 0xD66540B4CF28C1EEULL, 0x74312878C05A0081ULL, 
            0xBCBB2E5EB2058743ULL, 0x7CEF74BC470C496BULL, 0x79F8915A4DE38E58ULL, 0xC84B2DC2B8067B9DULL
        }
    },
    {
        {
            0x01EDF411CD27BEC1ULL, 0x95CD648D47B1F304ULL, 0xBFF9B53D3194DE1EULL, 0xE0465E174D52D0F2ULL, 
            0x92D140767020D644ULL, 0x19CE3EF64AE6BF5BULL, 0x85CA556C57FAE291ULL, 0xD932057BAE43144DULL, 
            0xF55C0AA0D54260DCULL, 0x0414E981C40E0D86ULL, 0x08F78A098895F7D3ULL, 0xBBFE58D02FE2F7B0ULL, 
            0x54A93F7223DB132EULL, 0xB5F6CCF841C7C622ULL, 0xB3CC5D40B6C41A7DULL, 0x3D48536CB963BC47ULL, 
            0xDF17A89D8EB941EEULL, 0x7F530D4A08720CFEULL, 0xA8D550DABD8955C6ULL, 0xC174DCE7C4E6559CULL, 
            0xB2D5A2D285561B63ULL, 0x48FF6B4D72F234DFULL, 0x27112E68B6279704ULL, 0x4615E041B9E9B2F6ULL, 
            0xD1656643FB83B2F5ULL, 0x581C6F1538B9D072ULL, 0x657F6F53DE1AFC44ULL, 0x201E5505D146FA46ULL, 
            0xD74E94811C0D3559ULL, 0x3AC29BA1EEA7C36CULL, 0x58A7AC3E01B58184ULL, 0x007C6B31EFF5A7F1ULL
        },
        {
            0x7C19AD71AAA7BA23ULL, 0xECAFFA397CBDF4DBULL, 0x90BE47FEE071DEFBULL, 0x5C4FBB0A3E5C7640ULL, 
            0x53ED3D2B21C54786ULL, 0xA56846D827512F06ULL, 0x46392282C7071091ULL, 0x1619E0C40B1A3EA1ULL, 
            0xA2980168F4E8A292ULL, 0xBC3DAFAB3DC64620ULL, 0x6E793DDB7A19FD37ULL, 0x2B02FA89FA5CAD60ULL, 
            0x5428A8DD31E6F975ULL, 0x90A0996A234C1074ULL, 0x94A736EBB998738EULL, 0x6E3C6B332B9BF6C9ULL, 
            0x10AA47DAF074F282ULL, 0x56CC67857628AEA2ULL, 0x2538CA4FD83721B3ULL, 0x3B74B8817278FFA1ULL, 
            0xB1B08F7E99E5BF19ULL, 0x4E002EDA2F2B0E14ULL, 0x5C26F8A5F1F2C39FULL, 0xAE15BC0F00946B8BULL, 
            0x5A6CCF4E6C1D35A2ULL, 0x509F74D18CED631BULL, 0xEC42556798E06623ULL, 0x9A370275E126E965ULL, 
            0x152CF817A88C4387ULL, 0xB9F2F742D3DF30A6ULL, 0xB786DD5174D0958DULL, 0xEF2C164D52F2F8CEULL
        },
        {
            0x3C56B148C93E410FULL, 0xA189FEBA5090AE8BULL, 0xD2D6564FDF75D9ADULL, 0x74DAE2D4F22F9FF8ULL, 
            0x0C963B613EBF4AB1ULL, 0xBB9DEDFF237EAB4FULL, 0x4454AF3CFB408BB2ULL, 0x355B5D0157FC0277ULL, 
            0x92A054BED78FC757ULL, 0x9F7EA0D463409226ULL, 0x22BDE471CEBBC426ULL, 0x3264B997168CFC69ULL, 
            0xD5DFE6B1B4B3DA8BULL, 0x3E90E6B1C5CEEC8BULL, 0x4CA1025FB6EE33A8ULL, 0xDD32E73CEC2AA337ULL, 
            0xEF62DC46008EA5DFULL, 0xA11712F3F2ACBD02ULL, 0xF7E4186ED41A35F5ULL, 0x01F3BCE739163318ULL, 
            0x5708001F93495E07ULL, 0x449D96834A21826AULL, 0x8C7ECC22168D69CAULL, 0xDFD546678EA0D13BULL, 
            0x9CE09404AF424BB3ULL, 0x626DFE9CE1E3C13FULL, 0x50C6D297DC5911F2ULL, 0x2B49E86FD3E11009ULL, 
            0x23C4EBE1AA560E70ULL, 0x08114173F9B78B79ULL, 0x412D2DE57847F308ULL, 0x7BBA38998C9C2D7CULL
        },
        {
            0x468B094D36418351ULL, 0x695360A4CE495240ULL, 0x39219EAAB9F5A821ULL, 0xFD5C7850FCED413BULL, 
            0xBB3BF00E2A1945AAULL, 0x54AF8DC5770C0169ULL, 0xB75E2D942F768641ULL, 0xA43094A92668A5A8ULL, 
            0x8AEBB77C37EB3953ULL, 0x119E6D362CBAB934ULL, 0xD27FE2AE49A1DB58ULL, 0x3F9D238BAF70B35AULL, 
            0x4301AD6AD910F0AEULL, 0xA4E5A6DC2C953F1BULL, 0x815B7A8E5926CA76ULL, 0x12D1AD6D8E2F03A9ULL, 
            0x5358A5B6B814AE83ULL, 0x7396BE7FF727B760ULL, 0xC9C1FE1FE334742EULL, 0x74FAC10776F69A12ULL, 
            0x9A6FBA3177874C46ULL, 0x67DE1E16FFCC6A8CULL, 0x76E0175FE94F713FULL, 0x500A4207E24D079DULL, 
            0x37E2A3B1EC20EBDFULL, 0x9229C170B9AB323DULL, 0xB470B4CA81EC60E7ULL, 0xE4AF0F3C9D7D6AC1ULL, 
            0xBDB8EC5B229A6EADULL, 0x36EEEEEE6F7A3355ULL, 0xB67D23366BACF476ULL, 0x52A7AA018EA7B25EULL
        },
        {
            0xB6850E9B9C4F2B0EULL, 0x969E000585EFD6C2ULL, 0x23D401AA4389459FULL, 0x43BE3834209DC8F6ULL, 
            0x3F4878078AA3D9EDULL, 0x35E1C3D99D7A57C3ULL, 0x051AB71424B1B8EAULL, 0xFE65FE1F915AA721ULL, 
            0x57953771CD7EC53DULL, 0xAE2868041832AEF1ULL, 0x916A1687CAB49369ULL, 0x0D8306CA942F36E6ULL, 
            0xA40549376FE45E81ULL, 0x572A8603AA0CD4BEULL, 0xA9FF122BDEF99562ULL, 0x43310C95B01615A9ULL, 
            0x229F78A87ADD0D8FULL, 0x03DCA8D88E9BCD4CULL, 0xF4600885123A3B38ULL, 0xCBF5DC881E76C59FULL, 
            0x6776FC7F221C0289ULL, 0xB9B507BD354FF1F6ULL, 0x851F526F8D5E1E7DULL, 0x0C43154F7FD46324ULL, 
            0x4C177E18534BC1A0ULL, 0xD0509CEE05EDC432ULL, 0xE9ECA1A9CFDAF4AAULL, 0x4EEC2771241BD107ULL, 
            0x5EDE734E557E0E9FULL, 0x9220C744E9414C46ULL, 0xBD51BB886EDF815DULL, 0xDEDAC83D194B4335ULL
        },
        {
            0xB381432DC2754DA6ULL, 0xE0484ED39522983EULL, 0xF02CADF6982DA81BULL, 0xA47A712AAAC16C7CULL, 
            0xEBE9D9375B4A4753ULL, 0x0343267EAB3065B8ULL, 0x815B4496339C9072ULL, 0x4D3DF990093EEE18ULL, 
            0x273A646A4CEE3109ULL, 0x69442FA9B627804FULL, 0x99B5EA69F6960B99ULL, 0x3CEBE45D59ED4E8DULL, 
            0x8D42336978AFE05EULL, 0x58E2BD0D69E75915ULL, 0x4AE90FC6F4132C1FULL, 0x3EA6078FD7C72975ULL, 
            0x15F682069407B82AULL, 0xA0D11BD58E494B24ULL, 0x2626B2D2FBBA044FULL, 0x090BF3D17E83DA0CULL, 
            0xBF7B199C057F2A7CULL, 0x119BEA7A8E065ACCULL, 0x6273C5F14BE1FDECULL, 0xBB40F31B6C60A6DEULL, 
            0x1C99019EE77FA162ULL, 0x50154BA2EBA628DCULL, 0x319F4E5D9FC4617CULL, 0x08031BCB04EE2A8AULL, 
            0x27E4E1B0AAF0B3EEULL, 0x131135BEDCDF334FULL, 0xE2E91C19CA170C38ULL, 0x611DB57E7269C7A0ULL
        }
    },
    {
        {
            0x54A29123EE5C303AULL, 0x6A0E15927F98B728ULL, 0xCA3E173E991CDDA2ULL, 0xE5304404F3E8B1A1ULL, 
            0x859705436E26A1E9ULL, 0xB404F2F688D4368FULL, 0xB1C745175EF4B65CULL, 0x678C835F7E845695ULL, 
            0xF67E500CC33A0F39ULL, 0x579D824F3C0446A0ULL, 0x1E5643EB116BCC6BULL, 0xFB33B18FD1EA3C41ULL, 
            0x6DEF7E67C09F6E65ULL, 0xF88D4333108CBFFBULL, 0xB476E964279EA785ULL, 0x85AF61B58D82C49BULL, 
            0x012E46A2699ABFB9ULL, 0x00E5F8DCB8AC5B68ULL, 0xD2157644DCA5E970ULL, 0x668B8FB6429F2BB7ULL, 
            0x1306ECA64DA38A31ULL, 0xE2A36E1C02F6BBD5ULL, 0x4C00055CFB3E0B3BULL, 0x36D929B9CA207D7EULL, 
            0x8CD9079987B0AECEULL, 0x69A7453AB417C7E5ULL, 0xB9E5F71F6CBAE57EULL, 0xC0F07F27209196A8ULL, 
            0xEBA0B8D0A65B0DFCULL, 0xDDF422A6906A6646ULL, 0x758DD363DCEE1467ULL, 0x7BF11F63548A99F8ULL
        },
        {
            0x5CD6DB34BAD4E8F1ULL, 0xA6D76821F4737FDAULL, 0x5A516077C50CF2F6ULL, 0x04D50B54593BDFA3ULL, 
            0x692C0D1798DA7509ULL, 0xA1B5E660955E4068ULL, 0x399ED00E32E9BF21ULL, 0xAC42968E93C0B341ULL, 
            0x90EA703094EAE2F3ULL, 0x171634FA04BD6969ULL, 0x8286CFEBA321ACE4ULL, 0xBC22B5909D0ECF40ULL, 
            0xED2382E367BED5F8ULL, 0x3E70F2F8E08B0C29ULL, 0xE326FD4333C773F9ULL, 0xA42072383603451CULL, 
            0x3BDEA92069B4E2F9ULL, 0x9E2714D8D28BD38CULL, 0xCED8230249E9E5B8ULL, 0xB2466D5EA81C4CEFULL, 
            0xD418AB8D7E73BEC1ULL, 0x6FCF4749CAA571B4ULL, 0x1AD247DED0A370CBULL, 0x8F849E3E07B7CC52ULL, 
            0x2B66E77F71FE49EAULL, 0x97B1C68720594B17ULL, 0x02728E787088F915ULL, 0xABDA5FFEEE887C31ULL, 
            0xEF7269BD2B75BC30ULL, 0xEE4980C29CA42D66ULL, 0x70151107ED694501ULL, 0x2ECEB6BFC66E250DULL
        },
        {
            0xB01E6A6A33B4D3FEULL, 0x37B8B5164BCE6434ULL, 0x29A66D8839C46AF3ULL, 0xC3E2068ECA0E5E24ULL, 
            0x03D81A3E11A5AEC3ULL, 0xB302BCB94A7C48D4ULL, 0xF192EE90F9926496ULL, 0x1BA236BA62518BAFULL, 
            0xC22064696EAAFC97ULL, 0xC297004EC7C8D3B8ULL, 0xF972A9C6BC5C26CAULL, 0x4F8FF88C142A9F48ULL, 
            0x159476D3888D03A3ULL, 0x119731FEA5B26CABULL, 0x065B36CA6A14C1E4ULL, 0x74A834075B7A5BD1ULL, 
            0xC4616CF60E37EEFAULL, 0xDCF6253DB2EA20BBULL, 0xB6CB65E6B8B4B4F6ULL, 0xB1CB8A8ADF20B0E0ULL, 
            0xEB22E64E85EF66CEULL, 0x2E6E3E524D85DD01ULL, 0x142BD6B5CD9EBD6DULL, 0x96DD23D29A97C763ULL, 
            0xA0A3348C445DD859ULL, 0xE9794E0CA6D2E13CULL, 0x1225E2A85FBC815EULL, 0x50D1BD5265BB1905ULL, 
            0x080A73B5D9D7E725ULL, 0x7589E99E65048B43ULL, 0xC494CB0BAD4F0304ULL, 0x59F111BE7EB320C4ULL
        },
        {
            0x2ADB05102E1D4FF8ULL, 0x3061054AAEF3D20EULL, 0x458B7E850E19BD9CULL, 0x32B02D6FAB96FEAFULL, 
            0x2A66B38CBCC5AE06ULL, 0x32E6D591546C8079ULL, 0x547A38B62766DCAFULL, 0xEA4E4DF7BF2ED57BULL, 
            0x659328EBB9C4561EULL, 0xEAA8411A582DC784ULL, 0xFDAB49AB224D76E4ULL, 0x0334BF710E235AD8ULL, 
            0x915C1954CDD273FDULL, 0x9D94C7A19550EE7FULL, 0x3D22836DDF5A6429ULL, 0x35CA17A8BB95FC36ULL, 
            0xC239D0BADBB6C6BAULL, 0xEC6362CD86E8CEEFULL, 0x30B1BEC4001856DAULL, 0x4139AA74B94933CBULL, 
            0xE9D9054C86293584ULL, 0x181BFD7CDBD05E22ULL, 0xB2E909E245019E09ULL, 0xC03D35AD9C80455CULL, 
            0x9E5DF891F214824FULL, 0xBEB799E01F3EAE60ULL, 0x8E7B34914B17B7DDULL, 0x58083CAC3A1BC7B1ULL, 
            0xC2FC0825973C9CD8ULL, 0xE350DB939D00BF9DULL, 0xC77B17015FA11F8AULL, 0x1CE28EBD03E76D21ULL
        },
        {
            0xFD9D64CEC54BC95BULL, 0xF58D0AED44BE6D29ULL, 0xF188240BDA77B3ACULL, 0xA10E1A1A6FC4CD66ULL, 
            0x6ECD17691136C17DULL, 0x8D0FC84D81EDD662ULL, 0x45FE0982D92FC6F8ULL, 0xEFFE1C779A451963ULL, 
            0x67CCCBC1DC8F9F50ULL, 0x4590AEFB99CF155AULL, 0xC81C35A6EA5CC675ULL, 0x32FDF3F50D1D33B5ULL, 
            0x8F908A06B8DBC1F0ULL, 0x6DD4357ED9AD2D32ULL, 0x5B0DA99E6E6E8F50ULL, 0x42810D22E61EBBDCULL, 
            0xEE6A40D59DD057FEULL, 0xFAD65B6D11B0146FULL, 0xCEAD17FA76492FEEULL, 0x916CCF7FC3EBFCABULL, 
            0x46FCD5E5FED799B2ULL, 0x75371F3BF0F70B34ULL, 0x3DF32F3D210999AFULL, 0x9AB98C08CE25AE72ULL, 
            0x6B3F690DD4E46904ULL, 0x2A718B0916D5C434ULL, 0xCFBF5F2377398BF6ULL, 0x632F3E19D20E5EB7ULL, 
            0xCE1DD2780C732A4FULL, 0x1051FAB7FB3D390EULL, 0x3769B2AA377E42A3ULL, 0xA28E5C84E34B0CBBULL
        },
        {
            0xB35B0884DD283805ULL, 0x42AFAAAB20B29DADULL, 0x5CAF3F1696C702ADULL, 0x098EC9CAC45652BAULL, 
            0x20619614296E8621ULL, 0x798AA3F892195679ULL, 0xD8C74D6220845F7EULL, 0x196FD53086E5A209ULL, 
            0x2AAD34D3BB079E96ULL, 0x20D88D3BA5070B05ULL, 0x690404F39ABDB8E1ULL, 0xDA313B0C7A04DC4EULL, 
            0x5B277B7C42E49865ULL, 0x6A8101CD4FEB03C2ULL, 0x3076773B9580C230ULL, 0x8AB808FEF24CC253ULL, 
            0x525599861EB77F88ULL, 0x4AC64AEE4401645DULL, 0xEDC80E95371C8D3BULL, 0xD1A11C7AA9586B10ULL, 
            0xD0EB423B94D43044ULL, 0xC722921503067FD4ULL, 0x1108F7DF68A1CDFEULL, 0xD764BCC10BEDBCDEULL, 
            0x405990658C983EBCULL, 0x058CD6E66AEF92D1ULL, 0xF55847D09DD8A323ULL, 0xF1C6B0E87AFBDA65ULL, 
            0x40ED5B286ED7D83AULL, 0x927A04E505DBC232ULL, 0xF5C56D82A842FD37ULL, 0xA5B32640A9363889ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseFConstants = {
    0x07387856E3B9A372ULL,
    0xB83EC7ABB1595A13ULL,
    0xA3111200A438492FULL,
    0x07387856E3B9A372ULL,
    0xB83EC7ABB1595A13ULL,
    0xA3111200A438492FULL,
    0x427A734C2C251C95ULL,
    0x39E2A3331A5F4091ULL,
    0xA3,
    0x30,
    0x8B,
    0xCA,
    0x8A,
    0x01,
    0xC1,
    0x31
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseGSalts = {
    {
        {
            0x552BF43747A09255ULL, 0x4D5CAC5E12B53FD0ULL, 0x7E45F0D9F87FDA62ULL, 0xB45F3505405BEE3DULL, 
            0x3AE1774C1995FA97ULL, 0x3341072B1B56D3CAULL, 0xF289A80C90A17C74ULL, 0xB48F28814784B935ULL, 
            0xEABA543ED85816FEULL, 0x89BF32A0D13C8309ULL, 0x69C183667E2ABB71ULL, 0x56CFA4CAAC2000A1ULL, 
            0xC9C8488C7AEE4E1DULL, 0x6D5BF8E2343A5D13ULL, 0x3ED71B54109C7BFEULL, 0x71832322398F3E61ULL, 
            0x039326706D622E33ULL, 0x92BB072E6BEC43DEULL, 0xD606425337F9C3E8ULL, 0xA0FA93DD2FD922E1ULL, 
            0x3ED0CA2639B7137DULL, 0x959C9E5A482A604EULL, 0x647353E629C1E3A8ULL, 0xAAAAD60E677007CCULL, 
            0xCFC4E2763AA55D17ULL, 0x97D8CCE77B1DE5EAULL, 0xC205D348FAA88B4BULL, 0xDB9F90B8030811CEULL, 
            0x0B388FB003D05602ULL, 0x5599DCB920B190C0ULL, 0xB37F2290C593DC85ULL, 0x8D63F3EAF4CDF5D1ULL
        },
        {
            0x262D9B326D03FFD3ULL, 0xC8779D0CBD3DE76AULL, 0xCF8A47020EDF4343ULL, 0x4A8D631B04300001ULL, 
            0xC9B1DE91BD2D6872ULL, 0x6A09A0BA72EBC19CULL, 0xD52C4CF14F8CFD58ULL, 0x6D90462651C49892ULL, 
            0x49B4F725EB3D029CULL, 0xF6DDCC1DCF18FC7FULL, 0xE0CFDD6D041D7A30ULL, 0x64AD155B6CA23778ULL, 
            0xE202FE8227DD9A74ULL, 0x506FBE15D6342551ULL, 0xA9A00AF9C2DB61D9ULL, 0xF8425291023249B6ULL, 
            0x85DB3D5D9B0FB120ULL, 0x1AC29CFFFC8FDF42ULL, 0xA29A5E0E8BE1365CULL, 0x17F43153CE77E73BULL, 
            0xA52F29FA58C16D52ULL, 0x273DAF1D19BF44D7ULL, 0x0830A62F003161CAULL, 0x8911A2C820B63CE8ULL, 
            0xD667CE490F5B8D60ULL, 0xCCC1525FC7345846ULL, 0x89368B58F215E0F6ULL, 0x84F7001766EA8395ULL, 
            0xE573D72B5C46EAE1ULL, 0xF0B179427BE2537EULL, 0x1AEAB96BD6649D18ULL, 0x1CB8B384D4EC0D2BULL
        },
        {
            0x55DF12AF84EEDEC6ULL, 0x7663BB52CDB33D54ULL, 0xC96C8399BFF4BF3BULL, 0x522870F69BA979CCULL, 
            0x9903EB8C6797E17AULL, 0x0885AA433F05FD87ULL, 0x8A81CC2847049452ULL, 0x5369B0675745C8A2ULL, 
            0x0475F5C4B45DD1D2ULL, 0x9753BE62533211ADULL, 0x39E133C88F6C160DULL, 0x79EA35740271C732ULL, 
            0xF4B5BC765813A3CBULL, 0x6F52765864359FEBULL, 0xB768A97C32607F5CULL, 0x3F4EE8833F809C42ULL, 
            0x55B624D3C2235B34ULL, 0xDCC80A79E8C91680ULL, 0x36D8F7F9E7E56C1EULL, 0xAE4A2A6090EE2D69ULL, 
            0x8B377EE426E76AA2ULL, 0x2513E9FC342A411EULL, 0xC174FC1DD8C73DDBULL, 0xA67C1E6A03C77217ULL, 
            0x36A4B503369F7BD7ULL, 0x71C238CF7BA26FB1ULL, 0x76E0D9ED09B072A2ULL, 0xE62A66C1C75657B0ULL, 
            0xED5B52C91FDE2146ULL, 0xE9569A0475626983ULL, 0x1E77F8DBA26B278CULL, 0x083BCC560A949AEFULL
        },
        {
            0xD661B8761CA73B71ULL, 0xBCABCC7DC8A0BDE8ULL, 0x4BC5B0602C3CFE42ULL, 0xA845568B82136E04ULL, 
            0x732DB193CAAB8772ULL, 0xD8A4B2226CB93E85ULL, 0xD44AD8BF17C4575AULL, 0x0956C6E4C824E0D1ULL, 
            0xAB83ECFA2F858E6FULL, 0x3B3FAD31F653FD5AULL, 0xA37DF91BC7927BAFULL, 0xB9E70B217D8A69D3ULL, 
            0x5A3C984437A8AF49ULL, 0x6A6228E7924DD287ULL, 0x2E0411E7D566FF78ULL, 0x1285430BE2ECB5CBULL, 
            0x5111B51BAD915F7EULL, 0xCF106AB27FCBF480ULL, 0x0A777B7F0AD7323FULL, 0xDAF6D89900FE3A90ULL, 
            0xC04A30A49F81C3DBULL, 0xC6A17B38A6A04402ULL, 0xF17A16CFF68865FCULL, 0x07709C3321B3F444ULL, 
            0xAEDE6A9BC4E5E471ULL, 0x01B8818728DBF586ULL, 0x9304A00D12A38D27ULL, 0x0F39A4A4AD56F846ULL, 
            0x3C36126AFAE156F8ULL, 0xB04973E799B514C6ULL, 0xF16AA12EDE521E24ULL, 0xC4F3B7727E9E4D31ULL
        },
        {
            0xBA33EDF5A4B66435ULL, 0xA55703FAF00A5620ULL, 0x6F0BDA1D124F004CULL, 0x0C4C74BB8A5243AFULL, 
            0x7D47CA25D8B4B4BFULL, 0x02AB312D85F7920DULL, 0xC08CADE0D0F2E493ULL, 0x12A8618CD47A63BDULL, 
            0xB5EA885CF19832B6ULL, 0x4E1EBC48D2E3AF2CULL, 0xFB2C1E43B82DB846ULL, 0x0CEE07AB07DCA97AULL, 
            0xC9657D3D29A1EA6EULL, 0x516D0D2F4776B243ULL, 0x57F5E08FF2C245F5ULL, 0x6B59E79E3E84E8DBULL, 
            0xBB4B9C1E20E65B11ULL, 0x2D6AE72580768C0EULL, 0x2F7445E78CD3DCDAULL, 0xCBAE259E368CE498ULL, 
            0xBFD472FE619AA547ULL, 0x7678E1E0F87FE4C2ULL, 0xD3DCADFE668E7EABULL, 0x116286110A116095ULL, 
            0x09996C7EB381DD8EULL, 0xE2972758E65AE326ULL, 0x4BF73E05AA9ACEB2ULL, 0xE4D3F8D5757FA926ULL, 
            0x4EAD119BEB8D7608ULL, 0xE6FAC4BC56DECA9AULL, 0x890473D4E90F2815ULL, 0x5E504CE5AC9FBDEFULL
        },
        {
            0xE7243EA371A3B3C4ULL, 0xC461DEB73F5536EBULL, 0x5C26ADCBFA1F93DDULL, 0x51048F84B07FE927ULL, 
            0x73706CC18F6849DFULL, 0x006BBED997C39FA1ULL, 0x233F13B5604FA960ULL, 0x2AD4485FF0E04B20ULL, 
            0xDE54156B8C6063BBULL, 0x8F8523D2EAA6B41FULL, 0x5E86D453D2255FFCULL, 0x2091ECF6BEE7EF09ULL, 
            0x32FABB8FCBF722C8ULL, 0xD2678995E8EF8BBAULL, 0x8768B1F066C1B04AULL, 0x5E7C51309F96AD88ULL, 
            0xBD0C92DE803B57C1ULL, 0x820C1F3E76C4A93CULL, 0x3259CDB7CFDC3EAEULL, 0x391BD80DD3204B6AULL, 
            0x9ADB019BB93FFF97ULL, 0x5A189A812974C753ULL, 0x577846E229471F8FULL, 0x46BB630665021756ULL, 
            0xDCF30B24BC99F356ULL, 0x68DEEC086BA82416ULL, 0x3F2A6EDBE3E8A1B8ULL, 0xD2E176B3306AF03BULL, 
            0x181452A6CC0BDE59ULL, 0x405E9F04F62C4D42ULL, 0x9B8ED9EE6F5FE9F1ULL, 0x6141867AF93B88AFULL
        }
    },
    {
        {
            0x678B68416F6B68C3ULL, 0x20A11907946A9FA4ULL, 0x4E3865B729958300ULL, 0xAE7FC6D10427AB89ULL, 
            0x8442E59F131485A1ULL, 0xE2D3BEF302E0823EULL, 0x49A675E54A149EE0ULL, 0x1A757B069F32D87EULL, 
            0xDAADF5293A4DABFAULL, 0x145985B7E7DC2131ULL, 0x712149E7C1C98746ULL, 0x0B2B7036C9E535ECULL, 
            0x9AD86216D62C1F40ULL, 0x6A44E204649E7E00ULL, 0x583FE3EBADC9FAB2ULL, 0x6E2C50BF64C12F85ULL, 
            0x46B103960E47FB69ULL, 0x07C35E1C45CB8C20ULL, 0x681E043B1DCF7BA9ULL, 0x0DD6F5604B0B2518ULL, 
            0xEBC276A15FE8B216ULL, 0x9D305B9B197A8752ULL, 0x277566CD6A8B2C13ULL, 0x29C2433C266F7E6BULL, 
            0x522785264346076BULL, 0xB21D21893EAA3F26ULL, 0xFE17EEE37FA2C938ULL, 0xAF5598E7C376F587ULL, 
            0xF7CE481F35306FF0ULL, 0x014BC4A3A6D7A85FULL, 0xF8D0B0D81ED33084ULL, 0xE7B92028527A33BBULL
        },
        {
            0x14DC8CCEAB3F890AULL, 0x6A45997C1E502F13ULL, 0xFA097B2A83DA71F5ULL, 0x4356E69DEEA67DC9ULL, 
            0xC2C7AC4155274FF6ULL, 0xC61278D369739896ULL, 0xFFBC1A4F664AACCCULL, 0xD55E35F773F10264ULL, 
            0xDFC52ECC612AD69BULL, 0x4E845274406201B6ULL, 0x82CD3C8AEFA6BB1FULL, 0x88104B7CA8C2494EULL, 
            0x4E15FD9F9719A118ULL, 0xFA7B96B47E9D024DULL, 0x710F4A7C1B9004D8ULL, 0x0604CB52BB82B8EDULL, 
            0xB7624BD5500F377EULL, 0x5599C638E351F04FULL, 0x5D2516396E2B6F0EULL, 0xF7232A0F436DC4FEULL, 
            0x9983EB2F65BD768CULL, 0x0B37314B911783AEULL, 0x9025A6FBC2E23980ULL, 0xFA3306C154E356A2ULL, 
            0x7FC09C6EE4DE8319ULL, 0xDB7DD5FAC22C4C16ULL, 0x88808CD550D8ADB4ULL, 0xBA260FA896E8C1CCULL, 
            0x1342A851A113F452ULL, 0xB401C3DAB0A51396ULL, 0xF982BAB0072F9723ULL, 0x321EB1447B052D20ULL
        },
        {
            0x8B4D2025594EA463ULL, 0xFA978D371AEB4736ULL, 0x0198073B0A6C9494ULL, 0xD6F2D1F81090EF6FULL, 
            0xF0FEABB43360CA1EULL, 0x2204872BF5100C58ULL, 0xA8540C0BF5A14507ULL, 0xB25BDEA575B835FDULL, 
            0x8A918657F07FE9A5ULL, 0x52140842E6870304ULL, 0x9B5388170E143920ULL, 0x0D234B618B462115ULL, 
            0x0CA4B080973C6964ULL, 0x454E30A98AF3C93FULL, 0x5D53A1B11C31C265ULL, 0x9806853980B4A448ULL, 
            0x5B29FB2AD5BB700FULL, 0xEFB617D8B4B44ACAULL, 0x9438CF7A4F8AB20DULL, 0x8747D26CE79B63E0ULL, 
            0x5E32889BDC063608ULL, 0x678B71DFE802C5FFULL, 0x3D3C216649D3C2ADULL, 0x0279A2446569C9A4ULL, 
            0x5D0FC8FDB655BFF9ULL, 0x4B1083F69829DEBEULL, 0x6340305B120EB8A5ULL, 0xB940EDD6D8D20F1AULL, 
            0x494E17E9C35EA2D4ULL, 0xB5076AD38EAEF5E3ULL, 0x5939971371100DA5ULL, 0x61245560970FB001ULL
        },
        {
            0xCAF075DAC461DF3CULL, 0x293CA1AF05E1EEC2ULL, 0x8C650423475E1C53ULL, 0xFA7CEC7C1FF03B60ULL, 
            0x19DAC1300518E897ULL, 0x907B530A650C8100ULL, 0x4A9BA66EF638090CULL, 0x2C4692BF6579E817ULL, 
            0x171F40A396E3D9BEULL, 0xD1C64F10FBFAB6D1ULL, 0x6AF1EC680C83CA9AULL, 0x8D91868F99A54645ULL, 
            0x7F1856E8642F7160ULL, 0xF4C6EAA020B3B82CULL, 0x6840B7100846C16AULL, 0xE1640DB55D76E264ULL, 
            0x1335154076B0B8C9ULL, 0xB599AA0D73F8F14FULL, 0x1360F49C7394A850ULL, 0xB781385D60A92326ULL, 
            0xD45A949486E01DD5ULL, 0x96AC9D182A79EF3DULL, 0xDF76D0F513EE6481ULL, 0x42D21A3D0D373506ULL, 
            0xCD9A42CC6E6D1340ULL, 0x98C4B4173757E71EULL, 0x5558E6782B2F5805ULL, 0x5D3E7A7FF8D999C4ULL, 
            0x40DF96BBD01566FAULL, 0x90D4493F06D2349EULL, 0xC1E5628C1620D8EFULL, 0x66503F530826226DULL
        },
        {
            0xD6638353480B7C67ULL, 0x03D9B830C1EC77F9ULL, 0x3A189713203E1382ULL, 0xF9D3AAEA4E3AC502ULL, 
            0x1D8A4E9D1CD83E0BULL, 0x6BD98E568A5A5DFBULL, 0xF6FA3636FC191A7DULL, 0x08CBF22CFF3FA3A4ULL, 
            0xF584BC66E5A3578AULL, 0x0450AA2CD5698E81ULL, 0x80257190E0D5E782ULL, 0x709D5EA4412336E8ULL, 
            0xFA2BAF64EAF788DEULL, 0xBC3D0F3131C7CB23ULL, 0xD8A3ED4924D51AD4ULL, 0x5532F2CC55BF6B84ULL, 
            0x704F6EC42075CF51ULL, 0x45FFB90BACAAEB39ULL, 0xFF3CCA380145C215ULL, 0x28D60F9F238C332BULL, 
            0x3E2E8AA76C8F61E4ULL, 0x898558E66918E2B5ULL, 0xC75DCCA5B3238105ULL, 0x9CF3077D446AD81EULL, 
            0xF1F62764BADC5383ULL, 0x8860E652ED852FDDULL, 0x9FCB9255C7C3DB4AULL, 0x330C4BF4B53A6C01ULL, 
            0x7318105260BE2E68ULL, 0xCC0018EF1FAA1A76ULL, 0x0A75BC5136026437ULL, 0x32E7F2A6E5FBFA5BULL
        },
        {
            0x745ACDC743356FBEULL, 0xDFA85055FA9746EBULL, 0xAB462B746956FFC3ULL, 0xCF1119322EA1FAE4ULL, 
            0xDE7D9D431C1CEC4BULL, 0xB139CF245886610BULL, 0x9A480E2F47B2E843ULL, 0xFA2B95CDD4B07FABULL, 
            0x2A335841217D4046ULL, 0x80F2DAEA1A66ED5BULL, 0x9001F7BC8E853B8AULL, 0xBD627389A07B5F04ULL, 
            0xE437805ABD6BFCE8ULL, 0x3DD4FD127E0A0C65ULL, 0xB5CA8504AC0001BDULL, 0xF6D78209A9D1B151ULL, 
            0x326795A9953BCEA0ULL, 0x9F9E6CE57E4FD65DULL, 0x3E73801755B82C65ULL, 0xFD3EAE882270047DULL, 
            0x2C6FE859E6087EAEULL, 0xC627713236F5D922ULL, 0x9A0D7577EF065E81ULL, 0x8404F6CCFB60487BULL, 
            0xC7FB988BDF5F5C25ULL, 0xCDD7D6703685D874ULL, 0x4C42E114617862C0ULL, 0xD4EC8D9535EDDB0EULL, 
            0x3ABD51120C590949ULL, 0x260AAC3FD424F740ULL, 0x75BA27032926D2B9ULL, 0x99FA1258120CDC17ULL
        }
    },
    {
        {
            0xA6DABCF03569C1FCULL, 0x7408CEFD3BDB5F78ULL, 0x90F6FC21EAB3CC6BULL, 0xFB6F05C24FBB7096ULL, 
            0xA8F4C02A6D779DEAULL, 0xDB971699887E082EULL, 0x8DCC4667D04ABC3FULL, 0xECB9239E6D9059FBULL, 
            0xCCDE496791DE7F75ULL, 0x5A5A067A2369BEEFULL, 0xECD0194918058805ULL, 0xC03A684D397EE163ULL, 
            0xB573214CA08F2E61ULL, 0xBD86CF6DACAC9560ULL, 0x067379A497C4C379ULL, 0x8ECFC995AEE20CEAULL, 
            0x35528F84ADEB5F21ULL, 0xCFF8E81ED0D8DAF0ULL, 0x3A3F5145ABBF22B7ULL, 0xE632F0E353F26C89ULL, 
            0x95AA6931F596ED48ULL, 0x29BF8429DAF31F17ULL, 0x867B7B8286FD468CULL, 0x381DE7F16A646CF8ULL, 
            0x7254C30F53668727ULL, 0x59EADB8C5287E296ULL, 0xEA2B2F005D92283EULL, 0x781D18301C558E81ULL, 
            0x0908C8B06BFB305AULL, 0xF6A8CC32AE1CF380ULL, 0xEA6D2A120B216951ULL, 0x47BCB803E1C1BC82ULL
        },
        {
            0x481F0E175E29E1F4ULL, 0x3DF2161C158A59D6ULL, 0xBA9142A9EF0ACAC1ULL, 0x6081EE8FFBEC8A05ULL, 
            0xFBB821541CE16B21ULL, 0x13DF5B639FF00A1DULL, 0x52D34D906C2C0840ULL, 0x6472DCC2B5BA72EEULL, 
            0x336BEA4659891B0CULL, 0x2A0791F2DDA4118BULL, 0x5173B92BF226F444ULL, 0xD359726872FBC8E8ULL, 
            0x9EDF3AD493301827ULL, 0x25D7B80BB986E77FULL, 0x12DD4552857D0B76ULL, 0x15623FE26470B8BDULL, 
            0x8D8C8E8351833EF5ULL, 0x5666DEA54957CBA5ULL, 0xEE8DA0F32C2D1F68ULL, 0x7FFC13D30DC670C7ULL, 
            0x55F57FF7E14A7854ULL, 0x5BAE246A124AC404ULL, 0x9653AABBBE3A744BULL, 0x11F0CF159CFE5A3AULL, 
            0x19112A0C779739F4ULL, 0x800D5D4C5D3AF5F9ULL, 0xA87417F551892CE7ULL, 0xE5A3A533E9B88E68ULL, 
            0xBCEA4D58BB673CFBULL, 0xDFEE358BDE757113ULL, 0x3918C961316801AFULL, 0x0F4BA2E12C361493ULL
        },
        {
            0xF386F8A8E6F44AC3ULL, 0xF5BD7F23FB92C5FAULL, 0x885E2340E63562E2ULL, 0xBB34C25F28A29A59ULL, 
            0xBE6374BBED0A4633ULL, 0xC4CBAF6D47482BBBULL, 0x239CCA216886D126ULL, 0x6BA4B6A5847578DFULL, 
            0x986A973D68C28CE5ULL, 0x5EFD0B1D1BAD4EB1ULL, 0xD03C73C3AE19D679ULL, 0x7282195398CFA9F7ULL, 
            0xFE07158A303E4B91ULL, 0xC8739F05D5E5ECF0ULL, 0x2F421076D5E260C8ULL, 0x58361C4BAF98898DULL, 
            0x01CC4EAF3F06C731ULL, 0x6ECF3E9596DBE12FULL, 0xEAFFBA331247C4C5ULL, 0xACF57E2B9BBC0281ULL, 
            0xDFBC210D02E8DFE1ULL, 0xA7713ED0B34829C2ULL, 0x31F0BF43E4952E59ULL, 0x5892514C15D48412ULL, 
            0x85D1B6292CCFB793ULL, 0x4228DEFE99BBFB74ULL, 0x22E484BAC6F9CCCDULL, 0xFCF46B8A8405CC38ULL, 
            0xE895B672A620E23AULL, 0x8E6F3D537BE69EC8ULL, 0xA82C6D6D83A2F8CCULL, 0xF910AF37EB1C4AE4ULL
        },
        {
            0xC395A698A3F129E2ULL, 0xD62F151952B944A2ULL, 0xC8362AA6EC8506C4ULL, 0x07DA86BE7464A305ULL, 
            0x8DE5922239319BBAULL, 0xB62F029DCAD15F8EULL, 0x6E577DAA23F1129FULL, 0x8976A19E13CE6914ULL, 
            0xAE246BEC03E8A0D5ULL, 0xF0C96E0E2AC5C577ULL, 0x552B229033D4BC67ULL, 0x56223D8EFDAA5B13ULL, 
            0x57A22FDCD030E096ULL, 0xE51F1491C26AB9C6ULL, 0x2319478FAD80848AULL, 0x03088082B455C4A1ULL, 
            0xAA158A7B784B6488ULL, 0xF16EFA30D98781ECULL, 0x0DCAED721CEFBC36ULL, 0xEEE2C344D575F013ULL, 
            0x6FCE517E855E2570ULL, 0xCCB1E91595468C30ULL, 0xC9737CCE3E053869ULL, 0x1BD045456E55D555ULL, 
            0x4CC030DD2C13A19BULL, 0x6E541F9984B07DF9ULL, 0x3215B0B7198EBE93ULL, 0x8FC02840105E89F0ULL, 
            0x7253654A47649D39ULL, 0xB7E51B2B7629040AULL, 0x310BB1C1AE637857ULL, 0x3D6EDE246CF760C7ULL
        },
        {
            0x21957D1D3842C9D3ULL, 0x8894F9B3A270C9C6ULL, 0xB84295D35392DDEDULL, 0xADFDB534DF915826ULL, 
            0x1A3453A20A6A8CB3ULL, 0x0F2A4FDB68598242ULL, 0xE078F426C218D141ULL, 0xF0C594BFF5FD8DF4ULL, 
            0x25AE42F232EDEB0EULL, 0x361F3E13CD5E61E0ULL, 0x0E4A212A3B9129C1ULL, 0x07D246B8E0F29B98ULL, 
            0x54F906BA480F889DULL, 0x8D90D67D299431F9ULL, 0x03966636A7919A7DULL, 0xBDD1CC3CD2128F11ULL, 
            0x3A9DEF857CFF4791ULL, 0x5BF04608A50DAA6DULL, 0x16EBA97F719F033CULL, 0xE2B4F25ADABF499EULL, 
            0x57F46573C82DC8D3ULL, 0x892A3D5F831FDDF2ULL, 0x1F6E281727B80286ULL, 0x00D18FD4CA043218ULL, 
            0xF55EA96AD7195F84ULL, 0xF80BD05D6D5A6876ULL, 0x4554FD4791BF0F21ULL, 0x7C70952DCB3D0EC3ULL, 
            0xAECCADD25715FC2EULL, 0xB957070244B3B085ULL, 0x1663EA8E2DC2DA0CULL, 0x9CA40DA87DA7E674ULL
        },
        {
            0x2B0214FB817D859AULL, 0xD3B3964CE3694840ULL, 0xCAC3C484BF579729ULL, 0x08F05AA1E31232D4ULL, 
            0x003471925E5D32C3ULL, 0x3B2808CD3B4CC53BULL, 0x316FCC1EAEF106F2ULL, 0x350E13D25B42752FULL, 
            0x67159474C428B681ULL, 0x1997B82E3AB7EBABULL, 0x6E33C84402FF04FDULL, 0x5DE64B9003325220ULL, 
            0x12235ED1E0165174ULL, 0xFCEF420BE06AF754ULL, 0x2F401AFD6D61B771ULL, 0x131BFBEF720E146EULL, 
            0xE51ED6063DFFD808ULL, 0x92038E70AE67BEF9ULL, 0x433BA4CD97C0E3C6ULL, 0x3C1511CA3A18D685ULL, 
            0x3072936FE28CB004ULL, 0x4B7BA35F057EF1BAULL, 0x5C2683B85C0D9C55ULL, 0xE145A3C01C5C1562ULL, 
            0xFB3058D5AE45A9F9ULL, 0x4C39BFE946C729A1ULL, 0x090FB1BDB3BFCE9DULL, 0xCDBEA9AC294B5B29ULL, 
            0xFAD1A298736DD5A4ULL, 0xAE631B0CEF4DF905ULL, 0x619CED14FF183E93ULL, 0x27341C265BA32705ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseGConstants = {
    0x0B1B81A35EF0EA74ULL,
    0x64FCA7B03B393B32ULL,
    0x1184C5EFF3BD814DULL,
    0x0B1B81A35EF0EA74ULL,
    0x64FCA7B03B393B32ULL,
    0x1184C5EFF3BD814DULL,
    0x54B2B510344B7A9DULL,
    0x94E65D1CBDCCBD54ULL,
    0xCE,
    0xD4,
    0x69,
    0xA3,
    0xB2,
    0xDF,
    0x78,
    0xBD
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseHSalts = {
    {
        {
            0x8BB536FB2B274AB3ULL, 0xA2F03245D29F3F54ULL, 0x5C9F335D629A1171ULL, 0xD80CF047278AABC1ULL, 
            0xCF341BC30842AFA6ULL, 0xA04B902FD3A5EFF6ULL, 0x4FCC19FD66C07A68ULL, 0x61CFD1286997E20FULL, 
            0x9561AB102CF5D460ULL, 0x6BA5FA1C31EB4731ULL, 0xEA73109C24C3EDE4ULL, 0x379BC45B11DBF53AULL, 
            0x8DAACABC8D14BAF8ULL, 0xFC79B394C01687F6ULL, 0x08EB238671AF64FDULL, 0x2F2C71ECCFE50B08ULL, 
            0x202DB47789235D23ULL, 0x785EDAD5677A9A1CULL, 0x72B5BCEC10E39714ULL, 0xE59C966975F6B357ULL, 
            0x10B8D6DCFDAF8A6FULL, 0x758684403D14C056ULL, 0x11F369B49D031D82ULL, 0xD92522651806C82AULL, 
            0x02B0523DCB159A70ULL, 0x88CF12DBCF839B06ULL, 0xEC9A41DF49928A18ULL, 0x694A20A589D07A83ULL, 
            0x82D6C3E93E2EA960ULL, 0x916CC6809996FE2FULL, 0x6709BE22E1ECD3F9ULL, 0x65B65906022FA166ULL
        },
        {
            0x883BED2F95C6D264ULL, 0x95CC5FF3583D90BFULL, 0x8E31152C20BBD6D7ULL, 0x92059B9322A9AE87ULL, 
            0x9334165E0F643718ULL, 0xEA536E70AE2430D4ULL, 0x57DEDE2FA2B6866AULL, 0x7357C4AE0E2A3FBDULL, 
            0xF92D1533FD8A0B1AULL, 0x9A888DAB87758DE0ULL, 0x4C97CE6625501684ULL, 0x9C95A27098D7B7E6ULL, 
            0x68664A00B901937EULL, 0x788DF6A6D23AED9BULL, 0xCBB7856C80E615E7ULL, 0x140DBCD990206E7DULL, 
            0x164A5EB27A3ECA38ULL, 0x0E23855847D82EFBULL, 0x589A6A77A6811C2EULL, 0xE43B0E9FC7B6195AULL, 
            0xFE0CB0C0AA579D0DULL, 0xCFAE3C88F34F4E25ULL, 0x4565C589D98EF70BULL, 0xB1CDEEF7F2F3F020ULL, 
            0x06E425A2FC75E584ULL, 0xD622150AF8A7D2C4ULL, 0x1F87657580E49D20ULL, 0xF9C3F7B776711EB2ULL, 
            0x52FA76ED64C61515ULL, 0x4D414D4D78C7DE1BULL, 0x63CD38F91362BFB9ULL, 0xDC71DE5BA989A365ULL
        },
        {
            0x01706B124640D7E6ULL, 0x5A115E6CC0A366B5ULL, 0x1F2FEB21B5430982ULL, 0xF7E11C4B52286D97ULL, 
            0xE61C2281261ED696ULL, 0x5F493BED9EDF90F0ULL, 0xA1FC179A529700EAULL, 0xF7C5DE0A41FF4E8BULL, 
            0xF488154AB70ECB92ULL, 0x3F852E6A24B4D4F4ULL, 0x7CFC5B5BEB8A7AE5ULL, 0xBC28002AB55A9DD0ULL, 
            0x25F6B2BDC14B91E4ULL, 0x8547F311727968D5ULL, 0xA1F81461D3DC4F19ULL, 0x789C245DF2B400D1ULL, 
            0xE459B6D035FB490FULL, 0x274281013C32BCFDULL, 0xCADD7E509E443CF6ULL, 0x704D9655BA8AEC2BULL, 
            0x3F085DC42DCD4DA7ULL, 0xB7A087A6320AD2D1ULL, 0x6215EBB2857E2E77ULL, 0x480E9056DCC6BA7BULL, 
            0x753226DD47B9DBEDULL, 0x8BB4FEC985CE012BULL, 0x34E301B8F4B18D2AULL, 0xBF963EFE9F5D959AULL, 
            0xD1F43595F53D4B05ULL, 0x0E996D610E22C793ULL, 0xD225DB7838B237AFULL, 0x4912A04DA70964E3ULL
        },
        {
            0x18D3B94BACBFB38BULL, 0xFC5FF02BBBDB6FAFULL, 0xDDD9C1C59D6D4955ULL, 0xF42A1F4ECC4E53B9ULL, 
            0x3F7F23A78507F0D4ULL, 0xE2529E056C17121AULL, 0x5BF0BA82E547F4E1ULL, 0x10EBEEBB32CD4308ULL, 
            0xDC8875734F172E7EULL, 0xF3D7915001FE0AF7ULL, 0xA489424324F2942BULL, 0xB6A5375FC1CB857FULL, 
            0x0118EA6FB31E4A3FULL, 0x434AAA1C083B2FBDULL, 0xAAA3C863228B6B91ULL, 0xC372446F689A9D54ULL, 
            0x8638024F6982CB5FULL, 0xD3B550CB3075FFE0ULL, 0x33C0A74B5E8C3B84ULL, 0x3164F84E211AFB81ULL, 
            0xBFE66423D28DFC64ULL, 0x5925F330947924EAULL, 0x4A96A2C630B6A364ULL, 0x63F8D1AF7FF341B7ULL, 
            0xF3411FB7B48DF588ULL, 0x52DCABA527E11F66ULL, 0xD07813C727362D20ULL, 0x3A3348767194D019ULL, 
            0x5A0F3DCEEF98AA95ULL, 0x01D8B97F0F60FBEBULL, 0x330906C832EF5347ULL, 0xC5A576108D954EA0ULL
        },
        {
            0x1F553C97F7FED90AULL, 0x5BC166AE801B8BFDULL, 0xB4A5D88FBFA8B4D0ULL, 0xC4D16E6DC154BF5AULL, 
            0x105F1D93365DA955ULL, 0x9979BF9CD8F202CAULL, 0x2ACFE6E2042AA761ULL, 0x37BB2B249B8193E3ULL, 
            0x3DA328F6C198D6B5ULL, 0xC1D86C0DB3A615E1ULL, 0x70F31826F8865A2AULL, 0xB2058D0461E0148EULL, 
            0xBDEC22E3EA5BB05CULL, 0x2CFAFF5CAF2A355CULL, 0x244322007A5E331AULL, 0x0C5413DCD5A266C9ULL, 
            0x9EEEA8179FA27DBDULL, 0x0AEAB7CFCA030479ULL, 0xEC79AE273A39F3E1ULL, 0x451C167BF05DABE1ULL, 
            0x8A6AD549F880154FULL, 0x50B656FBC8CBD7FCULL, 0x370CA626BB1DF7BAULL, 0x6074CFA51EC0FC9EULL, 
            0x5B6A87D7EC6CDFAAULL, 0x0605ED7132DE477DULL, 0x7323316B4A89939BULL, 0x1C9EB952F3DC6713ULL, 
            0x744978229B94F21DULL, 0x0C1492C40869C4C2ULL, 0x9615F7A85B65645CULL, 0x8AAC7DCB3E249F4CULL
        },
        {
            0x3FCC2DA8C46CFE83ULL, 0xB6831FF6AB79A109ULL, 0x399AB12FAE786BCAULL, 0x69146E471BDF736BULL, 
            0x081EE4122FD205E6ULL, 0x2537DFA4729043F0ULL, 0x94B25C8D6A3DC0A1ULL, 0x3634354D8F5327E1ULL, 
            0xA963B55C1AD06238ULL, 0xB6C66B6424F23C6BULL, 0x44013938407C611AULL, 0xA699B2A37B5F8B82ULL, 
            0x2144C56EF5F9D840ULL, 0xE169F728E16FB7CEULL, 0xBD3B48B4ED2D1EDDULL, 0xB7A55FF865C70AA9ULL, 
            0x53711CA8A2806C98ULL, 0x56B7890421E0908BULL, 0x128AF7669FE03324ULL, 0xBCCAF9260A1D5237ULL, 
            0xF52F258373FA45C2ULL, 0x954F1F57A55479E6ULL, 0x578FF707BCDA02A6ULL, 0x931E6A1EE945B249ULL, 
            0x3157DCE2ADC7A3FEULL, 0x1751C194A770811FULL, 0x9936292788A0DEA1ULL, 0x29F3F0DE368608F7ULL, 
            0x7530EC9C04ECDBB9ULL, 0x77FB3FB4E9F98EAAULL, 0xB3421E9A669C6FC2ULL, 0x67039F8136F318D8ULL
        }
    },
    {
        {
            0xA81B8E42BC35F32DULL, 0xBFCC97577918C54EULL, 0xB6F71EE7E2C0E3EDULL, 0xCDE9D2C42C1B9113ULL, 
            0xA0741E5020FA10FFULL, 0xDC1049617242B5FAULL, 0x92F58256A999E89FULL, 0xCCD237D7B2428C1AULL, 
            0x0B2CE0AA2405DDC6ULL, 0x52F5072EE2ED692BULL, 0x2D496F247027DD6FULL, 0xFAD3A3031DB354A9ULL, 
            0x2B0985BEC098DDA8ULL, 0x330358A9F3186EDCULL, 0x240F9934D32C6DF4ULL, 0xCA6F8882F040EC97ULL, 
            0xF6678A759DDF5AC1ULL, 0xCD8E816E451305B9ULL, 0x93FF2F5877AD297BULL, 0xB3F12A32DE5E492BULL, 
            0xDB1F773C7BD50C0BULL, 0x21E62DF9E1A1F37FULL, 0xB36AA769B5DB7215ULL, 0xF30C92A8467727F6ULL, 
            0x18A7C3BEB45F09ACULL, 0xF53C55091989C162ULL, 0x31DA7827D0DC614DULL, 0x0726EA3E1C749890ULL, 
            0xB670F8C51BF9E7B0ULL, 0xF21A0147D951DBDEULL, 0x336CA3F0A689BEBDULL, 0x8B05E19296913DC5ULL
        },
        {
            0xA992AE0F0AA57EADULL, 0x7EEF0D84B11364A1ULL, 0x537027B029F8876EULL, 0xC4031FDD02F09DB6ULL, 
            0x7FDF98C5B9685C34ULL, 0x7FA42A72000BB931ULL, 0x5EAB715293A7013FULL, 0x5545C386B90725E2ULL, 
            0x4980062E4E25441FULL, 0xB86E9C5EFDB766DDULL, 0xF642BA9169BA9B41ULL, 0xABE7094C0FD02FE5ULL, 
            0x6A7217B722C75C0BULL, 0xAC352264BBB6343BULL, 0x64A57CF3B5EB644EULL, 0xA9CA9C6B7F812F2FULL, 
            0x315BB6B5B62F4872ULL, 0xF8B926CB853EFC8BULL, 0x8D318B0DB4E98B47ULL, 0xF27D8AAE009C325DULL, 
            0x17944092E823FB1AULL, 0xF172E0CB3409CF18ULL, 0x34C21459FF08B180ULL, 0x7EB654FE6CAEEAA7ULL, 
            0xD9DBEFBC318BC72CULL, 0xB405EAFBB1504E8BULL, 0xBD2E9C78113507B4ULL, 0xCA99C961BA3E8718ULL, 
            0xC111FB13F06357BAULL, 0xD5CCB965CCF71F82ULL, 0xF6048D15C396FBD3ULL, 0x2B266B1ABBCBA867ULL
        },
        {
            0xD726B6E4EF7A81E4ULL, 0x8439F1ED5B62CDF7ULL, 0x340DFF6212050398ULL, 0x3A8C46B14FC78D2AULL, 
            0xAC75393450BFF52DULL, 0x1D4ABCFF478A81F5ULL, 0x95209C57104B1E8FULL, 0x233ACEB2739441AFULL, 
            0x9C2E0ECA692420D6ULL, 0x6D38AD47CE92A722ULL, 0x43349F5D0DF26BFBULL, 0xE6527E1F8F8B09B1ULL, 
            0x38FCA7B21C53ACFAULL, 0x1801CE2D83E97F28ULL, 0x4D465CB0338BCB83ULL, 0xCF354327A7F7A293ULL, 
            0xA9531D4305F7D1A9ULL, 0x0EA9D6EE8DF7D28FULL, 0x2CCF9BF54B104804ULL, 0x1BB1E05BA17231A9ULL, 
            0x12DD4F3CA5BD996EULL, 0xBC4357110428429FULL, 0x66F78D32F42CDA08ULL, 0xE979A185C224B213ULL, 
            0xE99CE0B932E34E00ULL, 0x534A5C2E3D2F9A8CULL, 0x06132925A1692C05ULL, 0xDC742AB1CDDB84A0ULL, 
            0xC7D63ADBE16EC668ULL, 0x511686A42D002D95ULL, 0x83637E48EF38087FULL, 0x939D774725C8F7F5ULL
        },
        {
            0x8EC6E6E5A17E9FEFULL, 0x3CAA909C706E0CF3ULL, 0x091C27BE91519B15ULL, 0xD4140922B2A53074ULL, 
            0xBEFB7A54945180D9ULL, 0xEEB610E647A1A559ULL, 0x8A48089A1C00E72FULL, 0xF1339AA653CC6B3CULL, 
            0x8C732069D9E44B13ULL, 0x2BA1380C6A0AF075ULL, 0x222F45BAC8A5AC0CULL, 0x1E7413A185F4717CULL, 
            0x6F1395B52CE02D1BULL, 0x0902B36AE332508AULL, 0x9931F56C679E27E3ULL, 0xEFD6CC01D2D1655AULL, 
            0xE7105EC28E4F527EULL, 0xFD453FF055658BF2ULL, 0x76FCB52AA13CF0DBULL, 0xB4052B11BF732B38ULL, 
            0xCE7067D92896031FULL, 0xCD6FB47A0F21257CULL, 0x40FF4B3E12E2B568ULL, 0xECE2359F81BF1755ULL, 
            0x74EF755CC1E35D89ULL, 0xFEA440794C8CDFE1ULL, 0xEC822BD98619B8DAULL, 0x6B75B4B6222F1C83ULL, 
            0x993B29808A01A5AFULL, 0x103516D62D40F053ULL, 0x0ABBC39C7DA8681AULL, 0x54F05C6CFE2F6BC3ULL
        },
        {
            0x0355CCB74E06916FULL, 0x7C29E9A943FBCDDCULL, 0x3E1A5E85502BF925ULL, 0x385863459BAF0929ULL, 
            0x3D666B06E7EAA593ULL, 0xCC898377AB9C18EEULL, 0x9799E2B3227D15F1ULL, 0x7D539ECB0586D42FULL, 
            0x719709C2D1583AE7ULL, 0x130A8F26796618ECULL, 0xB7149686A6EA653BULL, 0x18461665EFF3E968ULL, 
            0x4A9DD282DB7EF832ULL, 0xB5E49F85E32DD37DULL, 0xBB0A8CBF012847CDULL, 0xEDCC5058AFE3CAD6ULL, 
            0xFB64E9B963149333ULL, 0x399F3E288EA813A0ULL, 0xD582D0D8EDFE4498ULL, 0xDF89D85DE1EC20FDULL, 
            0xE532F0052E905AA8ULL, 0x6F4460C844722059ULL, 0x2E6057A9FFB5A2BDULL, 0x1023C023376B39CCULL, 
            0xE5670D9B6705E1BBULL, 0x79573A39A31FE6B9ULL, 0xC12AC8C4A61A8934ULL, 0x20B0166ACC3346BDULL, 
            0xB94DAC3E6789BE4BULL, 0x2803A4EC05DC4ECBULL, 0xAB513422F173B07FULL, 0x1612BA0522B9F91AULL
        },
        {
            0x55F1B67B718E41DBULL, 0x122AD121BD62A5FCULL, 0x8CA9E7475A71C880ULL, 0x9A75F1A962B6D619ULL, 
            0x21CD78ACBE75C693ULL, 0xD340383649356E2CULL, 0xF063CAB4CE603039ULL, 0x9EC6D24957795AE5ULL, 
            0xBD7AEF5B353ACC3DULL, 0x0F124CF391BF116EULL, 0xDC431F330BC190E7ULL, 0xA125379A1AFB7E43ULL, 
            0x010144E3DF3501D0ULL, 0x0F91F39DE8EDA3E5ULL, 0x0B9AC19FE47B3836ULL, 0xFBF25D12C0D9CD83ULL, 
            0x44B15EFA0A7DEA71ULL, 0xA568E8AF55ACB20BULL, 0x0F3E34185A351118ULL, 0x65B05A89EAB0771DULL, 
            0x1712B46862B0D39AULL, 0xAE3507A6BBE31C0DULL, 0x8B6612D5450471EFULL, 0xADDC07F04BE1D655ULL, 
            0xFF6FBAB6522A1732ULL, 0x0CBFBE5C9724C0E5ULL, 0x78C8F0F11E3D2BFFULL, 0x097198708B90F72AULL, 
            0x732E7C59A98E33BFULL, 0x85569A53C6431D88ULL, 0x68E89C7018D5B21AULL, 0x2D69D4585F80188BULL
        }
    },
    {
        {
            0xA52F1DD0C37B47C7ULL, 0x8AF9920C7DE10E85ULL, 0x148C4ED316331515ULL, 0x7B096B6642D1ED79ULL, 
            0x8700E0F7ACE4E4FAULL, 0x6812B43EB0F353FFULL, 0xC08959E4DE9DB432ULL, 0xD4E6ABDEC311237DULL, 
            0xEF6A5080A80E2992ULL, 0x8B91FADEF107B2B7ULL, 0x04F4EFE64319A385ULL, 0x9BCC71227EE69163ULL, 
            0x79938F18FB91282EULL, 0x39D48783157EC01FULL, 0x12E11786759B7957ULL, 0xD4EA44D9EC125F40ULL, 
            0xEE4BF1096B47F6D2ULL, 0x71539B8D3728F3DEULL, 0xAFB6E61582F817AAULL, 0x3E75320048DCCDB4ULL, 
            0xFC44EE445619F28DULL, 0x914E64461B9C507FULL, 0xCCBA6724522E946EULL, 0x9D1C13A60F7A1788ULL, 
            0x232BE3FAFCDDB21AULL, 0x3F6E99284D109F8AULL, 0x7B8C79B70E260492ULL, 0x1BC24E81A2164AE8ULL, 
            0xF7778496D95CD127ULL, 0x96462C25E5D7983CULL, 0x711E94A671006A08ULL, 0x7DD216813FE9DE1BULL
        },
        {
            0x7A475BA7B154A697ULL, 0x2750EC759A000FAFULL, 0x266E84BAFA427C46ULL, 0x34F320797C6F7B1DULL, 
            0xA447DB47A92D805EULL, 0x52C1D487BAC18DC8ULL, 0xE52CB3FE8FCB70E8ULL, 0xFDFE39514E0F7C65ULL, 
            0xA12039F51307D36AULL, 0xA87965DEEC89A9B9ULL, 0xA902033B74F0E703ULL, 0xC33EE94D2DCF3D6AULL, 
            0x8469449B4E627951ULL, 0x0A4B9B891F5A5683ULL, 0x6B19686BC7338C79ULL, 0x980297D453D392FFULL, 
            0xDA0BF63486874260ULL, 0xE02B79E22721C830ULL, 0xAF1E32EAC149A4F6ULL, 0xDFA20E0869ECB01EULL, 
            0xB4DDBE5B7DA77A38ULL, 0x7440FFC5259A32E2ULL, 0x05ECCD6E56318B59ULL, 0xA3ADE7B23CADE036ULL, 
            0xD0979E229BDDA966ULL, 0x554185DB79860726ULL, 0x8833BBCFB6363830ULL, 0x49A85B89F26BABCFULL, 
            0xDD9F9D3962C3F98BULL, 0xA4986576A86B93D7ULL, 0xC79795444A106E8BULL, 0xBB85AAAC9B851836ULL
        },
        {
            0x0D6CF7467D62E72DULL, 0xCAE4646C06B68008ULL, 0xF69C771E7B6E455CULL, 0x94D6CFBC680CA63FULL, 
            0xE576E48A0CD1BB00ULL, 0x5E9041A4F1BBACEDULL, 0x5DB8B6E78A4BF0CBULL, 0xC57A3552FA179043ULL, 
            0x326FD9F7D0BE1B67ULL, 0x01F0972475EA1AAFULL, 0xF663F0A0160C0C44ULL, 0x4A3F1A13072A77AEULL, 
            0x58012799B455679EULL, 0x2C4D6E68ACC665C7ULL, 0x527C07009601122BULL, 0x019AF0EB1BF3E1B7ULL, 
            0x735B15CA36073B29ULL, 0xBB501A5D722725FBULL, 0xCA2C0DE664C79F41ULL, 0x5D8B40AD2ED6B748ULL, 
            0x736F41DCD0CB9104ULL, 0xC873A626151BFC50ULL, 0x41525479C2C7DECFULL, 0xCD8465A2511166EFULL, 
            0x028436E9B7572A79ULL, 0xDF6C1B7F125C512DULL, 0x5EED2FCD07D885C2ULL, 0x3B27895FD86C7253ULL, 
            0xDBE8FD4DA417393CULL, 0x14469C28098B47C4ULL, 0x84745D0958D1AD19ULL, 0x3980DF10ED1A2C68ULL
        },
        {
            0xF121C81877FF5705ULL, 0x756E046CE737B466ULL, 0x5023F50F25FFC5B2ULL, 0xA51337992E9AF683ULL, 
            0xC4F6C7EC468DC717ULL, 0xCD84AAE35BA0B287ULL, 0xCC737DC0F064E4F3ULL, 0xEB764EAE92987BA6ULL, 
            0xE2CF8CBFB7D16559ULL, 0x5D7B9F7EDE8702E6ULL, 0xA962C92DDBB3669EULL, 0x098E1D778BBB72C1ULL, 
            0xE87BE431ED061D0EULL, 0xE93F488DA2060DA9ULL, 0x7B6C9E014F8B14DFULL, 0x3977CB9545621F45ULL, 
            0x3527D8CD14F834ECULL, 0x6CA0FA4C813298F7ULL, 0x3B4BB7B078483DA1ULL, 0x8E647D9C3ADFE2A8ULL, 
            0xA26AF5BDEAFD1F8BULL, 0x256DA0F2546F7EC2ULL, 0x8A5A69BE55570AF0ULL, 0x277F0D9ACF001F87ULL, 
            0x8FAEFF9E4193712DULL, 0x45124DAD9B39BC66ULL, 0x200E5715ADB99A39ULL, 0x3DA9928E3AC7D859ULL, 
            0x10474AEAFF01843BULL, 0x78AC37F04704DC58ULL, 0xD3ACB554EAB7E718ULL, 0x28D5D91419FDA2C0ULL
        },
        {
            0xD3D958A0AEEEABBEULL, 0xAC288475CC3C0C17ULL, 0x88F6B1CF442F5B1EULL, 0x8A46CA07C34EC2C0ULL, 
            0x556451D8E1A6D241ULL, 0x9A37B5DD9177A32CULL, 0x5260B01CE6D51278ULL, 0x1B226BE5FEA03049ULL, 
            0xB40E3F626E39A9E0ULL, 0xB636D4DA00F72CB6ULL, 0x49DEA904A3113CEEULL, 0x52837A2AC5AAA35EULL, 
            0x70C32450AC6C3319ULL, 0x1491F20B2A603B93ULL, 0xA6703F0A463AC50EULL, 0x33D911FB114FD3F1ULL, 
            0x8FC64F003827F9A0ULL, 0xF69C6A9CDB34B3A6ULL, 0x165BDAFB795EB9B2ULL, 0x94EC02AD43C623BBULL, 
            0x0FD5A6A50AF4FABFULL, 0xA143C067F0AAC1E1ULL, 0xE0F9DF1BA130405DULL, 0xC540819005585413ULL, 
            0xBFB07B76AB625855ULL, 0x9B2609AA2495DA9EULL, 0x19BD206A5429CF25ULL, 0xCCB671F360861350ULL, 
            0x8CE46E67E91F118DULL, 0xB1E266F5D263A4B8ULL, 0x19CFBE7436AA5629ULL, 0xA153270C9A267AB6ULL
        },
        {
            0xEC818D7FA7F747FDULL, 0x23AC528B186727C3ULL, 0xEBF4F131606A0649ULL, 0x3C3442DE282AE78BULL, 
            0xA1A8C541C01376C7ULL, 0xBFD0B2ADFAB3865BULL, 0xF07D02C1B771FC23ULL, 0x63AE65979AFB7245ULL, 
            0x508F16A39C12AEBAULL, 0x504CF49871B1EE0AULL, 0xFC93C59811697EC3ULL, 0x1EBB2A5A9005FBE9ULL, 
            0xB7D166F9F15EA213ULL, 0x58D47D2133D7062CULL, 0xF4265D54CCE24EACULL, 0xF3AD0D5A508637A8ULL, 
            0x9E515A8EACD9E09EULL, 0xE8AE9F5A82E339DBULL, 0xF9520BCDB6D9C38EULL, 0x875DBC411943E4C3ULL, 
            0xE78932F41DB568FAULL, 0x07A4C9D580DE6500ULL, 0x73185958B64D7D65ULL, 0x2E95E3D9425F6364ULL, 
            0x02011E9D3F967E80ULL, 0xC08D3C2CA71F886DULL, 0xD2ADF9ECB40FD75AULL, 0x23EC1CBE34F79A8BULL, 
            0x99F6A7F56A6AEABCULL, 0x69998B09FE6E11ECULL, 0xD76556B84E8B5398ULL, 0xFBC6C077F159B71CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseHConstants = {
    0x4908413F8DC08763ULL,
    0xD902417AE4254D4EULL,
    0x889E304FA42CAC49ULL,
    0x4908413F8DC08763ULL,
    0xD902417AE4254D4EULL,
    0x889E304FA42CAC49ULL,
    0xA8525DA0E6F4B85FULL,
    0x8D0E512C91755C24ULL,
    0xAC,
    0x6E,
    0x9A,
    0x28,
    0x9C,
    0xE9,
    0x85,
    0xFE
};

