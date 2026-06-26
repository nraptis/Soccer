#include "TwistExpander_Fencing.hpp"
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

TwistExpander_Fencing::TwistExpander_Fencing()
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

void TwistExpander_Fencing::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 15171179737478058150U;
        aCarry = 9900772707079829283U;
        aWandererA = 13708978037121067359U;
        aWandererB = 12308086508451717797U;
        aWandererC = 9837827963889203375U;
        aWandererD = 11981168986130270926U;
        aWandererE = 14434954350600257690U;
        aWandererF = 13979173381468156785U;
        aWandererG = 11500182743744615706U;
        aWandererH = 15144561868309137959U;
        aWandererI = 15002714412082831089U;
        aWandererJ = 14195084284912787340U;
        aWandererK = 11082895023265946605U;
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
    TwistExpander_Fencing_Arx aArx;
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
    TwistExpander_Fencing_Arx aKDF_A_BArx;
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
    TwistExpander_Fencing_Arx aKDF_A_CArx;
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
    TwistExpander_Fencing_Arx aKDF_A_DArx;
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

void TwistExpander_Fencing::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 17510907459713353896U;
        aCarry = 11846311001789249042U;
        aWandererA = 14623460889867722939U;
        aWandererB = 16949352427021165568U;
        aWandererC = 13428011668474165470U;
        aWandererD = 13173811726559322043U;
        aWandererE = 16195849812260178976U;
        aWandererF = 9972584285183635717U;
        aWandererG = 14692058341253160787U;
        aWandererH = 13818104564276282561U;
        aWandererI = 16351145439049982891U;
        aWandererJ = 18029748892092852880U;
        aWandererK = 11068887008170940238U;
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
    TwistExpander_Fencing_Arx aKDF_B_AArx;
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
    TwistExpander_Fencing_Arx aKDF_B_BArx;
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
    TwistExpander_Fencing_Arx aKDF_B_CArx;
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

void TwistExpander_Fencing::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    }
    // KDF_B PhaseA invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneB (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneB);
    }
    // KDF_B PhaseB invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneD (start)
    {
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseC invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneE (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneE);
    }
    // KDF_B PhaseD invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneC (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseE invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseF invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneF (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseG invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneH (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    }
    // KDF_B PhaseH invest aInvestLaneH (end)
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
    TwistExpander_Fencing_Arx aSeed_AArx;
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
    TwistExpander_Fencing_Arx aSeed_BArx;
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
    TwistExpander_Fencing_Arx aSeed_CArx;
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
    TwistExpander_Fencing_Arx aSeed_DArx;
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
    TwistExpander_Fencing_Arx aSeed_EArx;
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
    TwistExpander_Fencing_Arx aSeed_FArx;
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
    TwistExpander_Fencing_Arx aSeed_GArx;
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
    TwistExpander_Fencing_Arx aGrow_AArx;
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
    TwistExpander_Fencing_Arx aGrow_BArx;
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

void TwistExpander_Fencing::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Fencing::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Fencing_Arx aTwist_AArx;
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
    TwistExpander_Fencing_Arx aTwist_BArx;
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
    TwistExpander_Fencing_Arx aTwist_CArx;
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
    TwistExpander_Fencing_Arx aTwist_DArx;
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
        TwistExpander_Fencing_Arx aGrow_AArx;
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
        TwistExpander_Fencing_Arx aGrow_BArx;
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

