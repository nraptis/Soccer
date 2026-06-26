#include "TwistExpander_Badminton.hpp"
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

TwistExpander_Badminton::TwistExpander_Badminton()
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

void TwistExpander_Badminton::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
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
        aPrevious = 12317998253169973104U;
        aCarry = 14541042913079259594U;
        aWandererA = 18184565062730500766U;
        aWandererB = 10316837767297534792U;
        aWandererC = 17129168825916089133U;
        aWandererD = 12880874660436763735U;
        aWandererE = 13674254777836874672U;
        aWandererF = 10529334740482136001U;
        aWandererG = 16963169089755899127U;
        aWandererH = 17235611562924225480U;
        aWandererI = 10499587789251963541U;
        aWandererJ = 15827183863843314407U;
        aWandererK = 15583352316979434739U;
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
    TwistExpander_Badminton_Arx aArx;
    aArx.KDF_A_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
                 mSnow,
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
    TwistExpander_Badminton_Arx aKDF_A_BArx;
    aKDF_A_BArx.KDF_A_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_Badminton_Arx aKDF_A_CArx;
    aKDF_A_CArx.KDF_A_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_Badminton_Arx aKDF_A_DArx;
    aKDF_A_DArx.KDF_A_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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

void TwistExpander_Badminton::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 12706234282945587509U;
        aCarry = 16346569382280156322U;
        aWandererA = 15930532487913649515U;
        aWandererB = 12683316756731970053U;
        aWandererC = 9948682254538463915U;
        aWandererD = 11482997060858151225U;
        aWandererE = 15325097524052595258U;
        aWandererF = 17035041417099497034U;
        aWandererG = 9815302881523592580U;
        aWandererH = 14938789668282921389U;
        aWandererI = 12219517825410434449U;
        aWandererJ = 17508799013799579435U;
        aWandererK = 12528029516669340783U;
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
    TwistExpander_Badminton_Arx aKDF_B_AArx;
    aKDF_B_AArx.KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_Badminton_Arx aKDF_B_BArx;
    aKDF_B_BArx.KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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
    TwistExpander_Badminton_Arx aKDF_B_CArx;
    aKDF_B_CArx.KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 mSource,
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

