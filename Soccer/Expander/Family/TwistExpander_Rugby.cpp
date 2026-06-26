#include "TwistExpander_Rugby.hpp"
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

TwistExpander_Rugby::TwistExpander_Rugby()
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

void TwistExpander_Rugby::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 14370001519919403249U;
        aCarry = 13324612703298525221U;
        aWandererA = 11219323532557764056U;
        aWandererB = 14426189181618160470U;
        aWandererC = 11741151563404693212U;
        aWandererD = 16674392305660559982U;
        aWandererE = 10037490820613278618U;
        aWandererF = 10019559639666882045U;
        aWandererG = 16326574527774474512U;
        aWandererH = 9532154337229624636U;
        aWandererI = 14889642214174851833U;
        aWandererJ = 12485165446602522385U;
        aWandererK = 17002930077996333768U;
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
    TwistExpander_Rugby_Arx aArx;
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
    TwistExpander_Rugby_Arx aKDF_A_BArx;
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
    TwistExpander_Rugby_Arx aKDF_A_CArx;
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
    TwistExpander_Rugby_Arx aKDF_A_DArx;
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

void TwistExpander_Rugby::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14432190705991326182U;
        aCarry = 9629006379881080769U;
        aWandererA = 16409361727940802158U;
        aWandererB = 11118737015165788656U;
        aWandererC = 17992634806856273431U;
        aWandererD = 17835173583644370909U;
        aWandererE = 15402584596423828292U;
        aWandererF = 17912631766727453787U;
        aWandererG = 17783846633431723299U;
        aWandererH = 15333299834793485744U;
        aWandererI = 10172354397327203998U;
        aWandererJ = 11407635241281794925U;
        aWandererK = 12401571006752081491U;
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
    TwistExpander_Rugby_Arx aKDF_B_AArx;
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
    TwistExpander_Rugby_Arx aKDF_B_BArx;
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
    TwistExpander_Rugby_Arx aKDF_B_CArx;
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

void TwistExpander_Rugby::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneG);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Rugby_Arx aSeed_AArx;
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
    TwistExpander_Rugby_Arx aSeed_BArx;
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
    TwistExpander_Rugby_Arx aSeed_CArx;
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
    TwistExpander_Rugby_Arx aSeed_DArx;
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
    TwistExpander_Rugby_Arx aSeed_EArx;
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
    TwistExpander_Rugby_Arx aSeed_FArx;
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
    TwistExpander_Rugby_Arx aSeed_GArx;
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
    TwistExpander_Rugby_Arx aGrow_AArx;
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
    TwistExpander_Rugby_Arx aGrow_BArx;
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

void TwistExpander_Rugby::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Rugby::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 9747953452077582476U;
        aCarry = 11865829968495376293U;
        aWandererA = 12058724713605298816U;
        aWandererB = 16520318215945335972U;
        aWandererC = 14255878038144362687U;
        aWandererD = 18196991178273239413U;
        aWandererE = 10347019722159585359U;
        aWandererF = 11072489772162221446U;
        aWandererG = 13691971451415904542U;
        aWandererH = 16967113372402287807U;
        aWandererI = 17549569218060114410U;
        aWandererJ = 16079652768940275487U;
        aWandererK = 9572302315397810773U;
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
    TwistExpander_Rugby_Arx aTwist_AArx;
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
    TwistExpander_Rugby_Arx aTwist_BArx;
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
    TwistExpander_Rugby_Arx aTwist_CArx;
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
    TwistExpander_Rugby_Arx aTwist_DArx;
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
        TwistExpander_Rugby_Arx aGrow_AArx;
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
        TwistExpander_Rugby_Arx aGrow_BArx;
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

