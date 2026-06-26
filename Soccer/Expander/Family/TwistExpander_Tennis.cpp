#include "TwistExpander_Tennis.hpp"
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

TwistExpander_Tennis::TwistExpander_Tennis()
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

void TwistExpander_Tennis::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 11807012910610240735U;
        aCarry = 16852929010937739373U;
        aWandererA = 14108025346848701604U;
        aWandererB = 11596380797826547485U;
        aWandererC = 10080065963395460196U;
        aWandererD = 14601425975802896159U;
        aWandererE = 15776530354471535931U;
        aWandererF = 14549483278606789124U;
        aWandererG = 17052250422887877440U;
        aWandererH = 15823917733303853848U;
        aWandererI = 17607494280979205912U;
        aWandererJ = 16569509877170046724U;
        aWandererK = 10129889715088532421U;
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
    TwistExpander_Tennis_Arx aArx;
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
    TwistExpander_Tennis_Arx aKDF_A_BArx;
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
    TwistExpander_Tennis_Arx aKDF_A_CArx;
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
    TwistExpander_Tennis_Arx aKDF_A_DArx;
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

void TwistExpander_Tennis::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14527169867925710795U;
        aCarry = 14420873434439644129U;
        aWandererA = 10818526341982237617U;
        aWandererB = 17442841138547781564U;
        aWandererC = 12776067661939049530U;
        aWandererD = 15668589698622701073U;
        aWandererE = 13105638628868948046U;
        aWandererF = 11481689020467762215U;
        aWandererG = 12339905161525163197U;
        aWandererH = 11857117282088039666U;
        aWandererI = 14176837233807686489U;
        aWandererJ = 14698609275314069344U;
        aWandererK = 17433401668951733186U;
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
    TwistExpander_Tennis_Arx aKDF_B_AArx;
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
    TwistExpander_Tennis_Arx aKDF_B_BArx;
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
    TwistExpander_Tennis_Arx aKDF_B_CArx;
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

void TwistExpander_Tennis::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneB);
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
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneB);
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
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
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Tennis_Arx aSeed_AArx;
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
    TwistExpander_Tennis_Arx aSeed_BArx;
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
    TwistExpander_Tennis_Arx aSeed_CArx;
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
    TwistExpander_Tennis_Arx aSeed_DArx;
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
    TwistExpander_Tennis_Arx aSeed_EArx;
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
    TwistExpander_Tennis_Arx aSeed_FArx;
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
    TwistExpander_Tennis_Arx aSeed_GArx;
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
    TwistExpander_Tennis_Arx aGrow_AArx;
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
    TwistExpander_Tennis_Arx aGrow_BArx;
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

void TwistExpander_Tennis::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Tennis::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 17368949259878055816U;
        aCarry = 9501271133154818220U;
        aWandererA = 9932215175458670215U;
        aWandererB = 17553421465805750424U;
        aWandererC = 13056246184010386170U;
        aWandererD = 17150862705490064747U;
        aWandererE = 15529161846720167914U;
        aWandererF = 16612697420401608471U;
        aWandererG = 12734631026329889099U;
        aWandererH = 14892389138261186192U;
        aWandererI = 12696214097211606600U;
        aWandererJ = 15196938126940055653U;
        aWandererK = 10602264775948610642U;
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
    TwistExpander_Tennis_Arx aTwist_AArx;
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
    TwistExpander_Tennis_Arx aTwist_BArx;
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
    TwistExpander_Tennis_Arx aTwist_CArx;
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
    TwistExpander_Tennis_Arx aTwist_DArx;
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
        TwistExpander_Tennis_Arx aGrow_AArx;
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
        TwistExpander_Tennis_Arx aGrow_BArx;
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

