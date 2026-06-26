#include "TwistExpander_Lacrosse.hpp"
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

TwistExpander_Lacrosse::TwistExpander_Lacrosse()
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

void TwistExpander_Lacrosse::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 16156950949236167376U;
        aCarry = 14519663401176571638U;
        aWandererA = 16583088773279806779U;
        aWandererB = 9401529047639097131U;
        aWandererC = 13892039210970633199U;
        aWandererD = 15485742888132803594U;
        aWandererE = 9677058941265664483U;
        aWandererF = 12898979166515664046U;
        aWandererG = 12456566503129519295U;
        aWandererH = 12144958213355968808U;
        aWandererI = 10917359389754987690U;
        aWandererJ = 17701090510768180331U;
        aWandererK = 16179269242130881235U;
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
    TwistExpander_Lacrosse_Arx aArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_BArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_CArx;
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
    TwistExpander_Lacrosse_Arx aKDF_A_DArx;
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

void TwistExpander_Lacrosse::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 13941047849145878218U;
        aCarry = 9230741203769403272U;
        aWandererA = 9876023521217594477U;
        aWandererB = 16106147895388468515U;
        aWandererC = 14226739927343358474U;
        aWandererD = 14830520185145882291U;
        aWandererE = 17244281628710601409U;
        aWandererF = 12607314994746007224U;
        aWandererG = 16935134131850539543U;
        aWandererH = 14385600617891797206U;
        aWandererI = 9329004825297188335U;
        aWandererJ = 11287692004375588689U;
        aWandererK = 12325712620180730226U;
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
    TwistExpander_Lacrosse_Arx aKDF_B_AArx;
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
    TwistExpander_Lacrosse_Arx aKDF_B_BArx;
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
    TwistExpander_Lacrosse_Arx aKDF_B_CArx;
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

void TwistExpander_Lacrosse::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneC);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_Lacrosse_Arx aSeed_AArx;
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
    TwistExpander_Lacrosse_Arx aSeed_BArx;
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
    TwistExpander_Lacrosse_Arx aSeed_CArx;
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
    TwistExpander_Lacrosse_Arx aSeed_DArx;
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
    TwistExpander_Lacrosse_Arx aSeed_EArx;
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
    TwistExpander_Lacrosse_Arx aSeed_FArx;
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
    TwistExpander_Lacrosse_Arx aSeed_GArx;
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
    TwistExpander_Lacrosse_Arx aGrow_AArx;
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
    TwistExpander_Lacrosse_Arx aGrow_BArx;
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

void TwistExpander_Lacrosse::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Lacrosse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 16370800972058345142U;
        aCarry = 11151883178754018548U;
        aWandererA = 10462425319499772378U;
        aWandererB = 11449434212730521072U;
        aWandererC = 13917751989829026686U;
        aWandererD = 14824723334961650525U;
        aWandererE = 12889360829794020996U;
        aWandererF = 18402610766084416557U;
        aWandererG = 14125093541081064119U;
        aWandererH = 15337097197662522222U;
        aWandererI = 14653813767520113967U;
        aWandererJ = 12371851914622528579U;
        aWandererK = 14706070954782983314U;
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
    TwistExpander_Lacrosse_Arx aTwist_AArx;
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
    TwistExpander_Lacrosse_Arx aTwist_BArx;
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
    TwistExpander_Lacrosse_Arx aTwist_CArx;
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
    TwistExpander_Lacrosse_Arx aTwist_DArx;
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
        TwistExpander_Lacrosse_Arx aGrow_AArx;
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
        TwistExpander_Lacrosse_Arx aGrow_BArx;
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

