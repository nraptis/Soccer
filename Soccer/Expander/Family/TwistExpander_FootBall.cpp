#include "TwistExpander_FootBall.hpp"
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

TwistExpander_FootBall::TwistExpander_FootBall()
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

void TwistExpander_FootBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15264161702741347165U;
        aCarry = 10392041024712986222U;
        aWandererA = 12517693953618786598U;
        aWandererB = 9406726323546943517U;
        aWandererC = 18324654852859280354U;
        aWandererD = 10777586606813515454U;
        aWandererE = 16603034376109963090U;
        aWandererF = 12226745702206873932U;
        aWandererG = 15060878708548226274U;
        aWandererH = 14533911782919146895U;
        aWandererI = 11783428678434536612U;
        aWandererJ = 18282240744728884871U;
        aWandererK = 9394686576365217416U;
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
    TwistExpander_FootBall_Arx aArx;
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
    TwistExpander_FootBall_Arx aKDF_A_BArx;
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
    TwistExpander_FootBall_Arx aKDF_A_CArx;
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
    TwistExpander_FootBall_Arx aKDF_A_DArx;
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

void TwistExpander_FootBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14259576502103520646U;
        aCarry = 17815593695226485169U;
        aWandererA = 17655664693221777652U;
        aWandererB = 16883312415352147992U;
        aWandererC = 15210813931433553705U;
        aWandererD = 10282715078541405615U;
        aWandererE = 12954923709281980915U;
        aWandererF = 15884606515811253944U;
        aWandererG = 16201746667174768334U;
        aWandererH = 14630073387372397848U;
        aWandererI = 9717454015833801620U;
        aWandererJ = 11951293476223548002U;
        aWandererK = 16898118738696306582U;
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
    TwistExpander_FootBall_Arx aKDF_B_AArx;
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
    TwistExpander_FootBall_Arx aKDF_B_BArx;
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
    TwistExpander_FootBall_Arx aKDF_B_CArx;
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

void TwistExpander_FootBall::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneH);
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
    TwistExpander_FootBall_Arx aSeed_AArx;
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
    TwistExpander_FootBall_Arx aSeed_BArx;
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
    TwistExpander_FootBall_Arx aSeed_CArx;
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
    TwistExpander_FootBall_Arx aSeed_DArx;
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
    TwistExpander_FootBall_Arx aSeed_EArx;
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
    TwistExpander_FootBall_Arx aSeed_FArx;
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
    TwistExpander_FootBall_Arx aSeed_GArx;
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
    TwistExpander_FootBall_Arx aGrow_AArx;
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
    TwistExpander_FootBall_Arx aGrow_BArx;
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

void TwistExpander_FootBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_FootBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 13759947340069234024U;
        aCarry = 17225901381223984661U;
        aWandererA = 13012952106568082217U;
        aWandererB = 12769299906678247241U;
        aWandererC = 16494654986785093010U;
        aWandererD = 9929271751310085582U;
        aWandererE = 12242359339489935521U;
        aWandererF = 16224683715105180280U;
        aWandererG = 14919471018963392680U;
        aWandererH = 18088412006183663291U;
        aWandererI = 17148022562756042937U;
        aWandererJ = 15311306597415015289U;
        aWandererK = 10560929574019919117U;
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
    TwistExpander_FootBall_Arx aTwist_AArx;
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
    TwistExpander_FootBall_Arx aTwist_BArx;
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
    TwistExpander_FootBall_Arx aTwist_CArx;
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
    TwistExpander_FootBall_Arx aTwist_DArx;
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
        TwistExpander_FootBall_Arx aGrow_AArx;
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
        TwistExpander_FootBall_Arx aGrow_BArx;
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

