#include "TwistExpander_Cricket.hpp"
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

TwistExpander_Cricket::TwistExpander_Cricket()
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

void TwistExpander_Cricket::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 12483977504742981812U;
        aCarry = 11527360414157823749U;
        aWandererA = 13956877617025726569U;
        aWandererB = 15453072992878697396U;
        aWandererC = 15973205616145429337U;
        aWandererD = 13916617584834077188U;
        aWandererE = 9661926401768750347U;
        aWandererF = 16454436960708441080U;
        aWandererG = 16699493787249732400U;
        aWandererH = 15688913484857395028U;
        aWandererI = 10648305359430763588U;
        aWandererJ = 17098971494395076684U;
        aWandererK = 11871295451934359754U;
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
    TwistExpander_Cricket_Arx aArx;
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
    TwistExpander_Cricket_Arx aKDF_A_BArx;
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
    TwistExpander_Cricket_Arx aKDF_A_CArx;
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
    TwistExpander_Cricket_Arx aKDF_A_DArx;
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

void TwistExpander_Cricket::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12191334867148785722U;
        aCarry = 18324225718484949204U;
        aWandererA = 12572116262634005874U;
        aWandererB = 11925025355065849216U;
        aWandererC = 10979611230530230628U;
        aWandererD = 17577079976760627525U;
        aWandererE = 9800112527791015194U;
        aWandererF = 17353213647706580598U;
        aWandererG = 14328192427853625301U;
        aWandererH = 13147367529035471215U;
        aWandererI = 9703060244229177591U;
        aWandererJ = 10175369983092359074U;
        aWandererK = 16793355981193853328U;
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
    TwistExpander_Cricket_Arx aKDF_B_AArx;
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
    TwistExpander_Cricket_Arx aKDF_B_BArx;
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
    TwistExpander_Cricket_Arx aKDF_B_CArx;
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

void TwistExpander_Cricket::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
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
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Cricket_Arx aSeed_AArx;
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
    TwistExpander_Cricket_Arx aSeed_BArx;
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
    TwistExpander_Cricket_Arx aSeed_CArx;
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
    TwistExpander_Cricket_Arx aSeed_DArx;
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
    TwistExpander_Cricket_Arx aSeed_EArx;
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
    TwistExpander_Cricket_Arx aSeed_FArx;
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
    TwistExpander_Cricket_Arx aSeed_GArx;
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

        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Cricket_Arx aGrow_AArx;
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
    TwistExpander_Cricket_Arx aGrow_BArx;
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

void TwistExpander_Cricket::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Cricket::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 15834103543368659820U;
        aCarry = 15792350656104492941U;
        aWandererA = 10334290536631493997U;
        aWandererB = 12410951213600934912U;
        aWandererC = 18339436584185006350U;
        aWandererD = 17013621400018166302U;
        aWandererE = 16936822632558504589U;
        aWandererF = 11854657714338044099U;
        aWandererG = 18305324309681771141U;
        aWandererH = 15611927766995393164U;
        aWandererI = 13744442715364873157U;
        aWandererJ = 15299639031233200378U;
        aWandererK = 16252669483553221013U;
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
    TwistExpander_Cricket_Arx aTwist_AArx;
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
    TwistExpander_Cricket_Arx aTwist_BArx;
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
    TwistExpander_Cricket_Arx aTwist_CArx;
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
    TwistExpander_Cricket_Arx aTwist_DArx;
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_Cricket_Arx aGrow_AArx;
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
        TwistExpander_Cricket_Arx aGrow_BArx;
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

