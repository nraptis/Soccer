#include "TwistExpander_BaseBall.hpp"
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

TwistExpander_BaseBall::TwistExpander_BaseBall()
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

void TwistExpander_BaseBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 16546623548253238899U;
        aCarry = 17520748553365538582U;
        aWandererA = 11027081092073242869U;
        aWandererB = 17902891333282792722U;
        aWandererC = 11136083461970474199U;
        aWandererD = 11297512134778723476U;
        aWandererE = 18213362073318724396U;
        aWandererF = 14058754729698963933U;
        aWandererG = 16046525691467440628U;
        aWandererH = 14217048109350846911U;
        aWandererI = 9729944176152245901U;
        aWandererJ = 14707264866069406276U;
        aWandererK = 9877407439301238378U;
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
    TwistExpander_BaseBall_Arx aArx;
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
    TwistExpander_BaseBall_Arx aKDF_A_BArx;
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
    TwistExpander_BaseBall_Arx aKDF_A_CArx;
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
    TwistExpander_BaseBall_Arx aKDF_A_DArx;
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

void TwistExpander_BaseBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16592432341316766645U;
        aCarry = 13916387134049688113U;
        aWandererA = 11572589851252876480U;
        aWandererB = 13173849650887070035U;
        aWandererC = 10071673056794024658U;
        aWandererD = 13749543454090012087U;
        aWandererE = 13110879313957326848U;
        aWandererF = 17943011137641799303U;
        aWandererG = 17972808064221498067U;
        aWandererH = 17251834038383443793U;
        aWandererI = 12945193692868279260U;
        aWandererJ = 11139276589783643017U;
        aWandererK = 10461869295677453166U;
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
    TwistExpander_BaseBall_Arx aKDF_B_AArx;
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
    TwistExpander_BaseBall_Arx aKDF_B_BArx;
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
    TwistExpander_BaseBall_Arx aKDF_B_CArx;
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

void TwistExpander_BaseBall::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseA invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneA);
    }
    // KDF_B PhaseB invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseC invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneD (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneD);
    }
    // KDF_B PhaseD invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneG);
    }
    // KDF_B PhaseE invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneE);
    }
    // KDF_B PhaseF invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseG invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseH invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_BaseBall_Arx aSeed_AArx;
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
    TwistExpander_BaseBall_Arx aSeed_BArx;
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
    TwistExpander_BaseBall_Arx aSeed_CArx;
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
    TwistExpander_BaseBall_Arx aSeed_DArx;
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
    TwistExpander_BaseBall_Arx aSeed_EArx;
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
    TwistExpander_BaseBall_Arx aSeed_FArx;
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
    TwistExpander_BaseBall_Arx aSeed_GArx;
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
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
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
    TwistExpander_BaseBall_Arx aGrow_AArx;
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
    TwistExpander_BaseBall_Arx aGrow_BArx;
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

void TwistExpander_BaseBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_BaseBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_BaseBall_Arx aTwist_AArx;
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
    TwistExpander_BaseBall_Arx aTwist_BArx;
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
    TwistExpander_BaseBall_Arx aTwist_CArx;
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
    TwistExpander_BaseBall_Arx aTwist_DArx;
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_BaseBall_Arx aGrow_AArx;
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
        TwistExpander_BaseBall_Arx aGrow_BArx;
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

