#include "TwistExpander_PickleBall.hpp"
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

TwistExpander_PickleBall::TwistExpander_PickleBall()
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

void TwistExpander_PickleBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 18092191925639014952U;
        aCarry = 11272262647295871127U;
        aWandererA = 12888217152689344367U;
        aWandererB = 12577645856611303711U;
        aWandererC = 17480075387608008149U;
        aWandererD = 11728892140498035404U;
        aWandererE = 14685045168454953570U;
        aWandererF = 15765404586713137000U;
        aWandererG = 12436472305961995653U;
        aWandererH = 9422356685592053180U;
        aWandererI = 11107470113022399745U;
        aWandererJ = 16500490902449113279U;
        aWandererK = 14306170504728665843U;
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
    TwistExpander_PickleBall_Arx aArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_BArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_CArx;
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
    TwistExpander_PickleBall_Arx aKDF_A_DArx;
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

void TwistExpander_PickleBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16382655534796488421U;
        aCarry = 11987523946817067553U;
        aWandererA = 10464721749512005966U;
        aWandererB = 16865055340785770970U;
        aWandererC = 14426607731139453029U;
        aWandererD = 14376043511471038997U;
        aWandererE = 16923932566303793641U;
        aWandererF = 15110842271388837163U;
        aWandererG = 11611824553007974390U;
        aWandererH = 11050349349853604540U;
        aWandererI = 12061646745297431212U;
        aWandererJ = 11157300772987073774U;
        aWandererK = 16954779574523172779U;
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
    TwistExpander_PickleBall_Arx aKDF_B_AArx;
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
    TwistExpander_PickleBall_Arx aKDF_B_BArx;
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
    TwistExpander_PickleBall_Arx aKDF_B_CArx;
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

void TwistExpander_PickleBall::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneG);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    TwistExpander_PickleBall_Arx aSeed_AArx;
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
    TwistExpander_PickleBall_Arx aSeed_BArx;
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
    TwistExpander_PickleBall_Arx aSeed_CArx;
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
    TwistExpander_PickleBall_Arx aSeed_DArx;
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
    TwistExpander_PickleBall_Arx aSeed_EArx;
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
    TwistExpander_PickleBall_Arx aSeed_FArx;
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
    TwistExpander_PickleBall_Arx aSeed_GArx;
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
    TwistExpander_PickleBall_Arx aGrow_AArx;
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
    TwistExpander_PickleBall_Arx aGrow_BArx;
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

void TwistExpander_PickleBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_PickleBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 9934831430852643226U;
        aCarry = 13403490061641476357U;
        aWandererA = 15422397819639251607U;
        aWandererB = 16889832877132182819U;
        aWandererC = 15004107236411825889U;
        aWandererD = 17492078371379860285U;
        aWandererE = 15284456095288404366U;
        aWandererF = 14169045818121138963U;
        aWandererG = 10896814356453408660U;
        aWandererH = 13634018848459269611U;
        aWandererI = 12422186368546137174U;
        aWandererJ = 16319860007996124549U;
        aWandererK = 14984417392020855490U;
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
    TwistExpander_PickleBall_Arx aTwist_AArx;
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
    TwistExpander_PickleBall_Arx aTwist_BArx;
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
    TwistExpander_PickleBall_Arx aTwist_CArx;
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
    TwistExpander_PickleBall_Arx aTwist_DArx;
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
        TwistExpander_PickleBall_Arx aGrow_AArx;
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
        TwistExpander_PickleBall_Arx aGrow_BArx;
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

