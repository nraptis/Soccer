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
        aPrevious = 12455596912995384418U;
        aCarry = 10861964335307129427U;
        aWandererA = 16169983507434774555U;
        aWandererB = 14968778313693650999U;
        aWandererC = 10277293078633491711U;
        aWandererD = 11745284080549195840U;
        aWandererE = 11813266364809805948U;
        aWandererF = 18027180495489324634U;
        aWandererG = 12524718214293094226U;
        aWandererH = 9845789917396488481U;
        aWandererI = 13355815029830697042U;
        aWandererJ = 15894632109858897931U;
        aWandererK = 10122572483284432156U;
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
    TwistExpander_Cricket_Arx aKDF_A_BArx;
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
    TwistExpander_Cricket_Arx aKDF_A_CArx;
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
    TwistExpander_Cricket_Arx aKDF_A_DArx;
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
        aPrevious = 14863018640918453805U;
        aCarry = 13004416629935572405U;
        aWandererA = 13567942422143264016U;
        aWandererB = 17803746223969932081U;
        aWandererC = 14719754459057991075U;
        aWandererD = 18390620002624216248U;
        aWandererE = 18268800325470160029U;
        aWandererF = 13945514223050241353U;
        aWandererG = 17601054047028934875U;
        aWandererH = 14346855895921766508U;
        aWandererI = 14764726916513445820U;
        aWandererJ = 11693983165346460557U;
        aWandererK = 15501672963143776075U;
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
    TwistExpander_Cricket_Arx aKDF_B_BArx;
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
    TwistExpander_Cricket_Arx aKDF_B_CArx;
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

