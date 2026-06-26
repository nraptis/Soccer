#include "TwistExpander_Boxing.hpp"
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

TwistExpander_Boxing::TwistExpander_Boxing()
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

void TwistExpander_Boxing::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9455517822533609096U;
        aCarry = 16476001119735891844U;
        aWandererA = 13215575850047982354U;
        aWandererB = 11662754268036139679U;
        aWandererC = 13653447591714702105U;
        aWandererD = 16976729530840452481U;
        aWandererE = 9591568574053528251U;
        aWandererF = 13922560456740664050U;
        aWandererG = 9602894416322036639U;
        aWandererH = 11224720977435057097U;
        aWandererI = 16255858388499307742U;
        aWandererJ = 15081326571216072423U;
        aWandererK = 12883446963887482099U;
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
    TwistExpander_Boxing_Arx aArx;
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
    TwistExpander_Boxing_Arx aKDF_A_BArx;
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
    TwistExpander_Boxing_Arx aKDF_A_CArx;
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
    TwistExpander_Boxing_Arx aKDF_A_DArx;
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

void TwistExpander_Boxing::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12081797534111134619U;
        aCarry = 16568721165687753960U;
        aWandererA = 12659326742429577513U;
        aWandererB = 16594604147702774441U;
        aWandererC = 12263338785589570889U;
        aWandererD = 16515084626329970099U;
        aWandererE = 9784411666857829069U;
        aWandererF = 11396099811903224472U;
        aWandererG = 14139528102304430876U;
        aWandererH = 14615151339441342381U;
        aWandererI = 18197922052877310627U;
        aWandererJ = 16301102770681802834U;
        aWandererK = 13031361605149244168U;
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
    TwistExpander_Boxing_Arx aKDF_B_AArx;
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
    TwistExpander_Boxing_Arx aKDF_B_BArx;
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
    TwistExpander_Boxing_Arx aKDF_B_CArx;
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

void TwistExpander_Boxing::Seed(TwistWorkSpace *pWorkSpace,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneH);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneA);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD);
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneG);
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
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistExpander_Boxing_Arx aSeed_AArx;
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
    TwistExpander_Boxing_Arx aSeed_BArx;
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
    TwistExpander_Boxing_Arx aSeed_CArx;
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
    TwistExpander_Boxing_Arx aSeed_DArx;
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
    TwistExpander_Boxing_Arx aSeed_EArx;
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
    TwistExpander_Boxing_Arx aSeed_FArx;
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
    TwistExpander_Boxing_Arx aSeed_GArx;
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
    TwistExpander_Boxing_Arx aGrow_AArx;
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
    TwistExpander_Boxing_Arx aGrow_BArx;
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

void TwistExpander_Boxing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Boxing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 9913148743475243183U;
        aCarry = 16283518936399080028U;
        aWandererA = 17544063659129842907U;
        aWandererB = 14561115670594985265U;
        aWandererC = 12398567554551180865U;
        aWandererD = 14978666673970469470U;
        aWandererE = 10556379215652147712U;
        aWandererF = 17827804558913215566U;
        aWandererG = 12053218991501592485U;
        aWandererH = 13174120388707046640U;
        aWandererI = 14199001796339692817U;
        aWandererJ = 16301807823642803944U;
        aWandererK = 9959400748493220663U;
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
    TwistExpander_Boxing_Arx aTwist_AArx;
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
    TwistExpander_Boxing_Arx aTwist_BArx;
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
    TwistExpander_Boxing_Arx aTwist_CArx;
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
    TwistExpander_Boxing_Arx aTwist_DArx;
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
        TwistExpander_Boxing_Arx aGrow_AArx;
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
        TwistExpander_Boxing_Arx aGrow_BArx;
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

