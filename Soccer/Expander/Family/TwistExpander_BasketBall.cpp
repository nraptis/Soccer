#include "TwistExpander_BasketBall.hpp"
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

TwistExpander_BasketBall::TwistExpander_BasketBall()
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

void TwistExpander_BasketBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 16079493283739116877U;
        aCarry = 12121912137313915172U;
        aWandererA = 15763299167804640358U;
        aWandererB = 13687615433994225583U;
        aWandererC = 12187635055221500719U;
        aWandererD = 15059164417346324898U;
        aWandererE = 13125282683558291148U;
        aWandererF = 11803172462612175352U;
        aWandererG = 12391400292736348294U;
        aWandererH = 14422757498140944736U;
        aWandererI = 13710400659278526122U;
        aWandererJ = 11706981474785033765U;
        aWandererK = 11792246672214974752U;
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
    TwistExpander_BasketBall_Arx aArx;
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
    TwistExpander_BasketBall_Arx aKDF_A_BArx;
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
    TwistExpander_BasketBall_Arx aKDF_A_CArx;
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
    TwistExpander_BasketBall_Arx aKDF_A_DArx;
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

void TwistExpander_BasketBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12399906621879832548U;
        aCarry = 17643597171887556672U;
        aWandererA = 17501439918892242043U;
        aWandererB = 14016872450886124575U;
        aWandererC = 14516333277351419880U;
        aWandererD = 13273328679637667537U;
        aWandererE = 15946741636671284851U;
        aWandererF = 9822468983803037749U;
        aWandererG = 11798677918888195398U;
        aWandererH = 13131474851482494966U;
        aWandererI = 9428169299874894096U;
        aWandererJ = 11631897344114663742U;
        aWandererK = 12975078613412087598U;
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
    TwistExpander_BasketBall_Arx aKDF_B_AArx;
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
    TwistExpander_BasketBall_Arx aKDF_B_BArx;
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
    TwistExpander_BasketBall_Arx aKDF_B_CArx;
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

void TwistExpander_BasketBall::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneA);
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_BasketBall_Arx aSeed_AArx;
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
    TwistExpander_BasketBall_Arx aSeed_BArx;
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
    TwistExpander_BasketBall_Arx aSeed_CArx;
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
    TwistExpander_BasketBall_Arx aSeed_DArx;
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
    TwistExpander_BasketBall_Arx aSeed_EArx;
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
    TwistExpander_BasketBall_Arx aSeed_FArx;
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
    TwistExpander_BasketBall_Arx aSeed_GArx;
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
    TwistExpander_BasketBall_Arx aGrow_AArx;
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
    TwistExpander_BasketBall_Arx aGrow_BArx;
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

void TwistExpander_BasketBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_BasketBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 9768295296451157619U;
        aCarry = 14966442873338305502U;
        aWandererA = 17261747635166853846U;
        aWandererB = 15831993552141606534U;
        aWandererC = 14379020654857958257U;
        aWandererD = 14549596954379622483U;
        aWandererE = 17341161342555483681U;
        aWandererF = 15558011208644704885U;
        aWandererG = 17436854559640826117U;
        aWandererH = 15571261796843090089U;
        aWandererI = 10715909929741349000U;
        aWandererJ = 11841122952027649751U;
        aWandererK = 12592473747385926433U;
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
    TwistExpander_BasketBall_Arx aTwist_AArx;
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
    TwistExpander_BasketBall_Arx aTwist_BArx;
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
    TwistExpander_BasketBall_Arx aTwist_CArx;
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
    TwistExpander_BasketBall_Arx aTwist_DArx;
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
        TwistExpander_BasketBall_Arx aGrow_AArx;
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
        TwistExpander_BasketBall_Arx aGrow_BArx;
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

