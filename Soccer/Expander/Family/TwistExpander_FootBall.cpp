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
        aPrevious = 16465503473102991094U;
        aCarry = 17567131483367421957U;
        aWandererA = 12702211865555262553U;
        aWandererB = 12038046921796253971U;
        aWandererC = 11011116077063546360U;
        aWandererD = 12552505871864415366U;
        aWandererE = 11608911387641702527U;
        aWandererF = 17630046881112156115U;
        aWandererG = 14013583370709287265U;
        aWandererH = 15671470412169489443U;
        aWandererI = 17684474617232250977U;
        aWandererJ = 10890828070321536781U;
        aWandererK = 17604423413800371819U;
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
        aPrevious = 9928963050930681213U;
        aCarry = 12382154005695963189U;
        aWandererA = 17119839200908315407U;
        aWandererB = 10856143537909420060U;
        aWandererC = 12475253192084066199U;
        aWandererD = 9239685736369439676U;
        aWandererE = 16807771044037717456U;
        aWandererF = 17521246433462972220U;
        aWandererG = 11021148690206974577U;
        aWandererH = 13152681039910017074U;
        aWandererI = 18150050775108732329U;
        aWandererJ = 11167873200720515698U;
        aWandererK = 17794319439687138284U;
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
    std::uint64_t aPrevious = 0xF21708C4CF4D4D4FULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xF7CC54117180EB08ULL;

    std::uint64_t aWandererA = 0xD0D292225195F5C0ULL;
    std::uint64_t aWandererB = 0xF20A2D3A28D275ACULL;
    std::uint64_t aWandererC = 0xDB69AA1B901B04E9ULL;
    std::uint64_t aWandererD = 0xDCE3DD696D47AD81ULL;
    std::uint64_t aWandererE = 0x84B4CFEB717824F0ULL;
    std::uint64_t aWandererF = 0x9277D4F05A7229F9ULL;
    std::uint64_t aWandererG = 0xB67229F12C8412F1ULL;
    std::uint64_t aWandererH = 0x9F434EB3FD579CE2ULL;
    std::uint64_t aWandererI = 0x8EA36BA02DE9A169ULL;
    std::uint64_t aWandererJ = 0xBCFBFB2CC2C1D505ULL;
    std::uint64_t aWandererK = 0xCF2603E95617289AULL;

    // [seed]
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB);
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
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
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
        aPrevious = 14888645901578138397U;
        aCarry = 12842337789677951674U;
        aWandererA = 10368401997584739741U;
        aWandererB = 13040395820622335835U;
        aWandererC = 10544048376439905924U;
        aWandererD = 17853727810676143515U;
        aWandererE = 18014750488887770166U;
        aWandererF = 16566418773503203107U;
        aWandererG = 11720803086770634878U;
        aWandererH = 18313623012188448014U;
        aWandererI = 14242335612148971880U;
        aWandererJ = 16711424565083132881U;
        aWandererK = 16490063659682446826U;
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
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 3, 3 with offsets 1940U, 6924U, 4624U, 2332U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1940U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6924U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4624U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2332U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 2, 0 with offsets 3608U, 8059U, 1080U, 6977U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3608U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1080U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6977U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 2 with offsets 4115U, 6694U, 5904U, 1206U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4115U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6694U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5904U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1206U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 1 with offsets 232U, 876U, 4597U, 7748U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 232U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 876U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4597U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7748U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 0, 3, 1 with offsets 1218U, 1564U, 297U, 844U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1564U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 297U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 844U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 2, 0 with offsets 1466U, 725U, 195U, 318U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 725U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 0, 2 with offsets 816U, 793U, 1115U, 1090U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 816U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 793U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1090U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 3, 1 with offsets 1685U, 500U, 1433U, 1073U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1685U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 500U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1433U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1073U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 526U, 1256U, 1013U, 255U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 526U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1256U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1013U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 255U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 2 with offsets 3951U, 1039U, 2922U, 2562U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3951U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2562U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 1 with offsets 6672U, 2552U, 3676U, 7933U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6672U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2552U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3676U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7933U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 3 with offsets 7581U, 505U, 7990U, 6566U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7581U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 505U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7990U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6566U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 0 with offsets 1315U, 6726U, 1902U, 5507U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1315U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6726U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1902U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5507U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4487U, 4737U, 2320U, 5065U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4487U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4737U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2320U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5065U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1513U, 557U, 573U, 1366U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1513U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 557U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 573U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1366U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1555U, 1017U, 966U, 1204U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1017U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 966U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1204U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 887U, 1224U, 278U, 1258U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 887U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1224U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 278U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1258U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1243U, 298U, 470U, 140U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1243U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 298U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 470U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 140U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 0, 2 [0..<W_KEY]
        // offsets: 752U, 725U, 817U, 773U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 752U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 725U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 773U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseASalts = {
    {
        {
            0xB3FD65D9AA884736ULL, 0x4CA09334BE23B08AULL, 0xB1ABAC2F61E2D011ULL, 0x34485E0B8D56C05EULL, 
            0xB69FF1749CD93AF6ULL, 0x4B14256EF1DA40B5ULL, 0x0083F94A7BAE410EULL, 0xBB2ABC25A0FB6FB6ULL, 
            0x34000D53779E12ECULL, 0x71C3DC573E3C44A1ULL, 0x3EE2FBE64D4B9E18ULL, 0x0009EF6B5CC848E3ULL, 
            0xDFE05329982C8FECULL, 0x221CC485BD1FC81BULL, 0x2075057D1D7A5124ULL, 0xC8B4F2332A12A3D2ULL, 
            0x15BAC6ED78814B2DULL, 0xA78D370790522833ULL, 0xF44BBDAAF8E7F68CULL, 0xC8821C9F604C0C6DULL, 
            0x58F9B0B7F2C925F6ULL, 0xF8B39048F9D920F5ULL, 0x5FF27ED271527E9AULL, 0x21A191644FE7864AULL, 
            0x6B023285FB9244E3ULL, 0xE2EF42DE30511DC4ULL, 0x7132718FCF62C29AULL, 0x00B0518B4B9B2B7EULL, 
            0x1B8DBD566A90B26AULL, 0xA7406679D20C3204ULL, 0xDFC20DEE2E38EBDDULL, 0x823D2EEEE74656ABULL
        },
        {
            0x62CA2CD2210E50FCULL, 0xDEE68A778BA940E0ULL, 0x08A66F941CA47A53ULL, 0x825991F288DEF452ULL, 
            0xEBF71598C4BAAD79ULL, 0x0530F99049234975ULL, 0xE94CC1A3D35DD466ULL, 0x03B3CCC1A3364655ULL, 
            0xCA2F6C90DA931E3EULL, 0x8C76CF9DB445A6D9ULL, 0x241FD5925E357EF4ULL, 0x5B07DB1C1E16E924ULL, 
            0x9E50493A9640DBB6ULL, 0x48C1513175367888ULL, 0x1F3C65D9F2FC5D85ULL, 0xAA73E8EE07F93D78ULL, 
            0x17AB6E89C812CFD7ULL, 0x67A3E99AE1B58373ULL, 0xDA406267C988BF7DULL, 0x4D1390B5AFEDB3F7ULL, 
            0xD43887B207546200ULL, 0x8DA2D81184406282ULL, 0x29403679DC4EDDC3ULL, 0xBF63E41FD362CB3BULL, 
            0xE7A848CFE94DBC83ULL, 0x2B61E196963A949AULL, 0xBA151538238CE98AULL, 0x80522E822ABCD628ULL, 
            0x4686F8099071122EULL, 0x544D353F506B897AULL, 0xF943ACE7D3B95D9DULL, 0x88144D4BF5E3F4F8ULL
        },
        {
            0x76E54BDF49078AA1ULL, 0xA860FA3126946E59ULL, 0xECB94D0365EA198CULL, 0x5B6EFBBCEF7791AFULL, 
            0x913DD08EF0107915ULL, 0x112FE652D6012FCAULL, 0xD47F31F822C78670ULL, 0x43392CD49B97ED27ULL, 
            0x3DA73E3A85D1CCEAULL, 0x6567DDA7DC6F315BULL, 0xA5D7585258ED7DFFULL, 0x9056479FF19AA906ULL, 
            0x1C17E8EF8F4AE4A3ULL, 0xA2450A34AF738A74ULL, 0x8E63D824A26EBD92ULL, 0x0D0D1C56E6ED481EULL, 
            0x9DF67DA4E703D262ULL, 0x576ED5A5CAEEB342ULL, 0x25755FE45C1B179FULL, 0x9B91016DFF52E13AULL, 
            0x96A555C206AE842BULL, 0xA7EE846056361726ULL, 0x64AEF6CCE33CD4ADULL, 0xA7FBAFE9A4E51720ULL, 
            0x10006244D4799E6CULL, 0x630AAE202B1DAAF9ULL, 0x1FBC77BF054520D7ULL, 0x2B40AD8BDF04D795ULL, 
            0xFCE76140D0321A3CULL, 0x14A4C7B729ED759FULL, 0xB6742ACA451608E5ULL, 0x310A40324D05AD7EULL
        },
        {
            0xC754AB5CAD013BEAULL, 0x7180CBA7A34A50EEULL, 0xBEA0655014F2097EULL, 0xDBCDBAC1C1DD1845ULL, 
            0xB92A16A68FD1BD7AULL, 0x84DA277D4593B5A7ULL, 0xFEEBA4AE2C7BA873ULL, 0x031DD6100466E2F2ULL, 
            0x40AFC146F5316F6AULL, 0xA9AEEE5E626B5628ULL, 0x5160F81977082ED2ULL, 0xDEE94852B687A559ULL, 
            0x1900FA4440CEDC13ULL, 0xACC65285AE9E3760ULL, 0xDA1886522C20A046ULL, 0x81F8B226F2798021ULL, 
            0xE2CB27E5BF037FEFULL, 0x42F7BC35A199F4CDULL, 0xFB1AEB890EA2F0D1ULL, 0x2FE37619A2DE283BULL, 
            0x3FCEC9BE9DD4EC02ULL, 0x0CC2252E9B1B0217ULL, 0x8118C482DF8CEFE4ULL, 0x861F50A3E1DAD665ULL, 
            0xBFEA4CA1427AC955ULL, 0x4F95EA336389532DULL, 0x47BE912B3FED115FULL, 0xC50D4A0C40E2D29FULL, 
            0x4AB9EB2C89CDB025ULL, 0x74CC5BA24970ED0CULL, 0x541AC91E2DC0C169ULL, 0xB58BEBA3B22F7071ULL
        },
        {
            0x7DA200AC19F00CA2ULL, 0x2B282D557EF9E3E7ULL, 0xFAC6E0046000F708ULL, 0x605DA2299540C97FULL, 
            0x77D8410EF7E7B5F9ULL, 0xDD49096B353F8977ULL, 0xCC67986E3795F979ULL, 0x0DBF10C229146D08ULL, 
            0xF58BC7A0A0B6A691ULL, 0x2AC8242A273B2447ULL, 0xDBB1B242ECED0663ULL, 0x373DD3F2E5C85693ULL, 
            0x0A18B981C0F560D2ULL, 0x43E5733F6994FB3DULL, 0xFDABD5E35F25DCAEULL, 0x5679A952375D63B0ULL, 
            0x18DE9D719344A1D8ULL, 0x0FCA49ECC1E31280ULL, 0x559B4B116F255491ULL, 0x9B7C60F0286B64FEULL, 
            0x928EB91871CB94AAULL, 0x75AC22FDFE82C711ULL, 0xDE5A93458E3A9490ULL, 0x546E703BE43AD5A5ULL, 
            0x566A7D0E374FBC37ULL, 0x544004B31EE8D92BULL, 0xCAEDEF4CD1E6E219ULL, 0x64C770BC1D8ACD1BULL, 
            0x1627278A05076758ULL, 0xF3FAD5D14F6C51BDULL, 0x383C4A12A8DB5B56ULL, 0x36905B47B925CAB2ULL
        },
        {
            0x5F5A3ACA2E8BABD2ULL, 0x5DFA41BADFC721A4ULL, 0x3CBF8C62F883A238ULL, 0xCB1434AD55B5C5A4ULL, 
            0x884CE449C41141EDULL, 0x364432459F473D2FULL, 0xA797F76E5E2B9328ULL, 0xD3130CBFDE72E46AULL, 
            0xAFC20215AA7F616DULL, 0xC0EB972142D58779ULL, 0x7109218B14E9BD4DULL, 0xC846AF23F52FDAE4ULL, 
            0x391640BA03AF959BULL, 0x6A3829BCF5359F95ULL, 0x9453A1635842027DULL, 0x851FB629AF1DCF5FULL, 
            0x0B1EF04976ABC4B4ULL, 0x9AF7FD45A29A169AULL, 0x8A553B70E547FE4DULL, 0x45936F9CB2869A29ULL, 
            0x93BE2520E9869BF9ULL, 0x0EE5BC2A0D80908DULL, 0xAE9BB333116CD097ULL, 0x2E2826F89B15B382ULL, 
            0x23F83CB8F4EA7022ULL, 0x853103CDA86A17CBULL, 0x2D960CE85B75D8E3ULL, 0xDA1B8546ED688A11ULL, 
            0x8576D99C9E97119AULL, 0x052A908B8C76CB3AULL, 0xA254AD369EC8DA3DULL, 0x48A080CC7877ED03ULL
        }
    },
    {
        {
            0xF739D6CA2C55B41BULL, 0xD32F06D4E41E45E5ULL, 0x2C4E63078F4AC908ULL, 0xA4FCBCF7E5E423DAULL, 
            0xA82F89F87F8AB04AULL, 0x3FAFD82BCAC6C9E6ULL, 0x513FA44A0B1E37C7ULL, 0x6F4FFFC4BADB12BFULL, 
            0xAEBFE01CD9D9C3E5ULL, 0x763491D1A7DEB1FDULL, 0x282B938957B1FA71ULL, 0x9E678BFCC4E37191ULL, 
            0x83D8836698819EC6ULL, 0x6379DA10FA943416ULL, 0x811B5C61200B8D6EULL, 0x6B891F6379CF0752ULL, 
            0xBE67514165FFD992ULL, 0x9BCC4F043FA8D899ULL, 0x86A3FF5DCB4F956EULL, 0x0F131676FDB4B017ULL, 
            0xB1D9082EE9FE8BEBULL, 0x37F31EB70879D50BULL, 0x2564A2DE81648B30ULL, 0x020AE573DBDBD48EULL, 
            0x83BA4F54A08EE06FULL, 0xCCB107E020C26ABFULL, 0x83460088DA7C21B5ULL, 0x673E045C26D96361ULL, 
            0x652EB609E09BBCFEULL, 0x96993B4D525FECE7ULL, 0x5058396873F1340DULL, 0x9DE08D7907EEA6BBULL
        },
        {
            0xB9A3E9ED329E8B82ULL, 0x4C5E8379AC370731ULL, 0x9504A98836383E67ULL, 0x2FC62C45EC367BD3ULL, 
            0xD3C35D1C43C2636DULL, 0x5431E83AD524EF2EULL, 0x92B4C070B0483053ULL, 0x2B5E4C8BC6F2AA1CULL, 
            0x8D4E852B0539F9F7ULL, 0x17DB932F11BB84A8ULL, 0x0605803714896D82ULL, 0x76824FCB00005A97ULL, 
            0x7402C4D75C0735C6ULL, 0xFA374B128C3BECFDULL, 0x4E2A1589B7284919ULL, 0x8586C18621AAC490ULL, 
            0xC609B7CA22CF23BBULL, 0x4419A3BD0013BA4AULL, 0xD775F49EC8222A8CULL, 0xF78AABC92C539657ULL, 
            0x8B63338A0E5C6BE0ULL, 0x90F5D460487B179CULL, 0x2A061EF6AD3726F5ULL, 0x9D4F60D432F2DF20ULL, 
            0xEFB40F8C4B53B6B4ULL, 0x9751BC4C48F4BAAAULL, 0x931E6CD226CE754BULL, 0xA2C0209049FE995AULL, 
            0x0796D962049C6A6CULL, 0x4C90394C0DEC1C61ULL, 0x3D48F7D96BFB16EAULL, 0xB08949BF4218025EULL
        },
        {
            0x7CF1FA42253ED462ULL, 0xD34FDC80551471D4ULL, 0xB90B4AA2F7A7FA32ULL, 0xBC3BE57337B60DB8ULL, 
            0x76BE1BB2F531D93AULL, 0x1F489F27EBB94C0EULL, 0x4EA604886D2F88BEULL, 0x3A53B2B85A868F2FULL, 
            0x80E59D534ED2EF70ULL, 0x5CCCD94C3953F7E3ULL, 0x1314DFACFBC78D08ULL, 0x8FE26EBB1FECE666ULL, 
            0xDB0F9EE40FE9F85AULL, 0xA72E2264A8E87FD5ULL, 0xD9DF5BA65C7E41ABULL, 0x829B35187AF7E7ACULL, 
            0xCEF823B4CD2C836CULL, 0xF1C87D01E592848FULL, 0xDA9CA425114BED18ULL, 0xD350A310D5017030ULL, 
            0x6036094A3D5A9298ULL, 0xC1D8AC834695E9E8ULL, 0x630B475B6CDBDFB8ULL, 0xFF69435CA93A79C9ULL, 
            0x8919D5540E92431EULL, 0x4A292C28E0E84537ULL, 0x02AC9B7A41F61E21ULL, 0xE3F032831896C1DEULL, 
            0x2478C33ADD908627ULL, 0xCB227AFEB0D6AEABULL, 0x35805D211EAC3177ULL, 0x1A49A26938477F60ULL
        },
        {
            0x5C2C50D4229DB1B1ULL, 0x2F604A0B7F8DCC2DULL, 0xECBA2F2486486729ULL, 0x91C3158DF80122A6ULL, 
            0x77048619D60BB986ULL, 0x67CDD03A5371B4C4ULL, 0x75101CBD076CB998ULL, 0x9C916C09C2C9134BULL, 
            0x5B1B7CABB503420DULL, 0x1B88F27A68D16F29ULL, 0x51C1DCA9DAB3BBBFULL, 0xFA5C20DB8C1A8F30ULL, 
            0x92697E4126AA6EE5ULL, 0xA10695BCC180103FULL, 0x37DA28FF793720C0ULL, 0x0D7A8B74853EF91FULL, 
            0x0F2A61BE521A87FEULL, 0xB4B77098D0C37F4CULL, 0x29D82B325C1ACFF4ULL, 0xFE2A4779D0AEE1D3ULL, 
            0x39BDF21D5CDB2067ULL, 0x015762972406DAA1ULL, 0x1784537F1BE8A5D5ULL, 0x9C4853E19317DD8DULL, 
            0xB5E6F20336EB48BCULL, 0x1C181550936C204CULL, 0x5CE632BA90ED8BA0ULL, 0x25217EB94D2934C6ULL, 
            0xB0F73C57E7D8C5F9ULL, 0xAE6E7FBB549D077CULL, 0x17D9187C255D3957ULL, 0x18CA1318D97BC425ULL
        },
        {
            0x1A503751F7DC2165ULL, 0x6A59E3D4A813FD01ULL, 0xDD2812A6BD378175ULL, 0xE21B0EF593E470B5ULL, 
            0x17479C5DEFD7C9EBULL, 0x9AE5CCD8A430AEB1ULL, 0x0D36CA96793821D1ULL, 0x769D4CD7EF81DD93ULL, 
            0x40605D4F23A01C33ULL, 0x950A02BA6F987509ULL, 0x59DE92ECF8BAD9E5ULL, 0xD20FC8E824447EB4ULL, 
            0x6CC84C127B66EB65ULL, 0x6E18672F84225780ULL, 0xA624705C99163D68ULL, 0x72766F1B77EB2E3AULL, 
            0x8B552A5975F24D77ULL, 0x8B529608888C6348ULL, 0x63BAA987695F5E04ULL, 0x0CEA6E2D386BB262ULL, 
            0xE79EE64592B57F83ULL, 0x13E85D612CBC22AEULL, 0x445F87C6BF7C85C0ULL, 0x55FF015F78EA2631ULL, 
            0x88FE9D3784052AC3ULL, 0x22332A11838DF4CEULL, 0xDAD3A14B24E9ECEBULL, 0x1B0CB0A0F6356849ULL, 
            0x8BA76A88BF6BF3B4ULL, 0x8DD11C8874462FA4ULL, 0x5D30D2931EF726C8ULL, 0xFB7B75962ED75D3CULL
        },
        {
            0xFC3304B45A2ADB91ULL, 0xBC11D2CDF2BF4DB8ULL, 0x4659D6B62F313040ULL, 0xD9E161233119F04EULL, 
            0xDA57178F1C33968CULL, 0x33FA07CA142D50BCULL, 0x061309064E693606ULL, 0x58399CAB8D41722FULL, 
            0x0C058D370FFACEBDULL, 0xE61AD79F6CBD2A91ULL, 0x7ACDFA8A89518195ULL, 0xA37D1FE3B36B5303ULL, 
            0x628551A6759F00B3ULL, 0x68DE959140C29787ULL, 0x800637FEB1A8EC71ULL, 0xDAF5FE156BB03FFDULL, 
            0x48CDD00AB1C83CDCULL, 0x5F5AF719EC7BDEADULL, 0x4DB44F84BD298EBCULL, 0xA2973FC1534AE553ULL, 
            0x44C79673CB7EA3CDULL, 0xA332D0138BC5E96EULL, 0x1851E210C40C52CEULL, 0x3183852358D50A5CULL, 
            0xDFABD93BE4CE1D9EULL, 0xF6ED78F0107587E0ULL, 0x2597F7625EF9AD95ULL, 0x5A5C2ACE854622D3ULL, 
            0xB6237530AD8AEB35ULL, 0x3170403757E6B004ULL, 0x280B9A49CFE66049ULL, 0x8FD5F549C175ACDCULL
        }
    },
    {
        {
            0x41CAC6D83CFCB3FEULL, 0x6B01E9A929B2302FULL, 0xA56399B05F5B4ABFULL, 0x620C8CB599311615ULL, 
            0x8ADE328D18B31053ULL, 0x7F2718F568E816EEULL, 0x1EE7447392B9DCEDULL, 0x33F79BF6A174C0EBULL, 
            0x5595978012EFF802ULL, 0xBE978DA8271D9CE3ULL, 0x74B7BA1781BF3994ULL, 0x99D0DCEC2A91C6FCULL, 
            0xF0704B834F7B0FD0ULL, 0xFAA7F71C394435C3ULL, 0xB25631F9EE6B2F5AULL, 0xE2D971CA9197CAEFULL, 
            0x66F07DB94D1AE5A8ULL, 0xBE1AD3172F93E4ABULL, 0xDFD270F6380BCCD9ULL, 0xA8B75C2658E84EA4ULL, 
            0x986510EFAE254831ULL, 0x174B74843FCB91A0ULL, 0x8D23497BD62FBC19ULL, 0x923F27203196F05FULL, 
            0x1394A7475166AF10ULL, 0x11A8A0FD5AD3C7A0ULL, 0xD262595B1695D193ULL, 0x03618C99A5ED5056ULL, 
            0x2A4DCD8873E114B4ULL, 0x52D1A8FA5296FE49ULL, 0x09D45991B2A3B996ULL, 0x108561D7D02B4E7FULL
        },
        {
            0xE731E634110316BBULL, 0x8AE9C5BDB7EB120BULL, 0xA59AB5842956841CULL, 0xE3EF6A32ED2D91C6ULL, 
            0x2113EEE846C918D3ULL, 0x32100AF1B0CB657AULL, 0x318CEDD83DAD7719ULL, 0x2506494F57CCAD18ULL, 
            0x688ED05C88DC35BDULL, 0x4C1C7D618467A535ULL, 0x4FCA188315AEB043ULL, 0x3F7851315044CAC1ULL, 
            0xA63BF966C44DAFDDULL, 0xA441722FBD529EF4ULL, 0x0B5767CBECCC5E84ULL, 0x5CB6A63F6736E8F4ULL, 
            0x82DB1D7604FA4914ULL, 0x610D8ED1B7A87B97ULL, 0x74EBA9B7E8CA9FABULL, 0x0D2EA9D92E11AF2AULL, 
            0xF2114C24E0191E89ULL, 0xB3B2FC9512D66BEEULL, 0x735C4A35E47709E3ULL, 0x6991CD8E2AF7CE50ULL, 
            0xBA15C3DC0EA07796ULL, 0x04D7E49234D9B9C4ULL, 0xCDEFC644D3179CD9ULL, 0x857AE5006126EAFAULL, 
            0x51ED4ABC8432BA68ULL, 0xE7AB8D5FA36FC5EBULL, 0x35568B47CA56F4A3ULL, 0x5AC99BF62CF2D8DAULL
        },
        {
            0xC64498B4D9CCD2F0ULL, 0x868096E9DA117CB4ULL, 0xEBCD0B950D325E78ULL, 0x18ACBB34E38AEC3AULL, 
            0xD80AED7A1163DF59ULL, 0x3FD96F51E873719BULL, 0xC997CDBA2FC3BB37ULL, 0x89E907C973E8F546ULL, 
            0xEB67D134AF2D56F3ULL, 0xAAEA696A40789CE2ULL, 0xB49BDF137527D61FULL, 0xD5543F268E2BCBB8ULL, 
            0x8197EFEF1ABC453AULL, 0xECDE02F5729F7D58ULL, 0xB58F06358A26A161ULL, 0x247838EDFBD3425DULL, 
            0xD6EDC12750548C51ULL, 0x43DADBF490BC8C1FULL, 0x6A8C0FFD0BD80DB7ULL, 0xBCD3A8646A6495C4ULL, 
            0xA3532AC61BF23CA7ULL, 0x32AF9C91C1E34C80ULL, 0x094C6D263E029227ULL, 0xEA4A0354231D01E6ULL, 
            0x8A5ECDEFB3FA7773ULL, 0x355EB82155572B40ULL, 0x4BA57422BC8C5454ULL, 0x7B3A025D1A91C78FULL, 
            0xDE797CF636D61CF9ULL, 0xB5249DAA3C13AB73ULL, 0x63EFCABAAA571FC5ULL, 0xE691DC02AF9C318EULL
        },
        {
            0x124BDBD0D4DB4C56ULL, 0x9A21E8320C6E3DE1ULL, 0x14E6168D16CAF987ULL, 0x8E1A51D4A01124E0ULL, 
            0xE8BD761486260177ULL, 0xBB27030DEE0F059AULL, 0xF74911FC72B58717ULL, 0xD1396A53946CD574ULL, 
            0x23147CBDE736E7D9ULL, 0xEEF27EF3CFFC8D9BULL, 0xB56DBAAE600921BCULL, 0x13371001367E3A33ULL, 
            0x1C77A99E6C67D906ULL, 0x66AB3853E79FEFF6ULL, 0x5EE300E2840F2C54ULL, 0x243BDE3A9CB54C5EULL, 
            0xA86C0B7D0DF804E5ULL, 0x6EC70F117E1B63CDULL, 0x98504FC0901D60D4ULL, 0xF528A64CD33F64C6ULL, 
            0x629D1BEDA4DBF3DFULL, 0xB71C110B67F10669ULL, 0x9DFA203C6EA96271ULL, 0xC4BA108802A76E1FULL, 
            0x6DB3D0084919BCCBULL, 0xE224BAA791C62119ULL, 0x23AA9F6CD27D5A94ULL, 0xDD0ABE8C8F918569ULL, 
            0x1CEB5EBE630DC27AULL, 0xB7B1E6FFE9A72F51ULL, 0x531A5D26ACD1EB8DULL, 0x96031A1E4FD7783DULL
        },
        {
            0xD1636C6A366DBCB5ULL, 0x6779C1D86CD86C02ULL, 0x9901D30E443ADC4DULL, 0x4B5DACA2FF58C535ULL, 
            0x2DE9A66992D88035ULL, 0xF11930405592B5AAULL, 0xC3B160EAC1262E44ULL, 0x248972C4EF1173DCULL, 
            0xD46FD616DB8CE8ADULL, 0xB46AB066042E1700ULL, 0x52DA0C841F904CF0ULL, 0xEC4B97A571BB0ADCULL, 
            0xE5E441722B484C2DULL, 0x982AF27F1097509CULL, 0x20144A62B675614FULL, 0x6F39659FB29961B7ULL, 
            0x08BCFB4ED644C185ULL, 0x7B6C57A65BA0DDB7ULL, 0x8A008067B515A1A7ULL, 0x9DDA103B9CC803E0ULL, 
            0x5646E487CCE7AE81ULL, 0xD6DA17232FBC6A30ULL, 0x6D54D07F973ADBB2ULL, 0x0E80BEB46B325B13ULL, 
            0x20816AE17A1BC869ULL, 0xF35037A853D7EAA7ULL, 0x4B71E8FC4450EBDFULL, 0x2BE83730636C601BULL, 
            0x4AEC8A616C969439ULL, 0xD740691C3ABEFD60ULL, 0x31BA0677C9E7D1CAULL, 0x288CC2FC0C033A84ULL
        },
        {
            0xFA6626CBC8CA3EF0ULL, 0x2545B437D4B4E25FULL, 0x15A344C92D2CC127ULL, 0x4C287ACE2177722AULL, 
            0xE9F3C5A64641C736ULL, 0x83D20BEA5BF90796ULL, 0x2B90F4579ED9D4B6ULL, 0xA9830BE6E33E7E48ULL, 
            0xFB4BFE1EFF1DD70FULL, 0x54DBC0143130966EULL, 0x0F3606B5CB7D82D1ULL, 0x456D4303C16E0288ULL, 
            0x1903C227CE691EF8ULL, 0xA48A74E851A258ECULL, 0x8E4CC053F8AF1A01ULL, 0x8F6F3D592FA04122ULL, 
            0x108F77A1FA3385D9ULL, 0x7D87D8EC1BD5C29DULL, 0x3954C64D19A6D8B0ULL, 0x2B1113BAFA28EF7FULL, 
            0xAECF87497BB95A8EULL, 0xCE0E67CA3CDB6D9DULL, 0xAE79559BC46322E7ULL, 0x27B2EA2A01CDA80AULL, 
            0x821A271D33323038ULL, 0xE567F17B7DC65E2AULL, 0x314B40D0393FF60BULL, 0xCF26DD1BABB1F706ULL, 
            0xEFCAB895C2AE4CE4ULL, 0xE0949A26D9DFDD04ULL, 0x9C524C7C0CD51C1DULL, 0x4C401ACFD025DBC4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseAConstants = {
    0xACF96FC3E6857A1BULL,
    0x563A752BC9AAC633ULL,
    0x11ED6FCAEA09E4E3ULL,
    0xACF96FC3E6857A1BULL,
    0x563A752BC9AAC633ULL,
    0x11ED6FCAEA09E4E3ULL,
    0x0521007C2D5696A3ULL,
    0x827AF17BEAF226B7ULL,
    0x27,
    0xA4,
    0xC1,
    0x68,
    0xA6,
    0xEF,
    0x6D,
    0x9E
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseBSalts = {
    {
        {
            0x37AE13BD93CD17CFULL, 0xF42C9892C0E43345ULL, 0xCC63586ABAA7DAADULL, 0xFAFC62CBA372DDEAULL, 
            0x88818CE2384A9853ULL, 0x54202C1AA19EC962ULL, 0xBDD24B43553F20C0ULL, 0x6F4B0897A5F42C35ULL, 
            0xAA27402E2E421060ULL, 0xD2AAF320DF6602DAULL, 0xE5FA153EA946CBC8ULL, 0x1C283CFAE72FC865ULL, 
            0xE45177165D73DB13ULL, 0x0151480831833AD7ULL, 0x324239FBD6E2C7F3ULL, 0x5FE6B43B2DE9CC1EULL, 
            0xB4F895BFB442C4AAULL, 0x034D883E3AF7753EULL, 0xA2B07E9D79EA8AFFULL, 0xE10D7148202B7EC0ULL, 
            0x1627552EABED258EULL, 0x686203F27349BFA5ULL, 0x3605ACDDD5DCAD92ULL, 0xB4CF6C840238E815ULL, 
            0x014C995BF42DB5A4ULL, 0x0685408E556E1EDCULL, 0xC5E46CA8FF744EAFULL, 0x4E119EA088A6E6D5ULL, 
            0x7BC25B73EE59F73CULL, 0xA07C0AAB94D2D9DEULL, 0x50219C6C1D377049ULL, 0x32F665D53FBB0F2DULL
        },
        {
            0x46F534647AA85845ULL, 0x5354656C889E4199ULL, 0x68625654E88CFC42ULL, 0x3E30C1DF4D1BC022ULL, 
            0xE192616FAE15E35BULL, 0x7BA96708A2973C04ULL, 0xCED212523DD0FD4AULL, 0x6DA873F4B9CAE3EBULL, 
            0xC1C7BC15C2F5CBBCULL, 0x91D9D2DE626ADB4CULL, 0x2B69C9E6A0731D57ULL, 0x331C75E3F8F823EFULL, 
            0x8AD2250D98AD8EABULL, 0x626599C09CF8604AULL, 0x1D6F1BB2272C2CFEULL, 0xDC5EF17010F96448ULL, 
            0x9768ABA4459300DEULL, 0x9A33330ABDC34E63ULL, 0x5070BAE985111E7DULL, 0x8349424731D36D69ULL, 
            0xD06745532BF084AFULL, 0xEA6A0687BD1F29B7ULL, 0x0EC150A14C63D3D8ULL, 0xCFF6E5C1BE9556D9ULL, 
            0x323798D3F9B012B5ULL, 0xEA90EDAC874D1B40ULL, 0x78D097279B1AFCCCULL, 0x4E4CDE29B0344A1EULL, 
            0x31F9C20978BC4917ULL, 0xB161712A04672A56ULL, 0x465E8821CAE017A4ULL, 0x5689AA3E1C7DD0DFULL
        },
        {
            0x5994A7676C80258FULL, 0xABDAB0A21EA486AFULL, 0x97B973A25B2F137FULL, 0xE44F7A650A16A217ULL, 
            0x5FEBD51F7FCF6DCBULL, 0x6F1CC02180F97CCFULL, 0x32FAC2CFC9E6D8E6ULL, 0xFAFA4E72E1FFAD88ULL, 
            0xA4FD1E81ADD89E62ULL, 0x3415003002448755ULL, 0xE26FE60EDE8643CCULL, 0x595784233F647C34ULL, 
            0xD06DA7C3DCCCAD0BULL, 0x440ABEA7F3F28F66ULL, 0x6E88340F046331D3ULL, 0xA7DBF180774F9890ULL, 
            0x9ED0E505F1168BD9ULL, 0x63BE73F5E3440529ULL, 0x51D1A0633C11EAACULL, 0x13B040770DFCD402ULL, 
            0x46102A18AE1A0117ULL, 0xB2470A15815ECCAAULL, 0x5856193A7D422DCFULL, 0x49D6CF6DEF221F08ULL, 
            0x6166F27FD317FA3CULL, 0x09E27B39FDF7EEC2ULL, 0x4FD8ED07EB17E971ULL, 0x7C93C1941D7CFEB5ULL, 
            0x2DADA831532E1401ULL, 0x9F52D7D84ABE0635ULL, 0x55EE662C1EF8FF08ULL, 0xC707FC3611298F64ULL
        },
        {
            0xF6448FDC20E8746AULL, 0x94830069E5F84B48ULL, 0xA86E1666BD1B2EE9ULL, 0x0D8B50BFCCE6CED2ULL, 
            0x3EF13470D21E7A64ULL, 0x4DE1CF7B3579B876ULL, 0x6C59A9685EECE383ULL, 0x992BA386253F9A68ULL, 
            0xF364B45623908A6EULL, 0xD97AE92F6FB83E4BULL, 0x55C92DABB6BD8DEDULL, 0x61EA8650B238C070ULL, 
            0x604921291381871CULL, 0xB892A41F351A1A37ULL, 0x09B95A5C9E4EF9F6ULL, 0xE7A19F97CFE1CAACULL, 
            0xE581BD8B395F333DULL, 0x9C8A38AAC8847D13ULL, 0xE88D3DC8EBF36D5FULL, 0x4B94E979B64C06C6ULL, 
            0x6AF5B3426522E770ULL, 0x27D1072CECA682BEULL, 0x7242C10765204CDBULL, 0x652E5993B0CA15B7ULL, 
            0xD4526857BB1268DCULL, 0x9A81DD16933968E1ULL, 0xD457B8EB5137ED09ULL, 0x17AFBF5166449E93ULL, 
            0xED897C89B1B9812DULL, 0xAF9646DE0151F0A1ULL, 0x5D4F08FA7BD999DFULL, 0x57B25383FCF3C0F8ULL
        },
        {
            0x273B2D26407B8120ULL, 0x7743DD4DD0B1EB61ULL, 0xE7B5BF854D66EC42ULL, 0xE52D5F14EFB52B24ULL, 
            0x4C3E5EF8694C2D3EULL, 0xFC48CC43358DE6C6ULL, 0xCE39533F7F546B70ULL, 0xFAEF08AC713DF8B1ULL, 
            0x77D3A7C31DEB6751ULL, 0xC3934E61EBE2E655ULL, 0x3C3F3AE8C7D7B83CULL, 0x74AF4E63BB75A6F2ULL, 
            0x020E5B9875A8FAE9ULL, 0x88C9B83C609227F1ULL, 0x67F4CD5081FC5E80ULL, 0x50186DA134D0C633ULL, 
            0xDC7A7729D63AF550ULL, 0x3F8D125FA971338FULL, 0xC7670290C8934F77ULL, 0x71D220B985DFF394ULL, 
            0x84D603D33E2305A0ULL, 0x9C055B8476E70918ULL, 0x5CF71C818998DF3AULL, 0x6B559E9270AA5C2FULL, 
            0xCDCA15715E441340ULL, 0xDE88160E98ED317AULL, 0xD68F6037A5784499ULL, 0x81B0739F32115578ULL, 
            0xA473F82D80C784D6ULL, 0x7390CE310214E207ULL, 0x9981B4DCCB589477ULL, 0xBB9B8123C3DF4FD1ULL
        },
        {
            0x215663EE267F3EE3ULL, 0x7173523A4F42800FULL, 0xE55B6B87FE93F6ECULL, 0x3598BA0DF3DC3D90ULL, 
            0xF83D51BB8033C25FULL, 0xC245143126F390E0ULL, 0xBB8C381B07CD3D81ULL, 0xD16B10592CDEB0A7ULL, 
            0x4865A0A3484EB134ULL, 0xB984783322746402ULL, 0x0D3F716D0DC19654ULL, 0xBCF79F9DF566EA8FULL, 
            0x4334A5CC3FF95A16ULL, 0x2A67757573D5FA22ULL, 0xB87C0F25E5AED45AULL, 0xB11F43245EBD2DA0ULL, 
            0x6A6FF9AF73458D4BULL, 0x40B71A7A815299F8ULL, 0x131DDA45FD344F35ULL, 0xBB1C57716462810CULL, 
            0x1656AD8D7141F3E1ULL, 0xEEA820B038EFF46AULL, 0xE2E67E3177DA48BEULL, 0x3DF736B11BF5962CULL, 
            0x174AA67A0F65C5BAULL, 0xBF1EAA3A7E303369ULL, 0xCCE1AE69969FA400ULL, 0x186884D40D0E3358ULL, 
            0xBE8D01B279850AF8ULL, 0x2D995BF9367080E3ULL, 0x2B84089C224F8109ULL, 0xF8A4870B819967BDULL
        }
    },
    {
        {
            0x0A7B9039DF5170C6ULL, 0x7F0245CF95580101ULL, 0x21A6092475442371ULL, 0x522E4D602BF3DA11ULL, 
            0x76D3884BA6C09491ULL, 0xA02EFB0D7C0F9618ULL, 0xB6EB79151DC9127FULL, 0x50AE565CE0017030ULL, 
            0x251F7C2BB94D9A1FULL, 0xA9DC7BC53CE2FF2FULL, 0x0D0E86494FB2B556ULL, 0x2027BB5F39978990ULL, 
            0x0F9813A06914D0DBULL, 0x271B194B89612BAFULL, 0x97BD2622CB70F6C0ULL, 0xE755D4C6CFF6831BULL, 
            0x40C8C0F2F89919C0ULL, 0xD1860AB4E904DDB0ULL, 0xB3720A8958C5717CULL, 0x082FFCF80B55D857ULL, 
            0x2A6E24009FC2C58FULL, 0x4919EBD62540F702ULL, 0x8E44EA94216EAA30ULL, 0xA1195EBA9253D02FULL, 
            0x66935A0156B8ECBCULL, 0x5770960C884ADFC2ULL, 0x321FDD327356E201ULL, 0x38B23B3DABC9E106ULL, 
            0x69C325FE2A4EF541ULL, 0x2CD7463519952AD3ULL, 0xAE93FE85BFD5E131ULL, 0x8C4638739F07A527ULL
        },
        {
            0x60D7B37D708A34E3ULL, 0x247DF53A94FAC3FBULL, 0x28AE2246BDDCF352ULL, 0x3A3D9E9633CCB588ULL, 
            0x291055E6FBB10F97ULL, 0xEF70E0AC052B8535ULL, 0xCE54D62114CA1CE8ULL, 0x4F4004215AD5E15CULL, 
            0x57CC1D060D057958ULL, 0xCC8ECF14B11CF015ULL, 0x23E997481F0051A6ULL, 0xA8272704A6D16C56ULL, 
            0xB643E9810D67F2B9ULL, 0x0E6E8297E9D69492ULL, 0x543D8AB1F6FED8F5ULL, 0xDD295A97A9288602ULL, 
            0x97023A40D0666390ULL, 0x8D1A7B3562A5364FULL, 0x783E745D82F2E69AULL, 0x141365979232A7C1ULL, 
            0xAF6B360A46CB0846ULL, 0x820DBADC1252F506ULL, 0x9479246D9ABCDA9EULL, 0x2D8DFEFE7EDA2CD0ULL, 
            0x82B1E471BE2DFA4BULL, 0x326CBF27DC24D1FBULL, 0x253D3C63E7176082ULL, 0x34738E6A21A0332FULL, 
            0x0C2702C78FF8DE6FULL, 0xB8B6BF04CC3C1F3FULL, 0xF58C56E7A04EFD26ULL, 0x13EAABF790B81446ULL
        },
        {
            0x9EE6009A5C24345FULL, 0xDAAD1ECAC0595346ULL, 0xF01E73F90635FD33ULL, 0x336A400A6DB24F8BULL, 
            0xDDA910E68E654065ULL, 0x9A838A1AF27936FAULL, 0xF57DBE615AE8228FULL, 0x56C5964685B9C9F1ULL, 
            0xD93ED58D4FE90045ULL, 0x23953875A6C3A922ULL, 0x38CF82D77E56C059ULL, 0x78EB91231FE3E353ULL, 
            0xB4492303702B094EULL, 0x99945C4C92F246A6ULL, 0x2E36EEC90BC6536AULL, 0x67C621E7528CA548ULL, 
            0x5814352A499D98E0ULL, 0xE3DCAE65150174EDULL, 0x97BD13428545DA60ULL, 0x8110BA3DDC763D42ULL, 
            0x3086BD4B2D5AF1FAULL, 0xC1B07A283D8C7F5BULL, 0x0EC1007F5DF9189AULL, 0xD163589B36C539FFULL, 
            0xCB634967745F7B34ULL, 0xFE60221BCD2E8AA1ULL, 0x0F723D25E40514B3ULL, 0x2331DAE67203044CULL, 
            0xABCBA5859AEDF12EULL, 0x580DF79F75C43DE5ULL, 0xD81147A1458B50A9ULL, 0x50BAC444555BE305ULL
        },
        {
            0xD9D8B5F333F6ECE1ULL, 0x0163E10BD5BF80D9ULL, 0x9D83271DB1B34015ULL, 0x6F86C0F32DD75801ULL, 
            0x47D5193B559E7AECULL, 0x18196DABAD90A5B1ULL, 0xBB2468DA11C98F9AULL, 0x43B2686BC1F5C774ULL, 
            0xAB93581F7A782FC6ULL, 0xC51043735A22D6EFULL, 0x0F2296C65D862C8CULL, 0x6C54AED9D6C4E044ULL, 
            0x9661140B858A4EB1ULL, 0x14F67D713CCA06C5ULL, 0xB666C3D957C65BC1ULL, 0xED9B1D47F9186FB7ULL, 
            0x66057DB0A806FD90ULL, 0x83E027556BCC46ADULL, 0xC02B003758B8EDEFULL, 0x4C6C5F25AA728ED3ULL, 
            0x2B2E335BB8BC93C4ULL, 0x2C73C7979FAE04E8ULL, 0xC4A94944EE1EF775ULL, 0xAFF179C3038D13EFULL, 
            0xF70E6FBFB46B78A0ULL, 0x6A794A55790F4D0CULL, 0x1E1BBA2BD42B399CULL, 0x6F6E76259CCA39A3ULL, 
            0x1036D8568450BAD1ULL, 0xE7FA525BDF778EE1ULL, 0x07144B0A5565194BULL, 0x6DA8B6A3052977EFULL
        },
        {
            0x2B531181FF8E656FULL, 0x15EE9B8EA0612830ULL, 0x143D156D18EF5FB3ULL, 0xC1540D516DB29F46ULL, 
            0xCEB58518BBFA7929ULL, 0xA375FE69518CFE24ULL, 0xC587BC2A98C2EB95ULL, 0xE4A358CD52A54971ULL, 
            0x8A069E59FD5E422CULL, 0xF8F1A5420AD57178ULL, 0x9916172501C3008BULL, 0xF5248093CA46C962ULL, 
            0xC0D2C8606AE552F4ULL, 0x50F31D7EE60D945EULL, 0xA87B769EDC13CC7EULL, 0x14E20847B3A6D11AULL, 
            0xC14DA986ECE19BA6ULL, 0x54AEEAB6C58C4CBEULL, 0x4E6E29D78ECE7AE3ULL, 0x7B936B9A463B3DBFULL, 
            0xC68CA3DC80ECCBACULL, 0x47B866A9E328C148ULL, 0xBB6534DA0B425D61ULL, 0xF41DB58DEC6B80DBULL, 
            0x54A696EF84F4BF2EULL, 0x374EF0363F1D8388ULL, 0x18F154EBFD7D9B17ULL, 0x447E3D53646A43C9ULL, 
            0xED1F3859BF4892B9ULL, 0x335941AE546EEADFULL, 0xADC55B9BC29B6982ULL, 0x2BD350E34A2D8DA8ULL
        },
        {
            0xAFFE99B4987CC9CBULL, 0x50FBCB4AFDAA97EFULL, 0x4FC7AE87070ACCCFULL, 0x67CCD8D1C7E39D3CULL, 
            0xEF1377D45CA321CBULL, 0x1C425288BA80CC21ULL, 0xF562147FB0E3376EULL, 0x52F941CFC0E45D4BULL, 
            0x421CCEF461D109EEULL, 0xFC160DC063B564B5ULL, 0xDD3108DB81422327ULL, 0x76B9257C30503A85ULL, 
            0xCC687E9850D76785ULL, 0xF97E86E566414C5EULL, 0x401B6C4E91C50707ULL, 0xAA60A37C87D26D11ULL, 
            0x8D507A51A6B61EE1ULL, 0xB0CA3F3C4D4A2843ULL, 0xF7B30209EC0966ABULL, 0x7B13901F0E30BC50ULL, 
            0x3B071EF51D43AAA7ULL, 0x2CE1C344110F0A8FULL, 0xA914E24B7DD6E5C0ULL, 0x21BB813C27D03005ULL, 
            0x7599D9C99E0293E5ULL, 0x47D31426400D87D3ULL, 0x0134BEBAEE7C3BA6ULL, 0xD85FD6B767B3572FULL, 
            0x41B5808A116926CEULL, 0x208808DD6D5F8F53ULL, 0xA6246670188CABDAULL, 0xE9324C5C91314D8EULL
        }
    },
    {
        {
            0x16DD09A681D59258ULL, 0x844EA5ECFBC63843ULL, 0x4CC57D38986F6E98ULL, 0x712C51117A8264E5ULL, 
            0xD75578870EEE6B10ULL, 0xC5A51668EE6AD730ULL, 0x13E83E9AE8DAA7FBULL, 0xBA0F975E37C3982AULL, 
            0xE1B9147F617942D1ULL, 0x50738978418A1D13ULL, 0xBFA37DF09B545725ULL, 0x21527DE95DE91583ULL, 
            0x442ACACF4B69F7A9ULL, 0x07D26C89CF3BE3AEULL, 0xF4BC1CEF384313BCULL, 0xD5C1F728EBC12262ULL, 
            0xEAAAA64C4CBE03F6ULL, 0x31784C8C717B1CA0ULL, 0x35855BEEA19B49C7ULL, 0xD29A6C2AE52D4D42ULL, 
            0x2CA50DE80156D1CFULL, 0x3C1775C9A41FE8ACULL, 0x5ECB200B50736E0DULL, 0xCA9D75B957ACB266ULL, 
            0x5B9DA2A5C9396B11ULL, 0x81FDC06D1ED634E0ULL, 0x703274946FBBB153ULL, 0xA1C124CC9B4B197CULL, 
            0xB9F7410BBF440726ULL, 0xDA85D5B7BB036FDDULL, 0x719BBEBCA939FFC4ULL, 0x4C7FD5B54911A935ULL
        },
        {
            0x67DFB0203363C8E1ULL, 0x57EDE888C40979DBULL, 0xBD15BC0D761FB6BBULL, 0xD62671B271501E29ULL, 
            0xD9B37085E4C2D080ULL, 0x7B8F650E40252B65ULL, 0xC2FAAB97DFADB719ULL, 0x39D36FE40E22CE97ULL, 
            0x938F079DE9A2B96AULL, 0x47027E0FDED61A95ULL, 0x1C7210C99634FC2AULL, 0xB224C0EB7751C06DULL, 
            0x1557B020D67897D4ULL, 0x5F17B72131931E31ULL, 0x0B163AD698D634C3ULL, 0x62C3D3832684D73EULL, 
            0x9219EB236E699B7EULL, 0xF6E613AA3398E80AULL, 0x079C7D23315088C9ULL, 0x34ED36646932BBFCULL, 
            0x1C8968F3EFAA7E67ULL, 0xE1312F397D35240DULL, 0x084390AA4D508097ULL, 0x9E7DCAA7CDCC80A2ULL, 
            0x8050A29692704912ULL, 0x33D6551C8BD965F4ULL, 0xCFFD825A8272A082ULL, 0x234F15FCED7927EBULL, 
            0x2B67DC79930987FCULL, 0x504F78D56365A2E7ULL, 0x8C7C3D0E023F2F9FULL, 0x4938F29F2209D749ULL
        },
        {
            0xEDF6FDAE79FA311BULL, 0xCC12839FABEFA590ULL, 0x53376C687773E7FDULL, 0x01662CEAC2DAF6F9ULL, 
            0xDF4EE01A5589ED36ULL, 0x5AAD0FDCA7B77A7AULL, 0xDAC1AAF8B506E816ULL, 0x3FC88F4EC602DD4CULL, 
            0xF2A198E1C3038CA2ULL, 0x1043C5DEDAF0AAC9ULL, 0x84B26911EDD9D3DAULL, 0xE4E09F53907484A5ULL, 
            0x09D5242E4D30AFFEULL, 0x85CA2F2A0AE22B0FULL, 0x495744CC22FDA07AULL, 0xCFD040ED9496FE08ULL, 
            0x5F59DB747BBDBCB5ULL, 0x36B4A437D90F684CULL, 0x7CFB8CB8C6BCAFA2ULL, 0xFE581898FEC2013FULL, 
            0x151F5AD8419DF8FDULL, 0x109539755DF45107ULL, 0x956BE5A6DDD3B363ULL, 0xBBBD00275C41016FULL, 
            0x8C3B78CC753F8FB9ULL, 0xF254CD2792355499ULL, 0x81BDDCE7D9557F9DULL, 0xCB7E4B85F454C540ULL, 
            0x6BB2DE9A0748F5C6ULL, 0x759FF3559EAE4C38ULL, 0x22947F7A7A5C7F64ULL, 0x8FDDEC5AF3C484DFULL
        },
        {
            0x97470347F3772245ULL, 0xCABE492C19239714ULL, 0x4FBAB3287041747CULL, 0xC095ECE5833E0604ULL, 
            0x0E6366C0B8038A5CULL, 0xFAC5A0B0B3D9ADA2ULL, 0x4F1CCFED9B84BE8CULL, 0x8629B25AD49F2A87ULL, 
            0x6344CD0872E348E8ULL, 0x9F6365B33EAF24C8ULL, 0xF04F323BB70B9E37ULL, 0x49059535E115A1D4ULL, 
            0x2E38E98CB917111AULL, 0xF415C4275F852204ULL, 0x31023985C3DC31C2ULL, 0x74F5E254FAB943B7ULL, 
            0x57D4B282B53D2887ULL, 0xDA0E90FCB34B03A7ULL, 0x297A49AD48E8F101ULL, 0xD9653E8BF17E8395ULL, 
            0xD27CC530CC7AFB65ULL, 0x3B48E6F3A4D94816ULL, 0x0F648F7D28F64F49ULL, 0xE435655A772C5BDBULL, 
            0x96A19BF550130495ULL, 0xFE65AD66E145C331ULL, 0x0217D53205C9622FULL, 0x80662A28D2A369D9ULL, 
            0xAB984B294DB47633ULL, 0xBA28B55622D6F8AFULL, 0xBC81C231208370A7ULL, 0x8DF259CD40ED094CULL
        },
        {
            0xE1FC46B2BE23F233ULL, 0x949A559E9F7897C8ULL, 0xBA3CECEDEA8DF243ULL, 0x4EAD30C645AF7CF4ULL, 
            0x46EAE7822CBC21B4ULL, 0xD700362625F3EAFEULL, 0x5099BBA5C438A02AULL, 0xADD6F31CD161EA77ULL, 
            0x16A3C49864037BD1ULL, 0x12437BECB283C017ULL, 0x2EFF4417B9DC7BC7ULL, 0x531F45CDF646CC01ULL, 
            0xAC21538601E166D5ULL, 0x88B649C72C94C195ULL, 0xED9DC26EA037FE26ULL, 0x4F15E7B7D948DC51ULL, 
            0x3345054D6589B44FULL, 0x5CE95786EDB4FDCCULL, 0x1A7FE2F7CC490088ULL, 0x53B4851A43E70FA1ULL, 
            0x6BF220203C726A64ULL, 0xFB041B342384B5A7ULL, 0x5566A201B632F2DDULL, 0x30440162D58E6CC1ULL, 
            0xEFF0D19E8E4EB691ULL, 0x3BD643FE3B2573B8ULL, 0xEC8A5C9DDD048B61ULL, 0x99187961B3DA9C41ULL, 
            0x2A55F52A8E638587ULL, 0xA5ECE2A91F879487ULL, 0xCD46B734D19CBD8AULL, 0x174EF9F370EEF1C6ULL
        },
        {
            0xEF70549B5DE58602ULL, 0x32AD0D0E988512A5ULL, 0x69D999C915E9EDADULL, 0xDF0B51CD203B7FB3ULL, 
            0x623629EDB5C69240ULL, 0xB6E41E824CA5FFCCULL, 0x8281EAEBEA74F8B0ULL, 0x9083B0B93557C306ULL, 
            0xFF3F3CC15F60AA9FULL, 0x6317B170794ED8E2ULL, 0xE50CC2E1C6D03270ULL, 0x95070393B8DAD362ULL, 
            0x908C6EDA887973B3ULL, 0x51BB57EE734D1D37ULL, 0x6136B7526051991BULL, 0x121768A57F5AA7A9ULL, 
            0xB61432A963981CEBULL, 0x8DC4FBBDE89B6BA1ULL, 0x055A2F6499028D55ULL, 0x4FB8EF02D724DCCEULL, 
            0xAC68FF948D848602ULL, 0xA312E51B3477B94CULL, 0xAC17910EB7335E11ULL, 0x0105233660F90872ULL, 
            0x36C3D124B37CC412ULL, 0x3E27491C8DA3C9A6ULL, 0x57142EA59BFE3B03ULL, 0x006F93ECDB6551D0ULL, 
            0x017B8209DBF8FA41ULL, 0xAA1A2666FF1B3E9EULL, 0x8E7C57B17832AF91ULL, 0x72B9E18492B59D58ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseBConstants = {
    0xDB46A993F90BABEAULL,
    0x0394850D9FFAAD71ULL,
    0xC49675827EDE4FBFULL,
    0xDB46A993F90BABEAULL,
    0x0394850D9FFAAD71ULL,
    0xC49675827EDE4FBFULL,
    0x02D861235CB307E3ULL,
    0x287782E0C343F25AULL,
    0x71,
    0xBB,
    0x29,
    0xC4,
    0x21,
    0x1B,
    0xD9,
    0x85
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseCSalts = {
    {
        {
            0x82AAEEE28E3EF5B0ULL, 0x287F8E0DA4FD503EULL, 0x740897AD9D44F690ULL, 0x77278A0BAC0E07F1ULL, 
            0x4D8F34DC82FB3E43ULL, 0x1F3EC9EC7237D51EULL, 0x58DB29D6E7CC7CA0ULL, 0x8104AA1084BB3E9BULL, 
            0x7DE8967E888D02FBULL, 0x3DFB433D32CC1310ULL, 0x3029EF4FF375257CULL, 0xFE6083A33E31CC8AULL, 
            0x8BA9577D22A596CDULL, 0x1475DBA30071F494ULL, 0x63AAF86AF4F44DCEULL, 0x45B930D96FDA59FFULL, 
            0x062D71E25C3BCB0CULL, 0x1D9B3BA1E789CAA1ULL, 0x46652556AB440E7CULL, 0x53E1C8A9E2BF7C7FULL, 
            0xCA632E7370458605ULL, 0x2DCEDC5959CBD53DULL, 0x3CD3BC0C101354DBULL, 0xD2E851EB700A759FULL, 
            0xB8D79E7033013648ULL, 0x91C1C6A91D4C8474ULL, 0xABAE898A312BD9B5ULL, 0x4BF8F0B8933CEBBFULL, 
            0x650F4EAAC411E334ULL, 0xDBAD2875EC12A47EULL, 0x58E0E8FA08B5C6F7ULL, 0x56083C82FFE0848FULL
        },
        {
            0x73885DEC66ABA148ULL, 0xF7A9CA149ACF7C5AULL, 0x031AF614E08FA36DULL, 0x1D299EBDC9801873ULL, 
            0x1B4593EDDF37E2DBULL, 0x82938F00FA95CB31ULL, 0x0431DB0D793F4948ULL, 0xF76FD7D29D2DE359ULL, 
            0xB9435AC7FD610F7AULL, 0x2B1F833EEE45651DULL, 0x3287E3DBD3111AFEULL, 0x8A2B9ACFA1AD1FA8ULL, 
            0x0538356FE95BC82FULL, 0x3BD6C435CEAFCFAAULL, 0x13BF832A6D9F2ED5ULL, 0xE1ED189D08E723F3ULL, 
            0x26E46775DD552AF4ULL, 0xAB87353509FD71ACULL, 0x4849554458498F24ULL, 0x055701183F4B699DULL, 
            0xA3FA1B081F6E5FB8ULL, 0x84687178775C7A53ULL, 0x63757C99DC125039ULL, 0x319E79D0B13B27BEULL, 
            0x2A6DA33C74D434E6ULL, 0xF49D0413E2B58D88ULL, 0x0B2AE5781440C4E9ULL, 0x187BFB1308D7247BULL, 
            0x0ED86E81AEABE976ULL, 0x84DE487128186436ULL, 0x45CF4F46C5CEA4AAULL, 0x180BC56F677DABEDULL
        },
        {
            0x7F222971B79DC546ULL, 0x74E5C508161EF8B9ULL, 0x701D35DDEAFFB8BFULL, 0xE0ACC93B0F47B286ULL, 
            0xF3C71F91E9E1B178ULL, 0x3131C1BF3F0E4AFCULL, 0x17ED8C258EBE1008ULL, 0x951273C27E7BAC25ULL, 
            0xD7473813FB4D379DULL, 0x154CE39311633418ULL, 0x3CCFFF36FFA5BC55ULL, 0xE8A0ECEACEF2DC7FULL, 
            0xDF3B75AC48B48F9DULL, 0xE0BE92AEB6887593ULL, 0x1C98596131F7F5C3ULL, 0xDA7A143F5AC7FF4EULL, 
            0x3F12D59C48E33F5DULL, 0xE784BEE06259916AULL, 0x1D934DAE7428CE4DULL, 0x189E7E08F01BF297ULL, 
            0x428694010B8765AFULL, 0x878BB06D8656E969ULL, 0x42EDEAB9CC00DA62ULL, 0xDDD722BCFE35D1DDULL, 
            0xBA1773E64B406320ULL, 0xB982E9F90893733EULL, 0x3E461C1EE2588A70ULL, 0x83AC23A8D51841FDULL, 
            0x59EA6E03EC28B77CULL, 0x18393798DF70D376ULL, 0xD588A01BA9983A35ULL, 0x1AB6E70ED8C2C7C5ULL
        },
        {
            0xC2E495E2C1F1DC15ULL, 0x16527395806BEBE1ULL, 0x9B9293B32B188FAFULL, 0x1092D2B022E06083ULL, 
            0x9121180128D6B2FFULL, 0x8A0B88E273F9BF79ULL, 0x3A89BD1D85CAC681ULL, 0xBD8691CF25160ABFULL, 
            0x7EAE825B0D227726ULL, 0x3EAE0E5FB4BC3B90ULL, 0xE3213AC87129AC83ULL, 0xD08B483D62DDF725ULL, 
            0x63EF95AEDA4A4812ULL, 0xF1AE86E1AFA27CC3ULL, 0xFE47C189FF638559ULL, 0x064C04EE3E92E2C9ULL, 
            0xE0F6FCAAEEED2291ULL, 0x729D8A67D313E3A5ULL, 0xFE235255367FEA99ULL, 0x7A68786547351304ULL, 
            0x071EF9CE89A0020AULL, 0x1CE9F84061137B39ULL, 0x36540E963F563200ULL, 0x124DEAA54038DA75ULL, 
            0xB11DA7C7EFBD88F0ULL, 0x668326E491DFFEADULL, 0xFBADD05BBCCB7334ULL, 0xCE24494DDA9E920BULL, 
            0x49353B0BF05A0C53ULL, 0x82DC288E25201CA9ULL, 0x5445B6907BF420F9ULL, 0x141E1B698372B2D7ULL
        },
        {
            0x2AE1A871389484E6ULL, 0x8E0F8AFA671A3BD9ULL, 0xDDF52F6E939736EEULL, 0x5B964724EBD0971CULL, 
            0xA9DF41E3FBA22EFCULL, 0x78B4006166B43F03ULL, 0x4DECF1D99CFC91C4ULL, 0xBE35EA8D3BA1C56DULL, 
            0x175799FF1D59EE68ULL, 0x39DD08F635645B9BULL, 0x1D6717E4DE0BBE4FULL, 0xEE8AFA4FCAE8B508ULL, 
            0x761D542053A6E268ULL, 0x5C21AFD8CE3661B4ULL, 0xD555AA92C14C2A4FULL, 0xB107112036DA40FAULL, 
            0x6FB7FFE0A7EEC3C1ULL, 0x44B243A1920AFC07ULL, 0x7DDA6697187D12DFULL, 0x51AB7BD3A1E202F1ULL, 
            0xB03D0943E022F278ULL, 0xDE9359DF3B0B4A7CULL, 0x7F6F22A9232FF63FULL, 0x01B4C59928E4EC36ULL, 
            0xF435714D1FF0C7CDULL, 0xDB8E3A86102E6F29ULL, 0x6FBD44AB04A26CABULL, 0x9316C558DC3834BEULL, 
            0x865960469C596264ULL, 0xEB6B71384B352695ULL, 0x625C2A04B99077FEULL, 0xFB32B8D959A1E473ULL
        },
        {
            0x511278D30960A024ULL, 0x9E13731382E99E1AULL, 0xC586A6CBE76C6207ULL, 0x39DF94C6C46E0D9BULL, 
            0x172D63A508E50FA0ULL, 0x90488748F09A46EEULL, 0x628EDF5125EAC545ULL, 0x11B819D5023445F2ULL, 
            0xA81960F0B7AAB08CULL, 0x7AAE1270CB3D1997ULL, 0x8E81CEE8F9159D8DULL, 0x59028445527F07AAULL, 
            0x9BA7B4A9C63FB805ULL, 0x53F1C4225A4BC6F4ULL, 0x5ACA612632B93C37ULL, 0x4E682F3315E9FA70ULL, 
            0x826F3F5103340D6AULL, 0xB65AC7E4705F994FULL, 0x07B16217E36090A3ULL, 0x24118000A0D46693ULL, 
            0x76D6927DDB4903D5ULL, 0x83D8526293A0CA23ULL, 0x6F16822C6CB4C6A7ULL, 0xF9E892C7A1086BD2ULL, 
            0x6D572172B2FB73DEULL, 0xA7B6B3A3575F2A9AULL, 0x2ADF454FEE025642ULL, 0x5BC587083553DD4DULL, 
            0x0AA48387B37BBD64ULL, 0xFEA47D7FA9DA27B9ULL, 0x381CCA2E2D3CCFBDULL, 0x51D911D9D971840FULL
        }
    },
    {
        {
            0x456229ACD7AB5C08ULL, 0x47A227234EA34ED1ULL, 0x43EC674F4294CA2FULL, 0xA3B3AC082D011ED7ULL, 
            0xCF8DA1E56903D5DCULL, 0xD825006BD61C77ADULL, 0xD1CD37AC2E1CE036ULL, 0x5A2AC93004EB9C3AULL, 
            0xDFE27A05A0019D24ULL, 0x07F550C9EB99A9D1ULL, 0x9C06D34EAEF837F4ULL, 0x8065EBC7492F0987ULL, 
            0x852406327E7AE839ULL, 0xC01E558A2E08691AULL, 0x4A916ECC2A64551CULL, 0x28163A4DFAE32BEFULL, 
            0x65C6BF194D4D63C6ULL, 0xE82AD1FCAD058633ULL, 0x424102F8752F7AF5ULL, 0xEDC0324D1DF50482ULL, 
            0x9F08E2BF48204595ULL, 0x6FBDFB12A76ECBB7ULL, 0x13B3BE92B82FFA3AULL, 0x7DA03A70439B4492ULL, 
            0x9EA7662A65D24FF2ULL, 0xDD25F7EA3F37E75CULL, 0xF4ACBDCA34C0F7C9ULL, 0x7D86222744D9F249ULL, 
            0x0F6A83265F95B599ULL, 0x10C78B55D8ECFF72ULL, 0xFE66EA0D5D3F4649ULL, 0xF5196DE90FF0711CULL
        },
        {
            0xD362BA2191A1AB86ULL, 0x1AE4CF87C8D7B1B2ULL, 0xD6A9823ADB7FA5FDULL, 0x7045D56DA9EF51CFULL, 
            0x94B0416269F21108ULL, 0xBEB38872CA85353AULL, 0x6ACF517EF931ADD2ULL, 0x19CA39652F6CC374ULL, 
            0x447A76E64D76F13EULL, 0x1D214826037F6B12ULL, 0xEB676CF07E3458C4ULL, 0x795D290496F46C7CULL, 
            0xA2A1523895DE395AULL, 0x03E27574A253E844ULL, 0x463AE8A22E800CA2ULL, 0xCEA31BC0AA64F27DULL, 
            0x06A94B40166C5AB8ULL, 0xF9F9AC6F3B38CD94ULL, 0x82421287713FA8BDULL, 0xDE945985BB085EF0ULL, 
            0x3D2D865C5104F5D9ULL, 0xC572E997C4D79BD8ULL, 0x22E014CF8FD7ACF9ULL, 0x3C41047ED1C56E83ULL, 
            0x778DF3E22FA3A861ULL, 0xE978B5987D5552CEULL, 0x92562C22743C22E4ULL, 0x505A6B745DD2D142ULL, 
            0x7336D8ECAE776BDAULL, 0x3ACA9D3981E69BF9ULL, 0x0BEE794567402C76ULL, 0xBB9DCDCB64880399ULL
        },
        {
            0x8575AF3EFB94F3E4ULL, 0xCC0DB6EA900BE1B3ULL, 0x41B20536CCACB76DULL, 0x26F93A22F3BA911AULL, 
            0x581B2D7759378B98ULL, 0x833ED2BF7A07469AULL, 0x5797B47041C93A79ULL, 0x0521C0542D104EE4ULL, 
            0x21B35F410A859088ULL, 0xA9E02FF794F5BC0DULL, 0x2D408011BB6829E9ULL, 0xA75BC83D3037BECBULL, 
            0x0F719C48FF577A4AULL, 0x7812981EA79D7185ULL, 0x5125B19D7935965DULL, 0x3647C9FEE7C2B74EULL, 
            0x94789A328928B23CULL, 0x444BB3550425BF9AULL, 0xC7C73E5528B1BB65ULL, 0x2D54E2A8E25BC83DULL, 
            0x92350B2A3C6A2FE1ULL, 0xC24BF168CE461DC1ULL, 0xE9A4793D9C1CB8E9ULL, 0x230DCE5C1EA4EF9AULL, 
            0xCAA07FC040618745ULL, 0xEEDF39B9826D8632ULL, 0x06BDF9F800203566ULL, 0x258B8B23014AEF6FULL, 
            0x839DA1301F528B85ULL, 0xD56E6EA920F7531DULL, 0x5A70E95684645458ULL, 0x06D957CF2C00BE66ULL
        },
        {
            0xB5CC2151F853CCFFULL, 0xEBD7EEDF6689DE5EULL, 0xF958C85591F67D64ULL, 0x11E1A0C6A4BE1725ULL, 
            0x38085D614AAA893BULL, 0xEC9E7C8A62C64E9EULL, 0x89A49C3C7E012F88ULL, 0xCD27322FE31B56ADULL, 
            0x78C000DC3666307DULL, 0xAF241D72FB7DD8BAULL, 0x37A319B74BF69A65ULL, 0xAE0AFB3516D68984ULL, 
            0x16545ACFB625C91FULL, 0x05079B1E9D04D677ULL, 0x3564594ED1A95B35ULL, 0xA59CF331F05A6E20ULL, 
            0x841776A1D307F094ULL, 0x9CBB69D53CC7EBC2ULL, 0xBC5AFF21C81CF7EDULL, 0x6FA21CC1163F18BCULL, 
            0x3EC33E9CFD7A4110ULL, 0x0402E0FA328899A4ULL, 0x368743FB6A8A2343ULL, 0x10AA0229CFA970A6ULL, 
            0x5E49C477D96E50E5ULL, 0xB365538395A9F3B4ULL, 0x9498DD6DABC03672ULL, 0x50906AE575F003BAULL, 
            0xB6AE46F4504D6F65ULL, 0xBD08BC96ED409F6EULL, 0x5BFD21130FB8163FULL, 0x0A534E8D2DC790E4ULL
        },
        {
            0xE5906C2778BF65DDULL, 0x7FD1321E9CBB8D87ULL, 0x01D9F9B808D7F176ULL, 0x954D5171B7245B6AULL, 
            0x5EE1EE2E96B48155ULL, 0xD731CD961EA8C809ULL, 0xBC14A6118464B40EULL, 0x0A292198E6871B8BULL, 
            0x1D8FC5B769BF6DBCULL, 0x02E62C89B7B72ABEULL, 0x0E2ADEC3CEC65BE8ULL, 0xFF39D5807137862BULL, 
            0x4CD49040D4DBF017ULL, 0xC048B1AB121AF8D8ULL, 0xE11A34503A3C05B5ULL, 0xF4615916008B232FULL, 
            0xD512E7C011DE3D33ULL, 0x2F706F95EB97507BULL, 0xCD5E74950C06A725ULL, 0xC19093AA6B55D55BULL, 
            0x13C9293FDF4C839AULL, 0xD49DF68062077C35ULL, 0x5BE3BD8BC4DD3A3CULL, 0xEB80A2C94F828A83ULL, 
            0xDC15FE5DA1A998A8ULL, 0x2B8CE442B35E482AULL, 0x645C1D0551CE8AC4ULL, 0x8508FBC8B78AE3D2ULL, 
            0xC7083E185EF68B17ULL, 0x71F061B7B43F4F0DULL, 0x2C04F882D82EDB8FULL, 0x0E77F770A013479AULL
        },
        {
            0x610CF61B6F998460ULL, 0x879033AD90E7079BULL, 0x4F13937139C7AC10ULL, 0x6D79484000A22F9CULL, 
            0x25F2036639AE98DCULL, 0xA67A6F71BE7FE937ULL, 0x6616D7AC0C643A59ULL, 0x948D3DBC826D43C7ULL, 
            0x3948E8670313C2C1ULL, 0x93A3FF62118E514BULL, 0x202ACE89B938425DULL, 0xE2F1C82E74D8CDF9ULL, 
            0x77A721ADCB1BAEC6ULL, 0x3AF1CB2419561DFAULL, 0x070B89B50F621FE4ULL, 0x3E4BF55A97877041ULL, 
            0x6D7435B1C08D187DULL, 0x1B9681A34429307EULL, 0xEFDD81FC80045C83ULL, 0x732DE554061CB4FDULL, 
            0xC349CACA10551DE3ULL, 0x0564D94A93062247ULL, 0x9EDA08616E662076ULL, 0x717B3C3D155E37F6ULL, 
            0x7605BA57F2AD56F2ULL, 0xDB931C3637CF9E2FULL, 0x1570917F169859B2ULL, 0x9EEE6EB729E0BDF2ULL, 
            0xF3008F2DB2487299ULL, 0x6D4F8C959C9E2077ULL, 0x0408BB0F27A22DA8ULL, 0x02D17AC3B56BCE5DULL
        }
    },
    {
        {
            0x89E2BD7899BA1D05ULL, 0x18682B2D7FDCEBFAULL, 0x2FD0585A69FA957CULL, 0x9002BBCC07F336CDULL, 
            0x75FAC70AD4B6B88EULL, 0xD604A45EA3728A96ULL, 0x1799AC96FE1EDBB1ULL, 0x15354A336C6B6A44ULL, 
            0x1A01265438719723ULL, 0x5AEEDAB9DD6593A2ULL, 0x93A4A75178CAE632ULL, 0x084AF6893E17C0FBULL, 
            0x72A150BBB166ED60ULL, 0x636D97D97641389FULL, 0x589A5F7EABC19DE4ULL, 0x57EB020F324E0DCAULL, 
            0x7C81E415FB203F07ULL, 0x7180581A185B8CB8ULL, 0x9387F27D19B1CC5FULL, 0x626B05F6C6B11285ULL, 
            0xF18640381496756EULL, 0x52184754B64EE829ULL, 0xAFA2BAE2F3E9BF12ULL, 0xC846F77A9556A6E8ULL, 
            0xBFB695713F5865CBULL, 0xE9CD057A71E7390AULL, 0xF5578C736AC92636ULL, 0xCC446213D00F0AE5ULL, 
            0x418AD503954BEB99ULL, 0x866F667BE1603456ULL, 0x96F1D8B2A6C99B33ULL, 0x4F0C970AA80597D3ULL
        },
        {
            0x7162FBE0D6659256ULL, 0x8BCE791F20589D1DULL, 0x5D8E7F22C2BDA53DULL, 0x5922E2C05F6D27C4ULL, 
            0xD67A3333C3A5CC6DULL, 0x97EADC4E73027465ULL, 0xED36E0FF2BD73966ULL, 0x0E034F1B5559F5BEULL, 
            0x4DBF223D5B42A38DULL, 0x5C035890AD924737ULL, 0x4D9D4D72F4EF3078ULL, 0x12DBF40411F37611ULL, 
            0xFB21FFA59FEA7E0AULL, 0xF355F235D66BF258ULL, 0x0D8A0C48385009FBULL, 0x5911874845C0399EULL, 
            0xC0BC6C531CD75BD2ULL, 0x1AD4CDE73318CC53ULL, 0x616964DBB2C6879AULL, 0xEFA9086577A25126ULL, 
            0x50E3A9B4B9E0C59EULL, 0x137035F47DC8C95CULL, 0x6A469F3FD0FE93ABULL, 0xC9BD8FE5616F217FULL, 
            0x36C642E337330B89ULL, 0x82C2A1CC6FB9F7C8ULL, 0xBE38E0515A6AB95EULL, 0xCC39F9C00B44909BULL, 
            0x6F785E62E3AD4FBAULL, 0x70841185D8B772F8ULL, 0xE7745E1434AB5B0AULL, 0x82736D04A750CF3AULL
        },
        {
            0xACF327398EEB81C7ULL, 0x08037935B242D19EULL, 0xFA7EC13377A31F5BULL, 0x70AA3791472E3D10ULL, 
            0xBE10E6D2D292C971ULL, 0xB0E35818A647B276ULL, 0x0A879B6601797483ULL, 0xB6C58D4EB0C718AEULL, 
            0xD9F665C80E44AF71ULL, 0xF2A086F77B1A8C50ULL, 0x45400C195DF58174ULL, 0x91BBA9B7B45C4D05ULL, 
            0x870C2C4FCEE8D7FBULL, 0xBB78E76B49823872ULL, 0xDC30FBF59E2DA2DDULL, 0x05C78B0A20ABE54CULL, 
            0x41BB67067D539A16ULL, 0xD533C8EF8E76A9BFULL, 0x3D599A4F350F00B5ULL, 0x0B73851E13A00CEEULL, 
            0x90A90535C0D9A5E3ULL, 0x78C32F4E0A7AEA6AULL, 0x0F40B3C7CE866BC0ULL, 0x681ED5C15A254531ULL, 
            0x61F71439C9D81BF4ULL, 0x9A18392C98CC3FA4ULL, 0xEACB036F6F2CEDFCULL, 0x8D96CFC57D82294FULL, 
            0x8E80AA3F315EA6FAULL, 0x98464E77EB0921F7ULL, 0x81B3F04867D87934ULL, 0x93FA68CFD4E32498ULL
        },
        {
            0x705122C0373E8C08ULL, 0x540D8B5EA9DC075FULL, 0x2795805F3FA1E5FAULL, 0xD66950228FAB3B10ULL, 
            0x096BA3B6FFA8D22CULL, 0xB6919BAEC27DC73CULL, 0xE67F798444294542ULL, 0x33FB3B83D4E1F170ULL, 
            0xCE470031CCAD676AULL, 0x01DFBFF2D09CAE9CULL, 0xCAE0288C62B2F4A5ULL, 0xE8B48B9C72B53ED8ULL, 
            0x72B001F043411D51ULL, 0xC5C7A20E2CCFE3BFULL, 0xC568C2AB4945852AULL, 0x552DF29C5ADC8495ULL, 
            0x67E8DFB41E818200ULL, 0x66CEC98BF267B040ULL, 0xADD5D47AA22B2DD9ULL, 0xBB8C04B048AADC94ULL, 
            0x8DA7AB5E6ED468FEULL, 0x39EE66A4A44EACDBULL, 0xC2F9D42F9786328BULL, 0x6D6D76014558E8A3ULL, 
            0x28674E5DD784809EULL, 0x07E7235539ED81CCULL, 0x9C006101A8C1FA99ULL, 0xED660AFFE9976596ULL, 
            0x00E6F660B94CC9C3ULL, 0x79891281C015E688ULL, 0x5E6F1062E19D3D36ULL, 0xB3A20F155A54EE81ULL
        },
        {
            0x12C86CFDD32A6F03ULL, 0x90CAF0B28EF77998ULL, 0x701EB6F6A1F69873ULL, 0x014E9B33ABE6D508ULL, 
            0x3287AB8C9AA17551ULL, 0x757E9DEE5F3C1BBDULL, 0xFFF57CFA2C955024ULL, 0xC81363337661F408ULL, 
            0x5B3A5B0A8E12E82AULL, 0x53D47F1EA846E334ULL, 0x44FA2848B34FA19AULL, 0xF51F94D6551C2B28ULL, 
            0x64435A41D430B948ULL, 0xF343117E0C3A73F9ULL, 0xFDA40298D6249E73ULL, 0xEE9A0078B9649B18ULL, 
            0xC43E4934A8CA769DULL, 0xDDF8FC16DF483009ULL, 0x823444ECA65FF6B6ULL, 0x0C316D4CA7D3F593ULL, 
            0xAA95784AFEA7BD61ULL, 0xDA53B2DA7A7F3F83ULL, 0x1A01CE6FEECE28C1ULL, 0x0889B490F0F32ED0ULL, 
            0x13693E8F0DA73939ULL, 0x15888655E6D3D6E4ULL, 0xFFE95D8382CBA991ULL, 0x0AF160D1B06E4B47ULL, 
            0x4EE13169E4B4E32CULL, 0xAC6BAE62D7F83177ULL, 0xD02CCF8EAE37D1A6ULL, 0x23BBC7EFC6376384ULL
        },
        {
            0x7499B39ADFA29BE9ULL, 0xE96F39A606FFF735ULL, 0xD7EAC525D895CF23ULL, 0xCF04FA90DC7109FCULL, 
            0x7376AB93D45C035DULL, 0x8D5484CFA7E9EB8AULL, 0x42AB76E943D802BFULL, 0x7F9CC8D2E9C705E3ULL, 
            0x3F8943B9BA074948ULL, 0xDA84A0D2373C5A4CULL, 0x54C312781864C9EFULL, 0x49FFD57194232764ULL, 
            0xDC756DAD4E41E16DULL, 0x4F101ECDA8B9AC1EULL, 0xE19E90CF2D727B75ULL, 0x17C2BA9A569B147EULL, 
            0x0A8576F169B82058ULL, 0x9D26F760F2AB873AULL, 0x1BA782D67DB1DD81ULL, 0x2EDE394FC281829DULL, 
            0xEF23C5984241F5C0ULL, 0x693B9ADA76397573ULL, 0x69B1DB30FC878B41ULL, 0x1D4682395A22B445ULL, 
            0x7DC9DDEBF4E24061ULL, 0xBF22C661C8C5195AULL, 0x15B971D67FCC86AFULL, 0x4EDC401886ED1DA7ULL, 
            0x6CA0DEF26FD972D9ULL, 0x38034F5BCAF07B31ULL, 0xB20A9A0E1D853445ULL, 0x78C9D21331B40414ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseCConstants = {
    0xA18BEFBCD9FA0B5FULL,
    0x72756EA297E27E42ULL,
    0x771E4DFDE6994C33ULL,
    0xA18BEFBCD9FA0B5FULL,
    0x72756EA297E27E42ULL,
    0x771E4DFDE6994C33ULL,
    0x885A834B88BDF425ULL,
    0x01F2D87214EB5C2CULL,
    0x94,
    0x1E,
    0xF9,
    0x3A,
    0x6D,
    0xA2,
    0x1A,
    0x0A
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseDSalts = {
    {
        {
            0x87789EF80A1557B5ULL, 0xFDBFA61F75C35ADFULL, 0x286725DD81616699ULL, 0x969199F342CA72DAULL, 
            0xB0F44B85A6735AAFULL, 0x622E063B1EF18F61ULL, 0x7798D0D9E5228335ULL, 0xE3BAC3F4E15BCA13ULL, 
            0x01FCF3B8A28F6CD8ULL, 0x211D87C58A3DACB1ULL, 0xC8E2378026C2B791ULL, 0x261F2581AC52241CULL, 
            0x167FFFBA2CDB84BFULL, 0xE9FB5D5694D3D68AULL, 0x9124E1A862B69D7CULL, 0x91B7EF0C2E847B7EULL, 
            0x1ADC4E0512788A32ULL, 0x4FC810571841FDA8ULL, 0x46DC1B6A25CD8794ULL, 0x629944404AB41AA5ULL, 
            0x79F73E365395E423ULL, 0x5E8F38E3B46FD104ULL, 0xEC0978ED0B666719ULL, 0x2F31FD786CD9937DULL, 
            0x08250EEB57271366ULL, 0x38CCED096D058F85ULL, 0xB589C04EDF7F1FB5ULL, 0x30886BFB1DFFA119ULL, 
            0xF02A7B049A54E940ULL, 0x7E088251699A976BULL, 0x0D6CC87AC92E1A3EULL, 0x323A77B217541369ULL
        },
        {
            0x427EBA8BD6878175ULL, 0xB568D430E503A72DULL, 0xD689640BEFC510BAULL, 0xD3380193FE983DCCULL, 
            0x9CA10B0391DA7427ULL, 0x5D4291971CB94AAFULL, 0x650E76DC40AC81D1ULL, 0xD5B69EFDB712F99AULL, 
            0xEDDEB1F570880654ULL, 0x14AEEE2447987D59ULL, 0x8547FF0B3EF0293CULL, 0xF749DEE8860E65B2ULL, 
            0xDE44B11B1AE82A64ULL, 0xAF923D0E47756041ULL, 0x385BEC16BE3FB3F4ULL, 0xABB64BB211185D93ULL, 
            0xEA71D3FF61F18D7BULL, 0x5652F7836782CE9CULL, 0x7ADADB2F9673DDC4ULL, 0xB3F308A0E862D6AAULL, 
            0x73EDA1D5FA585F30ULL, 0x8B63FB20FF61CEC7ULL, 0x7D40224CA0B1C631ULL, 0x8ABD3549514A1AF2ULL, 
            0x3427EA082DEAE54DULL, 0xB61E3A4A5ABE6774ULL, 0xCDA357A6C4FB39D8ULL, 0x8CFD0133AE36CEF0ULL, 
            0xD3A25611539E5EF6ULL, 0xA08E913927B32EB7ULL, 0x5A3362A6DD183823ULL, 0x4E73534D0D637644ULL
        },
        {
            0x0BF0C6710B51528CULL, 0x5885836C637987E5ULL, 0x9E59D4821A69F312ULL, 0x8A6B1F317FB786ECULL, 
            0xAC5337E6383CC2BAULL, 0x9EA30F82129CE21BULL, 0x87E808B623C3A8BCULL, 0x7599BE8955554ECDULL, 
            0x1748C4F659B0EE61ULL, 0x73B07E8DFC95FED0ULL, 0x7049895B4CDC008CULL, 0x2DEABC7F0FFCACA0ULL, 
            0xA317964F1E79B18AULL, 0x5B844B54DC92B6D8ULL, 0x5DDA85041C244BBFULL, 0x5F836709B07D81EFULL, 
            0xE586444BC1806CCCULL, 0x5BCF538554E30AB9ULL, 0x04BB94F4866E3C2CULL, 0x8F9A61398C4EE9A6ULL, 
            0x1CCD16AE90ABCDE9ULL, 0xFA4FE99479FFED42ULL, 0x06F546FCD154A199ULL, 0xF07F07D71BFD811DULL, 
            0x97C65FBCD45C6D05ULL, 0x5EC3382C7259F4EEULL, 0xB8419AA8EED0C63FULL, 0xF1F4BE0989FBD62EULL, 
            0x6F59FF4C8D8256D6ULL, 0xDC55905AF3658EAFULL, 0x1C69A2FB66DF5D8AULL, 0xCF9BC5024AAB7603ULL
        },
        {
            0x4EF1641E117B7309ULL, 0x9C33FCA95B2288E5ULL, 0xC18FC17B43CFA2DBULL, 0xE8A8DAFFFA29CC94ULL, 
            0xC61AE891255FD29BULL, 0x2E84D3202E29B4B3ULL, 0x0E10BE1081C56DF9ULL, 0x4198D3170D3884F4ULL, 
            0xC100A84880B2D8F0ULL, 0xD9F25DA4B676522DULL, 0xDD52BFEE15DBEFB2ULL, 0xFEBC63521959B71CULL, 
            0x366236865F53B138ULL, 0x759E9BC6DBDC6F4EULL, 0xD16DD8EE3871DB90ULL, 0xCB15AF1F93FB7976ULL, 
            0x54F1BF370F3F3E8CULL, 0x42EF38F4445FD984ULL, 0xD92E47B4F7D29FBAULL, 0xAFB1808004F964D4ULL, 
            0x39771C17EB5046A8ULL, 0x2F1E84BEBFD76689ULL, 0x105D4CC6A9489857ULL, 0xC56BB8C10E331ED5ULL, 
            0xD33D1DB27E1563C0ULL, 0x5C33922A2A49169AULL, 0x965503659958EB9AULL, 0x9F7FBD94E7734D18ULL, 
            0xC5DC3088862B0859ULL, 0x842C31F2CF90F2A3ULL, 0x9AAA1EB05D970C3AULL, 0xB384242712404408ULL
        },
        {
            0x8AB40132CA1A3BD5ULL, 0xFDC4BE6F849D3875ULL, 0x691C8D041E4E984CULL, 0x7351D44A7FEEE975ULL, 
            0xF82ACFE1369D2547ULL, 0xE7E07E5564A0EDF6ULL, 0xDFCAEF4C8B25186BULL, 0x628FAD61F5973466ULL, 
            0x66106B3737C66C62ULL, 0x4A8E2A7BFDB57575ULL, 0x3AB2C4448EEAB36CULL, 0xE336E3800A9A413DULL, 
            0x11DAA95A2331E65CULL, 0x6935326A5E763460ULL, 0x5A4D049BDECB3A53ULL, 0x6D051CE78AA912C4ULL, 
            0xEB10BC514B4DC29DULL, 0x1123FADD0E50355BULL, 0xFC80061C60ED063AULL, 0x5F95778EB6591654ULL, 
            0x570D6F809990E055ULL, 0xEA9A680BD06495A8ULL, 0xDDC27E152B98623EULL, 0x52577EB259242C5FULL, 
            0x6B79625D5442A60FULL, 0xFA65ED2B011D8183ULL, 0x7953AA4771AEBF59ULL, 0xAF46AB4337411024ULL, 
            0xED1F151B1C68D6C6ULL, 0x5F76297A015E2D3DULL, 0x5D6F82BFC532C02BULL, 0xF44C4AF03257E6A8ULL
        },
        {
            0xB1749DE08780D36CULL, 0xBA21F3D47386C0FBULL, 0xBA1A327C6ED8E2F2ULL, 0xCE85C66EDDA4259AULL, 
            0xCE8735FAEE5BD1CAULL, 0x9484AC00B294EE3EULL, 0x601F569CBE990D7BULL, 0x200606B30B8C47A8ULL, 
            0xB094A28004698B31ULL, 0xB37026FFAFAA08EEULL, 0xA7758E6D6D27029FULL, 0x00CE399731210063ULL, 
            0x38DE717A589725ECULL, 0x6A33C96FD1CCBA55ULL, 0xC5523C6E058426A4ULL, 0x0AF80D2F2103797BULL, 
            0xC0A9CB6D684B0ACFULL, 0x0930A32527A5F1A3ULL, 0xA72AB34812F64613ULL, 0xDDF8DEE8CB2FE457ULL, 
            0x28E2053908984FD0ULL, 0xE51E88285DC0360FULL, 0xF757A9809107C6BBULL, 0x0C329C402126FFE3ULL, 
            0xA741B3150C47EAE5ULL, 0x0333F81B905381AFULL, 0xB04287D1F4477E0AULL, 0xC0A97B8D3580AC1AULL, 
            0xD3943DEA3F5DBCD1ULL, 0x99A82FD2BF0E992DULL, 0x37F1DE7E51BD435EULL, 0xEC845A398354A982ULL
        }
    },
    {
        {
            0x75FED99F97F0908CULL, 0xA9BCFE0900977857ULL, 0x6D9A6EFC564E2FF3ULL, 0x1CB99E577916DECDULL, 
            0x3181CFD92BA9DD6BULL, 0xB9D4F8C1A3E00567ULL, 0x9452EC0D46FB8BE9ULL, 0x2B939AEA6E4344C4ULL, 
            0xA8126A62E01F14B0ULL, 0xED0383817B63D5B3ULL, 0xDDF3674D6F51899EULL, 0x20AB7F924F167B34ULL, 
            0x806B276186DF7AF9ULL, 0x98890063E0CDCC8AULL, 0x029CF09EE37CEEF1ULL, 0x149F9588E9233C6BULL, 
            0x63C545726AA274B9ULL, 0xE9DD77423B004E02ULL, 0xA517C3FD473A07F2ULL, 0xE69C8F5B34D7838DULL, 
            0x28E5E30D609BCFF1ULL, 0x521EA98D5E27706CULL, 0xF68918453CDAC28DULL, 0x3B259D4070CA2C2BULL, 
            0xA63B5B901FBE0AE8ULL, 0x9267098ACE9BE9BCULL, 0xB16C2E447CA53D48ULL, 0xE52513EFB1E39882ULL, 
            0x78E8F82C795E019AULL, 0x374679C5FB45AD98ULL, 0x2BFDF3B3725B1D53ULL, 0xE5CF839585E8E027ULL
        },
        {
            0x1813ABC114E0EBE9ULL, 0x3DDF3A1BB5E6C47DULL, 0xC3EAD6CEBA57171EULL, 0x0567F591CCD30331ULL, 
            0x60C6606ACB6D75DEULL, 0x79D8CA20FD567892ULL, 0xDB78EDF54AC8C759ULL, 0x5148B15DED0A1F26ULL, 
            0x0FF48DE51C368113ULL, 0x3E382A5C7782F08EULL, 0x392F30AD729B3041ULL, 0x48EBDF1E38F90300ULL, 
            0x03C60120B1C4DDCCULL, 0xE3E5AB2320E98299ULL, 0xA92F0D37F54990EAULL, 0xF20A8BF35FE4CA9CULL, 
            0x2A17D51E8DEFB332ULL, 0xABC9C809FA442705ULL, 0x8316D2BB26260E52ULL, 0x27072DEC271C2FB6ULL, 
            0xBE82592025EF6EBDULL, 0x55A77C2EE4F73BD8ULL, 0x8A2E4D0C44336B2CULL, 0xC147CC0A562B9B8BULL, 
            0xDFF9C5ACCC736577ULL, 0x77F6F4ADD772D95AULL, 0x956B65F7FB23C406ULL, 0x0D047EE6EC47FA29ULL, 
            0xEC4C8D55BA51CC40ULL, 0x5D9EEDBAC0360FECULL, 0xC04DF5FF76FA062FULL, 0xD3FB948F407FE0B5ULL
        },
        {
            0xB64616EA8E919810ULL, 0xFBC94CAD4B87CE29ULL, 0x00038B5FB5972EA0ULL, 0x8A2C29D2C02F6C6BULL, 
            0x182194E20BC7113AULL, 0x88636E33B34F2F54ULL, 0xA6CBCDA310E607FAULL, 0x66F0A627A726595CULL, 
            0x266BFDAC69AB7C72ULL, 0x130AA9E5660F80F6ULL, 0x7BF513864654DC60ULL, 0x99DBAEC3A82CC151ULL, 
            0x7730C4CAF710DDB2ULL, 0x10D690A98C341006ULL, 0xE9497A4CD24D1F2FULL, 0x7F283D32CC6691B9ULL, 
            0xD25B9F0968FBE777ULL, 0xCD9FC6E48297F310ULL, 0x5C0828CAA74310A8ULL, 0xAFBC67EDFDA40A67ULL, 
            0xF5F03091B7A931F0ULL, 0x16EE636FA1F9E5DDULL, 0x78CEE8CF15C2529AULL, 0x0A59BA906E536870ULL, 
            0x8B62A4343FD60FC5ULL, 0x6D2DF63F5988B39DULL, 0x9ADDD0A80D66C630ULL, 0xF22E71F2321DF640ULL, 
            0xBCA6C91CF9F80756ULL, 0xAF3F89C089575ED5ULL, 0xF238648E0266E964ULL, 0xC695F6765A0DC286ULL
        },
        {
            0x7BDF441272FB1DD6ULL, 0x3F90CA6E0D874FADULL, 0x1980E87AEED359D8ULL, 0x74B4C1750F3A12E4ULL, 
            0xD05928C315A8ED07ULL, 0x5649CB054ED3C1B0ULL, 0x87FBD098A170870EULL, 0x2D73F1936E3575F5ULL, 
            0xA01179A4C6919E7AULL, 0x42381D7CDA748491ULL, 0x5E3E8FF8BD3FA083ULL, 0x0E527BAD33637364ULL, 
            0x0BAD56140B31D597ULL, 0xBEADC277D9931584ULL, 0x1C02DCC5D7F1F455ULL, 0x552E807CB0E3A5A4ULL, 
            0xB1343E0148E7B959ULL, 0xDC033A80A6FF2073ULL, 0x6A56DD1A0CB9B5D4ULL, 0x4C7BECE4895D6A10ULL, 
            0x9F169E6840BAC04DULL, 0x57537A539C1B847EULL, 0xA7C02C9FD0E768A7ULL, 0x0EB6FD59FC0E5EE1ULL, 
            0x7C5F4548E1AEE48DULL, 0xCA4053FF6E3C67A8ULL, 0xA4F886D43E6D3858ULL, 0x6D10DCEAF16ADE3EULL, 
            0xBC8BF5CD7A0D2AE9ULL, 0x0312E7284E6DEC34ULL, 0x1BDC1F999C2A3DD8ULL, 0xC38BE4D94D2D4D5BULL
        },
        {
            0xEE03932DB1C6D19FULL, 0x208709282BE7FC25ULL, 0x969DB85B2BB0CA34ULL, 0xE0768CB500CAB402ULL, 
            0x2F42F1EBA31678E8ULL, 0x4BEE50CC2C67C034ULL, 0x6F4B7C85E0D3DB67ULL, 0x1BF8F2BADB3629D5ULL, 
            0x42764093662A1793ULL, 0x6961E9692BE2DC49ULL, 0x04FB48D0D603E034ULL, 0x57D05BF5EAE35EA0ULL, 
            0x6F25B2E5BFC9A11DULL, 0x3D3122243CB69A31ULL, 0x91C029F9092D09D0ULL, 0xC3D0237AE032169EULL, 
            0xF6FC6A89129D3F54ULL, 0xD419A232C7E9A425ULL, 0x4AA62D6EA80C9558ULL, 0x3243E6D4BF410D0CULL, 
            0xF8EED3935203274FULL, 0x2C0D3802D2486090ULL, 0xC434798E1DFE9B71ULL, 0xA88412839C382416ULL, 
            0x474682D515DE0B2CULL, 0x9AE45A15B2A78AF1ULL, 0xB41957EAB37AA797ULL, 0x9270B0AE20AA744CULL, 
            0x706F6DAB6914C6E6ULL, 0xA91C8A2A4ABD6357ULL, 0x7139E6E65EB4DCF7ULL, 0x45BA4C27A2643DD4ULL
        },
        {
            0x21EAE1A7A64D2E21ULL, 0xF79F599E0D02AC05ULL, 0xA56F1D89EED76ADCULL, 0x44740CB4BD671C5DULL, 
            0x1D0869D5C47ED215ULL, 0x60372ABEB7EA55A7ULL, 0x90AE8E6F04508B89ULL, 0x86C43992DC6D6BF0ULL, 
            0x10B2AA997411DC52ULL, 0xF477822C719FD1EBULL, 0x29DE21D09C34AA68ULL, 0x7DCACEBE5D2B787DULL, 
            0xEEB3B97FF0EDA595ULL, 0xA0C01C5ACF03ABC8ULL, 0x32607EE916965568ULL, 0xC55122F75BEB2EEFULL, 
            0xADBF572055174DE0ULL, 0xA3D6E557A57172E1ULL, 0x361394E4D74B57FCULL, 0xA983AD82099ACC79ULL, 
            0xBCCB3386E0F5F9FFULL, 0x3CAD2BE38F88B1DAULL, 0xAFBED0E5E642D956ULL, 0x327465B7018AA360ULL, 
            0x1E825B6B61B2FB33ULL, 0xC30E1C2B57E23E59ULL, 0xEC5DDBDE5B4A7930ULL, 0xAA3D7B03D8CDF8CBULL, 
            0x40294B5C9082D0C5ULL, 0xC26BD0F18BA5D0DEULL, 0xBE73FD7EAFEE1E73ULL, 0xEA925B27102F1A89ULL
        }
    },
    {
        {
            0x12EBB19D387B1ED2ULL, 0xF4B621CF044F679EULL, 0x1F333813D16740B1ULL, 0x6FB5A3AD83895FFAULL, 
            0x39AF96B4F5F30A4EULL, 0x17B622C5EE5B3D0CULL, 0xD15BB659A8314804ULL, 0x38EE9E75D1F3B9F5ULL, 
            0x26613822B013678BULL, 0x81A49F2C317B750FULL, 0xEF2FF3678053E348ULL, 0x04EF11EE126E8BE7ULL, 
            0x1248D9F2BBA1E4A6ULL, 0x8221586D42078FF5ULL, 0x34EB030A86CE2F9DULL, 0x2D54DD22030B6207ULL, 
            0xB6A1306ECEFC96DBULL, 0xCAC72C8CCE19B2FAULL, 0xB7C7C090E586D4E9ULL, 0x8DD038F9D7578CE6ULL, 
            0x45312ABAD1471668ULL, 0x54A073839447F573ULL, 0x0B5C8F85528F0C2FULL, 0x81D3DEDF0429AAB9ULL, 
            0x51F98063FE02FA46ULL, 0x665106BA54692DB0ULL, 0xB0F4D35CBDB8C8FEULL, 0x813740E68B35A67CULL, 
            0x3D553BEE4AC7E02BULL, 0x2C31344AE657231DULL, 0xAD045BFDA1B86BE6ULL, 0x96B114CBBFD3C51FULL
        },
        {
            0x9228534B0972C39AULL, 0x9A0F9038129EEFF7ULL, 0x5650226079FC4F01ULL, 0xE999209AE9696FCCULL, 
            0xB116166CEB7B2BB1ULL, 0x611F57B6015255F4ULL, 0x726D895B250E887AULL, 0x10F057CAEBBB0CDDULL, 
            0xCAD8D0E9C652DF0FULL, 0xDEC2C4E03EB410A1ULL, 0x521C35A59E9E3B9DULL, 0x0B749F606C299174ULL, 
            0x7543C2ACB68B98EBULL, 0x37BC7D1A50E03547ULL, 0x404F68C341FD3A55ULL, 0x4C71153E9A056854ULL, 
            0xE1C00E2F6EF32613ULL, 0x477413969EC1C4E0ULL, 0x7A4F6FCC9EF015B4ULL, 0xDE9D51CC8E10C8F6ULL, 
            0x9ED77017B39C59DDULL, 0x7D009D87608CC7E4ULL, 0xA56073DC105C4421ULL, 0x7547E5B32A2114E2ULL, 
            0x4E81AD716EAFC7E1ULL, 0x15040D1644CBA527ULL, 0x2A3310F7F91C1873ULL, 0xC10187B3243F8B8FULL, 
            0x6804F61208D01CB3ULL, 0x998043631B361665ULL, 0x117AC680DF05126EULL, 0xF7593FAE137E3E8FULL
        },
        {
            0xC366765B13DC82CDULL, 0xF900F1C668732DE8ULL, 0xA8E6CB96FC467F94ULL, 0xA7C93D40A921E868ULL, 
            0xDB7E888DB10355E9ULL, 0x22759DC2AD1969E0ULL, 0x5C5B4E9BE5C93C79ULL, 0x26990E58D980B28AULL, 
            0x92EFCC35E55D8566ULL, 0xC85453D87B82D9F6ULL, 0xF8636924E1C8F486ULL, 0x7C241F703C10DA2EULL, 
            0xDDE1E58A79F68FC7ULL, 0x4195D9636F880123ULL, 0x8472B9670261A958ULL, 0xA3D29DDDB01E94F6ULL, 
            0xFDFEAB33797E39A4ULL, 0x30D14DDAC2BB93AEULL, 0x54CD089C26FDE086ULL, 0x3DA65F6910F084EBULL, 
            0x8CFF4095B141148EULL, 0xFE9479347BE711D3ULL, 0x422E74517C1A116AULL, 0xE371AB061CAFC7BBULL, 
            0xEB357FFEA8E54AFBULL, 0x21E7071E47697AB8ULL, 0x39989B05E2DAB8C2ULL, 0x623F352EE486E9EBULL, 
            0x3AF0A0FF4B1122F0ULL, 0x78A1F1575D4B829AULL, 0xC8F9ECA35EEB7D76ULL, 0xCC398D59D927623BULL
        },
        {
            0x4D467090A78B2A5DULL, 0xCD554F44CE619714ULL, 0xFF2094689C2366E7ULL, 0x89753FD4416F6B00ULL, 
            0x3F17C1F070446CD7ULL, 0x9F9E390BED1A7462ULL, 0xEE1857EAA772CEB1ULL, 0x808655B9D360F161ULL, 
            0xBF7FE7069B8AF3E5ULL, 0x4141FA517B11D581ULL, 0xC57C08A7577F8164ULL, 0x2E7285096A9FDB21ULL, 
            0x774C5918C409B407ULL, 0xE71784FA811C028AULL, 0xC5C9CCF8E6C11DA0ULL, 0x4D139A206B043B8EULL, 
            0x975E3587FFCD2D8DULL, 0xCD9545DB299D901DULL, 0xBA80989C379130A1ULL, 0x1409F3206316D270ULL, 
            0x8C7CD3801B892E3CULL, 0xDE789805FC57C0ECULL, 0x4AAE07630643E4C0ULL, 0xA23BEA8A29A851DCULL, 
            0xF6E7313B2077E879ULL, 0x28F9A2B52F8A27ADULL, 0x80AECDACE5849742ULL, 0x20AE2326069B1F42ULL, 
            0xAC0E2633DC3D8AB9ULL, 0x745532F37F66FD37ULL, 0xFDE4A91C45D8A8F0ULL, 0x2551FA4643D9B4F0ULL
        },
        {
            0x58121BBDC7808122ULL, 0xD54497FC4936F788ULL, 0x3E791E7514862ACEULL, 0xDC9F28EA09F656F7ULL, 
            0xFB530ED1A00B8958ULL, 0x1349869EA6B5C3A6ULL, 0xD25CD6B94FC7285AULL, 0x8D1A83C2D8C665ADULL, 
            0xD232A4E3E8385A8BULL, 0x33B859D309C8B485ULL, 0x90A4ACAD1284C59DULL, 0x731BBE0809895EDDULL, 
            0x75689F373841188DULL, 0x44D6306AEA9C4BFAULL, 0x04DA35F7BF33D2CCULL, 0xD888A0BC724B0E4AULL, 
            0x39F5368F3E3A8A81ULL, 0x76EF8D4D62C1BBE3ULL, 0xD63C3AA53D734F62ULL, 0x594940782986E5E8ULL, 
            0x45193DDE6C496678ULL, 0x1F411DA364E15347ULL, 0xC6EB389B9EBD32E4ULL, 0xCAD021B8D1137739ULL, 
            0x3A3FAEBAE0563EBEULL, 0x22176B2EF1E971FFULL, 0x3BFAF6C6C0687E02ULL, 0xEFCAD4A23AAD1068ULL, 
            0xF212F778A81CA058ULL, 0x5A77A2085B374F8AULL, 0x63DB1256BD522E36ULL, 0x82DC83447AD477EAULL
        },
        {
            0x8816E6F196A930CDULL, 0xFE99AA7C17A5ACC9ULL, 0xFB80F71E002C385CULL, 0x555EFE10F841B611ULL, 
            0x0A902BA15452CEDCULL, 0x0E6E0F1C66C18AE3ULL, 0x74BC0F8F9210A758ULL, 0x4FA02B889363CDB6ULL, 
            0x3672363682B53523ULL, 0xDF91217F848D8CD2ULL, 0x654263BA770AF7D0ULL, 0xA119C6AD39951A94ULL, 
            0xCED1CA12509E78EFULL, 0x42D42F080B7E28A4ULL, 0x5071EE5296460A50ULL, 0x8412B98BC0812D16ULL, 
            0x06CF45D55BF5C179ULL, 0xB0810EEBACBE8483ULL, 0xF9543C892A66EA8BULL, 0xB46372B03D05CE0DULL, 
            0xD3315A8F1CB30F72ULL, 0x57C836BFA6A92AB5ULL, 0x717C11ED91ECF6F1ULL, 0xA4B584413284AC39ULL, 
            0xE5EDCBBF037685CBULL, 0x65C53F89C42FCE18ULL, 0xCD70A6C4B369C29FULL, 0x925D88D3782ACEE4ULL, 
            0x93521FECD89F4611ULL, 0x9D82ABE730DAB73DULL, 0x1DF2C21CDEA86C89ULL, 0x90C83FA0E84A4027ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseDConstants = {
    0xD7D100712D5CB1CCULL,
    0xCCEE958B545BFBC9ULL,
    0x770E8FC32ACACFDBULL,
    0xD7D100712D5CB1CCULL,
    0xCCEE958B545BFBC9ULL,
    0x770E8FC32ACACFDBULL,
    0x87B0EFDE0F12FE27ULL,
    0xC75E16A0027CFA6BULL,
    0x66,
    0xE2,
    0x90,
    0x20,
    0x41,
    0x9F,
    0xB4,
    0x8C
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseESalts = {
    {
        {
            0x8D8B497B6F8767E2ULL, 0x1393092130256518ULL, 0xCBA6DA062E5AD989ULL, 0xB0A76E29122451FAULL, 
            0xE27AED5F997FF02CULL, 0xAABF9FEE3C02DD55ULL, 0x9B02DB66B8CB5933ULL, 0xB3710FDE370E5E7EULL, 
            0x633858F0E435C136ULL, 0xEA9FB6B6D47BB595ULL, 0x06650DF4B0531526ULL, 0x41BC7F058C8849A8ULL, 
            0xCC3D6CD20FF20464ULL, 0xD759D5C66240528BULL, 0x5D119B7D97E34BE4ULL, 0x4C4FB2F4BC368FB9ULL, 
            0xAF35F73FF84F0934ULL, 0xD557D37DE66BD196ULL, 0x12B36F80BFB449A3ULL, 0x0D074885245E5E4CULL, 
            0x794D76FF4C4E08ABULL, 0x776F7A9D82F2EA7BULL, 0x7ED194E02471CB45ULL, 0x6053855151486E08ULL, 
            0xBA694709559245E6ULL, 0x538EF2980E20C331ULL, 0x842A0DA82E592A27ULL, 0x69609C2D71EB52E8ULL, 
            0xA330936DB5F954F9ULL, 0xCB5E2D02C018C764ULL, 0x56402D8B12A43F09ULL, 0xA9EB74895AA1051AULL
        },
        {
            0x4896F6F38EF37602ULL, 0x66FDA15F6B388B69ULL, 0x2D78E7FE954C365BULL, 0xAF08F204F2B5D9EBULL, 
            0x81CE4459A3490514ULL, 0xFD172957DEABEA07ULL, 0xB1DB513F01C6A266ULL, 0xD4D2C42BFF4FF6CAULL, 
            0xAF4D8C7C4450049DULL, 0xBD0F57AB13DEEA98ULL, 0xAD4044F27052E3E4ULL, 0xD2D899995AD93A3CULL, 
            0x1E08307F0DB03824ULL, 0x57E12688D7B08406ULL, 0xD256BED3434D18F6ULL, 0x267A0E715D97FA1FULL, 
            0x9973BDF020920A7CULL, 0x033747D2E0B62080ULL, 0x5EF9B745BB180E0DULL, 0xE3CDDF829C11F2A5ULL, 
            0x07AFB4321E365C7CULL, 0x7F4E6585A306EB57ULL, 0x023E5563D8944A9FULL, 0x10B2AE0322ECBA17ULL, 
            0xCF10EB18A988B9EEULL, 0x9618E16063201D3DULL, 0x403B65F1D7734B8FULL, 0x5403716695A269ACULL, 
            0x5957CAC2429F1A59ULL, 0x1062BCCDFE0F47E3ULL, 0x2BFA9C9FB41312C7ULL, 0xE9A61551DCE624E1ULL
        },
        {
            0x2FCEAC9E24B9A7FCULL, 0x01EB8F315D9186C4ULL, 0x7762409D104AEAE6ULL, 0xAFCC6EE81B6EAFCBULL, 
            0xAF7FA0A379A27DC4ULL, 0xFCBF086C4D518AF3ULL, 0xC0D302790589424FULL, 0x3220615FB0803417ULL, 
            0xA19728F3DC89902AULL, 0x105ABBC762193749ULL, 0xF0E74E0D21776D59ULL, 0x7C397169E7B00E96ULL, 
            0xC542E12576B40337ULL, 0xB79474600B32A754ULL, 0x50F2881CE38D143CULL, 0x0D919E3DDC5FE5E6ULL, 
            0x7FB0BC05B272D0A2ULL, 0xADF70D3B6C8A65D1ULL, 0xCEC08E6AE9564035ULL, 0xC6B824F815067C58ULL, 
            0x025FB42B5AAA998BULL, 0xC3191CC001DE39FFULL, 0x32A977F387389D2DULL, 0x509D1B7A1A530644ULL, 
            0x2FE782F5FFBBB5EBULL, 0xA123631B2387F8AFULL, 0x269D63661E8B5E75ULL, 0x5D7C935033B11580ULL, 
            0xA9F5E0B1FE63802EULL, 0x6492E2069D880CD5ULL, 0x08E12B0E4E770FE8ULL, 0x3F70FBEDE849119AULL
        },
        {
            0x56260DF0F152ABD3ULL, 0x8092E039E9AFD239ULL, 0x913CDDCD48000E87ULL, 0x2D3021AE6B4988FAULL, 
            0x093FA8E23F38BC7FULL, 0xE296F855A8D2E713ULL, 0x22BB35B6B66DCD9CULL, 0xD5890DE4C8B7AA0AULL, 
            0x24C3923623A5FE4AULL, 0x5EAE91D55A111B15ULL, 0xA2609EDA368396DCULL, 0x2B3207582BFE7DD0ULL, 
            0x30C12FA3441C97E4ULL, 0xAAD7D90D15DFC436ULL, 0x8F46CF0B893F61C1ULL, 0x64C3770D2AAFEDA3ULL, 
            0x4F9228C113915FDAULL, 0x6929C5A70FC8FAD2ULL, 0xD9B6DE685234BB54ULL, 0x8362567688B12A09ULL, 
            0x5C99CBDF24ED0FA7ULL, 0x7A29611495442719ULL, 0xA76C1D57C577F5D7ULL, 0x8653B9F0EAAC1275ULL, 
            0x6CE3962FA39C70B4ULL, 0xF08F12D044B6896AULL, 0x87943A5DA94E327FULL, 0x10BE92DFDC86E3E2ULL, 
            0x71BF1379DA7A18A8ULL, 0xD8A6037D20C70A34ULL, 0x34A432519A3BEDD2ULL, 0x096F95EEFF2DE855ULL
        },
        {
            0x423E686AFAFE2578ULL, 0xC2D32F618F839655ULL, 0x7B2C2CDBA0454E63ULL, 0xA6906BD61DAB9E5CULL, 
            0xFB796C4C25D7CFF3ULL, 0x3CCE29C95E30D65CULL, 0xAC0013A17AF6232FULL, 0x00F023AE97741931ULL, 
            0xFFA0D5287D1628B7ULL, 0xDB07B62E313C08EEULL, 0x552BAE62E3A3B0FAULL, 0x4877D58711CEE3A5ULL, 
            0xC811A480C629D292ULL, 0x424ABD9ED03EEAF1ULL, 0xE71B4CE77CB28217ULL, 0xEDE338F052865833ULL, 
            0x4E84771853154DE0ULL, 0x1C60594C0F378402ULL, 0xEA7052BFCC93BF25ULL, 0x7891E1B9C58D353EULL, 
            0x8537BEDDED630325ULL, 0x8FE8BA8A976BEDE0ULL, 0x42A319B2F85C1D18ULL, 0x2E85B72A16C41359ULL, 
            0x7443A28C273AC84EULL, 0x73456864A475327EULL, 0x13928DDDCDD74090ULL, 0x623F9F884ADE40B5ULL, 
            0xA72FAB99B9FF6682ULL, 0xBD67AB87412A3F46ULL, 0xF0F098147868A2D7ULL, 0x1A65DFF324DB5009ULL
        },
        {
            0xC1255C229D9D57CEULL, 0xAF72CE6665999F73ULL, 0xD149ACF3DBF7E91AULL, 0x87C76B62669B33D8ULL, 
            0x6E89BE9D422820CAULL, 0xF64ACFD8E90F96B3ULL, 0x22E609D618E146BDULL, 0x87F6307C83006D29ULL, 
            0xD9D2F8F0A32E9F9CULL, 0x741677FE3FFD65E1ULL, 0x87D6F75C62C2894AULL, 0xB4A81798BF4F56A2ULL, 
            0xD3DC957780B610A5ULL, 0x51266EF25268E13DULL, 0x9F7C1753436BE18AULL, 0x1751C4B93E183A03ULL, 
            0x5BD420ED611E488EULL, 0xC8B53DF3B285529CULL, 0xBBBE8C9AF7842A48ULL, 0xECAFFF512E8B2288ULL, 
            0xA97C06DF72A24130ULL, 0x2AEB4276B93D8F4FULL, 0xA9101A27627A6781ULL, 0x707021E7F7850888ULL, 
            0x7AE1CEB3E77883E1ULL, 0xA2517608D040206AULL, 0x9564D53C056EA8F8ULL, 0x427D2226637E9E06ULL, 
            0x096707E4A4537C91ULL, 0x2539EB36F360ADB5ULL, 0xD16FB395355FD425ULL, 0x4E93DE1DB065D0F9ULL
        }
    },
    {
        {
            0x65FE35E590C6D760ULL, 0xB8CD7F5C81FE78A8ULL, 0x3D1FE11AB74E3519ULL, 0xEABB2B76F8B1F77EULL, 
            0x3440665C9804C3E9ULL, 0xBB24A7AC7686B3F4ULL, 0xA767B4C6818A804AULL, 0xA538C83D09DDCF18ULL, 
            0x4E004EB7F6ECE201ULL, 0x21AC2B1E4BDDFEC5ULL, 0x6057B09387808B2CULL, 0xCD893E9D30E7DD59ULL, 
            0xCB6D942B341CFE32ULL, 0xFA2851DB6FA8030AULL, 0x7296D5EE49469599ULL, 0x61835EB776E0680FULL, 
            0xDC4B007DCBD0D1ECULL, 0xF5269B838A1ED429ULL, 0x2AC8FB840FC14D80ULL, 0x96768FE4ED0DADD0ULL, 
            0xB37A7201EC8454C0ULL, 0x3DD9D86F3087AAE8ULL, 0x98DBE0328673A7E8ULL, 0x8D4302D5F9B08A54ULL, 
            0x267A6029FC454A49ULL, 0x7B4F6B0A9908ADF4ULL, 0xDA5424E741624670ULL, 0x433153D448B603A5ULL, 
            0x426387EA4771EAF5ULL, 0x95DB9F81AAAFFE54ULL, 0xB1FC18DB3CF894C9ULL, 0x913D73139F535CBEULL
        },
        {
            0xADEA5CF327641E33ULL, 0x8F20011F2E0E42E5ULL, 0xB17E8F470FD56A96ULL, 0x0177A894198FB6ACULL, 
            0xB72593EF6B7F0090ULL, 0x44BCC7A59185D335ULL, 0x179EC121F690528EULL, 0x0E096DAA07742A56ULL, 
            0x97DF4BDBB044ED93ULL, 0x9ABC2B1B797E00FDULL, 0xD16952509495749BULL, 0x8D5A4D4DBB2A8C4CULL, 
            0xB23F9ADF14A4364DULL, 0xF084BEAB1A238590ULL, 0x01D7FAE84B4201B0ULL, 0x139FD14F66ED0989ULL, 
            0xA50A515C85E55999ULL, 0xF7B8494317565D7DULL, 0xC9A7B029DD41F8E0ULL, 0x4D39EF65666E5A5AULL, 
            0x9EC6E80C1D227ADFULL, 0x04A7BE0CBF993243ULL, 0x401A81CE414A2586ULL, 0x3973424171DA5CB1ULL, 
            0x1739A31D051CD497ULL, 0x2B66840A13CE81C7ULL, 0x625556BD4F8A1DE4ULL, 0x3DE34268D5B42D52ULL, 
            0xCE7616842DC95C10ULL, 0x72435239E0858FAEULL, 0xDCEBBB3AD473CCB6ULL, 0x239FE316212DF1F8ULL
        },
        {
            0xE01F95BE3BD6389DULL, 0x0046356D7726B08DULL, 0xE4E5119AD28A46F8ULL, 0x23DC4C75141C6435ULL, 
            0x6E7EC5EBC5E829F8ULL, 0xCF319CBABAE8F121ULL, 0x67F9FD230F6FA783ULL, 0xA48092813BECD04CULL, 
            0xC2A293334BCEA33CULL, 0x173267A3B93609A7ULL, 0xBB5FDB2012AE39C8ULL, 0xCCC777A959BF21BBULL, 
            0x1C39364405BA2A1DULL, 0x0CCDA6AF686EA863ULL, 0x6380A79A76B5C37CULL, 0x9F65B24FB698A321ULL, 
            0x4CD05ACBF2DEB905ULL, 0x5D59A7B5CDD50823ULL, 0x2F501AAEBFD1FD84ULL, 0x210BCC1952A46EE3ULL, 
            0xC917308DAEEF85B1ULL, 0x0624747889AE21C0ULL, 0x3094C402F744EABAULL, 0x0873914FFFB7C20EULL, 
            0xD138DEED0CEC1304ULL, 0x2DCF6AC81AFFD3DCULL, 0x0B2491E0C84DEA0DULL, 0xF28358F6B3C55224ULL, 
            0x6882F98B6FE22A92ULL, 0x38260AA7AE82D74AULL, 0xFAF9F8563AD88B30ULL, 0xB8BB5C5CC8A87588ULL
        },
        {
            0x5A124CE7222A8A77ULL, 0xFF9C96D2897B791BULL, 0xEFA863E08EF1D74CULL, 0x09A6B827452EEC40ULL, 
            0x48A047C309065682ULL, 0x62046327AF96A066ULL, 0x01BE7C89030C8BECULL, 0x685979CCF96BA8DCULL, 
            0xE68461B08015E833ULL, 0x8E8F01E39022077EULL, 0xD8909D99DB22C41DULL, 0x3F6A62A85AE597CAULL, 
            0xF1603BB1476131C4ULL, 0xA609AF856FDF1774ULL, 0xBD11BB674A4F20DCULL, 0xFE00B2A40F1ED5F4ULL, 
            0xD826A053EBA5C100ULL, 0x091F2A1EB39F382BULL, 0x621CC093079BD94CULL, 0x62F4E2ED14F2F53FULL, 
            0xE63B2A1B5A349FFFULL, 0x20BB9AC77E720852ULL, 0x434407BF4ABA1536ULL, 0xA77BF537D77D95DFULL, 
            0xC0B2DC3B5220C631ULL, 0xBD343EBE0D3E6D87ULL, 0xAA96E0AB197AD21AULL, 0xB39A79BD908D2A22ULL, 
            0x27A25B49652C54A5ULL, 0x889B5C785BC48EF1ULL, 0xF0DA951C7FFBCF4AULL, 0x382AE41FBE13D27AULL
        },
        {
            0xE7B8647CC73A9EB0ULL, 0x4F994EE96D0FF06DULL, 0x63A42EE7B8050D0EULL, 0x004B3810B2B10E24ULL, 
            0x47129C29E86C9A4BULL, 0x898EF78AC7E0B5B4ULL, 0xCBC0E54CD71AF59EULL, 0x4DFEB77E54D71366ULL, 
            0x1B53ADF186EA177FULL, 0x0F7D2C408EBA20ABULL, 0x4BAABAA50FF0C8EEULL, 0xD7FAB86902FD7A01ULL, 
            0xE7B0D19790FC718EULL, 0x6359A83669A1275AULL, 0x9529D6BD42C77DDFULL, 0x6E55158F7CC90C54ULL, 
            0x88FCD2E27993675EULL, 0xD86B95D5F4707900ULL, 0x231FB15E7FC2E195ULL, 0x78D40FAA55A4B451ULL, 
            0x03E4BD2C68B8EBA7ULL, 0x7DF39510AD77B131ULL, 0x4064D3E7FE00560EULL, 0x4F12A15ACA5FF0E2ULL, 
            0x1E90BF2E79E9DBF8ULL, 0x26AB3879D258B7FDULL, 0x1638C962A4D91CD7ULL, 0x0D7398CD76CF0E37ULL, 
            0x49282E6381067E83ULL, 0x9314000A2BC998D4ULL, 0x3E40A797588CD7ACULL, 0x1E6AEF71112FEFA1ULL
        },
        {
            0x6F3A33037BDE2353ULL, 0xC50ABA748738AB78ULL, 0x7CAAEFD272704C16ULL, 0x84E1F469B1051F96ULL, 
            0x1E269AAD33C1A036ULL, 0x6A599286B450351EULL, 0x6AC38DC8C15B1DCEULL, 0x0E1E6A61D5893663ULL, 
            0x6A65DFAC545DF6C1ULL, 0xE190249195075D0CULL, 0xFB2D7C8CD470AF13ULL, 0x7AB854105ABACAC8ULL, 
            0x4D36EBF6E9BDA584ULL, 0xDA9BB8DDEF814505ULL, 0xB15732273D5F2A95ULL, 0x90623EC3EDC1C1B7ULL, 
            0x0A9D76F52380235AULL, 0xCF9C76CE10D5CA53ULL, 0x9B2DFCDEA89D6BAEULL, 0xFCAAAE98D69B8822ULL, 
            0xEA4CE82ED17E3ADEULL, 0xFAD7C04CC1BB38E7ULL, 0x80023947F8C88CDDULL, 0xADC1F7078EC2A83FULL, 
            0xA102492EAF4BA4ECULL, 0x1F1ACEEDAF52EC4AULL, 0xB5A2D9D32F02AAEAULL, 0xA6D1E3E413AD4612ULL, 
            0xC28FAA5F1EB00BF8ULL, 0xDEB1485928A4A7FEULL, 0x8641988B6EB13C28ULL, 0xEC791D60E429C9DCULL
        }
    },
    {
        {
            0x7C322BF9B3B52A93ULL, 0xAD4B27F918827364ULL, 0x5BF4AE7E350CEC0CULL, 0xD11992556FA906A8ULL, 
            0xBDF686420A36EB7FULL, 0xF5FDFDFB96E4E0C0ULL, 0x1DD5CD61718162EAULL, 0x3DB28A0E7E5B993DULL, 
            0x37C3527712840B19ULL, 0xE119D6AE30E62CC2ULL, 0xD1E8373CFAD943B7ULL, 0x283A0F49B6C7892EULL, 
            0x2C1FF521208C1DD5ULL, 0x026E4ADB53D5D5ABULL, 0x256AC377D3B45C8BULL, 0x4622E0D25C666F6CULL, 
            0x6215243BB23B9E50ULL, 0xCF028F18968B9452ULL, 0xB1537F570F8595DBULL, 0x8E3EB934FB03A724ULL, 
            0xE56B3A0E1CD9F18CULL, 0x55714388DC6DB15FULL, 0x704CAFE54A3AB9DEULL, 0x1EE24C075EF1C927ULL, 
            0xD593E5F465574448ULL, 0x2351C5E239FB5A5EULL, 0x2B80A84D06490C2CULL, 0x2427325EE6D23883ULL, 
            0xAB76348B0C8BF34CULL, 0x16E5F52DCE3FCE98ULL, 0xC5127F82DAD0FF6DULL, 0x69AF231E35A96F9BULL
        },
        {
            0x2496CC3FCD906D57ULL, 0xD2CB55CE58F44AACULL, 0xD319C7979C7344B1ULL, 0x625A96B6DFCA7135ULL, 
            0xAD67568D1D55FCB9ULL, 0xB9AFE95CD9422000ULL, 0xFD755AF324C8F9B2ULL, 0x87C6C47F00FA5D62ULL, 
            0xC318212AB650E0C9ULL, 0xBCE0B3BAF919A3BBULL, 0xEF8E9489C5F21484ULL, 0x0246E5BDB77F0D80ULL, 
            0x32B498010F96EC61ULL, 0xB3B4D9CBD135EC3EULL, 0xABC8948A7ED659CBULL, 0xB02C5B829C6E7A76ULL, 
            0xB8BF2CF4C1F8B5CBULL, 0x74CBC1D1F25DBE88ULL, 0x11826AB383E0E07BULL, 0xB65DB3FBF3055E56ULL, 
            0xECA776FB132A5EE1ULL, 0x29D7D354C846E8FFULL, 0x83709F998A7A29F6ULL, 0xBC6E02A5EE79126DULL, 
            0x85FA80A47255EE79ULL, 0xC3E5500B246DB1F8ULL, 0x211A8E5A41BCF60AULL, 0xB1EF498DE1FC8D78ULL, 
            0x3495E53A9E54334DULL, 0x6FBF4A31EDD7B78BULL, 0xED15818FCB280F83ULL, 0x7A14A095BA2D9275ULL
        },
        {
            0x073AF153F2E43DC3ULL, 0x572DBBF663E707ADULL, 0x9BE066B96AE38300ULL, 0xFAA28D476F8A9A35ULL, 
            0x170C39A55C796C36ULL, 0x8021B52FE23B4F37ULL, 0xA27F15AD9A5DEC98ULL, 0x24C261EA59C36284ULL, 
            0x0F04A214A8A7492DULL, 0x50E742F990EF8431ULL, 0x7E1E0E1B0E1D6676ULL, 0xD12914E98E5E70D3ULL, 
            0xC4741FEA85503618ULL, 0x973152F1D6752ADEULL, 0x2C1D49E54CCD4F92ULL, 0x237B0C1BC9F0E9DCULL, 
            0xB6E6BA595EE63ACDULL, 0x202A3705E3C59861ULL, 0x2B018FE8DA007D8BULL, 0xA285197814F90659ULL, 
            0xD7D8C5CC4AFC53FDULL, 0x35ACF1DAE75F0138ULL, 0x6B1520E7AB4AF34EULL, 0x08BC8BB6A833E0DCULL, 
            0x70B2CDD84F40C236ULL, 0x3DC809BA533F7D99ULL, 0xA5D11752242A9DF8ULL, 0x611C51592631D14FULL, 
            0x6B6A0581485A3093ULL, 0xB9D413E709A176D7ULL, 0x15D1245733B76D3EULL, 0x0B4EE206AFE94CE1ULL
        },
        {
            0x0930447BB5632E21ULL, 0xF0556FE093C020C4ULL, 0x9C886F786125998AULL, 0x6C3918B9D91D183FULL, 
            0x20026AB4613DB3D7ULL, 0xCCA10D0960AAA6E9ULL, 0x7B49704F934C6C78ULL, 0xEFCDF095A2F793E2ULL, 
            0xC9D1FF35E4E43CCCULL, 0x1EC94BF0B9179970ULL, 0xD18B5CFC3D3A0CC4ULL, 0x01B7E7C1285B1000ULL, 
            0xA522A37D63AF0F9BULL, 0xE3FCB83A362DEEE3ULL, 0xE1D6D4212BD5C72FULL, 0xE5643E05C9F57B57ULL, 
            0xAED80068ADCB1619ULL, 0x0F04474B37585EA6ULL, 0xEB5CF45D434C86DAULL, 0x237B3999F193A9FBULL, 
            0xC7672CA7BB37B38AULL, 0x18283512044C25BBULL, 0xAD7538B5DB495569ULL, 0xBCFCA3D4B23DA0D4ULL, 
            0xE60E8A8061D05889ULL, 0x98AED00F2F3017D4ULL, 0xDC51884F3C545394ULL, 0x146A429F829279DEULL, 
            0x0A2AE9BFB5D289ADULL, 0xFDD300DB688BEC9AULL, 0xA64EAC7ADCF81B9DULL, 0xC29AB9256F965FBDULL
        },
        {
            0x938DA386B876DEBCULL, 0x0DF973E2DEBD62C5ULL, 0xAFAE2A840EEC75F0ULL, 0xAE2D77112AA13478ULL, 
            0xA814B7C6B3228C4CULL, 0x8A02AD3FDC941923ULL, 0x8F0B1A3A1805565BULL, 0xF6C356E123BDC9CDULL, 
            0x7FB6EBA470719D67ULL, 0xEC3FBF48E6054D4AULL, 0x19925AECBEDE33F0ULL, 0x35F42F9743F4B76AULL, 
            0x05C9423D54B0A411ULL, 0xC750A90B3217A2AAULL, 0x109B20EF254C180DULL, 0x4B0023AA1E97086EULL, 
            0x9F481E16DA8F294EULL, 0x225F64A3058A7C7AULL, 0xC1B190F819468445ULL, 0x2D3C800CAD389ED1ULL, 
            0xC00E8CA4373D3575ULL, 0xC041D9A68CCD3C28ULL, 0x1A22ED7564F1383AULL, 0x6559723666BFB527ULL, 
            0xA37241CD1C20DE82ULL, 0x4C34E9DA956CF9CAULL, 0x6198E5529F779A00ULL, 0xFDC0F5BFA8C0F31DULL, 
            0x188D077ECA25180CULL, 0x1890D60A0A894F6CULL, 0x0DD71477378A5C2FULL, 0x3D38AB43BFBA3B33ULL
        },
        {
            0x5B9E457398828EDAULL, 0x6F63ED6F621D94AFULL, 0x595BB0E12314EC87ULL, 0x6B546D18FBE4D6E8ULL, 
            0xA945409CCCDB5BFFULL, 0x500FE37A09522DC8ULL, 0x6A0BE29BCAE2E97AULL, 0xB2E06718EA9DBC66ULL, 
            0xF64D76AE61C70E5DULL, 0xB676A5BC05E441B9ULL, 0x5E1E8AEEAF905548ULL, 0xDC016017F2F11B48ULL, 
            0xD593A4BF69D472F1ULL, 0x51E2A969F2D083AEULL, 0xA64EB46A516C8D98ULL, 0xADBB1A5A8A8EBA71ULL, 
            0xAC9E0A1242D4FD66ULL, 0x71F6E1944BC20BB7ULL, 0xC8C1F50728D0AC93ULL, 0x1724A23BBA1F11D2ULL, 
            0x88C9B5BC4601C57FULL, 0x539B8EBEFDBEDBF6ULL, 0x6314B370E66B7121ULL, 0xA6F05991EA2D8844ULL, 
            0xED9826F92EAF1177ULL, 0x6B30DAD6A0884B8AULL, 0xF6484A5EB4A0466AULL, 0xBE2539360FD8BC61ULL, 
            0x84FBDE9541F3715CULL, 0x8F125390F1EE0E28ULL, 0x78DB0A81CC6F4F34ULL, 0x4BFA0350DFCC6D0DULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseEConstants = {
    0x4868F6C6482A5A28ULL,
    0xF7BA44A5AAED02D0ULL,
    0x66FCECC6E98B6BF8ULL,
    0x4868F6C6482A5A28ULL,
    0xF7BA44A5AAED02D0ULL,
    0x66FCECC6E98B6BF8ULL,
    0xA32B0DB67B0280E6ULL,
    0xCFDB7562E81E8464ULL,
    0x2F,
    0xF0,
    0x33,
    0x03,
    0xBB,
    0xFB,
    0x85,
    0xB8
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseFSalts = {
    {
        {
            0xB99D7F3B59DC98A4ULL, 0xD84F5CA1E46B9901ULL, 0x4AC5382516191A5CULL, 0xA1B13C377BB11489ULL, 
            0xFC6DFB859543D24FULL, 0xD31908E8B5DE20B7ULL, 0x42AB42FADF7B5BD8ULL, 0xD0539F0D4812D9F1ULL, 
            0xFE062CFA059DD462ULL, 0x8627A1AB170E1D6EULL, 0x33AE53BF35096158ULL, 0xA66322BA351E0B53ULL, 
            0x2239173888DAB948ULL, 0x57AFEC1A090F0E35ULL, 0x457462F748FA92FEULL, 0xF1BA14E469D92EB5ULL, 
            0xAFE869F78C12DDA1ULL, 0xF3D0180AC064CD48ULL, 0x30EA2FE2EB7EC1A1ULL, 0xEC081543D843FE37ULL, 
            0x3E1E9E8697868933ULL, 0x5C3E9596BCD6CC35ULL, 0x2722ED6A2BB11962ULL, 0x1EB25BCD97A4AF4DULL, 
            0x3AF4A8931C6DE157ULL, 0x5765B42779AB6BFCULL, 0x86BD220948118AD0ULL, 0x18066E32EE86A35FULL, 
            0x2F04A98E32BA27F5ULL, 0x9FF9E8CB972850A1ULL, 0x1D536BC860C74C11ULL, 0x1BAEDD8E71D0FD1FULL
        },
        {
            0x44B5CDBBAD62C015ULL, 0xE9E19B144CDDFF3BULL, 0x9D413C1B8AB0A0BBULL, 0x6EB2C909CCB4F2F8ULL, 
            0xBB4E4059ABD058C7ULL, 0x83B9C47411691D63ULL, 0xED8DC1866D4E338AULL, 0x26D4EC05891CF84AULL, 
            0xB688B0EF72436A4DULL, 0x628C62F650111257ULL, 0x07FB84C993C314DCULL, 0xC05322AAF8F76A5EULL, 
            0xD1178826FB8C8B4BULL, 0xB84D76D0593AC457ULL, 0xE2B61C08A1635001ULL, 0x4684B5C251FDD5A4ULL, 
            0x965BB8FC06A4FC52ULL, 0xDCF9E4093DF797F8ULL, 0x01ADA758C1581A23ULL, 0xD6B924BFEED487AAULL, 
            0x98A72E22F7B516C7ULL, 0xD6795921DEBF6CE2ULL, 0x72924BA14EC533E9ULL, 0x018FC880077FB761ULL, 
            0xD9ABA90645939D1FULL, 0x6D0185B087F34818ULL, 0x8EFFC48B84A2FEBAULL, 0x0AC31BAF4A7DF7A6ULL, 
            0x4C6B5D1666DAD3B2ULL, 0xB8502599FA1A89C2ULL, 0xA754ED17ABE783DDULL, 0x1945D796DABF869BULL
        },
        {
            0x8392FFAF61B87727ULL, 0x406D9FB54F94E1F4ULL, 0x15E3481C561C8ADDULL, 0x7DBA82F971266F3DULL, 
            0xFD32A5BD93E303CFULL, 0xA92CFC249DA1C69EULL, 0xBF147DBE39C22DCEULL, 0x21D8AC8346EC1C9CULL, 
            0x04C9E3A45BA09472ULL, 0x1EF0BAB8ACE64EBDULL, 0xB9134E21BE63A5D9ULL, 0xBA6FEDB8088A92A5ULL, 
            0x6269ADE67DE15B1AULL, 0xE9650598C24A5652ULL, 0xAEDC8E7D2888A52AULL, 0x773ECC0FC4D4F7E7ULL, 
            0x5CA2AC500C7EAD46ULL, 0x1B5462FA0BEB15D1ULL, 0x87F7FCF3401F5FADULL, 0x163A10592AF9B0D4ULL, 
            0xBAC8D520D36F5F11ULL, 0xB1FA5BF74D6B35B3ULL, 0xA413B10779440FF9ULL, 0x2DFE236D7B79238CULL, 
            0xD2FA38FF0CEE169FULL, 0x4011DC3E5E263236ULL, 0x8F7DA936F2F88FEEULL, 0xF07F14F0EB1CEFD8ULL, 
            0x3BD9FC5B240297A3ULL, 0x2519310F20E72378ULL, 0x9B62B580C49C766EULL, 0x0A9E31A0B3B66036ULL
        },
        {
            0x86A9FCC640857AABULL, 0x58F9E3D51DEECCD6ULL, 0x7A072886D6173F62ULL, 0xEF17E37D56582D99ULL, 
            0x14B103100AA47B45ULL, 0xF73B54EBF29E5852ULL, 0x0C10E4515D08237CULL, 0xE4C64712D6FFF8D7ULL, 
            0x4554AE4D1ECC8BA5ULL, 0xDECDFA5FB83315C5ULL, 0xB832A96D002F6C04ULL, 0x1FF4017F28D18FDFULL, 
            0x8D5D6F66FAF7D798ULL, 0x71184B7F9ADB7E6AULL, 0x352FEFAD63182972ULL, 0xE11F3E4CC96E3C2CULL, 
            0xC5AEC6282FF5CF82ULL, 0x5EE56203D9ADF9F0ULL, 0x6F1033402A9C7048ULL, 0xD03AA52F734CB668ULL, 
            0x0704622FD51C9259ULL, 0xA2DFE891866474EAULL, 0x779896E948D8FF3DULL, 0xC4F611FB10205561ULL, 
            0xAAAE854E6C06DB11ULL, 0x34FE8E592BB4E8C3ULL, 0x0678DE8AA40476D0ULL, 0x74F08E5C8C7363C8ULL, 
            0x05F4103C6A24FD00ULL, 0xE05533E6E20822A7ULL, 0x5E7D8C5CF3F362D2ULL, 0x415843169B996AB5ULL
        },
        {
            0x9FC0CE62ECBC75BBULL, 0xD051237899F38B0CULL, 0x57393859BE8C39C4ULL, 0xB2A89879AF0AE8E9ULL, 
            0x7963676837D59FF0ULL, 0x23A59A56FB5BD445ULL, 0x095E153E04B1926EULL, 0x22DDD2B01C9368F8ULL, 
            0xFF41954332CD75EDULL, 0xD4F0E96BED6415DEULL, 0x83B3FD757BF02306ULL, 0x556EC75C59DFB19FULL, 
            0xB57111C7EF52489CULL, 0x546EAAE0B3AFA6C6ULL, 0x3541F7DD1FF75994ULL, 0x7667E38C9DEDC697ULL, 
            0xB0A0B210DDDEC9E0ULL, 0x9F8380B083147DC4ULL, 0xA8E4DC3FA9DC4363ULL, 0xA1CCF3D44270F143ULL, 
            0x567196000F6E331BULL, 0xFC45D167FBD41A3DULL, 0x4FDFAA8145F347A1ULL, 0xB4CC82023A163D5DULL, 
            0x96FBAFDAB6B07774ULL, 0xD67CB01F6F7E575AULL, 0x3769EF57957DDF7FULL, 0x1F9D7F833F595709ULL, 
            0x32CD7EC8435430BBULL, 0xD379F96DBAFD1D87ULL, 0x84ADD6E865EAF522ULL, 0x110B9FA4850B1032ULL
        },
        {
            0x8036012C22E4D92DULL, 0xC08DE64E4009FFFCULL, 0x68618AE48D01384DULL, 0x94FB62B5062341A5ULL, 
            0x76C1B9B5A3FF1D81ULL, 0x6723DEF72EBAC414ULL, 0x16F585E4A3B98B4AULL, 0x480129F759F9F4ECULL, 
            0x83A38ED4C353621BULL, 0xFE93120451DDFD33ULL, 0xE7757A5234BCAD9DULL, 0x2142484989837644ULL, 
            0x86BF43FFC49F02B3ULL, 0x74FBC08A1ECA318FULL, 0x7CC008F37162437EULL, 0x3164E009298D489FULL, 
            0x08EF5C37D3E2D4D4ULL, 0x4742611149A2E610ULL, 0x6BFD73325D2F8DF3ULL, 0xECDF94422DDE2E92ULL, 
            0x244F6BA2196070EAULL, 0xB746F3D95D21CE90ULL, 0x93679AC0E69BE39CULL, 0xEE0826C35D680ED5ULL, 
            0x8D86E36D7A234FFBULL, 0xF1DEBD435BA808F9ULL, 0xF30056EEE521E9B8ULL, 0x5F286B2ED1814410ULL, 
            0xA2BD6BA7DE9AA429ULL, 0x8829A41168627480ULL, 0x9A8696539A722BCCULL, 0x9BF2CC92065D29ABULL
        }
    },
    {
        {
            0x2A304797348A5753ULL, 0x19159A6959C960FEULL, 0xC70CEA95241C899CULL, 0x68130BAEF053BF4BULL, 
            0x7E6735D9F9C6A048ULL, 0x2263CA64C2DC5FD2ULL, 0xE2EC84FCF7958F0CULL, 0xB326CBC872F87C7EULL, 
            0xA410FA9A66D376F8ULL, 0x9E4E4E6564546268ULL, 0xC171134CD13C10E7ULL, 0x0B01DCFB33A0588CULL, 
            0x59E31DFE060F88F4ULL, 0x84D56D9734048DECULL, 0x906AAB5A4A07F373ULL, 0x1F3C5A9E5F6AB542ULL, 
            0x90554BA433C8E1CEULL, 0x803CF2FA1B974EECULL, 0x6592C88E414A8DAAULL, 0xC29C8F8641345BF1ULL, 
            0xAC77FE730C8CDCC2ULL, 0xA027971601C1699DULL, 0x3B7366E11218D894ULL, 0x461BF1384F6D4F52ULL, 
            0x8C963A941E712C6CULL, 0x2AA37B8F0D577447ULL, 0x18CE12DAE16BEF24ULL, 0x2C419206A00A976FULL, 
            0x381801E8BDF2CD2BULL, 0xEB17313B6E4B4450ULL, 0xFD0647135B309BA6ULL, 0x17FB8A1DEA219B42ULL
        },
        {
            0x136ED7BAA1185439ULL, 0x55F940CB1C262C06ULL, 0x5AB6B21811F637D6ULL, 0x99902565085F8021ULL, 
            0xA440B54ABAE4E212ULL, 0x65997A6E4C92C30AULL, 0xCE8FFBAD24FA431EULL, 0x51FB77724CEA07EDULL, 
            0xC01690EF78F0C330ULL, 0x2AD221BB03B12DD1ULL, 0xA240C749FE4F7E92ULL, 0xE2D4F5E06835CCA4ULL, 
            0xF2CDD1B0FE01307FULL, 0xCD4BE582EF724CF0ULL, 0xEB9F3C0627C89B2EULL, 0xEF46CEBC2C6BB8D2ULL, 
            0x3A6DFBE32926DB6FULL, 0xD8C1B88A020C91B2ULL, 0x3E23395F33F73F08ULL, 0x72B763CAAC5DD739ULL, 
            0x513E8AE945E57856ULL, 0x3FA3E7623F6CD39DULL, 0x70A73314FB53F08FULL, 0x0743753302B35D27ULL, 
            0x92F520CE95F3DC4AULL, 0xB31A3032B13F94CFULL, 0xCF8C0CD31643FB3AULL, 0x79470AE3730A9AB6ULL, 
            0x31B7D57C2A5ECB3DULL, 0x7376A3AB6C35AF2EULL, 0x75ED6BE489BCE144ULL, 0x89DF40CEF30D31BAULL
        },
        {
            0xFB600D838D45FAFBULL, 0xDC61EA7F092C754AULL, 0xD47ADD313C5B9F78ULL, 0x59B8D7BFC8F63929ULL, 
            0x0A8016C7955C8F2BULL, 0x283EFB06C8F365BFULL, 0xC99EA8AAFE06507FULL, 0x2B797B01A50371D4ULL, 
            0x59810E68DC968BD6ULL, 0x48B7C1C93DBDAD98ULL, 0x2150F2C21737E6BAULL, 0x795B474818F9AB1EULL, 
            0xF9D716DCB1B65275ULL, 0x62821D337E987758ULL, 0xF4007D5FFD9AD393ULL, 0xC22F873C297321F7ULL, 
            0x53CB89D77F929FB5ULL, 0xEF72D7A3DBF7ED24ULL, 0x4143F9ECFDEE3E9DULL, 0xFA521307D6EF6F61ULL, 
            0x97A614559EF9473EULL, 0x89744436E7E9622AULL, 0xB5D54703E3E6097FULL, 0xD81F36B47273C863ULL, 
            0x3DDE8B3F748DD274ULL, 0x162FF35D3326A5E5ULL, 0x84F0BD4C2B1526DBULL, 0xEAE80EA1E108EDAEULL, 
            0xCCF66D4CDD28DCDEULL, 0xA96ACF0E7A042931ULL, 0x766F5E5CD9C2904AULL, 0x311BE712DFA5B055ULL
        },
        {
            0x02E9B7793048773FULL, 0x2EF2906DE2261502ULL, 0xF538B217F2BEC76AULL, 0x9394F973BD3B250CULL, 
            0xAB24FEFC34060D57ULL, 0x7DE7C48791840173ULL, 0x9842A6C4110654B1ULL, 0xB67FA8FD20E9D853ULL, 
            0x8DB405214E74A8FDULL, 0x4AF4B5C3989A97ABULL, 0x6F21B537793020CAULL, 0x2B9A92C4CC595526ULL, 
            0x07021575457A25ECULL, 0xA2C48350CF8D1924ULL, 0x508A02A0DEFA13A0ULL, 0x55131A7D56247F54ULL, 
            0x8919D31CB5167CB2ULL, 0xFD6BD919B338EAE1ULL, 0xEA2763B92807660DULL, 0x0A3D8F972A86D717ULL, 
            0xE9B52132E846BC5AULL, 0x6C0B687A4EE434E3ULL, 0x6410A03244B0425DULL, 0xD301211E9BAA0AA4ULL, 
            0xDCEC8C88BB5E2445ULL, 0x64B2DD40CCBF4D8CULL, 0x46B25B7A17DF2BABULL, 0x6A6173A83C4C137CULL, 
            0xDC494C35473133D4ULL, 0x5046A6C9C91C42DFULL, 0x4609DA9573F63CEDULL, 0x9F0EA64D6E11BABAULL
        },
        {
            0xD98A5D271AA90C40ULL, 0x6160F4A7837B067BULL, 0x41672895BAB734FAULL, 0x7FF59F68102A266BULL, 
            0xB25B1DE651332994ULL, 0x0F121113F68EB44BULL, 0xEF7DA6BEDF16A6B6ULL, 0xF3A18B829528BD10ULL, 
            0x6F9F03A2CAF05F2CULL, 0xE45C645468AFD6C3ULL, 0xEADA1703F99B5083ULL, 0xB4F451BE11A1B06AULL, 
            0xF791AA91A4AA4EAFULL, 0xB0FEDFA2D863B2F0ULL, 0x31A6C9208BCCCFD9ULL, 0xC0ADEF061D72B5A3ULL, 
            0xAE58D14A69707F90ULL, 0xEAF699526CA929D5ULL, 0x40E606C53AFC31A9ULL, 0x35098C47C32E1E9FULL, 
            0xC9FEA6CCF7C92DEDULL, 0x0923D32DAC298BCBULL, 0x8D6D115233E833E3ULL, 0x103BF1FCF3ABA488ULL, 
            0xCA6B4BF9EA3DC399ULL, 0xDF90F2395C5EB706ULL, 0x22FBC68C1F75785FULL, 0x6823E9E1A028B11EULL, 
            0x0306FF27D86CF36BULL, 0x848028E2B627A375ULL, 0x1A4141DAB243739AULL, 0x6B1F2F8BBA728180ULL
        },
        {
            0x242C14DA862FF68EULL, 0xFF4242DF5426402BULL, 0xE162899D4448F028ULL, 0xC5DDAEA31CA526D4ULL, 
            0x487A3AC144137FCDULL, 0x73015C0966A2AADDULL, 0xC3C585B88F805F18ULL, 0x15BD149A31BD5591ULL, 
            0x58AF27CFAF2F1125ULL, 0x7D955020DA49C2A3ULL, 0x6D5B1CB102D75DBEULL, 0x72224630AE276CC3ULL, 
            0x501872D64579DBF5ULL, 0x106B16E33B80D18AULL, 0x1864963B64D78A89ULL, 0x6A46D94468587A6AULL, 
            0x550DF1989AC31699ULL, 0xE0DB9F44C1180D0FULL, 0x1B11621D1E472CB1ULL, 0xCBDA44316D6C64D5ULL, 
            0x95A2E5C90F43952DULL, 0xEE41A65150D8B085ULL, 0xA010E1EA192A7411ULL, 0x12A4D4B783BE0D2CULL, 
            0x58A53E8E1C2F1BD3ULL, 0x9F566B5C7EC4138FULL, 0x386B2E4495FB9CEDULL, 0x7D4D381F3FA81078ULL, 
            0x76F1A281B4BD5E94ULL, 0x0AB24CA4BDC346A7ULL, 0x53334E196B97046BULL, 0xDA871014C6054AA0ULL
        }
    },
    {
        {
            0xFF1CE3F77D604226ULL, 0x8E148595950E49D4ULL, 0x7ED5D4973BCFC414ULL, 0x53DB6CDFF28EA49DULL, 
            0xD0F86CE9FE5FCC11ULL, 0xC98135BDBF31614AULL, 0x8AD24D57F698702DULL, 0xDDC7B1791F6C41B5ULL, 
            0xAB6D20EAAC888181ULL, 0xBF9A0BF2A7272116ULL, 0xCD81BC131F511E6BULL, 0x034D6F5CEFF682E3ULL, 
            0xBE8D7AD30FE4FD32ULL, 0x85B828901FDB8435ULL, 0xDD88545463EDDEBFULL, 0x22D4245240852FC4ULL, 
            0x26A2BEF0D2AD737CULL, 0x3916E9F3E1550700ULL, 0xD6E04C85B0DF0B65ULL, 0x9700E7022CDE7C43ULL, 
            0xAC4291EDAC645F89ULL, 0xFC0C159E54BD7A5EULL, 0x8F3A0D56E8A6C4C6ULL, 0x7DB6977F4394167CULL, 
            0xDFF4D1CB58B378DBULL, 0xE333234B23A19842ULL, 0xE4C44B51560E49C8ULL, 0x1F839DBE748569DAULL, 
            0x84E9FDFE98CB46CFULL, 0xB91A4460A101F447ULL, 0x5A48F680B2E24575ULL, 0xB0FE3017576BD213ULL
        },
        {
            0xA4CD21449CDF838BULL, 0x2C99CADBC53741F0ULL, 0xE057CC68A41C7912ULL, 0x9BF6E38FDED6C6D1ULL, 
            0xA6FAD3927DB64246ULL, 0xE1E1869F63B8A43AULL, 0x2752012FE1F68D4EULL, 0xBED5229EAA1BCF35ULL, 
            0x18D9DC7904124859ULL, 0x70DB6E9751F2E0C7ULL, 0x02339D5D692E7ADDULL, 0xE6AB6F491997D9F4ULL, 
            0xF63AB6465C0664A0ULL, 0xEA51EDEA3ED358EDULL, 0x0746786335189BDAULL, 0x689FB335F83A90DDULL, 
            0x945A038A521F2CC4ULL, 0x6B33D0782EE532AAULL, 0xB71E6EFAE641043BULL, 0xB64517EFFB40D0F8ULL, 
            0xC51868059F7E72EAULL, 0x93BF7F1B85451EB5ULL, 0x8FEFA312208B82C3ULL, 0x013FF2335F5D1EFBULL, 
            0x6A7568EB6E996D94ULL, 0xE14EA91226D98B11ULL, 0xF2D13F3C89A12A37ULL, 0x8AEEDF2AD19EEE13ULL, 
            0x98263D51E3D8CBAFULL, 0x127F7C5202EE6942ULL, 0x732126F1F824F9AEULL, 0x3358F44D911795E3ULL
        },
        {
            0xD2ED240C1D78BEE3ULL, 0xF258419661CDBFDBULL, 0xECA65D3ED2A1166EULL, 0xB1F03390715872A6ULL, 
            0xF2CAF56CD1CF0363ULL, 0x9FB6D4BC39C581D4ULL, 0x404598C3ECCF157BULL, 0x39B1B812AA9049D1ULL, 
            0xC7E70452CAA5A95BULL, 0x09CE37BCDD7907DBULL, 0xDFD3673FBE64DC81ULL, 0x143265E50911BBF8ULL, 
            0x6DE3A3DBA0CA7A4DULL, 0x0C5D02DD203DBC7CULL, 0x1E01F078B45CEC36ULL, 0x41D206F67CE730A5ULL, 
            0xF31D2ABB6CBFAD16ULL, 0x412CFEAD4C300B6BULL, 0x94B4169206735A63ULL, 0xD5BF2982F8BF3E40ULL, 
            0xF4CC255DFCCB8A71ULL, 0x725D2822FBD04F3DULL, 0x24E739D0B01DCE44ULL, 0xD2FC2EA2F1CD51DFULL, 
            0xD243AECA1E69A6B4ULL, 0xE845CB6117879E52ULL, 0x97F3B68CB5F96E22ULL, 0x2A809CEAC0EE3394ULL, 
            0xFB384C880FE83848ULL, 0xB0FD4723EABB6FD7ULL, 0x54E8AACF25550A73ULL, 0xFA29F77F7E0F25E2ULL
        },
        {
            0x5B3354A525FE0B1EULL, 0x3EEE2BB934BE2F32ULL, 0xC84C1BFAAF77D941ULL, 0x3B1B9AA0132BE79FULL, 
            0x9C9216BB57050888ULL, 0xE5BA46E0F426DAC0ULL, 0xE66E9AB265E8C92FULL, 0x50FBFAD16AF88DF6ULL, 
            0x1538882640AA2462ULL, 0xF31E86899AB12C22ULL, 0x846AF6D8639F82A5ULL, 0x7CB8EADC2B74CFA1ULL, 
            0xF26E67C9F73FDCB8ULL, 0x478E25700A911551ULL, 0x3497FAF819DB3AC3ULL, 0x1E987F6655E4FD6EULL, 
            0x6F6C6174CCB8B7E3ULL, 0xDFA81AD0543CD2BFULL, 0x6EAA77E9B652C56FULL, 0x52677AB7CBF9E653ULL, 
            0x6B725C3ABC657E56ULL, 0xA790BE3077914836ULL, 0x7517A658BE044006ULL, 0xBE2717211C122594ULL, 
            0xBDB2262AD33B4EE8ULL, 0xD1CDFD57660CF673ULL, 0x6A0CC13804ACA2F2ULL, 0xFAF5724A27A489B8ULL, 
            0x8827C90884966DE7ULL, 0x25C04783CB49F4ABULL, 0x96B72D86EECDE190ULL, 0xED6D65EC011B1A6AULL
        },
        {
            0x188A226AC997678BULL, 0x9A23AA508769DD35ULL, 0x2DF23803C6274554ULL, 0x9E6E20A54724F246ULL, 
            0x24B37E72EE1B35CCULL, 0x75F9E048E5A10071ULL, 0xD04AA7B59A96675BULL, 0x167C022A9213FDE1ULL, 
            0x0E155A97B9DD2C62ULL, 0x7F5C9188903425FBULL, 0xC1C712EA3837A924ULL, 0x6D12B4397AE0A99BULL, 
            0x172C917B4EBDDDBBULL, 0x79E3DD0A97D3AE2BULL, 0x17E0067D4DD55853ULL, 0x2C5701201FF508C4ULL, 
            0x851916B63AD55D5FULL, 0xB9A530801512F469ULL, 0xCE5B95E3EFD52989ULL, 0x0C89407002A8F9FDULL, 
            0x2F5A5AC374BC3A3EULL, 0x108E0B08CBCE7AEFULL, 0xF4F2FAF651E5E860ULL, 0xE1AD3079F438B664ULL, 
            0xD486C109AB87AAF6ULL, 0x7EB51173614B8199ULL, 0xBB44564F88A5A1A0ULL, 0x205E4D95C454E503ULL, 
            0xE2DC2ADC23CC647BULL, 0x5FC448995232E673ULL, 0xA6134FE76BEABADDULL, 0xFBD1C2E3550E3751ULL
        },
        {
            0xCF183649E2B192D9ULL, 0x884D17C018D5D3D7ULL, 0xA83CFF40540185B2ULL, 0x9240FAEDCEED601EULL, 
            0x8DC27B684DDB5DF4ULL, 0xF867EBC319A3F9B8ULL, 0x156098B4DDBC8CC6ULL, 0xEDD3082EEC41DE99ULL, 
            0xC9CA3B3F356DE85CULL, 0x97CBDAC49A95680AULL, 0x48C03F4DD0AC29BEULL, 0xDC796F220E38309FULL, 
            0x7020674A9A769DAFULL, 0xC65AD03D4E006B83ULL, 0xACD26CD33DBD78D3ULL, 0x6CE8C39775FAD2B9ULL, 
            0x79894F6181F9BE1EULL, 0xBC8B011F4F0DF604ULL, 0x5453CCEC28D19FF6ULL, 0xA496A5645918BA53ULL, 
            0x3FCCC1B6C9358833ULL, 0x2FC07B4D169D7B90ULL, 0x750444E8D18F6CCCULL, 0xFDB033927D6DE2A6ULL, 
            0xBDE5ACD83F996050ULL, 0x6AD293E6B0BF1466ULL, 0xAE2AF178B6795529ULL, 0xC209CED56F2BDA9EULL, 
            0x3220E86D65D509FAULL, 0x47A8AD1C502AD02EULL, 0xADA329E3DC2E64CBULL, 0x374871B6326F8545ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseFConstants = {
    0xF51030F2773D8C3FULL,
    0x4009155B3822EB16ULL,
    0x6720E33699AFA541ULL,
    0xF51030F2773D8C3FULL,
    0x4009155B3822EB16ULL,
    0x6720E33699AFA541ULL,
    0x1358DA3406D53264ULL,
    0x45D11AC3867FF631ULL,
    0xA3,
    0xB4,
    0xE2,
    0xD5,
    0xA7,
    0xDD,
    0xF6,
    0x97
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseGSalts = {
    {
        {
            0x76CFB891A0D4189DULL, 0x9975F89A535A3324ULL, 0x0AAB06EDD4277EF3ULL, 0x77F214CA6E11D5C0ULL, 
            0x92A337D6D78A62ADULL, 0xFBDCCEA65F2EE353ULL, 0xED13541BDB749A98ULL, 0xDAC2FAE9A94999D5ULL, 
            0x3B9C5F07E9E5274BULL, 0xF4D7A39EAE39BAC5ULL, 0x3E2D509ED1BF857AULL, 0x9E1FE7BF9FC1F0EFULL, 
            0xE9A01A6C6E5426F6ULL, 0xA12824261AB97016ULL, 0x1C6261C9BE153B99ULL, 0x9A335585FCE5D9CAULL, 
            0x640B8A2E1EAE9A54ULL, 0x12B5F42186D925B3ULL, 0x05F5979FC8093399ULL, 0xA77A1EE75D55842CULL, 
            0x13628A841E2A5630ULL, 0x67A797E5A197075FULL, 0x60FC1AA4781E3C23ULL, 0x0F77E61C2D66D1A0ULL, 
            0x56F7F1798C734F96ULL, 0x2FB8230A1A73E5B4ULL, 0xF3E71D1D72E06854ULL, 0xD38D36638D5C1953ULL, 
            0x106E14729FED1559ULL, 0xC83381E49ABF518FULL, 0xEBB289AB734401CBULL, 0x0CEB3290CDBB6426ULL
        },
        {
            0xF222B8DE59CF008AULL, 0xC7E893AF4148F8B2ULL, 0x405E518F7CEA8C6FULL, 0x9428997E2CF14CB7ULL, 
            0x06CF2E3F1698A6ECULL, 0x663A6DE8DADE7666ULL, 0x39976DE345437B4DULL, 0x8BA4ACDC79DDFBF3ULL, 
            0x5C3E2DE932C04708ULL, 0x07893AA771CA905FULL, 0xBAAFE6B1B7715203ULL, 0x07D463D921162888ULL, 
            0xFA11C7E292D8F488ULL, 0xD987990691F860FCULL, 0x9C236FDDD0DD3B37ULL, 0xAC983F61A66326D6ULL, 
            0xBC949CEE99D6AA9CULL, 0xBE2B58BBAAEA462FULL, 0xAF5E80739CCA22B7ULL, 0x94362D58625710F3ULL, 
            0x838D3369EA6734BEULL, 0xBBC553B7C7B16127ULL, 0x294A9030728DE87BULL, 0xC2FDAC3BFED59146ULL, 
            0x5CFA157182494697ULL, 0x4E41E62A6E1871C1ULL, 0x6BB265C6DD6D38ABULL, 0x2B5495CFA46A278CULL, 
            0xA8B76D01BA1AA722ULL, 0x6CE7E35C710B4531ULL, 0xE1F4140E82E8E4E3ULL, 0xF4156B8EBB7E5532ULL
        },
        {
            0x16A514EF0391A012ULL, 0xC6E934E9F4AB4BEEULL, 0x47EC9E06AC17A9CBULL, 0x5D4E75B82D72858BULL, 
            0x32CBAA065BA249F6ULL, 0x1BB6CA734846289CULL, 0x7C522B9C80517E37ULL, 0xEDCA9EDEED4F82D1ULL, 
            0x90AE947A7A69FED6ULL, 0x764119EC9C54FFC3ULL, 0x93F7B1102B664E1EULL, 0x0B54703C93AB4651ULL, 
            0xEE7AEF0E6317B382ULL, 0x6285CAFFC37517E1ULL, 0x32780C9CD458FEA2ULL, 0xEB71F7AB8DE8806DULL, 
            0x6BEC38D0405D5250ULL, 0x11B9878DB6054BE4ULL, 0x4048AF403EFB571FULL, 0x1FFF70194F8B0FD0ULL, 
            0x5EB27F5661416D59ULL, 0x7643299A400881F9ULL, 0x7A5B494C4FBAA788ULL, 0x88BC5BD7BE01798DULL, 
            0x238450C7C6EB92DBULL, 0x17EF2CB6AC99791EULL, 0x3FA4AEDFC610C673ULL, 0xD57CF626947D26C0ULL, 
            0x054741AB0079E488ULL, 0xED39AD70A9AC2B61ULL, 0x1865A115DB2C95D4ULL, 0x8C4C4C89570C7095ULL
        },
        {
            0x9152A2575E78D6EDULL, 0x5002419A7F51A5D9ULL, 0x41C81637F1B6410CULL, 0xEC5A47B39ED34AAEULL, 
            0x7090DDB0097E9455ULL, 0xE50976DEB6C54C48ULL, 0x0ED448D81299911BULL, 0x0400F028B970FA3AULL, 
            0x88B4FCA1BEE00994ULL, 0xE773C0B8C7A22301ULL, 0x476522CA8D3724F6ULL, 0x39B78A7F1BFE0144ULL, 
            0x48456745057A066AULL, 0x74065A502D22AE3BULL, 0xDE1DDC9B538F9A65ULL, 0x2E7BF5014E813F43ULL, 
            0x3666EC7F9C64F1A7ULL, 0x975808C88BB3675EULL, 0xC5535988309B13B7ULL, 0x03D78841F905DA3DULL, 
            0x183A8D9E1BEB3A82ULL, 0xAD89F0D9CDA71B6BULL, 0x9256AEE852CD6D9EULL, 0x23819B66C84FAE63ULL, 
            0xE3C0220AB5AD0CDDULL, 0x77E3EBA489EC8A9AULL, 0xAB19A65219F68C58ULL, 0x779C20B022D20615ULL, 
            0x6BF1E85FDC393096ULL, 0x4D7520C7E0961768ULL, 0xD60B3D00B99B9801ULL, 0x861F1E730BC1A311ULL
        },
        {
            0x1E9E85932A653075ULL, 0xE687D424B865189CULL, 0xBF5F24F681C0FD17ULL, 0x60CE7FD29345E06AULL, 
            0xEB459CD8D4F053F5ULL, 0x8C1C5DA28C7171B6ULL, 0xE9BED63DEDEDB098ULL, 0x48064EE28BAEC669ULL, 
            0x783AD3080C845168ULL, 0x41B06E5D25594DD2ULL, 0xF42E6FFA438E6499ULL, 0x6BA231AAAA53FD5BULL, 
            0x916B5D63C6F0AB12ULL, 0x8C03233CA51D9D0CULL, 0xAF914BFC7B22F76EULL, 0x094C57779F5D0C84ULL, 
            0x9E27745FC7FDFEF5ULL, 0xC66DF0EC2D3F0E26ULL, 0x5548668090BD5C5EULL, 0x43500A0906085C50ULL, 
            0x8E68EB2D86565E84ULL, 0xE5D10B78152E61D6ULL, 0xC92FFDC7D37645BFULL, 0xFD8E103B70BF5AD6ULL, 
            0xA58CCC992B85EB10ULL, 0x5A59E113830C0960ULL, 0xF7EE4CEA3C33A54FULL, 0x51FACBF481E6134EULL, 
            0x665F0B29B425D23FULL, 0x2D37262307D0BE19ULL, 0xBE9C02EE3A1112C3ULL, 0x8BAC6D93B816C222ULL
        },
        {
            0x7E812421F0F94A5AULL, 0x6EB6AA0041118476ULL, 0x438435F60A78E972ULL, 0xD384C939F073892DULL, 
            0x395A2DD8EDF87F5CULL, 0xC3DC0B5E34380DE3ULL, 0x7569EF72C24FAB6FULL, 0x84B9071E97AC1C58ULL, 
            0xF662960191CC41D5ULL, 0x46CAB7D7715879C4ULL, 0xAAC223A417807DB0ULL, 0xB3843A93381811E1ULL, 
            0x71622757DF93B3A2ULL, 0x79C5D89620405EAFULL, 0xF29A4B12FDE2491FULL, 0xA3C6F00FCB90E04DULL, 
            0x71FADEC1B73FECCFULL, 0x81B78FBAA0B8A784ULL, 0x11A9F7F07BBBF238ULL, 0x95B71C3812CEFC8BULL, 
            0x5EC6A7B845E97FAAULL, 0x4503DA819602A832ULL, 0xA12A12C5E2F8B0FEULL, 0x37392D81F06609F1ULL, 
            0x16BA46492306011AULL, 0xE3FD3721F91B6FCBULL, 0xD639F84C442DE5D2ULL, 0xC27066CFE481A588ULL, 
            0x6C206612D8EA4609ULL, 0x3B07A4BA033AC89EULL, 0x353E41FF14C6BF88ULL, 0xDCF56421A364FC68ULL
        }
    },
    {
        {
            0x805019FC86240D31ULL, 0xA2BD6E27D1F2B4A1ULL, 0x35CAD14D80643BB8ULL, 0x5B583B9175107B03ULL, 
            0x42C7AE889BD17B61ULL, 0xBC8A91C50C441612ULL, 0xB894BC4C8B628FE2ULL, 0x4073169AB8462C54ULL, 
            0x80D6085749DC963CULL, 0x2E1C3CE889027630ULL, 0xAE99C42BF6CD54A5ULL, 0x06581A8B55111CC3ULL, 
            0x646A68D9AC342B82ULL, 0x91A9FD93AD4C7513ULL, 0x5F8CCEEBA329F05EULL, 0x57A415B8C1EEE12DULL, 
            0xDDD9D1BAA4D5597AULL, 0x5C40A8561E883DF5ULL, 0x4B04F6FB083A26EAULL, 0xFB91CF509514EE9BULL, 
            0x866074F431745EA7ULL, 0x596DC6164074819BULL, 0x8C9FC7E174B6A591ULL, 0x1C11993351CBC3BCULL, 
            0x8F8558EE6BB2F98EULL, 0xAC356D38BBB664EEULL, 0xB310E18D8353CF91ULL, 0x70617A04617BC2FAULL, 
            0x549D821FC0EC67F8ULL, 0x671E89F858321ACDULL, 0xFB03BEF739317B27ULL, 0x29678E8F9CF3F2CAULL
        },
        {
            0x16FB5429420180AFULL, 0xD46C99D4E9FF1DC1ULL, 0x8996EB3BD3EFABFAULL, 0x122CBCC1DA3343E4ULL, 
            0x0F8183282F7FF8EFULL, 0x0000B8F77D19CD62ULL, 0xDA04BD10EF62BF65ULL, 0xB48306AE1FC9E1E8ULL, 
            0x05E4A3DB876723D5ULL, 0xE29C91621D4AEAA8ULL, 0x7F02820586AB52D9ULL, 0x8379407A03BCFC35ULL, 
            0x195C9BC53A0F74E4ULL, 0x4E68C90FE5497789ULL, 0x73F1E43AEDE55BDEULL, 0xAD1443ADAC9E2274ULL, 
            0xC58A5FB5609F1FE9ULL, 0x21B5067B5B2ED919ULL, 0x068D279EB93F824CULL, 0x49826866684386BFULL, 
            0xA9BC0FBDF7CB1D20ULL, 0x3123EE7E5AE24FDEULL, 0x385060B00B52A183ULL, 0xFE42B685154335C2ULL, 
            0x812A8D46E2296689ULL, 0x6F7B55175F5B2265ULL, 0xCFE11838D8CCD953ULL, 0x9359D8910AEDF04CULL, 
            0x9C282C557E470042ULL, 0x1AEDA305C07C3564ULL, 0xE453490DC27A5EC1ULL, 0x9F829BD9A4EE2518ULL
        },
        {
            0x725AC303FCC7E688ULL, 0x1E78746811CA6F17ULL, 0xFB065E9007D14213ULL, 0x9363D10E64F8F816ULL, 
            0xCF1C0489FEFC44EEULL, 0x4B7A08E1031F879DULL, 0xBC73B6D1C01232F6ULL, 0xB9AF1A5AAB91885FULL, 
            0xA2677BD983888DAFULL, 0xE0D4A4DFEA493478ULL, 0xD391BF3A546FD48CULL, 0x248F96D43ADBBFE2ULL, 
            0xDCDBD38672F94395ULL, 0x40A5F87406485A9FULL, 0x67E0BCCE5E5B6936ULL, 0x0F9B0AE72180685AULL, 
            0x2249310143F58550ULL, 0xB45EEB8DF49BBB3EULL, 0xA2FC582857AF31F3ULL, 0xC3C550A22B4512EBULL, 
            0x909DD107AEC53528ULL, 0xFD6D4E7756BD6BE3ULL, 0x60C12B7C18530E03ULL, 0x0A09F74E21559CF3ULL, 
            0x72847BF76CFA4252ULL, 0x3AAE3071A23DFBA2ULL, 0xCC3489133CA1B7E4ULL, 0xB1CEE48A72931BD6ULL, 
            0xBDB8791AEF455DF0ULL, 0x90E56A9916AC86F3ULL, 0xACAB0E6CDF16B5F8ULL, 0x6D214AE46F72C7CAULL
        },
        {
            0xEE301F599E8F897FULL, 0xA573E68CA362F98BULL, 0xECA5E8F163315BB3ULL, 0x4288240F2F11A59EULL, 
            0x2ECFB557E712D8B4ULL, 0x68AAAC95A2D30375ULL, 0x91F96C3657A9D4EDULL, 0x642E60B2908E0E97ULL, 
            0x317B4A3EA45220ADULL, 0xA39122FE9A0D4DDCULL, 0x8CFBFF2F2443D2FEULL, 0x368F68B521479038ULL, 
            0xF9B4E8B1BBD62045ULL, 0x28A355265CAA7007ULL, 0x993733AF1223452CULL, 0x52AFCDBA2FFFACDCULL, 
            0xC805781836EBFC62ULL, 0xAC5822399BFD5069ULL, 0xA97D3638301D24FCULL, 0xC1C4940EE55C516BULL, 
            0x81A6A6BB92AE52A8ULL, 0x5BAB80F18F5A99BAULL, 0x1619CD9FA0F9F047ULL, 0x1EDF8E65FC877EA0ULL, 
            0x3AD84251C7013658ULL, 0xF46A3B47100A7E3CULL, 0x016EA9D11CE73FA5ULL, 0x1041FA08E5A6B65BULL, 
            0xF72779A22B43F012ULL, 0xA63F14F8226796C5ULL, 0x7E38E348AAABB104ULL, 0x8AE3523DF682E443ULL
        },
        {
            0xE59061F7BD5F8D0DULL, 0x40CBD08F2FFAC64CULL, 0x42E6FE124087F43BULL, 0xEE63446CBE4792D3ULL, 
            0x602E4B22F4A557F1ULL, 0xC5F2181C714ADE46ULL, 0x64B39CE525DC5C15ULL, 0x5E2724BD161F8805ULL, 
            0x79A7C04058E8320BULL, 0xFCE745BDA2776CBEULL, 0x84923C96F4C7A78CULL, 0x8782D44D69B57235ULL, 
            0x8A64CC6CDFCC96E0ULL, 0x4FB321BF9816A36DULL, 0xC9F642EB7ADB5A56ULL, 0xDD0899745CC89FB1ULL, 
            0xB28799E67E9CDEC8ULL, 0x677FFEBD753A952FULL, 0xD01BCF84DF0842A9ULL, 0x1BE67A469D7CF924ULL, 
            0x8DF7BA54BC789606ULL, 0x36FF600609AAE85CULL, 0xE65CD488DF276438ULL, 0x9723D09263BAA899ULL, 
            0xFD7253B3379D2240ULL, 0xC112EF44A09D5F54ULL, 0x2066621BC7D51B28ULL, 0x4927536DE35CBFBAULL, 
            0x944102D86FD7A4B6ULL, 0x72B63F283967900CULL, 0x819B11AA879A1358ULL, 0x1AB858CE5B928F38ULL
        },
        {
            0xD00329CC4756E5FEULL, 0xF0B7E3D69ECD598CULL, 0xF1AB3F1A277B1E2FULL, 0xBEB8E278CDBA4C44ULL, 
            0x92FD1CA08D082042ULL, 0x9FA9DA96FD78BDB5ULL, 0x55FF992C368862ECULL, 0x054931C5CF154290ULL, 
            0xF93F69B3FE04170DULL, 0xB5B1FFFED05616FDULL, 0xE1F2763A3697E01DULL, 0x127776BAF4F4D421ULL, 
            0xE1BC6513BD011A87ULL, 0xF97E1907F5CD0B07ULL, 0xC08044352DA2CECEULL, 0xDB9F9917B2C50B28ULL, 
            0x0D129421B3F3C3A3ULL, 0xF2EC45A29DC5A778ULL, 0x20F26701A3D7D535ULL, 0x0E9AB9BDF5071ACDULL, 
            0xF343FE7E81B755CAULL, 0xEDD6D333026B3FB2ULL, 0xFF95734EC4623DDCULL, 0xA5D76DCF3E1AF9E0ULL, 
            0x6EB4D2CA707892A5ULL, 0xC645140786FD668FULL, 0x1EF52CF846DA26BFULL, 0x745C18927B60A318ULL, 
            0x7E43E28D8157AD41ULL, 0xFB5BCC20D086D882ULL, 0xD4D8CD92B64AC9CCULL, 0x31185F706EA962B5ULL
        }
    },
    {
        {
            0x29AFAACFA68E7C07ULL, 0x0976037BF58E2BF7ULL, 0xE81296823AB80EF1ULL, 0x3035991C2E4A6C49ULL, 
            0x61D5D46121B8A90EULL, 0x32A2F67E704DC817ULL, 0x279146492C3E3B35ULL, 0x387D1A58D9C8D92FULL, 
            0xFEB6F73FA1E361BBULL, 0x4E2D1E632F22D2BEULL, 0xFCAE4BCC564239A9ULL, 0xFA4CFE02A82613A1ULL, 
            0x0C070A0D60713DB2ULL, 0x900CA1CF305CCE0EULL, 0x27D4769A6A1C9172ULL, 0x4D7343BDEA416C05ULL, 
            0x9FF25283A7191110ULL, 0x2904BEFAB508462FULL, 0x3C9DAD58FE5EB16EULL, 0x298404275FCBCFDBULL, 
            0xABE740B1E0E100F1ULL, 0x3A89629A56C81227ULL, 0x445BF7FC46300E2AULL, 0x91777AC6E638780EULL, 
            0xC4BAC2B633EDBAB7ULL, 0x8AFDEBDCF258F3E0ULL, 0x409708FBF8E638E3ULL, 0xACE47DC59134B26CULL, 
            0x457546FEA5B3752CULL, 0x2759864AE617BF77ULL, 0x4834B2F5FCF8291DULL, 0x57934EA60B3445CAULL
        },
        {
            0xD887776E8483D68BULL, 0x1187DF80205C015FULL, 0xB1E80E09BC43A2B2ULL, 0x1006758FD76FA120ULL, 
            0xC50527C834CD0A33ULL, 0xCCF9AB69F70726C1ULL, 0xEA59ECF9A6B6AA12ULL, 0xABB0581B3F1E69F6ULL, 
            0x53CCCF1C72B1B79EULL, 0x8C87A350469530C9ULL, 0x719209D1374F942CULL, 0x5F5831A833FC8FF2ULL, 
            0xDB2E83B056EB85F4ULL, 0x0D57B0AC3D3B5544ULL, 0xF6DFC85C4F824144ULL, 0x0731CFC043D4CA41ULL, 
            0x715FC23EAB61FD9BULL, 0x7CB431A1117612ABULL, 0xDE0C91BB1E5F97F8ULL, 0x0A1265AC6B38FC6AULL, 
            0xB74E9AD8AD9B71D4ULL, 0xBBB7EAB5518FE699ULL, 0x665DE48BF6854FBAULL, 0x8A54CEB0617ECF45ULL, 
            0x8B03128D1A7A3970ULL, 0x0AFB2CCEA6D4C545ULL, 0x32479ED7E642A150ULL, 0xC6C1C799B2F7E3F2ULL, 
            0x46B3395A0DC127B2ULL, 0xFE9CF7E5ED681842ULL, 0x7E353D29446D1322ULL, 0xDC160638E796C96FULL
        },
        {
            0xF4D1B9FA1F885F54ULL, 0xD34AEFC5E8382B7CULL, 0x8E1EEA1EB7595A85ULL, 0x7A6DD47448D516AEULL, 
            0xB477B530C4F58BB1ULL, 0x0779FEAE1861DCE5ULL, 0x2D02E22A08B0A5ADULL, 0x6321831D1635396AULL, 
            0x7A642CF5E5775A31ULL, 0x2A91F002132AD9C3ULL, 0x85AF5FE000D13FDFULL, 0xC99A27FA87368EB2ULL, 
            0x5B715CD035306BEBULL, 0xD530C3C4A835A075ULL, 0x55CFAC8782EC09E3ULL, 0xD7576A9D4F51B29DULL, 
            0x6D3F92974DA268F9ULL, 0x11450CA2ABD430A1ULL, 0xCBD226173089E843ULL, 0xDB15FCC4631EFA3EULL, 
            0x49509FEFC588BCB9ULL, 0x67E8C16ECB5DC91DULL, 0x105A3D745AD37FB7ULL, 0xD29FEFB36DF3886DULL, 
            0xD185CC3C057EB7B0ULL, 0x9148F30BF13C0D6EULL, 0x3614FB68B9D6E004ULL, 0x0F72721FE626BE2FULL, 
            0x731FC185B0178070ULL, 0xD25D634DED4909E3ULL, 0x86CCAA3256457607ULL, 0x3E57BC8A590338A4ULL
        },
        {
            0x06A536836BBD025DULL, 0x2955B610ECE15310ULL, 0xA9C9C5DC7C03DFABULL, 0x783A3ABA6638666AULL, 
            0x6B3A4C01EA116040ULL, 0xE741AA9366606D74ULL, 0xECB8E824D69EE15CULL, 0xF0FBA224E1F41C01ULL, 
            0x0D33DCEBAD1FAD46ULL, 0x9C7F093E1B1E90A5ULL, 0xD53EABAC83197C84ULL, 0xDA293C8F2D5585B2ULL, 
            0xF889084C05C629D1ULL, 0x1280593817FD01B1ULL, 0x1E108DB9722E975FULL, 0x15BEF69D196CF14BULL, 
            0x4131588828C6CDADULL, 0x9C741187AE4760F0ULL, 0xCDCC6E6B24C71AE1ULL, 0xE7AEB8475A19A768ULL, 
            0xBE96768694B182B4ULL, 0xFB549FF711E5E80BULL, 0x13EDC1BF0E55F394ULL, 0x4375555E000C1A91ULL, 
            0x0CD0FEB8ACF45486ULL, 0x8DFCD71B2C754B78ULL, 0xAB41AF82FA9F017FULL, 0x7FAADD3CC5786572ULL, 
            0x91D65F01ADA5FE29ULL, 0x9A7FA9BB6D4653F6ULL, 0x9B7FAEFFB8D971FAULL, 0x5CFBDCA592CA3079ULL
        },
        {
            0x12B269F286719541ULL, 0x2F8A2EBDEFBA3ADEULL, 0xEEE65E3D7FD6B5F6ULL, 0xD09DD8557728C666ULL, 
            0xA25F4993B98B56DDULL, 0x2A991433137A07ABULL, 0x00246C5C3FED4179ULL, 0x0235029963995D4AULL, 
            0x2B5FCA1A41F45AA0ULL, 0xCC1D7C536034DE4BULL, 0x51E88B9D31E00C3BULL, 0x2A80E14371B53AAEULL, 
            0xB6C297B07A7BB155ULL, 0xDB0CF99F479FEDDCULL, 0x768AA1377FE1C963ULL, 0xE2CE4C5D45DDF263ULL, 
            0x8CF3626BA9ECFFFDULL, 0x6E21FB1D79C86782ULL, 0xD6185196773C246DULL, 0x6874C9D0A60D0798ULL, 
            0x5D52BD3E40BB8459ULL, 0x656172ECD1BBB71CULL, 0x56C31DB7D068E670ULL, 0x2A0BB02AD54AF598ULL, 
            0xD3F864052CF9EC92ULL, 0x974FA67683B8452EULL, 0x8B361DB40BE606D8ULL, 0x69B39249C96C5D6EULL, 
            0xC506E12176F19C63ULL, 0xC69D4671FF1AA09DULL, 0x4BC35AB34556A184ULL, 0x49517C4D1122B681ULL
        },
        {
            0x2D15AF375E393B93ULL, 0xC52DE3335DF65110ULL, 0x9337A06075206B13ULL, 0x4023422CB4F7795DULL, 
            0x30E6A8BFB66773C5ULL, 0x4279F204580D87C9ULL, 0x3909EE5BC62B1278ULL, 0xD35029BC421350BFULL, 
            0x20A2D4EBE0E37DD2ULL, 0x7DA853758057A909ULL, 0x7DE18A9A94CE3216ULL, 0xD5F0EDD7320AE5BAULL, 
            0xE49521ACEDEAEA9CULL, 0x4FF0C26C166BA369ULL, 0x83A712E8680FF903ULL, 0x3C953D62FB4F4340ULL, 
            0xC4DA60E2C8E1D9DEULL, 0x7070BB771DA2F1C4ULL, 0x0F10B2C7A730DCEAULL, 0x6E9F1274F0444DC7ULL, 
            0xAB3FABED49DCFE0DULL, 0x2A1E29DD2FC18DD1ULL, 0x5CB5E78A7E133064ULL, 0x64CD0A2095D2D2A2ULL, 
            0x085721E611911080ULL, 0x85DE04ED601B983EULL, 0x9D142FE637C88742ULL, 0x07F92E0CDFAF17B7ULL, 
            0xD64C7C415507217DULL, 0x751B33CD9A22AFE8ULL, 0xEBF9AE1A6F859792ULL, 0x41F70AF27CD60FE5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseGConstants = {
    0x73BF68C204F99F06ULL,
    0x41F7D0820C75439AULL,
    0xBA72AEF254B9E17BULL,
    0x73BF68C204F99F06ULL,
    0x41F7D0820C75439AULL,
    0xBA72AEF254B9E17BULL,
    0x43E7087F12264303ULL,
    0xB8956B6A8A11B0B1ULL,
    0xFF,
    0x8E,
    0x33,
    0xE3,
    0xA5,
    0xEC,
    0x67,
    0x45
};

const TwistDomainSaltSet TwistExpander_FootBall::kPhaseHSalts = {
    {
        {
            0x3D79779D21928F45ULL, 0x80FDBBDBF6049936ULL, 0x9627FF01BE32BFADULL, 0x4CBF0B5B19323BECULL, 
            0xDB49F4ABB4C90117ULL, 0x1E607BF78CE11BEDULL, 0x399C121038655F23ULL, 0x91FC051A956DF769ULL, 
            0x083767BAD15B20CCULL, 0xBFE1B4C4858C6303ULL, 0x48004556EC259682ULL, 0x24D5F7870CE77ECBULL, 
            0xD23FCAA2963D3851ULL, 0xD9499A8A73B002B7ULL, 0x0F00837B3726D267ULL, 0x83B0D586587A0B38ULL, 
            0x1F44487161944BE8ULL, 0xCD6605E603F3B5B6ULL, 0x51691B5F1993A8F3ULL, 0xC7C93A1131588704ULL, 
            0x5D098FAF9B2542CEULL, 0xDC1B983FD940306AULL, 0xF578A6F8A329D031ULL, 0x06CFB623DE82DB28ULL, 
            0xD23B6DE7CF132183ULL, 0x4374D4B86534E982ULL, 0xD75DE2901292EEB7ULL, 0x3B0C0B95C770710CULL, 
            0x71E21F17C039F9AFULL, 0xDB8A3E3B5B4306E9ULL, 0xFE6F4EE31300187AULL, 0x624268A5D0EE5A08ULL
        },
        {
            0xA79AE4F85C745D28ULL, 0x88FD088C50637DA6ULL, 0xEBCA7C55A2E76A64ULL, 0x1BA2D0A092D7F15DULL, 
            0x2F8EFC8C464BAA59ULL, 0xAF4347F4C3AE5B77ULL, 0x22F15FBA1E24B1D6ULL, 0xD2EFD55FF8C7A7E3ULL, 
            0xBA4B4EE3AE6E03D4ULL, 0xA62A85816EAB64D2ULL, 0xA238D45833D953F7ULL, 0x1E2AC9B5F282BC6FULL, 
            0x700D27326262E1B8ULL, 0x14F76EBF7C5F48A9ULL, 0x3AC1F61BE33574CFULL, 0xB15CC6BC06925C46ULL, 
            0xFB1A21C0B51DC8E7ULL, 0xF1D33D467F968A7EULL, 0x1C9F063A88F9480DULL, 0xCD9C12E9394EF937ULL, 
            0xB23C3B634E1D37A3ULL, 0x0C313163592F68E5ULL, 0x27F5EB5065757C84ULL, 0x4263684B44C30781ULL, 
            0x67B36038B96F8E3BULL, 0xE3474BF9302CE3FBULL, 0xD56F590929491AA4ULL, 0xFB2102E63CBC2C5FULL, 
            0x03183EABD51DBDB5ULL, 0x769D552659B2CB9AULL, 0xC2E7562C869666C0ULL, 0x6FD3541F5B57DFC8ULL
        },
        {
            0x123F1071B6E22C7BULL, 0x20F06E7529D7F851ULL, 0x531905492BFAA504ULL, 0x7AA8EFB31E23E9EDULL, 
            0xC6EA5F39B6E16360ULL, 0x2192E5DF8F43EAC7ULL, 0x298206ACF5630300ULL, 0xD8D99A8946A2307BULL, 
            0xBFE8FA6D7CEA6EB5ULL, 0x03E8ABE6DAD58479ULL, 0x549508CE22805449ULL, 0x61204D926F0A96A6ULL, 
            0xD71E634BF8AE0217ULL, 0x3C79E0C406956CD1ULL, 0x3F357AB5CA89CF2BULL, 0x684F7AAA41181D72ULL, 
            0xE25D46E332AA073EULL, 0x3105FBA790809559ULL, 0x65E9DCB61F4FBFD1ULL, 0xE11FE30715641ABDULL, 
            0xA584ACF5028C598CULL, 0xA4A171E00C800CD5ULL, 0x069920532F4E0605ULL, 0x1DBA5BCBB1EDFFE2ULL, 
            0x422B172674AE818DULL, 0x8F9A56D2AD531106ULL, 0x54178CEC9B925975ULL, 0x4B01342FBA2D4D0FULL, 
            0xE39FDBA8BFA76A1EULL, 0xC06B52A56DCB273DULL, 0x596EC7486062C92CULL, 0xD8057F2E0E776AE4ULL
        },
        {
            0x07283FC788F5953CULL, 0x245F281795D1EC84ULL, 0x22DB6233B858C942ULL, 0xDD4B37DF1EE6A15BULL, 
            0x1D95539640E52607ULL, 0xCF33A62E1F5C22CFULL, 0x0899C364CA9732B9ULL, 0x44340E104C9CF2B7ULL, 
            0xD1218858E05FF5EDULL, 0xA863FF9923434D81ULL, 0xF61712D73F743F3DULL, 0x8736ABC8A302BEBBULL, 
            0xA4EE596E0ABD4B32ULL, 0xFCF90C1EF428CF4DULL, 0xDFC310EA77CF3A7FULL, 0x83B099157B5BE59DULL, 
            0xBF9BEEA10B3B8D8BULL, 0x50F1EFA938B1054FULL, 0x23FBADD9668F879CULL, 0xF868F7B81FB25AA4ULL, 
            0xFDFB6881D9E7BFC8ULL, 0xE389523A48B1C6A2ULL, 0xEE2A45980910D66BULL, 0x8E758758DF87CC72ULL, 
            0x1807539B03BE8E66ULL, 0x6C06D32C2CB58D80ULL, 0xB873964496EBC529ULL, 0x1AE02A4D67DA1CDCULL, 
            0x89F69ED1FE9C8565ULL, 0x914F56D46A690E7EULL, 0x3B5A6C82A8B9937DULL, 0xF61F94C20F53FE3FULL
        },
        {
            0xB264915BE10E2744ULL, 0x9515A7C2D8A22DF0ULL, 0xE108FC879DAA4835ULL, 0x60AB8E3767A1C9D6ULL, 
            0x924F08FEEB6E3003ULL, 0x7E193C215EC53E73ULL, 0x40032B86AF2A8E66ULL, 0xA303767EF9E9DB87ULL, 
            0xB07109B9939DA57BULL, 0x45076D7B2F8E4A03ULL, 0xFCEB068DAAF18368ULL, 0x3B15ECF8AF889055ULL, 
            0x77E71451A25A6279ULL, 0x7512B3CA9CFA3076ULL, 0xA3D195D87221C297ULL, 0x139FA1F2DBD0457EULL, 
            0xFDF887597A849EF5ULL, 0xB69C7EE65317211EULL, 0xB94346A6DC9E6AAAULL, 0xB095B3CB9FD8A05CULL, 
            0x14EABFC1F9EE5146ULL, 0x2599D63F06A25ACAULL, 0x736619BB198CBB6EULL, 0xED3C9E4818F73CF2ULL, 
            0x5FE704C8E83CEC43ULL, 0x5C57D23412C554EDULL, 0xB20B69F90D53D76DULL, 0x1EBA6F1D66D9D7B5ULL, 
            0x49BA9FFE6D06C2D4ULL, 0x23B1B0FC746369E4ULL, 0xBB0D7C55022C2B09ULL, 0x5461D0972C6EAA7BULL
        },
        {
            0x916C5A5DD3F660AEULL, 0x3541E39870A12175ULL, 0x2280527F3397BFA6ULL, 0x9D0E9C20C7BE553FULL, 
            0xFB0A49A3646EC1D2ULL, 0x0F52DD0BE29693B1ULL, 0xB9F32EA6DAE4FC05ULL, 0x32B948BDCA711FBEULL, 
            0x746B73E3576FD15EULL, 0x54A6E09728967E04ULL, 0x84FC77E76061C5E9ULL, 0xC7FBC60B7F27DE7AULL, 
            0xA1FD1655575B78CFULL, 0xA8CD4DE67A2A6AF9ULL, 0x6408ABFAC72BC7B4ULL, 0x6D5950BEDB1ABAEFULL, 
            0x8DB987ED08A2167BULL, 0x2FD13C5A7F9DB920ULL, 0x50B23D3AC1C335B3ULL, 0xDE22D8E2C9D792E4ULL, 
            0x41F91052EF67E733ULL, 0x790854C5FC059A51ULL, 0xEBCA666A4FAC720AULL, 0x6C517255C5F5CA9EULL, 
            0x57F4584185B64B80ULL, 0x4B1833D6523C6C9FULL, 0x93E393318615D231ULL, 0x3868BE09E86C31E6ULL, 
            0xC62713B1154B2942ULL, 0x37B5B9E85A8B26C1ULL, 0x6860C3E04AF8ED95ULL, 0x5E9616F04ABACEABULL
        }
    },
    {
        {
            0x7FC2850B30DD7F26ULL, 0xD5A872853DC8F122ULL, 0xE0C98EA0C172C5A5ULL, 0xDC86B5D9ABBA2F9BULL, 
            0x963A9F4D2E840963ULL, 0x82E3EB8088D31239ULL, 0xD38440C8413459A6ULL, 0x594735A95E7A9F14ULL, 
            0x0219FF01746BBAC2ULL, 0xB46220C4AC3207DBULL, 0x3DBFD752255CB69BULL, 0xDF25F4064452F101ULL, 
            0x781C2DAAB2580459ULL, 0x4455CB2BF35E533FULL, 0x645B6E0695D97C7BULL, 0xDAB952991F7741B1ULL, 
            0xEE4D143F19E2ECB5ULL, 0xF99B755088A49E26ULL, 0x0FB603E9F90D7E21ULL, 0xBE5DE8B79BE36223ULL, 
            0x8430F8E153417D10ULL, 0xB3CFDE480AC9006BULL, 0x9EE5A5822B85FA6CULL, 0x7B9DFB42EBB88FCEULL, 
            0xACE918012A6BBD7EULL, 0xA864C149A56BD1DBULL, 0x335C3F562FFF2565ULL, 0x4C6AA67F8CE74FDCULL, 
            0x7CE679CECE434A70ULL, 0x0258F16F4378F564ULL, 0x0B29D3754DCB541EULL, 0xF6AF9FE30D3B6ED6ULL
        },
        {
            0xA80F613466C4F1B2ULL, 0xA7E5C6906C412416ULL, 0x2E68E0D390B904BCULL, 0x009496D8AD566663ULL, 
            0x538AB84B7DC49E4DULL, 0x2B0B3D9A6CDE6D02ULL, 0x822243A36C90D2DEULL, 0x46C178EA7DBF8538ULL, 
            0x337578ACE0C3B336ULL, 0xB72A4A465F7EE9BFULL, 0xB8CE0D2E059DCA1EULL, 0x1571FBF9A97DFA2CULL, 
            0x0890214E3258ED05ULL, 0xA859D05C02D73F33ULL, 0x86EDF146BC1884D6ULL, 0xE078B737B1BC8190ULL, 
            0x4AB83F1FF7C4457CULL, 0x6B312698CA0A4AAEULL, 0xF52CEC3D8F36D7CAULL, 0xA97DC09669336C07ULL, 
            0x5E5A7C64A175E041ULL, 0x2E9EEA58C329C766ULL, 0x6FD8708A678D9CF1ULL, 0xD2C3AF160F7AAC8BULL, 
            0x9324FFE341E7F64DULL, 0x2BA669F6A967B100ULL, 0xED804515A53EE418ULL, 0x01093CB15E983BDEULL, 
            0x6B42980923A077A6ULL, 0xB2EA7B73E61E86A5ULL, 0x5E1F781D2AA26E0EULL, 0xE36E84753FC2C958ULL
        },
        {
            0x8279C0EB0BB480B0ULL, 0xFC723CA2052678BFULL, 0xA06A27AD5C616215ULL, 0x9B3E9AF6EF7985F9ULL, 
            0xC80AE854268587F9ULL, 0x79AA00DAB2C99AE8ULL, 0x76AD8D7758CF1FE5ULL, 0x47EBFDE249B5FF69ULL, 
            0x52B862FB8A055FE0ULL, 0x4A5C7096DFECBB8BULL, 0xDC758EFC82B6264AULL, 0x142C340E792CCADDULL, 
            0x25F0D23B955CBAA7ULL, 0xD59CFEFAB862362DULL, 0x6CF7B5F9213449CFULL, 0xDEA3A780A15C5FD4ULL, 
            0x69290D48DDF6D4F7ULL, 0x01A298D749CC90C0ULL, 0x554B0E38624F0BEFULL, 0x9C125A4A1B4FD549ULL, 
            0xA4AB732A57D0F10CULL, 0xFC16A3F56781A40BULL, 0x8C4FC6E2B0238BF8ULL, 0x3B2450AAC7E89A26ULL, 
            0x4B8FD8427EEC3F2CULL, 0xE2B1911BE1F0EA7EULL, 0x635886AEAE6AA211ULL, 0x4443B846E7D0892BULL, 
            0x0EFB1A0C03234709ULL, 0x40D309EEDD9FD920ULL, 0x3AE77EBB14A6818FULL, 0xADF0282F7ED0AB0BULL
        },
        {
            0xBB6D582A756669CDULL, 0xDEAEAA7EEECFEC28ULL, 0x4BF2F09314874285ULL, 0xA7230BD99736BC3DULL, 
            0xD8AF21558DDEA6CFULL, 0xDDD21DC28131B023ULL, 0xA0EAEE4F1A95DD78ULL, 0xD95E1A806D536CB9ULL, 
            0x1903686A404271FCULL, 0xD6A6281C49A13227ULL, 0x81F9B11AC5F960F7ULL, 0x522FBF53989BFE70ULL, 
            0x5B21D55B0FED22A0ULL, 0xF531C9590F3D298FULL, 0x25599C1C123FFC19ULL, 0x6017E1F2A04FF2B4ULL, 
            0xFCEED8126A438091ULL, 0x15873E26FAB17C49ULL, 0xEC7D722D7EFD67BCULL, 0x9601D1250F6565CBULL, 
            0x8BFF60137459B085ULL, 0x679395D367E43068ULL, 0xFF4E2EEBF3F375A0ULL, 0x8648B9DAA5169116ULL, 
            0x2165D4601E551BC8ULL, 0xC77C43EA715960D9ULL, 0xCE7DB97C3613006DULL, 0xB8C5BF1AC365CCA3ULL, 
            0xE1C373B351A20634ULL, 0xBBEF967F26C98FE7ULL, 0xE56D536164C0B692ULL, 0x9361BF14329DCED2ULL
        },
        {
            0x2B2629C8D6E68455ULL, 0xF349C40B6AA5258BULL, 0xF0A99398C7ABE00CULL, 0xE7347086DD1DF866ULL, 
            0xDD11B589184FC606ULL, 0x59A7FC0F1B01DA63ULL, 0x8F5DEA125883DF71ULL, 0xBF620065607DDE2DULL, 
            0x683C23461729E4E7ULL, 0x8D6D9394DBE6F659ULL, 0xF9081533233C428BULL, 0xE9C2EDB13AE55159ULL, 
            0x6AE9D3790024BED6ULL, 0xD2CC842D773F076AULL, 0xFED2A8D18282157BULL, 0x4C48FE843ACFD5A7ULL, 
            0x7ABC185182C97562ULL, 0xDD700D747E02D3C3ULL, 0x7DF20673A19F5007ULL, 0x1A4430EF30AC9849ULL, 
            0xDF8B6B3DB62BFFFAULL, 0xDF3568E0BF4D9B5FULL, 0x19F4EC1C9ACA4B44ULL, 0xF3CBE4121A3A67ADULL, 
            0x18E93135C87EDC9BULL, 0x8EDE28F13E1D23C9ULL, 0xECD688076D82C8A3ULL, 0x65C5D4710E858161ULL, 
            0x5902F371731A9E5FULL, 0xB367F5C0EF772F3FULL, 0xD7BD7F526BC1F1EFULL, 0x2DC446648D19A34CULL
        },
        {
            0x1A5202ED329D3B8DULL, 0xD631AFC58EE1E6F4ULL, 0xB892906F32E6648EULL, 0x1362D951BB0E6CE8ULL, 
            0x51A982B2EE6A2BA3ULL, 0xA2124632E8A51474ULL, 0x130ED951A6018830ULL, 0x1467F97E2F982D8DULL, 
            0x450983063D5205EBULL, 0xD1E90557E60C7F13ULL, 0x664383AFEA73B60EULL, 0x5585936BD35E4911ULL, 
            0x457D22322C2C863EULL, 0x5708898806E13AE4ULL, 0x15EE84DC9D39DDAFULL, 0x8643DF0FFAE792DAULL, 
            0xBC9FC443242EE515ULL, 0xB18114F7FB88E1E3ULL, 0x044CA59E5D60839BULL, 0xD1337D00B07E4D87ULL, 
            0xA1E61FCDD572DB5BULL, 0x64A4133CCF0C941CULL, 0xDC3A95302C7B379CULL, 0x2198F86EF1CD9199ULL, 
            0x7F309A0B466D1EDCULL, 0xA51D0777973E268CULL, 0xA360A2AE337D01FAULL, 0x9F91958B0D7DB8D3ULL, 
            0xF932E9C03BD7B7F0ULL, 0x4B9AE12203200A2BULL, 0x7EA445F35A23E982ULL, 0x6AF225B037F5F310ULL
        }
    },
    {
        {
            0x8078BA4CFA5C719CULL, 0xBC5CBE5E5843CB02ULL, 0x11FB11DB0285D8D4ULL, 0x721B253B4AF4DCA8ULL, 
            0xA85DE7E50F146723ULL, 0xA5E4DF7ED277B68DULL, 0x0AFF346E8398E313ULL, 0x0CE248903C1EDDBDULL, 
            0x6ED4649425206378ULL, 0x7FCDC44D05CB5425ULL, 0xA0437A483D695234ULL, 0x03B3C481544F736BULL, 
            0xCC770E409461AA6EULL, 0x84D2D5CD30365325ULL, 0x87063A3D5920849FULL, 0x334331128A7889C5ULL, 
            0x775C2A38ABAFB9B9ULL, 0x51526932883D697BULL, 0x6F747039215E138BULL, 0x0C7CF82D0CA7F39CULL, 
            0x7775AFCD5AC99E53ULL, 0x74C0AF39164771F3ULL, 0x809C02B43D37961BULL, 0x6B36D9DC3694E07AULL, 
            0x346508D605E19924ULL, 0x591FFB9C8ACEFDD1ULL, 0xF002AB0D0344CA89ULL, 0xD901AD9AAD4D19ACULL, 
            0xAA1666A2E444BCECULL, 0x9221D925A2DC604DULL, 0xAD638D62B9437785ULL, 0x0E4D4C8723515A08ULL
        },
        {
            0x6386EDAC36128C06ULL, 0x1CCCEA2252FED4E1ULL, 0x6469284011B313D7ULL, 0xB8D394626DE20E99ULL, 
            0xDC6302EF25E02708ULL, 0x666B3820E5842253ULL, 0x8A13127C6E5A7BF3ULL, 0x9933B495A2A7A0B2ULL, 
            0xB9B48833A15339AFULL, 0x88E5025314AC3E1EULL, 0x969C9B58250C8924ULL, 0xA199629C7C74E63EULL, 
            0x0DFEBBF0820C1E8CULL, 0x61E024003A4D225EULL, 0xEB161F5E6812CFB2ULL, 0x35C41B44DE731253ULL, 
            0xFCF31BE235270CF4ULL, 0x4BA647D4C56CCF02ULL, 0x47C781A8968B493AULL, 0xAE6C95D32EE880C1ULL, 
            0x03834C9994410F65ULL, 0xC6BC9C5113B4F076ULL, 0x63F19B0E852C55A0ULL, 0x5C4950DA49C16FD4ULL, 
            0xB564D5991CF31D29ULL, 0x1558AED8E25358DAULL, 0x65457742DF5F0E81ULL, 0x8A38C23EDF03DA79ULL, 
            0x5F29F1A03FD68A45ULL, 0x316D1B521509B9D7ULL, 0x84EBFEC3400DAE7CULL, 0xE71DB7BBA234EC0CULL
        },
        {
            0x9530B8BFC2D07C06ULL, 0x231356F36973D390ULL, 0x4AA5B9595123CE49ULL, 0xD296AF70155CEAF6ULL, 
            0x726D00A78C0D3DA9ULL, 0x6762D19184F69257ULL, 0xA7EF0A278DF18FA8ULL, 0xC2A2E0FF9B6D9737ULL, 
            0xAB6D8EBFA07618A8ULL, 0x65FB254AB6C43B75ULL, 0xC34FA5A99A80D0FFULL, 0x6107AE64F5686385ULL, 
            0x166CBDF56430466EULL, 0xD26F7C1B14070971ULL, 0x46544A73E6580AC9ULL, 0x31AB1151D20B7E45ULL, 
            0x5028D43B4B3CEF76ULL, 0xC093B6B8397851B9ULL, 0xA053952C2BA3ABECULL, 0x2A1449B04BB27DDEULL, 
            0xB3E9F5EC0E874BDEULL, 0xCAE1B71D8FF28E2FULL, 0x1D3280E4D96811AAULL, 0x6D47AB70F3B0E20BULL, 
            0x72B8A9FBA87FBD47ULL, 0x2ED0AEB875B754F1ULL, 0xE48AFA0F48444460ULL, 0x42665FAC0BE1F272ULL, 
            0x74ACA6B0DA291533ULL, 0xEC82ED840BFB7370ULL, 0x45A813587E290406ULL, 0x798B06E61E5417AFULL
        },
        {
            0x23CE9FED18C17E5BULL, 0xDDD7D9028A8AD5F2ULL, 0xAC78626BE6B85FC6ULL, 0xAE86E89B709745B4ULL, 
            0xDF5DDA5061470B49ULL, 0x114FC3FE878D4CC6ULL, 0xC7549E7D61DE6A10ULL, 0x5A1993BB4166D31AULL, 
            0xE970BFE80CEDB734ULL, 0xE0804846FA70796DULL, 0xEBCACF313E572365ULL, 0x976697752690AE47ULL, 
            0x0B035AFAE7780596ULL, 0x1CAACB487E1C8F78ULL, 0xD455034DC8AAFAC7ULL, 0x6C50A9BA11097D91ULL, 
            0x9BC49E1BD5AD7245ULL, 0x2ECBFFD554896002ULL, 0x23A66C0BF6476967ULL, 0xBFC83619F4FBBD07ULL, 
            0x5F61894A42A22E31ULL, 0x74C864F68465D05FULL, 0x4B6041B118FD6065ULL, 0x2FBFD6C610584185ULL, 
            0xCD21F5C57D2946F9ULL, 0x64A9CFCC50A3274EULL, 0x89A9FA9755C14791ULL, 0x0F49D2ABE5FF698DULL, 
            0x43602E48A1E18C53ULL, 0xB7A5E7BE1D0C2667ULL, 0xDDD99D1751B7A7ECULL, 0x45BC244DFC2D55D1ULL
        },
        {
            0x25AFB959C06B021FULL, 0x649C62C7153B757FULL, 0x5FD605A267D783A2ULL, 0xE630E129FF181C5EULL, 
            0x0AE5C7A58E598471ULL, 0x9DD6FA791DF7BB54ULL, 0x7C225D3D0AAA9709ULL, 0xB48573556DB7B569ULL, 
            0xEDDDDB6C1F32B54AULL, 0x274350B14AEEE772ULL, 0xFAE057C1D635E478ULL, 0xBF1461A41DF80DCFULL, 
            0x3426C5C2A79DB3A8ULL, 0xFA92D31DAE96BDB9ULL, 0xB2F458E050676917ULL, 0x50E7EBDAD531730EULL, 
            0x0BCB40356C0DF024ULL, 0x302CDCD7E89AD287ULL, 0x454039991E6F1A63ULL, 0x531FCA7820542D78ULL, 
            0xAE5A6545BDB13FEEULL, 0x4B5594FA48718EFEULL, 0xEDEA251AE15318F3ULL, 0xC23E518B48314A6EULL, 
            0xE85678A7ACEA3CA8ULL, 0x7D8F20BA4F41689DULL, 0xD351DD112775F231ULL, 0xEBDE558491A701C6ULL, 
            0xE4046808A0AAEB1CULL, 0xC258D28C3BB3549EULL, 0x4865293B156E8316ULL, 0x698AF216E43AB9C0ULL
        },
        {
            0x851AE406A4720F3FULL, 0xB611364234CB184CULL, 0xE5C0931CAFE51160ULL, 0xE33E340041D64058ULL, 
            0xA4D3B45B3995853EULL, 0xFBA5F260AF751894ULL, 0x98971220FD6A6C28ULL, 0xC0B7617E392E223AULL, 
            0x15FBB74912223F3BULL, 0xD28F4A2EA31995D0ULL, 0x5C3FEC9D8567B1BBULL, 0x45BF0412924A7AC5ULL, 
            0xE3DB4819B8BC675CULL, 0x2524F3C1474C593BULL, 0xBB06557BF157E17CULL, 0x4223F78F5A60D997ULL, 
            0x04CD64FEE6CB789AULL, 0x88466C07B0654CC9ULL, 0x5B3DF44CF41312A3ULL, 0xC8445734016F484DULL, 
            0xACC0743D67B99C02ULL, 0xADDA8746582942BBULL, 0x30761856E619FA93ULL, 0x5E0BAE9F2C242078ULL, 
            0x6BDED49CF4EE881BULL, 0x23D675D04166480BULL, 0x1EFC1788D05D2038ULL, 0xB481A5DC0EF0FF3DULL, 
            0x4850F3BC5380AEAEULL, 0x03A2258FE1AA6E10ULL, 0x4285BAB1EC37BF5DULL, 0xF9866D1C18ECB3BDULL
        }
    }
};

const TwistDomainConstants TwistExpander_FootBall::kPhaseHConstants = {
    0xD925B3B34B07A9D4ULL,
    0xE7922CDF3CC4C903ULL,
    0x4B2496B076DA2F07ULL,
    0xD925B3B34B07A9D4ULL,
    0xE7922CDF3CC4C903ULL,
    0x4B2496B076DA2F07ULL,
    0x196DCA40C181CD51ULL,
    0x2D5749F81DE2FE17ULL,
    0x14,
    0x24,
    0xF8,
    0xA4,
    0x9A,
    0x3B,
    0x18,
    0x4F
};

