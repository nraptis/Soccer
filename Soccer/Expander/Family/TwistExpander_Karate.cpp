#include "TwistExpander_Karate.hpp"
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

TwistExpander_Karate::TwistExpander_Karate()
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

void TwistExpander_Karate::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 13307794955794724921U;
        aCarry = 17368489861337611123U;
        aWandererA = 10439053661395402932U;
        aWandererB = 11688871639659780093U;
        aWandererC = 16639722471242633524U;
        aWandererD = 15703677274136256850U;
        aWandererE = 14162337850205591898U;
        aWandererF = 12739745633724943143U;
        aWandererG = 10007020565130059927U;
        aWandererH = 15556609211083980600U;
        aWandererI = 18170634316066183819U;
        aWandererJ = 17502629234807721823U;
        aWandererK = 14630816631500437291U;
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
    TwistExpander_Karate_Arx aArx;
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
    TwistExpander_Karate_Arx aKDF_A_BArx;
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
    TwistExpander_Karate_Arx aKDF_A_CArx;
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
    TwistExpander_Karate_Arx aKDF_A_DArx;
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

void TwistExpander_Karate::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 13333237690084880793U;
        aCarry = 11903073632206206430U;
        aWandererA = 17193088882233467592U;
        aWandererB = 10835530949041201771U;
        aWandererC = 17968082070743055295U;
        aWandererD = 17635320421879973723U;
        aWandererE = 13615516255337036242U;
        aWandererF = 11922951623206416173U;
        aWandererG = 9767987100797259018U;
        aWandererH = 12425071618511688433U;
        aWandererI = 16778093973928932420U;
        aWandererJ = 14761913388078079936U;
        aWandererK = 14473899453976986086U;
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
    TwistExpander_Karate_Arx aKDF_B_AArx;
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
    TwistExpander_Karate_Arx aKDF_B_BArx;
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
    TwistExpander_Karate_Arx aKDF_B_CArx;
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

void TwistExpander_Karate::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneB);
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_Karate_Arx aSeed_AArx;
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
    TwistExpander_Karate_Arx aSeed_BArx;
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
    TwistExpander_Karate_Arx aSeed_CArx;
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
    TwistExpander_Karate_Arx aSeed_DArx;
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
    TwistExpander_Karate_Arx aSeed_EArx;
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
    TwistExpander_Karate_Arx aSeed_FArx;
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
    TwistExpander_Karate_Arx aSeed_GArx;
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
    TwistExpander_Karate_Arx aGrow_AArx;
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
    TwistExpander_Karate_Arx aGrow_BArx;
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

void TwistExpander_Karate::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Karate::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 14634874790135316019U;
        aCarry = 10800356899531720052U;
        aWandererA = 12245754245497941258U;
        aWandererB = 9484704553294079893U;
        aWandererC = 15940979946233970968U;
        aWandererD = 11090846639097280439U;
        aWandererE = 11771185350851811417U;
        aWandererF = 9333654537546373659U;
        aWandererG = 17464878294627641301U;
        aWandererH = 12688767201491452886U;
        aWandererI = 17378677155194525183U;
        aWandererJ = 16869949333812419037U;
        aWandererK = 12013345226727070372U;
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
    TwistExpander_Karate_Arx aTwist_AArx;
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
    TwistExpander_Karate_Arx aTwist_BArx;
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
    TwistExpander_Karate_Arx aTwist_CArx;
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
    TwistExpander_Karate_Arx aTwist_DArx;
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
        TwistExpander_Karate_Arx aGrow_AArx;
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
        TwistExpander_Karate_Arx aGrow_BArx;
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