void TwistExpander_Cricket::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 1, 2, 2, 3 with offsets 4984U, 4323U, 7372U, 46U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4984U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4323U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7372U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 46U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 0 with offsets 6340U, 6199U, 1651U, 2817U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6340U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6199U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1651U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2817U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 1 with offsets 547U, 4658U, 5906U, 908U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 547U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4658U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5906U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 908U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 3, 2 with offsets 4480U, 1805U, 2131U, 4920U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4480U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1805U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2131U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4920U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 with offsets 771U, 895U, 897U, 2004U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 771U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 895U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 897U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2004U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 0, 3, 1 with offsets 166U, 1015U, 148U, 1064U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 166U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 148U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1064U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 2, 3, 1 with offsets 989U, 2003U, 952U, 1372U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 989U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2003U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 952U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1372U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 1, 3, 0 with offsets 365U, 449U, 927U, 1822U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 365U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 449U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 927U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1822U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1764U, 158U, 668U, 332U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1764U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 158U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 668U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 332U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Cricket::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 3 with offsets 1157U, 1110U, 2861U, 693U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1157U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1110U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2861U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 693U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 0, 2 with offsets 3127U, 6477U, 35U, 4504U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3127U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6477U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 35U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4504U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 0 with offsets 6065U, 4959U, 3768U, 6935U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6065U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4959U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3768U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6935U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 1 with offsets 1993U, 759U, 1483U, 7586U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1993U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 759U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1483U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7586U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7137U, 5093U, 660U, 4952U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7137U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5093U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 660U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4952U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 654U, 1402U, 845U, 210U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 654U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1402U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 845U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 210U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 621U, 255U, 424U, 120U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 621U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 255U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 424U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 120U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 104U, 1603U, 1547U, 1103U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 104U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1603U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1547U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1103U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 443U, 1751U, 1773U, 1944U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 443U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1751U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1773U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1944U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 [0..<W_KEY]
        // offsets: 1844U, 957U, 0U, 1999U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1844U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 957U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 0U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1999U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseASalts = {
    {
        {
            0x69B2F1C196D4EDE6ULL, 0x94291EF7F042FDDDULL, 0xB047E10653583BDCULL, 0x4807FF77DA3D9E6BULL, 
            0x3351FB30A3EF44B7ULL, 0x26DA886F83631418ULL, 0x410930CC3861E9D1ULL, 0xDABBB766B521C22AULL, 
            0x0029497BCE3BAF62ULL, 0x7FCEFAB09316E25FULL, 0x4F6D873931F5F157ULL, 0x0BC2A2826EFBE5C6ULL, 
            0xF239BB07EB11E89AULL, 0x55C64B00B40E4D07ULL, 0x43E4ACB30EDD1FF4ULL, 0x4E4E91C5EC69C04BULL, 
            0x7A587CB3EE64059BULL, 0xB9F75FA62D023FBEULL, 0x6203568B6B807AA4ULL, 0xC6ABBA8DACA77C7DULL, 
            0x7E9D0B7B29779777ULL, 0xA70CA6A802574714ULL, 0xAC508357DC48A6ADULL, 0x95D1E3782E383401ULL, 
            0x12726838EB3F3FDDULL, 0x7EACCF6A3B3E484BULL, 0xDF7DE2074FB11D40ULL, 0x4BC0D75ACE519D02ULL, 
            0xCEB7F7DD42E36C20ULL, 0xAD1059706D02BE3AULL, 0x6CD529118E6D54A0ULL, 0x518D396F60CC0DBDULL
        },
        {
            0x2A60A1D3F0ECD49FULL, 0xFB009C9E8C1C5AE3ULL, 0x41B45BEAE155FA56ULL, 0x43E4C4E75AFE7C2FULL, 
            0xD868ACC7ED7DB859ULL, 0xECB6E49D73D0590BULL, 0x6DEC54D3EB472749ULL, 0xBFEF2A85C866CD32ULL, 
            0x857D23548534B54AULL, 0x1F95BECC5524F430ULL, 0xC4D91C6D2F8EFD68ULL, 0x503EEE76253BEC2FULL, 
            0x0D4D9A4EED712B19ULL, 0xA624253339317025ULL, 0x018099D3A08981B5ULL, 0xC702E776AC5BE876ULL, 
            0x180BB32EED03E8AFULL, 0x06A583DEFF434A4AULL, 0x66B3B941ABC7F970ULL, 0x34BDAD53532AF7A5ULL, 
            0xF98FE186C88803D3ULL, 0x8ED69CFD4CC60EBAULL, 0x588A0DA29CB71E8EULL, 0xB5408CBF871AB106ULL, 
            0x1D138F05CCD88877ULL, 0xCBDF364AD226F4B3ULL, 0xBECED5E30973E424ULL, 0x21C973684C9AB852ULL, 
            0x161FA1539F6A3C36ULL, 0x6164A6609EA208DCULL, 0xAF137AB188CE722FULL, 0x6FF112A116CD922DULL
        },
        {
            0x7775992FFA7AB0E3ULL, 0xDA9315DF28C9097AULL, 0x541A2856199D46FCULL, 0xDA82CDB5C8E309F3ULL, 
            0xFE288790CAC61801ULL, 0x36E01BADC3585652ULL, 0xE4CC6543C85AB519ULL, 0xED323F5F69ED88EDULL, 
            0xC2D3AE194FF1C0D4ULL, 0x62FB69CCA1AFBD5AULL, 0xAEA2D41381D9A69EULL, 0xC7416974FEC7D78BULL, 
            0x08432751D60169C8ULL, 0xD6BA24FE6D4139C3ULL, 0x957A710ECB99C987ULL, 0x82B777777608123DULL, 
            0x6A47646D25C0328CULL, 0x2FE350E24E791010ULL, 0x9AF06DA06E215598ULL, 0x5FA97A0A00759444ULL, 
            0x53F3E914AD14D8F5ULL, 0x569A85A98FF9A169ULL, 0x4CF4F576461684E4ULL, 0x6BE812D5674B6493ULL, 
            0x4C5DAB94750EB638ULL, 0xA2D0D421EE307A8EULL, 0x3A282FD250FFFB1CULL, 0xBD883E1BF0BC0602ULL, 
            0x0EB6248799297900ULL, 0x7FB1492CF004B89DULL, 0xCD85AAE020D7FAE9ULL, 0x07CDF9163B4FD6D3ULL
        },
        {
            0x0E51AF0C57052783ULL, 0xFF4A15F2B83A1DCEULL, 0x21F8DE407D21AD4FULL, 0x4E3626161D73B032ULL, 
            0xA5FB657D25C47230ULL, 0xEE378C8547F3D399ULL, 0x521BF6B4EC41905AULL, 0x2C2E48AA446A3D62ULL, 
            0xACC568697363DBC6ULL, 0xE01A6DE195DE69D8ULL, 0xFAB27A3EB7DC2E60ULL, 0x5524C4E29356F84FULL, 
            0x93788DFF642695CAULL, 0x17B2F63BF6587256ULL, 0x5873E98E5C510D7EULL, 0xAC38619A5215DF53ULL, 
            0x364D55A9682FBED2ULL, 0x700C91FFC05DCD6EULL, 0x0191BEED5E19F702ULL, 0xD14D7A6BD524AB8FULL, 
            0x1CC647F25D21799CULL, 0x83314A0115298C79ULL, 0x5F7F731F3885EE6EULL, 0x26ADB4201D94A3BCULL, 
            0x968BC614D0860A05ULL, 0xD495D5AFB6957D32ULL, 0x6E8FAAD587320F9FULL, 0x3701819F5601963BULL, 
            0xE428C47A776A8467ULL, 0x30C1B05B197E8135ULL, 0x9CE803937CF69E06ULL, 0x08A9094B8C70B2FFULL
        },
        {
            0x58796D653D037AEEULL, 0xC3DF1C0786C5621AULL, 0x3BB3177324705647ULL, 0x47861921DD9A1613ULL, 
            0xC6B76156C1F9A892ULL, 0x7CF675CE37CB515BULL, 0x9DB8F8A69AFFF15FULL, 0xB2F01BDEBD18CF7BULL, 
            0xC290F147C4886125ULL, 0xF489A95A7766B084ULL, 0x6D6AF2EFD3646996ULL, 0x454EEB2A22230D38ULL, 
            0xA704C3A6567373B3ULL, 0x0A46A71CC301B761ULL, 0x111BF500CC7F61A2ULL, 0xC77E27534F59B80DULL, 
            0x74795CC4EC2A5D85ULL, 0x60E3CEC379D8715DULL, 0xB8E23BBAC90071EFULL, 0x247875EB5A8F3958ULL, 
            0xA3F1D18F03AFED19ULL, 0xBA35535394F2F61EULL, 0x748DEF55280A1FF9ULL, 0x1A11ADAE97113500ULL, 
            0xB0956CA7FCD8E67FULL, 0xB93907EAD3E472C3ULL, 0xD639E2E382BFEE42ULL, 0xD4AE6A04413A7B6CULL, 
            0xF75960BF8302866DULL, 0xC6D32D9BCCC08504ULL, 0x530FD4B868AC35DAULL, 0xC237DD874D9790C3ULL
        },
        {
            0x7A20B0415E46A643ULL, 0x9CB5ED22E38291A6ULL, 0x4C4C06B1D3793BC1ULL, 0xB0EC7B12ECD0732EULL, 
            0x354E3A03E305879CULL, 0xF171DE7DEAC9A35FULL, 0x103BCA5C6A367FB9ULL, 0xF6CDD6259D8D93F5ULL, 
            0xE4A097A11797EB13ULL, 0x2E8DB233AFF40A1FULL, 0xB5ED92AFB38C00F3ULL, 0xC15C826CE97ED6E1ULL, 
            0x7F82B3D91E98C340ULL, 0xCED825C6770F74C0ULL, 0xF2FC30CCD27CF146ULL, 0xE26DEECA1F2C5491ULL, 
            0x29FB53ACB64536C0ULL, 0xE45D781CBB51CCE0ULL, 0x8C60DDAB17DF6DEAULL, 0xA7C7F893A52C62D5ULL, 
            0x496A0C15B4249423ULL, 0x1CB6587B144BB8EFULL, 0xE9711F791ECC44E3ULL, 0x49A9B7CBD538BCB9ULL, 
            0x5EC20E64B5438A8AULL, 0x56E06CAAEB09C36DULL, 0x694D49A1FF5F90F2ULL, 0x4C3E364AE1FB2153ULL, 
            0xF137B11849863900ULL, 0xB512E8183AA6588CULL, 0x90D7288BF4CDE3A6ULL, 0x2E20F800C11D0BB4ULL
        }
    },
    {
        {
            0x3C117E4DEDCDCAA9ULL, 0x33EF6F812917979CULL, 0x9F1566AC81034BD2ULL, 0xA1B64EBB5CDF593FULL, 
            0x009890A7D42BE929ULL, 0xD92695065659C222ULL, 0x3704C57272497D85ULL, 0x10DF34E080E18283ULL, 
            0x02622D09EFF93FB9ULL, 0xB654D0D8AB9E3D1EULL, 0xF7A6977570BBA606ULL, 0x9599E244C35CBE88ULL, 
            0xF1ACA7FF300D0804ULL, 0x95BB322F097DAE76ULL, 0x32620069B4453619ULL, 0x5CE19BD5CC530302ULL, 
            0x7088CC71FAC2131DULL, 0xFA7936889617C7F7ULL, 0xB4181D73D9848181ULL, 0x97D1E356AAD55FE8ULL, 
            0x1A28181E260A7CBFULL, 0x2A5DBFAE9D0E9E36ULL, 0x48E3CD105A543BC6ULL, 0x13C0F515D27613D8ULL, 
            0xA21B79655D234F18ULL, 0xEB284676A0DF5A3CULL, 0x90DA12C93250AA4AULL, 0x3F4E90FCF3379E6EULL, 
            0xEC4340DD218E0E9AULL, 0x3834C2903ACC0D52ULL, 0x3F2BFB4A5C8112EFULL, 0x2022387251E8502CULL
        },
        {
            0x350EDCBD8D2ED9D2ULL, 0xA2CD2CB55B61062FULL, 0x189317BDC89C1D19ULL, 0x6FA6E4E34E8F3541ULL, 
            0x925AEF7FEA47D0FDULL, 0xE4A4A0FA3BC140F4ULL, 0xE3F34FB272A0C297ULL, 0xCAAA412B88DBE418ULL, 
            0xAAFA1A1D3548FAC7ULL, 0xE0EFF2D49ABD527EULL, 0xB4ADD78686D67F8FULL, 0xF52F90396C0697A4ULL, 
            0x74EBCDA351571FF0ULL, 0xFF588C73B99BC38AULL, 0xBEAB614792534629ULL, 0xC3F413A3EAD7EF17ULL, 
            0x31E9AB14DD8EA893ULL, 0x8C870B81F6A0FE35ULL, 0xDBBFB1C0CA759950ULL, 0x940553695EE19934ULL, 
            0x2B9377AD5E8FF48EULL, 0x4B381905F0550BD6ULL, 0x6C185D8A6C619BCDULL, 0x528B5071E1881D41ULL, 
            0x7BEEA75EEF0E19D8ULL, 0xB6EAF7E4C182401EULL, 0x1B5C8EC2C0D0A8D1ULL, 0x682C2282E7FFF950ULL, 
            0x2BA77F5420C73164ULL, 0xCF957DF0B9DEB85BULL, 0x1EBB09DEBF680502ULL, 0x169540A4531A19CEULL
        },
        {
            0x5EE80D37E5C0ED4EULL, 0x74D972DB027ED5EAULL, 0x84959CB02F9E9C7EULL, 0x77C14DDC7A4073D6ULL, 
            0xC75C6D26F955E15FULL, 0x5B3259B2842D9FAEULL, 0x928FC7D9F726A92BULL, 0x7F2276EF83437915ULL, 
            0x7E3F2A4A7BD9165BULL, 0x94DB5933F5B67265ULL, 0x37363C1500422ACDULL, 0x190CDCAE809FB3CBULL, 
            0xD0EE595DAFED1026ULL, 0x917720AB130D27E2ULL, 0x220B8AD808E5C0D6ULL, 0xB0375A503B08CCA6ULL, 
            0x6FA4478605C05CD8ULL, 0x720AAE19DC2DD0FEULL, 0xDDB4BAAFE8E14028ULL, 0xE1EDAB85ED877E4EULL, 
            0x14F9F1D4E07918C1ULL, 0x9A31DC3DD4367C36ULL, 0xDCB73DAB86FA3586ULL, 0x7B4C43D5AD9E5D1DULL, 
            0x4FE48D28A40D3917ULL, 0x1BF635A30144D65DULL, 0xDE5590B3FCEFA463ULL, 0x641A381233EA2F0CULL, 
            0x7682D9CCE7D93738ULL, 0x93AF1CC74DED68BAULL, 0x647F0EC81061243EULL, 0xBB417F381D233627ULL
        },
        {
            0xEE73341976AC8A5DULL, 0x7740AE0B9FA20F6DULL, 0xFE5EC61B6AE7D7A9ULL, 0x0A6D1B8E4DE4E483ULL, 
            0x23CFE5A2D44A3B23ULL, 0x36CEBB47E02A35AEULL, 0x81F6D2CA53540525ULL, 0x71E870066E604570ULL, 
            0xCD1BD24872CAA89EULL, 0xECA15062437291D8ULL, 0xCC267FAB6027E42CULL, 0x969F36C5F310D049ULL, 
            0x85C43051B76FCBFDULL, 0xC6CDA8EF055EF329ULL, 0x0351F88D4C53772CULL, 0x4D3835BADCC0ECF0ULL, 
            0xAF95D061F2FCD0CEULL, 0x7501742CEC110098ULL, 0xD379B4A437F0A92CULL, 0xF71268B826E9A116ULL, 
            0x12F321CA1F3E743BULL, 0xFC391AC57D49B734ULL, 0xDEE61D3460D573DBULL, 0xB594452F63E33EDBULL, 
            0x4539299F5C4AA8DBULL, 0x2C7D7A81AFBFB333ULL, 0x7343FCD4E532C972ULL, 0xF1441857A8821733ULL, 
            0xFD2D3CC76E627390ULL, 0xE5F1664908717BF5ULL, 0x5FA730619A5724E1ULL, 0x8668AC41771C2DD2ULL
        },
        {
            0x7E2A80EC8751A793ULL, 0x19A923E31E3BCC12ULL, 0xC254D5139F1BCD5EULL, 0x55DE7B2EF27DFED3ULL, 
            0xF6D8B5F571330891ULL, 0xE681670F14CA9B50ULL, 0xD058176CDDBB2C82ULL, 0x7D1B85129E87A376ULL, 
            0xB669F4208B82CD49ULL, 0xDB0C86D27252B5BEULL, 0xCCB38D15143397CCULL, 0x28F2E595442BE770ULL, 
            0x0B4424451B1F51D1ULL, 0xAF9645B78E71B863ULL, 0xCC6042159DC2B521ULL, 0xFE04C0716E7759C0ULL, 
            0x79CD05BE43E11745ULL, 0x36BC6C3A4164D5FCULL, 0x0389C7017B62F0F4ULL, 0x6E9AF1FFFC29AF3AULL, 
            0x78A9731623F76ACDULL, 0xDA2575B45066B289ULL, 0xB42EF53664B14A20ULL, 0x0F6CC640B554AADCULL, 
            0xDF4C3E4A9980B786ULL, 0x5116F4FA504C6D56ULL, 0x7780F63BF40DA0BEULL, 0x1C402B33D841FCC7ULL, 
            0x911D734DFD16F33FULL, 0xF5C93618F89F7ADFULL, 0x9F20A13C4D97D3E1ULL, 0xF75B7964988EB188ULL
        },
        {
            0x019E1A70B5A5F15FULL, 0x8FD25E6D48F36BA2ULL, 0xEDFE5D79BCC694FEULL, 0x538A2BF8C2DA3533ULL, 
            0x77D500A382505771ULL, 0x625BAF374AB633C9ULL, 0x6CC582748F070D58ULL, 0xC64079ABD03BE267ULL, 
            0x22A265F152C7A527ULL, 0x2FC48C41845B0A44ULL, 0x737DB10D6F89CA96ULL, 0x68AA7ED1DACA3CCEULL, 
            0x7969C2683A412969ULL, 0x35A584425F586B28ULL, 0x8254283576FBCABDULL, 0x6AB18261B56217FCULL, 
            0xEDAE47D48B2962A7ULL, 0x23A56FB3CDF39A49ULL, 0xEEFB451A5203717EULL, 0x45BF3E7A64DD504CULL, 
            0x7376D9DF94A8EB4AULL, 0xA63806625E65E5D4ULL, 0x846E7A797A79F3F1ULL, 0x689B123CC1089E0DULL, 
            0xE65E186A038C584AULL, 0xC20F5C9DDEDA8F6EULL, 0x11AA35F7EA2F157DULL, 0x79D2B047E73B1611ULL, 
            0x13852E97897498DCULL, 0x395CA115A8384EBEULL, 0xDA1F125457CEAB40ULL, 0xB0076E1B73DAE82AULL
        }
    },
    {
        {
            0xCE1C7473369B095EULL, 0x370140539D358FE4ULL, 0x8967787215CF4950ULL, 0x9866CA4AEC503169ULL, 
            0x8EDA8CCC9D745227ULL, 0x546329F8E89A6F1BULL, 0x7EC0DB410E2ACEE8ULL, 0x7FB900E45D6D15EAULL, 
            0xCED05863ADC358D7ULL, 0x5333B61BF7E6D96EULL, 0x26FDFE0E61B172F6ULL, 0x4269F1013CF5A6CCULL, 
            0x5679241AD5A34FE9ULL, 0x622AA97ADCEB227AULL, 0x2123A9A9F7BD581DULL, 0xA955CF35EEC88B7AULL, 
            0x4A67C9F415457B86ULL, 0xBCEC09EC65CDA0F9ULL, 0xA1E92A7EB73E9D17ULL, 0x2CAF10D3BFC9C567ULL, 
            0x5485598F726588CEULL, 0xA02F88FD028FF9A4ULL, 0xA73516BABC4983AEULL, 0x9B14CEE7B721F616ULL, 
            0x29D0192CBE6A1AF2ULL, 0x307BD7DFFC461994ULL, 0x291015D6F01AF8FFULL, 0x923810C4F9ACFCE4ULL, 
            0x883F236830E34788ULL, 0xEEB1282F38FDEDFDULL, 0xE66DC1A4CC4ED880ULL, 0xF4B0B8FD9E69ABEFULL
        },
        {
            0xC09157F7258A091FULL, 0x7E8F5F8DC206AC26ULL, 0x4BCDE37C66EBA6FEULL, 0x743459F61FC9F5EEULL, 
            0xD997E7B4CCAECF2FULL, 0xB76E2AD27DBE73D9ULL, 0xBFED94B8707BD5B9ULL, 0xA0B7E97D760812E4ULL, 
            0x5BEB6634DC136E8EULL, 0x1E0DD02FE4BA8654ULL, 0x6CF11A8DC06F388DULL, 0x98F281C6773DDEA6ULL, 
            0x8600C70665F2AF38ULL, 0x760AE3CB2119EEF1ULL, 0xFBA1F1B35B87A227ULL, 0x906276C7566C9696ULL, 
            0xB32D7B4E4D0A7D87ULL, 0x339F9AD76BCD9BF0ULL, 0xC907B51A7B372484ULL, 0x33DCEB41035FC0CAULL, 
            0xD7B993DEAF4EC72DULL, 0x8F9174C4D121F451ULL, 0xD02DF763FB43C5DDULL, 0x2AB77C9CDD07FA45ULL, 
            0x767AECCCFF6CB21DULL, 0xD65468A6F5618503ULL, 0xCC4C6272BDF46426ULL, 0x62F3705D6CDC0037ULL, 
            0xBF510BEF1E5BE566ULL, 0x6F5599C70D4B028DULL, 0x5DF32CB2C4565E13ULL, 0x9C0DD7EDF49AD1E3ULL
        },
        {
            0x022B5C8E63585BB3ULL, 0xF80B38B3BB31BAC8ULL, 0x8582DBB23C565ABAULL, 0x3274C6014DF86A75ULL, 
            0x1F60C6973B30293AULL, 0x206FC7BE247DB05FULL, 0x31F61E4798694A19ULL, 0xFA1998EA46D9B39CULL, 
            0x7A66BD2CE3E1F394ULL, 0xCFE8881F98F03150ULL, 0x2A5AD5883575A9A7ULL, 0x47048100E2F74B1EULL, 
            0xDB01A00A15918B17ULL, 0x726D274A950254F5ULL, 0xB4244FD17A150A4DULL, 0x3903C9BF47941D9AULL, 
            0x49CC3E304B8962F9ULL, 0x3B0A5F8AC27382EEULL, 0xE631BE19DDECA93BULL, 0x53668CE36083F839ULL, 
            0xA01AB27BC1D26DB1ULL, 0x2EED4C2DD9B58D9EULL, 0x0836FCB545483A36ULL, 0xA7D618EC30070572ULL, 
            0x1450FC0CF53AC8EBULL, 0xCF4ECF9501EECC53ULL, 0x89EE0AD5981BC0FDULL, 0x3C98F0ABF014292CULL, 
            0x9192655E43120EE4ULL, 0x2960324D99BDCB04ULL, 0xFA2EDAC6F05B2D8AULL, 0xE284661CF273FD6CULL
        },
        {
            0xDD83F3710665C513ULL, 0xD823EEBE320B57FEULL, 0x066890E18EA9F51FULL, 0xFE3F7AB4E96DA260ULL, 
            0xA3E591A3FB431CD6ULL, 0xCD1545BE4F35A0AAULL, 0x7BAEDC66535C47BFULL, 0xABE25C366DAEE47EULL, 
            0xC910D731B0D6050EULL, 0xD284931C2E789ADDULL, 0xF5457F0EDF4A0A02ULL, 0x795E24141570B5E1ULL, 
            0x19F9C2CC4637B305ULL, 0x21B573AA60E77201ULL, 0xD660E0E473CDCD70ULL, 0x2527599FD900F744ULL, 
            0xFB76848EBB6CBBB0ULL, 0xAF0C2376D7FBA452ULL, 0x745DD4F8D313A4A3ULL, 0xFE5518C51F647015ULL, 
            0xB5B5BA4434DAA2E0ULL, 0x1D64F3BD1FE1CC1CULL, 0xEB866D915CC8894FULL, 0x636576ED5EC5AEF2ULL, 
            0xF4C9D8B70677E147ULL, 0x3FE8BB8D15B019E8ULL, 0x0BD1FE3BE14309FAULL, 0x6BCD290A49B4EDC7ULL, 
            0x8D27195C3662006DULL, 0x967931E68F6EA8A6ULL, 0x592FF5676869230AULL, 0x95805D9792892041ULL
        },
        {
            0xA52664BA9604B0F2ULL, 0x8132D803AE472579ULL, 0xDAE171B23C20A11EULL, 0x35851C2209233334ULL, 
            0x8D700D933FAC3D11ULL, 0x7EF7AB935DB602C9ULL, 0x2C2DA9ABABABEB4BULL, 0xDD9278B59692D492ULL, 
            0x86CA24E97558759CULL, 0x11E86247BDFFD782ULL, 0x5729807989C0A2A3ULL, 0x5B3A4BDBA0D91EB0ULL, 
            0x33FF547E0CEA5BC5ULL, 0x75CD76E77A5A84D4ULL, 0x750239F7DA900E04ULL, 0x3823A6A593C48DCDULL, 
            0x9C74CF6D0440EBB1ULL, 0x2A1CA4F9D00E235EULL, 0x4E4ABC25DD2E025EULL, 0x3503383A45BE984EULL, 
            0xE2974FE09D64F4D8ULL, 0x46D20958F3338CBBULL, 0xB8A7A8338E9A2379ULL, 0x701795125E06774AULL, 
            0x1341C0C53D0FF326ULL, 0x7D0EABC9682491B8ULL, 0x5928E778E15FB956ULL, 0x3345DCC38F4710E9ULL, 
            0xDD7080AF0BB23BF9ULL, 0xAE277FDFF2EA64D7ULL, 0xA32965B4E696FAE8ULL, 0x0261ED85643907ECULL
        },
        {
            0x2A8703128FA7C64BULL, 0x7427FFD71A0367BAULL, 0x6A8D99CE7DAC0770ULL, 0xA0CF7307FCAB51E3ULL, 
            0xA1038691F77A958CULL, 0x59CAA9722FAC9F3AULL, 0x7B9DD539B010B709ULL, 0x51A35281C9A7713FULL, 
            0x8DCE2A78EDAA039AULL, 0x95BA0C9008CFFB1BULL, 0xA3B37583090B57B0ULL, 0xCBFCEE9FB0FA47E9ULL, 
            0x43824406D3F0E10FULL, 0x41DFB958F6CB3E7AULL, 0x62A30EBA6CFCC89DULL, 0x985E56D35CFBF30FULL, 
            0x1DB305B30AA50795ULL, 0xED6E8D29AE21367BULL, 0xAC96FFB90EDF0A2AULL, 0x348D46C3FB954BD9ULL, 
            0x1C0791A58EF73DB5ULL, 0x6497A58F20D256A4ULL, 0x8B9D49183F238276ULL, 0xBA3AFFBBFA420129ULL, 
            0x66A498C610C5DDE0ULL, 0x78405A27150E4B1AULL, 0xDA90EB38CA9677AEULL, 0x576CF4A187B6ABAEULL, 
            0x88B7EF5DD60A9226ULL, 0xF13F94067DF4F237ULL, 0xE374175FCEFA7556ULL, 0x7862D0C53FE62005ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseAConstants = {
    0xEED215F15C088500ULL,
    0x3973526A85F301C7ULL,
    0x6C92603ACF3ABA1AULL,
    0xEED215F15C088500ULL,
    0x3973526A85F301C7ULL,
    0x6C92603ACF3ABA1AULL,
    0xF0067345F344205FULL,
    0x979230C545E13339ULL,
    0x5A,
    0x21,
    0xB0,
    0x2E,
    0xD7,
    0xD4,
    0x5D,
    0xF2
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseBSalts = {
    {
        {
            0x0871824BF32A6AD9ULL, 0xC46A3BFBBCCC774FULL, 0x5F7E75D9FA3CECE5ULL, 0x4022807F898B603DULL, 
            0x178261654AD96CB2ULL, 0x172C371BC777F60EULL, 0x8D66BD0E80B7B4D2ULL, 0x1FD7E8CEF98FDD43ULL, 
            0x7EF6A7F20EE7669EULL, 0xB1AA33B551173731ULL, 0x2BF974762E0838B9ULL, 0x00523414F6B8759DULL, 
            0x232DA97A029C24C1ULL, 0xC4162A3DBBEB32F9ULL, 0x13A3F223F1CD1968ULL, 0xEFD2DFDABD226BD0ULL, 
            0x51479E376B0C5F89ULL, 0x59468D978A931EDEULL, 0xF3295D636831CADCULL, 0x952CEA2F30587221ULL, 
            0x83CA8D0B9101D6A7ULL, 0x707889A05DE193E0ULL, 0xFA5430DC146A44D8ULL, 0xC9C53FD16BA89E3DULL, 
            0x93AA2B898548B701ULL, 0x13F36CC4381A08E3ULL, 0x09D977FF52DEA118ULL, 0xFEE227EEE0AB440EULL, 
            0x637A1E5C180BEB88ULL, 0x94E124D06F135315ULL, 0xA956D9038280AE9BULL, 0xD8E56991E7EAC019ULL
        },
        {
            0xFBB9C3749B0C01E6ULL, 0x961048EB6C9817E0ULL, 0x3639A62D32E3F217ULL, 0x90694C758A6B9098ULL, 
            0xC98F4C1141F2D004ULL, 0x0D6E50910F196E55ULL, 0x87F57BE932C88919ULL, 0xE044BE92D16BB8EBULL, 
            0x7B4270F05F1D168FULL, 0xC2DCAF55D65FCCF2ULL, 0x43DE52F798E9EFA4ULL, 0xFA5853A2A728679DULL, 
            0x833C1D676E355977ULL, 0x1F59B2179AF7B815ULL, 0x6205D300E12291A4ULL, 0xE0E437781FCAFEA8ULL, 
            0xBBAF98B5AF64C7BCULL, 0x31E86133C5D2D1CBULL, 0x2D633031205F4231ULL, 0x6C2A0E0DF5100A59ULL, 
            0x9CBB70EAAE201E92ULL, 0x6C4FD4A8E69E29FEULL, 0xEF5244EAB66E7CD2ULL, 0x79F40E40490CEB65ULL, 
            0x3122FC093F17619FULL, 0xC751753947931940ULL, 0x70E078377EAAF95FULL, 0x3DCAAEFE11C2F93FULL, 
            0x61E3B50269CD97F6ULL, 0x69A8F5ED49076ABDULL, 0x33C289169A1A1040ULL, 0xA1A4974FF3AC2B3CULL
        },
        {
            0xAF1F5C5F76C971C2ULL, 0xA40489F43DD23C6BULL, 0x84E77312082E14FEULL, 0x81F22FDE6E0B1BB7ULL, 
            0x912BEF1C9712BF1AULL, 0x6347B26D81FE3267ULL, 0x3D927DF5B59A5A06ULL, 0x1648983F59702C59ULL, 
            0x79648DF6C05387CAULL, 0x34B6D09F053F4D79ULL, 0x5E772B368C13B9DBULL, 0x31AB8F54EDE16B57ULL, 
            0xF778F1DEA5CACB76ULL, 0xBE7034BDF2C54846ULL, 0xBAB0BE17425863CDULL, 0x247612DD627A8132ULL, 
            0x35ED0E1D140D14B2ULL, 0xF47F255F40CF7698ULL, 0x3673C177A862C0BDULL, 0x4A1A7D615EB98906ULL, 
            0x4A24C217C8C77869ULL, 0xC17F4A47278716E5ULL, 0x9D5109CE1CE66C1EULL, 0x6F5488D13DD17199ULL, 
            0xE1F737E3CEE2BA4EULL, 0x18EE44DA291CEF1EULL, 0x048EB5D1BDEADD24ULL, 0x1145F0900969D395ULL, 
            0x1150919F85CC8EACULL, 0x8BC4F361C4EBDD58ULL, 0x9E03FC5B54C1E631ULL, 0xD600FFDBE7B3B39AULL
        },
        {
            0x26743AE6BB68FF80ULL, 0xFEF52E8FB877D9F7ULL, 0x0868E6497D7662A4ULL, 0x5AEA11A29F8DAE4BULL, 
            0x634673F86091B412ULL, 0x67CA4046CD5DAE16ULL, 0x2C6CEFB1EA0C76B7ULL, 0x08BB794BE393D465ULL, 
            0xEE8D3ABAA6C9AF57ULL, 0xAB17E3643C782D75ULL, 0x7197FDFD2B5DC4E2ULL, 0x8ED9CC31E1A641E2ULL, 
            0xED376E072DC86EA8ULL, 0x4557D87B7E3291B5ULL, 0x7E0AD648E322E7CDULL, 0x74A4143489C6F640ULL, 
            0xA3EC16F62DDB14A6ULL, 0x39BBB6063D3DDAB7ULL, 0x004E1286AF51196BULL, 0x28B084EE3F0A1F3EULL, 
            0xC2DDD6BC02151876ULL, 0x4BB39A6DBF9F92EBULL, 0xF3146671B0547F14ULL, 0xA39198696968CB1EULL, 
            0xB97E25CB29942F10ULL, 0xEE14C9890E0A4EE0ULL, 0x5CF893B3A03C7814ULL, 0x142947425976F3F3ULL, 
            0xE1B174FDD5A3D346ULL, 0x5FBA5D180FE0E181ULL, 0x0700BD727682286DULL, 0xDDB348DDCFCBDA61ULL
        },
        {
            0xA8C853E5E7FB460DULL, 0xA1ADD1087B6FF6C2ULL, 0x07F08C894094A93CULL, 0xEBE440371069C57DULL, 
            0xD21109D404F050A2ULL, 0xAC6440F73B5EB0C4ULL, 0xDC92055D7C4D4F57ULL, 0x08CA4DB7A2E44789ULL, 
            0x154825E8048DFA30ULL, 0x6B2FA1244FDA5079ULL, 0xF9BF3214C434786AULL, 0x418C619A548FF102ULL, 
            0x6DFC056B457473C3ULL, 0xCE3CD17801A0780DULL, 0x404D0207A7100EF7ULL, 0xE986856D89CDE183ULL, 
            0xC00322E345629A81ULL, 0x17A13E42AA7E94D6ULL, 0xAC94087499861D8AULL, 0xC5D3E4EA33740EC5ULL, 
            0x6485B4D2B41FA298ULL, 0x66411CC20B2A03EBULL, 0x8E6BC8D81B56F572ULL, 0x09EEECE32B460C8EULL, 
            0x3C201B331AB9FCBEULL, 0xA4B79A30E873FE0DULL, 0x2AD5CE197A459825ULL, 0xDED08AA820EAD570ULL, 
            0xD8EB8FE91CD55A38ULL, 0x1AABFE748B8128C5ULL, 0x51C5DA631D05BEF5ULL, 0x50D501A3F1CAAEF6ULL
        },
        {
            0x8C153BE3E86905A5ULL, 0x72144759A9C16B2BULL, 0x4B61DF526124BF19ULL, 0x2532061D28136E4BULL, 
            0xFE6EA19A22B9754BULL, 0xED583CD4B81D3BF0ULL, 0x264BA930626D0999ULL, 0x9A17313AEDD56400ULL, 
            0xF0631B89558CF3CEULL, 0x4D632D892FB9FB19ULL, 0x2E3E3B9C614E12ADULL, 0x31C19708C866BE3BULL, 
            0x854B1A9707ADB116ULL, 0x3477DD96816E1579ULL, 0x13718EA7C13EC0D8ULL, 0xFFD76F021D3137C7ULL, 
            0xE3845BE6BD92867BULL, 0x2BE3105E3D1840B0ULL, 0x988D2C5EAB881E15ULL, 0x5A50CCBCE14ECDE6ULL, 
            0x482A6853A2929B2EULL, 0xD6EEEEF03A08E18FULL, 0xD914DA95851A0D8FULL, 0x5868EDBACCCA31F6ULL, 
            0x93F9B60B54749CE1ULL, 0xC4BB044826DC781AULL, 0x7F210BF6316C96B0ULL, 0x7A4978A7F97EF303ULL, 
            0x79D086CA06D6444CULL, 0xBC1357534BC6FA30ULL, 0xAC205C1FE4AB42E9ULL, 0x98D1C0D727C84EEDULL
        }
    },
    {
        {
            0xD73DF181FDE3DFFCULL, 0x47FD2257F14DDC4EULL, 0xC196E689AC8F4077ULL, 0xE5488092D6AB09D7ULL, 
            0x8AA3175410387174ULL, 0xC61F076F5EDCACC5ULL, 0xBE272BA002BF4847ULL, 0x8372CB0FC68625B7ULL, 
            0x02E60AD77717DBC5ULL, 0xFD443D849C69623DULL, 0xDD98377BE3A5C9D9ULL, 0x2D44802A4FCF22DAULL, 
            0xB892AD23C0651A39ULL, 0x5CD2AD930340CD15ULL, 0x1BDB308535247664ULL, 0x85FB5F56095F17BBULL, 
            0xC6C388233738F170ULL, 0x5368583051798E37ULL, 0x6FBFCB4DAA749ABCULL, 0xF8F013A90DEF74F5ULL, 
            0xE77438C7FCC9C473ULL, 0x6D464D818AE91DFBULL, 0xF8983B193D298573ULL, 0x177F994E833D893DULL, 
            0x78BF8533D3EF056CULL, 0x7482A6C257E3A747ULL, 0xA324B39D64CF35B9ULL, 0x084D1474AB00277AULL, 
            0xFBD8A7BA555B2ABDULL, 0x6DEA97F3C035498DULL, 0x754235B6913F65EEULL, 0xA383FDB1A3155F7DULL
        },
        {
            0x5C4DF034437FB786ULL, 0xFBC5E1ABF490046EULL, 0x42380F8F59910D92ULL, 0x165A11893D5E3ABFULL, 
            0xD8B56FCB8AEF7873ULL, 0x1242EE97147A004DULL, 0x533563387C6B30BCULL, 0x26D5C6EA01913FB3ULL, 
            0x7826CA2296C5337EULL, 0xF76473A38845D127ULL, 0xD9A039ACFC631E65ULL, 0xAAA5A5F3D9393550ULL, 
            0x19FE5C6F7ADD878AULL, 0x23C4DD0CD814BBC9ULL, 0x42DB241CEB2DE212ULL, 0x7CE97D0F317DDF56ULL, 
            0x02B2D6F8134C86B9ULL, 0x22191C2F785BB3EAULL, 0x83EA5BF9C205414CULL, 0x7BDAB88500CE81E5ULL, 
            0xFCEB8AA431AE8D19ULL, 0xB94987740BC25507ULL, 0xF0EC1454F8316C05ULL, 0xC0EB55CC2560A027ULL, 
            0x8BE3AC5852A082ACULL, 0xFB9EC85EC8BEB198ULL, 0x656F26441942258DULL, 0x19198DCF0CA12046ULL, 
            0x7DE56A0C924BD545ULL, 0xBE72A4A7BB0E812BULL, 0x74C863ADA6AE5861ULL, 0xAE178FFEE0827595ULL
        },
        {
            0x9E4FF285276EC6D0ULL, 0xF578A12158A568BAULL, 0x030FE456A71BDC22ULL, 0xC22176E7F867647EULL, 
            0x9FCDABFD552867F7ULL, 0xC16604DEFAD71B54ULL, 0xFA9B0B802C4FC015ULL, 0xBE783EDE3D5806B5ULL, 
            0xA1ADF9715DC06FABULL, 0xD4EE330EA8590B57ULL, 0x7654B0CFAD2D7E13ULL, 0x6FAB603891E7AFE1ULL, 
            0x97A2AB14EE0D5479ULL, 0x0F0B8C67F6392CFFULL, 0xC3C126E958A119C1ULL, 0xC18E8B5CE85BACAEULL, 
            0x60A406B5568656A0ULL, 0x59BA82FBC792CC4FULL, 0x0E530457EB547E7EULL, 0x4B6F23341E2696FDULL, 
            0x62931BA156FF8404ULL, 0x66EB545CA9F5E427ULL, 0xDA1931E0C8798643ULL, 0xFCBDC568BDD7391CULL, 
            0x6CC3811BF9B7F08BULL, 0x03543235A35E3951ULL, 0xD241810E1ECEB09AULL, 0xA57AFB376B4684B0ULL, 
            0xF427D6D1FCAA56D3ULL, 0x98E02836270A5290ULL, 0x8AD8CA3E62594EEFULL, 0x856E1E7EA318801AULL
        },
        {
            0x43B123E459D0CD60ULL, 0x3500C2487FD4C6EEULL, 0x38D52B81E09342F2ULL, 0xE0F29ADDEB811D96ULL, 
            0x53AA99ECA1AF7770ULL, 0x7880602B11072D78ULL, 0x2E822632E52D2AF8ULL, 0x201351A118FE9B1BULL, 
            0x9B5511C8A183D0EAULL, 0xB0F1917609A489D6ULL, 0xC83F64F6E8E7DF01ULL, 0x3348A05FC1A65EF5ULL, 
            0x8045EEACEBCB14B4ULL, 0x4D03FAA79575DC9AULL, 0x01B4DDB69FD62885ULL, 0x2B5505F80C619685ULL, 
            0xB766437978F18BCBULL, 0x87458B1EFABDA7F1ULL, 0x3BBA92A2B870E073ULL, 0x49C56211DFFBFDD1ULL, 
            0xAA91307D76EF12A8ULL, 0x523E9A39EFAA3362ULL, 0x09235F9D7363F890ULL, 0x482F0CAA44420B7EULL, 
            0x65C2BD8B409FE8C8ULL, 0x77F621B349E0CCD9ULL, 0xE82FD28FB81B0695ULL, 0x7CA7FE55719FD21DULL, 
            0xEECA5DC3CE609924ULL, 0x5130631B4CE54C1CULL, 0x116CEF87153636FFULL, 0x2F0C6ED902A87AE1ULL
        },
        {
            0xCE284E08FD757267ULL, 0x5DDA9CDAF713A8BBULL, 0xC21C1597328F22DCULL, 0x654F58F3A1452B9EULL, 
            0x7FF2A5A7498E1662ULL, 0x45915E3B05F07AD7ULL, 0x7F214FEDBA1FA63BULL, 0xFB88C901BE09CC66ULL, 
            0x5B43BD1132F8D5C6ULL, 0x73CDBA60BF5B7801ULL, 0x1623BCE08F317274ULL, 0x3EC74270CD67AF3AULL, 
            0x55BD02A7E31C00CAULL, 0x7D25A80B198D55FAULL, 0xEECCA827F47CED6FULL, 0x2394EC0C16992DFAULL, 
            0xFF25A13B14DCFC74ULL, 0x4EC6B9E58B45A23EULL, 0xB078A7D366088F1AULL, 0xAA1625A4E03C2D2DULL, 
            0xA3F87D9A6B7D3017ULL, 0xA21E941A79785761ULL, 0x88B6FC04927868C2ULL, 0x2370D24798BD4DC4ULL, 
            0xA4F49868AEFE345FULL, 0x972DDC59BA12D8A2ULL, 0xA468BEF08B31C676ULL, 0x09109E699B9602A3ULL, 
            0x6F1C95F604384DE5ULL, 0xF2362EFAD819C17DULL, 0x0A1612667C9587F4ULL, 0x0C955AED4F29B138ULL
        },
        {
            0xA5867FDB5C9D86C3ULL, 0xFBD618A7F8467207ULL, 0x6036A5840C7BD404ULL, 0x22E728023723C0EFULL, 
            0x0E6370DBE3A7DB2DULL, 0xD67E25A10130BF91ULL, 0x00E8F2260FD24F2DULL, 0x06B3615DA564E83CULL, 
            0x7C4B6D5FC952AC20ULL, 0x1E062652B4D4EA20ULL, 0xAEE6015EF3FA0659ULL, 0x38C83F026508178EULL, 
            0x8CCDB95C95E74836ULL, 0x07ED21CE343A44A0ULL, 0x1068C55A881C2A32ULL, 0x06D228790D7CA12DULL, 
            0xE9FC064940D30ABBULL, 0x9B03DEDF5C7707BBULL, 0x56A90CB89D356D89ULL, 0x57821165F5F2B30AULL, 
            0xC76BA7DBBE85842DULL, 0x372E65A335FF9471ULL, 0x62259FBB52F32E83ULL, 0xD7B3E333B94CD7B1ULL, 
            0x628E984D4837025CULL, 0x3030E43D6E17F25EULL, 0xC6BCCBE691771699ULL, 0x5CCDC06FE8B128BDULL, 
            0xC5DC30698660EF4EULL, 0x7E3AB72DD8845993ULL, 0x31758C9CF535BFC5ULL, 0x3F12946092797CF6ULL
        }
    },
    {
        {
            0x9FDBDC5A0AFFAE7AULL, 0x9EC955563B51CDA8ULL, 0xDEA081837722DC6FULL, 0x9B29F1F2D6EC195EULL, 
            0xAFE751C4CA2C3C46ULL, 0xC2054A1004106DA8ULL, 0x68BD0ED473C72D91ULL, 0x178BEC406E9DC566ULL, 
            0x0DA109F832DEBABBULL, 0x6E39ED60AA694D74ULL, 0xA9E66D77D4BDCFEBULL, 0x7B2269F9011F523CULL, 
            0x1DC1029AEA4BA0AAULL, 0x72E6B1769D7D3005ULL, 0x094D7D85A9AF6C6CULL, 0xBA41713E976CC7ACULL, 
            0xBA5F4DB2F5F0AF15ULL, 0xE5738419DB81D65DULL, 0x3A9A2E6CEB79F24FULL, 0x59ABC7429F4DA030ULL, 
            0xB839C82591438670ULL, 0x9586FA52D7E2606FULL, 0xD00B5DD89C14AB63ULL, 0x5135A9A4BFA0DEBBULL, 
            0xC5F73EF2C28FF940ULL, 0x85A7B8AFAF52FE7CULL, 0x6D049FA4C4F260D2ULL, 0x80D704C8E281B174ULL, 
            0x48E0A4F5E01BC11BULL, 0x7455B4555E928B01ULL, 0xC41F4B63BFE058A8ULL, 0xC301B041583E8039ULL
        },
        {
            0x87E32206AA566AB0ULL, 0x2D4BC9D610481745ULL, 0x3085CB7F68015A52ULL, 0x8AA7703240871D42ULL, 
            0xB4F2541763A86B2CULL, 0x0D59E314B1009082ULL, 0xF9133759B288F191ULL, 0x24ECD228C1FB6084ULL, 
            0xDA48D75D50C88085ULL, 0x0071461274B75E61ULL, 0x1E6A931EC2046645ULL, 0x7BEDDEE6A65292A8ULL, 
            0x885FC2B0CE5F2851ULL, 0x8BF6E327FB0601D9ULL, 0x892AF863844EAE18ULL, 0x43A493E188DBE333ULL, 
            0x6DE6D85FB74D250AULL, 0x4A1B5D3EA9C271C5ULL, 0xDFFB6B2CDFAD4180ULL, 0x804C62C558146B67ULL, 
            0xBF7A87DA32186BF8ULL, 0x826CE840AA57842BULL, 0xB4BF3A478B086438ULL, 0xEF6F4D0A892DF293ULL, 
            0xC7693796E17CB8EFULL, 0xDA2B37E40D5A3846ULL, 0xFCCC2F92AB786D38ULL, 0x771AB2AEE1E47B87ULL, 
            0x0E024C7821D64113ULL, 0x7DD290CB261F1C62ULL, 0xFCC15D3CEF45604CULL, 0x9FB0235AA2D9264BULL
        },
        {
            0x72675ACD7FC63CA5ULL, 0xBB18FD12FD15EEB0ULL, 0x9549B3E930748BBEULL, 0xB99E7E3C780A618DULL, 
            0x3A744D735F904994ULL, 0x0D9C4C9CEA6CA0E4ULL, 0x3D10328DD6F36058ULL, 0x944440306DF532A1ULL, 
            0x2C0824C8B3B57FBDULL, 0x85959318C8E9C382ULL, 0x62454EE36C23D98FULL, 0xA951BB30BAC01EBEULL, 
            0xDCFA53018D7451BBULL, 0x3FF03208FA0CB055ULL, 0x7D291D0FD35C523BULL, 0xF0780D8A83318EABULL, 
            0x2EA18167FE98364EULL, 0xC7A908BAF6F4E306ULL, 0xAB543A5DC985C24BULL, 0x2C92FD09F1DD6CFEULL, 
            0x263C7D52397B4848ULL, 0xAD728C7B54DFB18EULL, 0x775465AAA07DCAE0ULL, 0xE2FA815A8A87B5D2ULL, 
            0x8093614F9E06BD6FULL, 0xFA2C6B0A878A00FDULL, 0x76907BDF4DCC3CE4ULL, 0x7ECA4E80FD085339ULL, 
            0xF43F1F143E7DE07EULL, 0x7BB5F169C59006A4ULL, 0xEDADADA251401375ULL, 0x58EDB1DBF84C5E81ULL
        },
        {
            0x424E4F000B0795D9ULL, 0xA2E77B85C259E8B7ULL, 0x4390A1C005DC5FE6ULL, 0xBA782487C1C62C30ULL, 
            0xDEE8B148A5ED30F4ULL, 0xAC558E3C37E96F46ULL, 0x4BEF5022CD11482FULL, 0x912E77C181BED32BULL, 
            0x0F827CD8218C5D7FULL, 0x866C5CCAE5DC9202ULL, 0xCC6A1E25A0D727BCULL, 0x20D446EE3452EA2CULL, 
            0x0229A682DC54AD0FULL, 0xDB1DFBE30FFB2153ULL, 0x836D6883242DF7DBULL, 0xB7393A3798E0D261ULL, 
            0x01FD1C95C04E9DACULL, 0xF2F9DCC6A42C5EE3ULL, 0x1578797C24B3CF82ULL, 0x9CC5F3A4BFBAFD52ULL, 
            0x5FE2C1FD00A2C6C4ULL, 0xDB9A454B425B31BAULL, 0xACBD0DFA0E7E8181ULL, 0xCF23B9D7B02AF893ULL, 
            0x227C4559FF5CC7D7ULL, 0x8C211C3A450C4F38ULL, 0xABF6F0E885496760ULL, 0xB965D6C5B2954DDEULL, 
            0x426D1DAFB34AF22FULL, 0xB3DEB45999C93A97ULL, 0x21A4825E238E0A9FULL, 0x836547B792F0E850ULL
        },
        {
            0xFCD86F9E5049823AULL, 0x1625CD47A1E6D83BULL, 0x898BA56CFED61BDAULL, 0xB6B16D4E80E2AB0FULL, 
            0x8A0133614E66F674ULL, 0x7C1D95F8C8C3619EULL, 0xC83940A0EDB44289ULL, 0xCB5947E830E342AAULL, 
            0x841532B7A0861F0DULL, 0x0486C9E7A8E0A65FULL, 0x2FA1CD67489B6D4FULL, 0xBD5E41199784F107ULL, 
            0x801E9EB2E8376706ULL, 0x165EF58446156B57ULL, 0x299FBE9B53400E98ULL, 0xE6189B10EB64673CULL, 
            0xA01465D87EE8D088ULL, 0x97F1DC093131227EULL, 0x9DAD580AD1996A62ULL, 0x5F8C4754C1C016FBULL, 
            0xF5B92ABA608648A3ULL, 0xBA97073EB078A194ULL, 0x18947675FD334925ULL, 0x71C4E7EF60CF0387ULL, 
            0xEAC0FB7D4A89B1DDULL, 0xF6C574F015529D9AULL, 0x443C0AA6532E57BAULL, 0xADA458B75ACCD332ULL, 
            0x4BEA508C81D9C394ULL, 0xD93821FF18D0651DULL, 0x667EA6BACAD231A8ULL, 0x03ED9D7054FF1778ULL
        },
        {
            0x687EA4517D2D49E2ULL, 0x864D4DCF177146F4ULL, 0x17DDB0FC37E058B5ULL, 0x69598D29618E4FFCULL, 
            0x18759F91F4FF0C59ULL, 0x68237A4DE1AD8E56ULL, 0xDE24F5D692D7ECF3ULL, 0x775310B2A4829723ULL, 
            0x2ACDDAC151239F9EULL, 0x973507949D2214DEULL, 0xCD7AF1A786C4EDC1ULL, 0xA401B17D0B214114ULL, 
            0xC4722B180FA8CC3EULL, 0x354BAF1826CE1453ULL, 0xFAE242613B626BC6ULL, 0x7E6012D199189B74ULL, 
            0x1CF7A4B8560A8282ULL, 0x23F85CC80A42D0D8ULL, 0xD421BD9495359FB3ULL, 0x97A6F926DE78F31CULL, 
            0x12DAC7D9467C132FULL, 0x8106FB3FCC0EB99CULL, 0x4BAEB115D0CAC478ULL, 0x651BC8A31C679B4BULL, 
            0xA07505995466F929ULL, 0x923A7C322FE6131FULL, 0x38886FE325A3DB07ULL, 0xBC7F547DB815E8BFULL, 
            0x023223BF8AA13EA1ULL, 0xBBDA5641C7033D6EULL, 0x8A9641BEB5F94EBDULL, 0x35D6C2FD2B82BED4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseBConstants = {
    0xF794DCE54E2330AAULL,
    0x5DCDEBB4F749EB5BULL,
    0x2E90CFE23672B72FULL,
    0xF794DCE54E2330AAULL,
    0x5DCDEBB4F749EB5BULL,
    0x2E90CFE23672B72FULL,
    0xA97EBDB9DCA0AF66ULL,
    0x0F942B4F23F90C40ULL,
    0x7A,
    0x6F,
    0xAC,
    0x65,
    0x2D,
    0x84,
    0x1C,
    0x7F
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseCSalts = {
    {
        {
            0x5402935CB08131EEULL, 0x1BAE9FEC9BF7C7E7ULL, 0xEDE35A287C040105ULL, 0xE893B7B7483B8178ULL, 
            0x9D23D8B1D2BE3459ULL, 0xE688D51BFC3512D5ULL, 0x968817320CF6AD37ULL, 0xE1785E8DC052329AULL, 
            0x569C9997E4280C8CULL, 0xE4F35A8FC4B35F47ULL, 0x717D3985F22323E5ULL, 0x5BDD1D0AE0B26D9EULL, 
            0x1C15804F830D416BULL, 0x3D312608ED4F4136ULL, 0x73C3B46357B0A1BCULL, 0x94B9F722F5592447ULL, 
            0xD980EAF1126FB6B9ULL, 0xCF49625126B23336ULL, 0x4B5F619D04307DE8ULL, 0x04F5B072A0BFB4C1ULL, 
            0x3D51EEC823F15FD2ULL, 0x2A889BC53CB747B4ULL, 0x935DBC9FE5E0C615ULL, 0x772360409B61FB1BULL, 
            0xA4AF37594E0F8AB3ULL, 0xC687134BDB32AA6AULL, 0x8C0D0E06DDBDF370ULL, 0x3366CFB048C8A3ABULL, 
            0x431D2C74DD02FB74ULL, 0x5706E73C69FE6EDCULL, 0xA9E68BB300C8D790ULL, 0x83796807BEEFC519ULL
        },
        {
            0x9DA60ECBE6D908C8ULL, 0xB9D54B46F4EF271EULL, 0xCC46C10D10B04558ULL, 0xAFFF720C86516372ULL, 
            0x1B7DA04DB5E74494ULL, 0xDC42C99519FFA939ULL, 0x4F36529F7431321FULL, 0xCBAB657A7FEC46F1ULL, 
            0x24910E9814FC7DE9ULL, 0x1A4ACDF7E9F33B84ULL, 0x35CC5FBECF71E595ULL, 0x35AF175B4B345FEDULL, 
            0x177B0DB9990416A1ULL, 0x2AA04BBC9E830F6EULL, 0xD04E4882B024271AULL, 0xC173AD1C54CE2FF8ULL, 
            0xEF2734E6EE91D07BULL, 0x4D53DB92275A7911ULL, 0x007A7F0822902ECFULL, 0xDCBA6F13E8834563ULL, 
            0x7AD9F753D4139E1EULL, 0x7857C05C71E99A88ULL, 0xCE92649F010A9781ULL, 0x95EAB6B398F1FCBBULL, 
            0xC05CC5EEA10B6BCEULL, 0xF8D07D553521A304ULL, 0x939D6C60ED2C0BB2ULL, 0x24638C342298A66BULL, 
            0x5C36BF7876429084ULL, 0x17A2F443EC381AEEULL, 0x8020C513B0751279ULL, 0x11F2786729BEC3F4ULL
        },
        {
            0x0286E8A6EDBC1EC9ULL, 0xDD4A5A56967F8E6EULL, 0x245ECB0E9E23CAE5ULL, 0x27963B25688F2A03ULL, 
            0xF426075189D0D1C6ULL, 0x7A39D1DF5EBDD4FBULL, 0x868A8B1A7AF6DE31ULL, 0xD3FFA61F31A7A774ULL, 
            0x9C6817B44B477F81ULL, 0xF9C483544AAD47F6ULL, 0x0BF8913893D0CB98ULL, 0xC27111ED6559639CULL, 
            0xBBAF680820DDCE1BULL, 0xF4FCAFE7A242FB81ULL, 0x9D6BC8614654E248ULL, 0x3F3BB0C092A2DD28ULL, 
            0xF2A69E9000048DD3ULL, 0xC625141FF4FCEBB1ULL, 0xDEC7D2824462135CULL, 0x7B8BA1B6802954E4ULL, 
            0xEC041C51259FADC0ULL, 0x956BF2743C1BF795ULL, 0xADD27A1E0B43AB2DULL, 0xE6FBA8C522BE863CULL, 
            0x0813EC942304A959ULL, 0x0E751915908FC55CULL, 0x4B950C54007BFD7FULL, 0x704D690F3417A0F2ULL, 
            0xCB94B4A3C129B640ULL, 0xCEB775636CBEC253ULL, 0x6ED2AF26FE587D4AULL, 0xEA8E9AF79240CB09ULL
        },
        {
            0xBA6CEBAE761083D8ULL, 0xBAAF671673438595ULL, 0x3C4E13F6B53B860CULL, 0x104D4645E0D68DE2ULL, 
            0x8D2578A7B63E1AABULL, 0xA22A49A7626249DFULL, 0xE18547EEE399B8FBULL, 0xCD354802E62B8AD1ULL, 
            0xCF7446AEC405FDD0ULL, 0xABCCC09A31D700E3ULL, 0xB5DB9E0B7CF77E23ULL, 0x1D8D765E917A2490ULL, 
            0x0FA42C1D3954B588ULL, 0x8C63E811EF245305ULL, 0xB6AFF7FE91B2E251ULL, 0x7E0689BA2361E86EULL, 
            0x7BBDC759739F8CC7ULL, 0x8258C43ABA78F854ULL, 0x371827E3C38B2B7DULL, 0x0F2FD915B3FDD525ULL, 
            0xD842C6A299E04B6EULL, 0x900E6EC8BD55C47CULL, 0xC179BE4F3F4BFEFCULL, 0x424DCEE51DD4FB33ULL, 
            0x42E6CC2B13F5E08DULL, 0xA17D9407EDDA73B8ULL, 0xAF1D9C91CCC6843EULL, 0x5B5C39018F06D5FDULL, 
            0xC333A0BBFCF50EC7ULL, 0x27313A5CBF439F12ULL, 0x9BF3F991E2EE60E7ULL, 0x6C9C0DB08FBE976BULL
        },
        {
            0x3CD781EA56B7F7FDULL, 0x393AF99F9BA2EECCULL, 0x78D7D0152D004406ULL, 0x8C4D8B5B668A21FEULL, 
            0xC5C452F4D3E468C1ULL, 0x56E6DC6D4AA3E320ULL, 0x0FF9FE522069D5FCULL, 0x8249D350FB9AEE13ULL, 
            0xC9CF741C4AA588A1ULL, 0x3CBF9C031DDEE1F2ULL, 0xB1F1EF4E4E6F7DBBULL, 0xA3399F29B7F07BD1ULL, 
            0x07AB3AB174CBB282ULL, 0x7F2A138F65A4931FULL, 0x40531581A016E803ULL, 0xAE7DE261BDA12EEFULL, 
            0x3B746AE59F3A197CULL, 0xCF74E90AC75C6E5EULL, 0xF295D64DA3A4DECDULL, 0xD12D4C141DD8DF8AULL, 
            0x350BE153A0E62B0BULL, 0xC3245248DE97EDD0ULL, 0xBF4E3E5F7738AD4BULL, 0x86F26B0784C19BC0ULL, 
            0x4D234745DFBB7852ULL, 0xB01A836C5CA4412AULL, 0xAF97D7FFBE952737ULL, 0x61B1EB20E6FBEEDAULL, 
            0x41CA90A5424F5C40ULL, 0x94835809477F67AAULL, 0xF878016957084296ULL, 0xF606899FB89ECC8CULL
        },
        {
            0x8907DBB773C28006ULL, 0xF6831FE6DE48FA34ULL, 0x1689245E986EE668ULL, 0xE57156EE919A84A6ULL, 
            0x8A3C762A5C445919ULL, 0xA4EDDB97DABEA6E7ULL, 0xA4798C0092652ECEULL, 0x3395E8ED3E4F1888ULL, 
            0x3A744245F6CD6BA7ULL, 0x57D2816A2C19E191ULL, 0x76100E2F3D146236ULL, 0xB11F4C8B03270759ULL, 
            0x0822E1241C4CE679ULL, 0x6ADD89ABA9BE99C9ULL, 0x1119C1B25FBF60F1ULL, 0xAFDD6603358A84E5ULL, 
            0x1CCC8E20DB5F144FULL, 0xBCA22EA47DBBC86FULL, 0xC32E621832B1E161ULL, 0x298D7FBB057BCC86ULL, 
            0x12889F0DCD373A9DULL, 0x4BEDEAF78640DE14ULL, 0x91EB7D5B5C8CB11EULL, 0x726AEC5DFB57990CULL, 
            0x11559ACC017BFF63ULL, 0x17A00C41F04E37DBULL, 0x34DE673D806F6B48ULL, 0x015BD870D9424E54ULL, 
            0xE24F0DBC5BC9A3D8ULL, 0x05A51860D74F3647ULL, 0x1FD53AC29F111E1CULL, 0xF72FD61F6C2AE79BULL
        }
    },
    {
        {
            0x9D73A4A3A2B8A866ULL, 0x86BCD6A87B485F8EULL, 0x442C74958AC03764ULL, 0x028F695DF72F173FULL, 
            0x34243A9CB9BA37FCULL, 0xF98003E50A20C70FULL, 0xFE9B04032D956859ULL, 0x079700A85DB3A163ULL, 
            0xB7551E296D4F3008ULL, 0x30A528430007661FULL, 0x3FC99CA8E27233C7ULL, 0xF06572D4117FCED4ULL, 
            0x4525115E367914EFULL, 0x6A56E0F94C30D270ULL, 0x4ADAFC426A20F83FULL, 0xF2E3725D208B55A2ULL, 
            0xE163A9FD69694511ULL, 0x675AC0F0EAAC3BC5ULL, 0x5CDDA25BB581B1A4ULL, 0x36ABC1E753FFA29AULL, 
            0xC6090C1EC941FBC0ULL, 0xAE222A09187DEA47ULL, 0x9C732959E74DE1E2ULL, 0x3A15CDA5383AE58AULL, 
            0xBD052F134C7CF42BULL, 0x036C3FE93D4EFF44ULL, 0x5B7BA60ACA8600C5ULL, 0xAD733CEA5BC60B47ULL, 
            0xA32422120D6328B9ULL, 0xF694EE2D62E09902ULL, 0x705F17A333E0992EULL, 0x7A1473D2BA0B2789ULL
        },
        {
            0x1D83A9BD318A1926ULL, 0x41CA0DD4180EF7BCULL, 0x574BA9C9F6FEA31AULL, 0x8B22E450035DAFC9ULL, 
            0xB0EB01BCDFD1B277ULL, 0x796D848CD8F74CDFULL, 0xAE4109943C1F2D1CULL, 0x80B0B4696D238025ULL, 
            0xE9F5EF551311012BULL, 0x07A60DFA04828C2DULL, 0xB11166055A7B252AULL, 0xBEA9A10C97F18F52ULL, 
            0xB2CC1F2614993FF1ULL, 0x5FF58CE1A82BB822ULL, 0x5BF9C81580DBB489ULL, 0x334D0A0525D13D84ULL, 
            0xECD1C4FDD26FACBEULL, 0x8A4736DDB04DE3F4ULL, 0xBBB2E527EAACC96DULL, 0x236405BDDECE0AB9ULL, 
            0xC5C561D9A02D0C90ULL, 0x7857140622C020F7ULL, 0x1943BE70D5F51C66ULL, 0x86942F99198B17FBULL, 
            0xC7181A91894D6BF9ULL, 0xAF081588EC7699DAULL, 0x25E4E335446E943CULL, 0xC7EBC689DD14D2E0ULL, 
            0x1272FDCDEDAC92E4ULL, 0x0CF3D8DB832DEB60ULL, 0xB5BB409730AAC68BULL, 0xFBB7C9A53104BC6BULL
        },
        {
            0x4C57CE98363FBC76ULL, 0x331FCC301C44CB87ULL, 0x7E58CC5B56630C99ULL, 0xCC18F3C28B4E637FULL, 
            0x592B8B6F95F084EAULL, 0xEFFE736D3415DD80ULL, 0x639A7FD8ED9C6BFCULL, 0x84192CE1B15A29C7ULL, 
            0x9553545F4FC3009DULL, 0x5DF19EBD45302398ULL, 0xE1B3C6E16C69D3A2ULL, 0x7F96868FD5CA5A82ULL, 
            0xD719D2BA0B116B08ULL, 0x4EE9546BD9B4CABCULL, 0x29A96CA30D9F02DFULL, 0x386760B7B19E4542ULL, 
            0x5D70E2ECA2BF67F9ULL, 0x32156C3B6DF6849AULL, 0x84E1BFF2DAA5671AULL, 0x5DE70AC68D325DE0ULL, 
            0x86183409F5AD738CULL, 0x6BC85A1CD872BC95ULL, 0x58BC0F4E53D3FBD5ULL, 0xC3C33B1CB3977F93ULL, 
            0xB1314FA7403B0844ULL, 0xB92AA12DD5C5AF16ULL, 0x76D8FC891E85CCCBULL, 0xF182A1344E6FC3C6ULL, 
            0x73DA3C56B812909FULL, 0xCE7D4D8B0298FA09ULL, 0x5B500A088C4480DAULL, 0x269436CFC9221424ULL
        },
        {
            0xDB83413A0C810702ULL, 0xC18A4A4C87824948ULL, 0x5344F26FFF86C36FULL, 0x3D03038FCB96311AULL, 
            0x30C38EEBD1190CF1ULL, 0x66907A86B9FB99FEULL, 0xB3E177D3A05C126CULL, 0x9FC904D6D94C2BF4ULL, 
            0x5989F939D4C5A000ULL, 0xF7A67D821C90D6C9ULL, 0x3FAC3AB4035B7283ULL, 0x488C048A7A29EAF4ULL, 
            0x00F6A85776DF39ECULL, 0x6E927EC3370A6CBEULL, 0x1C126D7D3CB39277ULL, 0x9B8DF7102AAFBAB9ULL, 
            0x50E0A3468EECA9C1ULL, 0xC72A0A5A0BBA029FULL, 0x589FE314F6F612D8ULL, 0xA0219D489315E872ULL, 
            0xB84531A7712CA165ULL, 0x81559FDE18EC5BBCULL, 0x8CC42B5881887BCDULL, 0x8ECDC709489880BAULL, 
            0xD3B2490FBE92FCD1ULL, 0x23FB3CFA3A0C3D26ULL, 0x1C754F53A6A10189ULL, 0x994B1AC169B0DF32ULL, 
            0x025BA87C05B8D65CULL, 0xC214442FC2F76FC3ULL, 0x7EB0798F677CA5DDULL, 0x33B197F5B9BB6B94ULL
        },
        {
            0xB23BACEFD21AEDA8ULL, 0x1484D872374C2B0EULL, 0xA6F8D4924C370DF4ULL, 0xF9775E40702C006CULL, 
            0x154A7E6E8677E57CULL, 0xB73611026E6EDDB4ULL, 0xFCB0F836EAC97B81ULL, 0xFBE5B15E3B20F898ULL, 
            0x7DBDED9E894B7437ULL, 0x5F2D85F6604A245EULL, 0x1D8E7312A87E9606ULL, 0x5574EF5C01E55F88ULL, 
            0xB107FEAE894015CFULL, 0x7C5A37B414120AC8ULL, 0x2CE140561984EB79ULL, 0x43116F56450EC653ULL, 
            0xFE7E8488DD978879ULL, 0xE0D74719F3A90EC2ULL, 0x99578B8E62BEB35CULL, 0x2B68F1D611D7A1E0ULL, 
            0x63FC848D05ADCA5AULL, 0x6EA372345F078159ULL, 0xB75C62F44DBBB50AULL, 0x6C9074A040D2221FULL, 
            0xD6D2F4FD479E224EULL, 0x7C9D6D2FE92FB124ULL, 0x9D32D626DE6F5A6FULL, 0x1B604B5AADC3D716ULL, 
            0x5B501A5CA66B2A0FULL, 0xFEF35DE68BB0E4BEULL, 0x1B33BD29C2817BDEULL, 0x8F87A4CC28D9DA71ULL
        },
        {
            0x1CB6FE2873E579FAULL, 0xA8DFFAEAC134E8F8ULL, 0x10438FB8876D3509ULL, 0xAEB3179D42760BA2ULL, 
            0x768F9ADE7298E6CAULL, 0x92BCD3D4C726E5F4ULL, 0x07934B8CF58AAA27ULL, 0x9381C8E43C258294ULL, 
            0xD0733CD931C00FCEULL, 0x704B4A70C0C91440ULL, 0xCD00AB36B43F254AULL, 0x926FB3EB515D84C9ULL, 
            0x2AEAD51C22F70DD5ULL, 0x7852C39D2A0095B1ULL, 0x7361FB23578EA6FAULL, 0xE74839CFA19B59E2ULL, 
            0x1283BE433C773D0CULL, 0xF23F29355851AF74ULL, 0xDEC79951BCD1C0B9ULL, 0xD83B81D38A851EB4ULL, 
            0x5D71B5E1AE76E64FULL, 0xEAF5FC3B5807448EULL, 0x4269F3712EF1F9A4ULL, 0x8B4F627F617F7F59ULL, 
            0x71A1DDE7E8444E57ULL, 0x6B786E0050BC79D0ULL, 0xB678FC413D2EC48EULL, 0xC80BE42C1ABECA22ULL, 
            0xDD5DCE66F3399053ULL, 0xA0DB1CC8F862A928ULL, 0x40242A7B59E4D644ULL, 0xE5488834E8101B9EULL
        }
    },
    {
        {
            0x7D70C84D004A657BULL, 0xB08D723FC1B69827ULL, 0x1D486B4D6F283E92ULL, 0x01E5953DD908F8EDULL, 
            0x2393EBD94F6C0779ULL, 0xD795848922F052EAULL, 0x07D6D9D29609E9A2ULL, 0x0C5597CE2FD547F4ULL, 
            0x20AC5CC189936F7DULL, 0xCE4F7EF46FBE7EBDULL, 0x24D76F627574A199ULL, 0xE11632322E515399ULL, 
            0x1BB7A412F6E5A79DULL, 0x183D958CA49EC15DULL, 0xFBC694B6DE82D2FCULL, 0x88DB8D2E5B6D9555ULL, 
            0x1135555335CFAAEBULL, 0xC5C3142F4F04D710ULL, 0x170F00B21AD11E99ULL, 0x89EFC470AAA825F8ULL, 
            0x2F25C9994A4756DFULL, 0x8AACD3E43F86B2D1ULL, 0x893265CB29EF7D4FULL, 0xC8309C988E4B8EA6ULL, 
            0x651C56CEEFBB1848ULL, 0x8C1D7625CB9E8300ULL, 0xC2791A29FD98404FULL, 0x8E2E322A0BDD6DEAULL, 
            0xE29F7EB19FD56C81ULL, 0xD4FF0A8A5AA988E7ULL, 0x5010873801AFB050ULL, 0x50D9B87C7148843EULL
        },
        {
            0x711E200E1C292290ULL, 0x89B6ACDC3A7ABBB7ULL, 0xC8D2F8E1DAC0DE7AULL, 0x3A30D8D169296934ULL, 
            0x03AA33E9D6E0C861ULL, 0xB1639F7E65CB0058ULL, 0xFD8ABEB6E0EA4B8CULL, 0x712C00B9250BF836ULL, 
            0xD27E25AF9B2B6D99ULL, 0x108DFF0DDFE6217DULL, 0x6187BF9F4AFCA848ULL, 0x0336C10424081C40ULL, 
            0x939FF23027948101ULL, 0xBF627055B3776ABAULL, 0x7CAF2560AB0C575EULL, 0xA34895CFAA83D66FULL, 
            0xEAD88AB771151A5EULL, 0x95D71DFB399D62D3ULL, 0xB863BB4004802269ULL, 0x706B6CB5DF74CAF4ULL, 
            0xD594191B8DF82824ULL, 0x76A3BB539056516FULL, 0xCFC211B14B02778AULL, 0xBBE8F5D0FB84A638ULL, 
            0x16667DB9CD58123BULL, 0xD925C943877359ADULL, 0xAD7A2CD310DF2B49ULL, 0x4D19CDD062A8336EULL, 
            0x9F1ADDA695FAC615ULL, 0x551D8D76E51AE0A7ULL, 0x6DB7BD443B2F1FA0ULL, 0x498A780A3EA98CF3ULL
        },
        {
            0x2B94340FE2BDFE37ULL, 0xE5D796B5538BD015ULL, 0xF02F8D1B03C1F907ULL, 0x8304197B18053B94ULL, 
            0xDB645BC83C3155D5ULL, 0xBDE5929D2F0D63D2ULL, 0x9973DD3FCC7185D3ULL, 0xD9FD858430EB7A83ULL, 
            0x0252E4FB9F3E8CC5ULL, 0xFAE76CCD807EED29ULL, 0x011B0839957678E4ULL, 0xB2642A4337D26A54ULL, 
            0xF67890708F263CB0ULL, 0x1342E29FF89AC288ULL, 0x6152EF3D9EA3B173ULL, 0x659D989B55B15F87ULL, 
            0x63B2F8389AB7B3F4ULL, 0x8AF0D3B14F23728FULL, 0x4C0923C762D91CCBULL, 0x87740A4FADB79F4FULL, 
            0x54B4BAEEC7D1FB94ULL, 0x29D89D3E80AEF259ULL, 0x30317C687A0A94CAULL, 0xD2A7354FAF33DF37ULL, 
            0x746EEDA178D538FBULL, 0xE6739CC939DA3353ULL, 0x89598A11FA1A644CULL, 0xED0BC0B2A43E9F9EULL, 
            0xE3D104367E8EBD51ULL, 0xC17BCF7701E6E1A6ULL, 0x46128159C07B0080ULL, 0xD772280EC4FC6B4AULL
        },
        {
            0xA628E783FAA77475ULL, 0xB5B6283E5BA215FDULL, 0xCE8AF9CBF7015B61ULL, 0x2260A29F5E264086ULL, 
            0x0E1DAC214D0B54B6ULL, 0x80EF17F245A6426EULL, 0x272985AD89745D3DULL, 0xC9883848B18A6AEBULL, 
            0xE0650A437882F9D7ULL, 0x6A6E451FF16259E5ULL, 0xB37DDE47F2C383DEULL, 0x5352FDC1D85282A9ULL, 
            0xE62FFD3F44C2B9A8ULL, 0x04B0A4536B9D3123ULL, 0x6A169683D10F0C47ULL, 0xF9565979A442E652ULL, 
            0xD7F8962A893A945AULL, 0xF95B5E53465737F0ULL, 0xC6363CAF082C6DC2ULL, 0x22DE6D977CC2D3EFULL, 
            0x130177626758705FULL, 0x53953FFF2905B8F4ULL, 0x911441A68B344941ULL, 0x41944A93845A919FULL, 
            0x53E2A200E67C6064ULL, 0x4C1C878D9912351DULL, 0x4FC5FC8BE1EBB703ULL, 0x1658B74C55ABC065ULL, 
            0x96FC88D3026FF285ULL, 0x53518CEF5F51CA27ULL, 0xD1784AE755DE81D6ULL, 0x74D87C3E4878B345ULL
        },
        {
            0xAE6D0247FC5443D5ULL, 0xC363FD825FF1086FULL, 0x0387828FF478363EULL, 0x10DF4071723B901DULL, 
            0x1980CD8C3A363B02ULL, 0x2F9BEF80B706F6C7ULL, 0x334A3A60FEA82437ULL, 0x2274A6FD0194887BULL, 
            0x8AD1B97453632D7AULL, 0xC53192CFBFB1AE6EULL, 0x4BA2D18B40A16526ULL, 0xA1D8441C1970065AULL, 
            0x7624774CE353428CULL, 0xDE59CAED53A44CB1ULL, 0x298DC6E87DC6E415ULL, 0x895B743B58BCB61BULL, 
            0xC44EB12483E6FEEEULL, 0x46EF169968CA2C24ULL, 0xA84D46599F826D79ULL, 0x4546DFEF6FF81A6FULL, 
            0x25638FB546AD4E90ULL, 0x344310063DA6D86CULL, 0x5109F026471B3774ULL, 0xD0A07288EA4281ACULL, 
            0x060C4BF1FF9EC55DULL, 0xB91E5EEE1DC47608ULL, 0xBBB357F971E392FAULL, 0x16098DAB85996CBEULL, 
            0xC2B0FA19E5E1AE38ULL, 0x5377F21D84F2ADB2ULL, 0x860A7572ACF320FCULL, 0x9DA7D4303FDB1FA4ULL
        },
        {
            0xED0A7E63036B347DULL, 0xD15734C7975A9A52ULL, 0xC8E7FF508D490B1CULL, 0x1D03C4858A8CBE79ULL, 
            0x011415F3E7BACF76ULL, 0x41291D4C83061F3BULL, 0x59A7C0F0B6562E73ULL, 0xF708DC709E81BB2FULL, 
            0x8E95AD00B7AA8385ULL, 0x5C6991FD0017A0C6ULL, 0xF00F0009003244D4ULL, 0xB78E67F036BEDC8EULL, 
            0x5955EA3740BB7A3FULL, 0x29037E280F535229ULL, 0xD1E3820C9BE9BC49ULL, 0xA68BE40A880DD166ULL, 
            0xBD65E2F3F2C38BEFULL, 0xDE2BDD071CC0EA58ULL, 0x552402C778985B9DULL, 0xDD696BF3A9CEC6A0ULL, 
            0x706B7F1D2229D767ULL, 0x6856B76D60B38C82ULL, 0x70D2CBAB9D3F530FULL, 0x23DF663009D73143ULL, 
            0x65251752E6CDA922ULL, 0x9CDED2B368F92D40ULL, 0xB37A64F481F75869ULL, 0xA867D4C319F527F1ULL, 
            0x1318A911D18D847EULL, 0x1C2C2203A7610F23ULL, 0x46AD4421585F6EB2ULL, 0x22AC2967D1473719ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseCConstants = {
    0x0292712894DBC5DEULL,
    0x865C9D1E070AEDECULL,
    0x5C2E28ADD7C7433AULL,
    0x0292712894DBC5DEULL,
    0x865C9D1E070AEDECULL,
    0x5C2E28ADD7C7433AULL,
    0x43F0D067A8BC2315ULL,
    0x74D2C0EBDB2BD72DULL,
    0xC4,
    0xCA,
    0x98,
    0x6C,
    0x5E,
    0xDD,
    0xF1,
    0x48
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseDSalts = {
    {
        {
            0x16F58ED4F3B27D3AULL, 0xFAE6F035AEA8C015ULL, 0xE903F760331332A7ULL, 0x5595FAEAA8D1577CULL, 
            0xF6714ED8A4AFCBA9ULL, 0x4E84864CF8C8D117ULL, 0xAA00B5F0D1E81824ULL, 0xEE16CFE621498D28ULL, 
            0x8E31901BBB73EBEAULL, 0xCCC31543CF9CFE45ULL, 0x45C6574D175B070CULL, 0x337166932C16BC50ULL, 
            0x559854E192698A1FULL, 0x243DABB8CFB2AEB7ULL, 0x0117A3D0095B67C4ULL, 0xDB80E7F7D4E9696EULL, 
            0xE6EBE85D4D08851AULL, 0x2AD5A1A74EC27ACFULL, 0x1440F459AD4C0422ULL, 0x4A85C6DB6634F0B5ULL, 
            0xB9452098860715C8ULL, 0x7D8E21FA68C79FE3ULL, 0xC0C1E2CA0590A213ULL, 0x73CF38284BDF3561ULL, 
            0x8E9D2E0248DCBCA1ULL, 0x22C47270FD4E272EULL, 0x7F56237C9CC7C1A2ULL, 0x776BDB1A1C9B0107ULL, 
            0x2D0F1525B6F54685ULL, 0xD6DA955A862EC3CEULL, 0x18117E804770D3F4ULL, 0x66805561E290AF46ULL
        },
        {
            0xC44BDD2611B42BB9ULL, 0xE67C77A9AB42D2F3ULL, 0x049057F446C38C1BULL, 0x8665FBA69144A652ULL, 
            0x0325A2F5DCA74283ULL, 0x5A35C20CE39C7D9DULL, 0x2B301802F0619AEAULL, 0x5F6FBC8CF09E9395ULL, 
            0x0B2A4A3DCF995D1CULL, 0x76D5B2384C91E45FULL, 0x5FFDC8493F62476FULL, 0xE02027CC2F38B164ULL, 
            0xB67DF6BB552C1131ULL, 0x8CFCF3061B3F23E6ULL, 0x2E404F785F6ECCC6ULL, 0xA01DAFB6E01C7F28ULL, 
            0xDFF840A2321523CFULL, 0xBC727C9FB25E09A6ULL, 0x88B17AD1DB7AA08FULL, 0xDB18552A9D414FA2ULL, 
            0xC17CFF2040531A35ULL, 0x3542BC1C1830EC6FULL, 0xF5D8E6BAC5624EAEULL, 0x14002A1B5CFCE8F5ULL, 
            0x79368A9021BEDE9CULL, 0xE481F30EF45B8022ULL, 0x90CC720521A8335BULL, 0x81176A71B9BEB1E8ULL, 
            0xAC914A62EB8E9BE4ULL, 0xE081C85B68A0BA3CULL, 0xCA22E9C00E092B2AULL, 0x16B6E59404644BB0ULL
        },
        {
            0x9642EE137402EAE8ULL, 0x720286D82378783EULL, 0xCD3627BED1C500A0ULL, 0xDC6280767BE6D604ULL, 
            0xD4711C05FA44FB68ULL, 0x2DFF71AACCC51549ULL, 0xA0F9D4EFE7863732ULL, 0xE73D9829B58FCAADULL, 
            0x425EB9A93D7155ACULL, 0x94CA37B56227CD47ULL, 0x425F4950D42AFE86ULL, 0x6C9F619725324C17ULL, 
            0xF2CCE54F106C9DBDULL, 0x671A63A20BC8A976ULL, 0x580B488C24C822F3ULL, 0xE0251F165CC7223CULL, 
            0xACBDD896221A6943ULL, 0xBA41F1AE60EABBF7ULL, 0x6CB5CE67CC9457ECULL, 0x3C9D65C549FA7E23ULL, 
            0x5B0EE47986383755ULL, 0x70D500D041CB6FF3ULL, 0x32477A684C5C70CEULL, 0xBF59D069FCF873BCULL, 
            0x3F2A9C3C96BE9634ULL, 0xC0DCA9341F443210ULL, 0x2C7980618E169A7AULL, 0xD31DB32569FD50E2ULL, 
            0xDFA3408AAFCFD6F8ULL, 0xE3CB32312D1CFFBAULL, 0xD129374CDE4A6338ULL, 0x269B1F52F902B3EDULL
        },
        {
            0x228E91939258A4B6ULL, 0x2BA5B2807FEEBADDULL, 0x5658DB226DED999FULL, 0x874DE2F772C6FA48ULL, 
            0xE33FE6CD09F59225ULL, 0xBB3DDF96D61CC2D0ULL, 0x0D9C0E084793CECEULL, 0xD3FD16D77A71E02BULL, 
            0xA833A76EAAE374E2ULL, 0x0970735880B2493BULL, 0xA14BD0D6C1D69E2EULL, 0x2480C1ADBB216E8AULL, 
            0xBBF26D16A2ADC4F2ULL, 0x728DBD0469B52D01ULL, 0x26073E2A201D61F3ULL, 0x31DF3F2EAF1B4411ULL, 
            0xE9F337B085DC75DDULL, 0xCAAA5D669693DCCFULL, 0x975156DEEA0E6840ULL, 0xD6FB745080B33718ULL, 
            0xF4E62E0C0C0AE310ULL, 0x289D2B5C22C6E589ULL, 0x026381BDB7852477ULL, 0xE9A066AC7336B8B2ULL, 
            0xEE64EF7DEEA6A389ULL, 0x102B667E40905C28ULL, 0xAC1986CE2AEAFFB6ULL, 0xD8BCFCF1A71BE27DULL, 
            0x76B9F09E04922CBBULL, 0x33E90D7CC697868CULL, 0x1BDE45F2472C6D97ULL, 0xEACD101794C37170ULL
        },
        {
            0x86C92F6C35321185ULL, 0x83789591ACF984FEULL, 0x299CFD0A98F19B19ULL, 0x20E64C4097C61F86ULL, 
            0x6ADAD222D2647288ULL, 0xE6AFDF2ADB41A7D5ULL, 0xE3C53FB6FEE239EEULL, 0xF55A649DE9216285ULL, 
            0x4375BDC849C85CC8ULL, 0x98E01D128E4DA46AULL, 0x6DC739CCE57D9571ULL, 0xE894873BEFC71A38ULL, 
            0x3BD4B0EF1DBAFDBDULL, 0xC4D8876945EC0C7BULL, 0x64C581DF49DF1CF6ULL, 0x8B04E8278F8E19BCULL, 
            0xA8B4CA1B8265D811ULL, 0xBB92EEA3D3777E50ULL, 0x54152680436538ECULL, 0xACB8295DE387C0FEULL, 
            0x94E0809774B55403ULL, 0x3D35464537E366FAULL, 0x1F986648FB305B61ULL, 0xEB165079907B5EA4ULL, 
            0x878D3ECBA9C28172ULL, 0xF2621F3D29D9B0F5ULL, 0xDF0037EFC26E7D0AULL, 0xBBEA7408BB99AC2BULL, 
            0x2B70844AA3360ECDULL, 0x5AF90FBA8271B71EULL, 0xEAEBD2BFD2649B68ULL, 0x0C732D472E2373F5ULL
        },
        {
            0x689C12FBB82395EDULL, 0xB2E3D507548AB679ULL, 0xFAD9A11D2B384A9BULL, 0x89729163E6A9157FULL, 
            0x42F831A67192C890ULL, 0x1F6899D90D6F35B3ULL, 0x0EDC689C337155A0ULL, 0x4E09B46F665901B7ULL, 
            0x76FCCD9C7372B1EAULL, 0x8ED2F985190FC0BCULL, 0xBB4FF743BA3F4431ULL, 0xDAA3C6CD8329F268ULL, 
            0x6801E360287BB16FULL, 0x482430E414F15D83ULL, 0x7A40204EA1D53E89ULL, 0xF8AB846E9F72AE7EULL, 
            0x7E7F9970D8A637F4ULL, 0x66B4445F6DC93BC0ULL, 0xC9FA94CF3325E720ULL, 0x3EBE2CF9B51F11FAULL, 
            0x3DDB62AB2B0F4430ULL, 0x892DD8D163F8B2B9ULL, 0x2CD4C00BF3657080ULL, 0xDC79F0CFB1ACEB77ULL, 
            0x05369E32CACE189EULL, 0x4AA76E1E65C72C83ULL, 0x1194FBDEC39F12A5ULL, 0x1CCF24B4EAC46D0BULL, 
            0xE4BED5F36EBEA93AULL, 0xE96BAFC7BC95994EULL, 0xD35A39917A34EE9EULL, 0x7ED456FF9133AFCFULL
        }
    },
    {
        {
            0x448C8B684047A945ULL, 0x90352ACEA75D0EB9ULL, 0xB1E115B45F41C040ULL, 0x99FCBA7986E93AECULL, 
            0x67CE5FE1C0E749C0ULL, 0xCCD55E68F3BB6199ULL, 0x2CE5066F7A3A7747ULL, 0xF1E46C07707EAB1EULL, 
            0x77313694DB00900BULL, 0xFF23405EE98AEED1ULL, 0x7785D02504386B0CULL, 0x9B97C7887B4E7B7EULL, 
            0x3ACE1874DD678FC0ULL, 0x5B015B8CC672E7D3ULL, 0xD64920CA2B115867ULL, 0x23CD33CEEC23789CULL, 
            0xD24E8DB438DA3A00ULL, 0xB9109CEA0C98214AULL, 0xE45C27376F0584B6ULL, 0xC0678A64FB3A7B59ULL, 
            0xC6A4D3CC7A6C2881ULL, 0x28573CF017087A95ULL, 0x5487560934F9143AULL, 0x739EC66C6EC14CAAULL, 
            0x4AA581C20A9C063FULL, 0x28AAC039EE01F6E8ULL, 0xBACDA1AE95336FC8ULL, 0x8BCCEBF808092210ULL, 
            0x2DCA5DBE34986F6BULL, 0x5A2EC1B3F7710FD3ULL, 0x69444820DF965B67ULL, 0xD051071FD74F6331ULL
        },
        {
            0x824450D90FBC351BULL, 0xC582FF189B0FA39FULL, 0x0BDAEEB79DF1818DULL, 0x9BDEEE588EDA7743ULL, 
            0x433605413841402BULL, 0x041C2FEA0C86447CULL, 0x1AA013C87275EC58ULL, 0xA584FE009497A0C6ULL, 
            0xAAFEFA2C03AD36D0ULL, 0x6961603739163AE2ULL, 0x3AA8B0AB3CB66153ULL, 0x360EF1422898DDD5ULL, 
            0x2A57CF43886395D8ULL, 0x90196D74BE560D89ULL, 0xB6CD03D81041DAC7ULL, 0x59174221837FA183ULL, 
            0xB332C6833707A74AULL, 0x6F2043A4B48DA7CBULL, 0xA76F833A8CC72CF9ULL, 0xCE0594482E4807BFULL, 
            0xBEFB8D5CE15C5950ULL, 0xF68431EE2DB3CD1EULL, 0x0DD144ED1DFB9CFFULL, 0xA79EEF0A8F31BDAEULL, 
            0xB57043993D03E516ULL, 0xA15B36B2BF1EE3CAULL, 0x91D76261B446ACFAULL, 0x0812257635D4B680ULL, 
            0xA2226A9066049A76ULL, 0xF359B475234E4978ULL, 0x1A864EB420B5B538ULL, 0x0B2A528E19005B74ULL
        },
        {
            0x6D4EAF44F3BAAF77ULL, 0x3FE8F8D783B3EDDAULL, 0x1B4EDE6191DF05DCULL, 0x5C8A8ED782EF46D7ULL, 
            0xDBB07852A19DB0EDULL, 0x5B235C5C74981C6EULL, 0x4BBA454017437185ULL, 0xFB61C9091455E666ULL, 
            0xF1B27DB9EB8BDCFEULL, 0x5F7282B1BF6778B1ULL, 0xC79D43FB7AAA25C0ULL, 0x0A48D3FD952309E4ULL, 
            0xA0BCB7B1FE1C05ACULL, 0x17A4A949930E3CFAULL, 0xB749731ABA0ADDABULL, 0x0D4BEDB4BAFD4819ULL, 
            0x8D06A861D7A25FFBULL, 0xE0121DAFE77FF11CULL, 0x927C013E26C40CB5ULL, 0xFC41DAB0149B4351ULL, 
            0x6DAE928C84B61161ULL, 0x2A04D9F5FF9808FDULL, 0x95B3D59344F35F71ULL, 0xAB4C9F1BA1B2A73DULL, 
            0x185967FB89CFD807ULL, 0x690189869A7D45D1ULL, 0x47E08E9B7952A780ULL, 0x9A14396E847421E7ULL, 
            0x846D6B22C1A468B7ULL, 0xCBE0489F0300EF1FULL, 0x70840C06B42B1671ULL, 0xC7B26903E0F61580ULL
        },
        {
            0xA8DB70CB683287AFULL, 0xB0C298D7F708D853ULL, 0x15A7DC741299C5D4ULL, 0x2CB099F167C760E7ULL, 
            0x5275E3E9B5B1B389ULL, 0x35710E7907FB987EULL, 0x90399D882ACDCC8BULL, 0xB14DEC4ED6892116ULL, 
            0x09D77729C1876500ULL, 0x789FA58A58DF8F08ULL, 0xE6F260524D8152E0ULL, 0x97324F2C02173B20ULL, 
            0x5224D841C1EB31D4ULL, 0x7215ADA65C19D258ULL, 0xAEB7F2C30F122AAEULL, 0x9F8ABE68F9FC4653ULL, 
            0x53D0CB611C53640FULL, 0xB773D95C1C4C7913ULL, 0xDA6DD2B5C6550676ULL, 0xA32B6E3307977579ULL, 
            0x41AF0A61645E8767ULL, 0x3F9859A0A05FCEABULL, 0x2E7283672F5CC2D0ULL, 0x5F016F7D3C3F8DF5ULL, 
            0xD7945A4B8328F7D1ULL, 0x13BB3A7247BBC34AULL, 0xA2BB9F79C1A5DA65ULL, 0xF97B096CD39F7A43ULL, 
            0xC7BFB1EBBD836188ULL, 0xA4EF3893289F3107ULL, 0x83C88D3248166FE5ULL, 0x82A725F484FB96ACULL
        },
        {
            0x6E239171CED9AC1BULL, 0x35D31C892FFCCF49ULL, 0x749F86DD6EF3B925ULL, 0xAE7880D38A4B5CA8ULL, 
            0xE2519E175E49577CULL, 0xEB6BAAB934B2C830ULL, 0x017EB4C6E24F4593ULL, 0x2DF560EAC8C598F4ULL, 
            0xE07931547C9AED4CULL, 0xE28A2D34331C3FC2ULL, 0x4CF64A109829D370ULL, 0xE48E8087B357D522ULL, 
            0xAE48B87CE58A591FULL, 0x4D0688207D25CF2AULL, 0xA1D17561C29A481AULL, 0x8C4E9FFDAC77D2A5ULL, 
            0x8176491574C9C715ULL, 0x60D9FD0F1667A381ULL, 0x72F2F11DCA1B2E5EULL, 0xBC9FC42FCB19BE1AULL, 
            0xF385EAECA7F62C3FULL, 0xC7D9BAEE67018554ULL, 0x0C37B386EAF681A7ULL, 0xBA692BE6B8C9CFFCULL, 
            0xB3CC5A24A132C4AFULL, 0xD7652B946097BBFDULL, 0xE8EBEB5E535F87C7ULL, 0x7F0FFB46F21089C9ULL, 
            0xEE819AAB086330FBULL, 0xBA27C6BDDB81D19CULL, 0xB634FC27488632A3ULL, 0x8354D191130DA784ULL
        },
        {
            0x6B1C883155BB16EBULL, 0x5D26CB53EFFA3108ULL, 0x7CF1FE7F709C95ADULL, 0xD60ADF0E4ECE3C0FULL, 
            0x4439595D27B47654ULL, 0xB69966663532616EULL, 0x1949DD5585A44BFEULL, 0xE54F97AA9F5F04E0ULL, 
            0x5B1B9BDB41526B99ULL, 0x58EA4CA5B1B9C342ULL, 0x4DD2EA80A01FEDF1ULL, 0x76248B60DC01BA35ULL, 
            0x791BE60681F1F092ULL, 0x31B8398D908578FAULL, 0x5E2FEAB068CB9BABULL, 0x96CE9FBB6C344690ULL, 
            0xB060694DE4FDA37FULL, 0x75DD0AF136F877D9ULL, 0xDE4781E23174A47DULL, 0x4309108B09C23C8FULL, 
            0x4596BB66C5DFC19FULL, 0xCE8479FC1F0C9807ULL, 0x5D748F79D998C122ULL, 0xDC86F27009CC9C83ULL, 
            0xCAC5FE5B6B1D7A00ULL, 0x03297D082C216A3BULL, 0xC58928A7C57E34ABULL, 0x5DD00F4BA5722F50ULL, 
            0x5A9D99BFB7346889ULL, 0x27E3F5C75A939D98ULL, 0x12851EFF618FEAC2ULL, 0xEF3281F870F78FC3ULL
        }
    },
    {
        {
            0xBE41151371502B3AULL, 0xD67C42DC128BD0E0ULL, 0x475D5C1A2A51F2E7ULL, 0xC7755F1B689471FEULL, 
            0x85E3AFC1222E7230ULL, 0x3AE4511D7D55DC94ULL, 0x68BA778A9ED48F6CULL, 0xC2D90A46621F6B89ULL, 
            0x2B4CF60834BA1854ULL, 0x9C13A9921AC65C22ULL, 0x782AF3B0276611D0ULL, 0xF7E94A0669E99A14ULL, 
            0xC86D3F5F20E3874AULL, 0x57F566F549DF623CULL, 0xCD0805C518999F73ULL, 0x678DCD305C9EB4FCULL, 
            0xB6E37E33B31F9A77ULL, 0xC43514077A6F4AE6ULL, 0xA90C86F2094F02EAULL, 0x3FE7D04657A8AF02ULL, 
            0x2A9F82531D1DFEAAULL, 0x420E96F624519BEDULL, 0xE32B7178F8B4A599ULL, 0x30D7487943527BBAULL, 
            0xB47126386AF383E3ULL, 0xEB6B3B46DC92C147ULL, 0xB761AEE95793445DULL, 0x1C5EC64EA38675ABULL, 
            0xE14B565BF41EF538ULL, 0x785C9EFD045C0F81ULL, 0xBDC2A48ADDF341E0ULL, 0xC2B35C3A4C64EBE5ULL
        },
        {
            0xA03AA71187DD647BULL, 0x3D8E51FFB7BBA343ULL, 0x18B5DB03B2A5400DULL, 0xF18880A26F5789FEULL, 
            0x1CF515FB41634E5DULL, 0x08013DA4F4BAC2B4ULL, 0x723AF66078A69267ULL, 0x4B138112C565A2C6ULL, 
            0xAE9D1C4E6CEA2037ULL, 0xDF6518394CC1CE26ULL, 0x7394D3E70D7A3117ULL, 0xCD43DABAF10CB490ULL, 
            0xC2637E6EFA83EB94ULL, 0xC79CD2FCD971A7B5ULL, 0x33A5B771050C9C63ULL, 0xE14B6160EEC3FA4CULL, 
            0x4FFF2BBC0685D48CULL, 0x0D6C19FDEF1DEE5FULL, 0x38C63E08EC36447BULL, 0x41D07FF36347868BULL, 
            0xE819C834E1A09F8AULL, 0x626F0CC3F5E0868DULL, 0xFCB277BA890A9511ULL, 0x272B21338319F49DULL, 
            0xA1351ADA1AE49CB5ULL, 0xE3F6434CE2D17D2BULL, 0xD2BF36076E4B4905ULL, 0x9249965B0038BBBAULL, 
            0x0D555A620F9C3FF7ULL, 0x3A2B1EF4081CA846ULL, 0x05B7C34B0E330B68ULL, 0x16BF578223F1A525ULL
        },
        {
            0x4E8A303683C8D5C2ULL, 0xCE19DCD82C0F4F73ULL, 0x1F1C2A80CF9579A4ULL, 0xBCA98D561D7CFEF9ULL, 
            0xE21400868F69E1BAULL, 0xB74BB1BE28EED39CULL, 0x31C4C786C2119691ULL, 0x441561A9BD0C9A40ULL, 
            0x8CB75DC460925D46ULL, 0x356668F15793FB28ULL, 0xCC4C0FA91C79AA37ULL, 0x6DFB7F9307C75ED8ULL, 
            0xF63B3056803C48A2ULL, 0xD224BDC9ABBC2590ULL, 0x28D48848E6F3AA0EULL, 0x574E20730796889DULL, 
            0x5EC1C9755AF6F7C5ULL, 0x2C9411281EFEB09BULL, 0x9C6BC4E823E5135DULL, 0x783E4DCF2363833DULL, 
            0x2E63254CD8C6DE9BULL, 0xC191AD9362E3705EULL, 0x4DE4B3A1E37105DCULL, 0xE3D50011D8ADA8E6ULL, 
            0x7BDB618FEF87E7FBULL, 0x8FE27D86200EB1AEULL, 0x63778544A3EFCB48ULL, 0x5A091BC4651C60E1ULL, 
            0xFEE6B96525D36F18ULL, 0x73EECD4303786B03ULL, 0x76BF32F47FE396A2ULL, 0x743AB7FB5F64D15AULL
        },
        {
            0xC6FFC4D99CBD715FULL, 0xE8F1098BA43D9815ULL, 0x30033CDA3490D30EULL, 0x2771F7B0B177A0D8ULL, 
            0xC81BA53C1DFFE21EULL, 0x48FD4AA09D19A6B6ULL, 0x3927334A2D50FFFDULL, 0xA0A1399D9A15315DULL, 
            0xBED3E77B4523BC9FULL, 0xAF2EAD5BD0100A8BULL, 0xBA0BEC8E67D2FA4CULL, 0x22FB9F6B08188223ULL, 
            0x8C8C4C569ECA86E9ULL, 0xD61E2D2E6FD76BECULL, 0x52322325D8B6F13FULL, 0xB55A68DB69D57AD8ULL, 
            0x5763D65176950AC5ULL, 0xA6035908D5FE76DAULL, 0x97B5A931E3E08F25ULL, 0x0B8874E9E8E048D0ULL, 
            0x53B5D34E526639F7ULL, 0x6A2352F93278BDA9ULL, 0x9E1087FC98ACC1B1ULL, 0xF6F7B275C2B2CD57ULL, 
            0xE8CE507BA2F8EFCCULL, 0xB55C6A2365254D53ULL, 0x3E31045C3F807411ULL, 0x92991B2B31E5906AULL, 
            0x273A862A10C56E24ULL, 0xAFBFDAD7564AD364ULL, 0x638664CF8F64B0BFULL, 0xABD909FA25DFC7B2ULL
        },
        {
            0xD3F70610D72F2F5FULL, 0xBD6FBE0273A5D427ULL, 0xC6949E1E0E29F75CULL, 0x03484AE80A8BCF73ULL, 
            0x66EF1AEEF635CA33ULL, 0xD35B9ABFDDBDCA25ULL, 0xB08DC93F4FF563BDULL, 0xF2D9F254B7A3F5D8ULL, 
            0x7C212EDE7C60963EULL, 0x8561BBD16FD63CF3ULL, 0xFC320D169A2DEBF4ULL, 0x46763BA6402D63CBULL, 
            0xF8CE71355281B7BAULL, 0xF9AF5A5B7D608FDEULL, 0xD1C3D2CEE6B844C4ULL, 0x99D2864078A3A724ULL, 
            0x1948C1965EDC6785ULL, 0xD3030E341DEBEB8FULL, 0x63E1B1DF859308BBULL, 0x6E6850054B67863FULL, 
            0x0BD53C726878DE79ULL, 0x2648139FBCD7F58FULL, 0x1E34E0C978020F8EULL, 0xB7A7F17D2E05D8DBULL, 
            0x14E6ECC4E622AF85ULL, 0x1D664BFE2AE15B8CULL, 0x62055DC62E009C2BULL, 0x38BADB67079D1F34ULL, 
            0xD27551EAB49FE37BULL, 0x7602B3B1E5E1C55BULL, 0x6FDD695CBB450BBEULL, 0x9BD36C5272477C53ULL
        },
        {
            0xFEED0F59A92C9B84ULL, 0x1B075234DEA24686ULL, 0x298D3FCE83D115C4ULL, 0x602177F9AE4B7B95ULL, 
            0xFCA02E0C6F4B31A4ULL, 0xF1C7DD042CDD1C4EULL, 0x1C5A4AF8F863E5F0ULL, 0x5A76AAD34CA5E8D3ULL, 
            0x6E104D12DD4C1C6FULL, 0x559858A8F9A6125CULL, 0x6948542598360ABBULL, 0x1338A8B94B36E5D3ULL, 
            0xE27ED06D7C5F2960ULL, 0xE62A24FD1076C01FULL, 0xC76379C96F7F3B0AULL, 0x20C64BDD6B3926B2ULL, 
            0x7E4FEA4EF986F1BCULL, 0x8D592F45A38DFF27ULL, 0x252C93425205BF37ULL, 0x15228C583B22BBB9ULL, 
            0x72EE6F4CA07049B5ULL, 0xD110B7D2282903D4ULL, 0xEF30F3447E39E30FULL, 0x03891EAE2B14D6CBULL, 
            0x9E51D44CEAD280C2ULL, 0x93EB16C4D032AF10ULL, 0x8B6CFC8704D4E869ULL, 0xA1B04D5352C382D2ULL, 
            0x6DFEBC2D12F0348DULL, 0xB89633383FF6B0EEULL, 0x903A6CE8312C91B6ULL, 0x1C9EBD35B61AADEDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseDConstants = {
    0x5A52994192431337ULL,
    0x6B9271F5CFB990ADULL,
    0xFA84E9F3DAAA27A1ULL,
    0x5A52994192431337ULL,
    0x6B9271F5CFB990ADULL,
    0xFA84E9F3DAAA27A1ULL,
    0xE249A2BB7195078CULL,
    0x440D248B234ED017ULL,
    0x59,
    0x68,
    0x40,
    0xE8,
    0xF0,
    0xEE,
    0x98,
    0x16
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseESalts = {
    {
        {
            0x3BA0F9E4761B81C0ULL, 0xDD54542B946BAE5FULL, 0x6F75192797BDDFD3ULL, 0x760B4200AF8BAA7DULL, 
            0xB283CA3CB8DEFEA3ULL, 0xFEE07F3DA7544D64ULL, 0xDBA09CF46A2CFCF7ULL, 0x0B60D058C422681AULL, 
            0xE3CC75187C73A292ULL, 0xCFD73C0E5954332CULL, 0xD9799575400A8451ULL, 0x9BE0A6A32C4E1883ULL, 
            0xC1746D8FEB76D8A8ULL, 0xD437541AF881C478ULL, 0x17CB4AB986C85171ULL, 0x5A8A166E32B8CAF9ULL, 
            0x048578E1E27DD1B0ULL, 0xA6F5C8DB313E5BEAULL, 0xB9AB3515C5918D09ULL, 0x409B5E00F2282768ULL, 
            0x1D0483F3AA981F89ULL, 0x62C7F0F1D4BD7699ULL, 0xB5D1E33C1D405DBBULL, 0x31731E46577F9346ULL, 
            0x6B7CFF32873C6238ULL, 0xFCF4B3382F1594DEULL, 0x8868DB145AEE09BCULL, 0xA394A865853F4B63ULL, 
            0x0C311665ADF88D25ULL, 0xA096E2CF090A059CULL, 0x36A885B4C7F7BDFCULL, 0xB25D83F76D9291C5ULL
        },
        {
            0x2BDB5CD2B74F1EE4ULL, 0xAD3379C047BF15B1ULL, 0xA50F052A213CCD72ULL, 0x96F86A38318C4903ULL, 
            0x44D18FB9BD8A3B27ULL, 0x891CC9F333CD766DULL, 0x40630C8251AE4E65ULL, 0x7BE26E451058BF53ULL, 
            0x2D539FEC6DFECB5AULL, 0x7EF816EB8D09C7C6ULL, 0x157DDDD65D21E74BULL, 0x36816877FA89A92BULL, 
            0xCBE9B1D147D7484BULL, 0xF8D6596AEE4192D3ULL, 0x6DDCF0BA2569C70EULL, 0x4B46606493C08F2EULL, 
            0xB012D84EC917D114ULL, 0x6F7FE6AA3CAA9786ULL, 0x2421AE415C54AC81ULL, 0x689B187F85B42DD1ULL, 
            0x75EAFD63ACEF6FB3ULL, 0xB7F6A14985C0D1C1ULL, 0x0ACA6302ACB8F308ULL, 0xBAA23A49F5E97BEFULL, 
            0x06B8377D4421B2A4ULL, 0x253A17F8AD9AD7A6ULL, 0xEAA70CE687A8CB96ULL, 0x4147C59477C9B1C6ULL, 
            0x28234E60CF593FA3ULL, 0x33DF6F7E097E8604ULL, 0xC7D8C374306A121FULL, 0x4195ED0363E16A8EULL
        },
        {
            0xBFD0D7E2960A1F94ULL, 0xB6E37A6BB831F998ULL, 0x5DE1B71C2133AF4DULL, 0xEF83A8D8565B5602ULL, 
            0xC920EA5631ABD0AEULL, 0x0E3F23F7D897890BULL, 0xAB3DF0E07DDAF543ULL, 0x43D8F403D614EA37ULL, 
            0xB4CF9CB28C47B1C7ULL, 0x22941B067B92C281ULL, 0x03F796703DD02922ULL, 0xA2495820DE4AD64BULL, 
            0xAF385CA7CCD42DE0ULL, 0x5DDA906CD079393BULL, 0xA8C7E0079307B773ULL, 0x53429D45572F4928ULL, 
            0x28823D054ED43901ULL, 0xF05B3DC52C2CD2A4ULL, 0x560CFF3998F1A1AAULL, 0xE92013C32D947E69ULL, 
            0x2DE828F5E0170E49ULL, 0xD90183A9493E720DULL, 0x3C1105E26745382CULL, 0xDDDC61F7750F5D7DULL, 
            0xCD93A5FC075CA572ULL, 0x732110DFA8C13854ULL, 0x530C576C5C4FC25EULL, 0x56E0E3047776E717ULL, 
            0xDB11DA11968AB78CULL, 0xC4C7413C97954C69ULL, 0xEE06FAF797F85B0BULL, 0xE0F50A56F7773EF3ULL
        },
        {
            0x4F5AF83F284DB6F9ULL, 0xAFAA90DAFD341121ULL, 0xF31B40B20C761DE5ULL, 0x077C3420D5C49CF3ULL, 
            0x481A5AB19ECD690AULL, 0x74DB173410509451ULL, 0xF83A0601B5AAE037ULL, 0x08943AB6C20DB67DULL, 
            0x83C76038161802D2ULL, 0x91CF21D11AA9503BULL, 0x06B0F2308DD7A068ULL, 0x0C93C078A94B4DEDULL, 
            0x999A5C633402B1E5ULL, 0x1CB5659A656B2B26ULL, 0xB2BB4F1377AC7112ULL, 0xAD029F21A7B67EADULL, 
            0x8DAE9AFE3B271ACAULL, 0x080F62016283F8DDULL, 0xA2E3D9312E6DC871ULL, 0xC0B8DC21782FCD7CULL, 
            0x040D3F694EBA4DB1ULL, 0x259F6BE99A8D9526ULL, 0x58FC22B9B87E6AB2ULL, 0x8D1C1BB3D627F0F1ULL, 
            0x878568AC3A502476ULL, 0x8F675411A1AC9A60ULL, 0x0F0EDF9B62994684ULL, 0x96546E18562EBCE2ULL, 
            0xB86427BAF9AFB0A6ULL, 0xF4EFA1AEEFEEADABULL, 0x83B319BB9313C61FULL, 0x9E324AC6B218B44DULL
        },
        {
            0xD47EB8081B5ECCF4ULL, 0x0AF352DE34DF1A6EULL, 0x4AE57921C2E86678ULL, 0x1CA47ACBA036A4FFULL, 
            0xA81ECF5EA0E2BD4FULL, 0xF135662806582233ULL, 0xF6BCC00DFF911650ULL, 0x6BF781F84E88B195ULL, 
            0x89B4DB6DE95316D0ULL, 0xF37A10680FA8B7C6ULL, 0x05B000AE900217F8ULL, 0x452DA1AC31EDFD9DULL, 
            0x7FFCCC6D7F7536B3ULL, 0xD6E654A1375D1C8EULL, 0x08EB8292EA1D773CULL, 0x189145D4A780624DULL, 
            0x8F09114DDB6B7263ULL, 0x912BEADADDB91AABULL, 0x08C1DE743E7648E2ULL, 0xA9862112A6CBE043ULL, 
            0x882F56CF76E91CBFULL, 0x729B72BB262453FDULL, 0xE26EE359DA4C8ECFULL, 0x8C462A6806947C02ULL, 
            0xD895F79F383C2A55ULL, 0xF682613022ED1908ULL, 0xC1FA3A0841923A3DULL, 0x3A50A247EFC0D907ULL, 
            0xEADE255F303EB1A5ULL, 0x84E91BE9BAA5C616ULL, 0xE48CC49AC28B0BBEULL, 0x5060C8602677EE87ULL
        },
        {
            0xC9B20877BAB6DAF2ULL, 0x0B572164BDABA5D5ULL, 0x779140CA42F8D2CDULL, 0xB1B39EEC8CCA8509ULL, 
            0x3FAB69A3F390F382ULL, 0x05447905400F7AE2ULL, 0x75506329970EC9ECULL, 0x82F4B04FC79CB196ULL, 
            0x48A3B4A7CA69486DULL, 0x3640DC6F62D344F5ULL, 0x677F177537BFB10BULL, 0xC3F096C93F79E8CFULL, 
            0xE36ABBA670A74311ULL, 0x4770A5A7E8871712ULL, 0xF68F597A4E2D4CF7ULL, 0x6AF457466EA6B967ULL, 
            0x3400E1060DE67637ULL, 0xB90ED125141F90B5ULL, 0xCA5773D2DAFEACF4ULL, 0x23AE2D2493D28064ULL, 
            0x0B40D2110994DC5CULL, 0x19CA3CF940E6474AULL, 0x36748E60319270CCULL, 0x9C94631345D29E24ULL, 
            0x0BB5F91E1F7C0555ULL, 0x366721E6D8635A67ULL, 0x54D8FCEA641EB94AULL, 0xD4E06CB80AA69FD7ULL, 
            0xB72E10946EE5F955ULL, 0x7E23AC6AD2D10609ULL, 0x8B7676A73ED8CE00ULL, 0x360401FCA930857BULL
        }
    },
    {
        {
            0xA8D88F39211BCA83ULL, 0x8306FD1F35FDEEAAULL, 0xD644E908C30EF1B9ULL, 0xBF7B031B8C7488DFULL, 
            0xDB6C8110C6FAEFFCULL, 0xA07A57CF81AF3431ULL, 0x9196B8122380F386ULL, 0x834133C72DFBDE49ULL, 
            0x8590109169899B58ULL, 0xCB2B3A352C88F850ULL, 0x8778B7C1E8544EC5ULL, 0x8737CD9EDA89AB7EULL, 
            0x7EA5F49D1AAC3EF2ULL, 0x3A3D28CD49CC73EBULL, 0xE13FCD2EA61DE307ULL, 0x62156DBD3CB0039AULL, 
            0x0CE4A76A7DD3EC2BULL, 0x3F13FC6FA5F0FBD2ULL, 0xBDB754C80EC995BEULL, 0xD9598B5894643126ULL, 
            0xC5E8907A6DD73E89ULL, 0x9CCF8EEB1ABA256AULL, 0xCE131E02DAF2C63BULL, 0x28FBA62F9E106086ULL, 
            0x795460BDA4CC36ABULL, 0x64EAEAD4CDE77F30ULL, 0x5241D32FB5330D6EULL, 0xB9DB35DB83B621DFULL, 
            0x26DEE6F3C409BEDDULL, 0x161A08F9631C022FULL, 0xA0B6339024F5F0DDULL, 0x5273C8318D269D63ULL
        },
        {
            0x33BCF5AE721F7005ULL, 0x7F6D788F771393BAULL, 0x991F19BE0B5B4565ULL, 0x5CBD9AC599196367ULL, 
            0xC28B11E2D5BDEEECULL, 0xC829B3FA49875AA6ULL, 0xF9DA489F16117EF9ULL, 0x1C882DFCA24A02E7ULL, 
            0x1085502B706DEF82ULL, 0xCEC61D911858E53CULL, 0xAC9FFF096EF26DFBULL, 0xCE676B73C5452278ULL, 
            0x3157DE13E72C7C4BULL, 0x084A79F0F0AF0CC0ULL, 0xE25113CC2AA42C6CULL, 0x1F5F83328CBCC9CFULL, 
            0xEE37F03C01207841ULL, 0x8956C13A6691A56CULL, 0xDCCF72A16AAA58DAULL, 0x7A200864A001EE41ULL, 
            0xCFA7DE152D6CB4EBULL, 0x149CAF7C6C869BA6ULL, 0x0EAB23C53D9BB48CULL, 0x3A2B8996A259FEB9ULL, 
            0x06D040DC123DC997ULL, 0xA7C4FA3457458EC6ULL, 0xA07F90EBD85CFD4BULL, 0xEBCA7388AF8B5622ULL, 
            0x321A3DE2F16D09F5ULL, 0x6E61B550E1ED43B7ULL, 0x7C778AED3CEE3566ULL, 0x3ECB49FFE2DED167ULL
        },
        {
            0xC1A57F8C45D09480ULL, 0xD4B4B92D0E986FF5ULL, 0x39B6189205A94FBDULL, 0x32DDE4B7201F7A64ULL, 
            0x9BB5B0A19CD69E34ULL, 0x266C8C91856DF6CFULL, 0x694B6BC4D61CFE07ULL, 0x2803BD8688C71E2AULL, 
            0x25EA089AA158D28AULL, 0xBAC9849CF08E4729ULL, 0xA44B5467CFFAF2BAULL, 0x9BE70D9365D92E79ULL, 
            0x03BA0E15886FC84EULL, 0x61905E8C9D380661ULL, 0x3543BE5EB9DA20EAULL, 0xB258485F2324D686ULL, 
            0x8919A57B2173EC7DULL, 0x22326739DF4886E6ULL, 0x5FF83CCC01830FEEULL, 0xEE73A0C8CB416B5CULL, 
            0x33DFD2AB2C296390ULL, 0x7F716AB9C52BEAB5ULL, 0x368D037905D12D88ULL, 0xD9BE00247D29F418ULL, 
            0xCA4E800B327EF609ULL, 0x392ECBCB4034DD8CULL, 0xECB1C16B2FF414C0ULL, 0x7543B3CE25A84BF9ULL, 
            0xFCBA0930FC353DA8ULL, 0xCC5EC37C99ABE75DULL, 0xF2BC462AF762C891ULL, 0xC5A1AACA4495D95CULL
        },
        {
            0xCD9BFF4B84A5A2C0ULL, 0xD343DA8E71E5E25CULL, 0xE7C1E9F900656531ULL, 0x5944200E89E1F159ULL, 
            0x43D51F8631736CACULL, 0xC98463809EB220C2ULL, 0x9B9DF30DD15BE872ULL, 0xA020D38A05F81949ULL, 
            0x1E851BD18A4FB1BEULL, 0xF14CE19AF30D1213ULL, 0xC4422CA716A59C61ULL, 0x1792A4F484203543ULL, 
            0x71F790C84F09BF99ULL, 0x1790750497E67CBAULL, 0x5C31E5D1380F0F02ULL, 0xA1D6834B75EEA165ULL, 
            0x114EE67761DD4994ULL, 0xE264002DC0E9CFA7ULL, 0xE409DAAAA4285725ULL, 0xA3FEC1D44284FA77ULL, 
            0x914C8A73660D4461ULL, 0xF5784C62B245A91CULL, 0x1E4D24A2C491D9DFULL, 0x063300FFB2703C43ULL, 
            0x102C1B729499087DULL, 0x384198FA1D408B97ULL, 0xEBF586258AD38F77ULL, 0xE4714283A40CE155ULL, 
            0xBF805523EB098EFDULL, 0x2AEA06736CBD49B8ULL, 0x77BF43B23FB2FCF3ULL, 0xB6B362FB7D90BB05ULL
        },
        {
            0xD463E32BEE6E0EB1ULL, 0x163A54C604CA7C58ULL, 0x9F68756A9846683FULL, 0x3CD778938905E71BULL, 
            0x10275F1221804471ULL, 0xBDA597F22D564185ULL, 0x64D0C628F1E6BF5FULL, 0xF1E8E9BAB76E0AAAULL, 
            0x7FC0538EF821346AULL, 0x1D65E9D03DC4CC8EULL, 0x79AFDDA8483D98EAULL, 0xE5BD2946084975DDULL, 
            0x2B1390F148680F64ULL, 0x1D0027BBDAE4F074ULL, 0x44E618D25B837F65ULL, 0xD739FF1CA4C2E7C9ULL, 
            0x8A8AC25A781C9BB0ULL, 0x3DCED1D2E6A4CB5DULL, 0x00D916501A85DABDULL, 0x8E8E1470508DF22DULL, 
            0x084FDB3CE4E254C8ULL, 0x23F9AED34FF4C24AULL, 0x7F674CC8105991FAULL, 0xD5A9DAF3F8D919C4ULL, 
            0x537C602406381E3FULL, 0x2E2E778CBAA59CF0ULL, 0xB8B6E96A0E77EDADULL, 0x5E8DB93040859A78ULL, 
            0x95CA001BE6BFD8E1ULL, 0x88789655C3B7AF06ULL, 0x0707A98C6F48F202ULL, 0x28B2059AEA5C5CBEULL
        },
        {
            0x8908270FEAF31979ULL, 0x6286A306318F223EULL, 0xA372F0AE49FF2588ULL, 0x93C898B1F7DBA793ULL, 
            0x22FC84D822858288ULL, 0x0AAC1666FD75822CULL, 0x2889054240B8C7CDULL, 0x74D6AF11BBDBDB05ULL, 
            0x2F5089CD5A626A2AULL, 0x3F1B4BFEAE010084ULL, 0xBE2AAFE72719F1E9ULL, 0xCA97DA37760C9C15ULL, 
            0x85688DD13AD8EED9ULL, 0x542061B4E07568E2ULL, 0xCAB62904DF619F70ULL, 0x4CE90C06080C1798ULL, 
            0xAF6A2AD9A5D394BCULL, 0xDA2B617F9051D6CEULL, 0x2E0E3E9D26A2487EULL, 0x7F30F1409B97155DULL, 
            0xFDFE2E29E4BBEB75ULL, 0x86434E4C3F4F5E1BULL, 0x9EE35631DEA62096ULL, 0xE82E7AC9A4150F52ULL, 
            0x4732031D3F80CA8FULL, 0x019E97CB0FCA7497ULL, 0x8DBCC3E05D421243ULL, 0xC158647C9E91CE2BULL, 
            0x73ACD7B061A2F57AULL, 0x0E1D2388A13BC679ULL, 0xECD6D15933E7CA37ULL, 0x1D3702EEEDEF4A55ULL
        }
    },
    {
        {
            0x3238E8364FB411FEULL, 0x38B2D82A1E2B92D4ULL, 0xB7D376CF71D2DDC5ULL, 0xD694FEFDBCAA742DULL, 
            0xF533BC9654A5D41EULL, 0x5B4FA56A0683BA02ULL, 0x84318CD6A7D51224ULL, 0xF402E7D798627518ULL, 
            0x0E2425C26E808CEFULL, 0x945066B4852FB421ULL, 0x2BEEE18EA691E6A3ULL, 0xE0AC8365261A97C0ULL, 
            0x7D9C316C3873D757ULL, 0xE86A0F0A1B10A78DULL, 0x939450FDB6A5E571ULL, 0x58018DC2C04A7F67ULL, 
            0xF01298C991D7FD3BULL, 0xFCA67A941A66ADF2ULL, 0xAE45536EEFE5349CULL, 0xB061DE751024D2D8ULL, 
            0xD74F0E4777DD6830ULL, 0x33EFD56A41A86BE5ULL, 0x3AC29B1F1F989D37ULL, 0x2D33D741C8DC2847ULL, 
            0x8AB539EB24CDCE78ULL, 0x0AAA03CA0DD8A664ULL, 0x78277C21ABC56DA4ULL, 0x0B6F04BED0E52BDFULL, 
            0xA193D5026326A503ULL, 0x3966F1313235FFC6ULL, 0x2E7446E78B1978CEULL, 0x1623EFC12644158EULL
        },
        {
            0x8D5CEBC7434DF3B8ULL, 0xBB4A9DD49097277BULL, 0x95D6DC1236106C3EULL, 0x6095303135302253ULL, 
            0x64477809A8DF6C87ULL, 0xBB3983B19B4B8D3FULL, 0xE5C9FB669DE08B8EULL, 0x0E6F38EF84C0A01FULL, 
            0x6D01913BF49A9D72ULL, 0x2ED6A9CF321D63CCULL, 0xB031AD64B97246C5ULL, 0xF23AACCC2BF289C8ULL, 
            0x5A13C78AEB7E9C25ULL, 0xEB8007D85E54E76DULL, 0x4A4C884D5A3D0D77ULL, 0x299D27E319033B77ULL, 
            0xEF11AC30477149ACULL, 0xF5887C85FA28E3C1ULL, 0x95F13AB2E042B795ULL, 0x59277E4DBD9EC1B3ULL, 
            0x09ADF616D23C713BULL, 0xD472C806C9266132ULL, 0x1D846C0DFDC3F95AULL, 0x60F7FED69C0AFA38ULL, 
            0x98DE7D5F07ADDBEEULL, 0x7D85EB69808BA02AULL, 0xAEE312EF5B7BE67BULL, 0xFD195C25AA4A2EA8ULL, 
            0xDFA2D88333AC0CF9ULL, 0x26BB8220F19F5B81ULL, 0x93464F4208ED7305ULL, 0xF7947916648E5616ULL
        },
        {
            0xB1F8ADE2FF67F727ULL, 0xC827A9872F3D85A5ULL, 0x72BF5CF81085DDE4ULL, 0x0FE4DFEB5CC06608ULL, 
            0xBF19C6CF0C0A5BDCULL, 0x0BD908F9DF4D8572ULL, 0x8DEF3E6E17A287B0ULL, 0x806315846DD4BF8CULL, 
            0xFCDBEF76E1A970F6ULL, 0xE477908727AB1E90ULL, 0xA72665FACB77FFB0ULL, 0xF2BE4BA574A9B461ULL, 
            0x23A32200E2BC878BULL, 0x927B7A4575AB6DEFULL, 0x11E7CBA9E3A91E8FULL, 0xA8382DD9D45C6712ULL, 
            0x8D24039C2444CE4CULL, 0xEF8669A08C11CF24ULL, 0xB494FE9C1B448346ULL, 0xE1CE1BB7882A58CCULL, 
            0x0A0DB59676FDCD5FULL, 0x17877B5E7E048142ULL, 0x22B0D42883F11190ULL, 0x3B1C2BDB5DBFFE87ULL, 
            0xC019B4BC46E50869ULL, 0xDFE4BCF81537E7BFULL, 0x09C369C4B7EE40ADULL, 0x379498D62FD42ECBULL, 
            0x2E4C92AFE58EFC03ULL, 0x5B4DD0C75F025258ULL, 0x00A328F6689045A3ULL, 0x58ADB7AC0FA8CB02ULL
        },
        {
            0x7A2D5FD87F0AB5E1ULL, 0x30DE68F2A9015E71ULL, 0xDCECAD4959AAE762ULL, 0xA8093F22F3E5DA5BULL, 
            0xB5FB6CF4BFD55546ULL, 0x7B3FA89CB2E5ADD2ULL, 0xBFB1718CCB782313ULL, 0x1B2F7AED84AF8636ULL, 
            0x20B610D8AAB10281ULL, 0xC40205D015079501ULL, 0x4763103921DCC61AULL, 0xD0C324A8A2677CA3ULL, 
            0x79375901C0D0171EULL, 0xFBF705C7E5417265ULL, 0x696E2F8A991108DEULL, 0x73B2EC468DA96CCCULL, 
            0x6F724A130D813F72ULL, 0x3E6228B5929FBDABULL, 0x1BE2E0C58BA0A229ULL, 0xD89E016C744D46E0ULL, 
            0x50667B3971116FF7ULL, 0xC812CF2900F8B684ULL, 0x1F48ECAB17D3E3E4ULL, 0x461596615BACEDB7ULL, 
            0x70E02B4582070035ULL, 0x0B75DC4131F9DEE5ULL, 0x377783EB66276B23ULL, 0xCD10EF5C711D72C4ULL, 
            0x15D22E161262FF8CULL, 0x6694A7AE18DEEB42ULL, 0x5B786BF7B8407CC8ULL, 0x35A45454CE6AD575ULL
        },
        {
            0xDD25861C592336BAULL, 0xE200A0636B706708ULL, 0x9FA596FA6E0FE7E5ULL, 0x48376F70D1AE7D3BULL, 
            0x66434AB5440788E8ULL, 0xC425D28F3CFC0477ULL, 0x51743B2E903DFE81ULL, 0xFC29DCB5E3AF52F4ULL, 
            0xB7F55DC3326DEFEAULL, 0x06454FBC74E87FFCULL, 0xBE7A055FB3F609A8ULL, 0x2FF9E5863A5BD717ULL, 
            0xAF63793A97E42BBEULL, 0xA88B09EC7C4BA608ULL, 0x93605A3EE7357444ULL, 0x11BFA542F8F03BC1ULL, 
            0x2EA2F53111AEDB80ULL, 0x5ACF44995C20C010ULL, 0x05A9400179B15D17ULL, 0x5BCE9E6F1CE7701FULL, 
            0x6F74D1AC093E0DD2ULL, 0x34E215D4F9503B21ULL, 0x86A350EB8DB737A4ULL, 0xB11C45B070D4555AULL, 
            0xCBBB972E950CA4E9ULL, 0x98C59E2213C1A45CULL, 0x84004223568AA9FAULL, 0x66D0081BC8BB6FA2ULL, 
            0x17CF357C18D29A7BULL, 0x3A1C9DBD68AA0C2DULL, 0x977A9ACADF71F300ULL, 0x7F6C5454F44196A9ULL
        },
        {
            0x72A8E62E58134EE1ULL, 0x80D570736659AC7CULL, 0x31392712551F1057ULL, 0xF67BC3AC1B69C478ULL, 
            0xB8564E39D9EC9A87ULL, 0xB9EDE3F5D112C2B6ULL, 0xB2605D4324ACC667ULL, 0x4736340940DEDD67ULL, 
            0x00ADBAEFF904A477ULL, 0x200616CEE04FE57EULL, 0xD15B9B4804B5AD14ULL, 0x1DEEF966AB7F17F0ULL, 
            0x6A69ACEB937E8C88ULL, 0xCF996AD2017890A8ULL, 0xFE413B88605FD0AAULL, 0xB62135D580A74090ULL, 
            0xE33E229518771589ULL, 0xECCD715A8BABA54BULL, 0x06127AF8AA6C5D50ULL, 0xE479F85523C75528ULL, 
            0x3F1B6D8ADF794733ULL, 0x55C9616EAAE0482FULL, 0x714380092971EE2CULL, 0x323E68242A4270EEULL, 
            0xDE666134D711E811ULL, 0x812F6FD604FCEB86ULL, 0x5CC953EB3B2E8716ULL, 0xDD957CDA88533D72ULL, 
            0x9345F0BC8E25E542ULL, 0x2C5AA6F04B23CAE1ULL, 0xED90549FEAFC54D3ULL, 0xB9A6B9F3C1BFF822ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseEConstants = {
    0x7477DACBAD355492ULL,
    0xC3B57666E4D5C963ULL,
    0xDA83AC6E121DA84DULL,
    0x7477DACBAD355492ULL,
    0xC3B57666E4D5C963ULL,
    0xDA83AC6E121DA84DULL,
    0x48CE2459EE9D213AULL,
    0xD2C0CEA9F2AAF6ACULL,
    0x45,
    0xC3,
    0x3C,
    0xB6,
    0x48,
    0xE5,
    0x91,
    0xCD
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseFSalts = {
    {
        {
            0x4DC0CB9F7F2F1423ULL, 0x778046D7F4205E62ULL, 0xE5DA1B30717D6FE9ULL, 0x1B6ACD5EADE58ABBULL, 
            0x6E2AD1EFDFC6680BULL, 0x000040BC94596D99ULL, 0xC054A764C6792A16ULL, 0xC0CF9174470261F9ULL, 
            0xA0E68B6C4EBC4122ULL, 0x29173A3E33EF3212ULL, 0xE7AE90F7A27E8143ULL, 0x72FF572F75C353F7ULL, 
            0x74F91CC9DC7E21D1ULL, 0xC9824396A11411B5ULL, 0x0EB3BA5B0D42A87CULL, 0x3BFA29852E41454EULL, 
            0xC32AF5AC24E665BAULL, 0xB2A3A4C8CD7F6117ULL, 0x53800809515B246DULL, 0x5F7978B17435392FULL, 
            0x28B4AFC14B10866AULL, 0x5E1081C15A96B0C5ULL, 0x73D5AF184389A0EBULL, 0x1ECCF9BFDB3C4861ULL, 
            0x7E1D85793C994CC0ULL, 0xA86AC5CDA2962EAAULL, 0xDDFF92390413B7EAULL, 0x80AEAD57E778F45BULL, 
            0x2744C150AC411851ULL, 0xEC395D88DFC2DBE2ULL, 0x281E2343DF48E900ULL, 0x7C4DFAF10246134DULL
        },
        {
            0x7586F8BDD5CDAD51ULL, 0xE760A0AB58D6BDD6ULL, 0xB1FC1ADC4925DD75ULL, 0x3A6F9799009D8BFAULL, 
            0xA88B794A0754A9FDULL, 0xEC1E80D6BD780AF3ULL, 0xB0B0A58D23BB9681ULL, 0xE6FCDF50803BDBB4ULL, 
            0xE527A1C8678D68FAULL, 0xBE4D119EDD7086C5ULL, 0x3AC02F82104B2663ULL, 0x6D41762113412D77ULL, 
            0xF374FD6AE2B31DD2ULL, 0xCEAF68DB8FEBA3DEULL, 0x5162DA4700A1FA2DULL, 0xD7AA01F5090F72A3ULL, 
            0xA7FF33B9B29FBD33ULL, 0x8296BD471B75E8B7ULL, 0x9EAE097A7526348FULL, 0x339CD7A635E6263EULL, 
            0x167C156D1B0AA3D6ULL, 0x92B16C7CFECD8446ULL, 0x3B6128A5A5AFCD60ULL, 0x68F05CF650892315ULL, 
            0x8982961860BF7E19ULL, 0xB621B686FC82B451ULL, 0x08A4FDC12A2C2ACDULL, 0xDE55E691280F0AA0ULL, 
            0xA7F95C89BB331D0EULL, 0x4131A6548FC3FF9EULL, 0xCF2E251E1B9AD4C6ULL, 0x4A50AB9A2B359C59ULL
        },
        {
            0xE5E98681CD561BB9ULL, 0xFEFD3F5BB4E8834BULL, 0x0D6F0EC309D8B9F8ULL, 0x11341E0CDE165B9DULL, 
            0xB05A6B6B4B37BEFFULL, 0x6C5475A8E938B539ULL, 0x5F44EDA0A844E93DULL, 0x7C0B76E0DD02E857ULL, 
            0x7954D722BC576071ULL, 0xE941FAED0BBC06C5ULL, 0x8C8F39CE22B7F081ULL, 0x070D7FE53DC1DFC6ULL, 
            0xC94189159C70DDFCULL, 0x5360FBC974C60CFAULL, 0xE7DDF58DE561A789ULL, 0x8419B6325F6767D2ULL, 
            0xC507B99EE34FD1FCULL, 0x8A79AB3868883D6FULL, 0x22C4CE78909CF5FFULL, 0xFE0145C908C50C89ULL, 
            0x718AA1AE22D3C140ULL, 0x4623222BBD0CBAA2ULL, 0xAB84E67376401DC0ULL, 0x5FB9329409439272ULL, 
            0xF02291AFF72F017AULL, 0x90BC0A06FA94BBADULL, 0x464CB59DE348B6C5ULL, 0x0C036E2EE1C51218ULL, 
            0xC319D361D802FAEEULL, 0x36445399069F0E7CULL, 0xD677656FED7C467EULL, 0x2811C7A7DB44ECBAULL
        },
        {
            0xFA86CDBD725B273EULL, 0x503609F2AFFDB843ULL, 0xCFB6ADD31F53D626ULL, 0x33D9ECF0C7C11A42ULL, 
            0x277470CBF533C7F1ULL, 0xF80DF65D465663CDULL, 0xCC507447216233B4ULL, 0x6E4073BEDBDFF6CFULL, 
            0x06C4A2171262F76AULL, 0xDADEB1835FEFF09EULL, 0xF579D0302F00035AULL, 0xC84D3ECA9FE98823ULL, 
            0xD1CD7C7D4782841FULL, 0x5FA0DA234DCDEA7BULL, 0x19DAD2BCD6ECD1D7ULL, 0x0447C87C5B9E1956ULL, 
            0x3724D2EF2EA033CFULL, 0x1301E453BE17E71AULL, 0x65998239C9D62605ULL, 0xE2E57792790E979CULL, 
            0x68BDC4AB36E85BBCULL, 0x37284BE5D050BC3BULL, 0x3A3AD2AC3A3DAF48ULL, 0x11E8967D7940BF42ULL, 
            0x1BF1B18F8205D24BULL, 0x6EF8731A6BE88052ULL, 0xCBC2828932349E01ULL, 0x0D1C034A3F3A4CE9ULL, 
            0xA37FCFFF210BB84FULL, 0x07C94FABED3B5583ULL, 0xD3CF807AFB233A12ULL, 0xA36BFB2CEFF26931ULL
        },
        {
            0x9C824391C459C7F9ULL, 0x159723C19BCF4E00ULL, 0xE0E3C98AB971949BULL, 0xA75138490F17C46DULL, 
            0x7BB34870B941E6ABULL, 0xD11FECAC88998294ULL, 0x55A8890AE2AD765EULL, 0xF0C9D3BD2D3AB2D2ULL, 
            0xF3A558CD05CB43E3ULL, 0x627F99EF8BD894F2ULL, 0xBCC062D1BFB9BEA7ULL, 0xCA1E9EAC338A3FDDULL, 
            0xFF32CE8FA1B0BA76ULL, 0xD79D88E1844DF963ULL, 0xC81C72B67301CC9AULL, 0x523B5FFB83DB5AEEULL, 
            0xE6815225459215D0ULL, 0x1C09DC6FE038969DULL, 0x893232885C365168ULL, 0x82B0973C7CCAE23AULL, 
            0x4BD2784FC6B20B3DULL, 0x9F162B9877744792ULL, 0x773A518527043B6CULL, 0xDD349270F236E9D7ULL, 
            0x7E4136F93374EE50ULL, 0x0955EF0724B4AFA5ULL, 0x71CF3C361FB86A15ULL, 0x9131FB639DB7E620ULL, 
            0x8001E78C28B3BB99ULL, 0xAF796B30B4B5CFD9ULL, 0xAD370EF9455556E4ULL, 0xD8568428B0A946F2ULL
        },
        {
            0x2BA861D705A5BE8EULL, 0x5C58D0EC6CDE3F4DULL, 0xFAD9D38A9A67F085ULL, 0x503D9354D63E32D8ULL, 
            0xF61E306A6647243FULL, 0x9FECDBF3C9186FCDULL, 0xC3A78F153C98BCB4ULL, 0x81353A3AE0A2113EULL, 
            0x5E4956FBB56FA8A9ULL, 0x1E7581A76A4E3D42ULL, 0x20FCEACA789B8DF5ULL, 0xB298B56BFBA90967ULL, 
            0x0BDDDA1184A503CEULL, 0xBF1CC4E07D9CA3F2ULL, 0xF1687D3868D3C1DDULL, 0xB323A83A97DF2B44ULL, 
            0xB0789420DD00BFFBULL, 0xBE5FB69EF02D207FULL, 0xAC9A932A0DE6B3EFULL, 0xED3A7AFF31F7AF49ULL, 
            0x9017A836848911E6ULL, 0x4E9E209D36C197A7ULL, 0x2B3F1657F1781C90ULL, 0xCD404E4466FC8D29ULL, 
            0x5CA194AFD7B741D4ULL, 0xCCE6CCF896A519B0ULL, 0x48E85931782B17AFULL, 0x326D1A5D51228090ULL, 
            0xF00F5CE7AA31E867ULL, 0x3DD1C748D0332040ULL, 0xDED01FF8712AE139ULL, 0x523211B5A1073535ULL
        }
    },
    {
        {
            0x4653484AE0FE5159ULL, 0xF2402BAFAA4D45EDULL, 0x8720512A1237B69DULL, 0x3DB6751ACCA6FED5ULL, 
            0x57AE346ADCF80C80ULL, 0xB381781C36D85089ULL, 0xE00C07C9B34D8449ULL, 0x1004189DC9F0E3CFULL, 
            0xBA35BF9D9D423B52ULL, 0x23E0867216F2A03FULL, 0xFCB7DA618C353B1CULL, 0x27D91AD84B09214CULL, 
            0xBFF2FB9172FE92E7ULL, 0x7AFF8780931B36A0ULL, 0x43FB64194C73A8ADULL, 0xD43F0A95C07846AAULL, 
            0xE89EB1CC111FCF24ULL, 0xF2487A26352341BAULL, 0x4CABE15A63A3CDD4ULL, 0xE9A1770EDD41F18FULL, 
            0x954D783363B3EAD1ULL, 0x35BE95D96C2B1564ULL, 0x61AC64F259833058ULL, 0xBC5C9BD9B4D74DB0ULL, 
            0x54B3EC9640797001ULL, 0x11EE1938B41E5B68ULL, 0xA9BE931059B2D521ULL, 0xDDA3CC60DBCE4B96ULL, 
            0x68F3F7ECC6B3E832ULL, 0x694C67DD9F6DD71BULL, 0x23C1FF22C3258D6EULL, 0x92BC1E07571D8B8AULL
        },
        {
            0x93919BBCA648DC25ULL, 0x79CAE2AEACB7EC43ULL, 0x33A8F2A2F96A8D5DULL, 0x300BF57E0079D226ULL, 
            0x6C3A7C064BA18CE8ULL, 0x88748B93BCAE2E92ULL, 0x433E6CA114CBE26BULL, 0x50FC2C9F2F89D855ULL, 
            0x900CF3C489CEDC97ULL, 0xCBED48A7498E07A6ULL, 0x18049ECBA2D30EC0ULL, 0x75E2AD9BF67E2F4EULL, 
            0x91D7A7E76AF01B01ULL, 0x345B1AE1D07C844AULL, 0xD0D54794082C2790ULL, 0x5DA975FFE72EF0E2ULL, 
            0x0164451B350EDDEDULL, 0xFF01FF4BD789D7D7ULL, 0xA016CF57CE620AF1ULL, 0x23CB68135FB9EFFEULL, 
            0x3E82C1F13414D789ULL, 0x5FE21E34D8265D3BULL, 0xF4FBE7694C2039F7ULL, 0x8056A30869310DC7ULL, 
            0x4AB9B77CFC6A35C9ULL, 0xC04014A6EA7F4D93ULL, 0xFF2A7B4D56CF9399ULL, 0x6D2267E734F5C708ULL, 
            0x161AC796234F8139ULL, 0x8240973885618FDDULL, 0xF1A8124F7C1C7168ULL, 0x45958EDDD4DF0019ULL
        },
        {
            0xBB2C44AC46D4866AULL, 0x5331AD1FB600DEFEULL, 0x28642BB108E31FE3ULL, 0xCAA95CD91A014C1CULL, 
            0x343BFCDC158A2684ULL, 0xB73C3CE397806DBFULL, 0x5821F03004AC4F6EULL, 0xAC8500151C7573EBULL, 
            0x1320A4339589BBC1ULL, 0x5659920646A9330FULL, 0x7B59AAADF9585084ULL, 0x62470661A9532F37ULL, 
            0x201346F022B70EFFULL, 0x8B8B9DDF95318250ULL, 0xDA5A4C567F22B60DULL, 0x7C19B0B51E711980ULL, 
            0xC8DA5DE6CDAF2AB2ULL, 0x1C4EC82A47CDB5B8ULL, 0x522F02D7FAB47732ULL, 0xA4A75557331EF1E6ULL, 
            0x4D3E641696480578ULL, 0x71D77DDEE5F0E546ULL, 0xB715A42339A30E12ULL, 0x5C617330228AD55DULL, 
            0x5D23E9B97DE3CEF6ULL, 0x0DC376912420DCB6ULL, 0xA83B19F8867CD60EULL, 0xD7C5DA8ABD9416CDULL, 
            0x1C3F864C0D6630EEULL, 0xADEC36E0220F40D7ULL, 0x8DD5E4622C76F7C9ULL, 0xC7BD4179E5AB35A0ULL
        },
        {
            0x2AE912456A296194ULL, 0x44956127A14DD417ULL, 0x070590AC3A905562ULL, 0xD3355811B5E92DB2ULL, 
            0xC1F4CBD9F1D8A6CFULL, 0x1357030705819332ULL, 0x41CA691E2D807CDCULL, 0x22A69048761DD002ULL, 
            0xA1B7C93789269A3BULL, 0x3CDC9CE2CAEC2316ULL, 0xCB585F7BF128E9F4ULL, 0xEB85564B0F532DAAULL, 
            0x9380E631C62BD757ULL, 0x62FFD34FF9B924B5ULL, 0x2C52332AC19772F0ULL, 0x85DDAC37C8657D61ULL, 
            0x0553AA082655DDE4ULL, 0x9AB94D5BB9D06E36ULL, 0x3E1C4E85AF46E584ULL, 0x4B2D92A65D5FB5F1ULL, 
            0x4164884AC30AA0D3ULL, 0xEE07DCC6144D867EULL, 0x2F653ADAC513A929ULL, 0x00A07F59848079DBULL, 
            0xAE93687DBDCC60C2ULL, 0x226B5F1E25836D78ULL, 0x37F2E0383C4C96D7ULL, 0x4951E8B53664734BULL, 
            0x1C029E583BDB274AULL, 0x1474EFC3F0B3C9F4ULL, 0x91CE28CC8CAAA88FULL, 0x23BD3D7306207009ULL
        },
        {
            0x5D2F982F0053879BULL, 0xFB44D31C06E25060ULL, 0xCFAD79BC19CB6872ULL, 0x70667DD2C96DEF52ULL, 
            0xD4C0DC447FB87CAEULL, 0xF49EBDB3AE0D6C41ULL, 0x7570C512AED15B7FULL, 0x0790E4FEAF7F6E56ULL, 
            0x6570C1F9F1257860ULL, 0xC39329971EA1F77FULL, 0x1137F3F0140D0B3CULL, 0x6F103343BBF4B669ULL, 
            0xDD8925C0FD98857DULL, 0x49A9D8C4319B8DB4ULL, 0x8DCE909963398DA1ULL, 0x7C3803A90BEB140FULL, 
            0xAC0FD70E851FABF4ULL, 0x9676EE99A1EAC4A6ULL, 0xF7F8F9FBA4EB7A54ULL, 0x0A8FF0967A03C051ULL, 
            0xBDA31798E897BDE2ULL, 0xEF71F941EAE2632AULL, 0xDE2D616BFB2513A0ULL, 0xB1DB33C4B4BEB04EULL, 
            0x8272AFBC92A372D7ULL, 0x92B17088DA5FABFEULL, 0xF285FD0191B3C61DULL, 0xA814E04C9BF95B18ULL, 
            0xCC375413F1E8712FULL, 0x04CA148F8ADC2245ULL, 0xB3862BE32EF2A730ULL, 0x0EB69D4F1424016DULL
        },
        {
            0x4FDFA6F16EBCF3D3ULL, 0xF1708B57B22F9136ULL, 0x8FB41F79489C3F75ULL, 0x4D68BA6336C3991CULL, 
            0xEB47F13D97FCEBA1ULL, 0x6A2023EBE455F85DULL, 0xB8BDE3B6FD63377EULL, 0x80609D11CBEC25FDULL, 
            0x4B372146C36D3BFFULL, 0x1509C97A02D15B28ULL, 0x1EDA3A2E15B74B4CULL, 0xC6DC7956A509F1A7ULL, 
            0x7E4BAD70524AE656ULL, 0xEBCD2F84A445DE46ULL, 0xAE4BFDE4C0B149B1ULL, 0xF62E9AFC95D6C07DULL, 
            0x6054D23DF971F239ULL, 0x74F2B1B1D3FDB4C1ULL, 0xCE7B710CF34D97B9ULL, 0xFE19B90A9C61B066ULL, 
            0x2B419A5D222E6F50ULL, 0x71974EA1F01C0388ULL, 0xA26575A5F4002986ULL, 0x0BE8CF971A78AD51ULL, 
            0xAE4C7BCF294B562AULL, 0xD1174E8C6F5B61ACULL, 0xBA7933EC7327EA27ULL, 0x08628DC6E1D5558BULL, 
            0xD6F094CA45C9770FULL, 0xA1F6CD4823D72F76ULL, 0xDDF8C333DAEADA20ULL, 0x1270E3584316A715ULL
        }
    },
    {
        {
            0x3C855FD10D8AE8C7ULL, 0x6BB16F81B88E7ABEULL, 0xFECFCE37C02E6BC2ULL, 0x24D5A6A87DFE4456ULL, 
            0xFEEEFE6B78A6E574ULL, 0x004160219AA64D65ULL, 0xA783A7EF8FBFC7A3ULL, 0x24F233097C5C13B9ULL, 
            0xA6444D677DACA4BBULL, 0x3CE4E8D5EFCE281BULL, 0xB1ECA33D36B02ADAULL, 0x906D451B6C375AE3ULL, 
            0xC148B9BD2D91F7C1ULL, 0x6DCE38ADDBCB1176ULL, 0xF77990B964AD8F58ULL, 0x21220CB2046DBCCCULL, 
            0x0508D2156725076DULL, 0xC5D6FE5BBD4D8248ULL, 0x6D10F59AA6DF36C1ULL, 0xF904EECDFB873EFDULL, 
            0xCA8D6556BEE8D2CBULL, 0xFFD155FD04606F5CULL, 0xB3216A8154008D93ULL, 0x5BBFE3B0B5E2F4D5ULL, 
            0x9601BAAC3495CC5BULL, 0x985D4B7B6F6700BFULL, 0x8576CB27263D6C79ULL, 0x5E9067585F7A6B9BULL, 
            0x802AFEC2A4134429ULL, 0xBA9DC4BD776DEB4AULL, 0x73011934BEF42848ULL, 0x848DD0F79E6A5A01ULL
        },
        {
            0x6C5B262A2FFE462BULL, 0xD5FCC022DB5E3EA6ULL, 0x5AB4B202A37561E5ULL, 0x1197220F26111C21ULL, 
            0x0CD745580C9E8804ULL, 0x75AAAB2B5A04760FULL, 0x8467D18923897448ULL, 0xC22685F6B57E3C8DULL, 
            0xB43EF7D71AB7351BULL, 0x5D1567F9208D0C9DULL, 0x2F985DD8B07D75A0ULL, 0xF88C0064DA3523B5ULL, 
            0xA4A8888EF67216F9ULL, 0xB7AFA5BF4DF90297ULL, 0x3A01F7C40964B232ULL, 0x91238810B01BF5A0ULL, 
            0x944A621950F8E1A1ULL, 0x03ABDF3265A4B983ULL, 0x94C6BDB5BBBC7ED3ULL, 0x91FCCF04BB9BCE48ULL, 
            0x56DDDBD0ABE496B3ULL, 0xD9E55792D3B442FCULL, 0x073B7654A701E2F6ULL, 0xE74C76A8CB75814EULL, 
            0xA6B480D6B392B87AULL, 0x39478B6567BA719BULL, 0x475ADA201594046BULL, 0xCEE54B170FAD0993ULL, 
            0xF8639792023453BDULL, 0xE8E8A26F9DD78B1FULL, 0x0EB215EC393F0B70ULL, 0x9B9EB5B7FC2237C9ULL
        },
        {
            0x673C18C75BBA9FEBULL, 0xB883EBDC3DE244E4ULL, 0x9C40C0E5114F197CULL, 0xFD0780542577E350ULL, 
            0x346E4FC853EAD18FULL, 0x2EFA02A800D5022AULL, 0x89E87AD0BFCE0E61ULL, 0x5D5B0D491444FDFAULL, 
            0x4EE6086CBB152333ULL, 0xCA62063E0A98A0D0ULL, 0xBA0D975A2D26EC89ULL, 0xD49E85564DADBDB2ULL, 
            0x52785ACBA14E1DC0ULL, 0x71CF0C20BCA936C3ULL, 0x23CDF15F8A9FF293ULL, 0x02B41A2B23F14349ULL, 
            0x3A2328583097B8EEULL, 0x6813263FCA5EE688ULL, 0x95E920C1CC367179ULL, 0xCC3D33410A42CF5EULL, 
            0x59BE4FF7893C95C0ULL, 0xC34B775071AC265DULL, 0xA849408999B2A651ULL, 0xF53293C38679CE72ULL, 
            0x948627C4499F5C2FULL, 0x9C3CF93FBC225832ULL, 0x0F0F9B82D9A8348AULL, 0x7AE154EDEEF003F3ULL, 
            0x030CB1FA39204BBDULL, 0x034841B00D0FDAA8ULL, 0xA18030C79C24C558ULL, 0x3E53B6AC3AE48F78ULL
        },
        {
            0x7B4B94CE45C31EBCULL, 0x3FC9862DCB95B703ULL, 0x48D63D954778845FULL, 0xFC37D09B6926C311ULL, 
            0x786533FA46050D60ULL, 0xD9591FC624B2DF20ULL, 0x4A641468B961A691ULL, 0x23A2170B2BA1146FULL, 
            0x50E5BCA650DEE66CULL, 0x895775D127C1D7E8ULL, 0x6931F74A9BFA406AULL, 0xDFFE91A76B232776ULL, 
            0x2A3A643C752ACD4BULL, 0xBE19E3708EFC0DCDULL, 0xC9A8314628326BCDULL, 0x19AAC4483613CF41ULL, 
            0x98081234DBAF2908ULL, 0xDF8928298F2E9CB3ULL, 0x26849CA3BFFB637CULL, 0x257657DF5465D68CULL, 
            0xBE34EDB86E366EF9ULL, 0x5E471B445A37C2C5ULL, 0x269AF48C87852D35ULL, 0xD6EBD1CE44EFDB4DULL, 
            0xBD3E66907A321699ULL, 0xD9D8C3C1C2D7C864ULL, 0x3866035B8AD392BDULL, 0xBE456AA7FB3CDEE3ULL, 
            0xFD49CA8E88C5D8D4ULL, 0xFB36C5CCE3AA7E84ULL, 0xF0C68C5219F22365ULL, 0xABB5AC8E058B3C72ULL
        },
        {
            0x9CA0787569FE4E0EULL, 0xA5314DFDBAD1A66DULL, 0xCB02B8535086101CULL, 0x7A6DFBD7D535D74CULL, 
            0xB468A74B56AECF88ULL, 0x069A3A31C61D1AC8ULL, 0x68F5BBDF18757C78ULL, 0x125A0A2B596AF03AULL, 
            0x44E615A229171AE7ULL, 0x69A4BAC0C2965DA9ULL, 0x261F78A8113734A1ULL, 0xBD492E1742832B08ULL, 
            0x8A0C922891B77D02ULL, 0x7EC3626D4BBCA66EULL, 0xB77C584E67183B0BULL, 0xD6145A60B31E385FULL, 
            0x39B1D79564994486ULL, 0xED4C8B1E9376661CULL, 0xF0BB5163BBC8980CULL, 0x08F96D8309964AD2ULL, 
            0x3637AA643390FA51ULL, 0xF3C8C49A83B8C094ULL, 0xA4E35A9024734A45ULL, 0xBCA96F3A886F5E0EULL, 
            0x64F44CEF2D0901C9ULL, 0xC652E99110882346ULL, 0x9FF00D4E0EFCD4F8ULL, 0xDD1E66B05A9ECA6DULL, 
            0xE49A4532015D7BDAULL, 0x52C273A1E9B2CB6BULL, 0xC6AD1275748D3E3FULL, 0x2A72147CB0C0A458ULL
        },
        {
            0x28EF1B31DA80DD77ULL, 0xB73F916D90192CFFULL, 0xE490DCA1FFE33901ULL, 0xDFE3B914DC5F9018ULL, 
            0x8D681DDD6A8B0751ULL, 0xCE7295ACD1448F48ULL, 0xFA26CF1F22CE751DULL, 0xF885DE861E7E91FAULL, 
            0x30D72E7F5354F70EULL, 0xBB2D3C4FBB6DCDADULL, 0x6CA273876B26C0CCULL, 0xA4CBABA1EC6AAC04ULL, 
            0xEFDA8D50263FDB3DULL, 0x8D06AF7AAC16B26CULL, 0x9ADD4CE46A738EF0ULL, 0xFB1A31F7D9F4CFA1ULL, 
            0xF30D4E738448216DULL, 0xA64CFA2BB88C5B99ULL, 0xA9FD745EC7E45AB1ULL, 0xC9E0F8EB8F83BC0EULL, 
            0x82073A575414746EULL, 0x22417C64B65BDB2DULL, 0x8011E9BEC2DF665FULL, 0x74599A00BF216933ULL, 
            0xE8534610B4BE0723ULL, 0x9AB0CB44A5D0AC29ULL, 0x2DFB486E7D131B1BULL, 0x5290DDF5753103F9ULL, 
            0xC1359852BE28990CULL, 0xCE91D60632F6E6AEULL, 0x8D609DE23A6B5300ULL, 0x56635DD7C052E7BDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseFConstants = {
    0xDDEC74996BD09D10ULL,
    0x6C455400E3E94DE3ULL,
    0x694FEB57E4326B9EULL,
    0xDDEC74996BD09D10ULL,
    0x6C455400E3E94DE3ULL,
    0x694FEB57E4326B9EULL,
    0xF5582721A38882BAULL,
    0x5EAFA3EF2744C456ULL,
    0x37,
    0x73,
    0xAE,
    0xCD,
    0xE0,
    0x46,
    0xCF,
    0xFF
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseGSalts = {
    {
        {
            0x82F2B083BE1A690BULL, 0x6E4A3C6EAF443C6EULL, 0x1F40B9CD8E7B45C0ULL, 0xF464464696392FE5ULL, 
            0x01C5D15D57E9A761ULL, 0xBE09CA7CB2A8B26DULL, 0x5916C65D5900DA76ULL, 0xE19CC8802879FEEDULL, 
            0x02EDFA505389100FULL, 0x3D0D7428C3E87B5EULL, 0xC051057E911916AEULL, 0x340530EABF06F316ULL, 
            0xC4A11BA543530B85ULL, 0x11B5E4E2B7C663FAULL, 0xF8233D03D6B9A334ULL, 0x9198E51AC3A3C46EULL, 
            0xCBCC7E2F87D48D8BULL, 0x97D01D8BAFD60D59ULL, 0x6E1A693DA04717C1ULL, 0xBF74EA19A036AF82ULL, 
            0x24B96E9009385027ULL, 0xEDC2656605B3B2C5ULL, 0x4996B864D737020AULL, 0x842F396E3A097720ULL, 
            0xD6CB8BB3005BE4A3ULL, 0x677BA395DD5F0DDFULL, 0xECC13EE7AB6D7E85ULL, 0xC993F66CCF0064A3ULL, 
            0x9D25CD92788679DEULL, 0x82528E1A21CC7B68ULL, 0xF18C265E7C8F4C05ULL, 0xB87B5CDBF159D762ULL
        },
        {
            0x8A4289779CC47A1DULL, 0x3F252258665D372FULL, 0x21D40DC5DDB85BFBULL, 0xD692531D133D3692ULL, 
            0x1DCAC48620B87121ULL, 0x226F262B67EC5E23ULL, 0x80EA8871433F4D42ULL, 0xCAAA08AC87DA3832ULL, 
            0x574AAEBD1318B53EULL, 0x149258DDAEEA4B73ULL, 0x18AA7EF8545A7AD6ULL, 0xC0F18FED22995071ULL, 
            0x9467E305DBDD5975ULL, 0xC2CF0BA44A0EA694ULL, 0x14FB5B8EBCD2B2AFULL, 0x41911D74CFA3EF73ULL, 
            0x283CCADE093E9A48ULL, 0xF7F4D5FD7622A5F6ULL, 0x971A6A604894B5CBULL, 0xC7DF37BCD7D2A9CFULL, 
            0xB2F5174A358E4883ULL, 0x49A6676FFC0FC0ABULL, 0xEF4FA0C0F05E13E0ULL, 0x9A54B2ED41CDDA5AULL, 
            0xA4701E44E7FED198ULL, 0x766615405AD1C2B0ULL, 0x7C8D4D9A08AA3102ULL, 0xA4C0E6AD37374B83ULL, 
            0x0D8E79132584B13DULL, 0x6FD5A8C7D636280FULL, 0x004FEDAF30004F22ULL, 0xA73C6DEC9514ECE2ULL
        },
        {
            0xE90746BE13F51C1CULL, 0x201450DB8F66CB09ULL, 0x190E7CEB9221EA37ULL, 0xB11F751B18A3257CULL, 
            0x9C0257042D384A27ULL, 0x77D103C9055AD108ULL, 0xADBB44CD24DAB8BEULL, 0x835C0F8A8A108642ULL, 
            0x62E7ABA7E4F9D7BFULL, 0x9C27F3147050FFFDULL, 0xE3247D8FE24C31E3ULL, 0xF7D1E79BFD81F425ULL, 
            0x3596F07B273FB189ULL, 0x4B50C1D3EF4B9607ULL, 0x9C9212054BCDE745ULL, 0x874F025068DBDACDULL, 
            0xB431E3E8857EDDB1ULL, 0xDFF20E4FEF4863D3ULL, 0x8941B9D2CCDD35DEULL, 0x4BAC835485E6BDD6ULL, 
            0x9B77DCE7BD868E50ULL, 0xFC18D4E4579186B8ULL, 0x1729AA8930E73655ULL, 0x36FC8E1EF5D20860ULL, 
            0x42327CAF8FB53EBCULL, 0x36DC1B6D91A4455CULL, 0xA6273F8DAF60E406ULL, 0x1A864416A955010DULL, 
            0x56F8BA9652417792ULL, 0x49C25836029358F2ULL, 0xD2C62C0593770A04ULL, 0x87A82727EB387655ULL
        },
        {
            0x4AFF13B39BC1A70EULL, 0x02D8DB269BA9AA3DULL, 0x1C839A1746F64E7EULL, 0xC63D9AF5DBFBE216ULL, 
            0xE93339CC1F3BBB47ULL, 0x0CEC9C1829426F8CULL, 0xC1E5A7B13DBF8FB6ULL, 0x0B89DF1D8D4D70E7ULL, 
            0xF3CB9B7864425977ULL, 0xB111E6BEEE1A534DULL, 0x067CB22D4862F8B7ULL, 0xBEBA3627EAEB4E30ULL, 
            0xF80275867F759043ULL, 0xE7E7D65938839C29ULL, 0x9A8C41A7CD60579BULL, 0x5266DC2D1FA06E5CULL, 
            0x6D1C84712846CFA4ULL, 0xEFC45317F3B50E77ULL, 0x9E3F80496B0F52C8ULL, 0x85CAFD7085C841DBULL, 
            0x44325E87FB022F81ULL, 0xBD81C6220F0B4CF8ULL, 0x02BAD437925B6417ULL, 0xF5B0146B8C86EBD8ULL, 
            0x4CF362ACDEBE0094ULL, 0xD927FD6FAB9FA024ULL, 0x811D321A42AABACAULL, 0xBDA660E30906CA97ULL, 
            0x30DAB0D330204A4FULL, 0x85A4685FE304D6D9ULL, 0x2A994D148C54DC32ULL, 0xE377F1615380F549ULL
        },
        {
            0x5BAE232136F12892ULL, 0xE08328325A0AF937ULL, 0x72B321959F3029E3ULL, 0x056831BA3B94180AULL, 
            0x31159341452F2C92ULL, 0x2E705CD89CE6DB9BULL, 0x52E651F783914BC2ULL, 0x71CBAA9CB99FA358ULL, 
            0xEF6E30978BE07439ULL, 0x44C6E8468386BDF2ULL, 0x01F52E0D3A58D05AULL, 0x9022E6478E34AC9BULL, 
            0x29287503DA5EBC12ULL, 0xD879186D781A75ADULL, 0x8D16BCE80B0B92A7ULL, 0x27AE491B7FE06EC1ULL, 
            0x1B78E0B37FFEF761ULL, 0xAAEE4BA143FBBB8DULL, 0x6D38DB87D079F0C4ULL, 0x81D335BD837A93E3ULL, 
            0x6B9BDA4DC101FBB3ULL, 0xA76D456F0EF22AF8ULL, 0x1199847E72D938F1ULL, 0x52A4D2EACD5E2FD6ULL, 
            0xB5ED79B3EDE513F7ULL, 0xC71B9DBB0BAE87A2ULL, 0xC2414C34A6BFEF98ULL, 0x707868F20CB76611ULL, 
            0x32B8F2990F462C4CULL, 0x79C8CC5E87A5B25BULL, 0xF77EDCDF43EC4EE0ULL, 0x1CE7BDFE4A771C99ULL
        },
        {
            0xD34EF40D2DFE860DULL, 0x2213962C0D1D6888ULL, 0xC2BF1E1AE8693428ULL, 0xA2B9BE23C02B2EF2ULL, 
            0x451207C7B2529F59ULL, 0xE56ED27EDB330AE0ULL, 0xD854049F73E6334FULL, 0x37FC5BE563F0FB5DULL, 
            0xA04CC86FA1A47095ULL, 0x4115E7D9CDF88685ULL, 0x599DC82C12468EF8ULL, 0x1CD9FDEC75AD3560ULL, 
            0x68F96B137A47F887ULL, 0x3BDD79118E038794ULL, 0x3F83C1AD92D2BFC8ULL, 0x16B29B733F744AACULL, 
            0x3D2D91648DDB56A1ULL, 0x99F06E8F7F39F0A9ULL, 0xFEB3A064466C39ABULL, 0xC02BAF38858E65F2ULL, 
            0x7C166BAA1DF77A8BULL, 0x8E73AC726C28C7FBULL, 0x59FD917722244353ULL, 0xE16A227A9FC13B0DULL, 
            0x89415E3520BAEB90ULL, 0x9E95AF0891ED18B2ULL, 0x212EEBCC5BD59A19ULL, 0xBBCC17A18E824BFCULL, 
            0xAD0E6AF1FEF3B7E4ULL, 0x92C81F010D7CB4FFULL, 0xA639AF3F0C56F999ULL, 0xA468D04F6E903239ULL
        }
    },
    {
        {
            0xA17E966FA61441E3ULL, 0xF93059FFD34957AEULL, 0x940C80CF76458377ULL, 0xD98F00B6893348ADULL, 
            0x121260C85336E3DDULL, 0x64C85DFC81E74B01ULL, 0xC40CBB6E2DEB300BULL, 0x3D26854AC0745EC6ULL, 
            0x1F0645E46D46D111ULL, 0xA1C42107862EBC52ULL, 0x5AB0A93549311DCCULL, 0xDAAC2C4B62D09A30ULL, 
            0x4C9ED161C61E92F1ULL, 0x06CE41D4C64CC51CULL, 0xE133AEE862F607D5ULL, 0xAC7B7A5C51838AF3ULL, 
            0x6E8F5161633FCDBBULL, 0xD8E011DACE4FD3E4ULL, 0x52464C0C28396C94ULL, 0x5B925327307EA1D0ULL, 
            0x53497EC0E814C1CAULL, 0xF1E424EB31B1A100ULL, 0x071C91B8D9A64D5BULL, 0x7E9227235D59C33BULL, 
            0xBD24A2ACD4427CFAULL, 0x8CC9937A9B8EB8D4ULL, 0xA7471AEC1EFC54E0ULL, 0xC5B4FD2A7A6FE70AULL, 
            0xCC011CE0FC0C2C22ULL, 0xDE09E17FE6C90ECFULL, 0x199BFAA307E69A20ULL, 0xD734CC666F47C791ULL
        },
        {
            0xC866517E68175FD3ULL, 0x210044983A42213CULL, 0xB016CE1E0D595B58ULL, 0xCF8D527E8B2AB320ULL, 
            0xF9799D5DD88061F9ULL, 0xC764DCDF9EBCE9D2ULL, 0xA82761605A78D091ULL, 0x6197C3EED70ED319ULL, 
            0xD83B6DE754745234ULL, 0x140CA6397FA06597ULL, 0xDF62A2E094CDD9F7ULL, 0x51E2898347F007E3ULL, 
            0x5BD674A8F3CA6492ULL, 0x347CD2D7B50988F2ULL, 0x1816306A5F73ECF4ULL, 0x0A6A0DA2F00B79BCULL, 
            0x92E9E55C8E7AB6D8ULL, 0x1810E514B6A0E8CEULL, 0xDF1D3391A7C9F4E8ULL, 0x2C632E0100EFB838ULL, 
            0x670F34FF14994E0CULL, 0x0C00A97169CEA836ULL, 0xDAF4A2BB7B53DF6AULL, 0x6F6FBF983AE5679CULL, 
            0x00B16DB18818A374ULL, 0xA71BDB99DDE3E5FCULL, 0x1CB64448581AE57AULL, 0xEA79A324A0773DDBULL, 
            0xBDC119D273EFF408ULL, 0x6E202578FE3D97B1ULL, 0x03DA6CC5D635C1EFULL, 0xD3056A4CA10DE2F0ULL
        },
        {
            0x57DE4DD4C7C8A720ULL, 0x07E088BC875B6D36ULL, 0xB8549A295A43E8F0ULL, 0x93A5B26D5C4CA5D2ULL, 
            0xD93D3971413A9B4EULL, 0x55283AA6CE883360ULL, 0x0F7745A502F11984ULL, 0xA31A11263CEBC3C2ULL, 
            0xE5145900A95FC7A9ULL, 0x87DEB0A0BC93B559ULL, 0x813169697C902A29ULL, 0xD620A23E08EA289FULL, 
            0x4A218A615C454239ULL, 0x9236629AF5CB5557ULL, 0xB24C4BD0188D76AFULL, 0x823C6E0FD77ECB49ULL, 
            0xE23004ECB97A066EULL, 0xB57F00E221098D75ULL, 0xE65E6D826CDA9B43ULL, 0x4C8869E84A1C97D4ULL, 
            0x918FD0F1EDE30CCFULL, 0xB513CFE1C0E8F3D7ULL, 0x0348FB10DCAF88D4ULL, 0x7B257E09E7CA1BA5ULL, 
            0xE7425804EC3122A0ULL, 0x97DFC3FED3C89812ULL, 0x26725DAF9CBE87E0ULL, 0xA33BC64157C8BBD1ULL, 
            0xC3D25D0F91C3E931ULL, 0x5C4D6C2875433067ULL, 0xAE9A722D96714DC0ULL, 0x03AF6FEBAF546F5EULL
        },
        {
            0xFA1F14BE70449A18ULL, 0x6A14BFBBDF515278ULL, 0x060CD04A8BD7DDD9ULL, 0xE8836742DC0477A5ULL, 
            0x308F06497F49F04EULL, 0x9EC62769A6A29FABULL, 0x74F501C02ABC297EULL, 0xB9FE92BC48854017ULL, 
            0xDAE6B7D38746D216ULL, 0xD56FE5441D76F37AULL, 0x92CE3A29613A00D7ULL, 0x96BE3337E9D09867ULL, 
            0xB2862E2078E6B1FCULL, 0x76399BCFB5165184ULL, 0xB6CC45CAA1E5A3F9ULL, 0xC2451C3B8C16ADC5ULL, 
            0xB49D022E293C685FULL, 0x4296036032B85899ULL, 0x1900ADF219251C09ULL, 0x94ECC6735B664AFEULL, 
            0x247A43B2C74739B5ULL, 0x6EF74175E8E4D7FCULL, 0x455919ECD78DFD6CULL, 0xBE1DE0943AFEB7F3ULL, 
            0x3CD566E2D751865BULL, 0x76F77213DBCE6BCCULL, 0x7014C1BB53494EEEULL, 0x812FAADFE93BAC1AULL, 
            0x635D2E3EC2F99077ULL, 0xFE23F8A856527056ULL, 0x9E12AE33E9E700CFULL, 0xCB4E9A1E8731613AULL
        },
        {
            0x44CCF307DD24C409ULL, 0xB262FD8D527C08D6ULL, 0x35D96F389B548F35ULL, 0x65BD14F068C76E39ULL, 
            0x712D1D245C26CBA4ULL, 0xDADD56100FBE7154ULL, 0x54752A124C4A8AE1ULL, 0x9B63FC7C5E8D540AULL, 
            0x72521D7961483E2BULL, 0x3BAF49B7881588F8ULL, 0x5F83406B41091B9DULL, 0xE849DDF295DAE549ULL, 
            0x9C286762186F5AA6ULL, 0xC415AC2380730DC9ULL, 0xEDE1D0A830BB52ADULL, 0xF9A52AECB2E07D8BULL, 
            0x0190E10E28FFDB1BULL, 0xFD0A3A55F78A1BD4ULL, 0xBB2D66B619812530ULL, 0x1EF0F161DC5A5050ULL, 
            0x9A57FB98DC678097ULL, 0x39AA8DF39BA66AC5ULL, 0x27E314881D4D6A3AULL, 0x3408CB707CEE6C87ULL, 
            0x4E7C5757871071A7ULL, 0x7FFA653B839DE2B8ULL, 0x7E4F416CD8E0A898ULL, 0xCC52F953BAF95CF1ULL, 
            0xCDCF745EFE9A180DULL, 0x0F9ED1498D5F107DULL, 0xDB26F964E419C5ECULL, 0xA0C6C2D3A1411BD3ULL
        },
        {
            0xE7C9957A5D8FE1B5ULL, 0x3127ACC3DC265035ULL, 0xBEC7BA9B426FAC4CULL, 0x9EEB89066BFB79F2ULL, 
            0x95E611BF5F77C3A1ULL, 0x8C99F10A296D36A2ULL, 0x2DD2664F3496EEAFULL, 0x8A6D2B01FF88BC81ULL, 
            0xB5BB566CFD68DE5BULL, 0x1CAFF5BDF8701F6CULL, 0xCAD69D16AEF94046ULL, 0xBC4C4F38A4744037ULL, 
            0xEE32EA3E72865142ULL, 0x6E150F22407684D4ULL, 0xE7EEE30E7FC00D8AULL, 0x5BB3BC5752F921C1ULL, 
            0x6B6BE68A44759F53ULL, 0x4EEE044AE48FCEEAULL, 0xFE61EBAF3F72C8C6ULL, 0xD42CDE5D7CF9B0C4ULL, 
            0xB5D2D841844CE070ULL, 0x2189994B94A5046FULL, 0x4727932315452B41ULL, 0xD692FC0EB75498EFULL, 
            0x6DD08B856B271D75ULL, 0x4E109B48BE739BF7ULL, 0x3F80FB3604FFEFDBULL, 0x0B84B3907D60D9CAULL, 
            0xCAB236E53EC6B6C5ULL, 0x1DE3379702162534ULL, 0xD0D6D7A251C5E63CULL, 0x2277A25D69F8AA37ULL
        }
    },
    {
        {
            0xEA266E841CD7AAAAULL, 0x089F7F6E3601AB4FULL, 0xDA07E7A2F68D2F1AULL, 0x5757080A3392E0DEULL, 
            0xF9EDC89477AB88D8ULL, 0x0AF409E2AF103957ULL, 0x862077C669948C15ULL, 0x1BB5914A0003FDD7ULL, 
            0xB78DA8F5B3A69A44ULL, 0x04BE31E9D28929A8ULL, 0x6DEB3A341BC28704ULL, 0x18E248E30F93BD45ULL, 
            0x08713634C0C3D351ULL, 0xFDAF472D3AFAF6C4ULL, 0x8E22BECCA9BEA819ULL, 0x5636AC55C85AF311ULL, 
            0x5C3BD2E353EC1014ULL, 0xFC0252E77EB009B5ULL, 0x3658F9C755B80406ULL, 0xE89588A40773E8B3ULL, 
            0x92F52F5BF81CACB3ULL, 0xC0C01D8143A5E482ULL, 0x7CAC38072055F931ULL, 0xD686F3EB74459EC9ULL, 
            0xC16312DB5E796CACULL, 0xF5A5F19693DBED56ULL, 0x940384E42157156AULL, 0xA7A3AA5CEF739E73ULL, 
            0x781C6069F773FBCEULL, 0xB0E141EE349C9DE8ULL, 0xC9793678A8DFF226ULL, 0x72C89A9316F33E2DULL
        },
        {
            0x5478707A559B481EULL, 0x2B3997C19C90C663ULL, 0x8401FD7681D0A4BEULL, 0xF4EA9D0584664BF7ULL, 
            0xAE00D44AD1B2C18FULL, 0xE3E452D820C9C6E6ULL, 0x3517B19B0A7B54CEULL, 0x4140AEF79E6E8ED7ULL, 
            0x9FAAAF04DB8CE2DEULL, 0x930AFC534F9451E2ULL, 0x2D55031FBF47EEC5ULL, 0x3A14FFC3ABEF237EULL, 
            0xA165DCB2462B6307ULL, 0xB8612269CA786032ULL, 0x92461644F8FE4986ULL, 0x8E566C7531D3893AULL, 
            0xBBE3C53FB3614B88ULL, 0x7025615C656AE425ULL, 0x75B7EA5369763CF1ULL, 0x66E3F23F52CBEE8EULL, 
            0x025262972A79595CULL, 0xB203DF581AC8FF05ULL, 0x04C51977D4EF900CULL, 0xB69B16553241C5CAULL, 
            0x975FA5086C719E84ULL, 0x66DB3FBA3C657A0AULL, 0xE5DE6AA7C3EA62B1ULL, 0x502913300D25B04CULL, 
            0xFE16DDF399C668B9ULL, 0x70C4B2A936A6E95FULL, 0x7BFC71DD619953F4ULL, 0xF741A4FE6D976146ULL
        },
        {
            0x58FA8DA586E7EEA2ULL, 0xA1F62C80D3EBC540ULL, 0x0B89A3C29C842C29ULL, 0x11E3DAF03E01AAC6ULL, 
            0x45CC8E4AC47D3C8CULL, 0xC7143F7E8E852826ULL, 0xCA6F6D59CFFF2233ULL, 0x0DF108AD56B9A932ULL, 
            0xD8C844F0CA5C82B0ULL, 0x0A3745CB19EC259AULL, 0x33693A4863157306ULL, 0xB3ABD10255C3ECE6ULL, 
            0xE93646BBE0F46DA9ULL, 0x90CFB9D736D5067DULL, 0x8243D06AA08EC69BULL, 0x6C06BDDC59586774ULL, 
            0xC4A0D272992CB534ULL, 0xCE18B31F8997338AULL, 0x6B048AADD40B1766ULL, 0x9364751B1D33AF31ULL, 
            0x543B6FE726CE3344ULL, 0xE32610439C7D2B24ULL, 0xA164951722C16D9DULL, 0x64E7B2DAB978A406ULL, 
            0xE3E8D1A4EAB403CBULL, 0xF88D5BB56C0A226BULL, 0xA33D24871CBF1D25ULL, 0x09480CCED3B86E7FULL, 
            0x5DAF16793D9F7CA4ULL, 0x75BEFA33461F3FBCULL, 0x578248F8E41F3FAEULL, 0x3D58D82EA7D0D912ULL
        },
        {
            0xF5E551F07C1DF204ULL, 0xC3778C75FD1386AFULL, 0xF2FBED4B5AB3C264ULL, 0x68E188C67055D1AEULL, 
            0x9001E122A0A0F678ULL, 0x54868EF5EE9F9A8CULL, 0xF992ED44C8848B79ULL, 0x49D768E733FFB6ABULL, 
            0x1F5CB31D2C2E1A4DULL, 0xE617B6705D34B0E4ULL, 0x110FA2D29FE2887BULL, 0xEB2F10CB48B539EFULL, 
            0xFE4F452AFA14A8EBULL, 0x606725ACEE4ADBBBULL, 0xE62DD9B36D3EB0C5ULL, 0x8D577D55220DD9C1ULL, 
            0x936D135377ADBF69ULL, 0x9111708A3FC34BCEULL, 0x0456DB11AA97CFBEULL, 0xF22CB365FC5FA4CDULL, 
            0x09711B8F7A0874F9ULL, 0x36CB2E9E286D7717ULL, 0x0A6070AE3C4D09A2ULL, 0x6778DF3F0255CDABULL, 
            0xA3C6FEB5F6C3A43AULL, 0x3B156BB305B0313DULL, 0x36C53FAE14791C18ULL, 0xBE4FB4D0EABF719EULL, 
            0xC4415B7457726C41ULL, 0xA53443D2AC6BA019ULL, 0xE3DD42B976414869ULL, 0xCC0638006ECBC7E9ULL
        },
        {
            0xD541FB081FC912CDULL, 0xC65028C0A2909F78ULL, 0x47C55F955AC86EAAULL, 0x075E73685512D3BBULL, 
            0x9DB75240CD19B24AULL, 0xB204568DE8E99E74ULL, 0x69C676411A5CE65CULL, 0x29D74CFB33C7FCB1ULL, 
            0x9EB9E6679C297A21ULL, 0x74C31BD3F321C1AEULL, 0x9E1F0C9D4368A49CULL, 0x5C9F5606CFCD9AA0ULL, 
            0x05B428B98F7423AFULL, 0x9D51DF68198CA7F7ULL, 0xFF7AE3ECC3BDCF48ULL, 0x8E3AA67DC5D9450AULL, 
            0x99E681A733AFED85ULL, 0xA86F1FA6F4741662ULL, 0xC3505CD39D6E992DULL, 0x82E996B6CA2E5586ULL, 
            0xD13E99DD4C51A88AULL, 0x335D729F79B622DDULL, 0xDB556D68672BF350ULL, 0x4253D4F8F4F88E88ULL, 
            0x3CD550166630A638ULL, 0x54426F18F80BA63DULL, 0xFD75E5AD641506EEULL, 0x2FC680C8FC4A492CULL, 
            0x2D9E04DDF314C80AULL, 0x7A729577C537FC51ULL, 0x1AA3CA28EC31AA0BULL, 0x7EFE76CA7EAE7B40ULL
        },
        {
            0x64D9D236A143CC9FULL, 0xBAB89C553CD8A5A4ULL, 0xE99CCCBF8FDA1E11ULL, 0x147FB51714C1C2C1ULL, 
            0xA25128F18DE802AAULL, 0xA647626F3E37A250ULL, 0xE6D7F4C63558EA98ULL, 0x66A286C7CD1F70E5ULL, 
            0x4049446703E7B94AULL, 0xFE60FB8BADEE5191ULL, 0x53B5044BBA6DE517ULL, 0xE8953AEB38FC37E4ULL, 
            0x9D2C0BC3A4CB6285ULL, 0xC5DDBBDBC1A4B560ULL, 0xAC2D22837272408AULL, 0x33BC71AE235284A3ULL, 
            0xF696B449670DB112ULL, 0x002A1C22ACE8C429ULL, 0xA77035334ED0A270ULL, 0x21CCB2984E077782ULL, 
            0x9D239905AF696778ULL, 0x4B4C0F87AAAC3BB1ULL, 0x0B9A09E4865F2EF1ULL, 0x745A6D228293020EULL, 
            0x74B4DF5760AD48BFULL, 0xB276A62ECB8325A8ULL, 0x002D3680C79D02E9ULL, 0x7DFE452C17A5E744ULL, 
            0xDFCA34FF4F89E948ULL, 0xAF1796DDA8AB0740ULL, 0x6BA6978669C81AE4ULL, 0x3335FD341AB9B3A2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseGConstants = {
    0x4DB6D0912570C7E9ULL,
    0x65718643EFB8A08FULL,
    0xC7050D01FBE2BBE0ULL,
    0x4DB6D0912570C7E9ULL,
    0x65718643EFB8A08FULL,
    0xC7050D01FBE2BBE0ULL,
    0x604F1AA060FFFFA5ULL,
    0x872CB2A11178C6B4ULL,
    0x8F,
    0x33,
    0x40,
    0xC7,
    0x7C,
    0xF4,
    0xF2,
    0x37
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseHSalts = {
    {
        {
            0xF1389E4AC33BFC1FULL, 0xA450A4D1DA6200A8ULL, 0x44D5F2B626D53DD4ULL, 0xDD17A17FC985879CULL, 
            0x59ADB0F80441C4E3ULL, 0xFCB56D7E1DAA8E9FULL, 0x843C21CD861D3A4BULL, 0x5A2F27CE6745BB30ULL, 
            0xB43F8054AEA486A7ULL, 0xDA9FCB78E88515A1ULL, 0x43402DA8650EDEC4ULL, 0x5A7037ED5A44E285ULL, 
            0x299AB3F1BB40317EULL, 0x1FB11CFECA614A66ULL, 0x0CBC1B9D912051B0ULL, 0x8F22D7F51C1B6BA3ULL, 
            0x1126D8695AA7F644ULL, 0x2E1696851C92ABD6ULL, 0x9FB3C3370C925272ULL, 0x3B60D12FB9A3550CULL, 
            0xDE85EBE148DFB105ULL, 0xC17D9BB7FFDFB15DULL, 0x418F09462BA0B9C8ULL, 0xEE11A13B510CD22BULL, 
            0xB738F44C9EFF9BF5ULL, 0x9AEDBD4A50EFA4BCULL, 0x62B75C53989A6262ULL, 0x1B56498781E1D66AULL, 
            0x71B96C1AF3F6280CULL, 0xCEAD1E77367C8240ULL, 0x16DD542B2792E563ULL, 0xF21703FA6D39D14EULL
        },
        {
            0xD16ED7009F9FE4DBULL, 0xAC2CCA0BC4916E42ULL, 0xAF4D9C191D03635DULL, 0x2459322ECD62BE27ULL, 
            0x36B20D0EBFF460EBULL, 0xDDC4FC5A03D15036ULL, 0x175BDC2E75B207E0ULL, 0x9A0048D0186FDCB6ULL, 
            0x789E0C367402755CULL, 0x09B8B1B5CF565D25ULL, 0xCAF9BCF1E77C9613ULL, 0x5CCACA878AC48B32ULL, 
            0x571B8EC5CF415CF4ULL, 0x498E4C0CA97DE70AULL, 0xEF44176E92314A88ULL, 0xFDB50E185C6E4C74ULL, 
            0xA39AAC89B0B8FC15ULL, 0x8EF2221DF0AD83ECULL, 0x39643E7D41818DACULL, 0xF0630E2588F039D1ULL, 
            0x027570631B05EA8DULL, 0x6DE942F7E3B48432ULL, 0x6BBCD101D5979AD0ULL, 0xFC08F1EE3B44D7BCULL, 
            0xD653EBAD3C0A0816ULL, 0xA70B7AFAB63B775AULL, 0x04EC773C5ACA91C3ULL, 0x6FA8CE826912067EULL, 
            0x07169B8D84C6AFDFULL, 0x91118B5B6BD03FA0ULL, 0x1D430C823A537C37ULL, 0x3FC1B75D7BAD8F2BULL
        },
        {
            0x1535EF8D1D7AA2ABULL, 0xA4E54FD1B569602BULL, 0x7E3B388F153907F3ULL, 0x25723C3CA39F1BAAULL, 
            0x806AF71BE5B8F25BULL, 0x4A4D1AFB861EC14BULL, 0xD5598DC853F33E0AULL, 0xF0D479368C493961ULL, 
            0x6D08647E86661313ULL, 0xE612B999D878CBF1ULL, 0x5ADAE293968959ABULL, 0x118C2B2768EBC244ULL, 
            0x007D0ED8D8B892CDULL, 0x6B4C71B3FCB25CABULL, 0x8E0A5F2AAA39AAB4ULL, 0xF360E26DD3F7A927ULL, 
            0x74BE93BA06C9BC79ULL, 0x6B2FBEB4612C7D3DULL, 0xD89487C226C7BACEULL, 0x887B5376EE8E52AFULL, 
            0xF32F52D6CAADACB9ULL, 0x8F91A08C222BF966ULL, 0x67C7D347941BFD9CULL, 0x28CEED46BDAE5797ULL, 
            0x1120887D9390BD4BULL, 0xC236A750F2018D66ULL, 0x362D2EFA20DFEE36ULL, 0x335CFBF03BBE8A3FULL, 
            0x4D8EF7CB71E42DC7ULL, 0xD6DC0BDA12735DC3ULL, 0xDFEC870EA17F967AULL, 0x8498528659C95F3FULL
        },
        {
            0xF6680FE20617A812ULL, 0x3B34BB6451817E73ULL, 0x0383AE6CA2F6EEC8ULL, 0x4F0C4227A89E7C44ULL, 
            0x10CDB4662269FBA4ULL, 0xC64D79837432C54AULL, 0xBAC08C7442668A10ULL, 0xF9E602B5448D316DULL, 
            0x3A76470BE80D62AFULL, 0xEC03EEBB2914FF5CULL, 0x2738B7A61E58E75BULL, 0x8462A53D5BCDC16BULL, 
            0x2992B161D8733BF7ULL, 0x52148B9EB44D6F5CULL, 0x5F365C2C824FAA76ULL, 0x4B06369609C5A93FULL, 
            0xA36BB13D514588BFULL, 0x4FB78C512740C67CULL, 0x9ED1A1B8D9B99906ULL, 0x9BA554E6CC611F68ULL, 
            0xDF331DD48B3B36E4ULL, 0xEFB3854E2FA84E43ULL, 0x26C87417B546E7B8ULL, 0xE361C6AFABB2B223ULL, 
            0x8044EE221A40F082ULL, 0x66D527F3DF2B3937ULL, 0xDC7AA9807281C91DULL, 0x894E1C91EB178BECULL, 
            0x0AC926F9F42FE50CULL, 0xE2DD35E07B3197F2ULL, 0xEF61BFAEDD0B6C19ULL, 0x3FB3AE3252E31877ULL
        },
        {
            0x824A77F14A9BF5ABULL, 0x9F0A851877E83B04ULL, 0xFA9A6A65BD4660ABULL, 0x80401EC15514BE6CULL, 
            0x6FC5BDF66F09F61CULL, 0xEEAB1A97FDAA5386ULL, 0x8D42D18347A3AA75ULL, 0x5FA967DBF9D89E73ULL, 
            0x14BACF86476F5ED1ULL, 0xE0F69FC8372F55D8ULL, 0x0A44B730D840806CULL, 0x7847EF7A45D615BAULL, 
            0xE858E5DE064214F2ULL, 0x67EEE871A1941106ULL, 0xD433C628F016D696ULL, 0xC600777F95D89ECFULL, 
            0x61D669AA446438F9ULL, 0xB78A8CD2448DEDE8ULL, 0xF58CDEDF1D94446BULL, 0x1923A4F4AA1AC93EULL, 
            0xE3318C226F1006A2ULL, 0xEE89208C343B4FD0ULL, 0xE93B13B0963AC59CULL, 0x0F4915B396FB59B3ULL, 
            0x48FD3A7DDB1E62CAULL, 0x0C0087BA51FBB36DULL, 0xB0F7BAA2D5EEA36EULL, 0x3033A94EE044AE6BULL, 
            0x8F313741EE5526DCULL, 0x1047054269070D54ULL, 0xAC01E2B4BC9E7EC8ULL, 0x38DC2D646EC11738ULL
        },
        {
            0x806EEB18C4C23915ULL, 0xD6886EAB2675AA2AULL, 0xAFCDD99E764F76EBULL, 0xD749636A91E958AEULL, 
            0x1B81F486DA0874F6ULL, 0x70C4EBC6353A6F3BULL, 0x251033245633CD7AULL, 0x6F27F99994527319ULL, 
            0xFDA0F3818B0CE247ULL, 0xDD3F5E2E6D70A15FULL, 0x542BF904DA9A284CULL, 0x8F896B7ACC14EBF4ULL, 
            0x645E408A4B6C8FE0ULL, 0x8C4267C8BD30C389ULL, 0xD79682DE4118DF80ULL, 0x5FFA7E4706C167E6ULL, 
            0x7C03F678AE88820CULL, 0xCE557DFDCCFE1905ULL, 0x48169E0ED7C02BB6ULL, 0x0F01C4E8CAEE1F09ULL, 
            0xAA9E5F6C3D266A6FULL, 0xAE1C27414023E131ULL, 0xF6B522635A0CCC1EULL, 0x1857F10148BCA3C3ULL, 
            0xE988DAF177B12653ULL, 0x52C6428896CA5F64ULL, 0x85DBA237D58151AAULL, 0x2E82A18C59D2D514ULL, 
            0x3DFFBCC2577B347EULL, 0xA7CDCD0CA25190C7ULL, 0x44A792CA8AA3E963ULL, 0x6D744437B2FC7331ULL
        }
    },
    {
        {
            0xFD3F8F73E1D816CAULL, 0xBBE16BF371A65EBBULL, 0xD2EFE8827C5BBC87ULL, 0xFD11B4900D72D24FULL, 
            0x4B71438152855D62ULL, 0x2B599B9B158DA92BULL, 0xB63B335DD718BC22ULL, 0x43539FAB8A82F3C7ULL, 
            0x437872D67F40BF48ULL, 0xAFF9556AAE9C10ECULL, 0xA992C94C37F1AF07ULL, 0xFAE9943E98E2B168ULL, 
            0x586F2C92F96B9721ULL, 0x23670308A3351959ULL, 0xDB80753C2EE5EF23ULL, 0x8B81F763288CDF0AULL, 
            0x6ED01C1A98CADB91ULL, 0x9809706095963F92ULL, 0xEF37D8552F922368ULL, 0x2D46EBA6B4FACBC4ULL, 
            0x79A3D5A5D65AD168ULL, 0x4AFB5CF6D6D66856ULL, 0x920BE1369E8609AAULL, 0xE6F428C267BCBF1AULL, 
            0x98F45E9D73761223ULL, 0xC5148FEE56418C93ULL, 0x0EC7AB27EBDEBB76ULL, 0xBA0C6FA2EE633403ULL, 
            0x7A24E98B422119F8ULL, 0x9017F271D8DC68C2ULL, 0x04251D493BCC7D1EULL, 0x3D7085D19CFCBEFCULL
        },
        {
            0x7E436351BA116890ULL, 0x78460AAADDE8CB52ULL, 0x0D4B1FF091FBAB2FULL, 0xCF5832C5D68BBA7BULL, 
            0x376E5DBF36C52E8EULL, 0x1757089912E916C7ULL, 0xF62051E1B4282C22ULL, 0xE91CDB9C59770DECULL, 
            0x3295AC5B140C24FAULL, 0x11924FDEC950D492ULL, 0xD111DA051D48B7CDULL, 0x97DE556E9A955E94ULL, 
            0x28F20894B1F6928CULL, 0x7BCC3CD20198EEAFULL, 0xDCA3962A130CE7C1ULL, 0x815FFBE6E15B95A6ULL, 
            0x9ED51B522A5C48E0ULL, 0xC40777FFED32A875ULL, 0xC15D8413B2C1AA44ULL, 0x40EA21F0093037FCULL, 
            0x6179B3064AC7EBDBULL, 0x788BAD4245F5FF97ULL, 0x66C0309E37BADA05ULL, 0x4EAAACADEE3D3D05ULL, 
            0xEA14C96989CBC247ULL, 0x538D3C381F68186AULL, 0x1A7A02CDD7891679ULL, 0x79341F4AAD04A088ULL, 
            0x54FAD48720B92B58ULL, 0x4F67F5DAF734B33FULL, 0xADE615B5BF958A80ULL, 0x82D214A687342BF2ULL
        },
        {
            0x5E1FD4B5B5FA406AULL, 0xBAAC0AE3F59CAF70ULL, 0xE6B71138C3312380ULL, 0xB78CEC89108494EEULL, 
            0x021CDA5C0BF79907ULL, 0x3D7A0643AE78856EULL, 0x7C52D8048F9BAF8CULL, 0xA3DCC6CC238BE3E4ULL, 
            0x616D22F15C098563ULL, 0x8A4284F47B6CF2E9ULL, 0x8D902B4B3A3489DFULL, 0x525DA89538F4E70FULL, 
            0xE3C02313680284F9ULL, 0x3551089FDDE62537ULL, 0xC9BE01E5C2E982C6ULL, 0xF33D10FF911BD9D6ULL, 
            0xB5578588936ADBA4ULL, 0x5D00FD3CE8E15CE3ULL, 0x835F703EC538EE2DULL, 0xB7509B56A05ACFE0ULL, 
            0x81CFF0C13B19E4E8ULL, 0xB01CCC8871221264ULL, 0x4F7D66BCC7582008ULL, 0xE3930EC5B1F54D5FULL, 
            0x34000195B5992D02ULL, 0x335C2EBDE50869B2ULL, 0xC45FA27E204576D9ULL, 0xF759CF468E2481E9ULL, 
            0x1FE3D3E586ACD93CULL, 0x407DCA69D8898BC1ULL, 0x8EC4FF05776390ECULL, 0x47F93A5FDA8BD028ULL
        },
        {
            0x5BCAB6B5AC32B0ADULL, 0xA868B43254EC04F9ULL, 0x1000D9B9C5C9A1D0ULL, 0xC808D31E8FCEFB2FULL, 
            0x67E0144A02BC1092ULL, 0x4FBAB38FA48D07CCULL, 0x68918B577E59F446ULL, 0xFF6AC8FF0BE8D352ULL, 
            0x1BCE6E3F5CD5A4DAULL, 0x79964D05D9C7B8BFULL, 0xFE9ED02C06B80A56ULL, 0x3DECD1DEDAD73742ULL, 
            0x620B3734BF949394ULL, 0x1EE2FEB11FEF229EULL, 0xFD18DE515BA9248FULL, 0xDBEA1FC64135AB67ULL, 
            0x8A21B8018A526773ULL, 0xE8D935128209E0CCULL, 0x40F2E38C33E622DEULL, 0xEF46A3CFF099C34AULL, 
            0x380CED0501B00219ULL, 0x7479326704B5AD99ULL, 0x9B69F7C8ED356714ULL, 0x6FD66B6571063362ULL, 
            0xF0C44047703C9BA9ULL, 0x1FB7431915212330ULL, 0x5902E11142E04BB4ULL, 0x2973AAADE970E439ULL, 
            0x4CFC652613C73C27ULL, 0x382B561909B2A0A0ULL, 0x65DD9B9D540CB047ULL, 0xD35E4A674EEAD195ULL
        },
        {
            0x83825CD787C7C51DULL, 0xC8DB42BDF134A9CAULL, 0x4B065C0B6F496068ULL, 0x0E5469D8806F1CD2ULL, 
            0x76EA79D42BE0965FULL, 0x6ADEEFDCAD7E2CA5ULL, 0xDBA6A98E947545A4ULL, 0x6D09F2333C7245A3ULL, 
            0x0F006DE24DB8E4C6ULL, 0x8EF12E1134BB2B96ULL, 0x70CAB4AD90D3DE64ULL, 0x47C64FF2663ED8BEULL, 
            0x3F03C249A465F0EAULL, 0xA310799819A3CAAAULL, 0xD7C32960B26986AAULL, 0x214C97B08E5EE56EULL, 
            0x799495754009E04AULL, 0xF0B22D3E44C99670ULL, 0x9D339EF2D3BF86ABULL, 0xC5F2475851B7B792ULL, 
            0x8E6B61412236890EULL, 0x237E9CBC89BB9A34ULL, 0x7C2C6F4A703E6C59ULL, 0x419D29D30E38F919ULL, 
            0x79B945E2503696C2ULL, 0xCCF85B3EE2FE372FULL, 0x462E912806312422ULL, 0xF93A45DFACC7AC79ULL, 
            0x5F7939C137987F8BULL, 0x937CE71590DC3E35ULL, 0xEA2A62F4C27772A7ULL, 0xD577686BF8D0014AULL
        },
        {
            0x1F56187B6AEF4F9BULL, 0x77E101592B72655DULL, 0x2E1027B5E0DEAB96ULL, 0x646DB79B9C3F04A1ULL, 
            0x3714822FB3F495B5ULL, 0x80D93E1F9F716800ULL, 0xCA7FAD58FD30C9F0ULL, 0x5D7757A93BD2D48AULL, 
            0xB4467A229F383484ULL, 0x06255F0D222036D6ULL, 0xF1C03DB3FC396028ULL, 0x3358666B453AC014ULL, 
            0x6FC6DC682FB5D077ULL, 0x4A6A028EFA1ED282ULL, 0xFC0CE06249B20107ULL, 0x06E4EB5122DD8354ULL, 
            0x967DD95BA33C3146ULL, 0x197F4467F9A23C90ULL, 0xE03CABEA2837E934ULL, 0x5D799AEC1A5A01EFULL, 
            0x45F863065E9DF407ULL, 0xF137E2F7AD9751ECULL, 0xDBE19F57FD68EFB2ULL, 0x7397B2544DBD731BULL, 
            0xD60F9FD121733511ULL, 0x1C2DBBDEF06C988FULL, 0xFD8D78924C0E647FULL, 0x41B9A8FAC2EA0877ULL, 
            0xC8D0A7F15FE590CEULL, 0x6E991E5ED70E6970ULL, 0xEC3B8BDE27CAEA52ULL, 0x0D659C604AF73BCCULL
        }
    },
    {
        {
            0xA0D20FCB7280B7EEULL, 0xD79748AD57DB586CULL, 0xDDD30DA7E2AD93E7ULL, 0x2681D7529193646AULL, 
            0x3810BCD5B7F44D09ULL, 0x5027D977908B5170ULL, 0xE3016BDBE917A0F1ULL, 0xA1EDA79C05F24AEFULL, 
            0xA1489AFD751DA13CULL, 0x24302AFEB68E4151ULL, 0x5612A90464755508ULL, 0xF99D1CAF47DD243AULL, 
            0x3EC9D380E0AF3DB5ULL, 0xD0F9C9279081BB3BULL, 0x1F8D8E4EBDE1D029ULL, 0xCCC8F202F1A536DAULL, 
            0x370104BDD34C09F2ULL, 0x65D6F9E2D80E5783ULL, 0xAF09AC0B79C49323ULL, 0x65C79B52486AD7B2ULL, 
            0x115F59662D66B650ULL, 0xCEA220B5A1F8BF7AULL, 0x728776E1525E4C13ULL, 0xB63C35A18565EDB7ULL, 
            0xA0FA813DD8602F7CULL, 0x59DDB627D902E43FULL, 0xB31381F56A07ECBCULL, 0xE131ACC900912A27ULL, 
            0x3ED9B9210C9F3120ULL, 0x109CD51E94B4F752ULL, 0xBEB4E394FC033E1DULL, 0x043804F5AD1C5FC2ULL
        },
        {
            0x5E8CFCA96DAADDE7ULL, 0x306C2F8870ECDF7BULL, 0x3BD460A80F807089ULL, 0x016CFD61ED3A06CBULL, 
            0x7CA5BAB645FE5E2DULL, 0x0300CC0076281B61ULL, 0x3E6654AA63BFF317ULL, 0x3793963AF61AA6CFULL, 
            0xDEB81FEFD5FF05E0ULL, 0xEC7B344FFA74328FULL, 0x6DA452B4A4FDD181ULL, 0xE0296E2FD8416B13ULL, 
            0x8C7436599FB9F6A2ULL, 0x7FBE796EB0DC10F4ULL, 0x9BD363ECB85C5537ULL, 0x626903099F631C86ULL, 
            0xE2FA0F06D6BD830EULL, 0x6C0CF7AB294F0B24ULL, 0x1FF6DACFB560817AULL, 0x9218F43CFEBC4B42ULL, 
            0x7F1803E278D3851DULL, 0x0E146EF6A3787FC8ULL, 0x370376AE9CA78D70ULL, 0xA18066BC04122063ULL, 
            0x7F7DCD0477C2BD13ULL, 0xB9BE91F1F2E2FB5FULL, 0x18E6E0AF95B54C61ULL, 0x052FFF92EF4C56A0ULL, 
            0x5AD0ED7FB65C2067ULL, 0x60D6F32807AAE0B2ULL, 0xE38BC0256FFFF2FCULL, 0xBA4415B2BFCB972FULL
        },
        {
            0xD500BDCEC8FC6CC0ULL, 0xA081FBF73199E093ULL, 0x67517189BFDA8AFEULL, 0x37A86740B000EA58ULL, 
            0x171843A174CCE50DULL, 0xF047635D97B86A0EULL, 0x9C84A8E05BCDC12CULL, 0xF6481ABA83C770D4ULL, 
            0x5D198CC332C817E9ULL, 0x16684B4D53F8FCDAULL, 0xDA61704721460629ULL, 0x185AFBF6C90989C8ULL, 
            0xC0F652AB639EDEE2ULL, 0x648199EA485B0338ULL, 0x7ACCC5BF460826ECULL, 0x80EB651515E2C761ULL, 
            0x37419C8DAA0D93FAULL, 0xB7FA9FC63D503515ULL, 0x41979B74185F7822ULL, 0xF877731B00201FC2ULL, 
            0x3FD9C4553B2D83A6ULL, 0x6EDAE537695E9C4AULL, 0x75EBB8DBF0218B10ULL, 0x198B7B5D7EF13186ULL, 
            0xE22457A166756582ULL, 0x751AF445A3C4876CULL, 0x0749CA43A54FC8B9ULL, 0x65DEC8E16106B414ULL, 
            0x129EA6E873C6F038ULL, 0xC886E7C0D3D0335BULL, 0x929034BEF508E888ULL, 0xBE9CE25F8A81E160ULL
        },
        {
            0x10C86DE4958BB894ULL, 0x4F7CD03627C30200ULL, 0x72810E8DFFFA6F68ULL, 0xF9BF2EA30CA721C2ULL, 
            0x54266390B1756832ULL, 0x5E4625D4F5587A6EULL, 0x2E252C0DB7D3E7F6ULL, 0xE9B4DBC7360F1ACCULL, 
            0x0C95C4556DDAC6B3ULL, 0xC5FE86075771D83EULL, 0x5A144D7A7FCE9EAAULL, 0x0AF59A1873E7434FULL, 
            0xCB9C934F0A2134A6ULL, 0xE34F6EEC6155891CULL, 0xEA5F552757CBE400ULL, 0x444166684832DA9AULL, 
            0x676A1E6D446C122AULL, 0xADA382F540175042ULL, 0xA72BCEEDBDFD61E0ULL, 0xE79A5326A9DE97C1ULL, 
            0x3BC2737A767BAB86ULL, 0xB5CB087D60645095ULL, 0xA8D5B7AC2AC492B7ULL, 0x88FF599C931FD5F9ULL, 
            0x16DFB7DBD3FD4142ULL, 0x09A37E9BC4A4A3DCULL, 0x203FEEFA26B7F9C1ULL, 0xE1649C6F9B1C1E41ULL, 
            0xE670BF07BABA6DF9ULL, 0x3A9FF9CE75BAD924ULL, 0xE4CCF5782B368E4FULL, 0x4BC4E57B8404BAD4ULL
        },
        {
            0x259C3ABFEB7749C9ULL, 0x3BA9D72AFEC5C2F5ULL, 0x947C70D9D639415DULL, 0x96C8FAA67B5E4FB7ULL, 
            0xEE6E0DC9E842AD96ULL, 0x9820A632485A3ACFULL, 0x5FF5352506CB9740ULL, 0x9AEBE4EC156735C9ULL, 
            0xA05FA076876F8BF2ULL, 0x43C46F42E82CCDDFULL, 0x94AD954EF9478764ULL, 0x5C58076AA6A9A8FEULL, 
            0x0E3010409441000FULL, 0xD10E54C05D9EB918ULL, 0x957DEDE1D8454B05ULL, 0x464D57616BDCD7D3ULL, 
            0x03C45C6E863968F5ULL, 0xC491BDBE09D5A162ULL, 0xCB7ADBC0C2230BC4ULL, 0x21066A153E208D23ULL, 
            0x7B74CC50A6F12417ULL, 0x5FA29F2EF5AC1AD2ULL, 0xB76FF3D47EA3A67EULL, 0x0A997AC802EC4464ULL, 
            0x8404EBEBC7C845CCULL, 0x403D4E5D61003E62ULL, 0x43002A74BB5D3F73ULL, 0xDB8C75AB928DBF3FULL, 
            0xD10C4863F48A8704ULL, 0x50F2D0ACB985B536ULL, 0x547724CD57307685ULL, 0x00FD4992EBD325C9ULL
        },
        {
            0x1F6EAADCDD76D8B8ULL, 0xCC130888CFF4944CULL, 0x3723E37A85DEEDE3ULL, 0x6D8F3BBDD193E429ULL, 
            0xCB2B6D233EE93C1CULL, 0xC6587E9ACEC5D813ULL, 0x9C2483327C6191AAULL, 0x222249E18B0001B3ULL, 
            0x1EEF9C01A70A3370ULL, 0x3F2FF6B3C20D87FDULL, 0x55D89BECE0B0739BULL, 0x71551B47804C3FB0ULL, 
            0x3F378E0A7632EB25ULL, 0xC7FC11B7F9EDA06AULL, 0x039D9B4D05929521ULL, 0x5289CEDA2FABB734ULL, 
            0x0E44D98897E0C970ULL, 0x9F25457773B14026ULL, 0x2F1ADF7C394B038CULL, 0xFD693317883E87E3ULL, 
            0x75AA5B29423B4A79ULL, 0x15FB8DBFD36D7878ULL, 0xBB81DDE650897193ULL, 0x7CA6F2F76BFCF4BDULL, 
            0x6F261579D8C6ADBEULL, 0xEFEA8BC177D96E92ULL, 0x280B6ED82E7017CCULL, 0x7C9DB2900ADDD34AULL, 
            0x7E3F87F0635D0334ULL, 0x71EF545DF2614B03ULL, 0x0E39260BB294E067ULL, 0x384682F04D1CAB4EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseHConstants = {
    0x2D01C1C958130FC2ULL,
    0x56B5A4FBC222F7F0ULL,
    0xF69198627D313CD3ULL,
    0x2D01C1C958130FC2ULL,
    0x56B5A4FBC222F7F0ULL,
    0xF69198627D313CD3ULL,
    0xBA3BE5F09A25494DULL,
    0xB6E00837E63B7489ULL,
    0xAE,
    0xB9,
    0x6D,
    0xF5,
    0x85,
    0x56,
    0x63,
    0x35
};