void TwistExpander_BasketBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 3 with offsets 1142U, 5324U, 2117U, 1375U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1142U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5324U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2117U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 3, 2 with offsets 1633U, 3248U, 116U, 2069U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1633U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3248U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2069U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 0 with offsets 6101U, 6523U, 97U, 8104U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6101U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6523U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 97U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8104U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 2, 1 with offsets 2436U, 866U, 2383U, 5062U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2436U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 866U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2383U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5062U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 421U, 412U, 813U, 1515U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 412U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1515U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 0, 3 with offsets 630U, 142U, 208U, 664U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 630U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 142U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 208U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 664U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 1, 2 with offsets 852U, 884U, 894U, 40U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 852U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 884U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 40U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 0, 3, 2 with offsets 1512U, 1646U, 576U, 1848U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1512U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 576U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 169U, 226U, 1089U, 999U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 169U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 226U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1089U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 999U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BasketBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 2, 0 with offsets 2310U, 2539U, 4490U, 2033U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2310U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2539U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4490U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2033U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 1 with offsets 6344U, 774U, 1137U, 7861U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6344U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 774U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1137U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7861U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 3372U, 2874U, 8016U, 1015U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3372U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2874U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8016U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 1, 3 with offsets 8014U, 624U, 7409U, 4005U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8014U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 624U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7409U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4005U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1019U, 5791U, 4573U, 1662U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1019U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5791U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4573U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1662U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1994U, 1428U, 522U, 774U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1994U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1428U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 522U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 774U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 2045U, 618U, 46U, 1296U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2045U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 618U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 46U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 37U, 976U, 1451U, 36U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 37U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 976U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1451U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 36U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1588U, 330U, 558U, 1863U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1588U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 330U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 558U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1863U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 [0..<W_KEY]
        // offsets: 877U, 922U, 1064U, 362U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 877U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 922U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1064U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 362U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseASalts = {
    {
        {
            0x9305057586037813ULL, 0x9E44DD629484EA6EULL, 0xD4FE7E7D77FFC0F0ULL, 0xF72248A77578A816ULL, 
            0x7686A8D9E1973862ULL, 0xAF0F1EC1AF26416AULL, 0x468EF405C65298D3ULL, 0x121ED417C4670445ULL, 
            0x387E9711F3C6B1BDULL, 0x360633EC1C4880D1ULL, 0xED1298633F38A090ULL, 0x7C2ABC7D3F1467D5ULL, 
            0x22A50B7AB33716A4ULL, 0xF7ABD868D2987468ULL, 0x7ADAB7A4C03AB403ULL, 0x86A05D6AC7BA820FULL, 
            0x7B98D04844E81784ULL, 0x243EEA27909603B9ULL, 0x550DCED03FFB6C85ULL, 0x1FFF0CFE70179751ULL, 
            0x704A05DCB3D7D1EDULL, 0xD2FE47D2656BC509ULL, 0xBFC51662CDC2B009ULL, 0xD4D19FE0AF822B93ULL, 
            0xEAECC5F2EE0B388AULL, 0x92131A82F11390CEULL, 0x8BD2C62C691B537BULL, 0x7DDB40B15522342AULL, 
            0xDE8E653C8E4F9229ULL, 0xCB282E7586DCE7B9ULL, 0xB5EDB302A0200016ULL, 0xD9AD733980E597F2ULL
        },
        {
            0x630293F1DE2A9EF1ULL, 0x7434B40A86C83DACULL, 0xD9EDF7D0D7D63884ULL, 0x2538C4A2B8985396ULL, 
            0x49FFB37BF20A543EULL, 0xBBE9E6D071CC1C7CULL, 0xAD9F5FBCF9ED8058ULL, 0xD34C14937F95F8C1ULL, 
            0x81A5571F445A5B88ULL, 0xE460A25AB284C488ULL, 0x440DA195CB2FA3F4ULL, 0x1C509F52D8C93266ULL, 
            0x0EB1F014F514F78EULL, 0x22D5CB42E17F68B1ULL, 0x300F2FCFCD867545ULL, 0xC9AAB62D3D454069ULL, 
            0x1B2BAE0457EAD800ULL, 0x90DBB0F51539639FULL, 0xE92A8F6DC255544EULL, 0xBB3DD6337419A375ULL, 
            0x06114728B24F2401ULL, 0x740D93ADC45918A1ULL, 0x9DEA2FDEE41E411BULL, 0x87B2E2003FDCE40AULL, 
            0x72A10A449105CE1FULL, 0xEE84EAF5095F2E12ULL, 0x110D9CD835BAB0E9ULL, 0x71D12949AA38C21AULL, 
            0x6AEA3FB53C07BD31ULL, 0x9DFBCDDF3A7A2508ULL, 0x979AE790704690BBULL, 0xD96D24CE3DE440A0ULL
        },
        {
            0x59F9BFEDEB1EC74EULL, 0x7026E132DD8508A7ULL, 0xF7DA42527A8136A9ULL, 0xE6DC4E67D70CDFC3ULL, 
            0xC92AA193E4EFBF2DULL, 0x6B383211856836EEULL, 0x9687EA60D1479952ULL, 0x446DBDAB6BCCAD59ULL, 
            0x88E968D3E2D2AEFEULL, 0x6A10172A489B4616ULL, 0x975BCE2F7D5FE149ULL, 0xC68994C3FEBF0446ULL, 
            0xF1F0F9A151B91DBBULL, 0xFD13A0BE736D8F01ULL, 0x44A65070A9ADC713ULL, 0x363542BB57B3D6D9ULL, 
            0x31859C78CD4030E7ULL, 0xEFB8AFE42E31BB9EULL, 0xA0EBC5A5457A182EULL, 0x653C91C703579555ULL, 
            0x66E4EEB0557D4A98ULL, 0x0DBC83E02A3D0B3AULL, 0x0D33B3AB09531002ULL, 0x5CF3254847FF9DB6ULL, 
            0xF566C3DA72F88AABULL, 0x43F571685B18941BULL, 0x39AF89A6A05DBBD4ULL, 0x89D97E9145B26CC3ULL, 
            0x05F3A606696098E1ULL, 0x56AB6C08993BA4CFULL, 0x4BD8976A8475145BULL, 0x2490582435F4D678ULL
        },
        {
            0xC877177C60CAE343ULL, 0xAB6BAB6328B000E2ULL, 0xAB27759015EE6178ULL, 0xA1FA69592BA91C20ULL, 
            0x8BF331E32AB1809CULL, 0x58C0FACD36D6BB7CULL, 0x074901642F4F2F0FULL, 0x72F3EACB53B5544FULL, 
            0x50823D177A41711AULL, 0x11566CF088D3FD88ULL, 0x21DE37AE6495FF39ULL, 0xBFB4935A78E9A0C5ULL, 
            0xA5F4954ACEECBB28ULL, 0xAC3A6F60E7E51E98ULL, 0x41E1EBFE6F8B5AE8ULL, 0x45A2F68A917C2B38ULL, 
            0xC9482662FA241493ULL, 0x75492E643E50F8ACULL, 0xA479A7A6B7A1D5F6ULL, 0x50910D8E5EB4F2D6ULL, 
            0x17FDDBD51267ED7FULL, 0x7D450C98C2A69F7EULL, 0x6D0AD76B2F3CD9A0ULL, 0x916C47D33E5F49FBULL, 
            0x31384796DB6DE232ULL, 0xA22E708AE6AC399CULL, 0xBCBB30F7D1E8741BULL, 0x69D3325CBBB3290EULL, 
            0xF37D7873AB689B89ULL, 0x89DAE7E19C92218AULL, 0x3BF4697980C332CEULL, 0x8DB10955D571D6EAULL
        },
        {
            0x54610E547C0C9560ULL, 0xDD96C6655100D357ULL, 0xADF8C5283234BEF2ULL, 0xB39C6E867A8A0C4EULL, 
            0x4FCF19E749B3AB9BULL, 0xE8A2D581C4185BF1ULL, 0xB8194FFF537237BCULL, 0xAD9FBA74F8D2F7DCULL, 
            0x9F3EFBB6DF0687E6ULL, 0x5C5FC735A5882947ULL, 0x433793009158F5A5ULL, 0xAC80BACC9DC4F3FBULL, 
            0xDDF2F273227EABC0ULL, 0xF786E057A477AADFULL, 0x0C74300711D9F461ULL, 0xB8B33E822F6D35ADULL, 
            0xF0F488EEE4DDDBFFULL, 0x7E6645E88451B60CULL, 0x8993D5470F4DF4DDULL, 0xC6C9FFA314D9C5CBULL, 
            0xDAEA8E2DD13C0D07ULL, 0x4287D29ECF520187ULL, 0x0E5C093028F055B2ULL, 0x319F29F4C23FFF80ULL, 
            0x7172D819B89DCD47ULL, 0x2DAC1057D32B66F0ULL, 0x9FCE12E817EA9A46ULL, 0x77CF74E6C30AEC0DULL, 
            0xF03BB88AA55FF4C0ULL, 0x4BBBAAF3FD17F63EULL, 0xEB5A578F212837C5ULL, 0x8F5562C94A413699ULL
        },
        {
            0xC68E49C91B9A6FA1ULL, 0xB804D9E3A6C202C3ULL, 0x86ADF6D34B842E30ULL, 0x912D2DE818E1257CULL, 
            0x5850582D79CFFD1FULL, 0xCCCC3C99F1A58E56ULL, 0xE2F9B7CC3CDD64BCULL, 0x52C03710364AFD45ULL, 
            0x30F11696FC7CA5A2ULL, 0x1303A6F63FE109CBULL, 0x82CF0B33AF236D7DULL, 0x9C1CEE76635214E3ULL, 
            0xBE0BA35E96D872D5ULL, 0xBD18E5AC58A1ACB0ULL, 0x6E93ABD5FB5D1464ULL, 0xECF816E8AF4E21B5ULL, 
            0xE87390B79E515BA5ULL, 0x4D889F150F264479ULL, 0x1F29A27C24F3ADD5ULL, 0x34F8A8668AF964EFULL, 
            0xA98E97143844D230ULL, 0xEFE22AF86DB7321AULL, 0x698BD8A9B1081E2AULL, 0xF4134DB69735A59FULL, 
            0xA9F9DDB60AE4DBA5ULL, 0x0831E158F97F54AAULL, 0x12938B91B90887C5ULL, 0x970B72ED79D46559ULL, 
            0xF502499DA873F31EULL, 0x95604B5BBFF0E2DEULL, 0x13A555AC459AD91DULL, 0x6886A069C5F03CA9ULL
        }
    },
    {
        {
            0xE7E89FDEB940765DULL, 0xCDD1ED48A2D7506EULL, 0x71CE54FB1FCDE7F8ULL, 0xCD94AAC9F50BDFD0ULL, 
            0xD3747ED2F45BA8E2ULL, 0xF3573C6B2DA93CCCULL, 0xC630215EFCEC65C2ULL, 0x786BB39AD30226CDULL, 
            0x0D89567C3D173541ULL, 0xD0D13472C6573385ULL, 0x030A5D97D07B78EFULL, 0xA0F7ACA676379DF9ULL, 
            0xB901FD53708E0CD0ULL, 0x23EC1219D23E6FE3ULL, 0x325BAFBB3043610DULL, 0x487A7713F53280E4ULL, 
            0x33B6B7D2F544E86AULL, 0x05A302AF972394F0ULL, 0x5E9458686D1D71E8ULL, 0x7D7C884AF9234E6EULL, 
            0x14B802357F7B01BFULL, 0xDA853DA77C011502ULL, 0xCB53DA71E48C5D57ULL, 0x1E801F849B52BD8EULL, 
            0x29BF127E22664445ULL, 0xCF70C29525C4C184ULL, 0xE09ECB45CF683555ULL, 0x1E77FE72A7FE6954ULL, 
            0xEE6EAD15661BDAB5ULL, 0x1627E0C6875774DCULL, 0x1B9C347CED30713DULL, 0x76C3847EB4BE03F3ULL
        },
        {
            0x92CE1C9796A9DEBDULL, 0x8987AFA18F67EB7CULL, 0x5FBDBBC81B9587D0ULL, 0x3A7A85860FF65F1EULL, 
            0x941C40FAE7EAA858ULL, 0x42D9D245D78E4E04ULL, 0x725C41BF292E7BF8ULL, 0xCBA3165D27367137ULL, 
            0x8839F83A49A603DDULL, 0xA0B60F1E66EC61FEULL, 0x1A9C6532BA497802ULL, 0x30C61739558E0809ULL, 
            0x3F1AB40F714C6E3BULL, 0x476BCB28DE936C27ULL, 0xC2B29F030935E168ULL, 0xE459597D3B10A143ULL, 
            0x393ACEA00DFB5749ULL, 0x5810061C9E498CB8ULL, 0x56D8FF6633BC0329ULL, 0xF26CB336B1A9F08DULL, 
            0x45717930E03C4F4CULL, 0x57A3A65AB9EA1AECULL, 0xFA9682622FF0F7D4ULL, 0x1B2518B83DC208B9ULL, 
            0x995C5DF12FAB163CULL, 0xE3679564333B3BFDULL, 0xB6E12ADD4315F376ULL, 0x678832D210CA639BULL, 
            0xF717646522DF8EA3ULL, 0x728B153648CD21CBULL, 0x5CA5A0952DD812C1ULL, 0x8DC9F50B8C3966EFULL
        },
        {
            0xB2050041B7295EFEULL, 0xD7AD732F098EBC94ULL, 0xCE2A55EAB44A57C4ULL, 0x98899272BCDB55B4ULL, 
            0x890D5AD1196E8E10ULL, 0x70A29FED124B2B31ULL, 0xA890E82BE291AF93ULL, 0x581C1DE6EA7DC5BDULL, 
            0xECCB9EB35CAA3835ULL, 0x9F905F5317C163B6ULL, 0x18DDA5C0832F4607ULL, 0x48545F7E463FCAD2ULL, 
            0xCEBA47182A238939ULL, 0xFA92858844012B3BULL, 0x9C53E6BE6D65DB84ULL, 0xA0F5A26C37A2DBFBULL, 
            0xE8EEF0398DF8D4DEULL, 0x6D2A35C85D741E8BULL, 0x81670FE3B198F7ABULL, 0xE67863EF1D2B0B12ULL, 
            0x41FEDA03E51B8263ULL, 0x212E2EDB801D3BCEULL, 0x6F911C6388FDE81CULL, 0xEAC2A7C967BA4408ULL, 
            0x128AB62AE28EA2CDULL, 0x060739D7439DAADDULL, 0x29B46CF9E655B146ULL, 0x8F8DC367A022C0B5ULL, 
            0xA83C9CADA234E0BAULL, 0x2ADDD1ED2642305CULL, 0xD035A643C95EDBEBULL, 0x68177E5EFC7F9DE3ULL
        },
        {
            0x4C2C7376EB0579E1ULL, 0x70B81DDEA00D6AB1ULL, 0x5EA4A93A8B15967DULL, 0xD2ABBFEB89D2D2A7ULL, 
            0xDD6C8C45221EF932ULL, 0x74919BC8D381D64CULL, 0x46580C59D0CF386FULL, 0x3BE6FB5B3831F911ULL, 
            0x93CC11B25284A081ULL, 0x4239776D9D4D3870ULL, 0x2B0038B307573DD3ULL, 0xB1C2E3D3BC8DD326ULL, 
            0x37F3C255849D9CC8ULL, 0xBC78FF6E4EBD5D05ULL, 0x94E8436A67505E37ULL, 0x86D4A2FC93534221ULL, 
            0xD56A3C2A3E92834AULL, 0xFB2AA82F100B6562ULL, 0x9B8BA8847283CA13ULL, 0x4CC6C2E6FFA1010CULL, 
            0x9FD52D63F32C5CCEULL, 0x5F3F764B6CEF7A10ULL, 0x9F4F5E0AA400E3DCULL, 0x9E654A55FC870F53ULL, 
            0x79A99D3783BBFBB6ULL, 0x5E99F6D2885811AEULL, 0x5C5F1AB558A8950DULL, 0x9A5C99874D825CC3ULL, 
            0xDF828A5AC42B02A4ULL, 0x7BE5D7D919A40AF5ULL, 0x1947390357E700B0ULL, 0xB3E4B6A6E2E6839CULL
        },
        {
            0xCA552AB8502F16E0ULL, 0xFD8445CCF288D6E3ULL, 0x45DDA5435A49DC64ULL, 0xFFD6B2DCB7D68B03ULL, 
            0x5D58614AF5471596ULL, 0xA8D3551E461C969EULL, 0x70B24E6E21ECF55AULL, 0x9FDC0BAB9868210CULL, 
            0xF28DADD2600701F3ULL, 0xB1AF8A7622AF2628ULL, 0xB2D6ACE8F554614EULL, 0xD7D7F82D3F252E45ULL, 
            0xAB7E87FB6A545DF8ULL, 0xF05F79CFC88729B3ULL, 0x5A1928830F714151ULL, 0xE8E753A153526D97ULL, 
            0x6CC66E9147C27C41ULL, 0x339548BC2A8A9922ULL, 0xA83D5BB552D74124ULL, 0xC979EA016E65820DULL, 
            0x33C1BB88A3B9F576ULL, 0xA3237CAA38764137ULL, 0x94E0CA8C7C3E20EDULL, 0x588D6A4E285AE2B0ULL, 
            0xD9131BDFF69C6FADULL, 0x0629A036F69F9D9EULL, 0x4A520813B4EF7FD2ULL, 0xA46AFECF795F8BC5ULL, 
            0x33A080371448579DULL, 0x6990DD03E333046EULL, 0x81359D58C1B8FB76ULL, 0x87BB6D98F5ED8008ULL
        },
        {
            0x6A5332D45E8165D2ULL, 0x716B697BDD097A77ULL, 0xB5F1D622BD1E3794ULL, 0x89A49122098C7D7AULL, 
            0xD937BE023AC545FBULL, 0x6007E913CD0717BAULL, 0x391884EFD278B97AULL, 0xFE287354B377B499ULL, 
            0xC95014312636B31DULL, 0xE13C78976F12C625ULL, 0x5D7AD14221BAD1F1ULL, 0x22815E5E0C91B8DAULL, 
            0xB7345D4CC4931A3EULL, 0xE72D1BA0F6BE54BEULL, 0x59B4EFE2EC0F4990ULL, 0x8A20E441011F291FULL, 
            0x8B73E88208732C2FULL, 0x65F6B2C3D0BFBC94ULL, 0x3D25E1838F68F6ADULL, 0x65A8FD3A57B8D193ULL, 
            0xD7D524FD8C23760DULL, 0xD9F9A08BF59D6C67ULL, 0x20A1342962322765ULL, 0xF7BDD7EF3D2BE9E5ULL, 
            0x6113979FE7357568ULL, 0xD4644C0DCDAE3F7AULL, 0xB5887DEE9CA06EF3ULL, 0x3A8E6CF8CA592823ULL, 
            0xFF6CFD41163109EBULL, 0xBB832631A247DF41ULL, 0x8C3B649EF7077954ULL, 0x25980B35083ABCF0ULL
        }
    },
    {
        {
            0x1DF478FCDE6FDB6EULL, 0x45D33BE883423E01ULL, 0xE9B9870E152EF9D7ULL, 0x7FF73E8972604AE5ULL, 
            0xC45F90286365EB8AULL, 0x29AB1D1B91530CFEULL, 0xA3E055FEADBB9370ULL, 0x2C857521C41260E9ULL, 
            0xB937389C0AD396ABULL, 0xFCD2239936393F3DULL, 0x9389473309344EC8ULL, 0xC01EF63867E212D9ULL, 
            0x8301DA3CAD2A4AAAULL, 0xC1791748230BEC6BULL, 0xD335863DA7ADD55DULL, 0x3CAE478F4AD6661EULL, 
            0x19BFD114E7F5A6DCULL, 0x8382960E0461258BULL, 0xC445A213A4DB1556ULL, 0xEA8DDD90AAEA21E6ULL, 
            0x36D32B92E077406BULL, 0x39938D41BDEAC2D4ULL, 0x0E0759F65D2B89C8ULL, 0x603FDA59793B0F92ULL, 
            0xA7E94938EE9E486AULL, 0x335C9110D300F65DULL, 0xA9357AFFB4765082ULL, 0xF0321E27D7AF7E26ULL, 
            0x3877C2E28B512B2BULL, 0x2E5EF919DEC15E45ULL, 0x4476BD49A2C8856AULL, 0x278EAB82A20053B9ULL
        },
        {
            0x27D751B4ED22AFC3ULL, 0xF8B5607CD7BB0848ULL, 0x4542727A61A10308ULL, 0x177C23F057856AF7ULL, 
            0x63043FC1C1323E42ULL, 0x75CA724BEB091BEFULL, 0x2DB95DB0248925FDULL, 0x30BD106DE88E336AULL, 
            0x0821C8938F017856ULL, 0x42DE0C06C2D6E8B3ULL, 0x50558D21B7EE60E0ULL, 0x4262B682CCAA0899ULL, 
            0xED395317670463DDULL, 0x8AAEECC0E987C0A6ULL, 0xD30F6ECCD76FF1F0ULL, 0xD23A8F129CEF67A9ULL, 
            0x3C3BE31566749247ULL, 0x0D8654B07C139C2DULL, 0x7F9C1A7BA8326C23ULL, 0xE5161B6A4973529EULL, 
            0xEBBFB5335C4AD6C4ULL, 0x2D68195B043DA69FULL, 0xF375BD960C65B823ULL, 0x0933AF97810D10C9ULL, 
            0xA53FC7C7E7A17596ULL, 0xEE8A605289EA5246ULL, 0x6A7DBCEEBACB76E4ULL, 0x2F2AD552D6C92690ULL, 
            0xE3A708E53EF7661CULL, 0x9F9C9E9AF6448BDCULL, 0xF9910D114D13D2E2ULL, 0xE5C4AAAB1D9B5F15ULL
        },
        {
            0x0360E1A37E954709ULL, 0x9B13A7F74957593AULL, 0xFB1F0C0AA8A0C3F7ULL, 0x8FA3BF02982C2A3CULL, 
            0xC8DA16541A1CD898ULL, 0x675D53E59A68384DULL, 0xA50290AD680897B0ULL, 0x4A6140E36EE65225ULL, 
            0x158399F8A22BBF3BULL, 0xB92692F2FBC238CFULL, 0xCEF32392385A381DULL, 0x04F6C1B76715D212ULL, 
            0xF6A13A94C5BE7D8DULL, 0xF8794137CE9209D2ULL, 0xA71031AEFFB56E1BULL, 0x893CB4CD4D8C0806ULL, 
            0x97FDE38AFA8B0F55ULL, 0x721DF9738326A6EBULL, 0xF38F5E961A828A94ULL, 0x225A396E10704938ULL, 
            0x1B9A8CCF34C52968ULL, 0x07AB8A45DF188FD2ULL, 0x3CF15BC32C829B3DULL, 0x8E47D0552AF87090ULL, 
            0x841104B5745DB6B5ULL, 0x3A6CE28EF3EFF730ULL, 0x9CE122BBC72DB35EULL, 0x1D6F3346565F5614ULL, 
            0xBD924FF1DF9E2966ULL, 0x5E15C6726F115A28ULL, 0xDB64B79734C3C3F8ULL, 0x1BA111533C8560CFULL
        },
        {
            0xA6EA35C44F298ACFULL, 0xD6C1F7BF26614BADULL, 0x4FEB987212E585A8ULL, 0x192C97158DBD2660ULL, 
            0xB7A002C16DD384BEULL, 0xB2CA2801AB0A4A7DULL, 0x388144680901F9F6ULL, 0x0180D1D48446B114ULL, 
            0x30CD23D0F34324B2ULL, 0x0BAC77780C7F5E86ULL, 0x65B5ECF281CDFE41ULL, 0x6D725245557A80D8ULL, 
            0x64E0DC5A34E12E3EULL, 0xC230D8B34A4D14A8ULL, 0x6DFF260FC0235C12ULL, 0xC420898455664EC5ULL, 
            0x69A29CDF0BD441D0ULL, 0x4CD1E8DB33BDD2D8ULL, 0x6E7D035E57586AF0ULL, 0x32365DE411B650B0ULL, 
            0xD25B6170DCD86558ULL, 0x5B37FBDA8E248F48ULL, 0x49D1B4099A9C7A3FULL, 0xC7AB8A3ED63CB864ULL, 
            0x715EA038062D9C9FULL, 0xA26FE91D76E8EC69ULL, 0x6E8FEE86E6D54653ULL, 0x1ED41FF9587980B3ULL, 
            0x032202CB94C43679ULL, 0x53B5DD2C53404FF5ULL, 0x733A37C29F5668F5ULL, 0x4E65E65DED1C7D60ULL
        },
        {
            0xC30646A82C664BF7ULL, 0x3A486F6F60546095ULL, 0xC613FF4C9FFDB2E3ULL, 0x543A5AD5763F468CULL, 
            0x258A1A13458B8DA5ULL, 0x76B841EC748351AEULL, 0x948492441D399042ULL, 0x02373965E38610A7ULL, 
            0xD31AF66A0B8538BBULL, 0xC2C76ED5086FDB82ULL, 0x8E2DCBBF66490597ULL, 0xAD6EB59F464BF5E9ULL, 
            0xE6D00932467D8C51ULL, 0x8997738C1B5444B7ULL, 0x08C789EB13A55C31ULL, 0xA184ABBFFD5FF423ULL, 
            0xD1CEEE03AF37D814ULL, 0xB6BB5D714A73AE80ULL, 0x43ED8545F1991301ULL, 0xAB354969B7905871ULL, 
            0x07812CB9AC154C1CULL, 0x8FB65A10EAEE0A91ULL, 0xCAC106A652EC8F27ULL, 0xD8C920AB94BAE5CDULL, 
            0x59D0542F3960A1E8ULL, 0xE92F1BD7EAB8FF68ULL, 0x48F25ACAC0BD97E4ULL, 0x90AF350F4C5C4D10ULL, 
            0xDD32E477C7E44DFEULL, 0x2DAD05ED08DDC8EAULL, 0x4FCDBF5AC2D6BBB5ULL, 0x44255DC637DFD18CULL
        },
        {
            0x81453069F63B63E2ULL, 0x08C1B7690AD67432ULL, 0xC7EAB7715EB16D1AULL, 0x89631042A2DCA047ULL, 
            0x9E0928FEB516B0A4ULL, 0x7F9AF8E2B70CBB20ULL, 0x1AD8162F586158B2ULL, 0xC86744834DD25513ULL, 
            0x4C17FEC400D0AE78ULL, 0xEE369B94075CA0BBULL, 0x25313DBC12399577ULL, 0x51D321708196CB15ULL, 
            0xFEFB91FA598E8E46ULL, 0x2EC1BE911C9C4133ULL, 0x0A341B3050B4D3F2ULL, 0x524DCE250349F2ADULL, 
            0xEE3943AC187F1A82ULL, 0x1D922B26AC48C03BULL, 0x4C0598E15A8CABFFULL, 0xB4ED650398304D43ULL, 
            0x9EE1C964457B50F9ULL, 0x5E21D8C5A9491C14ULL, 0xFEF3A64E64D123DAULL, 0xBBFE6882F3D8B2A3ULL, 
            0x0AEF579F31C35D77ULL, 0x2DB775FF92E5F353ULL, 0xE6B30BCBB2436859ULL, 0xFC381ADB64A37455ULL, 
            0x93AA3495BD74E4EEULL, 0xDACAF5D1D91C8970ULL, 0x632C09BD09F19854ULL, 0xD11BAC78B1202562ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseAConstants = {
    0xD089CE3C15D8BCF5ULL,
    0xD0714A052E078BC6ULL,
    0xD55CD03AF19E089BULL,
    0xD089CE3C15D8BCF5ULL,
    0xD0714A052E078BC6ULL,
    0xD55CD03AF19E089BULL,
    0x9DE4C8EA67BB2C5DULL,
    0x97B5AD1B548DBAD6ULL,
    0x3D,
    0x12,
    0xBC,
    0xF5,
    0xCC,
    0x6E,
    0x53,
    0xC5
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseBSalts = {
    {
        {
            0xA9F238B894ED5778ULL, 0x50D0BD810DF61B70ULL, 0x7BE16372B8533DD9ULL, 0x86410CD29B4BE64EULL, 
            0x567B2F43E9414EB5ULL, 0x57711738F3B7E159ULL, 0xC842040EECE7D6B4ULL, 0xFF626454F9E7BA12ULL, 
            0x3B97B88F6B6E5E5BULL, 0xAB895091B0C6CCBFULL, 0xADD489D269F3FC8DULL, 0xC50F6CE190868D49ULL, 
            0x074EBE32972D2C1AULL, 0x917CC1B20D352E6FULL, 0xA756A3403723C1E3ULL, 0xBF725B5F375AA825ULL, 
            0xAF0B3A14D1235F2BULL, 0xDAA1AC33BFDBC20DULL, 0xD906780A7FB391AFULL, 0xD722D9C1CF98E4EEULL, 
            0x00AE584A0582B284ULL, 0x06C0DA16E74A95E5ULL, 0xBBF901F60D3ACF95ULL, 0x09644775865E1168ULL, 
            0x182399C964EFE820ULL, 0x053C756088C1D86FULL, 0xA0435BC968484D1FULL, 0x8DC80FB0E18D2ACBULL, 
            0xB5E7186874E3DB32ULL, 0x44A3684B952E13D3ULL, 0xA24564E838D91C41ULL, 0x56BD6B3DFF20463BULL
        },
        {
            0x504A8DD1F27944ECULL, 0x98D8426167A53172ULL, 0x65A99BE929EA20DBULL, 0x7272B180F7EBEF74ULL, 
            0x27EF40CAB75E5BE2ULL, 0x4BB50A536CA6135AULL, 0xDEBBAAE016AEF6E9ULL, 0xBB3F194603ED2A40ULL, 
            0x6D1E6DDD8EDF43ADULL, 0x37E7499F59EE97B9ULL, 0x78190183A25C7B44ULL, 0xFF59239F918C0B7BULL, 
            0x159920D48D204E5DULL, 0xDA5239000E28EF2EULL, 0x00BAFF263EAEDBCAULL, 0xF332E845CFFC771CULL, 
            0x3EAB4B4AB36A3C21ULL, 0x058F03134AF798ECULL, 0x45EB099DDC0965E0ULL, 0x2A7184C39A2ABD54ULL, 
            0x0D3F43779807BF99ULL, 0xD4E8D3469FF00CB1ULL, 0x3B53982157DB41B0ULL, 0xE94D05313F2DD79CULL, 
            0xA8C9FF115EBC433FULL, 0x78253015A2620E2CULL, 0x503749CBDB4DD833ULL, 0xB939E04E6337CF54ULL, 
            0x89468261A31A772DULL, 0xB8A02A98B908F8FEULL, 0xF2A7BDF1AAB9E885ULL, 0xCAD46C87F7C048CAULL
        },
        {
            0x16748CF3C6E93F9BULL, 0x4BB741C1E8967BF5ULL, 0x3DF0D9FC00B4D110ULL, 0x2EC4053177078336ULL, 
            0x9B852D6FCF3320A2ULL, 0x2B45663331E18745ULL, 0x4F34B516BE9DEA97ULL, 0x02551FC1158A735BULL, 
            0x3FCD8BEE483FBC6BULL, 0x546C15FB200433A7ULL, 0x7E399549F0926C98ULL, 0x2313C71852D5ADEBULL, 
            0x3775B48C0B20147CULL, 0xCEB939E70F5444B9ULL, 0xF1A85DBF939E2591ULL, 0x291CA735EED4B5EAULL, 
            0x1697E5E3E26A0F6CULL, 0xEE0996B09248FA1AULL, 0x1C9D51AD1A8476E5ULL, 0xC570A324AEFD10CAULL, 
            0x5ACD15C1A25FA35CULL, 0xCC36F2C38CD82EC1ULL, 0xABF1C0D4ADF1BDB2ULL, 0x8F43803446163EDDULL, 
            0x2F2DD992E0018A15ULL, 0xADF99EF9688C0FE6ULL, 0xF51C8504D331B516ULL, 0xF28D733AC06337CBULL, 
            0x049756F52CDBDC94ULL, 0xC4AD7F5B3D6794F5ULL, 0xABE56EDBA4417D74ULL, 0xA114757ADA647E13ULL
        },
        {
            0x500417085DC5E95DULL, 0xB11946E29DF4806FULL, 0xFE1E94F693836205ULL, 0xEFDD057552F55DDEULL, 
            0xBFF720AC3440577CULL, 0xF25C5FF2F65138D5ULL, 0x3135697FDA15C4D7ULL, 0x23BBD4BE400D98D8ULL, 
            0xE464631506052CA2ULL, 0x008D31C6F868AF40ULL, 0xFC30304F4324E4B4ULL, 0x21EC8F80346E2792ULL, 
            0x362F9CD27E7A73A0ULL, 0x47400894AB2B659BULL, 0x4C98B2D2025753A9ULL, 0x350B862A0A37D808ULL, 
            0xD5ADD41CCB7062C7ULL, 0xD2CC50EA199F0B02ULL, 0x5A5E0D2DBEEA51A6ULL, 0x2BC403DC99DA0A53ULL, 
            0x80924D1B86274598ULL, 0xB73833DB3E188C06ULL, 0x229DBE3EA37EC12BULL, 0xB4D19F2EEB90FC75ULL, 
            0x00336F37DAF4876AULL, 0x1DAE8F50E812AEF4ULL, 0xD7D8764EF09CEFD2ULL, 0xC91A9EA39DA9ED4FULL, 
            0x5C68D3AD3B47EC91ULL, 0xC8D5736469EF401AULL, 0x5BA45C6FB91C33AFULL, 0x58871C7430EE93F8ULL
        },
        {
            0x95E4C6EEC59D62BAULL, 0xDF6588F71DA19253ULL, 0xEC151C65B5A82AFCULL, 0xCD77D03D3E8E3840ULL, 
            0x558CEABF21BCA699ULL, 0xF0630DE948FCFB37ULL, 0xC1FF8C9276F4D2D2ULL, 0x48B463E451A5BF31ULL, 
            0x72A12B2A1EB8C4ACULL, 0xF495E46998767DB0ULL, 0x347A0CEDFE5FBB41ULL, 0x85843012DB037191ULL, 
            0x98932567D97C3C3DULL, 0xD2FCFFF6A9CDA227ULL, 0x93BA0D26AFBFDCD5ULL, 0xF5D3E2E76A96EBEAULL, 
            0x7930CD6CDCE45063ULL, 0x6D1AC97D145653FBULL, 0x3ADBFFA6A123DDB3ULL, 0x4CD5DCDE800A80CBULL, 
            0x2F59BF2971CBC023ULL, 0xB1CB71335EE53A0AULL, 0xD47E7B66F93C97DDULL, 0x46FD202B89FB4401ULL, 
            0xBECA946F4A8167D6ULL, 0x8A7FBA2841FCA2A7ULL, 0x0D7311E232073AC1ULL, 0x44856F3C7DAB67D3ULL, 
            0xD8059D91B7E66D40ULL, 0x77C6234D34DEB10CULL, 0xFAECDEF6E3E4980FULL, 0x483A011CF05280C0ULL
        },
        {
            0x738A91721AA1E4ADULL, 0xF385F2944D238AD8ULL, 0xBFAD56F30B11EFCCULL, 0x64CE1C8EA1EA9528ULL, 
            0x0C36FE615B952F33ULL, 0x4C00F9B0B8C43D31ULL, 0x5312B595D06AF218ULL, 0xE95A84C4D81CBD66ULL, 
            0xDE4DFD7C2391F48AULL, 0x523259DAF7F490FCULL, 0x789F743429983A1FULL, 0x6C31D7A5F8DCADDEULL, 
            0x78ED49CEFB6E6670ULL, 0x1A2E1B30884A9ED7ULL, 0xC8CC997AC23404F4ULL, 0xD2CA6E337517AC0DULL, 
            0xFBB17FB2B48CA4FDULL, 0x62119C4108C20EB9ULL, 0xB989213B6BAE152BULL, 0x45E81D1EAA389224ULL, 
            0x53A472858916978DULL, 0x67FDD7BCE869DB70ULL, 0x6DAFDF38E462B8D6ULL, 0xCFEE4B91C5F72A3FULL, 
            0x37D315986C9F0D57ULL, 0xBF8AD22781E564C9ULL, 0xCE27E5C5CC9991BBULL, 0x867CC5AF7EB5E09BULL, 
            0x967A57D84D342EAFULL, 0x02BC4F9094FAFEC8ULL, 0x8C6B1DEC341E7357ULL, 0xBE2F6DDA6B209FCEULL
        }
    },
    {
        {
            0x2951CB4EB2B5421BULL, 0x0344EFD6D65A8DAFULL, 0x7A467D2C8E61E51EULL, 0x542850C306D92DD0ULL, 
            0x1549FF0857A49530ULL, 0xC8E0333C3FBCB115ULL, 0x114613DD6B4C252BULL, 0x076CC2E071720C69ULL, 
            0xAAB492C7AA90A718ULL, 0x31B9328949D632C5ULL, 0x3103FE67C9E1E29CULL, 0x3819213C66736845ULL, 
            0x599BC1573609B1BDULL, 0x59A5098055191220ULL, 0x0DE842A355FF0C00ULL, 0x732892B4A594AE86ULL, 
            0x2EDFABC5E10A0DAFULL, 0x1DBA83A516F70C00ULL, 0x8D89FC5E895B9DBCULL, 0x5C242C4C962BD284ULL, 
            0x585FE9A9A6E7DB23ULL, 0x3FB633F720E7CF93ULL, 0xD06D807652D4F56DULL, 0xE9295912D05177B9ULL, 
            0x9D8D64C3CA95D749ULL, 0xB7DCF17C873CB51AULL, 0xB5149328BD90255AULL, 0x8A2DF7465DD512B5ULL, 
            0xB81FE706F86C848FULL, 0xEAB1100D8B56D40CULL, 0xB01A6D7C9400E510ULL, 0x853390A2DFB0ACD3ULL
        },
        {
            0x1025A9EA694C4549ULL, 0x600733323B428B57ULL, 0xE9E72CB1C062D3ACULL, 0x893C1CAB38E35893ULL, 
            0xB6AB39962B5A3EABULL, 0x74597DCD0FA8ED00ULL, 0x20E443B78311A700ULL, 0x2FF1F78F1B5E8DA7ULL, 
            0xEDDCBA43ABEDDAACULL, 0x95CBB59C3253D973ULL, 0xFC6B21B8EEFA5CC4ULL, 0x9CF7B8A33EE67075ULL, 
            0xC272A4E2DAA0F623ULL, 0xB5BB1F4E775EBC37ULL, 0xD3D369397D8E4473ULL, 0x2B79E9326709E474ULL, 
            0xCB5C49AD3D6E369DULL, 0x0AE65B90050F7D95ULL, 0x5D407D3DC7209DEAULL, 0x62A3349E85580070ULL, 
            0xCAB365BF06B76810ULL, 0x5FFBAD88B5C2E234ULL, 0xA91F5813081A96D7ULL, 0x4B822FE977C22C6CULL, 
            0x5E8306B41572A229ULL, 0xE7025C50AC672D9EULL, 0xC8A0F9E443855DFFULL, 0x929F020CA5E06038ULL, 
            0x171A2B1D5AE5E7C1ULL, 0x27383C514044F60AULL, 0xD7477E0593056365ULL, 0x633E466FEC0ED37DULL
        },
        {
            0xA5B1A080181C32DAULL, 0xD367E8AFA187330DULL, 0x0678E0CD093FCB8DULL, 0xB298B796ED4E2409ULL, 
            0x1A8F700F55530DC3ULL, 0xE3425E115339C930ULL, 0xE7D59FB3588D84C5ULL, 0x552242288F53FA38ULL, 
            0x9D0CC9FAA45A151BULL, 0x5C28A07291E049C2ULL, 0xE63F87B0DD72E324ULL, 0x652591E7E3026B72ULL, 
            0xC6E0E5834C1E9A50ULL, 0x1BE057557B3AD395ULL, 0x9E756CF75B56D7D7ULL, 0xAD2C4CDDC3A7608EULL, 
            0x54D1A264857F564AULL, 0x87EA1BF87EF7C5EFULL, 0x2DB3904DD533AB10ULL, 0x97E5E62BE731742AULL, 
            0x15AE5B9BAF07DAABULL, 0x63DFDF262D39D4FFULL, 0x6BCAC059D5F2DDABULL, 0x671F4BD08C002D3CULL, 
            0xD554FDD72E50D01DULL, 0x2E3F25B43391C37FULL, 0xCB4EC0C63E8DD44BULL, 0xACB856DFB3AD025AULL, 
            0xC1507E91406973F1ULL, 0x174C9FB4BA302BA3ULL, 0xED1B4129ABD5DF7AULL, 0x47BB4F26EF5A938EULL
        },
        {
            0x4F07B0FC105F779BULL, 0x48F2DC54519B066CULL, 0x5D01313BC6EC7BE6ULL, 0x9DB7B69399ED0F0DULL, 
            0xBA736CD8EFCF2A6BULL, 0x201BF80E42319CD1ULL, 0xFA7A4425531093E0ULL, 0x38287DCDE848119FULL, 
            0xD702A2D9F3AAC02CULL, 0x979B9DEFAF3530F8ULL, 0x1D65CD2560894772ULL, 0x6629DA0013A482D1ULL, 
            0xF607272BA0146764ULL, 0x462B64606E46B585ULL, 0xA2C5C1FED3CE3CADULL, 0x7A1CFC80D6CF347EULL, 
            0x3913CE6F9FC47FB0ULL, 0xEA752496BDB1E99DULL, 0xFFB77B998A3C8B0DULL, 0xAF29E6E98D2D8A36ULL, 
            0xD9B28DC3C8B930C3ULL, 0x485125DC797BC272ULL, 0x4EBDD875B456355AULL, 0xBC493FBA4627FB63ULL, 
            0x481CF38701BAE3D1ULL, 0x3FBC1E59D8871A2DULL, 0x159E160D94B349CAULL, 0x40F6F6A40E08CEC2ULL, 
            0x104C7E63A83F94BCULL, 0xA98CA86A9C60A622ULL, 0x59AD17910BFF20C3ULL, 0x831949A9E37D63AFULL
        },
        {
            0xDB307131F39953A6ULL, 0x8E4FB9698230ABC3ULL, 0x52CCFDF860B6ADAAULL, 0x7875FF974E3A1B2BULL, 
            0x45074D838D72BB61ULL, 0x3C985E3DCA17EBE4ULL, 0xA1B19EC18E2E3729ULL, 0x12E21124933115A4ULL, 
            0x5560B720A66FB1E2ULL, 0xB70E8F3C30B13A5AULL, 0xBD8048C279187CF9ULL, 0xEA02A277B45740B8ULL, 
            0x92B0F31D62C8F413ULL, 0xB48348CED7DE5A6BULL, 0x3D046655A2D557F8ULL, 0xF8F9E32CA2F263BDULL, 
            0xE43005933C612762ULL, 0x3E5D374757FC3855ULL, 0xBB0178676FEFB177ULL, 0x105AA42EBA0CDEE1ULL, 
            0x3DE9FE2F05FB7322ULL, 0xF918C314D30EF10BULL, 0x37828AC036366C9EULL, 0x349B098F8C2B9E8BULL, 
            0x95B5372C76610A27ULL, 0xE765B43D12C38E38ULL, 0xA735938F87C666A4ULL, 0x92EF8DD3B0B7D5C9ULL, 
            0xAD425D545EC84A82ULL, 0xA4EF0001562D074BULL, 0x17630981A84499EFULL, 0x71A99058AE3F20A4ULL
        },
        {
            0x36B90005C7044355ULL, 0x0CE22ABA2CE713B0ULL, 0x9D91F00053B3F02DULL, 0xDCB4FAFE490B0FE5ULL, 
            0x686B42D2D1BE4324ULL, 0x2A842102DAF1277BULL, 0x0FD8421DF7EA44D3ULL, 0x0274B8660F9D03E3ULL, 
            0xB5756542E9E84968ULL, 0x47D76A62348F21CEULL, 0xE6EBA57E680BB15CULL, 0xF9638EE31824F953ULL, 
            0x09DA5FEF0EC4F312ULL, 0x1C1B83B3F6873B9EULL, 0x74A43A769AAAF479ULL, 0x1E883047B32868F6ULL, 
            0x2E557E3745C312F4ULL, 0xFBBC186C0B3E41E2ULL, 0x16A8F8E7C6E66401ULL, 0x8BFD45283085B79AULL, 
            0x56DA120EBB7DE0FDULL, 0x7458D92CC8E356C6ULL, 0xE7D0E4636F51D018ULL, 0xCA9C00E5E73F0A75ULL, 
            0xFD1AB0E8C0068530ULL, 0xD662D8C8AF7ABF1DULL, 0xED0526391477B2C6ULL, 0x8A119AF37A82878CULL, 
            0x6F732DC69E72DEEDULL, 0x0D21D2FAD6F94AD3ULL, 0xE0D55C2B38276D8AULL, 0xE247242309B2E9F2ULL
        }
    },
    {
        {
            0xEE1A9BC859D177BBULL, 0x0712AF11C9E87170ULL, 0x733D7DD8356158BFULL, 0xC434F5FCC7ABB38EULL, 
            0xAB5F6725EE4652CCULL, 0xC6DD1B58E7B2AE5EULL, 0x67D9197BF7475AC2ULL, 0xA362332F53F48B44ULL, 
            0xC22411BB5A02DB49ULL, 0x3F7EB91347AC9F0BULL, 0x307A39EDBFCBBC99ULL, 0x9A3A49B862E6ED81ULL, 
            0x2F661B9C4BEFA2B1ULL, 0x4CCBEACF35EC01FAULL, 0xCF7C9AFA74A0C6CCULL, 0x6D62529B610BF07FULL, 
            0x7E0DE64A152804DDULL, 0xA4EAF8D96A237413ULL, 0xD67BAF118AD7FC9CULL, 0xC1808D3DCD7021A6ULL, 
            0xC82B008184FB8C7BULL, 0xC5AC66F25EB31DE1ULL, 0xC432E80956634CFFULL, 0x0BF51D1765372FE2ULL, 
            0x6BC8C799FEB77E28ULL, 0xBF501CD72AA79BF9ULL, 0x3A1BCAF310D712DBULL, 0xF20DD59A1EAAB21BULL, 
            0xBD1AD3208AF8AC35ULL, 0x08BD8F33653F24F6ULL, 0xB484C897C94141EAULL, 0x95F11F0780102DF7ULL
        },
        {
            0x2C39D662780E4D0FULL, 0xAD6F9ED7747E5EF1ULL, 0x2A6FC677E69230E7ULL, 0x297C93896E508CADULL, 
            0xE5CBE7D0BEA094E9ULL, 0xA19B3738A2FADA5AULL, 0xEF1FD0297EA590AFULL, 0x8BB4C3EA27DE0202ULL, 
            0x1D150C0AF9D2C3AEULL, 0xD19D8276EAADC193ULL, 0xA2122F4A97FA054CULL, 0x276A9826E0E58078ULL, 
            0x58561A20840C4AE1ULL, 0x0C44EC7FB985AD95ULL, 0xB4E7C2E360DFFC0EULL, 0xABE39EF2F9E04886ULL, 
            0x658ED71BE066F8C8ULL, 0xED3415EAE4251CC5ULL, 0x6D739B36F345C9C3ULL, 0xB70B56B75FF431ABULL, 
            0xEE7F7B2179A69BFCULL, 0xD015D9A49320C88DULL, 0xF3E1D487CEDC0FAAULL, 0xAD3279904432B3DAULL, 
            0xF8E12BB0AD188950ULL, 0xC6F10CAEF3331065ULL, 0x8EFFB9F9FCE48513ULL, 0x726390DFCA711D1EULL, 
            0x10792687F3C4C1BCULL, 0xED6E2D973594159BULL, 0xD9D6EAF1DEC85556ULL, 0x6CE40588DE6D1583ULL
        },
        {
            0x6C640EC87B539ED5ULL, 0x96344847F5FBEF99ULL, 0x2F43BD94C0505565ULL, 0xF8E720B705CCA78AULL, 
            0xB23D9485C397373FULL, 0x42912E45FCBC53A6ULL, 0x8A3CC109948EA1FDULL, 0x078B755D2F069996ULL, 
            0x04914131D6EBE430ULL, 0x4CC524447DD66D5AULL, 0xBA16A99640F7C530ULL, 0xD54131324E8BA03EULL, 
            0xDFA42583ECAA50DFULL, 0xADB2C4A265534347ULL, 0xB09244F85D431A20ULL, 0xA1A94D7AF7D7E94AULL, 
            0x5FC447E53411D16DULL, 0xA945B790933872F5ULL, 0x019D4207683498F5ULL, 0xE3C705CFDFEE0490ULL, 
            0x77B86BEED5E1C766ULL, 0x9B71DF1006093FE3ULL, 0x1F59A7E332C9F76BULL, 0x20E37853F75768BBULL, 
            0x831B96B5E1C8EBC4ULL, 0x7F0F8D4BE0701910ULL, 0x1187C646CCC53B05ULL, 0xC525AA6ECCF9271FULL, 
            0x86CDA7933171069DULL, 0xECEE472A64262B8DULL, 0xCD84B223CCFFAD81ULL, 0x198DB98889261A31ULL
        },
        {
            0xB03B1ACF72CAD0C6ULL, 0x5D5A9B35C063EBDAULL, 0xE24DA57231AFE950ULL, 0xC94348572E62D9D3ULL, 
            0x848E8459D9C3ACBDULL, 0xC70804D429F15FBEULL, 0x097D61BA2B578A2AULL, 0x310B27C092FF548CULL, 
            0x38F568C9FEA4AFD9ULL, 0x9C6FF96E1F8DC492ULL, 0x68D0007B1D97E70FULL, 0x2506AE7EE9EBCE87ULL, 
            0x59C6ED2A2BBA053BULL, 0xA74260F8EAC86D7BULL, 0xBA66321E86EA88FCULL, 0x98F69A438CA31422ULL, 
            0x016DC861C6CA62A2ULL, 0x80E2F9EADBC312B2ULL, 0x0688E5806DCEC124ULL, 0xCCD6C4F355A4238EULL, 
            0x840093AB223FC00DULL, 0x69709AE9B8F33A12ULL, 0xC5E208847418E54EULL, 0x4309876CB0089DF4ULL, 
            0x57F92F3AF58F371CULL, 0x67B06766B224E9B6ULL, 0x63CBC916D60CB38EULL, 0x05E083E554DE0EC3ULL, 
            0x960F766A0B2B070EULL, 0x9EF104C8DC6158E3ULL, 0x93DB20E3C96F0F6FULL, 0xC3924DD73859E6F0ULL
        },
        {
            0xFEA8978D93107B78ULL, 0x9C0E1704C331AAAAULL, 0x231F33FA167764AAULL, 0x3BBCAF326E4E177AULL, 
            0x36081C46FAB64EB4ULL, 0xFA82A1DC0965A9C4ULL, 0xCC9A03465FCEC316ULL, 0x2ACAFDB38B483EFEULL, 
            0x5FAEF5DEB284B7C0ULL, 0x2354D480E8D1F80EULL, 0x6EF1A99B8AC553F3ULL, 0xD0B9281DAFF711B2ULL, 
            0x351A42500DCA4608ULL, 0x680025BC228CEE97ULL, 0x1EB6CAF64800DD43ULL, 0xD51A2BA6B03B6999ULL, 
            0x0A173B0D0074465FULL, 0x024FE632C2C2D78BULL, 0x590BBFD9F5630D4AULL, 0x1450E96918F87183ULL, 
            0xBE3FA80DA84B2662ULL, 0xE73AEC18C7E7468FULL, 0x7C4426317D892149ULL, 0x97BC10B523A11D4FULL, 
            0xF8E9771F7438357BULL, 0x00E4D1E4BD454038ULL, 0x28C2F14B528E002EULL, 0x81C432B3EECF3D33ULL, 
            0x480CA420319D9F32ULL, 0xD06E0582B13C5A00ULL, 0xC0D1BB9AF362D636ULL, 0xE370E1BD8662E5F2ULL
        },
        {
            0x9938766B58B056E2ULL, 0x619522F97E9C78E1ULL, 0x38E5C1A097D31100ULL, 0x3695819D5FF35558ULL, 
            0xC8CA2FD37773D145ULL, 0x9A9D78DC0397710DULL, 0xF6474D74028D8500ULL, 0x917E726A9ABFC240ULL, 
            0x732799D0591B57BEULL, 0x5F8DA928E6FFF98DULL, 0x3199350239E60743ULL, 0x47149746DA488589ULL, 
            0xC4E47C9DFA21EC6FULL, 0x88B197F56AC3F4D1ULL, 0xEA6867B328ACDADDULL, 0x32918F2B497B3530ULL, 
            0xEC255CBE35416255ULL, 0x85E3C8942ECF5E27ULL, 0xE5166AF49056E099ULL, 0x6A633F303B0850D1ULL, 
            0xD9C407C9D05DC9F0ULL, 0xDD508A9AC00EAAEEULL, 0x20BCF6D2B2453D3CULL, 0x10C6166AE2A431F0ULL, 
            0x7F74921A7575DDA6ULL, 0x2EB4B91C4A21FC04ULL, 0xC08D287FF77D1476ULL, 0x196287BC68069119ULL, 
            0xF5BE86E2FC11576CULL, 0x05D98A9C45FA3487ULL, 0x2A5ECFA3AE02DCE4ULL, 0x6E923C0B5E7B02F4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseBConstants = {
    0x6F61179A07B973E7ULL,
    0xCD9C0A76331E3634ULL,
    0xC967B76B04CC1461ULL,
    0x6F61179A07B973E7ULL,
    0xCD9C0A76331E3634ULL,
    0xC967B76B04CC1461ULL,
    0x8887CFE380706723ULL,
    0x806A6932C4080700ULL,
    0xDB,
    0x53,
    0x85,
    0x38,
    0x46,
    0x70,
    0xD7,
    0x62
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseCSalts = {
    {
        {
            0x21FB9DF1AB216954ULL, 0x1463C2C50002C4D9ULL, 0xCD72A77979472238ULL, 0x8F489D37C8513DFDULL, 
            0xFB29A3249A394D26ULL, 0x09C28B0EF3D0520BULL, 0x9400EE84BDCE0B21ULL, 0x51921F89374E8F85ULL, 
            0x7E8933A67E758C0CULL, 0x9B0734BE65D23B83ULL, 0xA24CE22B0C916261ULL, 0x223EB2BF9EE63438ULL, 
            0xF5E3557B4CA60BD3ULL, 0xB6855F017A18E831ULL, 0x80D7209FC956BB07ULL, 0x1434FD8804D46F7DULL, 
            0x0F31E21C3D7BC004ULL, 0xF3DACBE6C8830C42ULL, 0x74369E54675815CCULL, 0xE68BF5C072537A43ULL, 
            0xC30A58DBB997F768ULL, 0xFB621F6AF975881BULL, 0xB82209DD296FF27DULL, 0xA2705B9971B85108ULL, 
            0xD97EDC723618004EULL, 0xC2AFC23994626957ULL, 0xE3CAB14C41977898ULL, 0x07713535BA76FF1FULL, 
            0xBAD60641192CC073ULL, 0xF9F36FC5CE4E55FEULL, 0x4EF2145FCE923736ULL, 0x901CEB4011028188ULL
        },
        {
            0x1B543A7327D4C266ULL, 0xD55DF7D14A09B16AULL, 0x0B919F0CC09C1638ULL, 0x0374D99132C70326ULL, 
            0x818D8AD70F291166ULL, 0x50057F7982CCF8C1ULL, 0x52047ED4285BFC2FULL, 0x2E9168DEAAAB6BB9ULL, 
            0xBEAEE71D3E52D0C3ULL, 0x70B0A6D9C3916B55ULL, 0x3BBE1DF10EBC7D4DULL, 0xD2DE8FCC3051B93AULL, 
            0xD748CEC4BE46A139ULL, 0xC65D40EBAAA60E48ULL, 0x03E3488487810854ULL, 0xB1CA9D06E876A38DULL, 
            0x42B8763C64511DA2ULL, 0x63BDAACD73CAC525ULL, 0x68AFF928A977041AULL, 0x9C285EAC8A093130ULL, 
            0x4BF76B855C864A31ULL, 0x0486A9FA1A0042F8ULL, 0x075D55B745C7CBE1ULL, 0x4A977166FC7802B8ULL, 
            0x2092C7B2DF68BA19ULL, 0x5D8AFA56B1AAEBB0ULL, 0x488379ED8A1AC9F4ULL, 0xC6F6F4DA991EEF94ULL, 
            0x4698777116AA74CCULL, 0xE5EE20F5B15D0685ULL, 0xE4155CFD12D5A65BULL, 0x3FEA2ED55180C6AAULL
        },
        {
            0x6291B0FDE91719E2ULL, 0x6207F1DFCAF044F6ULL, 0x9E0E709499D1C320ULL, 0x092AFB0B54F84195ULL, 
            0x386D0496E3A44EA2ULL, 0xB9D0AAE2A209FD46ULL, 0x5EE527A00A2BA281ULL, 0x7903884303EF79B4ULL, 
            0xD854E48CFFF0131EULL, 0x030F36EA411AA826ULL, 0x7F01FD4DF858D52FULL, 0xD9CB15827F4ACEB2ULL, 
            0xD576287AE5EDB1E0ULL, 0x8E35848F8D91013BULL, 0x1543F21C0C9E2212ULL, 0x8336AD1B2E7DA795ULL, 
            0x8B732E79E0A7212AULL, 0x40B393411D241856ULL, 0x395B66F44D4A75AFULL, 0xEC70F2156C48A58DULL, 
            0x713A066011AC7A6CULL, 0xECAE967815BB4587ULL, 0xFBFEC0BA0204DFACULL, 0x6497B52E3D9EECEBULL, 
            0x40062A355C54BF90ULL, 0xE67731B77971BFCBULL, 0x4E66A62FEB6A8E81ULL, 0x6461CC9E8E8B7AE9ULL, 
            0x790F13B50334BACDULL, 0x1F831B8817A80823ULL, 0x89EA56F91EA02774ULL, 0x17FF4BD90BE04374ULL
        },
        {
            0xF6E23C4E1B97D749ULL, 0xCE03C2DD1E72E44AULL, 0xBA64AF138DAE6B53ULL, 0xCAD1C01F820DCFACULL, 
            0xE4393608AD182555ULL, 0xA417243D905F3BECULL, 0xE7F5F626575363D5ULL, 0xA6F0D8431DE0F3F6ULL, 
            0xDA1591581AF51826ULL, 0x21828D3A58C1C426ULL, 0x1699EC59F14787B8ULL, 0x1DA8DE63D5EC8364ULL, 
            0xA33AE733B4A83732ULL, 0x9DCA0F6FE6852F95ULL, 0x7D373383F676C816ULL, 0xBF900DEEFCBE65BCULL, 
            0xA992715789916AF5ULL, 0x379FA961A0817E55ULL, 0xB6B40CB175BD769CULL, 0xE357B9ED1C629F3EULL, 
            0x2E2A7F9C97F4E49FULL, 0xB7A5FA3DBCB91786ULL, 0x46FC352048D3BC7FULL, 0xE7358A97F5D8FEB2ULL, 
            0x56C01A1B719B874CULL, 0x7AB03CFF4FE45632ULL, 0x7593C820B5E79CE1ULL, 0xCC134EC4A5002C87ULL, 
            0xC3914445EB829595ULL, 0x7568D510FEBD08B8ULL, 0xCCD2E150F0CF0456ULL, 0x79E23467725DD765ULL
        },
        {
            0x2A54199DBF8EC58AULL, 0xF262C4A65ED1AAC9ULL, 0x0B0D0EC440DCEDD9ULL, 0xD2842684341C2A09ULL, 
            0x554220C0AAAE3059ULL, 0x9143D4C4AC2F6DA1ULL, 0xE4AF9846D1ED9A31ULL, 0x53AFFF1A824D01E6ULL, 
            0x15B82700426F7B9FULL, 0x7C9A9F0628C101EEULL, 0xB5BE81E76C40C4A7ULL, 0xE31FD0E8FB61FD1DULL, 
            0x220CF25FEA5F8F70ULL, 0xC8D74C3B43356F2FULL, 0xA77ACA7AD4AEFD90ULL, 0x28503F8AA5E52D7FULL, 
            0x3FC4DA83DCA09443ULL, 0x4FF701A5078EF1F9ULL, 0x599910E0B6129306ULL, 0xABB3D1B7266194C2ULL, 
            0xA77CABBE559FDC58ULL, 0xEC9A850C344E60EEULL, 0x71A3053ACD8AF1BFULL, 0xBAD5DB639B4616F5ULL, 
            0x8F87FF0B24D631D8ULL, 0x9B007A896DE7E985ULL, 0x21CAC261DDF18FC4ULL, 0x77270B451D27CF15ULL, 
            0xC24B28D1A1655705ULL, 0x12B5755394C819A5ULL, 0xFC3BF897E93CEF88ULL, 0xF7C039F08592CE23ULL
        },
        {
            0x50618340497E6509ULL, 0x77804F3603EB858BULL, 0xD1DBFD919181B5E3ULL, 0x6EEA3194A8890DC8ULL, 
            0x833610195C2F2A3FULL, 0xEA62BFE7EF530B49ULL, 0x38073BDE736B5520ULL, 0x826F6F6AC4110D34ULL, 
            0x4A9158419510A430ULL, 0x31A9C25528453A06ULL, 0x6AEC692B13E30A99ULL, 0x918949A771E25824ULL, 
            0x6A9E16A3DE8250BDULL, 0xFA76F650F9DCF27EULL, 0xBE3DD1BEEED07FC6ULL, 0xF9E14C8DF4827362ULL, 
            0xDD65E06DAB1B268AULL, 0xAF037AE772216BD4ULL, 0x5EBC3AE59C384869ULL, 0xAA084180C92E8291ULL, 
            0xBB6BBC3E4DE301F6ULL, 0xE511F7197465F6BCULL, 0x622907120DD37A02ULL, 0x3C9BE2EDE2858DAFULL, 
            0x2CAD0DCBE771C053ULL, 0x9C144E1B638D5FC2ULL, 0xF229670ECC1C15DDULL, 0xA2214F95CFFDCE76ULL, 
            0x198F6392B0A71B74ULL, 0x714C84C58B061FB3ULL, 0xCDB836E69159B503ULL, 0x8D0B9E118CA0B7EFULL
        }
    },
    {
        {
            0x86B27A47EA67FCECULL, 0x784A119A46D2F292ULL, 0x50C3151DC29928D7ULL, 0x1AB0E4914EA905B3ULL, 
            0xCA3F77E95B266F03ULL, 0xED6DCB0ED85D2BC7ULL, 0xF88FAC1F9BB5A468ULL, 0xCD57EFC64B4D25C8ULL, 
            0x55720672020FA2CDULL, 0xDEE568A43AAD2664ULL, 0x8ACCD9B7E3CE3926ULL, 0x7C5F47F621CB6B09ULL, 
            0xC84E66E17D25D0CDULL, 0x1F1B5B0FEADD47F9ULL, 0x46555497410BCF53ULL, 0x417D8E5368DD3FE1ULL, 
            0x7B3889CD660E451BULL, 0xFAA4A2A74E42081CULL, 0xA41B9987D203C239ULL, 0xC008BDB105BBA5F3ULL, 
            0x1674D546E32EF8E8ULL, 0x34180504081121B9ULL, 0x7FCA1E32C6655705ULL, 0x79F3BF58BA722E65ULL, 
            0xE10A39A55EE54749ULL, 0x333CE0DF38900F2BULL, 0xD2C7370156CE274DULL, 0xE2767A9528623EF7ULL, 
            0xC82F7D3E2B6EB292ULL, 0xDC718751D299FDBCULL, 0x72E4D91859903544ULL, 0x92502437B47A84EBULL
        },
        {
            0x7A94E1F334E43D99ULL, 0xFC3663519C7203C9ULL, 0xB9351C36D6E4E96BULL, 0xEA45C71A2F3B8006ULL, 
            0xD36C6AEFD19C8C0AULL, 0xA933E7AB408D8A95ULL, 0xBFC8D1E8A09B0EE8ULL, 0xEC8633C3521FCBE6ULL, 
            0x89EF18FD25EA849BULL, 0x8EA696692A5E4BDFULL, 0x3771E64AC95943F2ULL, 0x956E5011170A2BABULL, 
            0x124DA7531A17E589ULL, 0xF55635BB3BE48E79ULL, 0x13134B2F21A13EAFULL, 0x653052067F4818CCULL, 
            0x1C277A174DCF3FDEULL, 0x05A28790D9DBBF9EULL, 0x264AA80A1E689FA4ULL, 0x92EA99B999CBBE79ULL, 
            0x55A70CEE2E5EB49AULL, 0x9C65C439A3DEF08CULL, 0x5905065C5F3BC0A3ULL, 0x720D961E7FFEB276ULL, 
            0x597C52C8AF17AB35ULL, 0x9089524B8AEC2B98ULL, 0x118EF49866EC38E4ULL, 0xE944ECF8292C584AULL, 
            0x3EBA4B01C7A08CD9ULL, 0xAEE22494ACFAA56AULL, 0x94914A44F0D5A4E1ULL, 0x6CC05E82C44D3E22ULL
        },
        {
            0xC650467BCDF17E6EULL, 0x5087E620E914A6E6ULL, 0x0981F5E060ACCD9AULL, 0xD87249511473DBFAULL, 
            0x6EF2CAE03ED3CC17ULL, 0x40D9A322F6DA21E9ULL, 0xF32B27E07B841115ULL, 0x51EBF2274997C9F4ULL, 
            0xCD31574886EA4794ULL, 0x99C2482AFA5D1DCEULL, 0xCF160F9F897EFCFDULL, 0x2BE9A44419A188AAULL, 
            0xC78869ACA373F59CULL, 0xB5AF046C4F89B132ULL, 0xA89A9AFB241ED9E1ULL, 0xBD496B1AA8139F94ULL, 
            0xCF42AB0C86D15284ULL, 0xB51E0FFF8BEFBE3DULL, 0xBF6AB76A766A0327ULL, 0x6369B84DD2C0CB12ULL, 
            0x20E4BBF95A6B7F97ULL, 0x21F03701BF3AB0CDULL, 0xA240445E18BB82D8ULL, 0x1888BB4111CA07BBULL, 
            0xDE0D7494B19684C8ULL, 0x906604B10C8435DDULL, 0x6C2C5C222F1F2212ULL, 0x248821CC6FBCCB15ULL, 
            0xDD76966C6CF5FAA6ULL, 0x872EDE2136710BD8ULL, 0x361F9D8ED785369AULL, 0xF239576CE8D172F7ULL
        },
        {
            0x5C2A9C0537C776C4ULL, 0x88978BCB5EC8010DULL, 0x725B881467059DACULL, 0xA1C588826F09F5D5ULL, 
            0x3839E8AB65BCD7CFULL, 0xD216C263432DECA0ULL, 0x5BE8EEEDC1DE1683ULL, 0xF8E221B91A24C26FULL, 
            0x6EFC3C1FB1264375ULL, 0x5FFCE212FCD7A219ULL, 0x2C54D6B97A0F40D4ULL, 0x7E8B79C65F0FA126ULL, 
            0x361165D339AFECC5ULL, 0x65DF784403AC9817ULL, 0x2CCDB1F5325E9FDAULL, 0xF3CA8AD9F95FE6BAULL, 
            0x2432274A4A04A5A8ULL, 0x863ABC50E63AC82FULL, 0x9C67EA61233ACDB7ULL, 0xBA105EDDCD5E1DA0ULL, 
            0xE4A0204814CFE480ULL, 0x4551364690BE2B20ULL, 0x44F3DD31D521FA4EULL, 0xD59A9604DF0B3A5BULL, 
            0xC4A0C181A0AEFD89ULL, 0xEF0F8AC4F2A2D0E7ULL, 0x7F3E1A1700027A6DULL, 0xCF26623D67A0875DULL, 
            0x3A16CE92D2895628ULL, 0xF6555B5451F7B9F2ULL, 0xEBDBF7C3E90004C1ULL, 0xCD93AEC69BDA7CF3ULL
        },
        {
            0x63EB561517F2D471ULL, 0xAC076DF3192E0139ULL, 0x981EC9F14824BFD7ULL, 0x50382FE32128B394ULL, 
            0xF7D20B87C6FD2081ULL, 0x06C754BA00550988ULL, 0xAF67A6888E232C74ULL, 0x5BF56E50945DDC57ULL, 
            0x58FA42579480768EULL, 0x79B47A0CA1D08856ULL, 0x3597430BB4B89658ULL, 0xCBA6905B6BDDBB62ULL, 
            0x5109FCE8B7125480ULL, 0x98C8072E73C07671ULL, 0x3788500893E56EA2ULL, 0x77EAE615CB00B566ULL, 
            0xBBACE35E2497C13DULL, 0xFD6762CBC8924D6DULL, 0x05BC6785FB03F9A1ULL, 0x5A0DA08727EF41B6ULL, 
            0xF98DB27BA888D987ULL, 0x9D0ECA94AFAD0D7CULL, 0xD0F0B9281F1F560DULL, 0xB5D7815882E88630ULL, 
            0xFCB9AA04F55C5DEDULL, 0x0A3427B75A2E1D42ULL, 0xCADF191E3259B73AULL, 0x945BC7368E1AA449ULL, 
            0x2243F5C8FAB2B225ULL, 0xB72121E2AB8992D6ULL, 0x975DE0D77FB010CBULL, 0x993B627B4508433CULL
        },
        {
            0x99651132C78ABFDBULL, 0x9661746D585D83FFULL, 0x303846FD55AAA89CULL, 0x7D8705734D2D6FE9ULL, 
            0x06C9D0A677891416ULL, 0x7294AA5E8CA0CB96ULL, 0x6EA0D744439D5E01ULL, 0xAB30279B414FF876ULL, 
            0x86553621EB753CCEULL, 0xD28567B8530882C0ULL, 0xA8BE8B1FF2F800C1ULL, 0xC6766A9FD2F0A8EFULL, 
            0x64F9AE720D2F4661ULL, 0xA7B24F63E9613590ULL, 0xC8CFC72F254E4E0CULL, 0x83EC469645E9CC76ULL, 
            0x269A2105D4255C2CULL, 0x1DAF68F7C6A067E9ULL, 0x3BAA1AFC3E20E387ULL, 0x053ABFB6D5FAE93AULL, 
            0x2B10C61627760E1FULL, 0x4A74835F9FD77583ULL, 0x96306ABF5049104FULL, 0x47DDE9AECB3283A3ULL, 
            0x750125370D7F0568ULL, 0x46A62FFBCBC109DCULL, 0x496BB67AC421DEBBULL, 0x61221657329066FDULL, 
            0x8C47087EB2F36224ULL, 0x1EEED94480D13966ULL, 0xE72235C57929F5B4ULL, 0xE1AB335AF84694A4ULL
        }
    },
    {
        {
            0x38879A7899275635ULL, 0xAA66F9E74AF98F1DULL, 0x68683C4AC7FC5AA0ULL, 0x88EC3DD1218C072FULL, 
            0xD0181C1D7713D2AAULL, 0x4CA36DEDE5EDA4B7ULL, 0x21494CFE2650A2D9ULL, 0xC046CCEE9E7A037DULL, 
            0xAD5C93C1BBADF360ULL, 0x95BB6D073603BC13ULL, 0xA45302AE38110BA8ULL, 0x8283C8FDECB23E58ULL, 
            0x71A52EF180E450E2ULL, 0x398EAE9ABE5ABD40ULL, 0x43D9BD906618BDDCULL, 0x7C3E603B9D5E5D5DULL, 
            0xE7FCAF390682449DULL, 0xB9FA6677544ADC31ULL, 0xFA0327F28B689DD9ULL, 0x4967575EE5FD5ACEULL, 
            0x0989A7E1BCA0E7AAULL, 0x9DBF0D3EE16C5BAFULL, 0x5D75575C5D2288A8ULL, 0xE80E2A2EE58F2AB9ULL, 
            0x2D521DBFD1131B3BULL, 0xE4E27F79A89E3B38ULL, 0x1FBE527219EE6F5CULL, 0x64A45F77F5AC6FEBULL, 
            0xB8DDAA966742D509ULL, 0xB86F4CDB9DA7E4D8ULL, 0x38E088268D833A1CULL, 0xD0E1488E7626F10CULL
        },
        {
            0xA502D2B033F2DE7BULL, 0xCB671768C2093931ULL, 0xEE296D9402BFD884ULL, 0x7A2CC18146D55B89ULL, 
            0x05C7288466D5153EULL, 0x10D71C7F4ADD8B6DULL, 0x0455961392181C09ULL, 0xE2BC00FCAB966F16ULL, 
            0x7E533D6B2DB4AEA7ULL, 0x696FF8EDB0099CACULL, 0x14F252C982A43BBFULL, 0xEB36A570546D6A84ULL, 
            0x6515AEEE5A86CE55ULL, 0x41DFE495A1A0A17EULL, 0x0EA95E1BDEA85CC1ULL, 0x2C8111A7A2D0C2E4ULL, 
            0xB94916DFED028B5AULL, 0x6B9BB45C3319EAD6ULL, 0x5FBFD53A55E20CAFULL, 0x1EE5DDF37E26814CULL, 
            0xCEEC185A0C808C17ULL, 0x2C9A67A10B54B3AFULL, 0x1ABD994BEEF33618ULL, 0xA4D3F50A8EDA8947ULL, 
            0xAA3325DE4DA18654ULL, 0x66473813C48F7262ULL, 0x6ED6B57E009396B1ULL, 0x9BF79EA0AEE2841FULL, 
            0x39F3FEFA9147B5CEULL, 0x4F3834F42C60C703ULL, 0x3C787F1AFD5901CAULL, 0x334CB1DE35CB85A4ULL
        },
        {
            0x16289F5583233049ULL, 0x798A4260F909BC2CULL, 0x33861B801F83D87EULL, 0x233C3E7F8BC82970ULL, 
            0xF2FB05B53412286CULL, 0xD4190A2A672E3D86ULL, 0x4033C48E056809F4ULL, 0xF37048FC69D2FEBCULL, 
            0xADB6BB98DC40D479ULL, 0xF36C62378AAC7EA9ULL, 0xD7AEE5732212A39AULL, 0xCEA9421D56344BBAULL, 
            0xB6E2DFD49D006A86ULL, 0x8640C15677BFCB23ULL, 0x2844F476F6A0D3E1ULL, 0xDF8D4A6E9680AE8CULL, 
            0xB37614607B18752AULL, 0xD63CA5C6C8A987E3ULL, 0x5F3BCE64816C165DULL, 0x465938D982EEF162ULL, 
            0x6943D1654FAA89B6ULL, 0x5A4499F15C30C5CCULL, 0x36A8B1499565617AULL, 0x8B29CE334D825B52ULL, 
            0x24D4FB054150BC01ULL, 0x198A8732080439FDULL, 0xE669F838E2CAFD9CULL, 0x8DC3299D331B003FULL, 
            0x73F513EF70336F7FULL, 0x1E5981B3D79CA9A4ULL, 0xE9F46C80F5047A2FULL, 0xD890F1874155D392ULL
        },
        {
            0x39E292C05820D369ULL, 0x19CEEBFC2464B9EEULL, 0xA7ED68CB73AFA17CULL, 0xF754C99CAF711DD9ULL, 
            0xE8DD25724E041098ULL, 0x710E227D290E33CAULL, 0x5A02E44F0AFDFAFDULL, 0x84051B9BA1BC8C8EULL, 
            0xDA86D4F80C0A9B44ULL, 0xDA6E4C17D165F556ULL, 0x55627F45C3307D7CULL, 0x6FC0BABA63042E7EULL, 
            0x1E6BB0CDAA6F6644ULL, 0xFFCE16E479CDD333ULL, 0x90B77EED99AB1837ULL, 0x461A04156B92D969ULL, 
            0x6495242DC9C4FAC7ULL, 0xB66E449B00431B3BULL, 0x0B16719AF0FAD906ULL, 0x005AF07AE13E5E8AULL, 
            0xE7DD59206592DF50ULL, 0x3047026CD0BF0B6FULL, 0xBABAFA9E37A991E8ULL, 0x40A9D0FF570394C8ULL, 
            0xB17B30B3A35104FBULL, 0xA969D6D271BC3D41ULL, 0x4BDE37F3561FDC14ULL, 0x803EE1D794F4C0ECULL, 
            0x5F4FF5F1804B9EC6ULL, 0xA0EFD4DB6C55B884ULL, 0x7A84A0110056CF84ULL, 0xAA5328729DADE38FULL
        },
        {
            0x2DB9415C83D11D00ULL, 0xC275108412733129ULL, 0x49B5D1355D798556ULL, 0x8A9A22BF0A3814B2ULL, 
            0x3006DD558AFA238EULL, 0x0826CE1CEC048C48ULL, 0x21ECC2AD92A67724ULL, 0xEB8E2B662F2EC74DULL, 
            0x031AE1C96E186456ULL, 0xCBD78E27772BD895ULL, 0x26809959741C845AULL, 0x992DD3B858B708E7ULL, 
            0xE612E509FBB43DB3ULL, 0x1024A405116F067AULL, 0x693DB3D9C811229CULL, 0x32543461DA0C17F0ULL, 
            0x5835EAF5CBCEC1BAULL, 0xF3E60CAC406DB839ULL, 0xE5400520ED252E23ULL, 0xDC49D250648EEB2FULL, 
            0x8C08C1FD7F606D27ULL, 0x096CB65740475D84ULL, 0x39E65CBE66B12EEFULL, 0x51361DF63436806CULL, 
            0x9C6DAED37E8D17DEULL, 0x42693A1DB8C047E7ULL, 0xF9EF9CE09B31ADAFULL, 0x0F4E51DA5BF4146DULL, 
            0x42B2B453D7A8DDB5ULL, 0xF03626037B680CAEULL, 0xE3C00366FE408748ULL, 0x04B348E76270E765ULL
        },
        {
            0x143062B88986DAD2ULL, 0x21EAF8CFB9E04431ULL, 0xCCF6402ABEB02197ULL, 0x914B9417FB0B82ADULL, 
            0x07C51F35128143B4ULL, 0x1481C8CFDBA3E5F2ULL, 0x83EFF39342D2A223ULL, 0x20E727969E22E07CULL, 
            0x606443ECDF15FFDEULL, 0x0D2FBEEF5BE66D36ULL, 0x717288491F332D91ULL, 0xD1353DE40F32DFDFULL, 
            0x172304E2A2E0C8F8ULL, 0x7602A00E29250873ULL, 0x0DDE6583447C8F33ULL, 0x1540960EBDB200F1ULL, 
            0x9FF265D913C6B822ULL, 0xB235C73712B5DFA2ULL, 0x87A8C0905AB0F7FEULL, 0xFD34A70B87981CF0ULL, 
            0x803A6B4F564A1AD1ULL, 0xAC20B9FEEE75A56EULL, 0x0300E08290C1894DULL, 0x474B03B486EFC81BULL, 
            0xB832434EDFDB146DULL, 0x270316D3C915A989ULL, 0x4B8BEF0A9849DEB4ULL, 0x82C3104002295979ULL, 
            0x30E21B5340C4EF28ULL, 0x2F2D065CE440853FULL, 0x359799C8C954D921ULL, 0x68D6E920D29029D3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseCConstants = {
    0x64AF9511F2700829ULL,
    0xDE783B960795920BULL,
    0x338A7A4B6DE48994ULL,
    0x64AF9511F2700829ULL,
    0xDE783B960795920BULL,
    0x338A7A4B6DE48994ULL,
    0x957D13A147E99F4FULL,
    0x15FACC0FFF243D7CULL,
    0xFA,
    0x7F,
    0x1F,
    0x03,
    0x7F,
    0xC2,
    0xE5,
    0x6E
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseDSalts = {
    {
        {
            0x14B17BBD3DBDCC06ULL, 0x2F7C774D5722B649ULL, 0x676961DFECB526AFULL, 0xC10477985B6A786FULL, 
            0xC7DDA72726C95BECULL, 0xEFE4E87419417938ULL, 0xF6A751D92A442EE0ULL, 0x286E96AB2EA7C24CULL, 
            0x709E56CD81D96EB5ULL, 0x953E4014B309AB2CULL, 0x295A8673DE156678ULL, 0xD6486D12BCC7EAE5ULL, 
            0x07DFF548CAE57BF1ULL, 0xB64C5156354AC869ULL, 0x4467AF31683FC298ULL, 0x9ABE624C4E6C45E7ULL, 
            0xA4E4F49C810F58ABULL, 0xE111221AA6845E57ULL, 0x21DACCF07EEAD556ULL, 0x7CAB2C6BC782B3A3ULL, 
            0x5D5E256F8D3983F1ULL, 0x4D92068F57411B07ULL, 0xEB229FB41863ED67ULL, 0x5AADACBF8B62EFDEULL, 
            0xC28D01D1B3A6E544ULL, 0x1F1D1E1E570E49DBULL, 0x4C3884F503B7DA39ULL, 0xDA18AC7BF3EE750BULL, 
            0x261406D0CDBE4FF7ULL, 0xE55CC292429785BDULL, 0xF6CB5DB0E12DA111ULL, 0x5E19A2C39A66FE07ULL
        },
        {
            0x6121C173F21A21B6ULL, 0x50E960549285A068ULL, 0x827C395B9EF5EFA6ULL, 0xDC3C4B9BF75F1970ULL, 
            0x1355710BCB4A037AULL, 0x375601F57528E8AEULL, 0x63D321D2C4256E82ULL, 0xC8E242845D05BB1EULL, 
            0xA6AC25C166F32AF8ULL, 0x57B2BD915D4BCC36ULL, 0x70554BDFC8CF198DULL, 0x28CB60D7869536F0ULL, 
            0x9824A6E868921DF2ULL, 0x7ECE10C7695CB72AULL, 0x75C60439CAE76DA0ULL, 0xC324C10F05BFC40DULL, 
            0xE6075FD1790E71C4ULL, 0x916336EF3FB623C2ULL, 0x524EBDC101851732ULL, 0x8052BE98A028C243ULL, 
            0x6FB0E81E566CB766ULL, 0xEED1929503EE91E3ULL, 0xA980E7D2C07E9DBCULL, 0xB8DFDD86AC259979ULL, 
            0x0507A23EC2D3CC5DULL, 0xFEFC5BA09FFE5D30ULL, 0x0C0FDA4C26E1411EULL, 0x5C1A2F29796A5F6FULL, 
            0x6B9D183C85402749ULL, 0x0D93804BBF4B5646ULL, 0xCF8B565C1735B05AULL, 0xE0B2E0ED9DA4B736ULL
        },
        {
            0x9EC5523884542037ULL, 0x958DDE5043F66369ULL, 0x4085E2762BBD0B67ULL, 0x3ABAF46A5395C924ULL, 
            0x59AB40BAE4CCA3B5ULL, 0x8529FE2900AC1259ULL, 0xFF8762D962C09BD9ULL, 0x643B9CADF0A7616FULL, 
            0x44D53317043EF603ULL, 0xDD1310368E7A2C19ULL, 0xBA99FCFFB8D8D5F8ULL, 0x83B05DA295033D78ULL, 
            0x3B3F8B57171C2C94ULL, 0x639C3FC0371E91C3ULL, 0x341CDA1E21CD22B6ULL, 0xF043F8EF7738F359ULL, 
            0x65F6B2A7AB163A98ULL, 0xE57F7CFE7D053694ULL, 0x76BF0209CF6DB244ULL, 0x76F21FB919594B0FULL, 
            0xBBA58B8BB4FAB48BULL, 0xC8EB31E9422C95ACULL, 0x5AF90FD1CB08080CULL, 0x4FC06331AFF8545DULL, 
            0x45C77F78A58D1382ULL, 0x9BEB9B9E6D1B6811ULL, 0x4EDD6C0549FB6159ULL, 0x2BBA21B89185DD5DULL, 
            0x50C4F26C2CABFEDBULL, 0x7B6B02E8AB446C36ULL, 0xC126E91542E315C8ULL, 0xDE3D0B9529F21413ULL
        },
        {
            0x47AE8EE6D8A3F9FCULL, 0xF1ED0CEB5E82E129ULL, 0xE3265136B90A1A77ULL, 0x3C79EA18B2D36FDDULL, 
            0x098530B335BA7142ULL, 0x966AA18F9C9B4E26ULL, 0x067D07C6790C8485ULL, 0xE032CAD53AACA83BULL, 
            0xBF9E8E63D4CFFDB4ULL, 0x8A4C4C1C5441F3EFULL, 0xB1160A86727A0EBDULL, 0xA3A6BFD629DFD89EULL, 
            0xF41B7192019EDABBULL, 0xA85328BD9100F02DULL, 0x59062B4D77A8FFA4ULL, 0x6ACD6F92EF266BE3ULL, 
            0xB04F918176E675D6ULL, 0x5880814F751BF774ULL, 0x9BA6286925974CCFULL, 0x5735BC190DC5E486ULL, 
            0xC567B53628B64135ULL, 0x7C04170834ABA650ULL, 0x3782C2AD61337855ULL, 0xD509B6E846EF8348ULL, 
            0xF9DFE4243D67A1D6ULL, 0x1BD9C3A97875E340ULL, 0x5973ACCD1668A07AULL, 0x527C3AE38536D74AULL, 
            0xAFD353783610093CULL, 0xE11D44EBCC397BF0ULL, 0x93948C73E367D828ULL, 0x7BB58B68C29AAA7EULL
        },
        {
            0xC4B6F631A01AED9FULL, 0x6817646C488AD724ULL, 0x1AD5B08118BE7682ULL, 0x1841700BCF682E90ULL, 
            0xDA491D88DB9B4940ULL, 0xF7F84ABF019D1ED4ULL, 0xD8F181E94F5CBB7EULL, 0xC14FAFF26767BD3FULL, 
            0x87A62B4578A08554ULL, 0xA6CA5A2A9D01D1DBULL, 0x50403D12EAA3C7E8ULL, 0x7441084386A12D05ULL, 
            0x4C229B8226E9FB80ULL, 0x8A116E022CF7E9F8ULL, 0x5746BC02ADB08C18ULL, 0x3CA8757FB3C071C1ULL, 
            0xA18408A9419A9533ULL, 0xB442CB879A330C26ULL, 0x3D8E0163C855DC0EULL, 0x477CE7376A420925ULL, 
            0xA4E197E1B7663F62ULL, 0xA59264326D4561E0ULL, 0xD4CB9EE26B4E85F7ULL, 0xFCAC597C7085277DULL, 
            0x686C5D7FFD7B07BEULL, 0x8DD71708BC62A108ULL, 0x457F68A38328F4D9ULL, 0x15FEB8A5509785CEULL, 
            0xB0F7D6227773770FULL, 0xD6EBAD2D615D562EULL, 0x0FC6ECB0EC28D6B6ULL, 0x2E73DFC0044C489AULL
        },
        {
            0x109CE8B7B94452CAULL, 0xE59FB6DBDA7F10EDULL, 0xF0AFF30934F18C2AULL, 0x0971C8D832001E2CULL, 
            0x638E3F1B60249CB5ULL, 0xF41397E9C1753BCDULL, 0x563A0C22D4AC7915ULL, 0x0C55DDD2BC58DCC5ULL, 
            0x2DDCFC929F5D8956ULL, 0xFD0C4C01DAF48ECCULL, 0xEA339975398BFDC7ULL, 0x8177AC93B29E95C4ULL, 
            0x6EF858EC93F1E722ULL, 0x49572D9CC4F4061CULL, 0x9F611891119D08CCULL, 0x04D1F8F9A1667A76ULL, 
            0xC81365725254389BULL, 0xB579573BAC75A0E4ULL, 0x3A134D112EBF4486ULL, 0xF9EE9C540FC0A9C6ULL, 
            0x68850E7EB1AF8F09ULL, 0xB60F9CB3F6DCE9B3ULL, 0x6CC76D468E31B6E6ULL, 0x8D119FACC7D1C018ULL, 
            0x2E225A2F553F213DULL, 0x0088CD32E46E183BULL, 0xDC4866CB91991289ULL, 0x6B8C265FCF51AADAULL, 
            0xAF624CC34FACDDB2ULL, 0xEFF09D37EE60B293ULL, 0x539F0FFAF064E3C9ULL, 0xE7AE54623A38467DULL
        }
    },
    {
        {
            0xE6BE659CC210043DULL, 0x4BF964420F41EF74ULL, 0x571EB53A6563F7EEULL, 0x5DDD16B278FD99FEULL, 
            0x6C59F93239B0D3CAULL, 0x268B40E521763B41ULL, 0x51B3FF7E2E543056ULL, 0xE94223B559116FF4ULL, 
            0x6360192ADDC5F0CFULL, 0x81A7AE758D69A581ULL, 0x191ED2DF4E317E69ULL, 0x6AB158B892A0E725ULL, 
            0x02F0D97A29203ECCULL, 0xECC3267B97484BB7ULL, 0x96650BA5FA525B9CULL, 0x2DE91B5AAC5D9A5CULL, 
            0x77A920ADBDA60143ULL, 0x474661446A47961AULL, 0x4537F1350F61047CULL, 0xD0A54C40EE427908ULL, 
            0xAD3667ABE44E52EAULL, 0x5A876D2098983F03ULL, 0xEBB3537A6DBE93CBULL, 0xC10FE89585D57798ULL, 
            0xC3E70511DE8856C7ULL, 0xFC6F5F4AB5F4D509ULL, 0xFF80CEEA08F621A0ULL, 0xE6D73C98C75A503AULL, 
            0xA6218E094D8CE181ULL, 0x556BAF7CB68C79DAULL, 0xD2F68E8704724D80ULL, 0xAF1F86831095A540ULL
        },
        {
            0xB4597077A5887FC5ULL, 0x964C14A82D1F0B11ULL, 0x4AB4FDA4D90A1468ULL, 0x6B7FAA512CF36732ULL, 
            0xB37F60AB25B561F7ULL, 0x220E9F8B0D50DCF6ULL, 0xAC4B79E28CE4A9C0ULL, 0x256CFE8B634E2401ULL, 
            0xA735F32E5EFD26FCULL, 0x1CDF07D008333D7FULL, 0xC6AD864C2836A930ULL, 0x18444F6F63C7D810ULL, 
            0x2944D750BE6A5FCFULL, 0x30A5E199EC148EB2ULL, 0xD8BE751DA44AF81FULL, 0x1BE5B4E163CBE318ULL, 
            0xC629531B651BF540ULL, 0x5C3943DDF9FE147CULL, 0x70DA1C191B34F939ULL, 0xDD7F78C10C9F7FD4ULL, 
            0x5C38074FCFBDD757ULL, 0x0DD12CDCD7B17C54ULL, 0x78B1EED0879F233FULL, 0x1849AB887E485A91ULL, 
            0x15987D44467247D3ULL, 0xF94C1454742191E2ULL, 0xD7593DF674C51193ULL, 0xF608BFE253D9FE67ULL, 
            0x85E1F702DBB0D16EULL, 0xCCA01E93DB8E23B2ULL, 0x35B8472951D67073ULL, 0xD8492709CD5972CCULL
        },
        {
            0x13B056057E4CF56CULL, 0xB33F82941511E839ULL, 0x21362FBBFE1EAD68ULL, 0x7C68802CE1234F32ULL, 
            0x3EE6883298E9047DULL, 0xF876951434B7BD07ULL, 0x3EA087940D2D511BULL, 0xA2DDC50FD84F6295ULL, 
            0xAC18732ECAF1DA14ULL, 0xB24E15222222F8A9ULL, 0xD2593725322D2D61ULL, 0x85DA4206C8BFD3F7ULL, 
            0x48597FD38A081E22ULL, 0xF9E6ADBF2DA1B64FULL, 0x431E72118A33C89FULL, 0x3059BC9721BDF656ULL, 
            0x93D97ED7706C8A5EULL, 0x83049134229370BDULL, 0x0B1CDE7401ED8C87ULL, 0x612DC4410C095160ULL, 
            0x539433B75A37A520ULL, 0xA7E6E42394330DF4ULL, 0x072AF929FC5DE74FULL, 0xED31877255CF2693ULL, 
            0x63A46865A6AE16ABULL, 0x6464945537962489ULL, 0x5C566946396405E2ULL, 0x4D16DEEF2E2FDC3DULL, 
            0x8CE5A9F7FB197402ULL, 0xB46A49B247275804ULL, 0x75747DD882496959ULL, 0x82C7ACDDBFFBC9BFULL
        },
        {
            0x276D0D1CA127DCE7ULL, 0x7E8703EE59AA706BULL, 0x561DAD54C1059A2BULL, 0xA40783A459B05A41ULL, 
            0x5AA3D3499F408D41ULL, 0x1A08EC6C7E83E9ADULL, 0xD95EFD80D3AB29FAULL, 0xC980A78524B5D14DULL, 
            0xFC40482C1E00107EULL, 0x43181B8CABEFCAD7ULL, 0x456F6CB416C22659ULL, 0xCAA0B3DA1713AB24ULL, 
            0xF4FB41728C2AE2E3ULL, 0x3FDABEB42654A19CULL, 0xB8E6732574C38259ULL, 0x11BC1035EB9B1BABULL, 
            0x97986AD42F489305ULL, 0x2DE45208502273D0ULL, 0xE454F64C1F8BCD39ULL, 0x80072D920DD8F794ULL, 
            0xF439F09B2F3A0977ULL, 0xE44206009EF0496EULL, 0x252DB35EB487FD9EULL, 0x66C4FE4B0BE6FFA6ULL, 
            0x4E4A3B6D64F12DB9ULL, 0xCD12675EF338939FULL, 0xFF856F8B0CB78441ULL, 0x6E96A1336637EC19ULL, 
            0x538487B34A9EF534ULL, 0x40795F5BDEF62097ULL, 0xA837EFF52E8F8481ULL, 0x48ECC5745D67D3FEULL
        },
        {
            0xC5C065DCE291C31BULL, 0xB17211D6371182DEULL, 0x0BCD481CFF64B91BULL, 0x6CF523ACF3129D5DULL, 
            0xD6D180E42E3C4416ULL, 0x3C3C792619B4E00CULL, 0x361681D3E1AD8055ULL, 0xA28ABEAAF191C9C6ULL, 
            0xEC78D0BE23466B91ULL, 0xA4C647F35D8D3835ULL, 0xAD645D843B5CEACDULL, 0x885A0C5038A96848ULL, 
            0xFBFF2C123C1D5C1AULL, 0x92AAB445751A6C33ULL, 0x6F55C6D8117086B1ULL, 0x9F576A6E87D2D5E3ULL, 
            0xC21A225C94DEB671ULL, 0xFFAAF234E986036FULL, 0xFF8A38511671ABEDULL, 0x8C4AD340A233ADE1ULL, 
            0xC132D16AB4880A1FULL, 0x78C180E424C44645ULL, 0x0F0B711E6E616613ULL, 0x65C262FFDDABF0B5ULL, 
            0xDD05EC669311CCA1ULL, 0xC6A04F0CA4F67388ULL, 0x999A06848C19D9FEULL, 0x1E2CCD40A3544625ULL, 
            0x6A71721299E61421ULL, 0x8D26A2665F7C498BULL, 0xD7C5B39AAC952236ULL, 0xC904CF9C5119201AULL
        },
        {
            0xED7F0BB784918A8DULL, 0xDDF821BA8780D58BULL, 0xEDC09E7615BF7F7DULL, 0x9AEA241A331CE693ULL, 
            0x614F692E24F56C5CULL, 0xC6B322752212A08FULL, 0x034408D0C41E69C9ULL, 0x587FDF60DE26CE72ULL, 
            0xDD1C26D27945B060ULL, 0xFFF91C8F730A49D9ULL, 0xD67CF87E9DF9D696ULL, 0x83156EAAD25AACEDULL, 
            0x7B833A06F45C873EULL, 0x003CE231A1EFA46FULL, 0x29CA85EEF8498828ULL, 0x1957A1E92565F6AAULL, 
            0xCE35EA8A3CE5BCDAULL, 0x0F491A60273F8470ULL, 0x6688122E90206229ULL, 0xE0B5DAE7226BD6C8ULL, 
            0x1B5800449D60267DULL, 0xB938685E19CC5034ULL, 0xCDC8E3CFD25C0C4BULL, 0xD6AC2B8B4A9FFEC9ULL, 
            0xFB1C6244B4385905ULL, 0x089AC978D7C8FBEEULL, 0x8BAE150E041161CCULL, 0x6B24B4DE6B18B2FFULL, 
            0xA2E3BED9CBF29D5FULL, 0xFE7B535A827D6725ULL, 0xAF4C68A4017BBA7CULL, 0xB9E8B4CC82D3891EULL
        }
    },
    {
        {
            0x625640055FA25AEDULL, 0x1D324552885738D0ULL, 0xD4F69531556A4658ULL, 0x8AC97E7CE9CC080CULL, 
            0x930218F57E6D7E84ULL, 0x64C9EF5F09643505ULL, 0xA4CE63360ABBE9DAULL, 0xA58804B1E51ADF54ULL, 
            0x5E6D1349930784DDULL, 0xC77B18E1153B7ED6ULL, 0x2455634C4020CFD2ULL, 0xF90E3C841EC69B74ULL, 
            0xF860ACE99AFEDDE5ULL, 0x4A3BA5B82270B7DEULL, 0x9AB2C9466A48F040ULL, 0x46B8382473ABB211ULL, 
            0x62FDD039DC0F93D0ULL, 0x15316B6C53AA1E36ULL, 0x9B7B9E82C8E844EFULL, 0xBEED96369833A154ULL, 
            0x83CA342326BCF6D6ULL, 0x3971FD895EB9A2A5ULL, 0x5A7908C1646E699FULL, 0xEF8DD3505EFC7436ULL, 
            0x3ABA7DAFB294F6BFULL, 0xD316FE480F1204CEULL, 0xF76735B05EF417BFULL, 0xA3FF875C69FBB152ULL, 
            0xAC37C9E318BB1229ULL, 0xE5980728CCD1AC97ULL, 0xEEBA00E0FF7A0C8BULL, 0x25D05F5258AE8E2AULL
        },
        {
            0x7D494F4081E7ADBAULL, 0x82AA6898414E40C8ULL, 0xC2B41015492B6717ULL, 0x5255AAB3BB4B105DULL, 
            0x7023993FC4D41C57ULL, 0x84B7EF39A3949B71ULL, 0xB2B8B6B2652E8488ULL, 0xD2315EDAA976FFA9ULL, 
            0x1465C84505EE2AA1ULL, 0xDECAF54E7B9795C9ULL, 0x4E5DD269E2DE5028ULL, 0x28CA9A400E4D2B55ULL, 
            0x1296B2B93F1F89DDULL, 0xE4A0B11DB20A6B26ULL, 0xAE87A63DC103B9D3ULL, 0x0455EA8ED2B9F45AULL, 
            0xF6845A557A884FA3ULL, 0x7635E3BEBF802A76ULL, 0xB424D02BEBC20B2BULL, 0x4A0A8430D185CA01ULL, 
            0x82CF2A85F4C00BFCULL, 0x920469C52304E250ULL, 0xE82C9011DD3E194DULL, 0xB27329BAE01E3634ULL, 
            0x71224B4E64D6C276ULL, 0xFA116602D68616C1ULL, 0xBCFA4120283AA202ULL, 0x2B00119041D36028ULL, 
            0xEA6DAECD07B9F356ULL, 0x1F797A53D47875FEULL, 0xB3C09178C2603A2CULL, 0xB3DD5D2919BA6FCFULL
        },
        {
            0x5E7127E941019D1AULL, 0xC5141AB1EFA44021ULL, 0x0E164093CD253886ULL, 0x89539028561BD59CULL, 
            0x043EC6280BFAA662ULL, 0x2B2EA184EFDA9E2FULL, 0x2B73457CEC4D1506ULL, 0xC602751025E1EC06ULL, 
            0x9A6A59A6C6C0F23EULL, 0x7BAC64AA7AA8839EULL, 0x5EDB9AB7B54644E2ULL, 0x56E8EEA62683B45EULL, 
            0x79FED96D4C3A995BULL, 0x443BA4FF54139135ULL, 0x5AD8B7CC3391D2D8ULL, 0x9A3652853FE31349ULL, 
            0xD53A08F9A04F45EFULL, 0xEF84429A4BD8A6E2ULL, 0xFCD2E57A7C1B7E92ULL, 0xF0050F950EC7B759ULL, 
            0x43E0FB51C76A7ABDULL, 0xA5B086643AC59920ULL, 0x01B6F3EF3CCE7D1FULL, 0xACE26EE89436BC09ULL, 
            0x8316DC301EF1EB76ULL, 0xF381AC330EFBAA32ULL, 0xF2925FCD3B60CCC1ULL, 0x6584DAB6205A35ABULL, 
            0xA5ACA0FCA8CCC28FULL, 0xF7DBE5D79F9B8D71ULL, 0xDB51BDEFE57BC7ADULL, 0x46595EDC725B34B7ULL
        },
        {
            0xC8DB617607FD0484ULL, 0x512ECF1676FF2EE4ULL, 0x21C3871AD11B16EAULL, 0x382BEA459617F070ULL, 
            0x41A891EECA720D96ULL, 0xD3B3DF0A94FF41D2ULL, 0x408A6FE93D63AA39ULL, 0x54B4971B45328046ULL, 
            0x453080D07A6B29B1ULL, 0x0F001767984EA382ULL, 0xE0E61F1DB3185F78ULL, 0x31F9443EC1EDCD0AULL, 
            0x5911A4B347A44DEAULL, 0x3AD754EDDAEEB187ULL, 0x95F1B5F85AADC9A4ULL, 0x2E71C78F97EA6C89ULL, 
            0xAF3608B256DBB2D1ULL, 0x8649CFE2F1F77407ULL, 0x5F7E0D5B15F16DC0ULL, 0x94C0D281A5390B75ULL, 
            0x10ED8B64AD8D39CFULL, 0x36EAC805EBE1BF45ULL, 0xAF040FAE2A86D586ULL, 0xAFA5717E6F2CD39AULL, 
            0x8A2D63A2A7E94886ULL, 0x536F816FCCB9BC4FULL, 0xF7156E243178A7DEULL, 0x720B0837CBCA26DDULL, 
            0x90B144FA083A482CULL, 0xA55CF57110291168ULL, 0x92C7D782A2B2DFD1ULL, 0xE8C0080A6357A06CULL
        },
        {
            0xADCB9809BC62ED38ULL, 0xEEDC925C3E746CA0ULL, 0xCC71703F47659512ULL, 0x8D91B4E2FB6CD392ULL, 
            0x2B1C6AC393BB51C0ULL, 0xE488213584CAD70AULL, 0x997A158E3DF93B43ULL, 0x773F97F2FCA07A63ULL, 
            0xE9C6273B60EB34C0ULL, 0xA73868A345F8BB38ULL, 0xC16DA2FC9DB76587ULL, 0x32BE7010E970DA2CULL, 
            0x870CB57AAFCFCA24ULL, 0xAC9D93E0BC8C57F6ULL, 0xBE1977DB1B7A234AULL, 0xC8D4BC911B516709ULL, 
            0x02157D7C64D9D491ULL, 0x4607F60A7353230FULL, 0x22988B8EE7D53CF5ULL, 0xE35BA7B6803600A7ULL, 
            0xD7B4F657F7485301ULL, 0x40D41B32A2FEF04DULL, 0x4D41CAAD9774A793ULL, 0x638DDECFE151CCF0ULL, 
            0xF313FF4367E5C960ULL, 0xFC9974008220B6ABULL, 0xF933047CDBB239F2ULL, 0xDB58B06736D19EDBULL, 
            0xAC05CEA95D102F82ULL, 0x9CDE1E74452E055AULL, 0x44A5B4A19FDAF317ULL, 0x6236F7F6E0317A74ULL
        },
        {
            0xC3D67985420246C1ULL, 0x2C6DCACECA31D597ULL, 0xABCCE45413D3FB52ULL, 0xD36E6C74CC4A7DBBULL, 
            0x034090F0EF0613FFULL, 0x7282DE03150675D7ULL, 0x25728913E98E38E6ULL, 0xCC4ADACDBE4BE470ULL, 
            0xC646B5E6F7C859F7ULL, 0xC239B519FC009FFAULL, 0x2EE01FB324A55A3FULL, 0x61DAFDCD1DAEECDBULL, 
            0xB4BC15BF474D1A9CULL, 0x923A8CCA0745750DULL, 0x36DA7B5544976DAEULL, 0xA8E18821EBA1C98AULL, 
            0x4EB5D7B9DD7D0843ULL, 0x252B6CB8DBCF4576ULL, 0x0802A5A16F4C8522ULL, 0xAAF2FB4A7ECB30F3ULL, 
            0x1021F4C96E3002B0ULL, 0x317B87D7530C2501ULL, 0x909BA26F936BD768ULL, 0x46EF532375FAE775ULL, 
            0xD585721C07A85F81ULL, 0xB83080A317E0F236ULL, 0x59E4722E70592906ULL, 0xDC16D6926A4F63F6ULL, 
            0xD86C4723D04E4CC3ULL, 0x957F4D8192E8AE66ULL, 0x11F04B10C5153D6CULL, 0x2CAF0C8E3E5B9A67ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseDConstants = {
    0xA2342A986BE789C8ULL,
    0x8531835AE9008909ULL,
    0xB51AD079B0AE52BEULL,
    0xA2342A986BE789C8ULL,
    0x8531835AE9008909ULL,
    0xB51AD079B0AE52BEULL,
    0x715FC53DBCCFD33CULL,
    0x0D9580E2156BE055ULL,
    0xA5,
    0xC1,
    0x6E,
    0x13,
    0xB4,
    0x22,
    0xB2,
    0xC7
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseESalts = {
    {
        {
            0x665C1653FEAC77F9ULL, 0x6F4E2024465AE4B8ULL, 0x11CD7B38BC2DFBBAULL, 0xF7DB08B69D9F92E1ULL, 
            0x263CC15B1818C238ULL, 0x9B99FF817241472CULL, 0xEF4ED62532126D37ULL, 0x34C9BC6E838A5306ULL, 
            0xA53C4CADBD93AC83ULL, 0xF26064A46C5C0CE5ULL, 0xA22B850FD72F186BULL, 0x3EC227B21D193898ULL, 
            0x45C503BCAC5C79B1ULL, 0x3EBBE5779599A4CEULL, 0x16482E967522080EULL, 0x15D824C7C7A031E7ULL, 
            0xFC4268BF40928955ULL, 0xC8B1A7A968B151C9ULL, 0x1C9A36D08E63CE33ULL, 0xD1AD7E3FAB8BE707ULL, 
            0xDA1B7D669977CC90ULL, 0x5B2C2A063101C2C6ULL, 0x78AFA473EFE0BAA3ULL, 0x8A0F3D8DA3852444ULL, 
            0x0AA6B5A90EAF29BAULL, 0xBBD1AD3A00CEDAF8ULL, 0x079BEF6AB86DD825ULL, 0x7858B4F8425E90CBULL, 
            0x0A9D2C5DEB4189F7ULL, 0x9DEF74EEFAF8324AULL, 0xDAB02ACDF429ED50ULL, 0x61AAD3F2EFDEB169ULL
        },
        {
            0x7B7CA3AFD0DCBD58ULL, 0xF3CE82319156E8C1ULL, 0xC35D471497355F00ULL, 0xF2D2E94ADA168651ULL, 
            0x200DCA68FAAEF0C5ULL, 0x9867D5C0C33C05C9ULL, 0x7914BF2D108619F2ULL, 0x3CBFF595B5027DE9ULL, 
            0x8DB0D28321138796ULL, 0xC557D4479BAF42D9ULL, 0xDD1E5EF3BF1174B6ULL, 0xADA4A29DE8911129ULL, 
            0x753EC507C09148C3ULL, 0x83BA13FDBC467A33ULL, 0xBF16357839E71ECCULL, 0xCD0D487D8F972C5BULL, 
            0x797505203AC15C04ULL, 0xED9E623CEA19E360ULL, 0x51B887C6771896E5ULL, 0x4A846A8FE085086AULL, 
            0xA9391CD74744CDB2ULL, 0x842D66A8950DE742ULL, 0x62C3A1E0BD756374ULL, 0x53E9957E5EB2C37DULL, 
            0x1C102AB3302A0DA2ULL, 0xAF51FE8F45098427ULL, 0xA646401C3D0C4ED1ULL, 0xFF8A914E97C669B5ULL, 
            0xE6C05116DB1BBA4FULL, 0x102A8A0BC117ABDDULL, 0xF425B047CFEBC1C0ULL, 0xE58A4A8F52179B8AULL
        },
        {
            0xDD5C4AD7D83E801BULL, 0x59761320CA4F830CULL, 0x2C8CB1EA01E6B5DAULL, 0xBFB138150C71CB1DULL, 
            0xCA1725870E685F61ULL, 0x3967851214D1E691ULL, 0x3C9EFE1BAD559FA7ULL, 0x5B566103D39EB929ULL, 
            0xB38F73938A69E8EBULL, 0x0930C0BCFAE737CAULL, 0xF648733DD6221026ULL, 0x132C5FADD5D9D7A1ULL, 
            0x6BD9C16DAFE704EBULL, 0xF1640F5EEB54DFD0ULL, 0xE105843FACFE0752ULL, 0x203241614B196517ULL, 
            0xF107240AFCD6A6A0ULL, 0x1EF0C73EFE4E7B9CULL, 0xA4FC334CCADE3DD8ULL, 0xC0D2CB2774E093A1ULL, 
            0xBF2340BA3056DFA9ULL, 0x6AD0D9A4FB2D42C9ULL, 0x212218BFEB60992AULL, 0x13CC8FF5EE50BBC1ULL, 
            0x8A77D7663B5A8FF2ULL, 0xFA90EE6F5F833A18ULL, 0x823CCF789E3180A5ULL, 0xC13E53896AE14C91ULL, 
            0x17C88C3413808499ULL, 0x5A244CD75B9ED76FULL, 0x67DCAE9464525CF7ULL, 0x57C3553A476A7FEEULL
        },
        {
            0xBFE11AC8E31AB047ULL, 0x19237D172A0D9424ULL, 0x0D148D5563ABBED3ULL, 0x12104BA4186BF418ULL, 
            0x9D7CA941C6093970ULL, 0xD5E9B52983F3CD93ULL, 0x6E2AFFDEECB617B0ULL, 0x7570BF68601946ABULL, 
            0x9AF03D7606A898FBULL, 0x5A3B6635CF1FE1BEULL, 0xC3009A1F3735CBF2ULL, 0xB839D431AFFCFA3CULL, 
            0x1D0031EF5EC98B88ULL, 0x488CF0DF6BCEF495ULL, 0x6A7BD8D4C42808AEULL, 0x4D12C59AD7104178ULL, 
            0xDF87CDA5ED27DA4BULL, 0x58D2E612C05A2D00ULL, 0x162C11DB5C78D443ULL, 0x0F3C52288B3F66F5ULL, 
            0x6A3795161D3B8E05ULL, 0x9789F44C49E1A39FULL, 0x5270C36C1D7F3E15ULL, 0x7C665D64FF1EBCE6ULL, 
            0xEBC144E1FBD8AC80ULL, 0x827A50B99D5C2EFFULL, 0x7ED820DC1FEF9AB4ULL, 0x6F0DDDCD5793B145ULL, 
            0x71508522D7804537ULL, 0x0FB2AD9CE65BD276ULL, 0x0A92F6FBC86B3343ULL, 0x330EA87D80D77E68ULL
        },
        {
            0xF2EEF34BB8525E50ULL, 0xEAF363A0E1DEDB9FULL, 0x0BA3A44DA2DB7730ULL, 0x64AA25C4E675A0C9ULL, 
            0x27FD7CD55A3AAE6DULL, 0x206C510A4F309F83ULL, 0x84FB4B79202DAAB5ULL, 0x6C59CDB29C4B76B2ULL, 
            0x648BDA573D340F32ULL, 0xC865A7F32B4E1611ULL, 0x605C38096AC9C75AULL, 0x4AC8A9BCD42ABB35ULL, 
            0xCADAB3F5D16C0DEFULL, 0x455F854B5C63FA43ULL, 0x5CCB5E675846B401ULL, 0xD04DF403F4FB7FABULL, 
            0x4C4D8FB2918817C5ULL, 0x9D8E79E8A1502843ULL, 0x8CA6C875D0175F20ULL, 0xC90234950358CA50ULL, 
            0x7E96433896D625D4ULL, 0x2279DA38CC873EBAULL, 0x4B6D53594BF4BFB3ULL, 0x90EBCF6CCBF21639ULL, 
            0x7F2AC73CBE5BF57EULL, 0x4D74C8B4F7BA82C1ULL, 0xD97B8ED3D9D7AD35ULL, 0x326FD6050F389B90ULL, 
            0x32B75F75CF4774B3ULL, 0xAA37FC01BEB8B115ULL, 0xA751D6359B459D9EULL, 0xD4483EBE361CE3E2ULL
        },
        {
            0x75588E71A706BF30ULL, 0x5F1B183826DF27BDULL, 0x14FB3FF786117BD1ULL, 0xC54078D78B4CD826ULL, 
            0x2AFB17D75C01DDA2ULL, 0x155206D8685DFF85ULL, 0x39853266F11F6451ULL, 0x84CB5CAC41AF8C1EULL, 
            0x53AFF59361511988ULL, 0x92917A87201F9B50ULL, 0x1A62F7BAE0CA058AULL, 0xDEBDDC379B778A4BULL, 
            0x79DC71F52195DD5BULL, 0x6AE5A1BF8BDB6F92ULL, 0x930826925C8D8E2BULL, 0x9DC1F05A3CCFFC57ULL, 
            0x8C4713A5021882A5ULL, 0x56F80755BB808DE5ULL, 0x9E203E40607232E6ULL, 0x75EED62781E38616ULL, 
            0x8A24D1ECCD2CA9DAULL, 0xE96718CFBFAE58D5ULL, 0x309D7F920EF3D60CULL, 0x4A504C9A8E870DA1ULL, 
            0x7F3AB336557D3336ULL, 0x9548818CBAE6DED2ULL, 0xC2411C6C5D2AF436ULL, 0x927B7110DFD41DDCULL, 
            0xCD5990CC9F5F6F7CULL, 0xE2E953732F17BA74ULL, 0xE63D98918AE11851ULL, 0xF75AA2533A5EB3B7ULL
        }
    },
    {
        {
            0xC423817B87D081D7ULL, 0x79A41F1D49E6827BULL, 0x9F8AD25DCE4F081BULL, 0x6DABA026E819C7D6ULL, 
            0xD0EF2F75418F6401ULL, 0xA0EC205148C812BAULL, 0xB4CFF904D60439F7ULL, 0x50A98919A3A94CABULL, 
            0x6BDEE021C45D2681ULL, 0x8DD1145D4BA496D7ULL, 0xD581C8137077DCC6ULL, 0x933ECFF09F128109ULL, 
            0x419306F67888EE33ULL, 0x99CDF687B5EABB25ULL, 0x198A1B8538F1A3CCULL, 0xE9D823C15D29319CULL, 
            0x33D4C078CFE63515ULL, 0x376B21CC2EA09B2EULL, 0xB12EF1E7B0ADBB30ULL, 0x9EE3DB34EA37BB0FULL, 
            0xEC6452774033BDAFULL, 0xEA4D2DBCE38DB7F1ULL, 0x10FAB68A8403F63DULL, 0x3C7A5EE41C80E4F4ULL, 
            0x07413A5BCF7FE0BAULL, 0x1EE67487DC28006BULL, 0x49756D1C1267C9E8ULL, 0xA07D3AE390C5F530ULL, 
            0x83A867920F0A4A44ULL, 0x1DA4B346943C66B4ULL, 0x5F3C8E62B5090B80ULL, 0x20252C4804F19FB5ULL
        },
        {
            0x7CC470FEC73D770CULL, 0x1776C961066D79BEULL, 0xD5CFE1A87EE5C0D9ULL, 0x02BF1845297080BFULL, 
            0x681042FE589773D9ULL, 0xE9DB0B874A327DD8ULL, 0x0031F8D5A7B7ED1DULL, 0x1235D450A10D176AULL, 
            0x7E093E122A550507ULL, 0x3E2D2E202A6EB538ULL, 0x3B508C2D8B9CD029ULL, 0xF62D6E32A7631AD3ULL, 
            0x49A0F3A80AE8BD94ULL, 0x503C53C604153571ULL, 0xC8EB0DE43FCBD838ULL, 0xC8787DD5489E87F4ULL, 
            0xC4FB057AEDB22388ULL, 0x86A15CB19BBF6446ULL, 0x93F837C29CA67397ULL, 0x78DE65196DBA8D91ULL, 
            0xC9219859E761C0E2ULL, 0x82C223861FE0945FULL, 0x39CEAF6652A94D3EULL, 0x94A7372BEA7EEFF1ULL, 
            0xE493F409B69E3698ULL, 0xCA733B004E6081ADULL, 0x18FE0502E3258C2DULL, 0xDBE760DA962DF77DULL, 
            0xD8767BB68AEDCE1BULL, 0xA163B912203A7D22ULL, 0x699608B4B6AB0D55ULL, 0x8660CA98CB2D8D18ULL
        },
        {
            0x0DA30C8943B099EBULL, 0x68EDB143D28E7A49ULL, 0xEB4BCA3CC81794A7ULL, 0x4025D0B9D0E9FC33ULL, 
            0x88F03679F307D7EEULL, 0xB072CA5EDFD85DEEULL, 0xF987BD3D82162529ULL, 0xAB0A07D2387EAF76ULL, 
            0x59E41BC262F97C7CULL, 0x29AF92EBDE80AA28ULL, 0x87C53B91C93645C9ULL, 0xB52A7080642C4E2FULL, 
            0x6E06612C20D6FD44ULL, 0x68467B04E9F8B28CULL, 0x3E74445BAFFA49B1ULL, 0x03DE9D9FFDC63751ULL, 
            0x2FA667FE7B128E9CULL, 0xD912CACA6DEC7DF8ULL, 0xE3A66E17236B20E2ULL, 0x4B58F6D6D21E0E80ULL, 
            0xF2A7F64C660600E0ULL, 0x6D6689DF25986C04ULL, 0x07F22BFDA9E7BA9BULL, 0x9679B8C6A3EB8F83ULL, 
            0x91E1818A10B6680AULL, 0xFCD9A4751C26E77EULL, 0x0DED2C58CCD0A0C4ULL, 0x13BAD9FA4B8307BFULL, 
            0x95DDEDC4279BC9E2ULL, 0x920D497948A83CE1ULL, 0x0584EBC23AEEB2DAULL, 0xFB0BD997826A4BA2ULL
        },
        {
            0xEDF5C9A3131194AEULL, 0x90381DEF9AE9B57FULL, 0xE8255924F946A638ULL, 0xB8EC411C3F1D234BULL, 
            0x7BEF752AAF6C8CDCULL, 0xEE10C657DDFDEDADULL, 0xF8DE38218AF8A344ULL, 0x4B8CFED42D5ACA23ULL, 
            0xFC23143328B82467ULL, 0x9DADB7BCE076F71AULL, 0xFE1159337186F7FAULL, 0x89D0A40A43D4EC3BULL, 
            0xBE1FAE30E7F42811ULL, 0x09ADCC149B3DA2C8ULL, 0x44907EA55E6FEF67ULL, 0x9A29B65F8C819B2CULL, 
            0x9320DDA17E4C9BFBULL, 0x8EDDCB72D5CA4931ULL, 0xB78AD94C82B2E0FBULL, 0x60890D1BE5D08A43ULL, 
            0xA15BB0C935A0B3FFULL, 0x65264C2F1A71E93CULL, 0x35A8A2DD262C7427ULL, 0x41B0A46ED941BCA8ULL, 
            0x82E87D603AC709E5ULL, 0x8AAB6E04C251548EULL, 0x629BE45D1C6F8162ULL, 0x4547609D1E0544BCULL, 
            0xFD5BB886755C39A4ULL, 0xAC477435A0E87B13ULL, 0xB33620F34B057606ULL, 0xC0ECB468037B30C5ULL
        },
        {
            0x6B9C9782DC091FA0ULL, 0x41B3C50EBE2421DAULL, 0x3E9E5E360BD224D7ULL, 0x53544AA70A237128ULL, 
            0x701B3692F3685A54ULL, 0x488D0437D602D8A8ULL, 0x248383A07CE1D8E6ULL, 0x7BC50A5AB7F2A1E5ULL, 
            0xEB2A080A9E1D375AULL, 0xA633C283971F9CACULL, 0x5F2C7D45A37CFC37ULL, 0x66B698D9ABEECFA8ULL, 
            0x0A49124A263C8850ULL, 0x53A6ABE81BA2B62BULL, 0xB06AF121882E315FULL, 0xFB3382F8894DC879ULL, 
            0xC146D99F311A2D07ULL, 0x5D5CC10A55F4592FULL, 0x8DD06E2E55759C59ULL, 0xF4E2E18008E733C8ULL, 
            0x6AA07B2B1B522CD5ULL, 0xAD0B6371153E5104ULL, 0xAA3BE1DA496E5823ULL, 0x984F6A4019D63729ULL, 
            0x75A02212D520C8B4ULL, 0x07E9BD5F18362591ULL, 0x67F240981A663D3CULL, 0x984104ABC18F68B4ULL, 
            0x618FB89C22E28DA2ULL, 0xD5769D3F8150E2D8ULL, 0x1750C4D6195DCAA8ULL, 0x2A8B4516EF0BE768ULL
        },
        {
            0x7B123110CC2ECFD8ULL, 0x2BC5624D1ECA8335ULL, 0x458096525BE3E485ULL, 0x6F778F77B1273ADBULL, 
            0xD7335FA3DD0425B3ULL, 0x599CAD184C6EF28CULL, 0x4E2A5D83B7A3AA05ULL, 0x50618322EF56FABAULL, 
            0xBEDE1DF2D1C67DB4ULL, 0xDF352637BEFA8219ULL, 0x143D8D051105878FULL, 0x47E9CC12D22A75BCULL, 
            0x4C42E8E498CAE9FAULL, 0x0E815B25886D003DULL, 0xBBC91B3DAEFF0B14ULL, 0x1E4E4574F072A13FULL, 
            0xFC3B20A47037F08CULL, 0x711DA2D18CEC14D0ULL, 0xF4882D6A758DD9F7ULL, 0x9F0AF20DDF1A0057ULL, 
            0x11A3275D7ED5A5F0ULL, 0x3A577369D9766A15ULL, 0x65EBCCD46CCBE2FEULL, 0xAF7F22B16C7C7719ULL, 
            0x794F55DD7463CA91ULL, 0xA1FE5315E36D06A8ULL, 0x9E03831A48795889ULL, 0x609C6B0D4BD2BECFULL, 
            0xE9A56B0BDA411E55ULL, 0x9431DB2E8FB93210ULL, 0x2B8048B4E3F77E00ULL, 0x4EC12A4C9553B40DULL
        }
    },
    {
        {
            0xD6382F752A197ED0ULL, 0x60C6BA891C6E1070ULL, 0x62258F1A21933DC2ULL, 0xB2D561D8B1DCAFF6ULL, 
            0x167FF2958C986C0BULL, 0xEFEE159E33887D2DULL, 0xA1AD693A4EB297FAULL, 0x2BE85F0281E865C8ULL, 
            0x4D07E715DA1C9989ULL, 0x99C0C99CCBB2AE29ULL, 0x703B53B5F7F5C3DEULL, 0x63D885E3C380C23DULL, 
            0x48F56B7C2205B224ULL, 0xC85281157890FD90ULL, 0xDBD4BDDAADF0D1ABULL, 0x6FB4F73488162764ULL, 
            0xCB5AC3DF3561065BULL, 0x3411EBF0CF1931FDULL, 0xE8A6C6C4A98E44A5ULL, 0xEFBC5566EF3DD582ULL, 
            0xF3FA6D293FC674CEULL, 0x5DBB01CC9E1FA4D3ULL, 0xCAA0C61474AE6277ULL, 0xFA3F5FB3B38A2E25ULL, 
            0x19193D1D584D755BULL, 0x6758BBAF0959B8F1ULL, 0x5AA9DB7833601F65ULL, 0xB1159308A56050AAULL, 
            0x73EB02241DC732F6ULL, 0xB330FE6E739B59BBULL, 0x2F6F097A429485E3ULL, 0xB983D5CE090AE589ULL
        },
        {
            0x5CF1285966FC507BULL, 0xF2E2C29355425CFDULL, 0x1C4ED34CACE326CDULL, 0xB0479F4684A71DEBULL, 
            0xF3D2EF3795A0E293ULL, 0x3ABA9E4154C95D47ULL, 0x762F9B858ECD3D15ULL, 0xDDA5087F5D50AE17ULL, 
            0x26A643ED36D0EAB9ULL, 0xFB3EE73D3E2E39D2ULL, 0x58964F61DE739EDFULL, 0xC353391C4C73F5FFULL, 
            0xE51A9FC07D9006ACULL, 0x4926BD03FA6D800EULL, 0xFE0F4A075C3D1491ULL, 0x001C16CD983DD1B3ULL, 
            0xE82FA8BCB8F0B97EULL, 0xEAF0A7B1E44AB156ULL, 0x20F1393189E6DC10ULL, 0x4A1D2092CF6FF4F9ULL, 
            0xA2E40886131A446FULL, 0xE7BFC0E62F0AA63CULL, 0x0FF83650B3EE45B1ULL, 0x2FB8E8272DA7D0A5ULL, 
            0xEAE9556077AB5FF4ULL, 0xE8A7AA0E69C5613DULL, 0x44ABB0761D8334B4ULL, 0x153993A1EC8C66D5ULL, 
            0xE667443051A07380ULL, 0xEF214B5831DFB1C4ULL, 0x542D0A191D21E011ULL, 0x4A72EBA8B55E7816ULL
        },
        {
            0x802EEA67287016B5ULL, 0x4428924D6CD8D631ULL, 0x1A344D066E40FC8EULL, 0x309543B6DC204AD7ULL, 
            0x56B8C4AE658D1CB5ULL, 0x4ADA56AB032C21FDULL, 0x66E0C1E0EE2FEEAEULL, 0x11EA59AA0D5CA509ULL, 
            0x7E6B89F279502B12ULL, 0x9E5F4FF711F1A56DULL, 0x640459AD390A5586ULL, 0xC49EC69134F9792DULL, 
            0x64436988127A5FA9ULL, 0xADF4DEE4427B335DULL, 0x4C1DBCA81253C193ULL, 0x0F8AAC4A433FD2BEULL, 
            0x0338BBE21FB67106ULL, 0x454FECDBAE48B5E0ULL, 0x3A7061E9F61EB439ULL, 0x4AD55E3A505AD33CULL, 
            0x8303AB8856A7F285ULL, 0x30D3A43BEEF5AA20ULL, 0x546042E7549C33A8ULL, 0x85B1231B766940C2ULL, 
            0x5F35E39BAFC5B94CULL, 0x4DFC650FCBF9183CULL, 0x0E56CC4E267659AEULL, 0x113A37F84ADA019FULL, 
            0x92B64BD2528BB508ULL, 0xB243C4B0C8C72948ULL, 0x7D7E2ED8C6F198CCULL, 0x257C1AD4B4BDD885ULL
        },
        {
            0x25682C76F811B954ULL, 0x77B893A03F6E3DA2ULL, 0x4AA24F1D71DE2C95ULL, 0x5FA7122DDCDE8DFFULL, 
            0x2E3F43A7B1B83D95ULL, 0x81FD262AECF42C67ULL, 0x036B71F265F473A9ULL, 0x93F206CFBF28F477ULL, 
            0x804C103565F53BBBULL, 0x96538FB05305550EULL, 0x9B81B4ED3DFE43CBULL, 0xF93AAB3DBBBCAFBFULL, 
            0x7909E22D8FAA0B8AULL, 0xAA408937BBF6EF41ULL, 0x02161958FD3249B2ULL, 0xCD2D89F14484F6DCULL, 
            0xD0A212EC72E6D3D3ULL, 0x5586578B5C702688ULL, 0xF9537E8B8B27FA9DULL, 0x3E10920B59837BCEULL, 
            0xD7B158BBB4DEC5F8ULL, 0x570ADB340521A372ULL, 0x7BBEC169B11EC43CULL, 0x66F0D14F8DF7799DULL, 
            0xACADF80A5096F7B3ULL, 0xF2B642F926DE8CCCULL, 0x9504C18228D7A1BDULL, 0x90E7A9E570187F47ULL, 
            0x3F881C182DFEA420ULL, 0x2AEA2D974358E290ULL, 0x9CC7217E0D5EFCEAULL, 0x813E7D59D0CC40FCULL
        },
        {
            0x742808FBA2082AB8ULL, 0x29F516AADC69C5C9ULL, 0xFF35A43C4B150C81ULL, 0x2F24D6D4755D7DFCULL, 
            0x5F4E4E1DEFF7D92CULL, 0x9382F91CF249DF71ULL, 0x7C73D49A4DE7BAE9ULL, 0x43F71A38CCA39B0EULL, 
            0x79DD3B4C43631B79ULL, 0x7ED17EFD84453C1AULL, 0x0810D67A852E787FULL, 0xA9F648AA2596210EULL, 
            0x849AC75808BE6B96ULL, 0x6466D7FF863530F5ULL, 0x48E801654B6CB5B6ULL, 0x582CA296F65C7C04ULL, 
            0x05D9CFFD908C617DULL, 0xB0B313A9D7E2497DULL, 0x1A808FBFA853523AULL, 0xF6D77DD8FE57D64BULL, 
            0xF6D61B96F59826EAULL, 0xFA199F1CF4882404ULL, 0xC7F3DDEF5FCF26E4ULL, 0x4FFA5032EB3BD29EULL, 
            0x94BEA0EBE74DB24EULL, 0x223B3F61ABBD05ACULL, 0x3B21C0613FA22BBBULL, 0x27FA50B56B66199AULL, 
            0xB6C23457450EF4D2ULL, 0x8F113885DE25AE79ULL, 0xF6BC617E10D5F668ULL, 0xBF1C57E2D5852E8BULL
        },
        {
            0x96A4247E7E6B2F6BULL, 0x9F833CA6A2542AC4ULL, 0x3B3A027F5B5FBCE0ULL, 0x93F40CC2F29B8821ULL, 
            0x152AF2CF3701A89DULL, 0x74304DAF3E434616ULL, 0x8917FE0B22B3BC2DULL, 0x0BF4A929B2A8252CULL, 
            0x0180A6D3284B8553ULL, 0x2E83AE20924F5B80ULL, 0xE5F075E2E442E1AEULL, 0x7586A5E6049010C4ULL, 
            0x50076D7EFD98E37FULL, 0x3F1968FB91DD4DB0ULL, 0xC9632D88F15A2DC9ULL, 0x9A25CE4BB5207E41ULL, 
            0x0A78769145E14A31ULL, 0x2FA5C7A833E720B3ULL, 0xC7057C23CE7A356FULL, 0x46B122463DB3D6A6ULL, 
            0x16DC93B86649F389ULL, 0xD7337FA9335BEFBAULL, 0xAAF0FA5F0B957B50ULL, 0x07116ADD4814FC4EULL, 
            0xAAC09D656B69C16CULL, 0xCF21EB8A55BFC44DULL, 0x72C0BA14F871DBEBULL, 0x0171A8651F494F65ULL, 
            0xFA9A490E8E61F0CFULL, 0xAB7A74FFAFFA98BAULL, 0x996AA3E7E2DFA740ULL, 0x97E011BDFEAE2678ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseEConstants = {
    0xEE97593B05BE48F6ULL,
    0x047A43E223D42EC2ULL,
    0x7053378E2450A36AULL,
    0xEE97593B05BE48F6ULL,
    0x047A43E223D42EC2ULL,
    0x7053378E2450A36AULL,
    0x99C8FA67370AA1BBULL,
    0x7564F0733F472BB1ULL,
    0x93,
    0xF2,
    0x5A,
    0x39,
    0xFD,
    0x7D,
    0xDD,
    0xFB
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseFSalts = {
    {
        {
            0xBB9441B038280B78ULL, 0x50F223795D05D828ULL, 0xD2FDD6092FB6F02DULL, 0x04E254DC6072DFB3ULL, 
            0x926E515E4008368FULL, 0xED09A2C8C7DFBFACULL, 0xC7309703FFE919A3ULL, 0xFC45E9BBD5167C22ULL, 
            0x9459D659B5551775ULL, 0x7A7B111E359C9E4CULL, 0x24673D225EF02CA9ULL, 0xA7056226A8386E48ULL, 
            0x5B3995E4AE346067ULL, 0xEDD0F1E1E6AE7D3EULL, 0x1DE8ABCAC614A465ULL, 0xDB5A0FAF205B02BEULL, 
            0x27054C820BE2BB6BULL, 0xAD8F48E69D991D9DULL, 0xAAAF04570DAE95E1ULL, 0x254F7E38248FEF18ULL, 
            0x0479AB6E12047717ULL, 0xF3D02041AD6BF200ULL, 0xFECED7C78B075141ULL, 0x62D07A109047273FULL, 
            0x44D5B4604E039767ULL, 0x56E946A72EF02C1BULL, 0x3024BAE75AA3E782ULL, 0xA3D483BF26F8543BULL, 
            0x006E5267F33CD762ULL, 0x9705258A0C44AB5CULL, 0xDEF55CF4A0ADEDDFULL, 0xA4086F0BF15D6D08ULL
        },
        {
            0xEAB495F5A52AF2FEULL, 0x41773CC4360A66E9ULL, 0x09823DD9C754B066ULL, 0x63D7415D3D0E7185ULL, 
            0xB0F0F95F632C3394ULL, 0xFC1E6004F9087034ULL, 0xCF9045CE106A2D63ULL, 0x4A13876B0A39D24EULL, 
            0x6FAE36EC580DA782ULL, 0x56F475E148305774ULL, 0x83C072503042D01CULL, 0x8A04041174DFFAB5ULL, 
            0x08533D9BF3365866ULL, 0x1368FB6B85C25CB9ULL, 0x619996CEFBDD4AAEULL, 0xA42C2089DDEB9057ULL, 
            0xA8D0DEE1F0E66E4AULL, 0x2D5C4A05C72849C8ULL, 0x351C301A270219C5ULL, 0x87FC9E8A14BE81B6ULL, 
            0x05726DAF3A19A190ULL, 0xE063E196B8A954D3ULL, 0x0D7F39F7ED44B011ULL, 0x72B133AB518C466DULL, 
            0x65C209B9ADA431BDULL, 0x47BD07B1362B5EE0ULL, 0xF182F33B6530C2A3ULL, 0xEB2037F2F62AAD01ULL, 
            0xCDB9D0EC07C10AA6ULL, 0xF829C58FB659A497ULL, 0x0F3B7EC718A47A24ULL, 0xECEB622E1B636417ULL
        },
        {
            0x7D1A589AF73A8985ULL, 0x8BA1DE8E175CE63EULL, 0x815A7E2BEA498E70ULL, 0x26FF37678CFE06ADULL, 
            0x2DFAB9DA81F17DE9ULL, 0xA65D4947D052AC40ULL, 0x9D9C38A209073125ULL, 0x273B3779FDD2FB92ULL, 
            0x5E481EE19CC7BA5AULL, 0x18D60A7557090CF2ULL, 0xEB7BCA2BB8054DE8ULL, 0xEABC9484461C8675ULL, 
            0x2DD2DD76ED436DEBULL, 0x30CEA11BAA3B7504ULL, 0xC2A3615CB6E7E529ULL, 0x54050060ECB1232CULL, 
            0x415D30A28FD0F799ULL, 0x3B781507A0FF541AULL, 0x809BBC2E6C9862DAULL, 0x972349A14582D36CULL, 
            0xD982C62EAEA7AE9AULL, 0xF12AE202CD04E4D5ULL, 0x175E1CCFF75ACE85ULL, 0x1C85FFA5189B576DULL, 
            0x29A1662D3163DB2DULL, 0xBE9ECA29D180E1F2ULL, 0x429972BFAD3C7C42ULL, 0xF06E2552DFD15DABULL, 
            0xB442F088E07EA58EULL, 0x50561A23B98170B4ULL, 0xD680695D91EC3BE3ULL, 0xCDA628AD7C6287D9ULL
        },
        {
            0x3B7F458E469B8C29ULL, 0xF88B2F90C0A3EF42ULL, 0x89DF83218B5E2C96ULL, 0x9E01BA5D1F0FBCC6ULL, 
            0x668D9506D8EFF989ULL, 0xBBE11CFF292FC0ECULL, 0x11CD02E0294017B0ULL, 0x365B4C53BBECA5CCULL, 
            0xDE9917AC965158C9ULL, 0x98D4D4F044EB64C2ULL, 0x21D80ED86AABE472ULL, 0x970A82E0A56E93DAULL, 
            0xE18F625B7D856396ULL, 0xE797D342D266BC24ULL, 0xE9CF7D9199E080B0ULL, 0x28A301FEE49E51C8ULL, 
            0x55ACDFC5687AE796ULL, 0xB0A6784D431F8B70ULL, 0xEE6CC122F1FAF785ULL, 0x2B7B761B4F929D5CULL, 
            0x2AF2B42528C4DB6FULL, 0x266D8C430BCD1AFEULL, 0xA4C462304D61F532ULL, 0xE6F6E6C4DC820AB1ULL, 
            0x12DA0FF725C8AD44ULL, 0x3D67706D5E817239ULL, 0xA0B24C7E823DF6DAULL, 0x4433BA90FB890C46ULL, 
            0x568EA0D4E96F0A22ULL, 0x6C2A3B4CF8F8200BULL, 0x3E2D7966AC44E6E8ULL, 0xA1EE99DB0602838FULL
        },
        {
            0x11A7EB0601309A97ULL, 0xC1B7024D292D265CULL, 0xB1A9E27D6209F65CULL, 0x341886E65F0DF7FDULL, 
            0x810CC9F4FC0F0D4FULL, 0x57CB1E0E04442DC9ULL, 0xB0C57C6300FFEE37ULL, 0x262CC76D3B563E67ULL, 
            0x3A29421F00B65EE3ULL, 0x30303E573334F03FULL, 0x2FD600F45FCAFCC9ULL, 0xB67B38C3EDDE034CULL, 
            0x91F69CE709731F33ULL, 0xF746F596E9C1A87EULL, 0x7E24FED413D690EDULL, 0x851934BB6AC3A1C8ULL, 
            0x189552607630286CULL, 0x8C943B6A09A48C9BULL, 0xAD12B128A96689AEULL, 0x33C9DFD7365FD40CULL, 
            0x611AD7801536855BULL, 0x6C4EF0DB2FC2400BULL, 0x28017694DE760586ULL, 0x052B54D9A7D0107BULL, 
            0x803A21971B7F832CULL, 0x185FB5ED5E26B1D6ULL, 0x90F26716FC0515D6ULL, 0x6039E808DB1F2AC5ULL, 
            0x54CDC1E9793DE62DULL, 0x7A6FB3C044CAD978ULL, 0x251EBAA2216B2A18ULL, 0x0D27A8D67A292EEDULL
        },
        {
            0xDA1D02E516C6AA91ULL, 0x527D7BDAB2747BEFULL, 0x22A46CE6AA2EAAD5ULL, 0x8244F07C57205834ULL, 
            0xA31189EB509758F0ULL, 0x5CF6E9C63BDD920DULL, 0x3D1C3B3EE07951FDULL, 0x42A44FF3FC76906FULL, 
            0xDD46DD3D5458053CULL, 0xE8664EEE10DC37E5ULL, 0x574FC5A33F601D1BULL, 0x4FD72502F64D16FEULL, 
            0x6FC3A27FBA830D09ULL, 0x2B9FEA58C4DC6759ULL, 0x595650550C84C17DULL, 0xDFFD62FE4D2769E5ULL, 
            0xE7CB7D4CF1EF58EDULL, 0x0C82A333339BF2DDULL, 0x4BC2DB318250B186ULL, 0xC4C65FE60CB5BBA9ULL, 
            0x83792F71D456FBF5ULL, 0x377D5DD1A2FDC8DAULL, 0x240AEFF5A08600DAULL, 0x8824061B65F43D19ULL, 
            0xF76CA3AC9611DEEAULL, 0x5152FA6CFA01EAEEULL, 0x0E9D3A98643AF79FULL, 0x60EC1470126A5B9BULL, 
            0x220BB83F5B809E24ULL, 0xF5073E509B8FA6B2ULL, 0x5506D789451CEFADULL, 0xB7CB9B3595F8D09BULL
        }
    },
    {
        {
            0x3249F9926EEAFD8AULL, 0x60B18B3AC8EA605AULL, 0xD43368DD5E5E705DULL, 0x271117B9E77F49BDULL, 
            0xCC9CFC7378C310E8ULL, 0x792B671001866081ULL, 0xC078D0B1C0274B59ULL, 0x532ABDE2F7F8F277ULL, 
            0xB5D024F18BCAB039ULL, 0xE340F9F7169C2A4CULL, 0x0D160DABAF434B3FULL, 0xEC58EEE9F7C960DAULL, 
            0x39B5474C8DFD91B0ULL, 0x9C9F43F33505E6DEULL, 0x94434D0483BB1300ULL, 0x0BA895DC6567FD1CULL, 
            0xA61BE8CA0152802BULL, 0xBED789FD799F3FE9ULL, 0x5D1A43C240DBFE51ULL, 0xC9243995488C54ADULL, 
            0x34571DA90B0FDB02ULL, 0x1C4B0AD0C6AE01B1ULL, 0xE13E47584EA76F1AULL, 0x1D40D5594309F8F2ULL, 
            0xA11C41E26E2662ABULL, 0xA86E65465616E053ULL, 0xE8B2F46F8119E309ULL, 0xA1E4BDA2985596F9ULL, 
            0x30D1C8621F0858D0ULL, 0x642CCFCDA87E9BECULL, 0x034E79BBE55E0233ULL, 0xA848F2D14125CA49ULL
        },
        {
            0xA92DEB213D75605AULL, 0x20B432D86C5EA5CCULL, 0x4D977CDC164EFA0AULL, 0x4AED834E54D98915ULL, 
            0x47B8A4C40B095956ULL, 0xCDC0CE278DF52364ULL, 0x71E0AFA22A7C154EULL, 0xC40680940ECC6568ULL, 
            0xF21CE59A9D076A4AULL, 0x292C5576839BEAE9ULL, 0x7DD817105CD041DDULL, 0x4E4FC1BC9BA09AF4ULL, 
            0x2F0268608941218DULL, 0x5FF18035513F744DULL, 0xE0D63A4D80906614ULL, 0x06F272CC0E6C1C5EULL, 
            0x57AE237202ADE8B1ULL, 0x7FEAF46F34DFD790ULL, 0xCD973D3502D4CC64ULL, 0xBF2581B8291D53DBULL, 
            0x911828B220274CF6ULL, 0x9A404413F7E05CB8ULL, 0x38B7343DCA69B5D2ULL, 0xC1D7408A38DC3A81ULL, 
            0x6A91953472B6B52AULL, 0xCF146CC0E750B904ULL, 0xCE067FB4CC0C42E8ULL, 0x00AE44A98D819EF7ULL, 
            0xA9475809235B1E43ULL, 0xCF15832A89202E7BULL, 0x5506BA9E3212FCACULL, 0xAB41A830A6D15912ULL
        },
        {
            0x712BE9E325CBEF6FULL, 0xEB4464F995FEA4DFULL, 0xBFEC0189DCD6AAA3ULL, 0x9C7D3D3F0AF6AB6CULL, 
            0x091CE6E8548EA224ULL, 0x480DEC238CF771F5ULL, 0x486B53EEBBD3D7D7ULL, 0xAABD0B318EDF6531ULL, 
            0xF07B244E94BCD2E2ULL, 0x842DA999C139EB26ULL, 0xE2F64FFF1CC61610ULL, 0x8250C1844FFBEB69ULL, 
            0x43A9E016E537DB47ULL, 0xB05AFD10331F2A13ULL, 0xFC879B15B703042BULL, 0xDF7767C510438B14ULL, 
            0x821B8F678C040C23ULL, 0xD0F1DE0E554C5A85ULL, 0xDAC28AEF6940AB74ULL, 0x52A825124F27BB1AULL, 
            0x020D94D9C7010E2DULL, 0x6BA08447988077CAULL, 0x0698864EF10B0E85ULL, 0xC98ACE1F5546B7BFULL, 
            0xE8E8EF28ADF59064ULL, 0x42B599E3DA672EBCULL, 0x0D76C683D7377E1AULL, 0xBAC50EBE10F33D54ULL, 
            0x86CB7EBC5AAC110AULL, 0x43CE8A9FBCD98BB8ULL, 0x27E9160595251919ULL, 0x76ABF4C223C6B69AULL
        },
        {
            0x464F22D353F5B0CEULL, 0x8513F247B5C7A055ULL, 0x47B4C6C521932A43ULL, 0xAD1B9E83520898ACULL, 
            0xEFD583ECA47CBEBAULL, 0xC054EC8814EAC421ULL, 0xCC7D6962BFA19953ULL, 0x5BCF24A4B4E1C2BCULL, 
            0x6F177C72795D1834ULL, 0xB85A113F9A2D309BULL, 0x4C5D8734C57FDFEDULL, 0xEE5F3D44FF058387ULL, 
            0x314CD1C887E7CA39ULL, 0x57D95B9F4D69F83BULL, 0x09973D8886D2F1B6ULL, 0xC1506FB36A733C28ULL, 
            0xBE6844D48FB4761FULL, 0x89ADAAA16BDD2E95ULL, 0x54E693A6D1BFBCE0ULL, 0x6BDDF5B2D888D6C1ULL, 
            0xE84690F8A2225B03ULL, 0x6300BDD235CA8C8FULL, 0xD84BBDBEF3D58E09ULL, 0x31463868EB6D01E3ULL, 
            0x60220D861C6EF48AULL, 0x18B1FFDF1A46C49CULL, 0xD5B9A38C4C669979ULL, 0xA3337E0917F3F0E3ULL, 
            0x5FD421D655608AD9ULL, 0x92BD057335E6A005ULL, 0x7750EFF379F67DFEULL, 0x504E8C1C7F130EEBULL
        },
        {
            0x83EB9D0FEFF0FB5DULL, 0xB164DCEE5FA4539FULL, 0xB0B39E8D51EA582AULL, 0xAF1586EA25951EAAULL, 
            0xA2EC804477429A5BULL, 0x41D232982E43D34DULL, 0x574FD64C678E24E4ULL, 0x0BC0E20010007DCCULL, 
            0x1AD7715FC66E1779ULL, 0xE5EEFA13BB3731FAULL, 0x9FA5CB96CE7A62B4ULL, 0xBDF851B7429A7563ULL, 
            0xC98C534DE4110CF5ULL, 0xB15B43A73B11AC62ULL, 0x541FB8D44D1B1116ULL, 0x9C8354AF0AF54A55ULL, 
            0x0AEDAD47BC6D28F9ULL, 0x257FDBD12435134DULL, 0x1981DAA0587128DEULL, 0x8FD1672148112DE4ULL, 
            0x9F900B8BA5AEAA1CULL, 0x06F680A1EBEDA465ULL, 0x76A202F8F0845EEFULL, 0xCF920C064B00F3F6ULL, 
            0xB55690ABF285230AULL, 0x2275AC5EAED91B37ULL, 0xA33EA6A06220781BULL, 0x0ED29CE408433EB4ULL, 
            0xADB6A86C99288617ULL, 0x2B349F9745ACE850ULL, 0x6ABAF5948631CFB4ULL, 0x7717750F8E5D0859ULL
        },
        {
            0x5A9EF425F007500DULL, 0x5582C94E0D7A3C4AULL, 0x7718D4688F75EAD7ULL, 0xEFE4054950C0AC70ULL, 
            0xDEF4E043DFCE7BBEULL, 0x5E67CC89B3770972ULL, 0xF7E0668D67C508DBULL, 0x48C335B8772C82DEULL, 
            0x65F5DF6EF771C7A4ULL, 0x502F71B3B41EA83EULL, 0x8C5AF9538E7CB962ULL, 0x9AA23AA3D019EC69ULL, 
            0x9AE35E350D115D23ULL, 0xF9EDC85854C0EDA2ULL, 0x5C96D173F3B1862FULL, 0x3C49F963DE259526ULL, 
            0x8C7ED458E4750862ULL, 0x9AFBD87A3B293FCBULL, 0x9873620778A01460ULL, 0xCD1F7E115C4C543FULL, 
            0x90FD92825E6CA31BULL, 0xB157F11E099FE762ULL, 0x9E915F4244D97E57ULL, 0x7D82CD573DD22C1FULL, 
            0xBB1CDC6A86057AEBULL, 0xFB8A6213EB99AA9CULL, 0x4F1D29528375805BULL, 0xC688A3AC37F9DE4EULL, 
            0xB5846331C13C468DULL, 0xC828918D77109C27ULL, 0x5201A95C1A70D816ULL, 0xAC1935E5FFD8EC36ULL
        }
    },
    {
        {
            0x07296283A887AC6CULL, 0xB172A6D2A6A67177ULL, 0x24FC9AA6EB27BC4DULL, 0x840AD27E7156EA07ULL, 
            0x3049DE09EFC0CCB0ULL, 0x0BA180CDE2F273A6ULL, 0x8874FE9A3D687E69ULL, 0x77930D976387B25BULL, 
            0x1B8C4522D1CD5E0AULL, 0x7CC5C89BB9AB14E3ULL, 0x04083DB6EE07B752ULL, 0x8D5BB6A910937379ULL, 
            0xC11008202422A90DULL, 0x4951D12EEA3A388AULL, 0x6099D957D7F161F6ULL, 0x326336FED1B2FB9EULL, 
            0x5BD3D7F1AE0C936AULL, 0x05EC7B10E2204372ULL, 0xFB01E0EBBB4AFE84ULL, 0x88282CB6AB257C9EULL, 
            0xA4843B63B8684075ULL, 0x84F4C6B2D92FA097ULL, 0x1A2D08A95827B34DULL, 0x2A262CDF8FF57AEEULL, 
            0x1BE557066728CDB5ULL, 0xF656DAE30D01E32AULL, 0xAAEC9F5213A30ADAULL, 0x311C79E7F569F4B3ULL, 
            0x4B66BEFA2DCD4004ULL, 0x3AE35C84C4469193ULL, 0x6044C273F877E050ULL, 0xBDE057728CE55377ULL
        },
        {
            0x222A610AD09345B4ULL, 0xC5D45C7295EE6764ULL, 0x421638307DDD3052ULL, 0x2309554E3B639C95ULL, 
            0xFC8AF83A651B35B9ULL, 0x204C111550205E64ULL, 0xA112C12D2FCE9FE1ULL, 0x22CC55CA827B9A08ULL, 
            0xA937D4231FB7EEFBULL, 0x4D275ECB452EAB40ULL, 0x255443C0FC9012E3ULL, 0x76A2285129C4B710ULL, 
            0x81CCAED3626B87A4ULL, 0x7C1F232D914D79F0ULL, 0xFF643061EC0B0169ULL, 0x095839709A8B89C4ULL, 
            0xF52A8984A42DD25BULL, 0x366EA80E2885C15EULL, 0x73F116FDEFE59215ULL, 0x66B8DE660F4D20BFULL, 
            0x9DDA313545BE939EULL, 0x21EE478D8E332754ULL, 0x2674578E23165C26ULL, 0x21C0A0A5E5C9D138ULL, 
            0x9001A7B732A8BDBBULL, 0x4F59947019F321A7ULL, 0xF445D1203C8FB580ULL, 0x22FF17ACFC6643E2ULL, 
            0x5C8628F980AFE37DULL, 0x969DE2A4F14BDF30ULL, 0x2817C314E08E5CBBULL, 0x66AD955C5C60AE53ULL
        },
        {
            0xBD304B0B15BDA5D2ULL, 0xF5574E928BF489B3ULL, 0x781286A27E874D7BULL, 0xC609C93B6AD93196ULL, 
            0x2E0CA7F04026F910ULL, 0xEC30F08ED8C0BEFAULL, 0x80DD7A2CE88F8BC7ULL, 0x81B9728901E2AC01ULL, 
            0x9289664F90D0DA5CULL, 0x7C09B952BC02D45FULL, 0x7011C3E69C853644ULL, 0x1AC1DABCE848B585ULL, 
            0xDAF3765C02C5A0C6ULL, 0xC3E3C8FC53EAEDF2ULL, 0xE1FF45A070F02E78ULL, 0x176913F48E62F7D3ULL, 
            0x894586216CBABAD6ULL, 0xACDFEA9EE75E1D2CULL, 0xF9B6D49EF8C1077AULL, 0x9D400A2B1CE9B0C7ULL, 
            0x7FD3179D156B8EF8ULL, 0xFA07B9445C802C18ULL, 0x200B49C8AF6B4B59ULL, 0x7FB90AECD46474EFULL, 
            0x134D42E97BC3DB9AULL, 0xA1D27E27547845F9ULL, 0xBDE1FF3A9642913EULL, 0x831C1EA724A44B61ULL, 
            0xF8CA2BDA63AD7A95ULL, 0x6EEE5C1830B49B39ULL, 0x55D0E09F2A644A0CULL, 0x7602332E34A0E79DULL
        },
        {
            0x8B2B18586F92D89DULL, 0xC7DC24152A1EA4B4ULL, 0xA2789006833BE0AFULL, 0xA54D17F9061B4A68ULL, 
            0x003BF29D4454B16CULL, 0x3100F3068D528CE7ULL, 0x02B234A6F0934B79ULL, 0x27FFC81A7F10F0E3ULL, 
            0xD00B416FBC7064B8ULL, 0x4E0ACDCF6F4FDBCDULL, 0x2CDF2B8A941EA3DFULL, 0xAD664071372AF6BFULL, 
            0x9E5CBFE3ABD44685ULL, 0x46994DD9BA530A83ULL, 0xDF490B8F964E0F2EULL, 0x955D8E1D3ABEE895ULL, 
            0x1F5A449482ECB597ULL, 0xF65A78968114A7FFULL, 0x19F412DF246B0D31ULL, 0x487AF6DAA64ABB10ULL, 
            0xD998F4838969D457ULL, 0x8ED171CC56EA1830ULL, 0x810DC8A6EF0A9297ULL, 0x86D360DCFC9A2C03ULL, 
            0xE6B7188DF25F5E28ULL, 0x89612A6510B7C75BULL, 0xBAC449003EF80FB9ULL, 0x2D71BB7AD06C7B39ULL, 
            0xCFF98C90C039779AULL, 0x0D37AF06D961E129ULL, 0x3B9A28CFF1E9235AULL, 0x2451D4D41ED074D8ULL
        },
        {
            0x0E0DB607003F25E2ULL, 0x6FCB9A761E50B999ULL, 0x7221825518C88A43ULL, 0xC6D83F1F4E7546BBULL, 
            0x5D6B8D1EEB8EFEA9ULL, 0xD028557D2CC80897ULL, 0x0AD895FB73EFD7C0ULL, 0xF8B456B17C15F9C7ULL, 
            0xCA738A0177A00EA6ULL, 0x6B63960DC63EF6F3ULL, 0xE8730D556E4E1FFEULL, 0xACA0ADD5E3622F67ULL, 
            0xFDC4D197E3FE56E7ULL, 0x6EC7364D2B6C4A90ULL, 0x41E705ABC76E6561ULL, 0xCE598A3B91A381C8ULL, 
            0x464D896F786AF5ABULL, 0x95D76F21F9A5E024ULL, 0x1C0249E61AE2937DULL, 0x420A45B7AB06A294ULL, 
            0x9CF1FAC3B01D9CCEULL, 0xFE5586F5C28F3F74ULL, 0x8D0C29025CFB356CULL, 0x9D72B5DAF2A5CF6DULL, 
            0x990657AD9A137E69ULL, 0x3AB6ECAAAB391D68ULL, 0x58E2E5526071AA33ULL, 0xE24F08E5CC62514CULL, 
            0xFE09A85287D6A63DULL, 0xA4DEE00B4AE77B96ULL, 0xD58D4EF3973A32BDULL, 0x0C4271A33C0FE206ULL
        },
        {
            0x98FAA5D5464A91DCULL, 0x1E1529896D23DAF9ULL, 0x4C4C4CEDD597C19EULL, 0x34064270FBED0904ULL, 
            0x2712EAFEA2BC8BEBULL, 0x9A6FBE16E6E85891ULL, 0x3D1D499439C30673ULL, 0x1B8F0B783F99B651ULL, 
            0x01669EA09EC4CB80ULL, 0x54EDFD44F09295A9ULL, 0x443ED2F6F9D4F581ULL, 0xB18516C0EE29CBBEULL, 
            0x5F7BB3635E12CCFBULL, 0xDC3B85E14C5C1748ULL, 0xC3C93E9A1C010624ULL, 0xF74DD299D732C234ULL, 
            0x89FB1D05B59FA6DAULL, 0xC867A5A0A5DBC2EEULL, 0x835CADB2477946E9ULL, 0x5E1E4F85D52111C4ULL, 
            0x92C40781A3F68E4DULL, 0x6E9686077A08EA22ULL, 0xF08E336A01332077ULL, 0xE295BFB6F8752A12ULL, 
            0x6080D93ED228A59DULL, 0xC6BED32F6A5A92F2ULL, 0x95BB6C649EAFF838ULL, 0x4341FA3E6064213AULL, 
            0xD86B3AF47D197841ULL, 0xC7A92225A7875261ULL, 0x56000F84E03DAED3ULL, 0xE7342ED09B95DC7AULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseFConstants = {
    0x40B1E40507D5201AULL,
    0x5C176BF1313E6FC6ULL,
    0xAA8C07AE88B124FAULL,
    0x40B1E40507D5201AULL,
    0x5C176BF1313E6FC6ULL,
    0xAA8C07AE88B124FAULL,
    0xC19940DC02FFAC3CULL,
    0x91C2BA99941B4E2CULL,
    0x3B,
    0x27,
    0xA9,
    0x3E,
    0x4F,
    0x09,
    0xB9,
    0xD5
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseGSalts = {
    {
        {
            0xC08BA3C5FFF6DDCBULL, 0x89AB99B56E7BB41CULL, 0x3332FB30B73E3641ULL, 0x73AAD56BF95F3E23ULL, 
            0x6C028282EBCD0BA7ULL, 0xE73E9488BD16F5F1ULL, 0xCC4309475C13819CULL, 0x9132454A2EC7F570ULL, 
            0xE0071D04535C65DEULL, 0x3F7A5F588B20DAE5ULL, 0x839BB49801F96F55ULL, 0xAF1B6F70149E40BBULL, 
            0xA0854D5BBBA106AFULL, 0x42D4A5F160FF30CCULL, 0x2FB0D0F1094FE939ULL, 0x713E30C15C91A666ULL, 
            0xB85A68E16A93C3A6ULL, 0x592B15BA8426C284ULL, 0xA7F066F7D792ACB6ULL, 0x16E83756E7EEF39DULL, 
            0x68372FD098EFCDCDULL, 0xCE639D215C019644ULL, 0x184D09512E01E13AULL, 0x31880CEE6BD553A6ULL, 
            0xCC6C7E061EB17CB0ULL, 0xA1C08A728804010DULL, 0x6E0DA8ACE6F00E8DULL, 0xAE30418D692AC1A5ULL, 
            0x25BDCA40EB1D167FULL, 0xBDC0379AA3B57A6DULL, 0xE1F8FDFE03B9D0B3ULL, 0xD7E4E66B6F8685B6ULL
        },
        {
            0x3DDE4CA03CA85260ULL, 0x733154EA002FD059ULL, 0xA6AFC2684D884698ULL, 0x654FC5399631AD07ULL, 
            0xD79811085C9EA800ULL, 0x75D98E757E037E75ULL, 0x850EFE30389CBB5FULL, 0xC145D950522E33DAULL, 
            0xF07A31D6540A7745ULL, 0xC25DAC3A89D2D79FULL, 0xED69DEE9C4DEEED4ULL, 0xC11454F1E03F1CA9ULL, 
            0x140E4510E74FCB24ULL, 0xA1C583D706B66302ULL, 0xC4FF36D82BE21A01ULL, 0x94B6111603D3D2D5ULL, 
            0x5678CAA5B441186EULL, 0x7FE9AC622731B71DULL, 0x2B3CC2CAB3D8B38FULL, 0xED7CFC89248A8F29ULL, 
            0x339403611EC769C1ULL, 0xC6A44480C2229411ULL, 0x0DB184C1C6347C57ULL, 0xCC4573CC910C0EF8ULL, 
            0x189B85D21BE02FB7ULL, 0x21D179429C63C088ULL, 0x2A025E95051D2213ULL, 0xF50924313286DF3FULL, 
            0x9402D6E26C5E9E5EULL, 0xB58C1D837D95052AULL, 0xFAA61694EB047513ULL, 0xC32F9522933601D4ULL
        },
        {
            0xCE3EB9C22BA437B9ULL, 0x4B323E3224F62C11ULL, 0xC02B7DED2570F4D1ULL, 0x6E8CCACD47F191D2ULL, 
            0xBE5E83E54A4A3731ULL, 0x5453F7AC0C713219ULL, 0x5241FB9EDB254FACULL, 0xB35CB666DD9E687CULL, 
            0x4D88260E621B99FAULL, 0xABA51A3272A1CCFBULL, 0x745B97935B56C449ULL, 0x99CE86C57D670312ULL, 
            0xD5E4C062CFBD9AABULL, 0xEEC4C593055D8820ULL, 0x3428DDCC99B67AE6ULL, 0xC8CF4C50655FBF21ULL, 
            0xCB4356F7E9FC2623ULL, 0x49F0A11FF17409B3ULL, 0x48E571B69937F228ULL, 0x6C5AF7231BEC280BULL, 
            0x6792B7DEB7CA6B7FULL, 0x47E0EE079F1CCD25ULL, 0x39884BD0CB3E9A3AULL, 0xE5E194066AED36A8ULL, 
            0x314DA67256F084ACULL, 0x2EFA4BBFEA95A728ULL, 0xCF6997642627E12BULL, 0x9C04F1BAC89E354EULL, 
            0xD2696BEF5890B188ULL, 0xA25C2DF823F852BDULL, 0xD14561CCC3E4B982ULL, 0x54482898191FC6E4ULL
        },
        {
            0x5B3A8F8051F10333ULL, 0xF900848EAD0490A1ULL, 0x373E0F9C9A35E5EFULL, 0xC1BF0B385BAD5EB9ULL, 
            0xC76400940B06BE3DULL, 0x12A4CE0A21B6FBC4ULL, 0xE1D95580E0BE9D9DULL, 0x5EC0C20B8E71AE9DULL, 
            0x6C2767B1A4B7A5EFULL, 0xB765CD2F24756110ULL, 0x93D042E1877ABB5AULL, 0xE7042B50D951DEBFULL, 
            0x0E8466D4C6911E26ULL, 0x8633DED3EB88DD29ULL, 0x136D91C4DBFBE154ULL, 0x46FF6AA67518B68AULL, 
            0x9C3C77C298D12583ULL, 0x6307A5B13832427BULL, 0x8633CE7E62EAFC0EULL, 0x6101150C9830977BULL, 
            0xA24A5748601482BFULL, 0xA8B92659C23E3C02ULL, 0xFE66F0A0096745B1ULL, 0x00DECC09E4382934ULL, 
            0xC38C6769A0C02A0FULL, 0xA9D9E7E255F49DBBULL, 0xB30B0B0DF9DB7FF5ULL, 0x6B24802D5C7A94C7ULL, 
            0x6FD6D27258D0AA14ULL, 0xA0D0CA95A1609D81ULL, 0x0DCC8ABCF68035F9ULL, 0x06505178F3EBE901ULL
        },
        {
            0x9777C62F307995ABULL, 0x60E7A720190DCF23ULL, 0x19CEAF35CCAEF4C4ULL, 0x6DAA010483F3F2FCULL, 
            0x8EB7E151DFE7BED7ULL, 0xCF9E25F201AF352AULL, 0x3AB9FFE3310CE000ULL, 0x3334DFE41993BE6CULL, 
            0x08974E119416DABDULL, 0x0691517D1E753234ULL, 0x96D2FB516478AEC8ULL, 0x70C189F902A9D704ULL, 
            0xFD396510B4CC4F30ULL, 0x53D37D15392D8CD9ULL, 0xFDA00F8E76E815D4ULL, 0x6FA1D4F4A41B0312ULL, 
            0xA5501E2404A877B0ULL, 0x06B9214F647660FCULL, 0x8FCEDC0B42EECDBCULL, 0xE49AB4FFC6295C2DULL, 
            0x749A971B06D037B9ULL, 0x49113464F8124F72ULL, 0x4A929E1B24E38708ULL, 0x3251F3E8F8E13046ULL, 
            0x6BAABDBF1E4F4324ULL, 0x0B1F0048F6F9EAA9ULL, 0xA00AAFC00FFC323DULL, 0xDE4F9DA65590EF3BULL, 
            0x8A4ED0BB1927C471ULL, 0xBB65697DF7FBD7D5ULL, 0x17AAC386E77CCE4EULL, 0x0852C7F4CBFEC70CULL
        },
        {
            0x70F00F499A1CD407ULL, 0x7184FFBC0DE2BCC1ULL, 0x75BC001FB4E2564AULL, 0x930504F01CD8B95AULL, 
            0xDA8AF1A771054B32ULL, 0x0F8B88305579AD21ULL, 0xFD76E79E50BF15CAULL, 0x37179F485859AC96ULL, 
            0xDA5ABB3E8A9CD89FULL, 0x523BD872540F9094ULL, 0x0C534C3C87054A94ULL, 0x22F8525F05D94FB5ULL, 
            0xA70427FCDBB517A3ULL, 0x81398D7C15BF5D40ULL, 0x8FFE67259D7E43D8ULL, 0xCBE9849A1037445FULL, 
            0x1A1003372BFDA193ULL, 0xA72638FC46692CB8ULL, 0xA040E9B0FA4A756AULL, 0x865EAF7711C13E10ULL, 
            0x3D54514E74F9E0D1ULL, 0x6D73D88B98C043FFULL, 0x9B21BC625B8FB28CULL, 0xB6E53D87E67105CBULL, 
            0x44290777373213CAULL, 0x4B0410523B0F5770ULL, 0x25129F2BF6F25DA6ULL, 0x4C4A09DFF8891B58ULL, 
            0x2CB5A59CE5B77AABULL, 0x6B327C80811E8D52ULL, 0x4A47F055C6D8ED18ULL, 0x3FCCA5263E681C88ULL
        }
    },
    {
        {
            0x9AFEF4CDDC5F0369ULL, 0x4F29EE80FF343B90ULL, 0x48D78D8077677B26ULL, 0x7963B5BA1A5CF284ULL, 
            0x38112BFEBD15F768ULL, 0x98F424E902089B71ULL, 0x203E29F064F746C1ULL, 0x8A24C567912606C0ULL, 
            0x6F20DEFD9F3032FEULL, 0x3B1047D3B1F702ABULL, 0x1DC5AC88D3E30308ULL, 0x515542480DEF8716ULL, 
            0x92AA22C2F1B7BA06ULL, 0x6F5D02059498F974ULL, 0xC34F8E6DAC186DB6ULL, 0xA4559C1639B72D99ULL, 
            0x72C2C8573DCCC081ULL, 0x1D0A81539A48E92DULL, 0xFC425761A1E4A0B5ULL, 0x04CBC9335CBDADFDULL, 
            0xA112F405B6DB9805ULL, 0x7ACCDFDA31FF177BULL, 0x215BF2F5B4AA80BFULL, 0x3C43374658A36DD6ULL, 
            0x9C0F141BD50C4CB9ULL, 0xFF5E47D166EA14CAULL, 0x467594FF13CA83E5ULL, 0x4A9A31E99B0F8BFBULL, 
            0x1652D0BA9A14B23FULL, 0x629AEF96364C5A76ULL, 0x125A6FD9137A6052ULL, 0x7B7D8ED68EA632D5ULL
        },
        {
            0xBABA1471962C3D1BULL, 0x415202F9F38B5AD6ULL, 0x753B4C668784395CULL, 0xA55E36281C5BB465ULL, 
            0x8A6CCA10F2A0E33EULL, 0x0809238F408D3705ULL, 0x67E55866E8D1F6AAULL, 0xF700BDAE2B686D98ULL, 
            0x29CC78298175E3EDULL, 0xDEEB841330EC7117ULL, 0x77384ED5F7C0A1C2ULL, 0xA9CB7615C6DABBC6ULL, 
            0xD11573E392965489ULL, 0x847F2C628F008F4BULL, 0x19CE8ECD1B36053FULL, 0x5DFCC5979B266F91ULL, 
            0xECBD41C0D14CCFF8ULL, 0x236EB4F4D6D9B8B9ULL, 0x01EF73C923784B07ULL, 0x1D9F7F077753A244ULL, 
            0xBC39EA05F960FCE9ULL, 0x5A64CC39D23046B8ULL, 0x77DCEA3D17A7B660ULL, 0x01408E5DCEB0DC54ULL, 
            0xE46A0C54B35B2B80ULL, 0x8DDC0604776F0813ULL, 0x4DB2CA7C9726121CULL, 0xAC3EF101B11447CCULL, 
            0xFDDA5F8898A0E0A4ULL, 0x5422AE2FB7AF0B6EULL, 0x5B9304501713514CULL, 0x45CAE293703D1519ULL
        },
        {
            0xDD7C3EC56A6A4140ULL, 0x2787343DFDA75785ULL, 0xE00F55E41D64AA1AULL, 0x67F0EA8CB23BFF05ULL, 
            0x093626A46B7B3C8BULL, 0xFCA9FAB0C23BAD73ULL, 0x5A788D869680AB19ULL, 0xC984C94656701C5AULL, 
            0xBCD65BA166C77862ULL, 0x64B977DD9E9B308BULL, 0x253300BDCBD969E1ULL, 0x24C1DCCFE30DDC0DULL, 
            0x73B88937DA744F52ULL, 0x4A48AC7FCDAF3E93ULL, 0x46E3091EC31DE264ULL, 0xDC07187009363232ULL, 
            0xE47C3368880CAA8CULL, 0x50A8A5645A1172D5ULL, 0x0F378E8A1531F208ULL, 0x2E367EA07E557263ULL, 
            0x9DD1C8ED23D235CDULL, 0xC4AAA7E57A99BD97ULL, 0xAC2F9733F9CE3D64ULL, 0x07731A2D96FB8D9EULL, 
            0x1CE18882AA73F62EULL, 0xCA911ACFD4D5F049ULL, 0x470917A4C792563CULL, 0x049CC440451BB18DULL, 
            0x8AB02720A3371D6FULL, 0xC5C696A0B413AE56ULL, 0x86A5707C43243FD5ULL, 0xC499165E08ADC7A5ULL
        },
        {
            0x756CB9B0151AB520ULL, 0xD335706C057812C6ULL, 0xA280CE35BA989327ULL, 0xD6B5A5DB6300C24AULL, 
            0x55C5FC4B6E48D025ULL, 0x32E2CD6A8B9E5EA6ULL, 0xF0FF5EF60D709932ULL, 0xBB61DDBFA312071DULL, 
            0x667EB26A50F10739ULL, 0x5F38A4816BAE04E2ULL, 0x02D5C4C1A280EF8DULL, 0xCEAFDAAB1A9023CEULL, 
            0x3B0ED25CBE41A441ULL, 0xB107867A50D6EF8EULL, 0xEA28A3CA6C25CADDULL, 0x0C242B43382581A2ULL, 
            0xA191159B15990CEAULL, 0x1CF66A618368C781ULL, 0x4DDAF868F2188EBAULL, 0xFDEB6884AD033377ULL, 
            0x017AB6C40E15AB7BULL, 0x03ECD11D254F839AULL, 0xAC22DB60F033A2FCULL, 0xE33C146C2481E5B3ULL, 
            0xA11E3DF409559B31ULL, 0xD9308B067DB83F68ULL, 0xFC07ACEDAA793789ULL, 0x49F2B4960854FD69ULL, 
            0x496073D1EBBD9AE9ULL, 0x84590E796C713507ULL, 0x784613A2EDAC45B8ULL, 0x7E7ED8774171B8F0ULL
        },
        {
            0x5CC56E0BF9F6E24EULL, 0xFA4361BF3EB395BAULL, 0xBC1843D8C7EB4454ULL, 0x05207BD3F54B3088ULL, 
            0x161477A0F273AFDBULL, 0xC8C6B7E6848BB5E0ULL, 0xDDAAEA907643A7E7ULL, 0xEFFCE4B79EB13E8CULL, 
            0x62784F48DD34522DULL, 0x85201ADC74AA7FE6ULL, 0xBB64352131DC29BCULL, 0x949FB40207256370ULL, 
            0x7743D5A84669FDEBULL, 0x36D74B9FF91A8408ULL, 0x569E0648DB5B30EEULL, 0x2B44A7DF0200CA76ULL, 
            0x99E2FD6E5970AA6EULL, 0xEE1013E44D0A3B32ULL, 0x44865600156F1EC8ULL, 0x87E9501452BB199EULL, 
            0xE31B382169BABAE3ULL, 0x9FDED26B57DEE7CFULL, 0xFB99DC76919C6DD4ULL, 0x3176FE1A39B0CAA7ULL, 
            0x971E37CB30FF1ED7ULL, 0x7F6EE7F97A3A11C7ULL, 0xB661DFC5BCF47DC8ULL, 0x3F20D2371295A870ULL, 
            0x462E41E32C608BE4ULL, 0xA4CA0F43FF73F64CULL, 0xD353C869D168A59BULL, 0x3AC7497B8719855DULL
        },
        {
            0xBD12A5F29986A53CULL, 0xD793D233F135F835ULL, 0xBB0E40C7675889F3ULL, 0x5A67C184B0AB3728ULL, 
            0xDCA3595FAC416AB4ULL, 0xEA07F038326274D2ULL, 0x8069463496F464E5ULL, 0xCA1C2131BC736FA4ULL, 
            0x4A5DB5F8C4DE3CA0ULL, 0x378B832C424FEC62ULL, 0xFCE46197B735E2FCULL, 0x3695D142396E6590ULL, 
            0xA759EF827C7706F0ULL, 0xCA084824382F1B92ULL, 0x2AAB9EAF75F5F16CULL, 0x36228B44B1A6B19FULL, 
            0xFC6E972BD566670AULL, 0x2C2C25378D6A731FULL, 0x0830305F1CAC14A2ULL, 0x2AF42525EBC27567ULL, 
            0xD005877E0C19A86DULL, 0x1A304DEC0F8DCBE2ULL, 0x7E599948F446E283ULL, 0x651023B4A56F7F0EULL, 
            0x305B063973DC0EE8ULL, 0x657D362FFF7ECDC6ULL, 0x39030B32BA334D98ULL, 0x69589EF52B8BDD98ULL, 
            0xF3C0B8CCDF4FD3FBULL, 0x9105479E48EEE29CULL, 0xCCC0CA2486C7660EULL, 0x03F1E11F5FA06B9DULL
        }
    },
    {
        {
            0xE13CA623164B2D98ULL, 0xF88DF382465352D0ULL, 0xAB48F727E418EF1EULL, 0x66B7A422893DACB7ULL, 
            0xB3BBC8B8ACF8BDACULL, 0x865F6B0EEA9DFBE5ULL, 0x169A86C1B394176AULL, 0x7FA3DA23F8E52A2CULL, 
            0x91D2AFE201A33AC7ULL, 0x177DD22037DE6AB4ULL, 0xAB5FA1679401FF8CULL, 0xBFD7E47E5DF6BDDFULL, 
            0x97215319D5EC3C77ULL, 0x8C6C62F48ED9498AULL, 0xC03649A0745ABDAFULL, 0x07BE527BFDA62BF8ULL, 
            0xC60AAA90A13FFFD1ULL, 0x3197DF32A035ADEFULL, 0xFE6A7A120B8C4876ULL, 0xCB8EC031FC0D7291ULL, 
            0x84ADD89894B3B430ULL, 0x7941424934FB70BDULL, 0x03BF0444BCC3E5ABULL, 0xEDCD80BA135FBFBAULL, 
            0x5B6F0A8543DA9A06ULL, 0x62E1A656983077EFULL, 0xB35162E199FBB84EULL, 0xB3EA04B571852B9BULL, 
            0xE9E06BD6E17A7228ULL, 0x580488DC4F9747E6ULL, 0x55821A10EEF30BCCULL, 0xAD3DB28FBCE28831ULL
        },
        {
            0x26C64366795AAC27ULL, 0x7BDACB8089FE2A8CULL, 0x8DAD63B02DB19E69ULL, 0x9F760C182193243EULL, 
            0x7237570938AE4364ULL, 0x1E597D93DDDE4469ULL, 0x8ADC619970451D19ULL, 0xE9B6A7E136D3D7B3ULL, 
            0x9900DE7AAF7853A6ULL, 0x3F79AA0D064FEE77ULL, 0x3E87EDD7AF265C08ULL, 0x9BD6F34C85E2DF5BULL, 
            0x1EFE571CBFC8D5E8ULL, 0xE2FEA52A9B069ACEULL, 0x8E74EFE45A9D0656ULL, 0x7A5AFD2F3A74AF90ULL, 
            0x8A359C5519FB0DABULL, 0x13A29FF7814D1029ULL, 0x6D8054E372A4AB8BULL, 0x7C645A0288EC4E82ULL, 
            0x3529166FBE035266ULL, 0x1802FF6B74FB9C67ULL, 0x342FA65D2CA66C15ULL, 0x2F49B95407AEA76BULL, 
            0x86D4A4F2B745C368ULL, 0x7E830E03D9C02B53ULL, 0x5C44A4F8496E8D82ULL, 0x4967404555DC56CDULL, 
            0xC2D1B7926C175F77ULL, 0x735ECA40CDDFDB9EULL, 0x419C763A499821C6ULL, 0x06AFA6CEB8562766ULL
        },
        {
            0x92283D3BE5CD4DDDULL, 0x39358C8B13054A12ULL, 0x67B7BA890155588BULL, 0xD15E72657C04AA73ULL, 
            0x312D7D37BD3A325BULL, 0x91AF26B2FF1C6FB2ULL, 0xEA9012FB27452970ULL, 0x9C5DCF7F7FCB7DCDULL, 
            0x3BF2F639CBA948E0ULL, 0x788E8E9F92E9220AULL, 0x14988ECF18B420B2ULL, 0xA1699CD5ABD4D280ULL, 
            0x2F863D8C2529D952ULL, 0x26D33666D2639BFFULL, 0x4D699626457E3A87ULL, 0x3550726061F668F4ULL, 
            0xB9BC8205A2839977ULL, 0x6C687FB1B6E1D0ECULL, 0x70EE80BFF8CBF819ULL, 0x492BA2FC0ED93A80ULL, 
            0x71D8A407E3936C12ULL, 0xBB91F147E47CC43AULL, 0x38FA78B29F4A7F34ULL, 0xA6A6FE3FD789367EULL, 
            0x197CDD7A0876CCA5ULL, 0xF285BC16ACADD317ULL, 0x3AF9A729013C74D6ULL, 0x4C48E2CB0A923456ULL, 
            0x999D9E544CEFEE1EULL, 0x2C70F184CEEBB2CFULL, 0x6ACBA3566BFD6A0EULL, 0xA0904B88AD8899A3ULL
        },
        {
            0xCA2EAA8EB0977CCFULL, 0x4DF0C7A31A4F7BF4ULL, 0x0D68E234B9A9A04AULL, 0x0048467CDFA6C89CULL, 
            0x00DE24662B667D43ULL, 0x26FC12AA98D1BFCEULL, 0x36108D18C2C7F3F2ULL, 0xA45986C706510214ULL, 
            0x213EC750CD60178DULL, 0x56C4EB430D7116B8ULL, 0x86C889F206E2B4F9ULL, 0x5DE97A0106DA2999ULL, 
            0x26764356D9C5C9DAULL, 0xDDDEAFB1D148F699ULL, 0x7415650E3A397D29ULL, 0x9E9191DD7F2B7741ULL, 
            0x9FF8B4CBFAA08168ULL, 0x3EAE726070472A28ULL, 0x58340B7F36A74A48ULL, 0xCFFA011E955D1574ULL, 
            0x662BC5E89CE0C04BULL, 0x6E34EC584FC4F1D6ULL, 0x75FCA74DFCA9991AULL, 0xF6310F9B4B6BD53AULL, 
            0xFD3A36B976533E53ULL, 0x18A1B72081B8D6ECULL, 0xDF521C326D72FE9DULL, 0x56A322C37834FCD0ULL, 
            0x3A756222E3E8A906ULL, 0xA71491077C21C7FBULL, 0x24F9DB6E8718043FULL, 0x12FEB0918A113333ULL
        },
        {
            0x51C8059646C04A2DULL, 0x7ED58D1C167721BAULL, 0x8EF0742ED61083A3ULL, 0xE9E5CE35F1384416ULL, 
            0x911547173B2DD23EULL, 0xC1C6D913CB03EBF3ULL, 0x489F2FF27A7153ABULL, 0x85D96B1DD67C2A5FULL, 
            0xD9CAE333AF83364AULL, 0x19277C82939C8A0DULL, 0xB7004DEE23CA0B47ULL, 0x662C1B2E581AFA75ULL, 
            0x657499418FB219B1ULL, 0xAA9B6F881C9266C3ULL, 0xE00A9310F70CE3E5ULL, 0x4030238EE8AE4C2FULL, 
            0xF3A292E448A7B514ULL, 0xED24A3B6CE529E9FULL, 0xA8745EA9782B7462ULL, 0x67079EDE39E6FA47ULL, 
            0xF17DDFB9C02B8A37ULL, 0x35F8172FF640CA1EULL, 0xE607AFD9EE2077E9ULL, 0xB8199095F5A8213EULL, 
            0x159602F3C1E804AEULL, 0xC4109CEF3513D526ULL, 0x774D886330AD7E19ULL, 0xB54F8B639A401901ULL, 
            0x1F29D59F6DEDA54EULL, 0xED219669474A15BBULL, 0x5920A721CC962D67ULL, 0x074DD50D3EB11F12ULL
        },
        {
            0x7CFBB20DDC9A1879ULL, 0x3C78BBCFF9F72210ULL, 0x4D61C79AC31E4FB3ULL, 0x8EFE5CA4AD411E58ULL, 
            0xE3D320D836040159ULL, 0x313FCDC2F3A19162ULL, 0x719AC847BC087CEDULL, 0x13F2C30B06ABA3F0ULL, 
            0x8E8DCCE153271EC6ULL, 0x724290F69756B705ULL, 0xF61009276B30B7A6ULL, 0x27A283613E8DCC16ULL, 
            0xE5810210F8495A02ULL, 0x2A9991173FF43F41ULL, 0x03A2DB5BCAA0F99FULL, 0x790E13F37B94772DULL, 
            0x0A3D47FDD488B9F8ULL, 0x7115EB62133CC189ULL, 0x0B89BDED1B5083B9ULL, 0xE2F816E1CD47DC91ULL, 
            0x94CAF929647F385FULL, 0x49472D4C4F58834CULL, 0xD9C08F4D47E04019ULL, 0x826C14C67AE5A120ULL, 
            0x36292D7084AC7B36ULL, 0xB919E357A68AB96AULL, 0x3FFC5149C347C67AULL, 0x42CAB6FAB3E5DA47ULL, 
            0xB6463CE4EEFF8CF0ULL, 0x2EFEE7A78AD40CAFULL, 0xC6465F6331F37C9BULL, 0x2AFC3342EE498FF6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseGConstants = {
    0x1AB551B40D12F58BULL,
    0x31C8F831CB473E79ULL,
    0xA31122290F2A1CE1ULL,
    0x1AB551B40D12F58BULL,
    0x31C8F831CB473E79ULL,
    0xA31122290F2A1CE1ULL,
    0x062AA32B3855B6FDULL,
    0x973FF872BDE9976FULL,
    0x49,
    0x58,
    0xA7,
    0xEB,
    0x21,
    0x14,
    0x96,
    0xA9
};

const TwistDomainSaltSet TwistExpander_BasketBall::kPhaseHSalts = {
    {
        {
            0x20BBE3CD23C8054BULL, 0x1B991114407B2E8EULL, 0xCD1E643BC86F41C5ULL, 0xE2253F3DAE1ED688ULL, 
            0x481B536AE4F08A85ULL, 0x2D463F3BACD705D4ULL, 0x65E7C6344592D8BBULL, 0x39602373280C6D46ULL, 
            0x657F2C3A7567A8ECULL, 0xBB187D62C20E1634ULL, 0xC4ECA751A21300B2ULL, 0x20D8DD065EAD1332ULL, 
            0x8A1B874E4527481EULL, 0x9746D05120EF7BF6ULL, 0xC7CD2D90EC60D1D4ULL, 0x0D3019D6A059EF1CULL, 
            0x0658E57029BE3541ULL, 0x5D01C76343459CF1ULL, 0xF90C2B8630890080ULL, 0xD4E0FA7F9F37E9B9ULL, 
            0xC3E18390E669387CULL, 0xE5BD642F8216BDBBULL, 0x3380B4CAF0B7198AULL, 0xAEA46BA3F643B13DULL, 
            0xE38B4AA8288A8F14ULL, 0x63EA29A225850528ULL, 0xCA9807E884F8347DULL, 0x3EB1C546340EEDEBULL, 
            0x5C3546F41C5D66C4ULL, 0x2E7170796217B38BULL, 0x5D01E1FC512CEB0BULL, 0x426E3FAC12676C08ULL
        },
        {
            0x1A987A821D6CD2B2ULL, 0x4526705D2001E099ULL, 0xB641901EB9117EE3ULL, 0x665353713BD138C6ULL, 
            0x4A2E2DA284EB64CCULL, 0x1BDFA42358A06266ULL, 0x2A7262684B31CBBAULL, 0x04A84C9CB33DB327ULL, 
            0x2F42FE16623BAA76ULL, 0xC4B47584313DC689ULL, 0xC45DF42F3354C318ULL, 0xAA601C28AC319A49ULL, 
            0xB8DBB1B15A63F455ULL, 0x8C66FC3F788A176CULL, 0xCB7C42DFB31408B1ULL, 0x62D21047CF9A51EAULL, 
            0x7984333853327FB1ULL, 0xC3623B42304EF654ULL, 0xA5CDA3979E64A931ULL, 0x3BBA30F4598C4188ULL, 
            0x19012F923C11EB72ULL, 0xA921796C5E02ACC0ULL, 0x915ED2867782D3F5ULL, 0x91FF695BE82FFF22ULL, 
            0x62569F8686C62AF2ULL, 0x53B505B8DEBAC230ULL, 0x74290F59F89BE1ACULL, 0x7DD9AF5E9335AB14ULL, 
            0xE7A4AE6857742867ULL, 0x3C07F59F0F32D057ULL, 0xD83E71C7F98B6C80ULL, 0x43041B7DA3209877ULL
        },
        {
            0xA802355F9F35C43FULL, 0xEE2B687BD5A37EEDULL, 0x0B20EA981990184CULL, 0xC645836CBD6B90FDULL, 
            0x4A962C2B1000945DULL, 0xC4A2F6274A4BD1E3ULL, 0x7068BF4E06534868ULL, 0x99BAD983FA708212ULL, 
            0x7553C56FAC44BAB5ULL, 0x34E826612E45AFDAULL, 0x3AC2EB84D65EE5D4ULL, 0xFA53C8046426B95DULL, 
            0x883FAC7CA6D9C1ACULL, 0x8D69FC7983877338ULL, 0x9E86DB73CFFB860CULL, 0x17E08D6A8F3CDFB0ULL, 
            0x1357807B06D1278AULL, 0x796520FFA8F94634ULL, 0xE8A16808D20E018CULL, 0xC9F55971B7B47D12ULL, 
            0x93B1612F19360CE9ULL, 0x419A812868C126C1ULL, 0x31DD842C467C9D94ULL, 0xB1ED3C41F2C2C38FULL, 
            0xF4753F6549CA6525ULL, 0xD40AD0D420DE92ADULL, 0x29614B5911FAA010ULL, 0x966A1FE7D5FFE6FFULL, 
            0x3D265931963F98E7ULL, 0xC21FCD6C23F5636EULL, 0x095CCF504A9D9FFDULL, 0x66C8D80156A9A118ULL
        },
        {
            0x95C7E44EF46E4D86ULL, 0xA5179BB623851994ULL, 0x40F11044C44586BEULL, 0xBF9C2D5AD9F340CBULL, 
            0xE6E29DCE5E93EFB6ULL, 0xC7A83D9200979D55ULL, 0x7C20CB5CC65C83AEULL, 0xFBBC3D8C8EDDF472ULL, 
            0x3BB44E4EE5FD44B6ULL, 0x68E7E087FB99F4FFULL, 0x60875890F510D817ULL, 0xC1CC322D764AA844ULL, 
            0x174EECC76F0E72B2ULL, 0xBD57BAE171D0FBEFULL, 0x7982ED41C9FA9C33ULL, 0xDF70E76159101501ULL, 
            0xFA7E11340228E84BULL, 0x8BB008DFC46AF901ULL, 0xE552E31BC83F8BEFULL, 0xAB15410B55A1CEE4ULL, 
            0xB02147090660F3ABULL, 0x6BDDC25BBABAB2E4ULL, 0x2570BEEDF73B03F2ULL, 0x7868AE09201120F4ULL, 
            0x0456E05039ADD2D9ULL, 0x7DB1E1901A70460DULL, 0xE2A6131E9F606581ULL, 0x99A4BFD806878D39ULL, 
            0xF2B75F61C6A388BFULL, 0x6FBA15F2B42D4E1CULL, 0xB2C3CB403F74AC45ULL, 0x1FEA37EC8E939450ULL
        },
        {
            0x06EFDCE409576443ULL, 0xE481BAACCCBCE79AULL, 0x6218CFC12FDD16F2ULL, 0xCB723A3D9DBE14B7ULL, 
            0x48D6C26E0FD425EAULL, 0x0D10BE57E1FC5B7FULL, 0x55600B500D919600ULL, 0x934A98306D5247D1ULL, 
            0x0E8365E3416EBF3AULL, 0x2A0200189B73478EULL, 0xD97B05D89ECDF978ULL, 0x20069152F1CD00B8ULL, 
            0x3A9018EA1AEADE1DULL, 0x59B959AA954D2373ULL, 0x8BD38C8E2CB41A12ULL, 0x95DDEFDDDC6CE743ULL, 
            0x38A2DF95C4285D57ULL, 0x063D205BC42E73EDULL, 0xCF3752BA43F9D7DFULL, 0x28E8E7087B778F14ULL, 
            0x4E33FD4D9A634774ULL, 0xDE34ECA65EB27B95ULL, 0x022053F66FF170FBULL, 0x1AA5246051E0E895ULL, 
            0x166846085A6FCAA5ULL, 0xCC2A5FDCB38C4FCFULL, 0x22CB81317F2CAF63ULL, 0x35BF3B60CF13DA01ULL, 
            0x284DA939DB981569ULL, 0xF08B06CF8354B575ULL, 0x3658E22F1AC79597ULL, 0xFCE9797EC2255B08ULL
        },
        {
            0xD018F8A13F1E6125ULL, 0xB6EDD2AF681B90C3ULL, 0x224FD6A8767E9878ULL, 0xE074E12DF78C1885ULL, 
            0x4C4ED753574A1D2CULL, 0x69FC58886A32E754ULL, 0x9663B686D91928EEULL, 0xB5A044CE354C5D94ULL, 
            0x2FAD2A758E7C96E2ULL, 0xD7165FD605233F38ULL, 0x017EC3D558ED0B55ULL, 0x663C4C9992D19F78ULL, 
            0xDF6DDEBAD63520BCULL, 0x607074399E5157A2ULL, 0xBC8942EC4BB9298EULL, 0xC1218FF4C4F85AC1ULL, 
            0x69E86120CB87358FULL, 0x732B34F1CC0C8F7BULL, 0x47572B03421FF7CEULL, 0xF58EDDD69E0E27ABULL, 
            0x139B8AFE1ECE1C9EULL, 0x1277B160071CD47CULL, 0xB40ED48D518EA965ULL, 0xEE0F7C49A33DFE58ULL, 
            0x63E81AF973AF9B5FULL, 0x94927C7D6BE09483ULL, 0x9F931126FA904102ULL, 0xDABC0EB228488124ULL, 
            0x7A578C475A914D7CULL, 0x6AE1FF8935F85931ULL, 0x86C83C89621B6E43ULL, 0xF3B91B0258A96759ULL
        }
    },
    {
        {
            0xEC087E2EE7FDFC9DULL, 0x717B705225EF5EF9ULL, 0x23BB1CD70674DFD6ULL, 0xE783D3C37598862DULL, 
            0x831C0242E2C6E85BULL, 0x1EE74267961E7E00ULL, 0x8449CE9A93263FBBULL, 0x89DD1846D24E9045ULL, 
            0xB82AF3F5AFD0C8D6ULL, 0x025E0AA12C42C301ULL, 0xD11E4261B0E8D070ULL, 0x98227F5C1F0E16C1ULL, 
            0x26668DDA52B7BEF9ULL, 0x6ECD915E043B497AULL, 0xB4892BF72B11F857ULL, 0xA555A2E17955A4B7ULL, 
            0xD15BA8D0595EE976ULL, 0xD47F535866B9D874ULL, 0x1800463BD610C652ULL, 0xBA7A6B7DB5B11CBFULL, 
            0x58E9006CDEB52AEEULL, 0x48FCBF9BAE7ECD45ULL, 0x9EED2D272EDB6207ULL, 0x7CE3F95207D3820AULL, 
            0x4382345A003328ADULL, 0x1BCBC6E52E0562C5ULL, 0xEBEEBE700EBA0A17ULL, 0xB3A6D2B6D0BE92FDULL, 
            0x583AC8343ED8D9C1ULL, 0xAF1C9B417E0C29C5ULL, 0x481713C4EF7E3B62ULL, 0xFAFA7C55783EEE8AULL
        },
        {
            0xCD8B875344BFC18AULL, 0xAF95CEBCCF13C9DAULL, 0x2EC1596E3F9A5C83ULL, 0x8DAF4AF989CEFB36ULL, 
            0xC391A922C95E3C84ULL, 0x54AE529E01FC5439ULL, 0xAAB4D8C7C1CEF42BULL, 0x5B75186C1A2E481BULL, 
            0x9D1B74FDDC196ADBULL, 0x284BE00CD665A33BULL, 0x0F50657BC1F0A117ULL, 0x308A2C5E2B541106ULL, 
            0x6155F2918E2095BCULL, 0xE8FEF45F2BFB2CFFULL, 0x1F99F2D73C1FBF61ULL, 0x12183DA4DFE41C6BULL, 
            0x39D11B0300680B68ULL, 0x1B5A5A2AE9822FD8ULL, 0x8E67702E13989F3FULL, 0x9157CEE86A25F617ULL, 
            0x4AB9600EA49E0FC4ULL, 0x96830C2591B564EEULL, 0xAD892E251BAA2570ULL, 0xFEB6EA31C291C508ULL, 
            0x0419F7DE3F55379DULL, 0xFBCEADC39A9041EAULL, 0xFAD45520B9FFCCE9ULL, 0x387787DDD2555F57ULL, 
            0xBDE027FA9A69B8BBULL, 0xAD588CFD2AB6BCAEULL, 0x9A31AF7216326AE9ULL, 0xCAEA83780A32DDF4ULL
        },
        {
            0x004A045A2D71968CULL, 0x14D54DE0F3392F1FULL, 0x56AEE9F12ACAA6F8ULL, 0xC1D39FF6BA63A8ECULL, 
            0x6005BB79176CB856ULL, 0x600D93502B8941BEULL, 0x18A6BCE1106D0617ULL, 0xCC4CEA8DB6F0ECB3ULL, 
            0x8CF07B2C434E8E6FULL, 0xFEA12D8395696138ULL, 0x14154D367E53297CULL, 0x9F2A309FCFB75C5FULL, 
            0xE7158B2B06507486ULL, 0xF79C35CE537E4172ULL, 0xC4EF23446D5DE45BULL, 0xE73D2EF574C97345ULL, 
            0x4075161405386E9DULL, 0x1737B6E896D1ADFAULL, 0x8F0B3A5FADA62FB3ULL, 0x7720DA1FFBB58BB3ULL, 
            0xA92A6D90899221DAULL, 0xE70CC82702EB0E1FULL, 0x68686EA92B93DAC4ULL, 0xD9012680A35ABF21ULL, 
            0x61507BE10FD3595BULL, 0x697550D1425D2DE8ULL, 0x824819D08C049DBDULL, 0xF34D4390A68150D0ULL, 
            0x668245F91C85928DULL, 0x6B519601593CD045ULL, 0x252C11DC7E60D7FAULL, 0x32FB356AFE48C0DAULL
        },
        {
            0x22135458B482128CULL, 0xB507A4B344512645ULL, 0xC1AEBE9EA024D876ULL, 0xCF1833E3003502F1ULL, 
            0x6AF4FA57B891727AULL, 0x3F978061A5F3BD7DULL, 0xAAC2A4543CD043CEULL, 0x539B8D6DFA42068DULL, 
            0x829885ABE045A872ULL, 0x60476FE1D80E2DFFULL, 0xD05C5F667161BB3BULL, 0xF6984F846FCD228FULL, 
            0xB9F065E63DB29A50ULL, 0xA1061570E40FB7A7ULL, 0x7797CCAA8437168DULL, 0xADB150899AD23E21ULL, 
            0x22837932F6D95C1AULL, 0x4A21878E55D58AACULL, 0x639F49A50BCB55CFULL, 0xD0A307BFE9449D2AULL, 
            0x4C77350A712C5A3CULL, 0x1CDC8FC7B4026F1FULL, 0xFEE31DBE35F88498ULL, 0x674636B2BC46EE2FULL, 
            0xCB57F1E24B5A2993ULL, 0xE51102254F6A5F1FULL, 0xDAEB90F826F5331AULL, 0xF118864E3CA21DBEULL, 
            0xA6D38C6565215848ULL, 0x8A73C8355CB858B6ULL, 0x22E426CDEEB86A4BULL, 0x42E8CE10DACDC316ULL
        },
        {
            0xCA0DBEA530470F7AULL, 0x7442B75C176770BFULL, 0x3CCA4F3CDAA56BF3ULL, 0x2F621E06209F754FULL, 
            0xFF171000BB07A835ULL, 0x072CD749159E721EULL, 0x4AB7ADDEAF4D1C60ULL, 0x3ECE445D4F497ACAULL, 
            0xCB1BF4026F89D9A3ULL, 0x916BDEF1047D5F09ULL, 0x702CA83D8A7C5370ULL, 0xF2C10BED7125B50FULL, 
            0xE71F99D3838EC04FULL, 0xCDFA7D08FC335766ULL, 0x899910E05BB09B9FULL, 0xFC292E0EA2530311ULL, 
            0xF905F7A325FD24EEULL, 0x98386AB0B8B800DDULL, 0x60B18A425CD7E721ULL, 0xCA7C05B8C097485BULL, 
            0x5569A353882EE0AEULL, 0x9C9515D6CCE78A86ULL, 0xCB68F9F7FDBFC113ULL, 0xEAEAF53DCDA1641CULL, 
            0xF62E2CCE343EA976ULL, 0xF6DADA855E411890ULL, 0xA613A761429A491DULL, 0x4DFE1B7DCBF121FBULL, 
            0x64DE7168BD94505BULL, 0xD7E4FBA4DAF91CC4ULL, 0x2E62C29A4CE0F5DEULL, 0xBC926BE6FDF69DBEULL
        },
        {
            0x5AE82AB21A8F8778ULL, 0x2AFBE93ADA06C9B0ULL, 0xE715BD3A9A5C8E32ULL, 0xFA1C4A20B695BFCDULL, 
            0xD7D7240414D36784ULL, 0xEEE5CB8A7BA4039BULL, 0x525D7A8971762B67ULL, 0x809F5246E9B19FADULL, 
            0x7FC33123C5D090F9ULL, 0x720D9EE313388013ULL, 0xF9D2B033404F83B5ULL, 0xFCCF554C445BD7CAULL, 
            0x3893595CD0EBA089ULL, 0xDF066E3D6826363CULL, 0xA45A14F33094B312ULL, 0x67CCD7B7334AA063ULL, 
            0xCCCE184ED9E6DA77ULL, 0x3EEB68BFF04AB2C0ULL, 0x8FA11AF99EFA6B90ULL, 0xA6CA91FEB1811364ULL, 
            0x73A244142675290BULL, 0xCDB4CD2C66D177D7ULL, 0xF66DE164C0BEA3ADULL, 0xF157C7EA1B882994ULL, 
            0x874A58FD892BE7D5ULL, 0xC1EC0629C51A2D06ULL, 0xD9A673822107F44BULL, 0x4F866E731B643F77ULL, 
            0xFF157A04C748D8C2ULL, 0x2DD041E8D315D290ULL, 0x441D97B2505BFAF1ULL, 0x5F58E6870CA0DC19ULL
        }
    },
    {
        {
            0x23005016A01CDFDBULL, 0x9D376ECDEB279D69ULL, 0xBEF50E6B062FC51BULL, 0xDB1A5A7674AE290AULL, 
            0x6E455FE92DE8A32CULL, 0xB59643AEA989FE8BULL, 0xA13AEEAD94795BE9ULL, 0x1EAA74BFB6145EE2ULL, 
            0xA2F7BEE3E7640B5BULL, 0xAC916267BFBD64BDULL, 0x0E387C8E072FDEB8ULL, 0x1793BB652778A642ULL, 
            0x4E0C764236E74C14ULL, 0xC0CA87C9013C7EC5ULL, 0xE9EE0F34E8147798ULL, 0x3E5FC8078CB878A9ULL, 
            0x1744511D0611A263ULL, 0xD4A63E717D95A776ULL, 0xDDBDD9147E81CB62ULL, 0x76B7D80C81AAA735ULL, 
            0x5D836B1F86BF8058ULL, 0xE0912D138F41F7C9ULL, 0x7ACEF92ED7885949ULL, 0x93DB70528A7B5516ULL, 
            0xE35FD1D28A8D305DULL, 0x5F3DFB4D01867650ULL, 0xC32026EAB3B291A2ULL, 0x321354733EE2D8C6ULL, 
            0xEEDE08D8AE4ECC6AULL, 0x6460C9FEF2AA995FULL, 0xC78AED9063202993ULL, 0x9AC221A295B4DCD9ULL
        },
        {
            0x9EB0E2BB8646FA58ULL, 0x6994D0DE13D4F1FFULL, 0x976928B5E0A7FFF0ULL, 0x897F23D869FB9F82ULL, 
            0x44E94066B8FA3616ULL, 0xBFC4523B847DC3D0ULL, 0x47E222156C2A3B81ULL, 0xCCC9C25A7A5F6D23ULL, 
            0x7D1994649A1EE5C9ULL, 0x789AE8B47E84D49DULL, 0x37205660AE8388BAULL, 0x86956C73884F169EULL, 
            0x9439B5D4EC47F4D6ULL, 0xFD8BAAF86825FC15ULL, 0xF6A1AEFE9999410EULL, 0xC460D2A79C05103CULL, 
            0xDBE8015495A68543ULL, 0x80B137055F9056FFULL, 0x8223AAFC67DAEF27ULL, 0x29DAC8A6B830FBD4ULL, 
            0xE2D18B0512DBB91FULL, 0x54FD3A472448B95CULL, 0x27039B044DEB5B95ULL, 0x912A60C29424BD85ULL, 
            0xD63E32C3551E6CDCULL, 0xA8AFB0087DED090EULL, 0x9100E5294DA8FF8DULL, 0x0B3D813904AECF30ULL, 
            0x66A19FF0CA655342ULL, 0xC62095BAEAFDEE1CULL, 0xEC59992CB415291DULL, 0x44A9D9974134D26DULL
        },
        {
            0x4E99BCA43DEFF08DULL, 0x48B31274B358CC14ULL, 0x85DDE1EDFE7C3D3EULL, 0x33D6D8E70DC44999ULL, 
            0x26CAE31436F0AE76ULL, 0xEB159941E1486E37ULL, 0x30EB45CE06D77829ULL, 0x784A7B8CD5F231D5ULL, 
            0x62444738E9243683ULL, 0xE7064E39C46EE0F5ULL, 0xB4C1ADB4B8BB2186ULL, 0x338812C31EF8BC63ULL, 
            0x79BF305DDF2A221CULL, 0xE84E413BF27D4D94ULL, 0xE906BD28E99BF096ULL, 0xB8AD060BE8E36C89ULL, 
            0xC31ADF399ADF05D0ULL, 0x1EDB35787F194055ULL, 0x59BB73CDA5B48CA5ULL, 0x2668CC43BB534542ULL, 
            0xB4326EDB1EAB161EULL, 0xAA3416AC399ECBEBULL, 0x327B64FA41022597ULL, 0xC556FFE75F490BF5ULL, 
            0x832D008CF7F50279ULL, 0xD71C876A248C5783ULL, 0x6A69E7020EA0750AULL, 0x6E40F8641AC3C216ULL, 
            0xB0AA5C16FB2E5895ULL, 0xD386E2BC9A5BD563ULL, 0x944CA832ACECF783ULL, 0x217AB1EBCDAEBEFFULL
        },
        {
            0x5BF60BD7566E15C2ULL, 0x64B112F473E338CDULL, 0xB79C8D637E6FF84AULL, 0x8046B5BAC1F8E305ULL, 
            0x1C2D7254D98E9E5AULL, 0xCDD5FCD3B5511170ULL, 0x20F60D53A0307DD3ULL, 0x6ABED1ABC512C77BULL, 
            0x148357CA7CEAED25ULL, 0x1A4F75EF82EC3EBBULL, 0xCC2583ED2E94BF00ULL, 0x31BC1A2A406738E7ULL, 
            0x3FE3C1D31810A998ULL, 0x5E6E776B8F9B850CULL, 0xC78D25947D4EA1C4ULL, 0x0E96A1CF27BE0853ULL, 
            0xE1A58103F097150FULL, 0x0519EB05C6357E97ULL, 0xA799480508D737ABULL, 0x4472824F4C3CEF2DULL, 
            0x1D8E542F0A8DB161ULL, 0x3858B13B52D5305EULL, 0x2669C7F4178340BAULL, 0x9FF47B6431221825ULL, 
            0xFBA5E3B90A1ECFCBULL, 0x544C447776394BE3ULL, 0x51E95B1730CFE8E8ULL, 0x82BF3E4AD35FC0C9ULL, 
            0x1518AF8A80F49C64ULL, 0x1215781639BB8C40ULL, 0xDDC3E8202013B58DULL, 0x07FE37BC90B071AEULL
        },
        {
            0x19A9C4DF27FBE9A9ULL, 0x314434B1A57A6DE8ULL, 0x66F5D84E6AE91F59ULL, 0xB0ECA09AD2013FADULL, 
            0x739EAC0A3AAD4150ULL, 0x9C2A3126B4A60C26ULL, 0x99E049F8A0DF6FB8ULL, 0xA8724F2F63E38EE2ULL, 
            0xD37971271566D3FBULL, 0xB5C1D79523829797ULL, 0x3CF64373BDD2DD2EULL, 0xD9FEE5F18AF59AF3ULL, 
            0xCA76F1E002A26481ULL, 0xE2EB21E7174BD891ULL, 0xF1E36F1881750726ULL, 0xBBD3091A59C23160ULL, 
            0x69C05CE18810432BULL, 0x09D07E83413B108FULL, 0x105C351912E37FB8ULL, 0xF7565B447E049772ULL, 
            0xD1DB88F5131FE7D9ULL, 0xDB07A5C85B9D781EULL, 0x7C999AE8ECF61B3AULL, 0xB67F58E846CFEF3FULL, 
            0xC00E37710D208383ULL, 0x41BFD13F8DA55063ULL, 0x65080F8B212E548AULL, 0xD905C62E6B94484FULL, 
            0x5E5B69901D9AC63DULL, 0x1DC0E889B4C8D3BCULL, 0x6F2A60D61A500CBFULL, 0xE4D794302A56435DULL
        },
        {
            0x3A58421CF039BA2CULL, 0x6E2CCD6E7899C11AULL, 0x2CA3858B33D561ABULL, 0xB9856AC479CD3938ULL, 
            0xDA21538AFA389010ULL, 0xAECFC7A860C5A642ULL, 0xDF93D2FBB287AAA1ULL, 0x782955B8E36B21A5ULL, 
            0xD1E0B9069370D9DCULL, 0x6E73FD552D23FA62ULL, 0xAD18550A9FA7E922ULL, 0x08F1E223B748050AULL, 
            0x7FC624A064EF9F1AULL, 0x2A1A4A15BB3644D8ULL, 0xB2F39094BFAC10B0ULL, 0xC8A0740FD4B72E26ULL, 
            0x675BCD38021368B2ULL, 0x3EDD2AB30C526EFBULL, 0x012413585A86CE6DULL, 0x4CD1092D8862AAB4ULL, 
            0x487E9B06D36C96EEULL, 0x22535BD8B7E6C961ULL, 0x8D85FC90823E0183ULL, 0x5A6C3C066E9CB124ULL, 
            0x38598A28944C716EULL, 0x963A86C0AEE58ACEULL, 0x2ACED806CF6E789FULL, 0x972CDF6787306D00ULL, 
            0x7311E0FEFB4B08B7ULL, 0xEB23C86002135D6AULL, 0xAE761CFAF8790520ULL, 0x222B29193B464198ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BasketBall::kPhaseHConstants = {
    0x2E2B83F2E9E2F828ULL,
    0xE76EBE30D3BC5564ULL,
    0x9F9AFAE392F89A00ULL,
    0x2E2B83F2E9E2F828ULL,
    0xE76EBE30D3BC5564ULL,
    0x9F9AFAE392F89A00ULL,
    0xB5826B9C9FEB213AULL,
    0x35C43BD1908AA714ULL,
    0x1B,
    0x2E,
    0x22,
    0x36,
    0x88,
    0x2C,
    0xD0,
    0xE0
};