void TwistExpander_Karate::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 1 with offsets 479U, 4547U, 2977U, 7759U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 479U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4547U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2977U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7759U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 3, 0 with offsets 3452U, 6881U, 1989U, 1707U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3452U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6881U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1989U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1707U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 3 with offsets 4636U, 8110U, 2713U, 7200U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4636U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2713U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7200U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 1, 2 with offsets 7204U, 3571U, 4340U, 3492U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7204U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3571U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4340U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3492U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 with offsets 1774U, 319U, 1726U, 1417U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1774U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 319U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1726U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1417U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 3, 0 with offsets 119U, 1129U, 79U, 1061U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 119U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 79U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 3, 2 with offsets 117U, 890U, 1685U, 1368U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 117U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 890U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1685U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1368U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 3, 1 with offsets 1227U, 811U, 1232U, 1159U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1227U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 811U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1232U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1159U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1503U, 1472U, 1607U, 1039U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1503U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1472U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1607U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1039U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Karate::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 0 with offsets 1095U, 58U, 3251U, 4652U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1095U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 58U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3251U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4652U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 2 with offsets 5674U, 2179U, 4160U, 5647U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5674U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2179U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4160U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5647U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 3, 1 with offsets 7664U, 6889U, 1993U, 390U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7664U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6889U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1993U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 390U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 1, 3 with offsets 5400U, 7539U, 3703U, 1428U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5400U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7539U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3703U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1428U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2964U, 2537U, 4984U, 2159U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2964U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2537U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4984U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2159U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 414U, 1551U, 168U, 801U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 414U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1551U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 168U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 801U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 266U, 1982U, 219U, 332U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 266U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1982U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 219U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 332U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1622U, 1422U, 1636U, 1738U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1622U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1422U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1636U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1738U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1662U, 1629U, 459U, 981U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1662U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1629U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 459U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 981U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 [0..<W_KEY]
        // offsets: 579U, 1842U, 1911U, 1824U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1842U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1911U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1824U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Karate::kPhaseASalts = {
    {
        {
            0xD2E983D95D744DFDULL, 0xF3850BCB53535074ULL, 0xCFCEDC80B17A2383ULL, 0x5398015AF6D04D66ULL, 
            0x0481744BF4D9E27FULL, 0x68FC90D645EF21CAULL, 0x7AC9577269C0554CULL, 0xA8A6CA38610CE361ULL, 
            0x81A0E9CAA7A47666ULL, 0x5D43CC6403973403ULL, 0x1DA8DE4199BEF7B1ULL, 0x6E19C472150DA564ULL, 
            0xA707A609620D6281ULL, 0x1C063605789A94ADULL, 0x9C8716FE72C151B6ULL, 0x5B499A191D374A22ULL, 
            0xFD88474171EC0822ULL, 0x83A47EEA699C4311ULL, 0x8C476C9543D06470ULL, 0xFD32FC2A7F3AE691ULL, 
            0x70A2D829CE8A5280ULL, 0x1E3A485EB9788E1FULL, 0xB862FA373E27BE4DULL, 0x68A52AAD97182FC6ULL, 
            0xF58F872E70154CAEULL, 0x97821727E1E99405ULL, 0x4A54D2CB234A6C4EULL, 0xA7375B6E0E64DED6ULL, 
            0x44AE77EAF3DC6531ULL, 0x667E001D03D8EF36ULL, 0x25452CF98AEAFDE8ULL, 0xEA9BBC0F5ECFFBC9ULL
        },
        {
            0xB2493CC9EC1ECE2EULL, 0x96596375D96ABA61ULL, 0xC5184E0B32F0CB9AULL, 0x365B6B8BA9CBE18DULL, 
            0x2CE12BA93A28549AULL, 0xD65600A68A9A06F5ULL, 0x216E4077CA1E9A10ULL, 0x1AA98812034D8208ULL, 
            0x6C6467B66A7D6AC4ULL, 0xCBB3E58529571A74ULL, 0x69CFB2270DE68B5AULL, 0xF33B1832494E47AEULL, 
            0x3E0CF4BCE3E21918ULL, 0x6FD659B5F78CEDE5ULL, 0x2AD1203A1D420D7AULL, 0x24DDA878FB0B9FD3ULL, 
            0x16F78ACF2AC25AECULL, 0x29C87BCEE6469E3BULL, 0x0383E79C64537910ULL, 0x82F17E3DD5FB1BF9ULL, 
            0xDCDBF510005D9097ULL, 0x31CEE2F723206AC2ULL, 0x4CDD3619304E3EE7ULL, 0x2DC05CABF4CC5AE8ULL, 
            0xFA7D2845CDD556E4ULL, 0xDC1A1FA9E792067AULL, 0x74E2C432E017C923ULL, 0x92850559DC7161A6ULL, 
            0xA9EC8E4C4A61AA2BULL, 0x1F30B87A2C18C8EDULL, 0x268B4F43CC15071AULL, 0x6495ABCCF7390127ULL
        },
        {
            0x85CC772785235C7AULL, 0xA6998923F8A5D7BAULL, 0x7162EE2B975FF8F1ULL, 0x9DAB36D47EA9820CULL, 
            0x810F04828BC9E483ULL, 0xCC321366C05B8C11ULL, 0x85081EA0EDA45B00ULL, 0x838C4E92009C035DULL, 
            0xBCDE18B4E2BF5BE7ULL, 0xD9AC4DC08D3FAECBULL, 0x3A4D448B7FDF0B34ULL, 0xC275FC1446FFC6ACULL, 
            0xA478E3E9F68101FAULL, 0x96C02F57A38F8CDDULL, 0xFA07B495D2394A89ULL, 0x12D50B92EDB937C4ULL, 
            0x257CBCC07D2E499DULL, 0xD267FE52656CA7EFULL, 0x0F9A7D1894798FBFULL, 0x09BB6C03AAD4D303ULL, 
            0x57EA266A4FF57D4EULL, 0xB164BFD5C738152AULL, 0xF7F7E5AB46235818ULL, 0x446C70BF9AA4980AULL, 
            0x3C3CFC289E72F786ULL, 0xF734EC1E9F07E235ULL, 0xEAD48913A5AFA1BEULL, 0x37F3911E27C1062BULL, 
            0xD407919DC03F7C6AULL, 0xED06DB10FA434FCCULL, 0x9ED6DCC323F3AE72ULL, 0x98926403332B0F4AULL
        },
        {
            0xF3DD9096CCF0E4E4ULL, 0x295CAB55A05EEDD9ULL, 0xC335F6ACC8421C75ULL, 0x6CADAC076A1CAE16ULL, 
            0x845AAD1ADEAE9DF9ULL, 0x8ADE25150DAE76EFULL, 0xCA23FFFA1BE130F2ULL, 0x656AAC6C9470CFF6ULL, 
            0x01CBB7C97C3EE3F2ULL, 0x6A9776BDBF78493CULL, 0xF5C6FA23E9FD81E5ULL, 0x2FFF44F80444B014ULL, 
            0xD997A2AE64C882B1ULL, 0x049EA53DDFADF014ULL, 0x6C842E3271368201ULL, 0xF7FF5A97B7716186ULL, 
            0x30945916A86D5B75ULL, 0x83813B870CFE854BULL, 0x4DAC48BB013401BEULL, 0x63F9F02A3DAA584AULL, 
            0x2208797F1589A12EULL, 0xDD98DEAD51E0B8AAULL, 0xCB6EA7BC2DFB814EULL, 0x20518CED81DFF338ULL, 
            0x0A4428E5FB079DCEULL, 0x7A536AF9C25CDA9CULL, 0x60D78409E27C5F0DULL, 0x3EE6DD878A30E4FCULL, 
            0x8CC071B40DD3192BULL, 0x7181813157F7B9D4ULL, 0x3B19F04F22BA9E4CULL, 0x2D284A5CF5006048ULL
        },
        {
            0x7BB95A21537F96B0ULL, 0xC38338569761E037ULL, 0x7B2333B7A2E779E5ULL, 0xEF768EEB1982264CULL, 
            0x20E93A8EE583AC2FULL, 0x506840149CE56DE3ULL, 0xC7A7844B3DD69E2EULL, 0x7F166EDC0FA79047ULL, 
            0xFEDC8FF6B6221030ULL, 0x03AE165D3DBE7DC4ULL, 0xC5D2ACD688ACFADFULL, 0xC29A56D1A9E6EB61ULL, 
            0x81D9FE550E29A2C5ULL, 0xDB985889A06E5EADULL, 0x804271ED9130AA5AULL, 0xB51943A41A0CB852ULL, 
            0xA2752EF0C2B168DAULL, 0x31FFCA212BC7029FULL, 0xF411306622B23C2FULL, 0x4FEDF5ED739ED05BULL, 
            0x58C9EBF265E99B31ULL, 0x0EA1340811952B6CULL, 0xBB1CE711FEA40A42ULL, 0xFC530346A5782A05ULL, 
            0x45A2CA1F5CD1E2F2ULL, 0x83FF7F47CC7A737CULL, 0xE3469CEC69753652ULL, 0x9C2769EF84D8FECBULL, 
            0x24F5A1683713CF04ULL, 0x78A494674FF1114FULL, 0x8300B3D683F06DEDULL, 0x806FCBF25E7B0AECULL
        },
        {
            0xED9A081392C6BC9CULL, 0xEF1714D23DF1AF25ULL, 0x56FAC885E23AB26CULL, 0xD6E987BE7E54349EULL, 
            0x6695C39506328EEAULL, 0x73A66587EAFEA693ULL, 0xE87C266B8D8C06E0ULL, 0x66331087AAA35F83ULL, 
            0x84D43EDE7B23E7D5ULL, 0xB249E5CDDCD2466AULL, 0x037B724749D42274ULL, 0xF05E2A3EAF6E29CAULL, 
            0xA981B5AEA51A3D03ULL, 0x47BA5178BF0030A0ULL, 0x19723D47F336EFD3ULL, 0x51564A21194ADF65ULL, 
            0x6B25567E6406A459ULL, 0xB7BC2F0467F3C80EULL, 0x6C6B9EFD5C5E06EAULL, 0x0E008076100F4E68ULL, 
            0x71DC2C30D46CFB7CULL, 0xAC882B7E4890987BULL, 0xE2A56D939574CCF0ULL, 0x16921FC3F3597BDDULL, 
            0xAA108D1B7E144B1BULL, 0x1A3A47BB700E1185ULL, 0xA15B86D02897F33EULL, 0x23C847797D8E0AC4ULL, 
            0x1CFEAC63C80B64AAULL, 0xFBF270CCB5270038ULL, 0x0BA01EE019DFEAE9ULL, 0xFA5C08F6188A276CULL
        }
    },
    {
        {
            0x743B2BE438C26A60ULL, 0xE15411B3343B8A85ULL, 0x2A6B52FC200A40F5ULL, 0x5F8D1810EA388930ULL, 
            0xC11BF7AF184FF7BEULL, 0x47AB41DB9DDAB810ULL, 0xA685A7195FE317B4ULL, 0x3276A28F331A55EDULL, 
            0x66F52F6F417BB690ULL, 0x6BE8C328E3342BD5ULL, 0x161D6CF3D583878FULL, 0xB291F7D4C488D24DULL, 
            0x2B364F5182DEAF6DULL, 0x8CBC724193E42B18ULL, 0x0732FF19EF871249ULL, 0xBF93D64FDE67BDACULL, 
            0x208535DDB26943D5ULL, 0xF153DA3DF1029BCBULL, 0xD66B39A36E1755C0ULL, 0xFAA93190D4E9F1B3ULL, 
            0x197825AF71CFED00ULL, 0x01F1504F87D69E41ULL, 0x22B7F625FDC146B2ULL, 0x184FB234C8EA3EEFULL, 
            0x82A680AD0ADAE4D7ULL, 0x51FF35D959DBD16CULL, 0x993DBB02612F9580ULL, 0x950DC97CF4FF94A4ULL, 
            0xA658977542AEDB51ULL, 0x5E924382FFA0EA5DULL, 0xFF9B79579C59C671ULL, 0x695DB0F244901EB6ULL
        },
        {
            0x910188C29EBD2278ULL, 0xA8C9A0C5728B1ECFULL, 0x26BEB60C6F8D0DF5ULL, 0x4759CCA3747B88B4ULL, 
            0x04F8D87851595C88ULL, 0xEDE32E3E14D9A362ULL, 0xAC0499625248AB68ULL, 0x4AB611A7F3007A58ULL, 
            0x2ECCEED6E97DDC21ULL, 0xC96DE4CC23CD841BULL, 0x088C45A9A44CD3A2ULL, 0x78756D4A21396073ULL, 
            0x0BF458CE4AC0812BULL, 0x4B1D0025D1CAFB44ULL, 0x870471C5D4F88C67ULL, 0xB96408B88388DE61ULL, 
            0x5B3D54CACF2EA24DULL, 0x651E1E5C289B12E9ULL, 0x39CD8A1DA9743DDAULL, 0xE28740E9E5979F7BULL, 
            0x13D10FDE2FF9896AULL, 0xF293231A6D66E28FULL, 0xCEB3DB2555FF399FULL, 0x5A1EE93BFA435BCFULL, 
            0x6F476593FF9C22B9ULL, 0x3903AE9E00A4F5B8ULL, 0x57F7D401E8DAB35FULL, 0x4DDF453703549425ULL, 
            0x94CA70BA3A5C33A5ULL, 0x666DDF2D524AC2EAULL, 0x46C6BE095E9CB9E2ULL, 0x97C7C9EFA05B6616ULL
        },
        {
            0x41F1554F61147365ULL, 0x1D83E5DD4677AB9BULL, 0xA91B47A6A8BAB803ULL, 0xE6ABB71B99D561D2ULL, 
            0xC29335ABA2E886FAULL, 0xC1D7AFC2652C2446ULL, 0xBE2B286ABEC03455ULL, 0xFE1A1EFBE6374E17ULL, 
            0xBB4596A86C307076ULL, 0xE66B48D78129B961ULL, 0x3DA608948B7E8E0CULL, 0xD1BD2FF0B8E6344BULL, 
            0x28C10A3F7114E355ULL, 0xD525D3533C3F257DULL, 0xB5311CA9E196C2C0ULL, 0xC3DFC58809F0DA38ULL, 
            0x583928B6D82214DBULL, 0x3AA7418E2CDA43EAULL, 0xAA4646946CA83825ULL, 0x89DB068B7C904F5EULL, 
            0x12118E942CDA18A1ULL, 0x63E1744FFFE0ED8EULL, 0x213BD434DC898406ULL, 0x5ADA30AF5D1389B4ULL, 
            0x8262F2F30465F09FULL, 0x6FA21684A18EAD10ULL, 0x5EBA9EA05FB0B3C5ULL, 0xE332BD1192F0078EULL, 
            0x34CA1E659D8FF496ULL, 0x35E22254393EF91BULL, 0x5E88A32DE22845B1ULL, 0x74B1D6A1DDD45068ULL
        },
        {
            0x5D188C0C4403AF28ULL, 0x4817E32D2AF034A0ULL, 0x1F7A04F7F9B2CE64ULL, 0xF5FC2501B1A8200BULL, 
            0x3217510939599BAEULL, 0xC8DACDB7AE098ECEULL, 0x5A410AFC191A6765ULL, 0x45F938F4988476B8ULL, 
            0xFF847C7E47A95E90ULL, 0xA9AB73671AE6DE9CULL, 0x5F790D39AE5DE417ULL, 0x2B9BE2DF324B132FULL, 
            0x4D1A8A31A02A8FCBULL, 0xA13EDB3FB7003DF7ULL, 0xA732C4A2910885F8ULL, 0xA032670D838B8697ULL, 
            0x30F62CDA24C1FE9DULL, 0xBAE2207803C817A4ULL, 0x9ACC065A281C1670ULL, 0xB4587366F7884302ULL, 
            0x088E79709C6B406BULL, 0x84D3870AC20A13D3ULL, 0x3F1C5BA1BCC28ADBULL, 0xFC8C895523C4D602ULL, 
            0x53EB2F6C18EDC441ULL, 0xFC03F7875459D318ULL, 0x15CB5B2832C4CC7DULL, 0x29F6FC5DEBA31EA7ULL, 
            0x23074F8CA19047FFULL, 0x9A90F7A4A3566223ULL, 0xE6D5A2195B648205ULL, 0x0EDAC2500E333886ULL
        },
        {
            0x21B3D4BB48FE2A6EULL, 0xFFA10AD228F3F53CULL, 0x05A0E302DF03140AULL, 0xB9EE6F39D46AABC0ULL, 
            0xE9689B03FDFCC76FULL, 0x5E54B3DE6B0E1BD5ULL, 0x0D06C5628464A38AULL, 0xCB789F4C7892722DULL, 
            0x7F013F102553C693ULL, 0xBCCC5C66517A3CDFULL, 0x4D728FBA6B944002ULL, 0xDD4FDA417977EEBCULL, 
            0x9CAEBB92F7C20D08ULL, 0x4EEEEF41B5B00027ULL, 0xCDF09C36AAC83B8BULL, 0x7640BBB9FB4738EAULL, 
            0x3DCEE56268F22C94ULL, 0xE72E96EFFD58B33CULL, 0x82932BC8104A4545ULL, 0x54A784852DF96A51ULL, 
            0xDF5D2C96654162F8ULL, 0x7B542C795B8777C9ULL, 0x212032E546EEBF76ULL, 0x0444F308AB8DC5ADULL, 
            0x722AF97FCDA91C71ULL, 0xB7B567604329D23AULL, 0xEC821B1C38196CCAULL, 0x840D543033C82400ULL, 
            0x4FB83179194B261EULL, 0x5DD4EBA752C5F6DAULL, 0xF302425B5874C001ULL, 0xEF7653C0D42AE3D9ULL
        },
        {
            0x1E0762252FF492A5ULL, 0x683316B6F89253FAULL, 0xE5D09EB042B4E766ULL, 0x16451A2DF9A5B675ULL, 
            0x67FF95A5E6C07427ULL, 0x511E6D2FABBD6F77ULL, 0xD40EAE518B50D54EULL, 0xD72128201097DBCAULL, 
            0x960FA765FEC1F1E9ULL, 0x181695F864F0F12AULL, 0x1403E3A76E5F7764ULL, 0x616C8EA9BD10A83BULL, 
            0x7C73428C40CFCE23ULL, 0x537F9E71FA94B2E2ULL, 0x465A47971283251BULL, 0x764C10807DAD76C0ULL, 
            0xD10DB105E6F04786ULL, 0x5872900BA9E2674BULL, 0x7E562CC450A59D5DULL, 0x6A0813B3497FAB09ULL, 
            0x038E4B3E44B0A559ULL, 0x839F2E5D27B6B755ULL, 0x1AB14AF24AAE890FULL, 0x8FA4014AA585E35FULL, 
            0x8FB8C7FEFB1C0225ULL, 0xD383CFD3A6C07F50ULL, 0x399FD3ACFF84DD6EULL, 0x76B3083EB4EE4F8AULL, 
            0xE116A03D790E0D57ULL, 0x5520DC3769024101ULL, 0x294FCDA121649170ULL, 0x3C472F5537255C7DULL
        }
    },
    {
        {
            0x2ADA97A2BDA64566ULL, 0x7BBA8BFFB5812C59ULL, 0x51FF480974F70E74ULL, 0x7C585A1881732F30ULL, 
            0x7C3C1B8BA50D9933ULL, 0xEBF0E1BF6C2BF968ULL, 0x81E6D76B9B3D5BB5ULL, 0x43538790E2592505ULL, 
            0xA2088D21F1A05D0BULL, 0x133DC96F2D1B74F2ULL, 0x1B92F0CE420524F3ULL, 0x0BE446E700BC41E4ULL, 
            0x20B3D03191F7BD51ULL, 0xAD5831E17B3FAD35ULL, 0x44538E51066D4402ULL, 0xFD7199DE9C15F640ULL, 
            0x2DE8A835BF45FE51ULL, 0x5FB25371DD9B2B41ULL, 0x95D8228860977DEDULL, 0x343DEDEC80126B28ULL, 
            0xE98739EDAC1C1416ULL, 0xC2140B792EE80EC0ULL, 0xE1B5A4CE9D8E2E8CULL, 0x883975EE45E23734ULL, 
            0xB51AA394B9D3C266ULL, 0x3DCF0495F4DDCDC6ULL, 0xDA7FB3A7873A8DCAULL, 0x26D2A5E0F337CA94ULL, 
            0x26CD10DA159FC47CULL, 0x23AE87534D938FCFULL, 0x2E72007EFA15DFDCULL, 0xC17AFD18F5831458ULL
        },
        {
            0xA42CA7D922563E99ULL, 0x0197B64AFBAF6190ULL, 0xDC16205B21884010ULL, 0x9E996B9F3B12C3CCULL, 
            0xA10B7142373BF258ULL, 0x460CD502AE571612ULL, 0x588335000308E56BULL, 0x7BA9D4A0312E4D6DULL, 
            0x3D855D0902BB87D1ULL, 0x66CFC95F83F03439ULL, 0x07E4593C52BF5139ULL, 0xFF29E284940B5377ULL, 
            0x444E7BD404C70DD9ULL, 0x74099F2909D79C0DULL, 0x6A81BD67C52CCD99ULL, 0x4EEF0FFC2F7A1D01ULL, 
            0x5A400D96CE7F836BULL, 0x076FF66CD14C4991ULL, 0x1511F84F6D405346ULL, 0x8EEE5A0F37082971ULL, 
            0x5C2E0B7D7777C182ULL, 0x52B7F79573D50806ULL, 0x352235EDB616FFEAULL, 0x33503F6F22EFF12CULL, 
            0xBB407DE877C1A04DULL, 0x31016F76C82C2C6DULL, 0x4DEC400B1483C85BULL, 0x1EED122DA3E46246ULL, 
            0x76737B7113600907ULL, 0x68167024C70E11CAULL, 0x644C1814B624FD9CULL, 0xA878BB65D9841957ULL
        },
        {
            0xCE917001307719C4ULL, 0x0EC3A3635EEF74EDULL, 0x1C305D8A75C05678ULL, 0xAF5EB32446977B83ULL, 
            0xFA5F96FDF0C2E2ACULL, 0x8BDFF6E60C7A346DULL, 0xAA576583C8B8092FULL, 0x4BC544AEBF6190C7ULL, 
            0x6F2B605DC99C9128ULL, 0x68E8D1C9D5B17098ULL, 0x9D00EFDB8B14BFD5ULL, 0x386C119ACF59DD2AULL, 
            0x6D05924BFA2DAF5EULL, 0x2A62EB8859C3F318ULL, 0x253DB18362EFE9EFULL, 0xA95FBF9BC2FC8C12ULL, 
            0xBFE61C52134650E5ULL, 0x3DFF03BFF673C48DULL, 0xD57090549F8ECBE6ULL, 0xECCE326095582D87ULL, 
            0x203EE2FFD1D8FCA6ULL, 0x25526676C8492909ULL, 0xAB08F21D08E90A1EULL, 0xE2BF6185356DB2ACULL, 
            0xAF00E7621AAF63DFULL, 0x7414BDCE47A062B7ULL, 0x91DB1DBA87ECB7DDULL, 0x0282EBF3806C10AFULL, 
            0x503B05E579D16E80ULL, 0xE2E735F7B007BCB0ULL, 0x869F5B34F4EFF6D4ULL, 0xFD0684221AE8EA7FULL
        },
        {
            0x2B76B0D2BC6AB49FULL, 0x5DC46CF7535497B9ULL, 0x2030EB3859516F18ULL, 0x94FF79CED3E2A5A3ULL, 
            0x840CE5DA9246FF7BULL, 0xEB8D78F9A0FE7D19ULL, 0x302A0009D81F8F53ULL, 0x555C5F82F966BBE6ULL, 
            0xD120E5993123917FULL, 0xC66397CDA2C93E8EULL, 0x22406F242B6CEB7CULL, 0x4E7EA517676C7246ULL, 
            0x72440789D612049DULL, 0x7F4C35BA07030BABULL, 0xCCD33ABAA40AD8F2ULL, 0xD239029995B3ECE7ULL, 
            0xD62B9F5576FA9764ULL, 0xA02EFBDC73DA0D9DULL, 0x33B571B22F2A8D0EULL, 0x6DD582AF103CA20BULL, 
            0xE290727836F86F93ULL, 0x11157C893C7B1192ULL, 0x96EB1A7094C28A01ULL, 0x94838D9AC5FA21D6ULL, 
            0xA379556C029479E2ULL, 0xE68BD5828C20F28CULL, 0xE5941023330640DEULL, 0xAEA33FE3AE7BB0F4ULL, 
            0x6513CDA8158B00FFULL, 0xAFC45541AC0BD57FULL, 0x0EBFA05641B99405ULL, 0xDB5E14C997112323ULL
        },
        {
            0xEA1D4911E743126FULL, 0x58FAD477D5CC6E00ULL, 0x318C0AB36CCBB559ULL, 0x16D347C00E3DFB23ULL, 
            0xA75356C90FD08EABULL, 0xDC0A0539913F23E0ULL, 0x3297DC497C81B7FFULL, 0xBA834DA37A430188ULL, 
            0xD477FF3C832C5CD8ULL, 0x7758A6C8262B5A4AULL, 0x219EBF57E2350636ULL, 0xB4CB7F6E611BDFBFULL, 
            0xC4087CBF01A23B1FULL, 0x4740A69D4DBA2C1BULL, 0xD6189B6B076D10C8ULL, 0xA33D1341215A50CDULL, 
            0x1FA76B7C231B8017ULL, 0x912204FA9BCD5966ULL, 0x147A8619D8D7A9F8ULL, 0x9E4B237B6F85C521ULL, 
            0x5DCAB3D92514011FULL, 0x15039EC75831F49CULL, 0x09A325C72CA149D7ULL, 0x7B2A16101E1C405AULL, 
            0x452E8D979CE87D58ULL, 0x1A973F83531D7919ULL, 0x284AD1A625E739B0ULL, 0x06562A98BD1ACD8BULL, 
            0x2E80BA693E5FAD6DULL, 0xAD56967E515F760CULL, 0x778BA19812D399A4ULL, 0x7F58318611C408D7ULL
        },
        {
            0x1B4A3966CD9AA878ULL, 0x92F430132688FAE8ULL, 0xDD8A846EBEF4B58FULL, 0xC67A6ED2DFD3AAC3ULL, 
            0x670F64B5577EBAAAULL, 0x237C7E71D65E832AULL, 0x52C078F8A057DE69ULL, 0x21D65A3BA86C249AULL, 
            0x58996CB41F379CBAULL, 0x7CF069C8E5DB5CCEULL, 0x2BBE1AA4CC2AF962ULL, 0xB9FD6A884478E828ULL, 
            0x0FB66F118C7123F7ULL, 0xCF9876C7D4A679CAULL, 0xDAC74B9EF4271387ULL, 0xA093836D19FE4966ULL, 
            0x018875B68A69F1BDULL, 0x14894464A1410B2CULL, 0xE958A2743E6EEFE1ULL, 0x30A8ACB095386465ULL, 
            0x1899027A69B5925CULL, 0xC3F7683FA1621509ULL, 0x5C9A793BD435CB5AULL, 0xAE9E92282A89AB32ULL, 
            0x1337298C2B54A0D1ULL, 0x454A14A9C26B6694ULL, 0xE52A54176DBC01C8ULL, 0x42BD41D807449CA5ULL, 
            0x24F1DA9301A3E70CULL, 0x329411B31AFA9792ULL, 0xFCCA1A5EC75DA44AULL, 0x7BD590F6B34BC160ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseAConstants = {
    0x507523BD052B78F4ULL,
    0xCB7ECB0910940E45ULL,
    0x045F141C9F730987ULL,
    0x507523BD052B78F4ULL,
    0xCB7ECB0910940E45ULL,
    0x045F141C9F730987ULL,
    0xC2F6B729B15CAD8DULL,
    0x118491BEF4CD1AC7ULL,
    0xB2,
    0x34,
    0xCA,
    0x6F,
    0xAD,
    0x3D,
    0x30,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseBSalts = {
    {
        {
            0x0234A87BF444177BULL, 0x4F062658FF27CDD7ULL, 0x1D275D71D6149176ULL, 0x43849ECE0A808223ULL, 
            0x93C7F1396DD7C368ULL, 0x69B1635B3B084D5CULL, 0x8FCD02729E08E671ULL, 0x578599E22A7130A6ULL, 
            0x20B95CCBADC75A99ULL, 0xEC40AFF025A9019CULL, 0x35C7B9211ABF5E26ULL, 0xBA8BD2C775B2EE10ULL, 
            0x878F285EA17B677CULL, 0x51A139AE0F325107ULL, 0xE104B5D6D1364B22ULL, 0x8D029B75CEA78316ULL, 
            0x80E0B216C87F9392ULL, 0xD9CDA35197750FE1ULL, 0x49016F00ECF89C5EULL, 0x7399DB445E805BC7ULL, 
            0x06F0BA7B75058DA5ULL, 0x4D98978EEC224EEFULL, 0x959A9CF0A1E54DA3ULL, 0xF15C7C865155E597ULL, 
            0xA5A68AADE3EEB5BDULL, 0x58DBE7051C94BDE0ULL, 0x480349F735304034ULL, 0x16BB4CA6DCA6B80BULL, 
            0x1A05E8AAA3399C1DULL, 0xD45F15043489E103ULL, 0xF0FCC9F7619300F8ULL, 0x5A09C6C4D5E1C587ULL
        },
        {
            0xBA5B93B0B3CD772BULL, 0xA421ECD092FF34E4ULL, 0x560A49381346C83AULL, 0xDCA5E4F5D230873FULL, 
            0x98A0EFEFDF97535EULL, 0x887E3176E58C8670ULL, 0xAF78A24D24D47C62ULL, 0x691FCCF7F1020241ULL, 
            0x088EF131C3457DA7ULL, 0xD34AD5E8CDD3FC39ULL, 0x87550DDCBABFFC74ULL, 0x0B9AD958E4A56767ULL, 
            0x082A9E37A6ECAB2FULL, 0xEAF442CA87830B89ULL, 0xC16D70023726E5D4ULL, 0x58D75EC4FBA59588ULL, 
            0x30923A76F340C8ABULL, 0x7C8C4C4024821E9FULL, 0x504162B9CEBF317AULL, 0x23A828CF96834B59ULL, 
            0xACAC4A06EBFC6BEFULL, 0x7E847E5AA2CDDBE3ULL, 0x11696F2ED71D76CDULL, 0x52E559735FC7F1CEULL, 
            0x41DA15BCC9AD458CULL, 0x333F6C7707F7B120ULL, 0x5F6BB82149AE156CULL, 0xBCB373434F6980E4ULL, 
            0x3A13609BACD6E28DULL, 0x4BB6645CCF258D66ULL, 0x461F9D1F3E9870F6ULL, 0x226BA5AF813EEEBCULL
        },
        {
            0x6C6739426E24BFD4ULL, 0x6AEE977AE8B94EA2ULL, 0x0A3B7E59C1813F7BULL, 0xDFB7F925AAF8754EULL, 
            0xBE201C042EA0A925ULL, 0x413BDFA984FE9C7EULL, 0xAA0B970274E5A830ULL, 0x2DAE7D2DAFAC0030ULL, 
            0x78AD1DFB9FC2922CULL, 0x98228FA72D2F0D6CULL, 0x998DB23CA27E9F9EULL, 0x8ABA271812459AD1ULL, 
            0x011F724F013FC62DULL, 0x06CB35C2ECACAFE7ULL, 0x8E438501241E8F1DULL, 0x3E9C842191CF0B47ULL, 
            0x2496078D5AC36AADULL, 0xCBCC19B335E78ED6ULL, 0xB2955DCF822C74F3ULL, 0xE3D260553C1D9CFCULL, 
            0x951783A669E375F7ULL, 0x832F4D6742FF9C56ULL, 0x83CEC606BC042CCEULL, 0x73FD03EB63F0993DULL, 
            0x3D157C420E8079A7ULL, 0xEC82A35A527A5413ULL, 0x22794ABC8A6C5DFDULL, 0x5FF29B159C7CEE6CULL, 
            0x174FE740F4911784ULL, 0x52258F26E3B5AE09ULL, 0x3C96502F71F08052ULL, 0x2F91A2B555909EF1ULL
        },
        {
            0xF80260F7AF568641ULL, 0xC62A37C765AA11FCULL, 0xF72C07031A1C9EF3ULL, 0x1374F76F3009F6B1ULL, 
            0x10F0D52EC5E8441DULL, 0x8C109DBE0B54DB2DULL, 0x20E8E47A25B37C65ULL, 0xFE74111487A05F1FULL, 
            0xF206B9946C33857FULL, 0x529C534D7C2D8DD5ULL, 0x72B65F6703874B60ULL, 0x92ACCA9FA54DE836ULL, 
            0x474D4469A36A2C24ULL, 0x1738D34C218F8C08ULL, 0x1E2ABCFFE3AB4E19ULL, 0xF34DE5F904AE8DFBULL, 
            0x62C12D2716B328AEULL, 0x491DDA4003D7618EULL, 0x0EBDF378C489964CULL, 0xF2A25AA745101AFCULL, 
            0x52D67FF6B248676CULL, 0xC548F6CFBE5EF8D7ULL, 0xA84B39C5275748BCULL, 0xAD6ADA2537618B30ULL, 
            0x306191195A134159ULL, 0x256A3E09A91FFACEULL, 0xA0C407C937B4A49CULL, 0xBFF1248B19F16E19ULL, 
            0x2BCB6FBA36774BB0ULL, 0xC12F13D6676D8C5BULL, 0x1B214E2892830D1BULL, 0x93122253DF10951DULL
        },
        {
            0xAC40BAB513676EDAULL, 0x2543C4B20C2F27CBULL, 0x9421E193ACAA2130ULL, 0x677A0915B4F60436ULL, 
            0xD77C504875FE43C2ULL, 0xF4F24042ECD8A573ULL, 0x6ACF70050CBED486ULL, 0x77B21DE705B591C5ULL, 
            0x214DA91ECF5BB1DFULL, 0xD107B242D956F2A2ULL, 0x58DFAA18AC4EA54BULL, 0xE385E041B6DE7A3AULL, 
            0x5E3A70E318220F65ULL, 0x71AA9B17ABECF8F3ULL, 0xACFE8DFB7BA9EF11ULL, 0x09255760B61B3522ULL, 
            0xFC1865BBBC599E9FULL, 0xBA7D2CDFF277A5D6ULL, 0xDBA3F0ABC03F2F57ULL, 0x16A6216C931FA209ULL, 
            0x0C14491278018E2AULL, 0x2F211FEAE2F6B5B7ULL, 0x0272BFF82AADDC90ULL, 0x7E618122D49DE0C6ULL, 
            0x0AAEBAB1E7700C98ULL, 0x59AD5C51FE3FE103ULL, 0x1D0B0F814E99A6DDULL, 0xD756B9F4B54EAE7BULL, 
            0x2063BF528E233215ULL, 0xE342D690159EF9D9ULL, 0xF9502A9975285D59ULL, 0xA9BD510554CB7437ULL
        },
        {
            0xC5123867A7BF3957ULL, 0xB6954B6E99E16996ULL, 0xC7B6DEB875FC9F34ULL, 0x5C06FE8D1E01EDF0ULL, 
            0x1790E4D01560C69BULL, 0x1F2E0BF68DEBFB57ULL, 0x0CBCB2093E6C5722ULL, 0x204E1786916466F5ULL, 
            0x383671E88FB0D6A1ULL, 0x293E7ABB94FC340DULL, 0x3EC8E559340EF701ULL, 0x763DDCEAFB9D0BF6ULL, 
            0xC4F9C18EC90E431DULL, 0x856088CFEA8D1CFDULL, 0xE0AAC29AC3BC5A05ULL, 0xEDFC3807CF7787F8ULL, 
            0x9C97D1905460146AULL, 0x42E38F73CD7CDAB3ULL, 0x3720F764DE9EDC93ULL, 0xAB5FB6B14ACF0314ULL, 
            0x6592536BFCFF8CFFULL, 0x821BE88C98EEE5BAULL, 0xE1FA78FEDEFE569CULL, 0x5DC20881E296BCEEULL, 
            0xE3BBDA93C24FFD64ULL, 0x519F489BAAA89DAAULL, 0x56C2919DE227720FULL, 0x9F6956C54ABCAF5BULL, 
            0x04F42A3A950CA0C6ULL, 0xDA381E5FDF7FEC59ULL, 0x30827F96F0677BEAULL, 0x36442D16D682102DULL
        }
    },
    {
        {
            0x40E9B52AC4BB57F5ULL, 0x3E6A03D0309E2993ULL, 0x2D61B42DFC77A770ULL, 0xEA35312F7909631BULL, 
            0x233BF092CE5D05D7ULL, 0xD85F1E9B78841A93ULL, 0x205C667A2143AD8DULL, 0x27E8AAE10F3D8707ULL, 
            0x86E613FFCEC7F92BULL, 0x96081E169805EAB6ULL, 0xC3F9BD20E65CBD14ULL, 0xB3BA69987F743085ULL, 
            0x1AB1C757A1ED7B9FULL, 0x34BCF73C8A16C053ULL, 0xCDE689E852869D40ULL, 0x52CFF82337E5B9CDULL, 
            0x6DBAA944B2077E84ULL, 0xCB0D8078DF70328CULL, 0x133600435CF990C5ULL, 0xBAC45FE985B732AFULL, 
            0xA67B2123277DF082ULL, 0xE236C977E8675D7EULL, 0x426F2D0676DB588DULL, 0x2E72C16A85031B4DULL, 
            0x19604071B2351BB0ULL, 0x574359894987BDFFULL, 0xD2E7BD4401A4DFEEULL, 0xD7E2FD995EDBFC96ULL, 
            0xC4680E1A5A5F4742ULL, 0xC452B8A841752FABULL, 0x27E5FABA8AE3A765ULL, 0xBA1D0B5834FAA53BULL
        },
        {
            0xF013CACB3D1E5A20ULL, 0xF9047D3F494FF798ULL, 0x92B6E54936F68BD2ULL, 0xE08ED3367902B7A7ULL, 
            0x4BFE5D8F33588599ULL, 0x9B873DFDCE46C536ULL, 0x2345F0F7969EA36CULL, 0x5258DEB7F7B4CAC5ULL, 
            0x2ADC9147C3577669ULL, 0x6F1B75765BDA5BD6ULL, 0x44FC7866B1939026ULL, 0x0F4F796C8B840E45ULL, 
            0x2F4F3CF1062E26B5ULL, 0xEDD5255F0802F000ULL, 0x0291DA614AE379FFULL, 0x5C4BA90101435C19ULL, 
            0x611E578979EBA842ULL, 0x73CCA38916FD78CAULL, 0x9BC53753CBD89CD7ULL, 0x6D2D9CF8CE76B8B5ULL, 
            0x28A39EF98D5786CEULL, 0x0F106B3D6710F4AFULL, 0x279F8EAB8617FB5BULL, 0x4F045288F10ABCE8ULL, 
            0x261FEE195CFAEA36ULL, 0xDDF9998C56DF1F1AULL, 0xA632107E2555CDE9ULL, 0xB65B825BC1D12DE8ULL, 
            0x321B80B7A849051EULL, 0xB42A7E9CA548B25DULL, 0x176B67059CD63284ULL, 0x2AD95875723429F6ULL
        },
        {
            0x18EE321016FBC86CULL, 0xBE635A2128E09246ULL, 0x1A1B1D7CCF33C8A1ULL, 0x64792F3574E3FDF7ULL, 
            0x7623AED2D493B215ULL, 0xF86928DFFC2ED505ULL, 0x0F586BDFAE38AFF4ULL, 0xC92A435E4662DC08ULL, 
            0xCD882558EFBC9B28ULL, 0x3ED651AF78540465ULL, 0x4C9AC7E7C00E9205ULL, 0xF363AE8A4044F26FULL, 
            0x22BD70B4641E9EB2ULL, 0xB6BADF0DECE88EB4ULL, 0xF2FB20E3AF8FF53EULL, 0x46FCE5A24D5DC049ULL, 
            0x30EAA43B15087EB1ULL, 0xF6A24A8DCE2EEEDCULL, 0x13222DE9B90F3072ULL, 0x8A70A6C3D79C9737ULL, 
            0x530F27C15851A424ULL, 0x4BD2DF71C261CCD1ULL, 0x6AECA70E101C4234ULL, 0x9788A0F79D1FEFEEULL, 
            0x6D0DB2ACC14AE013ULL, 0x93260DEB3478F2A6ULL, 0x5124CC8DE9336EC6ULL, 0x79B6F61E7FDE8B3AULL, 
            0xAD7F51C6DA653A24ULL, 0xC197A1E60DB9CF11ULL, 0xA89370D8DEAB74AAULL, 0xE347189BD94196CEULL
        },
        {
            0xB549BA087047DF4DULL, 0x40858C998BEAC5AEULL, 0x54F0761AC2DA4994ULL, 0x6AD4C5F80EE23977ULL, 
            0x73444DC6355DCF68ULL, 0x358BE59AA45E3E1AULL, 0x46A4A021819CF8E8ULL, 0x13EF7F4D92FE8517ULL, 
            0x00362023AE5B1C1FULL, 0x5F2FAE9581E22D2AULL, 0x833DD0474A8B1855ULL, 0xAD8420D3DA2C0F23ULL, 
            0xDE042F7E30588FD6ULL, 0x716CC8F6999DD739ULL, 0x4100BA346C609943ULL, 0x0DA792F556A79631ULL, 
            0xD884B4663BA7EADAULL, 0x9B113BE92D53406DULL, 0xD86FB894195EBA30ULL, 0xE9FD67BD86E896DDULL, 
            0x9FC538D4CBA2E2A2ULL, 0x9D752ECB7CD7203BULL, 0xC992299800AB8C7BULL, 0x0F0E715AF8ACD75EULL, 
            0xBE0414460CBC3675ULL, 0x7B681230CA878122ULL, 0x5D0D88BD7A17BB38ULL, 0xB41CEB04A3FCB547ULL, 
            0x1270E9F2DD9A336EULL, 0x00A60637F8CA34EAULL, 0xFC2DFC7332608DCAULL, 0x047934262955A7C5ULL
        },
        {
            0x3D9F754507073A16ULL, 0x738F9DEBA7282CFEULL, 0x326F6122888C9C6FULL, 0x17C777ADD31D2D4FULL, 
            0x0B17E12F92871C62ULL, 0x1F003B0366B1BD5AULL, 0x46375CD369193137ULL, 0x9E68F3A44D689ABDULL, 
            0xD7130E800874AF53ULL, 0x2C169C7FC01BB660ULL, 0x091D8325D78EFF12ULL, 0xE538906EDB4ABE49ULL, 
            0x00EA13F676D82181ULL, 0x91F54B0743DEBA8FULL, 0x31372058710E3271ULL, 0xE22A82E47CD4ABEDULL, 
            0x837FB24173C7EFA0ULL, 0xD998CC0A5F8B49E6ULL, 0x40E94C9FFF4B12E0ULL, 0x11C49A180BDC8DC9ULL, 
            0x37DCF6AF3BB008B3ULL, 0x0F00D620DCD7C8D4ULL, 0x9F7EBD463E787C2FULL, 0x95260473138D7639ULL, 
            0xFF11F9485C20F1F2ULL, 0x4BA6748511D62061ULL, 0xA650CCE3F7500A6BULL, 0x1E3F45E5C8F15786ULL, 
            0x3C4B17F4E8D38058ULL, 0x17556F54D929E79CULL, 0x684ED556577F300AULL, 0xD1BFF8F8BB6DFCBFULL
        },
        {
            0x4C994DFBE6AA7E15ULL, 0x08DA038CE1F0516FULL, 0x1424D3B4411D3BFBULL, 0x645759C386C2A038ULL, 
            0x7AADE3064F59F2AAULL, 0xD5A38B77E198298CULL, 0xB5B55752E631C71EULL, 0x233BDAAF166DD3F0ULL, 
            0x044AECFCAA43114CULL, 0x05CDA4CD4B9B0627ULL, 0x7D41C75049C6C290ULL, 0xD910C45A5FC42567ULL, 
            0xA68EAFE812E217FAULL, 0x8C5A96DFFD6CF528ULL, 0x5AEB4CBCABF9A092ULL, 0xCACF06175E7F20A2ULL, 
            0x7DB735651A54865DULL, 0x508012735A6D8155ULL, 0x6A1F8F86BD3AC375ULL, 0x70D4B686A3C16C98ULL, 
            0x868C712E63BBA91FULL, 0xB8C36895F8342031ULL, 0x340BB4F2C551F5E8ULL, 0xB4393CCB7FDE9264ULL, 
            0x76424774D85E10C9ULL, 0xF4397D11FDE995FFULL, 0x7E63B9E3505301D8ULL, 0x0B7FF42CC2702F09ULL, 
            0xEF28CB706041801CULL, 0x4CD4C36C1BBA0B93ULL, 0xD4100667412DF484ULL, 0x8DB2B859DEA3C622ULL
        }
    },
    {
        {
            0x4063112EF2BC4451ULL, 0xC1F4227102B2C1D3ULL, 0xE207CD4907E09878ULL, 0x75BDBC8F0A25FCA9ULL, 
            0x2BFE65F1ECBF7D9DULL, 0xDDB0783F673874AAULL, 0x9BD19278942D40BAULL, 0x2A4B3DE119157CBDULL, 
            0xB6E7C53E515C85BBULL, 0x4D126C25E05024D2ULL, 0x0A85DC2B914B4F7DULL, 0xBA61FC6EEEC8E5B0ULL, 
            0x58C435D0D96326A4ULL, 0xA72B9CA47CC39ED0ULL, 0x91E9ADC01CDEB14DULL, 0xE6CD67B46D49694EULL, 
            0xEF32538A9BEF2B0BULL, 0x4B8C2B8C27DE5B9DULL, 0xFC181B6121B0EC61ULL, 0x59EABAF655CC34E0ULL, 
            0x15760D3E4A0B3C07ULL, 0x7E02E48C62259AD6ULL, 0x072077D21317D762ULL, 0x6ED75417070AB682ULL, 
            0x6641746C097572BFULL, 0xE76BE86EC0B4870FULL, 0xD0ECC9F828622F77ULL, 0x1652CB2B8B568AEBULL, 
            0xB72A3F5BB5D89893ULL, 0x0CC2D06FEA724412ULL, 0xD279EB9859F8A9AFULL, 0x349EA6F65D57E982ULL
        },
        {
            0x028019E3BE5CBE1CULL, 0xDA847840623CDB72ULL, 0xE31042D922743824ULL, 0x3BA3CA2D6352498AULL, 
            0x70C7B303475AE084ULL, 0x86F9A3B376A3757DULL, 0x0579E89EF45C2AEAULL, 0x8B889787B2BD5010ULL, 
            0xF91ED4EB0250FDE9ULL, 0x55B60637A974C7DFULL, 0xC0572C7D96B75188ULL, 0x6476F46549020478ULL, 
            0xEF5ACD024D8C1F62ULL, 0x67972839CDDEF5BBULL, 0x5927D4054731C651ULL, 0xD390CA0DB6DE7315ULL, 
            0x56EEEBDBBEC336D6ULL, 0x5E6EC9F72BD902D2ULL, 0x89F90DEBB12CF65EULL, 0x1A41D3BF0B786B00ULL, 
            0x92110AEE1E73167BULL, 0x0AF261B1AC509EAEULL, 0x322DE257EFF7B20DULL, 0x9500F077276764ADULL, 
            0x67EFD4A8A19E4EFFULL, 0x3CE89F391ADA04DCULL, 0x1A90067C6957B04AULL, 0xE8EC48FD5D124AB6ULL, 
            0xDA4AFFD5F39B1D94ULL, 0x6E0C249480751C24ULL, 0x374874A394F6AF43ULL, 0xCD7D8AC69CE9914FULL
        },
        {
            0xE1122937033092DDULL, 0x72DCED6801687896ULL, 0xF9BCE98667954877ULL, 0xC2A1B3A1F70A7D11ULL, 
            0x2ADBF61F117EA75AULL, 0x4FDB2870557FEB1AULL, 0x4A47C6221EDBB8D7ULL, 0xD3105A77898C3E2BULL, 
            0x9E99BC5C804B927AULL, 0x63584053E23132DAULL, 0x64A69E87D5616F2FULL, 0x082F94AA8D73F9B1ULL, 
            0x82ACDC2AB6C53712ULL, 0x4FC9E1A84D281415ULL, 0x152682E62067809BULL, 0x2B4748D210FB42AAULL, 
            0xF2A6775B906C7107ULL, 0x7A47DCB98D21BF4EULL, 0x1108FB2E9FC21495ULL, 0xC45DD4EFD26EC14BULL, 
            0x38CF9CBEBCBF29B1ULL, 0x6FA3E14670947E15ULL, 0x8B374CCB62CF9BAEULL, 0xC4E447E609414E61ULL, 
            0x609393021AF9863CULL, 0x1BACEF0F12C19B3BULL, 0x01D8F415BF771334ULL, 0xAF284BA9125C93C3ULL, 
            0x87E993A4A005B57AULL, 0x4BA118E1D9C47730ULL, 0xBC6010FC28A8A7D3ULL, 0x04A3571527813D2AULL
        },
        {
            0xBE27A5861AA9CE88ULL, 0x1472F2983326A377ULL, 0xFED6CB13DF819CDDULL, 0xE1CF18A18A158C7CULL, 
            0x60F8B77A2056862EULL, 0xFAC2CB2CAC7B785DULL, 0x78E293FEE360D751ULL, 0x11034B6C4B8AF0BCULL, 
            0xD3A9C005DC1B734FULL, 0xAF84B9940FDB027CULL, 0xEAFC857BD87C6E10ULL, 0xA126E24A32AA5344ULL, 
            0x0EBEE446B9368341ULL, 0xD9D45DE59FBE25C6ULL, 0x40EB539509B02EBBULL, 0x2E29194F5072ABDDULL, 
            0xC5FE009451805F49ULL, 0x9CE9CBC328DD75C0ULL, 0x1B697547DC92F28EULL, 0x3AA3C109FE317C5EULL, 
            0x4D00414B476BF74EULL, 0xEAC96C199C541858ULL, 0xC5F63E9F0C47AA82ULL, 0x0EF90596AAD80E61ULL, 
            0x1A2F1795DE45AFFFULL, 0x8D1C4FC2656C2774ULL, 0xA06DF5CF8352B823ULL, 0xBA0DEF3ED5AEF435ULL, 
            0x84E7A3A9037193E2ULL, 0xD26EB98FECD7CAACULL, 0x0FDB09E52F3EA7DAULL, 0xF5A12C02C54C8D5CULL
        },
        {
            0xFF864B8D9AB8EE56ULL, 0xC4A04BFC3E14A810ULL, 0x34A491F00869E24FULL, 0xBB3D6D00AB21B6E7ULL, 
            0xEBBBEE4CE3DEED32ULL, 0x81CA203D10E3C752ULL, 0xAFAF8CF17DB7A120ULL, 0x8017B1DFB078AE5DULL, 
            0x3D2D7EC0EAB11692ULL, 0x5B9012B559F31862ULL, 0x89EC077A2902372CULL, 0x7D2DE65585B790ECULL, 
            0x51E600D65D2F1F50ULL, 0x494EF8814784A36CULL, 0x4117D6A67F1D4479ULL, 0x63C0C6A5210D6DE5ULL, 
            0xC2C57F7AA7921E7CULL, 0x98353AE34EF72B88ULL, 0x6D9B342B4CC9C8F3ULL, 0xC786ECB70EC32963ULL, 
            0x916B95AC1B827610ULL, 0xEBB354DEEC14ABCAULL, 0x5C2FE11DEB31E2E5ULL, 0x227F4D755CCEF05CULL, 
            0x90BAB28AF932E6C5ULL, 0x00D73E8D55A0E71EULL, 0x5C8CBCD56A17349BULL, 0xD1C8F3F7E34CB7ABULL, 
            0xF78ACCD5D0D51869ULL, 0xDCD7CFB51836A3A1ULL, 0xE16B0147F22B8108ULL, 0xE3F1F9E55FC2D613ULL
        },
        {
            0x288C50B8340118D7ULL, 0x92F227560B26C338ULL, 0xD1C16B61BF63FFD9ULL, 0x6FC400B7F3FF9EC0ULL, 
            0x2D7BDB0B3592B515ULL, 0xAC937C42B754183BULL, 0x46FC1C029A438242ULL, 0xB59DE1F68CA734EDULL, 
            0xC8836680FB15C3A3ULL, 0x246908FF2A2B6003ULL, 0x165C9367F1B9D8C7ULL, 0x5ECE02B855711E09ULL, 
            0x48232ABCE0AE0C61ULL, 0xBF15AC48419C5E04ULL, 0x0460BFAC3B81B95BULL, 0xBCA8AFE0BEF63043ULL, 
            0x6771EDA2A2C9A43BULL, 0xEA126F9DC9329518ULL, 0x4249D86148649BDDULL, 0xED14A10FA8CF3C90ULL, 
            0x0C275A8EA2EB5334ULL, 0x40EFDC9A38347C38ULL, 0xD4A64E772A9CE3C9ULL, 0xE5C24DE501594562ULL, 
            0xC93E215096BB34BDULL, 0x075B180277300AA7ULL, 0xFAF60612C6776157ULL, 0xE7AB41E45B0A86D0ULL, 
            0x1DF032CCAF2FFC7EULL, 0xF644EB295985F611ULL, 0x96B053E2E30383B5ULL, 0xAA105FDF72892287ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseBConstants = {
    0x3FC04FF119B14FE3ULL,
    0xFBD447D493DD4C35ULL,
    0xE211E9F8E4ADD1C5ULL,
    0x3FC04FF119B14FE3ULL,
    0xFBD447D493DD4C35ULL,
    0xE211E9F8E4ADD1C5ULL,
    0xA989C0357D88484FULL,
    0x0C101A8D18C84D04ULL,
    0x6E,
    0xBC,
    0x71,
    0x38,
    0x7B,
    0x57,
    0xC8,
    0xDA
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseCSalts = {
    {
        {
            0xACEF49CAB6000AA1ULL, 0x29B447B963DB12B6ULL, 0x0C4284663DA3EE37ULL, 0x5889B91653991847ULL, 
            0x1FA6536B893923A7ULL, 0x80F97EF27F456A75ULL, 0x665BC54DA374AC87ULL, 0xEA264AAED59E3893ULL, 
            0xA29CAF857BE00E76ULL, 0x157A9B1F6BB9DBA0ULL, 0x765C873B73589059ULL, 0xC4C57BA84B7ABEB7ULL, 
            0xFEB0D7C8B6D4BC2EULL, 0xB65DA34BB4B7566FULL, 0x22B257668C91EAF2ULL, 0x41B386952ECA975CULL, 
            0x17A6ED4B5927ED43ULL, 0x063732FA4A825528ULL, 0x68C03DBD0184FC1DULL, 0x64EBF7F51B7FEFC1ULL, 
            0x37E9BB5E0639E9E4ULL, 0xA4E73933F80AEF20ULL, 0x77AAD05824095CDEULL, 0xC5B8A6E9372EE466ULL, 
            0x6941B7FF3550D14BULL, 0xFFF55262FED2D0C8ULL, 0x2820BB217CDC6C41ULL, 0x882B836965D5E5FAULL, 
            0x3F90E867599A587AULL, 0xAAA54322CCAC5E6FULL, 0xF2534C205AEE5D95ULL, 0x1406D1EFEDD38B17ULL
        },
        {
            0x1F02B6D610D62604ULL, 0xE902FB95DD27CF69ULL, 0xDD17F7168239A6F2ULL, 0x87FF60A2813D1BFDULL, 
            0x8B5268B7ED1D53BBULL, 0xED923C11F4BE68F4ULL, 0xC056D5365AFB6F62ULL, 0xE9BFD0900A3D71A9ULL, 
            0x69E16761F3BD3ED7ULL, 0x72FE140FDCF7C9C6ULL, 0x26E8243720201B03ULL, 0xD1FDF0E061824AAAULL, 
            0x305805DDB857B29DULL, 0x4A63336066EE426BULL, 0x2022AE71BDD26792ULL, 0xCA4D44B38E5556F5ULL, 
            0x5BA6E78AC62C9FBDULL, 0x50E6466E759AB0D5ULL, 0x54E282DFFC12E0E6ULL, 0x74069AE2C823D92DULL, 
            0xEE09974FFEA4FF83ULL, 0x58DE855B0C00885AULL, 0xEE6AC2F96C757DADULL, 0x696DD51F34ACECA8ULL, 
            0x4157ACBF7569EF44ULL, 0x70A14DF17334C136ULL, 0xD2F59438F70A871EULL, 0x995078F7F44047A1ULL, 
            0x551EC5222D5FC20DULL, 0x10443D7F0F77ED57ULL, 0xD61FEA34A34FFF12ULL, 0x5B572737B77A6C5AULL
        },
        {
            0xA692616670D57F96ULL, 0x9C4959B81FB19B60ULL, 0xC6213E11CF2E612EULL, 0xC27BCD9BD5094B5DULL, 
            0x50F24AEE4E69FF8EULL, 0x2948620C7CF8AB32ULL, 0xF4087FBB8272C1E1ULL, 0xA79DA1ECB878897EULL, 
            0xBFAA0BA72B55080AULL, 0x0F3062CF9A42BDFEULL, 0x98C5B01008B1B2AEULL, 0xAD2BB362A44033D4ULL, 
            0x29F7210A6AA08EFFULL, 0x3B50EB521C44D709ULL, 0x9E8768BD6F2C9888ULL, 0xF5FB07753A5CED52ULL, 
            0xED7F6F1E6B1E08B2ULL, 0x06307278914D1C75ULL, 0x0A40AFBD3647D7DCULL, 0xD99E29DC2EE4EDC9ULL, 
            0x302F8845C3409CFDULL, 0xC18F415E6E1515FFULL, 0xF3D25E3BF67CE172ULL, 0x55C603D6B7ACD415ULL, 
            0x3C7DAF66EF91286FULL, 0xA881E0A98281E2BAULL, 0x6D866CFD9C4CBBFCULL, 0x8FCB530B5D01F8DAULL, 
            0x7F0446EDB0B8601FULL, 0xE3FC679FA565CD2FULL, 0x824DC4E50BA4DA46ULL, 0x16134EB4428D50DBULL
        },
        {
            0x4502260E36A16333ULL, 0x093D0D138ECD8D1DULL, 0x3D3EE2DFBAA733BDULL, 0xE53C6202EA8C008BULL, 
            0x8B9005B451C604FBULL, 0x564ED055C4D7A6D1ULL, 0xABA952FCB338307DULL, 0xA67C594BF0937674ULL, 
            0x928AD5A3EEE24994ULL, 0x36B39F2FB275D515ULL, 0x05D6F905DB0AD518ULL, 0xBBB0CF653C53912CULL, 
            0xBAC3F48491CE8A4BULL, 0x00ECD0A97600F3A4ULL, 0x36F03CBA5FBA76BCULL, 0x1C94DF7F53461984ULL, 
            0x481C4B7AD23E4A72ULL, 0xEEFFC3930C42560BULL, 0x853DF24DEA6AA46EULL, 0xBA21BDDECC2DE79CULL, 
            0xBCF0E27A22FF802EULL, 0x2F87B176701795C7ULL, 0x6CA29C5CA56B7279ULL, 0x20577160D8535373ULL, 
            0xEDD7B96F77CF1577ULL, 0x8A00B8197F5EC06DULL, 0x151C6000EA433025ULL, 0x6BEA71C9999E3EF2ULL, 
            0x963C0EB1043015A8ULL, 0x35FD15EEC722831BULL, 0x737DB8A8C4BF3B30ULL, 0x47CFB4F41C6CE767ULL
        },
        {
            0x6F8073D5221C5F0CULL, 0xADEFC8E1F1B5F25DULL, 0x142C7C065E89CA61ULL, 0x266B9CD2861D06B0ULL, 
            0x4DFC6B48747EE662ULL, 0xBB0262405A9D522FULL, 0x39EBD1ACCC0E62B7ULL, 0x642A6133BA490650ULL, 
            0xBEC4EDFCFCEA36AEULL, 0x8B2A3848A74C5146ULL, 0x9C2C4451F76C9DC7ULL, 0x5BFDB89AA5DC1DA6ULL, 
            0x415C8B6D620DD1CEULL, 0x77658B8AEB3EB1CCULL, 0xC1894D171E8BD78EULL, 0xAFBB9C0C9E9C1B4BULL, 
            0xA8CD9FC1DEAC03F3ULL, 0x65FEBAB69A078BAEULL, 0x1C7E28BE6F12D8F9ULL, 0x35A22065CFC941B7ULL, 
            0x9DF81B04F56C2DFCULL, 0x5AA0B1614A252259ULL, 0x0538C5A15A624E6FULL, 0x3C3CF37C4C7E0469ULL, 
            0xA8D0A89DA86B0D97ULL, 0xC7F8B07FDB72B860ULL, 0x21ADCFC81F141FDCULL, 0x72CD035A9711C796ULL, 
            0x24AEE59ECFD5280FULL, 0x631CD1AC13F35F8DULL, 0x4DA2DEC8744C5847ULL, 0x42C97B70525D0DCDULL
        },
        {
            0x1EE7851181ABC8A7ULL, 0xA65E12A280E0C29CULL, 0x7DD8220CD92D8278ULL, 0x8AECAD1AAE834D9AULL, 
            0x11D2746803E86CA0ULL, 0x34E13A5F4A6997F8ULL, 0x75B6A49CDFE0DB40ULL, 0xF9BB2D7F61F84914ULL, 
            0x46480DF41CAA963DULL, 0xAAB18F963BC121FCULL, 0xF48EA6DE701AA314ULL, 0x1CEF3B01306B00CBULL, 
            0x69BAE2A4659A5321ULL, 0x9D1B08D7E1A6FDA7ULL, 0xA22E31ECD262E2ECULL, 0x344BFD52D403D386ULL, 
            0x733CE598F4388545ULL, 0xFEAA13DAD45EAE06ULL, 0xBBACD623557F0BB5ULL, 0x845473BC70FFFD58ULL, 
            0x77A3B7DF43B313FBULL, 0xC79C364496992795ULL, 0x7587949D4F476387ULL, 0x5907C6F17FE8A297ULL, 
            0x5174A9CB8BA0C830ULL, 0x537259D7F20097E4ULL, 0x977CA5FB8CF9F90DULL, 0x76484D2B0754D2EEULL, 
            0x62E3385D5402D0C2ULL, 0x24EFDC6B35666026ULL, 0x6A351E6BEE6D2264ULL, 0x827A38BCEC6E8CB1ULL
        }
    },
    {
        {
            0xCE40630961812C55ULL, 0x218BD488CACE9C80ULL, 0xC2CCDA9CBF435A54ULL, 0x5F73905FAAB8BF0DULL, 
            0xCA8342A730F89B24ULL, 0x4F4D4FC7B7710FA8ULL, 0x9E4BB62A06EFFB9FULL, 0xE3AEB2D028C09D10ULL, 
            0x559C7699EBB14271ULL, 0xDDA8248E5303A53FULL, 0x3067E514289B8B18ULL, 0xD4887CFF9FE5EB44ULL, 
            0xA25F3A3B3A6D5D5CULL, 0x8EED86C8FEACC177ULL, 0x1F0BE41C9993D1EDULL, 0x046E5056B32D6451ULL, 
            0x61CAFF987747DFB3ULL, 0xAA579E68CB3CD4A9ULL, 0xC27A8E349EF73191ULL, 0xF7B17EF16928E309ULL, 
            0x245CF02FE20F1B74ULL, 0xC9F7CAE897FF34AAULL, 0x215AE9FA0D09B2D7ULL, 0xF4F7A3A915B3155BULL, 
            0xDFC97790AFF670F3ULL, 0xBC2D51AB20B0CF98ULL, 0xFD619E5EC923EE4DULL, 0x89BBBBFCB663F049ULL, 
            0x0F636F584BA22565ULL, 0x78424563B139A772ULL, 0xA7D899FE4481B4DFULL, 0x3E8F1C5A7D3D5209ULL
        },
        {
            0x2D7CF4839ACB454BULL, 0xA53BC172FD53C771ULL, 0xA54185F93343E95EULL, 0x96F6BD15DEA340F5ULL, 
            0x6FD8E38778C2941EULL, 0x80DD2135EEBA1806ULL, 0xF2136B80C385E6DCULL, 0x61DF890E4EDBDAE2ULL, 
            0x60807839689EEF3EULL, 0xBB1AD5036DECCDE7ULL, 0x5535D43FFABA8AF2ULL, 0x551AC29BB8984D93ULL, 
            0xA071C01969C2A428ULL, 0x08D2F755D972F4F1ULL, 0xCA5BE7E1F0588DC4ULL, 0x144C6A47A9D11C32ULL, 
            0x45FF2CCDA6C5D5B8ULL, 0xD459C4403554648DULL, 0x962F8F77EB750BEAULL, 0x0C8FD57205A4C563ULL, 
            0x3E3EA848B0DE568AULL, 0x9139BAC7E96BE249ULL, 0xA51C138EB46BB656ULL, 0xF8DF16585AA54A98ULL, 
            0xF267B384A3C0CE8FULL, 0x1E4253C7119EAB97ULL, 0xEC2B20202FAF211DULL, 0xEF75D1369058299FULL, 
            0x9E909236C3FB5412ULL, 0x1455E3E9C8FC61C2ULL, 0x30A0351588E0A5C0ULL, 0x3739830DDCC0B0C1ULL
        },
        {
            0x38DFC0F7E6C5C46FULL, 0x53EA9CA7F2048C6BULL, 0xB72B90B29815847EULL, 0x41A19957F8DCB131ULL, 
            0xB6FF78F189F573F9ULL, 0x7D3C7A557D2D2136ULL, 0x20264E1751791B23ULL, 0x4B6ED4FC5959C45AULL, 
            0x30735A2A55C5EB0FULL, 0xFE7A7219BE3CB042ULL, 0xB5ED6ECEA6275DCBULL, 0xA2CAC32EABB21521ULL, 
            0xE03968C3F7F9144DULL, 0x0AB8CA8EC1A84D12ULL, 0xB27957D54B31DC39ULL, 0x50903338468C859AULL, 
            0x6172036E22F51D09ULL, 0xD9A2ED721AA94217ULL, 0xED5A14386BA9AF1AULL, 0xBAEB5C6934AED748ULL, 
            0x43A8EFE2FD1A204AULL, 0xAC5AF8498EDFF0CCULL, 0xCD81978F07B07A11ULL, 0xC317CD01C363C4D2ULL, 
            0xE90B7BCE7DA2D08EULL, 0xC267865F015A3316ULL, 0x09404511D095E8DCULL, 0xD5A557E6E80378AFULL, 
            0xE155B77E9DE2A3B2ULL, 0x01D108C4CE6CF0E8ULL, 0xF7466416BA9D37C4ULL, 0xD2B0F7256E9495F6ULL
        },
        {
            0x490F633FE1145D12ULL, 0xA6BDD3A656423715ULL, 0xDABF88AF3B63FF65ULL, 0xBE1C15953ED42C22ULL, 
            0x8BA7407D37CAD698ULL, 0x2F348FBD7BEA9336ULL, 0x11A717ACB67A43BFULL, 0xDF4EF611ABCE8D04ULL, 
            0xC17F9BBAD5E31A52ULL, 0x2082DB4C316207C5ULL, 0x1C34A42F89C0CC71ULL, 0x14AD686D989FEB7EULL, 
            0x91905A9FD0662152ULL, 0x9FC2834BB9718CCFULL, 0x9D68B5706712EF93ULL, 0x507CA7D73E7B691DULL, 
            0x83A911D33FC605AFULL, 0x7F8ADD83A82BC835ULL, 0xB3594BEFAF97429AULL, 0xC696EAF5786F48EDULL, 
            0xD968ACD009E28AF8ULL, 0x6F749E14010A55DAULL, 0xE8F0A72251AB75CEULL, 0x062DDF1ADC8996CEULL, 
            0x99E2A920CED6CAFFULL, 0x8F565ADD89479AA7ULL, 0xD360236F5F219839ULL, 0x69A21ED5EA882AECULL, 
            0xDFB12F881EB64259ULL, 0x5F90D4DEEEA092ECULL, 0x7F9D416F9FBFE5FAULL, 0x21FB3FB0F78A8E5FULL
        },
        {
            0x003144218420398BULL, 0x44BC308A7795BB24ULL, 0x8CA8E08485D6D191ULL, 0x08AB317C7FD72673ULL, 
            0xDE8FFE719791AE4DULL, 0x85E842906B1A1AA7ULL, 0xA154C78E79BA8AD2ULL, 0x09AE6832289468F1ULL, 
            0x8E6959CDA1ED6BBDULL, 0x78719606F2B26967ULL, 0x699228B308307E5EULL, 0x8C6E0EDE8BD21277ULL, 
            0xD7B9F9960A0B6ED9ULL, 0x3CA20934A55ADF45ULL, 0x1083B107157B7465ULL, 0x3CD432A035DF754AULL, 
            0xC07C99192A1BAA81ULL, 0x77D4224CBFE1C31AULL, 0xAF9293AE1F2357B7ULL, 0x2982334F091135CFULL, 
            0x61ECD76EF705865FULL, 0x7402809982958328ULL, 0xF662A440EBF75537ULL, 0x01DC5E73350F557CULL, 
            0xF398AF7E766C9F71ULL, 0x7D77553B9119F3E1ULL, 0x1F06159749B35040ULL, 0x59835FAF98FBCD29ULL, 
            0xF8D7CE2FC7A38CC9ULL, 0xE7341197DFA3CAF2ULL, 0x61745B78C032143CULL, 0x2A42551D0118EE31ULL
        },
        {
            0x86669A0685FC4CA4ULL, 0x8B83A26B7E997922ULL, 0xAD04946A40035D28ULL, 0x45A50F2C3424FCF8ULL, 
            0x958579475232EEA3ULL, 0x68F5F9EDDC393859ULL, 0xA21F1EEB51DE49D8ULL, 0x7C5BABEE862150D6ULL, 
            0x8D3FFA43695C80B7ULL, 0x58B4184E8DD01432ULL, 0xF63F3D9720AEE880ULL, 0x1050C9A5463CA521ULL, 
            0x59B14280AEEBF927ULL, 0x5382440DCA4813C8ULL, 0x4A851E7B13B9BEEAULL, 0xDDB71D5B8F24D07DULL, 
            0x340A76796D67EB29ULL, 0x7D2423B4ABADEB0BULL, 0x20B6B47DE795B8FAULL, 0xB8E14F892FB0C404ULL, 
            0x99DD1A61F16696DDULL, 0x70ED5AAE538EEE5AULL, 0xF5DB5CB1D6E48761ULL, 0xB1BA91AF539C61D7ULL, 
            0x1FE27AA38EF5E6A8ULL, 0x44AD46D64F4836F1ULL, 0x2A28CAF281E61C6CULL, 0x5F0680AAE869495CULL, 
            0xDA9C9E59A9403AEEULL, 0xA0803EB6E2F9309FULL, 0x53DAA8DE26DF595DULL, 0x70AE346A3AAC30E3ULL
        }
    },
    {
        {
            0x9602E301BB67A5AFULL, 0x6263D316FD845312ULL, 0x72C036A155939313ULL, 0x7335D2CB84A5A54CULL, 
            0x8469A62A7A1C4706ULL, 0x53A2A491A2ED8420ULL, 0x7C7FED7BE8B393B3ULL, 0x846F89113905BE7EULL, 
            0x140CBBF6B28E999DULL, 0x7CC76BB0CDF56CFDULL, 0x9489BFE8E16F8937ULL, 0xB956DF7EFB86EC42ULL, 
            0x1446353B26CD8FDCULL, 0xACEEEC3B103F86FCULL, 0x4DD162BC63023C70ULL, 0xF81D8798E1065C68ULL, 
            0xF268F575F54DF2B0ULL, 0x034A8C5A0288B9AEULL, 0x105A1EDAC62DC4A3ULL, 0x1249B96414929185ULL, 
            0x92BE8FFC3DD130AEULL, 0xD06418787B1F8FAEULL, 0x5FD8FC4CB13F071FULL, 0x29FDA3634D2F613FULL, 
            0x5D6F1D0888397020ULL, 0xF4391A519A2CDDAEULL, 0x23AC484EC54990C9ULL, 0x97D9F45DFCDCE119ULL, 
            0x42CD06F2D23F8D6AULL, 0xCF810B338DCB6202ULL, 0x64330210DE7AD044ULL, 0x380A4E1C5F0545F6ULL
        },
        {
            0xA8C1D5A2E2C8086AULL, 0xB50D288AFD0A026FULL, 0x82BFAF9111505EB0ULL, 0x314D2396A7CC0AB1ULL, 
            0xC962DEBF2AB3CECCULL, 0x0D3F549F21703CEBULL, 0x03B03E36275F4431ULL, 0xE16179FBD5BF0748ULL, 
            0xD80405EFE1542FF1ULL, 0xCBC0C93BEA1EF503ULL, 0x3BB63329200A1A7BULL, 0x5E68996D7768CD35ULL, 
            0xCB7D2A4C64031FF5ULL, 0xB75C1D68E88AACE9ULL, 0xE5555AA8E7371061ULL, 0x0F174C1DEDCAFD86ULL, 
            0x38101B9B1AD68D67ULL, 0x9583AB10EB68CB97ULL, 0xD4F39DB8E73EE11DULL, 0x1073DA7B10980917ULL, 
            0xF62BE0EA62D17AF1ULL, 0xA97B4603D925CDA5ULL, 0x3D94ACD10CCD1327ULL, 0x63117A89FF4D26A9ULL, 
            0xC43A53904492228AULL, 0xCAA83BC691F76E6EULL, 0xB155FCA311214DE6ULL, 0xB04310C1A94199BEULL, 
            0x4B963B5C889B0722ULL, 0x65B2A0DF430F4989ULL, 0x000F2360F5B7FCFEULL, 0xFA72067922D45891ULL
        },
        {
            0x860992363AC68727ULL, 0xF22BFEC0943EABB7ULL, 0xF654F12E0FEC160DULL, 0xDE4FA25CE1C6A916ULL, 
            0x97EAF89793A49E79ULL, 0x0D9EED88410F65B2ULL, 0xE969EF9E3EA6640CULL, 0x9D45EA37391FDBE7ULL, 
            0x2440967F43FE71DBULL, 0x582FF7E518F88F40ULL, 0x6C0F9820B497F6A4ULL, 0x91015E3260F111CFULL, 
            0xA5A550BF780D3A85ULL, 0x518F1B8243E9A4C0ULL, 0xCA40BD7E9803F336ULL, 0x56FC221FAA92B62BULL, 
            0xFD6D2DA5D6BAB43AULL, 0xD786F37353D39C65ULL, 0x498704D5D94AA36EULL, 0x9067D329C3B2A275ULL, 
            0xA13E1C4E65CF8B3AULL, 0xD755C13A31D410F5ULL, 0xF42DD53928D8F597ULL, 0x5D8C83E1D9C8D892ULL, 
            0xA9173A7BA124719AULL, 0x9BD53A24CA9B84E9ULL, 0x5546C6456526B7BDULL, 0x87B0EAC7B1F87A8BULL, 
            0x485A22E612CE84B2ULL, 0xDAEB2EA551D311B7ULL, 0x1D99208861824455ULL, 0xC58D43D2FBF0D812ULL
        },
        {
            0x60DF718D3EAA524DULL, 0x60BC10A87BEC382EULL, 0x430EDC94C826A423ULL, 0xB38772A2FF00F3A9ULL, 
            0x4E91D0D848088735ULL, 0xF3059A8FAAE71397ULL, 0xA89F8C05D471BDC5ULL, 0xE343A79F3D08502CULL, 
            0x572EDCDD1A6CED89ULL, 0x3D25EDB2C44B94AFULL, 0x7A88B264B42EA5C5ULL, 0x819267D2186068AFULL, 
            0x1DFB8FC67B249E90ULL, 0xD7968C7AC5306482ULL, 0xB8E2C692EDE63E45ULL, 0x91A83DD9DC476206ULL, 
            0xEBD6292DA81DF0FEULL, 0xB80E77BADD8089D3ULL, 0x6B77F081C6CE8322ULL, 0xFB628BA49282B587ULL, 
            0xA41D25DCD519D679ULL, 0xE41FB6B309E89FF9ULL, 0xEE5DBE11924061FAULL, 0x6E46CCB321FEAAE2ULL, 
            0x6F50612F2A53A6F6ULL, 0xF98C322DF606960AULL, 0xE0F596062A65A898ULL, 0x17E58251D8E5C78DULL, 
            0xF93C11505423AA97ULL, 0xF5A74BAFDD0D28E3ULL, 0xEAD812D7CAD486E6ULL, 0x88876A842DE02AEFULL
        },
        {
            0x374B598A5F53CDABULL, 0x1FA7CD6466D6BDEDULL, 0xB4FCF9D97796F90DULL, 0xD9835D09F7764816ULL, 
            0xF083BA087D295A0EULL, 0xE39D26F2FE7190CCULL, 0xBEE7471B49F707C2ULL, 0x047556194E9DD7CDULL, 
            0x59F3F7BAFCB18365ULL, 0x6C60B768BE247AFAULL, 0x7C1328E13EAFC6DBULL, 0x33C6B5E3E219E2EBULL, 
            0x47828FDCCC4EAE7FULL, 0x8C57EE0368C6B568ULL, 0x3025159A03655C50ULL, 0xAA76ED7B7AB16BBEULL, 
            0x508294DFB5A47024ULL, 0x9A9F153301EE80DCULL, 0xB5DC6C67B83BF839ULL, 0x11F5EA95D871C0D0ULL, 
            0x74D8AC60CA56EC50ULL, 0xC6559B94EB4EBA33ULL, 0x23D23D0EDD82F0AFULL, 0xD4CF648F36B172B3ULL, 
            0x884A5A97485328C5ULL, 0x811C5B84036790D4ULL, 0xF7230660FE0010C6ULL, 0x720CF236FA8C0EEBULL, 
            0x1B605F04081488FCULL, 0x951861D18852C5E7ULL, 0x337E27CF70051844ULL, 0x9D4C22AAA74AB46DULL
        },
        {
            0x9D917625EF54BA0EULL, 0x2C2F5558FBD282B4ULL, 0x645D1B3FC7EB4424ULL, 0x1D93366A1EEA5547ULL, 
            0x1AEB5C0606BFC05AULL, 0xEC0145EF23712234ULL, 0x7F302C2E63717B6DULL, 0x8EDB4BF6CB875B7CULL, 
            0x66DF8C66D9CCD065ULL, 0x003089FA3AFC1A57ULL, 0x2BA979749B2733E7ULL, 0x031D8B6627D606C1ULL, 
            0xCF40B19DCD3661DBULL, 0xF9C6F23EE4C5D067ULL, 0x66B52AAC2B0BA969ULL, 0x0790E7389D68C695ULL, 
            0x4A8DF7A6A3B278FBULL, 0x8B8033F798E001E7ULL, 0x4216312FDEA2A7AEULL, 0xB14B64B9B88CFE12ULL, 
            0x02562056F63E0D5EULL, 0xDFF1601DDD129957ULL, 0xA4A012E48417EDBEULL, 0x02B8EC36954DDD4DULL, 
            0x3DBBB17673EA7B0CULL, 0x400ABFC7C4FEEE52ULL, 0x81A9B55594C49538ULL, 0xF373211651114CD2ULL, 
            0xE713345E0CDAF2E3ULL, 0xA29374DC00B11535ULL, 0x120B931411A434A8ULL, 0x89A37BD6680DC93FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseCConstants = {
    0xCD02C30197E6A794ULL,
    0x34BA862600CE1E00ULL,
    0x97F6F47D79905D1EULL,
    0xCD02C30197E6A794ULL,
    0x34BA862600CE1E00ULL,
    0x97F6F47D79905D1EULL,
    0x1936EAEA49392C3EULL,
    0x9F9C3796284D30AFULL,
    0xFB,
    0xF6,
    0x68,
    0x6F,
    0x9E,
    0x67,
    0xDC,
    0x8B
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseDSalts = {
    {
        {
            0xF20FF9AC963087FFULL, 0x9B55AC4523C28BFEULL, 0xE5729F768B8A3BB9ULL, 0xE022FF6F48604E6CULL, 
            0xF5FDEF8DFADE0D2DULL, 0x8E2DDE7351D03518ULL, 0xF5F5FE5C96964E93ULL, 0xE877159AA103E7D4ULL, 
            0x4D3DB38DDEA1C5C8ULL, 0x498DA1BBF23D4A6BULL, 0x34F0E76214BE7AD6ULL, 0xD3E0322648A7549DULL, 
            0xD625B2AC20F14B35ULL, 0x1FD793120F369648ULL, 0xE50340AA1F37965DULL, 0xB1ADE425A91D92D6ULL, 
            0x5B00C7F7573449E2ULL, 0x98DCAD187876D17AULL, 0x0C277A155F11D110ULL, 0x8A476C2B9BEABE2BULL, 
            0xD2DDBF12099A5B37ULL, 0x99DB2035743DECDAULL, 0xE5E28A672EE20D07ULL, 0x4D4EEC914811CB53ULL, 
            0xE336140B15A8FD77ULL, 0x4F9FC662692202BCULL, 0x46AB25EB51CC7351ULL, 0xFBED96466CAE2C64ULL, 
            0xED8DD4E46CB4C1E1ULL, 0x30C403C75C578402ULL, 0x6660DDE9644B9B76ULL, 0x3297CCECC58CFF76ULL
        },
        {
            0x5F1F77F7F99013FDULL, 0xABEE5795C01C9395ULL, 0x14D6334F89AFDA3AULL, 0x4FA13EE2978FC035ULL, 
            0x026380CEF40B6302ULL, 0x944009F9C844AF26ULL, 0x1C384BAC13E3621CULL, 0xF8CB85911FAFEDA9ULL, 
            0x8DDB09C88078782CULL, 0xE7EA0862D38F746CULL, 0x6645111B8824AFF5ULL, 0x263E2E922AFFB488ULL, 
            0x7F4DC527D8A8571BULL, 0xE17EC8ED33AAC995ULL, 0x0D167B1F33A43EDBULL, 0x28B53280D4D2D7EFULL, 
            0x13D09F7E5C408F30ULL, 0xF736ED702DDD407EULL, 0x2431B7B946AD26BDULL, 0xBB25F0108A4676CFULL, 
            0x47FBDDD6F7DAA8B1ULL, 0x0E4B591837915A6CULL, 0xFBA64D342517DD29ULL, 0x0441BCD2C7ADC52CULL, 
            0xA62C5C2F2D8A9C11ULL, 0x29366D99B639E996ULL, 0xD7E8A1A994F023F3ULL, 0x25045A39450821C5ULL, 
            0x634F343C21A6D098ULL, 0x1DB10AED485B8EB1ULL, 0x212B8DD6EA51931CULL, 0xCB0CD71645185F99ULL
        },
        {
            0x59661272D54D6EEBULL, 0x31F5D4EB264A8FC1ULL, 0x644EE943B4B48097ULL, 0x762B933AF255C980ULL, 
            0x57E466AFC2AE0B0EULL, 0x75954B2E92D9F00FULL, 0xEFCF44912AD47BAFULL, 0x73E9A461727A7F9EULL, 
            0x5A2BBA7F629718A4ULL, 0xFC56BE3C4AD17EE6ULL, 0x0BE628D784A2D0E6ULL, 0xE00FF820F30D1896ULL, 
            0x68437488C06C6430ULL, 0x94722FE109C40C83ULL, 0xE1558D71C18A630DULL, 0x4F66AC8A28FE2593ULL, 
            0x82896159C2D7EC02ULL, 0x7962E0A23020D4AAULL, 0xC09DDA47009E0BB7ULL, 0x05993E5BFF20DD19ULL, 
            0x927300FAB1B26193ULL, 0xBFCA175C60BE4131ULL, 0xAB61B9C874A710F5ULL, 0xD0368DD288772159ULL, 
            0xD92C92BA835AAE3FULL, 0xA0E2653EB9251906ULL, 0x39077E3F06329D00ULL, 0x56E9F9221937C60FULL, 
            0x8C7475BE8CDAD8DCULL, 0x1C66441851B2CC97ULL, 0xF33C10E626C389A2ULL, 0x85674C7317A80AFEULL
        },
        {
            0xC2D901124F82BB80ULL, 0xAA32323CB96C5447ULL, 0x909132D0B55EA6BCULL, 0xAF97C0EC332C2C89ULL, 
            0xE8ADB4DDDEC0BAA7ULL, 0xB11A14E79EB7608EULL, 0x51D5E58D9B25734EULL, 0x17669739369F1FC7ULL, 
            0x3D6816E505614E09ULL, 0x72C443F164863464ULL, 0x843523AFA7E6515AULL, 0x1E6481D62A105813ULL, 
            0xEB015A0BA1F61C0EULL, 0x2F7C2D18043F8ED9ULL, 0x9D1E99B833EE2077ULL, 0xFCE410C7A7D19FAFULL, 
            0xF42DE0D964726F13ULL, 0xEDFA785C1AFA6D4EULL, 0x594D9179C1E1E903ULL, 0x2F5E4FF32DD577F5ULL, 
            0x021B6C1BB14A0FFFULL, 0xE9EECDD4893719DFULL, 0x347B59F7CF144A07ULL, 0xED4E88D4477BED92ULL, 
            0x17CD82270435EEBDULL, 0x20018ACD9FDD9C2FULL, 0x6BAF7A704AD86DCAULL, 0x94795AA9F9F13F45ULL, 
            0x56ED0E78A5914528ULL, 0x10A4EB15E24E2F9FULL, 0xC99C1FD8AC5D9449ULL, 0x693F39ADB4E5F537ULL
        },
        {
            0x14E3170E129F4A28ULL, 0x7C58370CDE795350ULL, 0x731C287EFB0921E3ULL, 0xD64CC2169AF96055ULL, 
            0x3AF240BAD087ACC6ULL, 0x7E7CC6D22F9B4B14ULL, 0x6D10D3834F557A94ULL, 0x766F3F73C1F22EF1ULL, 
            0x16E5DA0F960464E7ULL, 0x7B366CE4F3A06881ULL, 0xDA5342262890F665ULL, 0x2995119050A17BCEULL, 
            0x887AD6A6BA6F63E8ULL, 0xA9EA7F410455354CULL, 0x2145B0771DDD90C6ULL, 0x89C573AE8876B943ULL, 
            0x2CD43A906A383DCDULL, 0x64553D24F26212B1ULL, 0xA521104BE9B0D05BULL, 0xA359CF18754B77AEULL, 
            0x73F07AABE1CB7FEFULL, 0xC244D1365EC09DC9ULL, 0x0B1CA3BC17FAE6B3ULL, 0xACC59D6DE2CD73CDULL, 
            0x8F11E3711B6A53E9ULL, 0x287775BEA16F00B0ULL, 0xAF1622193E8298FDULL, 0x03AC592CF231A97EULL, 
            0xEC489B809A44D7E6ULL, 0x526277E53519B239ULL, 0x3A9886BE05C265B5ULL, 0xD4C21FB1BAB78B19ULL
        },
        {
            0x0E2FE4AA7CCBF0CFULL, 0xE0AB9BA6CC0CA4BAULL, 0xE5DC0D586E00812DULL, 0x8B8B2EAEB074229EULL, 
            0xC404DC4813456FC6ULL, 0xF23CC208D98949F8ULL, 0x697309C4F972BC35ULL, 0xD45AC7D78B8FC26AULL, 
            0x494DADA018154526ULL, 0xE6A6B177DFE66035ULL, 0x89393A29F9921EC9ULL, 0xA603CCEFA36C8389ULL, 
            0x22F96B28CE65282DULL, 0xA25CB57C1A1DCF5AULL, 0xC291046ED9A4860DULL, 0xA8238D9376C3A901ULL, 
            0xEC524623DB311DA2ULL, 0xFA34B236A05FD531ULL, 0x2ADD32C7C5B7DCDEULL, 0xA02CE7FAEB939529ULL, 
            0x24F1E7A4D066C026ULL, 0xCAB597B5B966BA2CULL, 0xDC72588EA0816531ULL, 0x435295C1E1F29FE1ULL, 
            0x7F2858BBEA8D6C35ULL, 0xA0402DDE238A0251ULL, 0x3460197CFB286544ULL, 0x804AA28916EBE57DULL, 
            0xDC18C1885F81854BULL, 0x65B3F413BF49ABC6ULL, 0x7AA7C078A8E41B89ULL, 0x0B8CF25394456747ULL
        }
    },
    {
        {
            0x569D0102D5A8EEBCULL, 0xA2ADBC9D7AC59261ULL, 0xD8D62C50FD70C741ULL, 0xE7FE2030CC11BF00ULL, 
            0xFF3ACA38211BACC0ULL, 0x7953D2477CB967CEULL, 0x1337D677920391CBULL, 0x60B3932F1921BCE4ULL, 
            0x53970FCFA101E900ULL, 0x8A895ABEA07C627AULL, 0x32968D8829C5A72CULL, 0xFA178A60168A7E9EULL, 
            0x3FCE4852F96EB9A5ULL, 0xFDF282D972BC0167ULL, 0x55C3D81936594961ULL, 0x1131464600E638D1ULL, 
            0x4265239025A998DCULL, 0x62D6F741D7398EACULL, 0xD4BF4200AF8E3E47ULL, 0x9B88553F37320D31ULL, 
            0x97C8C0BF80C1108EULL, 0xF2F717F33C2AEAD1ULL, 0xB8AB7B382805922AULL, 0x81077886155E0B29ULL, 
            0xD1696C8FCCFCC02FULL, 0xADBCFEFC1911836FULL, 0x8E169A7CF9CF76A0ULL, 0x63CF4BA193850A44ULL, 
            0xDDB07283A0B8F5FAULL, 0x4EA7343696CB96C1ULL, 0x272C7896D876F143ULL, 0xF33FFC81A8C0CFA0ULL
        },
        {
            0xD1B7374AC672C238ULL, 0xDAA4EF2FA22D1C36ULL, 0x0E087410B5A57C61ULL, 0xF066E2C723F6217EULL, 
            0x07744323F58EE535ULL, 0x7FB2438962BEFFCDULL, 0xEDED07D37E6D440DULL, 0xEE3D88E539BD3054ULL, 
            0xF7F84EF53050933AULL, 0x0149D4C872423A4BULL, 0x7E7F27E6D00F4146ULL, 0x0344DF60BF7B292DULL, 
            0x7C35AF75E2B5385AULL, 0xFC11C02E341153E3ULL, 0x53CB7BD93ED01567ULL, 0x84002470D2ABD0A1ULL, 
            0xA23CAA2AFD97C650ULL, 0xDA01363E1614141CULL, 0x6BE52BC6A5809ECDULL, 0xDE81FDEF1092B827ULL, 
            0x65FE73B082B2A41AULL, 0xA4FB21A5725E1716ULL, 0x2B0AE9684D20C070ULL, 0x152356D82A08B1DFULL, 
            0xF55A54F158D56F17ULL, 0x189C3F9A7061F844ULL, 0xE682FD9B1669F6DDULL, 0x03DC899CEBA0FC13ULL, 
            0xC4B68B631049824EULL, 0xAB28A57CC22EA9EFULL, 0x9722E46C305BE6CBULL, 0x7B79FDEED3C7E587ULL
        },
        {
            0x86B8C9DDF71173A8ULL, 0xB6DCD432776FB120ULL, 0xDB5F5E2FC3D50D75ULL, 0x3029F315EE25858CULL, 
            0x5BBEFB022BACB12CULL, 0x52DFFD3C6C9AEF82ULL, 0x11D6B3110CDF138FULL, 0x92574C8AE566BC1EULL, 
            0x33CD149CB5426EC6ULL, 0xCD519E59E6584DF6ULL, 0xB3E9C3370E0CA2EEULL, 0xEEDE0364918A973CULL, 
            0x9DD248DC5B25DD3AULL, 0xFC89B6FD1350C86CULL, 0xB0A8BD5D1362825FULL, 0x2854F60966F85E4BULL, 
            0x8600146CD288AF78ULL, 0xF3695110FC16DC90ULL, 0xFED1B53683C919B3ULL, 0xFF297D2C43C70964ULL, 
            0x4E6B6F48A7274085ULL, 0xCAF008CEFED7BABCULL, 0x9FDEE0DDFA666913ULL, 0x0A41F6914BBF43B8ULL, 
            0xCD920F0018EE915DULL, 0x1967A12A4B94AC2DULL, 0x62491D97EF9AB9EFULL, 0xD66071274E915591ULL, 
            0x2614B59F544AA7D7ULL, 0x2FF5C34713442450ULL, 0xE995EF8BBC69E405ULL, 0xF4DC492A91207FF9ULL
        },
        {
            0x2CC7447BE22CFECDULL, 0x624443AE9A6E83C2ULL, 0x5B1BC6AEFABE2AF5ULL, 0xFB664D0E075DAF9FULL, 
            0xD8B5EA77F5488111ULL, 0x2AB047081C20C9B8ULL, 0x0591777146C28788ULL, 0x929BFC353AF8930EULL, 
            0x93CDC6CDE6CD7528ULL, 0x6F015CCE96E82887ULL, 0x5E9F038BA370E759ULL, 0x1F55DEF76DF73248ULL, 
            0x306D500D98D28824ULL, 0x4FEADD3650D19987ULL, 0x40776A25A6C0C845ULL, 0x0482E05D6DC9AE4AULL, 
            0xBB8C68F610BD83D4ULL, 0x4860D58E4CEE4BEAULL, 0x00CF62FAFDBCF9DCULL, 0x13A7BF0E322CD56CULL, 
            0xF7B03BD2A8C241A2ULL, 0x0B56FC33DB027422ULL, 0x0171F8A5ABAF444FULL, 0xD84E29B9C87D6063ULL, 
            0x8422576F5AC221A9ULL, 0x01E02BA1FACBE26DULL, 0xBFA390E352D6FE5BULL, 0xCD4E2B94B6F067E7ULL, 
            0x980F820469A00721ULL, 0xDEABA287033E5424ULL, 0x5CD74D2DD0F11D8AULL, 0x431A89AA09F8DA17ULL
        },
        {
            0xA3FF9353A1AD8A97ULL, 0xC71F479C4A74798AULL, 0x17A862F8B0CA4B91ULL, 0x0006AEB22EC6C1FCULL, 
            0x6EAF45D62A3B1EDAULL, 0x67ACB4C88BA93D93ULL, 0xDC1FFD184449F213ULL, 0xCF912FC0319F17DAULL, 
            0x70734C285C87A9DEULL, 0x96A311F0C1E24F88ULL, 0x37EE586EE7A57795ULL, 0x128F0CA8877E7FEAULL, 
            0x3A0647931716C786ULL, 0x34D80CDC5371EEF2ULL, 0x4B8B3DF9FA26DFDAULL, 0x96027C125435902AULL, 
            0x165DA9A45EC4D695ULL, 0x3226657366F49907ULL, 0x973F4C236D3CA12EULL, 0xC8523DA284F64EB1ULL, 
            0x66D03DAEDE9B64ACULL, 0x26684428DCD07932ULL, 0x1B068FDF4FB266FAULL, 0x8A269D4D20E13B7EULL, 
            0x733541D439485596ULL, 0x20402BFDB0421AB6ULL, 0x4B592A27026808C2ULL, 0x5F534D6F15575DE8ULL, 
            0xA0039E636F16E689ULL, 0x96C0FC51A9F8726EULL, 0xBF5EF4A7A76D6604ULL, 0xE8EE3A5615D6C265ULL
        },
        {
            0xF1EAA1CB5C1EE39EULL, 0x9C12A62D71683A04ULL, 0x64E559DB1A487DDFULL, 0x2A7944DD510D6656ULL, 
            0x28A330BDD61650E8ULL, 0x447892F524E002C2ULL, 0x2BB6C3A9630453D1ULL, 0x2497030F31077EA6ULL, 
            0xA2E5F269F39D92CDULL, 0xE559D78CBCB4C8D1ULL, 0xB3E53275F2198227ULL, 0x7C57607BD2B3A38FULL, 
            0x0E28673E2DA5DBD8ULL, 0x2F4491014D7B3AE2ULL, 0x5B49030D1160278EULL, 0x6459DE9CE388E3B9ULL, 
            0x81B72558A93CEA76ULL, 0xFF9951094C8007B3ULL, 0xFE86E2F7B112FDCCULL, 0x34333E8D13869034ULL, 
            0xE44081BE25CBFD01ULL, 0x15627735103086D2ULL, 0xEB887EDCBAEF23FDULL, 0x78C3B569C80A67E2ULL, 
            0x38716B790CD1A288ULL, 0x3E228C9462EE34D3ULL, 0xD4F5EC3B146C01B2ULL, 0xC0F5A3C594670C54ULL, 
            0x391464A3D2D5147BULL, 0x815959843366C619ULL, 0x48F638D10625D4DEULL, 0x542C78FEBD3077CDULL
        }
    },
    {
        {
            0x40405C57E8B74A6BULL, 0x84106A4C33632040ULL, 0x09247E9D7B7EBB2DULL, 0xD324A206F1EF7ED1ULL, 
            0xF005E76CEF57EE46ULL, 0x11B266FC2BA4412EULL, 0xDB45733191F88CACULL, 0x87065613D2348255ULL, 
            0x1962888E75FF8290ULL, 0x4789F97949275799ULL, 0x98E741B071E31E9AULL, 0x5644B87D9917DA8CULL, 
            0xD002014D3A4C57D1ULL, 0x742518BF377A9A35ULL, 0x0A399E34440EFBDAULL, 0x62BC71EF2855895CULL, 
            0x76C1155A88CEACB0ULL, 0xD8F2DA35290068C1ULL, 0xF958B6CB89D5261FULL, 0xB01D85188684FC06ULL, 
            0x870BE0FDC04AF97FULL, 0x2DE09BACB58AAD4BULL, 0xB4F5A520A58BDF0AULL, 0xC2FDF9AE2EE89A53ULL, 
            0xCB5404C8F1E58D16ULL, 0x45020A8F2906B0FBULL, 0x96099DE799210C0BULL, 0x1E58CF19CD686E09ULL, 
            0x8AF3677BCCCB78C7ULL, 0xC6D679DF11FFC989ULL, 0xFFB8C5F319610D1DULL, 0xDD990B247F0D3766ULL
        },
        {
            0x0302E2AC56FC6E1DULL, 0x0A2A78AD3EFB94FAULL, 0xE3ACF3EDF016B8C0ULL, 0xBE64BFFD73A30605ULL, 
            0xAB54A04CADBD5509ULL, 0x73942293680000A9ULL, 0xF764683FEBFC2C55ULL, 0x9C6E0EBE135A70EAULL, 
            0x916750AEF60E997AULL, 0xB4BD1E848DCA614DULL, 0xEDF6B7F144F25305ULL, 0x819879D659015CFCULL, 
            0xEB9C684CEDC4646DULL, 0x9B2C2DC92A97974BULL, 0x202A6FD65D77B2EDULL, 0x97D506E9F3A0945CULL, 
            0xD0D8DB5E59489E8CULL, 0x883300A236C74D90ULL, 0x73C17ED9ABBBC5E6ULL, 0xDF15EB7FECEB483BULL, 
            0x05DCAE678AC9CBD9ULL, 0xDE54F1BF8CDC3C83ULL, 0x777C71D423892C0DULL, 0x48D44ECE684B7B49ULL, 
            0xA499AE16AD605769ULL, 0xCD91D998D4BB1233ULL, 0x87A6C0A1C473131DULL, 0xD127B3339874DC18ULL, 
            0xDBC732BDDAD73FDEULL, 0x5395E5C718FFBE5AULL, 0xF0AB19080706D83FULL, 0xC35144C6F015FA40ULL
        },
        {
            0x620277440F62DB66ULL, 0xA5A071DB801A0D6AULL, 0xA5AD4C8960576F50ULL, 0xDB5FCD8B937374D3ULL, 
            0x29140438D03B9A44ULL, 0xEB42B9E21D9BDD61ULL, 0x9630F1AA3A7F32F1ULL, 0x5DD4D68DE8BCE124ULL, 
            0x5BEB78DC05518F92ULL, 0xDA953C1504A07D9CULL, 0x38AC8A69D078B733ULL, 0x2B5CBC65E56E680DULL, 
            0x7ACAD099C05CA727ULL, 0x3C519901EBEE63AAULL, 0x57AF95382B76261EULL, 0x08A47F13AEE6F285ULL, 
            0x0F952AFDABF82B6DULL, 0x9AC1883B5100EC7CULL, 0x729597A3561711FAULL, 0x09BC7D7C867C9FA7ULL, 
            0x240565F42AEE9218ULL, 0x6EE47AA6D2D3D860ULL, 0x0252BE3F9C96E3F2ULL, 0x67E6B2AF2531B9A4ULL, 
            0x62EB1C651041BBEEULL, 0x30AC5E776E87A100ULL, 0xFDDDB501C1B54AF8ULL, 0xF9C6EB821540F689ULL, 
            0xB4CAAC3855F87B8FULL, 0x52657E545D76C260ULL, 0x5A9AD6BCEE4C0A43ULL, 0xD601CEC746E941DBULL
        },
        {
            0xC16B33B076AB9E02ULL, 0x7BA5A2E7FBE1796DULL, 0xE65F8FD9412A612BULL, 0x2E919C6977CD526DULL, 
            0x2CE9DAA60E748A64ULL, 0xA085B181CCA2998CULL, 0x5D4D21F438664571ULL, 0xCA7654AB339E8724ULL, 
            0xDF29E1E61A996AFCULL, 0xD4058BEEBA54A281ULL, 0xE52625FB1C0489AAULL, 0xD77DB15B9323A85CULL, 
            0x4EDC94E6D17797B1ULL, 0x278DA2807F57DEF4ULL, 0xCC1F1E20B095E056ULL, 0x88750B07877F3C55ULL, 
            0x5DEA4EA07FEA9469ULL, 0xE34D4F624DB3E338ULL, 0x83BF3E633F6A2E1AULL, 0xC8DBBF492F9A4D13ULL, 
            0x098D8D01E419E228ULL, 0xA716945DF0E88F61ULL, 0x50F18895459C0E66ULL, 0x41373DD98A852409ULL, 
            0x115C58FA259CBBE4ULL, 0x53B8C21E6B9C535DULL, 0x5361A79D21C256C8ULL, 0x7CE2CCED754B0D1BULL, 
            0xA3681DAF0619C51CULL, 0xBFEA401C5A63F80BULL, 0x767037C9FE451221ULL, 0x9B46BF95C66BB242ULL
        },
        {
            0x82869C69D9E35AA4ULL, 0x60B11210596FFEC5ULL, 0x4808ED56CC6BF48CULL, 0x46E3F9A32609220AULL, 
            0x74D538A22A9DAF92ULL, 0xDD64BAB19A19B131ULL, 0xCBF1A8D3068048ADULL, 0xB31804F0AFC42ED4ULL, 
            0x037B20000C0D8BD5ULL, 0x1F5E47158FEF60A5ULL, 0xA1DC4E01F47D3CBCULL, 0xE22F8063A6855DBEULL, 
            0x619A1A3615A233B0ULL, 0x94AD9B3E3B1B4E98ULL, 0xFE7ADA20CB2DDA4AULL, 0xE282DC5D9CC40A3EULL, 
            0x66FD676D10E73237ULL, 0x964B42BE7779D935ULL, 0xDC17E1FEABD418E9ULL, 0x8B332D4CE2D76829ULL, 
            0x8992D1728D4C7742ULL, 0xD7E8DAEBAF9A38EDULL, 0x5A25A7B0F1CB6364ULL, 0xACAF53D491DA9715ULL, 
            0x77737B2F31CD5846ULL, 0x151871528BAC093AULL, 0x91F138AA322CDAE6ULL, 0x3293EB92F3E4631CULL, 
            0x6658F2DD249F8155ULL, 0x4BA7401FC7079908ULL, 0x52221E2AF3FB8ADDULL, 0x87BDFE578B409C61ULL
        },
        {
            0x5C80D02AE7C4B6DCULL, 0x051FCD16128A05D1ULL, 0x87D1992147ECA290ULL, 0x829A009A8868ADBCULL, 
            0x6DD2E31C7B70C67FULL, 0x15472CF0287F6411ULL, 0x4E8C16BAF0725E0FULL, 0x61BD79D4C056FE2FULL, 
            0xE7D3D23DDC09831BULL, 0xC424137EBA082F04ULL, 0xC87C677FEC250CBCULL, 0xECF73E8DE73BEC33ULL, 
            0x9D12CE907695D8BCULL, 0xFBBC7159F8EE8168ULL, 0x478BCBF5373C2A3BULL, 0x5CD5933325E7B82EULL, 
            0x0D41E1A8902F2B62ULL, 0x058DFF7F6B89C949ULL, 0xAAB69DA2406B7C8FULL, 0xC70A852EA4D0A1D5ULL, 
            0xD3E6559376B6ACF2ULL, 0xB232F4254192F565ULL, 0x0B51B4B6E73E81D7ULL, 0x298A74D078858B0AULL, 
            0xD921A10CAEF195E2ULL, 0xEFDA9DDACFBB2D7FULL, 0x674B124D05687EE2ULL, 0x36B5AB7173DEED2EULL, 
            0x94906799A5E23589ULL, 0xBDFA6A0A959ECB5EULL, 0x0D050B75841DB2DFULL, 0xB40C1D216815B488ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseDConstants = {
    0xFC8AC71E3437B147ULL,
    0xD37E807964100C96ULL,
    0x9786251687EFC44BULL,
    0xFC8AC71E3437B147ULL,
    0xD37E807964100C96ULL,
    0x9786251687EFC44BULL,
    0xF8FA4F08AC3E7DE8ULL,
    0x794284118BC3E89BULL,
    0xE5,
    0x1A,
    0xB8,
    0xE6,
    0x7C,
    0x98,
    0x61,
    0x2A
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseESalts = {
    {
        {
            0x8E06B319304CF280ULL, 0x6895B3002CFBCA24ULL, 0xFB133AC49B268801ULL, 0x0B6434F371BC952BULL, 
            0x3774DFA69F0D803EULL, 0xA1AD3460C392D045ULL, 0xEF747EF11CC48318ULL, 0x537DB481D27A4735ULL, 
            0x92FAC08AA803C097ULL, 0xCF80BE1B3CD9C95EULL, 0xB8E94819DB018E06ULL, 0xCD9FBD23107B6C36ULL, 
            0x136960DE0CC8080EULL, 0x7383EE9BA94B0020ULL, 0x1E7F50046D2C16FDULL, 0x2ED5045FD9261395ULL, 
            0x64AF22FC940E9861ULL, 0x23552F00373AA9B0ULL, 0xD06951ABF300F40DULL, 0x4A38221CA057CE00ULL, 
            0x9E6FFB8A9C33385DULL, 0xAC35AD7461793740ULL, 0xC739C77129A555D1ULL, 0x8009CA303B5C11ABULL, 
            0xA71665EF39D9B5C5ULL, 0x57EB2080E35972DDULL, 0x963BA68F23E9BA4DULL, 0x6D3F12901CEBA558ULL, 
            0x0065A9BB15534191ULL, 0xC29B7021338F156BULL, 0x16C67F24CFE28994ULL, 0x99F2F2F4C5B5E2E0ULL
        },
        {
            0x8BDB194590E58F7EULL, 0xBCE382ECA29D42CFULL, 0xC0A3490ED0E87720ULL, 0xDAF73C9B5F1B6E39ULL, 
            0x5E88DCFD6AFDC1DFULL, 0x2ECCEB00B912E273ULL, 0xB028C5098A12A008ULL, 0x015627D4433C4E02ULL, 
            0xB5738B2B5A2ACD4AULL, 0xF5C2373DAA3A9D66ULL, 0xECE1B475FFA9E358ULL, 0x8ACB9E5D1AF7AA59ULL, 
            0x4B6934FCD4DE3F76ULL, 0xC2C103C42774ECCFULL, 0xE157EC3BBAA7DDDEULL, 0xA557FA62F8F40F5DULL, 
            0x012D7941C237267CULL, 0x4EDEF4E3C8915544ULL, 0x244BA131B8A24CA4ULL, 0x70FDEB56089017E2ULL, 
            0x53B8F0600A4CC096ULL, 0x4B8AABCC1F2703C1ULL, 0x8348F3A53F4FAAF6ULL, 0xA2400825DAEE0807ULL, 
            0x7C3DE1860C2C9999ULL, 0x376A63545177D676ULL, 0x33B08B5484874FF2ULL, 0x4DD46AED901E8EE2ULL, 
            0x056FD12CF2CDC564ULL, 0xF887BC35A06F9D5DULL, 0x0C2B151AE837E39BULL, 0x2019022366E98913ULL
        },
        {
            0x6E1B87775172155BULL, 0x80885752B72DBC02ULL, 0x05CD432224BFF5CAULL, 0x1F59ADEFCFB01DD0ULL, 
            0x40022142C2F4D101ULL, 0x0E592E2D347ADC49ULL, 0x34A84CEC3194918EULL, 0xBBC893B4825B1B5DULL, 
            0x94D8FE59FC84B025ULL, 0x4FAFA45FC9E83C73ULL, 0xEBEA12055CEEF2EBULL, 0xD49D33D918C27A61ULL, 
            0x0B985FECBD2926D8ULL, 0x62B9E0267BC8C11EULL, 0xC4AEBB7CAC6C77DFULL, 0x5F0DC1B77A3796C5ULL, 
            0x4AC9582E9B7E3C6DULL, 0x9D01E5818CE39362ULL, 0x720AFBCA86FC13E7ULL, 0x1539F52860F0917FULL, 
            0x0F5F3AC57C6EA6B6ULL, 0xF7259D6BFBB0BACAULL, 0x1F46E082F4A86DCEULL, 0x492C5673D5F93F80ULL, 
            0x7EBD0A81982E19B0ULL, 0x8B9C7D9C2E8B7A86ULL, 0x1202BDE8CD8D6F73ULL, 0x27E8CF262E26088BULL, 
            0x716A145DCAE62A90ULL, 0xE62AC89AD6A9A324ULL, 0x0256421CB4A9A1EBULL, 0xB2DEBB7DE370CC22ULL
        },
        {
            0x7D90600A1A87D9C6ULL, 0x87C1F98F5E307B47ULL, 0x8EBF2969D1DD6F34ULL, 0x75BF41FFD691732AULL, 
            0x1DACC5EB37448C3EULL, 0x80BAE09992C0CC02ULL, 0x69B6743BD408274EULL, 0x35902E407CA03741ULL, 
            0x1618DDF6952CA38FULL, 0xE9365D12560B0B9FULL, 0x3ADE381A29E680B0ULL, 0x6BC00D56D05D4205ULL, 
            0x1F4C317009ABE276ULL, 0x840AAE6ADD19BCDEULL, 0x4FE64AD72B56EF2FULL, 0xBD6C0234C9DE1691ULL, 
            0x12B8B71F4F248F2BULL, 0xE71258750E42C6F3ULL, 0x5909A6F5124BAA76ULL, 0x77346D291F88F6CAULL, 
            0x87FA8621EDB9B8BCULL, 0xA020C4DB0FC98D1EULL, 0x08301F753617ABD5ULL, 0xDB485B5F5265E9A4ULL, 
            0x16D632C81160B079ULL, 0xA466FC4070095D93ULL, 0x94135F7CE1C86C00ULL, 0xD83ACFFEE563896BULL, 
            0x36B2E6C039A48E37ULL, 0x024A9B82C5FAECFFULL, 0x285816C71583F5E9ULL, 0x80B550B84F28B452ULL
        },
        {
            0x2D098D4E867557ABULL, 0x04DA903659D8D27CULL, 0xBDEC071730E02468ULL, 0xCF42128951ED7E56ULL, 
            0xB6B7BD1100BFFB38ULL, 0x2395BEB2CC97F501ULL, 0x33253E7CFD23B7EBULL, 0xE1C7DC7B25507741ULL, 
            0xBBB5B8AAC5996695ULL, 0x7ED423B72F7E3900ULL, 0x87AAA11578DF0768ULL, 0xCFA503FCE81B4149ULL, 
            0x412C71CB32555A30ULL, 0xD7AD22554CB45D84ULL, 0x47236C809CDF8BE7ULL, 0x9D60C7A7C45122C6ULL, 
            0x050CCAFCC5BBC7F3ULL, 0xAB452DA6961B2E4FULL, 0x849489C5343E16F3ULL, 0xB054F24E9B97DA88ULL, 
            0x798566087662E82DULL, 0x737462F8EC2C7C19ULL, 0x4EEEBB4F41BA2BE3ULL, 0x80C99E1D4491257DULL, 
            0xA912C72C3EACF8EBULL, 0x2609D1AC4924B51EULL, 0xB7E1C806CA072A86ULL, 0xB5F8D6A90A88D429ULL, 
            0xDA0916724D2EFAD9ULL, 0xA5FFADCEE33F880BULL, 0x102AE610632DA2B4ULL, 0xE6F0D7CE92FEF72CULL
        },
        {
            0xDE6F490954B77EE6ULL, 0x2645FDE4CA47C80DULL, 0x031F70E75188B581ULL, 0xA7BA916B14A74338ULL, 
            0xFA5640700F030CC1ULL, 0x478B2EE8E28F15D0ULL, 0x4B3CBCA6DBA0BACFULL, 0x74CCB186CD840C77ULL, 
            0x490403BC1431833DULL, 0xEA8C3C7011766322ULL, 0x89BE053C4FACBC28ULL, 0x75DCB540022DA39BULL, 
            0x954A378248BE49FCULL, 0xC82077AA13ACE1ECULL, 0xD326049B751BA3BFULL, 0x9F8EE5642A2FBC79ULL, 
            0x7B51C2A6E635DFC0ULL, 0x4DD4C30F7F916BC2ULL, 0x1BDFA123CEE2E05CULL, 0x03AD7839730E9BA4ULL, 
            0xE6D693C773628DCCULL, 0x1C02F18DD2A3FCB4ULL, 0xF7414CBDEC18D57DULL, 0x3EE66E7AD8CAC2F2ULL, 
            0x95B1EBD42C08616EULL, 0x4CAB5B585A0407CCULL, 0xDA78258D3079BB33ULL, 0x4CAC178463409A29ULL, 
            0xE41E730C42846CABULL, 0x381E83DE85A0C25DULL, 0x9098818777BF63A6ULL, 0xB15CF615FA948CA4ULL
        }
    },
    {
        {
            0x622CBD152AA4BA41ULL, 0x9E09F6C4C50C7DA3ULL, 0x667D04CB100CC0F4ULL, 0xCA00203F657D5693ULL, 
            0xB57465920738F207ULL, 0x1DB072A016AD761BULL, 0xAFE18DDC1AE72B9BULL, 0x4B4E6086C035A587ULL, 
            0xB0D191D24E9788EAULL, 0xCE2E3DD0D1CEB2DEULL, 0x70F6C646BE1B5235ULL, 0xC9311C6B2353CA89ULL, 
            0xE72720A42D5B1382ULL, 0xA021B7E4DB6A1336ULL, 0x3C76361880F30A19ULL, 0x22C7F15FFF4C41BAULL, 
            0xFA0CD7F32CAF768AULL, 0xD5BF2B43AB899BD4ULL, 0x8067A35260937995ULL, 0x41D3F2EC72C169FFULL, 
            0xE02BE4B9C529ABBBULL, 0x7A7844F87A51D81BULL, 0x846AF1B1D6DB68F4ULL, 0x7A0F9D367D039864ULL, 
            0xE0B4AC1303F21308ULL, 0x96A8F4F0AC334E00ULL, 0x40A6318C74C65AE3ULL, 0x3EAE666CC87BB06BULL, 
            0xA925D57E45481FD9ULL, 0x8425DAE285078C14ULL, 0x6264C7BD5BE725A7ULL, 0x9A1722D7AF91D2F2ULL
        },
        {
            0x181A15CD5800726BULL, 0xC278741CE702B005ULL, 0x2187F119C8C2F2F3ULL, 0xA29FE9934D17866FULL, 
            0xD69B51DB9551E7AEULL, 0x0270B0A294CCDE57ULL, 0x23FE22F2441068A9ULL, 0x5D07D5EA19EAA960ULL, 
            0xA30AA7F1A1216FB0ULL, 0x6AFAAD4ACE03EFFFULL, 0x6F990EAFDA408823ULL, 0xAE70A2A5C26CE272ULL, 
            0xC9451C2A92ACE1C9ULL, 0xF3BF0B493483F156ULL, 0x37D89D0DB0EB9767ULL, 0x3B792E8E3613D892ULL, 
            0x79EF7E91116E547FULL, 0xD827FF577EA2A963ULL, 0x40BDCE413EBEC49FULL, 0x5E32C654A30A04B3ULL, 
            0x77897323F865B6FCULL, 0x22C9D755822B0CFEULL, 0x398D31A5E93A79CDULL, 0x928AEC690F8D1CA6ULL, 
            0x16C35AE1DE5A8A83ULL, 0x5795B3FA8541A96AULL, 0xB2F78508DC73B100ULL, 0x9A4BC622C2E3B02EULL, 
            0xD69C93FD2E98A68AULL, 0xFE9B86C97D6D7340ULL, 0x18C927DB1752722CULL, 0x411DDB57048F134AULL
        },
        {
            0xAF12045AA14109D7ULL, 0xB8158FFE559653FAULL, 0x7327C27CD314DE52ULL, 0x85BFA6C2DA30C0B2ULL, 
            0x7FAB7809F1F8D171ULL, 0xDD1F15562D044790ULL, 0x3DDECE5157418614ULL, 0x012560C10A39BED2ULL, 
            0xFA09DE787C936923ULL, 0xB11D498300620A75ULL, 0x6F0E69AD7A9D3B2AULL, 0xAA8A458FCB647ED1ULL, 
            0x25DF8D4D5813B14FULL, 0x82484766758A82F2ULL, 0x3D531340218679A4ULL, 0xC4FAB6FB1D8758E0ULL, 
            0xF9ECF017FA6E5B60ULL, 0x915CDE9E679744B7ULL, 0x604D92B3FA24DCB1ULL, 0xDC8F688CD5A9BB92ULL, 
            0x9C20BCFCA79892FCULL, 0x27C8F7FA32E6AAEEULL, 0xA3576303FA0AF302ULL, 0xB03EA1F618702050ULL, 
            0x71688CDF4B74A117ULL, 0x794A79AE5E8ACC94ULL, 0x83E0D0BC03D232BEULL, 0x43DFA7744CCD3031ULL, 
            0x5251E2111A88D3D2ULL, 0xA38EBCCE677414FFULL, 0x2FC9C2F9C376A00BULL, 0xF779B4C145D08BEFULL
        },
        {
            0xBEA1548F4D7BD9A2ULL, 0xF7FDA3FE3DA4F927ULL, 0x9F20414594A8F091ULL, 0xD9958CC432C3A576ULL, 
            0x99FC900BBF4A46C9ULL, 0xC470449FED6B36DBULL, 0xBB9E9C61EF6C876FULL, 0x462930EC6ECABC12ULL, 
            0x507B22389A06A8C5ULL, 0xAC152E2DFFECD3B5ULL, 0x9D5625465EC61DF0ULL, 0xFB6574E98F38556CULL, 
            0x29DCC545452E02F2ULL, 0x64F85BBAA598EF73ULL, 0x670C368DFAF2999FULL, 0x8454CBD42C7795E7ULL, 
            0x31C36057FFDFA8EFULL, 0x260BE6529577DA38ULL, 0x94E08E1DABD66F03ULL, 0x733F711C1467D1FCULL, 
            0xD064BACE805179CCULL, 0x605DF33FF856EDBDULL, 0x3D485C36E7F1696DULL, 0x2A8251BDDAA93F75ULL, 
            0x733758505247BDDAULL, 0x66AA2978CD765C28ULL, 0x0BA3A9C7D62D112AULL, 0x6A18BA919DC37472ULL, 
            0x281F8840C4126079ULL, 0xCB3B49A970BDE934ULL, 0xBD2BCE8849EF5322ULL, 0x0BAFC3152B192BE6ULL
        },
        {
            0xEEDEA6C7825A030AULL, 0x792B9179AF0AB00FULL, 0x625EE7AF5DFD8483ULL, 0x23664C99D7A073C3ULL, 
            0xCC6EFC09CBAB976BULL, 0x9294459CA821A928ULL, 0x9C77686F32631775ULL, 0xB6DB213721D1E606ULL, 
            0xFEC6270CBB41FF78ULL, 0xB976B63CBBBAC272ULL, 0xBB283D327CBE6ABBULL, 0xCC1D6041E301784EULL, 
            0xB2FA7D6888DE1C4EULL, 0x308C6D033CC87088ULL, 0x855C1F3905E0706FULL, 0x38E5F1E861BCFA0FULL, 
            0x4470D40AB4F0318EULL, 0x25C338BAE7719A15ULL, 0xEFD43498D409E9F3ULL, 0x20908AF5EA2ECF6BULL, 
            0x97A8335F96B1CFFFULL, 0xBEE2C655756351C2ULL, 0x97BC4DBCCD666F1DULL, 0x18395B230DD9CD4CULL, 
            0xE9FE6E8BB67B27D7ULL, 0xDD912534A007AC14ULL, 0xBD52DBB9B43042D5ULL, 0x14B1A2D8DC6C1CD1ULL, 
            0x2871C95047305CFBULL, 0x16D57B950D6D29DAULL, 0xF64A4869998EF107ULL, 0x63CB8814FA57498BULL
        },
        {
            0x1F154AED6CE5BA12ULL, 0xCA5DAEAA63A87C1AULL, 0x68205F3E89464F94ULL, 0xC1D4D9FCC291854CULL, 
            0x4CE2CF3F58D7A2A1ULL, 0x85D957B0CBCF02D4ULL, 0xA10955A5CA75F57BULL, 0xEB210BDC986C12F1ULL, 
            0x68DDCA3EA47C16FBULL, 0x2C33DBA70FA74AC7ULL, 0x41C7E113B1287CAEULL, 0xBBD5E67E32E9ADB5ULL, 
            0x207BBC479A6BFF8AULL, 0xC23AC953099CA98FULL, 0xCB429E2C2856C28CULL, 0x5DAE083DEE1FC9A9ULL, 
            0x8D8E32B55315CC45ULL, 0x7528C8B59D1B8B16ULL, 0xB20152BC12C7412AULL, 0xC6DCD75ABFBFE8E5ULL, 
            0xC24FF987A18EEC01ULL, 0x3C992B125E63E5F0ULL, 0x04E90D4756ED3076ULL, 0x4572563E87A941CAULL, 
            0x86B0A9F0AB74C45FULL, 0x9E1CD6BED692EAE8ULL, 0x77EE7EE9827AFCEBULL, 0x44DE4C767CC8121DULL, 
            0x702B28DACD38CAE9ULL, 0x16D5325F9E9E2582ULL, 0x35976F56B4519091ULL, 0x944375CC67382B4EULL
        }
    },
    {
        {
            0x6B1C559FA48C48A5ULL, 0xA39EEFE6B6FA35B9ULL, 0xE7FAE103AD26856EULL, 0x373A450E7C497CCEULL, 
            0x64F7191812CC4F51ULL, 0x803510EBBEFA4F90ULL, 0x9ACDB7B5E2BDD13AULL, 0x5BEA6CF1295B92E1ULL, 
            0x74EFCAC8E39B08FFULL, 0x6FBB7E590BF4FCFFULL, 0xFE2E4F33548D5EFFULL, 0x9CAA2D7427F61350ULL, 
            0xDA82777E86B806E2ULL, 0x22D74498943D5E20ULL, 0x051C73A2F95329E0ULL, 0xA66CB3AF2A88133AULL, 
            0x6A8DEAD9495113DEULL, 0x42F696ACD2DA57A5ULL, 0x2ACDB76C3812C9D8ULL, 0x80D8DE87F93852BBULL, 
            0xF70A73907626D788ULL, 0x90DBD9C0B403BAA2ULL, 0x285A5800060AF545ULL, 0x4478D41844325027ULL, 
            0x720125E152DD890BULL, 0xA341E5DD9796D6F8ULL, 0xBA2E785205A824FDULL, 0x619B04EE55CF1284ULL, 
            0xF4EAD7499C749BEAULL, 0xC22F4FCCCA3E87EEULL, 0xF11033B25CB62FB8ULL, 0x2011DF3B5F26E13DULL
        },
        {
            0x4191A651ABF4F019ULL, 0x020D46030088E4C1ULL, 0x3C6F7A54F46E660EULL, 0xB8BA6B0EE99F794EULL, 
            0xEC85ADECB3A35660ULL, 0x0CAA8226E8C6002EULL, 0xB7A687C0FC4B0D3AULL, 0x9AE23EA63BBBA44DULL, 
            0x8006319F8964973FULL, 0x0AEA96D3375014E5ULL, 0x18D1F794B0634212ULL, 0x52CEF1A52B33C5E4ULL, 
            0x7083DB1891154DD5ULL, 0x488E887737C1409FULL, 0x9EE6327327742DD7ULL, 0x67311540169EE2EBULL, 
            0x78C9F68C4C09D64FULL, 0x36CD5D2D08D331E8ULL, 0xA232992CBD78D7F2ULL, 0x7D41B1EFF668D3DBULL, 
            0x7816FAA4EBB13DC3ULL, 0x5973DA0115720926ULL, 0x3404A005FABB6526ULL, 0x83B20C8ADC9C289BULL, 
            0xEF5A09E7E9C7BBC0ULL, 0x7C8C44A1B193E317ULL, 0x10369F177C074E43ULL, 0x6079608CEE94F793ULL, 
            0xF5F755B9BBB343EDULL, 0x6AFFE30406E7EBFFULL, 0x963C9153CCCED571ULL, 0x3B6F8C41C4A94204ULL
        },
        {
            0x4A107A0085C44332ULL, 0x42E2EF67E6AC2D06ULL, 0xA148121BB3FDE213ULL, 0x427BEF7500F22ABCULL, 
            0x65FA11B8505C6B52ULL, 0x909BC12483A30834ULL, 0xBBEB7E825C34B4C5ULL, 0x7D90B1841CBF5705ULL, 
            0x2308422F1A01B7FFULL, 0x06D6B8925ACA343DULL, 0x74B31C9011FEB74DULL, 0x603170A84C15CD88ULL, 
            0x78D099F16E3C2984ULL, 0x378A116D9504EBA6ULL, 0x5F988F4E084DC105ULL, 0x1D895D4B18BD7D45ULL, 
            0xF37DC5ABB09D0831ULL, 0x54CF60E91AD30A0CULL, 0x740F4DA8174F4C80ULL, 0x14BF2B5F578C1382ULL, 
            0x24CD8E1DE8631800ULL, 0xEB186EC82EB6351EULL, 0x5B5867A69EB6DD04ULL, 0xE7A0EFC433ADCF06ULL, 
            0xDE241B21161943C9ULL, 0x3471A0220B6FC846ULL, 0x9A5D68CCB0289339ULL, 0xEB8F4A61F478870EULL, 
            0x5C49977281C79E4EULL, 0xF02548407F85A729ULL, 0xC927E7AC53B1F757ULL, 0x671F06B2E4AD402DULL
        },
        {
            0xD4CBDA1A1AB1AA8EULL, 0x0CB5632F52E1A91EULL, 0x841C8DEEEE524E75ULL, 0xDB29A58F7EADA104ULL, 
            0x15A4D57F33153D6BULL, 0xCD2774802E071C6DULL, 0x7F07BAB12E14ACDFULL, 0x58785E035276F746ULL, 
            0x6FB44F01EA098061ULL, 0x53F5852AC6EAFC15ULL, 0xDE229EF38DBF07B6ULL, 0xAF287A3534829CC6ULL, 
            0x852F523BC924EB32ULL, 0xD532F41BFDFE9650ULL, 0x1C536EDD3A6B5EECULL, 0xFE89C2681ADA567DULL, 
            0x128B7C5DD1FD17FBULL, 0x423072D1307879A9ULL, 0x8148754C7EC49A76ULL, 0xB93FA1793F0E914BULL, 
            0x74A6BBA8CF0F6D88ULL, 0xB8EAEC5BB5DAFF74ULL, 0xC504293C1A9A1A3DULL, 0x64CB40C4FF1D2912ULL, 
            0x2662DAB1D5156AB5ULL, 0xCA20412AC5C3B0D8ULL, 0x6468E91F250B1EADULL, 0x0F35B524DA6AE7E9ULL, 
            0xF66834094D0AA30DULL, 0xBEDB2A06D8CB9EFEULL, 0x21CEF7ADC85CAB03ULL, 0x94B41C8795B57A78ULL
        },
        {
            0x706403889311AB05ULL, 0x3A1B600FF867D013ULL, 0x79264E8D7630774DULL, 0x6AD4B7321ACCCE42ULL, 
            0x795EB268D9C88434ULL, 0xF92061C30720BD4AULL, 0x57B145D36B92DAF4ULL, 0x29E085AA8B9DC796ULL, 
            0x33E08D09CBD7A17AULL, 0x34B84A42A2D1B95CULL, 0x819265E52471EBFEULL, 0x7173861128CFAAD9ULL, 
            0xBE07F6F4DDE573D1ULL, 0x3D71FD18334C73AAULL, 0xFE5B8D22735D5B69ULL, 0xCFB7B4705C5CECF0ULL, 
            0x5A4EFEBFB340BA5DULL, 0xA01A0CDEF3C18704ULL, 0x5EA758F1ADD9CEF7ULL, 0x6A89DE77E0A12EA1ULL, 
            0x8234F55DC49F6137ULL, 0xD7C25845DE8C69BEULL, 0xE7620303C74BD1F3ULL, 0x69E4E8446E9F9851ULL, 
            0x9B3DCED4A5AE734EULL, 0xD1520D2F23ED7B92ULL, 0xED472C48889DEE29ULL, 0x6A202640520F207EULL, 
            0x1B59E31978D61BA4ULL, 0x346FB80EC4B95AC7ULL, 0x3722FE88E662708CULL, 0xBCF5928C41AEA58BULL
        },
        {
            0xCDC057AD7A02A3A5ULL, 0xBA8A1C2260B8A7B2ULL, 0x0EB0544CCECB30D6ULL, 0x2EA3FC7C25D3D4E4ULL, 
            0x15C6FE4531CFAC75ULL, 0x1620907BB2FD8FC8ULL, 0x5BD0EFDFCFFFAEDBULL, 0xE8EC02C53A7F58D7ULL, 
            0x72E10229B600D1DAULL, 0x447163988F78B96EULL, 0xD3F71EAD68259AFDULL, 0x1222D0EDA077745DULL, 
            0x17D09D770F361CDFULL, 0xFE89C85FB9A91595ULL, 0x201B9FC3166C6D2DULL, 0xC1E0DEA41433836CULL, 
            0xA8686E3E968D56B5ULL, 0xBE1743F68DE17614ULL, 0xA2EAEF8C7BBB35AFULL, 0xDD9D0AEBFBBEA36EULL, 
            0xBD79A01D1A2D45FBULL, 0x019FAE06D46CF56DULL, 0x8B31D552F9AFC993ULL, 0xA3D3C9E843744401ULL, 
            0xCFD66DD28726A4D9ULL, 0x35AD36D2059B6F2EULL, 0x27DC045FB7AB8955ULL, 0xC214E86C71880E61ULL, 
            0xA626B75CE9A51DB7ULL, 0x2C60EFA5A2FF22D1ULL, 0xAD0DE7A569FEF549ULL, 0x548E7857DA50D37FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseEConstants = {
    0x79E17E221EF32548ULL,
    0x423DE4B9AA947142ULL,
    0x8C833143F09B02FDULL,
    0x79E17E221EF32548ULL,
    0x423DE4B9AA947142ULL,
    0x8C833143F09B02FDULL,
    0x0E45CB0B307D0AF6ULL,
    0x58EDC1D8A0DC8AC9ULL,
    0x69,
    0xF0,
    0x8C,
    0x50,
    0x59,
    0xDA,
    0x63,
    0x4B
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseFSalts = {
    {
        {
            0x3AE5ADA233FEC3D3ULL, 0x1B303A4C7487B9DFULL, 0x52CFB19DC7CB1D41ULL, 0x95C404D8530EABACULL, 
            0x0574274DF257739BULL, 0xBB7F56CA62D369D5ULL, 0x3F31EB4A317FD4C8ULL, 0x47EC0ACA9ABBEDF0ULL, 
            0xAECEC9454D022197ULL, 0xAACEDE9883CFA7A2ULL, 0x4A448B6EB87D4C26ULL, 0x41E1E64DB66CF623ULL, 
            0x556FBB241CC18320ULL, 0xFBC5DEC6C1AA8920ULL, 0xC15F41CCD64A08ABULL, 0x27FAD1F1DAC5ACFEULL, 
            0xCD5EB6ED944EB443ULL, 0x95C2DC4909C5FF0EULL, 0x1094D9829B7350F5ULL, 0x6D1DD0969723D214ULL, 
            0x214E592514CC444AULL, 0x85F5D12980EA43F1ULL, 0xCEC325824BA6EE50ULL, 0x93A461EFB6638E06ULL, 
            0x6667E95C77FC613CULL, 0x5B678839F93F417AULL, 0x2D4CCE82360AFA6FULL, 0x5D3A0B54EA541641ULL, 
            0x7FF81F224E98C271ULL, 0x4DA92997E1A70072ULL, 0x61590BB150ED21C7ULL, 0x072DFA9A1C0FCA7BULL
        },
        {
            0xBD55F03A71B48636ULL, 0x799D6F60D68CA469ULL, 0xE18C0EDB75C0E72DULL, 0xFA23623202094C9BULL, 
            0x31D4AD59FF089F41ULL, 0x68ADE14CAC0FEB97ULL, 0xF4E2437E9C4D886EULL, 0xA24933178F2F0006ULL, 
            0xF4236A2B38D09657ULL, 0x208DC8F93D2E07BDULL, 0x7EF7F330AE42A181ULL, 0xEEBBCD12CA12D46CULL, 
            0x7D7630792F32261AULL, 0xABD79BBBFFEC9E36ULL, 0xC97A7AA44D8C1C7CULL, 0x222A8FE1EBB5F725ULL, 
            0x4483F8F0A7EDB3A5ULL, 0x7BBC12D594692DC7ULL, 0x4A7DFBED66F570D3ULL, 0xE989B0490181AB79ULL, 
            0x8E74C23EF87273CCULL, 0x4A67DB855155DC55ULL, 0x9FCB812BCE24F2F9ULL, 0x3B9574B4A426C8CDULL, 
            0xA1F67FD6C677224FULL, 0xB2AA378BC92E0232ULL, 0x9787551E378334D2ULL, 0x7750381684B2A140ULL, 
            0x51D158C1D61EF50FULL, 0x0F6EB851D91FE26DULL, 0x9C1DD70DC66C79ABULL, 0x7CDD8C85C5E30E7CULL
        },
        {
            0x0B1204B1D229222FULL, 0x2A9AFAD1DFF922ECULL, 0x3F677D70FC6F1307ULL, 0x0DAA0FBEE904F3D3ULL, 
            0x4C26A4C9331CD3CDULL, 0x60899D4990FB1195ULL, 0xA0B12465F1978770ULL, 0xD8CE24ED5328DA3BULL, 
            0x71B5F449E94CBB22ULL, 0x22D25794D50872A0ULL, 0x2F9E75F709AA78E3ULL, 0x6E111F6B87A28813ULL, 
            0x0C1B2CF761BB14FCULL, 0x9BB221CF359B2EE4ULL, 0x3836027F5BE51DC5ULL, 0x4A237F90B261F70FULL, 
            0x5237EDECB1FEFD50ULL, 0x0CE723EFA1A0A303ULL, 0xCD233E6178B83844ULL, 0xD9FAE1599A545187ULL, 
            0x38F898DF48C94E4AULL, 0xF874CC9B37A76089ULL, 0xF34873C3429AB238ULL, 0x0EB18262F7B75062ULL, 
            0xF23B824321AE4747ULL, 0xFCEE499197026B5DULL, 0xABBE3B5F6EB73964ULL, 0x69ECC757F9AAAB97ULL, 
            0x3F638E2D90746836ULL, 0x67A27B536138873BULL, 0x6C2DD5DC313F0D87ULL, 0x02904ED1FD28F6EAULL
        },
        {
            0x21D06F839825AEFAULL, 0xB312391D69C5E407ULL, 0xEA4B3545019B196AULL, 0x6DC499BAD1354CF0ULL, 
            0x8EC9E5203FB59CF0ULL, 0xA07AED548E52E6D7ULL, 0x6D5D9957D5AC11A2ULL, 0x8DD0537C38D6B119ULL, 
            0x4E08F89E28C047A7ULL, 0xF4B0F293414E4216ULL, 0x0220731B21E12F5CULL, 0x7928B1BFB7F7DC0AULL, 
            0x3D08CCE6ED05A932ULL, 0x56198842734B542AULL, 0x4FC4226971B01EB4ULL, 0x984D2655D694865AULL, 
            0x1CFEBEC2F0DA8A9CULL, 0xD1CC876005A88CBFULL, 0xC6B828D464DAF774ULL, 0x02AC56DF2FFF7F8CULL, 
            0x9437425F04575ADEULL, 0xF54D71F106CCF7CAULL, 0x8425FF750897471AULL, 0xE4AE7E9B22A5705BULL, 
            0x3254BFFC5521C794ULL, 0x4C252C8CD5F08D66ULL, 0xB68F8978A912F50DULL, 0x7369743020B1762BULL, 
            0xBBB126E8B8F56933ULL, 0x089028990BC42663ULL, 0xCBFD9140F1863E9AULL, 0x4D4EE750DA2A8C0AULL
        },
        {
            0xBD46EC4C3884C789ULL, 0x757CBB63617AE784ULL, 0x8BBD7EAD0DE9826FULL, 0x969055CF0C31B383ULL, 
            0x9F214E3501D6D4CEULL, 0xED7E2641B29382F6ULL, 0x93079B376E84CF7BULL, 0xC280743F49544AC5ULL, 
            0x685E5A6B41868F4EULL, 0xEC7E90BD6E7AB7BCULL, 0xEC42E50684738FBAULL, 0x218E47261D19C568ULL, 
            0xFB686B69C8599B31ULL, 0x915CF2273B310214ULL, 0x7A5B5D4DD0EE1EC8ULL, 0x51E6E6422DB78E65ULL, 
            0xBD5C921BD7EA5201ULL, 0x3A0AB4E3C216E52BULL, 0xE54E62EFD478D8C7ULL, 0x2A8ACC9B2D79F21FULL, 
            0x152346E66703AF77ULL, 0xCD230F841BFF775AULL, 0x44A892795EE5777EULL, 0x224A74648C5D7C92ULL, 
            0xC93BC305763B6DB8ULL, 0x59EFA8DA1F0B0347ULL, 0xC17CEFCDB2585E03ULL, 0x90D0ED8EB2F99E62ULL, 
            0x4F16D3E7F50E827BULL, 0x73D8F9308F08602DULL, 0x3F077076FA9E961AULL, 0x5123D54696B852AAULL
        },
        {
            0x5468E7023316B43BULL, 0xF8BBA76F1C638CA4ULL, 0xA0AC56DEC9A7D55EULL, 0xF35503363C36A234ULL, 
            0x23B44E0DF12BA49FULL, 0xD1AE95799AACD3A5ULL, 0xA98EE0124C8AE691ULL, 0xFD5B37AC4D0B777BULL, 
            0xD4E3E2DD195CD928ULL, 0xD699C2610FE84C20ULL, 0x27A318A7327D0AEFULL, 0x7304E45082709ED3ULL, 
            0x9D9603C451C6CB62ULL, 0x92FDDF406E0F9872ULL, 0x38B095A12CC3E51DULL, 0xE2762077CC631B84ULL, 
            0x791AD1F827DA1F68ULL, 0x1ECF436B8EE9B7E1ULL, 0x799965EC9A46F750ULL, 0x5ED6B5822343189AULL, 
            0x1D5956CEB634538CULL, 0x17BB51E5C152A5F6ULL, 0x9C23849EF693B0F3ULL, 0xC4C12359032E2C82ULL, 
            0x11EDBE3B9239BB6DULL, 0x28A701337F682E56ULL, 0xB4A35CA76353F1D8ULL, 0x3DAB6EE8FA4374C6ULL, 
            0x1A6429CC52ADE969ULL, 0xD482721A0F1E7A21ULL, 0xF06ADC783256F6F1ULL, 0x7A673E0526CBF833ULL
        }
    },
    {
        {
            0x02BF7F1BA961EF90ULL, 0x9AB5CB19AAB77ABBULL, 0x66D8CB7DF1336AD1ULL, 0x95DB653294C58408ULL, 
            0x8F81391E0B2F2EF7ULL, 0xBA95C16C30DD3390ULL, 0x49625121FB3C8EC0ULL, 0x792F994235A595F1ULL, 
            0x30D8A8C19B31CEC5ULL, 0xB53F44534DF40DD8ULL, 0x6BD0E1E6B2836234ULL, 0x0054F4AB573A1845ULL, 
            0x7FBFEED08FDB63A1ULL, 0xE8079EB35951C56CULL, 0x908780E006764E4EULL, 0x151B7F044AB4E957ULL, 
            0xA3CAB6BC3922A7A0ULL, 0xF40117EAA6659044ULL, 0x9AEAA31A9C28701AULL, 0x3A87FA7CC631F8CBULL, 
            0xDB15AACCE67C1476ULL, 0x73415F587CEC0421ULL, 0x72E3C726475E6D61ULL, 0xBDA1A6BD90A1A3ADULL, 
            0xB117930B14857BBCULL, 0xC19D7C52F9D9CD03ULL, 0xF8A32CF48ACD0C36ULL, 0x1CCC331635005743ULL, 
            0x67FE1D6295725FBFULL, 0x3CD5763B2E386A73ULL, 0x3D5D4F68C9EA1F92ULL, 0x671939AF925CB68CULL
        },
        {
            0x901095A9C280FF8CULL, 0xDCA149EB41AF965FULL, 0x3E4A04028F3140C8ULL, 0x7BFE245C828AEC6AULL, 
            0xA0169CCC7A559D7DULL, 0xE05DE177D6346411ULL, 0xB946A2E6DA1B2784ULL, 0x87DE929FDE3B6845ULL, 
            0xCDCF8E834C4E0772ULL, 0x6A216230AA865BDEULL, 0x26C709EEF2E315FDULL, 0x9991060D59ED1A36ULL, 
            0xD9295B142E5EEA47ULL, 0x0FBEE2D76E1C11E4ULL, 0x8BEEE87FD363D564ULL, 0xC2E06B4BA1D31E50ULL, 
            0x6CD6D99C4AC43367ULL, 0x3C1EDA6FC17D5B49ULL, 0x627317F8A2A916EFULL, 0xB0F7F74E0425E0B5ULL, 
            0x405A5905D538B1C0ULL, 0x271C87E05021E430ULL, 0x4216FD63D91BB2EFULL, 0xD335F09DE487EAE9ULL, 
            0x1E547BE603F6EDD7ULL, 0xF8FF3A59EDE5AB84ULL, 0xEF5DE48D6BBB0419ULL, 0x0E976EB66F9B383FULL, 
            0x376682499F9BA415ULL, 0xEA9A562902D51BB7ULL, 0x4BF745DC1988DBFFULL, 0x203A1616F199028BULL
        },
        {
            0xCF285D005A6BDD86ULL, 0xF9D9F6CA393F4D49ULL, 0xCFEC5AF034E02E28ULL, 0x2699CA2ED012D4D0ULL, 
            0xB69EA3871A590DE4ULL, 0x1976B2D3D9721ACAULL, 0xED0BEE43C804F01DULL, 0xA918AF357D14A5D7ULL, 
            0x05B5B8555465FE81ULL, 0x5B5653CDB190DA94ULL, 0x75364A8DE0702335ULL, 0xA248417C3F6D59ADULL, 
            0xE9D7799EF7E19B0CULL, 0x3D9D88DF48BA1F3EULL, 0x6351B61F3FF576D7ULL, 0x219407E8B9B59A98ULL, 
            0xFA840D83DA611A11ULL, 0xC55CD5A114DB8D7EULL, 0xE6A4DB35023EA73FULL, 0xB47A9691A7F56FCDULL, 
            0x73B391D880B31288ULL, 0x3723E1D02AD3B202ULL, 0x9B435CED5ED0659CULL, 0x1A8779AD8189AF00ULL, 
            0x9442D92791588BACULL, 0x157D4D1F6E2EC489ULL, 0xDF48461CF6F32B4AULL, 0xA6801179296B46E1ULL, 
            0x779B1E0F2ABDA94FULL, 0x965C3247266028DAULL, 0x41C9EA2119447816ULL, 0xC543A45519973457ULL
        },
        {
            0xC04504200F5D15BBULL, 0x6EC649ED157E3077ULL, 0xCE3CFE9EF9E9B1EAULL, 0x46801F309151A628ULL, 
            0x322A2005D541F54FULL, 0xBE6475DFF54B9DBBULL, 0xE8DE046B0FDD6C8DULL, 0xD69D20823D0A5E7AULL, 
            0xDACF4D375F3E1582ULL, 0x8BC218C9B0B4DA35ULL, 0x49976A1DF33350A1ULL, 0xEA26ABF891C0DE79ULL, 
            0x90B33429D492C48AULL, 0x9BB275492A21A801ULL, 0xFCDB162853824425ULL, 0xFDACF4C462C7C69BULL, 
            0x7DE965D2654A7DABULL, 0x0A0BE325BE65EB7AULL, 0xF186728252A42C56ULL, 0x95336DF01158DA78ULL, 
            0x8892B89DAED5EB58ULL, 0x8B9DD7A57082B66AULL, 0x7233DDEBA95E7650ULL, 0xA0761ECEB6EA4814ULL, 
            0x183125089A6E58CFULL, 0x0F21387716930DFDULL, 0xDDD4F6743148BA1CULL, 0x9ABB769BD08E6375ULL, 
            0x509B59D9B77E876DULL, 0x74C5DDDF136F8AAAULL, 0x56EF414186AFAAD9ULL, 0x126F68C8281F5E8AULL
        },
        {
            0x719AC94934AA581BULL, 0x977EB730428BA9E7ULL, 0xEC1D8D7BB30A399CULL, 0x1B395122683FBCF5ULL, 
            0x51BDA94757810299ULL, 0xDAC8F718860883A5ULL, 0xD32B1F053773BFFAULL, 0x1D888550C1C72545ULL, 
            0x750E34981166B32EULL, 0xC197BD8C4BB78DBCULL, 0x803D356943650C39ULL, 0x1D73E2B12493B766ULL, 
            0xEFA91BBE29A127D3ULL, 0xA8C71ECCB772ED95ULL, 0xC58E4FBF0C6E6EE6ULL, 0xB13F5B2EB39CE593ULL, 
            0x15FE8A5D3719533FULL, 0x6679DAAFC98978E0ULL, 0xFCB9C5EEAFFD7D30ULL, 0x13E734D9DF2C3EA7ULL, 
            0x698FD9D1D993C3DEULL, 0x1F91A7EAFCD98709ULL, 0x99F1877FAC7B84A3ULL, 0x2CA4AC71E5828B4DULL, 
            0x518524C16187BC69ULL, 0x5F4677D339782310ULL, 0x5D329C4663C3576BULL, 0x7F43C71E702B7214ULL, 
            0x41C9CE3855B0956CULL, 0xD38ECD161EC36125ULL, 0xDD339141BD081050ULL, 0x3ADE2C33355988C0ULL
        },
        {
            0x345501907C5C5E05ULL, 0xDA36DC0E72978C62ULL, 0x2085B1DEB2803B1AULL, 0x4932B73AE777CCE2ULL, 
            0xC7B5D9AEF07DA9B1ULL, 0x3F81D84BE93FAE5DULL, 0x0881DD47532F57B6ULL, 0xB4491B8A413D9FBCULL, 
            0x13E1834482BE534EULL, 0x68D181F12C501D49ULL, 0x2006B08AA38EE500ULL, 0x319F372DBF1EE689ULL, 
            0xA55677DE912FDD8EULL, 0xB216D35CF40EB9A6ULL, 0xCC4A78999F9B4173ULL, 0xA8CA5C0F01A50390ULL, 
            0xAF06F73564D6E716ULL, 0x3CE10B4B29A94447ULL, 0x62E304A62EBA6D33ULL, 0xA5A3E2EF420BE236ULL, 
            0x176017E353328A4DULL, 0x7A03FE89F60BFC63ULL, 0x9FB27CEFB07FD22AULL, 0xC65E172BAB59ECC6ULL, 
            0xD6BD0642B401ECCEULL, 0x173537DAC3719E9CULL, 0x8CDFB5D2BA452976ULL, 0x9A0124590D11D677ULL, 
            0x042F16019BA37574ULL, 0xDF1EB183EC410B2BULL, 0xB98517DDC1AF34FEULL, 0xB2A916ECF61C4674ULL
        }
    },
    {
        {
            0xBC5D4C39592360E8ULL, 0x1513C57BA6DBD922ULL, 0xC00A32E4CBD96FD1ULL, 0xF06DC5CD2A304AF2ULL, 
            0x48307E75B714C3D2ULL, 0x941286271CDF1BF2ULL, 0xA1CA78C43D4E796CULL, 0x08C5B2081EBA6F5DULL, 
            0x4F589A0689AA6F81ULL, 0x85B10B8FC914F39DULL, 0x3A2CBE70B23A05A5ULL, 0x7C90702587EDBD54ULL, 
            0x52B312C2B6317F26ULL, 0x536F7E3E70FACBD3ULL, 0xEC51E0CA8D27D480ULL, 0x526B4BA88FE53D69ULL, 
            0x23C450D2EAE9453EULL, 0x2BC80126824B706BULL, 0x70E1FB6745959A58ULL, 0x36EF5D16AAC9CA06ULL, 
            0x0076DD9C8D20E22BULL, 0xDA483029D74713C0ULL, 0x7FC65276DEFE6629ULL, 0xFEA72C1C98B7C179ULL, 
            0xB49FC9AF237E2E0CULL, 0xDC044865FE1B7FF5ULL, 0x2EFD4326F4591600ULL, 0x5BABD7D9930C22ADULL, 
            0xB075E36B7B4B9B04ULL, 0x0807BE5C44746258ULL, 0xEF46DE95F8B8710BULL, 0x03D6000ED5157314ULL
        },
        {
            0xC63C6044E1C4AD02ULL, 0x23DA8AAE7CEA6BECULL, 0x9F73596AA1F0BCE2ULL, 0x1A8C58CBDE70437DULL, 
            0x85759AA4FEE772D4ULL, 0x9F0350E091500A07ULL, 0x036BAD9078E239EEULL, 0x9B7C12D35546B6B0ULL, 
            0xBA7233DA744BD3F6ULL, 0x1D8ABF99149E6CEBULL, 0xAA30046B346999C7ULL, 0x241D47582849D716ULL, 
            0xB0FA76DDCC784806ULL, 0x62A41E1B70111DE8ULL, 0x52862CEF4E2515FAULL, 0x3B7BB097EE30451BULL, 
            0x2B32E872603B8C6FULL, 0x89F6AA1CA8F676A1ULL, 0xB75B0554CAE33744ULL, 0xC366126B901FB283ULL, 
            0x261602897D13AF5BULL, 0x7A76ADC23A36FBB5ULL, 0x31C795B752C8DD1AULL, 0x231D992CAD267403ULL, 
            0x61BC10EAE5A77919ULL, 0xD545AAA21A449704ULL, 0x735FDBA49D47B516ULL, 0x35F29FBB6ACB4334ULL, 
            0x8BB7FF2B480F3B8DULL, 0x37BCEDCD40380E98ULL, 0x0AC38E235E68CA31ULL, 0xE9B60F890F01361FULL
        },
        {
            0x0CCB61A45F657C21ULL, 0xBE7158D6E8A71BCBULL, 0x8635D5201DF868D5ULL, 0x78F8BCE95060975FULL, 
            0x880E8A0FCF2C35DBULL, 0x4E8EB9E4D28B97D7ULL, 0x14BE699FC5EFE05EULL, 0x73DB7D2A185F5AFEULL, 
            0x0B9F16F5BFC33809ULL, 0xD4A74CE557F1F824ULL, 0xF591C925093C236EULL, 0x884C9A74B38C2069ULL, 
            0x3164016C484C2D37ULL, 0x49F6A6595330D3BFULL, 0xC31E97D81FC4FFB3ULL, 0x29E25697F845D305ULL, 
            0xD84837ABCF3FC700ULL, 0xE981B3ED500810D6ULL, 0x38D7947C1D044773ULL, 0x9FDCE2373B452F64ULL, 
            0xA3C994901A06470CULL, 0x8BE47400FC5C0901ULL, 0xCB5E2E823A0B097AULL, 0x4160D3FD9CE95AF4ULL, 
            0x4F93C4BD7E4374E2ULL, 0x8F37BBCB5C3493AFULL, 0x42759DC5D6E52424ULL, 0xF1813350F44674D2ULL, 
            0x8FDADDB594C9136DULL, 0x9F845D2C70565436ULL, 0xD7237957DF3E64A0ULL, 0x45926F34FD73D54CULL
        },
        {
            0x2E82F67F63000708ULL, 0xEF9D02ABAC69A7ABULL, 0x8C1744FB463BE140ULL, 0xD7FEAF56FCD4A745ULL, 
            0xDFDD107E2F7CDFD8ULL, 0x5D88B7CFBF1F59D6ULL, 0xB51DF4C30ED8D435ULL, 0x433D6BDDA7353DAFULL, 
            0xACEFD9CE09F04085ULL, 0xF047E357360BDF59ULL, 0x8924B75EE79FA14EULL, 0xA42904C8C7CC0AA2ULL, 
            0x5B9126EB48F97935ULL, 0x0F9032FF45446F31ULL, 0x8AA1330EF889CD01ULL, 0x68D7A454AC780793ULL, 
            0x54E861AF3BA9F0D1ULL, 0x6A06845895B0DFFAULL, 0x5AD6ED546DA638A5ULL, 0x2D0F2B5A7607E4C5ULL, 
            0x30C6F9A89C4A8230ULL, 0xBC216C5B28AFDAA8ULL, 0x846C94E5105C3094ULL, 0x22B82C573DB785C3ULL, 
            0x75D5B2B547396683ULL, 0x6D3B0F2F9324E9ABULL, 0xC20D343E219063E3ULL, 0x4A22B35263E1F6C7ULL, 
            0xC0B16277AA00E392ULL, 0xDF1469B5596FDE8CULL, 0x8A67C2440CF81CDFULL, 0x3AA4E27E87A5E068ULL
        },
        {
            0x9E8FF089351C723BULL, 0x759F82E27657CC87ULL, 0x733627E41E27277DULL, 0xB73710F9BB2A5D57ULL, 
            0x7CE9D51B82C68C06ULL, 0x49768F25EEF6E45CULL, 0x42E9EF3D1E9FA6FCULL, 0xC600A1DC6C86B803ULL, 
            0x0048C1087B827BD8ULL, 0x5E2412C9386F77DDULL, 0x46DC570330F711FDULL, 0xF6A7A982DCFFA287ULL, 
            0x8C3C67F9BE04921CULL, 0xAD0733A9C96F4980ULL, 0xAEE4E3C97CF557C2ULL, 0x3FB790ED2FB7EFA1ULL, 
            0x668A120516E0CE01ULL, 0xCD84B8901C7FE0BEULL, 0xB4D2F5FFB59CACF3ULL, 0x529365D42B46FE60ULL, 
            0xA3425A6EC3CE3DBEULL, 0xF9014825D14F57E0ULL, 0x22A88B14DFF6DCDDULL, 0x7CF25D4FFA58AD88ULL, 
            0x4C69A2638BC34042ULL, 0x80B66E4E4992DCEEULL, 0x7324F576E292E975ULL, 0xDA87924852CE513DULL, 
            0x3E887F5CBDBFAA06ULL, 0x10EBD7180994D195ULL, 0xDB7C6440CF4B1B64ULL, 0x67C61BD7389083EEULL
        },
        {
            0xBC2ABC2543372875ULL, 0x30133310CD08F8E0ULL, 0x90724F5E1EEA3135ULL, 0x34C7EED4539EFE71ULL, 
            0xB1CB309624AD8B34ULL, 0x2AFB4B740B913CC0ULL, 0x60F49AB12461250DULL, 0xD9AF91043A4C9F45ULL, 
            0x558D6015DB078FA7ULL, 0x66D22C05EEC2B93FULL, 0xDE1E99AA0B7AAB68ULL, 0x129D2A1770A8CEE0ULL, 
            0x6AD874688D838C8EULL, 0xD0E1430AC3E38C4DULL, 0xBABC6CDA8E229307ULL, 0xCD911D455C461D15ULL, 
            0xD529F482336F03EBULL, 0x1B9763001F6CDA04ULL, 0x0CE5C7A1440294E0ULL, 0xE9187F5D092589AFULL, 
            0x99DA1FD427AF566DULL, 0x094A993B28B5AA64ULL, 0x6F11B2F2CCF08E7EULL, 0x5253DE3EA00D7D42ULL, 
            0xAE02FBED0A4325A1ULL, 0xE8797360B9C3EDB5ULL, 0x0D01515B12FE7C16ULL, 0xA979CD4DA79C1290ULL, 
            0x9DA739D61F266AFDULL, 0x4CDBFBA0BE09D030ULL, 0x90D2FF9B345A735FULL, 0x65E5DBA01A25D964ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseFConstants = {
    0x2FBC07D8ECE8D577ULL,
    0x751A73145436FCD6ULL,
    0xC259E5FB8FE10C07ULL,
    0x2FBC07D8ECE8D577ULL,
    0x751A73145436FCD6ULL,
    0xC259E5FB8FE10C07ULL,
    0x4ECD314F861E21F7ULL,
    0xC25D08EABFB1EC07ULL,
    0x18,
    0x36,
    0x90,
    0xD9,
    0xB1,
    0xC9,
    0x16,
    0xF2
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseGSalts = {
    {
        {
            0x451FE72E9C7F1A1AULL, 0x38C7192136292D98ULL, 0x050CEF0DC8163772ULL, 0xFBD3D90FC4BD1F33ULL, 
            0xC1C76D3162E9F0EAULL, 0x4B5906DAB4B80D1AULL, 0x4DE9B7E9975604ACULL, 0xA41CBCB576F5BDE3ULL, 
            0x2FBBA134AC889CF3ULL, 0x499DC7195C808B77ULL, 0x3A3DB917B680DD9DULL, 0x58F2E762D6DAC433ULL, 
            0x2010BADF9F4799BFULL, 0xB1EBAB995AF18506ULL, 0xF19BF90D0A7AC430ULL, 0xCDDD8DE18871C6FCULL, 
            0x0BADD43E2EA697EEULL, 0x08BBAA8F0CFEDBD0ULL, 0xBAA79DABE746D4E2ULL, 0x3DC24208F88C3107ULL, 
            0x0BCFBE7CAD4A9B59ULL, 0x0BA79934F6CD23D9ULL, 0xFA759147B6A8AB06ULL, 0xBC30A095FD6F38E7ULL, 
            0x8C3B7355A8078A06ULL, 0x066DB44647ABE866ULL, 0xB84C423E9D5447E4ULL, 0x544B627469BF59A8ULL, 
            0x9D43484FB0A748A2ULL, 0x721B109C5C6E6060ULL, 0xA132C3E9D2E2C792ULL, 0x500D4D6DEF0FEBBAULL
        },
        {
            0x545FF8F4C7D7F1C0ULL, 0x2CEFA924A5FE733FULL, 0x15434BAAF83ABBB0ULL, 0x9B47D89E3363183AULL, 
            0xF48F2950CD649E07ULL, 0xC3B63FF97DA28451ULL, 0xD112A759712DE33BULL, 0x7FB988591349D59CULL, 
            0xA7C97A8BD9B9B1A2ULL, 0xFA4F96164D15CA9DULL, 0x42AF7985F37D729BULL, 0x94B23DD973A62586ULL, 
            0x61A4004B94C08A92ULL, 0x52F2796BEAE967D3ULL, 0xCEC255ECBFC56B41ULL, 0xD43BE6DCB439066EULL, 
            0x60DCADAF3E57F4CAULL, 0x812CABA8007E79E2ULL, 0xC939A347D10144FEULL, 0x6B333D41A51B9392ULL, 
            0xEC6F86FC2EBCA689ULL, 0x8042052849E5D839ULL, 0xAFE7A484631B33B9ULL, 0x04E4EB63837C03F2ULL, 
            0x8A308C88E0A7279FULL, 0xECEB32C924608034ULL, 0x9CE9C317E8D2781DULL, 0x9AED92156BE20521ULL, 
            0xC5E3582E7EDB0B3EULL, 0x4584B6AC790D4208ULL, 0x78A0CB4FC232E412ULL, 0x350737113D747F6FULL
        },
        {
            0x828BEF500133D0E7ULL, 0x0F473782CEFA62EEULL, 0x29C6ECA406625CA7ULL, 0xAD3837172D27FD51ULL, 
            0x393619D48AC07371ULL, 0x8104CC91BA9A0421ULL, 0xCDAB3F6F92261A53ULL, 0x1DCD8D0788B7E7F1ULL, 
            0x8ACF27F01D23A024ULL, 0x361AEA3B6778CF3DULL, 0x9A853A0ECAD23F9EULL, 0xAEB714B4DA58D74CULL, 
            0x150EC6A39EAC3FA8ULL, 0x36D20052AD54B0C0ULL, 0x948DB0C539477DB4ULL, 0x992E3EF6E9828888ULL, 
            0x9ED8146E4AF2009EULL, 0xC92B5231BE3CD730ULL, 0x5AA8B762EEC8396BULL, 0x5AB95F1000C3C5BBULL, 
            0x8D4DB9926058DB9FULL, 0x66EA9242E2EB7E0FULL, 0x9B041BCA15032001ULL, 0x7D31574C80276543ULL, 
            0x0DA1FC41403DC613ULL, 0x56367BB55C70239FULL, 0xCEBB06AA98049B2FULL, 0x6D09E14540685B09ULL, 
            0x28DE1AC91DDD9349ULL, 0xE23A306B9842A691ULL, 0x46C627DB61356240ULL, 0xFF1924BF44FCDA57ULL
        },
        {
            0xBA5AC61C9390384FULL, 0xF3552D5A1BAB6B6AULL, 0x48E4FA17D75CC065ULL, 0x3866C1A08E2A408AULL, 
            0xE68B3EB42AF471F5ULL, 0x6434B3F3D7482392ULL, 0x404826D74EEB47E6ULL, 0xA7CFE46776B1DF35ULL, 
            0xFBD84680135436F5ULL, 0x2022695DB7C3165AULL, 0xC1CE9C814226E6D5ULL, 0xEE899B183C7D39D7ULL, 
            0x5BADFD10B8372335ULL, 0xF4E82114229A1B81ULL, 0x85FFB092D149E623ULL, 0x814C847787C6E641ULL, 
            0xF38C4A9B3E6A86A9ULL, 0x105CC4288D5B9229ULL, 0xF47A929E98272AAAULL, 0xF3F5FA6B3C399123ULL, 
            0x30E2ADF61F4B89D0ULL, 0x70A8C60BA5DE130CULL, 0x4FDCF2836B77F797ULL, 0x98457329C69E12C9ULL, 
            0x92A464A764389708ULL, 0x75ADCD107D8DD9B6ULL, 0x4F961DEAB70BF628ULL, 0x59B101AC01AA1BA8ULL, 
            0xBD280A3CA4987D3BULL, 0x99E15890A0005133ULL, 0x6167557F766FD9F9ULL, 0xF9CAA519628DD532ULL
        },
        {
            0x103ADA7CBC5CBD93ULL, 0x3893FF19ABA4E4E9ULL, 0xF7B64E895D532FEEULL, 0x72EE45A664FFD11DULL, 
            0x3BABBE62E3CFC093ULL, 0xECB0A7ECBD0A3ACEULL, 0xE5BF1B3FCBDB7B38ULL, 0xAD22423D381B042FULL, 
            0xFC09FE6DE8527F3FULL, 0x5FDDE59854BF1BB7ULL, 0x828B060F43B2A65AULL, 0x632FA2FD3A1B8636ULL, 
            0xC76FCAA453B0E2C6ULL, 0x4FD00BA9AEB905FFULL, 0xB95D6C2F44FD220CULL, 0x28416741704B8FB9ULL, 
            0xB4612581A4E1BB18ULL, 0xD7BF58D086D8EAC1ULL, 0x92855A65C40B9256ULL, 0xC0DBEB89EFBA54F0ULL, 
            0x65172729C3891F54ULL, 0xB7250069B231398FULL, 0x3B08E28E30E30A52ULL, 0x962E97D0D63C2548ULL, 
            0xC82786A9735C9F3EULL, 0x6ADA71FBC35AE68BULL, 0xE143D315CCEA49B7ULL, 0xF503AA8377D3EC33ULL, 
            0x375AFDFA30422F79ULL, 0xB3923E161D0D0922ULL, 0xE003540862CC2C01ULL, 0xB2DA898B4ADB9BB3ULL
        },
        {
            0x96B47A4802DB1442ULL, 0x7E712D1290B5EBE8ULL, 0x5303F131DB2AFB94ULL, 0xBABCEFCCA5982D7AULL, 
            0xACC8FC6F70B26DCFULL, 0x350BF8CD57E3BA1BULL, 0xDB4F5ACA8934DB85ULL, 0x2F55FD0AB75792EEULL, 
            0xC1AA52DCA47A4E39ULL, 0xDEE2A7BEE805BF84ULL, 0x490ECA297D783011ULL, 0x82740D6EC0AF4D0CULL, 
            0x4C501606CB0ABCF0ULL, 0xF3D3DCBFC9AA77E3ULL, 0x337E2EB5F846AB6EULL, 0xE866EB7CD7E7BAD6ULL, 
            0x81D9D96C0AAC8CB4ULL, 0xB697282AB72EFE21ULL, 0xBC4C6BB79B083612ULL, 0x95F7D2A0B47CB9A7ULL, 
            0x85F78D4212CBA7F7ULL, 0xDF33648B02A07379ULL, 0x26099ABC446E6EACULL, 0xBD576361FB37769EULL, 
            0xED925B60C534FA05ULL, 0x1FDDA0D0CA18301AULL, 0xF099DDBE17F43996ULL, 0xE71731D0B4F44185ULL, 
            0xE60C133164D45919ULL, 0xDBDC3EAD2C1ECCBFULL, 0x20E72B0DE93E69F9ULL, 0xC12D079038B04695ULL
        }
    },
    {
        {
            0x644D355ED99E7821ULL, 0xB8F3CC060BA979F0ULL, 0x49809784F62A112DULL, 0x3C219B671C047B9DULL, 
            0x0E4322B9C84E2114ULL, 0x9719D56315D1DF8CULL, 0xB346EA60A71310D1ULL, 0xF88149B2F01C3508ULL, 
            0xEFB289B61D0A2379ULL, 0x23ACE16CE52F4484ULL, 0x28C61765CBF8AA0FULL, 0x94C0BDE42292D9D9ULL, 
            0xB9D40030D79B6E1AULL, 0xEC9F15902E91C457ULL, 0xE31FB19180275218ULL, 0x76D3D6B1E0D36CD7ULL, 
            0x6DFD5BB6B844B664ULL, 0x73D8968B5329F91AULL, 0xF6524C8465A3E816ULL, 0x76114957EDFCD612ULL, 
            0x41E3502DDB719F20ULL, 0x659E0AB8B2B86666ULL, 0x632288EE651A3E7EULL, 0xDA7671D2BD386EA0ULL, 
            0x88FEF30A4E7C55AFULL, 0x838E83DC70F1ADDEULL, 0xC5D7CD2C6FE48304ULL, 0x6BAA8C39A35C867BULL, 
            0x59176F95814EB4EAULL, 0xD22C1B3C7F917005ULL, 0x3108512650892A87ULL, 0xD531C63C380F2FCAULL
        },
        {
            0xDC519E6BC47A4C9CULL, 0x833778FDA9C7021CULL, 0x3D181CCB6AE121DBULL, 0x301F59C3675F84ABULL, 
            0xEAAEB7DACE591220ULL, 0x1C6577379C304EC4ULL, 0xE95E69C47C969E57ULL, 0x37901F6B5969954AULL, 
            0x2F1C0FD93F94D6D9ULL, 0x8A514D78BE44178CULL, 0x86701D6CCE0B1305ULL, 0x87D3793DC08A6419ULL, 
            0xAAA5A0F219833F72ULL, 0x8B1091BEC798D9D2ULL, 0x589B876B7CFD8E2CULL, 0x15392C3A1BD15114ULL, 
            0xC2A283B9CC83618AULL, 0x855BC5069FA7E466ULL, 0xEAEEEB440DE4C328ULL, 0xE0BB48333019D6BFULL, 
            0x95BB5F3EDDE82788ULL, 0xDADD6EFCB3C556E9ULL, 0xA4754A40A8DC0108ULL, 0x54A58011AA92B6BDULL, 
            0xA2D3BB29D8D18179ULL, 0xB8548ECC1CD96647ULL, 0x9FFBAE46F94838C9ULL, 0xAFB2669FE823BA83ULL, 
            0x12394483093CBE80ULL, 0xA26933EFDAA31982ULL, 0x91DCCAC26039EC5AULL, 0x412D81294F0EC5F7ULL
        },
        {
            0xCF01A93A341CDEB9ULL, 0x052976C45D196914ULL, 0xD5D41A6D374BEA6AULL, 0x8F478F0FE906A66CULL, 
            0x512811D301A61F6BULL, 0xE27F88B64CA00205ULL, 0x9B2EB98C4582D375ULL, 0xEDF450A03CBB3C99ULL, 
            0x5D0B8FBA1977A0B9ULL, 0x199E7266BC09106CULL, 0xDD53EEFA5E55AC08ULL, 0x6147696150ED0C19ULL, 
            0xB47504BA17DC3E40ULL, 0x36D15F2255560172ULL, 0x55D24AF0D90644DDULL, 0x322412BE4B608931ULL, 
            0x8B591200458B524FULL, 0xE5B800C5F2491AA9ULL, 0x2F688C010BB2D46EULL, 0xEF0FA9B5ACA7D059ULL, 
            0x305F4AB20646C72BULL, 0xBA93048D96B527B3ULL, 0x897D9AE8B5C7FFB6ULL, 0x0A0131F0BAC3A005ULL, 
            0x92E35EB6F4D9E38EULL, 0x676FF57F53EB25CCULL, 0xD9A3D4ED5BB7DB12ULL, 0x9DB4B200C2B511B0ULL, 
            0xCEA84CD858E90894ULL, 0x89F8342E577ECF0BULL, 0x1F55BB5FB7551262ULL, 0x91443AC099C19481ULL
        },
        {
            0x498EDD18E905A70FULL, 0x53CECAB30078503FULL, 0x086A97EC3874B15BULL, 0x11B38986B52F7C1AULL, 
            0x7D3D098888C193D4ULL, 0xE0CFA2ED5C101ADDULL, 0xCA4F15FCC2F00818ULL, 0xB42D4405B8D9A4F8ULL, 
            0x0072B328C4B02291ULL, 0xCDE6378B9672CB63ULL, 0x3D2B406AC46F5692ULL, 0xFB7319A8AD26B2E6ULL, 
            0x9CCD5F6EAE9C5DA7ULL, 0x70102629DEB747B9ULL, 0x6F48B792C19DAE5BULL, 0x241F1FE9946EA2C2ULL, 
            0x58BC8FE3A934ED7FULL, 0x3F688FDB31B68BCAULL, 0xD8B52691F9D98204ULL, 0xFDC9C54D794DAAEAULL, 
            0x5F2FD1FC2C5A62A5ULL, 0x13EFBB81E02859E1ULL, 0x7411ED2B30C0B43FULL, 0x6876E49F04F841EDULL, 
            0xEA3F0F013975FA95ULL, 0xA17935D71C94D7C9ULL, 0x5AB48931F8E9E119ULL, 0x91F9E58A3840F40AULL, 
            0x8DD811D38FFBF960ULL, 0x52BBF78BE76562EDULL, 0xB8E78CF91057C1BBULL, 0x87108FC8C4D99F57ULL
        },
        {
            0xE70A6AE0A487DD04ULL, 0xB590FFEC680CCADBULL, 0x7B80C4E9A3758827ULL, 0x8DBCF6FC0A7F74ECULL, 
            0xAE25F120C762C463ULL, 0xD4733A32EBA7C6B9ULL, 0x67C54FA0D9D6387AULL, 0x496F1EC90A6E2B1AULL, 
            0xB8FBF744CB4EB372ULL, 0x35B532FF4243C832ULL, 0x44B82E6429F1E66CULL, 0x6F763F3394F3FF1EULL, 
            0xC8BA335BDFE9CCEEULL, 0xCE5CEB0AC1FB54E9ULL, 0x287DCAE7BD1069FCULL, 0xC5D468567159BB45ULL, 
            0x18435C944A006304ULL, 0x922E1813650B1261ULL, 0x7D121CC8939B3000ULL, 0x97A824AD047544D9ULL, 
            0x288F2BB77447517EULL, 0x4E1CC8A2FC3F537DULL, 0x77A6B05FA34C705CULL, 0x2AC1C8CB64D87B62ULL, 
            0xD48D2122FB8D3727ULL, 0x4E8E04AEFDF4B8EBULL, 0xEEA8D87281FCD9B3ULL, 0xE077B19D97230B9DULL, 
            0x72ABD3C88DFCE505ULL, 0xBCF3968C96A44834ULL, 0xDC313D5D3A48309BULL, 0x33A7AC75186E76D9ULL
        },
        {
            0x9B256A2C9ADE8002ULL, 0xAFB0B6842F6713D2ULL, 0x00E2CA07ABDAA083ULL, 0xF51F33075E4176C2ULL, 
            0x9B48A7021F52B51BULL, 0xDFFE60E773CD09FBULL, 0xC4FF66748D745F09ULL, 0xB10BE473BC69FA51ULL, 
            0x27052645EDB99C9FULL, 0xEB05417C15830A64ULL, 0x5BA68C921783E8DDULL, 0xE9E4BE6C04AB1A44ULL, 
            0x816EB8066172FB03ULL, 0x04E07EF73B70B849ULL, 0x5F1644C55C966EEDULL, 0x6E8C6A59E01C2204ULL, 
            0xC89A34AFB9C0D1C4ULL, 0x5A081DF812554229ULL, 0x84D101C80D1A3F33ULL, 0xE99B22EBE136AC0EULL, 
            0xF040733D06B7AB1EULL, 0x1E4D242F8AE10D02ULL, 0xD7A993C709867678ULL, 0x64F1891F197F1801ULL, 
            0xB3C92B49E22A6D69ULL, 0xA774BDCFBB82388BULL, 0x146033ABED4A8067ULL, 0x72B422F17EC66F85ULL, 
            0xE046BFB5F78FFBD6ULL, 0x925FA6EECBD21891ULL, 0xAFD5F083462ADE68ULL, 0xF5EA87A31CC5D028ULL
        }
    },
    {
        {
            0x12F0742661E59A33ULL, 0x82AC22F690775831ULL, 0x80DA64116BA14845ULL, 0x63299BE138CF78C0ULL, 
            0x69576670EF1C0084ULL, 0xF2C50AB4A5CE947FULL, 0x93A9B9E013FD6641ULL, 0x4ADC4BDA5BA727B4ULL, 
            0x8DF38B31CB40E47BULL, 0x89A9E22A778D3E76ULL, 0x96A864305499CEC4ULL, 0x062AC05AE78DB4BFULL, 
            0x60FD1CDDBF629120ULL, 0xF7FF8439E466414CULL, 0xD7B1DCAFE816A753ULL, 0xAFC7DC406A861BD5ULL, 
            0x69E9845158CDBBDEULL, 0xABE08624D5C9555FULL, 0x0D638B80AAEDD47EULL, 0x98B31567CBA821A1ULL, 
            0x38D937233DDD08CEULL, 0x965F143FA71C4C2FULL, 0x138145DB964B0BE9ULL, 0x2EF11D66E0CBB176ULL, 
            0x6987091DA23FD8A5ULL, 0xE9F070A17F1D3535ULL, 0xFF9B0DE661ECABA0ULL, 0xD1C441B88541001BULL, 
            0xC8AC67B573EA3109ULL, 0xE18802390F17ED12ULL, 0x5305FFBB79E0A16BULL, 0xC99E4A72A72E96ACULL
        },
        {
            0xDB4CED7A8A41EF53ULL, 0x52481AEF4B60EB5EULL, 0xB2AD750489D5E282ULL, 0x74F65EC3BCA2A2B8ULL, 
            0x2AFC894C9A102579ULL, 0xD9335D05EB09C987ULL, 0x7A42B95670118EC6ULL, 0xF7A3032290756D75ULL, 
            0x1A78D21F04C2B660ULL, 0x1339E1574DF7DBD4ULL, 0xCB66176811FCC586ULL, 0x3CCC0DA5295CC3FFULL, 
            0x5B791E8572BB88F2ULL, 0x1226C8DAED2C5A0AULL, 0xA7B312D1789628F8ULL, 0x35356D819D5EFB45ULL, 
            0x4A9473D5D4308228ULL, 0x23E4FDF5B049DA92ULL, 0x8576561B12DCC52FULL, 0x5E3693229795A860ULL, 
            0x20461EB4B2EDAEE7ULL, 0x7D3E81421E92DD9CULL, 0x0A9317C7CF37787AULL, 0xC0835170EFAB4DD9ULL, 
            0xCA5A5C5378ED4A0DULL, 0x0C79B380973D6DE1ULL, 0x5FDF50504E2C4F5EULL, 0xA64FFE096FBC9C79ULL, 
            0x1D8BF81F7C43048EULL, 0x3145FE749EC12CC6ULL, 0xED2306A162F983C7ULL, 0x207359CCCBB13BE6ULL
        },
        {
            0xAD6252AF51DF4BDAULL, 0x1658803AD9B865F4ULL, 0x01CEEC3BA4B68EB8ULL, 0x73CC8FBE5F69D605ULL, 
            0x7F68479E0DFE9739ULL, 0x348659F544AB2E3EULL, 0x86331FAEF8090911ULL, 0x9340A8A461360B17ULL, 
            0xB7CCDA8F832C76EFULL, 0x7123678CFF520B24ULL, 0x90CA450B8FF645B6ULL, 0x1DCD13E648EB1F3CULL, 
            0xD91A5B4553995B8CULL, 0xE12D106F531ADF95ULL, 0xCDFB78376B36497EULL, 0x2F72C94715D075A6ULL, 
            0xBB6B131578D23F9CULL, 0xA37239A150EC3B66ULL, 0xF792B17524E0046BULL, 0xED59C7F1609752E8ULL, 
            0xA1D93E63F7E0254CULL, 0x0CFF1E8AF744CEBBULL, 0x5D0616B8C4BE9D90ULL, 0x788C7A916BEF978EULL, 
            0x9E570E7F63A89252ULL, 0xD063E20DEFF7E2EAULL, 0x2E7AF19F1B149A33ULL, 0x64E65928974666B8ULL, 
            0x8DF271224B8E311BULL, 0xC2A72499B0D55875ULL, 0x27B3B57ED46C5F2BULL, 0x744E9946E92DB7D6ULL
        },
        {
            0x06EFA341ECE3D465ULL, 0xB91D3AA19226DCC0ULL, 0x235AF447E17D708CULL, 0x477E9FB7F619B715ULL, 
            0x09C3266886142AF0ULL, 0x9D889F4B5ACD4C20ULL, 0x8FD7B6F08785AECFULL, 0x5CCEC875761B5FDDULL, 
            0x602720C67A1D95C8ULL, 0xD50DD49636F1DC9BULL, 0x7EA179C0E3305AA4ULL, 0x005EDD9A3394A0C7ULL, 
            0x91E9D3F02F18439FULL, 0xA3FC2A9C559BBB64ULL, 0x5976CB7D99B1926DULL, 0x1B4090737562198AULL, 
            0x4C60021F25C59D7BULL, 0x9FF4423A36F4D6E6ULL, 0xD5979BA9D03FC68CULL, 0x0099C0D0DDD89D19ULL, 
            0x3EEE45DD296ABBCDULL, 0x2D2B20101E3B892CULL, 0x9D25312596FED0FCULL, 0x8CAB2617F1E7EF0BULL, 
            0xAAAD199EF36195C1ULL, 0x812F65A463F772EDULL, 0x5A75A4F96A8EA361ULL, 0xAF6EB46661ADFEC6ULL, 
            0x987BADD57D919AB2ULL, 0x516C62FD4D660C0FULL, 0x7AF09EB138AFD5AEULL, 0x641D2D79442DB74AULL
        },
        {
            0x6DB7AB8D3E8ED98EULL, 0x05B13BE35EA8B2CFULL, 0xDA3E3B7B5415E309ULL, 0x16110E62247D0F27ULL, 
            0x6AB5107D7D54380CULL, 0x4A6280346CC6FF80ULL, 0x5017D9631CCE972AULL, 0xD094C8685B575C8BULL, 
            0x4CD5D7D7709A638BULL, 0x9FA29B93C48EA177ULL, 0x3FF0DF3B9CAB23AFULL, 0xC30DC9C5CE69B0D9ULL, 
            0x51D3F5AB0BEF0B17ULL, 0x4B422BA755DC0495ULL, 0x6B9DD8C71472F5B9ULL, 0x1F972E65352B31C1ULL, 
            0xA10956BEA17DC335ULL, 0xC5DE8B5771DB31DCULL, 0x480CE329E3DF961DULL, 0xF906AB9C888C0178ULL, 
            0x84FF41EEA2E9267BULL, 0x3585007DC629C965ULL, 0x3FD02B0149C34F10ULL, 0xB5B39489F8CA489EULL, 
            0x8FC799C0ADC0543BULL, 0x945620C1B7B8E1F8ULL, 0x36556EE67C26A530ULL, 0x571E498D2E5655B2ULL, 
            0xC9264FC8506729D0ULL, 0xC1E6D7654DC41D9EULL, 0x40B8DA3EBA24DBC8ULL, 0x18D12ADCC880B809ULL
        },
        {
            0xD0DE22089896C5A2ULL, 0xCC5C812CFDB3DACDULL, 0x4C85F02D6C59FFE0ULL, 0xC8F548E318C64ECDULL, 
            0x417D830CEBA037D9ULL, 0x172382CEE77E0EFEULL, 0x641FE658898F6BD8ULL, 0x288C545E1C1837EBULL, 
            0xE898DA8BB9D22420ULL, 0xA7ACF4DBBDCDF821ULL, 0xCBBAC03DC4CDA443ULL, 0x79A3731B8F981C2DULL, 
            0xC1033C90E4A38BBAULL, 0xA0AFE41E28EA05D7ULL, 0xAED88115517A529BULL, 0x58D9BDE6ADCE716DULL, 
            0xF2C09DDE512F7271ULL, 0xEA0DAB871A26C219ULL, 0xB467FE996FF05785ULL, 0x46CC6560D4578D35ULL, 
            0x282075C3AAABA935ULL, 0xAAB01EDDDF78221EULL, 0xE75A71D2E0233AE6ULL, 0xBE55DA082E7312CDULL, 
            0x34EF52CEBE08B7C6ULL, 0x241365326CB835BDULL, 0x9D0CF063608DBC6AULL, 0x5E8E1D55F51A20B4ULL, 
            0xD99924D61C62A897ULL, 0x8109F4634804FB2FULL, 0xC3043AEB80ED1776ULL, 0xB01A80E9FAD1A2FDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseGConstants = {
    0xA5966E1BCDD8B7ADULL,
    0x9B2BA94E3791C65CULL,
    0x9D405FA38DFC41F4ULL,
    0xA5966E1BCDD8B7ADULL,
    0x9B2BA94E3791C65CULL,
    0x9D405FA38DFC41F4ULL,
    0xCC609F0FE775BEE8ULL,
    0xF60C6AE23AA02733ULL,
    0xE1,
    0x38,
    0x82,
    0x17,
    0x7B,
    0x70,
    0x94,
    0xBC
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseHSalts = {
    {
        {
            0xB17F2F46492FEE18ULL, 0xCBF15D3BB9A9DE76ULL, 0x0ADADABEA657718BULL, 0x052D4F1F3D8FF624ULL, 
            0x8AF3E951D00B23AFULL, 0x82E7C3971638E74CULL, 0x666BFAF6C4CABC7BULL, 0x9EF0AA890CF3391CULL, 
            0xF8A8D01BB6B0B171ULL, 0xA0C73C2A1E0511D5ULL, 0x95396840B597145EULL, 0xD8F4587B5F7C19A0ULL, 
            0x2C4BC552DC62C226ULL, 0xF09B73B021EA9306ULL, 0x758D101A75650E50ULL, 0x70D85BF2144A80B8ULL, 
            0x951C954903490AC9ULL, 0x5D4BB43D5D5B5CA0ULL, 0x0662F2BB1657B14AULL, 0xD780F8B181CAAFE5ULL, 
            0x300EAE536C3E3C3EULL, 0xC090414A5C97BC46ULL, 0xFA77AF4F764A2E9CULL, 0x66F01BD2F2CF9573ULL, 
            0x1B9585E49DFEFF01ULL, 0x5DC458CBC184D2DDULL, 0x5AE532E52A2B035FULL, 0x335A876AEDBDCD20ULL, 
            0x88A4570AF9E08826ULL, 0x45D00EAA146DD0A2ULL, 0xE8CDA197D22BB946ULL, 0xDF6D93FD7DF905FCULL
        },
        {
            0x5CBC19FED0BC54A5ULL, 0x7B24D1704FD7500BULL, 0xC971CD47B085C36BULL, 0x01269B7B6F797776ULL, 
            0x43D3914E3A234DBEULL, 0x407801CCB3FE8C87ULL, 0xAB08227A2702D532ULL, 0xEAA51852F8ACF203ULL, 
            0xB9B6EA1DCAC9F520ULL, 0x307434264C9F627FULL, 0xD73D28DA26D1DF29ULL, 0xA50E928863BC502FULL, 
            0x4EFC1B508618246AULL, 0x253FC515A48FF664ULL, 0x148CA364A43F51CDULL, 0xFFD30F054A36F50DULL, 
            0x6BC1B34F109CEB5EULL, 0x231B3238E9A3190EULL, 0x771AFE4C2E0FEEE3ULL, 0xBF60DC38B597A6B7ULL, 
            0x3389146656061642ULL, 0x6CC08CD545E9F646ULL, 0x952D548D2A6D2F72ULL, 0xF6CDDD8AA25E317EULL, 
            0x16C172E9E3C74FA3ULL, 0xF733EEA4DDDEDB38ULL, 0xAED5A5044838D3EDULL, 0xDECCB8471A72CCE5ULL, 
            0x1E60833EDA2CDD20ULL, 0x2BC1DA767EF2AF4EULL, 0x1C2BFE98DD4669D9ULL, 0x8DB7B3E606E51ADEULL
        },
        {
            0x1809C2466C22787CULL, 0xBEAF0081ED7740D2ULL, 0xCC0619DC4050E4E2ULL, 0x6A4B86BFD18AD1F4ULL, 
            0x262AA37B8ADC8332ULL, 0x63BF501F38CF3BCEULL, 0xFD7962160144FB0DULL, 0xC7C7CA8F483F84C6ULL, 
            0x30EC27761C17A569ULL, 0x6DACAA7CA4DEB34AULL, 0x7E9A83FEFB06C381ULL, 0x19E1EE4557F42F43ULL, 
            0xD5061997CB174EFBULL, 0x63F77CD1D5611C6BULL, 0xFC3757150F9CAB3BULL, 0x0BD361122C7F66B6ULL, 
            0x004FB53070C4BD21ULL, 0x3442C70B76D12679ULL, 0xFEF6B138F16C4835ULL, 0xA838FDE4D2C6C3D3ULL, 
            0x5BA537AE26DA93A3ULL, 0x8D44461C5BC36D29ULL, 0xA4DE0A64C3B8FF6EULL, 0x05CFA0DAE2449BE0ULL, 
            0x97097D7325CD5ABEULL, 0xBBF544D0D4EB4EEBULL, 0xF3F6A68B9F739EDAULL, 0xFC458EB90FD09022ULL, 
            0x9CEFCEB1F985861FULL, 0x420EC4554CFFCC7BULL, 0x595C94CF44A5D4E3ULL, 0x92D32BD7237E79B0ULL
        },
        {
            0xC7B2C33B4622E8C3ULL, 0x57E5E3D5BAEDEF8EULL, 0x5DE353FBF6F8A05CULL, 0xDBC8FD317DFA1776ULL, 
            0x9B9A5FD68D30DA7AULL, 0x890397E6AC133B35ULL, 0x7BEB9EB468105360ULL, 0xDF12D6914EB5B9B7ULL, 
            0xC5BCB30945C9DD89ULL, 0x0A6E7EF43416D9A5ULL, 0x17FB7179E2A150D7ULL, 0xFA170C66D272F65BULL, 
            0x7A11B5FFC848DA8BULL, 0xB2B1420DEA0B0473ULL, 0xDC935079733AF7FDULL, 0xFA0AE58120650EA9ULL, 
            0x7EAF869A830068D4ULL, 0xAF14682CF23089B3ULL, 0x2EB13D570EB8B7C9ULL, 0x7AE6DCF0312690A9ULL, 
            0xE2C401AEB0E38057ULL, 0x3D5DD1829E247E93ULL, 0x2E34AF4DF7D77F8FULL, 0xF32D76B50219537BULL, 
            0xAA0B27277B04397AULL, 0x36C1C9E61FDFCD9FULL, 0xE1C5FD1CE1190740ULL, 0x1CE355CC41E3A867ULL, 
            0x33CAA0742332405CULL, 0x20D35343BC95B9E9ULL, 0x63DAD16E3C8F8876ULL, 0xCF61B1E136DF3F6BULL
        },
        {
            0x32DE2724DF182B27ULL, 0xFF664595BFC1BCCEULL, 0xC2CCD617598D7046ULL, 0x1864051E539232B8ULL, 
            0x8E939F2AA387B285ULL, 0x22D3C93DBB8F0F7BULL, 0x39F70023F9CCD40BULL, 0x5720798D211C8BBDULL, 
            0x215E586F6A02B9B8ULL, 0x42AF32FA0B7487BAULL, 0x6AC7986D05AE1188ULL, 0x65EF3A5EF1F04DF8ULL, 
            0xAC66E37DF9C46807ULL, 0x83AF7E185B8E8D77ULL, 0xB81BD7E9F201F5E1ULL, 0x37FBFAE14CF8410BULL, 
            0x8877174286F9259FULL, 0x69202954BF352C91ULL, 0x7EB364AAF81C6303ULL, 0x298F6F8F5DE0DC55ULL, 
            0xE151C67EDE75AAEAULL, 0xB7FF3BD234243295ULL, 0xEA84899676369818ULL, 0xAE8BF0590CC859FBULL, 
            0x3B2D7C980DA6E3A6ULL, 0x9B805B0D5B18CA8CULL, 0x766ED120E16F7F21ULL, 0x9FD45B51E5AC4A6CULL, 
            0xE939A51F62EDF31FULL, 0x00D4691AB2672846ULL, 0x48D4296BA682D5FCULL, 0xC4DD12300BC243C9ULL
        },
        {
            0x6C1A7F97087602F6ULL, 0xCD2444651967F581ULL, 0x06D2F508643960C2ULL, 0xE37F04F49D3EFA76ULL, 
            0x9733BC7D261BCFC7ULL, 0xFEFF048D73BCC4FCULL, 0x862066A76F1E1645ULL, 0xF61D2AD931479E8DULL, 
            0x00B7BC9A2FC10FE4ULL, 0x0C356E261E7C084BULL, 0x658850F5F4839691ULL, 0x0AF030ECB0268ACDULL, 
            0xE55781E03980BF41ULL, 0x4665B4A49E9AB01FULL, 0xF992BC62B00F4DC3ULL, 0x7D3162BDB565409EULL, 
            0x701864F888A3BFB2ULL, 0x95DF491385380D82ULL, 0x6E51F6A7A8DB1C33ULL, 0x8E669108957F3787ULL, 
            0x0993760DB4EC183CULL, 0x66938E762C34A8A0ULL, 0x6A8AEFB2EFFFE913ULL, 0xC29A1BB45D0E07F7ULL, 
            0x72D8FE1CC73ECE9BULL, 0x1A4006C441DA3A2DULL, 0xD1B1E9AEBC0A5ADBULL, 0xECB8DD0903401ACCULL, 
            0xEADB0D9DE0FAFFD4ULL, 0x0592901043A8406BULL, 0x073EF4D9251E7469ULL, 0x48435B8E96ADB96BULL
        }
    },
    {
        {
            0x14A42AB80445968AULL, 0xAFBB9CEEC852B1A2ULL, 0x34F878EA18D134FCULL, 0x582781ABD94737FEULL, 
            0xAF7F3D3F5C50D5FAULL, 0xC6BEF38BF02D98EFULL, 0xD323859A515F555BULL, 0x6F41430B77BB9CC2ULL, 
            0x0D88D8370D2ED2DAULL, 0x05A8A6ED966D97F1ULL, 0xBE9E393AB6BE4D19ULL, 0x5614F0D107B49145ULL, 
            0x66DFC01D568125EBULL, 0x6CDE6ED9F60AC06EULL, 0x3C6B8A8A93610D34ULL, 0x8C21E29139E33913ULL, 
            0x144F2F66DBBBCA2EULL, 0x85FAD9235FD68D22ULL, 0xC4864DDDC5EE45C6ULL, 0x740C9EA20819D41EULL, 
            0x4C1C44281BB66A0AULL, 0x5C33FA5DC3156EDFULL, 0xF392D7B1CB38AD77ULL, 0xF55B616172775326ULL, 
            0x960D4D5F8D1C1D63ULL, 0xFE1B60FCEE75389BULL, 0x07232A2B4EE8360EULL, 0xA52F95D5E921F0AFULL, 
            0x218BD38D95E89AEEULL, 0x92B5AA4DF1899D51ULL, 0x664A992D750516AAULL, 0xAEB1EFAB48AE7A6BULL
        },
        {
            0x1AA2823822CDD2E5ULL, 0x31F31CAA4989DA74ULL, 0x6A5F94F3E5D9893FULL, 0x05AA9EFC692DE766ULL, 
            0x63951AB5463E51BAULL, 0x7DF6EB20E7F5D005ULL, 0x9E71BB852D64587BULL, 0xDA489522E25F678FULL, 
            0xC2A5D6F92CF74DDEULL, 0xFA3724C5BFB8F602ULL, 0x052091E6C3E219E1ULL, 0xCCF1E482BD26D193ULL, 
            0xF83F19667CCD5E9FULL, 0xEA8462275E062689ULL, 0x7E28AE7F88677E61ULL, 0x22BC34B4DF697489ULL, 
            0x84906FD64909F685ULL, 0x0BA34DD2F3948D8BULL, 0xDF7D00CCF73DCBA9ULL, 0xCF92C057A570B064ULL, 
            0x679C879BD0C23796ULL, 0x55E664308A5A9BF4ULL, 0xC48DD30F3C477670ULL, 0x3D1F9C0F91896EDBULL, 
            0xD0AEDD4E68C32BA1ULL, 0xD3339040A7FF6CB6ULL, 0x8D8213EFFC26AEA8ULL, 0x3F605A2EBE4A2181ULL, 
            0x1D2AFAFD0D1A2B44ULL, 0x889913BD962DC8ADULL, 0x2C3FBD62BD751AA7ULL, 0x02EF93746A88E375ULL
        },
        {
            0x577E8CE6D026AB02ULL, 0x0F2ED2AF22811C49ULL, 0x358F100F6252A03CULL, 0x61550922EBA61138ULL, 
            0x98CDCFD99092F238ULL, 0x8615B4E374C25494ULL, 0x94761C88896856AEULL, 0xC3C3468E292FF589ULL, 
            0x6DB324CF48BAD085ULL, 0x78A983C352AFC869ULL, 0x68CFD4BC995008DDULL, 0x2E863D15CB0AAD23ULL, 
            0x3B9560EC44AB7801ULL, 0x68FBB87654EA64E6ULL, 0x2E2C60E50499CF95ULL, 0xDAD104AFF25ADD8FULL, 
            0x7059BFF873EAC699ULL, 0x36ECA5B0C9B709EBULL, 0xCFC494650E9085E6ULL, 0x1C2C8B4881DC4F05ULL, 
            0x841E5E2851E3FE26ULL, 0x9A145F07B5837FD5ULL, 0xC190357B3CAEC43CULL, 0x2A7A8C4B02E06277ULL, 
            0xF4672FA8994B77CDULL, 0xF9FE9C110846BF87ULL, 0x332EB9BA71B44F22ULL, 0x86D8059EF2F3550FULL, 
            0x611AB2E215CEE744ULL, 0x2F9B24561B2D973FULL, 0x248D170F3C8C8B88ULL, 0xCD122723E86B0790ULL
        },
        {
            0x043D615E1D244BF2ULL, 0xDDF4F7858C8559E5ULL, 0x46F4F78CB65B3122ULL, 0x34CA020DEC8C1EB3ULL, 
            0x847141C60612EE2EULL, 0x3D03564300233D4BULL, 0x22306FE984DA7AECULL, 0xF50C78B6A0AA665CULL, 
            0xA8ED0FDB0CAE8581ULL, 0x8D33F993F34CB109ULL, 0x38F7991A74E97926ULL, 0x6EE2A78446A2140CULL, 
            0x89EE371557AE87B9ULL, 0x06B0F050D28A0F64ULL, 0x61403900D57BF41FULL, 0xF38D47F5BBB1F07CULL, 
            0x8012E6CB256C5154ULL, 0xA00A4DA29A37166BULL, 0xB53A2817040F6EB1ULL, 0x18FD301B4FFB0CA9ULL, 
            0xC8D7BE82025CB176ULL, 0x4AD10AFDB85CD394ULL, 0x28D01FF25A41FE71ULL, 0x063199ECE745EDFFULL, 
            0xEB8AAB02758184F6ULL, 0x454595FD2F73796FULL, 0x0FB3844565B6F1DEULL, 0x96A5D77E9C779429ULL, 
            0x0F732425D848EAAEULL, 0x053E86AAC34F8CD7ULL, 0x32A8B50D63D2662DULL, 0xFAF0731028A1060BULL
        },
        {
            0x9530D8A489509295ULL, 0x793129C73C7A492BULL, 0xCC129A6DFF585F8EULL, 0xBF24C49B59709A2BULL, 
            0x1592CBD10AFC7C3AULL, 0x3D746C526E4C442CULL, 0x89236BA069DBD802ULL, 0x20ECD505E5C25041ULL, 
            0xEB953A10C72891D6ULL, 0x80D9300E990FA98EULL, 0x66375F99795B916DULL, 0x17A689FA2025623BULL, 
            0x43DFFF9FA6F61864ULL, 0x787BDE95F7B8D331ULL, 0xEA378FADE506E615ULL, 0xBE9744CE15C89E45ULL, 
            0x08D7343E565EF2BBULL, 0x65A1B23D32B18E1CULL, 0x4CE4471C163CA424ULL, 0x6E03DC8847A05866ULL, 
            0x6C4740A6AEE34738ULL, 0x06963962D5186A9BULL, 0x74C84FE1FCD86080ULL, 0x696743CEF194A390ULL, 
            0x9E59D8CE7C6B034BULL, 0xE3B296BFB919C0F3ULL, 0x549B8EE1E1F38D2CULL, 0xD9365EF061F16192ULL, 
            0x23F55837A73BA5ABULL, 0x79F8287544250AE4ULL, 0x0322757A72845494ULL, 0xFE746F4B6EDC0418ULL
        },
        {
            0x2A0AE31B37870BDFULL, 0xC2F5F3BBBD90DFFBULL, 0x02366F3E5326C0D1ULL, 0x90F9AA9E48928098ULL, 
            0x8B88AC8F98CC110AULL, 0xE9D9F3AC931120EFULL, 0x304C4F93B07AEDC9ULL, 0xE9BF2CD9725124C5ULL, 
            0xE79132CF0950D899ULL, 0x8674A2BCCCD595D1ULL, 0x516D182568F0A690ULL, 0xC5E7553F4A760A31ULL, 
            0xF89F9E7CEC294846ULL, 0xA6C95F7A0CD4E011ULL, 0xF7A6970D188AAF1EULL, 0xF936795579D35875ULL, 
            0x9D3AC71BEE07ED61ULL, 0x134C3F5AAF2B860CULL, 0x7A73D507CECA9DD0ULL, 0x2D2D139CDF04ADCBULL, 
            0xEF88F3B8A544DFD6ULL, 0x657E607958678177ULL, 0x196209DE3B21275DULL, 0xD944231EF6A8B860ULL, 
            0x0F7C135F79CDE0F8ULL, 0x3AD81FB93C39D27FULL, 0x7763C5721E8303E7ULL, 0x1C4330C96DA69AE8ULL, 
            0x59BF08AEFEDB12ADULL, 0xC01242303A39B822ULL, 0xDBD2B1D42762A7BDULL, 0x565E81C4120A54A6ULL
        }
    },
    {
        {
            0x5BAFA942F95CAA5DULL, 0x4B5E30A55FE730CFULL, 0x13CC901F54F4A28CULL, 0x1A844F99B345174BULL, 
            0x25F6D64A70650308ULL, 0xD2DEB667F9B81D1BULL, 0x97591AA49CE67EA7ULL, 0x87AC28EE5BBF19B0ULL, 
            0x43D47BE26B9B29B1ULL, 0x9AFA82EB9190D39DULL, 0xEFA535BF52E96030ULL, 0x9185F509AD6CFEC2ULL, 
            0x981618D3C88E21D3ULL, 0xB79E7FD45C43C447ULL, 0x01E340FA668F5BE9ULL, 0x2E4A5705A74BC143ULL, 
            0xCFC594E3F01D3FD3ULL, 0x78F6EC0663375610ULL, 0x7224A1201D2AE909ULL, 0xB93FA6C78A759194ULL, 
            0xE380A185F090310EULL, 0x847C4E4B2286854FULL, 0x79B8C5096FB7BF08ULL, 0xB0FDA3B0CAD2B273ULL, 
            0x9802FBEC7B3771F4ULL, 0x1A34EA1E8289FE98ULL, 0x9CEC09431AAB8181ULL, 0xB19C69E5C9038066ULL, 
            0xE891666CB243C32FULL, 0x474B6E2590F4503CULL, 0x685B75AD035E0EDCULL, 0x88FB4AD253F64D3DULL
        },
        {
            0x9978A53E962BF994ULL, 0xF1F05DCA74EE0A52ULL, 0xEF4EC15B5B6E9862ULL, 0x17F36699E178CCF2ULL, 
            0x6E09482582A145F5ULL, 0x65568AB0ABAD0F9CULL, 0x7243389B90F90E52ULL, 0x2CB1300274ED3087ULL, 
            0xB4E934DF6B0A4E6BULL, 0xB626669947ECAA3DULL, 0x36CA1B7F7F0928F1ULL, 0x387C7D0823C84662ULL, 
            0xA98856D4F97B16C5ULL, 0x5A0DEA5BD7377190ULL, 0x426DE048CB3FA6A3ULL, 0x531B07DB984CE8ACULL, 
            0xEABAA75FBB39561CULL, 0xC6F2C5C2FADD3E8EULL, 0x8652C1B9A3E08D1CULL, 0x1D1FD99D1C59434FULL, 
            0xFBD78D2BAF53B7F0ULL, 0xDB09EFB17FDC3F71ULL, 0xD2BF91A6ED659E3DULL, 0x7086FB3D15ACA52FULL, 
            0xC937CD414A23490CULL, 0x6A90808B2EF35D9BULL, 0xBFA6C7E81997EABAULL, 0x5AA976ED1B000048ULL, 
            0x33DAFC66D5606206ULL, 0xF4F847152511C246ULL, 0xAFB1FFB5564F6D68ULL, 0x5E4057E2E509EB48ULL
        },
        {
            0x5CB6DE9A6EAF3138ULL, 0x5E6DA5349643133DULL, 0x76EF9F5111B0FF3BULL, 0x44D2E4B0FE915E1BULL, 
            0x98E9BC6CB623D81CULL, 0xC86487CFE36D065EULL, 0xCEA97B9F24D0FBF4ULL, 0x08581926A88AD4A4ULL, 
            0xDF74622E4E4908DDULL, 0x868E582BBC725426ULL, 0x753569854D912DF4ULL, 0x6FA48EB220A5741DULL, 
            0x86075735C2B6B336ULL, 0x826CE6619316D885ULL, 0xA447C1A554728FF5ULL, 0x957942C163B278A8ULL, 
            0xE845D8BDE1F42B26ULL, 0x7540363725AE17A7ULL, 0x354A0B90DE448E3AULL, 0xEAD3939A0A295791ULL, 
            0xEA3FA3FDD11B8ED0ULL, 0x4D23CCC80C9ABF3EULL, 0xFFCBC5495C83E415ULL, 0x742089585DA6E649ULL, 
            0xED985E957F2493BFULL, 0xF7AF2F88572D37FBULL, 0xB987E7181BC0AF5EULL, 0x5153BB5FFA56FBDBULL, 
            0x3E6435B8A8064AF2ULL, 0xB980B4EC0B03C64CULL, 0xC8ACFF80D9EC28FFULL, 0x680C2656CF47AFD6ULL
        },
        {
            0xD4DF1C752289C735ULL, 0xB57BF0ADAAF0B993ULL, 0x5D2DC4F22898F19BULL, 0xF4E24FF478124201ULL, 
            0x9048C23D3608E05CULL, 0xA88AEF201F0E52B9ULL, 0xB56BE21E93AEA5CFULL, 0xF5CC7CEC46716004ULL, 
            0xD686F5F00B932DABULL, 0xEB1BBD4C96F4073FULL, 0x6D099C9A36BF3C23ULL, 0x86C5B80D6B6F61F2ULL, 
            0x8B1108C3F7091E02ULL, 0xF5485D3A6BEB7086ULL, 0x6D3DC9104CCB07F3ULL, 0xB90B18BB0DF38A13ULL, 
            0x469396818106845FULL, 0x5BBD17EB7D739278ULL, 0x8C7FCBC1C0654D32ULL, 0xAA2395440C20EE8EULL, 
            0x90050915ED1D2C45ULL, 0xF081FE1DC8AD8845ULL, 0x95E9D60306B8867CULL, 0x04BC92DC9F0E92EBULL, 
            0x8A331D0238864F49ULL, 0x6EC12004AFD2786FULL, 0xA3175DEAB1C61A2CULL, 0x854D205CCE60C6ECULL, 
            0x903AB503D811EE16ULL, 0x65AA33FEDCB5DCF1ULL, 0x631B5EACC686AC98ULL, 0x48B50BD7D9625A63ULL
        },
        {
            0xBE2C140BAFF0A754ULL, 0x8C7C4C6368794803ULL, 0xAD60DA5B18F3455AULL, 0xB5C364C56AC41C55ULL, 
            0x9377F99ED99310FCULL, 0xBFFF421986587ED7ULL, 0x78D667D0DE4876E1ULL, 0x0D5C5F9976C2EEA9ULL, 
            0x422415BF785ACFC0ULL, 0x054645055009424AULL, 0x76A42C841A53B4C1ULL, 0xDCC90E9223368971ULL, 
            0xF59DA4947FFFE19CULL, 0x80D602B51CB624CBULL, 0xCC28E5056D79C9E5ULL, 0xBB3CEB47BFC4EA0CULL, 
            0xA52301DD4F9B71C5ULL, 0x6A2A0EE23141C418ULL, 0x14FF5E96542EAB3AULL, 0xC6D1E72B06D2371DULL, 
            0x10E65E5F05DBC1B4ULL, 0xC1D7E66541D83C7DULL, 0x73C51ADEF257551EULL, 0x2544124777B14EA6ULL, 
            0x64A28D3E470A0C67ULL, 0x560324DBCF187EEAULL, 0x69FFAF4DB52C962AULL, 0x55A475DD4B050F25ULL, 
            0xB36B64837BF3D56AULL, 0x774CD84EA80601CDULL, 0xA2D611D013293811ULL, 0x86C7BBDECEB4510AULL
        },
        {
            0xF86BA1A427143B7CULL, 0x83F4D9EDD38339DBULL, 0x0788216FA498404BULL, 0xBB9A510447253204ULL, 
            0xFE644B96012CD662ULL, 0xF892280415BE1687ULL, 0xBB47F71B3F24444DULL, 0x32FD4883B1EDE7B1ULL, 
            0x029E82483C952474ULL, 0xE2D63CCA60C56DC6ULL, 0xB80263B09CD0FF7FULL, 0x31BE536A932D3105ULL, 
            0x08B0E415A9E1831DULL, 0x18474868EB2B8495ULL, 0xD5860C58832AF42CULL, 0x5771AE3AF2119B30ULL, 
            0xB20CBB6461579545ULL, 0x801B2E6C9E3241F8ULL, 0x3AEE0E467CA36CB8ULL, 0xA7B9B1868EC2DAB1ULL, 
            0xD3ED386D90D98931ULL, 0x317979F6F23F9FC9ULL, 0xEB1DBCAF3F76989FULL, 0xEE31760347F03FFEULL, 
            0x46656A933D7CD839ULL, 0x75C06065F56E9B4CULL, 0x82FE7B25481E48D9ULL, 0x97EB9444A9314893ULL, 
            0xAC91E1190BC6A43DULL, 0xD4F0148F41D81050ULL, 0x71D9B8F2DF82963AULL, 0x479591A042D65271ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseHConstants = {
    0x1F49B32A0E168B36ULL,
    0xEF4AD963F18A965EULL,
    0x1DB8804EE3190750ULL,
    0x1F49B32A0E168B36ULL,
    0xEF4AD963F18A965EULL,
    0x1DB8804EE3190750ULL,
    0x3AE76594B8BC6802ULL,
    0x7F9B7FB149EAC267ULL,
    0x32,
    0x42,
    0x5E,
    0x17,
    0xA1,
    0x0B,
    0xB9,
    0x74
};