void TwistExpander_Boxing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 0, 1 with offsets 2293U, 2122U, 1859U, 5208U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2293U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2122U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1859U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5208U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 2 with offsets 5213U, 246U, 3494U, 1618U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5213U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 246U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3494U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1618U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 1, 0 with offsets 2619U, 1485U, 1422U, 3356U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2619U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1485U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1422U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3356U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 2, 3 with offsets 4834U, 7271U, 6208U, 2350U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4834U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7271U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6208U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2350U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 with offsets 1769U, 1267U, 942U, 19U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1769U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1267U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 942U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 19U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 1, 0 with offsets 1550U, 545U, 846U, 1873U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1550U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 545U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 846U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1873U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 3, 1 with offsets 1852U, 1249U, 1739U, 183U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1852U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1249U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1739U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 1, 0 with offsets 549U, 994U, 1209U, 1359U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 549U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1209U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1359U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1158U, 1101U, 182U, 969U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1158U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1101U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 182U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 969U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Boxing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 0 with offsets 6859U, 6058U, 660U, 7237U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6859U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6058U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 660U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7237U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 2 with offsets 1289U, 1752U, 7494U, 1785U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1289U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1752U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7494U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1785U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 3 with offsets 7721U, 6217U, 7059U, 146U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7721U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6217U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7059U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 146U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 1 with offsets 4843U, 1520U, 6871U, 4533U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4843U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1520U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6871U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4533U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7030U, 2086U, 6535U, 4432U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7030U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2086U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6535U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4432U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1825U, 1212U, 563U, 1660U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1212U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 563U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1660U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 234U, 699U, 333U, 1950U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 234U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 699U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 333U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1950U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 870U, 310U, 1377U, 69U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 870U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 310U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1377U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 69U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 548U, 1790U, 1299U, 1306U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 548U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1790U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1299U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1306U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 [0..<W_KEY]
        // offsets: 1185U, 962U, 763U, 575U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1185U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 962U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 763U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 575U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseASalts = {
    {
        {
            0xC433C38C2167A179ULL, 0xB2D435DC1F4FF492ULL, 0x22E9CA2B81134E6DULL, 0xE99F68F12019CFB4ULL, 
            0x423767D11AF7C71EULL, 0x626D21B4203884C6ULL, 0xFBB99392D614F868ULL, 0xEB303E50FA5DE53BULL, 
            0x90444F7B9716B4A5ULL, 0x27FC8E5561574F02ULL, 0xD288FC27C3C8AB11ULL, 0x0E32E8934E204D1AULL, 
            0x3A1DE101347F52FBULL, 0x55255FE195EB8DA3ULL, 0xCC1FC7C18AADA316ULL, 0xFD0AEF0AA7ECF3AEULL, 
            0x922C65E1116445BDULL, 0xE62585A8D4643D2AULL, 0x7FB3B79AF140CF67ULL, 0x872D63DB386FFA53ULL, 
            0x7965A048B6DA1E2CULL, 0xFE438782FCB07F15ULL, 0x7D81B462716AF916ULL, 0xB7C2477287E6A0FBULL, 
            0xFE46A418E5677516ULL, 0xAD79DB0D6E791140ULL, 0xDDB6CD5054B603EEULL, 0x9C74B575EEF248E8ULL, 
            0x2BCA3CA85DBFBAC4ULL, 0x2498C1AE5D900A00ULL, 0x762A1F15A2925A2CULL, 0x6307B338E17CA66DULL
        },
        {
            0x1952146A785B5991ULL, 0x70855CAB755C38FBULL, 0x9B2FD37E1830A966ULL, 0x6B6DBDEDF8C80D72ULL, 
            0x846089A8667FB3B2ULL, 0xD5A364834DD8721DULL, 0x2FDFC54121FC7FFCULL, 0xEAF9FA251819DBC8ULL, 
            0xD3DCB5F04264F397ULL, 0xF8D1E10F247BBAE7ULL, 0x87E9E87A7D541EA4ULL, 0x0DF066F704C99375ULL, 
            0xDCC1DD52DE0E4631ULL, 0xA8215BC55BB6584CULL, 0x270C6853E67DAD83ULL, 0x8BC27CA093288B55ULL, 
            0x8BC946545D8D4B5CULL, 0x0F9ECC01B06CE75CULL, 0x976FBF12A37A23B9ULL, 0x525C8A72EF81D252ULL, 
            0xFBECB38272F83E30ULL, 0xB036CD4E93B52F0FULL, 0xAA536812B3F44085ULL, 0x671B4C029BA06022ULL, 
            0x4ED612D30913120DULL, 0xBD4B75DC6CC235E6ULL, 0x90FDEB4DDBEABD2AULL, 0xDC09475E7663A7C2ULL, 
            0xC57528243365C5FEULL, 0xE5DE894FB1E8FB55ULL, 0x2E6BB0C0B1D9BAC9ULL, 0x8B3F59C0DD59E68FULL
        },
        {
            0xDD1B16BCFB97E2F8ULL, 0xC66DB04A35AFA858ULL, 0x048EFB85B6D389F6ULL, 0xF9BC07F231E77552ULL, 
            0x7BB9B1771D48497FULL, 0xC7D655A2601835CCULL, 0xF65BB11F35D871D1ULL, 0x5EAF5FD0FD8338D8ULL, 
            0x0B45EA4DBAED4D3BULL, 0xEDAC490C502D5BD4ULL, 0x4BC5911905B12DF6ULL, 0xB920CF8045471EB9ULL, 
            0x2E252B0DD5C6983EULL, 0x38BCBD8AD80A705EULL, 0x98DBC529512E2252ULL, 0x451B58C4A54A36BFULL, 
            0x4BB88B57B5AE8FD7ULL, 0x4082063F5E7835AAULL, 0x45C264DED8DE073EULL, 0x24B96DCAA2AA297CULL, 
            0x239923E50A3A4320ULL, 0xED4D9D3399907D41ULL, 0x85B6A231773B4DDEULL, 0x1F97D8A7C35182B5ULL, 
            0xFDBABCC479A43063ULL, 0x52D5D8CE35683077ULL, 0xE6B15A73BDE9066EULL, 0x02605D82637C6D8FULL, 
            0x599037A716D95355ULL, 0x18FBBC903BD645ECULL, 0xB479E5B0FC4B479FULL, 0x028E36FD979B6A51ULL
        },
        {
            0x37489F6D21E9980FULL, 0x06977ED2A09FEDAFULL, 0x78AD0F362A350D0DULL, 0xF8AD66CC1EB9465AULL, 
            0x66C5C499016B62C9ULL, 0x4275678C7A0D71B5ULL, 0x8A19B9EF765911ACULL, 0xC5A355C87B8CC07CULL, 
            0xED7CB885BD8249D1ULL, 0x73A343C58524EA2BULL, 0x0AF923CC370420EFULL, 0xDEDCD1B1457DD246ULL, 
            0x8CF998AF91C20740ULL, 0xD72EAD087698C6B0ULL, 0x14D5B8DC84CD05C5ULL, 0x8ED40D642E766613ULL, 
            0x23B1B2784AA729C6ULL, 0x3A7E835771DC197BULL, 0x7E68B3757C9B5D52ULL, 0x10F15650AB700C2DULL, 
            0x151522B24D3B30A6ULL, 0x6817516FA9E3694CULL, 0xE6B9B188734900AFULL, 0x531D5052D7F55BF0ULL, 
            0xCD1804B733F05D9BULL, 0x0FA93552530B0284ULL, 0x9F8F5886F780832EULL, 0xF72A4713BE1C2930ULL, 
            0xE623D2B5D1821D4BULL, 0x1B789511E725B57FULL, 0x96BCDECEB728B7B6ULL, 0x8E5DB676F2E38A16ULL
        },
        {
            0x61A0E4CD647BCCCCULL, 0x7FC990ACA23D4780ULL, 0x232CC2F58AC83F72ULL, 0x672E8D9719BB8671ULL, 
            0xEDFC6172E5E7552DULL, 0xB4FA7CB5847F290FULL, 0xA7786578FB543F2BULL, 0x2AF0EC669CC19F52ULL, 
            0x6E3CE6DEDD84205CULL, 0x22B3D3D2E7DE88A9ULL, 0x7289D193A45E5D53ULL, 0xA61DF2B688F63AADULL, 
            0x25D3CD1D7A1D3C51ULL, 0x16B6F0CC0EA11E64ULL, 0xAEDE99305C5E6774ULL, 0x0F4EF72581DF2097ULL, 
            0x9B39C57D0875AD9AULL, 0x991311D8F2876682ULL, 0x25311A276CBB686BULL, 0x3410C6C1F9399A4AULL, 
            0xEA7DC540058493C0ULL, 0xC6581262B3B00FEEULL, 0xCD5B60146CC6CF1BULL, 0xA3822F0DBBAFD4BCULL, 
            0x07580A08937D3C3DULL, 0xB869A02B8CEF2430ULL, 0xE99D36579FAABA05ULL, 0x7CA8C4E27436E527ULL, 
            0xEB492BAF205D605BULL, 0x0FAF424DE6676F3CULL, 0x68E6F80475D25AC8ULL, 0xA49D7B2FAA2BEF83ULL
        },
        {
            0x25F0C2CA75E3502DULL, 0x6209348AD4EEBE1FULL, 0xE5F28D4E7004CD15ULL, 0x7F575968385D6949ULL, 
            0x17F155B79777648EULL, 0x4E599CCEE1A73704ULL, 0xAD03221C2ADE8214ULL, 0x3009491D5BD6BB18ULL, 
            0x6685413AF933EED9ULL, 0x0C3CAEC88005B433ULL, 0xD476E5A2FAD611E9ULL, 0x8181CC6B0C0DF91CULL, 
            0xD06CC2D9BA0A77CDULL, 0x4B89209B1AED41B5ULL, 0xA47FF7EFA59EAE11ULL, 0xBCFACCBA5EC54396ULL, 
            0x7D354056A460DCD8ULL, 0xAE4A565128334153ULL, 0x5663183C21EB4BB7ULL, 0xAED8AAB8F8B3F7BCULL, 
            0x915BE8512B1920C4ULL, 0x675D9F0417893BFAULL, 0xC8A6EA72DE0269C9ULL, 0x2AEBEFDC159D786CULL, 
            0x5AB0016241C9DC16ULL, 0xF520E188ECDFC9EDULL, 0xD137214750F1B84AULL, 0x79A7ECF07466E83CULL, 
            0x171BA6C079BEA182ULL, 0xE50078B1E5948319ULL, 0x91A674723AA9DCF7ULL, 0x9EB0309C739152B3ULL
        }
    },
    {
        {
            0x9D49C20A24C28A90ULL, 0xD992498656026ECDULL, 0xBF461DDF5566CE58ULL, 0xC2228923F3E642ADULL, 
            0xDFA8BD506B3BF84EULL, 0x85E6DE61E5AA3E96ULL, 0x52E629FE3C183895ULL, 0x26C0B80629FF60D5ULL, 
            0xE3BCDA69CEC9568BULL, 0xE30151E8F9D24A49ULL, 0x0886B55596587C47ULL, 0xADE4F983D1B3CC7DULL, 
            0xADC10D54BD1A7086ULL, 0xF781024B2CABEA84ULL, 0x0BE34DF6402B8F18ULL, 0x10F8548E4F53FEB6ULL, 
            0xB5B39AFB9DC77562ULL, 0xB18FC7ED170AAF6FULL, 0x472F0E4F12B13568ULL, 0x8B31BAAB7E5FB857ULL, 
            0x6EB53F246EDAB3E5ULL, 0x61EB51BBA9D50322ULL, 0xA300E61C76EC2F11ULL, 0x1D92581079C0C89FULL, 
            0xF4CA7EC7822A2589ULL, 0x71309C815A531062ULL, 0x49EB7CB752444CA6ULL, 0xE557353145D99E16ULL, 
            0xA0DDCECC03A0289CULL, 0xB56CEE8F658E18CBULL, 0x48549841FAF74249ULL, 0xC4DDC3817829F4CFULL
        },
        {
            0xEDEBB01434AFD54AULL, 0x3A010482DDEF3EE4ULL, 0x4CF36C0B19F7F925ULL, 0x02CF0F3501ECB0A8ULL, 
            0x2F0CAD713D1DE34EULL, 0x3475090E09B4A5C0ULL, 0x99F8E5D1E027670DULL, 0x7DC8ADE6E04BF4C0ULL, 
            0x4EEA28D3CBE36D16ULL, 0x1A4AC9FF36E8E0A6ULL, 0x483385D366187E97ULL, 0x556B518EF4D20CD6ULL, 
            0xCC79FAB22CC12497ULL, 0x79A0F66C8E0A9709ULL, 0x7A84377A716DC377ULL, 0x70B410D5C2D9AD0AULL, 
            0x9F6F1925EE2FE0E6ULL, 0x52B4D88E6367F3F1ULL, 0x9DF7FBDAC955BC0FULL, 0x7E6AD44ECAB55C80ULL, 
            0x5CFB23D45A8E341CULL, 0x3CC43CE31B3BA5E2ULL, 0xA95503DC4C3BE504ULL, 0xC732F264873852FFULL, 
            0xCE2C5598FF149F51ULL, 0x7687ED452BF04158ULL, 0xB0652BC8B2A3F026ULL, 0x5A5F0885CC08E24EULL, 
            0xBDA3D89697B8DCB0ULL, 0x4AD34E5EF9C274AEULL, 0xE44415920A8ACEA5ULL, 0x6A8A37833B0726E3ULL
        },
        {
            0x321ABB8C51A32629ULL, 0x17D3A3A075160BD2ULL, 0x071AC99B50DE69F0ULL, 0x2FED60A8C7520E7AULL, 
            0x20E4C66F9BD87F99ULL, 0x44BA56762FDC4597ULL, 0x04775404C2C6356CULL, 0xBD6F3B3CE76C0337ULL, 
            0xD926C530D6C648AEULL, 0x558E6AE2DC210288ULL, 0xDB49D5956F576636ULL, 0x2F28E200D6A6EF13ULL, 
            0x4430B86843206E96ULL, 0x7C65296E7012E5DFULL, 0x083F9A36B3580DDDULL, 0xFA5FE786EE3A53F3ULL, 
            0x1C128E4D8A0A2B15ULL, 0x003295E487D3EDB2ULL, 0xF3A23334376AFC09ULL, 0x79AB359F1AB6C0B6ULL, 
            0x0818A16FFD3AD06BULL, 0x808F347EEE31766FULL, 0xB9989CE3FE16C158ULL, 0xCA39298AD370BF65ULL, 
            0xBD15CA9677E5AB7DULL, 0x5E78E0153635D25EULL, 0xCC9F3B999C4F87F6ULL, 0x1785645EE23914EFULL, 
            0x55547B580E7FD19DULL, 0xF42493FB21297EA6ULL, 0xE34B5504F8233C36ULL, 0x539CAE53284BCF2FULL
        },
        {
            0x0618AE5DF184AF0EULL, 0xB5288909D97338EFULL, 0x7596DC0E7CB4151BULL, 0xC2CF6102B80F7418ULL, 
            0x1779E689C163E8D4ULL, 0xC7A3C58E3A813C49ULL, 0x32CB75275EE278CFULL, 0xDE57A583410E4C78ULL, 
            0x99AB11E911C88C90ULL, 0x1B7CFBC2519B5611ULL, 0x8358646A7FBFAF2AULL, 0xC084669D22890A41ULL, 
            0x1E658CCD4E17EB3EULL, 0x401D3007B9894BB1ULL, 0xD514D7D33C3CECC7ULL, 0xE190935389FB3A44ULL, 
            0xB23B5E3C15A22CC8ULL, 0x71124588931A680FULL, 0x47C9CAFEDC91ADCFULL, 0x82F4F6B966873B67ULL, 
            0xBC63271002784E3CULL, 0x0582DAE8F1D2B605ULL, 0xA3334D6E1A9834F5ULL, 0xB518E868DA920BB6ULL, 
            0xBA5A8EB9A2F82465ULL, 0x549602805BB62A9BULL, 0xC76FCABF811EC51EULL, 0xFB80188E4492FD47ULL, 
            0x61F8BCCAF07D3AEBULL, 0x1925F9182374354CULL, 0x1A214C45C3FC8C3BULL, 0x6D6A462DF0D7B4B3ULL
        },
        {
            0x21DAF0BF418761E9ULL, 0xC21756F20F7FEBCFULL, 0x802DC8E205A523E6ULL, 0x0A45EB0E891C5F54ULL, 
            0xA8C167D6B44B8411ULL, 0x1D76E27E5DE51F35ULL, 0x2594AB8543702777ULL, 0xEF7D9C43667D8D37ULL, 
            0x6651179188A7D351ULL, 0xC45863E6BE1BB262ULL, 0xF161752D26B53863ULL, 0x1EECD49163568B4BULL, 
            0x25A48D66227CBC1BULL, 0xB4D2938B29D087A8ULL, 0x6D149F4124A7EDB6ULL, 0xFC426D6A25831384ULL, 
            0x6472C0AEA477B389ULL, 0x4D753E593CEBC2BCULL, 0x262FCCAA77FB0E8AULL, 0x848725788AC9FDEDULL, 
            0x9DEFD23CD6731235ULL, 0xF542037757C3BFC7ULL, 0x2909DE2006498CA3ULL, 0x70B995E3F8966CF9ULL, 
            0x61B0232CA0F110F9ULL, 0xAB9B05A0431CF4FFULL, 0x1BBF037F57853E3EULL, 0x96F4D20DD53FE655ULL, 
            0xC169065DE5BD2D0AULL, 0x2301F26EDB1822F3ULL, 0xA0D1341F0E400930ULL, 0x8F0D5B6C739DB035ULL
        },
        {
            0x06727847E35636B2ULL, 0x4EDBFE98B6F4FBA7ULL, 0xA9AAB9529E713E9AULL, 0xAB495D8A05DA0783ULL, 
            0x1E5E557D543F5F56ULL, 0x2BDD6441E4D4756EULL, 0x06539068277EF4E9ULL, 0x71DA7207AE122179ULL, 
            0x2BF53EC18856250CULL, 0x6A523E262F7744CBULL, 0x2B64BFEE065695FEULL, 0x395B246612AB4322ULL, 
            0x230803D45B7ADE64ULL, 0x6B3B351644055647ULL, 0x35AFB163E8A2DADDULL, 0x3EFB3EDF1EFAF030ULL, 
            0x0DCBC06F187B3166ULL, 0x8A8ED62D16EF6FD4ULL, 0x8024C6FE80A66284ULL, 0x55A81F46610A0111ULL, 
            0xF582EE6F087FB122ULL, 0xDEE525FC2C7BFD50ULL, 0xF0CB9A4DE021BDC3ULL, 0x7D3963B3550B1750ULL, 
            0xA061B367CFEE27A9ULL, 0x774EC5BA6A887366ULL, 0x6A280B7B86EA43FAULL, 0x733739BB9D2863BAULL, 
            0xEB5E49A5BC8E67FDULL, 0x8D57D805DE80FC1AULL, 0x28569330809F5F21ULL, 0x018B5EF0E54830B1ULL
        }
    },
    {
        {
            0xFEFDBAE7244D9C4EULL, 0x9A98DE40E86CC161ULL, 0x667D61CDA75CED3BULL, 0x2A6C12CEB5D1F99EULL, 
            0xB8FA409BD4EDCD6FULL, 0xF2F02AA02E3922DAULL, 0xEAFAF9F0AB9D3528ULL, 0xB5B1F1A9F688C08CULL, 
            0xEF6812E057D41E67ULL, 0xB0C483B35082A5F2ULL, 0x1328D935D2FA9A4CULL, 0xEC116D502C04F977ULL, 
            0xF0B3AB0773C8BF4CULL, 0xD09A87166026E548ULL, 0x3E4B38428D9BE892ULL, 0x1F99A796AA8DD0D8ULL, 
            0x73EA3481E70BE75AULL, 0xE3047FAB8F7A8FEDULL, 0x90AEDDBEE74364D2ULL, 0x04E9DD109AE1BD3FULL, 
            0x01E22A3992083487ULL, 0x7C2EE22E82DCD07FULL, 0xB70E38F09CB4C297ULL, 0xCFF5E338A7590203ULL, 
            0x5C93959C3BDF5AD0ULL, 0x1FD7C8600D9C16B7ULL, 0x768CBA6410DC7CB9ULL, 0xF1475ECE0CC982AEULL, 
            0xA50070F75356E4C1ULL, 0xD5B969BCA51C5592ULL, 0xE7F596BED563ABFDULL, 0xE31B78EC3D35181AULL
        },
        {
            0x89A3933EC4377477ULL, 0x6021897A84AC6F77ULL, 0xEDE377EAE47F10A4ULL, 0xFE1C74350BC0EC81ULL, 
            0x67CA057FF7F1A7E9ULL, 0xC1211024EE680BCFULL, 0xFEBA9915B71323D5ULL, 0x27E2F61D7C5AA3DFULL, 
            0xA60459C3FBD27E75ULL, 0x650D2EE2331B1927ULL, 0x4B422C94345094DFULL, 0x88FD6AC12A32B5F1ULL, 
            0x6F830F7264180D5DULL, 0xB8C8B93C40B4A9A8ULL, 0x97E63AFE85510BE1ULL, 0x16BDB3F7C1867DE3ULL, 
            0xCBA81178CC32F714ULL, 0x37FE9571FE03865DULL, 0x6903D609A40ADCDEULL, 0x9CB780AEAF5D4C37ULL, 
            0x6007256AE1CD3200ULL, 0x2338AF10BED22652ULL, 0x86C42C372CD19C6CULL, 0x1C3AB5896E49E475ULL, 
            0x67A6D64989EAEABFULL, 0x7EB8760B967F7AEAULL, 0xF86846400C3478C0ULL, 0x3786FCB7C31D0A38ULL, 
            0x696F05DD94BFE08EULL, 0xF4779870611EF9E3ULL, 0x41469A0C3F67580CULL, 0x5E951BCE8EAB4FA5ULL
        },
        {
            0xE03B684F3781B983ULL, 0x9D82AB8CB57955A7ULL, 0xE0999B07EBEADCE8ULL, 0x4CF764AFA28A3381ULL, 
            0xB5E8634E968E5733ULL, 0xBF8CA860C9021727ULL, 0xE8DB103918A35580ULL, 0x80CFC6F5F1030F9AULL, 
            0x7ED8286CF04D9CA2ULL, 0xFB8D379FC4ADAEDAULL, 0x0F4862198C7B5704ULL, 0x57A32D5EBD78AD5CULL, 
            0xFAC1468510DC2FBEULL, 0x76F77288E347E220ULL, 0xF027CEA114AF816CULL, 0x43F0F9CB098FF958ULL, 
            0x93A7775CB987D5ACULL, 0x7877BA236A769BF8ULL, 0xB9CCD0DB58624084ULL, 0x4AAEDF7818A4AA45ULL, 
            0x571F5BB297A17ECAULL, 0x34C76C3E01567DD9ULL, 0x914DB748E1176CC5ULL, 0xD8E242D656BB76A1ULL, 
            0xD8346D5F21B76C75ULL, 0x80CFD2E419E9BFD5ULL, 0x093C5200373DFA07ULL, 0x1C968877F243D200ULL, 
            0x34841968020C24CCULL, 0x91F7452CEB2347DEULL, 0xA62504B285B42BE1ULL, 0x6CC27B4DFF850073ULL
        },
        {
            0xC1F3D590E3316076ULL, 0x4D183F6CA6594605ULL, 0x622CE6C0A1E5A673ULL, 0x0F71E5AD76E0A973ULL, 
            0x1B801D4B63328E14ULL, 0xC1DDFA77AEFF0C42ULL, 0xBE87D94B0F565859ULL, 0x2710C570CDCE593EULL, 
            0x89F2200B939B99B8ULL, 0xF0113C502231D203ULL, 0x341C6B7D55896CACULL, 0xF3D262BC8C2833BDULL, 
            0x726D9470ED66C677ULL, 0xD69DAD8C9BA0ABD6ULL, 0x15BBB5C97F753AB7ULL, 0x934D4F53278D8826ULL, 
            0x6381472A51361693ULL, 0x032C7DF905C39334ULL, 0xC6DF325C119F20BAULL, 0xCF795C8E87FE017FULL, 
            0x411521BE9C057891ULL, 0xDEDBFB43F26A1EF3ULL, 0xC20D74C47E2BA855ULL, 0x9552C31DD91169EFULL, 
            0x6666FF65C6F46EF1ULL, 0x22CD2F7213194F6FULL, 0xD06905546F783664ULL, 0xD31918D6016679EFULL, 
            0xC70091AD72853780ULL, 0xCA8E9FCCC6F5D8F8ULL, 0x0A4E56E5B0B40C08ULL, 0x967AA13F41AF0DE7ULL
        },
        {
            0xE208BFD35A8EAFCDULL, 0x31DFFB2F75C7D8B5ULL, 0xDF7893E9CF672A2DULL, 0xE22F5359EE2A1B65ULL, 
            0x942762AAA7549C18ULL, 0x4EB5CBC8B183E503ULL, 0xF8F5BF2464A6E4AFULL, 0x6A1A89743CE890C3ULL, 
            0x79D0D0E6C9D9DA50ULL, 0x86D7CFF7D2CD62F3ULL, 0x939F8ECE294B7461ULL, 0xA9B4C8FFE56BA01CULL, 
            0x29B3F999042C3B16ULL, 0x2A9130C1976574FEULL, 0x0214662ADF715735ULL, 0xC169DFF51F1C4E9CULL, 
            0xBA282EB19866EB05ULL, 0xE690724ABA00EB04ULL, 0x1CF7A22B0A1382A3ULL, 0x3D0FE6340708A54BULL, 
            0x80002147FA6687B6ULL, 0xC161A73E84A6C7C7ULL, 0x49F1F0768437F2D7ULL, 0xCC002DB314B03C26ULL, 
            0xD6F9B23C3FD8F42DULL, 0xA6559D762D0E8661ULL, 0x1F316C9402DF2653ULL, 0xCC75AEA0D95ABD6DULL, 
            0x5DBF111A0D27614EULL, 0xF366AB55C159A743ULL, 0x8DBDC154E72DF058ULL, 0x817D12943B06EB3AULL
        },
        {
            0xE041C3DF651D4518ULL, 0x364F2EDBBC45D80AULL, 0xA9E94C5816E1D506ULL, 0x2C545E5BD461718CULL, 
            0xCFC8658C62889EC3ULL, 0xFF2F24FD3450AB33ULL, 0x7B12927A0093CE45ULL, 0xF703C3ED7C92F045ULL, 
            0x01C257A0F54ADA92ULL, 0x6C6A6E75345FA2C9ULL, 0xD3CC346C3C6FF001ULL, 0x79C766011984E671ULL, 
            0x263EE8844F3DFB1BULL, 0xB4D3745453F8EA19ULL, 0xD06BA1268A1E6D0BULL, 0x09B57EA1D571D794ULL, 
            0x2A1BBF825C37B47CULL, 0xD6DB6D5427D8E4BEULL, 0x1E2D299D00F1F7F0ULL, 0x25A59F50DFDAD602ULL, 
            0x15FEE131A22C1A99ULL, 0xDA1F85296AC4D571ULL, 0x135D745BED9E7B89ULL, 0x5BFA93406264B4ADULL, 
            0x67F0465B99CF2B55ULL, 0x681A29CB528E159DULL, 0x210684372AB5EDB6ULL, 0x9E88C53FAB10001DULL, 
            0x1DFD51C6C903D630ULL, 0x7762DF7291F5AFD8ULL, 0x69092C79B030FA8DULL, 0x2D51D9F650B6F59AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseAConstants = {
    0x85A82E4AB8BC5D64ULL,
    0x451146AA2F14D1C2ULL,
    0xCDE8644159C54AD8ULL,
    0x85A82E4AB8BC5D64ULL,
    0x451146AA2F14D1C2ULL,
    0xCDE8644159C54AD8ULL,
    0x20AB19DE83A72B4EULL,
    0x3001698EF1D170DAULL,
    0x5D,
    0x33,
    0xB3,
    0xB9,
    0xF0,
    0x0E,
    0xDF,
    0x36
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseBSalts = {
    {
        {
            0xFDF6BF1574C698C2ULL, 0xB5FE0665D8402785ULL, 0x8F70A01C33243036ULL, 0x54B5BE54829031E4ULL, 
            0x717FD956764AB363ULL, 0xF38B5B4262489936ULL, 0xBA81532689CB0DB1ULL, 0x01CDF0A5B5B10515ULL, 
            0x446E352EC2CD2DDBULL, 0x857BF1C8731F97D6ULL, 0x628EB550B6907B0EULL, 0x798B0D109B22AB27ULL, 
            0x82FF60978278A7BFULL, 0xF92DB983F025FC1CULL, 0x4E8FA1D453E08472ULL, 0xBB5F877FB606C980ULL, 
            0xA8B5E8A3FFB5B333ULL, 0xC656B38CA0914AAFULL, 0x5AB0374EE81C1938ULL, 0x4757952D5D89CACAULL, 
            0x99F5A65B47EDB9F0ULL, 0x4D11985A84179F10ULL, 0xC27A4CEAB9D1911CULL, 0x6D99B1C51AED007EULL, 
            0x75C4EAE348553947ULL, 0x6BF5824BAAAE3A81ULL, 0xBD1C34A8A309B63CULL, 0x56694AD70F1630F3ULL, 
            0xD0C113CB76467566ULL, 0x2D3D5E25465E5347ULL, 0xAB641AADD5219ECAULL, 0x001A0AE6157BC86AULL
        },
        {
            0x25850F14B72EEBF7ULL, 0xA38062382EC33308ULL, 0x9BF1D8CAAE9BEE51ULL, 0x452E8C293B7B531AULL, 
            0x1C7C340864CECED5ULL, 0xFA9C93AEC4894E94ULL, 0x1FCEA41F6001592BULL, 0x98F28B152FA98E6AULL, 
            0x27706427B0C15E2CULL, 0x27EAA5A68517758FULL, 0x46D15462F186B8D8ULL, 0x24319416BB8F2DA7ULL, 
            0xC7FA3AA667C71CD5ULL, 0x2ECFD33A515123DBULL, 0x38E0789B9038A384ULL, 0x5AB20C1A6CB7691AULL, 
            0x974005CEA55E9E60ULL, 0xBD78145A601E656EULL, 0x5843D5AE9DD6C539ULL, 0xCA786633375173BDULL, 
            0xCB22F036B86146F9ULL, 0xF8B64CDCF251BDE2ULL, 0x790C3A7B7DD1C028ULL, 0xA023A8081C0B2B80ULL, 
            0xAA35DD2D1FF61296ULL, 0xD5BA37384A4C4D0CULL, 0x1F3402C788D9C43DULL, 0x57886D36227C0B7CULL, 
            0x454C9AC85C017FF0ULL, 0x8D580067E657D370ULL, 0xA305B6A9E6AA990EULL, 0x8B5B8780174524B4ULL
        },
        {
            0x7BF5474BC8233FB1ULL, 0x4D8FCBFC6DEA16D2ULL, 0xA348F7095C40E125ULL, 0x5F8D4CF2AC32CF79ULL, 
            0x06086800352470C4ULL, 0x3DED4A45DE721C19ULL, 0x2CE797C0F47D021FULL, 0x69C66D951BCCC7B8ULL, 
            0x6514CAA77DBC3628ULL, 0x803A27B18978C9D2ULL, 0x582CEDD333E86322ULL, 0xBAF0A509A3EE0B17ULL, 
            0x8F19BEE39C759AE2ULL, 0xCA6B5D4D14F0A016ULL, 0x231CAF9CB3E6F99EULL, 0xE5A93AE9C770D000ULL, 
            0xA130CD414F0E6EDDULL, 0x3571B3641F981F1CULL, 0x1DD57F86F7045814ULL, 0x037AFB7BBB170646ULL, 
            0xE4AA7E93D9F44DD6ULL, 0x8E239C62F2A94969ULL, 0x999E90EC85AE4396ULL, 0x1524F91EA864414CULL, 
            0x59195628C7FB0068ULL, 0xD55D73AAE3FAFAA8ULL, 0x28934D1FE7609EA3ULL, 0x9012B5ACF0336794ULL, 
            0x2A32C29D0FA8B458ULL, 0xE6B596FC581CB98AULL, 0x868FA54AFCB14466ULL, 0xCF6B1D19C76B1269ULL
        },
        {
            0xF295E64ED8C68891ULL, 0xEA227C5B7A71EE74ULL, 0x5521865F95CAB108ULL, 0xF650FA93A7D8F820ULL, 
            0x056670E98D6D1D57ULL, 0x59F980104EDFCF57ULL, 0xD758AD741B296815ULL, 0x23E4D1D38B38E9C4ULL, 
            0xA23BE2F31E016DEAULL, 0xF79548A5FBEC36F9ULL, 0x28071339301D77D1ULL, 0xA3B0156435B2B8FFULL, 
            0x57B35B2C976FCD09ULL, 0x3C06BE113A8BF823ULL, 0xBC55088C5D727B40ULL, 0x98E3D545AD5E88E3ULL, 
            0x67F6B154AF005136ULL, 0xD0AE5EA41CD6C40AULL, 0x2FFC0D1097D60882ULL, 0x68B8350E9D14CDFEULL, 
            0x7A47F85C98763387ULL, 0x3C022BDDBB6DE26BULL, 0x687AF51D9055E40FULL, 0x3B5292AA28B391E4ULL, 
            0xC7B6B153FA01CD23ULL, 0x7F6C7F966212DAFBULL, 0x70C04EBFFEE80070ULL, 0x5C986AD21E32398CULL, 
            0x98D475EC5633A04EULL, 0xEE3C6F5E5B135D45ULL, 0xD5657C92B4A2B1B8ULL, 0x996EDA5B29515BF0ULL
        },
        {
            0xDDDBED089EF3D887ULL, 0x68C3EBFE7066A116ULL, 0x3794F087FACD64CAULL, 0x6701F8B111DC25BAULL, 
            0xB7960A9248CDF7ABULL, 0x1FC6D0B81FEBD9F1ULL, 0xE0C12DAA3B34D371ULL, 0xC7F268FB6BF06345ULL, 
            0x105D991EE5DE76BCULL, 0x8B5C0452CB0A5739ULL, 0x5FB48525FF10D954ULL, 0x65EC30E3EA176EA9ULL, 
            0x1E67D795F6417090ULL, 0x1C20928EC6E3945BULL, 0xE670FC08EBA77B1FULL, 0x1C0C85E16DD6ABDCULL, 
            0xC23016F2FFCD8244ULL, 0xDCE0B802FF02128EULL, 0x42C0A910363FE3FCULL, 0x3054465E71BFC561ULL, 
            0xB407C7E6B6A5AD4CULL, 0xDA3248ED49BFF24CULL, 0x428827DF94A5AEA6ULL, 0xF8AE7A0FC3694DDFULL, 
            0x94CDFAA48AAD840FULL, 0xD74A4667FB55AD65ULL, 0x4AF967D99237EA15ULL, 0xB5B841FD05AE07A1ULL, 
            0x59F4DD876D274CD3ULL, 0xDD48BAE4DB6C4773ULL, 0x5321AEE614CD417DULL, 0xAC120A1FC57C5057ULL
        },
        {
            0x5DAADA5ECB6A3377ULL, 0xC8A7A31D3E711BD2ULL, 0x3BD125A24A39015EULL, 0x714318E8937C5228ULL, 
            0x089E836173EBE11EULL, 0x8DCFB7CD844B5141ULL, 0x417BA1FCC61D281DULL, 0x13314ED813CFED46ULL, 
            0x2C588B7E53ED4873ULL, 0x49742763F9E128E7ULL, 0x44036B2D0991D2ADULL, 0xBE20D4CCDDC985B2ULL, 
            0xFF7C29E9B0A83845ULL, 0x33CBD1FE8FB22931ULL, 0x216CAC4FA3685D29ULL, 0x553FA5EF64C77B99ULL, 
            0x2A694D942D65D614ULL, 0x8FE03EF445E1D724ULL, 0x39C28BC8D19656D5ULL, 0xA6DA78EEA70B7643ULL, 
            0xCB81F8E4C5D5CBA2ULL, 0x01DC94E93FA041E5ULL, 0x3366C5090A48AD1BULL, 0x28A01A8E6382DF75ULL, 
            0x743F0222C3887389ULL, 0xB32DB88658FCE331ULL, 0xBA7E1B6BDA797DB2ULL, 0xB563CF3B9BA4EA1DULL, 
            0x0B9A337CBD132827ULL, 0x448A9FB5B1AEA881ULL, 0x1CDA2C0E71731408ULL, 0x300234F5DC153A8AULL
        }
    },
    {
        {
            0x8F1F407A7EE1C89CULL, 0x775C88DE7BADD962ULL, 0x128D08A02B25A87FULL, 0xE589964B94CEB087ULL, 
            0x63EC03C98BF3157CULL, 0x9AB38B2189072C6BULL, 0x650D774287CA61D6ULL, 0x5BF0C9B14461A0A9ULL, 
            0x6ACFCE0AE1110A82ULL, 0xA8C4CBB54BA279F2ULL, 0x79D8A7D72F3A6777ULL, 0x19A2B6959313856EULL, 
            0xCAA11B7D0F4838ABULL, 0x7DD8AC20B77507D5ULL, 0x0D47F08C8C73AACDULL, 0x494A3374D3B6410BULL, 
            0x4C9D9A7771D4CD42ULL, 0xD78519EA4DEF36ECULL, 0x4B67E5654834BB82ULL, 0xF6FC488A85AEA756ULL, 
            0xA7A0E6531C85059CULL, 0x03D6F76F6FF2E289ULL, 0x28DC9FEB4D1CFB66ULL, 0x9BD10D4A91371253ULL, 
            0x20681056A008A6E3ULL, 0xB03676233E9F1838ULL, 0x268E23ED5C6ACA5AULL, 0xB6FD14BD524CF3CAULL, 
            0x52E191CA404F1E26ULL, 0x8494CBA14AE3AD70ULL, 0xD213822B7D247363ULL, 0xBF9C952F6295C6DFULL
        },
        {
            0x98299A8AE706F75AULL, 0x09793E8E1CBC8877ULL, 0xCB332F34A9148009ULL, 0x11E8222192F5BFADULL, 
            0x5E960AF687339033ULL, 0x25639242F8A7FC7FULL, 0x9E78D90AFB2F5D21ULL, 0xFBE68CAF6BDAE676ULL, 
            0xB1B3029ABFE835FCULL, 0x077DD54C201A5B57ULL, 0xC38E15634848B300ULL, 0xE2D942A8E54EBDC8ULL, 
            0x313058ADEF5EA0F9ULL, 0xE8583CA044633C83ULL, 0xF3D3F6441F23AD2AULL, 0x67529F4F2350DCBEULL, 
            0x5659BAFF93969AA3ULL, 0x4681B7D81B666EE1ULL, 0x05764A4E707780FDULL, 0x05DFB453C782A659ULL, 
            0x3D5E5B5044158461ULL, 0x0BB0D7CDAF9CD90FULL, 0x14B339EB2FDBE941ULL, 0xDA1A43DBB48BCD00ULL, 
            0x34AA4D141B5CD80DULL, 0xE2B1066A3EE60985ULL, 0x8F9BA8FEF09A1F74ULL, 0x373B661E8BE6C6C2ULL, 
            0x1F04818F8DE7153AULL, 0xD446440BDD075D3AULL, 0xA9551D0590BABFBCULL, 0xEC66C9EBFA5DB36DULL
        },
        {
            0xFED260F0E2FF3C2BULL, 0x727B564E2AEDEEF8ULL, 0x7A26A90D7C248861ULL, 0x363F74E570AA1ACFULL, 
            0xD0AE527542B2CB54ULL, 0x3EE052330FD76364ULL, 0x6274719C5279E921ULL, 0xFC57A0210EC31EB9ULL, 
            0x207B88F3550A1D8EULL, 0xA963C9649DA0B06BULL, 0x257906C1D6A3939FULL, 0x0B246A768D27C340ULL, 
            0x9CE64454AB1F1189ULL, 0x31605019623A345EULL, 0x5B1D36AD605F4C2CULL, 0x14E7D2AB7F10F4EBULL, 
            0x371293AAD3ED63C9ULL, 0x065EFB4F4BCF97CCULL, 0xBDB0AC9D18549A44ULL, 0xA1ADC7DDB3D8A257ULL, 
            0xCA1665FF97FFFBF7ULL, 0x9499C7DC20789C7FULL, 0x433C9DBFA9E9531EULL, 0x416455E4BD1E150EULL, 
            0x61B73C265A2AB492ULL, 0x5E1270EA81079165ULL, 0x4720175C32E36F5AULL, 0x2050B048D8EF5D65ULL, 
            0x6815FEA5969F2270ULL, 0x91FE53495350008FULL, 0x0636209414B0F870ULL, 0xB70D92D3A318CD2BULL
        },
        {
            0x427A0BE0DAB0A2C2ULL, 0xE7D14D4F57D71331ULL, 0x7B8BD1D461913EF1ULL, 0x01E375A71948B698ULL, 
            0x1ABA596BF87BAFFEULL, 0xA1DE0EEBF44C455DULL, 0x9D809C8ACB755369ULL, 0xF5BDD39FC9BE4CDAULL, 
            0x48EDB3390D537780ULL, 0x212AD0FA1AD828FDULL, 0xC98ACA081361FC23ULL, 0x559943AB602C04E9ULL, 
            0x291F6951C36B4133ULL, 0x5E2C041338E54436ULL, 0xF4CA3E801AA6CD23ULL, 0xA4F5793F169406BDULL, 
            0xF060EA5960CF24A4ULL, 0xD010DE43E37BE1D8ULL, 0xE2884D2789DBDBF0ULL, 0x4A7937450D166FBFULL, 
            0x8A6B6DE4AD99E747ULL, 0xC208F2ACF55C851FULL, 0xB89AA8F75849F8A6ULL, 0x0BADEA36931D23D8ULL, 
            0xF4A5A6E4F9AD8D73ULL, 0xC6D02FD24C9C69E8ULL, 0xED32E7D78FCA5D80ULL, 0x6AFC462B0CBFE121ULL, 
            0x08B013A875894F08ULL, 0xEF8187D3B0D0D003ULL, 0x0A86B5B18E049A8CULL, 0xFF80EEE3A4F88A7EULL
        },
        {
            0x505868794A71E38DULL, 0x6CD518B069291D92ULL, 0xA7A6F812AAEC9090ULL, 0x9B3F150BB8C4BDF2ULL, 
            0xA6A25BF6B689C72AULL, 0x8DEEF78E5317010CULL, 0x3A8593D1EC6F43D0ULL, 0xAF43E9503D1E5CC3ULL, 
            0xCA9266D3E34D7790ULL, 0x5F01A40517DF2BEAULL, 0x20A756EC0B24E0B3ULL, 0xAD267110658C43FCULL, 
            0x9787F9C6DB152CF5ULL, 0x2FC4FA0F43BC9D0EULL, 0xAF8DB425646C375EULL, 0xA8A2040B1D0A1B7BULL, 
            0xD3B8BAD8CFA4A6B7ULL, 0x9019989D83C7CA94ULL, 0x2D0F6D4F77A480DCULL, 0x7B75A92B4103B3BCULL, 
            0xC4AA95949337C035ULL, 0x1EEF4FF21409A491ULL, 0x33EF5225F8637886ULL, 0x7261BEA26A7CB009ULL, 
            0x9A7DA881D9089E53ULL, 0x9927704ED18A2E52ULL, 0xC85923D60CFDEC80ULL, 0x4A3A5AC6015BA861ULL, 
            0xE4F7FE40585789DBULL, 0x4801FF231D0FE94AULL, 0x9DCE2D9D1591E04EULL, 0x9CDA2A26E1C02BDAULL
        },
        {
            0x44EFF0EC652E26EBULL, 0xE6A3302867F28651ULL, 0xECAEA941247488FBULL, 0x834EDD3020063146ULL, 
            0xFD78B01421E48E84ULL, 0x091E43A4CBDDA142ULL, 0xB79D578BF960CD09ULL, 0x74140C3ADC28FEB4ULL, 
            0xB1B007916DE54D41ULL, 0x641A1648206CA533ULL, 0x39E7728BA35A2059ULL, 0xFE072D696F746935ULL, 
            0x3704E621F5452982ULL, 0xB8F2C15D98C7A796ULL, 0xE79918F24AA3D05EULL, 0x2D7E0C3E378CDBD9ULL, 
            0x1BE6B2CDD559A7D5ULL, 0x395749DDAF65596AULL, 0x56E6A2BBC27DF058ULL, 0xEF2B3696E736F362ULL, 
            0x185567F72B926B8BULL, 0x50601F470D8CBAFBULL, 0xD8AE65E74A4A506FULL, 0x92BB8750ECDC2FE4ULL, 
            0xC14E4DBBCFD3169CULL, 0xA7F6FADCA0F1B5D4ULL, 0x449CEB6DF1204033ULL, 0x4E5C4CA9A09431A9ULL, 
            0xECA5954E63BAE711ULL, 0x5BE042C06C5ED69FULL, 0x5DBB36C4C4076484ULL, 0x92C24EA81373EE77ULL
        }
    },
    {
        {
            0xABD59075B9076347ULL, 0xF1B5CABA506CB6CEULL, 0x56C9FAAD1C6470ADULL, 0xC15D7E742B5949C6ULL, 
            0x0EC16B31BD98D463ULL, 0x2CE2DE61572FC418ULL, 0xDEC64F9E87B75071ULL, 0x710740ED9FE3FC4FULL, 
            0x7B9A8FC3F45830B5ULL, 0x018F2C2E1DDF1E4AULL, 0x6C15B267AD012A82ULL, 0x9474052A2A6D085EULL, 
            0x67643BF302B87D7EULL, 0x9214E01D4C916726ULL, 0x574EA1673A7E3BA5ULL, 0xA8F89B0E3EE3CA63ULL, 
            0x502F408BA94CFA05ULL, 0x97DB8379D9B2B726ULL, 0x79F5631A07B9AE45ULL, 0xA7C36AEC90708289ULL, 
            0x3406BE1B6DD1555CULL, 0x063845FB69283BD0ULL, 0x962D6B71002A8020ULL, 0xD2ABDD6803B2C787ULL, 
            0x11CAB0FF9553EBE1ULL, 0xA56564B09A15E216ULL, 0x2024726BBAC32906ULL, 0x5B82355A63278357ULL, 
            0x57FEECA3266684CFULL, 0x14F951DE46CBAF88ULL, 0x45A3D794E450AA3FULL, 0x109D90776719C730ULL
        },
        {
            0xA4E8B9F66DF607B3ULL, 0xC3E7F1ABBDC3BE20ULL, 0xAA1C8C19939A755FULL, 0x955C3F0F4CD1C85DULL, 
            0x0AAF1824AAB43F97ULL, 0xE73160B0CD2E3C76ULL, 0xECF48FF83352C893ULL, 0x0339164585650AD9ULL, 
            0xBC658882FE25C475ULL, 0x8F846795F4DACF0FULL, 0x7A645286CF5AB1A5ULL, 0xA46D970EEFF8B8C1ULL, 
            0xF201FBA1E556EADFULL, 0xA2172A41D6944DDEULL, 0x0009E9B34E276ECDULL, 0xEB93CFDA85FEAF7DULL, 
            0x95953A3665150961ULL, 0x6F86423C057FAD21ULL, 0x0DD4C86B361862EFULL, 0x280BF39BA97E55C9ULL, 
            0x1B599C0C18AA2B4CULL, 0x780A7D0096B32510ULL, 0xF1DE5BD225B62A80ULL, 0xC0A4651E747F38D9ULL, 
            0x93C40DE6E02F559AULL, 0x23116C6D817619AFULL, 0x80B009A9AC9F4370ULL, 0xCDE478502303B4A8ULL, 
            0x0FE2CBB482017C56ULL, 0xFD3C118ACE0C814CULL, 0x85359F423DD1A076ULL, 0x623E03940F4A1727ULL
        },
        {
            0x115A420F9A4A6FC7ULL, 0xB0CC5433824B9039ULL, 0x62A3CE64B926D0C8ULL, 0x0664E354C5687024ULL, 
            0x0944A1E812E57B70ULL, 0x7747887F49119F8DULL, 0xF395A1D30BDB2056ULL, 0x18111A4FB9334A0FULL, 
            0xD9755A3F5850A24EULL, 0xDDEEF2D65177C17EULL, 0x72A24175C7E8E792ULL, 0x98C662AE39866652ULL, 
            0xDA5F9580E1599FCAULL, 0x0A285BBC0D930412ULL, 0xE92125F5CE8B8617ULL, 0xEB7BD11961A8C71EULL, 
            0xD2FA5C26E07ECEBCULL, 0xE8E6194BB518E352ULL, 0xB63B2F02DD9E74FAULL, 0x950D9D0EDC654510ULL, 
            0x00D61BFBC93E1057ULL, 0x29639ED6E8500C13ULL, 0x735E16F624123CB3ULL, 0x17088E3B71B20D9CULL, 
            0xD94ED04E7CC1FB35ULL, 0xD03C233BD2C379AEULL, 0x1830DE9615E66DF1ULL, 0xC372CB7A540D72E0ULL, 
            0xD375BF346F915754ULL, 0xA7DDF1DE3DAB9433ULL, 0xE02D7332BD12C1F0ULL, 0x45069F73C16A558FULL
        },
        {
            0xE890D8745B23FDD1ULL, 0x9297B641504B43DCULL, 0xFEADADAD96449F42ULL, 0xA8E104C768E81B1EULL, 
            0x45C9FF1909CEE627ULL, 0xFFF9BDB186CBFB05ULL, 0x661A8B4817E7FDCCULL, 0xDD7462E229430229ULL, 
            0xAB3337749EA784B3ULL, 0xFD311B2957749BD5ULL, 0x9F46098189AA9201ULL, 0x497C5C91AD700377ULL, 
            0xB6CE7534A22E28D1ULL, 0x269AF4F2C1400ECEULL, 0xBED0E2F624215894ULL, 0xD167877E249773F2ULL, 
            0xE71676874D4E3A8BULL, 0xAAEC53E6C1C7CA98ULL, 0x98C93E4E9D8473F0ULL, 0x7C20DDCD7A944B60ULL, 
            0x902ECF2E31B0D987ULL, 0xE2663C58A7CF75A9ULL, 0x864544DDE85BC455ULL, 0x312E3C1FE283670AULL, 
            0xE56FAB497BE47EBCULL, 0x094A927C913F50D4ULL, 0x96B281C055D3CCB4ULL, 0xEEE13888C9A78578ULL, 
            0x5D25840FBA2F31ECULL, 0x9442DE9C779F04D9ULL, 0xA9C8BF510EC56CE4ULL, 0x373A63FBB4508DD7ULL
        },
        {
            0xD3287ECD048398D5ULL, 0xF54D5C2CCD4B4555ULL, 0xBD0DD91908E8E0CBULL, 0x7BF4EF95563256CFULL, 
            0x0A691424A73975ACULL, 0xA0E7662A923279ECULL, 0xF7E113C10D0D6FDAULL, 0x515E2D82B8E47706ULL, 
            0x36D7844CD8F321B6ULL, 0xB8CF1428B6AE904CULL, 0x9659CF52D7B8C70BULL, 0xE743D8A3F68737A4ULL, 
            0xDBF5B7A911929F1BULL, 0xD441EB25E4DC684AULL, 0x0AFCE1C7DB9F3EB1ULL, 0xD9A6B15D23D8678FULL, 
            0x8453816194A16E78ULL, 0x41B876FC651BC7B6ULL, 0x3EDF8DEC07A99A3EULL, 0x05C21700F04C7FFAULL, 
            0xE417F7036575712FULL, 0x6EB288D5CD7069A8ULL, 0x341725C8A84B33C7ULL, 0x9EDA99668FD1E8D4ULL, 
            0x0DD2618A4CC09953ULL, 0x3777C9DCDA891C67ULL, 0xDF0CA423C4C30065ULL, 0x8A7E8889E698D830ULL, 
            0xD5168CF72EE66521ULL, 0x7AE181F4B3D97095ULL, 0x45882B5C36C5C088ULL, 0x1F402F6B96F5E83FULL
        },
        {
            0xC86D4F4D994B6206ULL, 0x6C260469F8B42DA8ULL, 0xABE9A2EFF77BAFA4ULL, 0x16FCCECE2607F1F7ULL, 
            0x156BC374130F8BABULL, 0x10471D6313BC2E55ULL, 0xABFD258B3DA82F60ULL, 0x1015D3A74D9B5F0EULL, 
            0xE6BF86F251018FFBULL, 0xDD4417C6FED07CC1ULL, 0xD30295B8D860D690ULL, 0x62DE9C5AFE3F0476ULL, 
            0xDAA9887B8E9685A1ULL, 0xCBFBDD57352F109CULL, 0x4CCDB9D3A88F0C20ULL, 0x82078B5002846C3CULL, 
            0x6014903A9780CDDAULL, 0x21BADC878C8E904FULL, 0xF1D4240D49B2993BULL, 0x3D0EC04B30734B79ULL, 
            0xAD7AC9685113898DULL, 0xA8B6D6647BC406DCULL, 0xB3A0D8E2FA39BBA5ULL, 0x4FCE1B76C4DC189DULL, 
            0xC0DF27C17E721D65ULL, 0x7C0F6EC7F13121F3ULL, 0xA14DB6BE57DE2971ULL, 0xB9B40AC70C212F17ULL, 
            0x23E6D6DE12C7B7FFULL, 0x8CC0C6B204892E03ULL, 0xC4A8CEA96939A111ULL, 0x5583F4BB6A21A779ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseBConstants = {
    0x5827D80B04B5E4FDULL,
    0xAEA43712A3414B5FULL,
    0x7FACA1C58AB9E86BULL,
    0x5827D80B04B5E4FDULL,
    0xAEA43712A3414B5FULL,
    0x7FACA1C58AB9E86BULL,
    0x3663F6D8A61FF023ULL,
    0xE3B70510AE93E5B0ULL,
    0x48,
    0x77,
    0x2C,
    0x9B,
    0xB4,
    0x50,
    0xBF,
    0x82
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseCSalts = {
    {
        {
            0x61D7E3CDC054766DULL, 0x69B054AB36551828ULL, 0xAD69E7B29611515DULL, 0x6FA6F73B7F16C3A5ULL, 
            0xCF185E32E2E3E84DULL, 0x38DF9FC6C166DA1FULL, 0x2464253442242E23ULL, 0xFBC5A2BB3955B1E1ULL, 
            0x7F4865799538EB9BULL, 0xF675D526B126A850ULL, 0x7BFC1CDC63FBCA28ULL, 0xF45B5399D7AB13ADULL, 
            0xBCD2E2B1E168E0A2ULL, 0x83F932BC96601921ULL, 0x3E2BE241D68C060DULL, 0x79F867417CA590CBULL, 
            0xE98D972FC2DC613BULL, 0x5B439FB8BB538D40ULL, 0x42916C041CFC50FEULL, 0xE6644F75A3CCC517ULL, 
            0x007583515DFABA26ULL, 0x28E21C9EA68E21BAULL, 0xB018739E87FE5B8DULL, 0x586CF67B6D371C2EULL, 
            0x812E72D9A18518CFULL, 0x6ED13D12EB6A0C30ULL, 0xE6A236CD0EA98102ULL, 0xC35A1F180E373D7CULL, 
            0x63BD0515F4C76C68ULL, 0x639F1C9723B0DC96ULL, 0x17EDB12F3327C0FBULL, 0x75BA0811B46AEDFFULL
        },
        {
            0xB41C76DF7A0E1E67ULL, 0x93A55774A32F07E9ULL, 0xE599CC5BF3D7C218ULL, 0x98E9FBFB039EE24AULL, 
            0x1DCF1DDB2F4EBF6BULL, 0x921B740EACFF6123ULL, 0x1514C46F700AB090ULL, 0x51F66E62B6E6FA8AULL, 
            0xDC990AA6C0009143ULL, 0x2CBDF62570937D4DULL, 0xB9A0BD9221CA5F76ULL, 0x0427BE0762AAAABBULL, 
            0x3DF348AA15B5D740ULL, 0x78FD486C2789C63DULL, 0x9C105F1C6F6EFE7BULL, 0x67C54823A79DEFD6ULL, 
            0xF3F6C357B110E335ULL, 0x53F8A74705904D08ULL, 0xABEDAE29107E411DULL, 0x8BDE6F8341AC1671ULL, 
            0xC16B3AE01A6658ABULL, 0x52046F04E9866049ULL, 0x76DF8B85AA911DC6ULL, 0x49627BFE1917402DULL, 
            0x7563757FFE7FAAB5ULL, 0x8F56CE1A52301AF2ULL, 0x216A6C5160333A5AULL, 0xD26A5537EB1CD4A6ULL, 
            0x384448D5A15FFD57ULL, 0x5DFECC8D0CCD40ABULL, 0x46391BFD6B9E1FCDULL, 0x3C7C8B56A2973354ULL
        },
        {
            0xB4A29ACEA9B98107ULL, 0xE7F5A2C5D5A8D29FULL, 0x1428616C04CF28BAULL, 0x18CDE35B63C32E63ULL, 
            0xD73AD3BE711D94EBULL, 0x8768E765D9CFB38FULL, 0xDA8FEC29D04E49A3ULL, 0x03590969BD3375F1ULL, 
            0xE7E3DB20201EBD1AULL, 0xA65755209C39AA6DULL, 0xE5B42EF770268B6CULL, 0x5EBD20C394AB6267ULL, 
            0x389274174AFEFB1FULL, 0x1493490A30EE98C2ULL, 0xFABCA3F466375C8CULL, 0x465FE7F90DD8DE48ULL, 
            0xAB9AD9FD6CAAE1F8ULL, 0x2A5DD03EFBC5BAC9ULL, 0xF00E55C32DE2FD94ULL, 0x23FEF3B1FB09D910ULL, 
            0x01C1CD70A141C928ULL, 0xB8FE78C507590C37ULL, 0x28522DA8AEFC2C71ULL, 0x4FED0D021EC24AE5ULL, 
            0xD573F0024BEABC04ULL, 0x5C60ED4FBD9636CFULL, 0x9BC863140F44875FULL, 0x168F7B30688FAC47ULL, 
            0x790FDD37F5D21184ULL, 0xD9660FBF93A8F677ULL, 0x0FF5059151043A3BULL, 0xB4F65F604D473410ULL
        },
        {
            0xFB866C856B0585FEULL, 0xB67C7D3524F3E96CULL, 0x355F0BBBB1F41215ULL, 0x3C6A50AD7FFE2F9FULL, 
            0x0032AB7E3DB9EFFBULL, 0x7ED401442037F15EULL, 0x44D4B2CF4678B7A3ULL, 0xE5E6BBCDB2C44E1AULL, 
            0x85FB44007131700FULL, 0xB5DA419D79991482ULL, 0xE5D0C22D37D00A62ULL, 0x9705FEA5F993FD8FULL, 
            0xA0777EA2C5DBA0D4ULL, 0x1D4088BB8116850FULL, 0x5DD7836158D99094ULL, 0xA639D5F3D60E876EULL, 
            0x2B4C2EA43D384101ULL, 0xC128E28825D3DC3CULL, 0x0C72AF96E67B722BULL, 0x7B530D50DC40F773ULL, 
            0x243AA0B06D7ADFF1ULL, 0x6C6C787A8578BCA1ULL, 0x8B9B964D45E42822ULL, 0x28C72D095239BAA3ULL, 
            0xF7F8E3A9A3045CD7ULL, 0x50611A9AF78288D0ULL, 0xFAD6896F1A4F83AEULL, 0x63E4AF6131ABDCE4ULL, 
            0x46FDC2EFAFB2A100ULL, 0x07BDDBFF1920417AULL, 0x98342E8C658BA0C3ULL, 0x3BDEDD002B979F55ULL
        },
        {
            0xB24DF35D7D239DBFULL, 0x6C0D7E8EB5825E81ULL, 0x48B94FCE06F350E0ULL, 0xF2B5B96561E9D03EULL, 
            0xD41349CEC533023AULL, 0x5275D94B7F91F6BCULL, 0x99AD1D8DA19502D2ULL, 0xC0F4A643130A4163ULL, 
            0x6E3CB9429769AA12ULL, 0x4EB34918EEC673A6ULL, 0x780F1395FA1E1CDFULL, 0x0595D17E9D93D063ULL, 
            0x6E60DA0D5D98DB33ULL, 0xD5874D9390987B2CULL, 0xCC60D7D204A711C0ULL, 0x543D5000112EF716ULL, 
            0x56E622D23BA761F2ULL, 0xA0254C6A4B2662D0ULL, 0x2F46DA561876D628ULL, 0x9DFDC4A7110B0D5AULL, 
            0xA8BB51B433F98522ULL, 0x91D4C3CCC02D80CDULL, 0xC6F76E955F4BB68DULL, 0x691C9D8996BE27D2ULL, 
            0x079B491086FC4A29ULL, 0x4DC8A0FF06695D0DULL, 0xA35AC829DA8E9B37ULL, 0xF5F2ADC067AAA2BCULL, 
            0xD1FD35FC379BC38FULL, 0xEBABCD9CF333185DULL, 0xE31D284675892B82ULL, 0x4D7688E40F504B6FULL
        },
        {
            0x85F3301D5DC51D3EULL, 0x42E89EF668F0FDF1ULL, 0x1A668E1903D1F227ULL, 0x747C5D59CE3C4F64ULL, 
            0x650B1D8255019E41ULL, 0x79D71C8106472B5DULL, 0x3293E95FCF94B306ULL, 0x5347F8FDCFCA6606ULL, 
            0xBD2558B2FC873FFAULL, 0xE7517B581A747B48ULL, 0xC6D86BC4446C52C3ULL, 0x742B6F3690560693ULL, 
            0x1AF413C69CF1DB75ULL, 0xFF5538F2C5187F42ULL, 0x694690199B8D0F34ULL, 0xAB4C5B34C1708564ULL, 
            0x741BF6365881E7C1ULL, 0x19AB45BCC4D28413ULL, 0x45F42A99DD8D8CFCULL, 0xFC276A646C85A5A5ULL, 
            0x4E7B4C9A8CA009ABULL, 0xACB78A6B13D52F04ULL, 0x725C50A99419856DULL, 0xBEEADC7E9C8F728EULL, 
            0xE3F7A190EF389558ULL, 0x3A3CCB68FAC5BA6FULL, 0xDFD832A039DFDEEAULL, 0x46E686A7A74B795CULL, 
            0xE908C71A7DDA0340ULL, 0xCDEAD5D392F53868ULL, 0xE691472490A6CA77ULL, 0x8F79BF8933657A5FULL
        }
    },
    {
        {
            0x05BA0D0D0BB65D36ULL, 0x8DD1A79FEBDB98ACULL, 0x24899CAD234B601CULL, 0x5C86484AE1A005CBULL, 
            0x3D23102D5689A8F5ULL, 0x166041C20B3EF09DULL, 0x76A64FEDEFC0744BULL, 0x77AB56C7DFDD6DACULL, 
            0x8159883CF22CF06DULL, 0xF9E9E4312275E6CEULL, 0x93D6518696870740ULL, 0x13B3ABDEB4A3E458ULL, 
            0x81710DEDDC1BB7CDULL, 0xF7203F5F806B6FC5ULL, 0xBF071253DF32FB21ULL, 0x56EC29EF6A61A795ULL, 
            0xB4F0714B9B672DE1ULL, 0x489606E48CBC0965ULL, 0x64C34E0F81B1CA6DULL, 0xB5E4C83999729062ULL, 
            0x40017365F115B237ULL, 0xF484CCFF5C69A482ULL, 0xAE00E80C3F50503FULL, 0xDCD624C28F252365ULL, 
            0xBD84C97E2102C8C9ULL, 0xE1CE35322464F7B9ULL, 0x11016C9A9AD85B63ULL, 0x146BF1092FC2B9F6ULL, 
            0x587C9E9AFF14B533ULL, 0x04A7BF1AD8A04FC5ULL, 0x76AD78C1B5215509ULL, 0xB5424D46B884D7EFULL
        },
        {
            0x40B0510F24E84532ULL, 0x8B0E1741095FA0FFULL, 0x12C62E91A1FEE6E1ULL, 0xC67393B1BCE306C7ULL, 
            0x14EF26A700938976ULL, 0x6D0446BF6F025729ULL, 0xECEAF5BC5823E1A0ULL, 0x86CD9C544968F1A1ULL, 
            0x69A8A101FCF344DEULL, 0xC6756E5DD1D41181ULL, 0xDE906259185D4F9EULL, 0xA8F0886EA8207014ULL, 
            0x56042995A01F3D25ULL, 0x1A20D39121511C9AULL, 0x0A5400FCAEA67000ULL, 0x03D920065701C35CULL, 
            0x9EF2223B0CD38704ULL, 0xC13FB176659152E1ULL, 0x12EA2EEE41964E23ULL, 0x8A9CF81AE8388AE7ULL, 
            0x4B0DB41100A45729ULL, 0xAB2259571D0AA5CBULL, 0x78DA4EC8F7A953B1ULL, 0x5CEE3830A33169CAULL, 
            0x6B5ADF6E1D019134ULL, 0xCA53EA8B4986F44EULL, 0x091CC4868AF1A87BULL, 0xDB797B3693BB27DAULL, 
            0xE5502DE091A54EC1ULL, 0x5FA755CD4B20017AULL, 0x8AD5BEEDA3033E42ULL, 0x2A5C50BB4BC118E6ULL
        },
        {
            0x63CC30806CD7A772ULL, 0xABBF08227F18C442ULL, 0x9328D3A2FB70BD71ULL, 0xE9420DE2FF60FE34ULL, 
            0x8D6C87B372AD3DA0ULL, 0xA5C70F6A7FBE9469ULL, 0x398E0A4D741D2AD4ULL, 0xDB40C025A513D8B8ULL, 
            0x4B3BA957DD911FE2ULL, 0x5A8A51AC9FB73E17ULL, 0x60295BEAF4308DA7ULL, 0xD2155E92C96B0B7FULL, 
            0x2D6D41E8657C292FULL, 0x0BC917320A0BB0A7ULL, 0xEEA314AEEE0F3211ULL, 0x1D0BDA1C592141E7ULL, 
            0xDAAB80335FF24F1FULL, 0x6276625E4F2452EEULL, 0x75AC97811ED94425ULL, 0x9F7F48C691E707BDULL, 
            0x3910D0253F637C43ULL, 0x7D01A6AF073D9830ULL, 0xFE6665BBFB5800DDULL, 0x4B74C97442F2893EULL, 
            0xB4FC4E45E89A8627ULL, 0x4F408B45BDD597E9ULL, 0xE2A16341C8AF632EULL, 0x533C52C50B93C070ULL, 
            0x2404413981429DDCULL, 0x699BC8CC1B662EB3ULL, 0x580A1DF2A7FBB254ULL, 0x4F08C0EDE3D23832ULL
        },
        {
            0x7FF4170811F5B81CULL, 0x8490328719EFE8F2ULL, 0x6F661A5757E478CDULL, 0x2577777C5F7A0DD6ULL, 
            0x3FDCBB2E6D8FD656ULL, 0xC4850EAF86FC78DFULL, 0x14BBC02A14D57094ULL, 0x98E7E9EA549A51EAULL, 
            0x11DF8B9EB11D11D7ULL, 0xCD717C07974254DEULL, 0x0D7AEF066BE9D52BULL, 0xAE640C65F67E49CEULL, 
            0x1E85EF1A5DC72D9AULL, 0x6850979A71C566ACULL, 0xCA8489B797E3DB0AULL, 0x2943EFDDB0B711B1ULL, 
            0xDB946E6E4D5C7ECBULL, 0x7A4B758EB88787CDULL, 0xF8D160AFFD375186ULL, 0x52408CD6146D6830ULL, 
            0x0CFE1CA640435BD3ULL, 0x52ECE3B2F17F115CULL, 0x2A882C9C7CCB0F22ULL, 0xE610E0C041C9DCEEULL, 
            0x79C42F654EA6C4C8ULL, 0x7C4D25BE1A645448ULL, 0xB2A76E8B27F7FF2AULL, 0x759417344C25698AULL, 
            0x7A930ED87D0CD7BCULL, 0x438EEF7BE04E2A05ULL, 0x862045FC90EB59CBULL, 0xA773E129548E807BULL
        },
        {
            0xBCDEF1CBE2847EF4ULL, 0x1F1C419E22CA58F3ULL, 0xD37D111A8206EB29ULL, 0x8FBC4516204FCE61ULL, 
            0xAAEF9B1DCF557958ULL, 0x6BDFE7125CB40F7BULL, 0xEE73EC1F5E98712FULL, 0xFECD77EB1E76312BULL, 
            0x4821C40B32E21228ULL, 0xB66D29A515498F76ULL, 0x362859B97D34A051ULL, 0x3D4D29E18244F081ULL, 
            0x158CB45CFF364B57ULL, 0x0ADB05A8DB67F57BULL, 0xD9DF9D558EDD99D5ULL, 0x8E963858EFDA03FEULL, 
            0xBC0DD0A8D524D67EULL, 0x46C239F284ACEBE8ULL, 0xF8E15510FB3803E2ULL, 0x9465C52C319135E1ULL, 
            0xBE87D72BB64DA61DULL, 0xA46DBB61DC52D949ULL, 0x1426787B921E58C1ULL, 0xC27A7050CE1504B3ULL, 
            0xAA788E6B4D6383DBULL, 0x610EBE02B2CB2BB6ULL, 0x68D28C74C351BCFEULL, 0x423DD70465E17A08ULL, 
            0x9254998877A788F8ULL, 0xFC466E5BA547E55FULL, 0x2F85572D374524F6ULL, 0xB9AD1FC14150B3B2ULL
        },
        {
            0xAE9239576366172EULL, 0x8BCBC3E77B9D64BCULL, 0x6C97CB4AB3C761CDULL, 0xB79E62AB678601B8ULL, 
            0x40BCEF5C19C50B7DULL, 0xB985F3AE88054148ULL, 0xC6E68E18D46B2991ULL, 0xB7D19E4FB263984AULL, 
            0xD4F4A95E7F09AD8AULL, 0x4794A930C5709BA7ULL, 0x2BD4BF49323E982FULL, 0x158DE22602B9F391ULL, 
            0x7FBB6F49CA8892A9ULL, 0xB750B72226E56C82ULL, 0x73BD977237C6F67EULL, 0x79EE59CA6E9C7E08ULL, 
            0x04C33EE3A9FF2051ULL, 0xACF684E22DC9CB0DULL, 0x6DE9688E7ADAA95AULL, 0x410707705AB0D309ULL, 
            0x459B40E790ACF3BEULL, 0x6869FB906FED18B9ULL, 0xB0F7644FD1CB8819ULL, 0x1E5FFC49D79EFF88ULL, 
            0x882F508DB8E0A6A2ULL, 0x639A38DD05EEB4A7ULL, 0xCFB3A07678C69BAFULL, 0xE3E75ECA0E81C1B3ULL, 
            0x20053BBC90C214DEULL, 0xE4F90254377CCEEAULL, 0xFE7FD9BA4725A796ULL, 0xDF2D6D34FBD3C2C9ULL
        }
    },
    {
        {
            0x9A2ED1CD79D856A0ULL, 0x017AB1427D31DA51ULL, 0x50D41DFB4A408AF9ULL, 0x89EFDA9E862BCCC5ULL, 
            0x1B7CC054AA4D08D9ULL, 0xF9081D4CD660A9EAULL, 0xF33E13D965A631FDULL, 0x12DC65E3CCC7AF53ULL, 
            0x1A3BE113F8040B41ULL, 0x9A0DA479DCBBF843ULL, 0xB51605C97F26A9F2ULL, 0x7206F2B28400E973ULL, 
            0xC7844D5AA1D2F38DULL, 0x6582A0A4C16F81DDULL, 0xD54AB4A573A9745DULL, 0xB33BD041AE928E45ULL, 
            0xDFD97B4D69D89B27ULL, 0x12FA52971D49D041ULL, 0x78467E2703C38B3DULL, 0x75C6AB7769D444D8ULL, 
            0x0F89874665FB766AULL, 0x418A4F8B15E97CF4ULL, 0xDE58F7A5CA49748AULL, 0x0DEE50975BFDE0DDULL, 
            0x07092D494775B497ULL, 0x22A6635BE5A9ACFFULL, 0x628B631529AD8B53ULL, 0xBD7C60DFF661C922ULL, 
            0xE42D4F54270C0349ULL, 0x9B6847FCEDCA6FECULL, 0xAB4E8535C009654DULL, 0x51A94A68CE1D1C11ULL
        },
        {
            0xA49B6A5FD8C48931ULL, 0xBEDD88C0FE9A7324ULL, 0x794A5E72AADD7732ULL, 0x7258974F82C8E311ULL, 
            0xC7B7488AC6C45820ULL, 0xD5BAF13422752424ULL, 0x9F46D71652247D4FULL, 0x4DBCDAF40478BF8BULL, 
            0x57A504F75880E3A6ULL, 0x5327147407B5D5C1ULL, 0xC0799EED4579FD5EULL, 0x704DD30CFE5FE29BULL, 
            0x2BB8EFCADA1E18E8ULL, 0xB36E3D7797C6B8FFULL, 0xBB8D480312874FB4ULL, 0x7D9C853659CA5CABULL, 
            0x7C4561060CCFF83FULL, 0xE507B07B93B83563ULL, 0x3C25209B51645567ULL, 0x3785A8095E34A97CULL, 
            0xE2C46B2A69EB5D18ULL, 0x8C6431277E2A7EBBULL, 0xB1255982D7937F99ULL, 0x2C545B84682FBC72ULL, 
            0x7C5F07BF32709934ULL, 0xF04FEC86343FD4E1ULL, 0xD496A4F6F0DD0EECULL, 0xB977499E657EA6DFULL, 
            0xE914F3BC9C935813ULL, 0xDC7400F7E8379266ULL, 0x2A573D106750FB99ULL, 0xC732267F458EE3C9ULL
        },
        {
            0xFD3CF7FE5C420A1FULL, 0x7672DB1DAAD5C75EULL, 0x17D4BF973BCEDDB1ULL, 0xDF4658CA940D1DADULL, 
            0x01D6B90B5865F35CULL, 0xC23B64BC46B31610ULL, 0x7EE6973FCECBDE88ULL, 0xDC5B5B10A1AA926BULL, 
            0xC6923682DB9F5FBEULL, 0x683397902524CF85ULL, 0x8B7E7667BD3EE001ULL, 0xF398F366CC4B99E3ULL, 
            0xED5091C9DB001C79ULL, 0x291C84EF42E5A4A3ULL, 0xC1FA67A76585E295ULL, 0xE253C0BF4D46420FULL, 
            0x7D1523F84952BBC5ULL, 0x9F875FBDEB6E27B4ULL, 0x6A4FC9EC09965283ULL, 0x970D946CD9258B42ULL, 
            0xAD7D8EB2A17057C2ULL, 0x41794C6ADDD22876ULL, 0xD41E7200EC25F19DULL, 0xCD822FAE0E604658ULL, 
            0x047BE15774055E5FULL, 0x8FB6C987CD80BF2BULL, 0xFF92475FF9EB0106ULL, 0xB8E5E88F8274C3AEULL, 
            0x7671BD2A793E44C3ULL, 0x1DF91AD3CD7029B3ULL, 0x0C7A140C68D8E04AULL, 0x961C67E1E2F181C0ULL
        },
        {
            0x11D38F4AD8FFF96DULL, 0xC4A744988E67D7D2ULL, 0x789D70EF356BD3DEULL, 0xDAF30F72129E90A0ULL, 
            0x6A8DF63C8D3779C5ULL, 0x6829BE82F17218B1ULL, 0xD67F4A167055074DULL, 0xC46F4E4E3AB0170EULL, 
            0x02BC96D47672EE9CULL, 0xE6AED706A01D55E6ULL, 0xEDBADDB6971517D7ULL, 0x4DBE9CDE590DE401ULL, 
            0xD5A89701E3D7B698ULL, 0xC81432B4A6DAC68CULL, 0xDAD98D87E53F0994ULL, 0x78B1EB4C4FFC541EULL, 
            0x3A0ABDFF98DAF963ULL, 0xB760756D1FABA323ULL, 0x4F5C051AF04BAA25ULL, 0xB041F573C53F7946ULL, 
            0xAFF8FD7CFF3AE069ULL, 0x88757ED7FF0A109EULL, 0xB0386EA501796AADULL, 0x952557369F1EB166ULL, 
            0x8E5FA3571D7C25D2ULL, 0x5125166C2504E543ULL, 0xC3C137AC452DB23DULL, 0xCCAACB8BE714509FULL, 
            0xAC456BB0F20BC8F6ULL, 0x4350272BFE553BB0ULL, 0xEBFB34BB03427BFBULL, 0x5C6B19D05FF1E8EEULL
        },
        {
            0x5D89F1393BD5367DULL, 0x343E689BA3D228AAULL, 0xA31944FD78DD520CULL, 0xB688CDA359E568A4ULL, 
            0x44239596538CF79BULL, 0x0369CB5DE94B7DA4ULL, 0xC34CC432F2D14C3AULL, 0x3A1EFAD53BFDDE7FULL, 
            0x06062819FAC546AFULL, 0xD050A77EFCAB6566ULL, 0x978B54C5A947B3FEULL, 0x5174499B2FEAD855ULL, 
            0x86ABB41CE2307031ULL, 0xFCCBE0C8631BE727ULL, 0x8A3A98AA734E0A7DULL, 0x61213A08A79CAD3BULL, 
            0x5DD8257C819EA19FULL, 0x918F1E89DF753C81ULL, 0x41F97501A0C81A33ULL, 0xC859282862957CE9ULL, 
            0xD319ACAB59A74EF7ULL, 0xDF9E7F795B2E678CULL, 0xC91BC9899F082E4CULL, 0x05A7C7703B581891ULL, 
            0x72FC85702EF2946DULL, 0xE8C65DDC99D99B50ULL, 0xB6280AB9A217D274ULL, 0xDEB4DD43939DB6F2ULL, 
            0x2741DC81871621A5ULL, 0xAAB2950F3F0F1E79ULL, 0x338009349BBB2E08ULL, 0x519DD2F67007A50BULL
        },
        {
            0x3CDD2DB5D311951DULL, 0xA81A21F4662413DAULL, 0xA11CD0DBAF3C0E6DULL, 0x98BDEFA45FED5C51ULL, 
            0xEA9FAC461F25E3C2ULL, 0xE4BF175FED761F67ULL, 0xBD011C27236F469AULL, 0x37FA996CA43B3D34ULL, 
            0xA624C1EB680D5AA0ULL, 0xA61A25DA0D471F11ULL, 0x87CAA4864218BCBDULL, 0xA7CB044760AA60FCULL, 
            0xA9FBE61CC6FEDDADULL, 0x8E4330DA793D5F6BULL, 0x97CAAD43D583DBD6ULL, 0x2F62213EB923E0E5ULL, 
            0xEF9CC9133D0E058FULL, 0x538EE4BD336E5475ULL, 0x20613837D5032C9CULL, 0x241039340A487857ULL, 
            0x903A81EC88AF2B8DULL, 0xB4C6F86C41FB67C6ULL, 0x117BF47E6A2F4115ULL, 0x6C48C90126070D97ULL, 
            0x0F98CF7BEBFA2FF9ULL, 0xC7353B263172F413ULL, 0x50E0FCA14E17FB22ULL, 0xEAB4712921B0B37DULL, 
            0x3500B363261F7C56ULL, 0xFCF61A38F2F34F1EULL, 0x5E41F31A0532B314ULL, 0x1FC35E38334FADFBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseCConstants = {
    0x53F813447227F93CULL,
    0x6C92EECBD3890150ULL,
    0x9E9C458CE9EC2518ULL,
    0x53F813447227F93CULL,
    0x6C92EECBD3890150ULL,
    0x9E9C458CE9EC2518ULL,
    0x959A2EDAD426773CULL,
    0x9FC60630A7EE83A3ULL,
    0x9E,
    0xB5,
    0x9C,
    0x16,
    0x60,
    0x72,
    0xAA,
    0x54
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseDSalts = {
    {
        {
            0x1E793416CA68D963ULL, 0xA3A650B2DB39C749ULL, 0x30F471A3DDC8AAE4ULL, 0x3CF20FFFD3181029ULL, 
            0xBEF2454018234BEEULL, 0x745DC698E7A50C5FULL, 0x4185FD8D7A231784ULL, 0xCD7888E4A684AD06ULL, 
            0x22A24FC81867C034ULL, 0x0CCB1026F7D69E37ULL, 0xE0778C738AE4E460ULL, 0x74CACEB54F0ED17EULL, 
            0x8D9163122F8A28D4ULL, 0xAB3C4FCBD0642780ULL, 0xABCD413A4F62C931ULL, 0x3DFA0E7B4525F335ULL, 
            0x82264F86B3141353ULL, 0x4E8B0B1FF8361DE1ULL, 0x6D3876E1B13258B4ULL, 0x0E58E9077E48D58DULL, 
            0xF5434EC6332DDC10ULL, 0xDCF32FE9A6F62E1AULL, 0xEAE3DA39E2AD13C3ULL, 0xFEF388BF8B11B071ULL, 
            0xF835EC891B0CD648ULL, 0x63CFCAA70925A33FULL, 0xAD4FC19CBC3E8766ULL, 0x10F448C346AF7AF9ULL, 
            0x549B0C75BA2AAD27ULL, 0xA1780FBC0D4DE7C7ULL, 0x7AF2E0F34ACBA474ULL, 0xD5CF59560ED2131FULL
        },
        {
            0xF1C52BB16434E225ULL, 0xE6D8E525061B1931ULL, 0x8F2144013A342C1AULL, 0x56F29EF000F96169ULL, 
            0x6408AF4E1E0A68C7ULL, 0x15ABC12207CBD38CULL, 0x497ABC244E328F67ULL, 0x0F8E64FED4759386ULL, 
            0x3C58BC0469EF4692ULL, 0x0D59678D02A1CD68ULL, 0x30A9333F667F01B4ULL, 0xB8C60F04C9C46D74ULL, 
            0x70578E94EE0131D2ULL, 0x6157E972FD8BABE6ULL, 0x3D4903B2C345065CULL, 0xD3B068D596407727ULL, 
            0xF315093CB6522040ULL, 0x85C6EEDF5FC0F388ULL, 0x970176BA78AB5444ULL, 0x419D5935EF04E586ULL, 
            0xF0D034EDF7C89D2AULL, 0xF7ACA2AA20FE90ABULL, 0xB26FCB4660A0007FULL, 0xF6723E7B6C0B3739ULL, 
            0xA0779FB1FE14AF0DULL, 0xF776ABCBB981A44CULL, 0x17D07C78CF807123ULL, 0x26DB18B065BC7C54ULL, 
            0x3F8DC3ED1EED7F2AULL, 0xBC354DC4B78871BDULL, 0x7910176DC1DFEE25ULL, 0x4AD517C814E5E685ULL
        },
        {
            0x5AFED37D31518394ULL, 0x141DE1613A24925AULL, 0x76813F107D3A43F9ULL, 0xD8D16265EEA44A5DULL, 
            0x3269878466BE4DCAULL, 0x939BB7164E8AD4F8ULL, 0x25B0C8FFB33789BFULL, 0x53362AF0C1565B43ULL, 
            0x48EA684CC84ED7F8ULL, 0xEBEF62A9FD4A031EULL, 0xCDDCA62D2CB60C95ULL, 0x20E90DADF6F10075ULL, 
            0x28C2E1262134D3B4ULL, 0xC45F4FA12497ABF9ULL, 0x1267819DF6BF121AULL, 0xB6A12FA1BB4E72C0ULL, 
            0xED1BC77FDF67F612ULL, 0xBB25F36E77D268FBULL, 0xBD36DB2DD1E16EF3ULL, 0xA52FD043FADBA643ULL, 
            0xC355CE0D145B9EF6ULL, 0x3ADE3B06E6C73B54ULL, 0x245716935309795CULL, 0x3A78516B00A54D0FULL, 
            0x3A3EC4C4D3E50A58ULL, 0x4C764A8F30808176ULL, 0x0A1972A39ED582ECULL, 0x34EFEE8B10AF2DD5ULL, 
            0xC9F6BED3DF67710CULL, 0x13A7D02C8890508AULL, 0x993D058CB50196F7ULL, 0xD7EAB2FE77A369F8ULL
        },
        {
            0x23AE939DF4B06B75ULL, 0x33C2C4C6D7935292ULL, 0xD7E2000F5131635EULL, 0xB7D43781596169BAULL, 
            0xCD260158D8F84977ULL, 0x380A43F7197F74CEULL, 0x226BDFB8CB6CF047ULL, 0xB9CB0DABC9941F3FULL, 
            0xFA6CF08738536D66ULL, 0x6870DEC9A6EE71E9ULL, 0x9EA0ED58EB0620FAULL, 0xFE09460C33823F5DULL, 
            0xA39066F1D33960D7ULL, 0x8E2C47A9858E123BULL, 0x1912436F350B91B6ULL, 0x20D2A7BBE97B39C7ULL, 
            0x32FB15C2E4BA9AD2ULL, 0x6C7A2A998CFDC7C5ULL, 0x380E108CACD7AE3EULL, 0xD227E617D46592B5ULL, 
            0x6A7E42D5E6C14F57ULL, 0x31970C739F1AA5C6ULL, 0xB61369B90B608BCCULL, 0x7A03D490104E8066ULL, 
            0xBC7BE69F6CCE2856ULL, 0xBE6FEB264CB990A2ULL, 0xFDD95603E2121A15ULL, 0x8F646367A009EC82ULL, 
            0xE613B99E99862861ULL, 0x387569443FD67E91ULL, 0x39AB608D4E096DB6ULL, 0x37679270D3FD303CULL
        },
        {
            0xFFF8B507126112B3ULL, 0x59DC4BD16969DC9BULL, 0x06F514BC6D6A5EE2ULL, 0xE769DAC191D8E1EFULL, 
            0x854BF6891C647763ULL, 0x1887A075B4E01DF4ULL, 0x9177EE9CD61FA8E7ULL, 0xFC2E27EC29C1877EULL, 
            0x1AA02E57CBFEB454ULL, 0x98ABC246741F3FDEULL, 0x43D860844C88DF5BULL, 0x57EDB0534E284C91ULL, 
            0xF8DBDFFB41572531ULL, 0xC103656B3F31528BULL, 0x19201E8E19456F8DULL, 0x2A2FBC6378DF71B1ULL, 
            0x38147D31898FD3B8ULL, 0xAFAA40AFAAEA5C20ULL, 0x94CDCC4598DF02ABULL, 0xBF06116311EECAB0ULL, 
            0x608ED7142F30093FULL, 0xE4BD60B5C17BDB90ULL, 0xA88853635B416F11ULL, 0xD62720D34A67B219ULL, 
            0x6387DF3238599749ULL, 0x94C63368F782033DULL, 0x76BA591F9E01F07EULL, 0xC5ABED4F6749907FULL, 
            0xD2CF1D546909B396ULL, 0xC73E6C1C41E34FF6ULL, 0x02FB559173A89926ULL, 0xD4EC35126B697A38ULL
        },
        {
            0x05062469CD73ED97ULL, 0xFD3F3EFED1D7F7C5ULL, 0x442D508BA252FCD0ULL, 0xB208E1454757F4F4ULL, 
            0xF0CBE5DBA17BE832ULL, 0xCF75E3B954B03991ULL, 0x98E66FCDCD6BBDF1ULL, 0x7095AED8045F7F6BULL, 
            0x20EDC170AEC16AD7ULL, 0x12BA0786971FF6A2ULL, 0x5FFDBF1D16110B41ULL, 0xB82AE3E05C4F87A7ULL, 
            0x60A1C26A3CE5CF71ULL, 0x183D889DC8F84A5CULL, 0xCF4145341D077850ULL, 0x4B7B8AF11B72A948ULL, 
            0xCFBECC6B841F3C1BULL, 0xDEB7F3971C82325BULL, 0x2521ADE161D1DD01ULL, 0xF899355D1EC92ABEULL, 
            0x297EFA8E77770859ULL, 0x5C9ADCEE1A4CED4EULL, 0x5508DCA3E67535A6ULL, 0xA037D371DE73AABAULL, 
            0x9C6D2E8F08119FEDULL, 0x257D7335621FBB3AULL, 0xD6A4EE3EA9AAAEF3ULL, 0xD7D8FEEE396FF592ULL, 
            0xE0B20FA07546992AULL, 0x5D783CB978DDEE50ULL, 0xD2FDE62E2ADABC9AULL, 0xA9A8209F88327C4EULL
        }
    },
    {
        {
            0x24884769A734C004ULL, 0xC02C821403FFAA7CULL, 0xEFC8727C84628B0DULL, 0x405B4A97CB72B19EULL, 
            0xF01B27B8CDC8B5FEULL, 0x3592FD97047571D2ULL, 0xD695CA607BC2C35BULL, 0xE11E6615352D2EE5ULL, 
            0xE9338BBDD76C4197ULL, 0xDBB742E180EC5A67ULL, 0x71E1D19DD2633300ULL, 0xB7FBFEAB60131982ULL, 
            0xCA6740A8C7A00212ULL, 0xD5385BFAE46546A7ULL, 0x094ADE61D22D8587ULL, 0x38EE7DB771E239C4ULL, 
            0x44BCAC4035DD5385ULL, 0x4015AEB352280FDBULL, 0xF3193A9498DE662CULL, 0xD5278874C4B87846ULL, 
            0xB9F22E1EFED76030ULL, 0x4ED8FDA124CA7114ULL, 0x7349519D6387C684ULL, 0x7112C962976AF881ULL, 
            0xDD60168E448D863AULL, 0xC33D813E355D495EULL, 0x5A13F02509805F44ULL, 0x9E63B7845E28AFF6ULL, 
            0x5BA0C0FD96677614ULL, 0xB0A0FDF0E0E14668ULL, 0x351234203923D27CULL, 0x07B64B5B6430BC09ULL
        },
        {
            0x839124C9C71B2702ULL, 0x6852BA71E1968B68ULL, 0xC5CA9F291BD431ABULL, 0xBECF6912517006C7ULL, 
            0x80617EAC04AD309BULL, 0x2538502D73A5F8FDULL, 0x9E3DB4E138EBAD85ULL, 0x8595FAD0709E9418ULL, 
            0x5300E25CCB50377AULL, 0x082E6BA363D60591ULL, 0xA1D82FABC30FE53CULL, 0x8E6C91D07BC75FE8ULL, 
            0xB62BC8F3B0C92F3EULL, 0xE14E7377678735E8ULL, 0xD53A4FEDBD3FF156ULL, 0xE30EB900D339E918ULL, 
            0x96BE5342417DED2BULL, 0x19A576F883F2A2C6ULL, 0xD494A91A2DDD7D02ULL, 0x3B644B42A990CB61ULL, 
            0xF9C67171C5F4A14AULL, 0xA1D7AF96199D1322ULL, 0x3FFA0800658D259FULL, 0xC0E0A75734DB2539ULL, 
            0xC7E972488A0A0E2AULL, 0x703B88B9AA9AA7A5ULL, 0xD11D5C9490392F2AULL, 0x38052C3092F7F25BULL, 
            0x1C80B6E7A104EB31ULL, 0xE3DE508099469D48ULL, 0xE4B2B4E144372D3EULL, 0x5AC329A360214D88ULL
        },
        {
            0x891313BB4FC3D381ULL, 0x964E71EF9690B5C6ULL, 0xE23A10E7B391FBF0ULL, 0x30820AEF0D4308EDULL, 
            0x62E9BB2BADD53310ULL, 0x848377E8C1F86463ULL, 0x60F1596123AE0C90ULL, 0xD1399553BCE971C4ULL, 
            0xA03C7F57BF59D433ULL, 0xD3039DA714DCB097ULL, 0xCF03AF746E07159FULL, 0x4E1A37E7BC68677AULL, 
            0x260F0E0F9EC1D36FULL, 0xC455091ACA07F58EULL, 0xC1C0DE5D762D01A8ULL, 0x8177EE645EF48637ULL, 
            0xF4401A61922727B0ULL, 0xF9ACF12D72273E46ULL, 0xDED790AADC79CEE7ULL, 0xC735493CD70A3312ULL, 
            0xB6CCD41AAB665830ULL, 0x7E4C825061B8D17FULL, 0xC06C56FE7CD94B6DULL, 0x7C68319ADFEB94A4ULL, 
            0xCA2C7EA3985B3D3BULL, 0x9906C959A5B2AD6BULL, 0xBF9B9F95BC764D44ULL, 0x243B2567B50B6306ULL, 
            0x3E95308E33748325ULL, 0x01AEFAB8A8B36FF0ULL, 0x5A32444BE283B13DULL, 0x21580424539724A1ULL
        },
        {
            0xB3775548EFCAC6B7ULL, 0x19E4F10DEF311E3AULL, 0xBC287D512DDCB8DDULL, 0xBE3F7B67E490AE9DULL, 
            0x364DFBA60A0B1E61ULL, 0x8B2B38450C9F68A8ULL, 0xBEEB8A4ABB62C2DEULL, 0x128763B757F534E5ULL, 
            0x799B239073FE0B98ULL, 0x98CA9412D6ED29C4ULL, 0xA12FB5E6CB6DEEF3ULL, 0x2A7DD77F8E9A6AD8ULL, 
            0x7B79B7969E326134ULL, 0x919D03895EB5A441ULL, 0x23AB6FD8E12A6CE2ULL, 0x43397CD90A6B722FULL, 
            0x769F5D5EC9145098ULL, 0x3B22A8362B93EE24ULL, 0xE6D6186F5235FC9BULL, 0xD1ED160F128FD2E7ULL, 
            0xF87882B0EB151B05ULL, 0xBD68E5269E247964ULL, 0x8AD0C8966EF19746ULL, 0x232009E055C294B7ULL, 
            0x0931C8DAF9220283ULL, 0xB7D1A110D429131DULL, 0xA5C98F0D3495293FULL, 0xF324B386560E9C1EULL, 
            0x42AF9948862AE804ULL, 0x2CEA0BE07A9A162FULL, 0x58F6C8C57FC4799AULL, 0x72FD07FE0F2BB330ULL
        },
        {
            0xD398ABB6C63152DAULL, 0x0F1AD300491A3FDBULL, 0x8DC6FD5F2FCBAAC8ULL, 0x262A476F3691434EULL, 
            0x565103578D71049CULL, 0x39D2295C722F8CF4ULL, 0xE78284AC2C56B459ULL, 0xB23272C84B8DFC65ULL, 
            0xACE38F4A98C887DDULL, 0x1E0B9AFCB4EFF33DULL, 0xC7979ADEDD2B1614ULL, 0xFB040180F1692461ULL, 
            0x93B482D17741D5D7ULL, 0x7E4E51F96E01BDB8ULL, 0xF4E2BF927B32217FULL, 0x8619928F7845ACC5ULL, 
            0xE337295CF1597357ULL, 0x7AD0DAC4D99246A2ULL, 0xA51D579A2EF9454CULL, 0x82871CCD2F4D0642ULL, 
            0x59A1241E4015A33FULL, 0xD59F056B5A8170D3ULL, 0x9526037405394AF5ULL, 0x0E66C113A1E6A370ULL, 
            0x23B6B541B439D05FULL, 0x32713EE51B0DE4FFULL, 0x757752EC949F79D7ULL, 0xE610BFAF99B774C0ULL, 
            0xD893638BE78A3B5CULL, 0x8D72158785E6B565ULL, 0xF4F2282907E12A6DULL, 0x0857AFE414FD452EULL
        },
        {
            0x1785765AF48CEAE1ULL, 0xC6E83AF34091A59EULL, 0xF2ABCF954627C04DULL, 0x0BCFC4DEBD8AB0B9ULL, 
            0x1261C89948A76532ULL, 0x0301A7A4FBF3BB66ULL, 0x115FA6F06536A5B0ULL, 0x0A9CCADE70DCE7F0ULL, 
            0xE54E832FB132C5AAULL, 0x6FEB1CD3DADB4E62ULL, 0x12C9C17B7E89671CULL, 0x65EDBD28D46D1275ULL, 
            0x99675ABB8E2DE1F6ULL, 0x235E460C140E99F8ULL, 0xB4C0F6877750A796ULL, 0x46543236886E5D37ULL, 
            0x433329883D1A8188ULL, 0x8EB83C79E6A717FFULL, 0xFA904D0FEB9B3CBFULL, 0x8604DD26AB569CC8ULL, 
            0xE877789F46B208DFULL, 0x3FDC4608889E4983ULL, 0xB0F9BABD21F5F928ULL, 0x02A42DA500E6DA86ULL, 
            0x448D978C8626933BULL, 0xFA2F3AC9F1916BC8ULL, 0x231CCD5176026691ULL, 0xC2F871015FE69B2AULL, 
            0x5DE6B7B4D49A6A99ULL, 0x7C8BDFD81FDBB7A2ULL, 0x2307028BD398DEBFULL, 0x3FC6237CF8BB6E71ULL
        }
    },
    {
        {
            0xAA172BEDF45F1120ULL, 0x47F179B9130B9EE3ULL, 0xD458BF1F3A98B6DDULL, 0x530F93B6FF226581ULL, 
            0x66C933BB34D22486ULL, 0x64E73E779F3FD0D8ULL, 0xA89EDD6B58DBA29CULL, 0x5E64A2987B6A528DULL, 
            0xC4EFF8093BCDD4D7ULL, 0xCBF20778225E1655ULL, 0xB2173837F043F3E6ULL, 0xA357390EB6400727ULL, 
            0xCAAD655DC8FA2158ULL, 0x4BA1C184318F3068ULL, 0x345221378522B756ULL, 0x050CF23867224543ULL, 
            0x8328542FC9E826D4ULL, 0xC9096AFC6A30DF9FULL, 0x7A9FB4C1A4A659FFULL, 0xE7F67E851E72A8BEULL, 
            0xE6BCBD053F66ADC3ULL, 0x538E9FCD90AF1364ULL, 0x826F73DD59DC2F91ULL, 0x409619D400EF7388ULL, 
            0xAC189B13D026860EULL, 0x282CCF3D1E822415ULL, 0xC5AC27BCC61A85E7ULL, 0x679C6323F3561677ULL, 
            0x3488D9C58FCB9FDFULL, 0xE2F325B047A9D61DULL, 0xBCECD7E6F08A5719ULL, 0x4BD6F04989962331ULL
        },
        {
            0x0EB47E5B406B9FC3ULL, 0x783C8201D8602CF8ULL, 0x10F87118B5349F5DULL, 0xD32AFA364C25BD82ULL, 
            0xD939772827B1815DULL, 0x9AE1632F359A52B5ULL, 0x64E0B4A84C986A03ULL, 0xFE5C97089C668DE3ULL, 
            0x400A128C6273DA63ULL, 0xCAAE62C643AA85B6ULL, 0x3A8AB8C422EBBD9DULL, 0xE6C9E2ABDB925044ULL, 
            0xDC52B4B89208526FULL, 0xB700AE511183FC36ULL, 0x572B2B5329E0A374ULL, 0x6C0D76DA39A2AB99ULL, 
            0xF7D256726A82F400ULL, 0x4C379C627CF025EEULL, 0x5D7692133258BAF1ULL, 0x8F41CABF401B1212ULL, 
            0x54921B4F73B38A1DULL, 0xFB8AC8E2556C17E2ULL, 0xB123C5B7786F88DEULL, 0x47E4AFB1CFCE1C9FULL, 
            0x2E612C6F51B1B19CULL, 0xEB2005E7C3EA1E0DULL, 0x22EBD327D05346E2ULL, 0x24B4CD33E97AB356ULL, 
            0x3D40DCE4320ABAC4ULL, 0x7AD5480AF5258949ULL, 0x11F12EB70AB16BD7ULL, 0xEA10E438A05DD929ULL
        },
        {
            0x25D26D86D5117B07ULL, 0xDBF75E6F374B9373ULL, 0xCEF24BA4EF039D7FULL, 0x1B517907FAB549CDULL, 
            0xCA5B8E7A9A4380F8ULL, 0xF585FA96690F9FC9ULL, 0xEC3C1C88EBAC382EULL, 0xC9FF0311A1D3F782ULL, 
            0xC64A7008DD3D8CE6ULL, 0x910D5384D9391F32ULL, 0x8B025A1858CC4755ULL, 0xA985BA925BFAE8EEULL, 
            0xD7F88E7A25191E2CULL, 0x72DE16B68482E31FULL, 0x5B313D58F4512FD9ULL, 0x1EFC7FC84C8CB7BDULL, 
            0xF899EB8B5AE687F3ULL, 0x1259A42A75CD2189ULL, 0xF853B9DA48DA3626ULL, 0xA2BB835CEFA324DAULL, 
            0xBC5A75C657632D5AULL, 0x7A9A8F83D71CA720ULL, 0x48615D8E68F01A9DULL, 0xF334D0842A33EEE8ULL, 
            0xF298850643CD4125ULL, 0x227E8625D14C550FULL, 0x5639A69DA494FEB6ULL, 0xC832A743F8D66D58ULL, 
            0x3C24DA23D7331724ULL, 0xDEFF0A2F369BE78EULL, 0x9EF86E95B7944E89ULL, 0x4EB434BDBE521612ULL
        },
        {
            0x419DCE8F2999CEA0ULL, 0x3270E3D03953C4F9ULL, 0x6973E7CDC5B89C58ULL, 0x729AA6F2DF09D081ULL, 
            0x1DE0292736D0C4A1ULL, 0x0988D8E4291CA08CULL, 0x5DDCE7A067B6E617ULL, 0x5455F72BAA78AB3AULL, 
            0x4F6BAA1CFE1AA456ULL, 0xB994A2430805F9FBULL, 0x950584C68E87688FULL, 0xE93E1FAA3E1AF7A1ULL, 
            0xB33AF6E622E1963AULL, 0x26654FC94741564EULL, 0x4714910BA212D6F6ULL, 0xCB031B4D39F5389FULL, 
            0x603DD412D7372FADULL, 0x956766538874AD76ULL, 0xFAF02479C3FE68CEULL, 0x1FA198196EC9A724ULL, 
            0x3C7FC6120723814FULL, 0x2F85CD11E6E3E871ULL, 0x66BC8DB95CAAE3C8ULL, 0x4AA1ED54002B7420ULL, 
            0x800F2E1569470011ULL, 0x0C486F8868450D9DULL, 0x6AA65D202F9E75ADULL, 0xA33EB55C66E14A96ULL, 
            0x00695C207319CCF4ULL, 0xA23DDF533BC447BBULL, 0xAF293B18EBF35C3DULL, 0x1D72488C82D963D8ULL
        },
        {
            0x2DE84F69759B8967ULL, 0xB91EEF39E6C6FA6DULL, 0x0EF48BFC0693DDF9ULL, 0x577395B6A9C324C3ULL, 
            0x62D890B8DCFF51DEULL, 0xB913D5C0E42B04EFULL, 0x34305749B2CE6305ULL, 0x709F8142C0FEF408ULL, 
            0x37951F63F3883B5BULL, 0x4CA9BADFEFDDF25CULL, 0x781F76717D1FECA5ULL, 0x4014CB151B072C43ULL, 
            0x0D74704517091BC4ULL, 0x536112637D3169BDULL, 0x207283D9DE6CD5B4ULL, 0x10720926143F1732ULL, 
            0xCE3A9EAB5DE4EB07ULL, 0xAD80DB77A6DB9DB0ULL, 0x8DD2D2C67C3ADFE1ULL, 0xBD165968EFF82ECBULL, 
            0xCDF685CD91179529ULL, 0x4F17DA9224F78443ULL, 0xF6CA2D5EFB91B63FULL, 0x8791903A69CB6BF4ULL, 
            0x6A861EE3042C7B75ULL, 0x21B11DB93ED1B45AULL, 0x36DF27B4922FC555ULL, 0x0A3BAF06A28629A8ULL, 
            0xEB2EDB52AB28BBEDULL, 0x273A2B97364CD1CDULL, 0x44934546EE28583DULL, 0xC7C41D773674A49CULL
        },
        {
            0x93E458F3C4DF8E48ULL, 0x44056D500A9D45F1ULL, 0x43CACBEA09F8E7CDULL, 0x76544D07C36A499DULL, 
            0x2EE872D5B12E2A48ULL, 0x9A3F80F72CE10175ULL, 0x558EB7D7989C2558ULL, 0xAD6D8B023CEB7AE4ULL, 
            0x631142098DADAA7FULL, 0x0B5B22EC8DD5E8C5ULL, 0x0B5F124A0EFC0FAFULL, 0xBC9A445935FCA1FBULL, 
            0x52BC84B3B2151B56ULL, 0xE38D857CC498F49CULL, 0xDD9BAC7AB4322E0BULL, 0x5276F4C05642601FULL, 
            0x8E4AD1A35EC6E2BEULL, 0x5829183E23E42F10ULL, 0x1AB8B758CC32A28AULL, 0xCE8D52672F41DEC8ULL, 
            0x0019E980714AF575ULL, 0x19A72E910A7202F4ULL, 0xE2D470F97D10EAEDULL, 0x7B4CBA2F39451688ULL, 
            0x115CD44506AB8AB1ULL, 0xD9AE5BD95CFCCDDAULL, 0x441B982095FCAA11ULL, 0x431BF7AF906CA0FDULL, 
            0xE3390C33C95FA3B2ULL, 0x37054689BF1BC406ULL, 0x87101D1C67027870ULL, 0xDD7406C8868C88A0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseDConstants = {
    0x3E844F8C20F5698EULL,
    0xB7AB08432BB81EC1ULL,
    0xABB17005968CDC04ULL,
    0x3E844F8C20F5698EULL,
    0xB7AB08432BB81EC1ULL,
    0xABB17005968CDC04ULL,
    0x2780F6B223B7F4F0ULL,
    0xECF38E0871D8B9D0ULL,
    0x91,
    0x7A,
    0x15,
    0x3D,
    0x38,
    0xA7,
    0xC4,
    0x72
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseESalts = {
    {
        {
            0xBC0098FCC2A02870ULL, 0x7436EA4185FC0B25ULL, 0x33CAE79003A67412ULL, 0xFACC5190C82198CCULL, 
            0x1E6172858791CF08ULL, 0xFF5D31B858DC245EULL, 0x45F0910A1BA5FAADULL, 0x96DF6070951AE20FULL, 
            0x88FBDBB08716EC70ULL, 0x3BC53274CAA1154CULL, 0xE7FF0B2401935FC6ULL, 0xD59E91FCFA558886ULL, 
            0x497F6A43A4768FC1ULL, 0xAB1D2EC207601503ULL, 0xBD797E36378E57ACULL, 0x8440F1D24D708E7DULL, 
            0xF178D13422B539A3ULL, 0x163382BECDC8F8D3ULL, 0x85EB33635E6E97A8ULL, 0x12E21964A8163381ULL, 
            0x73757708621AA0C6ULL, 0xD79B3D5291FEA933ULL, 0xDCCB1F0E374A3778ULL, 0x2A1FDB32C495E6BAULL, 
            0x47FDE81D56507657ULL, 0x5F7A39A51D2D0B77ULL, 0x2F4B262C5FD973A0ULL, 0x83BA87A1D542F93EULL, 
            0x3BA5FBA5F3CD5FC4ULL, 0x56A0F111FB6E27A6ULL, 0x0E299A784374D880ULL, 0x0826416F9148CA42ULL
        },
        {
            0xF94EE9A48B0D88BAULL, 0xC09EF29757D72E93ULL, 0x425D22DD1D2C6B82ULL, 0x3458C23C199EFDB1ULL, 
            0xEE731682A0B0E500ULL, 0xC9A4DD2EB70B6E76ULL, 0xF8D507DB554E816FULL, 0x1E76F779FC50A3F8ULL, 
            0x2E0D56D4B311DE4BULL, 0x29D6A40D5F081857ULL, 0x3AC04FABB0AFECACULL, 0x3508E04CB391A3AAULL, 
            0xE8043455458E4E16ULL, 0x213ECF9FE0E94BD5ULL, 0x74714FC8AD3DE6B9ULL, 0xD2CAA862153E5228ULL, 
            0xCF45A3AE706A3E3FULL, 0x5FC845CAE1FFBBDAULL, 0x26112FFB3AA96F42ULL, 0xDB097063360F0746ULL, 
            0xB43008F07155E680ULL, 0x147DEA64CD8D16EAULL, 0xC1CCFECDCC1FC798ULL, 0x67C992FFBB9E151CULL, 
            0x9FFD40646B8BAE76ULL, 0xFB7E30C3DF92A2B1ULL, 0x79D13C910EB82385ULL, 0x9F2DD647877CE82BULL, 
            0x50883EDCAE79105BULL, 0xE18CAC136CAF9D04ULL, 0x5EBE70D73A0757D1ULL, 0x43FC048A000F26A3ULL
        },
        {
            0x3D5A58BF7A4E1A45ULL, 0x753101B924C1A3A8ULL, 0xEFFA8FED4FA0CC54ULL, 0xA979E71E3E05DF8AULL, 
            0x6115D743C96CC5A8ULL, 0xB7ABD39A64DA77DCULL, 0x4E0F00DE7F7160AFULL, 0x083E71683C089B26ULL, 
            0x2C495601E2EEE84CULL, 0x2A51FEBCBA1DCCF0ULL, 0x2C19304462D9CDAAULL, 0x7A96765780547DA0ULL, 
            0x81A412396D709599ULL, 0x19688EA9AD92C4CAULL, 0x5247754E5E4617F8ULL, 0xD4716E5EC7CBB0A3ULL, 
            0x740501834D7E63D3ULL, 0x919F952A9F432934ULL, 0x68FD99F794FDCD60ULL, 0xA03E80D0CE09C65BULL, 
            0xE34C9E0A7D3E8B7CULL, 0x0F2424EB4D015A3BULL, 0x6EBA44DD857273ADULL, 0x6C58E930C01536BAULL, 
            0xE759717ACE0363AEULL, 0xC84351ABF27AC6F8ULL, 0x89F872802A640132ULL, 0x45AFAC256F2F6B90ULL, 
            0x693F810D5B2786E4ULL, 0x4B8A9417B06750FCULL, 0xCA6681FAA04EEACAULL, 0xAE735ACDC0941582ULL
        },
        {
            0x688E83608B9BBE66ULL, 0xAD9959C52E82F819ULL, 0x52018D448D237DE5ULL, 0x7C945EB89F4A2A72ULL, 
            0x326E8F1A96C71FBBULL, 0x63EF6E8ADD743B97ULL, 0x33A1FB236D9B2B96ULL, 0xF03BB36F492072E4ULL, 
            0xAE98E987F0A753A4ULL, 0x6B32245713C70078ULL, 0x7D2D747F3FB2DF20ULL, 0xE545BC95495C9FFFULL, 
            0xAA42B00338D2662DULL, 0xDBBF6DEB5B410C29ULL, 0x9773A694F0543CFAULL, 0x71C43AFD0062596BULL, 
            0xE0DCA5FAB40C469BULL, 0x0E594A06305AB854ULL, 0x320470C804E40D25ULL, 0x59DD2ACC1ECDB885ULL, 
            0x4BDD9E6A31482D88ULL, 0xD9FF94A3A04CBBCCULL, 0x813B80D662C63A69ULL, 0x3EBFD5C503716FF0ULL, 
            0xDD25F3ED2D6F9720ULL, 0xEBAA08F290F7893AULL, 0x49D30A498C488DBBULL, 0xE1316A4EFC576553ULL, 
            0xB2B41D90543C7A52ULL, 0x6BF5199C9D6F40A7ULL, 0xF62A631705CB1AFEULL, 0xCBF0B4DFB00BEE97ULL
        },
        {
            0xA489CF850502EC5AULL, 0x5383B327F5264CB1ULL, 0xD252397EDF96A8AEULL, 0x50AA1A9B7A278AB7ULL, 
            0xB2A8D987887E37BDULL, 0xC9BA2A42EDA4033FULL, 0x4BB484EC51AA1B87ULL, 0xB7ECD22FBDC1454EULL, 
            0x8B39A6585D054EACULL, 0x3272D988A3D7D49EULL, 0x7026DB302A70E64CULL, 0xABA190F2479AEA05ULL, 
            0x1D5FA0FFBB709AB4ULL, 0x28617CC708F268AFULL, 0xEA6EFC15476C369AULL, 0x933BA5F8D0728F4AULL, 
            0x9ED627827B9BAB93ULL, 0x4943DAA561D64A2EULL, 0x9B8B50A24A92CE6AULL, 0x76D35EDC4CF3D357ULL, 
            0x2F13713DE99134F0ULL, 0x61608290A1C070B9ULL, 0xB793C06F56ED974EULL, 0x30ECE48D01565EDAULL, 
            0xFCC1501F3BD2CD21ULL, 0x202EE6D72EDF4B19ULL, 0x7AFD69D4C8202D00ULL, 0xF72B35884F17257CULL, 
            0xBBC6BB55F486A405ULL, 0xE9F12830388717FDULL, 0xFC7101729C85D16BULL, 0xA2485F11B174D8E5ULL
        },
        {
            0x247701B2CBCAF002ULL, 0xD937232BE95883FFULL, 0x10B20B0FE5194A0BULL, 0x6B1461F39742F513ULL, 
            0x19211B8646E947A3ULL, 0x85041435D6E390CDULL, 0xB0CC58FDADBAA50AULL, 0x2ACF4A16E9C19374ULL, 
            0x7018FBBE71FBE66BULL, 0x840608D6381AEB9CULL, 0x08DEFB4341CDA349ULL, 0x4CD2E1A8C5E11DD2ULL, 
            0xCD8485FB31A2AF43ULL, 0x1573478C1202A56FULL, 0x03CE8D8CDCDB29C4ULL, 0x0962DAE3811E49FDULL, 
            0x09F1A13D44D4E213ULL, 0xF6EA41A8C2A7C750ULL, 0x93C3DC74B9B0354DULL, 0x5579F6505C36DDEFULL, 
            0x4CEE07CD156ECFA5ULL, 0x2465D5FDEC25131AULL, 0x4F21BC1753935821ULL, 0x9262321D7993970CULL, 
            0x0B5F91925A7C64CEULL, 0x954BEE931029FC5DULL, 0xBFA2D7342F00525BULL, 0x7D14884A95F7F53CULL, 
            0x070A5B81B5FD5D74ULL, 0x1E9F5DB409EC8F9BULL, 0x5FE5EA0CECA09FD2ULL, 0xAAC3AB685BD3D380ULL
        }
    },
    {
        {
            0xDF33992EC471DA14ULL, 0x7151C0A949304719ULL, 0x4B0DBBB58C0169ADULL, 0xBCBF4D123655E75DULL, 
            0x7851DF3678BE0585ULL, 0x6CA1866604482E73ULL, 0x17DB3330B34DF335ULL, 0xBE0F48F9380CD92FULL, 
            0xB7D09C955DC1BDAEULL, 0x35B83658C0BD38C3ULL, 0x34B4182CBC6B6E1DULL, 0xE4D0BB3A3D81BF50ULL, 
            0x72F7FC8C0C121239ULL, 0xEAD148EF4A9FC116ULL, 0x368094CCC2ACF617ULL, 0x0C385E8C71AFE2F7ULL, 
            0x2F1ED6B61F87567FULL, 0x00E26A3DD01507DAULL, 0xE6201C2C22385567ULL, 0x855CAAC2F72591CBULL, 
            0xBF5554B81B6BF3BBULL, 0xC21563A724CAF763ULL, 0x30948482BAED6C42ULL, 0xA6E22BE85F755FB4ULL, 
            0x821C51CF4A85EE28ULL, 0x8659C35748D649BFULL, 0x39628963692A799BULL, 0xC490F2AD896DD9A6ULL, 
            0x3364893EF2DA94C9ULL, 0x351A05CA2C0125ACULL, 0x06C522ED7E030063ULL, 0x308C245B0D4B09F4ULL
        },
        {
            0x23B303009313A34AULL, 0x28CF868272260295ULL, 0x608B612C88DB8A9DULL, 0xEA08FEB0227AAA87ULL, 
            0x3AF5B92615364433ULL, 0x751787F70E2A89F2ULL, 0x2D27F5ABF3DD3AB2ULL, 0x3BF8EB93F330EE75ULL, 
            0xA59D1946D4712077ULL, 0xD4FFFC356C5B2115ULL, 0x337170E35E0535F7ULL, 0x29A5B18BD8B3EA1BULL, 
            0xED7A1DA3EB4528D0ULL, 0xAF2A74B8A2DD9874ULL, 0xE4990E96FB3543A0ULL, 0x88122D360571751BULL, 
            0x0DCE1BCB02BE55ADULL, 0x475A1A7DD76AED88ULL, 0xBB3C8A6701BC995BULL, 0x507DDAF83431FB36ULL, 
            0xC98F49E2C763D711ULL, 0x347AC4103CE63661ULL, 0x4CBB9E0D85AD8ADCULL, 0x93576B7059695231ULL, 
            0x2DB390EA6A27B57AULL, 0x76D49B25DF67B6C8ULL, 0x04652DC62C84C6E6ULL, 0x0EE25A88268004CEULL, 
            0x70B5A256D6C906B5ULL, 0xA8AF73381D842F9BULL, 0xB389166F36463A88ULL, 0x87B141C06D3B5FF1ULL
        },
        {
            0xF7D3FA8C82B7A065ULL, 0x3814145D21294988ULL, 0x2E6E4D8FE141863BULL, 0xD67EB38B12F4C1ACULL, 
            0x20B8538E07A276B4ULL, 0xDF85635FFB046411ULL, 0xDD251986C232FACAULL, 0xD7EE740A4D4F5632ULL, 
            0xDEEAC65C9FB40D47ULL, 0x04A427BDAF9C36DFULL, 0x5B5EDA50CD4DE895ULL, 0xB8C7F46AFA61AFC8ULL, 
            0x7CD3F5B47F31CFD1ULL, 0x28C8D01EA2BDF83AULL, 0xB3B8820BD24690DAULL, 0x761EFED358C6EA07ULL, 
            0x32D4806F62E08624ULL, 0x2EC3889822C457DBULL, 0x830D57EC33197F48ULL, 0x4E90D135B77B8E77ULL, 
            0xFF82F5011424F49EULL, 0x676B9DB3E4800AD2ULL, 0x96659FF26E6A3B41ULL, 0xC3B32D066C836F57ULL, 
            0xCD123A693C308EE7ULL, 0xA910E193E9C3B444ULL, 0x2DCD53BB59BD3CBBULL, 0xE2E688B4B471DF43ULL, 
            0x3E7FB4469CD8FDA6ULL, 0xB07CA299E8E239CFULL, 0x5975786E130C736FULL, 0x165584F4275F3A60ULL
        },
        {
            0x48E4FD66D7C7FCE4ULL, 0x61B9FB07D396D41BULL, 0x8F3350F06F5FFE57ULL, 0x47B784D8CCC4BDFDULL, 
            0x1A30179A370A4893ULL, 0x9D25C5649D669CA5ULL, 0x9965AE349B695C43ULL, 0x0557EECFB1D5ABC0ULL, 
            0x1DF1510A7C86472CULL, 0x54AEB7FB0CB99BF7ULL, 0xC03AE1CE04C916B5ULL, 0xDF58C6A3BEC5062CULL, 
            0xFCEE6B5602C80BB3ULL, 0x5ADE195F7D748454ULL, 0x6E5E142B3776A62CULL, 0xB62FCCD8872CE4BAULL, 
            0x865DDA66175A7C8CULL, 0x4170AB40C074AC5CULL, 0xC93F91CC34BE48E2ULL, 0x739000BB8FA9B8F1ULL, 
            0xD162E382DBA5C168ULL, 0xBDE110BEE6909493ULL, 0x039B86CCDE14C54DULL, 0x77DEEA2AE8A1E807ULL, 
            0x3914ACD93CED424AULL, 0xDD1BF474B07D2AFDULL, 0x34BC20D5B1B9136DULL, 0x3069D23D0C5DF0D1ULL, 
            0xA4BECA332F2DCF47ULL, 0x5D2F6AFE2D3BF3FDULL, 0x554BA9111EDA439FULL, 0xB1978518632B6308ULL
        },
        {
            0xA319AD6B03A9B196ULL, 0x448491616CF661CDULL, 0xAFFC57807F3047BCULL, 0xF155118EFB5D4A00ULL, 
            0x8ADB3AEFBADD699FULL, 0xDF434AC0DCE41D2FULL, 0x94960D67B6FDD11EULL, 0xC9263A35946A3C9CULL, 
            0x04D9F03742F8D2D7ULL, 0x3BF1B745EDCD4C69ULL, 0xC3A213CF572E569EULL, 0xEBA3C8968BFEE480ULL, 
            0xFCFB298C4DB4B844ULL, 0xA697E20D013C4E2AULL, 0x6569C1FD9A623EE5ULL, 0xABDFA717DDF1D204ULL, 
            0x26437A7DDC0DABD8ULL, 0xDA0F0D14B2FE6EF8ULL, 0xF6F898F2B5FD92AEULL, 0x0BF04E5B019EF242ULL, 
            0x59741BDA45BF28A2ULL, 0x7CCDC0CC824B722DULL, 0xE168737629F00204ULL, 0x8469D206DC5DDD55ULL, 
            0xA487DEB1C6457CBEULL, 0x89C48E82852C7D1FULL, 0x72273E7F0952C6E9ULL, 0xACD8CF2C0550797EULL, 
            0x75432DD4B183EA83ULL, 0x9FE182666F4E1B0FULL, 0xE3E020CE43AFB374ULL, 0xC000EF5F752AF9AAULL
        },
        {
            0xFA134B4386BB308DULL, 0x9655AB4AE3720BD0ULL, 0xF0A4C02B7FB67947ULL, 0x88FC2BF633096F45ULL, 
            0x7D9A544A3FE49144ULL, 0xFD6D941274B23053ULL, 0x38E19DB66A0505ABULL, 0x3F6DD64D9FB6F8EFULL, 
            0x89E3AD035E4801ACULL, 0xA87559D6E0815C0EULL, 0x68DA54226E01EF53ULL, 0x747B7E50B51CFCA9ULL, 
            0x18933A4B7CA4B9A2ULL, 0x8C5C7C1391DDC188ULL, 0xC260F092336CA8C3ULL, 0x0C26BB20A0A25344ULL, 
            0x383CB5B39F56281AULL, 0xF2758199EB334893ULL, 0x8E98D207B03A6CA5ULL, 0x2C1A33ADBEC8491FULL, 
            0xBA69C550848435FDULL, 0xCA8B6ADCD0DA12D8ULL, 0x2376297A64D2F172ULL, 0x0EDE9C834624A701ULL, 
            0xA16161E36E4AEA40ULL, 0x011CEF572895F1D7ULL, 0x30B37C94D9ED8F6CULL, 0x9C936D0F2C18E8EEULL, 
            0xC2C7DA90A2700572ULL, 0x4FCF13ED1F8D9DCBULL, 0x96B6FCDE85C723F4ULL, 0x567DD9D962A0CC8CULL
        }
    },
    {
        {
            0xDB4DE9EF4C41DABDULL, 0xA50F04C56BCD7C5DULL, 0xCF2F70D1AF4F009AULL, 0x41FA1BA96A14BC8FULL, 
            0xE4AFA723CD013AB8ULL, 0xA0B09DE6D731AADDULL, 0x52FD05D4AA3E3DC5ULL, 0x6B83E96457395CD2ULL, 
            0xBB2D6E1F0A31B31EULL, 0xAA5B77D9CD915356ULL, 0x34BD1F8CBA8667C6ULL, 0x2FB8BBF33E60EBC3ULL, 
            0x0858AE00AAC2F69BULL, 0xF3B35218F3018567ULL, 0x5C83E1F52D62BB2CULL, 0x75B504F7B06E218BULL, 
            0x8E860E03DF144A8DULL, 0x0AD3F4DAA45EC201ULL, 0xD88FAEBF086DAD34ULL, 0xB72F8BB71A33C023ULL, 
            0x66BE5807CCB74EEDULL, 0x963A9D15D2594ADFULL, 0xE32A980CEE47CC8DULL, 0x01DD8D3DC7D9A398ULL, 
            0x9647B0DCFCB46222ULL, 0x47F0ABAE0213F9E3ULL, 0x7B79270CC17BDEBFULL, 0x66E2EC0F31ACD3D7ULL, 
            0x00CC48C60CBF9990ULL, 0xDBD2D57758270436ULL, 0xF201973908DAA2A8ULL, 0xA8ECC81917D1249BULL
        },
        {
            0x5CA8A4A4B1B82447ULL, 0x3755A00B7711058EULL, 0xD9F042825B90A839ULL, 0x8892138CEC3D8B70ULL, 
            0xF0CB148E95658F08ULL, 0xF5E5C7D319AF1970ULL, 0x6F5F70D46991E5DFULL, 0xCE7E5437E50CADA3ULL, 
            0x1401C2B75A2D151EULL, 0xA8C932EA5197A0B4ULL, 0x2D9C49DA608523DAULL, 0x5652677B33A0A74DULL, 
            0xAFE5DBA5EFC0F8CAULL, 0x85E9553761CB4EBEULL, 0xB956D286B141D753ULL, 0x3A5C385DC6A6C579ULL, 
            0xEC137BDDFC222B86ULL, 0xF3B09F31E662705BULL, 0xA84A815C76905312ULL, 0x03A4BABA8C5AAE67ULL, 
            0x7149815ACC496222ULL, 0xD069951CFFBCEFE7ULL, 0xBAAF1B8BA1275C10ULL, 0x109C9C90A0E686FBULL, 
            0xCA8E3C2ED5CF8C8FULL, 0xB7E289C4C36FFC94ULL, 0x95848723D47EB90DULL, 0x03F7223B17136C6DULL, 
            0xF6B557E39860CC11ULL, 0x3ECF04E55CC460CEULL, 0xB17B94BA75D8CB52ULL, 0x381C2EC8CC19F06AULL
        },
        {
            0x6A1BB278BAF6102FULL, 0x4938639DB86390C1ULL, 0x0F88ED45B1E7798AULL, 0x17023A3F8820D0F7ULL, 
            0x87E33032F3E7A62AULL, 0x901550968CCBA3EFULL, 0x294788CCD88A72B6ULL, 0x386684BA8C233133ULL, 
            0xB440CE8F252F5E21ULL, 0xD1CFF2536D692427ULL, 0xDA35BA17CC217A04ULL, 0xB0855EE10183CE6DULL, 
            0x4ACE1901F0D57406ULL, 0x09FD921BC182613EULL, 0x4BB68F4BCF0902EEULL, 0x9C54ECE36FB49F70ULL, 
            0xF1C38C0AB45FD520ULL, 0x0ED34423B52E0164ULL, 0x4562DC42BBEAFE20ULL, 0xFF56B00F06E95654ULL, 
            0xE34259FAA7F6FF29ULL, 0x8E218920AF10CF0CULL, 0xF1738A5A023CFE37ULL, 0xD456740CB382F99DULL, 
            0x0BEFC6F3A963E24EULL, 0xE6063F6D56141F7AULL, 0x4CA676101B1D2E22ULL, 0xE7897CC7F5477F99ULL, 
            0x30BFD7C35D612888ULL, 0x0CC1B313ED7CC681ULL, 0x934092C13F34A060ULL, 0x5A2232022CD4093BULL
        },
        {
            0xE4CBE79198156BF1ULL, 0x035A165C005CE313ULL, 0x04ECDF2B716C14ACULL, 0x359DF55C4F1CC08BULL, 
            0x21BB1ADB1D06E178ULL, 0x8A38BEAD046C3FD2ULL, 0x1C13A7A9A197A57DULL, 0xA0E1D9987EADD551ULL, 
            0xA31038D524299C54ULL, 0xB7BE2B9867DCDCF3ULL, 0x364B05DADEB0E7A0ULL, 0xF88FF06D60E8DBC5ULL, 
            0x2EE356ECC5CDA89DULL, 0x5A6ED05F74097279ULL, 0x1E107416E5402D3BULL, 0xEDA6C0AC99A07FD8ULL, 
            0x3901B1DE5AE9E1D4ULL, 0x20BD228F5481DBE4ULL, 0x29B387251CBE91BAULL, 0xB32E102E7C82A2E2ULL, 
            0x5CFA0A1E1B39A6B6ULL, 0x94D1EB4944F8E166ULL, 0xEC46A42B8A32E2FCULL, 0xD71D974EB5413FD3ULL, 
            0x70E49695DF419A75ULL, 0x74BA8A758F9B8562ULL, 0x80B1AB968D02DD15ULL, 0xB92B862202113C59ULL, 
            0xB323346C91681C64ULL, 0xFDED5B38A58D2ECCULL, 0x46DFAF9E1BE9AB1EULL, 0x33D4842FB903AC80ULL
        },
        {
            0x44D29019A292D9A3ULL, 0x014BC8F7EAABB637ULL, 0xA0E68B9458D656C5ULL, 0x0D0B4D9F7526349FULL, 
            0xFFD7E3231EE83E51ULL, 0xFFA41283CA7ED1E6ULL, 0xE8FFFA7299C8FAF8ULL, 0x590E4D01D0B4E154ULL, 
            0xFAE5CF55469D164DULL, 0xAF95D168D34216A1ULL, 0xEF728079B028B3B8ULL, 0x9884EB4D5CF63D4FULL, 
            0xAA977F33C4B145A8ULL, 0x0815DF9123BC29FCULL, 0xDA703D92BFE549A8ULL, 0x7EAD4353F1FB7F57ULL, 
            0xEC3FC96E9DB0E5A9ULL, 0x225159008E18EAD0ULL, 0x7167833D4352611FULL, 0x895B1B8698AB8EF3ULL, 
            0x20249ADBB9451EFFULL, 0xD1E72521CB59372CULL, 0x141210137B331DC1ULL, 0x1EF3678BF686B4FFULL, 
            0x9F72AEC0C10674CFULL, 0xBB6D7B536CF14672ULL, 0x18E650DA86018875ULL, 0xB1AF76A333DCF76FULL, 
            0x84DAE016DC5EA54BULL, 0x58AADCD6A38C1F9BULL, 0x097EA937961A3940ULL, 0xACE153591C3CBF31ULL
        },
        {
            0xB902146462494946ULL, 0xE72A9DCAC84B5CD7ULL, 0x04D1E7A148CD8FD8ULL, 0x838C1B493B960773ULL, 
            0x62679B601DAC65E7ULL, 0x491DF132E5FB9246ULL, 0x12062FA01561F9E4ULL, 0x1CF55B65DAE94A1AULL, 
            0x2F47B11229D2742FULL, 0xAA9C86A55C08DBFBULL, 0xF7286890873BED84ULL, 0x0701314639FC9F9EULL, 
            0x4928C0A0E574BA61ULL, 0xE64ED0CEE38AA9ACULL, 0x2B438DEDB0CB6964ULL, 0x0D0DF01820E6F338ULL, 
            0x8CE9ADBAE50B1EF6ULL, 0x4F7DF2DC6B3D0795ULL, 0x5D6706BBCE7D03D4ULL, 0x729901E0F360D46BULL, 
            0xB841E839591E9730ULL, 0xDD93753393B5FF21ULL, 0xFD0D48496B9C7C51ULL, 0x7D11D26EC5714A5FULL, 
            0xC266FE83CFC264BBULL, 0x52CB09784AE0F845ULL, 0x89B46DEB99C2FB4AULL, 0x45304AEC8FEDDB42ULL, 
            0x6058A9E1E6B48249ULL, 0x6FB9AB6E61E8A9DBULL, 0x3EC9AD0CA36747E6ULL, 0x99218C2616D3071EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseEConstants = {
    0x0E73BD7C2007C278ULL,
    0xC0C1C241D9CEF644ULL,
    0x0A282A596468017FULL,
    0x0E73BD7C2007C278ULL,
    0xC0C1C241D9CEF644ULL,
    0x0A282A596468017FULL,
    0x37D1420A8A962A35ULL,
    0x9B21D1D01FC705A0ULL,
    0xB8,
    0xAE,
    0x53,
    0xD8,
    0x37,
    0xCE,
    0x65,
    0x3F
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseFSalts = {
    {
        {
            0x7F7645E54774D076ULL, 0x3CBCB6327EDFF6F8ULL, 0xD28D1917E740B74EULL, 0x8255BD2EF1B8B6E5ULL, 
            0xB2889B3FCC77B9BDULL, 0x418F752982C91F26ULL, 0x92CE23AC0382323DULL, 0x06CFEA555DE05FE2ULL, 
            0x400D986D89F6E915ULL, 0x80FAC4741B0A566EULL, 0xED166D43A36F79FBULL, 0x92AD12A4839BA257ULL, 
            0x5D642C5B373BC0AEULL, 0x068B8F1F29456BA9ULL, 0x75571B67DEBE3E18ULL, 0xE32EC23007C6146CULL, 
            0x3F42051C65D1E86DULL, 0x19033FBB9DE32B10ULL, 0x87E7087CEDA12A56ULL, 0x1C889F28F92C5DA5ULL, 
            0xDB95FD575028FCF2ULL, 0x0A05DFA14E244884ULL, 0x8084C8CBD6B18C17ULL, 0x50FE2391A24754FDULL, 
            0x20CD8A21E7063489ULL, 0xBD8DAC81DEE8F089ULL, 0xBBC607AC5C7E7E78ULL, 0xB2816E911C2044DCULL, 
            0xA067B5AB59D78690ULL, 0x94F6D4E8C08F1B3AULL, 0x3178D605E557D486ULL, 0x6CD65278AB2ED695ULL
        },
        {
            0xC7ADAE0AFD5730D5ULL, 0x11308990A5DF819BULL, 0x8E8511AF9EE10CF3ULL, 0xC8E6A4B1BD4F4754ULL, 
            0x1F22E044FE34C9ECULL, 0xE88D2C212337EA72ULL, 0x09CEEBFF081A2949ULL, 0x75E5B44B0466A01FULL, 
            0xFF7F35DC8DA4F69AULL, 0xD3972F5A91801725ULL, 0xE530267862CA9EECULL, 0x55C45F121E403EA7ULL, 
            0xA4ABE8250CB8D7DEULL, 0x579B1AEF6F2EE741ULL, 0x87EB5DCF1C616D73ULL, 0x28F3F6E13FAEDFBEULL, 
            0x5C26BA504833B06DULL, 0xBB5860E6FA16A8ECULL, 0x296C5B9FBE36D32AULL, 0x473830BC16DD4D08ULL, 
            0xD0D10474EACD33EFULL, 0x58332ADD6706AA79ULL, 0x42747A0C8DEA9CE9ULL, 0xAC89D8BE634D3DCCULL, 
            0x1FDC8C20A76447E7ULL, 0x9399B424B61C22E0ULL, 0x8FEA54F9E04F5386ULL, 0xBB9022A9367D5317ULL, 
            0x753156F5AE4388FDULL, 0x04D0B5102DB24DBCULL, 0xB8E10C6BB9D2B8A6ULL, 0xD9FCB4323A89AE16ULL
        },
        {
            0x38893DC92F1B0E62ULL, 0x60290BB2E4D664CEULL, 0x90F15B57011892EDULL, 0x53D70D5AAE880032ULL, 
            0x6DE27CD4B86FDDB6ULL, 0xDAEB2F42859E164DULL, 0x35DBD77F18E8BB43ULL, 0x769D66E5AE329C67ULL, 
            0x172EBBAE47AA2A2FULL, 0x8623C3BB7653F6C1ULL, 0x3F2512892B0D503EULL, 0x08FE5F44EF4FD33DULL, 
            0x9B7AF480F7374B84ULL, 0x9203ACB1E1A8A7DEULL, 0xF8FF18B1D0C62256ULL, 0x8B3348845E862B71ULL, 
            0xC8748F8E5F03B198ULL, 0x48EC0776B1FF647DULL, 0xAA71A78584B07C32ULL, 0x82F8DA2AB28FA616ULL, 
            0x08D443F6DEF7A880ULL, 0xDA81205A3BC62301ULL, 0x0F2C532AB09A85C2ULL, 0x9F7E3B3F3C4A0C5DULL, 
            0xFA8AB8DBDBE9586BULL, 0x6B815093980CADFFULL, 0xD800642E55DB4F69ULL, 0x576986A5E9459E60ULL, 
            0x0EAB2C1E872BD25BULL, 0xCCC428BF380B5724ULL, 0x3346B218D9AA1285ULL, 0x2A28A3377C1AFF9EULL
        },
        {
            0x783881E6FF1FC074ULL, 0x156637924409E732ULL, 0xAA0283071158BB59ULL, 0xDED51A024E80E16FULL, 
            0x8A1039E3B7AEE5CFULL, 0x85A9833AF6BE5DB8ULL, 0x2D1A61A3752AF3F7ULL, 0x1118B32A072AED2CULL, 
            0xF696042E5C86054AULL, 0x9D98A620B7874C3BULL, 0xE6952E83A4CF0D63ULL, 0xF69E3B02F42C4DD2ULL, 
            0x5EBEE6C29589B95FULL, 0x56B34AB4C879DBF1ULL, 0x67BD5A1961D9B54EULL, 0xF3812341A4D5792CULL, 
            0x87D253203AC2AA7EULL, 0x5DBD8292F6FA35A0ULL, 0x9DDEB95338ECC4CAULL, 0x5455A318F2103CBBULL, 
            0xB446973AF9B00FA1ULL, 0x7F69998F8F23D335ULL, 0x56D234E53A28F990ULL, 0xF6FB9902C9EA5B77ULL, 
            0x39149668DBEC5748ULL, 0xB7A9300A92C10907ULL, 0x0BD0A036D7CDCBCCULL, 0x8A90303A1405DD3CULL, 
            0xFCE1D0743D095220ULL, 0xEA2CF9505AB132FFULL, 0x1D865C18EF810314ULL, 0xE3A9F4C95E63171DULL
        },
        {
            0x67E3508692320BE2ULL, 0x95614297E1FC9B7CULL, 0xC3F00817DC6F4317ULL, 0x81DFD75F42C61814ULL, 
            0x89C03AE4459AE7C5ULL, 0xCD29A5902714C764ULL, 0x8A030F72913FC21EULL, 0xFC1A94DB67BE7B1DULL, 
            0xA69880395B797468ULL, 0x384579DC00E3B989ULL, 0xCE31FF41369CFE2BULL, 0x26CC1E99EFF6A623ULL, 
            0xBF640C849AC2BCCBULL, 0x52DD9DED0EA29A12ULL, 0x387EDA9E2C7D5C45ULL, 0xF95A5115545E4CE4ULL, 
            0xE1E91FC8B0244419ULL, 0xCFFA356660FD8417ULL, 0x102C6D7D8FD92825ULL, 0xF231B5B32F817781ULL, 
            0xD1BB6A36C9B7C9B0ULL, 0xE63A894AE3AA6339ULL, 0x7FBA0D637201A3B4ULL, 0x8CE05BD254E6E0E7ULL, 
            0x3A2C7626ECE1C29FULL, 0xB21047B97B189FF1ULL, 0xAC8C853DA1B32AEEULL, 0x91D63BC360C817A8ULL, 
            0xB403B011A951E956ULL, 0xD25DDFD83AFADAE3ULL, 0x7CC434D7870AE374ULL, 0x0D945644CE44BB65ULL
        },
        {
            0xB6431635AAC93EB3ULL, 0xDDD45A114D9B3CA1ULL, 0x1597B366A576CDE6ULL, 0x705337C23FACFF84ULL, 
            0xD110809C86DE21A6ULL, 0xEBDFDB8FBD3EBA38ULL, 0xFFDD4E697B8347ACULL, 0x9E2B5708EC4B13C9ULL, 
            0x28532ED4ADE7F2C5ULL, 0xBA836C07F4B39EC8ULL, 0x2C9E3CDA3534F858ULL, 0x1A65666A7ADB6A36ULL, 
            0xCDA8A45AD3AA1549ULL, 0xCEE84EAF80ED2EBCULL, 0x7DA40CB0EB8E9DB7ULL, 0xDD936A5748EE1945ULL, 
            0x976F7C1273A89BCAULL, 0xF15874F59FED1D30ULL, 0x140216B30813512AULL, 0x8E749C90309824FDULL, 
            0xEFCB134A28254C42ULL, 0x6301068391D29F28ULL, 0x2454C5AFA5AD2D98ULL, 0xFA4BE47422B55029ULL, 
            0x6C2B4222B38D9477ULL, 0x7D0D36A6005764BCULL, 0x9FA634DF3FC4302AULL, 0xB38131C041CB4360ULL, 
            0x4F316DD78919AD4FULL, 0x4AA0115F4D30B615ULL, 0xD9D4B26EE0C21AC6ULL, 0xA960721AD2F3AD25ULL
        }
    },
    {
        {
            0x058CD41E3482FFD3ULL, 0xAA954A9436AC0335ULL, 0xF477171FE0273543ULL, 0x7D9894ABD10FFBF7ULL, 
            0x49C48A4E74114538ULL, 0x8CFC344BB39E114EULL, 0xD3ADDFEE0F50C2D6ULL, 0x80D818160BADB5A6ULL, 
            0xA8A867202C3C0652ULL, 0xBD257C9F466AD1B1ULL, 0x85AAC7435CF5EA71ULL, 0xB101FEC2C54F1B04ULL, 
            0xC2A955A6EF3579C5ULL, 0xBC81CDF3EF1F0520ULL, 0x7147DBC63418BE68ULL, 0xC366C3BF35298221ULL, 
            0x2154F556A06D5C65ULL, 0xDF90B13E99ED79BBULL, 0xCA4DAD344FC978C5ULL, 0x761140AD78503DECULL, 
            0x4438D3845E04F5D8ULL, 0xE9833D80EC481BC0ULL, 0xA424BA1FDF6AAA57ULL, 0x25906612D66A9DB0ULL, 
            0xBED74F58FA5E9C38ULL, 0x44D5F239BF162BD9ULL, 0xD007984381E8899CULL, 0xB5D9FAF3BA7AC40CULL, 
            0x9E135F522BC3C985ULL, 0x9B8B0BA7096C309FULL, 0x87C04CEA6568C41FULL, 0x7AD6190A1515F19EULL
        },
        {
            0xC47F0B129227B036ULL, 0x952819F6AB74C6C8ULL, 0xBD99BF8AA11852C5ULL, 0xE2DE62F0DC680F0BULL, 
            0x51E9B35FA56572E6ULL, 0x151F51CDE043F06EULL, 0x53A870FB522F617BULL, 0x71D800DB0B55C61EULL, 
            0x995FD5F87FB066A1ULL, 0x74534B769B0301D4ULL, 0x85E237EE95F8580DULL, 0xB8C260136437EA2DULL, 
            0x826704ECE287796AULL, 0xCCF50D09B0C1E9CCULL, 0x4C07DAD5D535F65FULL, 0xAAC1C9F4B79CB737ULL, 
            0x02E11C81A24FF30CULL, 0x2828CD6A2CDED1FDULL, 0xDBFBAF3D62D2859BULL, 0xD67779306BC2D51DULL, 
            0xC4A4632158ACB7FBULL, 0xB59D945ABF3A47D2ULL, 0xD048EEF446B01A62ULL, 0x262A48495C44D324ULL, 
            0x1BA664BBBDFA33ECULL, 0xEB5F7D9B1FC123E3ULL, 0x42F367F164B5E989ULL, 0x6399C596D56FEF29ULL, 
            0xFC2C6C29203E2679ULL, 0xD24103D495EF5270ULL, 0xE8BC6F28D605A4F6ULL, 0x5112DDE09C6D8DBCULL
        },
        {
            0xAEC66C1512FDA64CULL, 0x26DF3387BBE08917ULL, 0x260CEE017B9A0098ULL, 0x2D18D5F52DF46DCAULL, 
            0xAA17D11165898BADULL, 0x7965884105D6B3B7ULL, 0xECAE3A75D81327A5ULL, 0x0CF4DCC3A0ACA110ULL, 
            0xCAE36BA8141DC425ULL, 0xF036B98FF2452E70ULL, 0xC1B207B8F51D45C5ULL, 0x0AA662AC9F89762CULL, 
            0xC94ED1DF611011BDULL, 0xAA92F0DA5114362EULL, 0xE9BF65EFF91BF262ULL, 0x053ABD42A63A8BEEULL, 
            0x3774B424AE3FDE28ULL, 0x204902746B476BBEULL, 0x30CED2191BF391CDULL, 0xBFCE00EC7B47C0B2ULL, 
            0x081A3AD9F0038256ULL, 0xC0C8E3F7BE179AC6ULL, 0x4D0B4C67BD67E326ULL, 0x9836C7C15BAC12EEULL, 
            0xCE4DC850013565C1ULL, 0xC733E95A88A16D1BULL, 0xD69D745B2833E9BFULL, 0x0F276EC458478F4DULL, 
            0x776A4AF7DDACF098ULL, 0x9398BB2048977A3FULL, 0x337FF71A401B2658ULL, 0xD2604E3A91964A5DULL
        },
        {
            0x665D0F74CB951A81ULL, 0x824D52C36CF3C565ULL, 0xDB199B4E2FF55CDEULL, 0x57C3EABE868F7E8FULL, 
            0xBF6AC6EBA55E2AF2ULL, 0xFC5057B0418C78EBULL, 0x77BCDE8BBFB0E7B3ULL, 0x0641620C0F4735E4ULL, 
            0xE8B74C0800955C49ULL, 0x729A14A6BD062943ULL, 0xB1ABE3528ED19E79ULL, 0xF92DAC821BD80377ULL, 
            0xD1724281C08C7099ULL, 0xB39D865FF62017DAULL, 0xC6CA1751EDD743B1ULL, 0xAA71635368EC169DULL, 
            0x86A17A7C6CE52041ULL, 0x004B9B65A71A88B0ULL, 0xD16CF89D95C54E86ULL, 0x50FBEDC670545A95ULL, 
            0x668BC0CA412969C2ULL, 0x6D65DBE749E93958ULL, 0xDCF083F021B87B49ULL, 0xA46A7D6BC9BAC195ULL, 
            0xBA07C5F2890F5175ULL, 0xC785CBE5A9EDD736ULL, 0xDF78F4C6C8EE2C2EULL, 0x017B455334FE74C9ULL, 
            0x670C41D174548E5DULL, 0x0B03CBCBFE92FDCDULL, 0xE97A6C306DB9A5A5ULL, 0x6EB84E38E4180655ULL
        },
        {
            0x7C8CF00B469D4A0BULL, 0x10E572A7DCFDD538ULL, 0x04FAC0E013071404ULL, 0xAC5B95D42F9F3366ULL, 
            0x0367B7894570FB86ULL, 0xB4D2E2AFFBBD2CEEULL, 0x6614F8A9B045C0E2ULL, 0xE38BF4C3982077A9ULL, 
            0xD23ED0A1B4CDF261ULL, 0x2CC0162E475A441CULL, 0xEE2545B46DD10238ULL, 0xD859E5399D0FE410ULL, 
            0x75C3EEC4AEB09E59ULL, 0xAA83E6F7ECFA6093ULL, 0xB9C051C6E467E625ULL, 0x1CBB047C5DAAE354ULL, 
            0x3DFF63905FDB373DULL, 0xFAF2C8730342FE66ULL, 0x74569EDE40A8C8BFULL, 0x64BC9BCED29CD41CULL, 
            0xA1C8CC239DCC6CF8ULL, 0xBF175A58537D6342ULL, 0x176CF55E5360A692ULL, 0x11835940F62E05EEULL, 
            0x36054F57D6FA4215ULL, 0xB4BC07F0B5DF3D87ULL, 0x91B55AE1040983E1ULL, 0x3295188A89DBCDB1ULL, 
            0x121F4116FC076312ULL, 0x53EEC89B99F645F2ULL, 0xD10A3B7AA3E00EA4ULL, 0x5E00C3051C49D5C3ULL
        },
        {
            0x49AACF0D7E8A90C4ULL, 0xB0C55C91F290CF71ULL, 0xFD4B2A1EAD3383C9ULL, 0x58F6AF5DFF736B05ULL, 
            0xDF59D7BAF80F5A18ULL, 0xD74D7A7BCDAF43D6ULL, 0xADED7ABA4828D181ULL, 0xA41B5A9882FDC0ABULL, 
            0x973B89352549ECE7ULL, 0xB9BD8001D3BE5FD2ULL, 0x70C1D9F393ACEA8BULL, 0x7001FB317AA88F04ULL, 
            0x410927ED91CEC7EEULL, 0xCB5BC99601016EDAULL, 0x81D4837E215ADF34ULL, 0xE76E4423DE953864ULL, 
            0x5A9CBB39574713FBULL, 0x5783C9B68F9A6F56ULL, 0xCA99E1C000C54B80ULL, 0x69C21C5B86C4F538ULL, 
            0x474E427A45F3B5AFULL, 0x74A2EAFDA55C1DE5ULL, 0x05ED3EA985F58B41ULL, 0x1F424370A4DA1B55ULL, 
            0x3DB0FB38D88016FDULL, 0xCE8AC250E6DB6CBAULL, 0x2AA801E56139687DULL, 0x45E6772C48A87F36ULL, 
            0x34959E21400CFBE1ULL, 0x4506322894FB5EF2ULL, 0x18256AD45B96405CULL, 0xAFD3A6E9CD62C25DULL
        }
    },
    {
        {
            0x0BA146A9F01E414BULL, 0x676B64A06AB672BBULL, 0xB9E6AC3BD5CA495FULL, 0xD366C893D9934968ULL, 
            0xCA5EA1B744AF8929ULL, 0x4622986CDD8B7F50ULL, 0x12F14F6F14D5B98BULL, 0x03A49F373C730B2EULL, 
            0x64B140F003987836ULL, 0x2BFF85AC2DC51CD5ULL, 0xBF327F9260853F22ULL, 0x553772D26C399BC7ULL, 
            0x04A3C8EC235C6153ULL, 0xB1803AD050AD94BEULL, 0x7FD1E0335ED4C48EULL, 0xB024093C632EF0A7ULL, 
            0x728771097B356D13ULL, 0x9FD373AA2BCFB3CEULL, 0x5FF56170EB9B9BDCULL, 0xD9F86596370BF479ULL, 
            0x5A0C15776C0F3AEBULL, 0x421AD97C248B57B9ULL, 0xB08327380E5BEEEFULL, 0xBD5AD6A974726705ULL, 
            0x43C9B80A57701C70ULL, 0x8EE1F1A29265C5F9ULL, 0xFA18817AD623FCB8ULL, 0x9432BBECE8608206ULL, 
            0x137C8EE65189A023ULL, 0xF20D31AAB95A8311ULL, 0x58444E62D4F609CBULL, 0xF9D4BF920A5FA941ULL
        },
        {
            0xB59F4502D545E6B4ULL, 0x6CEDE9AD2DFAEC0FULL, 0xA2593105AFADB640ULL, 0x074D2E5434D0D266ULL, 
            0xFE85F4EFE1B2A7D6ULL, 0x56D3296C236AEBF3ULL, 0xD4214FE5B3133BE9ULL, 0x49027A424262ACF8ULL, 
            0x9824D9F4089423D5ULL, 0xC3BDAA88A07C612DULL, 0x537AE0857AF52D45ULL, 0x156BD5C0D4F082C2ULL, 
            0x5A8E061CEDAC9093ULL, 0x08063BAF26067816ULL, 0x76EBD976BBF10827ULL, 0x92F40A2AAD1DCC95ULL, 
            0xF1CBF5A5569008CEULL, 0x3FD65A4F71CBFEEDULL, 0x1A21AB1318AAE21EULL, 0x2C235E2DC4F89DA2ULL, 
            0xCB3BBF293F338625ULL, 0xE0851E22F89A3D3FULL, 0x8F61198E287B3AABULL, 0x6CC3E632D2F8924BULL, 
            0x6DAB97E11E073786ULL, 0xCBEAAA86C47C5837ULL, 0x19DDB5BFDCEB7F7AULL, 0xCCE9701ABDB6D2ABULL, 
            0xDCEA9446838281DBULL, 0x81E8D7A1DD6482DCULL, 0x1A1A52BB48169244ULL, 0x8F1A0A1DE29B286AULL
        },
        {
            0xBD975A19D5C6709CULL, 0xCD1C3A0941152FEDULL, 0x66504DCF873301D4ULL, 0x14767B568ADE3012ULL, 
            0x5C575EFD32C7C01FULL, 0xD93D5D5AEE3CB54DULL, 0x61BDA054FBA2B877ULL, 0x0BFBFF9538C45912ULL, 
            0xD249754F5F85FA47ULL, 0xDD2A1CE218E91D9EULL, 0x8857AEC1AAC4CF93ULL, 0x9E58EE927A930DBFULL, 
            0x74F0C6D606C7C075ULL, 0xF957F976C147B80DULL, 0x80BE663B6D551742ULL, 0x288D62B72B777BBEULL, 
            0x3957BB089B06FD5FULL, 0x5C2804D7D119C8D0ULL, 0x7F736F5BA37A11CCULL, 0x04D363596B959316ULL, 
            0xEE4B8C8576B15ECFULL, 0xB1495F196FDE1A07ULL, 0x540FE033737AFC45ULL, 0x25C3E2657CE4510BULL, 
            0xF9CD56FBEADE7DADULL, 0xDC0C181E88F521CBULL, 0x048234E704493636ULL, 0x385345A35DC4DAD5ULL, 
            0x0A2E6CE8436240E8ULL, 0x3C2CCC1B5EEFCFECULL, 0xFBEBF95ABF8DC17DULL, 0xB0DC161E53172BA7ULL
        },
        {
            0x60886DDF1F1ABCB6ULL, 0xD115AD0872288CB1ULL, 0x459DE65871BAC644ULL, 0x10B3C407311A8368ULL, 
            0x15C1F2CFC8C3B436ULL, 0x1CF32580EC5B392DULL, 0x8AB349BE480EE052ULL, 0xEBDB459597B052BCULL, 
            0xB1EB3D851CB86EF9ULL, 0x0F3A361E598F4147ULL, 0x2B24B258A8DBF609ULL, 0x69C4BD6FAAEC9AE3ULL, 
            0x888DEEEE845EA370ULL, 0x502C9CC88D3CD67CULL, 0x8D8A63B6F266885DULL, 0x1D343436DA343745ULL, 
            0xB80A802D6E3903F7ULL, 0x6723D3BE15FCAF7DULL, 0x846634628B6F5893ULL, 0x27BD928DED13D979ULL, 
            0x550E201C53E93866ULL, 0xA55D0C21927990DEULL, 0x9888D12CA05F3697ULL, 0xCCA748ED8FD96A8DULL, 
            0x13B8084AEB7BB46AULL, 0x4F2ED404E6A66D65ULL, 0x9CF384ADF7ED38F0ULL, 0x92461926594E9226ULL, 
            0x82FA723F1B4E5476ULL, 0x3F4878FC18566E97ULL, 0x98E2B3F68190752FULL, 0xEAFEC3693C027D52ULL
        },
        {
            0x0ECAB87E572D4022ULL, 0xA3171758D7E55C4EULL, 0x6AEF20A6D54A4954ULL, 0x229D83039AFC6316ULL, 
            0x700EC18557F75CB0ULL, 0xF89FA94482D46F76ULL, 0x4C129EBE42B985E7ULL, 0x15E187FA3FBC77A6ULL, 
            0x97A35490AF3E514FULL, 0x6B304BFC5480AC83ULL, 0x26AF3907005A3AE0ULL, 0xA7BCEBEC8955B746ULL, 
            0x6C67ECA8390C82A0ULL, 0x2CBA45F616A4C8B5ULL, 0x25DCE3DC9756F911ULL, 0xF077340ED4E0E08BULL, 
            0x50912E5853CC2994ULL, 0xBCAE8C7059921A55ULL, 0x086657FC0274F0B8ULL, 0x1B7DB3B508F909F8ULL, 
            0x6C695FB730BA9798ULL, 0xBB7AFD53CF2EEB72ULL, 0xB050EC9994705D3EULL, 0x2EEF2F02E75230C1ULL, 
            0xF5D72204E72D07E6ULL, 0xFE8924A44905C2C8ULL, 0x800811DC7D39B3E5ULL, 0x74DEF3DB2E459942ULL, 
            0x5BCB8669292FDB8DULL, 0x1C42B4F7A0EED67AULL, 0xCADEA2D02C4162E0ULL, 0xAC438F920D9A0609ULL
        },
        {
            0x64E4A80D4FE92ACAULL, 0xBB46CA0AACF5B2E3ULL, 0x0A4342FA73C4E12FULL, 0x9DB26FDE19306008ULL, 
            0x1D98D196AA79728AULL, 0xC9D2040440E1E0BDULL, 0xE0A49F9ECE829BB1ULL, 0x20C6EE7B328C8AB2ULL, 
            0x9DBB7AD18F876200ULL, 0x82634D02B19B5298ULL, 0x4614F6377290DEC9ULL, 0x1C0BFC20D3B06D0FULL, 
            0x05179D72B72E1A6BULL, 0x1D12B985ABCEC541ULL, 0x2150FD9459519FF0ULL, 0x7A85B7C69739CF8AULL, 
            0x94D7B85DF8B57E01ULL, 0xDBA09AA96103676CULL, 0xD0577E63AF480218ULL, 0xBC6D40A5442BD0EAULL, 
            0xB3E5F7DB91B7545DULL, 0xE47D292A2FC7B556ULL, 0x6256C55FEF0D2724ULL, 0x721F55FCE6AD0FB7ULL, 
            0x1DFD52872785F77EULL, 0x008820475529D9C1ULL, 0xC000020F4BD7E71FULL, 0xD5C47FFCBDA41E78ULL, 
            0x69756AE850819283ULL, 0x33DAC3140F578217ULL, 0xABB76AF57A24FBFDULL, 0xDE269A2398AFAC9EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseFConstants = {
    0x9CD7257C20D0E242ULL,
    0xB513B2CEC63773B0ULL,
    0x0BC2F6614FA3E452ULL,
    0x9CD7257C20D0E242ULL,
    0xB513B2CEC63773B0ULL,
    0x0BC2F6614FA3E452ULL,
    0x1CA425F692357CB1ULL,
    0x85C54204A4BCC00AULL,
    0x19,
    0x6C,
    0x01,
    0x62,
    0x03,
    0x0D,
    0x34,
    0x1F
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseGSalts = {
    {
        {
            0x1A5B2AE266A0F8AAULL, 0x664DD52C61F1AC3EULL, 0xB0950D00A4545333ULL, 0x08F54D76E9DB61A1ULL, 
            0xB5FF549A22A233C5ULL, 0x20991568386DF46BULL, 0x17C44B2CB0EF0F43ULL, 0x874BD41E1627319AULL, 
            0x7432BF8F3347B410ULL, 0x4E3BFB15E4C654F6ULL, 0xA8E6B859FDDB7197ULL, 0x292D7CD565FB588EULL, 
            0xBDFC2BBE86C1B7C9ULL, 0xCD7F5717AA13C110ULL, 0xD9AB9716E566BFC9ULL, 0x9D1E129AD075D668ULL, 
            0x701639794E45F24CULL, 0xC9599068F2DAB124ULL, 0x8940EB5EDCF2DDE7ULL, 0x968A560889B36DAAULL, 
            0x6A0BFCF878D046EBULL, 0x55779E5BD2BA8F71ULL, 0xA7863D25E5FE3907ULL, 0x3F9B1DFCCDA2D416ULL, 
            0x0D266651C38C49A5ULL, 0xC6919994CAC00282ULL, 0x1C938E31B8B048D7ULL, 0xD5B99B223AB1B382ULL, 
            0xDE2474D6640F53E0ULL, 0xEE79E28B6CE33BBBULL, 0x9B3EB09F8668BD30ULL, 0x42F0E8064D0B8789ULL
        },
        {
            0x7A6590E49F7619F9ULL, 0xDF7CD2981BA23A34ULL, 0x70775E6FCD8FA088ULL, 0x6880D0B85A0651D1ULL, 
            0xD2541146BCFFB428ULL, 0x8269A9382D555E63ULL, 0x15611201CB11DC5EULL, 0x474A690977FA55D1ULL, 
            0x648C5C4CFFA73A69ULL, 0x2A6A5605CB8A5C03ULL, 0xF1A1373AA09F4890ULL, 0x5A60A927FC1D776AULL, 
            0x02C0C5D6FBC4442AULL, 0x99F3F4D037C6976CULL, 0xCE792709048DE51DULL, 0x77D275B96973B7E7ULL, 
            0x9B9D85E2B582C0DAULL, 0x46FC7482E680A7EDULL, 0x5D44B3DCD6CE896DULL, 0xC212C21DF7BBDCB4ULL, 
            0xF4DA1C7E2C31C8F9ULL, 0x2C4E12B91D7E0B95ULL, 0x0EE3EC61CCB39BA6ULL, 0xFD17E5792B2B10A7ULL, 
            0x5E0273B230E86EA2ULL, 0x87D3672C02421FE9ULL, 0xC2E8085479A2CFA4ULL, 0x1FF49C1DCD7055FCULL, 
            0x947035CB5AC50D78ULL, 0xCE3D971ADB3BF39AULL, 0xB2D78D8CA556295CULL, 0x4C1AF80E2DFE86B0ULL
        },
        {
            0xC4261150028C6DB5ULL, 0x996F58CED79282A5ULL, 0x059E217B2BF9E284ULL, 0xB6E90534283189A2ULL, 
            0x68515ADC5428E43DULL, 0xCCC0F8ABB758BADAULL, 0x65A015F20E6E25EBULL, 0xF8D558E1BBC46E93ULL, 
            0x6DF8DF5BF9D4937BULL, 0xBAAB9A7684A8C09CULL, 0x732A147AC2A17F58ULL, 0x6E9C14E9B6FAD7B5ULL, 
            0xAAF504B3F96F8F81ULL, 0x4239EFFBED30EA26ULL, 0x9D860890AC01C28FULL, 0x1A1220678DE90B33ULL, 
            0x5D793C1DA0F34F5EULL, 0x25726F67960113F2ULL, 0x3B671309404E8FE8ULL, 0xDA501C02A983A669ULL, 
            0x6FEBE893E14D4B73ULL, 0x1126AF3D28DD2786ULL, 0x2D5016015D8B5E78ULL, 0x96B4E9BA357063C3ULL, 
            0xDA73B9D426199DD5ULL, 0x7C3DAD2FB3639FEDULL, 0xCD401FB24F061091ULL, 0x5A98ED96BFE6A963ULL, 
            0x4D5D3779667A0C24ULL, 0xE1C90135700EFB92ULL, 0x2B6B1B48DE48CFCDULL, 0x9E4B3BF79A274130ULL
        },
        {
            0xECFD71CF0A1C53A8ULL, 0xA58209FBBCF89CE2ULL, 0x90ADF25E905C750CULL, 0x9DC64B5B64CA3AC7ULL, 
            0xC2D1E49EAC328F8CULL, 0x9625AB6B7FE267ABULL, 0xFA87CDAFDC0923D1ULL, 0xFEB6DB5C150AA1E6ULL, 
            0x5D712AFAEA9C0148ULL, 0x929E1C6D8B1FADD1ULL, 0x6C74D6F96E0DBBAEULL, 0x04E27FAADD65D57BULL, 
            0x8A3FB9D9A7394D97ULL, 0x121B79E966EA2372ULL, 0xCBF1FC05052E8CC3ULL, 0x9E589A371A712D8AULL, 
            0xADB951FDC50FDF1FULL, 0xBC6D0A1AF04451F9ULL, 0x2902CF1F92A90D8EULL, 0x2B0D1FFB638C86A2ULL, 
            0x45942C141E5FD6DCULL, 0x301B37EB8BA2A80BULL, 0xD07BFE4E5017D794ULL, 0x9B9F0124B61BC7A2ULL, 
            0xCC6015AECB4FA2EAULL, 0xB9CF63FD1E7ACDB4ULL, 0x63AD1C0802C85491ULL, 0xED09AD216DE7D8B5ULL, 
            0xAFCEF691AA5A76AAULL, 0x6281AFB3D2914554ULL, 0x37A9985173915ED2ULL, 0xC0628A8019530D70ULL
        },
        {
            0x49C9C52AE7228E8EULL, 0x13841C710A7BC484ULL, 0x90C3804E0A8B84A1ULL, 0xF27B9F49D9137A12ULL, 
            0x8FEF3454539A14CCULL, 0xB507A2932A4947ABULL, 0x8DD2D2D75818CFE4ULL, 0x788A26879906E862ULL, 
            0x97C774D8A809B6CDULL, 0x5D1F4CD0D034DD07ULL, 0xCB78EABD7B27490CULL, 0xB4C7533FF01277A5ULL, 
            0x2655AE97C2B34E37ULL, 0x5A9342A5A589F17FULL, 0x713D7DEB54716393ULL, 0x1FD180281A7F54AFULL, 
            0xF2F6972375A10B4CULL, 0x59F3AFB848FCBB78ULL, 0xF9F3F85D08A47520ULL, 0x1360061C07A45B70ULL, 
            0x8C6FC44EEC36F5A7ULL, 0x27898CF155327E12ULL, 0x1B1D02D90DC647B1ULL, 0x769C2D0B926F4714ULL, 
            0x7EFE4E65C73494E5ULL, 0xD2DAD81D95ED012CULL, 0x1E7CDEEB212A98C0ULL, 0x0372FF47405C83DDULL, 
            0x03178347DB180F96ULL, 0xA07BD9A31248E264ULL, 0xB3AC9221D0A97DAEULL, 0xEFEB6C0C8EB2AABAULL
        },
        {
            0x7F48E70236ACBEA1ULL, 0x7B64C8487E2FE431ULL, 0xE5C8D25F4E896A04ULL, 0x1203712B010E41C5ULL, 
            0xB18F95BB199CAEEAULL, 0xF28D87D7744F6A48ULL, 0xE9E834ECFD911343ULL, 0xE45B1FD1DBF66F62ULL, 
            0x00D0BF7D5F35A2B6ULL, 0xBB29925B432ED668ULL, 0xCC4349EAB198727EULL, 0x66BBE2E783D49814ULL, 
            0xEC96F161586E4586ULL, 0xE50E869D91E90380ULL, 0x6697AB1249456087ULL, 0xDBA77990503C1F0FULL, 
            0xB369A510AE2718D3ULL, 0xA0037BA69576D7B8ULL, 0x5183F56957C1CD5AULL, 0x4CB0CEC049D478DBULL, 
            0x4E2C5EFDD89F5A3AULL, 0xED9C009A42F0B655ULL, 0x9D312B39801DA496ULL, 0xA8669260C0C83D70ULL, 
            0x0105EC39FBE2F537ULL, 0xC9CB63E8C1AE90BFULL, 0xDD8D62BFF9F80B3BULL, 0x56A9AD6359640DD1ULL, 
            0x5DC031A4E930BE4FULL, 0x630C21DF2B00A342ULL, 0xE85E926D89A0F473ULL, 0xC6459079BD24E0F2ULL
        }
    },
    {
        {
            0xE37932F4D2998596ULL, 0x55EE0328BDF72228ULL, 0xDDC1675336DC50D0ULL, 0x973801508AF17C68ULL, 
            0x6B836B9382B429FCULL, 0xA19D8BE0CCEF5152ULL, 0x7811E4E6C8D342B5ULL, 0xF20A97167F79F15FULL, 
            0x7289DFDA7C8455FBULL, 0x330237CDD08B54DFULL, 0xF67DE1B73F6E5F22ULL, 0x976DB7DCCE0C2F4AULL, 
            0xE71ABA01B2CE45BDULL, 0x6BD1A2B09FEC7F6DULL, 0xAF33E38118C2A762ULL, 0xA6BEBA1A0CE93F87ULL, 
            0x49AF34AB1BE20621ULL, 0x997D480C5F41B8A7ULL, 0xEC63C0D68AE9AF60ULL, 0xBF516B54EC7C9A70ULL, 
            0x8C0B1B47EF743989ULL, 0x9EB1F13C32AFB22EULL, 0x5C997275BA482712ULL, 0xB1D44354BBD98369ULL, 
            0x756CB304AA0282F6ULL, 0x3C9C06F6459E2017ULL, 0x55AAB37FBC06CED2ULL, 0xE19571B5B7DE0D5FULL, 
            0x227D81AD67B5D531ULL, 0x1FE6F6281F4EF525ULL, 0xA91649115990D274ULL, 0x6F07CF0B7E6495EAULL
        },
        {
            0x5DCC85784B26E318ULL, 0xEDF0A65690D800A7ULL, 0x562DEF85D86A057FULL, 0xB5EE3C95E9E09500ULL, 
            0x6CF95963E63B355EULL, 0xAB48EE804AE894D5ULL, 0xA17C5A2EAAEFD53FULL, 0xF16F83A1B37FC0F6ULL, 
            0x502A6A784DA2E41EULL, 0x1D548FF742CDE190ULL, 0xEF92A2EC2DE2DA56ULL, 0x49BBA4EA72F7B0F5ULL, 
            0xC186A867B914FE71ULL, 0xBA0F06994C969750ULL, 0x4513FF54D81CB78DULL, 0xD1D9412509BD7BF8ULL, 
            0x2441D9B02C66CEE3ULL, 0x372133EE973A0C9BULL, 0xC2ECD2F31DF1DDB0ULL, 0x776751BA8E61EEC2ULL, 
            0x971F16EAE300995DULL, 0x98AC4543BF815666ULL, 0x2EC78463C5F06798ULL, 0xA863CE8749E1C5BEULL, 
            0xCB02CF1B037C5877ULL, 0x3F58DA3074FF5534ULL, 0x9058F17D86DCAC88ULL, 0x21F37EC5CCB76EC4ULL, 
            0xE4A4E9484D5FCC7DULL, 0x21F96A2EAC58903BULL, 0x97177A95E56E5392ULL, 0x2B59D0EFAAC07BABULL
        },
        {
            0xD6241BA137352FE8ULL, 0xA8708C215272841CULL, 0xACD35E1279C5AD0CULL, 0x929AF21A99DD815BULL, 
            0xE6F5FD09A5990F80ULL, 0xF38A77C44E46C96AULL, 0xA6742AE8C4903F3FULL, 0xAB7A61DAFDE9E8E3ULL, 
            0x0AA8D9CFFFCB6D55ULL, 0xF1E8F105ACD534CFULL, 0x20A508F41435CD14ULL, 0x4C119CA5C5C47D57ULL, 
            0x12AD9B3E519EE736ULL, 0xCA648D366AF0D8F8ULL, 0x00069F81B685FC0CULL, 0x0BB4A7D7FDF5B686ULL, 
            0xF5868126CEB3EDC1ULL, 0x71B3E15EDF74B61CULL, 0xEC9195F1B9A7D848ULL, 0x001C709E92018277ULL, 
            0x716E6DB7FAC711B8ULL, 0xD4D0DDE7671E063AULL, 0xAB2FE0DE890A7BCAULL, 0x8B11BF1DBA4C1E71ULL, 
            0x32B50062A5C98E51ULL, 0x0CE326F4685392ADULL, 0xF127C9E96181FD4CULL, 0x74CCB702A42FDF5DULL, 
            0x6A37FB5A50A50F60ULL, 0x62397A260E2816D2ULL, 0x97753AA1EB30819DULL, 0x49CFE0E6738AE9A1ULL
        },
        {
            0xBEDDEC3C40B44AA5ULL, 0x45C2BFDCAF794EABULL, 0x96E8423FC2C7C9C0ULL, 0xFADCEE64EE92C439ULL, 
            0xF619079AACA04181ULL, 0xB06680B15F53055DULL, 0x07A6F6D41D275F83ULL, 0x6844B6032529945AULL, 
            0x5FE520A202ADC111ULL, 0x161AA883E9B88F48ULL, 0xD150E6E671B0594BULL, 0x49948F4818CBAA80ULL, 
            0x781C879C267FF9FEULL, 0xE6533130F0E321A4ULL, 0x737ACE48990C8E79ULL, 0x64F353569D328971ULL, 
            0xDF3D052736401072ULL, 0x8BD029D41E2310B7ULL, 0x18D47A391B19F533ULL, 0x290CD25E6F2ACC38ULL, 
            0xCBB09B4601D8FAF1ULL, 0x0CB50556797032E2ULL, 0x617A8E538A9A44B4ULL, 0x45A9999241908E85ULL, 
            0x59F94C48C77D64A2ULL, 0xD93C1CE8C31DB750ULL, 0xAD2CE02481E8A1D1ULL, 0x42187E801B65E778ULL, 
            0x919D951C5E742BE0ULL, 0x9EC618F9624D9756ULL, 0xDC90743C062D2185ULL, 0xB4100F0F8A0502BCULL
        },
        {
            0x573912361BB985E3ULL, 0x2A9ECDB2A851EC77ULL, 0x223B4722F0CC918FULL, 0x842EB1A5F8CBEE58ULL, 
            0x791232BB0BF50167ULL, 0xAEE44AEE1D19C371ULL, 0x879FC71CE8369A0EULL, 0xEA18AD9798E956DBULL, 
            0xFE9A9869FA2B81BAULL, 0x53D2A2D87851327EULL, 0x2D7133578FA304E1ULL, 0xDD0BB10A1D59558BULL, 
            0xB71DAD1A76F7F70CULL, 0x152BAEB62CF16997ULL, 0x217D20690BC59C1AULL, 0xECFD4F3ADDC4A8D6ULL, 
            0x1F9A9C705E969A04ULL, 0x014A8F28623C3482ULL, 0x6CD448769B973821ULL, 0x76844B125254F34DULL, 
            0x844F610A5AB52E25ULL, 0x76B5626098C1D378ULL, 0x4D8EAB6CEE6ADA1FULL, 0xCF338F8CEB2ACD37ULL, 
            0x6100CCC0C2B6CD94ULL, 0x03156F09A2D61098ULL, 0x2E96071864650D50ULL, 0xE85D7C512176CC13ULL, 
            0xDE6F635E8D291FFBULL, 0x1F45805F932A106EULL, 0xDE5E808C75127EFCULL, 0xCFC97363EC3B3175ULL
        },
        {
            0x9722EB0EDD7F5C40ULL, 0x478D3423FB7AE91AULL, 0x421C7C4A930643B2ULL, 0x33335EDA07896CC5ULL, 
            0x85FD92A5618614F3ULL, 0x3A8A21B6A1E3A687ULL, 0x647965CD036385BCULL, 0xC853EFE04982A951ULL, 
            0x86B38C4FBCBFACB9ULL, 0x75298C0D689F27E3ULL, 0x43D3F63AC0BCC5E9ULL, 0x0987D5AB85517850ULL, 
            0x56737B514A4CDB70ULL, 0x158F09B2D3C97743ULL, 0x3599ECED4806CC8CULL, 0xBD3A5BFD919F73E7ULL, 
            0x18562D8F1D059234ULL, 0xA40A9A5D0DB31634ULL, 0xC1B8D58359A89286ULL, 0xBE20D54175C2ED23ULL, 
            0x3D6B033138D043FBULL, 0xADEACB662111D5A4ULL, 0x925B491212554A14ULL, 0x2BEDA359167EB35FULL, 
            0xB147E438D1C372A3ULL, 0x5D4EAD0E8B97443CULL, 0xE2E03E85059E719CULL, 0x2E9288ABC6CCC009ULL, 
            0xEFA46C956E3A17BAULL, 0x4B494A562623C141ULL, 0x0F6F2F16815D8F6AULL, 0x354D023BC0493B32ULL
        }
    },
    {
        {
            0x131286C1C5F50DDEULL, 0xE1FED68FE32EA03EULL, 0xAA7DE14B41AD6509ULL, 0x9A70145EB07CCE0AULL, 
            0x01013FD36C3F26EDULL, 0x62CFDB72E430F292ULL, 0xA3D8C5DD075CF024ULL, 0x8D34A2C95CCE29B2ULL, 
            0x3CFF7A3A1B81E4CCULL, 0x287DCAFF78D9E37AULL, 0x4498EB73407250A1ULL, 0x01426906D5A2CB53ULL, 
            0xFA414852E33AA2D3ULL, 0x463E1B95D433B684ULL, 0xC76F1BC00A1F50CAULL, 0x25B5D91E85D9AAA5ULL, 
            0xA949DADDC46EFFE1ULL, 0x5CA34C3B1E4ECEDCULL, 0x3C12AAEFB5D20598ULL, 0xA677F689A8EB3871ULL, 
            0x11FBD8ABDDE39B18ULL, 0x6A94C7579E855489ULL, 0x464B111DFD16B666ULL, 0x1BB08D8EABFB996AULL, 
            0x4512F2791D720A1AULL, 0x8374B9835BC113F8ULL, 0xE19AC4F792DBC2D0ULL, 0x09B73D8246A65C66ULL, 
            0xD25852B14E7EA167ULL, 0xE6AC85C713AAA5B1ULL, 0x5024F8ECC4F7B61DULL, 0xDB4A6C1BC8EC9ABCULL
        },
        {
            0x0FD5DF251AF10B1AULL, 0xBD4AD9CA0F24F810ULL, 0xE2EC433F15AF99A1ULL, 0xD490A19E009C523CULL, 
            0x0A8BA03B2057D53AULL, 0x130E15DE991D9D53ULL, 0x7EB05AFCAB17E5CFULL, 0xB8E82532BBC49646ULL, 
            0xAD9305B60C785EFFULL, 0x2A5E8D348AECC977ULL, 0xB4193C3FECA03EC8ULL, 0xDCD3BCF43A123DAAULL, 
            0xCCBA852DFE41E077ULL, 0x19AD994F28B33EE4ULL, 0x8C5E08E660CD2C11ULL, 0x9122235B50BCF883ULL, 
            0xCF0254E4B6459320ULL, 0xD0F56A49B6620773ULL, 0xD12E137B2F2D8E0DULL, 0xE9428873A7BC59A4ULL, 
            0x43C262C8D5716415ULL, 0xEE1CBDF36F1C7715ULL, 0x6793ECD6AC558D21ULL, 0xEF04F97281D0320CULL, 
            0xF08CCAFABCF677A8ULL, 0x122C50707CD7C448ULL, 0x00BCF8D23FFF2BEFULL, 0x1E05C434E485FC6EULL, 
            0xDAED963BFF40CEDEULL, 0xA78C9F90FA2235D8ULL, 0x2CE195AEDEBF94CDULL, 0x89487BA544C05EF0ULL
        },
        {
            0x944AAD7445D3AFE1ULL, 0xF8B203756B999FADULL, 0x588BB81D693640F0ULL, 0x306BC33151C52498ULL, 
            0xCCB7BE90AB825F32ULL, 0x33A0C37AF25E0DDAULL, 0xC4BD998FED1FF719ULL, 0xADCFA18FDE8E21D7ULL, 
            0x449D1703470F21C4ULL, 0xBF4C24C44C14CC67ULL, 0x107286B6B0F0D8DAULL, 0x13E817CB47FB83B3ULL, 
            0x15E56047B7B454F9ULL, 0xC68878CF2F5772BBULL, 0xB8B9B975799EDA3AULL, 0x85383CD8F836B656ULL, 
            0x680D320B79232270ULL, 0x8ACCE2D11F9F3C2DULL, 0xFA93B7884E42D4E5ULL, 0x2BC29DB3B07ED513ULL, 
            0x88DF086A37180AD6ULL, 0xC1CCD361251B6F4EULL, 0x3EE6E76792FCAB02ULL, 0x688D8AA62A7553AFULL, 
            0x3A995DBF22FEFDC3ULL, 0xA953FF97BAC427BCULL, 0x3B5C76FFB0F2B4ADULL, 0x2CC2B316055162E1ULL, 
            0xDC5159CD271E01C4ULL, 0x78C27B7E6C3ED31CULL, 0xA6088F089F01114EULL, 0x8FF9309531787D9BULL
        },
        {
            0x8C578EC2E1D82107ULL, 0x4613CD78E89771C9ULL, 0xCFD08F5DE2BEA747ULL, 0x01B02EF45E725C76ULL, 
            0x4B31A97701C6C154ULL, 0xD1F4D607A3F39750ULL, 0x0671999C558463B9ULL, 0x1CD7A5E63116F993ULL, 
            0x5658A0DCF59ED3A3ULL, 0xAD01044BD816B125ULL, 0xD73245DA53F5E46CULL, 0xDDD44E59A7E4BFBBULL, 
            0x9BA50055EEF881AFULL, 0xE38B525250412539ULL, 0x5ABF76432B61DB1EULL, 0xC6E0066C8322D468ULL, 
            0xD62590075BDD8858ULL, 0x2A3BF3FF601F07E7ULL, 0xBA0F155005339996ULL, 0xAA1D22CB09AE1D61ULL, 
            0x37F3C7A12CBD2B0CULL, 0x4FAE464275D3DD2BULL, 0x183BAA94FEC751ADULL, 0xD431C8FF32F388FCULL, 
            0xE8C5F24A7E9520D8ULL, 0xD27B34EBC0EA15DBULL, 0xA6BD33A23320D22FULL, 0x06E2158257386B21ULL, 
            0x84DB60441E206F30ULL, 0x1B81179EA8FDFB97ULL, 0x81380D6A260150A9ULL, 0x1B2DA0CE86AF84FDULL
        },
        {
            0x7A92ACD96A0D1FB8ULL, 0x147E6DC6F7125E00ULL, 0xAEC679E93864E85BULL, 0x8515F8A9AD32D848ULL, 
            0x8721C134551991ECULL, 0xDA2D2A518E8C46FEULL, 0x5565E53243E00144ULL, 0x758FA221406AE69AULL, 
            0xDBDE19C3AB6C5910ULL, 0x1EEF6749C7FEC187ULL, 0xAB92D841ED0DF930ULL, 0x84FB599D7750D82BULL, 
            0xFAC28AC4E59D7683ULL, 0xE00F0C431F82C223ULL, 0x6BF630DD0D090637ULL, 0x9254D7557388BFF4ULL, 
            0xE0ABBB28AAB1EFACULL, 0x22722CB0AB7D2B74ULL, 0x0E4D5EAD3DA01E47ULL, 0x1BF13078BCFD980BULL, 
            0x04C68BFC48A69003ULL, 0xA935788CB7EF67DDULL, 0x721FF709635143B2ULL, 0x85F3B602890665C4ULL, 
            0x330888B61FB167F7ULL, 0x8F74C13CED4FE0BFULL, 0xB24B90529A629C78ULL, 0xBD79FE7E41417148ULL, 
            0xB3DE6A923C231968ULL, 0xD352D1011FEA454AULL, 0x537F68BC8079B1B3ULL, 0xA4DBAC0437BDBC23ULL
        },
        {
            0x1E9E6A856332B371ULL, 0x04C5824F41941171ULL, 0x7EFFDBCB91C16231ULL, 0xD21A12F1BE812245ULL, 
            0xBD91B8C6A82547C3ULL, 0x7B31AF1264E2C05FULL, 0xE61BA1702731B5DEULL, 0x7B1301ABD1F6E3B0ULL, 
            0xD34DEEA2F365D4D7ULL, 0x38B048837C61EB16ULL, 0x1681014DF102D6CCULL, 0xD6A3C56F03DC9DC1ULL, 
            0xAC0D132744B0E734ULL, 0x2396852F76131732ULL, 0xC0C402F5655E23FAULL, 0x9C28FAA031EE3C4DULL, 
            0x7547B8A5017D0DEDULL, 0x284F1189C9E59209ULL, 0x55E235D5E9FE9350ULL, 0x86948114843E51B0ULL, 
            0x4EB9345EA29E0B86ULL, 0xBBE7E969E7BF6EE7ULL, 0x646BFB3290562C54ULL, 0xE8A860DE27A13426ULL, 
            0xC139ED6835C474D5ULL, 0x04AEAFF0ED59BFA2ULL, 0xCA466B14967A8F18ULL, 0xB0EBB939BA00C780ULL, 
            0x3AD072CAF45155ABULL, 0x2D591EA9B9599382ULL, 0xC1B6B8E8004793F2ULL, 0x2516EA97242FEAF6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseGConstants = {
    0x7274EA5D0656353CULL,
    0xB47FE76CDC0528C2ULL,
    0x2CE94AACB70EAD74ULL,
    0x7274EA5D0656353CULL,
    0xB47FE76CDC0528C2ULL,
    0x2CE94AACB70EAD74ULL,
    0x9F6024172676A698ULL,
    0xCA2650A67C3AFD05ULL,
    0xB3,
    0x1F,
    0xCE,
    0xA8,
    0x4D,
    0xE3,
    0xA2,
    0x70
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseHSalts = {
    {
        {
            0x47A496139D2288E6ULL, 0x6CA59B9FAF74C37AULL, 0x9DC93755E956FB00ULL, 0x0665D941322452CEULL, 
            0xAB4730A1B709F453ULL, 0x64AF94BF64AD4AEEULL, 0x8DAF3E772A4B961EULL, 0x43893EADB609748FULL, 
            0x3C0F2025BF55DCB3ULL, 0x93E19A52BF1ACC47ULL, 0x6A266985ADDB4536ULL, 0x5BFCFBE31F39A9B5ULL, 
            0x4CA72AC8F0472B72ULL, 0x631D9355FDD0FBEEULL, 0x8FCE57660CE31B35ULL, 0xCC674791B9FF259BULL, 
            0xD0D50D8C38DEB32DULL, 0x7D1BDC3502188F19ULL, 0xD8D33C7CEBF16E62ULL, 0xE54284E0FB846CE8ULL, 
            0x2CBD6E2A51B99E59ULL, 0x6DCBE3D71EFCF486ULL, 0xE025B57C95F96838ULL, 0x17A0F96BF11ED385ULL, 
            0x811BA700C48F843FULL, 0x3BCFD33A831BD83BULL, 0x1E6DBFF4645BA3C2ULL, 0x90305492346A389AULL, 
            0x11FCADF7F004EC60ULL, 0x380654299A1804EFULL, 0xD3048B48EAE7435FULL, 0x90EA30A946F12E5FULL
        },
        {
            0x46D702E514847690ULL, 0xF6E15BDFE2F80936ULL, 0x8743C97852A2CA63ULL, 0xA240CB229EC21D2BULL, 
            0xCB1611233C1B5A54ULL, 0xD3945D53F8E8BA54ULL, 0x7105406A9E14296EULL, 0x6148C8EBBE154035ULL, 
            0xF32C9FC6FAC4E284ULL, 0x533D90B723DD2E04ULL, 0xD808FA4ED9A8B862ULL, 0x8421DAE3FAD2385EULL, 
            0x694B6B7FBD5E786FULL, 0x23244E5DA3546F1BULL, 0x3937D2ACCA40DD46ULL, 0x3AF741E8B21F1CCCULL, 
            0x0CF009B45D104507ULL, 0x23F9B654E8EF5C3EULL, 0x7CD58A5F79655BDEULL, 0x15E5E584BDE02B74ULL, 
            0x5B4055B51A1720F2ULL, 0x142330CED44E3EABULL, 0xD7C6030A76CAAB41ULL, 0xEB216133627D580FULL, 
            0xBA59A12D7017385DULL, 0x296A5B81DC863E1BULL, 0x74CA455B3110D33CULL, 0x874F8E3C0D552B93ULL, 
            0x64A935DF9F1D75E2ULL, 0x99BA2929CBC6F7F3ULL, 0xFF583A914905BDA3ULL, 0x21931986FEA6D6E9ULL
        },
        {
            0x5EB25AF02EF3EFDFULL, 0x6C59AE3F793AAB15ULL, 0xB0FACC448B8D37CFULL, 0x1B79BD2C9FBDFC29ULL, 
            0x571C5E72727EF892ULL, 0xC20B8ECC445DC9F4ULL, 0x211BED4EA163E0DFULL, 0x89C31A45E70FDE56ULL, 
            0x3771FCA1BEBC4F24ULL, 0x4CFD7557AF3E5DAAULL, 0x5DDBFC28CCA30106ULL, 0x0C43E6E0E8C3086BULL, 
            0x939375B505DA4CA0ULL, 0x72EB2AEB7F28C26BULL, 0x1083570AE74F1FA2ULL, 0xA19815A4F954E6B1ULL, 
            0xFE79815BCE057A5AULL, 0x7AB0186B6710A977ULL, 0xFB0E432C203543A6ULL, 0x306AB71167F95D55ULL, 
            0x1B2A6EB5D226F55AULL, 0x8E651B15194D6288ULL, 0x024136CFE3C46BE7ULL, 0x6300FB92838A8FD7ULL, 
            0x8F672C9BC149B623ULL, 0x16C199F7F27C27FFULL, 0x155DF36C837D3205ULL, 0xB88F91FFE503386AULL, 
            0x805028F5BC13D780ULL, 0x22E5077D0AB060D2ULL, 0x335A1716CF4394B9ULL, 0x0410328C5183BF33ULL
        },
        {
            0x8F9C58E4AF265D6AULL, 0x04ED3D7362815297ULL, 0x939E6C04DAB51CABULL, 0x22DD3F08BEECE6B6ULL, 
            0xF738BEFAC094F2E2ULL, 0xCE3BD4B6B760607EULL, 0xFD8520C95B57FAAFULL, 0x4B908D5B50726774ULL, 
            0xA943F51007ADFF1DULL, 0x7524FCC1E05FA3A2ULL, 0xDC07FC6D0B6867B7ULL, 0x3E8684C5BC5D5CFFULL, 
            0x91CBE7264D62B810ULL, 0xA35F0C8CE4BC3F57ULL, 0x7BFD52122CF98B3FULL, 0x56BFDF9EA812BAD0ULL, 
            0xE76A08D6EDFADB16ULL, 0x87A11DE87383E760ULL, 0x24D99E139A66F5F8ULL, 0xAA7FCC63553F1861ULL, 
            0x5187F3ED9EEBE0C8ULL, 0x6441A524F6D7BF96ULL, 0x9CE5EC73D4EF1912ULL, 0x7F1AF21F1FF0FC59ULL, 
            0x9ACFDE1987D7A107ULL, 0x00019925857BC8D0ULL, 0x64FBB7552B796E40ULL, 0x995B17AA8A2C736DULL, 
            0x3E5F1DE644E6763CULL, 0x57F315262FAEC604ULL, 0x4B1FAD3490DC6655ULL, 0x1255B1A5682AFD4CULL
        },
        {
            0xD1D7212FDE9B0D76ULL, 0x04E1AFF4922A3D6DULL, 0xD97604EEFF7FE1D0ULL, 0x10944BAF64BDA7E6ULL, 
            0x570D255ED3C2599DULL, 0xABC54C373D6506A0ULL, 0xB4C93FF833C92BE9ULL, 0x99C26D0494B309FAULL, 
            0x6B9C8F5A18E8271EULL, 0x01280271DEBAD9B4ULL, 0x259A80229633C79AULL, 0x3CFE8E2860C903A4ULL, 
            0x049B0A4A0D35CB90ULL, 0x07352C65EAEEB907ULL, 0x820E036B85209247ULL, 0xD5C21A568A13C267ULL, 
            0xA061E421B6802DA7ULL, 0x97D4C00FFC845CB7ULL, 0x2E64A16FE4FF502EULL, 0x36EBBAB2B49F1BA0ULL, 
            0xFB4633FB04219BE6ULL, 0x61BC6C39C9C2EDE3ULL, 0x3F96FE7165D377A1ULL, 0xDE0A8DDF373B918DULL, 
            0x72519B65F0A7A397ULL, 0x2E00BB5C61D54C0AULL, 0x3F1879378167B9D1ULL, 0x897A49E6B4191772ULL, 
            0xC34B18CA56A1347CULL, 0x9E9FF30DB7CFE132ULL, 0xEBB6C44795A54141ULL, 0x39D45260C4149687ULL
        },
        {
            0x487F4326CA10B617ULL, 0xE5C82FF0DE298836ULL, 0x4A247FA2405B94B8ULL, 0x13A09C1D313B2710ULL, 
            0xEC53A8F321978AEBULL, 0x4DF3C52646A497EBULL, 0x5ED29C1236D21D4CULL, 0x4D32B84A32070385ULL, 
            0xCFA2BD5E17BA903AULL, 0x32185407BFEF188AULL, 0x8EDE9DC5FDB1381DULL, 0x663C484A434427E8ULL, 
            0x810FCCE07B5456A9ULL, 0x2E08D0D8EABDF310ULL, 0x5A98D996A700099EULL, 0x08F16ED24C747E3FULL, 
            0xC70EC69B1906C699ULL, 0x6730DA8F423FDAD1ULL, 0x1CD15093274CD6BAULL, 0x7F3735F47D065592ULL, 
            0x1FBAF29EE35576D8ULL, 0xA22E99E1E3C06F20ULL, 0x7973CCA574F40D13ULL, 0x6F38A56583585EEEULL, 
            0x491375CF97A8BFACULL, 0x7F0BEA6F407DCE2BULL, 0x9F5FC655CDA78BD1ULL, 0x16A0229FE623A500ULL, 
            0x7828DD83E1DD94CFULL, 0x0AD7012328A62EEFULL, 0x281D98955726B0C3ULL, 0x4CE839183DCA20F6ULL
        }
    },
    {
        {
            0x6DAD9C0B21E79F86ULL, 0xE95732B030F2E5E0ULL, 0xCCA3F3667A77E3E2ULL, 0xC6F0DFB5EAF3ED16ULL, 
            0x1E74B9A4620C9433ULL, 0x6DE28A7532D09484ULL, 0x0B04CD16601E0B1FULL, 0xBA624E477E352E47ULL, 
            0x425A60AAC82E368EULL, 0xDD01133C5604FE11ULL, 0x0720402250A39B6FULL, 0xB2D22A2F415C2811ULL, 
            0xDEBF0A2377116E5FULL, 0x911CD5691B356071ULL, 0x811BDF188E878705ULL, 0x412BFE0A8E5BEDDFULL, 
            0x4D2E40A16BC719BAULL, 0x1A5BEC1E6AEBFCFDULL, 0x92D8F091100B0CC6ULL, 0xB6D9821637855E8AULL, 
            0xAD92A702759F663AULL, 0x7D172F0A363A837AULL, 0x1439FABC6FAE31B3ULL, 0xD198EDC79BED1328ULL, 
            0x4166491E7CE7BB50ULL, 0x46A2FB0093FC3A96ULL, 0xF6F42119DD6F8A50ULL, 0x230386C154B2E64FULL, 
            0x0D76F9FA530AA425ULL, 0xDD6E45061C5A6C1CULL, 0xA641635DFEB37C79ULL, 0xCBE5A6BA7416CC39ULL
        },
        {
            0x36B1A50DFE5CE980ULL, 0x8567F51887BF8E90ULL, 0x5E5D16CF868765C9ULL, 0xABA47201FA4ED9C3ULL, 
            0x5BD4667906C15B30ULL, 0xDEF9F88BE6A1E92BULL, 0xEECED39215D1DA56ULL, 0xB46AE830D3BE589FULL, 
            0x50F5FB5D0DC0DEA8ULL, 0x141704F898E3402EULL, 0x5EABDF906DE674CEULL, 0x5A2642BD40E65350ULL, 
            0xCB7B6FC4911F7848ULL, 0x97F82A2EDDE0B547ULL, 0x5F9170BFCEC73880ULL, 0x65C0E3BD9351549AULL, 
            0xD17A27FC84BD06D4ULL, 0x35AA21B38FB693D1ULL, 0xD3C45F54826178FBULL, 0xC98FA5A73DDCBB84ULL, 
            0x1E234A86E8FA8B5DULL, 0x830377E9F3B181B3ULL, 0x91209B2F1F671EC5ULL, 0xEF7939CC4C83E0BDULL, 
            0x48C69B45FF31E096ULL, 0xA5CFE76F9A8009C0ULL, 0xCC008AE00FF46F3FULL, 0x774D197305B89C99ULL, 
            0xEA4B39797A47EDADULL, 0x0D30CFE0798F422AULL, 0x29FE831358542BE8ULL, 0xBCA4B10D22CE6258ULL
        },
        {
            0xBF49BDE37B73FE12ULL, 0x58DD871AA83F7EF3ULL, 0x6E130652DC6BBC3DULL, 0x5084F41B2BE97A1EULL, 
            0x09D0E41266A5E8D5ULL, 0x52930FF1576B8C4BULL, 0x90CEE96178B99098ULL, 0x2F66A0ECB45785F0ULL, 
            0xE48877E35350FBCCULL, 0x123F9617F5E85CAAULL, 0xDB298DD8DC011DB3ULL, 0x3F578E3CC485E148ULL, 
            0x50C5BEA5B24B2800ULL, 0x9865F444532ACF11ULL, 0xECEDBB986E8238A6ULL, 0x1C285BDEED8264CEULL, 
            0x27F1A5AD85C2CC82ULL, 0xE7A5A2CB929FB782ULL, 0xC95F04382F44A5FCULL, 0x1414EBBF4B4F4E64ULL, 
            0x999B1492E9ED11BDULL, 0xF4353CCCF5214C77ULL, 0x1720D0B6DC4490DEULL, 0xE454CCCBC7C23363ULL, 
            0x8E0CFB000521F512ULL, 0x565410BBBB6E0252ULL, 0x04639FBDBD073827ULL, 0x196886DC2F72A3FEULL, 
            0x2E1462EC84DC2563ULL, 0xCB156349D86F7162ULL, 0xB82851008CB7731DULL, 0x0DAFDD0321687373ULL
        },
        {
            0x26093941F4A71B45ULL, 0x414F720B9758A297ULL, 0xA577A5EBABEBDFD8ULL, 0x9FA1CCFC08065656ULL, 
            0x89B6F7693E98B6EEULL, 0x85D4811BA69F1DE7ULL, 0xEE990A3804B3A3F9ULL, 0xBECF228C4E475F40ULL, 
            0xECBD0B8E128E3F46ULL, 0x039DA4724B4AF51AULL, 0x0B0EAD39BDCF8085ULL, 0x2FF7ADB67A477C3CULL, 
            0xE4CC0FA84D51DFC3ULL, 0x7E4FD64983D184AAULL, 0xB6FCCE6CA5F88470ULL, 0x418023DF7E5524A4ULL, 
            0x9A79C42F34C959A9ULL, 0x93407F918257F77BULL, 0x17070E4327ECD882ULL, 0x4B859FD983BA1A17ULL, 
            0xD30D2B4D03B6D15BULL, 0xE3A690F8E408CD4AULL, 0x1F459A639834C4E3ULL, 0x889A953ED6970A5AULL, 
            0x59E02138DC17D2FFULL, 0xAEC7233515AD1724ULL, 0x04F56675475F364EULL, 0x4A94C26828B3A7E7ULL, 
            0x780123E390DBBC79ULL, 0x796FAC17B1275BE9ULL, 0x21FD029BD4A59E04ULL, 0xE0D792D1A79F12C8ULL
        },
        {
            0x950CAC001C174FA4ULL, 0x02F0B935E466FA0FULL, 0x2AB88A156FC41C93ULL, 0x57A3C50890F943A1ULL, 
            0xB4DB0EDA425C2E12ULL, 0x6E37B4A8A6A70192ULL, 0x94DAF01928469950ULL, 0xA58F4C8187F9F59AULL, 
            0xDE1E101A4BB20E68ULL, 0xE4303EFBD541C191ULL, 0x16420F10FBD2CA0DULL, 0x9A5DD585CB26532CULL, 
            0x442DC74FEA5CEA2AULL, 0x33DC64BF98106571ULL, 0x44D5621B1F52E3BDULL, 0x15E8C0E8CDF675C3ULL, 
            0x6B543E957A59E1DFULL, 0xD7592EFB52DA3E20ULL, 0xEA02F596118A9793ULL, 0x42C58CF447F9067CULL, 
            0x484992D521CF3D9AULL, 0xA1AF252A9CC326ADULL, 0xF47017D25422C96CULL, 0xA9422EEA10EA9255ULL, 
            0x1FFC6E6B48FA38EDULL, 0xF9600F45846D71CDULL, 0xB08F271ED38C82AAULL, 0x60580B28C12E718CULL, 
            0x762D361E0E91DBA0ULL, 0x768B6A0FE9FF5569ULL, 0xD6776D8BC22771A4ULL, 0x6B911494BAE8C330ULL
        },
        {
            0x6E65C6CEBD595042ULL, 0xF7B8B00E693CB645ULL, 0xE692A8E64F57E763ULL, 0xA1F0E5B955746454ULL, 
            0x42E55CE68BE24A06ULL, 0xB0F873346471ED96ULL, 0x23AD0D4F188A48B8ULL, 0xBEEFF9B292AC02E0ULL, 
            0x06D72B58E96882EDULL, 0xEF276AFF7233ABDFULL, 0xD1873C3537527008ULL, 0x792BD504425227DEULL, 
            0x956EB06F754B5C6FULL, 0xE95AF37820482216ULL, 0xFADFDA055BDD8BA2ULL, 0x5AE3D8F3ED79A8D4ULL, 
            0xF0CDA8943E70BEBBULL, 0x67DB9B73C38006B4ULL, 0x5F6052DD6F5B5EBFULL, 0xB6F9590D310248CEULL, 
            0x9F02272670D30605ULL, 0x89AAC7022E54BB49ULL, 0xCA97BCC6F2F82B83ULL, 0x893466F902CCA53CULL, 
            0x37D83D61DA4DF813ULL, 0xCCF9DA43AC467323ULL, 0xEB22BCC0A2CB344BULL, 0x76F04F2200E58E09ULL, 
            0x542C04DCEA56A805ULL, 0xC386C79FDD92797FULL, 0xDED2DE19795D5AECULL, 0x788DF838D0D7F4C9ULL
        }
    },
    {
        {
            0xDDF8A86765ADB0BAULL, 0x070DA4694F7E9EB2ULL, 0x371327E995ED5E71ULL, 0xEE9B53FBB835A39BULL, 
            0x35C7F1AA4C9BD34BULL, 0xD7E412DB356BEDCBULL, 0xDB8A8C0FA5977398ULL, 0x2C1995A5B451E717ULL, 
            0xE7F92A06F75C49E6ULL, 0xFD251E9E1D68BC52ULL, 0x842A7581DFC29743ULL, 0xE3C45D52D9BE8D1DULL, 
            0xAA4E12487BCB3F87ULL, 0xD2663B4586FA9D2EULL, 0xECA798C572E95C66ULL, 0xBD1EF25FD64E242CULL, 
            0xCBC51F8C558814D9ULL, 0x791F8B1D534ADC35ULL, 0xCBF3F7C02977ECCAULL, 0x856EA64F42D139D1ULL, 
            0x0536AE0105E4154BULL, 0x2FA93B8B63565D39ULL, 0xE2538DABB75A2B34ULL, 0x0182E28E81441F29ULL, 
            0x55EDE5E39A1FA9F5ULL, 0x39A0960518C4915BULL, 0x7C800FE10FBD8E77ULL, 0xF6E632132FB8D1BEULL, 
            0xED52D6771E78B506ULL, 0xE959AA0DCE57AD35ULL, 0x733E19F8978F32B3ULL, 0x5BE749B08A7CC256ULL
        },
        {
            0x2DD902119B6B0871ULL, 0x08CE73A6008130CEULL, 0x529950293A792625ULL, 0x40DE62ED13436302ULL, 
            0x9FE244424E5BAD0CULL, 0xAF85CFF17B2C99DEULL, 0x6218D23F43CE641AULL, 0xB82C6D948EDB75F6ULL, 
            0xC08DBE0E9B06976DULL, 0xD0EE02CA8F3F0046ULL, 0x42207B4261F8E4D1ULL, 0xB000AC6417DB9A8FULL, 
            0x5E6AEAA286B41647ULL, 0x6989BCA28E169CDDULL, 0xCA5ABB3B043124C0ULL, 0x2F692C5B7238B098ULL, 
            0xD46FFC244F0100C9ULL, 0x0DF19A32B9EF449FULL, 0x6EE3CB857679C0B2ULL, 0x3E4901B885242DB0ULL, 
            0x145872EF5369F3F0ULL, 0xB00791A24BE192F2ULL, 0x81B285C16BB6BD37ULL, 0x82324677A502C6A1ULL, 
            0x50F9382552BC2ED8ULL, 0xF70CA1C8F0A7DE38ULL, 0x6AB4CA69CBD624B4ULL, 0xDCD162D06AEF9EC6ULL, 
            0x26E27F2B9DDE2D10ULL, 0x06A4DB5C6A727A37ULL, 0x3D86F03D86CCFA12ULL, 0x50D2244DDEC5C3D2ULL
        },
        {
            0x079002BB9AF5E88EULL, 0xA2039EEF92DF52FFULL, 0xC521A389FE4A2288ULL, 0x8CA65984079F30F3ULL, 
            0xC83965C4BCBD0043ULL, 0xD546F05DF0D8B612ULL, 0xD608242E498FA162ULL, 0x3A7FA771725830E6ULL, 
            0x021F7F368BC41217ULL, 0xF71417D4F0AF563BULL, 0x5B47C8350B2C2654ULL, 0x1B13D153DCBCF9EEULL, 
            0x5FB71EF384854079ULL, 0xBACDE73F0C9AF231ULL, 0x2BC2BD40C604EA9AULL, 0x4AD040834D0C013DULL, 
            0x2711833A06E1CB75ULL, 0x70E2AAF52325F067ULL, 0x787F43014A73E212ULL, 0x8C261846EA5EE86CULL, 
            0xCC1B777A2725663BULL, 0x84BFC7364CD0721EULL, 0x037EFAAA588376E1ULL, 0xF80C61C63A2E7653ULL, 
            0xF12B73F99925C8C8ULL, 0xC94CD5DB62079A1AULL, 0xEB08CECF89DE664DULL, 0x3ADC9B023464AF5BULL, 
            0x91A93186774EE534ULL, 0xA36A1AA7701D0DE3ULL, 0x927201934D078BF6ULL, 0x13377DFB4DFC5CABULL
        },
        {
            0x2356E038401E9FEBULL, 0x27E722C2A8965505ULL, 0x6343791E0B690843ULL, 0x21AF29DD32CD46C0ULL, 
            0x3895F73E5622E131ULL, 0xA760FF39A55A9F44ULL, 0xD74AA0D139F83223ULL, 0x0658ABADB4CE4F8BULL, 
            0xA36C1D057D54112FULL, 0x73D5E135CB53ABDBULL, 0x59BD765EA667FF1BULL, 0xB230BC8808C9A6D8ULL, 
            0xEB9807FC39F314EBULL, 0x39D103E08A089A34ULL, 0x559AFB665870FBBDULL, 0x5503939D8D10C22EULL, 
            0x31186C3B3CAA6D55ULL, 0x14C41E43847DAD0EULL, 0xD4C6C27034D0E547ULL, 0xD013477C68CBBEC7ULL, 
            0xA0CBEF8A36536531ULL, 0x9E0A05EB18C431CEULL, 0x44AE4FA96376F925ULL, 0x90D862233B44D192ULL, 
            0xBE5AA96E5FBED993ULL, 0x193743330334E2A2ULL, 0xB4AC920A20063847ULL, 0x65F0F5EC5CBDB2A0ULL, 
            0xBDC240D7352108AEULL, 0x822A46BFE60A79B9ULL, 0x344CB8FDB911A21DULL, 0x0EE85D58AC3AD08CULL
        },
        {
            0xB4F8BBE4309BE1F1ULL, 0x861B420F908731BCULL, 0xE119BE004491260DULL, 0xBC9E85694C912891ULL, 
            0x071404569ACADA3FULL, 0x658DAB1A9AAF0F6DULL, 0xA4A58F0C874846C5ULL, 0xC49D10385BC5FC15ULL, 
            0x170316E17DF015D7ULL, 0xFF59B12D7B9CBB76ULL, 0x921216D8ED4B86EBULL, 0xA501EAA34FFED545ULL, 
            0x464A1D49347407D5ULL, 0xA50A99729DC8D1D2ULL, 0x684C4724A40D7C72ULL, 0xB4B4CA8305A87C6FULL, 
            0x17A8C288ED2B8004ULL, 0x73E56959EB59543DULL, 0xAD99DC8988D76D34ULL, 0x2FE1E65C2E0F5752ULL, 
            0x878468E0D8307B84ULL, 0xB096B5596E5B0D24ULL, 0xB7C21981DF6FDBB6ULL, 0x162B1B641AD29B0CULL, 
            0x21CAED92E145C839ULL, 0xB57A3228A874744EULL, 0xA2CB6F7F96C8C0B0ULL, 0xE79F68706839AC35ULL, 
            0x078102632E1F5F74ULL, 0xDF3F2B6E3BE3FA30ULL, 0xC0CAB15C4375A77EULL, 0x36397D49C1BC9DC6ULL
        },
        {
            0x498E66502C5946E8ULL, 0x3B1C48E2CFF918F7ULL, 0x045BF653CCDDDD08ULL, 0x013BEEA6BBCD009CULL, 
            0x2D34A0F4B4E7E240ULL, 0x0B0CEB3C30D03A65ULL, 0xAD0028301CA0FB54ULL, 0x35EA283DBBBF328AULL, 
            0x59B740F981EC2B4EULL, 0xB840DD68AB212435ULL, 0xA1E5AE559356A469ULL, 0xB47350BAD7190A4EULL, 
            0xD7929149C744F6FEULL, 0x4A5BCC88D65040A2ULL, 0xB0907AB29EAF2B76ULL, 0xEE96B54DF62388CCULL, 
            0xFF7BE94D8BE6CE6BULL, 0x2816F4ED50BF8C12ULL, 0x0974AA414D135F6FULL, 0x00BF132A973A7F05ULL, 
            0x50D32FC963FE0D06ULL, 0x3F6F559B875938DDULL, 0x536F2DA5D76013FBULL, 0x9D3CEA158D3BCDAAULL, 
            0x3ADDA75F5C6278AAULL, 0xA50F17A42CFB7D00ULL, 0xB794881275A16DA3ULL, 0xB7320FA9F0DDBEBAULL, 
            0x514FA1332E1E61CEULL, 0xCBD1C9A806B545E9ULL, 0xC8B83D3AE568A6C6ULL, 0x2348E38D3D1079BEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseHConstants = {
    0xB19E016FB5F23795ULL,
    0x4486E0BD2B740B98ULL,
    0x18B9DDAF2C3EC3FAULL,
    0xB19E016FB5F23795ULL,
    0x4486E0BD2B740B98ULL,
    0x18B9DDAF2C3EC3FAULL,
    0x703D48B565B671EFULL,
    0x8D74316E36D92C23ULL,
    0xA5,
    0x75,
    0x1F,
    0xA6,
    0x23,
    0x51,
    0xD0,
    0xDE
};