void TwistExpander_Badminton::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pSourceInput,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pSourceInput, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr) || (pSourceInput == nullptr)) { return; }
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
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneF (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseA invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneA);
    }
    // KDF_B PhaseB invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneB (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseC invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseD invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseE invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneE (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    }
    // KDF_B PhaseF invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneG);
    }
    // KDF_B PhaseG invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneC);
    }
    // KDF_B PhaseH invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_Badminton_Arx aSeed_AArx;
    aSeed_AArx.Seed_A(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_Badminton_Arx aSeed_BArx;
    aSeed_BArx.Seed_B(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_Badminton_Arx aSeed_CArx;
    aSeed_CArx.Seed_C(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_Badminton_Arx aSeed_DArx;
    aSeed_DArx.Seed_D(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_Badminton_Arx aSeed_EArx;
    aSeed_EArx.Seed_E(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_Badminton_Arx aSeed_FArx;
    aSeed_FArx.Seed_F(pWorkSpace,
                 pNonce,
                 mSource,
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
    TwistExpander_Badminton_Arx aSeed_GArx;
    aSeed_GArx.Seed_G(pWorkSpace,
                 pNonce,
                 mSource,
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
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    }
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Badminton_Arx aGrow_AArx;
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
    TwistExpander_Badminton_Arx aGrow_BArx;
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

void TwistExpander_Badminton::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Badminton::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Badminton_Arx aTwist_AArx;
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
    TwistExpander_Badminton_Arx aTwist_BArx;
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
    TwistExpander_Badminton_Arx aTwist_CArx;
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
    TwistExpander_Badminton_Arx aTwist_DArx;
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
    {
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    }
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
        TwistExpander_Badminton_Arx aGrow_AArx;
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
        TwistExpander_Badminton_Arx aGrow_BArx;
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

void TwistExpander_Badminton::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 2, 3, 0, 2 with offsets 7415U, 4423U, 4394U, 4236U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7415U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4423U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4394U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4236U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 1 with offsets 1360U, 1170U, 2926U, 7234U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1360U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1170U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2926U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7234U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 0 with offsets 3884U, 5530U, 8040U, 944U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3884U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5530U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8040U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 944U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 3 with offsets 5791U, 3775U, 2350U, 6746U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5791U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3775U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2350U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6746U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 with offsets 1632U, 802U, 698U, 813U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1632U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 802U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 698U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 813U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 3, 0 with offsets 43U, 511U, 150U, 516U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 43U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 516U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 0, 2 with offsets 1858U, 188U, 1095U, 993U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 188U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1095U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 1, 0, 2 with offsets 204U, 1314U, 1278U, 837U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 204U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1314U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1278U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 837U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 2032U, 1825U, 1874U, 14U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2032U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1874U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 14U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Badminton::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 2, 3 with offsets 4917U, 4243U, 6600U, 4039U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4917U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4243U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6600U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4039U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 1, 1 with offsets 316U, 5109U, 5097U, 4070U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 316U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5109U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5097U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4070U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 3, 0 with offsets 3293U, 54U, 4480U, 5083U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3293U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 54U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4480U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5083U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 0, 2 with offsets 2506U, 4323U, 5254U, 4885U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2506U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4323U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5254U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4885U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6387U, 7046U, 198U, 1349U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6387U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7046U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 198U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1349U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 3, 2 with offsets 1669U, 1979U, 1290U, 745U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1979U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1290U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 2, 3 with offsets 1830U, 1809U, 1453U, 1991U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1830U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1809U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1453U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1991U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 2, 1 with offsets 1824U, 354U, 1150U, 639U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1824U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 639U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 3, 2 with offsets 371U, 677U, 1370U, 1806U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 371U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 677U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1370U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1806U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 170U, 316U, 1728U, 1107U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 170U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 316U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1728U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1107U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseASalts = {
    {
        {
            0x2984CCA38AB4062AULL, 0x2193450A326B895FULL, 0x724B3E3A06361409ULL, 0x8C47082623C8467EULL, 
            0xF0786A5C81853E1BULL, 0xEF550139F9E73A43ULL, 0x030884736D199A11ULL, 0x4020FC4353407E8DULL, 
            0xC5368224392DCDDFULL, 0x8489CFA724AD1A3CULL, 0xDF9A756AC7F8F618ULL, 0xC6D9A0D0607CC091ULL, 
            0xEEF804D8F779AE75ULL, 0x9ED4DA2B379E174FULL, 0x2C70800EF7064DA3ULL, 0xD2A622AEF0961468ULL, 
            0x2D7396781C9ACAB7ULL, 0xB0FB31F723579F7CULL, 0xA8F61014E16C824EULL, 0x244DA248209B72E0ULL, 
            0x1239D925712ACA81ULL, 0x3C75EDE9277BE278ULL, 0x28E14E48B52283D4ULL, 0xCFEA8AFC27230327ULL, 
            0x5A264F6B806EDA10ULL, 0x36DA82303DB64CBFULL, 0xF59952171A31DF70ULL, 0x5994BD28C3FD0DC2ULL, 
            0x4EA0C2830495D41DULL, 0x4FBA6D817ACA46A9ULL, 0x7F6D07B982E4AE22ULL, 0xE582D7986A7109D4ULL
        },
        {
            0xACF926E2751BA177ULL, 0xC21D7F7C5B78BC79ULL, 0x5BFEC8ABC05DE9A6ULL, 0xE9169336F28FEE8CULL, 
            0x3DD815E0B5F9501AULL, 0x3FDA8A3838DDC585ULL, 0x992B3DD73D59677AULL, 0xB8654797C860CCCBULL, 
            0x16432CED31990C4BULL, 0x4A8D61F01FC540CDULL, 0xA80DC8F0D288A14DULL, 0x8B6558FEBC6F41A1ULL, 
            0xE2A5AD43D354DA3BULL, 0xEA746112F8A35038ULL, 0x1990835C04141D97ULL, 0x286F486F5154C559ULL, 
            0x6960B36E4515806AULL, 0x625C8F53A4769367ULL, 0x3313C2318D2A3B76ULL, 0xA27981DF1FE412B3ULL, 
            0xC17199661DD78F10ULL, 0x9F37D2FBE09F15B3ULL, 0x622834AD516D9072ULL, 0xF859F92ED9B89E36ULL, 
            0x093272C9181F25F5ULL, 0x5B9E541610917DEFULL, 0xFDFA211CC30F396AULL, 0xB2368AA2A871BC62ULL, 
            0xFE8BA7D412DAAF3FULL, 0x1073E742C74BDD32ULL, 0x8E952385180B3369ULL, 0x6E7BD2E7AA3D2DBBULL
        },
        {
            0xF6C7DE27B45248B9ULL, 0x65C077A4CAFC14FEULL, 0x3D50F33BEFFBDEA2ULL, 0xA84EF91FE8B0BA31ULL, 
            0x098562CF3CB105AAULL, 0x48E5D037AB36FA7DULL, 0x7116D636D7CDB41EULL, 0xBE099AEE3211CF7CULL, 
            0xED42EA531164F396ULL, 0x7E578AAF1E0F1E81ULL, 0xB55443C16F8C1AE3ULL, 0xE3CD0B693C78956AULL, 
            0xF34FE0AFD2C784CBULL, 0xCC8BC6546BE9088AULL, 0xE0C9C711D8DF265CULL, 0x470A18189B8423E7ULL, 
            0xB6D06588601B26B7ULL, 0xB6F4059647A32A67ULL, 0xDF7C195E2DC9EE0EULL, 0x088898E1D1705BD1ULL, 
            0xC115B7679D50E6C6ULL, 0x4E244B8D3121A207ULL, 0x1ADE50C5F02CFCC3ULL, 0x400AD7C8D6938EA2ULL, 
            0x07DBB97866BAC617ULL, 0x85E732D95E5BE025ULL, 0x5710989219E0308CULL, 0x26166DA1CAE6B19DULL, 
            0xBD7BAC2EF4C63E84ULL, 0xD803F6555BC40E5DULL, 0x3ED57D306E29D2FCULL, 0xA2F653C3A2DBAC12ULL
        },
        {
            0x2539E024FFA38F07ULL, 0xD7BFB364480130BDULL, 0x1CB8E7A9C6D21846ULL, 0x97B07B4D5CEC03D6ULL, 
            0x573B7F5130CF23E8ULL, 0x2F828CF3C4F53D62ULL, 0x0D26EF767938326EULL, 0x09B78DB696D2332CULL, 
            0xD3C9640046047C03ULL, 0x9F633F25BBE947C8ULL, 0x4F8FE715E8333650ULL, 0x81E5DEAD3E0E5B7EULL, 
            0x6AD00BF471A8EE32ULL, 0x9AA92520BAE51618ULL, 0xECC297F11CB5C5CBULL, 0xD52A7A2D9A21D856ULL, 
            0xF4534E217DC63AD2ULL, 0x25C696900DE84CD8ULL, 0x4B1D076A08015796ULL, 0xC4D150C334D2BD6CULL, 
            0xDDFF509DEA818ACDULL, 0x40645490B33503B0ULL, 0x4037940F7568199BULL, 0x609C9095902FBF6BULL, 
            0xC01CA22BA37270FFULL, 0xEAE0C503D2650A44ULL, 0xFAADCD1E3315683FULL, 0x9391B94963AC63A3ULL, 
            0x519F4175CF63A830ULL, 0xEE170C49A2856C8EULL, 0x327DA23A64A07067ULL, 0xA4BA2CA6BF765AD5ULL
        },
        {
            0x4338A2F53E78653BULL, 0xCFF599D66CB93099ULL, 0x8944D306ADA310B0ULL, 0xB37A8E9497D911F9ULL, 
            0xAAB04528C5BBC649ULL, 0xD648656ACA380F9DULL, 0xC3F6926541818DE8ULL, 0x60E688BFC9560616ULL, 
            0xB4467108E00A2967ULL, 0x4F65B3DE9945338BULL, 0xB3729672220A0358ULL, 0xC7977CF07C0700C2ULL, 
            0x155619D90019E0D1ULL, 0x690145BBFEC2CF50ULL, 0x7F44B643A4E4EF00ULL, 0x728BA18868B67CF1ULL, 
            0x711C638E6806A135ULL, 0x68F28844244E7D7AULL, 0xC362A1CDEB05270CULL, 0xAED14F3A9A60C9C7ULL, 
            0xDBA807260B7C48D1ULL, 0xA2113965C2E5D5B2ULL, 0xD356C55BC5F8BEAEULL, 0x1F1C4EAB8BB437D2ULL, 
            0x9E2904882E2936FFULL, 0x2D5908E8AF801E0EULL, 0x618FFFF016176AD1ULL, 0x2745C837B8731629ULL, 
            0x22080B0BAFF7A47CULL, 0x5FAED1B6EBF156A0ULL, 0x60E0859295C920DEULL, 0xAD223B52943A4E69ULL
        },
        {
            0x0BA2DEEA89B16463ULL, 0xDC9067AB260FA1F5ULL, 0x303D99DA9F3C5720ULL, 0x60D57B110EAC4ABBULL, 
            0x47328AE6EDD3C62BULL, 0xFA5CF51AB5FB80E1ULL, 0xFDAA6E7C28A7D88CULL, 0x7E8311AB2E4C7ED8ULL, 
            0x61E19DDFE32E10EEULL, 0x673B02B54AD9C1C3ULL, 0xD043D95C316CED5AULL, 0xDCA2BFF22A64E976ULL, 
            0xAE77E5D2ED871A74ULL, 0x7AD9AB7AA53319F8ULL, 0x0481025C228E2466ULL, 0xB59F10C8FB07CB15ULL, 
            0x9DA7852B48A2003EULL, 0xC771A1ADC0F21654ULL, 0x5E70864146A2E7C3ULL, 0x4673B98E57D4EC5FULL, 
            0xB00ABEC3B6091F0AULL, 0xB19B7C11E9A528DCULL, 0x8272D27196E9D4D7ULL, 0x6547E71CF83D62D3ULL, 
            0x2D3F7FA374091F2DULL, 0x470EB210D6BDED01ULL, 0x23E868F6FE469CF0ULL, 0x9CEF18CAE7E74E93ULL, 
            0xCC397CCFBE1B501DULL, 0xDCAC50C07D1CF551ULL, 0x9BD242278D7F9D92ULL, 0x3CDA2CA42BA9915DULL
        }
    },
    {
        {
            0x88E89A102C5E8853ULL, 0x8B37EA5BD141552CULL, 0xBB6621FF09CBE7EFULL, 0x591934183B40DC88ULL, 
            0x628456E74F17F042ULL, 0x6756B93E0B52C694ULL, 0xBBFB553DCAFEA960ULL, 0x042AE4BD0782165BULL, 
            0x659B5E128432FF8FULL, 0x639F4E991CAD3F64ULL, 0x15727D2E3117DC66ULL, 0xCC4B3C673320208BULL, 
            0xB90C3C2DCD46180EULL, 0xEA81D02F9802AE61ULL, 0x26876A25DB9C88BFULL, 0xA4A7C280EDCDADF7ULL, 
            0x33446B2F240EF479ULL, 0x33CD93329F792C13ULL, 0xB0E712EB3F59DF47ULL, 0xF04A507CA1C7DD1EULL, 
            0x030D9930B82B69CEULL, 0x2DDCEF7A854BA955ULL, 0xEAA662FECC8C3A11ULL, 0x965A076F204EE5B7ULL, 
            0x17D596CE3A3ABF2DULL, 0xA8B75535F318D301ULL, 0xE1912CD36B243DE0ULL, 0xB7075F0D20712A88ULL, 
            0xF1A6CC3691315B8EULL, 0xB544EEC0AB91087FULL, 0xCF5CD6929EF34F06ULL, 0x9E9CB20CA3D2A842ULL
        },
        {
            0x99EDC17047C4607BULL, 0x027B90A5F8AE152AULL, 0x0B4F02676D2C8BCFULL, 0x8DAE4D10D8930F11ULL, 
            0xC589985E862C23ADULL, 0xE20A1A324214FE1DULL, 0xB930C88D12BE6D5DULL, 0x84BBE008F12D7320ULL, 
            0xA6B6250F7C9C7466ULL, 0x88C8ECB38D3E128EULL, 0xD94FB24662FA0801ULL, 0x8629993D6CEFEAD6ULL, 
            0xD1643E77C541CF49ULL, 0x7B223A3CAB5D0B0AULL, 0x86DDEF6D10ECACFDULL, 0xD040226795B0DC49ULL, 
            0x4DCBF1772AE9D318ULL, 0xA7EECB3A9088C744ULL, 0x340FBEA6ACDE9C21ULL, 0xF8C842861A642C1BULL, 
            0x11FAC62AD578EE17ULL, 0x865E99C1BDFE707CULL, 0x79BBC4FF16EDA123ULL, 0x733294349C8A1C3FULL, 
            0x3D1E24F8543BA14AULL, 0xB431AD9746749320ULL, 0x11A2E0A081D490F4ULL, 0xA7A9F80F95342DCBULL, 
            0x8276B576EA647AEDULL, 0x372684F2DC8CBFC0ULL, 0xB92C9CC15876EE86ULL, 0x67BB12AC9B657279ULL
        },
        {
            0xFB1DE1B9421D170BULL, 0x02F6BA4BA56D91F1ULL, 0x91D90F0982DAFBBAULL, 0xEA34E9CA32278671ULL, 
            0x74596707FF197074ULL, 0xF3663FA520A55492ULL, 0x43AD7797ED8ED5CBULL, 0xFAAA14B51772D33FULL, 
            0x8E272FBC16AF8179ULL, 0x2A48E0374F568AB2ULL, 0x8A4E099062B81572ULL, 0x4B8295EE210A41A6ULL, 
            0x4404F5073C2395CCULL, 0xAFDBD9864E0D6286ULL, 0x68B03048A47B6C3AULL, 0xAB8165CC020E9DFFULL, 
            0x73F860529F240E9DULL, 0x6A09CE9466D8056AULL, 0xDF84C2C13C37C39DULL, 0x59A4ABCD52943B57ULL, 
            0x89309C37FE946D01ULL, 0x69A5CF8EDE1AE660ULL, 0xA2E0490D8682027AULL, 0x48CAE91692F9D6E9ULL, 
            0x349C3922435D34F0ULL, 0x6ED3C139989FDC31ULL, 0x3B1A61F7E59D45B8ULL, 0x2162ABA0F85C7FBCULL, 
            0x02DBC132AA651B12ULL, 0xCF45F6727BC676C5ULL, 0xD54738F359CC7BFCULL, 0x84DD64FD7B684237ULL
        },
        {
            0xAF7AACE692D1CC9CULL, 0x8E89B92B24426E89ULL, 0x1F419B21CD5754ECULL, 0xF408A62D3F646439ULL, 
            0x31C6B78F68C9B8A1ULL, 0x65BF6EAF25EA505BULL, 0xAF79739819735899ULL, 0xC033D5CBA2BC0D3AULL, 
            0x6FA7455290AFCEF0ULL, 0x2BB62C61330191E5ULL, 0x8AC3F3C61BD77C5FULL, 0xC7D421285EC6038BULL, 
            0x11B848FCE84D99B2ULL, 0x5EBEE3C1AA249C80ULL, 0x9067369FAEE55743ULL, 0x2404078455ADDC35ULL, 
            0xFFBBC56060974ED6ULL, 0x938BF685717304C9ULL, 0xFA6ECB73D30CB4BEULL, 0x36FB2FB0271E577DULL, 
            0x272A83E614748A19ULL, 0x257B39A80EEC8A5AULL, 0x43915419A4F66AC2ULL, 0xEBF73447F7EA16D1ULL, 
            0x0B8813844DC7E3C2ULL, 0x1C0A7433346E12A9ULL, 0xDAB0C615EABE40F5ULL, 0x94D9C9D52C082533ULL, 
            0x8F50FDC59689A4F2ULL, 0x748CD4FC6662385FULL, 0x1CCA257CF2E9ABAAULL, 0xCCF1BF49823FBCBEULL
        },
        {
            0x212B43C42F2E3CCDULL, 0x16F02EF1550B71B2ULL, 0x7958ED1D67F783EAULL, 0x16C0CC225A3A78B7ULL, 
            0x015328002E2E0504ULL, 0x312514B3A6F2523BULL, 0x9351D687705B08D6ULL, 0xA3437C9D6447CB38ULL, 
            0xF77566AA50FAE376ULL, 0xB1D227BDE7D65688ULL, 0x90386F19A4104340ULL, 0xA77E1957DD4237B8ULL, 
            0xF3C6FB31D898EBE1ULL, 0xD1307E67D2298F28ULL, 0x612B5C2FD9C4F3CFULL, 0xA6D88528BC9A4750ULL, 
            0x5E41490616216DB1ULL, 0x3C44748F1C66BFA2ULL, 0xC6A3AA096E4F318FULL, 0xA079D5BF49BF3074ULL, 
            0x80F2D73C98003D39ULL, 0xAC061DE5D1DE1E91ULL, 0x9C73460DBEC4810CULL, 0xC2078B86CEBDC7E4ULL, 
            0xD5856BC1E01B0169ULL, 0x1E2019685B7DE446ULL, 0x066FDAF6D201D8B9ULL, 0xCDCC685329B5B728ULL, 
            0xE1E1A829AD5AE2F6ULL, 0x030D7EEF72A1F364ULL, 0x2BDCFBECBD2F9A3BULL, 0x9D915BFA3B6D5842ULL
        },
        {
            0x926BB823A870F374ULL, 0x8778E5050E65B40CULL, 0x6F87254D5C10B834ULL, 0xABDF97628D0C9CECULL, 
            0x8231E3B75EE8D1BAULL, 0x0824027F84140DC8ULL, 0x43638BD9218F1188ULL, 0x841BA1690BE9C536ULL, 
            0x4781FA4328B41B29ULL, 0xEDF7A14819A7A24DULL, 0xD854D31748021A68ULL, 0xCB8BB8780618CF2CULL, 
            0x5FDC77C7685D470BULL, 0x1A2DC4AE3AD1F087ULL, 0xE2BE6F39AFF7AF6CULL, 0x8DDDDCD9FBD793B2ULL, 
            0x5E11DF7BF1B6F5BDULL, 0x50C392D6170E02CDULL, 0xEDE0BCCBDC366E2FULL, 0xB13B717A336675E4ULL, 
            0x06BDA14F3B1206A4ULL, 0x71FCE0E319C579CBULL, 0x92133ED847F6F54CULL, 0xD24373D335FEE785ULL, 
            0xF7D3F16C8F0995DEULL, 0x0B4ADFFB2101C143ULL, 0x4F3727A1BDB34B6BULL, 0xEEDDDD9B79505D80ULL, 
            0x4FEC384722680F12ULL, 0xC10BDA2803A672CFULL, 0x8DEFA76E77D27AB0ULL, 0xFF4EB1C977368B0BULL
        }
    },
    {
        {
            0xE4F8458B45A55DB8ULL, 0x033B50907DB33B19ULL, 0x410EBE923DC63B1FULL, 0xB96A7A00C8140CA3ULL, 
            0x58875EB80BD875EBULL, 0x9120CF3370494C8AULL, 0x247E4E8E0171A0E3ULL, 0x31A295B5C2320215ULL, 
            0x38CE80D799C45B56ULL, 0xB6C0D807AD69DED6ULL, 0x75A401715B42D7A9ULL, 0xACFD1EE9BCD59A29ULL, 
            0x8E6DC07D0B403A17ULL, 0x2BD432D581714C7DULL, 0x1DDDB0852254194EULL, 0xEF21D80CD9A29C2CULL, 
            0x76432FC58C39BD78ULL, 0x62803D53FB10BDA9ULL, 0x0C3F0C9C6D6C1A93ULL, 0x4CC56F57A7A4A3E3ULL, 
            0x515EA38E1A8AC92FULL, 0x7614E85DEB4782D1ULL, 0x81A77B706F3AD5F0ULL, 0x11C78A14EB0397BDULL, 
            0xBCF9ECE95E92C067ULL, 0x80954FECDE922D42ULL, 0x884FBA2B93849E34ULL, 0x4468AE1C5F12761CULL, 
            0x285832DAC5E43F45ULL, 0x6FE7CAA333EA8328ULL, 0x67BF3FE692D141C5ULL, 0x04AA58E8739A88F2ULL
        },
        {
            0x956182006EC69AFAULL, 0x3E7A6C6025AA8D7BULL, 0x454EA74971E8EDE8ULL, 0x260A8F28A15E19DAULL, 
            0x7A6F68697C483CB7ULL, 0x2A4442FFC9F27CC1ULL, 0x7410E388BF767328ULL, 0x3568D7ACCA81AAFCULL, 
            0xC5A84223AD719539ULL, 0x6388CDBBDB869256ULL, 0xDEF9BB5C046B014BULL, 0xD9B886C26B092F79ULL, 
            0xBE1C8420C9AFB95DULL, 0x172D26E464936A4FULL, 0x558854C3896F31DDULL, 0x342FFFB8F7AD7150ULL, 
            0xC6E2ABA06C6DF449ULL, 0xE76FA63139FC38EBULL, 0xA3F81E54EF317BDEULL, 0x82762A3724EA4DDEULL, 
            0x235988BE7546B126ULL, 0x73219E09852413D0ULL, 0x75B027FA03E3D17FULL, 0x7B49D403558A3795ULL, 
            0x419272C4128D5E73ULL, 0x6FD6EDBFC542D789ULL, 0x201C0222D4F8775EULL, 0xAC46D8BE8F69BB64ULL, 
            0xE87E51D91BE58701ULL, 0x65E44FD91AF6C661ULL, 0x8B1C141D1B7AB1C5ULL, 0x2328725A8134BD42ULL
        },
        {
            0x02513752217BF6F1ULL, 0xCCBC93AE387AF476ULL, 0x1BF85CE9D761E78DULL, 0x6BC08E2B717952A5ULL, 
            0x2604AF5112084599ULL, 0xC93F735961414990ULL, 0x81DCE7E0AA23C040ULL, 0x47593D1E220C2302ULL, 
            0x5F5FCE0FA805AE0BULL, 0xC1184B8D2DD82A75ULL, 0x78B09FBB80ACAE0DULL, 0x2175AAF64036825CULL, 
            0x9B12B3D795EDA354ULL, 0xCDF6E1693932C8BFULL, 0x348FD6753F01B41EULL, 0xEF421A01FB7D8F5FULL, 
            0x480CEEED89607C82ULL, 0x10D57C5F3221F4FCULL, 0x47C60D766B22646AULL, 0x74D49FE87796992DULL, 
            0xBDCA6995B9169B14ULL, 0x300500AD769EDB00ULL, 0x9CA3AA9DA11BAFDFULL, 0xAD57BA7D245EC08BULL, 
            0x0F6308FB4335EF88ULL, 0xDF1DE598919DD364ULL, 0x8D692B00AC26851EULL, 0x4F3DD50813AEFB0FULL, 
            0x344AA7B9B91CE485ULL, 0xFA4C6C88E9A02BDEULL, 0xE4AC2F542AC66FE2ULL, 0x3456942F5A0E015BULL
        },
        {
            0xE3E56CC5C10AAFEEULL, 0x8DCB9B7505349A34ULL, 0x56CF411E2D092F9FULL, 0x782E1BBC43A9582DULL, 
            0x4F993DF807447688ULL, 0xCDAD93042FD55721ULL, 0x8ACACA7F1D654D90ULL, 0x945BA76ACBC7312BULL, 
            0x24FFCD8BF2BBB0C0ULL, 0x491292C066103067ULL, 0xFB2A7BEEF5FD9605ULL, 0x844E649462CBAE29ULL, 
            0xCA27020D4DCAA65DULL, 0xF6B78EDB04057325ULL, 0x430325155E043288ULL, 0x305AF482586604CDULL, 
            0x6FED23A81CC34970ULL, 0x53462B5B08B90DACULL, 0x757FC3162CB997A5ULL, 0x3D03CF25EBBAF111ULL, 
            0x31C6451F566F82ABULL, 0xE4CA020450789ACEULL, 0x135B8B96ED5EF1A7ULL, 0x1B1DEFF358696156ULL, 
            0x02D1A64BFAE1BAE3ULL, 0xB5CCCB58417ED18DULL, 0xB27BCA2E7193D168ULL, 0x332C9F2BF8C61350ULL, 
            0xE73539FDD56B89E9ULL, 0xD5279ADD267FB90DULL, 0x6E795D603AD7B2F3ULL, 0x34A96B5334DA9B9FULL
        },
        {
            0xC067D7BBFF6E69D6ULL, 0xCA91F1C9E0D03EC9ULL, 0x178517DB0B1140F1ULL, 0x589CACAADEEDDD71ULL, 
            0xB62C214BD4EB6621ULL, 0xB99CC128D2E36255ULL, 0x2B5D627619A2552DULL, 0x84ED24D97FB407CCULL, 
            0x49834CB1B995FD49ULL, 0x394FCCA695EC67DDULL, 0x94ED25FDCF1580A3ULL, 0xDD13969D634D0A01ULL, 
            0xA43DE24AD64202AAULL, 0x9549952C42B849CEULL, 0x2515AA800B328BB2ULL, 0x8A20E28AFA6EC151ULL, 
            0x7B6FA156F3B70735ULL, 0x430B56502B877E72ULL, 0x96C4384DFEE273C3ULL, 0xE772DB429744F58FULL, 
            0x4FE1802A41AFB716ULL, 0x9C21A40F607DEC50ULL, 0x2F0BD88D90ACC9B7ULL, 0x2280E0DAD50E9FB0ULL, 
            0xDB5B6510DBBCFF5AULL, 0xA182C49F0D2B6754ULL, 0x87ADFE65D56B064CULL, 0x32BDEE3CD02B8703ULL, 
            0x91B0912682146535ULL, 0xCA3391525D47A999ULL, 0xA82CB1C7F0FC7DEBULL, 0xD208FEFAF34C54C6ULL
        },
        {
            0x8DFAC47E427E02E7ULL, 0x5091F47C2BF94FD1ULL, 0x602CD7B6EF6394D6ULL, 0x3215A5AC67B258C6ULL, 
            0xA7399CB0EE198E5AULL, 0xF907C9E0AD3CB5BAULL, 0x7AA87C59E6723C0CULL, 0x9A26F578D52BF605ULL, 
            0x014A692FF09FFF1FULL, 0x895613F1A34E7BDFULL, 0x6D5B190E36CB5179ULL, 0xD8BEBB42F77DDF0FULL, 
            0x25BF360114E4E69CULL, 0x5D9486865FEC9143ULL, 0xAFD493EE748EE4F4ULL, 0xA9667F37D85A8AB0ULL, 
            0x76E7EFC3E4A1524DULL, 0x944273DB8ECCA0B4ULL, 0xDFE549B48360C6BEULL, 0x9F7D7146A9F93A6AULL, 
            0xA2BD81E3623EEC58ULL, 0x69562BA631F86CDEULL, 0x69716829E73B14B2ULL, 0x39E432D898EAC7C9ULL, 
            0xC127516145E4B717ULL, 0xB1FEFF1E10D0F648ULL, 0x986015B8C852C783ULL, 0x1A8FACE8C34EB6D1ULL, 
            0x691C4DBDBAE7270EULL, 0x63BD8E7426745CA2ULL, 0xD571A172AE2A77FFULL, 0xA1910BD1807C3DD3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseAConstants = {
    0xC488956E8D626026ULL,
    0xB42CCBB75D696B1EULL,
    0xFC9BA4AD50A5A44BULL,
    0xC488956E8D626026ULL,
    0xB42CCBB75D696B1EULL,
    0xFC9BA4AD50A5A44BULL,
    0x90A27FACB430A567ULL,
    0x0E3F8DDDDAA59485ULL,
    0xC6,
    0x16,
    0xEE,
    0xBF,
    0x2E,
    0x14,
    0xA9,
    0x92
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseBSalts = {
    {
        {
            0xD15C23B91E74F710ULL, 0x51E6D44FB0B7ADDCULL, 0xBF52B4A4EA96A22CULL, 0x94D27E4C0C03F395ULL, 
            0x45DECB740EBF511EULL, 0xD855E50CA41400EFULL, 0xE65E789B34009501ULL, 0x0A549CDC24386956ULL, 
            0x886BF0B4E6C5664DULL, 0xC78F0878E17CA1F8ULL, 0x3FF047593399CBC0ULL, 0x7FB797754DA49B3BULL, 
            0xDEFBF91F39B028C1ULL, 0x2C79A02176736578ULL, 0x4C2259A25A530B03ULL, 0x571E11C59BC7A098ULL, 
            0x96E3BA56C7EF120EULL, 0xBEDA7D5DCC1B8C43ULL, 0xC7F68C509F9D1E51ULL, 0x48569CBF19F4F82EULL, 
            0x98D3F7542EA5D9CEULL, 0x91547D40284C3C5BULL, 0xAAF359E3815C03A2ULL, 0x01FB1B7FCA7F0B83ULL, 
            0xFBC3E4C167D09673ULL, 0xDF0A11B7B541C558ULL, 0x55CB38772CF3D0EBULL, 0x2E652FE67A99E1ADULL, 
            0xE940847C68431596ULL, 0x3322FAF754996FE5ULL, 0xABE14FCCFC4422CBULL, 0xE58EDACA8BB74EE1ULL
        },
        {
            0xEFC94D67D569CCD3ULL, 0xDBA2AA66127CC800ULL, 0xEAECD1B29D4495A4ULL, 0x81514E21D64E463FULL, 
            0xDC181F519724EC44ULL, 0xFC48FA4AFFAF246CULL, 0x63AB04BF5B5EDB7EULL, 0x44DF08F81F8F8DD8ULL, 
            0xB442279FA87517E2ULL, 0xF4721714BBFB929BULL, 0xD6545A02B3C3981BULL, 0x53B955A68FBA4D4BULL, 
            0x83359D975B498545ULL, 0x3DF7E43DF840BCD2ULL, 0xD80C6BA9605EF078ULL, 0x5BE95BF13F35BAB7ULL, 
            0x2377D55AC76361F7ULL, 0x669E1B267ED7B079ULL, 0x1A8B74733F5AAF02ULL, 0x295E274A468A6673ULL, 
            0x4CF89D5B41DB9024ULL, 0x670595B0056B8104ULL, 0x92964CD0E556F470ULL, 0xE30F74A926B03F7CULL, 
            0xE07D5B2717F55CCBULL, 0xE8A9BB82945847AEULL, 0x5F688A0D35E2C49FULL, 0x53026F3D3D09917FULL, 
            0xD4CECC01962B7716ULL, 0x0B8FCECF9FE316DEULL, 0x3A84F17D8C78B873ULL, 0xE82B24C72DC06FF7ULL
        },
        {
            0x20CAD71EAE3BFB78ULL, 0xE2C278BE265681E4ULL, 0x9AEA186AA1B0F947ULL, 0x12C64EBF36D8A3C8ULL, 
            0xA0D4B0CA6A5F89E8ULL, 0x498799E06C906EBDULL, 0x64C26AFAC8B64ACEULL, 0xF64FB7C6D4AA847BULL, 
            0xAA4E71117930199DULL, 0x95FFEC4FB2867784ULL, 0x2799EB13D160CB48ULL, 0x7835D1EA64E1F5FFULL, 
            0xE337CA4EF3EBAD6DULL, 0x39D8580B2D4FADABULL, 0xE62932955FADF5BAULL, 0xC82B684F22FF31F3ULL, 
            0x2371371DC7CEC738ULL, 0x6A8EA33D13FC7287ULL, 0xC013B49E404656DFULL, 0x3FAEE8A785F5946BULL, 
            0xEA9DBC2FCBD132C5ULL, 0x2787FB2E38AFB5C2ULL, 0x81F2B5C0519AE028ULL, 0x3FBC7FE00F442C45ULL, 
            0x75BA71D141785886ULL, 0x734C3E5E3AC08ECAULL, 0x8AE1D5763723A4F7ULL, 0x8477038DD0D5E952ULL, 
            0xF0561FFC9EFBF1E5ULL, 0xAACFF6132728DE8BULL, 0x71D1CA80761C95D7ULL, 0xFD5F4F5A76ADE750ULL
        },
        {
            0x84B1105CFA62C65DULL, 0x183760B706B9AEA6ULL, 0xCE18DB976F0DDE20ULL, 0x1F386328C154D629ULL, 
            0x3E064EF5AFE2C701ULL, 0xBE4905911665C050ULL, 0x5CF07A2981C94198ULL, 0xF8B71EB8F9B1523BULL, 
            0x36653D8221ADEE62ULL, 0x9839F91B5F7B90FBULL, 0x1FFF23D17401E165ULL, 0x2864CD101E6EAD5AULL, 
            0xA9D33F27AE31621CULL, 0x5B278D6F1B037E46ULL, 0x6DE6078A9B46783BULL, 0x679E0B0F6051198AULL, 
            0x54E306EEE2C94637ULL, 0x0E5D07051B003033ULL, 0x575D745B978E0AE1ULL, 0x1BD1091A3EC54062ULL, 
            0xF3F37E6E15807293ULL, 0xD4952EA44C05B425ULL, 0x5AFDB89855942679ULL, 0xF4D825A48A329EF6ULL, 
            0x6087AF7FD3F15099ULL, 0xADCF43A153CD573AULL, 0x3382C75139F34580ULL, 0x9C4E8D2401611F7AULL, 
            0xEDEA2BE6AE3969A9ULL, 0xDD66736D13CE0A3AULL, 0x6926999301D6AC01ULL, 0x5B9483C878F37E65ULL
        },
        {
            0x9572C900C21A2995ULL, 0x083D733F9C8664BCULL, 0x20C68FDBA7B22BEFULL, 0xD17E23017A70DBD0ULL, 
            0x1DD11F13186231EAULL, 0x857321B7AC8F8EC4ULL, 0x7C4A7056D162D557ULL, 0x5A3FCFDEE1532053ULL, 
            0x48F633E1351EE01AULL, 0xACD24DB1D906CA8AULL, 0x9015E66E5CFE7D37ULL, 0xD676290E36C1A755ULL, 
            0x92A652962B3FAC9BULL, 0x7577AC61E9574817ULL, 0xB2F1E416B00FBB9BULL, 0x2AF2264683FB5603ULL, 
            0x8EB310A0E5CABB05ULL, 0xCB103ED3092AC5F5ULL, 0xBBCEF281146D7378ULL, 0x00324E4FC5FD8879ULL, 
            0x5EECD7BB213202EBULL, 0x3AC4B97C590AEEFDULL, 0x3CE9CF46B6DE1277ULL, 0x1412D568FC08560BULL, 
            0x68270F8E33815B28ULL, 0xE3CE0CDEE10996D9ULL, 0xD889ECB5480F721CULL, 0xD6CE4E374D2FF228ULL, 
            0x67B39AB5DE2EC860ULL, 0xC410458C21381688ULL, 0xF417655FFAD3309AULL, 0xA0FAEB807E4520E7ULL
        },
        {
            0x1179D432D7231468ULL, 0x3DB970C2270F4CF0ULL, 0xAF115ACD6CCBFF42ULL, 0x899F82041CD132ABULL, 
            0xF8F1BDC5FACC1247ULL, 0xA563B3779F4C834BULL, 0x2584E23E9B6693A3ULL, 0x659C218D51C7D235ULL, 
            0xFC959ABD6E6D9D7CULL, 0x8645878072592B64ULL, 0x038F8093223B7AE3ULL, 0x4D7367E220A2BFEAULL, 
            0xD5A7FA3DF62ACDCAULL, 0x0BF2A864E85356DEULL, 0x5084511537833927ULL, 0x99A09BB3B203CE45ULL, 
            0xA54E277FD3F2B420ULL, 0x9B0B29C2CF4A5DBEULL, 0x236B06ACAAD2A243ULL, 0x2CB4DC33A2028F86ULL, 
            0x4350D7DC07E74D99ULL, 0xBE20E939BC9D2606ULL, 0x9EBB96CD0AC2BB22ULL, 0xBE1B6FA61B49650FULL, 
            0xA4C34CC01B8F0850ULL, 0x31F3E2D9E2BD5516ULL, 0x5DBD936FB62A0310ULL, 0x5130945B9EE0BFBFULL, 
            0x5CCF07F03660A1E5ULL, 0x7B9A58738142F7CCULL, 0x88644FBB9E5A8CEFULL, 0x8F3E0E8DACD8D937ULL
        }
    },
    {
        {
            0x9CA71BE2CA712E2BULL, 0xF04346B5FB3F6090ULL, 0x9420064BE896AAD6ULL, 0xA79C0CE58E162567ULL, 
            0x687D278172707197ULL, 0x342D2AD6244EF464ULL, 0xFFA00BDE7C9F7AC5ULL, 0x3927A57D1FB62F6BULL, 
            0xE57FAF7C4C456D0EULL, 0x6D685FB592AA56C2ULL, 0x3DEBA1FF16984E9DULL, 0x7F2D70ED02398E46ULL, 
            0x101B04F9C9797E50ULL, 0x5A0704A8E741F344ULL, 0xA61B293155FA9A7FULL, 0x622C20BD3B5547EDULL, 
            0x14FA868530569126ULL, 0xAAF9F1896D7055F1ULL, 0x558F93D71B1507D9ULL, 0xB62616EF501E7345ULL, 
            0xB2A616B05CEC8B5FULL, 0xA3D0996A7E3BDF1FULL, 0xBC910686E7A54A04ULL, 0x786261C624EE6B64ULL, 
            0x436F7712922CECA3ULL, 0xBE5B8F13F2B5D249ULL, 0x72219495B2C1786FULL, 0x1F51CB88FCBB6FA6ULL, 
            0xB4491AD784877C8FULL, 0xA8E6D12B04C3B3ABULL, 0x0DB95451CCAFEE39ULL, 0xB5C139B816CF9F61ULL
        },
        {
            0xC8BE840D779DA20EULL, 0x5AB9944904B2DEFFULL, 0xFA13A891E02E755BULL, 0xA692EEC7C888504EULL, 
            0x59CA4429195E85E3ULL, 0xA106D4D649C267B7ULL, 0x384963D7209B37C4ULL, 0xE85F55DE596FED38ULL, 
            0x464DC9281E198285ULL, 0x8E663EFC17CC6019ULL, 0x0A3DC5AE9017F0DAULL, 0xD39A93A1CBBC297CULL, 
            0x6D8C758D9072F757ULL, 0x0CC14D5E497BECE6ULL, 0x3432AEDE5EF7B514ULL, 0xC206856EDADD14C2ULL, 
            0x85D0C8BC8F977CD2ULL, 0xA0B69247E89CD8ABULL, 0x3A377A3F750E729EULL, 0x1BD64010027922B8ULL, 
            0x0F68A8737F977E70ULL, 0x24B3F22921593EA7ULL, 0x11DBE4587C4D923EULL, 0x3A0F5DB31969E15EULL, 
            0xBA448A45CCB06E27ULL, 0x4B1441B6CDB14E37ULL, 0x45B7B648F9D43467ULL, 0x1BDD7118AFA8DF4CULL, 
            0xEF6DD27B1FBEEA90ULL, 0x01DE1AE88BC0D9B8ULL, 0x04CC885DFB4F14C4ULL, 0x700917DE54BF05C3ULL
        },
        {
            0xBD9E97DA3A996E10ULL, 0x080B872FABD3B016ULL, 0x09DC5A9AC2D67F2EULL, 0x35121685BDBACE45ULL, 
            0xED35AFDD136E7965ULL, 0xB57443AD862B3AF3ULL, 0xEAA848691CEC04AEULL, 0x3E29E4D6467A9698ULL, 
            0x0BC668F1544BE3EAULL, 0xD43F75E14236263DULL, 0x21393E2400B67786ULL, 0xE239D140D28D4DB6ULL, 
            0x7467607EE3BB8AC4ULL, 0xE825F9B8984F1DAFULL, 0xF15136F2CBAD10D4ULL, 0x03066BB72216E5AFULL, 
            0xC732BE46877B078FULL, 0x6BECF5C6FC46C3CBULL, 0xB56B5D6110793FCFULL, 0xF7300239C59BE986ULL, 
            0x0F7A729247C795C3ULL, 0xD22E3AEFDC245F36ULL, 0x42DA0E2BE0B2C9E0ULL, 0x988AF0994A213B15ULL, 
            0x9F2CC6C12AF51445ULL, 0x5D05421E8232B034ULL, 0x3B17456226AF113EULL, 0xFFC3D45B4E1D179CULL, 
            0x2328721E05E0EFE9ULL, 0x8DD4063F74469D35ULL, 0xE4CC5B2FFD836CF4ULL, 0x61DB376DF721FD74ULL
        },
        {
            0x06AD061F196B107BULL, 0x76172C60B9ABCEF1ULL, 0x50A24E530D255DBCULL, 0x5E9A948D3559DBEDULL, 
            0x51998A8A6ACFB3F1ULL, 0x2310490D761B95F6ULL, 0xF654372BC9D7B40CULL, 0xAECE686C2C8B7627ULL, 
            0xDECB909B23595642ULL, 0x48F725FAC05BDF47ULL, 0x0F6047E8DDB395E5ULL, 0x15FEFE99B5F74AB7ULL, 
            0x95307C0AE2C1C41BULL, 0xE2FF20BA33077097ULL, 0x23A764C1473204F0ULL, 0xC5810B5FCF848C0BULL, 
            0xE73B8F01F27CF3AEULL, 0x1C773BDD26FE2558ULL, 0x0794DABD3C161E13ULL, 0xB43C8CBEFDFFDDB5ULL, 
            0xEB77C2E2EE966A29ULL, 0x12B3C1BF704CEC6EULL, 0xEC647A633FB745E3ULL, 0x74228EBF88C6F455ULL, 
            0x0BB478488DB5AA96ULL, 0x62C5CBD7AFA27B13ULL, 0x59C2841DB9A60359ULL, 0x90F7E2BBAD366C4BULL, 
            0xBED27E9FDE40866CULL, 0x1D464357F22E1FB1ULL, 0xA63290A64FF39EA5ULL, 0x92B3D549AE01FC8DULL
        },
        {
            0xC1559D3B2E716D0BULL, 0x07525833A4EC3281ULL, 0x4C4C9D7E3D4ABA1BULL, 0x31A8577D16A36E8FULL, 
            0xBA3B2E827BD4E938ULL, 0x0E896754441864C7ULL, 0x5B8A4A827022A5F6ULL, 0x270A2338B71D6122ULL, 
            0xC68D1C284FFB9396ULL, 0x5095DAEA34BF19A3ULL, 0x4E7D63B13177A924ULL, 0x014030BB8615663BULL, 
            0xD47DAF9CF1C52B8AULL, 0x6288B1E6457A2F52ULL, 0xA9A8208F860E413FULL, 0x6406AA059B1FFBBFULL, 
            0x26B9DFAE9B2F5254ULL, 0x8ED9D72C157AC42BULL, 0x8951FF9C18DE5D99ULL, 0x5863285E3565062CULL, 
            0x942205EC2505CBA1ULL, 0x2B631B6C14B52524ULL, 0x873DF42973A4FE12ULL, 0xA4067673C5E57C43ULL, 
            0x7BB508D460C039A5ULL, 0x58B538B7009B9C32ULL, 0x4D3826AE67F3ABAAULL, 0x5FE5D26D412090DAULL, 
            0x1F561C553415066BULL, 0x61DC336CEC106468ULL, 0x4E7A2B54C3DFB2F3ULL, 0x525A2AD5664C5955ULL
        },
        {
            0xB34CC5391963B4BCULL, 0x4FB297735CE2DB2DULL, 0x92A295CB14731409ULL, 0x54775347E009041FULL, 
            0x3C7BCDD856051815ULL, 0x0001AAB0FD002620ULL, 0x45D8A44ED8369C16ULL, 0xC04136DC429CF438ULL, 
            0xEE4953EA19685F69ULL, 0x11BF01B623290E64ULL, 0xA21922E5417D2CE9ULL, 0x618CE7279765F8DAULL, 
            0xB4EC07DA273A2493ULL, 0xF31B08821C9ECBCCULL, 0x4C6A7A3E7E7570B9ULL, 0xC542087604F3D8C7ULL, 
            0x5A76DDCFF2A6E2C7ULL, 0x284854224A0027C2ULL, 0x27382A81E72DDEECULL, 0xA3D33C054D93D75CULL, 
            0xD5D61B7BD01D4A69ULL, 0xA62117DEB047F333ULL, 0x4E0E25F02C791CE0ULL, 0xFE853D9D6A9B50A3ULL, 
            0x76EDE20F8191338BULL, 0xFAEA61DBC024D047ULL, 0xF1E77EAF89F7E3C3ULL, 0x1CC41D304D5DFBE2ULL, 
            0xC5B07E393426D33FULL, 0x7077B993FD6E1D76ULL, 0x104D567758681681ULL, 0xE868EB742DD3D2E3ULL
        }
    },
    {
        {
            0xC1611ED7D922CB75ULL, 0x9FDBEBB6AED90B5BULL, 0x764A0C46AEE348A7ULL, 0x32591741DA6A0756ULL, 
            0x5ED57FE19144B27DULL, 0x68656A56E586BBE0ULL, 0x15F7E9614ED78C76ULL, 0x5AA2B097E1259CF9ULL, 
            0x43EF47984F1B9E79ULL, 0x95A376C6698BD110ULL, 0xE0FEF779BD501170ULL, 0x8A151E6CC18EE298ULL, 
            0x46544DDA184A0187ULL, 0x29556C5A51F8DBE0ULL, 0xC103A0F908C1EB4EULL, 0xDE6E55173953A235ULL, 
            0x3B89CAEF239FEA54ULL, 0x12B7D372E5700189ULL, 0xC0C67B35E8755C48ULL, 0x2EF93F71381B5BA1ULL, 
            0x4CF642131E6A87DEULL, 0xEA3686CA8A4761BCULL, 0x897E9467D08E58F8ULL, 0x3BA6579BBE226886ULL, 
            0x9B54779839980B49ULL, 0xBA3B2021FC53C329ULL, 0x83AEEE0FFAB29E85ULL, 0x7201E127C293C59DULL, 
            0xF9E80943F390039CULL, 0xF9E8F4D44FCFE80BULL, 0xFC4566437D2603FEULL, 0xEEB3B342C7EB0DC8ULL
        },
        {
            0xD0F341E61FE94F6CULL, 0x42E099DCA00EB3EBULL, 0xD1238B483496F874ULL, 0x98E97BF56E2A0457ULL, 
            0x7078D0D5B6A6D80DULL, 0x89B9AB31B61AB8D2ULL, 0xB8F9A1E6A0EFDF60ULL, 0x7E98FBED1BD64304ULL, 
            0x2D384B80754BDE86ULL, 0xDFA91C72C6658DD5ULL, 0xB02A040E9DD6C8E5ULL, 0x4CB82615243996CAULL, 
            0x6B44822E750B2E05ULL, 0x9DA44888395DBADAULL, 0x6158CA5C2AC9F024ULL, 0x7C2AE52BE65553FCULL, 
            0x64328CBFC511AD7BULL, 0x42C3F702C24C4A9FULL, 0x9E92EB1157048A48ULL, 0x454BAAC51DC4A92BULL, 
            0x3B4585D2173747DDULL, 0x35E769AB6591D2F4ULL, 0xA002C0F73ADAA414ULL, 0xECA2185537394A0BULL, 
            0xECCCB7966BBFDC45ULL, 0x5FEEE3485CDCCD67ULL, 0x1583E2F5237BC935ULL, 0xC40EB9FE0227EB2AULL, 
            0x0C2A7FD4D342E83CULL, 0x310EB52CB0890895ULL, 0x5C98E1FC50B51D41ULL, 0x61C1760AACB041C4ULL
        },
        {
            0xB7F4E79F5E6FF979ULL, 0x2F83DBBE3600DC72ULL, 0x9E517F24E013F701ULL, 0x4D3E46FDAD9E003CULL, 
            0xE51880B440C7B9D5ULL, 0x5665092AA52D4183ULL, 0x94B58D51A5DBA5D3ULL, 0x10D6D232B29018A7ULL, 
            0xEED7C79039062162ULL, 0x39344F902F35468BULL, 0x5E8336721D9F0810ULL, 0xC0E2A26DDDCA42B2ULL, 
            0x96BB3161F2DA9A9EULL, 0xE1AF213A091A0C3CULL, 0xA84DFC820CC4D0BAULL, 0x139D773DDEEEBFBAULL, 
            0x4533F37793ADC34FULL, 0xECC0B46A6850831FULL, 0xFC09A4283F6E4298ULL, 0xA215ABB02CADD51BULL, 
            0x39AC434DDAEEAB37ULL, 0x3F343B2C8A812F7EULL, 0xDEC13E79D342FF82ULL, 0xEB35FA61847FB06FULL, 
            0x756886B70A2CAF6CULL, 0xE0B78D421FED2972ULL, 0xEE2A377E41636495ULL, 0xCA4B078CD644BAF6ULL, 
            0xC1310A44286AD937ULL, 0x68A66686C8EFB653ULL, 0xB86BE3757E1EBD09ULL, 0xEEF4198A95C99719ULL
        },
        {
            0x7D484AD325A68A7FULL, 0x3E25555EAA1D697AULL, 0x13AE31D79E1B12D5ULL, 0x937FBF8DCF422328ULL, 
            0x82619B0D754F29EAULL, 0xBF9A1BA9F92AEF52ULL, 0x78E4EF3723E64E41ULL, 0x7B314CFC31A480A3ULL, 
            0x00520ABF0B79279CULL, 0xB3B4E374A6ABC6BEULL, 0xD6F66BA3263E3C47ULL, 0x07A1B7FCB61698F3ULL, 
            0xE09772A38BB97A04ULL, 0x31F26AF617851D34ULL, 0x06CE4556EF00503BULL, 0xD9A68BB8B51C5AEAULL, 
            0x6A5B38A47773789DULL, 0x881F29AC5E8DBF38ULL, 0x07C78D99DD77A9ACULL, 0x318DA22AC4874BE7ULL, 
            0x050A9D50B1BA7294ULL, 0x8BC3710C8598AD19ULL, 0x549B60CBC51D055BULL, 0xF7738AE7984F12DBULL, 
            0x9DCBB8AFE4AB0AAEULL, 0xF95EFCCFF8E77B0CULL, 0x4F6D7A58735652D9ULL, 0x2749D530EE5B17ECULL, 
            0x06A4AB418F4B4952ULL, 0x56C113751DEF45D3ULL, 0x0323F89383725459ULL, 0x28C697F7E30975C2ULL
        },
        {
            0x81F8CE55A19DCED7ULL, 0x7825CFE70ADB3EF9ULL, 0x713761B0E8A3C5BEULL, 0xFCEA5FB01E615FBFULL, 
            0x8BFFABA83CF275DCULL, 0x8875E97A04C85924ULL, 0xC5999B65E97E8FCFULL, 0xC7EA743BD232D222ULL, 
            0x641F84E73049B728ULL, 0x0046113838674A41ULL, 0xD107007A02B0EF3FULL, 0xDAA67E65F889F044ULL, 
            0xA3FCAA325D176B34ULL, 0x927D014D21BBB316ULL, 0xA6EB68EAE12990F0ULL, 0xDAD0EF06FAA38476ULL, 
            0xF19C0BD9C1AF99BAULL, 0xD247EB3E9A485FDDULL, 0xAB9BB213EEBCCBBDULL, 0xF8A3E9B88405883FULL, 
            0x55E8E7F7E2C72ECBULL, 0x0F2CFE35166F0CEEULL, 0x7DF3FAA33460C299ULL, 0xEC00E90058AFAB4DULL, 
            0x9C6A59F8064ED951ULL, 0xB122A9F68973C90FULL, 0x5A577AC421597C08ULL, 0xCF7D405372ABAA12ULL, 
            0x1733F47E289E2D0FULL, 0xF0C1B760E83578C9ULL, 0x10C1283FA41C9FA0ULL, 0xC87805CD1AA15657ULL
        },
        {
            0x1803B59E27CAAF37ULL, 0xBF70630651F8C9CCULL, 0x27A2FEBEEB8051ADULL, 0xDAFF335757FBCEB4ULL, 
            0x5FD4135307E1943FULL, 0x62BB58447533E1DBULL, 0xF043BD9752F47F69ULL, 0x95703D1D6C485418ULL, 
            0x9D12E96FD335F4B9ULL, 0x10B50F5BBD341A10ULL, 0x292CE677BE43E4D6ULL, 0x7D1C1E1AFCDA004BULL, 
            0x85B80F480D0481E9ULL, 0x46DA918ABD0CD8BAULL, 0x323B7ED5D955E6BEULL, 0x035C3840308D181BULL, 
            0x7063678E6024B381ULL, 0x0410259B199A2238ULL, 0xE85817BE8A9E8D8CULL, 0xDBF6CEC65E70E26CULL, 
            0xA959EB30258DD655ULL, 0x233DA20AD71DA0BAULL, 0x66B4527303AD3371ULL, 0x1AA70D6164C9A5B7ULL, 
            0xC4A91F0EC842352BULL, 0xC60C3BCB8703AFBFULL, 0xD782D166E469229EULL, 0xF2DB36EC8636E5E4ULL, 
            0x621941DD669F2548ULL, 0xA9069E972A5ED8FBULL, 0x881487CB86BAA1EEULL, 0xF567E4E706143611ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseBConstants = {
    0x38CA793D6521F747ULL,
    0x6E8E8663FA20080DULL,
    0xE8218197D459E0F7ULL,
    0x38CA793D6521F747ULL,
    0x6E8E8663FA20080DULL,
    0xE8218197D459E0F7ULL,
    0xFB767C991639725FULL,
    0x4D9C13725ADC55EDULL,
    0x5F,
    0xC6,
    0x92,
    0x6E,
    0x52,
    0x34,
    0xEE,
    0xF4
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseCSalts = {
    {
        {
            0xEA5DB7B039F4FF94ULL, 0x8CD239E3C7CFD05EULL, 0x9779C27E19FF11C8ULL, 0x1FB0A9E55B962DEBULL, 
            0xDA2F1E951B60F33BULL, 0x047B97686A113CC2ULL, 0xA6BA00F3063FAE72ULL, 0x27ECAA481832244AULL, 
            0x2287EFD5787DD35AULL, 0x489A1A341A5BDB0EULL, 0xA4533FE8715A8608ULL, 0xE355244A16A31EA5ULL, 
            0x1F8B583BD09F7C73ULL, 0xE7FA5C8C320B45F0ULL, 0xC3A31CBEDABC003FULL, 0xAC9006A0231A2EE4ULL, 
            0x211E1315AB4C09ADULL, 0x4166F33A0BAB5550ULL, 0x3ACDC9EA35F51F02ULL, 0xA249B2853499A105ULL, 
            0xCFD05FC7F4928CF0ULL, 0x351519F9FFF8DB7DULL, 0x4F262E068D026310ULL, 0xE99B23E636085247ULL, 
            0xA49B1F5C0F4E2B94ULL, 0x157A1956C0ECAE4DULL, 0xD77795A1C49DDAA6ULL, 0x2FA3549E95E49434ULL, 
            0x44B34845141A17DEULL, 0x93B089244BF745C3ULL, 0x692A7F94360A7391ULL, 0xF7CB6249062AEA8BULL
        },
        {
            0xCFB4247B74599A94ULL, 0x2B4F5B7ACDFB9E06ULL, 0x460391E3539CD79AULL, 0x43B4183540DA5E2DULL, 
            0xE28F2574CD774F44ULL, 0xD66FA1B1249591F3ULL, 0x448EE86CC9165DC7ULL, 0x2CC4AAF5D632095DULL, 
            0x4CCE8B436928FE0FULL, 0x97BD75A624633DBBULL, 0x69355471260EA119ULL, 0x4C3AC216EC4D3EF3ULL, 
            0xD26908E2A32C0F6CULL, 0x3E388E4473B6F374ULL, 0xBF254F85E8FF5484ULL, 0x5B45C4ABDC7E53E8ULL, 
            0x616B8A0CD12B1C82ULL, 0x35E0A7162E37D0CFULL, 0x5E20E8D1881C1253ULL, 0x723026F0021B9C90ULL, 
            0x8C288A9D0106AE4EULL, 0x63E905ABAF30FD28ULL, 0xD9A8CC4021432857ULL, 0xDB6CC7FB11AD9C51ULL, 
            0xF908C36A7B40FCD5ULL, 0x8F6AA30603045A3BULL, 0x9417960A669C61ADULL, 0x2F041472B4534E8DULL, 
            0x29C507027AF62C22ULL, 0xDE37E3E84A1CA42DULL, 0xF29822EDDBAFD4F4ULL, 0xE649C383ED5C606AULL
        },
        {
            0xBE5AC07152C73E95ULL, 0xE4BDB7A33A6748C1ULL, 0x0203101AD099D79CULL, 0x375D645A6226245CULL, 
            0x9596157F80D3979FULL, 0xBA6BDF355CA4BAA3ULL, 0xB7E46F54B256A125ULL, 0x12572C9352294B29ULL, 
            0x2BC6289B94A27E07ULL, 0xCC32D14A49B6453AULL, 0x5C8FC35212601970ULL, 0xCB639E6D4DD9B7A4ULL, 
            0x388E4298637336A5ULL, 0x87EDCFBCFC8015CFULL, 0xDF507422CCD5B347ULL, 0x52527B0F7D5D88EEULL, 
            0x129ADC2E4B6A1D5EULL, 0x245183F5B6B63FEFULL, 0x2E5D5EF0683FA1F1ULL, 0xB3CFB974BE554384ULL, 
            0x505D78DDA691DDF3ULL, 0xDE44A9B1A8386FB2ULL, 0x1F86A53A7D51541EULL, 0x90788EA90A14DC04ULL, 
            0x1C9C94B7884887D2ULL, 0x4B661FE99A6D5BBCULL, 0x0F4E2641A5F46F57ULL, 0x26CAEEE480A67F5EULL, 
            0x67C5690FF178AD57ULL, 0xA74D74BE0CE4FFEDULL, 0xF606E036238988E7ULL, 0xE7A62BF6B0C1253BULL
        },
        {
            0x85AFA12301F4849DULL, 0x02143AE3F56A034BULL, 0x7834CECBD6C63297ULL, 0xE5DC8EACCC261E5BULL, 
            0x5808BB7302807142ULL, 0x72524C4143B9BA18ULL, 0xD4A3442BAE2EEC10ULL, 0xF1608CF3E7E1728EULL, 
            0xC693A883C90BB7A3ULL, 0x6E2C1669CE47667AULL, 0xB993B55066F269DAULL, 0x0BD8A9DC190F1B70ULL, 
            0x07F60DB04AA40E33ULL, 0x54AB09BD7B705B9FULL, 0xA32B40EA5C41E500ULL, 0xF93E06C4B375E50FULL, 
            0x3A9909CD1223175BULL, 0x1EFE4D2EF5A3A2B8ULL, 0x9D717C2753E99777ULL, 0x515B7B60DE8327A1ULL, 
            0x5802E90ECCB607A9ULL, 0x577A28119224A53CULL, 0xFFB3CB4DB6C8755FULL, 0xADE8452FCDA1CC8DULL, 
            0xFCB63D2135CF62E5ULL, 0xB943C5C6C4BEEE9DULL, 0x7D51F1F6357B6FDBULL, 0x0F5B4465036C5003ULL, 
            0x44F3D0820FC8BF23ULL, 0x9C459D2EA14B9926ULL, 0x952C4C5381BED469ULL, 0x47486F70793DFE72ULL
        },
        {
            0xFA5F34C9EA0DB9CFULL, 0xDE36D8FD088B08A3ULL, 0xF47D72B923CD0C73ULL, 0x53C1EDD127614E21ULL, 
            0x0E04A4EE19F1B410ULL, 0xDB10492DA3EC19D3ULL, 0xE6AB8F71B31EA65DULL, 0x1A41607EE2FB2FB3ULL, 
            0xA7BB3FE47BA228BDULL, 0x0FAA800F44F7CD85ULL, 0xED9CEEEE73B56585ULL, 0x5C77C6E3052FA75FULL, 
            0x69066A41B294E593ULL, 0xBB2EE2D01933CBD7ULL, 0x56ED1DB09C9F1BB0ULL, 0x1171EAD4396AA78BULL, 
            0xC1547E255FAB7ACDULL, 0x15F80DC27550C16AULL, 0xD8F764E84C20025AULL, 0x2A84388C0E257A67ULL, 
            0xBF7C77B283ABD5EAULL, 0x5611D943C1ED9885ULL, 0xFB2A47B139CC462FULL, 0x468BDC3CD1137C31ULL, 
            0x6D0BFE24B1985513ULL, 0x54114BC631AB924FULL, 0x3247F2D08D08B4BAULL, 0x9418110411D84BF7ULL, 
            0x788FFEEE68483DE9ULL, 0x8BA0BC9CE3CB88E4ULL, 0xDCA7D978818EB4E1ULL, 0xC11BAEFE9FBBE677ULL
        },
        {
            0x94140EA485C9B6EEULL, 0x420770335C3D18F7ULL, 0xD170386A7274EDC1ULL, 0xA4998D8591F0CF5AULL, 
            0x7CA63515088EF1B6ULL, 0xA5A17F9A7BC4030CULL, 0x902BABCF20F9AE40ULL, 0xEE79AA96DA994762ULL, 
            0x03B7C3C06D5EA897ULL, 0x51A905A4A450B6FFULL, 0xF400347DDFD91B98ULL, 0xD1C58674D15442F2ULL, 
            0x68899406636BFC7FULL, 0xAF9D9DF2C8D30938ULL, 0xFCAEBEF1D17F9756ULL, 0xA5434503871D6366ULL, 
            0x816D29008268AF02ULL, 0x02DF4FD1D56F1E47ULL, 0x58DF5BE4C835AFE0ULL, 0xE77FF3237F07DFF5ULL, 
            0xCF9A74790B9EB8F9ULL, 0x72D90F38E1BEC5CAULL, 0x6960C6BFFF00E9E4ULL, 0xDE29338A85200012ULL, 
            0xEFEB68DD5689A5F1ULL, 0x5AA950F73A916A54ULL, 0x15CEA1B0D708BFDFULL, 0x0AA320C9C25E8141ULL, 
            0xF31526756F54DCB4ULL, 0x9259DCA8FE20CAF0ULL, 0x32DDA370EA36042DULL, 0xD4F7A393B348CBDFULL
        }
    },
    {
        {
            0x6BF927F0472329C3ULL, 0x747D4E409ED48A49ULL, 0x886097E5C8DD253EULL, 0xF2E08DCA419E844CULL, 
            0x0400DE1E12AD844DULL, 0xFF4BEA94141B0C85ULL, 0x5210D3B7C13E25ABULL, 0xC1DEA99B9DFA2CA0ULL, 
            0xE198CC8DE2BED255ULL, 0xBEE2D291C84D7F5FULL, 0xB85ECEF710BFB03AULL, 0x0696CE2F89517D60ULL, 
            0x0AD13E7E333B7305ULL, 0x737F5CFB9A335ED3ULL, 0xF60BAA37872BDADBULL, 0xB27C18903891C41BULL, 
            0xC00A71C04EA37365ULL, 0xE5A45A635A1F9AF9ULL, 0x648A8CBE5078A82FULL, 0x686EF0A7D2F7156BULL, 
            0x9E3B5EE0460F6A7CULL, 0x4C8BED369B6CF88FULL, 0x1AAD92ECB3DBFADEULL, 0xCA443A75427A6BE9ULL, 
            0xD52157DCC1C04055ULL, 0x8D3305F26ED30402ULL, 0x757411A3401F6CEDULL, 0xF772B1C378E2DCE6ULL, 
            0xF55B23C1E6099746ULL, 0x7501C23A54761D7FULL, 0xFF5B306C80F286E4ULL, 0x1311970469FBE024ULL
        },
        {
            0xD5FFEC3BB96A4BB4ULL, 0xE02435546A0C1751ULL, 0x0EE72E630D73D2F5ULL, 0x43602ACD147E3C86ULL, 
            0x21FD6702D7721F25ULL, 0xF1FDE766505CB38BULL, 0x9A2B65721F243D20ULL, 0xC3353FA8A8594447ULL, 
            0x794DE0CF827712CFULL, 0xC267829D82312D16ULL, 0x3CB91386DDCEC922ULL, 0x6EDF85725D835C4FULL, 
            0xA99A83340F5D864CULL, 0xB4F41EA9888CF469ULL, 0xA6D90BD87E1EA9C9ULL, 0x4B4C3E3125951784ULL, 
            0x886D01665DFC3B1EULL, 0x2F835EA2CAFFDAAAULL, 0xAE0B098974480FEDULL, 0x4AC5EC076DA3D8DEULL, 
            0x556CB583E1351449ULL, 0xD079484B4A7D5B1FULL, 0x29D712E3ACCEF35EULL, 0xE86FE4B0F32529F9ULL, 
            0x1873EDA9DBB09961ULL, 0x480800C87ED366CDULL, 0x937A46663A6C556DULL, 0xC007DC6EA90F82CFULL, 
            0x0919F26C9D34A63BULL, 0x1C0ECC60C2387279ULL, 0xAD9085465682959BULL, 0x8385A1175DDCC6AAULL
        },
        {
            0x06532E916BF3E689ULL, 0xD7789B995CEE96D8ULL, 0xF3AABDB1E969E017ULL, 0x51E0B3F39DEDA137ULL, 
            0x0000F4BC96538FF5ULL, 0xA1413A5DBDF2426EULL, 0xC967671E8D7D31AFULL, 0x9C8E02B955BB6D12ULL, 
            0x0CE50FB13AD175EBULL, 0xEE93EB41CC0F2335ULL, 0x865B33B950E105B2ULL, 0xA51E6AFF08614725ULL, 
            0x627290E1D2BC9BC4ULL, 0x4ACC0B1327CC3CFCULL, 0xE7B54C55B31ED381ULL, 0x73CF5172CACE9458ULL, 
            0xA80E7125389169A7ULL, 0x7A61DE59C81B75F8ULL, 0xA51AC4CDD2195B4FULL, 0xBC2115A55AA13673ULL, 
            0x55F559255828B44DULL, 0x53B0B8AF669C344DULL, 0x3490606AD8AA3CD5ULL, 0xDDC83264E5B4D16DULL, 
            0xB6EF807A8D6FB252ULL, 0xC4EFDFFCFB48BD7CULL, 0x29855C068A2F33A5ULL, 0x130AEA3FACE35169ULL, 
            0x2D01E9C80C521F92ULL, 0xB89E7868C2A6BDEDULL, 0x80C2CEAC75858252ULL, 0x2D0CEDCE8FFBF54EULL
        },
        {
            0xAE33AA03AAED64BBULL, 0x76E0E47ECE8C0FE8ULL, 0x7A9DB5CB4D05D90DULL, 0xC05C95CD8AE4465BULL, 
            0x1245113A24E5A339ULL, 0x6EE269C3037E050EULL, 0x937A46634C708F42ULL, 0x89D0D8F94ECA3278ULL, 
            0xB649DE48CB49D0B5ULL, 0x2A656EE265DBC9F4ULL, 0xBE495B6A8746E2DFULL, 0x19C6ADC3A6F62E62ULL, 
            0x5B7661E27B8AAE25ULL, 0x46D6D12EE88D3EBFULL, 0x07B36E77F038CA11ULL, 0x82E655163912887EULL, 
            0x408D8A51F07C1E36ULL, 0x21CCD647950A3B8DULL, 0x2805DE3A8B0F17A9ULL, 0xD7E9FF2DEF35C4D8ULL, 
            0x49EFC9D7073AD148ULL, 0xD3E5A60E352A8E7AULL, 0x6B89C94723B8238AULL, 0x06B1DD6380423973ULL, 
            0x829CCFACA7B3C26AULL, 0x451BBD1B584B8881ULL, 0x873D3F62E036F182ULL, 0x34A15D892DD8E53CULL, 
            0x2298153849F67C6DULL, 0xB34CDACD213E0FC1ULL, 0xAAF27D762E877C54ULL, 0xDD8ADACA95BCA6ACULL
        },
        {
            0x88210A06AE81AA6BULL, 0xA74C166EC0558F0FULL, 0xC8C8003DCCE8E4B1ULL, 0x84C3694ECA215D8AULL, 
            0xD865E897E5C3122BULL, 0xDBECD36DEB2EF5A6ULL, 0x5E75DAEC3A6A5FD0ULL, 0x8C654DCBBF6213EFULL, 
            0x8E9BA07DD8AB8F77ULL, 0xDEF567B04FEDC4D7ULL, 0x046DEE6592D87AECULL, 0xB300F9514AB6EFB0ULL, 
            0x4B884977079DE2B5ULL, 0x3E198CA40469AAB2ULL, 0x4E3A88823858E907ULL, 0x007D756819C779FAULL, 
            0x29B07B7872632A94ULL, 0xD88B48F7BA7D7EF1ULL, 0x59A10C35B8CEC4B3ULL, 0x6A95960A7814C835ULL, 
            0x24D59D2FAABF48FDULL, 0x358333071E09DB15ULL, 0x75E98EAEC6C20D4DULL, 0x108C90EE1A503D86ULL, 
            0xCA8ECBE4E49752D4ULL, 0x7075231AC4E28FDCULL, 0x4B0E5065072520A3ULL, 0x976BA1DF58D3E348ULL, 
            0xA9435F43DA74AC6FULL, 0x2459EBD41E9D595DULL, 0xCCA5BF08AFD6B71DULL, 0xF70E3A951DCF6DB6ULL
        },
        {
            0xEE7E8E93E68C5A3FULL, 0x9B77C2D1AED490EEULL, 0x8D89F78E895B9AACULL, 0xFFBCA736B2FA10A5ULL, 
            0x2356A6A49643673FULL, 0xB0316C36C9880E64ULL, 0x171B12C036641953ULL, 0x746EB4232ECC37A7ULL, 
            0x909324D33BD98E8DULL, 0x9D00121F265CF3F2ULL, 0x90FF5918A973EDF5ULL, 0x64804B64EEA4707AULL, 
            0xD751C85DEE6CD523ULL, 0x51DC62B88B9A6DECULL, 0xE8F3566A492DB6D8ULL, 0x000E8517339FDA23ULL, 
            0x9825B719B88CE29BULL, 0x4AC98E2F907C3DD4ULL, 0x75018F380AD03EE9ULL, 0xDF8F7FE9B0CC475DULL, 
            0x65B89E5C1D8439F4ULL, 0x36C2D8AFC482B0EEULL, 0x858406B94364D295ULL, 0x7C83C66E1002A9FAULL, 
            0x97276EDEE7C28DDCULL, 0x05CD91D5316572C1ULL, 0x6E79EA9B04B3AA99ULL, 0x4234CB631BF81D13ULL, 
            0xC2E010C6E2D398AFULL, 0xF6BCAC0D69D4A740ULL, 0xD6A7AE1263EB05DBULL, 0x4367446C5313A7D2ULL
        }
    },
    {
        {
            0xFA9EFFB10A20DC87ULL, 0x22FB13A8D32F8EB2ULL, 0x7B04A96DDBD27214ULL, 0x0AD323C1F25A8D08ULL, 
            0x2E27EEC4A6B791A6ULL, 0x0CA0A45C664272E0ULL, 0xCB8B1C01DF43C5B1ULL, 0x2EE175237BF904ACULL, 
            0x637E4298CFF488FBULL, 0xE9E752D9ABE62226ULL, 0xEB579F64535B6F52ULL, 0x8CE557CB0A6FA922ULL, 
            0x8C058A29C28B0A2BULL, 0x90314E958CFC2EB9ULL, 0x308C42EDF9F80EF6ULL, 0x64AB6740965EDAA3ULL, 
            0x540EE1C6C8F2531CULL, 0x3D4EC2B0CF2B3A36ULL, 0x421051A3CF9A1EF1ULL, 0x754DB0A5F9464870ULL, 
            0xED3378721C4FA863ULL, 0x3FE4B34E72E6B55DULL, 0x358B46CEE3666A34ULL, 0xB65D2D390E26A7B1ULL, 
            0x175CE239FAC852A9ULL, 0x92462B174AAF6756ULL, 0x2A39D14BB3BBD9CAULL, 0x16B0205AF05390D5ULL, 
            0x193639072B7748D6ULL, 0x5D4B359F5FE78BC7ULL, 0xC6148DB3091935F8ULL, 0x2B4C1738DE7003DDULL
        },
        {
            0x3DF8D70456A08CD0ULL, 0x48AAE6FA5567E3EFULL, 0x6468045A76C2C309ULL, 0xCFB33B85221D9B0DULL, 
            0x4957857AB5B4778FULL, 0x898836696A98083AULL, 0xDC24876F9D1A3A50ULL, 0x73A548473AD3861AULL, 
            0xAA3D1C111C8E70D0ULL, 0x7C107504B96E9B32ULL, 0xAAE9BE7C50EA6209ULL, 0xA9945BB241D80506ULL, 
            0x62BC14379278C5C3ULL, 0x0D67D9052956191CULL, 0x128AEC56655290B0ULL, 0x8448B38594E295F5ULL, 
            0xE1824F499899A7C2ULL, 0xB5E1E93A47F7DB6BULL, 0xD23AEB7A23E41BD9ULL, 0x940A875F948E66C7ULL, 
            0xA7272F3A9CD6538FULL, 0x5B9E8D6EB88D6216ULL, 0x15F1E09494A0BC03ULL, 0x2A4F6F0B25D34674ULL, 
            0x635505C8E29DE7E8ULL, 0x1388510C592C4850ULL, 0x28A88179912E81C0ULL, 0xF8B6CBB48DAD7750ULL, 
            0x1E6152A53F132D5FULL, 0x175D84608A7FEC0BULL, 0xC6D100C6E9808124ULL, 0xC13A4C96AAEAA014ULL
        },
        {
            0xE1469D8BF6F33B8AULL, 0x2742CC4B9C0208C7ULL, 0x7DD859F941B55950ULL, 0x458C652DF4BD8F78ULL, 
            0xEC78D4F51CF70552ULL, 0xF1C03C6E819039D6ULL, 0x058BCC6416327885ULL, 0x4B9B9B104AD47BBFULL, 
            0x21D06EE68902DA94ULL, 0x373F4E4068E99BAAULL, 0x1E5CB38F4AF948A4ULL, 0xB20C19D596C02A46ULL, 
            0x2993AA0D3223D662ULL, 0xB3480661A6FB1C4FULL, 0x694B3F58746D6C81ULL, 0x60177090ED14A61FULL, 
            0x5E2B0A0D8BFF9BD8ULL, 0xA55B3611D394E721ULL, 0x4C8FF3E1E2D0C1BCULL, 0x8AA8C3F9A8656078ULL, 
            0x96EB452AFF99DA04ULL, 0x596BDB99168C10C5ULL, 0xBF4C5543331DEFE1ULL, 0xA7644EE1CD22D313ULL, 
            0xE2DA1FD555CF2FF5ULL, 0x3CA15F5448C54588ULL, 0xEDB127B6EAAA1E7AULL, 0x4B867411EC538EE6ULL, 
            0xF26FAE775F83550CULL, 0xE3A4A0F207780354ULL, 0xCA8459F020B40DD8ULL, 0x77A8463BA44FCC83ULL
        },
        {
            0xD30FFE83A9E636ACULL, 0xEC790EB3E8CC79D8ULL, 0x561D26E7ECA864D4ULL, 0xE3B669EF259A3FC1ULL, 
            0x6922195A20FDDA83ULL, 0x373000157E926D65ULL, 0xF21A96754456FA5BULL, 0x9AB1BCD9BC6CE81EULL, 
            0xB50E46D1226A4871ULL, 0x54742AE489C2BC10ULL, 0xB3436532504889C9ULL, 0xCC62444D20A340AEULL, 
            0x5EBF1650C97614ADULL, 0x633A6CF4BC72074CULL, 0x7C319E4BC859E4E8ULL, 0xCAB8E1A094108A05ULL, 
            0x1C870C32682973A8ULL, 0x7E1AFA0421E12A30ULL, 0xE94B6AFA1F6BE08EULL, 0xB0879B62D6BA3D4BULL, 
            0xF5EE8317C161025FULL, 0x93441B817BBC1223ULL, 0x1849E69F8C4F20BBULL, 0xB85D37A110B04E62ULL, 
            0x7C9C273982A08635ULL, 0xB97A250513901DC8ULL, 0x04F6DDEB081A1C4DULL, 0xA200746342B6A6A6ULL, 
            0x1307CDA4DE27A92FULL, 0x93FD04C66EFBB8A8ULL, 0x207127BE52BD50E9ULL, 0x252F44EB0C377075ULL
        },
        {
            0x2A56724AE3F52C6BULL, 0x2DA1ED10A9FB1FC5ULL, 0x3A4EA75277F9EAC1ULL, 0x1606232B4E08D602ULL, 
            0xC00DEA42A5933A1BULL, 0x174CCCAE20FF4B0CULL, 0x564C57ED276A4B3CULL, 0xFCD74121EA9A395DULL, 
            0xD096365716E7B9D8ULL, 0x82A19B94E7D7EF5BULL, 0x572A3991C7A7736DULL, 0xB4E1DA1D254A74FBULL, 
            0xA49093BD3AF38A07ULL, 0xC3F3ED3E79583B01ULL, 0x24B8CE37C0C91357ULL, 0x62422AAA7226E1A1ULL, 
            0x63B98643BB567F16ULL, 0xA4189E2AFB2B73E3ULL, 0xB81F9EFD7B922600ULL, 0xD96980205296698DULL, 
            0xE12E167D2AE25EBFULL, 0x982BF48F00DF954CULL, 0x33B5EEAB90DEF91EULL, 0xFEFA6D7CF7CFF739ULL, 
            0xB3C50CFDA6AB519CULL, 0x2E6F676EC5AE0003ULL, 0x53CCAC4F5502E126ULL, 0x331FA4DB7DD163BBULL, 
            0xE5359CF0D5D05551ULL, 0x95562C70FBF8C39EULL, 0x80483023B955078DULL, 0x204C652CD675C0C3ULL
        },
        {
            0x732ACE4CE5B2B0DAULL, 0x89A83B900AD266B0ULL, 0x3DBC29F06E829699ULL, 0xF66F1362EE000B7AULL, 
            0x7A06C4702913A43CULL, 0xA34B511E4D38C39AULL, 0xDAAE003C7EC41EC2ULL, 0x19436786EAC44818ULL, 
            0x45BA59A02A3EDE5BULL, 0x1A5866C2ADCD348FULL, 0x036A50A5ACC0C4C3ULL, 0x3E3ED7F9611A20FCULL, 
            0x36162AC1894CD74AULL, 0x111BE2CC89D9A670ULL, 0x32449803222C309DULL, 0xCC36C55200D488E7ULL, 
            0xA0CF589D48AC9AB7ULL, 0xEE299A2CF5B26C2EULL, 0x19DAEB240F10E47BULL, 0x0B44A3AA568478EFULL, 
            0xBAE149A02BCC3D8EULL, 0x2B09AA89567486AAULL, 0x6C70AD1D4253B5FFULL, 0x157E2F36E1F7A8DFULL, 
            0xBB11796CB67117B6ULL, 0x37244FAABC76A4E9ULL, 0x39E795FBEE66F457ULL, 0x36DA4F2E4F27CED3ULL, 
            0x3A901349475A7225ULL, 0x93F723F4C400D374ULL, 0xE3A123776471C8DCULL, 0xE182AAFDADE95CDAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseCConstants = {
    0x8EE7DFA912F80E82ULL,
    0x9E78EE82CEEA1CC2ULL,
    0x2ACC49E11DA52965ULL,
    0x8EE7DFA912F80E82ULL,
    0x9E78EE82CEEA1CC2ULL,
    0x2ACC49E11DA52965ULL,
    0x816E22D1111A8C85ULL,
    0x2406EAC57B2EC1FFULL,
    0x03,
    0xCE,
    0x96,
    0x87,
    0xF2,
    0xF7,
    0x6D,
    0xEA
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseDSalts = {
    {
        {
            0x6036B7662A679156ULL, 0xD432673F905F2F53ULL, 0x314BFB17A2B1E7E0ULL, 0x46C2B07FE69CEB55ULL, 
            0x7C31A630F11BFCBDULL, 0xFE9F16C6155B3EADULL, 0x93EC378C69D62AEAULL, 0x3E66217D564324ADULL, 
            0x46595B83199BD2DDULL, 0x53A1AEACD9F1D936ULL, 0x1227DF546283E137ULL, 0xEC1A4BC286BE6A77ULL, 
            0x21AA29D71FC6B290ULL, 0x66CAD6161D2E9E77ULL, 0x09A4A50DA93658ADULL, 0x48F045B0704FD857ULL, 
            0x4D50B166486C274CULL, 0x2A854961E0263AEAULL, 0xDCF74B2375AAEA60ULL, 0x59D695D9B3D26C28ULL, 
            0x142BC57A573FC6F4ULL, 0x31E8285C2475AD50ULL, 0x4EE0FF9866B3525FULL, 0xDD22AA5C40CE09F8ULL, 
            0x1D9A2DDD55E0CCB5ULL, 0xAEB1AC1F205922BDULL, 0x3254E8F397CBD296ULL, 0xF463E2CDF5A74B39ULL, 
            0x6B2384CEA106AA49ULL, 0x5400A1F7866C1ECBULL, 0x439F4B7CD397B65FULL, 0x3141FBD0739B7032ULL
        },
        {
            0x159C256B7A5A6C8DULL, 0x2DD8963C2C7575A9ULL, 0x942855A29EE9568FULL, 0x440536DDFED26C5CULL, 
            0xB1877380C592D472ULL, 0xF69F4A2CBD0ADB42ULL, 0xF5ADB51F918165ADULL, 0xDE904B710F9F26BFULL, 
            0x9EBFE4CCCAE202BBULL, 0x87DD5AE6B253651BULL, 0x148D5CD557614502ULL, 0xAD618FC193380D54ULL, 
            0xECDBC0E7F54B0042ULL, 0x87868FFA71083FD4ULL, 0xF3BF0E6BC8230B4DULL, 0x58FB2404D5ECE50DULL, 
            0x1650C2512A13776BULL, 0x60877ACBF412764BULL, 0xF34A1340320C5958ULL, 0x9F295D1380732FF6ULL, 
            0xA64E3C5DA217AE5BULL, 0x94ED03C4E17D8995ULL, 0xF268AFF912385CD2ULL, 0xD60D5AA83CBF350DULL, 
            0x398C74307B42C22AULL, 0x11E7FF48CC93F1D4ULL, 0xAA0BADE1B8CB2C62ULL, 0x874707EDC7053E14ULL, 
            0xBC285D0A371D6EFFULL, 0xEC8497D8EFF58E97ULL, 0x69DE93959561FB49ULL, 0x5655EBF92E9321A9ULL
        },
        {
            0xF8463CB2508BB343ULL, 0x27500A1871243701ULL, 0x8131C185D11AD7B1ULL, 0xE48AD26F62CFA82CULL, 
            0x5B29ED39443F3698ULL, 0x920AE0993D3EF14BULL, 0xECBBA469B54D1F00ULL, 0xA446127CEFA757CAULL, 
            0xC346F8E58FC6F198ULL, 0x8530428469DD60C0ULL, 0x7AF4789874D3FD68ULL, 0x774149D00D86DB6AULL, 
            0x5C2556D3D3EC5F74ULL, 0x40CA9F2366C28710ULL, 0xD2D22AAC6AA11073ULL, 0xEB1896060E28BD04ULL, 
            0x599B0928AD59FA8BULL, 0x99D5E698E5C232E6ULL, 0x3ABD3B1199CAD223ULL, 0x54E8369914B05AF7ULL, 
            0x0CC7AD59D1EDCA13ULL, 0xE7FC90D9ABF44125ULL, 0xCA3C57C1EB6686DBULL, 0x355B52952B89E543ULL, 
            0x8C24C46CB7410E81ULL, 0x4619C2B7DCA7161EULL, 0x6557299DD7406A8EULL, 0x2E33428A79D8BDDDULL, 
            0x5BECD936C331C6D2ULL, 0x3865C9674C6D0DB9ULL, 0x7D502D1E3B31F6E4ULL, 0xAE0AD75B81B43462ULL
        },
        {
            0x2DA55C1323E7EE3FULL, 0xB66C7FF0D1EE0F08ULL, 0x0A08F95DA16C0367ULL, 0x5C51AA0310AC8EB4ULL, 
            0x72D0E058D09F0896ULL, 0x7C8E41F05D5744B6ULL, 0x804A511989B0CD25ULL, 0x2B669A0DA8116991ULL, 
            0x7D581BEBC7E552DAULL, 0xEE6F9D9C49E1A563ULL, 0xFAA05249A9D93602ULL, 0xCD6CE8A912FF3FC2ULL, 
            0xB9EE460F81596435ULL, 0x96A6377A8C2A5F16ULL, 0x9FCA538C95F5EB13ULL, 0xC8A7882843768F9DULL, 
            0x939BCF2BAFE81BC1ULL, 0x1E104889986712CBULL, 0x5C24479D2DF44D5AULL, 0xA40F77360BB91AABULL, 
            0xDF27E2FFFBF1BAD4ULL, 0x1DB3A8599E503523ULL, 0xEABFD3F6548A5039ULL, 0x4C74378700F60E78ULL, 
            0x28E953C5B3AF0EB9ULL, 0x349EB6A61DDA3B90ULL, 0x73596D6A736019DFULL, 0xA962318809ABE123ULL, 
            0x260BE09712CD4156ULL, 0xD4FA5185F3C7C8EBULL, 0xE5FE4E3CEB5C7921ULL, 0x960D06B06B9394C2ULL
        },
        {
            0x8DEA42E4A44CE27EULL, 0x575D3806840A8930ULL, 0xFCF50E6B9AD27F8AULL, 0x9C9C4C18DE41AA8AULL, 
            0x1BD7AFBFCA0CF1D1ULL, 0x342319A0DBCDB634ULL, 0x8CDD223E4F1CA9F8ULL, 0x03E8B96B134E199FULL, 
            0xE66C46B67C5334EAULL, 0x28AB06AC80BF2B0FULL, 0xAEFB3B12328809FEULL, 0xEC69F38509F99B59ULL, 
            0x5CD1AA56FE791E68ULL, 0x29FC638B03CFA62DULL, 0x0AA1CC873DA31EACULL, 0x794CC5A154FDDC3AULL, 
            0x9365C50157E31EFBULL, 0xE13557B334319C2CULL, 0x03FCB4FB64D878DFULL, 0x39F803FBCE708910ULL, 
            0x187F771EDDFADE58ULL, 0x791C42874997F5D8ULL, 0x8ABC7179D2851052ULL, 0x0FEA48F6D2F001C3ULL, 
            0x805A6DFF116937C9ULL, 0x0C46DE2559CD9C37ULL, 0xECEA0D7D3B2A540CULL, 0xE5C31A401F048443ULL, 
            0xF8799D47CBFB0A2CULL, 0x10001ECB9B01DDA1ULL, 0xB03DDD9E9A823162ULL, 0xBFBB14878642A046ULL
        },
        {
            0xAB469B60F79282A6ULL, 0x0D371DA443742B17ULL, 0xCCD3B6A0E5D1811BULL, 0x0CB5F9AC289D9D4CULL, 
            0x79F4E253CD407235ULL, 0x0FCA74B4665C8037ULL, 0xE3BEA839C76BD6EFULL, 0x58ADDD632E258417ULL, 
            0x4B5DFA6F5EB8C6C1ULL, 0x198B07F642FAC631ULL, 0xDB0C0DFF79E440F0ULL, 0x75D20257E7A3B0BFULL, 
            0x2B7C875948FE03CCULL, 0x39668639B0C14332ULL, 0xFC75DB53D3A89EFBULL, 0x00EF695730F59FCEULL, 
            0x5B9BB1EA264C474AULL, 0x2EEB115CD2569D97ULL, 0x42B1D478B4A79CECULL, 0x7E357E2CD1AA56C1ULL, 
            0x7A2EDE5696521987ULL, 0x17D7E0C3077FD204ULL, 0xD4EF6DD22C0FBA7AULL, 0x27B355B57B9B29EFULL, 
            0x8B66DBB40C04C317ULL, 0x8F5CC00BF795F985ULL, 0xB35567DC710B434EULL, 0xC3E8EE1C48C88D22ULL, 
            0x14E2DC09F1078506ULL, 0x854CAC1693CE78D5ULL, 0x2F7F3AB3D1C7E9B5ULL, 0x0AB2AB0A03344713ULL
        }
    },
    {
        {
            0x5F40AFA9D8396D81ULL, 0x4112E5D1152FFC05ULL, 0x0A05B2DD73C35FABULL, 0x20EBCABA25F4F6A0ULL, 
            0xA7006968B3943306ULL, 0x2EE4902322559CDFULL, 0x41055D40F7D1AE60ULL, 0x40390CBF42328DB3ULL, 
            0xE45E95C002315D20ULL, 0x34A1255CD95359FBULL, 0x6BDACFDD1881E2C0ULL, 0x1F56171945C7062DULL, 
            0x5BE868E3902BF33BULL, 0xE3A0D3B3D1BA835CULL, 0xCD4460559C2D4002ULL, 0x9F2305140729398BULL, 
            0x5968E7DD53664A13ULL, 0x44B87231CAF4FBADULL, 0xCCB3C66D954B7858ULL, 0x519112BF303E1E6EULL, 
            0x4B8003556EBA1593ULL, 0x177888D3AEA313BEULL, 0xF4C62AF7EB2B8F5AULL, 0x1E922A6596F3E29FULL, 
            0x79339E6B1937838CULL, 0x446A7DC9E4A3E328ULL, 0x4D0C64E22D7032CAULL, 0x15FA9F9DD1EBB69CULL, 
            0x3D1D21E98D3EFE78ULL, 0x905FE5AC355AAAA7ULL, 0x7A656633856554FBULL, 0x508302AFE9E3DE1FULL
        },
        {
            0xECB28E117F4194F9ULL, 0x19DCC57EB35A5B25ULL, 0x99CB8E0BCCD8DC25ULL, 0x84A5A3ED0EC5FC04ULL, 
            0x39C405973B8BF48CULL, 0xBCC0E0BED9E5787BULL, 0x3BEED4E4DE9355B5ULL, 0x2C46C5F2689B8D7FULL, 
            0x92EB1ED064EDB3B2ULL, 0xDC74F18A7049587AULL, 0xBAC06C5ACE181FB8ULL, 0xBB6995CDCC0C7100ULL, 
            0xBED3F77C830AE25DULL, 0xD6F8B155539EA979ULL, 0x48E89E086FCE44CAULL, 0x13FE944363D6FE3CULL, 
            0x509853FE3C840357ULL, 0x3110A935937D1AB3ULL, 0x7D1942F225ED1C14ULL, 0x4913FBBCAB2870DBULL, 
            0xA535585948365EE2ULL, 0xA6172EEAC3945E18ULL, 0x4C8BDBF4EFDC119AULL, 0x521344CC13A398C0ULL, 
            0x903E78DA56B00D06ULL, 0xB9C1D56F07B18405ULL, 0x6832A12890DFC1F7ULL, 0xE434C2B49411F3AFULL, 
            0x768B031ADB246BBCULL, 0x54DBA3B7E1B78DE9ULL, 0x5FC9D6E54818E70EULL, 0x735F15731AE7EE59ULL
        },
        {
            0xDAF8681FB83A2F9EULL, 0x90FC337F7C306DF5ULL, 0x7AFFC8AE4A2E1EB3ULL, 0xDAD1FC8E51C5ED85ULL, 
            0xD144B32F66BA60E5ULL, 0x3E7B2C9FCEC52D72ULL, 0xAE428076A9A64DC9ULL, 0xC891C1492D7AD331ULL, 
            0x12C4E4272CF12733ULL, 0x471EF14F3356B4F3ULL, 0x9A4526051905572DULL, 0x08815CFD1EE311E1ULL, 
            0x715CF959E033E971ULL, 0xD34886767A2610BBULL, 0x20AF86422AEFBAA3ULL, 0x3A385B055382683BULL, 
            0x22422D956DBA0D42ULL, 0xC8F5CB027E83CB0FULL, 0x4F8741C05474019AULL, 0x1DE9DE5A49ADADB5ULL, 
            0xAF1A95DA1E063825ULL, 0xC37DD5A701CCC008ULL, 0x4BED8589997D0210ULL, 0x4B85BB29201FA232ULL, 
            0x58C6FDECDEFA50EEULL, 0x841AA383A431AB5AULL, 0x111A424EE1260854ULL, 0x19560D5961B63942ULL, 
            0xE2F5DB7BCDBAF415ULL, 0xC31282CA42F93CCAULL, 0xB4D09FEF71057F0BULL, 0x555D4791A8F2FC4BULL
        },
        {
            0x6BF47EC6F58CBF2EULL, 0xD0B1A462B5074DC7ULL, 0x995990AD30458D2FULL, 0x6061D007E724A7CFULL, 
            0xBE00DD0B34FA753BULL, 0x391F68231535AD75ULL, 0xFB73F013B2BEE13EULL, 0xF8072CDA8DCE700FULL, 
            0x5640D2BC97BD52D2ULL, 0xA72BC692269C0D8EULL, 0xE3A6746563EBA071ULL, 0x113ADF0E7DFFE3D6ULL, 
            0x6B7DA4CF6BCA898FULL, 0xB36E8125932A8C55ULL, 0x0BD234F8DAE9C068ULL, 0x438857072FF3DEC0ULL, 
            0xF73C1190A1B0E51FULL, 0x220DFC5BAC2B28FCULL, 0x19E0E8E8AC8FA254ULL, 0xFD692F98924516ADULL, 
            0x8E1DA02A1ABB04AAULL, 0xA0B6FBC2C315DF15ULL, 0xEA405B650E44820AULL, 0x1DBD2CC415F49B5FULL, 
            0x71B2D35810D95854ULL, 0xB97A1AB4465EF1CAULL, 0x79998D2B9F1F5820ULL, 0x8F50E47422B95DEAULL, 
            0xAC08D2E5BACB3756ULL, 0x733E912C36685E01ULL, 0x8698FBB924C9636FULL, 0x10FAC1FF9F909A10ULL
        },
        {
            0xD66CDB08B07CEC25ULL, 0x633870952C0EB484ULL, 0x56F66008DD3FE3A3ULL, 0xBE91CF7E445B7F3EULL, 
            0x43F993CA3A5E5AAEULL, 0xD51D9044614D299CULL, 0xB4F29ECCBF1BD476ULL, 0x7A82CF8D7B339213ULL, 
            0x3A73BC63F2ECC22DULL, 0x8A675273F893CBBDULL, 0x5A8952FF7F8314F4ULL, 0x45CF09043D8D3D34ULL, 
            0x1094E408B6518D1DULL, 0x81F316B5E4B0DE85ULL, 0x923FA388D9AC4AF6ULL, 0xDA234F36AEFE9B28ULL, 
            0x0CD219093A706D89ULL, 0xDB39D29A08891D98ULL, 0xE6329B99271C17ABULL, 0x4094A452505A0031ULL, 
            0x432DD6DBB9D7A8A2ULL, 0x9B3CA5C54945082EULL, 0x13292087A82F4FC4ULL, 0xEB967A36AC2D7308ULL, 
            0xF2DBA61D73D9BA63ULL, 0x76EF22B70983F07CULL, 0xE41990270E65857BULL, 0x916C4AF0C5AE0825ULL, 
            0x0861EFB2FE80CBA6ULL, 0x487BBA111E56F8AEULL, 0xC5E3789B42A0B518ULL, 0x12703F125B9B2D04ULL
        },
        {
            0xC2EDE74671A006B2ULL, 0xE8672CF08DB12A33ULL, 0xB99C237C5246538EULL, 0xE6530206A3535129ULL, 
            0xFDE1BD7E51F02ABEULL, 0x6655743E5B8B355DULL, 0x8E3219C82E421ABFULL, 0xA24015F05028411FULL, 
            0xC0DEDD51771841ADULL, 0xBEDA8D76CEBED51DULL, 0x1519BD699E4A82A6ULL, 0x8C4F7016E1FA307CULL, 
            0x4BC429C4A3E0788DULL, 0xE4CE9F9BF68CB678ULL, 0xE4078A091F4B031FULL, 0x8AC5F7ABAEB2ADBFULL, 
            0xBDD1949A069C2C98ULL, 0x3F387DEC221E1314ULL, 0x68660B8B37373BB1ULL, 0x614F2A2D47131B80ULL, 
            0xF980755FC2079978ULL, 0xDE6E763C9C336F30ULL, 0xC4A6B5AEC7D835BFULL, 0x3C23F34A0039AF0BULL, 
            0xC537EC19661CAD8AULL, 0x4A4DE86F8D8B1CDFULL, 0x301EFAA254DD353CULL, 0x37DC61F05D39EC48ULL, 
            0xEC1C9E317EBDCCF4ULL, 0xCCE97709AEC92A5FULL, 0xB36A86599CF3B29FULL, 0xB8FF6B224620288AULL
        }
    },
    {
        {
            0x1F08D0570FC79942ULL, 0x63B2217A674ED9F7ULL, 0x00F41E2A5C52CFE4ULL, 0xD8D851E87BC94C96ULL, 
            0xCD922F6F846A2498ULL, 0x6DF8BB23E44BE548ULL, 0x490A428DB34AF73CULL, 0x819FE78745F7050EULL, 
            0xBD0CB834BF10F78EULL, 0xD2F5A485C29DE648ULL, 0x1C367AD646C91FE8ULL, 0x7717CED047BAA8F8ULL, 
            0x0D97E3327F2A833BULL, 0x7B7512AB0C531155ULL, 0xA393387B12174C88ULL, 0x8AF985B88314FE40ULL, 
            0x72EE2897116F2BB5ULL, 0x771477B92AA0EBDAULL, 0x8F464B2CEB6D5D63ULL, 0x1FBACCA16B4350C4ULL, 
            0xFACD2119B1E99E33ULL, 0xBA687486C18BCCC9ULL, 0x264B05575070779CULL, 0x730E044F5DAAEA8EULL, 
            0x3393EDA02BA0762CULL, 0xBE4D2859FE45ACAAULL, 0x438F3C8826666043ULL, 0xCD380CB3F4C04F02ULL, 
            0xE26C1C16A95AE787ULL, 0x328B692A71C05B60ULL, 0x9A2D71214870DBC0ULL, 0x20B0A5F99E57ABE7ULL
        },
        {
            0xAE6FA327D87F4635ULL, 0x174E38A62EE4F798ULL, 0x110B5E01530E7611ULL, 0xC56ECD6975C0B1C4ULL, 
            0xACC0EDF9C579114BULL, 0x68ACEBE9E2B754C0ULL, 0xE69A11E3A17C6909ULL, 0x07454A7F72E5532DULL, 
            0x9EC61968763569C6ULL, 0x1EA87425D8BE620AULL, 0xE1F833B5379E8D99ULL, 0xEF1BF809BCD3A439ULL, 
            0x4327F1452287B12FULL, 0x1EDEDDBA07F570D7ULL, 0x994C2D8613E4299BULL, 0x9BFEC542E2A5BFD4ULL, 
            0x4592A504815E747BULL, 0x5B37A0BCD57463EFULL, 0xA014D4A3D5C6BA15ULL, 0x43C8D230F9F19557ULL, 
            0x406D099B5B43A5E1ULL, 0xE8A813B95277B5EAULL, 0x597C3D0B1020FEE6ULL, 0x647DC536F5A5FA67ULL, 
            0xC6CF56826182634DULL, 0x8B1A4B5163552766ULL, 0xDDA68CC11F1B14F7ULL, 0x78D2E42ED1128C14ULL, 
            0x3C827DEE5FF95165ULL, 0x3B591BC563794CD7ULL, 0x9470856FB34A7B44ULL, 0x2DAAB679DD972824ULL
        },
        {
            0x035C977631251134ULL, 0x70FC5DA057FA4D86ULL, 0x08F28F76581BEE18ULL, 0xC78B0E1C313FA41BULL, 
            0x3C80D88D1DBDCD2DULL, 0x53F2AB70924DB25DULL, 0x6425FD1F404853ADULL, 0x9696F6B859E0E898ULL, 
            0x3437FB1DDF182D58ULL, 0xAE24B15030DAA7E5ULL, 0x1E8DD2A1EBFD6A33ULL, 0x4423F67CEB77B875ULL, 
            0x6A42B7A6223D6ABEULL, 0xC3D885B48F75C6DDULL, 0x94492E5D4E854D50ULL, 0xAE1077CA070F70DEULL, 
            0x8D86BA340B7706EDULL, 0xFA0F843573D19F44ULL, 0x20601AF730C9813DULL, 0x3B84B2C2C1283CBBULL, 
            0xE447C41528297B9DULL, 0xF96FC36A8A602A3DULL, 0x20E101FA08054572ULL, 0x9DC063C46DA00F1DULL, 
            0xD8F39D63082D573FULL, 0x79EA9CF8D770AF52ULL, 0x2906A3CB523E88F0ULL, 0x86A4B4FBFE0262A2ULL, 
            0x30DAB5FD0BDE497EULL, 0xCD790A491CA8B6BBULL, 0x44D59ED0A010DC3DULL, 0x61A3355D05C1D957ULL
        },
        {
            0xA33F823454ACF322ULL, 0x6E0C30A1E3CF2122ULL, 0xCCF461C54F0393F0ULL, 0x61167087A49D0374ULL, 
            0xCDFE481B5BB1D15BULL, 0x3E155ADB6193CC05ULL, 0x4CF9CE7EB00AA3A1ULL, 0xEF1AC9B7E1FBB914ULL, 
            0x62C120DA5D330A19ULL, 0x9CCF50A0C58CBA06ULL, 0xB05EE32EFDF4F667ULL, 0xC7CF0ECDCD2270D4ULL, 
            0xAABFBE2AE7FD1F29ULL, 0x4379FD39C62CF453ULL, 0x7333CE004EAC298AULL, 0xC7F4BA450A6BC3A3ULL, 
            0x5738D186A9370B22ULL, 0xE238D6A746ACF0C9ULL, 0xF2CD680DEF6F5C3AULL, 0x9DAD5C25D29A1C0DULL, 
            0xF43436FE24ECE701ULL, 0xDC5018F890B1402AULL, 0x67264A1AC6BBC25EULL, 0xFC009C6F9AD1B3DCULL, 
            0x736062A77861EF34ULL, 0x5A57FB183702AC9EULL, 0x43CBF551F5D43D23ULL, 0x84326D7DF33B8837ULL, 
            0xB6E519DC9043363CULL, 0x1584B49DBBB3C0CBULL, 0x0A0E58F0519F623CULL, 0x800C8AC67834BBE2ULL
        },
        {
            0xAF4A315A348CE147ULL, 0xD142F490E9FEB745ULL, 0xB471568AD57661FBULL, 0x8EE34F113BA36DA6ULL, 
            0x84268370C6A3D4D6ULL, 0x61520359C9A48368ULL, 0x7CC36C1B32DE5F1CULL, 0x113BE6CCB51560B7ULL, 
            0xA413608E3F50564BULL, 0xF99F58472081FA48ULL, 0x8298DB1CE2B0C6F6ULL, 0xB699E597DF6B8C1FULL, 
            0x4C34F2C0007E6134ULL, 0xE8F9CC3E72209380ULL, 0xA9144896D80264A1ULL, 0x4C309A300A306FDCULL, 
            0xEFFBBA67ED1594E7ULL, 0x7D3C28B91C71D3BFULL, 0xA56BE1AF5DF6FCDFULL, 0xEF00EC7AECDD31A9ULL, 
            0xC15F0E3BAA483B0AULL, 0x5B7F689058021823ULL, 0xBB567846D809073FULL, 0x6FA94FEAA839BE6FULL, 
            0x3BB43508DA41FAEDULL, 0x55E685A391F4CA47ULL, 0x18D0758F0FC9FCD9ULL, 0xD908D82FCC7B6C4CULL, 
            0xA93E8BC105B9168EULL, 0x24820135025AAD6DULL, 0x322DADEACE4F9342ULL, 0x199A10987EDF8200ULL
        },
        {
            0xFDF035AD808925DAULL, 0x51E47697A39FE4B8ULL, 0x30F7C85796F58903ULL, 0xB076A6467A457E28ULL, 
            0xAE7D0F8B208A35D5ULL, 0x15ED59C4AA4A298BULL, 0x7931CF6E2186FE98ULL, 0xFF543A49054F4B45ULL, 
            0x5DC835B800C6BDB0ULL, 0xDC6100F86E4800F0ULL, 0xEBB0E9B7D829FE91ULL, 0x70195E862B769790ULL, 
            0x1508CB431C67D180ULL, 0x2AE4752D740A78DDULL, 0x252C0BC90E308E27ULL, 0x84953E65AA3732D9ULL, 
            0x2F58C92EAFEA12A2ULL, 0x8F27881F1595893BULL, 0xEE4D3C2E3EEE2A45ULL, 0xB8C40E7941E19DFBULL, 
            0xBB39941B5427ADC7ULL, 0xB9754003B1B069A8ULL, 0xB64F6794A53D48E0ULL, 0x888B9954936ADDCEULL, 
            0xBD49DA6592F53DB4ULL, 0xBADDD98EBB5ABE48ULL, 0x20CC34B2795E7888ULL, 0x19A560263128C8DFULL, 
            0xB37BCD457AAF4371ULL, 0x4DB37168C8CA9042ULL, 0xCD8B154DF0B9C6C0ULL, 0x2DD4E69741EE0FBAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseDConstants = {
    0x6C9514AE5B8BB5F6ULL,
    0x70856E7029DC06BFULL,
    0xFDF275088375DAEDULL,
    0x6C9514AE5B8BB5F6ULL,
    0x70856E7029DC06BFULL,
    0xFDF275088375DAEDULL,
    0x259C5F0092099AA7ULL,
    0xE41BEF2A29C4DD1EULL,
    0x3F,
    0x22,
    0x23,
    0xE8,
    0xF3,
    0xBC,
    0x9E,
    0x10
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseESalts = {
    {
        {
            0x77F7AB93B5A5B1DEULL, 0x7F897F1F64DC9F4DULL, 0x1E7A6EEF19888B1EULL, 0x101F5FA3B0DD01C6ULL, 
            0xA0FE95347F0BBFBFULL, 0x473358C083AB3515ULL, 0x327FE60819E5C58DULL, 0x506D97DBA0955773ULL, 
            0xEE15EE788ED88601ULL, 0x06A38F667588BDFEULL, 0x56FE22187091739AULL, 0x93ACFDB9275ACFF4ULL, 
            0xACFA830B597D3023ULL, 0x12ADD2B715A382B1ULL, 0x9BEDCDCC5DD653E0ULL, 0x172718C7C2DF0972ULL, 
            0xF78A7FC8579AA2D9ULL, 0x7BC97DBFC9218205ULL, 0x99C4984A929B959DULL, 0x0776DAE955A35E9CULL, 
            0x63099E5EBCF29EFAULL, 0x9E0187422CC72A87ULL, 0x48B3E6E9F87C20CBULL, 0x76E89BF854F72991ULL, 
            0xEAB180548C92FA7EULL, 0x34CF0ED2445693DBULL, 0x4BC1D3D8C3DCE74BULL, 0x0A22BED791C0D4D3ULL, 
            0xF87C0A93B82D00F3ULL, 0x7A432D2546E976D8ULL, 0x7836FB2446AE0DE0ULL, 0xB75210A59F96497FULL
        },
        {
            0x87DFA733DCA4DE30ULL, 0xE6FE724A874B51F2ULL, 0xEA8F26489A4FCDECULL, 0xB3526EEF0F79CB3BULL, 
            0x5C7D7FF6CEE0DA4EULL, 0x6121C94C6BFE1CEAULL, 0x80D782D1FF2025A5ULL, 0x04AA002D572CCBEAULL, 
            0x829FBE8FF66271CBULL, 0xAC1D971618B34045ULL, 0x073101D46ADE59FAULL, 0xFC819BE150DA1018ULL, 
            0x1AC7C70FB276009BULL, 0xED76298AC7D447E4ULL, 0x1346E5ABDD986860ULL, 0xCA6A8C0FB845E810ULL, 
            0xC36C21AB5AC49560ULL, 0x2A60D8693E982FE6ULL, 0xC9B1E0F7E8016E09ULL, 0xD0FC1DFD4DABD1C9ULL, 
            0x5269C5F36FFE5A1DULL, 0x634AE95F01AD575FULL, 0x2D2E63A08AEBD6FFULL, 0x495D35A54741275CULL, 
            0xC1F612CD456A6869ULL, 0x0C3F4039E35914F2ULL, 0xD5702670FB31AEAAULL, 0x30713015F2009C54ULL, 
            0x85534740E4F82F08ULL, 0xFAAE9DDA24EDE916ULL, 0x311C39546A9893CEULL, 0xD5934C6B7623B1DDULL
        },
        {
            0x797C1C90FC89600CULL, 0xCC51411C9D4154DBULL, 0xAB7B8C177544146FULL, 0xF2B5EB9EE988DA73ULL, 
            0xA6912D42C7DB7C98ULL, 0x9A2660876905FEBCULL, 0x147C4A61DB7AD17AULL, 0x6E5A06BFBEB8C34EULL, 
            0xCA2C01B0605628E9ULL, 0x057B0DF552F96499ULL, 0x85D33C18C7D39857ULL, 0x7E5DBA3A8F3EA6A7ULL, 
            0x1D496DEF536EFF58ULL, 0xDAE80ADDA7E248AEULL, 0xA9C8E5C62E542679ULL, 0x650BE4CE0E21E362ULL, 
            0xB0373EAD0BC2984EULL, 0xC0C9F8918CB5FA1AULL, 0xED95F01BEB3F74A6ULL, 0x1F914004822623BDULL, 
            0x47A0620574533624ULL, 0x14C8AF09F5CEDCF0ULL, 0xE0A56DB977654930ULL, 0x3FDF96DCCD4363E5ULL, 
            0x0D3EAF27B01FE661ULL, 0xAA0EA0F683A568C1ULL, 0x73313483B2A3259EULL, 0x0EF5F02DA7B58D39ULL, 
            0x5789E7FC10E4B801ULL, 0x1723851BE0E1F03EULL, 0xDE6B8C83008E5D3CULL, 0x8E1CC26281AD9FBEULL
        },
        {
            0x5EE31239D441489AULL, 0x46038628D5ED13D2ULL, 0x4DA9FD87E969C4A6ULL, 0xCFC6321061C3A139ULL, 
            0xC96BBCCF1930EA31ULL, 0xA46F02D1EC388D5BULL, 0x8D7C89CDF6BDABC2ULL, 0x410160F10C4EA91BULL, 
            0xCD85FF95326B91CCULL, 0x841F62C8EE0C9B54ULL, 0x076A9EF7B7B8237DULL, 0xBD1023F734AAD40BULL, 
            0x872FF59D14B057BEULL, 0xA7CEAD01496604DBULL, 0xC060A013E7D60670ULL, 0x688957F4CD301051ULL, 
            0xF6448D561CAD59F4ULL, 0x1C32A5E17158179BULL, 0x136B9249D4154EFDULL, 0xF1E945F895F64768ULL, 
            0xA54AE9AF577351D3ULL, 0x6CBCDF9815DBF0B5ULL, 0xFA881051ACD7AD46ULL, 0xE21536E8B7D65D9DULL, 
            0x5A029DD666F1AD4AULL, 0x7939538C9B1218EFULL, 0x7A62F83D62B82513ULL, 0xCE4F00D0789FD196ULL, 
            0x03868ABBD43CC7A5ULL, 0x0299B5FC908B526DULL, 0x0C8303F933527DBCULL, 0x9E302DE70ABFE8C5ULL
        },
        {
            0x551C1E64AABD8B04ULL, 0x601695B15A898261ULL, 0x2A292B63749FBBB4ULL, 0xF6F122F3157F6FC2ULL, 
            0x70F4329AE5EED54FULL, 0xE7F861D97DA34756ULL, 0x94BCBB4BA229002CULL, 0x2D3EF64E761BA155ULL, 
            0xF2C79F7F334EDA81ULL, 0x0B8116E7C7D634EFULL, 0xEC2A720ABCB2937DULL, 0x22EEC667D128E3A7ULL, 
            0xEE255FB9BD6E3D90ULL, 0x9270A85A7E01F536ULL, 0xF5EA6FF50BDCABDDULL, 0x2904E5CB710F1717ULL, 
            0xEB951D9EB3D7FF1DULL, 0x17D3C2C1E806732AULL, 0xA2F9BC65AC4CA536ULL, 0x8E57D090537BA56EULL, 
            0x61D6F9C825021064ULL, 0x42D4DF6CA60A2374ULL, 0xF9C732E45D40BDC5ULL, 0xA49D1CE28F3B06ECULL, 
            0x149A37A92FFAD648ULL, 0xD30F1FD1FC1CFF1FULL, 0x870E4AAF95C9EC33ULL, 0x26664CC18B7CAB35ULL, 
            0xE3F95853C5A5C000ULL, 0x0973A5930B9B29AEULL, 0xB37817F44144D0FDULL, 0x89789FA80A69539CULL
        },
        {
            0x79B64EE9ABFB750AULL, 0xEC77ED5B625E09BCULL, 0xE60E951FE6D3DB58ULL, 0x9C8BE6F314E4CF23ULL, 
            0xA7A26ABDB5233011ULL, 0xAB90A30EA00F562FULL, 0xA83BD3D316DBE761ULL, 0x9E6C6D21F9DBD28EULL, 
            0x5B505140BFD7549AULL, 0x662A216F06390CBFULL, 0x69419772DFD116ACULL, 0xB2B6E5A5B6851391ULL, 
            0xAFC138896C1669DEULL, 0xAE15534F46749AF0ULL, 0xB359D3B689F24A69ULL, 0x25A665A2042DA670ULL, 
            0x53B308F97AA877AFULL, 0x251DB500AD5F010CULL, 0x688A806E380D72D3ULL, 0xFEF09EFCD358F3E0ULL, 
            0x19C1BBB2D4CAFFD5ULL, 0xC655C4F394B9168FULL, 0x120081BE511A8D53ULL, 0x12091057254EECDDULL, 
            0x72AD5778652AB53FULL, 0x541A460314E2E705ULL, 0xD5A3E754FDA99803ULL, 0xFF94ADD2B03D4293ULL, 
            0xF4BCDFBC18CBAEDCULL, 0xC53591D34A74FCB0ULL, 0xD83C79E6964A3CE1ULL, 0x1B4401EE624F4BFCULL
        }
    },
    {
        {
            0x36AAC28F34BE9353ULL, 0xF078F97919B61A23ULL, 0xF955D9601A306E1AULL, 0x65E75647C707C67EULL, 
            0x0275F68BE26EC0ECULL, 0x70404677E1367109ULL, 0x9B59E7268B9E9BA0ULL, 0xD92BEE0B3A2E903EULL, 
            0x3B7BA888629C4ABAULL, 0x20E70BF2083BD655ULL, 0xBFF498D5823E7C8DULL, 0x3495433786C7BCA8ULL, 
            0xE596C842F5221303ULL, 0xF5ACF0851E87B95DULL, 0x1BA3EE247299E2EAULL, 0x25EF0228B9BDA2CAULL, 
            0x0C32C973F0F58CB7ULL, 0xF243880966A2E809ULL, 0x748CFFAA9AEC28D1ULL, 0x1EB4B168614DEAEDULL, 
            0x7CCD76ED486D5DE2ULL, 0x81930FEA659A721CULL, 0xD8B0C12F30FF564DULL, 0x31120F8FCA366574ULL, 
            0x8AE9A0C0E0DCB825ULL, 0x8A8A118759079977ULL, 0xCD7109C06AD4C5F7ULL, 0xAEB1D96A9197CDE5ULL, 
            0x2700D6A68E4D1153ULL, 0x1B16B3E69BA7BB6BULL, 0xE552B1D9FFB81FE4ULL, 0xA56548E57F443674ULL
        },
        {
            0xAA39A4C484714119ULL, 0x6C7575886116B1E0ULL, 0x7A280F9AE66C036EULL, 0xD91A2D704A4CE966ULL, 
            0x974DAC1E18B0F91DULL, 0x96F8F3AA9D52C7E6ULL, 0x195009E348AF4546ULL, 0xCCD09D1D01B19814ULL, 
            0x841E9B5D1A5C5AD7ULL, 0xBADA30221273B480ULL, 0xE6D416569E9886E1ULL, 0xDFBE800756279ABDULL, 
            0xB46795EBB2ED7BFCULL, 0x397A3F7EC65CC1F6ULL, 0x12D01AF4AFFFD828ULL, 0xA818C78D06701CAAULL, 
            0x0E536614D66C9A32ULL, 0xB4C4F9F9CC7D0FC5ULL, 0xD3DCE245D483860CULL, 0x21D8DBCCEA389F7BULL, 
            0x7DCFB185C1743A08ULL, 0x3DF9C5B0C573D59AULL, 0x5D826C033E0190CEULL, 0x486C48BE4CEF7256ULL, 
            0x32DBF05DA44802C6ULL, 0x82D7C12786714FB9ULL, 0x69C98EA9EFD9D23CULL, 0x7C458DE170C30916ULL, 
            0x1989CFE00BD33A4AULL, 0x415122614D063E9EULL, 0xAAE269A30657CC30ULL, 0xF30D7F3709679BC2ULL
        },
        {
            0x976C135A370F1724ULL, 0x5A47718F3D90BAACULL, 0x1C46004431D39033ULL, 0x2C16CFF38701AC4BULL, 
            0xCD88B31CF21B9558ULL, 0xB024D3CC8365B30BULL, 0x89916245E151B0BEULL, 0xB596C3973A71C217ULL, 
            0x5C8B19E0495F2DEDULL, 0xFA4989E199E18B5AULL, 0x9B9707523AB742A8ULL, 0x0BFCAE077C00B959ULL, 
            0x6EA3A23297B9ED65ULL, 0xBBD585EF8AAEE1E3ULL, 0x14C04A69CE44274DULL, 0xBAF8982CA3213CF6ULL, 
            0x511A8D078777AD16ULL, 0x3ACB4D5E9A90EE47ULL, 0xBF963F82B21B3DE1ULL, 0x2F2C0720F37769C9ULL, 
            0xD151FDB58D92B30AULL, 0x62E0AAD1FACD8037ULL, 0x06918208059EF92DULL, 0x4F74734D0B74E79EULL, 
            0xCF8E50EFEED31B9FULL, 0x79BDCBA837B1FEAEULL, 0x7E207408145B6DF6ULL, 0x8BAC485822C7C6BFULL, 
            0x0B4ED089646A9ED8ULL, 0xE04192691E25F476ULL, 0x36FAD71BD7C4D57FULL, 0x208426761D835B65ULL
        },
        {
            0xE5F3F483173D4253ULL, 0x4BD32CDEAD02189CULL, 0x6A754E3E74AF9619ULL, 0x79ED9459F3857951ULL, 
            0x48E6943789F579A2ULL, 0x6C4670D2D26CC58AULL, 0x49DD54AB3976B634ULL, 0x2D593B35DCF29C7AULL, 
            0xD2985D002BB395BDULL, 0x400BB728696D6332ULL, 0x0FD41BBD6741A5CEULL, 0x579C7B7229DB70C1ULL, 
            0x219E94F481CD689EULL, 0xD4FC84A9A88FE2C5ULL, 0x7540004217C638C3ULL, 0x1F3759D28A11ACB2ULL, 
            0x81E3532FA3A11522ULL, 0x65C8170EF169F8EDULL, 0xECC20FEF3AA154B4ULL, 0x8735216993A0BDB5ULL, 
            0x9F814E93366816ABULL, 0x84F58A28ACD6610CULL, 0x8C4AF3CDB4A79094ULL, 0x10571FCD2FA8C887ULL, 
            0x39FB6E1E7B8C69ABULL, 0x736B09DC6FA4887AULL, 0x23B6B324345C98C8ULL, 0xAF43B221C15413B4ULL, 
            0x29F6963E4BC9E027ULL, 0xA28D1ADCD5A023DCULL, 0x751FAA092A9DD52DULL, 0x77105D0629083F8FULL
        },
        {
            0x9B6E582E4EB4E021ULL, 0xAC1188D629D88B46ULL, 0xA49C812016A8A82EULL, 0xAA53581625DF5637ULL, 
            0xF216425F591954D0ULL, 0x8D9BC95641D6D279ULL, 0xC7321F359CBFCD4BULL, 0x139603FA40B2249DULL, 
            0x16912D21B360F8BBULL, 0x31B324978BA09036ULL, 0xE84B541D6C1AC545ULL, 0x7CD4F0B0EFA63FC8ULL, 
            0x6A342DC8051D53DDULL, 0xFA02F4D6EBF01AE0ULL, 0x8953E141C1A28E5EULL, 0xD48CB33812B4B0F0ULL, 
            0x14EB3D2D623B3214ULL, 0x4E23D4D7A7DBCC6AULL, 0xC7B4BB115A118D38ULL, 0x2B02EE688D076377ULL, 
            0x544B4E546929E991ULL, 0x3FCE3B1E940EBB26ULL, 0xC9352B344D442EA9ULL, 0xC9D45FC5F0B7140DULL, 
            0xFFB887297A1B75D5ULL, 0x2EA9EB15C4AB4A25ULL, 0x17B87F698AC6C8FCULL, 0xC3A9C3E65C54E353ULL, 
            0x3581D4A0C8A981FAULL, 0x95729127216378B4ULL, 0x8F2DEA2B4664CE9AULL, 0xC63D7AE9B8CFB111ULL
        },
        {
            0x7C19BD724C618BB9ULL, 0x27CF9866CD31ABDAULL, 0xC5E25E7C688A3BC9ULL, 0xC0ED699836E01380ULL, 
            0x665DEF9C02E3F2B0ULL, 0xCBE5C97A2721A0F9ULL, 0xE0E211231C36A6D0ULL, 0x57B5573316CEFAFAULL, 
            0x944A389A7B6C0107ULL, 0x3F29E0C5641AF737ULL, 0xAAA9545560C199AFULL, 0xBB8F42F20A3ED878ULL, 
            0xB7B0F7BE480501C4ULL, 0x1BFC7DA05ECE28E6ULL, 0xBACF2E7C7051A016ULL, 0xA25A88651873DBA8ULL, 
            0xAF24F0676858BE1AULL, 0x229EBA3EC59A0BD1ULL, 0xA4AD514B2B555625ULL, 0xB218D187EA2AAA4DULL, 
            0x8DAD9EFC06BC64A3ULL, 0x5853B441BB16387FULL, 0xFD4C59994CD4FCFBULL, 0x9A493C8FE3C0E9EEULL, 
            0xC87BD687116758A1ULL, 0xD217199A49EBE28EULL, 0x510D431F9E70A93EULL, 0xEEFB9C23E7654DF3ULL, 
            0xFEAED0A717401ADDULL, 0xCB7A1E649097A9A8ULL, 0x895B6042DC173C34ULL, 0x4C6CB9DA9F2642B1ULL
        }
    },
    {
        {
            0x104E1AA025E91334ULL, 0x5A722CCFB5E5D404ULL, 0xDD60E94E061A03B2ULL, 0xF9D4260564FF47BBULL, 
            0x7530EE00372C6786ULL, 0x1B05955FA9928CB1ULL, 0x391E1275DD594103ULL, 0xFA9BCC7EEAA6DBEFULL, 
            0xAD4152C989D1463BULL, 0x4BE0F2EB2DBF9897ULL, 0x2EAF45B784112660ULL, 0x0696A5532175A584ULL, 
            0xE67129C03CE77AD6ULL, 0x4D7E3378E665A525ULL, 0xF23F10472AA4B877ULL, 0x8922B736F078600AULL, 
            0x683459042A4DA5CBULL, 0x80EED33B61F3D0D4ULL, 0x4FE1DB48D911B327ULL, 0xBABF00253A883F4BULL, 
            0xE0E61A4B7F05A4C0ULL, 0x17389B5616110EA8ULL, 0x557926A04990E4EAULL, 0x7A5CD450CD0E8B97ULL, 
            0xFEFC9D067F2E2495ULL, 0x75B3A82CEA9F146EULL, 0xF93FA3C980D9DAFBULL, 0xCFBEEEFA5AA03C05ULL, 
            0x574CBAABF32C8909ULL, 0x6351E3268D25ED57ULL, 0x21826870A877970EULL, 0xC5DAB4D989E8B391ULL
        },
        {
            0x78723C3618054DAFULL, 0x2BB8F42CEE43ACE8ULL, 0xCF8AC5028D955354ULL, 0x3947DC601631D58FULL, 
            0xEDF6EB0A0B1203E0ULL, 0xC6610D9BD50C27BDULL, 0x8E6BBDB0B20A9285ULL, 0xC57C65E58A7034BBULL, 
            0x90E62B46263B839AULL, 0x8AC149CC90B45466ULL, 0xCE81FF20291DFA69ULL, 0x7F7AA3CE2A1F2C79ULL, 
            0x2AD4B87018A562A6ULL, 0x1367F35D5A136FE9ULL, 0xB497A5FD37B0AC63ULL, 0x89EBF2FA902F5FE6ULL, 
            0xF8B6B90F6D4E63E0ULL, 0x99E340D16EE5C02FULL, 0x6845AD10651C2C0CULL, 0x9640ACC6792F4612ULL, 
            0xB2CCD1A30012FE8FULL, 0x97B481B08796F2D5ULL, 0x68BDC1E166EC4A4FULL, 0x427934EE7733AC00ULL, 
            0x2376DE45168A0845ULL, 0x9AEDC6E0E3152B11ULL, 0x5C54802B11202F15ULL, 0x6BA3253DCA1E5488ULL, 
            0x019B934C8F1723C7ULL, 0xBC5F8585738EF3E1ULL, 0x2752C613FD3A69DAULL, 0x68AB225DAE84AB45ULL
        },
        {
            0xB084196DC398E7C2ULL, 0xF57E7A0B340257DCULL, 0x01CD48EBDA0E28DBULL, 0xFCE04946960B5B15ULL, 
            0x37F27314FA3470A3ULL, 0x9C5C14191097E840ULL, 0x79EF94BBB9C00801ULL, 0x8B876D5EE946C37FULL, 
            0x16EF3F75688C1A3FULL, 0xE63A781C18B33D5FULL, 0x93D763B7FC8DCB1FULL, 0xB398CE66D34529B1ULL, 
            0xD8CC7266D2FF066CULL, 0x04C5804CFF3389D0ULL, 0x8F9DEF7492675202ULL, 0x3A4980C8B95CA4BFULL, 
            0x94C6446DEE1DD571ULL, 0xE5E205C74ACC48A4ULL, 0xDB965AE4E82576C1ULL, 0x6887A0094336BAFBULL, 
            0xEE12E030AEFEFF07ULL, 0xEAECBFCE74BA99E6ULL, 0x219F7147ECD896F5ULL, 0x0A5EF0C8004625EBULL, 
            0x1F655B4C9DD956DEULL, 0x094127007329170DULL, 0xA1CE5F0AEBDB49F2ULL, 0x527E2A43BB76C827ULL, 
            0x085E368C80D77B85ULL, 0x9284A3852173DA5CULL, 0xD3A47EE056674F27ULL, 0x8A2B6889E4D9FAD6ULL
        },
        {
            0x8CA4E6A5A1E742B3ULL, 0xDF823BD4E504370CULL, 0xB0F19443C3C126C5ULL, 0x8D07859C3EFB40ABULL, 
            0x10CB33BCB1560D6EULL, 0x769DCDAB3449C9C5ULL, 0xDE08E303EC469E38ULL, 0x245C5B259B4A9CF0ULL, 
            0x6E21600325E417F5ULL, 0xB43F0EFA33CF29D8ULL, 0x15519E3D22328CDBULL, 0xC8FE1C8D84EADA28ULL, 
            0x3A5F75B51D29C511ULL, 0x0C9223F5EBD976BFULL, 0x9ACDCB500443AB7AULL, 0xCE414E940716F787ULL, 
            0xDA35F5EBC0ADDFE9ULL, 0x898E55A5FABC3CD9ULL, 0xBB02C9CD04CAD0BAULL, 0xB8B87A6B1E348F4DULL, 
            0xBB0321368B18C72EULL, 0x12EEBE3CE802A7A8ULL, 0x8A121C57C38D6731ULL, 0x2CAFC23321770A1AULL, 
            0xD645CE687947D177ULL, 0x250833FF9600CFF7ULL, 0x8470B9FE2C78AD72ULL, 0x71AA4AD34320C7C1ULL, 
            0x8900D8727F552609ULL, 0x94C3C77137296CA7ULL, 0x799A1E25CC5B80D5ULL, 0xFC60A97FFB7BAC8AULL
        },
        {
            0x2358D467701E1B27ULL, 0xAC140F65F79188C0ULL, 0x3634FA00156C5D02ULL, 0x5DA6086BD605D2C8ULL, 
            0x153A2E10CB333890ULL, 0xEF270D40948C42B6ULL, 0x44033A3B11971F2DULL, 0xC5E8CFBFC9EDC2A0ULL, 
            0x96DE681E2DB2852DULL, 0x9FD4170F9D3FAEC9ULL, 0x67AADBD25758B0F4ULL, 0x0276BE79929ED84BULL, 
            0xC400AFD1E2B45E5CULL, 0xF0BE4AE699CA8D48ULL, 0x6DCE54DA21E655A3ULL, 0x3E3AEE098FC7F1DEULL, 
            0xD358CA363847A5B1ULL, 0xBA9E350BCEC409A9ULL, 0xF5823116AF1217E7ULL, 0x62F209E65535709EULL, 
            0x8BC50735A4FB54FFULL, 0x80DB93916CE4FB8EULL, 0x0DED0F8739A1BBC0ULL, 0x9DB630554E46EE5CULL, 
            0xA14FA44138882CFAULL, 0x1462B943FFD23F99ULL, 0x247142000CC9F4FFULL, 0xA7E4A2B38F32FDE7ULL, 
            0x3F1DB901870DBD84ULL, 0xDEDBC52297098497ULL, 0x56EC90917D12C2D0ULL, 0xB3D961B241C067F9ULL
        },
        {
            0xB6CD06DF73A38E57ULL, 0x3DA51F5203D367D9ULL, 0x347CC6C798A3AB47ULL, 0xEA9F8960D049318DULL, 
            0x7AA417C078EEEEFDULL, 0x0C75705570204173ULL, 0x123B52259C4AA521ULL, 0x01CC51A0B24BFEC5ULL, 
            0x733B31C12E3C8C61ULL, 0x683183A6D8380321ULL, 0xB53862FAB25421C2ULL, 0xD4A633D29242736FULL, 
            0x2FD639D4753CB6CDULL, 0xF84CFC1498356BD4ULL, 0x29F37CD7549762C4ULL, 0xB1599751F2E96494ULL, 
            0x26301A5CACB11BB3ULL, 0xA5CD2A5914BFB2E2ULL, 0x9DC31C451FBE2335ULL, 0xE19B539AB766CFE9ULL, 
            0x4A208A9F31DD173CULL, 0x750E122B32B2EC18ULL, 0x3A46986BB374D38DULL, 0x77189887826F8420ULL, 
            0x0AA0C41DA423AB28ULL, 0x08FD67195A116138ULL, 0x48887E7F6C803F33ULL, 0x520C8A4C5CBC2ACAULL, 
            0x159AD27960923908ULL, 0x2A3759753665149DULL, 0xEF478AB33C1CAC04ULL, 0x144006DBA8D91F27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseEConstants = {
    0xF3F3BA0A14E2C892ULL,
    0x61A546F4DCEFD617ULL,
    0x01959023A3C215CAULL,
    0xF3F3BA0A14E2C892ULL,
    0x61A546F4DCEFD617ULL,
    0x01959023A3C215CAULL,
    0x20B1F0CAE4500173ULL,
    0xBB27479B19B6D851ULL,
    0x35,
    0x5A,
    0x0B,
    0xF8,
    0x3B,
    0xDB,
    0x94,
    0xD4
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseFSalts = {
    {
        {
            0x362B07608A9CB34EULL, 0xCD06E68BDB6442E5ULL, 0x885881F10F9B263DULL, 0xFA7F03DACFFDA9F8ULL, 
            0xEB15AB37167E024AULL, 0x607B27E0A6C5C039ULL, 0x4CB8B394A34E5450ULL, 0xEF65068AD3837F3EULL, 
            0xDCD700B004140A7BULL, 0x31CA6114C3BF4274ULL, 0x3269761AB9AA30CBULL, 0x8DA275B26A36F2AFULL, 
            0x6715D7A7BF50B084ULL, 0x64E43B418335D0D8ULL, 0xBF6B8F64E9C7E1ADULL, 0x77F56C4716AAC8F1ULL, 
            0x307AC039BA30EFA5ULL, 0x247032CC56D43BAAULL, 0x70B553674180C29BULL, 0x4873FF40FF96FB83ULL, 
            0x5A05C986B4B57802ULL, 0xFCBC9764A297420FULL, 0x2C8E52FE58FC29A0ULL, 0x23756DA1F698E95EULL, 
            0xCAE5A25014350CFEULL, 0x2A158C988D05EF3BULL, 0x13A3FDF47EEBDBD2ULL, 0xC3DE11D1CFC8A2B0ULL, 
            0x7F9F8576B645690FULL, 0x15EC85C4C5B505F9ULL, 0xF5F25E4A688FA335ULL, 0xF13D1813CF982774ULL
        },
        {
            0xF20846A5DCD8CE7FULL, 0xF9A312D1D19A3493ULL, 0x36C313AE14EC9084ULL, 0x43C1EB48E0DA280FULL, 
            0xF5090A44B92CAC7FULL, 0x54897D943F4012F9ULL, 0xBC4E214051771914ULL, 0x3B5C8627A8143F51ULL, 
            0xF0027E2DF49127A0ULL, 0x3A323980F7FEA09EULL, 0x1162E847F0704E7FULL, 0xE23DFDCC21DBB391ULL, 
            0x59E22F209BE110AFULL, 0x5683C09E96A79645ULL, 0x7B57F5D4EF77C7FEULL, 0x4BDA170D4CADB759ULL, 
            0x467E32FBD3A18921ULL, 0x2EA43AA409E9C51CULL, 0x9F14472CB22B2208ULL, 0x1F68A9FB4DC86F8EULL, 
            0x4435FD5B2AEF582EULL, 0xBC63FF3C0E2A8F75ULL, 0x8D0EE7520B5B5977ULL, 0x83D0BA51B122818FULL, 
            0x91AAC987BA173BCBULL, 0x9CC367CE082C00BDULL, 0xCB175370945C0701ULL, 0xB5DA04C7A56E55DCULL, 
            0xC062047438F37CC2ULL, 0xC072C43A8EE133CEULL, 0x37C7F34B676DF4F4ULL, 0xEDBDF118EDA8375FULL
        },
        {
            0x05A8B039B1FF70E2ULL, 0x270788881F9C90B1ULL, 0x0A24C9AE5027E8B9ULL, 0x90E59DF16A1EC53BULL, 
            0xACD7F61C35BF1F98ULL, 0x2F3B05BFB5F50015ULL, 0x46D949B068AD5E99ULL, 0xC03D9F2886085D30ULL, 
            0xA1F3FBE0E566770AULL, 0xF814C67BE4D9981AULL, 0xF7F79280989E9696ULL, 0xB664A342B691D47EULL, 
            0x292FCFDB375F8E1AULL, 0x663FEDD6391B1231ULL, 0x9F5CF0D533F69157ULL, 0x8317EEB3BEA438CBULL, 
            0xDAAF62699ABCE5E6ULL, 0x93F61A2CA3520495ULL, 0xAF2CDC9DAA7A10D8ULL, 0xF386932CF85A793DULL, 
            0x0D3F40F843D9ECA5ULL, 0xD537FCAB05E78AB0ULL, 0x88BB52B98F265527ULL, 0x818E5D45968A0206ULL, 
            0xDBDBAFE4C6E23EE0ULL, 0x896755D0D3B47338ULL, 0xA6ACD4393D9C9746ULL, 0x7AD1491FE347BA59ULL, 
            0x036D09E6EAFA4A99ULL, 0x4103B11A8B90B45EULL, 0x91F354FF92B90184ULL, 0x40668DD5AE6C4633ULL
        },
        {
            0x3D61C6CA3DEFE452ULL, 0xD8E0FF7B900F61C4ULL, 0xF8068D69ABCAFF24ULL, 0x42B2BAD61551A288ULL, 
            0x8BD5FDFF568A6FDBULL, 0x4B8B990AEE371804ULL, 0xA462543564006108ULL, 0xBC82085629D124C4ULL, 
            0x09FBCAB528566CBEULL, 0x43854C686ED5315AULL, 0x0691856E938E4C40ULL, 0x2DC5C73966B5B6EEULL, 
            0x02DEB5274777B0CDULL, 0x531D2F644CBAC6F0ULL, 0x469CF45968BAE410ULL, 0x13BCF6336B5B45A5ULL, 
            0x258E5F01912B791FULL, 0x5CF36B27806D9380ULL, 0xA3D6281F5716D745ULL, 0x6DAFA71DE335DD2AULL, 
            0xBAD59E40537B9FC2ULL, 0x272ED18ABF8C6E5EULL, 0x4BF824EB5DC78C54ULL, 0x1AF66DBCCCF4903EULL, 
            0x72617D41FBA94028ULL, 0x36A9EB6324D4103CULL, 0xF8E033A526A45293ULL, 0x01F2A1D48591D82DULL, 
            0x491E0698C9A2363EULL, 0xFD964C9BEE85F80CULL, 0xA4191335D481E6BFULL, 0x9C668CD364FC3E76ULL
        },
        {
            0x1A3C4E3AE9754205ULL, 0x9F4A8627E3F1BF92ULL, 0x1F5CB57BC7357804ULL, 0xD50DF5BA902C3E49ULL, 
            0xF4386E25126D7156ULL, 0x2AF817C0CF767FB5ULL, 0xE36949364554BE91ULL, 0xA7D6DBCF3991438DULL, 
            0x302CEE64533B3F3FULL, 0x880BCEF57C19FB30ULL, 0x84D36034B3797754ULL, 0x7B69818BA2517A09ULL, 
            0x2FF7AA1861887E95ULL, 0x5E02E617AC79FE19ULL, 0xD61DA16D1A561B91ULL, 0x8B8F514AAB34CD8DULL, 
            0x228AA9D494B563EFULL, 0xA73EF9A7D63DAEC5ULL, 0x1A72EB812C2C7642ULL, 0xA7323067C6C8B72FULL, 
            0x1AF37B8DE247436CULL, 0x0F727BD41B207D06ULL, 0x2018AE2C858E532DULL, 0x11A048E090B86064ULL, 
            0x80215104379409C8ULL, 0x1DB0446C95BA34C4ULL, 0xBEAD59512B6D34EFULL, 0x56960D1E2F431C0CULL, 
            0x31EB7CB2FB2C4A74ULL, 0xF0010DD5EC5C3765ULL, 0x7AECFE10B9B17314ULL, 0x13BC2301F6E5E913ULL
        },
        {
            0xB260173B686F0E6EULL, 0xF28F4002B76F46B3ULL, 0xEF2DB9F6452E6D65ULL, 0x14156D743A88B9ACULL, 
            0x82C17C052CCCCA9BULL, 0x529C9178D087F7DAULL, 0x8DA0B82614F449CCULL, 0xD0A457E783BAE029ULL, 
            0x8B54DC484AE2B0A9ULL, 0xB07F48CA10D05AAFULL, 0x213B46FE786455E0ULL, 0x72B46056A8DB296AULL, 
            0x84ED5980D12CCC65ULL, 0xF4821C021DF26233ULL, 0xDDCD2D3C85E638BDULL, 0x561367E9917876C9ULL, 
            0x45CAC676CC1746E8ULL, 0xE818569F69CB87E5ULL, 0x6CF5460AF715C6EDULL, 0xA802D155527062EBULL, 
            0x10735E32BCB4183CULL, 0x967BEEDE9A6F90C4ULL, 0xA82989DCD4EFD6C7ULL, 0x4C453E3183F7D8D7ULL, 
            0x42A41F71EA06C334ULL, 0x9C6AC4466CA4272AULL, 0xC3A629E766194B36ULL, 0xC58995D3610B26AAULL, 
            0xAE9E8A156F9CBE8FULL, 0x3D8E96B2E19F49C7ULL, 0x53A126689FAB5707ULL, 0x08A925A05E1F793EULL
        }
    },
    {
        {
            0x91F05A1BAF1A5681ULL, 0x29DDD439B03F4534ULL, 0xEA068FBC3AD5FA05ULL, 0x77AF62393F5868BAULL, 
            0x03E51E582058B713ULL, 0x40D980D5D765832CULL, 0x8FA8390BD2551050ULL, 0x919C0B6FDBE534DDULL, 
            0x4532F9AECCA69D0BULL, 0x3AFF697243C41D66ULL, 0xFE763C6F8FC99C66ULL, 0xD0E7C04E05691530ULL, 
            0x81C7D4DE5557B29DULL, 0x3C3DA8B1E49DBF43ULL, 0x3B43F55C823FFF84ULL, 0x2799B210F9FDC381ULL, 
            0x2CC178BD0438F761ULL, 0x11869BA2B34FB17AULL, 0x964AF62EEAE2307EULL, 0x3DB750B9D77CEF69ULL, 
            0x9A1E580C1C3CCEFBULL, 0xD06B4CD90478DBF9ULL, 0xDB4B04F3C177DD73ULL, 0x22468E4CDBF30963ULL, 
            0x837B61A26C5FFC76ULL, 0x11F672B2FEB965E7ULL, 0xA90BE71FFC95F93EULL, 0x0F72AC9FDBEC42CEULL, 
            0x3C509AF1323B991BULL, 0x0B9F5DE1DCC4FDD8ULL, 0x6ECE4AB695B7CC2AULL, 0x67AA443F2E7BD389ULL
        },
        {
            0xC09AAD4153FA6399ULL, 0xAB70F16CA953911FULL, 0xE87D91B65C00C2C1ULL, 0xABAFA28E0D2492B3ULL, 
            0xC8F888BC92BACF2FULL, 0x8D2EB49950F2DA2CULL, 0xBCD6A93B682712F8ULL, 0x430ABD3C539D7A5AULL, 
            0x02AE9ADA792321FDULL, 0x4C6C0F44A4B8D46CULL, 0xAD2FB8A5B3DA22D0ULL, 0xF736C99E4FD855F1ULL, 
            0x3B7AD0175F061A0CULL, 0x91DB383A70C7073CULL, 0xEA7A938459800C43ULL, 0x90F9DB3821B63758ULL, 
            0xA2796ED16FB6105AULL, 0xECCC72697FA39514ULL, 0xB86A578E9156783FULL, 0x7A8FC8B963E1DA14ULL, 
            0xB0F93B650CCD1FB8ULL, 0x69B730F34DF69566ULL, 0x4AB2F3AD955CAD85ULL, 0x4D0ABFCA579E739CULL, 
            0x3C47C8606FAB6DE5ULL, 0xC1BDB44AF48EBF7FULL, 0xD52D55F4AC1A36E6ULL, 0xD55ED2BD92DB12F8ULL, 
            0x3D781F7133A33F69ULL, 0x430732A0F6103FAEULL, 0x9E1B71D9EC61B0F8ULL, 0x294195F40EFF8FB5ULL
        },
        {
            0xDA661C8E96547273ULL, 0xEE87AE4E223F314FULL, 0xD3BF74D4908105DDULL, 0x85F467CB295DEAFDULL, 
            0x6C7A799B330B4F57ULL, 0x69E972A4A1B92942ULL, 0x4517036E16294A09ULL, 0xC284B01CE889D555ULL, 
            0x94B0678DAA54F6F4ULL, 0xFFFA2C659E533265ULL, 0x700AD669F0E7F925ULL, 0x567BFAF24F9DC900ULL, 
            0x26DB654E4E3FACB2ULL, 0x3506BFDCAF502B17ULL, 0x58F9E5DFD38B4A40ULL, 0x6F89D16FBF4D1247ULL, 
            0x613B09420A1C2605ULL, 0xFD82EE4916D1BA5AULL, 0x1889A982A1D8BFE0ULL, 0x88E892DB978EA6B1ULL, 
            0x2356758F2E177625ULL, 0xBA09DAEB1E64E5A3ULL, 0x247EA41FD5AC7A6BULL, 0x46FF5FE718AE2AF6ULL, 
            0x077878B18B8CC0A0ULL, 0x84C4046CBB7CADF3ULL, 0x4A2DD9E04EC98009ULL, 0xA967CAA24F055CF5ULL, 
            0xE35BFE949F5E4D26ULL, 0xD6BF78EAC38DE6ACULL, 0x1AFCDE6B3B9BFCB6ULL, 0x964B06324513E777ULL
        },
        {
            0x1CD4B6009208141AULL, 0xDEF69A1DC18FB955ULL, 0xBB2FEFD426211298ULL, 0x1334F1A9E33F4326ULL, 
            0x556B69CE039CD3F7ULL, 0xF969DE4BBF177C80ULL, 0xA9F1B3A56BEB46DBULL, 0x8D8A319E2E063F53ULL, 
            0x085672A0D84C3BEAULL, 0xAB0B8305181B82FCULL, 0x1C9BE1CC36948141ULL, 0xC5A0305D2EFB7639ULL, 
            0xEA493F04E19788A3ULL, 0x70AD6DEE56B94041ULL, 0x43B3311118FCE5E4ULL, 0x4D2AEBBC5D89F5CBULL, 
            0x4F1E9E79A867CA6EULL, 0xB14800F80B8C8C84ULL, 0x8705E929F2121DEBULL, 0xCDB14BD224F70DBBULL, 
            0x042C826F14FD11F1ULL, 0x074BF3A577480D70ULL, 0x1CE842843B4684F3ULL, 0x9E59C2D124B78512ULL, 
            0x8F4661059FD65148ULL, 0xFA3EF796C00E8D2CULL, 0xAB5355A6A974145EULL, 0xB778F45C897099BAULL, 
            0x2F3F93319478A597ULL, 0xB4178737901D5BFDULL, 0x0BB6DA97E68373A0ULL, 0xB3D9C4E507811B9DULL
        },
        {
            0x14545E895ED8947BULL, 0xEDE7A61F313D5265ULL, 0x385209095A01855EULL, 0x841BF5FFF20BCCAFULL, 
            0x5C872D464284B0F9ULL, 0x167150F2DD240079ULL, 0xC9A27C0F7DEDF3B0ULL, 0x2DF7C6EB531C8504ULL, 
            0xB6BF82EBC43155B2ULL, 0xEE5F058BA7526A05ULL, 0xE726F1EE1B87D6F0ULL, 0xC29BB66CF60C65AFULL, 
            0xF61F94688C8E05A5ULL, 0x4AD6BADB288F1B5DULL, 0x9AB434609C9DE872ULL, 0x10AA170347251C01ULL, 
            0x25AD7266CAF7504FULL, 0x8EEDB7620AD6AA28ULL, 0x4D502F2B1C5F89D3ULL, 0x6E0966322069F40BULL, 
            0x62E8144A3CECE7E1ULL, 0x7E5257A82C3EDB21ULL, 0xEFC41772905A5DA8ULL, 0xF72A121B8B778919ULL, 
            0x483618FC0DD3A975ULL, 0xCE2043812815FFA4ULL, 0xFE4EC7AD40E55BFEULL, 0x7949BC105ED4EFB2ULL, 
            0xD4CE49CDA8624598ULL, 0x2541D7E1DA78588FULL, 0x40EE68737AC81A9CULL, 0xC988AE7D31A90189ULL
        },
        {
            0x190A5950B52BDBA7ULL, 0xD152AB0485893B5EULL, 0xDD988F13055A9E41ULL, 0x6507C99FD200F0D4ULL, 
            0xD3603B49A4CDC44EULL, 0x494618495198465DULL, 0xFE8F2DE183D0EF0EULL, 0x92408CC6626CC0E7ULL, 
            0xEABE8CCD485E39F3ULL, 0x82EA7C5EB3C3018FULL, 0x487E5375642BBE60ULL, 0x38996B1FCB08F9C4ULL, 
            0xC23DE33E1D79308EULL, 0xC338BBF42B5E8FA5ULL, 0x89B4166C3A7FF10DULL, 0x3BA7AE315A50DA02ULL, 
            0x526C0BBF57E41C9DULL, 0xE896CE79BA68BD72ULL, 0xE7E4F29578CEB9A5ULL, 0x27EF78EBE657B5E0ULL, 
            0x0ACF3AD08513BFDAULL, 0x8C68DB0BCD94EBAAULL, 0xCB362A67CD4D77E8ULL, 0xC3CCB7D082C0FC3DULL, 
            0x6138F50FADE2E987ULL, 0xA15A728D66E11E13ULL, 0x4B097B3A1B51A421ULL, 0xE82A341124D2C8CDULL, 
            0x5FCB3DC815BCE391ULL, 0x496C1FF8494F5246ULL, 0x82C3A46B339579D6ULL, 0x62E7882B20120D28ULL
        }
    },
    {
        {
            0x9E6FA54B83A89923ULL, 0x9C18E95922FD4A95ULL, 0x2A178EC51D3B16A0ULL, 0xA3210CFC5034DDF2ULL, 
            0x7FFD031014996D6AULL, 0x8528886FFD3C745AULL, 0xC63AD6968D7C2CF9ULL, 0xE31CC9C052DC4274ULL, 
            0x070FD4E07CA3E534ULL, 0xC5D791C617E2FB88ULL, 0x5FFD51F115C442F1ULL, 0x8CC27D36A714F821ULL, 
            0x9DD7B80196B44E8FULL, 0x79122B3322FF369AULL, 0x598B973A69C1EEB3ULL, 0x9E2782262F971EBEULL, 
            0xEF6531E63FA46B82ULL, 0x9E5E4664EADBB52BULL, 0x145072C95EFA31D6ULL, 0x8F03C1F44D00C458ULL, 
            0x403311006AECEAC5ULL, 0x6834DD0D025A9010ULL, 0xCAF172154EBED367ULL, 0xC0D2AB672D2CF9DFULL, 
            0x9B1A233FAA5B52E4ULL, 0x99C51EAC80975B35ULL, 0x30BB4352C80B9741ULL, 0xE6207D3FAD72FF0FULL, 
            0x3A944EB87F03F995ULL, 0x50DFCB7086CE7058ULL, 0xE2FFA1C23DAA9BA3ULL, 0xCC30AA6D109BCF93ULL
        },
        {
            0xA4019D5D40DF890CULL, 0x0114E67BFAE1FD50ULL, 0x66EA21C9AF758BAFULL, 0xD0DEF3EAFD6A97AEULL, 
            0xF6BB04B64A269BD7ULL, 0xCD8FBD85A4B48DE1ULL, 0x3303456EC199730DULL, 0xB07EFE73C553AFFCULL, 
            0x6AE02148AB87925FULL, 0x3833926EB4EF5A31ULL, 0xE714014A6887EDF2ULL, 0x5C8D8B33206A1700ULL, 
            0x6B6C3C56841643D9ULL, 0x2350F05D9E94A988ULL, 0xF6AEA79FED1E2A6EULL, 0x71CEAC784E4069EFULL, 
            0xB994A335E074C925ULL, 0x2B920B2056B5F6F5ULL, 0x651704E705C42B9FULL, 0x2C013369BD6840C3ULL, 
            0x457A9481DD3B742BULL, 0x1728F1C9BFFDC711ULL, 0xE6C8E774B2C8FC17ULL, 0x3774B1A595A00889ULL, 
            0x837CF2204872CD61ULL, 0x1856440B54E2F511ULL, 0x5F092F1A468FC9F4ULL, 0xB2369DE768CFFC80ULL, 
            0x26D97D92F5F09D94ULL, 0x38F8E9D4B1019960ULL, 0xB989BF8942B0B6FDULL, 0xFA30FED1EF4C08A9ULL
        },
        {
            0x4A2E105EB041F813ULL, 0xF5173D09B5C31380ULL, 0xFF99C43E8E19DBBDULL, 0xD99270D71F4D4424ULL, 
            0x5D9693D623AB067EULL, 0x460B259CBA550804ULL, 0xD3792539121165D9ULL, 0x93B20872E3367CB3ULL, 
            0x5880CE66998075E6ULL, 0x2B16D73FFB5086E9ULL, 0x4C9CAFA90CE0F484ULL, 0x65B831A28177621EULL, 
            0x0099B24FD0ECDC76ULL, 0xCE5A539D96880A61ULL, 0xF1B6EB50D97E4AD4ULL, 0x66D4F716376A48ECULL, 
            0x30EB8CBC4018532CULL, 0x688CBB9EB9C26EB6ULL, 0xE928B76F91E98145ULL, 0x82BA5D5B4D3482EBULL, 
            0xB078BFF836F3A85DULL, 0xD21C6D145B376CE8ULL, 0x0F61C6CF9530970CULL, 0x7F4C63A153B0520FULL, 
            0x5D0307492B25B0BEULL, 0xA6B44B8EF823E5A6ULL, 0x030730053FD54706ULL, 0x83B230ADCC5DF736ULL, 
            0xC62B679900EA110CULL, 0xF2061B52256C1336ULL, 0x709EC39FD59BCED3ULL, 0x647669B12AE58370ULL
        },
        {
            0xA93C90CDD5C60F74ULL, 0xD1559DC62F8426FBULL, 0x1266EDAB9DF63851ULL, 0x168EF8BFD4157B9BULL, 
            0xD9D2CB92AF0675CFULL, 0x934DB7A3817AB26AULL, 0x307387BDE8405DCDULL, 0x1BF39453767D31BFULL, 
            0x70D387749925B1C5ULL, 0xC7BBD2303A1D3517ULL, 0xA65349D959CBE8F8ULL, 0x1F78F61F6304A8DEULL, 
            0xA14DBE5952895EB1ULL, 0xE5DAC5C4F2E2B56FULL, 0x9A3287F676868B6BULL, 0x2B06BBC94C7E4218ULL, 
            0x2A1180CC7B724A13ULL, 0x877BE25DD9FBF914ULL, 0x77805CB5187953E1ULL, 0xB2607C9689236903ULL, 
            0x9265E5AB6C6D846CULL, 0x59419EAE1640AC60ULL, 0x0B1B1D5B3A76B459ULL, 0x744248CB358EB460ULL, 
            0x11EC3481278B07CEULL, 0xD81081CE5B66401FULL, 0xBD98E71D687984D0ULL, 0xD38470977835DEEBULL, 
            0x5F9B103813448820ULL, 0x880E14087DBED390ULL, 0xB5B45E4A9B6ADC4CULL, 0x3057E58DB92EDB76ULL
        },
        {
            0x401A9A06DFCA53E9ULL, 0xF998BB2BC6D3904AULL, 0xD3DBEC71CCDDED5AULL, 0xFBA85607F7C8C405ULL, 
            0x81C91A436DF8ADA6ULL, 0xE69C88FE9E87F406ULL, 0x8E04134F5248B1D7ULL, 0xBB70E4C2ADFD1EB8ULL, 
            0xC31934F016D2D0DAULL, 0xD87D471B3D541CA4ULL, 0xDEF1CDFB266776C7ULL, 0x0206694CE66BE5FFULL, 
            0x9751B516E9D5F148ULL, 0x8D689E14640BD187ULL, 0xF3019922A47896CCULL, 0x29CD65EAD2C47E90ULL, 
            0x988636C7D8701E6CULL, 0xD663F655C134AEB7ULL, 0x564B65EA5764169DULL, 0x05F48AEBC8231228ULL, 
            0xBC65E0887BE08BD4ULL, 0xDB1522A32D20C182ULL, 0x6FF615CC6AC978A9ULL, 0xC8C127428C6081DBULL, 
            0x453A5CC2050C3C1DULL, 0x00145945FE14E5BFULL, 0xF45BC9E618DBBDBDULL, 0xC058324C8810CEB7ULL, 
            0x592D8699E582F019ULL, 0x5933FDEF9D978728ULL, 0x3D074D3EA02509AFULL, 0x4E3D69BFECDED8DFULL
        },
        {
            0xE826BDEB4FC5EFD4ULL, 0x032BC511B2320473ULL, 0xF99754C0D291C44CULL, 0x014D59BAF5F52ED8ULL, 
            0x15927B9F7A80B037ULL, 0x31DD1D7C70E4F25BULL, 0xCC71BC240358B718ULL, 0xC7A4E28C2D14C6FBULL, 
            0xB9B8164C353BA0B3ULL, 0x7093C31DDF85709CULL, 0xDCEB1CAFAC13C75EULL, 0x713C29E814059DA8ULL, 
            0x581DF73A8FE42768ULL, 0xC75E09E24908F29EULL, 0x29EF45FFCA22AC55ULL, 0x01C3B0A5FD1DF3AAULL, 
            0xFC7E94C24D78FC9FULL, 0x2714C5903E0308ACULL, 0x183B916408625401ULL, 0xF4AE4EB3DB4DE43EULL, 
            0x468491CCD5EED9A7ULL, 0x655AEF265B4042E9ULL, 0x2994BBB6011A2698ULL, 0x4E2DB287794D558FULL, 
            0xEBD77424FA8BA7F8ULL, 0xD842CA3B744EB84DULL, 0x4F4D80A6D25C8E21ULL, 0x388EDD6FFA431769ULL, 
            0x615F799181ABB0A3ULL, 0xAFEF142838E779EFULL, 0xEAB002BD90F00749ULL, 0x8EC596962C04D6FCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseFConstants = {
    0xB5C737FE00F90530ULL,
    0x4B5E25E2D439403DULL,
    0x1D63CFC55B9B9BCCULL,
    0xB5C737FE00F90530ULL,
    0x4B5E25E2D439403DULL,
    0x1D63CFC55B9B9BCCULL,
    0x9F112021DBC5D634ULL,
    0xB50B3C0F3CF3CE89ULL,
    0xD5,
    0x9E,
    0x0F,
    0x3C,
    0x77,
    0xAD,
    0x5D,
    0x86
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseGSalts = {
    {
        {
            0x1337E90FD468FC90ULL, 0xD6F576B700216ADCULL, 0x56155CB0D2B78A6DULL, 0x0ADB2614E8EDCA4CULL, 
            0x8D6A3805FB6149CBULL, 0x4DFF7343C8D89C88ULL, 0x72A2C03CDC02A8FAULL, 0xF78919AF16F90942ULL, 
            0x9080BA6F259C67DBULL, 0x6EB54248AEA6600BULL, 0xFA7C18D288F7BCDDULL, 0x1AC9BF1849D50C7BULL, 
            0x54E19960B71E6860ULL, 0x46B2BFF5E044CBC5ULL, 0x89775BC0922CCB63ULL, 0xCE4E570CE6C8E06CULL, 
            0xC05E71AC8B2FFDEFULL, 0x7D110EAC0D77427EULL, 0xBCDE4F902001CAC0ULL, 0x3033C9B25BD08220ULL, 
            0x3EE0AA52B63F68C4ULL, 0x807C43784EE4F412ULL, 0xE15DE1BBB7D27EA5ULL, 0x6A32E75C3067BAD4ULL, 
            0x255CF540E147EC57ULL, 0x64DFA117A8D99A7DULL, 0xF15489F870D45AB8ULL, 0x71C54ABC306EA5D6ULL, 
            0x244D9DE24C8E46D7ULL, 0xE3728CA6C0E8BBA2ULL, 0x96B7514111B6F6AEULL, 0x005544FFF597ED9CULL
        },
        {
            0x9643A70791AF25E1ULL, 0x99009A5928BA2CB4ULL, 0xAAFA013086C1B921ULL, 0xA8F2A677659C4F31ULL, 
            0x4243BE2E2B6CAF0AULL, 0x53164FDE684AA8F4ULL, 0x7F7239210D2DD285ULL, 0xB838FBDD59FB14B3ULL, 
            0x6FE0DB19C20E584EULL, 0x42E4617F5B3B9F5BULL, 0x555D810C4D82B9B9ULL, 0x9384A4765DF81AC8ULL, 
            0x0C828A9CA553E8D8ULL, 0x22C38FB67C83D268ULL, 0x2FD0234C5A2C0B70ULL, 0xC55F35B8EE503575ULL, 
            0x3C205CBF9A07DBC7ULL, 0x80B69B7C8C3F5151ULL, 0xF04A6DCC09A7C30AULL, 0x6FCE9E2C352BE8AEULL, 
            0xFC916C8F3F468AEEULL, 0x6F1F85F60D03FE6FULL, 0x3C2DFC6F5B303207ULL, 0x6B46940C3EBB9F08ULL, 
            0x9962E7AEA5DA2A59ULL, 0xF701089D3E6F8BC7ULL, 0x1F0EED6496DDFDEEULL, 0xBF0555FADFACCCD0ULL, 
            0x6E560A0DA972B9B0ULL, 0xB1A4772F6A6138BAULL, 0x21CE128BF644DD9DULL, 0xC3975487533891D1ULL
        },
        {
            0x34EAE7452827509CULL, 0xDAC4A47E8340D79FULL, 0xEC9D23224EACDD8AULL, 0x1E89CB25F9D24EE8ULL, 
            0xD83F6E184551733CULL, 0x10642DC61629EA64ULL, 0x64137A61BF15D130ULL, 0x7F845D6C06B4CAA0ULL, 
            0x8EB2E527ED82F57EULL, 0x592AA2EB3646D815ULL, 0x759836D89DB13039ULL, 0x0DB32EA36D2A0FC3ULL, 
            0x74E5C4E3BED69C4FULL, 0xA15829CB7A79AC48ULL, 0x3ED73C9D9B4C43ECULL, 0xFB077C82B436853AULL, 
            0x3E83378A7F8C7564ULL, 0xE71D1803550A0193ULL, 0xDB1A2EDD9C866CB0ULL, 0x2E31CD1C0F189452ULL, 
            0xCB5FE4C030C43142ULL, 0x4ADA1B51AC47765BULL, 0xFA2A95F1364A035DULL, 0x70B91E4A784BCC19ULL, 
            0xEDCE548A27A72113ULL, 0xE8D13C874217067DULL, 0x294251F0F76D26DCULL, 0xDA1F01A9E64167AAULL, 
            0x15CD4CBFEE354B14ULL, 0x3471359267D49033ULL, 0x66C464377EC0AC09ULL, 0x0E3B2E2C5DCF9870ULL
        },
        {
            0x08C97CC1B79AF863ULL, 0xD8A1C0374F521089ULL, 0x0B5A14A2AE0C1FB7ULL, 0x5F0A578311F734DDULL, 
            0x05571E26EC0897C8ULL, 0xD4C782DE34C9283EULL, 0x61B1AC6E2EBDECF7ULL, 0x038294C54596C032ULL, 
            0x0515A910D115DA6DULL, 0x853B4FB4FA1994DDULL, 0xE5161034B1894490ULL, 0x1D4A1850FC8C80ECULL, 
            0x69036F5D35D6EF9DULL, 0xC96505C5A8024682ULL, 0x619B523FD4ABE6A6ULL, 0x514C2E843463CF79ULL, 
            0x1E2C0F97E8C03C20ULL, 0xE32397253A4F982EULL, 0x6D62736740C9589DULL, 0xEAC443544E3E066DULL, 
            0x9863E8B7017CA8C1ULL, 0x93741AE38830B106ULL, 0x2507964F5A351D9BULL, 0xC9B856D11ADC1C5BULL, 
            0x229309750CA03269ULL, 0xB2070A5C2E6AD08BULL, 0x59E72543BE1BB479ULL, 0x5D8F2C12CE17EB93ULL, 
            0x18323B5D0FC9507DULL, 0xDFDF288F697B7D9EULL, 0xCBE635EDE649BDD7ULL, 0x0BE9B4279182C656ULL
        },
        {
            0x9C8F66A56F9C3697ULL, 0xE613110E1007169CULL, 0x9E0CD17C6C69A09AULL, 0xBE164003371C5C12ULL, 
            0x4DB9B2ADF8DB7070ULL, 0xF266935C4FD23E5BULL, 0x973891B1EEF96FDCULL, 0xE83F0F97FC2E3F81ULL, 
            0x25B74C57AC9D77A9ULL, 0x20C796BF7E16C6F0ULL, 0x45A820340FEB0712ULL, 0xE13E25D205CF84B2ULL, 
            0x6D4036845E119A88ULL, 0x0D39AFFECE334560ULL, 0xF8F42073530647F9ULL, 0xB66352D6F82122AEULL, 
            0x2445652DC9AE0406ULL, 0xCF066DDC7B09B8DFULL, 0x753D4165F7953C60ULL, 0x366D0FFD930D4FB4ULL, 
            0xFC10A8B6C4CD38E5ULL, 0x5BCC575968399CAFULL, 0xEF913E026C34F667ULL, 0x00F247E042F65B5FULL, 
            0x1A8FCC48DE588C14ULL, 0x6B4A58F5654BE6CFULL, 0xA209B65015297F0BULL, 0x4427E85348B11D88ULL, 
            0xB0B55DC23605E89DULL, 0x360B570A89092FEEULL, 0x6AD2E7F31B094128ULL, 0x316A04F593B0E275ULL
        },
        {
            0xA9A478FAE60634DDULL, 0x4923A360496BAF9BULL, 0xC5286F730E24BBF7ULL, 0xB1140DC58BD1301AULL, 
            0x3FE6AEE4E7161617ULL, 0x554B3C4A62C56EDCULL, 0x7AE43D15550E78D9ULL, 0xFF8F337CF8F1A013ULL, 
            0x1969333A11A19172ULL, 0xC2DFAE185D47C59FULL, 0xBAB2DEC60941AEF6ULL, 0xA43B28FC5F54DAA9ULL, 
            0x1CE89BAC6528A277ULL, 0xC9C416049B15628AULL, 0x79071DC6B73D71FFULL, 0xCBF593C9EB99C91BULL, 
            0x4AFBB6B24BACFB06ULL, 0x40B5C8364C8E4666ULL, 0x362AF7FA9A17E9DDULL, 0x49381C3A18D34672ULL, 
            0xA8C4BA4DED0B1EB9ULL, 0xE28FB998D95498E7ULL, 0x3DE990A771E790B6ULL, 0x4168AE6F11E4D19CULL, 
            0x6678E34A969C01ADULL, 0x10C8D175769B8605ULL, 0xB7A62752597BF4CAULL, 0x98962F154C846272ULL, 
            0xF4776AA2EC8CD4DAULL, 0x360AEA63F9B41BAAULL, 0xFC4B33F671CB3FCDULL, 0x21A6593C5944DFB3ULL
        }
    },
    {
        {
            0xA5D881DAD0E20D63ULL, 0x99D032F2793CBC65ULL, 0x7E82755D850081D2ULL, 0x90928F91A85E625CULL, 
            0xB1A791B75FD22505ULL, 0x9EA28CD2040F2F80ULL, 0x32B780C7332174F2ULL, 0xDB83E585DBEA1CEDULL, 
            0xA56DED5655CE502CULL, 0x175C1B1A84313B3EULL, 0x7BCED07A22BE67FAULL, 0xFC5690BFEEF08059ULL, 
            0x093BC60BFC813E4AULL, 0xD679047D4E4A35D5ULL, 0x91AAA79B2DAA8AD2ULL, 0x3D6639CA6001A0E4ULL, 
            0x3C253A6D8F0453C2ULL, 0x0FF1046A6E0B9B9DULL, 0x3080484DBE7E98FCULL, 0x83ABE551B1BC8FC1ULL, 
            0x7D115381E8D2A230ULL, 0x8770A8C881464D90ULL, 0x003FACA34A5F41FEULL, 0x3333038F7574728CULL, 
            0xCE1766B72358C72EULL, 0xCD82017DD0C1C84BULL, 0x3F9643C4170CB517ULL, 0x08A8EE4E5C9A3688ULL, 
            0xD30DA8106E166439ULL, 0xDE064FC70F7C1E14ULL, 0x4A6386E13D960C91ULL, 0xF0BC9D3C2E70A348ULL
        },
        {
            0xBF8A714AA4B4696BULL, 0x820880A9E176BCB6ULL, 0x8F858C177B3F2D04ULL, 0x4AFD496024BDEBBAULL, 
            0x9C1F22793C821BDBULL, 0x1650256D4ABEF070ULL, 0xA37B6D3F417CE015ULL, 0x5E092D39935516B5ULL, 
            0x25EF60EDA1300B4FULL, 0xABEC8038225811D5ULL, 0xF68BBB3C7CEED94CULL, 0x33ECEC9D4DCFE8E4ULL, 
            0xA40785F843C14311ULL, 0x0D576841F88A2777ULL, 0xBA5458B93F00AE03ULL, 0x3AF5234EE8DA1DF6ULL, 
            0x1AFD87D9FDF5D6ACULL, 0x46B1A6E7A529E895ULL, 0xC9381D06079851D0ULL, 0x73D0E29437591610ULL, 
            0xDFA927BD41175ACAULL, 0xE03E732EF4137F84ULL, 0x9278E7358600694EULL, 0xE58AFCAE253C92D4ULL, 
            0x3F956BBCA2A13717ULL, 0x511A9C6A3A497A07ULL, 0xE91AAAC94148F7ACULL, 0x0D70817DB3E5FB27ULL, 
            0x328EC15842DB6E4EULL, 0xCF999EE10C5723DEULL, 0x45B429F984622DCFULL, 0xC02CC19084F4A360ULL
        },
        {
            0xAFFB0E343F726F6BULL, 0x1AF2E068CAFE7D79ULL, 0xBE619411D76C11FEULL, 0x30022B758F0E9B1EULL, 
            0x60B068BC1497F26BULL, 0x14DDF35706937545ULL, 0xE42B23B522124753ULL, 0x1981ED789309D839ULL, 
            0x07DDBFAAE1F24C9DULL, 0x0CAF5EC0D1F576CBULL, 0x443E87DAC4A009D0ULL, 0xA36A94A503F9F3B0ULL, 
            0xDCFC57549716A416ULL, 0x1142537763128930ULL, 0x27E9987DE6955709ULL, 0x6A1E48946EBEF2E6ULL, 
            0xB710E37A98274840ULL, 0xFB75A0F81701B675ULL, 0x5C26EAEB6F28D81DULL, 0x9B2FE7AE75896E3BULL, 
            0x3F2D7587CEDF8A13ULL, 0x9E0AC2A96FA90863ULL, 0x27D9C64B0D4DDBFFULL, 0x27B4892FDCB3D7D6ULL, 
            0xA0371C06408E5148ULL, 0xF77DF269C6106DDFULL, 0x6BF989215E70EE36ULL, 0x326103B39B2CBEB1ULL, 
            0x7649C1A99C3BF1A2ULL, 0x3B2A8198CF0D4CC5ULL, 0xBD6FCC74EC16B4BDULL, 0x3557437BCCC07C92ULL
        },
        {
            0x13288DEB281AB130ULL, 0xC6984D3B768FAC91ULL, 0xF5C0157711596005ULL, 0x0DE569F0C4774B05ULL, 
            0x7D7EF45A33F2DD81ULL, 0xA200606F3A8853C5ULL, 0x6B1EE36241953351ULL, 0x7330505CD96378DDULL, 
            0x79816D5DEDC7A729ULL, 0x31E4F9FCA10773DBULL, 0x68024032A2AE449EULL, 0xD8FA6AA3A8D1CEA9ULL, 
            0x259D18EED8266FCEULL, 0xA3E951088EAF2660ULL, 0xCF4399BF1C4606E1ULL, 0xD04251E46DA441D7ULL, 
            0xB279922D94EAC0B7ULL, 0xE152A8C92AFE2F69ULL, 0xC32C4E472C7A2FE3ULL, 0xC5E57AC1FBFC6538ULL, 
            0xBE89B1CB4CED9463ULL, 0xA437D4FE62CCE43CULL, 0x5514465A5DE91572ULL, 0x8D7AB74B3427C31BULL, 
            0x80A276C4F13BE7A2ULL, 0xB0641DD2FFE8CA8DULL, 0x9CFF1948BDC8608BULL, 0xDFBD08AC9A6E8E36ULL, 
            0xB268A1B15205F58BULL, 0xE9457F7DD4E3E711ULL, 0xF8D2F18F33EB49A5ULL, 0xFD65F0E586CF66DAULL
        },
        {
            0xB656F9D8CC7C99B9ULL, 0x8D348072E25B4747ULL, 0xE284E6F3F6BB756BULL, 0x633356D5451BA6C3ULL, 
            0x1C434DB6DB856CEBULL, 0xC74834C9221C9FADULL, 0x7D020CC7419F9D76ULL, 0xE41D53AAD740F9B7ULL, 
            0x97667BE36C7B7E2BULL, 0xC953079B241FDBDCULL, 0x43CF479428B6418EULL, 0x1800F47F4C14BA1AULL, 
            0x1984A91ADD80E1FCULL, 0x9C83AA9C080AAB69ULL, 0x4A37E9FE89C39E58ULL, 0xFE762E0E6CFAD9F5ULL, 
            0x4BCD33FEBF5213CAULL, 0x44C236B71BCB16D7ULL, 0x7B42590C567B7837ULL, 0xC02897DEDB238F6DULL, 
            0x9B57BF6E612A4631ULL, 0x51E81495E15DE686ULL, 0xFF7A98B208E1B892ULL, 0x74B9A9AE760991C5ULL, 
            0x77A5799CCB361DE9ULL, 0x0142BA42914C37A5ULL, 0xDA0D8632492A36FBULL, 0x041DA4259C8647FBULL, 
            0x51AA64D11306AF22ULL, 0x342BCC6A2A2CEEE5ULL, 0x9903C3E8DEA85227ULL, 0x08FABBB0AF9D6192ULL
        },
        {
            0xC63031E08609CAB5ULL, 0x0B21402A8E6C1A35ULL, 0x282F0EB61BDC3646ULL, 0x2ED1DAD3A7EBF4C1ULL, 
            0xAA5994C77B3FE530ULL, 0x3721A29155E07574ULL, 0xBDB62B211FB014E7ULL, 0x43F7BC73A57C93C5ULL, 
            0x1D9D4ABBDE7D8808ULL, 0x79E49E1A41AAD55AULL, 0x757733EA63DBB195ULL, 0xC10176674855D0E6ULL, 
            0xF6F64E7512CA211DULL, 0xCA303305901CBB62ULL, 0xFF5C03176FE6EAEAULL, 0x500D31087F65BBD5ULL, 
            0x354D93B49C056703ULL, 0x5A6A4F19CA6688AAULL, 0x2B32B75DFD6D3465ULL, 0x6ACC70F31500DCEBULL, 
            0x94A620578A873D64ULL, 0x4D194BCFF2B4B99CULL, 0x523A4278DFCE8DD4ULL, 0xA9D7BD9F019CBA90ULL, 
            0xBE8D9D12BF40E18BULL, 0xC00448E484B869E9ULL, 0xA197D1B7F438694DULL, 0x2EFD7378274ACA3EULL, 
            0x244599DE16FDC1BDULL, 0xBD8E000CEDE5AFA0ULL, 0xF1496146D764D41EULL, 0x5EBC43C147F2D6E5ULL
        }
    },
    {
        {
            0xCF32FD3B6C7DF337ULL, 0xB44AF7CDEAABA447ULL, 0x14C4763CE859F06FULL, 0xDEDB425E12859A27ULL, 
            0x9F4CDA04C7133156ULL, 0x58A92744E5061698ULL, 0x04423579FC98E219ULL, 0xC1CBD08EE31E7A43ULL, 
            0x67E04E392D41AB65ULL, 0xBDE62254CCEA84FFULL, 0x157CB6681FF09517ULL, 0xF1CD06EE7080FF9CULL, 
            0x2A8804077C93DA85ULL, 0x9A37D5D787918556ULL, 0x0F801B1938DC41C9ULL, 0xDC51540DC1C21D7AULL, 
            0x219B98A2D36542E5ULL, 0xEDF33457265F90C9ULL, 0x47FE0BF39911DDBCULL, 0x7660E88A44D5788EULL, 
            0x8A2B3BFE9BEA62CDULL, 0x431468B07081589FULL, 0x6D109E8B96CF978AULL, 0xBAD436D2EAAADE88ULL, 
            0x009DA3958778F8C9ULL, 0xA88FD9AD7B8D1F4DULL, 0x3662497E9836DD49ULL, 0x66E19F1D59188D7DULL, 
            0x7F2A47F0B2C23869ULL, 0xABCCBE8A21210887ULL, 0x8C279CA6ADA63A3EULL, 0x972A9E4971B42895ULL
        },
        {
            0xC30A7413FAE2A7E9ULL, 0x2DA619A67EEDFDEBULL, 0x857B0A96F411B98BULL, 0x800D7410171CD9DCULL, 
            0x8F0986C0659DED17ULL, 0xB20FB89582C8EBC7ULL, 0x8670F6841A17ED09ULL, 0xAA28ED7A8BBFB8B4ULL, 
            0x72C2560EC34F22A3ULL, 0x042AB680538FD1C9ULL, 0xA110CBEC7F832C90ULL, 0x0B9E45ABBF73814DULL, 
            0xB9B6DEF4AF847C06ULL, 0x647270D6C45F60D1ULL, 0xCD54BA2028157A13ULL, 0xC12FF571FE0423B5ULL, 
            0xDFE5C36FE31E7019ULL, 0x8EA5545D6D1BD24CULL, 0xECA192C9A6918731ULL, 0xA0AD42E6951AEAEAULL, 
            0x678F72F662546136ULL, 0x7080387894506692ULL, 0xB6D01D18F6E426B8ULL, 0xC95E49203F5A5D16ULL, 
            0x01BEA16F3F3D4E72ULL, 0x2C9D81510CDA3EFCULL, 0x288D3952DCADDE1DULL, 0x7F3882972CC29AD5ULL, 
            0x2DBC392D5E820C82ULL, 0x4875069FE1FD5F0DULL, 0x55484017B7B3AC40ULL, 0x83144F102B6B4EE1ULL
        },
        {
            0xEC9B70BDA34AE4C2ULL, 0xAF8F32C766A95546ULL, 0xF4F6888E2631F216ULL, 0x9A6B522CECBB43FCULL, 
            0x6584EABE97630ECDULL, 0xF566866000C4A394ULL, 0xBE8B6A88C1F1B7A1ULL, 0xE552AC2583CF98E7ULL, 
            0x63AED1FB16D7C1CFULL, 0x5C94E349DAD60489ULL, 0x82F5A6954552F350ULL, 0x9887A9A97B9D2DDCULL, 
            0xFB9CC673A5A48368ULL, 0xA6811EF9B1935AC3ULL, 0x6161F13D71C3DDEBULL, 0x4A7EDDBA7EB86ED1ULL, 
            0xA641F3033122A5ADULL, 0x07C0363EEB760E08ULL, 0x8E9BF790C9005A05ULL, 0x45FE9B230CCC4467ULL, 
            0x5BDB637A10CF3C65ULL, 0x3A549E52F91E4A51ULL, 0x1D0F1E98292434EFULL, 0xBBA8042B5C0D3948ULL, 
            0x9C4B1B985A26F023ULL, 0x0B8588E52CD6DD22ULL, 0xE5FC3FB8B9D72970ULL, 0x8628FB29ADC594ABULL, 
            0x074245C444BB1C4AULL, 0xA980EA326AF0DDADULL, 0xEC478F7644B80F40ULL, 0xC7BEB1B0FFE54526ULL
        },
        {
            0xCA4051057DF7E400ULL, 0xD016998CB4FB63D5ULL, 0x22AD5D2B0DB0F021ULL, 0x75F364AEB56B9DF2ULL, 
            0xCC394C1E82CFA1E6ULL, 0x54CA29B82E4636C3ULL, 0x5BF472CF045C06A6ULL, 0x0B128F31C5619B7BULL, 
            0x490E59494612A1BAULL, 0x390A0F503C3BA4BFULL, 0x99DB512E8C537893ULL, 0x6A668E124B80500FULL, 
            0xA984D25E626E340DULL, 0x51EAEA90E5671DB6ULL, 0x73261F98AD317D75ULL, 0xA74F7F15E96F0CDCULL, 
            0xABDE11224505D90BULL, 0xCF4522C6370CC5D3ULL, 0xDCC8623FD17DBB5CULL, 0xF74EDE9F55A58797ULL, 
            0x1910566751849CDCULL, 0x3641A2281C349DF8ULL, 0x5C06CEB8573BAE5CULL, 0xFA88100440F9FAC6ULL, 
            0xEAAFF1461BBE707CULL, 0x930CB33B7240B1A7ULL, 0x3238C675556B9F3FULL, 0x5B7107D9C87C255FULL, 
            0xB25FF2470191E502ULL, 0x1B4F4EB11364E60CULL, 0xD985626FF078F43AULL, 0x808F3FBB7892FF1FULL
        },
        {
            0xECD81BEF009129B8ULL, 0xBF6808521CDA05ABULL, 0x41115A772E60F5C9ULL, 0x79658BE7B80F573DULL, 
            0x9230B5981FA4284FULL, 0xB43A49551ACC3125ULL, 0xC5DFF906FFBA3140ULL, 0xFBEE73FE48A79047ULL, 
            0x36C2785B583AC8C1ULL, 0xB5D0D88F6B15DAAEULL, 0x3ABD3447AB5E28C2ULL, 0x1E4C70C8DD5C1AB2ULL, 
            0x27CBFA82CC096BAFULL, 0xFAF8CEE918A5BB7FULL, 0x759F08E87D0F3348ULL, 0xD5D4ED3C9611A5DBULL, 
            0x68FF97128A43F9E2ULL, 0x3A8E54192BA46DEDULL, 0x066124D13DE19FEFULL, 0xA62C0C877780A535ULL, 
            0x148E5864E41EF0BAULL, 0x614E64CC76AE61F0ULL, 0xC4AAE6E8E7482B90ULL, 0x132463C2184CC21CULL, 
            0xCCD8D1F62B401A32ULL, 0xBD7683EC4168071DULL, 0x3441436A4847D366ULL, 0xE5CBA783DD6A2025ULL, 
            0xF97A2767FC13FD07ULL, 0xC88DA2072767C1F2ULL, 0x623E6A89E2A5511AULL, 0x6898BFF8A2163F96ULL
        },
        {
            0xF1B95A273A299CC8ULL, 0xDD9C00ADB9D00FC9ULL, 0xA2C852EB96943103ULL, 0x52EC4F95BF50C959ULL, 
            0x312C09BCBC887522ULL, 0x960519267E30B285ULL, 0x7FA0F160D5C2477FULL, 0x3BD81C4D5E365D76ULL, 
            0xBB2E322F705FD9F9ULL, 0x91DBA444377607E8ULL, 0x4E1DB897119A5BAAULL, 0x5B63ED86A51A9FC3ULL, 
            0xC62A2B1B23703B73ULL, 0xCEB261B97E3EE262ULL, 0x7F5F5AC75F43834BULL, 0x370E83383186D6B0ULL, 
            0x8DAE9BBE568C1A49ULL, 0xF2A19660156D4117ULL, 0xB93B19B2B8DBCDBCULL, 0xB4C8AFF835ABC8BCULL, 
            0x034692258631842DULL, 0x653BBDFB02BF8448ULL, 0x43CADF62B665BAF3ULL, 0x792961567EE67E62ULL, 
            0x07F82853DEBCF5BCULL, 0x979954B9C29A8081ULL, 0xC8DBB47470CC3879ULL, 0xA908E8F1286AB9EBULL, 
            0x649B89CF837DA10DULL, 0xA7FB593EE4DD7849ULL, 0x3C6B4724869C84C2ULL, 0x12C0FA3E583BF0A2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseGConstants = {
    0x17EDD4AF74096712ULL,
    0xC0440662DA4F0CF1ULL,
    0xCAFB6B780A79DF72ULL,
    0x17EDD4AF74096712ULL,
    0xC0440662DA4F0CF1ULL,
    0xCAFB6B780A79DF72ULL,
    0x75E4AA81845F16B1ULL,
    0x096CF2835F07788BULL,
    0xDE,
    0x42,
    0x67,
    0xC5,
    0x3A,
    0xC9,
    0x53,
    0x53
};

const TwistDomainSaltSet TwistExpander_Badminton::kPhaseHSalts = {
    {
        {
            0x63563809EFE90967ULL, 0xD9E52E5953A7C08BULL, 0x897D12FD2F31C370ULL, 0x28374098DCE13A35ULL, 
            0xDC660C7565EE4A9CULL, 0x5F83B5B6C54684D2ULL, 0x020B9EF4FEC70824ULL, 0x29622B9BAF6D1D63ULL, 
            0x3DA1DC8ADBA1B664ULL, 0xDB7070EE04A88681ULL, 0x0BC635659DFC63F7ULL, 0x52F8A8B5095D9E77ULL, 
            0xA6B6B06C414BDF95ULL, 0xD0A1CE2F4FD21ABDULL, 0x858D5359404988DAULL, 0xF1723F24358D1E16ULL, 
            0xE80EEBB7C8A217B1ULL, 0xD5783ADF858D7BEDULL, 0x5271AD25CB5B252EULL, 0x9E0F83D773C82D65ULL, 
            0x12A6E050746D3AA4ULL, 0x5E7A6A07F438FA19ULL, 0x90F084CF4E08C712ULL, 0x733FFCBF482F1E26ULL, 
            0xB41240CDA26D3466ULL, 0x80F44ED9772EE7EDULL, 0x471CE0153577F3B7ULL, 0x5688FF0D1FBEF7E2ULL, 
            0xC7CD6DE422E4AD86ULL, 0x94C845AD8FF2515BULL, 0xF4AD9007A0752917ULL, 0xAC538CB438FC9CD2ULL
        },
        {
            0x12B44C0EFCD2F47FULL, 0x81C291491A6BB051ULL, 0x176F4A29F2CF241AULL, 0xFCF1CF589D6AAA26ULL, 
            0xF09BBF53160C633CULL, 0x7875EFE3EB7E2430ULL, 0xDC1A4438EE9C70F0ULL, 0x37E894CFDDCF4C81ULL, 
            0x30F155F3D105B4D6ULL, 0x0801DBFA064A5AC7ULL, 0x959382801C3B912CULL, 0xD72EC4ACBCF424BBULL, 
            0x5A257099454F9771ULL, 0x9F6E6F6017E65B17ULL, 0x1A9F051DC7F74BC0ULL, 0x56B552B33D7B3197ULL, 
            0xAEFE61E34D3A46FAULL, 0xBB110FE02437080CULL, 0x5571DAB680A9A184ULL, 0x3D924787988737B5ULL, 
            0x34E61280E29E44EEULL, 0x7EBD132DEE029F01ULL, 0x84FE5CEE738D6C3AULL, 0x77C5A6AB06450C78ULL, 
            0xBF87DD1382359F27ULL, 0xA067545CF0B404B9ULL, 0xEB4052FDC145FFF4ULL, 0xB8CC50BFC80D6C7DULL, 
            0x84D45DD5BF868921ULL, 0xD55465437E1B55FCULL, 0x404D30BAA567AC3FULL, 0x9F33F39029AD7A3DULL
        },
        {
            0x0099F8D8300506BEULL, 0x77D4FCD767AFDCEDULL, 0xE3492B05F5451ED6ULL, 0x9473915A44AD2932ULL, 
            0xF5331B2BD332B67DULL, 0x4B011DE4EBF98F97ULL, 0x94B8AC65008A8153ULL, 0xBDDD84B5C5EAB56EULL, 
            0x1351FB9875DE61A5ULL, 0xDFC7B2096A29E703ULL, 0x7773A678D031E20FULL, 0x1700A8EE3E10CC20ULL, 
            0x18DBB8B789924ADEULL, 0x3D232246DDD00ADBULL, 0x237E101A7CC20C33ULL, 0xEAE752D6DF8F9484ULL, 
            0x08B679E2C2FFB522ULL, 0x916B0675A0C3A059ULL, 0xDAE8490E8021AD94ULL, 0x894901D9855908FCULL, 
            0x66FA13317A803C4CULL, 0xC77BFCCB713E3584ULL, 0x5EFB03622353F38CULL, 0x217551636A03570CULL, 
            0xD2F2C79FA6DE6F96ULL, 0x3344AEB46BDF91DAULL, 0xEAEF1F1A1A6D598EULL, 0x23E8007B9F849E9CULL, 
            0x6B4E7E205F0D8813ULL, 0x07B03B02C179FAD5ULL, 0xF1018C4806ABF863ULL, 0xBE9A8820C01D3AFCULL
        },
        {
            0x9677F4A7405DF197ULL, 0xE7C2F5E6C5D5EBA5ULL, 0x573AF82C8F1577ACULL, 0x12D8592BD319CF13ULL, 
            0x71C14466913D5C2AULL, 0x22A79577703C041AULL, 0xD21E61188FBADE3FULL, 0xE23167740EE7DB20ULL, 
            0x34305DA10DE23688ULL, 0x1912406BD2FF5530ULL, 0x59E31A299B562B64ULL, 0x9FDE1975FBA1931CULL, 
            0x1AC17209009DEC05ULL, 0x4094D9BC8081E356ULL, 0x6AF53D6AD2CAD286ULL, 0x3C661EDAB2538813ULL, 
            0x6B3F9BA3D25066F4ULL, 0xC31E0E68F34BE00DULL, 0x95AB4C55777E6493ULL, 0x7EE64012D069F0A7ULL, 
            0x70F5FE6D85BAA63AULL, 0x71348662D47B2805ULL, 0x0A8318A0FF813B26ULL, 0x2F97A0E62EBC690DULL, 
            0xC66BCC10A3196D0BULL, 0x27E73E65E91AF919ULL, 0xC08E845728467E9AULL, 0x9E5D1A742A16794BULL, 
            0x84BC495243843472ULL, 0x14F8980DA185D5C1ULL, 0x0447FC6B5800D07FULL, 0x3E88F3A1B011F9E5ULL
        },
        {
            0x08233C17143137A9ULL, 0x7495AC99C698BC58ULL, 0x6D7A9A2033E9F121ULL, 0x0ACBA3A20AEC2A95ULL, 
            0x43B32711B922038BULL, 0x698113505C46A139ULL, 0x6FDA432BCC3029A5ULL, 0x2C6B9A150C1A22C4ULL, 
            0x06BFB1855FA0716EULL, 0xABB6CE06E3E6F29BULL, 0xDF2E82036C3108C1ULL, 0x36D511BAF306AE02ULL, 
            0x86FF2E987C66EBC0ULL, 0x9ACDA7AF855F9004ULL, 0x6554397A49A0067AULL, 0x20F0407A19602A10ULL, 
            0xE3CEEB1F4A45CDD0ULL, 0x09A624E69FA090B5ULL, 0x34A02466A4FAAA99ULL, 0x7DAD9840443FF241ULL, 
            0xA83154642A057B5DULL, 0x0168FA347163D633ULL, 0x9B66D5EEBEE3A6E8ULL, 0x7AFE641912A57D25ULL, 
            0x572443DAD29FA22CULL, 0xE136709588780806ULL, 0x202D8E64D7AF6B3FULL, 0x153D3C4428E750D8ULL, 
            0xFBBF9F277D904A96ULL, 0xE1C3ADCBB7561987ULL, 0xB49DECB1CD3E9F87ULL, 0x9A6E1C58533F4D68ULL
        },
        {
            0x166208862E13958AULL, 0x6EA331D62C1D22B4ULL, 0x004B0132B5EEB5E0ULL, 0x590984DB6B0DDE36ULL, 
            0x4C0E0A7231917E83ULL, 0x5F687D5D982FD784ULL, 0x89260E60BDE9FB32ULL, 0x50EC8B71BE55453EULL, 
            0x1A74E0C75E5C9DE4ULL, 0x03962A38829C71C7ULL, 0x200251CFC25FA664ULL, 0x8703CCBA20AD9F47ULL, 
            0x98844FA4B9339F4AULL, 0x0A0B34C1DD0CD3B0ULL, 0xD647484C7BE1EBCFULL, 0x2FF68B124E715D58ULL, 
            0xD5E727D5823F6340ULL, 0x6E657D25D7501718ULL, 0x8BB55F0D6BEE564AULL, 0x1B4AF06307731C1DULL, 
            0x7E708EB78515241AULL, 0xF93D9CB2BA17C23CULL, 0x8399B6136EF31A85ULL, 0x991230C8BF464BE0ULL, 
            0x5FD5F6207FA7C592ULL, 0xA9F5A9EFBF3266B6ULL, 0x64ADBDB1D67DE7E8ULL, 0x484FF05DF11E147BULL, 
            0x11C32A6E97527A1AULL, 0x6FBF66522A419027ULL, 0x226D579B2A153BAEULL, 0xDFEB038A8CDFFA93ULL
        }
    },
    {
        {
            0xC73937A8B56BDD39ULL, 0xDE03F61DB7D86719ULL, 0x418689442A8323ACULL, 0x8968E042DFE8BE7FULL, 
            0xDC6C865DB58EA0D7ULL, 0x5A94D9AB955AD253ULL, 0xF6C100A28696B9ECULL, 0x110031FA24061631ULL, 
            0x88C784560A918B1CULL, 0x49651A35B9193A3FULL, 0xE8BAB44CD8487044ULL, 0x515B1B4E50C04CA5ULL, 
            0xAC5C419A44684D2AULL, 0x47898721182B91FEULL, 0xFEFD984DAED1D18BULL, 0xC4B967D897237FFDULL, 
            0x57B1B08638257254ULL, 0x989991AA5C8055F0ULL, 0x61F9168D38073117ULL, 0x6978A37BA32C3722ULL, 
            0xDB2AB7A50EFF3FB0ULL, 0x427D34CE05A2739CULL, 0x0B6B940D9F92186CULL, 0x0BB0F25D552DCEAAULL, 
            0x237C7443D6619C9DULL, 0xAC5D11B5044AB348ULL, 0xF59A0EB0899BE3A4ULL, 0x14FF2ADE92C95507ULL, 
            0x6AF0A97C6985473EULL, 0x61C251F95EB6DE50ULL, 0x9D28ACEB0C45E287ULL, 0x133F2F1CF0191FFFULL
        },
        {
            0xD7517854A60181AFULL, 0x89C3338FBF85877BULL, 0xD2B87DF2212EEAEFULL, 0x541ECA0D97CD780FULL, 
            0x3F6FA24578C6BE90ULL, 0xA96457F50896E084ULL, 0xB2BD05AAA94E9DADULL, 0xBB37D12696B510D3ULL, 
            0x693F4EB414508984ULL, 0x063ABB365D5A1622ULL, 0xA1E75C4D1793DF59ULL, 0x9C5DE8C5BE2BE10BULL, 
            0x88D9394A5C9405EDULL, 0x21AE575D4082CB74ULL, 0xD196A80A1B90AEC6ULL, 0xAD2DD538A8BA8CBBULL, 
            0x77079501FBEDEE35ULL, 0x2C220F1F138DA17DULL, 0x60567FB866827F63ULL, 0x13EC8BFB2038D105ULL, 
            0x0D0DCE133B73EDC4ULL, 0x2DA5EC2B2484BCDEULL, 0x842C4BD11DFAFA9EULL, 0x5F5B898C976DD9DDULL, 
            0x9BCA9C5C4C1BAC2FULL, 0x1400BD2767FDBC33ULL, 0xA9CAE28C37F80479ULL, 0x2C9977D58F41D9C6ULL, 
            0x3DADFB2B0E35B6A1ULL, 0x0ED64C212EF7BB4AULL, 0x9B7DAE207EC6AA91ULL, 0x237677BA51DF4A74ULL
        },
        {
            0xEAD4FD384ED169A5ULL, 0x2C0C9459F0E92F0CULL, 0x9196068A1C2E09D6ULL, 0x8C0AB9781DF5BACBULL, 
            0x048C5E5BE44057C5ULL, 0x176489FCB149A1E2ULL, 0xB79D06BCD43830BAULL, 0x2D39E4A977E1BBC2ULL, 
            0xFEBFDFAF4A8E75D8ULL, 0xF248BD8634AE6D60ULL, 0x6BA99CC0AC4DDC88ULL, 0x51630D92D3963B0CULL, 
            0xF00FCDEF293AD208ULL, 0xC96F4FF5F8AAB81AULL, 0x78644B467B8CF792ULL, 0xCD22C63C140AEAFBULL, 
            0xC2A7821CF1BB4C66ULL, 0x8663FA469AF37CB6ULL, 0xFD2D039D03C28765ULL, 0xE18A2378A05A508DULL, 
            0x647ECCAD40F6904AULL, 0x11EA23207EDB06C0ULL, 0x505EC44440500F3EULL, 0x3927B47B1AD9B406ULL, 
            0x753ED50EC33CDE15ULL, 0x4846B0C42D8EC682ULL, 0xA134338336F89BE4ULL, 0xEB598995F22A4188ULL, 
            0x101443B9445B07C1ULL, 0x1469EDFC6FC59A7DULL, 0xA8F325CA63754DB6ULL, 0xC3B2D1D15696D61EULL
        },
        {
            0x82A84F425D3050AEULL, 0x6C3BC9659EF11C7FULL, 0xA658485D427C9F5DULL, 0x29FFCD95DC5A2865ULL, 
            0xF27125B25F78B683ULL, 0x405F2EF41D85ECD9ULL, 0xA849555667BDD8FAULL, 0x9CD509AC09C260F1ULL, 
            0x5ECB9595FE20FCD3ULL, 0x2E449C688AE90684ULL, 0x000486B960342690ULL, 0xA259AD5BDDA5DD8EULL, 
            0x6F469733BABEF969ULL, 0x76D26D618F593222ULL, 0x251A2DC10218DF26ULL, 0x735D5B115BC4E0A3ULL, 
            0xCC426F75CE8D7267ULL, 0xB0C8126A2237F51DULL, 0x54477DDDDF4D0E64ULL, 0x897245F1DA004B17ULL, 
            0xED74FEFE87FEE983ULL, 0x1FF7590CFD5B7FA0ULL, 0xA51B81B449801FF9ULL, 0x5AD9BE46BB66FA34ULL, 
            0x7F3EDE880629C780ULL, 0xBC5505DDB89B8483ULL, 0x3391F98558A2D988ULL, 0xB27897F5169E593EULL, 
            0xE0CF2CE54DADFE0CULL, 0x430C87A9D3332C35ULL, 0x912E5EC0D7986EE9ULL, 0x34B8C82B98A57CEBULL
        },
        {
            0xDA453E00F328B857ULL, 0x3340D50A81084BC3ULL, 0xC7C4B6F796C2A6DFULL, 0xF013697BC12887A2ULL, 
            0xB5EBA09183C63E98ULL, 0x538318D115CD3A5FULL, 0xF171D24FC63167F5ULL, 0x9BA21F363747B7ACULL, 
            0xE40732250AAD7A36ULL, 0x0AD72E9B18C029ACULL, 0x320B80EECE91C3A4ULL, 0x088F579CF3EF0C47ULL, 
            0xD85FEFB068E6FE1AULL, 0x8E8F95EA7646B1D1ULL, 0xF1E8CD50C3A6FE95ULL, 0x46ADF720734C5BEFULL, 
            0x65F204D47A046D05ULL, 0x69C5FD4F3D127514ULL, 0x01E831DC18AC623AULL, 0x944D04C29C3A5920ULL, 
            0x9DC18BE7C1435E52ULL, 0x8CE817B327592766ULL, 0x8A58576B3051EF77ULL, 0x3111D467DC253C98ULL, 
            0xE27671895720F6ACULL, 0x86D65725FC09C1CCULL, 0xA5F0F528F820EC0EULL, 0x2703C8CCC0E3CC6AULL, 
            0x21315395402F6F58ULL, 0x8DBD9A64435C0C2EULL, 0xC5B695BB95C140BEULL, 0xA0A9CB586CF1B0A7ULL
        },
        {
            0x1B3EAD88C8FADFE4ULL, 0xB274B451DD6BE489ULL, 0x781B8F49FFC924B5ULL, 0x37856F67BECF8DB3ULL, 
            0x3A0C7A662FD9B825ULL, 0x6D1C415197BF60CEULL, 0x6E7827031B2D399DULL, 0xBF504C1C799568EBULL, 
            0x7EDA53493A6D6657ULL, 0x9FC209D6F17B5997ULL, 0x6170F52005F3A296ULL, 0x069927FD7C99E47AULL, 
            0xBD202116E8BF5327ULL, 0xA01F62FFA378FA3DULL, 0x961A0142A7F8E80AULL, 0x8409768AA96B2443ULL, 
            0xEF048B5165A74EF7ULL, 0x2B5CAE2E628D1A72ULL, 0x53B86F0B81C555C9ULL, 0x75E2E74BF9E8A090ULL, 
            0xB8A09F9E0CBC5E3EULL, 0xCEBE6BA5EA294D95ULL, 0x5562F6B6D7BCCEB6ULL, 0xB484A53F0472E9A7ULL, 
            0xCA6C5BABC7E73E6CULL, 0x607C44C07614361FULL, 0xD0B3F353C94B7D97ULL, 0x8726DAFE12E9C108ULL, 
            0x3BDD2A7CA87073ABULL, 0xCF6D7186B5407512ULL, 0x86B72A514266F231ULL, 0xC1DF9C2A28FEE8D6ULL
        }
    },
    {
        {
            0x5A6FC934F6F2E00BULL, 0x535EB2B4BC17805FULL, 0x87317248FB0F2183ULL, 0x650CF02ED7AD1400ULL, 
            0x75BFD4FBC4790B3BULL, 0x772E8973345D9CB4ULL, 0x63CE725D2AFB7CC7ULL, 0x8108C6982796AE79ULL, 
            0xCB6BD64FFF3A9E83ULL, 0x86E7343E877B719EULL, 0x807BC3C98C96C1D8ULL, 0xE88C8808262F0086ULL, 
            0x3FB671554B9105AFULL, 0x13ABBC3310DB5C01ULL, 0x75355CEFAE6D2F91ULL, 0x9E168FBADADCDA22ULL, 
            0x2EED7261FF5DEB0EULL, 0x94D157214D1F079EULL, 0x0BF1F995F6DEA3D5ULL, 0x258A7E7113DDC403ULL, 
            0x10668C0EDAD22FC6ULL, 0x817018953CAEB365ULL, 0x349309667A00C5F1ULL, 0x26295A0F96F797C3ULL, 
            0x6C96A068019E8471ULL, 0x19C15867238EA17DULL, 0xC788209B682C938FULL, 0x7E4223F2C75A8D64ULL, 
            0x13A208B32B31CF7DULL, 0xA6D85C86D4B3B7D6ULL, 0x44E9797534789782ULL, 0x05EA3CF94849EC60ULL
        },
        {
            0xD8D256898F954407ULL, 0x0F38484AD0227EB2ULL, 0x38DE54A5CCC6C0AEULL, 0x3BDCE7321873825DULL, 
            0xCF45FC34EFD1E544ULL, 0x9B632603D8E5D109ULL, 0x2E384667C138420EULL, 0x0EE0BBF08367E548ULL, 
            0x3DD9485D851EDF4CULL, 0x7ED84F8055880C16ULL, 0xFD28AF166D55ADFBULL, 0x4C68FE91DF2E6709ULL, 
            0x2127FB7A0D55BEC8ULL, 0x84416B0F3E506139ULL, 0x2E637EC9505686FDULL, 0x6F2C001D010BE28AULL, 
            0x32FEB05C410FAD69ULL, 0xA4E042B742C2ADDDULL, 0xFAA35B3FC4E71DB1ULL, 0xE7721E866FBE296FULL, 
            0x18861469C72C92B0ULL, 0x2DA61085358AD02BULL, 0x8B04F385755CFEC1ULL, 0x0E8F6D043861AC88ULL, 
            0x04781961306B6883ULL, 0xEE04A99FBB3C00D3ULL, 0x38B4296319B9628DULL, 0x0273BD9965CA7E82ULL, 
            0x89C4679110B0432BULL, 0x0FC8D379055EC48DULL, 0x3A2B32B1E2C23CD0ULL, 0xB6C5493A4FE4F568ULL
        },
        {
            0xC0841B5855BC6449ULL, 0xCA49C16E4EB3085FULL, 0x12691529CDDD9749ULL, 0xC0646ECA3CAF7370ULL, 
            0xC8B0623122E5DFCEULL, 0x917C402174961DF0ULL, 0x70D19013827EC3A2ULL, 0xFA9CE3591B7DE61FULL, 
            0xFD9A28EF9B53749BULL, 0x32F64B000F2DAFAEULL, 0x582373EC9665F2C5ULL, 0xDCADFF4092070D5FULL, 
            0x883A7328C5CF79FAULL, 0x94563566C0E41493ULL, 0x4FC74B5BF4F37C20ULL, 0xF8F55AE3288DD205ULL, 
            0x5478FFFA3B03509DULL, 0x9EF9543D9E47479AULL, 0x1259FA5B9667E53DULL, 0x512646EA160F73F6ULL, 
            0xBF72C93B67A2EF8BULL, 0x48933458A6032158ULL, 0x7BF2C24B697D5448ULL, 0xD8E17E76D601032FULL, 
            0x279235E562F01D6CULL, 0x0F728D251116104AULL, 0x10D8B7C70745CC73ULL, 0x46C5F91B596881B6ULL, 
            0x4950B1D2498A3834ULL, 0x7A417E6E2DDDA5F3ULL, 0xB39D5231DE1D589EULL, 0xB324398E1C1DC504ULL
        },
        {
            0xCAA52F482EA41808ULL, 0x2CA8CF8BAF69909FULL, 0x17CBEA9633BAA9ADULL, 0xB7210DF4B4D85E24ULL, 
            0x8E5CD4B795F2C296ULL, 0xE6709EF6887226FCULL, 0x3EF91F4BD6954C9CULL, 0xB754C8EC2704C269ULL, 
            0xEDB38BFFB7287A63ULL, 0x11554F48F6E7C51FULL, 0x75021A8C01D4914AULL, 0x73CD1FA8E7EB5936ULL, 
            0x168DE2598DE15138ULL, 0x1F670223889118DAULL, 0xD3760D9D7E667F20ULL, 0x08B387708275FB7CULL, 
            0x2C9C15FE0A47B990ULL, 0x4C6E60A0070840A1ULL, 0xB7D3CDF50A427FC6ULL, 0xF2E70453B5BE411FULL, 
            0xCF23BC2C9291D693ULL, 0xB8C5C3A2C58E8877ULL, 0x30B25B3DAC7A7D67ULL, 0xEB09C632907C495CULL, 
            0x4E7561C634AF0DA9ULL, 0x44A53F247F8A9F13ULL, 0x4203A26454D71ADBULL, 0xF14A4DDBCEA2CD98ULL, 
            0xB91167A75B61DE29ULL, 0x32D9E8AEC9E70503ULL, 0x5B549B11FC6CA1B9ULL, 0x00862FEE3417750FULL
        },
        {
            0xBBD4EC07D5A4D93DULL, 0xAE3B629D683A30E6ULL, 0x30EBE1AC29C4AAFBULL, 0xA20EB2A521E7B459ULL, 
            0x7450F8E9B283E9F9ULL, 0x5BFA0B797C0E63D0ULL, 0x1A9AE0BFC17A8D39ULL, 0x193E0C455ABD019FULL, 
            0x2B1982CB7634C511ULL, 0x039BA5B4542B4694ULL, 0xF091E7879D0933A3ULL, 0x604FBF9590A8E59FULL, 
            0x99A9F0330C6E19D9ULL, 0x78FE5D342B57A1B5ULL, 0x2D70B03E3D2DA0DDULL, 0xD7E3D63183DD8ABCULL, 
            0x7370ED791A72FFEAULL, 0x471FE07DB10D255BULL, 0x33B319CB0815DCA5ULL, 0x2FE62275E976CC35ULL, 
            0x341428A1383D2062ULL, 0xF5FF72FB128D1E86ULL, 0x1FFCD4EBA94A6A54ULL, 0x5EE129C2FE1DF3E0ULL, 
            0x1B6A53F4A20BB8CAULL, 0x0DC16EB20BBE6A1DULL, 0x2B27481714EDFDFEULL, 0xCCF1B9CC20233E8DULL, 
            0xB7A9DE362C090653ULL, 0x80B26DD87208938EULL, 0x9B33F6DA71D04313ULL, 0x736DD00FDB402644ULL
        },
        {
            0x3BAF5C15AAD89E91ULL, 0x431F4F54A9B39831ULL, 0xCB80857404560CF6ULL, 0x353929E9DAE8D1FFULL, 
            0x327E13D8EFB279F8ULL, 0x966E4B30E167C81AULL, 0xC0CD87C6EC2C84C7ULL, 0xD2831A35059D3320ULL, 
            0x966AFE4AC645EBC2ULL, 0xB57F08C338C2F1D0ULL, 0x842AF7420F1017CDULL, 0x46268F147F922898ULL, 
            0xCC57AB5F94A4F789ULL, 0x652ED0777B22FCFFULL, 0x8A0B3289003706EDULL, 0x732C07634FE87C59ULL, 
            0x8E141D91EACF84B1ULL, 0xE450CEA35CABBF17ULL, 0x1263918DE429B51AULL, 0x15E8339F1971A770ULL, 
            0xAD0A9C06660C0BA6ULL, 0x92AED2D2D97FA191ULL, 0x56A2E85BF9C8BE62ULL, 0x5056E3438D8B9D89ULL, 
            0xD73BC6917D70A883ULL, 0x2F510CDB9BFEEB32ULL, 0x32EC0588E66094CAULL, 0x60A5320C796A8828ULL, 
            0xE069809C0C8B90EDULL, 0x6F54B4882F78E821ULL, 0xF50DB08A35D0EF0DULL, 0xF37D58E5231F0313ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Badminton::kPhaseHConstants = {
    0xC0102C858348E216ULL,
    0x7ADAF24F1C3B9744ULL,
    0xEFED261B47FCA82BULL,
    0xC0102C858348E216ULL,
    0x7ADAF24F1C3B9744ULL,
    0xEFED261B47FCA82BULL,
    0x1325AA945F5EE187ULL,
    0xB970507F523803EBULL,
    0x08,
    0x18,
    0x47,
    0x79,
    0x3F,
    0x8C,
    0xC7,
    0x03
};

