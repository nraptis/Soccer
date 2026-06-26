#include "TwistExpander_Golf.hpp"
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

TwistExpander_Golf::TwistExpander_Golf()
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

void TwistExpander_Golf::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 13977757450012399473U;
        aCarry = 12532745159717950116U;
        aWandererA = 16846072291268511760U;
        aWandererB = 9376340914665989254U;
        aWandererC = 17618214853338039556U;
        aWandererD = 10979248997917709489U;
        aWandererE = 12559301144242305188U;
        aWandererF = 11997679801281469058U;
        aWandererG = 13442950903971295305U;
        aWandererH = 11017914823696814927U;
        aWandererI = 9921167281025849351U;
        aWandererJ = 9947006065664131016U;
        aWandererK = 14139133367780199591U;
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
    TwistExpander_Golf_Arx aArx;
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
    TwistExpander_Golf_Arx aKDF_A_BArx;
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
    TwistExpander_Golf_Arx aKDF_A_CArx;
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
    TwistExpander_Golf_Arx aKDF_A_DArx;
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

void TwistExpander_Golf::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 11464826097124935460U;
        aCarry = 14584735180189246607U;
        aWandererA = 9251800691681761888U;
        aWandererB = 16934155084505749100U;
        aWandererC = 15767984902178144279U;
        aWandererD = 16110523818088499633U;
        aWandererE = 11928226378076713308U;
        aWandererF = 16252575511596194888U;
        aWandererG = 10071822625240175351U;
        aWandererH = 9870410038512704710U;
        aWandererI = 18281760368797301086U;
        aWandererJ = 13541997697134675619U;
        aWandererK = 9994090028882793488U;
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
    TwistExpander_Golf_Arx aKDF_B_AArx;
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
    TwistExpander_Golf_Arx aKDF_B_BArx;
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
    TwistExpander_Golf_Arx aKDF_B_CArx;
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

void TwistExpander_Golf::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: cha cha 20
    
        TwistSnow::ChaCha20Counter(pSourceInput, aSnowLaneA);
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    }
    // KDF_B PhaseA invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneC);
    }
    // KDF_B PhaseB invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneF (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseC invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseD invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    }
    // KDF_B PhaseE invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseF invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseG invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneA (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    }
    // KDF_B PhaseH invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
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
    TwistExpander_Golf_Arx aSeed_AArx;
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
    TwistExpander_Golf_Arx aSeed_BArx;
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
    TwistExpander_Golf_Arx aSeed_CArx;
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
    TwistExpander_Golf_Arx aSeed_DArx;
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
    TwistExpander_Golf_Arx aSeed_EArx;
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
    TwistExpander_Golf_Arx aSeed_FArx;
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
    TwistExpander_Golf_Arx aSeed_GArx;
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
    TwistExpander_Golf_Arx aGrow_AArx;
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
    TwistExpander_Golf_Arx aGrow_BArx;
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

void TwistExpander_Golf::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Golf::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Golf_Arx aTwist_AArx;
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
    TwistExpander_Golf_Arx aTwist_BArx;
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
    TwistExpander_Golf_Arx aTwist_CArx;
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
    TwistExpander_Golf_Arx aTwist_DArx;
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_Golf_Arx aGrow_AArx;
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
        TwistExpander_Golf_Arx aGrow_BArx;
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