void TwistExpander_Lacrosse::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 3, 0 with offsets 7396U, 4515U, 4817U, 4086U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7396U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4515U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4817U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4086U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 0, 3 with offsets 7582U, 7256U, 590U, 610U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7256U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 590U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 1 with offsets 6399U, 1633U, 1577U, 4855U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6399U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1633U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1577U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4855U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 2 with offsets 6078U, 286U, 8117U, 5567U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6078U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 286U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8117U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5567U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 1779U, 1363U, 1289U, 853U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1779U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1289U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 853U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 3, 1, 2 with offsets 1817U, 1590U, 94U, 1445U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1817U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1590U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 94U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1445U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 1, 3 with offsets 606U, 652U, 498U, 160U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 606U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 652U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 0, 1 with offsets 1673U, 1033U, 1523U, 212U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1673U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1033U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1523U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 212U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1995U, 396U, 494U, 1500U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1995U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 396U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 494U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1500U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Lacrosse::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 3 with offsets 2978U, 7102U, 7289U, 6459U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2978U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7102U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7289U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6459U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 0 with offsets 6105U, 8137U, 5754U, 6819U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6105U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8137U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5754U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6819U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 2 with offsets 918U, 1717U, 2070U, 5833U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 918U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1717U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2070U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5833U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 0, 1 with offsets 4572U, 7575U, 668U, 4714U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4572U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7575U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 668U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4714U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7606U, 8025U, 6468U, 1862U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7606U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 8025U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6468U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1862U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 745U, 1455U, 1771U, 97U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1455U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1771U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 97U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 643U, 246U, 1013U, 770U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 643U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 246U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1013U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 770U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1176U, 546U, 1554U, 1856U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1176U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 546U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1554U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1856U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 626U, 802U, 1630U, 1461U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 626U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 802U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1630U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1461U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 1466U, 1523U, 896U, 842U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1523U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 896U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 842U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseASalts = {
    {
        {
            0x4E14050743F5CBD5ULL, 0x83265EC79660BAAAULL, 0x1C6DF3612ADA31CDULL, 0x6E68E391D6F2CA84ULL, 
            0x2969AF59B14DBC6AULL, 0x40A648570464A5FCULL, 0x059FD56D946A85AAULL, 0x56F6F8BFF6644EB5ULL, 
            0x503370CC8984E8EFULL, 0xE0016FEA74DC8088ULL, 0x34B4292B3804C4B3ULL, 0xCBEEA2A0BDE34051ULL, 
            0x79DFD9619A8DF663ULL, 0x75E26FD6702CBB85ULL, 0xAFC4BD64E0F97AF7ULL, 0x869D2BD9260185CBULL, 
            0xEA1E2793DFAF9678ULL, 0xFECA4C8BAF221548ULL, 0x3752B7B7A8D497D8ULL, 0xF9C29052B32836C8ULL, 
            0x95C92E12C50225EAULL, 0x344F8F5FFC35E963ULL, 0xF4B03057ED338407ULL, 0x768D2B17EE5036CFULL, 
            0x42E40A761B6790AEULL, 0x45ECC53AD48FC2B0ULL, 0xBCA6BF80D9317C75ULL, 0xA1195A73FC3E5BE7ULL, 
            0xFF101CA31877135FULL, 0x3C9E2A8F8C8697D0ULL, 0x3992C9773A4D6755ULL, 0x9A08047501149F34ULL
        },
        {
            0xEA53E14924B4C658ULL, 0x8C51C84C0CADB87CULL, 0xBDB1167E4AD3C597ULL, 0xC3E88AD60AA1B517ULL, 
            0x730366860640F91EULL, 0x81042798CF97CF28ULL, 0x2A15196F2106DB26ULL, 0x4E589DE383570858ULL, 
            0x10A0D5C4D2B55AC2ULL, 0xC3560028985C44BFULL, 0xFA13713136A74C39ULL, 0x637714151A0832FFULL, 
            0x567D9560DA98BF50ULL, 0x5ABE668FDCB3F760ULL, 0x9D9BAC9CB9DAC073ULL, 0x215A3FEC534F13C9ULL, 
            0xB9E04A9451006293ULL, 0x3BCD86CFFF0F146EULL, 0x0C7808D4C4F4D709ULL, 0x24B8B4BFB27B8384ULL, 
            0x25C22B3592ABF63BULL, 0x5373E4415765EBC4ULL, 0x22CDAE3A6A184370ULL, 0x3AE307BC0FB78371ULL, 
            0x05A36761C5BE1355ULL, 0x6347589B63736117ULL, 0xD385039673CF6E07ULL, 0x585235875A5F169BULL, 
            0x377A62F8EE65C47EULL, 0x24DFDD691351D0E8ULL, 0xA8EEAE89074857FEULL, 0xF6433DF5EBFA7562ULL
        },
        {
            0xC3D4148EB4D56A9CULL, 0x3CD1C2F826A8AADBULL, 0x5BA1EB3D21D4B023ULL, 0x3C18185148DBABF7ULL, 
            0xC876DEC6304B31EEULL, 0x65654107AAA78104ULL, 0x98E98B859A52ECC8ULL, 0x130C4100A068F728ULL, 
            0x200DFF05FD863AB4ULL, 0xFC09C85D378CCC3FULL, 0x01E1C63DFBA901E7ULL, 0x1778417568FEE0F8ULL, 
            0x0013936742118227ULL, 0x9E18F9593A8827D2ULL, 0xB1E3F23CB1141FDEULL, 0x1250D489F0AFF90BULL, 
            0x2A6E8BF1A19EC999ULL, 0xC24673AA4E9B12EDULL, 0xA7B2385963B02525ULL, 0xDA0EF7DDD73E3AE7ULL, 
            0x25F3F1D6798D77D5ULL, 0x9BFE7624CCDFA882ULL, 0xFC6B52EAEF91DE5DULL, 0x3BA9A33D2584ABF4ULL, 
            0x314A0C1142457B91ULL, 0x9E2C371CB1EEDAC9ULL, 0xA49FBA98E4657353ULL, 0xD20ECAFD8EA29885ULL, 
            0x675885CA00E1F9FDULL, 0xA153D76F8F8F3D1DULL, 0x2E08DD392E8788F6ULL, 0xCD3AB6C95DF8C0E5ULL
        },
        {
            0x5585B4A47C35BA95ULL, 0xC6746BE049B7E664ULL, 0x084B47392F0707E4ULL, 0x363D9A6E1ED0E058ULL, 
            0xA85E98F334E2DAA0ULL, 0x19623AF47C8DFC72ULL, 0x0C893251687759B9ULL, 0x095216E7368CA320ULL, 
            0x53F0BB4850DC143DULL, 0xAA21874223F9AE1BULL, 0x4E89B047B8735823ULL, 0x714D570ACFB95280ULL, 
            0xF5D2805E30FA2F0DULL, 0xA10721F86BAE7CA6ULL, 0x3378BD40528ACBE0ULL, 0x7CB197EEF61ED060ULL, 
            0x0733BC4EBC6136F7ULL, 0x74AE314BEBAEE570ULL, 0x540D095D272D6F76ULL, 0x14BF8A808D7566F3ULL, 
            0xEC49BBA297B08295ULL, 0xD14869780F7A1391ULL, 0xF1ECE64A30F9FD49ULL, 0x964601A753743071ULL, 
            0x5A1AA223F3177031ULL, 0x7B158C1BCA0AEDB2ULL, 0x37F5D9D29614E505ULL, 0x87BE3E691EBE9B05ULL, 
            0xC84E1BAA83695F33ULL, 0x83C9B92B5D7A1DE3ULL, 0x3FEBB4ED433E6133ULL, 0x1AB1E26A339EF78DULL
        },
        {
            0x7EBBF1C6E1F053B1ULL, 0xFEA47E9BAC7BFFA8ULL, 0xA8D8A31A841F1C13ULL, 0x21935403FBC48EDBULL, 
            0x247D80FD26CD4139ULL, 0xB6513FA4F0CB1BC8ULL, 0x3C79B722769F3D88ULL, 0x00E7703505B78552ULL, 
            0x6FCA56A0195067F6ULL, 0xCFCB719BE9FBE433ULL, 0x1054C0473C473387ULL, 0xC42EAD9D354BF0CAULL, 
            0x57DE6523C37B29FDULL, 0x67EFDAA694D45C66ULL, 0x71194638C9A36F9BULL, 0x090389CBDC2B503CULL, 
            0x1B6B6B635164EAC8ULL, 0xAA9990A7D77B9C9BULL, 0xCBA4E1E9395BCF06ULL, 0x316E41032387FF90ULL, 
            0xE551EFC34C139589ULL, 0xCF4381F40F3DF703ULL, 0x921BC5BD59DB7AA2ULL, 0xEE74EB14335B5885ULL, 
            0x468C5F2EAEE70383ULL, 0xA09583A27A716E03ULL, 0x2A44297D45B6AB91ULL, 0xC75907C8CF309E8CULL, 
            0x3E25AF0BFF8261DDULL, 0x0CC6BDDEC419612FULL, 0x26913B7A3ECCE81EULL, 0xE5AA9F0A60AF24C6ULL
        },
        {
            0x7B44F886DAD23699ULL, 0xE422859356D5C601ULL, 0x7D166EC28FD3E290ULL, 0x9B68DA1B74910B86ULL, 
            0x0A6B68F7D6E6039FULL, 0x1F55132460B23CB9ULL, 0x3EAE83B8987511B6ULL, 0xD1999F696838837FULL, 
            0xD03C12DB16F5C604ULL, 0x2436BAFDC3526A3CULL, 0x1A6F7226B6690C62ULL, 0x1FFAF4FE98E13860ULL, 
            0x23B27D72CEB228BBULL, 0xBE8A97E0FBA84D59ULL, 0xCC157E45AE42FC2CULL, 0x199E99288D8D6629ULL, 
            0x4E9DB693E341CF9CULL, 0x1E2AF63542EB7B9BULL, 0x149FD97A5A53180FULL, 0xC7C72A186B3C5F89ULL, 
            0xCE4A6460DC5DB1B3ULL, 0x6A61AD03C25CE728ULL, 0x88E3148A8545C135ULL, 0xD0ABEA3A7D7597B1ULL, 
            0xB40A0C1A84472E6AULL, 0x5B0D7745DE1750FFULL, 0xA8DB82EE284C943FULL, 0x0108684FD67B2EBDULL, 
            0xAADC0721CEFF674EULL, 0xD320FD7C2F2403D7ULL, 0xB300F0646AF734CBULL, 0x9DD964755BA3B736ULL
        }
    },
    {
        {
            0xA5D51F8156A580E9ULL, 0x90F1E31BD396B8C7ULL, 0xEAF656CF7EF5B31BULL, 0x2EF51D404954E969ULL, 
            0xC5EEE0ED2D509D8DULL, 0x46F042800062A6A4ULL, 0x647FDD9EA003F9AAULL, 0xD25731B743ADF47BULL, 
            0xD5FBAE5ECDA1A11BULL, 0x9A48244CDF1E512BULL, 0xF98BF363748927C2ULL, 0xDCD5FB071D0C8AC8ULL, 
            0x7043B8DA2DE7AFDCULL, 0xA42BEA1C636887F3ULL, 0x82DB0FC1989A8BC0ULL, 0xE3B811E10DC87CB8ULL, 
            0xEAA8700FFC0FF0EDULL, 0xDE9EEEADF1C2CC13ULL, 0xD2072005ACA3851DULL, 0xF3152354FC47B233ULL, 
            0x331DF32D77990908ULL, 0x7AD3B3346DE54E73ULL, 0xBA67A942CE590B17ULL, 0xEA5D06A2B4248E04ULL, 
            0xC5AA3E9456C90080ULL, 0xE8DA5911EBCFC232ULL, 0x1C66C65739A2C16EULL, 0x2046EE65B701106DULL, 
            0x4F7FA03486531F5BULL, 0xF6979D6B79EF3E0FULL, 0xB34B513582480C90ULL, 0xEE80268E0596C366ULL
        },
        {
            0x82ED946F9D4C55F8ULL, 0x62619F2E6C6D8F75ULL, 0x23ED04F6A9FA5B5BULL, 0xBCC8D452F9D6E2A8ULL, 
            0x9B582A37E1901979ULL, 0xDA7CD0824FC81DE1ULL, 0xCA107A6AB7A0E48EULL, 0x8F433ABC1570BFEDULL, 
            0x5DA29772F6704F6BULL, 0xA2069DE9BBC9FFFDULL, 0x951C51DDC1AA7F73ULL, 0xDDF29484381AE9D5ULL, 
            0x5587FB3AE264E7CDULL, 0xD93979A6E791C46CULL, 0x5DB91F2D56543AD2ULL, 0x36AC0C0E74B56904ULL, 
            0x44FA517F74F29FE9ULL, 0xF170194CD901D13CULL, 0xAE301756CBE9D577ULL, 0x8BE8419C8E7C6050ULL, 
            0x11BBC34850E6BB55ULL, 0xDD7A55EE6B3C056CULL, 0x40EAD956D8FE9D35ULL, 0x622E01A546108CFFULL, 
            0x4B9C5F967D888B71ULL, 0x0294E8C3A5573CE1ULL, 0x275F5233FD682C91ULL, 0x35F7003AB168A947ULL, 
            0x5D6BBEA7937E8B2DULL, 0xC4D0EA6B95F79B27ULL, 0x96412710BC6C8833ULL, 0x1FCAB7E38F040D7EULL
        },
        {
            0x508F50FB58782603ULL, 0xEB371C9F9005E86CULL, 0x5426DE4B4B341CADULL, 0x7CEFA3A677374F1BULL, 
            0xB57D010FCA675103ULL, 0x0B0EF31B5696C5E5ULL, 0xFEE0AEDCF9D93181ULL, 0x36C2721652A21EFEULL, 
            0xA17AD683B837E374ULL, 0xEE062719E06FA1D5ULL, 0x74CBEBA1CAE4B6D3ULL, 0xCA9D1D4BEF48DAEEULL, 
            0xA109BAC39F4D7211ULL, 0x030914E438B96149ULL, 0x78707663341B38B0ULL, 0xAE520130A42258FAULL, 
            0x009196476EC8862CULL, 0x12460072944A3121ULL, 0xFD0FD53D94B1951CULL, 0x2A92E3F4828DD865ULL, 
            0x5C736C387EA9318AULL, 0xABE83FD593268356ULL, 0xEDEA912E4636FF86ULL, 0x6C55A90565034BC6ULL, 
            0x867E6B9FCCE62643ULL, 0x743F14B862E54972ULL, 0xEBFDCACEEAED6634ULL, 0xED7B6148E085E453ULL, 
            0xB29A299CE1E2A17AULL, 0x0189A61E8F953750ULL, 0x3614C104DFBC40E2ULL, 0x4A5710A3420FCBF1ULL
        },
        {
            0x9A8CC9EDF5680869ULL, 0xDC221A5742F6FCD4ULL, 0x7569B31E21BE549EULL, 0x847C8E97266A7EC3ULL, 
            0x258B50BF8B09D2B5ULL, 0x687AD51F9F3874F7ULL, 0x7106C8D2140CFB07ULL, 0xDA2AD54BBFD24FB4ULL, 
            0x30D1ABEBDB5A6F25ULL, 0xF834BE31A5DA5DA1ULL, 0x7EF593B371E76F93ULL, 0xE9358DBCA7EE5E79ULL, 
            0x467CBAEE37CF038CULL, 0x71B1221E5ED4590AULL, 0x7DE70AAA14486503ULL, 0x07587770C33E0638ULL, 
            0xF728DD13BF733A75ULL, 0xC888C3789D7A6854ULL, 0x39A39C4AB0DF8EAFULL, 0x48B90F237580295DULL, 
            0x1EB7B7791A68302EULL, 0x77B64F87008F7863ULL, 0x8CE269BAA8E64AFBULL, 0x7CF5649D51BB6C4DULL, 
            0xF074C53C4B0D2ECDULL, 0x513DD4403B80ED2EULL, 0x35A7FB81B343E837ULL, 0x78E5F78F0891CB4CULL, 
            0x50A941150F716350ULL, 0x036A34E717A4C165ULL, 0x00806DAE4A09B796ULL, 0xA2955B429B870D58ULL
        },
        {
            0xA6213779D06E4CAAULL, 0x08FE9BA2917D5625ULL, 0x2FF8A672B240CEA7ULL, 0x8963B9A3924B4F21ULL, 
            0xB0EE7D87273C81EBULL, 0x00197EF29E404A31ULL, 0x7D81061F7F08E14BULL, 0x9567DCB765131326ULL, 
            0x114635576C56903EULL, 0x05D63382197A7083ULL, 0xB3A77A8E46C8654EULL, 0x6E09095A0BF89ED9ULL, 
            0x2D03934C54AB27D2ULL, 0x2D132DA18B65D247ULL, 0xEE3D617363F15D85ULL, 0xAC913FE64D6F5502ULL, 
            0x9FA03D9773AD568BULL, 0x60D61881D18BD65BULL, 0x891C600C34625389ULL, 0x6EEDD010F2F5C306ULL, 
            0xAE7C61EBFE02B7E1ULL, 0xFCE3E26C5E67A553ULL, 0x4C6D641D32D95C7CULL, 0xFFAD5FA186E3B2D5ULL, 
            0xB0F5E1D7DCF5563DULL, 0x9096D697BC4FE88BULL, 0xB5D39C054336A825ULL, 0x88BD475FD79880DDULL, 
            0xAF1FD93C6D4EF92BULL, 0xFC79C7915A3DFB31ULL, 0xFF84976B8584EE00ULL, 0xD69E5AB48C905626ULL
        },
        {
            0x5C40DDE5CBB6FDAEULL, 0x7E353775686CD4EBULL, 0x78B06C70E68D0D15ULL, 0x8EBDBA3C6088ACECULL, 
            0x3CDEE47E66490940ULL, 0x81A4F1FFBB224206ULL, 0x31C783E035FAD221ULL, 0xD366A36C04BFCD1EULL, 
            0x819503D7F98F4E5EULL, 0x7BCABDCAAE31CAA2ULL, 0xD171D7B0C797B714ULL, 0xC6CC8460AEDD1CA5ULL, 
            0xF221B9F7EE017D79ULL, 0x3CF5F0793DDFCBDBULL, 0x3AD8397A0736B8F4ULL, 0x17671540BB203040ULL, 
            0x0295E0D3449CE782ULL, 0x26A3CACA08767F16ULL, 0x2CA6811FF6FFB946ULL, 0x2B54F7EA9006BD51ULL, 
            0xA5D32CA751084655ULL, 0xAD95E80DA7E9F6C6ULL, 0xD47C2095A3654CFCULL, 0x12AAA615402B5D47ULL, 
            0x08963E1F231DAE28ULL, 0xD4E8956576FB4A3DULL, 0x0B9A3DEFE56A3295ULL, 0xCF17FD35D71FA3DAULL, 
            0xBF0E546E0AB145C4ULL, 0xCC150D050AEE0095ULL, 0x7390DEC45D0340A4ULL, 0x767ED0515E369605ULL
        }
    },
    {
        {
            0x44E5563A40D37987ULL, 0x51E8C306FDE40199ULL, 0x701F75AC328DFF31ULL, 0xE1F099925090AAEEULL, 
            0xAB5DC6599D160ADCULL, 0x361127FFF25A1F63ULL, 0x9D8642F6A8CEC966ULL, 0xE5094344405D88CDULL, 
            0x643F1DEDECDA3A10ULL, 0x4C60DAA12C4E3F91ULL, 0x7FD6CA175DC2E160ULL, 0x3728608670914738ULL, 
            0x029F57688707E700ULL, 0x2D44D373E4E0A718ULL, 0xDEC30FFEED8C52EFULL, 0xBE61BA1D7802D159ULL, 
            0x826CBB21D9CF8C2CULL, 0x23F6E0324778307BULL, 0xCC7EB608F0139B33ULL, 0xD687A7FBE604C811ULL, 
            0x0AF64399942470C3ULL, 0x2D54F1F0CEDEE444ULL, 0x873657D391DA3C69ULL, 0xB3EAE3BB345B8303ULL, 
            0x022E895C2F6483C7ULL, 0x5666AD03D0272E46ULL, 0x9B19E82B1236EAE7ULL, 0x8832C1AA4DC0A971ULL, 
            0xCE6A688D0DF87B71ULL, 0x7E3AA78E2969255BULL, 0x4800B7BE7ABE5280ULL, 0x0FDF4013993D2432ULL
        },
        {
            0x246A082DBE4A121CULL, 0x62ACD64D1EECD661ULL, 0x08CE82E209122E0CULL, 0xD4B30CB98AA5A250ULL, 
            0x768B55EDEC1D40D4ULL, 0x952E805F04B751BDULL, 0xE7E3B8E90537C2A4ULL, 0x95873F86D3FE34AAULL, 
            0x92B781EB35C1131DULL, 0xB2BD17577AAF5B07ULL, 0x6865E1EC0EAE5882ULL, 0x5DEA8E894FC47467ULL, 
            0x662639B4507DF4CAULL, 0xA102C6ADE80A5F22ULL, 0x7033BF8A0D554260ULL, 0x9EEFF337D0DB7E48ULL, 
            0x26A072B12C529302ULL, 0xFF01712FCAF2865BULL, 0x1522DF0BF37C0B7DULL, 0x13AF6CB5F44D47B6ULL, 
            0x2A1170F06CFEE1E2ULL, 0x07E56E191E063B0CULL, 0x0E3FA6789740F696ULL, 0xAAF1892B09EC40EBULL, 
            0xA3CF1B50D43FBF24ULL, 0xE573FECDA56DDE5AULL, 0x55DB42C1465D52FDULL, 0xB728961B0B3F1BECULL, 
            0xCD548DA8D23C06A1ULL, 0xBA53C07509666B03ULL, 0x3E6AD7834B0300DAULL, 0xF01E609743DE4713ULL
        },
        {
            0xFFF807EBDAAF92B6ULL, 0xBF00D71677798B48ULL, 0x4321166828A7AF33ULL, 0xB5FB1F40944363BBULL, 
            0xF72EB18096063D54ULL, 0xB52394955E61BF00ULL, 0x5C2264AE04CABBE8ULL, 0x9DDF86F588EA7147ULL, 
            0x3E6EE22CC8A3FDC7ULL, 0x74CB76EA6A758248ULL, 0x96715CDF63064057ULL, 0x617BDBFC0905260FULL, 
            0xCDD4FFB1124B08CEULL, 0xDF5BF11A078DA047ULL, 0x226AE11F6B0F5403ULL, 0xD700B69ACAB628C5ULL, 
            0x63BBC2CB9B5DD98AULL, 0x9E11C5EFA0B1ED6FULL, 0x72388B4BF4FEE23DULL, 0x894CEB8799FF5333ULL, 
            0xD8FDA697CFB32A5DULL, 0x1955AA5608C1E971ULL, 0x07B639F1461F7628ULL, 0x131455B8936393BEULL, 
            0xB4DBBAE607A8DA6DULL, 0xCE7FB877F122B0E2ULL, 0x6AEE95932A435C6FULL, 0xD953551E014D8B10ULL, 
            0x7006B1D655E916F2ULL, 0x1F4C7BE7FE915846ULL, 0x509F41A066205AA6ULL, 0x1EC38FDC9EE8556DULL
        },
        {
            0xE3B123677AAAFBFDULL, 0xD3C6CBBF7E73F2CFULL, 0xB18DA52648121E62ULL, 0xB38AA3C3D627BC5AULL, 
            0x85BFE33C3C3B34EAULL, 0x4BB44AAE383BABFCULL, 0x1942DC9C84F6E33CULL, 0xC4970450F7936789ULL, 
            0xD24CDB249DB8DA1BULL, 0x04EFAC74EB591B46ULL, 0x6A9504BBAD908A70ULL, 0x99B766F2546CD86EULL, 
            0x278BE2311EEBC4F8ULL, 0xFAEFFA562280C38DULL, 0xF215CB0724BF35F6ULL, 0x05EFBC570F30B872ULL, 
            0x2127FD2B5736BE3FULL, 0x5D91C0BFC0CF3458ULL, 0x2352B35225E74F49ULL, 0xBB3AC7D743DD6E56ULL, 
            0xA2B6A31F6C59C11DULL, 0xBB90EB94AC3D4028ULL, 0x60C420628E23E8E2ULL, 0x8214C1EA6D56BF7CULL, 
            0x76D239A67B824E41ULL, 0xC2C9F59C7A1EC174ULL, 0xF4D617C8509FAA3DULL, 0xE3E1D7465D4120C0ULL, 
            0x40A4EEF260589AECULL, 0xE7BA91B8A64868BBULL, 0x8FC281A63EBD60C6ULL, 0x68C1C0976186BDE6ULL
        },
        {
            0x8807605F358D2766ULL, 0xC63E9C0A91D622EFULL, 0xA65039FB4591644AULL, 0x1C366B600D6B9E9FULL, 
            0x00B6B73D56A41CB8ULL, 0xA5CBBD40B00A6553ULL, 0x006907B4A88825D4ULL, 0x1222DA2010FD1749ULL, 
            0xA9C344F6E6DCAC0FULL, 0x3E16D5A63C7D8467ULL, 0x0D89B22152C90738ULL, 0x1D7F2A931B312C3FULL, 
            0xA1BC1FEB76B968E5ULL, 0xAA8F02178AD1052DULL, 0x7DD90EB81A7BDACDULL, 0xED6B29EB7AA69808ULL, 
            0x87672ADF7CD4DC93ULL, 0x4DFFEF5290DEA9F0ULL, 0x35FFE17DEAF6AECBULL, 0x0A764517738E2172ULL, 
            0xBA1B58E5669D2D5CULL, 0x577E3E3EAB56B2E3ULL, 0xF70123279520AABFULL, 0xFEDB4FE6084327DEULL, 
            0x0B2FE861CD041874ULL, 0x24348EE754380BBDULL, 0x6DB61C6F50F85494ULL, 0xD339E91E39A400D7ULL, 
            0x67ACE5493BE99BFFULL, 0x638E732624E03A6CULL, 0x8D0C91111BCEB309ULL, 0xED967997F124F2E0ULL
        },
        {
            0x6E58C34B226627EFULL, 0xEA9076CE0880CF8AULL, 0xB58C1B49DA9BBF93ULL, 0x25A1DDA3B3214F59ULL, 
            0x5E232207823DEBE0ULL, 0xB76BB600EF084EF1ULL, 0xF7307BE22FE09374ULL, 0x4FD861D8A8525BFBULL, 
            0xD4C444F519EB30D0ULL, 0x8DB7AC4A2A7D611FULL, 0xC1452E9CF9181CECULL, 0x2112AB36407E3863ULL, 
            0xE4035608E81AB56CULL, 0xA61BCF160691DCD6ULL, 0xE388F45B785B2801ULL, 0x1438EAFC8ACC5DB8ULL, 
            0x58F66FCD15352631ULL, 0x3ACEDC66E6F59E44ULL, 0x5BC5185133BB1E41ULL, 0xE1F51CE2F5FB8E48ULL, 
            0x90F2BBA46A971817ULL, 0x21652E7CAD1658A1ULL, 0xD98D498D0B11FADEULL, 0x9C8E7088D3E91E80ULL, 
            0x7EDF2AE4AA20F572ULL, 0x9A68B31AA97021C5ULL, 0x7BB917FC92EDF5C4ULL, 0xC0F7A1B06C16414AULL, 
            0x7593BF8F1BB219F0ULL, 0x77CF78F0E8DAAE62ULL, 0xAA8A2AC138C15F66ULL, 0xE21F630834BACA0CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseAConstants = {
    0x77EEB20077D2FC35ULL,
    0x5E2DEED16B73F6C2ULL,
    0xF4968B6DCC76959EULL,
    0x77EEB20077D2FC35ULL,
    0x5E2DEED16B73F6C2ULL,
    0xF4968B6DCC76959EULL,
    0xD649072CF17566F1ULL,
    0x578EADB14394DC1DULL,
    0xC5,
    0xF6,
    0x2A,
    0xD6,
    0xA9,
    0x35,
    0x7E,
    0x95
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseBSalts = {
    {
        {
            0xB12D9E18DD34DA98ULL, 0xFE86C491568EA0F6ULL, 0x3BBAD4388D2F08C6ULL, 0x891782512253FC58ULL, 
            0x8D8BB6BF328075BBULL, 0x13A847658EE2838BULL, 0xBBAE5F7899ED7442ULL, 0xEF4D930FAB98A457ULL, 
            0x32C5479473B72A80ULL, 0x9164C65F7B9D6DF5ULL, 0x46EFAF6D762BA978ULL, 0xA37627ED53888C32ULL, 
            0xE1D5F03123503C9EULL, 0xE09D28032C0100FEULL, 0xE583F9A9E04C2ACBULL, 0xF6852A0329C51585ULL, 
            0x88777D37C1A85968ULL, 0xB58962AD19A757D5ULL, 0x5A8D696A25685F76ULL, 0x8F6B40DDDE93C720ULL, 
            0xC0737D8245BF1CECULL, 0x0767613E5AB1B589ULL, 0xCF7680A668723C7BULL, 0xA2083337C7113AB2ULL, 
            0x74966C5779E4B422ULL, 0x81F6A0688CE84072ULL, 0x07AE2EB84B086815ULL, 0x2A530B7E6A434505ULL, 
            0x83FC1FA769254C15ULL, 0x455DF3A70DFF5BE6ULL, 0xF981BEBDCEA70729ULL, 0x067FB9F03A4C61B0ULL
        },
        {
            0xB5A59D34597F0B34ULL, 0xF453755DE550D3B2ULL, 0x45CE21F27D9B24BAULL, 0xB0D5E86F6A1043F4ULL, 
            0xBAA68A56A36404EEULL, 0x9FD4696FE9E1DE32ULL, 0x3B1209F2EFA7F5FDULL, 0xFA499FDEC40C16FCULL, 
            0x93168B506A41357FULL, 0x15415E59EE548F30ULL, 0x47FD9305A3E2C12DULL, 0x7FFE78518B9D1672ULL, 
            0x77BCFB797D186FBEULL, 0x58BFBA27F23BE4A2ULL, 0x558D6C96CFE018A4ULL, 0x37F13551CCCA29B7ULL, 
            0x19D6FFFDE0CE2794ULL, 0x9BE79B66A774602EULL, 0xAAFF34EF1118793AULL, 0x5F34AE821F687F75ULL, 
            0xA6AA4BB69CB84700ULL, 0x67C4ACFE5C44D2CFULL, 0xE9477100C76B06FEULL, 0xD8B3877BAEF6EC7EULL, 
            0x3DB0E20001A6171FULL, 0x25250479B51787ECULL, 0xBF525115E3B99724ULL, 0x6935881CB54943E6ULL, 
            0x78CA9A6859D00E8FULL, 0xF61050D9FE865FA1ULL, 0x561E14FCD0630748ULL, 0x64E955CEB8DBF36DULL
        },
        {
            0x54E73B1B274E6712ULL, 0x318DE3DDC35842A0ULL, 0xEB76E8CEF4C955B7ULL, 0x1BD75F3A298026F9ULL, 
            0x98BEAC205DACED35ULL, 0x590838FD4642E67DULL, 0x0B11C39413FCFD57ULL, 0xFB78D2D03765AFB2ULL, 
            0xECD867ECD5797D6CULL, 0x49114FBAC8C87CCDULL, 0x0E57E504E2657E6AULL, 0x7FC247AA2FDA575FULL, 
            0x48FEB7A8A0A35248ULL, 0xEAE0D50ECA9FC0B9ULL, 0x4F4B225525B7267CULL, 0xB8A286F145F05507ULL, 
            0x51FC117B032940F3ULL, 0x64881CD59BB0699DULL, 0x3155C0B9EA192FECULL, 0x2319AF980A5DFD6AULL, 
            0x1E41047347B74FAEULL, 0x22B77668EFB4866DULL, 0x64B131C5A253DEC0ULL, 0xB7ABB9539096FF92ULL, 
            0x01C683B51C186F43ULL, 0x51CF2ECF9EDC3BE8ULL, 0xB4129E603B8921D6ULL, 0x478BAB871AD0FCF1ULL, 
            0xB0E024764D2BB2BCULL, 0x9302DB75EB2E882EULL, 0x50C777AA79564A69ULL, 0x71789D59CC11F081ULL
        },
        {
            0xC1BB8E0577BF2310ULL, 0xC091D3D1EC9AAE10ULL, 0xB5E4F5080303067EULL, 0xC7B2C83FA6500699ULL, 
            0xB00E08F11717C75AULL, 0x1811C86F662DB9EFULL, 0x68A3DF8C9602B8ADULL, 0x4F258577719A4970ULL, 
            0x508343885A621102ULL, 0x54C986E123B5E660ULL, 0xCB8D4FF558B8666BULL, 0x99A409B4BFC194A7ULL, 
            0x429AEA30F539C59CULL, 0xDEC5BE887B555745ULL, 0xB31F090C64294036ULL, 0xE170CDCD8D8651FFULL, 
            0xB0BA13287BF9D6C8ULL, 0xBABE01DD61627E8AULL, 0xD8367894C4CC0E4AULL, 0x675FE566E7D4F2AAULL, 
            0x20FE23C64067D330ULL, 0x7EBAAFD20DD3DC23ULL, 0x71108D8C2C3DD0AAULL, 0x07AA77A6B108B893ULL, 
            0x48EB7DE52E5FE6D4ULL, 0x1339C01BB20D0635ULL, 0x84CACCA3357AFB2AULL, 0xECDF642FFEFAD7F1ULL, 
            0xD23ABEF54EF704FFULL, 0x04115F5B501EAB9DULL, 0x3B63033D1A165E28ULL, 0x0AF35EAD08DACF96ULL
        },
        {
            0xCD09DA4A8D8221F8ULL, 0x104B14F0F0B2004FULL, 0x49C1F13EE6C5B8EFULL, 0x216B4527567282A4ULL, 
            0x1DE57DB9D9E96D9DULL, 0x278638069391A890ULL, 0x0D72C9D8617B56B1ULL, 0x512C2F0CF8456E1AULL, 
            0x122389AC299E95AFULL, 0xB27841C6AB8A36E8ULL, 0x3528532AE3EFE7F2ULL, 0x17EAB467418662DAULL, 
            0x4551D869F3C770E1ULL, 0x4D462FC10FDFC9D1ULL, 0x619D1D63CF18C3BDULL, 0xBA5BA892862E03D2ULL, 
            0xC434E26CEB65590DULL, 0x30B7F90A43049D47ULL, 0x636429AE61D5692EULL, 0x83D4A554EA41E28AULL, 
            0xCD4AE4AD9ABC29ABULL, 0x58790DE080DE3497ULL, 0x93CDA0F03FFD6380ULL, 0x66D2FC88BB421454ULL, 
            0x1D89BBD7946F7DE3ULL, 0x8FD2573744190B71ULL, 0x0AA94C0327D778F1ULL, 0xA0E800AAE1534BBBULL, 
            0x215D1A77884DEF02ULL, 0x96D2A36530A049C9ULL, 0x727235D37A58D283ULL, 0x465469AE27222493ULL
        },
        {
            0xB94CFAE6A35B6C32ULL, 0x1CD704509B9F8143ULL, 0x702473924CC851F1ULL, 0x4EE4F30119399ACEULL, 
            0xBD9E5755E07EC7D7ULL, 0xFD335D314CFC59DDULL, 0x7EC109D5BE98816FULL, 0xE04D8CF58467990AULL, 
            0xFE8E77279D2C85ECULL, 0x85B797523CC953DBULL, 0xE5D89A8636F3BD0EULL, 0xB3CDA1950C3A4E31ULL, 
            0xF6A40F473BF3B382ULL, 0x10DA817D5B343A2DULL, 0xFF92D508B8F0261AULL, 0xDC38825D34C07AE2ULL, 
            0xD02D3A10E70BDD7AULL, 0x63141E1669214C86ULL, 0x7D4C2B0325D2C8DEULL, 0xF3E5E256513D1EA8ULL, 
            0x8DD74AA700393AF5ULL, 0x059CE903C617EDD5ULL, 0x8DFA52C43FC919C0ULL, 0xB05069F6F8398BB2ULL, 
            0x532CAE170679F109ULL, 0x58DA8B3479D74E76ULL, 0x9469CA874AA530D8ULL, 0x30162E7FF684DC73ULL, 
            0x653469DEB5260E35ULL, 0x2CC0D0FB337760B1ULL, 0xFDE8BBBA1E9B537FULL, 0xDB4E599AE4810273ULL
        }
    },
    {
        {
            0xAEAC723A0D20C540ULL, 0xA806EE73DCEFC542ULL, 0xE8404D173857EDBFULL, 0xAF43698D1DA4CB0AULL, 
            0x120C8BDFA9AA03CCULL, 0x2BC25974EC60A96BULL, 0xA3CD5D35B7E9FF7AULL, 0x6F997207FAFB766CULL, 
            0xAF40E76382559FBBULL, 0xEB895B59F3334371ULL, 0x7CA9267F2068596DULL, 0x925B21A45D76159EULL, 
            0x2C3ED46CDD6B3A3BULL, 0xAA847BC425552A90ULL, 0xD3C7246C171EC538ULL, 0x130B86E4833F2519ULL, 
            0x9E45E380AD21A0F0ULL, 0x33B112EE19C9168FULL, 0x9B0C580AD68D5397ULL, 0x5EBEF843746E8737ULL, 
            0x496585F78978AE95ULL, 0xF7C277C5AFE4EAA5ULL, 0x6C365902E20FAED5ULL, 0x891909A8848349D5ULL, 
            0x7F401ABF5D85D100ULL, 0x70C816E020084E9DULL, 0x2DC26D7CBDEBA151ULL, 0xA9E7EB808AFC8B70ULL, 
            0x2B669A865F381CC5ULL, 0x181D0362F3A641ABULL, 0xC489B030C7F9D906ULL, 0x1307F94FDE80EF09ULL
        },
        {
            0x4154CF029E539E99ULL, 0xBC0C095A9F46AE51ULL, 0x1EF9BB8BEA5D9F9FULL, 0x24500C2A46B50343ULL, 
            0xB970E66DD468E827ULL, 0x173F962033840570ULL, 0x299347C38F515B78ULL, 0x9C14935EDFAA67C0ULL, 
            0x1E4A3C29CFFABA9FULL, 0x0FD922DF779C1EA9ULL, 0xB3E8E0E8F9898F96ULL, 0xA234144C4453868BULL, 
            0xF2BBDC9839E9FA38ULL, 0xB15B29D716CD42DDULL, 0x4F826AC4697B9504ULL, 0xEADEC8D2222B4E3DULL, 
            0x16771460E615CE0EULL, 0x8819DC9BCBFCD827ULL, 0x132BB150084D9444ULL, 0x12A05F53FD5FB7B3ULL, 
            0xB53B11005EE261ACULL, 0xDE6AA946A4200D15ULL, 0x1D96EA9998905B55ULL, 0x26EDFB74F28BB53EULL, 
            0xC9C8ED5B3CAAE2ABULL, 0x53891CDCDA9E5427ULL, 0x0F9700E01F13C063ULL, 0x7D6A851458DCE63AULL, 
            0xF1A3A6412D56DCC9ULL, 0xB41115B845F38CD3ULL, 0x9FB73BA1FF381EBDULL, 0xAA9EF4C8984C0222ULL
        },
        {
            0x8B6B76340FE33EC3ULL, 0xB0DE160A43A4CAD9ULL, 0xE40CF0B5FF323993ULL, 0x29795C6A3DCB9A4CULL, 
            0xF5365CC99CAF107CULL, 0x0500023994824DBAULL, 0xF0FA2BD0792DC11DULL, 0x7CE5382A2C007CD5ULL, 
            0x63EE3DD61506D5D2ULL, 0x232754B0CC021024ULL, 0xD4F46718DF6BFA4CULL, 0x596B8FCF3D06A1C5ULL, 
            0xCF972304CEC0B7FBULL, 0xF6047A3CF89FE291ULL, 0x4358F0024600157CULL, 0x5B46C2810D8EF53AULL, 
            0x7EA77F38088A5B8EULL, 0xCEF7A86C34B1DA05ULL, 0x25E955D293C208D4ULL, 0xA43EAA4EBEDF3BC2ULL, 
            0x9B294851A318498BULL, 0x6D97DC75C1DF9837ULL, 0xDE852BAD7FA2C151ULL, 0x0A13BF59FEF30EE3ULL, 
            0x485745BE15C01389ULL, 0x3290014DC7ECE33DULL, 0x125A3624474382C4ULL, 0x7123E633EAEFB8EEULL, 
            0xD620BA28BC2E307CULL, 0x4A111CDEEDF27451ULL, 0xEE5E67DA14673026ULL, 0x94A18DC70EF4B016ULL
        },
        {
            0x3293E16C7B5449CFULL, 0x330B1DA43AC67E86ULL, 0x31BFF3E3515037F7ULL, 0xFF71E16F3B24B227ULL, 
            0x25C3306BD5996931ULL, 0x3D9974B19CD1003EULL, 0x955EF8E11C832E4BULL, 0x9E1EB57E8B5020CCULL, 
            0xFCC6018F1B6198B0ULL, 0xBE03D9BBB4F11DA4ULL, 0x17F22F5A215F025DULL, 0xE981A068B01A7C29ULL, 
            0xD0A7A706C1967B4DULL, 0x5A580E72373CD4E9ULL, 0x2ADB9FAD93226B56ULL, 0xF6937C79B4B3ABC7ULL, 
            0x29F5805CD28E9506ULL, 0xAFBC34F75345F736ULL, 0xA286AB92AFC61D09ULL, 0xE599A713469D79D4ULL, 
            0xC9B7CFFD72512923ULL, 0xCA370A12E2AF213EULL, 0xF105930F5E426350ULL, 0x7BB6305B2DDEEF10ULL, 
            0xB8B8587D6868ACB3ULL, 0x86709C0AFA900BBFULL, 0xB76B134D5D8F3D69ULL, 0x6072064A1B000408ULL, 
            0xAA02F8A52B3AE78EULL, 0xACC57090BD12F8DEULL, 0x21E3E0D25353D1D9ULL, 0xD07CF3BB11B2F12EULL
        },
        {
            0xCD38F0482E98D5D2ULL, 0xAE1729D34B7E792FULL, 0xCE53A12E21760B09ULL, 0x200FB96EEA4BFF21ULL, 
            0x84FC86BA0CF59FB1ULL, 0x73F4EEE6B76065A7ULL, 0x3BD03C24ABFA357CULL, 0x97148A9D93989B0AULL, 
            0x8EF7AE91F56CE43FULL, 0x2F671DDD2A3B6006ULL, 0x59D555078294AC82ULL, 0xDDDDC5EE684FEE04ULL, 
            0x631C0D8E91B04F75ULL, 0x243563AB5DC6203AULL, 0xF4915A0B60485AD0ULL, 0x6F7002CB34061361ULL, 
            0x72A0233924F0FCF7ULL, 0x989776C2D7B45F6AULL, 0x6A7AA50AAFCA92C7ULL, 0xDDF4BF3850060F1AULL, 
            0x06C84DDD1B538BE5ULL, 0x191F435565FE5753ULL, 0x4EB55E9AA88B9CA3ULL, 0x8257536ED47540D3ULL, 
            0xD3F8316095895953ULL, 0xDB81600525810E9BULL, 0x8502EC8A460A6E95ULL, 0x438E615163760549ULL, 
            0x259501204D9F09D2ULL, 0x41DE84B7B8BB07DAULL, 0x5D1EE050FDCDA963ULL, 0xFC5CF9DA867A2B83ULL
        },
        {
            0x766EACF525F1B9F9ULL, 0x306F0B57224328D8ULL, 0x66853DCA1A8F03B8ULL, 0x836918590FCD2FD5ULL, 
            0x73BE6904B2C45282ULL, 0x86CF0198E1CDAF77ULL, 0x658DF80EA39EF06EULL, 0xB5AAAFE9A56A7130ULL, 
            0x3613104A14A50EC4ULL, 0xC3B2B7E8435DE5F5ULL, 0xC5168970F04C518AULL, 0xF4E830895CCF4EBAULL, 
            0xD8D727975A6FA640ULL, 0xBE4E949D927CF8B8ULL, 0x27F7AAD99DEC6AFCULL, 0xFB87A21A9537D736ULL, 
            0xB02E2078288794D8ULL, 0x58E56FB35902B6F4ULL, 0xAEA9AE6A539B3E3FULL, 0xDA10A99DD2E1F436ULL, 
            0x2F6EB7B1428ADF29ULL, 0x0BD5BACA8FB06108ULL, 0xF11E5A0D94A9AF87ULL, 0xF30B2FFEF654356EULL, 
            0x1A9854944AD5D2E6ULL, 0x90EEAE76A40918CBULL, 0x2367C6DABB38F796ULL, 0xA52AE719A0F8E41EULL, 
            0x91EEECE322CDF3F9ULL, 0x2056938F17B417A6ULL, 0x5B7D36B2B12C931BULL, 0x23219763AD534D8FULL
        }
    },
    {
        {
            0x1F9DB047F8F67EC3ULL, 0x505E527270099A76ULL, 0x67556CE62D6225FBULL, 0xD329064027A68497ULL, 
            0xEB6FB7D23D591A84ULL, 0xD962550F409C724FULL, 0x755FC1200E5EDB0DULL, 0x8D3A91E9586087C9ULL, 
            0x5E2B3F996EDEE225ULL, 0xE667364DB9794B66ULL, 0x05DD458FFDD4D228ULL, 0x3D5254BD99ED70FBULL, 
            0xCA5BFDA0107E8E8FULL, 0xEF737EEA581CBDFFULL, 0x108E1F54CEC0E83EULL, 0xC6D8E9B4B6D26A7FULL, 
            0x0FC2C9E2FD2F460CULL, 0x4B9F9285D18FD71BULL, 0x949A3F0690C15731ULL, 0x1E75C1ED21B12924ULL, 
            0xBA14ED9DCB194651ULL, 0xA5620536FB3AC394ULL, 0xE15D61FB837F7269ULL, 0xC7ADD078DDA271C5ULL, 
            0x890C89FDE10DFF7EULL, 0xF2BCF8000B46CA60ULL, 0xE7F2EADE180FECDBULL, 0xC649FA945A14CE5EULL, 
            0x93FC70F14C431D53ULL, 0xBD2A236EA37E68BFULL, 0xF56E63FB0BFF9030ULL, 0x22FD661277948EA4ULL
        },
        {
            0xDA65DA942B50F11CULL, 0x525ECEC28B34AF0AULL, 0xC6964883BC2DEBA1ULL, 0x470C6F4BC238B64FULL, 
            0xAA1CD6F5DBF53966ULL, 0x6D30DF5365C059C8ULL, 0x41B6B811CE955904ULL, 0x7E57F331A78A2C14ULL, 
            0x83B87E4A2F2EDD6CULL, 0xA9D0E18853BD673FULL, 0x9485F4000386AA83ULL, 0x74F0689EA0F652DEULL, 
            0xAE58B5AD1F322E78ULL, 0x2833B78CF141E54CULL, 0x872681E70B8FEAF5ULL, 0x8011D1976A2727DEULL, 
            0x74C0F1F0FDC9978CULL, 0x7B73769E00EC653CULL, 0x7721B29054952224ULL, 0x572DCA9F1FD3926BULL, 
            0x32B0131941C191F5ULL, 0x4CB401AC7E3B1326ULL, 0xC9CCADD73AABB42EULL, 0x560CA910C5661C23ULL, 
            0xB210813EEEC29505ULL, 0xF8D5F803D1E36DE2ULL, 0x5643C8ED340E9B42ULL, 0x98D0B590BA45B079ULL, 
            0x1A39E61A711EA24FULL, 0xBC21106197A04DF3ULL, 0x583592BE67136117ULL, 0x17F41BD846A31ABBULL
        },
        {
            0xCA3A6565F2744F50ULL, 0x68DB213D98DF14ADULL, 0xB95FE52E5A490DCBULL, 0x322949E2AE3BEF78ULL, 
            0x654A18FFDD807B55ULL, 0xA6FB3AD32D75E58AULL, 0x02C15DF42F23F5CAULL, 0x33B5268FB3EE3429ULL, 
            0x40310CB670D4AA7CULL, 0xA91D6F6D67E39E69ULL, 0x983163B803B40CF7ULL, 0x121143F86E171BB7ULL, 
            0x8D3C0F1237125019ULL, 0x52FF03D4D542F5A7ULL, 0x4749B78553D383B7ULL, 0x01D2843EA0F8491DULL, 
            0x6F35207C71F3F095ULL, 0xC26DC5F030A35BD3ULL, 0x4A8693B5B0B5CB43ULL, 0x439B8FAD99DD91DCULL, 
            0xE53E14FA5155FD63ULL, 0x7E467102AB1F2D99ULL, 0xF4FADBBE73F2B192ULL, 0x48F3AF74089C861AULL, 
            0xCF2228BB13A0564FULL, 0x184AB7928B72F912ULL, 0x6BFB086000513492ULL, 0x5CB83DED5428885CULL, 
            0x26FA2B8A9E19FCDFULL, 0x20BDCF1FE3E7FE0EULL, 0x429EEE9AC0AADE9EULL, 0x9C31023E4D1191EDULL
        },
        {
            0x1E1C283FFBF185B6ULL, 0x81E0A7BEB6143EDBULL, 0x68CD5028F76402C3ULL, 0x5DA4138C5AA6AD04ULL, 
            0xA845F5160397F1D9ULL, 0xC7EBED67826DBA41ULL, 0x796BCE22369D4E97ULL, 0xC3CAF5B043A1EFB3ULL, 
            0xCD3F3CD40D88DB1BULL, 0x2E47BD8DC9BF7421ULL, 0x7B258F600F883F35ULL, 0xB403659E97ED4C3FULL, 
            0x77E7820ADDBCC139ULL, 0xF319BF914D834AEAULL, 0x560E3DEA448ACF35ULL, 0xC13F5A9492453FDFULL, 
            0xE05CAD9D867F0800ULL, 0x85FCE253D2CF9E65ULL, 0x1EC8CDFA54547AC6ULL, 0xD206ACA981DCA604ULL, 
            0xD32CF2BB8C8FD869ULL, 0xCEA86BF218C19EC3ULL, 0xF16B44997027A233ULL, 0xE0F01C5BDED59565ULL, 
            0xC3D4B881864410CEULL, 0xD7F9A4AB3DE8CC75ULL, 0x828D6CEACE014FB1ULL, 0xE52A95706EE20A57ULL, 
            0xE3457F59DF539173ULL, 0xDF20FE53E7546EFEULL, 0x5B97BFCEDAE5DD48ULL, 0x7F8C314655EA9F97ULL
        },
        {
            0xA612B42F95586BCEULL, 0x8FD36F8F7C92CA9AULL, 0x9DC82461B42F8274ULL, 0xABE9EDC4CEB04BB6ULL, 
            0x98727A077F9600DFULL, 0x5BED0DA40CCF3BA9ULL, 0xB3239EA794EBE9EEULL, 0x9D87098CA77F6D11ULL, 
            0x03C57627E2550DDCULL, 0x0BFB3ECC506F8044ULL, 0x7169D673C04B8CEEULL, 0x928496E0F8BD211BULL, 
            0x75D4B0DD95B039ACULL, 0x0CF5C0099C867FF5ULL, 0x9138305D9CABC4B3ULL, 0xB730DA85C23F7491ULL, 
            0xB66540C25052EEFBULL, 0xFDF9AE4DCC66B6A1ULL, 0xC022EF846E634F15ULL, 0x8EC343B4C149C437ULL, 
            0x3E4F169BBC22AB63ULL, 0x5AA656F344892688ULL, 0x21C7153569AC22F0ULL, 0x704D7DAAD5E2DA76ULL, 
            0x61062F42AD5748B8ULL, 0x566C598DB126CBD3ULL, 0xBC6BEA13F8BC81AEULL, 0xA6895E69CEB5D712ULL, 
            0x6A8A765DB58955B3ULL, 0x644CCB25CF752BAEULL, 0x52215F407D59899DULL, 0x360720A8C19EB1A0ULL
        },
        {
            0xF1CBBB58B44E5067ULL, 0x03BAEF72761BA0B6ULL, 0xC7C62F2EA3CBC971ULL, 0xB752D6F0263D3836ULL, 
            0xC147B0F613B55020ULL, 0x23C45BC72A03FE46ULL, 0x955F27275D3E8B22ULL, 0xE8815259F601A20EULL, 
            0x6DC75CB41B936E2DULL, 0x873EA6A5FF225F9EULL, 0xC24E231A92285227ULL, 0x027EDDD6BCE5AB0FULL, 
            0x0F885A79AFA88E6AULL, 0x09D0E73CD66BB66DULL, 0x0827ABB008922295ULL, 0x856426A2DD6473A0ULL, 
            0x0C9547CE231D2260ULL, 0xB728E03988DA8B6FULL, 0xEE6847209D05090DULL, 0xF7BA1691A515D56BULL, 
            0x274EB9CD4870CF2BULL, 0xD116D971708000D5ULL, 0x274D07B34421F963ULL, 0x44351FA59E477EF0ULL, 
            0xA293BD30AE75BC00ULL, 0x84095DDAC7536554ULL, 0x381BDCEBEF97AFBEULL, 0xA157B4F3E37A7888ULL, 
            0xE33818B8E6B266DAULL, 0x094D58D020B7E872ULL, 0x2D1DB6FC6CBBC800ULL, 0xA88DC47493510430ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseBConstants = {
    0xBE1F527754C054D1ULL,
    0x73CA778E371D0828ULL,
    0x10F133CC55E5678CULL,
    0xBE1F527754C054D1ULL,
    0x73CA778E371D0828ULL,
    0x10F133CC55E5678CULL,
    0x1D0D7B33DEAE4EB9ULL,
    0xB7E0676AC984C7C8ULL,
    0x90,
    0x89,
    0x2F,
    0x73,
    0xE2,
    0xD1,
    0x8F,
    0xCB
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseCSalts = {
    {
        {
            0xEF6DD2A49970A869ULL, 0x7DACC9FF1986858CULL, 0x6B2A9A1887AEB7B5ULL, 0x00A6DE059997A307ULL, 
            0x9F750E0AE29E2238ULL, 0xBF6E928A31210046ULL, 0x4ADF0156EA161B20ULL, 0x99609E22813A9B4DULL, 
            0xA84B6B40658E1F28ULL, 0xA10B14A05033C8AFULL, 0x527BC843C514B119ULL, 0xE02DDBB3FE94168EULL, 
            0x7887DB59B6FE78B6ULL, 0x7FB1CD2977830B30ULL, 0xBF1DC28167D7B9E3ULL, 0xA00B27D62EF93A5BULL, 
            0xC790ABC64F63736EULL, 0xE1685441852C21D7ULL, 0x5A37C4CC671C9B32ULL, 0xADD8A8E122A34298ULL, 
            0xD277D6ABEC651E83ULL, 0x9F6C98B3BD78C0B7ULL, 0xE6515B6B1B5C5984ULL, 0xBD5337614EB24B9FULL, 
            0x41D531565EC90DD1ULL, 0x884E3850E39103EEULL, 0x593D6FB9EA9B8050ULL, 0xDC68F21B47678B73ULL, 
            0xCDB5BFC3BE4C754FULL, 0xABFFEC6810DE0ACFULL, 0x34A7F8E63330E873ULL, 0x52AD41500F8501EFULL
        },
        {
            0x86F12D289F21B3F2ULL, 0xF3DFF91D235B762CULL, 0xDDF11467D6360800ULL, 0xBA4CE2D34C1C6D33ULL, 
            0x1C9755CFA7AFC2D7ULL, 0xA3AEA08AB79DF09CULL, 0x6963856171BB8284ULL, 0x8E60421BA7B53E19ULL, 
            0x18A164B6A23ACFCAULL, 0x7AAD178E50E5E76FULL, 0x863C28E424C3D5ABULL, 0x68A3DA3A76963030ULL, 
            0xBFA5E7FAE775395AULL, 0x9999AD8ADD934C1CULL, 0x46380BFD247FFF57ULL, 0x0D5E28325CAFA3A0ULL, 
            0x40E8869D84A31930ULL, 0xE375EA1BDDBC92FDULL, 0xBCF61906EEC1CF79ULL, 0xADDC8D49E75E3C6DULL, 
            0xE76F369440BAFB1CULL, 0x2F5B5F6C7CB318ABULL, 0x805BEFC18DAF00C8ULL, 0xA3D80732ACE25981ULL, 
            0xC655AE9510C7E5D9ULL, 0x138849D1D2287027ULL, 0xB31E7B5ED7616701ULL, 0xBEE279886AE76664ULL, 
            0x42697A8C5ADA3CCCULL, 0x038171CC869F1DB0ULL, 0x99DB6888A3AAA45AULL, 0xC0956FAE4EAAD583ULL
        },
        {
            0x0992C884F86C3C51ULL, 0xA3B3C9E99AE42347ULL, 0x166DC4F1E84953F4ULL, 0x8C756D465F03DC47ULL, 
            0x9FE6E43422DDBD17ULL, 0xF253B28DC107C938ULL, 0xDC40F882B5AC4CA4ULL, 0x781A0BA42A44451AULL, 
            0xD921FF294CF76B9BULL, 0x23EEFF673377FA18ULL, 0x2F5F2CEBF2574517ULL, 0x185D4D634CC43077ULL, 
            0x52AA3C5876D97BA7ULL, 0x81BA607C1D18455DULL, 0x3056BEFA835591E9ULL, 0x4CF9471576BA99E4ULL, 
            0x3F9473E0F1FEEF09ULL, 0x8CB3E2300E4D8BACULL, 0xF81B88808CDCD694ULL, 0x09368DFDE6CDE739ULL, 
            0xB9CC7BD446E66940ULL, 0xF95AD81BF6B01DCDULL, 0x26DF677A5E959446ULL, 0x415884E7B735621FULL, 
            0xCC43BE063FBF849CULL, 0x187B0AC047F4976FULL, 0x4318DEB26134DD0EULL, 0xBC7840163D3B7294ULL, 
            0xE9CEF333C557943DULL, 0xF42D2182A8C9432CULL, 0xBAB69619AF13A64BULL, 0x31C5DA2EF0B96B25ULL
        },
        {
            0xD77877810BC0A715ULL, 0x32D22038A1CB7BC4ULL, 0x8A245BCFA20122F0ULL, 0x5EE987B9BA0F465CULL, 
            0x2FBD4C6A48557B20ULL, 0xF7DC346103666A21ULL, 0xA1A21C2C5E66E563ULL, 0x9C44A0B0C67FF9B1ULL, 
            0xEA3158C74484EFF6ULL, 0x0F27A25BA962C0B6ULL, 0x8F1E23246A2B68E1ULL, 0x7C63D89C117E0887ULL, 
            0x94A2AAE8202033ABULL, 0xE09BEAA860319653ULL, 0x4411D5F4546FFF8AULL, 0xFDD12A1B1CB69459ULL, 
            0x914B8164907BA503ULL, 0x0E6090A0EC48EF72ULL, 0x94801D7F34858165ULL, 0x455A677CA7EAA8EBULL, 
            0x65823AA3F0596D56ULL, 0xCBCD3F8FCAA2F627ULL, 0xF460710FE8C5618EULL, 0xD8C633FAED3CCE42ULL, 
            0x365247175CEDABACULL, 0xDB29E509C842EEBEULL, 0x0875DCCD1DE76F7AULL, 0xE203033D9168DC00ULL, 
            0x51B6587BD8D8F181ULL, 0x93CA5167C622F26DULL, 0x62947F02724D1DF6ULL, 0xE9BAC085FEC731D8ULL
        },
        {
            0xFE492B717739C665ULL, 0x865D4EF6C0D8040BULL, 0x7BA563D40264FF14ULL, 0xAFC08915C6A77B35ULL, 
            0x1325C793A363E4BDULL, 0x742F3F7DC3FCD387ULL, 0x909E0C500CBA828DULL, 0xA3F062BEE0DC2B5AULL, 
            0x7497607FEEB38D9EULL, 0x33D5A82F17A65D99ULL, 0xFF95873BDF1FD3F6ULL, 0xE15B6BAAA537D25CULL, 
            0x74B83CAD82225F6DULL, 0x552C9BF8C70FC8CBULL, 0x05ED61997B8B5F5CULL, 0xABB4BAA56771CE5FULL, 
            0x1ADAD63B8CD7F960ULL, 0x6D7877AEEBDFE685ULL, 0x485E5DB12379B650ULL, 0x782CAEF902B6839EULL, 
            0xD73F1B895FFB9E50ULL, 0x169CF1377CECF5F1ULL, 0x36830AF7C338FF71ULL, 0x0CBEA54C06272605ULL, 
            0xAF44267AB5AAC926ULL, 0xC79FE6CAAC58ED40ULL, 0x107BD6054CF8F200ULL, 0x5648C0C4A0224B70ULL, 
            0xFEC2C9450FB55065ULL, 0x40CFFED6DCC5C914ULL, 0x4365E3A3CC825737ULL, 0xF8965819739C1198ULL
        },
        {
            0xBF234EC21DFA3143ULL, 0xB5DC21CA62B60C96ULL, 0x28031513817F053AULL, 0x83A22C3728FC2915ULL, 
            0x9BFA1F1D5DB8083FULL, 0x8036D07114E93EC8ULL, 0xE3725285BAAF2A4EULL, 0x0E2C55929C9FD3E2ULL, 
            0x73665CD9D0762A63ULL, 0x421F50B9BEEDA8F0ULL, 0x7BE92D8DC7B6B524ULL, 0x7E3DA3A0D9BAD508ULL, 
            0x4D1CEB5FE7EE5E76ULL, 0x3C2F82E27B6D5C66ULL, 0x104D50B967F733C3ULL, 0xBBDF61642B6D261EULL, 
            0x1D06627C21AF2B77ULL, 0x0F1CD2DFB83A6850ULL, 0x394CACBCA01CE047ULL, 0x661485904AB47CEDULL, 
            0xA3BF2748C14089E0ULL, 0xDB6A3CA57C0209FBULL, 0x4C48C46A23AFFC54ULL, 0x02D10D086434F508ULL, 
            0x01122425BF3A7B0CULL, 0x3F9347AFC1E0A863ULL, 0x1C58339F516F4FD4ULL, 0x54BDB44B40120CD0ULL, 
            0x4B3ED1B7DAFFA3F7ULL, 0xD2C9C539682FA8EDULL, 0x31895B39D82A0236ULL, 0x0433986D89C61C38ULL
        }
    },
    {
        {
            0x27DA280695E3936CULL, 0x618DFA0A64915CB1ULL, 0x81A30D82F804BB45ULL, 0x6E36711CC39386E0ULL, 
            0xA4CDD4C7892BF1D7ULL, 0xDF0BEE13F0C908C1ULL, 0x8BF41A4B562BEF92ULL, 0x05FA915F49D27E64ULL, 
            0x995C770DA61A450AULL, 0xDF4D179EAD36D538ULL, 0xECD89C1258C6156AULL, 0x26BBE410CF4E0303ULL, 
            0x23B157F09496B529ULL, 0x48C67EAD365B3E1FULL, 0x2F001A71AEDDECEEULL, 0x7B5691B721CBAD97ULL, 
            0xA990DBBB2D4E894BULL, 0xA8E60606FAA14583ULL, 0x2816A1C9037A5000ULL, 0xF0832B32AAE074ACULL, 
            0xA95433EBCE8A0C3CULL, 0x35FDE3D924318FB5ULL, 0x51B061057F2AEB49ULL, 0xB3AD478FDAD9DFBBULL, 
            0xD643C6AA62D67DEDULL, 0x7E98F42D2F12BEE0ULL, 0x66C302344BA3621EULL, 0x31002A8389DB0457ULL, 
            0x9FC763428BD832EFULL, 0x013F42DB3DCC6CCCULL, 0x61AE4E291884DEB7ULL, 0xA4AF382B0B99E496ULL
        },
        {
            0xF2B34053EE0A5F3DULL, 0x71F18C5B8D35E878ULL, 0x4B81A8B203AD56BBULL, 0x49E25F30776460AFULL, 
            0x6E68254779708A49ULL, 0x3A88DDBD3BC9D4E0ULL, 0x396A8F798CE410C7ULL, 0x2F7BEB1E67AB60B8ULL, 
            0x7702378D563BDB3CULL, 0xBB0617F1987046D4ULL, 0x593EEA645D9B4C0BULL, 0xF2A1A25B36EAE3C5ULL, 
            0x07A6BE2464C70D46ULL, 0x9AAE2EACC85930FBULL, 0x371015B983AF14D4ULL, 0x8CBCAC423479EB69ULL, 
            0x80448FD51A6FD777ULL, 0x7FFA4A3B11D401CAULL, 0x301B9BD132B987B6ULL, 0x088D201C7858486CULL, 
            0xEEDF5581A292D3D7ULL, 0xB991025E28E9535CULL, 0x7A417709CA8EBA51ULL, 0xE4D180B3AAB04A75ULL, 
            0x58952A59846D6531ULL, 0x1666C42221E7DC9EULL, 0x6E40FE0DFC2F5C65ULL, 0xF8BE7D41F94B72B4ULL, 
            0x3157691CB2A32B20ULL, 0x0C5D7C7FA5FE54D6ULL, 0xB7E43B9E48816FCEULL, 0x2923DC3F3A1B736AULL
        },
        {
            0xCCD1FE7C6A341A44ULL, 0x78F0F6FE5647BA86ULL, 0xE924831DFCDE4FB1ULL, 0x8ACAF7F191357805ULL, 
            0x7A5AB4B57D8116A3ULL, 0x71C3F3A7D081E56BULL, 0x431BFE4C2775408BULL, 0xF090B54A9288164DULL, 
            0x14FFEA7144BBF34AULL, 0xEF29233000B6ED41ULL, 0x2C596B2FC0E7205BULL, 0xA4B72B7D65B67E2EULL, 
            0xD2359A58140F6F2AULL, 0x4484BF0EEFA94C45ULL, 0x78A9CCF4810DA850ULL, 0x9259461442FC4F7AULL, 
            0x8DBA29738F8B0EF0ULL, 0x19A2FAD3B7F46344ULL, 0xC98087113F3561CAULL, 0x3CA71B18631FA9E6ULL, 
            0x90B58AA6EE171A08ULL, 0x8A84ACDD7A7FCA20ULL, 0x9CC1F35B3E96DBE1ULL, 0xD9B8ACBEA24E3A12ULL, 
            0xA9A78D9958C67489ULL, 0x46C2A309D70575D8ULL, 0x5A8D1D9A081D7B1BULL, 0x87E9D9E0D301F7D5ULL, 
            0x3FE3276E6C1EEB3BULL, 0x47935393647850DDULL, 0x40BDAC2A1B0499DDULL, 0x8B14D71E1B4C3479ULL
        },
        {
            0xF32C72C34E6A1372ULL, 0x23E97A4DCEF489C2ULL, 0x44416A6DDE906F8BULL, 0x5836324AA2685348ULL, 
            0xDB1AA3524B9D75B9ULL, 0xC21FED858199184BULL, 0xDE797F3440F8440CULL, 0xB5B5F36F6201C7AFULL, 
            0x8BB8593328724F65ULL, 0xBA6E0FEC01EEFF2FULL, 0xCCE2707926D93330ULL, 0x60AF97C3B60597E3ULL, 
            0xFF20B2B292571F17ULL, 0xDBCD2BB746A2B7A9ULL, 0x563C0554288E07C6ULL, 0xB9291AD645CE88F3ULL, 
            0x8A9CC478B7006846ULL, 0x61AFB297F53E352CULL, 0xB4C2B2AC5AD4A65EULL, 0xD5A2306137C8F96DULL, 
            0xBDB939A409359D03ULL, 0xAC6A3BFA4775AA57ULL, 0x6C13FBC1F11A430CULL, 0xDA50ACDC3D2820A7ULL, 
            0xEA34F4466BD55FD1ULL, 0x1553DF0ADC12A07DULL, 0x465CD6FA6E9A6695ULL, 0xFD67A2607915DEB3ULL, 
            0xD1BA39CEF1E0208DULL, 0xC835AE85590E6432ULL, 0x3F980B93A954C8D5ULL, 0x8CFC2ABDF86AB37EULL
        },
        {
            0x18E76C6D25D844C3ULL, 0x83491B1D1B9624F5ULL, 0xC4820EA2866BA0B0ULL, 0x733938031563AA26ULL, 
            0xD6D5CD4B6FC4C0D5ULL, 0xF9111E6808D6D046ULL, 0x40CEAA2F91C8498BULL, 0xE4F0914CBDBC294DULL, 
            0xF51E4AE260D10C2DULL, 0xC17BCCD1B165ED8AULL, 0x11B3F90E1B775933ULL, 0x764870D1B6BFC6CCULL, 
            0x61B218016773382FULL, 0x2C94650F3FE105ACULL, 0xE1910FC99C398B28ULL, 0x29D1BF52D0B03237ULL, 
            0xA4BB60096B9704BDULL, 0xBD5CF971599FF971ULL, 0xAA3933063B62D977ULL, 0xE7C0916E3F4AB183ULL, 
            0x4FF12D562C945C87ULL, 0xE07F4668D6C3533DULL, 0x734602D81F3F9AB6ULL, 0xC5FEA71778C011BCULL, 
            0x7AA9DF09874149BFULL, 0x2AE7DEF2ED9B5D7DULL, 0x4DCE22C4B4A1EBFFULL, 0x746C9EFE52B0D4E3ULL, 
            0x7194181410BC10DAULL, 0x3618F534594392F9ULL, 0x9AA1A1B526658F4FULL, 0xF4B1C120F6B839ECULL
        },
        {
            0x1C32D0407F1C379DULL, 0x68EC5F0BE95367BCULL, 0x531E0426C36A2CE0ULL, 0x3A9D8135CFBC172AULL, 
            0xB95515199C6B8CFAULL, 0x27FB76BD459951F5ULL, 0xB292C6214C977536ULL, 0x93726C009B21283BULL, 
            0xD71E4021B00DCDEBULL, 0x18DC52C80942F728ULL, 0x92D1FE5602A8DB5BULL, 0xBCDD91D35B1EE03DULL, 
            0x6C95486D2242BA13ULL, 0xF8E2C079AA6A99BFULL, 0x68D77C9AD16EF7A1ULL, 0x3A1DEA311115E6DEULL, 
            0xF184AAE667D026D2ULL, 0xC4DF89587B4A5082ULL, 0x04E91E00F1CDA9D2ULL, 0xDBF438E05B681737ULL, 
            0x97FF98C1B09237E2ULL, 0x65FE75B2A1F25389ULL, 0x460D706F18C8BF18ULL, 0x4C525715C5065777ULL, 
            0x6C9686FEC4BEBE69ULL, 0x54ACBD7534A85ABBULL, 0x332D46D3BFEDA6A6ULL, 0xFEF74B881B252260ULL, 
            0x67B6B24AE0D96BC5ULL, 0xB0C3D8224C6E5E7DULL, 0xDD974780C6AD26BFULL, 0x14214A07675E0835ULL
        }
    },
    {
        {
            0x2F2CB2A0FC81DD0CULL, 0xC9F9D0B3D75F4DA5ULL, 0x03DF07AA25FE3872ULL, 0x3CFDF329E54722B6ULL, 
            0x999C9B1894E3E82BULL, 0x2EBE57F5A4DD475BULL, 0xAFA2EC3CA27FC907ULL, 0x21FE14E63C6EE13CULL, 
            0x2284900CE8C11778ULL, 0x299CE174594F215FULL, 0x1C3F0E08B0136560ULL, 0x15C4A9E1F765902BULL, 
            0x62188CEDA9D029C7ULL, 0x9B944F11F69EF596ULL, 0x72012B2498FC3D05ULL, 0x902E330320FF0DC8ULL, 
            0xBA0464F1F069C0BDULL, 0x0AE3E15940DCA8AFULL, 0xBBDA4F9112CF75E2ULL, 0x349CE32FD9908E38ULL, 
            0x83B46986301B199EULL, 0x17064563C5FCDD76ULL, 0x85D4275CD3DDBE5DULL, 0x4A5433C01ADE7AD9ULL, 
            0xAFAB9FC96B18A7C2ULL, 0x0821EA5808E1F53EULL, 0x87F7164A56532BFFULL, 0x30606F1525609475ULL, 
            0xB39BEA198A349BD9ULL, 0x89C19343409E55ABULL, 0x249DD094AE5D4AADULL, 0x498DE3269F488DD8ULL
        },
        {
            0x79C410AFE776BAB2ULL, 0x05F093ADC78186A2ULL, 0x515F01847F0D9584ULL, 0x32CAAF411740F950ULL, 
            0x8F55EFEDE24C0D1CULL, 0xA38A624C50B94382ULL, 0x3F3CDF78CE639CFCULL, 0xCABDB406E7628293ULL, 
            0xF855251E7767F0A1ULL, 0xCC54DC43F0DD3E2BULL, 0x31F182664200C1D7ULL, 0x1B44C6DDE934D238ULL, 
            0x7B8DFC1464DF8FC1ULL, 0x77E05A54B0B3CCD5ULL, 0x7028BFC58D725493ULL, 0x61B94633353F158AULL, 
            0x8AC2EB88758731B5ULL, 0xF258C65F66EB199FULL, 0x598BC89843CD7BFEULL, 0x57C292871BA1D743ULL, 
            0xD7136AD4EFAEE141ULL, 0x719D5C002E5313D6ULL, 0x0640F8EEF8C0A056ULL, 0x51FCD289AECC8F64ULL, 
            0x04BF3FF5DD8D7CEDULL, 0x858E19C8A15B458AULL, 0x1D79CA52161EC0A4ULL, 0x81757DEAA15AB33EULL, 
            0xC27283C69C4B5DF6ULL, 0xBF666FA45062156AULL, 0xB142802579A8CD80ULL, 0x0FB31FDE0FA29258ULL
        },
        {
            0x1715396705A9F23FULL, 0x5FE0FCE6F318E2BCULL, 0x6835CA12A6C1F291ULL, 0xCA3200A59D360802ULL, 
            0x28EDE3D298544935ULL, 0x19710AD740F9B769ULL, 0xAB3066C9776B4BC8ULL, 0x82D66978B5C163EFULL, 
            0x7614E05E7AB2B934ULL, 0x539160AF2A53BBBBULL, 0x9D55FE9B46D696E8ULL, 0xFEC7A3DD49F6F29FULL, 
            0x3D79F675BE000599ULL, 0x91AB43F8230E0620ULL, 0xFC05A5B424C073A0ULL, 0xB5A0A7B2E736E1B6ULL, 
            0xE85CDAD2550720D9ULL, 0xFFB6BBFA1011D417ULL, 0x0025478375BC4648ULL, 0xE92AC80D9CC3A8C1ULL, 
            0x8D3ECAF83C747B29ULL, 0xD97B958DC5385AB8ULL, 0xB4B4525B50C61243ULL, 0x0828737E24CDE4EAULL, 
            0xD6E5CCB86993AFB6ULL, 0x86A8A9DCA347621CULL, 0x56961451ED76AAC2ULL, 0x8EC127C74E3D2824ULL, 
            0xAD66AFFCE068F919ULL, 0x350CEB2384C45733ULL, 0x02767D0096FF0505ULL, 0x578E43045F66BC91ULL
        },
        {
            0x586417A2C9A189DCULL, 0x28E3C83E44C56378ULL, 0xFB45B6EEC37BB7D7ULL, 0xDCA6B7B39C001F86ULL, 
            0xBB418DF49C467443ULL, 0x1864DDB44DEBA3B1ULL, 0x72516B848A3B7205ULL, 0x2A2ADB7252AE3550ULL, 
            0xB84F3A38C075920DULL, 0x33032AF583F4082CULL, 0x2823046C14CD9E87ULL, 0xDB8225EF761E824CULL, 
            0xAD400A0FF83AE1CFULL, 0xAB28C38026591B4BULL, 0xF1CF921EC82B71F8ULL, 0x245498B8616A14D1ULL, 
            0x3264BB22B36CEC5DULL, 0x58468F094D48E0F7ULL, 0xF92C6D38C70EB7D7ULL, 0xD2E4AA7A5B1A1896ULL, 
            0x6EDCC5CCB6622A5AULL, 0xD39E2BDF0CF345A6ULL, 0xCCCB59657BA259C7ULL, 0xF3113E1B0B86C57CULL, 
            0xEE579810ED294B28ULL, 0x43E0E12B42E38DB8ULL, 0xE188CE2EA9B53570ULL, 0x261BA5697A1DAFCAULL, 
            0xE94EFFA27D378E00ULL, 0x72CDB86FE74D6B39ULL, 0x8DBD54A8554C3471ULL, 0xAEB35706F8C6487DULL
        },
        {
            0xF4F2DA4BC922615BULL, 0x3B2F4529A9CCDEC9ULL, 0x97761A233DF52BE5ULL, 0x95A40EEFA0014485ULL, 
            0x2AC68714968BF6F1ULL, 0x5508500189FB158BULL, 0x6EEEA8B27E6A8733ULL, 0x81076E9B54B5AFE3ULL, 
            0x56A0CD36437BAF5EULL, 0x578AB7C2403A5328ULL, 0x78DA27FBD0D1B3E6ULL, 0xBCF4AF285A636956ULL, 
            0xF247DC5A6756A449ULL, 0x7D06AB82C5F8316BULL, 0x86F0969F409B6615ULL, 0xA9D7EAE8A88DE773ULL, 
            0x74281EE0C821CD7CULL, 0xB549A875A6E33726ULL, 0xDBA0EECFE3AB9344ULL, 0x74F77CC76044BE3DULL, 
            0x25F7533866AECDC9ULL, 0x9F570CE321220629ULL, 0x4CDBEA1F8A696A87ULL, 0x488835C09AC2A278ULL, 
            0x812AD32D2C69100AULL, 0x274642B5EC007382ULL, 0x05DA51CED0F09679ULL, 0xD5993011194F5B5AULL, 
            0x6B9519D0B3F87884ULL, 0x306C1E4C64E82940ULL, 0x88527868778906B9ULL, 0x8ECF948529171810ULL
        },
        {
            0xCC8EF963E297104CULL, 0x38ABB2875FDB6609ULL, 0x9CEABA8534114C9EULL, 0x0063782A0BD4C7B0ULL, 
            0x0FFB99E8F7E21C32ULL, 0xCE051F27EFA968ADULL, 0x9168E379DADA4A9FULL, 0x3BA03C41492F97AAULL, 
            0xD033A753F6CC30ACULL, 0xBCD7D787132E7BF9ULL, 0xAA698D343BF2CB2DULL, 0x06752E9BDC99FDBEULL, 
            0xF5288AAE92E7D7C5ULL, 0x7D57937FBE21BBF8ULL, 0xDD11500383CC1B4CULL, 0x5E539EDE81573E93ULL, 
            0xC93FCDEF8809A6C0ULL, 0x480DE90468D45BE5ULL, 0xD934460F3FA72427ULL, 0x97F11CDD5C957A08ULL, 
            0x07767AF413F562A4ULL, 0x4C451EEF4754E202ULL, 0x9FBDE839C00B103BULL, 0x47A699FD845BD24FULL, 
            0x3B54F004BFD3BF8EULL, 0xA4BABF2D7DB41989ULL, 0xDDDF8F230DCBE0B5ULL, 0xFABE238B8BACE384ULL, 
            0x11ACA6D8A8556238ULL, 0xC6E0E74F8D7D31C0ULL, 0xD9E1C36477963A2EULL, 0xF3A81344F5A98782ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseCConstants = {
    0xB7673C5C576A8293ULL,
    0x9CFC7A30023C38BDULL,
    0x1E79CD58B36D602CULL,
    0xB7673C5C576A8293ULL,
    0x9CFC7A30023C38BDULL,
    0x1E79CD58B36D602CULL,
    0xD61BBA05240948E8ULL,
    0x8B7EACB8D6C63ACBULL,
    0x5E,
    0x70,
    0xF5,
    0x13,
    0xE1,
    0xEC,
    0x37,
    0x4C
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseDSalts = {
    {
        {
            0xE15D3819BF08A977ULL, 0x89B67A9C5FCCE1E7ULL, 0x070105D9ABFF3E6AULL, 0x0D5EB30F83BB0926ULL, 
            0xFBCE36431CA94419ULL, 0x8D5DD6FCBDAF74FEULL, 0xD79C138DEE10173DULL, 0xEA0D34A151E96268ULL, 
            0xC48331DD0F9A7E1AULL, 0x158EB1545338468AULL, 0x9737B5C992508D0AULL, 0x895AEF3F90D3B3BEULL, 
            0x6F0916C244EA5274ULL, 0x56BE29DBC4C123F9ULL, 0x8B52E15630A4DC1EULL, 0xDC1978B0F6F48A3AULL, 
            0xAD0A014EA75EB5F4ULL, 0xA669FC7A6DFBB528ULL, 0x400125E5B9AB74C0ULL, 0x790CB4E782C47195ULL, 
            0xB618C6A3282E5D35ULL, 0xAC676893A32CFA35ULL, 0x583A25E8B6EAF941ULL, 0x0E63520A3323AFC5ULL, 
            0xCB2C49292CAB390BULL, 0xFA2BF1874C4EBB12ULL, 0x575CDE24577911F0ULL, 0x5A04C1D2716438EBULL, 
            0x2ED08A6B1B35BCE0ULL, 0x5A24FC3DAA42354CULL, 0xF560C97710A1D28AULL, 0x0DBA4D4811EF052CULL
        },
        {
            0x87B809CA37BF9064ULL, 0x1AB6C354D510875FULL, 0x2D47147EBD6A566CULL, 0x370CD6DD39517282ULL, 
            0xD590AC3002647993ULL, 0x2946EAF4662BDFA7ULL, 0xA24EDFD6BED016B8ULL, 0x4A5230165404192EULL, 
            0x1ECBEFF5BC7E1137ULL, 0x77258544BC77BAABULL, 0x53C94104EFCEC78FULL, 0xBE064EB7A6CE9418ULL, 
            0xB0CBBA041E012B85ULL, 0xD88907E63FAC575AULL, 0x57F8C63BFFC51AD1ULL, 0x5E27238807015DC8ULL, 
            0xC9F03B40F74B3EACULL, 0x7C1800E0A4D8E5B0ULL, 0x30021D8904620144ULL, 0x6BF2027EFDD88E9EULL, 
            0x4C104F6227F5D938ULL, 0x3EA387D2E0500D43ULL, 0x75C31FD9FFD1E487ULL, 0xF9BD070D3F263D7EULL, 
            0xA08C1695970EA88FULL, 0x76F59F5176208EF1ULL, 0x89D969DF2E810C3AULL, 0xE13EE75BA601A6CEULL, 
            0x3EB2736C29BE4E6CULL, 0x680126727AFF4E70ULL, 0xCA8ED9C2D6547B77ULL, 0xD99D7B37CEFC00F5ULL
        },
        {
            0xCD713553284B03B1ULL, 0xDF03AD5FE6140F4CULL, 0x3FE31DB8C0138388ULL, 0x687489B50D0EEB00ULL, 
            0xCF31B1E0438F0D7BULL, 0x91A38F0B9E0ED4FBULL, 0x41F30DE5543A6710ULL, 0xB1BABABD6AA0A9BCULL, 
            0x3CFDDFEB5B3DFD46ULL, 0x07A30999CA6ADEACULL, 0x2B9EEA31F9C985C1ULL, 0x76FEE4B54A7AD5D2ULL, 
            0xB42603910828F83FULL, 0xD4A516B8DB48B553ULL, 0xC42D7ECEFA52A1ACULL, 0x080DEED22A9541F3ULL, 
            0xB7909894030D0DD5ULL, 0x97F2E1B84DC04CB7ULL, 0x674FD9E839F40A03ULL, 0x07ED5300598C99EFULL, 
            0xA5DEFFFD79CCAEE7ULL, 0xF505F05201D3FD2CULL, 0x90304E6D0008F860ULL, 0xD4FE2BBCEE2C3985ULL, 
            0x28468FEB0BAC62ABULL, 0x1AA7CF214AE27205ULL, 0xA055CC52E8084927ULL, 0xC98C38E447DB8698ULL, 
            0xD7DC418786AABD53ULL, 0xD1E6AC4835D720A6ULL, 0x1416E0EC0F79A9F9ULL, 0x1114BE472AC95B0DULL
        },
        {
            0xE0A9F341A5F8FE23ULL, 0xF2C0FE2EC1914F9AULL, 0x7D96600EE387C016ULL, 0x481FA51DB4A6F65CULL, 
            0x9FF78FBBFA61FC38ULL, 0x45FC6F961DABCBA8ULL, 0x52AAE92CC9F2D578ULL, 0x5BD688D87321CDC4ULL, 
            0xEA78E061EF223000ULL, 0x8C8F2B034D42AC86ULL, 0x9A787B4D6B90C076ULL, 0x14D1A0E0DD4C32BCULL, 
            0xA776F3C133FCF4D9ULL, 0x56E7770EDEA59474ULL, 0xF939957A82987A91ULL, 0x382BA8774A05E5D2ULL, 
            0xF1FA7DA98B189901ULL, 0xEE23C8F9DF7F693EULL, 0x988655E581BB85D7ULL, 0x7255916EB31C2D6AULL, 
            0xA990BF3608D15E9AULL, 0x470C420BDB37D912ULL, 0x0E6DFEC22BD51E19ULL, 0x47FE77A31E65A484ULL, 
            0x5F18D0D48DA7B877ULL, 0xA0A43D1A38184831ULL, 0x7DB22632A85B38E7ULL, 0xB2B91796511B62F3ULL, 
            0xA41366F04EAFDF93ULL, 0x9B6B07BB8CC72FEBULL, 0xB48547640F2587E9ULL, 0xF3C98D660E1F44B6ULL
        },
        {
            0x3609FA07235E4F20ULL, 0xE1D507FE36CA4646ULL, 0xB3930DC3A842205BULL, 0x1F85C626FBF415E1ULL, 
            0x1C34DF829F868051ULL, 0x4C0F78A853C23AF5ULL, 0x5E3CDA79D2DEB212ULL, 0xC6B02B221C4D3C2CULL, 
            0x164DCD5607C9FF23ULL, 0x2683135C88A585B2ULL, 0x2B2E6D8B3343BF3DULL, 0x6044D031EDE3D9FBULL, 
            0x196A513C3077C5E8ULL, 0x22592C3A48F02A2FULL, 0x2C9BD388AD8AA5A1ULL, 0x4412D2EBED5DAAD4ULL, 
            0x228216AA66F33057ULL, 0xF3C0AB9E0A7BDECCULL, 0x2040217B11547A37ULL, 0xEDED3840FF331847ULL, 
            0x3D2B1A04E45DE916ULL, 0xC25139E16EB7E1DBULL, 0x2DCCE5CE10329E18ULL, 0x0064823926EC59BEULL, 
            0xE3EF7BEB82730961ULL, 0x66396C302E41FAAFULL, 0xFF3852E4465ADDEAULL, 0xA6F57B2993F97766ULL, 
            0xEC168E3A7C545258ULL, 0x0B3C6B93043AA3EAULL, 0xABDD4F2339C9AD19ULL, 0xCABD69EA331ADF09ULL
        },
        {
            0x8C12EB1B6AFABAEBULL, 0x1293DD5B8F5DC9E7ULL, 0x8E74526DA1B74EF4ULL, 0x94AECB3D4D259027ULL, 
            0x99058B58A260373CULL, 0x55829EB7A08DB6B2ULL, 0x6C503D3023D1C6D1ULL, 0x46BBB390C1F25E14ULL, 
            0x7E2A40440A3FEA79ULL, 0x998503B99D24C4C5ULL, 0xA65158CD808131F6ULL, 0x20716970C5DF48A7ULL, 
            0x0A40FF1320BF62B8ULL, 0xD2876F865E6B36DDULL, 0x56DF567D4927F412ULL, 0xBD372B9BF2D0A464ULL, 
            0x48D840B3A66AC8B2ULL, 0xF3E7697BFBF71B70ULL, 0xA3BB2303F8034535ULL, 0x2EBF81FA3C81D984ULL, 
            0xC8FDE68D66705510ULL, 0x70599CD80200875AULL, 0xC760F9C7E5203E4FULL, 0x6F0307A2DBA284A9ULL, 
            0xE3897C568CB311CAULL, 0x4A57368BD2128384ULL, 0x5E7B92BDC1D90A7BULL, 0x139318FEF76332F7ULL, 
            0x432A97318FC720AAULL, 0x19961CE10E777F73ULL, 0x6ADFD4D6AD68FBA6ULL, 0xE87B84B8DEE37314ULL
        }
    },
    {
        {
            0x02C4DD8B66F27737ULL, 0x759F2A7418B24D60ULL, 0x8A19A891DA78D8D3ULL, 0xBE0FBE07CF9DB46AULL, 
            0x4E8DE3CF2CAC3FCDULL, 0xF526D8467BE34D51ULL, 0x3C968B277BB44FFBULL, 0x22CB52F2BC52EFCBULL, 
            0x4E5E3D907FBB228FULL, 0x68B984DB108E03FAULL, 0xCF9C6D4C6113E754ULL, 0x87C3169FC737D984ULL, 
            0x346607180EBBBCBAULL, 0x395E57BF3BBBF16EULL, 0x67A3E802CF387F3AULL, 0x3A07D2745C5DEE08ULL, 
            0x2C773B85C04AE214ULL, 0xC26478886719A57DULL, 0xB265CB0688301733ULL, 0x5FF6BFF3EE83E6CEULL, 
            0xF3010B9FEA21A008ULL, 0xE169D290DC99070DULL, 0x88CC836D271C82CCULL, 0x4EC6B5F0CA2E96C3ULL, 
            0x11EA1B56C1631308ULL, 0x1439825B9434964CULL, 0xC81C417CD1BADE97ULL, 0x0B4D751C174CA9D8ULL, 
            0xFAE0C70E2DC95D08ULL, 0xDC8781A8DB6126E5ULL, 0x9C2B1EF643F3BB30ULL, 0xE068A3A451DD0CB3ULL
        },
        {
            0x43ABE174302A8E27ULL, 0xB91CF6321DBF4707ULL, 0xFC4F863C3454DFA7ULL, 0x4842AB9243EC2EAAULL, 
            0xC0994D2344443472ULL, 0xFE1443DA094316E6ULL, 0x8C266CFE69B1CF65ULL, 0x314F438DDC4D5804ULL, 
            0x0541FF220BE52E81ULL, 0xDBFC4DCEAA59E376ULL, 0xD994BAECD2097EC1ULL, 0x58A28821FBEE8476ULL, 
            0x2A8CB25701D84ED4ULL, 0xA8AE3057CE66B347ULL, 0x44C3FCA5B70A243EULL, 0xB9FBEF303BD40429ULL, 
            0x1C89D304EA7590E3ULL, 0xA905264192025628ULL, 0x66FEDB5BF628E95BULL, 0x7DDD16E967C0CA80ULL, 
            0xC27CF29A4F549F78ULL, 0x064642FB5223312EULL, 0xB11EF7C57468A490ULL, 0x6DD796714601CFAFULL, 
            0x6DA30C9A4C7537C3ULL, 0x57EA8D2C062CA0F5ULL, 0xC74F90445BB93CACULL, 0xE1AD8EF02BBAF6F6ULL, 
            0x8E1572E443DF06BAULL, 0xBA3C39807B3F65BEULL, 0x4FD0445F25F1AA04ULL, 0x40898C447856D62BULL
        },
        {
            0xCBF7F94134612F09ULL, 0x26EBACAB5C0FEB18ULL, 0x7E8B94D7F82E0A44ULL, 0x4314ECD5A2262EC4ULL, 
            0xC342C8C8F18A0987ULL, 0x7B0FBEF4FAF9851BULL, 0x569D9F5819BEA387ULL, 0x6D2E4C384C2F545EULL, 
            0x1528759DF7B9F3BEULL, 0xE8139826FD228AC7ULL, 0x36896E596ABC3E1AULL, 0x9AEDCC6F0BF76E9AULL, 
            0xA31CF09E6A10EAADULL, 0x1F7361694C0AA304ULL, 0x3C8728A95CC13374ULL, 0xEA50A963A4F2030AULL, 
            0x408A8B5FBADB36F9ULL, 0x6FBEBCB240F5E7CCULL, 0xFAA3AF33421BC036ULL, 0x3F58C23389A240E7ULL, 
            0x766B292FF1356500ULL, 0x076D46E010B85110ULL, 0xDE48DE672AC94925ULL, 0x028BC2C94DE04AF9ULL, 
            0x73A35AB1F0B83276ULL, 0x011048279DF01B53ULL, 0x9CEF2D5D90D317A5ULL, 0xFA46912A1D921384ULL, 
            0x3431FAA7FD2CECB9ULL, 0x6B5672204E23E2D9ULL, 0xF78B84B0B6C5B234ULL, 0xF5B62B7D92C6AA0BULL
        },
        {
            0x00DD96C6F06C48F3ULL, 0xD60C1CA89569F257ULL, 0xAA05D1EF4892FB0DULL, 0x0AEF6A9CAE949A5FULL, 
            0xEF2B7002EB1B709AULL, 0x93F0189FA885BCC5ULL, 0xD0729C4F2B8D0CD0ULL, 0x22303E66FB44263DULL, 
            0x8F9CA3DFDEB3924DULL, 0x88A1C0BA86C6027CULL, 0x02F8BA9305CC1353ULL, 0x89902C5996E2B3D3ULL, 
            0xDFA1DE467AC854CEULL, 0x29CA9AE0D66E8049ULL, 0xF9FC124F38835087ULL, 0x34E27D8C86267759ULL, 
            0x04F874A00BD5E9E6ULL, 0x24C3A2B5E901111EULL, 0x39F6145EFFD4216FULL, 0x12D8258051AF9AB8ULL, 
            0xF636FF258850108BULL, 0x75E5DEE38959B2C0ULL, 0x7AE4DA246312E09BULL, 0xB69745AC1C450084ULL, 
            0x8892A6B0F6EF5D33ULL, 0xB1AFB7D8AC75ABB8ULL, 0x915A6E4A7A4536F9ULL, 0x1FCD67D7CC934E2EULL, 
            0x73CAA2EA2CAD4871ULL, 0xF52C6E1A94E8E8AAULL, 0xBBA1B3C304CC632BULL, 0x8C8F3CA0824B5B05ULL
        },
        {
            0x800017DC9CBDE405ULL, 0xA59E83B1A19F0B55ULL, 0xE664A84ABF785303ULL, 0x550293748F33ED07ULL, 
            0x9D3F0CBD30D01568ULL, 0x5454BAB64FC87414ULL, 0x714101CF7550CFC3ULL, 0xD2DF3786C6509838ULL, 
            0x16B09BBC664B9CC9ULL, 0xD69EEA2D7BB0F0C1ULL, 0x23BDC5EF196D4847ULL, 0x371321FD8CC631BAULL, 
            0x70FBAFE9111BF38AULL, 0x2A1C28779640BC67ULL, 0xC907B0706CFAEB53ULL, 0x9535CE487AF688D7ULL, 
            0xD02E24E6673B71E2ULL, 0x6F5B4CD70BEA07A0ULL, 0x5943AE023CE2F74BULL, 0xF01F6E0CFD5289BCULL, 
            0xC67CD1A6B00A2E17ULL, 0x209127864FA53DADULL, 0xE90258C5C79FED2CULL, 0xA8176C754DA874BFULL, 
            0x17B489B31005C5E3ULL, 0x533BC025E260B598ULL, 0x456400B434C470DAULL, 0x9CE1C929F784AB7DULL, 
            0x0C28EB99F0F47504ULL, 0x20391CA2BA0E7F27ULL, 0x2B8A7D850BAD2129ULL, 0x67B48437A55AA094ULL
        },
        {
            0x8D673DC688CFB295ULL, 0xBFCF32F89B345A13ULL, 0x4A4DE61F0F77C1C0ULL, 0xE5F6832DE83CF56AULL, 
            0xC042AC7D7F4845D8ULL, 0x3FCFFE81C0E95D0EULL, 0xBA724277D364F3A7ULL, 0x57FF98D8D97D2C26ULL, 
            0xCC075DD1BF52176CULL, 0xB7051563D5FEDCC8ULL, 0xC8E7382CF926EF1BULL, 0x896662B47532ADF3ULL, 
            0xF4DAD36358D1EA4FULL, 0x8A49B2534DD49156ULL, 0xF5355A8523501E83ULL, 0xFFDA1C0996432C66ULL, 
            0x2B4421DCCCFD9E1DULL, 0x9177C43E2E6060C3ULL, 0xB4C0A9B6768575BBULL, 0xA39861B5FA080B9FULL, 
            0x1B13CC1CDC2EF1E5ULL, 0x08B464F32C7A531AULL, 0xD612C714D7C70184ULL, 0x451DE720ADB93119ULL, 
            0x1BF1E4AF07CEBCECULL, 0x262364AC84423FE8ULL, 0x45B7D3C34F16FA45ULL, 0xEC8D06188A61F5F7ULL, 
            0x3361DC85F8D3A7A9ULL, 0xB2E1A5843FF76AF3ULL, 0x1E36F7FCF1F6665EULL, 0xB483EC26BE0C58EEULL
        }
    },
    {
        {
            0xC2A704A0F525B5A7ULL, 0xBABA9511EFB5639FULL, 0x5AD582DA82DAD93AULL, 0x597818019EBC56BAULL, 
            0x26FD182AA56AAE2BULL, 0x31F5DE7B8720F138ULL, 0xF9A566E6489B9BE8ULL, 0x3F133E62B0070A29ULL, 
            0x03FBFDFA5749F634ULL, 0xC3D358E077A050F0ULL, 0x9E998C9F642B4808ULL, 0x6DFF69EDE0455E15ULL, 
            0x3D21DBA6A643881CULL, 0x2723F4F5AB967374ULL, 0x7A82E4A1592673DAULL, 0xC1BA09FE8FD8CA41ULL, 
            0xD9843CDF25638AD4ULL, 0x83BCE8E01DAA47A1ULL, 0x52D968B1D5EE1E5AULL, 0xB4D9BF2BD2F96CB2ULL, 
            0x5C4034D183BD226DULL, 0xDA5E6F28D47C380BULL, 0x57E46AD096460C0CULL, 0x5C93A99A7832BF2AULL, 
            0xC7B45B1C80C7C75CULL, 0x43DAE17AF6CD3FE0ULL, 0x07584964204811F2ULL, 0x43015074886857A4ULL, 
            0xB17B73E88F962DA2ULL, 0x0EA31756BCBDB4A6ULL, 0xD0AF0D7B83CD868FULL, 0x1DDEA9AF03DCB7ABULL
        },
        {
            0x1DE853D97D82516CULL, 0x6F128B118A993402ULL, 0x0716C6537905D2C4ULL, 0x8097D10F0AFFEE5AULL, 
            0xC33B77C8A9F09C50ULL, 0x16D18DEC40FD33FDULL, 0xC9DFE57C0F8509D2ULL, 0x9C80EAEDB6B96B98ULL, 
            0x3839BA4AA1F7C68FULL, 0x83D1A7431E6D4CDAULL, 0x235A851578C546F1ULL, 0x95E8D1080F00E524ULL, 
            0xC57D0FD1A6D6A35CULL, 0xAE41F2F34A8A2242ULL, 0x182F619056A6FD0BULL, 0x3345F5ECE1063053ULL, 
            0xD9C2C851DD4DB0D5ULL, 0xE8D8243C274B7A3AULL, 0x6BCA9DBCF4ACD7A0ULL, 0xBB90455958EA9575ULL, 
            0xD0B570A71ACFEB85ULL, 0x5197480BAE1A34C6ULL, 0xA4797D4A3B5930B4ULL, 0x8805BEB025533C85ULL, 
            0x6920B58F30C55DAEULL, 0x2E6C88DA9FDCE664ULL, 0xFC52CF1908213C3BULL, 0x85B29BE06B5592D4ULL, 
            0x54B3BD77747EB350ULL, 0x4A803ACE45CDDC0BULL, 0x35CD7D1A18A58633ULL, 0xBB0CBF92720F1D0EULL
        },
        {
            0xF25D332DFD1128BAULL, 0x8DFC038E2F552429ULL, 0x2E1D9C70AB8222FDULL, 0xE8A2F6616A86FB1DULL, 
            0x284A02E9D49D8714ULL, 0x10C9730D54C61983ULL, 0x21D5C41B24ABF62BULL, 0xB85373DA325835D1ULL, 
            0xEFF615D5E3D8D8CDULL, 0x9F46BA119291C0D1ULL, 0x20FA03DFD06D9951ULL, 0x6C0BD6931E82FF0CULL, 
            0x9F1CBC3CCB209D74ULL, 0x747EFF3FBB219C58ULL, 0x8B986BEC0AFF53F7ULL, 0xD150655EC64D9B70ULL, 
            0xAE33A300AECEEE9DULL, 0x7A029830B08309CAULL, 0xF8E405CC02F8A237ULL, 0x823EF6908D86A6D9ULL, 
            0x8C67FC7177BB613EULL, 0x04467A27DAF20302ULL, 0xC36499B0C03B1842ULL, 0xAF42D5666620A9E1ULL, 
            0x3D9D9249BB1CE0E3ULL, 0x1CF6606D8F26FE72ULL, 0x70CB1CD0FBD058C3ULL, 0x142DEBB197BE9309ULL, 
            0x9207CF5CD85A63C6ULL, 0x9C703ACA55812A29ULL, 0x2A7565A4FA208638ULL, 0x0916B063476C861BULL
        },
        {
            0xF55E97E5CFD27196ULL, 0x6F174A818295EE6CULL, 0xB650C4C7F60BF7D5ULL, 0xF27CF8B7C876D902ULL, 
            0x6B310879A914A40DULL, 0x8E762D25F663C924ULL, 0x65076BB99411BEE7ULL, 0x16A669E85EE64FBFULL, 
            0xE091AC6D78800B0EULL, 0x408E01649668AFE2ULL, 0x94136EAE71C3BAEAULL, 0xEDFEA3C13B1257E0ULL, 
            0xA0D0BAA9C72D9465ULL, 0x260B803BDFDF3211ULL, 0x5C69FE11E92A38B1ULL, 0x073BD865B6886E24ULL, 
            0x3143BD4D6EEBC207ULL, 0x7DEB840E33267373ULL, 0x19171397DBDA4EABULL, 0x4F7E97812F732412ULL, 
            0x5548034C85C6EFB7ULL, 0x6052B1674D20BBFAULL, 0xC511D41FC8276869ULL, 0x2C180F290F93F4FAULL, 
            0x52E4821B8C36CB6DULL, 0xBD3171F9D7A69B67ULL, 0xA3C4B1E10A824D11ULL, 0x8B68FBB57DB79337ULL, 
            0xA1DD46F02BA232DFULL, 0x64681E406D7BAC89ULL, 0x68F7597B04D22DD9ULL, 0x0FE6557B0F292129ULL
        },
        {
            0x132958BF01B4BD1EULL, 0xFD343C5E6F5D59DAULL, 0xD12602FBCABBBE65ULL, 0x1050DDC160A31AB5ULL, 
            0x315E0972AA108DD3ULL, 0x8068DA07E6F0B1BDULL, 0x5BBB234621299CB9ULL, 0xBFBE5AC0873D6337ULL, 
            0xEEFD8039F0F7B853ULL, 0x30DE747F699A223AULL, 0xF749D9D0C3D35531ULL, 0x0321BA6544DFAD60ULL, 
            0xA145E3EDD2985422ULL, 0x185B2E85D83E5590ULL, 0x4A9564AF0901A331ULL, 0x03D027CE38083651ULL, 
            0x81EB6598D023677EULL, 0xA2DD76DD2E699A36ULL, 0x69BC579C453C382FULL, 0x19D27D2E354FA624ULL, 
            0x93FBB79E4D0D3A59ULL, 0x0FFED290D3532C16ULL, 0x422938969085B281ULL, 0xC7157A5DCE55EF1CULL, 
            0xA1B467F5A8844D8BULL, 0x91EDBB0E4C6F98E6ULL, 0x465E21C0E745EB2FULL, 0x81F512A5BAAA76A3ULL, 
            0x5595CAE49D2038B4ULL, 0x31E94462DBFEBE77ULL, 0x0DDC46F1936F5D8BULL, 0xABC292077F61B1D9ULL
        },
        {
            0x96FB2AD6DE836D6EULL, 0xAE0DAA68CA6A34AAULL, 0x15A47DF7E82746A3ULL, 0x8470E683951A51EAULL, 
            0xB096EC557AF75F90ULL, 0x1A029CCE2449A475ULL, 0xF8FA3114BFCA84DEULL, 0x0E263CC6D0B63AFEULL, 
            0x6CE48233552B7F87ULL, 0xADE89B344DD7D49AULL, 0xA46DF52168F52BF8ULL, 0x783D5E3E7F6F4A8DULL, 
            0xCED79216A583321AULL, 0x6861ABA32B29EAABULL, 0xF457F20378B86704ULL, 0x65C484972455C481ULL, 
            0x85F114D6DA1B96A2ULL, 0x81F1A42B40004A14ULL, 0x30750D71B46F0CFEULL, 0xBF3EDB18F84708A9ULL, 
            0xD5040CFB4075D286ULL, 0xBD5223580EC8A426ULL, 0xE041A2EE16DB2ED6ULL, 0x7AE68A7EE15B53FCULL, 
            0x97108B01BBAB84D4ULL, 0x86DEBD19D11CEE94ULL, 0x2351C561C72B10D4ULL, 0x2CCAB550D1055561ULL, 
            0x0B74B5B5CAD10B44ULL, 0xC71E2E85AAAA4555ULL, 0xB01D7E9BA13C14B5ULL, 0x32A0E5211636A25CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseDConstants = {
    0xB18274F230B5EF9AULL,
    0x814FFFE4D39AB83CULL,
    0xBFF9E747EF35CF5AULL,
    0xB18274F230B5EF9AULL,
    0x814FFFE4D39AB83CULL,
    0xBFF9E747EF35CF5AULL,
    0x953B325F2CF803F5ULL,
    0x3568455F2FFE29E2ULL,
    0x12,
    0x9E,
    0x6D,
    0x6D,
    0x88,
    0x11,
    0x2C,
    0x22
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseESalts = {
    {
        {
            0x4CA7CB35B7BE4514ULL, 0xB87006D81A7BF7ABULL, 0x46292B48C5F0FDA0ULL, 0x1003BFA023619BA7ULL, 
            0xA0E3D431EBE77D88ULL, 0x4E57BBFA0AE45CE3ULL, 0xD2D543D13249E6E6ULL, 0xDC7FF27000CC04F6ULL, 
            0x8D1E1010A9760F7CULL, 0xB0AFB2FD18A78D7FULL, 0xB8165A5C8AE77444ULL, 0x187A6AED6E20C4DFULL, 
            0x97F1CE3BFE5C15D8ULL, 0x644B5691569A46A5ULL, 0x1B0A28F27012F046ULL, 0x890002E15FED8AD3ULL, 
            0xB6456DD96633A124ULL, 0x18CA905927AB19C9ULL, 0x04EE0BB10C36E0E8ULL, 0x17C750DB68C555F5ULL, 
            0x89F667C142E7D80FULL, 0x0CEEB14BBD4BAF98ULL, 0x1214811989D23B4DULL, 0x7EA0E6A1E922FA8CULL, 
            0x9B0E9C19DDA05534ULL, 0xB966DAF5BCEF49CCULL, 0xF5776CE163649FD9ULL, 0x229BAE2C8F559E3CULL, 
            0x690B6C1E7AC70ABAULL, 0xE0006961A2CA3465ULL, 0xE64D7A6BB48983ACULL, 0x2C084A2B818FFC6BULL
        },
        {
            0xF5719205482F6E12ULL, 0xD9BD06F3F04549FEULL, 0x7F64D4FFDF8AF1E6ULL, 0x9B43365350FAEE04ULL, 
            0x2685B84C82550D2DULL, 0x6A17F8CE82DF985FULL, 0x0D5906F644431131ULL, 0xC81426BD0AB9C8CFULL, 
            0xAAC45E72711E49ECULL, 0xF040AD03C98159B4ULL, 0xBCEE996469E0C826ULL, 0x089CBE8E593DB14CULL, 
            0x0AABC86982A17E70ULL, 0xE48120CBEBB779B3ULL, 0x604C2A24236D05B4ULL, 0x28123B52B16F2E52ULL, 
            0xD10F666552FC9A44ULL, 0x1A270F10234B306FULL, 0xAC50F50CFF9AC895ULL, 0x56D7DA5198F6B63FULL, 
            0xB39AA29B53769E08ULL, 0x2C45D1B0849919F0ULL, 0x318B9CDBF2F09689ULL, 0x9C85E5FC4143FF19ULL, 
            0x5CC251FEAB2729AEULL, 0x78286F0D9BE71AD9ULL, 0x5F342A67157D4F25ULL, 0x0980B2C7BED5E774ULL, 
            0xE1322396CCBB2179ULL, 0x4CA1E40BF681E8CBULL, 0x57968E996FFFC595ULL, 0xC0E63EDBD28AF4CCULL
        },
        {
            0xDD01AE2BD53834B4ULL, 0xC7413F6208E30B1BULL, 0x10960427A005586BULL, 0xF1A3D02F56358B05ULL, 
            0xCF6C48D4B9DCE382ULL, 0x7B211089FF197DBBULL, 0x82CD5DE7AD8789E2ULL, 0xE40CF6D2C9A002D0ULL, 
            0x77EDE97698362AAFULL, 0x21598D8FE79F994CULL, 0xC62B37F3B20C25E1ULL, 0x6EBAA2AE1930551EULL, 
            0xE298B8E052EE0D47ULL, 0x9BCD97499B36EA57ULL, 0x07C6897D3E4A08D8ULL, 0x80E52E75ED04BC9FULL, 
            0xD318C26709F7A325ULL, 0xAF08D122914239F4ULL, 0x43DE7D0AB009D475ULL, 0x0B26FBA8B0C3478BULL, 
            0x5E026C574C71B120ULL, 0x6B2E1624D68CDF68ULL, 0x09BDF0FD0B4759C2ULL, 0x7E860340C6F4AE38ULL, 
            0x15D5069E95D6116CULL, 0x768B47D02F354EB5ULL, 0xA8785B82691E23E0ULL, 0x66244B62577243EFULL, 
            0x5A473FBF981AE4DDULL, 0xF5728C68A2B3A5A1ULL, 0x545159D0C0D6BCE4ULL, 0x04817C382013F78DULL
        },
        {
            0x5109E7D92159647CULL, 0xA3770F7639C64192ULL, 0xA7BC5C3BF54921D4ULL, 0x8EF2ECE431CA6376ULL, 
            0x0AEDCCF0E5C6671EULL, 0xA53334B00E8FC7FEULL, 0xBA378324217D3390ULL, 0xF27C4EA310945261ULL, 
            0xFF3D7C23AA895A43ULL, 0x3CCBCF4CF0D50FB3ULL, 0x25F01737B92EF07BULL, 0x8F9655A38AF973E6ULL, 
            0xB0DCBDE61F8F0B1BULL, 0x036F83791E026AFBULL, 0xE78FBF895F63E842ULL, 0x2A61C0F9FD5F4082ULL, 
            0x909ABDB85236C151ULL, 0xA160DAB78561231FULL, 0x8D95F31DE02AD112ULL, 0x81269049DA2CF278ULL, 
            0xE8365FA269DA98B2ULL, 0x53F4778E29DD56D5ULL, 0xC945C6297D87749DULL, 0x8B753B01361D7878ULL, 
            0x481DB87CFCEDF46DULL, 0xA7A7B05089B98D53ULL, 0x2C6974689158B115ULL, 0xE5E69CE0F9915E58ULL, 
            0x2F6E4F56060E4089ULL, 0xFEDF7F68908F5A28ULL, 0xA4D5BA41BC76B2E3ULL, 0x07B1253CB35E9F43ULL
        },
        {
            0x22F47794A317612AULL, 0x326FCEC810F52BD0ULL, 0xA38BFC92F809C325ULL, 0xEE8BC2E61C610969ULL, 
            0x4711E2B57958CC68ULL, 0x49DF08360C5EAD5FULL, 0xBA38D636A92904B3ULL, 0x4C98FBDD3301B5F8ULL, 
            0x665EB60DF4071961ULL, 0x399BFC681B727EEBULL, 0x944D3CBFC093EEBAULL, 0x846DBF9F69253ABBULL, 
            0xF8EEFE4E1CAB2A53ULL, 0x37F25616605F2DCAULL, 0xE8094128624F5B6DULL, 0x7B8D4AAB0D62F4F7ULL, 
            0xF6B1EA5FBDD645E2ULL, 0xB7EB5306688AFCA8ULL, 0xB8D4187A35EC21F6ULL, 0x082ECD06663578BEULL, 
            0xEA560D47EA363B29ULL, 0x93E15EF866B3FD48ULL, 0x3F078F762E6B1145ULL, 0xC56F3FF8D715C92EULL, 
            0x22B514BFE2D9CA9FULL, 0x8928F7B83350275AULL, 0x428DA864F130436AULL, 0x5DFAEE6F46727119ULL, 
            0xF6F9A535CFB6441CULL, 0x6EC2A924627B7130ULL, 0xB9FE2453365BC04AULL, 0x66E3BA9045E2A368ULL
        },
        {
            0x5DAF8468CD198A68ULL, 0xA98D532E174B726DULL, 0xE903861068AAAD8AULL, 0x42734E31F7E0906CULL, 
            0x99495ACF03892439ULL, 0xC6A86FDF5B5333B9ULL, 0x042F98D6C73EDDEBULL, 0x2EAA17D34AA226FCULL, 
            0xC7B8F172E1E0FD04ULL, 0x5443D081FE2D7370ULL, 0x74BB57108E26EE77ULL, 0xDA8B0C02BD2E154DULL, 
            0x91649C28709FF00BULL, 0x3AA0FEE675A91976ULL, 0x67AF5936B876B7B3ULL, 0xBE44F3A57C24F0AFULL, 
            0x7D3ED191C98E293DULL, 0x84BE95C702A2C1A6ULL, 0x48AAAFE02422B6FBULL, 0x3BE76E62EAD2BD91ULL, 
            0x60783D6123FAA3BCULL, 0x181917A5B7838CF2ULL, 0xB305B505DA1AF130ULL, 0x095B59F1B1591AB9ULL, 
            0x25A99353D250B94CULL, 0x78D8F12E59F4D702ULL, 0x6FA05F6791D9A671ULL, 0xE6021CD3EF21A23EULL, 
            0xC8CE745174A01AADULL, 0xBBFC0A441391C8BAULL, 0x50D21A1125D6A79EULL, 0x7D856BCEA92EA46FULL
        }
    },
    {
        {
            0x0581C9E8B6D31BE4ULL, 0x06FFE60E6BFC7A5EULL, 0xEA56D4E3F97B7D0CULL, 0x0AA47853E99376D1ULL, 
            0x3B4DAB97F38FA17AULL, 0x167697EA34B31CBDULL, 0x094F022875331990ULL, 0x0C25F3CB41B9A175ULL, 
            0xC0FD5C8C001BE7A3ULL, 0xDE5D518B1EA05BD2ULL, 0xF3E281A9CA272E7AULL, 0xF930B3F765A556C3ULL, 
            0x860197C4B9EBF0D4ULL, 0x12C06212AF66BAA1ULL, 0x8944D62253BCA982ULL, 0x5F5CF0123CD35BA4ULL, 
            0x7E0C0079536D1188ULL, 0xD76413A0234B04E8ULL, 0x8BCD395AFC47DE33ULL, 0x73C69BF911589D6EULL, 
            0xC1075EB4A2709206ULL, 0x517C0783617CE28EULL, 0x19AD0F613FFB64CAULL, 0xD38A483DDA3D6BB2ULL, 
            0x948BA076A607A48BULL, 0x136DE0FA3BE704F4ULL, 0x3AEC15AD1AD9A094ULL, 0xC660C5D380AEA350ULL, 
            0xC8CBDCE512E40DACULL, 0xC08C22FE9122E0E7ULL, 0x33B9FB84749B1367ULL, 0x39E7FA4D35B5186AULL
        },
        {
            0x0AEF72AEE16E7A1EULL, 0x42BD7D277EE7DD7DULL, 0x29FEE4953684E244ULL, 0x0B0A0F1BF4C29040ULL, 
            0x8F0EE6664BB2BB11ULL, 0x9B8B35F63119C15CULL, 0x98ED011E89E10C06ULL, 0x3366FD4911E27144ULL, 
            0x68CD3D3B173DF6A4ULL, 0xB1FC907233D0ED8DULL, 0x87D6278CBBAFA759ULL, 0xEAC6E3A2B9E08FBEULL, 
            0x2D9D9FA799DE3C16ULL, 0xB7836F1EDB8ACB1EULL, 0x51DA28496F4B2702ULL, 0x6108BDBAE63440E2ULL, 
            0x569A24FD21F58D16ULL, 0xEB7C194F3203857EULL, 0xFA910F6730335833ULL, 0x0250E8FEE9FB1967ULL, 
            0x7B8F8F82AFD20C73ULL, 0x4AF2824DACB9711AULL, 0xB37A3E47790A5344ULL, 0x3C938532057E3CE4ULL, 
            0xBFB0DBB8291D655FULL, 0xC2C8F34E5519CFEDULL, 0x9774C169786AF435ULL, 0x2E5A8D382FD65D56ULL, 
            0x3D45F771E0CCE346ULL, 0x74AE9AC854CA0F4CULL, 0x2CBB15C7439134C7ULL, 0x2D0FC15C9A9B04F5ULL
        },
        {
            0xBFBF8D6504B2C32BULL, 0x02FEBE581B209A8BULL, 0xCDF5E0BC1B6A46C8ULL, 0xF22AA7AF57198DA0ULL, 
            0xBA8A3E587A4FE838ULL, 0x2E1656B185CB2169ULL, 0x9A158E17B50ED5A3ULL, 0xE7931194F895CE45ULL, 
            0x23364529A496EBBAULL, 0x7BE71B04239EE11DULL, 0x2F1E9B593D192DB5ULL, 0xC0AD8DA91DC7A7A1ULL, 
            0x1B99C4C5D6153BA8ULL, 0xEB1649449F2F8948ULL, 0x650A5F125BAE83FCULL, 0x785F257A3A9B7F81ULL, 
            0x421520EDF13B9D4DULL, 0x212FEACDA18F0B06ULL, 0x2A045543206F4DB9ULL, 0x3DFA1EA7909C4806ULL, 
            0xB14566569D76A7D2ULL, 0x5AAFB4A31170AF40ULL, 0x83854CB6837F3E0DULL, 0x0EDF8EBC09ED3F2BULL, 
            0xA538BF957292EEC6ULL, 0x919E25A3CE685FB0ULL, 0xBFE55FAE0D4700C6ULL, 0x74DEFD000D2EAB0BULL, 
            0x2FA248DC6422E2E8ULL, 0xA11F70AE0E60EF2BULL, 0xC1631BDA3C83D871ULL, 0xB999F92505E9020FULL
        },
        {
            0x602A0711989387BEULL, 0x550AB1D6A3B3E0FAULL, 0x9EBEB5EC6AE496AEULL, 0x4C36238FBEF39D22ULL, 
            0x81AF57DAE5F7A383ULL, 0xF29E55755FDCADDBULL, 0xFFEC8FC93F2CDE26ULL, 0x739BFC0334FC21DBULL, 
            0x877B0A04586D92B8ULL, 0xD80DC933BF02EA30ULL, 0x89C8A2CFA837B09EULL, 0x4AA36B539E280164ULL, 
            0xFD0CFF5B5780DF56ULL, 0x3929BD53745BB571ULL, 0xB68B51E50AE5B249ULL, 0xF1CE6DA4C6463133ULL, 
            0x4D1CE7EDFD7BCE25ULL, 0x76CFF94092C13381ULL, 0xE46E65E7AE334713ULL, 0xA784B0AA04EBC036ULL, 
            0x155C95D5D2152C11ULL, 0x32316CC93121C97AULL, 0x5702EAE58F103AF4ULL, 0x6AEEFC239296DF32ULL, 
            0x1E008C5560A461A2ULL, 0x1C56EBD36AB7EBFAULL, 0x5F34676C44D5ADB4ULL, 0x9B373FAF6461D291ULL, 
            0x9DDCC3F5A8B23DDEULL, 0x73885F6171365A43ULL, 0x865A342420D01C1BULL, 0x1EF6879BD5A2EA06ULL
        },
        {
            0x53DC0FEABE188470ULL, 0x67D618488854AD72ULL, 0x49C97AFA32F332AAULL, 0xB8409DD0289C8EAFULL, 
            0xC57F1AFB6C6738C7ULL, 0xF0AF66BD490CF3A9ULL, 0xDEB8B26F82AEC311ULL, 0x3A0DA68EEC6771D1ULL, 
            0xC13CEE32B983930BULL, 0x5396BFAE2E072034ULL, 0x39A56A005FEBC2E9ULL, 0x98E70CB67D6F25BEULL, 
            0x162287CC96AB2B9EULL, 0x7649A803A5F5934BULL, 0x49AAAA5CB64CFCBBULL, 0x44E71E24E6E9C5ADULL, 
            0x3F03DEB8BD630F3DULL, 0xF89EEC0F337D7975ULL, 0xBBCC0C22873CAF5BULL, 0x7115E1DBD7CA7B94ULL, 
            0xAB4223FF428CA878ULL, 0xFDB8AC9048B84BA1ULL, 0x4EEBF16A882C33A5ULL, 0x66C4789C9A407888ULL, 
            0x968A7D0765C45298ULL, 0x33D44117A46079DAULL, 0xC1F28997761521B9ULL, 0xDC80C939E86C073CULL, 
            0x991221DA54B88352ULL, 0x719449B188DE75CDULL, 0x560184563B9B4826ULL, 0xCEE68DBBC428976AULL
        },
        {
            0xE226FCA1D1AB13B8ULL, 0xF85E333883E151CDULL, 0x4F9ECFD69B0228CFULL, 0xBEA34ABB49261EC0ULL, 
            0xB26AB40977E5A7DBULL, 0x8CE7B9386419388DULL, 0xBE8972E1358C0118ULL, 0xE0CC76FCC920289DULL, 
            0x457A8664C82B9EE3ULL, 0x8FAB1F21814287D8ULL, 0xE9B61F928FBB2DB1ULL, 0xC96AE7EE3BB448C9ULL, 
            0x3E2521840A3F1C89ULL, 0xA77CAE3F33445DB6ULL, 0xB69DEC980BD2284CULL, 0x8FA25BE69B03278BULL, 
            0xDD6BCF443A4EAFB4ULL, 0x99DDC73FF3A76118ULL, 0x0574D33E9B78D356ULL, 0x31ECC4B40470F046ULL, 
            0x9E26FF27480E9BF3ULL, 0x9EC2D0ABFBF02769ULL, 0xFF848EF4E8C3AC51ULL, 0xE796AE46DED46A54ULL, 
            0xF214850A95DCD0CBULL, 0x5EFD481B6BE055EDULL, 0xAE18052546EEB878ULL, 0x96DF6357768DE639ULL, 
            0x20D87A41E0ED83D8ULL, 0xC7A126E90F7E11A4ULL, 0x66CF6DF234C2EA2CULL, 0xFF25123E8793423CULL
        }
    },
    {
        {
            0x916A003662BC6CD2ULL, 0xDD959DC636E2FAB1ULL, 0xAB815C922F79D87DULL, 0x06F8D1F282817B7FULL, 
            0x612D039AC1826F5DULL, 0x7D7301F6207BF90BULL, 0x1B1C3CDDFF05D26BULL, 0xCB03A69C988AD7BCULL, 
            0xF91708AE6C3B6DC1ULL, 0x9DDCAF7105BBDFCDULL, 0xCDCCEE58C834BF6EULL, 0x245F78F1749BFF15ULL, 
            0x732E93AFD625AFA1ULL, 0xA6CA600326608FB7ULL, 0x05E60C52F9111C63ULL, 0x76DFDEF3B02E2765ULL, 
            0x23DF589599921710ULL, 0x867CB89C916F3A90ULL, 0x5520C06C955AC908ULL, 0x14DC068C4DFDCEE4ULL, 
            0xA3DFFA635DA73BB3ULL, 0xB151A4EB289E8479ULL, 0x3D9EE92227FDD70CULL, 0x7546D0D538493EE9ULL, 
            0x906D9698AF366CCCULL, 0x1CB720E454B8C1C8ULL, 0x567C911A94B2C351ULL, 0x8E936305B94F5F9FULL, 
            0xB5EF5F3C428A2A4EULL, 0x006D5F2319FD607BULL, 0x3D8AEE38D8284703ULL, 0x481FA8593814DC47ULL
        },
        {
            0x2080E996DE1884C1ULL, 0xF48AAEF523C1C083ULL, 0xA1CF2C915C42C06BULL, 0x9F2F7D80D04A5B55ULL, 
            0xF77F53E9A879421EULL, 0xA9D7F75F77FA0382ULL, 0x1C086D8831FA5B3AULL, 0x9AF216EBD91C5B9EULL, 
            0x112AF49F5EE771AEULL, 0xC0B54FCD33DC7957ULL, 0x610ECCC26D1DBBDAULL, 0xD92889504A11BBFDULL, 
            0x496CF52FAB364675ULL, 0xB3B3F9330D2A80C9ULL, 0x2E5EC426CDC1207DULL, 0x008BAE38D20641E9ULL, 
            0xDE820F20666867F8ULL, 0x65418A31BF2E1C95ULL, 0xB20D0BEA3F8E2A12ULL, 0x949626EFB7FECB90ULL, 
            0xBE9A86D5C969F637ULL, 0x78975B76A93A95ADULL, 0x6E8519062FCF53B6ULL, 0x76429409D7ACB94EULL, 
            0x551CCDD1AAB5321FULL, 0xB142025AF8679B84ULL, 0x486482D51954AA1EULL, 0x0A9D7C3E5CC78907ULL, 
            0x31CC353D9482D1D6ULL, 0x43ED451B7A5D59F2ULL, 0x08DCF223A5CF83A9ULL, 0xAB87B490AF192E63ULL
        },
        {
            0xBAB45595B86D0F99ULL, 0xA951677100065670ULL, 0x553C69C91EFF9FF9ULL, 0xD37CE16FE0EC25CEULL, 
            0x010F9FF2B1A863F9ULL, 0x67774939C04F1545ULL, 0xBEA85379AE0EBED0ULL, 0xF917AA8AE8CE971BULL, 
            0xDBE838E5A130F6A9ULL, 0xDEAF1B634B6E1722ULL, 0x8BC195C318F7263DULL, 0xB8E1511084391463ULL, 
            0x88E00B2F398E2B86ULL, 0x1C45DC2079F83E61ULL, 0x082196B1AA4C6F43ULL, 0xD77BA6CAADFC7C0AULL, 
            0xF4A65C7965125E2DULL, 0x94329B53D999B217ULL, 0x71601A6F2A4A9BD9ULL, 0x3A016DD4C0D2F9AFULL, 
            0xD220A61D7546379EULL, 0xCEC85EC0AE33FCE3ULL, 0x03F37484D4D7E294ULL, 0x51E337C93207C5A0ULL, 
            0x58298021B08C69F6ULL, 0x028594149F6D4EB7ULL, 0x3B6F05455D043568ULL, 0xC4966AF20D386891ULL, 
            0x6AE5DC82609D0E97ULL, 0xA0310C7295354128ULL, 0xB8C899BCF129C185ULL, 0xA5E78B407BE489EEULL
        },
        {
            0x3F4A53BCBE475708ULL, 0xAC217AAA765C9D25ULL, 0x3C349C4DED5BB53FULL, 0x7CDFA22C871A2E8FULL, 
            0x44A39609FDEC8372ULL, 0x499A194DE1342567ULL, 0x5B3837B73F4D070DULL, 0x1913B12A0E29AA31ULL, 
            0x87E2082F3F7DE6EFULL, 0x310172DC1678BD66ULL, 0x587E5EB55382CF01ULL, 0x95874B2578333DE9ULL, 
            0x7D44EE1A313B3FDDULL, 0x9E1971F73038158AULL, 0x277138BE72333E0FULL, 0x60B503CB9F9ED811ULL, 
            0xE6E7BAF75AF543F3ULL, 0x16BE29305C207349ULL, 0xFF8B4D0D3FB27DFCULL, 0x69ECE6B7A1A2FAA9ULL, 
            0x23859419BDD7A73BULL, 0x324C8BE62FCBD191ULL, 0x7F7EFCD2A769A3DEULL, 0xBE07D67D2F736F0DULL, 
            0x18951EB69A60F830ULL, 0xF7EFB5C6DFA7091CULL, 0x5E246973119915E0ULL, 0x9D2F802FE3284760ULL, 
            0x9BA03BB8AB4BC0B4ULL, 0x19BF9265341DE22EULL, 0xD631FCDC5CE4690AULL, 0x2A4B1D7EE592AD69ULL
        },
        {
            0xD036C75ED145ED25ULL, 0xFDAAB8ED6EDE7187ULL, 0x10CDBC77D0584B34ULL, 0xFDC4C990A067AC40ULL, 
            0xC4CD9D5C4DBC2158ULL, 0x22E742FF68C0547FULL, 0x4BC7409B581F4717ULL, 0x47E7027E615D1DDAULL, 
            0xA7EF4BCED7D000C1ULL, 0x1079EC44D4098DFFULL, 0x5C62252F7C56606FULL, 0xDD49940C6B649414ULL, 
            0x7DB94F3F6611D35DULL, 0xEBFEFF1E3ADF2809ULL, 0x9203BD8DF0811292ULL, 0xB4D9C611B8FECFE4ULL, 
            0x23B93AA5E2DEB869ULL, 0x3200BBD10EB86E08ULL, 0x5010CCE864CAD97AULL, 0x1A0A731D759BF988ULL, 
            0x6A1C1D7A5E781097ULL, 0x849403E4E5417D0BULL, 0x1739E85BA6B9A9D9ULL, 0x80A38185E28A2388ULL, 
            0xA1927C6E85FE62B9ULL, 0x6231E3A5C0AFBD47ULL, 0xC5E488EA82B374FBULL, 0x2102151A9FDFBC29ULL, 
            0xD505B23357D3B9D2ULL, 0xBCBBBB030A710C1FULL, 0x8279E54255A792B1ULL, 0x970F66CE4954E045ULL
        },
        {
            0xDB49646637A45201ULL, 0x71AE8CE78A6D7969ULL, 0x80FB21B4B461AD8EULL, 0xBCDE255D880CAB8BULL, 
            0xF8FCBA33E681B405ULL, 0xC443976B0B73F917ULL, 0x64EF60187AE85392ULL, 0x47B37BF045125A1EULL, 
            0xEC37C244962B096FULL, 0x3BF2B545D2296F25ULL, 0xDA05D578DB4FD94CULL, 0xF3D7DED6C552DD52ULL, 
            0xE46C12D7C782C168ULL, 0x9EDCD2E0D1026794ULL, 0xEDA385F788CEF5E1ULL, 0xFB2740ADED8FF043ULL, 
            0x8CDAFEBA82F1058CULL, 0x922AF55B1612C7A4ULL, 0x61C7B883BA2B067FULL, 0x6BFCE0EC80DF8E00ULL, 
            0xC9B615F41DF21B99ULL, 0x28748733302F743FULL, 0x026FD02AD4119431ULL, 0x357D339E89648328ULL, 
            0x07BEC388F30BF4A6ULL, 0xB1E7FE84D2534D2CULL, 0xB817723A8E1CC894ULL, 0xDD106E8DCB44814AULL, 
            0x9045AF57EA2D6023ULL, 0xF53BD706923D41BDULL, 0x2614BFEF0C8360EFULL, 0x543F7681C6F8085FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseEConstants = {
    0x06D6309989D4C9CBULL,
    0x62A4B68045101FC9ULL,
    0xF5353ACA8A6E65BAULL,
    0x06D6309989D4C9CBULL,
    0x62A4B68045101FC9ULL,
    0xF5353ACA8A6E65BAULL,
    0x3D42258EACC82E8EULL,
    0x24B73E0E0A990692ULL,
    0xB5,
    0xBE,
    0x46,
    0x68,
    0x5A,
    0xB3,
    0x04,
    0xAE
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseFSalts = {
    {
        {
            0x849A64FF08501063ULL, 0x41630EAA1C1584D6ULL, 0xA5A90497A271F186ULL, 0x9F3750C70BF83A2CULL, 
            0x153EFEC028BF504BULL, 0x36BCAF2720E19465ULL, 0xCDCA8C082CA28F16ULL, 0x3366B7DBA527F9DCULL, 
            0xB299B037685308A8ULL, 0xB42A34344BFC1B1CULL, 0x4C1B1DC797649860ULL, 0x0547217620E6433CULL, 
            0x29B8FC800D541DC5ULL, 0xB5EAD30AA208A8E3ULL, 0xF17147070599CAECULL, 0xDADA25957381DB0AULL, 
            0x519723325E016AE4ULL, 0xB977E3EDF34DA9ADULL, 0x4FC1DA69B0E1A7DFULL, 0x02D3AE8001F4E2E5ULL, 
            0xD68A89C25AE8FEA9ULL, 0xDD12B9542FC5BC3CULL, 0x39AED71A0B64C95EULL, 0x7FF5C17568933184ULL, 
            0xB260AEB3E23EC3A5ULL, 0xA81AE9298E057FC1ULL, 0x667401EBCCCE29FDULL, 0xF9A0A2D05BB06270ULL, 
            0x8E851F93D97628C0ULL, 0xC2BC243178ADB4CAULL, 0xABC8721AA52A403FULL, 0x583B67EE646DE77EULL
        },
        {
            0xFDD6EB777C793121ULL, 0xDF7E71BF51A5E50AULL, 0x20DC21B79CDDE91AULL, 0x7E06DD5D6364C447ULL, 
            0x0BBFE4DCA0EFB1D2ULL, 0x574E1153A57E6955ULL, 0x875137A37AFC5BF9ULL, 0x70BCB39266F658F5ULL, 
            0x64B7C57D61C1334EULL, 0x6E5330B02077D289ULL, 0x18BB27C12A2EEC30ULL, 0xF6FC4963BF60E18BULL, 
            0x6F663208093C3F92ULL, 0xE7EEEE7662057BCAULL, 0x6F52B1EF702B1A1AULL, 0x47201047AC745D36ULL, 
            0x44BDBB3AD7725157ULL, 0x01359588D2E687C2ULL, 0xC05E32A34D1488F3ULL, 0x8FEEAE13FC0F7EEBULL, 
            0xEBA395728FAEFE88ULL, 0x415B4A8E04EF3B09ULL, 0x4A20E0D0C3A94620ULL, 0x7412F81DFB4BEECDULL, 
            0x0038FDA3D75A2136ULL, 0x992B2516B876AC51ULL, 0x3C8918C4070606A9ULL, 0x7C82BD19AC4EC099ULL, 
            0xA3C9E5D67CC983FBULL, 0xA6692C91E4D8B30AULL, 0x279DD94DBC144DD5ULL, 0x4BD276A63E3F308BULL
        },
        {
            0xC539623509ACAC29ULL, 0x2938037C023CF1A4ULL, 0x7F0BA3D181C876B9ULL, 0x2585F4A6E448AE92ULL, 
            0x9FDD147DB7B069D2ULL, 0x99AA855DC111008AULL, 0x17BD03411C282957ULL, 0x5D6C0C32547E7143ULL, 
            0x2C5257B5CF530258ULL, 0x4893EBD09706BFF3ULL, 0x330B345F0C308761ULL, 0x5781DA5F25061139ULL, 
            0xD23BB16EEEF17E3FULL, 0x16A05D08EAC1A3DAULL, 0x9C9056797E31AA42ULL, 0xD988B03BFA8D9707ULL, 
            0xC1E48F35A895ADF9ULL, 0xB566A344A2AB3B1FULL, 0x186857AB44B2E7A7ULL, 0xD263F6717DAF28E9ULL, 
            0xD697BBA63F8CFB5EULL, 0xB686851934CD49F5ULL, 0xFB6B1D51D0D6E3FAULL, 0x8E595FAF95BAD651ULL, 
            0x893ECF62A14E9469ULL, 0x71F7C48F501116A5ULL, 0x713AC841F3EF51CBULL, 0x156A9477FA62DB97ULL, 
            0xCDDC8AE52A3A0374ULL, 0x1919816022BDF039ULL, 0x8DD166FF177435A0ULL, 0x306A9F7D05F8782CULL
        },
        {
            0xD4DA0BA9E2ABACC9ULL, 0xF0A15D8390FEBD58ULL, 0x209B5E0B28F9ED5DULL, 0x00EBD753D276C588ULL, 
            0xBA86E436D471F0BDULL, 0xAC00FB7C7312847BULL, 0xB02C81E12A7D0CF6ULL, 0x772BFD7C6647771CULL, 
            0xA7F1BB6C480D195DULL, 0x0F7D42BF56BA76FAULL, 0x2D4B87A139CE494AULL, 0xCED24E448C15189AULL, 
            0x4322D7DB2AE7C79BULL, 0xA8328464546746D8ULL, 0x29E305A4FFE134B1ULL, 0x0F59918ED53EACF6ULL, 
            0x8D11F649BA735992ULL, 0x25C3A88CC4578B72ULL, 0x9B0F08BF8E6A7893ULL, 0x18A1D7282E5E056DULL, 
            0x8B5405A03D490C68ULL, 0xB6555A894DC2D827ULL, 0x5E02052DC0056604ULL, 0x5C0B2A74A57AB53DULL, 
            0x22EEB0D27D1B511CULL, 0xDC84603C2D43CB51ULL, 0x5DACB40538C374DEULL, 0xECB6C27D236E997CULL, 
            0x0DBDFBA11939ED31ULL, 0xC42AABE0CB74290CULL, 0x491EEDDBF0C1EB05ULL, 0x91F4E0480FE3D449ULL
        },
        {
            0x9C499A59410C4955ULL, 0x453CC31EBC8CAB85ULL, 0x3E0C1B9A7D229615ULL, 0x498F94A31ABB338BULL, 
            0xDC266EC94366A270ULL, 0x459CBAE87F7515EDULL, 0x8CF4A344F07CC1DBULL, 0xE2C968E43480923EULL, 
            0xFA32149FBA0CB1ACULL, 0x3A49B3113E28AEE4ULL, 0x4FC29923B8B70961ULL, 0x5292556FFE4AAEE0ULL, 
            0xBF5CD19DA56ADF8FULL, 0xD358F03CB124ECCBULL, 0x533B8166DABB51ADULL, 0xD5CA131FEA04113EULL, 
            0x1BDE3109A1949DE3ULL, 0xB9073021159D55E1ULL, 0x0BE78B1130F9C99EULL, 0x23A159DB2046CC56ULL, 
            0xD95767ECB6B0CA2AULL, 0x62A509863C93DBBEULL, 0xBFB127E4A7D7153AULL, 0xC3A0D8D70F980328ULL, 
            0xECAAFB2E624F4A4BULL, 0x0ADA8EBC062930A6ULL, 0x51DD300B5A25632AULL, 0x48CA639376CE4EBEULL, 
            0x94BE4C66305001CAULL, 0x8C2BA59273BB2569ULL, 0x2C4F0FA1BF445C43ULL, 0xC61E65ED49972CCFULL
        },
        {
            0x2C0ED468E91D5702ULL, 0x9BE40F92A0703DCAULL, 0x25C95B243C27A82AULL, 0x33A31F449482F554ULL, 
            0x100BBA4377DC93FFULL, 0x902D447E553E93F7ULL, 0x760246E301AB8C1EULL, 0x9D9B93DBAB583B79ULL, 
            0xFFBB3629FF14FF75ULL, 0xAE9BCEBD91887926ULL, 0xF8AFE6B8EAEBD63EULL, 0xB15DC5B18401F84BULL, 
            0x8218FFB7F32AEA99ULL, 0xA46AA28682750D9DULL, 0xAFB590229687C5FDULL, 0xF5DABD4E69C7B0B8ULL, 
            0x361E33BE2BB5F079ULL, 0xDACA9A07AB24557FULL, 0x213F260385A65CE0ULL, 0x17A2FEF048D556DEULL, 
            0x1EA00401CC98BBECULL, 0x721CBAE7C4A6A1F3ULL, 0x649B53B522E76492ULL, 0xF4C4DC8AC794CF11ULL, 
            0xB5591610C954EBF6ULL, 0xBCF876A36273085EULL, 0xF4F8C281CE943037ULL, 0x10B221D05E98B532ULL, 
            0xF8FAAF325F9B131BULL, 0xF92F53AB2E2347A3ULL, 0xC955197D6B780D35ULL, 0xAEC76A8C112AB9A9ULL
        }
    },
    {
        {
            0xDA484EA3DFB1DAD0ULL, 0xBF178E7DFFE28CF1ULL, 0x9FD20CC74AF3D56BULL, 0xB9BA51E6662F0EEFULL, 
            0x5AB3BB0BD4EFE704ULL, 0x58017926D21B9F94ULL, 0xEC04FA5217097164ULL, 0xE6519215F6028C74ULL, 
            0x0BAFD36B2D261637ULL, 0x5AA38CE1EFF1A290ULL, 0x5837B5C1090047C3ULL, 0x804E38801BA9B5CBULL, 
            0x166C2F24D9AEFFF1ULL, 0x220B1E5C9377A26BULL, 0xA68146E184761AE0ULL, 0xB5647BFB39D3F2AEULL, 
            0x43FFB9C66AB5A9AAULL, 0x09E694394BB337A6ULL, 0x5C7C87C306345285ULL, 0x80957D0465B96C58ULL, 
            0xD765DFC45983A837ULL, 0xA695ED498DE147A1ULL, 0xEF336E04E8EF9A98ULL, 0xF417B190789FB00DULL, 
            0x3FE8172C6CE3B663ULL, 0x71BB068ECFEE983BULL, 0x429C4B72D2144335ULL, 0xF8718D0A4FDBFAF2ULL, 
            0xB8CA358D86F55FA1ULL, 0x17B7DDC0B5836D85ULL, 0x111C44F449D5EF38ULL, 0x4B6FD3904B654F24ULL
        },
        {
            0x3E8BD241F443328AULL, 0xC1D2E49B2F11142AULL, 0xDC4CD4A95FAFD3C0ULL, 0xADCF9ED005252FF7ULL, 
            0x7F05E905D26A852FULL, 0x49537B7D595264C1ULL, 0xEB504C6A872AC684ULL, 0xB58FB77E39BBADD5ULL, 
            0xE951D1981CF8D701ULL, 0x60E02AD54690DDB5ULL, 0x98C3E0DD3D55530FULL, 0xE2FA882C8EFB7490ULL, 
            0x7A5F5595C26CA6EEULL, 0x81C623777CD9F248ULL, 0x36FD35B46FD63C25ULL, 0xFA22680F66A0A7E2ULL, 
            0xDBF57E9EAA3EA68FULL, 0xA1E9FDC6797BC92BULL, 0x96DD66DFDD7B5246ULL, 0x0194D64370DBD91CULL, 
            0x9F96BE76ED2EF1F7ULL, 0xDB2B9AC24F69BDD8ULL, 0x974EDF71CB198D22ULL, 0x1239751816F79530ULL, 
            0x4CAEBE8C986115A2ULL, 0x3FB0F8D762D42794ULL, 0x36BFCE9E923B187EULL, 0x67C3EE1B39C678C2ULL, 
            0x6314D2E8D1936259ULL, 0x4295BC293FFEBDB2ULL, 0xE7904798C2327FE2ULL, 0x6BD25B10F8968709ULL
        },
        {
            0x68068DA763F137C7ULL, 0xD63D347C203C173DULL, 0xFB1ED15E24B3D97FULL, 0xA0C5771284A7FE39ULL, 
            0x12D2D6AF83D66D6DULL, 0x30D732192FE8D0CFULL, 0x390BB983900EB346ULL, 0x3FE0E0F1FBE89C5BULL, 
            0x2260697E3F36549DULL, 0x51FC59F3D6943BCEULL, 0x4E0F555E50707387ULL, 0xBE57B22E07073B50ULL, 
            0xBAEC907F410748EBULL, 0x4B25F5860C4153BAULL, 0x0C20B3566830A796ULL, 0x1BEAD5E2572A029DULL, 
            0x4ABA22DAD8DE732CULL, 0x44746065511ADF76ULL, 0x36B6F22ACACE1B15ULL, 0x675716020DD34C8CULL, 
            0x13651ACC7C293576ULL, 0x60895435E93858C4ULL, 0xCC69FE08D0819394ULL, 0xB7D9058517F9FD4DULL, 
            0x70A4D2518C748189ULL, 0x312901C5CC29FA33ULL, 0x0D2E1BCF845AE395ULL, 0x833FEEE17474D73BULL, 
            0xB59B84A09B4C70A8ULL, 0x94D7A3548E98B796ULL, 0xDA1AA65FA602D555ULL, 0x2F20F2672203D162ULL
        },
        {
            0x01486C3736BF83D2ULL, 0xDB399CEC5E110796ULL, 0xB8177F44C9F547BFULL, 0xA7B69624E54E39CEULL, 
            0xA9EF2CE0B8AE6E0DULL, 0x68A91F8D6DE3835AULL, 0xCE983D8FEC14B12BULL, 0xF359771CA6BCCA4BULL, 
            0xACA5F21934073145ULL, 0x1A837869F2A1F102ULL, 0x545923766FA51E3FULL, 0x4EA419CE00DCA855ULL, 
            0xB05FADF13454A5F3ULL, 0x877CFAAE35030D87ULL, 0xB07D5A91D2BB2A1DULL, 0xB2B8A62766B3B84BULL, 
            0x65E3610310E80DF3ULL, 0x3E351161432311BDULL, 0x9D07C813932DB405ULL, 0xCE390D7520CAB5D2ULL, 
            0x2EB1115BD67B745BULL, 0x1B1F32A3DB7A6A20ULL, 0x8B1F2C1D60DE2A14ULL, 0x2C986C6CD4E6F8D3ULL, 
            0x9CCCDEE761BD6D93ULL, 0x27FE3F01758C18B3ULL, 0x7D14D485A7C4F016ULL, 0x2B5ED7F15F1A66CAULL, 
            0xE0E8AE89607D4AFCULL, 0x775515A776027352ULL, 0x9AA14EE312F010D9ULL, 0x97BF20FBC94604E4ULL
        },
        {
            0xA93053733D42B7AFULL, 0x62C65ACE535C1AC9ULL, 0xCC6A568FEE0D48C7ULL, 0x28B2144BB5EC38FCULL, 
            0xCACA17E6BDAD94ECULL, 0x6913FCF5B72677A2ULL, 0x94698A4A57C21E78ULL, 0x1BDD3969E2BE7877ULL, 
            0x7A257A07699DE40AULL, 0x5A8BF162C3C01A41ULL, 0xC579B24AE4D7E2D9ULL, 0x4AEAD37D8EA2A1EEULL, 
            0x727007B6A0B31BBCULL, 0xFB08F6CA5C7EA443ULL, 0x01264BADD9ACB52CULL, 0xDA49525BC582F5CAULL, 
            0x393C64DC524D112FULL, 0x4D68B7C0C58FE758ULL, 0xB70E60877B86ECE7ULL, 0x0836A484954E4463ULL, 
            0xF4E270DA282D67E8ULL, 0x0FD0B46EE959E959ULL, 0xB1B772733A0EA620ULL, 0x9AF9293881A16D43ULL, 
            0x04B8394814E10FEFULL, 0x5C24EDA943FF50B8ULL, 0xE9694AF27859BB87ULL, 0x3AE454765FA6E0B5ULL, 
            0x9873D8745C9CE565ULL, 0x89651015B53E61B4ULL, 0x7C7E7EAD7082F1CCULL, 0x397E67CB1BC7230AULL
        },
        {
            0x0030D392387D742CULL, 0xE17AA0A1F1F48A07ULL, 0x973FA4462B1BB635ULL, 0xDCF7034E7FCAE960ULL, 
            0x6521DE997A4D050AULL, 0x401E90E793B9A4FCULL, 0xAFBE7A98A5CA1ECCULL, 0x79EE5917CC17CC83ULL, 
            0x33032D012ECAF1BFULL, 0xC13A63400B90D318ULL, 0x46EA41CE1569EBE2ULL, 0xC590D3D0B4BD7EEBULL, 
            0x60B071396F6AD049ULL, 0xFFC0CF018C8F4F56ULL, 0x6A98EBE6C16EE458ULL, 0x9767E77903C3E045ULL, 
            0x1E32DB4530A8A9BFULL, 0x37479BF3BAE646DCULL, 0x722D8D3633EBFAEFULL, 0x39B38CBC57DB3289ULL, 
            0x29C2B2C77C836C8EULL, 0x41A76051656BCC3BULL, 0x98234046DD6D12DCULL, 0x98905EA8F4FA02F5ULL, 
            0xEC908D35E9B3A558ULL, 0xA43E7385D4B0F3CCULL, 0x39B9B528BE3D36DDULL, 0xF394BB77B9F61731ULL, 
            0x9A877214D65A8205ULL, 0xA941BFCAFBE16827ULL, 0x76BDDB2146353ECDULL, 0x62D5233AA0A43BACULL
        }
    },
    {
        {
            0xB82536B2CEAADBD0ULL, 0x1D9C08F94ADF7028ULL, 0xE558C41BEFE550E3ULL, 0x88549C46D6F23BBCULL, 
            0x81239E273BD30EA7ULL, 0xEF87DAAE10A2FD33ULL, 0x03965E8900DEE225ULL, 0xBCF1BAE46F708DCEULL, 
            0x62757E5E251F5C4CULL, 0xC0A61A584350C06FULL, 0x4A49AF56231C5BEDULL, 0x7B96D7E50EE250EEULL, 
            0x5F2E3A2870BD58DEULL, 0x4415F100F127058AULL, 0x89B547898452C8C5ULL, 0xB86A91CAFED4DB9EULL, 
            0xD1F4B0FD3FC8EB33ULL, 0xB86EDE403AB1D06AULL, 0x141269F4AE03C09DULL, 0xBEA4CE13B941A7C0ULL, 
            0x7D719F531030CCD7ULL, 0xB3564A34DEEE1AD3ULL, 0xE68CEF72D1EBAFCFULL, 0x69265630937F1EBAULL, 
            0x1C52C31184B22A06ULL, 0xFFD00F03057BF80EULL, 0xC3ACB2525710F40DULL, 0x6A9ED1BD828F0935ULL, 
            0x479CB02478195C31ULL, 0xF0CF8EB06492BE6DULL, 0xDDE49EDD572278CAULL, 0x576CD3F6767E28F4ULL
        },
        {
            0x533AAC6CE277D8B1ULL, 0x4C2ECC8AAFBFC030ULL, 0x42648A03189C7775ULL, 0xD180A9C45DD0CCE1ULL, 
            0xF1CCBD3EFC9DA41AULL, 0xFFF4DF273D5B9B03ULL, 0xFBA06F71BBF9A919ULL, 0xD9E0EC2636A615D8ULL, 
            0x2A29948EEB3775E9ULL, 0xF016AAF297589912ULL, 0x0F4F4C62DCFCB929ULL, 0xC5AA3043BEDD0003ULL, 
            0x7EBFA06B0FBA87E4ULL, 0xF4049162C3DBF987ULL, 0x548BAF688B72B8FAULL, 0xAC179575316EC72DULL, 
            0x279D87F71B31A515ULL, 0x0E63C88707AFC80CULL, 0x1E34E69128FEF828ULL, 0x1F7F72571625BF53ULL, 
            0x76C1A51456521DEEULL, 0x20190FDF3E94C189ULL, 0xE7C8C7B0858C8178ULL, 0x6261DC201D0B03BFULL, 
            0x1AB380A947E69876ULL, 0x51F7106B80B88518ULL, 0xBEF3D26AF588B35CULL, 0x83667EDAFEE888B3ULL, 
            0x87F3DFA19CCE0CD5ULL, 0x67C494F9415CC714ULL, 0xA79B17E11A3AE49CULL, 0x612452163A189316ULL
        },
        {
            0x68A062AADA173153ULL, 0x9AA30554B42B2E56ULL, 0x4604F5FE94D1DFDAULL, 0xD296C60DCC7DFB3CULL, 
            0x8474F40FAFE13419ULL, 0xB5760D64FD0269E4ULL, 0xF1D327198DCD86D6ULL, 0x78E6AE038877BEB3ULL, 
            0x8320081A60AFE238ULL, 0xCB10C44762E86A3AULL, 0x3C140F7BDB1DBC07ULL, 0xA042E4D154F11138ULL, 
            0xF6C4A857D3DC3F28ULL, 0x6A1267DA4C96A746ULL, 0x390931FBEACBA71EULL, 0x9216AADC52C7A6FDULL, 
            0x52D571E01C69857CULL, 0xB9B06D8D28D9B0DFULL, 0x4F917DC2A9DABE5AULL, 0xDA0BB41B1F2E0D6AULL, 
            0x5D200E2E2CF07B93ULL, 0x14095D87AEB5F0A5ULL, 0x087B9E05C2902A14ULL, 0x12F9D72DE663259BULL, 
            0xA6F0A9FC402F0B63ULL, 0xD0096515027E0F16ULL, 0x8E4A75A8E1D16085ULL, 0xF3919BFE86B47019ULL, 
            0xA4AAB5E20E7EC1D1ULL, 0x5C52D34D5687D366ULL, 0x72D633BA858504ABULL, 0xA1CFE7E2C86FEA76ULL
        },
        {
            0x18D2995C449C359CULL, 0x0B9576E7B28B4218ULL, 0xA3C2E1355A453EA4ULL, 0xF25BD221567440BAULL, 
            0xA04238C3CCE544ACULL, 0xC69203DC14FF8D0EULL, 0x36FD684245CB9926ULL, 0x3DE019F2C556086AULL, 
            0x36CE81210F747C14ULL, 0x2400BFF8FAE01C62ULL, 0x5159E1579DD92A76ULL, 0x5A2CA8B6E4157BACULL, 
            0x4D97121022109067ULL, 0x820CD03733E05FB5ULL, 0x7FA946D1C4463D48ULL, 0x09C542934B8C7791ULL, 
            0x2B6A967038FB9B3DULL, 0x1DCDC04E3791A5F0ULL, 0x530F709A547B696BULL, 0x222C05615D6152C2ULL, 
            0xE75DB7E3E7EF0F82ULL, 0xE90CE72C533A0146ULL, 0x386322032E6B436BULL, 0x0AA07D8EEA860175ULL, 
            0xE96A854489D6B9DCULL, 0x288F2014E2D9E63BULL, 0x71D0AF8E28629523ULL, 0x12F7BFF04595E8F9ULL, 
            0xEE0CC059C9C3EE1AULL, 0x1061AF119F794FCCULL, 0x73CBBE68C16B2D72ULL, 0xE91D8FEBB8354114ULL
        },
        {
            0x7655094D5BF45325ULL, 0x8F6BFCAAD33F45D2ULL, 0x315C97B8A30522FEULL, 0xA2373A555B6D7C84ULL, 
            0xA4A9C3474C40D932ULL, 0x59794B444E5E08D3ULL, 0x7F45F07C6F0D167DULL, 0x019A1579C4243D62ULL, 
            0x4AA20AC8C4229CA3ULL, 0x97732FF3E8BC7D9EULL, 0x6BEEF9074E127FE3ULL, 0x033F2FA2EDC40647ULL, 
            0x7A7A15E3953E736BULL, 0x5DFDECC3A09CC1E6ULL, 0x3662DD9C9F836DF7ULL, 0x1CF96F3C1949751DULL, 
            0x11C626368A4A3AD0ULL, 0x91F3B5A32520469DULL, 0x6657C2F1DAD47E9FULL, 0x969BB75157B2A5BDULL, 
            0x61A80E352615E0A8ULL, 0x7BD9D5C161236549ULL, 0x816D85611EA93D50ULL, 0x8313F08E51441ED5ULL, 
            0xA80ECEE569B00BEDULL, 0x2756C69C5ABE1D1AULL, 0xA8DBAB69902A74DCULL, 0x97E90B2069E3DD14ULL, 
            0x3B12AB9243901909ULL, 0x8259B5EDB77CBD52ULL, 0xF149A6F3D8244E23ULL, 0xDE6B28E99C69F6C5ULL
        },
        {
            0xAD6701B266AA0535ULL, 0xA3C964E5D9218597ULL, 0xB5068980E0D6FBB5ULL, 0x50019CA3B0A0FA58ULL, 
            0x8FFF3A48F2D64EF5ULL, 0x04E67C85206CB6EAULL, 0x3C8B4A4BBFBB4FDEULL, 0x0D91077127C40BC4ULL, 
            0xF2E269D933B1300FULL, 0x43E3929E11E997D6ULL, 0xD161EC9AEFF10585ULL, 0xCD6D897FB546E767ULL, 
            0x86B9611F4CEF405FULL, 0xF3E6EF1B63A912DAULL, 0x68D8138ECD0B06E7ULL, 0x6B9A3AD49D0EB300ULL, 
            0xC2CCFA35A14EE1FEULL, 0xD4149DA2654F3DFDULL, 0xE26A162C1A416F8CULL, 0x9501FE1345913F62ULL, 
            0xCE3472AB86B255DBULL, 0x7EDB5AA268930418ULL, 0x5342CDFEB71276D1ULL, 0x327325C1D4603218ULL, 
            0xB48EDB76A46EA978ULL, 0x78A0C660E63B8AD4ULL, 0x6C2FEFBA8B671DFEULL, 0x863188630BA904C6ULL, 
            0xCDB3256A89660A91ULL, 0xBA415E165C06DAE9ULL, 0x6E03C1E45726DFB3ULL, 0x0A0FBCEF6D34C012ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseFConstants = {
    0x3732215B91404712ULL,
    0x5CF233E4170C9AE9ULL,
    0xC8E4E5EF50B1016DULL,
    0x3732215B91404712ULL,
    0x5CF233E4170C9AE9ULL,
    0xC8E4E5EF50B1016DULL,
    0x1F2A511D5171CC3EULL,
    0x2D2717B8C9D8E700ULL,
    0x0C,
    0x7B,
    0x69,
    0x1C,
    0xC6,
    0x41,
    0xCE,
    0xFA
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseGSalts = {
    {
        {
            0x9131FDEA3804CA85ULL, 0x32E95B4414499CF1ULL, 0x4A8B9BBED213E3DDULL, 0xE6590C51D8F2CE57ULL, 
            0x040CE89527B847EFULL, 0x3C43E609935DC453ULL, 0xB3E0C1DEF3950B8AULL, 0x44D815482841645CULL, 
            0x8C0664D349526D87ULL, 0x0AD0E59268304BA7ULL, 0x8C1216BB2B9B45A7ULL, 0x564D34BE18865BDDULL, 
            0x34D0BCB62CB126FCULL, 0x4067A5BA3B9BB966ULL, 0xD128D23FA96B3CF4ULL, 0x2529CA64CE37CB19ULL, 
            0xCD5B4CFBFDB2977BULL, 0xED7E62BACFC09AD9ULL, 0x60CD693A723884E3ULL, 0x0286B444E41E982AULL, 
            0x268996CADFC13FF9ULL, 0x849874D6D112797CULL, 0xC52150857E23D68AULL, 0x5DB934B54A7714D7ULL, 
            0x5D5CECF7BDB2BDE1ULL, 0xCB874E8328372CD1ULL, 0xDBAD5D68389FB50FULL, 0x2BAD7A7C06B47B72ULL, 
            0x6B5C61593BDB94E2ULL, 0xD61195BF9D125E98ULL, 0x934C2E96EA12F849ULL, 0x273FEA10CE600619ULL
        },
        {
            0x817200D0E7A79785ULL, 0x935B4E5EFA2E9FEFULL, 0x2EF3FE1D049B4AF0ULL, 0xC7DF1882F447B7B2ULL, 
            0x9C9CF7D134A5D11FULL, 0x033904D2B4DF5C6FULL, 0xAB9B0C7ADF511977ULL, 0x7B07384455DCEB2BULL, 
            0xCCC599BBA3102A00ULL, 0x81359904C52AAC8FULL, 0x28AF119146338567ULL, 0xA3CA6E19FFC3DCFAULL, 
            0xB4762DDCAAF83BA8ULL, 0x153C82094AAF81B9ULL, 0xBBF047295BFBEB07ULL, 0x8A4F8969C0870CF5ULL, 
            0x57058089D6216FB4ULL, 0xDF19B6360B081C22ULL, 0x3880E0905AFA5FF1ULL, 0x1B511A16D6952964ULL, 
            0xDCCFBE38B53FF4A2ULL, 0x4CAA38BC32158D0AULL, 0xF88780F8383C4B76ULL, 0x552DAA5BCB0A6DEDULL, 
            0x351FE943AFC8ECBAULL, 0x85960456F38CD65AULL, 0x867FBA7CD6A0B94AULL, 0xD7AA32F3002FEA65ULL, 
            0x7513CA517539DA06ULL, 0x6ABFA43CF7269038ULL, 0xF5005EA45633627BULL, 0x81DFBDAC88026FE3ULL
        },
        {
            0xAA8B0EE7CC20A332ULL, 0x97E8A26C505A42F7ULL, 0xB414CE6FB3690F35ULL, 0xF53CECD03CAEFC68ULL, 
            0xF39017A77B9094B4ULL, 0x1C513BB7D6F76347ULL, 0xE2DCC6C3EACE13FAULL, 0x60EFA73C1A5CCA9FULL, 
            0xCBB4B31D5E4B4013ULL, 0x4EE6FC39CD2CB9A8ULL, 0x2030226CC1F97B32ULL, 0x39B7E219B4E96B67ULL, 
            0xFCA7D1EE776C1873ULL, 0xD07469371DA842FBULL, 0xDC9B315D855967C4ULL, 0xA447087F315DE3D0ULL, 
            0x3BB3DEB4719A0C93ULL, 0x985B1770D57C3527ULL, 0xD3F236569D1BC1A6ULL, 0xE0D0D0E0FF65D773ULL, 
            0x98100A7AADEA32CEULL, 0x1B718DE1086D755EULL, 0xE7210DB39058E60DULL, 0x740305D463737508ULL, 
            0xD5BA10DF1FF0372EULL, 0xF08BBA467A9C1347ULL, 0xD24DE4201FB3FDCEULL, 0xA49574E67BFECE7EULL, 
            0x66322E326C6D6BD2ULL, 0x9F288D5727E6104EULL, 0xA52AB8EA7632AB91ULL, 0x9FDCF0C8D5767494ULL
        },
        {
            0x6A2EFDFC64FAB62CULL, 0xAC95F28C1CDF6955ULL, 0x9562581A5F5EC7A1ULL, 0x2709018DC35D6D95ULL, 
            0xB5BEFCAF482CDD28ULL, 0xB51EC91C5786F2D2ULL, 0x2EEDD1FFA805EC8DULL, 0xA6FD8F0E5A70C5A7ULL, 
            0x68594FBF4AAFF615ULL, 0x188519CBB6B07BE4ULL, 0xBDF573EC54D8DB57ULL, 0x6A9895707F62F62EULL, 
            0x3B6A4DAC60F6F8C2ULL, 0x04AD4181849164F7ULL, 0xD2A6E198AE0A58F8ULL, 0x1B6E610FBD870CD0ULL, 
            0xBA744FB58ACB0E19ULL, 0x5E444B647C7C651FULL, 0x590996BAD45FDF94ULL, 0xCC1EE1A72615E5FEULL, 
            0x31771A0BFAF27E35ULL, 0x366A3AA7CEBA5A51ULL, 0x35F60BB85707EE3CULL, 0x3D65FABF550B0F15ULL, 
            0xF384A78D0BF644FEULL, 0x200CD7135D4AC6A8ULL, 0x271CCECC771F4C60ULL, 0x77C3703BD7FDED53ULL, 
            0x5872963048EA53E3ULL, 0x97901CA518D156B4ULL, 0x1EAC10CDD3CCD1B2ULL, 0x5D70DBCE37B2EAC1ULL
        },
        {
            0xF3FDC3A08AE7C189ULL, 0x95A9FF781F89E303ULL, 0x298302CB304FE4B6ULL, 0xA6128B92C38A7D21ULL, 
            0xA2304A56B61E2DBCULL, 0x5C3881880D95EBDEULL, 0x36A335C36ACD147AULL, 0x4757E729815688BEULL, 
            0xB9AD1064C4DAA01BULL, 0x43EABD82A2EB8290ULL, 0xE4EAC7E835B5577BULL, 0x899FF9C78638B008ULL, 
            0x693D02C751CF29F6ULL, 0x3BE445A6DA648A38ULL, 0xC79B30CCA46E69C9ULL, 0x5DB541E0D35D55B3ULL, 
            0xA1CAB2325D023BD4ULL, 0x91FD759D22F79BCAULL, 0xF0E00F1C1B2EEEB1ULL, 0x8C10A3884985B65EULL, 
            0x0CF42C7B158B4E82ULL, 0xA41271FCF5884353ULL, 0x3699B8F78749A939ULL, 0xB1F5E6FB9CD1B779ULL, 
            0x1A0CA039CB3CCD50ULL, 0xE7712C4E336C7FC1ULL, 0xA17F93FB00D10ED2ULL, 0x9CF244636E9BDF48ULL, 
            0xC264FC4EE6E52FF7ULL, 0x5FC96555EA6076F9ULL, 0x8C60295240DEC932ULL, 0x88C10C0EB4A90F58ULL
        },
        {
            0x51B27634AFC00A84ULL, 0x1B190178F08D257DULL, 0xD64024BAB94856C0ULL, 0x86333E5855895862ULL, 
            0x2EA5B204E7478D64ULL, 0x037522825A8AC9A8ULL, 0x376F94D20F0D430AULL, 0xAAED011BDA8396E6ULL, 
            0x2CF3599A9993AEC2ULL, 0xDDC3EA42E5079E54ULL, 0x8A65220D12ABD517ULL, 0x1615E766617792D2ULL, 
            0x1AE57BC021C16518ULL, 0x18A0501C864991A1ULL, 0x05BACA6FDEC3E773ULL, 0xE12B8F0A34E53D75ULL, 
            0x73DCF39C120CBE47ULL, 0x62491AF92FBAA832ULL, 0xB09DF10248B2DE7CULL, 0xE85FF94401AA622BULL, 
            0x0A49FFD5AA96CE02ULL, 0x110D3D5E8EDBCAB7ULL, 0xA0D07AD9D7CD38E3ULL, 0xA9F38F00134C0795ULL, 
            0x3F452702377F646BULL, 0x38068BE731FC8BB0ULL, 0x682BC7D13B567968ULL, 0x540ECD51C9DFB11CULL, 
            0xBE5FA7C5DB781C2CULL, 0xCFA7050B2BD45535ULL, 0xE20B06AF0B9B55D2ULL, 0xA727A19EAF47B366ULL
        }
    },
    {
        {
            0xE6D0FD51813A83E6ULL, 0xC07D1B6DF2E21019ULL, 0xE767522C0539100CULL, 0x35D2BDAA5775A106ULL, 
            0xD59C3CA699E7BE96ULL, 0x5BEF3E16E6B82E7AULL, 0xF03E8EB63D5EC450ULL, 0xB572F61187CB093BULL, 
            0x9E7038D9B6C428BBULL, 0x57DD5A973B21ACB0ULL, 0x7F16EE174472E46BULL, 0xA57ABD23900C5331ULL, 
            0x9ABAA35E334A9133ULL, 0xCBC7BA1559D34E01ULL, 0xE90CE8BF7A3CE4E4ULL, 0xBCA6CCC3029BC1DBULL, 
            0xA9145A2B76424D1CULL, 0xB478616EA52C75C1ULL, 0xF8C9DF7C87C577B0ULL, 0x6C1C6D0E6D55F2A7ULL, 
            0xD9100DA8916CD21AULL, 0x93F7C1374756FD45ULL, 0x752DFAC6BC0F683AULL, 0xCBB035F40A05B8B9ULL, 
            0x2A7F7C83A9477F02ULL, 0xADA98AA03CBCAF2FULL, 0x7F99AD27713CD726ULL, 0x5CEFA80D69A8E9C4ULL, 
            0xFC518EACCAF0C693ULL, 0x6F9B3F8F6C93E4B0ULL, 0xE120BEC090D37D5BULL, 0x42C4265E4C0CF1E9ULL
        },
        {
            0x75E8D0726F4B4298ULL, 0x7A34321140056476ULL, 0x96E197B208D2E52FULL, 0x640A7DC5E80BE2F5ULL, 
            0x644CD9778E499F46ULL, 0xE90927C51A54A024ULL, 0xC6F07BE11EA793EEULL, 0x6BA3AFD0173CBDA9ULL, 
            0x945A33399E952521ULL, 0xE1D235F56828B609ULL, 0x5A6A5D6FAFEC0495ULL, 0xB64F812BE064BD13ULL, 
            0xAA68168802BC4E66ULL, 0x5C7AAB5F73F7AFC0ULL, 0xABC0F5B87985B3D2ULL, 0xF3742AC849BF7306ULL, 
            0x11813E70411CB1D4ULL, 0x6D04574D3CC1289EULL, 0xEC3B11E32E68FC55ULL, 0xC790D865D1ACA0AAULL, 
            0xC5673A8EE7830555ULL, 0x938264694A5802F9ULL, 0x54DB1D1F513CEE99ULL, 0x02AB31B9D9D56A98ULL, 
            0x180A331C789F3452ULL, 0xB210E0C9C57A4814ULL, 0xC8855D3126EE5F95ULL, 0x69E467C9DAAB8A31ULL, 
            0xEFFA2A84E7B951B2ULL, 0xAEE6B549EDE85215ULL, 0xAB5F43588D289E30ULL, 0x1DB8F2A6257277C6ULL
        },
        {
            0x47470CEF5D905CB2ULL, 0xD77A5B7D8BA52E91ULL, 0xD844235F1CDF7C7EULL, 0x2CAF86734244A4BEULL, 
            0x8CDBD33935C741F8ULL, 0x6AE9671ED98419CCULL, 0x79D8DFAFAE33C30CULL, 0x7334D03F260893C0ULL, 
            0x1D0AEF0102C69C00ULL, 0xA82210033B5CF477ULL, 0xF305A8EDC73F0AFAULL, 0x0050546150F9AD49ULL, 
            0xFEA594E36CB944B2ULL, 0xAA092D833A069B21ULL, 0x51784C710BEF1DF4ULL, 0x87BD7CDB8D9EA63BULL, 
            0x71BD12647B0E7D46ULL, 0xFCF6D5B36DB2DDE2ULL, 0x84E13C91B0B5AECEULL, 0x4FF3F7589006E59EULL, 
            0x59175A71594BAC83ULL, 0x5D0E9D7CFC6232DEULL, 0x46D66DC76EF6EC34ULL, 0x77A3F4D3C734D697ULL, 
            0x7FCEB18D41DDFFFAULL, 0xD1633E3AE64746ACULL, 0x944A4ED04FFB75A8ULL, 0xCA99B6CC1587AEC0ULL, 
            0x20367FD9613B69D7ULL, 0x51CE7AE4BF766ABDULL, 0xA965D408DB634A0AULL, 0xE4A0AF2CFC2AED8FULL
        },
        {
            0x3B725BF55B68A91EULL, 0xFB97BDEF92E944B1ULL, 0x84C8ED2799B11669ULL, 0xE7253DA43F3D9557ULL, 
            0x11506BFBDCE569DEULL, 0x9D3F4A90F4F3E858ULL, 0xA8A8CB829430BCD2ULL, 0x506CEEC5C3EA7158ULL, 
            0x2893BEE03BB01C36ULL, 0xF8E72CD32B8C6756ULL, 0xB54FAC7FB5B6D5C3ULL, 0x8AEF5EDEC0A62024ULL, 
            0x62C511AE3226D862ULL, 0x563442CE37AE427DULL, 0xF2D8770BAD7F53D5ULL, 0x504F58581A798F5DULL, 
            0x6D264DE297C39DA4ULL, 0x248423DA42424C23ULL, 0xEB3690EEC1067E67ULL, 0xED5E3BF13B0B9C07ULL, 
            0x285BCDA0B8EF73B4ULL, 0x8EBC34E18DE8A003ULL, 0xE2E24EBFD4055B9DULL, 0xE4924EA8B082C14EULL, 
            0x2B0B59DA289193E6ULL, 0x08D6844252ABF9EEULL, 0x296D05485D2D2B5BULL, 0x8858DD363F452DECULL, 
            0x9D9930173035D578ULL, 0x2D1216EF912600DBULL, 0xCB30A280E06C83F0ULL, 0x74E15C284E1F13F8ULL
        },
        {
            0xDF8EE497DA27C43EULL, 0x31C707CBAEF3B9C6ULL, 0xD766986DA7933711ULL, 0x845AF741C88B1A22ULL, 
            0xBE207B5B1AB4264AULL, 0xC578EE3EE4B9B059ULL, 0x8718A439AD3B2052ULL, 0x717C513E6C36FBA6ULL, 
            0xD194978BF9DE9400ULL, 0x0AFF5088B63B117EULL, 0xEBFF9C6E6A596DD5ULL, 0x5786D417CCBB1AD6ULL, 
            0x040F3C37F6D525AAULL, 0x476E5DDCD8A10298ULL, 0x9C37ECFA728B4CEDULL, 0x77856184D4B90BF4ULL, 
            0x48683C33FEE0EA2BULL, 0xE1F69FBF4DAF647EULL, 0xC43609135FA2A02BULL, 0x6CC24EBF9C60BC16ULL, 
            0x30C8EF54F60FE772ULL, 0xB2085DD8EC183C63ULL, 0xCE8D84C43EEF7CD6ULL, 0xB969FECE1D1C7301ULL, 
            0x40AA6D8DA5226011ULL, 0x34D9D983834208D4ULL, 0x9B17948C4A841B49ULL, 0x8B8936E19E8ABD10ULL, 
            0x5FA6CA41C20A339FULL, 0xD0BEAABFA500320AULL, 0xDB223F52BDD73CDBULL, 0xCE36FF1F58BE8F09ULL
        },
        {
            0x9B7B3881445B25DCULL, 0x308D2D464487B38FULL, 0xC23ECF72D6240A0FULL, 0x1E13297B47249E62ULL, 
            0x6C2EA6B9BE096208ULL, 0x191405B8A2ADE9C4ULL, 0x576F0174B6748679ULL, 0xDA0BFC077F77396DULL, 
            0xC75D4703CDC6A52FULL, 0x7EBEC81BE25BAA7DULL, 0xEA6BECED3DE310E1ULL, 0x58469A5D985AA754ULL, 
            0xC7D8BEFA570877B4ULL, 0x71BD5513770FF338ULL, 0x47800B9340EB6039ULL, 0xB60A814E7E7AA5EBULL, 
            0xB061C488CF343273ULL, 0x769DF7C7B60CFC01ULL, 0x27E35E3CA4FC81AFULL, 0xE2E7B50F1CED9F3EULL, 
            0xB5D312A9716BCE38ULL, 0x1173A8460057C2CBULL, 0xCAAF2CD9080A377DULL, 0x67FB2258DD3C034CULL, 
            0xBE74474DD5FC9FFFULL, 0x2784364CAECD67C6ULL, 0xCBA36C266E62B0AAULL, 0xD41E1B15F6BD36CAULL, 
            0x7DA4A2286069EA73ULL, 0xE0B1EBDBEA675224ULL, 0xA7A1BE8ECE4CDB43ULL, 0xE8D1D2FC8446AD19ULL
        }
    },
    {
        {
            0x2C87105D93F099BAULL, 0x5BAFB9EB40082D38ULL, 0xF59D7ABB73A6CD31ULL, 0xE95658DDEA3EB977ULL, 
            0x4E1A543E15C40A40ULL, 0xF480F0EDC177DE2FULL, 0xCA73B86FC5CC4696ULL, 0x3BC3D8FCD4EB4485ULL, 
            0x553B1D2564142F1AULL, 0x5667F9D683961DB0ULL, 0xFC99D9EC75A45FD7ULL, 0xF4152C2501F3FB40ULL, 
            0x80E79F11761381E1ULL, 0xD8897D4AF35A2931ULL, 0xA2857FA643AF6FB4ULL, 0x7E75A77C34852509ULL, 
            0xB5C2B06560EC2F08ULL, 0x0667FCC8431DDD34ULL, 0x3E42204A038F3480ULL, 0xA61C3CB8D88D60E3ULL, 
            0x2D78AA001782D004ULL, 0x37A88BDAC0446648ULL, 0xD6F4D55A1AB8918DULL, 0x0F79435E2775F762ULL, 
            0x9DF36B6E310894C7ULL, 0x1F497234AB896D20ULL, 0xD5C888A4A093E454ULL, 0xBFE4CD6150440586ULL, 
            0x9B33EBB1423909FBULL, 0x08EDB28F1C9C13CCULL, 0x456CCACE897D0C86ULL, 0xB4A40E14EE92C367ULL
        },
        {
            0xC5EAACEB5F21E348ULL, 0x51995980109809EFULL, 0x3BB1F0A03BEE8226ULL, 0x4B55A00776ECE28AULL, 
            0x3091CF91F32FB5B7ULL, 0xAD177C852C1460DAULL, 0x59DA24F65F0E1C18ULL, 0x9DC68E84730AE48EULL, 
            0x9271042302E3CB1FULL, 0x9D667E9A4489E788ULL, 0x6422004D04E299CEULL, 0x8897825A75833865ULL, 
            0x20B72CA4DF0B37A5ULL, 0xECD85EE24D04E800ULL, 0x63E86A422DB3BAB3ULL, 0x093D6F6F6B02B976ULL, 
            0xD406EF54E6D25556ULL, 0xD37243673D9416E5ULL, 0x5FD68CDD06362609ULL, 0x49FFB5E5E6B26461ULL, 
            0xA677DD37FA244382ULL, 0xC7F4EB5FDFBD6761ULL, 0xB649C4DF7279ACCBULL, 0xC1831D7FC85161C4ULL, 
            0x94EBA5A9784EFC11ULL, 0x649C87EC137877A3ULL, 0xF0E3594DC57608DCULL, 0x7A8CEE7E7230DB29ULL, 
            0x34D977B900EA8B7BULL, 0x27DD289553D82B28ULL, 0x9DB2101CDCDEE78DULL, 0xE1EE7B378A7F65AEULL
        },
        {
            0x203D18B4FCFB4D6AULL, 0x021A58A121F9A9ACULL, 0x760055232029BF9BULL, 0x103525BFCC957480ULL, 
            0x1BF7CF21CF4F06C3ULL, 0x8240EFB81B4BF64FULL, 0xB66244729D951622ULL, 0xA60B6E46C0E870A9ULL, 
            0x4A17C0572CCC86F6ULL, 0x3591E296CE031C7FULL, 0x279FA2F79400EA52ULL, 0xFB643138F1AB608EULL, 
            0x05AC13D2426D9335ULL, 0x3D7C745D814AD210ULL, 0x7AE735CAD81CCC0FULL, 0xB5672F2B8550D753ULL, 
            0x485DB014FECD75B3ULL, 0xE36CF0B7A899CDB9ULL, 0xD6DB541FFDC87D9BULL, 0x8A24434F1E4B2D7FULL, 
            0x2CD47A9239A4AE80ULL, 0x4A6805528FF81AB4ULL, 0xE7C224E7AB120C2FULL, 0xCEB6EE6DDBD543FFULL, 
            0xB6CC06442F672585ULL, 0x02FB135B0C36C8A4ULL, 0x4982372BD90884EAULL, 0xBD98E50FDD7FAC4BULL, 
            0x5356B3F74D56A78EULL, 0xEF4E684F05AA9A0CULL, 0x0254E7E70F2C0888ULL, 0x900995C3ADEFC112ULL
        },
        {
            0x9990E87654C0845BULL, 0xD915C7193A6F9A60ULL, 0x9E9E86BBD188A444ULL, 0xB03694F51A0E8970ULL, 
            0x48488837D8AC3B87ULL, 0xDDD4D9344CD16901ULL, 0x71DA79D21C6A59BCULL, 0x93C57CA77B538845ULL, 
            0x43BA8644402F96A3ULL, 0xD22F33D24BB2F8A7ULL, 0x19EB82103D2A9944ULL, 0xE90AF3915E558FD3ULL, 
            0xDB97769F0820C62EULL, 0x9A8875DCB35E5265ULL, 0x1B69D89880F136FBULL, 0x01FA8E59147B791BULL, 
            0xAF2375E14C4FE72BULL, 0x7F69C3D0D3E2954BULL, 0xCBE1926C64698213ULL, 0x1A29F17DE7FB3022ULL, 
            0x6448506C57D27307ULL, 0xA4738971CCA1FA88ULL, 0x6F3B4BD6C9A37576ULL, 0x236E904061CB4114ULL, 
            0x34A2352D32EE84D2ULL, 0x5AB051A04D4D1E59ULL, 0x21060B52AAD97472ULL, 0xBDA97BC0ED5F7C9FULL, 
            0xEC9993B201551256ULL, 0xD575E9A46A8A042BULL, 0x609AFD780F06B6AEULL, 0xEAD3F757C4B3172BULL
        },
        {
            0x67629F61928B91B9ULL, 0xAAFF44C60547BAE9ULL, 0xA99676EB5EF0D4C5ULL, 0xF574F1E1BDF63F1CULL, 
            0x6F3C4A49C2A5E45DULL, 0x746CD9A4DB506194ULL, 0xEC39D2CF06916FD4ULL, 0xD0164D228A9203ACULL, 
            0x15768445C3640CC3ULL, 0x32DB983AF87666F4ULL, 0x3624BC9E38477418ULL, 0x58398F99C7770A71ULL, 
            0x4AA3744D74D2F3D3ULL, 0x1B627C21423DB288ULL, 0xEC8BEC9EB20DC20AULL, 0x5EEE70737D2DDEAEULL, 
            0x217906D1941CB08DULL, 0x85113C5E9C198936ULL, 0x605317F7C92986C5ULL, 0xBC6167DF8B413793ULL, 
            0x1F3C635C99D8E993ULL, 0xF8A53F3DD2ED1F9EULL, 0xDB4CCDFD11DE8967ULL, 0xCD4EAF9000EBA07DULL, 
            0x3AF2321DAF53784CULL, 0xFB3E345931F1603BULL, 0xF28943BC8DB9E239ULL, 0xED401DB51556490DULL, 
            0x37413B9374F5791EULL, 0xF785596A76D71918ULL, 0xF4AD1422D461AB6FULL, 0xD4416FA130376AE3ULL
        },
        {
            0x61DC2F387919C523ULL, 0x27192040B00AE706ULL, 0x1337B48975E4EBA1ULL, 0xC68B40901EA7674CULL, 
            0x75D6C1E477C50B0DULL, 0x511A9B59073341B8ULL, 0x5E969F7DF22E3812ULL, 0x77661A7C00279D77ULL, 
            0x4E5290A3793FA820ULL, 0x5F951A5006BF9E2CULL, 0x3E3476A045D524A3ULL, 0x4B4553A0B27D6028ULL, 
            0x2D623468C6AA97CCULL, 0xDC147EDE747AA9AEULL, 0x599010BE52F968B3ULL, 0xCFEA75AB7D974388ULL, 
            0xC43083875A98D18CULL, 0x6AB60A3090CE0E9CULL, 0xE08DC8896036C870ULL, 0xB76B7FCCEF6BCAE2ULL, 
            0x46207C2256246068ULL, 0x2AA1CAC7331C17E2ULL, 0x8F07AF3DF78E1EE2ULL, 0x0836B44B6FBA1D89ULL, 
            0xFC4D46E943531800ULL, 0xC776FD6C2B365D5AULL, 0xBD4913B842505963ULL, 0x12AC053E0D3C7CBEULL, 
            0xB51F8E7C5951B423ULL, 0xDD1BACC745B0EA9BULL, 0x9EE91FFD524D836CULL, 0x123F7E0C79F532E8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseGConstants = {
    0x8EAF4E3C1674F8A4ULL,
    0xD7F07B0D4B595F21ULL,
    0x0537400DBF18DDB5ULL,
    0x8EAF4E3C1674F8A4ULL,
    0xD7F07B0D4B595F21ULL,
    0x0537400DBF18DDB5ULL,
    0xBBEB01DFD76FF2B0ULL,
    0x037B0C30CF61F860ULL,
    0x29,
    0x4F,
    0x02,
    0x5D,
    0x91,
    0xB3,
    0x2C,
    0x11
};

const TwistDomainSaltSet TwistExpander_Lacrosse::kPhaseHSalts = {
    {
        {
            0x834B30F4E1741D18ULL, 0x599A383A487111EAULL, 0x6453B137A99058BAULL, 0x7654BAF45CDCB0C0ULL, 
            0xDB07A04CAE268303ULL, 0x9AD6599E10DC857BULL, 0xA462FD82473B3B07ULL, 0xAFAFBF575B7E84CFULL, 
            0x40BB224C824A5EEAULL, 0x6827C30B24B44A56ULL, 0x4DE6F0086033981DULL, 0xCC581F1F39FB54E1ULL, 
            0x5E1286D30CEB7711ULL, 0x91AE2829A2B898F0ULL, 0x71E14D9796C8C267ULL, 0x9012325A44D64CEBULL, 
            0x51BF7D6C7396F112ULL, 0x836F6AFA19F89939ULL, 0x9B6B402963D50429ULL, 0xC648922608F92933ULL, 
            0xA83C9C60F9E09F0CULL, 0xA35FA981D54502DEULL, 0xC18E3308EABC31E0ULL, 0xEA3A992D0711823DULL, 
            0x5684E94A90A40CA4ULL, 0x00327FB40B23B975ULL, 0x9A98BDC5DA814071ULL, 0xC7EA15E09835BBD3ULL, 
            0xB499C178A477B5C9ULL, 0x3B6ED145BD1D6219ULL, 0x607839C0F45ED7D4ULL, 0xC5A5CFBCB07F72E1ULL
        },
        {
            0x657CC2B67D74B4D7ULL, 0x018C4D310EFF809CULL, 0x421F798671F1934FULL, 0x5D441AB053FE6205ULL, 
            0xBF3B9A45C46FF0C1ULL, 0x02464639DCF84492ULL, 0x23FBABBC0EF8417FULL, 0x50D2F32A036D56DFULL, 
            0x932B585CF0B4A482ULL, 0xE6D3DF75DBBF2F76ULL, 0x3E3C83D708F43EEBULL, 0xD2959224A374C358ULL, 
            0x24B9BA597CBC760DULL, 0xAD23E728E7A34394ULL, 0x752435F9D8165073ULL, 0x4E6BBAC33288FDE3ULL, 
            0x102031FB1041EE04ULL, 0xAAB4641C88E9881CULL, 0x01CB59CA7BA4B0D0ULL, 0x6D2742F1EE739A82ULL, 
            0x6C449C062B274B31ULL, 0xE94A18306ACDD8FFULL, 0x7FD2C737FD64D658ULL, 0x8C4DF60B4265E4EEULL, 
            0x444595A42E677A97ULL, 0x9308CB2E69DC40AAULL, 0x2C9C722A214C120AULL, 0xF979102747DEDEC4ULL, 
            0x1FCECF5DDA1D4C45ULL, 0xC4EA9593141F8741ULL, 0x5CF0902F801CD085ULL, 0xF641032114605580ULL
        },
        {
            0x1479C1C0DCA821CBULL, 0xA2825F7478A82E46ULL, 0x0A0937D152A94D5CULL, 0x73B15DB0CAFE3283ULL, 
            0x29E9CE6152CA5783ULL, 0x4829660B662BDB7CULL, 0xE1EE6CD588AE5FF9ULL, 0x9DE3A51F96C84389ULL, 
            0xC3D8D7002F80CA89ULL, 0xB1CB153002DE1577ULL, 0x7A2506BA12B75C88ULL, 0xB5E41BAC26C386EFULL, 
            0x56933391CB922772ULL, 0x908BC6DCB4278B92ULL, 0x4B8A2DA4416C16F7ULL, 0x4A560B9313F75780ULL, 
            0x3486BC254C3D7450ULL, 0x3391DBED1561B89BULL, 0xBEBF0A52F72EAD8FULL, 0x4302E3391A9C060BULL, 
            0x131071F1E37EBADDULL, 0x6881D35025FDFD07ULL, 0x94C5E1BB64BD29D5ULL, 0x79FF50FF6C7B6859ULL, 
            0x4489A10927846EFBULL, 0x634FCB633B28D8B9ULL, 0x5BBF12CE6B559E03ULL, 0xEDD457E059EFDE68ULL, 
            0xC8CE6B0612530F30ULL, 0x2DA63D213492DE21ULL, 0x52F52B59BBA3FEB6ULL, 0x64B25FE39F8857D2ULL
        },
        {
            0x31F39FE60763E07CULL, 0xE5C55DC31D3300E0ULL, 0x51E75A82B81343AFULL, 0x67E7FADC4F460519ULL, 
            0xE63C331DC072AD8EULL, 0x83F2CA9A2331E8B2ULL, 0x222A3A25106B6C5AULL, 0x2ECBB8D87C1A0C65ULL, 
            0xDCC43100F3368347ULL, 0x4D2C360E22446164ULL, 0x6B442B18AC81879EULL, 0xC54A4D0E0DB27D4AULL, 
            0xCC00753081AFDCBDULL, 0x52A4D68D4D26D1E6ULL, 0x06D31E4CE99913CCULL, 0xD6E7A7591A41BC01ULL, 
            0x1D1967321E9A2421ULL, 0xA1FBE47B26889D11ULL, 0x1999FC95FE0E3834ULL, 0x49120B7990EAD1A2ULL, 
            0x6FE6B2B93634342EULL, 0x7DB3F33C944B4A0CULL, 0xB9E075D539076FC9ULL, 0xF0C5AD88866841D0ULL, 
            0xC9424DCA03D40B12ULL, 0x7C7A9EE32917BAE8ULL, 0x41AC6E14C0175B04ULL, 0x3D9516E4928EB06CULL, 
            0x8D4A93F7CEA96446ULL, 0x58F6F8CEACD5D5F8ULL, 0x6B163D10AA62AB33ULL, 0x8BEA78FB0B80FFA2ULL
        },
        {
            0x0C07891D8FDC6717ULL, 0xE3AC9EF0F28CFF8DULL, 0x539242867A1AD83EULL, 0xCB698F7C6307D30FULL, 
            0x2240948202875F34ULL, 0x32F39E22F562453AULL, 0x886925B499FD5D7AULL, 0x14394BD0045FBC7BULL, 
            0x3E76633F784E8D3EULL, 0x2088E1B9385BA301ULL, 0x792582F4A5B29E11ULL, 0x21A4C2DE6F36D3FFULL, 
            0x713AA3558184A0C0ULL, 0x02247112B1D3ADB3ULL, 0x783D3A11F453128BULL, 0xC5F75D1E0AC70CB0ULL, 
            0x06D03D19B555965FULL, 0x1909EDC018590776ULL, 0x96DDABDC105FA93BULL, 0x9DE9FC55C4789A38ULL, 
            0x520DADEA520A4940ULL, 0xAC7A0FF6E79103A1ULL, 0xD90FF5C5303CD9C2ULL, 0xDBC39AD1CBB6E02FULL, 
            0x2C853329C1201A3DULL, 0xE86CA92682791AFDULL, 0x742D4F0CFA272166ULL, 0xE184D17AF042E714ULL, 
            0x8BE11B0FB42893FCULL, 0x2F6CF437E96BDE20ULL, 0x3ADC21C87DE72B37ULL, 0xE3E6F84BE90B4EC0ULL
        },
        {
            0xFF9AA22CD2B05568ULL, 0x0832043E30F9A94EULL, 0xEDA3939014A76BAAULL, 0x02C1A03335DD9E3CULL, 
            0x1CD527EC941ECD43ULL, 0xDC7ED6774A2E4684ULL, 0xA8D1AFBDC25F9E8EULL, 0xB12F987EF09F90A4ULL, 
            0xE121E9D7E0CCC5A0ULL, 0xF38E31432CB01A77ULL, 0x1DCD313B9AE072DDULL, 0x96102CE448DCDCECULL, 
            0xA7715EC1B223CCE7ULL, 0xAA31EE4506AB6F09ULL, 0x07B58F677B59A13BULL, 0xF97E11698CB62CCAULL, 
            0xB5A8136BC247C171ULL, 0xB6DC21D51F1BB1B1ULL, 0xE11161669E7D7D11ULL, 0xE4DC7283B956EA6EULL, 
            0x6B43E3D17690A62EULL, 0x120F5DFC4EE135DFULL, 0x7CC0883A39DD5D63ULL, 0xA8F123ABF0070BBCULL, 
            0x31F8E3C85524EA1CULL, 0xC04FBC84A84DB926ULL, 0xB7762D1C518DD2F2ULL, 0x8DFB9F88C51B4D9CULL, 
            0xFDD52FE376607E90ULL, 0x784FD6BAC1EE73E8ULL, 0x3D40AD62AE90CD4CULL, 0xD6F505935251824CULL
        }
    },
    {
        {
            0x62418F0F1A82C3DBULL, 0x7FA7259DFB3A9D71ULL, 0xEE0F51BAA96BF0A8ULL, 0x0E1BACAB5A233498ULL, 
            0x4DCBD3A61EEED221ULL, 0xB717AE0A8872FFF0ULL, 0xD35B3831D7C9E3FBULL, 0x8EF44DF1A009BCA2ULL, 
            0x8CDC7900F8160DA9ULL, 0x7766706D5E7D29D2ULL, 0x204D8EFA4DA2841CULL, 0x7D600E6D1532BAFCULL, 
            0xBB7DD7038E8AD964ULL, 0x62DFDB5453186183ULL, 0x785A08EFBAC2101BULL, 0xCB2C5D5AF4172F50ULL, 
            0x43895F45D6EA8539ULL, 0x01EA35A9BC656B85ULL, 0x78EB3367AC403C1DULL, 0x3D6394E0459A28B9ULL, 
            0x3BCCC6128CDC1412ULL, 0x641FD01F718D5A14ULL, 0xD1A48192C60E3B2EULL, 0x7AF5B4CD312BC44FULL, 
            0x52321151CEEADDC9ULL, 0x9E65CD4884261BD3ULL, 0x5B0197E897522C38ULL, 0x507899ABB0369FD5ULL, 
            0x54207DDCC4814B3EULL, 0xFB0495213F934DAFULL, 0x2F0071C3CC2961C7ULL, 0x6B10597310041227ULL
        },
        {
            0xB282F791AD585584ULL, 0x3945E887B9A8C583ULL, 0xC4DD4E391078FFBAULL, 0x57C2F787796D99B8ULL, 
            0xFFF527025ADDA672ULL, 0x0A59186F407E1ECBULL, 0x2DC3086C14E87494ULL, 0xB68922154B412018ULL, 
            0xFDB8E2ACFEA74E4CULL, 0x37705DABD4E7C5C2ULL, 0x231B604CD0EA77FCULL, 0x40DF865E62BEACDDULL, 
            0xC12485B07097F595ULL, 0xEAEADE40389F6FEDULL, 0x1088F219D580D262ULL, 0x921ABA0625C1813CULL, 
            0x8B27A28BBF7A99ADULL, 0xA0E6015BD6AD8DD8ULL, 0x3D3DFCCA6BD622D6ULL, 0xE73ADB79DB9A900EULL, 
            0xA3694CCC6D8D86C3ULL, 0xD707EDF8994F8F6AULL, 0xD32E59E729DE49C1ULL, 0x82AC1D59FD7F06E4ULL, 
            0x4BA0241F94EF770AULL, 0xAB80BA8137D747D2ULL, 0x31AEB2BDA7A819A8ULL, 0xDD4BE04ED79D27C0ULL, 
            0xEBAFD5DC8DDBB56BULL, 0x45D2DA5893DF43B5ULL, 0x748416F5B45BB9E9ULL, 0x63FFC799FC3F1D73ULL
        },
        {
            0x475891F9F2E367C9ULL, 0x1535716082F5BF23ULL, 0xB6C1B8E8741D4670ULL, 0x0685B9FD9A9CDCAEULL, 
            0xADAA219FF4C2DFDCULL, 0x58E66C0297E217F2ULL, 0x1DA8970ED86709D0ULL, 0x41127C9B60ED52EDULL, 
            0x765719AC8A47E009ULL, 0xE7D148657AB7192CULL, 0x219C04CE8F3676FAULL, 0xA59A663E03AE6E32ULL, 
            0xA8B0A680C02673E5ULL, 0x69351DE809C52576ULL, 0x32DE94B38799B49AULL, 0x5133CEE5FC98706FULL, 
            0xB6099523259446A9ULL, 0xDDFF095D5FE7A5B0ULL, 0xFFD2232682F087DDULL, 0x62DDAF7F53A54E91ULL, 
            0x56ED4A83578BF0A7ULL, 0x4ED88DB156D1FA97ULL, 0x3FA39B953A532106ULL, 0x72B8A3E1514437D8ULL, 
            0xD56DE98C1E5F3575ULL, 0xDF028853991B4E9AULL, 0x352BF0DF9BA88215ULL, 0xA1F7993422CC7A87ULL, 
            0xDB4C00D9CF81F7FBULL, 0x98548EB2B79CF17BULL, 0x04C6FB5DB8E92F3BULL, 0x78DAB2C416370F7DULL
        },
        {
            0x2DE6BA3DAE94FD54ULL, 0x64281F3523CFEDECULL, 0xD249F104329D5ECCULL, 0xF2EA82F97868F6DBULL, 
            0x3D449FD811BD111AULL, 0x4CB0123B5D506411ULL, 0x58E3BA9C86DE7148ULL, 0xEF10B5388B98209AULL, 
            0x68B385536F115EECULL, 0xABBDCA74B1F28531ULL, 0xDF4F5E66285480E8ULL, 0xC41B9286A76E9EF0ULL, 
            0xC9310795F53B344AULL, 0x7847D0F54B07049DULL, 0x230C736C9394BB54ULL, 0x3FC44D56AB28B9F9ULL, 
            0x9EC749CADB4873F6ULL, 0x4437D396031A35B2ULL, 0xF0DEF8FAAE7FC721ULL, 0x8A5B54544B87BC5FULL, 
            0xA3BE25FC7D31773EULL, 0xF119EA07735CF1C4ULL, 0xCA660DA858C58E61ULL, 0xE385A72B41116980ULL, 
            0x9EFC42F81308509CULL, 0x4291A69A295F9634ULL, 0x0E91FC5BEFD8FB90ULL, 0xD201D55575138968ULL, 
            0xE888994053DE18C1ULL, 0x941CDE889C4CD840ULL, 0xFA3B2635734DA2BBULL, 0x9F20D5EF0F0EBE3CULL
        },
        {
            0xAA9E10DEB171C87EULL, 0x375B5936873D7D4CULL, 0xEBEA14C7D3BBAD72ULL, 0xDDC6E948F59F1583ULL, 
            0x1DAF4DBB5E5A3500ULL, 0x0B5C7E0106182BCEULL, 0x8EECD54CA2531012ULL, 0x15F03573A021D150ULL, 
            0x47A432EE3155BEF0ULL, 0x643E9512E4F1848AULL, 0x6626AE4601E16260ULL, 0x416DCE7C3F3E1C5DULL, 
            0x096B7C044576BC6DULL, 0x82612566F97BD486ULL, 0xF55C1D840696A7DAULL, 0xCCCAAD36E801CAECULL, 
            0x34FAC452050CD047ULL, 0x580DC85A9F0E7583ULL, 0x95EB241C0B4E46A7ULL, 0xD97C95D60C5E3BA9ULL, 
            0x69E32B8A47FC7F2AULL, 0x2B3F56CBEE50DB4CULL, 0x1EC1070A50E3A814ULL, 0xF7EBB039B26C5198ULL, 
            0xA9493E6974E730EFULL, 0x8B669A95A4EE72CBULL, 0x484E874B49BB81ECULL, 0x13411156ADF0ED4DULL, 
            0x458E823322E681B8ULL, 0x671A34A680FEBD3DULL, 0xB9027E34A3A94EE1ULL, 0xD6D276BC2A62BDCDULL
        },
        {
            0x24A44E2EA253545CULL, 0x8B786433CB18E4EEULL, 0xE6DF091336A56378ULL, 0xE80476CEA315C4D7ULL, 
            0x18755AF8D2ACE9B8ULL, 0x220FA7F790428CC5ULL, 0x8BDD6529F9C19336ULL, 0x84D328E0E287E707ULL, 
            0xEBD175763EC14F67ULL, 0x437B167EC6AB7254ULL, 0x63486431345B8620ULL, 0x8273CC8BE6F421F7ULL, 
            0x22A19C89A0EC8F1BULL, 0xB5D782BCD47B47D7ULL, 0x3D1A7F5CA6B90B3CULL, 0x63428A1835F92EDDULL, 
            0xBC60FD046C0E7218ULL, 0x5EE2A3B8290E9217ULL, 0xD668A92D5B1F5F74ULL, 0x0A22BBFCB57AD3D3ULL, 
            0xBED9BEB53F319D32ULL, 0x460C8774FC226877ULL, 0xC6CAAE57F6BB15E7ULL, 0x8EFB18D691073B17ULL, 
            0xD5B7DC889BAF6B53ULL, 0xBDE1C838281FAE0EULL, 0xE0F5002B7C5E175CULL, 0x33CD6D9EA98B674CULL, 
            0x6C1F2BB3B0AECCF1ULL, 0xD28DFE7BDF88FD76ULL, 0xF193A3A58588FADFULL, 0x2C9F42BCF91B3425ULL
        }
    },
    {
        {
            0x44A03327B43FEE5FULL, 0xE245EFF9AE031C30ULL, 0x4EDAF2D3E8577BA3ULL, 0xD10822D43F610F1CULL, 
            0x0EDC85C9CE07F0FDULL, 0xF898B06320462203ULL, 0x71A8377FDC5D4820ULL, 0xB9667BB37BCD7BB5ULL, 
            0x023F30CD9B2243EFULL, 0x0CAD21AFA795AD95ULL, 0x7BE2AA33E449373DULL, 0x312244F6911E481DULL, 
            0x5B1A242BD641D32DULL, 0xEDF20762D01B813FULL, 0x829D2C6156587043ULL, 0x2A8E0CB172BF1CE7ULL, 
            0xAABE0BB7A3394CBFULL, 0x372749022555E9B3ULL, 0x29C9B7139C4115A3ULL, 0x7C5A4D7A6998552AULL, 
            0xCAA7EEB86D7425F6ULL, 0x61EEB28CF9F66EBCULL, 0xCAFF24CB018F8224ULL, 0x4C9EC88CF2B0E552ULL, 
            0xED3B85C1C2B5CCF1ULL, 0xF05D5877022A533FULL, 0x2B4EA02847A43639ULL, 0x50CEBBE0D61224A3ULL, 
            0xFA4DD236D2E55E83ULL, 0x57E4F4C77603CFBEULL, 0x8ABF65DA9BAE93DFULL, 0x86A1945FC9BA9CD1ULL
        },
        {
            0xFA70D418829BFD46ULL, 0x7EB4EF505C6DB41BULL, 0x28815CD1E49F3239ULL, 0x1AD1982F0C8A4CF9ULL, 
            0x8EB51EAAAA0F879EULL, 0xB9C25177841EB681ULL, 0x25B00C3BDC8E68CCULL, 0xBA39EFB15B2CDC1FULL, 
            0x7B23911EB712F6F9ULL, 0xFA55DE5ED291C2ADULL, 0xCF610E0D1B8C5068ULL, 0xDC29412F5C1E705AULL, 
            0xB72A784B14019526ULL, 0x70055494C109851EULL, 0x16AEC0CBFAAA78E2ULL, 0x61A0952388722A3CULL, 
            0x352AB9CC63ACD919ULL, 0xE1472F0E211E6064ULL, 0x87D3DDD19B3C1880ULL, 0xF075761EAE1AD805ULL, 
            0x5677ADF86AA995FAULL, 0x76B51A17C1FDF5AFULL, 0x3BB00321C9F0232FULL, 0x27FF59DBB30C93FDULL, 
            0xE2ABCD121E5FE3ABULL, 0xCB7EE0D0087ABC52ULL, 0xBCCC34F648118142ULL, 0x3F35BD79DF1A89D0ULL, 
            0x374BF090C90C10C1ULL, 0xD8E93DF7E8356D33ULL, 0x040819B1CFA7A503ULL, 0x66A57BFDF9935727ULL
        },
        {
            0x482E7B42A16DAF76ULL, 0xA3EA4719B027E866ULL, 0x2EA87C2EE17A982FULL, 0xC917997FB9B71CEAULL, 
            0x83B7A8BF25F79F45ULL, 0x2DE9377786C816D6ULL, 0x62F925AA0CFA0339ULL, 0xF7791C517AC0EFE8ULL, 
            0x31EC1B5B0866356AULL, 0x790DE4194858CE32ULL, 0x13ADD2829D350DB3ULL, 0x201F5540E86F7625ULL, 
            0xC4F6F090357208B9ULL, 0x835534B78B556932ULL, 0xD509EA2F7F936B7EULL, 0x8CB5FEC4836B2F23ULL, 
            0x6D503C592FAA97E0ULL, 0x1BB7A33C42FABE72ULL, 0x877F95EC0A066FB7ULL, 0xF40AC821D1D26C35ULL, 
            0xAB2EEC4826951C86ULL, 0x5D71CF1B73C0C71FULL, 0xE30194B6B15511E1ULL, 0xD1F474A72ABC9B71ULL, 
            0xCE17396E323D5821ULL, 0xC755EEF9097577B5ULL, 0x8EEB82357EC0D4A8ULL, 0x30A0F997229B0154ULL, 
            0x159DDBCEB753CF01ULL, 0x31F22226A7AA820FULL, 0x1CBCCDC33427F3DFULL, 0xF060E8161A7F0E4AULL
        },
        {
            0xF063CFDF40C5564DULL, 0xEBE7A8839003440BULL, 0x5C421257656E8E44ULL, 0x958AF4601E860D9EULL, 
            0xCB456CAE623904D3ULL, 0x4FF254C231AA2262ULL, 0xBF9CB5F9A08A5336ULL, 0x83D8A8F9210BE254ULL, 
            0xADFF79FD8E2548E6ULL, 0xCAB640447C4CAF0BULL, 0xF8C21BD71BA63472ULL, 0x1F87C0698853A70AULL, 
            0xE93966E97A3DAA25ULL, 0x47DAD8BB4EA8CE95ULL, 0xB39BE6D48D8B0A3DULL, 0x9C5615C4D5D22FD2ULL, 
            0xDCA146DE5313E084ULL, 0xCDD055FAEF468444ULL, 0x257141F1CB867295ULL, 0xAC4DE528B804BBEBULL, 
            0xF1896E1BD8775689ULL, 0xD73ABDDE0AF375D2ULL, 0x0A370B74F68F66FFULL, 0xEC95B798787B408AULL, 
            0x77EF110AA6BB9524ULL, 0x57B84339F075848FULL, 0x1A653D59D945D0F2ULL, 0x71F2931977681547ULL, 
            0xE8AAD842EABF6424ULL, 0xC61EA080EEC69C54ULL, 0xF8E3720DA9DADC7BULL, 0x00622B2B2A717149ULL
        },
        {
            0x585165B34DA0593AULL, 0x107A574B05170AFFULL, 0x633734AF4E98AEF5ULL, 0xB8172D6188DEB5CBULL, 
            0xDEF07D13E6221B85ULL, 0xFDD748F25F8A2BA9ULL, 0x93088EF3749087E7ULL, 0x605591E1CBFBB235ULL, 
            0xED8C4DF0A80D63AFULL, 0x9DA7F40EF065CDEDULL, 0xBDB659FD2A019C17ULL, 0xCB2F7CB694897C12ULL, 
            0x97A5D127B3AE226DULL, 0xD83C1479EEBD6393ULL, 0xA5184625CE34E411ULL, 0x843526ACCCEA2D58ULL, 
            0xEFE3E6CE69C14F6FULL, 0x5FBD4852A7213308ULL, 0x73261A4553F6A8D4ULL, 0x61F6713F6B26DAC3ULL, 
            0x521B04181F4FAA88ULL, 0x5EE1780CA0ECB7E5ULL, 0x46300E58C2F6C04DULL, 0x8E19E3017008DC41ULL, 
            0x74D529AE2BF8B489ULL, 0x11E2768F5F2D1FCDULL, 0x4840C26758E1DBEEULL, 0xFE11CA7E442E35DAULL, 
            0x5C7B3A64BF2AFACEULL, 0x0C1EAF1CABE24A7FULL, 0x140D55A2CBB572E8ULL, 0xC54AF902D7A37DF2ULL
        },
        {
            0xE3A91EAE3BB20AA6ULL, 0x6410C4EDC2C11250ULL, 0x9711A33343BBCDEBULL, 0xB8833A8801A52BB9ULL, 
            0xBA27E6AE28AC6078ULL, 0x511BAF1EE1922011ULL, 0x5915F64976EF1719ULL, 0x46FA1CD8EA142B7FULL, 
            0x61B40F7444CDE9BAULL, 0x939A454DAE473996ULL, 0x83DB7CF8782EE6FAULL, 0xD7346C5F2FD62E71ULL, 
            0x190D93C16FF63868ULL, 0x99A8D4B2C6762F61ULL, 0xBE059AB6F78842F6ULL, 0x31DDD0C45E640084ULL, 
            0x0878419A065C109FULL, 0x2577D5AAFEF5049FULL, 0x1B04F71D9C527B57ULL, 0x95D55EC7459D651EULL, 
            0x015D9DBE8458DBF9ULL, 0x2A7F5A47548AD0DBULL, 0x1CB029C18B740079ULL, 0x4EF126E290522E56ULL, 
            0xF88852CF2B80D8DBULL, 0x54A87495248C2344ULL, 0xF1AB90B247094530ULL, 0xADD3CE6DEE5C67C6ULL, 
            0xE1D46AE470E10822ULL, 0x36BB1419FC3D69B9ULL, 0xCBD0994FDFE002F0ULL, 0xE4BE79CB781338A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Lacrosse::kPhaseHConstants = {
    0xA819CEF9F50DB3FDULL,
    0xBA353E13E448A753ULL,
    0x33B93C2D28A5CEE0ULL,
    0xA819CEF9F50DB3FDULL,
    0xBA353E13E448A753ULL,
    0x33B93C2D28A5CEE0ULL,
    0x968CB686F4B09DA3ULL,
    0xCE7BA1CE00D0AF22ULL,
    0x77,
    0xD6,
    0x74,
    0xEF,
    0xA2,
    0x05,
    0xE8,
    0xE9
};

