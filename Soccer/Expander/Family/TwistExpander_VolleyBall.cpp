#include "TwistExpander_VolleyBall.hpp"
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

TwistExpander_VolleyBall::TwistExpander_VolleyBall()
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

void TwistExpander_VolleyBall::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 18015316146137916392U;
        aCarry = 12637617626465843800U;
        aWandererA = 13426366396063970110U;
        aWandererB = 15047977618877711537U;
        aWandererC = 10705848471651766108U;
        aWandererD = 10197916051943693236U;
        aWandererE = 14437497956176934473U;
        aWandererF = 13793714064182792661U;
        aWandererG = 11291034719169620428U;
        aWandererH = 11067898429992743717U;
        aWandererI = 12550857678395334021U;
        aWandererJ = 14982314062259569182U;
        aWandererK = 13167058656280212411U;
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
    TwistExpander_VolleyBall_Arx aArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_BArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_CArx;
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
    TwistExpander_VolleyBall_Arx aKDF_A_DArx;
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

void TwistExpander_VolleyBall::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 16506910480159265058U;
        aCarry = 9995999181641419675U;
        aWandererA = 12068855738503331488U;
        aWandererB = 15958273583312440583U;
        aWandererC = 9556542827675658994U;
        aWandererD = 16035490418583021835U;
        aWandererE = 14076988946369589942U;
        aWandererF = 16769350993386193793U;
        aWandererG = 16552156841165495215U;
        aWandererH = 17157057424864640402U;
        aWandererI = 15427246624929531721U;
        aWandererJ = 10171034547993289714U;
        aWandererK = 16903407221028745231U;
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
    TwistExpander_VolleyBall_Arx aKDF_B_AArx;
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
    TwistExpander_VolleyBall_Arx aKDF_B_BArx;
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
    TwistExpander_VolleyBall_Arx aKDF_B_CArx;
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

void TwistExpander_VolleyBall::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneA);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneF (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneF);
    }
    // KDF_B PhaseA invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseB invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneB);
    }
    // KDF_B PhaseC invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneD (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseD invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneC);
    }
    // KDF_B PhaseE invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    }
    // KDF_B PhaseF invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneH);
    }
    // KDF_B PhaseG invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneA);
    }
    // KDF_B PhaseH invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_VolleyBall_Arx aSeed_AArx;
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
    TwistExpander_VolleyBall_Arx aSeed_BArx;
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
    TwistExpander_VolleyBall_Arx aSeed_CArx;
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
    TwistExpander_VolleyBall_Arx aSeed_DArx;
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
    TwistExpander_VolleyBall_Arx aSeed_EArx;
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
    TwistExpander_VolleyBall_Arx aSeed_FArx;
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
    TwistExpander_VolleyBall_Arx aSeed_GArx;
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
    TwistExpander_VolleyBall_Arx aGrow_AArx;
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
    TwistExpander_VolleyBall_Arx aGrow_BArx;
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

void TwistExpander_VolleyBall::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_VolleyBall::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_VolleyBall_Arx aTwist_AArx;
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
    TwistExpander_VolleyBall_Arx aTwist_BArx;
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
    TwistExpander_VolleyBall_Arx aTwist_CArx;
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
    TwistExpander_VolleyBall_Arx aTwist_DArx;
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
        TwistExpander_VolleyBall_Arx aGrow_AArx;
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
        TwistExpander_VolleyBall_Arx aGrow_BArx;
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