void TwistExpander_Golf::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 3 with offsets 7582U, 885U, 2697U, 5700U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7582U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 885U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2697U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5700U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 0, 1 with offsets 2615U, 7029U, 2616U, 7255U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2615U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7029U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2616U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7255U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 0 with offsets 5961U, 6922U, 3898U, 3997U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5961U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6922U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3898U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3997U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 3, 2 with offsets 1732U, 734U, 1036U, 691U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1732U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 734U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1036U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 691U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 1020U, 1219U, 925U, 805U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1020U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 805U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 1, 0 with offsets 247U, 1449U, 158U, 869U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 247U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1449U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 158U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 869U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 2026U, 886U, 1679U, 62U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2026U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 886U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1679U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 62U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 1, 3 with offsets 869U, 1706U, 1434U, 468U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 869U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1706U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1434U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 468U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1068U, 2021U, 867U, 1134U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1068U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 2021U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 867U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1134U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Golf::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 0 with offsets 4058U, 3971U, 2422U, 6010U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4058U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3971U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2422U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6010U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 2 with offsets 5853U, 5700U, 4359U, 7706U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5853U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5700U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4359U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7706U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 1 with offsets 3532U, 8167U, 5701U, 1064U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3532U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8167U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5701U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1064U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 3 with offsets 39U, 232U, 639U, 6330U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 39U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 232U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 639U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6330U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5696U, 1161U, 2903U, 1288U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5696U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1161U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2903U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1288U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 0, 1 with offsets 808U, 1671U, 154U, 1285U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 808U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1671U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 154U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 3, 1, 0 with offsets 903U, 365U, 552U, 1701U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 365U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 552U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 2, 1 with offsets 75U, 1260U, 115U, 1343U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 75U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1260U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1343U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 0, 2, 1 with offsets 1039U, 956U, 1975U, 1659U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 956U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1975U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1659U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1698U, 570U, 835U, 1477U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1698U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 570U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1477U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Golf::kPhaseASalts = {
    {
        {
            0x4E83B64BB62DCD76ULL, 0x1A42B44B8B78002FULL, 0xDB9AE5ED838E9DCAULL, 0xE8FE2F6C84597F99ULL, 
            0x7142A960769A9CCAULL, 0x86083C33705D0B02ULL, 0x6B149665428563FFULL, 0x91F9167EF64CA0C2ULL, 
            0xE27364A4DF172F6CULL, 0x9EACD35467968DCAULL, 0x436044AB816199A5ULL, 0xD4BDC2E5D65CA92CULL, 
            0x042E40FCCB56AF18ULL, 0x9CAAC12A1683513EULL, 0x1738A536E98C3DF4ULL, 0xE58B293D822EF559ULL, 
            0x5E05F762ED4989B3ULL, 0x481E62ED03C5EC10ULL, 0x2A2F6087724153ECULL, 0x8201739FFCA1A2B7ULL, 
            0x394E30EB71A9FB84ULL, 0xE98ECC8DFF7D149BULL, 0x3AFF4AFA393CA9D9ULL, 0x7C8FDDAA9B9E9C87ULL, 
            0x8EF1BB00C9857E2EULL, 0x27BD807B6844E6A9ULL, 0xB836F5C9C14DD9D6ULL, 0xBF7E7E01E2AB44F2ULL, 
            0x0DDC53FE622DA615ULL, 0x861FA4149A955F7FULL, 0x22EA5EA0129C5B0CULL, 0x6BA3F2E8FCCABCD8ULL
        },
        {
            0x968EB2B8B3B76AD8ULL, 0x9738EAAEF517E276ULL, 0x78CC5388EF4A1198ULL, 0x02476F8D6DA83F0AULL, 
            0xD44DFDA9A9283D5CULL, 0xC2CE0D3FCD9C6B58ULL, 0x072B3621C53D1FD1ULL, 0xDAB0D3F75E11755FULL, 
            0xA52D7FB5A201B6AAULL, 0xD7C5BF17C71069A1ULL, 0x34A6B10141E33234ULL, 0x6248EEB00A057900ULL, 
            0x63D030A3BCEAA507ULL, 0x658DFF8CD3C0D461ULL, 0x95ACD9A2C7D33547ULL, 0x946CAC04DEC5B8C4ULL, 
            0x4711D1631966AD8BULL, 0xDBB0838EBC8EDF80ULL, 0x11B865678905BD9EULL, 0xA4795FB06274E9D2ULL, 
            0x264858556880A29AULL, 0x9A97F140FF871C66ULL, 0x8DA575197B62EC56ULL, 0xA5706CB9B5A3018CULL, 
            0x9CF70244E8CF992CULL, 0xA522A2F92987CB56ULL, 0x793A1C1FA579C5BCULL, 0xDA724BB4C134D293ULL, 
            0xF62B0F9524286D26ULL, 0xA6D1FB99CB16ABFCULL, 0xF2AA899E7B4AD4E9ULL, 0xC514A2324A10B56EULL
        },
        {
            0x267A49FEDBF45A7AULL, 0x7A35F6849BE49B4EULL, 0x38B996FE85B912DEULL, 0xC9ADF197EA73D158ULL, 
            0xB019EF23A3DC0DA3ULL, 0x1DF5DE17AD2ACD9DULL, 0x1CD985CF3819E039ULL, 0xB5D651DA4EBFA21EULL, 
            0x8FD9EA745147C2E4ULL, 0xB55DC90F30312E4DULL, 0x54F8D0529AF51F9BULL, 0x139421B228A0EE14ULL, 
            0x5909C688CBE8813BULL, 0x3FF74A6CB4E4DAC0ULL, 0xB554EFA78D56F589ULL, 0xBA0873F28422FD38ULL, 
            0x99166F38643E6D7EULL, 0x262F145123498070ULL, 0xC4EE8C45C0F8A1E3ULL, 0x4BAF096E5C68D419ULL, 
            0x624DA9A3FB57EF3EULL, 0x71322EBAC71154BFULL, 0x77D23B197502ECCCULL, 0x8DE7A4EEDAE61A89ULL, 
            0x75F8E7ECBF0740A3ULL, 0x062539FA101377FEULL, 0x27DDA2D5CA96E07CULL, 0xD33BBD589A6D62F4ULL, 
            0xC23FF0FE13578809ULL, 0x4D6AEB8948A99236ULL, 0xC176757795DB1797ULL, 0xA84565D8A3D1DE11ULL
        },
        {
            0xD35ACFBECCB0D3A5ULL, 0x5755EC0AB4D9C4D8ULL, 0xF0AFFBAE3E48D0C5ULL, 0x7DFF24BCD001A39DULL, 
            0xAB395387FF6CD0C7ULL, 0xE23035F089023E22ULL, 0xC445CDF85346FE1EULL, 0xF70C9D4A63868A7EULL, 
            0xB697AEDF3404D630ULL, 0xC967EED37A6FC317ULL, 0xE70D0CF355C0C316ULL, 0x0D55372E8788E8BAULL, 
            0xDB7329FF525B563BULL, 0x917F0C7D3A0DBD63ULL, 0x771FD6BA371EF0BBULL, 0x1149B06EA389659AULL, 
            0xE5BC90DFE8AD41A9ULL, 0xF79A47B695E8C5A5ULL, 0x694660E4FA513E23ULL, 0x71E46338D69D7853ULL, 
            0xDAA8349C73E68F14ULL, 0x5F66D312AC04960EULL, 0x4DA76248E9B79E94ULL, 0xDAFF2EF4CE414E12ULL, 
            0xB01F517562B18965ULL, 0xD2D99AC5E0A773BAULL, 0xE6088A62580C166FULL, 0x30C0F108D414097CULL, 
            0x3A34BF5865F92216ULL, 0xC07DD2A4E424C0E1ULL, 0x42D28E047788E54BULL, 0xF3CC94699823501FULL
        },
        {
            0x6221F203B7802A8FULL, 0x5AFC7F192E7C57A2ULL, 0x60B4889A2EA383A8ULL, 0x36F37CB3C01B59ADULL, 
            0x9B4AF4B3F85500BAULL, 0xE5C35D6BD03B181DULL, 0x070EE14FEECB459FULL, 0x9141576DD5A49CD0ULL, 
            0x3C55A8C83AA0E730ULL, 0x9299A3952E522B93ULL, 0x84E83C0E498CBF48ULL, 0xFF6281795F656016ULL, 
            0x9DD04D5E8412995EULL, 0xC79275EF0256748CULL, 0x9D5FDE45FA75422BULL, 0x2E74EAE7BD9F3491ULL, 
            0x98B9FDC35BA90848ULL, 0x47B8C9399CBCB460ULL, 0xB54DB8813E154FA3ULL, 0x4AB2780F5C5AB8C0ULL, 
            0x0A21B569D92084BEULL, 0x8AA3F5FC1316BD7DULL, 0xA4EBC3056D60D973ULL, 0x7ED8FB50BC817D40ULL, 
            0x2A2FAF61A9536A4DULL, 0xFA93DB502427EC13ULL, 0xF405140A1947A1CFULL, 0x9E99E8751BA08263ULL, 
            0x42C292415A0A1A5BULL, 0x9FADECCE74ED6FDBULL, 0x3D43AA782B2C61F2ULL, 0x0C68EDAEE241DA35ULL
        },
        {
            0x8917A68BAA07E5B6ULL, 0xB67C709AB4472CC2ULL, 0x14A7D9202EB727FFULL, 0xB8438862164691F3ULL, 
            0x2EC7D51A81A63D67ULL, 0xB06A9C9539E041F7ULL, 0xDAA23313D1C81E19ULL, 0x9596ECE57B25CA67ULL, 
            0x8E762C0009DD975EULL, 0xA33990F367F73983ULL, 0xB643862B5BED59D6ULL, 0xB15D1408F80FD7DEULL, 
            0xF81124123CCB3079ULL, 0x065C71E21B7713A5ULL, 0x3DF55D27EF8CF354ULL, 0xBC10FE3C5ACB9D54ULL, 
            0xB99CC9841F25A81FULL, 0xED6CB406F91D1BF9ULL, 0x261C37A11DBA80C5ULL, 0xE6970EDBA47789C1ULL, 
            0xAA412897365B5571ULL, 0x8406E19E378F44B7ULL, 0x426AAFA078156D84ULL, 0xDA5CA13D496FA8DFULL, 
            0x9320B1B487D13BC1ULL, 0x228CFCF45982BDB3ULL, 0xF41B87BC0F147AF5ULL, 0xFF0503F566A8CB96ULL, 
            0xC4B0DF0E2BC0F287ULL, 0x36C830037FCB3139ULL, 0x6B32160A624BDAD3ULL, 0xA5BE60B5F8F09D46ULL
        }
    },
    {
        {
            0x59700FCC5D657853ULL, 0x34DFF15C412A3876ULL, 0xB536FC8B06C7ECCBULL, 0xDAB5C229227A6818ULL, 
            0x6C26A1B031632BA6ULL, 0xB015746CCB3849C8ULL, 0xA6B3AB4715B8CE2FULL, 0x763D308CC24CD1E2ULL, 
            0x552D942280573BB1ULL, 0x46D5A90F46234B7BULL, 0x04F9839698AA8300ULL, 0x830727B6903735B2ULL, 
            0xDD145E2E49F245A2ULL, 0xAF71605C45093DB2ULL, 0xA9A5F7A1F9D36ABBULL, 0x0F9F31433FDE12F8ULL, 
            0x7258F852B3E7378DULL, 0x5D5C204BEFE92D43ULL, 0x59D20E5CD968BF37ULL, 0xECF4CEA767516E2BULL, 
            0xB74CDC2129E5FBD8ULL, 0x87EF0D49425FFC1DULL, 0x9460C107B4E02C4CULL, 0x1867FA8173850001ULL, 
            0x36BF6C3AE569B9ACULL, 0x68567810BB68E16AULL, 0x2C104E209B369E5BULL, 0x77E1D5B1685A930BULL, 
            0x5A1B8C57E32A3AFBULL, 0xA6C3B6BDE79F27EAULL, 0x8131C9C511C7289AULL, 0x9A4A073AEFE151D6ULL
        },
        {
            0x412A8F4926CA7931ULL, 0xD99E9FE9DA4F30F9ULL, 0x92E8B7AFB810B419ULL, 0x0B93C8DED95103AFULL, 
            0x8013FEFD057D16D5ULL, 0x7519E87ED92F12A9ULL, 0x74A3B63F0F142252ULL, 0xEB7ECB263062BED3ULL, 
            0xC849BFE9CC634A51ULL, 0xD0CBBA68359A2147ULL, 0x3018392040409065ULL, 0x49334645DF054B17ULL, 
            0x60C8383307F6D80FULL, 0x0E0911246C0E9117ULL, 0xED144DA4FF2143B9ULL, 0x32CBF9B9D1F9566AULL, 
            0x94E4FB8271C98D78ULL, 0xD31E66B2B562FA79ULL, 0x453842BBE217C833ULL, 0xD0006FF60E141C80ULL, 
            0x85067C4BF769546EULL, 0x36C00AAA15276E52ULL, 0xABD5D7DC25F7AB99ULL, 0x8124D9D9238F2EE7ULL, 
            0x99ECDBBB34B978F1ULL, 0x803086D5A133021EULL, 0x17D0EFD7C843B210ULL, 0x2C3ED76BEAB38078ULL, 
            0x93071DAFE03FB390ULL, 0x923318D52CD092BFULL, 0x7C32092E9F8B4BC6ULL, 0x1B48C982EB3876E1ULL
        },
        {
            0xE747CAAA6B363C73ULL, 0x71BC4893035B6CDCULL, 0x75640F7CE8801D0DULL, 0x26754D4AE09F5923ULL, 
            0x58D3E6A70F877B6EULL, 0x05D6F425A780D3E4ULL, 0xB8325B4286DEE1DDULL, 0x792602ACCF3215D1ULL, 
            0x4074B56FA1ADB2A3ULL, 0x985CB7DD6D28FB4AULL, 0x2BB7034ACA1F9649ULL, 0xD6401991659F41BCULL, 
            0x01943F78ADD6D2C2ULL, 0xF5B30B981BD2D0EFULL, 0x1D7E8B201691EE28ULL, 0xAB3541BA30B57CC7ULL, 
            0xD92FDEB07C50CA21ULL, 0xB75A7B766DA0D400ULL, 0xCE7E027E4DCAC252ULL, 0xC57C1955B74CB758ULL, 
            0x40AE6C72A49045D5ULL, 0x541E43862EB21B24ULL, 0x4EC5804801EA1A85ULL, 0xF50F18EE8EDD8924ULL, 
            0xD0B2CB5D0B19BB57ULL, 0xA3D0454E4AD8F6EBULL, 0x54C22134197F214DULL, 0x6194FBB153FB74E5ULL, 
            0xA7F06BD548EBD9FFULL, 0xDF64FCE7F0CD7899ULL, 0xFB309A41407EE8CBULL, 0x0107D1E7A4F559DBULL
        },
        {
            0x0B1FE5A6E46AF373ULL, 0x1CF6FBBD07BE1F41ULL, 0xD06C28058F4BE49FULL, 0xD43E43B8CEC6D338ULL, 
            0x5A96C2FB2E25559BULL, 0xD1ECEDA0507E6F6FULL, 0xEBCC4A39E455E06DULL, 0x9BEA3E52C430483FULL, 
            0x9C2AB7538F4B79BEULL, 0xB5BC4BD4A13BD447ULL, 0x41D506B2050AB1A7ULL, 0x34BEE9BD320DC1A2ULL, 
            0x0AED92B14F07EEA2ULL, 0xA8AE9D2BE77DAF25ULL, 0x5BB2455AD5B063F4ULL, 0x666AB15EA5F21D79ULL, 
            0xFC2141EE3119BDC9ULL, 0x27BD2900E51C8672ULL, 0xE2EF122DE6CF025EULL, 0x9EB26CAAE4DFC6E7ULL, 
            0x73AEB9312CBE5D55ULL, 0x9B0853C0F5F8AF64ULL, 0x4B7D32C9B63C005DULL, 0x997D94DBF902CB65ULL, 
            0xD3E8D9DC30489D5FULL, 0x9972FEBDAC16EC6BULL, 0xC2DD1BE34DA2797DULL, 0x1427972B69E0BDD1ULL, 
            0x177CCED6A4C599EEULL, 0xD4FB69100D7B7D83ULL, 0x4D7DD6E25F9A9BC1ULL, 0x89B8C237554E1DD6ULL
        },
        {
            0x8C3B882E0A3ABA57ULL, 0x9A8E6D5A9AA8C202ULL, 0xB73C31BAFB4A36CCULL, 0x1AA5BFB1EE511313ULL, 
            0x79D085B187ED5428ULL, 0x2D248E5D423FCE8EULL, 0x11657E5E9BD5B92EULL, 0x40A9AE6186A5CB03ULL, 
            0x6958CF561C874197ULL, 0xA3C435484A18C67EULL, 0x62C9ACF39D81E614ULL, 0x7865FB50593B7B79ULL, 
            0xF6E86651B155D021ULL, 0x438BB484C7430F01ULL, 0xA95449851A1FA301ULL, 0x16138A74F373D0D3ULL, 
            0x38033AB35C622898ULL, 0x8F5AE03B7D898670ULL, 0xF05D297165A8A9EEULL, 0x7A993F42ED5E05B6ULL, 
            0x7DF3780272E8F0FFULL, 0x53FFAC6B6FC95511ULL, 0xF0BCD8D71169512BULL, 0x0FCB1E414760B4D3ULL, 
            0xD2B6573CC8D4A8CEULL, 0xEC0D44DE00FD9DBCULL, 0xD0EEB79A2B2FF528ULL, 0xD93BE241F4329E6BULL, 
            0x4F8264CEC32F40A4ULL, 0x31ECF8E8129C08A2ULL, 0xD36A32358C5FC90CULL, 0x893B5261C5B5DE9EULL
        },
        {
            0xD79B9BA613631873ULL, 0xC64D1F08E64D1C11ULL, 0x00F9B88173DE06C1ULL, 0x4D6917AE0374E50DULL, 
            0xC0AAE6F1A0F86E28ULL, 0x7F9096FFB4C1B1EBULL, 0xD1C611F779447C78ULL, 0xA7AEC84C4B8CF935ULL, 
            0x7DBD3E42BD35F4FBULL, 0x439EE54F53231652ULL, 0x990FD7FF1E0B15E1ULL, 0x9FB26AB5D7952951ULL, 
            0x1151E7CA2FEB615DULL, 0x75F79A4FDAE3EA71ULL, 0x298F4899E2A01D81ULL, 0xA433C8986707453CULL, 
            0x3240B6A53C64D600ULL, 0x71F04DD388D6EB44ULL, 0xAEDFED02C2826940ULL, 0x30109E1C7F17921EULL, 
            0xCF4378B6F9D0EF9EULL, 0x584CE0717F0C893BULL, 0x0A382DFAD791EDF6ULL, 0x4DCD8227CA8FA336ULL, 
            0x8FB9E14EDB161B9FULL, 0x2E8B650AD0A53255ULL, 0x9709A2304060BC48ULL, 0x34DB6D1EECF42ABAULL, 
            0x357D944060EBC843ULL, 0xAE81B8DC8F869146ULL, 0x6041B40CFFC7DFE9ULL, 0xA75C74C05A431C51ULL
        }
    },
    {
        {
            0x3D85008AED1AEE7DULL, 0x0BC54CE20D063316ULL, 0x4C90605F9CC985FDULL, 0x1FBCDA43AF6B5A3CULL, 
            0x5C31263B9DE4FC7AULL, 0x23EA4FCF19FF02CEULL, 0x1A0910126D596490ULL, 0xDEA93ECC632D5502ULL, 
            0x157689E8A68A8576ULL, 0x9BD555A0E98B89ACULL, 0xA2D8F6868D20796EULL, 0xAF8B60D66808716AULL, 
            0x95D6926D5E1C0BD1ULL, 0x519227C0F34ABFE1ULL, 0xFFE9795E24F77236ULL, 0x43279921DDF70DF5ULL, 
            0x00CF473D14D17E05ULL, 0xE6F93785A931A997ULL, 0xDDFDFA1DEF4A2000ULL, 0x74C0A877E45A4792ULL, 
            0x7D768E0E274D0628ULL, 0xBA43468DFCCBDF54ULL, 0x06FE923E9873CDDBULL, 0x2180CEC733FFFD4AULL, 
            0xFC37F7A37B8D3A6AULL, 0xDA58A94692AD9044ULL, 0xED17F69C2F306D51ULL, 0x8F111AD595D82A56ULL, 
            0x34F3536F50151A3EULL, 0x914A330BBC88B81BULL, 0x405E6D141954713FULL, 0x81566AB6B55B17F6ULL
        },
        {
            0xEDDDE3F2B058124DULL, 0xB35B92FAA70AF9A2ULL, 0xF74B60BEF2B56C7CULL, 0xCA91024A10361115ULL, 
            0x2CA29F463F3FE7D8ULL, 0xB73450D1EA0BFD61ULL, 0x26392F70412473B9ULL, 0x4F7A8404E3DD0970ULL, 
            0x1EA0295A10E4DB7EULL, 0x708D70C34ADFD53FULL, 0x8153814299706FC2ULL, 0x175E035212D26900ULL, 
            0xF71F47F949C0E219ULL, 0xF8BA4E465138FCA3ULL, 0x642CF1AC8839C30FULL, 0x97893C006213F5B0ULL, 
            0x8D2F173614BE1732ULL, 0x6717E5B7D2EF5E52ULL, 0x0AD910560FFB77BFULL, 0xC73CB4C5C1314FCAULL, 
            0xAF3FBC30CA7E2B9DULL, 0xAE24D8E91666C4B1ULL, 0xD51D80D60911D8DCULL, 0x23D7E3A3DD27C046ULL, 
            0xB612E85384FA79A0ULL, 0x3793AAA849E24FD4ULL, 0x0FA26EB51A43B466ULL, 0x32F24E6005CACA3CULL, 
            0x8A3E81A3F6D48847ULL, 0xD638FC8C61FF789DULL, 0x01B6EBC95B80AA5CULL, 0x9C1F710DD8D040A9ULL
        },
        {
            0x2DC64756ED07666EULL, 0xE450724E22B5B4B1ULL, 0x80090FC0807D7EA8ULL, 0x1140E5D651259242ULL, 
            0x4E03B14D4B169DD0ULL, 0x680A348A6688AC3BULL, 0x146E330C3E1899FBULL, 0xC0F2E774324334C6ULL, 
            0xB698E125B97E398EULL, 0xA8BB44513231ADDAULL, 0x8B3E59DFED40F0CEULL, 0x187ACBDD926B81F0ULL, 
            0x30C0554BBA4060CCULL, 0x27D126CBF54DA599ULL, 0xBE2AF467402DC7A7ULL, 0x047B21A178870D98ULL, 
            0x4CF177F78E5A81A6ULL, 0x37B1AF5E6E174BCFULL, 0x1BBFB60B25F8C6A8ULL, 0x3283DB493D765E02ULL, 
            0xC644FA50E4A5434BULL, 0xD3EA1080FF35FDE2ULL, 0xFD427F44419B4B98ULL, 0x7E603A71811D41E2ULL, 
            0x5CA20E9AF1CB8E2BULL, 0xF617DD746CAC32AEULL, 0xC260B25BAF75A802ULL, 0x3C9960E7C9255090ULL, 
            0x432305EEEBB6F057ULL, 0xCF4B70A5AD055DF6ULL, 0xDAC1154F49E1B10FULL, 0x57E3B1127DD44EF4ULL
        },
        {
            0xB071DE4A226AD991ULL, 0x82D0151D4F77659BULL, 0xF96B9E3414918E48ULL, 0xE620093008A05B2DULL, 
            0x0748A2378B27ACA5ULL, 0x7902AFFC2AF6B1CCULL, 0x4E6FECBAA9F12E30ULL, 0xF32FBA98458F8823ULL, 
            0x472704823F3C5BB4ULL, 0x4C159B949C32608CULL, 0xD3A558F77184D0E3ULL, 0x3640EF5BDA53AB28ULL, 
            0x8FEA31EAF811F25EULL, 0xAEF47D176BC7C39DULL, 0xE5B329F5323F8B3BULL, 0xEA1E21B3C4CBEF37ULL, 
            0x4D5C4B008A10BAD3ULL, 0xD5182C41CC2430E3ULL, 0x100DCC2A202E6DC8ULL, 0x91881114531FD2C5ULL, 
            0x142A4A33A0D20B34ULL, 0xBDD06843C5E4ED55ULL, 0x71898E137FBCDD74ULL, 0xB41E7F81E4DB86E1ULL, 
            0x44D426086B29E7D8ULL, 0x12794DBCBA8B2FB9ULL, 0x08DD06E30D2FED23ULL, 0xD9C181D1F5087EDFULL, 
            0x2F4A10FEA6E743E3ULL, 0x7BB45ED72E69F9ECULL, 0xA8108E2E4BB093B0ULL, 0x8B58275B7DF9CFBEULL
        },
        {
            0xF3B67D4AABAA27D9ULL, 0xF71522CC477E6784ULL, 0xA81B0BDFB1BD6636ULL, 0x748A22776CE35466ULL, 
            0xBD88CE02A7A2121AULL, 0x2715A343E7345443ULL, 0xA5750E72C2E2257EULL, 0x2A2856FFA28E8610ULL, 
            0x4D8FBA24362D6E88ULL, 0x9A05ECE15BE496BCULL, 0xEE66EE66E82D27F8ULL, 0x680F33680B249DE5ULL, 
            0x604A99AED16A9331ULL, 0xB31D46577F131A47ULL, 0x986D021603B97A6FULL, 0x71AF223F3C43CE35ULL, 
            0x826E58E73C04C69AULL, 0x3C1ECE419C2BF7A2ULL, 0xEF13FE46F4907A47ULL, 0x01FFBD7880859535ULL, 
            0x868BD000DD39FDA2ULL, 0x9DCBC80650B2C4B4ULL, 0xCF0C621F3FEEAEE3ULL, 0xC65FF0AD160B4E13ULL, 
            0xBEDE51A5887C0E44ULL, 0x881875FBEA5C3BE6ULL, 0x21BA42D5B0A7EE82ULL, 0xF19625B9FB80591DULL, 
            0x916D4A06C2A56D93ULL, 0x33EB98C7FF549C1FULL, 0x8CE31877F6BFCB33ULL, 0x7067846222B0744CULL
        },
        {
            0x6288757B3CB5721DULL, 0x2636DB024E233129ULL, 0x84BBAAE1D3E38E10ULL, 0x393DD9F674DBBDD0ULL, 
            0x17E59CA02EB098B0ULL, 0xC0D06E81D4AC8652ULL, 0xF995BF09F553672AULL, 0x35092AE614504254ULL, 
            0x464AA0EF1E3DC2B3ULL, 0xA87A332522E2263EULL, 0x7FE3A97A18E0F74AULL, 0x820E00DAE4711E07ULL, 
            0x38AC9B052619D4C0ULL, 0x684EF797E49D6D18ULL, 0xDA41955B0661421FULL, 0x2813F8D52B182915ULL, 
            0xD64E71E9B5BB4F01ULL, 0xE35F8621473D584AULL, 0xDAAE715AF95C4BF7ULL, 0xFFA260FCC07C47E2ULL, 
            0x2A2376E0E12AF773ULL, 0x35FD7E5B7645F387ULL, 0xB5E4C770F4D8876FULL, 0xB88E46337B2BF707ULL, 
            0x4FD3FFCEF25C1479ULL, 0xA19CA06F76692530ULL, 0x51AA190D6D2F6092ULL, 0xF5EA047256B486F3ULL, 
            0xBA25E19BBC61E20DULL, 0x88DBB14C6FB2AF37ULL, 0x4D542A832B21C932ULL, 0x50A624E97803462BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseAConstants = {
    0x059D0E0C29591EA6ULL,
    0xAAF7B9D134641E3FULL,
    0x0A855DA8A24F2409ULL,
    0x059D0E0C29591EA6ULL,
    0xAAF7B9D134641E3FULL,
    0x0A855DA8A24F2409ULL,
    0x62C6D401EBE5C0ADULL,
    0x349D2AA0B66F388EULL,
    0x01,
    0x43,
    0x91,
    0x71,
    0x3A,
    0x0A,
    0xE1,
    0xD4
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseBSalts = {
    {
        {
            0x0AF7699C06E3D2EDULL, 0x400AD1F3A579B2E5ULL, 0xC6DA8E08A32F7D6BULL, 0x4693C43CFE5C89AEULL, 
            0x2575C52DBA76CBA9ULL, 0xBAAB2E6EF4FD3504ULL, 0xA762A84B8D6029AFULL, 0x46EC5726DAF9602EULL, 
            0x7DCF9CE7C634BBECULL, 0xF1023CE58E242261ULL, 0x06110803556728BAULL, 0xF82AEB42247E67F5ULL, 
            0x2321649AF3E8A2C4ULL, 0xA7CD2F4214586E18ULL, 0x0D9EFA446D978BC5ULL, 0x84357E9BBFEE7B2FULL, 
            0x586B45A684C2685AULL, 0xF7E057BD2390DC46ULL, 0x5F803EAB497D22F5ULL, 0x90C867D42D3C8187ULL, 
            0x3BE39680E0304F35ULL, 0x12BCB01060475A99ULL, 0x92FCE0766336AA07ULL, 0x4F5E0DDCA341B9F5ULL, 
            0x83017E1804C906EAULL, 0x7B40A095DC1F3B1EULL, 0x5ED979A8141C0184ULL, 0xA29595FF861A41EAULL, 
            0xF272B56372621B1AULL, 0x2A74FD4F8DE772DDULL, 0x5056CDEA8446EB66ULL, 0x068880148276A2FCULL
        },
        {
            0x027B3F7B83B3D78FULL, 0x1F9EEE3BE1823026ULL, 0xB63FBA87ACB315FAULL, 0xDF07C89C3B5014BEULL, 
            0xC9B608541F421D7FULL, 0xED3D467A686BC1B6ULL, 0xB5628277C09D2995ULL, 0x96F34255ECEBF993ULL, 
            0x3D98FEE05C8B87BBULL, 0x8F56C5886B338AF1ULL, 0x33F56A7F0DCF922DULL, 0x8675247F206D8741ULL, 
            0xA8DDE964F1B0634CULL, 0x78FE5A2C9984CA7CULL, 0xCCA0BEA7AFEED166ULL, 0x751E2FDA71C6F629ULL, 
            0x1354279977A21449ULL, 0xF6CFE73A15BECB27ULL, 0x656057EB060C6D9FULL, 0x5857B0839D32534BULL, 
            0xE44B0C3B36C13C51ULL, 0x270D7F9985FD8D48ULL, 0x1D869B460733EF72ULL, 0x79B4C95B1DEEB804ULL, 
            0xB99DAE2661C61F29ULL, 0x2A808738E974BDEAULL, 0x7B59A4B0E69D07BDULL, 0xB08265DE9551F164ULL, 
            0x6808F16F75CEB779ULL, 0x2DB2698BE821BA19ULL, 0xCC644CB097E8B5DDULL, 0xE264CE4871AA83BEULL
        },
        {
            0x49FF9430AA191E60ULL, 0xB7AADC42194A6B4BULL, 0xFB30D897E2B98236ULL, 0x4ACB742A79740952ULL, 
            0x5F85AC4A36C4DFD3ULL, 0x196A4E8FE33A4AA8ULL, 0xFD2B4682DF67F3EEULL, 0xCF033F8D78C22816ULL, 
            0x7D50A7B6473F8A85ULL, 0xB2EB445BD5FF0265ULL, 0x5C2F12526CBC4E1EULL, 0x253BA105E94C0A69ULL, 
            0xCDEF32BFFA6F84B6ULL, 0x625BEDA9C34D3274ULL, 0x943DD3A172F39322ULL, 0x4F6D83C3748CF844ULL, 
            0x15DF7599D5CA32F4ULL, 0x7EC87649CF48DC1EULL, 0x755B2D03C124090EULL, 0x842BBD351BBF465CULL, 
            0x68BBED93BB27BEDAULL, 0xDB2A00992511268AULL, 0x40F52503392924AFULL, 0xD881E068F65C8C48ULL, 
            0x1C91A68265E1726DULL, 0xE968304106196E65ULL, 0x450A171A5E87072DULL, 0xF93F03FF8104043DULL, 
            0x985294C709679D5BULL, 0x80B427A979BEEA1BULL, 0x849612767AD1E77BULL, 0x712350FEB34B0D69ULL
        },
        {
            0x23D9137C66C8BDD2ULL, 0x79B4F34834D27C17ULL, 0x0CA45439184C33C9ULL, 0x3D9317058CF24644ULL, 
            0xB8A32B29B2ED14AFULL, 0x06438B2C8A65C239ULL, 0x5112489A6400DD6EULL, 0xBF8064E25454891FULL, 
            0xB2F6E5879ACF1EC4ULL, 0x206E68290F1BBD7AULL, 0xC1D544F3BAEAB347ULL, 0x46273C47287BE9F5ULL, 
            0xFDC4FB98795D7E5EULL, 0xBCF1FDF65FA3093CULL, 0xD6793F9FE43C610DULL, 0xDD3CD1C6483625BAULL, 
            0x431E700DA12E71BFULL, 0xD060BD48DBB9743EULL, 0xBE5E095F5F422792ULL, 0x0D87F82DC800583FULL, 
            0x931BAF3AC4764571ULL, 0x0377833C16F7F883ULL, 0x72BBF913FC164E10ULL, 0xE99A8C660FCB3676ULL, 
            0x503659F9483C2716ULL, 0xD0A9950597F62B3CULL, 0xD5875E99D286D03FULL, 0xC92802AE1BFE608FULL, 
            0x55A0E343708A5636ULL, 0x7062D967C9878BD0ULL, 0x06A8A5B496C35C83ULL, 0x2A3D9DF92DF0399CULL
        },
        {
            0x2C96FB75752A4344ULL, 0x4D6F647FAE3FC254ULL, 0xB403FDA58F9A8268ULL, 0x8A3F7E09E2439D30ULL, 
            0x923EE0414362852AULL, 0x6DAD332C3AB439EFULL, 0xE635653654BB2816ULL, 0x3A4B984343EBA472ULL, 
            0x802D5347A3B3FCDBULL, 0x838A65A7F971B2DCULL, 0x71E4A6A6F0015F2AULL, 0x28419C63D4A68217ULL, 
            0xB0B8DC43DCC8103BULL, 0xA5BB5CA052EBE1D5ULL, 0x520E696AAC268F35ULL, 0x2BD654EE6C018131ULL, 
            0x7C65CC86CB6E9690ULL, 0x9E56A60E26A07973ULL, 0x6E4E437AC206EF8FULL, 0xA9A917C4A050CB16ULL, 
            0x0C152E144F8265E6ULL, 0xFACDCCCA9F3E3E4BULL, 0x7567CC1126D5AD4CULL, 0x0495F5231F319CA4ULL, 
            0x5596E879E5D980B3ULL, 0x6F293E38286A50B8ULL, 0xF061ACDFF196974BULL, 0xF7886884DFAACE7EULL, 
            0x93BC07F0AB5CD93DULL, 0x7005276778F575B8ULL, 0xDC43C1CE88A2A468ULL, 0x35F5B8C34135ADEDULL
        },
        {
            0x94B69AC0F32EC88DULL, 0x63E0F57F5D3D9575ULL, 0x115AD64AB1E8BDF4ULL, 0x02A5558D1D3E485BULL, 
            0x6005EA29A0FE54FCULL, 0xD3E108A7B4E0ECB1ULL, 0x029977AE6971E7E0ULL, 0x139A06679E5E179FULL, 
            0xF50EB02688F134E1ULL, 0x6061F1CF2249AC27ULL, 0x1C4B20EB513AE273ULL, 0x800B6E0CFA5FCEF2ULL, 
            0xF54CAD9A89A03602ULL, 0xB22FBAA3B7116599ULL, 0x198013E0F8540465ULL, 0x812A990AD6C4A486ULL, 
            0x0CA788A68E2594B4ULL, 0x4E8C56834C20332DULL, 0x644DF3D22319580BULL, 0x214992B297B84433ULL, 
            0xBF2B48BC8951CBD2ULL, 0xDDFA1FB9079B4277ULL, 0xB73FCA38196DE87CULL, 0x983F60DFC38A51BAULL, 
            0xAC8E59DC8F4DF8ABULL, 0x22B0F4AAEA10AD86ULL, 0xF210AFC151DC6879ULL, 0x3E0A044166BDECD8ULL, 
            0xAB56F7327DB58C11ULL, 0x661C62E39342A2C6ULL, 0x670C9E2F0D846ADDULL, 0x89E77A21AB18C2B5ULL
        }
    },
    {
        {
            0x28C8513E3AACE084ULL, 0x94CF114244817520ULL, 0xFC00B58E18C3CE33ULL, 0xCC7FBF21A08359DAULL, 
            0xA62B47E69C561AE1ULL, 0xBE9FF62BEBA54F68ULL, 0x20DD0FEFF85B5544ULL, 0x3351F297E6744BB8ULL, 
            0x7C051AE7175AA5CAULL, 0xE4E45816FAB248DEULL, 0x0DEFCBE6FCF3358DULL, 0xDC2A5CC5B89CC9BDULL, 
            0xC39625C052E802EBULL, 0xA6EB373072702CC3ULL, 0x3256C3491CFE7E50ULL, 0x4966613F6DBC39A7ULL, 
            0x7DF527BA19603DE5ULL, 0xE69B9F132BE571B8ULL, 0xAD4E8BEC53F2FDAFULL, 0x88E74815615E65EDULL, 
            0xB25A9F3294126AC4ULL, 0x69B9375732C0C3D6ULL, 0x0B5B0178CAB52AB9ULL, 0xF2AA02C7918D4648ULL, 
            0x1490B7F953897B7CULL, 0xD3A9BA333BE7AC03ULL, 0xB1F1B14D896BF94EULL, 0x97B6EAC1400C2945ULL, 
            0x350CB70CE024B786ULL, 0x369C601E44DB3E8BULL, 0xC1C03ED8D00D797DULL, 0x9893ADA66E3DC446ULL
        },
        {
            0xF4A61420BFD9107AULL, 0x7B172E89B83A762EULL, 0x66D44F22F1158F47ULL, 0x8FBD961F91AC981EULL, 
            0xC208DA247AB65ED9ULL, 0x3506FE2365F14D34ULL, 0x3DAD274A2546F77BULL, 0xCE972714398E7138ULL, 
            0x2BAB90F428B4B367ULL, 0xCCBB1A93EFDE00F6ULL, 0x71E79BD2632CD6A3ULL, 0xBE342938FC4EAE42ULL, 
            0xD32584BFF4AC80D6ULL, 0x52935D9E436489DAULL, 0xCBA50B19413F367FULL, 0xDF13805A93A76873ULL, 
            0xC70E1474BEC6FB80ULL, 0x97ED168B332F4BACULL, 0x5AE321FEE8B7994CULL, 0xB04A802D3311F339ULL, 
            0x9A5640EF1B94EC04ULL, 0x5B24E56EC25D024EULL, 0x1C5EFF48C011BD9CULL, 0x0D8E2E70D3EF9A59ULL, 
            0x78D0C1B4B86F3C69ULL, 0x379484708A35A62BULL, 0x6F23A9830CC93664ULL, 0xBBC5734BE0853784ULL, 
            0x3DE95E4E8C190A7CULL, 0x7E85905E64EADF57ULL, 0x978F050584AB6044ULL, 0x748D777A28C4E1DAULL
        },
        {
            0xEC88AFE7D117CD19ULL, 0x403C8941C2ECBF6EULL, 0x49881D76AEA9FC03ULL, 0xEFFBA32D8CD66832ULL, 
            0x0F13440DEF0F0057ULL, 0x1E50E1A5EA957E37ULL, 0x33D7FC04D5AD58B0ULL, 0xE2B469187BAC0D2DULL, 
            0x71491A9D2E4953BDULL, 0x24A4D3009CEDEE83ULL, 0x90958EFD52A99EB6ULL, 0xDFE5988765BA7E39ULL, 
            0x6C13BC39218E39D4ULL, 0xFD5B51DA9601CFE2ULL, 0xC3988E7FD5A13014ULL, 0x075B5E3065D224A3ULL, 
            0x1ED2233E8F346609ULL, 0x6647F4D942591B0EULL, 0x66A3F07051D611BFULL, 0x5488EAA9D466D299ULL, 
            0x913B2665BE69F050ULL, 0xE7076A75617F3CE0ULL, 0xD30DE1F56984A020ULL, 0xDFE7DDAC3AB83FE5ULL, 
            0xD3F483610EDBDA67ULL, 0x9FBADB89659AAFCBULL, 0x17B32693D230433BULL, 0xD3E8F1B6B9C5B1ADULL, 
            0x0E07C530806E8017ULL, 0xFFD34DDB1238C059ULL, 0xDED50EB558F16D0DULL, 0x36299FB844964790ULL
        },
        {
            0x5BC2EB3DAA53A254ULL, 0x5045D16AB65094A5ULL, 0x9835C16F40702F47ULL, 0xE9A89E7F2156648FULL, 
            0xE1B5B82EF8F53C1BULL, 0xB914DFA6EB453352ULL, 0x79B3C78F54E02898ULL, 0x81A5B5977A99828BULL, 
            0x90E4107F7AF0BE51ULL, 0x9B1C8D1BDCD64B40ULL, 0x804BACDEB1BFAC8BULL, 0x3EDC21641D1510A6ULL, 
            0x330E52CEB037B1EAULL, 0xA0B59B7D18227EEAULL, 0xB77DDDB38E01EEDDULL, 0xCDFF0221C58DC43BULL, 
            0x8A4027066AD76F2CULL, 0xD68FDFE7C0C5C0BCULL, 0x2FBE6004C8DF3BEEULL, 0x67413A967FEDBB62ULL, 
            0xEFF7138AA34CBB9CULL, 0xAA5B1332C6F47D4AULL, 0xB5319393EBBADC37ULL, 0x928A48A2CBF49316ULL, 
            0xB3D72445B291DDC8ULL, 0x4581BCC9C127D95DULL, 0xDB0A11EF2E13995FULL, 0x5E58110A204E4E08ULL, 
            0x97BBC0FA49440279ULL, 0xE15844C43027CF9DULL, 0x262E358EFE545FD1ULL, 0x7163D9771BC3DE44ULL
        },
        {
            0xD5265C35BB2BFDD6ULL, 0x209E740C0D25E405ULL, 0x07E3D4B6F82597A6ULL, 0x1DF528D8C69472A8ULL, 
            0xC880DCB3DD4F4CB6ULL, 0xC2BEE0D9D5317993ULL, 0x10A8BFDEB0A77CCFULL, 0x03E8A330DFF9C894ULL, 
            0x940678F1C7172C58ULL, 0x6CCC3DE98390DDA2ULL, 0x26CFA2FE24A5F0CAULL, 0x72117F577D8D165BULL, 
            0xABE063EA53A63C18ULL, 0x36628F5E2911BC78ULL, 0xA67851B5549E3F95ULL, 0x0F4BC54AA3C839B1ULL, 
            0x728EA60548E6D84DULL, 0x7B26B9D1F1814E14ULL, 0xA947ABD0644CED5CULL, 0x115D37EE7F10022EULL, 
            0xFD905B0F8C2692A7ULL, 0x631E1CD318DCCF19ULL, 0x43CA2B252182DF69ULL, 0x420871E5E20F2C2CULL, 
            0x4130B1B6DBDE317AULL, 0x7CDCC492A7D645CCULL, 0xFA10E89091809939ULL, 0x09CF9BE536482ADEULL, 
            0x95CB3BD9C00BAD6BULL, 0x2857D64760FAD6A4ULL, 0x96AAA059D8EAA2C4ULL, 0x345FCFD3324F1E51ULL
        },
        {
            0xF1C71A86582EBC63ULL, 0xA11123237E2DB063ULL, 0x098F19DA56D2DB8FULL, 0x4BC8EE832AA374CEULL, 
            0x0F36F829A09CD8E3ULL, 0x4F9F1DDC727823E0ULL, 0xEAD88D824EB2111CULL, 0x5C62F1B29766D258ULL, 
            0x19645E2D5909E472ULL, 0xE320C1647A26C6E6ULL, 0x5AB7F46AE4B198B2ULL, 0x07231019EA4019EBULL, 
            0x676197608CEC6FAFULL, 0xF73991CB6048C7BAULL, 0x4D51162293E32915ULL, 0x032BC72194E65F0CULL, 
            0x671750593D98A9F9ULL, 0xB2261E08243800EEULL, 0xF22BC48664129BC9ULL, 0xF615CA96E654AED7ULL, 
            0xBDB104670DFF6653ULL, 0xAD64F21AB0C7CBD7ULL, 0x9CB7F63B0A7A4DBCULL, 0x69013F7DA66CB570ULL, 
            0x8F7BBA8E4212F71EULL, 0xCE146FD312B31F0BULL, 0xEC371BBBCF6AEDD3ULL, 0xC9080E49D17C13F8ULL, 
            0xA725D2268B078C2FULL, 0xF1CA716186301029ULL, 0x4637BAB8CCA09047ULL, 0x3601C9347EBDC2A2ULL
        }
    },
    {
        {
            0x5209009331DEB751ULL, 0x50A13510CFFDC412ULL, 0x54F3AEC552273B88ULL, 0x760126B95E94826EULL, 
            0xAB827FB4C2561C4BULL, 0x6926AC8FA285B9EEULL, 0xC99A5F5662B27AD7ULL, 0xD296A4BA9CBA46A9ULL, 
            0x505276013CEB4BF8ULL, 0xD0B3447027BD37DCULL, 0x800123233834BA52ULL, 0xB87945B5E862E409ULL, 
            0x9C531B5BC19C8E2EULL, 0xBC7E8DEDDC060D28ULL, 0x6F020AC4C9CCC624ULL, 0xD95E643017E83089ULL, 
            0xE78B1195C1299CD7ULL, 0xACA586B869646A13ULL, 0x214966A44EAA313AULL, 0x5F9D21508A16027CULL, 
            0xD411D69CCF3E3BABULL, 0xF3A42D9F2A6569CAULL, 0x59D489EFA428A210ULL, 0x29C830E014017475ULL, 
            0xB34ED7F3C28A2D49ULL, 0x4A9CDB8FD76AE6D6ULL, 0xF1AF22ABE60E6CB0ULL, 0x1E9E83A60F27A63FULL, 
            0xD901CD8798834C8FULL, 0x6DDCF23B3903764BULL, 0x9B45058DFB1F7004ULL, 0x7AD9559244CDDAC5ULL
        },
        {
            0xB994BB82B9CBEBD5ULL, 0xCF6DD4FBE2EC875EULL, 0x429098BE62E29FF0ULL, 0xF166A3130A0AA63BULL, 
            0xD578B7DAB6176E18ULL, 0xDD1D77261707FAA8ULL, 0xAEEB036A1E5BA143ULL, 0x7EB6166F7A742E0CULL, 
            0x299B56AD871163D5ULL, 0x35AEB3A3CAB7CD7EULL, 0x230B74B4BAF9E168ULL, 0x12A85ACADAE8BA04ULL, 
            0x339F6F49AEA40ECDULL, 0x169E8072920C78B7ULL, 0x36FB0E3CCC26FE27ULL, 0xB1A61E417F4310C4ULL, 
            0x21D355228E56BDB7ULL, 0x5E2D7FE55FE3499EULL, 0x7AAE5A5E1D44AB82ULL, 0x73116E7306709893ULL, 
            0x0488FB13C8173818ULL, 0x78B7EC5E78802312ULL, 0x2440F4B36FA0E339ULL, 0x8F52B5057831B22BULL, 
            0xBF160EDEFE881C7BULL, 0x124B95FB33773204ULL, 0xE4BD79C3C3E7D4A1ULL, 0xF2D7B887DD8645E9ULL, 
            0xEB9C01246C6B86EBULL, 0x7F7303DB87EC1DF7ULL, 0xFD6D6EA88712974BULL, 0xC4246C15D1DF3776ULL
        },
        {
            0x09B3B8F7F44EF634ULL, 0x5B58AB57F96B3ECEULL, 0xCC3D72228B2A0A34ULL, 0x8202DFD59F616E8BULL, 
            0xC634C5AD78BE813AULL, 0x635339DB445D5E69ULL, 0xCC39593EB4655E21ULL, 0xE2FA2182914E806FULL, 
            0x313FB9842B7C7968ULL, 0xD65C9A5C952DF3DFULL, 0x0EF635617617F4A5ULL, 0x3B0D9561D028DC60ULL, 
            0xD65FD1F466465F6EULL, 0x21EDCD03CC9E73CFULL, 0xEEC56EBDE1A1EB72ULL, 0x029E514F7A8835DCULL, 
            0x01BC29195F573FB7ULL, 0x605B364D1796F9E2ULL, 0x8EA2E4A94D3267A0ULL, 0x9603ADECE3E8235CULL, 
            0x2F424DF027F3BA7FULL, 0x8916EA373A2737BEULL, 0xF171B445D9AAF2F6ULL, 0x6468D642A9685172ULL, 
            0x1775A2ABF2EE8EBAULL, 0x4CCD8CE921231F47ULL, 0xE6D60459E3B15494ULL, 0xBDF55E95FE61F34FULL, 
            0xDA1863B310CD3AE9ULL, 0xB1FA5527055E0EE4ULL, 0xEA163D5CCE847E54ULL, 0xA81EDE0AAE7FEB42ULL
        },
        {
            0xE428B412B8551EEAULL, 0xDE6D5C8930787362ULL, 0x940AE99C2E670163ULL, 0x36103FD5566F12BCULL, 
            0x18426EFB6ECEF01BULL, 0x1A7571E96B155BEFULL, 0xA338AC3B9BC223ECULL, 0x5444BFE8C48474EDULL, 
            0x30BC0AFBBEF04512ULL, 0xFF0143EE4F1EFE06ULL, 0xD90854B2190DD50FULL, 0xFA5795046C885BDFULL, 
            0xC2C21E5FA13EDA1FULL, 0x513BADD26531950AULL, 0x3203ABC1BC88D20AULL, 0x26DF7CB34A38F72DULL, 
            0xB7BA520550B458A1ULL, 0xBF7FC9C3FFF1FE32ULL, 0x5DFDAA8B0C1E0201ULL, 0xCF6A1BDA803B4D11ULL, 
            0x9F094E14EA0E13A2ULL, 0x8166101F4A8F8670ULL, 0x14818BD00954D74FULL, 0xB426699A6753469EULL, 
            0x49A0F299068B960CULL, 0x0F7817BFFE4CC3EEULL, 0xF3E2F7F72D53CB4FULL, 0x76B6C99A739ABF9DULL, 
            0x3731C1B66C149BDAULL, 0xF5679FE7C6295AA6ULL, 0x4F8576B6521FB3DAULL, 0xDC88D1CACC2D0188ULL
        },
        {
            0x1A203BB4B7BC0D0CULL, 0x00829BF2EEB963AFULL, 0x0D162C826767945DULL, 0xC6068300549B4233ULL, 
            0xD701563EBFA89779ULL, 0x932477E2361A17E3ULL, 0xD824F8D346B09F81ULL, 0x5EAB280F33071CB4ULL, 
            0x553E06EC2E85D2A4ULL, 0x2A23C0A3BDF951EFULL, 0x0EF68BB4696F8566ULL, 0xCAE1F52BED627A4DULL, 
            0x54B3165B1D829790ULL, 0x665E118219EE61B0ULL, 0x4037AE1E07913CA6ULL, 0xB94CF63F990D78E9ULL, 
            0x8F62899D6172C558ULL, 0xACA16D6E8B0D8394ULL, 0x1CCDE1D7C778A059ULL, 0x68F3309F1EFB3C0FULL, 
            0xCFADFED81406F26BULL, 0xCFE5D4E703F6014DULL, 0x6AEECCB21F3F5E16ULL, 0xFE0C6C7EC6C77D7AULL, 
            0x88EBA8BE88AED196ULL, 0x4442BFCC52C3EA15ULL, 0x5A2A1D708B7A6794ULL, 0x9AA4D5C06107890AULL, 
            0x60EFB256F2C3A54DULL, 0xD997168B02247A49ULL, 0x07DC8168389D3CD8ULL, 0xF4CD7C7531EB614AULL
        },
        {
            0x01D36C3E8BA8976CULL, 0x051E2F6F25029060ULL, 0x658C7B2CD022CEC0ULL, 0x41BB4BF2C283ECF5ULL, 
            0xA9AD8F8D3FA7C1ECULL, 0x424BB36561FB8419ULL, 0x3D780BF50FF60074ULL, 0x27A2A39FB41DAADEULL, 
            0xE931543E06893C5DULL, 0x1A2985DDCEF6AC77ULL, 0xB80B4B966C2338F0ULL, 0x7B49B834B3D0AD92ULL, 
            0x2FBC1203F7C7372DULL, 0x09BE5FC6F6AB4E7DULL, 0xA2665455A252436EULL, 0xE081A54FE9ED75B1ULL, 
            0x487436CADCA6D100ULL, 0x37A920057637EECDULL, 0x9F1C7360D0495240ULL, 0x8C7FE9FF1C689495ULL, 
            0x3D14B0ACFA721DECULL, 0x84B8FE852C776125ULL, 0x5451FB3AE332355CULL, 0xFE90511CD6679E13ULL, 
            0x6AB9F9A064C9EC50ULL, 0xE6373FB9C868C748ULL, 0x40F0F42DED5ABE8EULL, 0xAF53963DE5474AD5ULL, 
            0x9641026DC9BDE9EAULL, 0x0B52E326D0EDF64FULL, 0x8B436951A894AC7DULL, 0xF5ED3C659B4D94AFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseBConstants = {
    0xF50887B8C7A2F15AULL,
    0x79A22F8C19C7D8B5ULL,
    0xDAAC0CE2B6D67122ULL,
    0xF50887B8C7A2F15AULL,
    0x79A22F8C19C7D8B5ULL,
    0xDAAC0CE2B6D67122ULL,
    0x87AD59848880E731ULL,
    0x83B2BC4E885016D9ULL,
    0xC0,
    0x3D,
    0x2F,
    0xD2,
    0x42,
    0x11,
    0xF6,
    0x5D
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseCSalts = {
    {
        {
            0xF5D3F2CAB869C13FULL, 0x365CD71822C7084BULL, 0xE122423D0F332536ULL, 0x6CAC922014CC4D09ULL, 
            0x93EFAD4519E3D120ULL, 0xD58173D7BFDA2F60ULL, 0x2FF4B57C4EDA0480ULL, 0xB93229DA8DC3D2A8ULL, 
            0x45F157F179ABA3E9ULL, 0xA958DBB2CD367C1EULL, 0x9C528E7FE3683CBCULL, 0x037350782ECFFD5BULL, 
            0x37BB2279A436A1F8ULL, 0xD430FCDF4F3FDAA2ULL, 0xD4C97012CD668C7AULL, 0x259BDCBC858617A8ULL, 
            0x14A80DBA856C9CCDULL, 0x42ADD7350D8FE776ULL, 0x4DFA16F25DDDCE86ULL, 0xBD383F1F34A85282ULL, 
            0xB9A630902BAE90CDULL, 0x8FD8350AA69B0017ULL, 0xC75593EFA89BBF2CULL, 0xC61AB242161C4E95ULL, 
            0x8A7E37D23D1FA584ULL, 0x2C4752D5BB6CEC6DULL, 0x610451E48531E047ULL, 0xD0252D61B92A4F9EULL, 
            0xDECC87ADF1101713ULL, 0x19ABD8161C5408B0ULL, 0xC9E317C6ADA929E9ULL, 0x7434458047EB9470ULL
        },
        {
            0xFB50CF39B7C2BD03ULL, 0x9413FFFFA338F683ULL, 0x9F316C5B5C3EFD64ULL, 0xF9560FCC5300137DULL, 
            0x76C5AFA69DCC4E62ULL, 0xFB9FE8EF15C98FFFULL, 0x9D9CB23897E0AACBULL, 0x45707FD240C5EF77ULL, 
            0x93334CDA6E974FAAULL, 0xC0550D0C55D9080DULL, 0x92ACE8BEB0C001B7ULL, 0x71A5C2011794E27FULL, 
            0xD3CECE604805879AULL, 0xFC2043C3110A01F0ULL, 0xBD6BAABD38FB701FULL, 0xE6449D37954EACE9ULL, 
            0xA74A2FA123F951CAULL, 0x0C99C3BB9A83D1EFULL, 0x24107A23E8157852ULL, 0x1ACB8E5CB932BCCCULL, 
            0x7AC18F737F8FCA24ULL, 0xDE1CCA40FB7100BBULL, 0xF104A0173678A5ACULL, 0xEC25F03DEF5F29ADULL, 
            0x30BF3EF935690D9DULL, 0x30287F50102D295EULL, 0xC0E113369E8BB761ULL, 0xEC0674BC02E3DAECULL, 
            0x5165E48D627102A6ULL, 0x69A0551FCF4A13DAULL, 0x81FC0F943D071EFBULL, 0xD74CBE50C657D1E0ULL
        },
        {
            0xDFAA1E1ACBE591C2ULL, 0xEADC137B57CA404FULL, 0xC190B8B1A0A45332ULL, 0x1CD3DA0FAFEE6AFCULL, 
            0x3574D70902F18253ULL, 0x960CFFF214A81F8FULL, 0x401DFE19FDC791A4ULL, 0x23C045F09CE53005ULL, 
            0xDF3A4B332E149A91ULL, 0x2042BA2072BF0069ULL, 0x07641E7A032E057FULL, 0x7D91BCF138F791D5ULL, 
            0x6E440B0EAF516C15ULL, 0x0E3587A46E84FFFDULL, 0x8B0EB2E13666E0E4ULL, 0x4BF1393862C75177ULL, 
            0xD7BF1C159090F043ULL, 0x44D20DC39F1F821CULL, 0x63727C04373B60CEULL, 0xEE521C226FDC86F7ULL, 
            0x85990E587B6E7A7FULL, 0xBDB5F79117C8AF89ULL, 0x6B2568CB30CF76CFULL, 0x6C11908183D42886ULL, 
            0xFCFD7612E78C9376ULL, 0x69CC0C2F9E1F181EULL, 0x3FB8D02B1230A447ULL, 0x8F136D7B33FFB728ULL, 
            0x48FFA53810222002ULL, 0x6A174D516C7278D9ULL, 0x7F5FF5E99587F0F0ULL, 0xCEB463ACBBA841AAULL
        },
        {
            0x216807E96D3F5991ULL, 0x654834CF8E93D0D4ULL, 0x6715DD5332542F06ULL, 0xF388660CA99F7BACULL, 
            0x12E90D0D95E5F332ULL, 0xA5AF0AD9F4888B7DULL, 0x33FECE8F8B330A38ULL, 0x1695446F56ECFBDCULL, 
            0x0D8AF2D5BBF6F1A7ULL, 0x335EFA1C070AE74EULL, 0x96AB118ED68BE8F0ULL, 0xACDF3D3623C0AF72ULL, 
            0x066229C8460E02ECULL, 0x2F0297F294E1D727ULL, 0x81C737EDBAD28E19ULL, 0xB6F67134EB63646DULL, 
            0x081BBD9D7708EE25ULL, 0xAE9CA6ED1D1105ECULL, 0xB6A29CE8FB8AE401ULL, 0x3A25ACE845EE26F7ULL, 
            0x8160AE93C06E019DULL, 0x1556FCE18A0E1E01ULL, 0xBB1D50BB90C54F02ULL, 0x146C2890716BB785ULL, 
            0x0B545C589084FC09ULL, 0x39D2EB07F438284DULL, 0x4CB4F7A397DADB09ULL, 0xA26AD30783DB1438ULL, 
            0x4D402DF148424C87ULL, 0xC85ECDCB7CC03D33ULL, 0x2AD321BCC903AD27ULL, 0xA808905B7B7B9A97ULL
        },
        {
            0x55B8D1889899A5F5ULL, 0x33C8169AC1E09119ULL, 0x9A966AA0BEF2F469ULL, 0xD1CCA48295206C3BULL, 
            0xFD05681F082FEFA1ULL, 0x80DBB87E3EC194C2ULL, 0xBA3051E1292608D3ULL, 0xC00494901F394297ULL, 
            0x41FD1FCC2EAEDB4CULL, 0x257C24FDC4809F88ULL, 0x8C2B3A7BA9B5A358ULL, 0x0EB81D7B990096A3ULL, 
            0xD3CA250FF7113BD7ULL, 0x446135BEF443AB2BULL, 0xB8C45892D8506E15ULL, 0xB8E9BDBD74DC9A60ULL, 
            0xAC80C24C6479F945ULL, 0x4822D370226E40F2ULL, 0xEF259306F7DC0D46ULL, 0x390A54B1CC564C27ULL, 
            0xED03403DAE91946CULL, 0x9E1F2F6BD2E394C2ULL, 0x3075F97622E99C5EULL, 0xE74324E6ABF61AEEULL, 
            0xE5C1282275B54888ULL, 0x9CA34434D2C5DB08ULL, 0xCC82678048A645C2ULL, 0x00BE19056B87883CULL, 
            0xED724020988DB2ADULL, 0xE11CA91691DCE2B4ULL, 0x20CE7AE4C69BCEF8ULL, 0xBAF95AA77B5819D8ULL
        },
        {
            0xA416FD1965A5C758ULL, 0x0F7D381A245EB3F2ULL, 0x4CFADF1B8CC25E39ULL, 0x78ABCC176C2EDCA5ULL, 
            0x08B610CB878F7033ULL, 0x3F99A9B83C954060ULL, 0xD755A5FAC2E5D7D0ULL, 0xA5A10D6FFFCB992AULL, 
            0x29529C0D00ED7C5DULL, 0x2ED6531A1C6DD006ULL, 0x1C9368181C07BC24ULL, 0x8E02D3A04AFD0CEBULL, 
            0xE33568EE6749E767ULL, 0x44EB7BD685292961ULL, 0x081BC1F91387E127ULL, 0x3171DE0971F86AE5ULL, 
            0x352727826862AD2BULL, 0xF94C01DC63BB922BULL, 0x9946CC422FF1CECBULL, 0xC183C3A8D743DBC5ULL, 
            0x1E393A8F0B166904ULL, 0x0769E820B0190B42ULL, 0x6A276CDC548A5936ULL, 0x46CABBD35B921174ULL, 
            0xD76AFE8D302F799CULL, 0x9C2145292B466BF4ULL, 0x51DE3D7865210220ULL, 0xE8D38BEE6529F918ULL, 
            0x3346BC18D8BAA477ULL, 0x1CDFA99BCA0E77A1ULL, 0x29AC8B23D62EB43FULL, 0xD6CFC35D9157C876ULL
        }
    },
    {
        {
            0x7DEE27722A9D02B0ULL, 0x2CE5EBC81FD5C605ULL, 0xDF6CEA8036A53CC1ULL, 0x9284D1247E7A6ED8ULL, 
            0x25C6316E73F2DD1BULL, 0x6670AE67415BEDFAULL, 0x9907157F86E521DAULL, 0xC353B8ABE77746D2ULL, 
            0x320D1D2D95DC8B28ULL, 0xB02E1463C2344773ULL, 0x294D410205CD012CULL, 0x418AA9FC243DA185ULL, 
            0x7D137CE2AC50DD02ULL, 0xA23BA2BCB7FE0BC4ULL, 0xE9F8E0B9A673C762ULL, 0xE4DD3A248C50C6D6ULL, 
            0x8FF0A5DF2C7FC7CBULL, 0xF21FB2B4E764700FULL, 0x48A339CFC9716883ULL, 0xF04E5E92CA085477ULL, 
            0x08F3F6957980705DULL, 0xB82679BEFA8EC6DAULL, 0xC2EAE0208AAFDDC2ULL, 0xE34EC46B3D78E667ULL, 
            0xC7230472EE66D1B7ULL, 0x71B849D9C2AF0403ULL, 0x7F8A27EC8FE20625ULL, 0xDB6DCAC16DB08A3BULL, 
            0x0E1B38ABF614B77AULL, 0x356D8C0B434673E3ULL, 0xA79E6E368C4FC2B5ULL, 0x4871032BC0D9501FULL
        },
        {
            0xC22E450763D2C58AULL, 0x20B1053CF36AD9B6ULL, 0x737CD37C75027561ULL, 0x23FCDE911E817632ULL, 
            0x4B3D8CE645B18F75ULL, 0x48A9B553267542DDULL, 0x6293772C084A0E7FULL, 0x05725E863D3EFDB1ULL, 
            0x11F8CD5352770C4AULL, 0x0B61F58AA67A2CB7ULL, 0x8C394839396D6BCBULL, 0xBDFC3190DCE670A7ULL, 
            0xEA192BE2450B014AULL, 0xD5F914B17F8ABAC0ULL, 0x95831BC397FF21DEULL, 0xB9D6687D222F0A21ULL, 
            0x96495C8B407FB722ULL, 0xCAFD79A2C918F684ULL, 0x7A7462A6648FE7DBULL, 0xA199FE4A7CD5C6ADULL, 
            0xDF8C5ED14D47EBFFULL, 0xB34A58DA04C11D0FULL, 0x11CA18053D4351B6ULL, 0x653FA4EEAB2782ACULL, 
            0xD5113D59D216060FULL, 0xA32421C74F75CA07ULL, 0x8DDF7E052A6A3E9EULL, 0xD774095AA78DB047ULL, 
            0x6A8EE255C10B367DULL, 0x63A37E1405444787ULL, 0xAB8EAAEFC2176B19ULL, 0xD7D53976CFEEA18AULL
        },
        {
            0x3E09445F07BF6302ULL, 0x26E6B33426CFF909ULL, 0x553EC5FDA33C5F88ULL, 0x5452D8733EA90E2BULL, 
            0xD9634D22683740F0ULL, 0x64755A2A34542BC1ULL, 0xFCCF0D9140CF6B21ULL, 0xF4C190F3290F6944ULL, 
            0x9E6015B1C237625FULL, 0x5C4328D5849E5E7CULL, 0x631E416EA164F5F2ULL, 0x30E6107495C76F60ULL, 
            0x1A442725871F5246ULL, 0x9650236263772622ULL, 0x5B5347C499603C4AULL, 0xD7B6D1CE35DEDA81ULL, 
            0xB916A9D7B2278DAFULL, 0x070A7BD74E22A051ULL, 0x00EDBBADDF947C03ULL, 0x9F6B2B5239FA2C21ULL, 
            0x435ABD8CC063C331ULL, 0x97415106B9C90C62ULL, 0x8C1E7BEF64317589ULL, 0x8BCFBCC8B8FDF150ULL, 
            0x114D9D99CDFA22EFULL, 0xDF708965FDADF999ULL, 0xFD760D88C4D759B9ULL, 0xFF09DD9C060961D1ULL, 
            0x98B0A3E3A89F6791ULL, 0x5BEA671A01196FE8ULL, 0x11C455FD720D6FF0ULL, 0x130370ABBE0BD577ULL
        },
        {
            0xB4290D2FCDA909D9ULL, 0xE6CE3FBFF712738EULL, 0x3CF8C65800CD96EEULL, 0x4180221304873E0BULL, 
            0x13FF33FDC4584293ULL, 0x772F2BA8A02FE1CFULL, 0x2A63DBED5487E775ULL, 0x7F66F893083933A2ULL, 
            0x46821F94A1E439A4ULL, 0x3E40E4BB6040BB92ULL, 0x50AE7F8699412B08ULL, 0xA115F3E2082C53F8ULL, 
            0x3A57863C0DBEF70EULL, 0x7137ED11702EB37EULL, 0x344B9E16FD20EB24ULL, 0x3A5258F4D6E5C0E8ULL, 
            0x591BF3C74DFD4CC4ULL, 0xFA791886F4F2DAECULL, 0x43DDA58AF96C8DD0ULL, 0x23BEEE29A24FFBFCULL, 
            0x34FB39BB24C19BB5ULL, 0x5FA7171D472E8BFAULL, 0xB0397606F11183B6ULL, 0x4DE44B0196A7779AULL, 
            0x973B326606013D13ULL, 0x85379B85346EAE2BULL, 0x8A0B84668214D665ULL, 0x03B54986C81949BEULL, 
            0x8204AED804F4A481ULL, 0xAE3C0BFCF3AE0355ULL, 0xA2193243A0551692ULL, 0xE292431706AB4965ULL
        },
        {
            0x74F39C4577598EAEULL, 0xAFC6987692B867DDULL, 0x79EFDDA41080D982ULL, 0xB4A47C062EA9D5D8ULL, 
            0xB207EDE1883DA327ULL, 0xFEAD018996028A90ULL, 0x8570D6E4932F117BULL, 0x582D7DFB693A876EULL, 
            0xDCFFCF9B80ECFD1BULL, 0x4CD697AA369EDACAULL, 0x10204B613A5A1860ULL, 0x867758F759C0E4F1ULL, 
            0x9BB19253D2C5716CULL, 0x9BCE3C1FF5D902CDULL, 0xB160F582141BDFC5ULL, 0xBA1866D3F20BB747ULL, 
            0x494B6EA691A38047ULL, 0x54B4FC0FA253E142ULL, 0x61D3EBE4D0AE6657ULL, 0x57B32863BD0EA93BULL, 
            0x6136C305B0EE5444ULL, 0xABB41AD5DDF9CF34ULL, 0xB0AC31E4FC14AE4AULL, 0xDDB8E9ACAB51BDECULL, 
            0xC60AE224AD2D3DA3ULL, 0x47BC02E99A071DE8ULL, 0x04AFB9DED7F3FDB7ULL, 0x444D2AE59EB9FD87ULL, 
            0x2453B3209A9158AFULL, 0x919B506936EC631EULL, 0x63D67E9C3C3F4D3AULL, 0xF60409EA2B941172ULL
        },
        {
            0xBD6AD7AD6921B147ULL, 0xDCFBC0112073DA2FULL, 0x3CED5E21DFB68663ULL, 0xF2B33EBF8221CCC0ULL, 
            0x05B5BB5FE20012CBULL, 0xB205CEDAB63CA8EBULL, 0x0C84C72B31DD17FCULL, 0xA559A6D69A161D54ULL, 
            0x0D50E2250E2C732DULL, 0x0EE15938A226D910ULL, 0xEDBD6BA2D7A82355ULL, 0x421C753C117CBC71ULL, 
            0xADA97F8887FB2B11ULL, 0xFC90EABCD5400285ULL, 0xDBA71CAFAE2D7C28ULL, 0xB8911DC2ECF99975ULL, 
            0xD864FBEECC34C06BULL, 0x85102EB39D1587A5ULL, 0x424FEDEBCD8FAC92ULL, 0x4DA75EFA2729C6CDULL, 
            0xBB36805199BD7AA5ULL, 0x206E59A7C6199642ULL, 0xFBA46AD9A5D0D6ABULL, 0xAD9601B4FACCC149ULL, 
            0xE8D02878A7F14F18ULL, 0xFA97B33DAC6C63CAULL, 0xA784668B8BA67C92ULL, 0xE78EA3548237FE9AULL, 
            0xD100387E9C38DDC5ULL, 0xE18B06A7240AA1F4ULL, 0x070D784D7026D96BULL, 0xA323BB41E08A01F3ULL
        }
    },
    {
        {
            0xB403CA4D99A2D7D2ULL, 0x3BCCE71ACED99625ULL, 0x8C13DE4615E51BE2ULL, 0xE331B5AA5B7BB6B0ULL, 
            0x9B255DE052A97342ULL, 0xA89E1F002972ABB0ULL, 0x7677F22F78E7EA9EULL, 0x76A6DEC62FC9F1B8ULL, 
            0xF871D034A9EE6C82ULL, 0x6DCA1F53E52B6475ULL, 0x2D022CF88FD08589ULL, 0x7A208A72E73BE0F9ULL, 
            0x2C40D64A6DF66597ULL, 0x32DE1213713CA056ULL, 0x7C0505096F40C228ULL, 0x739F54E39CB8D8CCULL, 
            0x5B793E37DD072A88ULL, 0x7910F82F6E2C01C0ULL, 0x918CFBE8D9500A9BULL, 0xA63285CC7ABD7C2FULL, 
            0x277432B6C316A324ULL, 0x07E834DB9CA845DCULL, 0x7523B34E6004E0EAULL, 0x1C41C25215E01B95ULL, 
            0xB3E3314150E82590ULL, 0x05F16683520B12EDULL, 0x51EE6DD64893DF79ULL, 0x2D46C74525F7E911ULL, 
            0xBDA55A387AF049BCULL, 0xDA830C4114B48CD7ULL, 0xDE1D9615BB95E90BULL, 0xCD7B005935A2FCAFULL
        },
        {
            0x8BFC8FBD845B03D0ULL, 0x332A60CCA5213464ULL, 0xF942D1C175962E8AULL, 0x49C0EE46DDE0B711ULL, 
            0x0A23B7C1764FD5FCULL, 0x58FDDADE15FA75D8ULL, 0xBD04A96BCF120829ULL, 0xAB4AA164B2967127ULL, 
            0xD4A8E21573A8194DULL, 0x90C8F77F9BC50140ULL, 0x91558661A42CACD5ULL, 0x2AE4198367A22C20ULL, 
            0xB0DCE3A531DB881CULL, 0x8C5198F07ADCB99EULL, 0x5A6F5C2F5906DD5EULL, 0xB65C1AA69F77CDCAULL, 
            0x24572408143A7E97ULL, 0xD8CA672831BDE783ULL, 0xF3EE79F4F77A4CB5ULL, 0x1BBCA272DA21D1E4ULL, 
            0x992BCAEC8368CE84ULL, 0x89C4482039C44B5EULL, 0xB2DEF73993047E94ULL, 0x61E6C8FB6F22559EULL, 
            0x2A3DA1890C6D0CEFULL, 0x3C342AA89A8BB1F5ULL, 0x9E63C67D63D77041ULL, 0x7CB352C8C971D742ULL, 
            0x886E93216A20EA0DULL, 0x7CABFB36BD1FB274ULL, 0x51BAB09044A84AC6ULL, 0xAD313889536B92DFULL
        },
        {
            0xE5DF7A72AEE2EF63ULL, 0xFCCC0556AFB38CB7ULL, 0x0413F282FF5DC700ULL, 0xACB082380E2A5D79ULL, 
            0x164AC0FB58194C20ULL, 0xE7C7A839A168C1D5ULL, 0xF2D201A997E5FB19ULL, 0x72EB87EFFA08BC89ULL, 
            0xFBC0C7667C2CD3EFULL, 0xA739E21D332B5777ULL, 0x7D439273FB384F4FULL, 0x6684CAE46BC476B8ULL, 
            0xC65EFADC25BA7EF9ULL, 0x268787798A6034CCULL, 0xDA9AA2C115DA282EULL, 0xA9562D079E7A7BE4ULL, 
            0x4795704C0A5CB616ULL, 0x88597F5456CFDC33ULL, 0x94786B586567B331ULL, 0x95391FD3B410C182ULL, 
            0x0E267E3F54EF2A6DULL, 0xE2BB7A185957289AULL, 0xD59B3EBF2082184BULL, 0x8843C971EE82537CULL, 
            0xCF6CCAC910F99ACAULL, 0x662653305AF9347DULL, 0x3B772F9D65A017A3ULL, 0xAFE2CDB98DA47F36ULL, 
            0x6E7134C0E03774C5ULL, 0xA8A8891485EE1680ULL, 0xE369035BB8E5E741ULL, 0x3577CC1A72DA0A07ULL
        },
        {
            0xF8A6A3ADB9F39C03ULL, 0x6FE02AD2FA709FC3ULL, 0xFF43C3280CDF3C73ULL, 0xBF4B3CB1448F5A1AULL, 
            0x1A1F31A2FE0A165FULL, 0x0712631CA7D22E93ULL, 0xAFCC0F8573D69A90ULL, 0x0A6CCBA3CC8E408FULL, 
            0xDF2B3233BDA94ECCULL, 0x716D49E2717DFBCDULL, 0xB82491A73E4E9B00ULL, 0x511E53515BC5D3BEULL, 
            0x315033D9FB999BAEULL, 0x76CF7C6A2F2F3567ULL, 0xC22FB8D07FC6170BULL, 0x90AA43CD0A3D3A42ULL, 
            0xE23A921757DF5F39ULL, 0xEAE9F5C5F2E8F55EULL, 0xF97EB290B202D275ULL, 0xD6E05AA4F7D40460ULL, 
            0x4B9306817C2B1125ULL, 0x529C13D0FEE30BF7ULL, 0x38018B200F195094ULL, 0x7DA6F7D1E691B0F9ULL, 
            0x15ED0E17DBABCF8CULL, 0xEB11D31316B674E2ULL, 0xBE5045AEC561CECAULL, 0x515215F38C7FEDACULL, 
            0x17E8AB972E225537ULL, 0x0F447EB16C127710ULL, 0x8D646741416363E7ULL, 0x648C34D97C0DB2E3ULL
        },
        {
            0xAA131711CCA5ED0DULL, 0x81FECB6A7D635D0EULL, 0x05580E9BC030B666ULL, 0x8B8843A3D652F0DEULL, 
            0x0314FB792E2A8670ULL, 0xCE21938E5EBD7D0BULL, 0x2613D6D6220E5097ULL, 0xEB06D55B0C043F2DULL, 
            0xACC5C41B4B5E63EEULL, 0xC0A75B3850BA58AFULL, 0x5B0679009D315AD9ULL, 0xA28D8C0BA279DC13ULL, 
            0x8A882277346F54C8ULL, 0xA9C9A1CFEAB86B7BULL, 0xB9F355F24BA4799CULL, 0x6466F7B0941E1D9DULL, 
            0x0006A294DCEC6A33ULL, 0xDB4624F0616CCC8DULL, 0x5BF32BC527BE1207ULL, 0x2B542545326F8D8AULL, 
            0x767FD8812DEA4E60ULL, 0xC1B028798D32B38CULL, 0x61348027C1A09635ULL, 0x90FFF469D74A49DCULL, 
            0xB570E560F08D69EBULL, 0x1FCB687F2D89EB0CULL, 0xD414CDECDDD15BA0ULL, 0x72098B7F73051DBBULL, 
            0x146BA699F9099AA6ULL, 0xF3AB3D0CD788AF0CULL, 0x83A8F7B3999662CAULL, 0xBEE0648681E002B6ULL
        },
        {
            0xB9192109738D5D2CULL, 0x945CD4E08A57C8CBULL, 0xB6E53109C98FCE5AULL, 0x3AC4E649AA6A6D42ULL, 
            0xE14EE9B716664549ULL, 0x93730EA849C0E588ULL, 0x5D248D99A3F1E05DULL, 0x54E46736BE35F81FULL, 
            0xAF59F53571EDD0F1ULL, 0x03498FFB0CAF928FULL, 0xA2A7CF4B81B3A691ULL, 0xD2540D53E74E0F38ULL, 
            0x6499CBB66CE8927BULL, 0x6F8D3F0F57EC664FULL, 0xA4375E72F084AEBFULL, 0xC638944B8637BE22ULL, 
            0xB0CB3AC2F33D7B3FULL, 0x1F0787B937B99D62ULL, 0x86413F7A38E80611ULL, 0x21B2ED1DA54D2889ULL, 
            0xB1261DBDDC425D78ULL, 0xE748B98BA540CC45ULL, 0xB7B32811DF412D07ULL, 0x64F3EDDEB6EC3A8DULL, 
            0x0F3E403E1B23975EULL, 0xCC7EED96D7165DC5ULL, 0xB76B0CF5EDBE772EULL, 0x0D428ED48E713400ULL, 
            0x150EFDD1925F35C0ULL, 0x5D1CACA5D12AC058ULL, 0xA0B7FDE192A85BBCULL, 0x11547751CA1C3A77ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseCConstants = {
    0xBC2194B3FBFC9D3EULL,
    0x393FA299E7B5C965ULL,
    0xF5D0663AF2CE7DC4ULL,
    0xBC2194B3FBFC9D3EULL,
    0x393FA299E7B5C965ULL,
    0xF5D0663AF2CE7DC4ULL,
    0x6B619D681E7D92E7ULL,
    0xC40EAACF92812D08ULL,
    0x23,
    0x06,
    0xAA,
    0x6A,
    0x45,
    0x24,
    0x65,
    0x9E
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseDSalts = {
    {
        {
            0xA65BDB012DDF6DFFULL, 0x39D6305B84F16B98ULL, 0x9E77B930032EF72EULL, 0x50A21FFCBE052EC6ULL, 
            0xBAA835514CD5110AULL, 0xD2ADFD27AA83FC8AULL, 0x8AB0F1C6C3CAF8F2ULL, 0x0E53C504B9C6A3E8ULL, 
            0x7B361DD05A50952FULL, 0x59260E8105EFECCEULL, 0x16104A44DE3A05A8ULL, 0x7C4E52B0DE5FC855ULL, 
            0xD661D6DCBD5EA106ULL, 0x7E3C46B1A30D021DULL, 0x06AE2F70E254F1DFULL, 0xA0DBB569541A09E5ULL, 
            0x18652977A721C649ULL, 0xFC290607D30B0B3BULL, 0x0037F7F1B1BF7238ULL, 0x9BE579FC15466F4DULL, 
            0x668380A76BB4F7B3ULL, 0x8872565DFA7A755DULL, 0x842EAB3953CF3130ULL, 0x9240DB5233C102F6ULL, 
            0x71843626F4EA8871ULL, 0xF8254B9323A4DFFEULL, 0x2E7F787A460E2ACEULL, 0x8F039A59FBE26BEFULL, 
            0xE6B9D5B709D19EB6ULL, 0x9E7ADA0CB0CF1B50ULL, 0x63DA8303140A07EAULL, 0xB65A7652FC4B7840ULL
        },
        {
            0x9DBC81F189942439ULL, 0xD38F581D953C6E28ULL, 0x6254E57322B602FBULL, 0xAF692EE20398A05CULL, 
            0x85B9D225E838940BULL, 0x8A2A01CAFD241FD8ULL, 0x03638FEE59290C92ULL, 0x8897691373FE601BULL, 
            0x9DC5E501BD0096ACULL, 0xF1BEECA3F56F8E9AULL, 0xB1755FE9751CD36EULL, 0x9247A91EC37D0F15ULL, 
            0xABDF6B3631EFDBC6ULL, 0xFF5ED59E34C1B29EULL, 0x6FB35CBADF8A591AULL, 0x6BA7F41C9B6E992AULL, 
            0x5FBF2501BFCF27F9ULL, 0xC9F784767B473086ULL, 0x217A24B90EF00D35ULL, 0x7A16B0F9EF5D91ECULL, 
            0x4EEDEA802B54387BULL, 0xCF1485E5489539E1ULL, 0x46EDA9D834A56276ULL, 0xB7986B8EBBED1F89ULL, 
            0x56A953EA35E72FB4ULL, 0xF27752D1DDC3BBA7ULL, 0xC141FF4DCB66EAA5ULL, 0x8B702B573949C6CFULL, 
            0xEB6D2C08E16239E8ULL, 0xAE68E0958A866B80ULL, 0xE292199982593680ULL, 0x90F1CBE1CAAA1284ULL
        },
        {
            0xDD764249DD9BE8A5ULL, 0xFA036E4B65D5D51BULL, 0x7229B1575A366397ULL, 0x63F05EE6375DA61CULL, 
            0x2F0C9E42C0C78357ULL, 0x97DB701681C30CDAULL, 0xE11CC974998C2150ULL, 0xF06F55D45363AD11ULL, 
            0xAE5DCE9D3E337721ULL, 0xFF1BB11BC39C04BAULL, 0x6AD5BC407B78BBC5ULL, 0xF23893E5ED7BC27AULL, 
            0xDB99D036756A2554ULL, 0xEF0B3DE7A8D5B3D4ULL, 0x30D7EEA8A7420F50ULL, 0x6CB6E154EF7A0891ULL, 
            0x7E8BDD61BF8D28AEULL, 0x210EBC0AB632DD99ULL, 0xECCDC84C271625E2ULL, 0x8A3E6D410C0284A7ULL, 
            0x5702AA10A1BAD56CULL, 0x83FD435FE07BD7E5ULL, 0xFDEB9727AEC3595AULL, 0x76025DE3A9DDED0CULL, 
            0x966705C0C110C2B6ULL, 0x19414677A8B86374ULL, 0xF1C9BD2C780AD99CULL, 0x80C9B16C6D6EC85AULL, 
            0xC6D2994FB71D95C7ULL, 0x4DD4510E2AA11D66ULL, 0x9FF072A2A2F868F3ULL, 0x5662332CA01D869CULL
        },
        {
            0x67C91F51A20933ABULL, 0x0FCF37A802EC0959ULL, 0x310B9E4E228F7601ULL, 0x87E44F9154ABF2EAULL, 
            0xD9EAD1CA75312F56ULL, 0x36FF1A7D51AB081BULL, 0xD3171DE0ABB01002ULL, 0xB11835D4B62FF9CBULL, 
            0xEA9A1101C840F40BULL, 0x546F1F655EE06A70ULL, 0x347CCD6D5B726DAEULL, 0x718E7DCD724E7D0CULL, 
            0x92F1742218E1F4D6ULL, 0x27DF221C6EFADC57ULL, 0x3777281BC530AADFULL, 0x384E825BA718505EULL, 
            0x8EDC0CDDDB7FCDD8ULL, 0x3D9E70CDD5DA5E3CULL, 0x7A852985430621C6ULL, 0x9976014EF74862B2ULL, 
            0xC9F15317FF09CB65ULL, 0x3CEC87CB7E4B0F24ULL, 0xF1B3A1E5B4D46604ULL, 0x70527853717CEB89ULL, 
            0xC8D4E145BD2D0F3EULL, 0x06E5369EE8A34A80ULL, 0xB9F5792093457D72ULL, 0x3FF66291010BF6CDULL, 
            0x6D204406FF02A47BULL, 0x3FA2A425C184AA97ULL, 0x9665C20B8D4CE043ULL, 0xB534013CD6397BA2ULL
        },
        {
            0xF3FBA510FFD15FC0ULL, 0x9BF4CDED1F5006B7ULL, 0x6160204798451B85ULL, 0xD9F1AE710F135A0FULL, 
            0xD4B338FC97581C0FULL, 0x0470DB4EF6D194A6ULL, 0x5164E7135B342416ULL, 0x5D4897B558FD712EULL, 
            0x1EEBB202A5AE3D22ULL, 0x163C56CF5ED01F06ULL, 0xC6BAC7A34E2572F7ULL, 0x7FE941D01B3137BCULL, 
            0xDBA921D656ED9E47ULL, 0x8C17F13F712079ACULL, 0xE7FF913BBE617B2AULL, 0x4DFDD0646293B357ULL, 
            0xBE343D64D22D6C3AULL, 0xC1857D044C767599ULL, 0x5E5F796CC9FAA7F2ULL, 0xE28EEADF2BFD4F69ULL, 
            0xA87669C369BF9B5EULL, 0x54D1B65535D8B486ULL, 0x7509AD6815918495ULL, 0x03FC8ED1A9D0B232ULL, 
            0x036DF0360B692D0CULL, 0xC47F9FFA4BD16042ULL, 0x49B6CDD063CE1C2EULL, 0x7C826563A93E5EC9ULL, 
            0xC65084D272CDA03DULL, 0x499657CF341D0F03ULL, 0xC8FBBD17D7D46DBBULL, 0x5526674988774DF2ULL
        },
        {
            0xB9BA363FAE5B9A5DULL, 0x13FFF669FBEDC219ULL, 0x640CD0ECC53582A4ULL, 0xEB2EBF008444FBC1ULL, 
            0x749684116DF23D2BULL, 0xD2638D199E9183DFULL, 0xCD5B06F3600AA058ULL, 0x180CA8377515C34AULL, 
            0xC66A8975E9F7A68CULL, 0x4C9F30E556952A35ULL, 0x3747556DAF5775C8ULL, 0x12C878DF41DB6CBAULL, 
            0x338A4CEEF1DC9D4CULL, 0x3BA9A852333DDD86ULL, 0x181C398C0CFC763CULL, 0xB0A4A220A829D8CFULL, 
            0x8E99B772F2AB6997ULL, 0x8E5509AD9BB6F07DULL, 0xCAA60CC9CD0BA36AULL, 0x5706FEB53B32D192ULL, 
            0xE01C30EF21E81C8BULL, 0x1E8852D9518874ECULL, 0xA9158B7CF8C4A051ULL, 0xE5DCD2B2F573C890ULL, 
            0x8CCDE62802FE45B8ULL, 0xE6E81A93E5D5A5F6ULL, 0x00882FCCF12671E2ULL, 0x0AA000A993AEB168ULL, 
            0xCC3EA9897ADB5757ULL, 0x0C13D12D6B91926CULL, 0xCA0968F9AA09280EULL, 0x03197B7EE8A2ACAAULL
        }
    },
    {
        {
            0x548A7539EEFB93A6ULL, 0xEF5F00D8DD2CEDEEULL, 0x1317967B09FE91CBULL, 0x8E7878513F640979ULL, 
            0x563A6FF0736CE62AULL, 0xB1FCD313ECADD0D4ULL, 0x9CEF4B6330674F98ULL, 0x0EA29A12313850DCULL, 
            0x1F3284F8FDF510A2ULL, 0xE45BD7BF3247D82AULL, 0x027C1CF54CE8A8BCULL, 0x284B3DB9DD668311ULL, 
            0x454E36F2E773B520ULL, 0x2D2428A862A94425ULL, 0xC1BCF05F908F49B0ULL, 0xA71F892D492A1022ULL, 
            0xBDB5C9F9763F78E1ULL, 0xBBB4ABB5D486F3F3ULL, 0x1B85B229E2BDAFB9ULL, 0xA3ED9D955144B661ULL, 
            0x6D2312F0EC5126AEULL, 0x33ED33F0E865677EULL, 0x0F889D651AEE37BDULL, 0x32183310718581F3ULL, 
            0x3FEEA88D7C2F0070ULL, 0xD84612AA282B7A1AULL, 0xF3D90FA547FF9CDEULL, 0x1DB24F46506DB89BULL, 
            0xB9158E3D20BA8A0DULL, 0x7AF91B5619207632ULL, 0xFD41B9CF32AB9C81ULL, 0x8B34EB860758261FULL
        },
        {
            0x95F342B827FDE40BULL, 0xE3244D06C17CBCB9ULL, 0x493435D840CC5C50ULL, 0xC731BF813707D317ULL, 
            0x2081D525984A4D35ULL, 0xCEBE2B2BE505B7C8ULL, 0x3CFA9534E63CECB6ULL, 0x921D5A426606F2DDULL, 
            0x08CAA69E1AC17B41ULL, 0x7F3BB6BA6F22E3BDULL, 0xDD74CE20227F1B25ULL, 0x5A9D6264A88C5CD8ULL, 
            0xA678D1E1411E943AULL, 0x68C9C3DFF7E453F5ULL, 0xC6EB018597F83CA6ULL, 0x7705015CDE6B391EULL, 
            0x4793FC3AEC926234ULL, 0xA29AE88F12C934B5ULL, 0xB8FFCBC9D4C6FB5AULL, 0x0BF6DBFF7E5D5D6AULL, 
            0x0B68F6428873BB18ULL, 0xCC1EAF798FAC2D13ULL, 0xE82B4EED5ABDE96DULL, 0xACEE7F943C2B4353ULL, 
            0x543AC1FA4477E07BULL, 0xEC05A2E834902426ULL, 0xC53045FC6CEA459FULL, 0x7B959FBDC82697AFULL, 
            0x9229908DD720B033ULL, 0xD9A2620453896453ULL, 0x356DEF54DB6E2B8CULL, 0xF01143B36CA1BB7BULL
        },
        {
            0xED5311B289325200ULL, 0xD2D42C87A9203A87ULL, 0x765EBE8552656176ULL, 0xA60E44F9028682EEULL, 
            0x369AB02C0B0A03D4ULL, 0x9D5438804C62D25DULL, 0xF8EE6D50D923B48BULL, 0x274F740DE2B51716ULL, 
            0xEDB9000CF1387FDBULL, 0x93BA76670892D89FULL, 0x88478532C3713A9BULL, 0x3CD346D6B4300D13ULL, 
            0xB00ABF5D794DA5FAULL, 0x48A6A908EE0B111DULL, 0x0EA1BDAB96DF8F71ULL, 0x7ED53D9D09B4D8C2ULL, 
            0xB3E6775530E43717ULL, 0xF7FADBE69BA15A4CULL, 0x8E51824F58EEE26FULL, 0xD041A4B3280B6E9AULL, 
            0xC36A63380043507AULL, 0xAE30EEE894338956ULL, 0x056FC86CDBD63442ULL, 0x24FD781ACE682093ULL, 
            0xFFAE881EE1651003ULL, 0x26625C4C294FFD29ULL, 0x2C14F76C93B181CCULL, 0xFFED80957AFDACEAULL, 
            0xA65FE825761A49BBULL, 0x242E9886ACF92E0BULL, 0xBFBF39FA91EFD1DFULL, 0x61E5F07DFB2E83A6ULL
        },
        {
            0x65A7603332C4EA34ULL, 0xFD052D7783C96D95ULL, 0xE3728127BA8BEDB5ULL, 0x4FC917C11748F08CULL, 
            0x7FD6B5FE279E2E6CULL, 0x77AF72B52176D602ULL, 0x96F796823DCA2678ULL, 0x2A1D7251BA1F7D5AULL, 
            0x7CE71410D6696B16ULL, 0xA61FC0C95AD5D77EULL, 0x33E52514DC355862ULL, 0xC0DB8BBEC4BB659CULL, 
            0xCAF6F05B6F3A550AULL, 0x6E1ECB725C25A365ULL, 0x2B154AA3E23370ECULL, 0xBB3797F8EDCAD797ULL, 
            0xC8164E6A9C93EB2DULL, 0xDC8935C5494821EFULL, 0x49B96FEFE2FBA9F8ULL, 0xF654D2680F9FF48CULL, 
            0x1DD251A60CA025FFULL, 0x0533FC7069622ECCULL, 0xE871C9C6F0BC38B7ULL, 0xFED84B0CA6473F2EULL, 
            0x49309402B9B34FC5ULL, 0x09322935A7D6865EULL, 0x4668750400C9E25BULL, 0x18AFE70CDF9DE57BULL, 
            0x53471C2B474BB563ULL, 0xED2CC577C9B18DB5ULL, 0x2A5108B07888F377ULL, 0x81F6FD457CF2C1C9ULL
        },
        {
            0xBE64AF6F036FB7CFULL, 0xD45885656C1018D1ULL, 0xD9B146BACA44E273ULL, 0x98EA768DAE9140CDULL, 
            0x28CA0311A4AEA150ULL, 0x905641C16F3A3CB3ULL, 0xF04026EA2B319A8CULL, 0x3A2C19384FDFE42DULL, 
            0x438A15FD85203C88ULL, 0x9A803C5C85BF26EFULL, 0x05102CA429549859ULL, 0x810D256B84BE19CBULL, 
            0x625A0C5B3644722AULL, 0x4A085F25349D64C9ULL, 0x7B3E7B259736BD15ULL, 0x90B6978B3C8290D2ULL, 
            0x2C79ACC31F75C42FULL, 0x416E31508AA13EE6ULL, 0xF9CAD958802D453BULL, 0xC01C35DDA6755A28ULL, 
            0xA04E63F58A34B598ULL, 0x2F724E142B3651EEULL, 0x281B7C4C5836594DULL, 0x3DABE7AC49170305ULL, 
            0x45C94C45A436F1E2ULL, 0xABAD27A5129DF2C6ULL, 0x2476922AF737725CULL, 0x2B23373C7BAAACCAULL, 
            0x41321E078C136B97ULL, 0x3462B93526F17B4FULL, 0x8F569226EBF47CC6ULL, 0x86F28AB6260FBE8CULL
        },
        {
            0x9547BF3E7B1ED484ULL, 0xF4032464E9261E7CULL, 0x0A4A85EFD72FF045ULL, 0x5787CE3FC9F905D8ULL, 
            0xDC8E7FF028565D15ULL, 0xE462AC6CDC54712CULL, 0x7F8EA1D621101BEEULL, 0xB7B653E667BD2929ULL, 
            0x0F6D8F5C48367AADULL, 0x386054959591B3A9ULL, 0x1358578A06FAA568ULL, 0x6661F73FE0CDD347ULL, 
            0x598D9D6412F03614ULL, 0x5A1B1A42AA56144FULL, 0x795F73A989443C8BULL, 0x6D72763462F72827ULL, 
            0xB77792CB2CF87363ULL, 0x19FD61F71C9804EEULL, 0x2FFBA0A99D252B95ULL, 0xCA50620F8485C50BULL, 
            0xB40E0E9F5AA26C3EULL, 0x768FD2F6857765C2ULL, 0x16FB509683791048ULL, 0x76543E32EB0CA34CULL, 
            0xBE957BD000AD72A5ULL, 0xF604F1DC6F8ADAEEULL, 0x8DE273EDA4B259E1ULL, 0x9AF5BFC9082C6990ULL, 
            0xBBD7C2D2B1271116ULL, 0x0B1FFE36C8F017F3ULL, 0x5BE3CAF8C8A07AFCULL, 0x4B38888B38F54D43ULL
        }
    },
    {
        {
            0xE3E39717AFE0615AULL, 0xF1F28D227683151FULL, 0xABAFD6719503C16EULL, 0x42D4697D8447FEBEULL, 
            0x2258DC517116EB7BULL, 0x0879AF1C24BA4315ULL, 0x66E0E81216E28BCEULL, 0x6980F3FB86FE825FULL, 
            0xFCA0EE3BF94D78E6ULL, 0x3B53D10CC726C593ULL, 0x5FDB841D719858B1ULL, 0xF66EEBB08CAE567CULL, 
            0xA9B164D69E81CB43ULL, 0x93ECEDEBF12571CEULL, 0xFDB93F133BBAF1CCULL, 0x865B8175E3789EEAULL, 
            0xF4A364EF8B63F3D0ULL, 0xAF81DDCE67904300ULL, 0x5167A3E94F94A3B4ULL, 0xC09274ECCFEC3D62ULL, 
            0xC906C83FBCDD355FULL, 0x4C93670D480F2F73ULL, 0x7ECC97EEE4B2B30EULL, 0x692BE91D5B6AC721ULL, 
            0xE819B067D8A1D82FULL, 0x1D6746B2D60FFFE0ULL, 0xF5F9B1C9612704BEULL, 0xBEE81EBEA0FFD395ULL, 
            0x427098FE7E0897FDULL, 0x9B54262AFA5DD685ULL, 0x2F51342710281CDDULL, 0x7CCF79F94DF08DA4ULL
        },
        {
            0x72E765730FD8C172ULL, 0x15869EFA28BDE444ULL, 0x3FE98A3D8A4DFF8FULL, 0x9C0B25CCFF3C83F5ULL, 
            0x3A055BF91B5CD608ULL, 0x54FD5FDC06F86F00ULL, 0x353A255C54024027ULL, 0x7D8234DEA66FF9F6ULL, 
            0xA90AA460DF462B01ULL, 0x451EFAD072418BE1ULL, 0x1B44ACB44FC8C0A3ULL, 0x51E87E13F10C5526ULL, 
            0x1BDD2A6E7E9477B4ULL, 0x386320DE6BE1A209ULL, 0x8673AC4BEA334633ULL, 0xA47BAEDBF66C9B1AULL, 
            0xE68E249D1B5C9B13ULL, 0x311ABAD3D36A5A6BULL, 0x4890C13D0CFC1F66ULL, 0x3ADFD6EF1A2EF4D4ULL, 
            0x5817D2FC580E58C6ULL, 0xFA7071F342EFF62CULL, 0xF62537EB0916EE1FULL, 0x1F774AE5A22C1138ULL, 
            0x4D7564EBFFC663FAULL, 0x20A62402B9D76E61ULL, 0x1B0C70D8EA6D5DE2ULL, 0xC8DF4003408CD517ULL, 
            0x237B1F5DA5F1364CULL, 0x354574C3C1FE235EULL, 0xDB5A132318D01251ULL, 0x88D9646AA7CEEBDBULL
        },
        {
            0x9198C3963164DDCDULL, 0xCF07C50DC9FB619EULL, 0x6B6A17CB14DB4DBDULL, 0x03C5906086B2164CULL, 
            0x85DDC21354EAC7C0ULL, 0x38D54ABCB7A65086ULL, 0x46FD4BB4BBBB4D5DULL, 0x930650129677C9A9ULL, 
            0x9ADCC3C819E60C1CULL, 0x299DDEEDCB22ACD5ULL, 0x3C421BB5C68F8DFAULL, 0xABE68D5C968137ECULL, 
            0xA5E53E27DCEB5AFCULL, 0x0E82ADC5BE830D6DULL, 0xF6345453FA719B34ULL, 0xB5970230DC85EF0FULL, 
            0x58AB932C5A604989ULL, 0x479B6EFC5A2878B5ULL, 0x001319F7C7543E48ULL, 0x902F6AD742070737ULL, 
            0xAFAFC516133C912AULL, 0xF1C15841855745F9ULL, 0xFB338E578B26ED53ULL, 0x426799491F0EF360ULL, 
            0x28079C3E11CB9503ULL, 0xEF5CA4B833E03F82ULL, 0xCFF029B03154DEDBULL, 0x93F9C7BF86D53962ULL, 
            0x7C7A1A51D760BAAFULL, 0x4B3F173F71E10218ULL, 0xC1D20FD6A1072777ULL, 0x31AB9943D459CF9DULL
        },
        {
            0x1AAA9F71B4DAD74BULL, 0xED3A6462D3F22308ULL, 0x2D51FD7469C07612ULL, 0xAAED7B692E662089ULL, 
            0x45DD7C4B85369F9BULL, 0x0031140B96557A3FULL, 0x22F443BA4E6DB7C7ULL, 0xC5EE481109BB2C9DULL, 
            0xC6F8800C94610EEDULL, 0xB2C1FA961575F376ULL, 0x55A283AD99E65E10ULL, 0x5F6F7DB35DCB9BADULL, 
            0x0BE49D1C68BF050EULL, 0x58A368A87ACDD454ULL, 0xC299D31982F3F91CULL, 0x1F5F498BC6DAE77AULL, 
            0xB51DFD36D1167928ULL, 0xD16033C7638FA0A7ULL, 0xE1D4F31CBDAECF2CULL, 0x27994AB65997E627ULL, 
            0x718A2329C539BEEEULL, 0x65819084C8A8EA3DULL, 0x8FDBDCB97B5CBC45ULL, 0x53EC973380E9B458ULL, 
            0x4E903BE5C9828A01ULL, 0x017EDFD1214C5800ULL, 0x7832262B3E8E43A1ULL, 0xEEBB70B9B5A53028ULL, 
            0xBB1431E3C8D56616ULL, 0xACE69565F3624539ULL, 0xF915F709350570FDULL, 0x10743218F9C10983ULL
        },
        {
            0x85956A6288E66D15ULL, 0xEC365A1A133ED2D7ULL, 0xA1562A9B423B97C7ULL, 0x130DDB511F0E94C7ULL, 
            0x02EBC58EA1D8D00EULL, 0xF229B1E44A5538C8ULL, 0xD4EECF3538596577ULL, 0x90D3FC1E4D1F0F56ULL, 
            0xECB79ECEC5E3DE6AULL, 0x11425E3EA7EEE4C9ULL, 0x97C1B21A1EFB182DULL, 0xCF0083518D6BEFF6ULL, 
            0x9F6E9C6D909704B3ULL, 0x2D8024E01BA2846BULL, 0x4D2A61923560C8D8ULL, 0xE5A769865BB1F53DULL, 
            0x384150CED06EF1B5ULL, 0x2E6AA8EE1A604279ULL, 0x141D24224EE5AECBULL, 0xF77F174561EEE703ULL, 
            0xBCA8B4A6F6B71CE2ULL, 0xA8848976A65FCF35ULL, 0x35FD541A8E7F369BULL, 0xEC588EBB26C07522ULL, 
            0x9403B27CD0A24AA6ULL, 0xE77061F04D37D2B9ULL, 0x6C858E146CD939C8ULL, 0x1D7F1009FE7CC080ULL, 
            0x7772B66C69C3218AULL, 0xDA31EFCD48BD2C03ULL, 0xA9704FCAEE1A4F83ULL, 0x0030333A3689BFADULL
        },
        {
            0x388381E533AE34F0ULL, 0xF411958BA05A78E3ULL, 0x67EE868F1294693AULL, 0x2C0F4CFFFF9D32B3ULL, 
            0x9E6B8E50334CB577ULL, 0xDA8D8BF1781B217DULL, 0x44D3575A8CFE9FB8ULL, 0xCA4192E1C348FB0CULL, 
            0xA6820C80780B14A6ULL, 0x746B6E0B33B6562DULL, 0x0A485D1ACAE3448AULL, 0xEB1879A7A6D78872ULL, 
            0x3FF79A6D36E07364ULL, 0x81BA1E7E4B3897E6ULL, 0x59337B1AD12C05ABULL, 0x3ECCF9C7C9D87ED8ULL, 
            0x59E27DAFB70D9DE2ULL, 0x1D393988B38C97F4ULL, 0x2EAF1935D39F3FD3ULL, 0x9779BC0D804B2F57ULL, 
            0x56894CB9FBE60DF0ULL, 0xEF4022BB812E5063ULL, 0x464EF5FA9DA44F6CULL, 0xE35427B50E6238B0ULL, 
            0x1F0C9844F0C45B17ULL, 0x5502944E280EF89AULL, 0x731E12D50A690BC3ULL, 0xF4614F4E5F4FDC76ULL, 
            0x9731B48427399D58ULL, 0x1F99395AB03F3849ULL, 0xFB783F624E0E0014ULL, 0xA86168A3E4B37D05ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseDConstants = {
    0x5F605BC54693C6ADULL,
    0xF8C4A25EE96F5313ULL,
    0x89EB8ECD74DB2D99ULL,
    0x5F605BC54693C6ADULL,
    0xF8C4A25EE96F5313ULL,
    0x89EB8ECD74DB2D99ULL,
    0xE0678AC589618626ULL,
    0x1026CF3C4C578047ULL,
    0x20,
    0x4E,
    0xEF,
    0x20,
    0xF6,
    0xB4,
    0xBA,
    0x30
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseESalts = {
    {
        {
            0xE409FD1EED90419EULL, 0xEF5B8BDE86A9D129ULL, 0x3EF6B44D251D1DA1ULL, 0xFB17EBEC2F3DF077ULL, 
            0x016735A0CD4C8DFAULL, 0xC5A4F141E4DB8F3AULL, 0x077614DC58BCDD7CULL, 0x581B36A89259B0DFULL, 
            0x91DF0C32AE59DEECULL, 0x35181D4594C8F816ULL, 0x0EA804272B615AE2ULL, 0xAFA42AEC8A9FC82BULL, 
            0x74C1A29E3D5C1548ULL, 0xB173494C873BD0B4ULL, 0x04C10AAA320D5344ULL, 0xE5EA6DBEC85DA9BFULL, 
            0x06CBC2E8C03E1E66ULL, 0xC044B9A2C2FE5BAEULL, 0xA07401E42C210866ULL, 0x995E03CBBA453EFDULL, 
            0xAA7ABB76912171FAULL, 0xD4575E2B4DEA4E61ULL, 0x4566EB73A202D950ULL, 0x0232E9FADD7A8A6CULL, 
            0x000B114155B4063BULL, 0x5AD41C0399274894ULL, 0x254666B5761494EDULL, 0x73540444F52E2F9AULL, 
            0xDFEED5F722328F99ULL, 0x2042C52D3FFAAEBBULL, 0xF8DA2FB272A030C6ULL, 0xB0F91846933A821EULL
        },
        {
            0x1CB9ED20C639F5B2ULL, 0xD891B1AB38119618ULL, 0xD89C3BEF91EFCEF4ULL, 0xAC39CC58BC9AA8BDULL, 
            0xE2F70788C1AB237DULL, 0x7028B98F903A50B5ULL, 0x135EC6719AFC3ECDULL, 0x539D37592CDD85F8ULL, 
            0x54D52559228432DBULL, 0xA0ED04B6D808B2BCULL, 0xFE0BCDE83E51CB3DULL, 0xA55CCFF0949BE3D4ULL, 
            0x4CAE2065183850DEULL, 0x864B9947BFD69896ULL, 0xDEE8F65692DE49E7ULL, 0x91876DC8AED2D1E7ULL, 
            0x28A819A3DCCD0777ULL, 0x30E8C12D82F47EEFULL, 0x533B880645AC58B0ULL, 0xA43FA77414E6508EULL, 
            0x0EC7F60A1B4B6118ULL, 0x4306539FEA2E4608ULL, 0xCF987D29F7FBEA35ULL, 0x8BE7463AD4ABED9BULL, 
            0xAB26F21904B53276ULL, 0x6835EC83A0DBA5A2ULL, 0x94FAF1067C217018ULL, 0x3D77E7FA70856B6FULL, 
            0x74A0F0004008029EULL, 0x283875426B3B6B15ULL, 0x8F2420D41CFFC25BULL, 0xC4CD6C6A3FC7C393ULL
        },
        {
            0x13017625B4C5FEC5ULL, 0xC9FE3717ED19CCE9ULL, 0x4D214B53B678384BULL, 0xC6047B4C25B1DBDEULL, 
            0x513F046B100FC48EULL, 0x3AC7B32E5902AFF2ULL, 0x7D38EB6F022D3982ULL, 0xC1D024822F9F5C80ULL, 
            0x4B4F6F0013E5E80FULL, 0x1DF8873094217D13ULL, 0x9E86B0D3BF1A9958ULL, 0x0F1A514A4F203575ULL, 
            0xD900548127A7C560ULL, 0x51B7A40282ADBADEULL, 0x6CD1BAAF77DF409EULL, 0x51533660087BC19CULL, 
            0x1C611DEEFF1B807CULL, 0xF8DBA3AC9296826EULL, 0x3B9F60E58F696023ULL, 0x098D1960469B27FDULL, 
            0x724A0BCFEB419A48ULL, 0x918BECD6B1393A06ULL, 0xBCF9968198880044ULL, 0x64849CD36CD778DBULL, 
            0x843CA95AE315F564ULL, 0x257C4501ED6551EDULL, 0x17562D0A53C37367ULL, 0xB5DE84AE47CC02FFULL, 
            0xD9FC230103ECD22FULL, 0x1FBDC215E0A8B804ULL, 0xB52ACA016689C2AFULL, 0x89CF6B1692E668AEULL
        },
        {
            0xF0AFEC4A0AD95967ULL, 0xF04A371C573BE9A2ULL, 0xEC504DC097B48B8AULL, 0x10FED21655B05B55ULL, 
            0x4AF812ED06E279E2ULL, 0x12607B56EEAAF13DULL, 0x4BB6460C5330EE9FULL, 0xB6929C0D2BD6E569ULL, 
            0x5304CC6AC2F6AD81ULL, 0x1130F90358F027F3ULL, 0x850279D2A5BB1AF3ULL, 0x723D62DB8D84FF88ULL, 
            0xD8AA4691321365A4ULL, 0x3E6B053C5B7220BDULL, 0xE7FB187033F7A761ULL, 0xB900979702AC8702ULL, 
            0x3FF4A53FFF7E47A5ULL, 0xF07181EAB8154B20ULL, 0xF28E9055A3515AA0ULL, 0x41F7B88748486DC4ULL, 
            0xE224C527F8DDAA3CULL, 0xF687A9054AAF6DC4ULL, 0xCA6AD2E3AD663EAEULL, 0x15AA7829064FF94BULL, 
            0xBBE244E74880FACDULL, 0x7ADBE71042BAF1D6ULL, 0x04B897AC46C86E7CULL, 0x0449C566B18F5431ULL, 
            0x6B8D2B51FA62D0FFULL, 0x29EB00D5AA3CA18DULL, 0x4521CFDC7F42676EULL, 0xF33D73797D947528ULL
        },
        {
            0x8D9C1F4A63CFBC69ULL, 0xE15EA3CF4E862127ULL, 0x2B87E412B76D8171ULL, 0xF83AB0AE96DA6F7BULL, 
            0x05695B13EA2805B1ULL, 0x05F840A7486DC771ULL, 0x8469783A3A65FD5EULL, 0x30E83CCE2D064C1CULL, 
            0xA1946465D6960B15ULL, 0xD1DD57B40CBE5399ULL, 0x16D8A163BD0E3F12ULL, 0xEAE4B3C617E877E9ULL, 
            0x3BE3985B9140462CULL, 0x948AE13824B84461ULL, 0x073EA9F0FF2D0D9EULL, 0x30374FA696E66FD4ULL, 
            0xE9065FBAF3DB6A00ULL, 0x9516F6F3DDDEFE96ULL, 0x6785A7AE70EC18A7ULL, 0x2E51C7B2CDAD36A8ULL, 
            0x3B625468D52A3283ULL, 0xCBF29B88F80A95A2ULL, 0xFB1C45E2B56D69FFULL, 0x9D8A4A1FE3247918ULL, 
            0x1033727D4D270F14ULL, 0x8008201AC6185F82ULL, 0x67BCD180B30EBF81ULL, 0x2A1E0CC660229CACULL, 
            0x484B14A44B18B0A7ULL, 0x1A120EDCBE0D878CULL, 0xFEC91001BD4C31D5ULL, 0x168A022F034C8BB1ULL
        },
        {
            0xF88E1994483862F2ULL, 0xEB573D7A63AAAF5DULL, 0x69A26747D0075637ULL, 0xDDE9AF265A92097FULL, 
            0xC6987D9A9F603004ULL, 0x8DEA78F8BDF1DAE2ULL, 0x31580C29BB170CB9ULL, 0x8570157FC6B961CCULL, 
            0x527AB093561EA550ULL, 0x0101076B012F2468ULL, 0xC201E029652A39EBULL, 0x945F7B8627A614C1ULL, 
            0x040DF704FD05DCFDULL, 0x3FC062796C8FE3DAULL, 0x79BCED8F2A23C58CULL, 0x4FF0D0D59C3FA9C7ULL, 
            0xB8BC4F82E46D61E1ULL, 0xD707F4FA4F58A672ULL, 0xFC2BC0BC7D366D0FULL, 0x0D01594EE46225BDULL, 
            0x1549AAE9E952FAA1ULL, 0xE8A6AD1A1FED4202ULL, 0xB851507A2351FAB0ULL, 0x10A061883E1F1376ULL, 
            0x8AC5DA91A4581C08ULL, 0x1C035C8E0FBE320BULL, 0xD23077564AFCC192ULL, 0x76AE2F1241297125ULL, 
            0xB5EBCA7BD41A5260ULL, 0x7DCC1C07E68DEC78ULL, 0x7A9FC10517257D57ULL, 0x31D6C078E271B735ULL
        }
    },
    {
        {
            0x6A7893B037E58EC4ULL, 0xC79E1218D3A283E3ULL, 0x13AB248BAEAA5209ULL, 0x5AE55016F21866F5ULL, 
            0x970CD10B5D25E703ULL, 0x40194CA2B2BA6050ULL, 0x8E4D7238036C544CULL, 0x6CBB2FC0DB6A2D52ULL, 
            0x615FAF75564048F5ULL, 0x97233918375E6F72ULL, 0x394BB963F635DB0CULL, 0x5B1478B82B9EB5B1ULL, 
            0x6D1D3D55C7071592ULL, 0xD492D1EE07E872CCULL, 0x05696B564EA2302DULL, 0x7C29C86C4896E9C5ULL, 
            0x2661A5D7671231F4ULL, 0x71AE043099567D1FULL, 0x6CCDF8A37ED1D9C2ULL, 0x2487E4F850D24A92ULL, 
            0x96007DEE575AB6B7ULL, 0xD5CC719EB7291E2BULL, 0x71765BE4720372E0ULL, 0xAF21F99F430659A0ULL, 
            0x6A23141AD646122AULL, 0xC7D172DB185DAA2DULL, 0xEE871C429C64697DULL, 0x3E9C80A950BCA680ULL, 
            0xFE9A44E4BAFFC2C9ULL, 0x69DBC3D1F72FFA74ULL, 0xB70CF48FD800D659ULL, 0x3DCEF0FD05BE2DE6ULL
        },
        {
            0xB76F22676E98BAD0ULL, 0x281C8902E650FA13ULL, 0xA5247695E0E9EF24ULL, 0x4C93E99277F3EE4EULL, 
            0x7ABE5FA6ABD55035ULL, 0x543C6C0B6E930768ULL, 0xDA017827975FE603ULL, 0xA74961705CEF76F9ULL, 
            0x061457F6883F267CULL, 0x01B14860D8A4B0B4ULL, 0xA6E1FF3D676D26DCULL, 0xDFB57477447C18EAULL, 
            0xB59A67A5599B7306ULL, 0x3C632D0220DCA2B9ULL, 0x9F2EC8F19E4AC14AULL, 0xA78290DBE4CF0F65ULL, 
            0x3AE31BE0D137023FULL, 0xA782B1B728B16868ULL, 0xF101467423F30AE0ULL, 0xAD46364BE64E5475ULL, 
            0x7D191BB3A1BFB92DULL, 0xAAEC05BEABCA2092ULL, 0x6C035C524043A64AULL, 0xE6ACAADA44E093D6ULL, 
            0xB19002280D0D4903ULL, 0x6243EB5E2651AA89ULL, 0x8363C17C9EDA8F7AULL, 0x39C09CCD8E964A17ULL, 
            0x2F9971B235CDF5A0ULL, 0xE5608023DB1C7DFEULL, 0xFD0771DFE5F9C5D1ULL, 0xFA5BC3D338A97394ULL
        },
        {
            0x24CE1B346E8C3B70ULL, 0x141F89F3C9EC662DULL, 0x2DF8F04576F13B17ULL, 0x24ACFD2857036396ULL, 
            0x4D7D0DC4FB10C3FBULL, 0x0337C3995CDC296CULL, 0x473324CC49DBCE6FULL, 0x94C6A12187166703ULL, 
            0x5808DA26925BC516ULL, 0x7E28F8419CD9F044ULL, 0x1117ED5C8C6E0125ULL, 0x1593A272648E1062ULL, 
            0x81F4BD06097713D4ULL, 0x6266923201ECF08AULL, 0x32046E0BF21FEF11ULL, 0x54A426AFFCF5DF6BULL, 
            0xF12101FFD8EB58DDULL, 0xFF671B23A619B143ULL, 0x48D7C3A09BE2DC7DULL, 0xB334576B4BD4E7E9ULL, 
            0xE8A4A0496995A62EULL, 0xDEA86768EF48C45FULL, 0x57CA4A63FE5B38B6ULL, 0x3ECFE64F6F176ACCULL, 
            0xD204FEDDAE3C8589ULL, 0x01B5F1CFF80F97B6ULL, 0x9CC800BC13B23823ULL, 0x1FDBFB5CF9FE213CULL, 
            0x704ECC1479C0EFB7ULL, 0x887DE2C00F4E5F2AULL, 0xDA8219FAFF32ED41ULL, 0x596155FEE1829C72ULL
        },
        {
            0x11C3CCA28A875E87ULL, 0x2BA67B9AACB748BFULL, 0xA9A1EF255B697A13ULL, 0xD50FDD077096E05BULL, 
            0x0B042C55E290667BULL, 0xBD6776D1CEFD07DEULL, 0x4EA4862BB6B36755ULL, 0xB3B418F8F1FD3A65ULL, 
            0xEC6497AB51252B28ULL, 0x53F601B5F9AFC878ULL, 0xA149D11F6ADBDA52ULL, 0xDC2D56B20A4E66ECULL, 
            0xA0F007B991BEE987ULL, 0x58A7DA4A17AC4C98ULL, 0x794364E3FDA75ECBULL, 0x0B93CDB768B29AB3ULL, 
            0xB0951098D87AF680ULL, 0x73652B25EE3A86F6ULL, 0x142420C355D17900ULL, 0x1CC5AFDD79A9D9A2ULL, 
            0xDD7832BB67440CC9ULL, 0x22CD73D40089CACEULL, 0x75FF177C51515E23ULL, 0x310E675C32BEEEE6ULL, 
            0xE3CC85B764D2F600ULL, 0x6308951B074D220FULL, 0x47426188CD73E9AFULL, 0x6B171C0AD9EF3905ULL, 
            0xFDCDDA3EE45BCE06ULL, 0x0D16EB4019568EA7ULL, 0x75F3F9FC0A95DCDCULL, 0x20ECA83302AEAD35ULL
        },
        {
            0x25C4B971C1BBF945ULL, 0x6710AD87EB8C10E0ULL, 0xC405EC2688736645ULL, 0x793158AB6E8E98F5ULL, 
            0x1C4DCA7EEEF7F6E1ULL, 0x246E054C8BB9FBA9ULL, 0xB43DC1EEF29FD004ULL, 0x2487FB39ECFDC27DULL, 
            0x7B165248AD944DE8ULL, 0x356483CF2A4A150FULL, 0x1BD1DF74DBAEBDF5ULL, 0x76A39A17719B957DULL, 
            0xF54DAD77D6B09490ULL, 0xDF3BA94CE4FB082AULL, 0x3066F698E301E514ULL, 0xDD35A0D8C1F1A5D5ULL, 
            0xF9EFA4D18E8FDE5AULL, 0x3386DACFE4072A88ULL, 0x5803563BE3C7C506ULL, 0xFACFD62AE18786EEULL, 
            0xC6C5DEC51584DE40ULL, 0xAA28998159535CE7ULL, 0xCA566EF2418846CCULL, 0x6815070FE1E9AECDULL, 
            0x912321D9193AD1DBULL, 0xA6A5DA932015E33DULL, 0xB45921BB81C9D45FULL, 0x62F92816692A9DB4ULL, 
            0x04B217AF501BBA31ULL, 0x60F04F2863D320EBULL, 0xD550852D768FF127ULL, 0xBC86EB5270C4AAA0ULL
        },
        {
            0x251EFA08298C70CEULL, 0xB0359E6AC7D19050ULL, 0x38E9932CF0252177ULL, 0x0CED7C51B2629032ULL, 
            0x5B68E9ABF0CD0168ULL, 0xF5926CB7A6BE823EULL, 0xFC3E598A96033C8DULL, 0xD2B652EE65D6AFC7ULL, 
            0x0A8D28D83AEFE6ECULL, 0x23329F9C9D4CDFA1ULL, 0x96CDB7291BC4A059ULL, 0x1785ABA5663D146EULL, 
            0xA5EDF505A16CC343ULL, 0x356753B09A379CD7ULL, 0x4B7C5581812692BCULL, 0x270FF705FA15F2FEULL, 
            0x183886C9F31A8A4AULL, 0x29DD88B7E48A411CULL, 0x1E647EB49CEE1E82ULL, 0x918767881E8EAC30ULL, 
            0xE7A69D43BF1A0695ULL, 0xEFADD71348BFACF7ULL, 0xD0FBD768DB2A4360ULL, 0x32C61E86FC295F85ULL, 
            0xB34303F113B8FCE8ULL, 0x55F4B21346ECFB52ULL, 0xC7D88CE1DFC08C19ULL, 0x59DC12487875D04FULL, 
            0xB2D8795C43C5F26EULL, 0x7A98475195AC1ADBULL, 0x487EF261D5C9A287ULL, 0xFE7022B1D1EB96C3ULL
        }
    },
    {
        {
            0x0F5F91471C1E7404ULL, 0x9483449582981C27ULL, 0xD0CA60F13EB8B06AULL, 0xCB3EAEE9473337C3ULL, 
            0x35B88F8FA9402963ULL, 0x980F7CAB02CF6921ULL, 0x5954F0E7660A1F34ULL, 0xE41F49684044A1ECULL, 
            0x4F18F1067D619C09ULL, 0xFC813FB4C2E1180FULL, 0xDF3715B445CF7763ULL, 0xCF83DED68828A484ULL, 
            0x27C05BF34C0B5EE5ULL, 0x18B316BA1B86FCFBULL, 0x63F855F1400341B9ULL, 0xBC1363B051D1571CULL, 
            0x249A1FC67E6CF69EULL, 0x5D5A8D237AD011C0ULL, 0x67CEC49657CF38F4ULL, 0xFCCC53B16375C1A9ULL, 
            0x995BE3904322D4A4ULL, 0xB37C7A32C39EEA5CULL, 0x80AC0F667B2A461AULL, 0xC7890BEC67143874ULL, 
            0xA2FCF327CEE4806EULL, 0x4588D42C37FDBF09ULL, 0xAF1478AB5FCB7713ULL, 0x5D51F5DC8A8C39A2ULL, 
            0x8B7161E75CB4CDAEULL, 0x3FBC2BB05640D2B9ULL, 0xDDB3DC231692D5A6ULL, 0xC0FF333A01D3DE6EULL
        },
        {
            0x32C9BAF5D47359F0ULL, 0x7A2CB1A726789E34ULL, 0x4101A416D5CD0F17ULL, 0x08963D3AE97F9D67ULL, 
            0x29992F3471CFA571ULL, 0x6411834E28563875ULL, 0xBC9D0B285C6BB64CULL, 0x2703128D2B76F296ULL, 
            0x321271F278824A72ULL, 0x604C2B7190A15B92ULL, 0x541581189B116A34ULL, 0x4B1E5B2491031830ULL, 
            0xB0A0F1FAD17A99C6ULL, 0x2831BD64F834FEAFULL, 0xA6FA0F3A5A4F60F6ULL, 0xD78DCACDD3D0A650ULL, 
            0xD7FDE870620E36B7ULL, 0x2964EA6FD76D5788ULL, 0x184B39D4B351D51BULL, 0xED628BA6CAC1AB56ULL, 
            0x1F15D8FD53D77D81ULL, 0x293E17AE944B73C5ULL, 0x34AD9782A160F76CULL, 0x115E4A47A3A2791DULL, 
            0xE892002AE241C5FFULL, 0x34F1BD364A85701EULL, 0x9E8FF9610D7DFFEBULL, 0xF8E9D1782AC21A1EULL, 
            0x633AF1ED53FE47FAULL, 0x077F665E7CC231E3ULL, 0xB2F7A9201F376130ULL, 0x98A28CE2C1FF86B0ULL
        },
        {
            0x5DE4A89DD50610DAULL, 0x6ED1CD3FD8EC96DEULL, 0x0B22654B69B43DFBULL, 0x72549E83C3086F74ULL, 
            0xCBD471AD15725F4BULL, 0xEA29EF68C7C7AE8DULL, 0x02EF18B06B0DC161ULL, 0x3213F8A46BEAC1A9ULL, 
            0x056D015B184245DCULL, 0xFE5C2A5D7716B7F8ULL, 0x1CEB57531CCC5B98ULL, 0x23E54724D040A4ADULL, 
            0x3C9E763D17F10992ULL, 0xC826DCECF4734C04ULL, 0x534EC493DCB3D671ULL, 0xE173DAC143B4BEC6ULL, 
            0x6428E590D9D9DF38ULL, 0x12E1CA8A4E378FA8ULL, 0xE33F7BEF2270ABDCULL, 0x47F07E373AB793BDULL, 
            0xC06F37B80C131CAFULL, 0x48C1FF5144F98337ULL, 0x4C0490C926F6D940ULL, 0x89971DCB5B6B22E8ULL, 
            0xFF0D384BCE1B2ED3ULL, 0xFDF5A5CAB67C2EA5ULL, 0x534AE868992DC8D9ULL, 0xEE886A53B6AA41A2ULL, 
            0x96D114676121EA3CULL, 0xD9C965F8F9B59794ULL, 0x8D75A602CB662B4EULL, 0x2648466CBF4110D8ULL
        },
        {
            0x9EE561BDF9F15732ULL, 0x1DFB558ECE19D126ULL, 0x741B512FDD9E3492ULL, 0xC7AE0397AA612CC7ULL, 
            0x31637BB63792EA73ULL, 0x105D7A0CAE3101A4ULL, 0x0534DB1B04228656ULL, 0xC8D82AC83CF8EC10ULL, 
            0x0E36AC1F99C4BAE8ULL, 0xE6B79B36886467C6ULL, 0x7F9F5E4602FD6210ULL, 0x171FCDDF8839C346ULL, 
            0xE0BB491107FDDC3DULL, 0xC4863D9F6E80176DULL, 0xF542A405845DDD33ULL, 0x41DD71AC514BAD4CULL, 
            0xB65B23F3BE7F514EULL, 0x4316699A80357C49ULL, 0x957CEF358E6B3A0FULL, 0x2A4CE36C6CBCCE1DULL, 
            0xF3232D8C919B7D78ULL, 0x916370D1E9FBA31EULL, 0xCC07C5D7655BC14DULL, 0xD9D5AE4DF74079F0ULL, 
            0xCC01BD93C80187E1ULL, 0xCD44D9C328388F55ULL, 0x90E93B1D80153C07ULL, 0xC3D555B69B1584E9ULL, 
            0xDD2E44A6C4BAF8EEULL, 0x8CE803FE9FE3E178ULL, 0x75431AE2F4E6B892ULL, 0x5F8F18CEF810081DULL
        },
        {
            0x3A843DE89225A08CULL, 0xD5D41279D4EF6AE5ULL, 0xCC0C61A37852F169ULL, 0xE7B23D0F9AB731C0ULL, 
            0x2C4544B5311FC9BFULL, 0x030A1000380DA534ULL, 0xDB7FF92B23A198E8ULL, 0x4601DBA7084E289BULL, 
            0x458AA0BB989E0C20ULL, 0x37E4E7F45FC3A3B2ULL, 0xADCDE19258C4CF6BULL, 0x12CB7DE190A81D65ULL, 
            0x745FE9FCDE2E7208ULL, 0xE259A76D1B91770BULL, 0x2CA360075E993E0AULL, 0x4D49B8A76D817294ULL, 
            0x3C4C1A9DF3E69908ULL, 0x3A834B1084E55EC3ULL, 0xB551F97E1061ABE3ULL, 0x9D4DC9A0A15490E6ULL, 
            0x8313645F48A29C80ULL, 0x9C1F88A986311F5AULL, 0x44E7EB88B81AD2F8ULL, 0xC865241B100813B2ULL, 
            0xAC5D7831B2DDB273ULL, 0x9C2C52637BB76C5FULL, 0x184A863D7E3C5E4FULL, 0xBB300A63F0D224B6ULL, 
            0x0D096D2B51A5CCC8ULL, 0x89D5BFE7D541F7D2ULL, 0xCDF97676744019F1ULL, 0x1BBF7D499226B56CULL
        },
        {
            0x1FA9B6FC5D200B21ULL, 0x1E128B75572217C9ULL, 0xC7FC2B217B2FD7EFULL, 0xF3F7D0036D9F641BULL, 
            0xFAE5F72F9A62C404ULL, 0x022DDE24601E1268ULL, 0x54845E715A5EDEA4ULL, 0x3B449D7F2722B743ULL, 
            0x1D3DFE88B89FF4CFULL, 0xDDB54497F5B146C1ULL, 0x9D29B3FD31EFACE6ULL, 0x7D427BCB8569EBF7ULL, 
            0x57874DC69EC182B5ULL, 0xDAD4E85D1F92838CULL, 0x29B53016E4AE1BBBULL, 0xF495E9D4BE0E6CEDULL, 
            0x5441BE626134BC77ULL, 0xC218FF31FABAD0E1ULL, 0x46697E69D441E041ULL, 0xADE1A0DD21469D67ULL, 
            0x579023441FC23CCAULL, 0x9F0C20B3D032812CULL, 0xDF59EAB3C8C7CC50ULL, 0x61B7B8DF86653D0BULL, 
            0x9AE0CC0808A6A599ULL, 0xFFDCCEC67A7AF496ULL, 0x1D9175EE99C589F6ULL, 0x2252C2F1E2370E54ULL, 
            0x4E7D017BFCFDD733ULL, 0x38D12FBD332B15C9ULL, 0x6C79E37A0646ABDFULL, 0xCB8E418AB153B066ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseEConstants = {
    0xF03D7B344ED549D4ULL,
    0x8C89C0C834563846ULL,
    0x1E7DC8D09895C554ULL,
    0xF03D7B344ED549D4ULL,
    0x8C89C0C834563846ULL,
    0x1E7DC8D09895C554ULL,
    0x4443412EA728FD27ULL,
    0x645C4967C04923DDULL,
    0x8A,
    0x07,
    0x45,
    0x1D,
    0x27,
    0x6C,
    0x73,
    0x50
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseFSalts = {
    {
        {
            0x2BC88EE4A9DA31A9ULL, 0x94986B0472D1A71AULL, 0xD877A789825227D7ULL, 0x33657A502C4F6EE2ULL, 
            0x6F361452135FC296ULL, 0x76DA2FABCDBC6284ULL, 0xA02779FE1515DDF6ULL, 0xDC5768A40BE76CCEULL, 
            0x926B815D12191D56ULL, 0xEFE914E1F4C18795ULL, 0x144F172D7A7ACA38ULL, 0x1DFBBD1B680C4F68ULL, 
            0x8F56352456C2EE46ULL, 0xFFF9C2E730402422ULL, 0x328EA2122898AA40ULL, 0xA18886C20C2C1C15ULL, 
            0xF1B2CFCB945A88B7ULL, 0x39A074EC24426599ULL, 0xD3023E8312038472ULL, 0xCA4C668F9FCCC86BULL, 
            0xDD36CAFD5B076219ULL, 0xB466D6B15B7F9E49ULL, 0x52DF9BBA99466513ULL, 0x286418964D307EB5ULL, 
            0x8A274AE66A2FCC68ULL, 0x044DC08113FAA333ULL, 0x0A1C9A6ED76A4D25ULL, 0x035E3A99AF25C176ULL, 
            0x9EAF237569C2911AULL, 0x254B50FCCB93476AULL, 0xC01800DDAFBDE02EULL, 0x1E765673ADC46109ULL
        },
        {
            0xEC4932D72B200EA1ULL, 0x8C4390D8D322A01EULL, 0xC5B5869A3707CA5BULL, 0x2C725E2E4DC67082ULL, 
            0x7EBCEA577C31D44BULL, 0x8995FF4A909906C6ULL, 0x9607073D20A3BC16ULL, 0x38F2976AFC3A8DC7ULL, 
            0xF09E380E71615915ULL, 0x2FB4CC719B2B4654ULL, 0xEF91A6EF95249915ULL, 0x58B35EB4EC0A985EULL, 
            0x0BB8BF59EF84290DULL, 0x2C09C61E0FDB3A26ULL, 0x38712A4221AAE77CULL, 0x34E0F1AE46231DCFULL, 
            0xA5176E8FD3D16251ULL, 0x7134C9F01B43E9C8ULL, 0x8A0EA0DCDE879C30ULL, 0x4C997EB45AE53879ULL, 
            0xE64B133A36693ED3ULL, 0x825E80C180B1DAFFULL, 0xD0E4F4FD07EAF2A7ULL, 0x013A542FE59E4697ULL, 
            0x004FEA875DEE5E5FULL, 0xFDA0999EFDA4F41DULL, 0x48F8939CFA98EFA7ULL, 0xC461F4AF24BF56A8ULL, 
            0x7FF20763E82ECE7CULL, 0x5A8614AFAC1CA611ULL, 0x672A798091C01689ULL, 0xA12B86F9FD3F4E6EULL
        },
        {
            0x833AFAFC23B75371ULL, 0xDCF85A9784F907B8ULL, 0xC79E3203AB7161D8ULL, 0xACD74EC3872A83F2ULL, 
            0x6BF1D276136CFE10ULL, 0xFB5A35E4A659B305ULL, 0xC685FD37C8124D52ULL, 0x1A326A14829F9798ULL, 
            0xD5ED5DF334B10B9FULL, 0x3EE422B4F33E9D7EULL, 0x34067180C8DBB610ULL, 0xE781EEF2EE9BBA3DULL, 
            0xCD6918ED16C5CE58ULL, 0x40D2C146C0982427ULL, 0x7CD5C98F6E3B9682ULL, 0x6501606DC597894DULL, 
            0x08876C4928962A1CULL, 0x711E2FC57DA5522AULL, 0xF5173C973A23DBDAULL, 0x5D985A4FACE66EC3ULL, 
            0xA61690E33B4C7812ULL, 0x23CEA18EA2273174ULL, 0xEF722A256591D7D4ULL, 0xE49339B4581A671EULL, 
            0xFFF61D372E4EBB50ULL, 0x4ADE5B0249D0F70FULL, 0x973C3A7E63C01536ULL, 0xD75F652E426DEEA0ULL, 
            0xBE228986DE52EF84ULL, 0x96B008355B74032DULL, 0xD5EEBEC03E9A332DULL, 0x893EA44D0BE02AEFULL
        },
        {
            0xE5D5CB501D17885EULL, 0x98CE3CC4935BC27EULL, 0x3EA79A04B11E90C8ULL, 0x157BD160CFF9633DULL, 
            0xB23A4A1ED0F97432ULL, 0x1B5F3AE4B48CFD76ULL, 0xE6DA40753518BBD7ULL, 0xF54D3A1FA1895560ULL, 
            0xF2B6AEED73B77DA7ULL, 0x55B6240C7B54592CULL, 0x65C98EBD448DE200ULL, 0x1427C4DE85FBAA48ULL, 
            0x2D661C2890859B99ULL, 0x70D3CD3B0164D08CULL, 0x61165D45C5871773ULL, 0x7F8FFB713A7A028BULL, 
            0x2A10D2977D0E911EULL, 0x99E35AFAADBEB5FAULL, 0x0DEA79AE2B021250ULL, 0x28CC45A90B6EFA52ULL, 
            0x988C42461A1646DDULL, 0xEF15D8BA8D3B8FEDULL, 0xDA79A21D40E9A921ULL, 0x1797AB29698FEB57ULL, 
            0xAE50BF5CEE80EFA5ULL, 0x24FCF69EBC62DBCDULL, 0x3DC92A0862595755ULL, 0xF4FF89299C75BB50ULL, 
            0x15B512F17298814CULL, 0x981D9DC0808E2D7DULL, 0x57453F488E7C0D2AULL, 0xDF232334AB57B7E9ULL
        },
        {
            0x1169220E07E95238ULL, 0x5832B1362B24E79EULL, 0xEBAA9CA3D43BD577ULL, 0x5F787668FA1566D4ULL, 
            0x9D875E5C334A17E8ULL, 0x3167B1777711E16CULL, 0x9CF8BA8EDEC73886ULL, 0x77717D0EDD37CB48ULL, 
            0x421C25FAD78919C1ULL, 0x697724DD9109DE7CULL, 0x4839D3A8CAF1D112ULL, 0xE0A36C49B3F823DCULL, 
            0xA863DD07C219B5E5ULL, 0x332381AF67270B5FULL, 0x6525695EBDBDD0B7ULL, 0x6416A58DC61B5835ULL, 
            0x593CD8328BEDBCD6ULL, 0x3C4FCCAFD8863323ULL, 0xA948B99CBD9A8C87ULL, 0x76DADEE48C34A8D8ULL, 
            0x57461E6B49B0C53FULL, 0x19E6AD57EA291C65ULL, 0x9C14EAA80E357B6AULL, 0x171CBAADB4A57723ULL, 
            0x005987D300E64161ULL, 0x8D11EED27147855BULL, 0x87BAF2F70950D603ULL, 0x0A3927952B330EC0ULL, 
            0x63771D12D11B8F2DULL, 0x16B10581F3805949ULL, 0x6939A45C0F9A918EULL, 0x61BAA9AEDA6724B6ULL
        },
        {
            0xC1A31862CA09EC84ULL, 0xB6F13101E12FD0FFULL, 0xC08864AAEA7EBC31ULL, 0x9CEE948E0BF4AD57ULL, 
            0x7D0DB63E156850CAULL, 0xF7D4E03E666F8416ULL, 0xEED3F63C2C451D5BULL, 0x43F1B8BFBD037421ULL, 
            0xE9A1C56DD7B01264ULL, 0x122F53DF4D4969DDULL, 0x75A5C1EA8ACA0319ULL, 0x1029A2389CCA5CB7ULL, 
            0xBA9C99415D8F7DBAULL, 0x1C8B2F149FE37E9CULL, 0x5EDE7CA1A6B8E803ULL, 0x8F75280A9383A6A0ULL, 
            0x6EDFEA1E8C4E8232ULL, 0x4285EFE345FD678DULL, 0x20753DE08B258E5FULL, 0xBF37A4357A4391FBULL, 
            0xA7EEE707860569B6ULL, 0x4F3BB0D932AEA6BDULL, 0x1F9C8D1A88D28255ULL, 0xC95E8731FBF5FC1FULL, 
            0x36B60E72201D1E90ULL, 0x37F1FC7EA244DB88ULL, 0xCE210CB8392CF3F1ULL, 0xDCA4C848D0FE6DF5ULL, 
            0x102208D532E8213EULL, 0x951AC448226EAA90ULL, 0x75696B8F61318D86ULL, 0xE891CCA708F8F0DDULL
        }
    },
    {
        {
            0x68A06E54EC011616ULL, 0xF9F50B66F49A63B1ULL, 0x2DE02E712A32E704ULL, 0x4BE746F339B9888FULL, 
            0x379F6B260E788827ULL, 0xC6745C1BFD34DE22ULL, 0x4B8C6F0C252C71F9ULL, 0x55052BD490093A4FULL, 
            0xBB09111D023593D8ULL, 0x5ADC15213D51F93DULL, 0x56C67B1B9DA14F08ULL, 0xEAD80129294EE147ULL, 
            0x80BE55363A66322BULL, 0x3F6633844BBC5A45ULL, 0x485641EE6D38222BULL, 0x2ECC06A30E730704ULL, 
            0x4C6FC7764CC15049ULL, 0x30687692EF525182ULL, 0x8B244666B9D67A4FULL, 0x87EE04473C355F4CULL, 
            0x64CA0817FBA2B184ULL, 0x102A773B9F97D6DEULL, 0x5A1D1A51AADDF642ULL, 0xCDB1DFDB943AAAF7ULL, 
            0x3B48743524D67B13ULL, 0x0C9D1A5A4CEF4DFDULL, 0x2CA18AF8C97A429FULL, 0x139B24E72ADF92AEULL, 
            0x5E3E2154205D9530ULL, 0xC57B1588512798E0ULL, 0x00BF0B224F4652A5ULL, 0x04F9B76317565FFCULL
        },
        {
            0xF63E0AC72C99E51DULL, 0x0008AAAAAF9C717DULL, 0xE9A0B09153B53BDCULL, 0x9489F93ADE1BD0EFULL, 
            0xE68C0FEF675EB0D7ULL, 0xD045594EA887A926ULL, 0xE346FFDE3D901E82ULL, 0xB350ACCFC2683EBCULL, 
            0x010D4BA1618675A8ULL, 0xE94CAFA52D20BAC2ULL, 0x7A471C0BD7B8B5B0ULL, 0x3000B6823729FE26ULL, 
            0x4B6BAEFACE127D33ULL, 0xC8F58E085BA34586ULL, 0x6C5C85D2095CA427ULL, 0x4FA7DA84FFA79B92ULL, 
            0xD84CBE88443E7FC8ULL, 0x7802FA21869B909FULL, 0x41EB2586210EB017ULL, 0x8E715837D2562055ULL, 
            0xB07A7A3F957F9D35ULL, 0x7721CBAFDD3259D6ULL, 0xB66E39DE01602B4BULL, 0x10285547739924F5ULL, 
            0xA8042672E1E6F824ULL, 0x10B62A2859FC3529ULL, 0xFA0CA65B3BF5BB49ULL, 0x648756421E48207DULL, 
            0x68D947763061469DULL, 0x3AB42EAE51355569ULL, 0x59F4726CD1A5C030ULL, 0x944D902F9D0A7F86ULL
        },
        {
            0xA49703FD267F9B8CULL, 0x052B10B4E3D127E2ULL, 0x805C98661BBC20E9ULL, 0xE51FC3D96707D5BEULL, 
            0x0ECB9ACCF7AD97B9ULL, 0x0F952717C709A9F0ULL, 0x0B89287EB8E8F9F0ULL, 0xA70F8ED7C7004933ULL, 
            0x3C7A67AE0854363CULL, 0xBF3F0E654ECBFDD8ULL, 0xC517AAD953218183ULL, 0xE1008670F2386D41ULL, 
            0xA94D975DC122F42DULL, 0x12CD3874AFAA407CULL, 0xA871B4082A5B4C9CULL, 0x67C6F4E533E4C269ULL, 
            0x9230495C382E854EULL, 0x128CC99CC9329281ULL, 0xEBD5EEF086E86C78ULL, 0x71FEAC06F442FC06ULL, 
            0x0B756E8C249400C9ULL, 0x7DC088D878D5D509ULL, 0x664722FB7E7F7B95ULL, 0x3DECA70090C5935DULL, 
            0xF0900D7E945F607EULL, 0xC0329D1CCADB3DBBULL, 0x17B863E1EE36F094ULL, 0xD96B41CD2C0ADDA8ULL, 
            0x6622F8FA8A15CCB0ULL, 0x3FD3D0B1FA473322ULL, 0x6AF5A40B22570B00ULL, 0x4C367083147FFECEULL
        },
        {
            0xD6A34931DE35D623ULL, 0x0528BCA1FB48638FULL, 0xCEED0E85BF5BCA24ULL, 0x12C4D72A2FEEEB00ULL, 
            0x81E27EF5F3F6FE60ULL, 0x76F4A8182270EADFULL, 0x7844BE4BC90C7809ULL, 0x575D84E6BD67C032ULL, 
            0x86EF62F5D68F2ED7ULL, 0xABE2D5BD8C113B3CULL, 0x645E2A2B7640B78BULL, 0xE554562DEE4CB789ULL, 
            0x31DD2E34288B2A38ULL, 0x302A26CA3106A201ULL, 0xDC504CB3D7CB08E4ULL, 0xFB5D47AA035A9E0CULL, 
            0x0ECD402E915C9F1EULL, 0x836CF50E9EFE8536ULL, 0xBE3A1612ED144BF1ULL, 0xFE6AEBE0BA2FCB9DULL, 
            0x5104515056660FA3ULL, 0x33D3A70408DA3A0AULL, 0x5CCB9ABA93B8DA65ULL, 0x1EF288236A3514E7ULL, 
            0xF34BC29BC86AC676ULL, 0x65FCC5B3A0840A5BULL, 0x77635C5AD1DF5449ULL, 0x8347C0B479A2A7D3ULL, 
            0x9B1EC8681826BC20ULL, 0xCC79507713340294ULL, 0xC4F437757E1DE647ULL, 0x588F3B65C9995554ULL
        },
        {
            0xD8BEF7DEDB8408DBULL, 0xA38232F9DCBE5C4EULL, 0x89AC8696B0942A77ULL, 0xA9D2364B6244C5AAULL, 
            0x551171AC190D5097ULL, 0x23977D5648ACBA32ULL, 0x7A5B8AFEDB0C9D10ULL, 0xBB0C41F7E6051CD7ULL, 
            0xFF291B9230763DFEULL, 0x8FA3149D9839938FULL, 0x1A8245E4BE391609ULL, 0x1E7EBD7AAA55BBD3ULL, 
            0x2B8BFB249260D552ULL, 0x66EE7FCC3FFAA6D3ULL, 0x15F434A8B3D7CB24ULL, 0x4D8B48085F07D8D4ULL, 
            0xAD46300F0C838622ULL, 0xF261CB72234E47D4ULL, 0xD6BF22DA9D5661F1ULL, 0xFEB9DF4B9531E040ULL, 
            0xCC12ED25AA900FD7ULL, 0x060BAF232787AEAEULL, 0x4D676165B2759A9FULL, 0xB9D37F9801EE71C5ULL, 
            0x10C1A539D6A25E48ULL, 0x7E03F1408C274B69ULL, 0x06C69483FA4A6259ULL, 0x400A53C4DB99064EULL, 
            0x94F40F59DDE5151BULL, 0x649A664DD5380259ULL, 0x06783DD005251AB6ULL, 0x9A16DE0F170E50DEULL
        },
        {
            0xF56DEB52B598E6ABULL, 0x256362D7465C69BAULL, 0x9B888C6F61775F4DULL, 0x4FFC8CEE8B56C3B0ULL, 
            0x0AC4BC1C3D5BF725ULL, 0xC68079BBC8B2B797ULL, 0x8100BBD467619AEBULL, 0x10129DF578BCDDFFULL, 
            0xC28DD3A145CACFF1ULL, 0x596983406F95F3B8ULL, 0x10B041090FB56D4FULL, 0xCBF5CD0B07A70F42ULL, 
            0xCE76EFC6469432E5ULL, 0x0A7422DB06EB8EA2ULL, 0xC86EC8D0629FE439ULL, 0x78730014AE114BD6ULL, 
            0xE0AD42C3A728A995ULL, 0x375077D17290C118ULL, 0x1B8A8971F61D2F08ULL, 0xA739A2B87FD7EDF8ULL, 
            0x3B6E454D65203EC8ULL, 0x88BD1B64AC72EBA6ULL, 0x25F1DE3DC9349B1DULL, 0x9CBEC2CF4DA0209BULL, 
            0x6616CAF44673FC8FULL, 0x54AFF5E1CFB3B991ULL, 0x630B90DDF822E7A1ULL, 0x6DED3F4E037ACEF4ULL, 
            0x299AB0F9BBDC1544ULL, 0x41F21D5A0229EC63ULL, 0x4157E7E89DC23B8AULL, 0x49D9B6D4D46FEEF3ULL
        }
    },
    {
        {
            0x81171C77F9D99C00ULL, 0xE984FB9361C47DA7ULL, 0x7BE6228577A0C63BULL, 0x477418B0D71972FBULL, 
            0x67EB8D5F709F1B11ULL, 0xB68A4AA3F84AE4D4ULL, 0xC4EA3BA1FCDECC6CULL, 0xD3BF917C0AF0D53CULL, 
            0x12884E987A5DD5CFULL, 0x9F6AE4E1C7A26189ULL, 0x7E90DDC6E180EEF6ULL, 0xBF8FCF7B91215D16ULL, 
            0x796FFEB481EDEE01ULL, 0xB79684804E0ADC48ULL, 0x0143D55A9715DDF9ULL, 0x862F93778FA228D9ULL, 
            0x3E4613CCD4B1EC6AULL, 0x5754EDD33253D3FBULL, 0xA8CE9935662BA19FULL, 0x7B24D1F2293DE0C3ULL, 
            0x8CE78E8F62A01D3EULL, 0x648A6C7273C42128ULL, 0x3F2ADA9DDCC8BAD1ULL, 0x965FF455682924C6ULL, 
            0xACCBBDCD1AFD84CAULL, 0x567D0617E2173F73ULL, 0x770B0A1A65FAC68FULL, 0xB3173169DF70585FULL, 
            0x832AE3B3E022ECA5ULL, 0x8F72B794E24F1939ULL, 0x493B56EB205CF151ULL, 0x70B4B878B5C09D13ULL
        },
        {
            0x1DD34EED45910EF2ULL, 0x5CBE482784D65F20ULL, 0xD08C8E9F8C581D4AULL, 0xCF087F01DA7EC324ULL, 
            0x0C731F4E74F9850BULL, 0x4505558EF6F3D9AFULL, 0x313CEFCD05405938ULL, 0x07F38149946FBF24ULL, 
            0xDA33B9AADCF4CB73ULL, 0x9B6CB17F24D7CC49ULL, 0x311DEC5905048AECULL, 0x7EF96A2BF43E368AULL, 
            0xAA3B7A13A04DFAFBULL, 0x842EA1D1673C82CCULL, 0x1EC4224EA364AAA5ULL, 0x555D8F6B6F5A35BFULL, 
            0x57F623EC58970B96ULL, 0xFEE0A49DC44D109DULL, 0xE83E72EE50EC43A8ULL, 0x500BD0F3A3B24F91ULL, 
            0x0D3AB879EC563AE7ULL, 0x5688A07D524DD3F9ULL, 0x5329C78A365DB318ULL, 0x467B0C8BACE14318ULL, 
            0xC06EEB4AD5C749C8ULL, 0xB79A490B0376367CULL, 0x5A9B9B65B0B0C0ACULL, 0x6C28AA6F020A8443ULL, 
            0x8DB7CB9E8287CB64ULL, 0x7F26D1BC5E579928ULL, 0xFA15126B910B21CAULL, 0x9540131765DD8640ULL
        },
        {
            0xA348453BA814F44BULL, 0x5930A57CA25A5F26ULL, 0x5EF9C3D728E785ACULL, 0x66F73CAAE68B480AULL, 
            0xC4485F4245A7DEBFULL, 0x6F20B5191480F01AULL, 0xA9197F7D531EA436ULL, 0xA3EC444CD632C5DDULL, 
            0x5C8AF1178A4A32CDULL, 0xD8AD96565BA21281ULL, 0xB5783A2474AA4063ULL, 0xB9627BF6DB715A24ULL, 
            0x08CF59FAFEC59F07ULL, 0xA730E7B5C833668EULL, 0x3EA2E5DAEE65866DULL, 0xBC3BF7B802E71220ULL, 
            0xC7624B9627233E8FULL, 0x3E71522529E04C09ULL, 0xB782EE72CDDFDF89ULL, 0xE275ABE23B771A7FULL, 
            0x9490BFEDCCD8AE30ULL, 0x96F782B5D163D783ULL, 0xD5EA33587F73D2CCULL, 0x874B5E45675858A2ULL, 
            0x01D85F95FAF69882ULL, 0x0F53B9CA20B038BDULL, 0x4C62267DC7C86F56ULL, 0x683462427C44D38FULL, 
            0x66D07287CD9261E9ULL, 0x3D97486C4C2E11E7ULL, 0xFAADE9AF24469AE0ULL, 0xAD1E84C27A6BBE59ULL
        },
        {
            0x856717D0541965B3ULL, 0x6E8973F8E0F54C5BULL, 0x95087E46DEDE3EB3ULL, 0xA4FD88D8BFA635CFULL, 
            0x93DAB8051A4F1FF8ULL, 0x518C9442E83422F6ULL, 0xC06EDCC5B24F6439ULL, 0x07BE71FEC6BAA94CULL, 
            0xBA6112E5466C5F2BULL, 0x929E733E111FDCC5ULL, 0x4E2A58BE68459031ULL, 0x9166097CD9E65877ULL, 
            0x339BC5AF1D5290F5ULL, 0x8F3566B679474647ULL, 0xD28CD58B8DF3A68EULL, 0xFF912CF8BABAA522ULL, 
            0x93E7ED5889788D22ULL, 0xBC6DE2359D7275EAULL, 0x5E12FDE12679529BULL, 0x3FDBCE03BDAA28CEULL, 
            0xA8E5B0030FBFE826ULL, 0xC58B4C0DE3BC36D8ULL, 0x4B22144FDD594785ULL, 0x482E3035E7FCFD64ULL, 
            0xCE79BAD74BAA265BULL, 0x31F85EE4809014E5ULL, 0x8734A6AE2EA8DC53ULL, 0xA8D03116AE229574ULL, 
            0x463C87E2CC5BDEB2ULL, 0xCB5586603C8E3ED8ULL, 0x01C0BC953D6669B6ULL, 0x24E3344A8A5F7F2CULL
        },
        {
            0x72D940F37FFE5732ULL, 0x7D56F15273AA0B93ULL, 0x05E6521ECEA27E8FULL, 0x0AB472F20BC8D15EULL, 
            0xA949A0D2AD633A77ULL, 0x5BDBFED00C1B0557ULL, 0x6C5243387A2162DBULL, 0x08283098868776EDULL, 
            0x30E0849A2CC0D1F7ULL, 0x5938604781675D12ULL, 0x61730E7A4E29D878ULL, 0xBD38F067FEDA3158ULL, 
            0xDA35D7B79D0E887FULL, 0x80445C5B020AC14FULL, 0xCD564C4B0B722755ULL, 0xA1090655F0D1A9A4ULL, 
            0x188753D891185F7DULL, 0x50A7D3C9EF79419AULL, 0xE2382B9341285007ULL, 0x99F7196F4DFF74C1ULL, 
            0x5987F6941FB4DF3FULL, 0xB222406CBFA7378FULL, 0xEA6CFB8D66555BE4ULL, 0xA1E053A9039FF32FULL, 
            0x541147188AE5A934ULL, 0xE8A8F8055598D91CULL, 0xA2971993E910BD8CULL, 0xC331FFF514B519CCULL, 
            0xA4B229A6801F4AEFULL, 0x0570B6DFA38F9286ULL, 0xF31B2F83D732F7C0ULL, 0x8FFB89519CDE0DCCULL
        },
        {
            0x1C34EE9B4EAEBF80ULL, 0xBDE6C10991197B74ULL, 0x1F118B83A26442A2ULL, 0xEA9C284488D1D207ULL, 
            0xE04D781B483F1F31ULL, 0x832CB18680F1741BULL, 0x9D13C391AC770D9DULL, 0x132818C1D2B92B6AULL, 
            0xBE3DC0CF1070541CULL, 0xE8B5AEF93F15DB8DULL, 0x5FA569C471B70F78ULL, 0x651E5E396C270F6BULL, 
            0xBCF71968ED0E3085ULL, 0xB19B80B0B04BAA1CULL, 0x1EE9FA10892EB886ULL, 0x4E61A88891BD2992ULL, 
            0x7914627D9516E21AULL, 0x35193DC4366A0095ULL, 0xEDA952E829C780F6ULL, 0x6CB74D74A141CB4EULL, 
            0x823788BEE4CE6FA2ULL, 0x063170EB4589E057ULL, 0x705768C291994480ULL, 0xC77A868AFD8D93E1ULL, 
            0xD67E99E9C3310510ULL, 0xD044BE35A59CCEA1ULL, 0xA2B1810EA6A6012AULL, 0xE80A9D53F35D6B19ULL, 
            0x36C62297E2773E8BULL, 0x8C01C5BC449EE5DDULL, 0xB36F7701569F367FULL, 0xD9B3B9B11007344BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseFConstants = {
    0x1C500D9F6E2B8583ULL,
    0xF69D2238FF077C10ULL,
    0x2948AC1A77458EB1ULL,
    0x1C500D9F6E2B8583ULL,
    0xF69D2238FF077C10ULL,
    0x2948AC1A77458EB1ULL,
    0x612CFE8AF779EECEULL,
    0x5DFEDAD75B42FEA3ULL,
    0x80,
    0x24,
    0xD5,
    0xE8,
    0xCA,
    0x56,
    0xAA,
    0x04
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseGSalts = {
    {
        {
            0x10CD9C57686049A0ULL, 0x5FD47A76A3AC7DDCULL, 0x2EE4C87CCFF9D952ULL, 0xB44439C7AB545D08ULL, 
            0x81A934D7FF8078B7ULL, 0x212799A2A77C23F0ULL, 0x9DF289AB6A270903ULL, 0x94380CB187EF80BDULL, 
            0xF0CB5C79FBAF791DULL, 0x2EDB1B21B541EA20ULL, 0xCA82E4EA546F46DDULL, 0xC2548A9859CA23F4ULL, 
            0x3118F3D04655B8BAULL, 0x9C52D615F486266CULL, 0xA4D49D5363A90DDBULL, 0xD97D68AE9BC7C773ULL, 
            0x3C87538CB523E07DULL, 0xC50468170A08CD15ULL, 0x4087B1DDCF692CB7ULL, 0xD9D0E43C6BF7F008ULL, 
            0x70DF372A1822E755ULL, 0x53A5FFEF0F5188A9ULL, 0x61A63B7C240D3486ULL, 0xA8B6C220F5ACC375ULL, 
            0x3B4B81EA5C8BD8CFULL, 0x38DB5111E247E74FULL, 0x98A18F365849D4ACULL, 0xF04C75C657924864ULL, 
            0x97AFF0ADD4A46D03ULL, 0x3535782F8ACAE9FFULL, 0xC728B92B770AEDD0ULL, 0xE1119FF3C738AD96ULL
        },
        {
            0xFEFE424214BCB0DAULL, 0xE89989AEA94D8DB9ULL, 0x22EC32A9B1512649ULL, 0x15A179D2D0556794ULL, 
            0xD426A9C8C106F43AULL, 0x39B66B2C687BB061ULL, 0x57A5BD4986EA6C94ULL, 0x5B63D37230850CF9ULL, 
            0xC6D9F760C974CE45ULL, 0x0E0539BE6946962FULL, 0xB721C439059C8604ULL, 0x98D6D4D6CE6C78E5ULL, 
            0x2D508C419DCEC9F4ULL, 0xC0A68D03BB592735ULL, 0x284F780667D767CEULL, 0x6B46420188598879ULL, 
            0x90B5BE8C1D305561ULL, 0xD83DC10CB850529BULL, 0xD3E9961F66981683ULL, 0x742AE856F9BF8543ULL, 
            0xF3FC16745ABE4961ULL, 0x39C9F860A744B5A5ULL, 0x0E3B6004E95C037CULL, 0xAFAA8B8F157A9D2CULL, 
            0xAE92B459C0716F5DULL, 0x7C21F0940C783881ULL, 0xDDD52C906CF0FF9CULL, 0x199B6F41C372A281ULL, 
            0xC344F4CF2753A945ULL, 0xC0CBE6AC83F1B779ULL, 0x1434D4B0B955E798ULL, 0x3CF096031D49CDFBULL
        },
        {
            0x510DE529FFC1088CULL, 0x93B6F1715EF9AE42ULL, 0xE533F5FBC1C519E1ULL, 0x412FF8FBD48BAB8CULL, 
            0x04096407FB20C104ULL, 0xF26A1A553D2561FFULL, 0x6EDB453376D930D4ULL, 0x0A64C764064AD19AULL, 
            0x4E05C506A6216574ULL, 0x50C9341D0146B5B5ULL, 0x7E8C6F91B684703DULL, 0x34230FD6669AE66AULL, 
            0xAF849C0094D0C833ULL, 0xA6853ED3F2432B9BULL, 0x188F58B82F899F93ULL, 0xF0979DFB5286DBF1ULL, 
            0x58C6A0DA1F33F734ULL, 0x34AA32723D3D5287ULL, 0xB5F3A8BB478E6CDBULL, 0x0548D70DCEB62C17ULL, 
            0xCDEF7F28CE054BD1ULL, 0xD7A30A106439F305ULL, 0x894E68C3D63E5E39ULL, 0x2D52B95CB22E7E1EULL, 
            0x7F42FFB27ECCB3EAULL, 0xC4AA2340A288A0A7ULL, 0xE0074FFA9731DA81ULL, 0x2FF5922258C02A7BULL, 
            0xE81781D895E5A7CCULL, 0xCCE3B3B3DD6F0D9EULL, 0xBAFC85344226CB64ULL, 0xA43F914C5D49DE27ULL
        },
        {
            0x80B802F1EED620ADULL, 0x19B15E2ABF2A7CBBULL, 0x9FDB2767D3A5A8C2ULL, 0x359994BA8857330FULL, 
            0x7145700634329F73ULL, 0x2C6A37F8B29AE070ULL, 0x407B546484843270ULL, 0x9D325973DA62370DULL, 
            0xD5FC8107FDDA1E74ULL, 0xF7D85ED834AC219DULL, 0x17EE5A902AF8C205ULL, 0xC84D26E7A837C27AULL, 
            0xBCA35869434741F0ULL, 0xF937A84309CF4476ULL, 0x8D3365B2D395F608ULL, 0x99F934FA37CE81F5ULL, 
            0x3BFB2389BB31AD0DULL, 0xE751FD36700F5EDDULL, 0x5A49FF1EF6B076B9ULL, 0xAB2C1C35F28B7061ULL, 
            0xB70C06E57F977CA4ULL, 0x2A4AFBE64E4E9DF4ULL, 0x5BB734A30956A406ULL, 0xD96CAC1ED0E20383ULL, 
            0xA6628AF54860071AULL, 0xAB971A881650D369ULL, 0xD84FC54A555F726AULL, 0xC1C6056581CA7B7AULL, 
            0x63BBA3584F02DDFFULL, 0x05E7067196080E33ULL, 0xA7AA6B9A13F7F4A3ULL, 0xACC9DBA50CF2B504ULL
        },
        {
            0xE2A7268E22CEB35DULL, 0x447E13DD60ADC331ULL, 0x376951CF3BAE73EEULL, 0x8EF3DB21446F0522ULL, 
            0x72A68C7CA342040AULL, 0x071B0ACEC52CB8E2ULL, 0x95E79ECEB8BA52CAULL, 0x7DEA25FE8652315CULL, 
            0xC3E0A96B1FAB975FULL, 0xF50AAE68B5C52F7AULL, 0x75AA324E545B0BBCULL, 0x281855CC5371A8F8ULL, 
            0x38EE1D77AC347910ULL, 0xDDE219C51BB76E7DULL, 0xC664744C1B40771FULL, 0x429F16A96FBE2CE2ULL, 
            0xF9C40415855CF898ULL, 0x6F324E6895FEA3A9ULL, 0xE75B5FFD098A1931ULL, 0x646B9358F667E87DULL, 
            0xFDC0363D661060CDULL, 0xB4DB57757A3795BAULL, 0xD13792D5B8D70ABFULL, 0x7EF48FF528C59E8AULL, 
            0x8BAAD60F0DDA7507ULL, 0xA1C172DDEFD78024ULL, 0x2F64DC0199F71542ULL, 0xAC9606058F27E0A3ULL, 
            0x385B18B6410F4B43ULL, 0x252773B80960E8EEULL, 0xE578D5E23B22F6CDULL, 0x93F0BD7D8A4CEE3FULL
        },
        {
            0x6192B55EABC4371CULL, 0x573E7E409F54A99EULL, 0x942E1CBC9D0E1AECULL, 0xA3B56B267939E6C3ULL, 
            0x7C71D8852127CFACULL, 0xEF5C7E909A8D99EAULL, 0xE8D905FBC70FF3E6ULL, 0x8C539FC85C92F2D9ULL, 
            0xBDA31E2ED45C3E66ULL, 0xC446F58BF5D82CF3ULL, 0x645457F5A4FCD4E7ULL, 0x85E12EB5B76D7A45ULL, 
            0xC04B1F72EB15E0B7ULL, 0x63DAE4372E7FF219ULL, 0xBD16FD9D84CC3978ULL, 0x1809F7994225F2CCULL, 
            0xCD012EA68B9FBE1FULL, 0x044844EF35A6A0B3ULL, 0xA05FE90CAAFE1F87ULL, 0x5560B18A09D92C50ULL, 
            0x82EDE838613F5507ULL, 0xF1342FFF9A194C45ULL, 0x574EAF6346DA401BULL, 0xD3A48F4B421C2396ULL, 
            0x7CF4FC5C571B1DCBULL, 0x13A67E068BB80D03ULL, 0xC5E84EA36D144CC1ULL, 0x5E931DEFF51892BBULL, 
            0xA325288E34644C8DULL, 0x665D9885C9B017FFULL, 0x4FFC5F4C7FE648B2ULL, 0x2742A53E0022FB3AULL
        }
    },
    {
        {
            0x65D43BB198A7E39BULL, 0xC839FF95EDDC95E3ULL, 0x14788D6883A14C59ULL, 0xECBC6AD863A6F1F2ULL, 
            0xDE1FB6F417860D5FULL, 0x7C7826583D02C5F9ULL, 0xFBA08BD5E082CB51ULL, 0x0CF6DAE46AC11ABEULL, 
            0x1B812B49126F72E9ULL, 0x446AD2030105264AULL, 0x0299484B88111B75ULL, 0xD9D7CAB76FAE77CDULL, 
            0x5FBFD76A885CCB9CULL, 0x46E2D0380AAFCF23ULL, 0x77CD4E2009558E72ULL, 0xFBC483D5494F1620ULL, 
            0x3B409F2BD37DDA55ULL, 0x9731D1019AF56734ULL, 0x10BD4032C87069C7ULL, 0x7CF14D06A9C1C6E7ULL, 
            0xD54BAE28E70F54D6ULL, 0x2766C9BDB47A07BAULL, 0x27B71986668489B3ULL, 0xD61EC601241E49DDULL, 
            0xCEE999D7A96D70ADULL, 0xBF0EC30B7E9B76CEULL, 0xE1C72030C88A372EULL, 0xA722092E2AEC2F7CULL, 
            0x83B9846F436C824CULL, 0xD726C4F3AE0C38ADULL, 0x9A8E6F05A49C9FD7ULL, 0xB32C2CDEAA40AE90ULL
        },
        {
            0x1F8B8CFABE5F7DBFULL, 0x1378A37278928701ULL, 0xD2B093A4A1BCC2C7ULL, 0x349C5836C5AE1362ULL, 
            0x22CEF74D660A4C18ULL, 0x0730C98CC452FF91ULL, 0xA8D95F96975EC91CULL, 0x4F6FC6F63BCB0FBFULL, 
            0xA6DB1C2A88140E12ULL, 0x786829A33D0DAA8AULL, 0x218BCCF5CA28B367ULL, 0x1822222CB86B877FULL, 
            0x59E665A1E2DCB722ULL, 0x4E3F7E8E12F32D34ULL, 0x5FA4AC2A4ECBC6ACULL, 0x39DE222E53A05B4EULL, 
            0x84447D7CDBC6D816ULL, 0xA58F13C69B6D51DAULL, 0x80932A7308E424C1ULL, 0xEDF6A10D5B7FF80CULL, 
            0x81C8905EDB868F98ULL, 0xEB11CF2E8ED5790AULL, 0xBB97F36409357FC8ULL, 0xB4CC9E7920842A36ULL, 
            0xB40D5AEE181732B1ULL, 0xC62D3A483A52D675ULL, 0xED1BA7F99E1E489DULL, 0x14508E7B76EE5400ULL, 
            0xBA8830A25B0911EFULL, 0x5A7B2C8516E84D9CULL, 0xEAF3C0D5945C5957ULL, 0xECA5AA903D8870F8ULL
        },
        {
            0xAD0521959F19C5EBULL, 0xD96F0157D2F2A426ULL, 0x9D4D7F8E25F76E45ULL, 0x7DA68DDDACC7CEECULL, 
            0x35B76056F8DD7126ULL, 0x1CDF88EED5C9948FULL, 0x3EE2760E75FD56C5ULL, 0xDCA84D1EF1680E0FULL, 
            0xD5ABDBE0E1C57084ULL, 0xC84AFE704DDE9CE4ULL, 0xD85FC6DC79CBE534ULL, 0x553CA24938CA4242ULL, 
            0x803442A725D41A45ULL, 0xAC08588BC18D952CULL, 0x361E0CD8B1B7A548ULL, 0x90BB86A7209BEB27ULL, 
            0x664A8244BF625877ULL, 0x5A98F84FAE4C6776ULL, 0x4099EE7B4F590BC7ULL, 0xEC6C06789442CF4AULL, 
            0xF04792C5AAE9F5E7ULL, 0xFC4D273D31EF70F8ULL, 0xE2211520B3E635ABULL, 0x7038E3878575FBEBULL, 
            0x482E9B412F54323FULL, 0x0D3F1416D8084EFEULL, 0x3EED5AA42E28872DULL, 0x354BDD3702B2A06DULL, 
            0x6ED9CDFCCE2356C8ULL, 0x92912E684F7D4D01ULL, 0x47A8C499473446C3ULL, 0x0B640E5A00569543ULL
        },
        {
            0x9B42F5DADDBB8433ULL, 0xC0107D2423DD90DEULL, 0x922394F1C3E44EFAULL, 0x89145BD612430DB6ULL, 
            0xB46CA0B40384AFA0ULL, 0xAC2EF9409C5E4E1DULL, 0x9CBC3721F48D93C3ULL, 0xB3ADA5A23300C9BCULL, 
            0x92A1B7BDCD7504C6ULL, 0x2E1751076D6A1343ULL, 0x4623A1829B0F898FULL, 0x5988B8AF137EB9BBULL, 
            0xE9E54901E6F9FD78ULL, 0x181F4BE81CE51CB1ULL, 0x1BE5193EF2C1AB20ULL, 0x784F80BEF4441713ULL, 
            0xD47106C27C093EB9ULL, 0xA8EE219932CC34B3ULL, 0x0594AEB95B5C76BEULL, 0x996FCA79BFC2A1B4ULL, 
            0x874FCB66064CB1C5ULL, 0xC289D7C750B9DD3CULL, 0x6035A1435E838A78ULL, 0xBD7692DC023880D4ULL, 
            0xB0485BE9E50E5410ULL, 0xAAD9827703E4CEE9ULL, 0xDB6ACBD6CE1CFEC4ULL, 0x2185AC220672F83BULL, 
            0xC581D8F7FFCA9D12ULL, 0x9D68EA6EE74E0D3CULL, 0xAE159477856A4CD7ULL, 0x4887E8FD6B1296B1ULL
        },
        {
            0xA29868EF737EC987ULL, 0xCCAEBAC6E3F0A15CULL, 0x782A8D9074A59745ULL, 0x38EBB89C73D0437BULL, 
            0x2DEC88CCBAB29FEDULL, 0x868C5331E71A08CAULL, 0xEADB9A03F7E1787BULL, 0x23E140E444C70A3DULL, 
            0x0772A9CA1B28D7F7ULL, 0x47F698978153E1C8ULL, 0x00D20CD50C5193C6ULL, 0x23192259B9E9011BULL, 
            0xEA036E67579C3CA6ULL, 0x912725F9D7C71DB3ULL, 0x8AF0A8572E156728ULL, 0xBC3C1913AC3941DFULL, 
            0xCA3EA1636DDEABE4ULL, 0xE6620D31345FECE0ULL, 0xA9B9828B12BE5D83ULL, 0x24E513288FDCC15FULL, 
            0x0C7C7B62E3C36F8AULL, 0x06313135F6FBDD7FULL, 0x7134DA03B2007906ULL, 0x719E7044FEF26B8AULL, 
            0x84ECB70303E03FC7ULL, 0x7EE66D4B1F166D97ULL, 0xAC2ED53748E92855ULL, 0x4D84D1F711F1B2C7ULL, 
            0x85732A7794CA6ACAULL, 0xF82DC7EE7448BA18ULL, 0xCDE8CD69EF71A9D1ULL, 0xCDE0705D01D208A6ULL
        },
        {
            0x038734F4F8437857ULL, 0xBFB48D334D5B9DF8ULL, 0xD82B23610016B434ULL, 0xD0278AF5C319338AULL, 
            0x26B45286E159E531ULL, 0x89BFF70FE5D5A3A3ULL, 0xDC21C472F4A0C414ULL, 0x7CF7C56DD2278940ULL, 
            0x701A693566E0669FULL, 0x5531145E516A0829ULL, 0xB0E4295C7A48ADF0ULL, 0x053800DE4D5D4E3FULL, 
            0x544352BF373C8624ULL, 0x4158446C89046C0AULL, 0xD55465DDCDA2DAEFULL, 0xC2E54B1738EA7123ULL, 
            0x284B54CA690B6D8BULL, 0x6D381BBEFF3B5FEFULL, 0xEBFF0D15FD898AEDULL, 0x686402FA0544CB31ULL, 
            0x91BBCCB68ED561D0ULL, 0x1CA1AE3250683187ULL, 0xA529DE0324C2CD78ULL, 0xE8809792F2047504ULL, 
            0x579DAEA8DF0593A4ULL, 0x0901163EE064B244ULL, 0x6EE8B2AED6BCF69DULL, 0xA36FA4F9D622C007ULL, 
            0x017E7D6D723CA945ULL, 0x23F291437B621D64ULL, 0xC6E55C90280AD44AULL, 0x354837687224BB61ULL
        }
    },
    {
        {
            0x26FCAA1E3C894F83ULL, 0x5A975F8766F4037FULL, 0xEAB41842C5BFAE4CULL, 0x88E9C5A5EF629B00ULL, 
            0xACAF920B744D293EULL, 0xA030A13B5292FB9EULL, 0x193D759F73B219C1ULL, 0x289A883607DACD83ULL, 
            0x3BCCD64937471005ULL, 0x894958D50049B021ULL, 0x779CDAD4B1482C2FULL, 0x48D3DAFB0D88B0E9ULL, 
            0xCCBC7BC1D4D75BE4ULL, 0x727627DF6C6491DFULL, 0x4C9BC06983F89532ULL, 0x68D74936F3DA1B8BULL, 
            0x34DB3C7307F664B3ULL, 0x3FFD95C518F8F322ULL, 0xBD79A21819749782ULL, 0x884BAB50DF8AD1AEULL, 
            0x9CBE56F9C4F7FEDCULL, 0xDDB76B8B9B613E99ULL, 0x5A881D42AD8241B7ULL, 0x0CD55BA777E672A3ULL, 
            0xA7D83EABA0E3E476ULL, 0xF2C8AAA5522628B2ULL, 0x470A96EDCE7DA161ULL, 0x23003983E9A49BDBULL, 
            0x44F97EEAA0AA3037ULL, 0xF9CAD51640E6F26CULL, 0x31E4B6A7C93287D0ULL, 0x5D68A32752B8C74CULL
        },
        {
            0xBDEA2812E3A3AD23ULL, 0x42001696EDB094F3ULL, 0x3D6DD5F6EEFD12C9ULL, 0xCE00DB7362B2A7B9ULL, 
            0x56DCF703B50EB595ULL, 0xFA30BFF3606341B2ULL, 0xD548B032CA79D8EDULL, 0x21C207693A15B37FULL, 
            0x696F6EAAD2C91D91ULL, 0xC957D40D114AF251ULL, 0xAFF78BDB22CA3731ULL, 0x7ECCD9DAB2797FF3ULL, 
            0x7BADE4C877BCBA53ULL, 0xC1A59E50CCAAFD0DULL, 0xE5C85A37F52B33EEULL, 0xEC97E6BCA4A89202ULL, 
            0xD550CEF272CC6F18ULL, 0xEBE66E9740DD76B3ULL, 0xEA75B5F5A23930E9ULL, 0x93D3877F91444C92ULL, 
            0xDE34F330EF219E34ULL, 0xF8DB75EF04E2CEDFULL, 0xB242197C0EDB6CFDULL, 0x65E087C782C8236CULL, 
            0xAB6E045B41ECB0C7ULL, 0x9A66A3FE37E24CEDULL, 0x373949FCF7EE61F4ULL, 0x48BE7E55714E340CULL, 
            0x27F09E890C87F139ULL, 0x5D51D80E1FB3A623ULL, 0x5EC8302051C095B7ULL, 0xFB65E8C0D31B6E54ULL
        },
        {
            0xB1ED979B73A565BBULL, 0xB40A68BAF040CD8DULL, 0x7C597FFF611DD683ULL, 0x46235478D9AA6A21ULL, 
            0xDBE7784AF9D04AAFULL, 0x6420413192613ED2ULL, 0xB55B528FFA329AC1ULL, 0xF0FC8340D6CB52B2ULL, 
            0xDA4A037515EAF969ULL, 0xF8C7FD48F7231362ULL, 0x3A9B02F4B4CBFCA4ULL, 0xA4CC85FCEE9BFC0EULL, 
            0x3E565838DF48D5E4ULL, 0xC10AE6BD9FE397DDULL, 0xA44EA7A8FD0540AAULL, 0x74C6243E0E596990ULL, 
            0x1E850C3A9CF3282AULL, 0xFCB5719570BEA522ULL, 0x414B93F08C88E0D9ULL, 0x51A5539EB9B0BB08ULL, 
            0x101A04B375970F51ULL, 0x3DD65EE5939462BBULL, 0xEEC8022548DB6ACAULL, 0x933A457E8D473841ULL, 
            0x62EDD189BF464E2DULL, 0x799E3DE7E19D02B1ULL, 0xD6E2B803B6E1E893ULL, 0xEA5A21CA1CA8D7B6ULL, 
            0x96CEF7D9973FCD9DULL, 0xD47DBECC1325257EULL, 0x3F373EC7EBA5D436ULL, 0x92E2C732E292E77CULL
        },
        {
            0x99796BEC0B80A634ULL, 0x61A1D0E74CEA9984ULL, 0x59D93A4FDD375E36ULL, 0x6B80AFC19DDF0A65ULL, 
            0x026B3D3CB25A97ADULL, 0x1D376E8975DCF9FCULL, 0x542961435DF426B7ULL, 0xFFE679E15CA14B03ULL, 
            0xBD72DC49046E88FDULL, 0x03555122535AB10AULL, 0xB61CB6812D000886ULL, 0xAB340C429B68CCA8ULL, 
            0xA707F18B44D2FFA8ULL, 0xB97269AF30DED735ULL, 0x164624C7184586EEULL, 0x5B932AEBEF21D50EULL, 
            0x8769070782DAAB76ULL, 0x9F671C77676315BEULL, 0x4C82B32A9EABD19AULL, 0xDFBF903B53ADE1C9ULL, 
            0x3C70972431A00D2FULL, 0x8CC7B71B97CAEE0AULL, 0xB6D739B54E95FAB1ULL, 0x0B3A3657702FAEC3ULL, 
            0xB31952B4A3E2EFF2ULL, 0x78660A78B6C24F9EULL, 0xEC4FF04903E2EE29ULL, 0x7F37F808DC2BED29ULL, 
            0x8909D60EDC896768ULL, 0x5AA5DBE31B1C4A99ULL, 0xBC011AFC34384B28ULL, 0x75FE4D281403952AULL
        },
        {
            0x442F0CF7058BDCA1ULL, 0x8187B4E4B57BCBC9ULL, 0xE5B00A241869A67BULL, 0xCE136021437EFB63ULL, 
            0xD72F3C49E6E132D3ULL, 0x47B9A4CBBB181462ULL, 0xC3D6DED06CAED2FBULL, 0xFB6744EBC4855857ULL, 
            0x8D7D806C79A56670ULL, 0x84C44375593AEC78ULL, 0x600F68D967F5C00AULL, 0x3B965C845DE884B6ULL, 
            0xC8E64A2AE3D1686CULL, 0x6AACA392F425217AULL, 0x656AE4D328684FC7ULL, 0x4D2C05AAA0B5F028ULL, 
            0xA91AFD3DB5978BDEULL, 0x08E99CFC869050BFULL, 0x46058B246FF8CA92ULL, 0x9E50A08976040072ULL, 
            0xBB7437DB728EC5EAULL, 0xDE29AC77ADC0F1A4ULL, 0x8879F8B6B05E7A0EULL, 0x5894F35759E4A04AULL, 
            0x43CF27515197DFF4ULL, 0xAF87EB65AFAA813EULL, 0x41A1070BC851C9E4ULL, 0x6B1B2524875776CEULL, 
            0x014A9D08F81CE949ULL, 0xBB2D77FC56B5134FULL, 0xBA118CDA77B7C387ULL, 0x549623EDE6A9DC6FULL
        },
        {
            0x08834B1199B8D653ULL, 0x84563931C41E8DFAULL, 0x608E85DA4F0C1FA6ULL, 0x18D153E1C0256B0DULL, 
            0x7F86D6DE260953B4ULL, 0x29A3DC18A6BDB7AAULL, 0x2520390CDE547077ULL, 0xA363AA519FA6E0D0ULL, 
            0xA5FA585AA38888FFULL, 0xF883016D9DBAD953ULL, 0x40421D9F7EBD5CB6ULL, 0x3FE5A2411C98D6BCULL, 
            0x4207B9E3005DA2C2ULL, 0x0291D20DF14C6CB5ULL, 0xE234FAB1E27C3CC6ULL, 0x4DF53FDC3DA50A33ULL, 
            0xAD150619B30BA19EULL, 0xB48C844AD45E8ECEULL, 0x9A2DCB3DA59A830DULL, 0x385B3D418BA78B7AULL, 
            0xB74062C4A43F5FFFULL, 0x98BB10F1F5DC386DULL, 0x0B26AC2A8C4AA17BULL, 0x018F3853F2B98B7AULL, 
            0x01A66F5A38CC2222ULL, 0xF65AC1F5878E092EULL, 0x168008ED725F5AA0ULL, 0xF9AA95FDA0A06445ULL, 
            0xA11FE12AD7B676DCULL, 0xBABE90C7CD5BD528ULL, 0x00C3B93B70D08DF3ULL, 0xA117F46A6666242AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseGConstants = {
    0x92A2DCE920834336ULL,
    0x4F9B78E7F2B4103CULL,
    0x4D6385ECFB054062ULL,
    0x92A2DCE920834336ULL,
    0x4F9B78E7F2B4103CULL,
    0x4D6385ECFB054062ULL,
    0x4DAC3FDEA2243627ULL,
    0xCFFC6B80FB1FB332ULL,
    0xAC,
    0xA5,
    0x62,
    0x34,
    0x80,
    0x66,
    0xA4,
    0x08
};

const TwistDomainSaltSet TwistExpander_Golf::kPhaseHSalts = {
    {
        {
            0xCC9E32375083086EULL, 0x7E4DC0F0427565ABULL, 0xA0F9975561B0B1D0ULL, 0xF0C3270AAF74A1C9ULL, 
            0x0692ADC0140332AFULL, 0x452784909530E5D9ULL, 0x21A9427A3E672C3EULL, 0x825483372875770FULL, 
            0x4C1916880A3EC5C2ULL, 0x7752398B9C67F702ULL, 0x4588237E8AB7EFF0ULL, 0x15E3187AC07464D0ULL, 
            0x966EB4B701F252B2ULL, 0x4B5F8CC5A217548EULL, 0x6C299C8A7F347DFCULL, 0x477D3E535EB5E5DCULL, 
            0x84D21499E9E5B99DULL, 0x694EED8353D15B87ULL, 0x04EF38F142A556E8ULL, 0x639528DEAE340638ULL, 
            0x687BB3C4FD7A0BA0ULL, 0x1732CE318CA67A85ULL, 0x7D9E0ED8E3433FD0ULL, 0xD4E8855331CD7407ULL, 
            0x16814CE15747F0B5ULL, 0xB1F1A15E043B0141ULL, 0xE93B4D62826EDF59ULL, 0x3948865EC9C25450ULL, 
            0x472A391F99AEDA75ULL, 0xB634E306F1A41099ULL, 0x46BBE9ECD8AD5444ULL, 0x28B9DCF9A2C1D316ULL
        },
        {
            0xBFB9FF0A4D5304CAULL, 0x8F46815C8C193EE0ULL, 0x104ED694675D3E7DULL, 0xFD5D5E8E86FC58B7ULL, 
            0x0D553E85AA694BB5ULL, 0x7175497F1490D4C5ULL, 0x12C2ADA1E796937FULL, 0x3067268E0C6A33F6ULL, 
            0x9A1C22E7BB99C9D2ULL, 0x41C9A39B0D77F7AFULL, 0x4B501C7FA2C21705ULL, 0x234C877AAC9BD5DEULL, 
            0x327F0C58EC152FE3ULL, 0x89BD1F2F3EEEAF22ULL, 0xCEEF5BDEAF22C0AAULL, 0x21FA540FA9FED56AULL, 
            0x6FC2C286FAFE5D16ULL, 0x2D4936C57915ADF9ULL, 0x3B2FAD11AB3B9DF2ULL, 0x8DE3C807E9EAE9B9ULL, 
            0x9BB02847B768FF29ULL, 0xAFF26B0E3EB81F10ULL, 0x4648D6AB8E4F84A2ULL, 0x7F866E33559D6577ULL, 
            0xFB39FE3BC14E30AEULL, 0x36103CC00E7292D1ULL, 0xEA9C77726106D02CULL, 0x123F714D22458EB5ULL, 
            0x4395BC5ABAE1300CULL, 0xFF7C13BC0F971FC7ULL, 0xE1A9D14CB892AE39ULL, 0x651314FCF7850625ULL
        },
        {
            0x474E6B737C7D9623ULL, 0xF29C599796B82030ULL, 0xFCF17D11BDB7E2DFULL, 0x4F5F77AA04D89CD1ULL, 
            0x61B2F183E56E9E13ULL, 0xC6F11A0597061EF9ULL, 0x7D194ED741408137ULL, 0x982AAD046B215D84ULL, 
            0x5C0E7329E8F76D32ULL, 0x73A9C1BACB685B39ULL, 0x489970379C222C76ULL, 0xFA09FEC7A2F308E0ULL, 
            0xEF2BD17111895EAEULL, 0x7F79E3009827D7F4ULL, 0x65710AA126E96BC7ULL, 0x5C63932B916ACD70ULL, 
            0x36B05326615224D2ULL, 0xB3DA417EA4C88CB9ULL, 0x0B489827C26BF24BULL, 0x9759C278242A07B1ULL, 
            0x0C8C528A5D52C86DULL, 0x661920AD68D8F035ULL, 0x8B6B1B805CF3C096ULL, 0x49864A0018EFC734ULL, 
            0x9BF471352E909676ULL, 0x5A486B8AD08309ACULL, 0x8BC86F8879572A2FULL, 0x68CE295E0AC335C5ULL, 
            0xF228DEB2D959BB93ULL, 0xB14679EB2631B2DAULL, 0x0ACE7D87CB905121ULL, 0x0358E984D6050B38ULL
        },
        {
            0x981DA06AAC5CE457ULL, 0x2ECDD5A08F38C83BULL, 0xF52104E2FA750ADAULL, 0x054D934BF0C8C40CULL, 
            0x94AC6F49BEC808A1ULL, 0xA962E5CFB0BEF32FULL, 0xED5730DC619443BBULL, 0xB3254A17E82B7B21ULL, 
            0xE93FB65BFBFDC873ULL, 0x68F01736AE9F5F9FULL, 0x428461CFDCC064F9ULL, 0x05D3B117F7A784E3ULL, 
            0xD58D33B6EF4F15DCULL, 0x454AAFD3279C3186ULL, 0xA73B367404F433EBULL, 0x8C152F65009165B2ULL, 
            0x783AC2AC5795221EULL, 0xCC63B1D3745EA29FULL, 0xF888757019BA071BULL, 0xDC5D86E581AB7DACULL, 
            0x549B1B0B9F652977ULL, 0x4BEB3CA85AC7F2A7ULL, 0x8B1D10CD89A44F0BULL, 0xD678336BCA4A8BEAULL, 
            0xDADB08B60AF3B77BULL, 0x6808687BAE151D45ULL, 0xE1F5698235BF488BULL, 0x9B00A75B7BB4CCD4ULL, 
            0xD9D7D308CD97E255ULL, 0x67328537F411BA79ULL, 0x0851AAE687C6EA3BULL, 0x15BF91455DC04E7BULL
        },
        {
            0x3E2438CDC28F21D4ULL, 0x01880895D1B88D46ULL, 0x578C17BDEDAAC079ULL, 0xC4C3893A1D97BFB0ULL, 
            0xE891EFF2D3967B25ULL, 0xEA0889ECB9E5B685ULL, 0xA8F6A1A2333BD967ULL, 0x3CD53283CB6A381EULL, 
            0xFB799724DE966956ULL, 0x48250D965906E23EULL, 0x7A70F7C25F4985F1ULL, 0x67F43AC784D6AC5BULL, 
            0x818C7E5A8BBD78FCULL, 0x2244B64C69490F6FULL, 0x66ABBA698E3BCEEFULL, 0x318258337C9BA8EEULL, 
            0x60B4A85808DE4459ULL, 0x02D31E544EAB1A5BULL, 0xAD6BDB3A74582196ULL, 0xDEB706FEB6254488ULL, 
            0x53FCF32253B40DF8ULL, 0xBD8FA06FE81EE9BBULL, 0x21E73E8995F61A02ULL, 0xCD4709C8465EB720ULL, 
            0x1386F7B983E51552ULL, 0xFEFC4BB52F80236CULL, 0x0F3A8B76B056137EULL, 0xEF4C3E7024AAEF0DULL, 
            0x86C4592883C0891CULL, 0xB58F5A3425194DF1ULL, 0x87F9C02B2D749E07ULL, 0x17D241B132AAC994ULL
        },
        {
            0xB145F9A8409A2AD9ULL, 0x8830B0144AA279ADULL, 0xE0EA9A302922F2F5ULL, 0x875AE08A26A2C594ULL, 
            0xCA63C79066A54072ULL, 0xA3F50DBFACE294A8ULL, 0x5B59837E66A2A517ULL, 0x68B778246461886CULL, 
            0x01B1CA4D5607E433ULL, 0xF869A26309D340ADULL, 0x73C8923605124684ULL, 0x1268B0DB87E701B0ULL, 
            0x672DB66E33B5F1F8ULL, 0x9F4CAAADC8699434ULL, 0x71366F75E9E2AA9FULL, 0x8B08E2C6D25D5959ULL, 
            0xC1C875DEC6DFE5CAULL, 0x3994102113316C64ULL, 0x810A9CE8609CDF70ULL, 0xC0DF3365380A30F2ULL, 
            0x837E23388DA77FD9ULL, 0x5385A842C743506EULL, 0x341A3AA0FBFCD432ULL, 0xEB177E5BD1C596ADULL, 
            0x0B80207A5490E14AULL, 0x9E19ED6529DDA178ULL, 0x1D80E06259F2F71FULL, 0x4B6ED3D54B57A329ULL, 
            0x522C5DB3B9DF75F9ULL, 0x6E1D7BC1397E75ABULL, 0xAEA825FDB42CC5E0ULL, 0x62CC863184BC6A2BULL
        }
    },
    {
        {
            0xB29E9DCF396A1682ULL, 0x9443EAB292DE4C8AULL, 0x3CFF00B074522A8EULL, 0xBD7A0978FA53DA68ULL, 
            0x64F8ACA44DA59354ULL, 0xC57D67BC55E28B3EULL, 0xF54D17E95CAE7E12ULL, 0xED70B8F27D890406ULL, 
            0xE9BFF4DD64BCF732ULL, 0x994262E53D21D94FULL, 0x986728B795CAABD6ULL, 0x73588847940111FFULL, 
            0x4321ABBE82962DFFULL, 0x641AA805891A052AULL, 0x9371082FFF1EC94AULL, 0x247F8863DF3EFD89ULL, 
            0xD2AD4F35A22AEA69ULL, 0xAA2DBF4978EE0224ULL, 0x36C4ED3D2F3C0BA7ULL, 0x8E014AF7948AC82DULL, 
            0x8513A213692DDA6DULL, 0x7B98AB38D913961AULL, 0x8F7E48859B3073D2ULL, 0xF4753F415BD70C51ULL, 
            0x365B4DF83BE1768EULL, 0xB8D26A798148DA9EULL, 0x3A473DA861F40D66ULL, 0x8E23BB0900085AA4ULL, 
            0xAC93F0E7D337C0FEULL, 0x72EB34B8FDB31DE5ULL, 0x06F0ED451DC18A78ULL, 0x76FFEAF73289496FULL
        },
        {
            0xB6052EF1820F357FULL, 0x4EF4E0DECE3CDA9AULL, 0xEE0A8EF6A85E3CA1ULL, 0xB20FE0F865C7CC7AULL, 
            0xB8A9174B99ABE16BULL, 0xFABF1A7150D6B4A2ULL, 0x45954BB1B98FC327ULL, 0xAF55EEF83DF21B1AULL, 
            0x494AB9CB0FDB7C2FULL, 0x353B4D01C785BA81ULL, 0xD7A5AE910E5C88D4ULL, 0xC77C491A71E5BC51ULL, 
            0xF17AB73F8B4867A2ULL, 0xAFB3C89C89CD3C5DULL, 0xC4103CC193AC788EULL, 0x979F7D2578D3C403ULL, 
            0x655F33B6C9FF99A0ULL, 0x8EDCB27382DE7181ULL, 0xB09E51E6CA79F42FULL, 0x650A726BC9077A2FULL, 
            0xC69B846850CC8040ULL, 0x1D0B245B8415E797ULL, 0x967D3E916789513BULL, 0x80A332BE2B36AF01ULL, 
            0xB7B81FAFCB1DF18FULL, 0x5A41EF80D850A9BFULL, 0x8F50F22569AAC2C8ULL, 0x06F65F8528FD2E8DULL, 
            0x7B334EB044D672CEULL, 0x144543204F419357ULL, 0xA54623D978228557ULL, 0xEF137EF96169E90FULL
        },
        {
            0x57D2E86449C06412ULL, 0xA694F21BF979B2FCULL, 0x5BEA5A2291533E50ULL, 0x5326BBCD04001A36ULL, 
            0xEEB9A4B20C4F66FDULL, 0x9A29EBF395E3EFEDULL, 0xFEF4FCC722D2B3C8ULL, 0x84CCA114AFEA4A24ULL, 
            0x243AC6C8E41729EFULL, 0x3C68CF8A472C2564ULL, 0x03D1624D82018C9DULL, 0x42F2722008B751B9ULL, 
            0x43C4FD4BBE79C77DULL, 0x7376F377A001A8D0ULL, 0x24ED3D54620C5E8EULL, 0x7ED0D7A736129D10ULL, 
            0x32E56990044EF042ULL, 0x5EEEC37D5A54F578ULL, 0xE8FDBED99BF64D52ULL, 0x05F2C6CCA0FA61DEULL, 
            0xDB3CEDE999C523EFULL, 0xDE4D23695C4209A0ULL, 0x7FE1B779F79DA4C4ULL, 0x520CF55638C113C7ULL, 
            0xF958AA752B20A189ULL, 0x19D5D8A50A006CB6ULL, 0x3361B8E6449864DEULL, 0x465DC4F69CE7E580ULL, 
            0xE43B168A72DCC7A1ULL, 0xDD19711D5FDD85C7ULL, 0x0FFDE1A75131A59AULL, 0xA2533AE708A0F3CCULL
        },
        {
            0x3E007E404127C576ULL, 0x0865C9CD86070E26ULL, 0x7A8DFCF3311622EEULL, 0x3C8B7602A2A9923BULL, 
            0xA74CD70EB79D9197ULL, 0x7C58E9F2279ECD0FULL, 0xEE6902C69BFBEE05ULL, 0xF84A87CBBD3D0D46ULL, 
            0x3B2B7000E9307B4DULL, 0xE378EF9D2BF609C6ULL, 0xE80785479A8EA794ULL, 0x70C17819EF168BADULL, 
            0xA4CDBB11588E682BULL, 0xB4B1B50BE7D8C2CAULL, 0x7E296A284C4E100DULL, 0x290FBE54436110CEULL, 
            0xEBAA2B2AE843B277ULL, 0x3575880D8A967797ULL, 0xFF0A5F4513C78046ULL, 0x1E90ACBFC1FD36DCULL, 
            0x4D3E1BD18E4BC7F1ULL, 0x6CD2150F6E32D303ULL, 0xE3798FE2807CC593ULL, 0x0C80B3AB7240FE4CULL, 
            0xBB198E8BB5389B51ULL, 0x15E27997DF188E4BULL, 0xCFC8A16863802A74ULL, 0x8DBEEA96E70E9745ULL, 
            0x64598843980D065CULL, 0x3634A8B8C7832885ULL, 0xBA5F53BF4317A90AULL, 0x856505EE59C442A2ULL
        },
        {
            0x6A1CB5C2EA5B73F8ULL, 0x8DF0B86C5D8FADE3ULL, 0xCD434E6BB9C23382ULL, 0xFA03BBFC8B9B4BA6ULL, 
            0xB8D275612E901760ULL, 0x40B1303C98E4FA55ULL, 0xD5E64633BEE38B03ULL, 0x25D76DF7C2939FF7ULL, 
            0x30A9A71FCF3F1D0DULL, 0x3EB1FB3580743B52ULL, 0x937E22BFCC50A5F4ULL, 0x6F573F7AAADD8B2CULL, 
            0xCEE1B260DCE343C7ULL, 0x2BEB3F2BFD84571EULL, 0x1704F786BB1DD69BULL, 0x1AC0B666413FF868ULL, 
            0x534126E87FD639B2ULL, 0x5AB9475262D72ECEULL, 0x4FB7AF6791029C5BULL, 0xA98F5CB45AD8D234ULL, 
            0x24CB3E2113C349E7ULL, 0x2B68177536662084ULL, 0x4327E2CBF5DEB350ULL, 0x081407C43845F26DULL, 
            0x99A671F898C7599BULL, 0xA4E6CE132CB2A821ULL, 0xF569D6D5570C2391ULL, 0x841BE48AE077731FULL, 
            0x1A7ECAE995570DD6ULL, 0xF79250732D63714CULL, 0x5203C6CE739DA6C9ULL, 0x0950BBC1C25054F1ULL
        },
        {
            0xF7B4D1D20D292956ULL, 0x7009EC799E87B7E9ULL, 0xF9BA89D3B299E252ULL, 0xBDEF735F9462BEF4ULL, 
            0xC064094098397460ULL, 0xF37C9CBDB60638FBULL, 0xB8D43E329ABDC8E9ULL, 0x32FB471B29785945ULL, 
            0xA0F577F522B6B15CULL, 0xBC8D33FA195443E0ULL, 0x7EF38F6D4D04AA8DULL, 0x800C80CAB9D2730BULL, 
            0x0BCD707429B016F0ULL, 0xC6A95160F7946129ULL, 0x3BE39B8342A3CB03ULL, 0xB89FA9BD0E8D28B1ULL, 
            0xBC5C03D57C0D7983ULL, 0xD63CCAB3CBDA58B5ULL, 0xD2349F5D4C573CFEULL, 0x3BF15A0FF4B341CEULL, 
            0x3352DF76F26085D7ULL, 0xCCA350E03654E009ULL, 0xF8041079264E6A55ULL, 0x18EC3BBE8B88243DULL, 
            0xB96AFC3A7B8DB625ULL, 0xB361B4EAFEA66947ULL, 0x059673B4B1B9669DULL, 0x05997E3D8251C8EAULL, 
            0xB92BD49858329894ULL, 0x306DC6937902DAE3ULL, 0xE79BCE762E8D0B67ULL, 0x91885420A28333A4ULL
        }
    },
    {
        {
            0x4A80FF6055F5615FULL, 0x4CE53CFFB433D071ULL, 0x9FCA34D276CDC35CULL, 0xB8F549886CA62B29ULL, 
            0x8E85413EB51D4283ULL, 0x440E3E775B56646BULL, 0x0FB85FFC6692109EULL, 0xB429AB532BB2E88EULL, 
            0x6BAAE4B1E9F0188DULL, 0x66CB43CE6A7AA034ULL, 0xEFD37E727E6912BBULL, 0xD2704BF422D0D6E5ULL, 
            0x882C06EEAEB24BB3ULL, 0xE6201516123462D8ULL, 0xB6FFEDD935428D90ULL, 0x5DE26AF911393C59ULL, 
            0x0B888A79881AED9AULL, 0x5C6C6ECBDA73391CULL, 0x6B340A8A1F02EB43ULL, 0xD0DA8EF1B6B7F13CULL, 
            0x60F46F676E5F5198ULL, 0x544F6238BE8EA4F5ULL, 0xF405204B34D92BB1ULL, 0x867F96613B66A8DDULL, 
            0xBD506660F4CD53ACULL, 0xD61C56773FFBBD27ULL, 0x1AFC6E4209C7C2F4ULL, 0x0FAD914162FF2C26ULL, 
            0xE70D42C739EC64D1ULL, 0x163E211BB06E62EEULL, 0xC10A118A615F9CEFULL, 0x9A66C8F13F168EF8ULL
        },
        {
            0x12E9568D951BF859ULL, 0x6C838D4F6D8C2E8DULL, 0x87E9E7CBF686C948ULL, 0x16094E6C041EEE66ULL, 
            0x0B232F1A9F522F2CULL, 0x96AC1C67E0180F1EULL, 0x6A6D11FB4BA908C9ULL, 0x89C4C0CE0E786527ULL, 
            0xDA5B844760533AC8ULL, 0x5C07CEFE9B221E43ULL, 0x81AEA64D792FCA2DULL, 0x9FBEB2143C04FF24ULL, 
            0x9D5D6FA4DBE78972ULL, 0xF26B808336A1C7AEULL, 0x196EFA19CC63CCBBULL, 0xDE7459CDABAC05ABULL, 
            0x59E869A6D439028CULL, 0xB0972475CBC98A49ULL, 0x49F093C2CA9E3771ULL, 0x932341573CC2FC01ULL, 
            0x8DD98F67EE9506BDULL, 0xDE8CB50440DF0B7CULL, 0x0C217A4CB52144F0ULL, 0xC1E267B76B45A6DEULL, 
            0x9BFBDE3291758BE2ULL, 0x576A5B95CDBE87FFULL, 0x4C304258DA4DFAE5ULL, 0x64701D5A6719CC21ULL, 
            0x72203737075B3C39ULL, 0xF7CA5299F1145C11ULL, 0xC90812ECA31686C0ULL, 0xB2291EFCCB3CED00ULL
        },
        {
            0x1DC5C07DDB215881ULL, 0x8D758FDCAB4CF9BDULL, 0x938E2A956772F571ULL, 0xD6488923E33E25C0ULL, 
            0xC4CA882DF1E9E902ULL, 0x6B93A0FE4BCFC8A7ULL, 0x1774C01866C0C9B0ULL, 0x3E875D2A5C206141ULL, 
            0x81C2F9F00CA73110ULL, 0x6B8754BB3F797D44ULL, 0x8CDE5E054D200DF9ULL, 0xCDF5FFCDFB9012E1ULL, 
            0x96C2C4D464E222FCULL, 0x82C8D6DBE3CF0A2BULL, 0x4A6FF068A9BAB1BEULL, 0x40BC1AB31595B182ULL, 
            0x889370F4E426029AULL, 0x7EBA5BC17087E374ULL, 0xCE3C6AC8B3B4EF1CULL, 0x1AFB382EB7AAF924ULL, 
            0x403B30737A0A6A34ULL, 0xB3F8D44F33D1946CULL, 0x4B5575D927FB046DULL, 0xD59A6C135D753317ULL, 
            0xD1C6B830EAFAC8F9ULL, 0x735E4A43FC89D02AULL, 0x5F278E814B0564CFULL, 0x10F62FC3F7C74BB7ULL, 
            0xB54D9888BD13C36CULL, 0xA1C6082AC3891C32ULL, 0x4B5ACAA1B23A2938ULL, 0x0936B2BAC7FD678CULL
        },
        {
            0x0DA92028DDC81076ULL, 0xD041B5BACAF0B6BAULL, 0xF4E3F03A93D12BC6ULL, 0xED904B43D33DA1BEULL, 
            0xC65967AE6A208644ULL, 0x6189D73657CDFD58ULL, 0xDED791D0EAA152D6ULL, 0x22EE54819E0E9910ULL, 
            0x1C44AA5CD3235440ULL, 0x7FECE56981BDE0EFULL, 0x4ED31E7E403A5613ULL, 0x41A8BFB9455BABB2ULL, 
            0x9470F298E0303E30ULL, 0x020789BC1B27AF78ULL, 0x9370750F9FB5DC2CULL, 0xCC184DFEEB26B62DULL, 
            0x93A1E1CA66BFE0EDULL, 0xD0BD7BE49D767A1BULL, 0xD29637608E7E30BCULL, 0x4D121485DB10348AULL, 
            0xABA2AF5D9733C81FULL, 0x1B7596AB8E1467E0ULL, 0x3D942FD19AE3F260ULL, 0x857A6FF28D868FE4ULL, 
            0xD87D8A336C3F910DULL, 0x0EA8B3D509AE0FECULL, 0x7511C0781E665161ULL, 0xC05317EEF5209D63ULL, 
            0xC397DFF9D3EFA140ULL, 0x690484784AC71821ULL, 0x295A0E6BDE347782ULL, 0xB304415D3E699326ULL
        },
        {
            0xE0DB66EF4DC7CA5CULL, 0xE2B8711C4366275EULL, 0xFE91FDB6F3FD3FD1ULL, 0xA6AC2B9BA0384B66ULL, 
            0x037697CE7C6871E4ULL, 0x74BE2F9FE12319ACULL, 0x1B4016E0245F435DULL, 0x4B82D001A04952E3ULL, 
            0xF1657F24BA726EE1ULL, 0xCD1D9415B7AF035EULL, 0x25CD2AC6C0537615ULL, 0x2EC2977495047C0FULL, 
            0x481270E5CDE83461ULL, 0xDF60FA403BFEAE58ULL, 0xF6AF36CF847C771CULL, 0x907D04438E476F53ULL, 
            0x58258C6C494FAEB3ULL, 0xF636B646522397A8ULL, 0xFAB313E10DB64D64ULL, 0x0B803F436A13C45DULL, 
            0x2957200A5EEAF95AULL, 0x2623BDDEB375254AULL, 0xB883E3D88C24D3C4ULL, 0x9257416BABCFF091ULL, 
            0xFD3DAE08B6057E73ULL, 0x290FFE74A87D22CDULL, 0x400B72585B29CD8BULL, 0x3DFAFC51FF5A7775ULL, 
            0x7792021450F6CA26ULL, 0xAF252832E485ECF7ULL, 0x33A6611E21EE526CULL, 0x149A705D5FC7DBFEULL
        },
        {
            0x6ACC6210FC123F3EULL, 0x29FB4E4CE32C2F69ULL, 0xA6D6766A33ADEB7CULL, 0xAA11D4020A8C8696ULL, 
            0xFAB685483E4B6880ULL, 0x1802A34F70BBBF55ULL, 0x17D788F2D04BD818ULL, 0x5D42759FC177241AULL, 
            0x6915C8998709BAE9ULL, 0xD550BFA5BE8F3560ULL, 0x7605948C912815C1ULL, 0x2482A7A9F74134B8ULL, 
            0x0BD620DFA537C643ULL, 0x8AE24E337A923B43ULL, 0x103D428185C08CB6ULL, 0x29185C2BA6B45A14ULL, 
            0x9E9EE104D6107F4DULL, 0xF209F1F8E5152F1FULL, 0x99802AA0F59F8B2EULL, 0x5A57983DFA3D7DC2ULL, 
            0x8C93473A09AC4B9FULL, 0x88D9259D178C7C21ULL, 0x20E25D0BFD66F2E4ULL, 0xACC42B88B4822EFAULL, 
            0x2E4503213628E0D3ULL, 0xF546B7DC60DF2D4CULL, 0x05A1A8A0A68B4BE1ULL, 0x14DF13B9D871E664ULL, 
            0x8588FFAF31E2B2D1ULL, 0x1FFF1B0AFE55C6EBULL, 0xA2A4DE77F9FD7EB0ULL, 0xDAC6158C4A3B9611ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Golf::kPhaseHConstants = {
    0x8B78DF8E51EE8E9BULL,
    0xCE06D24C3ED7E623ULL,
    0xC34476651DAAC4E0ULL,
    0x8B78DF8E51EE8E9BULL,
    0xCE06D24C3ED7E623ULL,
    0xC34476651DAAC4E0ULL,
    0x899B8DC73179CD0DULL,
    0xB66E037B369EF4BEULL,
    0x8B,
    0xD9,
    0xED,
    0xAC,
    0x8D,
    0xF1,
    0x75,
    0x06
};