void TwistExpander_Tennis::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 3, 1, 0, 3 with offsets 7299U, 4728U, 5908U, 2507U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7299U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4728U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5908U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2507U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 0 with offsets 6804U, 7915U, 7683U, 3632U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6804U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7915U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7683U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3632U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 1 with offsets 2051U, 400U, 8116U, 4136U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2051U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 400U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8116U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4136U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 2 with offsets 7204U, 3759U, 864U, 3349U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7204U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3759U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 864U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3349U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 with offsets 1929U, 1391U, 702U, 237U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1929U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1391U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 702U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 237U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 3, 0 with offsets 146U, 495U, 1493U, 1104U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 146U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 495U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1493U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1104U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 2, 0 with offsets 807U, 807U, 1580U, 1492U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 807U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 807U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1580U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1492U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 3, 1 with offsets 1233U, 1204U, 830U, 213U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1233U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1204U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 830U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 213U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1346U, 141U, 1346U, 1980U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1346U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 141U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1346U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1980U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Tennis::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 2 with offsets 4409U, 3984U, 516U, 6190U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4409U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3984U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 516U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6190U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 0 with offsets 65U, 1873U, 446U, 55U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 65U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1873U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 446U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 55U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 3 with offsets 3439U, 670U, 3404U, 1622U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3439U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 670U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3404U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1622U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 1 with offsets 4414U, 7573U, 1166U, 2760U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4414U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7573U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1166U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2760U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 2916U, 3259U, 2462U, 1316U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2916U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 3259U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2462U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1316U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 783U, 1781U, 1878U, 1041U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 783U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1878U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1041U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1541U, 229U, 535U, 1369U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1541U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 229U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 535U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1369U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 593U, 1262U, 2040U, 1781U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 593U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1262U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 2040U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 2012U, 1251U, 1443U, 1347U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2012U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1251U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1347U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 1, 2, 3 [0..<W_KEY]
        // offsets: 343U, 122U, 1243U, 500U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 343U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 122U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1243U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 500U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseASalts = {
    {
        {
            0xFA76C01AFDB128C5ULL, 0x4CC034E47DB836BCULL, 0x01F7233FD5AB9A55ULL, 0x2A12E605885944F9ULL, 
            0x2AE83D67E4411C7BULL, 0xAC23FB585985B996ULL, 0x406A63982B831109ULL, 0x9085D6679C76DC5FULL, 
            0x623ACBEFF8ED54FAULL, 0x904B14D4E707992DULL, 0xF0A205FAF12CD717ULL, 0x38D2A6CA7E10F43EULL, 
            0xFCDC2032454B2888ULL, 0xEB2C2AA656228F16ULL, 0x4221C292EF41D8B3ULL, 0xEB68F9A36DAB9AABULL, 
            0xF215809FCC77A754ULL, 0x7ED5E2142388EE13ULL, 0x0172E8B6DEE6151DULL, 0x5EBD692E7FD8D556ULL, 
            0x8F1699002245994EULL, 0x51FDA3004BD0C61CULL, 0xD463F8FD2BD9BA3FULL, 0x1EDC62D6965B0500ULL, 
            0x79E1803104905098ULL, 0xFFBA19C5C2047EECULL, 0xD12A928F326F9F6AULL, 0x16DF243D8C7C11AEULL, 
            0x8F189E7FBED4E650ULL, 0x920CD83AFC4C6475ULL, 0xAB2E5A92E503AA84ULL, 0xBB7C0323B139C8C8ULL
        },
        {
            0xF7EB54C3261A8D4CULL, 0x4D515B43E6239EFBULL, 0xF49F50BAB6A19C8FULL, 0xCEEEAE7C75B8D8E3ULL, 
            0xD5B8BA3B19E1FC41ULL, 0x04DC472B69E7596DULL, 0x73F6D9BBD15B4B3AULL, 0x8FB746F9791ABFA7ULL, 
            0xAB56DC23F7F0B165ULL, 0xA6AF4E0CCD1215A7ULL, 0x8683A47F745F3CBFULL, 0xD965892E124FFDE6ULL, 
            0x64AC7F7DE7C14E0CULL, 0x7594B09897AC33B4ULL, 0x9E29ADA3306ACD53ULL, 0xFC23F5600D0E78D4ULL, 
            0xA65CB7F920466C7FULL, 0xACFE550D1C3A7485ULL, 0x8DC9CA9806140CE1ULL, 0xCD255D9F4036ED9EULL, 
            0xD7B44943A698BE05ULL, 0xA5EB09ABE72824DBULL, 0xA164A686B0E9F7A9ULL, 0x95C8AA9ECD5917E2ULL, 
            0x5B3D211D1D43B077ULL, 0x2EAC2337CEC85AD6ULL, 0x8DC79DE4B4ECBD49ULL, 0xC7E501A92FC2073EULL, 
            0x3410257F9D4104A5ULL, 0x5C2DE289B6C5A997ULL, 0x7D53644CA1633EE4ULL, 0x0F6B17821B677CB0ULL
        },
        {
            0x8C566D418D556BC6ULL, 0x2839DED9BC5AC5F0ULL, 0x3F4CE8118D187CC9ULL, 0xA785E927F9A110D6ULL, 
            0x844C3B39EB6B35E6ULL, 0x2441DF534E381A25ULL, 0x466E433C7B2CBC8EULL, 0x64DCAF26F33932A8ULL, 
            0xD37FC27B2E74D155ULL, 0x93004841156349D4ULL, 0xDC4D5C0EEA4ED199ULL, 0x81C9B91B824F2BAFULL, 
            0xF1EC4C3E6178D7DCULL, 0xDD0F900606A9305DULL, 0x343DB9F41DDBA22DULL, 0xD1ADFBAF28666C41ULL, 
            0x2FD1B8C742BF9224ULL, 0xD5259777DA589A72ULL, 0x6D77483CA8E9885CULL, 0x9371404956C8FB68ULL, 
            0xD52151A142B3A97AULL, 0xE5D70390341340C3ULL, 0x32191441FC3C879DULL, 0xCE35F129CEB29A98ULL, 
            0x653A8D1557AD1B71ULL, 0xC8BE9BB499BDD2A5ULL, 0xF5AAAE9C530A9121ULL, 0xBED5EBE79AA019F0ULL, 
            0x901824DDB7601B34ULL, 0x8AF7A9B8B12E485EULL, 0x005F8B660CEC9465ULL, 0x55464563252F2805ULL
        },
        {
            0x41C3CB6FAAA0869FULL, 0xECA8F5BB3430354FULL, 0x656E5AAB251D3C94ULL, 0x92F4D8A4C59E0887ULL, 
            0xA354EC936A51C4C1ULL, 0xF09F33B7F13D8FE6ULL, 0xDBD7795E7C9CE21FULL, 0x6E05859D5F04F0DBULL, 
            0xE10778210034D031ULL, 0x44AFCCD2C172D26FULL, 0x3A29A4FDA169CB24ULL, 0xE2DFCB9AAB2AB4E3ULL, 
            0x8451B684D3AC18E9ULL, 0x8845B2D634798209ULL, 0x7ED3724303BC4EEAULL, 0x8130196AB5BBDECDULL, 
            0x580124328F734038ULL, 0x5E3F5ADD12DCDB84ULL, 0x49BE7C5A2C89DB41ULL, 0xCFECFD5E463F4E42ULL, 
            0x53C03E202E7527ECULL, 0x797CEDF6204758B0ULL, 0xC8A9A0497A206D5FULL, 0x7753999D0F317A36ULL, 
            0xA278E97B65769C3EULL, 0xCDAB3AB156303C96ULL, 0x8297CEF3FB85E245ULL, 0x4FA0D3A58DFCBF7AULL, 
            0x0C2DC0CEC6B156B0ULL, 0x80279E61F34AC311ULL, 0xE4188306BD82CFC7ULL, 0xB306DA451A7AC7D9ULL
        },
        {
            0x7D740AD44BAA1645ULL, 0x21116CD7BB5C122DULL, 0xEB9AC3011611B72CULL, 0x616B2BDC6CB342B1ULL, 
            0xF6C7B370F8608E9DULL, 0x11188DC6D75B9CD0ULL, 0x7937E03A4CAD99A9ULL, 0x964F85AE64FC1378ULL, 
            0x01EFA453CA59B96FULL, 0xD2138C9AE5B9E30AULL, 0xFB7417AD46D57845ULL, 0xB0188E98D3A8335CULL, 
            0xA3E80F7BB27CA209ULL, 0x3AF540627FBA8FC9ULL, 0x5B771142FCF8BD73ULL, 0x04D66D1074AA10EEULL, 
            0x32CBDB9B051F085BULL, 0x906C493AC1FF96F0ULL, 0x1E065A9C3E61C667ULL, 0x8D66DD00F1416A02ULL, 
            0x225360495A3BC0CFULL, 0x292F504B5FADBAB4ULL, 0x957F5ABF6081AE4FULL, 0xE69B49879E4A7CACULL, 
            0x917EBBAD3EDA5CE5ULL, 0xB7E0283AEC19CA7EULL, 0x79DC2AC87AA349EBULL, 0xE4FCD09B9F6AD279ULL, 
            0x61B7ACC305A389EBULL, 0xD524F50BC4848D00ULL, 0x90895195A5E11E51ULL, 0x707CC6FEE03AC3B6ULL
        },
        {
            0x7115766765AC3152ULL, 0xB3AA558BD2D88BC0ULL, 0xE20988558AFCB8E2ULL, 0x11619C266261C406ULL, 
            0xDA710A0998B9DEFFULL, 0xFA5398516E3A1609ULL, 0xACDCFA83A357FD84ULL, 0xEB14DEA8BB4CBD3CULL, 
            0x7F6E56C35DB7800DULL, 0x2E9C11E3585D07F8ULL, 0x79BEDE90030D69ACULL, 0x53BBE380179D24DFULL, 
            0xF22AEA0620C7664EULL, 0x0F810B88D301025AULL, 0x1CAE9A55DEBAB19AULL, 0xD72DB9073D42E3E8ULL, 
            0x82ECDD72D4EA2E24ULL, 0xE412292B7F4B33FFULL, 0x0D8438D6355AE4B1ULL, 0x8024B7A233300150ULL, 
            0x2E1170E157F0CDC9ULL, 0x3A3856AF8F1BBD73ULL, 0x45882E9074164A54ULL, 0x99E28A16A2EDB161ULL, 
            0x32146A9D5AE92371ULL, 0xDB3E80568E9E85DEULL, 0x0B08DA472D19E790ULL, 0x4ECCC762228470CBULL, 
            0xC0F6209E52912B5FULL, 0xB322AA1147687C2AULL, 0xDC519EAF9A8A18E8ULL, 0x5011F3CDFA714A78ULL
        }
    },
    {
        {
            0x9EFEF0EC5401E6C8ULL, 0xAB92BA0AEA185430ULL, 0x7FC097DABEB0FC52ULL, 0x439C4B7C2FE91CAFULL, 
            0xC707CD49E5053025ULL, 0xD7E13B6FE99F62CDULL, 0x66FE4E5F53B13255ULL, 0x13DE24DAF0703410ULL, 
            0x29C1A484FABF242BULL, 0xE685F8A70189B3D6ULL, 0x36EF949D1778C997ULL, 0x5589ECAD49C12749ULL, 
            0x12B345C91CCD19D4ULL, 0x19099178A8839595ULL, 0x4F66512AB018203DULL, 0x9BFCC33A819EE5B2ULL, 
            0xA79CB41512994518ULL, 0x02EB44791B6A03D8ULL, 0xFEA2DA267E8F4CA7ULL, 0x5CDF78AF92079266ULL, 
            0x07CA773AF881EAF3ULL, 0x66368D930FD9C51DULL, 0x839D1C09722E7CFFULL, 0x2952991C4760261BULL, 
            0x027EE0CF3B4C1116ULL, 0x4E677E088B045F5DULL, 0xF8E0EEC81AF56428ULL, 0x5B00E4F2FB94A85EULL, 
            0x7E655E5942625A24ULL, 0x21C0A1DBE82AE7B9ULL, 0xEB3B1E5EB7DB0807ULL, 0x5AC6005DE36D97E6ULL
        },
        {
            0xD202275A25FFCDA5ULL, 0xE26E421ADC8506CFULL, 0xD4DBB72703FCEA37ULL, 0xB51DC6D8A2D68D70ULL, 
            0x21D6D33F44854472ULL, 0x342BC2E6255CAF92ULL, 0x77FDE135DFBF87EFULL, 0x5D636D7B0DD7335AULL, 
            0x6FE38300BF8BB136ULL, 0xF273792D254685F9ULL, 0xE6A1BDD7DCD2741DULL, 0xF914E8AC092AF166ULL, 
            0x9B35BAD6C0646301ULL, 0x2250E0F2242CCA47ULL, 0xB0DA74F1588D6EBCULL, 0x4648983A7C687C4AULL, 
            0x4300981EF0C57550ULL, 0x18A0E286A3D0B092ULL, 0x5CD980FFD0D5E953ULL, 0xA441CDD4AF4F1126ULL, 
            0x366CEA38243BF96EULL, 0x301CC9B7C290942AULL, 0x7950E6F81C3FF6D4ULL, 0x0368D09F4737AFB0ULL, 
            0x3C3F43860B30D91AULL, 0x9545531D89F84ABFULL, 0x93E91AB4CBF55A80ULL, 0x908346AD5CBDD55DULL, 
            0xE24B50DBA5F3FEC8ULL, 0xA2D8B9F45AE59949ULL, 0x8315E254514A9BF5ULL, 0xFCC141FDF0E22F47ULL
        },
        {
            0xA9E60D153F01E43AULL, 0x5D3EEDF10E142552ULL, 0x03460DA254369049ULL, 0x5D4A15630F257A2FULL, 
            0xB9D462A14FEE7439ULL, 0x144499E55116CE08ULL, 0xD46FA52BB0D0A49EULL, 0x8C7D0398FA632167ULL, 
            0x5B6694404AEB0D6EULL, 0xF7E21918C9450A4AULL, 0x4A9CCD3038DE8D36ULL, 0x9484A05F19E99192ULL, 
            0x1763905753111AC4ULL, 0xC6F972801E6EFDC7ULL, 0x3151218F96C46842ULL, 0xD3B2CFE51864A8E4ULL, 
            0x34503AF94834AEBBULL, 0x9D9431ACAB3DB5A6ULL, 0x7AF8C0CFAA66C43DULL, 0x90F13EBE0E96C25EULL, 
            0x0000250BB3957CA0ULL, 0x3514B48393FA27EEULL, 0xA31E2CEF747A949EULL, 0x26248F842FC379BFULL, 
            0xD87F2A63F60DDF09ULL, 0x49A9A928C13848A7ULL, 0x8F088F61ECC2173AULL, 0x4D93E22C680B3140ULL, 
            0x0E78AEF041F8A94AULL, 0x21D0DF11FE5BDA8FULL, 0x843F4CAC9F93CCECULL, 0xE7336399962F44EFULL
        },
        {
            0x8EA3B3E752E85D19ULL, 0x34C51CD0C6955407ULL, 0x7CECF07B0DBEF835ULL, 0x65B40F5D3EBCF4E9ULL, 
            0x83E81DE46641B8EBULL, 0x6EACE1CB5F7ABB34ULL, 0xEDF7B6448B620D47ULL, 0x78F205A5408047CCULL, 
            0x358EA086B35C062AULL, 0xA7F840530F8AA5F7ULL, 0xF5AF6C33313575AEULL, 0xB0256CBD4C517145ULL, 
            0xCD3734300FF3E326ULL, 0x1030ACD864FCAC32ULL, 0xB8BDD0184070DD13ULL, 0x3CCBDC5783852276ULL, 
            0x8BADCE760078DA98ULL, 0x2BB6C16ADDEDB31DULL, 0xAAE0AFC8F5750BFDULL, 0xF468A589A7869CBFULL, 
            0x77F3E9E7A327DC28ULL, 0xD5AC416B798BD548ULL, 0x4F016451F0814D6CULL, 0xAA37A723DE0354CDULL, 
            0x710D50A72540744DULL, 0x0C9059EFDE42C8E0ULL, 0x1CF35A48E637581AULL, 0x2FF3C2A667EB9BF5ULL, 
            0x05F1C1F77DD96D39ULL, 0x7A54DE8FED239B93ULL, 0x698855CC04576F28ULL, 0x2630DC2E5022D7B5ULL
        },
        {
            0xA0D2AA9F5955900BULL, 0x33D4DB45484FFBD8ULL, 0xDE6E54582BE26D0EULL, 0x5DEB761CF34DDA2DULL, 
            0xE8149F4C9EAD5F59ULL, 0xA784428DA6AFE8B7ULL, 0x127A739B3B3AEED4ULL, 0xEBE700279AB72D44ULL, 
            0x8491DC9FA27F6F3CULL, 0xE8F50679546BE385ULL, 0x08B8FCE5B3683809ULL, 0x6123EE84C17015EBULL, 
            0x32AE3A9DEAF9B8C0ULL, 0x67D7227D69BD13CDULL, 0xFFBA81F4CAF71CE1ULL, 0x8FFFC864DFD05385ULL, 
            0xF83C99E1E8F51BBEULL, 0x1581CC1A948C5F3AULL, 0x955FCA12982DBFD6ULL, 0x8BAB87F53C4BFB61ULL, 
            0x571FF3ECB453C58CULL, 0x83649993165A7AD2ULL, 0xEC1BE6EBA07DB7FCULL, 0x714BCA5E6050295CULL, 
            0x831E3C9347D204FCULL, 0xCA60D33019808140ULL, 0x11FAE10296E860F4ULL, 0xB5E70592E8B14FD0ULL, 
            0x6D36CD1A525C132CULL, 0x57566E92328FE4A0ULL, 0xA3D71B6B7EED4ACEULL, 0x2E67DD73A74C0926ULL
        },
        {
            0xB8976DFC4468A21EULL, 0xCF992C9CA15F84C5ULL, 0x036E1D9EC89ADFF3ULL, 0x83DBE64E3500FD0AULL, 
            0xF4D3E154D5256676ULL, 0x420A3E2767DF33E3ULL, 0x857F74FB819E6C3AULL, 0xF998A40C1443D501ULL, 
            0x2D28DDDC9649CC25ULL, 0xE59DFDCC7FC1C29EULL, 0x993742114FEEF4B5ULL, 0xC91E382E054B8703ULL, 
            0xCAC4A2F949A27718ULL, 0x9EF56EDFCC6EA13CULL, 0x7A315CC043AC30E4ULL, 0x7B21225389BDF3B9ULL, 
            0xC96555FFEDB5B443ULL, 0xB5E3F76EBFEC1AD1ULL, 0xE31CFA738B4BFEDCULL, 0x45A55DB6FFA36763ULL, 
            0xF7BB74FB220D57C0ULL, 0xBFDA393B72DC135DULL, 0x0DD0C38B5047B717ULL, 0x95A577BBAA5F2FEFULL, 
            0x14A4BD6EB51C40BEULL, 0xB9EB0D35CFE3D31AULL, 0xB225CFD9C0C6BAC1ULL, 0x2DFCD9D1A0222309ULL, 
            0xE7F6665530D34921ULL, 0xA79CB26A8EAEFE44ULL, 0x05F89348D71BA064ULL, 0xAC03818FDA1E3FD3ULL
        }
    },
    {
        {
            0x1B979F57844BB7A6ULL, 0x63743E9B97646415ULL, 0xD06DF1E65D8E8D01ULL, 0x8BEB95EAF0A68667ULL, 
            0x5A818DFA89458CA6ULL, 0x5E2505082DC795BCULL, 0x3F795A2E7059E57BULL, 0x30DF7541A6BA5D15ULL, 
            0x00DBC9CF71D7AD98ULL, 0x9BE1F19A5733EAB1ULL, 0xFEAC9B6B1427D6BEULL, 0xBEF81BEFA0AA46D5ULL, 
            0xE0AE2B5BA4BC2C7BULL, 0x108BBAA88660FA0BULL, 0x61DFF1273C8EAA45ULL, 0x5D61E97CD2CEC525ULL, 
            0xAC900E26A5F3A8BEULL, 0xCECC1643F1207052ULL, 0xCC6AD6547CCFBB3DULL, 0x0330958EADAFAE6DULL, 
            0x9B478C51CB20B67EULL, 0xE2431507DEE503D1ULL, 0x0F28116B22E395EAULL, 0xAFB366EB8016C8F0ULL, 
            0x5A31BA57C1E86D31ULL, 0xDE8DC34ECDF5C87CULL, 0x17F574F1F9895488ULL, 0x81D3FE2AD1B6B23FULL, 
            0x799938D35CC816F2ULL, 0xC2611299B27D772BULL, 0xC81998EF96A3AF09ULL, 0xC5039DEE674BBAD0ULL
        },
        {
            0xA5945122C58F2E42ULL, 0x0DCB899D6A0D64B0ULL, 0xFA41FAF641F7429FULL, 0x5E0344090BB1C89CULL, 
            0x5E42474F48D93EFBULL, 0x43E40DC2EDBE0052ULL, 0x5A0B2120C2FB8305ULL, 0x859537E33D81ED33ULL, 
            0x0111526BBAA4C892ULL, 0xE0056EFB60C04BE8ULL, 0x241E4E4484A59BC8ULL, 0xCC64F4C70E517935ULL, 
            0x5CFF3C6AE5D8A449ULL, 0x3F6BE4378E7A082BULL, 0xCA6205B82ECC6938ULL, 0x5F842E25CBB35B82ULL, 
            0x544DF90481BEA66CULL, 0x89171D224D3C56F0ULL, 0x1BF99E67BF9D1510ULL, 0x849CCD6FD4828D78ULL, 
            0x9D1B5D74D2C7FD2BULL, 0x61A63779093D9E92ULL, 0x1D0F56246998BB21ULL, 0x7B04D7F5E82E065CULL, 
            0x47711C12FDC1A274ULL, 0xA7F8B5DE2313FC83ULL, 0x9E61783C15FA0C53ULL, 0x06D999451DB11BC4ULL, 
            0x06AB786E25864B8EULL, 0xD013A525B49134FCULL, 0xE0C494861A4E3C38ULL, 0xC7BFA55F57EDFEE4ULL
        },
        {
            0x8F5A5177E8B6284CULL, 0x83FEAF25A4F0B521ULL, 0xC3D4D9E73B977EB7ULL, 0x7B96ADF6D1BF5144ULL, 
            0x68537CE474A24037ULL, 0x73EE594FDFA5C83FULL, 0xF70024175E06BF7DULL, 0x366379DF3E27AE34ULL, 
            0xB88C02E360BD98D0ULL, 0x6631C35D72155A3CULL, 0x9AA754AA0BCDB304ULL, 0x79D29992F98C1BA2ULL, 
            0xE7D46AAC2B131D56ULL, 0x6AEDB912ACB73467ULL, 0xD3FA01B4E6715204ULL, 0x97B1AFEB0069AE12ULL, 
            0x9A75247E49D08119ULL, 0x1D56C1B4982F771DULL, 0x61FC30C6CFFA4055ULL, 0x050835727BB55643ULL, 
            0x9C3FCF8C94680FF4ULL, 0x8EE5CA6977784CDCULL, 0xCE3FEA08ABD7E3B2ULL, 0xFD1E9E1CB12FBEC1ULL, 
            0xDA985047191628C5ULL, 0x7C51A79AC1DE903CULL, 0x2A06BF9200635F8DULL, 0x8775CAEE03AF0C21ULL, 
            0x688C0DC1DF7ED4B8ULL, 0x47C0C9245BAC591BULL, 0xF3F6167310C329FEULL, 0x3B7CF7CFDAE0545DULL
        },
        {
            0x34B6B644E8BD88AFULL, 0x5A29B31316E6D5EDULL, 0xBD3552D130CC0BB7ULL, 0x6E872B1373D48506ULL, 
            0xE631D153EBC3AB3DULL, 0x75944447D7AC62ADULL, 0xBDE3FAC558C90FE0ULL, 0x6235B04463EDB6A2ULL, 
            0x206496CDD51FE76BULL, 0x1ABDEBE00D6DDFDAULL, 0x2E0409A765BED5B6ULL, 0xBC20953B5D011E59ULL, 
            0x4FFF20597666E9F8ULL, 0xE4F8CFE82746E3EDULL, 0xD4C4AB44C734F462ULL, 0xADCDA814D499A6D2ULL, 
            0x95C952792E154709ULL, 0x5DD83E5C92D24288ULL, 0xD56E3D720B731C38ULL, 0x41FEC6EA5834CA79ULL, 
            0xE99B8C8166512E37ULL, 0xC2B96572C601F077ULL, 0xC65E0033DE6F3059ULL, 0xE85D759345B63A1AULL, 
            0x46C53BBB8CFB33D4ULL, 0x70F8355BFB257590ULL, 0x035C4203A31F727FULL, 0xB7D6AB0A77B1464AULL, 
            0xCD561971DDE7B4E6ULL, 0x2F311D0F13D6795EULL, 0xC1F9D4D9C200A989ULL, 0x7B9458D50CB1775AULL
        },
        {
            0x24EEE6331FDC8523ULL, 0x40A68476BD2C1E27ULL, 0x193F0BD7C9EF75E8ULL, 0xF5E9D2473C6449B6ULL, 
            0x82BF715114155567ULL, 0xD8A75E88265EBED1ULL, 0x6A0E0ADE4F5C124BULL, 0xCA36189124AF588AULL, 
            0x394CE0B690CCD7F3ULL, 0x7A5DDAAB360201FFULL, 0x423C4C641B176008ULL, 0x24F758EC50667ED3ULL, 
            0xBFFBA41657100443ULL, 0xA58AA67AF2EAFA87ULL, 0xEB292E2887B2ADD4ULL, 0xA425E4127E5DB258ULL, 
            0x58E808A8BD2D7F73ULL, 0x921EF2A536D7764EULL, 0x7CA695C8546665EAULL, 0x2D226B8D4584AC6BULL, 
            0x8D740EBEB1EC971EULL, 0x927577A091EF78A3ULL, 0x8967714A440942C0ULL, 0x5849B3E566A145F9ULL, 
            0x8AA194E09408351AULL, 0xC138AF4D0991C827ULL, 0x0832613EEEEF8D31ULL, 0xFB3F213F191466C6ULL, 
            0xE2574DF8A78DEB93ULL, 0xC18755DC20DDA279ULL, 0xC553E1475FFE089AULL, 0x6963BF6CAEAF23B2ULL
        },
        {
            0x2E7F5DD89E5474BAULL, 0x5586376A3DB88ABDULL, 0xB4429E56B8AF8274ULL, 0x7A5FADFA259D4183ULL, 
            0x56FC8B1A14CC7C8CULL, 0x80FF62E97A527E00ULL, 0xFBFF9B8CA6783827ULL, 0x542E69B83798C2A6ULL, 
            0xDCA82E8D6F111C72ULL, 0x3220941E39803ECDULL, 0x380B8912704105EAULL, 0xB35E61463184395AULL, 
            0xD2EF5772B4029906ULL, 0xB6C75BA6E4B07B89ULL, 0x6FDC20E72048582BULL, 0x2FEEAA221F40E2B5ULL, 
            0xBEFBDDEAD0AB0C65ULL, 0xA100038894F92B71ULL, 0xB0D4B44A077A4157ULL, 0x39262D94227B05B0ULL, 
            0x539366B86ECCAB94ULL, 0xF9E07413458F3CC7ULL, 0x7C4D1327A1074C15ULL, 0x96FEBF152BC830ACULL, 
            0x1A160A3DEA3C771CULL, 0x65C0207B1A65630EULL, 0x1FD7F447F1E3F6A0ULL, 0xA0246C3F99F496B7ULL, 
            0x9DA8CF7D17A20F3AULL, 0x4E3C068DB7E56AABULL, 0x20DFCCB7DAE0653FULL, 0xEFA7CC205477BD73ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseAConstants = {
    0xF433ED79ECA95C31ULL,
    0x9212CB81314CFE26ULL,
    0xAEA567686D4A828DULL,
    0xF433ED79ECA95C31ULL,
    0x9212CB81314CFE26ULL,
    0xAEA567686D4A828DULL,
    0x04C351DC3945D38BULL,
    0xC47674A0826FE42DULL,
    0x50,
    0x3F,
    0x2A,
    0x9C,
    0xDE,
    0xE0,
    0x8D,
    0xA6
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseBSalts = {
    {
        {
            0x0E4913040BA25EB9ULL, 0x685E90E939478F55ULL, 0x8E93C33B9C5C74CEULL, 0x5E141057E83EF9A0ULL, 
            0x8CE742E66C5659A6ULL, 0xD7438CD66E9EFDAEULL, 0x52F734BE7800BEE4ULL, 0x64360A98D90D6D4FULL, 
            0xC956547B828A1EF6ULL, 0x1471E70DA0CC6AF0ULL, 0x2C45913619D09C4DULL, 0xAB029303AD5E4AE2ULL, 
            0xE46B524672AF2859ULL, 0x716CBC92417A63F6ULL, 0xAE9208746193D8CEULL, 0x437190B59B744897ULL, 
            0xBAFC83E51FA879DBULL, 0x586AB9A850D3F406ULL, 0xD3ECA1B9B1E8BDC5ULL, 0xDC86888412EB9D13ULL, 
            0xB8493DF1AF102AF5ULL, 0xAD7D88FEC4F75639ULL, 0x6E8E5D34D26C46DCULL, 0xE603DDC998E42C36ULL, 
            0xBA998A6858F634A3ULL, 0x17BD9DAEE0BA085AULL, 0xA23AE0F6929A19E1ULL, 0x802EAF4D7C3CD1C6ULL, 
            0xF1D4B092FE890677ULL, 0xB08747F0FA24E2E9ULL, 0x3ED83A7616101D68ULL, 0xA12F89EC012CFDE0ULL
        },
        {
            0x4E7511AA0CA15286ULL, 0x2297395A1F41AE6FULL, 0xEAFA88F73F56C20AULL, 0x46C3F29FBF0FFC93ULL, 
            0x776CFDCDCD8C4F90ULL, 0xFA7CC4383C22EBFFULL, 0xD537725AEB49CFF8ULL, 0xAD8CDDD1445E1D8AULL, 
            0x5AC4B36FB8C4C736ULL, 0x45FF63DDA335DAD7ULL, 0x76E8CCCEA6525640ULL, 0xA0E04AFB4150E5CCULL, 
            0xBAD4BB0FCA365E21ULL, 0x2C09B82DCC574E72ULL, 0xC31E153FDACD4CABULL, 0xC5DE5F6BD24755E9ULL, 
            0x938C22EE51908A5CULL, 0xE30D34FF5AB93CC6ULL, 0xA023AAE304C124CCULL, 0xC44539AB7906B472ULL, 
            0x16123DEB2377DD87ULL, 0x4D7F01FD765CE43DULL, 0xBE110BAB20F1B73FULL, 0xD1F9F2F3A40D95E4ULL, 
            0x36D02899CDD5E2E8ULL, 0x7B01448FAE1A9F64ULL, 0x78624904EC8121CFULL, 0x05F6DA9CC71EA9E1ULL, 
            0xD35BC830A92FAD7DULL, 0x6A02F034B276C0BBULL, 0xEB728449FF6FC324ULL, 0x1C2EF72E6B0D99F9ULL
        },
        {
            0xD85D28B5726A6823ULL, 0x77045CB4249E48F7ULL, 0x06C70F1D358F9343ULL, 0x5F6BC43EFEB7D693ULL, 
            0xD2B3A1FE6833DC7DULL, 0x681D0C35D53888CAULL, 0xDFF155C4B4D2C162ULL, 0xA7990D2032A4BF19ULL, 
            0x3B7CED2D6E339F69ULL, 0xED9F1DC03EF888ADULL, 0xD82C42188F81C93CULL, 0x886747DD71E78B42ULL, 
            0x6EC3838B65542E28ULL, 0x13D98F28D7BD527BULL, 0xDDB8E18D2E16F7C3ULL, 0x9BB2F63B9F620403ULL, 
            0x75133B8BE5F45B51ULL, 0xC538D8D8BB279CB3ULL, 0xC50FDAECA4205E6EULL, 0x79251724C0396264ULL, 
            0x0D6744FA60167FB1ULL, 0x8E7F0B7A3ED5B7B6ULL, 0xEFC0E8435FC56554ULL, 0x4931F5503555B6F8ULL, 
            0x19B559E0CF54C298ULL, 0x6047DD714E13D548ULL, 0x4B61149E82D52C2DULL, 0x1AEFEB7B1C266919ULL, 
            0x2886D1E99C6A8D83ULL, 0x3E866DC6A266EEF3ULL, 0x5D394578DDC3E897ULL, 0x94C8DB0CF72E3D17ULL
        },
        {
            0xFF125B18847EF102ULL, 0xB52FE05818448C9EULL, 0x00E76608778378C8ULL, 0x219FD27043EC5493ULL, 
            0xCD93EF5992C848BFULL, 0x87789A12199DF778ULL, 0x7A87AE9ED9F9F087ULL, 0xC53BA0C3872EC8EFULL, 
            0x91B15F9B2159C247ULL, 0xAAA8AE29811BDA33ULL, 0x47533254AB363E51ULL, 0x3ADB9C3645D2251BULL, 
            0x561554452DEB6250ULL, 0xCDBD1D9FC7CBEA51ULL, 0x6AC433767C9674AAULL, 0x32857F4906B7FE65ULL, 
            0xF92F82724D970F2EULL, 0x932974C7E6EF0EDEULL, 0xC6E843666D67D9DFULL, 0xD686625834584BF8ULL, 
            0x5214C38AD2022F08ULL, 0xCB75EF86566B8D81ULL, 0xD0255D1E2C232912ULL, 0x2A6C70FDD2768CE0ULL, 
            0x82F8C7963E248655ULL, 0x774E283B5B6912E0ULL, 0xF2EDE27A8DA7A0B4ULL, 0xB024879FD209D865ULL, 
            0x8C2DF479794D85A8ULL, 0xC1EB0F92993F9944ULL, 0x32983DBE9A82AD2CULL, 0xB4BB43C7462B9C98ULL
        },
        {
            0xB4D42286A7E98A01ULL, 0x804A08ACEFA5D1A1ULL, 0x188ED91FDFD9422EULL, 0xC038D9B2A3580D1FULL, 
            0x6A63700ADA65C569ULL, 0x484E6B429740C551ULL, 0x26A1F140DE7DE9F3ULL, 0xB4BDAE100F16C707ULL, 
            0xEF5C48BC344A1B4EULL, 0x8AAF112E71657BF7ULL, 0xC122CE21F166DC82ULL, 0x20A18FBB63176D95ULL, 
            0x90172787A02A54EBULL, 0xCC8B7F99FE7F5EB8ULL, 0xD540FFA45559A10CULL, 0xF5B4F42C17A333AAULL, 
            0xAE221B2C814EE790ULL, 0x6AC968CF2B546E25ULL, 0xA8A5DA7F4AE86B55ULL, 0xE8C0E99454024109ULL, 
            0x8726351AAAA86DD2ULL, 0xF61F379E036789BAULL, 0x0B77F8898D63F59CULL, 0xAF988F423C0E2AAAULL, 
            0x7FE1F745C386C32BULL, 0xA29A3E0766D3C72CULL, 0xB141051B21B8BCBFULL, 0x36860FDB01E16FD0ULL, 
            0x3D411B11B0154F02ULL, 0xA08E738DD8F8EA6BULL, 0xC8B4C861431EB2D2ULL, 0x0BD2289F541DB271ULL
        },
        {
            0xFA63EEA1DE1F050EULL, 0x9046B00FFFED0F00ULL, 0xCD9939EA4C138F12ULL, 0xC39D08FBDE5FAC46ULL, 
            0xDEF5970CA79436F1ULL, 0x4CA2B1A5377E00ACULL, 0x1C83672EB10EF43CULL, 0xA6397286F4B36BD0ULL, 
            0xBC8D4D9AF9B71DEDULL, 0xD5ADA924AE35C326ULL, 0x05114DD24E0B8D26ULL, 0x59987CD36A419341ULL, 
            0xDDF3C7185ADB1A1EULL, 0xD113366F58438336ULL, 0x53AC67828ECB0841ULL, 0xB2EAF7FB165F939BULL, 
            0xB3E75A905BDE853DULL, 0xC4CB31977980392FULL, 0x01EAA6098B4B1F90ULL, 0x10F3C7EBEF088EAFULL, 
            0xE995E68D04877EC8ULL, 0x9954415C57D86167ULL, 0xF86CDA986E094EC1ULL, 0x56FA6E8BCD8FCE43ULL, 
            0x99C57016BE73B77CULL, 0xE00DBAD2015CD123ULL, 0x0BF9D95C9330780EULL, 0xF9F54FD782874869ULL, 
            0x8663E287D46A8BB5ULL, 0x773F514E3FB00F51ULL, 0xD0EDDDE87999C7A6ULL, 0xB19E798F4DAEE4A4ULL
        }
    },
    {
        {
            0x14A5E49CA9F6CBCEULL, 0xC4A4B52377A8B9D1ULL, 0x1A884717F7481DA0ULL, 0x8185DE1ADFFB0B89ULL, 
            0xBBA810CA3FE8F9CDULL, 0xDD00517E70CAA5F5ULL, 0x99B84A63C7F31D5EULL, 0x80A44D71B9632E3AULL, 
            0xD7DA5A60F125F379ULL, 0xD07215DF54A50706ULL, 0xD3456EEAA3176AB5ULL, 0x6A960EAFA391E4CCULL, 
            0x0CEB73FDBD79AA34ULL, 0x11880CB959D306C8ULL, 0x61EE63854EB3B776ULL, 0x2030CE5165DAEB2BULL, 
            0xF193B90BB993643DULL, 0xCB72C413E488B506ULL, 0x8960BA8EF868DA03ULL, 0xBCC1A7841AC93F0BULL, 
            0xC994733EB500C6AAULL, 0x2E7D35F922428C02ULL, 0xD77250374244FFBCULL, 0xE360DC6995EADE04ULL, 
            0x3152CF3A44AB9C45ULL, 0x8493746C83116A10ULL, 0x6860D82C935CB785ULL, 0xD83662D8427A9932ULL, 
            0xC5A8DAC6F3CB459CULL, 0x629FDCD31F9BEB4AULL, 0x81538C400005FF3EULL, 0xAFCD7957856FBDB5ULL
        },
        {
            0xD3FD01A569B89DD2ULL, 0xA10BD8CDBCF30ACCULL, 0x804F5E5E1A280BF0ULL, 0x3AAB55D1F85A231CULL, 
            0xB3E379E6EDE9E866ULL, 0x599F43E941AA76F5ULL, 0xADC95BD87EDC6B00ULL, 0x9C5BEF5A9CD682E5ULL, 
            0xA5A0A4404F964748ULL, 0x75AD36612A5A1FA6ULL, 0x118E9E4F7C76864AULL, 0x226CEAA2BF8D91E0ULL, 
            0x91A1339BD68D92CAULL, 0x2C6A2A907A276DA0ULL, 0xFB9071BD60730047ULL, 0xBD183605452F34D8ULL, 
            0x5C58560472671B3FULL, 0x6802C0C6020AF5F6ULL, 0x12EB1AD0CFB47BCFULL, 0x838CCCEE64D6BE3FULL, 
            0xB40427BAE59E06A7ULL, 0xCAA2A1FA9E8DB889ULL, 0xBB7E71EFC0101257ULL, 0xA2999C9893EDBD21ULL, 
            0x90C65A746B391B5AULL, 0xFBA5120C384566DFULL, 0x594DFE803A5AEEF7ULL, 0x30A64C495EDA1399ULL, 
            0xFEA636B330E36AA7ULL, 0xC42497A8C307F042ULL, 0x7FA2B1598A592D9AULL, 0x2D2215A4B8C8D5E7ULL
        },
        {
            0xBC0EB1361C512E21ULL, 0xB18F0F4AD10C8B8EULL, 0xB40A06B43FF52064ULL, 0x967B6E53CF00A30FULL, 
            0xF212F0DC1A9F1E94ULL, 0xD12553C5DA99583AULL, 0x9FA8654EF676B431ULL, 0xBEE67189BD7D5DCDULL, 
            0x460F5A9D342FD728ULL, 0x7B6E850D5C1B5E09ULL, 0x4BB3E29999889A77ULL, 0x8C26261328594C3EULL, 
            0xCF81E2E37AC4F083ULL, 0x0548C0EECB11859EULL, 0xF6A551ADD89E6809ULL, 0xCCA7EBAC62F8E9BCULL, 
            0xCC8738624BC01C2FULL, 0xBF8508BBD1D30FFDULL, 0xF24CD3E179E5F55CULL, 0x5BE0C4A279CC2317ULL, 
            0x2C4BA756DAE47749ULL, 0xC4210C79125635A3ULL, 0xF3D81FED22586FCFULL, 0x9568C5BF4E8C0AB8ULL, 
            0x29B1B756014BC3B0ULL, 0x2DA6D37B2F417FACULL, 0x5D0C0AEB22B57CECULL, 0xE211450B6B51E77DULL, 
            0x6D49244A8277BBBCULL, 0xDF2A17302112ADCBULL, 0x676FF1D0D56BC20EULL, 0x88190886292B0AF7ULL
        },
        {
            0x7C4BF2B416FF014DULL, 0x88E50CA0FD4CAE3CULL, 0x1D12307ED9AA49A8ULL, 0x6E5E9F5BEF653779ULL, 
            0x4A175EBA8B7F1C51ULL, 0x4462355E4017801AULL, 0x99AA9A3EFC91D153ULL, 0x12A9C6E9FBF478F7ULL, 
            0x1E49F40893AA3D11ULL, 0xFC6B312AD3FC124FULL, 0x6C9542818C433332ULL, 0x2A709A9FEEA8F1C2ULL, 
            0x856C1C36EB9828F1ULL, 0x31F74904241B158CULL, 0x6325EF54B91B2D33ULL, 0xF2F172873030A72CULL, 
            0x1FC5A0CBED952543ULL, 0x943C01765E623B32ULL, 0x0A95E6195E451831ULL, 0x0BA96645B40CCBFCULL, 
            0x6221CE10DAD5A0ABULL, 0x8CE5BEEBE2CFB6ABULL, 0xB7AF3081A27EEEF3ULL, 0x5E5D991FFFFB53E7ULL, 
            0xF77955FCC957F7D6ULL, 0xE7E59D4E3D17B2B2ULL, 0xAE6AA94F06C8D94DULL, 0x8B1BBD1E0E9589C9ULL, 
            0x7077E73E1D58990FULL, 0x22A38A7ADFBA61B8ULL, 0xF8723E1B2C41411DULL, 0x7AC295F8BE6B5660ULL
        },
        {
            0x71DDC5F71F6CA345ULL, 0xA07096C2A8DADE65ULL, 0x88E0CB964B240B92ULL, 0xF49FB678C1ED5686ULL, 
            0xC0F9947935311A57ULL, 0x656988C4C2764674ULL, 0x15E4589FB3132D7CULL, 0xF6FA1750132CCF66ULL, 
            0x251E8A6685963CF2ULL, 0x8A6B17E7EF9DEB42ULL, 0x4D20AD493403B308ULL, 0x5E3C0C97B88F8D84ULL, 
            0x3A37400621F6BE7EULL, 0xFB1101C7FC89A48EULL, 0x4E571FE0549AE426ULL, 0xD1C61BDC116BF82CULL, 
            0xC06732B41BD7015DULL, 0xA582CC4D8E28D7DDULL, 0x8DB1205B7D692478ULL, 0xEA87DCB98261EC37ULL, 
            0x8C8F3939AF223DD4ULL, 0xECCC5B42C9544FCCULL, 0x742117F67A0F4991ULL, 0xC2EECCBCB84059DEULL, 
            0x99623B96C73356ACULL, 0xC0C18E8D022E3347ULL, 0x0F65D2ABB6F3CD8EULL, 0x7A3DD4174D847C83ULL, 
            0xDAC5E97D08A33B9CULL, 0xE1C51491291E0BCDULL, 0x0F05C076BD7B913EULL, 0x6603CC253111C335ULL
        },
        {
            0x7FDAB9B5ED5A54BBULL, 0x2D8F44BFC4356B9FULL, 0x9BD39B85BC0C382FULL, 0x64BFAE75949D3B43ULL, 
            0x3A5BEF9F52052F66ULL, 0x2D6D0529A5B432DEULL, 0xB7FA2331937A5E27ULL, 0x09D11DD65E67210CULL, 
            0x01091BF6E21490F9ULL, 0x67BC3F3037E7BD56ULL, 0x896BFB6225B7BB8DULL, 0x25447C30E1A267DCULL, 
            0xD2C5957B289B1FF3ULL, 0xD152D0E0AF042D30ULL, 0x802CE576AE0A7A16ULL, 0x9F202EF72EDCA000ULL, 
            0x2349B10D5B1B98C2ULL, 0x15ED1197243ECAF4ULL, 0x5396B84B1CF89F8AULL, 0x7315AC117F446989ULL, 
            0xA0565A5E27CAAC6DULL, 0x72BA9742E123744BULL, 0xD8362F627A2F8ADAULL, 0xACFC343F6D8272E5ULL, 
            0x3E194FBCFBFCD487ULL, 0x155E2FA158F72E5BULL, 0x37758D7A65B1E96CULL, 0xDF5EE4E4BB12EE6AULL, 
            0xE67D059830A682EEULL, 0xD9964B0435EE7F61ULL, 0x7DD51064598BB771ULL, 0x9CDC53313EF3F773ULL
        }
    },
    {
        {
            0xB9E8E8B8DBF86080ULL, 0x4D0A9D456C455B60ULL, 0xDE1A2969E816B4E8ULL, 0x2A9397139FEB8D17ULL, 
            0x33B13B27ED1268ADULL, 0x03C13A2172F506B2ULL, 0x1F363F33F3DEE01FULL, 0x9E1E423C9E7F689EULL, 
            0x89758799B78E8C01ULL, 0x9817888504360DCEULL, 0xB017CDB067FFB916ULL, 0x805881F75123E4D2ULL, 
            0xA2265FE2FAA4DB8CULL, 0x0C75D4873B41C2BEULL, 0xAD5021678AD142DFULL, 0x51E023AD3E2BC3AFULL, 
            0xC46E7A38F4964972ULL, 0x025161D79879738EULL, 0x18570118D6AD7AFAULL, 0x341F74771C86C491ULL, 
            0xF757A2CF313E40C9ULL, 0x3AC09E8F2917D430ULL, 0x2BA7C56923B496A5ULL, 0xFAD213C260E5E096ULL, 
            0x924123AFDE418BF5ULL, 0x13FC0AAF416B4B4AULL, 0x4E39C78A9C0993E3ULL, 0x672491AAB848622DULL, 
            0xF7EA0549F6AE2233ULL, 0xF1CDC0B9EA24A8EBULL, 0x60226F0BBD9CBD89ULL, 0xBE940813C7187F4BULL
        },
        {
            0xEAA9A6B6BAD1B317ULL, 0x518E040876D0D3B0ULL, 0x9F846881DA2D0117ULL, 0xB4C8F327849EC877ULL, 
            0xE16180BFCB055907ULL, 0x7E1DCBF7F8FAAB30ULL, 0xB216DD5C3BEFCFCCULL, 0x2FC7E74689A5B247ULL, 
            0x84416C488C39665EULL, 0x472FECAD7B54BE0DULL, 0xD1D2E29EBDCAED7CULL, 0x5C1945D757FC5718ULL, 
            0xD72E8A6A1680349CULL, 0xF0C13CA1932CF0C0ULL, 0xC7EEB4D86807482DULL, 0x735D5F603CEDC433ULL, 
            0xC2A72B50782C7B91ULL, 0xA768B99E3443C3AAULL, 0x73AE7514DD9EDC1DULL, 0x9816D54BE652F553ULL, 
            0x3137717441D86780ULL, 0x0AA74F9DAE16D986ULL, 0x8190C519F0450461ULL, 0x107E606BEC694333ULL, 
            0x26B023EF694A11EDULL, 0xC8CD914039B061CCULL, 0x8F85DEF2AEF73725ULL, 0xF210FFD1098CF29AULL, 
            0x131A1F54A74B3F2CULL, 0x19EE20697935299DULL, 0x480B03A67EBCAC59ULL, 0xCA92B65A7E47C953ULL
        },
        {
            0x07D85BD89C5F5531ULL, 0x0EE70AE02B0CCDE7ULL, 0x6BCD82022E7E3E17ULL, 0xCF39D67D1063B2BAULL, 
            0x6197D58C245753C9ULL, 0x4FEA54BA3F3FF509ULL, 0x1163D7F6C6CAD341ULL, 0xDEBDB8586EFA031BULL, 
            0xC5A0BFB15B27787FULL, 0x27DBE02F7C808562ULL, 0xF6A23C3498086000ULL, 0x5F6DB6D1EEDAC197ULL, 
            0x0633AA986BB7546EULL, 0x65DEAFC9DD407327ULL, 0xF92A1CFC5578E647ULL, 0x1D1A048797684E87ULL, 
            0xFBC671284EF14C6BULL, 0x7638B3127DC1164BULL, 0x1131AF572AD95479ULL, 0x1D892C196FC75183ULL, 
            0xBF85676930356741ULL, 0x9296D19C999BD7C0ULL, 0xCC2FEC3EF628899EULL, 0x431BFED0D614398CULL, 
            0xAA734AEFEDD6575CULL, 0x7B79AD992240D66EULL, 0x1A2D6AC9A7B53AFDULL, 0x2E3680D424C1198DULL, 
            0x9BC8F1264562DC01ULL, 0xDF5784C50DE5AEDEULL, 0x9B5062462A51F842ULL, 0xE31B5A736C0B6E4BULL
        },
        {
            0xF1AB437AA00EA181ULL, 0xCB16E176CB86B860ULL, 0xC8186C693840A7E9ULL, 0x61FF4ADD39F933E6ULL, 
            0xA25A103B85DCC574ULL, 0x5AFCA088901109BEULL, 0x2A90E08650AA1413ULL, 0x8BD8A9B1BD19D132ULL, 
            0x7553C8FB71F92A13ULL, 0x1DDABAF3C5F85F1CULL, 0x9C6A7E6E1994DFC0ULL, 0x60783CDB3CC223CAULL, 
            0xA2D00C71376C5039ULL, 0x404DF2D08ADFE7C5ULL, 0xC38AD55B71BBA5FDULL, 0xFE6AB3560F48D9F0ULL, 
            0x00FEF04B6BB4CA11ULL, 0xFAC55305DB35C704ULL, 0x917CCAD9B5FFDB03ULL, 0xB2098967D035E47AULL, 
            0x313A58E21F86F46FULL, 0x22A8F04D399E13E6ULL, 0xB2D73C91E63E94A2ULL, 0xA384F0F5690E89B7ULL, 
            0x20588AEB01B83478ULL, 0x4A7DFDC7CF29B897ULL, 0x56792DC11A076DFAULL, 0xABB10DFA8C0A91F0ULL, 
            0x1B6400257615B210ULL, 0x023D83DE0EACB231ULL, 0x272CB4D99CFEE71AULL, 0x5475939DB7C61C82ULL
        },
        {
            0x73001B8CD86DE2C9ULL, 0xCB702C119AA0824FULL, 0xD7223A277D99EC66ULL, 0x88C5DFD0EEFAC360ULL, 
            0x009EB658B74F4F8AULL, 0x637CEB53DC79973FULL, 0x9A941FA4865BD85FULL, 0x46FEDA514F4D39C9ULL, 
            0xF6D1D40C161857FDULL, 0x824C3428F2FD2A4DULL, 0xE587E1109A5B02F4ULL, 0xE68EF1A97C7B24D7ULL, 
            0x025E643DC8EC3182ULL, 0xE3A403095F8EBF5CULL, 0x094FCA4F29E68C8BULL, 0xFB09D10549C5DBF4ULL, 
            0x2FED71BE081F5143ULL, 0x5D66B297F1D9FB31ULL, 0xB66F26202610FF0AULL, 0x98FDAD02A3893AD5ULL, 
            0x8A557BFCC0A2F5B7ULL, 0x5C4EFAE85D0FDF95ULL, 0x169FDD8F71D73D9FULL, 0x589B87E6C235CE2CULL, 
            0x4275105BC2A2AD44ULL, 0x13F676CC46893E31ULL, 0x9BE8FFFFDC8CCC67ULL, 0x45C5E7D65DDB1DBEULL, 
            0xCCF845C65B229C35ULL, 0x5BCFC7229283B369ULL, 0x26DBB9C19AD3853DULL, 0x583961D5592169DEULL
        },
        {
            0xB492C87CB06E469EULL, 0x5A5DD050B97BE67DULL, 0x7F103494F62DD0B6ULL, 0x17559B18FF57CADBULL, 
            0x5D0EE3153B41B78CULL, 0x008B06483AEFDA8CULL, 0xFC57BC0F692EFC80ULL, 0x067FA08FED074468ULL, 
            0xDA3A7D2DEDB0E91EULL, 0x404A1E8CF59A2CBAULL, 0x3B9FCA080F0EC2E4ULL, 0xA3EE49EA0406AD02ULL, 
            0x188263713EA07CA1ULL, 0xD7201F0140D3D1BCULL, 0xA7688B40F58B3E05ULL, 0xE867C7524CECDBFFULL, 
            0x66657B4BD9D3949DULL, 0xA02811CE5E7371A4ULL, 0x6C1BEBF288FBB6FAULL, 0xAEB6359A8A1674CDULL, 
            0x62383EC63761CD79ULL, 0xEC5C14BFBA25029EULL, 0xD9F1239148D30789ULL, 0x51D9F491CBAEB838ULL, 
            0xA07F68975F993E04ULL, 0x1A9EA7E0C8619381ULL, 0x8450914637F13C1CULL, 0x950538533F914A79ULL, 
            0x4B7E2D38D0B29773ULL, 0x3436F39C64504525ULL, 0x3700BB7F476FF750ULL, 0x61544AE41D56C648ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseBConstants = {
    0xF6BFBD5286D90AF9ULL,
    0x18A7936597448F3FULL,
    0xA41F304D16F66992ULL,
    0xF6BFBD5286D90AF9ULL,
    0x18A7936597448F3FULL,
    0xA41F304D16F66992ULL,
    0x143495EAE1DF783AULL,
    0xB59A015CB481F289ULL,
    0xC1,
    0xBD,
    0xA9,
    0x20,
    0xBC,
    0xF0,
    0xD0,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseCSalts = {
    {
        {
            0x97582D66AEF7B257ULL, 0x086CC82B90539428ULL, 0xAA00934881F17A21ULL, 0x108E6D2781C6BF1AULL, 
            0x4B78D7B4CD4B613FULL, 0x73EBED3478A63A18ULL, 0x52E10C49B651351BULL, 0x6FD5C987C7B589D4ULL, 
            0xB2C0DA7802FFE5CBULL, 0xE646672A0D2049F7ULL, 0x4A6C8ACBA3160074ULL, 0x573BA18A15ECE831ULL, 
            0x9AB3CCE7AAA5EFE6ULL, 0xA2A6344D1F8F6E8DULL, 0xC79C00215EB16B4EULL, 0x1555ED3EF15B35A1ULL, 
            0xE56F22C2833CEA7DULL, 0xD5DA92BA0F642239ULL, 0x68693EFAE695787AULL, 0xD75059DFBC9B6E93ULL, 
            0x4F83DF0A0DAE0974ULL, 0xBCBAE23A0180CEFFULL, 0x34836E11D08EB7E0ULL, 0x3BE65ECAC6604888ULL, 
            0x11E1AAD0FE862556ULL, 0xEB99FAFDF9BD2C0BULL, 0x4AD105267A2D5782ULL, 0x134EBDB37554B353ULL, 
            0x48B06FB1B8A19928ULL, 0x93BCC985228178ABULL, 0x0F8C48A0D2E80F34ULL, 0x1170B2F62163A3F4ULL
        },
        {
            0xF1C6CD5A9AFF9AD5ULL, 0xA5143509E5F202C6ULL, 0x4CE34E846D186ABDULL, 0x71B3DB2E2213A43AULL, 
            0x3686AD6FE622B29FULL, 0x849EA41B7B5941E2ULL, 0x2A2462D5CE428FB9ULL, 0x9AE771DF4DD921D9ULL, 
            0xE11E7017EB061A61ULL, 0xD388CD1BE55D8E48ULL, 0x92939289F0A2E5B3ULL, 0xAF632DB19A70E516ULL, 
            0xF2893F3189ABDC1BULL, 0xF5C76A577558025CULL, 0x690DC8EBFC65AB07ULL, 0xCC5AE26993430C18ULL, 
            0x68034B78BB81DAE7ULL, 0x0ED6AFD76EEE52F9ULL, 0x30F122704CF4067DULL, 0xC288E14ECF85604AULL, 
            0xBF77B48E305D95DCULL, 0x742E86EE58B9CCE7ULL, 0x4E3C0FE50AB66974ULL, 0x48F4C0988F39634BULL, 
            0xD90B1932E20B7BD9ULL, 0x8392CEEDD79FC2C8ULL, 0x5587DF5802E6CD05ULL, 0x140E33FA2D9912ADULL, 
            0xA51D4EDF1D648C75ULL, 0x7D091F6451E74636ULL, 0xE27CC89326911ACCULL, 0x8CA86A4C19536330ULL
        },
        {
            0x4D213FA18A6B2560ULL, 0xF8E3280FF40A3A03ULL, 0x442064248E1390E1ULL, 0x4FD8C23EF4839AC4ULL, 
            0x22EDBC9856B6ABFFULL, 0x7EA0DDBA4C424138ULL, 0x3E6A9C481918E2D7ULL, 0xE669A7CBA66E0798ULL, 
            0x343387AFA9A994C1ULL, 0x797BEACE92055D13ULL, 0x435DD2BAE13DB6B6ULL, 0x1C86D9CC2DF369A5ULL, 
            0x0584864560A5FCD1ULL, 0xB9B7AC3D9419D766ULL, 0xA2CA2ECA055F6803ULL, 0x09AE8043F1E7314EULL, 
            0x96EB0BCEECC3AFD8ULL, 0xB20CA9AE885F2B09ULL, 0xFE7535CD84F3BD9BULL, 0x3589EA2BFE6927F8ULL, 
            0x3BAAEEE69A313FA3ULL, 0xFBA440421D41F07AULL, 0x2598491D30547527ULL, 0x922E331E4395117CULL, 
            0x3DACBFBACC7C9190ULL, 0x9B7F8DD7AF1B1A6DULL, 0x09310D0F226296CBULL, 0x98E8D3AFC81D5AB9ULL, 
            0xAEE539A71E7365A2ULL, 0xC7EEB9C6B8AE005BULL, 0x862C8AB3D7FFA893ULL, 0x95AB3B21CE8FB4ACULL
        },
        {
            0xDBB5EB709F22396BULL, 0xBDD6D3002F284D8CULL, 0xEBD2BA8BCD00E173ULL, 0xDE8D773D3307C26BULL, 
            0x8DE19AC56B2002D1ULL, 0x0E80690311A4E116ULL, 0x54AFE7DCCB7D0775ULL, 0xF3D9C28ED0E66874ULL, 
            0x05B8BC3733027CBFULL, 0x4684096BA31955C4ULL, 0x164299B760D22334ULL, 0x52A9226FB6C34BD7ULL, 
            0x00F06BE991752D2DULL, 0x2605E64D57A1DAF5ULL, 0xD0B199ADB5582A39ULL, 0x616D318C75FE6DE0ULL, 
            0x4107B3DCA38D089DULL, 0x8495B85819C76B44ULL, 0x5D2C723B5E4966CDULL, 0x5C820E5A6C1ED09DULL, 
            0xD23B8D494E94F58CULL, 0x60BFFE513A82D60DULL, 0xF99A82561F0A5EEEULL, 0x6B4DB68AD045AFC5ULL, 
            0x73FF8CAB51CF3A65ULL, 0x918584630CC16DDCULL, 0xD3E0F5554D1E4270ULL, 0xD1336CA7A4838566ULL, 
            0x143860D2160AB6D7ULL, 0xE355BFECE786D427ULL, 0xE069CC1001D54A67ULL, 0x5C989516E8EF19F9ULL
        },
        {
            0xD15E7867B2ABF982ULL, 0x33EC938371B04EF0ULL, 0xD50CDD538C2D1863ULL, 0x04924C68ABF3F05DULL, 
            0x949D6241B77C6AB5ULL, 0x0FE7ACE5BDED434DULL, 0x54CEBAC2E2DEA581ULL, 0x3DE8C7255CBF8F28ULL, 
            0x00E358623A1EB580ULL, 0x20E9112FBAB0FAF3ULL, 0x251EEC9E1163E8C2ULL, 0xBE13F2C52DE730E8ULL, 
            0xC6404EC45B133114ULL, 0x30038691C2E1D301ULL, 0x75F0B662804BE435ULL, 0x5C53463C1E1CDCECULL, 
            0xF6B6C4D45A5601B1ULL, 0x85948C75A5E76EB2ULL, 0x5119E08F27F595E2ULL, 0x060805D38D497E1BULL, 
            0x46BF9E60304A4F87ULL, 0x2B2DF35241600D01ULL, 0x30F2E1DF1792BF14ULL, 0x75EAEA7BA4A39653ULL, 
            0x1B2505B1BE59501BULL, 0x96795C949011D2FAULL, 0x1C0D6A043D1D497CULL, 0x2CAF694AB02B824AULL, 
            0x948C2C16156F29DCULL, 0xC3086DAEFEB7226DULL, 0x2DE0EBD687948887ULL, 0x2217843A0E0B0D7FULL
        },
        {
            0xB82503BD4CFEEDE8ULL, 0x9956F810F1F678D3ULL, 0xAE6C0C81A734C9AFULL, 0x887232C40C1011E8ULL, 
            0xA5DCBFD3C8430707ULL, 0x198C99D5D41C1F65ULL, 0x0B015403125C2A12ULL, 0xA67677EB196DCF0EULL, 
            0xA515AB8EBEAA70AEULL, 0x919B216A8A01A291ULL, 0x3540A28232C430CDULL, 0x5AD0FA0E71000AFAULL, 
            0x73832DCD79A486FBULL, 0xEA5EDE28B279FB81ULL, 0x24599FA914D8B721ULL, 0x74E4E68AB48BF1E1ULL, 
            0x1B69C20902D50786ULL, 0x4B847DC49CA7B6F8ULL, 0x87E20C1A06D68B3AULL, 0x83E7AA149E70E879ULL, 
            0x486AE57E4A23BB2AULL, 0x130AF799F431FAF3ULL, 0xFCDC3F357293E4EFULL, 0x2338E639557E73CEULL, 
            0x499353A156503FA3ULL, 0xDEA3DAE6E2177A26ULL, 0xC950E4B046156E42ULL, 0x142E1757B6E84BDBULL, 
            0x7F2D675487604542ULL, 0x87D26F8B0BBF5450ULL, 0x3FF6536E6C386D77ULL, 0x5B4DE3C5641FE79EULL
        }
    },
    {
        {
            0x3322B84CD1284D13ULL, 0x5D4279865E6DF39EULL, 0x73CA078E848D00A4ULL, 0x1C1ED63BF831E9F4ULL, 
            0x24C916595EFB1A74ULL, 0x10518B5CDED02AE9ULL, 0x11076E1727D8558FULL, 0x71F8BB43D58E6508ULL, 
            0xB8637C9FE80AFB02ULL, 0xF889405826C8DF06ULL, 0x18C19072501A82BFULL, 0x2DD60EBA24A78D94ULL, 
            0xF742D7CC2B1756E5ULL, 0x52A781D48766A445ULL, 0x593816361879A524ULL, 0x8059D176F7893923ULL, 
            0xC83751C316C72F73ULL, 0x35AB0AF566E52C18ULL, 0x93197668E612B9E0ULL, 0x906916436A2624D5ULL, 
            0xC30A51F992ECF97FULL, 0xAD73C29CBDAF5AA8ULL, 0x9350B8015155C00EULL, 0x3DF1B49E5D9F4189ULL, 
            0x1FB9809086E51442ULL, 0x0890441830E9D841ULL, 0x324AEB6F0F737254ULL, 0xD2AFB59917520449ULL, 
            0x1FA0BC8E75399611ULL, 0x8FE4FE43B9FDE775ULL, 0x8DFC320462B6F170ULL, 0x697CEAB2909A7C42ULL
        },
        {
            0x7224D4487EA10C5EULL, 0x7BD9A4057C298A6FULL, 0x2C4CAB9DACC178D1ULL, 0xDC42A4098778FC07ULL, 
            0x9219AFA4F0BC6098ULL, 0x299E33FE8D4FB688ULL, 0x536707968598AB1DULL, 0x9D53CA29FE0CF33AULL, 
            0xAB691B2730EA3ED1ULL, 0x16B0B309F17AD290ULL, 0xF44089B4144763F1ULL, 0x4370AFAC51C509D8ULL, 
            0x2E29875F46101194ULL, 0xD00A02B13388AEF2ULL, 0x320180B01D2F3D59ULL, 0xEA96593755A7B5C1ULL, 
            0x1280A5D79F535657ULL, 0x7767694AC66863ADULL, 0x067DD5A7C4E68378ULL, 0x49F8EDA15820A413ULL, 
            0xB93C0E999917B599ULL, 0xE01EC144CB55C7C5ULL, 0x13C8B51BD9CFD2F9ULL, 0x58453113A1F292CDULL, 
            0xE70DF276EC10F3CCULL, 0x78C522F85F88E3D5ULL, 0x842864540720DBFDULL, 0x6894483E4BD6361AULL, 
            0xFA309DBD329AD4B5ULL, 0x6FDD7E611C778515ULL, 0x999F872B189659AAULL, 0xA82AEF58DB54A78BULL
        },
        {
            0x39C0C58461E6F8AFULL, 0x7B96B517B06CDD2BULL, 0x84346EE2AB203BF5ULL, 0x0C6AD7DF9EC07213ULL, 
            0x4FB715FA9274A0A2ULL, 0x2957D4A4881AC28FULL, 0xCD50301D859D94BEULL, 0x9DFC9068408CBFA3ULL, 
            0x50A3978C4620A2A5ULL, 0xABDF42D67B6C1C2CULL, 0xE6AFAE50600F6237ULL, 0x001A14730B2292C0ULL, 
            0xC1CF68FE83066CD2ULL, 0xB71AC4D05CBEE2E9ULL, 0xEE4520EBDC5FC08FULL, 0x9A46E34CC3082141ULL, 
            0xDF210F0ADBC2E546ULL, 0xCD22EAC0F137DE4FULL, 0xB3966489BA5C920FULL, 0xAC05620B813282D5ULL, 
            0x3B79993D35E7C1C1ULL, 0x0EC1A07BFF8264BFULL, 0x15444061532300DAULL, 0x062DECA91CA609D5ULL, 
            0x5C28C21787101364ULL, 0x8746F26B3C37F891ULL, 0x636A25A68CB12BE4ULL, 0x419286391DFD7E68ULL, 
            0x6216199C0AB80CBDULL, 0x13BE8528E2A902A5ULL, 0x3B2AF9612D247F27ULL, 0x5D3810595A097869ULL
        },
        {
            0xFBA35DF647C69991ULL, 0xCA748D54C00FC5A0ULL, 0x134726CEE230FD80ULL, 0x1220C4179CA6CEF8ULL, 
            0xCC967CAC5129C117ULL, 0x0D2F0F4B9F2E9BBDULL, 0xA35B4DBE653F657DULL, 0xD44444F47ED0D464ULL, 
            0xA37A9C9548A6BAB5ULL, 0x785B478C13225ACEULL, 0xEA50C0C07A16BB60ULL, 0x8AD26852291DD38FULL, 
            0x6B0883B17747F921ULL, 0xE7A57CD91806DEBAULL, 0x4CE853386D692BAFULL, 0x313F3F7689B410EBULL, 
            0x1E8C8E18A8963023ULL, 0x4C186C24AF71DE2CULL, 0xCC60C860E25095A9ULL, 0x3C4CEB6EE1BFB698ULL, 
            0xCCAC8B24360D1D05ULL, 0xC4A6643D54C92CD5ULL, 0x27489AE62AAFC1E1ULL, 0x74655301B29C4FFBULL, 
            0x59AB4BFDCEDF86EFULL, 0xC5E4EEC2B00DCA21ULL, 0x4FF6CECD1ECC1F92ULL, 0x49FC75BEE2D94448ULL, 
            0x7FAAC2D23ED49ECBULL, 0xAFE098AEDF8A0355ULL, 0x23737BD71889DD38ULL, 0xCA1FE61869C7DDF1ULL
        },
        {
            0x439690D1A46742E1ULL, 0x26C701F4AD379E05ULL, 0x2AF1F4414274D3ADULL, 0x6C399C630CE3FD34ULL, 
            0xFC266FD3502EC226ULL, 0x0C2373B356DFFBADULL, 0x0B5A6CD89A6C0873ULL, 0x11A6F91D418E1829ULL, 
            0xB2C80D2E219F0784ULL, 0x7DC2B0443E89A77FULL, 0x6BFA8B19F55A2A29ULL, 0xFAEE1C1A258B41ACULL, 
            0x8FE91C8E9E9CF526ULL, 0x08CA6BEBE75BC8ECULL, 0xAC68A5C7E17BB197ULL, 0x2BBAEBB72F02A7A3ULL, 
            0xA36C646E68DD7876ULL, 0x29922D78723F6346ULL, 0x63A0BB563557D202ULL, 0x098646CB3FF2376AULL, 
            0xE8288AB11C195AA9ULL, 0x240CAB4529253F8FULL, 0x70EA9ABEB069514FULL, 0xF6274E0B9A5F3D4DULL, 
            0x5305ACCE5C6B19E7ULL, 0x387EA513A6E7A224ULL, 0x202F2F68BB4B427CULL, 0x1E55D13AFC2E3A3EULL, 
            0xDEDDD805C9ACD471ULL, 0x4B4EFEF04679D940ULL, 0x553B1BF6FAC2D5F3ULL, 0x92A589F945FC1F4AULL
        },
        {
            0x481F35570C740546ULL, 0x75CC3585C4D232C0ULL, 0x0C28C3F8A09072D8ULL, 0x64BFC24E22DEC112ULL, 
            0xF0AFCE54F67889E5ULL, 0xAF0F3C6123A209D8ULL, 0x913BAB64AF69EF9CULL, 0x8BC874A1A705E1FAULL, 
            0xAFF97B98CC4EB8BDULL, 0x31615B60F6E11E50ULL, 0x17EAEA7432DA7492ULL, 0x6DF1C2AB38CB11E4ULL, 
            0x10F180C74E06A8C4ULL, 0xCDF6046808715D6EULL, 0x8C545B051B9FF4E9ULL, 0x763D67D9383C4DDCULL, 
            0xCBCBDE315BA49007ULL, 0xF621BE72566A9A14ULL, 0x3DDA5F21F8BF356FULL, 0x707B9CD355A8012DULL, 
            0x8C47B9D290EE0624ULL, 0x73F3B1DB3E4A527AULL, 0x198C6F5D8005704AULL, 0x00DC2B46EF827D4EULL, 
            0xA1FB6E6B18D62941ULL, 0x6F148A30D85C3900ULL, 0x10B8F0CD17B64475ULL, 0x132669D646DF75A7ULL, 
            0x1B3238662B437FA2ULL, 0x5D04C09969344DB4ULL, 0x48C595405C63699EULL, 0x5045AE9E9171D3EFULL
        }
    },
    {
        {
            0x7FB0F9719730A02FULL, 0xB02AAC4DA90625F0ULL, 0x78377853825ADD9CULL, 0xE32BEE3F142BA4A8ULL, 
            0xB2E5F160F41978F4ULL, 0xC02C7AE79F6692F6ULL, 0xA038493CBE7B2ED6ULL, 0x2DF3FC3C74FE5027ULL, 
            0x27C5ED2E5B8FA5FDULL, 0x6FA4F49D59DBE9E6ULL, 0x79293E649CC49EC7ULL, 0x92F5163C84E50822ULL, 
            0xB32F21A8A7896AA3ULL, 0xDECA9BDB12A30119ULL, 0xF8635FB8A1971474ULL, 0xA50694893C11979CULL, 
            0xF4448E5BBB42700DULL, 0xDE2FC012D69A0E98ULL, 0xF9E79D17FD5DB862ULL, 0x1A3FCD19EAF62BF2ULL, 
            0x50D496FCC906A7D9ULL, 0xDE47EF9943BF8D8EULL, 0xA349CE626B82813BULL, 0xF26CF71B2C37E3DBULL, 
            0x75C9FBCE2000D734ULL, 0x61E059ACF3FB6C98ULL, 0x5A3E3432F83CBFBDULL, 0x8D371B6FDC182342ULL, 
            0x36049400E675F9EDULL, 0x3FFB9DB54568C12EULL, 0x34D79F158BBE54D4ULL, 0xC05C4A380CF06A8EULL
        },
        {
            0x1C2531F43DA15961ULL, 0xE06624EC12060654ULL, 0x2D1C23EFF25DF276ULL, 0xABFE8D837055C208ULL, 
            0x72A19EB3E9DC6462ULL, 0x814D7B53D6DAFC23ULL, 0xD0C93019D45FD823ULL, 0xD24D8A33A013BF5FULL, 
            0x82D4BEC422B1FB76ULL, 0xAF67314046A2B9BDULL, 0x5A27209CC5A4AE09ULL, 0x9DC27F4CA8209B6BULL, 
            0x7875F7D1EF6E64E8ULL, 0x6522E80A02214B5BULL, 0x14B7A8E606634CC1ULL, 0x2C26BE578364C327ULL, 
            0x7D1C23DEB7F4AA1EULL, 0x146F157D3514AD55ULL, 0x6DEEF8147915E116ULL, 0x426DD600AAD03C4BULL, 
            0x439B8C1552C9A471ULL, 0x9128C7EFA22B76FDULL, 0x02A49EEE655D6093ULL, 0x1CEFB7FF096E7D5EULL, 
            0x2ECA8C725977AF54ULL, 0x69A88B54C4043F49ULL, 0x9FF64A020AD4338DULL, 0xB4420B2887D51BB5ULL, 
            0xFF7BCFDA3EB06E66ULL, 0x8CB33CF3420F63D2ULL, 0xC0B2E14DF0CFA801ULL, 0xF7ED0BA546CDDA1EULL
        },
        {
            0xB4514674756F9C84ULL, 0xD3C8D8DDD6A76472ULL, 0xF33410E88210B44BULL, 0x57D3DD89000CA256ULL, 
            0x7CB9CC2EDA20A6C8ULL, 0x98300C0F5CF7ADEBULL, 0x5717EA0713FC251AULL, 0x5EB73E8CE2211A81ULL, 
            0x15F9BE6254BFBEC7ULL, 0xDFC8FF2937360508ULL, 0xFBD3DDEBF6D582A1ULL, 0x4BC4C7DB48BE0213ULL, 
            0x9124A43894BED360ULL, 0x510FC04879DCA0A0ULL, 0xDF2F23D09E13D585ULL, 0x42D762468902FD60ULL, 
            0xEC2BAADFBBCE38F0ULL, 0xD399C0657B87AF64ULL, 0xFD159DDE1119C68AULL, 0xA118AC5B5CEC6999ULL, 
            0x8F8DA73F50A78C46ULL, 0x8AAE285FC66E15EFULL, 0xFD65501506B473D6ULL, 0xF11026EDB22511FEULL, 
            0xCDBC772BA4300937ULL, 0x8D5BC8A8AF7175FCULL, 0x0A7191ED2093E41AULL, 0x73E1884ED06E3380ULL, 
            0xE3108ACEA9867416ULL, 0x4057B4D2DE68C044ULL, 0xF5B2F14DF5EC7DD2ULL, 0xF6D008D35F257339ULL
        },
        {
            0x148CDFE4D0300181ULL, 0xE3AFBA63E8252BD8ULL, 0x0FE41812C9CC7B7CULL, 0xA783CC5C59326EA4ULL, 
            0xBEC408DEF826B0D2ULL, 0x94DC6E805D2B2220ULL, 0x51DC15EC86BF0F6DULL, 0x22B4ECCA089880BCULL, 
            0x48AA753E692206C9ULL, 0x08555CB3E87981EBULL, 0xC0F4928E16DC12FEULL, 0xDB6D25BB6ADD996AULL, 
            0x89C85022CEAD0AD8ULL, 0x0C8F8F3BAB9DC024ULL, 0x832C91E1E5439E2AULL, 0xB05439FA313EF59BULL, 
            0x54F07F995817A9EAULL, 0x283E7702D38F13B1ULL, 0x8DCF2964765BDE2DULL, 0x2B1259863AF9053EULL, 
            0x359D79FA10225D2EULL, 0x62E0CEC44FEEF1B8ULL, 0x683A25A4FCD22F6BULL, 0x189B4B24D89411A9ULL, 
            0x1CD19BB13A5D06B7ULL, 0x1EAD582C590366DCULL, 0x3424239AD86CB579ULL, 0xC4F78F8A0567078BULL, 
            0xD6B61DDC1B64A1EBULL, 0xCF40E9DE05356699ULL, 0x878C377AFEC58F07ULL, 0x1180B5AD200296E0ULL
        },
        {
            0x5AEAA8BBA0A13143ULL, 0x872641023A17611EULL, 0xA37043A5BCCE76FCULL, 0x794160113C5D6529ULL, 
            0x5F9186D65523F1BDULL, 0x02692459667B28DEULL, 0x5F7978E711D78B8FULL, 0xDA9787D4DE77AFFCULL, 
            0xD94FDFBECF81BA3CULL, 0xDED16B2E71291746ULL, 0x1D298CDD57DFBDB3ULL, 0x68CDE350629F64AAULL, 
            0x6AB9D75B00BD5717ULL, 0xBFE29985E61BAB84ULL, 0xCA3919D0558DF4E2ULL, 0x5E784F445E200EC4ULL, 
            0x754478271502631AULL, 0x0A3DAF8407744B10ULL, 0xEE798B95022D566AULL, 0xED726A2D3F658A66ULL, 
            0xAFA007EFA57B5CF1ULL, 0xCDE0AA560C7C251CULL, 0x95700598F19E34F7ULL, 0x093A7F4889D845E0ULL, 
            0x8DA1CA14799A2019ULL, 0xD867A32D78130E43ULL, 0xD1B138FE23A96BAEULL, 0x1CA0BA95055E1E7FULL, 
            0x99426F4919EC7510ULL, 0x9C4B2B9965FF07A2ULL, 0x84FAF507CA000191ULL, 0xCB646F469145A794ULL
        },
        {
            0x8CE4917F43BF985FULL, 0x285915D04917FAD8ULL, 0xC74DFFAC1758AB6DULL, 0x6B0919AF069782E6ULL, 
            0x990AE86156BB9505ULL, 0xC352EE9A646811BCULL, 0xDB3051E1F0CC4F15ULL, 0xB586CDCFB2F30AC4ULL, 
            0x65F026606F967B5FULL, 0xFC5A652E3F7391B0ULL, 0x099164D48B16DF2FULL, 0x2B18D1F2608AC2CCULL, 
            0x5FF8C6B2F724D2F5ULL, 0x807582543DABFDA3ULL, 0x1F72144C017942B4ULL, 0x9A54F33081380B81ULL, 
            0x7C568D85183F882EULL, 0x3D61487F7132B022ULL, 0xC93BC93A991A3674ULL, 0xC127378F4D397DCBULL, 
            0x150E456ED0194F61ULL, 0xC7FE703B17F9CA43ULL, 0x8B57CF5A9D824618ULL, 0xB79A6B18C0E3A21EULL, 
            0x4916CDE0F8428052ULL, 0xDE9EA45EA315CFDAULL, 0xB37323C82C2126C7ULL, 0xBD4DBF8B545BAC5FULL, 
            0x24633E99E8DE84B4ULL, 0xF6E98D7CDB7A36F1ULL, 0xF09C9631C23B9FDEULL, 0xA6E2AFC264CD10A7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseCConstants = {
    0xD4813060D66D2485ULL,
    0x1A26BABD941A8637ULL,
    0x6CFAE2C7CDBC9483ULL,
    0xD4813060D66D2485ULL,
    0x1A26BABD941A8637ULL,
    0x6CFAE2C7CDBC9483ULL,
    0xE01957FD6B4DC1BAULL,
    0xD4F18B678E7001D2ULL,
    0x33,
    0x7A,
    0x39,
    0x13,
    0xE1,
    0x51,
    0xD8,
    0xCF
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseDSalts = {
    {
        {
            0xFF7E29051912E263ULL, 0x4E758C7DC167F947ULL, 0x45951C81D3C7880AULL, 0xBCF73ABD0CDBFDA3ULL, 
            0x59392F8B3AC136A1ULL, 0x98093D000A5A8B1EULL, 0x4D4E23482C7F363CULL, 0xAAD8C6E9789A4D73ULL, 
            0xD0F8776443B4A375ULL, 0x06EE173C7CB5D2A5ULL, 0xBB041BDB84C9D62DULL, 0x65067FC8CC990DFAULL, 
            0x3B9C7649FE4222C7ULL, 0x4125005F7CF4D436ULL, 0x6357716B57BCF644ULL, 0x524C643A8A216929ULL, 
            0x4E38CD2F3A080774ULL, 0x319851FA4E202C57ULL, 0x6DA3B222E53F2162ULL, 0x7A248DD056C796D3ULL, 
            0x4C434C7D0B9B7CCBULL, 0x2947E2E59DB80C08ULL, 0xEF6EFBB3E644974DULL, 0x1B2BB0B41D002450ULL, 
            0x7ACA7AC737DFB4D0ULL, 0xBB06FEC57A913F84ULL, 0xE4925204C7E5F252ULL, 0xC4BA6D11D3AC7003ULL, 
            0x2569147B2C0619E9ULL, 0x116BD4038F0A4F0CULL, 0x14F9865DB01122B6ULL, 0xC2888A62F0337201ULL
        },
        {
            0x03C6D2367D25D64EULL, 0x8BD491D55DA254F0ULL, 0xC999156DAFCD2056ULL, 0xA44396422DD9B3F0ULL, 
            0x73DC4C25CCA6C73EULL, 0x426B5C782A8D5FA4ULL, 0x05BB2AA0CB079C05ULL, 0xC9E89421A37397DBULL, 
            0x8BD1738935087331ULL, 0xEEE478979259D7D5ULL, 0x73A893F365C24B3EULL, 0x18022192A120D0ADULL, 
            0x566F857EA46373A7ULL, 0x9FAB1A5786EEB2C1ULL, 0xE99959F54B902248ULL, 0x7150B21320E27A64ULL, 
            0x72664CBD7BE1E83CULL, 0xCB6834E914A154C7ULL, 0x76600318B9FDF435ULL, 0x49A386CFADA9B9F2ULL, 
            0x870D4B7AA1B2643DULL, 0x5F403AF3EFB8E2C2ULL, 0x32FB2005E44C8AFCULL, 0x7FBA4BA560477FF7ULL, 
            0x5269F32EED932571ULL, 0x4ABAE8456509FB60ULL, 0xC43E0F2C86F60EFCULL, 0xBB72F5B605B1AB04ULL, 
            0x58343B942AA5C215ULL, 0xB6B004D7F2D39CA0ULL, 0x5DBAD1FA77CA84D3ULL, 0x30448F25D55C810EULL
        },
        {
            0x7CAA8358314B9983ULL, 0xDB7B61DC91EAB4E9ULL, 0x5590B4AF1CC781DDULL, 0xEC9C5F8F7DF75F2BULL, 
            0x572768F4F2C80F0DULL, 0xC753DDFD6E74DD7EULL, 0x29E1389782507F6AULL, 0xFC89802129C6F0B2ULL, 
            0xEF70CBF0E761E5EAULL, 0x5E970156D4AC28C8ULL, 0x9C3A95A59673C0E0ULL, 0xDA58BF190E99A2A3ULL, 
            0x5FE91AC631DCEBFDULL, 0xB7383FCBA6014C03ULL, 0x9541A409601E3561ULL, 0x0D867CCCE7708365ULL, 
            0x5726C854E5EBF635ULL, 0x383608667266064BULL, 0x41AF8194045DF493ULL, 0x9F8130D723B81033ULL, 
            0xDAE4984E8CFE29FFULL, 0xDB41CA935368BA3CULL, 0xEEE18286993B0C2DULL, 0x824D2925ABC27EE0ULL, 
            0x9666E639D2848394ULL, 0x80F9DA15065F7703ULL, 0x4FBD7CCEE76B09B2ULL, 0x6CF089E1C3B33EDAULL, 
            0xF78FB5225B4C1CB2ULL, 0x316ADC3BE911DD8AULL, 0xD7EAD1C2AB0701AEULL, 0x9DE2A68146DF9B9DULL
        },
        {
            0x9B33503D04108AA3ULL, 0x94E6F52253DB91A7ULL, 0x9F12FF5018874E9FULL, 0x54FA040457C26AF6ULL, 
            0x42BE2C2D3F419FE3ULL, 0xF355316A7C9A7F46ULL, 0x9C3872B2F8C864DAULL, 0xF22FD2F7307EB124ULL, 
            0x092BFF8D3B04C61FULL, 0xB21B4CFAF9CBB6A7ULL, 0xAFA24566FF488875ULL, 0x1339529D3E5E05DFULL, 
            0xCBD482E360C2219CULL, 0x8840869206CDC739ULL, 0x65140613DC506EBAULL, 0x96CDBA351A44E2CBULL, 
            0xEACD95308FDD56AFULL, 0x3D82FEB33C6AC7C6ULL, 0x8E3FB77724F617FDULL, 0x85F2FDC7524A1709ULL, 
            0xB5DE38D762629CFEULL, 0x5C84560A8F34318FULL, 0x3BEDE238FBD21648ULL, 0x3D4C845C2A1D49DCULL, 
            0xEEA3CA1EC9C8A262ULL, 0x6DA7A3064E3393F2ULL, 0x59B81E6CED98DA80ULL, 0x50AD76473F0C2B28ULL, 
            0xBCA71E0320C37EF1ULL, 0x70CD729B0D25CC9FULL, 0xC4B68F76CC8E0802ULL, 0x9D2BF92A8E26C6C3ULL
        },
        {
            0xBF66CFE8A911AB89ULL, 0x0CE468456A699ECBULL, 0xB6AA21FB894890B2ULL, 0x91130E8847E1838BULL, 
            0x8AA30211866E1BF8ULL, 0x694B22BFA949BA25ULL, 0xD4A224CE5E9CADA8ULL, 0x1D62C5D300290036ULL, 
            0x835F0CF22B621B03ULL, 0x18AF48A8F8D7DE17ULL, 0x43BE2B5C336A79CDULL, 0x9D00BBDE3D624C8EULL, 
            0x92BFE233CEE25A48ULL, 0xF4E2909269A5E85BULL, 0xA48CE65F1C247444ULL, 0xCDF2F6803ACA58E6ULL, 
            0x57753074104A6B93ULL, 0x3FFEBF0535D0515FULL, 0x79E9D30875A8EC92ULL, 0x463BAD446426867FULL, 
            0x2F338B0E2E1F3E84ULL, 0x3CA1B57CE804CA2DULL, 0x416F5A34D2CF13A4ULL, 0x456A891304326E1BULL, 
            0x9961198E6F4D5685ULL, 0xF151B6D2B50747D4ULL, 0x9C436038A4D26F29ULL, 0xF3ED63923F5FF1C7ULL, 
            0x36F93D7E77829DA7ULL, 0xDFBD8C7E7C2B5FD1ULL, 0xD43B623F41000248ULL, 0x40981922C5F7F76BULL
        },
        {
            0xECB90A29458127AEULL, 0xAAE653A12AA23AA0ULL, 0x7D8D047446C0497AULL, 0xDB83B9E71058719DULL, 
            0x2A2AA0F9D007BF7BULL, 0x417B355E65713A3DULL, 0x368326CBE8FA61C6ULL, 0x69B19C7EE8822891ULL, 
            0xC8763576A4D45C72ULL, 0xEF7F01A823DEE357ULL, 0xB432D0F6F28E5503ULL, 0x3F8F2C2807FFDB31ULL, 
            0x9DA3AEA1541EA702ULL, 0xC15D643B9D8FDC5FULL, 0x5A4526A8E0AF174EULL, 0x0C99C1B863576324ULL, 
            0x34BE03B6831B0E4BULL, 0xFA5E4ED461DBC995ULL, 0x88ACEA7D7AD35F41ULL, 0x74F0E877F7E36107ULL, 
            0x573CB72DB07FB59EULL, 0x643AA06124F84175ULL, 0xC6BEAB53A01D1C77ULL, 0x08B4777B76814EB8ULL, 
            0xE31B03EE026EB95FULL, 0x762D9C72489DFFBAULL, 0x2B22C0567C15B4F5ULL, 0xABC348D3FFB05842ULL, 
            0x5B5DD7D234C93589ULL, 0x23465D94C7F4C37AULL, 0xE78F56AEFE7AF998ULL, 0x135408F412E43646ULL
        }
    },
    {
        {
            0xA062BDC701CB20BEULL, 0x8D70A3D1B115C201ULL, 0xE2B4BC09338FD53BULL, 0x6642B3AA29573D9DULL, 
            0x1DBB6CFB51BC15DAULL, 0xD6797940F6A42331ULL, 0x6E216EDC188A78DFULL, 0xB58067E2F85B8D45ULL, 
            0x26960EC3CFF8D0CBULL, 0x7D520C355A1C88D8ULL, 0xDF03C2D6D1C7F914ULL, 0xE2AB9E4FF462BA67ULL, 
            0xD654035786926971ULL, 0x5B07E05161C791E8ULL, 0xB1614408AEEDE16BULL, 0xCF54C74DE7ABD08FULL, 
            0xBBE11A819675A725ULL, 0x16A6CE55570FD668ULL, 0x6EE39DC1E3412CB7ULL, 0x06D2CB26E30C683EULL, 
            0xFA6C6A87190A958CULL, 0x0A6AC565F18F2CFAULL, 0xFBCF134178A8CAD8ULL, 0x7B731B04B91674CDULL, 
            0xB1D89853A047749CULL, 0x3492EA72A2B1BF8FULL, 0xEFD3C6C6FBBEF336ULL, 0x2F8B995CC0D5CFD4ULL, 
            0xA642D8F5A1F383E7ULL, 0x353926A2AE6D6D40ULL, 0x657889AB17D7651AULL, 0x38DDF41B717EB456ULL
        },
        {
            0x84094B4167F56151ULL, 0x20E5332BA6F1249CULL, 0x61D40C9F79B9155BULL, 0xE079EEDE2EBA0708ULL, 
            0x694907BF81A32606ULL, 0xFA2EABC5B14E4C11ULL, 0xC58E6D3E4283F6EAULL, 0x743D587C712D3B61ULL, 
            0x2B85CA751FB9290AULL, 0xE1EEEAAB5A9B8AA2ULL, 0xD2D04637A99E7FA9ULL, 0x745FDA7036321961ULL, 
            0xF74AC53A82450D4CULL, 0xFA956933ACF975A4ULL, 0x37FE0DC1AD6D13ECULL, 0xF44766472F949E1EULL, 
            0x1EA22A51578BFC78ULL, 0x9E1C1FA244FF04D8ULL, 0x373757BA14F9864DULL, 0x3B9D8932398EACABULL, 
            0xDF3123F2A987B50BULL, 0x92D5DAA0ACFAEB16ULL, 0x009D5132DFD9DA3CULL, 0x036AA15A0D2EF2A1ULL, 
            0x33DF93656C18B9F5ULL, 0xEC0B36CC14B97887ULL, 0x58291787905D5022ULL, 0x65C998D97FB320C2ULL, 
            0x827B491D3C553C83ULL, 0xEAF45BA71113A1B4ULL, 0x7C3970298542E0EEULL, 0x2CD12FF590A07112ULL
        },
        {
            0x13C6DAA3DEE7F387ULL, 0xCB5164D4F02C9404ULL, 0xFCC2CCBE983988BCULL, 0xE43CCAAF0C1C886FULL, 
            0x57837D682C91AAEFULL, 0x8E3B92BABE017A69ULL, 0x4466E57D00E71481ULL, 0x2EFFAD663DFF1A3BULL, 
            0xB7451B250577ACCFULL, 0xE07A02ECC28998EDULL, 0xE3379D16D09486FBULL, 0x6649F723AE98BFDAULL, 
            0x43DD57C54D9C4D3CULL, 0x100D1256C1FB1FFAULL, 0xED7D9EA71E71E1E3ULL, 0x71CC0BA2BE5E4B79ULL, 
            0x3DF18B1AD8BE204DULL, 0x0054129C573624BBULL, 0xF3E79AEB5D9C0ADAULL, 0x380875856465DFFCULL, 
            0xA6B070E8DB0E11CFULL, 0xB7B9C7023585A133ULL, 0x92706B5FC157B96BULL, 0xF2269B7939F66578ULL, 
            0xC68E72AB85F0B57CULL, 0x9268B31ABB55910FULL, 0x7FECAB320723D317ULL, 0xE6701C8DFD35676DULL, 
            0xE4EE748B484B8E42ULL, 0xD7F015E84051DA12ULL, 0x3B0743AF06695841ULL, 0x0C880281CC8F530BULL
        },
        {
            0xC28233477BF25C6EULL, 0x54FAFBCD013FB459ULL, 0x98A489652BE82C47ULL, 0x82F5E2DD08CE492BULL, 
            0xCDAE3612FAC8307AULL, 0x38BA50B026410761ULL, 0x5D5D6825E6CC0D2AULL, 0xD8968F99B53AFCD7ULL, 
            0x712AF9C49C5EA085ULL, 0x2D0F8017AAD59063ULL, 0x067B9D436CDDF67BULL, 0xED4E30F4479740A8ULL, 
            0xABB336A420ED02ECULL, 0xBBD82042C524A848ULL, 0x9EBD15C354C2A393ULL, 0xAA2D0AD761A7DB24ULL, 
            0x1BADB5B41AC7B9F7ULL, 0x2AA6EBBCEDD98581ULL, 0x455D5EE1AC77E8B8ULL, 0x683CEA174503AE1DULL, 
            0x06CAD29390563480ULL, 0xCAF2E99617CE4AA4ULL, 0xCFFB058517AE776CULL, 0x281275A11FB473BBULL, 
            0xFD4AE34178F99AABULL, 0x9E6B952B9C58423AULL, 0xDB72D56C477F093CULL, 0x540259306B00EDAFULL, 
            0x6297B5C9958EDC7AULL, 0x22602CFB414ED257ULL, 0x8B59663FF49AAAACULL, 0xD39E20401CBBEE76ULL
        },
        {
            0xC46FBEB8C8C1297CULL, 0xA8B33BBAB663ABC8ULL, 0x0AA92598413E2348ULL, 0x4BF6EF4002704C87ULL, 
            0xA1A6D8B6408C46FAULL, 0x3A360E6C2A5CE850ULL, 0x56C04C1051A2A8C7ULL, 0x37E2A544B49F8908ULL, 
            0x948360BF16021254ULL, 0xC86061E21170369AULL, 0x66946A534AE22311ULL, 0x030DCF6597E178DAULL, 
            0x63CC181AAF8499B3ULL, 0x4757A0D7317D463BULL, 0x726E00931F600856ULL, 0x8FA609039A1AF9AAULL, 
            0x7A1BFD934B4E9B96ULL, 0xD401B09136A58E8DULL, 0x67C2BC17C7A3F543ULL, 0x5BA3A72A56AD4D85ULL, 
            0xBFA5D4E52159C27AULL, 0xAC4593A90DD535CFULL, 0xB020F84FBB873E13ULL, 0xC173EBBFF1B446ACULL, 
            0x44D909755BEEA66AULL, 0xF4F81AD389E7190BULL, 0xE56961FADA33E451ULL, 0x7C855F527935B656ULL, 
            0xCBC20B000EF2E4EFULL, 0x685C68D7DC2B7BE6ULL, 0x1417E992ACA7B02CULL, 0xDB7E8C02B6B2DE96ULL
        },
        {
            0xFD5F2037ECFDB01BULL, 0x8CBF0C5B6E988CF2ULL, 0xB80CB929C17D06D3ULL, 0x7E0AA74CFB8536DFULL, 
            0x670A6986B8DDF55DULL, 0x50EED8B06D575765ULL, 0x989E4AA681FF35F9ULL, 0xABEF5D16075BD423ULL, 
            0xDAF37761A2AEEFE4ULL, 0xE0D306DD8C0736E5ULL, 0x3F150A06AD653384ULL, 0x59FC706BCB7ACD29ULL, 
            0x95865F29EF91FDB1ULL, 0x4C2C676F6A040299ULL, 0x0295E80D823E5ED0ULL, 0xF147B346250D57ECULL, 
            0x20985D19BFFDA469ULL, 0xC6B6209A2E9402A7ULL, 0xE97E2CB3BBD1022EULL, 0x70C87195CCC437E5ULL, 
            0xA8312A1B7EBD2E62ULL, 0xDB050F883BB570A2ULL, 0x53F7955EAA4A0771ULL, 0xF3C47173315DF2E6ULL, 
            0x5D6E2B47B14390FBULL, 0x8EB2C1BCE6640839ULL, 0x4E458647CE9B02DEULL, 0xCA46E59DAE22CCC9ULL, 
            0xC674FAEE38D23B5AULL, 0x77DFF8ECF820C1FFULL, 0x47308218512D9E43ULL, 0x782FC7FA2379F6EEULL
        }
    },
    {
        {
            0x1BF18B2F245754B3ULL, 0xAFA770A20925E909ULL, 0xA183DE9CC3512FC0ULL, 0x59C10B73A7911D00ULL, 
            0xF139A2554F64DD62ULL, 0x0A8A2E0911550417ULL, 0x43F9820FD385DF46ULL, 0x4201E9F29DB8C2C7ULL, 
            0xC9DC8390028260DFULL, 0xF8E0E4C2ADD0C97CULL, 0x1721B1C4497E8F70ULL, 0x03DCE36466855153ULL, 
            0x070879824ACB26F8ULL, 0x241B5F501A26E24FULL, 0x5BE4512220D1D325ULL, 0x5DA9FFAC538683D0ULL, 
            0xE048B798FA0F4EB4ULL, 0xCD9242C3152E3156ULL, 0xB9FFE76B0682321FULL, 0x4BC10E44465554CAULL, 
            0x0D2DAD486CFA0050ULL, 0xC7000F51D1CDFB3BULL, 0xE6C45A060CCAD84FULL, 0x9D7B8D527FEDB344ULL, 
            0x9D6A9B623F07AA0AULL, 0xE926467CD59BBF6FULL, 0xDC57D5DCFBDC8119ULL, 0x50B09CED55EC2C89ULL, 
            0x59987F05CB93AF33ULL, 0x88D805E3E9F761EAULL, 0xF46762A23FFAD03EULL, 0xED946B9F8D09B49BULL
        },
        {
            0x11554232BD46DEA2ULL, 0x1E3D9E6871961C05ULL, 0x4879B0902DBEEC8AULL, 0x65CE0BCB882EFBE5ULL, 
            0x8F5393D4DBC70178ULL, 0x7B6A9164A16BB11FULL, 0xD4160076E236DC14ULL, 0x5F51BEE56EF6940AULL, 
            0x307395D490905061ULL, 0x1AAEF5CA307BBAA4ULL, 0xA0A6E60F6AF16D03ULL, 0xBE8B81C0D93F3F37ULL, 
            0xC4CA153C6916D4A6ULL, 0x80ACC8D8DF546593ULL, 0xAEB3443147F88F2FULL, 0xC8488A85A5FBBD0DULL, 
            0x0C176918C4735D05ULL, 0xFD7C98C1F4F1F3CCULL, 0xCE680F18F949C6A7ULL, 0x25285B8196ACC72CULL, 
            0x4D72CC0FB77B1D56ULL, 0xF8F5AA13E6F58B65ULL, 0x7A2254C8EDA7E7D5ULL, 0xEA7D6C46F569A445ULL, 
            0x96D47276F40168E6ULL, 0x9DF4D632816C1B1FULL, 0xB16DF4B5820490CDULL, 0x9671C457510C6A86ULL, 
            0x0B7782467F477B71ULL, 0x2BAE613AE35A2817ULL, 0x2FA72011B34FE685ULL, 0xB5AEF2CD156D73BBULL
        },
        {
            0x7FA030971465B50BULL, 0x0C81792240753541ULL, 0xB57EB94412E80B67ULL, 0xCCFBA5B61F779810ULL, 
            0x1C1EE451C035CAE3ULL, 0x3F90A788538645A8ULL, 0xFBA0F59285504873ULL, 0x6D5B5038C8E074BAULL, 
            0x63A6BE3A3753115DULL, 0x701D2AC8E3BF198DULL, 0x8EEDA4BEC88998ECULL, 0xEA4A46DF779F47D5ULL, 
            0xFE7B2ED6A18FA5FDULL, 0x928C66B113558E9EULL, 0xA045BF8F7D4FB570ULL, 0xB1CE82E5ECA39A27ULL, 
            0x2D944DA2309F1B4CULL, 0x018041F46C00ED1FULL, 0xD643B9F72117E562ULL, 0x648776EE71C8F375ULL, 
            0xC418360C49976695ULL, 0xBC745AB99911C98EULL, 0x75117E9739A9E97FULL, 0xD462043088255C7DULL, 
            0xB467B01F7060E458ULL, 0xD12BEDD94A1914F8ULL, 0x53C9C4A8080CE1FAULL, 0x91F7D4C60989AF76ULL, 
            0xA7337E8C8ACF433BULL, 0xE1BACCD303541333ULL, 0xB1F85592CF65A245ULL, 0xBAF31848ECB41F55ULL
        },
        {
            0xFA56906F265A3D2FULL, 0xE48A300A2D30AA54ULL, 0xBF1FF19308E5BF7FULL, 0xE3473C1DF54164D4ULL, 
            0x7FF327CB2B1B7AFEULL, 0x1784EF8AE901FA62ULL, 0xDE439A5A67396402ULL, 0xF34AE098DDAA2C90ULL, 
            0xDDD83411EED8D317ULL, 0x2EB36D4791D5C3EFULL, 0xB9CA00A97400544AULL, 0xE9BEFC21858EB629ULL, 
            0x4F038C9556B09972ULL, 0xAD39F1485878AA59ULL, 0x1C4948A19AF606F8ULL, 0x0EA03E37FC149CE9ULL, 
            0x5C371069F143F0F6ULL, 0x87FD76727FC48028ULL, 0xAEE19069E7E2F8A4ULL, 0x4488084B132A265AULL, 
            0x98D6E7BA501F1E06ULL, 0x410958F1D58D722FULL, 0x6FC1C417274FA79BULL, 0xD8264051050E9D83ULL, 
            0xAF4F5848FDF1F79BULL, 0x61BFCAB7FD7CF767ULL, 0xACE926FFA6090656ULL, 0xFD7F7ABA400C8768ULL, 
            0x16D3208E29FB7A0CULL, 0x25E72765F014634FULL, 0xBE800CEB1C951E6BULL, 0xB3E02F7D3EE03166ULL
        },
        {
            0xCB283B2AF0542E45ULL, 0x619A30E32FCC3FB9ULL, 0x6A79145848F05503ULL, 0xE6646BE665190CB7ULL, 
            0x6CA34670FE10EE69ULL, 0x1D497DEF6D977FD8ULL, 0xAD57208EE7F299BEULL, 0x571C1569CF055CFEULL, 
            0x105E832F1354D91FULL, 0x5D0BD5DDE2CB7F16ULL, 0xFFFDC57B5C18E22CULL, 0x8758AC1A12D3B103ULL, 
            0x0D05878A704E6DC2ULL, 0xB44D6F1B7EA4B248ULL, 0x0F0D0F6D89A248E2ULL, 0xCCBF10473C1D8E2AULL, 
            0xC721C97361134E97ULL, 0x28F12C05A49284D5ULL, 0x85C920E595E0C310ULL, 0xC4D2DAFA83CCDB87ULL, 
            0x3905024F395CF236ULL, 0x176FB97328237C87ULL, 0x6968E3880710BA79ULL, 0xE6D64EEB0C0BE129ULL, 
            0x897ACECEBC42C250ULL, 0x9752A81BDA2C3A90ULL, 0x3A669F8D718AC2C3ULL, 0xA91A92398266629FULL, 
            0xE9365026B9723D0CULL, 0xF7B09B517BA38360ULL, 0x3AC5231A11D1A9EDULL, 0xA0DCACD3E8C5D968ULL
        },
        {
            0x450BADEE60E20A24ULL, 0xF677FFDCB89EA90CULL, 0xAFC8821F36742371ULL, 0x05EE4CD48FB5AE97ULL, 
            0x73025B9DC44E5DE5ULL, 0xD9FDAF41D4A0CD04ULL, 0x219FF208D2B6E731ULL, 0x2A697D093BB7CDBEULL, 
            0xDEA35548FA942B92ULL, 0xD1D7218E900459EAULL, 0xAF8FC735C96E31CEULL, 0x6F6C1D8DD2613D5EULL, 
            0x26790F2C2EFF1E93ULL, 0x02E5EDE293CE8A82ULL, 0x53E14A6534FDDB85ULL, 0x7BE9B8F9C6CD3BB6ULL, 
            0x048E2562E0555770ULL, 0x47E2F664D76E389DULL, 0x2091A10286E8225AULL, 0x147AC950ED4F94E3ULL, 
            0xE1C3126318EACD26ULL, 0xE6A87A70C1DBB356ULL, 0x62CB90588CD0DC97ULL, 0x648E74FF3437F65CULL, 
            0x9FF07A734EEECAA7ULL, 0xD47CE62C364DB9DBULL, 0x136E9F2F9968C4F1ULL, 0x566222EF61D42350ULL, 
            0xA6FB9F3C3B57F78EULL, 0xC8EBBB18AF78CFBFULL, 0x51F8C80BA7D03D51ULL, 0x2599767994860EA3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseDConstants = {
    0x93ACF1BF00D22D67ULL,
    0xB0242BAE07875960ULL,
    0x1FC828B54D94DB09ULL,
    0x93ACF1BF00D22D67ULL,
    0xB0242BAE07875960ULL,
    0x1FC828B54D94DB09ULL,
    0xDB297D6F9F36E017ULL,
    0x8D80DDB487AA8B8EULL,
    0xCF,
    0x5A,
    0x35,
    0xE6,
    0xCB,
    0x5F,
    0x64,
    0x5B
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseESalts = {
    {
        {
            0xDB4C9B1548D1AD95ULL, 0xA9511F90590ECD89ULL, 0xB597EE1E3552F78BULL, 0xE6C40FED06A2782AULL, 
            0xFDB5EDD9033C34AEULL, 0x5293549B7BA0DC2DULL, 0x2F65BE4F62C0D0EAULL, 0x3DCBB632F6E051FAULL, 
            0x8FCE2D6C5E32928BULL, 0x3387E85C5BC7D1D9ULL, 0x1E0B5A5C95698FE6ULL, 0x5B4942BA4E3EF1FCULL, 
            0x3A8AD8A84D1578F4ULL, 0x09E17366582E9F05ULL, 0xCC0AA404725E35F5ULL, 0xE62F2C7AABC73B98ULL, 
            0x3F069E2DF8AC9F6DULL, 0x1BB07D075DA50E20ULL, 0x03BC324F5C1EFD70ULL, 0x673A6BD5609380D1ULL, 
            0x71B15A30B1CB0172ULL, 0x66371F0B0A0CCB07ULL, 0x18DA1440EE18EB2DULL, 0x62BA4A8376B57A6AULL, 
            0xE1962243553A8056ULL, 0x5C1518E59167A5FAULL, 0xD30085F98BA3A544ULL, 0x8F262E1679720AE5ULL, 
            0xB9FB978931FF7F47ULL, 0x5A4AD0ABCA4CAB90ULL, 0x8322E926E958CD91ULL, 0x367248D8933F3B13ULL
        },
        {
            0x42DB465953CE84ADULL, 0x01F98D7F36AEE733ULL, 0xAE6DFA398D0B4B7DULL, 0x4FF0F7CA8ED4C846ULL, 
            0xDCFCCB4FB0C21FE3ULL, 0x8AF02A4C54F00077ULL, 0xAF42990129D3F907ULL, 0x81F4B8F4AAD0F7B4ULL, 
            0x1A65FCB0DCE29718ULL, 0x07F026741AB4A3B1ULL, 0xF1345F9075EF625FULL, 0xBA9C05A8BD6E5F69ULL, 
            0x3BDA4710B79BBA93ULL, 0x93F8D1F1992A3D44ULL, 0xBF1C471923D16799ULL, 0x0225AE34CCE5C45AULL, 
            0x2122AABC68C926ECULL, 0x2183318EE3333C77ULL, 0xB8B4A108408B8B06ULL, 0xC5D6F069BA0F147BULL, 
            0x31B227CEBE6F6FDFULL, 0xB01AFC2FE08521EFULL, 0x522044445E692EBBULL, 0x2AB76E0574C76323ULL, 
            0x7D807E865AD3BBBAULL, 0x4C9526B84C7413AAULL, 0xAACFD2EE19C96AB3ULL, 0x6269A32C7FEB233EULL, 
            0x432F72470F656AB6ULL, 0x10F60175CBE8CAF7ULL, 0x9918595580AED4B9ULL, 0xF022501D5C23EEE4ULL
        },
        {
            0xFDA1592ED5F02E64ULL, 0x03B637A88DE18429ULL, 0xF53FE80E78C44D11ULL, 0x457D44E117F6E9A5ULL, 
            0x19C47E3FD6630AD7ULL, 0x95AD840C93E60B77ULL, 0xF03FEB9F828B9A74ULL, 0xFD8416BAB084FED5ULL, 
            0xD024EF0915B663E7ULL, 0xA4E60FD410B278CFULL, 0x2B1ABE9A9239629BULL, 0x2699AEB4B63BD71CULL, 
            0x5BABF493283EE3C4ULL, 0xA9D0DC0F263023BEULL, 0x5CBE57EBD7166666ULL, 0xFFE60B4373A6D4FBULL, 
            0x2C02B394CE51BC85ULL, 0x13E79B90E8CDBC9DULL, 0x1C4517B6B90C920BULL, 0x62310294857A9C36ULL, 
            0x2B3AA04DFF286E85ULL, 0x31E5F00627588A90ULL, 0xD8B696B690D312C7ULL, 0x4B4E2684706A553CULL, 
            0x733DC02940DFD744ULL, 0x504829669A90F0CEULL, 0xACC55C48C5F546AAULL, 0x39AADC08DFA8A468ULL, 
            0x40164C439C602488ULL, 0xED8D51C07A955AFCULL, 0x9A8C0561802FCCC7ULL, 0x0FB9846A9FC7EC77ULL
        },
        {
            0x18F59399F913317FULL, 0x71B83ACB57291660ULL, 0xCFAD4010326A9FA5ULL, 0x1FAA74549C62068CULL, 
            0x0FD9194AB01D4CDBULL, 0x2005AA69A339FB37ULL, 0xD8A375B799303654ULL, 0x9FE0B9A941CD3F13ULL, 
            0xB966FB28866A75EFULL, 0x07F1ACA025AAF6F8ULL, 0x091640E402462FCEULL, 0xC95F0578697C6AB5ULL, 
            0x8B0990205C2214D6ULL, 0x96E5A56A1C51915FULL, 0xAE02B61AA9FECF9DULL, 0x181F2A7EE23A20CAULL, 
            0x122A3500AF08E798ULL, 0x2719BBC55F755E56ULL, 0x869BEF406D5E34DBULL, 0x6044079607722B4EULL, 
            0x7C6EBF979747085EULL, 0x36FC0062BC35D5E9ULL, 0xE0D8D201599A7A61ULL, 0x0F21584133DF8409ULL, 
            0x175BAC608589414DULL, 0x31149EFDB4AB9F7EULL, 0x166518CB6937F721ULL, 0x21A12E34FC34DABAULL, 
            0xEF400040A40335F5ULL, 0x2B07FDA65BC02134ULL, 0x7CC1DC8E460B5A7BULL, 0x58B9820F1A53C969ULL
        },
        {
            0x5C55118893659D8AULL, 0x2A0D001DA58571BFULL, 0xB5C7AB10F1FBFA66ULL, 0xA9D50977102F8C2BULL, 
            0x5DE469FB2905BDA1ULL, 0x8EF705FAA008ED1AULL, 0x87C3E08EAB6D032BULL, 0xFCE9C5D37CC9ABDBULL, 
            0x9BF57210475742DAULL, 0x66FBD48BA86A7316ULL, 0x261120F0D6B266EFULL, 0xF0BEC91CD506F4E2ULL, 
            0x9D563A16C3C25935ULL, 0x9B3BA2DFDF0A6A8BULL, 0x9F53E33356703B0CULL, 0x603F53C1517B07D2ULL, 
            0xE346B4D6A91CC657ULL, 0x5359B1B38862831FULL, 0xAF4A3F1A4101F777ULL, 0xAA3C0609AA68E723ULL, 
            0xF098DEBE49D26395ULL, 0x895192F6BD8D6DD6ULL, 0x4A63CE987F38BCA6ULL, 0x0E6AED7DE723F2A9ULL, 
            0x46995DE8E7946D6FULL, 0xBBC6904ABA1E54A4ULL, 0xECA23F2712481085ULL, 0x20751BC61800C4CAULL, 
            0x5E8563FB65E94A05ULL, 0xC98A6454B2CACDAEULL, 0x64D12DA53E40DB96ULL, 0xDA8D56727E82D8F4ULL
        },
        {
            0xF0401CD2F2F63ED5ULL, 0x5E93A73048E71BF1ULL, 0x6D46AE521E889DD4ULL, 0xA2F91DD614E90727ULL, 
            0x3B2BF0173DC12692ULL, 0xA07353B3C6EF4927ULL, 0xC31130FDD7611745ULL, 0xE35D88A1992BFFC9ULL, 
            0x280ED916716B9941ULL, 0xE61A91401A77AD5CULL, 0x5BD9FDE423BC19C9ULL, 0x83FD7650D326BC60ULL, 
            0x5523D1794257FF53ULL, 0x7FAC5FC087347134ULL, 0x3E590FE8EA68C5A1ULL, 0x7851117A0C03233EULL, 
            0x4074879C010E1026ULL, 0xD0FF1A1BA827FC16ULL, 0x32501717195D7936ULL, 0x221F303F31197E77ULL, 
            0xC2B7A23F140C7476ULL, 0xB6BD0DACA3D83719ULL, 0x2C5D690E7508CD75ULL, 0x2F2328EC8FB4C556ULL, 
            0xADBF5DFF4006F777ULL, 0x6FCD45F6E836BF83ULL, 0x73A60FA0155872A6ULL, 0xBC6C77E8EEDD6011ULL, 
            0x59556122FFD8C03CULL, 0x3D54B3CF849DE71EULL, 0xD4924A6B556BB869ULL, 0x9F43D7902AE98784ULL
        }
    },
    {
        {
            0x0D49A7025D0A8696ULL, 0xE2BA7523DC7B7F44ULL, 0xD8ABB7CFCE3D40AEULL, 0x5CE9B00DEEAE8A9FULL, 
            0x16D069F22A8FA7ABULL, 0x5A4BC5959F4C2FBAULL, 0xEE04021F7EA86A99ULL, 0xCA71AB5B7AB706B5ULL, 
            0x284AACEB878DE1C5ULL, 0x9D5B64C51C7DF11CULL, 0xC544EBDE9855F530ULL, 0xE02144EAF762F79EULL, 
            0x0F4869E406B240E1ULL, 0x9DE2DDC5FE687513ULL, 0xF302DC5E3CCE9358ULL, 0x63CE6CAD0F72D55DULL, 
            0x6DFAC7328F3D0006ULL, 0x353AA754ACA997C0ULL, 0xB2477615DF0F9A48ULL, 0x28EC3E6C44DB0B01ULL, 
            0x87DEDDD6FD43CA5EULL, 0xA68D0D28397532FAULL, 0x47C54123CFD6E7FCULL, 0x65DE82943F6C3D7CULL, 
            0x8B92C6E463FA2C41ULL, 0xB755E62A4E2A741BULL, 0x075407F9303287EAULL, 0x5EADE563C9B06716ULL, 
            0x45E2317CCD752E46ULL, 0x695767A59BF9CE87ULL, 0xBB2F9506CE87CE30ULL, 0x83DC02805B65FA90ULL
        },
        {
            0xC5B4C03FFEEE0654ULL, 0x1D86AB9389A07A3FULL, 0x39FF8C67E942B978ULL, 0x2E2AA6007C895FA8ULL, 
            0x80A6BC9B68FCF646ULL, 0x5F7806625047059BULL, 0xA9112194B044C9E1ULL, 0x3B80ECF6BC426742ULL, 
            0x62F1D59801F5ABD5ULL, 0xCE848D2F6B0FE065ULL, 0x394B3F286CAE5BE1ULL, 0xB7CFBDBB1EF24D87ULL, 
            0x752BF1040C61F927ULL, 0xDC7455EEF6BCE8B3ULL, 0xA382A121B538254DULL, 0xCB53C8F496029ABDULL, 
            0x29701B581C6C3B83ULL, 0x7A807225BC02048BULL, 0xB81031EB9E7A8302ULL, 0xBF5C06AA3959793DULL, 
            0x7DFA4B380CA7CA81ULL, 0xC168425D0073DD25ULL, 0xC8CB4A72056A4294ULL, 0xBFA2523FD7311CE1ULL, 
            0x9731BA2D510215EFULL, 0x294990FEDB3036E5ULL, 0xE143483AA7F76FB0ULL, 0xBA3A3603F5E4D266ULL, 
            0x1F40F7A7A4AF50CAULL, 0xCFC75E93DE45F368ULL, 0x43335ED06F39F918ULL, 0xF87BAA192799FDD6ULL
        },
        {
            0x212E1708E8500FCAULL, 0x2C90AB3914408625ULL, 0x2DC38D7FD75EC7D8ULL, 0x0DF7909E58479106ULL, 
            0x15732BB77C49C381ULL, 0x1FDF05E069EA2ACCULL, 0x6DA3D836993BA091ULL, 0x9D8180D8F3CA3206ULL, 
            0x5D45E325FC745E44ULL, 0xF5B5FE46068A0D1AULL, 0x74820DA528AC0B4BULL, 0x8813090AAE68E7BBULL, 
            0x99DD323CCC5F7660ULL, 0x27E3D6389848202AULL, 0xBF2A78E5570719B1ULL, 0xA12DB31269030E97ULL, 
            0x49B66A56CC91C5E3ULL, 0xE2DE0667C991B316ULL, 0xDE8C0015C7DA07F9ULL, 0x81DAB1ED27E1FB7DULL, 
            0xA3D6F22037CF03FCULL, 0xBDEDFB58B37D45E3ULL, 0x2578B3BB16388B3BULL, 0x095E505AEA949962ULL, 
            0x1B149BC77313324AULL, 0x9731F4AF848C239EULL, 0xD43817C20DC19001ULL, 0x4AA710452A2E39D2ULL, 
            0xC53AC770F9CDA458ULL, 0xEDC2272275C98BABULL, 0x36E8C071AC0555FCULL, 0xE2AE29D4D13EA624ULL
        },
        {
            0xDBD52D29907E8E1FULL, 0x729DA0503DE45AB6ULL, 0xFBA9024F3BD2BB42ULL, 0x69BAE3F470F0FBA7ULL, 
            0x4A71851D6FBE7EBEULL, 0x95A09EDF8E29E4B8ULL, 0x1563190370A0474EULL, 0x00C2963E240DD45BULL, 
            0x1E6CC160FD2B822DULL, 0xAD34E871DFB0F044ULL, 0x6D7FCDEB8CAEC638ULL, 0x300A9E5862E5AE76ULL, 
            0xACB12AB79AB958BAULL, 0x489EC954926D8A87ULL, 0x59C9663B219F9B2DULL, 0xE6C9E1BADFBAD1EBULL, 
            0xDAE0C9E11F5E70A5ULL, 0x673195989F5F724DULL, 0x191EAF93BCABE402ULL, 0x203261F40C6E70FAULL, 
            0x26C0EE8B3708C0C7ULL, 0x4B8821ADCEB760D3ULL, 0xEC4ED0407B58EC7AULL, 0xFC71967085AD0CF8ULL, 
            0x218A85C7E6D6B726ULL, 0x88EAC470FE1AE669ULL, 0xF0E42D9790C86240ULL, 0xCFE716EB52F2BDD7ULL, 
            0xE55CC988C190EFFCULL, 0x7AC90D2C2C478D6BULL, 0x1E4B90980618E441ULL, 0x79C1D54CB3448F0EULL
        },
        {
            0xA22B53AC956CA0F1ULL, 0x248341AACC5661AAULL, 0x812B09D709BB7F0DULL, 0x60BCE146159C5331ULL, 
            0x5AA84F4F094CBB6BULL, 0x768462305695FAD9ULL, 0x443FDA11423D79DDULL, 0x499C7CA3142C230FULL, 
            0x731F16E778ACAD99ULL, 0x01D7DF113E72DFD5ULL, 0x463BAA2CDB93A5B3ULL, 0xF32C3A8872EE20FBULL, 
            0xB46FBE4D936B6F0BULL, 0x7446843AB51E3977ULL, 0x7B4F4183ED01EB1BULL, 0xBEF3155C1B19FA72ULL, 
            0x6947D19C3A0B0DF3ULL, 0xD1964237F77BAD6BULL, 0x991EA92B69491430ULL, 0x331C9D1C6488BA5EULL, 
            0x7C52DCBB89AC4F8EULL, 0xD5400F9FF1BB4B7EULL, 0x05C8656CAB01EB50ULL, 0x708A10FD1B838448ULL, 
            0x598DB4CBDDAEBBEDULL, 0xAFF8C764019B5066ULL, 0x03FF907B348E1DBCULL, 0x03DA955233D5BB72ULL, 
            0xD2D00299651FB952ULL, 0x031666A812FC2FB9ULL, 0xFC0A4D1DDE734473ULL, 0xF1A4D29AF4D96819ULL
        },
        {
            0xD6D7FC11FEDC4E9CULL, 0x3E890E220E38B84CULL, 0x08DC0C40A15A7D86ULL, 0x4E92BBFE4AE47789ULL, 
            0x25C0716C77985386ULL, 0x78AF759F43294C3FULL, 0xE424C39922FEF3E2ULL, 0x58E045E78A44F16AULL, 
            0xD546FEEBCC1F0E9BULL, 0xDBA329B0E2F99B90ULL, 0xEAEF00B003AC13B2ULL, 0xB3DA23ADB9470D87ULL, 
            0xC44483CBE522486FULL, 0xDCF1A8AE18ED5D30ULL, 0xEE0092154A80524AULL, 0x3BE8B542358555F7ULL, 
            0xFDE64B7A68104EAEULL, 0x2013A5F958150FD9ULL, 0x4B03F16F7923AC45ULL, 0x312B5B5777FBE71DULL, 
            0x28D988484262D8B2ULL, 0x1D885A642F17AF93ULL, 0x62B0C034D5EDEC3DULL, 0x7F7FE15193737486ULL, 
            0x115A45F59B38CEB0ULL, 0x47303DDEC335EEDCULL, 0x8EC4D2E299548EF3ULL, 0x426973D16A32B6EBULL, 
            0x12D2324D5A8F8519ULL, 0x20A4204FEC77DE99ULL, 0x123E1F9147247EE0ULL, 0x33486708470E0FCFULL
        }
    },
    {
        {
            0xA7C132448168E841ULL, 0x394C8BBF2AF96FE0ULL, 0x212753688C906F45ULL, 0x8A32D2301D5805D1ULL, 
            0x65C323BC401462F0ULL, 0xC002D34BC2978214ULL, 0x98AD035B9780FC52ULL, 0x43244BE0D86ACB80ULL, 
            0x0B7D025ACECA5B89ULL, 0xCDEE509D771D6CAAULL, 0xD289059DAB06DEB1ULL, 0xD8CE297D7EFB8178ULL, 
            0x47A93E68E4B046B7ULL, 0xF74725472BE63DB8ULL, 0x664D8ED78ADED7D6ULL, 0x2F31047B1D667855ULL, 
            0xE0E43070035FB26DULL, 0x66A1B2DF762011B1ULL, 0xC1836B7EE907CBEFULL, 0x166C3A448B209BA5ULL, 
            0xD175F2CB16E5A2CEULL, 0xEABF874E0F0474DAULL, 0xCD47D9345E5E5C32ULL, 0xAA58159914329D3CULL, 
            0x49DB8113A33DE6C1ULL, 0xE620427B669777A3ULL, 0x3B08987562BE03C9ULL, 0xEC20307A62868A5FULL, 
            0x97F25D0A378A62BBULL, 0x3DFEC6414B41ED7BULL, 0x18CDFDFE3D535EA9ULL, 0xDD21041EA36F0CE7ULL
        },
        {
            0xC01EE3A98A441288ULL, 0xEF5D7115434D4332ULL, 0x8E4545928FFF023FULL, 0x37D9F3ECD8497FFAULL, 
            0xDCC6AEA3A3B85081ULL, 0x7B099148CD0A4D20ULL, 0xC04F14EDE340FFB4ULL, 0xC756D7B1C3D1219BULL, 
            0x83C66C2B97B2E50FULL, 0xD555735D2D9E56ACULL, 0xFAC9F94BA5F1F152ULL, 0xBBEE3254E474D242ULL, 
            0x131EB5CBBEEBF6C4ULL, 0x39D888AAC51A2BCEULL, 0x06F0E07FADA25E0FULL, 0xD0F2BD8EA26D8BB7ULL, 
            0x5C75E6F53701DD27ULL, 0x86C8133AF01C874AULL, 0xBBEFE4CC04613C11ULL, 0x1DA597A67C0EB27AULL, 
            0x661795B83E3C3E09ULL, 0xF8FD84348D8CED8DULL, 0x12787BE0B4E7952EULL, 0x42E3397FF95F900DULL, 
            0xEFBE11D01CCE75AFULL, 0x5BF6662A27B63FC9ULL, 0x355F9E04363ADD07ULL, 0xF0FB430ACE8466D9ULL, 
            0x7B249D0A84806D0CULL, 0x355AB757D14FBB65ULL, 0xD8B6E240145D9E89ULL, 0x83C389747E8EB730ULL
        },
        {
            0xD0F523D789E25884ULL, 0x1CEE05903E8411CEULL, 0x0FCABF5A387963EFULL, 0xDF3317203689B523ULL, 
            0x0D6B3F2F45B27E6DULL, 0x527389835F21DE01ULL, 0x61DEA3E40591ADD3ULL, 0xF39481654AA78287ULL, 
            0xA0401FFAC2B6D294ULL, 0xDD8A83307B774DA4ULL, 0xDDD7D009B582D926ULL, 0xA06E006567C0C177ULL, 
            0xAC91F5EBAD94444CULL, 0x207A581E431B90DEULL, 0xB71C172681291FA5ULL, 0x8A7DA87E3C49FD39ULL, 
            0xB37750CD1A6A1550ULL, 0x689ACE67B181EF60ULL, 0xDCEF2F2682C64A9BULL, 0x9BE3995C9DD434F2ULL, 
            0x17AAFE92D41C3ED9ULL, 0x017C2F14B10967FCULL, 0x083AA72E6DCA53E8ULL, 0xD157B7F7B17B4848ULL, 
            0x4F6F05D48CC08C24ULL, 0xFFF6F6CC16414B74ULL, 0x0D7C31E075F9ED5BULL, 0x2515BE408D6857BAULL, 
            0x46E83E2796939CA9ULL, 0xBD1C48F11C61F3FFULL, 0x1035B3DDC1C07FFCULL, 0x7B543F7F6E7B65D7ULL
        },
        {
            0xCE14C9D9BA326871ULL, 0xE4EDB04182E8E08BULL, 0x6D59357FBEFAB57BULL, 0xC590AE9B3E97AAB0ULL, 
            0x6F58F70983FFDF38ULL, 0xCD92A97AE6C44500ULL, 0x1B38E248C61F3735ULL, 0x51DFA944A7AA61ABULL, 
            0x01BD0B5BD9B3510CULL, 0x03A38FF994F8CDD2ULL, 0x1131086D9047C278ULL, 0x9089FAF3796AAF64ULL, 
            0x10FD96AEC2F11FE5ULL, 0x8A9F354D8F11F5E3ULL, 0xDDEF423FD0FC9109ULL, 0x35D286FC4A375DE5ULL, 
            0xBB11BABEC233B217ULL, 0xF05789B8A750E090ULL, 0xB2272A92DC9FB198ULL, 0xBD3D5C7C0BFD0464ULL, 
            0x9B6304E230DA05C2ULL, 0xB928ACB206650843ULL, 0x9177CB34A84ACD06ULL, 0x797FA1D85276B2A3ULL, 
            0x8BB0F1E2587CF9E3ULL, 0xC2E4306D106A5367ULL, 0x3885F583D82373E0ULL, 0x583BB47FAD4913A9ULL, 
            0xE4714DD85E2491FEULL, 0xA087387A537570C3ULL, 0xD57E87BF7DE04681ULL, 0x9C4103A724CBABD0ULL
        },
        {
            0xBDD4F5F1C3AA7A94ULL, 0x87A181D20C7AE4C1ULL, 0xBE2FF33100305F42ULL, 0xF7A184A770633882ULL, 
            0xF0D746B051B97CF5ULL, 0xB86FDFE1BC63D833ULL, 0x02053DCC4216D54FULL, 0x90390A8A44E3ECECULL, 
            0x1CF782F18F81716BULL, 0x8926CAAAD52D8C37ULL, 0x490B1D448D306A88ULL, 0xDF0B471EB0825017ULL, 
            0x25F1C49F9252D5A6ULL, 0x8CC5BA851F4ACAD0ULL, 0x03FA3877A71DC47AULL, 0xEC77022A2AB645D3ULL, 
            0xF36E8EC95274511CULL, 0x7C74A384499A3200ULL, 0xE6F4220C75D96F8CULL, 0x48205C285CD73418ULL, 
            0xFDA67876E09F1B3DULL, 0x736FC3A933655B33ULL, 0x258A074D32B382BEULL, 0x9812323B35CA1D3BULL, 
            0xF63C4CD5C55EFF34ULL, 0xEC93371E4026A260ULL, 0x95CFC5D799A8A519ULL, 0xE7554B75B14705FCULL, 
            0x75F2B948BA1019A6ULL, 0xDD444BF3CFDACE0DULL, 0xD22A177D23E358ECULL, 0xBD47EFA5D1457510ULL
        },
        {
            0x5580F87F2F8F70D6ULL, 0xBA345AC3A452A555ULL, 0xD210667B2133834EULL, 0x0B9144A522F60696ULL, 
            0x19F5E5BD2EC75963ULL, 0xB4F3405589347995ULL, 0xC9D999782159715BULL, 0x8EB9774BFA9B8DB8ULL, 
            0x2F7421A4271754A0ULL, 0x81D370E29D0144D7ULL, 0xA060E883B8162F8DULL, 0xB677316CEF1C1D7BULL, 
            0xD1D9F07A71A4A249ULL, 0xA04923D2CA2F7E5AULL, 0x193398692D3033D6ULL, 0xF03495BFF24BFC98ULL, 
            0xB877AE7844AACFBDULL, 0xA5494A4244545A3DULL, 0xD2C2CB2A95E1EDE2ULL, 0x30067E39A950EDDBULL, 
            0x20D4F82D09E0B266ULL, 0x34168154211BE4A1ULL, 0x003EB44B9F762079ULL, 0xDFFFAC4E37C72B2DULL, 
            0x2E0AA9A9C0A63E18ULL, 0xEBCE1ED986F17FF2ULL, 0xF2D40A639543112CULL, 0xB9BB8F2236316F14ULL, 
            0xB400984CFC7023C9ULL, 0xAC72B06884E0460EULL, 0xB737321C5F44A15CULL, 0xBBDF4698D029D2C2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseEConstants = {
    0x36436758109738D6ULL,
    0x39ADDC23E6DA4CBEULL,
    0x83BE00599189C166ULL,
    0x36436758109738D6ULL,
    0x39ADDC23E6DA4CBEULL,
    0x83BE00599189C166ULL,
    0x367D3DD27E03FCC2ULL,
    0xF0C6A3CC01C919D6ULL,
    0x30,
    0x5B,
    0xEC,
    0x50,
    0x3B,
    0x35,
    0xE6,
    0xE2
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseFSalts = {
    {
        {
            0xB43BAC50DE20F926ULL, 0xD61EAEA04832F1C4ULL, 0xF4BE29FC7A83350DULL, 0xF7434DBF1833B10EULL, 
            0x452B2ED30885B6C1ULL, 0x9690151420455196ULL, 0x61D2D040C390629BULL, 0x41E5AF7B355B5B7EULL, 
            0xEB1D51E0D65F89EAULL, 0x9F6E65A7AB0B694FULL, 0xDE8F761E65291CA7ULL, 0x810E97CF7393B13CULL, 
            0xB77F2A72495A7EF7ULL, 0xD43AE420E5B83C6CULL, 0x4DDCE98CF34D5DFFULL, 0x328320475803A3E0ULL, 
            0x09009821ADD064A4ULL, 0xDBAAC399288EFA5BULL, 0xABF3CBEB54A409E9ULL, 0x21B758808A2AD2ABULL, 
            0xDC12C1EE57686AABULL, 0x9395C4693C559244ULL, 0x00257B5C4A9F733DULL, 0xD0AD08205FD4B404ULL, 
            0xB8690CD79625699DULL, 0x07634118249D7D43ULL, 0x7C46A8AC24FD11F0ULL, 0x7A333E631AE91428ULL, 
            0x90EBC26C34DABA15ULL, 0x0B78AC5DEE5491D5ULL, 0xA21B8FF0700A0FC2ULL, 0x415EDE96AEBBCC75ULL
        },
        {
            0x9AE73AA59B181C3AULL, 0x0266105D80CB22CBULL, 0x9CC0BFF0887407A0ULL, 0xC12CC66969908B7CULL, 
            0x020FECDD5A9EFA12ULL, 0x4283051D77FB283DULL, 0x68FB780F8A1D1B87ULL, 0x4BADEDE7764394C5ULL, 
            0xA87D32353CF24AAEULL, 0xC2339A1D0E40F250ULL, 0x73284737DA712C7BULL, 0xF5F668529974B48CULL, 
            0x6B786D0BCDE87E1FULL, 0xF5490AFC8F360C66ULL, 0x34B67926858AD1B5ULL, 0x81F58384B12B1503ULL, 
            0xB0CB06964E4AB270ULL, 0x3D1A6C06A201EBA5ULL, 0xCC3EE65EA2370354ULL, 0x5A15311EBAB61121ULL, 
            0xC8B95F9305DF9B0DULL, 0xE1B7885019EB9F3BULL, 0x6D1C0232B343F409ULL, 0x3336B0A7193D3B0EULL, 
            0x228AE0EE18D66023ULL, 0x6B74B7AECB219974ULL, 0x8DC950221FD496A5ULL, 0x70E736377902B5A6ULL, 
            0xA6DD43CB70AD972DULL, 0xC22538BC82F4273EULL, 0xED836257207B1B8EULL, 0xEFD9E377173B81F6ULL
        },
        {
            0xEE4AABE2CB348915ULL, 0xD80F515A54ACFB9DULL, 0x364C5195923C34FDULL, 0xEB6345232C328B28ULL, 
            0x40BFF5BF13DD1286ULL, 0xB56B147823DDCF74ULL, 0x6F3BD6097651BFF9ULL, 0x896E52F440EC8414ULL, 
            0x142D5F287F58550BULL, 0x50E4D8623FCB119DULL, 0x906AAEFD6238B78AULL, 0xBB310308A7CB68D6ULL, 
            0x76B6CD0A8BBA0564ULL, 0xAF22C7B9B1ECCBFBULL, 0x26CD60CA87ABCAD4ULL, 0x23B7C4F316F15228ULL, 
            0x88E57B9313C8E805ULL, 0x8DA4B73D80FADB78ULL, 0x4D89CABF4D79C62DULL, 0x8BDEFF584BD77565ULL, 
            0xF1584A86B0998CFFULL, 0x59794DA765C8EC9BULL, 0x2F753BA1868D6540ULL, 0xF05854D61A9CAB92ULL, 
            0x24391BA5F17781E5ULL, 0x51772C5143DBBF7BULL, 0xD0E9E2B533873E6AULL, 0x988148B876F13DFEULL, 
            0xFB33CAC2E98A008DULL, 0x190AA84AC6C9D4B1ULL, 0xF672E762D27F6287ULL, 0x5482C3FD75E75453ULL
        },
        {
            0x4A54FD597460AA9CULL, 0x32285759F4AAF450ULL, 0x7741EBF3A766D71CULL, 0x8DBD0A540D8832CFULL, 
            0x45FC0ED9DB017A21ULL, 0x3F0EE1B87BCBCD45ULL, 0x822B82E44324C146ULL, 0xEAEC634895092DCCULL, 
            0x0B3647E6F7B69BA3ULL, 0x97DA51289E17846AULL, 0x0C85CE2780F5393AULL, 0x7771C73E502C183EULL, 
            0xFA1C1CED080B5588ULL, 0xDDC33D61431A00BCULL, 0xE719717890726100ULL, 0x5876E74808E7AC6DULL, 
            0x5C456BABF888F03CULL, 0xE28D24E43F285B2FULL, 0x1AEAF8C8BD531C6BULL, 0x9E06E3E7F62C0AC2ULL, 
            0x51BB5F8BCCC822AAULL, 0x8C5BDD646BE19B85ULL, 0x15B012863691A0EDULL, 0x57260697044575FDULL, 
            0x2A6FE806E661EA22ULL, 0x665610B0AABA236FULL, 0x23106924695728B5ULL, 0x479DA07EBC4A3018ULL, 
            0x3E9A9C3A01E8F1C1ULL, 0x7051ADC0E021993EULL, 0x4B44CC794AEB0131ULL, 0x05FBC5697C9B37A8ULL
        },
        {
            0x98D2F4CD44E3AFAAULL, 0x601AC1A1D61764ECULL, 0xBC9E8D7372531165ULL, 0xF4B6D3C8085E533BULL, 
            0x967A295744825585ULL, 0x988637DBE78832C3ULL, 0x4BB870C804872854ULL, 0x0E847E8F16154F5BULL, 
            0x2780A5BE4C8DC0B1ULL, 0x2866C47FD9BF6545ULL, 0x34BCB660D5F18F63ULL, 0xEEB3F27641CBC09AULL, 
            0xF940FABFFBCC90EBULL, 0xDBCAE4F7F5D996FBULL, 0x67B207A208B8BBCCULL, 0x8B2FE968C1A46DC1ULL, 
            0xABF75A4E26731A6CULL, 0x3CBFC336ABB63A13ULL, 0x5E966C0DC98103E6ULL, 0x6A0398950D46CE32ULL, 
            0xD1D0EFF51D14A548ULL, 0x826C53B7F6C66EA9ULL, 0x226157F3AF04E717ULL, 0xE84937AAB260ADF7ULL, 
            0x1812184DBB47CE36ULL, 0x933BCAB411544F45ULL, 0x4757261745EDFB6DULL, 0xBAF07EB16F7D9074ULL, 
            0x3E3FF88D2181C7F5ULL, 0x7C9F9D4E56CBA7CEULL, 0xE6AF06035613EB76ULL, 0x53711A4ABE93F93BULL
        },
        {
            0xA94B347E9FA5BF49ULL, 0x92B18BF23311436CULL, 0xFEBE20ADB37FCF2FULL, 0x1D87950E95FA77B7ULL, 
            0xB63353746BD330C5ULL, 0x5FDC56F5C653B011ULL, 0x9C460EF6F85C9DE5ULL, 0x57A67FF10B76457CULL, 
            0x1B1F032FE49CA333ULL, 0x1CF6D18E4E04B3A6ULL, 0x553183BBDBE6112DULL, 0xAD9E5F710F265D8BULL, 
            0x4C56E6CD0D4C31DDULL, 0x9FBBBDA17BD12E57ULL, 0x958C5133969F2BC2ULL, 0x21DF63BE583D9F28ULL, 
            0x0072F0EFEFF422BCULL, 0xAFC815E3022D1815ULL, 0x75A85F6C7E6448BCULL, 0x67C0F63C708B3956ULL, 
            0x3696B1BB23C3A283ULL, 0x28B7F06C1179CDA8ULL, 0x714C6BDA679A798BULL, 0xDB19E1DC0230DFEFULL, 
            0x1F94FBB95061802AULL, 0x0BFAA02B616424D1ULL, 0x80E28E1DE38C3F83ULL, 0x57E6B53AB0B8BE65ULL, 
            0x35009105BA1016CFULL, 0x2BBD5DE07BFD3A3DULL, 0x91A9161495B19DD0ULL, 0x8F74A9DA51F0990EULL
        }
    },
    {
        {
            0x4607FD67E3047067ULL, 0xC6BD5367C97C9810ULL, 0x97C35B52F7B3D683ULL, 0x09028E81ED725681ULL, 
            0x8797C54919B4194AULL, 0x8849D0FE909F834FULL, 0xA0DCB518DEA83E6EULL, 0xDC12851EEBF669DAULL, 
            0x5C937BF1745D319FULL, 0x5807CD1E466F1875ULL, 0x10FE6DCAF1BC66B7ULL, 0x8840963D39364DEFULL, 
            0x4BAC9BDF0A2F79FFULL, 0x49152556C59211D6ULL, 0xAF168E0E4CCABEE7ULL, 0x3E3D50BA96DAAA39ULL, 
            0x9894F90C34745243ULL, 0x3EA1B2ACBD580B38ULL, 0xA3CC051505D78A7BULL, 0xEDFE25D4C8B354D8ULL, 
            0xFD0A366676201FD5ULL, 0x7B77EB312D59B4EDULL, 0x84363162B7352A0CULL, 0xEBD06504531E2983ULL, 
            0x0CEA308CDADADDA8ULL, 0x226143BCC12FDB8EULL, 0xD7FB66ABD03EA3A8ULL, 0x51C7EE201D86F2D4ULL, 
            0xEDE2B1D900AFEDE1ULL, 0x3CBE315C55C95FD6ULL, 0xB64DACD32BF5543EULL, 0x177364F255056CC6ULL
        },
        {
            0x1AEB0E3213D794B2ULL, 0xFD8A6E24F488F14AULL, 0x12494856DAB2EA13ULL, 0x588FBFA2B7E4A1ABULL, 
            0xF01ECD92DEE02F16ULL, 0x3F6B87CFC086D269ULL, 0x9DDDFBC894E1D70BULL, 0x163F68D030906258ULL, 
            0xA44E7B38E958E60BULL, 0x493C1933A35BA8E7ULL, 0xA839D17944B51F46ULL, 0x45315D29B957AB16ULL, 
            0xE6282AF94551BC37ULL, 0x1DD8CA3C5AC5D027ULL, 0x630A748B3036E163ULL, 0xFDABEC8BAD867CA6ULL, 
            0xC7C06BFB68050777ULL, 0xAF93EBB0F847993AULL, 0x97A75BF005B41710ULL, 0x8DB67890676C8039ULL, 
            0x20E8370C7FE674EDULL, 0xA467177851C6EFA2ULL, 0xE4DE8423143C8AC1ULL, 0x6A006CAE30073992ULL, 
            0x25115C0A87EABAC4ULL, 0x69407F0882509311ULL, 0x2A5B9D7AED8531DEULL, 0x201302069EA9FFDFULL, 
            0x8B9AA93D0C66ABA6ULL, 0x06B33F46C63D880BULL, 0x50C5FB07E99FDA06ULL, 0x98F02BDAE96F53F0ULL
        },
        {
            0x4796E59CD1EA845DULL, 0x0DB0482F3CE39672ULL, 0x5A7BED17EB742823ULL, 0xA4C9919A914D4CB8ULL, 
            0xEEED4A35E146B944ULL, 0x80B0732E88C23E55ULL, 0x48BAE21638ACEFA3ULL, 0x0EA119F07635A4EEULL, 
            0x56A27C7E0E3F2ABEULL, 0x28067142E6EFA4DAULL, 0x98143DCAC03339A9ULL, 0x6F74D1E53FD514E0ULL, 
            0x80D2027922641CC6ULL, 0x49DB95F61C5D9B2EULL, 0x4AF5FE307EFD412DULL, 0xBFC5E4B7C545493CULL, 
            0x035CAD09D35040B6ULL, 0x211876EB8BE9B792ULL, 0xA04138E4F960202CULL, 0xF9BF4BB3B608FC14ULL, 
            0x6F273C26CC55651EULL, 0xEA2CA4AFD3B021CDULL, 0x0C80C144AC7EBD35ULL, 0xB1681872149B74B6ULL, 
            0xA9A833FBC40DF36BULL, 0xF0B6AF866C929A94ULL, 0x096559FFEE51D16FULL, 0xB193D52C6655E5DBULL, 
            0x04036B646EB3796DULL, 0x440D497678FF8FEDULL, 0x1302DA3D679DF4DAULL, 0xE2282DED3214277CULL
        },
        {
            0xAC98D1969BD2B037ULL, 0xF80799E2C5DAE019ULL, 0xD336EEF13319FCE1ULL, 0xA389EB96378E2A76ULL, 
            0x81B3B7827D4E2E54ULL, 0x06A27D76B9520DDFULL, 0xCB3872A852A78F19ULL, 0xA8C3ADA3835DF607ULL, 
            0x43028D39FF20755FULL, 0x5A50F19759708580ULL, 0x4641E5A06D833958ULL, 0xAC28554BC5D9F0F9ULL, 
            0x0B890FA47266A155ULL, 0xD96247E3A7A278ABULL, 0x667C8D898784ED69ULL, 0x9D51F507AD9CBD9DULL, 
            0x1A4DF9223E837D25ULL, 0xC39D5119A2CFD2D5ULL, 0xE301969C15A2C3E1ULL, 0x4004C5924B514005ULL, 
            0xABE8250F54A4F0C9ULL, 0x34CD365FC3EB4DB1ULL, 0x07857673CE05CAF9ULL, 0x8281614A53A032BEULL, 
            0xA5AF861B9D1C433AULL, 0x664672BC23B7A7F2ULL, 0xC89961904A7CB5EAULL, 0x867F8AB77F3686AFULL, 
            0x5358C41772C009DBULL, 0x03D3F97CA204CCC7ULL, 0xEE9670D619059239ULL, 0x44C8AC2EA1CEA564ULL
        },
        {
            0x93ACD0C09CE22E54ULL, 0x0A5FA5BA998041D4ULL, 0x4B266A371A3D7001ULL, 0xFCC40C1D4262C82BULL, 
            0x754F4375246275E9ULL, 0xD319376F80926AC4ULL, 0xA532BC41F739C2CBULL, 0xC5A5A55E1C617A23ULL, 
            0x70C1A36E4E32D2EFULL, 0x214F4F5D532AFC81ULL, 0x876191E9A64991A1ULL, 0x9C0FC0B956F4E1BBULL, 
            0xAC30B626E4884026ULL, 0x3629342D51D9F46CULL, 0x634538278DA5ABE4ULL, 0xE4C4A350CB090FB2ULL, 
            0x2FBE4028FABCE293ULL, 0x5E90E3EC27D4CFE1ULL, 0x01063818539B59E6ULL, 0xC5AF3B1DA85D50ECULL, 
            0x388C8E78AE1B2E23ULL, 0xA33AC2786E8C9729ULL, 0xDA8580FAB25A84B6ULL, 0x38A03E2886424EC5ULL, 
            0x8308741CA8180764ULL, 0x6E4FC26D4130317AULL, 0xF370CC22DB472348ULL, 0x495353EEE1C3D8F1ULL, 
            0x280A9DA5B6AB0688ULL, 0xDD7E498D9A1B3270ULL, 0x4A77697B0EA39F51ULL, 0x30E1C7A1FBFC0868ULL
        },
        {
            0x5FE37B952C9929DDULL, 0x6B8A39C81BDF5293ULL, 0x81B8F7B01371326CULL, 0x50230C66CAEA4FE9ULL, 
            0xD80A187C437B24A1ULL, 0x56D187C67D763A17ULL, 0x6DB4127884A9652DULL, 0xBBECB84B85F984DAULL, 
            0xB170344BA374FC15ULL, 0xC8ACFA3FBEB4BF02ULL, 0x120B51493EE01CCBULL, 0xCE34F81FBE10A4CFULL, 
            0xEA8BA3797EAA73E2ULL, 0x5A8C531FD619B571ULL, 0x7CDA3824B349D170ULL, 0xA075D8951B514441ULL, 
            0xED7783DA67C38D5EULL, 0x01B4ADFB4E66C601ULL, 0xC07DDE46756C04B4ULL, 0x5C433E99BACE0866ULL, 
            0x9EFF0AB2A1680377ULL, 0x1DFEFC25EEDE28A4ULL, 0x8D85E712F781A0D3ULL, 0x63F66550D154FB87ULL, 
            0x9159FA2FEF98DC70ULL, 0x6F260F0CFB235BC2ULL, 0xF185A8419B81CF84ULL, 0xC764E5AEA0410AF6ULL, 
            0xBC41B823B9088CA5ULL, 0xBFA447886F39734EULL, 0x3677AF81E8427941ULL, 0x0F13FE221A960FA5ULL
        }
    },
    {
        {
            0x9550328E98A8F5CAULL, 0xBB67D62E3E227E92ULL, 0x841789D4B588A546ULL, 0xF98EF95D25A15F21ULL, 
            0xC5D07F586EBD3580ULL, 0x254B5C917D03D707ULL, 0xD85696370C8BA605ULL, 0xDB8CDBCE3A85E8C4ULL, 
            0xE7F653C7A8999778ULL, 0xF69FBF10A76BC96DULL, 0x69C8B8E76A8AE3C3ULL, 0x29065E532C06BC04ULL, 
            0x0FB8F60B7BB16CE5ULL, 0x2069F12CD1E56E3EULL, 0x453E6E5EF7227A9BULL, 0x271EA8761AB0EE3DULL, 
            0xFA1562E9B4D336A0ULL, 0x562D0180B35F6827ULL, 0x6CB11B7A1AFD3D96ULL, 0x5FDE35D54E66E3F6ULL, 
            0xCC989950E435074BULL, 0xB142BC65C90EA2BCULL, 0x594F731B827997CDULL, 0x18E4F62BD2EDAC1FULL, 
            0x70DCC5F9392A183AULL, 0x8A91439B29D683F8ULL, 0xA4A790E30F67E60DULL, 0x9FE0131F5490A516ULL, 
            0xDB7A01CB9914CA02ULL, 0xE326681B46CAC897ULL, 0xAC6D90F15DD1C461ULL, 0x7B1808FFBD2628C6ULL
        },
        {
            0x021EB0AD28800F84ULL, 0x6829475EDAC780F9ULL, 0xA0EECD896E5026B3ULL, 0x17CB2CD9E81BE70AULL, 
            0x1866DE7DF05E6FC2ULL, 0x9D7959F43D9422E9ULL, 0x95867110825BD670ULL, 0xE61195164473BE7CULL, 
            0xC131A553BC03A926ULL, 0x4D031E81AE151BB4ULL, 0x9A3362A2602963FCULL, 0x0C96F5BA9B2A0F12ULL, 
            0xA2A2AED2846136DFULL, 0xC0F0AF714FC8A955ULL, 0xDAAB7319528F6DBCULL, 0xEA069863A359F0DCULL, 
            0xD28CBEFEEA4E3935ULL, 0xEF796CA20737AF8FULL, 0xE28D11426E2605EDULL, 0xDD56D299C1B417EFULL, 
            0xEA8EF6FD0888036CULL, 0xA77DCD2605F46A4AULL, 0xCB32E72C94D926A9ULL, 0xDF8CF7120FA7B60DULL, 
            0xD7CADA114B9D0AAEULL, 0x1ACFA21EFA6FF989ULL, 0xA14E8A32AC1FB531ULL, 0x389C0EE74048728FULL, 
            0xFD28D1CF4F54AFB4ULL, 0xBC6ACEFE75AEF59EULL, 0xC25C92E55574560DULL, 0xCCB873DC2DAFD846ULL
        },
        {
            0x4E7622078763EB54ULL, 0x57E7C46A3F80FCC0ULL, 0x92379265C1FDACE2ULL, 0xFCFA02EA015FAC2AULL, 
            0xC8131751E40771BEULL, 0x3089177C7FBE5CFAULL, 0x3E92DD0D7814DFC1ULL, 0xF39EA163D5A6ABEDULL, 
            0xEE93D3D1E8BB0FF0ULL, 0x6C605DE7129A4223ULL, 0x084AFDA3FBB3ADACULL, 0xD487E93C06AA7815ULL, 
            0x4ECA1A8132E904B9ULL, 0x4FEB3183401A6EE5ULL, 0xE6376B44FAB4BDA7ULL, 0xE83A8F04C0DF0163ULL, 
            0xD887E737E86AEAF9ULL, 0x33C026F62E867923ULL, 0xC586659C1403E9EAULL, 0x7142757AEB4A26FCULL, 
            0x8D262FD99642015DULL, 0xF95242554E0D1B9AULL, 0x682C13CE0C169FDBULL, 0xDBAF84211514346FULL, 
            0x7F4675C80392ADB9ULL, 0x3705AC71C3DCDC2AULL, 0x07B129F0756BAC25ULL, 0xA79B0A41A6572000ULL, 
            0xF2B18CB4EAE2505DULL, 0xE8FE791F6E401AF3ULL, 0xC7656050415087E3ULL, 0xFF1033ABEE7CC12BULL
        },
        {
            0xE7ECDE1FD1A74138ULL, 0x7800D52F08CB2929ULL, 0xB01E6BE21A5B87BEULL, 0xD994598A5B9E412DULL, 
            0x5C40F21F7CA8CD23ULL, 0xC6A01FFFB2F6D451ULL, 0xDE0CD1F7CB4E12F1ULL, 0xB9694CF89610639CULL, 
            0x062DD47098EFC32DULL, 0xFC691B6A192E9D59ULL, 0x50CCF39B06D14CA0ULL, 0x34618523A132454EULL, 
            0xF62C169274555DCCULL, 0xAA0D837382841B29ULL, 0x411B591ABC65D0D0ULL, 0x5DC595DF8D6C0FCEULL, 
            0x1188D89E8CEB0F60ULL, 0x7778458C900AE3A8ULL, 0x4513DEBF102C220CULL, 0x00CD21487AD34518ULL, 
            0x095646F33CCDEFA9ULL, 0x2CFDB6AE1C5F7CE9ULL, 0x7ECE95819D3B6F8FULL, 0x59B417A08BB1DCB0ULL, 
            0xE167A40953361F0EULL, 0x3861888AC9B9D321ULL, 0x34A9F28B2CC34567ULL, 0xBBE25CB83EED0046ULL, 
            0x53F7D47AD12A9B08ULL, 0x52215C8496A3FD63ULL, 0x23A03D02A42704D9ULL, 0x9FF5D8C665676C3CULL
        },
        {
            0xBC261C766228B0C5ULL, 0xA32100BCF0EABA47ULL, 0x6570B1AF7FED21FEULL, 0xDF33AC459F6332B4ULL, 
            0xE21E9674151BCC4FULL, 0x28C2D3854E4C8C5FULL, 0x6BAB6A7245F16CDDULL, 0x5A702CB0FD9356C6ULL, 
            0x331B6FB7FF8AA06BULL, 0x408F21E9FE04BD55ULL, 0xCB04C0EC0D2B86DEULL, 0x08F2FF3B19937112ULL, 
            0xC5EADC0AABB86B6FULL, 0x874C019723193AA1ULL, 0x2E2517A0F8845BF5ULL, 0xAB089A7B820081DBULL, 
            0x8770E5B58DDEE6B9ULL, 0x506231206F49FEB8ULL, 0x5B8F8ABA2CF21BF9ULL, 0x464FBB5BA2F7BE3AULL, 
            0x5735B20BD1EE0158ULL, 0x8E5E698CC4A01A01ULL, 0xE7F2A5D173CBE339ULL, 0xE31BEDF0FD0AA276ULL, 
            0xE97DC14C2BEC6AAFULL, 0xC4960E3F53558B75ULL, 0xFB832423C5BB0B58ULL, 0xBB8F1D5211E8E62CULL, 
            0x84CBD27A6C9404E8ULL, 0x9BFD062CF9382B34ULL, 0x97255455BC93F435ULL, 0x6BEF63E79EA558E8ULL
        },
        {
            0xB617647A0B6D2D59ULL, 0x117933D5EAC66EEDULL, 0x7551D84D29B57B82ULL, 0x9E8E1835C0C3F252ULL, 
            0x08B864FB4104815AULL, 0xA08445F20F9A63FFULL, 0xC12F04C34BBCCD0EULL, 0xC57A49D75B36A0D7ULL, 
            0x7C19DE55E5305E1CULL, 0x9A1B0394E429F2D3ULL, 0xC399AE99F2B15A5CULL, 0x08107F03AAE84011ULL, 
            0x3A4ACED209AF5E0DULL, 0xCB9A63243ABDB41EULL, 0x54D179DEE15A776FULL, 0xDD85FC4AACD4BCD9ULL, 
            0xFA5F3415E6256BE5ULL, 0x2D9C8726A3620ACAULL, 0xAD56474F71924898ULL, 0x6496D630D1C1B70CULL, 
            0xC8E808F761CC24BEULL, 0x019559AAB0BCC210ULL, 0x9A9A3027D680C5AEULL, 0x3BD738D8EDE115DCULL, 
            0x078CF2AC62A9BBEDULL, 0x7B11B6B5369240DEULL, 0x9674CDB65017BBFCULL, 0x2F14FF62DE5A053FULL, 
            0xFBE4C56DD2851D59ULL, 0x86DB783FA0A32A93ULL, 0xC27488DE2B8E3B61ULL, 0x7332DBB42E242636ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseFConstants = {
    0x371207952804511DULL,
    0x7C0EA7E07BFCFF16ULL,
    0xA010656ECF3E62EFULL,
    0x371207952804511DULL,
    0x7C0EA7E07BFCFF16ULL,
    0xA010656ECF3E62EFULL,
    0x35D993BD4D868C80ULL,
    0x970410B3E9978ACDULL,
    0x5A,
    0x14,
    0xA2,
    0x35,
    0x0B,
    0x14,
    0x6F,
    0x76
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseGSalts = {
    {
        {
            0x1AA4073118A506BAULL, 0xB370EB5CEBE575B3ULL, 0x5A326744EDFEA42EULL, 0xF7ACA45F333797E9ULL, 
            0xBB8796E6865D5C9AULL, 0x2591F0E15A9FAD42ULL, 0xBE91DF27C347D4FFULL, 0x2C16F1D6EE1313A1ULL, 
            0x30AA1A18FCAAD33DULL, 0xE2D13B53D611D184ULL, 0x889B23561DF7DC8FULL, 0x5DD9229E536AF34DULL, 
            0x83C06FC1E29F8CA3ULL, 0x7503C0A60039503DULL, 0x29EB8E4FC3EA6C77ULL, 0x95C36EDEA393E259ULL, 
            0xCF9DF641FEDEB7F7ULL, 0x936D347C776DD156ULL, 0xDC78D04B43A17ADCULL, 0x6F9544E02F5376ADULL, 
            0xC0DC4C62DD52839DULL, 0x68EE22642990B49FULL, 0xC909EE6A34836739ULL, 0x79384CE741330074ULL, 
            0x4737621184E5EEA8ULL, 0xC42132A973EF4B4CULL, 0xF4EA1FF11AF25871ULL, 0x54A87835F9A484BDULL, 
            0x530B0600FC6FF52AULL, 0xDB26F2EB4CF10A9CULL, 0xB557DAF7C3FE3A4BULL, 0xD2BAD7B8E63C5B2DULL
        },
        {
            0xECD8C443757E3347ULL, 0x64EADDA7AF24C5B8ULL, 0x9F75B2DF8436462BULL, 0xC43CFA24658CC596ULL, 
            0xD2BF85AA1837EF9BULL, 0x264A20D0395224E7ULL, 0x55E0054435AB1EBCULL, 0xA8DB5560D1256F38ULL, 
            0xAE194B59EA585DA7ULL, 0x08C2AF386BB77923ULL, 0xD0CAAEDF51CEFB1BULL, 0xAEFCE7275D89EEFDULL, 
            0x5AD87EBA0D4F81A0ULL, 0x2F6D7D6F17679EB1ULL, 0xB0874DFC07C000D3ULL, 0x5D04328AE9BE41CDULL, 
            0x10DA2631CF0F051CULL, 0x294114706AEF16DAULL, 0x9243480C70E68F16ULL, 0x6A87809560E90E5DULL, 
            0x1104D9902A11259FULL, 0x977A1E695DD71863ULL, 0x5A670B2637605A43ULL, 0x0334679D770CBB95ULL, 
            0xBB6BB642459920A4ULL, 0x724A672319AD4670ULL, 0x21EC4B37BA24FFE4ULL, 0x2827859DBE13BD6DULL, 
            0x35B1BC5AE31D3C72ULL, 0x8D2E43C89B81B034ULL, 0x1279A86B1A663255ULL, 0x9D35BA020F27240FULL
        },
        {
            0xF9104F6C69261CCFULL, 0x1FD61799DB10A3F4ULL, 0x3A422CE629CC44ACULL, 0xE82D230567B866A9ULL, 
            0x6A4B6F9F912B0A8EULL, 0xC06B6B325EB901B3ULL, 0x47EB25A70AA39B2FULL, 0x0823ABF92C0156A4ULL, 
            0x91C2598A395B5670ULL, 0x00FD9576F1106CBBULL, 0x44C99C1EEC88A9B9ULL, 0xFFB828024F6F6450ULL, 
            0x7F5011CAA4A303C5ULL, 0xB313050AC4D5EBD7ULL, 0x4DDBCE3CCC369A5BULL, 0xF97420B9170D1B68ULL, 
            0x31CBE727C5A04360ULL, 0x957D4620F0070007ULL, 0xA0160A6D1270514DULL, 0x37B94E4B23AD66EFULL, 
            0x2398412E2CC6759EULL, 0x5D63F77867A44372ULL, 0x1B34CE3A5E0D2A1DULL, 0x49C2A0C0FE1596B9ULL, 
            0xC2640AC05CBC447AULL, 0x050DCAE3D33031F9ULL, 0xA37436523F66A2DEULL, 0x155E1AFDF41AF904ULL, 
            0xE4C9DC569209C8EFULL, 0xF60E40A7FF03C417ULL, 0x6C41EE9E6E7653E9ULL, 0xC589A1DCC394AE4BULL
        },
        {
            0xA567599605D2DFA7ULL, 0x372C896B1602CD0FULL, 0x19A4A25E10EE4F7AULL, 0xAC5B560821B7773AULL, 
            0x4B3B03828838C5AFULL, 0x4E48A0AD1D73206FULL, 0x02D3218E5AD20731ULL, 0xE245AF30FFDC9866ULL, 
            0x41CA85A9D42AEF6EULL, 0x8E986285E4B53449ULL, 0x60B99DA5C18C5F68ULL, 0xD95BB06222E350C9ULL, 
            0x662129E3FC38D140ULL, 0xE251E90A692BE13BULL, 0x86BD3A520F036486ULL, 0x001F23F594CCC9A8ULL, 
            0x3BE9A566F0136923ULL, 0x89DE12A32A9DA369ULL, 0x4FBE56FA293717C5ULL, 0x53ECE475396B2F2BULL, 
            0x5F928168EFA8C077ULL, 0x9C30C99A3CFD71FDULL, 0x81130ACA80C61DF8ULL, 0x26597DDDEDD6A7ECULL, 
            0x8DCAE7E5868B34C0ULL, 0xF4ECE997D06A04B0ULL, 0xDC48BFA700042348ULL, 0x4EC6F3435860650FULL, 
            0x47DF4A544105F5D8ULL, 0x3E925330504B2C47ULL, 0xCE87716D6D0F256AULL, 0xC883EE8E8164DB20ULL
        },
        {
            0x490F05C18C9741E0ULL, 0xEFE03DB61E394B50ULL, 0x6F29B4C0460BF404ULL, 0xFACCF990B5448553ULL, 
            0x404D3A392FB3109FULL, 0xB2DFE1B679924DAAULL, 0xA6F65D00EF278662ULL, 0x20B2CE6A9807F68BULL, 
            0xC788A8AADE1CBA1FULL, 0x6B231C5F6B36158CULL, 0xB1FAC59B802761C3ULL, 0x32C972719FE91A42ULL, 
            0xC8366F3AA0B21A94ULL, 0x30C6FC6B69BBF45FULL, 0x34607945DC7DDA1DULL, 0x7F9473DC0F1C45D1ULL, 
            0x8E4C009DD398FDB2ULL, 0x447C40DE5288684BULL, 0xD46104F3C6A121D8ULL, 0x0484DC383F127821ULL, 
            0xC3FF4216BF040EBAULL, 0xBF835285BEC0A4CDULL, 0x82ED2283248DA984ULL, 0x333294B2D7E6D194ULL, 
            0xB669C6AB69C09796ULL, 0x46E650428D8FB644ULL, 0xD395C42AD57D4435ULL, 0xB975BC15816C4886ULL, 
            0x515856C6A4C679D0ULL, 0x0FA2C692D144C6CEULL, 0xBA80B2A2EBA11099ULL, 0xCAA66BC957C01A46ULL
        },
        {
            0x27CD9F051850BE6AULL, 0xE46B12525F37BF65ULL, 0x25237405270EF893ULL, 0x23AB59A4D84C536CULL, 
            0x8D1C81950BFA6610ULL, 0x62015338C9CE87B6ULL, 0x97CBBF18136FC25AULL, 0x1791D57BABB9B3B9ULL, 
            0xE5746187B13A5D0AULL, 0x9E89FF7BEA4A9484ULL, 0xE1F9833B83A8095EULL, 0xC1E6EE69253C25AFULL, 
            0x8C631782E77AB260ULL, 0xB7B28FC940B3609FULL, 0x56E109F9FB5D6E6BULL, 0x2D84BB8CD1D6A272ULL, 
            0x046B818A26016FECULL, 0x5B53647A5E1CDBFCULL, 0x6BBA4CF0272D59DCULL, 0xDF081D42BB9B4DC8ULL, 
            0x6E6D65589CF9927AULL, 0x1EDDA746EDEBD824ULL, 0xB58A6C7208DC1009ULL, 0xA59A79629DB0610EULL, 
            0x1F3795E614FCCE97ULL, 0x6E73C0E8C7AE69B3ULL, 0xED8EAB6A12150655ULL, 0x4E5FE47C24F8C68EULL, 
            0x054C2AEA26E0C83AULL, 0xD1B9877E06A49695ULL, 0xC9D1DB23E3A69BE9ULL, 0x8C585408BE378113ULL
        }
    },
    {
        {
            0x79468A3830C095A9ULL, 0x26C4B7AFC7623573ULL, 0x1A6841D5FECD555BULL, 0xD1BDC0FDE0F2E4F2ULL, 
            0x48D3E887B9E1DAFEULL, 0x70AD331BD146E8AAULL, 0x775D4F70ED9DB2FDULL, 0x98072E698B22B698ULL, 
            0x66B308459325E3DCULL, 0xADC0765E801E6442ULL, 0xFFC5574FE540ED81ULL, 0x28005410A4490820ULL, 
            0x705BE22E31254875ULL, 0x0ECF5A999853ABAAULL, 0xEA591C12A8DF661AULL, 0x29F87274E4B3C65EULL, 
            0x5328239E0ECC84A1ULL, 0x4DD393E516EB22B2ULL, 0xA304BA814EE0766AULL, 0xE03201C0AC1C66A1ULL, 
            0xC22F25B32AA15312ULL, 0x951D6426229CBFF3ULL, 0x8E0E68CDCE6D7413ULL, 0x946B02B6D7413562ULL, 
            0xBB810F6D9F3F1127ULL, 0xFA1C24F5AA4DC57AULL, 0x04A0E57F6A616A61ULL, 0x6ACD3733B62C56DBULL, 
            0x24C2E1E49853B186ULL, 0x8642B65A4DC7E8F0ULL, 0x9FA64C946A3E2E8AULL, 0xF1B858370F031CEBULL
        },
        {
            0x945DB1A75036DCB1ULL, 0xFBBEEDBC950EF8BEULL, 0xC3DF6BB9BAC585EFULL, 0x65EBE99B5DFA8EB1ULL, 
            0xBBF9E86E32016478ULL, 0xD3F87453E3760723ULL, 0x2DDEA17FD8642AD2ULL, 0x30372A2AF6EF6C69ULL, 
            0x899EC6E64D478037ULL, 0x625DE2F394EFA963ULL, 0x8AF9798913A7D979ULL, 0x4E13CEAD139DBAA6ULL, 
            0xD739CB94CFB5D72FULL, 0x1682CB33C0501E8AULL, 0xE9AC4C52690DD0DBULL, 0x18EF6B6358350637ULL, 
            0x2CB7379B08A8E68EULL, 0x1B50713CE918C488ULL, 0xACD9D85895722353ULL, 0x90D36EBCCB9EF629ULL, 
            0xCBA2C7DD8C5B586AULL, 0xDE7C3E460FE3CD01ULL, 0x67DA95B94CB1CD50ULL, 0xB8D50E95B1A92F88ULL, 
            0x1BDDEFAE12AE3AFDULL, 0xCF88FE5E5D6CF074ULL, 0xB15D4F8F44CAE87AULL, 0x7BFD6240A0D8BD1BULL, 
            0x9FE4B64221BF9546ULL, 0xC94005721D37FE74ULL, 0xD7349F37CD832C99ULL, 0x5425BB5CC20D9C30ULL
        },
        {
            0x931AB7FA913E684BULL, 0xB0ADDC0862305E49ULL, 0x8A4480288620006BULL, 0x74B46ECEEFAA258CULL, 
            0xF080C3BE86563425ULL, 0xD4849C3A7CA5C7F2ULL, 0x0E0A6F3C44EE3474ULL, 0xFA07E44B2E7D4BF6ULL, 
            0x49B19DBC73BE3874ULL, 0x6B30C9BD51F79A15ULL, 0xBFCA2171B1017046ULL, 0xDFD5B2B38C196B5BULL, 
            0xA859ADD9B2CB26B7ULL, 0x08A2B9C6383FC27BULL, 0x4E543C1B75DEA15CULL, 0x837A0B5D7E9489D8ULL, 
            0xC9928E3F561993E2ULL, 0x4229DC04B201483AULL, 0x08F506C480CCEB47ULL, 0x072DAC70CB7CE021ULL, 
            0xAE54620367443C24ULL, 0xBF8891B8F08C9051ULL, 0xB7A4A17F78A65518ULL, 0x7BFD9CA22C69E295ULL, 
            0xA57DEB34E7B67783ULL, 0x8AD525DDA5285A28ULL, 0x6C915E560E355E58ULL, 0x00E28052A7D747F7ULL, 
            0xB704C665A0D58859ULL, 0x43279615060FB84DULL, 0x6620B8184E6099EAULL, 0x912F44BA1428C39EULL
        },
        {
            0x66FBF8B58B896A69ULL, 0x5919ABCC50D91E53ULL, 0x26C2F5237A7CC90AULL, 0x44478B7CDA166D26ULL, 
            0xF5B9EF5B892A8E38ULL, 0x4A4395E8A97B508DULL, 0x6B671D4D546EA63AULL, 0xADA8EEC0F4C0E83FULL, 
            0x772FFB9D9C1B8780ULL, 0x8B0D67AE35D03E65ULL, 0xCFDE33D09F048172ULL, 0x3E19F64405559CEEULL, 
            0xC28AEE283E038145ULL, 0x0AAF34E4276AAC53ULL, 0xCC287B210F960811ULL, 0xB38600AAFBBF02C1ULL, 
            0x2D12C09CA8AFCFB8ULL, 0xAC4D3DF17CA6C22CULL, 0x76572BEC633F7F82ULL, 0x51ADA750F4459E3EULL, 
            0x8C6C2FDFFDCA1805ULL, 0x6D47201D332A4F71ULL, 0x6D183BB4D68E45CFULL, 0x2A3212D20EEA1949ULL, 
            0x8C7AE7A6687DCF27ULL, 0x829E0630BD01D365ULL, 0x97B9CD0C8FF54081ULL, 0x21CD00810B5E57FDULL, 
            0x9B20663DF86A2B9CULL, 0xFF2371E5A0219FBFULL, 0x593D8CB85BE641E4ULL, 0x36FF226ED5027DC2ULL
        },
        {
            0x46F4A4C704AF07E0ULL, 0x633472676DB383C6ULL, 0x188F44CA9C106736ULL, 0xF18485B61272B67AULL, 
            0xCB96B0A94D02EEECULL, 0x4AEBD59B52F43838ULL, 0x0E1648F0E1A1E383ULL, 0x7C1669708122FC8AULL, 
            0x509B083B5C64A00FULL, 0x3063A8934AC695BDULL, 0x794345980B9D39F7ULL, 0xC182832C2AC312CFULL, 
            0xA743E87D1C09B9EBULL, 0x8E13DD9C663A0D98ULL, 0x011F9C8E5C22EB76ULL, 0xB53D0E4EA184552DULL, 
            0x78BAA783CD7B2574ULL, 0xAB6AAF5556505EB2ULL, 0x36CADF6755441DD5ULL, 0x014122A18280B20AULL, 
            0x2B63FE8D8D1B6374ULL, 0x3268B235CFB67088ULL, 0x12ECC067AED5E640ULL, 0xB30654CDB85985E8ULL, 
            0x57C870174EE18745ULL, 0x1D6DA8E0C0C8BBE1ULL, 0xC6232A66132D1DEEULL, 0x0F9EAE3BF38B39BFULL, 
            0x38C751857E442700ULL, 0xCDAF085830C79576ULL, 0x3EB06747E8DFC772ULL, 0xFFB43306BDDD9E25ULL
        },
        {
            0xC9C8DB0618FADC1DULL, 0xCC2832012A657570ULL, 0xE70A2A67608F0750ULL, 0xC65C47E4B56B450AULL, 
            0x3377FC543428ADEBULL, 0x50BE41A9AE0BE1A3ULL, 0xBC2DAE353A4041CBULL, 0xCE4C249EB5B52938ULL, 
            0xEBEBDE1369AB679FULL, 0xA4C86B3202EA63AAULL, 0x47B0D9C1B2905FC8ULL, 0x3FB0965F4D4C6736ULL, 
            0x7B8102128CBCFCE0ULL, 0x6837D0788B7A07B8ULL, 0xAF2FE91E6BBE007DULL, 0x1097A5DFD77ABB40ULL, 
            0xE2CA6EB413EDEEA3ULL, 0xED1BC7C3A4DDCD84ULL, 0x3A83DC93BEECDD20ULL, 0x3A894D6866F66BD0ULL, 
            0x836ACCE70362C075ULL, 0x682B421CCFF8D0ABULL, 0x095EBAF81F38E0C8ULL, 0x977A605426DCB0C0ULL, 
            0xC2AF331248B82D52ULL, 0x9857489C255B9508ULL, 0xFF4B4013448C13B3ULL, 0xDDB36286468AE836ULL, 
            0xE1B709045F0D13C2ULL, 0xCDF781E68ACB4AC2ULL, 0x8E8BACC51F15948AULL, 0x0F5716EDFBF5B23DULL
        }
    },
    {
        {
            0x06C8E47B1CB9FA39ULL, 0x2C3E809759F01AECULL, 0xBD6E457088DBA213ULL, 0xD47DFE6BC154A147ULL, 
            0xCE41EF240F226419ULL, 0x65D3A64581C09F61ULL, 0xE83CD05539F0E871ULL, 0x59D76174FB1CA097ULL, 
            0x8F42A5873ED6E285ULL, 0x39E06DAF060B29A5ULL, 0xFECA99094F2330D1ULL, 0x1869FCE8580A60A9ULL, 
            0x68840C4B143C2DF1ULL, 0x09D228C1A551334AULL, 0xAB04F13E5639DE94ULL, 0x88EC3E246C111D94ULL, 
            0xAB446371A65B8F49ULL, 0xF2BFF055D75249C6ULL, 0x29FC22AEA6D9B2C7ULL, 0x275418EF9E790579ULL, 
            0xCCF4165788F7AD87ULL, 0xDEA6A0379747A6F1ULL, 0xB03FED53C13F5D86ULL, 0x5412523E3357AC1FULL, 
            0xD3CD686297729C76ULL, 0x5F05F18DEB5958A2ULL, 0xFDBD5A47F7FBC86CULL, 0xE50F505796CDED33ULL, 
            0x0885757C9B2EB297ULL, 0x5461E89E1C107F7FULL, 0xFE65D195733116EFULL, 0xB064B0629FF1FECAULL
        },
        {
            0xFDEEC6CDDC1D2406ULL, 0x3582A9734C15691EULL, 0xCE8A43B1F384FFBFULL, 0x92F679FB3BACBC5AULL, 
            0x972EF085966D6B93ULL, 0xAEAB8AF330FFF3D3ULL, 0x37AC242958949C60ULL, 0x14E259C5A5BF3297ULL, 
            0x9EA060F3B4E22D37ULL, 0xD23F1073993BA211ULL, 0x5BBC31E4F936D363ULL, 0xD9F731AFC05D1C13ULL, 
            0x4AB37218D670974EULL, 0x40162CF936DD092FULL, 0xB5ABE10677C1D31BULL, 0x64501FC0BFE1D3AFULL, 
            0x4085D17C2C522140ULL, 0xAE5ECD5343DCE64EULL, 0x3B510353EF9F47C2ULL, 0x8605B38DE4BACF04ULL, 
            0xAE975A7727E9F672ULL, 0xB9407143B7350297ULL, 0xAC2153696B20C878ULL, 0x8C5EF8ED62F8CDB2ULL, 
            0xA1CFB0CCD301628CULL, 0x2A494D4ADB9A6D62ULL, 0x34168DB8B9D09AFCULL, 0xEF81EABFCE62FAD1ULL, 
            0xB18837071977C87EULL, 0x168719637C26199CULL, 0xCB0C9B3BCC51B8CEULL, 0xE3E065B0377A585DULL
        },
        {
            0x827DA6D288B4A249ULL, 0xD0A1392842901028ULL, 0xD0815DEDC502BFD1ULL, 0x1BC2EFCC9FA8CAAAULL, 
            0x0423E440F10C6BC4ULL, 0x9AB2FB6D092A7168ULL, 0x0FEBE2852E6C1368ULL, 0x041330245BDD0050ULL, 
            0xC1E363A5D09EA733ULL, 0x42F5185CE73DFB2BULL, 0x278A2CDF02D16942ULL, 0xA5AE9620F2C0C76DULL, 
            0x9E2B66DE4F5C3068ULL, 0xA19C8F2D5A5BC6EAULL, 0x7904278A25FE6604ULL, 0x4B1B00B0A0F3F865ULL, 
            0x16B1E3B2EC7686E3ULL, 0xD341F5B33CA3C86FULL, 0x2DBFB6BBEA61D639ULL, 0xDDC195219709CACBULL, 
            0xFC75A0262D6CE4C7ULL, 0x25D965A18625CB79ULL, 0x577E9FD0FBD934FBULL, 0x5A1BD24D18C2E632ULL, 
            0xC082E817CC459838ULL, 0xF066B574939D12E1ULL, 0x95988F0DB6469FB2ULL, 0x97A63067DEC56DEDULL, 
            0x3062A5E15C6972FAULL, 0xE2F239540FC1AA5DULL, 0xEB77632E5D4AFB63ULL, 0x36271EE2EB7D76C2ULL
        },
        {
            0x7A7E9D5C7E797D24ULL, 0x930830D80B4D6FAEULL, 0x65E4AC5E7D46336FULL, 0x5A80AFF2DEB29E2CULL, 
            0x5C78AAF91E63EF48ULL, 0xB8F3C493D48FD191ULL, 0x5B7EAE0FD0A8560FULL, 0x4F77212FC67C90C3ULL, 
            0x0B871635C5308F96ULL, 0xA26374F32C9BDE36ULL, 0x4C179E8154F0BA08ULL, 0x756C31B24E9669BCULL, 
            0x969082F033390578ULL, 0xA799BD911386E102ULL, 0x94168E0A33BA6B5EULL, 0xF8B6A46DB196C4BDULL, 
            0xEA511003F983413EULL, 0xF5A4B6ED04E9F906ULL, 0x01E1010D57C8FB86ULL, 0x5AE794E9FF30D24EULL, 
            0xC2C1F7C371B85989ULL, 0x2F4D13A59EC476A6ULL, 0xF0E83864D9CFFCFAULL, 0xD82D7E302A0A483DULL, 
            0x55F6964F6D88399EULL, 0x33D71C4284DDCAD6ULL, 0x775474827B8E6DABULL, 0xC046A5726AF22CF2ULL, 
            0xA951E09F7B08B1D0ULL, 0x012F97E16D67E165ULL, 0xA7D236CC8F27BB09ULL, 0xF4B5F05F6B0DCF01ULL
        },
        {
            0x19C16B2F379DC7B7ULL, 0x342BF9C5BF0DCBD4ULL, 0xC5E0E46525A8C2E8ULL, 0xE05223A1EEF7024EULL, 
            0x4296F2C0F19E4A61ULL, 0x1EB68AAC501E59F8ULL, 0xF40A861029370805ULL, 0x1F6EA5E742495DC3ULL, 
            0xC0C8C34F8E7B589FULL, 0x7DF48B6F2D7533B0ULL, 0x149861D30B1E2CB1ULL, 0xC6EA1F5BFF037A85ULL, 
            0xBF35C2FAA7C46D00ULL, 0xFE0065D52D5F22E8ULL, 0x3710AD5EB6E286E9ULL, 0x7B7B5D052A4CF009ULL, 
            0x55951C13AD2BF310ULL, 0xAAD7EC6C52B9989FULL, 0x81C3F63EC7C924D3ULL, 0x70B441D0FEBEE5DDULL, 
            0xD4D47998B25E4424ULL, 0x041218EEB02CE3BBULL, 0xEBE19DCE5CF3296BULL, 0xF494F43CB3F20510ULL, 
            0x87489492E81D1F46ULL, 0xB5325D6708034155ULL, 0x0C50B2C615036915ULL, 0x6B42CB9503D75162ULL, 
            0x7D77D9FF856615A0ULL, 0xEE553864A021E1FDULL, 0x627EBBE4079C0ED4ULL, 0xE442263C74471AB6ULL
        },
        {
            0x11112A80526B2FD9ULL, 0x3786732A5B9F34BEULL, 0x04DF03432E0B9009ULL, 0x9562DC8734FD959CULL, 
            0x7A99405B95FAE8D0ULL, 0xEC20827E5D2EEB7CULL, 0xDABF86D0C72DFF5EULL, 0x3E7DDE62DDD57E1AULL, 
            0x0A7A7367296E6E6EULL, 0xBB341130C170D713ULL, 0x5502B5FC69BE1C93ULL, 0x45F06BC4290238EAULL, 
            0xAAFFB254E8252154ULL, 0x3C029D1F0ED78008ULL, 0x6087A637807FE90CULL, 0x05B7DFF184AAF3D7ULL, 
            0x1226C5B96555A1A8ULL, 0x278346F3409E9D82ULL, 0x305720587167918BULL, 0x01B39E103A84564EULL, 
            0x6E86760616C544ADULL, 0xCDF1A8C7E71328ECULL, 0xBCA3F9C64B492BE0ULL, 0xEF44FB74ECE24412ULL, 
            0x963607A9A6F73CE1ULL, 0xC71FCE9F49B29070ULL, 0x2440C0CDE8C65F55ULL, 0xE160C8D603071298ULL, 
            0x9EC40CC221F35E91ULL, 0x4420B38825E83C42ULL, 0xFAFDE21A5EFDC604ULL, 0x0BB3D13004517950ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseGConstants = {
    0x302A065413E3CB64ULL,
    0x622AAE8A803A78CAULL,
    0x3FB71A2C31DA86E4ULL,
    0x302A065413E3CB64ULL,
    0x622AAE8A803A78CAULL,
    0x3FB71A2C31DA86E4ULL,
    0xCF2BB01772630255ULL,
    0x915EB749CA627BA4ULL,
    0xAE,
    0x5D,
    0x68,
    0x7F,
    0x9B,
    0x69,
    0xE2,
    0xC3
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseHSalts = {
    {
        {
            0x4904B76B0B3F5CF7ULL, 0x885A2DA5EC8DDF65ULL, 0xAE16B67D40D2BCE7ULL, 0x8874694598893D9EULL, 
            0x86E665FC84847389ULL, 0xD07E08723E6ADC9EULL, 0xDC285E5C18DE4C5EULL, 0x45B17A6BD05CF23EULL, 
            0x61FBF28D5F8F788DULL, 0x132FA44482BAD6ACULL, 0x25A6B8171BF41E83ULL, 0x8917E67EC705C6A9ULL, 
            0xCBE9AF8CA1D1E1E9ULL, 0x24139FC8C30EC0B5ULL, 0x703A19A46BC4FFE8ULL, 0xDA910FFB37F2ABE1ULL, 
            0xD81309FC081B9A81ULL, 0x83D9B10142041B0FULL, 0x8D0D2DAED8EE19D4ULL, 0x0F748B5615E2109BULL, 
            0xB8F64DC1EC703226ULL, 0xCA20FB0F0B8CDAD0ULL, 0xA0BCD8E5CACEFA3AULL, 0x674F8EC06BC5EDB0ULL, 
            0x345A635881D85846ULL, 0xA70840A4125DB100ULL, 0xB3F2CADF399CBCFEULL, 0xF8CAE3D2F2FEA82AULL, 
            0xC126C4D9D3E152FAULL, 0xA4654616382D8874ULL, 0x89BC87E7FF0CA8A2ULL, 0x1F741A570496B4F9ULL
        },
        {
            0xEAFFB342985F005AULL, 0xB1B8CD42675AA3E0ULL, 0xF17DE382CE048032ULL, 0x71E7CCE85A7CB9FBULL, 
            0x0937160A3DF0DBF5ULL, 0xFEA81663AF76523DULL, 0x166613943569CED2ULL, 0x5B9E5D6DFE9F2FFFULL, 
            0xB9EA3A797699BD26ULL, 0x0D7399CEE6DF3438ULL, 0x123CF4A298A40642ULL, 0x3A7AC8DE6DC02040ULL, 
            0x0E80C7173AA62655ULL, 0xF6B5B503660C44D7ULL, 0x5D1C3A4F1A944857ULL, 0x432410A705F5D1DBULL, 
            0xB8E9F9BAF3B3F530ULL, 0x6262FB0934C6262CULL, 0xE53F4C60E5D7D500ULL, 0xD62D9575E26CFB1AULL, 
            0x663DC890E78747A7ULL, 0x6FB59B6AD8B871BBULL, 0x0F9A91FCFBB6DAB4ULL, 0x108C1694634EE512ULL, 
            0xF3E8A49DADAEDDA5ULL, 0x4AEAC9117985FBD5ULL, 0xDE7F59278886A85FULL, 0x56030F3AF3ECBED6ULL, 
            0x614064744F530C63ULL, 0x8CC8091742CE093DULL, 0x8AF49ED9E6C1CE46ULL, 0x25CA74130F15CB50ULL
        },
        {
            0x197E83D3C05490AAULL, 0x148CD05885712C97ULL, 0xB893AA3F7EEFA5C8ULL, 0x36EEF7B04648FD85ULL, 
            0xF521BD7E760F81C8ULL, 0x81C45DE60D6B7500ULL, 0x7E66E801B97B8FE4ULL, 0xABA127AAE12963E1ULL, 
            0x957E8DB2F5D3BCFDULL, 0x9ACD6B4F1781A0A6ULL, 0xCEFE9810B69AB6B4ULL, 0x7CB1C701580338EFULL, 
            0x7D6F906CDDC5DA1CULL, 0xC57B2F540837653CULL, 0x6897916A81CFA457ULL, 0x939D6675E465CD1EULL, 
            0x7C251F1BBDBF30B2ULL, 0x96ABF3C483FC7561ULL, 0xF0569C9AA9E01275ULL, 0x6909154A1626F201ULL, 
            0x35D930BE3A7ED8C2ULL, 0xA0F5223539A12F46ULL, 0x113EC23DB6F41E34ULL, 0x69A10E02E002DBFDULL, 
            0xA88303F241B089D9ULL, 0x8BF968B22E4CE1CCULL, 0xD5231970B05DD0AAULL, 0x07D3BC32D625D9C4ULL, 
            0x0815110403E5E46BULL, 0x896FBD63652849D3ULL, 0x611BECE4E9FE7B82ULL, 0x5E836E737B20DACBULL
        },
        {
            0xB3F6C1EDEAF721B4ULL, 0x54DDB7A6D3DBD296ULL, 0x912736A0EF198CF4ULL, 0x8DDD19CA05649744ULL, 
            0xA0E60E9CA653EBE3ULL, 0xEB38CEBC8883B13BULL, 0x7EBC37F4B10165EDULL, 0x240D0E38875F89D5ULL, 
            0x588D9648D0B78F12ULL, 0x643BB4A04788FD28ULL, 0x066CAFD09671DC10ULL, 0x06DBDEBC63DABCCCULL, 
            0x57673BCF0BF24F75ULL, 0x460CCAA3173F8E23ULL, 0x706B13E82408108EULL, 0xF63FB916840F1566ULL, 
            0xAE5FFCEC16D280DCULL, 0xEC84D7B3836BC380ULL, 0xEDEADF7CD6023DC1ULL, 0xE0E27ACBDDCA2A98ULL, 
            0x784380EEF1AB4D20ULL, 0x6D50E121B60BD7DDULL, 0x8B21BC59F6EC2531ULL, 0x18E22DB649FDCC53ULL, 
            0xBE02BF1194B17830ULL, 0x7C77205F3A79F7A1ULL, 0x660A6EC9AA67199FULL, 0x7B78845C29ABA9BEULL, 
            0x066767C9514D3973ULL, 0x991D4023F41643BFULL, 0xDAF331C183769B01ULL, 0xC36552EC557CA00BULL
        },
        {
            0x7B45667C539EEDBEULL, 0xCBB050F96B82F6A6ULL, 0xDEE7B350AEED4317ULL, 0xE349204E73B9AAF6ULL, 
            0x5EF8DC3DFA7BD859ULL, 0x912D7F2ADF4DD07EULL, 0xCBED049FFF4403F7ULL, 0x8B47951D320312D9ULL, 
            0x55441898B904BAB1ULL, 0xB890FAF2DB5F6EC9ULL, 0x16895074664CA7ADULL, 0x4E6C352D63397D8EULL, 
            0xE1BF4798E6BF480BULL, 0xF73575CD121FB636ULL, 0xF9FBEB280701B4EDULL, 0x6AFB8FD86387F8B8ULL, 
            0x1969E86F38F3487FULL, 0x1295EB0B7F5AB40CULL, 0x2D0E42F54D63D8A6ULL, 0xA0D54E22837CD348ULL, 
            0x28F07527357BE9A5ULL, 0xC2C19A9A2C55756EULL, 0xC415E3605D0FA76EULL, 0xD1230519A3FCF5ACULL, 
            0xF98AA14590C98FBEULL, 0x78AA72CD454BE1D0ULL, 0x0635976DBFAC1820ULL, 0xEB9F06505BC5BC0CULL, 
            0x33A3B4872F49F5F6ULL, 0xDFF05C1342CC09D5ULL, 0xF92D724704F6115CULL, 0x696C0D468C156805ULL
        },
        {
            0x0181D72F734702FDULL, 0x3D412BA4F3746586ULL, 0x86C3697C270B8BFEULL, 0x797E59B2FC6DDEE7ULL, 
            0xD1839FA788A130F7ULL, 0x1D9BC46F29A3F39AULL, 0x97BCF6E15AC46BD2ULL, 0x7CAFDED9A48A3207ULL, 
            0x5859037773D56A0EULL, 0xABFBB93D438388BBULL, 0x71AD6C1B7A5DF405ULL, 0x33C6824DA2778B72ULL, 
            0xCDA20DED121A3AF9ULL, 0xFB26E6BE213131EBULL, 0x83355972D0F0CBD9ULL, 0x106E15438C7498A0ULL, 
            0xE3C8B7CBDCD6EB18ULL, 0xBD2FD377D55B1E36ULL, 0xE433169F5E1E25C5ULL, 0x548489EEF0DF5B66ULL, 
            0xC5AA09185A3037D5ULL, 0x8D85661D81FA82C6ULL, 0x302ABD67FBABB620ULL, 0x06C0D7E3BA91D686ULL, 
            0x08E2769EE65925ABULL, 0xDB4942DF5CC49EAFULL, 0x5BE3EA0FAC66C107ULL, 0x3CEAEA9824D794E5ULL, 
            0xF8CC9D75D93F800BULL, 0x4DD74D84EE5AEB87ULL, 0xF4750FB21807632DULL, 0x6EF9077227BD69F6ULL
        }
    },
    {
        {
            0x1D358FC1DE360AEFULL, 0xDD57C1A54BB491C9ULL, 0x9F0C90FFB7FBAB78ULL, 0xC2D85EDA7DECC946ULL, 
            0x0E37E1554E6D025AULL, 0x157CBFD3EC8E9070ULL, 0xF5AD1C53D8B4D501ULL, 0x102201D180C50506ULL, 
            0xD46A931A417338DAULL, 0x3342E028B8A9BFE2ULL, 0xD210E1A532985FBCULL, 0xFD5DC6C1F3F62694ULL, 
            0x4C8F6D6C50BF48C8ULL, 0xE63FD4346C29092DULL, 0xC8BDD07F53BFD01DULL, 0xD50C7A08CBB4EF50ULL, 
            0x4E51B45E040096B8ULL, 0x7A18099EBAC6963CULL, 0x4D632889900FAE41ULL, 0x91154CE42C962876ULL, 
            0x4AA69361AA6F6F92ULL, 0xEB06FF94A7AF5947ULL, 0x319838164F5BE7C0ULL, 0x72D79E4D1B47C5A5ULL, 
            0xDA71A39565E43463ULL, 0x8462EC5776CBC51BULL, 0x458CFF3811DE14B8ULL, 0x8E2AB132B1DC186DULL, 
            0x9F74CD479682114BULL, 0xEEDAE31F4FCFDE8FULL, 0x5D3FE6E7D5262F24ULL, 0x646089EE77B56917ULL
        },
        {
            0xA612DDF52E9B7F3FULL, 0x2DD50F9170F681D4ULL, 0x74C740C46193A885ULL, 0xED8129C01050F7BBULL, 
            0xA110A0427333B629ULL, 0xCD204BBD9604B13DULL, 0x9A8682E67D33F567ULL, 0x8F6D620E11604D95ULL, 
            0x2CC158BB5C759CC3ULL, 0x6DCA6D22BDFC0F76ULL, 0x1462665412549B6DULL, 0x20E8A405EA1FAB61ULL, 
            0x3BAA30E6E4E8F0F1ULL, 0xB671DDA24D6DF7B9ULL, 0x0E4D8B21A7AB24ACULL, 0x6CFF710F470241FCULL, 
            0x3178C603D7735927ULL, 0x0311F195E187F60CULL, 0x02382BDE2C5C17BCULL, 0x16A9A1B6DC5A0C95ULL, 
            0x2A87C9BBEDE2BF8BULL, 0x7589478D67BEB638ULL, 0x22565BD85FDBB419ULL, 0xCFF0A2F1165E6999ULL, 
            0x04B554188331B3FFULL, 0x2BDF94FF960D31B4ULL, 0x7A189E54508DD3B4ULL, 0x652A4196F9A0AC9DULL, 
            0xC9AB2FBD09EBD79AULL, 0xA33E1665EBF82B57ULL, 0x5A361392D895B1FFULL, 0xF8CDBDB7245A9CC8ULL
        },
        {
            0xDCC0BD305BBA69DDULL, 0x57DED530CC9234E7ULL, 0xD08DA6A655BFC9A7ULL, 0x5D7B853E0DE8A1EFULL, 
            0xBD8098EF83C82C3CULL, 0xF2ECC60F4A100650ULL, 0x6BB5D985CDD50065ULL, 0x4FE482AA59D1FF2BULL, 
            0x724AC348AE6C832EULL, 0xB5D0CAB709C87FC3ULL, 0x78C649F43535AA5AULL, 0xD5BC9A87876EE44FULL, 
            0xF60BBEDC586F5FA0ULL, 0x1E327471A5522194ULL, 0x5DB49E26A635DABBULL, 0xF777329343354091ULL, 
            0xA657E98B989893CEULL, 0x9A15A77823354371ULL, 0x8702C41EF1726CBEULL, 0x5CFF0C64BECC8758ULL, 
            0x0B83B4ACAA0DC2FBULL, 0x63CE98BD3AE68B1EULL, 0xC8968A38933FEBA0ULL, 0xEB95CD957A51453EULL, 
            0x7DFE1D3A27C0B75EULL, 0x75497AA656E183F7ULL, 0x091134555F8EC464ULL, 0x97FE8833458DAB35ULL, 
            0xE07E46F1091B85D7ULL, 0xCE64AA4C9E4F7371ULL, 0xAE78B6EE4A0B4C2FULL, 0x982DD54156BD4F5BULL
        },
        {
            0x3213400BB1FC27F2ULL, 0x6E15A6C0EE6AED9FULL, 0x17C9A90601ED1BD8ULL, 0x24A0D8F7DBEBBA73ULL, 
            0x3EB99836D20910A9ULL, 0xDBADC78256E06427ULL, 0xFF03023118F6396EULL, 0x686ABC67CF483D2FULL, 
            0x275F0987700A7B61ULL, 0x751FFA4D93470343ULL, 0x161E1C18B610F745ULL, 0x7852D92A300260FAULL, 
            0xDC36FEF5A9AA93DFULL, 0x46FE00E8F4047437ULL, 0x9BD2F8E97B01C531ULL, 0x7882CDFE92396273ULL, 
            0xB76B420EC35D9BB4ULL, 0x427FE7EE1F2A3A71ULL, 0xBD5D17A6744F06D9ULL, 0x540213E9D404CFECULL, 
            0x6B572C74F2CA1D13ULL, 0xC53DC4ACA6862104ULL, 0x381F9AD88FF7E9B9ULL, 0x764C47F98EFAA9E3ULL, 
            0x6388624471B374A9ULL, 0x64914DB52A160ABFULL, 0xEADFA52CFB571C96ULL, 0xDE6690888AE735D0ULL, 
            0xEF2ED9A5E809FEABULL, 0x5BD33EF0FF83DE04ULL, 0xAA9EA4A887A4E62EULL, 0x6370081B9CF069E5ULL
        },
        {
            0xBB6028B5813FFEBFULL, 0xAC89F12DAEBA7A21ULL, 0x71450F98CF37CBDBULL, 0x91CB0C21FBE62A8FULL, 
            0x188E2F6F3A39071DULL, 0x4ED878A5DF10003FULL, 0x11C51DD8063E494CULL, 0x0992466A3CF620C7ULL, 
            0x4236BFFCBEF636EFULL, 0xEFD8899DEA44C09AULL, 0xCA5F66178CDDABE5ULL, 0xD73EACA27C236264ULL, 
            0x9D9D8C8F14F4A5B2ULL, 0x35015DC6B2C85CE9ULL, 0x3772489E06FC78CAULL, 0xD77A5BA8255C63C9ULL, 
            0x3CCC8ED62C65C4B7ULL, 0x61C6E5BE75F7608FULL, 0xB099219B4D1E021EULL, 0xF642C8FD55B901DDULL, 
            0xE893C7094F112C06ULL, 0x6DDA6EE9A594C243ULL, 0x238B29CF81115871ULL, 0xD1D6B0B6DC21171BULL, 
            0x9E7E81843E6FBCEAULL, 0x90D80F455DBF4CBFULL, 0xACC5AF38F3038693ULL, 0x25B8BDDDBD53A9DAULL, 
            0xE001D8200B523E20ULL, 0x817F2C2A295F9DD2ULL, 0xB5EA66C819F7CC12ULL, 0x5D546513C634D6A2ULL
        },
        {
            0x5695C425C25420F3ULL, 0xA721B1AE67D7EA25ULL, 0xF6E46A523E0E3A51ULL, 0x6A03A5E2641A84BCULL, 
            0xDBB8B6846059D810ULL, 0x4CA7EA46C3B9A0C7ULL, 0x8C6649029C86C922ULL, 0x12303BBF5BA601C3ULL, 
            0xBF4FBC1235FCA076ULL, 0x0A49B14325A65704ULL, 0x30527DB0846D8E5CULL, 0xEF9100CCB11A5582ULL, 
            0xC11D0AF875B320F1ULL, 0x16565255547663E6ULL, 0x51FA97DF1BC7B2CAULL, 0x4A468D25D633DCDAULL, 
            0x80E0370F0C5E08FDULL, 0x889AE6BD1661987EULL, 0x47E2F3CF98E507A4ULL, 0xE927A1762F102541ULL, 
            0x40E8F586551690F1ULL, 0xE66F2D62A16F2E05ULL, 0x52D24281AC09648EULL, 0x9523556DE87352E7ULL, 
            0x4AFD18057D669CF8ULL, 0x9A1BA7C6716AA3EBULL, 0xC115D744C0626C57ULL, 0x1886CC5D406A17B5ULL, 
            0xC2ABCA37B5683632ULL, 0x7B87B19370C0C9D2ULL, 0x8D45620D193984BAULL, 0x3C4CB6947162ED4BULL
        }
    },
    {
        {
            0xFD405D19D4C1F357ULL, 0xAC8BC09F26751737ULL, 0x2BBC9DAE85089117ULL, 0x5E9A4A2309C928ADULL, 
            0x864D22E4E9DA6E84ULL, 0x1B0579D161AD24E9ULL, 0x5E11C5941DF2A298ULL, 0x4CEA4347232284B2ULL, 
            0x630A1992E3B81DEDULL, 0xDE2AFAA778AC923BULL, 0x39DA976CF3EA4AEBULL, 0xA701F24448FB3738ULL, 
            0x5D0B8C41CA05DEBAULL, 0x7CAE7A93C181BD30ULL, 0xE1D9912E93267398ULL, 0xE78E0AAAA678E8FFULL, 
            0x5F765BAF896A495BULL, 0xE0A84B8CF64AECC4ULL, 0x089C1F894204F3ACULL, 0x87662C607DE167AEULL, 
            0xAF3D030B57CABD79ULL, 0x8789360DD72275B6ULL, 0x0D56108BB665BF42ULL, 0x10E9F726B8A5E2E2ULL, 
            0x358DE91311A3AE40ULL, 0x5594F129288AE312ULL, 0x26D3694D37018BAFULL, 0xC425E1F4F1C7B946ULL, 
            0xB4978A37FF6DA9A1ULL, 0xAF2C4B21DC92E648ULL, 0x90C29BAAC05F51B3ULL, 0x4CB2594FDAB31A30ULL
        },
        {
            0x4F3E74B0128502C1ULL, 0x2E3D92F417396E4DULL, 0x07F17BC83AF580D1ULL, 0xDEAD35D610887279ULL, 
            0x1284393FFCDE65EEULL, 0x42F1427317B02D72ULL, 0x3934BBFA9B81449EULL, 0x8EE4F1C5925E2E7AULL, 
            0x736B915BCFB04A1FULL, 0x5BCE5FD282C36243ULL, 0x600BE2A33499B496ULL, 0xB218231746CE55BDULL, 
            0xE0D805EE85442D6EULL, 0xBC18C1AA7FE8D9AAULL, 0x6750603393D35B39ULL, 0x8429E5D6CA34D881ULL, 
            0x3533D203D13FC000ULL, 0x1CE22EC6C881A159ULL, 0x6ABD81197242EFE1ULL, 0x469A19CA45A4240EULL, 
            0x57E6E8CE0FDFF287ULL, 0x86DF4B145B443706ULL, 0x8281507649DF30CBULL, 0xA70B50078821D419ULL, 
            0x3E89A313704E4278ULL, 0x309B2C9BDD0089F3ULL, 0xA53A810906FB49E5ULL, 0x74DA7603114002D6ULL, 
            0x2A00F6318E646EAFULL, 0xA76C9CE6DDBAC3BCULL, 0xEE38293BB7AAFAEEULL, 0x70E97E9DEC726684ULL
        },
        {
            0xB7B7FBC55763D9F6ULL, 0xB50831790DA34F20ULL, 0xE48CEBEC56ADF267ULL, 0xC52144F3327EC2C2ULL, 
            0xCE63F3AB6E92B514ULL, 0x5EC853E5A8E0159BULL, 0x07B6A79AE6B30AF2ULL, 0x04045E064056EE7FULL, 
            0x515276F29CDE9441ULL, 0xCB8525D60AD71AA6ULL, 0xC1D104EED6634467ULL, 0x41ADABD18382D6FAULL, 
            0x13384F935235E3CEULL, 0x450908AF50B67147ULL, 0xC6027063E86E90ABULL, 0x4279823FD1D7B531ULL, 
            0x7941A40DED87339EULL, 0x1AABF92FE8767769ULL, 0xCCD4DEDA2422CC60ULL, 0x6506BC6A0446090BULL, 
            0x0021F90A29FAA472ULL, 0x95642496A5C8C246ULL, 0xE10C48BDEE1CF54EULL, 0xB6724DC3F3D4CA75ULL, 
            0xACF30C64C71BD51DULL, 0x8A7BD882D7D5954DULL, 0x53B709E0A7B09F5AULL, 0x273DE1FD331343CEULL, 
            0x01CB6F0C877E656EULL, 0x70DBB155A60839BCULL, 0x81C0F7708392D483ULL, 0x0CFA6091178CAE0CULL
        },
        {
            0x1DFB6F6DD1DA652CULL, 0xA78B48C3B46DD699ULL, 0xD5BB37460E70CD2AULL, 0x2CE43EFB3172E5AEULL, 
            0x7A6EF47C674EB7B9ULL, 0x28680BC65672894CULL, 0x1F6DA83EAD536D3CULL, 0x438A98C0FB033455ULL, 
            0x53663739D2BF97EBULL, 0x7C74B069FB4E38BFULL, 0x534B40087278BF34ULL, 0xC5EB4198FF453401ULL, 
            0x99E1E711D5BF6014ULL, 0x2FB9EDADEF5FADE6ULL, 0xF4C33AC9118C3270ULL, 0x2FF1CE81AB89665AULL, 
            0xF31B418AD3A418E5ULL, 0xF26CE1A3062D597FULL, 0x9F19323E904619E4ULL, 0x57AE1584CEABD6CEULL, 
            0xEB9E16854B62FC26ULL, 0xF78C3A94D5DB325DULL, 0x7B71B25957D4426EULL, 0xA9190A3F91024FAFULL, 
            0xDAE2B12CA076D901ULL, 0x9D7346E83236E670ULL, 0x5837E5FA56AE8093ULL, 0x45F98B5B3CED3E23ULL, 
            0xCDABDF0ACD2FC9A9ULL, 0x7701C79C024B19AEULL, 0xC0A75509F266D1BEULL, 0xD5FBE684CC8A9E45ULL
        },
        {
            0xB8D9634CC71D81E9ULL, 0x391C471FBC513F86ULL, 0xE56C5AD8CFDAC321ULL, 0xB3E1E71EC5E72515ULL, 
            0xF2C4A84B4BFF1D16ULL, 0x9DA8ED98F6ADC7FAULL, 0x07CB10EC4DDB8B5BULL, 0x98D8D1EA3DE36640ULL, 
            0x6BAE232B7F75910AULL, 0x1D2A41E0AC3DBA2FULL, 0x2811737520D66BE1ULL, 0x0BB281D621910C28ULL, 
            0x600C66823B552C66ULL, 0xCBCE8A45C3975DF2ULL, 0x9FA175D731A5F94CULL, 0xA43AE0F4CF777378ULL, 
            0xEF5F85FB599059B2ULL, 0xD318FF2730D18C6DULL, 0xEBBC2A442AC2E0CBULL, 0xA2DB8381B0063BAFULL, 
            0x31A897CA6272DED9ULL, 0x0D7490B223AB5FF5ULL, 0x1E6BACFC6E5FAD4AULL, 0x6EBB339ACB349FC1ULL, 
            0x388A62E46423B79DULL, 0xE36DA91C544E841BULL, 0x98D96FDFD0FD894CULL, 0x13F300F5483E7C2BULL, 
            0xE98AEB340F7C896AULL, 0xEF6716959CFE4796ULL, 0x51B4A581A499C8D7ULL, 0x50486C53D6579A9BULL
        },
        {
            0xB0C32363C083A148ULL, 0x28FA91FEBA2B0490ULL, 0xBDC21AA3D1658E5DULL, 0xC6281AA4CC908645ULL, 
            0xB3C7689D0F5B3C0EULL, 0x13F136AF6363132CULL, 0x1E2FBE2DA40E7713ULL, 0x13697AFFE5C2D976ULL, 
            0x69F7DD4D3753949BULL, 0xA5C6E53BE00D8F0DULL, 0xDB0E0BBB3E8F4CE7ULL, 0xA0B2B577CC2F1373ULL, 
            0xEC5142016C3A05AAULL, 0x3F4D1618A2AAB94FULL, 0x82E907ECCEF1AC19ULL, 0x71446C3C334ADD77ULL, 
            0x4ECE93BC8D9D07F3ULL, 0xAC8A18482B15B0C9ULL, 0xABE5BDD2E1B3B607ULL, 0x007312F5167C0008ULL, 
            0x35CB65028FDB1478ULL, 0x708AC15A45209D6BULL, 0xC765F52C67B654B9ULL, 0x0210F654F09DB21DULL, 
            0xF9BDD8538FF878BBULL, 0xEBFA8CDD62F3ECCDULL, 0x37CADEE4803427FEULL, 0x6647B9432CD67EAEULL, 
            0xCC14B79DFD4B2584ULL, 0x931648FDD0071EC1ULL, 0x8983D6CD19CA7861ULL, 0x15618144CEE81ACDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseHConstants = {
    0x1FACD77009F72570ULL,
    0x0A55AF20D06A7117ULL,
    0x6B273EA0797A6BBEULL,
    0x1FACD77009F72570ULL,
    0x0A55AF20D06A7117ULL,
    0x6B273EA0797A6BBEULL,
    0xC2EC19E952F5FFAEULL,
    0x810CDB510E16BA0EULL,
    0x8F,
    0x5D,
    0x66,
    0x70,
    0x60,
    0x65,
    0xBB,
    0x39
};