void TwistExpander_FootBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 2, 3 with offsets 3391U, 5385U, 5922U, 2669U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3391U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5385U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2669U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 1, 1 with offsets 4888U, 2509U, 595U, 5092U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4888U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2509U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 595U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5092U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 3, 0 with offsets 5461U, 5831U, 2787U, 462U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5461U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5831U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2787U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 462U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 2 with offsets 710U, 6699U, 7192U, 7486U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 710U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6699U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7192U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7486U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 1320U, 1851U, 1338U, 435U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1320U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1851U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1338U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 435U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 3, 1 with offsets 117U, 1307U, 1920U, 1805U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 117U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1307U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1920U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1805U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 1682U, 1722U, 992U, 1196U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1682U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1722U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 992U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1196U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 0, 2 with offsets 142U, 967U, 107U, 1071U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 142U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 967U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 107U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1071U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 206U, 621U, 1635U, 210U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 206U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 621U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1635U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 210U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_FootBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 3 with offsets 3877U, 8082U, 2320U, 1194U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3877U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8082U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2320U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1194U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 0 with offsets 3418U, 5561U, 677U, 3325U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3418U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5561U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 677U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3325U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 1 with offsets 5647U, 2753U, 507U, 6718U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5647U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2753U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 507U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6718U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 2 with offsets 168U, 2453U, 6509U, 2950U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 168U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2453U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6509U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2950U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 8041U, 3921U, 7936U, 3273U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 8041U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3921U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7936U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3273U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1130U, 287U, 1599U, 114U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1130U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 287U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1599U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 114U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 669U, 1004U, 544U, 479U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 669U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1004U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 544U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 479U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1624U, 619U, 661U, 836U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 619U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 661U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 358U, 1718U, 1423U, 1023U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 358U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1718U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1423U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1023U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 0, 3 [0..<W_KEY]
        // offsets: 1665U, 1777U, 1703U, 365U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1665U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1777U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1703U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 365U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseASalts = {
    {
        {
            0x776E0B4022A2452EULL, 0x3F448CC996A74B25ULL, 0xD68693FB11B9955FULL, 0xCBE538177CF4E0E2ULL, 
            0xBBF04FAF20F846C4ULL, 0xC1622DD033491148ULL, 0x82B3C6021F297FEEULL, 0x2C13BE7392ADB3B1ULL, 
            0xDF6A43D1B559F794ULL, 0x334EAC9BAA130979ULL, 0x1192B9414110EAA9ULL, 0x4B100A8D5BE59A03ULL, 
            0xC1C4FD542108D036ULL, 0x63988A88DC098100ULL, 0x4746B71478FFCBBAULL, 0xDBA8286E26440B0BULL, 
            0x9876BF5510A9B5A2ULL, 0xA8EF497F22226AD5ULL, 0x0E631F7C653A44CBULL, 0xA15A768C047A5E2BULL, 
            0x6BC47AFF525B8346ULL, 0xE2E6B8AFFAF91D5BULL, 0x95E5A068195148D6ULL, 0x6FC65D22828AAA21ULL, 
            0x1C9F8E12552E2C11ULL, 0xB7AE827D393F72B1ULL, 0xD2DF6D5DFE8B91F1ULL, 0xB0BAA10F1656BFDFULL, 
            0xC3C4BA4EF28B6C09ULL, 0xF77A2636E47C01C3ULL, 0x5FD082097CA94BA1ULL, 0x9F4416ADBB51AA49ULL
        },
        {
            0xE9424A7F655C89CAULL, 0x6DDDC6D0E55B7028ULL, 0x03FFCBD552768735ULL, 0xC5C5F920F5069419ULL, 
            0x00825E0F070B1953ULL, 0xCDDC4BB1486E1549ULL, 0x500F9AF9DB5A8A20ULL, 0xCB05B53610A3C5A8ULL, 
            0x79A1D9396BD1D16AULL, 0x790B872B32E9008BULL, 0xB2C87B2C1F41C8CAULL, 0x4FE3B421EE54345CULL, 
            0x7D6B5B63CBEEF1A3ULL, 0x2C7420F319A209D9ULL, 0xC3BACC665115BE55ULL, 0x0B3DE76B8F5C2B3EULL, 
            0x51E5624EE2223C2FULL, 0x26086099BBA9585AULL, 0x50CEF45ECDE42CCCULL, 0xC7A095850BE80F3FULL, 
            0xEC77A8E87E479842ULL, 0xAD43C6CF99966BDDULL, 0x7FF70E4486F4A753ULL, 0x060854D9D6432928ULL, 
            0xAA35ECB2FC4E91D7ULL, 0xBC121ADA7925D3A0ULL, 0x3EE09B94727E5193ULL, 0x2421CAC7ACE18AD2ULL, 
            0x4A6C15CD25217A9EULL, 0x0EC0E30B194CDDEFULL, 0xB69B395126367E59ULL, 0x83E8F21A7B313CCEULL
        },
        {
            0x6D349DE58793A573ULL, 0x05B8A09658EF1324ULL, 0x54C31952649E5A41ULL, 0x59E1D919E219E431ULL, 
            0xDD3BE558EE5A1719ULL, 0xE85B785D2A29A5BAULL, 0x68D0D61E91D8545FULL, 0xFBA93B5C7B09CF7EULL, 
            0x3222E95A8B57FA61ULL, 0xE2BBAA653B22DA17ULL, 0x396A5A1497A77476ULL, 0xB1E70B292617308BULL, 
            0x645F6ABC7340B450ULL, 0x651C6964E0E76071ULL, 0x03CCC93CCF7D26AFULL, 0xF86A7544A011E136ULL, 
            0xB52B7065B2494086ULL, 0x6D3F785BBE0C3D1CULL, 0x83437E73143E338EULL, 0xFF215DD606DAEB0DULL, 
            0x1151AA1121E03DDDULL, 0xF646F9E73B7B74CBULL, 0xCF42760D48E75D99ULL, 0xC468D78551FC8AB3ULL, 
            0x12CEE74CAD005647ULL, 0xA7C552C97298BB10ULL, 0xBC9393B5F0C3EA72ULL, 0x772C75FAD2A4311FULL, 
            0x013803887353A2DAULL, 0x4CB90261806986ECULL, 0x3C9E215C9BF5E52EULL, 0xC814ED199563B865ULL
        },
        {
            0x0F3C0605E4A179E6ULL, 0x21F22081937CF5B5ULL, 0xFF15913BDFE9B4A6ULL, 0x6D0C4B67C759D418ULL, 
            0x6346795E0FE898BDULL, 0x79E82956ED69D231ULL, 0xF6F792401F38C13BULL, 0xC38F24C130D3F254ULL, 
            0x6AEF0F767FDBCE6FULL, 0x2D73FC9F101C8FE5ULL, 0x4804D9C72039B056ULL, 0x39D4A714EA210938ULL, 
            0xC9B35B8B6E9CC48CULL, 0x3F64A90302833D58ULL, 0x8D219BCAD38BFBB0ULL, 0x41B3983A3B015914ULL, 
            0xC45E6246ED233BACULL, 0x7134496972059854ULL, 0xF9D58CD3D9871591ULL, 0x0B3757DAFCD34401ULL, 
            0xFDD01050697824B3ULL, 0x06988FE0453CE181ULL, 0x0823CB15A0546FC2ULL, 0x69EE1D9EF168C6F9ULL, 
            0x67CA93A182C7BD27ULL, 0x3BFD3E722CCE0017ULL, 0x10C20C563F80DB0FULL, 0x869139D8DA3BFEFCULL, 
            0xCDDA3D2821F6E13EULL, 0xE30EDA41B40DD9BFULL, 0x0A3E872C7D92C383ULL, 0x3ECC0C8651F618E5ULL
        },
        {
            0xE273E366A393116CULL, 0x5D746E38A10D6859ULL, 0xC5640C3E799BD586ULL, 0x59AF168DF7C984D6ULL, 
            0xBDAD67031B7C0DFEULL, 0x466FCE48A62CC266ULL, 0x4549E5E9BBB1AC56ULL, 0xE77E5C350C8F4F03ULL, 
            0x0C7D58BE626F4BB1ULL, 0x762BC6017F2F2E28ULL, 0x4BB512326A12FBADULL, 0x2187333B37A39D62ULL, 
            0xCB3FD0B8DE5876CDULL, 0x72076BBCD3ED223BULL, 0xA669AB44586F96B3ULL, 0x3033579FB4E2EC42ULL, 
            0x5589A90B601E8622ULL, 0x91547D99488D37A4ULL, 0xEF3E1BD7A321ED57ULL, 0x2ED5B2EA962730DAULL, 
            0x28EC8216994CC1A8ULL, 0xBEA8391683315563ULL, 0x97BF3B209566DB23ULL, 0xC450A11E92FFB8B8ULL, 
            0x70C5AA7EF7C88434ULL, 0x2C60B490DC143654ULL, 0xA939981254772F38ULL, 0xCB2E3DCE916BB487ULL, 
            0x0D6CEEB4A312C94AULL, 0xC871084A582D5006ULL, 0xE88780C41F975FC2ULL, 0x6EB53AF31555FF59ULL
        },
        {
            0xA1D4F3FF3D75FA63ULL, 0x449C5C9B2BDBDEA9ULL, 0x131A2F40E6158696ULL, 0x2AC3027E0E1DD740ULL, 
            0x89BAC46FBB3D1E46ULL, 0x04C8B25BDC34413CULL, 0x78AF8154AF9E7D8AULL, 0xA401B713582E6BADULL, 
            0xB0D4E6F73F223226ULL, 0x94A78426DB69FF1BULL, 0xB3F2D0B5C4FF4DA8ULL, 0x794739D8F45E79F0ULL, 
            0x14741BDEE2902474ULL, 0xBB16AACF020E4526ULL, 0xB9899D720F372ACBULL, 0x75C6ADEEAF474B79ULL, 
            0x39D33430E40330A0ULL, 0xA8492949C394F9DAULL, 0xA4C953A08C0C9B23ULL, 0x89E22A3191D7EC93ULL, 
            0x009BEB36DE7699AFULL, 0x3075FBB8AB6ECCF3ULL, 0xA2C5546750BE31B5ULL, 0x5D893CEDE7D6E0FEULL, 
            0xF2EC0FCA4A42A132ULL, 0x8DF4C59B0889DA85ULL, 0xA3B5BF91FADD52D1ULL, 0x9898743F99698D4CULL, 
            0x92317032F6C791DAULL, 0x2368663963EE8676ULL, 0x10C54D1E5179D618ULL, 0xD934F86466AD8C8AULL
        }
    },
    {
        {
            0xA041879BC5ACE5E8ULL, 0x3D2DB214B6C3D8C1ULL, 0x295FFA2E349164C9ULL, 0x14EB64D33CED4715ULL, 
            0x0AA8D970E9F16DB1ULL, 0xC8D8CCE13A94642BULL, 0x5FA9A0B3E01D4D42ULL, 0x2FE1AF683862A483ULL, 
            0x9D5D9852171A3969ULL, 0x87300677D339C8F7ULL, 0x4F68C6B45B62E422ULL, 0x5C8839D8BB1ED2F3ULL, 
            0x88DE22531B5498BBULL, 0x4C3FF3E4CAA525C8ULL, 0x007333B06323BC95ULL, 0x29534BA7D7F83D94ULL, 
            0xAE680359F8D173F9ULL, 0x10053B8A8C6E8BDFULL, 0x35CC251BEB65A4D1ULL, 0x423D8352ED8ED93FULL, 
            0xB7206FBDC202B62EULL, 0x05A24B6712B7F4BBULL, 0x29E1C34250173D00ULL, 0xF0C10631C5E6CA4BULL, 
            0x951D25D9A0F365FAULL, 0x43502AD505EE8F83ULL, 0xFF8038AF3EA7BD48ULL, 0x16D9CB9962838043ULL, 
            0x1BB9F636946F7BAAULL, 0x6F7683EBD4515620ULL, 0x5AB0D8CDC77EFC99ULL, 0xCEDE9844D8A82D95ULL
        },
        {
            0x9C1B2E4626276A37ULL, 0xF477C600F2CF14FEULL, 0xAEF5D8F4823CC11FULL, 0x8545D3E9EC58C595ULL, 
            0x6980BFFB80F7DCEBULL, 0x001B5D68B63DFF6CULL, 0xD30874C47F12C00DULL, 0x54FA4F065A42E6FEULL, 
            0x1E045B18449AFB72ULL, 0x671DF989A6099642ULL, 0xB9429CB1DE9D76D0ULL, 0xF5897CB20F84F58FULL, 
            0x3C57A30C5685FF30ULL, 0x26339E52F4385DA2ULL, 0xF8C1A1A9AE9B6080ULL, 0x3900ADE17CC813C5ULL, 
            0x90999251B099D7BAULL, 0x2B6D6219B72C6C93ULL, 0xA3B9F1757BE2C685ULL, 0x88B5224436F3EA44ULL, 
            0x336E2079E4A3BFFAULL, 0x05687A3BE95318EEULL, 0x37B23904BD2974B4ULL, 0xBDABE401D693DB88ULL, 
            0xAA3EDD64041E7227ULL, 0x98F4F781D8EE5D98ULL, 0x277047D9D7413D25ULL, 0x507523AB8EAD055CULL, 
            0x90E7593565939A9EULL, 0xC8A47A2BD596C69EULL, 0x1DB7964A503BF637ULL, 0xE6F86D75EC71D77EULL
        },
        {
            0x5B863DC33F21555DULL, 0xFFCD87450D074F14ULL, 0xF9CB05A4D02BE04FULL, 0x74B591142996E5F4ULL, 
            0x577DBA06F4F9993BULL, 0xF5B961822407BD49ULL, 0x935C76714C44DF41ULL, 0x37B88BAF514AF038ULL, 
            0x0FAAFAEDBD41456AULL, 0xDFD9746258749E25ULL, 0xE8521CD67A279BD8ULL, 0xA85D150F1C09FE08ULL, 
            0x056A50C3A8FE8E82ULL, 0x069DD8E17DC24795ULL, 0x8559081CE4B6BE23ULL, 0xBD57DBE69C488B78ULL, 
            0x2B559275077154C3ULL, 0x2459D7649740B007ULL, 0x7676661547956CCAULL, 0x2E840080E16983B1ULL, 
            0x23EDCD40FFBE9F31ULL, 0xB1BE823210992311ULL, 0xBE7F510A79744BEBULL, 0xACC8844097834B31ULL, 
            0xA63BE358D3055803ULL, 0x6698CC5C25646CE4ULL, 0xB3311C8C8DE3AA71ULL, 0x715C65B81875F914ULL, 
            0xCD12835AC77FB8A5ULL, 0x251CE5B9ADCCC3E8ULL, 0xB2AFC4B2F2C18CB4ULL, 0x7E5835B909A1A662ULL
        },
        {
            0xA840A1CD4F191E23ULL, 0xAE528C981FB65721ULL, 0x198674A450C246E0ULL, 0xDC8A65FFEE651C71ULL, 
            0xC01DAA5170DB8A46ULL, 0x1CF225FB28D5DC9BULL, 0x2CED16C7D439EBCAULL, 0x31C3C9BFC4417C82ULL, 
            0x5FD4EB4BC3282A6BULL, 0x2552876C1E4536C0ULL, 0xF74C98D50A8EE8BDULL, 0xB77593C256BBEC1BULL, 
            0x63012CB8E5BAD783ULL, 0xFCF06C4DCAFDF6E5ULL, 0xF0FE7A5039867E28ULL, 0x47DFB87163421734ULL, 
            0x427D5EBAE903EB64ULL, 0x83A89F19B108FDAEULL, 0xDE4B55E197E76BE4ULL, 0xB2779D8024FD465BULL, 
            0xE1F4EF00ABADC5B5ULL, 0x55E066995EDCE5C6ULL, 0x39C2BAD6B9B39FBDULL, 0x5715D4BD35BBE515ULL, 
            0xEB26502060EE25D0ULL, 0xB431F7D65BBF6657ULL, 0x3DC21CF2A944002BULL, 0x1F049291CA9167D0ULL, 
            0xF1EEA5ACC3B910DDULL, 0x0805241359715F63ULL, 0x25992B884DBEBBEEULL, 0xBA3EDC44582FC7AFULL
        },
        {
            0x98F0F4E543EBC430ULL, 0x7639CAFFE5C5934EULL, 0x16ECEE8C03B8E47AULL, 0x5942A51BEA5A05F7ULL, 
            0xFEC4472C30CAD598ULL, 0xD08D97F259C13FB2ULL, 0x1867769038FB1563ULL, 0x4684E4C048F584A9ULL, 
            0xF78A816583D3C6D8ULL, 0xB3FE48155A699E20ULL, 0x14F8B75DDE100FA1ULL, 0x203C0F2E92F64B54ULL, 
            0xE13E8DFE2A1C07DDULL, 0x4A5A6C8E89F5ADC5ULL, 0x225F8381FDA554E2ULL, 0xBAF8E4C98AF6106FULL, 
            0x3C91A6747F63C3AAULL, 0xF8D839E2827EF7FEULL, 0xABFA3F11167DF458ULL, 0x7D0E291F6F7AB246ULL, 
            0xB55948EE2D0C2F02ULL, 0xEEAD2159547A0B0BULL, 0x0AA181BB007805C0ULL, 0x694C67567EBD73BDULL, 
            0x6ADB10B95292D614ULL, 0xDF044A93D1483DA7ULL, 0xC5E138411D845391ULL, 0x4A9291D54C60E4AAULL, 
            0xA8F3B369337E8B84ULL, 0x87C3AA7A1405D2DFULL, 0x6E3C6EAE040043A7ULL, 0xDD6D11329E14640CULL
        },
        {
            0xD3523138C30FAEFDULL, 0xA202CF1C16B03811ULL, 0x11C6EE4CC20F25F4ULL, 0x396D67470FB1AE7BULL, 
            0xB75E9A44FC66858AULL, 0xF38E77CAE211861AULL, 0xC4855A2D50430740ULL, 0x767F969F3AEF4F70ULL, 
            0x6F075D03F23583D7ULL, 0xFF24257030181915ULL, 0x2B7D8DD724E177A7ULL, 0x435FD632238D65F1ULL, 
            0xB118007CF6FE2476ULL, 0xBB158CD899497F08ULL, 0xC3C379008B3A69F4ULL, 0x3B118EE59CC0C559ULL, 
            0xAB685226B3E49874ULL, 0xBC8106E7D379F195ULL, 0x9F5788887300702AULL, 0x288DD027D18C58FDULL, 
            0x238BE765E43C1755ULL, 0x25D371844DB14C56ULL, 0x834F0545245FE710ULL, 0xA4A84637F861A2CEULL, 
            0x1FE0D3428D65BD5CULL, 0xB6FE7391B8FC6794ULL, 0x09BFF9BD311D5C0FULL, 0xD8198B3657CD240DULL, 
            0x7CA33C17E0DCCBC3ULL, 0x9867F4180C326ECFULL, 0x1DAA62C141A4D60EULL, 0x32594771A5E033FDULL
        }
    },
    {
        {
            0x62F23F1290E1EB7DULL, 0x645755ED07FAEDBDULL, 0xB0D29D544EDA5997ULL, 0x7E6D4C4FAC60925DULL, 
            0xA409D464FC8F194EULL, 0x09067C81BB8823E9ULL, 0xC7E7CDCB4A606172ULL, 0x65991CCE2C32260DULL, 
            0x215DBA1A647FBC7AULL, 0xDD9ADD19747D675EULL, 0x36ACBF90B2C55D21ULL, 0x3C4227A822F7793AULL, 
            0x08A36D987FCB1B21ULL, 0x526E90CDF2CEB1D1ULL, 0xA12F3C84EE97F154ULL, 0xEFEA2DF32C3B0A37ULL, 
            0x5D660633EB589FDCULL, 0x535C6164A8FAE560ULL, 0xA1E4D3E28E790513ULL, 0xF4C6AF11FC83CA56ULL, 
            0xEAB66A558A25CA75ULL, 0xB326AEFEC2C9C278ULL, 0xB89BAFADFEBBFACCULL, 0xAB5575D26C0564E9ULL, 
            0x1D543062DD6ABD9FULL, 0xB58B4CB0A930299DULL, 0xE8C7C37D058E6630ULL, 0x9A8439B20C9E174FULL, 
            0x059A618B680E6BC4ULL, 0x9F77A25D522C30A3ULL, 0x2D0521934FBA34FBULL, 0xB24B0A166A976C9FULL
        },
        {
            0x023CA67F47CE256FULL, 0x90DFA0C747AC7D3EULL, 0xE765855083336354ULL, 0x7F85BF4CA9E4DD15ULL, 
            0x786BB93918F5C0E8ULL, 0x685F4FCD45F2A7D8ULL, 0x1043CDC8E6062479ULL, 0x2C8C674E8E3FD6C8ULL, 
            0xA39C8BFA001F5E48ULL, 0x22320F7BFF242E5CULL, 0xF1BEC6F1B82417B6ULL, 0x5B474593BCD4AEFCULL, 
            0x34BD6C40E625EA3EULL, 0x60CE91775F54D70EULL, 0xDDC5280ADA7B8FD8ULL, 0xBBAC03E8BE17F8E8ULL, 
            0xCD396C0628A576F8ULL, 0x5F159185AEB459FDULL, 0x8DC879C16EA95098ULL, 0x4BFEB76D9667C265ULL, 
            0x0076861359343454ULL, 0x9C38D9B127780D0EULL, 0x7FEBE0D81F12E1A3ULL, 0x73FD5612E525F3C1ULL, 
            0x8AF8D2E5F8ACF9B6ULL, 0xF601A88C5C5FB418ULL, 0x48D2F1EF88B5A547ULL, 0x9DED3F09F247AA9FULL, 
            0xD8ECF2459133EDA0ULL, 0x24EDAC1E141D5B75ULL, 0x5EDA6EDB35730321ULL, 0xE65C8003DE2A6B9BULL
        },
        {
            0xD5132B96254A0B93ULL, 0xD5F80352F23E653AULL, 0x653135B7E1903BE5ULL, 0x2E885AB2F9A1EC39ULL, 
            0x9B6EAF7C07DF6F67ULL, 0x5A40E1C38A4FC19AULL, 0xBBA04CE2E82E175BULL, 0x0C632B69753FCA69ULL, 
            0xB1233905BBAB771FULL, 0x6276A15CC5016834ULL, 0xA1F2BD879A6F1CEAULL, 0x959F204E1F413C52ULL, 
            0x78689C40CBB272EFULL, 0x78A83CB190E671E8ULL, 0x7CF7FBDC213ABAF1ULL, 0x45647D6C468562A9ULL, 
            0x45A51509DADF7FC8ULL, 0x322A7CD791426877ULL, 0xFBD26E2486737FF9ULL, 0x4F8C67F1623A46B1ULL, 
            0x6110862D157F523BULL, 0x39F4EE8AEED77B67ULL, 0x41913C1987E2ADFAULL, 0x995DC6ABE45B96ADULL, 
            0x5EF9C2F9E08FB2B3ULL, 0x49B36D1ED7B55644ULL, 0xC2B701745EAD46E2ULL, 0x6460918E6556C9D0ULL, 
            0x98CBA3B6A192BB35ULL, 0xA99FDED70696FE99ULL, 0x9D5B75F9BF54F5DFULL, 0x85EDF907F4E158D9ULL
        },
        {
            0xEC60ACD37E5B6E23ULL, 0xF8B49C8F7C8D3ECEULL, 0x77F5FEA3F73F1586ULL, 0xBB90B65716836889ULL, 
            0x647EB6731DD94B63ULL, 0xDBEE6F0F35470C9CULL, 0x1089D4E181508E80ULL, 0xFCD73439B3E3B746ULL, 
            0xC61F5A807928B157ULL, 0x0A81C9B46D01F2E6ULL, 0xF288571584CD5041ULL, 0xB2178ECDD2E042BFULL, 
            0xA4098BA6367A5C24ULL, 0xF4B14EE17BC81EE5ULL, 0x1609CC7EBA566D8CULL, 0x5C0D0EEB906133F1ULL, 
            0x0FE7B6F4286E3B0CULL, 0x83D9EC7F0F652CC3ULL, 0xFA0BBD9011198012ULL, 0xAEA3AB1CE0D58051ULL, 
            0xC6A8E537FAF663CCULL, 0xCDC8427DCCF347C4ULL, 0x6E2C9E73D8B0320CULL, 0x6172A7E2D117F3DBULL, 
            0xEF439C5585D3B832ULL, 0xF0B1BBD52D54FD61ULL, 0xD80D8C6AD29ED88CULL, 0x14FC7F650D902DA8ULL, 
            0x216FA9AF4D7E8EF6ULL, 0x4E14B3705174D7C3ULL, 0xEE5391383B961D51ULL, 0x29D7AF11A86F6C67ULL
        },
        {
            0xAAFFC0AFE41F9979ULL, 0xDA6C6E53686FE514ULL, 0x5FFDC1733FC489E1ULL, 0x662022FA58B6D6C1ULL, 
            0xF41040C349D71A78ULL, 0x0651D40A0707A5AEULL, 0xC57D319C9BB75EA0ULL, 0x6BADF6B98E3D5232ULL, 
            0xB4CE2EEAA5944B51ULL, 0x9E204204D4C7CC31ULL, 0x60C55C4C027EB9A6ULL, 0x9600E5802C30C11AULL, 
            0xCB9C7BD5DB5E9995ULL, 0xCC490E0E55CE2C9BULL, 0x992442727068A20EULL, 0xCA18A0521562F4BEULL, 
            0xD58B62C4F2491BE6ULL, 0x22B54EB9740B6B10ULL, 0x926253ABCF89740FULL, 0x67864129A79EFC40ULL, 
            0xE8182BE759C85FBCULL, 0xF63747C06BA10D4BULL, 0xD61DD13FD8631F39ULL, 0xD6D3A9CC49ECFF62ULL, 
            0x50E194A0E4537B3AULL, 0x153147668DAC693BULL, 0x0C8A3675A07FC7C8ULL, 0xE1144A23F69112ABULL, 
            0x60CF2D6D38132753ULL, 0x656095FDA06BE787ULL, 0x325EBD7E4C2D1128ULL, 0xE3D7D5C4D7092959ULL
        },
        {
            0xAF9BDDFC41466BC7ULL, 0x38CB27C00923358FULL, 0xB9ECC86ED9F129A4ULL, 0xE2A63CAD432753E1ULL, 
            0x4B654DEA5130A530ULL, 0xFC78884E753B9C6BULL, 0xBE76469379493D58ULL, 0x901FFFD92EB709FEULL, 
            0xCEADAFCB276E497BULL, 0xADC0FCBFDA4BF12DULL, 0xFE2D884015CED856ULL, 0x1A8AC7386F267743ULL, 
            0xA79F6C1C252F1A5DULL, 0x949DE02350D955ABULL, 0x089D139BFD81100FULL, 0xB747ED95DCD722AAULL, 
            0x21EE748F823D864CULL, 0xCD22C4AF4753A88DULL, 0x1A9B7DFEBB6344D3ULL, 0xB398A248BC578485ULL, 
            0xDB18C759790BB2F9ULL, 0x5CA021F764901A3AULL, 0x3A8BB22F168D4391ULL, 0x27836F3B9AC0954DULL, 
            0x97309585A5FB8924ULL, 0xA0AB2C4B30086340ULL, 0x2EBC15912207CC3AULL, 0xB54B9F9ED660A25DULL, 
            0xE4189708D2C98018ULL, 0xC76B4E4672D59740ULL, 0xEF23F5E9EB5C7280ULL, 0xD75EA9EF93BB74E0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseAConstants = {
    0x89F878C0D1F22DC7ULL,
    0xD33AA683EEDADA1DULL,
    0xF69836F5D2446283ULL,
    0x89F878C0D1F22DC7ULL,
    0xD33AA683EEDADA1DULL,
    0xF69836F5D2446283ULL,
    0x98AC3D591A9204F8ULL,
    0xE88566095A2AB409ULL,
    0x56,
    0x1B,
    0xAB,
    0xC9,
    0x76,
    0x4C,
    0xE1,
    0x07
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseBSalts = {
    {
        {
            0x49A7DDE5BCAF3A72ULL, 0x76843C779B756940ULL, 0x9188C0E2ECF94C77ULL, 0x15D7437D8693C657ULL, 
            0x1AD9CA8B02BDD80FULL, 0x26FDBDB621A28F22ULL, 0x241C1CFEFB943061ULL, 0x608AFE579FA90A74ULL, 
            0x24057A7CEE180E3AULL, 0x49650A5646E5CCDDULL, 0x426C001BBD3623E2ULL, 0x9F3FE83B3FAE7933ULL, 
            0xD896789059576639ULL, 0x200174E70D959A97ULL, 0xDB61557D94D88D0AULL, 0x7BCFF7AF94E146B6ULL, 
            0x3557106FC1C460CAULL, 0xF79F5E4AC3FF2A70ULL, 0x25A5E2B5FB882FEEULL, 0x37FF6D039D9D11BBULL, 
            0xF3833FF8B500D653ULL, 0x3879E606CBA90E48ULL, 0x57E3F64C06EC77D9ULL, 0x13D9CB63C44D3895ULL, 
            0x51D19CEB819CD87BULL, 0x63D3D9484220067AULL, 0x2476B5BECEAC5D01ULL, 0xD831950A21B80B21ULL, 
            0x1BCFD89FD0FD9306ULL, 0x2F9671593E5FD560ULL, 0x51FBBBAC7C9CFA07ULL, 0x16309B2630D8EC66ULL
        },
        {
            0x96ED1B4A2E768D2DULL, 0x81273390033AA3F1ULL, 0x3F9A5422BAEB447FULL, 0xB8E850BD6473026BULL, 
            0xCEF85FE989ABDF60ULL, 0x7839E63FD7562B4CULL, 0x0D24A99A5E3AEA11ULL, 0x6E282F94868FA4EFULL, 
            0x66E906C4501DB381ULL, 0x0D45792D6A5B1363ULL, 0x3A0A81C9CFAFECA5ULL, 0xC4107AC8DCE0BA30ULL, 
            0x7DFA977A39658956ULL, 0xD84108E3A45C2C18ULL, 0x4F53C0BA8E293C58ULL, 0x3A1F3F7CA6207801ULL, 
            0x9B1AA934B00B14BAULL, 0x1FB3BF3AB9544A12ULL, 0x707C2F984BAF42A3ULL, 0xFAC936B448280AAAULL, 
            0x037413447CDD07DBULL, 0x2BCEA66BDCFDE26AULL, 0x125AFE2512D4D18CULL, 0x9116AC90BF2B1EF5ULL, 
            0x060F4C13EA13E612ULL, 0x37FC631F12C342EAULL, 0x28FAD46A2A01BAA2ULL, 0xA3DF16593E1FDD89ULL, 
            0x60683428D974EBF1ULL, 0x6551111601AF6A1AULL, 0x5657039C864FB208ULL, 0x8D3D4F05A19FAF92ULL
        },
        {
            0x496FECFA67835FC8ULL, 0x1D13F026115456A8ULL, 0xC96CF313A61CBB3CULL, 0xAE7F03F069B2CBD6ULL, 
            0xD69EC715EDB191DFULL, 0xB1DDF36E2C6A2F0FULL, 0x095CE8E0B3D3B2E4ULL, 0xBAA929D5ADF09808ULL, 
            0x7D9409FBB5C91499ULL, 0x0D944CC0CF0AB301ULL, 0x89EFEF836493321AULL, 0x8455F69CEB521ECBULL, 
            0x07D680A7477396A6ULL, 0x16F18FBE7618C8AFULL, 0x17072EF4C6D9AC8EULL, 0x22717884A8B12E93ULL, 
            0xBA2FC92890305400ULL, 0xB672D11FACEA1B14ULL, 0xE4C14A11E6D799D1ULL, 0xD225FC3A6D1C3DC2ULL, 
            0x254D76A0A71A8874ULL, 0x19C09EA5FC08D9F8ULL, 0xABE9107F739CDF47ULL, 0xB97456713B4C7633ULL, 
            0x0BA3C58465C89370ULL, 0xCAB834B2C1677B02ULL, 0xF8A871956D663183ULL, 0xC984D1DD7573D9F3ULL, 
            0x068557B68C71B6C0ULL, 0x72CBF9BACE91515AULL, 0x707E1A5C90F6E06DULL, 0x65EAF9C5F43771A9ULL
        },
        {
            0x5F21FEB42053C202ULL, 0xAA8134F11468AC71ULL, 0x263AF8A164F7A989ULL, 0x0018EBC5915EE828ULL, 
            0x47CDE105FA23C7F8ULL, 0x2C0FCF475B758008ULL, 0xA3F410C2DE74694BULL, 0x95061408A8CAA0FAULL, 
            0x7849EEE2335E79BBULL, 0x117B1C0747A0AA24ULL, 0x28D22F26CCF45E2CULL, 0x87ACFB9300A83588ULL, 
            0x70BF6874C16140CEULL, 0xCCEDC16232DB487FULL, 0xB2FF8C8F5D4A4E5CULL, 0x8487F9AB9B08DF34ULL, 
            0xDB92AF761290BC3FULL, 0x3F1EED12E72430E3ULL, 0x2DF021C3DE13EDC3ULL, 0x26B81E871ED2AABFULL, 
            0xC84A08B90B9D4536ULL, 0x33B546938F0615BBULL, 0xF9E48B70ECCF767EULL, 0xEC5DA538C9209042ULL, 
            0x9EE82D3FE23EF68AULL, 0x32D2B916CA9B782BULL, 0x113859B9A4C9279AULL, 0x12C2DB69F59C22E7ULL, 
            0xABBEE95040A1C5A5ULL, 0xBD4C86B2C71BA511ULL, 0x2BA64D0B1F8DE734ULL, 0xCB9085D71B67DE31ULL
        },
        {
            0xE19CA4794240F459ULL, 0x6E3A44756C4A1C92ULL, 0x541F4E579410A56FULL, 0x9B8A979122CF4544ULL, 
            0xB17C440BE7D3730BULL, 0x9465F7584C7A90D0ULL, 0x8FF63D4F6153144AULL, 0x01CEFA6EAFB6F14EULL, 
            0xF0C4B0E6CE2C594FULL, 0x649E43EA702105C2ULL, 0xC19A2099172B7125ULL, 0xA63699F0CBF43CDEULL, 
            0x4D788C24C27E488DULL, 0x2759CC4BB535570BULL, 0x73EB1226CF0939E5ULL, 0xB4F690371FD2D33AULL, 
            0xE2995C7EF1EC8372ULL, 0xBF832856F43A19EDULL, 0x039CC0984C7F0473ULL, 0x84D379044D024552ULL, 
            0xE61FE010491CBCF8ULL, 0x26BD5EE30DD98290ULL, 0x9C2D8FE6E3E3BA40ULL, 0xAF781A653A713B05ULL, 
            0x57CAB64F3FAF42FBULL, 0xD7E228B26B858FB1ULL, 0xEF32BEB0B5BF55F6ULL, 0xC64F4EB1CA73BCF5ULL, 
            0xCF975B340C3DCCF6ULL, 0xC0C2EE6367167272ULL, 0x5B4799D907A7C983ULL, 0xACFF194552BC4B1FULL
        },
        {
            0x5D7BA2D0F10AC53DULL, 0xC141E1EB3F2EA403ULL, 0xFFA1D1DB2147DCE6ULL, 0x0BB6069C6BD7CE21ULL, 
            0x5CC3A622FEABBDAFULL, 0x652EADA2EBC5ECBBULL, 0x376D6FC05C8A0E97ULL, 0x5C7B4867DCA94DEFULL, 
            0x05073873C1A0E7ADULL, 0x3AF95C6DD6027879ULL, 0xC70731CAE1DA29F8ULL, 0xB537216394CAACEBULL, 
            0x2DAD554C736E1729ULL, 0x61B654C6EEE330E1ULL, 0xBBE0CAC13F957FDFULL, 0x120F31403F570413ULL, 
            0x624EB317B78F35AAULL, 0x58A1BB338BBC5E83ULL, 0xB723CD0808CFECBAULL, 0x8FFD99C2C0D8CBF8ULL, 
            0xCF1229485D190055ULL, 0xBDAF391CFDE15DB5ULL, 0x303434BDD726256AULL, 0x768BFC2835C7B9B7ULL, 
            0x0420AA84CF90B9DEULL, 0xEA257F6CAFEEAD00ULL, 0x290F52424FC947C6ULL, 0x379DFB367326BF25ULL, 
            0x9D81F13F63F81B42ULL, 0x30FE3233AE9E9CC4ULL, 0x33F1376E51287AC6ULL, 0x3ECF0D9AE9B83ABBULL
        }
    },
    {
        {
            0x144DD923BE11C1D8ULL, 0x6101F230C1874D59ULL, 0x604A38161B85C12BULL, 0x19923A9FC3869EA7ULL, 
            0x746280E554B1465DULL, 0xEC9962AF171F8F76ULL, 0x4D447257E2AC50F7ULL, 0x6C25BB61DE39F2B1ULL, 
            0x8D24B51E0899B7FBULL, 0xF63751363DCD2AC2ULL, 0x264DB924F109B2B8ULL, 0x2DB387EF44744FDBULL, 
            0x604DF89CB2B7B912ULL, 0x517B279499AAF136ULL, 0xFC50B5E75DB2756FULL, 0x00160CE58B8B1BF3ULL, 
            0xAFBAE9A8EC942DCEULL, 0x2B17938B89718787ULL, 0x3EB650C45F67706EULL, 0x156DE480E22884A4ULL, 
            0x5DA82B29BABAB13EULL, 0x70B463A8C319A122ULL, 0xB2266AC2B38D2848ULL, 0x1D31D327BC2B17BAULL, 
            0xB7B59E1D1AC1DC7FULL, 0x1BE60A69F9865473ULL, 0x416D1E15140E054BULL, 0xA753914ACDE50CB3ULL, 
            0x51B9133409E8969EULL, 0x4FD209ADFC95CF10ULL, 0x7FE413F45DBF2DCBULL, 0xF96CB6016FB62A9BULL
        },
        {
            0x0C6A9DD38DF187A5ULL, 0x4FB9DED3DCB67D31ULL, 0x73D60CC5EA2B3203ULL, 0x59550890B5004EFDULL, 
            0x41FF0CA54401F931ULL, 0x4808A3FEE35864C0ULL, 0xF4D3171C31C08AA6ULL, 0x40514CB00ED12737ULL, 
            0xF2CB799425B7C94CULL, 0x90CD49024CE6E6E5ULL, 0x883FBBF790591BD1ULL, 0xF08E5FFAC7160789ULL, 
            0x9BE626B67C1A71B5ULL, 0x6428D3DAC602DE5EULL, 0xB74AFE535B05FAB3ULL, 0x725F1FFF58A5F9FEULL, 
            0xEAAC090875A0FB7AULL, 0x684A363F6F1D0320ULL, 0xB5D1B4FE9C00F78DULL, 0x3CB779A1F43F5119ULL, 
            0x564481F3138E9DB8ULL, 0x843E1BE33277F1A1ULL, 0x226DEB0EF662669BULL, 0x2939C159299B1981ULL, 
            0x666F5CE20F12ADD8ULL, 0xC13924D37C60F527ULL, 0xC74D7B35F48053F6ULL, 0x92C48CE98D8AD321ULL, 
            0xCB994417A2F59ED1ULL, 0xBCFBECA6047DB006ULL, 0x39AB0DF5DD1EBF8EULL, 0x2CAE150007047A24ULL
        },
        {
            0x6E66B5BA2E048AD2ULL, 0x3CF974EEBF3D93D0ULL, 0xC46558355ABE3504ULL, 0x9E9AAFDC568F9BB6ULL, 
            0x83D589647C37A9E3ULL, 0xE1C34CBF985F2B94ULL, 0x4B4881AECC514D10ULL, 0x09807614E0648E30ULL, 
            0x01D38B70A0CB0D8AULL, 0x3A3CD8525BCB1D66ULL, 0x6CD21FCDF194798DULL, 0x0B79390A78FF3690ULL, 
            0x567DACA834B82EB5ULL, 0x3BA6935B98A22C21ULL, 0xF203C1A0BA75CEDCULL, 0xB46AE2C29B5F8B70ULL, 
            0x4C9A1F4C67ED07CCULL, 0x71AF3AD46405CDC6ULL, 0xB119CE588552D8DDULL, 0x5824FD7F205ADD4CULL, 
            0x1F91328006A4F3B7ULL, 0xEBFDE09D55EA78C8ULL, 0xA95F7767BC54B863ULL, 0x50D5554B34326E3DULL, 
            0x7CC1536BD8885CD1ULL, 0xE95C60F1AE255C1DULL, 0x8F0CDA5725C43ED6ULL, 0x6C3383EEF75FAB7EULL, 
            0x7AC6F617290F3AD3ULL, 0x07F83E8F3CDB3773ULL, 0xD7948FCAEAD996E1ULL, 0x4BAC891F443BF220ULL
        },
        {
            0x3141B40AD9A35C66ULL, 0xCAFA32D1D9F347AEULL, 0x94B93842A9C77F6BULL, 0xE22422C2F1278A14ULL, 
            0xB56B20604315C997ULL, 0xBEA43C414C87D086ULL, 0x0FE9A35CE0FCDAF5ULL, 0x0C157A8AA2CC008EULL, 
            0x0368F05FDB388B6AULL, 0x1CADC12F7395F9A9ULL, 0x1F85933AC6220599ULL, 0xCA25DDE588D95DADULL, 
            0x6B6B5BCAE08836A3ULL, 0xB24287EF17D837FBULL, 0xB32F17E719B64A0AULL, 0xE8729D4ED92F8A92ULL, 
            0x4E21C846727EF260ULL, 0x5625FAA48E42EB82ULL, 0x4D2DED92C1C76590ULL, 0xF7A055C6C0ABBF7DULL, 
            0x0CA4DCA657803A37ULL, 0x810F56823760D4D6ULL, 0x55590EEE03490D0CULL, 0x6217D2BD3C962E0CULL, 
            0xCEE740CBA5096283ULL, 0x6B0BC4DEA5CC6963ULL, 0x14ABA1636F6656A6ULL, 0xF86801DC9C278A7AULL, 
            0x8E40329C14761897ULL, 0x0BB3FB3BBC79D25BULL, 0xAF23B62F7FA6C06DULL, 0x7AF220E1C881BCEFULL
        },
        {
            0x63DD2BAC031BEF47ULL, 0x67372A904D8F22FEULL, 0xB561527418EDB84CULL, 0x15D4193E9D65D3FEULL, 
            0x7FE344084DDD523BULL, 0x405B421F8E187D2AULL, 0xC6EA98B37AE7E809ULL, 0x4FAE3D45D9BFCAF6ULL, 
            0x446FA63F01E01759ULL, 0xADD30BC88F1808D1ULL, 0x96DBC1FA33DDC119ULL, 0x519DD73ED9F3C40BULL, 
            0xF4C714AA349DB21CULL, 0x1681D1F3729570C2ULL, 0xEBE23BB27B5B1105ULL, 0xC0CAF363C7847E46ULL, 
            0xCC0D79EB1480ACFBULL, 0x0ECB4D57F9DD084FULL, 0x8C44E3CDA7D05274ULL, 0x508627C1BF46384BULL, 
            0x5B8A272294BE5C37ULL, 0x14016FD527726E28ULL, 0x000F245F0ECD6ABAULL, 0x6626CCE33D583091ULL, 
            0xC16DB45B7F348A99ULL, 0x0D819891998B55A9ULL, 0xDAD476D46122D240ULL, 0x97B11A016CD8DD5AULL, 
            0xEEC4AA4053422DF4ULL, 0x70AD0B76507746DCULL, 0x948872B2FA3BAECEULL, 0x1F5F5BC3DF563E52ULL
        },
        {
            0x4604E5704F65A56CULL, 0xE4100FF9DD561349ULL, 0xD094B2AFE09221BAULL, 0xF5AD90782C8F9CC9ULL, 
            0x9213E71BA8FCC29CULL, 0x4D327E8865B958AAULL, 0x93521D9A7590C566ULL, 0xC8C7577A4E1190F0ULL, 
            0xD76505723FDA1026ULL, 0xD958D7DDCB5CB9EBULL, 0xC78F0E075EC4C189ULL, 0x5F15ED237765AAC7ULL, 
            0x8ED266799369A95EULL, 0x8E941D37BC7FBB9EULL, 0x76319583544FD482ULL, 0x84E0C16F7307D042ULL, 
            0x867303849EBC871AULL, 0x92D8C3466BA7651EULL, 0x27D4C22349F29207ULL, 0xF5AF9AA385712C73ULL, 
            0x82B58EE084C749E3ULL, 0x7CC7216E0666EFB4ULL, 0x18649D32C815654AULL, 0xFF79C9A3B147F51AULL, 
            0x7483E1BB0DD02CDCULL, 0xCBC7C15D851CCD2DULL, 0xAFACA10AD777D5EDULL, 0x45EB73F5010EB16DULL, 
            0xFC464B1915BC8D5AULL, 0x87638395B5FCDC9DULL, 0x6CFE076F18B93C7DULL, 0xD1EB2D3F3423FF41ULL
        }
    },
    {
        {
            0x11B21724EDBF7AE8ULL, 0x3148E91399A74680ULL, 0xC9E885C3F670B70AULL, 0xAA2EE46C13B9EA8FULL, 
            0xDA9071C26CBE2F35ULL, 0x50B87D43EB840C6AULL, 0xAE3EAEABBF9748ADULL, 0xE25EC0C1E981DE2BULL, 
            0x94F6F5F43EFE9190ULL, 0x886ED2E1762834FCULL, 0xADDE7F1083BD46A9ULL, 0xDB04CE9718E61AD7ULL, 
            0x6FA66E18D109FB5CULL, 0x2F2500AF2C3B9AA9ULL, 0xE134EC37BCD07012ULL, 0x6F95D2DE1570298FULL, 
            0xB748738F09C5943CULL, 0xB1373036EEF3681CULL, 0xFE9F48F7D0F9960CULL, 0xE930133B025A3FE6ULL, 
            0x551EEE93226F7A00ULL, 0xF60E6707917EEDD8ULL, 0xA16CDCBDA9A6952CULL, 0x8A37D901E3224D34ULL, 
            0x4FC5530900F926BAULL, 0x70997530B121BD57ULL, 0x24282262A41AD99EULL, 0x8C911D3DEAFBD8CDULL, 
            0x6DE1FDA306B643D6ULL, 0x36819806E3E4167BULL, 0x2489D3D1B680F5E6ULL, 0xA4BC0D947D86D2D9ULL
        },
        {
            0x8A14CA5BD22185CAULL, 0x0622544C08F9F1F2ULL, 0x2C739ECE8D5F57C2ULL, 0x3D132EBDD1E5BA1CULL, 
            0x1115B99D9FA79F76ULL, 0x27CD19F5FB7455A3ULL, 0x18BCF8528457B028ULL, 0xA376CDA1D46CE8F2ULL, 
            0x2185D1F2A44A47B3ULL, 0xBEE1361131157E62ULL, 0x6CAA1167F4895A17ULL, 0x21E7C76B61E81BF6ULL, 
            0xC3B2243708857482ULL, 0x3BB854AA6E5F0F27ULL, 0x505B514D2DC0C68BULL, 0x9473A44E2A4FEE97ULL, 
            0x09FE4FD9F980F7E2ULL, 0x8F6B26400E5A1910ULL, 0x320E07C88BD5D2A3ULL, 0x05B817CA83ED1930ULL, 
            0x2C3D3DA53ACEAA2BULL, 0x7285F043E475FDBAULL, 0x5E2F5B692D7CF6A2ULL, 0x307E7C4976B06245ULL, 
            0xF0703FDD2BCF12F3ULL, 0xC6D9E118216D0666ULL, 0xF51910DD03F9FC01ULL, 0x4F41F1BBDD09B64BULL, 
            0x9A9B716846373E9AULL, 0x8A272A9D45DAA25BULL, 0x0484CB7804EF1BC7ULL, 0x3DFD499D8C7859C6ULL
        },
        {
            0x99D0A1C738A03987ULL, 0xA1B6207D7C7A0CECULL, 0x8BE33B5016233731ULL, 0xFCFE7D35274CC6F6ULL, 
            0x4C66ABE0A290484EULL, 0xECFFF35A9ACA75AFULL, 0x87BCF9A3739E4694ULL, 0xF4BDAEAC5F27DF96ULL, 
            0x1EA35DFAC78C5D4DULL, 0x065A863BC8D258C2ULL, 0x9EEB61E330F8791CULL, 0x7996AE6055D88A05ULL, 
            0x27FCC100308D23FDULL, 0xF55ACD427EA05748ULL, 0x7FB6EA7BDDD84BABULL, 0x46A79F55836DA781ULL, 
            0xA5A3D0898BA10A23ULL, 0x1B74B3ED0B0FAC45ULL, 0x21955B28822174B1ULL, 0x542512BAEF56EBECULL, 
            0x589C032C13149C32ULL, 0xC892625138F9F173ULL, 0xDC70E6EA4B4B8DF7ULL, 0xED86CF5654C102FEULL, 
            0xC8A156E2D87E13EFULL, 0xF3473DB7BFC1EC1CULL, 0x4AA0EE3EC083E30FULL, 0xA18AE4C6C6D26B4BULL, 
            0xFB5737ED59D283F4ULL, 0x3DA4C7108CFBCFE0ULL, 0x6EB579CB782D7F2CULL, 0x0483CA75C00CF440ULL
        },
        {
            0xE093CD0DF57AF1BDULL, 0xC0E016E28E887C26ULL, 0x0AFF9DD6EFD8FA51ULL, 0x2CA1AFC74B11191BULL, 
            0x0CC903B2256BAFB9ULL, 0x9883ED540CECEFADULL, 0x392F20597D80E034ULL, 0xD48876C422284920ULL, 
            0x4B99BCDCDDA857ECULL, 0x51A62DAAAAA0E48AULL, 0x750CC6EE6D4279B0ULL, 0xABE6CB19B3238B1FULL, 
            0xE779E16F755A02D7ULL, 0x66F4090868B55C04ULL, 0x7DDB85DABC72AAA7ULL, 0xC1434D3EA193AB1BULL, 
            0x10F1E35A6F2CC45BULL, 0x2B6B206C3AA234B5ULL, 0x5D8F26E6C6D5563AULL, 0x2236966AB6819D93ULL, 
            0x1356567F19EFB43AULL, 0xED3FD65BFC80F19AULL, 0x3F2EC053B8AD30B4ULL, 0x255113B5174AB395ULL, 
            0x6D09088DD30AB332ULL, 0xFAD63B076F21B61AULL, 0x5FA4E6B2016CDBD4ULL, 0x51A561CB8A871B95ULL, 
            0xE1553BD5B24FE431ULL, 0xC87CB575BA56910FULL, 0x528547D22BAB9D71ULL, 0xC69A6170877E7629ULL
        },
        {
            0xDBF277039DE7F8FEULL, 0x4A75578C15DF7BCAULL, 0x707BEF5CE8C6B226ULL, 0x55A18EAE8702A7CCULL, 
            0x8A387E3F0DFF4B64ULL, 0xB39B5218FE3FAFD0ULL, 0xC428DD668F057287ULL, 0x2FDBD595189E3690ULL, 
            0x09CA9A22C104FAFCULL, 0xD052016896932D54ULL, 0x668FCDCA1CDF14F6ULL, 0x2E1A35DAAFADC6C1ULL, 
            0x06E0F36DC7D2772AULL, 0x478DD30710CDCF78ULL, 0x5626435025BDEE0EULL, 0xE951EBD01073B502ULL, 
            0xF2A2AF77878CE18BULL, 0xB277F4F4F960B095ULL, 0xE62B8C4C321AC5BCULL, 0x8B359E4FFA55BB02ULL, 
            0xA7708AE7763EBE01ULL, 0xB5AB12027B553D22ULL, 0xD54387E8BDDF44D9ULL, 0xC6C2CF53E3AE77FAULL, 
            0x2972645831B97269ULL, 0xB0D2FEA34B0559DEULL, 0xCF9E0B37665311B2ULL, 0x98067FEB8CB41E96ULL, 
            0x1E17DAB7E4C363A6ULL, 0xAF9681A2DD27F35EULL, 0x21815B139FEB3045ULL, 0x913B4385C3D05093ULL
        },
        {
            0xE3A573C6073FB4C6ULL, 0x05E4151ADF3A8FB4ULL, 0xBCF2A404536C814BULL, 0x1839A77C068A4AE6ULL, 
            0x25E120B6AC6D88D4ULL, 0x48D0864254C91D32ULL, 0x02B4CD6C5EC6ECBDULL, 0x1A0D2EBB8EFF9362ULL, 
            0x705CFF3FA4E2BFD7ULL, 0x17324CC7B853A86BULL, 0x2DA3783B88A89739ULL, 0x0324B8527604C27BULL, 
            0xDCD2F63034D4E498ULL, 0xB753D80C2F91B6FEULL, 0xCB92B222111D2303ULL, 0xFE5E4354D03FEE60ULL, 
            0x750786A86D049A47ULL, 0x0F99E30E78A468D1ULL, 0x448CFC50BA0D173CULL, 0xED4CBE7F5CE841AFULL, 
            0x6EB42D521B13A925ULL, 0xA395017F71BEA22EULL, 0x1B1F8099C743C8A2ULL, 0x606BECC99ABFDE6AULL, 
            0x6F385ED593EE6F9BULL, 0xE5779A3C6FB45137ULL, 0xD76700E5D02B4F34ULL, 0x394FF0810A6B5372ULL, 
            0x1215206BECA9C117ULL, 0xBCE90F46ADD3A382ULL, 0x28A4567A73483735ULL, 0x0B29ED7FECED1C49ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseBConstants = {
    0x16804112AC9A6895ULL,
    0x4C8D08A958C2B3FBULL,
    0xCF941B1AB3A4E5BCULL,
    0x16804112AC9A6895ULL,
    0x4C8D08A958C2B3FBULL,
    0xCF941B1AB3A4E5BCULL,
    0x754839FB5649BAB6ULL,
    0x6180A534A933DF7EULL,
    0x0A,
    0x2A,
    0x30,
    0xEA,
    0x0F,
    0x87,
    0x9D,
    0x97
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseCSalts = {
    {
        {
            0x57F23AAA37C223D3ULL, 0xAE5C1DFE32340B6CULL, 0x70997BBE9A49813EULL, 0xFD8A2BA957F4DF77ULL, 
            0xDD3C61EABF9AF2F2ULL, 0x93371193115B2EAAULL, 0x4679FDA9A24D9F86ULL, 0x9EAD4FE73FE71242ULL, 
            0x54AD5E67A9C1A43DULL, 0x5864FE018C205BFEULL, 0x2EF87DC2D3A19F71ULL, 0xB30C96227010A9C5ULL, 
            0x111EC936B8DFA9C6ULL, 0xD437E90E73961774ULL, 0x38DC817847DDD134ULL, 0xB6C96F1540E6F5FDULL, 
            0xB37A72A07CA52116ULL, 0x6DFB2CCDB40159A5ULL, 0xE4FCEF399EF81FCAULL, 0xC43473DED5E03D96ULL, 
            0xFDDB95B49FBEAFA3ULL, 0x4F458BF967523462ULL, 0xB75542AB7102C74CULL, 0xF97DFC77D19E765EULL, 
            0x22069B7A7EB59433ULL, 0xD554C2A84EDEEF1FULL, 0xF1B0A862968E3B36ULL, 0xC01C0A3DDCDD6937ULL, 
            0xA277154F723EF43EULL, 0x60F33B53047CC5E7ULL, 0x60B0DAD9DFD93A15ULL, 0xA808BC3E1E597641ULL
        },
        {
            0x276F7C7657B431B0ULL, 0x02A8ECE793564562ULL, 0x9583B1ECFD63B7BAULL, 0x87087CFF6E05C966ULL, 
            0x9EA79EE4AE3750B7ULL, 0x02F67BD59399D41CULL, 0x63D955DA236D47A8ULL, 0x741E169E13EB11D1ULL, 
            0x3571452169FCCE7EULL, 0xCBB645BF07BAD6A3ULL, 0xCA57629F811D898FULL, 0xCE528E6D9A1C716FULL, 
            0x3FEE7802C928F32CULL, 0xC6FA8C412834AE82ULL, 0x0B42CE34F743AEECULL, 0xF0F1EB82428E794DULL, 
            0xFE29AC7A555D3845ULL, 0x21D19C1D450105A8ULL, 0x49EED0239088CC8CULL, 0x3D4A88F0EBEE18D7ULL, 
            0xA415BFE9261EA528ULL, 0x14136C600BCBE3D9ULL, 0x03EB05953067EA05ULL, 0x30A6CA21FF85419FULL, 
            0xB01B8ED292684833ULL, 0x719F0D89ADE08CF7ULL, 0x6F86F1399B66C4F4ULL, 0x0A1B0391F48EC4C3ULL, 
            0x3C1A86BA6FBC3E01ULL, 0x1585FE9E28A25516ULL, 0x37008640B0FDABECULL, 0xA883C244EFB0DB2CULL
        },
        {
            0x0596F4E202254AE1ULL, 0x331CBC92751B5F06ULL, 0xA00322C583E7B322ULL, 0x0789ACA02E87A8E5ULL, 
            0x7B1963D34A87B170ULL, 0xCBFE5BBAC86A6473ULL, 0xA7270BAADAEEE3D2ULL, 0x8020A9F33B7C9654ULL, 
            0xBDC73636F664F0D3ULL, 0xDCBFA96AEF1CF61BULL, 0xBA86CEAA60D64AE8ULL, 0xDEB3225F4DF4FAAEULL, 
            0x9B29A75EB12604DCULL, 0x011197094BD5BF92ULL, 0xC87ED5AA8973ED59ULL, 0xC44ED80B869365A2ULL, 
            0xFAC37F4FC1130C8DULL, 0x6739E1DBF6AEA3FBULL, 0xE2FA4AF5899815ABULL, 0x0FDDBE9A020F4A2EULL, 
            0xFCED15348EC88884ULL, 0x9A5150F743FA5A5DULL, 0x8FA1C7A041D5AC34ULL, 0x6B45FA6E249DF3C8ULL, 
            0x95DCF720F1C7E496ULL, 0x93297CFCECB28DC8ULL, 0x7E996415D0529E69ULL, 0x0D1DBF2218D7864DULL, 
            0x44D83EAAF861BBD1ULL, 0x235B428C6381ADF1ULL, 0xB3E35D7EAB67274CULL, 0xE6DE422B4D2994E7ULL
        },
        {
            0x942543F9707E2250ULL, 0x1A6C6CE85BA20C91ULL, 0x7004BB5873F7A149ULL, 0xD3C99629F5AE5A45ULL, 
            0xC01CA80A02032C3DULL, 0x0854F4C3F49A499EULL, 0x7B1D49AB8B934011ULL, 0xE96DF5668CB7C71DULL, 
            0x42953A966B5E0069ULL, 0xD32F168915603380ULL, 0xD267C504CDDB6236ULL, 0x125C93FC99ECCBD2ULL, 
            0x7DD02FCFE7B20F69ULL, 0x94AAD8E2E82DD00FULL, 0xB44735BB838D3678ULL, 0x76BB40D9C2A6AFB5ULL, 
            0x2BB5476D0A52C9A4ULL, 0x9E64632014D7F653ULL, 0xF03965086E36C60EULL, 0x5276905478A4F6EEULL, 
            0x01C271F27144D38CULL, 0x3995E8EEA680B273ULL, 0xFF9980C33A4FF1D4ULL, 0x6B04ABEBA981D7AEULL, 
            0x7D0E2691F61AD049ULL, 0xD1681119403A9C08ULL, 0x0855F22CF3AE0339ULL, 0x3B830D3ED422A9B6ULL, 
            0x3B3016EF7077809FULL, 0x8E5BDA64CB4B6F37ULL, 0xA5A24D5AFA385652ULL, 0x57D0D14DE9C8D2D1ULL
        },
        {
            0x9693B47BE933E04FULL, 0x9FE13DE4B426EE3CULL, 0x82EA901C21BA05FCULL, 0x4C9FFE008D9A9ABAULL, 
            0x68C278E863E1F0B3ULL, 0x5D76B3115156E8EAULL, 0x46FD459A0533CF5BULL, 0x1962E8E401435F7BULL, 
            0x7D26C79698141434ULL, 0x0D0106CFB44FF034ULL, 0xB65023B9C049067AULL, 0x218369CDABD219E0ULL, 
            0xA0337A332415C8BAULL, 0x6370F8E6DA181C50ULL, 0x2AD7D66C3953C6BFULL, 0x305D311CEB89DE3DULL, 
            0xEC789864AE0E485CULL, 0xF3996E15FBE22C61ULL, 0xC2372EBEE3D56629ULL, 0xC6CEA1A3BF82AFE9ULL, 
            0x5F020B8A030918CDULL, 0x25C97DC04EC69F12ULL, 0x2F8C5A74A3490F6EULL, 0x1CA3D55C26A9B268ULL, 
            0x3E5D21EAB2AFE24BULL, 0x203D3C08BE1BEB32ULL, 0xB18F39B2CDA9F43DULL, 0x202DCFF848C6FB03ULL, 
            0x3E825D8BB9EDA026ULL, 0x48DD3D0774BEEE68ULL, 0x2E6C69C0DF726D5BULL, 0x40C2F1D9BF17F909ULL
        },
        {
            0x6731CE3BBC72EE98ULL, 0xB25BA5DADE4F2B10ULL, 0xA6C91B25892E7B07ULL, 0xBB3065F2DD68ADC2ULL, 
            0x2F93B1326F6A1F2BULL, 0xAB7E7C79F00FCD74ULL, 0x17AF9C1C350AE359ULL, 0x447ABB76C93D8C56ULL, 
            0xC6A9B1F621CD2217ULL, 0x22FC3FCEF66B29A4ULL, 0xA4BEB09EE5C7FE94ULL, 0x020BA4B3DE70D6E1ULL, 
            0x1CC0A60A721DA1A3ULL, 0xD392473BDD3A737BULL, 0x2470A9029121B29DULL, 0x9229A91724DA3E53ULL, 
            0x6A96B53F48868C28ULL, 0x502427314CCA9E10ULL, 0x5C0486DEC09A50F4ULL, 0x393284396461B784ULL, 
            0x5EE24DB5973B75F0ULL, 0x0AB235A5FC611692ULL, 0x8133B4C5E7162C3FULL, 0xC1C0EBA279EA18F0ULL, 
            0x5420065C48BFB0D3ULL, 0x475CB0A921FDFDE0ULL, 0x773E4C65A2558AE3ULL, 0x9E4FE2DA736FCCBFULL, 
            0xFA7CB5A61EAE82AEULL, 0xB167A741085465B3ULL, 0x158048E7C1DF1E90ULL, 0xE7CCBD10449982D8ULL
        }
    },
    {
        {
            0x5977243CD9F98F57ULL, 0xD6F2A5068BF473C9ULL, 0xA97ED685451B49BCULL, 0x16D006321DDECB99ULL, 
            0x416883665B458ECCULL, 0xD1EFE5BA7B492E3EULL, 0x3F2899BA29C99BB7ULL, 0xB94BBF81B67014DFULL, 
            0xBF6F2D1ABEAAA7F0ULL, 0x55A403F77976CD32ULL, 0x6F48BDEB1DC70ECDULL, 0x7270ABC737646F18ULL, 
            0x2263181023A32D94ULL, 0x45B46A77D7796B84ULL, 0x0ED07A1E43955113ULL, 0x7F1D5C6C3B0DA428ULL, 
            0x09BB9C60D8478712ULL, 0xF2EBC017E7F9B717ULL, 0x0FA680B408618541ULL, 0xFABD7BEBAB2B418FULL, 
            0x069D699018659851ULL, 0x2D5FC5E3DA50AF62ULL, 0x293D5FBEEF931478ULL, 0x515C9F19FD0D1E14ULL, 
            0x266DB28D2539E516ULL, 0xA9698BF03B031C2CULL, 0xDE0F6F11E588C638ULL, 0xC71C69E71DF8B506ULL, 
            0x8A9C15D75FA13556ULL, 0x3B707411E109F2C9ULL, 0x02A2AB36AA5304FFULL, 0x33923E4FFB8807D3ULL
        },
        {
            0xC99A939FAE0B46E9ULL, 0x0B2C1D15C4502861ULL, 0x61A49C2BABBE6C23ULL, 0x6451951206A4CF1EULL, 
            0x958FB2C7FC106E0FULL, 0x1FBBE0BB303A28F4ULL, 0x24F7ADEB2FAB4D06ULL, 0x8CAF8CAC3DAD722BULL, 
            0xE7C361D5B37A0DA0ULL, 0xFAE0A0D4FAB8B742ULL, 0xCB0BDA5CA61A00BBULL, 0x3BFC9388713D4240ULL, 
            0x8A528576D45DC27FULL, 0xDE77E7FAB7BF04BEULL, 0x3F498AEC3BAF7B0DULL, 0x35591C7A44AA51A4ULL, 
            0xEA2AE13B56773CB3ULL, 0x9ABC47F6FF90C558ULL, 0x25E6888B0E717CB0ULL, 0x94D76DD73622450BULL, 
            0x1710361BD7A52A11ULL, 0xE01FEC3B2635903FULL, 0x5AFE1BF880ECB090ULL, 0x5CCC8B1BBA20165BULL, 
            0x09A53C591E77CB89ULL, 0x2191EDAB555C0611ULL, 0x2105000D3A0D9B7DULL, 0x0CC38292FD580624ULL, 
            0x8DFA605BB7460391ULL, 0x6203982B45234E83ULL, 0x2CF5D55F5C9DB2E9ULL, 0x0A1F5DFDFACFFB3DULL
        },
        {
            0x8762727C323F33D3ULL, 0x0A7297DE328DAB64ULL, 0x9987CFA6D608CB11ULL, 0x8C2FDE18B4CC928EULL, 
            0x4A1F26CF48B509ABULL, 0x00C973E532754F48ULL, 0x6EB74B70424B05FFULL, 0x0D4E94B65C341F83ULL, 
            0x62D9DAFEE2DDDDCEULL, 0xB73FD132C9DAE245ULL, 0xF58349AF5E69425FULL, 0x126951A9C9829737ULL, 
            0xC428BAF2857A8306ULL, 0xF96B74A039F19157ULL, 0xE1FE1754C2DBEE6AULL, 0x9CE7F2B6CDDA2369ULL, 
            0xF9D9CBF5624A5E3AULL, 0x14F08896BD4D8039ULL, 0x88A88EF82888A415ULL, 0x1D55152D070FDE27ULL, 
            0x366DF0BFE862A7FCULL, 0x4E2F9B6FC6710A0DULL, 0x8043D64E474B9EDFULL, 0x83ADE55AE11E9019ULL, 
            0xAD4C19A32FF2DF67ULL, 0xEAC675B5965B2887ULL, 0xD33DDF51F4C8A7D2ULL, 0x42BD321686C53D6CULL, 
            0x4B5A1F589DD58EABULL, 0x58B8CFFF7794897FULL, 0x22384E594D4AB4F7ULL, 0x496639C6BA78A9E8ULL
        },
        {
            0x47AD916540EF06A0ULL, 0x281558EDA0F7A738ULL, 0x45BC691BCE088C09ULL, 0xCBB6EE462A7BFF5FULL, 
            0x7CC12891B3BDC3FAULL, 0xD94E57AEEA8C42CCULL, 0x22A652A6EA19465BULL, 0xF2624D967EE2255DULL, 
            0xB56E00D4CC3B95C4ULL, 0x0EE3C29F5FE76F59ULL, 0xD8D2ED99307D921EULL, 0x853869766BAC1EAAULL, 
            0x44FAA13DAB5B1398ULL, 0x1D589299F530E912ULL, 0x5176DCA18A48E68BULL, 0xC15902833B71A669ULL, 
            0x175EA1CB8BC031F2ULL, 0x7D61EC4E3880707BULL, 0x78FD170278A767A9ULL, 0xF00CCD9AEC0ED4ADULL, 
            0x599478DCEFA81F2FULL, 0x381396A4C56873FAULL, 0xF1430E8B5E0C9642ULL, 0x2941185D2B19DA99ULL, 
            0xB20602AE9865CD4EULL, 0x0B6F0C8A988B45E2ULL, 0x3B29C7D0AA690E4CULL, 0x44A479FB99BB7901ULL, 
            0xF4AC7EDA956A4608ULL, 0x0DC16380044FCFC7ULL, 0x420FDC2FAFF4B5FEULL, 0x7CE7F1852F9F5F7DULL
        },
        {
            0x3E48A5C6158DE7FBULL, 0x7336F2E264DEBF83ULL, 0x15E2DC1886C27A94ULL, 0xD052ABB190BF2B2AULL, 
            0x7E75815E083BB706ULL, 0x1C9EB8000055B8A6ULL, 0x3A68AC0A3915F120ULL, 0x1CFAF7C028179AC8ULL, 
            0xDD678A7142EC881BULL, 0x3CF234B613E1864EULL, 0x02B315CD10852FA1ULL, 0xF025CFA7217B2AC1ULL, 
            0x3B2D9BEC013E048FULL, 0xB9D239FC452EE971ULL, 0x5636DF22E29B2EC4ULL, 0xEFD80631536085A5ULL, 
            0x9ADA9C6FDDA0B427ULL, 0xBD4AAFE3EA35CEDDULL, 0x274ADD9B9098D5C0ULL, 0xDBE4A77F9A96E4D7ULL, 
            0xFB6BB2E4A9FA4E16ULL, 0xD110497C91DACB0CULL, 0xD6AA36D670D725A4ULL, 0x570FD6CC92093179ULL, 
            0xFA3E8BED0F3297C0ULL, 0x65064A6479B363F0ULL, 0x9FD44FEA9B634D10ULL, 0xDC4E6E1F683E1B8FULL, 
            0xBF055763984C5C2EULL, 0xF9A690E6B0B9707DULL, 0xA939ECA93E969E7BULL, 0xF9334F308C3DA5ABULL
        },
        {
            0xC85B423E94B8F40CULL, 0x53FB04B63B09AD8DULL, 0xEC0119F3EB868A57ULL, 0xCFC2A5CB5D02D781ULL, 
            0x48CF61B41DBBB676ULL, 0xCBBDDC13CCF46B6DULL, 0xF0F034B5DD785848ULL, 0xA4357B5DA7578B9EULL, 
            0x27169C59E2C2A2FDULL, 0x9BD0CFAB439DA8B6ULL, 0x609F680517B85D75ULL, 0x701A2D381FA45243ULL, 
            0xD0DA0F4FDFCBEE62ULL, 0xE3463B1189E90AFFULL, 0xF72DAC5CF5CF2C56ULL, 0x2C85BFA4AD89D0A3ULL, 
            0x8313B8EB680E2614ULL, 0x229FD24FB03CB0C6ULL, 0x7A0737C57F76FFA1ULL, 0xD66C1652128E6E3AULL, 
            0x242645FDA84A030DULL, 0x23CBD1529B9BCDEEULL, 0x64F021AB235B708EULL, 0x212E655642D75670ULL, 
            0x07B23E390222DE99ULL, 0x0ECF9CAD65955225ULL, 0x634D3B30D35199A1ULL, 0x7E5AE99C7E2B6159ULL, 
            0x550B32319CF6C196ULL, 0x195D492C6DF95541ULL, 0x0FFA5E24AC598881ULL, 0x07A258379B854AD9ULL
        }
    },
    {
        {
            0x9ED588AF64E19DF2ULL, 0x5638A309DBA47CE2ULL, 0xF983ABD14AAB0F22ULL, 0xEE264E2B6901A27CULL, 
            0x0195CF10254FFA2DULL, 0xEEAA619BDF3C94B3ULL, 0xE62080D643DB6269ULL, 0xB3A5B4EFBFA667E9ULL, 
            0x34CC82196BF84BB1ULL, 0x37E45D97BDF42F58ULL, 0x88556E2B741D7205ULL, 0x1E4C9C1C7C37ED77ULL, 
            0x6BCB19DCF958488AULL, 0x0177D4E05B8FCB1DULL, 0x4FED6CB6006826E5ULL, 0x2D8E1D5986584EABULL, 
            0xC2C2E72871C9A6D6ULL, 0x9F949209CEA05C00ULL, 0xE5935D84A360CF19ULL, 0x249D1BF4A62A199BULL, 
            0xD7D4F232C06D1BE0ULL, 0x725BC868A3E81189ULL, 0x3666C064749789E6ULL, 0x85B41590C0D25A19ULL, 
            0x715B01D5904DA37AULL, 0x936124AE7C01E364ULL, 0x763D926302E9BF9FULL, 0xCC7DBC2758F1D2ABULL, 
            0x4CAF9BBC9E04EADBULL, 0xAD9EB6CA91BD80E1ULL, 0x29EA9A2AAAE673A3ULL, 0x2DB6F6A0940F34A2ULL
        },
        {
            0x869856F564BFB923ULL, 0xBDCAE65C552F7A61ULL, 0xA377C708AAD3C940ULL, 0xC870DD602CA3EB40ULL, 
            0x5D66F4BA984286DAULL, 0x67E782EE5B762104ULL, 0xED208B8F11430129ULL, 0x439BEEB2EF230B7DULL, 
            0xC2ACFF16B178B777ULL, 0x973D3966419438F6ULL, 0x199D1FD352FE88BAULL, 0xE9FBC2ACA86EC5DBULL, 
            0xCA1E8B347C5931CAULL, 0x8063FFE2233C712DULL, 0x25E4FDB70F2CD897ULL, 0xBD024DB065E552D7ULL, 
            0x98426EABDAB6CAE5ULL, 0x6E51AB3409054638ULL, 0xFA93DE00293E3243ULL, 0x97C5833FBC9DE45AULL, 
            0x4136322AF4614A90ULL, 0xC3BD17B2448FCB7AULL, 0x0A122E2DAB71EFCEULL, 0xE980C0F1B6024D44ULL, 
            0xEC2E92FD2661382FULL, 0xAB75CCB70C7977E4ULL, 0x7EC48EE9959581C8ULL, 0xC999A17FED394C39ULL, 
            0xC5A9C5794C0E2EB5ULL, 0x6C374BE6231494BCULL, 0x8A4AB96C22429BA1ULL, 0x33434E729B714B6FULL
        },
        {
            0x397FC503884EC139ULL, 0x65F1EB307E1665BCULL, 0xED17FA1E1258E377ULL, 0xC00C625536EF8453ULL, 
            0x14CC5A169605E9E5ULL, 0xD3F48E11985D17A1ULL, 0xEFA14A8907F41776ULL, 0xE0B19B8FB0BEECBDULL, 
            0xFDD63400688D18EFULL, 0x5E28BF537F3D04B0ULL, 0x6E5626D8FA7E8FCAULL, 0xC9876A82C8FB5792ULL, 
            0x43A58ECE5AE2D113ULL, 0xEA1820292595BE23ULL, 0xE274674115DC0300ULL, 0xBF900877A2C19705ULL, 
            0x9E74EE6CF99CF12FULL, 0x6BDCE4F1169B2CB4ULL, 0x2F65C94910078805ULL, 0x748A9D50DF305C53ULL, 
            0x883BECD7EC498AAEULL, 0xAED8B2FA92562C33ULL, 0xE18A97C2554D762FULL, 0xB489D5CF89441886ULL, 
            0x4F94D778F14449B8ULL, 0x1DDF9CB4CCE448B6ULL, 0x6BED431C24D54914ULL, 0x192D30D2D184F3EFULL, 
            0x1FFEF9C2D86245D2ULL, 0x9290527FB5438F70ULL, 0xDAF5CAA9A3794458ULL, 0xC5CA89F6DBDA96E7ULL
        },
        {
            0xEEC64D3103045AEFULL, 0x76EBDF432F950133ULL, 0xAC05EA64FBD504E9ULL, 0x9EDF076A4CF409F9ULL, 
            0x47D86528C7C9065CULL, 0x0F11662A4073CB07ULL, 0xCFF307FCCA28F612ULL, 0x696338794B5D1AE0ULL, 
            0x90E2D7FFD58E265CULL, 0x3E1828F2BAA74EBCULL, 0xB8AE3BF63F13AB0BULL, 0x8EAC7977676067EFULL, 
            0xC20DFA94E3A76B3CULL, 0xC061112827321AB5ULL, 0xFCDA04B97FFF1B72ULL, 0x6FBF9CFB39A74B3FULL, 
            0xF57C93951098BC9EULL, 0x07F01FC9227A7756ULL, 0x56042AEED649DDF3ULL, 0xE56391A9DD3EC35CULL, 
            0xAEF06710E9457B4DULL, 0x5787E635A8F2D3BBULL, 0x18A7C6ED9CDE64A5ULL, 0x6B9B52BCDCD5E6D8ULL, 
            0x8C74E71A40F7C325ULL, 0x0A9CB56E2FEACC62ULL, 0xB5835776A5CFBFD5ULL, 0xC05B4A21689F62BFULL, 
            0x71E42F282F4556E3ULL, 0x70A880349D2F636FULL, 0x0C612D7D5DDFE699ULL, 0x9F3E7DDEB05E4036ULL
        },
        {
            0x867D7F7FA1224C02ULL, 0xCA753D6F2FAAD880ULL, 0xA1AF605C11715E9AULL, 0x54263C2B64DD8522ULL, 
            0x7D77134660D33D07ULL, 0x1EA8498B38BAEE6EULL, 0xA31DAB80EC759923ULL, 0x82ED56BD3E5CBD7DULL, 
            0xFC61DA5FCE509B6EULL, 0x71A542A943E4F692ULL, 0x8B7E36F5DA97115DULL, 0x0EF347C5F840C925ULL, 
            0xCA9396A2371CFFBCULL, 0x3582D714429B9D81ULL, 0xBBBEE2D36CB0E550ULL, 0xC022D621F8853CCEULL, 
            0x98F2BCF3E7F84C28ULL, 0x449E4AD8EFE1F805ULL, 0x413FC2FD22C8C906ULL, 0x87B93C56F30FD0A8ULL, 
            0x0A2AF5A44ECBB90EULL, 0x196306BA8F84D367ULL, 0xE4D93D4D1EE93CF5ULL, 0xBF5A8CCB22B63E10ULL, 
            0x03E077BD70AC6CADULL, 0x92E10E55743EF652ULL, 0x4EF3F9B635255742ULL, 0xF3B402E282645CDCULL, 
            0x71CDA2DBA0383F64ULL, 0xD646B54DAE48F5B6ULL, 0xAFDD9E4B2B62BD90ULL, 0xCD59AF26463A3532ULL
        },
        {
            0xB3AAA50BA32E50CFULL, 0xED8379CBB4A06C01ULL, 0xC75ADF61AF946A77ULL, 0x702EC432EE88432CULL, 
            0xAD509B815C48CDD6ULL, 0xD52CCA88593A0A55ULL, 0x76811609741217A7ULL, 0x50E6751140FFEEDCULL, 
            0xF06C11A044536090ULL, 0x43F23718547FBD8FULL, 0xFFBDA3A69642F0BBULL, 0xF59B1953B032A401ULL, 
            0xF8A1D580A469A34DULL, 0x95B7EDCD74EC0C83ULL, 0xB3C41457AC5DA9FCULL, 0x352BF270DA69D140ULL, 
            0xE8D0D5665E9B2860ULL, 0x19EB3D1E475525E0ULL, 0x5554D05FA52CDA68ULL, 0x6FDC9E1531FDA600ULL, 
            0xFD2A8E78423E099FULL, 0xB8DC8B5FE9A6457FULL, 0xAD270CD2077BC155ULL, 0xEC64D8FF74146A0FULL, 
            0x80C62C36F51D5233ULL, 0x7BD80D7ED20DCD81ULL, 0x86FBD0D309C7FA41ULL, 0xDC96DD6D38A91C13ULL, 
            0xC7E08DD06AD0D751ULL, 0x30688C6877D6C5F9ULL, 0x3C20559F916BE5DEULL, 0x5AFDD6AC78EE1473ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseCConstants = {
    0xAD1F949E05DF13D8ULL,
    0x3763A239EDE8EB12ULL,
    0x3DEAB1056F643368ULL,
    0xAD1F949E05DF13D8ULL,
    0x3763A239EDE8EB12ULL,
    0x3DEAB1056F643368ULL,
    0x5C101157553B878DULL,
    0x951BF8212E937191ULL,
    0x6D,
    0x17,
    0x4C,
    0xAF,
    0xA1,
    0x16,
    0xDE,
    0xEC
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseDSalts = {
    {
        {
            0x09010F033AC99CE0ULL, 0xC81D76CE8DFC6AEAULL, 0xB41500F3AD48E858ULL, 0xD8AAC0CD1E2D6700ULL, 
            0x40979FB7C388B75AULL, 0x4D011AA99A5DD837ULL, 0x55C31AC6253B4ACEULL, 0x4E4E0451AC0CCD0DULL, 
            0x07F9CF099ABFA4E4ULL, 0xE2E4EAA5184EC6A2ULL, 0xAA1A9D805C5328B1ULL, 0xE700C1E016D857DCULL, 
            0xC511FDFB85AE48E2ULL, 0x2771021798BA717EULL, 0x016C67A990B946F9ULL, 0x4B29234F486D46C8ULL, 
            0xDD9B8FE34543B3FBULL, 0x8554EED614CE817BULL, 0xB1FC3FE674877721ULL, 0xF4C9B428797BEB01ULL, 
            0x1FCF9A9ED77CD23CULL, 0x1E68A179F40BEB0FULL, 0x44344F18023833BAULL, 0xE2A540C99AF667A6ULL, 
            0x6AF46C1DE1307B23ULL, 0x306F3F4ED8F1BFA0ULL, 0xA37E28ADBE4923C8ULL, 0xC1A9643A69888485ULL, 
            0x8961DEB3B1D08571ULL, 0x8022932BCC0E70DDULL, 0xDAEF988134AEEA72ULL, 0x480135D87CFD240DULL
        },
        {
            0xAFC784A7E974FF6EULL, 0x1CF398E05941B117ULL, 0x89DCC282DA5E069FULL, 0xDC5A0B3B1C2D4C6DULL, 
            0x8A74B393C06683A5ULL, 0xFA6CA2AC98B8A07CULL, 0xC8DB651DBFD0CAA6ULL, 0x2C0591C1AE39D714ULL, 
            0xD618750A1821E231ULL, 0x42F36B211FF39C22ULL, 0xFA02EF585A6DED11ULL, 0x5C8DCC0D8FF37948ULL, 
            0x9439808AE4B762F1ULL, 0x51FFB373DF5F2890ULL, 0x14DD408B4B8632B7ULL, 0x3416439DF3C90EBCULL, 
            0x1047DFF845AD27D9ULL, 0xB988E327A3C57C89ULL, 0xB75EF2E363A53B56ULL, 0x59F37DF0D06C3016ULL, 
            0x4FBD558DCC2DF92DULL, 0x98A9DD67AC936AC2ULL, 0x2DD01FA47D694278ULL, 0x6769AE7374BC8AB6ULL, 
            0xD522E12AF1D61A0EULL, 0x296BA741D5C78DA5ULL, 0xB69748BEF20C33F4ULL, 0x09B018CD142BE726ULL, 
            0x2520AA3064F9E9EBULL, 0xC9BBD09EF0950B9DULL, 0x35EBB1C2A4A15816ULL, 0x9A3C212A6810676AULL
        },
        {
            0x9363150A3926D63AULL, 0xBD7C017D6470EE19ULL, 0x26861C63CDD70BADULL, 0x55FD52C17AD74DA0ULL, 
            0x20BDCD2759CAD272ULL, 0xBC5D6B7E9840699CULL, 0xFF617BBFFFE41358ULL, 0x872DB2DF2239D7E4ULL, 
            0x36C6A2BDF76957BEULL, 0x6EE0AA45650818A7ULL, 0x7F545F41F20DD0E2ULL, 0xCDC5D3195207C6C6ULL, 
            0x2B51BB2BDE7B8938ULL, 0x1F00A60D8B7A195DULL, 0xC43D5AF688BB56BCULL, 0x97E9C584FAAF40D9ULL, 
            0x770D1FFB2C7A9AEBULL, 0xC5A2D17412DEC703ULL, 0x8015F18BF8441068ULL, 0x4E1624544B3671D3ULL, 
            0xECC880489F54ADCCULL, 0x9A8A8928D79BAB52ULL, 0xC70F067E433CF383ULL, 0xD684848752261F5CULL, 
            0xB3A5BD54791E94C6ULL, 0xF6BA948F3654C184ULL, 0xC1642E6D932DAEF5ULL, 0xC33201F0F0A6433FULL, 
            0x3C63C5150728C393ULL, 0x466847643D449F1DULL, 0x47C2F75210C54197ULL, 0x4A80C641495EBA97ULL
        },
        {
            0xF41B7D12C5475CBAULL, 0x7E34C1D0CC6F48B3ULL, 0x1D78ACD2E7E06A87ULL, 0x2E553279B904C8A8ULL, 
            0xD00DB3E4D8174AF8ULL, 0xE57B52E354201843ULL, 0x503B111C7C656148ULL, 0xEE6297635846B256ULL, 
            0x051F6CD6E7C86A11ULL, 0xC8E9BAA7C522DA67ULL, 0x35B31AEFF47CA534ULL, 0x436837E2A02936C1ULL, 
            0xADE75CE5D18117CDULL, 0x22DF4A4B868BCBE1ULL, 0x8F21995B87CF2AC8ULL, 0x4C6BAF23C2B37254ULL, 
            0xC1254A13CB3F3E33ULL, 0x637E0EDBA8D3FD4DULL, 0x0127706D9B5B7190ULL, 0xC11E96E5AF263073ULL, 
            0x655B04E2E516AA3EULL, 0x29DEF489C6BA96BDULL, 0x9C2F5C8E3E384822ULL, 0x1774FF65F4B322FAULL, 
            0x081E12E34127BD02ULL, 0xDA4B5B69522FD06DULL, 0x3465AEDF4BBDF4BAULL, 0x44B0522ECE61A1E3ULL, 
            0x6ABA40A1C1C13EA7ULL, 0x4A2410BDD2E6B67EULL, 0x1E33E921ED47C4F7ULL, 0x3F51EC8C5A983EBDULL
        },
        {
            0x275C20661F7B0422ULL, 0x83783EEAE78E3029ULL, 0x86DC04223FE80CFEULL, 0xE731405B122149E6ULL, 
            0xCFB34E329E7EDEBBULL, 0x6225F470189145DCULL, 0xED15C065D3C23CE4ULL, 0x5580609BCE1AE91BULL, 
            0x3E0B77FDC5227DB5ULL, 0x69F402F4E36FA08FULL, 0x75DA19237AFF8EDBULL, 0x5EF6335F791508C3ULL, 
            0xB001408BC7D0E22FULL, 0x49CA3C07A910B666ULL, 0xCA36A4856020F535ULL, 0x8B638C20D3A92E97ULL, 
            0x872AD4AC03C61F4EULL, 0xBEDF4B7E6E320E92ULL, 0x404EFA342772F0B9ULL, 0xAE40F16D4B64B3D3ULL, 
            0xD1C7C95AFE46FA36ULL, 0x4C55C9885B4E227CULL, 0x2588FB7B88755EE0ULL, 0xDEE69DA2813ADDB7ULL, 
            0xC6D94E5043759B25ULL, 0xBA8AFBF123FF7B63ULL, 0x6BFA182171E5C566ULL, 0xEED9EA9C95434C24ULL, 
            0x40AAED3D52E9163FULL, 0x982A0EA0E32673F5ULL, 0xAE9EF9626B5AC740ULL, 0x298700E1CB0A63CEULL
        },
        {
            0x92C3FFB0A42364C3ULL, 0xF1DCF00A3960EDA7ULL, 0xED05D2009B9EEDAEULL, 0x499D62DC0E73A7C7ULL, 
            0xB118A96C92E41706ULL, 0xE6217065802BCE08ULL, 0x25DC6D164F9498C1ULL, 0x5656B613391856FFULL, 
            0x3D8BA3A2107E7CBFULL, 0x6773341B66D80BB0ULL, 0x92A69D9A7F3F0F2FULL, 0xAF6DAA625A0907AAULL, 
            0xC67B918DF1386445ULL, 0x5FFEB1B96122ED7AULL, 0xA02D053B9B697C1AULL, 0x278D78191461A539ULL, 
            0xADBB9816C433CB24ULL, 0xD916DFE9C9088BE2ULL, 0x8308748B642EA7F2ULL, 0x37B54457C2445B4FULL, 
            0xAC032B5219B487B3ULL, 0x4889023ABF79127FULL, 0x4F5DAB83611B9034ULL, 0xD47DA0AF85732EAAULL, 
            0x140ADB0B6972F4FBULL, 0x37847C8F7D3B65D8ULL, 0xB3188F9035EA2AD9ULL, 0xDCD182AFB2512297ULL, 
            0x9614D30A1D926816ULL, 0xFFDD79EB361AC253ULL, 0x048661E2CC3DECCCULL, 0x82A08DB85815FBCCULL
        }
    },
    {
        {
            0xB8481168B96B694CULL, 0x9BFC08C9FA7900C4ULL, 0x9919860D33B872B1ULL, 0x5977442AD4F01D50ULL, 
            0x7F6839396989B0A4ULL, 0x85E69A0B3E7C5357ULL, 0x3BCB22D9A0C84E35ULL, 0xF63409A50147E2C2ULL, 
            0x530781DFF62F70B0ULL, 0x4B51C14BE5623761ULL, 0xA9AF25D9D538E010ULL, 0x5D465591E89BD6EAULL, 
            0x75AF27BFE32F17FCULL, 0x6F306AECE34D4127ULL, 0xC566544036214879ULL, 0x9A34964928A663B4ULL, 
            0x2C097FA4DD82F073ULL, 0x880753FD1121F286ULL, 0x511BD6C31BFFAC63ULL, 0x87F9D27BAC4E64D2ULL, 
            0x3B28080538DE2281ULL, 0xB703C12759836B09ULL, 0x2597E18A25554A7BULL, 0xFABD4EFFB8C6552FULL, 
            0x345BA329F09041B6ULL, 0xC2A91920EDDA39CCULL, 0x5C38E4300EB9552CULL, 0xE613F706C98EB01FULL, 
            0xB098DDBD38623786ULL, 0x738727AE8BA474CBULL, 0x426247DF8112A626ULL, 0x7E7803DC8F94D213ULL
        },
        {
            0x7367638F255597C1ULL, 0xA017405F086BA49DULL, 0x37F576746011CE36ULL, 0xC7C61C64C47D8F86ULL, 
            0x5EB590DCE0124696ULL, 0xD6B0A9F36AEA5A74ULL, 0x40C465927DBEBFF4ULL, 0xB57017D82E34940FULL, 
            0xB50BD28232935C0CULL, 0x116483AE2E41F14AULL, 0xC36968456D80CDE7ULL, 0x5A4E02AF8D736432ULL, 
            0x68234F2EF3F7061AULL, 0x92A67EC081765CD2ULL, 0x68BAEBAB49E06B4FULL, 0xD31124665015CC14ULL, 
            0x38F6D9F7A041721CULL, 0x328939B93A6485C9ULL, 0x5385FF7D49400411ULL, 0x9EED4AEF4B4EBCAAULL, 
            0x9C8F9A4527024869ULL, 0xDB1E9919DA4D6CDBULL, 0x373915F8771F1A4DULL, 0x934F78A1970CD03CULL, 
            0x911B3EF70F6ED855ULL, 0xF3D3DA552F11F416ULL, 0x388735B1BE52400CULL, 0x2890FA4599FBCC6DULL, 
            0xA33267AC92EA65D7ULL, 0x3761D3B9642BAFFEULL, 0xE37549CE177DC937ULL, 0xB4AF131A2F5B5486ULL
        },
        {
            0xCCCF2AB3DB8F654BULL, 0xDD9932B751980F59ULL, 0xDA960087187581D2ULL, 0x16E223CF924F3CC6ULL, 
            0x2401689808381A80ULL, 0x757D1EDA8F55DCF7ULL, 0x5C164B449251CB1EULL, 0x87111F482DB11A02ULL, 
            0x41B6E41C6C3DDF1FULL, 0x223EC58562808ABAULL, 0xDF0E9C95CA8AB73EULL, 0xCC6EE5D1CFE2CD6FULL, 
            0xA35016B4F371CBDBULL, 0x7B3AB8EB25A21310ULL, 0x16D82FBD7DC3DDAEULL, 0xB9939EC341742A83ULL, 
            0xA3BA024E4438389CULL, 0x0932D018F3F80F9AULL, 0xCE4208148BFFC087ULL, 0xE2B321A7F98253E9ULL, 
            0x15420EEAB460E791ULL, 0x8E9A01C8D66CD57CULL, 0xDCF8271D94C6A5FCULL, 0x8C52D1DBB1DBCF0CULL, 
            0x9C28F22C5E9F2E87ULL, 0x8B08351E1ED3D8FCULL, 0xCCC5FD157BF63F9EULL, 0x43871E7C63E3C27EULL, 
            0x62E9FDC387015652ULL, 0x2C5E95A088FF23E6ULL, 0x8C67BE33DE8B7E9BULL, 0xB992F842CFFE9891ULL
        },
        {
            0xFFBEF6DCD368F932ULL, 0x61961580052BF80DULL, 0xF3B867ED0810A1E2ULL, 0x17B470EB2E712CACULL, 
            0xCAE67F03DF738537ULL, 0x5124662450B6D987ULL, 0xA143F78E01B15BC9ULL, 0xC36AE4E3F36954AAULL, 
            0xDF20C8305E38EEB0ULL, 0xDBBF8A2EBECC8B8EULL, 0x34EF9CF036124988ULL, 0xDCEC8E6B03E40560ULL, 
            0x3727A20101D0C9B4ULL, 0xAABC0705820B4B1DULL, 0x30C3AA372E377085ULL, 0x952914CDEF71412CULL, 
            0xDDDD5B77B3933D03ULL, 0x1C0829AE94DBFA59ULL, 0xD0C95805101FFEE0ULL, 0xCE019923287B0887ULL, 
            0x1F1680CE52ED40A3ULL, 0x6B704A4CC8E98361ULL, 0xAC58C90C1A31717EULL, 0x7CF5510070857E16ULL, 
            0x0BD20B82E22CBAF8ULL, 0x3F6B48DDD366A6EDULL, 0x6D2F6AFE7EA2BCB3ULL, 0x06FF9BD4974211F7ULL, 
            0x83F1674D20CDBE75ULL, 0x4A91AE86439BAB69ULL, 0xE2367B464D52CEE8ULL, 0xFA6F35042C2B31F7ULL
        },
        {
            0x575147C808E2EDE5ULL, 0x2F46625BDBA8E45BULL, 0x05A6806889E490DAULL, 0x338F2504BC8D879CULL, 
            0xEED51E95C42FF4A2ULL, 0x41C33E7DF3CFA038ULL, 0x8BB50486E607C488ULL, 0xC9087C9C7577BEC6ULL, 
            0xBD12FEAB2C9A8969ULL, 0x35A48BB5B6AF575DULL, 0xCB8DA9C466E1D651ULL, 0x0D953F42395A909AULL, 
            0x336FC9BD494424C2ULL, 0x50C1F7E9A6A775F2ULL, 0x9016BAB436C0E12AULL, 0x0937E10991E5C45CULL, 
            0xE1B2AE9B87F88A86ULL, 0x411DCB7FFBB78EF0ULL, 0x306A7099477BDD43ULL, 0x7639351110572514ULL, 
            0xD00C0DA2677A5793ULL, 0x5538D5F963DEED18ULL, 0xF019E138F4CE4BFBULL, 0x815FD175C1F03D5FULL, 
            0x5A521DF6197AB95AULL, 0x2B1D50B74E421463ULL, 0x1DCFC4975EF90C79ULL, 0x69B102151B6FAE2DULL, 
            0xF0EDD6FE36562472ULL, 0x03C4F23BBB955F87ULL, 0xA00401B8939D8FC4ULL, 0x37180B3A480F765DULL
        },
        {
            0x48D50F1890EA04C6ULL, 0x94D9F424FDB3C03CULL, 0xF8B7C29A0B0DD520ULL, 0x1207557A593D43A6ULL, 
            0x33D296C7923117A5ULL, 0x845E847B528154F4ULL, 0x2158521ABB937FA2ULL, 0x50E5150DECED511CULL, 
            0xE2981A65FBA2EE56ULL, 0x13FA4B60960ED411ULL, 0x60938E362BAFBA87ULL, 0x5D8B319758E30DC6ULL, 
            0x8EC1145A0B097830ULL, 0xB8AA5E6265691D03ULL, 0x181D06F8058892C6ULL, 0x3BAC86D050BF5AEDULL, 
            0x67B3A8F744BEBBBAULL, 0xCDA6D547C826F63DULL, 0x5DF586DF456BF5D5ULL, 0x7ABCB1EFA83E1BDAULL, 
            0xD7E3772438D83426ULL, 0x3C73C16926984A7EULL, 0xD33B3C02451D9776ULL, 0xCB8AAF1209E96B85ULL, 
            0xCC48D48AD89F10C1ULL, 0x16E49BE0AF2FFD97ULL, 0x2B333BB273DC3A15ULL, 0xEA9A87AF65FB4660ULL, 
            0xA00BAEB24CCDB394ULL, 0x8FE8A915449D9E80ULL, 0xB9EE8E5A8B217FA2ULL, 0x7B11ABBD4974651DULL
        }
    },
    {
        {
            0x6BE348BD31E19C14ULL, 0x42F3B67C422BB178ULL, 0x7201A51CB55ACE2FULL, 0x869F4A6EB7AE1475ULL, 
            0x089A37DE04F09AA2ULL, 0xF6CBDADBEC88F4BAULL, 0xB50AA8017F75CDCAULL, 0xACD118987644F163ULL, 
            0x7DEEFC2169E0A39AULL, 0x981CE7234B1B3623ULL, 0x67C035E10E7C4FC6ULL, 0x9B9D63158453D7FAULL, 
            0x20048165160ECE3CULL, 0x8C06390F2D591CF6ULL, 0x3B9EA78FAF98309FULL, 0xE5964237F41ED6DBULL, 
            0xBA9166E00E7EDAEAULL, 0xF7E0E5C0CE967132ULL, 0xA9EC720A73E32E1FULL, 0x984381FEE449C924ULL, 
            0x30079F5A0C299779ULL, 0x3B91B5917C1E7C9FULL, 0x113B10C2B8CBFC00ULL, 0x552BAB8701E6FD07ULL, 
            0x481E05CC23BDB17AULL, 0xC5A7A985E77878AFULL, 0xDC505AEC62B5C250ULL, 0x3C41BF53529154E5ULL, 
            0x626D09D6C4A24E29ULL, 0xD2144882782B3D24ULL, 0xC322CF2A87DE1C21ULL, 0xA0262E6E103B4205ULL
        },
        {
            0x3D6F72F88C917DF4ULL, 0x5395D08CB37E0504ULL, 0xFA9F42A6E34FF4C8ULL, 0x462863A5617DC406ULL, 
            0x5C2D68344BFD18A3ULL, 0xCC666D2064C2ABDFULL, 0x32CB5D78607AC4C0ULL, 0x823249A94664C14EULL, 
            0xEA74AB6ADB60BEEBULL, 0x2946AC90A4F6C904ULL, 0x6EE0FF9B5D573A62ULL, 0xF2575E28BE52B188ULL, 
            0xAFF3810AF37C17FFULL, 0x852C28B16AA5ED75ULL, 0x716779A79FBAEE15ULL, 0x23774C2C08EF78BBULL, 
            0x812A8767AF9873A5ULL, 0x9347502F9F4BF6FBULL, 0x54AFD4D1D3ACD319ULL, 0x4DAD8DA523CDD771ULL, 
            0xCC1D4567E4031AA9ULL, 0x8BD770D9E682B2ECULL, 0x6E0D55E94A74C3A2ULL, 0xDD52B9516DE76B7FULL, 
            0x59ADDE2772DD1A6AULL, 0x7830F0AC5F79E7F9ULL, 0x7D29921682BCFE04ULL, 0x180AC6C4D055D7CFULL, 
            0x07FE083E3A8EB9C8ULL, 0x8F70351A652D668AULL, 0x13D77F75CDD4CFAFULL, 0x7DB64BE055FB7872ULL
        },
        {
            0x92F5DF51842E4B1CULL, 0xBF2792580C1D79C6ULL, 0x78EB19D9DAAFC687ULL, 0xB0141A93B73163F0ULL, 
            0x8782C59C5E3637B2ULL, 0xDF8E0443BB05E705ULL, 0xDE48C62AFF73FDFBULL, 0xDFAA510668EF3E43ULL, 
            0x864F7DE13B24D37CULL, 0x93389A0AEF831F94ULL, 0xBAEA5AB848B884CCULL, 0xF484C118BB1545E1ULL, 
            0x0CC8F5E70E0511FEULL, 0x308D8F6744C6414AULL, 0x0E1B05B64BA5E3FEULL, 0xC982375B8078C835ULL, 
            0xF7B7E62AFE08FE48ULL, 0x049B3DCB7B405D4FULL, 0x4204B87A2DBA8E8BULL, 0xDD14D1FD000A0733ULL, 
            0xEE766527B385A262ULL, 0x28EF33D525C278B9ULL, 0xB671079902DDA3F2ULL, 0xBC5C70608041D800ULL, 
            0xD4FBC1CC4E30ECE7ULL, 0xC3C638D2A90B72C4ULL, 0x97BF295B69CF3591ULL, 0xAFEDD7AEF354626CULL, 
            0xB4AB4AFEFA7ACB0CULL, 0x65DAF50CC8A1B4DEULL, 0xC063B3F0FED8F5FEULL, 0xBFEBA81EED8C5AADULL
        },
        {
            0xF2C4C1998AD97F47ULL, 0xCE946E2B54A25347ULL, 0x9205492BB0EB834CULL, 0xEF824B52094AEB5FULL, 
            0x3AF38010A04E2F14ULL, 0xC92819FB6F9B5FAEULL, 0xB9D2AC05885505A9ULL, 0x125C435A518A5191ULL, 
            0x026997D07DB1A9F8ULL, 0xD3630521E9DD9AB5ULL, 0xE86F0C11F9F6BBCAULL, 0x41ACC9B6406C101BULL, 
            0x6591657A2C10255FULL, 0x5403D318C694D07CULL, 0x164923051E9FDF79ULL, 0x8469F456CFDFFBA6ULL, 
            0xE6FDF71F9538DB6FULL, 0x9AECD1B44EC7EF68ULL, 0x1E66554886A2320BULL, 0x8453A939E6C866B2ULL, 
            0xBADEE4543139F331ULL, 0x6DD299EDED1F50A2ULL, 0x79FA31CC70A004FAULL, 0x2974ACA067BDF230ULL, 
            0x01E415123FFEF361ULL, 0xDBAC7138FDCD948BULL, 0xDCD9BD90E4C95EEAULL, 0xCBF4048E2EA5C14CULL, 
            0x1CB4964892A3CEE8ULL, 0x70443170B34CC3C7ULL, 0x2997346B7495B6B9ULL, 0x82EF8FAD9FDF9E84ULL
        },
        {
            0x09B3C9468610CD04ULL, 0x27B8475642E6FF0EULL, 0x9D1DF7C16D4BCAD6ULL, 0x4E9B65FEECFFDA64ULL, 
            0x401F09495DF44FB8ULL, 0x57A0E8D6DD26320AULL, 0x98D50CD89B8A6199ULL, 0x7578F20BB1BEB9CCULL, 
            0xD60A32C66B36E34BULL, 0x2B456D0C5E9EE7AEULL, 0xA452DFC9426A9AD7ULL, 0xCC14CB59C22725A2ULL, 
            0x3D96DC56DB7986F7ULL, 0xD34F993C1F96BC7DULL, 0x6EA0C2FDC3C8413EULL, 0x9D8ADBC21DB7BBABULL, 
            0xCBC9E98D71E9635EULL, 0x196BBF297E98A3C7ULL, 0x48044327764D0C47ULL, 0x394AD296C5F5F1DFULL, 
            0x408E6BB92EE90C3FULL, 0xF66692A89C5498BEULL, 0xF0AB1625C3410D6DULL, 0xC675C81168FFB2B7ULL, 
            0xBDB3BABF77CE637CULL, 0xB0FC916E23F38A4BULL, 0x6E93CE273E72B524ULL, 0xA20FF24F3546227AULL, 
            0x377DFBE4E4270723ULL, 0x15ED70EED311515DULL, 0x8D91115B3D9E3D41ULL, 0xF638717455B223FDULL
        },
        {
            0x40A5589BD7A30DF1ULL, 0x14599F002A4864A2ULL, 0x0C7AAEA13D9F2CD2ULL, 0x9CB891B7C01DE96CULL, 
            0xFB43FE858B9E7415ULL, 0xA81248FC0A9EB8F2ULL, 0x8061836A1891271CULL, 0x5128218ED5F19CF5ULL, 
            0x2BCC097F278D1612ULL, 0x7FA7DF524E47C5F9ULL, 0x7264679FB099281EULL, 0xAC803674C0110CFFULL, 
            0x3143F87F266230F9ULL, 0xF4102D627E7B191BULL, 0xAFA5A8A0A3A9D8BEULL, 0xB92BC71F0C9A0E1DULL, 
            0xAA67B97FD499860DULL, 0x271FEB0042C35F56ULL, 0x178A28202D07E545ULL, 0x3C003C77A328E77DULL, 
            0x3D5ECD3C8304C241ULL, 0xA111ACD98A6054E0ULL, 0xC7C5586489D3593BULL, 0x3BE02F6AF5CF543EULL, 
            0xD07B1E7A7C2ECBABULL, 0xA01C183EE275F683ULL, 0x20EFD72FED5C7242ULL, 0x235C583A073826CBULL, 
            0x59DC4AE11DDB1D85ULL, 0xE228856CF1C102D5ULL, 0x5D7B42534E966380ULL, 0x7F4A11696FF3DA07ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseDConstants = {
    0x633F2901CDBC2CE6ULL,
    0x98D860ADCCBFA6B5ULL,
    0x0E2A379B01B11CCCULL,
    0x633F2901CDBC2CE6ULL,
    0x98D860ADCCBFA6B5ULL,
    0x0E2A379B01B11CCCULL,
    0x81FDFFDC36F0BA46ULL,
    0x0F60CDED057B02AAULL,
    0xDC,
    0xEE,
    0x79,
    0xCB,
    0xFA,
    0xA7,
    0x36,
    0x1A
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseESalts = {
    {
        {
            0x25CFBBCD14B73BA9ULL, 0x6C5612B3D079C141ULL, 0x7F876F8FCAC89EA4ULL, 0xEC26E796AA2AF86BULL, 
            0x17153F1504B0D24BULL, 0x2799798D468F0C05ULL, 0x696B28F1DBE66623ULL, 0xE875C0E550BA762CULL, 
            0x4975937A068A3820ULL, 0x01F756F42AA0F193ULL, 0x14E832B28B76F04AULL, 0x2C196E29A12783B6ULL, 
            0x764A225EE20AD6D1ULL, 0x425603C77A9C0723ULL, 0xC0372884E7623DBBULL, 0x08117B2852CF8330ULL, 
            0xFC05DA1DA02D036CULL, 0x9E785486AAA6EAF4ULL, 0x6C860DE24C5D9BB3ULL, 0xBA66E35EA1D9F78AULL, 
            0x2A2AE248DCE2D6D7ULL, 0x8661E5EA93116F6AULL, 0xCCB06368204154E9ULL, 0x5ED4A3C452BE7803ULL, 
            0xC6098DD48D54E2D7ULL, 0x6B1DC4C72E364E9FULL, 0x953145CA2AFBA1AFULL, 0x32A85297CD8E4796ULL, 
            0x02A564BC2B39CB60ULL, 0x66E80F0234DBABD7ULL, 0xC9E20D3CB96AD1FBULL, 0x9DD7CA2B738DCC9FULL
        },
        {
            0x8D18B6702AD83599ULL, 0x1E1E719EE095A0FBULL, 0x53108E7116521CC9ULL, 0xD47640EE0D03AA47ULL, 
            0xB4CAAF54D8A5A5DDULL, 0x5F28478B830E423AULL, 0x456D8DD2D65DCE41ULL, 0x8FB176C56901C413ULL, 
            0x184466DC700A8667ULL, 0x3C62DB13715AE58FULL, 0x5B09A87EC98F8698ULL, 0x3ECF4F0165CA2B66ULL, 
            0x80201375AF8BD134ULL, 0xC4E17E8E3246A7B9ULL, 0xB923BFF9FD965A58ULL, 0x867C236110AEC4BAULL, 
            0x4B9A00D4F566209DULL, 0x3C71A9BCC88C734AULL, 0xEEB02262209CE237ULL, 0x5B7BBB46386A7629ULL, 
            0x71EFE40D73C12DCFULL, 0x30AAC19C72D1BFF8ULL, 0x89BD9A72DC993FDDULL, 0x922205BF5F9B6993ULL, 
            0x50F9E1D11F905A12ULL, 0xEC3DBD1BD5589B64ULL, 0x43B8A0AE2A2B9C50ULL, 0xA65839794A347D4DULL, 
            0x44D5E80B90A77666ULL, 0xEA5E6FB87C52B687ULL, 0x7E849E8F8C2FDD9EULL, 0xC55E6A2BE08EF861ULL
        },
        {
            0x21C29748BEBAC109ULL, 0x7773EC3F38FDC8B3ULL, 0x6C0CA8854C58B843ULL, 0x28604FD0B51AB71FULL, 
            0x72C28655EAB69CDBULL, 0x97658EC8BA90BB2FULL, 0x0CF4C34078EA7726ULL, 0x33CFD34D91C835E8ULL, 
            0x91831F1646B86BE8ULL, 0xF2C263E0FEE8AF35ULL, 0xE102E1C48832A8F5ULL, 0x527551EE3777DE47ULL, 
            0x15FF79376B2640BAULL, 0xE060123DFBE777B7ULL, 0xE797203560AF06F5ULL, 0x0FFCCB6F5F92AB49ULL, 
            0x62263DBEE5D9B701ULL, 0xFC911CC4E97E45D4ULL, 0x5D2191ADE5706229ULL, 0xAD5DB52447DCE91BULL, 
            0x4AFCB549C1F57274ULL, 0xD94A00B875D927C9ULL, 0xDB2FFB43E5E93B9DULL, 0xE3C6741AB071FC9BULL, 
            0x5036BD687A02AFACULL, 0xD8E409ED3F1A2CD6ULL, 0xC3AA37517F4A6C87ULL, 0x136A28F1A2D2E52FULL, 
            0x6592FDD6816BE8A4ULL, 0xA7BEF7A8F0170C9CULL, 0x6C50515F919D9AD4ULL, 0x7ED3189175790BCDULL
        },
        {
            0xE930BF8970C420C8ULL, 0x0CDFFC5465AC852DULL, 0x8C2CBBD62B8D973CULL, 0xD9B7C132C47652E9ULL, 
            0xAFF5908491A195AAULL, 0xF0F185C9083B0B58ULL, 0xAA23BE5EE4FDDD20ULL, 0x540A003D4618A4CAULL, 
            0xE34B0C3473C1D0B6ULL, 0x50640338E5F58E89ULL, 0x95E6D2799FA7953CULL, 0xF54567D5E265480CULL, 
            0x9D563E6D47CC238BULL, 0x8F015E04E235C460ULL, 0xC79A6AFBA730E51CULL, 0x7687DC6B69AC019EULL, 
            0x502F591EDD67021EULL, 0x9C9AE83D79487032ULL, 0x1F3F7F4026870496ULL, 0x16BF1E746E3B78E1ULL, 
            0xD41AC2344738E192ULL, 0xCBD52605FF651F97ULL, 0xBAD93D95426FB075ULL, 0xD30AA459C1FA1646ULL, 
            0x3A67B5EE26FCAA67ULL, 0x09069FEED1968CF6ULL, 0xCCAFB213C8EF11C2ULL, 0xEAD7946889F27DB6ULL, 
            0x33F6B337A2CACE60ULL, 0x2E51B3687AF2200AULL, 0xA32327AC26DC0F70ULL, 0xD71A4580914F3C6DULL
        },
        {
            0xA87FD84FDF4511F7ULL, 0x45FBB5B7CC6EFE9DULL, 0x091E9B95A1D3ECF7ULL, 0xD9E69E7CAF809D7FULL, 
            0xCAF8A3F8AC6B035DULL, 0x50708B52A122A22AULL, 0x25783345D0B71BF5ULL, 0xF3AC42F380ABB038ULL, 
            0x2A7A4A2215CC4D1BULL, 0x0C4BBBCDE270D122ULL, 0x1F1B2A310DF2CB7FULL, 0x77424451D2DBCEA2ULL, 
            0x451FC27B611DE849ULL, 0xB26FAF4B90980337ULL, 0x816EA284D5D444BAULL, 0x290F4A9704B58866ULL, 
            0x83E5EBEB881C2088ULL, 0x4573AEFA6AAC750EULL, 0xB21C97A2175C8120ULL, 0xE539D4C3A9B679C1ULL, 
            0xF47CC16C4432D73BULL, 0xC92FFA22657DA381ULL, 0x278A204945C71C4AULL, 0xF11B65A22B2CAEBBULL, 
            0x4C6E899BAE113CE1ULL, 0x0DCC2C3922FEC86FULL, 0x33E3CBD40BFE4EA0ULL, 0xB60334B15F1D7921ULL, 
            0xF055070C4DC3A604ULL, 0x0A0BB1BE483C9D63ULL, 0xF74194034D2E2B9FULL, 0x143D7839B82D4997ULL
        },
        {
            0xD07E9FAB1C0F9E97ULL, 0x9DEC8A8D3738E7AAULL, 0xB648B8CA1BEEC065ULL, 0x4B0FDA8999B20FD0ULL, 
            0x6D598FA06894CE20ULL, 0x4D65065DFEA65F2AULL, 0x1B1684A2AF3C4F61ULL, 0xEC9F9CED9ABA8400ULL, 
            0xE0914983290D1176ULL, 0x0A1FA6CC30E836A0ULL, 0xBF6712D19CE5449AULL, 0x30B141CE7581C571ULL, 
            0x1FB453573D096DD0ULL, 0x701D2B4E215645A2ULL, 0x1FA727D7A8A81928ULL, 0xCF211450FF4DE524ULL, 
            0x7A28D5D30D4C6EA9ULL, 0x2FFA6CD2FE5D8EABULL, 0x9684628CEEECB0D2ULL, 0x2017F75BEE2658E3ULL, 
            0x99C6855BE70A1F3EULL, 0x5785DE6FA0882BFFULL, 0xEDB3B6D669D19B82ULL, 0x9E7F5B3F3C13F30BULL, 
            0xF5E312A490CDA147ULL, 0x2EB9A2852903C7C6ULL, 0xD371A877DCB218DCULL, 0xCEB6EED529AAA309ULL, 
            0x61BC98AF4980B95FULL, 0x7F08ACA1C5954B67ULL, 0xC20C88F964C5E9A3ULL, 0x0B792C8B492C2AB6ULL
        }
    },
    {
        {
            0x5B1C6FA96E8F5C95ULL, 0xEA3256DD0ABAD213ULL, 0x5341B80B8F81CF09ULL, 0xEFEB0531709AA5DAULL, 
            0xD1EA90B90616CD00ULL, 0x4D392E714FA09271ULL, 0xFCDF90D053D25514ULL, 0x1243CD30540F498DULL, 
            0x014738F286250E15ULL, 0x4D0F9FF085B05F62ULL, 0x91D37A2695035C5DULL, 0x892033B32E395DF2ULL, 
            0xC3481237DC0FCFD1ULL, 0xEB13353C21CCB91EULL, 0xE046BB16DAB99BF6ULL, 0x25D871CE59701B7DULL, 
            0x540EE46B6C1637A9ULL, 0x6D854BCC3CB0BA24ULL, 0x9C9B5730484EFEBDULL, 0x1884E0236D31D7DAULL, 
            0xB3C0E207931B941CULL, 0x31915D8C187B04C0ULL, 0xE677AE1535D364ABULL, 0xE5F98646B5C0DF11ULL, 
            0x3E454C2E15E99561ULL, 0xF7836C848DCDFC72ULL, 0x68C013B22EC62C43ULL, 0x8DD2DC4CA18E24BCULL, 
            0xE844EBBC084821B3ULL, 0x6FB9803937A486DDULL, 0x80DF9295F9A486FCULL, 0xC329FA102D2F99F7ULL
        },
        {
            0x8429623886A21832ULL, 0x02BE2DEF7B409EAAULL, 0xB6A3095549CE9DEFULL, 0x79A85D5D1FB7FB85ULL, 
            0xE9E8883E10B20302ULL, 0x50D24F3A902B6A98ULL, 0x63418C62AD4ABB84ULL, 0xCACCCEA4619AEEC0ULL, 
            0x6173FB58C0CDBA2DULL, 0x2B9066358808DE45ULL, 0xEA1D7FE9362A193FULL, 0xA5AA8132BA9F3E3DULL, 
            0x786A07F9F5962C8BULL, 0x8A8D69B960552EA6ULL, 0x9EA55E89DDC3F282ULL, 0xD800CD5D48CE62CCULL, 
            0x6903C3829B00CE47ULL, 0xBCFF98FFD4F0DAE8ULL, 0xF8A52E9CFE0D243CULL, 0x3B67B94599805A3CULL, 
            0x0A644B31E37DDE95ULL, 0x1A200E3A987D2D61ULL, 0x89F85D21B50B24E7ULL, 0xB9CA5D2A73D92A30ULL, 
            0x304E633B12AE2079ULL, 0x3E174F32809FE629ULL, 0x85661F77A321D7FEULL, 0xEA77706C06AB566CULL, 
            0x0B5F90425CD4A313ULL, 0xFF8DF9BA6FD56EF5ULL, 0x771B62E4ABB276AEULL, 0x11FE63AB0FEA6801ULL
        },
        {
            0x4717B5A01D4A0A5EULL, 0x5D7777B347C2DFE1ULL, 0x572590993AA7D042ULL, 0x29021322FDE88125ULL, 
            0xCFC45C23DC1689B3ULL, 0xC27001B1AD1504EDULL, 0x7CF38AD54115A4F0ULL, 0xD5AFBD506DCF4B56ULL, 
            0x0D16C08D1C1F3B74ULL, 0x028274B9B3014DE6ULL, 0x71ADA95385F787CDULL, 0x2932CABD7A38E17DULL, 
            0xBFA0080D13822DFFULL, 0xCA6306625F6524BAULL, 0x75ABB198CFCFD080ULL, 0xEF6C82007AC8C6B0ULL, 
            0xAFD6DA67E795ED99ULL, 0x9FB9344673F6A39AULL, 0x8917340A2D25E8BAULL, 0x45DABFEF0E5F2FCFULL, 
            0x18CA9CDE0BC1D225ULL, 0xB3BA5D7F6F60C84DULL, 0x5E02ABCC2A302C72ULL, 0x879CAB93B736F8A1ULL, 
            0x8BCB9BC48852A922ULL, 0xF41CCB64B1C6B58CULL, 0xE359EC50A4DBD1AFULL, 0x063C7D670815C58EULL, 
            0x6294537232B21503ULL, 0xDA5A5D6F45922C3EULL, 0xFE8FE72A4216CE46ULL, 0xC7E2899883BA142AULL
        },
        {
            0x0F67D8DB9F32AF59ULL, 0x605843E7F6F6D5DBULL, 0x2CCBB37C27A3B67DULL, 0xDD2F9DF111316173ULL, 
            0xFD17EA4FAC8785ACULL, 0xF5F87608FA630D9DULL, 0x0C92A188C17AF4D5ULL, 0x1CED35EEA067D02AULL, 
            0x3AE991990F9E2423ULL, 0xAF898F25FA33FD60ULL, 0x97AB7283BFE3FBE3ULL, 0x988FB721393D12A6ULL, 
            0xF2A65F35071E33CFULL, 0x572717A0717A09B5ULL, 0x83350AA13166EBD1ULL, 0xD7E8368D7C278879ULL, 
            0xEC43214195F57C95ULL, 0xC19F7427B54C9FAFULL, 0xC34E83FEAE0922E5ULL, 0x045D14C2B6F91798ULL, 
            0xB8346984D751FA2CULL, 0x96CE0BACE40D0265ULL, 0x4565677F4CB4C8FDULL, 0x336C6534E14C25B7ULL, 
            0x936978730D8099C0ULL, 0x8F3B467B2D7F2C14ULL, 0xCCEB823279DBBC14ULL, 0x548D97E4F8371240ULL, 
            0xB4E2020DC67C3777ULL, 0x0C3D05AB604EDF9CULL, 0xA4ACFC43434FE9FBULL, 0xE255EA8B79471EFBULL
        },
        {
            0x647435D1CF9A2010ULL, 0x48713B2759C57101ULL, 0x86BF0FB368CBD9A0ULL, 0x42C74846C276C3C8ULL, 
            0x468E12E7E2A88648ULL, 0x72239E8848D0B597ULL, 0x59D19C7096C098E3ULL, 0xE0E6F1ECD5B7DD3BULL, 
            0xA358A7D7BDE43163ULL, 0x272DF7E5A68E5ACAULL, 0x1B8296079E5FE1A4ULL, 0x90346EB375298CB8ULL, 
            0xF587E42DE5AED484ULL, 0xC6AFF61310CF6DCEULL, 0xE9B517AA2648A5E7ULL, 0x0D7145E886D71F06ULL, 
            0xADDCF4239A1EAEC0ULL, 0x3DD01B22C4583C89ULL, 0x4004EEB409FD5C02ULL, 0x51850B8C81EDF304ULL, 
            0x41C7CEC8E126A226ULL, 0x733381953C7C8B2FULL, 0xC2721FFB6CFCFA98ULL, 0xF43FA22F9FCBB99DULL, 
            0xAE42DBC2F6CAE5CEULL, 0xDDF9BD3EA947826EULL, 0x32C7962024D0B7E6ULL, 0x3C8110177D4A326DULL, 
            0x130C6124EFA088E2ULL, 0x102580E03A856202ULL, 0xC8A85637E60D7BA3ULL, 0x49CACB2185C201ACULL
        },
        {
            0x4232B90F150ED8B5ULL, 0xBF294F3B57FA2A0AULL, 0xBE57C08BE6C24A97ULL, 0xA8D6AC9CD9464183ULL, 
            0x312AF4F0D865C216ULL, 0x3ADCAF189E55CBFEULL, 0x4192CCA49AFCE8A0ULL, 0xA366324CAB245659ULL, 
            0x094EC92C949F188DULL, 0x0EB3925630524850ULL, 0xA1D1839110086AA7ULL, 0xF79FB4FA849BB4D1ULL, 
            0x123F9CFEEA1C9521ULL, 0x769EE810AF638872ULL, 0x1ABF1C277C422AB2ULL, 0x3E0BE79FF37A9C1CULL, 
            0xCFA99527ADD1987CULL, 0x874FBA00F4B3EF00ULL, 0x07FB52068E8D35FAULL, 0x73812D7D6B638176ULL, 
            0x8272B76A2FD86C13ULL, 0x4BA2E0668690B57AULL, 0x88EB080F654243FFULL, 0x5A1C075FD6FDF60FULL, 
            0x5D088915F0800864ULL, 0xFDD136241CBA7B57ULL, 0x9A5CDDD864BD1FCBULL, 0xD28D0702A71071F0ULL, 
            0x0D1190A03ECC0399ULL, 0x5CD6A214C426EA02ULL, 0xE7F159174428515CULL, 0xF5DD7C1C3523D7FFULL
        }
    },
    {
        {
            0x53762EA00AC2D8DFULL, 0x7FE780B0A6BC97C9ULL, 0x6430B11D5A4C7815ULL, 0xBB4AF3B2BBDAE006ULL, 
            0x9F7D1353553AE016ULL, 0x2F637EA635CB3835ULL, 0x1D362A4098B49638ULL, 0x8CAB283590424F5BULL, 
            0xEBE808BAE6C3DA5DULL, 0x876514CDC449F82BULL, 0xF687BFE87B479D4EULL, 0x58479DD59A239FC8ULL, 
            0xBECFAF42083F661BULL, 0xD87200F798A7320AULL, 0x161EC5DDE8203623ULL, 0x85261348397F16F2ULL, 
            0x7C6153B66904F7D0ULL, 0x2EF2A542F4A8B600ULL, 0x699A31A2C1FDB773ULL, 0x55662C30FF9F3132ULL, 
            0x0F9FAB870F8BF7FEULL, 0xBE13F3394368A63CULL, 0xB25F618FF45DBE23ULL, 0xEAEE34B125962509ULL, 
            0xEB70BB52AF73551AULL, 0x7CB4A3BDC254F2E7ULL, 0xDCC7C4E109E1372BULL, 0x6C83617860844C3AULL, 
            0x33F9F092230840DFULL, 0x1E3B20A8188CC8C0ULL, 0xBFAB2397CB71AF74ULL, 0xA69A8D37313FF35CULL
        },
        {
            0xFAC257FF8F3FD5DDULL, 0xC5355E47690EF67AULL, 0x23014009436018F8ULL, 0xE7D3AF9728C2A249ULL, 
            0x7447D5F486329EEEULL, 0x4AF58D0D849DA1B9ULL, 0xCC2E39A91BF83844ULL, 0x29618A2C6C8DD555ULL, 
            0x4A3EE46D56311F49ULL, 0xCD8953E08A0E8CF7ULL, 0xB28D0B03B2587089ULL, 0x6A591816AE597C91ULL, 
            0xE562665318A12421ULL, 0xBC779C263D0B3120ULL, 0x67C7BC6C235328EEULL, 0x0B38CEA91D9ACFBBULL, 
            0x0FDB4E13FEDEE1DAULL, 0xE4A782CF8AA422C2ULL, 0x535FC434AE62505BULL, 0x88BCFDA652D6895EULL, 
            0x5F869F281F544260ULL, 0x3CDE964074228799ULL, 0x562001F99407323BULL, 0xED4222653E64C832ULL, 
            0x0B79382A07986582ULL, 0x5A01E78BFE82BDC3ULL, 0x6059EF50EDD0A26DULL, 0x7ABE449CA49D5E56ULL, 
            0x143F9F926E0B2166ULL, 0x9D3B64BC0327E4BDULL, 0x451D5B6936EB08E8ULL, 0x5331FEBBCCEC1207ULL
        },
        {
            0x5E75041DF59DE22DULL, 0xCDEE37AC80299092ULL, 0x05914B4DF3418E76ULL, 0x2124BE359FB92FF1ULL, 
            0xE1884D83B37B0032ULL, 0xB5BFA48558494EA6ULL, 0xDD226180E89099B2ULL, 0xFF9017955EB8CB2CULL, 
            0x6E568BB929D14BDAULL, 0x9B98314BF926496EULL, 0x88B1C874D79E91E8ULL, 0x52301119465F5330ULL, 
            0x1027C5C16ABE3E1BULL, 0xE509D170F5F2773CULL, 0x9642CA2FF126F93CULL, 0xFC581D4BFE8BC51AULL, 
            0x5F78A7820F1192F7ULL, 0x3F14605BC87C40EFULL, 0xFC8EA04A48D1D77EULL, 0x8F8DFA8CC33B9741ULL, 
            0xCBEAF8CD410C1F0FULL, 0xEBE92451DAC6700CULL, 0x9F8F7FE90AE4F626ULL, 0x462CC8DD62EAC999ULL, 
            0xE2A4D8F0AF560633ULL, 0x386DCE697EE7A76AULL, 0x46ADEFEF574DF0D6ULL, 0x2E5CA3C19D595EC4ULL, 
            0xD156FD562ADF8866ULL, 0x986A2063FF4CF108ULL, 0x929D4B2678E1FC5EULL, 0xEAF1F32EA5CD85F0ULL
        },
        {
            0xAB836322F3A8FEBFULL, 0xBABE3914FDEEB97EULL, 0x33E154631F5AC63CULL, 0x42FDC0E1269B5BD0ULL, 
            0xACFD1470707CD821ULL, 0xC9F7CC545FB12051ULL, 0x3B4530A067D29E57ULL, 0x043A4B3508D7917BULL, 
            0xEA266829E81CBA7EULL, 0x0DC0F71A041F144EULL, 0xAE503FCA3B70015FULL, 0xC0FF5F8F0F3BB11EULL, 
            0x396A0FB8FC6A64A5ULL, 0xEA414A2B9286E736ULL, 0x974046ED127F0944ULL, 0x1935284A4E202F9EULL, 
            0x2672E68B13DEED79ULL, 0xE5D3F27228AE4012ULL, 0xABEFC748028DBA64ULL, 0xA4BE7185688D3AE5ULL, 
            0x44415AB557205955ULL, 0x6A37F295A5A0D0A5ULL, 0xC6EDF0853C64ACACULL, 0x4F18E164450C44D3ULL, 
            0xDDFF624ECB6FD876ULL, 0x373F14A11AB94A04ULL, 0x750ECAC86D53AA4BULL, 0xB16E048B91F37E63ULL, 
            0xBB437D88C09D7FB9ULL, 0xF1B8C529A42D6B60ULL, 0x84108EF8F03F1A4FULL, 0x49360150EE2A96A6ULL
        },
        {
            0xCC1F05155D06E713ULL, 0xFD226045A84A43E4ULL, 0x4037B08A904320D2ULL, 0xF7415BA8E56F5FDFULL, 
            0x25902306711B7EAEULL, 0xB4FF195B93845782ULL, 0x484C91FF411C71A8ULL, 0xF03018C1CBABDA7DULL, 
            0x04C3686F59E00329ULL, 0x93BEAD9B267DD0A0ULL, 0xBBB8F7E894C6EBCEULL, 0xDD05732C9EB1AD22ULL, 
            0x585C0D6C3E8A6DE8ULL, 0xEEB7E6BE8F5A0ED9ULL, 0xA468680D5F8B8EF0ULL, 0xC55B305E7655FBB9ULL, 
            0x6C33765392CEBD26ULL, 0x247DADA7CBAEC5AEULL, 0xB602E1B79A1B3FBCULL, 0x7765272384E621CBULL, 
            0x474264B1E1E988B1ULL, 0xCADBC71CE8BA91B6ULL, 0x7D43052B9B3A45CDULL, 0x1196376F1439AD84ULL, 
            0x1A104E4518B5B988ULL, 0x8495BAB37C82A35BULL, 0xB17DD3437ABF1FA0ULL, 0xD4333029CA40B6B3ULL, 
            0xCE3A2D9779557CD1ULL, 0xD3F1F0A8DA724EA4ULL, 0x2A03397D18A63625ULL, 0x6C587DA74EB4E5DAULL
        },
        {
            0x020169EA4C033331ULL, 0x79E22790EFBB45C8ULL, 0x6F317D1048AD18F9ULL, 0x140E9C0FE7F88D35ULL, 
            0x03901B33369433B0ULL, 0xC66DED3657823987ULL, 0x2FF1CC2FC6EAFD1DULL, 0x6AE77FAC14E9A544ULL, 
            0x3CF0BE5310ABD0E5ULL, 0x7D9D03CD8DE5EB6EULL, 0xB36A91F3A8F10DDCULL, 0x7245D6C9AF606706ULL, 
            0xA448C6EDD0411664ULL, 0xDC7BF9F056036362ULL, 0x8CCF6B05A0FC90A1ULL, 0x105AEC2DDA11FED5ULL, 
            0x3F30704BACF98789ULL, 0x676F1544637608CCULL, 0x05A3978CA787ED18ULL, 0x142EA4985D2E4629ULL, 
            0x23A888C599D94EEBULL, 0xB50F5DE184FE7220ULL, 0x44A77D8E10D8A6D9ULL, 0x6FC704F641FB1730ULL, 
            0xBE9B5655D432F310ULL, 0x1293272C8BDE003DULL, 0x9BA0F14159ED6810ULL, 0x4DE82195DE6AF7CEULL, 
            0x4DA27FB39EA4CD36ULL, 0xC5981421EA85A743ULL, 0x9F0E26385C3C8F20ULL, 0x79661265DE0E6A96ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseEConstants = {
    0x32017026C67AB0F9ULL,
    0x363B585A6F197F3FULL,
    0x3D87C99B3EC192A5ULL,
    0x32017026C67AB0F9ULL,
    0x363B585A6F197F3FULL,
    0x3D87C99B3EC192A5ULL,
    0xB0637CB5648F4AC9ULL,
    0x1A2FE1D8863ADB37ULL,
    0x2A,
    0x43,
    0x72,
    0x97,
    0x42,
    0x51,
    0xC1,
    0xFF
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseFSalts = {
    {
        {
            0x2BB9DBF10199A69FULL, 0xB37275B6C594DDC6ULL, 0xB9CC3F625458EEF1ULL, 0x9271D88BA9547B60ULL, 
            0xD5851916C25EF2AEULL, 0x2940ACDE70265E47ULL, 0xB1D3D4631ABAD6F7ULL, 0x394720862B5E846DULL, 
            0xB0F7E3405B17F432ULL, 0x7AE4D2AC020F2091ULL, 0x8CA6C552BACE666DULL, 0x9CF17D63EA38CB44ULL, 
            0x02ED0F814BE0D4C5ULL, 0x95054AD7F22D9415ULL, 0xEBF9CB76F23705DAULL, 0xA711EAA778F1910AULL, 
            0x22F2891BF80D1F42ULL, 0x6243C16764359F10ULL, 0x09A315341AF0C8B7ULL, 0xFF08D801CE723DEFULL, 
            0xE5A0D2D0B6004DFAULL, 0x1357DC1605DE2321ULL, 0x702EE56D68783905ULL, 0x93CD1026DF30CB5EULL, 
            0x6BE94D24A90C5805ULL, 0xF07A0BAAADAE0686ULL, 0xDD15248E0364AEC1ULL, 0x85826826A94B7639ULL, 
            0x13FB313280CA6ED8ULL, 0x038E3032F104A341ULL, 0xE47341B5AEE54EB3ULL, 0x8A56B713FDAA7888ULL
        },
        {
            0x3926A18D6049E68DULL, 0xC96BB7C0E4B7F413ULL, 0x009DFB62EA419E65ULL, 0x555EECA2C17D2BDCULL, 
            0xFD285405A507C0E7ULL, 0x704CDAD3D05F5A84ULL, 0xD0DFC0143DBEDFE4ULL, 0xB07E82BB34AEE6C0ULL, 
            0xAC57EF3978140D26ULL, 0x7858225E2ADFECECULL, 0x0AA8BB903F69E33DULL, 0x82B6EE7D7A81C7C8ULL, 
            0x238BDB1B3F8E1397ULL, 0xC77DD57821A3925EULL, 0xCDF594C9298F6433ULL, 0x5DDBE99BB5C7235FULL, 
            0x6702C924A5ECE4E5ULL, 0x6A5471E179F2B2DCULL, 0x18A5B9B4BEEF1286ULL, 0x4F5474CA823AC24FULL, 
            0x48404B78F0280CF1ULL, 0xD59F95DF4927C0E4ULL, 0x43F343998EA2291AULL, 0xC6AA9478475B7480ULL, 
            0x6586F460601140A6ULL, 0x95857B6DA3CA1F15ULL, 0xE48F0C2058D87F02ULL, 0x8B854CA4987E3081ULL, 
            0xD8C94B02185A52E6ULL, 0xFC2918F573E17C10ULL, 0x4CB8D96FA85BF4D2ULL, 0x86B89AA292B7243FULL
        },
        {
            0x6F487E8F0D476851ULL, 0x28646E86AF50D868ULL, 0xADB46AC597E4B3ABULL, 0xB364F48B83380A76ULL, 
            0x68DD77DC8F1E57CCULL, 0x66EA2B055788D1D5ULL, 0x685B3391B7CD9D72ULL, 0x555A3D8F38ECCA04ULL, 
            0xD99C73C5C0A6B360ULL, 0x1768CF473859B6F3ULL, 0x93A47C6A89879759ULL, 0xFCBE3D29C719A6E0ULL, 
            0xE2AFB7F18F2D10FEULL, 0xC60317818FDDFAC3ULL, 0x4D8CBA5DC062298CULL, 0x26224B7DD156B9E4ULL, 
            0xF383B592CE2068E7ULL, 0xB4EC823BD24BCC59ULL, 0x7FD7C979E55442BCULL, 0x10E3433924007948ULL, 
            0x22D7EB13876AFDABULL, 0xD519CA7B6EDD1692ULL, 0xBAF6759BC1B2E8E7ULL, 0x52F4589CD79E972FULL, 
            0xC17EABE51A5F4073ULL, 0x2D95BD2B332C655CULL, 0x1C367F5F3BFAEFAAULL, 0x8552EA323642F51FULL, 
            0xBA8836191D90D831ULL, 0xBD4A10D6EA913FCEULL, 0xD0759DFF0E0FE1EEULL, 0x04A53F33D5EC2701ULL
        },
        {
            0x4E04BED754699ECAULL, 0x8BF1F7622A0B0F58ULL, 0xDB1E261FC2ACF260ULL, 0x4335C815B1A5C628ULL, 
            0x976DB89927F1F1E1ULL, 0x44FBF2A03CC4A037ULL, 0x667F3AB95786D4E9ULL, 0x7660ADF29D73F457ULL, 
            0xC3C3EFD5A564302CULL, 0xF467C94827CD2F8EULL, 0x2F76CC9BA8D27673ULL, 0xD03DA644E34D696DULL, 
            0xA7BB6B43878E0810ULL, 0xA123BEED95FDC336ULL, 0x179EC04ABDD98DD3ULL, 0x51E9DCA9626AB33CULL, 
            0xF0BC9355E6A50DFBULL, 0xB9070260ECA6F611ULL, 0x8D5BA3C55FCCA12CULL, 0x550FA324B624D3D8ULL, 
            0x54D1001AD90B5DDBULL, 0xA0002402836EFC3EULL, 0x02CE1C9391B5743AULL, 0x31D5992BF1D2D884ULL, 
            0x9CF5579C9DE81713ULL, 0x0F5261597E49ED2AULL, 0x8AB4EDCAD7F723D1ULL, 0xCEF6CE2BCC5B7480ULL, 
            0x806C88D371A1074FULL, 0xAC3AA75BDF2C4D82ULL, 0x7BB4FFF9246CA96CULL, 0x201BC1729A10B355ULL
        },
        {
            0xDABED7B6404189B2ULL, 0x6DD1EC1E36DAA2DFULL, 0xF3C761A970478FE8ULL, 0x75B8732DB00F5FF4ULL, 
            0x6F159515CF738E63ULL, 0x46F743B3A1E54B47ULL, 0xB6337CB4D1AF91CBULL, 0x6784A14171865241ULL, 
            0x9A344BB067BBF862ULL, 0x8A4CEB6668C0D58BULL, 0x6FAA3733B3339C65ULL, 0x83C50568FAFA61BBULL, 
            0xAD8CD8FE67C0F9EEULL, 0xB0929A09E7864255ULL, 0xA32E41476BB51B9CULL, 0xF50645D0F78BFBF1ULL, 
            0x8E4382F9F8547660ULL, 0x6D96F408B7E527E7ULL, 0xAED4D1BD48C6DA3CULL, 0x6ACAE8B3D4E983B6ULL, 
            0x12A5704A1648289EULL, 0x7C3BF5DE6FE9638BULL, 0xD250EC76D37D3576ULL, 0x733E4D1F6E5640D8ULL, 
            0x7F0AEAA988302D21ULL, 0xB76B237958E13737ULL, 0x3AAACA8DA5FC6528ULL, 0x0F789B2CA9F10725ULL, 
            0x056EAD875312C436ULL, 0xC510C7F8D00C86B7ULL, 0x905E7A9A4E1CC905ULL, 0x94828A4EF16A46B5ULL
        },
        {
            0x24843D8A6584D4C3ULL, 0x0712CE93C0AC687CULL, 0xAF17C67FF5C26137ULL, 0xCA0EB9F343FDAACFULL, 
            0xAC5B96C72EB22D13ULL, 0x4BE28B6B5FABE343ULL, 0x6DDEA455356F8E10ULL, 0xAFD1B9FC2F8A9F26ULL, 
            0xEDF5D431735986DEULL, 0x28C634EC490F4A0FULL, 0x107DCC89B09AB6CAULL, 0xE7E30FA13F645D2FULL, 
            0xC7046E4ADE1FF7A4ULL, 0xB85A115A76AD656CULL, 0x8E21E209B98CD49DULL, 0x71863BE1FE9A5678ULL, 
            0xBB504676545345E8ULL, 0x075F7005A5DC516DULL, 0x06E79BCEA83A9C08ULL, 0x1203D08285FC78B8ULL, 
            0x28892FBDEC102BA1ULL, 0x09730F64B11BCA2CULL, 0xE2FBC10B425FBAE6ULL, 0x3CFD7E8BACB4558AULL, 
            0xC311C29C2C77CA1FULL, 0xE10CA7EF3630DBC8ULL, 0xE847CAE68D962E12ULL, 0x2ACC2D10A81F9562ULL, 
            0x8BD4F4D50B49ECABULL, 0x044D32BB67C7EFE7ULL, 0x66B0409AFA329414ULL, 0x98D92F31D84109E7ULL
        }
    },
    {
        {
            0x75F9563BA82BF4F1ULL, 0x753647619D86EEFAULL, 0xE34CE1B5057B0B2FULL, 0x2BB7F6B06B568A67ULL, 
            0xFD4D919E238C6E1CULL, 0x0F7506F5C6113785ULL, 0x0A83BC6CD7AF7C8FULL, 0xA16C507B8CFF86A3ULL, 
            0x42E4A4D3CFB2E755ULL, 0x551053C4553C03FAULL, 0x3DB1DAB997A23DC9ULL, 0xF21E99379EA01A9EULL, 
            0x942D4D0056395F7EULL, 0x5FB320DA3A49C8FEULL, 0xE9B90456D2803385ULL, 0x126C38547CA2D74CULL, 
            0x610B54F101B33320ULL, 0x0214F444F939DA94ULL, 0x682F89535589F379ULL, 0xBB9E008B760FB79FULL, 
            0x33D7A5BDF3B43B1EULL, 0xD9851EF991A769B0ULL, 0x27CDA59119B3A5BAULL, 0xEBA8E75321585EE6ULL, 
            0xCECDAD978259A025ULL, 0x22AC1F67EAFCB38FULL, 0x3538C2E6CB5B7552ULL, 0xB09CD2FB9E46048FULL, 
            0x73DEDFB22DB87FA1ULL, 0x3F354B8FB893697CULL, 0x1A5FA41DB20F8B7FULL, 0x867F758546FFEFDAULL
        },
        {
            0xA6ABCD7A9CE33A78ULL, 0x95CD22D5AA10D3F8ULL, 0x25B371E8081224BCULL, 0x100E7404A07095A9ULL, 
            0x8F67FFC2071ABB23ULL, 0x4B2D88E0CC270550ULL, 0xCE7C2DC7B2802EDDULL, 0xE0A610477E5E9A8FULL, 
            0xEC0604FB397A4DF4ULL, 0x69833B5A51E60A69ULL, 0x7D7BDC8F66390CC4ULL, 0x9D20AC77E6737E3AULL, 
            0x27195AABE1BFF6F6ULL, 0xDD7D075377A6EC83ULL, 0x14E1FAB4798B1D3AULL, 0x2A4084667D3937ACULL, 
            0x5161BE1829B7DAACULL, 0x140A0EBA8BBB2279ULL, 0xB548A5F1FCF904FCULL, 0xF0F0BB915DC3F658ULL, 
            0x49EA4D95AB4DB450ULL, 0xE9110152997D5F17ULL, 0xA04CA94A2E7A24B8ULL, 0xFD07F6A2859084B3ULL, 
            0x272387475C9F5B99ULL, 0x84BEB82AD67D9243ULL, 0xF82E0A8DA387E287ULL, 0xB8F7E954ACC3DCE4ULL, 
            0xBA550B5FD7EEF0F8ULL, 0x730E4F350E663848ULL, 0x14259BC3D2931887ULL, 0xE1F01AF276096EEAULL
        },
        {
            0x42F21B86BEDF0926ULL, 0xB8FCBA58D8389F00ULL, 0xDA0703EBE4AC1449ULL, 0xC17D32D93E805A33ULL, 
            0x501D4A1294CE0CADULL, 0x04E7C40C2C86C0B5ULL, 0x2AE95C2EB28B3606ULL, 0x5B02624296352421ULL, 
            0x51AF27EFE8F049A8ULL, 0xF7A247EF7479A2E2ULL, 0x8A545099330E82F8ULL, 0x36BEB4E11A9F6E97ULL, 
            0xBBC0D798D3BCCC9AULL, 0x2D9901389CCDCE0AULL, 0x62A8DAA3D00DD0A1ULL, 0xC3BB70FA9E656CA0ULL, 
            0x030B53AD74ECB96FULL, 0xB0F8D130E8D6C5ADULL, 0xD40C6C3DC08A021EULL, 0x726FF1020369C28CULL, 
            0xC367502917BA56CCULL, 0x9D8AE3AD09EC0E6BULL, 0xE7E17ABA9D936502ULL, 0xC2F8CDFC06BC9F29ULL, 
            0xFCC3CF93E8DACBF2ULL, 0x8A92531E62448388ULL, 0xED96CEDDC32FC3E9ULL, 0x0D8162974F7166E7ULL, 
            0x9E1B9879CDCCA0CEULL, 0x0102CDD482B72A1BULL, 0x34EF644ADF750090ULL, 0x6DAD76C5FE1C123CULL
        },
        {
            0x007FBEF1F82D2DB9ULL, 0x273E2EADF20AE224ULL, 0x19D2D56E1333E9E7ULL, 0x96C9171E10C43ED0ULL, 
            0x057FA7B99184C33DULL, 0x3E35B76BB7FEF6BFULL, 0xE9798E1F8FE74ABBULL, 0x53ED8ACA5E49C54AULL, 
            0xB9090987FB8AF68EULL, 0xC7EB3B337FFF3F44ULL, 0x90A88C58A645AB2AULL, 0x20D562CB895C7897ULL, 
            0x8FC44DBF964A49ADULL, 0x8539B6F40C5E4319ULL, 0x155CBA8C3FA782EDULL, 0x169121EA503E2E08ULL, 
            0x9C704F6E773D812FULL, 0x80778B0106B82800ULL, 0xA64CCB68A96B998EULL, 0x153697FFE831CBD1ULL, 
            0x9CF87C0A454F1A2EULL, 0x731EEB29115ACEACULL, 0x02C1E7B4DE99434CULL, 0x2F29B9C5DCA82A62ULL, 
            0x6D51417900E7AB68ULL, 0x9535BA737F7A7A30ULL, 0x09036E232CC99684ULL, 0x802A63C015F96CB4ULL, 
            0xF1BA4C1FD997E50BULL, 0x9E47C0B27CDD99A3ULL, 0xF1FC5ADC24472937ULL, 0x2BD82799441570A0ULL
        },
        {
            0x0B1FE145D1FA6CA8ULL, 0x5A3420E303177224ULL, 0x59CFDC1D44F1F6E6ULL, 0xAD0E44588FB87BD6ULL, 
            0xF977044FA0DCAAB9ULL, 0x885273822A04A775ULL, 0xAFA2B010EEA792FBULL, 0xEF740ABDC71AE484ULL, 
            0x86CA1E9313428644ULL, 0x4933838E87BC4481ULL, 0x56D565F2DD157A9CULL, 0x3E01B0BC6AAC1EB9ULL, 
            0x0014654787184875ULL, 0x181206E0FF4A2E2DULL, 0xAE51464FBD11D2EAULL, 0x1F5CFC87943EB957ULL, 
            0x06DCE4D5FBC041E0ULL, 0x8C5F7BACA14051CFULL, 0xB338BF4E255E2C44ULL, 0x8897571333CFF8F8ULL, 
            0x15BBA8C61E9E0E7AULL, 0xB0AA72F178364701ULL, 0x8CFD5756685EB1EAULL, 0xCFBAE90B5FAE1836ULL, 
            0x7B05CD0CE9A78FCCULL, 0x15852104664F212CULL, 0xD8F211055276F424ULL, 0x5381AEC4265C26A3ULL, 
            0x224567C02DA1B71CULL, 0x3FA8535865853067ULL, 0xA0705E50E1FC98F8ULL, 0x50F33B0767DE78E6ULL
        },
        {
            0x10F955A40BA299ECULL, 0xBBB695A4F3CA0A26ULL, 0x76FE4F5536A3BF85ULL, 0x7332FF9487C7D3D8ULL, 
            0x47E11B32C08B6CB3ULL, 0x1E8579EC87D1CBE1ULL, 0xEEEF87043F132037ULL, 0x439F9787CCA04EEAULL, 
            0xD442273BEBA08882ULL, 0x826F1C0C7EE4A7EEULL, 0x0CE611E4F6EC7FD6ULL, 0xF1BEFDCE3F208087ULL, 
            0xF13023E2D025A6BDULL, 0xC2A26D5DB627FCD6ULL, 0x92A9EF2BE3DFB6A4ULL, 0xB2A184A965BBF2DCULL, 
            0xC7A9027C069061DAULL, 0x93FFE0A57728316CULL, 0x0B29AE3730B9EFA8ULL, 0x8520BF3CB67B0B8FULL, 
            0x633AF4D1318C070BULL, 0xCCA1A0811E77A1B1ULL, 0xAE8CFD3D8D888916ULL, 0xF5214E5563CC4DC1ULL, 
            0x7C6CE06C4B19BE07ULL, 0xD5CB15449DC69C08ULL, 0xDF8243BEAB7E34C4ULL, 0x0EB84726E0984F01ULL, 
            0x420CC12720353257ULL, 0x0D3BE4429A7DFD17ULL, 0xB8C5CECCCF2F545AULL, 0x51E00EC482C109A3ULL
        }
    },
    {
        {
            0x863425C7A58A537EULL, 0x9C73FD9EC8CB98AAULL, 0x4C928FCF8EDC0D25ULL, 0xF6F086AE55F98FF1ULL, 
            0x9FC6C8C076237823ULL, 0x5E2A6BABEAF6ABA1ULL, 0x55F18DE229850744ULL, 0xD741C29F20852BECULL, 
            0x9683863F5DF692E4ULL, 0xDCD0E5653ECE903CULL, 0x379797B4152240D1ULL, 0xB49A1C254E915D63ULL, 
            0x988A5B1BC8E3627AULL, 0x013D6C137A2C78D0ULL, 0x0C54E2E919395E39ULL, 0x70978A0BEA58EFBEULL, 
            0x26CCF24B4B0ACBCAULL, 0x07D12F9FEECF40F1ULL, 0xA38FB35B1B1AB0FDULL, 0xC0CBA77E038AED24ULL, 
            0x934166DE3CFAFEBFULL, 0x277AFE101E622B4DULL, 0x34ADFEBD4DB1445CULL, 0x9758D5CF2D513268ULL, 
            0xF823E18BC4283AC0ULL, 0xE528DCEDCBFF70ECULL, 0x7B561787FA1B8DA2ULL, 0x26325E1E25A82EE8ULL, 
            0xD57A776A98A843D4ULL, 0xBBD5A90F2C4E8D95ULL, 0x0617F62AAFDE0EB4ULL, 0x6DE0AE9712AEE5C5ULL
        },
        {
            0x13A148A3A8079516ULL, 0x925B999066F9F715ULL, 0x196DF48AD8794A5FULL, 0x7123E7D0E518AF7AULL, 
            0xE85E50770C507C92ULL, 0x03620CF03A0EAD89ULL, 0xE37D8FE8CA7E02F3ULL, 0xE66B7AD67A758422ULL, 
            0x5A8964642E550D35ULL, 0xA5B62168322A33F2ULL, 0xD75098CFDFE1A393ULL, 0x91E1089D61897F18ULL, 
            0x4A45A97172ECE4D8ULL, 0x955350FA8C700BE6ULL, 0xA8428A72986861FBULL, 0xA8F39FA3AAE9625CULL, 
            0xF3F2BB5EC57AD6E3ULL, 0x2587A985B301CCDBULL, 0x5EBF8ED598138526ULL, 0x3C0974168F3865FEULL, 
            0x5421BC97D0383CE3ULL, 0x94109284791DBE13ULL, 0x1312082B591BE6EBULL, 0xA2B89AB265949111ULL, 
            0xF18D64ABE2495A11ULL, 0xA47A16E1A4C3DCE4ULL, 0x705BDDEFE5931FD8ULL, 0xE0E3257F7E75F2E4ULL, 
            0xA78DE55A7420D56BULL, 0x49AEA68FD561FB0BULL, 0xB8D74A01EED16E5DULL, 0x2EA24FA73655FD46ULL
        },
        {
            0x7D9419DD2918A573ULL, 0x9B4058104A229F89ULL, 0xAA86EE743956D059ULL, 0xB5DCFD1C37918EF1ULL, 
            0x4D0E20DB8551B165ULL, 0x50DD944BD7D0D5E2ULL, 0xB4496BE10B3CA4E7ULL, 0x8A19E1E72733E509ULL, 
            0x6D65916815849086ULL, 0xE209C90732568D65ULL, 0x8FA338B37DA959CFULL, 0x300A9B3AF09A5759ULL, 
            0xA6EA5BB80D173F41ULL, 0x8CD984A90A17BFC6ULL, 0x25872EDB8232E291ULL, 0xD8D050F5B74DF03AULL, 
            0x7B8661BD6DC371C4ULL, 0xAA4F8EFB71F44606ULL, 0x094E78E721F87D97ULL, 0x2E7BB085A8559340ULL, 
            0x0C945767B15B632AULL, 0x7C2F0A52393DC85CULL, 0x050D53D493151F9CULL, 0xC3178C9EE70B99FEULL, 
            0x2E16B0F25B9633CFULL, 0xA9003C79E2613126ULL, 0x71A515C862410F75ULL, 0xF683E1BE15453F90ULL, 
            0x93E84EB674323470ULL, 0x7475D73B6D91FDCFULL, 0x8245E92F52189238ULL, 0xD0AC4DD6A2D12482ULL
        },
        {
            0x68608BA79550D715ULL, 0xC566746640E5DAC7ULL, 0x7C8149259BE97B58ULL, 0x635A1BB897660055ULL, 
            0xEA86C295181A9479ULL, 0x64BCA00CD90F8D05ULL, 0xF353891EF3570FC1ULL, 0x7F8D38B968210A94ULL, 
            0xCBAFA3C20939B4A9ULL, 0xE22C450B471DB317ULL, 0x67507A9430B55AD4ULL, 0xF62534346024CC88ULL, 
            0x6BA5A45A57DDC032ULL, 0x7DC14301E4CFDA56ULL, 0xED1CD6FA6D088FA5ULL, 0x80AEA92DF9847C02ULL, 
            0x9347C72619638F29ULL, 0x7F21948598EC7C91ULL, 0x2C864EAB6E9F1DA5ULL, 0x613DFE13FD77CBEEULL, 
            0xADB7556B6C531EC9ULL, 0x851103F082110BA7ULL, 0x318B4D1F5EDDE2E4ULL, 0x8C7C892FB65359B9ULL, 
            0x1182AA00B313627FULL, 0xC634D0DC015B6AE7ULL, 0xEB065C8987A58AA2ULL, 0x8FFCD4847E85621EULL, 
            0xAA0473335729133FULL, 0xA05E1400B75BE283ULL, 0x037D72053BF59C64ULL, 0xDAFC63E2DA72307BULL
        },
        {
            0xCA21E7EDF36F7DE2ULL, 0x2FEE27F5600DBC42ULL, 0xCAEFA14E709E897CULL, 0x74B9B8B34FFD0181ULL, 
            0xB51434EA72961632ULL, 0xB1D86E174306FAB7ULL, 0xA8A3113E9CEAC87DULL, 0x183383C9C820A96CULL, 
            0xBA7A4745129E6FC3ULL, 0xBA284000EF310447ULL, 0xB246AEAE51C8BC0CULL, 0x1F45BB666C0155F3ULL, 
            0xB2C566C86CB41592ULL, 0x17DC41798F5FB7BAULL, 0xCFAFA10F4AAF030EULL, 0x6F7946FFD3B737C1ULL, 
            0x9CFD081ACC49E812ULL, 0xA913E929EBCA7F6AULL, 0xFDEBC27C166761FEULL, 0x799657DC316677D4ULL, 
            0xE7A32064A42D0418ULL, 0x334EED3DE3DC0F39ULL, 0xC628E796BE5F8F79ULL, 0x2B6021CBBFD5CECEULL, 
            0xD4F7CDFDE059CCF8ULL, 0x47D4CDBBE998AB0BULL, 0x91E85C97B62F5FDDULL, 0xF11A901F94E251ABULL, 
            0xACD22C595A79777EULL, 0x632BAAEBCE1AFFB2ULL, 0xE2339D542D8FED6AULL, 0x461E1FC68D81B569ULL
        },
        {
            0xE3FEAB8CF2C4E61EULL, 0x37B34FACFFD24EADULL, 0x1AA28A520441CB3FULL, 0x76C3BF89089DF66BULL, 
            0x8E37272179F8D60EULL, 0x93735FFF25E37EE9ULL, 0xDDB0D715A108BD30ULL, 0x37D18FA1D32049B1ULL, 
            0xDFCB648A3BE1295DULL, 0xFDAD05A278096884ULL, 0xC7C40F1B247C725BULL, 0x0B77513B9E292AB9ULL, 
            0xCD8AFC2C5094DCEBULL, 0xDCE9FA03D92440C4ULL, 0x006B7BA511F78C3BULL, 0x3CE7360795E5C883ULL, 
            0x1B6840945E05B793ULL, 0xFE7C94559D4BEC87ULL, 0x6BF815391718055BULL, 0xEA4E414A33532A4AULL, 
            0x5015B1830C3B3000ULL, 0x8D48B0AA2ABBC56AULL, 0xC5BDF5616DD02BEEULL, 0x64B4722795AE0751ULL, 
            0xFDCF72B5B6FA1FC7ULL, 0x1FE47B9209C79A58ULL, 0x7404CF77783B2AF7ULL, 0xCD977355917101F9ULL, 
            0xC4232EFAFF204F08ULL, 0x34FE2DD81E86B5ACULL, 0xA3467ED78EDFBA3BULL, 0x4080CE64071C8922ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseFConstants = {
    0x355F192FE43FAB8BULL,
    0x105F4810F5B25964ULL,
    0x2F5B2500B3707189ULL,
    0x355F192FE43FAB8BULL,
    0x105F4810F5B25964ULL,
    0x2F5B2500B3707189ULL,
    0x49245071B8E495A1ULL,
    0xD6B8C282B687AEDCULL,
    0xBB,
    0x99,
    0xA8,
    0xBC,
    0x2D,
    0x38,
    0x7A,
    0x9E
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseGSalts = {
    {
        {
            0x45FA1D29ED723E6FULL, 0xD6F793FFF0F8E6A2ULL, 0x80D9A62743842625ULL, 0x6775112DA8A822C7ULL, 
            0x318E9050F504A598ULL, 0x5DDD2C35AB7A72CAULL, 0xBD3FC649844BA3F6ULL, 0xCE9D0BEDA06E32D6ULL, 
            0x25841A9C7AF2BF29ULL, 0x82D940A53D8D7AC5ULL, 0x75F50565D7602AB9ULL, 0x344C7ECCBEDF2C9AULL, 
            0x25877E5908D906B8ULL, 0x744BC087588CC01BULL, 0x8B2D9540E357A706ULL, 0x01C68A0AA1C050AAULL, 
            0x8B362D25811778FAULL, 0x068572D5AF34BD4BULL, 0x1017A85D64ECABF1ULL, 0xFCFD0A31BF7BD288ULL, 
            0x6F315EC0102F9101ULL, 0xD09B973106E9D491ULL, 0x7B1E46CC31C4341AULL, 0x0FEC5D16AE18075BULL, 
            0x8D1EFD9968B664BEULL, 0xCE52F2E36177E25FULL, 0x0393D0B37675EFC3ULL, 0x9852148C8B6CF912ULL, 
            0xEE31B636D018689AULL, 0xD6837EE1A82486A0ULL, 0x039DDDFD2ADC7D6FULL, 0x60FB5945F4C21CF5ULL
        },
        {
            0xA0AEBFA33A2F9E44ULL, 0x02C0959CBA5CA490ULL, 0x92D370B4A65641C6ULL, 0xE574308F282E35C2ULL, 
            0xC1B3211D8F995FA5ULL, 0x32B3C6432154C30CULL, 0x20C6AF9D44115F9EULL, 0x90FDBB3E210125E2ULL, 
            0x988AB82678053796ULL, 0xD485EF69B704B7EDULL, 0xF374F5EB0239DC41ULL, 0x40BCBCBD45C9E41EULL, 
            0xFB42237EB00C6941ULL, 0xD9A117CEB16FA8E3ULL, 0x2A790BC7C0E49501ULL, 0xBD44A9C51F4091B6ULL, 
            0xA0B14A493DEA9E50ULL, 0x5A194425D09E44E2ULL, 0xE90DF796BD08DA18ULL, 0xD79F435D53D9E545ULL, 
            0xD95C3821B2857487ULL, 0x51433FD7B3162F6DULL, 0x17266CA3E3C590CCULL, 0xA95063EB1915C02DULL, 
            0x0DE07248AD84610EULL, 0x5C3E1E42F460D8A3ULL, 0x8E78319690EB0A7AULL, 0xFA3B43F2AE232F91ULL, 
            0x0771096F6ACE979DULL, 0xCD890FFC7CA5C16AULL, 0x88CEBCAFD17A05EDULL, 0x06B48B85E9802565ULL
        },
        {
            0x2C99EF5AAD135144ULL, 0x108A9B316456C055ULL, 0x6629C001D7D92BB4ULL, 0xD515C7D05B279E6EULL, 
            0x67ACBF0F5E0916B0ULL, 0xF670FB52334D6EC4ULL, 0x5774EC2E66B83533ULL, 0x02F09D8824A4C279ULL, 
            0x71B45C78F00E523EULL, 0x66758DF2F4D7E701ULL, 0xA3C4F665A8E06038ULL, 0xB7E3784DEAF0E78EULL, 
            0xE1AFB16F808C42D7ULL, 0xD9FCC6183DE148DBULL, 0xCDA6A84AD3E3B9DFULL, 0x2D5E5FC2236928B2ULL, 
            0x6916A2959C0615BCULL, 0x61E9F2759213A47CULL, 0xDD401A255B1E5701ULL, 0xB72F2DC7334AF71FULL, 
            0x166FB2B6AFBA4059ULL, 0x433079AD2CC5BEECULL, 0x0EEA7B5BE4314E7DULL, 0x1E0006113B899D27ULL, 
            0xC6B54054ED1FABFCULL, 0xD158998FD9B2E197ULL, 0x1B2F3A217AFAC9F6ULL, 0x1B74DDAC5C213BB1ULL, 
            0xE1EF2E77ED46FE42ULL, 0xE4E7BF056AB4F0CBULL, 0x762F0E01EE606759ULL, 0x1A27875FFF0C13F5ULL
        },
        {
            0xA63639FBB352A640ULL, 0xC8E422AD64EFC0E9ULL, 0x9A12DF8865BE5097ULL, 0x487655D89570DF32ULL, 
            0xBAF300596C380242ULL, 0x77159A3C70E53160ULL, 0x14809D3BDFFF5C15ULL, 0x32A3B1584AA4CC59ULL, 
            0xD2DB7189BE2B6BABULL, 0xEC2467C76B547786ULL, 0x344009332CB468A4ULL, 0x95A0458AB69A577BULL, 
            0x1C5EFCE86DE28FEAULL, 0x092C06E96359BBA9ULL, 0x7476F46F63996AFDULL, 0xD22E77706EF93398ULL, 
            0xF1C609E510377350ULL, 0x0B9EDC14F2FE1CC2ULL, 0xD6DCC841C0D08E19ULL, 0xE256E6E196F7BB3FULL, 
            0xB9ADC7F714BC51FFULL, 0xB86F59B4BE060841ULL, 0xF4210DE34A315F85ULL, 0x67984D2B126EC5FCULL, 
            0x262747731146C76EULL, 0x814EB521D0749911ULL, 0xE189601609E3FEDAULL, 0x5ABA39CEB7FF5A43ULL, 
            0x0CB09CC37A0C11EDULL, 0xF1684AC42A928CCCULL, 0x4536407190BB6402ULL, 0x835A10669A9C5AACULL
        },
        {
            0xD1FC9BA44143A60AULL, 0x350FD9E2FA8DEA18ULL, 0x8DD1EF2BF30E947BULL, 0x7D985AA21977BC2DULL, 
            0x5D1056E74670024DULL, 0x80BAD979DF317EC9ULL, 0xD255BDDB7D7716BFULL, 0x601EDF9DEF9A0B5CULL, 
            0xFD57D7155A0E1228ULL, 0x67E330CBD15F103DULL, 0xD57BA32987A9BCFAULL, 0xA90F7F885246AD59ULL, 
            0x541FBC9D8FE87996ULL, 0x9C2BF3757A3CA0FBULL, 0xD77C88F15715F178ULL, 0xC572D8DA3FC069B9ULL, 
            0x999278A0DF095BBFULL, 0xFC3A5FC6D852F299ULL, 0x04BFC8EED482AA40ULL, 0x47F6D82EED5F21F5ULL, 
            0xFDD51173A61541ACULL, 0x930F1E75D9FACC91ULL, 0x0434EF1D66C0BE48ULL, 0x27332BD90D856E08ULL, 
            0x4975F2023A256D99ULL, 0x5D812F2AE09ADAA2ULL, 0xEA325F83FF27ED61ULL, 0xD9BFE00373C935CDULL, 
            0xA43F797671F51C16ULL, 0x627A91E4045D195FULL, 0xF2773B4AC85CC142ULL, 0x55DB00FF2E8E1B23ULL
        },
        {
            0x4EF20F1BAFDF796CULL, 0xD3CC79EEEF45DE2BULL, 0x8214039053F3665DULL, 0x4DD8000ACF40858CULL, 
            0x3B056BB2046F5828ULL, 0x6A88545A9589D548ULL, 0xE7723EBF2BAC55A5ULL, 0xA7FD284527C1B0ABULL, 
            0x4D60651E4115ECCCULL, 0x2578AFCF9CB90BDBULL, 0xF429741E4FF15957ULL, 0x09B250A5278A04E0ULL, 
            0x8133FE43B87DE2C3ULL, 0x7E1AC6393E5D1AD8ULL, 0x5ED0E995DC46A0E4ULL, 0xD86F71D12145F18CULL, 
            0xB23972DD565BC593ULL, 0x487DDE6CC35F9816ULL, 0xBCB25C39D15725C5ULL, 0x4BDDF2B9C4B37442ULL, 
            0x350956F71913833FULL, 0x0731279E5964330CULL, 0x0671C0545A1AF6C3ULL, 0x9AE01DA9C1A9A128ULL, 
            0xD01598ACA098502CULL, 0x72530DFD403EB9E8ULL, 0x1627A225752810FCULL, 0x9C916D1DBC06F704ULL, 
            0xEA5654B4275BFF1BULL, 0x35206B3469BAA8F0ULL, 0x2F963E05BB74E14BULL, 0x05C3A321F7828131ULL
        }
    },
    {
        {
            0x190661C86FBD4B69ULL, 0x5FB93A64A5B53DDCULL, 0xCFE51B0730F5AB53ULL, 0x571B11A6F56CED14ULL, 
            0x237A1E6207EA25F1ULL, 0x11D9B8E7D326D705ULL, 0xE6A15CEC9A4C6CA2ULL, 0x9577A59C94DB427BULL, 
            0xD0F222C83947B6F7ULL, 0x2BC89F62B8AE1C96ULL, 0xAED9F67AC59386C1ULL, 0xDE97E3058C1F5B33ULL, 
            0x503CE1E5ED3F8089ULL, 0x241F18E909439316ULL, 0x1106B2CE1023E317ULL, 0xA57C3E07BB54170DULL, 
            0xA8D45CD32BCD28F7ULL, 0x1F364692B9A9EB57ULL, 0xDEB7295E8860EDADULL, 0x88CA8DD8F21E4CC1ULL, 
            0xE9234E30581D8BDDULL, 0xC25D0418AC7D6A64ULL, 0x0EDADFB1C5660629ULL, 0xBAD92AB2B2F6BFADULL, 
            0x35D2000B9C358BFCULL, 0x19B38DB27EF976E8ULL, 0xA3F9AF78502B2BDBULL, 0x8753867AA2211311ULL, 
            0x8DD8D9E3EFB7A482ULL, 0x5FFAD014EE6F9A2BULL, 0x1D7D5FD7D8BA3217ULL, 0x32901D1286D49F4BULL
        },
        {
            0xEDA893869F385FC0ULL, 0x4B92712E24995263ULL, 0xF98BF96D6AB6C923ULL, 0x8B1572B595B35D76ULL, 
            0x8194456DF9349DB0ULL, 0xB6FBD48D82CD8E99ULL, 0x7667BA812CAEC4E6ULL, 0x813E4E6FD321AF67ULL, 
            0x752C9082A3CD4F70ULL, 0xACA4B556F1E6DA6CULL, 0x81FB4DD919BA8785ULL, 0xFDFF0058688BDD85ULL, 
            0xCD71B2D4790F04ACULL, 0x46B2685CC5C6E907ULL, 0x35507283B2C01599ULL, 0xBF509AFBB7436AE2ULL, 
            0x685B2AB473C35FD9ULL, 0xA32EE1D36B368A61ULL, 0xEF9A7CBA9E7B82C7ULL, 0xEAB56D4C319E06E5ULL, 
            0x770602A2450DB7DCULL, 0xF0A44DF67BA286EFULL, 0xD37C85D2009467E1ULL, 0xD7F4D0493B19BC6EULL, 
            0xE7250D87D0096DF5ULL, 0x44F3E09B71F87D5BULL, 0xADBB522970A6A2E0ULL, 0x6F530D8CF7C020FAULL, 
            0xC3242A46B45F7E9BULL, 0x281FF9CE3C8CCB95ULL, 0x9D45EA42045FC6A7ULL, 0x0EE0593A765C7E02ULL
        },
        {
            0x477C1C0DA96C7F0EULL, 0xB8E457341F8507D0ULL, 0x9C7ACD14D39FFAFDULL, 0xD825E7DF6F23C0EFULL, 
            0x70D565DF1B6B7647ULL, 0x935313800898F91DULL, 0xBE271BECA9BA163FULL, 0xC90568900FA5E9DBULL, 
            0x3518B5C8248B90DAULL, 0x067809AC9B0BEE40ULL, 0x7F72B1A2ED8FDE52ULL, 0x7573E16F01F24AA2ULL, 
            0xD3F6CFE73687D192ULL, 0x8C6676C65F2F0D9EULL, 0x21BD7F0208A36A5BULL, 0x708EB44FE05A07C5ULL, 
            0x1D67239B9D49B6EEULL, 0x53F14CEA79CAF300ULL, 0x3F1163E5144D109CULL, 0xC30FCE9DC0AD9408ULL, 
            0x0907F2833ACF4FE5ULL, 0xE89B561AD2501C06ULL, 0x2ED625A8F66C3D85ULL, 0xEB3A4DB3F4811282ULL, 
            0x83915DB3B7384890ULL, 0x4BD3FBC07D63FD8AULL, 0x7701E50749F377C5ULL, 0xA5B9F6C14B876F3AULL, 
            0x7F75AFAEACC663A0ULL, 0xC2646DF6136599B6ULL, 0x8EF8358169C0518CULL, 0x7D22B6AC18D91244ULL
        },
        {
            0x1FCC9D8E5439573BULL, 0x4AEEC3FDDFBA6775ULL, 0xA9FD3ADF181AC312ULL, 0xCCD1B7805A733D10ULL, 
            0xF2BE8AAC286FF7F4ULL, 0xE3F3E000BA451A8AULL, 0xFD0656372072AEC6ULL, 0x680FB6CEEA0A92C7ULL, 
            0xE9C57DFEB07DE2BAULL, 0xE359B0DDAECD1E09ULL, 0x430A8320F16283CEULL, 0x12663ABD9E6543B7ULL, 
            0xB48EE5DB330CF871ULL, 0xE3D53F8CA8039C92ULL, 0x24503C4A5D07E93BULL, 0x12C1E9854A7A1BFAULL, 
            0x22B6D758ED5B16E4ULL, 0xEC174DAD62D770B2ULL, 0x5C3199806F9B7369ULL, 0xFF95B4A5B81D4FADULL, 
            0xB086A6C338777369ULL, 0x39AAC201B23A2643ULL, 0xFAB7D51DDAD07F64ULL, 0xA3E5A4AAD39016C1ULL, 
            0xFE34C9054BC6ABB0ULL, 0xD2A6C7D03DC2BA1AULL, 0x380F3F27CCC18D11ULL, 0x4BB60BC4F04FF476ULL, 
            0x0B70BD51217DD783ULL, 0x64C0026046812A1EULL, 0x37E8A066C0C6A094ULL, 0xFE370C5199518452ULL
        },
        {
            0x6CED744DA94DC03CULL, 0x7F52408FF26A7C90ULL, 0x54D547C5F285EADBULL, 0x9EC8259305AD4B61ULL, 
            0x581E4BD790FBCC0AULL, 0xCE7343B0C9CF46ADULL, 0x723600F5353CE43AULL, 0xA8D80848C6C54455ULL, 
            0xF148A12AD2824B37ULL, 0x94F306E167DA9F37ULL, 0xBD7B83A000B94A6CULL, 0xBBCF51F024CAF7ABULL, 
            0xF9BF2AF2A79AA67FULL, 0x0545AAA3974F5D87ULL, 0x186329D1CE1C6A4BULL, 0xD59F74BC6349DBFAULL, 
            0x6A3332864C4BF914ULL, 0xB6AD4016A677C6A4ULL, 0x279522F7CFCED70EULL, 0x7F2149419CF901F5ULL, 
            0x03C28BF7991A9FDDULL, 0x77BA8ACF074243B7ULL, 0x702C00D060A343A7ULL, 0xD178E57C16FBDE67ULL, 
            0xFC27AFAE44B4374DULL, 0x01EF3CA1A8F6B79CULL, 0x7B7A74C3DF703E25ULL, 0xFB0DA7CF39B0FEC1ULL, 
            0x7E22B1BD5BE11D07ULL, 0x6A4E64090E2A8512ULL, 0xE24022E636D7C62FULL, 0xF48B65BB1B70B139ULL
        },
        {
            0x09927BE5A5692995ULL, 0x05A726900F4EB357ULL, 0xAA7B0CD23D7DCC29ULL, 0x93C64E1EE7E804C9ULL, 
            0x3415F09EDF0F64B9ULL, 0xF67F7ACA4449272AULL, 0x193C639D90059FFBULL, 0x3D9D1B16A1EB760EULL, 
            0x2A054095D6D70149ULL, 0x81A9F2C18535F36EULL, 0x052F617F886CE5C3ULL, 0x2147563230FB9D41ULL, 
            0x22A1FBF5A96E6D71ULL, 0xAB7B8D567CA7F54FULL, 0xA72346941C2C77CDULL, 0x0AC4A8A8033D5596ULL, 
            0xB9A95D6C6A9BA83AULL, 0x4FD9C7E3C62C0FD0ULL, 0xF0DC699A0F3AE770ULL, 0xD15BD7FE98C2E2E7ULL, 
            0x70324B599E691580ULL, 0x1EED6B8D70623736ULL, 0x0441A845D32B5FB7ULL, 0x732C077084778F28ULL, 
            0x17876FFE0239328CULL, 0x45C10D6A57FCED05ULL, 0xBA4379DF67E8D2E4ULL, 0x7521FE004FD2A2D2ULL, 
            0xEC91DAA1A6229419ULL, 0x9DFAFA6323C4FAD3ULL, 0xCF510F3074936862ULL, 0x049F47E46C4DE682ULL
        }
    },
    {
        {
            0xF9F37F11FC57F9F8ULL, 0x3FE73BB5274CD527ULL, 0xE5579EF263A5725FULL, 0x61579D855061810BULL, 
            0x589720B0E91C3CFAULL, 0x2F6E0ACB3B23E76EULL, 0xE49F632EA3CDB3F4ULL, 0x2C008FB8EB272639ULL, 
            0x25CBE6C427EECFD5ULL, 0xE1FFC0C71FF253C7ULL, 0xF3B013D597F425C2ULL, 0xF7F38EB1231EAF8CULL, 
            0x894B1F6BF8EBB09CULL, 0xB312A4B7835D829EULL, 0xC217F96ADFAAFD4FULL, 0xA2788F2EFBF31C9AULL, 
            0x170B7E68E4216827ULL, 0x21498CB08D266B9FULL, 0x1AB288F9EFFF3A2EULL, 0x3E7A1A5EF7A7F314ULL, 
            0xECCA9124D65A1663ULL, 0x52D346E2B6263F75ULL, 0x8DBEB25BA5990186ULL, 0xE1604C742078DF6CULL, 
            0x5A6915C962C84CFAULL, 0x9460DECAA0698EB8ULL, 0x48727141973CD905ULL, 0x0B7FD552B499F5FEULL, 
            0x9E6EBB8EAAC6A502ULL, 0xB82D7795703E8E47ULL, 0xE68A9968E63B26F3ULL, 0x4ACB6E0232715C7EULL
        },
        {
            0x798275094EF31EE4ULL, 0x9CDC8CBBBBE0F205ULL, 0x33DD51D938729B0FULL, 0x02713EABD3DCB491ULL, 
            0x0A5BC32E01D3A5BDULL, 0x08DCE060F941ABEBULL, 0x93618DAF269BDFCDULL, 0xB964208ADD36C9AFULL, 
            0xD733B745CECEFD71ULL, 0x023B0ED34537DCAFULL, 0x3C804F208024571CULL, 0x54402A0F7620CF5AULL, 
            0xC2900D6160098F0DULL, 0x9175A66CD1112DA8ULL, 0xFED0E7E0B8070A18ULL, 0xE604D4DB58EB3524ULL, 
            0xD033073A9AD0D2FFULL, 0xBC213D184E8F6B10ULL, 0x7585DBEC5A65195AULL, 0x6AA2EB34B8A9C0FAULL, 
            0x637294C256A73EA0ULL, 0x0413DE030D3685B5ULL, 0x9FF47EC0AED16EBDULL, 0xBA6E8CB349D17360ULL, 
            0x78ADA63FD024B491ULL, 0xC05D666A9DF4994FULL, 0x1383F79B70CF8F69ULL, 0xB5DABCE3C6E50941ULL, 
            0x3D904F98D10EB0B3ULL, 0xCECA52B4F0F4D2D5ULL, 0xA0AFD2E181FD5969ULL, 0x27ED6E755DC83EE7ULL
        },
        {
            0x98B17D70BFF18C5AULL, 0xB1F5D8316FDF7C9DULL, 0x9DB56584FC768F5FULL, 0xA1E6DA7532DC7C15ULL, 
            0xFCA1AD1BC1808C67ULL, 0x35FA99C01CF40821ULL, 0xC550967F46088125ULL, 0x3586C5DCFC0C571AULL, 
            0x4F5421E1839D5A08ULL, 0x8EED32BF5971F6F2ULL, 0x0E4DCD300D498E37ULL, 0x835B69893E797C95ULL, 
            0x6FF59A8027A5CD22ULL, 0xC6025172E430FFE7ULL, 0x115845AD60B2EA90ULL, 0xDCA7F9076A1A1419ULL, 
            0x1D31BE2B7BE979BBULL, 0x29F18CDD8A82B531ULL, 0x8F11AA4A01C3DCEEULL, 0x718A6189D67ED078ULL, 
            0xC8702A8D3AD7DF58ULL, 0x6922F57D74975514ULL, 0xA34504697915E75DULL, 0x36ECEB11DB56EE49ULL, 
            0x4C30D07F168899FDULL, 0x11D3EFEE02D8CB47ULL, 0x37E50E155F28CF70ULL, 0x784EEE4766FB23C6ULL, 
            0xF4F9D70489975735ULL, 0x9721F642BD306D33ULL, 0x062B3659FC8210B7ULL, 0x24A74E9F9B2B558AULL
        },
        {
            0x996809F1D43FC646ULL, 0x70CA28E3F7DF96D6ULL, 0x58F6A28B030335AAULL, 0xDBADBE3B18326EA5ULL, 
            0x4590ACF98DE62459ULL, 0x97346859391A0FB8ULL, 0x25500D65BD02C36EULL, 0x5BDEBE8220FCE3BBULL, 
            0x7E7AA3B35DFEEF6AULL, 0xBD419CCF6475C765ULL, 0x4309C6F62B2105BBULL, 0xF9AC37B42D1B3B11ULL, 
            0x8E3105B305CAC67FULL, 0xD876C0E77C2893E1ULL, 0x7D8747941A649E75ULL, 0xA7CB7C6D7F507313ULL, 
            0xEA47BA12204EE3C6ULL, 0x54B67F3A48BA9B42ULL, 0xFC5C9E39D3EDB891ULL, 0xE47EC8E93C1D6A4FULL, 
            0x0827803DC339DCF1ULL, 0x9D3F2118FB34F57CULL, 0x98CDFBFD8A2E2947ULL, 0x851E9EC9F562E6C7ULL, 
            0x9E592D2E31127431ULL, 0x7751FE1A3A22E7F8ULL, 0x567EF1982BA4E010ULL, 0x4D0B0C9DBE541F3FULL, 
            0x3506FBC151B0D322ULL, 0xD69C6E4A9A261BFFULL, 0xB628D5B98CFAA9EDULL, 0x3DD1DF285DCD83B9ULL
        },
        {
            0x1ED0D7D599906F5AULL, 0x9D6B2025C8AE36BAULL, 0x9471898959DC4AB6ULL, 0x141E8A2279163570ULL, 
            0x98A6E345E7A3909EULL, 0x0F791CC16C6A058BULL, 0x9A3F5C231B0E11E5ULL, 0x3BF05A19E853A5ABULL, 
            0xE7F77761FF5E6B6BULL, 0x884710865C7D1F1BULL, 0x606817C245EC3CAAULL, 0xA4B3DEBDA68BEE31ULL, 
            0x3B7E6A4FE3413D75ULL, 0x6F65F8A1D7665CD6ULL, 0x3D00731A039B1846ULL, 0xEC5B35A16E3FC269ULL, 
            0xCC09B1147E152E68ULL, 0xEDE0B17F28723BDDULL, 0xA9AC4E66F52BBBCFULL, 0xDBBCDE7169320997ULL, 
            0x33DAAAACDD4CD90FULL, 0xB389033E232E2DD4ULL, 0xB06165128EC1D9E5ULL, 0x74FA2DD4C122CE7DULL, 
            0xA28E417BB638E092ULL, 0x09CE79FBEB178616ULL, 0x8A5BBDF025459EC4ULL, 0xE67A13E33A2B7DEEULL, 
            0xF149482CD5A1BCFBULL, 0xB8F57DE247DE688DULL, 0xD6A62CF67867C62AULL, 0x958CFDDB226561ECULL
        },
        {
            0xEFE2625008E5EB37ULL, 0x7B690A2AED39B209ULL, 0x77246D6555F48102ULL, 0x0A2037B114D76115ULL, 
            0x8E33FEC96AE8D474ULL, 0x4E0D3D2613BFF07BULL, 0x2E7F7C468BD61603ULL, 0xD0CD4C06653F3622ULL, 
            0x84CDA41C975B90B1ULL, 0x3D83A7BA0FD7D9BCULL, 0x6F95D31385C416ECULL, 0x9E827DADFB62B3B3ULL, 
            0x620A012F22242E03ULL, 0xE2208ED34065C9D2ULL, 0x28A179F845252362ULL, 0x32A0A901245FF135ULL, 
            0xD04621CED91937BBULL, 0x0E8335F2D71E403CULL, 0xA422A3937BE20DAEULL, 0xA381E1AF27504808ULL, 
            0xAD7E684D248C7013ULL, 0x1FE2B37B58F32FF9ULL, 0xDFBD0B4A201D73BAULL, 0x7CFA5FCE3EC14C74ULL, 
            0xC4E53646A5BD714CULL, 0xF54D017E465AA05CULL, 0x4C3CB5E81323CB13ULL, 0x2911CA35CB1957EDULL, 
            0x50B9D1DD11B6C2AFULL, 0x1866F88C22A4B591ULL, 0x6E7AC1565E36FF1DULL, 0x4E9259DFE0FEE1B2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseGConstants = {
    0xEB97AFFD4457FB8DULL,
    0xCF5D2397A0BB86FEULL,
    0xABE2BF27413441C6ULL,
    0xEB97AFFD4457FB8DULL,
    0xCF5D2397A0BB86FEULL,
    0xABE2BF27413441C6ULL,
    0x03AFA0391BF3421BULL,
    0xACE09D2414DEC828ULL,
    0x39,
    0x1B,
    0xB1,
    0x01,
    0x15,
    0x2C,
    0xE9,
    0x87
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseHSalts = {
    {
        {
            0x276C9F93969BC599ULL, 0xA1737165EC0AC77DULL, 0xC1EEF24C38C90597ULL, 0x928C6E66119551A9ULL, 
            0x570D3D320E85DDAFULL, 0xBA25149C3539B1ABULL, 0x4D1EAA813880DAF0ULL, 0x2512A23A8C8B8D68ULL, 
            0xCA829754F19638B7ULL, 0x68B704DF9E5115E8ULL, 0x5FCBDF782D4485C8ULL, 0xD9EB233F7C04115FULL, 
            0xA51ACB006FD8DBBBULL, 0x0E08C966FBACC495ULL, 0xCFBFB89877690A43ULL, 0xE28D732620FAC090ULL, 
            0x0130E22C15003BA3ULL, 0x04396C8630278070ULL, 0xB32244F4D875EC41ULL, 0xDE138AF235AED68DULL, 
            0xED567CF22081E9B3ULL, 0x3B51F9CA8BE738D0ULL, 0x70FA5CA0E379C10CULL, 0xA3EDF133EB8B3BC0ULL, 
            0xC314CCBAD82F7137ULL, 0xA65E9C5F18DECDB8ULL, 0xACA12E685602879CULL, 0xA497FC388C770A79ULL, 
            0x24050E26F5529399ULL, 0x6124E41104149A84ULL, 0x18D7115D99B85D61ULL, 0x3C5981A98A034147ULL
        },
        {
            0xF57ABC3CE943DBEEULL, 0xF52A65FF97BFAA89ULL, 0x04509B062F450BDCULL, 0xEF200AC1DA3A9D60ULL, 
            0x59439F0A6364B734ULL, 0x263ADA656B073F09ULL, 0x0B330CB2A5BFFCDAULL, 0x40DCA55014BC871AULL, 
            0x8E6FCC250A99D9B4ULL, 0x1C929FDFF623A2ACULL, 0x1EEE9B1932A04FD8ULL, 0x9B6D3CBCC0FE001BULL, 
            0xBC342481E48A2F79ULL, 0x268CD3397318D990ULL, 0x09BCEFE3552F238FULL, 0xA96FEFEF47BECA7BULL, 
            0xBE49BBB2997A76EDULL, 0xAEAA09E8AC212718ULL, 0x437FDF9ABC9C0961ULL, 0x33F18960467636E4ULL, 
            0x8A1BB3B1140A1210ULL, 0x5F287B24EE66C06EULL, 0x09B618456B37514AULL, 0x8A5A57B9FC8CBC69ULL, 
            0x08A51EBFCF4C7493ULL, 0x291A81AA75568ACAULL, 0x100EFF9D5AFA838AULL, 0x9242051531488546ULL, 
            0xB146A4AE7B7A742DULL, 0x53EA76E1BD30DCCCULL, 0x4C88BED2CC976572ULL, 0xE2AF182FE740BF2FULL
        },
        {
            0xA70A1F36A310D32BULL, 0x64C4750E61B77E19ULL, 0x04C0B257DD756FCEULL, 0x9A211E398B938141ULL, 
            0x7EE4B5B0DA20DA2CULL, 0xE95C44E3BD4B2494ULL, 0xD41274FDD31F7C88ULL, 0x08AC1B982731BF93ULL, 
            0xF5FFC92D8A7BFA79ULL, 0x6D3494997462A680ULL, 0x24170DB993379942ULL, 0x87A7F396FB25EACEULL, 
            0x71E508CF3A798B9AULL, 0xBBCD8952A232EA17ULL, 0x53AEA1C9ACFE5409ULL, 0xD72E736B2F37C6EAULL, 
            0x17687640EDA153A0ULL, 0x17AEA6031AE06B43ULL, 0x5896D81529B2EC80ULL, 0x81148B4AF9CEDC8AULL, 
            0xDB7C2BD7A4B86817ULL, 0x299C8188F0D8BFF5ULL, 0x14ED47F09BFCFDDDULL, 0x17E2882D529F067DULL, 
            0x16AA7F60FE509281ULL, 0xDA992133086A24E3ULL, 0x0C6577B655AEFD19ULL, 0x948C2BCB9874DA44ULL, 
            0xE2B6B85B8A16EE61ULL, 0x06B006C034B78FABULL, 0x81383218D85F7AC1ULL, 0xF937E4EBC6E485A2ULL
        },
        {
            0x6715499E27CD2A7AULL, 0x0834E323D78EF1CAULL, 0xD6551B3F518A17A6ULL, 0xAA1F9C5AD30DDE95ULL, 
            0xDC913B433F4D5A30ULL, 0x829E9D02BABA611BULL, 0x563E1EE89F8C0E55ULL, 0xFDE7728EFAA2D592ULL, 
            0xDF21F1355A27C937ULL, 0x9F7D079D9FBF56D7ULL, 0x9D5369287D2E7199ULL, 0xF3BD071A90A11E63ULL, 
            0x44963B2F0CCD0A2FULL, 0x67DD5F30E24BD56EULL, 0x4C082059AF3A75E0ULL, 0xBEAF860B658F287FULL, 
            0x24EA95A1AD51120DULL, 0x3F950F61044FAEACULL, 0xF53B936140D55481ULL, 0x35147BFC0CA03584ULL, 
            0x7F09A84A5B7F9F82ULL, 0x4B60CE3C90C13B99ULL, 0xEFB4D17672D807F4ULL, 0xBAA9885976A82022ULL, 
            0x2CF230F8FFB6DFB4ULL, 0xFD895D76C6620849ULL, 0x59F18E464537CBBFULL, 0x188CC09C301DFEF8ULL, 
            0x31A99A2D131E613AULL, 0x3C408A2DB086D7FFULL, 0x3210B444F478803EULL, 0x7405A07786D2716FULL
        },
        {
            0xB43D5BC9A5BA5007ULL, 0xEB05AD89FDDE2559ULL, 0x4D9F273CCA0B854AULL, 0x9A25F769CD147844ULL, 
            0xE1DFCED159B5B7B0ULL, 0x683F680722CF8D0BULL, 0xBF10474367C8529CULL, 0x2075B2F0DA22BF14ULL, 
            0x12499BFBC2CF370EULL, 0xCBDA0F58BB94A3BCULL, 0xA9EB8C612F4DE333ULL, 0xAD9BEFF3ED02B183ULL, 
            0x1BC5240B66FF13EAULL, 0x58D0EF5FE69E269EULL, 0xDFE6BB5DA0079D69ULL, 0x034EA42329A0DC17ULL, 
            0x0D8C9F8B2296E3C2ULL, 0x8FE081DAD7A13DBBULL, 0xE0DCFC25061DA233ULL, 0xC2C045A9B34537A7ULL, 
            0xE22FC61D5009A364ULL, 0x51B36861008D3945ULL, 0x87749F0F7F01E1E2ULL, 0xCF59228D52372B89ULL, 
            0xC1D5EF340E9D70FBULL, 0xC72A653AB5F55799ULL, 0xFABB5D4B13849AD6ULL, 0x9E4C5F303EC022E9ULL, 
            0x2FC3614BAE3377FAULL, 0xD68E81CC30B393A7ULL, 0x7EC309CF998877D9ULL, 0x4024274FB7FF7FACULL
        },
        {
            0x01A3B6DE40E9E11DULL, 0xBF29BFE9E4DECEF4ULL, 0x4C41E1B298EA3894ULL, 0xA21E9E24E0CAA90DULL, 
            0xDE2FF3F1BFEEEAB7ULL, 0xE138431D4BE85F07ULL, 0xD887515E2027D8B5ULL, 0xB23F88D2A952661DULL, 
            0xA72600F01D283CCFULL, 0x37C721B6A15714B4ULL, 0xBCDD58004C695852ULL, 0x371AB81F5D2201DAULL, 
            0x51B5823C11C9E886ULL, 0xE1B5F2DE2F0BB57DULL, 0x76D5EFC47FAC40E3ULL, 0x259B6EC60486F9EFULL, 
            0x54B50471927AAA3DULL, 0xFF49AD8F17252613ULL, 0x39D7216CB5FBD321ULL, 0x66AB30DC0B4C5CF1ULL, 
            0xB0364CF7A11F31EDULL, 0x143ABA936975BB4DULL, 0x903AAF322B021C5AULL, 0x8F1095E99BF32EBEULL, 
            0xC129FC9E0E75B5E5ULL, 0x70964770B7AD75D3ULL, 0x55A3D87885A8D01CULL, 0xABA9A652656EE1FEULL, 
            0xC42CCDA35BB6B1A7ULL, 0xC4ACB88C6190D646ULL, 0x0BCEEA08E200E21DULL, 0x75C9B82685EF1595ULL
        }
    },
    {
        {
            0x9B105A2AD8D447E8ULL, 0xC1A81A7D73DDDD4EULL, 0x98BD6EC32EFBBD4AULL, 0x73DD506FA04FD1AEULL, 
            0xD55FE743A411BF94ULL, 0xDB4E99E39DB843E7ULL, 0xCC2DE1BB548DDB80ULL, 0x126987CDCBB771DAULL, 
            0xF3091EF332C61EF8ULL, 0xE6C679B2EC989DDBULL, 0x067C9194E485A3A8ULL, 0x968A3C29BC346943ULL, 
            0x616FDF68056B8A07ULL, 0xEC5C59B2E3B48CA7ULL, 0xB7817C4EB3C634DCULL, 0x95BCBB2BF254DCB3ULL, 
            0x4FA72F0EBC1F1A87ULL, 0x6323BCC3E01DF7B2ULL, 0x5A16F2D48C12A3AFULL, 0xA6B980AFA76A0219ULL, 
            0xE2C8270C87279FFAULL, 0x6157A19FA45D657CULL, 0x6F89114C831ACEB5ULL, 0x47F58386B2B0A729ULL, 
            0x9B0AF23AC520D47EULL, 0x4AF32986D56E84F4ULL, 0x27131808EED694F5ULL, 0x79963CCF3003A807ULL, 
            0xE62756ECE78D6876ULL, 0x096BE1E3F5A03906ULL, 0x4B3424706B44CE75ULL, 0xBB9E32AF82C004C6ULL
        },
        {
            0xE7FD8C6273BB9AF5ULL, 0x60C81D0329671F11ULL, 0x1239004440AAFAB5ULL, 0x201E476901DB6F36ULL, 
            0xB2A24588AD2DDE06ULL, 0x7EC376241400250AULL, 0x21E209DA0E552D17ULL, 0x3B19A38A952605F1ULL, 
            0xEA2DD0C525C8E8FCULL, 0x97FF19B9826E89E3ULL, 0x154ABC8DE596D7BBULL, 0x48E36811413EB4E1ULL, 
            0x87035596B4F4BA56ULL, 0x9D3FB5D58002FD8FULL, 0x7AE321043FC4DCC1ULL, 0x4C772F367B48543FULL, 
            0x52CFB2FD13D6791CULL, 0xE4C5998062AAE4E9ULL, 0xD66C31C2731D59D8ULL, 0x7927C280E1023CEDULL, 
            0x3150FB22875B31E7ULL, 0x0FE6504E684BE5BFULL, 0xEE25406D4B3D7C9AULL, 0xAA9219564DD9DAA9ULL, 
            0xFB02866A2754F5BEULL, 0xB25713E6A5161080ULL, 0x85234099675E5354ULL, 0xD4A41BD973CDB264ULL, 
            0x3A23C920C9D6BCD7ULL, 0x2BFA0AB37E6A41FEULL, 0xB2E837501CCD1C9BULL, 0x26EF276A2C4623FFULL
        },
        {
            0x4FF6A09975F0D0F3ULL, 0x4030A1F861DC61BFULL, 0x27D632B630A3FBCEULL, 0x7B577C2127FEB32AULL, 
            0xFC4CA739E023A059ULL, 0x0F0BB8CC9C63ED5BULL, 0x1811221C2BC8AEA5ULL, 0x351B89632C8D0C94ULL, 
            0xF70395E0AA90C13DULL, 0xFCB19BEBFFE887CBULL, 0x767F6A2461EE61B2ULL, 0x6617697A11B1402FULL, 
            0xF909E1451DA23607ULL, 0x393044208A7212FCULL, 0x5B823B46A63A0757ULL, 0x64272AC1E1C5D1AEULL, 
            0x5B8D2BFC88078889ULL, 0xF09B13F2C902A645ULL, 0x16FC30D95630D3ADULL, 0x6BC40A0FF4BF4D11ULL, 
            0x87DF1F4E3DF19D07ULL, 0x3927315145042BACULL, 0xB0AA7CC8F3403598ULL, 0xB0ACC82A9F99AFB4ULL, 
            0x6CF1CF3AA660690DULL, 0xEA8DAC861C4A1C35ULL, 0x1ADEF3F0AB6C55C9ULL, 0x9FA500926D66C35BULL, 
            0xE2B51949942FA6AFULL, 0x81481FB2B30CBF02ULL, 0x3C4A237462C31C97ULL, 0x59D060E9355C4DE8ULL
        },
        {
            0xEB26F7CB24E2893FULL, 0xFCA492FF4BD2C5DEULL, 0xFB9D94D71C1D3E87ULL, 0x31DEC918BFE69635ULL, 
            0x74A82953DDA3DF9DULL, 0xA5320CDB11AC417DULL, 0x0D34BF8A0A178966ULL, 0x76A545E9843C199AULL, 
            0x8ABA21CD07BD0161ULL, 0xF28F11CF575CB710ULL, 0x11DBA1C3FF761FA7ULL, 0xA21C866ED9457A4EULL, 
            0x5F75C8C329427233ULL, 0xE31A00527B0684E3ULL, 0x5D7386860E8D46F3ULL, 0xF11867383AF0FEFAULL, 
            0x036EF0E65570808AULL, 0xD6C057D8033AE722ULL, 0x9E25DF619DAC6C17ULL, 0xEC260130711F35F2ULL, 
            0x2E898F9CDB0B46D1ULL, 0x5AA20D64EAE8C42AULL, 0xF460057A532E2B4FULL, 0x099730A88A2EB763ULL, 
            0xBC7E818E13B296C4ULL, 0xB5064E6588C1418CULL, 0xD5B24393E12346ABULL, 0xCF9EFFEFAA00C38AULL, 
            0x5D62B6E6AB862B89ULL, 0xEB93E511D0C990ECULL, 0x5F34D78508DA77B7ULL, 0x0E08E9B2A842F4AEULL
        },
        {
            0xD7213F377D551DE2ULL, 0x47AD4D12207AFA7EULL, 0x47912913CD5739C6ULL, 0x4A1D4EDCFEB33B9FULL, 
            0x6BD16D9DAFACF975ULL, 0x293864E792E9BA1BULL, 0x63C28D9DA283536EULL, 0xB81D9FB29591487CULL, 
            0x0692624B351A2FDAULL, 0xB1B2AB4CFBAD8B31ULL, 0x0D7D8375CD945A50ULL, 0xA4076486796E42F0ULL, 
            0x6D1CFB805C38FC46ULL, 0xAE1DDEAF246A2904ULL, 0x86A66B56BFC00AFAULL, 0x2531F9C72C95A138ULL, 
            0x374469458038A0DCULL, 0x79B6C6A5721467B9ULL, 0xAAEEA1A01A81E29EULL, 0xC9A6AB49DB02A2E6ULL, 
            0x7967D9E527F500EEULL, 0xC0F4ADB5F6120454ULL, 0x5536AB248A5436E2ULL, 0x63C1B14F45F064D5ULL, 
            0x99B0FD6C3DE157C9ULL, 0x4074AE6273A09648ULL, 0x0469A362029C7B81ULL, 0x3C9AE23063652381ULL, 
            0x0459E1E99A73B30AULL, 0xA01ED3703E413DEBULL, 0x05BF20F85B7920ADULL, 0x59DDB5AE9173865FULL
        },
        {
            0x7A383BA3848202B2ULL, 0x28A14BEDC9564B57ULL, 0xE733DD2C41710FB3ULL, 0x65B5324F7E581331ULL, 
            0x61CE2EA7F9BC7EB7ULL, 0x68231D9A10C45552ULL, 0x28238134BD39BF2FULL, 0x3AA7EF89FD36E0B7ULL, 
            0x635B2D4EAA23D15FULL, 0xA1F9160E6F8B0F3AULL, 0xCE86E92676C7D6A5ULL, 0xFAB93D71A88D9560ULL, 
            0xD259F5A2EB0936C2ULL, 0xB274A63DC49763A9ULL, 0x87CFA47B64B09B44ULL, 0x90680E0B372ACA46ULL, 
            0x280A7F20AA023F61ULL, 0xA37CEFAAA58284DFULL, 0xF6EB20D9E342E20BULL, 0x2494C906A92A9227ULL, 
            0xD0498188D076C15BULL, 0x8C6983BF50FA375CULL, 0x4D03F7B060ADA18AULL, 0xF459935D801EDC7AULL, 
            0x0C1617657D83E2E6ULL, 0x22F3E7E51196136FULL, 0xFF9D1C7678A93788ULL, 0x2C14DF7B48BF947EULL, 
            0x05EFA87F3C45B326ULL, 0x4E8B0E0323DBF78EULL, 0x58CF97AD5D769154ULL, 0xE722FCC00C748BC3ULL
        }
    },
    {
        {
            0xA1113F0D165ECEA0ULL, 0xF00E74E525D7F4CFULL, 0x483C4E694293DD01ULL, 0x1CF6B52B4E132332ULL, 
            0x4C59916FE4B5DA80ULL, 0xC2D521E0C014CB85ULL, 0x01D84424887DB4FCULL, 0xBEA78A47A7412387ULL, 
            0x0338C467DB925C4FULL, 0x067563259D02AA8EULL, 0x15A763D558FD07DCULL, 0x481C3D2CE4CB6BB1ULL, 
            0x64128136FBE0AB3DULL, 0x01D442A3031AD22EULL, 0xA482E169312E35A0ULL, 0xA5B23AE36CB08785ULL, 
            0x01BDB5546AECB832ULL, 0xE40B9DB3C780C15CULL, 0xF52CBCE2C632D6D9ULL, 0xD6D1E573C86D2410ULL, 
            0xD78814D817C52859ULL, 0x037E73D720017111ULL, 0xEA0D42F6616F08E6ULL, 0x40DAA0D9ACA769E4ULL, 
            0xA627FA35098EAAFEULL, 0x5961FB712EA1166AULL, 0xA9A422AF2510819FULL, 0x8A07BC0F7BB4DD26ULL, 
            0xAEC720A4E899E047ULL, 0x049AF425477618E4ULL, 0x27330F4294A9B45FULL, 0x70B594AD726F8896ULL
        },
        {
            0x1D14656F9A13DE17ULL, 0xBB209D705A1F9BE3ULL, 0xF67F5FAF96546B0CULL, 0x2FA47C4C0812A743ULL, 
            0xA352C16BCD3EC24FULL, 0xC9000972118DEB9DULL, 0xA78559D4F97C6CEAULL, 0xF52A4EBA358D8CEEULL, 
            0x46FA141A184FEE78ULL, 0x4D30C1AFFA5B7C95ULL, 0xF8B56CD90F186B67ULL, 0xD1DE7584AF486FFBULL, 
            0xA36D7CC77A0225DDULL, 0x0B73CC2E80A85C87ULL, 0x39E4A6DEF48C1619ULL, 0xD8603AEC942A4534ULL, 
            0x8F4C2365EF053844ULL, 0x0CB4BC4AD099F308ULL, 0xCFCE7B0B22E5FA60ULL, 0xC551938C40411AFEULL, 
            0x98725DA732D63234ULL, 0x209AB7BCE8A17FAFULL, 0x3B74F99B6E64EACDULL, 0x65FDFA7EB0BEE0BAULL, 
            0xA91E94BFA260F3F4ULL, 0x9CD76BC403B38692ULL, 0x84079FB1516364A7ULL, 0xD26F1D0015873884ULL, 
            0x0715320D508DB720ULL, 0x3367FE401844D885ULL, 0x4CE7C59E6D8F7C12ULL, 0x505A671D2D9F5A76ULL
        },
        {
            0xC9C04A7B21395F7CULL, 0xA0FFA1F95F517174ULL, 0xFB1A4CC36442B8CBULL, 0xEEC019F82CB5FF92ULL, 
            0x50F34200524EE46CULL, 0xFD5D1F762DCAC085ULL, 0xA8A3049E2CA88A55ULL, 0x6959FA863DFFD241ULL, 
            0x972C6ABDB62E9826ULL, 0x0B45C9F86DC1F452ULL, 0x27300D121BE4BAFCULL, 0x2051F5763E8CEEE4ULL, 
            0x4E05A6A83F452A2DULL, 0x8383EAF9C52EF79AULL, 0xC7D891D99DAF4CEFULL, 0xB67427C8B315ED36ULL, 
            0xE904D83FB102C3B8ULL, 0x3DCF3EF1A220F175ULL, 0x8B8BF765FFD8A0DBULL, 0xA5672C030C14F64DULL, 
            0xDCDB5FB30D03C6EAULL, 0x9E639EB56040EB4CULL, 0xF3B22F816E1FAA66ULL, 0x4274D9DA914838E3ULL, 
            0x314EC7D57CCEACA1ULL, 0x267040E9BD399292ULL, 0xBFB45637E2FD18C8ULL, 0xF53BB66E2C4867ECULL, 
            0x0EE230ED4FB44F86ULL, 0x2A9B0D3A2E9DB7FDULL, 0xDDB4AA651508FE29ULL, 0xF68400F7D19282D1ULL
        },
        {
            0x01F61C87611D31FAULL, 0x7B10AACCBA11EADBULL, 0xE4BA92C1C9E86760ULL, 0xF38FF96FBB2265F7ULL, 
            0x8C5A278995FA2C7EULL, 0x91A641CD49001402ULL, 0xC8F793B9B0420469ULL, 0xDCD232E6B8DE6585ULL, 
            0x43454E465BAC1511ULL, 0xCA03DAD326834D08ULL, 0x529493774409C58AULL, 0x20CA2CB17A131194ULL, 
            0x8FFDAC2D512E0E1CULL, 0x269EBC761BBC5A55ULL, 0x5115FD06B7E57361ULL, 0xCE61A60C14371DDDULL, 
            0x4D342B7575AB315FULL, 0x392E27810299444BULL, 0xB987BC60FE95B832ULL, 0x2E8A3D2CC2C41F17ULL, 
            0xE4EC0EFBA377F0E3ULL, 0x31822E7A624E18E0ULL, 0x0838CF41FD6F8098ULL, 0x466BE67E03E32168ULL, 
            0x02E7E403694FD107ULL, 0xE129984644AED3B9ULL, 0xF7C5E7B5DE409EACULL, 0x87AB9756C0B225B6ULL, 
            0x6785C061C4BD45BBULL, 0x4125F3D06B357335ULL, 0x7D9BEF4F634891C2ULL, 0xBEF1889C84B6DBFDULL
        },
        {
            0x4A180FF031D2DDB2ULL, 0xD8DB147C2F9F2AC2ULL, 0x5C1EF4D06F104CBFULL, 0xFA7C926BD4EC2C56ULL, 
            0xFBFDF9D014A34419ULL, 0x06658580B2013A23ULL, 0xC45D88B0AE2E8874ULL, 0x7B3E4DD0704A6B9DULL, 
            0xD6A03C8ABE351E48ULL, 0xC457171E73140F35ULL, 0xED24084814C0E1DCULL, 0xBD49B1C4C9FD3A9EULL, 
            0xEE86BE0E57B39C95ULL, 0x0BB8B644AF1C846DULL, 0xC406C1B14C186D80ULL, 0xF566E49AE81197EFULL, 
            0x736CAAD6D6F7D906ULL, 0xB63E0924ABC442F3ULL, 0x5C797A145EC16F2FULL, 0x3173B06DFAA7FB06ULL, 
            0xDEDC7EC15F73511FULL, 0xCC73A96FD2E68140ULL, 0xF130993A82F962F0ULL, 0x7206EBAF75A6410AULL, 
            0xEA0C48A3DC094169ULL, 0xA90365C0076BFD01ULL, 0x33D9603F09C4ACE6ULL, 0x6B9758142F3BE9EFULL, 
            0xDC35FE89C94245E3ULL, 0x77ECF45413B889B1ULL, 0x970BD3D65C80CB0EULL, 0x7CD8C31F4CB05E2CULL
        },
        {
            0xC6B14944BCA4F71DULL, 0x5EAC53CAC9CBE93FULL, 0x6D33B081E65ACB87ULL, 0xCBB6A431F1A676B4ULL, 
            0x407A22E0CB983BBEULL, 0x32E05DA8F7F7C2BFULL, 0xFCB3C0B8C89F5883ULL, 0x9A12A9542DB43FDBULL, 
            0x76C2D4619CC91530ULL, 0x3A9AE1DD6421BE18ULL, 0x97F481304D758910ULL, 0x77CBA81CBFA7A5DAULL, 
            0xAEA2541D4E1B248FULL, 0xECB73C2D2BF77376ULL, 0x40553900D969C3A5ULL, 0x72834EDED0CEAF4DULL, 
            0x2C14A27D8BDB9E52ULL, 0xC95DE3260F2C7897ULL, 0x157FA2954BA14E43ULL, 0x178A3F6831F8ABCCULL, 
            0xDAB9BD14CCD65694ULL, 0xD2C62AEC3FF08E95ULL, 0xAEF6C2C41205A07DULL, 0xC19226EA6ED95E37ULL, 
            0x281DE8367EF1F373ULL, 0x88C207A7F2C909C0ULL, 0x942A0BD633408181ULL, 0xB7FD16DFD76E4C3AULL, 
            0x51579AA4C47DCE10ULL, 0x285B41492C14808FULL, 0xA8FEAC50DDECE737ULL, 0xE8FE2B6F9F483C49ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseHConstants = {
    0x51F7E037F70CA886ULL,
    0x548900EE2AB2490CULL,
    0xA30EB51A7EE307A3ULL,
    0x51F7E037F70CA886ULL,
    0x548900EE2AB2490CULL,
    0xA30EB51A7EE307A3ULL,
    0x44CD47FDF0CC5061ULL,
    0x445387E47D214A43ULL,
    0xEF,
    0x71,
    0x68,
    0xF8,
    0x94,
    0x1C,
    0x5B,
    0x02
};