void TwistExpander_BaseBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 3, 0, 1, 3 with offsets 4190U, 24U, 4848U, 870U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 24U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4848U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 870U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 3, 1 with offsets 2827U, 2961U, 2507U, 1062U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2827U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2961U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2507U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1062U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 2, 0 with offsets 1726U, 1078U, 5896U, 538U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1726U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1078U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5896U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 538U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 2 with offsets 4453U, 1624U, 7941U, 6400U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4453U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7941U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6400U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 with offsets 1311U, 471U, 1162U, 378U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1311U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 471U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1162U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 378U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 2, 0 with offsets 811U, 442U, 779U, 653U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 811U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 442U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 779U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 653U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 1, 2, 0 with offsets 1844U, 1783U, 1946U, 1982U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1844U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1783U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1946U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1982U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 1, 2, 0 with offsets 966U, 794U, 1834U, 1491U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 966U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 794U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1834U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1491U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1470U, 925U, 64U, 1867U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1470U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 64U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1867U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_BaseBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 2 with offsets 526U, 2046U, 5542U, 2127U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 526U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2046U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5542U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2127U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 3, 0 with offsets 2906U, 1125U, 1776U, 286U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2906U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1125U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1776U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 286U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 0, 3 with offsets 7371U, 5501U, 4313U, 2480U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7371U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5501U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4313U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2480U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 1 with offsets 823U, 1743U, 4126U, 7158U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 823U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1743U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7158U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 884U, 8014U, 5673U, 5879U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 884U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 8014U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5673U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5879U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 0, 3, 1 with offsets 697U, 261U, 718U, 864U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 697U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 261U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 718U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 864U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 0, 1, 3 with offsets 294U, 617U, 1344U, 273U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 294U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 617U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1344U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 3, 2 with offsets 401U, 39U, 144U, 829U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 401U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 39U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 144U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 829U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 3, 2 with offsets 2030U, 490U, 1794U, 506U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2030U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 490U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1794U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 506U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1784U, 1229U, 508U, 1979U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1784U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1229U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 508U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1979U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseASalts = {
    {
        {
            0xF0AEF673C1D8E0F6ULL, 0xA01648983CC5D236ULL, 0xFC16E9FAD3AAFE2DULL, 0xE8A94D363FE4F356ULL, 
            0xA73AE5A65CF9D9C9ULL, 0x2E30109B324D1570ULL, 0xB30EC30349D9A8EAULL, 0x9A1CEBE7E4C71F6EULL, 
            0xB9411816E70297DAULL, 0xFC722A7C320842D1ULL, 0xECAFE2B8BE0C91C4ULL, 0x0949AE2288171C90ULL, 
            0x20D69E3E74577B85ULL, 0x13D0D6569FBD7B1DULL, 0x17E30E1248FEDF5CULL, 0x8595A4D907D21678ULL, 
            0x78C8A3AC05BB49A7ULL, 0x411DC959F1387437ULL, 0xC1E0FD5D5729AF50ULL, 0xEBF6C4EC2D13A9C4ULL, 
            0xB4F36289DB957D97ULL, 0xB89CF3CE0DB7D5FBULL, 0xFE0AB80C998CF250ULL, 0x32B6B4FDBEA00D40ULL, 
            0xB1DC780E4D014059ULL, 0xB74261E206EBF70FULL, 0xE686E7FC4CBA4B41ULL, 0xCCBA47E450859328ULL, 
            0x7F76522562A4F1BFULL, 0xA678AA85C2BE8633ULL, 0xF2AE758B1C10D7B4ULL, 0x7538A805E64B4E64ULL
        },
        {
            0x58455073841712A9ULL, 0x1AC88CE3919027E5ULL, 0xDECB2B43C7FCDD90ULL, 0xD2F182B42C773D54ULL, 
            0x763EBACE020B6863ULL, 0x90681DCF0D3FF399ULL, 0xE78DBA19101CB706ULL, 0xF9E2B26EE47C8B85ULL, 
            0x2957EF7547731DB9ULL, 0x350209F3A0CBC14DULL, 0xE3317D5FA0868D34ULL, 0x0C635DB7F737F3E8ULL, 
            0x2802C2327A130FE4ULL, 0x8F6F22AB92F1F9C3ULL, 0x0D4CE9671A485637ULL, 0xBF10DEC18849F075ULL, 
            0x096D60F10AAA4F28ULL, 0xBC7BA0317EDB608EULL, 0x90F3200877D84386ULL, 0xE15B546358175910ULL, 
            0x47EF19A39193D626ULL, 0x21727875A7A8A182ULL, 0x3EF5A5600BA69C6FULL, 0x72A031B02A18B2A2ULL, 
            0x7EB92C1836EDB0D8ULL, 0xEC7E8A6D3E132324ULL, 0x4D3ABED914909943ULL, 0x69E715672C2E74D8ULL, 
            0x70535036183A6259ULL, 0xD59714B9C969A2C5ULL, 0x546A29149BB7DBEDULL, 0x594197D7F9DD234DULL
        },
        {
            0xD707D8D9432267D6ULL, 0x190BEA21DE2BBB16ULL, 0xD2C69426F872E397ULL, 0x0691EB047540677DULL, 
            0xF2385EF0D7EE7A44ULL, 0x54C2FA2E2D4C8E60ULL, 0x5A81F8DB0136556CULL, 0xFDC56CB4E5B9EE4EULL, 
            0x1B8EB18E6E44C475ULL, 0x4E36F57EAFDDF112ULL, 0x696EB59F2AECEDFFULL, 0x33A17171301E8618ULL, 
            0x56687D4920E2744FULL, 0x94882C86AB89CC7DULL, 0x9239ADDAF429EF53ULL, 0x425B72C692482A58ULL, 
            0x28989E5E00425674ULL, 0xAC7BF559CA2E5AC4ULL, 0x643CCB09945E3C8DULL, 0x00B7F9FB65ABE8A3ULL, 
            0xB8A9467BA395EA22ULL, 0x81EDC74E6939EA0BULL, 0x1656B846D959363BULL, 0x9572FB5F3DA153B6ULL, 
            0x05F1784C8A46B700ULL, 0x9BAF33DD41BDB19BULL, 0xFF8D8A9BA96A9497ULL, 0x007E67F9EA296C0AULL, 
            0x035827C4AA6BF25DULL, 0x39983A7DF636E40BULL, 0x1393A6D81C3DC31CULL, 0x5730A048F87F47B0ULL
        },
        {
            0x4E16F6E5B124E559ULL, 0xF250EEEFE30C78AFULL, 0xBCD83A7A4A2F9002ULL, 0x491B2A90206EAF41ULL, 
            0xA2D92A468CC496EBULL, 0x28627E206374FE0DULL, 0xFD8DC7E73BB62072ULL, 0xEE8EDD88E346ECF9ULL, 
            0xFB7362C5CD3AE916ULL, 0xE817C76F250ED912ULL, 0xE4042B47D569889FULL, 0x8B025D8D1955C94EULL, 
            0x0A0C3430BC25ED83ULL, 0x5707DF6B1AD920D8ULL, 0x8E7F113B22937692ULL, 0xBE57DA21378FFFFCULL, 
            0xC6899159AA4FF22BULL, 0x0DFC10869432B061ULL, 0x6EDBE16ED33E2E5CULL, 0x9BBD33D44CD1AA62ULL, 
            0x514EED3D8259DA22ULL, 0xFA3FA33CE017B804ULL, 0x385FEB4330E09226ULL, 0x932E735E439E32E1ULL, 
            0x8F21044A3949F920ULL, 0xE58581F443A57FECULL, 0x9E689C2A38193C41ULL, 0x7B965C321C702832ULL, 
            0x0B22F1DA5F9991DBULL, 0x8B2DA707EDA982B6ULL, 0x4901F8697F28BAEDULL, 0x68E4712B9F4CAD9EULL
        },
        {
            0x490E4E23E82FF34CULL, 0x6BC80BEB2C3DE341ULL, 0x2103649D9A7F70DAULL, 0xAED452BCCAA76A14ULL, 
            0x8A2E63669D065098ULL, 0xB8729C96C47CF767ULL, 0xF08D1EC41B635D86ULL, 0xF49D6FA33D82DBCBULL, 
            0x4C6B1C154A52CB9FULL, 0x10D18D325531B3AAULL, 0xDBAC0E3AFD5E3B71ULL, 0xEA91DD2078F54712ULL, 
            0x81A8131D67923592ULL, 0xB53C69F54BF8B0F8ULL, 0xAF605A2FCD4B3AEFULL, 0x3C77C290EBC043C0ULL, 
            0x39DB10425D2D7DFBULL, 0x30E861B73823BDD1ULL, 0xD77634B22E159BA5ULL, 0x095C1EC907B8A539ULL, 
            0xAB7498D19A664158ULL, 0x664C2A2CBD8878DBULL, 0x0B098B1D08B6CBFCULL, 0x335C2CC8393C4D82ULL, 
            0xE0C32C92DCC7CE72ULL, 0x301E4566E72055DBULL, 0xDF32E06C5F035D7DULL, 0xC118F5697F79E978ULL, 
            0x532318FD22DB83D1ULL, 0x13F445DE6E2A5AADULL, 0x3ED88BEA1EFC8642ULL, 0xC28491C502E554F5ULL
        },
        {
            0xBBABFB830EE28F2BULL, 0xC42376DC6A980FF0ULL, 0xE5156EDFF768A3E5ULL, 0xE875A454B61D21EDULL, 
            0x38B8EEAE170AB30AULL, 0xAB1A771EC916740FULL, 0xD8D190B7E5A8B0A8ULL, 0xADA817C96D81236DULL, 
            0x7F2BF766D538E8F8ULL, 0x50F5BBF38F6D83F6ULL, 0xDC502E306358CD8FULL, 0x710ABD534B4557F2ULL, 
            0x861ADA91BA9AD9B7ULL, 0x7C4E5F023C4D8397ULL, 0x77712912FCFD1035ULL, 0x8E59785E92ED1042ULL, 
            0x5842AAC1A51227A5ULL, 0x912FB0D9D97248D8ULL, 0x90E7F6B62D399055ULL, 0x60E7D741FD466EC4ULL, 
            0xFE0C252D20A92903ULL, 0x5F495B6D34B15D7EULL, 0xE35B81F5110BE0C2ULL, 0x484F2F7118BD9711ULL, 
            0x79F380E858AC3207ULL, 0x21978A77EBF2C7E3ULL, 0x6B8DC5D53205D668ULL, 0x58A826CC6E996543ULL, 
            0xEF4C794C5B6AFC67ULL, 0x671387D7B5CA9D2EULL, 0x8AB42BD69CA8940FULL, 0x0DE7E7562DEF7CE9ULL
        }
    },
    {
        {
            0xB3A3E16A1F953C2CULL, 0xD0BCB5E04B6723ADULL, 0x91270791CFFD8772ULL, 0x582C29BA40CF2FE0ULL, 
            0xEA33E74A86673A2EULL, 0x56513F3B99A37E30ULL, 0xA4AB58B2DCEC8AE1ULL, 0x559758480D2DE3D4ULL, 
            0x1FBEFC56E7D008A8ULL, 0x830044F4D45ED94CULL, 0x2061C609BD6D4A26ULL, 0x52B20BD69A25EDCFULL, 
            0xC64DEE1862BA8816ULL, 0x1F42C1621BB88C4AULL, 0xF091CCD90461D979ULL, 0xE63CE71899777F0FULL, 
            0xDE7B3D95AB268D8EULL, 0x0245F29C4CF9AC38ULL, 0xC270F0E11D6705BEULL, 0x0AD2E9508344BC83ULL, 
            0x1D68519E9C1411A8ULL, 0x4A4C108F14B696AEULL, 0xB198E3A5FD525E78ULL, 0x4A0C4E3BB6FF6A1AULL, 
            0xC335DB14F82AB773ULL, 0xB9E0E2BDF92C7964ULL, 0x3BFCD9CFDA6C62F0ULL, 0x0A28E858258E4FDFULL, 
            0x7FA8369023DB5FEEULL, 0x4DFAB99357486CC3ULL, 0x76D242DEF8D64697ULL, 0x50ECB6ED91288975ULL
        },
        {
            0x20F6E567A8FB3DDEULL, 0x6BA781F4739FF5F0ULL, 0x97EA0D580B82CB11ULL, 0x6DBFA9B6EAD631D1ULL, 
            0x5D631E652313A356ULL, 0x41B82256D01903A2ULL, 0x3E35B205998E05AAULL, 0x58A385D37876281AULL, 
            0x5097A583894851C4ULL, 0x1CB8652970BE6A59ULL, 0x4AE0B709AA4FF4A0ULL, 0x624201F04EF7B838ULL, 
            0x67371920181F1C1CULL, 0x3C8BF0167316F771ULL, 0x48AC6AD46ADFCF9AULL, 0xB095A0EDAF7FEBAEULL, 
            0x7106DDD687A9A325ULL, 0xB05C7821479B4A6EULL, 0x0A7A0F7176A58E80ULL, 0x456D6B115FFA2806ULL, 
            0xFA1156A773D1B2ECULL, 0x7D9EEC2280BB8CF7ULL, 0x6B4E0D2387377967ULL, 0x629B1DD27DE99E26ULL, 
            0xE1ED2182C1C2F74EULL, 0x977672769C8D6686ULL, 0x07A3FC6D55A0E106ULL, 0x7C1323EFA31D34F1ULL, 
            0xA25575C8CD6E5785ULL, 0xA3125B3CDD576B70ULL, 0x1BF5423B90E0B3A3ULL, 0xAB98D03515A020E9ULL
        },
        {
            0xC6DF5DC6B647274DULL, 0x5C39D0D67DE9AE07ULL, 0xC93D0C68CD225ECCULL, 0xE71AA1E8EE30B8B6ULL, 
            0xF4B2F156BFB839A4ULL, 0x1264F0D75F93E2A0ULL, 0x86957A51583EFF9FULL, 0x51A66E9F82346847ULL, 
            0xACE278F9C074D44BULL, 0x7FD898AC273AD127ULL, 0x281E92768554D174ULL, 0xE928AC3CFDC7467DULL, 
            0x008DEA8D05EFEC58ULL, 0x716D91D6C6820D65ULL, 0x80764D09B655908EULL, 0x84D76D33161FB4E7ULL, 
            0x7845240990D5653CULL, 0x82A188D22D094E3FULL, 0x2B1E70957342E3FFULL, 0x458946FF9F7B7DE3ULL, 
            0x383A1449518F51C2ULL, 0xBB553C109A494B57ULL, 0x859E885EBA64E7F1ULL, 0x59EE89820E3BB69EULL, 
            0x1E8FBA86F6843EB6ULL, 0x226A0265821CF485ULL, 0xD32D0A1D88CFFD5DULL, 0x36DCE0194F6A0E08ULL, 
            0x7F16755B653674EDULL, 0x5555B44599ED0776ULL, 0x044B7409421604EFULL, 0x4ABCA7AED1D2AA7CULL
        },
        {
            0x2738E4E9D5991A9AULL, 0x85CBC3E578A8DF11ULL, 0xC4F73C2FDF598DE4ULL, 0x0EBA48D2E1D2BCF9ULL, 
            0x631BDE92B23BBDB6ULL, 0xACA4207D974A20ECULL, 0xFA3102B9F71FB9D1ULL, 0xF7786E1FC3653923ULL, 
            0x76470863974D62F1ULL, 0x7CE06A1B62E82526ULL, 0xB0F810EF6D2C09EAULL, 0x3301B0C9CB2FD8A0ULL, 
            0xB080B9995F6C9570ULL, 0xE9750488C31E63B7ULL, 0x8D28C7E6D313085DULL, 0x84518B07B1358D01ULL, 
            0x8FCEA9577DB6AA2FULL, 0xFDEDD7671D82923BULL, 0x002825C3316D6EDEULL, 0x4F3FAC5B3783EB6CULL, 
            0x6CF669C165C80619ULL, 0x5816B277D4B505E3ULL, 0xBEA8F15497B952DAULL, 0xDCC4999C8D359F0AULL, 
            0x1C696F78D66F05E5ULL, 0x2E6A5DDC973D27CEULL, 0xB6D77C2B23FBFEFBULL, 0x9F49BFCA3DB31B1DULL, 
            0x64DA4C83D203D0A7ULL, 0x2EB0F2F7B020ED8CULL, 0xE46CEF7D089B275EULL, 0xCC4C0B64D1316AC9ULL
        },
        {
            0x4A6A5611C7C6F547ULL, 0x19E3E504AAFD9F82ULL, 0xA597965CB88B19C6ULL, 0x9E681AFFF84E4C0AULL, 
            0x222FFC490360DDE1ULL, 0xDB7A148B3D0C7A58ULL, 0x85062A3CEAE521E1ULL, 0x6910305E801D4D88ULL, 
            0x0C40E272D5603DDDULL, 0x02A1E2E870DD037DULL, 0xEF30294FD7748FB7ULL, 0xC11BE618B1C3C5CCULL, 
            0xCBC722278A849453ULL, 0x3365DB271643A5D7ULL, 0xA560B0B95B701DECULL, 0x1D061170742A7CEDULL, 
            0x2D93BC5E4BF471A0ULL, 0x578AEA74ABE2C283ULL, 0xF4520F9DDBFD6D0AULL, 0x4E68BAE0958C81A8ULL, 
            0x8AC1B2012ECAB266ULL, 0xA9816AF6256F3350ULL, 0x615F9D0F6D9C06E5ULL, 0x926F1CA2E78D4A11ULL, 
            0xD0CD91D4B848F7DFULL, 0x5C85A42D8D91EED0ULL, 0x40E1DE76B36555DFULL, 0x1E67080FDEC24D39ULL, 
            0xC42CEC3AC1F663D2ULL, 0x78C5E650A4FDCC0DULL, 0xB8102FBD008F1240ULL, 0xB496D2D53035FD7EULL
        },
        {
            0xC019B2F4E87862E1ULL, 0xA625F2081A5C7E43ULL, 0xFA8584CE96ED4DD9ULL, 0x8187A384EBDEF090ULL, 
            0xFDD19CE79EC620D6ULL, 0xBAD71E4C3FBF9E57ULL, 0x518B82CC5B71FF93ULL, 0x16DF4A378ACD0875ULL, 
            0x81CD7589CCA74B0FULL, 0x8F67306F020B778CULL, 0xE7929EC07508908DULL, 0xCAE49FC5ECB6FD3AULL, 
            0xF0CA5B87CA2064D4ULL, 0x46E27637E7DBDD1DULL, 0x5F00749F5909A9CCULL, 0x57A17EE476C99DB6ULL, 
            0xC34C21D97CA3C166ULL, 0x589B2398C7FDA24FULL, 0x2589DA6ACA726955ULL, 0xC963E5C2AF2F13F2ULL, 
            0x8A420755BECA62EAULL, 0x7350D939FFFB5109ULL, 0xB609835BE16C0538ULL, 0x58D2ECBEDE64BB8BULL, 
            0x3F5BB622ED1C732FULL, 0x63F65B9FE690A487ULL, 0x46923938C96911F7ULL, 0x9998949F75948A3CULL, 
            0x4AB50A6BC400713AULL, 0xB55A63EEC2C342F1ULL, 0x034EEF5707F52F55ULL, 0x600B40B8CD76A549ULL
        }
    },
    {
        {
            0xB141A3CFE4B5000BULL, 0xFB0AFBD711C3927FULL, 0x6BB49C39811BB88FULL, 0xE9D0F8230EE7340AULL, 
            0x895D0533F9EA3CB6ULL, 0x035DEB3DCBE8CB6FULL, 0x7AD7AC6097494538ULL, 0x206CC39A14634BB0ULL, 
            0x0C31FB0CDC99F13CULL, 0x24D9BDE36CBA1B34ULL, 0xF7D76496FC4097D6ULL, 0x2EF1D56000765CB3ULL, 
            0xEE30304E4CC87390ULL, 0xFF838ED099AF5105ULL, 0x74DEB6C02413956AULL, 0xE2250D5683546F6DULL, 
            0xCE95E4ED02F9E38FULL, 0x1593E46DAC46709CULL, 0x01B23D8071BD4EA5ULL, 0x98F10210AB53773DULL, 
            0x8E01A455BB1FE5F0ULL, 0x771A3C633CC9D759ULL, 0x047F495F4648D74CULL, 0xBE3EAB7FF2A9E888ULL, 
            0x4A16A9FC0D9231C3ULL, 0x17DFB5C65A406AA8ULL, 0xC29B51A541C3B623ULL, 0x4DAA5E43E2E452B8ULL, 
            0x6E79FF0BF9334DD0ULL, 0x4C3ECE19E9AB6FB9ULL, 0x56768061E46F6896ULL, 0x7EE52E0F48E0BBFCULL
        },
        {
            0xF5430E0F96696174ULL, 0xBD7F8108C3BEFB82ULL, 0xE22F3F2D30E6B31BULL, 0x9BA3811D5446B4F8ULL, 
            0x6D25380125576C28ULL, 0x4E1020ED1F83E5C1ULL, 0x6D97A3796C0F6B71ULL, 0x8BC028E1CE7C322DULL, 
            0xE0617B8CB7F4A286ULL, 0x3F52CA967147340BULL, 0xE1F710BB77B3280FULL, 0x4DD6ECD0A004EE2AULL, 
            0xE29B440431EBFED9ULL, 0x5108969A9870400FULL, 0xB571A317F63A942BULL, 0x80B204B852044BB9ULL, 
            0xC6BAEB7189BD7084ULL, 0xFCD473618F1F95B6ULL, 0x25FFF5C575E21096ULL, 0xAE7869F7B6E5AA8FULL, 
            0x269966E7ADF1CA1AULL, 0x872FBFAD91F7F931ULL, 0x34562D753C4D4386ULL, 0x0A123AEC09B0881CULL, 
            0x002280D63352697EULL, 0x465AF94DC6DE31D7ULL, 0xF83E9D7EE8329F2EULL, 0x7B1B3A9E295F68FBULL, 
            0x53DE050374260A87ULL, 0x22D0E806A268F264ULL, 0x2D13F8ECEE932C4BULL, 0xA872C0C9F42C334FULL
        },
        {
            0x72914027FE534800ULL, 0x8C041B46A9B9C0E4ULL, 0x93D0CCF89011519CULL, 0x3E511826E7F62D84ULL, 
            0x049D0461B88B3BAFULL, 0x866A7612B0538E72ULL, 0xD03757B2397A35B8ULL, 0xF0C019CC3418C2FBULL, 
            0xE8F1EAAC1B4EC507ULL, 0x7D1EBCED8F7AA32BULL, 0x3B90F6C2E947A346ULL, 0xA8DAE5B99D68C5E9ULL, 
            0x55E6478BD5B1A950ULL, 0x62F3CB1CB4B8F1CEULL, 0xC1C576DAE5E1545AULL, 0xC459DEE0DF77542BULL, 
            0xA8ECC371F6E445BAULL, 0x94B56F9AF81E7E00ULL, 0x32C9433B2595250FULL, 0x58E5DE5606DEBF47ULL, 
            0xBFCC9C3F431482D0ULL, 0x076766655C60417DULL, 0xD94B4ACFD53D3DEEULL, 0x97E35D14E63AB241ULL, 
            0x7314C5B04FE8EBC3ULL, 0x91452DE1BAF57D2DULL, 0x14F56F632A9DDBAAULL, 0x2B665FFCF29360EEULL, 
            0xDCEA8DD362C8B824ULL, 0x3951E2BAEF62F151ULL, 0xA605229BB3D170E6ULL, 0x3DF5599B082C5ECEULL
        },
        {
            0xED5603C563757060ULL, 0x8908115269BF975AULL, 0xBC169DB7C768D5E2ULL, 0x7EF4DAC2778CC190ULL, 
            0x4DDD28025FB0D9A2ULL, 0x95E9F2D771B55C3CULL, 0x7D4033AF48332C35ULL, 0xFF18C454363C429CULL, 
            0xF0AF0385EF0CE0AFULL, 0x16B749AF2AFDF3ECULL, 0xAA90EDFBA0FEB48CULL, 0xCFB67B8DCCB72AB7ULL, 
            0x25E0BCB453CC6365ULL, 0xA0A7581F9CE64A5CULL, 0x3014992F2475F111ULL, 0xD48B4A9D9595A88EULL, 
            0xABA5AC12FEF2C1C7ULL, 0xA20B71F4F853D73CULL, 0xEA9F0C073DCB561CULL, 0x027A4EB0BBB4D67AULL, 
            0x47569AB54E4084C2ULL, 0xC476E7237B43206BULL, 0x44288A470501B843ULL, 0xF9ECE6A248872AEDULL, 
            0x9B58AC2DECFA4473ULL, 0x3EB349555BCF6476ULL, 0x09070C8B95B4BA4FULL, 0xE302AF35A334A4F4ULL, 
            0x6CB0EC7A82589901ULL, 0x87B26E588D76E55DULL, 0x0603E1758E9CBFADULL, 0x6C80D41760E1430EULL
        },
        {
            0x367C657AC89DE7C9ULL, 0x5B71A8BD14DF481AULL, 0x0A90DF5269D04622ULL, 0x74535EBDE3CD2410ULL, 
            0x64FB2E935CCD46CAULL, 0xBC4EAA3BC0981A0AULL, 0xFE3D124BE2B249ACULL, 0x4FA76D3BE1DABF81ULL, 
            0xDC423F97A9F4B800ULL, 0xA3BF902F557F988CULL, 0x8B1F266AB106B94DULL, 0xCF99A43AF05537F9ULL, 
            0x949C9E9C5F3172B3ULL, 0xCE13A31011759EAEULL, 0x7693AF1E110CB367ULL, 0xA6A8AB562D973DC4ULL, 
            0xF012F205C12764D3ULL, 0xC90AA0D487F9CD5BULL, 0x411EE501AF2D01E8ULL, 0xD5B094960C7440D9ULL, 
            0x12F12BE457BBD9E2ULL, 0x57BE6E57F5DF0665ULL, 0xCCE083413463D343ULL, 0xEAB479DF5BAB72DFULL, 
            0xC58EABE2C1BF079FULL, 0xFFD44099BD9C9CC6ULL, 0x4286FFCA5DD98575ULL, 0x7FA28600CDDC1609ULL, 
            0xD85889D17D0FF164ULL, 0x6AF2255A8CB163CAULL, 0xE55490BBBA6BBF0AULL, 0x348FED2049A82825ULL
        },
        {
            0x56401C6BAEECCC90ULL, 0xFA84E6F42F82B4B9ULL, 0xCD58F39A83BC1EC4ULL, 0xD8C3AF09549E6D3EULL, 
            0xD7A1527E132A4EA4ULL, 0xC030A974705B99B3ULL, 0xAD677B699951DA62ULL, 0xF3C8B1B55F9B7392ULL, 
            0xF4C9B4C13ABD2603ULL, 0x2480327B3404322EULL, 0x604D15AE74B7F6D6ULL, 0x41F074348CDFCD2AULL, 
            0x90A1C4922F4C940CULL, 0xCD2B3BC84B8D54D3ULL, 0xFC745DF8A6E60226ULL, 0xAC4D19E89A0F307EULL, 
            0xA3E103B332CD7518ULL, 0x393B8FB1129382C1ULL, 0x41DF29E6B5ABAFE4ULL, 0x340C09E559C93A3DULL, 
            0x3F2F6FDCBCD8FA2AULL, 0x31A6461564ABBA93ULL, 0x48533B521981F8ECULL, 0x3EE85DE819590FA3ULL, 
            0x1366C2BF97E6E159ULL, 0xA3E52589FF3D9A09ULL, 0x8123F40B65A9194AULL, 0x5A66AA657D7AB5F2ULL, 
            0x7435EDAB2FE4E9DBULL, 0xC9732F855A2221B3ULL, 0x3432D783BE0BE049ULL, 0xE2A100D6C9F4F23CULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseAConstants = {
    0x60A6FDBD4B9D8D4EULL,
    0x6E2B0D2EBDDAFEB1ULL,
    0xCF82AC79E3A88058ULL,
    0x60A6FDBD4B9D8D4EULL,
    0x6E2B0D2EBDDAFEB1ULL,
    0xCF82AC79E3A88058ULL,
    0xCA5ECD2A24DB1E45ULL,
    0x0847373C4BF571B0ULL,
    0x9A,
    0xBC,
    0xB1,
    0x8D,
    0xA2,
    0x04,
    0x04,
    0x01
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseBSalts = {
    {
        {
            0xBD671F8DFAB23053ULL, 0x04790A775FEDCA06ULL, 0xCB2114F482F4D222ULL, 0x51DB472C38186B33ULL, 
            0xBD8841DCB77225BCULL, 0xA3389B5B720F0EF0ULL, 0xB0EBA8EDA71D6BB2ULL, 0x45CFB0BEC6B8F202ULL, 
            0xD42995FBEED5FC66ULL, 0xD00F4C65CB81CCA9ULL, 0x94D96FC2FC2D94AEULL, 0xADCAEC5B9CDAF0B4ULL, 
            0x90F7E71369D038C7ULL, 0x4F62398CBCD2F0C0ULL, 0x7A884EB3BFD7B19CULL, 0xCFFFB43F78818DF5ULL, 
            0x4DC70ADDA5A0D927ULL, 0x3239AA3E893448E9ULL, 0xD4E0905A7F12774BULL, 0xF572C41E1381668AULL, 
            0x04B90D34F7CB4436ULL, 0x9BB5B710512429E7ULL, 0x956164A4441D5FEFULL, 0xC60D79173ED5280DULL, 
            0x056E2342DE1F5259ULL, 0xE2E0A4AD1AF1AC1AULL, 0x51445A6A8133F298ULL, 0x5709106CD894238CULL, 
            0x25DBB1BC4C8A7EE3ULL, 0x2CA7F84B23551072ULL, 0x83F0F1DC75B63352ULL, 0xADEAB4A8C18CF728ULL
        },
        {
            0x22536D9BBD0AD887ULL, 0xA83CF3EC786C3AD6ULL, 0x9CF099DD86BB2E5CULL, 0xEE617239FF1F6422ULL, 
            0xD14259AA9F23D494ULL, 0xD67E16D65B171C20ULL, 0x6C3D44C2DD8FCC61ULL, 0x14BCE34C87C34A0FULL, 
            0x5F0B5FD099D170A7ULL, 0x57F4F4B73993BDDBULL, 0x9E8D0E4737D3B997ULL, 0x38DB2B45F685FB85ULL, 
            0xF29B4509B28F7A5CULL, 0x6D65F4D30D6E4DAFULL, 0xFB292C33A55EA3EFULL, 0x95CB6BC8FF68992DULL, 
            0x02D5C0B4AAF83947ULL, 0x68516C30C74003E6ULL, 0x9E02547D559AB38AULL, 0xD799811F409AC6A7ULL, 
            0xE003C3578664B89CULL, 0x60CD30093C594EE1ULL, 0xFEBB3EBD5F0DF40EULL, 0xC39A7D853D7B1C23ULL, 
            0x0E425B31162A0EF9ULL, 0x969694BEE5ECE1A7ULL, 0x17DDB7DEC055E051ULL, 0xD9885FFF1F2A7276ULL, 
            0x341A046C565F58DDULL, 0x557F3C094E19791DULL, 0xEC48D949669264B3ULL, 0xD102D568F8706EA5ULL
        },
        {
            0x1184B1066F81DC01ULL, 0x663006D13F2CA931ULL, 0x1485180A98B5C1AAULL, 0x4AF696AF66148519ULL, 
            0xE0E8A887150B1C3DULL, 0x280EBCACDF0A7324ULL, 0x6571B9A3C8EA09B6ULL, 0x182D7F93B730B504ULL, 
            0xFFA25DF2D9E4ADA1ULL, 0xA17D85397517918BULL, 0xB7F7904CAF7F8F07ULL, 0x079E521C1FC56DD6ULL, 
            0x85BD6085DA7337F3ULL, 0xC61BD74A64A5B7C8ULL, 0xFCE2EFC0C0139756ULL, 0xE5E8B895A8ED671CULL, 
            0xA97CC592FF5B1FEDULL, 0x83AD2AE5BB37B3BCULL, 0xD197C7141C1685A4ULL, 0x85C010B1CDCC6A33ULL, 
            0xA7D90AF88FE3F8E4ULL, 0x57E130408A5DDBF2ULL, 0xE77DCC458A70AB0FULL, 0xE4EF4DEF83DC42C1ULL, 
            0x8AA8584295A7239AULL, 0x4691E709D0BC580AULL, 0x2561DEDC3CEF042BULL, 0xFF1562C41FE49675ULL, 
            0xE2B1B911FADED526ULL, 0x53E2EED54CBBD9D7ULL, 0x0204E68909D8A570ULL, 0xAD003FF18737A9ACULL
        },
        {
            0x1BCBBBB7507AA5CCULL, 0xED03E7AFECD219C9ULL, 0xD866A2A4E4D26886ULL, 0xE613B56E6129246EULL, 
            0x9E05A653B3904776ULL, 0xCD7B38C836E49423ULL, 0xEE3CF24ADAE64830ULL, 0x10CA8FBB3DC02A50ULL, 
            0x482E3A947CC49A25ULL, 0x62E9492CD7902E88ULL, 0xA487EFCDBF398870ULL, 0x993BA3AC523F5CE1ULL, 
            0x5AF97B5D9CA20702ULL, 0x6BA93AE842E1C46FULL, 0x0D55732F301ED719ULL, 0xD3C13C66B8CDF013ULL, 
            0x257309E2E31EFE6DULL, 0xCB564BB88609611FULL, 0x622C870FDEE81530ULL, 0x5CABF483199505E4ULL, 
            0xFD573B32D53AAAF2ULL, 0x74A42BB6DFAC2FB5ULL, 0xEFBA9F58DA3B241FULL, 0x1071AAD9D3877C85ULL, 
            0x5A1001AA68492693ULL, 0x74E93B38CB86DAB4ULL, 0x9E8CDAD7A20DB317ULL, 0xFA09292D3AE71A0EULL, 
            0x630C62995006B120ULL, 0xFE2FAFF2A5A72B28ULL, 0x2FDEC663A34A2EC0ULL, 0xB806BB87FC721B58ULL
        },
        {
            0x2778AE8BE9CC3238ULL, 0xC6F63021A15C7790ULL, 0x646BAF9CEB6A01F1ULL, 0xE8C13F349E454733ULL, 
            0x31DA6BA82B35EF53ULL, 0x13B147A21AFC46C0ULL, 0x3249AB615C242F3CULL, 0x0B1E55148AA4FD55ULL, 
            0x4E991DFD957EFEA0ULL, 0xDE1F2311F328E26EULL, 0xBEB3ED675A5AC902ULL, 0xE4E3E778FEAC6FABULL, 
            0x04534800377AA357ULL, 0x5C08B4CE47C0DF0CULL, 0x62FAD2BAA47EC613ULL, 0x5BFB2C4BE533AEACULL, 
            0x14FA9F47D5231355ULL, 0x7489F0FC2E8BD157ULL, 0x2F3981DFAA184D05ULL, 0xCDDF04E50494A4F2ULL, 
            0x4418C1D04CC9F69EULL, 0x4FAFED98D772D4AFULL, 0x78E3660ACE9415EDULL, 0x22D77012B4243BB5ULL, 
            0xF3CD47905AC33BE3ULL, 0x96F1D67E4E0BB6C4ULL, 0x655E5DE3E03FA942ULL, 0x89BCCD5ADC399243ULL, 
            0x22E755FCCB0EF4A4ULL, 0x3FFFC4A4483A50EEULL, 0x65A7EFA7F3132900ULL, 0x9D3DB42225EE6775ULL
        },
        {
            0xA53B453B6F6576B5ULL, 0x122A05D2330B9090ULL, 0x326319BABFE1A157ULL, 0xAC9F1266195D2D78ULL, 
            0xCFD17A636F8FE313ULL, 0xB3D5BEF777216AD6ULL, 0x8DB30E70538A6052ULL, 0xD74D0B007D7B237AULL, 
            0x1DD391AFBFF49CD5ULL, 0x94743829AB68C865ULL, 0xD978E4F2E6D7CB43ULL, 0x81B3A5E270E1D905ULL, 
            0x09A66F9C1AC0BA01ULL, 0xA67A718160D01864ULL, 0x8FC63C3212123991ULL, 0xF392EE74C2E92AB5ULL, 
            0x1DBD037945915902ULL, 0x9A05289B9C6D34B1ULL, 0x4A9529C5DF90FB47ULL, 0x6283AB53814F36A2ULL, 
            0x1E1494152E49793FULL, 0x139E932FF398C9D1ULL, 0xE56CB278F084D21DULL, 0x94A22BC9477C6E0FULL, 
            0x21F39577F8CB3C00ULL, 0x2B220B7F5FE7A3C6ULL, 0x293D7006B8F4B407ULL, 0x91B298F423FDED6FULL, 
            0xD9FB2AEC3139E6F6ULL, 0xBC1AB5B29B746504ULL, 0x2F6FDDE5129B6A3CULL, 0x024401F83C809454ULL
        }
    },
    {
        {
            0xB990024933730CDCULL, 0xD7B4B4FF256376F4ULL, 0x78185788B0B93C65ULL, 0xED6490B8253F8CAFULL, 
            0xF0BEE04D29907A20ULL, 0x841EBD4E44882404ULL, 0x9B9A4980FC47DAE6ULL, 0x4E9CDAD66680DAA4ULL, 
            0x6EE6CAB5BF119A7FULL, 0xC275CE09B74838F8ULL, 0xAE1AB296A2D3021EULL, 0x994FCCAFB25D5F94ULL, 
            0x6330C957935E6A28ULL, 0x9C2BD691B67E4546ULL, 0x1D220AE118BFA400ULL, 0xCEE8DE6EC7E56714ULL, 
            0x875098498B535A64ULL, 0x54F3C6F5AF8B0B1FULL, 0xD469DA25BBD72200ULL, 0x05D4163AE1571DB8ULL, 
            0xB4BF51C4D7665A71ULL, 0x581FD80E7DD21C88ULL, 0xC7D71A6FA9041154ULL, 0x537EC5BAC0AB47C0ULL, 
            0x1649437984BEE7F7ULL, 0x2321642C55A78E5EULL, 0xEB6DC90A41D8F6E0ULL, 0xD91EF01A5A48368EULL, 
            0x9018564069D2A0E5ULL, 0x55773D4CBA846764ULL, 0xB861CEC8FABC9203ULL, 0x9E2460FCF05BF92FULL
        },
        {
            0x69C052EC4B6CB24DULL, 0xE65549BCA678564CULL, 0x5BA068100D94047AULL, 0x0FC90340461D6EAFULL, 
            0xB799647FA3E905C3ULL, 0x01712EC1B32478D3ULL, 0x1C0BA01BCEB441A3ULL, 0x35EB686D6963BC3DULL, 
            0x9F945C9763DE0D55ULL, 0x5A0B92355962B92AULL, 0x6D19E3664BBAD7E5ULL, 0x51115C19AE21F297ULL, 
            0x320FEBD15D842DE2ULL, 0x71A2B7EE7DA5F075ULL, 0x1C68DC4DFCBA5103ULL, 0xEE8931E4F022F196ULL, 
            0x27F5053F97E2325CULL, 0x289A342E61B67A21ULL, 0xB5E92255E763B332ULL, 0x8F71550994040519ULL, 
            0x63A96808E02445CFULL, 0x8505DD26BF17CD81ULL, 0xF1FEC9F15E85DA81ULL, 0xD06746E34C69BC01ULL, 
            0x40B033CEADE1F4F4ULL, 0x587430195A331E08ULL, 0x605642C15EE28674ULL, 0x3BB04F7F22369417ULL, 
            0x53EAA1D021BBE7ABULL, 0xFD259D008146346FULL, 0xF280C2A1A4D86210ULL, 0x7CE2B10591173D90ULL
        },
        {
            0x5F1D4FBCE01B4FDCULL, 0xDA6E83819576D17CULL, 0x50707EC4540FC3DCULL, 0xAA5E0B3728AE4A8AULL, 
            0xEDE7423DEDD79757ULL, 0x96A8C0D7187FA32EULL, 0xA22FA0E5A257A8AEULL, 0x5FCCB7E54FE83293ULL, 
            0x65CB1E7E22B8331DULL, 0xE47A96EA84788C7EULL, 0x7F6AF056CC457DDFULL, 0x7073B512A84DE69DULL, 
            0xAAB578EA9EE94BF1ULL, 0xE3747D63CDD1CA36ULL, 0x2937B7C58317FD6DULL, 0xB411A73FA295CA1BULL, 
            0x5447C55B1F02D041ULL, 0xA0A0D277BF1DE65EULL, 0x77C024DB38A2D1D6ULL, 0x9F98B4BA5C8E1308ULL, 
            0xAD068AF11E2914B9ULL, 0xF88F5EE9F626847FULL, 0xB8B373A533FA6D8CULL, 0x6EEBE1F96DC6BDB6ULL, 
            0x349AC70EAE28EE78ULL, 0xCFDABCFABEA9B815ULL, 0x43DB1F826F29D6D9ULL, 0x00EB0B97674F3705ULL, 
            0xC4ECCD84359F4F98ULL, 0x7B482FE5FF96E6F4ULL, 0x4D7410BC589DFB9FULL, 0x66EBB9F870E9D605ULL
        },
        {
            0x8955C756AEA4D61FULL, 0x57532F73520183F9ULL, 0x0C34A4F2E72870F1ULL, 0xDE99B1FA246E5BBBULL, 
            0xC91821C15111AE05ULL, 0xD2EDD9C7DFF455B4ULL, 0x935861F2D980FBD9ULL, 0xEEF121F58B55F083ULL, 
            0x986FF323B4A38F47ULL, 0x3DDF8874A979CA48ULL, 0x5EA8C7B4D3207713ULL, 0x129E9C4C022E8A33ULL, 
            0xE0EB174244A39247ULL, 0xFC7C6872B454D6D3ULL, 0x7B1B9C8C032EC81EULL, 0x222EB882E4D771BCULL, 
            0x82F747508B9763EDULL, 0x101BCCD814E59441ULL, 0xAE012C0D43CE2E96ULL, 0xE04FB847BD15B88BULL, 
            0x5B029C19FDF093DFULL, 0xED353A20B919655CULL, 0xC7D4017379E05123ULL, 0x11F851E252332CA3ULL, 
            0x01F832193721C9E5ULL, 0x9A7CAD41824CCE87ULL, 0xA57AE3E130553909ULL, 0xE551478711D6CDECULL, 
            0x4FF1B5C0AFD0E1FFULL, 0xBA06635A1DBE8F83ULL, 0xCF03468B54930852ULL, 0x6AE67570DBC6F472ULL
        },
        {
            0xC5506344A9857039ULL, 0x7A3412EDAE24CD0EULL, 0x0C0FFEFE55D096B5ULL, 0x2C387619DD67ACFBULL, 
            0x9BB865B995753063ULL, 0x4E1636694D9E7874ULL, 0x441BC6F454CE6B31ULL, 0x059C4E561DB0D069ULL, 
            0x0C4BDD6C3C3461EDULL, 0x1BD618C836D8092CULL, 0xD0AA24013541054CULL, 0x58C9EDFF72872134ULL, 
            0x7C5833A994A1E5D2ULL, 0xD56AF944C294DCB9ULL, 0xCF49E4A62E65A85AULL, 0xADAAF5721333D205ULL, 
            0xEB221BD91B54758BULL, 0x7CFADBCFF828405DULL, 0x3BBF895B18FAED07ULL, 0xA8D45082BAFC1604ULL, 
            0xB2AE86E28C140000ULL, 0x2B7745B5CF63BEEBULL, 0x8AAEE86278D66401ULL, 0xB03A868A5EA7AD77ULL, 
            0x80E9738E88B15F5FULL, 0xDC8CDCB6E5973DCDULL, 0x9CB43E7CA50F9DE7ULL, 0x6430A39CFD21C854ULL, 
            0x43D20487961D4305ULL, 0x90ECD03AC07F1FA7ULL, 0x9F62D2CA5A4D4770ULL, 0xFC59721D76390B85ULL
        },
        {
            0x7934432756206BF5ULL, 0x4D726DF96F65003AULL, 0x096453EB67114E07ULL, 0xB7A951BEC0CE690BULL, 
            0x249423263F050CDEULL, 0x783C126F12FF8FEEULL, 0xF29C9239214FD07EULL, 0xEDD221763422589EULL, 
            0xDCC43BFE0F126649ULL, 0xB3B814BB6E6322CBULL, 0xED8C33ED5D74F8F7ULL, 0xADDB86BAB28C5161ULL, 
            0xCB6914314F90B649ULL, 0x456174F2A31F81D6ULL, 0x23D7AE546F2830D6ULL, 0x39BC2C00E202879AULL, 
            0xD5308A179C943D59ULL, 0xDE94CA2512936F91ULL, 0x2E9AF3A1498F970BULL, 0xECE4D4FB0F9D1B8AULL, 
            0x073BD1F681197693ULL, 0xE7BE68A40985077AULL, 0x6C203C2E3F5E05B6ULL, 0xE737B8F803669CC9ULL, 
            0xD1CBB638665F76C5ULL, 0xAFCA44B36DB42058ULL, 0xB0AF4FF5E28073E6ULL, 0xCB465F0C1F2D1F67ULL, 
            0xAB89BC9AC63C9F67ULL, 0x3A3CDFCBB5052260ULL, 0xED99FBE9F9A1E82BULL, 0x63CF9A95FB9A4A9AULL
        }
    },
    {
        {
            0x0A30CDB039C0301EULL, 0x2B223FFEBACF71F8ULL, 0x8B7247376D890BB9ULL, 0x5F1C699FFB902C3BULL, 
            0x19D78843D47E2521ULL, 0xEE4E96B7AFFB8369ULL, 0x10981D6C075588BEULL, 0x8CEA6BDC14769C4BULL, 
            0x1509A158DE6BAEA5ULL, 0x9F4001550B19DEC6ULL, 0xF5E3C6855DABC650ULL, 0xEA4CB054C2FB4108ULL, 
            0x4F8B308B428F65CAULL, 0x002DE1D54BE06D16ULL, 0xFBE313577D688BAAULL, 0x632F6D06231FD96AULL, 
            0x2E50771168504490ULL, 0x7D3E2A41E5579244ULL, 0x0401F4BC837AFA98ULL, 0x5D47C65821CABEDEULL, 
            0x7993F9CC4CF25DECULL, 0x3C5156EA68A781C9ULL, 0x1F0AFA3DDCDE30A2ULL, 0x2D2288E190204C8DULL, 
            0xCCA08AD181908A6AULL, 0xAB05BBA4C6323224ULL, 0x3F82B2CE0EEFAA65ULL, 0x7D4BC7F70BE7EF84ULL, 
            0xC6662736E56753F6ULL, 0xA1ADADA0155A83DAULL, 0x76423AA5E1A1BAE6ULL, 0xDC4229E4C47BFC8DULL
        },
        {
            0xF9E1D43E47D3CC34ULL, 0xDE728231186161D9ULL, 0x744E0C9EDF727D18ULL, 0xB01B008034DAB048ULL, 
            0xC2C0D8C028CE1EB0ULL, 0xD9051A3ADEC1E3C7ULL, 0x741AEAB05B88DEE0ULL, 0x84C90068DA7C8205ULL, 
            0xF2E184559916EB3CULL, 0x37353F07774F5898ULL, 0x31563841A75B4D0FULL, 0xE5BCDFE87244D36BULL, 
            0x59555246CFE0EF80ULL, 0x6EBC1746579F470DULL, 0xBDFA41686C66EDEFULL, 0xD6BA5426F903F625ULL, 
            0x0618ACBB9B270023ULL, 0x3C2167BC3F42C7BCULL, 0x42C8E2A4FC4A3DC9ULL, 0x9198A1AB3DF15E94ULL, 
            0x58FBCE6C2CB645A8ULL, 0x929F0DD4551ED3B7ULL, 0xFF66D9EB8A2A0630ULL, 0x1A629B53439C2C4BULL, 
            0x81705B2F51A289F7ULL, 0x70AD5D55D3B4E6A7ULL, 0x8CC6796CE76B8CF0ULL, 0x70293E234A3CF5BEULL, 
            0xB7AC84FFCCCAA321ULL, 0xF6F5FCF2B434DF47ULL, 0x71B48A64CD7B62DCULL, 0x5552CE16595B5722ULL
        },
        {
            0x60A3F9D616A0EC8FULL, 0x39E409028F882708ULL, 0x95D3030937641093ULL, 0x091DE6EFBADD7CE9ULL, 
            0x37A293830AC49BC4ULL, 0xEB408F713A21DB6CULL, 0xB362CF303E676BDFULL, 0x607E242FFA16E49CULL, 
            0xE70658FEDEC9AF39ULL, 0x567CECC590675A44ULL, 0x1850BB5F4F95056AULL, 0xEAC033EFE85D3044ULL, 
            0x3127143CD9B8C361ULL, 0xF42688040120FFA3ULL, 0x8C638FB61707D37CULL, 0x10C7E89BCBE5E80DULL, 
            0x06718E1CC7070CD0ULL, 0x75252640F6C2C7A4ULL, 0x28C3FD3E2F6462FCULL, 0x48273AF688E6E57DULL, 
            0xBBF9C46EB7E9B5A4ULL, 0x01F1D04E86C21A75ULL, 0x9F0F466505A9C08DULL, 0x03110523D48CA1D5ULL, 
            0x891C7DA5B0CE4D8DULL, 0x6E48346FE32CA070ULL, 0x801BA360AA41DFD2ULL, 0x61AE7C636FF16BB5ULL, 
            0x02C4A971928F1218ULL, 0xF36CBEC836B088D6ULL, 0x3E2B230701DA5D0AULL, 0x62885CBD7BF9835BULL
        },
        {
            0x453D9B44508BA97AULL, 0xAF4B492C23A66593ULL, 0x4A5B254AE9275ECEULL, 0xFCB88289434D8ECAULL, 
            0x65A0B67013C9AF0EULL, 0x3DA48FBA3774BAEBULL, 0x99A5FCF6EFAE9636ULL, 0x46E8D0D65C7F4066ULL, 
            0x770739B8E83B96CCULL, 0xF7D911FE5FE1F929ULL, 0x9A8FD03E0099D77FULL, 0x5A6E54DD93D00862ULL, 
            0x8DBA31B7E70E9287ULL, 0xC5D757A0AB12A171ULL, 0x9D497F6A472DAA5AULL, 0xA7E4A9F0772C4AFCULL, 
            0x9AC780D5BF870042ULL, 0xEE8355721979F804ULL, 0xF62FED7D8FADE2E8ULL, 0x80E460E2877875AAULL, 
            0xDEB68C1B55BBB208ULL, 0x3A162B2878835052ULL, 0x2660A59C3E8E9EF1ULL, 0x8A3580658B40D271ULL, 
            0xD22B96124D97538FULL, 0x681C9AD67DA91B2AULL, 0xB4F56BCD85EC8BE4ULL, 0x444781553811C00BULL, 
            0x526D4DF1F3A228FBULL, 0x0EAEBC7D787E6E4AULL, 0xD0EF2844DE7F26AFULL, 0xC1EB02C53DF38633ULL
        },
        {
            0x2D8569D95803C930ULL, 0xD869AC10E2E6ED0AULL, 0x5BD8B6AE78ACCDC4ULL, 0x92BC2F126668BFD9ULL, 
            0xB3207A61B589BE21ULL, 0x6EA985C34A69F4BEULL, 0xE1631A1971756D97ULL, 0x3D4D959CF71F192AULL, 
            0xD4DAE8CAE3502F71ULL, 0xF1F420E7B4AC06E4ULL, 0xC217A34E88D8FFFBULL, 0x64936B1681D62FACULL, 
            0x2EEF76B56A16AEE3ULL, 0x9EB0AE22F42BF403ULL, 0x4D628D15B4C0B44DULL, 0xB084F7170B95427BULL, 
            0x64C7996F69DF99D4ULL, 0xC0D826625CADC4E1ULL, 0x73B9FBB4DD917567ULL, 0x716E60550EB3479DULL, 
            0x7BE6AEF9AF79B8B0ULL, 0x7267F45F07F1C9BFULL, 0x111E6BA8FB3E38C9ULL, 0x198B3A71A339DA1CULL, 
            0x09485FB1498184F6ULL, 0x5EA977F2C877D7A2ULL, 0xF2D442963536E476ULL, 0xBCC5FF88C812A968ULL, 
            0x2984A495DE60935DULL, 0xC0F5F898747330C1ULL, 0xA4D3E4417F7A3B1EULL, 0x803D42F6974C4189ULL
        },
        {
            0x75A9E6F5FF0FC778ULL, 0x91ED0F433C637EDEULL, 0xA2A500570402AFA4ULL, 0x27828712BB916C3BULL, 
            0xC13AF5E74D243BD8ULL, 0x4A4E4CBC13BE8038ULL, 0x6BFAA1ACA32507FAULL, 0x031B46047009E919ULL, 
            0x5101101EEE268895ULL, 0x87C2AF3B8A81D7D8ULL, 0x87A1C3D40481EFF1ULL, 0xD764198B4B497D43ULL, 
            0xF6F195923CD71B26ULL, 0xFBE760CCD59015CFULL, 0xD9930D18773F92DFULL, 0xCE319882C5443FB2ULL, 
            0x1205F714D6411B39ULL, 0xB7809A93B999C402ULL, 0xD68129969E1A046BULL, 0x9AA105DCDF57DB02ULL, 
            0x4C3F9BD003C9AE12ULL, 0x370980437087D43FULL, 0x964E18E04AA76F00ULL, 0xAC0A2A51A536CB8DULL, 
            0xB39F2A221313FC93ULL, 0xE38654B7058B2A32ULL, 0xF7E5985EA932BCE6ULL, 0xFA1F7A948674EEC9ULL, 
            0x263B6380B5B0B0F7ULL, 0xFE5D0C74D1EA41CCULL, 0x34BEE6F01925BEE7ULL, 0xFB2404A23206BA36ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseBConstants = {
    0xBB481875498E42E0ULL,
    0x5573F3786057D531ULL,
    0x24A8F2D223E1C3AEULL,
    0xBB481875498E42E0ULL,
    0x5573F3786057D531ULL,
    0x24A8F2D223E1C3AEULL,
    0x40671915C07B01EEULL,
    0x7EF431A7E684F5B9ULL,
    0xAC,
    0x87,
    0x1E,
    0xA5,
    0xF3,
    0xD1,
    0x7B,
    0x69
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseCSalts = {
    {
        {
            0x087A480DBDF9E772ULL, 0x26AE33F8A566FC90ULL, 0xB6754ED8112B54A9ULL, 0xF0D8654346FE76FBULL, 
            0xE9D060FFE7EDEC20ULL, 0x26EC6211901009FEULL, 0xF16C83B8510005E0ULL, 0x244FF28D8F548697ULL, 
            0xAC1133CB68E4FF18ULL, 0x046AD17C2851029AULL, 0xB256A3D16E938EB9ULL, 0x27127CBB5AC93DC0ULL, 
            0x0FC2A30331653E1FULL, 0x1F8AB6700868D591ULL, 0x20B3BA81369E6D4EULL, 0x839E5F0CC70726FCULL, 
            0x34E3CB34BCCA0233ULL, 0x4F220309DB3228D7ULL, 0x370F8D9A4CEF8B58ULL, 0xBC31E1C6D9A45B3EULL, 
            0x52179214696928D6ULL, 0xF7A5DEC78632E0E0ULL, 0xC0D190A5B8A2895FULL, 0x02C4CF9747DD51C2ULL, 
            0xABAB07EA8FC32A11ULL, 0xBD19B51656EC67F9ULL, 0x0CCCF871984B3B94ULL, 0x15126B0B505870B2ULL, 
            0x4082753878F4A87DULL, 0x6CD2DC3272F39CA1ULL, 0xF447B902F272F1ADULL, 0xEA5084E5DDAF7F62ULL
        },
        {
            0xF43A33FEF2B87F6BULL, 0x764A0C38B83DBD86ULL, 0x1A40BA3DAB9A7115ULL, 0x4088BFA63905DA6FULL, 
            0x562061D3DAF72DA0ULL, 0x2034EC6078B803C2ULL, 0xD3EB63A2F1D02491ULL, 0x59BC1528286E0404ULL, 
            0xAF2E019718EC3086ULL, 0xFC207CCE405334DEULL, 0x9AACCCA6D42047DAULL, 0x636E8A954ED874FDULL, 
            0x6B130ED2C19FF26BULL, 0xD96CBFB12E504AE3ULL, 0x58CA69A04F6C4F7EULL, 0xBE767B547AEF4687ULL, 
            0x55F3BEE8CA0D6577ULL, 0xDB5A26BA216102B9ULL, 0x51FB302699201AF9ULL, 0x987DC4C61A605F12ULL, 
            0x5596E149A3359D17ULL, 0x8F4A2CEB42AA2FFFULL, 0x98BFEAD860353AF3ULL, 0xD91F871BB7F3EBA1ULL, 
            0xC3DCE020EBB4911AULL, 0x3EE38F8A37624E16ULL, 0xC05CF20A1B759C2CULL, 0x46445380FC3A52F5ULL, 
            0x6B60EA2DAF6F62A1ULL, 0xE716308AA3A8970AULL, 0x2DC3CE4E1910E748ULL, 0xA7B1A25546C69BE2ULL
        },
        {
            0x7FCB3D6628612986ULL, 0xEDAAE7AA77E7D667ULL, 0x8BF1BD94CE3A88F0ULL, 0xBAC3AC380F264880ULL, 
            0x00BF10227435F49DULL, 0xA4BA20537DCDB6CBULL, 0x9EC700357F5192CEULL, 0x1EA0C007F5F7F868ULL, 
            0x4F95AE8AEA84AAE6ULL, 0xCA966E0211305BACULL, 0xF27AB2C5956A80F2ULL, 0xFEF4D23D56F47F67ULL, 
            0xD2333EB0A954F56DULL, 0x03A274826E3B9B79ULL, 0xE8C15787A7E44510ULL, 0x74C51545BEFCAECCULL, 
            0xA0091906566F3CF5ULL, 0xEFF7C455FF29E7E7ULL, 0x0B5975FCA2ECA8F7ULL, 0x4355FD8252DF542FULL, 
            0x0B1F1EDD0820EC12ULL, 0xC38BB57E893E69A3ULL, 0x324302D39E38ABC6ULL, 0x163EF31F70046922ULL, 
            0x0A08AFBF22132C4FULL, 0xED95F9D3E46ABD70ULL, 0x19D2E836E9EDC922ULL, 0x0823F4728A0AE3C7ULL, 
            0x63EDE6913D673DCFULL, 0xB3500883C693DE15ULL, 0x685F64903B5FF19FULL, 0xD58BC1C7C41CEAC4ULL
        },
        {
            0xBB6AC5DC523D1FA6ULL, 0x7FD08C7ADC444CF3ULL, 0x4711779B3A85DA66ULL, 0x9859C7097A3804B4ULL, 
            0x4A18F3B12092F2CBULL, 0x4D9F64149F3FFB53ULL, 0xDE0CE38A7A613DC7ULL, 0x92DBE751BF211354ULL, 
            0xABE1F692AFE7209DULL, 0xF76C28B11EE02C77ULL, 0xD62E15C65E03A496ULL, 0xC2BA69947BFB8872ULL, 
            0x6B78EE06E2B6B985ULL, 0xBD2A4CE39EDD6528ULL, 0x20663E00747F71ACULL, 0xEF21B4F61D0E0302ULL, 
            0xDA6182AC4506DFADULL, 0x5653B5DAC58329CBULL, 0xC50C641BAB2D185BULL, 0xED7B9EEA1689A79CULL, 
            0x697DDEC1EEB32720ULL, 0x85244A94FD625ED4ULL, 0x5455A2472A1A1405ULL, 0x7119915CDF13BA6CULL, 
            0xF9032135691E89A7ULL, 0x8BAB46E6143E99F3ULL, 0x73D3D116C1567D15ULL, 0x9E715BF5598C1C49ULL, 
            0xB9F50D34F1AE5B56ULL, 0x6319DF111CD270CCULL, 0xA51D9859CC9FA9B5ULL, 0xD9E2D5583C2732FFULL
        },
        {
            0x80F6752842F941F0ULL, 0x7A77BB09DC0723BAULL, 0xA51DA0361FB5C183ULL, 0xBC25CC1BE7E748EFULL, 
            0xC1321CDDCF812A49ULL, 0x263F6B7CA93B2F2AULL, 0xD5F565CFC8AE4D1DULL, 0xF0D2E8FE03D4BB5CULL, 
            0x209CD0502D3990DDULL, 0x059E1040F603062AULL, 0xB21905BB8A71BE16ULL, 0xF882F4646C1B87BDULL, 
            0xA1B6560AAF83C51CULL, 0x49AE87D513A6DDA7ULL, 0x479339C7C710499AULL, 0x9A567284EC9B286FULL, 
            0xE52FFD9349B7D922ULL, 0xE942B6D2DFD8E3EBULL, 0xDEE4EC9C36D01C2DULL, 0x3856DE2AFE21725DULL, 
            0xE9A81D659D9A84C8ULL, 0xFE1687076EF2236FULL, 0x442A55CE5C9605EFULL, 0x623643B504B70A72ULL, 
            0x332163DD8EBFAD15ULL, 0xEB818D2426CD8E3AULL, 0x4721A05475C1F9AFULL, 0x17BD8957A5341667ULL, 
            0x3E60A695C24C5631ULL, 0x8F7459C622568DBDULL, 0xFEB4BB716476991DULL, 0xEC06E445B6C6D7B3ULL
        },
        {
            0x4D00A3E77552ACBFULL, 0xD43B6F5AD220C59AULL, 0xC1A0BBD7C05AD46AULL, 0x5BFF3CC371C74D34ULL, 
            0x5B4853CF22225B65ULL, 0x7B08DF781AC1257EULL, 0xCCFEF042690AEFF1ULL, 0x699BE2278FD564A5ULL, 
            0x35D6FFBED0153100ULL, 0x4C96F1A2406B627DULL, 0x38A18C99AE4A8361ULL, 0x28F9C15DD1CE1B3FULL, 
            0x7B3C72BEA5237D5DULL, 0x57D4582C10B3F918ULL, 0xE048881E314D233BULL, 0x7285F80E1C338ECAULL, 
            0x8BDCDF97C87CCF6BULL, 0x5B456D4CAFC22F29ULL, 0x866A0367E48133FDULL, 0x9FFBD673A8250970ULL, 
            0xBA8FD5D630306A9BULL, 0x7039EB7C580F37BEULL, 0x8E17621489375270ULL, 0x92807AB0CC11C90BULL, 
            0x29F298CE018DABA5ULL, 0xCE34A3B491F93602ULL, 0xAD14C9185C1310A2ULL, 0x8803976015F95B78ULL, 
            0xCB73B1F17CCD485CULL, 0xABADC9CB00763EE5ULL, 0x6076B7D6E7417A8CULL, 0x9DB3D89EEC2ACB0AULL
        }
    },
    {
        {
            0x7435EC99ED6E5D50ULL, 0x33AA2D687D18AE9FULL, 0x55787E81DBACBB08ULL, 0xC129305636C821AEULL, 
            0x0B0D8F7F24FB2673ULL, 0x77B25099E5970F2FULL, 0xEA3BC91556A46D15ULL, 0xC19013E201BD0F95ULL, 
            0xE6641BD0B80D0D6BULL, 0xB90929E51E16A30BULL, 0xA0EC9E1FDD56B0E3ULL, 0x8AFC373B24746F8AULL, 
            0xFB5E69E9C612D4B2ULL, 0x865AD6C2D7402FCBULL, 0x1959975014120709ULL, 0xA79A89758A438217ULL, 
            0x35ECD237DD71790CULL, 0x5158D92BD549C1DEULL, 0x517069A9E4C8F968ULL, 0x3286897D7F23F417ULL, 
            0x6244E0BF0D8DF989ULL, 0x61DA770A6FD6B67EULL, 0x577A509B044F60C7ULL, 0xA721A45F3B078458ULL, 
            0x145BD81DA60D1D8DULL, 0xDF987FE463B082F4ULL, 0xDC69BACAB3CC03F4ULL, 0xAB98C21A34B84C58ULL, 
            0xB45BB1A93F836F06ULL, 0x961AFED96D2855BBULL, 0xC3064951CD91FCF5ULL, 0xE13E94B8D2F5B855ULL
        },
        {
            0xB128ABC420F42D41ULL, 0x1D78D66BA3673AE7ULL, 0x07F1E37490E26B43ULL, 0x518500F43B8D3D40ULL, 
            0xA803C161BC739585ULL, 0x720EEE995C0E06CDULL, 0x6CC0F9F1F0B0DDADULL, 0xB4B505C397D1FF11ULL, 
            0x59D45B7F7540E9D1ULL, 0xFE413F3412295971ULL, 0xDDB270B3B357D1BBULL, 0x46E9CEA813040DB4ULL, 
            0x01D4C0CCF9A39340ULL, 0xAB48AE1840267DA0ULL, 0xD6D57D76BFDC0DEAULL, 0xD72F1DF5343428AEULL, 
            0x2997388E0F975BFBULL, 0xDCBBC39B42D22B05ULL, 0xACC9A3F752384B4EULL, 0x76AD5BC7C3876DCAULL, 
            0xE155D984A691E93EULL, 0x30B08E26FDF98F97ULL, 0x4DD1B1BF7BCF4E60ULL, 0xDF4B50E7BEA90BA8ULL, 
            0x15231609DB120119ULL, 0x8DF4EB48BEE3BDAAULL, 0x08E5ED5EE8B32865ULL, 0x01B547F9084D07CCULL, 
            0x36970F18C1C54A52ULL, 0x3E219E7C3169FE54ULL, 0xF4DCA00F362926B7ULL, 0xB9879399EC6F4A91ULL
        },
        {
            0x986F31AFE2FDF675ULL, 0x418B8DC7DF148ECEULL, 0x8F5A6989475A5EACULL, 0xD0B54BCC4D162E04ULL, 
            0x8F791B9E56590C01ULL, 0xC45D20D73EA49C3EULL, 0x7BD45B797FEED7D2ULL, 0x5F1BC50E042B4EDEULL, 
            0x5E9416BD122239BAULL, 0x2EBA0464D1C0EC39ULL, 0x0A3944DBECE7E92EULL, 0xADC65F1E4599DD88ULL, 
            0x7A03FC41BE159831ULL, 0xDF69DCE0AA86C60CULL, 0xFB643202BE4F0B2CULL, 0x4DDF279055DBB467ULL, 
            0xAB599562F6CE7758ULL, 0xC182BD742E1FAEECULL, 0xEA054C5B0110A861ULL, 0xA3CCA559502F1792ULL, 
            0xA22BC283ED9849FDULL, 0x45C74A1CDE92D20EULL, 0xFC330B60B0731273ULL, 0x63D0682B8D4E682AULL, 
            0xEBCE75E9CBE190E2ULL, 0x4B78663769918AFCULL, 0xE6AEA31B514F2519ULL, 0x5C5A7C0CC4F6126BULL, 
            0x572F0B23A18C5DEFULL, 0x9FEDE96E9AB709A4ULL, 0x53007E3D8A8B50CCULL, 0xDC297A46E678178EULL
        },
        {
            0xECA72C06293D391DULL, 0x73C45FD08EF95314ULL, 0x0309689CF77E27CDULL, 0x15F105AFBA18BE42ULL, 
            0x7051EB9EEAC488F9ULL, 0xB4B5A1B2B4B8D470ULL, 0x260A324D2DF5337AULL, 0xBDDF339D7B532A40ULL, 
            0x11210C586B58EBEFULL, 0x0A86E1D244A90695ULL, 0xB1EC3E72AFB336FBULL, 0x49CC8C912245A646ULL, 
            0xCEF25B67DE31BD76ULL, 0xE8659FA6AD70B893ULL, 0xD10B9ACC1236DDA8ULL, 0x1CA221CABF018223ULL, 
            0x5AA02CACA65FEEBCULL, 0x3C042125E7704581ULL, 0x595D2A319A0E44FEULL, 0xF92EBBDF9F470B2EULL, 
            0xAFC5B6F1769610A6ULL, 0xFBC8DDE82259F861ULL, 0x2F55548B736D7058ULL, 0x0E448BCAF8B3D203ULL, 
            0x9D2A7CE70D99EAF0ULL, 0x427D8C6E87638F6DULL, 0xFE7BCE4750D73A9DULL, 0x11F4A334AA668F34ULL, 
            0xB88ED383F5D8BF4BULL, 0xFF27D0D93FC489AFULL, 0x68FC7B77BAE77672ULL, 0xC966E1770A451D5BULL
        },
        {
            0x8951255326A85D80ULL, 0xAA2AC35FCC67AC4EULL, 0x0467BF891F4F94AFULL, 0xFD80FCE9DDEB34F8ULL, 
            0xB9AD98B7A09CFCF9ULL, 0xB3903BF57BC80452ULL, 0x300F1ADE6229EC6EULL, 0xAFC963DEBAD74E69ULL, 
            0xB5334AEE7A701FD2ULL, 0xC139E7E1D6398274ULL, 0x907524EB1DD52551ULL, 0x045E6DF4AD333419ULL, 
            0x01A63DEE6BEDFEC7ULL, 0xF43FA813445C2AA8ULL, 0x3813B5F7B5BB9C91ULL, 0x0F8433E8AC099772ULL, 
            0xCBC31580DDD1DA7EULL, 0x40C06A37AECD457CULL, 0xF80FE2F19D7EA039ULL, 0xB44B2F1F6FAEC60EULL, 
            0xB41785B93AABA21CULL, 0xA8564FED422A6563ULL, 0xFFA30CB24A104049ULL, 0x1EFA1FD7F69D9D8FULL, 
            0x2C33B3FC1F1AC599ULL, 0x80EB5C94BE2FC9F4ULL, 0x98D91F35FD1416F7ULL, 0x5BE690135341DA55ULL, 
            0xDDE82D739DF516CEULL, 0x5F25D92CF25171A6ULL, 0x62D17955E8E003DAULL, 0x430855F9D1FF2B97ULL
        },
        {
            0x230CD5F5B132ACAFULL, 0xB5D6D546112192E5ULL, 0x83FC2371691B0A62ULL, 0x8EFE7969BB401ACDULL, 
            0x33D11EDE140257B6ULL, 0x71C065407B9A7745ULL, 0xD518C31951ED2BEDULL, 0xFD17B9B060652F44ULL, 
            0x7E76771D9E8815EEULL, 0xE77247B75AD06465ULL, 0x8FE3420A3B30CFE1ULL, 0x715D582B2A5E3F07ULL, 
            0x7D319A53D991C0C8ULL, 0xF7F25073C61DCED6ULL, 0x07BAED3FEC945127ULL, 0x4D2C4E390CF50BBEULL, 
            0xE357C4D598EB0D3AULL, 0x51E60490ABE00D50ULL, 0xB09BACCF9290AB2AULL, 0x51FE83A8758144B9ULL, 
            0x6C1727F5170A72B9ULL, 0x346D662156126668ULL, 0xD490DD24522FDC3AULL, 0x15F51AFFBC1B0977ULL, 
            0x223CAED35072BDE2ULL, 0xD3FC9A5846FA9414ULL, 0xC2986186F89A6D8BULL, 0x06CF5A4CF6AEE57FULL, 
            0x2AB64CAED8833EDFULL, 0xBF9A4CFD45981DB0ULL, 0xE520A19398BAD1F2ULL, 0x6775D7F6D0A9BCF5ULL
        }
    },
    {
        {
            0x3BBA39EF8F90E571ULL, 0x34E5D5D5813F4692ULL, 0xF0FCA7B8A552265DULL, 0x80153B2CEFFF16B6ULL, 
            0x80BA70AC485F7085ULL, 0x3805F350A5D2ADD4ULL, 0x7C54AFF002B3A1A4ULL, 0x4CE8ECB5F92E3EA8ULL, 
            0x831C073C58ACEE0DULL, 0xB9BD5B255B0CD0A0ULL, 0xCA62EC9242C96906ULL, 0xA3175D049E1C22DDULL, 
            0xD7385692A085D313ULL, 0x6E02E4FB38AE7CA0ULL, 0xBEB601001A39A54AULL, 0x2B43727230904AE3ULL, 
            0x5D229E23E61148EEULL, 0x3FDB59F7E6506BEFULL, 0x797236D31FC3401AULL, 0x5FF8320BB0DEF317ULL, 
            0x93365348E71ECB86ULL, 0xBAB918AFAE704CEDULL, 0xF477947313C689CCULL, 0xB86AC8136053A11AULL, 
            0x1FA40116DBC76570ULL, 0xFC03C7718A447716ULL, 0xAF8242C8D14C1BD4ULL, 0xCB6DD1EB3F0565CCULL, 
            0x858DE096287DEF22ULL, 0x38DD03715C435073ULL, 0x1AFB9F66D29DF9ECULL, 0x81C0EFBCE4C660C2ULL
        },
        {
            0x73EB187AE616C9F5ULL, 0x0E2DF7B837512B53ULL, 0xC193016B61B8D972ULL, 0x7C1E0249E64F3CDFULL, 
            0xBFFD964AF29BCD65ULL, 0xC0FA7EF7430006DEULL, 0x291DB7CF6526A00BULL, 0xE4E31D36242FB528ULL, 
            0x49E4CCCA0A39A700ULL, 0x8AC3AA2E56769ECCULL, 0x73ED7B6493BF84FEULL, 0x85F083F24080025BULL, 
            0x137B01C4FB1D4BCDULL, 0xEC5F28521279B890ULL, 0x987D6E6F5B7C9F8AULL, 0xE8A04541A337B51AULL, 
            0x09B41FD5D7B094A0ULL, 0x24F4995DB87212FAULL, 0xC3EFBCBB5EA7324DULL, 0x9B4D25092CB0BC18ULL, 
            0xB8DA397B7F73BFB6ULL, 0x2EBFFB62B967AE2DULL, 0xB88D972E4E0079FEULL, 0xF34C05613B5EC006ULL, 
            0xAB85173198ADD0A2ULL, 0xDBE542A5F366423FULL, 0xB7767A634E3122FEULL, 0x67B2412D15EDE259ULL, 
            0x5EF2AACA8401FD1FULL, 0x9B92C7DDBFED9720ULL, 0x85F53C88F37A7BD4ULL, 0x5A36F42F4DC35845ULL
        },
        {
            0x187E39427A6803D2ULL, 0x509479AD58F4CE25ULL, 0x18F04F99BD591772ULL, 0xF0BBD47FD5F8FE0DULL, 
            0xE95E732C76928F99ULL, 0x194CB191C79EC598ULL, 0x5AC15F67A01A1252ULL, 0xA3366B98A4280D99ULL, 
            0xEF34B1715399A4A2ULL, 0x5EF94AE597A997DDULL, 0x5645FE22E6191C51ULL, 0x260137166DAEE579ULL, 
            0x35C7D3F10FDA9192ULL, 0xF593674EBD194785ULL, 0xA3B39DEB9AF5414DULL, 0x42F3C4FDB264BBC0ULL, 
            0x96ABFD2273F51FB0ULL, 0x1A4171AE982E5FF9ULL, 0x1C69983AEE7EB8F1ULL, 0x9B9DA4C2D182F5A7ULL, 
            0x735A1DAA3CF7F652ULL, 0x2F98A434E5EE2935ULL, 0xBE44D9967A95255EULL, 0x522B10DCF3C866CEULL, 
            0x41FED97E7CE924C9ULL, 0x63928E8159DF51C3ULL, 0xDC907D3BAA5F4272ULL, 0xE4541360D326EB64ULL, 
            0x92434011DBF30FEEULL, 0x4329540F0957E103ULL, 0xC02DCAA46955D71BULL, 0x0A9021C6B88D590CULL
        },
        {
            0xBC5EEDFF8EBFEC93ULL, 0x4E6CE18331E8460DULL, 0x14AAE40968C6DAC8ULL, 0xB652245355C5D41AULL, 
            0x17EBA3968D264245ULL, 0x9835D9CDA934DF62ULL, 0xF8A5CB0CF3BBA25AULL, 0x45EB02BE913096D7ULL, 
            0x7DEBED5BE4C0E578ULL, 0xA8F1F11ACC9CC5BBULL, 0x28A4E695F7C5B8D0ULL, 0x31AC3267F815A986ULL, 
            0x5EF9679285E76B71ULL, 0xB10D4E258B685868ULL, 0x850ECF991539B3A4ULL, 0x077F0DBE576A3EB2ULL, 
            0x0F68ADE634891520ULL, 0x96F2A9DFE205057BULL, 0x4562DE6775AD0F1CULL, 0xC4663F6327DE2823ULL, 
            0x45C5BC4C157B1D95ULL, 0x9D3120C7F1CB2B58ULL, 0xC5163CF1C3F8FBCCULL, 0xC61F5190D5D51197ULL, 
            0x8FF731A786F9CCCCULL, 0xF0B4A604657402CEULL, 0x55DC2D3DB74737EAULL, 0xD6C17A886D8C9967ULL, 
            0x17B605FC10B54E86ULL, 0x6F3A09F2E7B3057FULL, 0x099B347F054C79FFULL, 0x605E133422419F25ULL
        },
        {
            0xA35ED729C512B457ULL, 0xE8861FE21CBF91EEULL, 0xA881EAAF59F46AA8ULL, 0x36FC67CD6B03A50EULL, 
            0x57B2504D49B40F24ULL, 0x6AFBF7D11701CD1EULL, 0x1532F459E7CF2DA7ULL, 0x1309B35F7B2616EEULL, 
            0x92664C0E670D22C3ULL, 0x2F12F4120C062AC1ULL, 0x8AADB287EB81201FULL, 0x5B499C225D14FE10ULL, 
            0xE30100D9C8F9B1ECULL, 0xB8F20151E98D2B0AULL, 0x039F6FEA27E6A0B7ULL, 0x1D84331EFEE96C5AULL, 
            0x0A13543CF1B48B37ULL, 0x56B4CC8DFE8B5617ULL, 0xDBC7A36513A55D89ULL, 0xBB354C15901FB586ULL, 
            0xDFE7B4C26F34428BULL, 0xC6720EA86E19D150ULL, 0x9338FAEFAD1FF521ULL, 0xF6B0BF53873A8317ULL, 
            0x2037011DE56DB15AULL, 0x184C7F0C19D0AB37ULL, 0xF19B5EBBA9B2A0A0ULL, 0x2D2CC56FD1D157DFULL, 
            0xB07F44C5BBD94DEAULL, 0x9BD38F65A0EC67CFULL, 0xC27B7900288D1C4DULL, 0xC9195A8E3726440EULL
        },
        {
            0xEF987ABE16B934B4ULL, 0x29DABEBD55DB759AULL, 0x51798E72AE68FE1DULL, 0xD73568AA52DE8E52ULL, 
            0x97291820D3D68C8EULL, 0x69FE15F3DDE9FE82ULL, 0x9C96CA1D50D44892ULL, 0xAE195FEDE9476AEAULL, 
            0x2178DBDBD7196A0AULL, 0x84260CB4AC187172ULL, 0xD97A8144623B6F03ULL, 0x8E260D0F95E78283ULL, 
            0xA2B8344044769358ULL, 0x805A6548BE6A8D4DULL, 0x3E3C17D80616A26CULL, 0xB7454408D4223E7FULL, 
            0x2666F058AB4E9499ULL, 0x582416A486BD9998ULL, 0x8B6B43848E63799FULL, 0x830A1F3563537FFFULL, 
            0x84720739600A68BDULL, 0x233BC3EFA74B53A7ULL, 0x23B7252608ABA2C0ULL, 0x111381C6A0AD3932ULL, 
            0x2521E91EE2B1B6E9ULL, 0x929703F04B1BA230ULL, 0xCDC1AC27347B9776ULL, 0xD741B7C8B73702DEULL, 
            0x776519BD6E5F740EULL, 0xD9C7AD0DF15EE739ULL, 0xF2076A98E6E2F1A5ULL, 0x49746B6077803817ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseCConstants = {
    0x0FF88C30F2565ADBULL,
    0x1335899B99E6B790ULL,
    0xB2E1CB3C4488AC58ULL,
    0x0FF88C30F2565ADBULL,
    0x1335899B99E6B790ULL,
    0xB2E1CB3C4488AC58ULL,
    0x945FA9B0469115B6ULL,
    0xEE6155C454F10701ULL,
    0x64,
    0xFF,
    0x32,
    0x67,
    0xA2,
    0x1D,
    0xF4,
    0x41
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseDSalts = {
    {
        {
            0xD93266145351A3E4ULL, 0xF4E88BC2AFA4C689ULL, 0x85B07D43AA325A95ULL, 0xCEF79ED805BC1B63ULL, 
            0x56228623E47EC537ULL, 0x14C32D7A83426DDAULL, 0xAE74FC3AA08B7A72ULL, 0xB27562C6E3B87356ULL, 
            0x2B05A4DB54878D18ULL, 0x165822A972416A3EULL, 0xC40884B51FF8AD1DULL, 0x74B6BC48A6E31141ULL, 
            0x7D14023184EFB912ULL, 0xDAA1B47804B03EE5ULL, 0xBE9EEEBE316CA2C7ULL, 0xA8366622A43895A3ULL, 
            0x80E6F86D8663F75EULL, 0x5E37F5BE2F3B7608ULL, 0x3865E025EB0AD4A0ULL, 0x88527BC8372D653EULL, 
            0xFADF74C31011E11DULL, 0x9BB49A1C454ADD3FULL, 0x0C49B159A90B26CAULL, 0xC0A7FEF0B4BED5B9ULL, 
            0x6CDABE7139069323ULL, 0x83D3759365A268CDULL, 0x3A284DFCD5EC16F8ULL, 0x4F0C177D26CC8D27ULL, 
            0xEAF621F3C1CFB59CULL, 0x210A1C68BE40954DULL, 0x717C35E08E7945FAULL, 0xE51FAF76FCEBC235ULL
        },
        {
            0x969F49E18E1151FEULL, 0x58F78ED5B29BFC30ULL, 0x638B84EAED870EEEULL, 0xA1A6B7E0E66D8BC9ULL, 
            0x7F33FA18516FFF70ULL, 0x811545274352AEE3ULL, 0xB84470CB260E16C0ULL, 0x5E05521AFD5DE439ULL, 
            0x5C6E735AD6490C6AULL, 0x702D22E1BD531C19ULL, 0x96232D5C251DB64BULL, 0x61E034779931EE85ULL, 
            0x448883D558716109ULL, 0x392803DE7691EFCBULL, 0xD346917A576C7872ULL, 0xC74B468412107875ULL, 
            0x3E072447849CBAFEULL, 0x5F897972EF927AFFULL, 0x52FB95C8DACB9AFBULL, 0xF8D47D96DDBE05A9ULL, 
            0x1F8530109790D6AEULL, 0xFAF4F8EE3CD9A6CEULL, 0xDEA2C142C3E095B8ULL, 0x1617164992FDFCB1ULL, 
            0x28FF1EC12A76B208ULL, 0x577B50DC47F2A552ULL, 0x7C17D4BE194175E0ULL, 0x62688FB1021BB0ACULL, 
            0x507C18DB3A18AEF6ULL, 0x3363C7A9E6340310ULL, 0x5BB45488A9394B79ULL, 0x7552FE1115B806BEULL
        },
        {
            0x0EA27095A407D81EULL, 0xA5C667B5D3896D5FULL, 0x328EB4224BBADCA9ULL, 0x965C5F3FD62FB361ULL, 
            0x84F74B5D515C62CEULL, 0xE5EF1BB00D58817AULL, 0x9892A42F38BABF27ULL, 0x675738E46C707088ULL, 
            0x6608F26062E174ABULL, 0x766ABB72D2F30317ULL, 0xE24C3F9CCC61CEE4ULL, 0xCB829F7BAD32BF12ULL, 
            0xBC7795DCD48648D8ULL, 0x4254F42365A1D9C3ULL, 0x5B7EAA9F31F03A08ULL, 0x9FD422F5AD026CD6ULL, 
            0x17D7FF7F3F4DCB30ULL, 0xB0626B1189E094F3ULL, 0x0BC9955F64A3890CULL, 0x5978A2BD5BC8A837ULL, 
            0x1497710EFCA15468ULL, 0xEEE3E69D7F733852ULL, 0xF40E080A9A6C3460ULL, 0xB90754C040931D19ULL, 
            0x45F018EE419C0D42ULL, 0x9116696EF2A19D8CULL, 0x49B55C2107BCFCB1ULL, 0x6D9DF7A31DFE0433ULL, 
            0xB8C0FD8242601A95ULL, 0x4DB90FDE2B2B287BULL, 0x23F5E696338DB72FULL, 0xCEBDF835870C0401ULL
        },
        {
            0xF132BF4BC8B8B350ULL, 0xF76B51AE8CCA41E6ULL, 0xDF1104079D9BD477ULL, 0x9EF4A5BA01DC7C56ULL, 
            0x3B72B79EC3E7CCCCULL, 0x51252970AA97B2E0ULL, 0xB540232B3A7A6F72ULL, 0x3F940148454D6CF1ULL, 
            0x0F81EFAA416B4135ULL, 0xE84A4E99738734EDULL, 0xD126FDB9035A41DEULL, 0x09B8E924EE48BF52ULL, 
            0x747C71E15E8FA433ULL, 0x86823F0431D68BDCULL, 0x80EE61696E45333CULL, 0xBA4165E6DE2488B5ULL, 
            0xB5CEB6334111585EULL, 0x80BFF295C4363D88ULL, 0x53EF2CF2F1EB2F52ULL, 0x65B432F6E578218BULL, 
            0x65FA35A106CB0D21ULL, 0xA6EB6078FA86F156ULL, 0x9891EC3CB2E91E0AULL, 0xD7B5DFFB29AED2D3ULL, 
            0x26B0A23FD65918E8ULL, 0x5C11F5E4F250F230ULL, 0x4C104D610CA12A52ULL, 0xC9593A887D38637AULL, 
            0x64FCD4601B5CCA5AULL, 0xAE4BB48E1BF6621AULL, 0xDEFB82B96F10EA19ULL, 0x8F09F7F074C396B9ULL
        },
        {
            0x3072816AF957E967ULL, 0x7E688E6FE7306B85ULL, 0x42C085AD190422FDULL, 0x4B457DE82128E09FULL, 
            0xB2A0F4ED3243E528ULL, 0x65D32A495E4554AAULL, 0xFAD0CF0940732599ULL, 0x7E31E87B8093297FULL, 
            0x889499A72260BE67ULL, 0xC0C341DA32922AF8ULL, 0xEAFB3BD8EC6B2117ULL, 0xBD3E57C6F9675753ULL, 
            0xE7577A3DFCA9C1AFULL, 0xD0FFFF5905A24E62ULL, 0x5A59230D0866145BULL, 0xB5043F51754D738BULL, 
            0x3B139E48C0D39DF5ULL, 0x393F64DC4FB3AD02ULL, 0xAB601218F7A86A71ULL, 0x46D07B93B59D8153ULL, 
            0x52444329D2066FB2ULL, 0xBE0B561B6F4B3C2BULL, 0xF6AFF716B1011AB5ULL, 0xF0C63484AAB01ABFULL, 
            0x3AD27869B3CE4DB8ULL, 0xA76AC547F99B1CBFULL, 0xFD5179CFF2D99D46ULL, 0xCE4759BCDEB7953FULL, 
            0x952DDCDED4161C70ULL, 0xD1820E82E5D04268ULL, 0xAC69BA495C481422ULL, 0x9CD5462C0FB19115ULL
        },
        {
            0x4BA2B2BE1D36E19DULL, 0x2A4DA4E05E1F4D9DULL, 0x967B7ECA553284B3ULL, 0x577A70B7CAC8AAC5ULL, 
            0x4712101649D34032ULL, 0x77593A0363FD4435ULL, 0x28643015130B8199ULL, 0xD94D3BE10B2617CFULL, 
            0x38CA2EBAEB8BB989ULL, 0x559275797DC30A96ULL, 0x494A2B4CA506B1ACULL, 0xE1A322213CE9A7C3ULL, 
            0x1BBAE18D9EFB31AFULL, 0xAA1239BA3F7D902CULL, 0xA3C97881418D0799ULL, 0xC7B7B95B28D6EE89ULL, 
            0x1632B5B88B17E744ULL, 0xE4055315D62820AAULL, 0x509F296616687BA3ULL, 0xC5BC8666F946A163ULL, 
            0x94C44A11D909047FULL, 0x72BBF322D1F55E13ULL, 0x6F7FB42FD32BB6C9ULL, 0xD24DD6D3A961BD16ULL, 
            0xEB3CEEC570233147ULL, 0xDC673EF2E81A6327ULL, 0xD97D2D2644CCB675ULL, 0x066CE222DE94DFBAULL, 
            0x61B6CFD5854093AFULL, 0x5F50A5C5CB65B8BAULL, 0xED29F6BD9538907EULL, 0xF7FB7CDD6D19AC08ULL
        }
    },
    {
        {
            0x31F6C4A2838654E1ULL, 0xE8C4F1E7EEDE2D4FULL, 0xBCC2C46404F87EB0ULL, 0xF5AA3821B2AC7D74ULL, 
            0x5B9BC523D846FAC4ULL, 0xAF68338964DCD628ULL, 0x7D9DBD7AE136975BULL, 0x30670CB0434409EDULL, 
            0x78FC30911807AF4FULL, 0x3D87DC8D1558B807ULL, 0x3F8C80402F341489ULL, 0x6CE21452AF9CC497ULL, 
            0xDAAC653E5991C0B5ULL, 0x5404456E75961D5EULL, 0xC75B6B77D155E723ULL, 0x715A049D7994B39DULL, 
            0x54C131C568055BB8ULL, 0xDA6F590459F05F35ULL, 0x857BAB7A313E8A63ULL, 0x37127FAE361AB5D9ULL, 
            0x9125D169B9CEE4CEULL, 0xFAC0B161E6559FECULL, 0x0DBCF8919B839BA5ULL, 0x3CB631CA4FA8BECDULL, 
            0x657E4642858C71ADULL, 0x8C33749C4A1030EDULL, 0x4D6A2509ECD0AB14ULL, 0xAD91589C1038E7A4ULL, 
            0x502154B3CDA184CBULL, 0x7827D0188174D305ULL, 0xF99577AE4D3BD573ULL, 0x810B97717E3891A3ULL
        },
        {
            0xA92C5CC8A1A3C597ULL, 0x98BBE2669A85ECAFULL, 0xA6C741DE7D57CDCEULL, 0x1F9154472B7D880BULL, 
            0xA6AFE7B984495A1AULL, 0x3199248A25229505ULL, 0x6663C48C1A86B906ULL, 0x4D7ACFD1F7CA3088ULL, 
            0xFC979AF87A431793ULL, 0x4E5506DC9EF40C5DULL, 0x1EB48FE6A9C5A0CBULL, 0x94D05EF2A70C86D4ULL, 
            0xD29D23099C2D4CD4ULL, 0x524AB64C87CC073FULL, 0xDDAB1509E818D57FULL, 0x8F2160F7E66F6347ULL, 
            0x663C56DF001BB88DULL, 0x721421268A047623ULL, 0x570B516DA0808814ULL, 0x18EABB709F818742ULL, 
            0x4E214F3C1123ADA3ULL, 0x9A7EA125D6971385ULL, 0x55E097777C37AF95ULL, 0x9D308E235D41EE1DULL, 
            0x1FB2157136D3A2BEULL, 0x048C4719B6A62D13ULL, 0x77211444071CFDBEULL, 0x502A4C8BB772A1C9ULL, 
            0x10D6D6AD68A9E718ULL, 0x8EE51D270BC92DCFULL, 0xE0CBEEAA736E4F15ULL, 0xE46F2F8AB0E691FCULL
        },
        {
            0xC08B0C6415E94056ULL, 0xC14F3DA800A74C44ULL, 0x099EE8C681128BE0ULL, 0x5AC77571898AE336ULL, 
            0x52D601FF7926260CULL, 0x2E6B79C91D2E22F5ULL, 0x3A4FDF6EF822173EULL, 0xDB2E41E558DA4189ULL, 
            0xC5AFD45CE3E104A5ULL, 0x3ADA3C0BCAF79EF7ULL, 0x70363460B5E044D6ULL, 0x63C1300D5C808967ULL, 
            0xE1F5291F040AE4BFULL, 0x4F6C698AE65F49EFULL, 0xD49C97A201571547ULL, 0xCBF49206FCEB86B0ULL, 
            0x13DBC3EFC6023B66ULL, 0x511631217E62AF08ULL, 0x32B517C78ADC7835ULL, 0x95BF77FDF79599F5ULL, 
            0xE368D969D520EA4CULL, 0xA866DCE7BC3AF9E1ULL, 0x35606B9C91EACB4DULL, 0x71864E02064499D0ULL, 
            0x241159626C4E434AULL, 0xC3515A03D339BF61ULL, 0x421E3AEB7E17C3D5ULL, 0x3BCB2D939E1B1CD7ULL, 
            0xABCF46512E53F733ULL, 0xE80E83123874D22DULL, 0x0B2822D7EF31BA1EULL, 0xD6FC5E26CC7E03CFULL
        },
        {
            0x896542292DA595CAULL, 0x9C1EAEF23E035F87ULL, 0x3CD57D204F378C8DULL, 0x20FE9A210ABFD908ULL, 
            0x55ADDC13B3079D40ULL, 0xB21FCB612B54840EULL, 0xBD3AB8D37076EFD3ULL, 0x35C31E390F83A7ACULL, 
            0xBF64E01618510BB1ULL, 0xA1DD8F3C54BA78EEULL, 0xE086228D0E39BED0ULL, 0xD45043CF9E66081BULL, 
            0x9858B88F26784BB9ULL, 0xA231520741828B77ULL, 0xC4CACE87D43E772AULL, 0x5F664FDEB762986BULL, 
            0x154D68E1E6E8E553ULL, 0x4459AF2587A3D26CULL, 0xE81BC0AE432961ABULL, 0x471D97FC2275FDBBULL, 
            0x8A8DB96BC88A8E17ULL, 0x9DC1E2273ED1ACCAULL, 0x4E95EC411397AA68ULL, 0x8210F05AE9396AF9ULL, 
            0xB551F7CF6DB3F1F9ULL, 0x3DF637C36DC65B45ULL, 0x6189EB6D93E428F5ULL, 0x0565C2F4FE7103A2ULL, 
            0xA9C0378D683A2AE2ULL, 0x69F49D78ADEDB889ULL, 0x0EFCC6A7F60E33EAULL, 0xE087199983004A36ULL
        },
        {
            0x0388290B2F8BDFEBULL, 0xAA196637B0BCED85ULL, 0x6434BEBE84DBA483ULL, 0x776C71745A8E733BULL, 
            0x7D38610C3983F4DCULL, 0xAA1545E672033610ULL, 0x5767820293746119ULL, 0x952012FACE20DA74ULL, 
            0x662860BCB06F8765ULL, 0x314FA648158DDA53ULL, 0x22C7BE1C2408AC94ULL, 0xAC356AF6FF90AADCULL, 
            0xEDD2164F57A359BBULL, 0xF166EFFEE2AB02BCULL, 0x9FCC2C8727E5A035ULL, 0x1697D2197ED76291ULL, 
            0x8AE3CE3A66CDED3CULL, 0xAE6AF993E3C72251ULL, 0x6D9C576736B9DC49ULL, 0xDABC58B2918D08BAULL, 
            0xFB9CEC0DDD71113DULL, 0x99EF9DC3674B47E8ULL, 0x4D6594BFB616E931ULL, 0x327C9CFEF92AF3ECULL, 
            0x03455243EF67F526ULL, 0xB70B09B9B954DFD0ULL, 0xE4C4F05BE34947F2ULL, 0xA093FC0C452C7E0EULL, 
            0x101BB5599DFAB488ULL, 0x0ED52964160BF914ULL, 0x13391DAB1C82C352ULL, 0xC643252A07288A5CULL
        },
        {
            0x8C4153F1F070D4ACULL, 0x73D3411D95CB40B1ULL, 0xB292DDE56A1A0F65ULL, 0xDCA8E1DAFC3DF476ULL, 
            0x0393EFD2D12549C7ULL, 0x0E24EDCF57E1BD59ULL, 0x0EC564AF9DD5FD9DULL, 0xDA028DE82C41A3E0ULL, 
            0x652951E0CD89D616ULL, 0x4B1BE772D71F8BDDULL, 0x376BE5C4D838ED78ULL, 0x3E25C873DA61121BULL, 
            0x8D182E3A4B257257ULL, 0x32F120943E763422ULL, 0x524D19A07B93E119ULL, 0x9B547104B29F9E85ULL, 
            0x58CBA40659F98873ULL, 0xF0F838F6F291FAE8ULL, 0x484433BFEB1E2E02ULL, 0x07B96DAB94CE492AULL, 
            0x1C3688AAFC7DECFCULL, 0x459E8B73300F2858ULL, 0xF1606E4802A685ACULL, 0x81651B3A2605473DULL, 
            0x0BB94A2CC0E8DD93ULL, 0xE36521D161B68FE2ULL, 0x230566E1F5B4E815ULL, 0x75C374A470C41E13ULL, 
            0xAD527898405A1252ULL, 0xEA9AE9A834065CFBULL, 0x3AD2F7CB7C7AB124ULL, 0xA131F7C40E79FCA1ULL
        }
    },
    {
        {
            0x113B35EFEEC0A7D0ULL, 0xDEFC3445B7B1C7E5ULL, 0x5876D6B2142D43E8ULL, 0x731AE7903978BBE5ULL, 
            0xECC359F16B12662CULL, 0xA0E39C27D5C3356FULL, 0x6FD9A912CF3BD183ULL, 0x45A69B260743B79BULL, 
            0x2778D2BA5E9D2F6FULL, 0x07A622B89A1A5F87ULL, 0x538E3250077B4430ULL, 0x62934A3D894369E5ULL, 
            0x67F8703053C15278ULL, 0x6BB68D98A924D890ULL, 0x96B76BCE3F542622ULL, 0x2E981369E4C9B07CULL, 
            0x7DBA7EB76777C8F0ULL, 0x4753B162E6FA93A5ULL, 0x461157136513AFA7ULL, 0x56D07001B84F4A2AULL, 
            0xD7566590231C83CCULL, 0xB2CB853AA8D98E7DULL, 0x49A8BB24B0B0EF69ULL, 0xA6AD680611D33ECEULL, 
            0x217251FD19346F5CULL, 0x64FE62DA1B21AE53ULL, 0x2B0877498250D98BULL, 0x5518D44C13994A86ULL, 
            0xB1292C0710420429ULL, 0x71ECF1BCFE7D4D10ULL, 0x43876D485C538BE9ULL, 0xAECEE71078A62C68ULL
        },
        {
            0xB627B5F9A4428C10ULL, 0x2E2FAD6FCE3AA401ULL, 0xE3DD2C41945EBE33ULL, 0x5AB1BFA5AFF8486CULL, 
            0xEB2BFEAEF2BEAA4FULL, 0x6F53B48A5AB39802ULL, 0xC3AF8C5760E44042ULL, 0xCA67DAE622ED9C92ULL, 
            0xA1EA850025658E2EULL, 0xE8F4B8CFBBD62BDAULL, 0x7E580106AD70ED64ULL, 0x298CE75F6931AD97ULL, 
            0xD6BA2D5D4E55A729ULL, 0x353722EFB9404C23ULL, 0x4E12E3FBE9E464C6ULL, 0x2CBB02094A8F1C8BULL, 
            0x13C2DFE455155F14ULL, 0x521F7ED5E9AA8707ULL, 0x086C1759A2E7D155ULL, 0xD7260474E30BFE6AULL, 
            0x3558642BD76DA9A9ULL, 0x26B0D6928386763DULL, 0xD24CFB92A5FDE652ULL, 0x0BC7FC39F48ED198ULL, 
            0x4230A191FE4AE9C2ULL, 0xE561F02B781334A5ULL, 0xA771C5C10D04DDA2ULL, 0x07D83A40F3395A95ULL, 
            0x34A6303904005823ULL, 0x54218E2F5AFE5738ULL, 0xEA73B8440A868DFDULL, 0x0CE6C82902F578D4ULL
        },
        {
            0x6638ECF0EEAE8BA3ULL, 0x3A2236ECB822F89EULL, 0x1C6742BCEEBA2FB1ULL, 0x6FD6D5543373E880ULL, 
            0x246719D7C3054E06ULL, 0x0B62C86BEA1A901AULL, 0x568443D5AD34CFAFULL, 0x49ED13B31249623DULL, 
            0x8FC79570C8458C8DULL, 0xAD99D6AEE4656B59ULL, 0x35F2DAD15B20F6A2ULL, 0x86500EF177376BC4ULL, 
            0x5BDEAB178D38E76DULL, 0x14DA5B8437AC83D2ULL, 0xCD031009F711871DULL, 0xE0B808D116F27906ULL, 
            0x2A7BCBAE73137E81ULL, 0x55D2B49397EC1A73ULL, 0xA7188C5CC832FDDAULL, 0xC4752601A39D3611ULL, 
            0x8A8D66E8351E59D6ULL, 0x86229F188142E4B2ULL, 0x25418EAF39585840ULL, 0x16F74383830890A8ULL, 
            0xC79CA3A4B2751756ULL, 0x0CEAB2A147D2BBB6ULL, 0xF63683917ACE7885ULL, 0x65718FE224F7041AULL, 
            0x3EF96B95459C58C9ULL, 0x7AA267EF30E53ED0ULL, 0x49D5F26FFB5415B9ULL, 0x6B61B6F29320790AULL
        },
        {
            0x8A256CDE1C0B9750ULL, 0x50769ADFA6E52865ULL, 0x99BB921A7E633987ULL, 0xE74986D5F97A8606ULL, 
            0x6C76CB82751D400EULL, 0xF6E517C425F3AA67ULL, 0x4375544378C1F020ULL, 0x8FCCFDB9B4BFE0B7ULL, 
            0x6A1D836A3CB6B9EFULL, 0x779F94AF2ABE8CE2ULL, 0xB8379C5DEC2009FAULL, 0xCC320842CFB62A19ULL, 
            0xCE6BCF0184D1B3B7ULL, 0x681CC4816FC3E992ULL, 0x6552F041B7A90D46ULL, 0x4B3CD2EF4DBED7D0ULL, 
            0xDBA5F8DC32221751ULL, 0x948FB76CE37B57A3ULL, 0xD4EED1A0C52B79F6ULL, 0x83C1CB34E6828DB5ULL, 
            0xFB919857CF6333E5ULL, 0x669A495E0A629F03ULL, 0x2EF5F3746CFD450AULL, 0x45CFFD3224D10D8DULL, 
            0xFB6275D7489A3731ULL, 0x5C0C98BBADADD098ULL, 0x09C93816FF272EF4ULL, 0xB13D123FA8C29EF0ULL, 
            0x7B025E72EA7EE096ULL, 0xFD0C4C4E0912D917ULL, 0xF43A1ABBB34114A8ULL, 0x721B0B1C1CC1E4D8ULL
        },
        {
            0x59D6759F2BA49BEFULL, 0x85FA13818DC52127ULL, 0x44026C67FF8851A7ULL, 0xA5C01909E0678A43ULL, 
            0xE2C2B6F5E90251D0ULL, 0x9686E69AD5A9BCBDULL, 0xAD80C8804975A142ULL, 0x7DA66095F273D73DULL, 
            0xFB6B42A1BF6F10DBULL, 0xF199B44F2904220AULL, 0xBD6390542C7C6F96ULL, 0xFF7F3C38E4D92AD5ULL, 
            0x85296C07EA3DEF10ULL, 0x59DEF3B2980C7248ULL, 0x6DC722E950C02988ULL, 0x72977D476D91EFDBULL, 
            0xC9AC2DC12D625796ULL, 0x76824E385E3D5087ULL, 0x81A7BABAAEF83920ULL, 0x6B32C1FF7C8929A0ULL, 
            0xBCD57E6804E961ADULL, 0x10C2D63D5F5ED250ULL, 0x2105E7344F6C9A6CULL, 0x72A942B305FB4786ULL, 
            0x535E163E15F4CB2FULL, 0xE6E25CD9CC9511E2ULL, 0xBE68706D277A0B39ULL, 0xBDAF6F0A1B27A2DCULL, 
            0xF617F28C6381D8A5ULL, 0xF2A128DA84174903ULL, 0x1B66AE8971C4BC10ULL, 0x56F0F4FAFDF2E9F1ULL
        },
        {
            0x25C7898A028B612EULL, 0x85A973B08C36E0E5ULL, 0x89287BF765E8F368ULL, 0x9ED382E314AEA1E5ULL, 
            0xEFC95BCA16420397ULL, 0xA0EE3E4D3F1EF3DEULL, 0x3AA6220A8B1101EBULL, 0x3329CCE116496F0DULL, 
            0x516DBB4FADA5D556ULL, 0x4A974DDC4C10D97CULL, 0xB6C54E68E1FB0E27ULL, 0x44220217EE75EBEAULL, 
            0xCA904613216CE2DEULL, 0x1C03613E1BC27B5CULL, 0x985D5BAED75755EAULL, 0x547B7B03C7F57844ULL, 
            0xFE5FF9A7166B7158ULL, 0x2E609773A6E03AE1ULL, 0x4D97E5790BC0BEB3ULL, 0xE481C70FCBEDDCCEULL, 
            0x862E39ADB1D22CB8ULL, 0xF4306B310B0923B8ULL, 0xDCB77A9D2B217099ULL, 0x5CAEE082F2A51A6AULL, 
            0xC4B673D057F46436ULL, 0xC2494A43F83F8850ULL, 0x7DA9C9843E573F69ULL, 0x3E45E84765960037ULL, 
            0xC2F508288CF9D9BBULL, 0x91C0139627AE6A26ULL, 0xD9D9C908A71CCE04ULL, 0xDB0A282A6A6BB759ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseDConstants = {
    0x6E31A723CB8AEE76ULL,
    0x9D5F58CB9AFB8784ULL,
    0xE0665D1C2D97809FULL,
    0x6E31A723CB8AEE76ULL,
    0x9D5F58CB9AFB8784ULL,
    0xE0665D1C2D97809FULL,
    0x14348A8A5083B046ULL,
    0x1C3AD395AC6EA31CULL,
    0x28,
    0xF6,
    0x51,
    0x18,
    0xC0,
    0x03,
    0x5C,
    0xE0
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseESalts = {
    {
        {
            0xEF78949390ED9E62ULL, 0x3277E64E1DCAB69BULL, 0x2CB4C51992388278ULL, 0xAB480D81831CD21AULL, 
            0xF0354587E425BEF7ULL, 0x2EA7A79C62AE0D68ULL, 0xCC862350BF3439AEULL, 0x92725AC0F1867B6FULL, 
            0x255C96A446B961A1ULL, 0xA0688CDDCE1463F3ULL, 0x100B59870D63E380ULL, 0xDF83BCBF996B91DFULL, 
            0x8977C60F453BDE1CULL, 0x567A63BCBA3349D1ULL, 0x9CD29B883FEEAE4AULL, 0x42AE283841E73E0FULL, 
            0xA9D8F9B5BEB542B8ULL, 0xFFEB93697D38D4CBULL, 0x509F07CBADA67A9CULL, 0xFC0C4D6014BD8E70ULL, 
            0xA7FCF4C7FEA7DDE3ULL, 0x61143A68F330EAFCULL, 0xDFE54FDBCBFA4AC8ULL, 0xDEF8C4CE3AA1E7AFULL, 
            0xB2B3675EC6EC2D47ULL, 0xE29CE9D1C56D31C2ULL, 0x54FC52E3EC258C06ULL, 0xB0DD4C06F447BC4BULL, 
            0xE32D890F858B170DULL, 0x6B8EDA50407F9E0EULL, 0xA5FC47C47E713102ULL, 0xB72514787578369DULL
        },
        {
            0xE0F319E329CBEB49ULL, 0xB8158CE899C466E4ULL, 0x74D4BB32DD35D87EULL, 0xF78B9B734EDC418CULL, 
            0x9102DB2CC431AE97ULL, 0x75F4B4DA54466ED1ULL, 0xB08D8387DB6D4045ULL, 0x46F9E0759CC266F8ULL, 
            0xBCC83DA08A57453BULL, 0xE7BCD1653792A35EULL, 0x3C9B747FBFE80387ULL, 0x8DDAEF3482DE6864ULL, 
            0xC94943DB03E8FD7DULL, 0xFAB9E0A2E3BF44D7ULL, 0xD18CE2A956FA8F69ULL, 0x09188EEA55FEDC95ULL, 
            0x9705DE53F9C8C5B5ULL, 0xDD2285044B4283DDULL, 0xA8A0928F8E18A59DULL, 0x5F17AEEB44964909ULL, 
            0xEA68A8406B6E1D43ULL, 0xCEFE4C456AE8F9E2ULL, 0x6C89888B3E3EA952ULL, 0x6EE5DA38E9237E91ULL, 
            0x2C2BC7657055E9D9ULL, 0x36F43BAE0A5081F4ULL, 0xBF892E9C0005E338ULL, 0x509EB9B4A5CE8BE3ULL, 
            0xAE4B9607D977E904ULL, 0x301C4661E73637D6ULL, 0xA4457D3FE5F56C59ULL, 0xDBBD1C02840E5C47ULL
        },
        {
            0xF759A74B017E9C11ULL, 0xF8DAD6AD885169E8ULL, 0xFF112E1268006F48ULL, 0x1CFD5BB855736AC9ULL, 
            0x9472D0B52F8FA85EULL, 0x35F7085092F2D3F2ULL, 0x9A04F677DE5629C5ULL, 0xC33117B69B05C00DULL, 
            0xBA5A47E4471E74C1ULL, 0x13F3AF5E318B9E40ULL, 0x2C285AFA90AA1A49ULL, 0xAC3908765CA7AD1DULL, 
            0x2E6505B6939B78C2ULL, 0x1C1FD5786AF355B6ULL, 0x443DAAB9EAE82261ULL, 0x92E3082AE2ECF08CULL, 
            0xEAAA2A46A562A9B2ULL, 0x1E72E5DC7A3176C0ULL, 0xD0A6E9796257B04FULL, 0xA486FADFC3E9BA17ULL, 
            0x7E7C376326664FBAULL, 0xA2D5A75D774C8174ULL, 0x04FCBDD4DADAD7D2ULL, 0x9BBB7C3745BDCB85ULL, 
            0x2EED5495445CE7BFULL, 0xC12A010EE3960C4EULL, 0x51FE53D73F3B8190ULL, 0xFA45606EA6A80DB8ULL, 
            0x9CDCC5DD2089729CULL, 0x78684B8A2CEB749DULL, 0x2C2E616EC5E69AA0ULL, 0x9CFB39235F9F0933ULL
        },
        {
            0xCFBA295523D48EC7ULL, 0x64A4476E299B7AC3ULL, 0xB9E1C7C8E274C3C4ULL, 0x6737740C088A46BAULL, 
            0xE8063BFBE80CFA0AULL, 0x9B7768F1DA3E0316ULL, 0xFD675494A7451BC1ULL, 0x5D5AB43982E9C6BAULL, 
            0xFE1DE0C03A2F0313ULL, 0xBC037644D98EF1BCULL, 0xD054CD238729A971ULL, 0xDE1776218458206FULL, 
            0xE6CCDB726F1D2C75ULL, 0x4267A9E9115C9022ULL, 0xFD6338F6623B2FA4ULL, 0x2982118C4A535050ULL, 
            0x65F175ADA900F3F1ULL, 0xF94AB9C84EBA6A63ULL, 0x97EA08531695DB1CULL, 0xD9700E95D600D453ULL, 
            0xE6B66C3734CC8CA8ULL, 0x5EE228EA0BDECDA9ULL, 0xF43B1D7D33E46F1BULL, 0xA83AA17784FF5C5CULL, 
            0x72317061498EDEB3ULL, 0xB93E542425458F3CULL, 0xBA921370FE558F00ULL, 0xFBBCD94FA80EE89BULL, 
            0x186045D9E107E5F8ULL, 0xB85A7B73A2001D3CULL, 0x5D60EFF454B6CB9AULL, 0xDB6CB6E1E1A1E482ULL
        },
        {
            0x29F88F0528FD4207ULL, 0xAF70EA766B66D425ULL, 0x90B871AE99F694D1ULL, 0xD4F93CBD8CF816CDULL, 
            0x0A8A68299A154654ULL, 0xCEEE040EA48A287EULL, 0xDFB8A908B57C9D65ULL, 0x497C3B5135D37EAAULL, 
            0x2D28AF9F6EC2E266ULL, 0x32E26628B1C6E983ULL, 0x10DD8905D0A086FCULL, 0x126C92141A95F315ULL, 
            0xA192D2555326AD27ULL, 0x48A1D8AC50A62E19ULL, 0xBF28B67199A411E5ULL, 0xB6F4D4D9A6F1692DULL, 
            0x8776DFD59FB42FD6ULL, 0x4A650AE9FE08DC52ULL, 0xE5E3308641475A3FULL, 0x9D9BD473EB32283CULL, 
            0x9087080BCB96AD84ULL, 0xACB24510AB0C0118ULL, 0xBB04CB7D2BD11998ULL, 0x5CAEB54B5837BF1AULL, 
            0x7B915A4812351003ULL, 0xC1255DA53AE25C12ULL, 0xBBC42622ADE16BA8ULL, 0xD954A55D65A45E07ULL, 
            0x253585657823AE1CULL, 0x5B8560C2926FEC1FULL, 0x8B91F15A597D7E43ULL, 0x8EC528E12F454E84ULL
        },
        {
            0xC1CC81270B9B9614ULL, 0xE24C8389D20C7055ULL, 0x84DF0E1BA20C33BCULL, 0x5217F84545DAD950ULL, 
            0xCAECC9C261C6D1CDULL, 0x5B5DF5CA0B73DC0AULL, 0x339FC4571423D6FFULL, 0xF6D8895E28B51A86ULL, 
            0x54BA072BCD3A2A74ULL, 0x455E144EDABAE28DULL, 0x1D7D6F2FAC84352CULL, 0x378DCCC30A09F58AULL, 
            0x3DD7ECB2C54CAEE9ULL, 0xC2DEC97366E0C13EULL, 0x480983E3696232F4ULL, 0x16392B27E0561C9AULL, 
            0x840FEA0B4AE33B3EULL, 0xCA1E01173B254C2AULL, 0x861D66869F1F16E5ULL, 0x3707D97CF758C567ULL, 
            0x4D19C00F15ECADD2ULL, 0x9182065418EEE6EDULL, 0xA6079C56ACC7CFA5ULL, 0xC6C428E4BAFD4AF3ULL, 
            0xE5277356C567C9E8ULL, 0xEA95E3CEB1C1DC8EULL, 0xF8EF09E0CDE89AC4ULL, 0x6C7274553A6E2D6BULL, 
            0x6BA63A010AD4CFCDULL, 0xCDC0FC8B3B6E3199ULL, 0xC9BFC87DC33CF9DCULL, 0x7D597CB490728642ULL
        }
    },
    {
        {
            0xAFF29913AEE2C281ULL, 0xFE49D6E39752482EULL, 0x5CD52676BEA994A0ULL, 0xBCC91BBA7F588DE3ULL, 
            0x464241C8E27EE215ULL, 0x32C7174ADBCF6F7BULL, 0x72428591C440DD5CULL, 0x921D757DAAF89AE2ULL, 
            0x3C192525E6B3EADDULL, 0x46062BFDF8A00067ULL, 0x893E397A4B4C8918ULL, 0xB2CE8FE827CFBBB3ULL, 
            0xD16183C9AFBC8B4CULL, 0x00E4316EBE51BE70ULL, 0xD13134A7799F7F62ULL, 0xEC4E5A3E0A720B9AULL, 
            0x628A84BA9B948499ULL, 0x2B8DCA4867FF57C8ULL, 0x8B3A8DE4AD374397ULL, 0x65F593390B552378ULL, 
            0xB0A6D7208599A4C0ULL, 0xF870560902297B1AULL, 0x21238BFC754E2D8CULL, 0x24738B5BE3A03155ULL, 
            0x935B26247A58D20FULL, 0x8C0A7D7ECC12CA04ULL, 0xAB0D09B620C2A2C8ULL, 0x9A383F3D3300FE8FULL, 
            0xDEF4483956C5696DULL, 0x6F602A50DC5FC199ULL, 0xF7E71339083A4607ULL, 0x9C76309BC44A3318ULL
        },
        {
            0xC0DDBBD82CA38A62ULL, 0xA1FE36C985E81D50ULL, 0x59378420009B7048ULL, 0x13A63F9EEA536865ULL, 
            0x72BA76C03BA14D99ULL, 0xD49548C5AEA0AF13ULL, 0xDFB3AC338956ECA4ULL, 0xA1880AA417D8F8ABULL, 
            0x5B04317227E8B885ULL, 0xC699EAB549341619ULL, 0x47A8996F9F6A5450ULL, 0x066EC874861E774EULL, 
            0x2D8B12BBB430C45CULL, 0x25C0DFF96239E327ULL, 0x2537B12ECCD6B6DAULL, 0x2190E78C48377997ULL, 
            0xE6B1B6B5246B7E38ULL, 0x431332D47F4354ADULL, 0x1E1534069B90F91DULL, 0x7DD39F8BD3BAE72CULL, 
            0x5999DCEB0E8E6FFDULL, 0x4E7495BBB14A8C87ULL, 0x0D8E0C7C4811FA05ULL, 0x3156A00ED947A4E0ULL, 
            0xB868076B32B5158BULL, 0x9B42B3AEB6B6D026ULL, 0x8D81E2D07A61E03DULL, 0x6C71B4464086A9AEULL, 
            0x034FB31F6A3EA455ULL, 0x633CBE71139374B2ULL, 0x6D36F605A87E3DE1ULL, 0x62C0D1FA0AA337D1ULL
        },
        {
            0xF9296679359D6D64ULL, 0x6BE95C38EAFA188FULL, 0x06ED73E5058D4912ULL, 0x1B387D65339047F7ULL, 
            0x2A3A257AAC849088ULL, 0x229804FE51B6F4CCULL, 0xEAD2B519A1D6159BULL, 0x5EA1E60C2592987EULL, 
            0x6F0DFF2FF498E659ULL, 0x15935EBE850FC5D1ULL, 0x4B85EDAA58F66CF7ULL, 0x7ED81A9315B1C59DULL, 
            0xF09DFF2D17184DC2ULL, 0xDBF495EE7DE5C9EBULL, 0x0E61157CD35169DAULL, 0xE982AF2078427388ULL, 
            0xD87B9564771B52FBULL, 0xB56CBEF0A6C4CF85ULL, 0x2EF5E706878CD081ULL, 0x62CE76985358807FULL, 
            0x3557E27E66B31379ULL, 0x3F1B710967797CAFULL, 0xC85E7FC0C3D8CA1BULL, 0xA0AB23656B29661FULL, 
            0xADCDF8094058507DULL, 0xFAD364F67BC4B837ULL, 0xD056629618C99103ULL, 0x5F95806875CACDF5ULL, 
            0x1AE0BB034262218CULL, 0xDEB9BE488EA6C7E6ULL, 0xDF4C95E75A8F6F04ULL, 0x9AE4CABB2208DC56ULL
        },
        {
            0x30C0B71A1B5FAC52ULL, 0x069340AEDB1AE63CULL, 0x2CC6572604CAD922ULL, 0x38167544F64BE27CULL, 
            0xBF1009C01A973490ULL, 0xB5B82F0DA4C293DFULL, 0xF36F2F5FA5DE99C8ULL, 0x6182F58D51914563ULL, 
            0x4033D750B2AD635CULL, 0xEE8DD01F4D1EB1D1ULL, 0x4D1A5F62737294F0ULL, 0x9648C70CA9B6AAC6ULL, 
            0x57E86160B7DFA966ULL, 0x98479BA96DB8D589ULL, 0x87C31AA4F399A69BULL, 0x0B62BAA434DE6A79ULL, 
            0xE85489064C8921AAULL, 0x5D8395BC407B8075ULL, 0x0AEC55FB81B3BBEFULL, 0x68439987A37950ABULL, 
            0xAC05739AC5227D9CULL, 0x9CDA6CCF3D0AC651ULL, 0x4AEDCC9774771A53ULL, 0x1B3391836B9E7055ULL, 
            0x6A4BDA1AA343620AULL, 0x23E70691E08B3DECULL, 0x33CCD90CFF5258D7ULL, 0x68E64A8D4609DA5DULL, 
            0x5BC2DFFC335CD9E4ULL, 0xDE74D118DDD2AC28ULL, 0x53F5053AF338CAB1ULL, 0x74EA52ED5CEAD6C6ULL
        },
        {
            0xC669ADFED51D17C9ULL, 0xB67A65C76DA37422ULL, 0x15B7FF2FF738A958ULL, 0x708336441A047BC7ULL, 
            0xA6BB2C77B3F166F9ULL, 0xC3AA465C2F9A3568ULL, 0x06DC02271F52F17DULL, 0x1C71189951AC6C00ULL, 
            0x57264750CE2109A1ULL, 0x9419EB433743958DULL, 0x0F5995C41AC8F4A0ULL, 0xE11BE812D880ADC5ULL, 
            0xE5DDB1889EF38BABULL, 0xBF93F09F80070721ULL, 0x545F6ACFFDB0E9F2ULL, 0x78D92F228B333DB0ULL, 
            0xCDB03C08617DC412ULL, 0x9B8059D9A1515B18ULL, 0xEBFF8136184329C3ULL, 0xD4A5F8A996E2728EULL, 
            0x33F7F39916FAC6C6ULL, 0x6B3724370818F024ULL, 0x7B095BFE784591BBULL, 0x7A324D4D005DA580ULL, 
            0x9A8A10E38E849EA3ULL, 0x3802A3F244E61BD9ULL, 0xF552B80656DA4D85ULL, 0x5B06442298C32D03ULL, 
            0xD8E2817D271265FBULL, 0xC94BF64517D25365ULL, 0xA386E811F1927039ULL, 0x1E6E396B976E28F9ULL
        },
        {
            0x395FEC73373C67E4ULL, 0x4A3D10A3F9C44FAFULL, 0xA66F253540C2AA04ULL, 0x571F50CDC6AD3272ULL, 
            0xAE97D81B3A6A607CULL, 0xBAEADD90BBD5CB7FULL, 0xB38644389843664FULL, 0xBEAC3B2326E723B5ULL, 
            0x4DA2BE4517ADC7C1ULL, 0xB2EB11C7428DB737ULL, 0x529D9C08CD0993B5ULL, 0x9632945CFCE80FA9ULL, 
            0xCC5D977192C9F6F1ULL, 0xA2B92D9067D92E25ULL, 0xE4598F032D41205CULL, 0xD322C247C1A110DBULL, 
            0xD98FBE9BD9893174ULL, 0xABD487E045717C72ULL, 0xBF7CB437E61A4061ULL, 0xA9761E134989253BULL, 
            0x718C1FE64B207719ULL, 0x4AF0566AD0F9780FULL, 0xD58AE1C282ADA3C7ULL, 0x276DEE0B8373BAC3ULL, 
            0xBAAC40C505ACFA04ULL, 0xCF6524E24FA0D4FCULL, 0xA17B1DB6B7A3E7B4ULL, 0x12E80E553D2516A6ULL, 
            0x257EE0031AF58A18ULL, 0x73B3C8B2B88C9DC2ULL, 0xCA326B606E136C17ULL, 0x131662031A7381A5ULL
        }
    },
    {
        {
            0x08D008F173D9190FULL, 0x3AC444D0E67E61E4ULL, 0x61CFDAED0516E3A2ULL, 0x1F72B8A074D982CAULL, 
            0xFB1EC95BB41C0FD1ULL, 0x9C24B2A76E1BE08AULL, 0x9B78A80FFF81B106ULL, 0x8263C6E1E3D19FB7ULL, 
            0xE0951913DA788374ULL, 0x84B5B5EF7163EEFBULL, 0xDE46870E14135C82ULL, 0x62B30FAC2E37BBDDULL, 
            0xCEB6F3E3B275613BULL, 0xCC4D30169E0C39E7ULL, 0x3D88E4CDFBC4FBB6ULL, 0x8AFD7AC2B28BBA65ULL, 
            0x82BC8601F71F4AC0ULL, 0x64E2172DBFD60DC9ULL, 0xB012C5657D02476CULL, 0xB3B914BA7738C125ULL, 
            0x9A5D90F8C3666861ULL, 0x133ED5EFCB65E878ULL, 0x2AE758BD613852F6ULL, 0x3553A0934B70C43CULL, 
            0x57A2467EF3847DE3ULL, 0x14D42393202E8C08ULL, 0x04E129A6DD12F6EBULL, 0x05067269F04515C9ULL, 
            0x04D86635D7C85DD0ULL, 0x22A17C6C2BFECF0DULL, 0x5F287720F0B48DB2ULL, 0x41D843EE7FC8A0C4ULL
        },
        {
            0x6B3FC1DC5BD8A1B2ULL, 0xF43542EBA57E064FULL, 0x3ED170BDAB4B4EC4ULL, 0xA27094BE07341163ULL, 
            0x391203D893FC2C51ULL, 0x223DB00DBBB65923ULL, 0x47B4BBE95B44AC82ULL, 0xE4A986AD03D9359EULL, 
            0x2169196BDEB16272ULL, 0x4154455463500D6EULL, 0x842B07014ED6AE00ULL, 0xBB531F55905FE890ULL, 
            0x84178E2A2BD7B1C8ULL, 0x32E016DE8947EFBBULL, 0xC97B7D9D882DC007ULL, 0xE210568426213DC4ULL, 
            0x6F7F09CE9B09B5D3ULL, 0xC0247057F8EAD73AULL, 0xAD55B6C0EDE359B7ULL, 0x64C079C2D330C70FULL, 
            0x0AE4C144092A6E67ULL, 0xB126931A1F23A60DULL, 0xC2DF881B884AB1F6ULL, 0x72388CDB05F0CB1BULL, 
            0xC490BB1929780F35ULL, 0x96100043B947AD97ULL, 0x81976861A052B002ULL, 0x5DD309B018ADE536ULL, 
            0xF60954E20894E9A4ULL, 0x02825C23AC5D46E0ULL, 0xE6DAFD9133629C65ULL, 0xDBEAC3A936E07D1FULL
        },
        {
            0x53F32CEDEBC51467ULL, 0x8113D8BFDF154864ULL, 0x57F331F6AEA70F79ULL, 0x6AF5174D36CE5090ULL, 
            0x0E5CA6D1D81685D9ULL, 0x0643B20BF7D5E587ULL, 0xD1AB8C483526BCB5ULL, 0x302AF04D426ABB1FULL, 
            0xB4B3995DCACC50D2ULL, 0x4407706ECCFB7933ULL, 0x9FBDA0F591E08072ULL, 0x76020FCA4085CC6BULL, 
            0x355C0F973D9C1B13ULL, 0x6C330872B7D0CB59ULL, 0x87A312E26B7EEBFFULL, 0x2CC6375F2D6F5911ULL, 
            0xA1B8F7B6F8A6A195ULL, 0xFC6EEE7C3FB3D2B1ULL, 0xC8190D1E5BFB629FULL, 0x25BC0AEE12B3AA3AULL, 
            0xE6ACE92F0DA1190FULL, 0x48752EE3221BF391ULL, 0x564D60736D354930ULL, 0x33DE9A57C20E12C0ULL, 
            0x7EB6B59C95DBCDF7ULL, 0xB33BB67DFE0709E2ULL, 0xB91B0466A8316C93ULL, 0x9CA66C0CF8B9628BULL, 
            0x9DB21AA010394083ULL, 0x45E05217E5CBACB9ULL, 0x495AC9B63F310F35ULL, 0x40F0CEF9D43D9104ULL
        },
        {
            0xA7C6451CF34BDB03ULL, 0x20D5BC711343EAC0ULL, 0x26B1866A3AD305B0ULL, 0xCD5D93DD2AFD2D8AULL, 
            0xD48F6D54B2F7641DULL, 0x7BC54BD0327B0B5FULL, 0xD1A2BCACCA7EBBF7ULL, 0x78B05E9E02CE3DFAULL, 
            0x88F8C87768098185ULL, 0x1443A6E2F0DDB270ULL, 0x59391DEF8217DEE2ULL, 0x1AD1D80A0F0C3D7CULL, 
            0x89B0FCDB22634C40ULL, 0x8FF79DE3BFD1854BULL, 0x8049D0EE14F8A899ULL, 0x1FF5FF292B3D0249ULL, 
            0xC9BEF9E718821F0AULL, 0x15701FA0D6C10F0CULL, 0x8494D6F9C462C7E4ULL, 0xBBFB038513DA64A0ULL, 
            0xDCF692B98C07DAB5ULL, 0xD73D5A0DA5C794EAULL, 0x8930CD67D65AE277ULL, 0xCB33E08002D19D65ULL, 
            0x75613386311B3063ULL, 0xE0510F4B4CC08D4DULL, 0xEF5B7BC45625041EULL, 0xB4253021B4E415C5ULL, 
            0x11C44BEAECFBEF7EULL, 0x8B144BEF022411A4ULL, 0x77BF46322D62C215ULL, 0xC3F2AC78AA58CE5DULL
        },
        {
            0x415FA02821B65143ULL, 0x88D8F354EF7E213AULL, 0xE3D56616427410A9ULL, 0xF0B57188F3B630D1ULL, 
            0x702265E7F1D04842ULL, 0x763D1BB858D38FCDULL, 0x62C0128528BE0104ULL, 0x9B98E5DFF39AE13BULL, 
            0xA57CBA45B65065BBULL, 0x19380EAC9AA324E7ULL, 0x99CDAD45EF240C68ULL, 0x1C3884AE38B51734ULL, 
            0xACC98A4BAD23315FULL, 0xAFC0FCB99560094FULL, 0xCC5E9EC05C43022FULL, 0x8AF7A410861A4C1AULL, 
            0x8054ABE495DB9934ULL, 0x6477D6C57B55B7A4ULL, 0x8494479FB82112EEULL, 0x9DDF186384DA0396ULL, 
            0x11D622AE977DEBC6ULL, 0xA63B9C9526579F82ULL, 0x97DF3335C3E7DABFULL, 0xE07BF05BDAB87899ULL, 
            0xD3940F4DF6EB35B5ULL, 0x327A6F0D91119D43ULL, 0x24A549B07ACE8A77ULL, 0x834019DFBB5BD7B4ULL, 
            0x0204CA50478EAAFAULL, 0x66EC28E78DB376A4ULL, 0xA54D1F024883B153ULL, 0x5D222CD1EAE4427AULL
        },
        {
            0x965475FDCF516FBFULL, 0x31E91F406242E33BULL, 0x4C7F23431A4D2CDFULL, 0x8BC555BD4A60C653ULL, 
            0x06CA799B3C215303ULL, 0xAA62A1A8DCC5E56BULL, 0x2532A346F03DB5FFULL, 0x005275B638BAC74EULL, 
            0x9438A66BF65FB563ULL, 0xA8FA9C1DECB539DAULL, 0x1EB1E85258073FC4ULL, 0x3960C2DF7B60A919ULL, 
            0x8C555076840991D9ULL, 0x77A109BCDE156C0CULL, 0x267141CAF75F2006ULL, 0x250575A66520CDA3ULL, 
            0xBDE606EF2E7D4190ULL, 0xDA0B488697848E50ULL, 0xC50EF27FD272ECC3ULL, 0x0A730A962B3AC046ULL, 
            0x1B88231AC2E0F555ULL, 0xC08DE92ABC9D5772ULL, 0xB4EDA1AF0499EA5CULL, 0xFD810C5E5EB10C70ULL, 
            0x6787C9D2E6276B5CULL, 0xA0BB12C2FB73B904ULL, 0xAD37C467463CD871ULL, 0xEED3ECE0F2160929ULL, 
            0x299DBEC9016AD5CBULL, 0x52AFC27EEFEEA6A9ULL, 0xFEA13D81E5025D92ULL, 0xC817FC9E3CC134B1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseEConstants = {
    0x67121DC101A90F8EULL,
    0x97C694B02860943AULL,
    0x483F0FDFD4E78AF2ULL,
    0x67121DC101A90F8EULL,
    0x97C694B02860943AULL,
    0x483F0FDFD4E78AF2ULL,
    0x47D871D08574F7FBULL,
    0x34E4CCAA018A7000ULL,
    0x2A,
    0xAB,
    0x9B,
    0xF2,
    0x41,
    0x5C,
    0x75,
    0xE6
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseFSalts = {
    {
        {
            0xFA38F54211E50DF0ULL, 0xE1B66327EA4D907FULL, 0xB30E17C88945095AULL, 0xEFBA354411A67035ULL, 
            0x0E3AE1F5A29BAA2CULL, 0xA0E5B334FF06940DULL, 0xDAC060E1D779633FULL, 0xD498C70169F8BDE0ULL, 
            0xA9F5626F5D4867A2ULL, 0xBF47B37026B9E6B9ULL, 0x1D59D15A4BEFD6B7ULL, 0x424D35A854D93CD0ULL, 
            0xEBFB4A253C4CF87EULL, 0x8CB582F374FC3523ULL, 0x7E7C867809B1E2A6ULL, 0x09FE32752F60BCB9ULL, 
            0xB3A4C25EFEC26EA3ULL, 0x0B323F6ED5E03E9AULL, 0x79AF40FEFD667066ULL, 0xB2B43307756E99BEULL, 
            0x6B39905476A09D6BULL, 0x3C6D8FC498F65539ULL, 0x7BF0A2D36C1EA224ULL, 0x23213A98EDECC1C0ULL, 
            0xB9BD9D74B73AD102ULL, 0x932ED8CFA56078C6ULL, 0xC3825CB22584D2DAULL, 0x441C71F2C77EFF61ULL, 
            0x6F7B3FFD7E67201FULL, 0x55E367CCFA4311AEULL, 0xCE31360BF9682D11ULL, 0x956850660E6FF205ULL
        },
        {
            0x91ADBE5E63C23B73ULL, 0xE0471DB38EA5D681ULL, 0xDF759F944F4A7075ULL, 0xE73F9992DD053902ULL, 
            0x1A3EEDAF7BCA11A2ULL, 0xA745BBE3BFD6526CULL, 0x8C513097BA19A54BULL, 0x790451F85703C4A2ULL, 
            0x9844655EE722A221ULL, 0xC91666727C5F43C5ULL, 0x2C1D292611B73424ULL, 0xB2C5690227B91702ULL, 
            0x9CF70B5283075E65ULL, 0x4673B665252FF8B5ULL, 0xB94D30EA1F9F157DULL, 0xCED3F3788AE2B8ACULL, 
            0x81ECA3EBAE6677DEULL, 0x96B7FA930F01A98BULL, 0x09B7A5F2C5035818ULL, 0xFEC466F5579F3F0EULL, 
            0x26970C6EEAF09403ULL, 0x04EF86B9BBDB0328ULL, 0xEFFF3DE3EBB36209ULL, 0x29905ABC4C86CE5FULL, 
            0x5FCB4E4B4A6A1D46ULL, 0x5F2C51B30E9013DEULL, 0x1C8F86D0636F5541ULL, 0x35378C0092D06535ULL, 
            0x607E461A7A47E0C2ULL, 0xE7A73E538AC88F3FULL, 0xEB4545EEF82EB341ULL, 0x70F409ADB44E41EBULL
        },
        {
            0x66DDA5A11813B0DDULL, 0xDBE310E9CFF2BBE4ULL, 0x4D30B0E442C74F93ULL, 0xB682D50049385985ULL, 
            0xC6039F2A0C341620ULL, 0xA4DC5649E291DD09ULL, 0xA59A0DAC96014EAEULL, 0x983931F85283D020ULL, 
            0xA97B80666EE1FEE9ULL, 0xF55F3F575A8F87A6ULL, 0x7500EC871388DD2BULL, 0x298324AE8369DA2EULL, 
            0xDC41FF97C9D21B17ULL, 0x94C1B9D014372251ULL, 0xFA0E2DE818205E74ULL, 0x0CD4C4999880C522ULL, 
            0x6171434570023A77ULL, 0x1D95646AA53951F1ULL, 0x025D7D01F60E9BDDULL, 0x84D92FC6A5FAFC0CULL, 
            0x1054B110E9917E86ULL, 0xE7D3743B0A13F022ULL, 0x56AD5626A48AAC41ULL, 0x1E2043213C4EB1F7ULL, 
            0x5F50BF6551B601D2ULL, 0x8A9D8A44EF52B6F1ULL, 0xE61BACD30DD74807ULL, 0xEC90A7553C95ADC0ULL, 
            0x80904486548FC122ULL, 0x5CF08EA19ADDC63EULL, 0xCA2B7C53B4C49948ULL, 0xEA2AAE3B83DF814FULL
        },
        {
            0xAB98C970C849B9C5ULL, 0x54781257707D8088ULL, 0x7E9E08FDB0FAD11BULL, 0x22B47D1816186204ULL, 
            0xDD8EA474F1C632E1ULL, 0x633CEFE44040EB0EULL, 0x4475DEBB97D2CACBULL, 0x269D36050EB8CAE5ULL, 
            0xCAB5D9C765E9678CULL, 0x43C5FD2BB59AB8B7ULL, 0xDEE1A5E5720B9697ULL, 0xF461741662836D58ULL, 
            0x09610290E70FE3A1ULL, 0x9DFA65B52AA06120ULL, 0x8C380CEB26FE6137ULL, 0x88EB8307BACE04E3ULL, 
            0x8DDED381F05EBA73ULL, 0x364A7B9EEE798051ULL, 0xA3A65BA597D55050ULL, 0x1CAAB1CC962E4DC1ULL, 
            0x5AB76AC4E2B23E7FULL, 0x4AED7967EEB5AF84ULL, 0x490F91BFAE231A60ULL, 0x37A396386BEA3559ULL, 
            0x14D906325321A351ULL, 0x48B8EAA610CAC92DULL, 0xC134BDD6C183763CULL, 0x44629D7E905806A8ULL, 
            0xB6B9DE2DB127401CULL, 0x6C9005BD50A73EC9ULL, 0xC7A806DA15FDD9F9ULL, 0x83B3B460662CC116ULL
        },
        {
            0x52EE38AD2C93D5B3ULL, 0x22D200302EDC18E5ULL, 0xB4ABFEE6946C9348ULL, 0x00F2DD1EE0B492CBULL, 
            0x7AC45913000BCFDCULL, 0x826AE03FC2AA3281ULL, 0xE7702EF331E31959ULL, 0xE1E2730308E3AFCBULL, 
            0x68C6F57A1E486371ULL, 0x1869A772E4897B75ULL, 0xDB98F96B72790054ULL, 0x9C96AF4F82211819ULL, 
            0xFDC427D22AE4AFD6ULL, 0xFC55C6CBEA44ADFBULL, 0x320D6BAB64AA560AULL, 0x419EDCDB1D64F0C1ULL, 
            0x165F02B9794B3C5BULL, 0xBCFA2A75AE367E7AULL, 0x817F70C67384CC0DULL, 0xE37F2B9EA56E4687ULL, 
            0xC52B0F41EBF06A24ULL, 0x44DE0E056B997B64ULL, 0x7D8F543A7513FC1DULL, 0xA1C2B41CF9DBCC97ULL, 
            0x7A2C9ADFF9ADB9A4ULL, 0x81322519F8DC8347ULL, 0x4F37C43C1F8E8363ULL, 0xB3D859E82D21AFF3ULL, 
            0xCBCF41EA545EE3CBULL, 0xB43D913ABC855ADCULL, 0x7342A850979483EAULL, 0x27DBB24536FA7E7AULL
        },
        {
            0xD5F3478F41F47D6CULL, 0x86F642B25AC55200ULL, 0x8EA28C23F8E9B545ULL, 0x7507A791227C7110ULL, 
            0x694DEC562C97FE33ULL, 0x0AD3511537B9F513ULL, 0x3B6A6D0CB76EBCEFULL, 0x0C0B4C19FEDDA888ULL, 
            0x97E2F6F030CF5F73ULL, 0x3EE866A0F3FCA887ULL, 0xDAD6C81905A38667ULL, 0x0E2000C54415839BULL, 
            0x9950C451E1694436ULL, 0xF6509D539DF22096ULL, 0x3ABFD8A74AFB3D1DULL, 0x1068B509DC5FCD10ULL, 
            0x86C1481B0F6BFC59ULL, 0xFB3D52B17CFC7C68ULL, 0x60D8CB698CDBAD22ULL, 0xDA1E284744864936ULL, 
            0x766ACA9D3D42BC07ULL, 0x72884FCF9F150F5DULL, 0x6E235046F34B687BULL, 0x978DB45314408570ULL, 
            0x7CD3B26251EF944FULL, 0x156097113A2F7B66ULL, 0x58EC79A4558C3BF1ULL, 0x061E837869DE0A62ULL, 
            0xA634D40F0EE21CA7ULL, 0x8DC50185DF07C5CDULL, 0x39863BF877CF941BULL, 0x6C3E62CF2D0782DCULL
        }
    },
    {
        {
            0x813B1473F0CE4206ULL, 0x9EAFFD15FE15B1ECULL, 0x46889ACBC56C58A8ULL, 0xDB87BA5741F4D1CEULL, 
            0x4CB3D36A14D81879ULL, 0x2420950583C70305ULL, 0x096733CCD7715675ULL, 0x408F7EF4B3F2C70CULL, 
            0xC30F04E938C3D89FULL, 0x045CA83E9753E173ULL, 0x9DDE8FD339D9D103ULL, 0x758902323AA932D7ULL, 
            0xBB0FBA6E92A8414CULL, 0xE3DDE855AC03FEEEULL, 0x6281D40994C04BB4ULL, 0xF0565FE3DF2F1296ULL, 
            0xAC03C93710DDB485ULL, 0x066BEBD55A2F66B7ULL, 0x4598D89E2AAB3637ULL, 0x4951BC1335D881F0ULL, 
            0x2916D96C9FE3532BULL, 0x2632BD81FF4AE250ULL, 0xDBF4AF3CEC327C39ULL, 0x176F3D967AD18492ULL, 
            0x5249B13F2109D122ULL, 0x4BEB3D0AFE4CD1FEULL, 0x2CF80284EB737459ULL, 0x9854764707BCB90CULL, 
            0x654CA8C09DBB87D7ULL, 0xB63CF0CA4625B553ULL, 0xBEAA552F6ED38E83ULL, 0xE1671519410BF725ULL
        },
        {
            0x6D0CF4788053EDD7ULL, 0x66E0D0F2F4699D8AULL, 0xAE9358E21A804DB5ULL, 0xDC83AC1434B63813ULL, 
            0xC433A9AC80BC01EEULL, 0xD0A736F9710A787CULL, 0x87A9D7F4E8CACCCEULL, 0x4CE217107DDB4A03ULL, 
            0x12423FCC0AED138DULL, 0xF132EF55C2C2DBC4ULL, 0xD899195B4DBB2A66ULL, 0x7F6C067501E7270FULL, 
            0xE98533D152192AABULL, 0x14F46880B090114EULL, 0x3ED1CE3C0C1F345FULL, 0xDF3F1793B23004FBULL, 
            0x39DF27757132E443ULL, 0xA575EFC51C2FC942ULL, 0x7B5D618B03D36BD9ULL, 0xDE9AB2B2921A42F7ULL, 
            0x937206FB7807DD33ULL, 0x1463FDEAAD8AF7B5ULL, 0x4729110B3412E5CDULL, 0xF1781C227F1071E2ULL, 
            0xB259C1C8DFA4E20CULL, 0x1FBF6036FD09F9E5ULL, 0xF94C0FFC84817FB2ULL, 0x5E8FD316AFDD99BAULL, 
            0x3374441C13B72F02ULL, 0xEC14FAA19C166C22ULL, 0xB9296CE2921D2F94ULL, 0xB50233B14DD4303EULL
        },
        {
            0x15AC6228174D87EDULL, 0x73C11E7E42B84604ULL, 0xCEFFED89F00B6C2CULL, 0xEA0E8E2A98FAA6F7ULL, 
            0x2E181A71A7505BC9ULL, 0x0D08813897CF0911ULL, 0xF4B10CCB83080BA0ULL, 0x6C4379CF734CAE82ULL, 
            0xE2B1E8C4D0BB2277ULL, 0x3AF48CDBCC0D5FE8ULL, 0x595B7D3DE1C987DFULL, 0x9C3E87F5877D4C81ULL, 
            0x8B1F641BC4DF6767ULL, 0xF4286B47D0C69F62ULL, 0x20DB1EBEF36593B9ULL, 0x4CBABDD60937CAAEULL, 
            0x6C85142A12FA45E4ULL, 0x4D588BA8E9D6FEE4ULL, 0x2D7786D920305486ULL, 0xF3780FB4E977B27BULL, 
            0xE813FEEDBCEE70FBULL, 0x7F50F9B3FDF027DDULL, 0x949F2807EC7C73F0ULL, 0x777129FE338694D8ULL, 
            0x10A20D24E0A5BF17ULL, 0xBC24E3A55405B2C1ULL, 0x6A5F951693295650ULL, 0xE7A614314A9117A5ULL, 
            0x097DBBC404F3ED08ULL, 0x370A4159963B2894ULL, 0x1DD478FC69F19946ULL, 0x485C69AAC6A2BC46ULL
        },
        {
            0x1F470110C7F1CA7BULL, 0x5DEBF8DD9D45598BULL, 0x24E600406A263646ULL, 0xDD14457D222EA477ULL, 
            0x30390E607CDC7AC1ULL, 0x85A0E1C0D992E71CULL, 0xC4C3D1BA88024765ULL, 0x8EA83C69907D8849ULL, 
            0x7C4923E16B714B6EULL, 0xA1FF8CF8243EF5FCULL, 0x9D2C1EB38C992822ULL, 0xB94A7F4BD3E54488ULL, 
            0xD0ABEEC234F4A0E2ULL, 0x86AF5C6C59A44AAEULL, 0xADC64029E112170EULL, 0xBD78297B601A62D5ULL, 
            0xECD6E0A349FDA472ULL, 0x674B392824896CDEULL, 0xA9CC701A0C81823FULL, 0xDDA15D5A6C484B27ULL, 
            0x716A14004AA7E5F1ULL, 0x5BD9E4D7E7D033F9ULL, 0x966EEBF561C4FD7AULL, 0xCB0FEF15002A674CULL, 
            0xEFC3BDA9B7BFF3FFULL, 0xDBC53BD5F035A4D1ULL, 0x450A6F28296742A8ULL, 0x7BFAFB5484E1A080ULL, 
            0x13366635F6431735ULL, 0x00AE0A50EB1D18E2ULL, 0x0D32EFAE5F89BA03ULL, 0xB5FDC61B0C973F1CULL
        },
        {
            0x655786ED062DBA4CULL, 0xC5DB9D5B4A58CC25ULL, 0x8871E8B442DB3239ULL, 0x4EB752ED594C5EA7ULL, 
            0xD24601668667BE3CULL, 0xC3819C64ED150F1AULL, 0x2D64BEAFF8295B70ULL, 0x047AE831C4F43FADULL, 
            0x21ABAAB4AE0E41DBULL, 0x5F1B902296B7B64BULL, 0x6D200BA29F05D9E3ULL, 0x3060FD764C1B51D3ULL, 
            0xFB1D228374A2466AULL, 0x5D8D6BA960971819ULL, 0xAE024EBF1187D4BAULL, 0x12E69E4226BBC1F2ULL, 
            0x857C8598A3CE7073ULL, 0xBBB292D817571707ULL, 0x01668142F275B4ABULL, 0x271FD42200654010ULL, 
            0xE8DADFA3DB5100A3ULL, 0x5FF5B006887157F7ULL, 0xC34F4CF983B0DA24ULL, 0x8548F90BE85B4C4AULL, 
            0x6524635AB3003DF3ULL, 0x402A23ACAE90FEDDULL, 0xB94DEA3595DD6F05ULL, 0xF9D0D29EDF1A2D47ULL, 
            0x91096F502AD2A00BULL, 0x3849B8E2E5210494ULL, 0xE86679AC1A9555B0ULL, 0x34E0C72D744E1373ULL
        },
        {
            0x54F0A53E2EA3429CULL, 0x1FF7CAFB1605D8A4ULL, 0x96FEDD297ABE6BA7ULL, 0x596217098DDDC786ULL, 
            0x515F54B9E6D01045ULL, 0xC1DCCA6917973E12ULL, 0x2EA4EBA499DA04EAULL, 0x8567DBF8725215DCULL, 
            0xB1941DC92AB1DC7AULL, 0x1A3BBFDD7623A131ULL, 0x810B9D0F8B7F3188ULL, 0x87F28B08B7CC3BDAULL, 
            0x8EAA75A9B28739DBULL, 0x931EC5A8D5677C49ULL, 0x722ED1CC418532F5ULL, 0xD110B91632BF95A6ULL, 
            0xB78760DD931DE0D6ULL, 0x617E486582797A5EULL, 0xF786ADE0831A5BB3ULL, 0x8425709DB8822347ULL, 
            0x2669714AA50EA3A1ULL, 0x1139E59491AB71E0ULL, 0xEA7D9BBC9E04DBB6ULL, 0x447C1DB9B5773F5CULL, 
            0xD06DA8933721A954ULL, 0x8007FCE7352D4827ULL, 0x6BDED221C6DFB414ULL, 0x93A5EA8F98658FF7ULL, 
            0x6DE5C32EC75DD63DULL, 0xFCC145840344CD5FULL, 0x03D966423B36B241ULL, 0xC0D9621FA62784C5ULL
        }
    },
    {
        {
            0xDC680516C8883940ULL, 0x2E3175E662E70E72ULL, 0xBB70A20BC4D43301ULL, 0xAD9A85679BD0B6CAULL, 
            0xF8F69B237219EEFAULL, 0x7F10263F172A44F7ULL, 0xC949546ED5A2C5C9ULL, 0xC51076D875597C28ULL, 
            0x425B5FFBAB5C0EC9ULL, 0xBCD5E7D0BC9A31F1ULL, 0x9E8EF436E08A22AAULL, 0x09394B5A21210EB7ULL, 
            0x81F870CC9788F789ULL, 0x1A247473D503A85CULL, 0xD8862073E596C872ULL, 0x4F1DC9E9D686D5D2ULL, 
            0xD4804C1DD6A2245AULL, 0x4D802F7DB4614EB2ULL, 0x5A31965F76C880F1ULL, 0xCF0F3822EA1D76D4ULL, 
            0xDBB48A39B2617E03ULL, 0x09EC5425D39B3836ULL, 0x25D821B2BF163327ULL, 0x05F815538EC2D4D2ULL, 
            0x05E54301C55629B6ULL, 0x03CBA2F52288A8DFULL, 0xC725C11C6619BBC4ULL, 0x3D513DC2D46CE304ULL, 
            0x09622EC62D9A1B1BULL, 0xF1F19339E8593337ULL, 0xDF045EB26DE372C5ULL, 0xE833BCDE07463B6EULL
        },
        {
            0xA0A01B173216196AULL, 0x32092BB6085ED28BULL, 0xDACC21CA690FF2C1ULL, 0xB805B07C69815CE3ULL, 
            0x2F4EFCB8CC83887CULL, 0xCF023032BAA59503ULL, 0x5A7E7E99341B72A5ULL, 0x82EDADCA0B9E69EFULL, 
            0xF572849A6F72F764ULL, 0x122AE03A302B1EDFULL, 0x5EE4E60AAC4EEA7EULL, 0x7030812D47983A97ULL, 
            0x245B09464F56DAA4ULL, 0xE61C24E7EA044C8DULL, 0x19D2F8CB74B6DD07ULL, 0x48D0665231356FF5ULL, 
            0x291565B5F40AF718ULL, 0x2C70F9E05B8F6D6CULL, 0x951A0BD408232025ULL, 0x24C5F584D8EE20C0ULL, 
            0x1BA26631F3E871E0ULL, 0xB05BF0A3BE9CFD02ULL, 0x3D0A659B212219EAULL, 0x4051E7D9E7971087ULL, 
            0x954281F0AF9C6EC6ULL, 0x348E64889979D870ULL, 0x75016076C9BE91EDULL, 0x944BDF1F4538FACBULL, 
            0x137AB2D68ED3E158ULL, 0x494C898260A260D0ULL, 0xF88C50F4CC266402ULL, 0x6AE4B9BB40A36AB1ULL
        },
        {
            0x0D1D8AACF719068FULL, 0x912C37F52B944364ULL, 0x7876F53085F92855ULL, 0xE03B402424059185ULL, 
            0xEE6BDAFA8D673CF8ULL, 0xE4EF95CA362EDD03ULL, 0x43AE87CDEF76828CULL, 0x2F701001917E796BULL, 
            0x2064ECB6163BC6BBULL, 0xFEE825DBE5C49F9FULL, 0x8C0109417068073BULL, 0x497516E20B13DC9CULL, 
            0x053B44967A375AB6ULL, 0x312354493A73D093ULL, 0x09BE1EFF1CE60DB7ULL, 0x9CC1654A33CF2D68ULL, 
            0x092C3E0AF9865E16ULL, 0xEE8F8B37DB716B6DULL, 0x6F4E8DD6099A6AA9ULL, 0xE849A4C273BCB18FULL, 
            0x47BCA1F0C7643083ULL, 0xAA30FC39FF532475ULL, 0x010983BB95FD0CF4ULL, 0x0286EFCB9B00377AULL, 
            0x0FFC846031C4E853ULL, 0x45C5E94D38F4F0A8ULL, 0xCE64AD3B33D82C2CULL, 0xC2380646A49ADEABULL, 
            0xB61A12863C7771FCULL, 0x2B74C256A25E2EFEULL, 0x49AA763B1B83BF0FULL, 0xAA1A4B9E1BBBFAF9ULL
        },
        {
            0xDDB5B823E7B3411CULL, 0xF529F3C976C65FEFULL, 0xEE2359EE1C873243ULL, 0x7F68BC98C51E6B16ULL, 
            0xB6707ABADFC80E03ULL, 0x2701A24439F818B5ULL, 0x741B311749C09750ULL, 0x26FDF98BA5AACE74ULL, 
            0x5AF224FEAEF47FCDULL, 0x156E7549DF112C78ULL, 0x9AC33556A1DDB107ULL, 0x4D2277679E894BD0ULL, 
            0xD7C718684EADA602ULL, 0xFCB642C5B8F7332BULL, 0x88257703A3E807DFULL, 0xB34C105F7AE55067ULL, 
            0xC55E0D0076983CD8ULL, 0x6A95E288E9DCFC70ULL, 0xE61F8261B68D6761ULL, 0x287A4975103A1117ULL, 
            0xEE5FCEA65BAEF369ULL, 0x5729B6E6A106D51FULL, 0x09A9AEF34B8D945FULL, 0xFE8AC0D8304C2231ULL, 
            0xDE6D082D4353E743ULL, 0x2E0412DD77305345ULL, 0x54A9A0F003395081ULL, 0x40526F0161B0EB87ULL, 
            0x393F795217282F7FULL, 0xB90584A62297181FULL, 0x9D3CA47DE956E24CULL, 0x1F3AAFE0FC6EADA7ULL
        },
        {
            0x1767387786F1BD97ULL, 0x2BA49C185E8AA0A1ULL, 0x37DB78245A3DD67FULL, 0x0E00FE3F37FCED5AULL, 
            0x640414251142C631ULL, 0xC890C1A1D2E83B9AULL, 0xC363C1DD9B02FF48ULL, 0xA07E47A85A2B05FEULL, 
            0xA0F1F63D84659BDBULL, 0xC60A8E05CDD5DF8BULL, 0x8C0581A508C8FC4DULL, 0x173160A7A10C3753ULL, 
            0xC1C4DD7472F062B7ULL, 0x8F1095739B457D83ULL, 0xC712DC97AF393B98ULL, 0xB99233105D359C2CULL, 
            0x34FD452DE9E210B3ULL, 0xACF6E8A7BC95965BULL, 0x5B6143F663E65445ULL, 0xC110C469B68C4D32ULL, 
            0xE7866B3D5E2DE4A1ULL, 0xBF1535794022D62EULL, 0xF248068E2441756AULL, 0x70DB648B9E6127FEULL, 
            0xDFEDA423C7A6F982ULL, 0xF2B85A1654AE79F0ULL, 0xF21691A03BBF39DDULL, 0x92E3413571ED4437ULL, 
            0x2379A808F10C01B5ULL, 0x03EFA72D03932B13ULL, 0xEC18B6B4643712ABULL, 0xB40D2E31F9B13E02ULL
        },
        {
            0xC188A2C149AD1596ULL, 0x8A96A30C39F68625ULL, 0x6444FD58DC36D063ULL, 0xEE0CCE7DF61685EFULL, 
            0x6D982905F1D4E00FULL, 0xBB6E22E1B0D4B172ULL, 0x1AFD44503C6ECF98ULL, 0xC10F3190BA5EBC66ULL, 
            0xCF54504503145D9CULL, 0xA425038EF258EB51ULL, 0x2E4AD16DDF8B4D66ULL, 0x2BE1E9D8DC15DF42ULL, 
            0xB72E8E9802AA5723ULL, 0x342BA152F16A9764ULL, 0x1DB73D7C8A68989EULL, 0x2B2AB534F0ABE9FDULL, 
            0x470C0E50CA9CE00AULL, 0xE78AD73BBC5FF5AAULL, 0xE8002BEADC7E302CULL, 0x47EE2B40DF4391C1ULL, 
            0xBDA9819461B39DC3ULL, 0xA9450A0BD6475753ULL, 0x5441AD48A285D9B9ULL, 0x07A7A943DBA2A131ULL, 
            0xA768EDF95AD0C7EFULL, 0xB0497A2188F261F2ULL, 0x7D4CA36030F6BF69ULL, 0xF0F6427B2798D3D2ULL, 
            0xE341A0C70C03A93EULL, 0x08FC62DE7234E3EAULL, 0x3D5D76D815CE6B8EULL, 0xC432F4C40BF7EB3BULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseFConstants = {
    0xA5EB899430729F18ULL,
    0xFFEF4F1E9450C253ULL,
    0xFA67DA8021300AA0ULL,
    0xA5EB899430729F18ULL,
    0xFFEF4F1E9450C253ULL,
    0xFA67DA8021300AA0ULL,
    0x769BBF4AECF273EEULL,
    0x2AC47C4D35F85371ULL,
    0x7D,
    0x21,
    0xEC,
    0x80,
    0x1C,
    0xB2,
    0x2B,
    0xB1
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseGSalts = {
    {
        {
            0x8548B9717153250CULL, 0x33944038196A2F09ULL, 0x93A34C1C5400E7FDULL, 0xA903950162C2BC23ULL, 
            0x263F74E7958B008EULL, 0x0216288283DA2C38ULL, 0xD70874711059B64EULL, 0xD1F04ECD4FDD74BEULL, 
            0xB8CD43414DBEED97ULL, 0x4730DA722C5A7AD0ULL, 0x27C7A9157EE20B88ULL, 0x26B48A70605A2567ULL, 
            0x59530D9D012357E3ULL, 0x46E4DFAE69FEA12FULL, 0x745D933C15994A0FULL, 0x7995434B58CDB457ULL, 
            0x61DB33E64DFFF5C3ULL, 0x0B88C21D7F3498A6ULL, 0x014BB500C5E8556DULL, 0x801228961931B2CAULL, 
            0x05828F1BD383B478ULL, 0x5D197AE411B0420AULL, 0x2182651EFC83CEB7ULL, 0x84EE8A464ABCDC75ULL, 
            0x5844D071540D152BULL, 0x559545B5AD809324ULL, 0xEC9B7A3860D0D550ULL, 0xF99887889CAE48EFULL, 
            0x7E0492266A9CECADULL, 0x8DF04E6A9BC413FDULL, 0x68C6AB1DA61AEE57ULL, 0x2AB7232E24B814C2ULL
        },
        {
            0xBE55EC6E876BF55CULL, 0x76FAC48AB1A37FFBULL, 0x97D838D3371E5188ULL, 0x64FFE032F7D62AD7ULL, 
            0x657FFFE87892E65DULL, 0x947BBB395E6587E5ULL, 0x1E386FFE4591105DULL, 0x5A37C4E1F4437B19ULL, 
            0x86F1CF555BB37108ULL, 0x3E631962D598E966ULL, 0x8D3F3738B54E7F0BULL, 0x954F27F7CDD9F32AULL, 
            0x06C7A0D37BDFB17BULL, 0x7E016B6D3AE606ACULL, 0xB429DA98BD660B89ULL, 0xF4BF0BFEA9B9ED9BULL, 
            0x4C3E5B11227C6660ULL, 0x872C8482C347159CULL, 0x042FD63AB7364A20ULL, 0x8779E6944A7E49AFULL, 
            0xA279A9A59AE7E311ULL, 0x51F68AAE58BB1AE1ULL, 0xADFC8443D838B2D3ULL, 0x91E2B01C601257B3ULL, 
            0xB57C76F70B6B9A54ULL, 0x1CBBFD3F1A57EC75ULL, 0x162BCBC3FFFD97A7ULL, 0xA64043A7C9A81B3BULL, 
            0xAA60D929B85A846EULL, 0x78EC4BA1D21C4BEFULL, 0x9659EF8972AF66BDULL, 0x3B6FC5A4F20C9C2BULL
        },
        {
            0xE94CCFC76CF06CCCULL, 0xBA90B873F01C587CULL, 0x063B48BF9622D22FULL, 0xACE400DF5925E140ULL, 
            0x691FCE0C307CE813ULL, 0x7A5D7761D2AAEEF7ULL, 0xFEB91D5D53D4F91AULL, 0x64CDCDDE7C473A1EULL, 
            0x3B015E10BA4A0CC5ULL, 0x31CEE7401A4B0C85ULL, 0x815A78228440903BULL, 0xBC23FB800A204E93ULL, 
            0x1410E47B2058A69FULL, 0x88FBAF0327B1499FULL, 0xC316AEFB45B52A1AULL, 0x8CA1897E405411E3ULL, 
            0xA54BFD632E032AEAULL, 0xA05E7AA5DEA89FFDULL, 0xF9E1E1501BAB608CULL, 0x76799A63913FF007ULL, 
            0x0C2E2488158A4DE4ULL, 0xC0B1D65D139402CAULL, 0x5535813D948D75F4ULL, 0x52FA767E6D8A5EE0ULL, 
            0xDB1DDBE6D698D57BULL, 0xCEDCE1DEC1CC603FULL, 0x27143DD987379E2DULL, 0xD22C7FC51D50F82DULL, 
            0x4778AE582EA0E799ULL, 0x6EC5BF0D098D5869ULL, 0x03BD6B073388225DULL, 0xA8B8C1D56EBE3653ULL
        },
        {
            0x7E5FFAA7335988E5ULL, 0xE8BF43D67D19FA9AULL, 0x1D29BB5AA084C392ULL, 0xB0E33C1B638DD261ULL, 
            0x0B366D6BFB4A647AULL, 0x14E6E975B89BDDCBULL, 0x51402C1DFE9DAD78ULL, 0xA274C2A441452D12ULL, 
            0xEA32E762BC2C9114ULL, 0xD644F8A513F1A0AFULL, 0x46E65FF58FC26657ULL, 0x85E0E28D6AF9FF4BULL, 
            0x3C7C1FBE178D18D0ULL, 0x42D43A0E51449362ULL, 0x1184F5789D3DA0DFULL, 0x3BF85A9286A00598ULL, 
            0x3515B581833C83E3ULL, 0xE010500B93DF6A91ULL, 0x004F098C0BBC939AULL, 0x6D298BEA77581EA1ULL, 
            0xE7B8BEBE4C3E7DFAULL, 0xC9E234BD8BCA39D4ULL, 0xDA17B386F670ACB4ULL, 0x907260A8FC9DDA8FULL, 
            0x13344E4BCAC541D4ULL, 0x8E5EDDFCC6A315E0ULL, 0x5F224D789657E3AEULL, 0x91CFCB80912FA122ULL, 
            0x19AD7FAAD8F06A22ULL, 0x0C0B6D333A888E83ULL, 0xDB37D309DB8EFA23ULL, 0x5B462C4A3FC75C9CULL
        },
        {
            0x31BB35196DE20796ULL, 0x03C4922304BB08A5ULL, 0x64C8F2059118D3F8ULL, 0xBB256DCE90422C22ULL, 
            0xC65828B82394A28FULL, 0xED88B77D71FC2A0EULL, 0x75831828CFDEE798ULL, 0x3CB8A9338C00AA15ULL, 
            0x3304FDC45A6A5DC9ULL, 0xB92871B1892AA39CULL, 0xDEA23D7208AB2621ULL, 0x5F6B33E70509236DULL, 
            0xF9CA0651D3E2A919ULL, 0x0FDBEE1FB1BD8C35ULL, 0x01460578D11B8E9BULL, 0x159A8C4F4B4F27A8ULL, 
            0xA8AF603512E0C889ULL, 0xA981232104F46CD2ULL, 0xF2E373302424F727ULL, 0x1A4B5A618FE74146ULL, 
            0x5A91819CCEF28A8AULL, 0x0C5B6E630A3F5A68ULL, 0xF922AE1278631B20ULL, 0x248E876311FDB7A7ULL, 
            0x64054AA06031BE90ULL, 0x8BED4EF139E8D2BDULL, 0xD20000B439C722AFULL, 0xC32358035A0F9F3EULL, 
            0xFF1D70E3EF4C9281ULL, 0x7A5BCFF2414FE767ULL, 0x3BFB8D3EE942C449ULL, 0x42DF48313C2118D9ULL
        },
        {
            0x579F1C5FA497F824ULL, 0xA6834B99FBADC5E2ULL, 0x6221142300752987ULL, 0x7028270F470C398EULL, 
            0xF948137156B84B50ULL, 0xD3DAA5EDE72134BFULL, 0xBBB7ADA8CA965CA4ULL, 0xF39E70E5B3C1F155ULL, 
            0xBDA78F0F005402FCULL, 0xBB33D0B29EB153E5ULL, 0x1A59A9A49D460FE9ULL, 0x190640340E2D5E39ULL, 
            0x895B90359D964F4FULL, 0x033A8E8FA7D3A4B5ULL, 0xC7CE42A3B69F302AULL, 0x2AA31BB74D99E25FULL, 
            0x17109DCC7504B872ULL, 0xD9A9F9B4C0D67278ULL, 0x7719D3DD94EEB7C7ULL, 0xE1CC50D4A935B62AULL, 
            0x2C01B5E92EA376DCULL, 0xA30A743F4711D6B0ULL, 0xCC2674EBD50B2E48ULL, 0xF0EC3E5476EB6882ULL, 
            0xC4CFBD44DEB42A56ULL, 0x6921F165565A3A2AULL, 0xC9C8FB29A4E8A544ULL, 0x7B755888BAE0F86BULL, 
            0xF4ABE443287F11F2ULL, 0x521B641025B38ED6ULL, 0x9725F616DE5442A5ULL, 0x7D93AAC0FF39061FULL
        }
    },
    {
        {
            0x8200AD156AE8709DULL, 0x8486C428F2992525ULL, 0x217AC86A3CEFE380ULL, 0x7EDD81E1F6F43E51ULL, 
            0x563C46878E117457ULL, 0x12AB71AA980FA411ULL, 0xBC2D4A0C2115EA49ULL, 0x2DDD247710FC4F22ULL, 
            0x37E6581665A7EFD9ULL, 0x4B819CF5F4C00E4DULL, 0xBF88309B316A1239ULL, 0x79612999E7C29C00ULL, 
            0xC4D4CEA9F88EC125ULL, 0xCFFB303761E68989ULL, 0x5FE4C836BD45DFE4ULL, 0x77E9FFDFF2EFA427ULL, 
            0x0352A14E188CC7A6ULL, 0xFB41B3584FFC86E2ULL, 0xD9F08F8D9173E316ULL, 0x30F23E773485F363ULL, 
            0xD4928CBEC709E3BEULL, 0x62FFDB87CB47AE6DULL, 0x81C46C6D6FB67525ULL, 0x5BD35B2B792A911AULL, 
            0x884228B7990D1BE2ULL, 0x52B37A977CC551BDULL, 0xD7D24DB97E16AEE8ULL, 0xE9E5B8F35C280AF0ULL, 
            0x18B8BD51C1428C53ULL, 0xAA8C992A04BF67BFULL, 0xA1D4070442E8CF72ULL, 0x676E561C994787F4ULL
        },
        {
            0x0B20F1EAB8718BBDULL, 0xDB53958AAC059C4BULL, 0xB934A2EBC5D4FA39ULL, 0x46CB4D464EA95D28ULL, 
            0x60C563FF449B3DC6ULL, 0x0EFDF0BECBEBE78AULL, 0x0F35B75FC2CCC3EFULL, 0xDA7DC4C6E9421EC8ULL, 
            0xC4204117E7519444ULL, 0x70B1005CC86B8F3DULL, 0x728EA6813283CC70ULL, 0xDDEE8703BDDA1E05ULL, 
            0xCCC9FEED684AC0F7ULL, 0x9FE2AE831159D92CULL, 0xAAF9AA5668C7E4D7ULL, 0xFC33CBD87BDDD87FULL, 
            0x363A3805D12D5A92ULL, 0x1827E8B2FD023CAEULL, 0x03B774CEEC1DA148ULL, 0xF3E3CDBFDDDFAF01ULL, 
            0xEDFEC7D027EDCF14ULL, 0x585C2667159074D1ULL, 0x807D7ECEEE85F3A3ULL, 0x467FDB3D5782B95EULL, 
            0xE1E7B470DCF6E5A9ULL, 0x193562D6BC78A6DDULL, 0x9867E755ED05058EULL, 0x7BB03C7EE715F363ULL, 
            0x1B871BDBA76C7E31ULL, 0x01FA17D1AE2688DAULL, 0x76B14D0BBA267FCAULL, 0xD0990AE882F9C543ULL
        },
        {
            0x5350C18FF972A538ULL, 0x5738B04C3A424D36ULL, 0xAF3CDB1F344139AFULL, 0xC7F509B5419BC721ULL, 
            0x6504484E279CC7CFULL, 0xE794C8B82E4BFB73ULL, 0xF7C05965167F0DA9ULL, 0x5D7D4D00FC168A6BULL, 
            0x3726A2C2CBA7F0CDULL, 0x98F604AA0B84A904ULL, 0xEC070357521203C5ULL, 0x50A0FEC3C4C1D6B7ULL, 
            0x56527135F0CEB3D5ULL, 0xE358F95473407457ULL, 0x6BCDC0F5E7EB99DFULL, 0xA370BFA9AEDFC563ULL, 
            0x7809829151F8E37CULL, 0x4D799A17EE6D025CULL, 0x1EC0734778C44F30ULL, 0xD72DCB15BF6D7378ULL, 
            0x51E2357E2978ADBCULL, 0xD013F2CDC381C713ULL, 0xBBED98D2670434DCULL, 0x8AB0DE1F91F79A73ULL, 
            0xFD9CD8022D4C997AULL, 0x08D9B07588D4242EULL, 0x8084783AF60BBDB8ULL, 0xEE339DFA76B5FD72ULL, 
            0xB1324732E7209BDDULL, 0x25182D77259C6FB2ULL, 0xCA5544420E9F3038ULL, 0x212ABEAD01B2A9DBULL
        },
        {
            0x52BDFEA7C6278DF2ULL, 0xABFDFA7541391830ULL, 0x4C81E7B815D74F7FULL, 0xBFC5B4A3CEE84465ULL, 
            0xEE12C98B38FD7BCDULL, 0xCDCE874CD8594F74ULL, 0x8A24692D01AD4567ULL, 0x456B6314D36B91D4ULL, 
            0x71504D1C83914650ULL, 0x3C08A69BE48CA6BBULL, 0x8154543134410C7DULL, 0xFECE8D73CD33AAE6ULL, 
            0x3E23556C0860194FULL, 0xB748453B08FD8690ULL, 0xD2CD5AC42C6C00FFULL, 0x2ACE9373692D0CC5ULL, 
            0xA0FB22C6DDBB67F9ULL, 0x816E9DDD2F36F3A9ULL, 0x73E169727982E3B4ULL, 0x3A41FEF283C0F75CULL, 
            0xF4F1DC34CEAE0041ULL, 0x4CEDDDF0EC079902ULL, 0x86016CA5D895CDF3ULL, 0x7069302BAA5BF94CULL, 
            0xB017EB2ED55A6E25ULL, 0xF1D4634552A5A1BFULL, 0xD73AE225ADC9C2D1ULL, 0xE67B72955A635A22ULL, 
            0x5AA527A14EFC4800ULL, 0xB0C3724D73B78890ULL, 0xCF35817389B9C344ULL, 0xB79D3E6BD1C05E92ULL
        },
        {
            0x7A5B7B3BFAAEDB51ULL, 0x6D18076FF8D5EBF4ULL, 0x08696189EE75F187ULL, 0x3EEE3574B2CB3ABAULL, 
            0xF48ECEAAB990AF90ULL, 0x8DA2B610C93A07F4ULL, 0x8B67F2F77553C112ULL, 0x6EE0E7FE8C1F31A2ULL, 
            0x44489C739A7D8416ULL, 0xDE18F328F595AD3EULL, 0xE15CE3A1B2A5B871ULL, 0x99DEBAC756C38373ULL, 
            0x27B5705111D51BB6ULL, 0x549C191CC7DED32BULL, 0x4B85CF448348265DULL, 0xC0A9BFE2024C7851ULL, 
            0x3B03CCB177962235ULL, 0x05DC64AE58833327ULL, 0x994DE59FDD59755AULL, 0x368CE3AB0952C4C5ULL, 
            0x32F1A054951EFBE1ULL, 0x661D75939C74CB70ULL, 0xD2D45ED5DC7BBD85ULL, 0x2D19DD82E2BBF5AEULL, 
            0x81692679454725E0ULL, 0xCECAB04D6418E976ULL, 0x10850B8C4AA58059ULL, 0xF51F9BA4E2770A33ULL, 
            0x2D23A0CE6A0C6993ULL, 0x81D917962159233BULL, 0xCA961B202E47E78AULL, 0xB7B73AB4B5CB90F8ULL
        },
        {
            0x4CA729474FCC9FDFULL, 0xCAB869731E70B9E7ULL, 0xF0CCC910AC871ADAULL, 0x247F3CEF2EB34E53ULL, 
            0x642E44C16A9AC506ULL, 0x7B8CF02F7B0C65EDULL, 0x6BE07DD7221971B5ULL, 0x5A103BA5E692C30DULL, 
            0x90BEE7EF5DCDAAC7ULL, 0x63ADC2F20B5B764EULL, 0x16F38EF7F79056BAULL, 0x080B3156FBF8B042ULL, 
            0xAA9FB90ED2E44F45ULL, 0xEBFCB0173D96A5DCULL, 0x3981662E937CABF7ULL, 0xC36B2CCC610A8A4DULL, 
            0xE9CB4E1C5AF28DB8ULL, 0x374644F5FAAEA85EULL, 0x8B0F8B63F71D5342ULL, 0x384821CE622EDB74ULL, 
            0x853F427FBD27AB92ULL, 0x6D48CBCA2987DEF9ULL, 0x09065C4F5998BEDDULL, 0x4B59AC30172D8874ULL, 
            0xC347A320EC8BF5B1ULL, 0xD9A831AB2072A74EULL, 0x122C2A62501C7CB2ULL, 0x2BFF56B58DEF85A6ULL, 
            0x3A1BD084C4FA218DULL, 0xF93AEB898F67446EULL, 0x2462F58D8BA7A733ULL, 0x9B1C87F47EDA9B81ULL
        }
    },
    {
        {
            0xBF84B3FBCFB2CB4FULL, 0x43E6C928C2351887ULL, 0xADC2EF9650E75267ULL, 0x977E7F22A1EC0E7BULL, 
            0xD7162F6C6A90FF3BULL, 0x8A594D1F27DFDAE0ULL, 0x71640979AD1D824EULL, 0x3AA51F81C40B2CA4ULL, 
            0x269A9485FB67D02FULL, 0x14D14D58F0FB4832ULL, 0xEA52203A88F82A54ULL, 0xCEFFD6561D87F009ULL, 
            0xE927C810C68D2CACULL, 0x2EED426B0CE694F0ULL, 0xCBB06001B5CF49BCULL, 0xFBA77F3C9F5CEF7EULL, 
            0xCCB0950B3C1B4B23ULL, 0xEC0771E62AF34175ULL, 0x4F3467A63B74C608ULL, 0xFBE3495F639ECD32ULL, 
            0xE3042B66B6BFB019ULL, 0x32E2DFE239BE84A0ULL, 0xBDD7A0EE08EA6100ULL, 0x3BCA3F53A677F150ULL, 
            0x9E31B9A8E56AA540ULL, 0x0C1DC6CD1A48EE37ULL, 0xABD35F7ABF8EEBE0ULL, 0x54D9D8C60BED77D2ULL, 
            0xAF6111ECBA32A4DCULL, 0x02F5C9259F230715ULL, 0x237AA7A5511A053CULL, 0x9D208DC0FA19C941ULL
        },
        {
            0xF42028128121485FULL, 0x280E85020F2D7BA8ULL, 0x04E22734454655A6ULL, 0x28E216E078222C73ULL, 
            0x29ADA04BE8F94A38ULL, 0x7BC322D61BDFF9F1ULL, 0xD7F030A3D44754B1ULL, 0xC81085CE941B89C8ULL, 
            0x7B01D7C6B9C88CDFULL, 0xF6AFC9A5E9F21B2BULL, 0xB5A8A5A0A8C995ADULL, 0x49B581B638C9D645ULL, 
            0xE22A2614CDCC3D74ULL, 0xF3BB798156FD6528ULL, 0x9987927FE1BE16DAULL, 0x52804AE4C2BC2BACULL, 
            0xAF0BB259B7FEAFBDULL, 0x873531D7CECF66FFULL, 0xBE6BE1F9292622C6ULL, 0x211F1844E75F0D75ULL, 
            0x49C0B9AF0037C70CULL, 0x99C8E4A55DB664C6ULL, 0x5AEB04D49243CBB4ULL, 0xDCEE53A4B26675BCULL, 
            0x619D7F5758DB2A94ULL, 0xE0A1CBE105C10F68ULL, 0x916A4447A2D00166ULL, 0x0ECFBDE9BDE3A79BULL, 
            0x84CDF6C848DF46B6ULL, 0x3AF13483082B553AULL, 0x4537E332CA0BE2CDULL, 0x44A45FD4F91E0CEFULL
        },
        {
            0xC66D3601FDF9F50CULL, 0x1B9135C9594028B0ULL, 0x0CD8632A359FFAB4ULL, 0xDA26FAE8B616D842ULL, 
            0x633341F34BA28BF3ULL, 0xE4D64FC2932AD624ULL, 0xF5FE63FD19C8F0AEULL, 0x90E0D86CAC6814C7ULL, 
            0x82A248B67500006BULL, 0xD08336AEE1DA55A5ULL, 0x1B7CBFC7DC5973F4ULL, 0xC6FFA6A02AE9B353ULL, 
            0x0ED87AA7951CE254ULL, 0xC40C1DD7CAE3645FULL, 0x97C1F5AAFD10D709ULL, 0x51FE36A771F24F50ULL, 
            0x3CF243412299E5E1ULL, 0x1B44EB2CCF6782FBULL, 0x981ABF3441641C77ULL, 0xA881A2FC75424CE6ULL, 
            0x99C6FD1925466386ULL, 0x57B84A38449D0A9EULL, 0x108A4DBDEA9F8B64ULL, 0xBB11D1609ACBEC2EULL, 
            0xC4C6FB87A28557DDULL, 0x124DD969664EA2DDULL, 0x96A2E2C014ED8E36ULL, 0x3CD33715F8670108ULL, 
            0xE9DB705FBCA71F68ULL, 0x547D913AE94B496FULL, 0x109822BAF8BC4D81ULL, 0xD275F1AD429D33A8ULL
        },
        {
            0xE43B10CEA5965099ULL, 0x965BF271D6CA585CULL, 0x03D03389FE2D11FCULL, 0xBA4880F735FEC112ULL, 
            0x20D937046389E691ULL, 0xE7ABDAE5C5BF7B78ULL, 0x1FFCA32673835E87ULL, 0x3105D284927C1B3CULL, 
            0xED0FCCD8ACA8A090ULL, 0x7732B1E72C1BDAF9ULL, 0x852D3589A18B31F6ULL, 0x0B5477A122A2D5EBULL, 
            0x83EAADB4E9D4CE11ULL, 0x094617A72BC1C077ULL, 0xA2954B539F98051DULL, 0x36E1F628327CB35AULL, 
            0xBD06FB188C3DED9DULL, 0x8A4DD916103A0E07ULL, 0x4885F56644B9FEBFULL, 0x8D8F325861EADF59ULL, 
            0xB6AE26E4F0C7A84EULL, 0x49CC85F93BB8B6CBULL, 0x1AC867F8F4B6E9F9ULL, 0xE2766385E9EE5A13ULL, 
            0xFC52972AB188CA9AULL, 0x30E136E02B8C24C8ULL, 0xE52DE04937CAF81AULL, 0x30E643457ED9DAC3ULL, 
            0x276BC3979B1A27D4ULL, 0x48E3B86CDC9DB287ULL, 0xB02316E8EC3E5093ULL, 0xDC229A34582C043BULL
        },
        {
            0xDC1C251494F08C49ULL, 0x5F164D91EB0BD77EULL, 0x066F4191160ADB5DULL, 0xBEBAF63E6F150945ULL, 
            0x312F8149069FCBD5ULL, 0xD865516BA84D8025ULL, 0x4F07D059A8928322ULL, 0xCAD9EFB802629663ULL, 
            0x3EBEA42E773D89A3ULL, 0x302087FAA02FEA53ULL, 0x1EAAD10E7E678DD5ULL, 0xCFBCED479AD9AD94ULL, 
            0xC922ECA9B2BCA691ULL, 0x98A249FDE19B042DULL, 0x5F78BF24BCF956A6ULL, 0xD2FA8C0CAF23A6CDULL, 
            0x283368976418EB42ULL, 0x5158C22D0642C9F6ULL, 0x55DEC7740856BE25ULL, 0xEA8F13D864A29610ULL, 
            0x6030F3DBF5D6D4F2ULL, 0xBC87F23A68EE2EC9ULL, 0x083602B3589A3603ULL, 0xC1DBEEA963A3CF77ULL, 
            0x7DDFD986C2AD5B3BULL, 0x9BB1F877DEF16388ULL, 0x1419D289932A4821ULL, 0x595F3A2BE95E1FB6ULL, 
            0x837B9DAD26072487ULL, 0x2D02A964AB970CBFULL, 0xD1D3551F640BC059ULL, 0x8B8866838AC2DB3BULL
        },
        {
            0xAF81C8AF648F1D85ULL, 0x532DD52FC9D2B289ULL, 0x95F627D36097E310ULL, 0x7F8E2A4815F4B505ULL, 
            0x856B3D3D1CC1F423ULL, 0x39A7492A51E319A9ULL, 0x5F99533923501110ULL, 0x1C889F807BCDD145ULL, 
            0x18CFCB7CA87E7FADULL, 0x4FD5DC853D91E511ULL, 0x0652904E7574B654ULL, 0x67951BFBBCE11D15ULL, 
            0xAAFE53A9612042F7ULL, 0x0C746324E157B550ULL, 0xAEB6B56AE04D157DULL, 0xEE1822C349289A17ULL, 
            0x38A8083FFC86C5F3ULL, 0xF2ECFBDF1FB9A7B1ULL, 0x94482BAD2FC8F192ULL, 0x6AAE36D3D5B35CB3ULL, 
            0xC6CC148DA6EAED36ULL, 0x6B12875BE09CA927ULL, 0xC7A28276AB9BED85ULL, 0xC03C363F9E61E462ULL, 
            0xDA263F35CE9C8B0FULL, 0x7EC0C6467BCF6541ULL, 0x523581450398DB51ULL, 0x32558CC620DFA7D9ULL, 
            0x26C66F0BB2F5BDD9ULL, 0x211838642F39EB2EULL, 0x8EA8664E9B6E4537ULL, 0x02A1FD1D4A9440C8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseGConstants = {
    0xEEE15A87E9951153ULL,
    0xD064560B6B7B832EULL,
    0xD917C8992ADA3AB7ULL,
    0xEEE15A87E9951153ULL,
    0xD064560B6B7B832EULL,
    0xD917C8992ADA3AB7ULL,
    0x35C48B79F279EC28ULL,
    0x104EDACB0B0A7AA8ULL,
    0x47,
    0x80,
    0xAF,
    0x9F,
    0xC6,
    0xC6,
    0x08,
    0xB8
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseHSalts = {
    {
        {
            0xFEDB9CAB2D0752FBULL, 0xFBEEECE9D81C2BDDULL, 0xCF8B1DEE21A1CFF4ULL, 0x023051EDF94335A0ULL, 
            0x6D8317BA6EB5C218ULL, 0xEC0AF81106C86103ULL, 0x2964DDC9A3354CE3ULL, 0xD3F6A50DCBCAAAB4ULL, 
            0x85BEF6C0172A9DE4ULL, 0xA523FFD8808FC2A0ULL, 0x7C4EE85A34A7F441ULL, 0x185FE7394CEA45D4ULL, 
            0x41F5A72E8FE09E50ULL, 0x99993797990AB74DULL, 0x073030714AC81CE1ULL, 0x807FBEEF8E29CB00ULL, 
            0xDDC3505E471B1E23ULL, 0xE4CA55DADD4FB6CAULL, 0x5F857CEE6D768096ULL, 0x4DA14BC7F60B17D5ULL, 
            0xF373988C68E4A173ULL, 0x9A0972EC51DB7DA2ULL, 0x420DD2E9E55FEB2EULL, 0x04D9E39C8808FA9FULL, 
            0x8A38E48A832AF7DDULL, 0x497D8D25E7FB24B7ULL, 0xED22270F32471006ULL, 0xB9C9C6D32AC3A2D5ULL, 
            0x19B58F7A6416C17EULL, 0xADDA47C05FEF1A0DULL, 0xE6BBC7BA86582BA1ULL, 0x8D43D901FBD904C8ULL
        },
        {
            0x59F04F8A45989B14ULL, 0xE17A9B1CAB127758ULL, 0x3E185B7BCDB1FED1ULL, 0xB001924D6FD05994ULL, 
            0x0A5ED011F1C0EB45ULL, 0x289AAC9FB1345E2AULL, 0xA262961F0B9496B7ULL, 0x7CF738CE980A8798ULL, 
            0x8AE1494F5955DEFDULL, 0x1B82814A98A1E4B2ULL, 0x4ED60003B98392CCULL, 0x5B333B144D9AE878ULL, 
            0xB2D877900777EF4EULL, 0x1773DE956725EED3ULL, 0x7B2F56687F055A8CULL, 0xCAC316E8F1ADB3D1ULL, 
            0x73DC15E176FAC2F1ULL, 0xA0573E66F6B82469ULL, 0x6DC7E6DD1F123019ULL, 0x213CBD2302C52D22ULL, 
            0x01EC23500AF57828ULL, 0x7D511BE5F2110225ULL, 0x8E9E07E85B895A37ULL, 0xA70A29C7AA1B422BULL, 
            0x7C61372E3D1A2A85ULL, 0x8915EEFEB0D64B7CULL, 0x69717715F906B48BULL, 0x562DE9789D204F3FULL, 
            0x621099E969772E45ULL, 0x8375902D25F14C5EULL, 0xB1E175A53F777B23ULL, 0x1256E99E45F1B3FEULL
        },
        {
            0xA590B56213B67383ULL, 0x749CA3D5A74D9EEDULL, 0x937EF34FFE37DAA7ULL, 0x658727CAC857A626ULL, 
            0xC5DE5CDDCBF20A7AULL, 0x31BA39EB7E2FD51BULL, 0x59713AE92D5BE6D7ULL, 0x398EBCB5D47D67F5ULL, 
            0xE6C847E6B95F9058ULL, 0x0EE7C04764CEBD80ULL, 0xCD808A911EFAE61FULL, 0x249CE1E9826F1188ULL, 
            0x610397E16421ADD5ULL, 0xFD0C1E6E8F36779BULL, 0x2443D1BB03202CEFULL, 0x0825788322C32F46ULL, 
            0x9131C2702A4C8527ULL, 0x5D97FA6473DF3800ULL, 0x2598378880123050ULL, 0xCF97431AD4905377ULL, 
            0x9946F1420F8798E8ULL, 0xE71C172575608559ULL, 0xB35CCAD5E82BEBB1ULL, 0xF22BEAA30B69CCECULL, 
            0x1BD7B25615CC52E7ULL, 0x390F07FF02CC5536ULL, 0xA06C465213D68782ULL, 0x9B3346A932490696ULL, 
            0xCB6B356479FB9B2FULL, 0xCA8214A4EFAD5542ULL, 0x978B554CD4EC8CC7ULL, 0x5F74F3BFA92FD497ULL
        },
        {
            0x2843274618631B42ULL, 0xBC4D0D22CF9A9325ULL, 0xCF12B2FD3CB10199ULL, 0x6C0938A78448AB69ULL, 
            0xA3F6177EC968CF7DULL, 0x8F58E22963FF38FEULL, 0x999ED9B30B9AB61EULL, 0xB998A5EBD7357A08ULL, 
            0x67FD9D51107E2DA8ULL, 0x7EA0FFC5D74DAEFDULL, 0xFC4CFE37E4D754F4ULL, 0x2E96002322039869ULL, 
            0x7001C048E7378C54ULL, 0xB809ECF42F12A598ULL, 0x180F310628902842ULL, 0x1268404DC9E7EC85ULL, 
            0xA7C3854C0DEC7BE1ULL, 0xF0F123B5ABBCC94FULL, 0xEE4D4BCA93AC7621ULL, 0xF4934A32828DD97CULL, 
            0xE138B2EE0C74D133ULL, 0x7C9162B1E09BD4E1ULL, 0x3D41312C2C7CBA7AULL, 0xB1D3B47D5C5ABB02ULL, 
            0x42FC6D318B4E332EULL, 0x43A2034AC1653104ULL, 0x415C933D81848168ULL, 0xDEEB8EEBD4CDEA3AULL, 
            0x4C79B66B125B7C8DULL, 0x7E90410ABB3DB2BEULL, 0x401D0BFAEE18C9F8ULL, 0x4AF167E66C14D4C2ULL
        },
        {
            0xBDC08766F103C240ULL, 0x4F929AACE8C3D3B8ULL, 0xAC3BF36446AD411CULL, 0x1C05E32F6BBB0D3AULL, 
            0x37978C86C30E3335ULL, 0x3BD29E7492D35EBCULL, 0xEF85B97A65B93594ULL, 0x0D953FE43F8477E6ULL, 
            0x6212DA250827C5BDULL, 0x7AA2CA3EBA48A553ULL, 0x75DD498F1AE13D2BULL, 0x96ACFF5F4E236B02ULL, 
            0x70DBB43571991C1BULL, 0x3E8EC9B4EB187C25ULL, 0xD8EF44E9B70E06D2ULL, 0x8566BF2DB65E6035ULL, 
            0xE1FD84AE0FECD0A7ULL, 0x76DDD7FD20EB5586ULL, 0x0BF42A31CC7D0ADCULL, 0x95A751840BBACC2DULL, 
            0x381C5D498B2BD44AULL, 0xA734D4507B477884ULL, 0xB5195108753762F2ULL, 0xE88FC70A834018FEULL, 
            0x798523C7F2F2BD19ULL, 0xA9FAFB4EE23B6D2CULL, 0x97362C461CB44241ULL, 0x66472AEA95D1F097ULL, 
            0xA329C5E32E256D0AULL, 0x1868EDA65DD19D58ULL, 0x7CD9D6C24B5CCDE7ULL, 0x2F0C1A95ECFCCE4CULL
        },
        {
            0x25C7A3348D592F15ULL, 0xE1DAF55A8F1D73B6ULL, 0x5E48F2567A018A69ULL, 0x242746908F462B1FULL, 
            0xD1259FF15B675ECFULL, 0xCC299449A54FDC75ULL, 0xC8D4C622A8402528ULL, 0xAD1640D1211AE20EULL, 
            0xD0C557DAE0BA3400ULL, 0x21AE37F8AF423D60ULL, 0x04AD5B514CFC3BB0ULL, 0x63A3DC72D5A09451ULL, 
            0xD3A5B98D55CD826FULL, 0xFBF4CB56D0B7F167ULL, 0x526B452B0C807F2AULL, 0x759C003D58F404E5ULL, 
            0x6C14DDD4D5B5213BULL, 0xD9C9A05D4B1BFCA4ULL, 0x17B8DB82B51991E2ULL, 0x8CA6E32631492BDDULL, 
            0x0FA62A934EB66287ULL, 0x2E0F96942EFB597EULL, 0x7099F0B1C701517EULL, 0x4F4AD790B2B25F9DULL, 
            0x22DAA45F9484F907ULL, 0x51E35A20232E6BD0ULL, 0x275661D4A5BF1D7DULL, 0x72395B3A22670CCEULL, 
            0xCBF0E65B6D5A44AAULL, 0xB32F7522F25F954BULL, 0x249F472E4FE227E0ULL, 0xF2FF297EAAE76398ULL
        }
    },
    {
        {
            0x8E4C2ABD19D475A0ULL, 0x1B71C59989FF0617ULL, 0x285E18A2172F621CULL, 0xA34525F022B5725FULL, 
            0x5015B0175CE55C68ULL, 0x77FE6221E4FF2A0FULL, 0x1CCB7467A2F7953AULL, 0x2C157719D8C8E548ULL, 
            0xCE87ABF47BBD9E58ULL, 0x6E279A70381CD80CULL, 0xB53DD09AA757C392ULL, 0x7B84846E99F9DC4AULL, 
            0xFD0090D49307800CULL, 0xA5AE74AC830011F1ULL, 0x69EAB9FC2C020543ULL, 0x79E152C919A068B8ULL, 
            0xD0A8452A2CA8B9F3ULL, 0x0474BB8F3CD9975BULL, 0x38A052C52E4F03B9ULL, 0xD8ED5027EFB39343ULL, 
            0x941788B8ED96FA1BULL, 0x079111E443BF3549ULL, 0x0DDAF3C1E3F2E801ULL, 0x10740162C1F14A4EULL, 
            0x56758EB3C10B1D22ULL, 0x494D16AF287DF9A4ULL, 0x901C6BBD8B0DCEDEULL, 0x5EC373980ED01E0AULL, 
            0x8C285A8F822012ECULL, 0xF59EEBD8A2B9AEB4ULL, 0xF37976574FBDA32DULL, 0x63E8F9F0DA9955DEULL
        },
        {
            0x6B45EC279A27A11AULL, 0x0A3888EA3865AD0CULL, 0xAE2590D826A19783ULL, 0x63E73047F35E9520ULL, 
            0x3D7609F4BBCBBB8FULL, 0x029FC66D5FEEF6D6ULL, 0x094ECFDB5E8C7DAFULL, 0x95A4725BB0CED190ULL, 
            0x86E2B7F5FB49571CULL, 0xFF985DC17EB1CFE1ULL, 0xA818946DD4108BB5ULL, 0x81EB23C332B74F36ULL, 
            0xBC8568A7BCC35086ULL, 0xA461C367190E7CC5ULL, 0x19468103CE1B68D1ULL, 0xF52E76FF0C78F7A9ULL, 
            0xA7E1FCE95BF1B836ULL, 0x9AD5FDC5828886A0ULL, 0x76E4D3575BE5C7A4ULL, 0xED63AF674E647683ULL, 
            0x9D24BAA6786B0F60ULL, 0x24270D959AA517B3ULL, 0xF80A4C4B84D0CC69ULL, 0xB6F476B94628BA60ULL, 
            0x1EAFE2006AC62B34ULL, 0xF64DBAE7F2576EEDULL, 0xF711BEB2BA3E8DB1ULL, 0x70C04A2483B6F65EULL, 
            0x318AB0E046F360C9ULL, 0xF6195AA32A61D66CULL, 0x6475F3DE87C78AD2ULL, 0x89FB42F8145C2C45ULL
        },
        {
            0x116526A534BAEB57ULL, 0xB59D7681358D0C92ULL, 0x2BC57410282A205BULL, 0x60DB8EE6F1754D79ULL, 
            0x4EEA24CF7976DE32ULL, 0x79CD24D71BB718DDULL, 0x6A17AEE91188DFCFULL, 0xD3CB4CF03634DB0BULL, 
            0xDA10DB38CAFC5C5EULL, 0x93B4E3ED6ED0BA85ULL, 0x7D12C12E8067243FULL, 0x4CEE075439649A54ULL, 
            0x29F0BBCA5D8930D3ULL, 0xE0CDE7579D1E0781ULL, 0xA4D0A2A559746787ULL, 0x72948E100472687AULL, 
            0x161416B252A7CC2CULL, 0xE1EC85F303D4B5FEULL, 0x89F37C8E85AD5273ULL, 0xCCA6CD2AFCA9863DULL, 
            0xA8EF147625DF3E0AULL, 0x4CF55FD18859BC51ULL, 0xB08C830010E3FB1BULL, 0x129E55F57A8746F0ULL, 
            0xB1820078785A777BULL, 0x605AAFC46884A615ULL, 0x7D9C79C6C95F2862ULL, 0xB46E5EEDA630A49DULL, 
            0xCAAEB4ACD0670697ULL, 0x2B93F798204ECEB7ULL, 0x900F85F9193ADB97ULL, 0xDB680876C3CB7A2CULL
        },
        {
            0xCA84ACDB8FA1F66BULL, 0x6F72D447DC2ED7E5ULL, 0x7CEF749A5BC235C2ULL, 0x283B100036C43E15ULL, 
            0x46364DCB35036C45ULL, 0xDAAF3FF8A75BA5BFULL, 0xA2201C46F770EFBBULL, 0xAC7A1D3976D5120DULL, 
            0x3411A2E9EDD5477BULL, 0x37108B5E343ABAD4ULL, 0x74AC0710A957D642ULL, 0xBB4EFB6DD193CC81ULL, 
            0x3B826400681172B1ULL, 0xF108BDE85BEAF237ULL, 0xCF1236E1D9488464ULL, 0xDCACB7C9EA48C3DEULL, 
            0x9D58D5E6C0B38F94ULL, 0x5AC5EF17F1405310ULL, 0x1519045E62BF1678ULL, 0xEB525A164C69452EULL, 
            0xABF2F1A91412C0C2ULL, 0x33FE9FE06AA4FBC0ULL, 0x624A6BA4A6E069A7ULL, 0x0A053C8394923DE4ULL, 
            0xAF8F2203570671A4ULL, 0x761FCDA758DDFA4DULL, 0xC7C8B2F91FD61012ULL, 0xD9691122FD495931ULL, 
            0x3FD742BD305D9ED4ULL, 0x8ABD50D8EA01A573ULL, 0x0325AAB8C2AAB55AULL, 0xDDBD92C088191A4DULL
        },
        {
            0xA13E5398FBBD1B1EULL, 0x392D0D38783662DDULL, 0x9DE3F30D0E04C48BULL, 0x968DFA0129E5C4E7ULL, 
            0xA522638DFA8F60D0ULL, 0x0D76C096B10BD9B6ULL, 0x326A0D970985E790ULL, 0x7E209CCB3DB2E39CULL, 
            0xBDC387297D9678C0ULL, 0x41ED3A2472C4E0E2ULL, 0x69F2B06A93786A15ULL, 0xA48BFC5C8F1CE64AULL, 
            0x6A177B2321E22510ULL, 0x018AFDDD030A76E3ULL, 0x287C043966E69A85ULL, 0x5E78A3111736F438ULL, 
            0x83D0AE71640FAFB4ULL, 0x3B14021E4DB2B00DULL, 0x1887CC73B1B86111ULL, 0x3E5A91D223C8F552ULL, 
            0x02814F03ED4EFBEFULL, 0x9D36FE15E9829745ULL, 0x8544CC6B21A75BA5ULL, 0x27DC2746DAA079E3ULL, 
            0xBEB840FF60CFDAFBULL, 0x74EA242E1AF09515ULL, 0xE2E9862BF0A672CCULL, 0xE179BBDE5165E938ULL, 
            0x123212DB8A764631ULL, 0x4BFFC73C26058FD5ULL, 0xFE8DA117D4C11EC0ULL, 0x5A854BB96FB82F81ULL
        },
        {
            0xE28D78FAE3C8523DULL, 0x4BDCE021E771BD9AULL, 0x3DCD94B6D674A672ULL, 0x3CBF87C2FDEB6813ULL, 
            0x4304E8CE2D6A7C6CULL, 0x10ED563229EBF223ULL, 0xA116C301EE024FBAULL, 0x7FD59E2BD5D69688ULL, 
            0xE49876D9D354A37DULL, 0xDEB0576871DA66C8ULL, 0xC197FA6F362AE71EULL, 0x15935257781C6A69ULL, 
            0x2A72EDD1B4DA92BCULL, 0x760BAEC3B6719179ULL, 0x937A219149670703ULL, 0xF06279F7580F063DULL, 
            0x07C1F92701E8878BULL, 0x108BDC5C6E1BE7B2ULL, 0x4250201AD7E12E0AULL, 0xB0210E508FE0F87EULL, 
            0xEC03B7D9E4ECD2A6ULL, 0x029E56D01E10D021ULL, 0xA3156D217486D360ULL, 0x63564F77ADDE66EEULL, 
            0x086A6FBA4041B514ULL, 0x776F4D18E7F90A81ULL, 0xFD5A757DFB597E15ULL, 0x474E26497F2CC6D2ULL, 
            0x33C0A85D35C10748ULL, 0x52E7DC3D8DD508B5ULL, 0x81B9005C466C1F40ULL, 0x26646303DCB797A6ULL
        }
    },
    {
        {
            0x148A8E45A12474D1ULL, 0xD1B52E0F7722A78FULL, 0x8BC9E8F7CC9BA593ULL, 0xC024693F338C8E50ULL, 
            0x2B1E5E55277C3457ULL, 0x17820CE6B3C610A2ULL, 0x084B0C52C062A8A0ULL, 0xC411525A857BAE10ULL, 
            0xF0DCB7333F8CED9AULL, 0x02136F049044C076ULL, 0x4BF9C1C5223B1C14ULL, 0xF9EFBDC8B349A4A5ULL, 
            0x2FA8382ED29EA87DULL, 0xA23C64682AD17B61ULL, 0x9E1A8EAAEFDB0613ULL, 0x1078313891D40B34ULL, 
            0xAE30856E77BAACA4ULL, 0x29921B47A5054A7AULL, 0x8DC8F2AF7343ED6BULL, 0x6C75991E79B1603BULL, 
            0xC215B1BD7EDB88A0ULL, 0xC525EF012CC57840ULL, 0x261FD3FA512780ADULL, 0x9C47F7CC221FBF84ULL, 
            0x5D8EB2647F1B4E6CULL, 0xB08F27172239A86BULL, 0x79D6DFE3C5D10F72ULL, 0x08FF2D9165930196ULL, 
            0x17A484C39594CEC6ULL, 0x66B4482812054347ULL, 0x08B3D348D67C6468ULL, 0x78D1E22AFA4E85E4ULL
        },
        {
            0xF1C000536DA834B4ULL, 0xE6E30E81A305E5B7ULL, 0x064715BDABBC74EAULL, 0xB5DD945C2324E021ULL, 
            0x8D961AE5AB1C26B5ULL, 0xC7AE4A7A7177DF5BULL, 0x2ABE31E686F036D2ULL, 0x60E04930E1260F73ULL, 
            0xF9C86DC4560EF38DULL, 0x7A399C649E09CAE5ULL, 0x7C3410D3E15B6642ULL, 0x87F67E526606457DULL, 
            0x905F732056D5C8F9ULL, 0x142582F3DBF0275CULL, 0x981CF5E0E97945B0ULL, 0xC550186628A63B7AULL, 
            0x7AA65027BCF0E315ULL, 0x54DBC43DC4D8099AULL, 0x13A65E83A9021B18ULL, 0x16FA970AB465300BULL, 
            0x8D3FA5D7495D0C58ULL, 0xBD5A59E06B4F83A6ULL, 0xFBF57730366D5D50ULL, 0x097737C1BB335EF6ULL, 
            0x5F39007144119664ULL, 0x73C074F27E72D999ULL, 0xB7B31D8BDFAE86D7ULL, 0x210966A38934FD32ULL, 
            0x55C9866AC724559AULL, 0x9CBDBC5E3C142237ULL, 0x5E741C48A68680C1ULL, 0x3ED6B94C4804C1BFULL
        },
        {
            0x4C9E3033029A44D5ULL, 0x821FA675D55BFDDBULL, 0xD02371CE2CEE2504ULL, 0x4B664C0CC7A792D4ULL, 
            0xCBF9D1381D2820F5ULL, 0x8130EBABFC3AE525ULL, 0xF03F4F6FDFE2390AULL, 0xFDD7D08E755D56B6ULL, 
            0xB177AB4ACFE54F47ULL, 0xF30F577CE8EA7965ULL, 0xED0F5E42B2BDDFA5ULL, 0x5F1DA3C7DA48B5F2ULL, 
            0xA97E3EC9055EB8F8ULL, 0x2B1A54D2AA1929C7ULL, 0xF3343C6F0D04B434ULL, 0xCF85DA29331A6924ULL, 
            0xD51783A12A42DFC3ULL, 0xA1EAEDA30AC28624ULL, 0xABB569AE13A6AE85ULL, 0xC1984363E95FCB4EULL, 
            0xB86EAA08F7F0681EULL, 0x4DBE2EFE52A018E1ULL, 0x4291772227083D91ULL, 0x4EA4C787D12AAA25ULL, 
            0xE2B69D7FBB0D9A30ULL, 0xBE1666968135169EULL, 0xA6BE7041D9D84286ULL, 0xEA2C6EC86420FDCCULL, 
            0xDC04577E19556027ULL, 0xC7D75B06D0D7EC4CULL, 0x5854274A91C35B66ULL, 0x20F90C5264AB540CULL
        },
        {
            0x4E4746B454AFE638ULL, 0x94C5E19780400D5EULL, 0xE961C3A811F0518DULL, 0x3C65E487C42C8047ULL, 
            0x31683E572B6AE4D7ULL, 0x3E426E6999D29B5AULL, 0xEABF2FB761E3CE02ULL, 0x63FF08491A0E2222ULL, 
            0xE04F257A9D771FC4ULL, 0x0410B9269505AF08ULL, 0x64C04EA365B4B77DULL, 0x72691CFD98AE649BULL, 
            0xB1C29ABD79CB774BULL, 0x8DC9F2CEC2022A49ULL, 0x42F1044D7EA0E605ULL, 0x4794BD568B9C1E25ULL, 
            0x31E569A2E3A2DBDEULL, 0x55366C73C182F6BCULL, 0xCD9E2EBEA3BD38BBULL, 0xAA4459A68434EF91ULL, 
            0x433B811E8A91FF2CULL, 0x4B1A64CC0C721B8EULL, 0xA31D230A3051F6AAULL, 0xE525135851E0AD87ULL, 
            0x9CA5F3AC1D58C988ULL, 0x7C5D136C1E1482CCULL, 0x49DD0CF09D7F9C24ULL, 0xDAC7693AC791CBACULL, 
            0x6D6767A081A61846ULL, 0x4651D6D83717A558ULL, 0x9D40C3361B2503E9ULL, 0x34A89649A7528987ULL
        },
        {
            0xB41DA30762E939A8ULL, 0x7B37ED1F6795EBD6ULL, 0x570152F00E234947ULL, 0x3CA62377139C05DAULL, 
            0x19883562793E413FULL, 0x55DFA43905520C57ULL, 0x4B2F95058BAB2108ULL, 0x5F1DFFE3ADA8737AULL, 
            0xF0CA7BBD32B85B81ULL, 0x9B0AD764E339F735ULL, 0x9FC4C39373874064ULL, 0x1F36F4E761BCFB03ULL, 
            0x9E38A4C6CDDDB2EBULL, 0x860E5E43E893C73BULL, 0x31B8E40D2778D17EULL, 0xF2216597BBD5D667ULL, 
            0x4EF20C7F74AA9296ULL, 0xB9CEA8D8A31319D1ULL, 0xB530CA545A3526D8ULL, 0x6AA50D0E81FDD54DULL, 
            0xAA2BD14E995FE17EULL, 0x68F407DD47E846CEULL, 0x3E2C88239AF24CBCULL, 0x7775BA2FF0119F30ULL, 
            0x3C98A741077A89F0ULL, 0xA3A355A434884C01ULL, 0x4C90CCC3D6BEA5CEULL, 0xB46061163B1D998FULL, 
            0xFC9348CAC3766B29ULL, 0xB0C509209464E2A8ULL, 0x155A8D2EBB8FC8FEULL, 0xE7AA8D76BAEE002DULL
        },
        {
            0x690F6A2DDEACCC64ULL, 0x624D3B5E606F04D7ULL, 0xE8420ED3D36E8139ULL, 0x822C9459B7B65D2DULL, 
            0xC2B1606C312D9C73ULL, 0x84EE70DE11456C75ULL, 0xB226D7DB1392C1F0ULL, 0x806EDA35D6F42CA6ULL, 
            0xFED3CBE17296B743ULL, 0x65527E6F51E62667ULL, 0xC9221C5CE1412D74ULL, 0x595E885CD6885885ULL, 
            0x0F2D059FC3B197F5ULL, 0xD4F7CEC431AEE3A8ULL, 0x5D5DB438516768FDULL, 0xF5446A0A1EE11E30ULL, 
            0x4BAF27EB12A4E86EULL, 0xB2CC491154E65538ULL, 0x363A7F6F6430CFC1ULL, 0x857599EEDFB3FC5FULL, 
            0xFF22F751AFB3DB7DULL, 0xAC2BA1FD58D1EC95ULL, 0x4EE57064BDB504C5ULL, 0x71F6617924630CC7ULL, 
            0x85B0D08304902C98ULL, 0x543C5303D0A33359ULL, 0x1806C0E32B643489ULL, 0x489C7260F3841300ULL, 
            0xB5527178BCB0E90BULL, 0xAA0EA55F25D4BC55ULL, 0x06DD2A848CA54655ULL, 0xBD48CE94F9643D2DULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseHConstants = {
    0xBEBFFBF807880360ULL,
    0x6CD69A2D08846E6AULL,
    0xC04854B5A96E4779ULL,
    0xBEBFFBF807880360ULL,
    0x6CD69A2D08846E6AULL,
    0xC04854B5A96E4779ULL,
    0xE6C1ED146BFD8490ULL,
    0x5A19DA3A2C33420AULL,
    0xCE,
    0xD1,
    0xF5,
    0x46,
    0x3D,
    0xAD,
    0x22,
    0x1B
};