void TwistExpander_Cricket::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    }
    // KDF_B PhaseA invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseB invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    }
    // KDF_B PhaseC invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneG (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    }
    // KDF_B PhaseD invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseE invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseF invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseG invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneE (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseH invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
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
    TwistExpander_Cricket_Arx aSeed_AArx;
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
    TwistExpander_Cricket_Arx aSeed_BArx;
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
    TwistExpander_Cricket_Arx aSeed_CArx;
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
    TwistExpander_Cricket_Arx aSeed_DArx;
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
    TwistExpander_Cricket_Arx aSeed_EArx;
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
    TwistExpander_Cricket_Arx aSeed_FArx;
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
    TwistExpander_Cricket_Arx aSeed_GArx;
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
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
        // read from: aOperationLaneA source quarters 1, 1, 2, 0 with offsets 8126U, 5086U, 4503U, 340U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8126U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5086U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4503U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 0, 3 with offsets 2170U, 5958U, 6040U, 5434U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2170U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5958U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6040U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5434U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 3, 1 with offsets 2567U, 2073U, 6447U, 579U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2567U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2073U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6447U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 579U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 2 with offsets 1432U, 3998U, 593U, 7450U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1432U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3998U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 593U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7450U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 2, 1 with offsets 869U, 928U, 1191U, 1213U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 869U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 928U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1191U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1213U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 1, 2, 0 with offsets 1470U, 1837U, 1800U, 2039U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1470U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1837U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1800U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 1, 2 with offsets 1346U, 1811U, 1732U, 1080U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1346U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1811U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1732U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1080U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 1, 0 with offsets 1674U, 668U, 852U, 38U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1674U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 852U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 38U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1895U, 132U, 565U, 1081U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1895U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 132U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1081U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 1 with offsets 3182U, 2811U, 4818U, 2236U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3182U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2811U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4818U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2236U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 0, 3 with offsets 5324U, 7898U, 4155U, 916U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5324U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7898U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4155U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 916U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 2, 0 with offsets 5681U, 5931U, 6455U, 1953U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5681U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5931U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6455U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1953U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 1, 2 with offsets 6963U, 5029U, 4160U, 4049U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6963U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5029U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4160U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4049U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7768U, 5988U, 3296U, 4128U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7768U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5988U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3296U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 4128U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 3, 1, 0 with offsets 1891U, 704U, 258U, 688U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1891U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 704U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 258U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 688U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 2, 3 with offsets 918U, 252U, 443U, 196U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 918U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 252U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 196U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 1, 2 with offsets 1928U, 1859U, 1305U, 568U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1928U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1305U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 568U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 1, 3, 0 with offsets 1818U, 852U, 165U, 150U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1818U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 852U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 165U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1490U, 1708U, 1534U, 2032U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1490U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1708U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1534U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2032U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseASalts = {
    {
        {
            0x003F430754D5FE04ULL, 0xB17FEEDF13B33885ULL, 0xD134398EC7AC3608ULL, 0xDC195C3175A88740ULL, 
            0x924D949018DE1565ULL, 0xCAE652C48488D832ULL, 0x43819934888356F1ULL, 0x18377C1574873F84ULL, 
            0x0638A3662F40BD7AULL, 0xC709D33A37E0E45AULL, 0x488D60CEDB9465BDULL, 0xE602920C4D5027FDULL, 
            0x43EF84BFCE5594A6ULL, 0xEC62B7FF60FB568EULL, 0x7AABB78ECEFBED60ULL, 0xDDA9524A2E517F7AULL, 
            0x33CAC895B095D786ULL, 0x587DA593EB01844BULL, 0xAC8CEB79A0402230ULL, 0x3F3B4A9EFBDEC627ULL, 
            0xD1D979206687674DULL, 0x306C88F72DA35E39ULL, 0xC2D49FA3AEDA94EAULL, 0x4ABD5AF33E2A0B45ULL, 
            0x83F7AB55C3B2C12FULL, 0xE7363D1EEC55B563ULL, 0xEF6BA1E1A234797BULL, 0x55383A20867B5CA5ULL, 
            0x29C58137BB10D176ULL, 0x6CC46D0C7C8D83D5ULL, 0x6FA64BD371FA55D8ULL, 0x146D960FED1C77CAULL
        },
        {
            0x428ACA5F18E941CAULL, 0x216427C6C93006E0ULL, 0xFB271BB3CC6B7B31ULL, 0xAA70DE5A3749B2A4ULL, 
            0xF2C2D5C5CF20547FULL, 0xDE5A4C1BD0866A25ULL, 0x53E78909A415780BULL, 0x2C11523DDD0F95A3ULL, 
            0x33ACF6898B7CDB66ULL, 0xAE506B88B2828147ULL, 0xD5E2BE65A2E62024ULL, 0xA3B86E177D32E70DULL, 
            0x1D529E38FB45D990ULL, 0x3033807021DCA231ULL, 0xC4694C852386F4A7ULL, 0x9B24DA464424DAF0ULL, 
            0xFE9E0BEB91286EECULL, 0x5C212EA89F26FCE0ULL, 0xF227D894591CEC1AULL, 0x421392E7FF6DEA48ULL, 
            0x188F01AB2623E511ULL, 0xC216753B4CB2E074ULL, 0xE80F1FF869BF2766ULL, 0x0F0789475CBEC4D2ULL, 
            0x12AD724314BC4DE1ULL, 0x9F759848292EBC35ULL, 0x4B5BDAEAFFB189BCULL, 0xB51B9C0BC8A5E5F8ULL, 
            0x50FE21055E9D69C4ULL, 0xE1DFBF47FDA807FBULL, 0xE1AA3A4689E47CD5ULL, 0x694A562ABECFC225ULL
        },
        {
            0xC4EB2DA2622675F4ULL, 0x62EB456A1206676DULL, 0x69D673C9E936C7B5ULL, 0xA168AB8065F1B15FULL, 
            0xEFB726A9755B7050ULL, 0x7864292A72A23D80ULL, 0xDEAC886673057EA8ULL, 0x18463DF87D398623ULL, 
            0x0573E57B9316EBC3ULL, 0x3CE4C4FBFA4D65F1ULL, 0xD211C0BDF955466DULL, 0x18AE532520565D6BULL, 
            0xBADBFC527922975DULL, 0x404B67ECD986D30FULL, 0x8A29B40CFCDC5C4FULL, 0x247B66F8F3E09291ULL, 
            0xBBC61109EE42EFF9ULL, 0x1C06B5C97AF548C0ULL, 0x35D49FF207C9CDF4ULL, 0x2F53DEFA8EAB9E42ULL, 
            0xC6F2C1B59FE8AAD8ULL, 0xBFD0646D815007B3ULL, 0x63987FF5C2309538ULL, 0xFEEF90680E801F7CULL, 
            0x66CFFCA011864442ULL, 0xB9395FBC3E77AF72ULL, 0x24E627A6DD28A6DDULL, 0x939A4E33FB43C90EULL, 
            0x5DE301267539DCFEULL, 0x82D8264E00FE0105ULL, 0x5C9D246426C2B5FAULL, 0xC6BE495820842DEAULL
        },
        {
            0x6D5C21A1BE70CF4CULL, 0x1B2933806545F09EULL, 0x05F873DC124571E3ULL, 0x43D7FFE7F221F855ULL, 
            0x9ED084677DDDAEE1ULL, 0xC012D2953452BD11ULL, 0x43D5E43A92B62FF1ULL, 0xF198C26443885F38ULL, 
            0x0ED47265B9C9143EULL, 0xA7BFBAEAE3785C9DULL, 0x7D6239C13022DC95ULL, 0xC7546284E1A229DCULL, 
            0xBABB27CECA410FB9ULL, 0x48D955649CA015E3ULL, 0xD3079674657A6095ULL, 0x1C83296BFE9A355DULL, 
            0x9A648977E2F897DCULL, 0x2AB935D6BFD9A840ULL, 0xF957B18BDE9CDBFDULL, 0x37DABE9206A299C9ULL, 
            0xD9972C8795DE7D8FULL, 0x7429447AB12EFA03ULL, 0x5667AC53C04CAE7EULL, 0xAC3399C32FADF888ULL, 
            0x06FED9954638E547ULL, 0x35A0BA94D29434FBULL, 0x479D88BD239E2C81ULL, 0x54A6B8D2F97E30D5ULL, 
            0x69B3457B161DE056ULL, 0x6C1FBC1B798DCB50ULL, 0x5F00370BC44D3337ULL, 0x5197B647B66EA578ULL
        },
        {
            0x23A793926D29C197ULL, 0xB12DA3F2B4ADD1DBULL, 0xCAB592E0E15D1821ULL, 0xCED0D85557438762ULL, 
            0x3E2C3CF56DCBB029ULL, 0x3BD9951D77ED2608ULL, 0xE98BBCA4A4C6B56AULL, 0x7A8871E067E92873ULL, 
            0xEB57798A149A2741ULL, 0xA19AECDE7A1B776EULL, 0xFF9DA84D387A74D5ULL, 0x4F4ED304AE81CAE1ULL, 
            0x9DDD747A868329DBULL, 0x0C47B2FA99C898AAULL, 0xF26F6ED089DCDB6AULL, 0x8A5850ABCBD60C3CULL, 
            0x4DF8537AD779D6D8ULL, 0x20A732B0DBB8E0C9ULL, 0xC7AC04F2B983C5C6ULL, 0x8FE1391D0D25D757ULL, 
            0xDD79C94C79616590ULL, 0xADEDCFF7AD75497CULL, 0xB1125CF59834A97DULL, 0x7944CA6990D3597EULL, 
            0x0018D3DC3DBF0C4AULL, 0xA6EEFD201D5E191FULL, 0x24742993398B01A1ULL, 0xF881D56D9C013C84ULL, 
            0xBBABD185995FC112ULL, 0x59E523E279BED4FFULL, 0x79D42F0AAF436F96ULL, 0x35DE5056B3E650AFULL
        },
        {
            0xBC6362B90C5243B8ULL, 0x612B8F58EA5462FFULL, 0x8425177B7A1D4F21ULL, 0x8D2924832A21109FULL, 
            0x7ED1F910210FCECAULL, 0x7B8CE5A6ED4EB7F5ULL, 0x126A801ED06E9891ULL, 0xFCA69B654718F088ULL, 
            0xCF2D9753C844F21BULL, 0xFEFFFB0710E6EEE3ULL, 0x8146E8D788F9CFDCULL, 0x562194759B6E9E51ULL, 
            0xB1F98FD1C7AD024CULL, 0x05E60792EF6DBEBFULL, 0xE335874A44772926ULL, 0x3911E4EC68D6B1B1ULL, 
            0x0D9594946AECC449ULL, 0x697341E39AD515A2ULL, 0xAFAAE86138BA0CFBULL, 0xF565CB1A71FED95CULL, 
            0x4C2C321F898E0DD7ULL, 0x3B5E78DE80430472ULL, 0x39E7A7A7E026BD9EULL, 0xDCE19FA78227FD0CULL, 
            0x18BCBDDDF777EC9DULL, 0xBAAA5659089831E2ULL, 0x66D35B24BCCB6E41ULL, 0x4AA9E32D77C17F72ULL, 
            0xD8B1AA80C92D02E2ULL, 0x6FA378765593BF9FULL, 0xB9326D49559AE3C5ULL, 0x008A6D961DE8DC44ULL
        }
    },
    {
        {
            0x39D870AF301D4E7DULL, 0x9A6B4836F1A692B5ULL, 0xA2901782B5E648EEULL, 0x2817D35953892709ULL, 
            0x297B315DE2F6C845ULL, 0x937BBBAFB3FBFCCEULL, 0x4975677BB124D56AULL, 0x950BF32F95ED19CEULL, 
            0xA4ADDB95D0E8C996ULL, 0x3429339E85753ADCULL, 0x2CCF9F8A49DB98A3ULL, 0x340A7AE06B9BEF44ULL, 
            0xB8C595A76FAA350CULL, 0x00F77F30498F731BULL, 0xF2033697E7DE859DULL, 0xED3027DB835338F2ULL, 
            0x7839575168E26195ULL, 0x2E700F1E05BE66C1ULL, 0x3D5AB12B7B5D3D4CULL, 0x59EC46F5CFC981F8ULL, 
            0xFBFB2926738D635BULL, 0x5F627955BB138A0BULL, 0xC78654A953C0A728ULL, 0x9E332423E0952461ULL, 
            0x2498953A8695B21CULL, 0xC3F8F94A2196E04EULL, 0xC706F9403F5F762DULL, 0x72AAD1F6656E7EF1ULL, 
            0x7DB796E0F40A59CEULL, 0x45663BB70B081452ULL, 0x8C74E4D44DB81B09ULL, 0xC05E1E208363D676ULL
        },
        {
            0x6549E6DE050A9FE8ULL, 0x1B0B2377E4E59E73ULL, 0xAB60050045D806E3ULL, 0x8AC5D7804666111EULL, 
            0xB46198E21BAA4F26ULL, 0xF6A82FDAEAA8A71CULL, 0x3EB90A678B6F162DULL, 0xCE4A53525DEF0548ULL, 
            0x8B990F7D2D366B21ULL, 0x93F346652FAF129FULL, 0x67D7E82B25B1B1C2ULL, 0x204105D9EA73BF12ULL, 
            0x233C3C8A64F9031FULL, 0x134C08A9BE37A98AULL, 0xDA595D942EBAF937ULL, 0x58888B4970495B87ULL, 
            0x41ADEA3554BE4EB8ULL, 0x960518D1138F685EULL, 0x71C95CE82677A58CULL, 0xB186077C3346AAC8ULL, 
            0x005374A6FAC4DFE5ULL, 0xE51179C44F9F9177ULL, 0xE7D81C3F03BBC80BULL, 0xDECE7A02D582134EULL, 
            0x3667307B364B94A0ULL, 0x84F9E4D34FE583CBULL, 0xD1EF985CAE009ADBULL, 0xA6F8E94127D443AAULL, 
            0x5757E9351FA4AD03ULL, 0xB7401FD8C293CBE8ULL, 0x8C85171A3ABFE979ULL, 0x04E13F177723FD4EULL
        },
        {
            0xF570F537AD935494ULL, 0x4916DBB219D059E7ULL, 0x4488B0B002DE73F7ULL, 0x9087C41F0C3CAC31ULL, 
            0xE44D2369653398AEULL, 0xD399BFDDECFF3239ULL, 0x2542C33100B7351DULL, 0xF526CE6D4C71498CULL, 
            0x61ACAB00E9F86A40ULL, 0xDB3C03885D61BAE5ULL, 0xE04B65C014C94415ULL, 0xA0871E73245B8A7DULL, 
            0x6DEB0539BA0563D5ULL, 0xAE2DC48A539A9CA3ULL, 0x3A4C5B269641A95DULL, 0x4704E44FE6076F60ULL, 
            0x27123C6564DACC96ULL, 0xE5DD886FEE301CEFULL, 0x9637B30519826933ULL, 0x2FD2C01E91D6B6AAULL, 
            0x0A8BF17D2ED9BCA0ULL, 0xC874E93E8912E903ULL, 0x94966771BCD63349ULL, 0x7FC9BC40BB4DB8ACULL, 
            0xA80F95572156D6DEULL, 0xBADA178F9A77EE4DULL, 0x13B191AD1E30825AULL, 0x524105708242F72CULL, 
            0xF6521CE315C400F1ULL, 0xC5A71D6A3AD83FA4ULL, 0x97E6462EAE297ED9ULL, 0x1BF5DCD6E1D4AA96ULL
        },
        {
            0x5C7863D806E74E86ULL, 0x98313D28615C448EULL, 0x9AD813D8C4E74C53ULL, 0x06B1D0499ED52D6DULL, 
            0x5752632B47D8DF4CULL, 0x5D2D8DA5C1250D29ULL, 0x00210C765B0A9BCBULL, 0x85D937927173464EULL, 
            0xD42EC0C462165291ULL, 0x1F4526D29B2FCC65ULL, 0x390CC1FD1015FA74ULL, 0x9AB85992D432FC02ULL, 
            0x33996872E1277929ULL, 0x1C1DE2565BC2B154ULL, 0xC1E58A5ABC93A88CULL, 0x95BB624F40724B54ULL, 
            0x2F2272637B8A7BEFULL, 0x5E65DB619110BD05ULL, 0x5087F175768FA26BULL, 0x2F629FD2EBA4491BULL, 
            0x58E8E35C6913458FULL, 0x00395C42726E450BULL, 0x273F705C7785EA54ULL, 0xF0240D5CD6B86DEAULL, 
            0x89701130D39CAEC2ULL, 0x48DD98C6023F2389ULL, 0xA1761F6E74A7F528ULL, 0x20F5874AB59ECC2DULL, 
            0x3373DC4C8BA78A87ULL, 0x5E6E023C2F10D4F0ULL, 0xFA35DFF6B55C2B4BULL, 0x5042C03D7B1EC58CULL
        },
        {
            0xDA17A66E62F5267BULL, 0x39561E8C206C1092ULL, 0x473E83CB13676C93ULL, 0x5693AEAFAE98BF37ULL, 
            0x8D399E4C3656ED3CULL, 0x42E7DFDFE28A6F3FULL, 0x8AC4F740D0C97E9BULL, 0x4CBA745245A44E4AULL, 
            0x4A033709BCE72A3EULL, 0x9F6F67BD628EF5EBULL, 0xD1C2910FE2CEA407ULL, 0x4805EDDCA6CD1E35ULL, 
            0x6DF76C23C9FDA999ULL, 0xDBE4143E5C71BEC7ULL, 0xED539E4EAA880A75ULL, 0x231965E7A3D034F3ULL, 
            0x2771818E1823F847ULL, 0xD58CACFFBC28292CULL, 0xE67FC139F6EFC4C6ULL, 0x31913F37E1BF29A4ULL, 
            0xC492BD8DAACDC149ULL, 0xC80C6B18F42A0149ULL, 0xE3D4DD423BB15DE6ULL, 0x47BE2C02E6CA1E09ULL, 
            0x11C61F31F45572F7ULL, 0x35EFEF45038E5401ULL, 0x88FEF7FC7E81B0BAULL, 0x5AA7A139AF78EB9AULL, 
            0xDE2D2F709F0B2346ULL, 0x829222E6BB4D9B3DULL, 0xD6D555D248A364A2ULL, 0x99E6B1CEAE82B4FBULL
        },
        {
            0x2EC7E5EEA4477840ULL, 0x2310428EEF3C2164ULL, 0xC9878D35E188FB23ULL, 0xA5E3F4C7A5E74A5EULL, 
            0x879BB30384B8378FULL, 0xCFFA41CA44E44984ULL, 0xDB9B181281AEFAEDULL, 0xC9900C931E72918AULL, 
            0xA0738D26DC366240ULL, 0x56B938C1A6F827A9ULL, 0xE84C58A747369584ULL, 0x3532FB3773B3F4F9ULL, 
            0xD438FA02F28CF218ULL, 0x14830A40CEAEE05EULL, 0xFC350EA4E2DE3B3BULL, 0x35A6AF1546D96225ULL, 
            0x1161FB65DA2A44A2ULL, 0xE57DCB9271B81ABBULL, 0xCAAFD41A29EB35FBULL, 0xD4596B4B4B640C9AULL, 
            0x9BB91EDE9386FFE2ULL, 0x715907CB050DBEB6ULL, 0x048E529DA8646CF9ULL, 0x29DA9A5165570B63ULL, 
            0xCDCE47848AFB91DCULL, 0xA710BEA277D0502AULL, 0xCF27BD457509C735ULL, 0xB3B1DFD48161D23DULL, 
            0x6A51D9CDF181DFADULL, 0xC90F613A5B52193CULL, 0xF0671DA0079DCB60ULL, 0xACAE3FEA43F0CAAEULL
        }
    },
    {
        {
            0xC41945403BC4AFA2ULL, 0xDDFC3EA4C68080E7ULL, 0x1E14B5536E309EB2ULL, 0xCFB4F8ED4EC9AB82ULL, 
            0x155E1480E8C4041FULL, 0xCE8E9BF352397F34ULL, 0xB2FD1FE2C5A8B931ULL, 0x0FF4315868C668E4ULL, 
            0xDD3C1913213C9F1EULL, 0x415A8E2790939FE1ULL, 0xC270C064B7F6CC05ULL, 0x2AD23B7120EE492CULL, 
            0xDAF147F87203CB15ULL, 0x5F1FB1B8441E6BD4ULL, 0x82F3981D401028F1ULL, 0x262A2369DA1F9971ULL, 
            0xE0798E17D700E7A2ULL, 0xDFAD174F7CD3F746ULL, 0x7AAB7A4D7066DC5FULL, 0x5B1FBDB0B158225EULL, 
            0xE08A805DFB586349ULL, 0x616E167CEF9C72FFULL, 0x2BDBF2E84D0BBCCBULL, 0x24DA7D6D1ED4AAAFULL, 
            0x70B31FA985685EBCULL, 0x9E16564249AFABBEULL, 0x3AEC2C3931995BE0ULL, 0x98CF5EE7BC74A129ULL, 
            0xBDF261C8B4DCF01CULL, 0x6F99A2A6B96F4FFEULL, 0xEE7616BF81D36445ULL, 0x925B3C50FB292848ULL
        },
        {
            0x2E1B5BAC524A8646ULL, 0x8A5700CAE6642185ULL, 0x1B953AFDD86CDF50ULL, 0xF84B1A9BE8052DB7ULL, 
            0x220E32756D4AE088ULL, 0xF0CD0F8459122D3EULL, 0xDD00760A809B3D74ULL, 0x8938A529F9D35503ULL, 
            0x98D9FD9F0D7E42E9ULL, 0x2124D918AFE60D8CULL, 0x57C971D3B4AD4B4BULL, 0xACDC68A2FA9FBD88ULL, 
            0xF3058DF16278C112ULL, 0x3FCB35E77AC8B0BBULL, 0xBA50AF0DEF2C7ECAULL, 0x76D9107F1108D85DULL, 
            0x850B0DD63F600EACULL, 0x2C49D389594B5542ULL, 0xF87CCAB7374B8E6FULL, 0x19CE131A74509C69ULL, 
            0x3A601F206CE475ECULL, 0x78877DB2B1B6CCF0ULL, 0x54548459157DC1C2ULL, 0xF7C7FE2B72E041BCULL, 
            0x921E48917713E369ULL, 0x6E6324225B78E41BULL, 0x778DA4E3AAD97B37ULL, 0xA2A4A03CE905628DULL, 
            0x91BC4F27F6E66F80ULL, 0x860CD0871A54C94FULL, 0xDF306184F7F8E695ULL, 0x45D27232990D2E8FULL
        },
        {
            0xE2EC9B48A9125621ULL, 0x057D537F4055A578ULL, 0x52580497814B8AF1ULL, 0x4385D7C121909330ULL, 
            0x5048E753846C8242ULL, 0xD58D36A4C2956EAFULL, 0x13D927232F965FD3ULL, 0x28AD8A77849DA5C8ULL, 
            0x69A5B32EAFA37E74ULL, 0x8E60023D5ED265CCULL, 0xE0BE14D87FCA0CD5ULL, 0xE047087280649DB2ULL, 
            0x3BE94FA1E37199C2ULL, 0x405FBFCD2147CE19ULL, 0x984EC031CC6BAF4FULL, 0x2C88FA74E68DC544ULL, 
            0x9876034C12D25F3BULL, 0xE213C8952CE3A61DULL, 0x5A017C6BADC5EB93ULL, 0x9248816376A4A1F2ULL, 
            0x77333DBEE9AF4EFAULL, 0xCF5E23AC541EEACFULL, 0xE177E52BD13E836AULL, 0xD5652B60054DA33DULL, 
            0x8D18D6A06ADA937FULL, 0xEF504367592A8BF9ULL, 0x69F85BD8CB302589ULL, 0x6E898DAB34BD64CCULL, 
            0xA52286CDA9E94B9AULL, 0x8A01B4C67A92A329ULL, 0xDB277AAD7DD891E7ULL, 0x7BF68B843C72B279ULL
        },
        {
            0x39FA7CA92CAF172FULL, 0x8980956D6BBB95A3ULL, 0x17DA3ADC56B73F2DULL, 0xCAC8B90E3031F762ULL, 
            0xBE6924B1E5546536ULL, 0xDF6F9B8133176B00ULL, 0xC5931B7E885BD047ULL, 0x8016EFB9998B9606ULL, 
            0xD43FB2941E62D7E4ULL, 0xBC9A877630FE3DCDULL, 0x99B38993B9D8619EULL, 0x3DAE87725AD0ADE5ULL, 
            0x3C3B3683C7AC50F9ULL, 0xF1DD95992E04050EULL, 0x6F92E8522D96F691ULL, 0x400C770B12D93C20ULL, 
            0x25AC143271283E85ULL, 0xBD087FFC234B15B1ULL, 0x28D367DD940FE151ULL, 0x52830DCF71F1E4ADULL, 
            0x3D1E6440B714E1F8ULL, 0x525BE4AC143FD2EBULL, 0x33107FE02099C616ULL, 0xD68A51F9B45E0FBCULL, 
            0x71D550BE93142760ULL, 0x32993D64B996757EULL, 0x1731BB01ECABA54FULL, 0xC403730D807373E5ULL, 
            0xFDECA3FB5957849BULL, 0xFBDD46697745AF83ULL, 0x724AC7FF2557DAE9ULL, 0x0EB2EE308F217185ULL
        },
        {
            0xC7196C2227E6F384ULL, 0x164F22FDE9C06E82ULL, 0x87ECAB64B3504AE5ULL, 0xF88AD1EA0445035EULL, 
            0x5E7B9C18783AE139ULL, 0xBCB9CBBF6FE07863ULL, 0xFD9BB4C42C9DAC69ULL, 0xEB14E5D5C9BEDAAEULL, 
            0x10623CE872A5FD7CULL, 0x979919B3F1397781ULL, 0xE96C1E30FB8FABB2ULL, 0xC170B32F2DEDFA97ULL, 
            0xF6FF04930E7DC604ULL, 0x2504F141555A7B0CULL, 0xA07AEB52FD93D31CULL, 0x42D3E09B8A778CA2ULL, 
            0xE81B01FA849C0448ULL, 0x916858AE4B3489F3ULL, 0x80733A8203F43E86ULL, 0x6020154236074CF8ULL, 
            0xD423D5CF2D81B44EULL, 0x0084FB9ECB8164D8ULL, 0xF628AA18BF1020F1ULL, 0x04D437E16D83018FULL, 
            0x6FDF373B28CAC472ULL, 0xF63D68D2E1D067B9ULL, 0xC89F2F0D1AB356FAULL, 0xD4B13BD30247CC06ULL, 
            0xE145A95ED3B874B9ULL, 0xD5B6E6B1BF602B34ULL, 0x67840D2DC76D2FB2ULL, 0x366CBC05DE8A02ACULL
        },
        {
            0x1448327D392F88CFULL, 0xE7955177EF9C5E12ULL, 0x393ABECE5EE73581ULL, 0xAA7C5A9D8ED11848ULL, 
            0x31EC272F3C306B45ULL, 0x4F32940694121E23ULL, 0x8ED1AA3F5E7ACF6BULL, 0x9E5281A65D530034ULL, 
            0xAB51E3B8304C111EULL, 0x8A5DC0AA8E36233AULL, 0x423E2F351B192F69ULL, 0x0838AC8C6200DAFFULL, 
            0x8326690B56A178A0ULL, 0xC795D5343FFEAA32ULL, 0x1327785DBA25E77DULL, 0x945BBA004B231E77ULL, 
            0x8927AA6A60C76B59ULL, 0xA2F6D22958A690B5ULL, 0xB11F2BB718FCAD71ULL, 0x9250DF2EBDAF8B0BULL, 
            0x8914DF94A77BB317ULL, 0xE7F45518C8E8C087ULL, 0x9D8F00E3A45F2C5AULL, 0x10EF835872644254ULL, 
            0x108F8DBA08D6C3E4ULL, 0x539B8A1E2780858AULL, 0xD970515E830D6A12ULL, 0x008016851F389CB6ULL, 
            0xE617D10EA63E2E32ULL, 0x56BF8E76A8F4748BULL, 0xBAC996533A2D9065ULL, 0xCEFBEE3941804536ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseAConstants = {
    0xEA0F139ED93BC858ULL,
    0x7A56A64B0CB23E0AULL,
    0x019A5AB42F315433ULL,
    0xEA0F139ED93BC858ULL,
    0x7A56A64B0CB23E0AULL,
    0x019A5AB42F315433ULL,
    0x3024AF9BC1417868ULL,
    0xBF6FE04599C4C51BULL,
    0x8C,
    0x9B,
    0xB5,
    0xE7,
    0xE0,
    0xEC,
    0x9B,
    0x67
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseBSalts = {
    {
        {
            0xB52C7B9F7C635064ULL, 0x910266B42B8B00B8ULL, 0xAFD70C6F0DD9DA72ULL, 0x4AF6BF0BC7D1A269ULL, 
            0x05F1964FACAFFDF7ULL, 0xAEFAF47D92227E95ULL, 0x16B2F84DF952F720ULL, 0xE6870189076ABCC8ULL, 
            0xBF3A9AEE76E66359ULL, 0x93CF233596738041ULL, 0x2350DA8777CCAD02ULL, 0xEDC7DAC5922BCA62ULL, 
            0xE024161698C6ECA5ULL, 0xC4A16058B1A04A90ULL, 0x507C7A9DFFE56FA1ULL, 0x1794C3274BE4BD1AULL, 
            0x14F6DA62B56EC3D3ULL, 0xD538D85100C12DF7ULL, 0xA4657FD2036030D6ULL, 0x144DF5E0BDD9DA1CULL, 
            0x80A8719EF1564027ULL, 0x5A444B4E467361A3ULL, 0x6BB2785D5DB61B08ULL, 0x989561A4CE251511ULL, 
            0x1646EC61ED3EB258ULL, 0x03BE05074AD07611ULL, 0x448F31B4A5D6193EULL, 0x95564F6877424946ULL, 
            0x888018ECF43CE4E3ULL, 0x9ED9D0D1E72D5932ULL, 0x30165B7C4AE0D38BULL, 0xD337396D0BA919DEULL
        },
        {
            0xCD5A367E8A5E9712ULL, 0x5F8B4DB335C9B24DULL, 0x2AA8C46131471CC6ULL, 0x75ACC9A350C5CE9EULL, 
            0x64C9612ED8976C53ULL, 0x9F29CE1BCC6328AEULL, 0xAB70DAC1BF843AD2ULL, 0x6E63812D95039A25ULL, 
            0xA43DCC5F94559FDDULL, 0xDBE4E0739D5E9394ULL, 0x57A0AA23D850E554ULL, 0xB317BA36362DBEDEULL, 
            0xFD4F5EE0CA99743FULL, 0x95CAB3A93EC83418ULL, 0x747EFB74BA3BD0DFULL, 0x043D3D3DD0F78A73ULL, 
            0xBB1B3E06CAE3117AULL, 0x4F0553EAEE9B4A3EULL, 0xAF214CF0C067B463ULL, 0x42CCFC37D75A72B1ULL, 
            0xB022F4FE0FB35E74ULL, 0x32FCA26B20EC8641ULL, 0xE769B1E27C1C8808ULL, 0x2BFD574C1FCCA3C4ULL, 
            0xDDF94F09472A540FULL, 0xA5EEE615570B014EULL, 0x1047D1BCAE3825FEULL, 0xE3490BF6F9EDF12FULL, 
            0xCCB2757377EB0184ULL, 0xF381B435CC459E02ULL, 0x07E0C07A01D51B48ULL, 0x2D93A35CBC18B0B3ULL
        },
        {
            0xE05E7889E8A32D70ULL, 0x6F21FF3EAFA6DA4DULL, 0x048497E65F671BD0ULL, 0x8F59F6C2C26AA354ULL, 
            0x8AB1BE981ACD762AULL, 0xB35214EA8827B1A0ULL, 0xCC79BFE158447676ULL, 0x97CF82BC3A7F1E8CULL, 
            0x2E88D0CBF6274522ULL, 0x9342FF84FC420F3AULL, 0x60256F1D8D519B8AULL, 0x52F3CD31E7C2998BULL, 
            0x4ACEB7643387F947ULL, 0x34C8CDAF003DD25AULL, 0x5FF528B5D91D16CEULL, 0x22ECB5798489F62CULL, 
            0x8DBEED03F7BDDB5CULL, 0x92896184D0C4BBD9ULL, 0x2D4E1D72532CF668ULL, 0xEB68A5EBDE8FC011ULL, 
            0x25DD5C8388E25F00ULL, 0xE3BDEBF5205034B5ULL, 0x01568F1436056E4FULL, 0x94851130CFEC300AULL, 
            0xD4A0FB05DE9FE4E8ULL, 0x6B1F990B21683384ULL, 0xD3105E1BBF54DCE9ULL, 0xF6ED0E3A888C20AAULL, 
            0x161718E45C632625ULL, 0xA50890FF9238F1ABULL, 0x40D94ED3CBA1E4DEULL, 0xE4A3F5F6460DF26DULL
        },
        {
            0x5F4CAE96267C91D3ULL, 0x9F52A2E6DDCC39ECULL, 0xC26D0A810280758DULL, 0xAA97892B56E2C4B0ULL, 
            0x43B5CB1F6D8D6BC4ULL, 0x56124750F7250D0DULL, 0x1F2619EF913E3A93ULL, 0x9C1F1093917A7990ULL, 
            0x3C0D37D564FDE27DULL, 0x2E1A417B173B3547ULL, 0x889E6AC58B2A6C65ULL, 0x637925CD58B112EFULL, 
            0xE7767BD603CCCC05ULL, 0x7A52A5A58C62CD2DULL, 0xB83C2873D2D6F666ULL, 0xADDE1E0ACB065C18ULL, 
            0x6D2AB849CCDAF71DULL, 0x1B8867FFF824A22AULL, 0x979C2DFB2092ADA1ULL, 0x5E4788F82F98A691ULL, 
            0x997B42C79AE7613EULL, 0xF8282A0738E77680ULL, 0x6CE4ECA07FF66B09ULL, 0x3F6ECC0A63DBB030ULL, 
            0xFBF7B1621ED28A6CULL, 0x8CDB3F64F7B436CEULL, 0xEBBDB05EF976AAB7ULL, 0xD15CEC3C50DEFFECULL, 
            0x80909DB56814CD79ULL, 0x1BD60C9AC7458B2FULL, 0x5AF95D3F1F642F8AULL, 0xEE07492F8BC97021ULL
        },
        {
            0x3C8C84B47731BDE0ULL, 0xEC246DE7B879F631ULL, 0x79F8DE8B2225D836ULL, 0x528534C8EDE0C996ULL, 
            0xF62CCC13BABD1F36ULL, 0x18B45CE289D21558ULL, 0xC29BD8AB4310974EULL, 0x70933D02424F21A3ULL, 
            0x1FAD3C83CA3FBAD1ULL, 0x54BB0E15A793CD02ULL, 0xD757D485E8E12CF2ULL, 0x19CE3C91E047D224ULL, 
            0x888511B7E6A47881ULL, 0x841EA14296C57F33ULL, 0x92F70B6709A21165ULL, 0xB4924672E8335E3EULL, 
            0xBFB1348AB3A5ED26ULL, 0x764BC9542517571CULL, 0x59219EC14C19BE7CULL, 0x3C0CE221132A888DULL, 
            0xFE4056DF854E9A2CULL, 0xD90021EAE2089043ULL, 0x532D7B5FEBCF5D26ULL, 0xB176964886F1DAF5ULL, 
            0x76A700CC2FAB85E1ULL, 0xAEC4D496840A6F8AULL, 0xBFF1819FD295E2CCULL, 0x9668E33FCB64531BULL, 
            0x7F50C4BA76C98E4CULL, 0x1BAB8386F5537A2FULL, 0xA11573504F2EC566ULL, 0xEFBD0BE0C93D388DULL
        },
        {
            0xE29773868F55866FULL, 0x3E6649AA3865E569ULL, 0xC1103853312AB545ULL, 0xF094241C14A75FC8ULL, 
            0xB4F79AEF9414E3D3ULL, 0x29B6A950B0F73C54ULL, 0x941615D6EAC04E58ULL, 0x66365EC6865212E6ULL, 
            0x5C7F5BC92FB57286ULL, 0x933CDCD0C7494CF3ULL, 0x8B96742D8343D66DULL, 0x7201D864F4D78676ULL, 
            0x8E618EE6680529E4ULL, 0x3C79870090D82277ULL, 0x75DBCBB185C46144ULL, 0xF8874AC28824D05CULL, 
            0x46471E8100F1DE9BULL, 0x7F08B6468096F8FCULL, 0x645E4C3AFF7A9E94ULL, 0x91EE3E31EA7BEFE7ULL, 
            0xE02DECED842B7F4FULL, 0xC2EE6B5348127281ULL, 0x98E2D03D29BB38A8ULL, 0x7D9B2AADD1BB5EE7ULL, 
            0xB8C2671DB2DDB183ULL, 0x7F4EF3CD2E1D9E5EULL, 0x250A58CEE1B8E814ULL, 0x155D38A07C5792B5ULL, 
            0xB25E3DA00F53914FULL, 0x7C7C8ACA02380E15ULL, 0x2D30BB446AC8D9B1ULL, 0x16BCF28BCE1351CDULL
        }
    },
    {
        {
            0x9F8F98622E941CD4ULL, 0xCF1194447E0DFEA6ULL, 0x2A1A80EBFEC46345ULL, 0xE7DC1441ABC9C97FULL, 
            0x82135F7DD0F47ABBULL, 0x9056C60C618EFAE9ULL, 0xF30C7D8D35589E8EULL, 0xC3096E56669EA4EFULL, 
            0x3ED6B1287F020854ULL, 0x9B1F6E16A740C9C7ULL, 0x1E23C081B691A300ULL, 0xDD48E5A647AD4CE8ULL, 
            0xAD3E9EA007B57BC7ULL, 0x6353A330F92AE675ULL, 0xE00410C1D2F1D2A2ULL, 0xB05B9C93EAA5B1DCULL, 
            0x0214947FA17A5E9AULL, 0x4DF3FB49B1A4BDD6ULL, 0xDD57F683DDB89E2AULL, 0x5A3EF34DF79BFF31ULL, 
            0xF9292013E77433B5ULL, 0x7B15AFE7CD80B057ULL, 0x5DE66B496FF38AEFULL, 0xE0F09132A4682E41ULL, 
            0xDAB05C034168462CULL, 0xF14A2CB7B6B99755ULL, 0x60F2E7656CC1BD6FULL, 0xA787F61109FC08DCULL, 
            0xD2703E4DE44648FAULL, 0xA7B0EA8D03843C37ULL, 0xB0DB2DEB27DCD1BCULL, 0x6F88333935A96294ULL
        },
        {
            0x4A60A92F8E62A0B2ULL, 0x118DC7C9FF8B2A16ULL, 0x257004DB59635EB3ULL, 0x39B4D8D7CB47F061ULL, 
            0xA37811CA093F3976ULL, 0x2FBA873FC01CB36FULL, 0xA30D2DF1000EB4A2ULL, 0x697EBA915478CF97ULL, 
            0x6D993682E8AAA6CEULL, 0xA5A467C39BB24A4EULL, 0x0AD486470E8FAB55ULL, 0x5DAB0D96A7FEB5C7ULL, 
            0xAA8E4BEF247F5A1FULL, 0x8EAFB6FF2FF77DC9ULL, 0x785FAA14413AB4B8ULL, 0xE206265FC9533B92ULL, 
            0x83FEADFF6C3E34B1ULL, 0x1345A26AB363A21BULL, 0x82C83191655365C4ULL, 0x9221B95968BBF32AULL, 
            0x0F203753D000314DULL, 0x2257AEFC193472BAULL, 0xEFC066DB968061D5ULL, 0xBBECA6A2716192D3ULL, 
            0x9B79278440565995ULL, 0x5C736114838F2D4AULL, 0xB0291E0243D6DDB7ULL, 0x76650A5ACA539913ULL, 
            0x992F4CAFA9146CDCULL, 0xA185A72DA241D43CULL, 0x7AD2997875C6D213ULL, 0x98306CD6FBFF193FULL
        },
        {
            0xC514193D84D0E42FULL, 0x472D3C52C1FB9BF5ULL, 0x9ED7ABBD58D1B4A7ULL, 0x538E6BBFD7F18DCEULL, 
            0xCD57E7DBCD5B745EULL, 0xFEB95C29B29F0802ULL, 0x6873522B41F9B74AULL, 0xEE059111ECB206C5ULL, 
            0xB1A6E24558E4263DULL, 0x768A04A6EEAF56A2ULL, 0x1FC1961FBDA49205ULL, 0x5244C1C38E92661DULL, 
            0x2100E41BC5AFDA7DULL, 0x11EDB58CBF9722DDULL, 0xE7C4BECA68093168ULL, 0x48901EF2FED84354ULL, 
            0xBB2431E2FD491513ULL, 0x48C63C7BF7318E41ULL, 0xBC9F1B7412ECB073ULL, 0x09AD1B5C3B5616F3ULL, 
            0xB103330275A03FA8ULL, 0x2A3B89AAA36EB7C8ULL, 0x77D71199FCAE73CCULL, 0xDFFFC35A50F98E37ULL, 
            0x154557ED849CC145ULL, 0x4F5E312F8EB62A95ULL, 0x8E3D9BB1D93A40E6ULL, 0x5AEFC397C12A6C27ULL, 
            0x7EB1F709CC1EDA7FULL, 0x1AE66E039A7718FCULL, 0x4106D1AA4961056AULL, 0x7B748E93C4DE35F2ULL
        },
        {
            0x0731BFC85D6B41DFULL, 0x5E990DAB1656692FULL, 0xA44E4EC5EA8DBE03ULL, 0x4C3005595A97CD0EULL, 
            0x8CF7957E89F83ADFULL, 0x67DE97D449946F29ULL, 0xAD43177EFC3D79B9ULL, 0xE5D83F2B1E397DB7ULL, 
            0x1D175BE5EC6EB609ULL, 0x5EAA7D1059E553B9ULL, 0x595744915C60BC0CULL, 0x1B3ED5DD4DBBBA25ULL, 
            0xFA5401DBA68D7B8BULL, 0xDB9BF377D1626AB5ULL, 0x755B1E71F63CF380ULL, 0x62D2AFDEC6276710ULL, 
            0xD5732C7F1E9069A7ULL, 0x7B902B91ECFC24DBULL, 0x7A3D1AE5D78BE7DCULL, 0x4A80E5F88530F713ULL, 
            0x53A1166621B47DB2ULL, 0x665F25009614103DULL, 0x16AB86B26D4D49ADULL, 0x12538A723F1BE514ULL, 
            0x7115A3352E0A55BDULL, 0xDF8BA6F30F84377EULL, 0x3996F6E01AAA6F4CULL, 0x9F79A38CDD87BDD3ULL, 
            0x9BEBF417EBA30D23ULL, 0xBBFBD947D0176C6DULL, 0x20E116168F5ED37CULL, 0xE9BDAD8935A25B0EULL
        },
        {
            0xB90960CDC9A2908EULL, 0xFD63CC7FE9A6430FULL, 0x1964C61C65529DD2ULL, 0xB07020A9AA014AEEULL, 
            0x6FF46040F5782861ULL, 0xCFF295AF7BCE0476ULL, 0x7F935544477688DCULL, 0x0338127613280EBDULL, 
            0xD01FB399AB3D017EULL, 0x6BBE728638AAEC13ULL, 0x1391B13BE0BD9191ULL, 0xE96231EC6641EA3AULL, 
            0xD55092C59CD16160ULL, 0x458D445C454EB7B3ULL, 0x1A5AA6791E22276FULL, 0xE06DC495DBB26317ULL, 
            0xE9EF166BA786900BULL, 0x4B22A1F98AF9EB24ULL, 0x6B102194778B1ED0ULL, 0xE34951858CFC43AFULL, 
            0x32A16299B8D46B91ULL, 0x552AD4A926912303ULL, 0x0752D2229D7F2125ULL, 0xA5719730DAB5825EULL, 
            0x6ABC96FCB4F9CAF4ULL, 0xA13D091BD914FA7FULL, 0x02511FEE45E3E4CEULL, 0x3510DABF04C0B224ULL, 
            0xAB3ACA8BE12E2DCBULL, 0xBD102AAC87A94755ULL, 0xAB4C29FEA8FCAF3BULL, 0xEB1F3C382B591817ULL
        },
        {
            0x9C3C9234E50757CFULL, 0x4DDF0FD73D51D9DEULL, 0x32269E4A399D2205ULL, 0x0ECDE3211FC28B02ULL, 
            0x73635EED2B261E6FULL, 0xF78636AF2DEA0D68ULL, 0x3BFABCC22C5F4718ULL, 0xCD1292386765A6F4ULL, 
            0xF284DBCA23075BF9ULL, 0x8AAA54D0C4F15CB1ULL, 0xF23C9B22BE9C9648ULL, 0x0EF80010AEF27DD2ULL, 
            0xAD509E87E831A770ULL, 0xBD90325A61EC01AFULL, 0x51DB1150E561FA8BULL, 0x90D8CE7E64DB20ABULL, 
            0x063AA9C31EAE403EULL, 0x1A65B70AF302734DULL, 0x575427F46BF375F0ULL, 0x0F7C18B47817900EULL, 
            0x612884E1CA92D7A2ULL, 0x2C9DE587FA5EB9E6ULL, 0xF6EB004ED940134BULL, 0x84039E2586978705ULL, 
            0x34CFD92F6A985D30ULL, 0x04A464D32B184CFDULL, 0x94EE64087C19AF6FULL, 0x4A29EB51EEC4D20FULL, 
            0x53158D8A78E2A9B1ULL, 0x8BAECA306FE23236ULL, 0x46C14BC2FEAE670FULL, 0xB93439737A2E4239ULL
        }
    },
    {
        {
            0x583FFE0C3CDD7E6EULL, 0x1CCE6072A8860311ULL, 0x0F152EC24289D7DCULL, 0x11669C95D520343EULL, 
            0xAC3FD72912EABD88ULL, 0x83E3825CDBD24805ULL, 0x85718A87C06E79A8ULL, 0x0C31C80BD442990CULL, 
            0xD23BB2BADB059D11ULL, 0x2544B40F1691C296ULL, 0x06902C07B365789AULL, 0x04D1FA65D1596886ULL, 
            0x1494DB8175566856ULL, 0x34D7AF945A3BF092ULL, 0x5B6D3324244F9CC6ULL, 0xA1781EFDF3A3A4ADULL, 
            0x485C7E85507621E2ULL, 0x05026AF5EFC800A4ULL, 0x333B33EF070B94A5ULL, 0x492D1BA985FA6F55ULL, 
            0x45BEFF580A3AB9F6ULL, 0xF07BE3EBB8F7A16AULL, 0x3A84595FC6648ACFULL, 0x44A7626B22020EB8ULL, 
            0x9E301CF8AAFB967DULL, 0x53A1B4FA48A3E3F5ULL, 0xC5A14C63323BE0C2ULL, 0x8D773EAA6540D71AULL, 
            0x7B371E15F609565FULL, 0xF95DC4B66D335E65ULL, 0xE2A9F8D48C19A6DCULL, 0xBA365F41B05AFB5EULL
        },
        {
            0xAD52B9F99EE83725ULL, 0xE62535EE4050FC90ULL, 0xE1F4A800844C0790ULL, 0xF7FEDC5997B02630ULL, 
            0xCA3DA4EDB4E415F0ULL, 0x29C68FEF57B45B29ULL, 0x385EBFAA86E64749ULL, 0xDEEC53EC902F1416ULL, 
            0x9A669BB8C31F119BULL, 0x24AFD8BB21FA38EFULL, 0x45C86C809AF013B3ULL, 0x990A9778CCF83838ULL, 
            0x8B3A947C8C39705FULL, 0x0351D3048744E8B8ULL, 0x199AD213B0D7242AULL, 0x9BFF4CB56421D4F9ULL, 
            0x2B9C429FBB5C99D3ULL, 0x4D1E96A7A13278AFULL, 0xD2D4A8B39A3DBC0FULL, 0xFC40DCF97A2F46BAULL, 
            0xB130E93C7791ACE8ULL, 0xA21FDBB2684A38D3ULL, 0xA798AEFA3A036F6BULL, 0xEB0292503A2CCBD1ULL, 
            0x553B5FBE429EB2BBULL, 0x78EDB8E2791C6E07ULL, 0x62E196DFF34F968EULL, 0xBC79BA4E0294EF84ULL, 
            0xA58CBFF5E284FD18ULL, 0x36ED87E41EDE57D6ULL, 0xAB0E70E5904907C2ULL, 0xB048E293F2947C8FULL
        },
        {
            0xA7C1F2313FD24C42ULL, 0x7BDC4FCFE9A87567ULL, 0x6E1071759774DD37ULL, 0xFB5BB0866B7C12AFULL, 
            0xAC3623CC84313E51ULL, 0x9A7F14FABF33CB9AULL, 0xCEBA160AE022F602ULL, 0xC90E048FE679FC7EULL, 
            0x6179E77A81F2F0A3ULL, 0x8D2283B65F6381E2ULL, 0xD953BCD136683468ULL, 0xF77B1C313F179658ULL, 
            0xE19E149142E10706ULL, 0x718B63F52CD0CBB9ULL, 0x343416A0C36586CDULL, 0x125B6745F4E98DF5ULL, 
            0x82FB0CBDC655ED5FULL, 0x2E9CF89117D7DCE4ULL, 0xF124BCA62113DA4CULL, 0xFA129867FADF982DULL, 
            0xBE3DB05AE617DC7AULL, 0x6A84D3FA9447B651ULL, 0x1A4F739465518F72ULL, 0x8EBEE816D8195F83ULL, 
            0xB00B6050EC90469CULL, 0x636BE64521ACDA42ULL, 0xE77ADB090F594AE3ULL, 0x668C75D66FB05447ULL, 
            0x175B807A47C786AAULL, 0x272E4314B80C52C6ULL, 0xE6550008F81323D2ULL, 0xF207CD5D5C60323BULL
        },
        {
            0xB2B39C1B95AF8C26ULL, 0x4211BAB7ADCEC93CULL, 0x3F4206A3F114B1C2ULL, 0x5525F793888D886BULL, 
            0xD4DB4812B3D9778CULL, 0x6D99EFB9B23D0154ULL, 0x9FE49BFF6930B21EULL, 0x36F6352613CEB3BCULL, 
            0xE7D4876017B8B369ULL, 0xCAC4C06CF7C33B01ULL, 0xE9289ABF91B5B37DULL, 0x4D45EAAB6776025CULL, 
            0xF0EF9DB14EB573E7ULL, 0x323B673ED1DDFE2CULL, 0x74918109ACBD2CA1ULL, 0x77BC129BD790E3B9ULL, 
            0x59BC2EAD2DA2ECF7ULL, 0x782923E8A5DC5891ULL, 0x5C1AA6254BE8ACE3ULL, 0x7B2B2FF86658A80EULL, 
            0x979B3557DA1F5890ULL, 0xA18233239EBFBE05ULL, 0x3D86476D754C92BDULL, 0x90C0D749C62079CEULL, 
            0x3A423B6569F637EEULL, 0xB3114612B4172F36ULL, 0xB7BAA10B6DFB5335ULL, 0xE14964A31CE270E4ULL, 
            0x411881B4A9E4E417ULL, 0x6356507246FA4817ULL, 0x78181178E4E7978FULL, 0xBC20A72ADD208BC8ULL
        },
        {
            0xD943444406A5474FULL, 0x3873265B3A663DADULL, 0x07B6EB31ACDA1A5BULL, 0x13FF311AF2AB56A1ULL, 
            0x7636FB188A204F89ULL, 0x6944B47731DFA310ULL, 0xC9CBA1D8E46A98D0ULL, 0x6073A0F0044FCF04ULL, 
            0x8EA983D91FD07B37ULL, 0x7FD5464980F6AE4AULL, 0x660BF9708EAA7C1CULL, 0x417F6BD43754A0C4ULL, 
            0xC41543D135FB3BD7ULL, 0x4EAAF7829C81E4ADULL, 0xE5AE7F2FA9A04B74ULL, 0x0516EE599866EC7BULL, 
            0x51FF3C1F9CAA16F9ULL, 0xBB9A88A0E19277F6ULL, 0x97E783AFDDA9F48AULL, 0xC0999E55D95B0A69ULL, 
            0x6CAE2A88A3DE3715ULL, 0xF547FC8D71C7E154ULL, 0xAB6F1A0D884DEF60ULL, 0xF113D983F7DCF35FULL, 
            0x3489EE0712BF4D10ULL, 0x71C8ED16CC403C4DULL, 0x3000596AE6CEF621ULL, 0xC5BC4EFC72B4131CULL, 
            0x4AD80F7A61085D9FULL, 0x9234176878B40430ULL, 0xB3916DA863BEF056ULL, 0x3E96CAC5275900CBULL
        },
        {
            0x6161B2F27FE35596ULL, 0x4182E266FA27900DULL, 0xB9BD731074DE9208ULL, 0xB2B87E834E1DF586ULL, 
            0x2E6FA31FE6C401F2ULL, 0x6F7D39A180646652ULL, 0x35540540DAF9FB2AULL, 0x6CB22E323E4D5E6EULL, 
            0x71CACD1A66EF3C0AULL, 0xA6A97ED784FE68BAULL, 0x69BC9CE10B519993ULL, 0x9643B52E8BE65F5EULL, 
            0x9F0527FE38F8B598ULL, 0xDFC6746F619A8EFCULL, 0xA12DDD6F8643690DULL, 0xE9F5204D64E38333ULL, 
            0x96F79C222CAE1C15ULL, 0x0F4535CB94EF6AA1ULL, 0x92F5BDDB6B6583D0ULL, 0x71EC9C3EBF93B39DULL, 
            0x17A7A5139B8D5E04ULL, 0x81F92E6213CA838EULL, 0xC756A950B1D6D381ULL, 0x45D8078A69B62230ULL, 
            0x6847DE591FD1E31FULL, 0x554A022D6DF48E58ULL, 0x99BCE04E4EAF114EULL, 0xBA2AE46B3C71720FULL, 
            0x047FDC45DF9AAC47ULL, 0xF7894CE8D7B3E8BAULL, 0xA1C6709988CF2653ULL, 0x6D3B4136338FA093ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseBConstants = {
    0xB9E450E4B410A4EBULL,
    0xD5F4988C1EBC5F28ULL,
    0xF82CD29D8B38ABDEULL,
    0xB9E450E4B410A4EBULL,
    0xD5F4988C1EBC5F28ULL,
    0xF82CD29D8B38ABDEULL,
    0xFF95C68FA1A1CBCFULL,
    0xCFD771A1761A538DULL,
    0xD0,
    0x50,
    0x42,
    0x92,
    0x19,
    0x8C,
    0x37,
    0x1B
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseCSalts = {
    {
        {
            0xFBC3AFE082CF2378ULL, 0xFFB8F2CD6F834C3DULL, 0xB82732EE4B715D78ULL, 0x494175594B926C1EULL, 
            0x575977FDCA4AAC93ULL, 0x8C9D81E37B26EF0CULL, 0x365F0710625E51F4ULL, 0xF58CF2DC98516ECDULL, 
            0x02860E744D0E5338ULL, 0x9FAFC2FEB80A51C2ULL, 0x51D964DD4C807388ULL, 0xC741B94B7F3AFD80ULL, 
            0x26D26E4A48127FFBULL, 0x8165D60DB0AA9E47ULL, 0x824ADAC39DEAEE14ULL, 0x0C503E9780B2DE09ULL, 
            0xC83EA04DDF067E68ULL, 0xC6E29679DBBD6A7BULL, 0x71147D69A3C26539ULL, 0x65F4F532E702096CULL, 
            0x36B028750ED3657DULL, 0xFBF6D90F8517D057ULL, 0x68936603FA99C129ULL, 0xC88FF7E96B3713C3ULL, 
            0xF353ED43818DFAE3ULL, 0xC3B402BF5E2BA953ULL, 0x51EDBCB8312E6E99ULL, 0x68D6507FD55FF143ULL, 
            0x01117B55684F7F33ULL, 0x3DDBC3CC82EA4773ULL, 0xEBE9D71766C71829ULL, 0x354668B3EDE6EB36ULL
        },
        {
            0x2857C65CDDDFA15DULL, 0xE862750C8C1571E7ULL, 0xF39B04BFF5B8BD5AULL, 0x6A271B8A36DE6A1CULL, 
            0xFEBA410358AF10F1ULL, 0x31720629D8F52FD8ULL, 0xF746604E2789CDA7ULL, 0x9843053A105C8569ULL, 
            0xB0B898F0F6298148ULL, 0x43AF5AC817AB8A59ULL, 0x9E681F527CCC02E3ULL, 0xA2E13B7B23BCBCD1ULL, 
            0xAFC9555598956276ULL, 0x664737F33A951F1BULL, 0x1F24B46C6BBF8871ULL, 0x7D5AA7ECC05293D6ULL, 
            0xB8153E8012FC6C6DULL, 0x739B185A1831B674ULL, 0xCCA9375570317F15ULL, 0xD2241D270C435196ULL, 
            0x28FB921C9DFC6493ULL, 0x8DFA3CC24EB63994ULL, 0xA319809D6D8A3399ULL, 0x3105F6BAF8571DAFULL, 
            0xCA2286D49B5893A6ULL, 0xA9E697CA68CEBF70ULL, 0xE7DBF56EA69E87EAULL, 0x22DDDBBA4781A606ULL, 
            0x0EE44B6B92108C73ULL, 0x1E7E13EAFE2683AEULL, 0x5539B4560E7570E9ULL, 0x831C299752FA398FULL
        },
        {
            0x3E562A8C70459F7AULL, 0x3D8DC0348B4FB0EFULL, 0xA41B59AB6962E6EEULL, 0xC527BA281BEB2A77ULL, 
            0x9AFCE0E498C39294ULL, 0x951FF52800DD7D55ULL, 0xB8B11027EEC99EFBULL, 0x41AC1D58320BCFF0ULL, 
            0xFB5033409E5C4CAAULL, 0xCD67E085DCD0D384ULL, 0x0135364CCD730BB3ULL, 0x41577C03788C3EDBULL, 
            0x1BE588321E63FEB9ULL, 0xF767BC6F32F38318ULL, 0xCBC9AF26A37DBE5EULL, 0x5A19259BB5242C4EULL, 
            0x53B9892F2BDCEA76ULL, 0xCA8E3FA943B24D74ULL, 0xB9AB3F6B4CAB8718ULL, 0xA05F9F0CF3C01F9CULL, 
            0x9005DDD5A33B510DULL, 0xDD4D20FC3816F231ULL, 0xF4FC5243936F294BULL, 0xE25EF4221D14C214ULL, 
            0xA4BB2C9C05781E0AULL, 0x609C2FDDEC560262ULL, 0x50EFD3CFAC9D7201ULL, 0x94309FAA40853807ULL, 
            0xD5434CAD8D127E1AULL, 0x62367B8C75EAE3D2ULL, 0xC152C2E8415A5F3BULL, 0x24D2C6D035B2296DULL
        },
        {
            0x5841D4DD798C80C8ULL, 0xB5B19498D837FCB6ULL, 0x091E74910FEF81CEULL, 0x51340522C027DE9BULL, 
            0x6EF1059EC4C339DEULL, 0x2377CC04E00A9B82ULL, 0xB09FE0471B438985ULL, 0x8ABF102034EA5CEBULL, 
            0x3371B5498EC9D3B4ULL, 0xFEF32B8DE121B196ULL, 0x89AAAFF4CF57817CULL, 0x116A3C67FAB3EB5DULL, 
            0x9295EBA42D35A9F3ULL, 0x633C12B5426090E9ULL, 0x9F5CE970FD2EA2B1ULL, 0xF7A778B0EC05F135ULL, 
            0x18C111B348BFA3A3ULL, 0xA8F81314D374E413ULL, 0x0CA75DBB59D3EA74ULL, 0x0EB12CBB7973C54EULL, 
            0x5C1B0914C0DDD942ULL, 0x9EAB3A3EF414F9FBULL, 0xB542C87E422195C8ULL, 0xF8E5FD436DB13321ULL, 
            0xB6BB5DAA57CDB9DBULL, 0x713BE822814E8E22ULL, 0x1C3FE07FB0F603BCULL, 0x921D50CED8BAA934ULL, 
            0xD729B5CFD7D17026ULL, 0xDE30619970F3EBC3ULL, 0x3C66B5CAF70A4E70ULL, 0xE2FC326FC7CD8418ULL
        },
        {
            0x741447F80F330069ULL, 0x873786A7D2CA5BA5ULL, 0x01A08AC0D7E1E92BULL, 0xCC7BC40D836A9E91ULL, 
            0x41CB3C1AB3F6B697ULL, 0x4F828166462C5D94ULL, 0x917E1B588FEC6310ULL, 0x17207C7FE84F4EFCULL, 
            0x596515E187321758ULL, 0x4DA7242444FF4D1BULL, 0x2DC5EF8A5F18A0D9ULL, 0x7A1ACDCF3270CAC1ULL, 
            0x6113018E05E52185ULL, 0x01F0F8821091A788ULL, 0xF346ACB063A80950ULL, 0x85D71553AA39B6EFULL, 
            0x6E7F94D6EB6B54D8ULL, 0x67A3E6687601C81DULL, 0x2E9772BEB16A41F4ULL, 0xF48525A76961D24EULL, 
            0x27BE91462EEF55B6ULL, 0x151060E1D5CDB3ECULL, 0xB489434FFD1846C6ULL, 0xD4C328AB81275016ULL, 
            0x4685B5A24E536EB9ULL, 0xD90CF793C5CC19E1ULL, 0x76742E6B46371AD0ULL, 0x780C20F505E08BD1ULL, 
            0x22D93D0217C948AFULL, 0x78B76486EDBC8EC3ULL, 0x7011E91EA4C959A9ULL, 0x00BCF8E5A7C9B182ULL
        },
        {
            0xB33E2DE3FC53A337ULL, 0x5AB8490EC3A18040ULL, 0xD7041A3281555319ULL, 0xA6957C2FD60F95D9ULL, 
            0x5CAF726669D0EB09ULL, 0xD26AB558A86C7FA7ULL, 0xB4068D3E77BA7F40ULL, 0x2341B1AF75F32BF1ULL, 
            0x6A5561E15B955BFAULL, 0xFA0FF4837CE0828FULL, 0x364553F1B4137BFFULL, 0x864B05C3C3846770ULL, 
            0x283CEACD1F72BFC4ULL, 0xEA252301D99A7038ULL, 0x6CAF24A5F8FFB455ULL, 0xE66AE311752D257BULL, 
            0xF64656C19DFBDBB8ULL, 0xD15B88D4C3E221C1ULL, 0x1EF82D46FF7D9C14ULL, 0x56D9CE414B59CE1FULL, 
            0x323FD79679ACE311ULL, 0xB93DE52280A1D36CULL, 0x96BFD5B8DE1BF55BULL, 0x53F7AD4C8F36D02DULL, 
            0xA7AEE9787C7BB3E4ULL, 0x39CC16D03D0C3C06ULL, 0x52A7BFC3AE2906F6ULL, 0x040256116186A0D1ULL, 
            0xD2B875C6612488A2ULL, 0x0AFBEF27F696C315ULL, 0xFC81816BCC1F32FAULL, 0xC7193FC9D5ACFCA6ULL
        }
    },
    {
        {
            0x4C2FA3FE73F802E4ULL, 0x02FCB6732BB2A96BULL, 0x861166CD60DC5D7FULL, 0x387DB9BD42C08D58ULL, 
            0x6DE9D779B9CEE604ULL, 0x71AD59C2A389D394ULL, 0x7557726F27DD7DC1ULL, 0x95A75FF6A929A45DULL, 
            0x795F96A8276036A5ULL, 0x3CF06466D4B11123ULL, 0x84F634B611081753ULL, 0x89FF093E8EDF304DULL, 
            0x9C25333BC7A71F13ULL, 0x68FF635BA6038F1DULL, 0x453973B32A7AB730ULL, 0x9E0CA060F1DAA415ULL, 
            0x4118102D8BCE173AULL, 0x89CDF9E66BF8CA68ULL, 0xC09617B29C2D01DCULL, 0x3B4DC18AA897C2B0ULL, 
            0x9ACF94B2D7DB87DFULL, 0xF7E630B12DC1325BULL, 0xF79B145623620CA3ULL, 0x5A17AEC24BEAB7CCULL, 
            0x14D111CAC79819AAULL, 0xA784EC3381C5894EULL, 0xC03C10E5510CCBDFULL, 0x3855D5E2AE8AF82FULL, 
            0x8D69FF7A4DFB7DDEULL, 0xABC35CB502AA9B93ULL, 0xDC1B42C686FBDF69ULL, 0x9129B4E040914349ULL
        },
        {
            0xAA9AD2E3354391FEULL, 0x4F18D43390BB8434ULL, 0x856C05EA6C4D35CFULL, 0x0579E4699819C93DULL, 
            0x76A45D9B945BEFB3ULL, 0x175FF7D8A3387C69ULL, 0x497B6560D54EB140ULL, 0x65643AD941107B87ULL, 
            0x3F2766AB9D4DF56CULL, 0xC108FEDE9BC61BD3ULL, 0x91289E65EED3DB2FULL, 0xEE526CB4FDB6DAA5ULL, 
            0x59DF1B133E53F09DULL, 0xAA697EB7AAFC251EULL, 0xF8D2E63CA6480C4CULL, 0x0E380F36AD39E5D1ULL, 
            0x98AF0D29B1B0A683ULL, 0xA35B430DE5219055ULL, 0x07CDC5A0D62ADD48ULL, 0x54CD0F797E42CED8ULL, 
            0xA341D2D6632B1732ULL, 0x89B95550D1DD6523ULL, 0x8D9EDAF4326F2E39ULL, 0x70B3BC4325C49C33ULL, 
            0x678B70D9B9E918CAULL, 0x07C220F6C11A88ABULL, 0x9DDBA21AD03EE2A7ULL, 0x84D0E6389CD0CE83ULL, 
            0x12164F1864BD4ACFULL, 0x791E5B87D56F5F88ULL, 0xC94396CC20406989ULL, 0x62EDE442B6ACAD5AULL
        },
        {
            0x5D443A29FC609E35ULL, 0xB6DBD0898DC4910CULL, 0x75498BEE16DA2128ULL, 0xA05EE140660AA203ULL, 
            0xBA8C3EB5DA6E6BBEULL, 0x656D2F747389DF56ULL, 0x2502F1A964E4A063ULL, 0x8C85CF7B91FEFE43ULL, 
            0xCA14A35A024664D7ULL, 0x9DD0538D379830E4ULL, 0xAD41A2A37CBD36E0ULL, 0x0164D23E1F2FCE25ULL, 
            0x3DA6832E83F201BBULL, 0x7C687BAFA04B8C25ULL, 0xD495AE098610CAB0ULL, 0x618E6444123086D4ULL, 
            0x1C6AF75B7AAF211EULL, 0x8ADE5FE2D8A0DD8DULL, 0xA64537810BC582F2ULL, 0xB7EC6BAED49F7D47ULL, 
            0x908A4DEAB367E24EULL, 0xA9B8C9C21B1675B0ULL, 0xB1810C480F8C882BULL, 0x3DE0805693E70B61ULL, 
            0x585C0B98688EDE6CULL, 0xCF309C6A00EACB05ULL, 0x8C1959C67DAE30F7ULL, 0x6D2E5A7F50D0CBFBULL, 
            0x78BA627E92B65AAFULL, 0x5C5C77900F07F6C9ULL, 0x53CC09217AF3D85AULL, 0x53F6D2BA5F5F37A6ULL
        },
        {
            0x455CB0D854D06976ULL, 0x49B7FF3A20E5475EULL, 0x4964C4217F7A082BULL, 0x8960EC664C1DA76CULL, 
            0x34BB1C66CD2E1FDCULL, 0x9B9A4E3D2301F5A2ULL, 0x5BBF4D0938097588ULL, 0xBFB582D044E74203ULL, 
            0x546BCBF62891C3F9ULL, 0xD70CFBB4C217914BULL, 0x49925B0E70440FC9ULL, 0x9155847990ED6F4BULL, 
            0x53FE60A121CF3E5AULL, 0xEA2776C919384B24ULL, 0x8208B95D69AF982FULL, 0xF47D7C32797D4AC9ULL, 
            0x83B1C7D6D9291548ULL, 0x2BA708080639DB7EULL, 0xA2B79D7F7FCA9718ULL, 0x81E164B4236F26E5ULL, 
            0xC7DEB7D1D27A4476ULL, 0x11B71767E6F2DE65ULL, 0xAE24387669DEABB5ULL, 0xA976E8CB05CC36FAULL, 
            0x6A1200BC7ED56917ULL, 0x8CF71CE0A57E1E3CULL, 0xA92E19C690AFEA4CULL, 0x82241542CAE532BCULL, 
            0x2FE572FF9AF08A2FULL, 0x109A9954E11DAA79ULL, 0x018D624174C36C6AULL, 0xA675460E3D252CCDULL
        },
        {
            0x6B209E2E07D049E3ULL, 0xD40996167847B3FFULL, 0xC7EEA6DB35ED3BF1ULL, 0x9BED8CBF58F7122EULL, 
            0xC44A411A27BAE31DULL, 0x284BAFFAD8A2DE1CULL, 0xD54240157740B168ULL, 0xF5569A3F1DDEF682ULL, 
            0x9D1C1566A8D58854ULL, 0xC3537E44B7253F06ULL, 0xD970E72926D5E25DULL, 0x50368F740C15A57BULL, 
            0x0F1656EE664B5424ULL, 0x55F8413BEC254E64ULL, 0x9585E79C21B30750ULL, 0x02CE6E699FAC20E1ULL, 
            0xD87D55A97FB684F8ULL, 0x7C938BD96FAD12B9ULL, 0xCDF06975EAE359D2ULL, 0x1FA27BF390830C43ULL, 
            0xE5F5A4639B2380F7ULL, 0x9F912FE41A80A011ULL, 0xF6E7516DB46DE7B9ULL, 0x9D87C62F0096D83BULL, 
            0x438D07E6936BACBFULL, 0x198A083087B3EF5AULL, 0xDA65F20A3CB6E588ULL, 0x83A830400F56BCE7ULL, 
            0x30B2D4DAFD82FDA4ULL, 0x047684319839D9B2ULL, 0x8D2F62D4F5CA7A37ULL, 0xD312E5774012D124ULL
        },
        {
            0xAD9A97B68B1CC8A4ULL, 0xD8B13BBC3F5DE6DEULL, 0x6FBBEF9792F92797ULL, 0x4389CDF7A5D571CEULL, 
            0x29C560076776A438ULL, 0x10D78E7DC2F80CA2ULL, 0x39BB72887F31EB7CULL, 0x5C76719D5FF534A0ULL, 
            0x57B9D1D02675E0A9ULL, 0xC7CCA6709129B0BAULL, 0x9C0D4427A038A7B7ULL, 0xA5836117FEC10ED1ULL, 
            0xC7D016EEE219AA49ULL, 0x1552B0483A4649E2ULL, 0x1E46B7BFA7EE9F85ULL, 0x93BE0E23802744D3ULL, 
            0xAB36CEAF7B55684EULL, 0x9A8006307C8F4C79ULL, 0xC40E328D60A98D6CULL, 0x51DA2806AFF2D9DEULL, 
            0x2B5B5A881B009310ULL, 0x5F5FECA962BAAC2EULL, 0x455CCD081677CAD5ULL, 0xF68A5912F212E507ULL, 
            0x8488A78E269A4085ULL, 0xCBF5CA688D4411FBULL, 0xFEB658A80B16BEC9ULL, 0x86CAE7482EF53404ULL, 
            0xB17064DE0BF52991ULL, 0x05A7D14F8AB918CDULL, 0x959C57C206C49386ULL, 0x8C8388A88CA122F0ULL
        }
    },
    {
        {
            0xFD1A691A176D76B5ULL, 0x118748492E34E02DULL, 0x9FD83172E3957FB2ULL, 0x8274FF5E680BCDD2ULL, 
            0x06C1DCE852DAE845ULL, 0xD64C38FE13BD1997ULL, 0xEE479C861EAEE6A3ULL, 0x3935210E48D90110ULL, 
            0x7EFC9186C08672D7ULL, 0x62C76595B293BB5DULL, 0x39813E21F9C305ABULL, 0x8783280EFE7A0C7DULL, 
            0x1DACFC5B4F3D8839ULL, 0xE5DB6755CFDF02D1ULL, 0x7B30467AFE784B20ULL, 0xE1FA5FED812227E6ULL, 
            0xE21C4C3CD6CC1C08ULL, 0xE2A2445B808C378AULL, 0x4BF62F28E50D50C6ULL, 0xD4C004B57F8EE70DULL, 
            0xF9323F1943FDCDBCULL, 0x2B4DB36BA018775AULL, 0x3BF0AD78D2296652ULL, 0x1F0FDF3B907368B5ULL, 
            0x9C674B4A0EB0F554ULL, 0xA5FE9951E02A4E5BULL, 0x25C0630D8C5FC8A3ULL, 0x5C49EC695757993CULL, 
            0xE223D91BFF68334BULL, 0x4898846215B4A3B2ULL, 0xB167826DE32DDB4AULL, 0x08A8D8A38FF26906ULL
        },
        {
            0x233B573C2BD4E9A2ULL, 0x69B2DE6E85DDE310ULL, 0x14DB6EB1C7C06CFBULL, 0x09866DD700F0600DULL, 
            0x342F8E00C2AC918EULL, 0x0D802207D50028F9ULL, 0x6C9CA5F147737E8CULL, 0x2AE894E45F4F86ECULL, 
            0x1DF4762A3E48830DULL, 0x0ECAC0FDBE7DC726ULL, 0xCDBB7D612AE4AF10ULL, 0xD261B38ABF20521DULL, 
            0x513BE051D52AD0DCULL, 0x1AA21676A30E18A5ULL, 0xFC49BC3FF96AF207ULL, 0x42DB953F030BAC73ULL, 
            0x568A9DA7C7202E5BULL, 0x92A4B9F79449E076ULL, 0x712194E83A7EC248ULL, 0xEB2DE45EE7E563A2ULL, 
            0xE98140DC845F3A34ULL, 0xCFB3FC2DF92FC939ULL, 0x0B552FEEBB1C5913ULL, 0x1963756BBCB2FDB7ULL, 
            0xD2AC1FB3438DB27DULL, 0x48CF59A1C71F4727ULL, 0x13C90A67B646979AULL, 0x5D98CABEC2372AE6ULL, 
            0x6AB9F802E7A8751DULL, 0xE7EF3832877129F5ULL, 0x5B555080CAE1546CULL, 0x1F1A113E2682FAA6ULL
        },
        {
            0x907965197E31FE05ULL, 0x82B46B8406EC04E0ULL, 0xE967DFC3E9144B29ULL, 0xC49BF81E249CB4D6ULL, 
            0x7FF5BEAF25D66AC5ULL, 0x2A17B93F7FB7F95BULL, 0xA3C8DE54E110065AULL, 0xEA73646B1D83A57EULL, 
            0x3E4FD8548B68B3ACULL, 0x452EC47089C95242ULL, 0x671FB923DB87505BULL, 0x03E3F97C779941ECULL, 
            0x29ED8CF889D42467ULL, 0x5F67FEBAFEC418CAULL, 0xC3F8E107145C2777ULL, 0x29448D05E8EDAE3FULL, 
            0x45940FF569BBCB64ULL, 0x5E90A8353B88B0F8ULL, 0x0B85F40C31860C73ULL, 0x3962404300C7D09BULL, 
            0xC390B991C82E4FAAULL, 0xF0005D07DB979B0EULL, 0x7A1AECE4437AD660ULL, 0x4EA74D162DA36ABDULL, 
            0x99521A56386C5B84ULL, 0x2117FDAE2159D124ULL, 0xAC49C50D565F7333ULL, 0xC83EEA9644B8AB81ULL, 
            0xEEA49DC46D7C9712ULL, 0x061F45EAB5EA0457ULL, 0x8A234794EA7DF48AULL, 0x53F2220F335DAB94ULL
        },
        {
            0x722FA93AADFF8BE3ULL, 0x6847ECE97EA23FBDULL, 0x0B3B820F5D9564C5ULL, 0x4B916E197582F049ULL, 
            0xDE0B4805A1588988ULL, 0x7BA7FDBBE65159B6ULL, 0x36C2ADCCEE4C3B1AULL, 0x3BBA08AD8796E3C1ULL, 
            0x91E0D5F2F5409ACCULL, 0xD5E6A85EAAFF87CBULL, 0xF162C1868650E8E2ULL, 0xB0D467962C11850DULL, 
            0xCB0A638B97F4E52EULL, 0x1DEA286656100F60ULL, 0xCFEE23E242F7CFF9ULL, 0x15B06CE6FB39098DULL, 
            0x55E313104E0D8A70ULL, 0x5152AF2168EFEE55ULL, 0xF30C301BB643FD9AULL, 0x52757BDA0E4D63C8ULL, 
            0xA3D4EDE15343B53BULL, 0x576CD9D318FE6D5BULL, 0xDB8924CC7A90B434ULL, 0x9D0C6E6DC9CE3B90ULL, 
            0x0E60BE32F67C25B0ULL, 0x61395BF090A12CDAULL, 0xCB3CD6A3964FB343ULL, 0xFF4DF5055BC1A2CFULL, 
            0xD2EE968A844BF9D9ULL, 0xE04F59C497FC48FAULL, 0xA9B9B0189DF779B3ULL, 0xAD4250DD67ACBCDDULL
        },
        {
            0x834C81C4EE1EBD75ULL, 0x6C5F0DDE72B884E2ULL, 0xC7F68B86A18C0400ULL, 0x2B73A21E81CACE56ULL, 
            0x898AF325AF33E9B8ULL, 0xF1D9ACC62749E956ULL, 0x8A1FA9CD1F416155ULL, 0x216EB7AECC183EFBULL, 
            0xC1765DB8A0028B4DULL, 0x1B82A3AECF22B0F3ULL, 0xB8C7701E045A2648ULL, 0x515BEA537F97AFEBULL, 
            0xADB39DD343DF1712ULL, 0x0EFB8D8BBC8BAF4FULL, 0x06BA6469EDB16F16ULL, 0x25C472C8D18B3719ULL, 
            0x168F17060E25160CULL, 0x77776B67BED7C59AULL, 0x35A4433C38D4A251ULL, 0x34B90F8A24A7ECDBULL, 
            0x159B58DE4785379AULL, 0xACFFCBD45FFB9E4BULL, 0xB9DBF07E5E2775EAULL, 0x5D650E77BF75B01CULL, 
            0x9C960C21C03DCD6FULL, 0xD5916D34CA6894A0ULL, 0x33BF40A4EA24B8D7ULL, 0x4D08A4F2DB07B7FAULL, 
            0x46171FE87F513A26ULL, 0x0A7D56B4100E9CD9ULL, 0xB924555E612B2F63ULL, 0xF3D50609E0EFC7A6ULL
        },
        {
            0xC4E11915E2938937ULL, 0x9720D2DAFCB2D885ULL, 0x2851F92E0FCB94B8ULL, 0x39E2DE3AE43CF8FDULL, 
            0xE6D5DA23ED8634DFULL, 0x7CD862AAFFC72222ULL, 0x4E361F37DF5BBCF5ULL, 0xB0E95F6FEC595823ULL, 
            0x8D2AA9339F75B0EAULL, 0x84B0CF503CADAF88ULL, 0x961BCF98C76CAF98ULL, 0x08E5DA449EF0F10CULL, 
            0x4B456A1BA290E603ULL, 0x004C7699D4655E78ULL, 0x0CF8584C08621058ULL, 0x949F0ADFA2997AC7ULL, 
            0xA710C023390B04EBULL, 0x2776BC0174B8CC18ULL, 0x50F1AE0B69B0895DULL, 0x0E352B140D9073A4ULL, 
            0x3F34EB6B86CB8364ULL, 0x08CCD5C2DFD7F871ULL, 0x4F58D49ABA2CB9F1ULL, 0xDE19A54842725AF8ULL, 
            0x6DEA2EB225290411ULL, 0xA1D890D40B558EB6ULL, 0x015975F9D23E013DULL, 0x43BBFF0DF8F60400ULL, 
            0x254FB4A74228CBC0ULL, 0x9C455D34AD508B88ULL, 0x193B57AA67532036ULL, 0xC7E5046AF7989729ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseCConstants = {
    0x06086820CD92A09CULL,
    0x74C32513F9E877D9ULL,
    0xE764D26322D390C7ULL,
    0x06086820CD92A09CULL,
    0x74C32513F9E877D9ULL,
    0xE764D26322D390C7ULL,
    0x0094245B863D19C2ULL,
    0xEE5DDB32FCE1A166ULL,
    0x63,
    0xE9,
    0x6D,
    0x6A,
    0xEE,
    0x3D,
    0xBF,
    0xB3
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseDSalts = {
    {
        {
            0x82E070B45DBADF7BULL, 0x47C7CFEEC47AD536ULL, 0xA15D6208FF5922E1ULL, 0x6F57E18A6FC2D563ULL, 
            0xAAB5FB5F9050B78FULL, 0xC40471AF61E9AE38ULL, 0x4AD544B6EEE4BB0DULL, 0xCEF65473CEA7FC4EULL, 
            0x669024AF34792B35ULL, 0x257C0F97C3FD5131ULL, 0x7B8A9B66FB435284ULL, 0x327A9FED4244D86DULL, 
            0xC68AC1C9B95F2BDAULL, 0x63135028E64E2F0AULL, 0xC2AF6609974CD327ULL, 0xE22838473466EDC1ULL, 
            0xDE40440BCA7A0A4BULL, 0x5AF29907520D1151ULL, 0xFC2D699D85329BB7ULL, 0x8BAEEC04A906C0E0ULL, 
            0xD96DC26869B5402AULL, 0x254C480502C52F8FULL, 0x5B290A86CEE338B6ULL, 0x3D0D313C5D6760A0ULL, 
            0xBB23EF7AE922A1CFULL, 0x5928FDC0CEC54F8DULL, 0x7A4876150963EFFAULL, 0x41B220CB0F8E4514ULL, 
            0xD964FEA7F4C73A77ULL, 0x182310C9C132A467ULL, 0x9D7A67F8E017C9B4ULL, 0x8830A89DAFFD2023ULL
        },
        {
            0xD80627996F7719D1ULL, 0xD8B41C9F7EADD91AULL, 0x26FBE511B5B9860FULL, 0xB36010FEC8303453ULL, 
            0xEB0726195D53DB16ULL, 0xE37BCCA59CFB4AEBULL, 0x1A8919C13596D0B6ULL, 0x758FFFCF9AAADBF9ULL, 
            0x86D2336B8A08BB22ULL, 0x813DD6E1ACA56115ULL, 0x40B4C1D0FE65477BULL, 0xAB983DDEE1FE98E7ULL, 
            0x75FF867A47E15AE5ULL, 0xB49A3FEEFCD4DF5DULL, 0xB979D8E0A14B2223ULL, 0x4D8A65CEBC9E17BBULL, 
            0x581C8386E07B889FULL, 0xFCAE552A0A0230EDULL, 0x06E378442379EBD0ULL, 0x515D83B01B3748A8ULL, 
            0xC236AE1A99C4F224ULL, 0xEFF2B8F41DD54E59ULL, 0xE1A1DE8922A3D033ULL, 0x3053B45D8DD7253CULL, 
            0x53337DF439BBE951ULL, 0x15463A5744D122CCULL, 0x332E1350C1239749ULL, 0x5E4F4A1C1CAFC355ULL, 
            0x3ADCB0952975B20AULL, 0x823A06CBC4F6DF21ULL, 0x8A412EE750B5942AULL, 0xC4F76D859446AE69ULL
        },
        {
            0x905D6F1E3227C124ULL, 0xCAE76CB339E6B32AULL, 0x5E360B7340DBAF6DULL, 0x4DD6055D62A93859ULL, 
            0x57AAED0927B477C0ULL, 0x32FD012159BBDC69ULL, 0x4A8AA36C5C34CB36ULL, 0x46C230D1C821C999ULL, 
            0x32A927D91215AA35ULL, 0xD06E70BEC1792651ULL, 0x0A0076740AFD2122ULL, 0x94B7B15912E878B5ULL, 
            0xF3ADFDF69B07FB2DULL, 0x03F58CA50972B1BAULL, 0xFF1F378D9AF86B4AULL, 0x1F9C2BFA51D94AFFULL, 
            0xCAE7BC3678CD48AFULL, 0xDE942DF32EAD0BEDULL, 0xC6359FAB2F5615B1ULL, 0x0CACD6651C9FC11BULL, 
            0x1B4A60F83AF27DA3ULL, 0xE48EFF87A484C7F2ULL, 0x3B3D1FF2BA7FE3B7ULL, 0x764B277786BE1843ULL, 
            0x991D19EEE8B43EF4ULL, 0x184E07AAC761F8E3ULL, 0x8877DB13DA21C226ULL, 0xE84BC2AB95AD90D2ULL, 
            0x5332116545B67DBEULL, 0x38F3910F51D426BCULL, 0x2ABA8254A5A4FC7BULL, 0xC2002E8C3FECAB51ULL
        },
        {
            0xF8F182D665AA29E6ULL, 0x83246A3087125EF6ULL, 0x8B4399A6CF4197C5ULL, 0x4468B27F39D157BEULL, 
            0x5F6FCB280516E47DULL, 0x78DAD241CED5C74CULL, 0x74B160001D2A2875ULL, 0xFEC6385021CE046EULL, 
            0x14F1CCF6CC1B8983ULL, 0x6A1E0C5A8F6CFDEDULL, 0xB833D863EF95AB8EULL, 0xF3611B0038439D91ULL, 
            0x78D1576B28E1F8FEULL, 0x64FB70BBB145A4A0ULL, 0x2A9D79AAC75B6244ULL, 0x522B3CB29AE8A41EULL, 
            0x637DA50CA614952EULL, 0x6984DF95FABEAB7FULL, 0xDB3D3A59081C33D6ULL, 0xC515C2EA1F8B7AA4ULL, 
            0x5845358A9640B059ULL, 0x757775404805D52AULL, 0xDEFF642D77CBF30EULL, 0x51BE7B9E05DB72CDULL, 
            0x51AFBCC33C18BF4FULL, 0x925EBFC8B8062DFAULL, 0xA82A07F8D1855ADFULL, 0xE168C96244D5BEAEULL, 
            0x774D371E0344D544ULL, 0xB64EA18F01555619ULL, 0x1E3BF9656E264571ULL, 0x008E7D99BC2E001FULL
        },
        {
            0x9840AFCA103BB6AFULL, 0x18F619F16AE8CFC2ULL, 0x7CCBAE5C32A803ACULL, 0x8F3114555A08D164ULL, 
            0x814C5E137AEF20EDULL, 0x02318B1C2AAD5C9EULL, 0x23AD3D9246CB65FFULL, 0x224A9B8AE6F37050ULL, 
            0x6365B6239129F9F5ULL, 0xB0A384C7ECC752B4ULL, 0x6B4631CAD76CA660ULL, 0xFDCD4D4CB06D7DB5ULL, 
            0x41DE0E1D80415D5EULL, 0xC8EA40793F0B2456ULL, 0xD6B1732F4A7DB04FULL, 0xA185CDF96E725AA0ULL, 
            0xE898E2E8F9384D7CULL, 0x7372E93FE885865CULL, 0xDEBA97F54FF1831EULL, 0x7A42533C29B3BD46ULL, 
            0x4E54D6B32F2A349AULL, 0x6784F606656AAAD8ULL, 0x4121DA61B73EBBCAULL, 0x2126FEF36C306951ULL, 
            0xA03FADE850233079ULL, 0x9C80A1B0006AF4B0ULL, 0xEAB84649DA0D3375ULL, 0xB74470182452F4FDULL, 
            0x18E27774F992C85DULL, 0x5D0D1FC0B40B5FD7ULL, 0x2E6C8217AB61A5F5ULL, 0xFEEC1A1EC20FA411ULL
        },
        {
            0xAC0BDEF28274B488ULL, 0x7745E5DACC78ABDDULL, 0xA0E030CB56E56757ULL, 0x9B750C6E5EADD9E6ULL, 
            0x97AD276801F9B00EULL, 0x560335BDA94D0303ULL, 0x8F9044218F590BB6ULL, 0xBE338C11CE08C9A9ULL, 
            0x65ED04A76F6289CCULL, 0xF285E0F51F9F6154ULL, 0x8C0E0984DFAC4420ULL, 0xA4247B5570A299CFULL, 
            0x204D8C7AB4C0AB83ULL, 0x8517085014D4DEF4ULL, 0xFBE6263527A94CC3ULL, 0x6A5815A06A8C9234ULL, 
            0xE528ECF267303310ULL, 0x801413DC329B7705ULL, 0x4ABC1FBF8191E603ULL, 0xB4FD84877498A500ULL, 
            0xF42AF6D22B92D976ULL, 0x48D97C3A4E01351DULL, 0x17EC749DD1E757E9ULL, 0xE399C9E190A7E7C2ULL, 
            0x7F901DD1B263D8C0ULL, 0x66D4660452E38A0EULL, 0x76F715DCE75ACC0DULL, 0xC8D563DF911C07C4ULL, 
            0xD7F3EBC21875FECDULL, 0xF3269D85C895EF26ULL, 0x99CB894C780C41EFULL, 0x1C32A21794E38453ULL
        }
    },
    {
        {
            0xD0E1356119BCC7A4ULL, 0xC7827E500D6E1885ULL, 0x48DE5498F2F695A7ULL, 0xC0EB16BE4396EA7DULL, 
            0xE3DAA2D12F0C43CBULL, 0xA086E8F125B4266FULL, 0xE00ABDD5D86ADAA2ULL, 0xCA23640A3C4DBB3EULL, 
            0x5D918591635A6E53ULL, 0x5B22D8AE481F8D46ULL, 0x0E305A3E0D48D7A2ULL, 0xE2DCF7AD93B4B2C3ULL, 
            0x7A802A39B903B093ULL, 0x443911E6EA768A8BULL, 0x9406FC769C9BF229ULL, 0x8DCA4779653602C6ULL, 
            0xDEDBC07DC9A73CF8ULL, 0xBA82C0960C1F9A7CULL, 0xB780518C82AF81A5ULL, 0xB781CFFD10310071ULL, 
            0xABD007E2E9F8D3E0ULL, 0xF4134D90A944DA20ULL, 0x4BCA29A048F45DB4ULL, 0x3EF346CA9E170DD1ULL, 
            0x94A3426AA7BAAE3FULL, 0xA1073736ACEC1D82ULL, 0x2C316044361B4EA7ULL, 0x993724A9F74B91EFULL, 
            0x7782E54B855EF71AULL, 0xDAEED6A1B391F6B7ULL, 0x86BE2E0E42DFFF05ULL, 0x87DD9962035E5692ULL
        },
        {
            0x4137A3B528D8415CULL, 0x0B8A308401D87AAAULL, 0x6F799AABE4AADC63ULL, 0x80DAAA3DC122B6F3ULL, 
            0xC1708CD942F7E51AULL, 0x15C30FD505313701ULL, 0x1154D7F42BAAF1F2ULL, 0x9D7A2F512B623244ULL, 
            0xA6458D471C071CCDULL, 0x0C89E325107DE387ULL, 0x413A27AE76477064ULL, 0x58970692B7652357ULL, 
            0x07676C2F54816F10ULL, 0x3597438876CAF940ULL, 0x94E808959BD669B9ULL, 0xD864CE2543276B1EULL, 
            0xD50FA584FCF5DD84ULL, 0x9336E3EE04EA9BB0ULL, 0x17529F23B15037BFULL, 0x854C3B29C48107D5ULL, 
            0xD5E3F2E1A385299AULL, 0x74D936F174346112ULL, 0x5FA6C9EB6720F80DULL, 0x720E043FF2B66F06ULL, 
            0xD4C2234071521818ULL, 0xABFF564FFEB7044FULL, 0x98DCF730F5A17773ULL, 0x9423320E6FA58E6CULL, 
            0x522F53E3FDEA1CE6ULL, 0x202A8A7B5A607626ULL, 0xE4C07098013D507FULL, 0x19E4187E5B56836FULL
        },
        {
            0x1A04C3095F5AE7F0ULL, 0x1367C2BD6FE1232EULL, 0x8A7D55E58CBBE8F6ULL, 0xC81FDE26D50DEAB8ULL, 
            0xE84822D81F3E8F03ULL, 0x7527D22637ABCB68ULL, 0x530D41C8B9A5C9F8ULL, 0x067FB3B532BC06D2ULL, 
            0xD61C381036B0E058ULL, 0x0E9A1CCC8C6A95CCULL, 0x29B8726F3F2C22B8ULL, 0xB2B72F35D6374C85ULL, 
            0xC7CA08D687CBB3E1ULL, 0xB5115C6C4D977569ULL, 0x487A6871F4C8EE2EULL, 0xF4F18BADBEA5DB6CULL, 
            0x921E85896E438999ULL, 0x973E8C582267C206ULL, 0xEE2D437F2C094A0BULL, 0x848A70D576353FCAULL, 
            0xD547314DF1A5A2B2ULL, 0xF15D10588AAB6FFEULL, 0xB78A131300B67CB0ULL, 0x9BC43A8DEB7EB9C6ULL, 
            0x7A46D647076E7828ULL, 0x0D5D100067F0834DULL, 0xCC3ED9B9754A27E3ULL, 0x1E7FBE46D5570A74ULL, 
            0x8325B51F3E3EAF48ULL, 0x0C1E9453B2102ECCULL, 0x921A8EE199C0A682ULL, 0x473279644F79B643ULL
        },
        {
            0x2BDDF688EBA167C9ULL, 0x99AB9E2B9E63ACA3ULL, 0x7B4D7B140506C82BULL, 0x20CC3603766732D2ULL, 
            0x35F1FD4DE84E6334ULL, 0xF0216BE1AEF70A93ULL, 0xFD4D7E01C0449478ULL, 0x03D7EBDCBD067FB7ULL, 
            0x20EBE7685CC14C1CULL, 0x70E1FFA2FB376225ULL, 0xC2CB30B51C465A1DULL, 0x4A1E89AE69688339ULL, 
            0xE05C9F2802D9236FULL, 0x45E65179140DAA99ULL, 0xF9DECE086411B9D3ULL, 0x1ACF2B217CFFFB9AULL, 
            0x77E372A4578F0670ULL, 0x20513597BC99F828ULL, 0x90407DC4A088C163ULL, 0x5B2604E19DF38712ULL, 
            0xDD3A631BDF7061DEULL, 0x8619D2955717E85AULL, 0x6BC009195F49DDEAULL, 0xA84F65BE9AB46B86ULL, 
            0xC65B4F306BE63627ULL, 0x55F892FCCAAD30D9ULL, 0x362986C1AC7CFBEAULL, 0x12656FFCD773CC80ULL, 
            0x6BE4A9EB5F9D8848ULL, 0xBB2822C07C7C5C8AULL, 0x687680CF36030C54ULL, 0x84732A20B200B11EULL
        },
        {
            0xE6C54600C32C047AULL, 0x28E1E58CE1764CA8ULL, 0xBC7054CCD4D384FAULL, 0xCA5B468BC8686251ULL, 
            0xCA36A9FA082BC188ULL, 0x1BD1FF6B018314EAULL, 0xAD2957C247AB578FULL, 0x4052DC01A160B741ULL, 
            0x8B7DF780B3B1A526ULL, 0xD66650416BD6C812ULL, 0x13F180F86CB14598ULL, 0x2F95B4DB8298A144ULL, 
            0xF36E18EF1A6074C7ULL, 0x651A5077BE5FDB6FULL, 0x7251FAEB25C63501ULL, 0xF5D67091A0084124ULL, 
            0xC885D232EFF36BC5ULL, 0xC67E3D9E09D3C604ULL, 0xCBD154817F1D63E1ULL, 0x73F7A9195C461B62ULL, 
            0xB05EAAEFF68EF45FULL, 0x7BE5FD716842EA6CULL, 0x18CA6EE57748EBC1ULL, 0x3EC3667197F3C634ULL, 
            0x689B12D9874AAEBBULL, 0xB948273D945BD911ULL, 0x897A600CE8B4B625ULL, 0x3B66053837799585ULL, 
            0xF89301875D527DBEULL, 0x9FA8B619937C71DCULL, 0x3019DB034B461B75ULL, 0x0375FBD0DBA87343ULL
        },
        {
            0xE05AC808B5BBEF87ULL, 0x8ADD7FB12041CE74ULL, 0x331A74AAB111E1DCULL, 0xB23ADBC72E8D362EULL, 
            0x27BFF4A0E1CA0B5FULL, 0xED3CA8D788E69467ULL, 0x039B05C8DA7D6A57ULL, 0xA13ADDB13FCB1F0EULL, 
            0x7B8B576052D20753ULL, 0x2FD37D924D1CD02EULL, 0x5C3040AC8B835119ULL, 0x5E11F01BDAF654C9ULL, 
            0x29EAB5B3BD2A5323ULL, 0x170398365A0E6FC0ULL, 0xC36F3583F7472CD0ULL, 0x25A2A9906AD774B8ULL, 
            0xD2C8B896B677C6ACULL, 0xDFAFB8F9FB78D9C9ULL, 0xB5255FD2FF0477F2ULL, 0x44CF8AE60A777D89ULL, 
            0xA853E026BD30D33DULL, 0x5128781020BF5372ULL, 0x523D554522B907F5ULL, 0xFD7F1C6886ED2B42ULL, 
            0x9FDC3399D39D8ECDULL, 0xCC2D827F88ED455DULL, 0xE4B60B06AA7FCDF5ULL, 0x0CE77A101F76E4B3ULL, 
            0xFD695D37A3B0B81FULL, 0xEDC5AA36F8699661ULL, 0x4F73517920C6FC13ULL, 0x8E36C8AA3F7C96C5ULL
        }
    },
    {
        {
            0xA3A0EE839417FAD7ULL, 0x5CA2BE820DF21C6DULL, 0x9A85A7E2832686D6ULL, 0x9FB3C5B8D1429E72ULL, 
            0x40E43BA5093A1C50ULL, 0x17C2A88F41559C0DULL, 0x7A3F00E0CC18482DULL, 0xD96E30D304982E90ULL, 
            0xB4A73914B9A31FF8ULL, 0x0C57DEC40BF57FEFULL, 0xDBC3F66DB838A6C1ULL, 0x3A250EAADD264B53ULL, 
            0x85BFF68FD04055A8ULL, 0xA96C6957B85B0FA5ULL, 0xFCF5CD4BFC91C916ULL, 0x39F775356DDF82ECULL, 
            0xB7ADFDBCF197047CULL, 0x116608BF739537ABULL, 0x0D70FD557D460332ULL, 0x8A210C93810E2C60ULL, 
            0x3E0648B873D9149CULL, 0x0AA3BFAD1342E4C1ULL, 0xB7B1F1EC17F2954EULL, 0xF93EE603DB06FF6DULL, 
            0x7F9AAFBD64F23019ULL, 0xFE42A12331F96E0CULL, 0x8428A2C9659975B3ULL, 0x9EA0451FDC276AFAULL, 
            0x6042F0657E41C908ULL, 0x2FD30E291B96260AULL, 0xA992FECDDD24E13FULL, 0xE7A3E13052FF1E04ULL
        },
        {
            0x247FD11CCE5612C1ULL, 0xA7CE825D3A148C96ULL, 0x09C37DBD59C5501CULL, 0x33A3833F5B1FE64CULL, 
            0x6B5D416E04A2D734ULL, 0x400B9188DAE6C2FDULL, 0xDDFF4918D9A743AEULL, 0x18F9BFC4C22AA610ULL, 
            0xB397E7CB74AC56F0ULL, 0xD225DB55E115BD59ULL, 0x4DDA469006C84107ULL, 0x200084B0E4020391ULL, 
            0x35FA9628F567B637ULL, 0x75FEB020E1D82630ULL, 0xE78F0DF00169B441ULL, 0x97A7C62FCFA85462ULL, 
            0xDCB46D58450CCEE3ULL, 0x85594D6490B5BEDDULL, 0xE12D108A255C427EULL, 0xAAA8FEF3DEC3F389ULL, 
            0xA42C155168BBD26FULL, 0xBCABF92C9E821954ULL, 0xB9EADB697766811DULL, 0x45F229D921113AAAULL, 
            0x665D0B7BA0D0A433ULL, 0xFAC378E7E78A81B2ULL, 0xBB62D586B5F7C426ULL, 0xD4E139F16D4F5473ULL, 
            0x6BA8007A12D1EE4FULL, 0x88247FF7722BC02DULL, 0x5FBEE34DB8720A83ULL, 0xDC37F5BB943C8D1EULL
        },
        {
            0x19504B32DF6EB50AULL, 0x9B21BD42807589A3ULL, 0x7CCFA96250BDE2B9ULL, 0xD37FEC7710E679C8ULL, 
            0x2D7DF596F6257090ULL, 0x4CD5C18A59637630ULL, 0xAC35398E2B08981FULL, 0xAC1E6E678EB71E7AULL, 
            0xD2147BDCC3D00F32ULL, 0xF68C4B85AD5DC303ULL, 0x299BFFF63A112CF8ULL, 0xF262CC5D766C5156ULL, 
            0x29D4A997FB11448DULL, 0x402330B7ACFEDEA8ULL, 0x1E605ABE06A50601ULL, 0x1E1387B2C7F4118FULL, 
            0xA3FEB382DFC9EAF6ULL, 0x08A5577191129BFFULL, 0x34F7F0EAFDD99A49ULL, 0xC3B37F2BAFB804E8ULL, 
            0x83A1CFC1CEF11D32ULL, 0x21042EDA35BF91BAULL, 0x499EF5143C8C5862ULL, 0x5796710290DC7A2DULL, 
            0xA52D54ECDA59E4E3ULL, 0x32379871821806E5ULL, 0xECC5AA5C838FA091ULL, 0x290155C2FA58435AULL, 
            0xDB2FCB6EDDBCA5B7ULL, 0xC5E12B5252F4700FULL, 0x9BF4A609C67BF365ULL, 0xC1123B6BAE6CC3B7ULL
        },
        {
            0x3AA64B6115D5B3BEULL, 0x7DA9F46F358B26A0ULL, 0x678ABAF4BD616969ULL, 0x12533C7F922E0E0AULL, 
            0x3BD1CB584CA99833ULL, 0x3CDD35108609FBB9ULL, 0xCDA0BFC5EC737A2DULL, 0xB18894D61347061AULL, 
            0x66C1A7CD71014A4BULL, 0x468C066C9C7850A1ULL, 0xCE95F2C9F4DAEA23ULL, 0xDAB3EB6BFC1224FEULL, 
            0xFF8109641642EDD7ULL, 0x1C9CF215D1D48288ULL, 0xCD15F9F48A1441BCULL, 0xDB670C5860686121ULL, 
            0xCE788286E107BA89ULL, 0x352D70A949AA1797ULL, 0x0BC9D3C7B124C063ULL, 0xEAB70BAE71CB0A57ULL, 
            0x3F2EE6295F268904ULL, 0x70BB943B36C4FB41ULL, 0xC685A707EA53B763ULL, 0x7715E6C49A9AD692ULL, 
            0x383641BE2DEB8001ULL, 0x4A268C68F6C44D14ULL, 0x77884F277EAB41D8ULL, 0x873124B59061EB86ULL, 
            0x0E9F72A55CC53C58ULL, 0xA7D111283D2DF80AULL, 0xA2D838E15BE6426BULL, 0x2126DC3CB117423BULL
        },
        {
            0x614F826C18AB043DULL, 0x3276F1E9C8982147ULL, 0x448BA0BEFB669D68ULL, 0xE5621F1455AB0C9BULL, 
            0x728F91BB4DF8563AULL, 0xD0204EC24FE557A5ULL, 0x8539685F164E0695ULL, 0xE1A7B5C1C1A712D2ULL, 
            0x744E7DA5383ECFC6ULL, 0xCD2759CB591CC89BULL, 0xBFC91DDC29EE04CDULL, 0x257050B4E1455AD4ULL, 
            0x8002F1E5BCE1B54CULL, 0x19664B34D293960DULL, 0xABA267EC62FD254BULL, 0x8D98D2EB481D5886ULL, 
            0xBA47F8F449507AEFULL, 0xE260E773103ACFEDULL, 0x64CF274C7A1BCA80ULL, 0x8D49CEF9A686340DULL, 
            0x3E3B029F6904B63AULL, 0xEA3CF60D149DF18CULL, 0xDF2F34BAAA2FACACULL, 0x29A1566312A447B5ULL, 
            0xA0CDC811AB33BF9BULL, 0x0EFE1B58469359AEULL, 0x0C582953AF5BFAEBULL, 0xAF809F42C8580F75ULL, 
            0xA41906962D3C94B6ULL, 0xDD4EAF2765F00752ULL, 0x4EFF28CCD5A6E292ULL, 0xD61D52321FCD7196ULL
        },
        {
            0x6D4C660A9716A960ULL, 0x8D36C7937B5256A6ULL, 0x8242693F1B96353DULL, 0x884FE9F390CED86AULL, 
            0x9D89751054458E55ULL, 0x13599BB303A0E61DULL, 0x57162E49BD9F198DULL, 0x38707C5565308684ULL, 
            0x659FB683F16D3F0FULL, 0x37F62D909857532BULL, 0x7EEBC1153309170CULL, 0x16574EFD16ACD765ULL, 
            0x3993A8E5790902EAULL, 0x51AE31E45DADFFCBULL, 0xF23950348430717AULL, 0xD2B91168F2ACF060ULL, 
            0x76BB6D71A1AF2B8DULL, 0xA5BDCC340AC2B61AULL, 0xFB4F392676C7B889ULL, 0xA1D8C642CA610FFBULL, 
            0xCB5F2AD5883728A6ULL, 0x779586736428B894ULL, 0xBB0EA23DB92F1935ULL, 0xD693AF98C1E33128ULL, 
            0x12B50D27B69793ECULL, 0x2AEAA439ADA2D706ULL, 0x1FE1A57D4C7D2630ULL, 0x5656DF8E330F5070ULL, 
            0x5996213A7E61C26BULL, 0x3669EF92F54C8CEEULL, 0x152A3A88CBB0ABC3ULL, 0x4D07B6B0CA1DDB36ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseDConstants = {
    0xD097A61189EEFACFULL,
    0x2BF5A4B642EF33A6ULL,
    0x3FF8AB6325012C0EULL,
    0xD097A61189EEFACFULL,
    0x2BF5A4B642EF33A6ULL,
    0x3FF8AB6325012C0EULL,
    0xE937649891511BAFULL,
    0x1D431E98BE09776DULL,
    0xCD,
    0x5C,
    0x83,
    0xB0,
    0xF6,
    0x33,
    0xAF,
    0x03
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseESalts = {
    {
        {
            0xE95D0F94A8E7A4CCULL, 0x074EB3B410A2736DULL, 0xF91E9D9790FB8118ULL, 0xD73A1667DEC624DCULL, 
            0x11EFF8537854F16EULL, 0x31D5BA3033AEC563ULL, 0xACCF0ECC5BF9A751ULL, 0xD245DCB3DDA6E0A0ULL, 
            0x9139A33AE405DDB0ULL, 0xA65AC69CEF30B033ULL, 0x16D5B942E6931EA7ULL, 0xDB646DB9952D39ABULL, 
            0xB0CAFB9C96D25232ULL, 0x6199EB5A1392ECB6ULL, 0xA15A4A462EF676D9ULL, 0xDACF3EBF066B9C79ULL, 
            0x27F10EDCD3EA6EFAULL, 0x9CD179EA8C8F6F91ULL, 0x0814030D70FAF65DULL, 0x5C14A1C5D86B7381ULL, 
            0x4165A7C89FBECD3BULL, 0xA7A36DDC151D4724ULL, 0xF4987A9DE6E00FC5ULL, 0xA44B175A4D3ED3CEULL, 
            0xACB2FFB44E5A43A7ULL, 0xEABE25A986164C79ULL, 0x762CB0AE576BC2E2ULL, 0x0E4F7E3F87C28389ULL, 
            0x14BD4E8B01DD6196ULL, 0x77F28FD9E7C0AB00ULL, 0x44D4B46331770DA0ULL, 0x760DD06D48D7EECAULL
        },
        {
            0xD373F299D2565229ULL, 0xCCA30FDF04DD9569ULL, 0xC917A2001C6B0451ULL, 0xF92D0F5F5535FB59ULL, 
            0xD3CC06ED3A489C58ULL, 0xFA2C00F3CFEE9FD2ULL, 0x6A6289B8D0244074ULL, 0x52FE6A00EE961534ULL, 
            0xEEDDB528F855BBCEULL, 0xDFE0ABD3D086DD81ULL, 0x67419035931D25C0ULL, 0x12C3BC4B2F052370ULL, 
            0x940A39214EB336E4ULL, 0x0F8CB1843B7A7786ULL, 0xB4227ABBA0C4F0B9ULL, 0x139BD1D1EA655285ULL, 
            0xA0AC35FD05E506A7ULL, 0x9D525FA0D549F33CULL, 0xE6D1BD0DD1889B09ULL, 0x683FABDAF6E41793ULL, 
            0xBE644002C75FA6E3ULL, 0xFE6655827F089B2DULL, 0x0795C1C48B8CE9ACULL, 0x8AFF8E413838B390ULL, 
            0xDC58D4F2D053B825ULL, 0x95CF555BC461A1F3ULL, 0x75C4338AA76F3A10ULL, 0xD8569B149871F520ULL, 
            0x79CF2C6E2BF47D4DULL, 0xB7C7516C96CFEB36ULL, 0xF474965EFF161BDDULL, 0xDAE4788AC8E1C2A7ULL
        },
        {
            0x268E3B7D83C16E84ULL, 0xDC97EFEEBA5E15A5ULL, 0x5B75C058E9A0B208ULL, 0x0197B9EE89E9932CULL, 
            0x290E103F43148B4AULL, 0x778CD40B1A84219FULL, 0xAD7FEF999C7458B5ULL, 0x45393FC74AFEF8CBULL, 
            0x49C9518D8C74996BULL, 0x63B0879C22837D97ULL, 0x462109E86754B34EULL, 0x4034D5EC4FB5ED07ULL, 
            0x178305079FCA5DBFULL, 0x4208BBA792D36EABULL, 0xD77C56E4C3FDB808ULL, 0x769182D4108424D5ULL, 
            0x6F8E07E32ABC3AA8ULL, 0x7CFEA4B8137BC8F8ULL, 0xFC97523B748087C0ULL, 0xD5F56E5A243A6EFFULL, 
            0x9E509A0495B413DDULL, 0xC696270E3EBFB850ULL, 0x395065693A41BC42ULL, 0x0ED2E26D62FD11E2ULL, 
            0x3B91D8E5BFE43A61ULL, 0x6D3A7271D37C8CBBULL, 0x7ADBB26D6F639F9CULL, 0x908A3FBB1701B26EULL, 
            0x7F6F92A1B4785D92ULL, 0xF94D28233D25C686ULL, 0x2D7C27DC2709C588ULL, 0x66D369758E94992BULL
        },
        {
            0xA2D166AC0C540C4CULL, 0xC4E17F8AF9269C6EULL, 0x31B60E460CED9BD9ULL, 0x896BB93805D81A3AULL, 
            0xF95B51BD595C6206ULL, 0x3342D9D02767E084ULL, 0x568ED8E2E0CEB400ULL, 0x6CF84962CD4B73B5ULL, 
            0x8EA0A8541B9EDFCDULL, 0xAE1AA2F08A32A6ECULL, 0xCBC3FF31A2839F52ULL, 0xF2826191A1698680ULL, 
            0xB937AE8456BD93C8ULL, 0xB369B52A3E69C1A7ULL, 0xA18C9E0CE61BB68AULL, 0x6DE7BAD730AB30D1ULL, 
            0xC3D46446E7A77D54ULL, 0x80646E5B1AF21B74ULL, 0xE5AD84944771E6A4ULL, 0x4735554B513DFCF9ULL, 
            0x8F6469122253F9E8ULL, 0xFFEFF65FDB49A842ULL, 0x43AA07BE0589D933ULL, 0x749AD3A07E57FAABULL, 
            0xE7D63AED458A255AULL, 0x7AC5CFF1EBC4E3A9ULL, 0x5707D9B8F7AE0419ULL, 0x457C6795B340B3EFULL, 
            0xE86AC9DCB6F236DEULL, 0x28A71E4EE3CDBBE5ULL, 0xB25D3755909E6900ULL, 0x75B89FDE40F404F7ULL
        },
        {
            0xE1CC1873B55B927DULL, 0x13BA6B4DFDD5E3F2ULL, 0xE069FD5AB0C2F902ULL, 0x14E4582E40E4CD96ULL, 
            0x6D3865284F6FA9FEULL, 0xB991A4924951AD64ULL, 0x4CA880CD9384C56AULL, 0x1FD0A0D7AAD21D88ULL, 
            0x1D06010ABBF3D60AULL, 0x27F1C928E54DB90EULL, 0xB54D542B77ED8486ULL, 0x5800928B42D86AA1ULL, 
            0x421DCA6F3004F74CULL, 0xA4EF75514D691EC3ULL, 0x17F09E7DA5A7A342ULL, 0x4A62C4137AEC8E03ULL, 
            0x7C961598B79C4CD2ULL, 0x3360CA95ABB4C66FULL, 0x6F5077CEF672EC06ULL, 0x1F983DBAF25BFBE8ULL, 
            0x12BCE97121108B6BULL, 0xBB488F0D4A9D10BEULL, 0xBA5D499493EC156FULL, 0x7F96E6E4FDAF3EA3ULL, 
            0x6986230BF2DDC0CDULL, 0x45C9055407375928ULL, 0xBCAB72D921448E78ULL, 0x08AF9E47D2B616A2ULL, 
            0x90F49E8B501B25AEULL, 0x07F03C4B7577034DULL, 0x8257CEAC2FCC6BB3ULL, 0xCC36F8CE25714891ULL
        },
        {
            0xA0C73FF2B070D694ULL, 0xC33F2572D176CA1EULL, 0x44965D903C76FB30ULL, 0x2D7800BACF61E1C7ULL, 
            0xDBE2C031475BEEEEULL, 0x16B8953B6EFE21A2ULL, 0x4B91E9D2F676BCEEULL, 0x42BC5944C81405C6ULL, 
            0xA78C3EA305EF65A5ULL, 0x73E2534C99A05B7BULL, 0xDADC5E29A2E6601BULL, 0x903D334DD27205DBULL, 
            0x3F66ADC6490809FFULL, 0xA51939EEF9DF5810ULL, 0x3B2AD063EE5821DDULL, 0xAD397362CB0F89C0ULL, 
            0xE1A08080670A6F68ULL, 0x96155BAFBA24DF15ULL, 0x1011FCCFA640ECF1ULL, 0x2DFD2F4AFFEE6232ULL, 
            0x6669AC9127DAD299ULL, 0xF2FA846FB2346567ULL, 0x58A357EA4369258AULL, 0x066ECCA1F25BA1EFULL, 
            0x51CB3B78E45EF5CFULL, 0xDB945944775EDBFFULL, 0x5FBB646342D0FCADULL, 0xCEA54E29862CF161ULL, 
            0xD898DB4F4AC8BE4CULL, 0xD57D4D2E23FFBF31ULL, 0xA816DEE8C8CE6B86ULL, 0x3C78AAFF1AB49864ULL
        }
    },
    {
        {
            0x85363F12030B99D1ULL, 0x91069BA8EFFFD9B3ULL, 0x20DAC95EDB8CCE92ULL, 0x680B26CE77C8633EULL, 
            0x6DA907A6E5928F60ULL, 0x0A4C626AE358FDEAULL, 0xC40305267A7E7229ULL, 0x27BCA5F91404DA7CULL, 
            0x28B1B55612EA94A2ULL, 0x85A2557BCA47DC3BULL, 0x8A8ED1F30218B61EULL, 0x83B18B41BEFEB3DEULL, 
            0xDB48D38AC338F2FBULL, 0xD3DE9C02AF9B4F2FULL, 0x6822D6BC52F3DE6BULL, 0xA168BB6549A669FAULL, 
            0xCD9D466856B70996ULL, 0xF7A59CC2F1A2FAAFULL, 0xA24FA0608F287F7BULL, 0x8F9EFA0F013685F0ULL, 
            0x9C7264D36E085DAFULL, 0x10F83657BD00D5F0ULL, 0x8C9A0EF5ED002E30ULL, 0x75998400A438BDB9ULL, 
            0xE77761E4AC29D6B5ULL, 0x0757189945513F02ULL, 0xF9F55AB22878FCDBULL, 0x6E357A2B24A99828ULL, 
            0x1EC26AF52FEA9873ULL, 0x543C638CA755CFEAULL, 0xC68FE127508AC83EULL, 0x0A496196985B74BDULL
        },
        {
            0x229F2273C15597DAULL, 0x24A3B0DA5DAAE7CFULL, 0x084741F07076E250ULL, 0x42DD3576B4D77348ULL, 
            0x91A81A359B59D7D6ULL, 0xE10CF91D01D8A2E5ULL, 0x0866C4283DC610A5ULL, 0x534E9B5C7EDDFAD1ULL, 
            0xE68AA4930C686301ULL, 0x0D4F50C47F3FAB4AULL, 0xA7DA3FB5C96CEFE0ULL, 0xEECE5A97A5576E1EULL, 
            0x41592D781DC25F72ULL, 0x6EEAD7A01D81A0ABULL, 0xADE81052F46A79E6ULL, 0xB5B3EC26941B431CULL, 
            0x294E416DD47C0D21ULL, 0x7E0DF76D8E1F4F0AULL, 0xCE9F739AF900FD1CULL, 0x78D98B2992E54435ULL, 
            0x9EE6FAE082091D60ULL, 0xECC84862A3A6C849ULL, 0x0C4902FA729B6D17ULL, 0xDD95BB7D732BF178ULL, 
            0xC9885C5C2711A955ULL, 0x77947C94930FCAAAULL, 0x2284DA2645649AB5ULL, 0x70F6536BC49B0869ULL, 
            0xD31ABCDA8B2DF56FULL, 0x9FFEB47FF5DD5C03ULL, 0xB629C14565322C01ULL, 0x2881A07D8F647D82ULL
        },
        {
            0xABD6B093EF2CA012ULL, 0x81ABF5E8CEC0CBE8ULL, 0xB2AFBA90DCB1156BULL, 0xF864BF24B3C0F702ULL, 
            0x512F9698ED79AB55ULL, 0x28389B687BF2C715ULL, 0xCB5401EBD89D54AAULL, 0xCA0AFFA6BD350F57ULL, 
            0x4398866B1D09590FULL, 0x366CE7AF86BB4094ULL, 0xDD07DF72CD2CD5C6ULL, 0xCAE4317D510E406EULL, 
            0x914712BCA381221DULL, 0xE713693DAB965023ULL, 0xEAF9AB6649A63B99ULL, 0xBE41EFC56CDC8901ULL, 
            0x662453FD4F5C1B94ULL, 0x0B6351EEF64DD381ULL, 0xACE717A1B5E2AA38ULL, 0x1361B4C12ABAEB7DULL, 
            0xB1C08FE528E89174ULL, 0xA8F3ACBA86A8FFBAULL, 0xFECD3442C92975D3ULL, 0x4C88357C5CD1F150ULL, 
            0xF6AC4110A9AEDAAFULL, 0xB316E057BD3D49D7ULL, 0xE3872AE8837D062FULL, 0xEE47A54E9C29C4B9ULL, 
            0xBDDBB5642F3EA4BEULL, 0xA638EA89BA8E95FAULL, 0x5F7DE3CBB94FE23CULL, 0x137EAF8368A59C6BULL
        },
        {
            0xFEA247D1184EF4FAULL, 0xBAD4E658F268F3B2ULL, 0xBBE25CDCC23D9239ULL, 0x89234037AC0B71C5ULL, 
            0x917FFF735D6B3881ULL, 0xF5B442A0EAA3EB66ULL, 0x683671B8CE1A1994ULL, 0xB06935B5717D5796ULL, 
            0x38734D36266354D6ULL, 0x6B6DB8F327AE7D72ULL, 0x7F73090A459DE552ULL, 0xCB268640B2A8B0FDULL, 
            0xBD866734F3578CE3ULL, 0x4FF252E573F9C7E9ULL, 0xECC8914049AC5B6BULL, 0xF564F86EEC129172ULL, 
            0x9558BBE46B46EA84ULL, 0xB96907F4C4F1E993ULL, 0x019F637739108481ULL, 0x1C3564F7BEDFCE14ULL, 
            0x01A17A3F2E7BD08CULL, 0x46288F6668FFF1B0ULL, 0xE8053D99355A06BDULL, 0x104E79B876F4D646ULL, 
            0x7FACACBD16FBDDA6ULL, 0xD305086C8019338FULL, 0x115625838740B71CULL, 0x652F349FD152962FULL, 
            0x1F7606484B21EDBDULL, 0x613AD47B58399C83ULL, 0xECB6DEC32A1A21B2ULL, 0x1C4F0192CD4BC495ULL
        },
        {
            0x289F851E1F7261E1ULL, 0x32BF10C6CDD2E6D4ULL, 0xA7A700E5162A4FB7ULL, 0xAB0949E5422EE22EULL, 
            0xDEAF117C1144391FULL, 0x9FB622CA38FEAE5AULL, 0x999086160243EC53ULL, 0xFCD4E006AB454A34ULL, 
            0xD8C7F87B79121C79ULL, 0xAF54A0735109D26AULL, 0x301F5971F7F91C24ULL, 0x2D00F7950D18C27EULL, 
            0x6946195248933EBAULL, 0x7E4A529524B91CDEULL, 0xD6BDF9187D0F34AEULL, 0xEC708B0EB6E7EC68ULL, 
            0xA51A782F254314C4ULL, 0x0408F0DC36D2B7CFULL, 0x50902BDFE9DA061BULL, 0x10B63B60D52889FFULL, 
            0xA0C782DA2C198B13ULL, 0xF9C3A6716C0ED8CBULL, 0x0FC7CE31A4ABEBADULL, 0x0F713E6BDF9E6885ULL, 
            0x41D8F334A25BFA97ULL, 0xA7EE959C86CBBFAAULL, 0xA45CDEDF7A5B2613ULL, 0x60E1E083AAB375B8ULL, 
            0xF0BFFAD1A9A714D3ULL, 0x88D5787AE5540A22ULL, 0x6DA8A55160F9B328ULL, 0x826B8D82FAD9B257ULL
        },
        {
            0xF716C8AFFC38CEA7ULL, 0xEDABA95F65BF6529ULL, 0x32A9F08FC5D0B09BULL, 0x5B7E2C995AC3E9D4ULL, 
            0x3CC3721806AF4E4FULL, 0xC3079723F187D5D4ULL, 0x796897D5E0402DBCULL, 0x6BEC5A2F3E92339DULL, 
            0x81224E0974E704BBULL, 0x9876DA220FD6AC73ULL, 0x3E47F403ED28998AULL, 0x81CC78E2B2B3BEF1ULL, 
            0xF8025E6594452638ULL, 0x443DA1BA5EC082C8ULL, 0x9D85B8AE1CFAB3F0ULL, 0x881EE876DC977222ULL, 
            0x5FB897F3C0892F62ULL, 0xE97C54F7B61C8F48ULL, 0x2B4785ED7D14663CULL, 0xF46BBBE8D8E7721CULL, 
            0x4351779BBE86298DULL, 0x4494CF9DEBFCD048ULL, 0x95964A335FBD1B1AULL, 0x30DB7FE49867354AULL, 
            0x5A48262F4CC522C6ULL, 0x778C49114363E6B8ULL, 0xDA0EC913F43DB3DBULL, 0x37C8D2945F084FC5ULL, 
            0xBCBD5CB718B4C928ULL, 0x390FB0E1D07AE660ULL, 0x8D2387F7EED006FDULL, 0x24E72845DEEB9CD9ULL
        }
    },
    {
        {
            0x08E7FF5D9238361CULL, 0x7B56F40C3178665BULL, 0xE61B40DDFA45EA03ULL, 0xDCB5CCCA32049E37ULL, 
            0xB5A2D37817B9C53DULL, 0x036606EEF12A18D7ULL, 0x15F6C67D79DD43C2ULL, 0x7EB494314932E8A9ULL, 
            0x775FBF3B1115E266ULL, 0xF15625442F9E53C5ULL, 0xA53D4F715525C096ULL, 0x28831B7AA1547873ULL, 
            0xF87B3DE91E2914A9ULL, 0xE6F2638F54C860FBULL, 0x29A03DC0314D9288ULL, 0xBDE9D5359EB69616ULL, 
            0x2338F3D2A88B91CDULL, 0x0882BAE555A944FDULL, 0x31833DB95D7C50ADULL, 0xB6C53DAA3FF99CB0ULL, 
            0x1A04FF8F7047FF9FULL, 0x97509D63C56175CDULL, 0x139A5AFB378F0F6FULL, 0xD96AFCFAD791953BULL, 
            0xCB48F922540ABD22ULL, 0xB055BF05838C4DFFULL, 0xDBD9CD07F392B6A7ULL, 0x80C7772C3CD34224ULL, 
            0x1996FF75549086D9ULL, 0x1093BAB600C24B22ULL, 0x1F38EB97908BBA47ULL, 0xF94EF7E417B2232BULL
        },
        {
            0x1F2F9DCA6C740B89ULL, 0xFF90C4A02F8B09E6ULL, 0x39B856F3BB7165C9ULL, 0x183B7EB8BE8BD3E2ULL, 
            0x71ED685258FF9332ULL, 0xDF062B3BEE607F6EULL, 0x353DB6AECB0E2D6CULL, 0xB69808E2482B2292ULL, 
            0x8D30EB232BA4B9AFULL, 0xC687E4A6A4EDC16AULL, 0xB38380B506E3A8C3ULL, 0xC9BE4111D1F24BDFULL, 
            0x650E6E0DB248E920ULL, 0xA900103ABEA523CBULL, 0x957C0273F2D9AC81ULL, 0xD8C5B19F024D9F00ULL, 
            0x9CD8E0E796EE2852ULL, 0xBFC91C322503B04BULL, 0x04DFA726FB8E68CAULL, 0xE07A9BCF25F60A2EULL, 
            0x72B3BCDF1C25E833ULL, 0x48F786A0D4C5B35AULL, 0x1618DA4320CE49DEULL, 0xC7284157AD860394ULL, 
            0xFD41E5673450244AULL, 0xEBB8FD4958B0A446ULL, 0x7A32613625F090C2ULL, 0x2842A708741DB001ULL, 
            0x8049FD849C0DCA5DULL, 0xC0A88B44E9FB1C33ULL, 0xFBE71B1E7D4C2440ULL, 0x499C69CA4B8C212EULL
        },
        {
            0xC9B8BE13A513D756ULL, 0x8CB8D1A4150AF5E1ULL, 0x6182F2583A32CC9DULL, 0x2B3ED55F1DE3B9A5ULL, 
            0x3D00CC31AB49DDC0ULL, 0x9C859924873E1B31ULL, 0xB7DFEACB682781B5ULL, 0xCA3CAF48090820C4ULL, 
            0x56E2ECBF3E47C246ULL, 0x5A4A5D11480D938EULL, 0x8571CA0706AB53C5ULL, 0x7E37BFC941482A10ULL, 
            0x49D481F3A75B3F29ULL, 0x2A4FB6B73F535701ULL, 0xABA0D80558630DC5ULL, 0x25DC550A2DBE2697ULL, 
            0xE57590B327F2CA56ULL, 0x00D5EB4F20867028ULL, 0xF3F067C75B077CD4ULL, 0x5ACDFD7208E46247ULL, 
            0x3B1E40E7FEF44571ULL, 0x84295FC4EA0F42D6ULL, 0xFD0633AF4DEA67FCULL, 0xBB44812EC6A3623CULL, 
            0x6B7DBE2A4160DF05ULL, 0x98CCA8FBCFF9786AULL, 0x18B378C8A116D420ULL, 0xC43D18981006FC1AULL, 
            0xABD47E5C3D126A6AULL, 0xE512D9C9F70C1DDAULL, 0xE8B58360C98D4C8CULL, 0x97F5172F4C178635ULL
        },
        {
            0xCECBFAE84399E8F5ULL, 0x33CBE9198366F7D7ULL, 0x3FFD1B2CECE8486EULL, 0x12099D3B5E662531ULL, 
            0xDE28AFD24758EF82ULL, 0xC55ED7C468A50091ULL, 0x66EC6B3039532E13ULL, 0x1391AA1CAAA06DF0ULL, 
            0xA2640ECF6F60C9CFULL, 0x558193945C871EEBULL, 0xA763EE3176D44D13ULL, 0x95E321CCF130D2A8ULL, 
            0xE9E3DC77F59FF8C9ULL, 0xFE4ED2E230F6B461ULL, 0xA90EADAA4DD5757FULL, 0x1ABEE47D60EAAFFFULL, 
            0xBBB5B720445D1525ULL, 0x93D36347DE1BE68EULL, 0x4BF190425308F91FULL, 0xDCCCFF8DF1B98998ULL, 
            0x6E6914288643FDC4ULL, 0x668BEFEDF958D154ULL, 0xC9FA51A6B44E073BULL, 0x3CEE222BAA86C750ULL, 
            0x4E73BDA376638441ULL, 0x2EF83FCCE3216068ULL, 0x3715ED36DDDF3A66ULL, 0x33EC2D77256CD0E4ULL, 
            0x967DF0602F0D179BULL, 0x808B0C5601B01C0CULL, 0x645308CB90ABB00EULL, 0x09933B3840362C44ULL
        },
        {
            0x331083CD6F409370ULL, 0xA7992F1BFA1C8615ULL, 0x178E349D0F358B1FULL, 0x659944F88F84E422ULL, 
            0x2B32469A2607AA7FULL, 0x8377FA7BCD2B6F6DULL, 0x6390302B51A0A74AULL, 0x1B0951281F853BB9ULL, 
            0x671760A7B3AC0DC2ULL, 0x6D40905682561109ULL, 0xFCAAE513C9F85503ULL, 0x88DB5BF5E3981537ULL, 
            0x1818DD66EEEAE9BBULL, 0x02064A9213D2D091ULL, 0x9DAC1207695B6DC8ULL, 0xE1B75D7CE0B235A1ULL, 
            0x6E24DF624C896DDBULL, 0xEC9786C840909C5FULL, 0xD4CEA0533BC63D53ULL, 0xCDB01F3A16C61786ULL, 
            0x9A1B2CA6B534F7ADULL, 0x2A95D6FE1D00202EULL, 0x7612CD57759C6935ULL, 0x44A56A4C30B6A3C1ULL, 
            0x18FD81C5C5CD05CEULL, 0xDCB309A63E777124ULL, 0xE288565E3FBCEEFDULL, 0x132CB146AFC0AF60ULL, 
            0x9A208B2D67D0A2B4ULL, 0x04C4F84BFD5379FEULL, 0x88DF965B0BC25FDEULL, 0x37AFA34693B73548ULL
        },
        {
            0xAAA5F1A5C5022FC9ULL, 0xE5DC62CDECD7B574ULL, 0xBFD86A252FE79A76ULL, 0xD2F9E1A52403970BULL, 
            0x7FF978C845E4D3DAULL, 0xD6A87304D4EFF27DULL, 0x585159D46C79A6BAULL, 0xB989A7EA8266AEBFULL, 
            0x4ECAF89759591B6EULL, 0x810E14E737692A0CULL, 0x45DDD0F9404DD237ULL, 0xD06DA6AE65B27A3EULL, 
            0xA1C7131CD3E052FFULL, 0x2E52C18294BEB156ULL, 0xD141FD28DCA39A5AULL, 0x7F7152299596F305ULL, 
            0x9F6C14B32303140DULL, 0x46BD930942C404F2ULL, 0xC54BC0E1BF57DD4FULL, 0xEC8D66835F1C2FCAULL, 
            0x6759C2E80FCE7194ULL, 0x0D3223587AB2731EULL, 0x2FF25F138E510164ULL, 0x6DD4808994AE3371ULL, 
            0x9A293366A0374EB1ULL, 0x54BF8A9A80EF5018ULL, 0xBC257D24C28AE6B5ULL, 0x8C0FD2F3753215E5ULL, 
            0xFF9C04281AAA942CULL, 0x850B585C7F56764FULL, 0x21DAD3A1F8B18433ULL, 0xCBAD009ED8DB6F30ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseEConstants = {
    0xAE2507C2155C8E58ULL,
    0x5C8D66FDECCB5FB8ULL,
    0x32E635E6949CAD9BULL,
    0xAE2507C2155C8E58ULL,
    0x5C8D66FDECCB5FB8ULL,
    0x32E635E6949CAD9BULL,
    0x4E34F67EAC2DB864ULL,
    0x5165AF4314AAA023ULL,
    0xBB,
    0x63,
    0x5F,
    0x70,
    0xF1,
    0xDC,
    0x2A,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseFSalts = {
    {
        {
            0x81E4647CA57DA817ULL, 0xDD89002E3949E785ULL, 0xC7BF9707DF63D267ULL, 0x696A2A75FE0DE05DULL, 
            0x6CE50D2B62C976D2ULL, 0xBBDDAE5149F3F9B5ULL, 0x6B270B71E5630E3EULL, 0x5402681EE18EAB07ULL, 
            0x0417E6EF93E35FE6ULL, 0x98D3950B80401939ULL, 0x87DB1B7180741225ULL, 0xFC1D8DFB21F6EF84ULL, 
            0x2BF2CC4F45920475ULL, 0x4C8595A50CC9FD86ULL, 0xE744C9E1D46923DBULL, 0x51CFA443579B3070ULL, 
            0x4F0649EF6E426934ULL, 0x7D4A7B036B28DFA7ULL, 0x5C03A7C95B3EA84CULL, 0xDBD2C850DBFB1DC0ULL, 
            0x893B24FE5D0DDF25ULL, 0x8BB30996382730B4ULL, 0x131C43B56695B52BULL, 0xC4C74EFAFFB31394ULL, 
            0x2A44F68F9FDE7726ULL, 0xF5D427DBF82CA3F9ULL, 0x761CB6A4A7EC3333ULL, 0xBE151D9F9AE5CED4ULL, 
            0x8243EB3F9477C0C7ULL, 0x5F6EEDA466790D11ULL, 0x5C39C4645EC9610DULL, 0xE33E56A4B5A60398ULL
        },
        {
            0x1EF28EF201D3B68CULL, 0xC1EE4977B15442FCULL, 0xE608938ABD71B2FAULL, 0x98296E65A6990644ULL, 
            0xF9FD18C9FC162EF6ULL, 0xC64752BF61C885F0ULL, 0x7E1361CB40668AC7ULL, 0xD62CE7E9831FA085ULL, 
            0xC9AB0A3614FAB907ULL, 0x519C3F5A73796DD7ULL, 0xC100DF6E792EF883ULL, 0x2CEDD47DDF1DDE23ULL, 
            0xBAD42339E10C6BB4ULL, 0x1CFB9B8B21098AE4ULL, 0xB5286D19F983169DULL, 0xC25474585DF934C4ULL, 
            0x09145F9B312DD1EBULL, 0xD5D697C057843EB4ULL, 0xD7F644F334B72414ULL, 0xD046DB1DD8A7154BULL, 
            0x79540E91FEA46751ULL, 0x64E09D464FE216C1ULL, 0xB93B9D272C5E7FB9ULL, 0x6494AD90C3743504ULL, 
            0xEAB28131F3B9FC36ULL, 0x65972B4FA9CE11A6ULL, 0xC42231E857C952E7ULL, 0x61353A225C23F3D1ULL, 
            0xC26BFF1B75B91CA0ULL, 0xFBE322D1AD2BD393ULL, 0xD3CD6A45E88730E3ULL, 0xBF035F8DC00A8349ULL
        },
        {
            0x9B7B350154A6702EULL, 0xEA93E7E37A9696E9ULL, 0xF63DE38E69071532ULL, 0x6CBACCA8A9A8E9E5ULL, 
            0x7E1BA570DF757F2AULL, 0x59EB3F274392F02FULL, 0x3087A45264714D6FULL, 0xCE5CC2D59C89E668ULL, 
            0x194CC8DA6843FE96ULL, 0x909FB66ABEAB9C50ULL, 0x3C371384940AEFFFULL, 0xB51C1984B1B9B3CEULL, 
            0x595DFD179B82B438ULL, 0x3CFB6CE96C5EFC53ULL, 0xBCA419EFF2E1BB96ULL, 0x3D3E9541B982389FULL, 
            0x36E5F21DAFC15F40ULL, 0xE2E6EB7EE0A01D1BULL, 0xAD293CB1174ED0B2ULL, 0x1312F5AEFB98137FULL, 
            0x0A8E3AA91C8D9F1FULL, 0x1B39E01228C4D588ULL, 0x7414C8046E029D3BULL, 0x8B22673BE0589ED9ULL, 
            0x66DC196FE3BA29A8ULL, 0x6247E84DA69E7A6DULL, 0x18CC88DB3206BA21ULL, 0x0BC45692DFFE2267ULL, 
            0x68B776BF0450CF01ULL, 0x8306486878A101F9ULL, 0x5A71DC9C222FA479ULL, 0xB7026996347C55D1ULL
        },
        {
            0x951A50EF57BF96BFULL, 0x9948485078A0C874ULL, 0x0E760FE7D924C19BULL, 0x5F48AD30B55A5814ULL, 
            0x0D02BEBE7AC38B65ULL, 0xE4BE979F0B068121ULL, 0x5C6534261C864DF4ULL, 0x8204332FCEA27C92ULL, 
            0x8DF1A6138C50B46AULL, 0xF182019CBE841403ULL, 0x952F1A8A680559ECULL, 0x7B4765ACAC99DF90ULL, 
            0xF1A0A04CB5CB85E3ULL, 0x00CE0617701EDF0DULL, 0xEF0C65651AE43D60ULL, 0x40FC3243F7D9466BULL, 
            0xD862B53FEB38B41EULL, 0x989DEE34394E4C8AULL, 0x0EF0B9FC4B473C95ULL, 0xFF0AEDE86D835CF2ULL, 
            0x409D086DA3D0AF9CULL, 0xB7A5703CC6DAB4D1ULL, 0x548A01ECE4F27AB5ULL, 0xB1A0DCFF68FD1E8FULL, 
            0xF917E984D0A698E3ULL, 0x3549E0D4B8F5FDE3ULL, 0x1CACBE779CF8DA7EULL, 0x6F034EA7D7F555FCULL, 
            0x328764A971FEBBA6ULL, 0x749D62A3C5B6589BULL, 0x2E4FB661C227E8DCULL, 0x54EA9D010060E0FDULL
        },
        {
            0x32317E912D07F90DULL, 0x0C0B7E4696B0B555ULL, 0xB3D55AE64F735ADCULL, 0x1808985B8B938431ULL, 
            0x006872EEC941C67BULL, 0xD04ECCE0AA0D00E7ULL, 0xF9F6EBF3E0B781D8ULL, 0xA46F9B5782E206F7ULL, 
            0xBA5E83D00A749516ULL, 0x5A71E24443896977ULL, 0xD286BE5D6110DF1EULL, 0x3B6B2E75AA4E92E0ULL, 
            0xA87B490560C9D4C5ULL, 0xC040AD297C2E2056ULL, 0x8085B413F3F643EFULL, 0x005446CFC24D29D5ULL, 
            0x61A40515F4DAC3C7ULL, 0x48FF086E9766E488ULL, 0x2758305A532A9B0DULL, 0x26CED869E778B91BULL, 
            0xE0AF35F30A65B7B3ULL, 0xF1D0E64C124CC5C5ULL, 0xE6D2B632D8D251ADULL, 0xB996CA5047AFD3FDULL, 
            0x5A754787FF554A3EULL, 0xC1EA150290DF0DC6ULL, 0x464721DCF9D10F02ULL, 0xE67BCEE416C81704ULL, 
            0xF86467736E16EBECULL, 0xD0BC23E538FA8F95ULL, 0x3EA00D277E7776C3ULL, 0xCD0D84D25D76F17AULL
        },
        {
            0x2E531EE30284BB26ULL, 0x386D68340A46315BULL, 0xD6C5F9E165673404ULL, 0xAE6C1AA1F374B997ULL, 
            0xA911ECB5D4B2C8C1ULL, 0x5C2814ED59BDDD2CULL, 0xA8341046E1060D29ULL, 0x0DA039EDEFFEEEDAULL, 
            0x1EE990478124BBD3ULL, 0x5A3A0E1201975A5BULL, 0x88915D523FA341C1ULL, 0x1AB875C599878CFFULL, 
            0xA12CAD979040371AULL, 0x91C0475A2AE3CD0EULL, 0x68ED2296990F96B3ULL, 0xBFE99E43A5C5FC06ULL, 
            0x4274A3B5FEC1B095ULL, 0xCB8398B06363BDCBULL, 0x5098B65E79B84633ULL, 0x20089D03013A8799ULL, 
            0x3FC92ABF40BD2213ULL, 0x5A8082407D63A66BULL, 0xECE25289B17BDA54ULL, 0x93B7B996DFFACEAEULL, 
            0x17D9B9D2DB194E28ULL, 0xA044F390F24D01E2ULL, 0xE50C738FCDB2A1B6ULL, 0xD528796405941CA0ULL, 
            0x5FBB19021726A543ULL, 0x3946AEC5CBB0F10DULL, 0x479B9266628663ADULL, 0x202DC9AC9B098D08ULL
        }
    },
    {
        {
            0x490B969944B0437EULL, 0xD1826401B43B09BBULL, 0x40367BDDF6A88F7BULL, 0xB271F8230B3E3220ULL, 
            0x61B7456E5CACE646ULL, 0xE42A6BF28F4E5F63ULL, 0xFE5960C575AFB6E8ULL, 0x31F5201317F3F580ULL, 
            0x6984C94528129E7EULL, 0xCA53465F85BCDEE3ULL, 0x0F3C0D4BE981408EULL, 0x5514C8AAD2AC0D94ULL, 
            0x942934D3666DC6D9ULL, 0x3271BD1F83C4DE9EULL, 0x074D8850F4A512CDULL, 0x6BCB63C3644533D7ULL, 
            0x754483053479099CULL, 0x830615581C845536ULL, 0x3EB40B81FBF534CDULL, 0xFD90D0500BDD2D9FULL, 
            0x2ADE7E38D77B7236ULL, 0x11D285C98654544AULL, 0xB1C6CEA76E50EAB1ULL, 0x3ED6C426133786BEULL, 
            0xEE688E5207D2BEAEULL, 0xB146B5EA498FE51BULL, 0xA77D2DAFEAF7572EULL, 0xE92F7B79C569DD6FULL, 
            0x833F3F461A128AC2ULL, 0x2B4B6791015F3720ULL, 0x40F1222488B33B71ULL, 0x2DD65E3CFA08A1EBULL
        },
        {
            0xCFF3E315A24CC1DEULL, 0x7D67ECCF597D60C5ULL, 0x2E7839B1A8117C3BULL, 0x2806FEA6CACC3348ULL, 
            0x5F9551A48C313637ULL, 0x8B16625C61D3726DULL, 0xE119D7BD9E4A4B5AULL, 0x607332C4CB0628E5ULL, 
            0xF7527E11CACFED42ULL, 0xF27B7326CE62A539ULL, 0x38A4620D3D15712BULL, 0x5E1BAC794E7F7279ULL, 
            0xBE74A511178C161AULL, 0xAD3B3BFE2D571456ULL, 0x6A4AB406E18155BBULL, 0x541F85ABA9F7DC36ULL, 
            0xC05971C72D1E1B58ULL, 0xF4532B9A4E2C4FFEULL, 0x4B86BFB32B60532EULL, 0x799CB804C5A3F253ULL, 
            0x89E5796B79550B3EULL, 0x8B3AB194FB6F058EULL, 0x809C86791DD39ED7ULL, 0xC0FD5FE12AF289B9ULL, 
            0xF6FF7416D5F64537ULL, 0x3F976401A9F62FA2ULL, 0x17E388521CC99A1EULL, 0x865BACEF0EC5B1A6ULL, 
            0x16BC9AF8A3DB0AA5ULL, 0xE29696C20DED3B5FULL, 0xA62821B6B7B0523AULL, 0xEBAB906194AF750EULL
        },
        {
            0x5B686A6148024B27ULL, 0xEB63A48F60518A49ULL, 0xA7E0F0DD0FEB7FCDULL, 0x5E5EDCC2AD373764ULL, 
            0xA19273D2D849AFEAULL, 0x98D4E6202A61D0E9ULL, 0xA74EA12B96D7E772ULL, 0xF0A93D565CC65766ULL, 
            0xDE915BA770FDC544ULL, 0x744868ED7B6FD68DULL, 0xF255BC0A6EDEC08AULL, 0xB4A40A8670A9F854ULL, 
            0x5CDBB75188DDA3DFULL, 0x939059B932AA4DFCULL, 0x3AD10BDC99CBA5B4ULL, 0xEBDED9361F4F660BULL, 
            0xCA28988E0C891FA1ULL, 0x8ADAC2EEA2E70E6EULL, 0xFC76595D08FDE9B0ULL, 0xE47D96951B24F5A8ULL, 
            0x101B55D05EA0D815ULL, 0x1E23625FE1033506ULL, 0x3E5CE89CF6D1BFBCULL, 0x373681BB652DAC10ULL, 
            0xC5E65F1C82E13C7EULL, 0x603D3D6BD3F461C7ULL, 0x4BCBAF988D8B7042ULL, 0x9062B6DE17E78C35ULL, 
            0x6247C61F34ECA627ULL, 0x107EE2257A482D61ULL, 0x3A581DF14B8BEA73ULL, 0x21F167100E8E91D5ULL
        },
        {
            0x2F8729AE95AABAE1ULL, 0x994570DD74FABAE6ULL, 0xF8EAAE1C5C5879F7ULL, 0x0F11374FA4130DBCULL, 
            0x8192A1DCFB4B6AD1ULL, 0x4A51BB0537794B45ULL, 0x0526CCBA319F3CC4ULL, 0x0B31518C5C3C6F29ULL, 
            0xE8497F2AED5989ABULL, 0xCF987D021139A6D0ULL, 0xD2C71D783A64AA3DULL, 0xE97A6F7C676956BBULL, 
            0x52B4580762156769ULL, 0x094EF3CABA9DA196ULL, 0xF37BFD9B8DDCB719ULL, 0xE45D2BF28651B18FULL, 
            0x14AC0E4A714FD256ULL, 0x735AE2C1DD398703ULL, 0xF2C3506B119E41C9ULL, 0x8079999BA401CB2EULL, 
            0xC133F1B505F8B913ULL, 0x7F371531B9FD2238ULL, 0x0A1C709D3F07D8E4ULL, 0x86ABC88D7A5A984FULL, 
            0xE3047869999C3BE5ULL, 0x75D7F5C40AA2A242ULL, 0x51390965A356A668ULL, 0x7FEC89D063855780ULL, 
            0x5E443C9D8808D54BULL, 0x710497DD9D418945ULL, 0x52597EA82AFC263CULL, 0x95BA06A386D941CBULL
        },
        {
            0x751AA2E7752B496FULL, 0x858CC313E06919ACULL, 0xB4760D707256004DULL, 0x23667E1095DA7C25ULL, 
            0x0FD773DE54F3BF6FULL, 0xB1B378F00A93B2C7ULL, 0xEDE197C32DD9A574ULL, 0xC0421DFE6121E1C7ULL, 
            0x942F69BFF4EB3710ULL, 0x255999991F42C706ULL, 0x46B91D65A518DAD7ULL, 0x2855B2EC050FD217ULL, 
            0x5A0296AE406514AFULL, 0x35469568C632DB78ULL, 0x01160A06AA6F1383ULL, 0x81FF679B5C29C70AULL, 
            0x8C96F874CECAFDD0ULL, 0xD3D3BBDFEED49F64ULL, 0x5C00801434BF3786ULL, 0xD04332D18019FB11ULL, 
            0x870921BEFC653243ULL, 0xB3A13133596D4A94ULL, 0xAD90FFAD4B3BE487ULL, 0xAB300FFCD454F6E8ULL, 
            0x993C86A38903DEE1ULL, 0x3217E3E822B57F98ULL, 0x70E12322AAEAA409ULL, 0x53C7806340FCF240ULL, 
            0x9E1C04C1ADE346BBULL, 0x51669B73D353AEFAULL, 0x269DAFACABCBE777ULL, 0xB1278349580C5365ULL
        },
        {
            0x1AD54E25CEBA3D7FULL, 0xEAA147A8A88C3178ULL, 0xA796D92CDF3D01D2ULL, 0xC216115C51E291BAULL, 
            0x72FF6C8AC0811164ULL, 0xEFEE70C619790E5EULL, 0x9FFF0709A15981EDULL, 0x0AC881194F225821ULL, 
            0x157BC0F14CD9DE1DULL, 0xD8A6E105B22B1BDAULL, 0xD3C166DDEDDF77EDULL, 0x08F959405887DE76ULL, 
            0xBD6256C9555A31A3ULL, 0x8587F7AF44F79465ULL, 0x9A78925C269AC57FULL, 0x9D0AC78A01E05621ULL, 
            0x3D53349279592DA5ULL, 0x87BD222D5CACA681ULL, 0x27D6783121D02E9EULL, 0xE98E2BC25B42C953ULL, 
            0xB5B994592609FFA0ULL, 0xF8D4EF1E960B1F12ULL, 0x4D72DF1A8C9B35F1ULL, 0x9797A6FA984FA0B7ULL, 
            0x282AFB808C5B5867ULL, 0x82C48BC33B0BDB3EULL, 0x948F2747915035F1ULL, 0x7B8C59CB89269918ULL, 
            0x4F5DB3D64B653CFBULL, 0xB8C113CA27F8677DULL, 0x89AA892849D9DC97ULL, 0xD716E269C5EF3FD0ULL
        }
    },
    {
        {
            0x43652BCC29A03218ULL, 0x7C6B36AFCB82BC2FULL, 0x71FC44232918E7C0ULL, 0xA406D896D9B680C2ULL, 
            0xAFD74D7AA1745A31ULL, 0xE0D540FD811AA08DULL, 0xA17AEFD4BC1741C7ULL, 0x7CD86C48E897640BULL, 
            0x778C1BBCEB65B53CULL, 0x994B6182B32F59ECULL, 0xBDFACE1EB52000BEULL, 0x8E64F0581F19CEAFULL, 
            0xA25769A2C8E21284ULL, 0xFEBA3A41AC77C501ULL, 0xD788400A37A2A22BULL, 0x05ECD7ABDC8A9D4CULL, 
            0x39FF703F1E84D333ULL, 0x4376B6603843C9D4ULL, 0xA98B666B6AC1FA04ULL, 0x80781C2D59218FADULL, 
            0x5CA82B48AEEB298EULL, 0xE622B2499240491AULL, 0x02D3670631B2127DULL, 0xE527E96160AE740FULL, 
            0xC386FF709CEE5C20ULL, 0x7BB9340426B34B6DULL, 0x9F03683CAE48EFD9ULL, 0x086A08902CDC3853ULL, 
            0x925AF134F3A2C495ULL, 0x739D966284FCF70DULL, 0x00B0480E9BB78500ULL, 0xB7CF9F2A5F5F61F3ULL
        },
        {
            0x1589B0CD83FB3F49ULL, 0x9CDFA16B97D0947EULL, 0x9895EDBAA4D62D89ULL, 0xCEA3F0DC9ADF972BULL, 
            0x3E75EA3330F8B5ECULL, 0x1973AC8D2AC9B9B6ULL, 0x7E25CA3CF804E463ULL, 0x2D3DD353079A390DULL, 
            0x782636E5C4F1AB79ULL, 0x1942046DDABF50F8ULL, 0xD8B5206B666F5ADEULL, 0x6D71E6D8D8B68CCFULL, 
            0x1CA54997CCF3FE1FULL, 0x926B1AE6DE498698ULL, 0x2C0732882F2E35F3ULL, 0x8CB7A17C3E155FEAULL, 
            0x93DB0B6B399A6D5CULL, 0xB472C86BFF957D4EULL, 0x0A8CC498E3313C0CULL, 0x1AA8294E9BD71D7CULL, 
            0x8D21599C25E52B01ULL, 0x2814C4D40366BBDBULL, 0x49DC7A14D3F0DEE2ULL, 0xA728F39316BAC32AULL, 
            0xBFCB9314B9C8A984ULL, 0x934D3980D85C9829ULL, 0x2E5683F4B0855FC5ULL, 0x3E7FB32CAD17EC77ULL, 
            0x8DA46D2D1D73222CULL, 0x9FC68230EA523C94ULL, 0x42E8A5EEDCEBEE24ULL, 0x11F44F0DA65E623EULL
        },
        {
            0xC0B4D84F576D1B27ULL, 0x3E7E871A33F9B355ULL, 0x9C97D20F105D48DDULL, 0xF63EF9C49846C403ULL, 
            0xA632304950CD0D14ULL, 0xBC86BB85BA78EF01ULL, 0x6D456CDD51036CF7ULL, 0xB72756A838EE2874ULL, 
            0x8D4E02C22D679594ULL, 0xA9421216C9253920ULL, 0xDEE8B0E7F97E689EULL, 0xE6E8E45094C16BF2ULL, 
            0xCC1627E059E5F10DULL, 0xBC25E24B21FD8AC8ULL, 0x5A670F2C898C4A92ULL, 0x8F1D682DE9E8A1EAULL, 
            0xFFC5577F1A2DE1CFULL, 0x22A171F7FB6EFB72ULL, 0xB43B5F8444E6AD36ULL, 0x4CCAE911C4C8675AULL, 
            0xEC618C6B0C510E88ULL, 0x4090CFF8AAB5F6C0ULL, 0xC3BCC323DC59D576ULL, 0x39CB347CA9DAA1DDULL, 
            0x548ED065127E3801ULL, 0xB1A5FBD73A4A9160ULL, 0x2649450F41FC0BC5ULL, 0xD815832824B2E349ULL, 
            0x29DA7F35DEF16BECULL, 0xAEE1E95318821155ULL, 0x860B55750B5AF250ULL, 0x55E0E574BF97C96DULL
        },
        {
            0x0B3959F450E4D802ULL, 0x422FE092F64D216DULL, 0x79F3919FEB0D0E66ULL, 0xB8EACB7EFF46D133ULL, 
            0x7AFC40306BE2C621ULL, 0x69981C0AD8C432F6ULL, 0x11528FE6B7A6B9E9ULL, 0x80ADEAD2AAB26F21ULL, 
            0xDE1DAA6E39FBB003ULL, 0x78A8471BD079E1D6ULL, 0x034D606DD3392D16ULL, 0x644C2EA455328F0AULL, 
            0x88CE4B65BC4497BDULL, 0x3E9ABC903FCB4207ULL, 0x5315C6265D56456AULL, 0x951FC2FF4FBE5872ULL, 
            0xE2E90D157B38B189ULL, 0xE27E5F54085576BBULL, 0x9B7CE5B5E954FFD1ULL, 0xC772006CE74EE368ULL, 
            0x8758130913E57683ULL, 0xBDA5C209AE3F4648ULL, 0x82B3BAECF7692AA4ULL, 0x62E0512FC6C57417ULL, 
            0x2C42D4D983D1095CULL, 0x90DF18843B886F9CULL, 0x1024AEC158BEFED1ULL, 0x75D368A02A40723EULL, 
            0xBFC7279C044D1584ULL, 0xE740FA5A5F9BA194ULL, 0x3486366CB1FE676BULL, 0x1B2254837C5DD7CEULL
        },
        {
            0x571D1AF025D3EF96ULL, 0x2CEDBC3E6546907DULL, 0xF40F4A6C493D89E7ULL, 0x7121A93248EE98D2ULL, 
            0xC537EFC4F67CE076ULL, 0xA8463FC24D1CF699ULL, 0xF32E5B89ABB6E2B0ULL, 0x7F28E298A7069CE2ULL, 
            0x0238341C97F2789EULL, 0xD4A8DACB4CCBBCE4ULL, 0x71A278BA6B475BADULL, 0xCB524DC6D9F172A8ULL, 
            0xBC2940CDA084D510ULL, 0x90D6D2ABB8EB2A0BULL, 0xD9C21F3485C26A14ULL, 0xCF69F7566E456CF0ULL, 
            0x2CA2E226041B1406ULL, 0x47ED15C12D71558DULL, 0x3DCCD2BFAD3D0CABULL, 0x055929522B2C7B75ULL, 
            0xF2A33630B17D53B4ULL, 0xAD6F5A7C04E090BEULL, 0x356E03C1BFFC2F5CULL, 0xF45044EC42BBC361ULL, 
            0x87689393C5141FFEULL, 0x7F2095C8EC7C220FULL, 0xE5AB790E3DD1E0F1ULL, 0x3A5B19C244138BADULL, 
            0xD615BE3F73199DDEULL, 0x1A4C88E47A612F48ULL, 0x7B723681F60FE5DEULL, 0xD30AD207459815F9ULL
        },
        {
            0xE1E3D7D247C68766ULL, 0x4CECF9AE6286A84AULL, 0x728DA7FB6B4DAAF2ULL, 0x1036A30B4F3B9A19ULL, 
            0x17B1C52E3908E58BULL, 0xA2AA5AB098D12161ULL, 0x7A7C2D5C51A9B340ULL, 0xFD2B88A663D0CBB3ULL, 
            0x7BA47529257CD505ULL, 0x76A263C488DD9760ULL, 0x2C7A6A5C4EB3031AULL, 0xCF7567613AEE4229ULL, 
            0x47F7B136EFA8D4BAULL, 0xA939329B95818801ULL, 0x3448174948C5D7C9ULL, 0xBE968B4D968C8ED0ULL, 
            0x88C3DC4C5DA3134BULL, 0x0098AEB03B8AE268ULL, 0x47FE8F3B5436F094ULL, 0x0403D9BD702B6B6AULL, 
            0x1961685BF29485CEULL, 0xEFD443CF376BFCB8ULL, 0x62E3F9FA114E36C3ULL, 0x5D7F6D6D97CFBB7CULL, 
            0xC97607128214810CULL, 0x5866300814F2C290ULL, 0xA6E95641D7BE6D0DULL, 0xF3831AAE8A9AFCBEULL, 
            0xE2636DC5B654EF7EULL, 0x21A99F17AB034382ULL, 0x99B900C3BA53B425ULL, 0x82DBF095B840DB9FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseFConstants = {
    0x5AF02BD2DB720F4CULL,
    0x31C33B5B7FACBFEEULL,
    0x659F556490C60977ULL,
    0x5AF02BD2DB720F4CULL,
    0x31C33B5B7FACBFEEULL,
    0x659F556490C60977ULL,
    0x62D37AC042C95F55ULL,
    0x1EF4F79E4F356A5EULL,
    0x0A,
    0x91,
    0x71,
    0x67,
    0x87,
    0x09,
    0x77,
    0x93
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseGSalts = {
    {
        {
            0x5D6455240EBACF2DULL, 0xFDEEC87612E4FD6DULL, 0xA98C6F4CC2FABE45ULL, 0x41043112A8DDEFD5ULL, 
            0x7F0D3C717AAB64C1ULL, 0x11B3D56C03985F18ULL, 0xE436A95F7759C28EULL, 0xFA385215BEF584EFULL, 
            0xAD9F5C39C426F501ULL, 0x6989987BB2D3A241ULL, 0x301471023DF329A9ULL, 0x5CD651C7514CE794ULL, 
            0xEA1A793D0F23E42DULL, 0xCC3CC4ADC4B31331ULL, 0x6C4E87DA02DD9A76ULL, 0x68B50DC21BDE8563ULL, 
            0x704FE232802FD18EULL, 0xE8FAD2B2EC6402F3ULL, 0x6BD23F895E28C741ULL, 0x3AA3451C2111DE2FULL, 
            0x77EB44D344D11982ULL, 0x9A170FF7BD628E06ULL, 0xB2048120C8A2ED02ULL, 0xBAB9F5ECAB782270ULL, 
            0x9FA34AEA993D91DBULL, 0x51F8018E5CF4B51CULL, 0x55D66A50E3829DDEULL, 0x9D16F17168C2A6F3ULL, 
            0x5A3CCDFA0202005EULL, 0x2593F3E07DF022F7ULL, 0x9623B2F9DA184652ULL, 0x09AF0F367D331E53ULL
        },
        {
            0x5CA385ACE87E46C3ULL, 0xD1DA2CE1FC28F568ULL, 0xB842744A61ACFACFULL, 0x4E7FE7E74A3D875AULL, 
            0x7E374E511D794D2BULL, 0xC16BD9C916E75656ULL, 0xA78D798C2122F24DULL, 0x8ED0E1A9D138F34DULL, 
            0xCFCDDC869F685A8DULL, 0x40E9D1F622C5B901ULL, 0xA714DC915B19CF27ULL, 0x7BA67581A6DC09FAULL, 
            0xFA6EE1AB75DB6FB3ULL, 0x289FE2078AD4789BULL, 0x481115FDC45C165DULL, 0x30F1451E9D3626BBULL, 
            0xE38D2735773F0182ULL, 0x020398456881DBD4ULL, 0xF60B6EB0A7CDA053ULL, 0xA6F92D82312BA9CFULL, 
            0xE7ECDD50F53FF170ULL, 0xA6C51E37A9522EA4ULL, 0x830A7EC33BC59DD2ULL, 0xC57E4A4AEF8DAE3CULL, 
            0x146A910408BAF8B6ULL, 0x01CC52D8AF57638EULL, 0x6BA78E25D927D841ULL, 0xE79E387A158113C7ULL, 
            0xF4391D06F94A4989ULL, 0xF9F173E38B95AF51ULL, 0x47710337861D50BBULL, 0xF379CE8D0221730AULL
        },
        {
            0xD1BC0151AF7C664EULL, 0x2056448FFCB31996ULL, 0xE90BA07DEB106305ULL, 0xD10014FECD19036BULL, 
            0x5CF21C61F093B4E8ULL, 0x68BD17A738C967F7ULL, 0x99F2227041A8B07AULL, 0x134E46EC034AF5ADULL, 
            0x90414F9F45FCAC74ULL, 0x664211A60C5F4E14ULL, 0xEE460E70635591D7ULL, 0xE4C9BE141B13255BULL, 
            0x596A1A592921EC48ULL, 0xDEAC38DB550C708FULL, 0x2EFD091BD944C5EFULL, 0x9514050CFE89C9D7ULL, 
            0x339F03FC67147F8CULL, 0xB96467DE857DB0FFULL, 0xBB693F6CCC6ACF90ULL, 0x0560049A0686CB79ULL, 
            0xE2FF2CC10016125AULL, 0xA75BEDA4F3918EE8ULL, 0x149029971334FF57ULL, 0x2684E4E221BD90A6ULL, 
            0x929C297575A1BCC3ULL, 0x2B16CEA157CCB28CULL, 0x68275692FEA79A96ULL, 0x5410383B81543E33ULL, 
            0xC698D7A938B52243ULL, 0x08FA2E2680410CB6ULL, 0x6D20B0F104F89077ULL, 0x9F8EC2706D44CFC8ULL
        },
        {
            0xD2F2D59D7DE8F4CAULL, 0x8BBCD1E377F1D1A0ULL, 0x939C09C9874CABACULL, 0x01CBA68CC0BAC07BULL, 
            0x6772C2F32A14D3A1ULL, 0xFAFDC1A3093E59F9ULL, 0x8DAE24F556858FAEULL, 0x8BA2FC7E2BC6B4EBULL, 
            0xC0BFE6FC3B874FB9ULL, 0xBCB329FC3AF4C7FAULL, 0x1E48F678BB366DBCULL, 0x6F06F299A9D653D2ULL, 
            0xDBCD7A562D2B9FE8ULL, 0x4835A263CB23CD13ULL, 0x1F6FC4CE23BD16D8ULL, 0xA7C70CEABB485010ULL, 
            0xF52F3691C8196413ULL, 0x688C78E7E285F1D4ULL, 0xE2FC20AB06632CE7ULL, 0x3D57766714D21DFAULL, 
            0x9DE8D2DAA19A8BAAULL, 0xC7E65EC26B7D35BDULL, 0xA21311570898F2B1ULL, 0x57A30C127476D4DAULL, 
            0xC0C6F3123A0BDE88ULL, 0x5B0E1B2F0E19E177ULL, 0x114444A4AC4B90AEULL, 0xB917116B749A0FC4ULL, 
            0x08F7A667B8DBE8E1ULL, 0x4860CAFFBCE45505ULL, 0xFA2CB08C37D1FEE1ULL, 0xF833E342676C1A94ULL
        },
        {
            0xF4644BFBC7FC8897ULL, 0x0BD0B6FAF1E1E5E1ULL, 0xAD11A5DA7E2CCD72ULL, 0x076F5E6FCC205E8BULL, 
            0x357060872CBCE6DBULL, 0x5DB78AB8453E87B4ULL, 0xDBB4D59118E30103ULL, 0xC1901B4CD4FA8D8FULL, 
            0x9BF615ACA306AF4FULL, 0x9A83ADCD92C2030DULL, 0x5B8730D5085CDEE3ULL, 0x1FBC2C3278FDC80FULL, 
            0x4FF4601C6EDB5157ULL, 0xA0D9B381D830B0E0ULL, 0x9BAB407FC8F56C36ULL, 0xECFEB4F8B717A342ULL, 
            0xEF53CED9A8DD9D65ULL, 0x6E7B54180CCA5528ULL, 0x902C7A5D39D12AA4ULL, 0x15B7251677574173ULL, 
            0xFF34AAB27C657E9DULL, 0xE88CF37F69A48604ULL, 0xA72FADCA160D530DULL, 0xFC6DE162208752ACULL, 
            0x14BC90F0B3783CA3ULL, 0x127AA946099C82B8ULL, 0x9E337C6C532A5FFBULL, 0x7D0B8C4A77174507ULL, 
            0xCF00CCDD56FF9DB8ULL, 0x175E3B4DDD4CE9ECULL, 0x7ABAF7372F9F6F57ULL, 0xBDA51532BAF7BE19ULL
        },
        {
            0x3DCDD65E7AFC9CA7ULL, 0xD3423C621F9497EAULL, 0xFA03595EC1A15C7AULL, 0x9F1DFF51630384C1ULL, 
            0x4AFCE91962F70EE2ULL, 0xCED1A6DB08AEE4DEULL, 0x5946A7FBCFE29828ULL, 0xD3D4F2319B913596ULL, 
            0xE7FFCA14F2F6363CULL, 0xD59C267B509CD074ULL, 0x95689FA22C680440ULL, 0x458F7520F036F11FULL, 
            0x5C2D2FCDCC8BA1F1ULL, 0x0B9163E95856273CULL, 0x8AD091B7FE078AF9ULL, 0x53DFB14B9CB5784CULL, 
            0x3908F16BC93BDC70ULL, 0x872939B724D4CDE4ULL, 0x01ABCC40190D40A4ULL, 0xE794372850AF82A4ULL, 
            0x2CD350690EBB76F9ULL, 0x3E38B538DA06CF30ULL, 0x2584536FAF81D2EFULL, 0x5C2004BBA571E302ULL, 
            0x3C82E30B2AA1A0EBULL, 0xFA1545D0BAAFA0EFULL, 0xF316D51A0A7AC91CULL, 0x856FF636296A29F1ULL, 
            0x671C7EF9FCA627F3ULL, 0x2DA136BD78A2B3CFULL, 0x30F08B3BC2E73636ULL, 0x063B578A8579FF68ULL
        }
    },
    {
        {
            0x36E0FB6EBC1B02D7ULL, 0x19441D61F255419FULL, 0x7BF7995CFD7FF761ULL, 0x399B2B680B36401BULL, 
            0xA9CCD58977F8B3ABULL, 0xDBE9AACA4299E3DBULL, 0x691A11DAD1121F78ULL, 0x59D485B9802FC34BULL, 
            0x5A8589A661F5F027ULL, 0x78509797BDE3585FULL, 0xF4BBEC10A1150199ULL, 0xD0A248E1A43852B1ULL, 
            0xF903EB1C640157DAULL, 0x8081BDB19A99ED74ULL, 0x51EB95AF80A9D902ULL, 0xA952921357997DE9ULL, 
            0x9F6E0078C6385707ULL, 0x5D413DB9600C210BULL, 0xC665ADE06AD9514FULL, 0x8946DB6C34A7853AULL, 
            0x0E391C0A2B8FB04AULL, 0xEC9B628E625A0A0CULL, 0x72907F3D6CA148FFULL, 0x259BD704571F1386ULL, 
            0xFFA2CE105A945ACAULL, 0x27A9E5165CD6795FULL, 0xE9B817C5658BD356ULL, 0xB51D9C063CA256E0ULL, 
            0x8E9F6A04ACC9FAAAULL, 0xD5DF4421B89CD6DCULL, 0x370A9BA63C19418AULL, 0x948265FB7B1C1A1BULL
        },
        {
            0x475C9E9FE9AE8BABULL, 0xD7EB9DBDA0A58E6FULL, 0xC8038065CB69FAA5ULL, 0xF4D0768CFFCDE3EEULL, 
            0xB3C03074C70B281DULL, 0xD38A311DBB61FECEULL, 0xEFFD35780A12CBB8ULL, 0x64668C60F6405CAEULL, 
            0x5163E1B16F191395ULL, 0x367782657F33FEC5ULL, 0x83013A55AF801C47ULL, 0xDE72EC67277B30EEULL, 
            0x7BB2F6BD772E5EE1ULL, 0x5FC19C92622018C9ULL, 0xB287A1DCE9B18241ULL, 0x19967065729CDDE9ULL, 
            0x5FC35B693496E8F9ULL, 0x589698B946BA6BEBULL, 0x7E7866CCD5589BD1ULL, 0x7251D06C0A700900ULL, 
            0x3D20DE6352E34F0FULL, 0x40F970EDB5D87844ULL, 0xC62A5F19E0BC896AULL, 0xDD8AB5033A8002AEULL, 
            0x6039EB6F1C1EC9E7ULL, 0xC97C7E5884D218C1ULL, 0x268E04DAC3F2EA21ULL, 0x5B9A723CFA82E9DAULL, 
            0x38CF243B42862C32ULL, 0x0D45503291896A49ULL, 0xECBF57C515907F54ULL, 0xD9FF4130B865DE42ULL
        },
        {
            0x4BE280B11A2508F1ULL, 0x8304765CF03DB04CULL, 0x03617C9B9B811CCFULL, 0x312B5337E62071A4ULL, 
            0x559B2B3C9A8AEF97ULL, 0x4089D37869DD61A1ULL, 0x968B437BB40A2625ULL, 0xBCB37E0ADB7CCBC9ULL, 
            0x9B63681B0942BCE2ULL, 0x94FB8909B321938AULL, 0xCCE4EF95F4F8E4A3ULL, 0xB18D312A3C3DD44AULL, 
            0xFD401461C9738FBDULL, 0x774C3028DE395C3BULL, 0x655F7C59FEE165D8ULL, 0xDBD4E4D18CCABBB5ULL, 
            0x1B646A641E021360ULL, 0x21D32DE19436F26FULL, 0xFFD932D7C6872636ULL, 0x067DD0204E30F3A2ULL, 
            0x0A66137E323EFA13ULL, 0x99CE71179FDFA627ULL, 0x88DFFBD00BBB3633ULL, 0x6BFD5432B549BC16ULL, 
            0xD62C3E2E92972F57ULL, 0x13AA998117935706ULL, 0x70A48A8B745F1FB1ULL, 0x06A1FF2004AF0192ULL, 
            0x63B09B50AFE38E82ULL, 0x2BE88F6E70AE03C3ULL, 0x52016719FBA98CA1ULL, 0xEDE355DEA9DAD407ULL
        },
        {
            0x6EEA02363811EDB2ULL, 0x6D2E73C18E844D6FULL, 0x3AA13BADE2AA294CULL, 0x3F10D642A9B636A1ULL, 
            0x23E200AD0E5FC8C0ULL, 0x6A5C686364E69153ULL, 0x92FE0AE84A5579B2ULL, 0xFBEDAD8304BDA71AULL, 
            0xAABC16E131607C90ULL, 0x5B0F2664D3EC8986ULL, 0xA792E5A032126590ULL, 0x1DEF5E356990B377ULL, 
            0x4D224E4D3783575CULL, 0x77380B64A27A97D0ULL, 0xD1B3139B60E2E355ULL, 0x422300A83DB32309ULL, 
            0x1F7FC295B97D67FCULL, 0x5AD41768A326E63EULL, 0xF5F7A273F735C585ULL, 0xECC58C4F6C81EBA7ULL, 
            0xC6E0D72DE52AEA4AULL, 0xA7DB4C7EBB133B42ULL, 0xD7918E459BFEE5CAULL, 0xB3494B9787219690ULL, 
            0xB1ABC64D643E82C3ULL, 0x4916BABE0164D817ULL, 0xC0A9210ACA6798D8ULL, 0x4D2687F1B91A1B9AULL, 
            0x65B448BF0A40C5DFULL, 0x0996C1B33D098809ULL, 0x933064541AF4B588ULL, 0xC894C45059E793ACULL
        },
        {
            0x908EFEA91132E3D3ULL, 0x16F1EF5E159C2A35ULL, 0x3FF900391E82F07BULL, 0x580665FD3944E76EULL, 
            0xB8804F67D6945BF1ULL, 0xA20833D1ACE4CAEDULL, 0x7EA4C2C2D168A578ULL, 0x952C30522C512D6FULL, 
            0xEDE9FC247A33CC9BULL, 0xD91D7F98D1A51305ULL, 0x60DC08654E0A6C19ULL, 0x2722BE622FFA0DFBULL, 
            0x14814F8676D909B9ULL, 0xAA87DC4DE7447DEDULL, 0x0589E5ECDEF7BA87ULL, 0xA42A94D4D17574D1ULL, 
            0x3954DAF59A421B82ULL, 0x20AFD546AC82FFE8ULL, 0x9444317DE9970B9AULL, 0x9E34ABFAD2362A71ULL, 
            0x5812FFBB9EC90C2EULL, 0xB0CDF0AC9137CC05ULL, 0x524C77C0791ACC39ULL, 0x4725773E526E876EULL, 
            0x4DF6995B935E872FULL, 0x3843F0D75B57E5B3ULL, 0xBEB10FB0657DBD09ULL, 0x7247E116DD0BD24EULL, 
            0xB1ECA65C5A3C2B48ULL, 0xCEF8700F10498202ULL, 0x227C92559CAC1B1EULL, 0x77FFEB88356EF80CULL
        },
        {
            0x48F8FE101023A6A1ULL, 0x7173F9C4C429D833ULL, 0x373B098D9C2C2E20ULL, 0xDFFC2998AED27A0FULL, 
            0x87F31A09860B6D1EULL, 0xACCAFEDE99095E10ULL, 0x1EA1A94F20FD3515ULL, 0x5CC3093905B96321ULL, 
            0xE467C0630C3E0D31ULL, 0x6DF85F3F6DC9B5EFULL, 0x50AD690983348C3EULL, 0xB74E34903EC12CE4ULL, 
            0xBE42F81A6CF314CAULL, 0x5920A815A4C8E179ULL, 0xAF188E4F5E4C5C02ULL, 0x6C486032301A4A81ULL, 
            0x8CA21D191E775F2FULL, 0x89AF878E6F21C24BULL, 0xC5C91DFDC3D87875ULL, 0x46FFB7B394DD2D18ULL, 
            0xA74BC5CC21F4260EULL, 0x370D3477B1A70D03ULL, 0xF5443B4A335ADBACULL, 0xA18DC128E6C7F0E9ULL, 
            0x89E64F46E3A085DEULL, 0x71C4023441D8C9D7ULL, 0xCEE4117D7092A7CCULL, 0xB851A91BACF7A92BULL, 
            0x4FBF83D30489697AULL, 0xE0E91DE04609239AULL, 0xF714CD8F29853F91ULL, 0xF5EE25F9A0D38545ULL
        }
    },
    {
        {
            0xA9D51F5768085FB9ULL, 0x3F7392733FBF2D55ULL, 0xC55292008C065E64ULL, 0x3A487648DB4FE093ULL, 
            0x67A6AEB405B9C72DULL, 0xF61DF3392B1BE199ULL, 0x0C1919D010E8F0A1ULL, 0x13BFB2F1DC4540FEULL, 
            0x44D8599B89C4940AULL, 0x48DF709774A11733ULL, 0x465963EA89F251B1ULL, 0xB997F908A89B515AULL, 
            0x723C7DBD7AD28708ULL, 0x7F87A54B920CFAF7ULL, 0xAF1F0E428B971208ULL, 0xB3394F1B2A91F500ULL, 
            0x236C016BCF7DD33FULL, 0xC90B5D8C5EB3065EULL, 0x9523B33C727E4F51ULL, 0xDE53EC45097BB386ULL, 
            0xF7A8E64FB63CD830ULL, 0x703C4A36F4F3C9B9ULL, 0x332243A54131426BULL, 0x77B87EC092D40318ULL, 
            0x515BA0BF3F5F8457ULL, 0xF793B813E437268CULL, 0xBEE125D8C7C6B668ULL, 0xD81E7C79F249450BULL, 
            0xBE3CA998F718CED2ULL, 0x99C2DAEE8019DC14ULL, 0x94CBD408F3A3FD9CULL, 0x7FA65F44073239C4ULL
        },
        {
            0x9DC3A413F7700095ULL, 0xD50765439CDF401EULL, 0xE754D1930B0DC441ULL, 0x3A78D59638C82D56ULL, 
            0x654A00F98DDD3A17ULL, 0x225A00E348CADFDEULL, 0x087230A9532DFA5FULL, 0x3A2887FCBE068A61ULL, 
            0x986ADD5A372B0720ULL, 0x3037CF01846EEA8AULL, 0x43A00217DFFBDDCFULL, 0x09DB2815B8F6ED93ULL, 
            0x9213E1A5E7BC6F6EULL, 0xFA2DE3132684C6A2ULL, 0x5F8E0C2C6B6A253CULL, 0x5F434800F830D6DAULL, 
            0xAE0DB0FC87372E10ULL, 0xF766DDCB34319BEDULL, 0x3EA954C4C22ABF91ULL, 0x2709F1105EEC003FULL, 
            0xD30B0FDC5F32962DULL, 0xB74A79B37075A018ULL, 0x542D50A9590A4CCEULL, 0x83787222DF85142BULL, 
            0xBF216A31E24546DEULL, 0x14E43AAE2B26A59BULL, 0xDB9F64B6C4E032A2ULL, 0x95DDD7C8D2E779D3ULL, 
            0xA022D5CB99B66B78ULL, 0xF06334928356FC84ULL, 0xF38371918101DB6AULL, 0x2454D7B593D72FC1ULL
        },
        {
            0x2F5527408CDCC293ULL, 0x37ECC4C0CC01D6CDULL, 0xB90DAA442701D3F5ULL, 0xCBCCFC09A9799FF5ULL, 
            0xE44ECF7FA0DBAC99ULL, 0x06F01C7AFF731B16ULL, 0xA6FEF5086A66B312ULL, 0xC11925F6C212EB70ULL, 
            0xBB819989CB83CCA0ULL, 0x4789B7CCB4F81B29ULL, 0xD467923F9D81454DULL, 0xA638C784ED7EA629ULL, 
            0x84F182B44C5D6BFBULL, 0x83B389F1414F45A2ULL, 0x7A1E49DB4E733573ULL, 0x55F76450A50C4A27ULL, 
            0x41262F73410139D2ULL, 0x31F807038BCEDD3DULL, 0xFE483133B24AB7C1ULL, 0x890676491224BE26ULL, 
            0x5E2E9E18F7CB8C08ULL, 0x90473424BFF224C1ULL, 0x11FC895DA227E67AULL, 0x4E90A83FF2D2CAA4ULL, 
            0x62341685EB892DBBULL, 0x8E396770E4A47CF6ULL, 0x9A6A12F972BCE45AULL, 0x6DB945F7ACA275F9ULL, 
            0xA94A451AF0960DECULL, 0xBFF4703EE2C49F38ULL, 0xBF37087589D3BEFBULL, 0x9AD6EDE759A665CBULL
        },
        {
            0x0948D056244FD185ULL, 0x9D8A7AE0BB119E16ULL, 0x6E2726AC180C3266ULL, 0x3D91F9E826F61D80ULL, 
            0x3E8A1A67901150ECULL, 0xCF3097FD45132B8FULL, 0x625BBEAC7A8F1E0BULL, 0xBA02390EF39F02C8ULL, 
            0xF067640D40F972A9ULL, 0x0DF09D59F648497DULL, 0xA0B8F5CE4B5A1C8CULL, 0xB1BABEDF96E43F60ULL, 
            0x50378B349CA60103ULL, 0xB1221B74A280AE65ULL, 0x80BE20E0BAF898A5ULL, 0x51129029E9AD8A0FULL, 
            0x95E1AFD00FD91FA8ULL, 0xF6DDCBF39003831EULL, 0xDAA9D21487384B15ULL, 0xD40CFB8CD4911B32ULL, 
            0xF257FDC03E0F05EAULL, 0x0073A436B0C0A785ULL, 0x71A033F4419874D4ULL, 0x5A165EF7554347F7ULL, 
            0x6B692FC6267C7F7DULL, 0x3A7246642791A8CBULL, 0x72254F385BAFACC8ULL, 0x592E59F92715FDCAULL, 
            0x26A0583180D07B5AULL, 0x46E890B0BA351C5FULL, 0x9117A46A33700BA7ULL, 0x650B2D5159390507ULL
        },
        {
            0xFBDFE73180222D2DULL, 0xB5C02432AB68E5E0ULL, 0x1FF8E10C0FDD7CEDULL, 0x665147ABCDF64AC7ULL, 
            0xD1821E2DEB58CF2DULL, 0x2E4BEF527EF22EFFULL, 0x4B821248984E85C9ULL, 0x597034C6B4865FABULL, 
            0x5B05156BA37B4493ULL, 0x2F4B612B68826E57ULL, 0xDAA911FF80B6274BULL, 0xCA9434106E6EAECCULL, 
            0x4E5C83838FF41291ULL, 0xED2AF1FCCCDE1A79ULL, 0xF889719B081CC5BDULL, 0x0057934E0A474DF4ULL, 
            0x31D71EEB5FE74AA1ULL, 0x501ED6CE1ECC0320ULL, 0x4A4ED021C80FA297ULL, 0xF1939E11B47667B6ULL, 
            0x66309652C3EF6169ULL, 0x0A6683C09E6DD788ULL, 0x8D83CBC51C1E3C6BULL, 0x0D267531ACACA81FULL, 
            0x58DCACF5FC43026AULL, 0x8FAD44AE9D67919EULL, 0xC9AFB920E3A898E4ULL, 0xA5AB0FDAA40D7AA3ULL, 
            0x0C9D6AC39E0EF534ULL, 0x9A2D6AA68A1EF97DULL, 0xAF2BF615F6DCEE21ULL, 0x46171ABD4346B800ULL
        },
        {
            0x2DD02421AA103521ULL, 0xCCFF750058141CD5ULL, 0x587E73E99FBFB03CULL, 0x55D10759610A6A82ULL, 
            0xF47DED6791E3B47FULL, 0x8112AC3C74AB519EULL, 0x3678A3F5DAC93426ULL, 0x82F2445EA1EED8F7ULL, 
            0xB5B823FFD96D386AULL, 0x3A20668A22E6FC88ULL, 0x755D305DBFAF422CULL, 0xDF6B0FE9BFA41A4FULL, 
            0x509B2BDA64A102E0ULL, 0x30D49F6FC140A7E4ULL, 0xBDCBB3C2211FEEEEULL, 0x10AD0A72FFC23C3EULL, 
            0xAE9C9A6EF7CDB857ULL, 0xD034ACCF66E23A32ULL, 0x4713A737A8F006FCULL, 0xC7159C7AD4A3E0D8ULL, 
            0x5426A927098584D8ULL, 0x6AFFCE07E1342958ULL, 0x6C123943B2916E21ULL, 0x711E147CE0C86C97ULL, 
            0x02CFBDC693073ABDULL, 0x34EA6F6EC87E425FULL, 0x0B88261CB785186CULL, 0x481AD145D6045392ULL, 
            0xDCE27635326437ADULL, 0x2AFFABD7BBDCB21FULL, 0x068BDB7447CE422FULL, 0x24C8E90183A02F6DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseGConstants = {
    0xEEE7E8FB69630513ULL,
    0xD3EE08781B5012ACULL,
    0xDFE1C427F3DA44F1ULL,
    0xEEE7E8FB69630513ULL,
    0xD3EE08781B5012ACULL,
    0xDFE1C427F3DA44F1ULL,
    0xCAB6E1B432196A58ULL,
    0x1655B4F678135C10ULL,
    0x83,
    0xC0,
    0x2F,
    0x91,
    0x30,
    0x81,
    0x70,
    0xEE
};

const TwistDomainSaltSet TwistExpander_Cricket::kPhaseHSalts = {
    {
        {
            0x524EDBC0F6B86187ULL, 0x9F222C2D18FD0726ULL, 0xFFB8B59C9CBBA92AULL, 0x8F7A3158F9272980ULL, 
            0x042165594F1157C0ULL, 0xBCE98731A025390CULL, 0x3F375AB3D1F5F19EULL, 0x2541441C7ECE5578ULL, 
            0x114E80C9431BE272ULL, 0xE83AD3504E06B0A5ULL, 0xD50A45B642C540FEULL, 0xA09C0953AF221109ULL, 
            0x1C57D117A07DF77FULL, 0xCC76732A59A9F47FULL, 0xFA089BA54A9433D8ULL, 0x67AF912E42ED0695ULL, 
            0x58241ADD3ABF4286ULL, 0xFB9A98B319CDEC5BULL, 0x83E6D500569F3059ULL, 0x52146EA860935D64ULL, 
            0x750F05C3EF89C77FULL, 0x6428CA19E9EA04BFULL, 0x5B1D75B5960BD1FDULL, 0x04AB20ECEBC2AD2CULL, 
            0xBE9FF76354DF65B1ULL, 0xE516C2D0D4980397ULL, 0xB9EE4D8B399CDB38ULL, 0x1B22746AF83B8D98ULL, 
            0xAABB3E561952D944ULL, 0x8E051B717A1C7719ULL, 0xCAFBE1C7EDA15F97ULL, 0xC03CB485A34137F1ULL
        },
        {
            0x15B26FA73997C4A8ULL, 0x4DC48479A56D7A85ULL, 0x7EEC2A1B0CE85CFBULL, 0xB3CD2B13EBE8A7C5ULL, 
            0x092F73F46D1FD976ULL, 0xE1E86FC2BF85DA6AULL, 0x45AB50F6E720B942ULL, 0x9F7669531443CA3AULL, 
            0x5B3A99B1B2DF8680ULL, 0x658F02548085A73AULL, 0xE6E83C966F120110ULL, 0x3DECBE24C0CF8B64ULL, 
            0x3242392FB3698276ULL, 0x7E2A6DE59165C17DULL, 0xE37C0165F525BC7EULL, 0x51F40AFBCFD9E0B1ULL, 
            0x8431C28585F87734ULL, 0x9329699E333A2B9BULL, 0xF53536D6E5E734DAULL, 0xB4B73D8536928503ULL, 
            0x0CFB6ECEA62EB294ULL, 0x0FE982AE87137E77ULL, 0x687EA8A8F55D4D97ULL, 0xF6C4D0B6631E1A1AULL, 
            0x008367E3A82BB73AULL, 0x3C2A7A76E4F509DDULL, 0x3D2F0A463EF11D79ULL, 0xDE71B3D6319EC46EULL, 
            0xC45C077204C510ECULL, 0x4976076FF353542FULL, 0xEF89BF3A1A498A47ULL, 0x9A4E1EEAC6463989ULL
        },
        {
            0xF7E2F11E22C8B62BULL, 0x64DFD1AA9BF9FAF5ULL, 0x3C7509FB37B49D3BULL, 0x2E2F5C51B537F779ULL, 
            0xCA7C16F26B111EFCULL, 0xB07968A47AE112CFULL, 0x7AE1B316C8B1F407ULL, 0x05AB2720B6DBD1BFULL, 
            0x9DBBB330CAEF43CDULL, 0x063A8974DDE0E0DFULL, 0xF6E81FCCE72A5E37ULL, 0xCCCEC323D0BD5768ULL, 
            0x4178F3C421022A5AULL, 0xA109F0D5248B24BFULL, 0x417A41F65B61076AULL, 0xAB7AD6DE869D93AAULL, 
            0x382421D2F42774E1ULL, 0x51C52820E3D8B945ULL, 0xA23EA2551C162E1AULL, 0x36B6EF3DC9559F26ULL, 
            0x81325A8A6141B311ULL, 0x6DD33A57293F6883ULL, 0x68BC0E0205587D02ULL, 0x867AAF42B6BEAF1CULL, 
            0xDA9264BCFC7BC2C2ULL, 0x32DE98520FC626EBULL, 0x9C68A7B256F38454ULL, 0x6AB24D9227D48900ULL, 
            0x36059CF4BD04E5A9ULL, 0xA72590478DC979B2ULL, 0xC24BE7BF8AA5C60CULL, 0xDBB759BBFDE45418ULL
        },
        {
            0xC28CFDC6C1FB0888ULL, 0xE08A148890214723ULL, 0xBF853DDA464F4CDAULL, 0x974A28D436A953EFULL, 
            0xD6049FF7ACE8AEBBULL, 0x7F7B9FAC16BDDA63ULL, 0xA85DCB4C7E6D6970ULL, 0x7280D21FDAEFE01FULL, 
            0x81B37478EC7E91E4ULL, 0x8F2010D87C4EDF78ULL, 0x5FA3E54C386060FEULL, 0xE41AB6AAFB35F290ULL, 
            0xCC4E202DABD3C83EULL, 0xAEEB3BE1CAFF4F27ULL, 0x5E46E0D2BB568748ULL, 0xB1A18BD509C28820ULL, 
            0xA39202B709A661BCULL, 0xF4DD462A8086F4A5ULL, 0x7BFE1FFC358DBA1FULL, 0xAF8050B8D276FF45ULL, 
            0xB080317816EF4D48ULL, 0xE8503868DE850DF2ULL, 0x802E89F56EC16FB3ULL, 0x958360B47862A810ULL, 
            0x464B52528258D0DBULL, 0x8EB75B051BC41935ULL, 0xF9EF53748C165628ULL, 0xC11C1A4AD61639C8ULL, 
            0xC6877FF843F1ABBDULL, 0xF3D773C108DAEB67ULL, 0x30600F1A7FF0258BULL, 0x4DF0A6BFAC1D6823ULL
        },
        {
            0xC145461D5DF2A576ULL, 0x4D0735C49EFBCC84ULL, 0x94CF266A554B1087ULL, 0xA968637422E1D551ULL, 
            0x5656E32FF769DDCCULL, 0x3809179A73BE60CAULL, 0xE06B5C8E636A6BA8ULL, 0xA710ECE690152C31ULL, 
            0x8E489987431CCEBBULL, 0x4D8AD765CC493F68ULL, 0x21FD47FFE824062EULL, 0x3019D6CC5EAAB457ULL, 
            0xD6B7A3B0FC4F3641ULL, 0xA6ED95CBE8548888ULL, 0x8BE59F314B3685FFULL, 0x8B80F2B5BA386583ULL, 
            0x1192B40BD7C4105EULL, 0xC1DCD4729F9ECC0FULL, 0x94343DE6DE725BD1ULL, 0x95B4472B04AD5DBAULL, 
            0xE554AE81C47B16D2ULL, 0xCAD59F763EBCFAEAULL, 0xCC66DA3FAB131AF2ULL, 0xC8935A78435C2F56ULL, 
            0xE0A692055BFCF4A3ULL, 0x78882A40A5247A37ULL, 0x9D1A5191CACB54BDULL, 0x85A824A60C45BA5DULL, 
            0x6D9CA99166BFF6ABULL, 0x30D1CB1E202F23C7ULL, 0xB65D93C04AC85CC1ULL, 0x1094DD9BB72918D4ULL
        },
        {
            0x356E0FABF5B07D29ULL, 0x97E4D7FCF3F2E6BBULL, 0x312CB513AD44EC47ULL, 0xBF16F55A088E6315ULL, 
            0xF62C06B95868FB92ULL, 0xD2B93E45D4576BF7ULL, 0xB1577B3561BC9430ULL, 0x78FD1DC0387C283FULL, 
            0xEB09AA456C2D4170ULL, 0x592F0740C8B4FAF6ULL, 0x7AE0031A5504EE0FULL, 0xB229D404E123DAB6ULL, 
            0x275D419E474399BEULL, 0xB81F65AA09EC058AULL, 0x8CB494E6B7B59F20ULL, 0x94D4C6BC02D108E4ULL, 
            0x27AD277B11182848ULL, 0x788631BF33990629ULL, 0xCB1AE75D5852CE0BULL, 0x2022A0D2FEDA7C9AULL, 
            0x79025609C07A9376ULL, 0xC360F26E294EFDF8ULL, 0xF245EA824E3148C9ULL, 0x84EE60D17B7127AFULL, 
            0x7B08B283749477E8ULL, 0x945B01594EAFCE74ULL, 0xCF26860A5598879FULL, 0x79F3B48CD4ADC538ULL, 
            0x933779382DA42AA1ULL, 0x5080133B788827CFULL, 0x74813A89436335E8ULL, 0x680FF02FAAEEFCB8ULL
        }
    },
    {
        {
            0x93FFEF25956043D9ULL, 0x3D6E98F6B45DF290ULL, 0x8BFF0FF42BC750F5ULL, 0x2BF3CC82F198B71EULL, 
            0x9F6560E5BB7246DAULL, 0x82401143BEA49225ULL, 0x49AFBA33053A63C7ULL, 0xF1A9060B72F5B675ULL, 
            0xDC3D707548CD5028ULL, 0x337C9B54C68A90D2ULL, 0x1F8661AFFFFAD72DULL, 0x2B2B0B444F88B0BBULL, 
            0xF67D1D8870AC0E60ULL, 0x5506A563A0177CD0ULL, 0x0F7BAC8A9D8BDF73ULL, 0x29228C5867BC0248ULL, 
            0x8A1F2F2A7E578701ULL, 0xAAEDCE600CF11B0DULL, 0xD40C5721D1EAD21BULL, 0x6C9F26EDC5D0591CULL, 
            0x058A7C7595D32CAFULL, 0xE8AFB8348D3E9721ULL, 0xF005159BB33DDAC2ULL, 0x564607A505E9EEAEULL, 
            0x7C391480A3DC7580ULL, 0xB038964530C1A190ULL, 0xE50A1DF3B69CC2A6ULL, 0x7147BF20E19886D5ULL, 
            0x4A410E4C108E5BADULL, 0x4BE141DC0812DAD3ULL, 0xBE34362D4901B8E0ULL, 0x00A437B465B6B878ULL
        },
        {
            0xEDA143264FF03C1CULL, 0x5304D63DAAEE8C22ULL, 0x9A2CD918D9B99D4AULL, 0xEB0F90EE5FE90782ULL, 
            0xD1F4DF87535CDC38ULL, 0x53A3D29EE2BF4F12ULL, 0x6C8F610C88AB106AULL, 0x063AC6E5254CF149ULL, 
            0xDB48CA51DA0478F7ULL, 0x998B838D1719799FULL, 0x93929D5C52BE4C48ULL, 0x4F24156284B23727ULL, 
            0xCA724F9E41883ED1ULL, 0x2240AD9D18720314ULL, 0x6F40223C8A0E60BEULL, 0x7F31837577718AE0ULL, 
            0x7119D7E83AF4805BULL, 0x8BDDB9D359866CFEULL, 0x80EB52602F15CE1EULL, 0xDCC4B8B42DEFAFE0ULL, 
            0xE4AC1DA1C90FD27BULL, 0x619E7032730B2A71ULL, 0x482DE41B9C974C6FULL, 0x99AC90168F3A33C0ULL, 
            0x0F650D4FC4CB24BFULL, 0x59F4223EE6851FB3ULL, 0xC7AD4BB1CAD0DD09ULL, 0x5E5673A0774F9416ULL, 
            0xCA7E81D70D97A07EULL, 0xF05FDDD9627E03E6ULL, 0x888AA7CACE845E7DULL, 0xC503B9412AFD8542ULL
        },
        {
            0x458F58ED1442D930ULL, 0x54CCC1FE38C0AAC6ULL, 0xD65D1FD35E615CAEULL, 0x4144315CC8594798ULL, 
            0x6618B666F8199242ULL, 0x217B0746CE03F0F9ULL, 0x4FE3AEAB43C4BF43ULL, 0xE578B2AFBF5866E7ULL, 
            0x494C3C024FB973C7ULL, 0xFDEE9F96C9E0C773ULL, 0xF1494C1F7BE61BF3ULL, 0x50FAFC39EBB7B618ULL, 
            0x73F07B2906037BD8ULL, 0x646082FA61EB49C1ULL, 0x2EB94AEDB55B63E8ULL, 0xB200EBE9FF32FAA0ULL, 
            0xA50546C6B1F8B45EULL, 0x8FAD544272034B10ULL, 0x9181EEF29C9A9A28ULL, 0x58700A5F3F6545E1ULL, 
            0x8E22FDF80595DBAAULL, 0xC5DF6A5CB5738FD9ULL, 0x7E7A7CF3830B64FFULL, 0xC190F4C4D3FBF810ULL, 
            0x6233A4D23750BFBFULL, 0xC49F75383DD30037ULL, 0xACC49B6C2B9611CBULL, 0x09B6731DC0BE7DD8ULL, 
            0xEBD501CA40C586ABULL, 0x0FD10E734FA80FDBULL, 0x6E40BB613C86D78EULL, 0x515D8F737A37580AULL
        },
        {
            0x312C664728E7B5C1ULL, 0x22D8D7052F7A44C5ULL, 0xC72A114A561951D8ULL, 0xBCCC7000F3264C01ULL, 
            0x63834E8189CF5902ULL, 0x99C33A3381D153EBULL, 0xBD92A6DDCE3DCDC2ULL, 0x4B9CCAD11B062D23ULL, 
            0x4FC500E8A8618DB1ULL, 0x9AF18A974F353425ULL, 0x0FD050B3C419EE5CULL, 0x5C1D18D6637C8AA6ULL, 
            0x13692F759888A211ULL, 0x45840FD7F9D0158DULL, 0x068188ED70DC7435ULL, 0xD9BD79054EC14355ULL, 
            0x59060B29D8865B06ULL, 0x0E95D0D3A981D7F2ULL, 0x5A257276B3BB34AAULL, 0x0BAA6D0414F77719ULL, 
            0x487E077035774C64ULL, 0xE4E0A1924B9E2C1BULL, 0x55D64F3846AAF49DULL, 0xF036402D2E214C07ULL, 
            0x4A024CEB0C3D7EA3ULL, 0x0AD9B9A12EA72F7DULL, 0xE3196E774D311B02ULL, 0x358D20EA75E33BBCULL, 
            0x901494EE66CBB961ULL, 0xD7C35798259ED86EULL, 0x7E99D4C48EB1229DULL, 0xF3802AD5D3774597ULL
        },
        {
            0x421CE64490A0A0EAULL, 0xFF99036D5599BCBBULL, 0xB7BC21B4B7847FDBULL, 0xF4244D05F6E8B02FULL, 
            0x2CDA696BBB6ABFF2ULL, 0x46B913EC848E592DULL, 0xAE4CEA1995982E31ULL, 0x4E01350B1D462995ULL, 
            0xD458BA2490B8FA21ULL, 0x3424B3139B178264ULL, 0x8A5B1B039E155DC1ULL, 0xB755B318F101C15CULL, 
            0x8B6937E9BB1FCDB9ULL, 0xC91837A9E902A433ULL, 0xD9E022EB960EF979ULL, 0xEF44BE3994E23A5CULL, 
            0x440EE0F3D8555FDFULL, 0xEBBDE21059FEF510ULL, 0x944BEE94DBA3DCFCULL, 0xD60E1D7C73662C83ULL, 
            0x3B7847D8F7AC0774ULL, 0x84AD2204939922BAULL, 0x32B0DE6447161DD2ULL, 0x82435270FECAE252ULL, 
            0x45B237836EA8CCFCULL, 0x9904973646E853ACULL, 0x048705918D2E76EAULL, 0x3E20451566F31F88ULL, 
            0xDF2E2230426945F0ULL, 0x46BEC4B9A283819CULL, 0x00270537DD0D6910ULL, 0x6A360724A577BAFCULL
        },
        {
            0x55312D9F865E8152ULL, 0x07F6ABEB313DCE5AULL, 0xEA9A5555220E08DAULL, 0xBB440DED223FFBEBULL, 
            0x4C4B328B567D54FCULL, 0x9EF190C51BCA9CDFULL, 0x86DADFF17177BC7BULL, 0xFFD27DA1D1F6F6B8ULL, 
            0x1B1A989DCE4978EAULL, 0x639C2A54571B9799ULL, 0x59D030638548D24EULL, 0x7834AD2E2492B192ULL, 
            0x5D40A1AE469A180DULL, 0x5CC635BC477F2344ULL, 0x1840F152CD502DC0ULL, 0xB5DDD19389CAEF66ULL, 
            0x97199D51A9DC3285ULL, 0x7685DE7728736B2DULL, 0xE6A6569E81B4CEAEULL, 0x766BE4F537D5E6DAULL, 
            0x24B4786547E93C6DULL, 0xF97A83B63F53D9A7ULL, 0xC476101E4D135FE5ULL, 0x1BEA4A860E5342B9ULL, 
            0x06528C7161CCAD5CULL, 0x97328ECC0CA5C1BFULL, 0x135B19356BC6C6D8ULL, 0xA19E09B3DEDBDCA6ULL, 
            0x0DA5EFBBEB918CDBULL, 0x7B3D70A29DC3BE67ULL, 0x9A68E66A4B0F4413ULL, 0xE4C7CBF7A4191F8BULL
        }
    },
    {
        {
            0xC77D469CE1E49D83ULL, 0xE35887A8CCB47F9CULL, 0x776AC71CF16170F2ULL, 0x123BFD2392174E85ULL, 
            0x800CE422BE0914C9ULL, 0xAD231E02580A7AC1ULL, 0x7899E770359AD6D0ULL, 0x1AA9D2CD9A8343E2ULL, 
            0x4694E02DFDA5113DULL, 0xB95197CBAF5E1028ULL, 0xB882B8B2EC1376FCULL, 0xEABA5719C1DC7D85ULL, 
            0x45F72EBFDFB92C99ULL, 0xF84871F264067446ULL, 0xEE6F89FB8B13F2F7ULL, 0x80A9861690E55E5CULL, 
            0x25C3A286F8717D98ULL, 0xF50AD2C4B3AF8EE7ULL, 0xA75A9F325B0801E5ULL, 0xF3817D06009C49B6ULL, 
            0x8068242AF84F2D19ULL, 0x44EDD0EDC9648FFDULL, 0x4853E4E045380ABFULL, 0x225D9D4640FFC953ULL, 
            0x674D6259FC5605D5ULL, 0x5FFA4D0F843E7ADFULL, 0xE65192802F66F8D7ULL, 0x7666C6394CDC24FAULL, 
            0x16A9B6C7B55B262FULL, 0x8720FBBE8F2115B9ULL, 0xECCBABCAF60C9865ULL, 0x04384DF41520746BULL
        },
        {
            0x6CC4FB0E9DA171A4ULL, 0x1B471FB2F5F6F150ULL, 0xB13A77BCE1A405E9ULL, 0xEF9B0A0740F84A73ULL, 
            0xF93FA681849B06E9ULL, 0x7C394A27785893E5ULL, 0xD1A3294F476826C7ULL, 0x3034228617B14E64ULL, 
            0x02197E2BB843FDD8ULL, 0xF2F2690C67855E0DULL, 0x6C42B84563FF3596ULL, 0x8F50AC1E419DADE1ULL, 
            0x6956B761E281213AULL, 0xAEEFF62BF2B8E469ULL, 0x4A0296BD2959A6BCULL, 0x9BC252FC59DB69C0ULL, 
            0xD29F4D3863E05B31ULL, 0x6F14191BBBDA58F7ULL, 0x7EB2EBE2D72EF378ULL, 0xAD9F193986F97A9CULL, 
            0xF375EDE0CD6C7939ULL, 0x01CF1E87C96C19BCULL, 0xC52625300A7036A8ULL, 0x7215548DEE9F11CFULL, 
            0xDBB1303B5DEB9D92ULL, 0x039CAA21F35BF376ULL, 0x653ED7B24918BFC8ULL, 0x7238DE17946E9091ULL, 
            0xCDBC8E4E0F959C50ULL, 0x9601E4D6AA0FD93FULL, 0x162D8856F133DBE4ULL, 0x43D35BF4E163DDA9ULL
        },
        {
            0xE176D7637992BF9AULL, 0x62F440937FF8D5B0ULL, 0x4100BFEBCDA16730ULL, 0x7B45BC05C7DA242AULL, 
            0x4AAC8F133E03FEDBULL, 0x0C47EF15DE88EEA2ULL, 0x46E4BB12203637C3ULL, 0x4B74FBEEA3A288C8ULL, 
            0x817DE561623EEA21ULL, 0xDAAD2FC9F3A284F2ULL, 0x161F9098504BEECFULL, 0x96ACCEDA964EF2D4ULL, 
            0xE2116379D9B7F18DULL, 0xD64CEB7C884A4487ULL, 0xB2142DC17D5D05B4ULL, 0x31F1ED3B2AF0A40DULL, 
            0xFE7342504ADF0730ULL, 0x9B0699F1D6391BECULL, 0x2DECFEC28D1555C8ULL, 0xDD11C0166522CAF7ULL, 
            0x133C07698A64168CULL, 0x1C6FC5D8D0DF8AFBULL, 0x607953D7DC2D5D31ULL, 0x6D1DA49F9F771909ULL, 
            0xECA56C38191BF7D4ULL, 0xE405BF9247C14ED8ULL, 0xC3C19F5F6884F94BULL, 0x4688B9E04123611DULL, 
            0x726CEB4F3889CF1AULL, 0xF8507BF912622C28ULL, 0x63A3BC19E793181CULL, 0x0CD4A7245B847B15ULL
        },
        {
            0xDD206DCB2E22F350ULL, 0x6A21F78D4EFF7B9CULL, 0x607F73661C028BF3ULL, 0x31415E22FADC8B77ULL, 
            0x372582B2E4E2E481ULL, 0x5886A9F0578FE2FAULL, 0x4BB4409C10C94F3FULL, 0x7A598B0EAFCF5F43ULL, 
            0x9898DA2AD6821590ULL, 0xCC0E98F141731A49ULL, 0xE8827A8AA352DB86ULL, 0x5C3B006395416058ULL, 
            0x04F2CEAE3A6053EEULL, 0x9397127D47B6D26EULL, 0x49467FD76F3817EAULL, 0xC24EDCE9AB0538E0ULL, 
            0xE79A340B51393AA5ULL, 0x4978A41ABDB16B21ULL, 0x7CCFCE39FCD6CF1EULL, 0xC4D1D28C8745028CULL, 
            0xA3EA909193E0428EULL, 0xA9CA3126537CB143ULL, 0x8DA55292B79C605AULL, 0xE80639870EDC0B20ULL, 
            0x2574C899B014B7BEULL, 0x937E2C048E3944A8ULL, 0x645ADDBE94FDDC2AULL, 0xACE7C60779B111C5ULL, 
            0x6B2F6F2065E6702DULL, 0xFBF5657B2D5C6CECULL, 0x3A6815A8337E4D89ULL, 0xE7D85DB8F3EDCD7FULL
        },
        {
            0xD39EC989E48E051EULL, 0x3A6D273E054952A9ULL, 0x784AFB46B4016CA7ULL, 0x19FEDCA44D57F446ULL, 
            0xEA652F7F2CEAE9D8ULL, 0xF63379E7971CFA03ULL, 0x2963CFD574031113ULL, 0x2B3283813A143FE2ULL, 
            0x4857D325981BBFA3ULL, 0xAA69A7C5EC75AC4BULL, 0x88121B9D6E10FCCBULL, 0x9902C6597012BB4DULL, 
            0x40025B372CEE0330ULL, 0x4A6CA37EE04902B2ULL, 0xB04A038A6B895A6DULL, 0xCF4EEABEC749FCF1ULL, 
            0x4273A11A65008B88ULL, 0x65988AE79A90B1ECULL, 0xF914FFEBCD19B8D6ULL, 0x88D7D8E2629CDF53ULL, 
            0xC4917A0008B3BFC0ULL, 0xDF16CE003E398323ULL, 0xE4EE1E959819C1ECULL, 0xD9F3116370DA6235ULL, 
            0x91DD881F129CD72AULL, 0x514CC5C8EA8F8103ULL, 0x37E25AEF2D881313ULL, 0x5D96060F89074775ULL, 
            0xAAE074A5A10683DDULL, 0xD0410B1F64C4B307ULL, 0x26F7B6D856B03B5AULL, 0xC37EFA20FF93E492ULL
        },
        {
            0xA16C4A3EB7188E9FULL, 0x689C3912BCAD76E2ULL, 0x96F09FCF6C352519ULL, 0xB327A57C092CB246ULL, 
            0x532D5C2EC84DC3D4ULL, 0x325B8F49EEDBA61FULL, 0xFC5C9DDA770C2724ULL, 0x167CC8E9FEE0BB6AULL, 
            0x251EFEE2467D2FFBULL, 0xFD57B1DD57D7896DULL, 0x408E00F9AD15E434ULL, 0x5C27011D209C22BEULL, 
            0x59F44C93BD0AEC2EULL, 0x4250D9181D689FE6ULL, 0x9F9DB09739481F90ULL, 0xE62F0FB846DD62A8ULL, 
            0x0D8C7B0F4B58B6BEULL, 0x3417EE30C5BD42DDULL, 0x916DB40B25A9C7B4ULL, 0x267EF0C637C2E854ULL, 
            0x3CAA0F04EB68C54AULL, 0x4492E7E27663389FULL, 0xD2735D71BAF99224ULL, 0xA4248CC29C06E46AULL, 
            0x14C17517640BBF7FULL, 0x43396691F0A71ED4ULL, 0x9FBCFE5D549F5C2AULL, 0x6996FCE5CB8F90B4ULL, 
            0x3CF901E3F3AB205DULL, 0xC4344829FFC02CD0ULL, 0xE4E286FF767A42BEULL, 0x9E22E204EE6C2641ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Cricket::kPhaseHConstants = {
    0xD50C9A4C3D86D851ULL,
    0x0468D3C7E0FA5FFBULL,
    0xF115E19A1D52CA62ULL,
    0xD50C9A4C3D86D851ULL,
    0x0468D3C7E0FA5FFBULL,
    0xF115E19A1D52CA62ULL,
    0x6E2C3463A947685AULL,
    0xF89D2C52DE3B36E3ULL,
    0x73,
    0xFE,
    0xDA,
    0xB4,
    0x28,
    0xD2,
    0x96,
    0x80
};