void TwistExpander_VolleyBall::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 2, 1 with offsets 512U, 563U, 7307U, 4066U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 512U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 563U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7307U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4066U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 6608U, 7535U, 6050U, 6393U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6608U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7535U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6050U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6393U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 1, 2 with offsets 4666U, 3330U, 6709U, 1876U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4666U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3330U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6709U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1876U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 0, 3 with offsets 4104U, 4595U, 1893U, 3230U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4104U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4595U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1893U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3230U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 1348U, 420U, 1966U, 172U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1348U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1966U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 172U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 1052U, 1286U, 1652U, 1694U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1052U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1652U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1694U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 2, 0 with offsets 1580U, 1005U, 1926U, 928U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1580U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1926U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 928U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 1, 3 with offsets 1150U, 1207U, 381U, 379U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1207U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 381U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 379U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1184U, 38U, 2023U, 1873U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1184U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 38U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2023U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1873U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_VolleyBall::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 3 with offsets 7922U, 6299U, 7754U, 5082U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6299U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7754U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5082U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 1 with offsets 4225U, 3181U, 7663U, 3498U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4225U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3181U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7663U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3498U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 1, 2 with offsets 249U, 7544U, 1810U, 3849U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 249U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7544U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1810U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3849U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 0 with offsets 7685U, 7950U, 7247U, 8154U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7685U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7950U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7247U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8154U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3690U, 2705U, 1993U, 3615U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3690U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2705U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1993U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3615U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 1, 2 with offsets 682U, 1711U, 410U, 1832U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 682U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1711U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 410U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1832U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 0, 2 with offsets 1177U, 490U, 390U, 1938U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1177U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 490U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 390U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1938U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 3, 0, 1 with offsets 754U, 272U, 691U, 1697U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 754U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 272U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 691U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1697U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 2, 0, 3 with offsets 880U, 1488U, 834U, 885U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 834U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 885U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1865U, 1044U, 2018U, 1537U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1865U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1044U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2018U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1537U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseASalts = {
    {
        {
            0xA0B83EA0D27B631CULL, 0x815E9B67DA296DD6ULL, 0x379F2E917386176EULL, 0x0D7D23CC3C8CB68CULL, 
            0xBBE086CB95EAE3BFULL, 0x91FD46EDB33FCD4BULL, 0x9B18741D260B706DULL, 0x342A18AFAA3E87E7ULL, 
            0xA149ABDA24C7FEECULL, 0xEDBF1DB08913F648ULL, 0x0B0348ABBA897F26ULL, 0xD05F486D0FCDB612ULL, 
            0x78DD6DE219A9CD91ULL, 0x505408EB7307F8B9ULL, 0xD993E463DFE3601DULL, 0xF8169D3F811F8F9FULL, 
            0xCF89377CF8E20EACULL, 0x35C3BCEF90FC03B6ULL, 0x7C02D9ECE5D8A1BAULL, 0xE37C44CE1BDA4B87ULL, 
            0x2375A8585491E3E7ULL, 0x815098208AB8FF31ULL, 0x970CA4690E455E4AULL, 0xC55270F1A26CF617ULL, 
            0xA51CA82329BD4D43ULL, 0xE03F3CFB20BD4441ULL, 0x1C37F48FD2C1214AULL, 0xC3F82641DF2A8632ULL, 
            0x426771C4A22B8D0FULL, 0x6FE19CAE56173C54ULL, 0x8275C95B1EE63440ULL, 0x88DE0A93781215E5ULL
        },
        {
            0xFE8A613FE9488F56ULL, 0x7D5209351F996A1AULL, 0x0BE1B1CDB8185935ULL, 0x71C8D4C6D1584858ULL, 
            0xFA2FD3D99FC6B621ULL, 0xAA2ED02E0DE6A1B2ULL, 0xE3D69A16ADAC8594ULL, 0xC2FFDC2FFF394927ULL, 
            0xA9C6BB4DCE255FEAULL, 0xDBAEFC213101B0D3ULL, 0x61E6BFB0A8A34745ULL, 0x1AD1F4989EB468FEULL, 
            0x0846F880EFEAFE7BULL, 0x7F0A96BB219E83FBULL, 0xE6C71E1008486531ULL, 0x4C8AF77867B0F190ULL, 
            0x6FB10E5587607F05ULL, 0x658D6B389EADA48AULL, 0x89A48DCF247A0CA5ULL, 0x379491D5E307B260ULL, 
            0xCC80EFD3E2BABF7BULL, 0x3A1558EF47986E2CULL, 0xD643C9CC7CFF08B4ULL, 0x84CAF66771641DEFULL, 
            0xB849A0C4D91EA70DULL, 0x9889F1D37FB74317ULL, 0x46AAAAF5CA91A1D6ULL, 0xB95D7C53F54EA68FULL, 
            0x3E9082A4B4603EC7ULL, 0xEFEFF3E4D49CC848ULL, 0x7EBCEBC1F20BC36AULL, 0x5F6C4CF24ADAC6D7ULL
        },
        {
            0x5B6556C0E5E092B6ULL, 0x343AE4E4D2AC7B94ULL, 0x0D62781F6AFC2DF7ULL, 0xC3874EB73D6006A2ULL, 
            0xBEA35676C4C47B01ULL, 0x596E03AEFE1D9551ULL, 0x11D534B672431284ULL, 0x920B9E5DF3799DA3ULL, 
            0xE9A9E085E1B59852ULL, 0xCA9051ECA7669BE3ULL, 0x535DA19EFF815E14ULL, 0x313B33E10A400065ULL, 
            0x84314D3581CB7D2FULL, 0x76CB2F71DF13F5DFULL, 0xB448E59181981BB4ULL, 0xC1281B34BB0AD3FDULL, 
            0x4A5A04B8AC6B200AULL, 0x37288324A708670EULL, 0x86BC27BBBA354E64ULL, 0x91819C7B2D2F74F3ULL, 
            0x236A3D82CF05827FULL, 0x4478FEAA7D0B2004ULL, 0x2B9FE41BD3663F0AULL, 0x3709B07C137CA3C2ULL, 
            0x74F952DEDD229C94ULL, 0x298CF55652F87513ULL, 0x47166234192CF717ULL, 0xF9C0691654B00D8DULL, 
            0x009B0D1913912D50ULL, 0x8FE8F64C6BFA76FCULL, 0x2301D6E6C852701CULL, 0x0FC87F9572A61975ULL
        },
        {
            0x41378E38FAED010AULL, 0x8935EDCF3EC6BA10ULL, 0x226D15DE769DAC32ULL, 0x5E3E83912C3A2908ULL, 
            0x5AFAA67FA2CB6C2CULL, 0xDFE6F1EE3C90EFBCULL, 0x13F52C926C4DA18EULL, 0x024D1628DACF6712ULL, 
            0x8351AF3262B6648BULL, 0x1A10735704FE5F63ULL, 0x2CBAE147AA90937EULL, 0x0F68B7FF7FBB9E12ULL, 
            0xE57356B0766DBF4CULL, 0x03A96702D19DBDE7ULL, 0x3F57DE057F8878C7ULL, 0xE9998A30889D8E67ULL, 
            0xFD7EE124E37C1E30ULL, 0xF73692D5001AE994ULL, 0x82A530078C7B0DB2ULL, 0x3880502A21CE2892ULL, 
            0xF5068991E47C962CULL, 0x30BF9D3B910FD9B1ULL, 0x6F943ED49232956CULL, 0xBC2BCEC6E00346F7ULL, 
            0xD06EAABB7CD2B3FEULL, 0xBCC3E7A7CFF86E4BULL, 0xB9B458378D8F7829ULL, 0xA9BCD5844357F9ABULL, 
            0x0BCDE2B28B1B1F15ULL, 0x9404196FDF2877A8ULL, 0x1D404FBB515FD2BBULL, 0xE90D2AF760791652ULL
        },
        {
            0x6B4BFDDC28035D79ULL, 0x6EFB5059FB3C7C1CULL, 0xF079168A258FF39EULL, 0x22265DD9804AC8C1ULL, 
            0xEE19B7C567E7A737ULL, 0x023294BE271EA57AULL, 0x01745BCABDF4233BULL, 0xADE8733CF443DE6BULL, 
            0xB1A147083AC37372ULL, 0xA2DA2DF0A6F7619EULL, 0x3DDCA03B804972E5ULL, 0x1B8AE1899D7772A3ULL, 
            0x2EB73FFE1349B13AULL, 0xC6EA3410AF1EAD11ULL, 0x9EB0706AA1C0CF5DULL, 0x5853A5BC350139F8ULL, 
            0x22AF49D0571702F3ULL, 0x19118F490560012CULL, 0xA60C4224500CE76EULL, 0x5DC2A087156B678DULL, 
            0xAEFF6C0B03FAECB7ULL, 0x254D79C8FDAE767DULL, 0x2CDD91BA850F4E45ULL, 0x7881E2457DD56A21ULL, 
            0x7FF7415B0CFAACA5ULL, 0x0711EC8A12517AFBULL, 0x8506A87960F8B7C2ULL, 0x9910497463C09DC8ULL, 
            0xA85AB78EFCB39BEFULL, 0xFB35D90BABC7E3E8ULL, 0x8FD16F77D6119EFDULL, 0xC91FB640F5570C8BULL
        },
        {
            0x874CA6B68C9FF61FULL, 0x38243965F263B8CFULL, 0x7914FA1FF945027EULL, 0x630BE36A8CB8F399ULL, 
            0x17415F917BED6EF5ULL, 0xB7E5CC2B78348729ULL, 0xABFE716B50EF3BE8ULL, 0x4BBB01371CB1887AULL, 
            0xE7D4D27F00ACDCF3ULL, 0x30E5908911B070C1ULL, 0xF0A87E70CE782283ULL, 0x4B5A2320EF7E5CD1ULL, 
            0x70A3626B705C979AULL, 0x2F75C28FF153FD8AULL, 0x1828F54239223A5DULL, 0x2175DF4E2CDAC118ULL, 
            0xF0D6A122710B53DEULL, 0xB4506EFB9FB10DD8ULL, 0xBA6DBBB6E95E4C2BULL, 0x9014CFBA4B5BB2E0ULL, 
            0xA9B6CDB863D23F33ULL, 0x17CDFE4BF1EB9A68ULL, 0x3B33014CF699F6E0ULL, 0x3B640B64D1A83E51ULL, 
            0x324A5906E1D92B85ULL, 0x5369F83E36E69E18ULL, 0xA9B84FBAD62CCFFBULL, 0x9167CDCC30D30CA0ULL, 
            0x548A2398FEFEC05DULL, 0x0931E5FDAF3C373BULL, 0x7F91044DD4552D5AULL, 0x27007221DB98DD5AULL
        }
    },
    {
        {
            0xD326CAA23FDF14CFULL, 0x4CCABAFF5A69A97FULL, 0x0FE13F660E3EC4D3ULL, 0xF0A836E36C9DB180ULL, 
            0x43C88E9370192C13ULL, 0x26C0B0AAC74259C4ULL, 0xD47C0990B42CD2F9ULL, 0x5CC8F1963B3CD0BCULL, 
            0x00ED08259A154350ULL, 0x2DA2798AFAE0AAD7ULL, 0x533E6D2C59765FE1ULL, 0x8703D2A089A5E984ULL, 
            0x95B7706139906070ULL, 0xAC57650DDC23A674ULL, 0xBCBE999F8D1C7AF7ULL, 0xABE789446710D724ULL, 
            0x639E3CE6055C4B7AULL, 0x28171C32A8E88F8CULL, 0x42FF4B699CC30983ULL, 0x30A58B5DEF6E6755ULL, 
            0xEC8625E2C4030C0FULL, 0x50F5E13B049B7A7FULL, 0xB9CB8EE26761023AULL, 0xE7B79EAE3F93E549ULL, 
            0xD97D53EFD1941019ULL, 0xF8B6E343F4026FBDULL, 0x0B0FEEECC1C4FEBDULL, 0x554E784FFA6CE7FDULL, 
            0x8C5E143DE0B8AADAULL, 0x36384F75AEB5B058ULL, 0xE1C461234E395888ULL, 0x3B89457B8F829852ULL
        },
        {
            0xC25B056CA9018A84ULL, 0xF3FA755E6E311DF0ULL, 0x675FA91540A7F172ULL, 0x283CD69C6D19675CULL, 
            0x3B25866907B3A4BFULL, 0x7A74E4119C19D09BULL, 0x563AB213D603F77DULL, 0x85DA71CE45977A62ULL, 
            0x2E4603CB104944A3ULL, 0xAC0FD58AD75D1A55ULL, 0x41E84A8D83F9BFB6ULL, 0x5563542843630230ULL, 
            0x74C0912592085FA3ULL, 0xE156E3688249B89BULL, 0x73C0FF2DB4AFE0CEULL, 0xD7920F810CD72978ULL, 
            0xBA20359C23B34ECCULL, 0xE51EC5677FF13A23ULL, 0x6A811E0376761350ULL, 0x5DC41823BD392558ULL, 
            0xC823825CEB162439ULL, 0xB5E345547D2EEE3AULL, 0x934B7A3A651D82A4ULL, 0xAFE5566EF3E6E241ULL, 
            0x9AF055C1A02D1F07ULL, 0x3F56E2A09D4D2282ULL, 0x391D0EC82164A220ULL, 0x7F80760613FD3311ULL, 
            0x6A54D0EACDA65A08ULL, 0x8F436AA1670FBC91ULL, 0xFF582AA48B1D7209ULL, 0xAAD8EDC4E48EF639ULL
        },
        {
            0x3C018B0EFC4F2FBEULL, 0xCA03FE5528E487EDULL, 0x882B0921968F3F3FULL, 0x06382FFC96BE4BF2ULL, 
            0xC77A367A313603E1ULL, 0xC8F55EBDF491207CULL, 0x1D6EDE877778DCBEULL, 0x495F1C52ACE3DC05ULL, 
            0x39D6D67C70C38E07ULL, 0x33BBDC5ABF2DC48EULL, 0x2A9F328EC41343A6ULL, 0x1DC12C9453EF5DE2ULL, 
            0xA69CDF504C028046ULL, 0xDFCF5AB032681A99ULL, 0xB10265963E71F36AULL, 0x3EB9CC8802CF3B92ULL, 
            0x4C4F197F162BD3D0ULL, 0xADC54229004BA9F8ULL, 0x9966E1EA319F8F1CULL, 0x2007BE6CA3CC6A50ULL, 
            0xC90F508482B895D8ULL, 0x2E22CEEC30464F12ULL, 0x5250CC635EA2890CULL, 0xD0A7A6DF1EBA2837ULL, 
            0x78D26BA588972425ULL, 0xD383FB62B4DC2750ULL, 0x3E68D34BAF490D61ULL, 0xA7C3901BE464B8A7ULL, 
            0x5EB6D51F407EECA9ULL, 0x97C6B9F6E5B44465ULL, 0x228F44451D5E3732ULL, 0xB65D01B87AAB4B36ULL
        },
        {
            0xADCA3AF33DEE1C71ULL, 0x27ED4DE215737E08ULL, 0x0107FE4750DAB23EULL, 0x6D2B2D72F41C382AULL, 
            0x2D9FBB8CCC1B62D8ULL, 0x3ED2BAB2C447063EULL, 0xA3B349A4AB4EB940ULL, 0x72C7AC46F252F9DCULL, 
            0x6F85D883D1F4400EULL, 0x9552C4784B563900ULL, 0xEE2F3D2F37865FDDULL, 0xFD29E1CA4FF9451BULL, 
            0x31E1558A882E971CULL, 0x2DE9EC06A4386A14ULL, 0x713AA6C9038E59DBULL, 0x2FFE135F213C41E8ULL, 
            0xBF1A4704366B498CULL, 0x415D969A2C68528FULL, 0x8F620D56257CAF1DULL, 0x2D434DDD437F29AFULL, 
            0x6358FF8F6E54DA7FULL, 0x3FC5E1C83CCAEA96ULL, 0x450FD074FFDAE426ULL, 0xF4BFDF4C76A2CE24ULL, 
            0xEEBA06D41AAAE43FULL, 0x7CEC636F773A7949ULL, 0x86B302BBD612CFA4ULL, 0x1CF0B4718356505FULL, 
            0x7E4FC2E44529B23AULL, 0xC257E6788E42A9F4ULL, 0x312DFF8DD9BF1321ULL, 0xEB417BA1BB86EFC1ULL
        },
        {
            0x2E663D57C950933FULL, 0xB4A10A0E80E2BA5CULL, 0x22C104FB63E6E91AULL, 0x790537F37994EAF7ULL, 
            0x7215341AF9057A2CULL, 0x9C633927D07968CAULL, 0x89A028EFA232FF6DULL, 0x305135CAFCF782EEULL, 
            0xB03B60D2F4597527ULL, 0x9F3226DD8E9C9805ULL, 0xFC825402E767B0A0ULL, 0x4AB193AED9404094ULL, 
            0xD682A47F6430576FULL, 0xDBC1DE200D3A56E8ULL, 0xE4429B68CD82CBE9ULL, 0xFD6966595E705D16ULL, 
            0x7C75FCA2EC77629BULL, 0x28D5F3C6D1257AE4ULL, 0x9239B57765CCF0DDULL, 0x98933DDB50D954F8ULL, 
            0x6FAE3F4C03CF7448ULL, 0xE58375D983C3440EULL, 0x7E468348B4A77172ULL, 0x189B18CBDEA92B44ULL, 
            0x4C1CACFF39DBF254ULL, 0x6DEA5F29C5CB7A61ULL, 0x21ACFDE12C47C746ULL, 0xAE213B49115FD22DULL, 
            0xE739142D7AEDF4D2ULL, 0x83303C49B5CE8720ULL, 0x4A88038C97B32269ULL, 0x6238DA7DF1B00FDFULL
        },
        {
            0x0CA6200D93E76DECULL, 0x604B882773A78BE3ULL, 0x3BA31BA7D48851D0ULL, 0x1233D3629AD260BBULL, 
            0x294ECD2E3B583AADULL, 0x55173F54828E7E48ULL, 0xC75A1D5438E956D5ULL, 0xECDD36DED85200CEULL, 
            0x433EF07C3F303E27ULL, 0x0F70563E5147D47FULL, 0xC569840CAD57CAE9ULL, 0xBD7DFCAD922F8F4DULL, 
            0xA15F3EC5CB4C864FULL, 0x37BAE49A23880056ULL, 0x969FB4D7BD1A3308ULL, 0xAEF52D15ABF76CF4ULL, 
            0xC86A966651D400C8ULL, 0xCBCA08B72A8C4C6AULL, 0x3F0E11C5B555F4A8ULL, 0x7FE5CD221F23F3F3ULL, 
            0x680113A5E46CBA3DULL, 0xD47CB17780EFDABCULL, 0xE80339F4F672E336ULL, 0x001E55716E9AE58BULL, 
            0x3E79EDE6F5852519ULL, 0x1239BE35D111D3B4ULL, 0x0B22640EC62A7A83ULL, 0x88604F5C9A25DA82ULL, 
            0x6E67EE3E9F13C5FBULL, 0xF8DA7D86A3215F31ULL, 0xF0E8A04C6CCFB0BBULL, 0xC3DAC3BFD53FED9AULL
        }
    },
    {
        {
            0x107974ED8A83F9EAULL, 0x3E7CFF3A18C7C06FULL, 0xF7E043A263402E0CULL, 0x14E8030DADE5B09AULL, 
            0x4F820C59999B97B4ULL, 0x56924BD06A6A78E8ULL, 0xCA76C0B89F346C3AULL, 0x4C0CF117AED95263ULL, 
            0x7F160CB548D3DD54ULL, 0x0A05258E47C587C0ULL, 0xB15AF3EB9387F0FCULL, 0x03F477F4C75F976BULL, 
            0x5C2277240A12F194ULL, 0xA669628C7201E111ULL, 0x3D86A3E9DB2CFB69ULL, 0x4275915E1D9FDD61ULL, 
            0x1DA20D4CDE45BC05ULL, 0x5999213EEF6F3C58ULL, 0x6722B2C2EAD062C1ULL, 0x128319FB098A2580ULL, 
            0xCDF3E16366B4D030ULL, 0xA361322A2EBD342DULL, 0x620C3DD68AF7F2BCULL, 0x2094F7D181E3C8B4ULL, 
            0xAC0FFC8C28D84453ULL, 0xEB177984C4B5766FULL, 0x092E785B0BAC905DULL, 0xEC8F5B40A9C66819ULL, 
            0x87B4F63A3BD32FB3ULL, 0xAF4CB803FF385BCDULL, 0x92F37A53B510DBD7ULL, 0x70BD75042548F2A6ULL
        },
        {
            0x3C0DE253EAD3083AULL, 0x5B1D9A2BB687FF77ULL, 0x5FACB406DA5AA4E6ULL, 0xC959DFDED4EFA6FBULL, 
            0x3F0E6AE439A556FDULL, 0x48BDE651AA614B24ULL, 0x7A9F81B571734C76ULL, 0x04CE38D5A33CA6AFULL, 
            0x5005F8317E210E40ULL, 0x04F6F9A4E7267B4EULL, 0xD7C88675EB8A44F4ULL, 0x31FA4DBBA7FFDD74ULL, 
            0xA934809A9106BE5EULL, 0x4CDEF1207F3C8B52ULL, 0x018532E5A3BC4A9AULL, 0x930A4010D756C784ULL, 
            0x8503B290CBF844F2ULL, 0x477AC460E8880685ULL, 0x8D61153DD1E2AD60ULL, 0xE3512458615C33AEULL, 
            0xC951839205201FA7ULL, 0xBC116BFBFEE2B3E9ULL, 0x33BF15BC7AE853F7ULL, 0x1CCDEA1F04D22BDAULL, 
            0x9A20E1DA05087534ULL, 0x34262AA8624F80F0ULL, 0x3FDA30FEED98172FULL, 0x0DD461043B34A1F5ULL, 
            0x1EE8BD8F2C85D474ULL, 0xBF9A291B39A3D055ULL, 0x688E0B83A47ED512ULL, 0x43CD9417907483DFULL
        },
        {
            0xA429ED75EE79DFA8ULL, 0xD4D343ADF6A5B788ULL, 0xDB5E2ABC0060416BULL, 0x8A5FC996508F9799ULL, 
            0x2C99DD2A0528F380ULL, 0x88BD4D7B3B745B10ULL, 0xE8163C2414022F24ULL, 0x97EF6875489F768EULL, 
            0xF8688B0024D773B7ULL, 0x0ED7E6564361F835ULL, 0x333A4599DFFB71EEULL, 0x85FF207A20C0E02FULL, 
            0xEC8CF47299A36602ULL, 0xD65A982885A83461ULL, 0x5CCEA6D259872697ULL, 0x6BB5F00C8793A5B7ULL, 
            0x0A4119DEACE65A5DULL, 0xF0FB900328FFCA6BULL, 0x8FEBC1477050D6D0ULL, 0x22CC41F8BEB0471EULL, 
            0x53A141720E24A2E7ULL, 0xFF2C85B408C7C48BULL, 0x1C0F88C04B26C03CULL, 0xD93F2E2E24A9660EULL, 
            0x1A2EC9588C2EF34BULL, 0x33AD3FA2A456709EULL, 0xA3951BB6DA67481AULL, 0xC8CA877FCD20E7F7ULL, 
            0xE7B1F9F9DBEEA824ULL, 0x59325860956EDCE6ULL, 0xC5D561CB71A55116ULL, 0x3239493C84E1C06EULL
        },
        {
            0xC6881A38805C74D3ULL, 0x522DDD017AE617D1ULL, 0xBE48EA640D261BFEULL, 0xFCBBF7CC5179F8F8ULL, 
            0x3765283AE85BBC05ULL, 0x6063F5F480FB6F14ULL, 0xE086713053A9B778ULL, 0xEDB23727A5627632ULL, 
            0x2F4629C2F2D29B3CULL, 0x195F72730CE7DBADULL, 0x1CCFC310B688A45AULL, 0x3D42A165C9AAC3E9ULL, 
            0x6822E4615232C925ULL, 0x78201D1954C486DBULL, 0x5559FE8B84056E6CULL, 0xB13AB4119B4A8EA3ULL, 
            0x1F20F3A4E626AD9EULL, 0xAA6AA98091CE3D6CULL, 0x45E7F05076AFF1BFULL, 0x08D04D0A031E996DULL, 
            0x637A54A5DCF17475ULL, 0x83E17670F6020D86ULL, 0x7AF42856458F9375ULL, 0xA0BC56938CC4E99FULL, 
            0xFCE0F5A9565226EAULL, 0x83D6BA9E50C890F0ULL, 0x2A107680F86738E4ULL, 0x706D7BE9BCC11C49ULL, 
            0x4CEB1F3244B32BF4ULL, 0x1CB9473CB8529A08ULL, 0x1462FFAEF7859DB1ULL, 0xF6B87A5E26C5DCBEULL
        },
        {
            0x7D1BC9E37C747416ULL, 0x5D4366723722BA49ULL, 0xC360BEB5600B887CULL, 0xB2D04FCECFBA8F14ULL, 
            0xC24DB4BDEFE9428DULL, 0x4E5F237BC73AD507ULL, 0x4B4B7F9A786740D6ULL, 0xC9694BC84D67D64DULL, 
            0x751CCA06982FA3F5ULL, 0xFC987F0A1E881EB6ULL, 0x1A7216C074550BF9ULL, 0xDBE82700E72B1AFBULL, 
            0xB19FDD6F89ED67B2ULL, 0xD3274F44F0951CA0ULL, 0x5DB0804CC564DF39ULL, 0xCEA878C10F00A8B1ULL, 
            0x7A26C9728D7F850FULL, 0xA82871205C0BF07AULL, 0x46EC448365D2E8F7ULL, 0xC42583F5B6029A33ULL, 
            0xDADB61D2ADCF3126ULL, 0x55C3FCF85710F066ULL, 0xC2013AE97B9DFD53ULL, 0x9E38D58348D696C9ULL, 
            0xD529FD044FA2A9CDULL, 0x876376A5A04EAF00ULL, 0xCCDA3D69BB8F2789ULL, 0x96D47623E99683AEULL, 
            0x45D3680E4E7D9D4DULL, 0x5F9AF135191524F1ULL, 0x7CD39FD53C9E96BAULL, 0xD5341B1E2FF9FE36ULL
        },
        {
            0xFA73D3350BA23DDAULL, 0x45C48034C5147059ULL, 0xE60F3DBD6A1C78C0ULL, 0x66AF5CDF1FFC8B69ULL, 
            0xB1BD0A0D6FDCAC69ULL, 0xD024CE1373E53048ULL, 0x7767D86F211C43CAULL, 0x2EBECCCEB18949DEULL, 
            0xF75584D656B8A87FULL, 0x96EDB41A11306638ULL, 0xF01A69E7F236FA0FULL, 0x49C9FDD3858FCC9FULL, 
            0x94EEEE38C31F22F4ULL, 0x33EB8947D5DE551FULL, 0xFC2CA1130DAC87DBULL, 0xD2D41B9A65994C2DULL, 
            0x6EC5A5260D8C6093ULL, 0xF12811FB94DF166BULL, 0xF32735F5466A799EULL, 0xDE6D2623A4B6641DULL, 
            0x9C7A0A6A143696CCULL, 0x677B8902C7098C02ULL, 0xC3F52C78C467E4E1ULL, 0xFC7871327DD6A8BAULL, 
            0x1695FC3FA6641AC7ULL, 0xBA92398B96718E58ULL, 0x40D01C9D5951542DULL, 0x4366D758AFA94459ULL, 
            0x3C19D8CA3668D13CULL, 0x32EFF9B13B4B239EULL, 0x8F8CE037826ECC73ULL, 0x5BEB68A09244CFC9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseAConstants = {
    0x2AD51FD32234A26EULL,
    0xB53BBA965E74020FULL,
    0x9AD2D8CC52A69EEAULL,
    0x2AD51FD32234A26EULL,
    0xB53BBA965E74020FULL,
    0x9AD2D8CC52A69EEAULL,
    0xF5ED59D7E8272863ULL,
    0xC6B32EA0C3632642ULL,
    0xC6,
    0xA1,
    0x4D,
    0xEF,
    0x45,
    0xBC,
    0xC2,
    0xE0
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseBSalts = {
    {
        {
            0x3A2BDD185CD02C25ULL, 0x4A4532DF58BFD2E1ULL, 0xCD08823AB9A737B2ULL, 0x124B81680AD93CCEULL, 
            0x5D5F7EDB28B4BE78ULL, 0xF9D1044701949EC5ULL, 0x0FE8D4C382BDEF8DULL, 0x95A84C2FB5E74E27ULL, 
            0xAE55B5870BDB7E62ULL, 0x9F996580D97B1985ULL, 0x72E8712D1F35DBA9ULL, 0x2807569A077854EFULL, 
            0xE7A27F01BA527EC1ULL, 0xE7361CD024F1E863ULL, 0xBC413B0E5BD5CAD5ULL, 0xB86144C3AD5E7A83ULL, 
            0xA5C9ED88E07B4D92ULL, 0x3ED8368992D750FCULL, 0xF00C3E53601BA584ULL, 0x4215476DDEB3A21FULL, 
            0xBC23A097F86B1EAAULL, 0x3C92E8EB6163DB40ULL, 0x1645A59C1BCA1944ULL, 0xBB86C0AA96EA890DULL, 
            0xEB283CB2FF74DEF6ULL, 0xB424EBB266BEBF50ULL, 0x15EB1364DE2BAF33ULL, 0xF53D077C3C62E502ULL, 
            0xCDD823D2C490E759ULL, 0xEDE1E85918B1A8E5ULL, 0xF28D88B558C84BFDULL, 0x57FCE1A71268BAC3ULL
        },
        {
            0xBFF7AA5CEA1F2A5EULL, 0x6857CAA66303D851ULL, 0xD6536AF854BA97C1ULL, 0xF810A8838849A117ULL, 
            0x513415E5DA78AAD6ULL, 0x3E26830182A2D5E6ULL, 0x88FBD9F4651CF781ULL, 0x7626190E914981D9ULL, 
            0xB1BD370656C60576ULL, 0x0A7A10D7240EDBF0ULL, 0x0212E3D730AC4C2CULL, 0x41455B0E5519C878ULL, 
            0xB329431BAB6D65C2ULL, 0xA2C0DF1AF1050165ULL, 0xFDBDDCE6771D4976ULL, 0x044B02D9BA9F71A5ULL, 
            0x89E3858AEEA24B3AULL, 0xB07A07707085A5B0ULL, 0x191D2DBE67982686ULL, 0xC7C278AB740721E2ULL, 
            0xC2BE189D9CE67A3AULL, 0x216EE7B6EAF5AC9BULL, 0x1F67E923993B8FFDULL, 0x30EEB3FF292CF984ULL, 
            0x14CFF537032570BFULL, 0x0744655A22CD4FF6ULL, 0x84B43A89C8CA8B13ULL, 0x15C7F1223D75AE77ULL, 
            0x19FB4BA6B2E5153AULL, 0x0866B4C51FD9F611ULL, 0xD230ADB87D3154B4ULL, 0x6E47C0336F4AE026ULL
        },
        {
            0xAC66EE753C307C3FULL, 0xEDB8623F11FBD3A8ULL, 0x2771E013524FFFA5ULL, 0xB86B5B029F6B750DULL, 
            0x3F6862306EEDECC6ULL, 0x197AC94DE39D7CDFULL, 0xBB799EE729C56EDDULL, 0x3AE6DFAB0D0882F2ULL, 
            0x78E4F5F5621B3216ULL, 0x265594952C477274ULL, 0x1817D3055624A55DULL, 0x22AB3E42872F6185ULL, 
            0x290B0A799C35DFE8ULL, 0xA977C0658A7B5158ULL, 0x2829B244BCB1F678ULL, 0xEC9DA4C225889664ULL, 
            0x091EFA00352DF2DEULL, 0x7AA02E469AC6EDEDULL, 0x1E9AA3B6CBFF28E5ULL, 0x6F43BE35805EFEFBULL, 
            0x29103F522030DF3EULL, 0x363CE9DDC76CA4D9ULL, 0x39F27D6297E07C43ULL, 0xB9CA983582594732ULL, 
            0xCE8E6B882E663EB9ULL, 0xCD59FE9FCFD39455ULL, 0x50E5C764CC01D58DULL, 0xEA2AD3D7DA5B6E62ULL, 
            0xD722F6DE0C2BA660ULL, 0x0CF7A06D808FD3FCULL, 0x8F6BDC78BCA88D11ULL, 0x13D1D894A38A18E5ULL
        },
        {
            0xB9658E85933745A9ULL, 0xC0DEFAAB097EC5EDULL, 0xE2E17A638736B468ULL, 0x615E0014E69063C0ULL, 
            0x36058B2D5C1F37DEULL, 0x98B4F557F0FBBDB1ULL, 0xCFB6A244BD438C00ULL, 0xEB8D414DB71376A3ULL, 
            0x293FF55B28C0A327ULL, 0x4BD0F8128331DD6BULL, 0x3E5DD0A47D7EBB35ULL, 0x034E99B3140D9E23ULL, 
            0x08BABB4A0787B288ULL, 0x04E8683758303C23ULL, 0x072A1BB8EA3A8058ULL, 0x95463F4C00D7FBBDULL, 
            0x84F67B9DD21A6BFCULL, 0x69EC2E0D4F5F6507ULL, 0xA8022082CDB1B806ULL, 0xEC7D87ED3BAFD494ULL, 
            0xA3165A139AD08862ULL, 0xA2760C3DED384B4DULL, 0x67E632A02A6FB62AULL, 0xE613AAF231EE44B4ULL, 
            0x5D1E7C8E2B1D6AB1ULL, 0x38C36D814397FF8DULL, 0x582394BA5E0C2BDBULL, 0xAEEA563CB23D0305ULL, 
            0x4FBC20B0145212E5ULL, 0x4E99371B11CEE839ULL, 0x2E5C1F0EDD3ECE00ULL, 0xEB8E0ACEDBE5DD22ULL
        },
        {
            0x3660587C701970ECULL, 0x22BA6619C8665393ULL, 0x6739CC7AD1ED6AC5ULL, 0x649C3B7D493D028DULL, 
            0x2F91CF522FCF414FULL, 0x03E607C32FE494ECULL, 0x2116B48C41A2E182ULL, 0x3050912E14446311ULL, 
            0xDA5489E23068AD62ULL, 0xE91926523153C388ULL, 0x5FFA853F6DB576B3ULL, 0x1FB5EBD320C66E10ULL, 
            0xA9626EF9E297C319ULL, 0x49D77E7CB79453F5ULL, 0x618FA752F2437CAAULL, 0x35A3B8C27E340357ULL, 
            0x4BCAFDF3F9E341F6ULL, 0x8EF5370492B737C2ULL, 0x5E80F6A28968AC7CULL, 0x4FD24EAAADCA8B80ULL, 
            0xA9C1979A96EF4F2FULL, 0x9B8D88A14658EE1AULL, 0xCC81BB3D4B8971ACULL, 0x1133FB2071C17DD9ULL, 
            0x9753F33E878E1065ULL, 0x8D33E6A2AE1A3DEAULL, 0x4E8AA1B19D629AD3ULL, 0x358DB6166FFD190CULL, 
            0x88E8B7829B50C8B4ULL, 0x40FB4E7CFF26DC52ULL, 0x4878DABED51498BFULL, 0xABCB2205F58CDDD5ULL
        },
        {
            0x75142D029DFD2C07ULL, 0xBC888E2326D1D347ULL, 0x8EB179DFCEE56992ULL, 0x9F7EE23E99A8B87DULL, 
            0x6FB3951FA50A1B03ULL, 0x6488F3556DB14B78ULL, 0xDB7776DA355493E4ULL, 0x5CF65965B513A9FEULL, 
            0xDB26483E2DB25611ULL, 0x216CFC2B1C919F86ULL, 0x9D5E5DFDD08EC41FULL, 0xC356468C88FE05C2ULL, 
            0x9ECD6D6F31C39857ULL, 0x06F6E18EC1B79E17ULL, 0xEC5C1B737396FB13ULL, 0x9DEC3AFFC9E9A45FULL, 
            0xCB87A24CE6447E97ULL, 0x78BBCE29E9677587ULL, 0x40D29AF4349B9F14ULL, 0x5114F17751A42D5BULL, 
            0x247B6A18BD7C31FEULL, 0x67615E4A3611854CULL, 0xFD2A77C3FAC6B88FULL, 0xA6FEB05D4DBEB08AULL, 
            0x7ED338A376798ADAULL, 0xC0C9D273E982F466ULL, 0x1FFECC91DE118F35ULL, 0x6974D7AEAA388467ULL, 
            0xA8BDD8C3342C123DULL, 0x375BEE532F46346AULL, 0x8EA31E91ADA97A0EULL, 0xF2BB62AE3820F53CULL
        }
    },
    {
        {
            0x78ECFB8559A20645ULL, 0xA5F0B49185EB3C9AULL, 0x1E81B0B3770685FAULL, 0x8622D24584F9CE63ULL, 
            0x2B9ACF79F75FBB81ULL, 0x70FB16515FB40A6FULL, 0x623D1122E63AED0CULL, 0x572EED4B356869BDULL, 
            0x64752D9E47742311ULL, 0x15805A1FCC288BEDULL, 0x3BB789CD6318843AULL, 0x7F37674CFF14524DULL, 
            0x8739F9E2CDFA2677ULL, 0xEA65C6DC964DA1A9ULL, 0xE5225B886700D871ULL, 0xD45B2A44F0C60DF7ULL, 
            0xC586C2B614B2EF4FULL, 0xB2DBBD3B69903839ULL, 0x20E2E0BF8CB3ED45ULL, 0xB586BD61F37FE71EULL, 
            0x75796AD8827584DBULL, 0xDF01290BFDF02A97ULL, 0x08AA301FD07B511BULL, 0xC5D3BB25D6253098ULL, 
            0x64F3DD94F1298214ULL, 0xF425D18FC15F278EULL, 0x10274CE562991FEDULL, 0xE912D043F9059ED5ULL, 
            0xF3A0B93A565183E2ULL, 0x717D46FBF1A06CCEULL, 0x120729E0C2636E60ULL, 0x4AE565806EBA6E68ULL
        },
        {
            0xD97F8301E28D89ACULL, 0x3DDCD02A1B1699EDULL, 0x4A9B70BE5373999DULL, 0xECBC7FC174ACE10EULL, 
            0xA468A55E3E35D83CULL, 0xEBB89FF499356E56ULL, 0x34E3868857861F77ULL, 0xE6FE0CB061454396ULL, 
            0x466417C7702E4D65ULL, 0x074D034AC2D6E7D3ULL, 0xF9FFF5756C8A15C5ULL, 0xB2CDBFD753298C95ULL, 
            0x9B782D16E7E959FAULL, 0xE9E3C7262BD996F6ULL, 0xF0BB1101AD8411C2ULL, 0xD5ED2C366A9C42F9ULL, 
            0x09A676B6745DDEA0ULL, 0x48F08D2A05496A25ULL, 0xFA9975DC031144C0ULL, 0xB02DA740935EF914ULL, 
            0x9C14D03E74FE8873ULL, 0x8DD58973DA7E4ECBULL, 0x83E8017CF742A975ULL, 0xAB49FB39F2716B8DULL, 
            0xA718301C18869E39ULL, 0xD32FAB1D62CB3290ULL, 0xFEDF8EC5E2CD3EE8ULL, 0x76D553BD53B7F614ULL, 
            0xB03C4128E5C9FAC8ULL, 0x04F59EA604ADA781ULL, 0x56D379B403A1238DULL, 0x9C11188A05337F81ULL
        },
        {
            0x06CC353710B1ABDBULL, 0xC80BB29856439A77ULL, 0xF1D74633FE06F49FULL, 0x5FDCABEE8978DE65ULL, 
            0x6B60D35C8499DAFEULL, 0x3BE05729523572DEULL, 0xEB9EC568F2A10494ULL, 0x32D53029BDA0EB9AULL, 
            0x4A28CF230DF91993ULL, 0xFB77EAF0DDEC2AE2ULL, 0x486327DCCA88AB14ULL, 0xCC97654AA606001CULL, 
            0xE2DD4BE73C937ADEULL, 0xA5158F1F5730D4EAULL, 0x331296D14E1ED09CULL, 0xCB8AB43A0EEE8491ULL, 
            0xDED0E2AA5ECCE89FULL, 0xAE8EC4F986FCB83DULL, 0x50C24E4E07A5933DULL, 0xDBDD5D92E2FC19F7ULL, 
            0x1BBFDE819E0CD33BULL, 0x62F6234E656667CAULL, 0x5E8E0A54FDAE0362ULL, 0x502F900B518172FDULL, 
            0x2874B207248FCC2AULL, 0x8D335EFFE78DC350ULL, 0x78B41D7CE07D29DCULL, 0xE0C06E5744BE6E5DULL, 
            0x9B296E63261CF44DULL, 0xCDA82F2C8D15C504ULL, 0x7E0D09630542BC55ULL, 0xB517B83F5809EDDAULL
        },
        {
            0x27BFA0D916093CD3ULL, 0xC17CA882E36960B6ULL, 0x6F3A96833F0E0321ULL, 0x1EBEAC27A13066E0ULL, 
            0x5C739C16268BD171ULL, 0x6DDC804C2706970BULL, 0xDE34AA90A86F459DULL, 0xDB7460545145DA97ULL, 
            0xE789E4934553D181ULL, 0x5509BC5421D3F6E1ULL, 0x468169C03DFED6DDULL, 0x279BB2F6CE34AD15ULL, 
            0xF39EF5E4D59FA9E7ULL, 0xE5868258FA1B761FULL, 0x32A028E57A840763ULL, 0xB6BE6A7A26DA3DA2ULL, 
            0x184F98451302C9F8ULL, 0xE03AB4BCE91AF6E5ULL, 0x1789D647892B459EULL, 0x340613B070177BFBULL, 
            0xDC9FEA131211BA51ULL, 0x5A890148B222C349ULL, 0x7F5100194CE38EE4ULL, 0x00B06257BD43EAF9ULL, 
            0xF8C3021C6CF4502EULL, 0x3FB8F192677AA299ULL, 0xD086EA29DD441046ULL, 0xA6AAD27197E7B85BULL, 
            0x59C43E0528D59988ULL, 0x1E6253A178EB9839ULL, 0x0E17F47CDB0EF061ULL, 0xC66F89CF700E679AULL
        },
        {
            0x95113928C25FD6E8ULL, 0xCF76C86BCD006482ULL, 0x7B7BC2EC8A306DCBULL, 0x84DC4D2A18694B2AULL, 
            0x5181986B39E70B2AULL, 0x3124982CC5AED504ULL, 0x14E634E89C8D23CAULL, 0x68512B0340365375ULL, 
            0x126EFD241D03BC49ULL, 0xCC6D89C003F42D1EULL, 0xD3683B8E8C2C0F04ULL, 0x30DD16E52388313DULL, 
            0x6B4E725848A8A16AULL, 0xBDD096A34E5CF837ULL, 0x997615F092E7A630ULL, 0x30134D58D8AA200AULL, 
            0x0718B27B937EFE9EULL, 0x35BF11CB8E4FC641ULL, 0x3EE4AB9792CCCD68ULL, 0x104CE8AC6462C476ULL, 
            0x7B6B26FC7F5C364CULL, 0xECFFC0D8C82B6EA0ULL, 0xD13049E1C2398E00ULL, 0x13CEDD99A68AB256ULL, 
            0x5258A2CF70124304ULL, 0x66E3F9112997694AULL, 0xA19DA551320477B5ULL, 0x7402CCFD59AD4EF5ULL, 
            0xD04F96D13F67A072ULL, 0x393605E5C0B483A6ULL, 0x6C09A8034621EF80ULL, 0x891A912AD2F7CA2EULL
        },
        {
            0xFF693841A390F6E0ULL, 0x71B917322E171398ULL, 0xA1E9FDFA06BD7488ULL, 0x9B817DC09772B398ULL, 
            0xE7067864E787C454ULL, 0x96C490503933CEE3ULL, 0x070FC66843EBD907ULL, 0x208060830439FEEAULL, 
            0xBC97DDBA572D1310ULL, 0xDAC40FF1C2D85501ULL, 0xAA286D68EF38E1F9ULL, 0x7E267C877643B5F9ULL, 
            0x19EA40EF3551BB4EULL, 0xB4FC5A4F1A8711F3ULL, 0x6D2DE7A0EE59C5ACULL, 0xD8B094773660348EULL, 
            0x7B9BDE0188E5977BULL, 0x3C4B64F6519B5507ULL, 0xD85334A81D280E13ULL, 0x41F1DC735ABB8CE6ULL, 
            0x54556B256CDF8FB1ULL, 0xB023BC4E7DDB2110ULL, 0xC405EECD56BD6F1EULL, 0x0598C0A7AE4ED993ULL, 
            0xED2D5BF5CCEC6292ULL, 0x19FB8003E49B283EULL, 0x3E554F8E09D7950EULL, 0x47F7485B5F0932B0ULL, 
            0x0734706B88C03D9DULL, 0x5432BB85D8CCA1C4ULL, 0xFC135EB0848AEB70ULL, 0x0C1570378533070BULL
        }
    },
    {
        {
            0xFBF85175A002CA51ULL, 0xBAF9BD614B1228E3ULL, 0x488118473757055BULL, 0x1AAB96E501B63F80ULL, 
            0xF45FAD65B76D86F8ULL, 0x4B620F7D8C9C1D37ULL, 0x9F7631CF35AF633CULL, 0xBEF2FFF6EF3D77F9ULL, 
            0xA6736F8F90CF0887ULL, 0xB15EE0E85715EC1CULL, 0x74F3510A974D70A7ULL, 0x8979EC6770F10C71ULL, 
            0xBFF241770AEEB1FAULL, 0x87E38CB861690395ULL, 0xCC18BF9492641BD9ULL, 0x01A7970B1A6E4068ULL, 
            0x5E542EBA9A7D32A6ULL, 0x477B0F3E6BFB38B1ULL, 0x9041E11603B47405ULL, 0xB4A2E220609D756DULL, 
            0x162BB5A174EDB6D8ULL, 0x41203D3F911FED9BULL, 0xD5A43FE0E98A455FULL, 0x8DA3DDA6764FF523ULL, 
            0xC7AA0040B4621B84ULL, 0xF18E5969F152A9BBULL, 0xEDB63827E9772CE7ULL, 0x4E7BEC6C6D3AA17CULL, 
            0x611888A198069D0FULL, 0xFE089C5409BB4A4CULL, 0x04B29E3B1B1BA0F0ULL, 0x0961FB7536C9BA30ULL
        },
        {
            0xA92A2BFA90420313ULL, 0x54ED4F8EE2D890A8ULL, 0x5E30FFEC502A4ABCULL, 0x33EA857DF5EA4175ULL, 
            0xD340EBC4B2091348ULL, 0x799953D7C1107811ULL, 0xA0CA9738E0B6B50AULL, 0x1F13C6A349721EEBULL, 
            0x696C5FF3E16B47F7ULL, 0x54869181DB6438CCULL, 0xBF4C87F9AAD24F09ULL, 0x429C7576B7110968ULL, 
            0x295CF3A85B0DCEF1ULL, 0x8A290561685467B7ULL, 0x5447B22B78E5F236ULL, 0x4AE5F0ECB73B8AE7ULL, 
            0xC79BED81E4C3A3FEULL, 0x0227727AEF481F47ULL, 0xFAE6F5F0939429E5ULL, 0x533025D3B8A209E7ULL, 
            0xB5C3B3AE9B7D208CULL, 0x076D655239AFDD30ULL, 0x2AFEA8604ECB3DEEULL, 0x53E56EE67A827DE4ULL, 
            0x0F17CAC52D267FD5ULL, 0xCD47D6EE6AE1FCCFULL, 0x27C60D28771FE6D7ULL, 0x5F96ED11176BD71CULL, 
            0x2C19700938A41F7FULL, 0xB6DA2320327844C1ULL, 0xE94D7D01DF33FDBFULL, 0xAFCCE6EEF7057BF3ULL
        },
        {
            0xAEB2B7C2331B87BBULL, 0x7559E05A7D67A9B2ULL, 0x15D66CE7492E4198ULL, 0x0F6A5076EC01A9ACULL, 
            0x491CDBA6FF64EB5AULL, 0xC83CB04E3590EDD0ULL, 0x8571690B1A0FF5C2ULL, 0x09E096596DBE52C3ULL, 
            0x4B121F2AC3E06969ULL, 0x72F8315277882FC4ULL, 0x8BA998A2FF3F4ACFULL, 0xE39180CDCDB73BCFULL, 
            0x59DBDDA13A5F50CFULL, 0x595A1F021D222ADBULL, 0xB6EB7915D8FB0726ULL, 0x615EB469948E3BC7ULL, 
            0x73DA0904882FAD3CULL, 0xAC1F4B669F3B5508ULL, 0x657D1934D3A987DCULL, 0xDD8400F787178D56ULL, 
            0xF8C84079BD68D454ULL, 0xF255776B4A7647E2ULL, 0x72B67C48A0B1A100ULL, 0x2D486D6C380ECF67ULL, 
            0x8154C74BFF7DEB8BULL, 0x6EAE6E1F19B16058ULL, 0x30CBF7721C08F44DULL, 0xA2D4E1B768E65D5EULL, 
            0x3C2E1FDDA4C0E2B5ULL, 0x75BD6C9DE44C6EBDULL, 0xD066549108F0B2EFULL, 0x5DD793EA27D90963ULL
        },
        {
            0x48DBC503A2990A58ULL, 0x69483A1227DB5D99ULL, 0x78F24A97A0FE9762ULL, 0xB2CADF9AD1FE7750ULL, 
            0x71B63544C421CCB7ULL, 0xEE55267668627706ULL, 0xB07CDD9491E293CAULL, 0x43B79CC31CC36955ULL, 
            0x914FFD72C4A58B8BULL, 0xBCB5BCD0CD0AFC52ULL, 0x6694D42E5BBF6DBDULL, 0x64CB7FC746F4135BULL, 
            0x114878B6B3B69248ULL, 0xC2B6418FEAA1EF52ULL, 0x89F1FD8BAA1F97ECULL, 0xE10A111B621DAAB6ULL, 
            0x8356B5EE259ECA19ULL, 0xD2D8D3C9D729ED6AULL, 0xDD49CF8695B97F34ULL, 0xA1FBC227F5DCA174ULL, 
            0x74B277F65A0A0679ULL, 0x333F45C4D798788AULL, 0xB4693968E6E77F6FULL, 0x6F725543E7FE9B19ULL, 
            0x439E14109B763575ULL, 0x88713D05E39CA8ACULL, 0x87BC0CE9DF25D827ULL, 0xB6C7E3D22700A4F6ULL, 
            0x2BD61CF783F2FE58ULL, 0x389DF67E39B7090CULL, 0xA8BE1B3348C45613ULL, 0x148918E705E69ED7ULL
        },
        {
            0x1091CBF98EC334F3ULL, 0x85AD48E196918278ULL, 0x7746147872E755A8ULL, 0xC870A50D9669810AULL, 
            0xA64A5DB7A3970954ULL, 0x314AF84D460E3159ULL, 0x114C399D5A9ECC51ULL, 0x65C2030B93B27AD9ULL, 
            0xB0E2507C6F088895ULL, 0xA11700D66AEC383BULL, 0xF2AD870C8770CBF1ULL, 0x378A6479C2EEB58AULL, 
            0x85029A09476EE683ULL, 0x56D02BE2892ED8B5ULL, 0x3472AD6F006CAD2AULL, 0x2D68BC197F6E283DULL, 
            0x29F4DEDB71CC46C4ULL, 0xCB6307BFE66F6A94ULL, 0xC0E8A087FC526D89ULL, 0x1D7D54EC276E4AD4ULL, 
            0x66F939C355DFEC80ULL, 0x9739AD34EA53B6EFULL, 0x3E2A3927FBEA5362ULL, 0x5ECA23F542809D2CULL, 
            0x55B11882829E1C67ULL, 0xD7EA98524ABBF5E0ULL, 0x9D186B123BF16EC4ULL, 0x4DDD7B0ADA1898D9ULL, 
            0x7E4B598E4BA455C9ULL, 0x92E110A304498001ULL, 0x808DDA73037609B3ULL, 0xD157E3FC12ED4F1FULL
        },
        {
            0x8B3D5C40F2CF336CULL, 0x8C1323E23F32D614ULL, 0x2390E0A95426BC60ULL, 0xB6295D60818CF74DULL, 
            0x4F456E904B53A955ULL, 0x8C32DF82F97E2ABCULL, 0xA7D7D20642EA0E7AULL, 0xF8A66B54B0EC436BULL, 
            0x64220219ACEEEEFDULL, 0xC73B9B651C4B58D3ULL, 0x6A4E7631F38C140DULL, 0x80E95720F99DBF52ULL, 
            0x5EB83C1EF56BE08CULL, 0xA3A9040F0B5AD4C0ULL, 0x8CA00E3BCF1FB83CULL, 0xCEEFBE2865244E70ULL, 
            0x6FC4A70ED1F1A403ULL, 0xE49D9643B46C125AULL, 0xF4A8009A66AB1F6AULL, 0x8F8D4840AD1B6D04ULL, 
            0xCF0FA3E51BDFDD01ULL, 0x1D65B9B03DB41133ULL, 0x0B60894D186B8BFDULL, 0xA7B28DD5350ED083ULL, 
            0xC6F0F6517FE60893ULL, 0xE3333883C6C62445ULL, 0x9946F5C1DF86A200ULL, 0xC5E29DD38678C9A1ULL, 
            0x8DAF20CAAF9589BAULL, 0x95EBCBF9D73D55B9ULL, 0xB2DF5EE56C1470CCULL, 0x6A461CDB33D354CBULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseBConstants = {
    0x22FEE83F71921082ULL,
    0x16A75CA0B22D2C3EULL,
    0x97506076A9A5AF40ULL,
    0x22FEE83F71921082ULL,
    0x16A75CA0B22D2C3EULL,
    0x97506076A9A5AF40ULL,
    0xE6947ED546345ACDULL,
    0x4BC2E55FC55AB3A5ULL,
    0x23,
    0x46,
    0xBF,
    0xC3,
    0x69,
    0xB4,
    0xA2,
    0x04
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseCSalts = {
    {
        {
            0xA4C796A4810FB0A6ULL, 0x78A53BA6FC2572F5ULL, 0xA77C785150E12776ULL, 0xC247440288E207C4ULL, 
            0x7BC82E265BC83659ULL, 0x0B8D6A9DC0E8472BULL, 0x7F7526254D64268EULL, 0x7F0D4C12D70A3556ULL, 
            0xA90E677D94E4B56DULL, 0xA6F18D72A3300889ULL, 0x708CEB71DA88FCFBULL, 0xC5DA7F33C368D092ULL, 
            0xE73355F83964C5F5ULL, 0xCFB64FD82F68A604ULL, 0x6C35B58D020A9430ULL, 0xF81E0972C913D5F4ULL, 
            0xB35D9E034C7E73A7ULL, 0x36F003A2DBC504B9ULL, 0x5DD8ACAE09C859C8ULL, 0xF7A28FF59F77F575ULL, 
            0x70D205CAFB5F1281ULL, 0xE0F605808523FBA1ULL, 0x3C494873511784A9ULL, 0x95489386D8DF9DFDULL, 
            0x56CD6F0677C04DBBULL, 0x2EDF33ECBF6FF328ULL, 0xE46174FB47858EA4ULL, 0x8A0D7F226262213FULL, 
            0x24D160C1A547993EULL, 0xF8C92EB50B0BECE9ULL, 0x9E3E28DD95679544ULL, 0xC2BE072EAC09D9AEULL
        },
        {
            0xD9102FB43506E49EULL, 0x626ACD16E17E2EA5ULL, 0xCF301A10BB98DB55ULL, 0x02BBF481D422AF7FULL, 
            0xE34CD0BE165FD4B1ULL, 0x0D1380F88F229653ULL, 0x7B2D380D2731294EULL, 0xEB24BF8E9B1AA6E9ULL, 
            0x1A7349BB96001588ULL, 0x9A7CD8E4D7654E9EULL, 0xE0B70ED809B38B86ULL, 0xA03B0A885A599725ULL, 
            0xB4CEC1FA96F42269ULL, 0xA7488307CD80B6BCULL, 0x08F3AC54C8EB3376ULL, 0x0B31A46D18C2AB99ULL, 
            0x7DB3E75A8C4462CCULL, 0xF70793879552C064ULL, 0x9A24DF09183F65D7ULL, 0x5AF783D7C8CDF1D9ULL, 
            0x695039CB94301DEEULL, 0x005C798DB9135E4AULL, 0x26AFF90529977BD8ULL, 0xA488067142F36FD4ULL, 
            0x89058C2179918826ULL, 0x26298DAC361CB427ULL, 0xE01AA249D1D7BD9AULL, 0x3111F984AC1B8575ULL, 
            0x137EEDEC75D6DBC9ULL, 0xA1E583EF40711013ULL, 0x4593A37CB248F04CULL, 0x6E778518CAAE01EFULL
        },
        {
            0x9384A5D3A77367FDULL, 0x2DE6E8F64A372A75ULL, 0x605D18FA1FE42143ULL, 0x483A445260824169ULL, 
            0xF8130AB16268DACCULL, 0xAC09577585754113ULL, 0xCC36DFF6749FDE6DULL, 0xEF88B2111BF61F8DULL, 
            0x19DB7DF878E2CF4DULL, 0x2142D7AAD2EF87CDULL, 0x897ACECDFA266A16ULL, 0xCB16526A8DEA1A16ULL, 
            0x09976E59AF560C73ULL, 0x449671D239F63261ULL, 0x81180C7A960272D4ULL, 0xA613B077C053DFE3ULL, 
            0x174C6CD072820068ULL, 0x4E894A0E3E58D075ULL, 0xB01EC93A29DDA5C8ULL, 0x8CC31FE5C79BD918ULL, 
            0xF567C58A3306146EULL, 0x8E02DCD0D04C96DEULL, 0x213DE7B493D4B01CULL, 0x21C49DCF759732E6ULL, 
            0x2B04B68174C04BC7ULL, 0x0AA3EAAB40F109CFULL, 0xC22933D3AAC78393ULL, 0x46ADADF527E32BDDULL, 
            0xB7F420EEB4B10421ULL, 0xC3C162AC06A93929ULL, 0x320F1582B3169619ULL, 0xAD3D03CE418DC01EULL
        },
        {
            0xDF9EC5DC6AA58BF0ULL, 0xD10A3366B3E746CAULL, 0xAE644AE0AFD69D4AULL, 0x9D21749745D87BCAULL, 
            0xAA7C7CE799AF23ADULL, 0x2A7993609A5B6825ULL, 0xC2655A34B6D77DAAULL, 0xEE095FDFBB4B790EULL, 
            0x63DBBFEB40855B51ULL, 0xDB65E23EE6AC8BE0ULL, 0x81E76C0567633F8EULL, 0x44A23934F09403B8ULL, 
            0xF65605B7FC44BCF6ULL, 0x94E2A5EF3F180CFEULL, 0x5AB07F0F36E35379ULL, 0x8F085D8AB9B61AD2ULL, 
            0x20A7B13E74D377C6ULL, 0x1E17C5F864BD7F46ULL, 0x66941AF35C83D3B6ULL, 0x9BFEDA86C4719AD1ULL, 
            0xDF00AA74010509BBULL, 0xBB0E4C5D9EE38521ULL, 0xB55E096C570D97E8ULL, 0x69DB67CE2457B772ULL, 
            0x35646A843A5E94BEULL, 0xC0803D279E3CE0A6ULL, 0xAED4294900F0D32BULL, 0x60F40677DB5D28D6ULL, 
            0x59B55D1D402C3043ULL, 0xFAD42730F4B9D811ULL, 0x205C9568F8A89618ULL, 0xCDA67B0DA0D80348ULL
        },
        {
            0xAA59EDFF1C415414ULL, 0x6B066261FF3991CBULL, 0xDBB9C707A8221143ULL, 0xFAF0E25228885A5DULL, 
            0x4EB0704211B7F677ULL, 0x9B50749779F0B68DULL, 0x58CBCDB539161A88ULL, 0x6A0E2C5971D600ECULL, 
            0x8A6519192B005B9AULL, 0xD3570C61534750E2ULL, 0x16B7484D5B37AA7EULL, 0x8D8353197E1C2461ULL, 
            0x52309FAAD307DD77ULL, 0x5F2EEA815CE8FD46ULL, 0xC40456A32FE5CAFCULL, 0x544858EB2EC73B24ULL, 
            0x8253356E6276EC31ULL, 0xB3648F8D73F560BDULL, 0xC27B66328933A32FULL, 0xCF41CA97DD9E038FULL, 
            0x2315E0D85AFEDE84ULL, 0x3088ABC6B9DB6EE8ULL, 0x35BF0A9ED98E1678ULL, 0x1D02AEDAADAB34CEULL, 
            0x0A1551116EEA452AULL, 0x10F89DBAEC67F811ULL, 0x9E1322FC08FE3672ULL, 0x923983AA7D3597B6ULL, 
            0x875BA5FB11298966ULL, 0x11C3AC40C425DB5DULL, 0x5526DC3FB7734A53ULL, 0xF49B16E49566DE07ULL
        },
        {
            0x14D7379A615AD7CDULL, 0xD0C3BC8DBAA8F21FULL, 0xF17CF04E5988D8F5ULL, 0xBC318EFFAC753CD8ULL, 
            0xC31E7975810DF0ECULL, 0x5876251AE0E07B26ULL, 0x6B83C34AE3024436ULL, 0xDF7D3BC443241DD8ULL, 
            0xCD4CC74B86CDA24DULL, 0x36B121000A9FEBFBULL, 0x95D1B63759C38CA8ULL, 0xE7D96002848DB26DULL, 
            0xD6C38C4C3587CD7DULL, 0x3E797AC56A8D05ABULL, 0xF18D1D8CBD232E20ULL, 0x37AEFF0F726DDEECULL, 
            0x620B021624897A56ULL, 0x1BCF32CDDCE6A8C1ULL, 0x2C6003F1C7C6496CULL, 0x27DFCBFA98FCA60BULL, 
            0xE09A0BA00D8603E6ULL, 0xFAD498FB2AFE8C82ULL, 0x1CD2C5B0B8FF1F45ULL, 0x924FF51DAB676762ULL, 
            0x670C2E9D9245F37FULL, 0x8EEDF0789A2D5249ULL, 0xE6458A08102C2F86ULL, 0x7838E489E04219BEULL, 
            0x7ADFBA13F6831676ULL, 0xB1F997D56A2A1A7EULL, 0x2BA0DBF07340056AULL, 0xE29987144D815D27ULL
        }
    },
    {
        {
            0x0371C4CC76BFD3F4ULL, 0xA8D3D4D428FB9FB2ULL, 0x9D094F8C0DDE85DFULL, 0xF7FC30E01923BF85ULL, 
            0x187463F5102E8A48ULL, 0x12AEDFDC72AEC5F2ULL, 0x526850EFAD4F0DEAULL, 0x0CFCA907C8B33FDFULL, 
            0x358717A0D87B4FF3ULL, 0x38E69F75224B4BFCULL, 0x77AB7190F432353BULL, 0x96F2D5729BC9ADF3ULL, 
            0xAA2087A80D98CA2EULL, 0xEBECD2FB82F7C942ULL, 0x8C2B98A8BDFDD1B9ULL, 0x29072C0853F4DC19ULL, 
            0xF94E880D024499D0ULL, 0x8AAACFB82E6B907FULL, 0xE37DD52CA7EBB61FULL, 0xCB94563D1BD96302ULL, 
            0x9AF5058FE3395F15ULL, 0x54457C82E13D3EF3ULL, 0xBA8136C896C5EB4AULL, 0xB710AF1E5AED6D80ULL, 
            0x63D558FD8F4F8170ULL, 0x4A62E1A03A4FF79DULL, 0x5D119BF8434D00F2ULL, 0x737B56DC10A67744ULL, 
            0x1A47231FCFDA2A83ULL, 0x1B7F25AE3AF86052ULL, 0x73A5E4A67BA1EC86ULL, 0x508A69EA070A2F7EULL
        },
        {
            0x49FB25E8F1386864ULL, 0x356EE1E4E64B17C3ULL, 0xDBD410B89CB52B2BULL, 0xA693F318BD8632E2ULL, 
            0x147E105744D6E661ULL, 0xCD11BC49FCC4547BULL, 0x6EDF099AEAB2CDECULL, 0x0A4D84971539A0E2ULL, 
            0xE4B38BD9865EDBA5ULL, 0xBE71B85AEB3F097FULL, 0x0B449028841ED1AFULL, 0xF5345C1D8AE42567ULL, 
            0xFDCA24960ED18510ULL, 0xAFC7F69B5A9F24BDULL, 0xDFD9DA00CF6AA1E3ULL, 0x1A452C631DED6C98ULL, 
            0x58FC63C3E691B78BULL, 0xB88886C035886A95ULL, 0xC125DC6CF7FCBC8CULL, 0x0E3EF9C7624B1315ULL, 
            0x0D04800358E901D9ULL, 0x38C2C46A754C2580ULL, 0x08C2DF5F54856CF4ULL, 0xA84BEF52AF127645ULL, 
            0x6850F5BF22E96F5AULL, 0x62F44B12F3A7FB4EULL, 0x4A6E5B45B14107E8ULL, 0x3A4932806FF50D41ULL, 
            0x0E77F5D5C113B424ULL, 0x4D8DD4AE6363FE23ULL, 0x0ED5FC723E521FBAULL, 0x8F21059D16025C05ULL
        },
        {
            0xFEE220CC2719B5FBULL, 0x3D1D5FDD85CAC5E9ULL, 0xBB1C72503BD9A075ULL, 0x7E11903B5771EDC6ULL, 
            0xB4AA759AB064B968ULL, 0x499B2C0A9A3F1B8AULL, 0x43EB9D71603956C1ULL, 0x2C126FCE2E145342ULL, 
            0x4C5D9F408498CAEDULL, 0xF492F2AACF14E4A1ULL, 0x3F6C0ADBB5475D55ULL, 0xA0595A6E2C1296E0ULL, 
            0x9FC102FC74A74368ULL, 0xC2529A54AE251198ULL, 0xF7777C669FF24B20ULL, 0xE72A56AFE13DAF05ULL, 
            0xFEE994E4190F86A1ULL, 0x4A61197ED1C1A4FFULL, 0xD6E3008C71D35C7BULL, 0x6753CDE015289BCCULL, 
            0x012D7C4B870D1A86ULL, 0xDCBA7B7C093D14ABULL, 0x2A005735E120AD74ULL, 0xBAB6A06114E95F62ULL, 
            0x0C1F2EAC48AA107FULL, 0xEF1DC35A6125BC13ULL, 0x0D497817D800427CULL, 0x36EFAA71BDFF7607ULL, 
            0x826FA3FCEF668581ULL, 0x6FABEA96676D80F2ULL, 0x44FDCEF1282D943CULL, 0xE54DD25FE25734E7ULL
        },
        {
            0x2B3610978B62A61EULL, 0x44B8A2A70DAE161EULL, 0xE8938B4A80955DEAULL, 0xC3E458FEB8F550DEULL, 
            0x70057AAECAD8E743ULL, 0x751E1E6F5018DCBCULL, 0xDF552E2F124D88BAULL, 0xA4FDE681AEF0462AULL, 
            0xB3ECAC7C6A6CD33DULL, 0x0850DD7F4FDEB37BULL, 0x213712C103F73384ULL, 0x044715997B516936ULL, 
            0x58DBF3638C9C785DULL, 0xDB19D7306BA986E8ULL, 0x3430A15DB3A7518BULL, 0x60558A51D856F2E3ULL, 
            0xFE20A95B9BB7E295ULL, 0xBEBCB8C2D3736CC6ULL, 0x32194B8C422166B3ULL, 0x7722659B09E9B25FULL, 
            0x9EDB924A6AD1628CULL, 0xEC223459610A5123ULL, 0x04EF9F413243C8B5ULL, 0x1F794E8477244746ULL, 
            0xE47040FB64B46EB3ULL, 0x61A9BABB8B12AEADULL, 0xE950DF36944EB077ULL, 0x2164351D0C59BDD1ULL, 
            0xE0AD08E54D2708D2ULL, 0xFDD513C359FFB148ULL, 0x516EFBBAB7E00356ULL, 0x9B4DEDB9FF78D4A6ULL
        },
        {
            0x8DB588CF7D882E09ULL, 0x134FB6B2D7085491ULL, 0xB96B4C8938B149DFULL, 0xBC2B5312FE835175ULL, 
            0xA3E15174B59572C5ULL, 0x57537FF27E204B95ULL, 0xF24CA605ED408FF1ULL, 0x562B7A9839B36E46ULL, 
            0x864EC566EAB9ACE6ULL, 0x21D8044EA7519A60ULL, 0xB46A3FB3B635B540ULL, 0x007FDDD8B943D51FULL, 
            0x5098226C32CDA75BULL, 0x6A191829F2421F4BULL, 0x6B22DD15B2290D8BULL, 0x40ED14F299EB95D6ULL, 
            0xEEB2323962394946ULL, 0x2DE6D068F1494184ULL, 0xD9064354CBE36C60ULL, 0xBA14BB8EF0C88B51ULL, 
            0xDCF6DD894BC885B5ULL, 0x1FAEA9A0457B8F94ULL, 0xE0680B98E8205D72ULL, 0x4FEB434DDDC8FE02ULL, 
            0xB6325D2855F8DDE3ULL, 0xF583E59B88AE3EBAULL, 0xB78161102BAE5699ULL, 0x38D7A7B435F88205ULL, 
            0xA216298833815AD7ULL, 0x9B4F798263EBC40BULL, 0x85E1BC8DF6E37C9FULL, 0x191EE722B1E5D0EAULL
        },
        {
            0x7AC26B1D3DBEED7DULL, 0x80678878C731DE05ULL, 0xE7A6ED579B65349FULL, 0x94B2B07F3E25F61AULL, 
            0xD18457640576F29BULL, 0x1EAAB9982CD4EEC0ULL, 0x591659B702EBE0C3ULL, 0xFC19F344FCFF10DFULL, 
            0xADEB6F816F3A6700ULL, 0x6E3E5493F8AC9FCCULL, 0x01A4EE66F60972A1ULL, 0x1AE1168AAE619CD6ULL, 
            0xA4CCFDE4E99580AAULL, 0x4EE7E21672D560F0ULL, 0x6C442A20A3603880ULL, 0x412F6D960A5F8B80ULL, 
            0x370694A80848EF41ULL, 0x1817690404A23974ULL, 0x2197AD081866342CULL, 0x79D6A81740C074D7ULL, 
            0xB863876975086632ULL, 0x114B38B21F3AF1C8ULL, 0x9B2481945B792FADULL, 0x7B59FA99AE6CF07CULL, 
            0x742C6F31A83FD404ULL, 0xB0A380764921994AULL, 0x07A7FBD288A13443ULL, 0x1EF5FA471F557BA3ULL, 
            0x6E5E6F33679F07D7ULL, 0xA9AFDE47EADDB256ULL, 0x2E04F787C0351BCAULL, 0x2D6B360625B183C3ULL
        }
    },
    {
        {
            0xAEB387E3382286D1ULL, 0x52A094381D172FFAULL, 0x212FF0D7181BBD34ULL, 0x8953B45B54D92ACBULL, 
            0x5D194253FAB731AAULL, 0x135AF29D323089B1ULL, 0x490DD27E5E37B563ULL, 0x44B627A6C1F28648ULL, 
            0x0635099EBDD874C4ULL, 0xED8EDF65E0D8D7D9ULL, 0x28B11D7B713E44CBULL, 0x041B55F500D0A660ULL, 
            0xC7CBD97552211E3AULL, 0x00468252E666BFF9ULL, 0xFD082B719D0B42B4ULL, 0x6B9519B7826308A4ULL, 
            0x6A7EF0734BD77113ULL, 0x14001BC101FE6C9BULL, 0x1695291349CFBA96ULL, 0xA2858F7AD7F423BBULL, 
            0xF66BCE791E352155ULL, 0x7CC7CBAB9A1A82B8ULL, 0xC869B8894648F6DFULL, 0xEAF491247B418709ULL, 
            0x0D9A8C3E2F87E26BULL, 0x5CB63D9D44537B34ULL, 0x432D1AA0A4C4D35CULL, 0xDFF6EE3503A5F1C2ULL, 
            0xF48AC36827A2476EULL, 0xCD4B6BAAEA9924E7ULL, 0x7B699C0A99E608B0ULL, 0x2153636B06CED0EEULL
        },
        {
            0xD2FE0A7FD8F77289ULL, 0x9608F93AD4F7DCCDULL, 0x414524E659A9820CULL, 0x959CBBA5357C36B0ULL, 
            0x65D9F4E02FF09B1AULL, 0x9CBBBB817EB3AD38ULL, 0x0A4BCDE230AC58A1ULL, 0x7BC081757F24EA5FULL, 
            0xE9DF1134D52AF890ULL, 0x27990D1DF2FCEE01ULL, 0x942AAAE10001D64DULL, 0xEB7EF740AAB8E446ULL, 
            0xA6DC3EAE6FD8A124ULL, 0xC384290400E2154BULL, 0x7D235B3CD5074B31ULL, 0xC50AC90F2A4D840AULL, 
            0x34652CD129182096ULL, 0xE8F7AAE629086625ULL, 0x2C982D33DA4BEA1FULL, 0xE8E7FF7FF25411E0ULL, 
            0x043F0D850EF393D4ULL, 0x27A0081810173EE3ULL, 0x773F0BA08DE35C45ULL, 0x6A4D62532B321A79ULL, 
            0xCE89CBA27FF66898ULL, 0x552B8BAFAA0AEBDFULL, 0x57F77B149144531EULL, 0xD8E69B29597BBD6DULL, 
            0x53D8E8020D05E3DCULL, 0xA28E2638983B581EULL, 0xB5EAEC3557CB8E8FULL, 0x1B586A58898A1FEAULL
        },
        {
            0x4965FA4FA632B615ULL, 0xBD7F741BD6838FBFULL, 0xB8C85D52B03139EFULL, 0xA84A748B833346F4ULL, 
            0x5FA2A3133BE158FFULL, 0x809FF834C22B486FULL, 0x7DD651FC74BCE6ACULL, 0x03C10E0C033B87B1ULL, 
            0x80E5CB69CDED0C33ULL, 0x162E6F9F86966DDCULL, 0x158641272D7CAB46ULL, 0x0F82249D4A165517ULL, 
            0xF68E4D6FA35229F9ULL, 0x98EF01EE3A106C09ULL, 0x257C8D86A0361E4EULL, 0x1E041423E961567BULL, 
            0x910220668BF8CB6FULL, 0x467423CFDEE51BDAULL, 0xCCF4298CEB7E6133ULL, 0xECEA544883FCA5D2ULL, 
            0x1308F687F737CB9AULL, 0xBE92C8CB931339D1ULL, 0x1226FEC4481D937EULL, 0x0D4306EA6B4185B6ULL, 
            0x74F9881CD7EF6001ULL, 0xBE5687C9F0154D06ULL, 0x9230135419442760ULL, 0x108F49E65879F69DULL, 
            0xCAC94B8FD64D284AULL, 0x21057CAB82D0018BULL, 0x1AD951FA08729631ULL, 0xDA186E1245A633D5ULL
        },
        {
            0x7385FDA81EC8E027ULL, 0xC3FCF28824FE03BCULL, 0xF9B9B88EB836A6ECULL, 0xE75BF3451FC24CCDULL, 
            0x2EF58AE94683A93EULL, 0x7044474690DCADBAULL, 0x5FF8D83E49CA6983ULL, 0x37EB788CA43A2387ULL, 
            0xC4BF9561E34AE868ULL, 0x3FD331DE7251D14FULL, 0x4CA24C4585E4F346ULL, 0x39000F5DE0F3B9FDULL, 
            0xC3FBEC3A3607B502ULL, 0x6F22BD41E128F573ULL, 0xDAB0A6F92A0CB7C6ULL, 0x74EE9386F159D890ULL, 
            0x9BF9FE073667F957ULL, 0x7685E283E3E09AB2ULL, 0x2D0A8FDB8A6D5399ULL, 0xCB7682E1F33F83C8ULL, 
            0xC2C385C2513CE537ULL, 0x861B2286A056EA44ULL, 0x140519C26F2188B6ULL, 0x1C8595BA2298BA0EULL, 
            0x809656B974E169E6ULL, 0x9156C67093326373ULL, 0xD03EA18F2DFB396BULL, 0xCC4A4A85DE2AE508ULL, 
            0xBD3AEDDE69BDE909ULL, 0xC256E4EF22A40386ULL, 0x323D6101866F7A9EULL, 0x93C2B9B40D2000F4ULL
        },
        {
            0x6B75E7E3814D40DBULL, 0xE49D7CA642A42447ULL, 0x10B3C037DA24831FULL, 0x1C39E25C0FC4A3B1ULL, 
            0xD7F4D1C11C1E6446ULL, 0x9BDE4932C40AB504ULL, 0xE8AA459EEEF098EEULL, 0xED5F075F5174A722ULL, 
            0x44488A7173F50A27ULL, 0x2F2DCB67CC4A448BULL, 0x6653F525FA3C9D2BULL, 0x5A777E08B4FC0483ULL, 
            0x2BB3F503EAA7A655ULL, 0x89E148F0EEE09D05ULL, 0x5F521A63676A501AULL, 0x6D0D16A248D74AEDULL, 
            0x5E748BCB34CDEB91ULL, 0x1F796872D5E8CCB4ULL, 0xEB58F0F40EAAE438ULL, 0x3A4121765C080491ULL, 
            0x7839820D1BE09FB5ULL, 0xF915F8B619522457ULL, 0x1EAD78B1B5B2CC03ULL, 0xA05403F5BD8A47A9ULL, 
            0xA459AAC5D2A33CABULL, 0xFB83441DFB5C4DD6ULL, 0xF03CDA1EDAEE097CULL, 0xE6BC0C39244DA0E2ULL, 
            0x7984654A0A2D434BULL, 0x1CB03F58928C6D16ULL, 0xAC13D1EBB0D9E10FULL, 0x7C0C4D48D54D6C5EULL
        },
        {
            0x0F3A814067B43F3FULL, 0x722A9E6E0D1C5942ULL, 0x8F5C00DFF836B9FEULL, 0x2F7D7B65E5EADF07ULL, 
            0xAB5B9A394C10C353ULL, 0x3598ABA53298D2EDULL, 0x71A29D3E3ECDDE68ULL, 0x82223BB935EA9750ULL, 
            0xF21EFBCAA2C6152CULL, 0x62F7E8514FB84C94ULL, 0x46423121CC834584ULL, 0x59CDEC6B5861350EULL, 
            0x1CB3282622FB1CBAULL, 0xA4B646E2B00144B4ULL, 0xD31711E1A24A2386ULL, 0x331005D572512797ULL, 
            0xB352CDAC0D021DA1ULL, 0x5337D36CCF3EB627ULL, 0x936FC75F0EC7F8C8ULL, 0x4862D76695714B9EULL, 
            0x7747446A2BA67F21ULL, 0xE049C9DFD473C110ULL, 0x3034AF1894071BD2ULL, 0x51D055576ABF185EULL, 
            0xC63CC29438B67E3DULL, 0x6C06943C29103284ULL, 0x57EFB80FD7B073E7ULL, 0xC3B5812DE5AA4BD3ULL, 
            0xA475D972294ABA6DULL, 0x9FCA71C25F6ABC32ULL, 0x58D17A336052B655ULL, 0xECE9CEC0F6DEB6EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseCConstants = {
    0xA909A73409E6D58FULL,
    0x6678BFE216094FC6ULL,
    0x975819F103394B22ULL,
    0xA909A73409E6D58FULL,
    0x6678BFE216094FC6ULL,
    0x975819F103394B22ULL,
    0x4054149EC9CEC901ULL,
    0xCD8EEAAE88669335ULL,
    0xC3,
    0xC5,
    0x19,
    0xAC,
    0x31,
    0x48,
    0xE0,
    0x8E
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseDSalts = {
    {
        {
            0x0EED2F9900700E17ULL, 0x6C037C635DF4BB77ULL, 0xF4C57808621A270BULL, 0xAEBF41D3F6532B83ULL, 
            0x36897C3C1BF986F1ULL, 0xD6A33412BF1CD6A9ULL, 0x655FD3AB0D91EF8BULL, 0x31529767C31EFE71ULL, 
            0xF556C2532E3C263BULL, 0x68CFADA9C92CD96EULL, 0xB7A5E79F46F2979CULL, 0x19D3D88FFBA2F979ULL, 
            0x8C4416A5C3C16684ULL, 0xDCE3E7E3C0778420ULL, 0x4E8706E2980C468AULL, 0xE17A37878C31FC91ULL, 
            0xA2362253089B5E3BULL, 0xFA687090B587A549ULL, 0xEC8FB80B3BDB79EAULL, 0x36F0FDF97F90762DULL, 
            0x1926ADE74C610BD1ULL, 0x18210BB9813701BBULL, 0x15ED79881F9918C2ULL, 0x356FAB5CC3D0A60FULL, 
            0x85810704B16AC947ULL, 0x668E5DAA693118DFULL, 0x21607C5121B6172FULL, 0x2AC421A9E001109EULL, 
            0x20AC4E9AE1508149ULL, 0x4A364EF7A23DFCAFULL, 0xA0BF1573A01535E9ULL, 0x2811CE7FF31DB3A8ULL
        },
        {
            0xF3C9B8302D4F57E9ULL, 0x9225D92F204109F4ULL, 0x2B1E5168EDC1B81DULL, 0x0673F28C2DCFAF2AULL, 
            0x31881FEB184E699FULL, 0xD353819D1819D02BULL, 0xC300A16ED9070CB8ULL, 0x8AC93BB1975D0F97ULL, 
            0x06413CB41C6BCCCEULL, 0x80571446662C5BF8ULL, 0x4C9E8FAA474DB607ULL, 0xDFD6D1C1E40ADE3AULL, 
            0xF115F8484D4A36A1ULL, 0xA596A1204657FC92ULL, 0x0D3C004A3CB9AEF7ULL, 0x40D429B2E3F41439ULL, 
            0xB612B846799583CAULL, 0xF11AFB6DC3D1E204ULL, 0x3C4CB4BCFB2B6E13ULL, 0x1F6C498FE5BF52CAULL, 
            0x48363E0409E0D7A3ULL, 0x94DFC55E861142E9ULL, 0x0EA562B4625359FAULL, 0x934B1356B559EB11ULL, 
            0x932D4D72F06A1D78ULL, 0xB40BED660531D421ULL, 0xDE8EDFF618B9DC10ULL, 0x90DE8E81CD0A3FFDULL, 
            0xD2FBC8624720667AULL, 0x8C4713800BB84BE5ULL, 0xD5C15D6A89D9AB07ULL, 0x0136E270E884B674ULL
        },
        {
            0x9A0C4493C5E7BE6FULL, 0x19EDC0C106C66703ULL, 0x7F31996A647CC105ULL, 0xD4C46D18B8C31F57ULL, 
            0xB6DBC3E7BD8D8434ULL, 0x1CAD069B220FB9C1ULL, 0xFF3F3B897134E584ULL, 0x50F9AA8DC2057369ULL, 
            0x242208FFD82DFD5FULL, 0x37CE3F276684BA1EULL, 0x28A026DB90D82D85ULL, 0x30E7920EEEEDFBF8ULL, 
            0x83DFF8CECA4FBD2EULL, 0x1DFF531ECB75C66FULL, 0xE934B5193D3AEB6EULL, 0xD14646E018C66E68ULL, 
            0x6FF67A57EFEDA0A6ULL, 0x5CAB180F07D049AAULL, 0xF80FE15CBEF7140EULL, 0x8CEB92CFDEC67D61ULL, 
            0xCFB76E3405B24F6CULL, 0x90A506EBABD5523FULL, 0x3EEC1D1CE2A3C682ULL, 0x19A774BA6FFD60D1ULL, 
            0x2DF7842F7BB8F8C2ULL, 0xD54C2DFD2838C71FULL, 0xAA7B32B97926250AULL, 0x1EEDFD3CCD11C446ULL, 
            0x9729A1FCA52EBAFAULL, 0x9C668FC6BF47AD54ULL, 0xEEDDE65E419FDA63ULL, 0xCAE3CCD508C8D7D8ULL
        },
        {
            0x14F34C263FF7C2D4ULL, 0x04BBE39F8AEBDD83ULL, 0x56C16B201126B52BULL, 0xE814881AECA35AB9ULL, 
            0x273320468CF5CA42ULL, 0x588A1E3F016EE69CULL, 0x8DC28AB55325218BULL, 0x1B3EDC57FED841DBULL, 
            0xE3371B8CCD07D164ULL, 0x25782D29EFD0AED9ULL, 0x6613E54AA6825C2AULL, 0x2B44E5AA3E8197FFULL, 
            0x0C1EC4B7FD709B86ULL, 0x93CEDAB394120D87ULL, 0xC822FB9E4D2F5E7BULL, 0xDC9BB46CFFE57A78ULL, 
            0x81A799B0176F45E2ULL, 0xC2C0FBC256225A96ULL, 0x4FBE6CCAF3A24211ULL, 0x7FC592C92089C0D5ULL, 
            0x90F7EF7120847862ULL, 0x5F939700A739E9F6ULL, 0xE12B7E229CDE3BE3ULL, 0xD20438EA136D86B3ULL, 
            0x83A149BB962FDB8BULL, 0x33C59B1D56BDC41FULL, 0x7F509125D6F741E9ULL, 0xB321B586A8714C41ULL, 
            0xB2ACFEAA24EA6950ULL, 0x9CE753E9907AB030ULL, 0x8A0A4740FA77C29AULL, 0x70FAF2CE69404E92ULL
        },
        {
            0xEE5FB5A1B3A5D634ULL, 0xBE05FB023FC0D39EULL, 0xA800C15C51CAF06DULL, 0xCA93B9CBB2752F11ULL, 
            0x864940BA752CC268ULL, 0x87FCAAE1B193AFE2ULL, 0xAD77367C7AD2CD35ULL, 0x08E190CBA42AF19CULL, 
            0x9DF113C6014D5993ULL, 0xBD62CCB61A73D3C9ULL, 0x6BAA7B7158D28A1AULL, 0xBEAA9F2BB4B5A178ULL, 
            0x5D4354E703D5409EULL, 0xAAEFAE1C55F19034ULL, 0xD80A27488AE438BCULL, 0x4D1987B8C1FAEBE6ULL, 
            0x84D208B436771844ULL, 0x7CAAA4A80C801626ULL, 0x55F1AB06FA28BB50ULL, 0x56918DBE88FD75EDULL, 
            0xE4AE5A644A1FF306ULL, 0x15C050AA53EBA858ULL, 0xC3E195899B54ECEFULL, 0x15A28C75E42E4AC3ULL, 
            0xAEF7B31625EE922AULL, 0x22679D42AECFCB4CULL, 0x05B5350597AB7608ULL, 0x982BB8CB757A7500ULL, 
            0x0751C3F9FF16B7BDULL, 0x3BBA4794A9A6714DULL, 0x6872CE750E9937A7ULL, 0x5113E79781CF2C45ULL
        },
        {
            0xF929E8D9BCBDA129ULL, 0xDCCB2C95C2249F73ULL, 0x2F7F8B79D0BE0B29ULL, 0xF3595582BA4F8F52ULL, 
            0xCB19C9A5D382C623ULL, 0x24B881784CCAAC82ULL, 0x2B827943FD055AAEULL, 0xB7A41097B577DF3DULL, 
            0xE5972A1B9C9FA1C9ULL, 0xA351CBFE96EF3875ULL, 0x0A43350B4687E432ULL, 0xA839B31AE76E130DULL, 
            0xB9B65EA628DF91ACULL, 0xB2A5049413A2A07CULL, 0x0D7322A7EAA6D85EULL, 0xCBB7DA73240A843CULL, 
            0xB2F203BFD11BA8D4ULL, 0xFA6A256660CB55A8ULL, 0xB44784F164AA6144ULL, 0xEFDB8A4A33073BD8ULL, 
            0x7DCA908A596B5A30ULL, 0xBF15E45B579E5CE4ULL, 0xFC9AF94DF38345CCULL, 0x2BDAD69E0DA19355ULL, 
            0xF61AC6542F20B7C2ULL, 0x23719251E47A1732ULL, 0x4C3A7AEFA5173802ULL, 0xF7AC38FC089C9463ULL, 
            0xA11D7F189A00744BULL, 0x37E6999AA2296B69ULL, 0x0D0996E50F0C0A44ULL, 0x60A94605506E972AULL
        }
    },
    {
        {
            0x7E676EC1A21C7D71ULL, 0x8F0C5FDF683F7E90ULL, 0xE34C6112202801E1ULL, 0xF04C222EABD531CEULL, 
            0x1EF1ABF5D68F7769ULL, 0x2082DD9F0FA4EF09ULL, 0x87CA0AAE6321898AULL, 0xA02B93BBF94A031EULL, 
            0xD94A2CD2B8D5B620ULL, 0x751C8C21194C4FF5ULL, 0xE4C5F70705CF992BULL, 0xF69567CCC4D7E41CULL, 
            0x9ADA9AB50E50962BULL, 0xF84AD047AAE463CEULL, 0x4ECEDB0886AAB68CULL, 0x19B906A046FF22D1ULL, 
            0x599B07DC63D8CEC5ULL, 0x8F5A66CFE3AE436DULL, 0xF3B02ADA4E8FD2FBULL, 0x9994C8806B65AF0BULL, 
            0xD4AC8320EF4BC4CDULL, 0x3B4CD4C3FC82CB53ULL, 0xD319969322A97503ULL, 0x2A3BFB99FE10A106ULL, 
            0x15B27004B77A343BULL, 0x5B84F42E0B0ACE4EULL, 0xFDD90BA594828443ULL, 0x5B83EBE1BF13E695ULL, 
            0x354A9AD1A8169AF4ULL, 0xA05CB8B514B0F7D7ULL, 0x15197D4B1C927DFEULL, 0xA98118D08093FF94ULL
        },
        {
            0x5278F4D79197E343ULL, 0xE071CFB9E0FBC00AULL, 0x50A13432572A3F57ULL, 0x8E5CA0E83E8473A9ULL, 
            0x0E1F23F03B35D4ECULL, 0x167F93D21266C137ULL, 0x3FF61D9A95D05F1EULL, 0xD9CCDFBB3D4FABD4ULL, 
            0xEBA587961616CAEAULL, 0x20B9AE25E1070DACULL, 0xCBD99707E7749ECDULL, 0xC0F5B3213AB2F86AULL, 
            0x0E69864D9539C39CULL, 0xDD1A7608CB5673D3ULL, 0x9FFC79A976846C80ULL, 0xC4486D68C9262EC3ULL, 
            0x24346CE958FD31DFULL, 0x5F1FE1199A643A6BULL, 0xD6AF8091B17F69C6ULL, 0xE2B88B1623245507ULL, 
            0xE9CC0ED38BC12915ULL, 0x727B37062C2E5F95ULL, 0x68C78EDF14438D5BULL, 0x45FCB16E85C06C3FULL, 
            0x2A1117CFEBC8993BULL, 0x82DB567A29A6B5D3ULL, 0x543E96179F8AB6F8ULL, 0x7C92152B5D94FE8CULL, 
            0xAC8C4113A1F3A0F9ULL, 0x0748685F5E2ACFAEULL, 0xDC7BAD3736771A2FULL, 0x5E8AA289841FB507ULL
        },
        {
            0x433ABF89DF98C0BAULL, 0x209029A52E1AF436ULL, 0x960769233AA3A02BULL, 0xA7E883A49337B9E6ULL, 
            0xE68CBD1FD3D7F1ABULL, 0xD26A97A1DDB68779ULL, 0x868988514B9FAE21ULL, 0x55C183C0EABC7CE8ULL, 
            0x941E38766F24A0C2ULL, 0x6CF7ED886DDA08ADULL, 0x674FD407D7FE847CULL, 0xC106FA2655177667ULL, 
            0x1A5B7924B96DFCB8ULL, 0x090F1AAE76A15F3BULL, 0x35FB79E2D47E80E4ULL, 0x0A66E30B2AC68740ULL, 
            0x56DDDC6811048828ULL, 0x18744488C1A4E3C9ULL, 0x1D58D38F7B3C960AULL, 0xF5FC036BC400028EULL, 
            0x231AA7A62ACDFAA1ULL, 0xC9C71D455E460151ULL, 0x53DA740CC82827ADULL, 0xB73108AAB20B16BDULL, 
            0xCCAFCBD59C1DDBAEULL, 0x0690CE500F1DB309ULL, 0xD7A7CB17E518A1B3ULL, 0xED51BB011D0F8B12ULL, 
            0xAEB6033B7B7C116EULL, 0x6D4CC9D6E6A39FFAULL, 0x7C219F284F9A2666ULL, 0x1E2C4118ABDC24DFULL
        },
        {
            0x94AF904103878638ULL, 0x42522F346BE7EE07ULL, 0x7C569A9A0741A24EULL, 0xE7888961AB621FEAULL, 
            0xAB41456748693295ULL, 0xE51CFB0C39B16A15ULL, 0x7199B766EFE23713ULL, 0x10DD34EB5FFC7438ULL, 
            0xB615486025FDC8FDULL, 0xEA16592E52CD61DCULL, 0xED39B8E5EDEE791AULL, 0x83DFEE2387AAE2AFULL, 
            0x014739A566DBCDAEULL, 0xBC47E2EDD6B30035ULL, 0x5480BE479384A6BDULL, 0x225E2E9DAA075F31ULL, 
            0xF569619C9E5FF699ULL, 0x606FC69FE3CE992DULL, 0xE96F23083BD4BB73ULL, 0xD97B0952B45740D3ULL, 
            0x2C0125517F019706ULL, 0x3A24FF1F189C3E1FULL, 0x17B9E5DECCBA00F8ULL, 0x770CE4688BD39F4AULL, 
            0x1BE2BB89446FBCBDULL, 0x86E501E6FEE127C2ULL, 0xDCA7510AA4879683ULL, 0xB1E867647CFBD993ULL, 
            0xEADD122996DCBFB0ULL, 0x8F88EC810D0E3EEEULL, 0x57EB8FF8F73DA3AAULL, 0x52CC04ED25FA252DULL
        },
        {
            0x336E8097774375B1ULL, 0xFE90DB1669616ADCULL, 0xE9C3CC0F50F3FC80ULL, 0x1A455A7EA92B8A1FULL, 
            0xB9865E38FB5E999FULL, 0x065A083EEAE9EF86ULL, 0x5D692C3D3FCCA275ULL, 0x28E586BE00635D7FULL, 
            0x90D7616A207975D0ULL, 0x1C933281A016192AULL, 0x86D9A04D80B94E8DULL, 0x204CB667323ACBEEULL, 
            0xE77E66C67D8A451DULL, 0x000E39AE861732F8ULL, 0x6D80F8226BA35638ULL, 0x6D0F7D3C7CC43AA2ULL, 
            0x6221AD86C1902656ULL, 0xB36B1ECD29A1CE8EULL, 0xC09D68729B829D5DULL, 0x9804CC06FDC6F9C8ULL, 
            0xED4705AFE5E971CFULL, 0xB3C843847540E2CEULL, 0xCF147BB64A8FE42CULL, 0xFD3CEC7E17E0493AULL, 
            0x706886E9D8D4FB6EULL, 0x065F69DFFC92C721ULL, 0x96ED4BDC34109236ULL, 0xD59F39D06B3D0561ULL, 
            0x22FD9B68A6495170ULL, 0xB2BF54F62822A054ULL, 0x11A1D62B484F21F2ULL, 0x3152159A45E43B48ULL
        },
        {
            0x6A0B7F3A9ADCFFDFULL, 0x5A0D93947F182D68ULL, 0xCC6FA3FF9FD09254ULL, 0x5A1E8EEF60E717A8ULL, 
            0xEE76703CD4122944ULL, 0x367F1A62CB6633CCULL, 0xC5E47580357923C0ULL, 0x4847EF5053B755D0ULL, 
            0x227A99568023A537ULL, 0xD795955B0C472B85ULL, 0x07DA15929F9FB1B4ULL, 0xB5C6736F6D42BBC1ULL, 
            0x253B272C80C87C25ULL, 0xA18DBDAB70DA8C0CULL, 0xC46098790B3AE60FULL, 0x5A4E8F6F6BFABE68ULL, 
            0xEAE90FDA6EEB69FDULL, 0xFA8CEFE75E7F7EF0ULL, 0x060236CB62D07024ULL, 0x921196F08BEAA50DULL, 
            0xFB8ECCEAE6361051ULL, 0xFC385B6EB59E6866ULL, 0xB0A0F56D45E16FF6ULL, 0x82B1F37A41DD051AULL, 
            0xABFDD32D5C859375ULL, 0x299E4EA82C936320ULL, 0x55990AE2CD9B25A3ULL, 0x2C215807CF34E1C5ULL, 
            0xA895D5FA121401BEULL, 0x839912843BDC9115ULL, 0xCA27A7BAFE385E6FULL, 0x0446D70AB83EDFEAULL
        }
    },
    {
        {
            0x6DEDD7AC8507B8C8ULL, 0x13865861A316F71AULL, 0x62F06700FE0D83B0ULL, 0x668EC2D71C26C2A3ULL, 
            0x1D929D1B921BC10CULL, 0x5818401F04923AEDULL, 0x18B9BC3C4BEFBF96ULL, 0x5504272E50969D52ULL, 
            0xE45F2F232194AB69ULL, 0xBB2BEEE1C42891EBULL, 0x12E2C35491E5D6D4ULL, 0x7E0548AEE4DA7744ULL, 
            0x080D457B60DD4F1FULL, 0xF14B38529233E17CULL, 0x17C64F620F873B85ULL, 0x408CB8837F2ACD91ULL, 
            0x910DBCA10E4144EBULL, 0x4BBBBB6E8D21BB93ULL, 0x736E726D4198C3FEULL, 0xC7FA1055F552BCE4ULL, 
            0xC0E12CAB0E1F306FULL, 0x01B3B9592AA60D22ULL, 0xDAB50D3C1B6EFFE3ULL, 0x28207C74884B321DULL, 
            0xA34B47E2B248FF65ULL, 0x87C4222454448EBDULL, 0x7F5CF660D6E5FC06ULL, 0x39394EB7ABEE6DB4ULL, 
            0x2055905DC0BA84F8ULL, 0xCF579A6FAFB34335ULL, 0x8DB58641DF7773C2ULL, 0x104B382B3BF09409ULL
        },
        {
            0xDFF8292B7443B2A6ULL, 0x7D2DBE502598A7BEULL, 0x68F312E1E4B16587ULL, 0xFE19CCFB19A72A80ULL, 
            0x4243D6BE45D53237ULL, 0x1BC435D1E3EC433DULL, 0x3BF85730177F7FE5ULL, 0x752A97C7502E6F02ULL, 
            0xB36E97035E442E99ULL, 0x9E15A1BC5521B0C0ULL, 0xBA1F9B61D04F089FULL, 0xDB5B9CE3D9996DD5ULL, 
            0x7D7FC66E96CA12BFULL, 0x39A048C890CFBFCFULL, 0x34A604C9C09C7DADULL, 0x3B5327FFA920025BULL, 
            0x46528BF00D5F4639ULL, 0x256F0FD0E8BBE905ULL, 0x309F7A31CC7AB74DULL, 0xCE5185E636550736ULL, 
            0xD811BBCCD5604D72ULL, 0xD261EA90C1479115ULL, 0x7FD0668C0CFE463FULL, 0x389EE5DEDEC67300ULL, 
            0xB13C345372AB7F2CULL, 0x6C19502E79933FCAULL, 0x470F63801F658679ULL, 0xAF37CAC2A6150F16ULL, 
            0x25D86DDC289F5F5CULL, 0x3492D780F11ECC5AULL, 0x05D2752D2D8D8C4DULL, 0x0066960D3212003CULL
        },
        {
            0xF7593DF65D920656ULL, 0x145079DAA339C950ULL, 0xB18179A28FA1C93AULL, 0xD5F0A7E8CBFFFB9FULL, 
            0x4AB2A4E562998B0BULL, 0x480E4B638A4D41E9ULL, 0x44208C80466982FDULL, 0x02980D175BCEEC04ULL, 
            0x6ECEF1A0E945F9D5ULL, 0x33FDBB3D8A70204AULL, 0xFDE9922732F3AA41ULL, 0x86551DEABD9EB1AEULL, 
            0x1AD5298CEFD9FAA9ULL, 0x074992CAC2271FDEULL, 0xFDF637FB5F7A281BULL, 0xF39BAE5212D9D1D9ULL, 
            0xA46A13A73B96F6D3ULL, 0x064F2CB1DCF86BA7ULL, 0x899A57D0A53F01B2ULL, 0xF7F843B4104BA52AULL, 
            0x7498204B4417DD58ULL, 0x0BD96F60A8EE912EULL, 0x01642FBACCAD6A93ULL, 0x482F700D4C37EBB9ULL, 
            0x64920D831F1A358BULL, 0xC0685B7A84256F88ULL, 0x69D033DC0E9CA2B4ULL, 0x12A7B1B37D21D24FULL, 
            0x7EBE7DDB7E54B69AULL, 0x079B06B504DB5D76ULL, 0x512996F6D1C009BDULL, 0x67297FD68D315166ULL
        },
        {
            0x7772D8202DC08CC2ULL, 0x6C661E30D7B08667ULL, 0x752ACBF75C1510E5ULL, 0x58740724F572C00AULL, 
            0xB9D4A905B2DC587AULL, 0x1D44D1C648A9DDFFULL, 0x8E471093AA4A02C5ULL, 0xF61659DCF1C8E5EBULL, 
            0xD4C6E116D81ED6DCULL, 0x1FB1CCA7845EB1B3ULL, 0xAE451F8A0912542FULL, 0x78249C7DA2EA6D19ULL, 
            0x6CB02E923F41D132ULL, 0x2D4EBF035F7D3EE5ULL, 0x61BFF53E390883D4ULL, 0x26ADDE0FE8706482ULL, 
            0x4F1C9B57B1227BC7ULL, 0xDE97B478761E85A7ULL, 0x1E97DEC3AEC9638CULL, 0xDEE170057B4DBAA5ULL, 
            0xA21EB6BE0388D2DFULL, 0xDBB9B5156E908A3BULL, 0xB8CD0272C4A771D0ULL, 0x6C7421FB82A8DFF5ULL, 
            0x32EE8C9A98FF0082ULL, 0x23549EAA6FD27ED1ULL, 0xF9E0C511B78C9B44ULL, 0x5BF168207E8DDC79ULL, 
            0x3246146B3C8854B2ULL, 0x72051585CE96AEF1ULL, 0x0D61791E7FBD8AE7ULL, 0x357AB690A311F5D5ULL
        },
        {
            0xA23C2A4B6E94C46FULL, 0x89FCD95E2C2AE091ULL, 0x3AAE67E91F83FF31ULL, 0xCFD18401A54B9D96ULL, 
            0x3FED9579BBC2B8D6ULL, 0x9B52B33B7A89B1E5ULL, 0xCD2CA5C95C0A407AULL, 0x2D7F4EBA27FA06A5ULL, 
            0xDB64B1CFF7FBB7D2ULL, 0x9682EB36E1B81A36ULL, 0x32DD91CBD05784D6ULL, 0xFAFDFA48243BD96CULL, 
            0xEF8A659A02BD3121ULL, 0x3DCE48FB32C52CC3ULL, 0x64880096FF7FF66AULL, 0x74F6C79D6464884AULL, 
            0xE2EF60DB6EE070A1ULL, 0xC9C59B3C08C43959ULL, 0x2661233554FDC9C6ULL, 0xDF55DA89760B6822ULL, 
            0x017EED40D6D91002ULL, 0x90BFB8807B9F2E4CULL, 0xA302E6A85E05CBB0ULL, 0x16FBFEF78BAF893DULL, 
            0xC9E5EC20867344CAULL, 0xDA1936DD68FB2E77ULL, 0x4C1ABDFBB612796BULL, 0x8983EEBE3C96B049ULL, 
            0x162793DA98AF4A47ULL, 0x708DBE4D695EB86AULL, 0xDD229A84BE3BF300ULL, 0x691DE0A4CA1413DDULL
        },
        {
            0x398FC51801A2A469ULL, 0x5B3A26D6B691F011ULL, 0x52C02EB962AC11EBULL, 0x7B9A5EBDDACB2888ULL, 
            0xAE0ABB55EFE4D2EAULL, 0x6D668599F7F46110ULL, 0xB5379FC75B7FFAAAULL, 0xF73C5107165E6092ULL, 
            0x8192B752588006B1ULL, 0x9E890E8187D2E7B4ULL, 0x9A28B4E149C02D81ULL, 0xFD2ED96FB7A998B8ULL, 
            0x0135579BC6EE6C15ULL, 0x74B323AADC4C0666ULL, 0x90BB5CEB87DAB42EULL, 0x0B30F60D7733439FULL, 
            0xB1C33C1DA376ED08ULL, 0x29DE8C4746EDBF21ULL, 0x3AF4F517E1A0766AULL, 0x74B8A2DA1BCBECC5ULL, 
            0xF515687B79877EF2ULL, 0xE197A9F1C825052FULL, 0x8F78A246372F7448ULL, 0xAF4C9B2C5D04D93CULL, 
            0x6AD202F1E8B1B38BULL, 0xBC6AE38108CEDB49ULL, 0xF245716178BF7FB4ULL, 0x139BAC8383E5FBD1ULL, 
            0xB8728C4FEAAC83C4ULL, 0x7361F2452C6BB27BULL, 0x0014C6A4DE958389ULL, 0x1F84FC29B3FF3C84ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseDConstants = {
    0xD697B555FA374AC1ULL,
    0x5920C879796447FEULL,
    0xF254A157692186DCULL,
    0xD697B555FA374AC1ULL,
    0x5920C879796447FEULL,
    0xF254A157692186DCULL,
    0x7C581F69439070B9ULL,
    0xC7CC3CD542977FA3ULL,
    0x16,
    0x4C,
    0x8C,
    0xD9,
    0x36,
    0x71,
    0xDC,
    0x26
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseESalts = {
    {
        {
            0x19436566ECB01493ULL, 0x6AEF5D4F849173EBULL, 0x7E86B19068A4ECC4ULL, 0x3FB943BBAB07D31AULL, 
            0x44B6AF08653E631BULL, 0x14B8BF833DEFB838ULL, 0x7ECDF46747BC6B90ULL, 0xEDF929BAC29603CEULL, 
            0x0935D5589C7D51D7ULL, 0xFC18F885BE516F83ULL, 0x86C38BFB660E9B10ULL, 0xB464C802187B9DD5ULL, 
            0xF701E3BD373D7444ULL, 0xF05373B7469B3316ULL, 0xD6691C6308B13265ULL, 0x5143D8C666E35F81ULL, 
            0xED1C9AE7F15CF81FULL, 0x36557C08CCF4C645ULL, 0x9CFECE7B02BE549DULL, 0x033FA1BBF9D27A97ULL, 
            0xCB0E43FDBB30EC2CULL, 0x7E0D853150BCB978ULL, 0xEDA35CECED4DD90BULL, 0x856DD8E3F121B145ULL, 
            0x61CC972D4D8F5A20ULL, 0x3521FCE0E3A81546ULL, 0x21DFD7E431B5FE5CULL, 0xD92FA8C3B072B584ULL, 
            0xC1EE7998F3678C3EULL, 0xAF63D0F3382A7409ULL, 0x7BA0B748BA37F941ULL, 0x6512A22A581F8FB7ULL
        },
        {
            0x77EC6BA3F1891F58ULL, 0xAEFC8D551E026CDAULL, 0x0B46F3AF460812DAULL, 0x36BCC98773E58CADULL, 
            0xCB96B178102ADCC8ULL, 0xD6643A3BD206426EULL, 0xB034E8169496525FULL, 0x0A5BE7CD9E510BBEULL, 
            0x4A644B4C992F8B43ULL, 0x364FBA3E7B9EDFCEULL, 0xCDB7BEA4EAE2D44AULL, 0xD60D8A98692B7D5EULL, 
            0x2A91587A47F32957ULL, 0x410F744D29F80F65ULL, 0x15B8CD09B83FA7CDULL, 0x9FE482DCFD49C0E8ULL, 
            0x9B7CC0E9A30664CDULL, 0x7A0627EA5B992E79ULL, 0x06B68B9BCD8B28D5ULL, 0x528636F71E5305CAULL, 
            0x0EEECB1DF82B87A9ULL, 0xA267A2607D18BF9BULL, 0xEEA5F121F6EF2965ULL, 0x4396F9198C7DB2FAULL, 
            0x5B024A1DEFE600ECULL, 0x8F43DF890A0760F9ULL, 0x0845001CAFF43324ULL, 0x823C4CBEBC283D7CULL, 
            0x2BDBAA3BCC5CBBC7ULL, 0x0B2745DF955CD3E8ULL, 0xBD6859C46D9692F0ULL, 0x9056ED9163E5F6BFULL
        },
        {
            0x1BEC2F982E221964ULL, 0xEF8B6E819D25AFA4ULL, 0x3135847459CD8B0CULL, 0x6CEAC7BEF3767B3FULL, 
            0x8211CE40C378C9B1ULL, 0xC9F634E9C021D2C4ULL, 0xA06BD37C794ACB37ULL, 0x2BFEBE511C702217ULL, 
            0x3139AD54348D2F95ULL, 0x956EE4ACBBB37DD2ULL, 0x790DAC95D0AB37BAULL, 0x98F357233BE6C5E7ULL, 
            0xABD2799E9793C72AULL, 0xE37BE2B0D10CECE9ULL, 0xCE2E51AB064084D2ULL, 0x3F7373007DE83AA7ULL, 
            0x92F80859A72E18CDULL, 0x70DC4B48852F7633ULL, 0x5B13C96782B4162AULL, 0x8970B9D4FE1AA9A6ULL, 
            0x5E7637DD6FB32A34ULL, 0x3959637F55969873ULL, 0xF305A0D0652403EAULL, 0xCCB7BD67A7B35242ULL, 
            0x559558CB0F4CFE71ULL, 0xDFB62F269401E66BULL, 0x334E8CFED24F4FE3ULL, 0xF644902DF546E393ULL, 
            0xFEC50C1DCF4CFBECULL, 0xFD702BC9ABE1E009ULL, 0x33488BC89E78FFBCULL, 0xD0D86533DBE6A619ULL
        },
        {
            0x214F6909831E0FD4ULL, 0x721A037E77627848ULL, 0xC295F64ADCCE7CE1ULL, 0xBA5563A49E3D0F20ULL, 
            0xDA504CEF11AAB321ULL, 0x15D5EAD6DD6C0AB5ULL, 0x37A8111F9EBACE72ULL, 0xE1662A6BC45FFCDFULL, 
            0x3E56424EF355B9A6ULL, 0xC67986AA4EF9F614ULL, 0x68F0B4566940A9BCULL, 0x2A463E3A45BBE4A0ULL, 
            0x1E2B715C590D677AULL, 0x29C02CB42D56FA3FULL, 0x6F58E4E4FB80353DULL, 0x3F8A70C3C5A78CA5ULL, 
            0x01EA2539AE9688F4ULL, 0x270DDB5691B3A11CULL, 0xD86CF03ADA8F249BULL, 0x659AE6E228EB83A4ULL, 
            0xE96A0CF8D057FF99ULL, 0xDCC92DE310900587ULL, 0x187B359BDF90B252ULL, 0xC62B5184F969150DULL, 
            0xBDB5279DF455B329ULL, 0xACAB9216C23EA2A4ULL, 0x209C154B8E97DAD9ULL, 0x32A96F033752604FULL, 
            0xF7FCD4275B938B88ULL, 0x3443D93243902160ULL, 0xB69CB23C9AAA4C35ULL, 0x5A2230D4720A92A3ULL
        },
        {
            0x54EF033408D43F96ULL, 0x4AA1935CD70E4896ULL, 0x7E40D507B49E448CULL, 0x14B52C398F8F3C13ULL, 
            0xEC998AF53168066FULL, 0x7C7828F3D40B1D4DULL, 0xEFE987C08320455EULL, 0x499661793D402612ULL, 
            0x04E11E183A9E1433ULL, 0x56F4C7BAF08F0015ULL, 0x826023A3EF2CC68AULL, 0xB0B36483F5AAE22EULL, 
            0x57A7859C72265CB2ULL, 0x6F81613C57791308ULL, 0xAFA8FCC199313B52ULL, 0x8DC8F4C16C368B78ULL, 
            0x8887DD89400B8523ULL, 0xB170134EA3B7983CULL, 0x090F730E770171BEULL, 0x7E3FE9732CD2B3A8ULL, 
            0x81818C3D00D356F4ULL, 0x38B63766F1586FC2ULL, 0xC4AA329894E53C2BULL, 0xBC7EF4CEC9258778ULL, 
            0xDDA0EC1CF17579AFULL, 0x236C25BEA9314900ULL, 0x13A2AC0E7DA47C19ULL, 0x8A8F362D55D176B9ULL, 
            0xE1092530FA9A3CB7ULL, 0x185E80D2C6F473A0ULL, 0x502FA3D9DBF3BA58ULL, 0x799131B13D8F7180ULL
        },
        {
            0x3EE9D0F8CA1B4D92ULL, 0x85864D813905891EULL, 0x3EC90CB7D15488E0ULL, 0xE91A61D0DD72F823ULL, 
            0x58B5D7800B4E6DBAULL, 0x4A3C9C7E5DE3C36EULL, 0x02809E72379051D0ULL, 0x49DBB489989EC045ULL, 
            0x2A97D13F3950ABCEULL, 0x31951CF449435622ULL, 0x2F5202FE68A2BF1AULL, 0x9E7D5C5621BA2F2AULL, 
            0x01B5AF217F4F6CBCULL, 0x72860CA6B483A42EULL, 0x1CDE920CDC8C5625ULL, 0xDEF224C05902D21FULL, 
            0x5CF0FDB54FFE412EULL, 0x5607163213291248ULL, 0x288BC22CEE87B56BULL, 0xB9DE86FEAFA48DE6ULL, 
            0x811E277AB8C68526ULL, 0x1A57513CA4FF085FULL, 0x6D97FA94B167067AULL, 0xF95034B5165F12AAULL, 
            0xA645F489D4E3363DULL, 0x1249C2FD7CC05C25ULL, 0x305F41AAFD71D983ULL, 0xAD281AAEDCD045E7ULL, 
            0x99BFD9F3D11E1AE4ULL, 0x2E72B38EFA29D234ULL, 0x5C051E3569B01DAAULL, 0x5667E684DE1CFFC4ULL
        }
    },
    {
        {
            0x210CC86C1EBEF8F9ULL, 0x3F10BD08C599F6DDULL, 0xFC22661E5896FA6CULL, 0xAF723EACD3A7F5AEULL, 
            0x158F81DC69BABA92ULL, 0x3832356D1EA74B6DULL, 0x9D093FD8D61EA0CFULL, 0x803EC3168B8C06E6ULL, 
            0x16D6F7F3682856A1ULL, 0x42E1DFAF138D25C5ULL, 0x6EA2144A2988E95AULL, 0x82E78860794AC568ULL, 
            0x5CC688184395F6A0ULL, 0xC8959438406C365CULL, 0xA6688753E0C7F09EULL, 0xD761A261C763D90DULL, 
            0x7A7D4291CF05D5AAULL, 0x291353475C478E40ULL, 0x42A4E98E726AA688ULL, 0xEF59B79ACC10F68AULL, 
            0x510887D4582AF0B2ULL, 0x0B392933AF0DAFB3ULL, 0xFBE71E0DDE3F9DA4ULL, 0xDB1019F764211671ULL, 
            0x636E146FE05217EEULL, 0x0F7712711476C378ULL, 0x64554FC38647B65AULL, 0xA0A50F2F25A81884ULL, 
            0x774A87CE96C7B133ULL, 0x1624DF54CD357DB4ULL, 0x69B6F73AAA473406ULL, 0xAFC6EE2665E60F9BULL
        },
        {
            0xEC59190EE1740165ULL, 0x6CE26F49206525E7ULL, 0x4E99CB76ADE034B7ULL, 0xD8954D80FA6A977EULL, 
            0xBA6C3BB17ACC4012ULL, 0x07DEDA7763A4D3ECULL, 0x7669F4FF250F4712ULL, 0x60C8D265857BE0AEULL, 
            0x9879561628223F4BULL, 0x760599E76F40230FULL, 0x94681615B84DF02BULL, 0x98A89148B917F608ULL, 
            0x887E4729A27EF4BBULL, 0x1EB92830E0A7CF46ULL, 0x7C988DE239D0F2C2ULL, 0xE09AA19E9760B701ULL, 
            0x50A1A76625E14B47ULL, 0xFCAB1150CD231BEBULL, 0x510D1D6118F0D271ULL, 0x6E7CC9926D229EFBULL, 
            0x6C90E301C85B2AB4ULL, 0x42E599BC8387720BULL, 0x58D1B1A5FA77C8C9ULL, 0x4D513938B35D146FULL, 
            0x166ACFCFAD97504AULL, 0x92A45383C65B73EAULL, 0x1E7E729E3BBD9245ULL, 0x4F1986C326302A4CULL, 
            0x0AFE4300181A1C22ULL, 0x3B151EC469AEC803ULL, 0xB6C248FD83D4745FULL, 0xA65E2C8686241D69ULL
        },
        {
            0xAC9C1A3589B7540DULL, 0x7F4FE701F21E1F95ULL, 0x2C23A061CC982E98ULL, 0xB09D723D1C17609CULL, 
            0x48C921054CF3A45FULL, 0xADEDEB559358E889ULL, 0x993F3C4483AB2D12ULL, 0xA5F1B98F30E21D8EULL, 
            0x4231A16B3AB3BDC2ULL, 0xAB29964FCAD0A84AULL, 0x1B63C21ED68AA9A3ULL, 0xD92030D0F008B8E1ULL, 
            0x629E66021B2B8BDBULL, 0x0B712245CD3825BBULL, 0x74B43A9C1A8F1958ULL, 0x9ADC6DBF125E5343ULL, 
            0x91DB98527B349ABEULL, 0x43D779D7CC5BBBB7ULL, 0xD991D07B2B84186FULL, 0xAFFF5EC2B4AFA9C3ULL, 
            0x1E97D72601AB6109ULL, 0xEF62BE5BDCE8592FULL, 0x6845C9991E9E96DFULL, 0x192297A51B97B725ULL, 
            0xA7E01D32C94E8A7CULL, 0x2063F6F08CAA58E7ULL, 0x29E3D09039F2CFFAULL, 0x5DCC0CBF29031DE5ULL, 
            0x37240FF967585494ULL, 0x7677209183D507B5ULL, 0x99EA015617DD355AULL, 0x401CEA9C3A9794E1ULL
        },
        {
            0x557699C0B8259073ULL, 0x5666AD9AC1528CCAULL, 0x07E94D1212DCA873ULL, 0x999F4B184AED49F7ULL, 
            0xD93CFC2E6184C665ULL, 0xA123B3D3E1037816ULL, 0xC0D6693FDDA27B73ULL, 0xF7F0BC3A36F636B3ULL, 
            0xD276DA830B37F7C3ULL, 0xEB4A5A02E8B147E4ULL, 0x28BBD3A3CD139A72ULL, 0x7F99309071953F17ULL, 
            0x015F8FCD1089AFCBULL, 0x359FEA5F5D83D63FULL, 0x28A8D03DC3BEF05CULL, 0x27DF00F97B425CA6ULL, 
            0x66D81C4C35A9B273ULL, 0x4558253BE263E4C4ULL, 0x6F810F97CAD9719FULL, 0x205AFC3F757C0C69ULL, 
            0x690B1A4FCE6F728DULL, 0xD4CB45A4AC54FBEAULL, 0x170DC4A4121DAAF2ULL, 0xB8B341D81527892DULL, 
            0xD5D0E4818635DD9EULL, 0x3CB3E5E35CAE52B9ULL, 0xE31CAA4F2802B654ULL, 0x377082C77672E1B3ULL, 
            0xD7EFDB307FC096E5ULL, 0x5281B81212B487C1ULL, 0x12F88AD2BBEACE38ULL, 0x2F8E9433371E4811ULL
        },
        {
            0x23A6BD0BA2E06F1AULL, 0xFB6F5EBC5A22347BULL, 0xD1C8C508B9B860B0ULL, 0xAE1F49CE9BC4285BULL, 
            0xA110EC36ECF2A7D1ULL, 0x3C1B8E1DF4DAC6C7ULL, 0x4258E73D51C2C0EFULL, 0x7F858B5AD7EAA248ULL, 
            0x6C4FBEBEC096E70CULL, 0xD26D154B7DF57AA6ULL, 0x4928D5CAB54161DDULL, 0xADF813E1FEF53974ULL, 
            0x0A409B0356922FA3ULL, 0xD8D55C7C47D76373ULL, 0x65995130198FD4E7ULL, 0xF6EAB00ECD36D826ULL, 
            0xE0F216CD1E6135D5ULL, 0x263F0A7BF55EBA5CULL, 0x22099AA6AC3C69D2ULL, 0x111CA395EC927C2AULL, 
            0xDDBA55CF8C7B7617ULL, 0xF5C0539EE87E7BD5ULL, 0x3C325913B58FC0EAULL, 0x74D4B40EF3530E26ULL, 
            0x1B9FF46E586501CAULL, 0xB6ABDEDD564C1174ULL, 0x1B001041083CC6E0ULL, 0x8D05BE8309937DC0ULL, 
            0xF50CA0FED7A6A589ULL, 0xBF5A8DE8A4073C63ULL, 0x558298B5B4C16869ULL, 0xDCD83E9CE7A76873ULL
        },
        {
            0xE4AEE4108BD67687ULL, 0xEDAC929EAF17FF6DULL, 0x3E5FB3D0F3AD02D2ULL, 0xE6D8DCBF6FE2B375ULL, 
            0x5E90BA7599B08737ULL, 0xB3995829B63F6192ULL, 0xBC7C79EFF049EF48ULL, 0x47A31B9652B46569ULL, 
            0x4643ECEFEF987BBAULL, 0xDA4D6A8702A25CCBULL, 0xBFCD231BB08ED637ULL, 0x7586CF87599EC1B0ULL, 
            0x674BADF7F728E321ULL, 0x1A35EC075D24113CULL, 0x29743F7CA3162E70ULL, 0x35B84DC4DE3D31E7ULL, 
            0x454F0FC26ADED913ULL, 0x62324F66239F35D1ULL, 0xD6DAD5C1997E3C22ULL, 0x0B8BD2D7ED0AC968ULL, 
            0xD1EB2B1F8E6AAD32ULL, 0xA594F2F170D54899ULL, 0x72C10DAFBBB09491ULL, 0x72445F2A27F762FAULL, 
            0xFBCB89F8DCE73058ULL, 0x967AC10C3AEEE341ULL, 0x6377C1B86FF806EBULL, 0x24483B7ECECE407DULL, 
            0x5E6F25BEFE9F0A0DULL, 0xEBB307A5E882B2A5ULL, 0x54E0C822D4B87D66ULL, 0x1EDB0EF317487560ULL
        }
    },
    {
        {
            0xAF5ACDC7207506DCULL, 0x02A3DB38D521F84CULL, 0x2274966BC644FB32ULL, 0xF271638723AFE21BULL, 
            0x710E414471B0A609ULL, 0x5D09A46A1FEAA3F1ULL, 0x20FCDB348455DDE9ULL, 0x048303BE7F4C595DULL, 
            0x238B34C836E0E7E8ULL, 0x6F132F07075C927EULL, 0xF3E5694799EE2539ULL, 0x1C43BF8D34AD1C00ULL, 
            0xC1462C7DEADCC5A9ULL, 0x985ECC35458211FBULL, 0x5A12AC960D277DF6ULL, 0x176E78405A72235CULL, 
            0xB27CC5F90E5AA274ULL, 0x48ACA2FE7AD2508CULL, 0xC80CC0F3CA74D244ULL, 0x093CDB00224753E0ULL, 
            0x4C975BB77519B062ULL, 0x5807A389294C9414ULL, 0x43D8257AE182932BULL, 0x5D27302942CE20A7ULL, 
            0xD7941317571C6367ULL, 0x664B37D43E137AC6ULL, 0x7B071A286AE07F75ULL, 0x87163FE4F3AE2E2EULL, 
            0xE6E62BF9FBFC7BFAULL, 0xBE5DEBB019FCD0C9ULL, 0xBCB011E53687460EULL, 0x08672E047E80A1DDULL
        },
        {
            0x13E8AE3A2E0458B5ULL, 0x5D39BCA7F352BD91ULL, 0x716197A35BAD7FF6ULL, 0x2682C2A7D9CBD753ULL, 
            0x0975854F88AB916BULL, 0xBDA0C8BB588326E7ULL, 0x502D31E4E05E66B6ULL, 0x905F46E9F6E18ECEULL, 
            0x78F5FE19521EF8E0ULL, 0xEE5295EE0571C3F0ULL, 0x4BB02AB4C16F3FB0ULL, 0x07DD20295DD5C04BULL, 
            0xABB3120AF18D7486ULL, 0x7B8682049B8660AEULL, 0x0F70F590BBDFF43EULL, 0x498F50C90B038AFFULL, 
            0xFBC7B3154DDD5ED4ULL, 0xD517030F74E8F560ULL, 0x5E9EC60414C31D35ULL, 0x8BF4C309137F1EEAULL, 
            0xA03813572EF69652ULL, 0xBBFF588CFAFBF7DEULL, 0xB0541612272D0841ULL, 0x3EEB14440D4CC7A1ULL, 
            0x6861E9C06BEF9798ULL, 0x5755DD35D655CBFFULL, 0x0C063BD0671DE7B0ULL, 0xCD606CE0039C5C50ULL, 
            0xF536C6EC69FF990DULL, 0x08C16364F4393454ULL, 0xC3BC9CC40726D395ULL, 0x7C6E1F3047069540ULL
        },
        {
            0xF90FA5509F4D4BC7ULL, 0x3E4051C2D47D37D4ULL, 0xBBEFCE913E7B3BB9ULL, 0x8F77C01372044031ULL, 
            0xE8DC58F12E6437AEULL, 0x775E20EB8E917925ULL, 0x5057E41C8563AE4EULL, 0x886A7E9AB0D386B8ULL, 
            0x76BFCF95A9337AA1ULL, 0x0C3A180D31A3C877ULL, 0x21E9D378D4FE1CDFULL, 0xBEB9E843A672C902ULL, 
            0x1E6FA3EA75B776B7ULL, 0xF4A42F37D04B41D8ULL, 0x585249528EE774CFULL, 0xEC76825C1C1829ECULL, 
            0x88DA138E1A26A1A7ULL, 0x028C8BD31F87CF37ULL, 0x346C14380AD5DF44ULL, 0x2EBCF42979F78E8DULL, 
            0xFC029679A62378A0ULL, 0x8DC268B90087C974ULL, 0xB9C32E5E36EAEECCULL, 0x0351AE6D42A7E6C3ULL, 
            0xFA2E53FF9B2E851BULL, 0xB23132E4499DC7A7ULL, 0xA566F58809E43B55ULL, 0x43B61ECAD42C0EE4ULL, 
            0x0108CEA5BF5659C5ULL, 0xA5CED36BAFF3AA74ULL, 0x706365CDCB4F44CAULL, 0xE0EF29D6360DF6AEULL
        },
        {
            0x25B1ACC934E91CDDULL, 0x68BFFD6328B4EC63ULL, 0xA45977A0E41AC533ULL, 0x72F833B55B9E3D9AULL, 
            0xDDB3E82991431711ULL, 0x52A0C5DAA1DE6C08ULL, 0x6DBF2DAC46026F7BULL, 0xE15A409D13234EB2ULL, 
            0x6BF4D148B7F2BB3AULL, 0xD33E15366DA7E536ULL, 0x17222BB0E4B79AE6ULL, 0xC2AFFBF97AD9AAE2ULL, 
            0xC9485EEFB525399CULL, 0xF2DE1825F4A7EE9EULL, 0xF493656E8BCB2B2EULL, 0x1B11491A70DE4934ULL, 
            0x4AF84F01345DF441ULL, 0xA2C67D604BC2D3DAULL, 0xF3FF78AC268FA78AULL, 0x6ACEC3242AB7CCA8ULL, 
            0x4871EC12A41F4BA5ULL, 0x6B7EC85BDE6E86D2ULL, 0x7B9F8D0136170FCCULL, 0x9E47B314211A2DA3ULL, 
            0x1D83D2664664B69FULL, 0xFFC4EB12E27BC113ULL, 0x8B591607AF07FB40ULL, 0xD1A9ECF627E429F6ULL, 
            0x034D1EE8DAAE978CULL, 0xDE8386A9935CCD5EULL, 0x111FC692DBA2CA0AULL, 0xBDBB81E4ED30C3BBULL
        },
        {
            0x116E0086641C8D90ULL, 0x4942DD75F15040C7ULL, 0xAAA4D62B49DC2D38ULL, 0x3DFD7CF28165C9EEULL, 
            0xC145D467BB5689E1ULL, 0xA56122AC8BCF4482ULL, 0xED61CDDEE263724AULL, 0x1961ADD688A3E4ABULL, 
            0xA9A8A5FB5CD88E92ULL, 0x8BDD99D14BCE15B6ULL, 0xB93BB3975D05D936ULL, 0x0A33052EED419D20ULL, 
            0xC6DD7AF00A8E9616ULL, 0x53AA151E38F626B9ULL, 0x6B58954629569255ULL, 0x0CE3FE2515FA0BC5ULL, 
            0x7B53213A229456E1ULL, 0x32A327B49F0AB632ULL, 0x755D2D09A3288767ULL, 0x548178515C5330D5ULL, 
            0x5C39E268396865E1ULL, 0x197F8028A14AD479ULL, 0x255B4EBE5E431BABULL, 0xC9C1562B6F70FB12ULL, 
            0x4683478964D8CFCCULL, 0x5BCA1CA5400BFE3BULL, 0x3AC7945C11D0512EULL, 0xA31E716D2BCBB6CFULL, 
            0xD291A0C225BB3337ULL, 0x69D5EA91A77B765BULL, 0x59C44AE72A4BA072ULL, 0x8CCC0C11043F14B8ULL
        },
        {
            0x3E23D3752D891F25ULL, 0xF767917EE269B756ULL, 0x74B4C7DF3E8B7EF3ULL, 0x70D354059F5B7668ULL, 
            0xAD316EF21EA0A44CULL, 0x20AE5D7B0C29D252ULL, 0xD0173F193BFEA8EEULL, 0xD6AD00145AF1FFF7ULL, 
            0xBFC3E40987289E08ULL, 0x93DCE76C32DD5ED0ULL, 0x69CE18512B9DD867ULL, 0xE82980D4B9CEE796ULL, 
            0xD594251D7BED7942ULL, 0x5EC3217F242FD7F7ULL, 0x19C8735D0E95A32CULL, 0x17148F61CEEDEDF9ULL, 
            0xD70C6ACBF87B8083ULL, 0x859400675D8A79DBULL, 0x1622411A6E58104BULL, 0xEE611A36DCE83A94ULL, 
            0x770D781631415012ULL, 0x0607595CEC2F341BULL, 0x65B016667F6BC0E6ULL, 0x6DA454F4D6E321A2ULL, 
            0xD6A2F0BBA6F66F7AULL, 0x9CCC2C90C32A78EBULL, 0xD4CE836EE23A35A0ULL, 0xB34C2DA235AC1F4EULL, 
            0xF675E431D5EEC4F4ULL, 0x9D9658C9D6557980ULL, 0x09778434B9227534ULL, 0xB0601AC9ACB55EA9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseEConstants = {
    0x0BB994A4C0FD919EULL,
    0x7B84873156FF1231ULL,
    0xEFD5CE55FCDD7D4AULL,
    0x0BB994A4C0FD919EULL,
    0x7B84873156FF1231ULL,
    0xEFD5CE55FCDD7D4AULL,
    0x53328EBB8724D0B7ULL,
    0x63ACC914ADBE90FCULL,
    0xCB,
    0x9D,
    0x3F,
    0x05,
    0x43,
    0x2A,
    0x60,
    0xB6
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseFSalts = {
    {
        {
            0x60EA7DFA39C7365DULL, 0x1A181329D68BB827ULL, 0xDEE3DB5EFC4CEE3AULL, 0x73BA959C63AD1297ULL, 
            0x9C9172EF15125C01ULL, 0xA03A37DFA867F017ULL, 0xDE51FCACB10C4B98ULL, 0x1239963C153C8E78ULL, 
            0x3FA822849FF0A441ULL, 0x2353FB9475ECD8C6ULL, 0x6216AC3F93D49334ULL, 0xEB1ACEB5543D3DC9ULL, 
            0x98806DB75402923BULL, 0xEDA72F241166B202ULL, 0x1D5454FBA4C19F69ULL, 0x1DFCCE4B76A3BA2EULL, 
            0xB17F253821C9BC31ULL, 0xF27238D8A9FA09E2ULL, 0x4B436635C9DCA3D3ULL, 0x02785C8681C9A8CFULL, 
            0x0C73439D2CE83F11ULL, 0x4432A48BEA969CBDULL, 0x18FEEF8925A51958ULL, 0x76450D438D094FEAULL, 
            0xD53E1895789A5769ULL, 0x903C8D10CA3AFC93ULL, 0x01BC3FE27734E310ULL, 0x69E9E71C6BF6AD17ULL, 
            0x1FBF1FDF3F33C4BFULL, 0x488FA143BB8EE4A8ULL, 0x1528336861C0CBD0ULL, 0x44AFCB5070AB8930ULL
        },
        {
            0x7100AA888DE10797ULL, 0x6C5076FB12F5BBD3ULL, 0x094BE2636BB936FCULL, 0x28D2DA844A5B53D7ULL, 
            0xC3BC3C96B1B64E2CULL, 0xD7D680AE603BED2AULL, 0xD151F7BA2010A25FULL, 0xA6C584202B82A62BULL, 
            0xD801344B8A2D8DD2ULL, 0xD39744022173F9F4ULL, 0xA9C8C7E00582A7DEULL, 0xB98A78A76E5741BFULL, 
            0xFDACC66F43789DFDULL, 0x7B7CE7349CD6B8FDULL, 0x13BED45A62B7ACB7ULL, 0x9DEF77D75454368CULL, 
            0x833FC6BA59530EE3ULL, 0x730C7C112DA5E283ULL, 0x50A775D3BD33C924ULL, 0xDBFF6A69C1DDF53EULL, 
            0x9A0FCA53460EDF59ULL, 0x32A369659D6F78F4ULL, 0x05C683661891FEFDULL, 0x963057C07DD1D880ULL, 
            0x55FAC99E7408FED6ULL, 0x4995298DB0B3F962ULL, 0x91E24A4975D561D4ULL, 0x68E1B6CC76DFEE96ULL, 
            0x043491630D1D7446ULL, 0x57AD0557C76D5391ULL, 0x68F98767BD9632A8ULL, 0x8D3EA1C9ACFE56C7ULL
        },
        {
            0xE246D7E8FB27CBDDULL, 0x7B1DCEF1A4ED2824ULL, 0x51A23220BF612EA2ULL, 0x9D70149B79774EFBULL, 
            0xEF11D77D83282EAEULL, 0x783E119F1474449DULL, 0x2E82152AE65E3EF9ULL, 0x0B064E7CB2FD357AULL, 
            0xAADA429729138A27ULL, 0xCEE0F4584808FC88ULL, 0xB391C83E6C1CFA9FULL, 0x5B93D548EA30A7E3ULL, 
            0x356E35027C270113ULL, 0x60C0BF8A234644A2ULL, 0x72DE085E36C2E642ULL, 0x5F7E24C37B7D1771ULL, 
            0x0F545D0EA5A8DFCDULL, 0x2541701C0D1EEE27ULL, 0xA14FD3CEEB67EA16ULL, 0xA383DFA373D68B06ULL, 
            0xFAFAE6320E149BA8ULL, 0xCFF3C6DB7BA6598EULL, 0x075C0A64AE894919ULL, 0xD176B306A4F677EBULL, 
            0x65CC2C66CAB9E607ULL, 0x67086599C90EEFB2ULL, 0x2F6643EE1FA9C384ULL, 0xB81954E0DDA97C43ULL, 
            0xC2F1DB2E410DEAD4ULL, 0x5E859C168814CBC7ULL, 0x0B1887614D630773ULL, 0x8CF4C92CE99BB15EULL
        },
        {
            0x69D94C7BD8C5A9D5ULL, 0xCB94ED12AF8CA6F6ULL, 0x2F1A15C3A840CF1DULL, 0x155A5406EF3FF83BULL, 
            0xC12D11540D7566F2ULL, 0xE9DBF89E89CA94ABULL, 0x714C7525A05325B2ULL, 0x6210DDE9A990DBC4ULL, 
            0x270147597279EF84ULL, 0xC1C1F5E3C8A0E458ULL, 0x6E72371FE58E9C97ULL, 0x1AC93406382F1450ULL, 
            0x9FD7A9A630A593E4ULL, 0xE4EB57DA80EBDF6CULL, 0xBF71D00BA1BA02B0ULL, 0x1512618AC1739653ULL, 
            0xA8D552A972839C2BULL, 0x10CCA5EC6C0C66F6ULL, 0xC7E7A19A54ABDB4AULL, 0xFB688F6B4D924347ULL, 
            0x3F86D7C68BE0AEEDULL, 0xAE0D944DC4ED9C55ULL, 0x1C8EA383336C1A77ULL, 0x8D5A208087CCC6F3ULL, 
            0x3D833A1E8802EBB7ULL, 0x52E22ACED9FC95BEULL, 0xD944DFED96D20944ULL, 0x01B68C547308C836ULL, 
            0xE04DC91A78977F0CULL, 0x497C041120278451ULL, 0x4CDB28731775B917ULL, 0x13200ABD3DD5A994ULL
        },
        {
            0x139B4C7C59D2B436ULL, 0xA955962BE478F57EULL, 0x080C66D77A645FCFULL, 0x40E9EB27C91D21F3ULL, 
            0x770521C373B640D9ULL, 0x5B6F1D617AD5B50EULL, 0x6F7282D77CDC0432ULL, 0x53C86E3AC1BE8052ULL, 
            0xC040E97C80C4C296ULL, 0x6DC7805251240B9CULL, 0x8A449D9589324733ULL, 0xADFE2DB5718DCDF1ULL, 
            0x2B6BD873FBF7083AULL, 0x6031CE9181CCBADDULL, 0xD32E32CE58D7B3F3ULL, 0xFF7B9BAA2AFF40E8ULL, 
            0xDB3F733AFA883595ULL, 0x9B1E2C5B3A2A6C9EULL, 0x1C11FD741AF0ED07ULL, 0x4F773A921A2553B9ULL, 
            0xE59A52040C19177EULL, 0x8486ECB312B32BD4ULL, 0x3998B3528E950C42ULL, 0x1F3AFE6B167E48EAULL, 
            0xED8A5ED7120E7FC6ULL, 0xAE0560BF7551B8E8ULL, 0x62F65F2129E68CF9ULL, 0xB55AD3B35D079156ULL, 
            0xA991DAA241E300E0ULL, 0x8021F081703AE299ULL, 0x1A4DB71050879263ULL, 0x5B889307BC8F4967ULL
        },
        {
            0xD1DCA3E453394CC1ULL, 0x7FB84DEC0914E707ULL, 0xAFF2F9D21D051216ULL, 0x5C3CDC9402F27F11ULL, 
            0x1D0D7B390EA78C3BULL, 0x8FBA4D77C0E3A7E0ULL, 0xE52F37170AB0B001ULL, 0x49666E61C77C8FBCULL, 
            0x30471C769EC4525CULL, 0x2E1A88A1225CF9ACULL, 0x24DD433415776087ULL, 0x34D308AE507732DEULL, 
            0x5D33EA81E151EF30ULL, 0xDB2731F116FB3AB7ULL, 0xC3AC4DDCED32F485ULL, 0xC5E4A5A4032E5A3AULL, 
            0x0E9693FE9124141EULL, 0xFBE099C0000F47AEULL, 0x4593F62AEBE9B16DULL, 0x6AB99F38D7074132ULL, 
            0x81DA54D115CC2D32ULL, 0x5F2242F066703E38ULL, 0x87F75139610F790AULL, 0x969282915A884BE3ULL, 
            0xCB4DA246D55E6D8FULL, 0x60B194FD3F5FE7B4ULL, 0x629E578F0C4DB4DCULL, 0x9C6D3AA09143280BULL, 
            0xDC1E64DED466A9EDULL, 0x7AB77DA7F5C271EAULL, 0x7BC81E8C409390C9ULL, 0xCA66ABCB96D96353ULL
        }
    },
    {
        {
            0x1EAD7F33729AF473ULL, 0x8804601981A6A289ULL, 0xF522C095E4D4AA12ULL, 0xE1D2625C4C79CAD3ULL, 
            0xF7D3DAF66BB9BC57ULL, 0x828F1B500BD92324ULL, 0x9E2180F3D9F7AFF0ULL, 0xE51BB90F2D9933AFULL, 
            0xD64EAA6413F7DC33ULL, 0x89DE05C82B78ACBBULL, 0xB2666007E3F81D6AULL, 0xD4E3C5EDEA3FD7FBULL, 
            0xF28A4FE6D647118DULL, 0x057C0C837A8FF3BFULL, 0x16B4B92780BA0B8CULL, 0x18D428F43D929D30ULL, 
            0xE0EBC3211E08E869ULL, 0x59BFC5383823C6E5ULL, 0x9E7D4D832C78C525ULL, 0xA87CF4DA42DD831EULL, 
            0x485C81C538FBADC2ULL, 0x3A57C021A4AACEB4ULL, 0xF766DBEE6F6FB8B9ULL, 0x30519CAA3CE3352CULL, 
            0x943361ED374C71BBULL, 0xB71A3E11A8EC4938ULL, 0x0B5AFB52B475A912ULL, 0xDFCB0BD6214F849AULL, 
            0x0300B62ABE7D04A4ULL, 0xEAC766E917E3ECDDULL, 0x38EDE33D11A5A294ULL, 0x0DE7B8061A25C3A6ULL
        },
        {
            0x399C68771562CE27ULL, 0x40474EBC37508BF3ULL, 0xD4B4E3939D3A4226ULL, 0x10BBE608DFDD18E8ULL, 
            0x3F425B82FA26C9C6ULL, 0x4DF24DD431FF1A64ULL, 0x7CCBAB7C721CC8D0ULL, 0x0998D4D15C0DF499ULL, 
            0xA49EB84DC7FE02A5ULL, 0x4A4B6B6636405BE6ULL, 0xA8095936282EA37AULL, 0x02CA1CDE7F265454ULL, 
            0x1DA31D53CEF19D9EULL, 0x532759440410BA9FULL, 0x050D4D57A5EE7CF4ULL, 0x0DA41DD5B1633B13ULL, 
            0x7DBF51C633BF8CB7ULL, 0xF7F58AFC707214DBULL, 0x6744C4544F4E8698ULL, 0x7DC14AD584F1A7B8ULL, 
            0x202BACCCBD532816ULL, 0xDBE7CB6E4E9CE3BDULL, 0x2C83C266CBFB4B1AULL, 0xFBEAA82C59E6135AULL, 
            0x175C02F9EBF7FF20ULL, 0xCB0857CCC725BA1FULL, 0x59DEC891F4FE333DULL, 0xC060B14D3EEE5E60ULL, 
            0x4E2AD760BDA56410ULL, 0xD1F5B5A27C2B294DULL, 0x3D8383C9D9FD78AEULL, 0xD3E56E0D8D3B9589ULL
        },
        {
            0x35BFA5CA3174013CULL, 0x64C0229D0A514F38ULL, 0x62A04C80B12E1D22ULL, 0x4004086B852DFC70ULL, 
            0x5959440FE8808A41ULL, 0x0ECD85BE91481E23ULL, 0x5B54A78F859308B4ULL, 0xDF4D460498D2FDB2ULL, 
            0x3A2D03C4CCCC4D25ULL, 0x2F7A7706C4D8C393ULL, 0x5F7F9A4F2B48D751ULL, 0x5B70100AC94A631EULL, 
            0x18C3C8AF3CC4C5D8ULL, 0xC7B5EF4B8BDA2E32ULL, 0xB622742AD81E247BULL, 0x9B87AD3263F11772ULL, 
            0x41D5BF78877A8E01ULL, 0xA13789F8EBA9AE91ULL, 0x2958CEF3A8241A74ULL, 0x4919560C52526CBBULL, 
            0xCEB92A129128D365ULL, 0x6F85F04631313C9EULL, 0xE11ACE0F811CB18EULL, 0x06DED9FF042BFD01ULL, 
            0xD9F9CA652FA23D45ULL, 0x943F1A6016B72073ULL, 0xC2364B3B90270560ULL, 0x784ED77DE5709DD2ULL, 
            0xD8ED8AE480081A66ULL, 0x4283978D688D6F90ULL, 0xA61229DD1BB2A410ULL, 0x448F6A990BAFD0A2ULL
        },
        {
            0x1A589AD47A260A57ULL, 0x0F0656DE82C7D50DULL, 0x92F42D076BFB53F9ULL, 0xE6A16A18D33C97D1ULL, 
            0x1773EEDF40398135ULL, 0xB150754E90AAF1DAULL, 0xCA7332FC8B95CB1BULL, 0xD37DAECDEC9F8CB3ULL, 
            0xC44FCAB928D8DB10ULL, 0x97A5E55F900E30EAULL, 0x697E3A1A3C0CA14DULL, 0x1D3BB445FC38A7BAULL, 
            0x170F91CE5B08ABCAULL, 0xC0DF6357602E4116ULL, 0xE40B20259813434FULL, 0xFEADF4CED76266DAULL, 
            0xEC65CB4689601B53ULL, 0x81A7ED6C66F071B4ULL, 0x61D534125BCBCA8EULL, 0x8F43185F75105B94ULL, 
            0x25AEEC1E1065C6C9ULL, 0xA11A5FE1FFC08887ULL, 0xC1AAE340E2AE7555ULL, 0x97283E27617E35F6ULL, 
            0xF32E8076A6CBBD0AULL, 0x500650C984E07659ULL, 0xD30F4478173762B2ULL, 0xBC03BC27852B9B14ULL, 
            0x6779CAEFC73E5C16ULL, 0xC6F8252ED0D72025ULL, 0xC0927666D5611575ULL, 0xC2C7064FC48028FDULL
        },
        {
            0x604CB3AD6B483F3CULL, 0x573975DD4FFF265EULL, 0x8BFFE0DFF8054518ULL, 0xFE82EBC2F2A15A5AULL, 
            0xD3AC60C69D855B85ULL, 0xB3B93DAD742ADBA0ULL, 0x5F346C01320FC7C7ULL, 0x7D5DF8382959AB5AULL, 
            0x7D170033E3E5636AULL, 0x6F439627277FB871ULL, 0x5B296125FBB2AC0BULL, 0xD536433622D8F260ULL, 
            0xD6A16EF4C97D1EBCULL, 0xCEC91C1092B2208AULL, 0x1749424071811FFDULL, 0x4B03BBAF52EB3011ULL, 
            0x81B7D8A78978D3EBULL, 0x6022C2F99DB55AC6ULL, 0x3EB18D80DE63110BULL, 0x61D56028B741F0F2ULL, 
            0x19B77A5014F55812ULL, 0xEBCB96684BEC4CB8ULL, 0xC3835C8596A043CAULL, 0xDF4E4ED61789F5B3ULL, 
            0x49C36FF69E19530AULL, 0x28079E7B12DC9B0CULL, 0x0BC91B394E888C7CULL, 0xAA7AD6A085A2EB2EULL, 
            0xD9C7127857DDE875ULL, 0x33E2DD030930824BULL, 0x0FBEB5F74F933F50ULL, 0x44772A9CE91B88DAULL
        },
        {
            0x9AF0AC81216EDF78ULL, 0xBEF3A352F94CF5CEULL, 0x544117D2DE336347ULL, 0xB920E8C22C14BCA3ULL, 
            0x2CE9936B8AF82EB8ULL, 0xCACC702CA3BB7249ULL, 0x1DB7848067419F18ULL, 0x681E5648E8BDC222ULL, 
            0xEF25573F91FF77E6ULL, 0x20781AD82B02363FULL, 0xCD54DC95A45DAE32ULL, 0x4523451780506DFFULL, 
            0x06CFA0D45C1670AEULL, 0x3AB98D6005B9E6B2ULL, 0xC01FE417A84C36E5ULL, 0x3B7223ED4F9BA425ULL, 
            0x285189427B8E34D2ULL, 0xDEF3590276F917F8ULL, 0xDDE815986531AE7FULL, 0x09E5080C982AF57DULL, 
            0xD9040EAE0597C3E8ULL, 0xF4981F868FE2B37DULL, 0xBBE3FB5A234FE7E6ULL, 0xA1ED7C2A0E3D3D4DULL, 
            0x7ADE634D2C211F6DULL, 0x63ECCD67178B7E0EULL, 0x4CBA2995F9614E37ULL, 0x34992ACC3AD091A1ULL, 
            0x7E5BDDA2A979E93CULL, 0x2E5865BAB4D9492AULL, 0x67BB03F8AC3B7C26ULL, 0x027C62382DDD3C8BULL
        }
    },
    {
        {
            0x0D79DFF0B8E9FE26ULL, 0x6B4F54F1F2BB1455ULL, 0x66770403BC7DBD0DULL, 0x14D767E30173D125ULL, 
            0xBFEC85A4523A9856ULL, 0x215019D47E400A88ULL, 0x478E912B528394FDULL, 0x0E9A30023A9AE9E9ULL, 
            0x9CDE9F99F64707FEULL, 0xC3411927BD431CD9ULL, 0x8B9BC6B74F3C733BULL, 0x5DEFAD7261EA8A07ULL, 
            0x99BF7989AA2F6078ULL, 0xD5DCE85D6DE8D4E7ULL, 0x23835EC872F8611EULL, 0x8252944245F8A71BULL, 
            0xBA11343B75611849ULL, 0xBA928AC3A5C7AE97ULL, 0xA20D9ADA65B3C52BULL, 0x09AA691EFADBA10BULL, 
            0x21BBABF1179AE4AFULL, 0x2B11D2331DD0D31CULL, 0xC5ECD3A357ADFEDCULL, 0x31AB267632E1EEE7ULL, 
            0x3E7279777B01D3C2ULL, 0x4BC93332305D2AA4ULL, 0xAA2A0090831B7447ULL, 0xE30DE99752F6A2CBULL, 
            0x56AC6F0D8EFFEF00ULL, 0x3CC3D040F9C000ABULL, 0x92DDB7143AE6CBD7ULL, 0x728C565362A90ACCULL
        },
        {
            0xD3BF2954D543467AULL, 0x1B07E362C7F7E50FULL, 0x815D101865115D8CULL, 0x2D0D447231C76937ULL, 
            0x5D838D1F892631F8ULL, 0x722FED3E5902D93CULL, 0x3632D9D029F4389BULL, 0xF730A5656B84D7AEULL, 
            0x76FC0985FB051A94ULL, 0x2E89FE0C3BC67B15ULL, 0x960A3DD1ABC2EA82ULL, 0x0FBACB064B0DE880ULL, 
            0x176B236B29D2915AULL, 0x448437FCBEA6B838ULL, 0x5158A3AE82388B9EULL, 0x80AB810C05337A55ULL, 
            0xFB0F7B32CC06A852ULL, 0x66FE53CECA54DFC4ULL, 0x50533CCB3A3BC9B9ULL, 0x2659EBCFA26BD82EULL, 
            0x1375272D4170732DULL, 0x9B495F31BCF2FE54ULL, 0x47691C3561AA8E17ULL, 0x354A05107E6B29B0ULL, 
            0xBAFEA6E1F9951C2BULL, 0x03112E39D117D027ULL, 0xE5A30AB0F3A83BAAULL, 0x4A751CDCA3145432ULL, 
            0x8527A6335B62DD32ULL, 0x7DCBA12580889931ULL, 0x8B49B3DB4575D6F7ULL, 0x8AB92F6F93336570ULL
        },
        {
            0x9E1649EFD9F59089ULL, 0xD3AB544DAF4C698EULL, 0x6236C25E37B5896AULL, 0xB56A0E6162BF3CACULL, 
            0xA32DF0751489D690ULL, 0xC3F547DF270F05ABULL, 0xD68A9C800E82A6E8ULL, 0x688753B9D6A648ABULL, 
            0xAE8D750438ECD0A5ULL, 0xA07550A2B696C64DULL, 0xA0FC3856F13C16F1ULL, 0x813C16DF34236BC0ULL, 
            0x41DB710FBB0CA2FBULL, 0xFE4CA510FB858318ULL, 0x01D75DCC999D9BCFULL, 0xC87BCEDEDF3A065FULL, 
            0xEE7E3BB48CE06F49ULL, 0x369697874AD6C993ULL, 0xA4ECD12CE968896CULL, 0x177F9BFC340854ACULL, 
            0xA43F923E3E42C14CULL, 0xC27470B7EE8CA273ULL, 0x0A907A9E4C5304E6ULL, 0x74C4E7577EA39EF4ULL, 
            0xC6CD865A259520B1ULL, 0x41BC78527283E7C7ULL, 0xC93B441211B5EA5CULL, 0x2520DD7AC9E8FC56ULL, 
            0x58B419DDEC152DA0ULL, 0x2C5653F52CA721DFULL, 0xDCD757880BF6D3C5ULL, 0x8031A2CBC526B827ULL
        },
        {
            0x198B04D0EAF59BB3ULL, 0xA52CA28BDF9E6438ULL, 0x966D7A81F9E597E8ULL, 0x9823F1C30AC3520CULL, 
            0x85B27386DAB08399ULL, 0xFBD6199176295E10ULL, 0x8D5FB2CD01B0CD27ULL, 0x6397A15D50B1DAE9ULL, 
            0x3E11034D8C7D82D1ULL, 0x0DA8F6912F5568E6ULL, 0xF0C9E7E9CDE5C2C4ULL, 0xF023C8D1999BCF38ULL, 
            0x34ED7F35022E729FULL, 0x3CD5859BF863CDEFULL, 0x2C1E9AB056214C6BULL, 0x5C76999B382CCE6EULL, 
            0x1D208DF558DDE3D1ULL, 0xDBB7E20309143372ULL, 0x62588B319D530ACBULL, 0x5E8225BC27AD4F12ULL, 
            0x08A20DB85C4FDEDCULL, 0x8DCF36BF216CDF66ULL, 0x0639AA93C5B30FB0ULL, 0x423C029BF5B01B05ULL, 
            0x5B74ADB4DDB5F324ULL, 0x8670F2B39CD3F65BULL, 0xBE9557C0DB541EB9ULL, 0x59194D4797E68CBEULL, 
            0x57A2B67CC300DD3DULL, 0x0A7C31EB717E9569ULL, 0x48FDB6E444A5DA20ULL, 0xA3BDA4D5DDD2B116ULL
        },
        {
            0xBB808C9E1E9E971DULL, 0x8327163553D2BE57ULL, 0x844D68BE04453851ULL, 0x7AA5E554638C01BCULL, 
            0xAFE8B2735D45957CULL, 0x7CE5B7F7297A423AULL, 0x10A39EA7E32FFADCULL, 0xFC01BCBAFCDD7E00ULL, 
            0xB0533C85C38B7AC6ULL, 0x331032B4FBE836AFULL, 0xE906F5F67408CE00ULL, 0xF1C67A24B97EB078ULL, 
            0x08137EE285CEC2B0ULL, 0xE0856CCE7CBB2D18ULL, 0xC3C1F9669A5A9442ULL, 0x210F278896DA58E3ULL, 
            0x0C019FA264D6E9CCULL, 0xC32C5F7C83BF97F1ULL, 0x6591297638503D11ULL, 0x537270A21B033E82ULL, 
            0xC5233F36D56CB090ULL, 0x00558171FF8D977EULL, 0x4BE2DDBCA8238DBDULL, 0x8A91DD3AD72B6656ULL, 
            0x97F3D34615E04890ULL, 0x3D070DA472B1A809ULL, 0xC5E3DBCE4374D3D8ULL, 0xA4D1B206802DC1C8ULL, 
            0xD31964EDFA2D376EULL, 0xA265076A3BD07565ULL, 0x7716196770F44B52ULL, 0x35BBB0E567C215A9ULL
        },
        {
            0x18F9CAD2DB0D19E0ULL, 0xE6D9639A325C49CBULL, 0x2D33DC53E236100EULL, 0xABDF2AD097882639ULL, 
            0x225C55405A03F6A0ULL, 0x0291196782B89F94ULL, 0x12FD295EF81B9D4DULL, 0xEF32CA99118BF7CFULL, 
            0xF215EA94E8C4B08FULL, 0xD22EB763DEA72A50ULL, 0xE9853F55FB7B8A21ULL, 0x7308BE798A2FDCFEULL, 
            0x4FABDB89720E7506ULL, 0xEF1A06431473E2FCULL, 0x927DC045B3CF58CFULL, 0xB9E52B3CECCDFFA6ULL, 
            0xC325B16E9245DDAFULL, 0x2D59B509211EEEE9ULL, 0x1E92A4956A7F7059ULL, 0x708CE79E2DF364EAULL, 
            0x4887377AD688CFA1ULL, 0xA79B301DF2EC50D7ULL, 0xC923557FACA8E20AULL, 0xA8EDF8EFE6225108ULL, 
            0xBBFE8407AD58A1F2ULL, 0x613004AD7D88CF2CULL, 0x4547F4D57B4E2E6CULL, 0x2B58A674639555ABULL, 
            0x99B05843A9EC820BULL, 0x288B5E17AF096557ULL, 0x4B2F13A1E1C21703ULL, 0x9DEAE96A18E08254ULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseFConstants = {
    0xBAA63EC9B6651C56ULL,
    0xDA15657CEDEC7C90ULL,
    0x379D80185F41BB45ULL,
    0xBAA63EC9B6651C56ULL,
    0xDA15657CEDEC7C90ULL,
    0x379D80185F41BB45ULL,
    0x70595BAB04B276B0ULL,
    0xEF771CEEB4E94441ULL,
    0xA1,
    0xDA,
    0xE0,
    0xAD,
    0x91,
    0x81,
    0xF0,
    0x78
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseGSalts = {
    {
        {
            0x795D4AB931D4BD07ULL, 0x8A5C062BC6C8E5FDULL, 0xD521841DE8C002BDULL, 0x5F3993F06FD01DEFULL, 
            0x2FF692C8085502B2ULL, 0x265C525ECFA16AF7ULL, 0xAB1020B2F21D4A32ULL, 0xABEB0A24E3D74B83ULL, 
            0x431C01B9EB8EB180ULL, 0x736C56E5AE518B78ULL, 0xF0F5997D26E3FC30ULL, 0xE7CE57EFAFBCB843ULL, 
            0x43183414C31F070BULL, 0x10287ECE303CCA79ULL, 0x9AC017F622BB29A6ULL, 0xEEE300ADB0304D65ULL, 
            0x230ADF673875D864ULL, 0xE1E41EF9ACC45D3BULL, 0x3BF806985DE9AE5DULL, 0x3D0B6D2EA49B878DULL, 
            0x8DA5D202EDAADA15ULL, 0x20AD23E76111E512ULL, 0xE6C6074DF101D980ULL, 0x1B96D6F7DAA05F95ULL, 
            0xBF174C5CFE81C6B1ULL, 0x23D06599AC3C1EFFULL, 0x94288BF40CA0F01AULL, 0x9C09DECD46AE4706ULL, 
            0xFA7181821EA1C330ULL, 0x76D6830E4AF0ED21ULL, 0xE96F9AA4888D8FD0ULL, 0xE080E172C35C2842ULL
        },
        {
            0x432864DE3F535FFAULL, 0xCCC0F6395AE3AB60ULL, 0x8A37008EF190BB1FULL, 0xBBA37AB21F68638AULL, 
            0xE0566F152BC1A71CULL, 0xA59F5CED38D80CB8ULL, 0x5A9A460F49E76280ULL, 0x5DC368CD8B8CD5E1ULL, 
            0x06A39F787EDDE309ULL, 0x0F4B7C26D7D9B95CULL, 0x07C10FD0B14CC6E3ULL, 0xA70FD2B83F03E1B7ULL, 
            0xA586F195F89E18EEULL, 0xBFFDA66E47D1A561ULL, 0xF8449354B07259EEULL, 0x0AE601531E414A7DULL, 
            0x230C2F6B57739D8AULL, 0x8FA4368626C997BEULL, 0x967E86EFE17D4479ULL, 0xE04515D6B181F267ULL, 
            0xE51914B0A699A498ULL, 0xD6782EB15B4F275DULL, 0x6FB510B88147CE1EULL, 0x827503D7682961D8ULL, 
            0xD8CC68AAB9ABDE10ULL, 0x2A2A9342764BDADBULL, 0x2DBE5CC805C1C1E8ULL, 0x1790761D4210357BULL, 
            0xDF23A1C3109C79A3ULL, 0x3DC0FE114178864DULL, 0x40C041DFC682923EULL, 0x33FD49DB64CDF9F8ULL
        },
        {
            0xE9540A1E2503CA63ULL, 0xDD3E0656AF4BFE3CULL, 0x3EBDB68BDB7F6B59ULL, 0xDA2F007D1DC97CFCULL, 
            0x6DA6D5AD51A7763AULL, 0x25D844A046A6C66CULL, 0x02D5E2CDD78D3A86ULL, 0x9F53A6DD9B18826FULL, 
            0x49C362C4F060C637ULL, 0xCF86BE30BCA8E381ULL, 0xC7E1C3B24EBDB202ULL, 0xAFE465AE599144BAULL, 
            0xF411AE7FE50528A7ULL, 0x5DAF965CD4638C06ULL, 0x3660DCFA481C2A70ULL, 0x6CFD541786138B8AULL, 
            0x393BC797D4439F93ULL, 0x255A7CCD5ED89514ULL, 0xEC2592166EF11277ULL, 0x125308AC15DC2DDAULL, 
            0x1D9AD2D2B9FEB07DULL, 0xC243B4C06D5D4A63ULL, 0x0661500BB032FECCULL, 0xFDCB04FB0BB4FA56ULL, 
            0x2F9209FCB8CE2347ULL, 0x00B63D012490BF13ULL, 0xFE9BF21C480499BCULL, 0xD51F9E9D0D0B418EULL, 
            0x4A569BA23488AAB5ULL, 0x6F33A252E66093B9ULL, 0xA43861966E8F7736ULL, 0xC8BD645B2C8B3728ULL
        },
        {
            0xAFBF84861D28F519ULL, 0x6BCFDA7CD6F30FBBULL, 0x4C3DE180DCCD50B0ULL, 0x5D392DDC4774E2AFULL, 
            0xFB2AA4A5899AC73BULL, 0x881346F11D5BAFAAULL, 0xF608EADDA565FF75ULL, 0xCA4B4ECC08161759ULL, 
            0x54FCD4FA6CD3F795ULL, 0x83C6C34609912C77ULL, 0x8E515064FB062E22ULL, 0x29B7E5E4105A642AULL, 
            0xB4F845D2D180942AULL, 0x42A260EF52C185B5ULL, 0x955575EDB83A9BB0ULL, 0xFC1ED844D42B4FDAULL, 
            0x9AE9FAB1F90FA67AULL, 0x5211687C394E2D92ULL, 0xFE369838BB0A96D5ULL, 0x895DCADEBDB4BC20ULL, 
            0x661DB6C98ABF631AULL, 0xACCDD39346CBB56CULL, 0xB7CD0A649F2136FBULL, 0x6E0F0F84219C62D2ULL, 
            0xA14E9554D00B734EULL, 0xCB376BC5ACF37B47ULL, 0x368D5158DF523280ULL, 0xCB46CCD5EE23C1A8ULL, 
            0xC2297172817440EAULL, 0xB99B71EFA452BA97ULL, 0x8DC56E5DD1FC3C02ULL, 0x16BB2BCD1368AAD5ULL
        },
        {
            0xFF0DDD0E864D565DULL, 0x213514862ADE0482ULL, 0xC7ACBCA968B1DD35ULL, 0xE83E386054585A7AULL, 
            0x09F86FFB6680136CULL, 0xDAFB271B46F95606ULL, 0x335136530F1885BDULL, 0xE73AFCF193A3F198ULL, 
            0x6956A22A0E6808AFULL, 0xF9F6C1BF8473F06CULL, 0xA8CEFFCFAB8204EDULL, 0xB735BE0922CF1F58ULL, 
            0xB25E989A9426798CULL, 0x2F4AB96028E3BD36ULL, 0xC210FF0286B2B721ULL, 0x1090F3057C1BEDD1ULL, 
            0xC12CABCBB021A3F8ULL, 0xB2C1B793CF68B2A1ULL, 0x939A02E5864F85B4ULL, 0x22E2105FAC034A84ULL, 
            0xAB60DB9BD45613E2ULL, 0x2F31C2938954EDC4ULL, 0xA210A084E4C3587CULL, 0xEA60CF79897A2607ULL, 
            0xE408E0EF4803A31AULL, 0xAA66F532588AD42CULL, 0x2E8301709A3BC6FEULL, 0xD84C77CF69C43EFFULL, 
            0x1D145CB82B5F4860ULL, 0x68F2BB8B92E2040EULL, 0xAC9640E39D566021ULL, 0xB4095392625A4EFAULL
        },
        {
            0x2F803EB53FDA009AULL, 0x2BE12A9648BB97A1ULL, 0xF999351F767EFDEFULL, 0xB831D29EF8234C9CULL, 
            0x5E015DA62EBA7D4EULL, 0x8FA8C55EBA6F4E72ULL, 0xC40E7A87AB11519DULL, 0xFDA7A3CB638BBE0FULL, 
            0xDADD7F28832F5C04ULL, 0x77750EE6A7DEA545ULL, 0xDC0854D7A3957A10ULL, 0x7602A21DB98F9850ULL, 
            0xF3B87869CD26E096ULL, 0x36A2799828A4AEB9ULL, 0xD68721DA0E2B1933ULL, 0xC7F26C525E0071A8ULL, 
            0x254A305BCFD85F6BULL, 0x010FE7499C095A1BULL, 0x11235A8D7B61F95AULL, 0xA83EF1B258D02023ULL, 
            0x35E34D5A6FF45012ULL, 0x73524B93017003A0ULL, 0xCFC2F21B6BF126EAULL, 0xBF2D248618038067ULL, 
            0xD1F31FF804C0BABAULL, 0x62313E122A912467ULL, 0xA83105163DA84125ULL, 0x0E8BDAADE08EE3DFULL, 
            0xE8023823A0B70891ULL, 0x15BF854E7AE7F4E2ULL, 0xF283398979EAA4AFULL, 0x17519586269B641BULL
        }
    },
    {
        {
            0xFBE942EC9C5F370BULL, 0xBBE30F80DE5A3F67ULL, 0x392328D00DA54B9DULL, 0xEDABC0FB00FCB87CULL, 
            0x349A284EB7C4A060ULL, 0x0FA14F28E77C644BULL, 0xD86D0B9BEDA68B5CULL, 0x3747F441ECF566C0ULL, 
            0x4CE778EA055B0FACULL, 0xFA1064BF1D391863ULL, 0x7B21CD1B9A569253ULL, 0xC79397EB181A7274ULL, 
            0xFDF831D36178423BULL, 0x312FFC25A47CF624ULL, 0x6FEF4FCE6E296B86ULL, 0xD9C64775410C4244ULL, 
            0x5FDDE122BA8551E2ULL, 0x00EE3CDE702FD4B6ULL, 0xED0F95B104AA35BAULL, 0x3BEB288827BC92DCULL, 
            0xBCDC3CDD3A6A2328ULL, 0x2217822C7E0BFF5BULL, 0x48AA532277D1A804ULL, 0x67B674E1CCB430FCULL, 
            0xCFD2F87FBAB81B2DULL, 0x38E663F8EDFF877EULL, 0x17D77EF258853431ULL, 0x82A8A21D033D24A0ULL, 
            0xA2D46A0545B410F3ULL, 0xC4B59C31F6892280ULL, 0xF010E2B9C0C3C3FFULL, 0x25D07611D9D39301ULL
        },
        {
            0x4D59EE4B639240D5ULL, 0x14C34B734B3EBAE6ULL, 0x8B8898FF28CBED42ULL, 0x3EFA88380CE35974ULL, 
            0x3680D0A341E0C769ULL, 0xE8A89CDCC37448F6ULL, 0xA81EA38A18769F89ULL, 0xA4AB634A91EAFC00ULL, 
            0xFF10FAA83840227AULL, 0xC1E00EC938840D25ULL, 0x31E5C46729DCF8F7ULL, 0x5E0488B0BBE2D503ULL, 
            0xEEFED126215A5377ULL, 0xC66BBBCC4AB8CBBDULL, 0x7FF3C50B96014D68ULL, 0xF0E7B059E8594FCFULL, 
            0x6A0ECF650407AB01ULL, 0x1697FDF2D6D60C32ULL, 0x52DB31F72892A791ULL, 0x8394366955986208ULL, 
            0x009795EF6CDCCA71ULL, 0x13D0A2D0569FD864ULL, 0x340DEB89CB2A462DULL, 0x9E3890ABD339EE40ULL, 
            0xE461B4D7664386FBULL, 0x21BC212BBF658E99ULL, 0x7F2E3D25B450C7AAULL, 0xD7C487EAC91E1C52ULL, 
            0xD5E1094419D31B37ULL, 0xB911B1137B97D40EULL, 0xE6680A8697452DC7ULL, 0x4CABC6ABFA7FF045ULL
        },
        {
            0xF6AEAA5DB2EFA26EULL, 0xC7582070D24815F5ULL, 0x8DE04A2B527C3AC5ULL, 0x1D2979275725C2E4ULL, 
            0xD48B4848377F55F8ULL, 0x5F1FD908C9838AE7ULL, 0x307342F6D76DEE99ULL, 0x718BD2CD68515D63ULL, 
            0x95F84E2DAAA89CC4ULL, 0xD206110BF3015E43ULL, 0xE51EADBCF01DC94AULL, 0xE46FE7A13CF5670CULL, 
            0x2EEBE38A65AC7A3AULL, 0x00B71442DF8EE68EULL, 0x06EC1C1DE750015FULL, 0x06F623556E160344ULL, 
            0x9D0FDB82587A1EB7ULL, 0x3B83BF2500C3A03AULL, 0x4C1B68F790FA75BDULL, 0x1DDC6BD3FFADC0CBULL, 
            0x6EFBEE3C169A2279ULL, 0xCFB592D1457FD70DULL, 0xA12593BA9C15546BULL, 0x8E7871E094806F0BULL, 
            0x886EA7D650855E6FULL, 0x37FAE7DBDE500D1CULL, 0x613858E6437ACC9BULL, 0x145D6B6D4DE5B3BDULL, 
            0x8EF2BE1F9DF68033ULL, 0x5728B366EDAD8981ULL, 0x008058EB7D8D52ADULL, 0xF4FD184C38CA3B05ULL
        },
        {
            0x8F5C140328C68F83ULL, 0xF916E502A0811445ULL, 0xDFE67BA127B2DCDEULL, 0x8655C95B5367B102ULL, 
            0xBC51FED0E8E1B632ULL, 0xCB096A66F10A63FAULL, 0xA02D7937EA7E3655ULL, 0x77B17A209657146CULL, 
            0x2CFEE3537517F1E2ULL, 0x1DE75F0033CEF139ULL, 0x82424B1A92D0422CULL, 0x20088CA51B83594FULL, 
            0x5E3C8E90D5AC2152ULL, 0xC82737F8F6DADC69ULL, 0x925643AF0CA38813ULL, 0x87B8F2BB9413BF65ULL, 
            0x7C7DCB788FC1628FULL, 0x9A51036D7170E2BFULL, 0xA2C6E8147F0C30AEULL, 0xB57766B62B4B5864ULL, 
            0x2BA264238B53D1F9ULL, 0x350690537E40B391ULL, 0x79FC674ED48FCE33ULL, 0xE318C9227DFA7911ULL, 
            0x2B10CF6C4F337665ULL, 0x34B73D66EB3F4B6AULL, 0xA226349037832512ULL, 0x1F348E440567540FULL, 
            0x3C8AF56FB38E8B68ULL, 0x3F9D320E4DB35C88ULL, 0xD55B45DC179AE478ULL, 0x9D0A7E123EAEAEDCULL
        },
        {
            0xEB02F74187EF230CULL, 0x519074B27BC215BFULL, 0x801C9C23D3AA3BC7ULL, 0xFC76AD8E991094BCULL, 
            0xCEB61C3DBDDEA40DULL, 0xC4F472A143CC253CULL, 0x21B83A127ED03E72ULL, 0x905B35F3670B34DFULL, 
            0x63B25EC209EC860AULL, 0xB71905F5E2DBBAB7ULL, 0xCEFCA2AFC6B7AEBEULL, 0x8F723A95C08EA35EULL, 
            0x45C8471424C83764ULL, 0x3AEDA74D9C44E574ULL, 0xE1D4BE05A905B6D1ULL, 0x452AC3A11F9BF417ULL, 
            0xA7BD6E2290DDD885ULL, 0x82D24D5946089C02ULL, 0x8DF22642E4DE2FE1ULL, 0xBFF50E73EEF49068ULL, 
            0xA2FA0E7A0DF2C4F5ULL, 0x11C0824A78E37A14ULL, 0x7BAD36F74B30A5F2ULL, 0x7C0356F0BD676BB3ULL, 
            0xD2070E3281645110ULL, 0xCCB6A987F5C43A78ULL, 0xA943D51022A3A77EULL, 0x17E1F5CDFDC7798CULL, 
            0xE0CD518C892B1F10ULL, 0x2E365653D036F44DULL, 0xE8212B96B8D2D6D5ULL, 0x5B84DC50F4299C38ULL
        },
        {
            0x79D71B9A52EEEDEEULL, 0xC62E5143B25AD517ULL, 0x5352029316EE34B2ULL, 0xB661F11BD6465C50ULL, 
            0x4801CE6BB138F6FBULL, 0x69A3CFB7A02BA5A8ULL, 0x32A6365E8C1C5010ULL, 0x7DD05F82CC1599CBULL, 
            0xA294081C5D526B57ULL, 0x6541818D15E2E71AULL, 0x4361A5E775068466ULL, 0x4B024D6A15F14EF1ULL, 
            0x64B148EF88171609ULL, 0xDB645EA01CD2FA70ULL, 0x9C899B38D8E5DC82ULL, 0xE35E6F8C42726CABULL, 
            0x7FD45DCF56E4CFE4ULL, 0xDA2514F70FF1815FULL, 0x4A1F31BE15162D2DULL, 0x260045EDAA8933D5ULL, 
            0xE5B684D7F1B904ABULL, 0x8AE7D7D997383301ULL, 0xD0D34564BFA93CF1ULL, 0x70ED99A773D52420ULL, 
            0x023244B7DFC24C0CULL, 0x8236E699D0E6C525ULL, 0x198051F44E37E0A2ULL, 0x8BC1B9695E3D9F71ULL, 
            0x26ABE767240A2483ULL, 0xAD23FA53540F878DULL, 0xE97950BE988E9FA1ULL, 0xE706B4572A696B14ULL
        }
    },
    {
        {
            0x83F8F14DB55F2710ULL, 0x0C93A0E250727CE2ULL, 0x46273A701B2F113AULL, 0x132645AEF4CFDED4ULL, 
            0x2D69ABC4995D33BBULL, 0xD43E4B411AC23BC2ULL, 0xB73931DB48EE0E3BULL, 0x79A0EBF59B2D3EA1ULL, 
            0x4E706EE425DFCD5EULL, 0xF2EFE68BACC55220ULL, 0x71590149CB3523DEULL, 0xA14C159E6E815C6DULL, 
            0x172F7C988428A166ULL, 0x34B3A5512A99559EULL, 0x36A82EE0BBC042F4ULL, 0x8B80BD167B575834ULL, 
            0xD67D62C0F8B5ED3AULL, 0x47D0A48FA97D5E4AULL, 0xC0234C2D1D8CB0EEULL, 0xAA98E16F1CEA5363ULL, 
            0xA790EC7D79939D29ULL, 0xA7C12E16E58627F9ULL, 0xBD09F5542DAFBFA9ULL, 0xAA95C7ACFF78977FULL, 
            0x55ED7A34D247FEC7ULL, 0xAF7CE03E249FA187ULL, 0x2A661347FBEF2B5DULL, 0x043A576B88487070ULL, 
            0x10593B456DF2BA0BULL, 0xAF97D1C40F6C4CC3ULL, 0xD35DEE6B4BF85B81ULL, 0xAAA697EC294E1F33ULL
        },
        {
            0x93512FAAD62C8103ULL, 0xB9A7C14AB7C751FDULL, 0x5728E8A07196B1B5ULL, 0x6B2D2AD423944627ULL, 
            0xA3153421748648DEULL, 0xAC774B86022BDE92ULL, 0xDF184F97FDF6ECCEULL, 0x0D951DF0AA347CD0ULL, 
            0x37193B7E826D5F20ULL, 0xC3B971C1A5086E26ULL, 0x02060C2327771194ULL, 0xCD042DA1D169512CULL, 
            0x7EEF92D16BDE0383ULL, 0x406E263BB697E8FDULL, 0xA89AD0B3B6506216ULL, 0xBEE522A5E4127C6AULL, 
            0x38206C0192DEDD04ULL, 0x34037DB1E52E2E03ULL, 0x0C3A5EF80F890336ULL, 0x4036F4A22A0DFC65ULL, 
            0x7F4F42806CC5AB66ULL, 0xC35A09902DECD4D0ULL, 0x4CBB74171FE8CAC3ULL, 0x5565644729BF0D63ULL, 
            0xC76B6A0C5A6FD3EBULL, 0xEEB25EBD76686245ULL, 0xE84E9F6E73814532ULL, 0xF02F5171CB8C2137ULL, 
            0xA27C1F2DAB695FB0ULL, 0xF2C8D80987E69F7CULL, 0xCCF16F9D71C0DA5EULL, 0x0304BA6F3FB4A667ULL
        },
        {
            0x1ADF9CD821018F33ULL, 0x67831150938938CAULL, 0xC6BA62800CE4010AULL, 0x5B30CBDCFBD39366ULL, 
            0xAE903B2D6C846559ULL, 0x685309F81CA5269EULL, 0xA46E88F3EF5B92EFULL, 0x059988023C9C037DULL, 
            0xA9FA13E1A40111FDULL, 0xDF6CE66AA8487DF7ULL, 0x5541B49C5C70EB4DULL, 0x8CB363C19C1ABCC2ULL, 
            0x60233F5A791314C3ULL, 0x9146C327799985E0ULL, 0x1B97F6DF8194E031ULL, 0xE36C35EF4E9FDFA7ULL, 
            0x6955F0E952FBDA5CULL, 0xDB4ADC11CAE42CEBULL, 0xD951F87D2AA7774EULL, 0xC5AD967F747C5960ULL, 
            0x7B948E23CCC1D499ULL, 0x06FAAFA1BB1ADE43ULL, 0xD43D40DEDA8820F6ULL, 0x8F7312E0231DECB3ULL, 
            0x305867B82F82717BULL, 0x4F9FE38386D28A8DULL, 0x421678F45D95375BULL, 0xCA0B3078ED964D5BULL, 
            0x359BAF5C64CD93F7ULL, 0x41BBB6A51539652EULL, 0x9D04B0C0EBE0A324ULL, 0xF7BD541255AF899EULL
        },
        {
            0x3AC4AFFB9456D47FULL, 0x2BD678F600526EACULL, 0xB03488EA12004236ULL, 0xAE18B9BF26694A40ULL, 
            0xE7EFCCCCF10BA347ULL, 0x1514374D7067376BULL, 0x4CB076D087394BB2ULL, 0x134C95BF438A4268ULL, 
            0x8DC33619629CFC71ULL, 0x3803C2D9FBED3069ULL, 0x89820C15256693D7ULL, 0xBD49B34A44DCDB1DULL, 
            0x6A2ED6574A43441DULL, 0x57E52A0FE49124A8ULL, 0x123C9E0D08781C40ULL, 0x5D7AC66BC1304352ULL, 
            0xBA49026E3478DFF8ULL, 0x59AAF8C8999B9701ULL, 0xEF8DD038D61933A1ULL, 0xBD9886A38010D63BULL, 
            0x3ED59C921A8A1EFBULL, 0x9A04FBF97EBC4350ULL, 0x47E9CC631A89B4E6ULL, 0x546F16D53D5A3E6EULL, 
            0x751DF1F65A53811AULL, 0x6A041BF0CA2C95B4ULL, 0xE7A948C8B60BF3E8ULL, 0x52B4B7DBBB89F44DULL, 
            0xB88875F8B44D105DULL, 0x33B96174B37C0239ULL, 0xD0A8841F6479DF89ULL, 0x93DFFD587F5EE510ULL
        },
        {
            0x129F2D5B954C86D7ULL, 0xE1F331423082B2C6ULL, 0xAFD5491C530A6069ULL, 0x119CD628A78A5A80ULL, 
            0x5887FC83E1F6B46BULL, 0xECDCAD998F6549A1ULL, 0xD3626F98AE28C0EDULL, 0xAFC83D01AD4AB256ULL, 
            0x61882664264C3E50ULL, 0x73E4B2A057DDE750ULL, 0x7A286BA6D8C646EEULL, 0x03EBD0A7F7F028BEULL, 
            0x257FE208FFD96774ULL, 0x69CAF96189732583ULL, 0x6FC059D375DACF7BULL, 0x694B982FBF162214ULL, 
            0x6CFF89BED60855D9ULL, 0xD034A22D6A4E0960ULL, 0x3F40352C9F963D7BULL, 0x42F372D5F77288BCULL, 
            0xE53FECF120AEE3C4ULL, 0xD003CA131C813A21ULL, 0x36B79D667AED4065ULL, 0x8DCB7B1D80433508ULL, 
            0xD081D12C128A5D78ULL, 0x68D3D13FA67E4C6AULL, 0x502F818140EF3588ULL, 0x2A108CC68D77E9DCULL, 
            0x738A7AFFFEC8FF30ULL, 0x9F57AE2197D18180ULL, 0x90A7310C20CAB522ULL, 0xD6FB70B097447AE8ULL
        },
        {
            0x5A4F9B1F4B530EA4ULL, 0x3744EFDBDD64718BULL, 0x0D7BC2D171162EA3ULL, 0x753950C60408205AULL, 
            0x860A29D5599309C8ULL, 0xA3D391F399C070F8ULL, 0x9F3822CA70551C57ULL, 0x1BDD19429D453C36ULL, 
            0x3222033FDB14AF8FULL, 0x4A6FCD5A75B6BC8BULL, 0x3D1EB1460FDE5B3EULL, 0xF35533AFE4389301ULL, 
            0x124DC28EC9BB032FULL, 0x013B7BBC709CCB36ULL, 0x9A2377C11899D6A4ULL, 0x213C93826B34A416ULL, 
            0x7736E016CFBAB704ULL, 0x5814655DD000F4AFULL, 0x0A1A1F16DBB66DF2ULL, 0x43ABEB87EA87FC39ULL, 
            0x51A98C8ACBF5F5E4ULL, 0xF55EF035476F8C87ULL, 0x25D58134A430C409ULL, 0x38D3368AF74CBA46ULL, 
            0x3E7DB67C9E79BE02ULL, 0xD184483EF9392320ULL, 0xD5594658B380B226ULL, 0xBB3C7B178B48757FULL, 
            0xC055046ED18BE8FEULL, 0x938B191DBA726DCEULL, 0x2C498EE44EA59726ULL, 0x8ED7FF30715CAF5AULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseGConstants = {
    0x410E826953340E32ULL,
    0x74E27FA41406D298ULL,
    0x963726AE6AEACD4CULL,
    0x410E826953340E32ULL,
    0x74E27FA41406D298ULL,
    0x963726AE6AEACD4CULL,
    0xCE602AD7E9749DEDULL,
    0xE0F71C8B652237B5ULL,
    0x61,
    0x3D,
    0x44,
    0x57,
    0xB9,
    0xEF,
    0x6C,
    0x67
};

const TwistDomainSaltSet TwistExpander_VolleyBall::kPhaseHSalts = {
    {
        {
            0xA9AF0B981D7047EFULL, 0xCDDAB58D9B794877ULL, 0x62653F322136D3CEULL, 0xAE4C236284D37B67ULL, 
            0x52B223AD0E7F66F2ULL, 0xA57FE83962F79112ULL, 0xCC0BA1C069DF33CFULL, 0x307AFAC7B6B3926DULL, 
            0xFEA0C1C7F2A68B8DULL, 0x2B83898792959C4AULL, 0x000CC6905735096FULL, 0x5CABAFBDD4C1F119ULL, 
            0x390A6917E147DE17ULL, 0xC09E5DE2974445FFULL, 0x39447E2B78A641D1ULL, 0x6D9349F139128E7FULL, 
            0xDBE4BCBBF00FC0ACULL, 0x1EB84B8CF6F32249ULL, 0xE09A6931C723B008ULL, 0xDC5E558920CBF8DDULL, 
            0xC67DAC56A3DF843CULL, 0x1245EBDA9519702AULL, 0x393D74D48A0E7C93ULL, 0x7DCD3A53EF0F5EF0ULL, 
            0xAD5438C154373665ULL, 0x7F5F1D2548BD2224ULL, 0x7107119D20CF7060ULL, 0x2D240203023B15BBULL, 
            0xA4884E9C37AE053AULL, 0xF794B41089C67869ULL, 0x9B31A0EC768CC941ULL, 0xB45EBF0E590B4837ULL
        },
        {
            0x8C8A9F4B02BEA609ULL, 0x30A81B6B4D42D625ULL, 0xDCAB3E3F3CEBE6A8ULL, 0x1412870475C6EA94ULL, 
            0xFF1E927B8E330015ULL, 0x37B0D91381B756A1ULL, 0xFF555969E6F75321ULL, 0xA93F49A4B0F85314ULL, 
            0x38D23775DAB0FAFEULL, 0x0C7465A5858E3F31ULL, 0x7D34179D4C6467ECULL, 0x94D382DBA78D308CULL, 
            0xEFC7AC2BA589FE41ULL, 0xD1367CE84BE623D3ULL, 0xB7A417CAC582D435ULL, 0x44B9F8B1FEADEF21ULL, 
            0x01A80F5C554F7062ULL, 0xB5896928CCCA8D6FULL, 0x58A33452BC9985EDULL, 0x1E4718FA6DF747F0ULL, 
            0x21EEAE897BAD2903ULL, 0x2281F6579A84F418ULL, 0xB42694D5D059E162ULL, 0xC7F36582C55C03FBULL, 
            0xB298B629F6297CE7ULL, 0xEFC72BDD5C257BAEULL, 0x64389AD3EFA4D045ULL, 0xC05197FFE552862DULL, 
            0x251F072FA870F288ULL, 0xB14852275A9A615BULL, 0xB2764F91D2A8A0BAULL, 0xDBA103C4EEB61F63ULL
        },
        {
            0xE76FC6D47F16A288ULL, 0x634D05441D5920B3ULL, 0x3F85EEE931BE3826ULL, 0x13446F70DE2A83A3ULL, 
            0xF58E7D011EB8498BULL, 0xA65D26B636B5DC88ULL, 0xA3F921E623D9F738ULL, 0x5E890D1E8AE3630DULL, 
            0x5839ABA3348CDE8FULL, 0x0F951B07661FBA18ULL, 0xB14827C3BD73E4C3ULL, 0xF9AEDC30109906E8ULL, 
            0x88C4BB1AE8643D62ULL, 0x5A80DCE56D0EA93BULL, 0xAEDBA6B473B5C3B5ULL, 0x0C26AE59742EB525ULL, 
            0x1169577C622D0355ULL, 0x2AE33CFF506011FFULL, 0x48664C21BECC76B9ULL, 0x91F7C7589310FBD0ULL, 
            0x1991B4C475F90047ULL, 0xEDD339CF0291A304ULL, 0x733E4D91E4B58749ULL, 0x15EF538B424CC8ACULL, 
            0x21513D6B4DD8E803ULL, 0xEAC66696EDF8845EULL, 0x7042DA01C8BF788DULL, 0x82A7CAF8B6B1F7BCULL, 
            0x88F0F875326E3868ULL, 0x067CB89D1B06AEABULL, 0x86D60B3A9D6FC23CULL, 0x4B2E1A0BC474CC4BULL
        },
        {
            0xB5752ED4E6FC6F4DULL, 0x4C075AF6E7423FC0ULL, 0xCBB092A987C97F92ULL, 0x091FA98BF7820682ULL, 
            0xF65E3B32B513A7DCULL, 0xB0FEAB813330CD63ULL, 0xF806F2E9439360AAULL, 0x09F980A0704EA8BBULL, 
            0x6454AFC10C72EFFAULL, 0x958D02605BC82D97ULL, 0x7A41FB70E72AD2B0ULL, 0x1F7AD3289C87753BULL, 
            0x0DA067E2F14F341BULL, 0x279019EB36C6DF4AULL, 0x37CABF0DEA6BE483ULL, 0x538758A39ABF0DAAULL, 
            0xFDDEBC6A94D60DE9ULL, 0xA2C2411B78CC8778ULL, 0x8EB841BACA2E0B4AULL, 0x8CF008CD8C80200DULL, 
            0xFAD5685F11A15349ULL, 0x293C2D5A0B3A13CCULL, 0xA717C1DFCE3A05F4ULL, 0x97C6FBE910A32178ULL, 
            0x4853265AA5890AF4ULL, 0x372BF85F83427094ULL, 0xACD62761B2A844BAULL, 0x2655D6241A66D962ULL, 
            0xE3728BADE30AAD9AULL, 0x76C1605EAE5E9516ULL, 0x79CC79649263C979ULL, 0x944EC4DC37C7DDBBULL
        },
        {
            0x22EFB44B9B89152FULL, 0x5824D9DABEE0E67BULL, 0x36C12544C00DA2AEULL, 0x2974CC4A5E42B172ULL, 
            0x36DC014F63004EC2ULL, 0x383406E736E2F848ULL, 0xF1389242AC51B05EULL, 0x0FE5702D52C8D191ULL, 
            0x7456D93F3B6E8558ULL, 0xF836B71E82D10E7EULL, 0x37068861C7CD7CD0ULL, 0xD64A059A579E7A13ULL, 
            0x3FFE1177BB70CB40ULL, 0xDC0D73F59B32362DULL, 0x00E30E5D6796D0FEULL, 0x06BE9F745A351367ULL, 
            0x4AA753F9140E8971ULL, 0x0FE7F7A280D65E85ULL, 0x98C8B984A0B113F1ULL, 0xCEBBE5589EB12D5CULL, 
            0x5EEE893EE9D7D000ULL, 0x730129785874E266ULL, 0x5B921F878EDB1CE0ULL, 0x63E8150DF2F7531BULL, 
            0x0909537DD3D8C2B5ULL, 0x76D58B6947FD4602ULL, 0x909BEF8DED750939ULL, 0x0C5BE19B6D929E52ULL, 
            0x278710CBC5018A3AULL, 0xEFD1F3279A117E73ULL, 0x83747A78E0836083ULL, 0x558A9630646F2171ULL
        },
        {
            0xAEB4791A9572683FULL, 0x5B6C8D64255B4A77ULL, 0x23E0D480187A572AULL, 0x83B1CF0BF06A404EULL, 
            0x9D7ED0D1DC794700ULL, 0x2F7430F9847E7073ULL, 0x0E7072FD562E0461ULL, 0xC3C9A31930B9034FULL, 
            0x1FD392AA06E5B94FULL, 0x0036C28F645209F6ULL, 0xF60005DD7A76B5ACULL, 0x5A3F1DFDAF003D13ULL, 
            0xD12BD8E1EA5728D4ULL, 0x1FF35AB408C5C1F4ULL, 0x5A9DC3E4324663AEULL, 0x36132CC5D23F029EULL, 
            0xF8FD85361B6D835EULL, 0xDDDFEAB6FD345AE3ULL, 0x9433CE0281EF8121ULL, 0x6F59B4683F9B7ACCULL, 
            0xAF655CADA8A55ABAULL, 0xB543A9DFBF2EFD47ULL, 0x68BF29CC26792C45ULL, 0x1B53D0DDB0150D26ULL, 
            0x3BEB06ACD801D682ULL, 0x75416F994296A226ULL, 0x2CACCE08E4771A8FULL, 0xE5560BBF90229372ULL, 
            0x3AD8DB8F2E7FE9D0ULL, 0xE4402A2252DACCDBULL, 0xA16940E033890C8DULL, 0x30D2F3FD385A20EFULL
        }
    },
    {
        {
            0xFAFE97CAA5F5F6DDULL, 0xC5A8E8FFA106AD5CULL, 0x85B7E89D86D9F95BULL, 0x97B1F289997AA9F3ULL, 
            0x02D9EF85C5C3DE23ULL, 0x620E3E4B55AB31B6ULL, 0x028791AC8BFBD402ULL, 0x38344D3C1DAF92D6ULL, 
            0xB0A3DF305C8AB203ULL, 0x2C160C5C6F775A83ULL, 0x8C1EF3F4A19724EFULL, 0x69D02707E947A1C7ULL, 
            0xE213DBDE1B630B2DULL, 0xFE08F0D5A268F9D6ULL, 0xFABE77B5F2697C14ULL, 0xBAC0583EE72C6028ULL, 
            0x8D311784FE87BAD1ULL, 0x0F0CA2198918CA4EULL, 0xBC778F942F08E519ULL, 0x9B73BF060643E83CULL, 
            0x6BD32A5887EC8990ULL, 0xE1510A9D696D9475ULL, 0x36FCFB76F1966841ULL, 0x320F29EA125448F3ULL, 
            0x1DC6DE1BA9953164ULL, 0x66DB677CDE15B2CFULL, 0x7F277152F6B3CAB1ULL, 0xD4045ECAFDAD9332ULL, 
            0x66B6390E9E057B45ULL, 0x90D85C01A8BF1999ULL, 0x55395FB08FE74E7DULL, 0x1643DAFE4DDA3947ULL
        },
        {
            0xC79DD469AD715E67ULL, 0x18BE7CE848EA4805ULL, 0x9DED23D61C4E6133ULL, 0x3383C4552D36F8B5ULL, 
            0x795A89190481F7DBULL, 0xCEE5C30865EF62E1ULL, 0xF71CB687D804A0B6ULL, 0xAECCCAA7EF02DF22ULL, 
            0x11F5A7077E484C7BULL, 0x64899EAFC0BBD1E4ULL, 0x3624716C9E3A2D53ULL, 0x1713798DE312800EULL, 
            0xACC30A77FA95CC53ULL, 0xD5F12D719D1B64A5ULL, 0x5A73BECB4A2460A3ULL, 0xBDF395E133E6F888ULL, 
            0xF1770D7521679927ULL, 0x3305A9F1C0AC7A44ULL, 0xBBC1FD5554D494A4ULL, 0x9679CFD0BF721907ULL, 
            0xF6D7994FAD9EB0FBULL, 0xF25DAD3EDD4E483DULL, 0xE415A7061C46CAD8ULL, 0x0DC99A38E10D9224ULL, 
            0x5D9FA9DFCF86C0DBULL, 0xFD8FC5A1FE7591B6ULL, 0xB1D72786B60EA207ULL, 0x8991E9EB518546D2ULL, 
            0x5AE1A18E26AC95F5ULL, 0xDCD719EC26455182ULL, 0x2EFF46B20A61E084ULL, 0x3EA90CF6E5BD404FULL
        },
        {
            0x3ACA8DF6A846F4DEULL, 0xD4574002675F0F7AULL, 0x7B48F78F3B4A67C1ULL, 0x145289F96673457AULL, 
            0x3D6FCD4F2682E42EULL, 0xA224FE8CD1E0D22CULL, 0x54B4737E4025CD1FULL, 0x292ADBD49921218AULL, 
            0xE2D66916D8A78832ULL, 0x723EBD9430D21803ULL, 0x8836C0E6BC5FC58CULL, 0xCDCB2C97480F0EFDULL, 
            0xAE35162304C9E47FULL, 0x7F3B3C91F4BDC40BULL, 0x59EC3A7029A5D4C5ULL, 0x308C4AC0ED1E4ADBULL, 
            0xB416E767DF47F59BULL, 0x8B2C40CEC7DB5672ULL, 0x584407F40731B820ULL, 0x3FB050256C3DE5F0ULL, 
            0x6F410AF421CDCF92ULL, 0x47A16A0516F3B071ULL, 0x59FD1F14DCFCC914ULL, 0xD8091BDF75C9BDD3ULL, 
            0x61F72D5E58B05EB8ULL, 0x0158BDBCDF15BB93ULL, 0xFB874D246D32B8F1ULL, 0x19769B7BEA1F5217ULL, 
            0x8ED3B38BD48F96DDULL, 0xBCF05D27F32289DBULL, 0x71DA628A954B4BE9ULL, 0x66ABFFD35142FF61ULL
        },
        {
            0xCBD5A27F5BE72C76ULL, 0xC03E3B84B5C745CCULL, 0xB02C364C493C6736ULL, 0x0323520DB9A73FF9ULL, 
            0xA405474C898194D1ULL, 0x7F6F4DABB05C5729ULL, 0x1D2B120971A54733ULL, 0xE77DAA4DC5CEC0B3ULL, 
            0x3311F68F85F0EC1BULL, 0x05BB95A40C2C2BEDULL, 0xCB87B23409B75547ULL, 0x195F804347B80665ULL, 
            0x5672096E7E437C38ULL, 0xCDC11418A6F44DEAULL, 0x1A6F9D4C24DDEB3BULL, 0x5F344A75D85BE1A7ULL, 
            0x890FE4CB1C9AA107ULL, 0xC2662CA6F19F4464ULL, 0xD8CAA0AAB8194DE6ULL, 0x384CED66A375F8DAULL, 
            0x5013001F2D254F11ULL, 0x4825897329326908ULL, 0x187A927A1FA5EA3BULL, 0xE218F745C1669D7CULL, 
            0x39EE95679F6CD166ULL, 0x22459544FFA900FFULL, 0x7283824AB4885FA0ULL, 0xCBB2BD099AC99A0DULL, 
            0xE26414F5C9399811ULL, 0x6E6F3E209FAD012CULL, 0xB785A4DACE367138ULL, 0xA6DC0E36740D591CULL
        },
        {
            0x9803DE4B4FF634B9ULL, 0xCF88ED8CA2450CB9ULL, 0x6480DA54F40D02EAULL, 0xB37A6BB7E7E9CD0BULL, 
            0x41A7B700EDD0A8A8ULL, 0x27A4B891D970F50FULL, 0x2F48B1F3BF1CE99CULL, 0xD5B2A2CB617AF7E5ULL, 
            0x83F5E74B221891B6ULL, 0x4DC2558FF99B860DULL, 0x5BAE113475354DF9ULL, 0xB2B27102B15693FCULL, 
            0x1A44E28C0A8EAD36ULL, 0xFC4BA009BA46DEB9ULL, 0xC07586853EE5505FULL, 0x7DAE3ED67B15178FULL, 
            0xE78E39229836905CULL, 0x252354893221A0B9ULL, 0xD1DBADAE3A5E66AAULL, 0xE9ED5E28B788D8EDULL, 
            0xAA4E194E8839751CULL, 0x0BBAE119FA16610AULL, 0x66D2597AB14CE5E1ULL, 0xB5D7D3EBD4186A64ULL, 
            0x1233D4485652C028ULL, 0x1705B0DF2041D4B4ULL, 0x8D3F0C96C852CF5DULL, 0x724B6326B905FE3DULL, 
            0x931EC365AFFAA1EBULL, 0x587539724F67D993ULL, 0xCF4D7F52549343B7ULL, 0x69488F7B47D61C32ULL
        },
        {
            0x470F2DAB7F15CE8EULL, 0xDADE98F51EB70AA0ULL, 0x5ED6B7F1FA751668ULL, 0x58ACCB05B22A8736ULL, 
            0x4A5A9112CF70A37CULL, 0x7028CF54401B9AC9ULL, 0xB94717340FCE42AEULL, 0xAD44326840FC7764ULL, 
            0x359C12A7766567E7ULL, 0xDA5900799E3997DAULL, 0x490669517ECF6149ULL, 0x8278AE1D1767755BULL, 
            0x597391723C3A12A7ULL, 0x6FEAE53A441A7285ULL, 0xCC8C53FA7943F2E4ULL, 0x8C39213B5E4C4992ULL, 
            0xB39099BBB66D8345ULL, 0x074DA55E9C186810ULL, 0xB5181F10FBBF1682ULL, 0x91EBE53707A57AE4ULL, 
            0x88C28DFF0FD8C817ULL, 0xB0594FF1EE2915F9ULL, 0xD029F70AFB8D3E2EULL, 0x5D0127EA4C445545ULL, 
            0xC7CD2E72ABD20F33ULL, 0x9BB804CC71A25579ULL, 0xEEA2F6C76970D3A0ULL, 0x9FACA6D4989D4C8DULL, 
            0x2CB65CF68213ADAFULL, 0xA5F5EED341A12F36ULL, 0xA81040B7B7FCC14CULL, 0x3AE951EC123F7328ULL
        }
    },
    {
        {
            0xC5771A8655027B56ULL, 0x1F2AD91F77916DEBULL, 0x026BCF43E57468D2ULL, 0x65F9A9C734ECAF50ULL, 
            0x33CEE4287AC7A69EULL, 0x1FFFED58F1D21B47ULL, 0x8C0BB45DC6F83EE2ULL, 0x1BA1E284A5018409ULL, 
            0x8E9E73F609F8E55FULL, 0xFB848E0A58DD41D5ULL, 0x0F3C4F261A9400DCULL, 0xE0D53AACE20D9B9CULL, 
            0x5EB808DD703CDB7BULL, 0x17FDD8026FF82AE5ULL, 0x3D868C1D3E00DBECULL, 0x2C70976446EAAC19ULL, 
            0xF4EEB01726E7277DULL, 0x9FCB937D4F46FC4AULL, 0xC1721AF6DD89A3CFULL, 0xD04A2513AD41F42EULL, 
            0xD56D6661D3EA540FULL, 0x98DA13D0C8648DE9ULL, 0xF60C81A09FA1DF35ULL, 0xB7C043C68C663E25ULL, 
            0xB8A7D4B0DF14704CULL, 0x1C426A25559136CAULL, 0x29E48FE29A90A0F6ULL, 0xED33D85A6A66B3AAULL, 
            0xE0EC590B766F11DEULL, 0xDAEB1D090B7FCEE8ULL, 0x78F68B30BD184E48ULL, 0x439693498B26C519ULL
        },
        {
            0x6C3562885B323521ULL, 0xA0DAAB408E972D54ULL, 0xCEE6D8165DA2801BULL, 0xC27B661CD6BCF2DDULL, 
            0xDB0AAE7BD32CC8C9ULL, 0xE5B392C38498023AULL, 0x4488A3416369F3AFULL, 0xFD0A6B694B6B26A8ULL, 
            0xE6527700879F6F17ULL, 0x8EEFC4B1F25D119EULL, 0x7C69A0E0CE14947CULL, 0x2E9164D52D899999ULL, 
            0xD80E68EA6BFFD054ULL, 0xA3C17F661E456EF7ULL, 0xA9F6D07E0319749EULL, 0x07E1D07E85EFC94FULL, 
            0xAE0F74BAD2D19636ULL, 0x32FFFA04F3C99677ULL, 0x42A3D5625D807294ULL, 0x6532474835E890EAULL, 
            0xD2C1C38B897CBEA8ULL, 0xF27D20C6BE7E9F8BULL, 0xBDDD9234492E69BBULL, 0x412A8DD208EAA9CCULL, 
            0xE651C4558E13F833ULL, 0xEDB74ECEE484E772ULL, 0x36960577EC85368FULL, 0xA2A6DD0A02BF120DULL, 
            0x7CACA1F7B2EF6E74ULL, 0x802D5E7F88F40C45ULL, 0x5BBEE63E9D944A7EULL, 0x77984E4E1DAE7326ULL
        },
        {
            0x3FA5DC30C7754746ULL, 0x6D3D5E5F18E382CBULL, 0x620981BB83CF5F30ULL, 0xE39F3D9F38F55B8EULL, 
            0x0BB175F3344BE461ULL, 0xB8F1486F5EC1FA0DULL, 0x35B30D2F4A5780BDULL, 0xCD7E0AD0E7AA707BULL, 
            0x2337FF57DE307CA8ULL, 0xC56B3D908471E847ULL, 0xA24A7AA425CC00B8ULL, 0x4D4FB6471DC8AAD5ULL, 
            0xE61AF13DEB4F476DULL, 0x92D77217B013CD5CULL, 0x13A72E3F39FDF190ULL, 0x9CED1AD6A2636F0DULL, 
            0xA8C6F41CCA89E282ULL, 0x1C67FB73C6357267ULL, 0xB88151634605A91EULL, 0x82917F0166D00F33ULL, 
            0xD0E8A225F031B550ULL, 0x0BBF59584110243FULL, 0x87C27ADD84769350ULL, 0x4FB20A93187CDCB1ULL, 
            0xECF519D7BC743994ULL, 0x98449919A11DA009ULL, 0xA04F53CAC5A81646ULL, 0xECC357C6EE4B4CEFULL, 
            0x75FDE48A9478BD19ULL, 0x80E6B1C20716A308ULL, 0xAA74AA9699C3896BULL, 0xDF668CD9605A7673ULL
        },
        {
            0xA68498856E997113ULL, 0xEDD58E9994205707ULL, 0x8E8B9A5C8189D97BULL, 0x311C411DBCBB2651ULL, 
            0xBA46616A3F07252CULL, 0x4FB63BD58998029DULL, 0x40C1E2EE516BD4B3ULL, 0x313CDC9D90BC99EEULL, 
            0x11D494B76FCFD5DAULL, 0xE772CCE9C16905D7ULL, 0xF598450B67573D8BULL, 0x973A5C76569C180BULL, 
            0x4D0595268D7BCED0ULL, 0x4FAD66EF5B68B2C1ULL, 0x085A1FB56F3019D0ULL, 0x5F420914396BB710ULL, 
            0x1B3FDE968937FE6FULL, 0x436A77FDB9BCD6A2ULL, 0x587D15B3C5E49C8FULL, 0x75DFB62A22DD222CULL, 
            0x503AED42684FA6A1ULL, 0x4C3358197B4521B4ULL, 0x4D5C9C257E44E43FULL, 0xFDAD1A723C318DD4ULL, 
            0x20ECE37F383D9D0AULL, 0x2F49E8487B54E9BFULL, 0x447C09DD554F86A8ULL, 0xB93D0B6203F622DAULL, 
            0xFE6802EFB4EA29AFULL, 0x3402721181A7BF12ULL, 0x33A535E426BA95E9ULL, 0xA69361D1F1BB18DDULL
        },
        {
            0xF8BF370AAD7E6147ULL, 0xCA7971B42441ABEBULL, 0x09788D287A0EFFECULL, 0x18056EFCED7EBFB0ULL, 
            0x8AF4EF39EA34EC08ULL, 0x6D8086F205028EA3ULL, 0xA239DFB1963CC356ULL, 0x884C3FD2D2E3FCADULL, 
            0x81881875333D8895ULL, 0xFBE3309EE5BC3C39ULL, 0x3A30F0FAF8BB5FD2ULL, 0x3117138E1DB869B5ULL, 
            0x36CD0AA1290440B5ULL, 0xA8108B9078572090ULL, 0x939A0A67BA18E318ULL, 0xDDE12ED94A026E60ULL, 
            0x2DDECE64B5A75056ULL, 0xF8945772602EBD2FULL, 0x2C3102F00E8321E8ULL, 0x3E3451D5BBB57A6BULL, 
            0x4F30B8D16120E6CBULL, 0x8D70083B8A06C3B7ULL, 0xA61C5988FD3EAD99ULL, 0x06737335DC9A945AULL, 
            0x08AC4308BB3C4CA4ULL, 0xB3FD857B4EAF50A2ULL, 0x35D874EC0E8444F9ULL, 0xCD61950C00E4F64CULL, 
            0x1C095F74E88B41D2ULL, 0xBD0CF7F82341306DULL, 0x4D1595C0E6062CC5ULL, 0xDA04BD0AE9427C09ULL
        },
        {
            0x515A45666B924E0DULL, 0x47152D18F1C1FDFAULL, 0x68882E6ADD61CA6FULL, 0x7E648DBC3BAAF91DULL, 
            0xB08A640805607332ULL, 0xF3E39BA30AF99972ULL, 0x0BA728CB3B0DB97FULL, 0x19259AA003A59555ULL, 
            0x966CBB8BC088BD8BULL, 0xB9CC2FC02B221ED2ULL, 0x379691B8C7421C0EULL, 0xE225E5DC9A2AA867ULL, 
            0xFCC9067001A8E0FBULL, 0xCDA7B4202518CDC0ULL, 0x6D261D961C2BBE96ULL, 0xE98E845EFADCC7E2ULL, 
            0xEEFFFDB9A42FCC85ULL, 0xED91A5AF5F006D11ULL, 0x63F18A5E64E1D1DCULL, 0x33AC6B3295F55030ULL, 
            0x4556DD30FA1AA2E6ULL, 0xE1E96C6309D305CBULL, 0x577289AC5B008252ULL, 0x4102AA2BEA7B14CCULL, 
            0x47AD85159238C6FDULL, 0x26A7D982C56BE35BULL, 0x2E3A8E9C343F1BEEULL, 0xE3F1BC7FF1C69321ULL, 
            0x919362600F043659ULL, 0x07370374DE75303EULL, 0x4B41931B7A32A8E7ULL, 0x5622E9E164A41D2FULL
        }
    }
};

const TwistDomainConstants TwistExpander_VolleyBall::kPhaseHConstants = {
    0xA8D5C5B6CF206940ULL,
    0x0259E209DF42C325ULL,
    0x730CE051ED6F5F37ULL,
    0xA8D5C5B6CF206940ULL,
    0x0259E209DF42C325ULL,
    0x730CE051ED6F5F37ULL,
    0xB4EA1ACC2C152C02ULL,
    0x45E39F904977EED8ULL,
    0xE8,
    0x71,
    0x21,
    0x0B,
    0xBA,
    0x58,
    0x7F,
    0x9A
};