void TwistExpander_Rugby::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 3, 0 with offsets 4859U, 6147U, 3497U, 6992U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4859U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6147U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3497U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6992U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 3 with offsets 1117U, 4309U, 4255U, 7063U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1117U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4309U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4255U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7063U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 1 with offsets 39U, 4249U, 2337U, 6250U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 39U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4249U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2337U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6250U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 2 with offsets 2174U, 3313U, 6729U, 4611U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2174U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3313U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6729U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4611U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 2041U, 666U, 1887U, 1694U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2041U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 666U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1887U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1694U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 1, 2 with offsets 2018U, 1581U, 59U, 1759U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2018U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1581U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 59U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 3, 1 with offsets 1925U, 691U, 385U, 840U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 840U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 3, 1, 2 with offsets 877U, 1239U, 505U, 580U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 877U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1239U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 505U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 580U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1418U, 1488U, 1118U, 955U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1418U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1488U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1118U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 955U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Rugby::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 1 with offsets 1662U, 2903U, 3441U, 2972U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1662U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2903U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3441U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2972U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 0 with offsets 6076U, 6840U, 910U, 1091U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6076U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6840U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 910U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1091U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 2 with offsets 6484U, 6588U, 2429U, 4907U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6484U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6588U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2429U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4907U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 3 with offsets 32U, 4547U, 3657U, 1461U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 32U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4547U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3657U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1461U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7045U, 3166U, 8009U, 4641U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7045U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3166U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 8009U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4641U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1465U, 1434U, 746U, 402U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1434U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 402U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1626U, 256U, 18U, 1847U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1626U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 256U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 18U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1847U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 937U, 918U, 248U, 500U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 937U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 918U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 248U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 500U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 310U, 1904U, 1460U, 1249U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 310U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1904U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1460U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1249U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 [0..<W_KEY]
        // offsets: 747U, 625U, 1208U, 787U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 747U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 625U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1208U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 787U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseASalts = {
    {
        {
            0x30C20FAC0FB77F02ULL, 0x7C51577E6EE2D455ULL, 0xED214451C354AC83ULL, 0x1346213718FC7F4FULL, 
            0x08F6DF93A2385389ULL, 0x3D4AD352ABEE93B2ULL, 0x01AF2A5539BA0E69ULL, 0x4D2C742DA357EA5EULL, 
            0xC432F72245931597ULL, 0x2839108950C04D40ULL, 0x420F5D89AA05CB3AULL, 0xE9B6D63B57203246ULL, 
            0xF907CC9769E69B01ULL, 0xEE6D58973D6F2981ULL, 0xF340787E83F0E8F0ULL, 0xF395AFA82834F76AULL, 
            0x550757EE9DDDFAA7ULL, 0xE8965F083B7E6EBDULL, 0x6EC4BA94AED4F429ULL, 0x01DEC27CF749CB4DULL, 
            0x8E1C3957E3306781ULL, 0xA35A3A9EA90402E4ULL, 0x9B105000E0AF1C51ULL, 0xC07BD6C93F024609ULL, 
            0x745DD33CC6E81186ULL, 0xDF2C78204ECB107CULL, 0xCE68ACA3FBABB12DULL, 0x22DD57B62D95C0A9ULL, 
            0x4821254BFC6B60F0ULL, 0x4BD0DBC1357C2F04ULL, 0xBCA09DCB11CFF8F1ULL, 0xD57C041231564521ULL
        },
        {
            0x65AE7F3C92871433ULL, 0xAC038FB7190BF177ULL, 0xECA432EB7CBB1154ULL, 0xAA63CDFFD4F8F0A8ULL, 
            0x31C59FE7E88CDBEBULL, 0x6B1A52EF04A7A185ULL, 0x9FE2FEFDCA1FD263ULL, 0x964E4C1C90218404ULL, 
            0x85C3184BDC6C6FB6ULL, 0xF6FE5B73D64BDEE9ULL, 0x316A05575CC93919ULL, 0x9BC558CE82324B4BULL, 
            0xACD879C0E5FBDDF3ULL, 0x99D7D36F335AC992ULL, 0x075DC799F0E915FCULL, 0xED6FCA5A8948DF38ULL, 
            0x50A12E7ACE56A2C4ULL, 0xF577D664BF6F39C9ULL, 0xF61CA5B171A335DAULL, 0x9731A26A1F8ECE49ULL, 
            0xA6D52CFA46E3E1CEULL, 0x6594CBF0E1E294B0ULL, 0x6546EC5101F457DEULL, 0x09CE5D2CFD221D8DULL, 
            0xA62DEC3543F3A7B2ULL, 0xA004925350C72477ULL, 0xCBD4EFBB94C696EAULL, 0x0674DF80E6D2CFFEULL, 
            0x2477A2998A075B6EULL, 0xBF4B5C106E3C6576ULL, 0xBCEBAC97AA499C69ULL, 0x5D2D460B98E147D9ULL
        },
        {
            0xE7EC1F3A06673BC6ULL, 0xDCDA516025B7BE14ULL, 0xFB49D42F19BA19D3ULL, 0xD6196906876FC628ULL, 
            0xA68EDFA5E9A75F46ULL, 0x9AC5F7B15DC34D05ULL, 0x3F22326EC404FF35ULL, 0xB6700F7FFA71EE21ULL, 
            0xCD2A875E60D15D6BULL, 0x5DC13E71791A56BBULL, 0x995BAC0160B5D412ULL, 0x97DA5A0D19924A77ULL, 
            0xCDCEA8B3434DD50EULL, 0x210338BD3571F25DULL, 0x0BCAC289659878AFULL, 0xA3FE27E89CBB6B7BULL, 
            0xCF14A543F93FF4FAULL, 0xE8F72F6999E6155DULL, 0xC2EE385B122FD3EFULL, 0x07E652E3C4D3AF81ULL, 
            0xE8E4425BF45E5CEAULL, 0x0495D1C350D7C9B5ULL, 0x52158B9675C8D521ULL, 0xCFE8A402F67A84D1ULL, 
            0xE83F1CC333370F58ULL, 0xFB579CB1B567CBA6ULL, 0x6C51C247C733C9DDULL, 0x3ED47610ADDFC743ULL, 
            0x4787EF9B87396CA4ULL, 0x0202FAA81EEC5CAEULL, 0xEBDB1D4FBC93AB36ULL, 0xB442A1602FDF76F1ULL
        },
        {
            0x26D578C3796AC923ULL, 0x9134295CB6C802B7ULL, 0x1E27C758BF1B871EULL, 0x250E5DA2A4E180CDULL, 
            0x4B34FA2EB8A36450ULL, 0x8D728EEA76597477ULL, 0xC74D1A7DB3877CD4ULL, 0x295D11C06A51AFABULL, 
            0x7B2A6F2CDB385B02ULL, 0xEFD12A8497143972ULL, 0x525BE87D78ED2C28ULL, 0x57A1BE207DC8FC1FULL, 
            0x1876E6FDE6C68CA7ULL, 0x96D99CD837A68F78ULL, 0x0F7FCBFE5741A0C5ULL, 0x0EC047B77A2F004CULL, 
            0x5BED57D4EC065025ULL, 0x8C50FD11AA1E9C22ULL, 0xC80C50DB40E37EF2ULL, 0xEB3CB0252680A5CFULL, 
            0xBB6E2D08F40FED67ULL, 0xF1E40FA5AA1CA6FAULL, 0xE803638023F5A51FULL, 0xB89123601C6CC7C3ULL, 
            0xB0FEA13E5175287DULL, 0x035A91D03DADEC42ULL, 0x5439FE16D3364157ULL, 0x805D11D7087985DAULL, 
            0x6E1A61D0D2EDF11DULL, 0x80846F288EE12B9EULL, 0xCD45BEBCA68CADF3ULL, 0xB0026DF93D0D3659ULL
        },
        {
            0xDD94D719791419CEULL, 0x755741DFF5721FCAULL, 0x4CE806A1A787D366ULL, 0x34479FC118D46034ULL, 
            0xABDB0FDA475755DBULL, 0x87E03B7CE00E2D8CULL, 0x2995EE943164D57FULL, 0x49D68C51D3B744BEULL, 
            0xA69B93FE66D1F59BULL, 0xD4B470A894C1DADBULL, 0x13B71463B8F16DE2ULL, 0x501EFE1894349F12ULL, 
            0x3358159AE30FD752ULL, 0xCAC13649560FE3F1ULL, 0x87EB8E4154CA2A0AULL, 0x0E00FC931AD2EC4CULL, 
            0xE1CF34C07B5570CDULL, 0xEBD4429B7EE8D425ULL, 0x7E49A65E643D7B48ULL, 0x24B9B72D3E7AAA41ULL, 
            0xF094F0B3C714BB4FULL, 0xC852456346B5A76BULL, 0x38824CF2DF4E240AULL, 0x2EA69495237141E1ULL, 
            0xCC52BB284CB495F9ULL, 0xBB50E0D2E81721E2ULL, 0x932EE2EF234479DBULL, 0x9701DB38E328CF54ULL, 
            0xF47CDB247CE77253ULL, 0x187A589E662E7C30ULL, 0x3290A44BF506C290ULL, 0x1D21E740209D04FAULL
        },
        {
            0x47DA3BB2F41B8B6CULL, 0x209026FC53DA030AULL, 0x98A33A86D6411553ULL, 0x9548AB3FAB67C9E5ULL, 
            0xAD997995E25D1AC6ULL, 0x1DED26FA2898A9AEULL, 0x30DD65064B976E56ULL, 0x6174A865B550F97CULL, 
            0xF39AE2E9316BA292ULL, 0xEE426C6B1BB9A8E9ULL, 0x5FD8372545B6D9FCULL, 0xB3B5D0BB42693818ULL, 
            0xB54F1C444DF9C4B4ULL, 0xE8B91CE8DEF5CC60ULL, 0xE3BE21F88365FC2DULL, 0x14D6875E4B1E06D4ULL, 
            0x46F9E405F075BF9BULL, 0x4A9E91C0C7E3D4FFULL, 0x836385065BC4AB97ULL, 0xDD61A86E0A2516A4ULL, 
            0xB6B3F449EF724B6FULL, 0x0148D6FF36C38C5AULL, 0xC965E4CC88F65FD9ULL, 0xA7FA0B5036B0BED9ULL, 
            0x0B0F34DCB87D26FAULL, 0x632A884A9D7C841EULL, 0x16B02C5AF7C7E41CULL, 0x8E40E8441786050DULL, 
            0xC23650EF08DC0578ULL, 0xCAE383010E29641CULL, 0x44A6C011CC960F3CULL, 0x8B00C9CE6EFA7291ULL
        }
    },
    {
        {
            0x1F1B825307AF85A3ULL, 0xB588203EED6E908AULL, 0x1B76D1362B9E751BULL, 0x0EAA080B70115439ULL, 
            0xB692B0CAE16E31D9ULL, 0x7B445DC1BBB7BE9BULL, 0x06C2CA8439FA9E50ULL, 0x3BBB54CCACACD616ULL, 
            0x8FF9D644705AED67ULL, 0x382F8C2498AB7A49ULL, 0xD0CA0F11C310C942ULL, 0xC0D7053F88044A97ULL, 
            0x9F53F6149C7005B7ULL, 0x85461182139AC4A8ULL, 0x3C74735D5A92465FULL, 0xC0AF2FED7B303AD3ULL, 
            0x1556C07D38D1F900ULL, 0x23B580BAB44A8D1CULL, 0x91BD3834B11896F9ULL, 0xDB488D6B7D02E6D7ULL, 
            0x8B0E23F41EC52969ULL, 0x3C24B41A0A3A2449ULL, 0x4FD0A7B8425773BBULL, 0xCC116ABDF8679646ULL, 
            0xB16D31AC6D880D4AULL, 0x5EE720A566936E00ULL, 0x8CD83F68C472F455ULL, 0xAAD413CB54CD0900ULL, 
            0xC9FF8CD36201C236ULL, 0x36ADCCFC2D2B2304ULL, 0xCC61633412DF06B7ULL, 0x92262429514C1EEFULL
        },
        {
            0x144A02C401493A09ULL, 0x0FC47AF15F38A2A6ULL, 0x274EA6058899F11AULL, 0xBF3D1476D3BA7A15ULL, 
            0xA3E8C44037FF475AULL, 0xD074F6DC74DC486AULL, 0x1973CCBCBBE8F7B4ULL, 0x4AB25646C8A9ADD9ULL, 
            0x097529D08C050DEDULL, 0xBAADA3452155375FULL, 0x017E61A5D4A4C014ULL, 0xA7D8535540ED03BBULL, 
            0x7E4FEB43C9BAFB35ULL, 0x0312ED963D03E293ULL, 0xB1AB801C694D7640ULL, 0x8DFF96093548B183ULL, 
            0xBB8D7E89C807C8C8ULL, 0xE47D46B5BDEDF624ULL, 0x0D09D88794736B44ULL, 0xD8A20EBFE8568A24ULL, 
            0xF458BAF93087FE2FULL, 0xC79F3074AAA2EBE1ULL, 0xDD1F916BBF09440FULL, 0xC4FD956E8062EA6FULL, 
            0x5FE8BC0C7F01C44DULL, 0xBB647CB6CD71186EULL, 0x19F6FB3273167DA7ULL, 0x81773E3118770AE0ULL, 
            0x2E04BBFC0A6FDFA0ULL, 0x98A9574CD63A6F9FULL, 0xBEDE401E74426277ULL, 0xB310385D79F326ACULL
        },
        {
            0x8FDFD2F333B32338ULL, 0xB8DA23CD9A72EDFEULL, 0x095ED3191DA157F3ULL, 0x78DBCEAB750EF15EULL, 
            0x9EB9A7E797FA26DBULL, 0x75F2A9A16E017CE0ULL, 0xEFBF5EDAD6646CB1ULL, 0xD750C7C5A17AA592ULL, 
            0x1CF19E2DF629C830ULL, 0xDAF3C1B3EB097845ULL, 0xC90B8B372CE67B6EULL, 0x44B9C8F7FB58D518ULL, 
            0x5403C28CBAD17338ULL, 0xD3224252FF68D061ULL, 0x67A882551D7AB3ACULL, 0x7DE1A177E1C548BCULL, 
            0x255244CD717981A5ULL, 0x888468EFB23973CCULL, 0x10D059F4E87E4701ULL, 0x31D1B3F5214D09A5ULL, 
            0x1F54475550BF58D6ULL, 0x6352B8745963B7EBULL, 0x8ECB478EE2F874DEULL, 0x11B68EDE52E9CC6AULL, 
            0xAC94FDFCDAB6B7CCULL, 0xC6E19AA5528AAA58ULL, 0x9B611682D025A24EULL, 0x69BF862C1D46096FULL, 
            0xAE64C885AF9E8998ULL, 0x94A4BDA6C069BABFULL, 0xD0F94DF0610AB50FULL, 0x3237343A7354C8D2ULL
        },
        {
            0xBCE43BCBB17E73E7ULL, 0x73355482A9671BFBULL, 0xD1B541414D48D251ULL, 0x4DE01C71879980EFULL, 
            0x2F956381FF716BEFULL, 0x1176260179D06235ULL, 0x1C42D26D8CA0D365ULL, 0xD8C1CA9958507488ULL, 
            0x85EBB84921AD2740ULL, 0x0C10481E2B8B2575ULL, 0xC04847B750C3B1F6ULL, 0x472A3B7B962DEB61ULL, 
            0xBE23A548BFFF7574ULL, 0x7FA598A434AE976EULL, 0x287C35212D8CFE0FULL, 0x6FFF5BA43871C9B6ULL, 
            0x32FDF58DAAD4C4BBULL, 0x47072BFCF947706CULL, 0x0ADD3418DADC3C1CULL, 0x1CF739F0BE2989CFULL, 
            0xE1794A67F7A32A45ULL, 0x0EAC01FD3A320045ULL, 0x2EF5F4A8CA3E4A86ULL, 0x45BA7B5F69AEFDCFULL, 
            0x5584F2B1E1CDD089ULL, 0x1AD78FE4D15EEBFEULL, 0x696AC06BCAC05C51ULL, 0x2573C4220C181B11ULL, 
            0xB3A2FD224994DF18ULL, 0x19115101B1F296D6ULL, 0x78501AFD8D822CA5ULL, 0x59CB2CD7EE6F913EULL
        },
        {
            0xE48525BD95990CAAULL, 0xC2055150C28B10E7ULL, 0xBE65BEC99D65BC22ULL, 0xF169AB19C22A112CULL, 
            0x97BF79F870E23418ULL, 0x2A67648B80ECEAC8ULL, 0xEF89924513087823ULL, 0x6760BE2D4A12513FULL, 
            0x769B0EA263870019ULL, 0x80982DF009B7B5AFULL, 0x9037203B7568D455ULL, 0x11245ECDAEEA8086ULL, 
            0xC80DFEA25B48F2FCULL, 0xF8101D713C3743E8ULL, 0x0E366ADE54C653EDULL, 0xA400A29C1042FB5EULL, 
            0xAB7013BFEA847703ULL, 0x944B51B5450E53B2ULL, 0x12F372267D57AC5DULL, 0xB2EA6C1F92E98EAFULL, 
            0xE62315083353CFA4ULL, 0x6CE0BF06C6C8DBD2ULL, 0xB4C6CB27CFA0CEF2ULL, 0x7EA04316A504013DULL, 
            0x9240C583B2C00B88ULL, 0xB9812667DF0D3092ULL, 0xB31F254A0078344FULL, 0xA10F43E7DC06C848ULL, 
            0xDCA5DEB05D97CB3BULL, 0x7BE6E6C74C45D0F0ULL, 0xB12327C077A1A086ULL, 0x2353DEE555F886F1ULL
        },
        {
            0xB0D1B87FB290B419ULL, 0x24285B2686E04438ULL, 0x2B08C9695CAEA53CULL, 0xF4BEA418E8ED3DC9ULL, 
            0x63D09B9A0140A3C7ULL, 0x7258AE1DD94A4351ULL, 0x0DC4E901C4E39272ULL, 0xF71E14CFB8A1C1D6ULL, 
            0x6738761B341EC792ULL, 0xE10231D8D80CACC5ULL, 0x57454A9FC207FCDDULL, 0x8F865E32FE2E6707ULL, 
            0xDB9552DC099E3196ULL, 0x2036564AAA547F5EULL, 0x663CC0400C4964FBULL, 0x951A04439420A1AAULL, 
            0xF3F53C87DBA9099DULL, 0x4C62185E7BAECB50ULL, 0x8130E4906EC9F091ULL, 0x211D1DBBE9E00147ULL, 
            0xB7ED143B9AD96FC8ULL, 0x3F9B0A2BF247B5E0ULL, 0xE9D4F7F7871231FFULL, 0x1109B5FE7F14CD22ULL, 
            0x5B4C3F5C5FBFDA4CULL, 0x3972BD2DB11FCF20ULL, 0xE9849BAF949AB29AULL, 0xD4C5FD2FE72B21FEULL, 
            0x5D0BAE4A877921C7ULL, 0xCC67D25A96331372ULL, 0x1278C40FC99686B9ULL, 0x50793D830B87972DULL
        }
    },
    {
        {
            0x423D9A25B413A95DULL, 0x0D08DB150E124B7BULL, 0x0220F2083CF532E8ULL, 0x89EC16DFF818CDFFULL, 
            0x9885D07D17617922ULL, 0x98635EDD7F199F9BULL, 0xB955E53F14B398C6ULL, 0x9132430E8B044B19ULL, 
            0xBD0726F72E0FE4A3ULL, 0x33B71AE07C160EB7ULL, 0xC51A90455FCEE1F2ULL, 0x4EB4C54E1F14647CULL, 
            0x4087AD35CE705B2AULL, 0xD70F90A8ACA5A667ULL, 0x94F203AB1557C504ULL, 0x3A476B8026A2AB87ULL, 
            0xF6CBE36910219CDDULL, 0x9D485259FA6163B4ULL, 0x0DAE8A2764C0D345ULL, 0x9C684C6046EB87CBULL, 
            0x634685243406CE7DULL, 0x78DB70F3648F971DULL, 0x41F1410C9D2CF5DEULL, 0x004E3530A54083D3ULL, 
            0x1EFA63694733C9A3ULL, 0x5AD76C3D59069BA2ULL, 0xCF77FAB329D44CCEULL, 0x833F57121E45C55EULL, 
            0xFD9B23D5B66E8904ULL, 0x8EFED274259D6CABULL, 0x0265868A663AF222ULL, 0x1B18CB0BAC8906ECULL
        },
        {
            0xFC1F0612E2CDFB58ULL, 0xEC3F0410883FB188ULL, 0x5D1DCAF42A9EBF3BULL, 0xAF3A2334325FF7CFULL, 
            0x7CDECE0C54F2B53FULL, 0x64E76862D0BD316BULL, 0x2742192825CA378FULL, 0x116E36576DFCEC1BULL, 
            0x29FD81AB5B2B5C24ULL, 0x5E315341A0036A7BULL, 0xAEA61A0FA736A953ULL, 0x0BDDC4ECBF8FEB5FULL, 
            0xD14F2593CB0BC0FAULL, 0x299C5BD24BD1B7F2ULL, 0xAF53E0C96D435A02ULL, 0xC4F680BADA757199ULL, 
            0xAEDA681DD408936FULL, 0x55E037E8FC162FD2ULL, 0x8B6DF33F427EE0CFULL, 0xD51FE6EC13098EB1ULL, 
            0x8ED4B396145A661CULL, 0x3D95EBDCB1DF5D24ULL, 0xBD4486655E7248F6ULL, 0x9B32A2778748D195ULL, 
            0xE3E8066876B3D047ULL, 0x0B4D8087F23FCCA4ULL, 0x2CC0EE4038567630ULL, 0x5D678060AF5C5828ULL, 
            0xDF1E0D5325518F0AULL, 0x23CFE5411BD495B9ULL, 0x2C7B38F60C7D77A0ULL, 0xD8BD330A1C5A7636ULL
        },
        {
            0xE9E957FE397BCE8CULL, 0x8346F5147937DBFBULL, 0x9452E5C6AEF7C822ULL, 0x77C11C213EBB50ABULL, 
            0xEE3AA90A99CF31E7ULL, 0xA58E05470B4098BDULL, 0xEDF7A5B4A56032C2ULL, 0xACCABB92E1E375ACULL, 
            0xFBA061D8FDF769D9ULL, 0xC0225A47F42B2D11ULL, 0x67F42AFCF8354516ULL, 0xDAE1203AFBFFDDF9ULL, 
            0xF836230F9C2A9577ULL, 0xDF4ADC81C0AA4A73ULL, 0x0CB1F3784939919EULL, 0x4A0C59B467084E53ULL, 
            0x198DBE3FD1759EAFULL, 0xAE5BB43BF749B832ULL, 0x114D60225958240DULL, 0xA9691F59C4FA33C6ULL, 
            0xB8AC59A842F77CE1ULL, 0xDEA02AF329854B9EULL, 0xCDA67CD46EF9E569ULL, 0xC7B7F7775124A1B6ULL, 
            0x2DDC7FB19B23D7B0ULL, 0x50F583B65CBC3E4AULL, 0x4C96A146806B1D90ULL, 0xF9830990C3396BF9ULL, 
            0x4FC6227D9CE4BAC6ULL, 0x66B7DBE57EB4DF49ULL, 0x4B79A48D0140D58EULL, 0xFF39E4637FF49BEDULL
        },
        {
            0x0F43B59DBF7B8137ULL, 0xF93E000386F615C5ULL, 0xAC9AE7558AD7B274ULL, 0xD173D9840E27C5BAULL, 
            0x8B0B37C53EE1BA28ULL, 0x0E7F1CB15ABF59B4ULL, 0x8123AEB1D38A1B17ULL, 0x2341D06D4ED64785ULL, 
            0x0B711E5E00B756CCULL, 0x2F8C1C51A44ECCE8ULL, 0x8EB1DD92461EFF4AULL, 0x141C390148335B06ULL, 
            0xED8B2F86A791B4AAULL, 0x3A34DB0B25624C65ULL, 0x164EDB6AFA2E9C8AULL, 0xB1768F4AC426865EULL, 
            0x9BA0EE815298DE73ULL, 0x826D5956A2702253ULL, 0xA93DA14DF3EFEC8AULL, 0x74F7FDE4DD9D1179ULL, 
            0x045A6415DF131365ULL, 0x041754044791523FULL, 0x01798C45835EDE4EULL, 0x34F60765308102C0ULL, 
            0x8362DCE9282937C4ULL, 0xA6A02118C51C27E0ULL, 0xB6BBE39435A18CBCULL, 0x525D6EDE5D2787BBULL, 
            0x551D7CFE71EB61A1ULL, 0x80EC904112042E6AULL, 0x1E5166FE91327E3DULL, 0x3E00F0ECC9E5EABDULL
        },
        {
            0xE840D2D90F85621EULL, 0x35C80B5514423B70ULL, 0x8795AA713698AA33ULL, 0x0726075659D98E84ULL, 
            0x32F3A03E46D6967BULL, 0xFFA545E011A176FBULL, 0xC4C73E4632A0D287ULL, 0x35870844EBC818D9ULL, 
            0x025C673E3596DB34ULL, 0x37B529696BC9B85DULL, 0xF228B744775EBF06ULL, 0xDA0452F0D9656246ULL, 
            0x2B094792503C68EFULL, 0xA6BA3CD3869EFDE1ULL, 0x7B0B1003E0271F09ULL, 0x021A72EE7C4FD489ULL, 
            0xF2A052B6D8411C0FULL, 0x69923F88E699FCDEULL, 0x19DA7943D3FF31D7ULL, 0xB4CB164FB95207DDULL, 
            0x987C5EA1EDDBAEC2ULL, 0xE739CA3123A5E4DFULL, 0xB2A0F3F1074D829EULL, 0xFD8CE8D47BC7E541ULL, 
            0x9929ECC14757A0DCULL, 0x747E66AF09A3CCC1ULL, 0xE48384C3F8D12317ULL, 0xECAB6C1A36CF6EADULL, 
            0x082290D22C691C14ULL, 0x344AB295DE0F87BFULL, 0xBA61E17CAA958210ULL, 0xA25D620F7174B9C6ULL
        },
        {
            0xB4303C4B8444844BULL, 0xD14F484116847030ULL, 0x384E7B03680FBEE3ULL, 0xD74384D72E0560C1ULL, 
            0xAB283AB856C5D30DULL, 0x84162340BFB13FDFULL, 0xEBB681D42DA09964ULL, 0x475919588641D385ULL, 
            0x82078E9A77272C71ULL, 0x4F2CDAF04F464F6FULL, 0xA536F44B28A7E683ULL, 0x301233A19DF60F02ULL, 
            0xC339BA9CE87C6DA9ULL, 0x632C4645CE813549ULL, 0x8D833E305F1D4959ULL, 0x4F080430604B5974ULL, 
            0xE2CDA54BB82423C8ULL, 0x7C59C64BA18CF061ULL, 0xCD9C632796EA05D3ULL, 0x2FE25E4AA09FD483ULL, 
            0xF33853186C3DF25BULL, 0x6435C6CE75151757ULL, 0x942F02FF4CD333A6ULL, 0x2E35482BA1300629ULL, 
            0x0B3363E87962250AULL, 0x0C8F95DF49F90E9DULL, 0x6DF37015C58C629BULL, 0x0D6D94AAA903102CULL, 
            0x034EC604E8BA975AULL, 0xE5BD4BCD4AE4119FULL, 0x4ED9460C36CABEC5ULL, 0xDE75B6D21AE3A7A8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseAConstants = {
    0x4977BF7965FE2CCEULL,
    0xB0A052E8DD207C29ULL,
    0xCAEC1A0153D9C3C8ULL,
    0x4977BF7965FE2CCEULL,
    0xB0A052E8DD207C29ULL,
    0xCAEC1A0153D9C3C8ULL,
    0x53441FD4676AC35BULL,
    0x24E4E1539BBF54F0ULL,
    0x8C,
    0x2E,
    0x28,
    0x35,
    0xFB,
    0x2B,
    0xF7,
    0x04
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseBSalts = {
    {
        {
            0x4AC5D40471F9B76BULL, 0xF536C7284DF9D321ULL, 0x150A9B50774B14ECULL, 0xD063F5A1935C2A05ULL, 
            0x7A361EF50274B98BULL, 0x375BB4E02689F44BULL, 0xA7862EE3443C5FF7ULL, 0xC2FFE1A8E04691DFULL, 
            0x79266116F7A22BD3ULL, 0x68FE1C8A1C9E2145ULL, 0xF247D10BCEC04F51ULL, 0x5AB3DBE6AC1950DAULL, 
            0x3E7D6126E419D97AULL, 0xA1EA4B8D4AA4855AULL, 0xD99CB8A15BB08664ULL, 0x78AB2874EDE6EE15ULL, 
            0xC7F397F4E81BEE95ULL, 0xDE3C2A4F2BCE8C55ULL, 0x0A5C99F70389109DULL, 0x7FC4FFC2ABD71748ULL, 
            0x18D351E526548B6BULL, 0xABFE012079D29E99ULL, 0x1F7037526E6B5913ULL, 0x00997F2D2468C4F3ULL, 
            0x880AAE9B2426511FULL, 0xF63B7E3D6A0D92B5ULL, 0x3F95C9D1FCE36131ULL, 0xE449E1C3996C8684ULL, 
            0xCC6E12870180488CULL, 0x0E5F531E8013F4BEULL, 0x7074F8AA29DB8FAAULL, 0x6A66B3DBC2FBEE1EULL
        },
        {
            0xEB332728C6346285ULL, 0x9AAA7D08540C18A3ULL, 0x49DF05306B622B7BULL, 0x9646BE59446F74FBULL, 
            0x1126C96088BE34B4ULL, 0xD75EFE9214E810B0ULL, 0xBFDFD567A1A19286ULL, 0x71F272A75496CC07ULL, 
            0x8B166A3B477C8D0EULL, 0x1DAAD6E41296C1C4ULL, 0x0B4A95C7D0D40A17ULL, 0x3D0BF9C5C58813C2ULL, 
            0x8432A727E990B7F3ULL, 0xE8BB3999EA997014ULL, 0xA1579A0DEF1BBDC8ULL, 0x8EF5EF6DA7069DF1ULL, 
            0xA1DC8EBC7AB5D42DULL, 0x9D69CED83BE33E87ULL, 0x9C3779B88BB5EE0DULL, 0x3984D0C886DB42AAULL, 
            0x45FA03ADD48D419DULL, 0x8A18A75B1C4F2230ULL, 0xC0B03957912FF1D5ULL, 0xE0A6D9DC82AC0F00ULL, 
            0x32979A4EB5F7BC0BULL, 0x58B0DFEF948C4D4DULL, 0x626AC3A5869F944FULL, 0x94E5C8118C0CC9B6ULL, 
            0x5051D45994AF3458ULL, 0xE5A806DF8371C6C8ULL, 0x40C19D54ACEDF4FFULL, 0x579A253EC35268B2ULL
        },
        {
            0xC92D9BB1FE526D72ULL, 0xAC65469D589D1D3FULL, 0x2EE93BB241D48A4AULL, 0x1D54F07749414DB2ULL, 
            0xFDB2C19FA9EEDD55ULL, 0xD947B678ADF3B1E4ULL, 0x28AB1597DAA6563DULL, 0x3F3411FBFB8E14B4ULL, 
            0x64079DA0A41CE029ULL, 0x64876987C7B7EA3DULL, 0x9620CF5AA587103DULL, 0x8062759A9F606470ULL, 
            0x0823CAE253BFF2D2ULL, 0xABEC154AC083C025ULL, 0xBBCD971990E05604ULL, 0xD348407747112552ULL, 
            0x97C03710C45C3181ULL, 0xF0D4D3BB84341EE1ULL, 0x07E539EC70C4FFC4ULL, 0x2C4E47A4D2A92F22ULL, 
            0xD5E3798E5EB7F8AAULL, 0xD43A15FDA0E01BC1ULL, 0x1F020CDCF4D5AD4DULL, 0x476E772786E767B7ULL, 
            0xCDAC9C02E5ED96BAULL, 0x22CDD93F05266A91ULL, 0x87035A5C2A86F79CULL, 0xC6CEF82A6A8BB125ULL, 
            0x2E0CE3AC9542C248ULL, 0xFE93AAE5DC1FCD12ULL, 0x2DE0240EECC3DA93ULL, 0x1C67CB3ADF58028BULL
        },
        {
            0xFC2FFCE72351ADC0ULL, 0x02A283F03D1CE631ULL, 0x502A3696FE44CED3ULL, 0x0E3690371DEBBF04ULL, 
            0xC23690ACF436A30BULL, 0x80B66BC0921F4175ULL, 0xACE3B37F4251D034ULL, 0xE2F4ED599AAA6BE8ULL, 
            0xEE847D9DC8227FD0ULL, 0xFF6E0E2C1D840071ULL, 0xD6C277C55C1E91FEULL, 0x895F8E7247A7E661ULL, 
            0x844591EC912D99E5ULL, 0xFB60879C968B5F0CULL, 0xACB169F1E97318A5ULL, 0x0A01CA278D255B4AULL, 
            0x3AD2CAEADF0B2EF8ULL, 0xCC5F456F01651BFAULL, 0x73B211286BB81794ULL, 0x91DFC7EBB2B1083DULL, 
            0xF799A69522D32550ULL, 0x16F5104E20728C76ULL, 0xC43262DA814019A9ULL, 0x2CB59DBB6E894C18ULL, 
            0xD55E34E4F50BD0C1ULL, 0x7F13F43793E0D27AULL, 0x2BF52EDB37883260ULL, 0xA2118C1E235FD094ULL, 
            0x0D34C5DE00E64863ULL, 0x1EF95B525ADB0FA9ULL, 0x3CC1379F483956F2ULL, 0xDC671217605EA567ULL
        },
        {
            0x59994F2FDF6B9A75ULL, 0x140DAE0DEC30A889ULL, 0xCEAEE7D5F5B9973DULL, 0x819D2C128B95457BULL, 
            0xB40080E0FFE77B09ULL, 0x187B4D9E375115C3ULL, 0xAA823D4E15D88330ULL, 0xCAA074207B6BD3E2ULL, 
            0xC200F59F11FD3C46ULL, 0x8FDD5D294C44335AULL, 0xC6C6EFEDDB459BE3ULL, 0x454B3382DF845605ULL, 
            0xD42FA5A3C4C416AFULL, 0x711F258EFED4BC17ULL, 0x0126673ED335445FULL, 0x6A8FEDF95258157EULL, 
            0xA208852A60F76D22ULL, 0x5FB4B873F581DCAEULL, 0xBFF945C5ECBC40F2ULL, 0xC7C22E14174FBA70ULL, 
            0x606D11ED27627C61ULL, 0x38870A88C7C6DDCBULL, 0x6D5D27576742F8BFULL, 0x990290D2F60C5269ULL, 
            0x3FF1E0E6A2572B7EULL, 0x55242F49DDAB8F26ULL, 0x81D75A4581D37D21ULL, 0xB5EB0F242D0708D5ULL, 
            0x5589B230B9CFDFD8ULL, 0x3E29115628E92EE4ULL, 0xA4CC367C81C000D2ULL, 0xEC721C0873873BC5ULL
        },
        {
            0xCD448C6EE82186E3ULL, 0x449D5A69E3AF1A43ULL, 0x5310DCC42DFB3096ULL, 0xC29CCF273CF52623ULL, 
            0xDE655DF2D99D13ABULL, 0x4C2F70D950DC5484ULL, 0x11FCAA33AF31EF5EULL, 0x5E551A1FB937CA1BULL, 
            0xB681DF524D2804A6ULL, 0xF1D834805CD21B6EULL, 0x331177F3AF090933ULL, 0xBA5D012512412EF1ULL, 
            0x6B863DE1507560F6ULL, 0xF44ECF57BC78A6C0ULL, 0x7ED1EC6817DDABFAULL, 0x48DB2051F6DB89FBULL, 
            0x268E2CFFE6E912B8ULL, 0xD0A1647184681FE5ULL, 0x87B64CE2342AFB5FULL, 0x4545F4C20ED75D67ULL, 
            0x6408E4EAB7A2B3A8ULL, 0x2E7257168E3FF4E9ULL, 0xC468CC5B00455A93ULL, 0x039026BB42E1121EULL, 
            0x5B8FD26238C4F582ULL, 0x45B926FC81F15C29ULL, 0x7C71932A8BEE561AULL, 0xAE5943AF0E570704ULL, 
            0x4873733D47024139ULL, 0x3A7D475E6DEA3D28ULL, 0x9C8290FEE0606FA3ULL, 0x9A1CA6D4BB29F77DULL
        }
    },
    {
        {
            0x9298946C045C2654ULL, 0x23ECD588B01B3FF4ULL, 0x4DDDF2B1EC7BC597ULL, 0x5B6383734B8D1DC3ULL, 
            0x50CA4BDA407435C2ULL, 0x7119F2308AC91324ULL, 0xF0EDB4B9892BC69DULL, 0x5EC19B831E985E6AULL, 
            0x421BC12D6F6E0EE9ULL, 0x48D1DF43A4CD5C34ULL, 0x41940102415E7105ULL, 0x54D55D6E427923BCULL, 
            0xD4FD327F6D077905ULL, 0x745C1F57A9CB906AULL, 0x66C35FB383743F7FULL, 0x72D690D01A06E59FULL, 
            0x4642C6CE76279394ULL, 0x94B094F9549AF2DFULL, 0xC71C60190571EAFFULL, 0xCD90513A52D528DCULL, 
            0x03388C5183F4AFD4ULL, 0x124E5D4A9BA7AEDAULL, 0xC9DABD12B934FC14ULL, 0x1248D1A563D98697ULL, 
            0x9E1DD017544B1967ULL, 0x707F3C8C2126D4A5ULL, 0x2AE8ADD6C3A2633EULL, 0xDC95C594F7591297ULL, 
            0x7130E401FD9DEFF5ULL, 0x7B9AC95092977C24ULL, 0x5767BB48BFE3A5F9ULL, 0x2CC1C5D33FBC8436ULL
        },
        {
            0xDEE00FF8CDAED398ULL, 0x012594390E07DF23ULL, 0xBDB97B20B00A4652ULL, 0x226E746BE98F1DF1ULL, 
            0x8580D225F213AF12ULL, 0x55CA07336C3BE325ULL, 0xF6D5FBCFAAF5224DULL, 0x0646FD85620B9FCCULL, 
            0xC2FE8B9B00167B71ULL, 0xEFFA9E3805F907A6ULL, 0xFCE48A010709BB2EULL, 0x7D9A6F2D943FADC6ULL, 
            0xB69CB16BEBA264C9ULL, 0x36FBF8B4EC8B1B67ULL, 0x1E61E4A714B78BA0ULL, 0x0DF90F74C7E92864ULL, 
            0x51B0A926EF37E214ULL, 0xE249F9DAD44BB912ULL, 0x719FB620AD37C293ULL, 0x9D37B83E175104FFULL, 
            0x7C893435614DD967ULL, 0x339792874107EE68ULL, 0xB95BBC68FD992BC2ULL, 0x0AD8A9C9DB9ED5CEULL, 
            0x0770BE2D9385E2B7ULL, 0x8C8FA02DDD95FC30ULL, 0x06A0662C9D0D7D86ULL, 0x4D45A031A0949BF6ULL, 
            0x8D0B8DC1460C19A7ULL, 0x345EB4D5AC3967B8ULL, 0xFE60BA9F4B73BBF5ULL, 0xB9965C51BCBF6ED3ULL
        },
        {
            0x50288E6E6BA657CDULL, 0xDCB9E2D3C6D78275ULL, 0xCB8FC086CF8D18D3ULL, 0x7BA20C7244590222ULL, 
            0x7D5552C0F7B17EAAULL, 0x80CDDC3B4BC2ECCEULL, 0x7800F3C72C746744ULL, 0x8C19D16DBCE5B8B0ULL, 
            0x849642EC77A8AD41ULL, 0xA2630965BC5CC98CULL, 0x11CE423659EB6ADFULL, 0xD31AD6C130452926ULL, 
            0x8DBED7E344D9DA45ULL, 0xD5E9B105F955599CULL, 0xF2B9C29AE7F5944EULL, 0xE18F67F7645E1BE2ULL, 
            0xF2E7C1E187C5D4B7ULL, 0x0604654CD534C609ULL, 0xF948D91695F1D606ULL, 0xB4C60256D4345D24ULL, 
            0xA635CE430843D076ULL, 0x7D390AA6645ED2B9ULL, 0xFF8965217A4D11DBULL, 0x819519D4F7903679ULL, 
            0xA8C1DAF9B5778AE6ULL, 0x2E7454745F646187ULL, 0x5A3A63B37EE64FC3ULL, 0xB5D54F4F73B073D9ULL, 
            0x24AC9CBB60E9EDE5ULL, 0xC3EC73C0202810EEULL, 0x78469DAAAE24F673ULL, 0x2A5B476C8DDD4FF2ULL
        },
        {
            0xECCE5674A2E04D09ULL, 0x349F6E5A7CEE8D67ULL, 0xF2A9267D81A5B65DULL, 0x53D460E9F3EDEA16ULL, 
            0x1184B35434F8F0EEULL, 0xD9AE91589B0CE1D0ULL, 0x4BB7744BD8E1FC7EULL, 0xFFC7E8B3FFA27D49ULL, 
            0xE4EEA6F45B6DF085ULL, 0xD78720F274693E82ULL, 0x8BD220772556AD8AULL, 0xB50C8F45F7764FF3ULL, 
            0x6FB40A44A0A1BB21ULL, 0x1FB6BF9E8782BA89ULL, 0xCBCE912E39579F84ULL, 0x7E2688682838C87FULL, 
            0x50618374AF16ACD4ULL, 0x554F2840DA472E35ULL, 0xE8468CA5C37629EBULL, 0xD1968C51556FAB88ULL, 
            0x61CB6EF036A1E644ULL, 0xF891D717FB3B7A10ULL, 0x0DCD5C8D12C925EAULL, 0x20808D94DE1BE856ULL, 
            0x1D6B96B006E13C86ULL, 0x34AD96C085CD07C3ULL, 0x8BC3427A2E5788FCULL, 0x544C2330858ADCD5ULL, 
            0x20F2486C2CE29075ULL, 0x42DE85CB0FC06163ULL, 0x10ECBA456DD92AA6ULL, 0x6C0242C3C891B974ULL
        },
        {
            0xB4ED9BFA697184D7ULL, 0x719D1563FD3BAA58ULL, 0xCFA26D7C72CA29B4ULL, 0x3794B48B0F4B11DAULL, 
            0x831905BE30A57CCDULL, 0x9502F2F056D66EA1ULL, 0x05DADCF4E6411777ULL, 0x0D85937516BD9862ULL, 
            0xD5EE1CBEA027B2EEULL, 0x7CEBD46E2F06D4C7ULL, 0x3C9C5F40DEECA387ULL, 0x901FA9A4DC2FFE65ULL, 
            0xF0C42CE02017E65CULL, 0x14B4F228DBF3789AULL, 0xC8E4A28CCE073848ULL, 0xC92195F3605C0DA1ULL, 
            0xE8251234959EB683ULL, 0x84ADFAB315E26A94ULL, 0xBDAF839E8C8F32E9ULL, 0xDBF4825FC2084DDEULL, 
            0xD5479133849E8EDBULL, 0x4BE9828C8EBA39FBULL, 0x8F617893F7F76391ULL, 0xFED34F3105E447DAULL, 
            0x3F1BFDB3BA6FDA23ULL, 0x65C22D0FC4371732ULL, 0x6BA8B9123CAEE2E0ULL, 0xABAE64DBBDEB6B44ULL, 
            0x62F0E706B841EF61ULL, 0x56F5680B45DB523DULL, 0xD09F035DF737022DULL, 0x88B3F14B32C07D81ULL
        },
        {
            0x4BCD3F8DC522FFCCULL, 0x2B22984AD9954BE9ULL, 0xCACED0F2EA1B4511ULL, 0x481281F3D1D36BBFULL, 
            0xA4D9B8739D2E1F27ULL, 0x9B85D2834C4BAE75ULL, 0x3A632CD1285F1E02ULL, 0x2417BF2015BC44BEULL, 
            0x9DE95E64C501EC61ULL, 0xD5638C050E4A6560ULL, 0x51399B799998B956ULL, 0xEFE9F6BBE7CF0F48ULL, 
            0xAC645FA98E56F06BULL, 0xA96DDAC15C76577BULL, 0x8F9E49204BE59658ULL, 0x94B10BF9C5C2E29CULL, 
            0x9EF3E84BAA52844FULL, 0xC55B0090DA5D3AFDULL, 0x805F34D9308A7371ULL, 0x09911A6A2C55ABD8ULL, 
            0x86BF521B8CADBB0BULL, 0x36A4DC5AED47C639ULL, 0x98154692B43CD668ULL, 0x9808FFFED0339E34ULL, 
            0x21043E146A1228F0ULL, 0xA5EAD43880BD2DEEULL, 0xBB4342C7012AC7E0ULL, 0x5232B842A550DC0CULL, 
            0x3A10896BD6059B24ULL, 0x4037A72F71EB8998ULL, 0xD986E3F36974F61FULL, 0x1F5F5ADA607BE8E4ULL
        }
    },
    {
        {
            0xF6390471D707221AULL, 0x28B02CA186F52927ULL, 0xE52605E6B08C1678ULL, 0x4A7D3DC98DD112C4ULL, 
            0x299807BFD9D80D7DULL, 0xC4C5A49B257CABA9ULL, 0x02409957E375652EULL, 0xD6C57FED61E1D2C7ULL, 
            0x5D539EA00ACE3884ULL, 0xC0A378B4B7C8F128ULL, 0x745F263E8A0B0E9AULL, 0xEF2F95D953A571C6ULL, 
            0xFBA9E269046B5547ULL, 0xB138B82EE2A660E0ULL, 0x566D6450E504EE27ULL, 0x7404E6948439BA62ULL, 
            0x746B34CB9C7BE973ULL, 0xA2FEE95218F0E8F1ULL, 0x27FA38E622340B7BULL, 0x733B51A675A179E6ULL, 
            0x312E1EE2F9D47BFDULL, 0x311EDBE3F52192AAULL, 0x8D4E751DD3B5FF71ULL, 0x08292E927F421774ULL, 
            0x72E902B521A34332ULL, 0x742C99EA171CBBA5ULL, 0x53A04CAB07A80A63ULL, 0x88E39A0F49F4E89DULL, 
            0xB95F6717D5F75E46ULL, 0x9445C884F22666C6ULL, 0xE6D38E3F026F1CAAULL, 0xFD741BDCBAFF673CULL
        },
        {
            0xFFD8C159B769AFC7ULL, 0x4C1B5FB7E3B741D2ULL, 0x9B828B872EB518D7ULL, 0x9E13E9F22B274F32ULL, 
            0x4A1924C15664CC19ULL, 0xC624F4EF9D405905ULL, 0x0985DCD6ADA9E429ULL, 0x3F40664E646EDFF8ULL, 
            0x8DEB29AE090BDFACULL, 0x03484849ACB6B0E7ULL, 0x6C9D37E9CCBB833CULL, 0x6462CF3C5AF0E879ULL, 
            0xF4FC3EB9519F3DDAULL, 0x87E588623D7C1AF3ULL, 0x7B2E59EC6A50EBE9ULL, 0x5B5CF6229B36F079ULL, 
            0x092CCE39749E1D2EULL, 0x344F4A190C49D8E2ULL, 0xDF6524B797212B90ULL, 0x741C9B466CA333B8ULL, 
            0xC8A5BD8D4D4A7126ULL, 0xAE1914642D62FB4EULL, 0x067AD5F9D5BADF70ULL, 0x14189B01724A3DF2ULL, 
            0x839FB1D6B33E09FDULL, 0x8CACD42439B835CCULL, 0x83770ACC96B0827FULL, 0x0FB2CC8911566454ULL, 
            0x50CB3E7E1AF7D7B0ULL, 0x490B717C7CE2982EULL, 0xB68CB940CC1E9BADULL, 0x801E469F134CF2B6ULL
        },
        {
            0x6A44068CE2FB9731ULL, 0x84B99506F82A95A1ULL, 0xD50C2372BB5E56A7ULL, 0xEB9BEAA7D26147E9ULL, 
            0x5D1645EC1AE05D4EULL, 0xC2A3DD2227452B05ULL, 0x5BD76F6E55D4FBE4ULL, 0xEDF69CA3802C3CECULL, 
            0xB1C157F8E422BC12ULL, 0x9AD3F48E71C91B0EULL, 0x589671B9B8D2E231ULL, 0x564D2A7F5ED49A91ULL, 
            0xAE70E3E5A8279052ULL, 0xE27AA2BB26D5E524ULL, 0xF0E66E353F71688BULL, 0x34E745DD5E791096ULL, 
            0x802FDB27C05F7348ULL, 0x3BEAB5126CCC58CBULL, 0x8A941DBB30BCE7A7ULL, 0xAE87FF5CE1CA5818ULL, 
            0x2845DB6318AE1A40ULL, 0x49192773394BE244ULL, 0x9F1229ACA0A35A1EULL, 0xC0FE8192C1333186ULL, 
            0x8D32E618593F8FFCULL, 0xBE01FD9951605BEEULL, 0xB2FC7DC46E5A220AULL, 0x4E0C5FA83708954BULL, 
            0x9F56CDC6DFF0E4EDULL, 0xD213D364C15E219FULL, 0xC3918A368F71F8B3ULL, 0x21DFD7C15C3B762DULL
        },
        {
            0x347603BAA406D77BULL, 0x2118CD4A7E8C1F66ULL, 0x98F462887867B66EULL, 0xB9366D18B81B003FULL, 
            0x6F74A5D3FE16899DULL, 0x1FF6D8A623095A42ULL, 0x13036FEC36D6B4A6ULL, 0x3FF36B256EBD023DULL, 
            0x6BD5ED3CFBE68682ULL, 0xC5C50F79D7BC1EE6ULL, 0xD5C8691E1BA5CA97ULL, 0x69C6CAE6D4724F80ULL, 
            0x56357D26199557AEULL, 0x593A45550AD5CAEDULL, 0x9FA4A8213B615280ULL, 0xFB081CE521506CE6ULL, 
            0x52116F801755E2D0ULL, 0x0334B0CA7428A41DULL, 0x7631F633A6903D3BULL, 0x5F528232CFA47D86ULL, 
            0xCD253552B0E7878DULL, 0x818054D5526CA818ULL, 0xFF1B73C3D7008CF6ULL, 0x4F2803FCD90FFE38ULL, 
            0xFA7B22D88EC6D0CCULL, 0x9496A4DA41ECA952ULL, 0x6553F491EE8D438AULL, 0xBC719A16D6D8A345ULL, 
            0x780859F974879F81ULL, 0x1965FDE86941B3B1ULL, 0xC1C1AF069C08DD26ULL, 0x673A82D6ACCB5345ULL
        },
        {
            0x06B0D051768D49A4ULL, 0x27DF280AF1BBD976ULL, 0xF72603806862A14DULL, 0xB537656C40D837C8ULL, 
            0xD4FD7F5F9EDC526CULL, 0xDAB4526565AF250FULL, 0x379A34E85A0AB27BULL, 0x828C008DB9620D62ULL, 
            0x6E99EA81848F47BBULL, 0x7F9C640DDE8002C3ULL, 0x44D995577783E54DULL, 0x37BF685A6D7E42F9ULL, 
            0x2279D72D7228FCD9ULL, 0xE0AC8B7DC37009AEULL, 0x76007E1DB92B6E6EULL, 0x44905479ACEBB431ULL, 
            0x12B0680FBD3AB087ULL, 0xEF2C7B34D853B317ULL, 0xC6255C31FDBB2965ULL, 0xB3E8F465AAF1F6A4ULL, 
            0xF120426670C5F86FULL, 0xB283533D6955E940ULL, 0x53A22A404A40E93FULL, 0xD9DEE7FC7FBB9A50ULL, 
            0xCD9A888884E1162FULL, 0x15B3195EFFE51DCAULL, 0x21C1BB16462E47BBULL, 0x5FDDC47574F79FABULL, 
            0xBE90518EE26A6A0EULL, 0x26DDDF6EB516E1BEULL, 0x6AB094E07FC6E264ULL, 0xB190E1971A4505DCULL
        },
        {
            0xF58B846DCFD2086BULL, 0x35AD7E63566A492CULL, 0x88AC6BEE0D5B8CDCULL, 0xAAFB216AA968DDC1ULL, 
            0x8938E0DBEA6334F6ULL, 0xA636CF0C91531593ULL, 0xCFB4D08949BFD5F5ULL, 0xCE8FF3019D502B82ULL, 
            0xCA26FBC23C85E217ULL, 0x3CD8BC48ACC021B4ULL, 0xA5922DC1921643E5ULL, 0x4C91CB0C4515FF74ULL, 
            0x653AA059DA93BC7EULL, 0x2569AFA7932887A8ULL, 0x12CF0B4BF708A270ULL, 0xD2D1DAAEC3C79232ULL, 
            0x43125772CC789CA5ULL, 0x3DD87128327E2C15ULL, 0x29CE64AF4AF5B6C8ULL, 0x6C30A84C075EF642ULL, 
            0xFFE35F070F0F1E04ULL, 0xA9032449FF7E46D0ULL, 0x1A0C34FC768B7401ULL, 0x114886741B230382ULL, 
            0xB13C1067EAC1AE78ULL, 0xD2FD6E2BD3BF57A3ULL, 0x13B0F8FCC36447DDULL, 0x7C42295A28D0DE0AULL, 
            0x21D088D1A2D40F86ULL, 0x1355FA7B7DF2C512ULL, 0xF1FF7A07EE9D09CAULL, 0x36D9A68A912274D9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseBConstants = {
    0xE57F8AD407D88617ULL,
    0xC251C8888004A8EFULL,
    0xAF134B36E15FC0E0ULL,
    0xE57F8AD407D88617ULL,
    0xC251C8888004A8EFULL,
    0xAF134B36E15FC0E0ULL,
    0x8D2FC7CFFC176675ULL,
    0x835CCEC17B741A8EULL,
    0xFD,
    0xAA,
    0xBE,
    0x51,
    0xBB,
    0x47,
    0xE8,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseCSalts = {
    {
        {
            0x3FA87A40BB70F9B0ULL, 0x93B8CB6D31CCE0D5ULL, 0xB4E83DA057184FDBULL, 0xC68704129D2EE084ULL, 
            0x2E708AA9BF327845ULL, 0x07F9B3DE390B0C30ULL, 0x1604CB3EC34DBCCAULL, 0x2261BDF5E2077DBCULL, 
            0x4DF2E948C0CC0E2EULL, 0xF90F9B78E400BC0CULL, 0x793B729A9D75C58AULL, 0x7D03BA6539927FB9ULL, 
            0xFCA895FDFEB52B09ULL, 0x41EEAE002C17877DULL, 0xCC26812B57A2B3C2ULL, 0x1E63782BBFC246BDULL, 
            0xF2C585165F597E2EULL, 0x9454B029893164BFULL, 0xDE0DCFCD9226DF9FULL, 0xAED0BEFA23D5B86EULL, 
            0xA56059BFA03DACBCULL, 0x4BC81D87A088060AULL, 0xDF894029B6F069B6ULL, 0xA00A6B6CC31B337BULL, 
            0x3B718F91E597C354ULL, 0x9189078AFBB5AFFDULL, 0xD7A4A9831628ABCBULL, 0xEB85B9E8FD4911E0ULL, 
            0x592C839C5488F398ULL, 0xCA55690A73FB689CULL, 0xC989D2B77339B8A0ULL, 0x5B2BF748C654C408ULL
        },
        {
            0xE2FCAFC8208CDD3FULL, 0xC34D4683882382FFULL, 0x9292810B91D39B42ULL, 0xD259C86A154FDCB4ULL, 
            0x40DD6C7C96F78843ULL, 0x6E766A8FAB3AEE8DULL, 0x7871B7F52E3F5688ULL, 0x8B7FF51B5F9EDE14ULL, 
            0x40FE2B33D6ABA485ULL, 0xFD787FF41C4D5CAAULL, 0x215BBC63C4B3F6B2ULL, 0xE85B24042E1A1B81ULL, 
            0x6BE5BB33B69C9C14ULL, 0xF6F98E5635FCBDCAULL, 0xB9BEE2D8C81BD27DULL, 0x0588C3E9488EF4B1ULL, 
            0x53F31408EA159A7BULL, 0x0A7EAC08C1E11032ULL, 0xD320999C7243EAE6ULL, 0xF00F31ADC7070DCDULL, 
            0xF2801654CA289C11ULL, 0x0F78A256E68A59BBULL, 0x27F26421C575CA06ULL, 0x2D3414E5DE625582ULL, 
            0x6542029307EA2DB2ULL, 0xBDD7C2DEFCC01020ULL, 0xAD57CA59D86C89B5ULL, 0x2FC6AD9B97B419FAULL, 
            0xC8C16ACEDF284757ULL, 0xB3CB811AB438E5C5ULL, 0x0DF1C14D86CF225CULL, 0x36EA63E32641268AULL
        },
        {
            0x1A81843AFB459177ULL, 0xB558A8ACC60FD7ACULL, 0x93FABB9334849341ULL, 0xBAE280CD520FC773ULL, 
            0xFD28238621386EA7ULL, 0x0613BE194F06A5F1ULL, 0xB7E8126C4428B155ULL, 0x401261C63F32F8EBULL, 
            0x88E0E0B96403E3F2ULL, 0x4545BE1D3CCAADE0ULL, 0xF297CDDCF464F163ULL, 0x42447F0559D0794CULL, 
            0x5484662598EE1B4EULL, 0x66C972B8E2228C9FULL, 0x51E3C17B29957F83ULL, 0x503270F0F3C56109ULL, 
            0xD00E7011F5A83AD6ULL, 0xB69ECA1CE125B834ULL, 0x1546E77B50566AC5ULL, 0xCE2173CFDEC1683CULL, 
            0x44A9B18F02646A7FULL, 0xF50E1E8CCD3BE6B9ULL, 0x6D4E6B05EF350FF8ULL, 0xE9CC21F06807DB56ULL, 
            0x3490F960AC8B301EULL, 0xF1CE883B4DB2FFC2ULL, 0x25E56A4E63CD3C0DULL, 0x66A2228491B0B8A4ULL, 
            0x4AC5B324BBE09DEEULL, 0xDD40468D27051B65ULL, 0xC8722F3024768E0AULL, 0xB0A817CFA15FA469ULL
        },
        {
            0x873996F26FA3B7C6ULL, 0x0C7A099DB2F868F9ULL, 0x6B9FF563DD7E6042ULL, 0x43A12E8F8CEEF4C0ULL, 
            0x10AFEBD189914A3BULL, 0xE36C765F7CAC45E2ULL, 0x0570F6800200CF76ULL, 0x72E8A88F50E52CE6ULL, 
            0x30ABCF966F19346DULL, 0x92A8E6D4A673906CULL, 0xE91EAF3030E967F7ULL, 0xD88D27C747FFB72CULL, 
            0x6FF3E9A8A23E906FULL, 0x72C01A9CE2AEC276ULL, 0xA7DDAB11536B81EFULL, 0x74C16990DD3AB485ULL, 
            0x81E7F72D7D0C7231ULL, 0xCDBADDE38F525E50ULL, 0x7994B6D2EED4F4FAULL, 0xC932220793C52CAFULL, 
            0x1D70092C59F32FE1ULL, 0x9878DA4A654EC659ULL, 0x2D4D1E9640AB365BULL, 0xE4FE6A40EE9B6B31ULL, 
            0x070A8DFDE5C5286FULL, 0x582A6853166BDFAFULL, 0x05DB5987EE3B25A4ULL, 0xEDA758B25B6B24FFULL, 
            0x77C3344EC1A84029ULL, 0x751DA89CDA58999BULL, 0x506A55F2146EF268ULL, 0x87AAE91A5EE31711ULL
        },
        {
            0x120DA0C14EA63CC0ULL, 0x16E7080F2586F383ULL, 0x7B9B3A4CEE5916A4ULL, 0x9CF33B038EFCC9FCULL, 
            0xB7F25A96F69AA70BULL, 0x6C56FE4144437E78ULL, 0x7294F4D3097C9FFCULL, 0xC763FB078E564545ULL, 
            0xA29C51995501B1F0ULL, 0x516E7C53730E95B0ULL, 0x37A6AF72B1E92007ULL, 0x7FAB7B22F9103EDAULL, 
            0x2447030AC976BB20ULL, 0x366CA0358D4161D8ULL, 0x7CB17A8821A6ABCAULL, 0xE1164F5BA9A5E5DAULL, 
            0x588918E3EBE4BA07ULL, 0x72CFABDB16876B4FULL, 0xF1754E93B2C9DA6EULL, 0x25EECCE15BFEFAC4ULL, 
            0x61E538454FE7E9C5ULL, 0xA7028885F5B73DFCULL, 0xD116923773A1E3C6ULL, 0x3E98B78558828696ULL, 
            0xAE3CDBA741B7EF7FULL, 0xA1B39BF6A3CFD414ULL, 0xA944E0B88DE6869CULL, 0x3150E7E4D34D1350ULL, 
            0xA8838F0CB5A0F9D5ULL, 0x929BE0842BED0E21ULL, 0xBCA548001A39ED6EULL, 0x3F128C984E2E7727ULL
        },
        {
            0xA3268BED935E39B7ULL, 0x72EE30906D9350A3ULL, 0xAC07ACB05DA2B86CULL, 0xAE93FA6583F3E56AULL, 
            0x7C47724D2260FD5FULL, 0x34D9963B59A4C553ULL, 0x985EDF7E1B0ECBE4ULL, 0xC00612514BCDA886ULL, 
            0x65AA345CB040EF24ULL, 0xFEF23AFBC7DF5E89ULL, 0x0E9DA64A4A79B451ULL, 0x7F650FDD85EC6BC7ULL, 
            0x9F23A0822B5B7D4CULL, 0xC445559B6B40EC5EULL, 0x6C1297D3BF88FE5EULL, 0xDD624B3022E38786ULL, 
            0xEC9D331F13E4E837ULL, 0x10D9142F5F048831ULL, 0x4D33A784A1B16678ULL, 0x15E4D0A14616BC2AULL, 
            0x4C9D0C42436C9A45ULL, 0xC2BAD88B950159F4ULL, 0x6473F33B5E5FA363ULL, 0xCA0FB512BEFCE654ULL, 
            0x584C0413E87E9A02ULL, 0x5D4217DB5D554859ULL, 0xD23154D8CC0E0A8FULL, 0x8930F85E6EE4AA67ULL, 
            0x69F109018A82AECFULL, 0x5A2234648025E058ULL, 0xFC0D39016E8D7516ULL, 0xA6A732642F9FAA32ULL
        }
    },
    {
        {
            0x96F4939856A37888ULL, 0x3CE8A00C3120CEB6ULL, 0x8B898199A169B249ULL, 0x00DEBE1CBED19EA8ULL, 
            0x1A426D4DDB9E555EULL, 0xF26BBBB429D612A1ULL, 0x9F326DDD8CB038BAULL, 0x2DEAA0F21839F31CULL, 
            0x08B5B35B69765B44ULL, 0x96C2C5A6F77C75F1ULL, 0x8E082F4EB55932B8ULL, 0xFC4F58A49BC9AD85ULL, 
            0x2EEB015E7B46AF47ULL, 0xF6C70BF77EB87CA3ULL, 0xED43889E1B40610BULL, 0x1A9D7DB4BC7C5933ULL, 
            0x664358DC470D63EEULL, 0x306A60D946741D64ULL, 0xBAE01EF5F74D81E2ULL, 0x8CD39FF685E6C012ULL, 
            0xA9A84CE15D0DD557ULL, 0xC3B8498500ECDDB6ULL, 0xB698DAC6B867F0B5ULL, 0x002D954998A194BEULL, 
            0xB6A7C939634B9C47ULL, 0x9BF1AD9B6F976DCFULL, 0xE84E86615858F088ULL, 0x1652959D2842A3D4ULL, 
            0x8C125232FA93C584ULL, 0xBE3E87BB8ADE7733ULL, 0x99D0563AFF6FCDECULL, 0x9D709FD6CB438E50ULL
        },
        {
            0xA1B075168426B341ULL, 0x7A93F9B9BF2B52A7ULL, 0xDB8985092EBA04ABULL, 0x710D20EA713FBFDCULL, 
            0x4C1D61F47BCAE561ULL, 0x5908C1E0C27CFA7FULL, 0x71334B420B4013AAULL, 0x07C16935B17F607FULL, 
            0xA9FBF05F053D9CC1ULL, 0x9994760B4BF8227DULL, 0x37F2363780BFD928ULL, 0xD235FCE5AB3AD0F5ULL, 
            0xB962A8266E2BBD69ULL, 0xF9AE8A17637638B5ULL, 0x61558D53D77A915FULL, 0x87FB6C15ED280065ULL, 
            0x6C46D04222A22B44ULL, 0xF2D189CBEBB67D0EULL, 0x56282F2B628638A7ULL, 0xB55C3D6357DA5333ULL, 
            0xAA17C7E36E4DE133ULL, 0xB15EE045695FC334ULL, 0xD240073D1C1256ADULL, 0xFAD205D851EFDDF9ULL, 
            0xA94C4704F4322381ULL, 0xCE32DAD2130836BCULL, 0xDCF355F6A5DF5F2EULL, 0x9BE2176651E94C93ULL, 
            0xC3FECADAEEDE7FF1ULL, 0x15265BC4A5A8D4EBULL, 0xE2B26A4D8726371AULL, 0x1DA8A1C0F308C87EULL
        },
        {
            0x42ED1DF2E68944EEULL, 0xECCED6F271CB9F5EULL, 0x813B4F7EC1BF5A29ULL, 0xDDC27CBB6DB3B04AULL, 
            0xC03274ACF466F85DULL, 0x445F59A440FC4F14ULL, 0xE37CA2AFCC700F9CULL, 0xD58EE44794FA967FULL, 
            0xE92D475A61B12C42ULL, 0x4A748C6A8C1D8E91ULL, 0x6BF284276D78A21CULL, 0xED68039907E2B181ULL, 
            0x19739F66B0C758CCULL, 0x8CB850FC046432BDULL, 0xA42D6629DC88821DULL, 0xB86C07C4F07F340CULL, 
            0x8AF3D85A4855CA15ULL, 0x2D36D9491A89033EULL, 0x1DEC6F84C21BE3AAULL, 0xB6B50B16D8CA1899ULL, 
            0xCD2D0B098252330EULL, 0x4F11D596CCB408B6ULL, 0xD5675CF9C37F2C74ULL, 0xC3AAE7F9DF630F15ULL, 
            0x7356F34B44A612BEULL, 0xC845E1C0241914FAULL, 0xFF0973C1EA361972ULL, 0x252835258327A090ULL, 
            0xF8EAE97D7F79D0C0ULL, 0xC55B5544130FD558ULL, 0x6D35E235A5AD61ABULL, 0x324A42F7E2E0B024ULL
        },
        {
            0x8F7D2B9A2DE6D349ULL, 0x0EE73CA2513F8257ULL, 0x5361D56065B7A3BEULL, 0xFF883645A5684525ULL, 
            0x137758D207DE5F15ULL, 0x907A7F63FBC51077ULL, 0xA51B0C273713301BULL, 0x94847A6BCF62EB15ULL, 
            0x53E87504E288524EULL, 0xAFD30656C61D0E53ULL, 0x526EC2EEF9103142ULL, 0xD707AF95D510CA8BULL, 
            0x74AD020EBA179A2BULL, 0xC9448764EA68E623ULL, 0x93F3CA9C12C4CAFCULL, 0x31C59911EF24CA43ULL, 
            0x78D45BBA39A3E3ADULL, 0x3110A1FEA3D5AFE9ULL, 0x6E56A361E5645A59ULL, 0x7035D91E2C541A6DULL, 
            0xADA2E5DDA77FD7EEULL, 0xA69E19DAB604277EULL, 0x865C363706D9DB95ULL, 0x0A30CF17A8C83C75ULL, 
            0x9B05EC988183A5AEULL, 0x9CB605D4651DD788ULL, 0x0DDEAC2E70274E84ULL, 0xBC258F29BA1F6FF1ULL, 
            0xA1A4C33B01484BC8ULL, 0x610C737D425C5962ULL, 0x9B65B1CC306CC0FDULL, 0x5FEC494DDF57E1E1ULL
        },
        {
            0x367418495B96F29CULL, 0xDBD00CAE0BEE760FULL, 0x8849FBC655ADF49BULL, 0x3EF53526FF8E6E1EULL, 
            0x9E4FFA236D2DA6B2ULL, 0x220D11923F22621DULL, 0xB5CEFB659AB58B39ULL, 0xD643619B0F4F8AE6ULL, 
            0x65DBBF67F4DC41EAULL, 0xC3B19B52C75A18B9ULL, 0x614A3C6761D70A0EULL, 0x32C33D4F8D4CB097ULL, 
            0x0C3AB0E63F79E4C7ULL, 0x77F13CDE5C171AE5ULL, 0xE5836938B43E6E00ULL, 0xA3E5525561A59BE2ULL, 
            0x6C7420DA887BFD86ULL, 0xB577A099C3E7F0C6ULL, 0x9EAAD3C908E39613ULL, 0x3AFC4D622F1479B1ULL, 
            0x40F798979BF8C767ULL, 0x4748B47D2C722A8AULL, 0xF8EA11194C9CD3EBULL, 0x740EAFB906F8CBE2ULL, 
            0x0D681A89481BC70CULL, 0xA5CF8E3781FBC791ULL, 0xE71C0E953BCF8B7CULL, 0x2AF67A177D8EE85CULL, 
            0xE6A98D3EA26361B3ULL, 0x085F878CA8DDCC4DULL, 0x9C06DE9D7CE77434ULL, 0xE46195DFDBA1BEA5ULL
        },
        {
            0x3B2763AC8BC41EF4ULL, 0xE5BE685DE562878AULL, 0xECA80B25CF81AEB4ULL, 0xA947C31E855802BCULL, 
            0xB02C04CE9096F98AULL, 0x9DBD3A4FB7771B92ULL, 0xD3CB0F0596AFE97AULL, 0x0E2F5FDF733256F8ULL, 
            0x6C3FA4DF101CB9E3ULL, 0xF7CDE038D5A8C664ULL, 0x48CF58C9EC483F3EULL, 0xF56DBD2467980C7AULL, 
            0xD87344C7AFCDCAD2ULL, 0x5BE2C7E1FAE97C34ULL, 0xD9497203EA72B670ULL, 0xCE73B294B8124507ULL, 
            0x2FA560CE5571674FULL, 0x406976AB86B1F507ULL, 0x0399A05FFB620FE3ULL, 0x7B15CF8B3F631DA8ULL, 
            0xB05D796B21ECB608ULL, 0x8CBA6E0186FE0A20ULL, 0x9B0EFA4B03391FF0ULL, 0xF150BE1D5883841FULL, 
            0x7F47BE79D0BCC108ULL, 0x9DCEE1D13CED419EULL, 0xC5954C191B03BDB6ULL, 0x87330A3A1DB296BAULL, 
            0xFA8EBB696788091FULL, 0xF403E6C33FBB4B5FULL, 0xBCC00D82B3ABFF37ULL, 0x365E4971F3E740CEULL
        }
    },
    {
        {
            0x5630C158BDBF9A43ULL, 0xCA79616D5935B309ULL, 0x75E83E128210FCEFULL, 0xF9C0749A75F2AFC4ULL, 
            0x088983737BC60ED4ULL, 0xEA9DF1BF85439B48ULL, 0x75C0DE1E787D0A8AULL, 0xDE9AC372F801BEEEULL, 
            0x6F915CFEC2FD5BD3ULL, 0x9A63279AB6B45B66ULL, 0x2B4F00B437292C2DULL, 0x28EDC4818909650CULL, 
            0x10ECA78375ACAEFFULL, 0x309A9F6AD86DF4BDULL, 0xF81DE4B9FA68AD34ULL, 0xEADBCDC65254D39EULL, 
            0x04A6A2D0BD9C605EULL, 0x7C5456FDC7DE5DF9ULL, 0xC1C0CF1FC3B363FEULL, 0x697A56A6FC7DAC52ULL, 
            0x51056F3C351BD0E8ULL, 0x369CCE53728E4F70ULL, 0x0A72C3174A5D1010ULL, 0xB30B61E90A88C70DULL, 
            0x3CC80B1D2623E56DULL, 0x2AE9C21F186C24E7ULL, 0x88068146D7797570ULL, 0x3BF08C8DE672FD86ULL, 
            0x9089E564F7329569ULL, 0x29B434400BDF5C28ULL, 0x9B3A5F5A41C53F3AULL, 0xC0F0E40E446358ACULL
        },
        {
            0xC2132BCAD2582B50ULL, 0x8B85D13EB49EEF01ULL, 0x6A0CAFE4A8E34985ULL, 0x9E7DB8665E5871F6ULL, 
            0x4E6B6E37C3C6E3DDULL, 0x7204AFA566B6FC97ULL, 0x49D8F318B593A05CULL, 0x1D4C3B04A89B6D83ULL, 
            0xA3D1D4D603934390ULL, 0xC4151DB537AA4295ULL, 0x6101819346062A74ULL, 0x32BD1CEAF17D60EFULL, 
            0xC22EAE6157473DE2ULL, 0xCDF124CDBDE2A168ULL, 0xCDD6593BFA57131BULL, 0x54BF686F9357C1FAULL, 
            0xF469FC30B639CF7FULL, 0x5D629987612A9711ULL, 0x8F04E597E4FAF324ULL, 0x65B3AF35690AD84FULL, 
            0xEDE056F3F2DF16C1ULL, 0xB6668D5A463CF2BFULL, 0x273D477652EAFE95ULL, 0xD234FD38999CC4B1ULL, 
            0xE71850C8A29FEF58ULL, 0x04AA92C0CF341FA0ULL, 0xCE28A0238A0C8779ULL, 0x3B3C54A02C12B53FULL, 
            0x346E162DAB2C9EBAULL, 0x5FC66D9522850B82ULL, 0xD7E7DE98D2F9325EULL, 0x8098069E5329B338ULL
        },
        {
            0x2FD2E89972F7F2FBULL, 0x9596B94647A4D088ULL, 0x0DEB844653E9D76CULL, 0x29FED23695C3E5F1ULL, 
            0xE147B865F70FDB68ULL, 0xD78C2CD9CBA107E4ULL, 0x69B9948719253439ULL, 0x9B3D4D5B2BF9E4FBULL, 
            0xFF9CBECA80B116BBULL, 0x6D795E61D78105CEULL, 0xAB6282B75D91CF81ULL, 0x9EAB3FF7BC074D6FULL, 
            0xD711E6252250ADA5ULL, 0x3941DE88F68C8F1BULL, 0xCDD03A03AC77165DULL, 0x2DF89129CF16D02FULL, 
            0x5821862E7A1B08CAULL, 0x1734FA468568AA23ULL, 0x51F8D908E972E65EULL, 0x18E2ADBE4BCB6202ULL, 
            0x91E79E29ADAF7AD4ULL, 0x63B08FD570ED2737ULL, 0x3D8FACE9CC3EB030ULL, 0x821FA968BFC838F2ULL, 
            0x027366B563DB20F5ULL, 0x7BF80CF5AC600D48ULL, 0xA75F7AF0C8ACADFFULL, 0x3E2861A7167F85B7ULL, 
            0x4037E938A0815DCBULL, 0x32CC540A162F3CD6ULL, 0x047A98E13BA35463ULL, 0x986D0944F9794198ULL
        },
        {
            0x054DE6ED6E04872DULL, 0x5657FD33D7A3F910ULL, 0x76987B4B1728DFD2ULL, 0x9CB3776A1DC73189ULL, 
            0x3FB49C999631F677ULL, 0xC4F1FD8A1ABE2E80ULL, 0x9F5E37EA193E8BCEULL, 0xD439CF07D59C7ABFULL, 
            0xB6CD72CC4C8B4F04ULL, 0xDB70E6233A016986ULL, 0x61D9BBFD3EF19FF3ULL, 0xD0F4B5CA8082583DULL, 
            0x2DBAE90F9EEC9203ULL, 0xC9327FE766E0B998ULL, 0x18BD764BBA30C791ULL, 0x987B44259205BBAAULL, 
            0xB14CACD8B4705F5EULL, 0xE6557AC42932BDA2ULL, 0xFBD83825EF92CE23ULL, 0xA9FA130050CC5708ULL, 
            0xC4D570D7769EF0A8ULL, 0x9DCCA281943C9ECDULL, 0xF9330E9EF68D1DE2ULL, 0x2641EDC19BA94722ULL, 
            0x85A2C13246DBB0F7ULL, 0x22FEFA33390175A1ULL, 0x2DBF63C7A361B7B6ULL, 0x124BEC507FD08842ULL, 
            0x0C3D5049B76FCB10ULL, 0x422AE40A4C10D227ULL, 0x44D2A59A9C6C88D8ULL, 0x87C1A5B14B03238BULL
        },
        {
            0xA80EBFE936889670ULL, 0x021DA7127F39D2ADULL, 0x85704B27FB4A75F7ULL, 0x4FF32EEC548842CDULL, 
            0xD1110CB14B4F3726ULL, 0xB8F414550656B878ULL, 0x4FD0E649E09956D3ULL, 0xCA52E04CFDDC313CULL, 
            0xC0FA07283906DACAULL, 0xAC7C0CE9715FE318ULL, 0xA919E08E26B8998FULL, 0xBDE194EDBAFB0F74ULL, 
            0x871FEBF5FFE8B881ULL, 0xBA17116D16C7CB15ULL, 0xCD6F49FAEFB59348ULL, 0xA5B684C363115191ULL, 
            0x529B80873206715AULL, 0xA7497BAAC8EB550DULL, 0xCB3B39523D958BB5ULL, 0x0C1D781ADF830C26ULL, 
            0xAEA167C2F60BD58CULL, 0x344701D8C12ABD16ULL, 0xD1E91ECEA1C178C3ULL, 0x8C6291513D2BA932ULL, 
            0x7FD24F2AB46C3A84ULL, 0xA186295AF2D55729ULL, 0x9C08D97162B0470BULL, 0x97D3171B653ABE4AULL, 
            0x97AB630C9DBE3A45ULL, 0x2E11A5608667C147ULL, 0xA180F781FE804A26ULL, 0x0154A5B3E3E55D5AULL
        },
        {
            0x12AEE7B7A3EBF1BFULL, 0xE5339F7EFFE3F382ULL, 0x15895AC71C7E08FAULL, 0x5EFCFA2F7CD3F34FULL, 
            0x4801D84075FA6732ULL, 0xB1266F190C9B7239ULL, 0xE7FF0DE89A7AC4F4ULL, 0xA8F6AFFF3960B760ULL, 
            0xDBB4C52533B26A98ULL, 0x8C75E8BC3D21BDFEULL, 0xA6A7A19523F3A6E0ULL, 0x6EEB9EEAC9CB5B14ULL, 
            0xF490BC5AD4C296FDULL, 0xB8747D34681DCEBDULL, 0x61463484D9099FFCULL, 0x39169DBE29A3208AULL, 
            0x5214D9D97DDAC809ULL, 0xC8BB97B4C618F194ULL, 0x69C404E8FAF270A8ULL, 0x2B3DE4BEE37861D5ULL, 
            0x1D141B51E1CD1C54ULL, 0xF9D3B857B6D54614ULL, 0x8B4559EC9DDD2255ULL, 0xFAA085104AE4F4E7ULL, 
            0xFCA10CFBE65F2674ULL, 0x8A2BB22F79B895E1ULL, 0x26AA401BB92155D9ULL, 0x597DF1B4DD3B8971ULL, 
            0x173222BBF38372A9ULL, 0x8B4CD94448BE7A2DULL, 0x771FF4F0BABAC5BBULL, 0xADF53F87BE0088A1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseCConstants = {
    0x05553074AB9C45B5ULL,
    0xBFF0E1C154A14785ULL,
    0x71408977D7AAB232ULL,
    0x05553074AB9C45B5ULL,
    0xBFF0E1C154A14785ULL,
    0x71408977D7AAB232ULL,
    0xB8D292A234544E08ULL,
    0x133181D355F7ED0DULL,
    0x2F,
    0xF2,
    0x76,
    0x56,
    0x03,
    0xE0,
    0x4B,
    0xD2
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseDSalts = {
    {
        {
            0xAAFC932E5E6EEBD3ULL, 0xBE2192DBC208CFC7ULL, 0x93E2CDE40A439696ULL, 0x71F1284BBD73E54AULL, 
            0x127A684F65090F5FULL, 0xE344270521EFE2C9ULL, 0xA335DC439B4A5BB9ULL, 0x976C8D684ABDB02CULL, 
            0xE41F8108D07C811BULL, 0x3651265815C32AFEULL, 0xD33038EAEA117AE1ULL, 0x51088AB6B421E995ULL, 
            0xAB055C8017247F7CULL, 0xEF91BA82252F2664ULL, 0x64A8B24064C27F6DULL, 0x10DE6A6BF402CD02ULL, 
            0xC090C91C99B70423ULL, 0x5B15B2F534491898ULL, 0xB79839F30F5879CFULL, 0xB95DA64848D93D80ULL, 
            0xD2D9C798A1127512ULL, 0x76452A64B345A5B7ULL, 0x7426FAC295CBB0C1ULL, 0x2E052BB708957EDCULL, 
            0x266DE88CCF084A51ULL, 0x87920CD350887F81ULL, 0xE2B260557A853643ULL, 0x1308DC25523AB7B2ULL, 
            0x5165C355F97C56FAULL, 0xEB9C8D90E0E34F57ULL, 0x7E27DA31E9873AE7ULL, 0x4DBD4284064AE221ULL
        },
        {
            0x3F23232BE7938AF2ULL, 0x3EE40E9680BDE021ULL, 0x7E1436E41FD6BF63ULL, 0x23C193AE198FC548ULL, 
            0x0BBA1C9374BB59C2ULL, 0xDF18DB94138AF7CEULL, 0x771B4271E4E61A78ULL, 0x295C33F479B6D53BULL, 
            0xFE13BCC868FFFE60ULL, 0x8322F6CFD8A154FFULL, 0x6D75218B54BCF4D3ULL, 0x5AC8CBD39277351AULL, 
            0xF0B1EFBA69173290ULL, 0x73E843BF1240A29CULL, 0x6ACF0AB52A217CD2ULL, 0xD9275DD72F1EEDF8ULL, 
            0x35BF09F6619E0287ULL, 0x66D088FD9F227FD9ULL, 0x9011B4F892F8DADCULL, 0x7E0B560D7ECA3AE2ULL, 
            0x72822A22216E543BULL, 0xC7F0E4CB58E2E759ULL, 0xAA89576558477FEBULL, 0xC3105DCEC3367C2DULL, 
            0xCA29A7DD75A16F74ULL, 0x94976ACBBE5616FAULL, 0x945266F3B1EBD290ULL, 0x4F4BC0EEDF4A9BF2ULL, 
            0xCAA22937B354EA23ULL, 0x2BB28A55BE486FC6ULL, 0x7D8550992AFAE74DULL, 0xC78888D67CCC4A5CULL
        },
        {
            0xB95E10E51E7B6889ULL, 0xEA3CEBB3D69EB4EBULL, 0x850016B622C3CEB8ULL, 0xC713E2B4EBB4903FULL, 
            0xCBB9D6A921E024E5ULL, 0xB8B52C6A7F39AA40ULL, 0x57E51853F4BCB6F4ULL, 0xB537AD1800A9146CULL, 
            0x078E45621DFD3CF3ULL, 0xD88BC5F021BEE328ULL, 0x5109A114EE12AB0BULL, 0x8384C79F8FDAA2CFULL, 
            0x900456E9A2F1A464ULL, 0xA6341795A9C128FAULL, 0xC17F3CC28EDE8588ULL, 0x0DBB50F49BB45831ULL, 
            0x01433C2980940F3EULL, 0x114FFC9D03199DEEULL, 0x670E631287F629ABULL, 0x2CBF7B94A074D9F3ULL, 
            0xF394B9921A868AB1ULL, 0x999406812C300122ULL, 0xEE795DAF173A9EF6ULL, 0x2CBB395D7530C098ULL, 
            0xA9706397EB98DA7BULL, 0x53B255FB84D3C858ULL, 0x4929AB25DD60EF4FULL, 0x4A2F354BE5316864ULL, 
            0xDF4B5D9A60D50292ULL, 0x5BDC6A51B94DC260ULL, 0x498CC648D7970589ULL, 0x46CA1AE53E9CB020ULL
        },
        {
            0x7F540C445E1EE212ULL, 0x12B4D7ED0A747753ULL, 0x5F40D663FAF109CBULL, 0x0A1E6F237456DBEFULL, 
            0x1ACA35C98F033190ULL, 0x63E4322EB840DC70ULL, 0x9B3B1BAE46B01ACCULL, 0x38619DABEAE7587FULL, 
            0x3D195F4270322D03ULL, 0x37584F0DE9AB3D11ULL, 0x97C424DA6B47969EULL, 0x707B77B48E4EF07CULL, 
            0x43834F9357F7ECC4ULL, 0x1A0288462C03D18BULL, 0xCA10731401FF9710ULL, 0x451CF11D46794C2BULL, 
            0xF4C36A22CD2D0582ULL, 0x18612F6C03067A4BULL, 0xAEC90262EFA68C85ULL, 0x85B9899830FEC250ULL, 
            0xEDA9A7ACABF41664ULL, 0xBFC1E6387B8C89F4ULL, 0xDC6D68CC1E51546BULL, 0xF1091E601B0EDB0AULL, 
            0x944551C331557ADFULL, 0xF1BCE353FCF3D8F0ULL, 0x4DBDB0D3C9853F15ULL, 0x26B3D91643B872D1ULL, 
            0xFA5C2FF83DBB5147ULL, 0x2F1EF1C60787982CULL, 0x74030E1FF58F23D3ULL, 0x49EEDD9D4F1043E9ULL
        },
        {
            0xAC39CA037B27A921ULL, 0x55DD0D14B786793AULL, 0x29FB01F4C0C2D924ULL, 0x52A3D28ADEF03672ULL, 
            0x0FA3B22166E53B8BULL, 0xF35786596162DE02ULL, 0x67BD9DBA7E9245A9ULL, 0x8D5188B79541440FULL, 
            0x2FE03185F037152EULL, 0x3303C27D46984610ULL, 0x48AF1D57EFA4AAC2ULL, 0x7C151F502027DEEFULL, 
            0x019F7705B0A3607EULL, 0x5B73943388588152ULL, 0x7DF8894020349E4DULL, 0xC4CCE87011608929ULL, 
            0xA57789EF12707646ULL, 0x8FFBC206930BCBD8ULL, 0x8B48E91A9CFF5B0BULL, 0xD6247F20E090503AULL, 
            0x6A8C06788742FD05ULL, 0xABD4B542919E23F7ULL, 0x3515602696A91B2AULL, 0xE43D778175E85A47ULL, 
            0xB014BB519DD4B355ULL, 0x0DD0019318302DB3ULL, 0x2410F80FDFBF9D98ULL, 0x38D3FCB8BE7E1187ULL, 
            0x7B2B23F00417BAA0ULL, 0xA85FB7CD2B9ED586ULL, 0x5791B1837424079EULL, 0x0DE5FA534E752042ULL
        },
        {
            0xF8364CA00504F303ULL, 0x04FAD1C7B503A607ULL, 0x86634B93BE121E4DULL, 0xE1C6EE66B61AE68FULL, 
            0x5663AF343FC22BD6ULL, 0xD31FFC6B71963C3BULL, 0xCFC48FE4785F7B04ULL, 0x095F20DDC417F35CULL, 
            0x3C7B643C10A8D9AEULL, 0x32A30092C219B049ULL, 0x61916B548DFD29D7ULL, 0x6CE93AF2053AAFE4ULL, 
            0x8E5C41879B8935ADULL, 0x6E90171636276051ULL, 0x71F0BC5CBB77ECA9ULL, 0xB58DD4D901F74542ULL, 
            0x7E06847633625B9AULL, 0x35F698E6E97FD734ULL, 0x77FC2389390F6F10ULL, 0x5DD592E573A776A2ULL, 
            0xA19EEABFF47CA5E4ULL, 0x13D4647EE4E1135FULL, 0xCEDCF3CC303EF85FULL, 0xAFA4BA37103F1B3AULL, 
            0x4C894FDB1539BF17ULL, 0x08FB2E9D06B06CFCULL, 0xAE2FD93B532094E6ULL, 0x4D051716D1CF143FULL, 
            0xDDC80E1305FAA8DCULL, 0xB5E179A6293DE402ULL, 0xD6650AE7351DB6FCULL, 0x9341F1F155500048ULL
        }
    },
    {
        {
            0x9611359D518E669CULL, 0x1EFEA57A551BBAB6ULL, 0x80E355ECA255F15DULL, 0x09241279B251DFB9ULL, 
            0x7174622516871132ULL, 0x8AEB167B74EB207CULL, 0xD5B40438E3FFAD54ULL, 0x8DFBA0167C396468ULL, 
            0xB0B01490A67843FBULL, 0x400C79E85AEF9380ULL, 0xC8BF59E17DDC46D0ULL, 0x3CE762DF84BC5E62ULL, 
            0x18B4F5C676FAF215ULL, 0x2694ABFFD27A5E96ULL, 0x887FD12063C0BC19ULL, 0x3D98A8C058781B16ULL, 
            0x513C957CD8A9775EULL, 0x55725D02D660C933ULL, 0x2B00F7744B67E508ULL, 0xF046FFC9E380AC84ULL, 
            0xA43402CD1928C7FCULL, 0x6635625061709261ULL, 0xCABDD6E353F1BBC2ULL, 0xC990DD5D717BEF23ULL, 
            0x36F34724F8869232ULL, 0x605B075C185923CCULL, 0xD4716D768150C05BULL, 0x0276A14109CF56D4ULL, 
            0x5B31F27CBA1E4EC2ULL, 0xA7FE855A68B02461ULL, 0xDB78EF9BA9C62951ULL, 0xDEAA8288180E8087ULL
        },
        {
            0xE5456264526A1DFAULL, 0x18723908E74CFE1BULL, 0x418C291991468F1CULL, 0x8B14B3BD1A81D6FBULL, 
            0x1516928CD569A122ULL, 0x8BB773BF93F9717DULL, 0xF0C29C8AFA0CBD2EULL, 0xE5E1CE248F5140FCULL, 
            0x331174DB7A1145ACULL, 0xF1740E674A3BCF5AULL, 0x1759F38AADDBE876ULL, 0xCDD981A506FBD604ULL, 
            0x749A094DB962132BULL, 0xA9F3591F9EFD83ACULL, 0x59740BABEFF75373ULL, 0x8232AEF58FCDD54EULL, 
            0xD3855E3D6C172A2FULL, 0x77AC70CC227B8E14ULL, 0xEE74EFE751D35D42ULL, 0x56F9CBC99170C4D1ULL, 
            0x8D9B19E9C21D1798ULL, 0x5E6B41427F13A107ULL, 0x8232B5C66B2C8635ULL, 0xB8343656FE2FDF14ULL, 
            0x9193955666AF423BULL, 0xC7E724A0073A25D6ULL, 0x3F916801F9DFF491ULL, 0x6B9A3C511435F731ULL, 
            0x91BA7D3C76545D61ULL, 0x76BB6E221C33B44BULL, 0xDD5311CC2B60F7B6ULL, 0x8393C3CDF8DF379AULL
        },
        {
            0x550CADF966595731ULL, 0x1B0DA9567BCA3DBAULL, 0xA061E6C6F58E3ACFULL, 0x49473EB5EF9636CDULL, 
            0x1F4EBF9580D3B396ULL, 0xE7883FA03F35D3F9ULL, 0x6850C6CBC23A233FULL, 0xFF6EFEB91B96E912ULL, 
            0x8CEC888D0F9958ADULL, 0x8099BD45EC90C7E5ULL, 0x6C8B1D6752C9A9D2ULL, 0x8D5A8FCDF62D8CD3ULL, 
            0xCFCBAD586D18D642ULL, 0xFAC20E9A6FC0ED1EULL, 0xF016408DA1AB57C2ULL, 0x6B2219DD6B07F746ULL, 
            0xAFC4E3FC89109A7CULL, 0xE5FBC5EC6718D266ULL, 0x3C015685473E8236ULL, 0x6C9205EDBBDD3869ULL, 
            0xAC275562A2A5E086ULL, 0x6D3623D00D085E3CULL, 0x32608B42F312AF46ULL, 0x723A04314B8F18F3ULL, 
            0xEB9EE2B9EC8C1509ULL, 0x8F8A40F7DC465FF2ULL, 0xDFEEC0AB5208FB39ULL, 0x3BDF606AB47DE92FULL, 
            0x85B2625DFF3D0682ULL, 0x9EC1158E8E0CD3AEULL, 0x015F864E2603A7CCULL, 0x9EFC4DC0B7538C7CULL
        },
        {
            0x8C10670D880FD812ULL, 0x9C687CDB3CA9F7E8ULL, 0xA61537202C4C91B4ULL, 0x3D758FCDDE27945DULL, 
            0x3EBFD2FD7C0A6148ULL, 0x84ABF26664CDFE4FULL, 0xBDBCBED369EA4E09ULL, 0x36FDE1ABF37D55DAULL, 
            0xC7A6A8A31B5DF07DULL, 0xA611736FB1DB69CEULL, 0x54DA906B82E54FC7ULL, 0x9592520278905D5DULL, 
            0x091A9BBEFBBB423FULL, 0xE9B1E51F309E3FD7ULL, 0x6D7D4FC9CB5AFD23ULL, 0xB728FDA5481F9F26ULL, 
            0x71B05511FDF96440ULL, 0x5DC12D91EDB6FD79ULL, 0x7418B4D1D53E605AULL, 0x1B3C1F45571C7911ULL, 
            0xFC1D7B9E65F37062ULL, 0x8CBA7BE9356F16D7ULL, 0x01669ACE0E566736ULL, 0xEF1C7D1F5BFBEAC1ULL, 
            0x0FC26FDCD94015B8ULL, 0xDB5BCC8CC5201C7EULL, 0xD7AFBB298E98F55BULL, 0x33DD1858D0421BB9ULL, 
            0x78BED2273EE35492ULL, 0x689935482E2ABF8CULL, 0xE993CA517E14EA5FULL, 0xFDB7F55CE71BEB66ULL
        },
        {
            0x72B8043D388E9AC0ULL, 0x6FB39890A9F041F6ULL, 0x9685983F55C2868AULL, 0x018348A7CC4C1DA1ULL, 
            0xA77BB7FA5060B7B1ULL, 0xFC3846A2BFF23D4AULL, 0x3E1684BD49BF6A15ULL, 0xC12028BBBC505B8BULL, 
            0xEB10767FC45F8F0CULL, 0xB78B8B78BDB1C0D1ULL, 0xDEA290D8FFFE8AFEULL, 0x9F0395F6AC7C28F6ULL, 
            0x3980368A6945C994ULL, 0x76D249B3D5B3716BULL, 0x18753E84F6154908ULL, 0x8A0E46D5CBF7F2B4ULL, 
            0x631AC1912ED1EE82ULL, 0x7817D3D03474C421ULL, 0x7A85AFE950A703B7ULL, 0xCD77D475BCE124F2ULL, 
            0x9D392C0EC8C761FEULL, 0xBF238EB6B1F3C136ULL, 0x6EBACFA871CB1ACBULL, 0xEEB99150944A6194ULL, 
            0xD5E77A59A86B2077ULL, 0xDDA9FBC12253A63FULL, 0xC6B4D1B499B2B2D7ULL, 0x2258E0A9EB975C69ULL, 
            0xD8706401A31920E0ULL, 0xBF638F4B27AB69A8ULL, 0xD09957D838E74264ULL, 0x3645C628B6A9DFFBULL
        },
        {
            0x922AF27B9C19A5F7ULL, 0xD4E82431CA3480CFULL, 0xA30928F0FCF16770ULL, 0x91A319A704F194B1ULL, 
            0xDBA423DDC0703047ULL, 0x932B23A5CFA1A1E5ULL, 0x1DB85957A4F7AE9DULL, 0xB17D80D93FC1D996ULL, 
            0x3424867B9F0339E2ULL, 0x9B3D413300864DD1ULL, 0x43DACC5A5B1AC82AULL, 0x1E8E20275D2D59AEULL, 
            0x899D3FC693A88B14ULL, 0xE4D7A660FA7AA56CULL, 0x046B7C64631A29D6ULL, 0xA9E151DF580C0060ULL, 
            0xA6335A4B91AB95E1ULL, 0x0A24B72FDB56B8FEULL, 0xB10C88A584246B02ULL, 0x31465B294A01496EULL, 
            0x5B99012C35FCF9CEULL, 0x877766CCB2C9A47BULL, 0x519055736C36F3FEULL, 0x25975770CD8EE982ULL, 
            0x0671C18101AA00AEULL, 0x63999C6B3A52AEC7ULL, 0x6CAA73F8F239CDEBULL, 0x6D85A7F140ED83A6ULL, 
            0xC36706265A2728AEULL, 0x5D1C98EE747370FFULL, 0x2B1355F0A1F0041EULL, 0x5B0FC15122155AB0ULL
        }
    },
    {
        {
            0x0F74035BC8C962E8ULL, 0x056FB06322C29FE4ULL, 0xE13C0843E83FD64FULL, 0x5954C08519CC02EFULL, 
            0xD02D211967DFFBDBULL, 0x047EC2EFC6B82FCAULL, 0x505F331A99FFD459ULL, 0x74A7D255EACC9DAFULL, 
            0x0E219FD7A10757C9ULL, 0x60CF0C4C8F8C4B3AULL, 0xC23DF9560DEE4190ULL, 0x68B7DCEB8D2C10AEULL, 
            0x86BA82E6984F10DBULL, 0x56DD3854E8EEDFD0ULL, 0xEF5F1EB102F3794EULL, 0x31682C1DA82095C5ULL, 
            0xB802A3407B5FFC15ULL, 0x259EBD2EDE1F867EULL, 0xD9B77F0DC5C467D0ULL, 0xA0EAA7D2C9C3B8B1ULL, 
            0xBE5D3F7F2D2FCD1CULL, 0x863E86752B249538ULL, 0xAF1D8FAB68C1A875ULL, 0x01512714768D63CBULL, 
            0x0EF03FFD2AD9CBB3ULL, 0x33AE6A5418300F3EULL, 0x2D5D86ABBE36225AULL, 0xE0D055DCCDEC8D0AULL, 
            0xC406AC52AAB05541ULL, 0x908EB89D741587DEULL, 0xF7123B75A5658C63ULL, 0x90AB3316E6F20CB0ULL
        },
        {
            0xF65C21A80AB38179ULL, 0xFE44043876282CB6ULL, 0x99C13639AAD56990ULL, 0x89A3E37221CF8EA0ULL, 
            0x99BD86499522BB4CULL, 0x842856C473F53C24ULL, 0x79EB9C411D51C0DAULL, 0x5DE968292E70F4ABULL, 
            0xE094595FBA972619ULL, 0x6C579A4417982E7AULL, 0xD553037FA342A6C3ULL, 0x1A46AB5C96ECA522ULL, 
            0x297470D37EC8B8C7ULL, 0xCBC27C0CA0262276ULL, 0x405A08AD066A15F8ULL, 0xAF2919803AD60F92ULL, 
            0x82F419A07D382F30ULL, 0x4345CE5E7304F41BULL, 0x2AD5A6D0CE810DBCULL, 0x2EA14A2330C5D41FULL, 
            0xC844169861E4D430ULL, 0xD58DB4C82B6A9625ULL, 0x483DD45EB64EA3FFULL, 0x97947014BABAD482ULL, 
            0x10D1A60F3967B874ULL, 0xB19A29344D6FBF78ULL, 0x64DE9FAA80C80A5EULL, 0x66539656C73C0D29ULL, 
            0x41390DE1AF3D60C6ULL, 0x12EE5D50649B9593ULL, 0x9B6AE8FE21CA34CBULL, 0x980396C6EF3A59BFULL
        },
        {
            0x57FBB17E9D9BB0B6ULL, 0x5DCC3B15A05DB0F3ULL, 0xC185E43D23666B60ULL, 0x841BEBF79E22CBE2ULL, 
            0xDEA3532127AF3376ULL, 0xA7B9F189F6480F7EULL, 0xE4F201A78CC122F0ULL, 0xD3E6F281098B5D79ULL, 
            0x524CC1B0F0BACBA9ULL, 0x0EEF6A0883D6D517ULL, 0xFC210A8AF61CAA7AULL, 0xA3955CD88125192FULL, 
            0x79DA34C09C6B2C14ULL, 0x01FE8DBAA7F2483AULL, 0xD8DB53E15349E27FULL, 0x8F733C17269C0E70ULL, 
            0xFE404F3E8FB98241ULL, 0xA2F2C81D0E76979BULL, 0xD82568C76003A5FEULL, 0x5578D6A85E26191DULL, 
            0x5CFC468A0C12939BULL, 0x47A6692EBE7BC4F8ULL, 0xBC265ED56D1D304CULL, 0x93086F76D2029BDAULL, 
            0xCC1026844C6E9D0DULL, 0xE7C3E9E886BEC798ULL, 0x70F5DBA15F3D837AULL, 0x20CBADAD54066318ULL, 
            0x7322B765A7C5B47AULL, 0x7ECAA64F0DA8FA22ULL, 0x6154174601516740ULL, 0x1FE71C3442B7B476ULL
        },
        {
            0x7DB526E3B7B2C4DBULL, 0x89F2734FAEBF4468ULL, 0x1D600AB471655F50ULL, 0x4FA89D7059D871C4ULL, 
            0x4E2C4288EB85E45FULL, 0xE03AA0F49898CD03ULL, 0xC2F0031909984511ULL, 0x059B16D7E26E8D77ULL, 
            0x8F93A7C2D8E06DD4ULL, 0x917EAC66AA1F2175ULL, 0x9D555D01C549E729ULL, 0xA416D9C87DFE4BB6ULL, 
            0xFE1684B41BDC2A2BULL, 0xE6B6DFBA343F1F3BULL, 0x861AA7C2A8B21594ULL, 0x44FDBF8CABFA0FFDULL, 
            0x38C1608FF60B86B9ULL, 0x151EFF7FB6A4AD58ULL, 0xB16B6749493D5067ULL, 0x720AD47F333AF29FULL, 
            0x011E6CCA23835F60ULL, 0x434C5FA87B684901ULL, 0xFAF7491D5981C0D6ULL, 0xC57637811268EB58ULL, 
            0xD97AE5F1E60EF4EAULL, 0x71EA6E76754F31E4ULL, 0x0490B95B5B730D0EULL, 0x03B503216A5CCB80ULL, 
            0x683E19EC26B8594FULL, 0xA65EE6BDD2B4E0D1ULL, 0x76F7FC646AD2819EULL, 0xBF2A7C5D9BD8DAD7ULL
        },
        {
            0xBB33BAC75AF41A08ULL, 0x60870A19E9753DE7ULL, 0x549305BD7B6FDDF3ULL, 0xF9490C6B9F4F4E3DULL, 
            0x90D64F452735F740ULL, 0x581E3B0C543B30FDULL, 0x870B4E3BC77753E8ULL, 0x94317907549B886CULL, 
            0xF9B357EB69278736ULL, 0x5A8AC8A2C36D4635ULL, 0x533717916DA6E83DULL, 0x26A71BDF7E23283EULL, 
            0x0E3EE9F7775139E4ULL, 0xBCA40767F9690C8DULL, 0x13E732569A5A4283ULL, 0xA0372F0ACCCEA1E0ULL, 
            0xA9FC4BB50EF0F255ULL, 0x918024A52C673092ULL, 0x796C0625BD0B7D2DULL, 0xADADA2A173047727ULL, 
            0xA19674308B8249F3ULL, 0xE02BDA2821C680E0ULL, 0xF89900EF8CD56F20ULL, 0xAFBA08A869B4F5ADULL, 
            0xCA4BA5E411F0F31BULL, 0xBA7F02426D88AACDULL, 0x010998D50B0B5C5EULL, 0xC4CE1291385FE0F5ULL, 
            0xEF11836FC810C878ULL, 0x80863E18842E198CULL, 0xE5767A004CFA5E29ULL, 0xF2C94F377E74450EULL
        },
        {
            0x849BAB005780E4F8ULL, 0x9DDC8866E98B2BECULL, 0x0E98D3F55DB708D6ULL, 0xE9E16EE41AF4E4B7ULL, 
            0xBF8E3E1E2B0E3972ULL, 0x0EE257210F333F57ULL, 0xE56B6FCCB568EBD9ULL, 0x829A84B1C533CBC9ULL, 
            0x042BFA0176FFC511ULL, 0x0F4FA5D5871682EBULL, 0xE2E31CA34CBA7483ULL, 0x1535E4B80A7C5874ULL, 
            0x89F5F1E6EED20E8DULL, 0xD477F142EE68B819ULL, 0x5593A580B8D5EFFFULL, 0x1C5BEED16B5C0009ULL, 
            0x4241994575CC81C9ULL, 0xCA7542D17BCCBDAEULL, 0x15A574F57B9B4F1BULL, 0x2F37D0235BF81043ULL, 
            0x6ECF7E686805E695ULL, 0x4F25A1E0BEA52A9BULL, 0xA276F39A515E05A4ULL, 0x5A92F4B2977989CCULL, 
            0x2B56A270F9EC008BULL, 0x75F32849C0D14F99ULL, 0x1FB5762F00B6AF63ULL, 0xF975DA9C3545A0F1ULL, 
            0xF751CB4CE4B1D057ULL, 0xF3652841EA4D4236ULL, 0x96F547B81EEF3035ULL, 0xB944AB452EEA430AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseDConstants = {
    0x94A2D8510DCEE6A1ULL,
    0x57B999BFEBB4E74BULL,
    0x43F739DE3D77A4B6ULL,
    0x94A2D8510DCEE6A1ULL,
    0x57B999BFEBB4E74BULL,
    0x43F739DE3D77A4B6ULL,
    0xDBBB41AE9AE208F5ULL,
    0xD02D60948F9382DEULL,
    0xA1,
    0x10,
    0xD9,
    0x08,
    0x3F,
    0x57,
    0xCB,
    0xB5
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseESalts = {
    {
        {
            0x2FA1AF88E6AEDD6CULL, 0x6742EFB41F70E9C0ULL, 0xAC289F693FF5DF40ULL, 0xF890B2C7CE5C0E43ULL, 
            0x1E2D1C3810315C20ULL, 0x7B9F8F2092FA83A8ULL, 0x357EC65D64C71269ULL, 0x49FB4752248E3C4BULL, 
            0xFAA97E28D53B1A0DULL, 0xA26F48741678E931ULL, 0xB12946896424DA13ULL, 0x0FA5FF13F1508D6EULL, 
            0x1F51E8D5EE3F81ADULL, 0x1867BD9D92953CA8ULL, 0xC19D9FF6FAFC6CE0ULL, 0x85BA4E7D57FD5748ULL, 
            0x5DF4AC96CE3D15E9ULL, 0xFAF364A6B24E34C9ULL, 0xAB1307CE38638133ULL, 0x9E055D32BCD1CCDAULL, 
            0xD209CE041135F591ULL, 0x34F2065A4D89701EULL, 0xA02CDB86EF0A9111ULL, 0x24A48C550FF5F330ULL, 
            0x2F428568860F6BCAULL, 0x7DBA834595C759F5ULL, 0x170AC4A7D94ABD5AULL, 0x476823B95FDE1A26ULL, 
            0xBA3C012D57B8F2ABULL, 0xE936C91126EC3864ULL, 0xB0D2934B95100F09ULL, 0x59B1D83C7ED46DCAULL
        },
        {
            0xEC4AC07C04DB3580ULL, 0xCCB1D4B0C13457BBULL, 0x758CAEF9143CAFC2ULL, 0xE90DEE50C90289C1ULL, 
            0xFE7F126B3F9425B8ULL, 0x8863C6B03E171E93ULL, 0x2BC05871FF26444DULL, 0x4C04A4FE5061892DULL, 
            0x3C85D4ED30CC0DD2ULL, 0xC6BC0B14235DA968ULL, 0xB9B917CDCD065C08ULL, 0x43A108333A62FC89ULL, 
            0x91F214E974C46EA5ULL, 0x16C0E156FD69F7EBULL, 0x3B6BD56033B30366ULL, 0xD4FBE137437860D3ULL, 
            0xFB6DA920CA5C50D2ULL, 0xDD4B6F48A2F61819ULL, 0x31C8E0B76E0FA778ULL, 0x58329335BF7EED50ULL, 
            0xAD49C9BBDD409339ULL, 0x1F3D216AD2A069E9ULL, 0xDA588858AEE39754ULL, 0xCD0E6BF33CCC24FBULL, 
            0x21E418B638B0AEA3ULL, 0x4F116E0807428C8BULL, 0x748A12AABF6A9970ULL, 0xA1897F7FC6FBAB53ULL, 
            0xEB8C30C96AD8DF1AULL, 0x39AB4A703C2D3819ULL, 0x59A37816BF098B10ULL, 0x1F500747147DFA85ULL
        },
        {
            0x733F824E0EBDC243ULL, 0xCF77D475ED2EE415ULL, 0x79673365AA51A6C8ULL, 0x41E17F4E39F1CA1AULL, 
            0x3524BAACC93D2C18ULL, 0xE2084EFA6F9D3356ULL, 0xF7B046D3F6D594EDULL, 0x92EAE7054AAF49E6ULL, 
            0xD58439FBECE83968ULL, 0x7D137505C4A2795EULL, 0xB2FDEBDE23284178ULL, 0x896EE5E45ECE6C64ULL, 
            0x7D0C0F195421B5B7ULL, 0x7D43CA770ABC71C2ULL, 0xD2B84B7DCCA7DA85ULL, 0x9E7B87F04A6D13C8ULL, 
            0x679A7F986230B47DULL, 0xABCEA27BD7DA45ACULL, 0xD07A712955101DDBULL, 0xF08B29AA225B57ABULL, 
            0xA20300C98F2617B9ULL, 0x587EC325962872F1ULL, 0x67741E72725CCCDBULL, 0x5B50EAFDC4F58ADAULL, 
            0x899AD4AF914DE857ULL, 0x60957A0FBC682E69ULL, 0xE25D3199246410E9ULL, 0xEDD61BFB55E07292ULL, 
            0xEF5D8CE3CF6BA2BDULL, 0x289D2494F07F5F98ULL, 0x2F118F87EC8728F3ULL, 0x074E41F35BA9993AULL
        },
        {
            0xF9E0FBCA44306356ULL, 0x2A574C7B29F63B3BULL, 0xE7B62353AD402BDAULL, 0x70D8B9287510F847ULL, 
            0x42249B2EC6A08FC0ULL, 0x8C58C98FC6BCCA82ULL, 0x8950F00CAB37D0E5ULL, 0x105799CAD84B8A4EULL, 
            0xA5297DB895EDC235ULL, 0xB4BCDAE23ABF7628ULL, 0xCC8EC66C03DC1D51ULL, 0x78379F0A97CF0756ULL, 
            0x09005DA82221476EULL, 0x10AB22DFB466897DULL, 0x055329012CDF6BE2ULL, 0xB5141DD0AE5914CAULL, 
            0x50EFF27192AD622BULL, 0xBE799BD00ED0BEE6ULL, 0xFBBBA347733DACD0ULL, 0xE8DF306B6F0DB926ULL, 
            0x426B10474CFDA2EBULL, 0x273FF5072C1D1D83ULL, 0xA6984E1CDB274382ULL, 0xCA9154AF345D3AC6ULL, 
            0xA0254DCE0EDC0C79ULL, 0x563AFDB2DF34D83BULL, 0x47AFE85EA9C8DB30ULL, 0xBAA7EB9BEEB4FEB4ULL, 
            0xD21B7C953BD81640ULL, 0x4E513BE68E5C4FB2ULL, 0x37007F19BBD6DEE9ULL, 0xD5DDBD11D2136078ULL
        },
        {
            0x9007D6518CEB6815ULL, 0x46DAF9ADB2F71FA6ULL, 0x19644081682D9D08ULL, 0x67DE736D2A78E81AULL, 
            0xBE411E2DBC89320DULL, 0x4BC38BD601D32F27ULL, 0x8DEB97A6D875070CULL, 0x1F406B8252A17858ULL, 
            0x3EDD75B7F63F77B8ULL, 0x90774FBC06F549CBULL, 0x431D31ED8A444170ULL, 0x47A3B717CF75898FULL, 
            0xAA7E5B10378EDFD2ULL, 0xBB193B7E1E8C1D2BULL, 0x28AD810D873602BDULL, 0xD40BEE48460D0267ULL, 
            0xF8BD4CF4B96DB480ULL, 0x832603C1B8D29F49ULL, 0x0C5E67EF6B911AF8ULL, 0x305ED49250729C7DULL, 
            0xD1DB9183062795CFULL, 0x22232BA25B5FE61CULL, 0x4D48AE5989052675ULL, 0x82954A9A8FB463C8ULL, 
            0xF9EA2EA0F4BC708AULL, 0xB53B9ED92D056790ULL, 0xAAE94DB0D801E367ULL, 0x3F7023C7B313FD2AULL, 
            0xE158736FDC88F3FEULL, 0x63369988B4715BD5ULL, 0xE12613BE2DC5D6D6ULL, 0xE86315ADA1A32818ULL
        },
        {
            0x8D9FA20B2FFB233EULL, 0xACA21E15603C27A3ULL, 0xACA7061B7D6B60B8ULL, 0xD39BF5733B6ED84CULL, 
            0x3B645BB8427097E9ULL, 0xC1FA7299C415853AULL, 0xD9ED932B37B1A289ULL, 0x2442C3E277F50472ULL, 
            0x8D2D0B2CD5852700ULL, 0x377ECBC0187175BAULL, 0xB77972DE03A7280DULL, 0x12667756FB0DCCFAULL, 
            0xDCA64E11EB206852ULL, 0x487FBE6D3B51F031ULL, 0x9AF9AC9FEAC0CECDULL, 0xDDDD23D0C356AF64ULL, 
            0xEABCF4A2212EC029ULL, 0xCAC93E44822D4270ULL, 0xF983DB55B6515D81ULL, 0x09BE541AF2AB6717ULL, 
            0xC0BD1925F70A574FULL, 0x774F6194A9A69AD6ULL, 0xCDA66122FA827572ULL, 0xA73921468DB77C8FULL, 
            0xD1A2B1D2E0331DA4ULL, 0xAB6AFD922AB3A41CULL, 0xA628720F9E84181DULL, 0x5F8632D2B8DA2D29ULL, 
            0xFDA03C992D224A81ULL, 0xF55EEFB042FEF623ULL, 0xDF2D85D559985415ULL, 0xA1F623978AE24537ULL
        }
    },
    {
        {
            0x8AB6FE2463516D43ULL, 0x59161F4FF8B5A16EULL, 0xF5F48213317FDBF4ULL, 0x9038863068E99033ULL, 
            0x9607216306216F50ULL, 0x2D1A25B9DE9D7CD6ULL, 0x493F0AB6C3DA60D6ULL, 0x1CB451E4C4243E9CULL, 
            0x0DFFCD947611A30BULL, 0xA6618C15C1ACC54AULL, 0x8F861440CACC30B5ULL, 0x30ABDC84C91160D3ULL, 
            0xF063A1572B49A7BDULL, 0xB5F806E5B2897388ULL, 0x36F2C86F94CBC254ULL, 0x35C0C5EB605955DCULL, 
            0x2F0074F3EC69C59AULL, 0xF6FB4981BA3A6510ULL, 0xABA980EC986CC92DULL, 0xD87A3F4D1090E3E3ULL, 
            0x0155EB4F8FF64A7DULL, 0x03DD6073FAC8E49CULL, 0x8DE20D0026A7C00DULL, 0x66EBFE750B4DF895ULL, 
            0xE28A07943384AB9AULL, 0x8263673289AB539CULL, 0x8AFBF623A2401422ULL, 0xE54B2FC283F96431ULL, 
            0xDF099566E80692ECULL, 0x4941A4412171E00CULL, 0xC7604A663B41D044ULL, 0x93F99FFCCC18BE2EULL
        },
        {
            0x1A64067770529D68ULL, 0x599EF8A506A730A2ULL, 0x13E32F2DAE5E6755ULL, 0x6C06AE20976F22FDULL, 
            0xD41023E815B8346CULL, 0xE8093248BFAA996EULL, 0xD1D36510251A982CULL, 0x5FF33BC3C2802D9CULL, 
            0xBDFCAA1D884864AEULL, 0x6EF3758B2339555BULL, 0xE8A4DC6D7C02D156ULL, 0x093742CF7C794CCFULL, 
            0x6AB54F335159EA72ULL, 0xE72277084AD9BBBCULL, 0xA534D02311AEE7B9ULL, 0x5ACCA2D8D43D45C2ULL, 
            0xB90A8EF559CA3554ULL, 0x40B2F8E384EEC810ULL, 0x0119F9B84E962874ULL, 0x2E65CB2443D2D2D2ULL, 
            0xEC0151E5ACA88550ULL, 0x1005D7700E238960ULL, 0xDAE6C00ECBDCB832ULL, 0xEACB7CAD0FFAC0CEULL, 
            0x345EE4E7838013C4ULL, 0x9553CA1292AFFE26ULL, 0x83CC386EDE5B6265ULL, 0xCED73B6B68D58091ULL, 
            0xAB5C30461CADB43FULL, 0x0771DD6C168A507CULL, 0x4585EC2127AEAE9DULL, 0x81CBFEEF3CEF43DEULL
        },
        {
            0x6417693A8DC77376ULL, 0x9A01BAEEA56AB651ULL, 0x19BC2B7BB74B0CF7ULL, 0x210F5700BF2FB6C3ULL, 
            0x4A3623E3A974D11BULL, 0x1CF3CACB68A7C09CULL, 0x7A23E3816EF9BB42ULL, 0xA1865F7723BBA5A5ULL, 
            0x443967F6EB052FF2ULL, 0xBABDCA23F09959BEULL, 0x69F1BB424660EC3BULL, 0x8DAD24BC0B11A645ULL, 
            0x4FDA83BCEBDAEDEBULL, 0x428D5A67DE784DE3ULL, 0xA19756DF0E177390ULL, 0xBFD0F078994193BAULL, 
            0x78F1CA6FD328B19CULL, 0xF0003D617ADB9212ULL, 0xD32E535CE4B18ED3ULL, 0xD64C90203CDCC8F0ULL, 
            0x5BA5771F46832508ULL, 0x4582C294CC1C3E0CULL, 0x8B56BC07AC5286D1ULL, 0x040E550B88B1A455ULL, 
            0x7E4755418DBC75F2ULL, 0xCAE0594E1448F139ULL, 0xBD984EFEC1BD0F46ULL, 0x3B23E52B8889345EULL, 
            0xEE75DDDCD7177F30ULL, 0x7470AD340C90B42CULL, 0x92892DC51793CA08ULL, 0xE3888BA011975D55ULL
        },
        {
            0x304634E941B25882ULL, 0xF1D7E862BC84AC35ULL, 0x090D6ED5F7EE29C7ULL, 0x9F423F2526C8F684ULL, 
            0x7EF382101F105443ULL, 0x196A0EC0816AC675ULL, 0xEB0463A7A8B764B2ULL, 0x5174F644B59AEC20ULL, 
            0xC4E151749C0D2CE3ULL, 0x5EA068DC6BFB450FULL, 0x43B19548555278F6ULL, 0x90CD4C5888B35089ULL, 
            0xC4C807F2526560C0ULL, 0x6EB64BF5BEC2535DULL, 0x764D75BE28EDDDDCULL, 0x6CFB32864246053FULL, 
            0x4EC3CFBE76259CA1ULL, 0xD2B9DC337C6AD695ULL, 0x7C90A70F898DA714ULL, 0xA7DAB0D70A252BBBULL, 
            0x0CACE13BEFDBDF6CULL, 0x5A2DC9F0E9D9B6BBULL, 0xF81C18ACF3A9ECDBULL, 0x64170A29449C79CBULL, 
            0x30B5F67531B098E9ULL, 0xE92E7CAF9C9B279DULL, 0x87A9CBCB2E4BF5F5ULL, 0xF4233AFF0C0F0E45ULL, 
            0x4AB95E05E1D9666EULL, 0x540C8AED8F9CB757ULL, 0xE7F95CF00678DBC6ULL, 0xA4B4FD4FB92ED60DULL
        },
        {
            0xFC30CF5C51D15B23ULL, 0xCAEB0932DBFD4905ULL, 0xC19680D44F7734A2ULL, 0xF63ADE1C9047D069ULL, 
            0x89C76B04626E065BULL, 0xAA37AA0AE036FB7FULL, 0xCC9FF749E649F0B4ULL, 0x42AE58C503A8C7FDULL, 
            0xADF9D34378151B5CULL, 0xDA32CAE97C6491F4ULL, 0xE55D9B7925AA4F94ULL, 0xE7B23A62B4E47157ULL, 
            0x08B7ACDBECD37A02ULL, 0xB342934D80DD8736ULL, 0x60C22FBC57A00361ULL, 0xBF64A596ED0361F0ULL, 
            0x32F6A4745E9AC3F6ULL, 0xD2D13C8AA9CCEB86ULL, 0x5DCE3C96E4E1CEA2ULL, 0x8C4D45B2C9B504F3ULL, 
            0xB430B9F2FBD2D992ULL, 0xC8BE8933C80C936EULL, 0x0166C8645F81E452ULL, 0x26D9C0F50F91BAF0ULL, 
            0xD3C4C0A2DFC13A84ULL, 0x2FD8A2C05497A702ULL, 0x0BB5529A3DD64705ULL, 0x4894D87C50E5413CULL, 
            0xF1250023A42BC526ULL, 0x9DE53FADA82D30E6ULL, 0x2C45BB49DC007C48ULL, 0xE1542771E724A055ULL
        },
        {
            0x68AADB40FD08684BULL, 0x828E907CCE914281ULL, 0x287E9FBBEC069591ULL, 0x5A95B5D36ADB22F7ULL, 
            0x54525B953D3C7AD8ULL, 0x897195C64696451EULL, 0x1D3E6C518E0A2098ULL, 0xCF30F346A34B764BULL, 
            0xFBA916F743BD9C1EULL, 0x8EBDCD721BC4F2AAULL, 0x40463CA57594BA95ULL, 0x0760B970A3064576ULL, 
            0x0BE65CDFAA21ED88ULL, 0xAC80899E8CB28AC7ULL, 0x2ED63E39444BA134ULL, 0xD45B90F1AD1C3418ULL, 
            0x977875890CB4E264ULL, 0x9A8A336D60E7FF32ULL, 0x7F068C92049BA434ULL, 0x8CCB880AD2AF388EULL, 
            0x80A26E4E1CBC3405ULL, 0xE5B2566D5651E949ULL, 0x8B7DA56D1060E34FULL, 0x4E50E5E9849B59FFULL, 
            0x06DF7A96D195A91EULL, 0x8322E17F27F48EE1ULL, 0x471235644C47BB29ULL, 0x05EC7016D4261F5CULL, 
            0x4B6228DDA238D1AEULL, 0x7D213330B5A520A9ULL, 0x8B9D3140D66B4168ULL, 0x429A3B7BF97E029CULL
        }
    },
    {
        {
            0x3509CC4C6B0018C6ULL, 0xE0D41B89A19567DFULL, 0xB3B9E974B5D67DE2ULL, 0x1325B63E98120065ULL, 
            0x22FF89187C98723BULL, 0x026D19499E2BB452ULL, 0x17F743260AC63B0FULL, 0x32CB1EC2F67B3A98ULL, 
            0x9F74D37CA9886BC3ULL, 0x180012F30331FD3AULL, 0xDD6B37743DDE3843ULL, 0x35D2315F1162565AULL, 
            0xED5AAD8DBEA41969ULL, 0x03EB49601B3156EEULL, 0xC79736406401522AULL, 0x246B6D3EB1214F88ULL, 
            0x4FEF1D5A574DBFFEULL, 0xF6858D9E2B56CB74ULL, 0x31D9C3D5D5175423ULL, 0xA72C3E37B2CD2A20ULL, 
            0xB30DC782095108C1ULL, 0xA4844D52C7C2F07EULL, 0xFAE19542C9BFB94CULL, 0x0396D78E9CAF8FD9ULL, 
            0xBDD35A7C05CBB45EULL, 0xD70ED80ABD773F43ULL, 0xC85000B7D0A8CAB1ULL, 0xEDE4B08675181A5AULL, 
            0xFA5FDEBCCD0BCF64ULL, 0xB7339B32E5F76DBAULL, 0x42714AB404E27A7CULL, 0xDCAF5BD7E46955A8ULL
        },
        {
            0xDD8C218BB3CD5E73ULL, 0x215F4DF1942BB8DDULL, 0xF2F1E9AA3F3C5124ULL, 0x848EE68A0A012F73ULL, 
            0xD31A88703D8374E1ULL, 0xCBE14F7C2227AAEAULL, 0x1908572424DC87D1ULL, 0xC005A51F7253D76EULL, 
            0x0A6C019AFFAC527BULL, 0x0C7AECE6E37E3BA8ULL, 0xC7B76D044449106AULL, 0x9A7FA773867E996AULL, 
            0xF28D2576598F82FDULL, 0x9803868E3A8F0B2AULL, 0x1E97EF22B4175CCFULL, 0x972694B771B789A8ULL, 
            0xCAC4A66FAB811148ULL, 0xFB7A66C829A1F46EULL, 0xFF0106FA0ABD755DULL, 0xEEAE95028A7A17B0ULL, 
            0x046A368211F91029ULL, 0x4525A8D3363DDA6EULL, 0x74EA9CD5C686B76CULL, 0x27F2E0CD084F246EULL, 
            0x99194F22AF412647ULL, 0xA9751C76BF017C18ULL, 0xD639442491F832C2ULL, 0x26D4A4987359C49FULL, 
            0xBD695EAAE694FA0AULL, 0x39CE1CB86CA80E73ULL, 0x9D1564C04CFC910BULL, 0x20E67E69EF784AB3ULL
        },
        {
            0x89EEA2AFB4ED91A7ULL, 0xBBD7B178660396A0ULL, 0xE7E24D9F2716B84DULL, 0xE866C7017A3CAECAULL, 
            0x9163D5940FF53321ULL, 0x1989063F89F5822FULL, 0x755689DD8297169BULL, 0xE84AA4CB8509D80EULL, 
            0xD4CB12B134ABDC9CULL, 0x0D563095769F00C6ULL, 0xA568273DD3C7E046ULL, 0x286D5CAC4DB6BB93ULL, 
            0x973BFF40037D3BA8ULL, 0x2A2454A15C8917A3ULL, 0x8F434EB7D69F14D4ULL, 0xBF030C19DF5F9FC4ULL, 
            0x83DE439FEB8F4420ULL, 0xDBBF6F0B856502DBULL, 0x69EED2E4625FF67DULL, 0x8B347599C9A94312ULL, 
            0xF3F5762261CBA58DULL, 0x08A55E8C08AB02D0ULL, 0x42C2BD083C75E79DULL, 0xF69CC85BBF26B118ULL, 
            0x8B26B59F205C261CULL, 0x71848B82438390C5ULL, 0x1AE53FA95B9DC68BULL, 0xFE758174D55E8776ULL, 
            0x5DDAA5A0AD478070ULL, 0x871B1CE5201338E7ULL, 0x3DBF5A2BB61F7D0EULL, 0xF269C8138FD63517ULL
        },
        {
            0x4AD5D572546EDDDFULL, 0x291889CBB3B3403AULL, 0x0720B99A20C60316ULL, 0xC80B5616F32DD59AULL, 
            0xE1F2D8902EC4E3A8ULL, 0x9AE21514D8BAB602ULL, 0xBF55BC582CC0412EULL, 0x91E720FB843B29D6ULL, 
            0x5C4B3AA93C027354ULL, 0xC15527CC14EBEFEDULL, 0x484F78E62BEAB1C5ULL, 0xEE2B11E400E0F8D0ULL, 
            0x85FB11E22017176BULL, 0x563D0FC657A65B5CULL, 0xDA1682685B4AFC3FULL, 0x75D0056F703B98C3ULL, 
            0xF690E45EC7C6F59AULL, 0x55259CF58E575F28ULL, 0x1C306FBF167ADC75ULL, 0xFBF613985735FAA1ULL, 
            0x77AB52494955B4E2ULL, 0x4ED01EE5C2CE1AA5ULL, 0x1A60ED7F83EDB8EEULL, 0xE34737F53D93B384ULL, 
            0x46623F53A3730FB8ULL, 0x080C47577BFADA0DULL, 0xC126029F0346AAC6ULL, 0x6A1843747A1631BBULL, 
            0xAD25D94F9255DCF2ULL, 0x39D598D76338E3CAULL, 0x7FDBDBC942C8FB87ULL, 0x05615EBDD7F912F1ULL
        },
        {
            0x18A2C04D305BA3D3ULL, 0x2074B0C6FD175484ULL, 0x7F87E9C737445EC2ULL, 0x026BE9C680FA999AULL, 
            0xE2F416F265259015ULL, 0x24317F7414D03F9FULL, 0xECFAE9404ED029B0ULL, 0x902F47B770EE2F91ULL, 
            0x5C029231306727C5ULL, 0xDC1A9365A4A27E4CULL, 0x13B759E97A91139CULL, 0x5D9C6A182B7A7C71ULL, 
            0x0A3DC6CF5AF4E839ULL, 0x8FAD1DF0E9E13CEAULL, 0x33152AD52FD4B69DULL, 0xF0C71475F282A099ULL, 
            0x753DFC44B58736E4ULL, 0x5813A233E9344526ULL, 0xBF112D81244883A5ULL, 0x5B926A58239F0AF2ULL, 
            0xF3D6DE945B2D457DULL, 0xA40EB321516EF052ULL, 0x7A9DD7D920631505ULL, 0x292362B033A70F4CULL, 
            0x51B48CEF48C0347DULL, 0x5320AF1387BAE8C1ULL, 0x96DD6AAA1688DF75ULL, 0x8966ACB031E49145ULL, 
            0xDBB8B7F17FEB1FE3ULL, 0xDB2466FB61E46A3FULL, 0x512A8FEAE543D3CCULL, 0x8D87C924C53CC117ULL
        },
        {
            0x8ED7BC31503C94F1ULL, 0x593EA9B70D7C6675ULL, 0x8E8945F098D1A7B6ULL, 0x591797AEA9C053D4ULL, 
            0x88017130206EBAABULL, 0x5B89CFA51CE43C91ULL, 0x8D0F2819743BD1DCULL, 0x3482701031313664ULL, 
            0xAA612353721AAA4BULL, 0x75F1BD99ED610183ULL, 0x0507F66B77AB1A8CULL, 0xCC2E85858CDEBB5CULL, 
            0x2737136D0EDC08E7ULL, 0xDEAC131B9993AD0BULL, 0x1AB4CA4E8ABB30A4ULL, 0xCE672372FDCF645DULL, 
            0xDDCFD4A7F2932346ULL, 0xAF420FE443B62CE2ULL, 0xFCE8468DB8967020ULL, 0xECEEB48374530215ULL, 
            0xF63B3987794A0CA7ULL, 0xD5645F2D84ABF03CULL, 0xEF77316E353ABF28ULL, 0x0B3837E777FA47BEULL, 
            0x2AFFF9C0CEDEF3F0ULL, 0x735B539A81B7B5F0ULL, 0xAF331FC5DE60AA56ULL, 0x3C344EAA6AB3DC33ULL, 
            0x15104DE1C80195C9ULL, 0x6596773D584052CDULL, 0x6CB8493B20FE35C9ULL, 0xD551302B24D1E1E0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseEConstants = {
    0x7252F58E48B627FEULL,
    0x2167BF73D09F6A8EULL,
    0xC955AF843530D4E1ULL,
    0x7252F58E48B627FEULL,
    0x2167BF73D09F6A8EULL,
    0xC955AF843530D4E1ULL,
    0x326A9BC913E52419ULL,
    0xB41FD023E235DA06ULL,
    0x46,
    0x29,
    0xFD,
    0x15,
    0x45,
    0x97,
    0xAE,
    0x10
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseFSalts = {
    {
        {
            0xEFCDEE4EFC616BD0ULL, 0xE17BDC5753D95FB0ULL, 0xAB164381E0BC0067ULL, 0x89227BC1BDC5393DULL, 
            0x8A2FEC62DB996825ULL, 0x81C6FC9A18FBABD9ULL, 0x4676B63C24646A0EULL, 0x143E3F23A38D8A5BULL, 
            0xC8FD819AFAEC0755ULL, 0x20520BFA87A62BBCULL, 0x78207B7A142643B1ULL, 0xC388A2304A81EE57ULL, 
            0x5BDC748722F88721ULL, 0x5AE8BCCF722D701CULL, 0x9600480D260DC880ULL, 0xA720D951AD046D4AULL, 
            0x753C87B5D6A61113ULL, 0x4384150881C8FA0EULL, 0x42558888FB2B2A80ULL, 0xC9F61BF9EC8B975DULL, 
            0xC06CC0755A266336ULL, 0xFD67D8361274D135ULL, 0xA04AE62B80071A4EULL, 0xFBFE9A34F41E1BB3ULL, 
            0x81F522E654AD09DFULL, 0x712B5FD0D9C3C34DULL, 0x1B24FB45A968186EULL, 0x2DBB3EE27565632CULL, 
            0xEAB72B56BB115451ULL, 0x7A44268367B59E44ULL, 0xA0A9FAF35497762FULL, 0x118142885EB59D94ULL
        },
        {
            0x415A7330568E8790ULL, 0xCE223AB1BCF51327ULL, 0x5FF1C5977E2860CAULL, 0x9CA99F69A4C636B7ULL, 
            0xC829857D16090B28ULL, 0x5D31F492DCAA0D2BULL, 0xE991D1B5B5C4CDC9ULL, 0xE176B1691B4A862BULL, 
            0xC3343FA90AF20658ULL, 0x2C52006D69C06C9EULL, 0x03E0AC7B194223B6ULL, 0xF171CFB484A6971DULL, 
            0xB7C63C01F3E34CEEULL, 0x0A71CC4348A9C8EDULL, 0xE365091C5009FACAULL, 0x1E16B0AA2A02391CULL, 
            0x9C4B3A6DCECCA4F5ULL, 0x8B1E309CB9DFA702ULL, 0x58D1BAEDBEA1C832ULL, 0xACD4A4A4911706DAULL, 
            0xC8DE875B7D72CB88ULL, 0x75025DBBC178371FULL, 0x95026ECB6C8D885FULL, 0x8BD69FAFF5785AC4ULL, 
            0xAD02660B662358AEULL, 0x80AE63F1A0575A52ULL, 0x6E6A97B3E0FC70A7ULL, 0xBABF02C5EE14C6CEULL, 
            0x058B365A87DEC247ULL, 0x2AA92A6E92BE0AA7ULL, 0x4A3F2DCE4693EC60ULL, 0x4C67E85E917E439DULL
        },
        {
            0x146DD12D37A32B08ULL, 0xAA5D7740F3F959E4ULL, 0xC3204F888190D1EDULL, 0x210E74839B0C91B1ULL, 
            0x0A2ADD018230E1BEULL, 0xF50CBD9354D012F0ULL, 0x0A3C33DB8646A149ULL, 0xED59945D890E2D12ULL, 
            0x9C618DEABD96AB8CULL, 0x88D381F501BB584EULL, 0x0C9B70680CF511CBULL, 0xBB121EAF72A9CDBCULL, 
            0x81FB98B708528E2DULL, 0xBBF18EDDED93C2A9ULL, 0x7FD2808E8E2638FDULL, 0xDCBEE64E959A76EEULL, 
            0xB8F6CE431D20FB2CULL, 0x075C70740768E715ULL, 0x20A798F0E1CAFB78ULL, 0x6DB6502B15524814ULL, 
            0x2F4C60B5C81B4DAAULL, 0xC92DDFBD6BE61800ULL, 0x9E37DA55EB8DA153ULL, 0xF6A5536FCDB6B4A8ULL, 
            0x125D80B611190B28ULL, 0x4ED28FBE7BCE795FULL, 0x1EE1B73FB44F5DD5ULL, 0xFB1D573B421CCCFDULL, 
            0xE8FFDAE1AB957971ULL, 0x007E1F2AC2DB1D72ULL, 0x9BD6DD4F56C30FC5ULL, 0x878FD87A741F8157ULL
        },
        {
            0x1842AAE179E12C2DULL, 0xD3CBEB2224AABE69ULL, 0xC0D8F2A2E43F0883ULL, 0x7A6690F82454AC54ULL, 
            0x8B3909E9002F7FC8ULL, 0xEDCF093D01D72618ULL, 0x60EF1565AA2A7836ULL, 0xD6D710C2C0A322D3ULL, 
            0xB671EA5012698962ULL, 0x504F37BF162C1D13ULL, 0x7A7979EBF0598E0EULL, 0x39EDFDF2814B6350ULL, 
            0xCA513C4F9422B59BULL, 0xB9B9E804AAF746AEULL, 0x542B1297C8A596B4ULL, 0x159FF41B1BD39852ULL, 
            0x6FDBA9C2D91C17B2ULL, 0xA69DBFA982A79C27ULL, 0x453EEA2DCB001F93ULL, 0x27ECF4FEE2D71260ULL, 
            0x26913794592196CEULL, 0x1FEF6CFA39210AB7ULL, 0x20F799C84CDDE2A2ULL, 0xBE9317A1B962DE6DULL, 
            0xE8BFB3AC86B4D281ULL, 0xF3FC6EAABD67F064ULL, 0x4B0BD6BFB2082546ULL, 0xE14C3621D86A74D6ULL, 
            0xC04B98637DA21B6BULL, 0x6DEBEB77F77EDB10ULL, 0x19E595F1E04C1A42ULL, 0x8F782106495A2C03ULL
        },
        {
            0xACD5D9A22A8E9C14ULL, 0xD7516D204D11A841ULL, 0x635262ABA63B138FULL, 0x51411E5D75F472D9ULL, 
            0x691C0582BD378A7BULL, 0x913E93E12AACAC41ULL, 0x68BAB4E170F9850AULL, 0x3F975B8135DB5CFFULL, 
            0x9B5C6E9E304AF088ULL, 0xFBBA5655CF32903AULL, 0x25B3AFF172FF6D76ULL, 0x3CEEF6A494D44E00ULL, 
            0xD41F4021EC2621C6ULL, 0x3E32B19BD650EB8AULL, 0xC4224F16DD995B42ULL, 0xA06F4A6FA226D7B1ULL, 
            0x42232B14D291E823ULL, 0x5CC2EF1F95FF9AA7ULL, 0x9232D32F0E79CA86ULL, 0xF8A688CE82E29E0EULL, 
            0x4FBB6031085D356DULL, 0x8DB5578514365ABCULL, 0xC49C49229F9E9181ULL, 0xEDF81A1FA5348A6DULL, 
            0x9BAC2A4586AB1EEFULL, 0xB872050CB240294DULL, 0x4B76FD0FA32062E1ULL, 0xB8722BFCC1357739ULL, 
            0x4969865732C99954ULL, 0x3022ED60E44B9671ULL, 0x130A92D95626B322ULL, 0xA5545C7B68AF4B20ULL
        },
        {
            0xA4C6320709050792ULL, 0x4633DF366625CAB5ULL, 0x4574D56756A21A44ULL, 0x1488C86C0C366613ULL, 
            0xCB7AEB62B8C59958ULL, 0xA8BC0456239B1695ULL, 0x15092257FA99A1E4ULL, 0x3D6F44703C1813DEULL, 
            0x45D7A6B6E394BB4AULL, 0x1E94EB423A635461ULL, 0x12CA568203DAB5A6ULL, 0x860D73C1FCAE2599ULL, 
            0x3F3B857B6F8AA91AULL, 0xCC4C4339BBC1A92EULL, 0xFB935A152FB56D20ULL, 0xF067247D89814628ULL, 
            0x52B4921EBEE82097ULL, 0xC2D9A105E65CBFF6ULL, 0x5730EF39B48AC5D5ULL, 0x44750E5079B7A821ULL, 
            0xF3882BA6F8879B84ULL, 0x31A9ACAAF57F991BULL, 0x9104B56C030F9B77ULL, 0xB6E2928B465F6E5DULL, 
            0xE8C0D8C06171E256ULL, 0x9AA14FB85F03655FULL, 0x1B4A6C3C281F8F6EULL, 0x3E8FD68C9CC2AE14ULL, 
            0x0B1ECA3F88F6FB96ULL, 0xEC160DEEB8C91AE5ULL, 0x7D19E6A6926D2448ULL, 0xA3A4713E95CFE96FULL
        }
    },
    {
        {
            0x58C58B82E76DBC33ULL, 0x8FFDFF870998F3D9ULL, 0x029E5E32B07E3D59ULL, 0xBEAB575F96ACB498ULL, 
            0x94F22B7969094289ULL, 0x8C704A9CD08CC249ULL, 0x60502FAD305CC7EDULL, 0xC0C379E9D57B2CB8ULL, 
            0x76FB260E1DFF1A29ULL, 0x0244A46D058E40DEULL, 0x0BA875219011248CULL, 0xF500F5A52ED1BA5DULL, 
            0x0F92820769BF6B11ULL, 0xD1055FCADAD44EC0ULL, 0x5367693026E50F75ULL, 0xF6A9A48D88A7A229ULL, 
            0xB7DE27AC104D7BB1ULL, 0x89439C9ED830BD01ULL, 0xFB804409565F8AECULL, 0x9096623352307725ULL, 
            0x52E95444781CED0FULL, 0xAF7C507EC9AA05EBULL, 0x7C864A7223F25684ULL, 0xD3C64FB2900AA6DCULL, 
            0x1AD516D6AC6387BCULL, 0x1E11AA6E88C9C3B9ULL, 0xA0D2BEB89F79B29BULL, 0x7671B771D1A2D593ULL, 
            0x4844461905C65540ULL, 0x119C004195E0C8CDULL, 0x4D0DE8747AF9EE02ULL, 0xF8216E7664EF9F62ULL
        },
        {
            0xA32DA223AD7DEC7CULL, 0xB2174BCDB880E6A0ULL, 0x060C3B39B8D98A6CULL, 0x845367825C2F7A4DULL, 
            0x6C2B92B4DFA5627DULL, 0x1AD977351A48B29EULL, 0x8E4A8DA953015516ULL, 0xFB2EF801EA11E188ULL, 
            0xAED63AAE8D3C6430ULL, 0x5D0550264225ADFBULL, 0xCA89E5924AB40B45ULL, 0x988F6E124E76DADAULL, 
            0x35621302CE36E56EULL, 0x6EE66C60C78D13CBULL, 0xFA3BA2A26A1B0155ULL, 0x7AE5812DED18D455ULL, 
            0x79BE7D555EE00CCAULL, 0x143A634732703753ULL, 0xD430C8F6AD51AE5EULL, 0xCA287084039B78EFULL, 
            0x11F4C39B309387D4ULL, 0x7B20036D0A2D4192ULL, 0x4E6E6E235B8FD117ULL, 0x9AF3417460BF3087ULL, 
            0x547A3DD088B63866ULL, 0xA6A2A994B3059E55ULL, 0x77ABA2D85F7EF420ULL, 0x09C03A57EA35C146ULL, 
            0xF061953DAE108577ULL, 0x387D7F14135B9ECAULL, 0xAF197032227F385FULL, 0xDFDAB31A6F387C20ULL
        },
        {
            0x147454C4454964E4ULL, 0xCBB16231D394D8B3ULL, 0x5D7090816566EF06ULL, 0x304C1605270B746CULL, 
            0x0C7268973BF50BF2ULL, 0x5F61DB5A43E2F867ULL, 0x9FB5B59425AB0D1CULL, 0xC4A28AC610B211E3ULL, 
            0x05DB8EABD1B2603EULL, 0x3D2DC08D8D4DD8F3ULL, 0x18589F09D07EF8D1ULL, 0xB5CD56AA227156E4ULL, 
            0xF295E586194DFFFAULL, 0x95FA6AA6A8747EF6ULL, 0x8A831FB155EA453AULL, 0x5DEBB00A16F45731ULL, 
            0xD7EF42F13B9C1F1CULL, 0xC0306792DF9C02AFULL, 0x24E9329D6C0DEF0BULL, 0x2674E3D49261897AULL, 
            0xE46852F9A4E9E130ULL, 0x7FE64D38578F6F83ULL, 0x1BAAB4B429D90906ULL, 0x94A8AA76D477A27EULL, 
            0x4688B43863D9C2C0ULL, 0x7BBF4DDBA02BD172ULL, 0x2F1D83D207F2D5A7ULL, 0x24C89235A11F5177ULL, 
            0x8BB981474DE035AFULL, 0xB04981A0ACA64941ULL, 0x4CD3D5C569051547ULL, 0xF9563A61547775F5ULL
        },
        {
            0xE284D989C199A86BULL, 0xDA303CDF8392E62EULL, 0x09091CE60C5181C3ULL, 0x2C8B10512410870CULL, 
            0x7D2EC20EB1493AE1ULL, 0xE7ABE3E1BA9A2B10ULL, 0x2230F378A01AFD22ULL, 0x2B4FE111755A9527ULL, 
            0x9C9C5C3682C885B8ULL, 0x3640C287E9AB27C5ULL, 0x84D657062DB57EB9ULL, 0x813A8A277EF7AE5CULL, 
            0x549BE08C1F144259ULL, 0x4A576DC887E9A2A2ULL, 0x41409902B3A41D1CULL, 0x66823EB4B31C6034ULL, 
            0x473FF23D1AE5DF8BULL, 0xCC5F595F60A5D424ULL, 0xCCC81502986CE326ULL, 0xFDD6EB5FC40A9B4AULL, 
            0x7B0468CE96635AFCULL, 0xD848766216B11FF3ULL, 0x6BF13FA0004C8452ULL, 0x4D7A881CCF95A890ULL, 
            0xDB3E9D37104BADE4ULL, 0xFB8C051DCDCF6692ULL, 0xC2D0D1A5C74BB90FULL, 0xF01A58FFFEB7A7F5ULL, 
            0xEA2873409AF12686ULL, 0x02F2FD03FF7852A6ULL, 0x7BC5C8BC1126C52AULL, 0x0E3BFE19AB3D9D9BULL
        },
        {
            0x990DAF81B9D2F10EULL, 0x75DEB9ABA6A6F4C8ULL, 0x661BAE3F151EBD19ULL, 0xD1BD7E5226EBFC67ULL, 
            0xBA5FE8445F1D8F8AULL, 0xD46C7B18B48749A5ULL, 0x6BDC9A9D9C1BB871ULL, 0xC4B71CFF838D4302ULL, 
            0x1A1A10C3B76AA445ULL, 0x95A5AF9BB7BDF11AULL, 0x12AE232CDA35FF1CULL, 0x74250FF97DB4AA95ULL, 
            0x842339400FEC18C2ULL, 0x5CC78E0307333492ULL, 0x3C3A919CFC02D77FULL, 0x8C66352980F7B4F0ULL, 
            0x8034E29FC49F80DDULL, 0x1D7142EC56CA58B3ULL, 0x3C2B59E6746117E2ULL, 0x102883F674F24A7CULL, 
            0xDDBFD326959806FCULL, 0x5B146C1DB26B595BULL, 0x303721A42CB19F23ULL, 0xA1A928A7A82773EDULL, 
            0x6BD0583DC55E68C6ULL, 0xB5CEDFCBA399A157ULL, 0xBB582AC863BB9E66ULL, 0x668E93FC6D76869CULL, 
            0x5C323CDE04F4DDF4ULL, 0x05E621F5915A6F78ULL, 0x9F01AF4F24719597ULL, 0x371397E05BE82E6EULL
        },
        {
            0xFB6E3AC4BB8D5AE5ULL, 0xBCD6A4A9942728F7ULL, 0xADFF6090369C547DULL, 0x665DCAA946A2D7B1ULL, 
            0xEF644917A13A6D5AULL, 0xCD0CFA7C43AF7C2CULL, 0xAA99541D3E95B976ULL, 0x33318C362CB6431EULL, 
            0x160925FD58CA8AD6ULL, 0xE346A5DA44BFA47CULL, 0x32D3670074609519ULL, 0x3A9AE4131DCB272FULL, 
            0x777F0A9A93193EAAULL, 0xE5FFABB6B24EA656ULL, 0x257E3B9A89E9E843ULL, 0x6669F8A3CA1F47A4ULL, 
            0x7A22C41DE557C6EFULL, 0xA0DDCDCDEE1904E9ULL, 0x3DEEBB3B464F80CEULL, 0x7A0D215F7D3FA2DFULL, 
            0xD54B983CE8153154ULL, 0xFE54CF6605724CFEULL, 0xB048D7DC525880C9ULL, 0x4ABFD4B0D77DC657ULL, 
            0xDB0230DEBF3E7DF1ULL, 0x6E47B1979CF23E18ULL, 0xF40A84090D24557DULL, 0x01BE309DE664F298ULL, 
            0xEB73B916B58EA6C0ULL, 0xA865A9C4433E519FULL, 0x87D8C6B1480C2566ULL, 0x335BF5C039549C98ULL
        }
    },
    {
        {
            0xDC5A2DE085E99107ULL, 0x7BE0F77717E6F1B3ULL, 0x90339C4547898733ULL, 0x1479573653F81C71ULL, 
            0xE2ACA698217D5BF4ULL, 0xBEFA994E7CB3C61BULL, 0xDD7974C5B184A27FULL, 0xC115B7BD769D3261ULL, 
            0x58FB88E1B7B0B876ULL, 0x4F9DE03EF5907E1FULL, 0x70F8FD1C4CF3B0C8ULL, 0xF3BE78C9A0A6F22EULL, 
            0xD9252D45B0B53D0FULL, 0x45F78C686E6BE03BULL, 0xF99361B8E31AA2DAULL, 0x6432BAD12C4FCAF7ULL, 
            0xACDFD3B96B695F4DULL, 0x69D93CF93729572CULL, 0xF42E3003A1074B10ULL, 0x8E583C0DBBAF90D9ULL, 
            0x18E48C6AB6A2516AULL, 0xF8CD942E444C7D17ULL, 0x666DAD247768B4FFULL, 0xA76810AB02298DB1ULL, 
            0x8E898463F629174CULL, 0x914BCA77618EF1EBULL, 0xC1CA48AE393BD104ULL, 0xE28C7F1D0EA58692ULL, 
            0x7E075486A0A22E73ULL, 0xCD9B506723F66505ULL, 0x923B7181017B0EEAULL, 0x0AAD55E16C2A5925ULL
        },
        {
            0x644B7449273451A6ULL, 0x7B226E0132823705ULL, 0x0D4007EAC2016389ULL, 0x74B122BAED47AE29ULL, 
            0x437D5996EBAB95DEULL, 0x8434C52151038AD8ULL, 0xF4542E147BBA23C1ULL, 0x61E2CEF6D616DF3FULL, 
            0xD60380B0CAB5D13FULL, 0xEFEC80B50D3A8D8AULL, 0x835235D1DEDF57C0ULL, 0x941FFB4360797D0AULL, 
            0x97CD15C2913DA4D8ULL, 0x01D6D47BF6748C07ULL, 0x1B515C3683CE1E22ULL, 0xBF7AEC2E5DE4B46AULL, 
            0x1B6346FBB81BACE4ULL, 0x74923746D778761DULL, 0xA300972E6D7F92A4ULL, 0xF2AC995FFA57BD96ULL, 
            0x8ABE1969944A4888ULL, 0x8A3A18AD638222EAULL, 0xB571299DCCF2620CULL, 0x95BFCAC340270351ULL, 
            0xDA24E36EDD82A020ULL, 0xE115142C95840920ULL, 0x52B7BE69B7C1162AULL, 0xF3E559A90794B127ULL, 
            0xA8CCDDFFEB66BDE3ULL, 0x43A6C5F070184DCBULL, 0xB8859012C3E74D41ULL, 0x6F91F7BCD9B7C9D1ULL
        },
        {
            0x7F8BFBEAC8886F4EULL, 0x148E2404E6672408ULL, 0xA8B8BE85AEE3AC1AULL, 0x037E7ED3779F0A80ULL, 
            0x82873C5A1DDEFC12ULL, 0xA7E8088E937E1352ULL, 0x8899D3F530F381E4ULL, 0x6807F0358AD9AB9EULL, 
            0xF5C53815383A6CE6ULL, 0xB72B25F3AAFCE867ULL, 0xBAB2F87B991F6C92ULL, 0xDB1AF6190560457CULL, 
            0x895814D067FDB4B1ULL, 0x8DCB59D0F6363E8CULL, 0x0AAB5F20356B9F87ULL, 0xDEA353EEC8D665E7ULL, 
            0x227390C94E379DB1ULL, 0x081A41F0504BE53FULL, 0x928273213781805BULL, 0x4DF3ECC26B6253E9ULL, 
            0x28F132C873C9F5AFULL, 0xCF1EEBB38321EB6DULL, 0x9A7C1950ADBE5747ULL, 0xCE095C5587F749FCULL, 
            0xC725B934826B9E79ULL, 0x399DE712486D365AULL, 0xA897385E8BE693E9ULL, 0x9EDC663A1626AA81ULL, 
            0x2410DBD02B5E4887ULL, 0xA5EEB6CA8D2CAB58ULL, 0xD8CC138A538DE30EULL, 0x0CEFC600D9EE2854ULL
        },
        {
            0x5EEB204A13D58241ULL, 0x4BD34CC06DF3E551ULL, 0x8992ED1A37DBBA3AULL, 0xC8E3CEBF359B3EFCULL, 
            0x1605DAF884C2E4F4ULL, 0xFB015E771D43F8BFULL, 0x56F946B46A89E819ULL, 0x61E39030B876D4E1ULL, 
            0xB40B724555610EC7ULL, 0xA4424BD71CF5C6B7ULL, 0x30649C11E44AEB40ULL, 0x06E031896BB56BF3ULL, 
            0xD2B9B9C5957644ADULL, 0x43AA840814DE4C58ULL, 0xA5772894756805F3ULL, 0x9145A00DCFF1516CULL, 
            0xBFC93EEB4349F0FAULL, 0xF0E992EC0BD09A3CULL, 0xE3A09B99EBABA929ULL, 0x31289B79610F416CULL, 
            0x6832307779278D11ULL, 0x527F7B8F9FCD42BEULL, 0xE7249493A5A859B9ULL, 0x52A5F1BBF5D574FDULL, 
            0xECE5FE359BCCFCBFULL, 0x718DD0EAFCE01AEAULL, 0xCA19552D3013A896ULL, 0x9DDB2D2E6C576552ULL, 
            0xC218EED4A87C47BDULL, 0x549E971DB91E98DCULL, 0xC57211ABF896C037ULL, 0x6679E02AB694AEC5ULL
        },
        {
            0x4B27987EB019E204ULL, 0x06439101ABBB4023ULL, 0x76E867A6C891C981ULL, 0xFE4A587C2BF6F619ULL, 
            0x08BAEFA956AB6D48ULL, 0x27FA9B1F6A0BD906ULL, 0x312EA498E1F7A9F9ULL, 0x4075DE1F3BA3DE59ULL, 
            0x02DABBBA87B9030DULL, 0xDA4C4D8EFE4BC7C2ULL, 0xA8ED3F70DFF89306ULL, 0xC995EDA54E18F22CULL, 
            0xB4E458BB823EAAD0ULL, 0x0C54D0E8A8C539D1ULL, 0x0F401B250FBC87A7ULL, 0x897745D5BC0BA03AULL, 
            0x62854BD13B954D5BULL, 0x0DC23694570ED213ULL, 0x0CF42D68E2EEE530ULL, 0x237CAEF194CE95C8ULL, 
            0x8B4B1A18F8AC07E4ULL, 0x11CDEC27919F02CFULL, 0xE85DAF802E9392FDULL, 0x89FB54A3475E4839ULL, 
            0xAFC7060ACB3EDE18ULL, 0x8D0A0A0C77773A48ULL, 0x9AE09F1898C7F5FAULL, 0xB553063541C30820ULL, 
            0x76385B7CF45EBB46ULL, 0x9F6BE693DE05ABF5ULL, 0x7E59C498F3FCDA19ULL, 0x9EE8DCDBDC16E840ULL
        },
        {
            0xAC6EA404A75B2858ULL, 0xE146CAFE581D63DAULL, 0xF8E2268AFF215100ULL, 0x4A22A81BAB5A50D7ULL, 
            0x0FB1DD6E18F7728DULL, 0xF0611B7A7B1CF54CULL, 0x5460E0E08066CD5DULL, 0x54F8EA7F7DD43084ULL, 
            0x73ECE4CB41D0BB22ULL, 0x9214D6058D2F1934ULL, 0xE342CE6F6EA21AA7ULL, 0xA3A1E966B65954A6ULL, 
            0x109415EB5CA97A87ULL, 0x721E6A8E132533CAULL, 0xB570A254A7516763ULL, 0xFCE9EAA1A6602B68ULL, 
            0x10A5F90D28BDC10EULL, 0x4F82ABD49A704AC8ULL, 0xF37029C2575EA1EAULL, 0x62048944AA24D8E7ULL, 
            0x2934E2131D3067A7ULL, 0x126686344004BD7DULL, 0xABEA338C9AACE4BFULL, 0x7EA33C5DA1A79A9DULL, 
            0x705ED2AA59942A7BULL, 0xE9A834DA208157EAULL, 0x19A4B82B7ACC43C3ULL, 0x1AC27B5D266196F6ULL, 
            0xFCFD4FF69DF50633ULL, 0xED2042FB5DD71604ULL, 0x408C830ECF4A20C4ULL, 0x2EE5660CBD87539FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseFConstants = {
    0x8B2200C12E327FC1ULL,
    0x4B0A567986E4BA16ULL,
    0xBE68452C54F6E6B7ULL,
    0x8B2200C12E327FC1ULL,
    0x4B0A567986E4BA16ULL,
    0xBE68452C54F6E6B7ULL,
    0x8D3A2F6BDEA61A9EULL,
    0x9D37D2EC581E1982ULL,
    0x04,
    0xF2,
    0x67,
    0x10,
    0xCA,
    0x56,
    0xAF,
    0xAF
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseGSalts = {
    {
        {
            0x24F5D0392C4C6591ULL, 0x3B2F6F057B0C9588ULL, 0x12D8C9BB5460560BULL, 0x2BAD001AD9CD40DDULL, 
            0xB7DF775B2AF13A0CULL, 0xD9C1081847386F3BULL, 0xF4898A68B4AF37C5ULL, 0xB1EC968FF75E7112ULL, 
            0x96ECF55B1118FA11ULL, 0xED7374BB281DBC0DULL, 0x78A9094C4DEBD5D3ULL, 0xD6E90E6146967B82ULL, 
            0x62145EEBD1464358ULL, 0x74A45D2EC869BA12ULL, 0xF8F6CAFC0D273095ULL, 0x3CEC48377613B7BEULL, 
            0xAC2A933F006C783CULL, 0xFC8C64E1DF3B937BULL, 0x53BCFE994286E56FULL, 0x0DF2F3E8CF2BD942ULL, 
            0xFE0283E5E68BE111ULL, 0xE93784717C14AA65ULL, 0x08F48F7DF97F5A7FULL, 0x7CE22F8376F6DC69ULL, 
            0xA422E9CDFE6208FDULL, 0xC80BCD2DAA5237D8ULL, 0xF81F85EC78A61AE5ULL, 0xA7BB5EB63456E8CFULL, 
            0xD66A84996F1D3EFDULL, 0x2622A2876A1BFDAEULL, 0xC40C7EC8733743EAULL, 0xDF6CF1878AE8112FULL
        },
        {
            0xADD075270B50D07FULL, 0x97C3FEC466D5C2C2ULL, 0x36D5106EB1087469ULL, 0xFFA834B098027EE5ULL, 
            0xDB9697F8FAAA8C37ULL, 0x10CBD9E9CA5B3427ULL, 0x42A811849D9D0A66ULL, 0x4E81B249C2A20460ULL, 
            0x58538D4A8681CF00ULL, 0x811C356F036E5DFFULL, 0x3672A74E2EB490C6ULL, 0x6F74B5626ABB46C5ULL, 
            0x539AAABB44C142F2ULL, 0x13F9D16D7A9E672AULL, 0x4CBFDE137EBBECA2ULL, 0xBE72AC7C64C43924ULL, 
            0xCE70740A34DA74E4ULL, 0xEA978CA03B549F69ULL, 0x890375571D3622EBULL, 0x736F3E7F0F0AE70AULL, 
            0x57A33E84EDDD25A3ULL, 0x9118D369C31BB165ULL, 0x327BEB219702BD49ULL, 0x899E259E5013FFF7ULL, 
            0x72FE091DB8BA7174ULL, 0x3AD479E1324DA884ULL, 0x3BCE8F895A578F03ULL, 0x8CA24486B9141064ULL, 
            0x7C0C837355CC79A8ULL, 0x1C71864569A6A28BULL, 0x08AFEA4A3E18240BULL, 0x69A16609E868E880ULL
        },
        {
            0x239C89D7E7E15316ULL, 0x44A16EFCB8C05ECEULL, 0xFF78F9FDF32237F5ULL, 0xFC7E14DB3747BDDEULL, 
            0x79C1AD14496082ACULL, 0x4EC5643D7BA217A5ULL, 0xD42C3C38A450BA1FULL, 0xA755CD43DA3D0266ULL, 
            0xB23E3A301DF101E1ULL, 0xDB9CA302F75CDC7DULL, 0x49B1463E5B8A987EULL, 0xE3B46E1A32CBF270ULL, 
            0x8785F63A8EF8AF38ULL, 0x70BE784EE5CAE1C5ULL, 0x95E0E7A8AEF9C432ULL, 0xEF9DA0B07573D9F4ULL, 
            0xB2912536B4A211E9ULL, 0xF432D3518FD1ABD8ULL, 0x8E38418D0C03BFB0ULL, 0x6928457E1D11C2AEULL, 
            0x0DF1EEE6D7F8ABCBULL, 0xD1AF8751BD772F18ULL, 0x2F5211CF04BCB445ULL, 0x641075FA53D2DD30ULL, 
            0x85946B52A6AFCB42ULL, 0x858CED49AF8D9922ULL, 0x3853006C8D58F7D2ULL, 0xA14BFDC9A8C7B494ULL, 
            0x71BECA7CE7B48847ULL, 0xBB6C86548E96DC0FULL, 0xA287F01168F4668FULL, 0x6A31CF5234FB8F82ULL
        },
        {
            0x20A43D9A33D9C6F8ULL, 0x5E54C99E3BDCEB49ULL, 0xAD5A5276CCFF2920ULL, 0xC10E904511619237ULL, 
            0x5B12A05F9187E5ECULL, 0xD4EE1F03EB7DB76CULL, 0x10FB28F3EBC9B9DCULL, 0x3E32BC2635BAF5E5ULL, 
            0x86B613B4CEDEEE1DULL, 0x653F1A1FF0F6B23BULL, 0x2F85D6539D119D33ULL, 0x54DFA199901DE794ULL, 
            0xC0C869FEA081C14FULL, 0x5AC727D6427E5AE8ULL, 0xA4AF20C2386CD77EULL, 0xAA3E38A72A754C22ULL, 
            0x35BCB825CDEBC8C5ULL, 0xFE9E01C0A9902758ULL, 0x450B8A1B11475A19ULL, 0x718B257C91BD2E3CULL, 
            0xEC2F02FF90387D6FULL, 0x5FC3222F2BAFCC1AULL, 0xF86C97F0F840B1CDULL, 0x2A26DF03FDBC8AEFULL, 
            0x0220002568F03F29ULL, 0x99DAC517C9C3037FULL, 0xFAABE51A0405662EULL, 0x801428B346BEF491ULL, 
            0x7CEACC759F9AAC55ULL, 0xA042390A93053200ULL, 0x2016C7A686755C5EULL, 0x86BFE0662DA64DBAULL
        },
        {
            0x6DE86A5F536247B4ULL, 0x76F2571DDE2CF5C5ULL, 0x7556EB92955A54F4ULL, 0xD50C54087763868BULL, 
            0xD53ED627C73E3B66ULL, 0x50B4B249F6618DD5ULL, 0x994FF44C6254EAEBULL, 0xA602A476D22EE61AULL, 
            0x6E62013A74833184ULL, 0x60A0B8464097D5A9ULL, 0xC7893353223DFB63ULL, 0xD5AEA1BA816305E5ULL, 
            0xAFDDE95DB4977FD9ULL, 0x0FAC3B8A7549C834ULL, 0x8A83C474AB3B0042ULL, 0x2684D934FC0F2381ULL, 
            0x3C694F7A11BB6704ULL, 0xDE2AFBAC241CB058ULL, 0xFF9B18577587B6F0ULL, 0x8B4C8A300E7B5E48ULL, 
            0xAC1ECEC6D147171BULL, 0xC439677A30083FDDULL, 0x43BED4EBD58640A8ULL, 0x3D61F4F3CB5F0E7AULL, 
            0x1A86E6BBDBC5788AULL, 0xA7DA4203D3B06A06ULL, 0xE0C5D4E24B62F9ADULL, 0x3119B69AB4EE8642ULL, 
            0xF404D63883649687ULL, 0x162F91EB74A137E1ULL, 0x93F2B9AF24309221ULL, 0x97318D0EC218710BULL
        },
        {
            0xE985A344D46DD653ULL, 0xA6594F4888810C4AULL, 0x160C7B966B06EC40ULL, 0xD5DF4216B0838C19ULL, 
            0x9658D8B980195C65ULL, 0xF05584B7A57535BBULL, 0xC85FA7C8747CBBEFULL, 0x3CD5C0B0ED8B23CCULL, 
            0x9ED8D5CEDDBB4955ULL, 0xACA7D40D062AA7A7ULL, 0x0245EE078EE34923ULL, 0x39ED84414B40D3CDULL, 
            0x2440CE823BE9FBB0ULL, 0xDB0B5151E211E3C3ULL, 0x6F03C7279AB67D94ULL, 0x81E2C4671A9D76B3ULL, 
            0x5FC70E960EFCBE59ULL, 0x8EEDA2347D6C42A6ULL, 0xA7ABC03A75C41FD9ULL, 0x2F7389FF955A6D63ULL, 
            0x5D5955F537EBDF1FULL, 0xCDF6017AAAC130CDULL, 0xAE3D1902889A051FULL, 0x1B2022EE305E2BCBULL, 
            0x7C2A09E80AE7B902ULL, 0x49C2E29A01D11B23ULL, 0x45B04DA1E0E4718BULL, 0xA50CF7D1CC35303BULL, 
            0xD99EA56494740854ULL, 0x8532D47175735004ULL, 0x741F59F136EE0581ULL, 0x2FBF817E6940F845ULL
        }
    },
    {
        {
            0x14CAECA39608AD76ULL, 0xEF3FCCDED97599F2ULL, 0x6F4C01B17297DF8DULL, 0xA0ABE912DC169389ULL, 
            0x6FE2F34066E01821ULL, 0x1CF1383A16FEC364ULL, 0x93E92F65523C383BULL, 0x0925EC50D1E05D8CULL, 
            0x6F9A363DEA803966ULL, 0xE06A47FBA161F574ULL, 0xE4620B85DE2A5D76ULL, 0xC0D269A28182EF21ULL, 
            0x158C7D0704D45225ULL, 0xED892A35281F8CFEULL, 0xBE831F3641F03114ULL, 0x85579E460CB63C23ULL, 
            0xD79D152A6F86AD7BULL, 0x7D844F557007C60CULL, 0x9EB7007DC1B4795BULL, 0x9AD4300AF558AD75ULL, 
            0xD7252CD602D370F2ULL, 0xC55C7DA90B6980F0ULL, 0x317759F572F68BFEULL, 0xAA909705E433C052ULL, 
            0x498D43CAA35E83AAULL, 0xAD7A0AC90258EBFCULL, 0x4CA6E5C8D63BA00FULL, 0x515AA6313DB3BB69ULL, 
            0x6D26D67D29CE82C1ULL, 0x41650D1774AD942BULL, 0xF91856F1D3A86F2EULL, 0x01E6D2A9BB190395ULL
        },
        {
            0xB1C3944C861F6868ULL, 0x023E737DDECE00E2ULL, 0x41C344ACFF76A24BULL, 0x6B69189E513F9CD7ULL, 
            0x2F35E878639F3D21ULL, 0xF06618D67188E7D3ULL, 0x9891E0656666B25DULL, 0x89DB5E60BDF67A29ULL, 
            0xE65509D3396DF68EULL, 0x967E282784500BCAULL, 0x3AEFCD63A528D20FULL, 0x245D96B9A190F30EULL, 
            0x6F80F7D3D936B5AEULL, 0x20F53FFCF15F72E1ULL, 0xE862DB25934F26CCULL, 0xEB9711D62596F4EDULL, 
            0x580FC66725F7DCF9ULL, 0xC8E00EB887B022DDULL, 0xF2D533AFD9BB1327ULL, 0xCDB5CD87FEAE337BULL, 
            0xF68FF3CDC6832D7CULL, 0x9DD4D6BA987AD454ULL, 0xB7A7243351BAD229ULL, 0xC96549331112DAD4ULL, 
            0xEBA4E4EDFAE2C25BULL, 0x7D272A0E929F9492ULL, 0x17AD91FFC29D5202ULL, 0x9E99570C100EB9AAULL, 
            0x2A9B3E2837CA8C57ULL, 0x597E49A18A6845F0ULL, 0x7BF2CB0E11586235ULL, 0xAF0D077E85FBB1E7ULL
        },
        {
            0xA34AC9608592D580ULL, 0xCD0B29878292732FULL, 0x52DD2266883FC9A5ULL, 0x9517A4D4EC8D3856ULL, 
            0x32D0938C6B3E3140ULL, 0xA82E9CA953A64FEBULL, 0xF86F705655BDC2A3ULL, 0x25AB48A88481CD1CULL, 
            0x602804EE4CC73AAFULL, 0x239F44E37D291AEBULL, 0xBA07F48A52A3D539ULL, 0x952FAB43C7EBE9C9ULL, 
            0x1049C525E712ADAAULL, 0xB0C9246E5AC3571BULL, 0x0F636F86BC5880CAULL, 0xAA43D275B6BA600EULL, 
            0x4CA98AD15C033BE7ULL, 0xE3D7CF3E8F623331ULL, 0x4B9121C4621F34BDULL, 0xEE43B130BB187149ULL, 
            0xF1905DD30739DEFAULL, 0xC12497144C2EB4B6ULL, 0xC4B10801AD5C70CAULL, 0x9371E80BFAC450B1ULL, 
            0x0B2051E654B0D887ULL, 0x7679FFCCFDC098A1ULL, 0x42BD21065BE6371EULL, 0xDCF683F7CB78CFF5ULL, 
            0xC14B020A21F6A013ULL, 0x130B338942358FC0ULL, 0x1104CEE87353A8DAULL, 0xD85C9A12D4C368B2ULL
        },
        {
            0x268E79439A89F668ULL, 0x92DE7727ADBFDEB3ULL, 0xB7F1B4BDED16845AULL, 0x296D97F9036DA3E9ULL, 
            0x2728B061EAA499BBULL, 0xCE97B5EAE0AA87DCULL, 0x0543A0CA5DFEDE61ULL, 0x158557837F709D05ULL, 
            0x420405214B95A205ULL, 0x2EC0C822D2B3AFF6ULL, 0xE7EBBD92AF196BDAULL, 0xBA44DB131558FD75ULL, 
            0xCC2D0F6334E845A3ULL, 0x875C1A01079D4841ULL, 0x44C248618852F1E8ULL, 0x49634575C700290AULL, 
            0xE5C6CAE066772A18ULL, 0xFC0D099E75FCBCA5ULL, 0x8FD643BB7A7F5B17ULL, 0x63AE9DC33AAC3350ULL, 
            0x482EEC343FF0830EULL, 0x60CC326EBB46BF78ULL, 0x5EF83355CAE399A2ULL, 0x7DFB7DE7A1F40CF7ULL, 
            0x3F81C3DA6517D212ULL, 0x9826DA4489C46F94ULL, 0xC0252D81B6903510ULL, 0x032D8A0A5882FE82ULL, 
            0xCE55E19778FF26E3ULL, 0x2291012722D4707DULL, 0xCAD051E5DEEC8B3DULL, 0xAAA3AB9D55380641ULL
        },
        {
            0xC14777B55EA74699ULL, 0x2574BCDD526C0256ULL, 0xFFF6F0889781815EULL, 0x7640ECCFAE86477CULL, 
            0x3E22D441AE3666E3ULL, 0x3D5CBEED4102F4C4ULL, 0xAB47007E6683EC6FULL, 0x96AA537CDCD48722ULL, 
            0x6C07CCEA31D0323BULL, 0x92DA55B6A63EB2C9ULL, 0x62F87F2E67D3DA97ULL, 0xF52FE11E2C418EEDULL, 
            0xDF77E4FB9DE687C5ULL, 0x67CC2FEC0176274FULL, 0xAA67A4110258439CULL, 0x5F9971DE2ACC6547ULL, 
            0x6A5AD60A3552F37BULL, 0x908B548B36CEDDB9ULL, 0xB5B7618C96399B5DULL, 0xC0CC5015034F13E4ULL, 
            0xD56C7160300161EFULL, 0x44492DECBAEC81DBULL, 0xA071375133E63F0EULL, 0x220154D173E6D74EULL, 
            0x4A377DBF22B03A2DULL, 0x65148660060959E7ULL, 0x1C099482D34B3A4AULL, 0xC22A3938DB751BC0ULL, 
            0x9A70A27590A29210ULL, 0x83F72582F91274AAULL, 0xA47AC1777126AE1BULL, 0xCC858A5D7872FC2DULL
        },
        {
            0x483EBC2905A6338AULL, 0xC26D2FFAAF61BF63ULL, 0x692DB54242392BF8ULL, 0xEBC183D4054A763AULL, 
            0x5C8CD70FA0681B68ULL, 0xAE485184D268DA6DULL, 0x316B2A8168E48751ULL, 0x5CA798BE9DEE4CE3ULL, 
            0x4F5E88FE7B34B9C3ULL, 0x0310792F0E876C17ULL, 0x83FB2387E4F44EA7ULL, 0xC08BAD9792DB8A53ULL, 
            0x7BA3093404C742C2ULL, 0x0675FB52FA1BF7B2ULL, 0xA043DF5C366859E5ULL, 0x1C98AEA3D5D6DA46ULL, 
            0xE0FC75A9B1DA6FF1ULL, 0x07C87FEBC8314D19ULL, 0xE2FAB711B7DA18CAULL, 0x32E0850B97CC825AULL, 
            0x5CB73BAD2F98FAEFULL, 0xD24636AAD7DBDD6BULL, 0xA5CE9807B7817C6EULL, 0x80D22F623E019574ULL, 
            0x92A6111EDCD159B8ULL, 0xD321F21A275FCCFCULL, 0xB2824B5DE78D3779ULL, 0xBE35884BED7FEFE0ULL, 
            0xC0354019161808F4ULL, 0xBAC7766792714B50ULL, 0x6A299E64E18AA478ULL, 0x6056F18753AF1860ULL
        }
    },
    {
        {
            0x31A45ECE46C01A32ULL, 0x098ABD49EF8FA697ULL, 0x3EEA6B4953A39E33ULL, 0xFAC82D2CBAA45045ULL, 
            0x508022AAE3A6DB95ULL, 0x16010FA34F5C45A8ULL, 0x478196E2C8A02C44ULL, 0xAF7A2E44A32F6D29ULL, 
            0xEA9AC60743DBF091ULL, 0xD1A80D8CD0B28458ULL, 0x8B9AF0D695BAD1E7ULL, 0x6431069F4AF2C5E3ULL, 
            0xF94A824974D3C57EULL, 0xEB42D208F01B5C44ULL, 0x0E3ABC96649EDD62ULL, 0x5E6EF8149EBF3A15ULL, 
            0x0B18C324B890F6F4ULL, 0xF1F2DC3FB0BEA3D3ULL, 0x101CB2D1E87235FBULL, 0x26DECF423313C8B3ULL, 
            0x0B078A5D267BD9A4ULL, 0x107F367D29E60310ULL, 0x29A3087AFC3338ACULL, 0xF5433860DF78A9DBULL, 
            0x53C69AA91D805950ULL, 0x313EE38178F013E7ULL, 0x7B6EB169D614CEE2ULL, 0x72EB0A046202B480ULL, 
            0x33DF65D6ED775C8EULL, 0x157B9F3BB1FFA23DULL, 0x32FFB2640AF70BFFULL, 0x3F0584A504D91A96ULL
        },
        {
            0x0D571E3C632C18BDULL, 0xF24507EA2307F70EULL, 0x7F7700ADEBFF6FF5ULL, 0xE0889CBF7B1B4BFCULL, 
            0x95A252F64A63D0B6ULL, 0xC6733EAC37C873DAULL, 0xB770F6ADD1F84AD8ULL, 0xF83B820E01585E0CULL, 
            0xB0BC6CD2CF55D34EULL, 0x1A4ABE9AB1A01BCDULL, 0x790D188D42CFC25CULL, 0xC469C90097EEAAF6ULL, 
            0x65EB90D98B96A2C7ULL, 0xDC702EDBF0C5F443ULL, 0x750066B491EF50A6ULL, 0xBA47E7C4EAF4BCA5ULL, 
            0x072E7854BD3135F7ULL, 0xE375D9968A418424ULL, 0xCDAB49EE68A55028ULL, 0x87DBC16A4A0917ECULL, 
            0xD93DD546583EE3E5ULL, 0x021800B7DD92FDF2ULL, 0xDC39AEF4EB7F6B9AULL, 0xAEEA928503F18F2BULL, 
            0xB49BA9CCD893B880ULL, 0x7C40026F008C4B3FULL, 0xF7276C9D043CE50BULL, 0xD299B4275C88F938ULL, 
            0xE2A3199D48D32436ULL, 0xC432FEA2F7289B37ULL, 0x84F90FA6A0AC3A17ULL, 0x4DDD321D6ACACB08ULL
        },
        {
            0x30EC81DC6F8710A7ULL, 0x3D9B46917C10C5D5ULL, 0x44A695467D780B2FULL, 0x28825E0352F9D4B1ULL, 
            0xA41BB679167FBFF1ULL, 0x63C0FB4A266218FAULL, 0x955AC283A41BDF32ULL, 0xE89801279DBF5486ULL, 
            0x2B175C0BBE3D1659ULL, 0xD980D15FB6CF63D8ULL, 0x0351F831C76041E6ULL, 0xB48C6F1849748DADULL, 
            0x5B08C1DFF3C76F77ULL, 0xC4207A5FBDD9C471ULL, 0x9E86CA54B31C219CULL, 0x63BFF8A334087FFDULL, 
            0xB474D25DC778CDB9ULL, 0x172E38D48DE9065EULL, 0x9BA4C47296773BE8ULL, 0x7C255F889AF265FAULL, 
            0xA0CEE150122165F2ULL, 0xA1A1D2C2366CDB65ULL, 0x3273E1C69502E391ULL, 0xCF61CCBA46204B30ULL, 
            0xE7317B27E5F41A3DULL, 0x2AAE0593BEBC4048ULL, 0xFCDC54B032805CF0ULL, 0x6E163ACE5B455E60ULL, 
            0x2D4F1FC4FD851892ULL, 0xC89DE112F1BF66DFULL, 0x4CFC4A7B1EBCA827ULL, 0x7BF779777D8589E9ULL
        },
        {
            0x050AEEE8E2E1EDF4ULL, 0x583B4EB2B3598939ULL, 0x7BF19B6519586B93ULL, 0x78F40C14419B6B78ULL, 
            0xF9015809E91CF383ULL, 0xFEF95B6198C8C31AULL, 0x8D68753991796081ULL, 0x71460F23D62A6399ULL, 
            0x4B289E5B52A8C5CAULL, 0x26F2C661A3E3B872ULL, 0x6BD7C521E9A6E172ULL, 0x552DAD1E9F9E81A2ULL, 
            0x68373DA1375F808CULL, 0x400B6F93D2FEC625ULL, 0x6BD4425C7D971B85ULL, 0x43641EEA06F2D8EBULL, 
            0x31D95A9AD1754879ULL, 0x0362DD5BA01B19E6ULL, 0x8A76DF39F18B89C2ULL, 0x13523F392227CED3ULL, 
            0x7CF26AB1A3806981ULL, 0x581C40C8CA19F996ULL, 0xD0A837D4A7F58461ULL, 0x2BEDAA5E4888CECDULL, 
            0xDCC460B72ADAEE4EULL, 0xA5F5444E4B1F7CDAULL, 0xD3176C52620047A2ULL, 0xA1A453E9B341977CULL, 
            0xFC7412C86DD9DA60ULL, 0x09B7561B26C78AA0ULL, 0xD8999EBCE281521EULL, 0x823F468DD3C2CFBBULL
        },
        {
            0x78634223238F83D6ULL, 0xFBC0E51E0FC48C48ULL, 0x0C9E57FAD58D47B2ULL, 0x5BA55A05119ADE6DULL, 
            0x6004F7EA7FCFF40CULL, 0x23C410C017CF60DAULL, 0xB61C0C3DBD004AF1ULL, 0x5AEEB03A74354024ULL, 
            0x69FA18C72DE39487ULL, 0xEA5250676DCD197CULL, 0x648ABA929B73ADC5ULL, 0x3E72972D216281D1ULL, 
            0xDC26675D89310740ULL, 0x2819AC2EEFBFFD8CULL, 0xB72FC33630532E88ULL, 0x6909C9782F11CAE6ULL, 
            0xF2134F4088750C86ULL, 0x6758EC760BF95FCAULL, 0x328B9A7DF235E708ULL, 0x5F31133A6990CA3CULL, 
            0x52AFD8FB4B02B20BULL, 0x70C7B9BA000002FAULL, 0x613AB439414537C3ULL, 0x25227A423435C19EULL, 
            0x65388919EE6B680BULL, 0x82951570EC487879ULL, 0xA8CC5574FF16EB4FULL, 0xBB82E7AEB6CA2B87ULL, 
            0xC628324CF4A7B1EEULL, 0x0EBEF8A540DF8606ULL, 0x4DAFF9D73A212256ULL, 0x1D58337EDDD8DFA1ULL
        },
        {
            0xF20C245F4BDB1BD0ULL, 0xF887B74D0DE10B9AULL, 0x50FB45C3BE2A04CEULL, 0xA68A63E87A80643AULL, 
            0xD8CB5B119C2FD731ULL, 0x464FEF982E416ECFULL, 0xCA459C90AF698727ULL, 0x8579D02ADE6292CFULL, 
            0x8D0C30545A64E4EDULL, 0xC69BF62D8CF2C40CULL, 0xF1B20E62998091B7ULL, 0x53F2D02DDCDBD2F6ULL, 
            0xBB7CD4945740280FULL, 0xA64AE714BAEAEDCFULL, 0xDD61C0E3C5673ED6ULL, 0x38EDA138186246A4ULL, 
            0x31AC365D2F176AEDULL, 0x620559915C53E83AULL, 0x696A369919339248ULL, 0x7B3F2EC0A8090257ULL, 
            0xCB0657E8BCDEAE8AULL, 0x8C6B8D54C6AE1708ULL, 0x12EF1B03FA0F2F6EULL, 0x7BC891532BEE0446ULL, 
            0x82B60DB8244EC399ULL, 0x01EC6BA9710BAE74ULL, 0x735F8B58F5039F78ULL, 0x5A5C32A7C836CF3BULL, 
            0x97CF185ABE3716EEULL, 0xE67AF7C4FC4A65BCULL, 0xCDE3ECFCA078F989ULL, 0x403E4ADB53499450ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseGConstants = {
    0x4F09BE1D5B23AF2AULL,
    0x1E1793CC43F94266ULL,
    0x2E30A2A1045C3725ULL,
    0x4F09BE1D5B23AF2AULL,
    0x1E1793CC43F94266ULL,
    0x2E30A2A1045C3725ULL,
    0x20E903ACE976AAF7ULL,
    0xE09232DD044B42A6ULL,
    0x26,
    0x7E,
    0xE6,
    0x13,
    0xBB,
    0x3F,
    0x56,
    0x51
};

const TwistDomainSaltSet TwistExpander_Rugby::kPhaseHSalts = {
    {
        {
            0xD5531F1FEF3028C4ULL, 0x2C6E756797AA2DD2ULL, 0xE05D7B25AA1D4E75ULL, 0x1336152F3B75E93CULL, 
            0x24DA1E85E3734627ULL, 0xB59E1B26B4F6F54EULL, 0x756A30350730100FULL, 0x381517281C307992ULL, 
            0x4E0075D9A210BF80ULL, 0x7FBE9E18510EA94BULL, 0xC6A5654F26A84883ULL, 0xBA7C3DB590CECDA7ULL, 
            0x0AC990C8EC6E5937ULL, 0x768571D579393EC0ULL, 0x269DB18E9115B1F1ULL, 0x590E68E24A956FCDULL, 
            0xDC40E5ED9DC3197FULL, 0x0FC4F5C63C6F3CDBULL, 0x002818697DF722E1ULL, 0xD4D9B6EA593659F3ULL, 
            0x61448D023D037F43ULL, 0xA133AC1BB09C5029ULL, 0x0876051F8F4F6F7DULL, 0x8A2158C120F78A3DULL, 
            0x3F5691B7784F102BULL, 0x512752245B88138AULL, 0x129C244891597F2CULL, 0xEB14DE53211F15A8ULL, 
            0x7397081E12DCFEA4ULL, 0xF6DD82B1B7D5986AULL, 0xC66E061C6A5B643FULL, 0x9BC060FEA725B385ULL
        },
        {
            0x88BDBA08C881C060ULL, 0xF93CAC5F254A93E0ULL, 0xBC3C7A07B12F1FDBULL, 0x0715A6C6E78C5DCAULL, 
            0xD93648A084E7E21EULL, 0xC8D93F565EBC5F6CULL, 0x6432F3B4C526B843ULL, 0x93D1B57EF4A6A649ULL, 
            0xCBC23E89F8A9A1C1ULL, 0xFFF482B0F1A146FDULL, 0xAB46A18793E4DD10ULL, 0x8B44AFD6E91DE834ULL, 
            0x81BE12D76E1E5234ULL, 0xA3D6CD28C08D4C44ULL, 0x51781D23BE2FA60EULL, 0x0225EA4EFC5A438FULL, 
            0xFFCA5C100585BDA0ULL, 0xE11B1A3B4580CB53ULL, 0xDE6D3DD28131607DULL, 0xB7343280C0AC7CE3ULL, 
            0x89FF418D352DE200ULL, 0x61059006BAB59C55ULL, 0x324D394489171575ULL, 0x3CC5EFE71417370DULL, 
            0xE13D209C6BD0F12FULL, 0x71597557BA3860F7ULL, 0x2267B58D00BA9B03ULL, 0x07198BBE8BD03764ULL, 
            0xA83226BD9536E5D3ULL, 0x711AABC8C4B9EE4AULL, 0x94A69CA6BCA4394FULL, 0xAAB74E26D3F39BF1ULL
        },
        {
            0x50C8FF7266CF26B4ULL, 0xF86E1D9E7C6DCADCULL, 0x4F7A11B59F48E515ULL, 0x24942728FD3BA20DULL, 
            0x7E3CAE28667C72E8ULL, 0x3D00E6D871BFCB5FULL, 0x7EE79CD52236E653ULL, 0x23EF73A474F977D4ULL, 
            0x71A6314B94F11E1CULL, 0x8578981418C3CE48ULL, 0x1BEB543D62852191ULL, 0xAB6A18B42DED01F6ULL, 
            0xF6346ADC92177961ULL, 0xF7774BC3BD58F21CULL, 0x2E7579033B9F3695ULL, 0x77646FAFFC15B2BAULL, 
            0x5DE25F839B24427EULL, 0x75D85A71E8E87DBFULL, 0xA248F4AAED20E82BULL, 0x2FEC30D7C2438D0EULL, 
            0x8ABD697F1102C97FULL, 0x32CBF38FC00657E0ULL, 0x2A8758976CC8DA03ULL, 0x5172B176EB0C1005ULL, 
            0x668F151ED935AA56ULL, 0x5B662D3F4049D038ULL, 0xB4C35C0168DC0F5EULL, 0x772F8DB2037BF817ULL, 
            0x19276A4CDB984332ULL, 0xC4DE4F81AF361564ULL, 0x939F1E9CE41DFB2FULL, 0x7803458F207284C6ULL
        },
        {
            0x705EA2BE71B43DA8ULL, 0x6071242907B4F891ULL, 0x03DAE1FB920DD836ULL, 0x0C2F8D0B5F0C5039ULL, 
            0xEB74BC388A498735ULL, 0x9357A65C67A3369DULL, 0xAAC23ABC3078FDA0ULL, 0x820168F800061D2AULL, 
            0x279560A08F60C226ULL, 0x2B0AF357BE903841ULL, 0xEB0A0A7187140D5DULL, 0x3F82BBDF58A92823ULL, 
            0x88A06DB4CD6B29F7ULL, 0x59B91588AAE3303BULL, 0x4F93886F921E81B8ULL, 0x918BCE9C2F81378AULL, 
            0x44DBF9245EB2014EULL, 0x13DB58968A727592ULL, 0x528E28465967B54EULL, 0x535B5D3429E1D2D0ULL, 
            0x191A0973AFEE12E5ULL, 0xD3F8DDE2085F51B3ULL, 0xA4E0941E03B4D3E1ULL, 0x27FAA082A496BDC9ULL, 
            0xD35501CCB6474A49ULL, 0x36702A70A4AA13FBULL, 0xCCD48A26FB686BB2ULL, 0xD061DA85DD0790A2ULL, 
            0x8ABB1D7B39E63AF7ULL, 0xFC6BDF842487BE3DULL, 0xEC01CE171D55860CULL, 0x2DE26ECE50002908ULL
        },
        {
            0xD443CBBC72EABDA2ULL, 0x7BBD7AE4D2C44165ULL, 0x8E31E20E40897CAAULL, 0x21A6B8744C68FC3CULL, 
            0xEF4AE2E21F1E9417ULL, 0x6B3712A21E0E2A26ULL, 0x7DC4EA061A361FADULL, 0x851500349EFCAFF7ULL, 
            0xC24F5FA6FDDAE9EFULL, 0xC56B97CF53D44740ULL, 0xFBFC95C9C12B895BULL, 0x366D425B1255A32DULL, 
            0x95BF122B74FA53CDULL, 0x12689445A2B7DBB6ULL, 0xA3118BC19EB9C190ULL, 0x7EF892CDF84758B0ULL, 
            0xBE9B8882946B1A3FULL, 0x1C9B1B8D4F276C24ULL, 0xE0F5A3226E1302B2ULL, 0xCF08C333381964D3ULL, 
            0x2850F3090DE4622FULL, 0x72AE72E1EBABEC5AULL, 0xD7BE0FCA20C9C6A0ULL, 0x5D90E41BFC67422EULL, 
            0x738938FCBBEEC6A7ULL, 0xA3B413D76E0E946BULL, 0xCAAAF5EE3DCA5B6DULL, 0x283955DC00AE6627ULL, 
            0x87342D835D997FECULL, 0xF719AC9A51DEDB82ULL, 0xF385AA83F2BC7308ULL, 0x01AF95CEAC595A32ULL
        },
        {
            0x42C5DE1937E43227ULL, 0x9BE9C946F4907143ULL, 0x9BFED637E9595F6BULL, 0x127DBAF8A805B07BULL, 
            0x83AECC3627725D7EULL, 0x2D32378715AF4747ULL, 0xDF9E6632F3C116FBULL, 0x748E3262708AE55DULL, 
            0x813655B769314C89ULL, 0xEA99F72B00B25496ULL, 0xD8017695775426D6ULL, 0x31ECB7E6A0561030ULL, 
            0xF32E368AB2F1A526ULL, 0xD3A9DD249C7C7716ULL, 0x482592A21233CC25ULL, 0x49A2BB35B0EE98C9ULL, 
            0x0BAA69E108694BCAULL, 0x0367294BE22BA1A0ULL, 0x4123C7ADA09AFC36ULL, 0xD5515E3FF43ECBF1ULL, 
            0x0F43376275602DF5ULL, 0x2147FFF4F902F941ULL, 0xA1370A1CEACEB5C2ULL, 0xBF1A1958E8B6E46DULL, 
            0x81035EF404CDFF1AULL, 0xF277860B855019E1ULL, 0xEB4715F64D5BA2DEULL, 0x09075E25C70A7D5FULL, 
            0x585E0F74B63A063FULL, 0x603E6FD8F3E0A7DAULL, 0x33294C6C016BB694ULL, 0x3702F135F2D5B5C6ULL
        }
    },
    {
        {
            0xA30A36726FF96980ULL, 0x8C130AE60239A192ULL, 0xD9AFC76E33E5E654ULL, 0x0CBDAB3F6F10C1B4ULL, 
            0x6383FFB33AB1CFAAULL, 0xA8030DB90621A860ULL, 0x0B89EC638EE93195ULL, 0x4576792F496FC2A0ULL, 
            0xE16511B37FF7B5ABULL, 0x54336E694673F9F3ULL, 0xE90F1769C99E7630ULL, 0x43725980B4F72769ULL, 
            0xF39FE886BAD65314ULL, 0x72481A5135ADAF41ULL, 0x071FF7E20CC20EDAULL, 0xD92B594CAF61C552ULL, 
            0xAAD80936CB7BA398ULL, 0x2E9A01D251D25F45ULL, 0x2B2BE23D978BB9F7ULL, 0x5AAEC06385764B95ULL, 
            0x2B05973793FF7F81ULL, 0x301AE9AD531CC69BULL, 0xB2C06193DF210B7CULL, 0xC57E3A57EC80028CULL, 
            0xC1E5A017BDA55332ULL, 0xE1476D6D81B71304ULL, 0x8CF03A4EC9BEC488ULL, 0x8CA31426775CB187ULL, 
            0x3A6B683914390290ULL, 0xFCDE2B3C249E84D8ULL, 0x23FC25C232C3BCE7ULL, 0x7507C92858386BD0ULL
        },
        {
            0x22780080B9CDC63CULL, 0x6BCF6C4D0E74E91DULL, 0xEEC4166856903C89ULL, 0x3A82CFFE1BC5DD7DULL, 
            0x0B924F1A28120372ULL, 0xB7FCF3735A62CB05ULL, 0xDC9D5B66DEECB475ULL, 0x25B90A79B42E3264ULL, 
            0xE78E0236112AE226ULL, 0x2088FCB9251B5075ULL, 0x357D4A09B451A683ULL, 0xB20D9D43F0E02DE0ULL, 
            0xC060A1FF5FE65D40ULL, 0x32BF0B68CE3F05A3ULL, 0x2A649677EF1909FAULL, 0xD5BFC060EFF23C38ULL, 
            0xF95A3FC6CC4F4517ULL, 0x5C4B580541B4BF90ULL, 0x3F679C395DD66B9EULL, 0xD6565F0D56488E71ULL, 
            0xC17DCE8C02CF8315ULL, 0x8ECD5EEB80A3ED63ULL, 0x0E00DAD7BB8291B3ULL, 0x42B4EE932528F85BULL, 
            0xC5FA18E88C6801C4ULL, 0x900A740EFBE7DE4DULL, 0x15C7520EA100A0BCULL, 0xBE9CCDB8600BC2B0ULL, 
            0x37BA098EF162608EULL, 0x73D0082FDF40F6C8ULL, 0x97B76ECF780DDE40ULL, 0x360804AE90BEAC0CULL
        },
        {
            0x2499E1529C57B663ULL, 0x2CBD19941C548BC7ULL, 0x7D3AE82D95995ACFULL, 0xA825C95C3A96D73AULL, 
            0x8F33509A9BF30709ULL, 0xADCF402DEF3E60F0ULL, 0x106A1FE49E5CC713ULL, 0x80DD9BC4F454ADAEULL, 
            0x677B3A5D272369AEULL, 0xF84F42FDC89F36EEULL, 0x876C4BFEBCD0C2D0ULL, 0x3F6C3CA732841A8AULL, 
            0xE8802C16A747F469ULL, 0x9AF7E4FD3364B474ULL, 0xC42A5F718EBACB64ULL, 0x7FA42FE2F1C5C539ULL, 
            0x856D5E87F27C014EULL, 0x63FC28C8DEC783C0ULL, 0xBF71C1CCEE767087ULL, 0xF7AE0862081BDD0CULL, 
            0xC3B74B4E86C45E67ULL, 0xCF078079185D81BBULL, 0x55185A81DEA5EB14ULL, 0x2966A7A70AA7BC66ULL, 
            0xC4C2404285C918E9ULL, 0x7653C8EB34AABDF3ULL, 0x668A82C308448D5BULL, 0xD6499A8BD634E769ULL, 
            0xA50371530A09A727ULL, 0x6D9A39CFE68C53DCULL, 0xFA8EC51E67A7B575ULL, 0x4340454874A2B0E7ULL
        },
        {
            0x79E1437A707B0E7AULL, 0x29A298E2147AF076ULL, 0xD21520D9095150E2ULL, 0xE015B51BEA82F3C6ULL, 
            0xA72BD5AE18038CB7ULL, 0xBFB5CF9042D0A41CULL, 0x95A8F2A0C195902EULL, 0x6C3D639FF1135B64ULL, 
            0x425E452DAC3A1902ULL, 0xACE47E2DCF42072DULL, 0x6FE7F6A45B287BF7ULL, 0x7CF32C13F6BD0E84ULL, 
            0x71C5386C08926AF3ULL, 0x95FCE6DC4AB750C3ULL, 0xAB81A51A275B1669ULL, 0x2B76762D400B4334ULL, 
            0x8717AA796B71C47FULL, 0xAEB141DBA8A18E8BULL, 0xCB382B1970704A54ULL, 0xA9FE17A2065DAC13ULL, 
            0x377ADBBAFE7FB76EULL, 0x2CD15646A76E57ACULL, 0xB5C8706F3D612D5EULL, 0x8E0B081298F25731ULL, 
            0x3F4E3C581E3D9D65ULL, 0x4E12B7B80B78C803ULL, 0xFAC6807A1860B20AULL, 0xD94F9DE7F6DF0E99ULL, 
            0xD7E8BF5665317D53ULL, 0xC8EC5822BB15B321ULL, 0xCD2BC7215DEE2293ULL, 0x9F9B12D8CD949874ULL
        },
        {
            0xE451C8A20EAB4C82ULL, 0xFC9C671DBB3784F6ULL, 0x34E5CE0468629661ULL, 0x0035E897F54364C9ULL, 
            0x23D2017BDAEE435CULL, 0x97FBCF2E84CBAF06ULL, 0x16389FF4DC1F5222ULL, 0xCD59C97F82FEA38BULL, 
            0xFDAFB7339BCC1B23ULL, 0x0D498D33689F5191ULL, 0x69E675F995E3A7F8ULL, 0x46A2DB9EF8514EB0ULL, 
            0x28F97530DB6D17FCULL, 0x0FAF382679E65822ULL, 0x140AA7AF4A8C775BULL, 0x989B8FE2E52F5336ULL, 
            0x4B71A7303FDC0406ULL, 0x4658277BF05B6B9EULL, 0x2C327B45DAEF751CULL, 0x3D22463C0ADFA360ULL, 
            0xEDC649B05D0CE154ULL, 0x2C8B9D9EA3208FD3ULL, 0x297359AD97FF0E60ULL, 0xD26F88AA3EE35236ULL, 
            0x007734A159550669ULL, 0x837F7B996F6D64F8ULL, 0xE55D840AB92A7F06ULL, 0x03D97E87A019C471ULL, 
            0x7C8EA24E55475F98ULL, 0x2F368AA03351C925ULL, 0x3BB546E88BFD3490ULL, 0x84D36975214C6F09ULL
        },
        {
            0x2204BC236A0214D1ULL, 0x63A24221E800F308ULL, 0x83000EAEC1065163ULL, 0xBB1093C4CF9ADF94ULL, 
            0x94CFE032E26775A9ULL, 0xE6BC339F834D2A1EULL, 0x887ABBF861C1A9DCULL, 0xF6EB6D5C27B28D5CULL, 
            0xDFB29430BC47DBEBULL, 0x6052577324DF8AF1ULL, 0x5509D49A7D4B30CFULL, 0xA369EA87FC71CCF6ULL, 
            0x02549EA0C4C4D852ULL, 0x6B66933C9FF2E877ULL, 0xF96F1FC19FA37621ULL, 0x2D4AE94E2CDC7FC8ULL, 
            0x17F6AD427305F7BEULL, 0xA66C4421A86FEBDEULL, 0x94A9F77C81172F95ULL, 0x6DF9E40FBF5FE734ULL, 
            0x939B1CE2CF76A450ULL, 0x15353BAFD8A89F0CULL, 0xA41D69F040FBC0E3ULL, 0xDD4D8358CB731A55ULL, 
            0xE8B531E5AC94FF19ULL, 0x47FBCB8B3089ADE8ULL, 0x8B2E515406C18092ULL, 0x06823CB9000B2DB1ULL, 
            0xCF2EA61472EFEF9FULL, 0xE6A3AB4AAD11A380ULL, 0xEB53BD09170A9B79ULL, 0x239AAE740B1AE9B9ULL
        }
    },
    {
        {
            0x4405B4A833877EAAULL, 0x92382C54EF8C242DULL, 0x06B83E17805FB1D1ULL, 0x075B0723AD195B7FULL, 
            0x8AE594506631CE55ULL, 0x465D77D0EB1E37CEULL, 0x35B0F4EA8160A02DULL, 0x1F838ED2D1F0BC71ULL, 
            0xF9E365BAFD0E5929ULL, 0xDF21AB9433291A6CULL, 0xF0F6A982DF7F03E1ULL, 0x236C0083F7223465ULL, 
            0xCD484F152535BCF4ULL, 0xE3F8936EDE6C0201ULL, 0x52AE7A3C4AE8AD91ULL, 0x8429E15B9CF5B969ULL, 
            0xA4B888EA13FBF8B8ULL, 0x20439EF5F15BC6E3ULL, 0x9B0F369C26F49569ULL, 0xEC28DC9AC36034F0ULL, 
            0x92ABC924DC213FE2ULL, 0x6EDD2D8D4284F49CULL, 0x06BFA1557C03DE13ULL, 0x183695222EB5E27EULL, 
            0x82581E17D1304390ULL, 0x4D4FB0C7D6F774ECULL, 0x377CA9EB2B33EE26ULL, 0x6FF6A6345B9A54C0ULL, 
            0xB0BB094B8A8ACF49ULL, 0xD74BFB6E420EB11AULL, 0x9C7463DA31300079ULL, 0x6A49753B00A05795ULL
        },
        {
            0x40CA82E3222A5CC4ULL, 0x25DC4BC89154F164ULL, 0xE4DE940519A03F59ULL, 0x253CC75097B362A6ULL, 
            0x6C6E69B0638B9CBBULL, 0x01A70FBEF376E4B6ULL, 0x851DD68CF628843BULL, 0xE71D97A70AEA5B27ULL, 
            0xA32F52DA5821106CULL, 0x75D473A75B40450EULL, 0xE608AB91ECC80A65ULL, 0x19E9FD03A91D31DBULL, 
            0x5A6D191B28EEFB57ULL, 0xA9D7706E7C565E5FULL, 0x017A47718A4FE12BULL, 0x0838D0134A83454DULL, 
            0xD7A196B1C86526CFULL, 0x6572DC2BB1E7D1FAULL, 0xDE3BE130DB9D0EB0ULL, 0x90477143674A542EULL, 
            0xCE303258244B40B2ULL, 0x286D25903824D676ULL, 0x9534D0A083AEE1F5ULL, 0xBF507D2A561E8141ULL, 
            0xD8BC76C20B2FFF6DULL, 0x7147A51D183440B3ULL, 0x3D8869E292CAD4FDULL, 0x778CF82F9460D7BAULL, 
            0xEF44E4730D20157EULL, 0x9D5C166A906B0D5DULL, 0x14D2259084150B23ULL, 0x89FEA90FFB5A0A2FULL
        },
        {
            0x344BCA4685DBB502ULL, 0x033608DF5E71098BULL, 0x6A4FFCECDA0C99A4ULL, 0x5EB192DFAF215CE5ULL, 
            0x4803120BEFF821C5ULL, 0x3A60E857F498B53FULL, 0xD24A27010AE5CAF7ULL, 0x38979AD17B978736ULL, 
            0xD735F70933E62E30ULL, 0xADCCEEBDFA72B507ULL, 0xB1FAFA7B0DA16F19ULL, 0xAC725D65AE16ABCFULL, 
            0x1EE3CD9BD00093CDULL, 0x9178A770FD302595ULL, 0x73CC9B766DFB8654ULL, 0xB86810D93F16F6C0ULL, 
            0x1041C7F697491277ULL, 0x072D9F0AB74BFFA1ULL, 0xBAA201BACC4BF8E0ULL, 0xEA573488765FB1E0ULL, 
            0x1423E4A833AEA292ULL, 0xF6D69BDE0B925DD5ULL, 0x196D28F4DFB52815ULL, 0xFE7A49406F1B39BDULL, 
            0xAFC30F277943B8DEULL, 0x6E8AD719A174C130ULL, 0xBB7EBFE588CB6F82ULL, 0xE5C69516A6D20F1AULL, 
            0xF903CDE065C5C972ULL, 0x8EDFF5A055EA0B9EULL, 0xE16D3C7D89EB9612ULL, 0xDFD6424B71A5BDA6ULL
        },
        {
            0x2F0366F2508F32A5ULL, 0x5774873EDB46F80FULL, 0xB83CED7A90D29E7AULL, 0xC7DC6713B63DE620ULL, 
            0xE1C972CC4FE0CEE3ULL, 0x3563AB6AB7E36F11ULL, 0x7BCF92BCC79F9AE2ULL, 0x754F66B7A9730344ULL, 
            0x1EB7FA922CCDBEAEULL, 0x605D0AD10FECB5B0ULL, 0xDB123224FE575311ULL, 0xCD25CEE531498DAFULL, 
            0xB81D68A99A5130F9ULL, 0x070AEAED55732E00ULL, 0x691C2EE43D144F8FULL, 0x75F91F73DB4F236CULL, 
            0x6714837C075DA3BCULL, 0x11EFED91DC1BAEF0ULL, 0x4884F4FF4EC91686ULL, 0x704F61279671191BULL, 
            0x4192D649CEE87026ULL, 0xB3077E18AE7C4550ULL, 0x7C71827A7647E66EULL, 0xD5179F1CF95C60D7ULL, 
            0x820E4BAFC0D7C704ULL, 0xDAEF047EFD1A20A3ULL, 0x3933E9F52FDAD9D0ULL, 0x31A77ECA73FFD34BULL, 
            0x409B39324F8A121AULL, 0x9BE97194CBAAA9C6ULL, 0x11E9B5B60ADEEF91ULL, 0xC1DA53ED09DF07C3ULL
        },
        {
            0x68C70013AA269F3CULL, 0x3EDF79879D63EC24ULL, 0x68A643AD2E76F99BULL, 0x06063AE441A0C8A3ULL, 
            0x3050C0B0D3005EFDULL, 0xD2C9B8D2A1B19C3AULL, 0x79CA720A84E9DEA5ULL, 0x6D9F8DF79CA12EEAULL, 
            0xD8EA32F44039A8C6ULL, 0xAB69747BB684E7B9ULL, 0x13A3F05E34F6B64EULL, 0x2312DFA7105C690DULL, 
            0x311C6C6BE21902E2ULL, 0xAF9A7373F3D5F388ULL, 0x4A99D71BFC60AAB5ULL, 0x145450C02DB1D414ULL, 
            0x40DA89B81BEAD54CULL, 0x255FBC8637578D97ULL, 0x2DB185E06EAA9E37ULL, 0x05D4EFA166EBDF8FULL, 
            0x4E73AD43D9450E4FULL, 0xAC6FC04FE700891AULL, 0xA8674020DE5553C7ULL, 0x7232152023763240ULL, 
            0x345669A4867C7EADULL, 0x0CF6208A10777EEDULL, 0xBD2373EB1529DA46ULL, 0xE668A2E431BE3FB0ULL, 
            0xDE5CFC009079DD71ULL, 0xAFBD43DA4D4DF80AULL, 0xFEA2B7ADA5D20990ULL, 0xDEEDFDB30BF00ACEULL
        },
        {
            0xC008A7AE928AA0B5ULL, 0x16F4B1FF8A34B5A6ULL, 0x2CA007112BFA53B0ULL, 0xD5F3DF4A389333E7ULL, 
            0x0AFE280A4F0D3269ULL, 0xC3C9368AEC9B4646ULL, 0x6278ABB576884BCCULL, 0xD36E1F4940D4640EULL, 
            0x53A71BFC3233144BULL, 0xA19837352C8C6E4AULL, 0x067A0983BE20853CULL, 0x025791908D0DF9E6ULL, 
            0x64928246CA2D7677ULL, 0x4F2F144B6BB62BDCULL, 0xDDF2150A64C7015FULL, 0x24BE729986EF41FFULL, 
            0xE409CC7B3424C5B0ULL, 0x43522A2296968DB1ULL, 0xF056C013B244CA75ULL, 0x9A187E910201C6A5ULL, 
            0xE8613CC3FC65D645ULL, 0x85CC94BA4E1D192FULL, 0xE204B01B18F5CD7DULL, 0xC2ACB39262A35126ULL, 
            0x8AF251ADD57F9565ULL, 0x9EAD2D1DFD210641ULL, 0x41259242D42EB427ULL, 0x3F37B2BF089933DAULL, 
            0x0F344A2908605CDEULL, 0x17F528965EF81595ULL, 0xE2A5BF0E32E88263ULL, 0x6CC393B83AAD49CBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rugby::kPhaseHConstants = {
    0x62FBD63451DEDEFCULL,
    0x79DC4A900CC6CE38ULL,
    0x8DF3B04ED9DA75DCULL,
    0x62FBD63451DEDEFCULL,
    0x79DC4A900CC6CE38ULL,
    0x8DF3B04ED9DA75DCULL,
    0x4F715D1D069B0A0FULL,
    0x788D8A2E3D0C5F65ULL,
    0x5D,
    0xA0,
    0x6E,
    0x5A,
    0xA7,
    0x8E,
    0xFF,
    0x87
};