void TwistExpander_Fencing::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 0 with offsets 8164U, 958U, 6151U, 147U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8164U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 958U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6151U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 147U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 0, 1 with offsets 7315U, 5254U, 4145U, 1892U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7315U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5254U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4145U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1892U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 2 with offsets 4126U, 6756U, 8157U, 4166U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6756U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8157U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4166U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 2, 3 with offsets 6900U, 2479U, 6043U, 6733U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6900U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2479U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6043U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6733U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 with offsets 594U, 1349U, 615U, 22U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 594U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1349U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 615U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 22U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 2, 3 with offsets 1102U, 1182U, 1916U, 337U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1102U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1182U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 337U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 0, 2 with offsets 70U, 1021U, 1996U, 1619U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1021U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1996U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1619U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 0, 1 with offsets 1369U, 1221U, 1395U, 442U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1369U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1221U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1395U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 442U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1972U, 1578U, 193U, 1362U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1972U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1578U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 193U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1362U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Fencing::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 1, 2 with offsets 4285U, 3751U, 193U, 7762U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4285U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3751U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 193U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7762U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 3 with offsets 5101U, 7910U, 2508U, 7899U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5101U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7910U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2508U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7899U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 0 with offsets 8043U, 7457U, 1720U, 1810U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8043U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7457U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1720U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1810U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 1 with offsets 6619U, 6125U, 4347U, 622U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6619U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6125U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4347U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 622U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 4380U, 1960U, 8172U, 4534U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4380U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1960U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 8172U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4534U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 0, 2 with offsets 1550U, 1260U, 497U, 1180U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1550U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1260U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 497U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1180U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 3, 2, 0 with offsets 226U, 474U, 2012U, 1095U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 226U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 474U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2012U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1095U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 1, 0 with offsets 1015U, 2038U, 574U, 165U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 574U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 165U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 2, 0 with offsets 1058U, 1243U, 1660U, 1599U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1058U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1243U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1660U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1599U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1782U, 986U, 962U, 575U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1782U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 986U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 962U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 575U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseASalts = {
    {
        {
            0x9D2E03961F525D11ULL, 0x9BE536F4B7CD8456ULL, 0xA47B9B7E892E0260ULL, 0x06E16EEFF125EF03ULL, 
            0xAB2A703A6498DC5BULL, 0x39C93284A4EB158EULL, 0x5320E44CBE049F4CULL, 0x73107CD297BF985EULL, 
            0x1D3870E616A443E7ULL, 0xC78CB07F8178BB6DULL, 0xFDDCB42855549DCFULL, 0xD5BAA084CF770654ULL, 
            0x05175DDD13E49952ULL, 0x98CECA1D57807D5FULL, 0x11C08DEC84E6403BULL, 0x455CB60FE128B0C7ULL, 
            0xA7E7839029CC1D00ULL, 0x4B706DB63567821BULL, 0x897CB2CF5EC62087ULL, 0x792322AD747F63E2ULL, 
            0x38B9D1D91104A2E6ULL, 0x856171CE74DDADBEULL, 0x31AF8CDF7D04E8B1ULL, 0xF718AFD258D03C9AULL, 
            0xA0F4834924BEBE40ULL, 0xC68C410AC00EE12CULL, 0x9AB437E033123E27ULL, 0xB279A44BC6EE4C4DULL, 
            0xA0D9BBA498FF1A3DULL, 0x0EBEF77AEE025723ULL, 0x26F3E70F1DFE3C27ULL, 0x43CE248B7F4E29D9ULL
        },
        {
            0x4538897F68EFC25EULL, 0x23691FF9A83E8B26ULL, 0xA2AE0262ADCB1050ULL, 0x2DAB58441319C334ULL, 
            0x6B87364A61B0A40DULL, 0xB9A425E873B3D2B1ULL, 0x4B4F350D051D5D18ULL, 0xD6364650F4196247ULL, 
            0x6CBDC32DAF3FEEE0ULL, 0xDAE8D74A516A8DA6ULL, 0x7F41669C2C623DF9ULL, 0xADBA3829EA285AFDULL, 
            0x42CA47FAFBD0DD4EULL, 0xE093218D1A1A0E13ULL, 0xA523D99B9A9BE314ULL, 0xC3D0A34F1DF26349ULL, 
            0xBA0E0CCBC0D15CF4ULL, 0x60682DDEDB049E01ULL, 0x3D56E3D6C9B8D9FAULL, 0xE895ED9786CB2ACCULL, 
            0x1D8B7ED7F004F954ULL, 0x9CA6945F5E511BB5ULL, 0xB8E62A492D223219ULL, 0x59AA1FFD428FB180ULL, 
            0x07A9BAF46922F70CULL, 0x34C7D7E57631F05DULL, 0xFB42DF35A5A67918ULL, 0x188B066862144131ULL, 
            0xA89334F7C44B1F65ULL, 0x9D1DD86053279901ULL, 0x6333B8B31F8B57D2ULL, 0x0026DC9692EBA40DULL
        },
        {
            0x04C22645F02BD54AULL, 0xDB00DE8638CBD93BULL, 0xE573FE303558AD1EULL, 0x85B2C3ABF2E99983ULL, 
            0x863E42BF3F84981EULL, 0x3A1C7B82E78085CAULL, 0x6AD97FD2D38370B4ULL, 0xC826F381E4B677CDULL, 
            0x4136E8DF3FEFA31DULL, 0x200934F2B586EADAULL, 0xB29F09B9CE637274ULL, 0x1806925673F560D6ULL, 
            0xF6ADC488B3689526ULL, 0xD83C16A252165D74ULL, 0x4235816AEC7A28BFULL, 0xDBC38C0CB993A576ULL, 
            0x5AB35FA3BC3D25A3ULL, 0x98D6599F0A5B932AULL, 0x6AD356815ECF1A70ULL, 0x4E6E4A22DC675EB8ULL, 
            0x3AA8DDB340317396ULL, 0xEF9053EEAB167810ULL, 0x6C541B9AA96EE5C5ULL, 0x3016D0F247440503ULL, 
            0xF565DF27203E0D72ULL, 0x87814A720B21D675ULL, 0x700D0B811E0DDEA3ULL, 0xF3E811388B038E16ULL, 
            0xCA5BD8C0DF1D0E14ULL, 0x84822D7F52286FB3ULL, 0x622EC699CA9792E1ULL, 0xD2D16D8F59B20F16ULL
        },
        {
            0x94F8416E34C61E10ULL, 0xC6F09679724CFEA2ULL, 0x22F1762C83786CECULL, 0x3155AB25A14645C6ULL, 
            0xD1E016AD321E7D8BULL, 0xFECDDB5DDF20C129ULL, 0x249A24CF771ABF8BULL, 0xA796FF250361E281ULL, 
            0xFDB297A7F16DE8B5ULL, 0xA276F9C94C68C69CULL, 0x95199C103C408436ULL, 0x2A11A412360E3262ULL, 
            0x104683908D9E1F54ULL, 0x9E09B55A8ACAE105ULL, 0xDDCE63E36CD28ACCULL, 0x15D340ED9970DB43ULL, 
            0xE875EE014DC8067BULL, 0x1F5A95571E359D1EULL, 0xB56B2584D2601F1EULL, 0xDEF672F5925CB8A5ULL, 
            0x39E662E287CB0655ULL, 0xD09197B6C2C9A736ULL, 0xBD12FCB0430C869EULL, 0x07FB0F0CCC467749ULL, 
            0x24F36CF1F6F87AE1ULL, 0xD1B24CCD89222356ULL, 0x00D5576A86C5CC8FULL, 0x06211A857219958DULL, 
            0x81B58D353C650C7CULL, 0xC55CA04F33E9DBF9ULL, 0xC539C220EF85056DULL, 0xF0B35815FCA0ED09ULL
        },
        {
            0xC89DC9A88BD47EFDULL, 0x90FCE95444F81238ULL, 0xDCD1EEA58E3F69F2ULL, 0x878D287556606D09ULL, 
            0xA160A532BBB8BD9CULL, 0xB2C9A0CCF78D37FFULL, 0xFE07909D1C44B760ULL, 0x02FE23F430E6FAF8ULL, 
            0x878897FE0DC4679EULL, 0x34D80ACD9B577DDAULL, 0x3A9CC2E3FB39F069ULL, 0x178A403DE8F801DEULL, 
            0x82676415F052DF87ULL, 0xB9CA8EA5C3A980E2ULL, 0xD2BBC6448831A909ULL, 0xE6224E22220BD21EULL, 
            0x4274EA853ACDC527ULL, 0x62F0BE5AEAD797E5ULL, 0x7F61BF5C5DD354C2ULL, 0x2A26406E2DF282C4ULL, 
            0x3412CBE1C7D102F1ULL, 0xDF5763ED93C12254ULL, 0x59368EE8EA2E4A1BULL, 0xA98B9DCFA0CC6FFAULL, 
            0xF1950550C011FD8DULL, 0x9CA2B1714C148F4FULL, 0x51795FE691993278ULL, 0xE6CA0D0FCFF6A67EULL, 
            0x21AE3D43FA51BFBEULL, 0xAEB43D53D671CC39ULL, 0x88588F08B5CD7522ULL, 0x5DCE9C1289D8A375ULL
        },
        {
            0x15FD807B71EEEEE8ULL, 0x3DACBB549CA55646ULL, 0x783353AA68D489C3ULL, 0x78AB283C6809EE99ULL, 
            0x650767283AA929E1ULL, 0x0D1B52F2E5422D30ULL, 0x4AD9008E9AACB074ULL, 0x17A25A5AF4028022ULL, 
            0x0B9ECF8B0908D49EULL, 0xF1C16E2517C6A78CULL, 0x0B83F6AB84398C0BULL, 0xBF5B0257F91BD48CULL, 
            0xBF611806209FE3E0ULL, 0x969421196DC35542ULL, 0x626C18FDF8F82C6EULL, 0xF2B8EE06849D47FCULL, 
            0x73ACBD6B28F748D8ULL, 0x20783D6DB56F29ACULL, 0x7D7E84B95352B749ULL, 0x4D485A4D8FC4B906ULL, 
            0xE1A15F791BF20AD2ULL, 0xCEEF965A9017B716ULL, 0x34C8104BD8850B94ULL, 0x1785D0925C2EC83AULL, 
            0x9A8FC73610ACB767ULL, 0xB33DBCD02F4FCC7AULL, 0x2C28184B98DF843EULL, 0xF9BE33F5186D27B9ULL, 
            0x529555C32C67472EULL, 0x3E02A43DDFC711BDULL, 0x368FDA5FA0E27D5FULL, 0x20FA5F47CB98FCFFULL
        }
    },
    {
        {
            0xF7DD365AFC79F7F8ULL, 0x052E05960C150F4FULL, 0x39494279D3CB7A4AULL, 0x36F7EC3A68E0DD1FULL, 
            0x90D93B9548230D3BULL, 0x133B82E73E736211ULL, 0x47414AC7E2B1A25DULL, 0xC75CD7A85239FA15ULL, 
            0x1DBC36EB47B97420ULL, 0xA91260647FFE6815ULL, 0xD652E47D50491592ULL, 0xE2B7E1187B5F040FULL, 
            0x970B118AD0FF0DFDULL, 0xDA210FC8A50831DBULL, 0xAA99422AFB97D527ULL, 0xEEEC652ECDBC84CFULL, 
            0xCA430A533406216CULL, 0x25728203FF8F3B74ULL, 0xE14B17E8581D9C9BULL, 0x11E685B643A4A51CULL, 
            0xD0D15EA51C98B1D0ULL, 0x21A8A78C4DAAD030ULL, 0x16902141755E6BE1ULL, 0xF7E632F3542E694CULL, 
            0x3FE8BF7728E6A985ULL, 0xFECCEB6E0030EC35ULL, 0xDE1DDB18A4D40291ULL, 0x2642271D452AC30BULL, 
            0xE8B4991618B56A5EULL, 0xB73AE5BCD9BB9C5CULL, 0xB2F763332B3C8E3BULL, 0x5DA7F582CC754C06ULL
        },
        {
            0x573C8D6CFE5105F8ULL, 0x15D4197EBC5D4907ULL, 0xF1926AC35B2916C4ULL, 0xACCE8940B5D3FE2EULL, 
            0xAEE7BFBA18C3635FULL, 0xED667EDB8B6D81E7ULL, 0xC3E68312E02D1356ULL, 0x65A9EDDAAEEB9495ULL, 
            0x8B68EEF3BDA66EFFULL, 0xBCAF9E195F30412FULL, 0x27A8441600C9E3EEULL, 0x3E94EEE53A00B952ULL, 
            0x51F9CA776EDA2D27ULL, 0xE5E3AE6B81606C51ULL, 0xE83D87F526CBA592ULL, 0x1F1A2DAEA620F477ULL, 
            0xC28B5E5544794CC7ULL, 0xA09F39476A83A429ULL, 0x88CB22EF7CAA3E97ULL, 0xC1DA790487B4995CULL, 
            0x526E2047CD8340F9ULL, 0x0F783E8637ABA7EBULL, 0x5264F3D74BA0DBB3ULL, 0x1B13CE33FAB188E0ULL, 
            0x2B196F895B9C029EULL, 0x227BF9E2E4E94EF2ULL, 0xC0EA3118C66ED6ACULL, 0x08F9E435A28D0EB1ULL, 
            0xFDF7FDFD94BEBDC9ULL, 0x8E603D47206D3EFBULL, 0x40BF500F004BB55BULL, 0xCC08A631635E3BDCULL
        },
        {
            0x3FC85118E06CCA0BULL, 0x1C7F0FA0778E0843ULL, 0x15C075684044C05CULL, 0xD0E4111FBE4F24B3ULL, 
            0xA5ADFCFF1B9C4626ULL, 0x6E950D4A09BB90D4ULL, 0x0E2EB985EA659CC7ULL, 0x6753928AA23B6590ULL, 
            0xE9761FBDBD9F0B19ULL, 0xF8A4000E04DD6B20ULL, 0x532579DC14670717ULL, 0xC8AC0563EB666293ULL, 
            0xD752BB6D55E09A59ULL, 0x40B50AD8B58B2B06ULL, 0xD1286F93C3A00AA2ULL, 0xA0B778745FAD2493ULL, 
            0xA6F36252AB1D6DAAULL, 0x8E138B9A452540EEULL, 0xAB290BF1E219A453ULL, 0x623B3AD9BA27D65FULL, 
            0x7EE32CAC4DE3864EULL, 0xC996E5ABDFF7A8E2ULL, 0xC1B4888C8A45473EULL, 0x22AF144365A45041ULL, 
            0x0D335659B7E78A55ULL, 0x0166B1A06EA472C4ULL, 0xB058DB9463DBEAFBULL, 0x6E11462BB4696A74ULL, 
            0xB98FB411202FCB25ULL, 0x17C987128ACC70FDULL, 0x6A298C1D08B601CFULL, 0x14A1871AC83EF718ULL
        },
        {
            0x76C80E15BD94E587ULL, 0x418125A9DE2EF880ULL, 0x45427A64A31F669DULL, 0xB626BA3BE17A1562ULL, 
            0xDAFE4A9D8FFEA253ULL, 0x26CFCA8D8A8D8B2EULL, 0x871E8C8FA4CAD174ULL, 0x022848B4A862EBFEULL, 
            0xA1D27667DD0E20E9ULL, 0x10C5C4523A8E5768ULL, 0x948C52737C37E3A4ULL, 0xA15E00AC3AA0D8A7ULL, 
            0x45ECCF5180C900A4ULL, 0xC40C50D5770CF1C7ULL, 0xB61DE07D66FF9174ULL, 0xE7E4747CF337F233ULL, 
            0xE884505FB2F5DE74ULL, 0x4BCD10A36DEE3AB2ULL, 0x7FC975D60D0EB0ACULL, 0xE67A7C9A5822501BULL, 
            0xACB5A786C4C93DA8ULL, 0x31772233F2AE9516ULL, 0x26B460044DCE015FULL, 0x4A03BB9F44E7A853ULL, 
            0xFD35A8304E14D918ULL, 0x5142116C0DD1F17AULL, 0x9BD65E6BCD818CF9ULL, 0x1CD3DA1296C1B285ULL, 
            0x280B0044C223CE5FULL, 0x0F04916BDCB0B913ULL, 0x158E90760978810EULL, 0x16B382E20863B27CULL
        },
        {
            0x1B82881605E4A673ULL, 0x6BD927B65096C74AULL, 0x592FE5C41F394FADULL, 0x21DB778D61DDA127ULL, 
            0x86AF53EC242CC491ULL, 0xA25968BC6A3D9A8FULL, 0x4BAF087599EA7B93ULL, 0x3417DB59D8933C99ULL, 
            0x6AF66225EB07EE91ULL, 0x52FF6B664AD9B65AULL, 0xAAD9A6FC6F7FD852ULL, 0xB12046FC42CF2171ULL, 
            0x1C1711B66266893FULL, 0xE664C24771E90FE5ULL, 0x0D3D9C288F47C788ULL, 0x33BA72DB34E367C5ULL, 
            0x665181A18836D882ULL, 0x6DD9598EC7CAADAEULL, 0xF11194D56057E698ULL, 0xE24247C1307CC654ULL, 
            0x3D4C87C597CEBB05ULL, 0x31AD7D1CDDED0F61ULL, 0xB0ECA2511A3D12AAULL, 0xA6E582273E83C466ULL, 
            0xC7FFB334BC437B54ULL, 0xCF08F9E388B4F2B1ULL, 0x6168CCC837143A02ULL, 0xCE69273DE6570099ULL, 
            0x687D8308FEC113DEULL, 0xBB98C4B95DEB8194ULL, 0x079C89149781B019ULL, 0x091D0DDF7DB471A1ULL
        },
        {
            0x9FE611ADF658B2F3ULL, 0xFBA72A1A6F2401C6ULL, 0xAD1708361464981FULL, 0xE07830B8730FAA70ULL, 
            0x2BE9EF467737EA9CULL, 0x740DA9D05A672320ULL, 0x9D462AE5DB846DE4ULL, 0x3DB272CAFD241207ULL, 
            0x958F1488B80F1CB7ULL, 0xC0FCCA34490310B1ULL, 0x7EB83B8DE18A6399ULL, 0xF0ED242C947179B4ULL, 
            0x1F6B5885F872A118ULL, 0x607D8AE86C8C0A9AULL, 0x7C8B92405116B94AULL, 0x61543AF36E1D7345ULL, 
            0xB296EAF86D74FDF1ULL, 0x621301AA41157F7BULL, 0x3D7EBD5839D1F51DULL, 0x655D6636FBE35533ULL, 
            0x87E4990D2B641BCFULL, 0x2A5F9BA7822080DEULL, 0x99CFD1A27A4FB588ULL, 0x955E586FEA0F3D77ULL, 
            0x0F6A2CDCA3EE5E56ULL, 0x513DA10CB1AF57FBULL, 0x824CD12C5E3DD17AULL, 0x622C9B9FADDCB571ULL, 
            0xB508CF476E880F3CULL, 0x5CD44B649AF37879ULL, 0x46DDB98863409A6FULL, 0xF0C4A10A1D4D3D96ULL
        }
    },
    {
        {
            0x5DC2A6FC4FBC8AF6ULL, 0x9F4947311678770DULL, 0x00B47F65CEF27239ULL, 0xBF53CC9E1B0DBB5AULL, 
            0xDC4FD7F34638975EULL, 0xF757AF49DC217078ULL, 0xB5B3F58688BD797EULL, 0xF27064384EAC3AA2ULL, 
            0x6C36433C410F3F4EULL, 0xD2D34394BD22FC8AULL, 0xAAF8E20724BCAA78ULL, 0x0B997FA83DF9912FULL, 
            0xA854FD716906DD67ULL, 0xE02A2030A8CD9757ULL, 0xA9E8A369A855961FULL, 0x19671525C4E5DCCAULL, 
            0x857F64C0C2775F20ULL, 0x08A9AFAFEB47C71AULL, 0x83348909C96AEEC4ULL, 0xFC4AD805F476A357ULL, 
            0xCA4B698988C7800FULL, 0x4811F789B4FF671BULL, 0xE4F3FD7145358370ULL, 0xFBB6C76B2681EC3FULL, 
            0xA2AC5B7F4FE49C5DULL, 0xDE8FF9380E4207BAULL, 0x45903EA9C1D6883BULL, 0x750875DFC61AF539ULL, 
            0xAE90D5FFB61348E5ULL, 0x877101553BAD1BB2ULL, 0xDA6F55890867CCFEULL, 0xA485D9E74F81B41EULL
        },
        {
            0xFBC4FAD8AEC523FEULL, 0xC07DBD483DF42B05ULL, 0xBAF93AC60568147FULL, 0x625687830D84B607ULL, 
            0x15CAF3A5EF456C04ULL, 0x85398C6D9A19562FULL, 0xC340A07C515DA4BCULL, 0xA7949D6C342A4064ULL, 
            0x4C30348BD7BFF2E7ULL, 0x6D7A3E63AAEA7DBFULL, 0x15660690DC52FDF1ULL, 0xFDD32073FCDE2473ULL, 
            0x5BC465256D177793ULL, 0x137D4EF589C373A5ULL, 0xAB36C65A529EA890ULL, 0x3BB2C0C5179A61AFULL, 
            0x8D88882D85AC0E0CULL, 0xFFA9262CA86E0D6CULL, 0x520A97F9A01D3E32ULL, 0x3B85B31036D7E554ULL, 
            0xD60AAE91A58E22CEULL, 0x1123A49224CA644BULL, 0xE4CB101E068911AEULL, 0x268B0A3E7E0E3144ULL, 
            0x7120F592596B49E9ULL, 0xB0DED55A8679FB14ULL, 0x764BE027D1D237CAULL, 0x3CB4C91ED3FF2ED4ULL, 
            0x3EDDEF1FF6C248CFULL, 0x9867A56643E5266EULL, 0xA12431A8337C847FULL, 0x4DD39ED192E8E12AULL
        },
        {
            0x052BB8BBD8B131C4ULL, 0xBBB17191033A70C2ULL, 0xA25EC43B3F977C40ULL, 0xD4D0D2F12E860B67ULL, 
            0x350B22518E830B86ULL, 0x02A9DCD45C53B625ULL, 0x1E393ACCF2191BA2ULL, 0x5E85345BFC2B1282ULL, 
            0x075D068662CE1160ULL, 0x8450F3A0BFD81361ULL, 0xC21B3F2125C514CEULL, 0xBD899997CE9B644FULL, 
            0xF103BFA4069006EBULL, 0x7B8323E42451E902ULL, 0x58FBFC7080641FCAULL, 0xB22D89FFCCDE1630ULL, 
            0x44E1DE2F877101C0ULL, 0xD0B85C18C923CBF3ULL, 0xA828263B0C097F3AULL, 0x22A27BD7BF6E9750ULL, 
            0x5F7D1B7147730EC0ULL, 0x0C4030F95F1BF2E7ULL, 0x435433498BEE419AULL, 0x4335B5CAA459C669ULL, 
            0xC77BE60D8F15B022ULL, 0x734C7326B47C4D2EULL, 0xBFD6074DF02C85F8ULL, 0x02EA17D450789705ULL, 
            0x14CC47A95B0A8171ULL, 0x663C71839B88BF3DULL, 0x119C42E09BAE9F9EULL, 0xDE5EB314605239ECULL
        },
        {
            0x1B24D888FE66D1FEULL, 0xCE83D6C6DB0131B3ULL, 0xEA89E45A235C93ABULL, 0xD911285F14712EE2ULL, 
            0x6BFF6A324C817E56ULL, 0x97F201D6254D2FE2ULL, 0xCF812EE967996A78ULL, 0x1321DFC91CEEA0A5ULL, 
            0xEC96DF7FCA2B3ECCULL, 0x01097CB6C1D8BF84ULL, 0x33D1E371046DE807ULL, 0x541653AD87086F6AULL, 
            0x3E4C38C2F8B545BEULL, 0xB9B09E42B10A1F99ULL, 0x9104BCCB2597AC72ULL, 0xDBC83B1D61E8CEBAULL, 
            0x0CA8E1F6D5DC04EBULL, 0x4F89808C13797AFCULL, 0x4006B42CFDB755B4ULL, 0x887A4B5A2AB82F51ULL, 
            0xCC29352983344E05ULL, 0x8122B3DE05C65D99ULL, 0xBC19C5890FE6ACAAULL, 0xA16AC08550479156ULL, 
            0x9A0578B17E42FB34ULL, 0x3727CE76867156F2ULL, 0x56E0614F8206A51FULL, 0xCF4923A27C891A3CULL, 
            0x2B6C9BF0AFD2B58AULL, 0xE086FC9C2DDB33EDULL, 0xE4C33F0A7905B14AULL, 0x3EC61910D278D1E0ULL
        },
        {
            0x88D497255F55F1E6ULL, 0x793569315DA23122ULL, 0xAA357CE2E77ED008ULL, 0x84017AB970A2CCB9ULL, 
            0xBC019218CAD3F4D2ULL, 0xEE8C3C6741C6AE89ULL, 0x1B983C56DD7DF1D5ULL, 0x238F17730EDD9BF8ULL, 
            0xF62D7EE3DF0A7CA5ULL, 0xC643544E48438F70ULL, 0x9AC001793402843AULL, 0x8081FF01D5A65692ULL, 
            0x4E88619B54B74763ULL, 0x0B47C78FC109BE21ULL, 0xE071D5A9C97280E9ULL, 0x9C07DE0EEE35521EULL, 
            0x05CFB97D52754667ULL, 0x832FCBC293721180ULL, 0x2891079F55BB2225ULL, 0xEA8DED740E70E985ULL, 
            0xCE35E6BDBDEA219EULL, 0x85D52EF44B28FB96ULL, 0xEA82075A983A9ACBULL, 0x5699E43A685CAE2EULL, 
            0xDAAD27435691303AULL, 0xC218861C23830425ULL, 0x2F84CAE99E56510DULL, 0x834C0385DCAA2A37ULL, 
            0x42DD0E1B48B694C0ULL, 0x861E1273D7E6AE3FULL, 0x83C43E4DA38D354AULL, 0x37BE0D64C43F144DULL
        },
        {
            0xF5576D726F047613ULL, 0x89A2F12375A11C25ULL, 0x4454A4A396EBB6C2ULL, 0xA6BD4F93139FFB6AULL, 
            0x9E71086182619B34ULL, 0x536FA92C30DA0F06ULL, 0x489AD0720F79F6E8ULL, 0xCDFB1216F655E5D3ULL, 
            0x10347C5002F69780ULL, 0xE9F3A4298332C581ULL, 0xECF5DBAC69D74773ULL, 0xF8D07FD4E7DFAD95ULL, 
            0x9B3AF5B9FA1259A6ULL, 0x38566BBEF1A2F433ULL, 0x703F2622BE24CF4CULL, 0xB23E1E0B21B1CB8BULL, 
            0xA3D2D722F116DE2EULL, 0x07A422928A950187ULL, 0x8EAFE455DE9554FAULL, 0x96A7FAE0CB8057D9ULL, 
            0xE586215F80E20DC8ULL, 0x9C06AC53DD2C81DCULL, 0x5912E3C984ECBF5FULL, 0x50DB7F4C28151997ULL, 
            0xB02FD0C6D492C863ULL, 0xB75DB4AD05EE588CULL, 0x93780F9FC1B450BDULL, 0x9517FD2C6C0BA783ULL, 
            0x6100FD46E96B426EULL, 0xC82693C39EEAF1AAULL, 0x4F0039FCCDC491F9ULL, 0x7FF5C998C4FAAC22ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseAConstants = {
    0x7476DD9CD5B1DD40ULL,
    0x80309D41F7B16118ULL,
    0xD9E7A5B93BF3437DULL,
    0x7476DD9CD5B1DD40ULL,
    0x80309D41F7B16118ULL,
    0xD9E7A5B93BF3437DULL,
    0x8CAB02935C543F02ULL,
    0x69D5A1E3AA4DC35BULL,
    0x07,
    0x18,
    0x90,
    0x6D,
    0x3E,
    0xB0,
    0xE7,
    0xBC
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseBSalts = {
    {
        {
            0x732E91D1B687C1CEULL, 0xACE099C561205B75ULL, 0x7E51EC68D3405727ULL, 0xDAF9BADDCE5DBFF7ULL, 
            0x0624FDE31552A545ULL, 0xB4ACF7CA12CC8739ULL, 0x3DB14455F6C69C53ULL, 0x6EEA4EC954F5FF38ULL, 
            0x8832569F3A1D9723ULL, 0xE476175374073D5AULL, 0xA1EEC73485958387ULL, 0x4C7C62418AD18761ULL, 
            0x6D7B4FAF8148A169ULL, 0x7A695291FD34A5A3ULL, 0xAE39308E2819BC05ULL, 0x09FDE9C3C89B1E96ULL, 
            0x11A4A51E68592CCEULL, 0x01377319AFA40AF0ULL, 0xCE2F8893F2332FA0ULL, 0x83D649FD8764FADFULL, 
            0xC3B6FE4A9E45A989ULL, 0xA9472BEE4FD6A997ULL, 0x46EE1246555DCCFFULL, 0xF0C37AFE05F83865ULL, 
            0xF2644AA7D9E447B2ULL, 0x18D1A902F1A18E0FULL, 0x8D7318DC13B7E82BULL, 0xD480C547A4943AC8ULL, 
            0xED0124D1DE46B843ULL, 0xF6A887D6C2C8F714ULL, 0xDDC6E709B2F0695EULL, 0x88209DCA508C052EULL
        },
        {
            0x49E04C0DC59FB332ULL, 0xA2F82468EF5455CCULL, 0x52F30F168E7551A9ULL, 0x39D9CC490E018338ULL, 
            0xB5FF97E6D42708F5ULL, 0xED4C555E5C9BEFC0ULL, 0x32A1D6615771A8D6ULL, 0x4CB8BA9B1D1BA1BCULL, 
            0xC449940ED5DF5AE1ULL, 0x0CA9A30CCF45E15DULL, 0xAC494E0B92C11CDFULL, 0xBDAF4A0F759E64F4ULL, 
            0x27FF2F7508B86253ULL, 0x5423CFF0685DF49CULL, 0x0148551E380D0F8DULL, 0x72D1EF994EB63024ULL, 
            0xE1AC348FF87E67CAULL, 0x77508F44F60D68EAULL, 0x40052C4C21AF88EBULL, 0xEE2F82C27A909B5FULL, 
            0x0DB9923A52998AC8ULL, 0x7EDDA2A232418EF2ULL, 0xC8EA648BDFDA7E47ULL, 0x8A2C4E709563F885ULL, 
            0x3C0DCE61832CC1AEULL, 0xA610E8C6C4DCA9ABULL, 0x64090B1CE2C4166FULL, 0x53CEC3726BA13DF0ULL, 
            0x2E33681B7EF98831ULL, 0x88CA2E53B2D9BD71ULL, 0x591B4C1EE28B971DULL, 0x1AFAC2934F753277ULL
        },
        {
            0x9601AB27739EAC74ULL, 0x3C8D020F2A91F5ABULL, 0x292F6267941A53F4ULL, 0xB543B4F2A6CAC083ULL, 
            0x918A9FB21D3916CAULL, 0x6209D688CFEB7BC2ULL, 0xA3ED297333335539ULL, 0x6179B5C5506D9535ULL, 
            0x12F0E206B705963BULL, 0x483953D82190A229ULL, 0xD5D4C7324E76F26BULL, 0x43077755CD8533F6ULL, 
            0x6B9E7A6069A5676BULL, 0xD52A0BE956648ECEULL, 0xD72838BED25819EEULL, 0x98BC85330F22E477ULL, 
            0xE598B89209EE0C7DULL, 0x1304E0068F5E11C7ULL, 0xE5069CA2E5EEBECAULL, 0x2B6613BB5B5C0F21ULL, 
            0x5BE91005BE0EE14DULL, 0x2329AD4DDCBDABB3ULL, 0xA481B853854B0F7BULL, 0x1A62097509A9ACACULL, 
            0x482A41BB87563BB1ULL, 0x6577384BCDE44BD4ULL, 0xE70D9883D59B17B5ULL, 0xF570AF05E3F9E7CBULL, 
            0x05164323B9A1699CULL, 0x083AAF6925E0F5BCULL, 0x413D2CB849ED8D18ULL, 0x43F44E7AFC68D65EULL
        },
        {
            0x9E8838A14DE5F2C5ULL, 0x3EC6618058433130ULL, 0x8FAF0953B20E1737ULL, 0xCC2E717E24921BD6ULL, 
            0x0F14D12CDE53E763ULL, 0x54ABEC8FDD7B32A8ULL, 0xEC1483CD72796DC6ULL, 0x7AFA136C96BF3194ULL, 
            0xF057D878E7653CB6ULL, 0x9577DB7A7E1E8FBCULL, 0x474783ED5A1FBD7EULL, 0x3113A5E675FEAB66ULL, 
            0x67EDFDDD5E7CE1C3ULL, 0x0A7F1D1D14F3AEF1ULL, 0xD9FACCFFE219008DULL, 0x845A99C25CEC2E0DULL, 
            0xF5F63E8147C13C75ULL, 0xEC2E65BE08FE94C4ULL, 0x1A00FF7F09EF57BAULL, 0x4938780070DA0A46ULL, 
            0x8A85C8DC0BC16892ULL, 0x42414A3D95BB32E0ULL, 0x632AB43C39362369ULL, 0x4B82510F24C7E33AULL, 
            0x7691A4815127457FULL, 0xAACB3DD1EC5166F8ULL, 0x608D875133A608E9ULL, 0xF4CE643F03F72B9EULL, 
            0x3868944EB2F0EC75ULL, 0x7E3A33D02C87364AULL, 0x3F12DDE07F1E02B4ULL, 0xEEC54C2F2B5703E0ULL
        },
        {
            0x6D5D8139CB3498D5ULL, 0xDA64D917C5818562ULL, 0x6663FC1E0EAE83D4ULL, 0x08E74C1A1C429137ULL, 
            0x7AAE44D549CA2FEEULL, 0x42FFA4402322573EULL, 0xB25DDCE4EC13D313ULL, 0x4AE5DC11C6D31D29ULL, 
            0xF31649EEE10D5945ULL, 0x1539B5C04D1C885AULL, 0xD5A7EE5D963BC61CULL, 0x4D9DD97F578AA1E0ULL, 
            0x62BEE4C51FE3D3F7ULL, 0x3629FE115894AEB9ULL, 0x9892F9A7608CB4F5ULL, 0x1CCCE3292E155F69ULL, 
            0x2B534A32FCF5D1BCULL, 0xFF5009428A141E12ULL, 0x8320E68C7C77C6F4ULL, 0xA6790593AFEFE4DCULL, 
            0x4ED953B08C047057ULL, 0x0BE4BFB5E4EBC7E9ULL, 0x0A41ACC3A280398CULL, 0x4735DFBDE9FED777ULL, 
            0xA4BBFEDFBC131015ULL, 0x393C6745E96AB6E7ULL, 0xD759CBD8548205C7ULL, 0xDB3C5C4DDCC9CEE1ULL, 
            0x3E1E92959A71B215ULL, 0x4579752CE44CCA9EULL, 0xC61DF29F34B3566EULL, 0xC9F76E5B996D3B7CULL
        },
        {
            0xE31F36E1F547A019ULL, 0x2747C1E8F03ABB09ULL, 0x7AAB6AEBA687E75FULL, 0x83DC97488F043198ULL, 
            0x1CA3B6B2D6B65949ULL, 0xCDECD0B84DF5072FULL, 0x3D12C8B128B8C01AULL, 0xF3CE284BD73F0C6FULL, 
            0x512130AE9484F3F8ULL, 0x8514547B98F5D531ULL, 0x3EE9693E89B02641ULL, 0x804580A33E7F2262ULL, 
            0xEAC3A9B65DDF1C47ULL, 0x6EF77488B514D0ADULL, 0x83DC3A5CAC5082FFULL, 0x7A6BB9B488420D17ULL, 
            0xA0C3CC21F6E7397DULL, 0x1ACC3912725C19ABULL, 0xE21B2D64AE219C5AULL, 0x834BCA112EF89906ULL, 
            0x4DD7727BEFB87F4FULL, 0xAA36CDF6C9AC2367ULL, 0xD48F3DC885F993FCULL, 0xDD52AE710BC0993DULL, 
            0xA1D6D703C07F988AULL, 0x1C3436D6AD025371ULL, 0x0E1E2BD8A231181BULL, 0x1339E33F94B280C8ULL, 
            0xDA9AEC4B4126B19DULL, 0xB4B11AC728A1C516ULL, 0xC7B9E035DADDFD9CULL, 0x48A11DFA9E042A97ULL
        }
    },
    {
        {
            0xAA2D0C84AF64515EULL, 0xAF8EADC779BE171AULL, 0x89B95CBBB17D7D86ULL, 0x55162472A0392B88ULL, 
            0x9A635A61452D7E6BULL, 0x94331FA8769739A5ULL, 0x5603057C8C86910AULL, 0xB4D07E1EF10849A6ULL, 
            0x44EC811196067E54ULL, 0x02FE8AEBFF14B839ULL, 0x6AEADE81C6A3A5ABULL, 0x1224A4844C6AAF08ULL, 
            0x39EA1D4A38945F58ULL, 0x1350B6394634DD6BULL, 0xB2971191C095C1AEULL, 0xEE905750D00A6BABULL, 
            0x301894066D589F47ULL, 0xDCAB3D06C81326DAULL, 0x70BF9A0D94820815ULL, 0xF9A7E913DDD7F22FULL, 
            0x75F4420BF1E78EEBULL, 0x15D86CA002394FBBULL, 0xD348DBEE27769810ULL, 0x963F8AD98D7503E4ULL, 
            0x9E63B44AFDA2D242ULL, 0x5A9DC68049335780ULL, 0xE8F61B165E0483C4ULL, 0xC90CE53F8B4820F3ULL, 
            0xDF3E3C9A6D160890ULL, 0x8F1BE697DDD08419ULL, 0xE691EEE7C26BB9A3ULL, 0x7F3F6DB8A368C6CAULL
        },
        {
            0xA9AD35AD6A6258ACULL, 0x68B31D873AB68665ULL, 0x68EA93AFB42B416FULL, 0xEC5D1FDB60CA33BCULL, 
            0xAA56339D695C1B07ULL, 0x63E2644E1DF6EFE3ULL, 0xCE3052B9623BF5DEULL, 0x4870AA11EFBD186AULL, 
            0x49A97F4F1CB98C1FULL, 0x5034CAAC3DC47493ULL, 0x2A7C32E0CCBF5240ULL, 0xBC338EE6CDFD00C2ULL, 
            0x5800F642089F0255ULL, 0xF5874BF96927C947ULL, 0xD8DCEE41A5D0F805ULL, 0xBE46D8282FF15323ULL, 
            0xFE865FD1C3487000ULL, 0xBD02C82AFD69F215ULL, 0x94DDB543A02A1427ULL, 0x994E3307726EFC7CULL, 
            0xFA4253CA250AD3E3ULL, 0x57D4A5B551B45C82ULL, 0x33AD33365D770395ULL, 0x98A43E55B2FEF881ULL, 
            0x1E17AA3B2457A241ULL, 0xACC9E2A5E154BAF3ULL, 0xA2D080E9B1C0B231ULL, 0x2F15BB2E6688F420ULL, 
            0x168F29D1DDCA6248ULL, 0xA4D4349EE4CAD08BULL, 0xC92D2CC57344C43CULL, 0x81153822262CDB7DULL
        },
        {
            0xB1E030930A5D1FC5ULL, 0x2F9F67F1676B6562ULL, 0x808EDA2A8F4B2F7DULL, 0xAED2282B2FD67C18ULL, 
            0x5E54FC4E09F3B87EULL, 0xD5C057EC072405E4ULL, 0x895316EF75D909A8ULL, 0xFBD7B7F797339CBFULL, 
            0xACDB3F84A14AF95FULL, 0x333C631BAD0278FFULL, 0x413534511C76CFBEULL, 0xBB29F5F8E1F399DBULL, 
            0x643F9FA0E4329CA1ULL, 0x9359BA8A13E22F1BULL, 0x8E54E31E876F9B59ULL, 0x43B992DDE601BA53ULL, 
            0x0BAF354273AC7DD6ULL, 0x0F4BFA3E69B1B14AULL, 0xDEF79E73F2BF3C61ULL, 0x694DEAE4E4353332ULL, 
            0x8983D6CDFCC572EFULL, 0x13BF1929287FED85ULL, 0xA6B613D7CA3E297AULL, 0xBD4524DD4307841AULL, 
            0xB9A1AAC679A733F8ULL, 0xC5D912F9215D8503ULL, 0x998503D31D825056ULL, 0xC04BBA2A824311F3ULL, 
            0x07C86E9010EC07A1ULL, 0x3C23CF4E7DD852F0ULL, 0x55CABA1331213EB0ULL, 0x3A3DA66C4373C5D7ULL
        },
        {
            0xFF3FEFDD7EB3E325ULL, 0x16CD08CAC990ED3BULL, 0xCC84F47B0489C6DDULL, 0x2062C374462CE127ULL, 
            0x11BAC36EA91CF367ULL, 0x03A36ED808598DB2ULL, 0x373A024076CBCBDCULL, 0x9C8A6E0186DF0966ULL, 
            0x4DBF4685605CDA0DULL, 0xC7D12076070776D0ULL, 0xF494C75A267F6374ULL, 0x6E4C758A0AD95038ULL, 
            0x5B89949170F0C1F1ULL, 0xEFE0A8A76C1CAECCULL, 0xC89E569B160403B2ULL, 0x908EC7A81AEF7447ULL, 
            0xF9740101DED69BEBULL, 0xC2726B4146DDE75FULL, 0x9CED27C8E9CA5DFFULL, 0x0CEE767F8D98035EULL, 
            0x97967CCA9369297DULL, 0xD75D5CA004A4BF77ULL, 0x5B0334914C1A2380ULL, 0x15D96E23B5FF6CFBULL, 
            0x33DE1E9D7E692243ULL, 0xEF1B616D03DC740DULL, 0xDF59916393FA7035ULL, 0x4CAAFA10A7663153ULL, 
            0x1F5BE3EA86A83457ULL, 0x0E596422DF31B4C8ULL, 0x7A97F96EB02FE71BULL, 0x3288CEDF8700C175ULL
        },
        {
            0xE9423183B379DEB1ULL, 0x69A91B9C6EFA272FULL, 0xD27C103073B1BEF8ULL, 0x4FA12D67D6FF9AB5ULL, 
            0x27F03F1B575641A7ULL, 0xF945170285A44430ULL, 0x2BCC15C1DC7CD5F8ULL, 0x8278D6F4EFA7CAB8ULL, 
            0x5129004C5C7606FFULL, 0xA0DC774602D51A6BULL, 0xB8F9C71F07B25514ULL, 0x6F9B82908492A5A9ULL, 
            0x275D6157F271E3B2ULL, 0xE30AC3F4770D11DDULL, 0xD430C813DBC5116BULL, 0x46C1ACDAE6D09F67ULL, 
            0x70FCB29C3FD102C9ULL, 0xE040049E9C13E66DULL, 0xDABDA85671A4F1BAULL, 0x5B6580D074DADF6AULL, 
            0x32560032E7DFE17CULL, 0x1038C6960662FC5AULL, 0x2510E7B3A9BDA2FCULL, 0xAD0DDF7350E766E2ULL, 
            0xF28695486105C62BULL, 0x319D80A6B0B726C3ULL, 0x2418855CB7070330ULL, 0xF02B03B9AD1F8DF2ULL, 
            0x80EF980FAD34D5E2ULL, 0x9FA1C9135FED63FDULL, 0x34C4E5DF3145D342ULL, 0xF61DF2EBD65BE21CULL
        },
        {
            0xE2025120019FCC9DULL, 0xCF57E0ADBC29EC27ULL, 0xF5056C59417A7792ULL, 0xDB1E960C3AC9633DULL, 
            0x9D25086540FB3FB6ULL, 0x43CC67F2108DD4AFULL, 0xE152D7CAEB66CEEBULL, 0x3D6A00991C22394AULL, 
            0x08F3243E9229F29AULL, 0x94DF6EB80A550AD5ULL, 0x0BD56332598E89ACULL, 0x5256B2DC36EE1547ULL, 
            0xA0B5BEC0224A31B0ULL, 0x5549E078760E8F71ULL, 0x707B0C7664CB69DAULL, 0x2CF26091A601F09EULL, 
            0x93F22BCF4CB9EF27ULL, 0x4A730F4012DBE441ULL, 0x2AA8B1E1713C8F26ULL, 0x317456D333431FE8ULL, 
            0x932F189DB71FB9E5ULL, 0xDD999C95FB1ECE45ULL, 0x74A82304601DB991ULL, 0x91794306A3BEDDB0ULL, 
            0xA3F4223A107EA1D4ULL, 0x048C6CBA6AFAA251ULL, 0x8B1BA60F1BB225D8ULL, 0xA4B93EC4A92D662EULL, 
            0x5479165A8C79BB78ULL, 0x0304D36FCDBE9B66ULL, 0xB4AC04F720CBABFFULL, 0x9D5D55D809044BCAULL
        }
    },
    {
        {
            0xB87E5D6AB0D77A90ULL, 0x39FA92B30D40849FULL, 0xEBDC3A620ACC44FCULL, 0x2F47B14C75EF19E3ULL, 
            0xDE0D1D7A5803EB3AULL, 0x1492DBCFA60C418EULL, 0x12CAC22FF9BFA7B2ULL, 0xE04C663BCAF3C8C2ULL, 
            0x4E28229B5ABB042EULL, 0xA379666225ED9AF9ULL, 0x8683BE36CDFDADC5ULL, 0xE943A82D30346DEBULL, 
            0xE2A1BB858F48FF92ULL, 0xB670A25617B9F7D6ULL, 0x611B533158A63B4AULL, 0x2B10B6EC38341128ULL, 
            0x1AB95BE8BBA710F4ULL, 0x5A73D9650044D6AAULL, 0x29F4750B13BD8F84ULL, 0x33807A97776982BAULL, 
            0x9473D60A97AF4CF1ULL, 0xC48A548399BACD5FULL, 0x41742F7AB7CC500FULL, 0xEE651207BE16CBF9ULL, 
            0x25E28F4A6102ED7CULL, 0x36D8B3F12EC806FBULL, 0xFDB1FA7370F9BC2EULL, 0x7C1D01D73E0FEA55ULL, 
            0x96522AFA16623BDAULL, 0xDEB99F202AF5C15FULL, 0x005D51C3C8D1A8E8ULL, 0xC6D66E5379C226BFULL
        },
        {
            0x9AF4EAD5CE7FFCA2ULL, 0x416C79074425DAA5ULL, 0x187FA2A38D069E6BULL, 0x56BACFAF6D3C03CFULL, 
            0xCCB885A2B94B9218ULL, 0xD05132D74FCB8EDBULL, 0x370B342C3DD4F774ULL, 0x2DC5EC5A8642AE3BULL, 
            0x37BFEE4B07F937B8ULL, 0xB7E5744A030DD708ULL, 0x23102D568372E481ULL, 0xD6583CBFC1390468ULL, 
            0xA489CBF363759C27ULL, 0xC9D5DEA444461BF9ULL, 0x2D18A75EB9CC0813ULL, 0x2B2BD35951854031ULL, 
            0x29A1F37C25088578ULL, 0x88382BA217DF3108ULL, 0x757B7693C7842E5EULL, 0x11102D4C2BAB9C82ULL, 
            0xE78B6D8A173D1F28ULL, 0xFBE2F6F117904D01ULL, 0x19CC08E1B596B931ULL, 0x3BA9F8BE27F32F5BULL, 
            0x453B2C25A9D8AB5BULL, 0xF3538DBB6637CCB7ULL, 0x36EBE85B9EA3E15EULL, 0x616F33AEE5432123ULL, 
            0x1C34BBF31920BF2AULL, 0xE2885EAC776221F9ULL, 0x15ABACB8C60D7C1DULL, 0x9C54538F3BB72212ULL
        },
        {
            0x3A717D694F473AB5ULL, 0x77A0E952DEB383CAULL, 0xF06ADF2AC89D3FD4ULL, 0x54E5A25D7AE14760ULL, 
            0x5233CEBB42FD389BULL, 0xBD96661C16A216FDULL, 0xC110B6AC00433C9FULL, 0xD4FD954FE34E1002ULL, 
            0x3D45AA3EF817B683ULL, 0x89B5DB84DF214EADULL, 0xADB27285DE02514FULL, 0x59BB69DDB965991DULL, 
            0x2F3FC00716815FBBULL, 0xB4CAA2D614B63E37ULL, 0x8967E58C5C478CA2ULL, 0x39921D3FC5ADD169ULL, 
            0xEF39C490CCD752A5ULL, 0xE4913FBFBEE3731CULL, 0x4B4FF129E52BC7BDULL, 0xD02EAAE0AC3FE2CCULL, 
            0x71B051A03B74CCCDULL, 0x9366FFDB51227A80ULL, 0x89426A6DF34D8892ULL, 0x4E377FCE0BE6E5BCULL, 
            0x6561F3269B4D5FD7ULL, 0x7C457DCC8F9F7DE6ULL, 0x8DF4599922651B05ULL, 0x14612131087CBFC6ULL, 
            0x754520B3CE916D6EULL, 0xAC686F200F02A8DBULL, 0xDA8A9CBA06F88CADULL, 0x69FCD91C6AD5945CULL
        },
        {
            0xBDEEB0AF51354D84ULL, 0x74119E6253C3F3D1ULL, 0x1946932E417FB97EULL, 0xA51C4FA1CCE41883ULL, 
            0x68932F022C43CF9BULL, 0x351F39F14DD73629ULL, 0xA1EB1EE40BF722CFULL, 0x1CA40CB92417D9D0ULL, 
            0xA95D96AFBAE48638ULL, 0xB2A258F0EDA7ECA9ULL, 0xBEB9256550D9C87AULL, 0xFB2DA2BE45140CF0ULL, 
            0x516ED81B7E2E8868ULL, 0xC4780DCDE68A6B0EULL, 0xE406485FA6681243ULL, 0xE6ED0BF5312D28C7ULL, 
            0x9423CC6F2B29FD13ULL, 0xC0D149982B4F91F6ULL, 0x62FB4347ABE560E7ULL, 0x865E2B0877034F2FULL, 
            0xE2DA8F17F323049BULL, 0xDEE530333B6203B7ULL, 0x460F5ACD1BED70CDULL, 0x675A743D9797B4C8ULL, 
            0xB1C46EA3FAD83A57ULL, 0xFD24AA96100A20E9ULL, 0xB78E538CFB8E50B0ULL, 0x1BFC799B405212AFULL, 
            0x57EA951D50FCFADAULL, 0x3E6CC2CE7FF9CD79ULL, 0x01C7BD9C68D05184ULL, 0x9AD70D09A4C001A8ULL
        },
        {
            0x6E1F5CF4D8229F4AULL, 0x6768640AD94E67DDULL, 0x7743E782BCB16D56ULL, 0x6D2A28504D74FBA1ULL, 
            0x48A025FED2D61B01ULL, 0x5E015F7CFFAF5483ULL, 0x56C2B67B87BACB5EULL, 0xFE9857937242362FULL, 
            0x8B926B15CFDCA131ULL, 0xF357C487D692C33CULL, 0xD639221C4FE775F6ULL, 0x05E4F0257AD327E4ULL, 
            0xBC0E5C33F5F1ECC7ULL, 0x633112B52F506376ULL, 0xF90F3DE93685AF47ULL, 0x70DF28C6019433FCULL, 
            0xE0AAD83CEC5E7D24ULL, 0x026B90C6AFBE2AB3ULL, 0x9B62D37D2C9DEC40ULL, 0x099AF293EC3D92B2ULL, 
            0x9A3D1FBA920FF5F3ULL, 0x956469643DA18F15ULL, 0x5712DBB383121403ULL, 0x03E8C6DCFB1B789AULL, 
            0xD256C0B1F33CEBEFULL, 0x62FF0711D731C6ACULL, 0xB72636988E158DCCULL, 0x50BB15B0DD817367ULL, 
            0xC7668B12F1AFE377ULL, 0x4EEEC5B45A12AD6CULL, 0x4DA7AAFAA562EF4CULL, 0xE9EC97B8CDD00969ULL
        },
        {
            0x82701A6AB654B056ULL, 0xAF62DB7F2CFD0D8AULL, 0x21C05EFEDAD6C13EULL, 0xF52F2B831A057852ULL, 
            0x464EFCC3EC6876F6ULL, 0x20F1FAE81508FBB3ULL, 0xCD6B9C8B56123A8EULL, 0x0A7C11A1E19DC01EULL, 
            0xA81137BB9951D591ULL, 0x77F1D3609BA10E63ULL, 0xE64291CF573696C4ULL, 0xC16AEAEE217C0171ULL, 
            0xF24C750DD670050CULL, 0xD5056AFA3554F2E2ULL, 0xCC3CAEF6FE8D323DULL, 0x40BEB3B0E760AA9BULL, 
            0x5738B2BDE487B917ULL, 0xFDD0A6334B36FF26ULL, 0x90F7030C093C85FFULL, 0xCBE0CE098F6F4F85ULL, 
            0xD5AAFC42B07470D2ULL, 0xAB69F907F396F06CULL, 0x258575B117631D0FULL, 0x51768E78F4E0C772ULL, 
            0x7B1AADCD57E65F09ULL, 0x40238A050D8B7162ULL, 0x348AC52254051D51ULL, 0x41116617766F5C17ULL, 
            0xE87EF60CCED5A132ULL, 0xA943E1AB41601F54ULL, 0xB6B4BF0B3C1DEF7AULL, 0x7CAA2415F04C16C2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseBConstants = {
    0xA393B8615072D817ULL,
    0x11EFC66EB5D45B2AULL,
    0x36D0A4F1D0170088ULL,
    0xA393B8615072D817ULL,
    0x11EFC66EB5D45B2AULL,
    0x36D0A4F1D0170088ULL,
    0x7F137D2BEC84CD59ULL,
    0x189375EC27AA53CBULL,
    0x8D,
    0x9A,
    0x3F,
    0xF2,
    0xB6,
    0xF1,
    0xC1,
    0x4B
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseCSalts = {
    {
        {
            0x5235F5F620A16D6AULL, 0xE8769D1AFA5871BDULL, 0x6C75DFC25BC99F14ULL, 0x8A220816E8A34C93ULL, 
            0xCB24FE5E8F761DF9ULL, 0x5117DA6489F9B95DULL, 0xC8CFAE93B23D6B0BULL, 0xD750CBDCB5DC6760ULL, 
            0xF6B49C105E7A6210ULL, 0x088AD7453A9FC91EULL, 0x96D2560E0469CD4DULL, 0xB0AEA6556C0A50D0ULL, 
            0xFBEA7BE0D3DD8053ULL, 0xCF8A5532FA82A45BULL, 0xEECB3A13497B89ECULL, 0x05CCA910E164E628ULL, 
            0xD547CF66F6C61149ULL, 0x87676B7E89B0EFA2ULL, 0x0308ED968871A3A7ULL, 0x5D86BAD777ADB27BULL, 
            0xC7D04AF0B3BCE283ULL, 0xDA2FE83455EC0859ULL, 0x36D18E0A85304082ULL, 0x44AE3C0A8F026A8BULL, 
            0x3142B6CA9E170B2DULL, 0x4264B104F115AB46ULL, 0xCD9BBB869B9FE31DULL, 0x8CFF67EB2C3CFC98ULL, 
            0x1E747C3FA9EDE566ULL, 0xADF5F14C853578E9ULL, 0x7DDEC1CFDFA241B3ULL, 0x7A73C7D5B9055FA2ULL
        },
        {
            0x4D87B653717B6BFEULL, 0xC870D5F7E50A09B5ULL, 0x85BB42704453058BULL, 0x4B51B668A8614814ULL, 
            0xBC27BC091B249B8FULL, 0x6BA25B0FC6744655ULL, 0x1734D472DB8BC726ULL, 0xE899F85BF5256A25ULL, 
            0x6FE09BA1F3D5C088ULL, 0xFEEC0847501484CEULL, 0xD1AAD62600A0CD2BULL, 0x0C68158E0875584CULL, 
            0x3551B7C8A833330AULL, 0xB0E3EF6396900FC7ULL, 0x67DA3AC39B7F19DEULL, 0x916FAC331AAC2A68ULL, 
            0xC6C2859DF7D74495ULL, 0x7FAD317D8808B8D2ULL, 0x1A949543B030D445ULL, 0x7EF8227171B52414ULL, 
            0x0898B61246FBABA5ULL, 0x98770CFE8D3D23DBULL, 0xD83211D2F6CD614AULL, 0xE4E8A8A0A62CE027ULL, 
            0x8F6E8B1C1B3953ACULL, 0x87750DBB7E128AC6ULL, 0x4EFC351D9C1A168EULL, 0x47CF065C4BD43090ULL, 
            0x865265B499C131E0ULL, 0xFB04624EAF435AC1ULL, 0x0472460A8835DEE9ULL, 0x711FF46798F428A9ULL
        },
        {
            0x925310B816D03573ULL, 0xABA46648C6849B79ULL, 0x16416FD927711039ULL, 0x2B83AD4A6B0354BFULL, 
            0x01C8A7CFF246ECCEULL, 0x17B27EFDE2E3C461ULL, 0x59CCA0DECFE06C2FULL, 0x5B7D4DEBC9897922ULL, 
            0x2FB8A586598518BBULL, 0x60F27F2DC642BDE4ULL, 0x42CA206C702B8912ULL, 0xF7E0B06F8F8C3C03ULL, 
            0xA7660789F327A2DEULL, 0x186FA36C44659F0AULL, 0x40828765917A4D14ULL, 0xB02406740B374128ULL, 
            0x60A88D47615EBCE3ULL, 0x8D634F4C582F76DFULL, 0x68456BE734AF0550ULL, 0xB1A6108C0A5BEED8ULL, 
            0x0A34F372E416059EULL, 0x81E9301F8504702FULL, 0x793C66E2EB56F996ULL, 0xE7998B89C26442DBULL, 
            0xC61AEB05BE6706C8ULL, 0xD93784A9AD7B7A10ULL, 0x918AB71380DF864BULL, 0xAA41E8759674ED84ULL, 
            0x769ED9090351E502ULL, 0xD5427A9E00FB5332ULL, 0x00E25A50EAEFAA7FULL, 0x5AFBBC75C80BD5EEULL
        },
        {
            0x2DECC92DE94FDFF0ULL, 0xCD6A23CD3F673A1AULL, 0x2E1EBE4F5CF8C2A1ULL, 0xC2A5998DE0523E2EULL, 
            0xB3789B45D2B25212ULL, 0x88EC972BD0BF2ECCULL, 0x1725840956D7DD4EULL, 0x20B2D6995EDE8FD0ULL, 
            0x2D13DBA3623922C3ULL, 0x81BE50BCA81438ACULL, 0xE461769321298B86ULL, 0x672B0180F56CF24EULL, 
            0x59A82DEDD1E02950ULL, 0xEF3413AA4019DA1CULL, 0xD70E879B629EAB68ULL, 0xFB638874F0F53C06ULL, 
            0x9DE9C4596B3714D4ULL, 0xC7E6806EAFC379A1ULL, 0x4606D0A69B41D943ULL, 0x891272D0D96A9690ULL, 
            0x1E6E2053B49E6C53ULL, 0x950F2E2257EDB3BEULL, 0x064CA6143F5501E5ULL, 0x13FE7DB4A3335A28ULL, 
            0xD3ED9E0B77D5F412ULL, 0xD92CE73FE05985FCULL, 0x4256A86CB827C169ULL, 0xBB58908C8126ED9FULL, 
            0xA6D6943AB648F6C8ULL, 0x78E1BED0E61A1E5DULL, 0xAAB3390109288D47ULL, 0x74996F41835E60ACULL
        },
        {
            0x4C85453AEDE23C5BULL, 0xB8BB10F27D9A8CAAULL, 0xFB993A98A26C2D4DULL, 0x29561A2C9A4DCEEEULL, 
            0xD10F6D4C1A7A3D78ULL, 0x8B3688EFD4370990ULL, 0x1231DBCE14518D5CULL, 0xC88CA63DD4B5C5E9ULL, 
            0xE8E3E890BCDD0F29ULL, 0xF6F46A9C9A2C4EA1ULL, 0x8521C0C17F3F3058ULL, 0x64D30EA03FC25883ULL, 
            0xD5C82604A1435B79ULL, 0x4AE34A55413070CEULL, 0xDD55D092E6040C1EULL, 0x860313D46F5E06CFULL, 
            0x185A966A5A3FA6FDULL, 0x1DB395DA0E2FF0E6ULL, 0x2B16F3BC2343E1A4ULL, 0x48B6F1F52479743FULL, 
            0x42FD72819367F8B8ULL, 0x90CABE6DA5CCB95AULL, 0x582F4D40D09BAAC1ULL, 0x09DD50D739F08498ULL, 
            0xCC6DD3979F1FF57DULL, 0x6E3DB05621EE1AB5ULL, 0x95161BA0CF455810ULL, 0xDD610B10FAA8B1AEULL, 
            0x375791B2D7850C5CULL, 0xAD9AA653BEAFCDD0ULL, 0xA0BF84F1974685B6ULL, 0x89E67DBB7AE4357DULL
        },
        {
            0x2F80A56C88269B56ULL, 0xF4DFECF51A9623CDULL, 0xC25713FE0DC0ECFCULL, 0xD1055ACEC59E3F53ULL, 
            0x703E033063299643ULL, 0xC8103EF2720B94F4ULL, 0x4EA50F3A25EC8296ULL, 0x7522CA394572B7DDULL, 
            0x5F1A592F8F13408FULL, 0x7A900EC6A4E39C60ULL, 0xAE58CF9B495F2FB7ULL, 0x825B5F49F7586FB6ULL, 
            0x47431D005915DC29ULL, 0x5B2ED2FE270F9FE3ULL, 0xDBAC01AB2422319EULL, 0xC27CE71B052BE1CDULL, 
            0xCE8053F5DD629DB3ULL, 0x2E95495BAF93F91CULL, 0x11E9B1303255D75FULL, 0xFBEF56BCDF097857ULL, 
            0x480FCF30EF2AB3F2ULL, 0x4B1E754078F6FBC0ULL, 0x1D1601C617FD2020ULL, 0x85D795A8226D5C92ULL, 
            0xEEDC7EC80B46DA30ULL, 0xAB61C916B2CD96E1ULL, 0xA23DC9625DA09441ULL, 0x8AB79CCA7482D30CULL, 
            0x9473ED078500602DULL, 0x7450B777CBA1F99EULL, 0xB1D92B6031213BE6ULL, 0x9C27C80F43048F53ULL
        }
    },
    {
        {
            0xEF6955770A3977F7ULL, 0x06200F68FB75C305ULL, 0x6F98214DCE20C423ULL, 0x378B2D74A0768298ULL, 
            0x47BCC1F461245E38ULL, 0xA8172138E908C4DCULL, 0x1406A5E07C8614B6ULL, 0x3E576F8C134488DBULL, 
            0x39E6FE4D24BA5502ULL, 0x9B2A9701128E137EULL, 0x3EC6FABCB91AD2DCULL, 0x4D7E175F7EB176FCULL, 
            0x56338C5D23D0AE30ULL, 0x4AB39EDC2012EBA2ULL, 0xAAF08D8F5190E60AULL, 0xE83DF56066C53D98ULL, 
            0x4E44846FB1E5DFC9ULL, 0x646636EB624408BCULL, 0xCF9EF3FEE468F257ULL, 0xF4E2F0A341D99692ULL, 
            0x043F4F67E7EDD821ULL, 0x38E1C6E43EE0510AULL, 0x26290223D1506CDAULL, 0xA08F61EF06D1FDD6ULL, 
            0x445CA3ECE2BA6641ULL, 0xF9AECB6E415C0920ULL, 0x9C11194C49407B52ULL, 0x22F760E6FFDBF317ULL, 
            0x52FDCB3F8D3852FDULL, 0xF99D4D14316A82ABULL, 0x22A5AA5DE9BCF30BULL, 0xDCA50CE1113C34C0ULL
        },
        {
            0x3FCCFAD2DC9529F5ULL, 0x3A9295DB5EF9BD86ULL, 0x9BBB739CE22A1C4CULL, 0x16D23BFB3EFF4DF8ULL, 
            0x0D5855CD621A3968ULL, 0xA68F480EBD57AEF9ULL, 0x6D735A8E1388DF5CULL, 0x06942D15E200F5F8ULL, 
            0xE935343B69CBC50DULL, 0xD792137664A5455CULL, 0xBF7DBFA56FA90BBDULL, 0x97BD62197BA84BB8ULL, 
            0x366F40CF8810B278ULL, 0x93FEE9570ABEC406ULL, 0xFEEC6A872F263F8BULL, 0xEE61B26F66BBD774ULL, 
            0xBF9F049F02CE6E1FULL, 0x9E26A6284E29F974ULL, 0xE7203800CF53ADF5ULL, 0x41E1D0B59941643EULL, 
            0xC1CAA2149DC3CF65ULL, 0x5FDEF265DE028099ULL, 0x25A08727DF8D7898ULL, 0xD4C383B6F5883955ULL, 
            0xF2AA4016BB32A80EULL, 0x4B058122C037412AULL, 0x3EC6D3A258C3E3E3ULL, 0x259BA9010A6C504CULL, 
            0x0930FFBC022265E3ULL, 0x9E2691C1ACC2313DULL, 0x1B654519CCF2C246ULL, 0xD4C1968E50579F15ULL
        },
        {
            0xC4AFFE840696442DULL, 0x3FF738331AFCC63CULL, 0xE47090E8C64CE223ULL, 0x7BB06DCC2FE4C1A4ULL, 
            0xF4C07E685DD92C82ULL, 0x0296FDDB1B99C621ULL, 0x52825D63908AD526ULL, 0x98EC970A3EA17AFBULL, 
            0x39015B3176205D0EULL, 0x3E45463E0C0664E9ULL, 0xC839E6B3850031A1ULL, 0xF3CA668F75FDE72CULL, 
            0x7B3D8DD4EE52F444ULL, 0xCB2788CD6B900A6DULL, 0x0B4E6197A3E40C48ULL, 0x578D6D8C1F56CE7DULL, 
            0x1F2AE6A69274E656ULL, 0x23A2B89F19B06F9FULL, 0x6E6D81521738DD0EULL, 0xBF3C0ECC1A57C47CULL, 
            0x30BC20E8ECF30F2AULL, 0xAF1A32A7B251ACBFULL, 0x30B4110E10E66B32ULL, 0x3E4CA0CE8B7AB843ULL, 
            0x68A697B5267CB48AULL, 0xA976ADF64587F73FULL, 0xA86BB22C42335034ULL, 0x3454EDDD45BAD8B3ULL, 
            0xC87DA5BD010E1D0BULL, 0xA3310718E4237D34ULL, 0xE78FADCA3858BFFAULL, 0xD79CDA74820A601EULL
        },
        {
            0x8B11864174C3DB8AULL, 0x46F0773F202396ADULL, 0xBAD7D170F775B90BULL, 0x875FE3BB6EFF824AULL, 
            0x7F976A75B9B09AE1ULL, 0xAD30058C2F626F99ULL, 0xF8DB39E0464AB24AULL, 0x8714465EF6B6F33DULL, 
            0x74770EBE6F7AC591ULL, 0x650BBDABFB91A180ULL, 0x6DCD8F98E4DFE233ULL, 0x70E1FBF3E6AEB119ULL, 
            0x660C6ED3AF8D3961ULL, 0x450DE65AEBF4174BULL, 0x5680E8FBDFAECAC9ULL, 0x5ABC3C0586BAE4F9ULL, 
            0x1878AD395B18E7D8ULL, 0xCA50C929162530D3ULL, 0x1E942AE882B4FC2CULL, 0x5383E9BA8E544E66ULL, 
            0x93D5246E568876D1ULL, 0x1223F5D163A5C6F5ULL, 0x6F19C87518E0BCF4ULL, 0x8AE5EE93A1D6393DULL, 
            0x29B7682271DC770AULL, 0x21D956DD54D78E5BULL, 0xA3BB4786104AD5ECULL, 0x9BCC1A0094BDF004ULL, 
            0x60A0785E4C3567EFULL, 0x03B72716B21B0ED8ULL, 0x9376376202D45BF5ULL, 0x1A03DF88B763F5C0ULL
        },
        {
            0xFA4D385EAC81B3C5ULL, 0x75556087A695155EULL, 0x0A044E08D42CAF0AULL, 0x0AA6667824D0CA65ULL, 
            0x24D26C8186D1921FULL, 0x535CF34FC4CBFE17ULL, 0x98C4E78C6669658BULL, 0x674DAD1A2A9FC6BDULL, 
            0x8423B0CAD542A6D6ULL, 0xD637AC4B2A4F0D7FULL, 0x7418B0FD59AC7A50ULL, 0x993112777AB7F6A7ULL, 
            0x699BF5C8A0412099ULL, 0xF89D80321A9F7034ULL, 0x87D627D047F8DB4EULL, 0x5C0C62E7763854DBULL, 
            0x898A45BD639DC00AULL, 0x6BF4B78033C86305ULL, 0xD6EA3D3F0B5969EEULL, 0x39B8B8B770EF2918ULL, 
            0x68F567DBC6C5D8C6ULL, 0x90EF981036A09A13ULL, 0xBF631BAB89808571ULL, 0x4E4C99B26EE4890EULL, 
            0x5D94A8B881F1DAFAULL, 0x1DBDB83E7507258FULL, 0x53FE560D4764D508ULL, 0x9C9FBDCB061771FFULL, 
            0xF9E918227B4E8455ULL, 0x9335425CEA000D37ULL, 0xEC9D2A43FD67A3C7ULL, 0x2833BC5C0FA1BA88ULL
        },
        {
            0xE149F65962C69FEFULL, 0xCD58259FBD86002FULL, 0xF3A3A13E057D6747ULL, 0x49D75E1CDC9EF7C9ULL, 
            0xD683501017DC327AULL, 0x56A69658EFB3D818ULL, 0xC38C7872D052AD08ULL, 0x046148E4AC37730CULL, 
            0x4B78C4EFF338F713ULL, 0x5E9D4608EDC454F8ULL, 0xB675C008B6BEDE92ULL, 0x021B213D2A6EB944ULL, 
            0x6A6C5E346330CE2BULL, 0x2AD4771F226E4E4BULL, 0xD493465151CBF157ULL, 0x00E2E2BED3148020ULL, 
            0xD721C98970A75E6CULL, 0xD1FB4D55A8E9B75CULL, 0x1F5A43A4A9C8732EULL, 0xA1D18C125ACDA876ULL, 
            0xE021D7A4B34B4B64ULL, 0x3C994739E3F68630ULL, 0xDE8B3D17DA15CC31ULL, 0xECF1FD47E1B87008ULL, 
            0x4DB3B1BDF2F1C62DULL, 0xDE31F21F102CBA29ULL, 0x11A2A6FE8647802FULL, 0x5A3AA461CFCBD4B7ULL, 
            0xE7865E7ADF7C0D37ULL, 0xD48EC742397D8B09ULL, 0xC174A88175C01198ULL, 0x54829571CBDBC84EULL
        }
    },
    {
        {
            0x5B0E25524C720B1FULL, 0x1992C500BFB3123DULL, 0x7D0CF641A0457C58ULL, 0xB1ADF0CF854FE283ULL, 
            0xE89E885BDA55921DULL, 0x7D8D39142040EBF5ULL, 0x7EC9F2FD5F098A2FULL, 0x7C575F2251FF45B9ULL, 
            0x8A1B5C461F96595FULL, 0x3C1C2942801EF24DULL, 0x8C4ECBE512E2C225ULL, 0x20446BBBBE253EB9ULL, 
            0xE0A88D9D9025D622ULL, 0x3467354E2EDEAA49ULL, 0x484270780AED4422ULL, 0xF3778AA8DA77D0B9ULL, 
            0xA64DFD6797D6CD52ULL, 0x454B9F2B2A1374C1ULL, 0x95E6E2FC560BFE5BULL, 0x840A6C9036EB52ACULL, 
            0x0AE933CD915E3FABULL, 0xC6E503B9E149928EULL, 0xB0355EFF4CE68FD6ULL, 0x60776CC032C12C12ULL, 
            0xEEA59360E44FD80FULL, 0x071DF23D1A791669ULL, 0xCCC4271578604697ULL, 0x903F14F85C08607DULL, 
            0x38ACD65CF4554DF1ULL, 0xBCD855D70AEDD176ULL, 0x8FF07C88F9AD9525ULL, 0x235F91C6B8B95FBBULL
        },
        {
            0xFA7B8E6A19D879D0ULL, 0xC974CE34D1757A72ULL, 0xDB8A2E26005F4A4EULL, 0xDBC8AD4D33BE8080ULL, 
            0xB098CF11282694A5ULL, 0xFF83C90BCD3DF077ULL, 0x33E2D247632E2FA1ULL, 0xE29184704EE0F381ULL, 
            0x2ACAD8C38053A664ULL, 0x348A11E6E61B03A3ULL, 0x43CD616AF177F183ULL, 0x65C1B0C0207EEAAFULL, 
            0xCA171498512E8E2FULL, 0x8F8BE683F6A43B94ULL, 0x487B02988CD219BBULL, 0x7211E601E7FB98D9ULL, 
            0xC8B47120A1E3D3BDULL, 0xD247D45A2666DC23ULL, 0xCF8FCAC708C95FFEULL, 0x59A85BD8DDFA1426ULL, 
            0xE819225A27F28BE3ULL, 0x1C1B736322C68B79ULL, 0x113E30F58198C18EULL, 0xDAB54AF72739F774ULL, 
            0x5E04CA1AA259873CULL, 0xB9691AC37B5D56D3ULL, 0x56EF82B300F7BF45ULL, 0x03C3951BA8FA065FULL, 
            0x73DA32BBFDF7D0C6ULL, 0xD57FE5DEBC7D71D1ULL, 0x552EE1434DEF089DULL, 0xA83683419A65C56DULL
        },
        {
            0xA13F2C662C5B6DA3ULL, 0xA518D9B8671DC58EULL, 0x793AFAEDDCFFB44FULL, 0x87DD1B3FACCFCE77ULL, 
            0xB494CE27352A6665ULL, 0x5F995FEDD6784033ULL, 0xF99F662B749CDC1CULL, 0xBE4417DA2109E1D4ULL, 
            0x494B8AAE9C90A4BCULL, 0x097DADF15342EAABULL, 0x27C433ABE932BC5EULL, 0x50D3A7BD628AE840ULL, 
            0x10DB8F8DF22659FEULL, 0xBA82E7A0749B7E34ULL, 0xE290F1360530C033ULL, 0x71D12D83AB19F01AULL, 
            0x07CDDAD80F62F2D4ULL, 0x54E764332752E64EULL, 0xB6210B0264421997ULL, 0xBCA3B1E637715693ULL, 
            0x7CD06F97AD301D27ULL, 0xFEC469C15C4A1E15ULL, 0xD5C53AB558D4C0DDULL, 0x9DB6943F5B5B199BULL, 
            0x6C4625F577CE072AULL, 0x38056700B348B793ULL, 0x5D35C070F8A6AA96ULL, 0x206D7A4BB75E34DBULL, 
            0xC5FB7CE8A6B664D9ULL, 0x07C8F1F053B295F8ULL, 0x1A2AD2298B355B97ULL, 0x9988389805E4A428ULL
        },
        {
            0x6007206D1624DEE1ULL, 0xE250F0A332505E3EULL, 0x320A2CBC00BF1963ULL, 0xB9C52D055BD8CC46ULL, 
            0xE417DF5F132A9650ULL, 0xAC154790E788F570ULL, 0x611DBA92215F40A5ULL, 0x561025F4A8FA3EF6ULL, 
            0x8DCF4E120E3FAC65ULL, 0x6D647B5BF91FD29AULL, 0x09A29AD11B14A1F2ULL, 0x9F540897C098F114ULL, 
            0xB7634C62D3E7411DULL, 0x21AC46821B264071ULL, 0x7B2B17625A636392ULL, 0xAD4B87B6F0914F66ULL, 
            0x24B5A08C826881C9ULL, 0x635089697C30C5E2ULL, 0x8E586774676FB6ADULL, 0xA8F4E69C6601FC14ULL, 
            0x254320AC2BE436C8ULL, 0x0B789C0BAF536C4DULL, 0x9C320D408C620844ULL, 0x2E07D3880E9526E7ULL, 
            0xF0F0A14DF3CFB357ULL, 0x1D150D675A64F4C8ULL, 0x2FA6701DAE5040D1ULL, 0xCD3CE15ADD1C8DBDULL, 
            0x5C5EE17CF73CAD90ULL, 0xE84CBE9DF89662E0ULL, 0x05F0F6F71533F418ULL, 0x894692F89C8EE0DFULL
        },
        {
            0x6D8AB7749F55AF66ULL, 0xBEAC7097CEF0F132ULL, 0xA204890824CB24DFULL, 0xB94B42C368F0DF0EULL, 
            0x2BAA8293CFC90B6FULL, 0xB477C90CB47334BBULL, 0xAAE52BA889783282ULL, 0xC9183D9446D2D5A1ULL, 
            0xD8AC0FAA637B51D0ULL, 0xF35233891CE149E7ULL, 0x52FADAEC87385772ULL, 0x4046F173C61DB27EULL, 
            0xF54027D2318DD9E1ULL, 0x1A9D0385C1499BAEULL, 0xE016A09466C475E7ULL, 0x0A0FD9DE3F6FAF4DULL, 
            0xA13699A2E0EF5169ULL, 0x2B95C56DF20E1056ULL, 0x36631F650313D08AULL, 0xB82A95EEE731615FULL, 
            0x44FB2F19370C6A6AULL, 0x14844B63B71DF4B4ULL, 0x741E8F4238E9D065ULL, 0x0C558EAE9B3F4E23ULL, 
            0x7BF3154928B3F42DULL, 0x6370C67DF54B0D72ULL, 0x7516F4D36F4FF863ULL, 0xC5F83CA7CA12B5C7ULL, 
            0x2107CCA0C3DD2E55ULL, 0xBD6E547FA61F17D6ULL, 0xD6689ED99A8349BDULL, 0xC6AEC77AC4507683ULL
        },
        {
            0x26364D13E154CCBBULL, 0x6C2A2CE36864F754ULL, 0xFD2E4DE2EB58F018ULL, 0x375B218F6283BC14ULL, 
            0xE56277D6333332A2ULL, 0xA0CFE21F08CBC056ULL, 0xC455B13D21032BD8ULL, 0xA56B690355FB7136ULL, 
            0x72E10C46CA4433B0ULL, 0xC00D38589A432ABAULL, 0x5C504F2E88085981ULL, 0x087846B89041831BULL, 
            0x48319BDDE714AC06ULL, 0xD46ECDAB532A91C0ULL, 0xE6A98CF690F850B6ULL, 0xA8D8C41EA81D8238ULL, 
            0xDD9C0EF4551BD35CULL, 0x164D4C5506E178A5ULL, 0x857C23DB248D35BEULL, 0x44C9F54CE53B458FULL, 
            0x39D32EF85DC24006ULL, 0x52283D2BF69583B5ULL, 0xBBCE54010EDF0291ULL, 0x0414E6988AA2FD5FULL, 
            0xA2EA27DFB5F18130ULL, 0xB4D2755A4D121795ULL, 0xE4B9D7989B06DFABULL, 0x3789E622624F913CULL, 
            0x4E30223CE58A9223ULL, 0x24203848A231FCA4ULL, 0xB18C0491B6449FD0ULL, 0xF12C0239B2BF962EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseCConstants = {
    0x97F1525ECBCA830FULL,
    0x323C8C274F5A7526ULL,
    0x216DF083318DBAE9ULL,
    0x97F1525ECBCA830FULL,
    0x323C8C274F5A7526ULL,
    0x216DF083318DBAE9ULL,
    0x13661D415A5BA127ULL,
    0x650995EBDFC2AA89ULL,
    0x36,
    0x86,
    0x3C,
    0x68,
    0xF1,
    0xED,
    0x39,
    0x78
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseDSalts = {
    {
        {
            0x74E56E157874BA07ULL, 0x4C7EBC495F054259ULL, 0x014F00460D661313ULL, 0x8CC3902B3019BAE4ULL, 
            0xB13FB0BC295074F1ULL, 0x3CD4C1F3092B74D2ULL, 0x1FE5A87C0AF9F1E3ULL, 0x0A0DCDDFFFB606CDULL, 
            0x2681984D69044CAFULL, 0x1D026830B3BC5F4FULL, 0x7FD83C0E6A39F901ULL, 0x2404517054AA27B0ULL, 
            0xFE650020B0C33855ULL, 0x899B6C58ECD05B14ULL, 0x2F8A9F0EBF705625ULL, 0xC6C1DD6BF5752072ULL, 
            0x29D4AD688B192E4EULL, 0x35CDC6ED03177BF1ULL, 0x6AF37A792ACFBFDFULL, 0x248D0452A07A1BD4ULL, 
            0x77EE98D622FBA402ULL, 0xD1E23F83EDDB10BBULL, 0x643F6A85DB9C89BCULL, 0x9E68675F8106DD31ULL, 
            0xF7077E733DDFCC1BULL, 0x58BDB66E192D72E4ULL, 0x94115F1CB84D73E9ULL, 0xFF5ED2B7C082F7EAULL, 
            0x1076935791A0C926ULL, 0x858380B31AB7A79EULL, 0xAE786CBC619D7C34ULL, 0x53FA8B97E01E625EULL
        },
        {
            0x145A83B67E2BDB57ULL, 0xD0225AA174955C00ULL, 0xE49892D1E4BEA388ULL, 0x6182CB172519D13DULL, 
            0x5BD832FFC66B426EULL, 0x07D56974C8564943ULL, 0x1F019C95DC71F8CEULL, 0x933789387CBEFB1DULL, 
            0xFD1E43DCD09EDCB9ULL, 0x1CEEAE687123BDF5ULL, 0x407258622704D825ULL, 0x42302BFC79775217ULL, 
            0x6F9B0ADBF31C7A06ULL, 0x074A19EF35FE252FULL, 0x609F620AF6EF6703ULL, 0xACE3B2C3D0117907ULL, 
            0x5BA3801A26221C38ULL, 0xF739EE91BD8B023DULL, 0x6ED0BFC74FF1C7B9ULL, 0x6363B1A6CC3EA4C6ULL, 
            0xBE6741E2EE8405E7ULL, 0x00139E5BB2F48746ULL, 0x4EE4100A9AAF3403ULL, 0x3BE8C3474179E9FEULL, 
            0x3A25438999EB95BAULL, 0xD9FAF4102BBFCA2EULL, 0xC395FC492060ABA2ULL, 0x280B38643C816896ULL, 
            0x3BA6B004B294AE7DULL, 0xA039C8C9AD98DF87ULL, 0x1E528A2790869B4BULL, 0x9FCFFE4275ECF25DULL
        },
        {
            0xA6AFB333159F2718ULL, 0x806A7439FC5B5B91ULL, 0xC832AB7461447026ULL, 0x32F5F5DF28338037ULL, 
            0x9D910D790A12CDE7ULL, 0xA1431D9879CF4E12ULL, 0x0CE22ECDA1257A3FULL, 0xFC3C79990D1B8AC4ULL, 
            0x518E4BC54904FC6DULL, 0x582F8C458698297DULL, 0xCE9965E80287FC19ULL, 0x8B90F2B7720CECD5ULL, 
            0xA9A6D200C72934B8ULL, 0xC9B39F472517492BULL, 0x52EFC329A973E1D2ULL, 0x1A1CEF3FE74546EFULL, 
            0x3431F2B90409B025ULL, 0xB94ACACA8E782906ULL, 0x91BECEF17BEB510FULL, 0x81826EAC8BED9257ULL, 
            0xC8C1337ACBC3A2DDULL, 0xA41038C8487CC410ULL, 0x3F55FFAE3A2A9B13ULL, 0x37F4220A8A900125ULL, 
            0x0CC5DC7D38BEA2AFULL, 0xDC2955C9951EABD1ULL, 0x3A90E0BB1A0C0FF0ULL, 0x244073F710C395BAULL, 
            0x11DC3F17F6C4D101ULL, 0x92459ADF12D10AD3ULL, 0x3C9509C350125FC5ULL, 0xF978F38EC77D8F1DULL
        },
        {
            0xD281BE8078DFF2E1ULL, 0x8F09304EB9A75BDDULL, 0xE07B639A9272B58EULL, 0x2DB69A3D46D85D92ULL, 
            0x1CCC9384297667E3ULL, 0xABC99491E7B26A41ULL, 0x68F414B0F09D8DC9ULL, 0xF9C108423250188AULL, 
            0x5356CA8D65F98220ULL, 0x2DF86EAC12E4ACEBULL, 0xF2778A30C2E6D9B1ULL, 0xA2E67086EBFAB0BAULL, 
            0xE41D4307FD7F1790ULL, 0xD621F43EB9946F0AULL, 0x03BFD91339F5D27DULL, 0xB18455C83D11E22BULL, 
            0xC771FAE7C264BB4CULL, 0x7880926BAD78730AULL, 0x8197F394FEA2FD63ULL, 0x2990720A54513AF2ULL, 
            0x741F3BB9AF0F85A1ULL, 0xFE5311A06C328DCFULL, 0x430C553149488899ULL, 0x0343896AE9DAD431ULL, 
            0x41E154901797839AULL, 0x3346F8B1EEC66FEAULL, 0xCC8E3AFDBA1E78F7ULL, 0x308D6FA344B355AEULL, 
            0x378D529BD483DE6CULL, 0x6056AA578A2990A0ULL, 0x49755B1C42383544ULL, 0x955C76B28B57B682ULL
        },
        {
            0x2995394B697EC815ULL, 0x1D01AF48FAE2C70AULL, 0xD183FFF3B52E0F00ULL, 0x050E92D0F92B394AULL, 
            0xA322C2C71B531E3DULL, 0x5547E8B097141AE7ULL, 0x7A2C892877865EBCULL, 0x9AF2363D1DAFB089ULL, 
            0xEA85908CEE5B143FULL, 0x572133F5ACE7BB5FULL, 0x4BAF3CBE0F3A11A9ULL, 0x45214042D7CE0E13ULL, 
            0x4B5B78B52767A88EULL, 0xFFC112911ECE1760ULL, 0x17684C9B8782FCB9ULL, 0xA7BB49DF01A1FE69ULL, 
            0x9B22728ADFFFF2FAULL, 0xE606484DFF1A974BULL, 0xA7D718F36F771EC4ULL, 0x021D77CA2BA939D0ULL, 
            0xDD6AE5EC4962DE9BULL, 0x59A38E69D515E9ECULL, 0xB2D9E360E668727BULL, 0x8DC727D26EA4697BULL, 
            0x4000547F9AAE0C64ULL, 0x1022C4EE1C581EB0ULL, 0xD8959A03451E608BULL, 0xE7B940F713F33E9FULL, 
            0xF0C66C386803D045ULL, 0x25B45CCACC0EEA95ULL, 0xA9506E6EF263A2D9ULL, 0x4AD1B21A8D6D136EULL
        },
        {
            0x717C53695BE913B0ULL, 0xAA39ABA06A586B2EULL, 0xB4057B3536C6298EULL, 0xA8281E911A9AED83ULL, 
            0x489069271E0DB1F5ULL, 0xC01A83DC12913EFFULL, 0x5245C6046C921E81ULL, 0x3670530203AAC839ULL, 
            0x2BAADE455B535E4AULL, 0x0E90EF2F22920263ULL, 0x5A0354CEF078DA05ULL, 0x78E0AC4E41544ADFULL, 
            0xA6A0C3D147F2AE2CULL, 0x410D88346A00BE9CULL, 0x0BA52DA75590AB1FULL, 0x9109B33FE2D9CAEEULL, 
            0x2CF389D83FA601B8ULL, 0xABFE8AA4AFD0E9DEULL, 0xCA8E8BECE9CAE0E3ULL, 0xC2439157127426F8ULL, 
            0x6C39E5A07E8C2B91ULL, 0x0587E40B14194FA2ULL, 0x70A0F53268D668BBULL, 0x17279B89A7D52E17ULL, 
            0x80147B8B607BA20EULL, 0xBAF7C97078A199A4ULL, 0x38C67D06E52F3D17ULL, 0x8ED571F0930593D1ULL, 
            0x9D5B0DCF35BFB699ULL, 0xFA5B37FD6BF188DEULL, 0xEBB677E6FD07FC3CULL, 0x63518D0EEC4FA845ULL
        }
    },
    {
        {
            0x2B378D132A7BE72EULL, 0x020E946DE71EAF0AULL, 0x5C66B7153024C0FCULL, 0xBDAE0C389316C085ULL, 
            0x5836E8F2496EF4BAULL, 0xE58E2D2803825CB0ULL, 0x49A50FDC7E1CA1EAULL, 0x0DECA19B95B032BCULL, 
            0xFE408824B778F1A3ULL, 0x7DE4AD1CA47A7DF3ULL, 0xC594C9B5DC614525ULL, 0xE7610D4D38C17716ULL, 
            0x6B26E6CE4C64C028ULL, 0x7ABDA74527B0AEBAULL, 0x1661A37C6E605BEFULL, 0x7758994DF007A826ULL, 
            0x4E28DED4687350A8ULL, 0xA024D84E13DB149DULL, 0xCB2807889971B2EBULL, 0xC947FCA17325355AULL, 
            0xA3AAE629026C370BULL, 0x8C8506E52C9B8609ULL, 0x44AE95C1C2A1F339ULL, 0xF41ACDF7819D5EAEULL, 
            0x44001F1CA23E25F0ULL, 0xDC8C172B10B775C6ULL, 0xB2DC11559248A50DULL, 0xD4D4240BB5D05AAEULL, 
            0xD1A8AB5A418A0AC9ULL, 0x9D073F7B3C518AE3ULL, 0x44297B9209CB566DULL, 0x806A63EA40B889ADULL
        },
        {
            0xD3B187BA8327F1E8ULL, 0x7C443E87A38144F6ULL, 0xD87F17E91AEFD5F4ULL, 0xD9547A50BE405BCFULL, 
            0xAF8AC002C4AC89FDULL, 0x69B02B5B511821BFULL, 0x0A6CF6E4BCA44232ULL, 0x3CC69B4E7E6751DAULL, 
            0xF7FEE419ABEFA76EULL, 0x5869EDD534725E67ULL, 0x9A6A70A4BE5DD1CCULL, 0xDAF96745A3E32359ULL, 
            0xDC122AE7A6B4C388ULL, 0x67FAF6D5B9F0DD8DULL, 0x2FA0B15832DBF310ULL, 0x8A082C1A5C853125ULL, 
            0xCC8177955720B4AAULL, 0x014C745D157344A0ULL, 0x8CEDD780AC72FEDDULL, 0x8219A9D87D007548ULL, 
            0xB9C486A11E83F636ULL, 0x4A7694232D89832FULL, 0xEDA0E25D6E658C9AULL, 0x7757A746027EB1A0ULL, 
            0x86F24894E53FCBC8ULL, 0xC4E1CD633A06F57BULL, 0xAF3F51A3CE52C17EULL, 0x3B0CE95F82B1D182ULL, 
            0x7E797902B77E11F5ULL, 0xCA7A6A908F5092CDULL, 0x04E64E3DD635D809ULL, 0xFBFDF88DF63CD4F5ULL
        },
        {
            0xA2791415ECF78D80ULL, 0xC767980BA5CD4C86ULL, 0x8D8C66BFBB5904E2ULL, 0x65B2DD91F86899F0ULL, 
            0x5AD4F352C6BB8458ULL, 0x26625D623836A4B8ULL, 0xF073508ADC1E9179ULL, 0x96FDF83B3BEC7F92ULL, 
            0xEECFC5F03113AD60ULL, 0x31ACFD62D7DF0BD9ULL, 0x64CA25F962E7B51DULL, 0x110269AED8977FCFULL, 
            0xE497BE1C8FE3E109ULL, 0x4B96ECD855BB4C1AULL, 0xC330D5DF47FDA0BFULL, 0xE4A0AE4A441FDF06ULL, 
            0xF6FBBDB6DD816471ULL, 0x4AC48F1A90F8A450ULL, 0xE29AE1031450E114ULL, 0xB666950248C90591ULL, 
            0x10B7C9EBF7B6A33EULL, 0xF368207632026982ULL, 0x6984E02905CA0290ULL, 0xAC181B25494D6422ULL, 
            0xAA8CBCDA318E02F8ULL, 0x4578AE4D5DB807A3ULL, 0xF6D88F94A0B5C55CULL, 0x513C689898BACFF2ULL, 
            0x25F58E77891AAF8AULL, 0x5C4A95DF33BB0DB4ULL, 0xBE3AEA7B8914D1F0ULL, 0x745C18A1092025BFULL
        },
        {
            0xD57B26B9C6BB78D5ULL, 0x8BFB7BBD6A45F75DULL, 0xB5077C1526FDEDF0ULL, 0x972812A2BDCA34B4ULL, 
            0x9558CEF1B26A0A2CULL, 0xB94411000B4DEBB0ULL, 0xE7AEFFA0EBE0D8DCULL, 0xDDBCC0F168B490FAULL, 
            0xA519D771419F7A47ULL, 0x95A2B5603218035FULL, 0x732BD57B2B6E8640ULL, 0xAA2509462E7FCDEBULL, 
            0x0178FAAD27DD92D2ULL, 0x22F8E1AD86A1F988ULL, 0xCAE3959F4DC95D27ULL, 0x79F9E10C372BC881ULL, 
            0x9D739B1F4F6861A0ULL, 0x2B843199AF5E029BULL, 0x6F440053AD98C178ULL, 0x1C6D7C37333EFD22ULL, 
            0xC42D40E3D8E23607ULL, 0xAA491EE8D561BF4BULL, 0x0C23360B476CD925ULL, 0x036565CFE410DF0CULL, 
            0x7617693404A0B9DBULL, 0x39170E2BB57ADCD2ULL, 0x5718297C53BC7B0EULL, 0x1D1B610240B8B584ULL, 
            0xE91A81B2A03426E0ULL, 0x6E5166331CF0D968ULL, 0x04B4A0D24A863B8DULL, 0xFD87560788C7F73EULL
        },
        {
            0x0DE8E7C64A763D6AULL, 0xEC319E02D49DC498ULL, 0x3E21C2CF896B197FULL, 0xBF140429BDC58D1CULL, 
            0x29EE32B9406C4C04ULL, 0x0E6CA50274D099ECULL, 0xA6AD814CAF633372ULL, 0xA264E91493CDD6B8ULL, 
            0x9840A333228107D6ULL, 0x8784A5D4AE5B77D4ULL, 0x1460AD6DABCF5BACULL, 0x2B18C7AF8B8B4085ULL, 
            0x7368C50D079ADF84ULL, 0x9790476BF10C0B63ULL, 0xAAE0285E25C042B8ULL, 0x520C65B89A914044ULL, 
            0x563E0AD07751197DULL, 0xF46CA226FBA752EBULL, 0x65E4DF23599EE428ULL, 0x74FBB1944F4DEBFCULL, 
            0xA72A692865D76063ULL, 0x997D2C473A553F0EULL, 0xEB7FB352BF48D2D2ULL, 0xAD77C95BC1E5F07EULL, 
            0x1B65F00D49555655ULL, 0xF957CFA24406D8ECULL, 0xE3824404721292FEULL, 0x56CA36B030AC7EC7ULL, 
            0x52335A6ADA5A32D1ULL, 0x82353FBB0D5955E9ULL, 0x289169797F0EB7B5ULL, 0x086A59085A80C5CFULL
        },
        {
            0xBC92DBD78277C957ULL, 0xBFB89E8B7CDD0BCFULL, 0x9C953EC227D0BC3AULL, 0x2174D5971CAC3B1FULL, 
            0xB85FB77A03BCDAC5ULL, 0xD3B4F71E68BA8396ULL, 0x622B174B53E63656ULL, 0x1EE65AA42777652DULL, 
            0x0325F426E450E99CULL, 0xF672CC3881F0E197ULL, 0x3DCF3007975B4D81ULL, 0x9491D5D8503EC974ULL, 
            0xBD17258818E31BFBULL, 0x6AF9A8C87188A9EEULL, 0x028F5CAF026100A7ULL, 0xBD1F7A7A7332B794ULL, 
            0x11644A4F9FFE4E1AULL, 0xDAEEC95045AE5BF9ULL, 0x946899D31995BA5FULL, 0x9B2014CDD171C555ULL, 
            0x9832C573138A27CFULL, 0x96E8D2D2B888B7E8ULL, 0x98940479FA4CF10BULL, 0x655B4C48272129A5ULL, 
            0xA301A8BCC03C0087ULL, 0x19C714E0DC3C78DFULL, 0xB01C225262CF2556ULL, 0x238B199BEBD2158AULL, 
            0x18A84DF8D9A37ABCULL, 0x8EC639F3B5A38AA8ULL, 0x10D64ADFB026EA28ULL, 0x9CAE7063DC84EF75ULL
        }
    },
    {
        {
            0x8D33B7216ECF78A3ULL, 0xB262D7510C79FE8AULL, 0xB71E6B1A468FB5D0ULL, 0x205A667C2ABDB190ULL, 
            0xD5396207A7DE9A9EULL, 0xBBB4A15CFE03378DULL, 0x0A734DB1339033C3ULL, 0xC6BA400EE54DF521ULL, 
            0x195A69709349D7AEULL, 0x4E97F7C7DA2238F0ULL, 0xEC44B084EB569891ULL, 0xBEF49E1ED447AE0FULL, 
            0xA11529249020EEE3ULL, 0xB0050F6EDD105351ULL, 0x902C592B8ADE33E4ULL, 0xD6E3DDF386E813D2ULL, 
            0xC0A22606196F9C42ULL, 0xA9F4E1133EAF0088ULL, 0x8FB4F2AEA425A85EULL, 0x9B3EA9BF7095F5FEULL, 
            0x628BF48730E8FEC0ULL, 0x49B8B80F251A0FE5ULL, 0x3195E6FCAEE17AC9ULL, 0xE7BAF07583B8DE80ULL, 
            0xF395CA5C9490924FULL, 0x275CE99A5010971EULL, 0xD1582AB1F010963DULL, 0x535462A8ADB07114ULL, 
            0xA135D2770FDA29CAULL, 0x6247A44E3045AE94ULL, 0x104C466675C9C8A3ULL, 0x74F1491FCA39411DULL
        },
        {
            0x1B1628B9A7B07F21ULL, 0x9F91286094C24615ULL, 0x8046343103080094ULL, 0x6784E5F77720A4E9ULL, 
            0x28904D19808DCAFDULL, 0x473D757EB721F3FAULL, 0x65144C4EAFB22BA8ULL, 0x9260AFB90A9FC005ULL, 
            0x8F715E6A2DC07223ULL, 0x31205ABC1C63D8B3ULL, 0xC2EC271C7FAC0D82ULL, 0x57403612E2EE90EDULL, 
            0xE3BD5DC95DA8F249ULL, 0x9D918F8B90DCD9B6ULL, 0x930CFE8E31F4A978ULL, 0x7598EDD6CA7C7350ULL, 
            0x6401C3791E3F851CULL, 0x95661C13407E0326ULL, 0x5AD8DBEA722FF943ULL, 0xDB4F64AD1D793E8FULL, 
            0x11547CE44676BFA9ULL, 0xEADB5778BA8AEC72ULL, 0xF17D038FAC658353ULL, 0x80FF83E20D83DD6BULL, 
            0xDBD1B73AC98F9B73ULL, 0x76F0AA6BB139D448ULL, 0x83FC4823F0F86987ULL, 0x9FA59105FC146004ULL, 
            0xF705B11955AE4816ULL, 0x1E7986A289CB44E7ULL, 0x6EE7D28AB743695BULL, 0x8E925A00D1A84B97ULL
        },
        {
            0x99D68C7514F39EADULL, 0x8E92A2B77A6444AFULL, 0xD3DBCF4AD978F26BULL, 0x00953C3E760EE534ULL, 
            0xB9FB3B82E681DF77ULL, 0x66BAF9F658CED5E1ULL, 0x110BD0A9CF754130ULL, 0x5DC16119BB267C56ULL, 
            0x19F22443AF3818ADULL, 0x1484E68BA9234B44ULL, 0xB2EBC8EADF6965AAULL, 0xAA2396E04192C2C1ULL, 
            0x1D830D572A4EBD2FULL, 0x0B3B19D3ADE5F6C4ULL, 0x3FA37DD9772C9C3FULL, 0x01157BF034F10037ULL, 
            0x21D85C2108CBC19DULL, 0x83ED24096143295AULL, 0x6A4275867E604E72ULL, 0x3E449C9C32A52CABULL, 
            0x0300A7AF476B0DFAULL, 0xAF37D7E34EC7BCD9ULL, 0xF0A9E5FD38D6C2B1ULL, 0x8706785CE45D3037ULL, 
            0x31D8DBC2DC353649ULL, 0x81561C702601CB0EULL, 0x73EA00984CBB3F65ULL, 0x5024F1BFD2EF942DULL, 
            0x1FE08574BAE6D3A6ULL, 0x156E17FAC85C71A5ULL, 0x4D28E0A41CEB4550ULL, 0xD253018836593C82ULL
        },
        {
            0x0833CA7CA6C477FFULL, 0x9C028927F4082103ULL, 0x5A032DA74B07A0E5ULL, 0x3D3EE95833BF0274ULL, 
            0xA9B7A1DA06284D44ULL, 0x8C4206F14FD1C64EULL, 0x7B6E78B64AE7B9AEULL, 0x053858F82FBC3804ULL, 
            0x282708280B01A128ULL, 0xD6956A0DDE59A198ULL, 0x481285F34EFA7F61ULL, 0x49973AD2B80E1E8CULL, 
            0x73FF078943E7A028ULL, 0x9FBB52B3B7D3BE57ULL, 0x09273D2412008FFFULL, 0x0D85C8C5CD578EADULL, 
            0x1C4CED00F99022B9ULL, 0x1EA6F98D4D02C817ULL, 0x6E1ADC520D75C347ULL, 0x68D9496DBF801241ULL, 
            0x50B39FF7B5FAD59BULL, 0x0E6ADF614362B847ULL, 0x3EA953CCE166EFF9ULL, 0x17EF2A1D5B0BCE7AULL, 
            0xA01B3BF5FA6708BCULL, 0xDDFB23B71E38A21CULL, 0xF04645BAC92ED90AULL, 0x6642E4E7BCE048CFULL, 
            0x59AFCB6D0E5786E5ULL, 0xF560E13D97FAE9A3ULL, 0xCB2BFBD796868EE7ULL, 0x3420AE4DCC983EA9ULL
        },
        {
            0x060C89239A123343ULL, 0xEC0AD441B2CFF480ULL, 0x0277D70065092429ULL, 0x8F20217A37CAF17CULL, 
            0x023FE6AE2CD1A12AULL, 0xA0F78008CA1564B3ULL, 0x10B23893DF4A40E0ULL, 0x02F5AB5B33EA72D7ULL, 
            0x02E21669185F637FULL, 0xB1EE4BB94C82AB78ULL, 0x45B7C5C48C315B8FULL, 0x75A08E0036DBB71FULL, 
            0x9D0A34E2E02B341FULL, 0x96A218E6EF0E6977ULL, 0x52F9037DF688EBC4ULL, 0x0EFF288B18DEC407ULL, 
            0x88EB8125494EB153ULL, 0x3A3E20CFC18D4090ULL, 0xC1BCBF7FB5E335A2ULL, 0xC311C91A14031E3FULL, 
            0xCC0B47A8793A7830ULL, 0x583F83583C7B774BULL, 0x230C17B029E2883CULL, 0x63B7FA765EA1BC43ULL, 
            0x2D8D9A58C1E544A1ULL, 0xA34ED56A5522EBA5ULL, 0x43F7F99DBD69E842ULL, 0x96EB9B2884236D2CULL, 
            0x161792AEC45B06E0ULL, 0x91B00A0EE0ACEB11ULL, 0x0F1948968E2386A6ULL, 0x8234327D72B20A07ULL
        },
        {
            0xDFEC4E1F81023E70ULL, 0x4C49861E5EA428B1ULL, 0xAA930CC7C9992E16ULL, 0x5E56A58EEFAB5376ULL, 
            0x1416DA2DDB41A653ULL, 0x3FC8AE105266F432ULL, 0x2B8C56B2C15827C1ULL, 0x4CA48C8E28E03EB1ULL, 
            0x7C8A932F0303850FULL, 0x4EF6A9F7F9E00528ULL, 0x23F0645D78A44522ULL, 0xAB518C880C1CE507ULL, 
            0x91BEEBAD4C73292CULL, 0xBCE3D89414A99B27ULL, 0xB8608B7F3030F189ULL, 0x7300443678E55188ULL, 
            0x57D613B92BC3A15CULL, 0x8B4371B0ADF27DD3ULL, 0xE340460F2CE5496EULL, 0x7B3000EC45B376AAULL, 
            0x85AC19AD2BDA25D4ULL, 0x2F01F3D20DFC6D0DULL, 0xC26F886E6395D0AFULL, 0xC9FB3D4AF91A6CB1ULL, 
            0x74F1489BEABA8670ULL, 0xACAEC59B379FD61EULL, 0x0A86F40D30CF7251ULL, 0x66FAA92783D56602ULL, 
            0x8507831C83DEC0ACULL, 0x29596943E027B5A7ULL, 0x3377329D92F6B7ADULL, 0x8F1F6C2F1D026F10ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseDConstants = {
    0xA7D372AC871C5F92ULL,
    0xC310D5CA2786A161ULL,
    0x904A526DBEB61781ULL,
    0xA7D372AC871C5F92ULL,
    0xC310D5CA2786A161ULL,
    0x904A526DBEB61781ULL,
    0xABDAB964048DC3BEULL,
    0xD8C3D6E4A5B459DBULL,
    0x0B,
    0xFE,
    0xA5,
    0x97,
    0xC9,
    0x4D,
    0x94,
    0x16
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseESalts = {
    {
        {
            0x2824BE6AA347F578ULL, 0x8472DF62793D7799ULL, 0xC65634A3976AF3B3ULL, 0x465E0769E3A6B3ACULL, 
            0xE99A28E343071786ULL, 0xB02A2EEBDF25A0D1ULL, 0xFA6232516812FB8CULL, 0x0389CC81D6C8F3A3ULL, 
            0x125BF1435A496848ULL, 0xFD74CA64988A383EULL, 0xACE52FA73FCC2B79ULL, 0x656240D36606F9C1ULL, 
            0xE15B7FD785640BBFULL, 0x77713B578DC3335FULL, 0x6EAA95FE99C3B042ULL, 0xBEDA7D94AFDEE9AEULL, 
            0x1BA07AB1AEC1D0F1ULL, 0xF54BF3DE28D6ED37ULL, 0x582E4C51952DD781ULL, 0x707D2F840B969752ULL, 
            0xB23BB8CF2D9F2746ULL, 0x5B4A1F8CA1EA9A06ULL, 0x5D0F01BCD7E6BED8ULL, 0x3DC3EC1D6F29E942ULL, 
            0x30706A52392FDD50ULL, 0x31D7D1347F808F9DULL, 0xC3A69F24B67813AFULL, 0x4FE9435857F0E654ULL, 
            0xC59C35D53D76DF7BULL, 0x9F0DC90CED671E4DULL, 0x919C44B22B67009EULL, 0x6F3791F564405ECBULL
        },
        {
            0xE0444556C1FF7C59ULL, 0xB592E466167EF848ULL, 0x6CDD09B5354CE610ULL, 0x3C64647FB51FBD28ULL, 
            0x11A54342BA6678AAULL, 0x0938A5FECDD9CD43ULL, 0x189A571A71DFC339ULL, 0xD5D67142CCE404E2ULL, 
            0x14751ACB63909692ULL, 0xD0E81E356ABFE573ULL, 0x0BBB39343ACBAEC4ULL, 0x783293E68225A12AULL, 
            0xB8BD63377E839EC3ULL, 0x22F064F8F5A56731ULL, 0xE75AA95AE9E42B7DULL, 0x7A7C7943942B80E0ULL, 
            0x1D7EF7A26F040DB3ULL, 0xD6695F6E8493C990ULL, 0x9FCF3F895B79263BULL, 0x609722BC8C180FB6ULL, 
            0xA14527D8501AA991ULL, 0xB65D4137C03F1E62ULL, 0x6D9C00FDA03AD93DULL, 0x23336A3272789CB7ULL, 
            0x0C06F1E0400A03EDULL, 0xB2444ADD5CFAE0D2ULL, 0x898E61FCA3A3EEA9ULL, 0x0BA18DBE4A3B98B6ULL, 
            0xDE1448E21F0CC37CULL, 0x82D5608F887D2B0EULL, 0x19C1325CFF5E27C4ULL, 0x57365CFF7AF39A66ULL
        },
        {
            0x1F20E536EBF4A6E0ULL, 0x89AFBECB7B521DFFULL, 0x1CBD708F7DD6AB42ULL, 0x0531D3C84C97B689ULL, 
            0x7F1A968738B6A0D6ULL, 0x2FD5FB17B4AD8DA1ULL, 0xC24C58EB159720A3ULL, 0x89529D7811BF23F7ULL, 
            0x3F224B169ECC4585ULL, 0x2423A6D5ACB16DE1ULL, 0x6A8DA49B1A87A0C2ULL, 0x994D36D1805DA0CCULL, 
            0xDA6C39B17C8B036DULL, 0xEC1AB6A7E22415E5ULL, 0x32303B0BC9599D41ULL, 0x4FDBB2F2A6AE2179ULL, 
            0x5E716C1B62BB9AEAULL, 0x3CA661D8D5CA976AULL, 0xCE64036A8987A0B4ULL, 0x9AF08AB5D955EDBDULL, 
            0x7746698B42E6FF81ULL, 0xA355F0A61167DD1EULL, 0x7A37B6694BE87D27ULL, 0x811670E8E663D9CDULL, 
            0x2C262C997B8228F1ULL, 0xA3470C044EBA825EULL, 0x00B94C3525FBFEA1ULL, 0x2A3B255938C9E149ULL, 
            0x9283EDF75505859BULL, 0x62E7FC95346B34F0ULL, 0xD5B391110D50C543ULL, 0x48B16F5CCB97018EULL
        },
        {
            0x262DC24DDD766989ULL, 0x30D0B612753F3234ULL, 0xA1D44466C247DE4AULL, 0x9ABB8F3B41203883ULL, 
            0xB6459541F2B8962EULL, 0x8462DA757D8A6984ULL, 0xBB38481B264CEBEFULL, 0x06923DD134FDD167ULL, 
            0xFD418F623B3912E6ULL, 0xAAA05102D2A561A3ULL, 0x56D441D3EA7EB87CULL, 0x770154B03915CA45ULL, 
            0xC29D84CA8614C092ULL, 0xB4D14380C282B24AULL, 0xDFE05D056077E17CULL, 0x91CC1C43729D5E81ULL, 
            0xF5B2E48EAF67A8E8ULL, 0x4AF7278407615363ULL, 0xC8E156A2B117DE51ULL, 0x8E4021060888BD62ULL, 
            0x7E14D8BCEF79AE3CULL, 0x6C0AC4EEC49BEE3AULL, 0x3916BDF868C5274DULL, 0x2581AD9BA23BA364ULL, 
            0xEA96EF6ED36339D9ULL, 0x4513EE6117DEC9B7ULL, 0xC5E4B1F21213F57EULL, 0x477F3B0DE792CB7BULL, 
            0x3175E06B93C5D679ULL, 0xC710C29161DE9A66ULL, 0xE8535611D0DA661EULL, 0x223EF107F1611235ULL
        },
        {
            0x958FC60138C9DAB8ULL, 0x7ED8556B6C9C99CFULL, 0x32C1649A94605EE3ULL, 0xC7BA449263501E1FULL, 
            0x2F8A14E0D626AD51ULL, 0xC20A8B81AF468869ULL, 0xB76636A3C4E89164ULL, 0xBFE90BD0DDCCD61BULL, 
            0x2DD348F6049C2B8BULL, 0x6EF150ED6A143293ULL, 0x6A018927702E8EDCULL, 0xBEDABF7732A9A7F2ULL, 
            0xFEE79F61A18732FCULL, 0x1DA91B11AF6EF53DULL, 0x3311A93A827F10BEULL, 0xD6E3ECCDD2B66E8DULL, 
            0x74F13EB533C7E9BFULL, 0xE9E8253FBA28E848ULL, 0xC2268CE55F2433A2ULL, 0x99ECD45C3E00D158ULL, 
            0x036470181D82189AULL, 0x556D14E66F386A56ULL, 0xFDCAE06A7C64B6DEULL, 0xE0EA17196F91B1CAULL, 
            0x50DE141D8EA83750ULL, 0xCE1DBD270147C63FULL, 0xB13DCEFB7342CDADULL, 0xEB768DAFCB1E73A2ULL, 
            0xBCAE9CC9D483A9BFULL, 0xB0FC463920B4332FULL, 0x3A2F53B74D903E82ULL, 0xFCD8E5981C70AB50ULL
        },
        {
            0x5F2D1F161DA39E12ULL, 0xA92425E0FC6EA311ULL, 0xB4D457E66109AC86ULL, 0x664031A3C7F2765EULL, 
            0x2566F726B74EF41BULL, 0xA60E7BEF18252AA6ULL, 0x2CFCF9E46905AA8BULL, 0x1A8B95D129B71BA5ULL, 
            0x70A30EAA6106F3EBULL, 0xBBE3729DDAE9B875ULL, 0xDCBBD615274198ACULL, 0x237F8936F67059A1ULL, 
            0x4688305A440A82B1ULL, 0x77E19E8608A567F0ULL, 0x7B248DF6EEA02B8EULL, 0x55E591C57025B239ULL, 
            0x3A12C8DB5F2AFFA7ULL, 0xBF75DC25AA9B68CFULL, 0x21CCFC8F6C41609DULL, 0x710E20374672D922ULL, 
            0x5DC015BACFB73FE0ULL, 0xF98B5C2C9305EC06ULL, 0x2371E44CA8850012ULL, 0xC194395DC2385B8FULL, 
            0xCA2BC42AD67433A2ULL, 0xB0C071539453AB03ULL, 0xFC720F0E756A6184ULL, 0x3F3B6342A829C588ULL, 
            0x1C0C0E84382F1D46ULL, 0xF6D2473891174000ULL, 0x84BEDC5A27C08695ULL, 0x8EC1FFE917D01A87ULL
        }
    },
    {
        {
            0xDDF58EDF64359844ULL, 0xEE9404E9F535ECA2ULL, 0x698C54CC7B2BDC24ULL, 0x0AC84FC3F39BEE49ULL, 
            0x804678A726DB7D66ULL, 0x36672922D3D9C56CULL, 0xE3A3087D7BABD68CULL, 0x5980FADC758C33E2ULL, 
            0x1A151E5E4451E2FFULL, 0x1870616258AC4ABEULL, 0x71FEAC7798E9F890ULL, 0x9987AF7A495C8077ULL, 
            0xBE65FFA9E4E73ADBULL, 0xDAA42035F7657F6EULL, 0xB0B7D3F97E5DAE03ULL, 0x921D4ED6F9E7CEA9ULL, 
            0xEE2777613B810AA0ULL, 0x574CF20D5D209DCEULL, 0xCC9B4A690061092BULL, 0xB6E33DE6CA692A2AULL, 
            0x2217A090A7580112ULL, 0x46CBC91468B963A2ULL, 0x491D93CFD3B51D52ULL, 0x09A6A38E6D57627CULL, 
            0xBE3FA9AD3F787CA3ULL, 0x760779A0E03F4E44ULL, 0x3EC40CCC2301D6A2ULL, 0x89F8914D2FECFA84ULL, 
            0xA38EA6CAD0A6A6B9ULL, 0x8900113C92D34D20ULL, 0x9256E23601963309ULL, 0xDBCF9DF5B2D59B56ULL
        },
        {
            0xD948EF418490C017ULL, 0x4D0D32F30B528663ULL, 0xD61A2020E0FFABA9ULL, 0x867FFD4884248A42ULL, 
            0xCCE3A3E643F6E9E3ULL, 0xAABF73BB1E3A08C9ULL, 0x7B5C88C9C790269CULL, 0x77D143046A79F2F1ULL, 
            0x7D553D354FA62D65ULL, 0x8609D30591610F60ULL, 0xAF5997EBE9EEB16BULL, 0x8F376F867C33A305ULL, 
            0x28F88B727E08EFC1ULL, 0xAF8DD3BF17B00097ULL, 0x53E8F9E2748967F5ULL, 0x6DC4781A0878ABDDULL, 
            0x592F2B59F7A684A5ULL, 0x3EF11F25478BD019ULL, 0x0AF1ECE73F79D419ULL, 0x75CE4CAF062BA62CULL, 
            0x32E69BF97D6D9C0BULL, 0x7DB094E891F3C5BAULL, 0x8B2BC5105276F9A0ULL, 0xD70EED865AB503CCULL, 
            0xD1B5BCAA37DD5376ULL, 0x7CE9EAAE37AAC83FULL, 0x5FECDA432589CE8FULL, 0xC17682FC9516024DULL, 
            0x37A0414CA0737C7FULL, 0x2CAB0ED232A056CBULL, 0xD373749BD55FD52DULL, 0x990E5CEB330101EDULL
        },
        {
            0xB8501512B4FFC974ULL, 0x414278FAF030CE27ULL, 0x35D5E9333C353167ULL, 0x74B5CA39D99B4C1BULL, 
            0xFF1B2415B15D89A2ULL, 0x7769AF2815554C27ULL, 0x77F764A6CA7CD675ULL, 0x28F0D85519633E89ULL, 
            0x7622C10BA4C7F2B0ULL, 0xD230E1C38ACFCBEEULL, 0x1FDBB429C8490D29ULL, 0xBC82A89C256ACEAEULL, 
            0x283C14C8F3DDC9C3ULL, 0xF737AA7D39DF5F91ULL, 0x90B95543DF540981ULL, 0xE35EB7C7043D5888ULL, 
            0xD020A05A86925233ULL, 0x84DD8191F4D6E67CULL, 0x50C92DE29021E888ULL, 0x33C963DFB62FEB98ULL, 
            0xB183B52D5CA051BDULL, 0xFF12CD78DD04F252ULL, 0xB3E7F9AB44D44380ULL, 0xDC6F97788BFC8AC1ULL, 
            0xFC392B45C67538E3ULL, 0x3C0DE271BE57B4A5ULL, 0xE69EC0771CF9E79AULL, 0x2CDB3BF89C7D081AULL, 
            0x8CE453F34C2537B5ULL, 0xBD94179A60769EC7ULL, 0x649E0FD242454B62ULL, 0xF28722428BEBC626ULL
        },
        {
            0x00D210E9D741007CULL, 0x647C9483E9D2CB41ULL, 0xDBCB9F4E7536C6B6ULL, 0xA74F5DEFC3799630ULL, 
            0x3AD5F97891A79211ULL, 0x9FC21ED5A737216DULL, 0x08FB6DC23CBBE6C2ULL, 0xEE7F0A3D67C46552ULL, 
            0xC4E4B4535BDBB4A5ULL, 0x02E51C2C44D21A03ULL, 0x6A7252821F74E557ULL, 0xCA40CC21ED31B7F7ULL, 
            0x0F5B25E27234DCF9ULL, 0x306DBC366B37B2A8ULL, 0x13557B75ECF4BC61ULL, 0x9494F55F71A24519ULL, 
            0xE4E374D300B095A0ULL, 0x61346A1294F6DDC6ULL, 0x822EAF3C6D66F624ULL, 0x7FCE0729D15A5CD5ULL, 
            0x76E10338438BEBFEULL, 0xC81C57DE1379CB7BULL, 0xFF4483AB27EFB84FULL, 0x40735B3F8D63C513ULL, 
            0x27B828A451588506ULL, 0xFD55F533F0E9D2D4ULL, 0x66970485CD481FDDULL, 0x4ABA56E288002DAEULL, 
            0xFA87137F5793372CULL, 0x003FB3F142828AA5ULL, 0x05D20265B90745DAULL, 0x81DE0C9B56A244DCULL
        },
        {
            0x677F775ED3D8BEA0ULL, 0x4092EB4D41318448ULL, 0x1F585506583A8B7CULL, 0x8E014DB681627D94ULL, 
            0x8A025F8801F1F0C0ULL, 0x80D784257DCE2515ULL, 0xB934E403DCF90A64ULL, 0x023C4658313D1103ULL, 
            0x1BABB7A8EAEB4568ULL, 0x9336F3726CE86CF5ULL, 0x415A662B7C634777ULL, 0xC2691172D2F802F3ULL, 
            0x4165C1147B168844ULL, 0xE2A0080C699C583BULL, 0xB3A3215D4821BCADULL, 0xB9A250629DEDB379ULL, 
            0x9CE2B529817893B9ULL, 0x1E4B7478D78D3B72ULL, 0x7AC045F8BE0EEB93ULL, 0x44EBF2E9EBEAC4C9ULL, 
            0x92301F2F4746DDA7ULL, 0xF4C4CD333347A754ULL, 0x81B62C6DC5319D49ULL, 0x73EEA6CCCFEA55D0ULL, 
            0x14A8EF5803CAA075ULL, 0xDF7E1922EC1D8523ULL, 0xC89F78E570D75DDBULL, 0xC4203429FBFCE6BAULL, 
            0x01836C43BAE9E50BULL, 0x8249864778EF133EULL, 0xA1247A244F2EAD4BULL, 0x2F70F7FD09862472ULL
        },
        {
            0x7EC6253B71FBB961ULL, 0x30FBB0F834CD335FULL, 0xDFB3CE1F1B73EB5EULL, 0x46FA4D6AE3E3A5F8ULL, 
            0x9984AAC3233DD029ULL, 0xBF5CBB71C00DB068ULL, 0xCAEDFF600B828549ULL, 0x20DE92D6DCC9EEDFULL, 
            0x7E7102526BB552D9ULL, 0x66CE84F0FD8424B5ULL, 0x1E4A0923324D60F4ULL, 0xF9A97D2C42A91D32ULL, 
            0x902CBA55F6CF15B8ULL, 0xD5B82211B58AC997ULL, 0xFC1AFC4AB3753ADFULL, 0x346FF74D15A8ADC8ULL, 
            0xE853BAE0188A58E8ULL, 0xF78BC446F87209B6ULL, 0x17B14C7D7CA22F9CULL, 0x6BDD1D43817DC73FULL, 
            0xCF3CD4F9723E1930ULL, 0xE5E18928A7D32B62ULL, 0x5E5650E74E9954BDULL, 0x10DC118F48E7E83AULL, 
            0xE86968F189BE1070ULL, 0x7122E9CEFA9B84B2ULL, 0xCB91064FB92DDD0CULL, 0x556AAC507D1C5417ULL, 
            0x2708585AA1C0D074ULL, 0x04146E3347360809ULL, 0x05E29ACCFCA76612ULL, 0xA13B41CCEA68E09EULL
        }
    },
    {
        {
            0x94DB894AF1133860ULL, 0xBEE182F5B0D8669AULL, 0xD5DD65C919C7FBEBULL, 0xAD9A9121A6CC7A42ULL, 
            0xF5227C59E231AF2BULL, 0x769B067814BAA05EULL, 0x7493E683DE86643DULL, 0x0D4BD08C0D704BBAULL, 
            0xE939656C34DEECB0ULL, 0x3147D6D8F82FD779ULL, 0xB1B80F198BF15472ULL, 0x02728823F07EE7B4ULL, 
            0xDC51BBE67E490308ULL, 0xCE2C7740AD8AB230ULL, 0x66FCC55D4B6FD258ULL, 0x51E54C8F92D5FCB9ULL, 
            0x5FA9AF12E4511257ULL, 0x66F4F5A7B0AA9E50ULL, 0x82267C2CC7CEF731ULL, 0xA48B5F2194B39440ULL, 
            0x6814125D4664C036ULL, 0x6AD024CAAEBA0BBBULL, 0x428B2890221FD95BULL, 0x3C9755C189EA6EA1ULL, 
            0xB7521F0601C091BBULL, 0x1436F95ED52AB595ULL, 0xCF6066D2269CEDD7ULL, 0xE56E57F5BC3F7AFCULL, 
            0x0C4913AFFE68E0BBULL, 0xE4349923272AF34FULL, 0x9685C596C281ACB2ULL, 0x020BA75CC9CD596BULL
        },
        {
            0xE44868C473BF6EEBULL, 0x424F7A785BBB1F63ULL, 0xFB51368641C716E4ULL, 0x6ABE80A88FC95494ULL, 
            0xF8CAE71900004298ULL, 0xF4CE93E79A7B1742ULL, 0x697BCEF168FF74BFULL, 0x7510CEA0B6B732BBULL, 
            0xD0DACB60AA1F7415ULL, 0x0F9C9CADDAD8089EULL, 0x18D38D1AF4CFC3F0ULL, 0xC269BE9E5C2B4593ULL, 
            0x19552311FA131FE3ULL, 0x067082EEA59FE126ULL, 0x17417C38F7C93135ULL, 0x85BDADC5F984DDC3ULL, 
            0x9199AF5A69477B13ULL, 0x6DF6BD257BA60D44ULL, 0x2F1FE8D113B77E1AULL, 0x975999D0777451F7ULL, 
            0x2C898C56832FD0ECULL, 0xF2CEA5A9D4F619ACULL, 0xF1392335E9FB4FCBULL, 0x0E8E170E8AC1DDC8ULL, 
            0xCC4977C3F0EFD647ULL, 0x9984B40670197024ULL, 0x0FA1499CE323CE4BULL, 0x8A89A65E74F2EFF4ULL, 
            0x97FAA1986E35DF57ULL, 0x2E3C5CBB391C8E54ULL, 0x2ABC7B4250DB4D27ULL, 0xE017AC2DB35C0457ULL
        },
        {
            0x1A250F3B7E468E29ULL, 0x2B4318FAABF2FF42ULL, 0xEFAD2A38239D4BD0ULL, 0x939A65B1BC2C1934ULL, 
            0x83512A5D60618B85ULL, 0xAB581E8484459C2CULL, 0x787A088ADC86E66DULL, 0x6B3BD6A7CA8CF8FDULL, 
            0x28039CAA3CEF3B13ULL, 0x9A5C839C07F51B02ULL, 0x1268C0AF3E1B96B5ULL, 0xB60356896B9EDF8BULL, 
            0xA5E3D1BCB54E3E07ULL, 0xC62FEB6D74CB9EDFULL, 0x89F3DB38F413A63AULL, 0x7113C671E3F538CFULL, 
            0x5542AFC12560FF7BULL, 0xFFE8386780F4E90BULL, 0xEE55232C240EFCACULL, 0x49A955D6B9D157FFULL, 
            0x15618241EAF8DCD1ULL, 0x994E4E364BDC69E5ULL, 0xFF0FD95F165FA5EBULL, 0x922AB3C7A3421E33ULL, 
            0x656F6558B65CF72BULL, 0xFC794A538777D6E9ULL, 0xB4CDB555631C3A53ULL, 0x7E0949A24A12871BULL, 
            0x721EF9591B0FA7B7ULL, 0x7CD3E55A0CEB7DA7ULL, 0x4C8F99F9A64D517CULL, 0xC24E7A97B49420FDULL
        },
        {
            0x309C78F054A811F5ULL, 0x87B1F6E4C2499854ULL, 0xB7F24EA4FD91CD95ULL, 0x3FCB60AC55D66B3AULL, 
            0xE51DBB2F636829E8ULL, 0x5EDC1579E31FFC98ULL, 0x91702ACFAC6BDC2BULL, 0x4BA9049490B510B1ULL, 
            0x385D2F661F495F34ULL, 0x59F29124E6D056E2ULL, 0x35D9BD2B4718F7BDULL, 0x8C5D6DDD8976BA1DULL, 
            0x5A93600B2319EDD6ULL, 0xA0E36C4993EA3E98ULL, 0x241F3FA8D8057476ULL, 0x713A4122B58E3FFFULL, 
            0xF0E7996A8DDCD7E7ULL, 0xEAFEEFA1A86F0BA7ULL, 0x6F38B058FD3777C3ULL, 0xBC08625587AA84C8ULL, 
            0x0FD24172B6DBB0C0ULL, 0xD437C7CD59E722C0ULL, 0x9F93E98D81415FC3ULL, 0x5F6E18DD6DD01749ULL, 
            0x7F335C99CF610A8DULL, 0x451E5AE571AB251EULL, 0xA7C1F32891C1789BULL, 0xB200BB94E1D4750EULL, 
            0xCFDBA20570481247ULL, 0x4D814BB337740EAAULL, 0xDF7209B5294E37EBULL, 0x5F6C20019070A559ULL
        },
        {
            0x2F8B2355520FD875ULL, 0x4BBF76BC1AEC05B6ULL, 0x833EABC536F6F4CDULL, 0xC1149412235339FDULL, 
            0xBEEDCE8EFB056482ULL, 0x99E629A0E80E62AAULL, 0x01CEDCC97584F2FEULL, 0x73F66D752A52C6B8ULL, 
            0xB161ED489F6CA99CULL, 0x70CA51DFDD2B239DULL, 0x2B96270B187BAE55ULL, 0x4E441F3061ADDF2BULL, 
            0x4FA7DAA33FA8E807ULL, 0x0B9A9DCA453E2D6CULL, 0x159E7000539F52BEULL, 0xA43B44BC5ECEE580ULL, 
            0xBA8189E124CF63ABULL, 0xCA969E26F40CC1B5ULL, 0xBDDBD3C8E57CA71FULL, 0xAC3397F2BCDC67BAULL, 
            0xEEB6A655D50A7378ULL, 0xFFE2A2F4EB267682ULL, 0x76E416CD1D11B62EULL, 0x397D6A6652694735ULL, 
            0x16147AD01F4FE8C5ULL, 0xAEC52ADA8E2554DEULL, 0xDDFFDEBE96B4EA9DULL, 0x75E8E3B68E8A6AE6ULL, 
            0xAC83437612F7829BULL, 0x01996FAD2B239C19ULL, 0xBB02F2E553CC8C4DULL, 0xAC93BA9BB5650EBDULL
        },
        {
            0x45358AE79D611D81ULL, 0x651CF6A4B51AE1C5ULL, 0x32488F392C917131ULL, 0x3A80B6AAD4DD33C8ULL, 
            0x775D5F29BA103E05ULL, 0xF5591CB7399605CBULL, 0x2A1B71F76BA3B7B9ULL, 0xD031D4B82B20054DULL, 
            0x5AADA7D1B8A4699AULL, 0xFC3233798DCC2743ULL, 0x7500E5EFB57DB731ULL, 0xB6EAC68C83B2D08BULL, 
            0x2C8E78EEA5A17D5DULL, 0xDD294BF120D48BADULL, 0x6E86BE738C0407DCULL, 0xB5EB6886B2994D31ULL, 
            0xD7DC410E60417D31ULL, 0x52F38326DCA26825ULL, 0xCF53FB003F5F923DULL, 0xF1F8883527327187ULL, 
            0xEFCD42EE84C0B16AULL, 0x3BB1D586DD7450DDULL, 0x0678E2AA5497B8CEULL, 0x87B1049F349759C5ULL, 
            0x426715BF4AB471CCULL, 0x78658799A036FB90ULL, 0x0216D5914940A84AULL, 0x7A8198D9A4AF4509ULL, 
            0xD1E82801622DE79AULL, 0xA3434C0E86CCFB52ULL, 0xE99912A3B6920FD5ULL, 0x20B085F7E0A1A7B3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseEConstants = {
    0x7951307F16A3C4A5ULL,
    0x9B530B7CBE541F83ULL,
    0x930803DB2022AE66ULL,
    0x7951307F16A3C4A5ULL,
    0x9B530B7CBE541F83ULL,
    0x930803DB2022AE66ULL,
    0xEBB2B22D2603F827ULL,
    0x0C0389BEC5344E1DULL,
    0x0A,
    0x74,
    0xF7,
    0xFE,
    0xBC,
    0xBE,
    0x7E,
    0xEC
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseFSalts = {
    {
        {
            0x66FF102B2B079638ULL, 0x2FE73127CBF8F108ULL, 0x5CE985747D326BADULL, 0xF3604B83C5C0DAA1ULL, 
            0x1BDDC856CC838A73ULL, 0x87512F8E85CFFCD0ULL, 0x00AF31E2178BACF3ULL, 0xA009B814C5CEE885ULL, 
            0x6BBD2CB6380954DBULL, 0xF39217FE03629559ULL, 0x0CDC9327416015B4ULL, 0xADEB66C36D84D825ULL, 
            0x366792D3782F84B9ULL, 0x41BEC65C68D8DCA9ULL, 0x81787EFE1AC4CCBFULL, 0x62CDB6FD86912B1BULL, 
            0xAE322A2928AC61B1ULL, 0xCBD2B993D46232CFULL, 0x0F32A7FADA1DBFC4ULL, 0xE31F84FA9C45959FULL, 
            0x82ACFF2791822E1BULL, 0x155FDCA5B084737FULL, 0xE4DC036E710A8261ULL, 0x9C5740C8623B38C5ULL, 
            0x2F943DAE9504E33FULL, 0x041C633EA86C0F02ULL, 0x41C1D0167DDDED3DULL, 0x274EF82CC37F9720ULL, 
            0xAB6028BE8C2DFDFFULL, 0x037E71A8E22F3089ULL, 0x611B8A2910848147ULL, 0xF4074B2A56B0ED48ULL
        },
        {
            0x87F75E374B1C0061ULL, 0xC98AD53149AECE86ULL, 0xFE41D66AA82DBE5FULL, 0xA3AFD9B0F93095FFULL, 
            0xA9F3FBB6DE7A6A1DULL, 0x6C03BB5E3526DD0CULL, 0xB85EB58B86405160ULL, 0x22B7ABA1269C50F4ULL, 
            0xC0C098584283E39DULL, 0x8B6A89FAB32C7F37ULL, 0x59291589E425D2C2ULL, 0x3548F44BA3D97844ULL, 
            0xD6DDD710DE387CC3ULL, 0x62D917678D836B2EULL, 0x48ED529D960B5664ULL, 0xB163A05B1A2C2B61ULL, 
            0x595A2A3297FAC4CDULL, 0x600DF117FE0F03CBULL, 0xEA2C7A4545E6F597ULL, 0xBC951E9009593BE6ULL, 
            0x715296D1C8EF0E71ULL, 0x624DDD18D74738F8ULL, 0xF96141D34A5D2DBEULL, 0x01714C922FECA246ULL, 
            0x8BA07194DC53268BULL, 0x73A3689F808491F9ULL, 0x82B0888238686155ULL, 0x65271ADD74DA2C2FULL, 
            0x6F7FDF6FFA99B177ULL, 0x7D031AD42ED4DADBULL, 0x4CBF02638AD4BDF3ULL, 0x724FB96D4E311197ULL
        },
        {
            0x685AE03D6C858B33ULL, 0xDC833007C9E93C55ULL, 0x7D29D4CBB7A98615ULL, 0x202388D2FE1774AAULL, 
            0x32EE6113653FDF08ULL, 0xD3CB827F3F0943BEULL, 0x4EB72294ED474837ULL, 0xFA217D4F31AFD6FEULL, 
            0xE0EC45A87869AA49ULL, 0x10D9B659F9F4DC79ULL, 0x4E94D90DF7A37F2DULL, 0xA219E771AFFDE3BBULL, 
            0x29FF3A1D7D1009D2ULL, 0xD65A58046C1080ABULL, 0xC5C78712F7694E22ULL, 0xF5685C5D45953FBCULL, 
            0x6A0C03DE393E12ABULL, 0xCD0DC4C0C56F57E7ULL, 0x8FF2524064C326E6ULL, 0xFCB44CBA29603669ULL, 
            0x91A496CC6D5BCAFCULL, 0xCCBAAE8436AC055FULL, 0xE3545599B014E3E7ULL, 0x6DCDDD1DF625E0E8ULL, 
            0xC950C9F59E701F69ULL, 0xBA8F047D519BE7D5ULL, 0xB8BE4E6526E87719ULL, 0xED38DDE83B288F82ULL, 
            0x534D9EBB1BF84EF9ULL, 0x314563549FE35C5DULL, 0x9C0B433FFF0ECD04ULL, 0x91D2398F0AEA084FULL
        },
        {
            0x440AE431AF53EE1FULL, 0xB7C86E6E9E351389ULL, 0x95DD7BE78692A8F3ULL, 0x312ED667726137C6ULL, 
            0x1BD9E3AB6248C004ULL, 0xB0B077AC6CB898CBULL, 0xE7CB893F43964563ULL, 0x5993F37ACDADC66AULL, 
            0x386FA8603ED544F8ULL, 0x74120DB8963D0190ULL, 0x98E7108DAEA107FBULL, 0xE21FD23C2A13FA1FULL, 
            0x6F5432C4F9FFE4D7ULL, 0x7E533EB4A93D2829ULL, 0xE03269A4262ECFDCULL, 0xD7EACB0746A6DE41ULL, 
            0xA8858AC01A03EB4BULL, 0x1D6F13D6B3816AE9ULL, 0x033C2B5DEC8C3CF0ULL, 0xB778D8083F9A76DFULL, 
            0xE2448BA80FAA5076ULL, 0x0BF6F7DDF008C5D5ULL, 0xF02F984FEEECE1BBULL, 0x28FF13B039F3AAB4ULL, 
            0x1A87EDFF649AE3D3ULL, 0xC164990BFC0DBF80ULL, 0xFEE920C3DF7C434BULL, 0xD428EC285134309EULL, 
            0xC9BE007CC1BF2B1EULL, 0x09EED39BE04D15ECULL, 0x56F375F4E4218018ULL, 0xAE4E5B54AF71FE6EULL
        },
        {
            0x4950A6EF727975B3ULL, 0x145FECCBE99B6F14ULL, 0x3F8617CEC69B8046ULL, 0xA143F8B4A1A249B8ULL, 
            0x026641832C3D59FAULL, 0x7E785E3D1AA7407BULL, 0x5314BE9F6B9E7014ULL, 0x4ED06B2E7FD30557ULL, 
            0x3357E59AFB53B39BULL, 0x4C53E14876D3593FULL, 0x66C8F1F7E4D28827ULL, 0x6BA09EC6A36FA6B3ULL, 
            0xE93C94A179A189E6ULL, 0x3783C4BCC4DAF880ULL, 0x1046C669B826EBC9ULL, 0x2135935AE9B3ABB3ULL, 
            0x84436B5FFFD11F2AULL, 0x642075D4F688634BULL, 0x6DEC29C655671908ULL, 0x623C99912A43840FULL, 
            0x5CF33A6563315244ULL, 0xC186F2037423D56CULL, 0x9E2A65EBFDF664A5ULL, 0xCB3F1714E1035DFBULL, 
            0x76E4E879275CFCDAULL, 0x81CA6D1AD103144DULL, 0x59ED0F975A49CCB6ULL, 0xA596B4E27C269412ULL, 
            0x3C59D8321AEC5FD4ULL, 0x2A3F2973C8EB4C5CULL, 0xCF29D376A1EE4B71ULL, 0xFA6E0EB924C2CD29ULL
        },
        {
            0xB6A7C32A667AFD9FULL, 0x54C9C69D52CFF923ULL, 0x567241C3701ABBFFULL, 0xA6B5C53145733A29ULL, 
            0x803B7076985264E6ULL, 0x4A31AF4F9E2BEDF9ULL, 0x824576DEB1939789ULL, 0x19A3E6C80C2285A6ULL, 
            0x436E81CB4EFE4903ULL, 0x6CF036FCE660FA39ULL, 0xBF01D2977ADBAF68ULL, 0x183A808960DC2E9EULL, 
            0x5E09D67DFAA84237ULL, 0x91C8CEF87C85F4D0ULL, 0xB15F84FECB25001AULL, 0xDCBD29D5ACF1EA38ULL, 
            0x22337E7777DC4DDEULL, 0xDADCCFDAEC8B42BCULL, 0xAAF5953E8C7A1836ULL, 0x06190367B2A6EE9CULL, 
            0xBE1723BD829A0AACULL, 0xACCE1E272C98D6B2ULL, 0xDE4859868AA43789ULL, 0x25FE836B28B29DEAULL, 
            0xDBF9807455215304ULL, 0xD31258CEC7626A5EULL, 0xB1A99B72899D0019ULL, 0x2BBB5D042AE3B2E9ULL, 
            0x3284FECC096702B9ULL, 0x5C7350F831D57133ULL, 0xB3B52F39CD216A5CULL, 0xE4F65475781AE860ULL
        }
    },
    {
        {
            0x609C1DEC3F57D320ULL, 0x13FEE8021829D9BBULL, 0x0129331E1A71A136ULL, 0x0E4904A885C5FB04ULL, 
            0x12C93C8454F86D29ULL, 0xC3D0B5B403E594B8ULL, 0x7AD772AAE4B67498ULL, 0xD028BB96494C2546ULL, 
            0x7B3E32718B5C10C3ULL, 0xFC38AD693C0C3A6FULL, 0x9335D8D4AEB2504DULL, 0x9E106470740D9585ULL, 
            0x8D91A4E3239EDE2DULL, 0xB3A7009E02EE5B33ULL, 0xD84B49EBEC1A68C7ULL, 0x5191231B89AD395EULL, 
            0x070B22D129BB2629ULL, 0x22CC258308E3CE3FULL, 0x8B31DFB985FB468DULL, 0xC1617C38B84BBF94ULL, 
            0xA01F7945AD6FF6DDULL, 0x7DF98FCE05B84F9EULL, 0xF6D2AF6A11AC56C2ULL, 0x114E9FDD58554D31ULL, 
            0xA75697A11FBA55B7ULL, 0x280E6E6CC7F5D53DULL, 0x68C07E4A87362F7FULL, 0xC7C597C51ECC4796ULL, 
            0xB412F0F29AF0D558ULL, 0xBB80CD81A53A4492ULL, 0xAFB0864829D0FB37ULL, 0x2AECD733663467D4ULL
        },
        {
            0x57AF8567BBA3AEBEULL, 0x1416289B1187F63AULL, 0x5F61BD4A8CB2D9F4ULL, 0x944C1B1C297004F6ULL, 
            0x37DD70CAB640FE62ULL, 0x0A5B060A43023070ULL, 0x60C019A340F414C0ULL, 0x3D3D8FD88A809072ULL, 
            0x64B2AC53C9D3615DULL, 0x99050ED6B2D6D34EULL, 0xD87A128052A4B1E5ULL, 0x0623A3E40E81010DULL, 
            0xADF103216765F2ADULL, 0xFD48B5E23B617148ULL, 0x06AF6A7D4556175AULL, 0xE73BFBC00062C651ULL, 
            0xCED8E7D6539583B5ULL, 0x2ED0A8CD6C834317ULL, 0xE9AC87D449C386B0ULL, 0xEA181FE550E00B33ULL, 
            0x2C8B5CAB0165642AULL, 0x2B40CB87781FFA66ULL, 0x9EF4C3B49CF778EAULL, 0xB6F016BB40B81F42ULL, 
            0xD12323631F197271ULL, 0xAF390DC1AEA8DC1BULL, 0xBD24E7E6C785065EULL, 0xD387B0C97B4A99DAULL, 
            0xF404CC98EFF937C2ULL, 0x769B3471C2245763ULL, 0x612F11D8AD64FABBULL, 0xC12324515F24C98AULL
        },
        {
            0xB3E2277AA94B2AC9ULL, 0x52057594FDD60CBFULL, 0xBEC8FA3D841FC749ULL, 0x94444E3B1BAFF250ULL, 
            0x67C27A7455FAE0AAULL, 0x21789BA262C50390ULL, 0x08EA3D1E008A037BULL, 0x6750BDE04DA0DEA7ULL, 
            0x5FC549157D776B63ULL, 0x1262E64C62B72EE1ULL, 0x527A6AC80EED6259ULL, 0x9209504C3EE7B717ULL, 
            0x7D3FD5413FCDFE47ULL, 0x082341CA10BA9B3FULL, 0x0D513CEFF0D9726BULL, 0xD26CF14EBC54D765ULL, 
            0x357CC1E69F2A01F9ULL, 0x44C95DFAB063DDDBULL, 0x24817DE75D9AADB1ULL, 0xD96BE09934AD8D20ULL, 
            0x9CADA6A203706B9DULL, 0x9AE16644C5087A0BULL, 0x49FA5895DE3C9657ULL, 0x9D69F815DB974359ULL, 
            0x1D140F49BDE7726CULL, 0x012C1A9FE5813082ULL, 0xDF5A29347DFCF372ULL, 0xEF5EFE20B5E567A9ULL, 
            0x1726102ECBC5CF9CULL, 0xABDBA27ED57E5000ULL, 0xAF7AF3E6CC578778ULL, 0x299B845ED12B3F5FULL
        },
        {
            0x36C9F6944BA1E3ADULL, 0x34F53EEDA6BE9E89ULL, 0x6F5CF0BB426DF1C5ULL, 0xAFDC8EA282655BDAULL, 
            0x75B637AA49D78EF7ULL, 0x9F8D7435D62FAB2BULL, 0x20664BFF0DBD83A1ULL, 0xA76DA20D9706385AULL, 
            0xB932788C9BD55ABAULL, 0x06A918A9EB934DFFULL, 0xC424E59B6CEABB7FULL, 0xDE6D56471EF669EEULL, 
            0x77E569C52306A174ULL, 0xC1B624472CE13314ULL, 0xD090E1A6E71BA62FULL, 0xB045399834559373ULL, 
            0xA05BBBB3E9332DA7ULL, 0x63FD9B9946B739A5ULL, 0x328BF5CE7EFADCDEULL, 0x8F1C8283756D2DC6ULL, 
            0xC0E8B5D1BD5582DBULL, 0xDEBF991BC9C7CE98ULL, 0x32FD39803A9F748EULL, 0x254DD3F49D29FD51ULL, 
            0x0A5004F7D9229CB8ULL, 0xA97E280BC8DBA1D3ULL, 0x2B4FE3187C4B53E4ULL, 0x8F5CBBD03D5ADC65ULL, 
            0x92F0745F3BD891ADULL, 0x91DE01EDA9FB0A1BULL, 0x8CDB2F1154FF2E10ULL, 0x5579F2A4BD1FBFC0ULL
        },
        {
            0xD6E1A507559CE017ULL, 0x3FF7C6F26FF4301CULL, 0x1CD49791632B233CULL, 0x3AEEE4A2B5280D53ULL, 
            0xF6C5A6EE84A5B928ULL, 0x2C0BB819A9D92D23ULL, 0xB715F29793A9D7B7ULL, 0x3F5AE73FB0F90B62ULL, 
            0x012A37BDFDCA424CULL, 0x7C69FD638742A167ULL, 0x72E9DC34C5090235ULL, 0x8FF92E7BE9A2050FULL, 
            0xAC0251F961EA333BULL, 0x4D9136DA68FAC22FULL, 0x57E3C3F75057CE8DULL, 0x8490E40ADF421B85ULL, 
            0xBA0D8A7445A03D35ULL, 0x43BA9A7B2650374EULL, 0x39D6690D63DA78E0ULL, 0xE88EDDC20A8BF838ULL, 
            0xE858F9BF40EC09BEULL, 0xBA08E86E47DA8418ULL, 0xE753F1E7C40313E9ULL, 0xC37F8056210C305DULL, 
            0x502B0C97094B9FF4ULL, 0xBBB57AF207316675ULL, 0xE20BA04D0CCD0766ULL, 0xFC50E6F760649837ULL, 
            0x78B212969BAA7FCFULL, 0x22A727FE94F2E889ULL, 0x954DE8CFA1B32628ULL, 0x9F9F16E5D216B187ULL
        },
        {
            0xEC3A1A19EDE12296ULL, 0x60D70506283E5577ULL, 0x507BF143A4DC250AULL, 0xB4A0E48AEB9D3E68ULL, 
            0x3B7B9D8D0C52F11DULL, 0x7B82DF6C17134855ULL, 0xEA3B076EAACD6CFAULL, 0xED920FDA5231FC92ULL, 
            0xB4AFFD4CCCADFC36ULL, 0xE271F59C93A46B5EULL, 0xD05ABF2F3411D69DULL, 0xF6F1B7CCEA02E40DULL, 
            0xE6BEB562147970B6ULL, 0x49A23BBDEF716443ULL, 0x1CAE7684209390A9ULL, 0xB816FB0813688478ULL, 
            0x0B2E2A2D1C711761ULL, 0x1EC2A45D6F498379ULL, 0x4A4CB89C5461D204ULL, 0xB7A979792EFA1ED8ULL, 
            0xB975FCE5C29B6E04ULL, 0x4934FAAB616978D6ULL, 0x4E0408C38FA0C660ULL, 0xA59545657B337326ULL, 
            0x828F78587874D5A1ULL, 0xD2491AE08D26A874ULL, 0x99D1C6994CF1BE60ULL, 0xB4EF794DBD28D946ULL, 
            0x27F38CFE4017E56DULL, 0x588ACD955EB32C8DULL, 0xD889B20885C38F93ULL, 0x92906CA2052FDE66ULL
        }
    },
    {
        {
            0xDD341505D3ED21AEULL, 0x4CD0A6D0CA9E289CULL, 0xC4C06D6417300710ULL, 0x0F67C8492C9E9AA9ULL, 
            0x72F29FA6AF29DF8EULL, 0x50D4D8676AA0E38BULL, 0x516C8CE5F545547CULL, 0x81FF46BB6466DC7EULL, 
            0xD75D729C5BD4861FULL, 0xFBB75EA26830B174ULL, 0x2C1558940CA50992ULL, 0xB218DAE70CE253E7ULL, 
            0xA924E0A60466954FULL, 0xB3D7423B18FC37E6ULL, 0x6A037E71B8CD52BAULL, 0x6B4155CBC27F617FULL, 
            0x42CF417B3DDDC302ULL, 0x39AC7F446559864CULL, 0x27053A80E89B1173ULL, 0xF66AF81A106FEFA0ULL, 
            0x5471B8D38D1BF085ULL, 0x5E788774F0A99F8DULL, 0x4154C837D39A2E95ULL, 0xF58BAC3727383CDCULL, 
            0x885AF4528DBFB0EEULL, 0x4CF467A0A9A94985ULL, 0xB04C7809A8438F16ULL, 0xE3889630FEA12915ULL, 
            0xC7CA68C5488C972BULL, 0x54548520CE9827A3ULL, 0x91D34A259D0F60A8ULL, 0x234DEA983C4B1B4CULL
        },
        {
            0x7CC816F715B195D4ULL, 0x56D679688EF3082EULL, 0x817743355D20DAF0ULL, 0x32F13ECA86E14513ULL, 
            0x0B9D419E46745953ULL, 0x5F4D64D6BD8CE34FULL, 0x2A2C358FCA3E8545ULL, 0x93559F761A8CCBC4ULL, 
            0x44DECE0DAEC533A0ULL, 0xB04C359C9145B6FFULL, 0x18CCF3635CDB5F66ULL, 0x33116BC98418748BULL, 
            0xBBAED7765E9B52C3ULL, 0x9465187654B2CA4CULL, 0xB0B0AEFB2EB9589DULL, 0x275EA99777532992ULL, 
            0xEF688004293DAEDFULL, 0x814F978A998885ECULL, 0x41027C16C0C91BFEULL, 0xE119310219CBCCF1ULL, 
            0x221CFA5B53962A86ULL, 0xBC7847983FBB0C9AULL, 0x4CC272FA967C62AEULL, 0x277ABC705FCB96A7ULL, 
            0xD952D77FD81346A5ULL, 0x8361830B592392D2ULL, 0x4D655DBB22BF7E02ULL, 0xBA4D14AB71C7FE4DULL, 
            0xFE572F20EDE5BC9DULL, 0xBB666B37821FC2DDULL, 0xFF9263F30D4F47F5ULL, 0x21D10BA8B5588148ULL
        },
        {
            0x1C52DE63CD4607CEULL, 0x0DA4987AB0F22E62ULL, 0x002B615AA8703AE1ULL, 0x58BDE499CEC41A1EULL, 
            0x199CF28BB7C7739AULL, 0x75DD4EB4A006EDB8ULL, 0xA4901D5CFB2CE1D0ULL, 0xE5C3C52FAB527C79ULL, 
            0x944FD2A4211C3623ULL, 0x9513AD11D477470EULL, 0x7A3EB7A74095C9C3ULL, 0x620C7137DEBE47BFULL, 
            0x2BBBBF83B60B46A5ULL, 0x6DE7C3521606741EULL, 0x5DC7F8C1B3135D79ULL, 0x8BC1E35D8F76E87FULL, 
            0x65D3AB78E106A850ULL, 0x0E739178BAB6A9EAULL, 0xB1FB385FA0A3CF9FULL, 0x1C2FA286CCCF47A1ULL, 
            0xB52C4E281A952D22ULL, 0x3ED7B052ACA9581EULL, 0x0105487A60DECA10ULL, 0x9DBEFBB4014EFA91ULL, 
            0x57E569A194948F37ULL, 0xC278C5C3E27F0565ULL, 0xF29568737E56062DULL, 0x47FE880F2CD60060ULL, 
            0x510F078B9570030CULL, 0x6AAB83B4F938FB37ULL, 0xCF134D9B9C714005ULL, 0xDDE492A51F753676ULL
        },
        {
            0x312DC1A7644D8FFBULL, 0xD0AF72E61528162FULL, 0x53EAF8EB8E9A3E59ULL, 0x9C316CD75431FC77ULL, 
            0x6232644C448A9F40ULL, 0x0763B5224470CB8CULL, 0x0063418597CB8314ULL, 0x44DE7E765CB3D895ULL, 
            0x3B1E2FB28B81C111ULL, 0x6A32C20C77692C0DULL, 0xBDA338FF93E57A9CULL, 0x40333E7C1621CE01ULL, 
            0xE70D69D621FBF226ULL, 0x20D6FFD30F0A3295ULL, 0x5AE09FB969AEA410ULL, 0x4489A877628B5B26ULL, 
            0x3113340AF29F678BULL, 0x83EB41A297F46B14ULL, 0x7AD3115452591871ULL, 0xB7B0469FEC8C21BCULL, 
            0x5F54B3800E8B18ADULL, 0xEBF1266FDB1DC620ULL, 0x6F0F0E8C893F6CEFULL, 0xF3A6DB831719BED5ULL, 
            0x0C74C4982BE126EFULL, 0x7BBF1FBB4EAE9D9AULL, 0xDBA450C6BA9C8832ULL, 0x5DB3E0F4080FF758ULL, 
            0xB9495A840780548EULL, 0xD5C55F0DD4C17D62ULL, 0x24F6FBE7087F89A0ULL, 0x512A032EB679A4C7ULL
        },
        {
            0x973DABB17D49FD7BULL, 0x17B3BCA1A21FA3B2ULL, 0x6A538EF42CADFEEFULL, 0x602D12DFC739FC0EULL, 
            0xAE00157F76AB8DF9ULL, 0x2823F4C66ABDC716ULL, 0x49A2C05ED981C126ULL, 0x5858BE1229A53D21ULL, 
            0x163089B462B06231ULL, 0x447EAAFA5C58F464ULL, 0x71429857C8DE9D72ULL, 0xE858FF25CE4578A2ULL, 
            0xF553FDE0141F7349ULL, 0x80B80DC93D10C028ULL, 0xFF9EB325355357F4ULL, 0xF4E898F3E405CCCFULL, 
            0x6274EF5B6760C0DCULL, 0x7DB55EA8F1675498ULL, 0x488A6E4B17EB73A3ULL, 0x7E9CE715A5EC2CE8ULL, 
            0x96A9CB8C139DE4C1ULL, 0x3D028211499EA8F8ULL, 0x628558AF14E65D9BULL, 0x30D2C55FF87BEFF6ULL, 
            0x875647CC4E50F728ULL, 0x785BFDCCFA1E749CULL, 0x84806F3B61F7A231ULL, 0xE44B489CBACAC465ULL, 
            0xCF679F8088349B6FULL, 0xD03E37B7E2A62098ULL, 0x1DE3CFDB15809F8DULL, 0xAFABDCF50C17FF76ULL
        },
        {
            0x9FAB8E3A5E34ADCEULL, 0x365867CAE8B81FA3ULL, 0xE46BFB79F62CED96ULL, 0x732240541CE9AF1EULL, 
            0x9D624B1243F674C0ULL, 0x94DA8D1EABDE861FULL, 0x91CB5B0BBAE7134EULL, 0x7F4745CDEB245D38ULL, 
            0xECF6806B200D1643ULL, 0x03ED693AFD868339ULL, 0x9AE3B4148B4E534AULL, 0xF99EBC94BBBD0509ULL, 
            0xCA66DCC889D25B38ULL, 0x60A45D4719B975AAULL, 0x0FA07053DDDD466AULL, 0xE96F22B082B412E5ULL, 
            0x1BD500644E6A1634ULL, 0x13ACF785D0A45A58ULL, 0xAA851E2FD4FCDDFBULL, 0x8FE538E711A6D09EULL, 
            0x3C2CB84563994071ULL, 0x26BB4EBE06773E4BULL, 0x9FD4732380795820ULL, 0x82019D5F443075AAULL, 
            0xFE10FD337E950046ULL, 0x01528D5510B8F84DULL, 0x1CC2DD3BB0B2FC04ULL, 0xDB1D5FD1C9D068DAULL, 
            0x9BAC4D34A9B185A4ULL, 0x2ABB51C56BDC7336ULL, 0x9518CA86E92CD1C7ULL, 0x0FAB100AA95D07BAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseFConstants = {
    0x1E706D463813F7B3ULL,
    0x40BFE9D6977D2E69ULL,
    0x74562E776DF44A73ULL,
    0x1E706D463813F7B3ULL,
    0x40BFE9D6977D2E69ULL,
    0x74562E776DF44A73ULL,
    0x1C1622BB1D93CD37ULL,
    0xA74C95D61ADB803BULL,
    0x43,
    0x95,
    0x3E,
    0xCF,
    0x39,
    0x1F,
    0x24,
    0xE3
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseGSalts = {
    {
        {
            0xB67EECABB5214C47ULL, 0xC066A4B4B0F20EA0ULL, 0xA77F254937EF341FULL, 0x4407F78FECD887E9ULL, 
            0x18A0A176CE6C4609ULL, 0xC9D970E65F4E7BB9ULL, 0x3BCF0FC77AB06673ULL, 0xE5C8DF28A11D9B9FULL, 
            0xAC3B503FD2AD7025ULL, 0xFEFF5959A5600891ULL, 0x1D04809190512C72ULL, 0x045B0E275FAFDB4DULL, 
            0x1FE29C4EDE89F433ULL, 0xE8733996F236D5C3ULL, 0x5C0DC07A631D4FBFULL, 0x321A118E40DC1E68ULL, 
            0xC16E075E1516996AULL, 0x4FA716FC6C14DAD8ULL, 0x8039B8944C3C8FA3ULL, 0x4A20A4C51C9340A2ULL, 
            0x60F2FCEF8198084CULL, 0xB31D842F4E16FBBDULL, 0x9610CE041459A444ULL, 0xEC035A0B6B753265ULL, 
            0xF355F6CEFE3F375EULL, 0xC584BD6D19CF2E6DULL, 0x96A6BBC385DA0C48ULL, 0x926D93C7AB759E16ULL, 
            0x11B0A4CEB2B8F181ULL, 0xAC33CE5AF693164AULL, 0xBDA1DE9189282779ULL, 0x1CCF53BFC7103C4BULL
        },
        {
            0xFCEE5CDE5D5A0E10ULL, 0x04F1CB886C7C8A42ULL, 0xFE1F5A39196D91AFULL, 0xD45600982CB84631ULL, 
            0xDE34BCF9A68E9C75ULL, 0x879D852AF0FA7FCAULL, 0x0405193D7DE91F95ULL, 0x5B40784CFC800547ULL, 
            0x73C0EBF7125CE2EAULL, 0x0CD8F6BA01FD4C25ULL, 0x142D8BF9F9AE8460ULL, 0x87D53821FA28932BULL, 
            0xAB53999A7346BBF5ULL, 0xE57AABF2875BEE46ULL, 0xC8AA7006A00C51D4ULL, 0x1F39454B9194522DULL, 
            0x62601CEE3CFF146CULL, 0x7A552FCDF3288D4FULL, 0xFB40063EC5F9B1AAULL, 0x18179080A22A0ADFULL, 
            0x547C988E351263F7ULL, 0xEC24C2EBC584A481ULL, 0xC5477D4A145E0712ULL, 0xE56BC37477621022ULL, 
            0xB9EC9CFEF1D9BB24ULL, 0x84AA0AB0E67599F7ULL, 0xFEE0FD3E7A8D74F2ULL, 0xB7BC26312E06C8C1ULL, 
            0x9DB36E234ACEDDB6ULL, 0x9E2560C94F887F41ULL, 0x60A3461156AE67B1ULL, 0xBE7F46D018422B63ULL
        },
        {
            0x0175C90BAF97BFA8ULL, 0xDAC74D68AA53EE16ULL, 0x4D72ABF3929C54D6ULL, 0xE6D02B5E49E59F6BULL, 
            0x316C5ABD91309CB5ULL, 0x4C68CE01A3055E65ULL, 0x09D8E507BC31E990ULL, 0xB779DD5A8CCD520AULL, 
            0x9A331D6ABFCFEB1AULL, 0x3B27A17436F7EC39ULL, 0xB295093480F22284ULL, 0xC777F6630B04E664ULL, 
            0x47C76F4F424AAB26ULL, 0x39652C580B779549ULL, 0x7FB69C3C6AB9CAB1ULL, 0x25C6AF48868A9F76ULL, 
            0xE93C183AAC354FA0ULL, 0x7BF009889257CD30ULL, 0x634FA4C320E55FCCULL, 0x0B38B92D1D477E4BULL, 
            0x2E6B8D931524828BULL, 0xA86D98687591B0B3ULL, 0x1F334D16C07EFFADULL, 0xF6F7D3B774F8CC87ULL, 
            0x45578D2E1FF971EEULL, 0x97BE887128A5F9FAULL, 0xA77F66F847CAE338ULL, 0x570A9EA77305CEA2ULL, 
            0xEC65DA4734D89405ULL, 0x0FB9829E8CF8DE05ULL, 0xB0666814B3EA2CE1ULL, 0x3AD6AD99B120B135ULL
        },
        {
            0x841E11AF66A08A45ULL, 0xB9F4A163F29392E4ULL, 0xDC43B20E5AAB9E54ULL, 0xDD44A811E2C3BF6FULL, 
            0x61BE1E5B6D6E0802ULL, 0x411DF80C1B2209DBULL, 0x4964E72E0BD8C5B8ULL, 0x287868642ED9C27BULL, 
            0x6F40EED4124F2CF7ULL, 0x5EDA309C788454DDULL, 0xA5D10473B2984ADDULL, 0x3063EB278D05B6ABULL, 
            0x0C352A3855D06688ULL, 0x708DB2942E74CD39ULL, 0x10B1FCF004A20A60ULL, 0x528D5ED7CE4B80B1ULL, 
            0xF4B87230A88D0565ULL, 0x56C5F7CF63104D83ULL, 0x2D05537F6509B0BEULL, 0x1DDF1434639A9528ULL, 
            0x02BF609A2F0F599EULL, 0x031311F167AA26F3ULL, 0xF7C23CEE50735649ULL, 0x252F978D32F0AF23ULL, 
            0xEB96C04A551F1B1CULL, 0xB235E3AF2FDCCECEULL, 0x052D53036AF61722ULL, 0x12AA8D442210826DULL, 
            0xD19D5EC51BA13CC2ULL, 0x7C3E9A47515558C0ULL, 0x9C16DAB0C6671810ULL, 0x1DBF092C728BD7E3ULL
        },
        {
            0xA797F432B2022C74ULL, 0x08C67D5EC99A7DE0ULL, 0x04251ECA8FF75C4AULL, 0xB9DD12AC8C2900CDULL, 
            0xF09C38EBD305A5FDULL, 0x47060B9B98D248F6ULL, 0xF180FB66AA8AC93CULL, 0x08C31B560B3F08FAULL, 
            0xABC316D1D5BB785AULL, 0x52670C4C332EB589ULL, 0x4B94719CD6CD6EC3ULL, 0xA7D20741F0DD7248ULL, 
            0x2A572B1D02516835ULL, 0x24C72C154BB6938CULL, 0x54AEC4A2BF618EBDULL, 0x76128B5270D30B91ULL, 
            0xC9A76CF9E1572BBFULL, 0x285BFA86252A07DAULL, 0xF64C0198074E4D4FULL, 0x5039BA3835789D91ULL, 
            0x41CC902B46D2AA30ULL, 0xC22B9A6F359ED13EULL, 0x28FEC70976B4C638ULL, 0x889BEB30CA26A285ULL, 
            0x50795479F4BF9833ULL, 0x9D2C7CE9068224BEULL, 0xF56B8245D1F545DAULL, 0x8524A146D485CECFULL, 
            0x0767C65B995D9215ULL, 0x4352D654EA4F3B99ULL, 0x9C3A9C4FCDF75F3CULL, 0x1C6FBFE980D39367ULL
        },
        {
            0x839F01FD2280E22DULL, 0x69B0906178123F73ULL, 0x8AE244431D76E4C6ULL, 0x83204D8B9D8C76DFULL, 
            0x39A394C1B3B24794ULL, 0xE857A7484FC3006CULL, 0xCAD7049D9271FCE3ULL, 0x4ABA1C4E4B61A191ULL, 
            0x3C863D4C3308EE6DULL, 0xD4B09A9B30C40BAFULL, 0x98530D8B45F768D7ULL, 0xBA6D03FE67F3868EULL, 
            0xF1D868206FDA2BC1ULL, 0x70841A795306C2A2ULL, 0xFD2C3412A5805BF7ULL, 0x3728A1CCBF78E9B5ULL, 
            0xB217FE0087A2785BULL, 0x5E81CEBAA76215E4ULL, 0xED941009FB7BC733ULL, 0x3226030C97312351ULL, 
            0x51B13D97EB101467ULL, 0x5431ACB5066985F6ULL, 0xFF18D164478087FAULL, 0x1DDABF39F0762E41ULL, 
            0xBE42579F576C9AFEULL, 0x547369A5C0E4DB99ULL, 0x308ADC5969B42D82ULL, 0xB94BF1A7147C7828ULL, 
            0xF3ADD4998605C983ULL, 0xE056CDFAF95D9B1AULL, 0x44D204A8B4EADA24ULL, 0x1BBB9C47F1E696BFULL
        }
    },
    {
        {
            0x1DC25A1C19B190D6ULL, 0x1E13E62F238916CDULL, 0x2E640AF693C185BCULL, 0x063CF9C97C3060DAULL, 
            0x253BFD8CFF5F8F22ULL, 0xE789AB85BCD4724DULL, 0x81450E69D48542CEULL, 0xF19A7FB3C54BF613ULL, 
            0xF19122005FBBDDE9ULL, 0x703C6C7E78674060ULL, 0x3C340B9E8C37F83DULL, 0x22CBBE2D2A56E72BULL, 
            0xD6B9CCFE810801EAULL, 0x6BEDEE1574277862ULL, 0xCA4BDDB188346ECFULL, 0x9F1C4DEA43D4786CULL, 
            0x8BB4EE8A048FCE10ULL, 0xA6CAF1BA8A697225ULL, 0x29860D879DF02736ULL, 0xEF2636A47EF194E2ULL, 
            0xC2965F3D11CF7135ULL, 0xAA66920D31686B31ULL, 0xA464B69298AC5D1BULL, 0x807A0ABAC6F648F3ULL, 
            0x623C2D446FBE7DF0ULL, 0xB4AD6341A02CBD4BULL, 0x51AD025938FFE016ULL, 0x06FB68B7E4A01A7CULL, 
            0x0F0E9BB0454852A5ULL, 0xA2B5B86B05589ABCULL, 0xEB893B27EA81A17BULL, 0x22A5778872E9618CULL
        },
        {
            0xE5B4C6FFB5E2C6ECULL, 0xF42E13510007DEADULL, 0x12CE937625A6728BULL, 0x2BA2179015410E14ULL, 
            0x4A4C32B2716AE858ULL, 0x211DC0C7CD633380ULL, 0x3715122C3E49901CULL, 0x0BE3CE3CEF5947D8ULL, 
            0x14A46DD503A7FFF2ULL, 0x2ACC32ED1A54F389ULL, 0x38BAB9BC7F43E766ULL, 0x0E0C59080363B414ULL, 
            0x861D7180875F2C1DULL, 0xD4E9B08DF426EFECULL, 0x04C4386263EF9631ULL, 0x047ED856412EC1E3ULL, 
            0xFCEEC2EAFDC5439CULL, 0xAC8FEDC992BAA14BULL, 0xDEDABF0D10A3A2AEULL, 0x80F8689AB6A88CB5ULL, 
            0x6D2B7D99F3146265ULL, 0x45C1482971DE5D5FULL, 0x9AEFB14876B17843ULL, 0x03911DA5F770728CULL, 
            0x5C7EBACD3AAEE445ULL, 0xB4CAC6CB5F55ED2EULL, 0xC3C5ECA94AC0E227ULL, 0x5CACCD47A01F1F59ULL, 
            0xC879542FF87FA1BBULL, 0xF91E3BC8488C9898ULL, 0x9BE6F842EB22DF4EULL, 0x9B74452794A3579FULL
        },
        {
            0xCB3C9F0B5608509DULL, 0x9607DF05BC174FF2ULL, 0xA2DB33C0BABCC86BULL, 0xFEA0C234E939C767ULL, 
            0xD65F21D0B2E5AB72ULL, 0x346B89B1894A9079ULL, 0x0D3248C1FDB95701ULL, 0x46CD70D81D21D77DULL, 
            0xF79DB0DB2A31B95AULL, 0x275017DEC4150BCFULL, 0x47DCAA5566388023ULL, 0xD0A4D5D5AACD7A95ULL, 
            0xAC5AB8C29D6F3B62ULL, 0xAD864E24637DDF91ULL, 0x1C78488A0B400002ULL, 0x43120C9424617BD2ULL, 
            0x5C0AAE242347452CULL, 0xCC1AF3D38C213858ULL, 0xCC77C54AC3163F77ULL, 0xF64131E683542350ULL, 
            0x661E1F3E37BF1958ULL, 0xB6DC32D338C0084AULL, 0xFDE7AF3CA4D80F2BULL, 0xC6CA0BB84ECBFEA0ULL, 
            0x6B861A0C80A9A81EULL, 0xA5DDEA32EF182867ULL, 0x592F95F2793D5B63ULL, 0xB7E4A03CC8D847B6ULL, 
            0xC9D8049FDC6B83F3ULL, 0x89003C5A87E6C106ULL, 0x2FD1A807A6C6A3D4ULL, 0x6EE9A7A57600DBAAULL
        },
        {
            0xD83B51C294FD1CA3ULL, 0x2AFB93E63BDCE339ULL, 0x747BDE738CEF2BE4ULL, 0xE07C80157CF66751ULL, 
            0x287D1EE9CD81F1ABULL, 0x5A51A384D310DE5EULL, 0x740576E3AAE702B7ULL, 0x31DCD0074E5BF461ULL, 
            0xDE588426433A31F4ULL, 0xCA75FAD45AD465B7ULL, 0x5675011B42872452ULL, 0x2129DBB1B2E93090ULL, 
            0x1417A184ECE61C33ULL, 0x4F6C03A5E403DA6BULL, 0x3416B665FC20BCA0ULL, 0x74A1E4B6FDAD154FULL, 
            0xA908D75A25EA663FULL, 0x1904655EBE0FAB15ULL, 0xCB6E211B752E2AB5ULL, 0x50C3AD8A95C80DFDULL, 
            0x0846DEF7C42FCCECULL, 0xA0A810555F7D00B7ULL, 0x154FDDA884EBF3FEULL, 0x22C1EEA6D7B3E5B1ULL, 
            0xCFA51DC9E95D1B4CULL, 0x41DE23F8BF2DBF5BULL, 0x65474B3BCEA6E1C9ULL, 0x792229651B157476ULL, 
            0x4F8AA0120ABEB86AULL, 0x7D3102FF2C22448EULL, 0x2AD27F528BD53936ULL, 0x6628A072AC4A428BULL
        },
        {
            0x2557412DBAF2F182ULL, 0xCAA14F483ECC9E9CULL, 0x54DE7A707CCD131DULL, 0x484D652C55CED644ULL, 
            0xD335E7BFD38E2EB6ULL, 0xA9FC9CBDCE43B94CULL, 0xE0F5697204C2D1B7ULL, 0x4C7E1DB733F7EFAEULL, 
            0x1A35AF4C75BC38C1ULL, 0xEB4F8A13EF6E1419ULL, 0xCBC8F5D531705D84ULL, 0x4AE2E6DC015A8C01ULL, 
            0xD84D11A929492708ULL, 0x40DAFCD350E6A9A6ULL, 0x09B0A5C49B0367CEULL, 0x9FDD9E2661780FADULL, 
            0xB9BF11821845F2EDULL, 0x7880BF04AC574746ULL, 0x8079F510496A1AB2ULL, 0x8287E487943BD246ULL, 
            0x4FFC9755219D8F6AULL, 0xE0FACD312D58A1C5ULL, 0x4C0882DE6FD75DD8ULL, 0x70427E83BCD82725ULL, 
            0x2838F05C10F2A614ULL, 0x0D7683926E726855ULL, 0x95F03CAB63497E5BULL, 0x4ABE0C6B720E10F1ULL, 
            0xEED52ABA00EB7B1AULL, 0x84D394B55F4C0AB9ULL, 0xDCD64ACA2AC24CEDULL, 0x2E288D017B725444ULL
        },
        {
            0xD25B38784572F8B3ULL, 0xEA952180B17D44A9ULL, 0xFB99653934693BEDULL, 0xB28DFE90BDC69823ULL, 
            0xC1179C49CAAA847EULL, 0x994C4A6CBFB24A8AULL, 0xA23E7FFF1AFD8531ULL, 0xD864D061A458AF15ULL, 
            0x53A1BB8762E23C32ULL, 0x8553CCD6AAE40B30ULL, 0xB13152DEEDEBD2EFULL, 0xE924F0F2DF9BC4C2ULL, 
            0x0FD58669A2ECA889ULL, 0x2B9A02D493024873ULL, 0x6A61A0C11828DD7FULL, 0xC6E7E73178469091ULL, 
            0x009FD4FEEDB469DFULL, 0xAEDB768AC26966FEULL, 0xD036F8952BECCB79ULL, 0x303477B21CB3B028ULL, 
            0xB367880E7D6D9BA0ULL, 0x24AE3CABD877BD40ULL, 0x296106E8323E0D17ULL, 0x935846C3F07214EBULL, 
            0x5968026F41900C2BULL, 0xD348BE16F73E3EFDULL, 0x79C95CE6CD370AE3ULL, 0xF9BE0940F8DB91C6ULL, 
            0x90847360C170D928ULL, 0x43168E4A32446015ULL, 0x47DAC8159FC5A8D6ULL, 0xF044C5BCFB2B1419ULL
        }
    },
    {
        {
            0xE017F865D952C932ULL, 0xC663D18EDA7DA577ULL, 0xA901437B434107C5ULL, 0xE44C9F678159CB4CULL, 
            0x9A477A5619881608ULL, 0xDE3B80F3B0F99710ULL, 0x88D26DC6E0A29EBAULL, 0x465D61308852FF52ULL, 
            0x6DC2BC42370738F4ULL, 0xDA199260FBC10D02ULL, 0x95774B0A12F2249FULL, 0xD525A6EDA0E53D6DULL, 
            0x054A78EA3B346807ULL, 0xBFAED0E3E50FEFD9ULL, 0x51885C47A84D2D4AULL, 0x6A0EE265B9F68473ULL, 
            0x83A3303906C9794EULL, 0xBC2FBC1CE532FFE7ULL, 0xDFB8F094DFAD1200ULL, 0x8C7546E134F1075BULL, 
            0xB4881E2CFBDF4C85ULL, 0xD4543D545E4CFC3BULL, 0x2794916F41F78D83ULL, 0x2459A1A9825B9E65ULL, 
            0xB8A04CA1EFF5963FULL, 0x94A633D828B412EDULL, 0xA3509521AF55A79BULL, 0x4AC9651E45C8C538ULL, 
            0xD98741FB71D278AEULL, 0x3AB90470EB487029ULL, 0x05D4E34859E499C3ULL, 0x1D6118A817BA9B8EULL
        },
        {
            0x34E9003A3D90C9A2ULL, 0x7512BA09D3CB6C53ULL, 0x1A312A02514B132AULL, 0xC26492FA63C0C782ULL, 
            0x905F5DD607BC4D6DULL, 0x742A227BA4BE142BULL, 0xC1DB5C74E564AE73ULL, 0x8846FC946263CF1FULL, 
            0x37416B4B204D7A94ULL, 0xBB7E157BAEC7F77DULL, 0xEAD29792AE477332ULL, 0xB8D93ACB5D175F8DULL, 
            0x8A271442C54AB11FULL, 0x26CB645181F27B55ULL, 0xFBFEC06B73B683E2ULL, 0x05856F7E52191947ULL, 
            0x713B7886D82811AEULL, 0xCC55A7CAB5011689ULL, 0x9A25906605816988ULL, 0xB4FB05AFBA5AD21DULL, 
            0x7AB6E98EAE0C1A3FULL, 0xC1A4BAC875B3DFF3ULL, 0x0FD03FF091DB1D9BULL, 0xD710635ACE127A66ULL, 
            0x6DC5FC084A3FF19AULL, 0x7409BC605FA65344ULL, 0xF0EBE2CFBB13C07BULL, 0xEC9EB7AEEF846DE2ULL, 
            0xEC5499FB9915789FULL, 0x9B8859144678A952ULL, 0x18F4AC4AC8962CADULL, 0xFEFD5633397ABD9EULL
        },
        {
            0x481CA720BC3E1B1EULL, 0xD91CCB18C7D6775DULL, 0x2F6BFE6850BE3158ULL, 0xF22C375487AF3097ULL, 
            0xA4FA7E005A97349CULL, 0x6B5C1CDFD8818779ULL, 0x4FFEE9602911D56AULL, 0x766B1B1E278A48CFULL, 
            0xE8DF28BB29C87CA9ULL, 0xD0AC78B662921C5DULL, 0xBC3910B86B49DB7EULL, 0xCD681A435368344FULL, 
            0xCA62FCBFD1FB0B7CULL, 0xDEEF91616E35B0DDULL, 0x07122F31CB4A9EEFULL, 0x4E0CF30CE608249FULL, 
            0x93DB8B6908CC1343ULL, 0x3511E8B08D608164ULL, 0x1385C2031686F416ULL, 0xBB5F7A3A2FF3B264ULL, 
            0x111AB2615138AA6AULL, 0x9316AC723947A679ULL, 0x48DA7E1F2B6D35E0ULL, 0x995BA78D14AD01D8ULL, 
            0x078A13F798474FBDULL, 0x5FAB0F75D4724C14ULL, 0x085D4F303D2C8D9DULL, 0x23855A14AF26AD98ULL, 
            0x20DC9138FA641248ULL, 0x852220BA039177B5ULL, 0xFAD1586516EFFBA3ULL, 0x79F1B61CF2474536ULL
        },
        {
            0xA1F9ADE439FC2DDDULL, 0x130C87B92B384E8BULL, 0x7D3D4FF1BE121FF4ULL, 0x3224DB8626CA0CD3ULL, 
            0x9E1D976BBEF3AA0EULL, 0x2B0001ADC1007B15ULL, 0xDCB71AB631A01B15ULL, 0x1AAD224D4BDAF87CULL, 
            0xAEFEA7EA405E8E12ULL, 0xB8EF7FF61E7DFD6FULL, 0xCA8793476FC021E8ULL, 0x3C2DDED514C2F2E1ULL, 
            0x7D89BB119A50BE31ULL, 0x067B19C4A801F16AULL, 0xEB82DFADA0E5484BULL, 0x179A7FA70BE53910ULL, 
            0x3CB9EA463BB11647ULL, 0xF97ACB028675D0D9ULL, 0xE7DBCBDCB3451CF8ULL, 0x9BF484F74FBFB03BULL, 
            0x14F02BC77FC25FACULL, 0x3FD893DDEE140D83ULL, 0x38916428F0A910D5ULL, 0x8ABE8528C575A1D5ULL, 
            0x1115DDCBA0E9D374ULL, 0xBB2070FBC37246BCULL, 0xFD4CE1BB306641B0ULL, 0x4CB4AAD714F90AB7ULL, 
            0x514983D02135D972ULL, 0x4E9EA1D666D69E5BULL, 0x41C24A0C24E9C535ULL, 0x2E81D828CA87D739ULL
        },
        {
            0x3FFF8B8DD0EF5FDAULL, 0x83E8043599C47520ULL, 0x121C4334791A528EULL, 0x32B4E91B72155407ULL, 
            0x4DB0F81707DFB793ULL, 0x7EFB2658BB4C046CULL, 0x29A615CD70BCE1ABULL, 0xE0D185016E52064EULL, 
            0x1E0BCF3ECBF48BF2ULL, 0x47F8E8A31814EE84ULL, 0xF43A24704AA673D3ULL, 0x664E0CBDBFFF11E9ULL, 
            0x26BE2CA2C430FF8DULL, 0xC9C117BB8DF1637BULL, 0x812984E313F77755ULL, 0x4E958656BC6D778CULL, 
            0x349C3C1013D7523BULL, 0xE5BFE6131D1C7F9DULL, 0xC782C9C7B5B9935DULL, 0xA8C4A0AD2B44AFA9ULL, 
            0xA5696FC91A75D6C9ULL, 0xE2D62BD2A6BF3738ULL, 0x23C318D3CE675AB7ULL, 0x7985CADCAD0A64F3ULL, 
            0x06087B65180DE298ULL, 0x6A7C27E1DB208CCEULL, 0x9283A9738698DE8AULL, 0x5D251D33EDD35386ULL, 
            0x85B9FF9D66BB98D9ULL, 0x9702FFC475F867EBULL, 0x6FD3C1C80C0DD4FBULL, 0xF1E4A02866099333ULL
        },
        {
            0x3478B561AA680C3EULL, 0x7CE99F355FAB40BBULL, 0x95ABBCF28E47EE54ULL, 0x15785E751BDE6B18ULL, 
            0xB633A0ADDC581539ULL, 0x248B6763ECCFCA8BULL, 0x80E57A30D7395222ULL, 0x88114A3F7D5E5DD1ULL, 
            0x643E8E21C0AFE005ULL, 0xCA6EA17D6E0EAC0EULL, 0xF0EB35BB04792349ULL, 0xF02219BD48EA532CULL, 
            0x6F6D0198C7801FFAULL, 0x05D8EAAB572C6EFCULL, 0x982404C6C8F2034CULL, 0x8303ADA9EECC6791ULL, 
            0xFA0417BDE6A18685ULL, 0x79906F7E724A6428ULL, 0xF9BEF66507DFB379ULL, 0x18D0E17E74F415DDULL, 
            0x29A2A51C91134C4AULL, 0x824D892611031058ULL, 0xBDB2181A42697EECULL, 0xABD859081E9B5DCFULL, 
            0x12ECE6C2D4DB4B88ULL, 0x8E9DF632FC751FB6ULL, 0x7FA13D3C0A7DEB98ULL, 0xB1F6C55EF80217A3ULL, 
            0x06619BA1110CD86CULL, 0x2C9E0F94B0D775D8ULL, 0xCB46BA111312C973ULL, 0x5CB39C7AFF0266B2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseGConstants = {
    0x840B50C308ACFE8BULL,
    0x1DF09F7DBAAA9A84ULL,
    0x2607BF233164FE0AULL,
    0x840B50C308ACFE8BULL,
    0x1DF09F7DBAAA9A84ULL,
    0x2607BF233164FE0AULL,
    0x497C684E2EF2C3D4ULL,
    0x9C910CE251A4CB3EULL,
    0x63,
    0xC9,
    0xC0,
    0x13,
    0x45,
    0x4C,
    0x67,
    0x85
};

const TwistDomainSaltSet TwistExpander_Fencing::kPhaseHSalts = {
    {
        {
            0x798F44AC4046232FULL, 0x1FC48C4D318342B3ULL, 0xE1531CABD44D9269ULL, 0x38BDE77A77B596F3ULL, 
            0x4A1F7FD329B6862BULL, 0x4F04385D17B43178ULL, 0x29F9E30960580425ULL, 0x5CD591BA66B04D36ULL, 
            0xC94915E030CD69CBULL, 0x4645B0B88D7DE080ULL, 0xF38C41B448900505ULL, 0xE130A4EE7AECE5D5ULL, 
            0xE3F84A981D4B5F99ULL, 0x59CD83D3DC77B34EULL, 0x2B4188004D557742ULL, 0xDC44637592CBB9CDULL, 
            0xBCA230F66793F560ULL, 0x521F418C78123544ULL, 0x6F594069BAD84CF5ULL, 0x657AF4162C747FD1ULL, 
            0x76B61A3C899AEBACULL, 0x5DCF6676B62A2789ULL, 0x4367597A4B7672DDULL, 0x258759E8D026AD73ULL, 
            0x14A7B0101441DAE3ULL, 0x2B90084AA4251BA8ULL, 0x00D978236FC88129ULL, 0x5F673919B8A17C0EULL, 
            0x8C6C76B0BB68062EULL, 0x781ABE2198202A3EULL, 0x21E558195D41A00FULL, 0x20CCFACAE1C2D744ULL
        },
        {
            0x134EED773AA10FF2ULL, 0x4A09557E38185FB1ULL, 0x9C990ECA79427C37ULL, 0x8C9E1DC3D3501A10ULL, 
            0x77F06DDFDE359D82ULL, 0xCAC25F9E05DE2D58ULL, 0x7A555812744E084AULL, 0x782707EEE3617073ULL, 
            0xD7FE03101DFC9942ULL, 0x85876D9E0E7EB24AULL, 0x6B512C37827FF268ULL, 0xFC1FB126BD14625FULL, 
            0xC3C01C9723EFC1B4ULL, 0xF54E510F90352F3EULL, 0x0910AF82DD800D1AULL, 0xEF796BB41E50AB67ULL, 
            0x27967A703690E64BULL, 0x8EA93489C1170395ULL, 0xF487C0CCCDA2FEAFULL, 0x40407E40966EA8BAULL, 
            0x629592C482D1054AULL, 0xA6DA3B7DD3517139ULL, 0xFA03364A23AAC3FDULL, 0x9AEAAD97D563105CULL, 
            0x94077E9EE96474C3ULL, 0xB2168C57A1DF7888ULL, 0x57EE1E1E21A8048EULL, 0x33877122EA1B4D4FULL, 
            0x7630AB0CCF729A99ULL, 0xBC931086524C2289ULL, 0x24B9BBD89502E4A3ULL, 0xBD6DBBA9D9BDD837ULL
        },
        {
            0x10CE4FC936EE6521ULL, 0x37DF058583BD49AEULL, 0x7D6EB2790E46A385ULL, 0xD3B3F72E593A1C76ULL, 
            0x247DC53481E52663ULL, 0x51921E078AACAE71ULL, 0xD4AB71ED5718B687ULL, 0x9CBFC584EA13B2EDULL, 
            0x0504BEA618C5D395ULL, 0x56B294F99E394B0FULL, 0x664FC4C8CB47BA9EULL, 0xF211898E6386E4F5ULL, 
            0xE6AA65E98F96EAACULL, 0x21703C18C30F7E8DULL, 0xBE94D218C7CB1F06ULL, 0x832A8C70E5743354ULL, 
            0x3CF7AEB5063147FEULL, 0x04825F23FF56DBB3ULL, 0xF33328F392CE3E19ULL, 0x10E5B7637E0F59CEULL, 
            0x1871FD041719E4E8ULL, 0xF871FBD6FEA00560ULL, 0x39315C315E4EEB70ULL, 0x5026AE539D150021ULL, 
            0x06E70D0AB4CC7036ULL, 0x0F648FC29131942DULL, 0xBC023BA945BD6372ULL, 0x3C7E2C1A674CF120ULL, 
            0xA04C7EDC9FBA41FAULL, 0x068C8318EC70BE6AULL, 0x6B18164A74B1C291ULL, 0xA0DEBA5BF2C39873ULL
        },
        {
            0xA041230BF7FBA6D1ULL, 0x7EFD1A4D32D055B5ULL, 0xE77B5B10513149A2ULL, 0x010F6CEB9673A46EULL, 
            0xAF7439DE5F151969ULL, 0xB70D9AD98A545ADBULL, 0x410DFD0368589F5EULL, 0x4A4F8C006D394E8DULL, 
            0x09F6650F9562808EULL, 0x8EFBAE3B00B8AD12ULL, 0x2976C668FEA80C5DULL, 0x5AB60412BC9FA01BULL, 
            0xDB1E06FB1A1769F2ULL, 0x3C4FF281314A9FB0ULL, 0x19DAD4845AD6DAEAULL, 0x87E23A2A7F602B97ULL, 
            0x84C3E85768EBD182ULL, 0xB1461F34F0C6F92FULL, 0x61444110C3B8B472ULL, 0xF85341A6747A724DULL, 
            0x6512458D094C957CULL, 0x056DFB88950C262CULL, 0x4218EEE1CC143D1DULL, 0x9803D1A5EE622E19ULL, 
            0xEEA498EBA52997F6ULL, 0x40636AA02BA8B630ULL, 0x03451CBCAD20B637ULL, 0x4111981093CBFDE5ULL, 
            0x2F0351C16C39D0C2ULL, 0x618FF684F1EADB1CULL, 0x452C63A34DCDB0DAULL, 0x50DA79882378C44CULL
        },
        {
            0x368EF1AC778FBBC8ULL, 0x51F88EEAA7601F82ULL, 0x27005DE82A5B9FF3ULL, 0x25B487BC35D53FC6ULL, 
            0xE16E33B9C78DA07CULL, 0x24541331F5DA7CA9ULL, 0xD88A6F1389AE52F9ULL, 0x1D518CC9657616A3ULL, 
            0x1B241F54388F710AULL, 0x760F8E494CB232B1ULL, 0x44098ADB32EB7C11ULL, 0xCDE363611D8ED92CULL, 
            0x62ED1D387EABE6A5ULL, 0x4EBE0ADBB1D26065ULL, 0x994477906FCDF5BBULL, 0x0A1E0D58A6791CB7ULL, 
            0x97F2DDC808290933ULL, 0x2ED49B3C0372794AULL, 0xA215A39E3E510DC6ULL, 0xD8F828ACD9BEAFA1ULL, 
            0x3C34E23BBE392748ULL, 0xBBE09C55631CE952ULL, 0x997C7970F7DF244FULL, 0x87D49EB3D65EBB91ULL, 
            0xEC531527454C9E7BULL, 0xB8D73E36CC0C46C0ULL, 0x6AB687B03D58FE1EULL, 0x812DDE85E9732D3FULL, 
            0x9EB6B91075A52BDBULL, 0x7EA274B510D7B7A3ULL, 0xB534CE2927C8DE0DULL, 0xF3067AF5B4414FAAULL
        },
        {
            0xCE230C0AC75A3B1FULL, 0xC11F1BCAA4C3CE78ULL, 0x52AFFD20D57629CFULL, 0x5EFBB360488A77B8ULL, 
            0x8429A7E0A7242209ULL, 0x453ABBDD35F30C1EULL, 0x419731E7E67F0266ULL, 0xEBA1A6A93A9EBA5DULL, 
            0x9F3C7FAFFF19AE03ULL, 0x0B0DD5306B03C735ULL, 0xA4FDFF021D620AEBULL, 0x8180707146F8C3F3ULL, 
            0x4CE4CE07CEC8BEC9ULL, 0x3864EDCE9392D8A6ULL, 0xF7E57BD7264359E8ULL, 0x6AA12B7EC9DFD9A1ULL, 
            0xC194E51D6B8BDC40ULL, 0x1701D88E782C79DDULL, 0x06806A1EC3B62839ULL, 0x70FBCE12702016B1ULL, 
            0xFC5478443A6C7608ULL, 0x104417BAF3E40250ULL, 0xC92EE12E1BEB76F9ULL, 0x35E9B4AFE6601E0FULL, 
            0x05CA149B83244BB7ULL, 0xF60805CB555B4204ULL, 0xEBE94D867ED7D252ULL, 0x9EE93ABCA27C1524ULL, 
            0xB611ED138E06777CULL, 0x38FB342B3AE1565FULL, 0x2CF3AB2CB2494386ULL, 0xB6353FF5278219B8ULL
        }
    },
    {
        {
            0x7F5E8F8C939BDE17ULL, 0x8CE7803B1A53F48EULL, 0x547564CB5DF8C3F3ULL, 0x9748E791B4BFF188ULL, 
            0xD02EE95655320D4CULL, 0xD16CEA336B9279FFULL, 0xEA6654F9583E77E9ULL, 0x140916059C9BD077ULL, 
            0xC7DACC4E1492A3E2ULL, 0xCA8D7A65A4911770ULL, 0xD959DCFD3C5E04A3ULL, 0xE173DD1BAFD93F46ULL, 
            0x5DCF3F98B490F5A5ULL, 0xA264017FD0B4D2C6ULL, 0xD4D737F5A145AD16ULL, 0x95FBA72FF3AC6298ULL, 
            0x3B65CB8248A36D45ULL, 0x4D0D87C2DFC130E9ULL, 0x87BA9F761EF11236ULL, 0x6A940DE17A1C4233ULL, 
            0x841D70E8A59CF706ULL, 0x9497DB5AC97D7D73ULL, 0xE82C6A5E33829DA5ULL, 0x067CC09A0693201BULL, 
            0x91C993E3D768F619ULL, 0x7A6017801FF7BA0EULL, 0x425B7EFFBE125C5BULL, 0x1525113A06C44C19ULL, 
            0x53E6C0CFA9335BE2ULL, 0x31D4493EC73E60EDULL, 0xA49C096A72C192AFULL, 0x9EBFB9BA9C50E0EDULL
        },
        {
            0x4849CC86855C105FULL, 0x4638C2CBBBFA198BULL, 0x7C7D488C3209D33BULL, 0x6C45E6B9CB3CBC96ULL, 
            0x7ED915552D292F38ULL, 0x38D510468145A09AULL, 0x40B9531721C7767CULL, 0xD026E4B9DB41FA6DULL, 
            0xE147EEED6D5A5139ULL, 0xB195CF4115638DE5ULL, 0x1E4D5C9531846725ULL, 0x2E3D11D7F48417FEULL, 
            0xF2EDED10EBA5BB42ULL, 0xBCD0BA2E3A794015ULL, 0x6015800E5A4D7253ULL, 0x81F42D0AC7D9EBADULL, 
            0xE1461E339B45E73FULL, 0x67F4BE9514E417C0ULL, 0x4689FB311C70EB1CULL, 0x38EB35372DF036ADULL, 
            0x3C670A2761912344ULL, 0xF413CD200DEA8961ULL, 0x54C7016F5A3942F5ULL, 0xE876297D5A34B4A0ULL, 
            0xFBB6289CBA9429AEULL, 0x08E1A89D39B7775AULL, 0xEFDA192456F64EE0ULL, 0x2E1F15D81EB5822EULL, 
            0x57221E7CE9085BBAULL, 0x3027464E1D29D1F1ULL, 0xF0057BA472B01714ULL, 0x59F1068068EA605AULL
        },
        {
            0xF1037B0F74010F3EULL, 0xECCE3FAC9C98E872ULL, 0xC6ADDBE2D325777EULL, 0x5CC16A75AD609BE5ULL, 
            0xF0E679FB798A58D0ULL, 0x519DB38B7BD0FE94ULL, 0xFA505701F9EBFAA2ULL, 0x29F489298AE68176ULL, 
            0x943A4DBC7546EFCCULL, 0x4CF23C1D7ADAF1B5ULL, 0x1F35817ECFD852E2ULL, 0x109964771EA40917ULL, 
            0xDF4526972456CB98ULL, 0x36CD5BC9F72ACE96ULL, 0xD5061C76833A49C4ULL, 0x8E5EE3F189B8F230ULL, 
            0x26554CE7EA66AC46ULL, 0x0BB6DD47536C4158ULL, 0x3CD2D2E34B7CA50BULL, 0x500A3DA3DFF04284ULL, 
            0xC469EDB24E161782ULL, 0x2E66FD4D78FB2481ULL, 0x032E11AF6F9706BAULL, 0xA4B68E0CACD7E164ULL, 
            0xA710FD8346AC7787ULL, 0xADA74364E16D48A3ULL, 0x1CFF916A3427E288ULL, 0xCE055F911BA696D2ULL, 
            0x14E5C57750D376EBULL, 0x33F6A05C8E3AC5D7ULL, 0x2EDD0232A69F7998ULL, 0x896F660FB7EAEA92ULL
        },
        {
            0x4858680E604765E9ULL, 0x4685CA1BEB174D06ULL, 0x7EA16BCADFEEB389ULL, 0xF4D453C4AC7E2A68ULL, 
            0xFB9BEC8B6A9E5332ULL, 0x15C142B157D1FA24ULL, 0x5C4A0902ECBC76FCULL, 0x819A817F672D8FEAULL, 
            0x3BDD67C121A37F45ULL, 0xB6A5B66CBDD3CA98ULL, 0xB3170B038A80AEB7ULL, 0x91FBA6A14AAFD71CULL, 
            0x54CF4334A1FFE562ULL, 0x282900A58578E8B7ULL, 0xAA58AC3981A2F8A7ULL, 0x71F06775F97357BAULL, 
            0x21CF60529DD44D18ULL, 0xCCED26DF973F66B9ULL, 0x07A825D904CC5B5FULL, 0xCC16B30A7E5E5A8FULL, 
            0x1ACAC0A893F17D32ULL, 0x45AD3A932618CFDBULL, 0x70C9693A58C72D08ULL, 0x958553AD2DBF2A40ULL, 
            0xAEC8A3E3F21D1A2FULL, 0xF5222E365F02AA55ULL, 0x49BB0C95451170C1ULL, 0x4AAF6648DD5ACD09ULL, 
            0x4B71943C8EFB2EBAULL, 0x133E405B6EBC8676ULL, 0x4F8F3AE145B1B674ULL, 0x7BB2AE83271CD8ADULL
        },
        {
            0xDF8953580319DBDDULL, 0xB608125E882E8E57ULL, 0xC3A090E35BE62533ULL, 0xE2409858468A7C0CULL, 
            0xBBBDDA1B3F270336ULL, 0x98CE1110C9D851EFULL, 0x5FA604632ABE6979ULL, 0x73ADA66145C04920ULL, 
            0xDB2E72DF438E8881ULL, 0x44FDE856ABD2972DULL, 0xC9C93430101BEA05ULL, 0xCA26E0F4E90A6DC7ULL, 
            0x4D844BA6BBDAB342ULL, 0x94E979F30C99D3E7ULL, 0x360137339825399EULL, 0x144A479805219F03ULL, 
            0x58BFA1121B1A5931ULL, 0x3377BE40D8533CA9ULL, 0xF3B3B87354D1E202ULL, 0x5FF9165F599AB9A9ULL, 
            0x831C3A1FF2F7A748ULL, 0xD95B75AF69866286ULL, 0x3F06AC5828F1F24AULL, 0xA84AA781953A9499ULL, 
            0xCC6AFEAC466658F6ULL, 0x16553D8B3858513BULL, 0x162C47305918E1E4ULL, 0x6C6D52725071C638ULL, 
            0xF2FBCA4BAD791BF4ULL, 0x41D1CD3AB03CE7A6ULL, 0x9C3B481F3F718C64ULL, 0xC0F07C431DBE885CULL
        },
        {
            0x04C1139C2C30C886ULL, 0x7B119DD40EFD7377ULL, 0x7D257780943F4A6EULL, 0x0DADEB297FAB755FULL, 
            0x12681E4D93993372ULL, 0x38707A83B43D7746ULL, 0x38AC7DA5A0E649FCULL, 0x4E18B5B55F900AD1ULL, 
            0x98D11C1972635BDAULL, 0x3C28E50542C0AD05ULL, 0x90A2E1BDBB542D60ULL, 0xD056809383E943A6ULL, 
            0x3AE151ED39104BAEULL, 0xF0EF3ABDE33CCFD8ULL, 0xD27103E512B3CEFFULL, 0x4B2539D6C7B74FDBULL, 
            0x445D18C5721C5595ULL, 0xF8EB186560D6AAFAULL, 0x8140609C5CD9C88EULL, 0xE3BB67C6001E5CA3ULL, 
            0x16249E62AA355EDFULL, 0xBF384BBF5B30C065ULL, 0x281C6F3D5B16D5C5ULL, 0x44F1E3A252DC670BULL, 
            0x96356ECBE16A9963ULL, 0x904813B43F133D28ULL, 0xAA4B5460DB3F37F5ULL, 0xB4C9C65369FC29C5ULL, 
            0xA56A9F4BE6AA1631ULL, 0x5F8D246CF6316D0FULL, 0xFF14A7CBC5A862C5ULL, 0xD6141EEF3260BC49ULL
        }
    },
    {
        {
            0xAEDAE415143645DEULL, 0x05C759E728020FEAULL, 0xDA411E0E3A0DE339ULL, 0x0D30F42B5BAF4B80ULL, 
            0x66780BE796E2553CULL, 0x090A4B727DAAFF80ULL, 0xF6166C09CD183DCDULL, 0x76856680245BE502ULL, 
            0xE55A383B7B572502ULL, 0x7F7D25D574CD20DDULL, 0x0677F814463852B9ULL, 0x458B455B355DEE86ULL, 
            0xD623B73131328A28ULL, 0xAB028417FA117945ULL, 0x5B251E2CE07A7A7BULL, 0x5FF80F508D543810ULL, 
            0x91A1C7CFBCED7414ULL, 0xD1F045C93528605AULL, 0x8DF898D692255019ULL, 0xA114CC87FF6C23BBULL, 
            0x695E5E3B18F386AAULL, 0x414A7774FCDBA160ULL, 0xDA503F257BA90396ULL, 0x03C1D8DB517E53C1ULL, 
            0x0864EC7909B9E174ULL, 0xC8AB40F4D3E284E8ULL, 0x80C64578132557D9ULL, 0x6F38CF981E34A095ULL, 
            0x11427129DCBF183DULL, 0xBF956FF03D1AAF18ULL, 0xC3F74ECFFB2B9A9DULL, 0xDE83DEED39931C2CULL
        },
        {
            0x0CA50C4B63C8D2F2ULL, 0x08EACAEC4D5A04F7ULL, 0x5DE73D8172577964ULL, 0xEFE7547757AB436BULL, 
            0x75ED38FBD7EC1DF0ULL, 0x4F6747E52F08B400ULL, 0xC1C6853B2A1F111BULL, 0xDB4447DE2852FDF3ULL, 
            0x8151496B95AAD577ULL, 0x388582E6FA38B16FULL, 0x69354A09DC198294ULL, 0x715868B8D8B292CFULL, 
            0x5C7EF08958676C78ULL, 0xBD03942836E9A071ULL, 0x65674AD08C99BF37ULL, 0xD040111ED820E265ULL, 
            0xB841969E012042DEULL, 0xB96F6A9077EEDDB3ULL, 0x70A7D49A44EFDD18ULL, 0x5B6AAF09D7C454CBULL, 
            0xB3DB40747A44DF30ULL, 0x45B9704DC598AF76ULL, 0xE7F13F122C4A9E52ULL, 0x454AD8BDC3488EF3ULL, 
            0x1417748D68569F7EULL, 0x5208B4CF444EA435ULL, 0xA60FB5E84A8C753CULL, 0x7784DED58FCA0555ULL, 
            0x4664682AC007DF8CULL, 0xC485358AA2A0973FULL, 0x4CF34F975B4E32BDULL, 0xEA77156981A5B109ULL
        },
        {
            0x813F4F8675ECE7EEULL, 0x0218C2F50A7D31CDULL, 0xA97FB0BEFD2605B5ULL, 0x2FA57690EA607EA1ULL, 
            0x10D359D2D3B4F4FCULL, 0x7EA2F8D81B763398ULL, 0x598680E343901207ULL, 0x0C641D38AEB25208ULL, 
            0x6642AF5807CD8A9EULL, 0x4298F9B9152D844AULL, 0x81E6873394C0C9A7ULL, 0x19C8F088941970FCULL, 
            0x6AB91D5AA31A173AULL, 0xAFA12DB75BA5F997ULL, 0x9AF3C63CAF4161F2ULL, 0x40FD577F323B1EC8ULL, 
            0x132CBBC4750F5940ULL, 0xF84A1BDB6D837C64ULL, 0xA25926DD3A1A3597ULL, 0x0410B041666EBF87ULL, 
            0x89449DD70E8B64EBULL, 0xEA23FEE5BBCB1D37ULL, 0xE12383C748E6353FULL, 0x02098C3DCFF5240CULL, 
            0x85A4C0AEE9CFA277ULL, 0x19DB8C12F94BACAAULL, 0x8027A25684C7A19DULL, 0xCC1E9B879379CF20ULL, 
            0x8AD2A94D343AE6B1ULL, 0xF6747469B876100CULL, 0xEB7859AF6DDAD64FULL, 0xD039A3E4873200C1ULL
        },
        {
            0x0589B970E7079325ULL, 0x1F07C4943BFC9F4BULL, 0x984FB826676A3C41ULL, 0xA7FB75F653E5DC8AULL, 
            0x366858327E7CE0D8ULL, 0x9306F66260FED127ULL, 0x7AD904F897DC5488ULL, 0x2F0C6E98E8B07183ULL, 
            0x1E7F9E64BCDB107EULL, 0x7330D75CF950D975ULL, 0x31E9B8EC5A9010C9ULL, 0xF121CEA1427B97B4ULL, 
            0x2A8338EF4F9DAE70ULL, 0xD5353D34405C7462ULL, 0x60DCD3B393B0CED3ULL, 0x1015FDD6CFD95F65ULL, 
            0x0BB901EEA650A771ULL, 0xF30C4ED9BF1E5AEBULL, 0x19EF247152B5D234ULL, 0xA959F0AEC98B8EC1ULL, 
            0xCC739E61A2326D6AULL, 0xF85035F102F15C69ULL, 0x44283E2A7571B6B1ULL, 0x464481D5071FDE6FULL, 
            0x785E6FCD85DAA1AAULL, 0x88224C6A849A4D80ULL, 0xC48536378561C36BULL, 0x5F2393096B24B9D5ULL, 
            0x516B9F402FAEB0F4ULL, 0x35CF42425BCBD95BULL, 0x71E7130ABA1F21BDULL, 0x8E5436459B8DCDCBULL
        },
        {
            0xBF097E52D8080DDAULL, 0x9E1A52B80D1B1A89ULL, 0xCF80060F9758AD9BULL, 0x55EE780770C955FBULL, 
            0x2AFD24D05C1B94BAULL, 0xBBDC4DA7785939ECULL, 0xCE1AF09B08E0163AULL, 0x6F0D88DB7588B970ULL, 
            0x489B15200FE41ECAULL, 0x19C9DF60166F6684ULL, 0x19B77E3AA1E2AADEULL, 0x2B9184601F10CEC3ULL, 
            0x66951DE5EB068217ULL, 0x1FFCC77C5571374CULL, 0x01ABD64743BA3220ULL, 0x21BA11C20816E3B7ULL, 
            0x96DBD2FA5E0ABA7CULL, 0x90A1815793DFF681ULL, 0xCCCF303F76B1C9F2ULL, 0x077DAEDEA68D2550ULL, 
            0x96E9E64A5FACB7A3ULL, 0xC8E660E6D5E274BAULL, 0x0BDD9C2E7845A510ULL, 0x59F060E994A193F9ULL, 
            0x067045390408B595ULL, 0x4606F77B697361D4ULL, 0x211BE899DCE20000ULL, 0x9D2862B8552FE67FULL, 
            0xED236F4627F26863ULL, 0x5BF026129FF52B98ULL, 0x6E5CFB0ABB887F8AULL, 0x761694BFA877B01DULL
        },
        {
            0x73A0E2B1B6B090F3ULL, 0xA62520597F2C48DBULL, 0x0D248F56A051D8C2ULL, 0x449C23827D0E1282ULL, 
            0xD7DC7638CED906ECULL, 0xDA233C52D00FF4F7ULL, 0x63B655AC10E3F987ULL, 0x870284B2355C7395ULL, 
            0x1174F6F3A0A87F21ULL, 0x4859E2AA7A46C477ULL, 0x24E8C9263DF3CDC0ULL, 0xFB834EEEDEFAF37AULL, 
            0x37C1FABD7A93E05EULL, 0x990B6215BB06AD17ULL, 0xB17605008CE23EAAULL, 0x230BE1E1668DE85AULL, 
            0x11EFDDDECCADE1C9ULL, 0x1F00E7B1C1CCCE5DULL, 0x2BC6AE0B1200E913ULL, 0x6A85079FEC9BCFA0ULL, 
            0x9E92350DF3BE8253ULL, 0xD214F5F2D32AECF3ULL, 0xB3B34CE32A749657ULL, 0x6E3772EAC954D22DULL, 
            0x5DB6B0432BCAD653ULL, 0x7C3F3E54784A00DAULL, 0xA6AD49FC45311D45ULL, 0x79B27DED4869ECD6ULL, 
            0xD3298C948C151E04ULL, 0x7BE0F8546B4BEE0DULL, 0x60B6948D3F9DCDBBULL, 0xED9ADDD3A06C1EBEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Fencing::kPhaseHConstants = {
    0xA25A4EA8C0EFB5F4ULL,
    0x2A3B126391D8CA7CULL,
    0xF153E0CA864BC573ULL,
    0xA25A4EA8C0EFB5F4ULL,
    0x2A3B126391D8CA7CULL,
    0xF153E0CA864BC573ULL,
    0x583C3AF4F1AF5D18ULL,
    0x8802A84DD4F6C698ULL,
    0xF2,
    0x9C,
    0x43,
    0x5A,
    0x44,
    0x99,
    0xA2,
    0x7F
};