void TwistExpander_PickleBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 2, 1, 1, 3 with offsets 51U, 7864U, 7463U, 2434U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 51U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7864U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7463U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2434U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 2, 1 with offsets 5358U, 842U, 7712U, 3014U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5358U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 842U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7712U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3014U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 0, 0 with offsets 7056U, 340U, 7781U, 5562U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7056U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7781U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5562U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 2 with offsets 3425U, 7796U, 3644U, 2874U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3425U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7796U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3644U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2874U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 with offsets 873U, 1824U, 779U, 352U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 873U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1824U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 779U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 352U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 2, 0 with offsets 784U, 1721U, 1854U, 1658U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 784U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1721U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1854U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1658U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 2, 0 with offsets 1498U, 1041U, 930U, 240U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1041U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 930U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 0, 3 with offsets 150U, 340U, 1507U, 1403U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1507U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1403U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 729U, 327U, 1016U, 1989U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 729U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 327U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1016U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1989U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_PickleBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 0, 1 with offsets 3488U, 876U, 7990U, 8189U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3488U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 876U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7990U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8189U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 2 with offsets 2988U, 3496U, 7695U, 3418U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2988U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3496U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7695U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3418U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 3, 0 with offsets 6786U, 987U, 2302U, 7020U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6786U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 987U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2302U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7020U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 3 with offsets 7421U, 2835U, 7906U, 3472U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7421U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2835U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7906U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3472U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1644U, 6196U, 4304U, 1317U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1644U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6196U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4304U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1317U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 676U, 1699U, 906U, 647U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 676U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1699U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 906U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 647U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 620U, 889U, 1640U, 18U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 620U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 889U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1640U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 18U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1738U, 1836U, 598U, 348U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1738U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1836U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 598U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 348U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1982U, 306U, 1303U, 72U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1982U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 306U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1303U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 72U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 [0..<W_KEY]
        // offsets: 1569U, 1986U, 421U, 1133U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1569U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1986U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1133U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseASalts = {
    {
        {
            0x8BC5F06692943568ULL, 0x47BEDB9424E3F51FULL, 0x01CD1616DFF46613ULL, 0xF0A70B57A9423E18ULL, 
            0x6A85C2FF5AAF3018ULL, 0x8F7514102D5EDEA0ULL, 0xD3729FE4B0BA8EE7ULL, 0x7A7D2B1A1566BE96ULL, 
            0x44857C89E69D07E1ULL, 0x5E82C0010BFD3D1FULL, 0x4957F6A2BA47DBFBULL, 0x409ECFE0A4F02B8FULL, 
            0xE49FFAEFDA73E519ULL, 0x273B940E784684F8ULL, 0x3EB10B9E8C31C5F4ULL, 0x396B7FE53C8C8847ULL, 
            0xE9BD0E0E009006F3ULL, 0x35ED7426EBD164DAULL, 0x46940D970B762B7AULL, 0x86486A43225AFC0DULL, 
            0x86BD3CEBB55A87A9ULL, 0x9A7271E6741A8CCBULL, 0x070095B62628901EULL, 0xC854D0B361430ECEULL, 
            0x7CEE6291B621A157ULL, 0x2BBF809D95BF61D4ULL, 0xD892BBC9F146A0A0ULL, 0xC069EC742A0FFD3EULL, 
            0x31B684D732BCC72AULL, 0x921AFBB9F3699177ULL, 0x988C7C45AC3D23B2ULL, 0x0662B0F21F4D01D4ULL
        },
        {
            0x27F1C34F3355BD12ULL, 0x55BADC12F8379991ULL, 0x880F43C2D1A221F8ULL, 0x998084B8F20ABAFDULL, 
            0xE4022D890BC1451AULL, 0xCD076F160365BD4BULL, 0xFC10AD07A1AE9E6BULL, 0x75626CD0BCB9DCD3ULL, 
            0x8D037B494E082C40ULL, 0xCCF53DD1229EEE68ULL, 0x55D44B68A392C2E2ULL, 0xC55FF9C299F9D12CULL, 
            0xFA9B57A38E9E2B4CULL, 0x20008B664AFCAF6DULL, 0x97284CBD494EB097ULL, 0x0BA781B956664E06ULL, 
            0xF0764C68A1651BDDULL, 0x2E3E53EE72266A77ULL, 0x8D1089028A5CF234ULL, 0x9DF2740B9F4BBA60ULL, 
            0x9BC2DAE812C6F88AULL, 0xFDB4036BF2F4694BULL, 0xFF3EB556D16F1665ULL, 0xAA393F081FFD00BEULL, 
            0xDE65FCF8953D4C76ULL, 0xCC0E6C2F62AEA147ULL, 0x482D28F0B185624BULL, 0x06F1FF15CBDEF7B1ULL, 
            0x2FA844425D719B1EULL, 0x9CACFC862C7F84B8ULL, 0xA409CD53584407A5ULL, 0x26CCA0BA69F37AEBULL
        },
        {
            0x8697AE73B1C3CF22ULL, 0xBBD0B125FDDDC2D3ULL, 0xD499766CF43945FEULL, 0x629B4B19E301306FULL, 
            0x55B0ADF0AE3377DBULL, 0x305ECA034BDF5913ULL, 0xC204FACEB9D49813ULL, 0x0B5F3BEA3A1C544FULL, 
            0x64042BAB5ECA7381ULL, 0x5DB44FA185B462B6ULL, 0xA78D70A77C003732ULL, 0x2412421E790C3E1CULL, 
            0xE952BF7F94AA7E8EULL, 0xF85EB2181E9DE504ULL, 0x4264496176E3B3E0ULL, 0x10091662C9B3DC75ULL, 
            0x92FC625A13E34D8AULL, 0x6B3172608A958013ULL, 0x961D0CC155B77F47ULL, 0xC01524C54A9AFE86ULL, 
            0x4281B8F976D83234ULL, 0x67650368F3BE750DULL, 0xE8B4718B71EBB0DBULL, 0x0B5F010845FB7630ULL, 
            0x430CB35DE88E62DBULL, 0x8DABF20305886BB2ULL, 0x4A39DCD52233F664ULL, 0xA591A56D58E3AECEULL, 
            0xA7E9245C7F418C68ULL, 0xD8CE84FE148A45BAULL, 0x196BD12196D7862CULL, 0x2B8A6EF9D014324DULL
        },
        {
            0x1D310E43723229AAULL, 0xBE742B9190CB2BF3ULL, 0x34D0A764430EEA7DULL, 0xA83EDF58D48B8968ULL, 
            0x5F9457271962C4A4ULL, 0xCC43B8AF21741A9AULL, 0x9F6D88BF6743578FULL, 0xF67ADA5F01206EBAULL, 
            0xF857416E3ACE69B5ULL, 0x9095760D6BCB9EE9ULL, 0xFF2A125366E7AA3EULL, 0x58B20A8F2C0B29B7ULL, 
            0x76CF44AED0BF0C7AULL, 0xBC3D2905EF835DB5ULL, 0xBD4D2924F53EEE37ULL, 0x6CEE2AB248CD3864ULL, 
            0x015EA525B20610CAULL, 0xC6B2CC7C0E60AC64ULL, 0x5FCD772D7AE51765ULL, 0x1FBC1309E90C8BF2ULL, 
            0xBA2971C21E90BC8AULL, 0x61298EBCB99459BEULL, 0x36BFA2C6FE1CF4F8ULL, 0xD030DC2B87AE2BE2ULL, 
            0x9BFE36B7F2E40849ULL, 0x5CA5AC01F402D568ULL, 0xFE4E1B0A4FF61C41ULL, 0xD5E7E7B1D623FE92ULL, 
            0xAAB6B3962F14772AULL, 0x7F5424C39FC942C6ULL, 0x575E64B1383B44EEULL, 0x3B1465B3D297864AULL
        },
        {
            0x39D392166BA92657ULL, 0x9DC05263E2C6D021ULL, 0xCF3781254D2B4C4CULL, 0xF8899C5594D8F4EAULL, 
            0x93134851F5B393A3ULL, 0x89BAEE19BF582386ULL, 0xFB4A4CE47C6F0290ULL, 0x09B7D514E66F81A5ULL, 
            0x2CF8884FC02F479DULL, 0x46C9F4E09A4CCCA4ULL, 0x215CEB35D855B310ULL, 0x03FC7EFDA2B9EFCFULL, 
            0x2E6F203B820437DCULL, 0x0D09300D9DD19350ULL, 0x6C8FAE88BAE8A3CCULL, 0xE4D79C38D565A2A1ULL, 
            0x212BD85AF962742DULL, 0x5B5E6C7DEB6CB13DULL, 0xB797F259DE9BFBDFULL, 0xFF590726368F1C1AULL, 
            0x5A9260FB78BF5FF3ULL, 0xC08CECF3C330714DULL, 0x3F2556AEC3AB8C9FULL, 0x95BB109B5FB1B7F6ULL, 
            0x28F9752A1501A55BULL, 0x89B5E6EE2C0134ABULL, 0xD24CD11BEBA6758CULL, 0x1183FC486F58ABBFULL, 
            0xD204F73FD15AB1FDULL, 0x45329BB8ADA0F773ULL, 0xA61C08B9086EDE12ULL, 0x92BFE480E7E4C054ULL
        },
        {
            0xCFB909B81FD4E9BAULL, 0x4CD87879357C95B6ULL, 0x2843BD648A8FD961ULL, 0x1EC2B859E28ACED2ULL, 
            0x129E2C31EB506F5BULL, 0x184A5EAD3F9FA312ULL, 0x7E74D94D87CFF032ULL, 0x945A230F7004946EULL, 
            0xFFCB5F4EE1EA2405ULL, 0xF72D9CF876C2390FULL, 0xD08B492E4EFAA710ULL, 0x02E80B54049485E3ULL, 
            0xEF42CB985185440DULL, 0x3FD2938D1701D5E1ULL, 0x719BA1AAECAE07C2ULL, 0x7A95C2899FB0C28AULL, 
            0x34563E408D5C0A7DULL, 0x48444B6608FE7650ULL, 0x4B3A7B89F065B2ADULL, 0x8B674398BD5B39B1ULL, 
            0xE999E8B118BE73C9ULL, 0x7CF0EE6281741D0AULL, 0x05FE3CDD8BF73C84ULL, 0x127466319BD8E945ULL, 
            0x2BE73AFE344BD52AULL, 0x8A792ABBB8F10B87ULL, 0x331CF0CA5667A847ULL, 0x99F9A9A55C9D4DC0ULL, 
            0x223FE86EF6FA1BB1ULL, 0x5A20CF0AFC9090F1ULL, 0x7E43CCBDBF018F8AULL, 0x248647FB56C9B6BBULL
        }
    },
    {
        {
            0x466CC0D22C2F2618ULL, 0xEFAE4B27C8422906ULL, 0x3E44E8091C90EE49ULL, 0x8D0DF662C0C7ECA6ULL, 
            0x72520FD169666D4AULL, 0x9020B99853A6B287ULL, 0xFA961C19A6AE8127ULL, 0x910B2BD2A8D0754DULL, 
            0xE0DF0F352019A142ULL, 0x4B2A046E3C191426ULL, 0x25565425A0CAF864ULL, 0xA995904A5C6F4027ULL, 
            0x38F333FEDAB719D9ULL, 0x65475D9F9C145451ULL, 0x33175AB7154BD537ULL, 0x6339E3120F3A6976ULL, 
            0xC484A73DB4E79853ULL, 0x7668A7BABBD131B5ULL, 0x47FB4D108D3BB125ULL, 0x5E88A0DD1B538C92ULL, 
            0x48C7BB7AF1732ADBULL, 0xA0A3471925127D82ULL, 0x8CE9559BE9ED0BBDULL, 0x46597825F6144968ULL, 
            0xB85453ACAD0E522FULL, 0xCF5A16B2150CD08EULL, 0xC442812DAD6E4D10ULL, 0x2511EF470D5275B9ULL, 
            0x439FEACC0D484707ULL, 0xDC5A0250EF9767D5ULL, 0x4924421C44963BD1ULL, 0x2F825CB96AE2A1BBULL
        },
        {
            0x63173F81C57A433EULL, 0x9F0BA446C6C04C16ULL, 0x726E51F60F06C56EULL, 0xE5797FDA33534985ULL, 
            0xA2135CB8584C01F2ULL, 0x55DBED2F9DB09AFEULL, 0x002E7E236573BCDAULL, 0xD47E06D590974A41ULL, 
            0x934AEED35F69A3B7ULL, 0x8734849EA884278AULL, 0x7D827E53B06F196BULL, 0x775D1CF1F32273EFULL, 
            0xB0D442E4B9F96171ULL, 0x6CB252A5BD802F1CULL, 0x0960C87B0A9BEED4ULL, 0x4E0B7F7FABC2120CULL, 
            0xEB92864157CA4992ULL, 0xA958026FF0C3DEC1ULL, 0x3CC9BABA7B812433ULL, 0x1BADFB1F8B662358ULL, 
            0x6005E3C8BAD2F580ULL, 0x194160307C0BD99EULL, 0x885E9B6AC2166BF5ULL, 0xB5E98862BEE8611EULL, 
            0xB363E66AD5FDFDF0ULL, 0x7B53A9189C129B80ULL, 0x87740F96E8E248E2ULL, 0xAE1EDA4BF6C12AB5ULL, 
            0xF500B450E100B404ULL, 0x57654A853A9417B7ULL, 0x5A40752D8D4D6161ULL, 0x17496D73381A5504ULL
        },
        {
            0xF6606950ED9ABFEFULL, 0xF59D3E8F34A3AEA3ULL, 0xE241A06B3A8F0DB2ULL, 0xEDEC7BDA53311419ULL, 
            0xE9DC02716A908699ULL, 0xE28CC4AA31A9006BULL, 0xD8F82403A3842E55ULL, 0x4DC45ABBBEB876FAULL, 
            0x8CCC71D936E638EEULL, 0xDD478A22282B4F82ULL, 0xF990CEF66F31972DULL, 0x44BACCDF356A6B34ULL, 
            0xC450A49A554F7E7DULL, 0x4BC08B7C6964C297ULL, 0x99EB7DB5556E48DCULL, 0x96359B74E6DB5605ULL, 
            0xD0802B6E4C544BA2ULL, 0xFA3476040AC6A4B0ULL, 0x781C30F9DD85EEFEULL, 0x701457B00764FBF1ULL, 
            0xD53EC0B0E0E455EBULL, 0xAD0D8C8CF668A119ULL, 0x174A45F416BD5669ULL, 0x773D989969229800ULL, 
            0xA32E598DFBEE4BFAULL, 0x106CB5E92EADF7A8ULL, 0xA869FD60B250F7EFULL, 0x2B53545DE7A1F93CULL, 
            0x2A60C03751D8DACFULL, 0x440D018F8C5C433DULL, 0x0B238776C54195CAULL, 0x10EA0C1871CE1976ULL
        },
        {
            0x548E0FA30EF9BA6EULL, 0xF0A7164BB6624648ULL, 0xF7B0A0DB8714ED73ULL, 0x9ECB25D77AE43024ULL, 
            0x90BCA00470486986ULL, 0x6B91198126B00930ULL, 0x50DE7603ADFDDDDEULL, 0xA7EA45E4FACC69D6ULL, 
            0xB115652DD22D15D1ULL, 0x02FC78F21FD443D8ULL, 0x86113600D3D31FA0ULL, 0xE8F3462DC1D402BEULL, 
            0x59B0D4257F2F375BULL, 0x63ED2BD63CEA6639ULL, 0x478D0E3F0494BDB1ULL, 0x3C93AB3D38DA151AULL, 
            0x6626F5ADD6634482ULL, 0x414D68FC4089C5E7ULL, 0x6E2E90DF670174F9ULL, 0xC19DECBCD7E58D3FULL, 
            0x093325A055D048E0ULL, 0x7D4F930DAEDBA375ULL, 0x8D2D3CB287CB396DULL, 0x8BD7B610F048E815ULL, 
            0x5BFEC60A80AD0EE7ULL, 0xA586E22DC50E148EULL, 0xC668F7205A57D06BULL, 0x23B35B56D92FAD84ULL, 
            0x3E9CC27AD1921E4FULL, 0x28D2E01EFB1DDD9CULL, 0xF670CB64A81DA171ULL, 0x82ACB00C5FAD35A7ULL
        },
        {
            0x7B7E9E4E48FB87EFULL, 0x4CEEBC419EA5DF08ULL, 0xBEEE3E77D6F36E97ULL, 0x68C526CEF85B0B3AULL, 
            0x08F93541A2B02E6FULL, 0xE067C79448863265ULL, 0x646377664D7ECE28ULL, 0xE36C8D3F9D5A0775ULL, 
            0x983C4985F0D467E5ULL, 0x540EB04302DEB0D8ULL, 0xA59BD522746E346EULL, 0x4138F3C40CD4B4D1ULL, 
            0x48D1F3064E03160EULL, 0xFD701A8AD5F40874ULL, 0xCD4D0134E718C119ULL, 0x1C5E6D92B252523BULL, 
            0x0C77A50DEEA9CCE7ULL, 0x7D638B2777BF7636ULL, 0x1E6F6CE7B07E9657ULL, 0xA488DF0900C04666ULL, 
            0xA7BADA8DFC84D119ULL, 0x26CAF247D73AF021ULL, 0x3DE4FFEDDDF459D0ULL, 0x798595177FB6C490ULL, 
            0x9E43FBCA7A7119F0ULL, 0xAAA2B9BBD5363976ULL, 0x62F7454C5E09B56CULL, 0x761E4594D4D69039ULL, 
            0x9224210FCBD936A5ULL, 0x6D073768A4BCB44EULL, 0x35B8CE862EF437C4ULL, 0xF55CC741FC695B6BULL
        },
        {
            0xC84789DC0B755CFFULL, 0x3536AAFB4151A4D3ULL, 0x54A109A6D66392F5ULL, 0x1AB4CA7630E5D572ULL, 
            0x26A027BAAFC907E8ULL, 0x909A5695550A32FBULL, 0x07BE40D585E8F56CULL, 0xA0E1554C304B1123ULL, 
            0xFD22BDEEE01EA8B0ULL, 0x06E93865F4631F3EULL, 0xDF4BF3F02F6D5BFCULL, 0x64393AF2F3A88EABULL, 
            0x99C9CF5EB9F05E5FULL, 0x9B80849B46F104B5ULL, 0xE0C35BB83B70E03AULL, 0x4C50298077DBF1A4ULL, 
            0x605BA8A44B280719ULL, 0x105D15B3ACC94A50ULL, 0x03B1C0AECC67B5CEULL, 0xA2BA6BF3EF98AF0DULL, 
            0xDBCE425319B55C7BULL, 0x942B28E199C88B94ULL, 0x6953CFC4C901450CULL, 0x34B0ED02E847FCDBULL, 
            0xA80859812FC179D4ULL, 0xF585D4721DAD5D82ULL, 0x31A1502A8FC60BB2ULL, 0xF58769DC0F707A02ULL, 
            0x35800C5BC88E968EULL, 0xDB72913122466AB4ULL, 0x4160A5C39D135FC5ULL, 0xB71374110B127A01ULL
        }
    },
    {
        {
            0x5978BB4F1A5D24BCULL, 0x1A87CB85E082690DULL, 0x0FCBC558B8091D98ULL, 0x57B23858BF39371AULL, 
            0xAFE199E1250C466AULL, 0xBFAA1D567BFDBC1FULL, 0xE8260BB62D66489BULL, 0x6969E6EBB8B66E9EULL, 
            0x0CD587384AF93F5BULL, 0x2DAEDC69E48D4462ULL, 0xB5296DD70FC7E98AULL, 0xFF4420D3CC0067FCULL, 
            0x49BF5CE79C1589F3ULL, 0xCB8DDC0F8FC1A627ULL, 0x0F099E3152F52F49ULL, 0xAB727707C96C6C9BULL, 
            0x9E2622B53D2AABC4ULL, 0xD5F47316D223348EULL, 0x30933F67EB2FCA29ULL, 0x77A6749E95947E81ULL, 
            0x98205A7CB3B5C5E2ULL, 0xB3A2CE693214E3E9ULL, 0x7E21B3FD4DC204CCULL, 0xE989471E26A75537ULL, 
            0xC931D42F4425C186ULL, 0x58E5769037981E22ULL, 0xAE48896B9668AC0DULL, 0xABB81AD8F576E142ULL, 
            0x971CD48C0486085EULL, 0x0DC763BC164B6CD3ULL, 0x0921356F5C7516F9ULL, 0xD7FCE5C2502E4A0BULL
        },
        {
            0x6EC9AF8C89C3A617ULL, 0xB199A14B9E8A78C2ULL, 0x8B273CA35CD80CD4ULL, 0x69B98F3CA18C7DF9ULL, 
            0xAC95FA668178731BULL, 0x29753E4994454AF2ULL, 0x85844E9F312192A6ULL, 0xCDEFBC543E90E93DULL, 
            0xDFB0A343A40CD851ULL, 0x6706842E9612CAB5ULL, 0xF99A35EF67625059ULL, 0x72201CA9CC9E1316ULL, 
            0x4D831775DD48D01AULL, 0x6EF93B41F8692867ULL, 0x11695FD677667D43ULL, 0x25EFBBF8095BBC6AULL, 
            0x15A0CDE93342422EULL, 0x29047BF61C4C52E1ULL, 0xC02C85A68143200DULL, 0xE6E86E6870EB2834ULL, 
            0xF1600011A71A4023ULL, 0x9BDB07991F727B30ULL, 0x233019B27A3D816BULL, 0x8E2214196632910BULL, 
            0xAE824EF70C275917ULL, 0x97C81793F9132404ULL, 0xBC6EAB14829CFEDAULL, 0xE90301D8B90891B3ULL, 
            0x4D6C40FECD9D964CULL, 0xE83D0999F11D86CBULL, 0x3F4BC69535BBAEC5ULL, 0x25870EB997A2A9B7ULL
        },
        {
            0x6D0B5011AAA730E6ULL, 0x288ECEBF3651ADB1ULL, 0x69623E9DF79DAA5EULL, 0x92A13FFC26B73082ULL, 
            0x744D9068415CAFBCULL, 0xB56961F91FD5CD15ULL, 0xF4D58D82875F8623ULL, 0xEF5F5ABEBB137F3EULL, 
            0x0C3A3DD2DEB54020ULL, 0x24B4816E9078FEC4ULL, 0x6B2DA1B95C8F4E8CULL, 0x3FDE52BE68C61381ULL, 
            0x0368288796F697F1ULL, 0x847301BDCCBCD601ULL, 0x1D020B0C49B38086ULL, 0x4179B962588A9DD1ULL, 
            0x60778AFF95FA663EULL, 0x14E1D6FEE00A89E5ULL, 0x3155D5565CD1794AULL, 0x5D00B5D4C8640281ULL, 
            0xA0575014036FC147ULL, 0x970D8972E9760DB5ULL, 0x7E96C4D25F2C7C5CULL, 0x4BDD70B6FB26AC31ULL, 
            0x20A168A09650CB80ULL, 0xEFEA02043DF9A86CULL, 0x3A104FF89B6FEC1BULL, 0x4D9A00F0BE1D3612ULL, 
            0xC744C1DA974CF3D6ULL, 0x09BC84F767E6157BULL, 0x43C81087781D1A5CULL, 0x670C0229130D2DA0ULL
        },
        {
            0x4CD7B5BDF96BAAB8ULL, 0xFCBCDE7FBAD397A8ULL, 0x00787FCEFC2B9DC1ULL, 0xF9EBA829698D6B86ULL, 
            0xB9C7718FD8CEC557ULL, 0x913A8C6D69AE9508ULL, 0x02167D62E6755B70ULL, 0x191B22F1EEF05AA7ULL, 
            0xCFD96912B0A236B4ULL, 0x644004FD195DE1B8ULL, 0xB1AE564F8A639011ULL, 0x82E43A77DE695DA7ULL, 
            0x542F7BBB0CC386A4ULL, 0xEE42B4CDC7F21199ULL, 0x0CCD157CE4263243ULL, 0x6F1F332EDAD7AEBAULL, 
            0x17E7D83F4AE43CA1ULL, 0x411FC1FA24839B54ULL, 0xF204DECE8ED8F31CULL, 0x954F54730855BC38ULL, 
            0x54617A7331DF3987ULL, 0x3AB2B37668C7D288ULL, 0x6E486257C62BB98CULL, 0x4716C9376D58B565ULL, 
            0x76096207546FFE3FULL, 0xB33222DFD3E6DE1AULL, 0xAE6434DCAC194464ULL, 0x669B7413BDBFB007ULL, 
            0x656BE82E0476C413ULL, 0xFE4A24D25065F290ULL, 0xE2E499320E767AB0ULL, 0x65960C3F3856824FULL
        },
        {
            0x8F0A83133D50A422ULL, 0xFD4C722EF44862EFULL, 0xE5B7B0F94B48D826ULL, 0x30B7526025FA5822ULL, 
            0x720BE8FF326137C3ULL, 0xCA34CA7B46F53469ULL, 0x0F9A33E10B822417ULL, 0x6758D4D530E4D900ULL, 
            0x55A00EC003FD0187ULL, 0x808A75A7DE468694ULL, 0xEF483B593639972EULL, 0x227D89DF53636034ULL, 
            0xF8BAB49066483F50ULL, 0x5A9846D14393A50CULL, 0xBF6555F275D45ACFULL, 0x94EC2B64ED04898EULL, 
            0xB3B3EE8F5BC39A3BULL, 0xA9B09F7E92ADA484ULL, 0x50DE4283647A8CABULL, 0xCE508018FA9278A4ULL, 
            0x796F71A2C71D9DDEULL, 0x5517740ED8C5900EULL, 0x66B60E71ECA499CBULL, 0x595D4D04937936C0ULL, 
            0x3AD2AA0D273E31EBULL, 0xB372C4D8486D97DDULL, 0x3C5AAF45371C588EULL, 0x24C5A9CDEA79A00AULL, 
            0xCFCB6848A53BA21DULL, 0x30F3ACC48A7BCD20ULL, 0x734A8B67569D7FF2ULL, 0x4E716CC450EEBB2FULL
        },
        {
            0x8E6F15B9436681F7ULL, 0x7F11B8CAFCBA3F34ULL, 0x5A154E05BA799482ULL, 0x23D2BF46D3E8B204ULL, 
            0x4E0F9A63B6E26988ULL, 0x3582E16EEB8780CCULL, 0xCD6D48EFE38DA39BULL, 0x5715E147988CFAC3ULL, 
            0x724B6D379A18D675ULL, 0x8336D723ECAC246FULL, 0xEA73284B38F3E4BEULL, 0xABF96F057E5A6710ULL, 
            0x05B7D20D51F1319BULL, 0xE53C1C1C8ECF138BULL, 0xCC0EE63CA7F3E9B9ULL, 0xE1C27970FBB135D1ULL, 
            0x76AA16F55ECB491EULL, 0xC98F5C26B3B52183ULL, 0xD7017D01C43C4AD3ULL, 0x69B7BFE460C91528ULL, 
            0x9949309CE85A0993ULL, 0xA3E8D08073765E6BULL, 0x8EF71DF6C4576746ULL, 0x8FDAB2B57BDDE536ULL, 
            0x5AB7092F51785077ULL, 0x149D1C2161502E8FULL, 0x4E633A11B740BF35ULL, 0x602D7AD4414C4759ULL, 
            0xBAB813A2A86AA54CULL, 0x217219E051594E7EULL, 0x9ABDE734E62215F9ULL, 0x9DA4888AD8EDC31BULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseAConstants = {
    0x8089B1B03C0A353DULL,
    0x462E411283D851E6ULL,
    0x5F02483E916B6E59ULL,
    0x8089B1B03C0A353DULL,
    0x462E411283D851E6ULL,
    0x5F02483E916B6E59ULL,
    0xE3CB98E0CDF1F788ULL,
    0x48B890EA97CF371EULL,
    0x41,
    0x7B,
    0xAC,
    0xB0,
    0xAB,
    0x25,
    0xE2,
    0x12
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseBSalts = {
    {
        {
            0xC1959C05500EC6ADULL, 0x27EC5E0A9AF514CEULL, 0xBC85101EFA5F086AULL, 0xBF1981E56F571B46ULL, 
            0xEEEEC8FA2F703DB6ULL, 0xAEE2ADD8AA12511DULL, 0xADE0E55E94E229BCULL, 0xB0F960FB08BBFD69ULL, 
            0x435E2F03D0DA7E18ULL, 0xCC3B848F5525024DULL, 0x72546431AD5003F2ULL, 0xC117FD917CC44A9BULL, 
            0xEFF1B4AD905BCF51ULL, 0xC1A4E06D025E0DDAULL, 0xE758F4E62CDDBA2EULL, 0xE28ACBA658AB50ACULL, 
            0x16C67AE58B472632ULL, 0x181912982E241379ULL, 0x960B8C11A430566FULL, 0x3983F6DDB0AFE66AULL, 
            0x207F666DD4665656ULL, 0x22B742190DC9264EULL, 0x642082A63961707DULL, 0xA10CBBAA4EEF3A43ULL, 
            0x258E015008E1E2DDULL, 0xB766DBD8AF3FCE32ULL, 0x5EDC07E1CB00AEFFULL, 0xD799A3ABBBB0AC85ULL, 
            0x50121BDF22CB1ACFULL, 0x15877023811F2DFCULL, 0xD6642FC32368052DULL, 0xE3E92CD1028A7C74ULL
        },
        {
            0xA823A228EE38C7A4ULL, 0x5BE44E915A53C403ULL, 0xA3AACEE110C073CFULL, 0xE0B4C7796385BAF2ULL, 
            0x37E69BCF95F6DCEFULL, 0x30E18542D4EB873BULL, 0xEB231C3D6155CFB7ULL, 0xD4A7A70502654DC6ULL, 
            0xADD47D9E810F1E34ULL, 0xABEC40A4FAE42DF8ULL, 0x8EF85585B5DD6023ULL, 0x42D20727751BED5FULL, 
            0x6236C81ADD8C020CULL, 0x6FD95356CA345B28ULL, 0xF95492C2A103598BULL, 0x7A55E801F64ED18BULL, 
            0x41AABFBC0EED607EULL, 0xD34B74DA26C62688ULL, 0x483728F916E057A2ULL, 0xADB5C494B7B73A11ULL, 
            0xD0BF8E2D9564ECD8ULL, 0xB65A623925D4A3BFULL, 0x0846D87447F77379ULL, 0x80781EF5C161DCAFULL, 
            0x45C73B286C355B1FULL, 0xD3142696CB5D4716ULL, 0x692AA790E17C24FBULL, 0x8D37998BD78D9A55ULL, 
            0x99EA39177651FE6EULL, 0x33AF75E4BDE83E14ULL, 0x219DEAE0FFDF84FFULL, 0x1C1AD8DA1C3A9A69ULL
        },
        {
            0x08B6AB2F1098991EULL, 0x19ADC2750656DC46ULL, 0x59C3ED850427A5FCULL, 0x04E2CEC6EA88034AULL, 
            0xB430667408690ADCULL, 0x4447E29CBEA44A38ULL, 0x82E7E890FEDA64C8ULL, 0xE112771DE9B7263BULL, 
            0x99624FBBA3303798ULL, 0x5B127A0DE9093B08ULL, 0x4F2D1E4C98B31CE8ULL, 0x481144EBAD853CCEULL, 
            0xD66F79543E6FF7F8ULL, 0xDB77B3BFCFDEC30AULL, 0x5B6BE72385AFEC4EULL, 0xF392FB00507A51BEULL, 
            0x0E15F785EE275EE5ULL, 0x45AC0A4EDD4D9C64ULL, 0x1A3B71BCCF88B315ULL, 0xD2FF1E2AA3667ECCULL, 
            0xBD03FE03C3B0FB56ULL, 0xB3EB70233FD51BB4ULL, 0xA5C93672F39E2155ULL, 0x83BA5DC28EEDF747ULL, 
            0x961A317BAAEA4169ULL, 0x6981FE416CD7D43BULL, 0xDE6ADFFD98ECDE8EULL, 0x4E75D24223227FE9ULL, 
            0xB8E09BFF6A90AD0BULL, 0x9E5E9A020E64EB35ULL, 0xC0E1BD235151ED62ULL, 0x5BF7096CE0F312ACULL
        },
        {
            0x2094DD582EE71C95ULL, 0x54CD7A3748EEEC0DULL, 0x5107922780927386ULL, 0x5901AB7510C9FE76ULL, 
            0xE31BE7A8707B8177ULL, 0x579F0DAFF67BD569ULL, 0x44D19A98D18189E8ULL, 0x2C898B61B5428A6CULL, 
            0x12E8AFF1D2E3993EULL, 0x606297D940B446BDULL, 0x719D585490011EBAULL, 0x7B1A458CEDAC9E32ULL, 
            0xAF9D86368B19D931ULL, 0x639B704C5DA63822ULL, 0x51FA614C122918B9ULL, 0x2F2AA8ECAB791D37ULL, 
            0xAF018E871249D360ULL, 0xF677805FEF277E0BULL, 0x5F42EF3446F25EBDULL, 0x6165C9BC98E56D3EULL, 
            0x47CE5972D46EAA52ULL, 0xE389457C03B98820ULL, 0xD99828357A62C40CULL, 0x1777D79C4580EF36ULL, 
            0xBE72A257FF5D3984ULL, 0x783406AC6B0C3A1EULL, 0xD98EC1A01226FFD8ULL, 0x58A4540ECA1C4CA5ULL, 
            0xD938B1AF36E6EA8BULL, 0x4491381B420FB0E3ULL, 0xA14F9A4DB8B603B1ULL, 0xF05DC52379DC1D67ULL
        },
        {
            0x50B49C4390A8D271ULL, 0x438EBDB61775B966ULL, 0x246A60D8FF8AF6D2ULL, 0x9FDDE4029D08D2E4ULL, 
            0x05F36431BCD3DFAFULL, 0x0D39AD820CFA9505ULL, 0xFABD508DA0E8C77DULL, 0x6ACF0068BFDF68CAULL, 
            0x732D79FE7C887D53ULL, 0x83B888F786466F7FULL, 0x896C4C1715A0AE46ULL, 0xAD34473C09C9FB9DULL, 
            0x121967FF4708D8D4ULL, 0x95FEA5027F81F5B9ULL, 0x745A8C618700AF3BULL, 0xBF583689EF986561ULL, 
            0x333786DC0A3498A4ULL, 0xA02441A207EE2E7DULL, 0x24E84FB718DC4016ULL, 0xBDDE16CCC8526461ULL, 
            0xCD4AC7FAF0F487DBULL, 0xF39DAF99CB7E13D2ULL, 0x895B17F336E1BE1AULL, 0xDE859F916659BB59ULL, 
            0xADBA8451DD1C2C3FULL, 0x61E0E1CAE2C2478FULL, 0xBC72733E2F5952E7ULL, 0xF9C39DE580F9CC9FULL, 
            0xC912C2C85B612C6DULL, 0x03E816A7FACCBB95ULL, 0x43C50FFD6CE2F54AULL, 0xEA93CC94A5F6848CULL
        },
        {
            0xFF932A3748B04391ULL, 0x69DB922295330217ULL, 0xA58E42878CE9548EULL, 0x3D24A2D3ED37E7EFULL, 
            0x8D3E8FAEEF442D6AULL, 0x791EBAA807E0481CULL, 0xD58F559CE4F60528ULL, 0xB7E36B31CAC0CFC7ULL, 
            0x301682E3B1430E76ULL, 0x558E8203E693BB6DULL, 0xE524BE8C55BBEC30ULL, 0xEBE64994DB4A9088ULL, 
            0xB28B699857253F9AULL, 0x3B823C619ECC6D9AULL, 0xF68207E6618DE218ULL, 0x70FC6009BDF951BEULL, 
            0x876EB581D819BD40ULL, 0xD0E71BECE6C17842ULL, 0xEA8E50E557A6EC11ULL, 0xCD80AB74548EF68CULL, 
            0x8A5FF329FA24B822ULL, 0xF9BECC3017CBCB6CULL, 0x0DCF390856703CC7ULL, 0x7D56A87A46AF6B15ULL, 
            0x069F0D18449BF6A7ULL, 0x3213908137F7E9F9ULL, 0x96A5C43820268E9EULL, 0x4E34D1482F3D5805ULL, 
            0x1D6BB0382A0D572CULL, 0x7E70E539DE919867ULL, 0x4A92D8681B0DAAC5ULL, 0xE343EB2F63B744E3ULL
        }
    },
    {
        {
            0x92A591FE63B4F05BULL, 0x738256C1C7D85C06ULL, 0xF6B93E28536FE6D6ULL, 0x55FCF6FFFB66E637ULL, 
            0xA57EB6D3CAD9682DULL, 0x468A9F0BFF2AF2D1ULL, 0x0B9FA93D4E681D3AULL, 0xCF4506B50FE84C9EULL, 
            0xDCB3D4E83127FD85ULL, 0x1BD4A88DD0752903ULL, 0x3DAB1EDE4ED1500FULL, 0x879E449BBC56A72BULL, 
            0x89F46B350F17B943ULL, 0xCEA3D0064D53F535ULL, 0x7FD725B44C7A5EEBULL, 0x7A448317F65F4C1CULL, 
            0x715CC821B624F632ULL, 0x04ABA62956CDFC3BULL, 0x0F9E81DE1461CBFEULL, 0xEFAA6B006714EF27ULL, 
            0x4EEA34C7B6BD61B9ULL, 0x030141D746618D68ULL, 0x1F54672DA8E3DEBAULL, 0xD9D2DB44EC6B87B3ULL, 
            0x6F5D4DF004D34F5CULL, 0xFC46643FDA2D061AULL, 0xF8B709DD55536CE4ULL, 0x7D2DC2A88D54B465ULL, 
            0xAFBEC2B01284475AULL, 0x5D1DE2AC30ECBDA9ULL, 0x0A9A8CF6A21C9A90ULL, 0x13A4D63610DB9DF6ULL
        },
        {
            0x605981FD4622D3C4ULL, 0xB8B16C0F6E2515A1ULL, 0x6877BF0F825C1F9AULL, 0xB76AC0DE178660B6ULL, 
            0x519A6C34B8F43025ULL, 0x72E005A5B26EFE20ULL, 0x673C0A573613AB98ULL, 0xD7A8C7292EBC779CULL, 
            0x3C60BB59F847D158ULL, 0x916CC422C6FD72CAULL, 0x3647236D555C6D33ULL, 0xDB2477E7C1340227ULL, 
            0x0BD320A0339B081EULL, 0x25999FA6E248E974ULL, 0xE3B9F024F542B129ULL, 0xFA71E06F51B1CD87ULL, 
            0xE6DF51A5168052B4ULL, 0x17F5999457F8CB21ULL, 0x921F15D112D4809EULL, 0x2676F967D6D5D361ULL, 
            0x870A8BFA54D50E28ULL, 0x596499A7F0EF56C6ULL, 0x5B91BA153DCBEFD4ULL, 0xE0893473E0059216ULL, 
            0xC87C4A79BA675A52ULL, 0xF06CB105087132ACULL, 0xD79798078AABF44FULL, 0xBEBA184169230162ULL, 
            0xB5F09DD81A2CCC37ULL, 0x886835C507B55E40ULL, 0x479A3A8905ADA174ULL, 0x857576F245636A54ULL
        },
        {
            0x51C79E983EE03E10ULL, 0xD49A2289EF8B8F8BULL, 0x11CB2BB9C28C1CB3ULL, 0xE50BA92FF1830844ULL, 
            0x149E87090E831DF9ULL, 0xC14844D635CA49EAULL, 0x72EC496EF410C6BDULL, 0x4E2F337C924260D8ULL, 
            0xBD4E8E7FB74E14F1ULL, 0xFFE32B685766EF56ULL, 0x6EB6BCE0C7189C38ULL, 0x61387F1E26FAFD27ULL, 
            0x3B57BAEBE722E8BDULL, 0xA42C5F99D66B2C64ULL, 0x7CC7340681AA7ECDULL, 0xF71190903A150189ULL, 
            0xB367586362808A5FULL, 0x36CD1BFDCD95C860ULL, 0x60816A83631ED99DULL, 0x9FEEC1B09BE74F84ULL, 
            0xAA117F388253997BULL, 0x5BDE6C7E73FC2BD3ULL, 0x114F8107880CDD32ULL, 0x6891B4C2A40EFCE7ULL, 
            0x6AFD8104F77049D2ULL, 0x91E20FDC09872078ULL, 0xD3628CC8FBFFFACFULL, 0x9EF0BF8EDB1409F4ULL, 
            0xE3AD79236FCC4C3BULL, 0xAFD2C7DB1B5B0A95ULL, 0xCA18F05FE3B1291EULL, 0x940A8ADA46F3C0B5ULL
        },
        {
            0x716015A2C30DEE9BULL, 0x474F71B696F86DC7ULL, 0x0CAA8FA5F286A318ULL, 0xD9C480A38E6869E7ULL, 
            0xF3B326C1B6CCD62DULL, 0xB4450B163037DC96ULL, 0xF6A9839B43E5D60AULL, 0x6B07D13F88A4E633ULL, 
            0x261FFDED7286E246ULL, 0x9D25DBF4F9BC19E2ULL, 0x7DDEF1251E35EF63ULL, 0x9673FECD94795E1FULL, 
            0x90A815FAFD5FF415ULL, 0xDA7C60925F37AE7DULL, 0xFD3A6A233771D407ULL, 0xC0D5C4BD76B174C8ULL, 
            0xCE9C9FD363BD7C3EULL, 0x9940980329C15B0FULL, 0x7A85900C955F1863ULL, 0x538CE52076B79858ULL, 
            0x4D3BD89D343357A5ULL, 0xB0132F3DCE6FD7BCULL, 0x412AACF7208BD044ULL, 0x50732150BB496D80ULL, 
            0x558ADB08D623E6F4ULL, 0x5BF136D11C1FDE6FULL, 0x666A05FCFCCBBE40ULL, 0x2612C099C5C88E4AULL, 
            0xE2088282E5505561ULL, 0x031A57B10A4BC030ULL, 0xC3EBBA5ECB0812BBULL, 0x0AE18D4DE4EE0534ULL
        },
        {
            0xAFA7A6B0278C5751ULL, 0x701F67F8B7FA7914ULL, 0xBE16E4E79DB0C208ULL, 0xEACAACEBBBEC21A9ULL, 
            0x5432E75C19DC0ABEULL, 0xF18B10504225068AULL, 0xF48327A4AE9FBFB7ULL, 0x0734E7927D815F4FULL, 
            0x0297F463639A09B9ULL, 0x47A6826CF7E8C408ULL, 0x2FEC464141AE5E53ULL, 0xE1035BAE08B51916ULL, 
            0xC3F3D4E17687D8EDULL, 0xE2439D6B8D80D548ULL, 0x9B0A9B5D68340C9FULL, 0xE46C5BF989C4336DULL, 
            0x17BBECC5CE08F4D2ULL, 0x15F1B35214BA079AULL, 0xA1A750F9CEE474D2ULL, 0xD91820DA45D6EA0DULL, 
            0xC959BA5D20A1F7EFULL, 0x3E5E34BA4AE5ECB5ULL, 0x3D98F301A4063B93ULL, 0x2B77CA7E987A795EULL, 
            0x4AC514DE154FD82EULL, 0x86536CBDF6C5BE4AULL, 0xEEA2553C8F52567FULL, 0x21EE7E731A7FB36FULL, 
            0x011B3D2237E94AA5ULL, 0x9606787AA7A4E1E9ULL, 0xF5F9F353F4C823DFULL, 0x300662955189BA3DULL
        },
        {
            0xA0FF06F63C9F7A52ULL, 0xBADDEC8259472244ULL, 0x51A6C4FF0366640EULL, 0xE3A13BE820F17E7AULL, 
            0x85441EE218749091ULL, 0x0B140BC964BCD9E0ULL, 0x850E56B9E471183BULL, 0x257D1C270478E4BEULL, 
            0xF4735DBB25E6AF80ULL, 0xA8A74ADC3961953AULL, 0xEA0CE835BC3DF5C1ULL, 0x7EE6740F4B4A2884ULL, 
            0x4B42027FD718079BULL, 0x30D22922D79A7015ULL, 0x0175D6DE3B8B4AB2ULL, 0x0A9443DCC67992A5ULL, 
            0x9A6F05C4D5421BF8ULL, 0xC15F7AB3D7A53CFBULL, 0x7C647369544B4AAFULL, 0x5F1F9DBCFA3721A7ULL, 
            0x2B50DD45EDD5A011ULL, 0x316CF3102B04C169ULL, 0x3E3DF1D1EF4460F2ULL, 0x67AFCEEA74DF84CAULL, 
            0x09CA5421D14E5B12ULL, 0xE752FBB58C0318B4ULL, 0x981A14CCC2D8E796ULL, 0x06DAC814A2E69E0FULL, 
            0x73F346555A7B9C64ULL, 0x04FC7CB4E7A9187FULL, 0xBA2D22D3B5A78774ULL, 0x4F673D04C3C6E20FULL
        }
    },
    {
        {
            0x0799B1B872B5367DULL, 0x25136DE94C2CC915ULL, 0xF0B9370B9D003F6DULL, 0x1A23D3E3BD269D2CULL, 
            0xDD6FAABE5FFE2D81ULL, 0x7D81D2A1983B041DULL, 0x93769B4A87564138ULL, 0x815CE33C2DF87814ULL, 
            0x0EEC51888694F9F7ULL, 0x81979293AB2D8C7CULL, 0x2FF71504DD6A104DULL, 0xECEF27372A893DD2ULL, 
            0xD274F32AA2FDCC33ULL, 0xA7D9A69652CC2E98ULL, 0x4A51EF63B21B1C8CULL, 0xF387E6C5ACD8F967ULL, 
            0x745856250DF5E2D0ULL, 0x2DFAE1C36575B599ULL, 0xBD37D7D711F129FAULL, 0x8053B459DA73BEE6ULL, 
            0x629A979241C7CCC3ULL, 0xD5E1834C0996B5CCULL, 0xB9C64122D74EF1A6ULL, 0xFAF7AA6721E7B4EBULL, 
            0x23D0DF2D5158C234ULL, 0x8572AB8BD04D9D97ULL, 0xF961A6BADF8DF28AULL, 0xCF634C5CC5A40711ULL, 
            0x3F9F7BE22DEAFD0EULL, 0xD40D87C9AA4A78D8ULL, 0x5F82CCA391D025E6ULL, 0x3DED3B1066F1BCBAULL
        },
        {
            0x27D2846A2DA048A5ULL, 0x0685DF8A30F85E18ULL, 0xAE7485072EE27269ULL, 0x38A2787102748056ULL, 
            0x7598994194999AA4ULL, 0xEB46522F4E510881ULL, 0x4734DEE9086B77A8ULL, 0x283244CAA6F14397ULL, 
            0xB3AD5203921D7983ULL, 0x28F69D2B7890FF00ULL, 0xD79ACBA902B9BC65ULL, 0x19289EC889E2E9A2ULL, 
            0x51D7030915EB9D11ULL, 0x1191797B0C13B274ULL, 0xA2ED40DEE2EFC33EULL, 0xADA7EA594A67E015ULL, 
            0xC7110AC70E62D7CDULL, 0xEEC5D3C435DC0EBEULL, 0xCBDB15935A4282F3ULL, 0x79B68746C64FC1A0ULL, 
            0x1A6DC300B4F429CCULL, 0xB8BAF96D3ABC6195ULL, 0xB24EBA28855806B9ULL, 0x90081D79259CE2BDULL, 
            0xEB967902345EF6F3ULL, 0x023D5E7998275BAEULL, 0x7095AAAAFF5D908CULL, 0x694A6CD5699550F5ULL, 
            0xAA10C1BC3D82D3AAULL, 0xF93A9B55B340E861ULL, 0x733A342ABAE23769ULL, 0xE5310A33405CEF30ULL
        },
        {
            0x2E953E36377771EAULL, 0xB05AADF96B975BC4ULL, 0xFBC62A98EF354997ULL, 0x3D29A4903BE5AA6FULL, 
            0xD3A679A1E6A46E42ULL, 0x9A1B212B7AE360B8ULL, 0x427FD7C4AC63D77CULL, 0x9B5DC81CE99610D1ULL, 
            0x2F964F140E34005EULL, 0x2DE2B0C647E26AB5ULL, 0x99E3248AF9A4F78EULL, 0x656B547C996E519CULL, 
            0x865E86CAEF359DDBULL, 0x67AD79251DEA20AAULL, 0x6AFEBB555685BB60ULL, 0x08D266FBD1E3219CULL, 
            0xBDA4B9316C550C8AULL, 0x92B1C7CA2BAFE870ULL, 0x10922C15D1B146F1ULL, 0x0D67FB68DA00C3D4ULL, 
            0x46C4DFB689BF2039ULL, 0xEF48001586B337A8ULL, 0xEC3F79C1BDE188FDULL, 0xA15772FDD6D2CA43ULL, 
            0xD7D56C30B7176DF6ULL, 0x52CFE94E825A937FULL, 0x0DD681718E2D9968ULL, 0x8306E10656EAEBB2ULL, 
            0x630017EBD9098FE9ULL, 0x774645A6B1534204ULL, 0xF0208B3D2CF54255ULL, 0x074A1487E3977901ULL
        },
        {
            0x1E39953D28B30F32ULL, 0x00083EF3B2E6B364ULL, 0x0FB07552540B9982ULL, 0xA1096611ACD4B583ULL, 
            0x0D43786AFC254917ULL, 0xEEFF02D42487CFDDULL, 0x47EDF9E5A7C25D6BULL, 0xD4B13F0B22CAD87FULL, 
            0x40B0A9C333C2B8A9ULL, 0x09DC967A2D5B5E2DULL, 0x05CC90A5EAB9E3FDULL, 0x3B1F0BD30E659C58ULL, 
            0x582732AD602DB019ULL, 0x701F2DDF93527D96ULL, 0x41FB80BC710E9C31ULL, 0x1B621BC400D71899ULL, 
            0x170C3E114748FE8BULL, 0x0CF936CA8D6D90B2ULL, 0xCC040CD78C791771ULL, 0xE19264F82FCA85ACULL, 
            0x97CCFC2766F7A57EULL, 0x26DC81A3CC7856ECULL, 0xCF9C4CBA23344060ULL, 0xC09F3E09AC50788EULL, 
            0xDE822FD6E8BD2CEEULL, 0x5482C0C69A834419ULL, 0xF9A36A5A927EB937ULL, 0xC17F4087FD64EF5FULL, 
            0x0481E199471BC346ULL, 0xB42179E1BE275C1BULL, 0xED8338615913C5D5ULL, 0x851BB741A6B622C3ULL
        },
        {
            0x6A21F5F94FD90242ULL, 0xE60E810B032E7ECBULL, 0x403CB7B9767744C4ULL, 0xF386FE99E8638EE6ULL, 
            0xA093020C762426C7ULL, 0xA4A77719C591338FULL, 0x010210A4D826A94FULL, 0x4FCD882D88F75A5FULL, 
            0x530CB4AB73586F38ULL, 0xE18AA23659CD17B6ULL, 0x466D2D1F861EC062ULL, 0xDA9582CC89590345ULL, 
            0x352234BD7FBFC8D5ULL, 0x38DAD1428FD504CAULL, 0x0502DAD6FC63D53BULL, 0xB629B4E0B69D224EULL, 
            0x036AE30AE9BD8A1FULL, 0x71435650DF098D20ULL, 0x06DDC92279440E7EULL, 0xC2FCB586988B3819ULL, 
            0xA9BA074601E14B65ULL, 0x7654466AE1910C52ULL, 0x32D55661BB2B0F2CULL, 0x8A56986B2EB5F153ULL, 
            0x6CAE107593A71489ULL, 0x499FDA916095E796ULL, 0x197D96EC80003D5EULL, 0xEF61559876CC98C7ULL, 
            0xDD3D7FE93750186CULL, 0x84A1D11199495492ULL, 0x8489D78DA36D50F3ULL, 0x0C18E0CC0FA9FDD5ULL
        },
        {
            0xF0A90AB45C6FA1DBULL, 0x7AD3CD24E144BFA3ULL, 0xDCCCAE75EB716B92ULL, 0xD7FD69A73626FAB6ULL, 
            0x99DD7C6C3D199C07ULL, 0x05F908DEBBF9F337ULL, 0xD54B83E97E45A79EULL, 0x0D3D772F49CED9E2ULL, 
            0xB5AA9BD6830FE353ULL, 0x7A8EBFAB4692A86FULL, 0x1DC0FA42E8E760EBULL, 0x8262DED343BC1E03ULL, 
            0x1B7B7E2286495C9EULL, 0x05C1BA2BE7566387ULL, 0x116FBBD4D366424EULL, 0x018D739848025DDAULL, 
            0x4AC5398B129EC4FDULL, 0x01D9BCC19BBE78C2ULL, 0xE8EC07D4502C971AULL, 0xC4D39AC54276F148ULL, 
            0x2AD182EE83469002ULL, 0x8FF976534A972D1BULL, 0xBAD5BFA218593341ULL, 0xB1DE9126F4A0B606ULL, 
            0x6368475C2829CC85ULL, 0xE2932BC73DE4787FULL, 0x5EB805ACBBB34F6DULL, 0xD2A934B8110EE043ULL, 
            0x20EFACBA967AFAC4ULL, 0x1E5FFAE35476041EULL, 0x3BC301FFBB055D23ULL, 0xBFB5386D5CFF61F6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseBConstants = {
    0x38CB8118F37B0ADCULL,
    0x91CB3006AC134ACBULL,
    0xC7DDAB396D7C48C1ULL,
    0x38CB8118F37B0ADCULL,
    0x91CB3006AC134ACBULL,
    0xC7DDAB396D7C48C1ULL,
    0x6FB3824E60E42981ULL,
    0x392BBACFD674C8D2ULL,
    0x9B,
    0xB2,
    0x26,
    0xA2,
    0x68,
    0xEB,
    0x03,
    0x44
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseCSalts = {
    {
        {
            0x9317F469561ADE74ULL, 0x9EEB96ED927432CAULL, 0x9A935BD071374254ULL, 0xFAAEBA456A53E743ULL, 
            0x916648EF16121B51ULL, 0xDCF6F15F77539CD6ULL, 0x64026E50AB91BD9DULL, 0x9654E691DB776FC3ULL, 
            0xFB289C7012904FCAULL, 0xF8780F0CC1A145EFULL, 0xF1F04ACCAD5FE784ULL, 0x8108A52E3067747DULL, 
            0xDFE476A5DF74740EULL, 0xD84F67EDD1782318ULL, 0xE51BBFC4D809D27FULL, 0x44D49B8FCD9D477AULL, 
            0x036C7CAE979DD6AAULL, 0xA3E9ED2087DD6CB3ULL, 0xF9BA754D6782C15DULL, 0xBAD66626CE9DE8D9ULL, 
            0x0C786668B687C78BULL, 0x8BD6C2732CFA35ABULL, 0xB7F077EB0B951E7FULL, 0x1CCA45186AC1325DULL, 
            0x7870C738BA05767BULL, 0xB7894ACB6091CB41ULL, 0xDD42D8F277B0ABBCULL, 0x5E4CC60863E029DAULL, 
            0x171C4C0D465CB22DULL, 0xAB7C71FE558E1AADULL, 0xDC2A453E5FE86AD4ULL, 0xF7848DC149B0D769ULL
        },
        {
            0x0A454B2194F66DC0ULL, 0xF8276084847C1E60ULL, 0x10A3975BF4C7563DULL, 0xABECB44830C41CB5ULL, 
            0xE10ED9EE21B1E325ULL, 0x0C0139171CF36631ULL, 0xDD7B5DD0660608A2ULL, 0x5DD30F755E627B13ULL, 
            0x2171375597C91B3CULL, 0xF4593BFD0CF50F86ULL, 0xC4D26B6DD4632E68ULL, 0x0412267B9A6775BDULL, 
            0x23DB6A57B4CBAA75ULL, 0xC2BBB979B62A5D52ULL, 0x8AB5AAEC711AF138ULL, 0xD5073FB1FA7FE683ULL, 
            0xBECB2E02F7E0FFD8ULL, 0xACCD2AEBAA53763FULL, 0xEC65220F8D5F8F0FULL, 0xD4055944FF9D23ECULL, 
            0x398F35B69D458C38ULL, 0x6018C2487D53DB28ULL, 0xDE0631C295425AB7ULL, 0x4E30D07A0EABDD34ULL, 
            0x22E9E6CB8C9ED40FULL, 0xE62E625649D11F26ULL, 0x4B8FB2B16B4410E5ULL, 0xFC6A9AD6F27D7E82ULL, 
            0x2C5C9DE92BFAA9F0ULL, 0x80E1FBD991BF48FBULL, 0x840776EC33BA9C44ULL, 0x39B2EC5A09764581ULL
        },
        {
            0x077DCA07B7AE6D4DULL, 0xAA630B2CF3A23F85ULL, 0xB963CA77BFCD2220ULL, 0x3E4A3E56CB925863ULL, 
            0x6B7995E0F8F99805ULL, 0x4EF9A1E1AFA37E5CULL, 0xBB2C584DE222D5D0ULL, 0x34B59CC592DD08D9ULL, 
            0xA6DE2AAD5930A31AULL, 0x033F32C33E34F945ULL, 0x28F979978411278DULL, 0xD039AF22EBFD45E8ULL, 
            0x6F3F9B403956031DULL, 0x355E7A525B3C3C22ULL, 0x7EA6FF6E7FA8BC72ULL, 0x173109D565F4B185ULL, 
            0x02AA76E1DFF53CDAULL, 0xFBDCE2F40211D7A6ULL, 0x8B8BE81CD581401BULL, 0x60A83C1E16A3CFAEULL, 
            0xD05C5DCA8E0F9157ULL, 0xE9DEC70EC4F2F89BULL, 0xEF1848E4ED7542C7ULL, 0x81449AD1FCC01624ULL, 
            0xC89BF010F8893A84ULL, 0x42E94C6539E530CEULL, 0x2BF5C459849E6964ULL, 0x262CAD0B77F48F61ULL, 
            0xD3CB480B0BB6512CULL, 0x39A373E2A7541407ULL, 0xF0488D1ABB0BF6B4ULL, 0x2BAC97EFE0568119ULL
        },
        {
            0x4B8D543BACF80F9BULL, 0xACE0DD11221544A9ULL, 0x060E3339C4FAD9CBULL, 0x07F7F2113E8CDAD4ULL, 
            0xE10CD5E2F76DA04DULL, 0xE7FB88BED2785DB1ULL, 0x65428A94D60D936DULL, 0x2567AA7E947B72B8ULL, 
            0x67054BBB934DC278ULL, 0x72D068B74B5CE0AAULL, 0x65B99DFF20B5C8C5ULL, 0x00708372E915607EULL, 
            0x5212DE3BC4E16E68ULL, 0x459C3EBDA21EAE92ULL, 0x2DC0EBD4EBD6087AULL, 0x72B24CAD00DC61C7ULL, 
            0x80B4E846E9EF42EAULL, 0x0D0ED6D03068A86EULL, 0xFFE092186D959451ULL, 0x970AF2B7C9CAF688ULL, 
            0x8034BE1906FE2769ULL, 0x050F3084F2A01DBFULL, 0x87E34195A6636467ULL, 0x7A3CA8990A77E002ULL, 
            0xA6F3C9C3F220919EULL, 0x215F4459F19A5438ULL, 0x687BE6034838D778ULL, 0xB45C6ECE35254EDAULL, 
            0x3C8B82986C9AAAB0ULL, 0xF7B92F266DF1C6A0ULL, 0x4F5E8D962D144ADEULL, 0xB830A6126C731AB3ULL
        },
        {
            0xD1B11EAD78889704ULL, 0xE11D5AB89BDB63E7ULL, 0x25053D97E4CC6257ULL, 0x9C23CDF1C5AC00DCULL, 
            0xD21EFC92AD0561E4ULL, 0x4FBE617333D6750BULL, 0x34F7D6DC6897CC8DULL, 0x2753A1A262A114C3ULL, 
            0x48967A964E31EBD4ULL, 0x6B1BE0344CA96AFCULL, 0x726299C6207BF4B0ULL, 0xDFF0DF74619395ABULL, 
            0x25C402CB112147ECULL, 0x347362E0B7E0DADEULL, 0x92B7AC70008B4D2DULL, 0x329A7DEE0F41F012ULL, 
            0x076CA7E08D7B6ABFULL, 0x8AAD9C7012BE5607ULL, 0x6C6AFA113758EFC6ULL, 0xA61D67979522DAF9ULL, 
            0x55DC0F4F9BE949A7ULL, 0xEEF80324AD57CCCEULL, 0x6BC4B59B387F7801ULL, 0xC852A267401B7621ULL, 
            0xB801F5B0D52FE8B3ULL, 0xD81DADDF752F2FDFULL, 0xC0A3EAE5D25B2F42ULL, 0x1DE08C96E8A9183BULL, 
            0xC4748A4F9F40DB5CULL, 0x508B19B6C1D2CA7CULL, 0x744EA0410DABA668ULL, 0x7836ED98DD158EADULL
        },
        {
            0xF99B672DAC84A0FEULL, 0xE3023D39E653D4F4ULL, 0xEB09A675C06E2153ULL, 0x7E1F5B8534E11746ULL, 
            0x82024170EE5C173CULL, 0xF897D469F4BE01E5ULL, 0x13AC48C2C14359DDULL, 0xA9EBD8F8E4E91ECDULL, 
            0xA962F20A77589DADULL, 0x999B80DCAC2A40AEULL, 0xD6A075B13198F71AULL, 0x2E7026AE70399BFEULL, 
            0xD42B83816BBF4197ULL, 0x051AB420946F5709ULL, 0x6B1DE569585B8069ULL, 0x1E03028D5ED308AFULL, 
            0x95D78A2B600C11B1ULL, 0x43F9281F3B77DAEBULL, 0x3E345C01B73567C6ULL, 0x39E13777923D829EULL, 
            0xFB5CFA2D0271B4ACULL, 0x32519D9DCBBCD902ULL, 0x4D3582A13D40405EULL, 0x9D4AE5789BD11D74ULL, 
            0x58E8D86B4E539802ULL, 0x493C90FA63C7DA1DULL, 0x38E56164D0D9D6D7ULL, 0x42BA7874E3E122A6ULL, 
            0x1AC7D2FA81B7AC7DULL, 0x2536A2DF8D5DAC4CULL, 0x13145569472A23CEULL, 0xD27F4846A063127AULL
        }
    },
    {
        {
            0x1B91F1EDB2ECD086ULL, 0x22F0A498F05C5EB6ULL, 0x71B71D1B93363874ULL, 0x3E7C8CAFA7441DADULL, 
            0xABFCD2C0C23D9BC1ULL, 0xCB7FB88312B454FCULL, 0x4EE605935595D784ULL, 0x9A5FC20A743330D2ULL, 
            0xB65EADC428359850ULL, 0x42BB9218E47B6175ULL, 0x3B00EE1DA3924B73ULL, 0x7F86E6D33DEA5190ULL, 
            0x4782B8E379F9803AULL, 0xAF298690CBD97B00ULL, 0x9185B1BE34C6A488ULL, 0x7F2559850FF26CD8ULL, 
            0xB0FDA5235B0144A4ULL, 0xEB2C8C95E9B1B0C5ULL, 0x7C72BF67B24496F0ULL, 0x0BE332B8795516AFULL, 
            0xD882CC6FA785C2CDULL, 0x288B99DDBBFDEB07ULL, 0x22371179D4CBD6B7ULL, 0x1A7BEC26000D7E13ULL, 
            0xFDF4E6990284354CULL, 0xE53360AD263B8363ULL, 0xBE5978627966510DULL, 0x7B00F952B10FA533ULL, 
            0x104392E85F883DA8ULL, 0x6DA6AB0182ADB118ULL, 0x35BEB85A4EC387CDULL, 0x95D7F078D5775036ULL
        },
        {
            0xD3EDF39CB1D2A129ULL, 0xBE459261C04D3A4FULL, 0xFC7CE8163173B304ULL, 0xA2D9C3755C9B50C8ULL, 
            0x745FAFC05A6FFEBEULL, 0x34F3B250E21E6CCEULL, 0xA5D273D9F83AB040ULL, 0x34849314DB59D808ULL, 
            0xD75653BAE0F16A46ULL, 0xC10C8E44F6372EE5ULL, 0x3F6965CE91AE03F9ULL, 0x8C0095879CA31A32ULL, 
            0xF719DEDAA127C14BULL, 0x90A94CFF94660008ULL, 0xC60AD593E568E662ULL, 0x1609B00B0F84885AULL, 
            0x737E5E03AC1F68FAULL, 0xABAFC9892A89FC18ULL, 0xBDEE0E3AACA28276ULL, 0x39B7309E78505587ULL, 
            0xC5A9296BEB81F375ULL, 0xA98AADC21335EBECULL, 0x1DF631A3EE7E006AULL, 0x3D2426225E99E436ULL, 
            0x23B8E37840B40011ULL, 0xEAAAE29D7B3F0AD8ULL, 0xD8B223C6DF95936BULL, 0xEC4E1998F7A433A8ULL, 
            0x4B0636B1BBB75320ULL, 0x4B1EC74F2B9592D0ULL, 0x82A69051E98F96A3ULL, 0xB8CA9709CCFF8075ULL
        },
        {
            0xB2648EFA33A15E21ULL, 0xE350A2E43CA7C447ULL, 0xD95458605D3F2018ULL, 0x7D00BCF56F12990FULL, 
            0xE57CC26DC51697D8ULL, 0x0C80E20E237FF0BBULL, 0x7FE63D789363EB15ULL, 0x265E0E5398ACE01EULL, 
            0x27256028BB3B35A5ULL, 0x80DA4435CE2E23A5ULL, 0x76FA9BDA747B9AE8ULL, 0xFA2981E18A6BB409ULL, 
            0x725289F4C187F4F0ULL, 0x5068EA5919355F34ULL, 0xB2A4EF4A0AA2508EULL, 0xBAF699609CB75FB1ULL, 
            0x00A111FFA3F6CF17ULL, 0x25CA14E879740B8BULL, 0xF4713AF6BE4EDB49ULL, 0x8E75B9AB106FF8A3ULL, 
            0x90977179FD07BD0CULL, 0x2B6C343A97709B9EULL, 0x4340B5C1AFB948AAULL, 0xDB4F2950B5761840ULL, 
            0x5EA33A38D5CF55D2ULL, 0xE57B8F2F48D81231ULL, 0x52AFBB5EFC38133CULL, 0x9E84F1E646418D32ULL, 
            0xBD744E2A1A0D477DULL, 0x103BE382D79F3AB4ULL, 0x2846536B7B306FE8ULL, 0xA8828964303A42DBULL
        },
        {
            0xE4C286C3B4663E0FULL, 0xCFD51303EF3C7C7EULL, 0xC01E79A8720DD667ULL, 0x7A028773E8147782ULL, 
            0x1FCF6C59C279FC92ULL, 0x350731974CAFE854ULL, 0x6E86CD7C307B2CE5ULL, 0xE9BA83126B295509ULL, 
            0xEA8E8E3AD309B6EBULL, 0x267D56B7B00E7C93ULL, 0xEF32C08DCC2864C3ULL, 0xB0025A31D8543776ULL, 
            0x69E48089FE230D02ULL, 0x41AAA864FCAA0C93ULL, 0x5559950E37DE022CULL, 0x1D3FC7CB4C8A4F7EULL, 
            0xBBCBE09E10667C41ULL, 0xE12B027E3BBA05A9ULL, 0x8FB9B36CCC67AD5CULL, 0x0BC42B2994082B59ULL, 
            0xD9C844601CF22D0EULL, 0xD3342E76B434BB90ULL, 0x0E82D9E03C346AD1ULL, 0x46747F5D9A4858B7ULL, 
            0xC3AE4D88E5EDD5C7ULL, 0x3BF658ABEECCBA26ULL, 0xE71B2C112173915CULL, 0x755F8E7690B28FFEULL, 
            0xAF626A4D3367369CULL, 0x3FFE651EA0C3A3DEULL, 0x5D16AF6EAA3A2565ULL, 0xD0C1356232E86916ULL
        },
        {
            0x72D27F52D6CBE5CEULL, 0x2CAE0099368C107BULL, 0xA7E54F6071316B96ULL, 0x765945A3B451544EULL, 
            0x92AE2B64E0878851ULL, 0x3270C89F15FB49C6ULL, 0x71314061E4201170ULL, 0x7D0C340201299F55ULL, 
            0x8D0859AEDA122C83ULL, 0x1925956D66D69EF6ULL, 0x4DDCF69B860A774BULL, 0x4190BC512F8894C1ULL, 
            0x1EA15C597BD7999EULL, 0xA0ADEC116B1CC181ULL, 0x4424A02E2CDFEAE4ULL, 0x9EEBB16EE1466D77ULL, 
            0xBE1BBEC1B0B34E9BULL, 0x7E6A120EB1BDAB90ULL, 0x0CF88EC719C4C326ULL, 0x90C44F3BC5F8AAB1ULL, 
            0xD6BA98A9668584C1ULL, 0x89314B3DE3BC204EULL, 0x4B2F03363E5DA3F2ULL, 0x52A36161D1C8A645ULL, 
            0x36C7BF29A5705BBFULL, 0x0E88499EF8A38E4DULL, 0x82F12681951DD5F6ULL, 0x88F09A18A6CC1593ULL, 
            0xE52DAE23DEA761A9ULL, 0x2BBEB43DF9BCA937ULL, 0xD9B04C8260FD9477ULL, 0x7A33091E15D6CCBDULL
        },
        {
            0xE84DC19BDE1790B7ULL, 0xAA6107B78713EE3AULL, 0x1750D24545D29168ULL, 0x2C65E163AB4A0B68ULL, 
            0xA351A0871439A348ULL, 0x600278A502DF9BA0ULL, 0x2D9BF8D0889DF6A5ULL, 0xAE96FEC7769CD8BCULL, 
            0x85D827DD21F2B6F6ULL, 0x4B8BCEC130903DB0ULL, 0x3C3FF6A37A647349ULL, 0xAD4C767ECC91E6B6ULL, 
            0xDEBCCE7B66B47FD3ULL, 0x7D6601CE71619048ULL, 0x253F0ADF2EE8E44CULL, 0x03E43B6B3229CEBEULL, 
            0xC97823781F078FA4ULL, 0x3ED9D35727AAD505ULL, 0x3D175194E66F0FDDULL, 0x3E626D304216376FULL, 
            0xE5C17CE0D96B27F8ULL, 0x4F2746689391E8EBULL, 0xA450F429BEA3C57FULL, 0x4F75817C7C3899E8ULL, 
            0x9AA9AA5F8F5152D5ULL, 0xEEF13FBE6D7E87E0ULL, 0x029043DC6FF507B6ULL, 0x5F4DBE8BBECCDB9CULL, 
            0x496089832817E105ULL, 0x96EC955B5542280CULL, 0x56B46BF39EC5B8CCULL, 0x975211656FE94E29ULL
        }
    },
    {
        {
            0x14D4FABA9C1C5DEEULL, 0x82FFA812518B7BCAULL, 0xFAE86E42A856EC53ULL, 0xE10EFBA9A94B1C74ULL, 
            0x648BA7EAB5FA5048ULL, 0x18A3A4D6E5C2C81CULL, 0x2B589BBFE8106F1CULL, 0xEC8D816F73598A88ULL, 
            0x50605C80F7856F05ULL, 0x230C88C1CF59A4A3ULL, 0x2AC25099EF450C02ULL, 0x8B74A6679E9623A3ULL, 
            0x3C1FE4CFB95FF406ULL, 0xB5BB2C42FD1BEB2EULL, 0x09EAFCDDF8B47F6BULL, 0x59C8DAEFB346D6E8ULL, 
            0x573D1AFE81214A6DULL, 0x048CC3D6322F7091ULL, 0xE8F887A027C60719ULL, 0xB9C56640E6CE8514ULL, 
            0x1D91BE3760019B63ULL, 0x783A42FE4CED0D75ULL, 0x8B25E56D778E6254ULL, 0xC9C8D90153EF3A34ULL, 
            0x36D033B5F2AA1263ULL, 0x25019AE2B4CF8046ULL, 0x3EBFC5E33E7D6FE3ULL, 0x27635D23C003C238ULL, 
            0x8300B270C0338184ULL, 0x1D1F37D80A8FCE46ULL, 0x2CAF4D0159EB08A4ULL, 0x5753056213F625F8ULL
        },
        {
            0xAAA2621213E82E87ULL, 0x7D171904AABB455EULL, 0x2D3B3DE26B6CA7AFULL, 0x3BFEB7DEAD7118FBULL, 
            0xD415D97474EACE47ULL, 0xEBDC88D4B969D6C4ULL, 0xB2CA171B502BE292ULL, 0x702B78726851FD0BULL, 
            0x64A4BA79417E517BULL, 0x2437DF196B31E3CEULL, 0x91DD96FDDFA2A62AULL, 0x1ED07C1B680FC4A7ULL, 
            0x577C27F45472B67FULL, 0xB3BF272468F26067ULL, 0x19691C7D42284B14ULL, 0xA326B56F877012A4ULL, 
            0xC38C089DDA640827ULL, 0x23D06511BDAAE31DULL, 0x0A4B3489A25ED4D4ULL, 0x3B3A58FB2C48F091ULL, 
            0x7F65CF602036D934ULL, 0x6C86BAB823B27527ULL, 0x9DA19B1A18D94179ULL, 0x69AB5BA73FCDDEDAULL, 
            0xC1C6093372C5949FULL, 0x0BA058E5879B9A0CULL, 0x56B951D9E07ECD28ULL, 0xE6946EF396BFE400ULL, 
            0xD63ADD99FC62E62DULL, 0xE387658A8828C2D4ULL, 0x7C54354665E120F0ULL, 0x3109887F8FC8C34FULL
        },
        {
            0x5B67A97C4CFDBDF4ULL, 0x56223B029FFDEA36ULL, 0xFAE2B70872ECE727ULL, 0x471404859295D7ACULL, 
            0x3EF9377FCB306B56ULL, 0x721227E90E9B00DFULL, 0x6A54EAAA796F58DAULL, 0x69023517F42A1B2DULL, 
            0xBA7B519F8156BCC8ULL, 0x4B994EA1F05EEF6EULL, 0xCA2B17218029C94CULL, 0x03C67F371B0FD477ULL, 
            0x0C038FFEDF08E95EULL, 0x169D3BB49B1DC591ULL, 0x02EE0433BFBD8DD2ULL, 0xD495E9FE0FA88717ULL, 
            0x0C95537F88164B9EULL, 0xCCE0CC3EE0D93E08ULL, 0xD01227EA33CE36E6ULL, 0xAFF0C529409470C1ULL, 
            0x044334AB3EDB1A97ULL, 0xEA064316EB1BC3B6ULL, 0x818BFB09F9A67FBBULL, 0xCBFED5168C40795EULL, 
            0xA5FD4DD1266BDAC3ULL, 0xF464D66BEFC5927AULL, 0x16563C4A78ABE9FCULL, 0x8A247928646F9EA1ULL, 
            0x7050027CC85CD192ULL, 0x7F16AA2A53AFCFBDULL, 0xAF1DBBD0BCAEDA72ULL, 0xF3D2A160E9D0B7EDULL
        },
        {
            0x7620CED852267E02ULL, 0x21BD202FE2A8E115ULL, 0x93CB8618634EA1BCULL, 0x7309881FDFF0B464ULL, 
            0x3FE063E6B50E5042ULL, 0x4D831B2DF0AB9926ULL, 0x17FCFF0E3A56786FULL, 0xE8BF9CAE1E5C7008ULL, 
            0x16E34DFAF5131FBFULL, 0xE7C3DF0D8460D229ULL, 0x490FB5A6AE9E9855ULL, 0x321201DBDDC75E3EULL, 
            0x53FFC4EA62625C38ULL, 0x7BE8BD053741A1BEULL, 0xC4F0DB7E44D50113ULL, 0xBF646AD711ACD2EFULL, 
            0x73A59D15C732C935ULL, 0xBB226FB48D752CDBULL, 0x860A941D511A3DBBULL, 0x8CDAAE09AE08CB1FULL, 
            0x5079769B33743C58ULL, 0xEB0487B664C9BA4FULL, 0x5C7005174147AF5CULL, 0x6CB1E17B8A78FED0ULL, 
            0xE02478CF775419EBULL, 0x4A5808781B42C250ULL, 0x45AEC6038DC7386DULL, 0x57281AFE656F124BULL, 
            0x03BB4A0CD4F570B4ULL, 0x5F3D0CF088BAB131ULL, 0xAB728708F1724A44ULL, 0xC776218D45D92EC2ULL
        },
        {
            0xA26B59BE96D26CE6ULL, 0x64CAE17E3C128B30ULL, 0x822F295F176460AFULL, 0xABCC7CF48F942E42ULL, 
            0x2780D54621A489ADULL, 0x227B7E436E049C37ULL, 0x7AA82ACFD03C1177ULL, 0x6216136A2721EE0FULL, 
            0x287489E08FD7AF57ULL, 0x8FF51C23F36A1FEDULL, 0x3FB1E3733BD6C5B3ULL, 0xEC2030FA8FC2BE45ULL, 
            0x44E1CB23A39C0039ULL, 0xC1E0D5C29122516CULL, 0x387BF261105C53CCULL, 0xB268CE99DE2BE4D5ULL, 
            0x57DAD0BD70DC2FDBULL, 0x074B1DC6C2A406E4ULL, 0x47C03FAF9119EE1AULL, 0x3EF8EEB02F19F0F9ULL, 
            0x4DD665AB38E7C4BBULL, 0x375427692052BA70ULL, 0xB1BEDF71312D3090ULL, 0xA1518A22DD70E900ULL, 
            0x03917BFB83D7575CULL, 0xA7BBBBBCCAE36F41ULL, 0x90DA2D09921B0C96ULL, 0x0320255943BFE4E1ULL, 
            0xEB7FD3C82F449677ULL, 0xEEBA34A4FE9051AFULL, 0x13A913EEEFCE33E9ULL, 0x918858B103E3FC7EULL
        },
        {
            0xFD424B121693F9F1ULL, 0x5BF0F2ABAED66E97ULL, 0x58351591ECA99203ULL, 0x275AE7EE7CB3F70BULL, 
            0x59D214D2550BF17CULL, 0x104612AE9CE4092BULL, 0x8708F18E5B3EE8D3ULL, 0x7926391BB5908CFAULL, 
            0xBABF3323CB005EEFULL, 0xC6FFCD134EF376D3ULL, 0x5A6DF143AAB81BE0ULL, 0x8359D5E5EA9BFE4CULL, 
            0x70DD5CD5028F0CAFULL, 0x39EAA03D3C36B541ULL, 0xC9E11C47499F3418ULL, 0xA8C7EBD29E93F653ULL, 
            0x33E6B998C8F9856CULL, 0x5FCC28B8639D05B4ULL, 0x9D16CFEA4A5C2D62ULL, 0x5702B6689A80CB92ULL, 
            0x5A3B1BBF4266B766ULL, 0x78B438B938AD1D7FULL, 0x5787A5D8C2F89388ULL, 0xB9881D5AFC18DF88ULL, 
            0x973F8B397F8FB56DULL, 0x949194CED4E77781ULL, 0xDAC9037AB722310AULL, 0x33822FFE1D9F74C4ULL, 
            0x06861E05A0CAED06ULL, 0xD3ED9E4B36E94E81ULL, 0xF404091917BE5E54ULL, 0x8C4BCE0EEAD18F85ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseCConstants = {
    0xFC88C850D41E07B7ULL,
    0x815AE37FB4546AF1ULL,
    0xE24E02A01D02B0B3ULL,
    0xFC88C850D41E07B7ULL,
    0x815AE37FB4546AF1ULL,
    0xE24E02A01D02B0B3ULL,
    0xD210F6682D43E919ULL,
    0x7DFD3BE97D24149EULL,
    0xD0,
    0xC7,
    0x3B,
    0xB9,
    0x7F,
    0x49,
    0xA1,
    0xB1
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseDSalts = {
    {
        {
            0xAB8DEB86702F183BULL, 0xE95904DCEC8F3E5EULL, 0x0D381C57DEBAA6D0ULL, 0xB9126AAE2BFC6001ULL, 
            0x5A988A844F20F990ULL, 0x17587312ACD05A7BULL, 0xEC15753DA1DE04B6ULL, 0xBC23A5117BE789B6ULL, 
            0x8D8234D200C9A48EULL, 0x88F26FF329E0DDDEULL, 0xFD5C7338E9A7E1A4ULL, 0x2FB5729BADB78015ULL, 
            0x7481CE5862CA1EDEULL, 0x7A6F2726D491E809ULL, 0xCA55B91329DF4AFCULL, 0x558882A0A00CA2DFULL, 
            0x871721A7FB8DB5DEULL, 0xDEFBFC88A3AB0869ULL, 0x0E65BBF4AC14C90BULL, 0x6296DD3FEA2BF899ULL, 
            0x8AD161255ACA89A5ULL, 0x9B126808B6B74149ULL, 0xBDFAF47A282D838CULL, 0x6CC7632C4F5C1880ULL, 
            0x0637EB877A95AF66ULL, 0x808DFFEB6DDEC5E0ULL, 0x60EC43562AC4C120ULL, 0x86388F77C75A14A0ULL, 
            0xB809C9E1F7ECCA19ULL, 0x47D612985A263D68ULL, 0x99749BD60A580DE9ULL, 0x0EEB7F4F421C1BA8ULL
        },
        {
            0x34F8BD130A37F0E2ULL, 0xC193BBFEC88F4CCBULL, 0xA85B0B7101C94B98ULL, 0xDEA6110A7F1C80ECULL, 
            0x45897D7D5CAB83BDULL, 0xF891BDBD81FF9C5EULL, 0xEF1CC28AF9155C1FULL, 0xE90222FBFEB6F23DULL, 
            0x1FFF504CE0F03297ULL, 0xCFE9320938FEBC6FULL, 0xD0D4EA41A880649AULL, 0x2E2D61FF88980B75ULL, 
            0x7B1B89B2B504A3E6ULL, 0x8089EEAE87C0DF7AULL, 0xD2E8F4B469FDC56AULL, 0x3730A1760E418185ULL, 
            0x3ACD565C4D88F180ULL, 0x40C91D0683581766ULL, 0xAD08A0D3BF378175ULL, 0xBE8399FF9F6BBF37ULL, 
            0xC4BF1DC01B85F9DAULL, 0x57BE3F50E9B46ED7ULL, 0xB031A9E23C035575ULL, 0xF5191DCEDED79BFBULL, 
            0xE4C4AB7B586B57F0ULL, 0x75B19E5A5DA48845ULL, 0x1DEF7CD6EB985805ULL, 0x2FD68906AEDF1CF7ULL, 
            0xC5C2C770C94AC46CULL, 0x28EBCACE785E5AA8ULL, 0xB7E431259E9DEF25ULL, 0xFB3B9265DD631031ULL
        },
        {
            0x9E8450F076E72F8CULL, 0xF55FCF52430C8147ULL, 0xFCF0BB5AE34D1368ULL, 0x4CDD074FBE623512ULL, 
            0x9B7DBA046FAE7DB4ULL, 0x208368E04A379CE9ULL, 0x3489920AC26CB8B6ULL, 0x7FE618703EA12345ULL, 
            0x6DC9BE8E8549A74AULL, 0x1DC2093001066351ULL, 0xAA54AF71AC392C78ULL, 0x053E69CB5169B04BULL, 
            0x30B47BAF57F26AE3ULL, 0xE1DB5FA3BC7FB295ULL, 0x27C4CF12461C2EE9ULL, 0x744A235CDC4745B1ULL, 
            0xA997CED58468CCF4ULL, 0x50C24AE46AC792D8ULL, 0x7D2A2D4AE776C7D0ULL, 0x000F3295ACD78625ULL, 
            0x1DCE182FE1E39BA5ULL, 0x2446EBE0AA006462ULL, 0x990E517A2A7DD218ULL, 0x16FCB9B16FCE99F1ULL, 
            0x972D4E8F05DE0A24ULL, 0xCFC10273AA5EC2F4ULL, 0x8B3CA3EA672C27DFULL, 0xE9EBB7AF3DEC997CULL, 
            0x721CE39386E39646ULL, 0xA86481EBAF34BB47ULL, 0x63B579EF6BC30F8EULL, 0xFAC788975DE90E8DULL
        },
        {
            0x9F483DD3D298B888ULL, 0x2ADFD063ED09B5D4ULL, 0x19F55760F5C25847ULL, 0xF181FF3BF39FE992ULL, 
            0x003D250A9B79C06CULL, 0xA40953EB360BDD81ULL, 0xC33170C05F924074ULL, 0xAEA68E011FD7B275ULL, 
            0x066CFB8D4A160099ULL, 0xCCC60C3335BC0BB2ULL, 0xAD6BE97D83D77AB6ULL, 0xFEEDCF506A5BC3B3ULL, 
            0x9661CE387875DB48ULL, 0x4D254295C0E5E8C9ULL, 0x722FFA8C17285139ULL, 0x76E049348BF0DC78ULL, 
            0xC309C5C88E49B287ULL, 0x9D62C40A780EDCD2ULL, 0xE12A3BC39B05A961ULL, 0xE2872FDA6EE80C79ULL, 
            0x13B4FF9895885FD8ULL, 0x890C48520B8411F8ULL, 0x8FDC3CB19829B34CULL, 0x9037FD0E7085471AULL, 
            0x3B3B5F877D05755FULL, 0x5422226A93A041F4ULL, 0x637EA7B5759073EEULL, 0x7935A94CB90B2073ULL, 
            0xFB81EBC782AE592CULL, 0x612B05BEAC1F65AEULL, 0x70D855C057716695ULL, 0x3203CBFC92B5695BULL
        },
        {
            0x0EEA66DBC1C83680ULL, 0xCE986E1861B67FBBULL, 0x8C2E35A0DBF60B02ULL, 0xB15BA1B4B3F49861ULL, 
            0x1F5EDF274E7B010CULL, 0xB0BA727B7279AD9FULL, 0xB34626A047A5D44FULL, 0x1ED1ED4D089C127AULL, 
            0x2CB11D8A4542D288ULL, 0xA7E3AC3933451E35ULL, 0xEDEB74CE66DE8F26ULL, 0x8C224BF19AF8FE1BULL, 
            0xC117546BDC27AE64ULL, 0x53481D2EDF9EA488ULL, 0xD998224F38191D4DULL, 0xC441D84904C4FB8AULL, 
            0xB21DC35797BF1147ULL, 0x5F176C3937D13C1BULL, 0xB4D3CAB53FFEAFC4ULL, 0xF08DFEB6FF532710ULL, 
            0xDE39CBB4820DE81BULL, 0x6687E1C3DDC339D9ULL, 0x445D5C399EE1C621ULL, 0x787393D100C6E619ULL, 
            0x0BD99462EBEB7ECAULL, 0xAB51386E63EF7208ULL, 0xEF4576FCE655739DULL, 0xADBB7219EA732342ULL, 
            0x246A7A19E91D8903ULL, 0xEAA729B514E1B49EULL, 0xA73A4B9621B0380EULL, 0xD994C939A93F3DD1ULL
        },
        {
            0xD3B609716DA188A3ULL, 0x325D8DEC8DFD3920ULL, 0x4DC7B21AA11C5748ULL, 0xC4A0714D48A0BED9ULL, 
            0x561F714BB1B83529ULL, 0x15A3EAEC2944DC62ULL, 0xC52EF1431CC92D55ULL, 0xF4D9F367F8052BB5ULL, 
            0x342C380A5F308B5AULL, 0x37AF297EB56E5B5BULL, 0x545F8FDA942B8E7BULL, 0x7A97AD9DA91650FEULL, 
            0x81B903AFE427B847ULL, 0x6880B872BAA428A6ULL, 0xEE425196935E6AEBULL, 0xE0742260F1FC9747ULL, 
            0x8DFF12EDB87B6278ULL, 0x58C88117A37E5B14ULL, 0xFCEF3352F06AC203ULL, 0x334F97116470BCC1ULL, 
            0x9ABF6A6876FC5B84ULL, 0x41C7BC0F535DFD2DULL, 0xC75A0E95EA92E2EAULL, 0x10731F4BE77609B9ULL, 
            0x769C2CADDAF06065ULL, 0x8B6F0127C414ABF7ULL, 0x786532AB4226CB1BULL, 0x04B1FF9216F589DCULL, 
            0x57437B5887A43825ULL, 0xBCF2C923B20E4D20ULL, 0x5CE8912376DC9750ULL, 0x1B5B4EF97FC1F0ADULL
        }
    },
    {
        {
            0x0F8D8170831B37A7ULL, 0x9B05FA5995B1D9EDULL, 0x359494642908E90DULL, 0x5B07C29C0023DEC8ULL, 
            0x44560518240F1DD8ULL, 0x015FB77492EA9F94ULL, 0xA0300B72288A0EB0ULL, 0xE2F82E3D08AF4ABAULL, 
            0x0F8F35ADA95E9B33ULL, 0x4DC471784DFFDE6DULL, 0xC625D332D78A528EULL, 0xE39AA735D95A9825ULL, 
            0x01527885555CE910ULL, 0xC6F283DAE1A8AFDCULL, 0xA855BD7CC90A5B87ULL, 0xA5042FADF4F47FECULL, 
            0xEA307801A3314AEEULL, 0x06D9172C54CDCCA6ULL, 0x4EE743005F5B8B73ULL, 0x0C57B1C3E6B49D20ULL, 
            0xC4E82F07CF8F2D0FULL, 0x11D6BFA321F407E2ULL, 0x491FB01ED6E11ADFULL, 0xDCB9596B9231586BULL, 
            0x4D312EFA67DCCD04ULL, 0xC9C89202D6423125ULL, 0xB35B14BF099EFBAFULL, 0x6ACED0DDCE33BF9CULL, 
            0x3C518522C8E0C280ULL, 0x4659D438E44BFC66ULL, 0xAB0F6F46D663BEFCULL, 0xCB2F004D26A48B83ULL
        },
        {
            0xD2BF0D8CA824D10DULL, 0x70CF317D0473ECD3ULL, 0xFBE478C4216D0B06ULL, 0x32DD3C4D7B2D2894ULL, 
            0x3E2F375D0A6A67A2ULL, 0xD135FBDFE3F0DCD3ULL, 0x46DEFB51E1E08329ULL, 0x20D43A8FB6C05019ULL, 
            0x4C78C538B13B0B8FULL, 0xB9E5A799B5DF8848ULL, 0x4DB249DE3B6E5942ULL, 0x5009086958BCDBA9ULL, 
            0xD380475B167ABAA5ULL, 0x192DA8C3E9FEFA01ULL, 0x01F175BB69BDF3B7ULL, 0xE7F173D7EAAEE537ULL, 
            0x3B60D5C7989D6286ULL, 0xCF2CDB22D39E939DULL, 0xD611F8062A3E7F60ULL, 0xC2B4CBABE536C422ULL, 
            0xB081329A3D2B2958ULL, 0x90BFEDC506156FFFULL, 0xC61718AEEF9011D6ULL, 0x99B65681A6A56938ULL, 
            0xA02D7013AB0DA744ULL, 0x62F023D1A29277C0ULL, 0xCF9ACF2B1C29872EULL, 0x56F5B8A2346DEFBDULL, 
            0xB5036EEB6349FE48ULL, 0x47AA202AFB3AEEA9ULL, 0x386767F8ED4081AAULL, 0xAEAF7E4FC5B27B51ULL
        },
        {
            0xD695DCAEAA461166ULL, 0x23B04C7B32DC73FBULL, 0xBD77F38735E0E8D6ULL, 0x6ECB55F9E605C733ULL, 
            0xEC9AD75CF1ABCFBCULL, 0xF4C1B47AF78F4A6DULL, 0x9F4343B0D5AD314EULL, 0x3897BE4B5D36D940ULL, 
            0xE8D4B2EF0B1C1ED4ULL, 0xB50DD6B92E17E489ULL, 0xEBBFC3E82F05D548ULL, 0xC9C022454F2756F6ULL, 
            0x9D6996E954E5C69CULL, 0xDE48E109DDB23B2CULL, 0x105A5A3428F9BFB1ULL, 0xAB94273D7D45CEB5ULL, 
            0xEA9F62C7E67FAE27ULL, 0x9878EC66F9E2B5A0ULL, 0x5BBE445018603584ULL, 0x6C39EAEB385EDC83ULL, 
            0xF78C06E4C7B17042ULL, 0x4812859F5AFDA7E7ULL, 0xD4D4DBEC4B7EDC69ULL, 0xFB22C57ECEED5A5BULL, 
            0x9D31033F079D00EAULL, 0xAE73636C36AA10D8ULL, 0xA584D8B990729733ULL, 0xF23611CF66BBB446ULL, 
            0xB50EFAF0F753C87BULL, 0x66169E4E67F75172ULL, 0x107AD15B0793A02DULL, 0xEB2412E2C88DD42AULL
        },
        {
            0x7A670A1E5BDB928AULL, 0xD9CD426BE4480791ULL, 0xFA5D0CE5931472C9ULL, 0x3BD3AB6E2CE0D46EULL, 
            0x4935E16320561161ULL, 0x3ACA156B80DF159FULL, 0x6E489DD48F659D3DULL, 0xF470D2CD625C3C17ULL, 
            0x3385F7A4B3EB9599ULL, 0x3B66A20DF74C4A7DULL, 0xD84927113D147B07ULL, 0xB5D05336CCC82C9BULL, 
            0xB21FA871C8F6FE66ULL, 0xF7C53F7BE3514ACAULL, 0x99EE42D70525E229ULL, 0x1813B5AA883FD3CFULL, 
            0x0364C64352BD83D9ULL, 0x5593BBAE8EFD172AULL, 0xEE3182D2872F5891ULL, 0x4C937F47DCFA9791ULL, 
            0x7CF3A90220AA0456ULL, 0x568584DF5BC47027ULL, 0xD48C84B5C60D14B4ULL, 0xCC4CD37D9AA17BD7ULL, 
            0x04A772E85DCFF234ULL, 0xEED62ED8FEEED722ULL, 0xF49550580C45C166ULL, 0x967085C88DCFA6F6ULL, 
            0xB35E315BCE75CAE3ULL, 0x5ED00D0B152D8F0AULL, 0x596E9B651FA7FB21ULL, 0xDFCA88E18E4D85A0ULL
        },
        {
            0x381A8AF5D8EDAC7CULL, 0xE8A1D8AE529BA6D1ULL, 0xECE50B3F0981EA0CULL, 0x50BD65D7D53A2A4BULL, 
            0xBCCDD1A4B4363ABEULL, 0xA3F36D4CCA1FE12CULL, 0x64E0D13F34C052FBULL, 0xC4B89FEB0E5A0927ULL, 
            0x512865112A643104ULL, 0x8F49E53567961FE1ULL, 0xC42A5149F1EF6C65ULL, 0x19556FBDFFBD6DB3ULL, 
            0xB87E20079CFFC853ULL, 0xE9F45D5DAB3ED552ULL, 0x1928C3403D65FDBEULL, 0xF562870F9DE8298AULL, 
            0x4FC7E8BD810D7F53ULL, 0x941023778B614C51ULL, 0x58608408B24ADD9EULL, 0x93A6C554C6146C54ULL, 
            0x5ACA39E18F5AC59DULL, 0x7B570AE21F8AA3A0ULL, 0x48F170F2549445EAULL, 0x6FF4B997183B5720ULL, 
            0xE29A2F143E3B5402ULL, 0xD3A5863EA881F4CAULL, 0x81D09ED65F653851ULL, 0x7951945675FEC8B1ULL, 
            0xA50A21B3768D73DEULL, 0x4A390D13DEE1D662ULL, 0x9D728549D1F817FDULL, 0xEDB82F635A02FD83ULL
        },
        {
            0x7B131ECD6FD17838ULL, 0xECE110F5059774E8ULL, 0x85C1A77ADE0751F2ULL, 0x792E2D68D9104A5CULL, 
            0xC781C5C449F9956FULL, 0xEC1D97848E057888ULL, 0x11C94FD9268A7A91ULL, 0x481696A01A8476DBULL, 
            0x34F585CC3F91E1E6ULL, 0x1A0C8B5FFF2D9F77ULL, 0x7CBF20433FDCD42FULL, 0xC202C0C357327739ULL, 
            0x0DF583DCD33613DEULL, 0x98019CAEA6306DAAULL, 0xF20D5286A7DCCFF8ULL, 0x7C968A40A38169C5ULL, 
            0x941BAAA27DD1D956ULL, 0x251F1FAAD9E06F99ULL, 0xC71F9E622CD66B14ULL, 0xEDA5B7C9D21D3392ULL, 
            0x53B64BC53D1C459BULL, 0xA8F283A36DA82426ULL, 0x9291A45212FB7FD9ULL, 0x9E2AF778A57885B6ULL, 
            0xED8F0D0A48A2AF14ULL, 0x39F40BD086FA0B4EULL, 0xAA8CC5EDED4C492EULL, 0xC9119D8C85FFEC46ULL, 
            0x0B1033CBB98FC7A6ULL, 0x9352C6AA73DA55E3ULL, 0x3923502A6FD3DAE0ULL, 0xE1E1E973AF0B0DE0ULL
        }
    },
    {
        {
            0x839D79CFCBAE6142ULL, 0x3668EC005FB9A7BEULL, 0x1497929CAB300E74ULL, 0x7584A8F3E1FFC358ULL, 
            0x12AB39CAF9AC8CEFULL, 0x5739B0CCF099E2FEULL, 0x2C8336A3E0FE1ABCULL, 0x820E379774AB3AE1ULL, 
            0x0912F31217B408BEULL, 0xB789C0C57740AB04ULL, 0xD6A12CEA69CEB4A4ULL, 0xF64A474A7D6204D8ULL, 
            0x60A986A7D821577EULL, 0xAB986C3DB8F4CCD4ULL, 0xD3AB9C479CCB3F40ULL, 0x85DA69A76F99B0E2ULL, 
            0xE268B3C7B97EE64DULL, 0xAB4B26C81997065EULL, 0xAD0EA93D29F1CCB5ULL, 0x1F94C6649C8A4DB4ULL, 
            0xBA5FDF73387D29D7ULL, 0x0459C40B3CFC159AULL, 0xBAA382D0B0EAF71EULL, 0x8395580ED0523971ULL, 
            0x1B2C5AF1CD59F6B0ULL, 0xA4FA752BF378EA34ULL, 0x4E2ADD763E64BE4BULL, 0x4A5628617894849AULL, 
            0x5EE76FB18A5859B1ULL, 0x1C11B60A56975891ULL, 0xB2D91CF5E6FAF7C2ULL, 0x38634EBA54268DB9ULL
        },
        {
            0x70112702AE21D28DULL, 0x315DA05580304D54ULL, 0x33FDF0BE617F49B6ULL, 0xBAFED8CDC69364E8ULL, 
            0xD2D58FF01D501816ULL, 0xA798D423E9249ED0ULL, 0x59C214A9D67A8AF6ULL, 0x3B9740ACFE434AFCULL, 
            0x516919C23DB945FFULL, 0x348B069922FCAB13ULL, 0x0263082CDD46D043ULL, 0x56A2891C9941524BULL, 
            0x5480DB2F6464F4D7ULL, 0x0065E11982E3D8BBULL, 0xB44C8CEAD2E38B17ULL, 0xCCF272E95C21B016ULL, 
            0x23D5019B5C9F3E7EULL, 0x3AAD331BD3779F42ULL, 0x3CE257EEDD0886F4ULL, 0x7D0DC5AD5AE898AFULL, 
            0x2AC1B8FF1F462080ULL, 0x86D233E34FEC4D39ULL, 0xD8578D43FE38730CULL, 0x520234EC33221CD2ULL, 
            0x73BE0705DC139A8EULL, 0x8235370C8F7945C4ULL, 0xA47AF4BC21E7B939ULL, 0xA15C433A3915A78AULL, 
            0x806C51727AC71455ULL, 0x733438336B7428CBULL, 0x73E63C8A263E57E1ULL, 0xD5E97598F676501BULL
        },
        {
            0x190638385ED8DF2EULL, 0x4BDDC87CDF636CF0ULL, 0xB279E8FABB7B0C34ULL, 0x20B313916F4B246AULL, 
            0x4F0A060DD86A59EAULL, 0xCDD59A857F2EBFC3ULL, 0x2867B7753DA5E511ULL, 0xCC59E38AE425DA8EULL, 
            0xE796F183746170EAULL, 0xEAB4465E4A9C1E0AULL, 0xB28B2494A67692D8ULL, 0xD92F6724875AAC0DULL, 
            0x54828DD16C324D6CULL, 0x3F5792E91FD936C6ULL, 0x1AA28CEB4661B5B7ULL, 0x0565E3E868668F86ULL, 
            0x65C293382865441AULL, 0xDC4FB8C14184EF02ULL, 0x4922E24A5392E710ULL, 0x628814CFC1F7C126ULL, 
            0x11FA29A0A8238A31ULL, 0xD32730772C160EA3ULL, 0x4ED39B84F5864EACULL, 0x0B7BDACECD934863ULL, 
            0x1F0210A29F77A3EBULL, 0x48A1F4E1FAAD5EA4ULL, 0xFE29A3C4DC2CABC9ULL, 0xC8F30BA50529AA77ULL, 
            0xB4D8F85855F8E781ULL, 0x7BED21425FB4C7A4ULL, 0x0AC99E6C081AC001ULL, 0x7372F6BACF3B6ADBULL
        },
        {
            0x2014B91BDEE681CFULL, 0x59107E7CA57B2943ULL, 0x20BCA705B0D12611ULL, 0xFDCC194D8CAD6C9FULL, 
            0xEB5C044E6BEC090CULL, 0xBFD42923AD8B1F47ULL, 0x2EA1B58339C74981ULL, 0xE5D1EC7D1CCC36B8ULL, 
            0x102F1FE40D1C789EULL, 0xF763C7712E48C361ULL, 0x629E0C748C4218E4ULL, 0x2706AC88AC7356E0ULL, 
            0x38398519AD3D2234ULL, 0x941D6BCEFF0F9725ULL, 0xD67D1AAC6DAF1E22ULL, 0x39F6AB4709CAC978ULL, 
            0x3FCA6E90BC88FA1EULL, 0xC4E883A127101ABDULL, 0x692FD7DC24E41DE5ULL, 0x2798CFFBA4961C51ULL, 
            0x55DA8FE467037D63ULL, 0x02C0481D26943140ULL, 0x9673F870E843B2E5ULL, 0xDF68F62213891309ULL, 
            0xCA415799DA7579D7ULL, 0x6539ADCE4C9D3A81ULL, 0x94A5337E4D04584DULL, 0xE2E0596819F4F955ULL, 
            0x13DE6806E3256052ULL, 0x567A4BC9852A8416ULL, 0x560A6F3ADC1CE54FULL, 0xD02436FA40F14A95ULL
        },
        {
            0x65E6EAB1B204F21AULL, 0x5638CC1E1AE59C66ULL, 0xB49917B5E7420FBFULL, 0x94E58F0A265360AFULL, 
            0xE3BA7CB4CA0960E0ULL, 0xCD684E25B8852E71ULL, 0xD941E4D97C46D6D2ULL, 0xE90A0BC90EA6E020ULL, 
            0xEA4C745B9EBC2BD6ULL, 0xDAF589E26B92C53AULL, 0x2BE78F579DC0F37CULL, 0x0B4E623639E1385AULL, 
            0xE60263FD153CBC06ULL, 0x6B2517737C9FE13DULL, 0x1BFE1B9519198E92ULL, 0x9DFCD15B52A76B4CULL, 
            0x8EE0825EBDB8FD39ULL, 0xFBA0541E48F6F20EULL, 0xC06688FA1F5339FBULL, 0x1745E292B9F4A473ULL, 
            0xE5A6F040763A7362ULL, 0x79A9FD31E6301E59ULL, 0xDF571E19A5ACF408ULL, 0xAA7ACCC3A53CC5A1ULL, 
            0xDA068B9401CB9489ULL, 0x6584C9584B124052ULL, 0x960FB84564D71911ULL, 0xC76EC504DD3B37C1ULL, 
            0x4604D6550A1A15D1ULL, 0x52DCCD6698F860D9ULL, 0xDF53B0DB65E8F9FEULL, 0xBB4EA94F086F1B74ULL
        },
        {
            0x5BDA05FEC1B82AE0ULL, 0x4746E1E84721C86FULL, 0x64A8638EFCDB30E4ULL, 0xC77E5064D386C814ULL, 
            0x86905AE9ABB3703AULL, 0x5E63C114275C4611ULL, 0xAF59B403E88538F3ULL, 0x975B24AF860434E5ULL, 
            0x863DF231686A6C0CULL, 0x0B0EC86869A8E744ULL, 0x40C7ED105294A64EULL, 0xA341C187502FE789ULL, 
            0x904FC5EB3DF69CBDULL, 0x77553E31E56C92A0ULL, 0x0E7ADA4F8D62C7CBULL, 0x68DB0182DB49512AULL, 
            0x77D2823F5117A68AULL, 0x862C9D179B7296E3ULL, 0xADC6374CDCB10603ULL, 0x933CCF87BCDF17F1ULL, 
            0x17A673E506EEDFD0ULL, 0x54B33D25408AF5ABULL, 0x6731F9F5448B5F13ULL, 0xEDBB280C5D1D57CCULL, 
            0xE86500967C60F318ULL, 0xF05876423D61E8FDULL, 0x6095D60BBFD7BE2EULL, 0x882011F58C777517ULL, 
            0x8FCD447EA59FF6E1ULL, 0x4619DCA0635FD03DULL, 0x2D49C0B0400CCA0FULL, 0x33FC9D565B0D8B4CULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseDConstants = {
    0x5FB9D0D94CF5E35EULL,
    0x81D1BB5C95D695FDULL,
    0xF453A609D3D3585AULL,
    0x5FB9D0D94CF5E35EULL,
    0x81D1BB5C95D695FDULL,
    0xF453A609D3D3585AULL,
    0xBDED714489CFBFF8ULL,
    0x726DE22C0724A54DULL,
    0x88,
    0xB7,
    0xBC,
    0xE4,
    0xEB,
    0xD6,
    0x83,
    0x62
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseESalts = {
    {
        {
            0x3EEC41E65986C430ULL, 0x18ECD3138CE7EF38ULL, 0x2C35A63BCF51B7F7ULL, 0xDDE8E439564C10F2ULL, 
            0x3CA029C346002C71ULL, 0x49F99E827777BCA3ULL, 0x4E2A0ADE31643E30ULL, 0xA612F44F09652B25ULL, 
            0x13922EB54E9C8912ULL, 0x4259A73D6882C046ULL, 0xECE3C893CCDCE92AULL, 0x64F3B5ED90E72DD5ULL, 
            0xFE5A3132DDD452CCULL, 0x27C393FC46D72036ULL, 0x92FD90CFB736686CULL, 0x2A6AB076C3CEDAE3ULL, 
            0x202F2710DAF57421ULL, 0xAEB75B309AD0769EULL, 0xAA7F71339C2DDBE9ULL, 0x4C49E2E922BD8146ULL, 
            0x5EEC597A905E1482ULL, 0x04494D1B47F6A53EULL, 0xDBE8C1A827F6438CULL, 0x4324A17383C17DC1ULL, 
            0x9315CFEABF241845ULL, 0xA6428D0AC011B484ULL, 0xFB3D72C3F24C1393ULL, 0x7CE34B269F13BE96ULL, 
            0x190F7D9093707C6DULL, 0x179C80735A778977ULL, 0xEDED21DB53E5F509ULL, 0x338A812CD315F628ULL
        },
        {
            0x1307569E3608722EULL, 0xD0B94C46E8FDF9E2ULL, 0x455784A69D357430ULL, 0x86C81BD6184E0866ULL, 
            0xC6D1C00C52C2F9DDULL, 0xCAA9B40BFD7CB22DULL, 0xB1C37EA90ACE0089ULL, 0x4F901A729D503263ULL, 
            0x0F6D86F5E0FA5A72ULL, 0x66266CE8E5C819FDULL, 0xA744FE7EFEDBD472ULL, 0x4A281B8DBA938EABULL, 
            0x3187D071683F4249ULL, 0x25F31E42FAFC5A07ULL, 0x9C31B8CEDE250A8EULL, 0x44F5D7BD4426135FULL, 
            0xB1CF6BFC5AE395E3ULL, 0xD6404D9AB49EF68EULL, 0xFDE18554C4BBC358ULL, 0xFC93F1C17B79B2C2ULL, 
            0xD416735AE3F1C052ULL, 0xD44B1131DAFE0406ULL, 0xEED235B528710402ULL, 0xD3E655EED03B2859ULL, 
            0x36BEC4164F8CC381ULL, 0x57DD0CA7D493EE07ULL, 0x2C96BD34CFB5A04EULL, 0x2BEE7910AB336044ULL, 
            0xD5706A901E5EAF6CULL, 0xAAF7A8FB6ABEDBDDULL, 0x6141FA768CA2A625ULL, 0xE481747AF098C5DAULL
        },
        {
            0x8FD0A7CF5F2305EFULL, 0x75D50B6F6B8CDB4AULL, 0x031C6E2C43654D70ULL, 0x8DFEEFD6AD67C199ULL, 
            0xF91EC9CAFF2D2EBCULL, 0xA9FE60A26638A195ULL, 0xD4F290B94C71E804ULL, 0xBED66BB8CDCEA1F7ULL, 
            0xFDA6D54EC1C619ABULL, 0xBD6C30CB4D19B664ULL, 0x03E7BFC059DD5897ULL, 0x3CCFFDBBE9CB195EULL, 
            0x2F2033CB5452275CULL, 0x13F48F2EB682D816ULL, 0xEF649A21D07F2850ULL, 0x822DAD38B4EBFF45ULL, 
            0x8780B60D5972A873ULL, 0xA09296BECDFA0EDBULL, 0xA4E1E048DCE4E5B5ULL, 0xFD515207B5C2D76CULL, 
            0x144BF7C78BB7D870ULL, 0x51C721766E226580ULL, 0xCB6B58BEBC2F5CADULL, 0x61752693C2DB3ABCULL, 
            0xBC987C1DADFBDAB7ULL, 0x996A320B4A0248DEULL, 0xE605A08EA8EF5EBEULL, 0x198A2B7A0758B11BULL, 
            0x7023A822CBC618F6ULL, 0x5DE1B3B5EE4D73A8ULL, 0x78DAC03631D4794CULL, 0xA34EE527D8822AD6ULL
        },
        {
            0x0F7ADB0686845069ULL, 0x118CEE6C95A99447ULL, 0x556218ED92FA54B6ULL, 0xE582464C5CBADE88ULL, 
            0xAED71C7A61AC1954ULL, 0x329521D489449ACFULL, 0x6542114907CF0615ULL, 0x4025563F046BBC98ULL, 
            0xEB16D5AF4FC3612BULL, 0xAC307E3CBEBA3BBFULL, 0x8FC7FE22B5F614DEULL, 0x52D2E93D8A94DB65ULL, 
            0x45DB01A1AE4B39FCULL, 0x82DD88B8CF02A85AULL, 0x6422E79153869F4CULL, 0x286ED56248E5BA4BULL, 
            0xE5579C28FDB04301ULL, 0xA4EAF898DFA83C1CULL, 0x74CA3D903A818108ULL, 0xE9A6131D2492985AULL, 
            0xE93D0D6D337545A2ULL, 0xE0B34E8C089DA1E5ULL, 0xF287CD75689651D4ULL, 0xEF293861FF1A8634ULL, 
            0x1C05C8E4BF6BD1E5ULL, 0x3D60C3AE7A7F29B3ULL, 0x5CF37B89D227566DULL, 0xA811C3DD833B8345ULL, 
            0x5A5194CE1AA9FE1AULL, 0xCDA91A1CC7962300ULL, 0x8BBA84B13AE7A349ULL, 0x86CBC8BA2B184C31ULL
        },
        {
            0x728A1D8FA93A54D4ULL, 0x01036C76163FB9FEULL, 0x4645E59FD37E94EBULL, 0x3C5A00A7134516F4ULL, 
            0x6EFEF0661BA9920CULL, 0xF9B22CDAB953FC22ULL, 0xFF699CBCA942D6AEULL, 0xD517955A3105EF7FULL, 
            0xD59EE35C3A277B0AULL, 0xFFDFAD14A501F831ULL, 0x5F4DB9CC8785E13FULL, 0xA01D12A90DF0E802ULL, 
            0x956F6F0653150C5EULL, 0x69B1006437D8AA76ULL, 0x4D039B0C17D7AA65ULL, 0x53F665992D15D17DULL, 
            0x4E550DBB5B613573ULL, 0x4C30B8D74512B1FCULL, 0x45C564AF002EBED1ULL, 0x90B6C99CE0881202ULL, 
            0x33336C460754A295ULL, 0x29508AEB155C8622ULL, 0xE00A698DE5583CDCULL, 0xB3825CE9A4F01C16ULL, 
            0x27237EA75F29A7D6ULL, 0x17B8043A2EA070F4ULL, 0x752495A19ACFF03EULL, 0x75B169D971E2FE2EULL, 
            0x2DB18EA465241E42ULL, 0xFE718076E5DB6F4FULL, 0xAA7D6BB0E82F2E1DULL, 0xF5D8C1A5885BF10FULL
        },
        {
            0xE539BF0C080D5D2DULL, 0x94AAF1E2E2EA9867ULL, 0x936F203A31C0BF79ULL, 0xA8137E33E0D92D28ULL, 
            0xAE90D5A75BB15C6CULL, 0x0E2EF95A4322C880ULL, 0x098F4AE799D3151DULL, 0xEBA2642A212372ACULL, 
            0xE96848D873DEF421ULL, 0xF561EEDDEF2B9395ULL, 0x79D3C3A18A1343BFULL, 0xB18308916A07F83DULL, 
            0x78B17DE7F3AC7285ULL, 0x09B71F38959A7F07ULL, 0xFAC6B54341479B25ULL, 0xE92C32C00414C658ULL, 
            0xF230760587087A95ULL, 0x30666CE27CC62D55ULL, 0xA10E38654EA53562ULL, 0x0C8E6E7476D1B7F4ULL, 
            0x74E21A4EB5ED30C6ULL, 0x0EF8076ABC78E9DEULL, 0x8312D722336D4A08ULL, 0x63C8F9ED1EDAFBDDULL, 
            0x72204AB64C44E8ABULL, 0x8AF428018B029CC6ULL, 0xD02DAEA91F69EB1FULL, 0xD398D227172D8AEDULL, 
            0x5F53DC94C3888665ULL, 0x1D85F4E859DF1BBFULL, 0xAD527C021BBC1127ULL, 0xF2E922BCF47292A0ULL
        }
    },
    {
        {
            0x30E1275F502EB850ULL, 0x00ECBA1A44A8EB18ULL, 0xEF48208F6EF0724CULL, 0x8E1729CA34DE4214ULL, 
            0xCCD3AF6785C3D4FFULL, 0x11F12C892DD7429CULL, 0xBC71F0085A8F3E6BULL, 0x4E7EE796C92089FFULL, 
            0x200F9B420D32DE41ULL, 0x4BB8FCC8AF934371ULL, 0xA77CEDD4E241D85EULL, 0x79A607BB49EBBD3BULL, 
            0x213B9237521B922FULL, 0xB0909F64622760B1ULL, 0x1A30FB3A1A8933D9ULL, 0x3052A7D3981918A5ULL, 
            0x7ED00C520E6805F2ULL, 0xAD31DDBFA8BD411CULL, 0x4BA2EF63E5BC8383ULL, 0xEBFAF01CF5C4F295ULL, 
            0xFB5995EBE04DF1A6ULL, 0xB8C2444760DB4A9AULL, 0xE9AC6A95CDBE60ABULL, 0x30A9F602BC4EC62EULL, 
            0x0F846C4CFA2BD5C6ULL, 0x91C01A17D3A255A2ULL, 0x1E58CF4616227284ULL, 0x165ECE6AC6FDD1FCULL, 
            0xDA8F1C65AEA1BBB1ULL, 0x5E0B8BCDB8398EF9ULL, 0x55CB265F778C5FC2ULL, 0xDA74417893AC3571ULL
        },
        {
            0x21EE62F4E2EC2994ULL, 0x5874828349DB04ADULL, 0x80021D4E5BA645F1ULL, 0x3667872B69C2D803ULL, 
            0xC0D42959A56B20C2ULL, 0xF9A3404A462324CCULL, 0x96C8485D32D2D89BULL, 0xA751F2A2500CF4BFULL, 
            0x70C54D3E3F5A25D6ULL, 0x2109864ADE8BF89BULL, 0x16250B2B2B86F2A8ULL, 0x141CCFDB5C7692A8ULL, 
            0x70D7E7FF42150788ULL, 0x1621E5199446AFCBULL, 0xD2D51855641E89F6ULL, 0xBBAEAC560C58705AULL, 
            0x2A982BE204AF9D03ULL, 0xA1B492FDC0F8403BULL, 0x4F78D38F6577D923ULL, 0xBE3325C087681747ULL, 
            0x4C35822F9BB3CF65ULL, 0xBE09450F81B412C9ULL, 0xAFC96C3494E695E9ULL, 0x6269EC804CFAEA6FULL, 
            0x9CBFAE39CFEC5515ULL, 0xBE9CF68459593DF7ULL, 0x2FD15CD77B989A3FULL, 0x36873CA7537F0C8AULL, 
            0x10025279B589A66DULL, 0x0DB33C719EC09377ULL, 0xF50D6D28F48FE01CULL, 0x25F9EDB1001E7CB4ULL
        },
        {
            0xF7FA568055E6DF17ULL, 0xB47190D268F6878BULL, 0x8C0DB6ECCFC2784DULL, 0xA8FC85A401E37551ULL, 
            0x02364AC663CFA976ULL, 0xA1BF0E49943B1953ULL, 0x068948C447D1FF49ULL, 0x3A2CDE0C924EDEDEULL, 
            0xE5EE9C23E1A4CB11ULL, 0xBDE3A946EBD1BB4DULL, 0x6A5FA44405661FC9ULL, 0x57D1F89649C333B8ULL, 
            0x2DF04CE9B04D8F66ULL, 0x1118D7757FA62936ULL, 0x13F2445725EEE0F3ULL, 0xB2221BEB4972DC9AULL, 
            0xCC053E3FE5D79C64ULL, 0xFEA277EB9771BA4CULL, 0x722592C852C6BFFEULL, 0xA3C5F4CFFBF9DE82ULL, 
            0x7CDFA70EB7662C8BULL, 0x8BD59E639876B595ULL, 0xDD2AEAB84C8F364BULL, 0xB1FEEBE06E59D035ULL, 
            0x202AEE87FCA226DCULL, 0x174488540E7A1C07ULL, 0xC52E107CA6B869B2ULL, 0xA1578812DB592696ULL, 
            0x91AE571FD469070FULL, 0xBED3CF5C66F077A3ULL, 0x37CBA0FCB8D35E92ULL, 0xEF0FC8E37175E202ULL
        },
        {
            0xDBE1A4BC5A7EB8BCULL, 0xC5519BE1B333E323ULL, 0xC5FB0C67A8B0045DULL, 0x2F778B2D898FB112ULL, 
            0x6B52062E3C80DE7FULL, 0x49E490A30DC3E429ULL, 0x1753A3ED664C7B64ULL, 0xF0EA2142AB5ADB11ULL, 
            0x2EBA3D4D780E607EULL, 0x53C8F53FE6FE01F5ULL, 0x41628F7ACA789092ULL, 0xA05C19F713D70F64ULL, 
            0x07B4F79538471F94ULL, 0x11E559ABDE3C27E2ULL, 0xA277C4DA21FE1774ULL, 0x9560170FA9625670ULL, 
            0x46BFE12748516D5DULL, 0x9EA18948ACC80FC1ULL, 0xF1D12E5A227A2681ULL, 0x0267A3101AB662F4ULL, 
            0x9D7D426E4B8CCEDEULL, 0x4E668CF35377B3ECULL, 0xAFE7D9A85867DB0AULL, 0xC9193E8F59C9AAC3ULL, 
            0xF7894BFD124455C2ULL, 0xBB12FE8649371868ULL, 0xB760B2FB004A2223ULL, 0xF08882C449464B96ULL, 
            0xB9A64B54A8786890ULL, 0xFE5FD4D60ACE7BDEULL, 0xC405025DED3AED78ULL, 0xE206237954894D14ULL
        },
        {
            0x5123F036F22FBB35ULL, 0x3424F34E96709A75ULL, 0xF09408EE5E58054FULL, 0xBDF23EB31D34A0A0ULL, 
            0x95777EC89F047862ULL, 0xF9E89FA2DA24B50CULL, 0xED831C8FB5984BDAULL, 0x11105FD84EE61BB3ULL, 
            0x65547A116FCC9BA3ULL, 0x64D760117E7AA44DULL, 0x3E3B841F930DC6C7ULL, 0x1C872C4C9844B64CULL, 
            0x1934F7018F25E801ULL, 0x89E008DB22B27FDBULL, 0x5879C46847C190D8ULL, 0xF5885C4206C43DCDULL, 
            0x870E4A63F81CAA3BULL, 0xE4A49DBB0D2848C2ULL, 0x8B25A6A6C9A0F6D4ULL, 0x2BEB3C4553EF886BULL, 
            0x1102ED6B56CF52A2ULL, 0x302BD763BCAB437DULL, 0x0F10FB071A416E49ULL, 0x1B269ABB20E41EB3ULL, 
            0x462EDCB862792F3AULL, 0x54AE91723C1E7BF2ULL, 0x0B54864A6B835C51ULL, 0x2FEFB61CDA1F2BEAULL, 
            0xE13720FC0B5D8DA5ULL, 0xDCA5E577D8071DD8ULL, 0x4C50CB9B6712C0A4ULL, 0x50161D1612247152ULL
        },
        {
            0x1D507CCA5DA67731ULL, 0x0D40328713DA5C03ULL, 0x1996EE35CA9EE49DULL, 0x0C53B1FB4DB9078EULL, 
            0x5F25A50E852E1336ULL, 0x31FD26335CD6C36CULL, 0xA3DF3E7D6DA920E3ULL, 0x515C642B6E874A06ULL, 
            0xAE1232DCB9268A39ULL, 0x3526D5B502B39ABDULL, 0xA6BD6222222038B5ULL, 0x5F4C3E0EA074BFE5ULL, 
            0x4EAD17D827670CE7ULL, 0x03FDE2B95CF39CC1ULL, 0x27B399310F0C5C80ULL, 0x3C684AED7857CA32ULL, 
            0x2675636E753A2C21ULL, 0xBA7C8F952B635F6CULL, 0x017CE4F6D8E3FA85ULL, 0x73CD7A2733D9B7DDULL, 
            0xA601513BD2BB2C47ULL, 0x2AB6B4DC2D3416F6ULL, 0x37F7A3C3B03F71B3ULL, 0xB05D506C77A46900ULL, 
            0x55F47C3393BF8870ULL, 0xE8284F264CBB3B34ULL, 0x17DD3658B1759A89ULL, 0x1EDCBA645BBAFDAFULL, 
            0xA2037D7834466C47ULL, 0xE0C412B8B1B1A211ULL, 0x804CAC93EFE730F6ULL, 0x3ED8EBC24CAEA3FAULL
        }
    },
    {
        {
            0x462B94FE3F6836DCULL, 0xB9621A931AABDC8EULL, 0x4DCF9881F7AC4082ULL, 0xF312BC2FC20B81E5ULL, 
            0xBEF80541C9CE506BULL, 0x96315EAB7DC10A9FULL, 0xC738A861136F4486ULL, 0x6BBD1C45BE243867ULL, 
            0xEFD8D58241A05443ULL, 0x739242D68CA4DE77ULL, 0xB029BB30CB51FB76ULL, 0x5368C1EB8D67E461ULL, 
            0x1D930CBBA6491105ULL, 0x54284733AF7128E0ULL, 0x70853398A7FF48F0ULL, 0x27DFB579B4221B73ULL, 
            0x7FA9049FE6FBA5EDULL, 0xD3A7E93957DE8C34ULL, 0x73430C7FEE2EB61DULL, 0xE35172B6E1C4D368ULL, 
            0x71FC2827C83AB5F7ULL, 0x863DD758220D9BE7ULL, 0xF52C2C4D379D4A15ULL, 0xF4C2579D318EB7ACULL, 
            0xF05296C8959F1BBFULL, 0x4C25542E5EE6D6A4ULL, 0x768C77D69409FEA1ULL, 0x96E6D6408DF5830AULL, 
            0x6C3C0E6FA17B7905ULL, 0xDC272B1451E3D8CDULL, 0x3F1DFCCBE456100EULL, 0x3DF32B01E29A19C9ULL
        },
        {
            0xC827953DD717EF02ULL, 0x9E70CBB0E9C74DEAULL, 0x5E80C247A31B772CULL, 0x655E048AD36AAE5DULL, 
            0x4A126D096F42A39CULL, 0xFE2AA3D4F72BC6DBULL, 0xFAB45E0DA510DD2BULL, 0x4CB6694968978885ULL, 
            0xE0CC9C58E53E8976ULL, 0x3E325883997545C8ULL, 0xE89DC60D1C286EBDULL, 0xF07971946E15EB26ULL, 
            0x752E8D9BCCB7A9DCULL, 0x5AA55D4418D85367ULL, 0x33D70DD4F769F37BULL, 0x9C93EFDF02E66E2EULL, 
            0x446FF6BC384F30A8ULL, 0xF8288E22817D8773ULL, 0xA804CFE2348210D8ULL, 0x444BCED2DCA52951ULL, 
            0x9AD1A65DE8AB906FULL, 0x0E3EBCF1B5F78599ULL, 0xA9BE4D3E7C0E7D9CULL, 0xC4BBCB5CEA822DF7ULL, 
            0xEACC3AD3B8312CDCULL, 0xB0C7504909B5FBF0ULL, 0x07FAB6DC4F4A760BULL, 0xD3E022C373BDD283ULL, 
            0x1F5673693FC4763AULL, 0xAB1E88816C5211DCULL, 0x7EF5AB8E4DC98B17ULL, 0x3BACD40B90166F95ULL
        },
        {
            0xAAF8B7B2E1E855A5ULL, 0x5196D79603C4D8FDULL, 0xA8B62C68DA5F68E7ULL, 0x9993B4523D17E8DDULL, 
            0xAF2DDAA52E869D98ULL, 0xD939FD077D51D89BULL, 0x24C2A1A7F382CA7AULL, 0xCE8FD6B702074E82ULL, 
            0x7ECD92051C9A8C7AULL, 0x04BBEE412224ADF8ULL, 0x52213D346BDE7D42ULL, 0x24A8B29D04F28CCEULL, 
            0x89CDBAAEC7A477E8ULL, 0xD1B2869C01CF7CBDULL, 0xE4FA03CFB578D194ULL, 0xE00ED9963934F1A0ULL, 
            0x3A87D8E39459950AULL, 0xD18E8682EC5DFC08ULL, 0x8939C78041275CE9ULL, 0x7DE52109BBFDFDAFULL, 
            0x4A3F90D645796A4BULL, 0xAADC8D439695C34DULL, 0x4BBB733792448034ULL, 0x10868D6FB92B87E2ULL, 
            0xDEE83156C6DF40E8ULL, 0x9A18028AED812CF3ULL, 0x760991C0245F0ED3ULL, 0xB5D1D7696A84E4C8ULL, 
            0xD51289E3B00B652FULL, 0xB0912B70F188C1C6ULL, 0x7C7ED38B2BB920E9ULL, 0x72CA466C348D6D7DULL
        },
        {
            0x76E543EE46F6DC08ULL, 0x05BC43746E1B52BAULL, 0xC75952ECEF8EE295ULL, 0xD663BC7139CFD854ULL, 
            0xEDD59178DFBB7F1DULL, 0xA27C7A89DD22820EULL, 0x8BA8A54C264D1397ULL, 0xB64847720A3726F0ULL, 
            0x27B9E2E5A6FF9C85ULL, 0x5F0B1C393626351CULL, 0x5686C1245F206CC6ULL, 0x7C2FEC5D9088B55AULL, 
            0x13805D94E6A7E608ULL, 0xCA59DA744B79DA34ULL, 0x69EDC11275B85BCFULL, 0x400940E9BEE01832ULL, 
            0x58C55AE012985809ULL, 0x210B05604879D8F2ULL, 0x58BA00AC45D3BD30ULL, 0xF4E46FE8CB593A0EULL, 
            0x86EF4B7F19320249ULL, 0x930E1F1E4DB1E72FULL, 0xC8A553258624755CULL, 0x1AFBBB46D29F6BAFULL, 
            0x6C8285834EDC3165ULL, 0x1836320DF15005DFULL, 0x9EF35A7750C310AEULL, 0xC70912932D4E46E8ULL, 
            0xC05F89FEA3CB5845ULL, 0x49FAE094357257BEULL, 0x25988DE8CA1E172AULL, 0x7BDC8303AF56FD04ULL
        },
        {
            0xA735C4C934FC0D75ULL, 0xDE8E4AE7CA26EA87ULL, 0xFEEADFDDB00C4D40ULL, 0x536DC3B5CD38C3DBULL, 
            0x1893D0BFF1865359ULL, 0xA9CC65BDB5C1647CULL, 0x647CE52C2753E5FAULL, 0x680B383C068BDBA8ULL, 
            0x910BFBED7162CC91ULL, 0xFFCA8CDF08BC5F8AULL, 0xBDB00FB5E8C80C66ULL, 0xC0DAA523B1B56189ULL, 
            0x55FC8A94BC2BE54DULL, 0x964950F79D2C0FE9ULL, 0x05F2F1D00337AB33ULL, 0x64E7408E186EE767ULL, 
            0x1201836F1385C83BULL, 0x676162E9F48430F1ULL, 0xD3803F96B9761A43ULL, 0x239B8EFCFCA5B980ULL, 
            0xF3A2F6C4F1F5E511ULL, 0x6E0FB55236AA824CULL, 0xC380501267257553ULL, 0xB67BC119F38F95BDULL, 
            0x6E52EC933401D38FULL, 0x9BD875A376257C91ULL, 0x711EEA793ED3DFABULL, 0xCE8430A2E771A539ULL, 
            0x7259F6FA9302F2FAULL, 0x29B28CA87D7A6C11ULL, 0x8EA3EF3509C3E453ULL, 0xD8EAE81B29005342ULL
        },
        {
            0x68867E53A094E3BDULL, 0xCA46ADE7393D429EULL, 0xB836D8BFD3F3469EULL, 0xB1A1334DDE9DE859ULL, 
            0x5D6663F23644447CULL, 0x156327E0B161A087ULL, 0xB4517B1DA812607EULL, 0xAEE34CA5C5436564ULL, 
            0x28428F8D25E256BEULL, 0x3BBE39DDB72FBFA5ULL, 0x6C6E69AE3AE5EBD4ULL, 0x7B03061C17575E6EULL, 
            0x25094220ADF9B191ULL, 0x9E3A366B055A4B7FULL, 0x55B7899F5854601FULL, 0xA1379481864BE8EFULL, 
            0xE31004CDA0C009E9ULL, 0x09772E2FA2F44831ULL, 0x6479A5F23FBEF36CULL, 0xFC36D656FD46DE29ULL, 
            0x274781DC160FEC26ULL, 0x9D325831D72C6821ULL, 0x4FB2E439F213393DULL, 0x6F340D7ADB673F21ULL, 
            0xEB1A792EFB978720ULL, 0xFB7935B1A6B83695ULL, 0xD841E9BF36BF6AFCULL, 0x2BD97D47D5CFEF47ULL, 
            0xE81FE2E8B72F7CBBULL, 0x5E66A3BCE38F166CULL, 0x3602546C7568A64AULL, 0xDF44DEB56D588250ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseEConstants = {
    0x621977C9854C9185ULL,
    0x4F766F02D15EE74BULL,
    0x1EA50ADE03FB89E3ULL,
    0x621977C9854C9185ULL,
    0x4F766F02D15EE74BULL,
    0x1EA50ADE03FB89E3ULL,
    0xB21B9326BF9BB995ULL,
    0xFBAB659E623458C7ULL,
    0x96,
    0x22,
    0xFE,
    0xD3,
    0x0B,
    0x35,
    0xCA,
    0xFE
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseFSalts = {
    {
        {
            0x4B4FE5F28311BF10ULL, 0x379856EC54C93B2CULL, 0xAFE9715E9E9B7B57ULL, 0xA1ED799351150C65ULL, 
            0x1ECD9B667201DB6EULL, 0x49C1F194CF51D7C5ULL, 0x409D31E3100167FFULL, 0xFB92FA381486BE84ULL, 
            0x3C60EAE016C0BAE3ULL, 0x6982ACF8262BF565ULL, 0x61D5786674E894EBULL, 0xBA6AE42A050402AAULL, 
            0xB08C2F4492980D85ULL, 0xDDE828ED5B8DB165ULL, 0x246382BC39367237ULL, 0xB8FB2754076A5A4FULL, 
            0x139AFF96CB389FD8ULL, 0x0D1209C9AFC3FE30ULL, 0xA6520252C378EF11ULL, 0xC9331F38CD46FBBAULL, 
            0xE07EFAF922158BA6ULL, 0xCEB516C1CCD14388ULL, 0x114879ACDCB7B864ULL, 0xA0A168011EFD5E88ULL, 
            0x5203D05D96F4AA08ULL, 0x9113E162CA7A2E40ULL, 0x3C70C7ADD056065CULL, 0x6378BF99730CEAE9ULL, 
            0xF5746FF3810DD8AFULL, 0x7E106626A637E2FFULL, 0x897CE8675D1F2BDEULL, 0x8F65304C28F016E5ULL
        },
        {
            0xDEB4831A3E5A8EE9ULL, 0x2775118C80EF71B1ULL, 0x0FA6F4665C672AF4ULL, 0x049756EFA8223018ULL, 
            0x463CB8B8E63E2389ULL, 0xEE26FAFC74D16954ULL, 0x05978510E1931B70ULL, 0x901A4896FD687867ULL, 
            0xAF5E63B7CC749F6CULL, 0x05970ED83E36E543ULL, 0x8FA250F5A289E5DDULL, 0xF23BD3F88924D793ULL, 
            0xF0C0E1D9CABFBE8AULL, 0x5D3F629CB1185622ULL, 0x3FFF438F13BE2E74ULL, 0x91C957142872EFDBULL, 
            0xE5F70DE8ACF245A5ULL, 0xB232817660C6431EULL, 0xC6A7023D5D68E632ULL, 0xA53E2A8961E3C532ULL, 
            0x4E1B3864C7936935ULL, 0x4480D700F4516A24ULL, 0x827ACA6B1D29E7F9ULL, 0x5A1DC3E9FADFDB0CULL, 
            0x74B162055AF84A06ULL, 0xA718FCCA12BAE0E6ULL, 0x160C252DBB7044FBULL, 0x96A3198FF7F15A8AULL, 
            0x048ACF1DA384A10CULL, 0x71B67BE29758AE01ULL, 0x0EF6D87EAFDB97FBULL, 0x9D0AB308F7248A2CULL
        },
        {
            0xE9886976C689CF46ULL, 0x8028375415744D3AULL, 0xFA6EAB4F227C4C89ULL, 0x4B1DFC3646EEA443ULL, 
            0x83D11E55548D9921ULL, 0x046D8EE3D074F191ULL, 0xF01F69E1E303B409ULL, 0xCBD33C33C34C06E5ULL, 
            0x5F58D8A2D1D91E46ULL, 0xCD634046C68ABAB2ULL, 0x6568BF427868D3E6ULL, 0xA7505F7BE894684FULL, 
            0xAEDE37F7103F1158ULL, 0xDE860DE9D93BE9A2ULL, 0xAB348479318161ABULL, 0x5F1603B743C9EFA9ULL, 
            0xBAF991AA5BC8D8E9ULL, 0x6AB5F07A0051737BULL, 0xE85B8E7BA9292A37ULL, 0x5F5843E8F34A4D66ULL, 
            0x3C392D9FD0DAA8F0ULL, 0xB2672D9B412070F6ULL, 0x88B6CF03F72D114BULL, 0xFC0C5E5E4744EFCAULL, 
            0x78AE56A902177A43ULL, 0x62184C1181F78538ULL, 0x5BE197B66C57EAD3ULL, 0x565C0775D6522206ULL, 
            0x79F9DAD318E65A8DULL, 0x0DDABD32137C3F14ULL, 0xBC2AE5BA3B6EB504ULL, 0xFAAB374EF5010291ULL
        },
        {
            0x648E3567066599A2ULL, 0x40FCD92EFA914BB3ULL, 0xAB9738045E991893ULL, 0x6182A54201AB2F15ULL, 
            0xCFC03A1830080187ULL, 0x9F792B80E5291ADBULL, 0x7B90A6772008F52BULL, 0x32179C0760A7C334ULL, 
            0xE54CA4176B0F5E34ULL, 0xDAD4C3439BE83EF7ULL, 0x6BA5AD89E831E52AULL, 0x3E6F0A661E26E5E1ULL, 
            0xFB88CC964BA0D4EEULL, 0x21414583E6EC1EB6ULL, 0x988C4A5E937D5DB6ULL, 0xA2C91235B4304EC5ULL, 
            0x1CE063DF9086C6E2ULL, 0x8C4054B318AC9EACULL, 0xF1CE5DA429A52A1DULL, 0x82E45A15D8BA1FA1ULL, 
            0x8DF98A1379D37073ULL, 0xA866D057EAA7F386ULL, 0xEE397E651518CA1EULL, 0x3E38166956BF722CULL, 
            0x07C33C225060CFE8ULL, 0xD620479F11ED5EA7ULL, 0x38CDF6171A03A912ULL, 0xC6E041AE8D09CD57ULL, 
            0xEDB4B14A4123C217ULL, 0x2EE9DF057036D51AULL, 0xC4F37EC0D9030BF3ULL, 0x07681A6B5318D6F1ULL
        },
        {
            0xBC8D5EB19670B094ULL, 0x95EACFE82A954D2AULL, 0x8CA90DE1912AC718ULL, 0x7F11CDCFD3312398ULL, 
            0xBC85FAE628A1ADC4ULL, 0xEC4D1B0939A7BAFFULL, 0x1C2E97FA6045C419ULL, 0x411AC0AE7CC31890ULL, 
            0x35275341C5910383ULL, 0x6EE02474F5ACEED6ULL, 0x709BB64953F56114ULL, 0x1859A71B7F97AE56ULL, 
            0xB4561ECCCDCAAA89ULL, 0x32CDC842CDF22C82ULL, 0xF471C7C6018DCFACULL, 0x2A081CC4AD061DF4ULL, 
            0x04A10F0E6B999D20ULL, 0xDB1EE594F7D70195ULL, 0xA2C963CA07FCDF7BULL, 0x2A6C2876CB62928EULL, 
            0x600702C3BDAD9341ULL, 0xFFB208B93F877303ULL, 0xEA1946FDF7F02485ULL, 0x50E3810C40A3AEAEULL, 
            0xED02B3E93D44639DULL, 0xDFE0A7F91ACD9491ULL, 0x4F8C131D6D380E34ULL, 0xCC06576593214FF6ULL, 
            0x065F73A636A052B0ULL, 0xF7DAF8AA1713FF3FULL, 0x716A1DB18E730AEFULL, 0x8E69CD3A32275126ULL
        },
        {
            0x6466647765B97409ULL, 0x8D2C7D66E0D8B647ULL, 0xC7C22486F56204DFULL, 0x710A09C10E90FBC1ULL, 
            0x7733B18E4B3A6D47ULL, 0xBF7A074F90A8B580ULL, 0xCAE8A9D471533F40ULL, 0xA68778884F85A79FULL, 
            0xE860669CAD67FCCBULL, 0x195342CB8726E71EULL, 0x32D0C15074CA2B85ULL, 0x6C14DA0F615C0A5FULL, 
            0x8F33E41C6B44B0C8ULL, 0x6D104BFB78DA91D8ULL, 0x749C933F695FD639ULL, 0x9EC9B514AF16CEBCULL, 
            0xA8CCC0C2E26F6C8DULL, 0x563576EB4F053E79ULL, 0xB6998BDA3FEF3291ULL, 0x7E9CB78CF53BB84BULL, 
            0xB245A7893F59139BULL, 0x978C174856FF8C4DULL, 0xC46B4613236EC503ULL, 0x6565B455CA70A910ULL, 
            0xEB6B013510A52B53ULL, 0x70F693054AED4F0EULL, 0x85CB52FCF06A889EULL, 0x748902D2785D6A42ULL, 
            0x5E4C9FB31B3BA8E6ULL, 0x45394C2195773BB7ULL, 0xA6AACA606500F88EULL, 0x44CBBCD7233DCF0FULL
        }
    },
    {
        {
            0xF2E267D00C53E9DFULL, 0xBAEE4F8AB62DC86DULL, 0x527E8D6438338C2CULL, 0x137B38DFBA99112AULL, 
            0x9C0237F49A127E8DULL, 0x84C2EBEBB0D3D7E8ULL, 0x100285EFCCE49468ULL, 0x7D3A53138B3BD51DULL, 
            0x879FB62F12825B06ULL, 0x81B49D0F935C996BULL, 0x746D6CCBC9685DFEULL, 0x92DF8D6FD1069A45ULL, 
            0x779F0CCE56162D0EULL, 0x3C45EA8C30446E59ULL, 0xB3BF5F3D16263A88ULL, 0x280EA8E8E02F2A0AULL, 
            0xD8BB258F217C74C4ULL, 0xEAB0ECF89D8AADCFULL, 0x70D200FEFA4651E5ULL, 0xDF8DE2586723B4BFULL, 
            0x9A12724C6E9031CAULL, 0xC2D5396318354EA4ULL, 0x0C1BCDF08A1E12D9ULL, 0x5687D2885B70B9D7ULL, 
            0xF1C606DB37962332ULL, 0xC0903A98633017CDULL, 0xE6B38326C0C0BDEDULL, 0xAF766084579D32FBULL, 
            0x51CB0084B0E3592CULL, 0x7B47E2EB8969D584ULL, 0x8350070EC8AFB1C1ULL, 0xB54D1E091C20C655ULL
        },
        {
            0x88F35EC1A329AB88ULL, 0x888EB29B280F0975ULL, 0xA9BCD4964B52A2E5ULL, 0xA2D02B8184E82D63ULL, 
            0x49CCA58BC7CB80B0ULL, 0xDC26E732AEEED4F5ULL, 0x70E4A3D46F7AB2F2ULL, 0xA7DDE4C9564217E3ULL, 
            0x52E50826427CADA6ULL, 0x5ECFFA171926440BULL, 0x274E736CB1D28891ULL, 0xFFB0EA520F812EA4ULL, 
            0x6986ED3A1420E51CULL, 0x699A78831D65A4FBULL, 0x7FF6C98F55624C81ULL, 0x4BF31335326224C7ULL, 
            0x672A182D4DC40E5EULL, 0xEB3947849403D410ULL, 0x65FEDEED3FFA6FA2ULL, 0x17D08D09A925DCDCULL, 
            0x3E22FEE60C187EA2ULL, 0x235B79BBC94F03EFULL, 0x1774CEDF2BF720E0ULL, 0xF9CF70C3D273E38EULL, 
            0x4265032AA9CE7AE9ULL, 0xA9E232828EA091A1ULL, 0xEC06FC2E4E2A182AULL, 0x25C4CCB540020DF9ULL, 
            0x4DC10E560EDEDB24ULL, 0xFB9C86E618D94E45ULL, 0xB8A78666118760E0ULL, 0x7DFA405BE05A22B8ULL
        },
        {
            0xF0497A5828173F53ULL, 0x926DC9E1D10894FBULL, 0x68CB2709689E1368ULL, 0x1EFDCA003BCFF515ULL, 
            0x7F33B3CFF43DC499ULL, 0xE3FB23EBAA6B5B76ULL, 0xB38ADDFB020C15F4ULL, 0x7F6BBA5B5B800EE4ULL, 
            0xEA7B1FFE327C3749ULL, 0x0967BBDDB62881BAULL, 0x5B39A1C8E881A7CEULL, 0x9EA7FCDBCAC82ED9ULL, 
            0x133A52ABAAD56E1CULL, 0xE5CF1BCA718D3DF8ULL, 0xDC029CCEEF12B9D6ULL, 0x67A1598F1B93CECFULL, 
            0x1CF37F39566CA91DULL, 0xD262A6B075CDCA64ULL, 0x86EDD7F6CAD8AB7FULL, 0x3FF035D04BFA5444ULL, 
            0x8482D88C93FAA896ULL, 0xCF2865FC914BCB78ULL, 0xB9D446A5010E7267ULL, 0xE8198DE5831B9FCDULL, 
            0x1582679C14FEAA20ULL, 0x3E7F7D71BCB22BC3ULL, 0xAAFD024F5AED8D25ULL, 0x6446EA9E93CC4303ULL, 
            0x01B644A8F8145FE9ULL, 0x6FB4BDD773916084ULL, 0x312BA80765312F57ULL, 0x41D17A0E1A925B79ULL
        },
        {
            0xE98D9035AA0ED9BCULL, 0x8009E7B7ABCCCCB6ULL, 0x41B08EF0B4A70479ULL, 0xB3FC81A0C53F6784ULL, 
            0x3377759A90C3D692ULL, 0x1F85203716F2B5D4ULL, 0xA1DAE351C0476B92ULL, 0x844882CB03221BC4ULL, 
            0x7699BE1EF396792DULL, 0x0F16990035D19A8CULL, 0x109F870B6A864F46ULL, 0x6967235CB1259D66ULL, 
            0x237C5C48188A2A2BULL, 0x8EE22F2705F29E24ULL, 0x81F5122296F65883ULL, 0xA2A0BC1EF431D430ULL, 
            0x426A86558D8A9A6EULL, 0x08D4F821C60BB7A9ULL, 0xF8BE1F3A89BEFBCFULL, 0xBD8592DA9D6A5B07ULL, 
            0x9EDF90DA19647971ULL, 0x22C49F04A40F981DULL, 0xFA88738F1BA77FC6ULL, 0x231AAFDE32D991B3ULL, 
            0xDDB695FAE1E93194ULL, 0xCC2721139C62B062ULL, 0xE517DAA8409DB59AULL, 0xD62466517F207DFEULL, 
            0x093965008A7A48B8ULL, 0x4B6ACB30A8048996ULL, 0x09FF7F0423D0E2B7ULL, 0x24F2FBDB18561B44ULL
        },
        {
            0x633E18219E37B3BBULL, 0x0A0E65D7DC1A728AULL, 0xC22AEC9708208081ULL, 0x2113132A4E16B58EULL, 
            0xA187B9085B711D8DULL, 0x75DA1FEABF5B2E4BULL, 0xA3E18C818E6FCAFBULL, 0x7703537C343DA393ULL, 
            0x61C88C14BA3CBCCEULL, 0x673C82E5A2979FE1ULL, 0x17EE0A3DF79DB676ULL, 0x195E475CBF003AA6ULL, 
            0x8674CBA684F636DFULL, 0x0CF04CCACBAC6826ULL, 0xB3DBBF6ABA909B97ULL, 0x8FA5081863BCEAE3ULL, 
            0x2D186C3A413C14ABULL, 0x41BD38998AD4961CULL, 0xBBD35B34954457B9ULL, 0xF694B3B2AA331635ULL, 
            0x8E24C81C29CB40C5ULL, 0x6A36A170AD460127ULL, 0xECBB8C4011E4183DULL, 0x9C672F2C72E5B013ULL, 
            0xCFCE37C83A922AE8ULL, 0x7EDFE37C845FE0E3ULL, 0x546BBE66B3A26AA0ULL, 0xC1658D68015F7B0EULL, 
            0x3ACB04FE8D5B0E52ULL, 0xF9042FD22FC20902ULL, 0x118CC1FA6DC0EA19ULL, 0xA2F3FDF57C745F4CULL
        },
        {
            0x15D0D1D252A69C36ULL, 0x60ECF344C1BF7894ULL, 0xA20EAE29258177B1ULL, 0x051E9D0C460DA79EULL, 
            0xFBED06A7D3780F3CULL, 0x2E853EA48FB1358CULL, 0x10BFA16ABC07774FULL, 0xD4174D33B7BC9FCDULL, 
            0x920386B081745483ULL, 0xA6CE33B1562694C4ULL, 0x658BB08347BCA372ULL, 0x7418C95E7F4038AAULL, 
            0xDE34E89B25AECDB7ULL, 0xCF92DCB794E9ABC3ULL, 0x1E5CCAC0FB085A8EULL, 0x958DF8C2BF673960ULL, 
            0xE2F87564EF5D1BB2ULL, 0x6F5B2A17A31327A4ULL, 0x0DDCE02C3D5A3DCDULL, 0x17806DB913F572A1ULL, 
            0x0A7215BEAF013AAFULL, 0x5E608B10EDE994CEULL, 0x8349F37CE6A5FD1EULL, 0xA13984FBC6ABC1E2ULL, 
            0xB55C596675734B59ULL, 0xB32189B1D077250AULL, 0x793B259770976930ULL, 0xC3799D413B2BADE1ULL, 
            0xD0E03C901D39EFC9ULL, 0x7DA3C94F8C98F5FDULL, 0xE395E3448F0A491BULL, 0x32ACB7E083003727ULL
        }
    },
    {
        {
            0xFFA828CBFFDC8BBAULL, 0xA49F64D1D4EACB68ULL, 0x9F7C4D6CC292FB66ULL, 0x00A89795AC80040EULL, 
            0x5AC6AC370395643CULL, 0x768792C9732355B1ULL, 0x2B9D01DDB45C3A38ULL, 0x25C6B1A9EE095CFFULL, 
            0xFABA408222819B28ULL, 0xDC1EE1E335B65FF5ULL, 0x20A9DCE35AD0AEE1ULL, 0xF6D1E8B1599A140EULL, 
            0x8969E8A0425926C3ULL, 0xD380FFF8ED1918E0ULL, 0x5A7F59ED4A68C93EULL, 0x301672DEC7A30CDFULL, 
            0x6A54C5B8138870F3ULL, 0xE05032B72755E4CEULL, 0x54827E20D4E226EBULL, 0xE344B982EB462B36ULL, 
            0x1A96B91D3B600CA6ULL, 0xB332EE3622505F2BULL, 0xFC0A372BB6FF7D35ULL, 0x3CC3FABDC6E08630ULL, 
            0xC1CACC6F4108EE87ULL, 0x0CE4126635EFEC83ULL, 0x83CE5D23910CECD3ULL, 0x111BB7A137FD5BB8ULL, 
            0xB2FC1EB9A2634679ULL, 0x1F140717F4DA40F3ULL, 0x2015A9B4261F3C42ULL, 0x6B900C671CAF86D5ULL
        },
        {
            0x55A364155AFB8C20ULL, 0x0D8947CA64FF0069ULL, 0xE9CEE8B4E0FBB4AEULL, 0xDB34ACF3F3B4EFD0ULL, 
            0xBA41B840770F340AULL, 0x9C6A5A47D1F2900FULL, 0xDD217E6B986E2E07ULL, 0x2B67946A0ECBE72DULL, 
            0x56EC53A087E27C2FULL, 0xB0E409B297073C2AULL, 0xEB52705A8224B515ULL, 0x36D1D0E15EA57BD4ULL, 
            0x65D6230E3B917F3AULL, 0x0D76017C7ED78184ULL, 0x6F856CB445855DC5ULL, 0xDD7E6B52F815BF40ULL, 
            0xB696E95A6FA06DABULL, 0xD2AD7B7BE965F338ULL, 0x91B1CD93310701E1ULL, 0x7B1FD433DDA6AA93ULL, 
            0xC94313044895E3D3ULL, 0x69E33760E83EDE24ULL, 0x75A6953316C2C058ULL, 0x406E80B417FA9E40ULL, 
            0x2669A36C66B6DFD4ULL, 0x072404A5A7918E8BULL, 0xD07EAE9D84C8A5CDULL, 0xB40B476977B34B8BULL, 
            0x883946A474450F06ULL, 0xDF066E481D72442AULL, 0xFE2FD87D77537B96ULL, 0xF8FF34EE390D26F1ULL
        },
        {
            0x0759DA9FDE076060ULL, 0x2D60EE18276F70FAULL, 0x7D3C7A75DDF6375FULL, 0xE224CAD534678ADFULL, 
            0x89D21DFCA8DC5D83ULL, 0xFC601A1E6EA6B310ULL, 0x860C2944515D841FULL, 0xF43935117BA62FEEULL, 
            0xFC8A6678DF3F4EE4ULL, 0x179A02D9773899D9ULL, 0x1C6980A71CEDE657ULL, 0x6DB0B4B000C4E792ULL, 
            0x585344DD8BA4831EULL, 0xB52DE2FD5DA63F7CULL, 0x7FD3FFAC48A89D33ULL, 0x889A556F841EE641ULL, 
            0x320E339F5ABEE042ULL, 0xA114C22CDE09CD8DULL, 0xCD668DBE008DE00DULL, 0x0A3C84F13683CD72ULL, 
            0x2D3594F81B9F947DULL, 0xC4A0A20034920B87ULL, 0xFA947BC97083FF4DULL, 0x2B9A5667D86A9F77ULL, 
            0xB10067337809B054ULL, 0xA96CECDC40DBE604ULL, 0x55B94AF776879F65ULL, 0x0257DAEA46CCDB7CULL, 
            0xEBE82DADD3B9E648ULL, 0x2AB2924894A9F82FULL, 0x0F5A2B5ECD62E549ULL, 0x8F51599BE2F77866ULL
        },
        {
            0x8F349B4213F73FCEULL, 0x0295D741BDD66317ULL, 0x529C787ED82F5045ULL, 0x7BC59B8B18721472ULL, 
            0xE372AB7E89492EECULL, 0x0F26ED8CF3CD212CULL, 0x6AE66A47E7021051ULL, 0x59F06EF29A96FEDAULL, 
            0x8AF45C66AC1FA829ULL, 0x388137654578BFEFULL, 0xB590891F51824080ULL, 0x1F47E8DA4627754CULL, 
            0x352702A1A50ABD89ULL, 0xB29F721023917C57ULL, 0xA050BF6C17C24FFFULL, 0x260CB95570D4E660ULL, 
            0x3B5883A2582F6B67ULL, 0xAEDCC40EE4BCEA62ULL, 0xE8BAA3288BBDB15BULL, 0x2FCEBFC071F394E9ULL, 
            0x3AC2EDC68196098BULL, 0x926605BE6814F0D3ULL, 0x4D96954EADF8C70AULL, 0x074F090A7DF4432DULL, 
            0x2BF7F6B7AFFFD024ULL, 0x518D428E4F83B78CULL, 0x98D420CD08A8E5F5ULL, 0x1EEB16228975FA36ULL, 
            0xC9B1F3F0B9BA586DULL, 0x2CC4B2ACA4A75996ULL, 0x5BF40863EC522702ULL, 0xF8ADC382D4F237D1ULL
        },
        {
            0x686D27DAE091D763ULL, 0x782DDAB89AF12B8FULL, 0x2D8D0816772E906FULL, 0x9CADAE40E88C1FBAULL, 
            0x14323579A8034892ULL, 0xAE2287A8C58E9669ULL, 0x399D8174DACAC148ULL, 0x1AF69ACB5031121FULL, 
            0xD3A1A7B0288B5407ULL, 0x665A82C177405234ULL, 0x80C125DFA50124D8ULL, 0xFF9B51FBA341F373ULL, 
            0x2894F135B68C76ADULL, 0x3F874C536083FAEAULL, 0x47531DB5EEDD4E0FULL, 0xAF3641941F2DCAD3ULL, 
            0x7BB24063ED975A6AULL, 0xF45002376B26FBFEULL, 0xB84D16C7588C67FAULL, 0x6F10E6100AA5E986ULL, 
            0x0CDAD8D90D8CA323ULL, 0xCDB8428A105BA72EULL, 0x1050B2DDDCC66A60ULL, 0xF2FBF3C121856D4CULL, 
            0x733AB4CAC2C9EA96ULL, 0xAFF9ACA3D3A118D0ULL, 0xB676200BD9BC6E2CULL, 0x5AEE876C6FB45DB2ULL, 
            0x60BB47D32124C91BULL, 0x97E6FC5DE900B448ULL, 0xD76B238D969C835EULL, 0xED0BEFE65137A816ULL
        },
        {
            0x00200086B63443A3ULL, 0xF3E0FFB7A904B706ULL, 0xEE201B552509FD58ULL, 0xD2A12DD56368A801ULL, 
            0x79FF446C3BE1D977ULL, 0xF544575E90E0BBCAULL, 0x63287121F15B7A41ULL, 0x576CEF60FB954BC0ULL, 
            0x034473AE1FF584FFULL, 0xD6C0E3377EB5E120ULL, 0x0EB046F8B536F112ULL, 0x5BD9FB088F35D72BULL, 
            0xDA3D3DDCF39F5775ULL, 0x5BC089F1A9C8182CULL, 0x5BB77B5049B44CC5ULL, 0x14350AB6ED999703ULL, 
            0x3D011AAB11814766ULL, 0x4620894DECAF318EULL, 0x371C96C9F96007DBULL, 0x2D40A6D4152420C6ULL, 
            0x3FC97BCA3655E167ULL, 0xEE6545454FC32FBCULL, 0x19B59C998E19B65AULL, 0x74B9CEA5592EA659ULL, 
            0xC92F8E152F4C30FEULL, 0x1810BDF5FDCA5813ULL, 0xCB7990D68A122C9BULL, 0x1B02DFD72BCB8042ULL, 
            0xC6D3A33FB429E02BULL, 0xA510BE170EA81C04ULL, 0x9B02DEE162AA5A91ULL, 0xC7C6DF3FFB98C794ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseFConstants = {
    0x6552E62F194A9502ULL,
    0xCFF8CC7490A904A6ULL,
    0xD06446287E329AEBULL,
    0x6552E62F194A9502ULL,
    0xCFF8CC7490A904A6ULL,
    0xD06446287E329AEBULL,
    0x0A38BECE0A281A6DULL,
    0x3922F86A968EFDACULL,
    0xAF,
    0x85,
    0x96,
    0xE1,
    0x6F,
    0x3D,
    0x10,
    0x96
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseGSalts = {
    {
        {
            0x37F91655558F5FDFULL, 0xA13196DD7A534A9EULL, 0x78DBD1B1793516B5ULL, 0x501F87155675CB72ULL, 
            0x0C6F0D14EAE97753ULL, 0x1B4C0A9E140C74D8ULL, 0x29F1B714A106973AULL, 0x54F4CB909C982651ULL, 
            0x3FE37A3186B3A6A0ULL, 0x97D31E24BAA3E4B7ULL, 0xA1B52DAB878E9606ULL, 0xCBFE57057DC7ABF5ULL, 
            0x410020F6983DDFEEULL, 0xE5CABABCD794228DULL, 0xE466B2F6681147B7ULL, 0x9C39AFCAA0600115ULL, 
            0x39A8E70AE64875C2ULL, 0xD8DD22522B9B5A41ULL, 0xE35D5CCA9F5077DDULL, 0x638633F2512C527CULL, 
            0x1DA4577ADF4BF0D8ULL, 0xA57F9C8A9E53F4D8ULL, 0x7E504F86C9A1A540ULL, 0x17C2A5405BE7800BULL, 
            0x9758CCC2B273D57FULL, 0xC596AD84E8D0003DULL, 0x3613E0AA01842095ULL, 0x32F062C598F097C1ULL, 
            0xA29EF8D3E2176178ULL, 0x4FAD25D92DF66ED4ULL, 0x402BF9D9EBE86CD8ULL, 0x20EFA59560B91635ULL
        },
        {
            0x40A6B9496CF1E1F8ULL, 0xC3D01D93F1B405B7ULL, 0xEDFECED5EE4BC15DULL, 0xC66B52485FC3070DULL, 
            0x55B6C07BAB4C3F3DULL, 0xA1572FB184E7E9E3ULL, 0x30526A83DDCDA7D2ULL, 0x8FEDE8D0D458EC8CULL, 
            0x3C4C73AA93CEB029ULL, 0xC798023037EC259BULL, 0x1EB11205D4B52EE2ULL, 0xFF19641DA5652251ULL, 
            0x57EE9868720852DDULL, 0x6CC0A91DA496E79AULL, 0x64342D8E4260FACAULL, 0x38224D290D9A5B29ULL, 
            0xBEBD2A17DFE60089ULL, 0x23E93B6B40D44481ULL, 0x2B51241B69401549ULL, 0xF7B35AA7DBF5CD95ULL, 
            0x227CC7024F6FA554ULL, 0xC1D6F8265EA3B315ULL, 0x65CB8D054BD81AE3ULL, 0xC3C1B09FE6E225C7ULL, 
            0x877009D81D578694ULL, 0x02BE67029E715688ULL, 0x6E4413B41F65734AULL, 0xEF8444AD4BDDE7BDULL, 
            0xEA0F0BC953BA0122ULL, 0xC208F2592F4D8B42ULL, 0x0304D91BC293DF63ULL, 0xA49AE9E55F78DAFCULL
        },
        {
            0xDF546004940EFF25ULL, 0x74FF848EAACD8457ULL, 0x34EAFD9CA7428375ULL, 0x0BCD664466673432ULL, 
            0x0CF06F9C84787EF0ULL, 0xE79793204B47978BULL, 0x21358CD37A1CD35CULL, 0xBB078F8F4F0696CAULL, 
            0x0CCD746BD71F0CA6ULL, 0xAAEFE8EC59803832ULL, 0x554FDB78A2E9B80AULL, 0x3B62F0C428A0C8A0ULL, 
            0xAEDA95DA9C78E0D0ULL, 0x84DE53C36CD3653AULL, 0x5C2B7B4FEC50FBB7ULL, 0xDB2A55A5D0DFAA6CULL, 
            0x5C18A75F55588A4CULL, 0x4DFAA8BD5284D959ULL, 0x19FA92AA7F87AE78ULL, 0x84C0208E9FD9E283ULL, 
            0x0A4842B937A323DFULL, 0x2AAAA324DCFD412BULL, 0xF873D8FEC86B131AULL, 0x0658BBDBE7F5FCFCULL, 
            0x62BCD4B33F4D84EAULL, 0x65DB545AD015470FULL, 0xDEF4161D7880D9ABULL, 0x8C2323FC77AA08ADULL, 
            0xE2498B10FB407D14ULL, 0x1D9127AB70EAFFE4ULL, 0x772ED0184B161F70ULL, 0xD0D9D4151FFFA98AULL
        },
        {
            0x85AEB81C023CB854ULL, 0x0B30A95B94F63A38ULL, 0x65FE0220F51B7B07ULL, 0x4DFD4C5525518EA6ULL, 
            0x7EB775F22CC27521ULL, 0x109E9BC93C67AFC1ULL, 0x0DDC04134E611DD6ULL, 0x6A4A64D3D415123FULL, 
            0x8CCAE65C9372CA46ULL, 0x0FA188C3AE4BC848ULL, 0xC61874E4F61A8FDCULL, 0x444FD126AF195336ULL, 
            0x977CA2A3C74C9D00ULL, 0xA153CB3F61791EF0ULL, 0x1558544176054E05ULL, 0x41CFDB158076ED33ULL, 
            0xEB26E219F1A79DDEULL, 0x0CDE427998907A57ULL, 0x57C8446CF29ED1AAULL, 0x55A6142E22B71E9DULL, 
            0x30E79672F4DD8F0CULL, 0xB8C96B600635D3EAULL, 0x4CCDE43EF65C2D94ULL, 0x416ACE1B70E03F00ULL, 
            0xCAE012D132C98799ULL, 0x6E0AF83B80F47178ULL, 0xF739BB92B469C7CEULL, 0x4FBD94F82A4F1F74ULL, 
            0x4644789EAC473FF9ULL, 0x15EDDD241EDDC1BBULL, 0x6F7BFD1ADAA72652ULL, 0x6F946CAB876AF886ULL
        },
        {
            0x828E0CCB6C35036AULL, 0x1A89BED0D1402A35ULL, 0x9F40F5908DB180FBULL, 0x8527FB4BEB64F085ULL, 
            0xE08BB81D3E434F42ULL, 0x191CEBCABBB4EE93ULL, 0xD418DDD99870C151ULL, 0xF5E23CAA2437330AULL, 
            0x5D86429FB0C914D5ULL, 0xEF50A46225D6DC14ULL, 0x01F40D993BE6CCA4ULL, 0xE219A6A69C43C934ULL, 
            0x73D879EEA2C0B9C0ULL, 0xB0A90EF42DB3C23AULL, 0x0EBDEFCE84AEAE1FULL, 0xD0543212EDC96AABULL, 
            0x10DDBE5C95843C13ULL, 0xD0BDC3B990E22440ULL, 0x9A814D6B5822F924ULL, 0xF3C3D61D51249314ULL, 
            0xC12BC59A98E307F8ULL, 0xA87FABAEF17ED853ULL, 0x4FD005DB7B748C97ULL, 0xFDAF6F726F79D71AULL, 
            0x76EBFECD995A8026ULL, 0x379949A4702DBC80ULL, 0xBAD63AC20D54D009ULL, 0x956A2C4D022B7137ULL, 
            0x0E14BAC280C6E9C7ULL, 0x37DB22BE58B15D04ULL, 0x46A8932B7C83BDEBULL, 0xF06D518CB352C823ULL
        },
        {
            0xEF4EF02CD8B77011ULL, 0xDD2C9CDE6BDF710EULL, 0xB903F71361692E35ULL, 0x7B04A33C38F46291ULL, 
            0x40B527C3FAD80368ULL, 0x9A820748047EE609ULL, 0xE469C5848897FA24ULL, 0xBF95416EB30E14F9ULL, 
            0xB1DF53C74E65AC87ULL, 0x5B53FF78C3F515CFULL, 0x11DB312259E2EC2CULL, 0xB9D1E6FE36A638B9ULL, 
            0xA05F064782269104ULL, 0x16EFAD014E50517BULL, 0x2A8B7B6C31B3F670ULL, 0x4E0350CC7E68E550ULL, 
            0xAAEAACD1495FC7D1ULL, 0xD414D07C3467841DULL, 0x2077F159AF3C2BE6ULL, 0xF5EA336BB664FB10ULL, 
            0x53D4456339FB201DULL, 0x947C93D32D10CFD0ULL, 0x104DF0B82F0989A2ULL, 0x78D8D792820ACD36ULL, 
            0x329972DE1FC32D3BULL, 0x87E3627C2E864FE9ULL, 0x459F00486ED37241ULL, 0x4F9780A2C9690C78ULL, 
            0x2ED49E47DF9B29D2ULL, 0x6AD96BC0CD9607BFULL, 0x097F394CC8E8173EULL, 0x901187AEA846D3AEULL
        }
    },
    {
        {
            0xA827A053A35533ECULL, 0xA6B1E7C8A5452FC0ULL, 0x2AB0EACDAAD185B4ULL, 0xC3BA52E4E33E187AULL, 
            0xEC52036449FA3175ULL, 0x4878691BD2BD4313ULL, 0xAF2BC4BBBAB5C4B5ULL, 0xA3FE55FAC15C3069ULL, 
            0xB2237BAB340D98C8ULL, 0x19AC71DAEE7ED647ULL, 0x409D9177E66420EAULL, 0xC63B61460A783CE6ULL, 
            0xFB07DB38AE4A3A33ULL, 0xAD0AB9D422A7AB57ULL, 0x3360271D46F02306ULL, 0x08EDF212AA60BF96ULL, 
            0x2A713FFE721D03D0ULL, 0x401D1C1294CFD999ULL, 0xE5152C2AF61FA94EULL, 0x7F4D0231769645FCULL, 
            0xEBB1BBB5D8A0315FULL, 0x590DDC65FE0E7DD1ULL, 0x8DB103639B2263CDULL, 0xC02A3098999DFAFFULL, 
            0xA6DFEB837569F72AULL, 0xBE4F599023658142ULL, 0x8A1ED6C89926A24BULL, 0x451CAD65EC8B06FDULL, 
            0xB49A75C17DF9F779ULL, 0x081655946140B062ULL, 0x94C9A2390C73EC40ULL, 0x4747C68691D73C69ULL
        },
        {
            0xE528CE9A7734CF18ULL, 0xA0E4D82A3CDB0747ULL, 0x95BDE681336CD6D4ULL, 0xD75B2B9A2D124807ULL, 
            0x260845CBEE466C72ULL, 0x5E348C17B3F5B354ULL, 0x8671BA14BD99AF51ULL, 0xBB72097576B23D1BULL, 
            0xC9088BEED68FFE90ULL, 0xFF1260C3A3E83A2AULL, 0x60FAC1F35E6876E3ULL, 0xEF401F80BF5999F9ULL, 
            0x0C16BD481F28CFE3ULL, 0x2A2198F6519B6613ULL, 0xDFA37F0BED8E64C7ULL, 0x7145E1F877D56E83ULL, 
            0xE16677B75B5511C5ULL, 0x940B278296E37D8BULL, 0xF0A43E2CB564080DULL, 0x5167B11713DD2E36ULL, 
            0x08683A3A6E90D171ULL, 0x0AE6279CC103B050ULL, 0x20F015EAEB73AD7FULL, 0xE05E87DB8F0B4CA3ULL, 
            0xA91C94EE55B9ED98ULL, 0x8FC577F22D511C82ULL, 0xCDDC437811803665ULL, 0x14DFC6D3F74C93E2ULL, 
            0x9631EDFA431DB356ULL, 0x05A6E9555B02998EULL, 0x4D31834902852997ULL, 0x239828C2A81F5D2DULL
        },
        {
            0x673DEF41DD981826ULL, 0x471CBB810075A4AAULL, 0xF8CAB38A9D7BFE04ULL, 0xB8EDC88BC4194002ULL, 
            0x9AB87BAF55FD5F7BULL, 0xED09BE7FD56DDA81ULL, 0x565C8C9A98B8954BULL, 0x2D1CED7454BFF4E8ULL, 
            0x463FCCC5B41CA26BULL, 0x68A5A7D334E556E8ULL, 0x77CC074A36F4AE1AULL, 0xDA9E407B3BA05ADEULL, 
            0x9D7C03701588A58CULL, 0x89EDC80DB91D21A3ULL, 0x861D8883A66E9E9CULL, 0x79198601CF1F0285ULL, 
            0x75A24062004A2B86ULL, 0x5C2AC7527CFD605CULL, 0x3E0B58E8065BDD3EULL, 0xC57B9C19A62E1F79ULL, 
            0x1F9C9C7F5236667FULL, 0x506E5EDBD9A46E1EULL, 0xCC4B67A22EAFA5F7ULL, 0xA2B99D56C0094EA8ULL, 
            0x6F1DE6881F613551ULL, 0xEE2A091E4535168CULL, 0xEC0E95CC33C7530DULL, 0x035EDDA3279AFAFCULL, 
            0xBFC490709B129406ULL, 0x0285E575639A14A3ULL, 0x78A78EEDD8C6651FULL, 0x43E3A8C50AD7E384ULL
        },
        {
            0x54F04B36968A5121ULL, 0x636415E0D462EFADULL, 0x0BC06D8166600ADCULL, 0x13B155ED27F20E8EULL, 
            0x59502BB81EAADA3FULL, 0x0E580B31D635676BULL, 0xD589D8A03771BD98ULL, 0x2419986A52A4B4A0ULL, 
            0xB9EE959D3A775EAEULL, 0x52454F5F44407397ULL, 0xE6BE4109DA31354CULL, 0x569592DBCBE34A22ULL, 
            0x88B6236DD347D3BCULL, 0xFE65D3670C48F1ACULL, 0x6DF8AA72CBF74C8BULL, 0xD969E816054FB685ULL, 
            0x9F869C5CD8903AF0ULL, 0x1DEA3F45B535BD10ULL, 0x764BDC0B0934EC77ULL, 0x6810F5DF73228D25ULL, 
            0x18BC232497EF7758ULL, 0x53554742005112D5ULL, 0x22BC19B371962EC7ULL, 0xCA107CBFDBD8B02CULL, 
            0x67286E72A27B0ECDULL, 0xFA2CB1E55AC9DA2BULL, 0xA7E19A0E8606B573ULL, 0x5C71E49587005E6CULL, 
            0xFDF0B135A0D13580ULL, 0x19E5BB918FDB54E7ULL, 0x0FB4B8CBBDFA6CCCULL, 0xD667140604DE128CULL
        },
        {
            0x66634E8ADAAF874EULL, 0x5FC7739FF4C544E1ULL, 0x19491649780FB604ULL, 0xA3CD18F8E014C4F3ULL, 
            0x7017AA4D7B7BB942ULL, 0xC49445C94129D429ULL, 0x15CB50A1E08B2A76ULL, 0x1C168299104A5BF3ULL, 
            0x4713B3C8F9644AE2ULL, 0x754DA703A5F7B149ULL, 0x5A9A8A727082A15EULL, 0xD2C2E526232F3972ULL, 
            0x8F87DA5F06548DABULL, 0x3BA009776A9FE219ULL, 0x3CDA237D268E127CULL, 0x345042E13397F619ULL, 
            0x1683C00DCBFE39DEULL, 0x414F276EB7BE93CAULL, 0xE07AD43997879644ULL, 0x1BED997533FA830DULL, 
            0xA4017449889EE281ULL, 0xF040120E66192A5AULL, 0xCBAE176A81CA0F9AULL, 0x7A1507A93F240EACULL, 
            0x7487A63AC1074C0DULL, 0x6525CE143C81DE2AULL, 0xD3452A04E31C90E0ULL, 0x5DEA42938369F2CBULL, 
            0xD91670489B117C4CULL, 0x0FCB46E5DA9C36ACULL, 0xC40CCD83EEC3F672ULL, 0x4AC936DFA82D935EULL
        },
        {
            0x09F6082051BFD99DULL, 0x482F0D8D196C7381ULL, 0xB139430C4C5BAD4DULL, 0x12C3958305A72F9AULL, 
            0x26E8FE4C1DD8D039ULL, 0xD8CECF75A23CCD1CULL, 0xF1347B161E1F9F5AULL, 0x44A08455E394449EULL, 
            0xACC6FFFD7540F45AULL, 0xAA390C9447D3FD0AULL, 0x0C291FFC9ECDEC8DULL, 0x7C921817D2D0515EULL, 
            0xB5BDA69128F1A32AULL, 0xA4F446404E4A7463ULL, 0x7AE018D16643DDC6ULL, 0x229D4EBA5F9E1DBBULL, 
            0x7466079375F6CF38ULL, 0x29B04B824C21BF87ULL, 0xAFACB5C5C5F6F5F1ULL, 0xC5E2A16432A4358DULL, 
            0x9EDD9EB27B6C1D72ULL, 0x1E4D478BAC24AACFULL, 0x8A41DB7E92F1E794ULL, 0x91E81995A95AE360ULL, 
            0xC28D746318FEB978ULL, 0x9C530D21BECBC1D2ULL, 0x323C11863AB52D72ULL, 0x6135B1550B0D8CA1ULL, 
            0x20A4A3A97DAADA45ULL, 0x7A4AF04B006D221DULL, 0xBD272D4EB3EE71FCULL, 0x8B006B4E95AE15EDULL
        }
    },
    {
        {
            0x73FEEA63055201EBULL, 0x378B34C83E97C0E3ULL, 0xA7FA92B4FD231AAAULL, 0x19AF8D8158A7779EULL, 
            0xD0010F125DCAFF9AULL, 0x76FEBEC31F81880BULL, 0xA8F3178C9CCBE553ULL, 0xDEBDAD782D2CB307ULL, 
            0xF5BA3D89BC73CC2FULL, 0x0B774087C720937CULL, 0xA8B226946336405CULL, 0x1852971F83930377ULL, 
            0x9F4DE830B037D5A8ULL, 0x7F629A258DDF7F02ULL, 0x21AF43425E2C8D47ULL, 0x52D6A8B1E7125BC6ULL, 
            0xAEB797333CBEFBE5ULL, 0xCFF8A3593BF1F54AULL, 0x1F69C2DF68E0840DULL, 0xC62E77551714456DULL, 
            0x3202E2A61174E2CBULL, 0x984F4BBB533C144FULL, 0x7843D9FB6F637E99ULL, 0x5AB466F0514DC33EULL, 
            0x3F1A3558FDE06978ULL, 0x20CD908C06A31496ULL, 0xC0506C4556D6D3ACULL, 0x1E9E09C42820434DULL, 
            0x15968A257C725707ULL, 0x18E348059E71370FULL, 0xEF0BD973D342A98CULL, 0x821672FABDFFBEF0ULL
        },
        {
            0x3204D70E78DD2F0CULL, 0xC191C6C943893BBFULL, 0x70077C54710FC45BULL, 0xDBBF48FF13F16D6CULL, 
            0xFDAA22376C33E1C4ULL, 0x15E66DB534DD131BULL, 0x32189F241CAF1F85ULL, 0xA9C1E0CAC387AAFFULL, 
            0xADDD443633EB7269ULL, 0x612C08834D7A81B9ULL, 0x24D89EC082499D4FULL, 0x0470C2CE8F4A93F1ULL, 
            0x03C6EE77593BC3DBULL, 0x490DFB7941714ACDULL, 0x454C4B646B91C6EBULL, 0x4429EC6C098C5146ULL, 
            0x62399C27DB8AC4BBULL, 0x2CA60B8E5CE80A92ULL, 0x48C71844A76F3C7FULL, 0xB68C6557E42B1A2DULL, 
            0x9060A84C7C79C804ULL, 0x8147E3A242939869ULL, 0xE9B5B48B71F9B0E8ULL, 0x1B363352ADD26931ULL, 
            0x5C756059B54E7209ULL, 0xF4C184CFFE65FC49ULL, 0x67E36B7F04811063ULL, 0x3143F06B313F9D5DULL, 
            0x472B115A5D1A9C4FULL, 0xEECE9C43C033BE04ULL, 0xBFB48074C6A05E77ULL, 0xE406E04B53DF3188ULL
        },
        {
            0x6E5EE82E44A72F2CULL, 0x00B7DE0DF7538238ULL, 0xD6856B33E4ED629EULL, 0x3A2B3044521F7C00ULL, 
            0x5598EA6575C3D6B7ULL, 0x9E70A1324C384D65ULL, 0x7B1886C9A3D82FDDULL, 0x7B4D8F4BD3EAB6E9ULL, 
            0xA357BFF8CFC31C9FULL, 0x5079F9FCEE9FE9C5ULL, 0x0320CC6318B1B30BULL, 0x907BB9BA50ED6178ULL, 
            0xE9E4434AA9D8DCC1ULL, 0x5ED6D91B030A2418ULL, 0xA47E4959E09592F2ULL, 0x930CA16DC94D29C2ULL, 
            0x8927ED60F1EFD649ULL, 0xF5A1224EA3C8E78CULL, 0x025AB568721B6BECULL, 0x9F97ECCAAC051D6CULL, 
            0xA4CEB66FB6CD60A3ULL, 0xE97D38EAB3C295CFULL, 0x7296EF4B371BEC06ULL, 0x033CBE9089B71941ULL, 
            0x01503101AB342CADULL, 0xCCFF05A2A6E4963EULL, 0x7C2408CC77E675C1ULL, 0x58908F637A0E14A2ULL, 
            0x847C196F56F82093ULL, 0x62FC2634CCB7F397ULL, 0x467543C33B6C5EE4ULL, 0x203478A6B9641C26ULL
        },
        {
            0x720DEFD3275C5B30ULL, 0x408C6DA7C6A4C173ULL, 0x7F0A460B8ABB1BA2ULL, 0x96DF62252348F578ULL, 
            0xAB1C9A7356EF3049ULL, 0x0DE06A10FB55294AULL, 0x1CE22BE0B9E9461CULL, 0xFEF1ACBAC3D49721ULL, 
            0x11EDE407727CCAAEULL, 0x7F1B7044EDB96B4DULL, 0xC0BF202DEA38EA9FULL, 0x43CD479FBF5D5DC0ULL, 
            0x72FA5DBB2C5C9E0AULL, 0x9237B8059FCE99B8ULL, 0xD610FF7804ADBD74ULL, 0x5E7EE61CA3ADE726ULL, 
            0x1AB59F08CB7DB05EULL, 0x612CF8674E4B860BULL, 0xBF904DF8C1E2EF42ULL, 0x6C152527EB65F3DAULL, 
            0x90C09436E0BA786BULL, 0x4A1F3A0B8A740205ULL, 0x435DBB8F571ED7D7ULL, 0x06922D9393845621ULL, 
            0xD3784F8728B846EDULL, 0x75561F79559F56A8ULL, 0x453E11892E5D752EULL, 0x51A231CE8F35B065ULL, 
            0x8B278BD8E02E5709ULL, 0x839719B8BADBB881ULL, 0x025452666412E76AULL, 0x051D3DF5EF0CD6F4ULL
        },
        {
            0x57A0B52240C3E6DBULL, 0x3222F4817AC66495ULL, 0x4BED42DB4EF1402FULL, 0xF99C9FC5AC2D7B2CULL, 
            0x75E375EFA0DACD2DULL, 0xB72575326A91E665ULL, 0x389F1EC2BE5BAF92ULL, 0xD83EE501FE15A358ULL, 
            0x4DB09FAE25B4CC71ULL, 0x3BB9DC55ED7677C8ULL, 0xAD9F65389E975803ULL, 0xE555E0CB770CE03CULL, 
            0x0A8D01535AF8FE65ULL, 0x4AFDC2779590BEDFULL, 0xD0F74686461C2432ULL, 0x78D9296F3F638F92ULL, 
            0x42AFDEC77ED46A95ULL, 0xBFC5BEF6979C6FA7ULL, 0x07D5439347F39C62ULL, 0x6FAF7D183C61D600ULL, 
            0xDBF75F975AF3BFA9ULL, 0x55676D34F12C8CF0ULL, 0x440ED8E703767160ULL, 0x62D31964AD1306EBULL, 
            0x3474ADA6131A26A7ULL, 0x10C7BA7F716AFF87ULL, 0xD0D292D1B4A67344ULL, 0x3B2DEA493232DAA4ULL, 
            0x60566BED35355724ULL, 0x9B34A04A7627ACA8ULL, 0xA9B609E50E4D7CDFULL, 0x11D5DEA0364C2C0DULL
        },
        {
            0xD0B9A75725ADBB68ULL, 0x97CA959ADA7867C8ULL, 0x596021B74950905BULL, 0x46CA3CD45F629BFDULL, 
            0x781D264A3FB7C2FCULL, 0x2CDFBFDE174C34EEULL, 0x5DEE66C652186B17ULL, 0x590F327DA569BB66ULL, 
            0xFF712AAD3F0BAFD0ULL, 0x75DF4503DDAE4F06ULL, 0xCB9EDC5222C2DE94ULL, 0xB8861CE52C821DE2ULL, 
            0xD4CE6338555EBAC3ULL, 0x9E31931CF65AECF4ULL, 0x14E6B5107603BF83ULL, 0x6EAAF90A47C8B981ULL, 
            0x94DDC11FF5F1655AULL, 0xB4E46E8A9CD1E4B9ULL, 0x389B32F0E9FCDF19ULL, 0xFC48D7368E1E1F8EULL, 
            0xF815BEF7E7A8A54BULL, 0xC5AD165CB0CCBE8BULL, 0x69D555DFEC6A2A79ULL, 0x05EAD89FF222BC51ULL, 
            0xE0EFF4C5F64E7E2CULL, 0xB3952E16242959DCULL, 0xAE8FE276960FDD44ULL, 0x6E291FF23096E79FULL, 
            0x176C51517FCC11CAULL, 0xE8C8365A9BE3F13DULL, 0xF664C17814C68F37ULL, 0x79B58DEC590A295CULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseGConstants = {
    0x2837074C832C02A9ULL,
    0x055A17553775A2A7ULL,
    0x984ABA45C1409ED1ULL,
    0x2837074C832C02A9ULL,
    0x055A17553775A2A7ULL,
    0x984ABA45C1409ED1ULL,
    0x10D1134707C74A28ULL,
    0x96F5F5FCBA067AFAULL,
    0x3D,
    0xC4,
    0x04,
    0x6E,
    0xF5,
    0x37,
    0x75,
    0xFD
};

const TwistDomainSaltSet TwistExpander_PickleBall::kPhaseHSalts = {
    {
        {
            0x450AA39305602825ULL, 0x3BA0233BDAFA68B6ULL, 0xD2CD22656206125AULL, 0xA7F3F71D02513CEBULL, 
            0xD3BC1986B5C6A7A7ULL, 0xD16B276CBD15F748ULL, 0xA3650D62226E1E81ULL, 0xC4FE9D5691103CD5ULL, 
            0xC4058DDC415905A6ULL, 0xE3DEFA859ACDE8C7ULL, 0x5C843531B61D3707ULL, 0x57CF6F3F8D5AA40CULL, 
            0x7996A2F99338FAFDULL, 0x0AEFE0FDA18D6D7EULL, 0xB3C6ADC9D7931035ULL, 0xC49C57623C3D4DFAULL, 
            0xDA1FC154B8AEAE21ULL, 0x4990BB3B255E771DULL, 0xE3BF69D9D8319A46ULL, 0x175F9C2C3F6D39D8ULL, 
            0xE9E3A1A9599C2C04ULL, 0x167884B68B0F0B36ULL, 0x4B6FC8AA7ECEECECULL, 0xEE01830794DF3929ULL, 
            0x3346A921582AB8CBULL, 0xF7889CD064E90BE9ULL, 0xBD4E78D62FA6F831ULL, 0x29CC794606B7B36FULL, 
            0xAF8FC00780D509FBULL, 0x2FB4528C04B17772ULL, 0x1D87240C6E5D854CULL, 0xCF0C8D17993AF73AULL
        },
        {
            0xE1F605ED79B16BF2ULL, 0x86C73F7DD23BC396ULL, 0xB0EE932C18C7C053ULL, 0x9AFD7F9E0816A8CEULL, 
            0x6B41A98C1FD8EC58ULL, 0x9E30C1B65A999487ULL, 0xA073FE2184B40393ULL, 0x190EC74DB79364BCULL, 
            0x076534F9DE83A412ULL, 0xE77D48BBEA273F97ULL, 0x630AB169D507FF3FULL, 0x02BA2F6DF6CA3D95ULL, 
            0x244B1B0E91AC800EULL, 0x57282969F9926CE8ULL, 0x216B2CD81CF768BBULL, 0x464C8BE9FDC354DBULL, 
            0xCA783109A3209997ULL, 0x52FD26F0DE6CA88BULL, 0x6FE854A1C44C3B7DULL, 0xB3BD1EB6BB95FD10ULL, 
            0xF4D240E3F7BAB3FFULL, 0xC82A653E27C1DAE6ULL, 0x205BEAAFF37D74F3ULL, 0xA79FF9ECC4928260ULL, 
            0xCB8E1FAD1B7A00DEULL, 0x8860D386D7EF8CE2ULL, 0x831BDFF2C98450B6ULL, 0x16863BE19E916F32ULL, 
            0xB5DD80C76B226766ULL, 0x739A382CF5DFE9DFULL, 0xD4A96DE9FC2818E1ULL, 0x43EC36027429EB07ULL
        },
        {
            0x65B0E050973DBAB7ULL, 0x6826F29F8AB1B955ULL, 0x3C6848B4689073A9ULL, 0x0E6079953ECA324DULL, 
            0xA203075D1C82540BULL, 0x44FEE40679D6FBFEULL, 0xC6CAD76F3CE9071DULL, 0xED74FE5FC84A92D1ULL, 
            0x6BE0E09CA4CADFD1ULL, 0xB47E846853C52243ULL, 0x634064AB66C0C638ULL, 0xE266110956907392ULL, 
            0xBAFA155C7C2322C0ULL, 0xB8453D969C6BD66DULL, 0x476419A54A582288ULL, 0xB4F0F1149EE0F796ULL, 
            0x2D1EDB81ADDA5EC0ULL, 0xDDAD56A26DF6099EULL, 0x8667A4FE97B5F610ULL, 0xEFB7BBC0939E48D3ULL, 
            0xA9D6D7CEF5339577ULL, 0x29B824BDBB1E2000ULL, 0x57EC58536E76FD4FULL, 0xBC1A8EE8EE618ED3ULL, 
            0xE82D6FD0E7454748ULL, 0xC3C28063B28E3F31ULL, 0x69DE7BFE894B6746ULL, 0x7785D5BEF9AA3C94ULL, 
            0xFE264CC9C84F5894ULL, 0xA40F6554518B3A85ULL, 0xDC14A921C67E8328ULL, 0xA24F8B54ADCF9E44ULL
        },
        {
            0x8D9AD0703635799EULL, 0x7585D743A5EDBC1CULL, 0x2C5D47636F721DD7ULL, 0xBE3DD5301A15102FULL, 
            0xD291491B3CD9C229ULL, 0x4E145487C1FA511CULL, 0xF6CB95166E01E8A7ULL, 0x0A52660BC1D600D2ULL, 
            0xFBF2549787CFBE8EULL, 0x323FE77CD6AF4C85ULL, 0xFE7948F6D35C64D1ULL, 0xB30169A6040C0670ULL, 
            0xAB5A438EDB32FCFCULL, 0xF23DDE9113C719CBULL, 0x086FF45B91C00937ULL, 0xADC329CD9DEA4BB7ULL, 
            0x5B1EDDF3A97DFB38ULL, 0x6DA9ACADE4739184ULL, 0xEF4E74CF04C0109EULL, 0x2903C907D621563FULL, 
            0x230983F0890BA62AULL, 0x1E7C7E53D196786CULL, 0x7AA208C4901D1B38ULL, 0xA53DAC3922460071ULL, 
            0x032CCD8040ABE2AAULL, 0xDAF2D28DAA991656ULL, 0x2B6F739A84240145ULL, 0xCC3500FF3BD1A9ECULL, 
            0xE737A1F782286D51ULL, 0x9D7EE417DAE290FAULL, 0x394D2C2310F70CE8ULL, 0x0B78B84C34FBC074ULL
        },
        {
            0xA39F13729622FBE8ULL, 0x70FC0BDE09907715ULL, 0x069A7EDBEBA6F9D9ULL, 0xDD19247454193058ULL, 
            0x69044E0527B188F2ULL, 0x1D2858061AF0A856ULL, 0x0DFBAECA71B5D943ULL, 0xC94CC98CFC485C0DULL, 
            0x366B3FB69BE15E7DULL, 0xD5C33BCA9445E21AULL, 0xA038A5AA37B037EEULL, 0xB4018D581FF30F07ULL, 
            0xB255E9F79BDCC1ADULL, 0x07C3B0DA00E25EEDULL, 0xAFF993FFB4857BC4ULL, 0x4C5557F403D5461AULL, 
            0xA807F9A3EE88B773ULL, 0x7257FC0340C2E96FULL, 0xD867546901B467CEULL, 0x0F70B71993448AC6ULL, 
            0x1D70FF5A38AA2209ULL, 0x2E2C73BAC95F3A84ULL, 0xD5193FB2087AE6D9ULL, 0xA5AA3AA72339FDEBULL, 
            0xB635FC17459079DDULL, 0x12FBF31FFC03FE95ULL, 0x0EBD396ABA55ACF5ULL, 0x2C00123F7740FD7FULL, 
            0x7A420AC7FB572C2CULL, 0xED73A1872AB40C6EULL, 0x887CF3B0F9B4FEA6ULL, 0x2B2B65E659ECFBC1ULL
        },
        {
            0xBF578D46EDED04BBULL, 0x55D4BBE1DA79B3D4ULL, 0xD8733B8B4153804FULL, 0x9DC6C54F4C1917C2ULL, 
            0x8380D9236F7CB27AULL, 0x8A473D3EB16FC51FULL, 0x84B53496106A4464ULL, 0xE2FCADFD3DD253B0ULL, 
            0xD3E9025E9F9DC988ULL, 0x449E66372B332FF8ULL, 0x5BA29878C21C35D7ULL, 0xC1B48B7461F58B8AULL, 
            0xE6A96B0BC8DC90ECULL, 0x214CD1D4D2A896FFULL, 0x611DF407A7479D9EULL, 0xDDEAD2778C769A79ULL, 
            0x436FE57FB8638405ULL, 0xC9C68BB0BCD9B029ULL, 0x5AB380938A55A684ULL, 0x8AA68777D87423F5ULL, 
            0x5919536C28F9B648ULL, 0x9951F634C3848C81ULL, 0xDF6A61B011169247ULL, 0x879FAED98EA9D62BULL, 
            0x038F530A0BD80B45ULL, 0xED7DA00CDB270308ULL, 0xD264012CBE8F3266ULL, 0x21A9A62EEAAA6093ULL, 
            0xCE5907D4BB5D4517ULL, 0xA5581EB3CAC481ADULL, 0x4FB53E84AD206EF0ULL, 0xF29D34B802435E3DULL
        }
    },
    {
        {
            0x447151AB6BCBEB22ULL, 0xCEA8ABA6C746018AULL, 0xD52FA54BDAD48B8AULL, 0xE8241C53EDBC73E8ULL, 
            0xB83ED75A297917E9ULL, 0x6731C0B9573A69C7ULL, 0xAA712F35951E9FF4ULL, 0xD6C34B404CC898A7ULL, 
            0xD47EC6EC408C565DULL, 0x9FF374C832DB2F68ULL, 0xDAE33191D63ACB32ULL, 0x638B97C3DE613825ULL, 
            0x634B98CD94B95BFBULL, 0x6B4EBF20375B9E9FULL, 0x3ED7790FC8CF3D7FULL, 0x38855F0007A75930ULL, 
            0xCC753E654F321532ULL, 0xB031884F8DC8BF3BULL, 0x9E45AE72CE547514ULL, 0xB5FF8F272853F35EULL, 
            0xB1D4CDC12AD8FD76ULL, 0x1A3F7F798AEBF02CULL, 0x93DCB4EF96555970ULL, 0x8F591243FBC8854AULL, 
            0x76537357B0587FE3ULL, 0xD4632BE00C9B7DB0ULL, 0x55504D84F7F32D22ULL, 0xC117F89837DE6E0FULL, 
            0x74837BD282B096B8ULL, 0x1184A968385F409BULL, 0x329E72239AB0BAF5ULL, 0xC152E8A7148ED149ULL
        },
        {
            0x98B662EAB410DB98ULL, 0xA33B366323FC31FAULL, 0x93D0A46F7C1E23C4ULL, 0xCF227C159C31FC24ULL, 
            0xEAD975E723322D08ULL, 0x0DE7541AC4C61EAEULL, 0x708292BE9FA9BA79ULL, 0xB9C520261F06715FULL, 
            0x0E4D19F6C8EE94B1ULL, 0x339691DBCA65306CULL, 0x684A2A74B39AC173ULL, 0x40462C96E9C05DC3ULL, 
            0x9E5F3BAD3DEAD322ULL, 0x12C27D4D31999DFEULL, 0x6E958328CD455D3AULL, 0xF7591D4F850C8B4FULL, 
            0xEC4AF784DA3E7D2FULL, 0x5A1065693B1FB35EULL, 0x2D497D8537DFC5C9ULL, 0xBC2184194ED3A04DULL, 
            0x8A934D045DABBB30ULL, 0x3A209AAB7ECF3155ULL, 0xC32E03E09332F381ULL, 0x9409F82D0C36AE5FULL, 
            0x2A2CED34EA7D7DE3ULL, 0xE6D0241C21FF1C2AULL, 0xFB8DB6B04421CA3DULL, 0xC3BB6DED46ED64EEULL, 
            0xD4A4D8C2DD7E8C7EULL, 0xB2FBC396A1C53697ULL, 0x9522F161568F6B92ULL, 0x91E7DF7E19F6179BULL
        },
        {
            0xC782AAF283C07902ULL, 0xDB6A77B74E302A4EULL, 0x554963A7B32F11C7ULL, 0x6C19138FBF0CEA08ULL, 
            0x1A7CE02BEE996179ULL, 0xCDECDEF4E900AE08ULL, 0x65C84521188662FEULL, 0x233094A02225CEA7ULL, 
            0xE722D5A6D99BF14AULL, 0x2588190167920C84ULL, 0x7BB4F4B28A2182AFULL, 0xBD291ED623A445AFULL, 
            0x4564D80272413C3AULL, 0xFD94E4AD0CC2A079ULL, 0xDEC864EA733D4317ULL, 0x44E827E06ADBA4A3ULL, 
            0x18ED9D2C1C37E4A2ULL, 0xABDBBFB3C996C938ULL, 0x3259C5DCB29EAB07ULL, 0x8212A25503615D8CULL, 
            0xC31B82F75EAC8326ULL, 0xD17F921C2769E385ULL, 0x3CC65D5C5B301305ULL, 0xE92634AD575FB99BULL, 
            0x831A5ADE75EB53FFULL, 0x596FD9E2338FD702ULL, 0x7F9ACD543E3D6330ULL, 0xF1CBAE06B5B3DB14ULL, 
            0x559253A064B94113ULL, 0xC31ECC8D4704A90EULL, 0x2FA7204E175DB2C3ULL, 0x833354B7CE6D4014ULL
        },
        {
            0x75BC8ECC48D104ABULL, 0x2DC8D8B350CC6795ULL, 0x8793E1589A608BB9ULL, 0xBCFA22FFBB1D5AFCULL, 
            0xBC0ABFCA27882480ULL, 0x43FA2D7B732974C4ULL, 0xEEA1AB18C2893FD5ULL, 0x8654605B4EE7A1C7ULL, 
            0x7CF952FF8AB56F9AULL, 0x458F2026E0EE354CULL, 0x24563188D2C5611EULL, 0x3ADA47E579AE375AULL, 
            0x08A05878DEFF5399ULL, 0xA7FDEB2F289E4D84ULL, 0x838C8F7D956C506DULL, 0x64492975EE8FFC3DULL, 
            0x931E37B1A3038F14ULL, 0xBBD0CE6EFFB65EFCULL, 0x1281EC3A6CECA52EULL, 0xC53535FCBB3EC6EDULL, 
            0xD41ADE8336A580CFULL, 0x26FB0709C8017558ULL, 0x32A5A518ABB17CECULL, 0x6FD6AFC378B908BAULL, 
            0x5812DF4FD0CF2F07ULL, 0xFF450827B1F93957ULL, 0xDECECAF2E2E21B88ULL, 0x12164D906C48503BULL, 
            0x34EB7355670FFEDAULL, 0x4E5D405DBE8895BEULL, 0x33FA49871EE980EEULL, 0x21D3C81F2E57AD16ULL
        },
        {
            0x7EF778E56175A763ULL, 0x1C9FCA0A69D03A74ULL, 0x0389174B3DFE2EE1ULL, 0x705CB8A9CEDEA73BULL, 
            0x3855BF58D2637DA6ULL, 0x9BF73AB5D689594CULL, 0xE7E2A24325FE2953ULL, 0xD2CC2702E397C069ULL, 
            0xFEEC9A138FF7D957ULL, 0xEBF6E534187BCA64ULL, 0x7C151227A41457F0ULL, 0x74288A42E113CCB9ULL, 
            0x2F8D92ECA8DBD950ULL, 0xE34F0EFE33B0A527ULL, 0x67F400649DFACFDFULL, 0xCC8FA09297B94C85ULL, 
            0x669D47BCCF180539ULL, 0x704489D7D5D9EF30ULL, 0x965D28DA41EA29B5ULL, 0xCC80BC1666E92741ULL, 
            0xEBB5B090F4096356ULL, 0xC9C5E3AC8AC81F37ULL, 0xC23BCF60B55DF7E4ULL, 0x67BEA4B0AF04A2EDULL, 
            0xB0EE9F7507F3B5A3ULL, 0x5CF523D65E3A3CA6ULL, 0xED8679A168C01031ULL, 0xC99183E192557E97ULL, 
            0xBDC66BAA7505F9ECULL, 0x57F03AD90E167674ULL, 0x6CC137B5CC5A537DULL, 0xC826E529761C1860ULL
        },
        {
            0x4A1A9D4C7B638F29ULL, 0x02F29F5C411B77F5ULL, 0xCDA99DCCCA7BF678ULL, 0x7AB551626CFFB660ULL, 
            0x2769FEECF5C2D4DBULL, 0xC3F2AD9A60A40BBAULL, 0x2EE8788A1D2FB447ULL, 0x7E90ABC0FDC13AEEULL, 
            0x8CC98C0FA221BFC8ULL, 0x85756D39D73BDC7CULL, 0x9640325B262B0623ULL, 0xCE5804AC6ECBC969ULL, 
            0xD22C8BBF527929F3ULL, 0xC3BC1504CB50872DULL, 0x6A07043F23C20735ULL, 0x8F5C63AEDB176251ULL, 
            0x2B6D0FCB6A73DF20ULL, 0x14D853BEA69E98FEULL, 0x3F37664388BCAB31ULL, 0x39B54E9F8C369FFDULL, 
            0xA0F6AD6102955C6CULL, 0xEE6BDD8B3556C710ULL, 0x78038AD64714ECB8ULL, 0xE78DA0D1CF294B2DULL, 
            0xE7635CA04D1ACCDAULL, 0xEA3B9F519FC4CEF3ULL, 0x39DA7D5E14B43A88ULL, 0xEB3D6C0F4D771881ULL, 
            0xD13C47343CD4E055ULL, 0x05414926E76500C7ULL, 0x6B34FDF2D78F25FAULL, 0xC3D1DC6F30327B69ULL
        }
    },
    {
        {
            0x41189A7B5A9CD971ULL, 0xD53EA3B8372874D6ULL, 0xDBAE32A47D7C38EEULL, 0xC19164C871054A6DULL, 
            0x65DB4092F0A2BB64ULL, 0x904FD49190846E78ULL, 0xB493EC2C0A0276CFULL, 0x2913A4F41E412D28ULL, 
            0xCE137AAC83C35162ULL, 0x14BD1F3B814D2CB2ULL, 0x8AE2FB457BF73D79ULL, 0xFD864A99A3AED236ULL, 
            0x0412EC48C3612469ULL, 0x5AB32D49E8AB4B6FULL, 0x46E72BDFA942D8EDULL, 0x48AD192C1BB632A5ULL, 
            0xF5F373AA8EEFB029ULL, 0x816E780B3D2E9F70ULL, 0x6A7235DDB5BE1188ULL, 0xB9C1987D4A1D883FULL, 
            0x189F2256E63DD92BULL, 0x5C7ED57C33CDE7BAULL, 0x6F8198D29E450756ULL, 0xF3C832085BF7A959ULL, 
            0xFD5716E96B35E423ULL, 0xFB69940BBB0D47F7ULL, 0x09695F2A4B359B14ULL, 0x3556048E1138370DULL, 
            0xD421AED6C6C900D3ULL, 0x86E6376E1F97C611ULL, 0xE584044D3202360AULL, 0x65BDE4A5693588C8ULL
        },
        {
            0x3E5BFB134F6122D8ULL, 0x32EF2D632641E2C3ULL, 0x9D843851A7736A1EULL, 0xF77C52E0053510BFULL, 
            0x32612A6FE2DB002BULL, 0x1562ADAD9841A700ULL, 0x2882EB04068F26A3ULL, 0xEA1BEF26118F9BD0ULL, 
            0x317BD9AFCE4509D0ULL, 0x309011CB8B14F935ULL, 0xD237F3B9EB66933EULL, 0xE3D33C7A037E3239ULL, 
            0xF9185E6E2D5AD8FCULL, 0x763D6CFC547BD52DULL, 0x1E8BCEC734C96336ULL, 0x81F21942447DA902ULL, 
            0xC799D39E45D7093CULL, 0xEB47FDD5B0C0A9AEULL, 0x9801EC86A9EF9797ULL, 0xD01DB4A5C6702656ULL, 
            0xF2E3BFF2A2B79418ULL, 0x363A7F49BE99F832ULL, 0xC1662CE6133E7C75ULL, 0x6735870037BBD758ULL, 
            0x2D261A5A1E1E9839ULL, 0xAF5A1ED51105F862ULL, 0x3BE9DFA52463DD33ULL, 0x80D0B8C93A43807CULL, 
            0xFDC17CBE9E283289ULL, 0x84EC0E8AE60070D4ULL, 0x173ED110FE40BB55ULL, 0xF694EBD788677EA7ULL
        },
        {
            0x695B09A8E644624DULL, 0x98CACA3EA67042BFULL, 0x84A4A427E85334FDULL, 0xD6399A091003082CULL, 
            0x98D76CDE6AAD9690ULL, 0x673BC5E040DEBB08ULL, 0xACC57E2117D79EF6ULL, 0x90C0102A0B221954ULL, 
            0x00E28C856ABB081BULL, 0xC66442F9273AD79BULL, 0x762FC16A47A85223ULL, 0x993FE66946B7D9C6ULL, 
            0xDC888B5B50526873ULL, 0xBBD1C68F3ABC07E6ULL, 0x801E59F6E3B87322ULL, 0x5A1DB0A681727318ULL, 
            0x81103515E01E3E60ULL, 0xA20E2EE221F58F5DULL, 0x7578B41958DBBA56ULL, 0xDCC290A087EAB2B1ULL, 
            0x87E9AA06A4E42B1CULL, 0x81098B91CBC974CDULL, 0xE87CCB2431BA247CULL, 0x9E094743241FBE54ULL, 
            0x228A35D516A208DAULL, 0x5643D5538568CA9EULL, 0xB937F5144D8AB4DDULL, 0x9DE62FBF66E64CD0ULL, 
            0xAFF29AAE3CFAC533ULL, 0xFF89BD64AA5DDB4CULL, 0xD094D76C2EC0B864ULL, 0xFF5498433CEAA5D3ULL
        },
        {
            0x9D3672F68238A2ADULL, 0xA6886DCD9030D3A5ULL, 0x5BFCFD200CADC14BULL, 0x5084F1951A734EDAULL, 
            0xC22239E87FB676EBULL, 0xB127F14139930185ULL, 0x3639B3CBF2ECCB41ULL, 0x626AA78F4A9D3B74ULL, 
            0x1FDCA43AC18B5E1FULL, 0xF6AC9C1AC4642A41ULL, 0xB6F80CC247EF5291ULL, 0x07642D57744C9C37ULL, 
            0xD84AAAA162CC85ABULL, 0x4D1542ACCE15C687ULL, 0xF8595D1D9BFFE9B9ULL, 0xEA800FAE4C1C98EBULL, 
            0xDAEEE7A5A42C52D5ULL, 0xB08E5DFCB132DD9CULL, 0xAE5282737A544A40ULL, 0xE3F947C46F8B6E49ULL, 
            0xF99E37A9F221B237ULL, 0x581842E67B20CC40ULL, 0xFC6BB9A8F4DA9ADEULL, 0xEA390FDB7D00AD68ULL, 
            0x2990834ECEDCBE23ULL, 0x7A3E67F7E74307E5ULL, 0xF6B91E63F0BCB81AULL, 0xB000B6FC7D61872CULL, 
            0x114C57769DA5C55FULL, 0xB6B0662B1F10013DULL, 0x1BB37E4C8B26A310ULL, 0xD63538682D6E5C6EULL
        },
        {
            0x223A97CCF991899BULL, 0xA742423AE95ABA62ULL, 0xBD760C797653732CULL, 0x22EE5CDC28991320ULL, 
            0x8E0B3F695DA046A9ULL, 0xF526DB627B8FC957ULL, 0x576672F87CFD1118ULL, 0xF8325E9F18948BEEULL, 
            0x7DC040C2B2729866ULL, 0x8B12D4307C756C98ULL, 0x619149582F32C3BDULL, 0xBB7303D384CDBB8CULL, 
            0x45D5E499BA221C07ULL, 0x1CF911B3AF025F00ULL, 0x44306A7253F34B78ULL, 0x0FF338D3A09EEE7FULL, 
            0x0EBB98E65097CE3FULL, 0x747B5EAF8B29A0B5ULL, 0x2D2647A72D4B20F4ULL, 0xD3BBF1042D003471ULL, 
            0xED603F0DD33B1079ULL, 0xDA08C21EBBDAC33EULL, 0x75348FB12789A21FULL, 0x7C5FF810E7F96398ULL, 
            0x8D0F0B2EDBF2B22DULL, 0x2ECB84EDA9F07449ULL, 0xB77797A9C6A1B74CULL, 0xF6C54339A8957FFFULL, 
            0x4C9CDACC02A9E781ULL, 0x2C7F0C85094601F0ULL, 0x194A52579A4754AFULL, 0x97411D982EA19A52ULL
        },
        {
            0x25CD4552A990B9A1ULL, 0x321FCF7F6475740DULL, 0x93B9F4F5DF6FB4AAULL, 0xAC9565EF16984645ULL, 
            0x773D6FF3A593BCE3ULL, 0x04A617B2535C162AULL, 0x045DFA66C569EF1AULL, 0x7D7CBF0B3CE38C65ULL, 
            0xD65252B20404902DULL, 0x571E6F3B590DF66CULL, 0xA857E846AEF268B8ULL, 0x6A9908F969112B49ULL, 
            0x81054C1E50D35EC6ULL, 0xC1ED6E9DD8F84EA4ULL, 0x98A2A88494344737ULL, 0x8482E70F0639BC9BULL, 
            0xBD891534A0D56A89ULL, 0x303817CC2B868F55ULL, 0x42704B3BF1D891B9ULL, 0xE1B283DADE8238A3ULL, 
            0x40FD1D228D3D7ED1ULL, 0xBB28CA370A35D097ULL, 0x7CCE86AE025C83E4ULL, 0xF4928B81872C40B3ULL, 
            0x01DF7FFA7819BE6FULL, 0xC13BB8317F36851FULL, 0x047BC1BAA7DBA77EULL, 0x849E6FB9D1D01072ULL, 
            0xB630F15ABD6EF816ULL, 0xCA03ECB0502348B6ULL, 0x5B05CE287F098531ULL, 0xC29D0F4C0B9B21B2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_PickleBall::kPhaseHConstants = {
    0xE9900794AA936A57ULL,
    0x2A78398EFC6D15C1ULL,
    0xF072CAE618F01CBAULL,
    0xE9900794AA936A57ULL,
    0x2A78398EFC6D15C1ULL,
    0xF072CAE618F01CBAULL,
    0xAED795552C81131EULL,
    0xCEA1AA0C86DD7130ULL,
    0x1E,
    0x8F,
    0xA7,
    0xDC,
    0xEB,
    0x49,
    0xA8,
    0xF4
};

