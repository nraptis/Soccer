#include "TwistExpander_Archery.hpp"
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

TwistExpander_Archery::TwistExpander_Archery()
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

void TwistExpander_Archery::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 9937336174470761442U;
        aCarry = 13399215774544862333U;
        aWandererA = 12558171136169635797U;
        aWandererB = 15496484827500906266U;
        aWandererC = 17292738182856575604U;
        aWandererD = 11397043098390856690U;
        aWandererE = 10955041905813204470U;
        aWandererF = 13656184508981935602U;
        aWandererG = 10875915042188981515U;
        aWandererH = 15087436725939721698U;
        aWandererI = 9799393452980951362U;
        aWandererJ = 16322389115207834578U;
        aWandererK = 15938810799739219708U;
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
    TwistExpander_Archery_Arx aArx;
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
    TwistExpander_Archery_Arx aKDF_A_BArx;
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
    TwistExpander_Archery_Arx aKDF_A_CArx;
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
    TwistExpander_Archery_Arx aKDF_A_DArx;
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

void TwistExpander_Archery::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 15232308486642442234U;
        aCarry = 11896769216909522639U;
        aWandererA = 9498110238293717130U;
        aWandererB = 18010469979855920957U;
        aWandererC = 11810734794378008756U;
        aWandererD = 17810315856687375746U;
        aWandererE = 9973389196062167448U;
        aWandererF = 10346324993071109382U;
        aWandererG = 11585858348745805110U;
        aWandererH = 13585879752391323239U;
        aWandererI = 17625649265217553866U;
        aWandererJ = 14297833424833959808U;
        aWandererK = 10040099283167519307U;
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
    TwistExpander_Archery_Arx aKDF_B_AArx;
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
    TwistExpander_Archery_Arx aKDF_B_BArx;
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
    TwistExpander_Archery_Arx aKDF_B_CArx;
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

void TwistExpander_Archery::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneF (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseA invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    }
    // KDF_B PhaseB invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneG (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneG);
    }
    // KDF_B PhaseC invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneH);
    }
    // KDF_B PhaseD invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneD);
    }
    // KDF_B PhaseE invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    }
    // KDF_B PhaseF invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    }
    // KDF_B PhaseG invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneC (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    }
    // KDF_B PhaseH invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_Archery_Arx aSeed_AArx;
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
    TwistExpander_Archery_Arx aSeed_BArx;
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
    TwistExpander_Archery_Arx aSeed_CArx;
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
    TwistExpander_Archery_Arx aSeed_DArx;
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
    TwistExpander_Archery_Arx aSeed_EArx;
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
    TwistExpander_Archery_Arx aSeed_FArx;
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
    TwistExpander_Archery_Arx aSeed_GArx;
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
    TwistExpander_Archery_Arx aGrow_AArx;
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
    TwistExpander_Archery_Arx aGrow_BArx;
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

void TwistExpander_Archery::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Archery::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Archery_Arx aTwist_AArx;
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
    TwistExpander_Archery_Arx aTwist_BArx;
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
    TwistExpander_Archery_Arx aTwist_CArx;
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
    TwistExpander_Archery_Arx aTwist_DArx;
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
        TwistExpander_Archery_Arx aGrow_AArx;
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
        TwistExpander_Archery_Arx aGrow_BArx;
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

void TwistExpander_Archery::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 1, 3 with offsets 2178U, 2020U, 4269U, 592U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2178U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2020U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4269U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 592U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 2, 0 with offsets 400U, 4306U, 6159U, 3201U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 400U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4306U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6159U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3201U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 3, 2 with offsets 2666U, 5423U, 4846U, 7208U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2666U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5423U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4846U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7208U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 0, 1 with offsets 1369U, 7752U, 5732U, 4020U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1369U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7752U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5732U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4020U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 0, 2 with offsets 690U, 859U, 1440U, 499U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1440U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 499U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 0, 3, 1 with offsets 1659U, 646U, 921U, 1731U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1659U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 921U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1731U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 1, 3, 2 with offsets 1448U, 1529U, 807U, 1090U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1448U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1529U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 807U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1090U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 1, 0 with offsets 1540U, 1813U, 87U, 1712U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1540U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 87U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1712U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 655U, 1367U, 1553U, 1238U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1367U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1553U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1238U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Archery::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 3 with offsets 7274U, 6025U, 1902U, 7783U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7274U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6025U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1902U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7783U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 0 with offsets 6178U, 2766U, 4292U, 392U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6178U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2766U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4292U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 392U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 1 with offsets 684U, 1323U, 7538U, 7253U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 684U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1323U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7538U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7253U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 3, 2 with offsets 2273U, 3227U, 5277U, 2015U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2273U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3227U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5277U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2015U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6837U, 1950U, 6481U, 5675U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6837U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1950U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6481U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5675U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 3, 0, 2 with offsets 1697U, 2005U, 393U, 965U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1697U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 393U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 965U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 0, 2, 3 with offsets 82U, 919U, 1908U, 1123U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 82U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 919U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1908U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1123U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 1, 0, 2 with offsets 1461U, 732U, 534U, 1506U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1461U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 732U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 534U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1506U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 1, 2, 3 with offsets 962U, 695U, 20U, 1500U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 962U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 695U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 20U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1500U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1937U, 756U, 1923U, 1496U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1937U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 756U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1923U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1496U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Archery::kPhaseASalts = {
    {
        {
            0xCF22340284208697ULL, 0x720CCB869236B7D2ULL, 0x0249A0D9B0FA0921ULL, 0xCCBDB46BA68DA2E6ULL, 
            0x0C19AC26A191C612ULL, 0x8A7FB1E38F2EA97FULL, 0x65BFC55D3C6C3729ULL, 0xD6526FA6063B8575ULL, 
            0x9EE77336B88AB0E5ULL, 0xD2EBF4F3A53BDAB7ULL, 0x86B2559DC5C40CABULL, 0x41171321D23A8BB9ULL, 
            0x184642E5EBA6EF2AULL, 0x370A80772FD595A3ULL, 0x14938B0AC94CAA98ULL, 0x8095F5FF12D56C36ULL, 
            0x0760304C7303E0A4ULL, 0xDC62ED93B634A9CCULL, 0xFA1F85E31DBF0A56ULL, 0xF9EF360DBB0E7140ULL, 
            0xCCC8CD144B537D93ULL, 0xEA96D39BB153150CULL, 0xDB731C9B1E5915ABULL, 0xA153D0A5740B7D69ULL, 
            0x57B0EB13295BDF33ULL, 0xFC9A1FBB2E7567E7ULL, 0x3DADCB14650FC3EEULL, 0xE0048AC2B6A0381AULL, 
            0x3DA4CEE4DCA33E65ULL, 0xFB4E1850F2069882ULL, 0x635C09815BFEA302ULL, 0xFF89F3550CF449BBULL
        },
        {
            0xF79583A4A6C00362ULL, 0x330DE91D19E0F344ULL, 0x0AC842F79DF071BBULL, 0xE9D21093FBD91DA3ULL, 
            0xB39F4839FC6ABBA3ULL, 0x169312AFF4B892AFULL, 0xA335EB094A82D9CBULL, 0x70CD072730C7A7CEULL, 
            0x8CA13E4B98AEACD9ULL, 0xCCF1BDCC8ADFE6F2ULL, 0x44012944A9EFF4F4ULL, 0x38109E1CA8CF8F50ULL, 
            0x9CC1F242C66E353FULL, 0xDBC7368DA178C21FULL, 0x21ADFEFDB6C6E3F2ULL, 0xAADDE4B9EAE50C5AULL, 
            0x7BA266C74E942B2DULL, 0x22D008DCAFCA19A6ULL, 0x4C82C43A301F4C6FULL, 0x0C938B2C81805259ULL, 
            0x3D6A1DB43D401EF4ULL, 0x3D543988F4011DAAULL, 0x1FDFFAFE6B4F2F99ULL, 0x40498D956EE285F8ULL, 
            0x04FBD7A87DBC7560ULL, 0xCD30DFC3D16CCFB5ULL, 0x11C364FDADB2B5DCULL, 0x129CA0392A068784ULL, 
            0x71F448A259197073ULL, 0x1D6A64CDD82E80B2ULL, 0x2297691A53213011ULL, 0xC5CB5D43F0325564ULL
        },
        {
            0xA54169C78D5FC275ULL, 0x302D4D75C8F12F4AULL, 0xD07C6DAD8B0F13CCULL, 0x1FC7355F50491B91ULL, 
            0xF48C917E9DF9F0FBULL, 0xF725C5084D1D6CDDULL, 0x74159877F527AB71ULL, 0x235485C01B9FFFB2ULL, 
            0x56219F821DE8C654ULL, 0xBF626A7B374DE067ULL, 0x144C655EEACD1235ULL, 0xF39EEF5BE95A2D93ULL, 
            0x7ADDCA524F25408BULL, 0xF965EF6A4737A68FULL, 0x6365096DAE3D4BEFULL, 0x2FB2D075A097068EULL, 
            0xD42836A794E07667ULL, 0x4A34E25EBC310A9EULL, 0xFFAAD5CB2A8E3276ULL, 0xC8C4B5A212FDADA3ULL, 
            0xACB6E84538FCE8B1ULL, 0xF9F36E32B0382723ULL, 0xD17794C2EDBD04CEULL, 0xB88C0AF305CB1155ULL, 
            0x455D36E1F3B7F90FULL, 0xB543E11B42537E9EULL, 0x7BD157F2F3AA4BBDULL, 0xA95EE809E4909C26ULL, 
            0x3B048299AFF4A2F5ULL, 0xC57735D15EB8DB49ULL, 0x7D916971EC308AFFULL, 0x6F795B7BB3F4412BULL
        },
        {
            0x2ADA30E9A66C80EAULL, 0xA96E7156F3496225ULL, 0x617EA3267800C0C1ULL, 0x057B635EA2173E27ULL, 
            0x130C73CBFE38CC62ULL, 0x55922CF353ECAEE3ULL, 0x2F9F5621285656F4ULL, 0x2CCFB053402E1AB5ULL, 
            0x4FCDAC2F6B5BA1DCULL, 0x69AC35450CA7D85DULL, 0xA18E67FD3218A2D2ULL, 0xD3F4C175D5078918ULL, 
            0xD8E92FDFBFD6F6BEULL, 0x0E57C77C894810D4ULL, 0xA24A35FF0A71C650ULL, 0x6E52D2C9E5406C43ULL, 
            0x27B2856DCA28E43DULL, 0x312B41F8B6EFCE9EULL, 0xC269252E4FA0B8C9ULL, 0x167A1052F2B5F644ULL, 
            0x7E8D48D85610A784ULL, 0x74E6E0BB47B3A956ULL, 0x94832B6F17A32112ULL, 0x724F524792AA01CCULL, 
            0xCBF454226A1F4C49ULL, 0x97A0BB809616F639ULL, 0xFAF7B81D0B80385DULL, 0x1315CD54085EEFD8ULL, 
            0x2785FF5E25303AE0ULL, 0x6CAA7B4090F1521EULL, 0xD7E02B60EFD4B0EFULL, 0x641256D214A137CAULL
        },
        {
            0xF6EDE7818D742093ULL, 0xFB818807DF14C22DULL, 0xB85B2937CA40B2F7ULL, 0xFAF1449947F34D10ULL, 
            0xE930A862A98ECA16ULL, 0xA5598E634051CC6BULL, 0xF46C2B5355CA69FCULL, 0x97A2808ADF0A7137ULL, 
            0xE698BA8D1A054B2FULL, 0xF946B93E2F15E8B5ULL, 0xB56CD22233189252ULL, 0xFE7A7F47C403BCF2ULL, 
            0x9AD3C56A061A11F1ULL, 0x3AB4D64729336063ULL, 0x4D1B6165A2C13985ULL, 0xC067F63DFBB53446ULL, 
            0x65D80AAD0415A0ECULL, 0x4EF93C8CAA3C434DULL, 0x2789940B1DFC0AE0ULL, 0x08B141770D739467ULL, 
            0x4FF073E4B4F3CB20ULL, 0x0D3D534C6643B4CCULL, 0x52A305446C610CF6ULL, 0x63AFAAA639FE1461ULL, 
            0x7D98C5A5BEEC8AA6ULL, 0xFAC0417B25FBA2C3ULL, 0x5E99E3C5176D144CULL, 0x1129E76DF6110915ULL, 
            0x827D7E2E13E0B873ULL, 0x8987C96A104F008DULL, 0x172FEE4C5A497072ULL, 0xD1BD2ED9DD16B9BBULL
        },
        {
            0x72FFA2799B334383ULL, 0xE0A23A7813BAF42CULL, 0x7994E511172764CEULL, 0xC9EBC16227670D26ULL, 
            0xCD099170C1DC47A7ULL, 0x94CD2ED7442744EEULL, 0x47C13BD6969631B0ULL, 0x94DAACEE3CF7B4D6ULL, 
            0x3E0B62D05EDA9074ULL, 0xFD1777FBF53F472CULL, 0xCDD9D9FA01FC0C5BULL, 0xC3347C713C379F94ULL, 
            0x6A19096E29D3C605ULL, 0x373CA7452498CA88ULL, 0x28DFF1105C8F8CA5ULL, 0xB05B134492F78D54ULL, 
            0x359DBCA3EFB1B831ULL, 0xAF39396C516C1F8FULL, 0x0A4299A933973613ULL, 0xA57D77D64F1A7C64ULL, 
            0xAE2E6ED544737151ULL, 0x6C4103D901402B8BULL, 0x804C0CD916F87264ULL, 0x5A1EAF9FB885265AULL, 
            0x4B3D9D9A755BC8D3ULL, 0xB0E17CA31C5964B7ULL, 0x4E59D2B7C9928A75ULL, 0x5BA7BEB0FF2398B0ULL, 
            0xEFEC529435AC1BF9ULL, 0xAD0FCFF920131A5CULL, 0x4AE5A8608581B975ULL, 0x1675CB1B45058B5CULL
        }
    },
    {
        {
            0x56310DCE9808C871ULL, 0x9BFD0C731A700967ULL, 0x45E4E4999B1D61E9ULL, 0x3B1608E33A08D74CULL, 
            0x921AB0FDBF42C7D8ULL, 0xE9D7028FD7A40971ULL, 0x20CEAE2744C1F1CCULL, 0x12B1127EE3F5C2A7ULL, 
            0xC8F08E87D04658D1ULL, 0x5B550A85FBBFC065ULL, 0xF6FA3EDDD2214DF0ULL, 0x67EEDE80E4D69208ULL, 
            0x2FF0E46EA5164CDDULL, 0x6AF8A834A729EF05ULL, 0x49A1CD412F25C896ULL, 0x9BEE2D6BD436F836ULL, 
            0x64FDF091D7757FA1ULL, 0x7C0AD5FC45E479B9ULL, 0xB6A8736EEDF12378ULL, 0x0F8FF91960E93C75ULL, 
            0x0EF2CB7E934E8454ULL, 0xEDE6E9A2C3214F90ULL, 0x6F6AA6C4923436D8ULL, 0x9DF67BB7BF2C0358ULL, 
            0x17E45F2B7C1C9F74ULL, 0x5F9AD64D549D85C9ULL, 0xF176B551BC304BFEULL, 0xE1A3E2A88D0AEBE4ULL, 
            0x4144B948F4110715ULL, 0x9A5936D3E591068DULL, 0x990F5BA80AD6209FULL, 0xBF012A0C025CAF22ULL
        },
        {
            0xF9DFB5CB6BE0576EULL, 0xB3639E803A213A80ULL, 0x599FA58810418273ULL, 0xEF8F7693F24DF87BULL, 
            0xFCF8D012A2E73D25ULL, 0xB0D9DB48CD96874CULL, 0x9DB91D6602B463A6ULL, 0x42E619876D3FF83BULL, 
            0x933BF0A67206726EULL, 0xA6E3BCCB05916031ULL, 0x0673E5741884A45DULL, 0x57F1FDB44E5ABF03ULL, 
            0xCAF1AD1C281C4C1EULL, 0x73657EF7107899CBULL, 0xC0519863D7B19472ULL, 0x6964EB92098143C3ULL, 
            0x4C73552F90984913ULL, 0x8C6FE0FCDD08CF6DULL, 0x30487D2756538DC2ULL, 0x64C2831ED12E91C6ULL, 
            0x9182665718C1FBEFULL, 0xB3F96A86E89EDF7AULL, 0xF5E4E087EB68155AULL, 0x0010D395A6272711ULL, 
            0xE3D8D78D349293CAULL, 0x91901A8FDD8A0D5AULL, 0x9B37C36F7B570EEEULL, 0xEF3DC5AF3E3CE65FULL, 
            0xD4518887FE5359D6ULL, 0xFDAACFDE6DEB01EEULL, 0x49292A8DF39F5EB2ULL, 0x783211D23F0945AAULL
        },
        {
            0xC24E21A39F6B7D32ULL, 0xE6964E7FA9F973DDULL, 0x49856863DE179C41ULL, 0x53CE8114DEC6FDD6ULL, 
            0x4F668AD37EA44E26ULL, 0x3809BE69FA167EA9ULL, 0xA0E9AFF7E7365970ULL, 0x3F2E691AF4BA8E71ULL, 
            0x6D8F2951BC768A6EULL, 0xC8C94E7BAE5D3172ULL, 0x266130377575B29BULL, 0xFE1B599598FD9DC9ULL, 
            0x3282B1B2C49ACB0BULL, 0xC0AB435442F854DAULL, 0xAB5464F033755415ULL, 0x322D0DC0C95F675EULL, 
            0x04CF1E442B5C34B7ULL, 0x287288A8FE141033ULL, 0x6B807957F2AEBB48ULL, 0x957190354E4C3811ULL, 
            0xE0DB6538FD9CA05CULL, 0x550C173557F4151BULL, 0x0D748FCB87EC0FF5ULL, 0x226AFDFACFFF5F1EULL, 
            0xEE37CB8C14C1D5F3ULL, 0xEBA9F061ADCBD14DULL, 0x7549F13C577A9A51ULL, 0xAED2DB17C4C65595ULL, 
            0x4C2F0CB4097A4E52ULL, 0x52AF735827EF916BULL, 0x9E1BFCEA9A9499BBULL, 0x9841042B684E8EB2ULL
        },
        {
            0x6248F1759538F7D6ULL, 0xE2ACC65E8A4E05F4ULL, 0x8BAE759D174B908AULL, 0xD9EE0FC224551172ULL, 
            0x28A1E0813ABF8065ULL, 0xC4CF3F81EAEE02ADULL, 0x5ACB28D213F6116BULL, 0x0B5A269734757B99ULL, 
            0xECD33695937F6521ULL, 0xDA49840AEECAF708ULL, 0x0CCF6A86E349396CULL, 0xC169004C2320FFE1ULL, 
            0xB165BAB0B9ECACF8ULL, 0x338F645648B62F81ULL, 0xB499774D5CA3669DULL, 0x90752A0204DF0F1EULL, 
            0xC556C57C2BD9A8ACULL, 0x27036DC0EFAA9D64ULL, 0xD83870CCFC3704ADULL, 0x7820B75F5AF0D869ULL, 
            0xE2FDFEEEB4D05895ULL, 0x6DEFA9B6F236779BULL, 0x137FD0A9698079DEULL, 0x76AF1A37EBE2DF62ULL, 
            0xE4D36DAB12C8B0AAULL, 0x867E720673C7682DULL, 0x83ADF7C97B6265EDULL, 0x07A6BB0028720CA3ULL, 
            0x6603E69853B7DC70ULL, 0x8EEACBAEEDDE6A9FULL, 0x092262BBE7D0ACEAULL, 0x908587BEDEA2E661ULL
        },
        {
            0x682C9E7995801095ULL, 0xB882EDD8D38C9C41ULL, 0x065E1662727E7F6BULL, 0x4D56ECC5B878F01CULL, 
            0x1129B89833004C23ULL, 0x2166A25F99331B0BULL, 0x6CD709CEA75AE511ULL, 0x21F4F1A2E9F6E567ULL, 
            0xD0203B207FCC8A79ULL, 0x7C6D6470DE2ADF92ULL, 0xFA1EB7948EA3CA6AULL, 0x56F8FBB6F85F0B1EULL, 
            0x406457A6DEAAD9DBULL, 0xD7AAE2C59D36B18CULL, 0x600C3C9AF3424BD8ULL, 0x8ED69CEB885285ABULL, 
            0xE563F0D114724E17ULL, 0xD85B91343181A78FULL, 0xA7ED3DD3E8C710E4ULL, 0x97F99D3F6CF6F198ULL, 
            0xA7692017D1DD1DB3ULL, 0xA285C6AD50A3E76EULL, 0x2E026099EC21C6A8ULL, 0x42301CE2AA697700ULL, 
            0xEDE0B613388035A5ULL, 0x0977EA7DC44B05E7ULL, 0xFBD73112933D75D0ULL, 0xF57A69F5CB9FB068ULL, 
            0xB670B36766DE2D9DULL, 0x17DD5EA254853168ULL, 0x4136D91906859AA8ULL, 0xB7ACC103D2EEF28CULL
        },
        {
            0x0D5B933445C21EA7ULL, 0x866FD3629DE83B47ULL, 0x5B4AC6218A84A3AFULL, 0xB32C6B577CE37900ULL, 
            0xCFB3C60DA35D8795ULL, 0xD41213D90AC14CCCULL, 0xDEBB27CC5CBEAB8FULL, 0x47A6F6878E4FC9DCULL, 
            0x9FB350D99C58DCF3ULL, 0x7F99D3C67F228231ULL, 0xE0B84E6805B44EF1ULL, 0x4EE854C0020F9D52ULL, 
            0xE66AC2EA977C0D3FULL, 0xC576FECA07D05807ULL, 0xC580F832F8911360ULL, 0x50B26E09EB3AB062ULL, 
            0x47E3C7DF39D1E946ULL, 0x4F058BB6EDF651C3ULL, 0xF8B993C1CB2E6F7CULL, 0xDB83B848E6B1B004ULL, 
            0x1DA84BC238346099ULL, 0x4439380F84CDA7CCULL, 0xF356E5EA267B4768ULL, 0x8F6D9A87202E6A45ULL, 
            0xEDB0E75D7241856EULL, 0xB91FB18CD6ABA6B2ULL, 0x1DB10DDFAD7ED975ULL, 0x710D33D45A5F7512ULL, 
            0xBA44E278A90C8DE4ULL, 0xCFDBE89CA8924DD3ULL, 0x584F16544B033122ULL, 0x4533F1B63BE2C8FAULL
        }
    },
    {
        {
            0x154EDB5529C1F319ULL, 0x8A84E9A62EBE90A0ULL, 0x2A240BB5B260CB10ULL, 0xA5217A96463E396BULL, 
            0x6BF6505020558DCFULL, 0x8D6F94274A36388DULL, 0xDAE955939001324DULL, 0x2A2A5BA87DC0F444ULL, 
            0x56686735C2DFA8F5ULL, 0x489DB161FF21A80EULL, 0x1EE8FE7BDE060ED0ULL, 0xF8C8835AA576D5F9ULL, 
            0x159D625EA159D418ULL, 0xC88DA9420186420CULL, 0xF502880F24DCC6B7ULL, 0xF9EA23BD91DE3B32ULL, 
            0x66856303B877DB62ULL, 0xF294AC4018D82EF2ULL, 0x53FF9DAC485776D7ULL, 0x4E6E69EFEDAA798AULL, 
            0x1FAEED0810A3A7A6ULL, 0x198C393E5946BF6FULL, 0x48071C479321C57BULL, 0xB63E1332BB9F5B76ULL, 
            0xEEF0C8993E43C103ULL, 0xF6F521933B96822EULL, 0x02C3C736E84A6698ULL, 0x1F99D2A02F157F9BULL, 
            0x49BE638E72171AA9ULL, 0x2100CCCF98D8264DULL, 0x7ADB1548779F947FULL, 0xDEE6A092BED9012CULL
        },
        {
            0x47E8DADD0DDBCA3FULL, 0xFEAF1D4C4AA8705BULL, 0x11DFAEC4970A4F28ULL, 0xFDD9C0928FD226BDULL, 
            0xCA539AF3640C96E7ULL, 0xF1109BD2E41CFCCCULL, 0x191C77B8E3D265F9ULL, 0x10E3C32BF007334CULL, 
            0xA9C641EEA31443F3ULL, 0x0B1893183359472DULL, 0x38C7F3FB2C5F8A0AULL, 0xD061ED68EE6446CFULL, 
            0xCF790B6702BF54BBULL, 0x497B321266D94F23ULL, 0xA2C2013AB6D777F9ULL, 0x7D47EE5212C1F7D5ULL, 
            0x4E7AB995A07DD666ULL, 0x94977032356EBA6AULL, 0xA3E040C071DD61E3ULL, 0x23117D674A108D0DULL, 
            0xE1CBC92BA9CDD91BULL, 0x240BA68B4D1528F1ULL, 0x6CC3DFCE63C3DCA9ULL, 0x2110B88D666323A4ULL, 
            0x54CD6B38A78FB247ULL, 0x6E798A1FE21F5DFCULL, 0xCF7AA2021DCCA1DFULL, 0x982D895126B194DDULL, 
            0x7CA9DF98C491910DULL, 0x6C5F19EB5776A214ULL, 0x48639A594FFCF1C7ULL, 0xA1E1AFC971D12BA1ULL
        },
        {
            0x00B68424DE0EA12BULL, 0x94DE317893093957ULL, 0x69CFABC543A919BEULL, 0x20F4C4F67525A6DDULL, 
            0x35359088598418F8ULL, 0xCB83DBE12C07213DULL, 0xF477B256D75D1734ULL, 0xCD6412C336F89F50ULL, 
            0x6B160F4D5BAF9626ULL, 0x17540ECC97579B56ULL, 0x245D4FAC577E2B86ULL, 0xB119315398DB405CULL, 
            0x974AAD6087C3AD9EULL, 0xB6ECBD771E66A973ULL, 0x6CDE905077667C90ULL, 0x9760603B8FA6C4F4ULL, 
            0xB0AD00D41690D0DDULL, 0xF46732D176021652ULL, 0xD79126F9DA0A487EULL, 0x66199D66E510CEA6ULL, 
            0x99A0E056038BDBC4ULL, 0x428983DEC1638061ULL, 0xE4FCF311C61C69C9ULL, 0x5B33C9A8CE4F115EULL, 
            0xCC3E40A6F15FDBB8ULL, 0x9DACE6A955159E17ULL, 0x23EF584BFEA5E58BULL, 0x4C45D60B0C0BE430ULL, 
            0x8D88D1C22DFF8245ULL, 0x2DCE709FE955EF69ULL, 0x2AE24BA86D64DE21ULL, 0x1527D889E8467E0AULL
        },
        {
            0x0D8182C9BC4F84A2ULL, 0x283A68B6E9DC617AULL, 0x94A210C62FABE3F4ULL, 0xF9A69E875D96239DULL, 
            0x7C0882616A13D4CCULL, 0xE1D0E368C70482C4ULL, 0x7F794334DEAF52AAULL, 0xAA96CB2BB4AACD57ULL, 
            0xC53442D9404CB83CULL, 0x66A053DD2C3A786CULL, 0x7E1ECFA481D52A75ULL, 0x87AFB334E40E3C3CULL, 
            0x2A2E5BEE5C1258F6ULL, 0xC06C3943722C55DCULL, 0xC5914C7D0A2C2556ULL, 0xDABC9E6B0A16212FULL, 
            0xA354DD09F2A4514BULL, 0x67B213B9ACDC76F0ULL, 0x21F6717752AC4454ULL, 0x3E3496594D092C1EULL, 
            0x687325B1977004A2ULL, 0x6207BF7AE3929ED8ULL, 0x847E54F1FB282822ULL, 0x950AC6930FD60514ULL, 
            0x24BD1BDA5B83DD14ULL, 0x3CF4D7B3CC71E367ULL, 0x133FE40D1EE09139ULL, 0x7961B0C927A3E1A2ULL, 
            0xFF3312D425A21769ULL, 0xEE5081E423AB07F4ULL, 0x808C57719DEF1C06ULL, 0xD9663E7FFCF633EAULL
        },
        {
            0xBC0F8B08A5F1CB3EULL, 0x04A85468462A3052ULL, 0x58F6834ECBCD26F2ULL, 0xD95CA1B9AAD372DAULL, 
            0x4F070ADC50319E21ULL, 0x0D7747B823CF0EADULL, 0xA65C4DDAE9F97096ULL, 0x7A140615F65AC035ULL, 
            0x4C0BD879891C5A0DULL, 0x828FF63E2761F391ULL, 0x06EA5513248D6DB6ULL, 0x7EE1199E8B94676AULL, 
            0x201BCFD94316F83DULL, 0x69C86DA1551A1D1BULL, 0xEED02A2B7A69DA1EULL, 0xC19FC22BA2920F12ULL, 
            0xB12BE638BBF97C98ULL, 0xEABEB90A27D30E02ULL, 0x7F121CAD6B7A1B7AULL, 0xAEF6A0D6396A9A55ULL, 
            0xCDBA4B5CF2826315ULL, 0xCA80DA8DB48C7CDBULL, 0xCFDD09932BA499BFULL, 0x33D3788B9FAD4FFFULL, 
            0x722F8DF4B18737C3ULL, 0xB146CA889EB92F15ULL, 0x9DB3BCD369CF7957ULL, 0xC5608F60EFF9FB3DULL, 
            0x3FD9E86B393779B4ULL, 0xDDBED5229AB879C9ULL, 0x10D783AA13749168ULL, 0x510DEC262EE3F4AAULL
        },
        {
            0xA6057D5BE9E013CAULL, 0x4096AF5CE26C5BC3ULL, 0xD8C3ABA985028F57ULL, 0x06720BCD80CBCF5CULL, 
            0x82CC9CA59503AE90ULL, 0x3C7B8BF792AF5536ULL, 0xEA6E5C90332B78E4ULL, 0xD2E4AD93A21E97B9ULL, 
            0xA3965D42008123C5ULL, 0x152F0A18759925FDULL, 0x8DF032B458ABC2A7ULL, 0xF761C0C7237E88F2ULL, 
            0x8407D6E7E31C3D56ULL, 0x0A2D5195F84D9D99ULL, 0x1D574D343F08E831ULL, 0x879CD4139A0BC63CULL, 
            0x6B2812E26331E39EULL, 0x6018A273C57A1210ULL, 0x5D90681246EE5E4AULL, 0x3E35DCB46451EFE5ULL, 
            0x06A9E187D37C433FULL, 0xA1C3F09EAAE79E9AULL, 0x5116219A558BFEA5ULL, 0xD8B58C8E4899DACCULL, 
            0x7D99FF813EF2A1FBULL, 0x2725E971ABCEE270ULL, 0x1B23633DF9F7DB94ULL, 0x201F1AF243999202ULL, 
            0xF691EADF9249F521ULL, 0xE2609F178E83AE99ULL, 0x7B026DF11500058AULL, 0xA971ABC5A99AFC6EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseAConstants = {
    0x7E81422947CE3D9EULL,
    0x895E163671DD6299ULL,
    0x6BF98594C09D2E9FULL,
    0x7E81422947CE3D9EULL,
    0x895E163671DD6299ULL,
    0x6BF98594C09D2E9FULL,
    0xA4E121678DC6533BULL,
    0xE2901A66E71DE131ULL,
    0x7C,
    0xDC,
    0x2B,
    0xE6,
    0x69,
    0x97,
    0xE9,
    0x01
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseBSalts = {
    {
        {
            0x81460A0801FF2642ULL, 0x033EB7F97D547CAAULL, 0x9A7DDA354B42F5EBULL, 0xAAAD0C6B7127A8D5ULL, 
            0x33FFB8D7A40FFCE6ULL, 0x81B9253BDF61DF98ULL, 0x83F9F1C7E5732C88ULL, 0x514D10153DF201DBULL, 
            0xC01C397DF5C6B642ULL, 0x722EFCF1072860D0ULL, 0x5AF10199AB6914AEULL, 0xE7B47A22CCF060CBULL, 
            0xE1FC7CCA61118188ULL, 0xD9E56A7C0D2E95EBULL, 0x982DC0AEE50363EBULL, 0xFB5F55AD2E78D0F6ULL, 
            0xCD1BB80103872FB8ULL, 0x0ABAF5CC6C6B1F44ULL, 0x7E538EA38E66DFB1ULL, 0xF291742B33A7C92FULL, 
            0x1F77B57B1608D017ULL, 0x905FA5461C19BA5BULL, 0xD2AC940C4DCAA5DBULL, 0x9C1835A6C9C97BB5ULL, 
            0x8D7C2EF9829EFEC1ULL, 0x6177C895506807B0ULL, 0xA9198E1F53C315C8ULL, 0xC3D9918A73D12972ULL, 
            0xC92D9F72F82A9760ULL, 0xCBB17B292BC93900ULL, 0x9B68D400E153CAA8ULL, 0xC587B0A1F6CC5F4DULL
        },
        {
            0xDB324438530F3211ULL, 0x4B452721D6FD24CFULL, 0x4FC38A5537E7FFFBULL, 0xE86F0E581F72425BULL, 
            0xDA4564AC801D0E3AULL, 0x9F3D2F59DDCDE716ULL, 0x55581B7199608B72ULL, 0x5792DF550087774AULL, 
            0x301CBC30BA3C5654ULL, 0xF5C9580874B24AF6ULL, 0x542956D7CDB07418ULL, 0x312D06F721D07126ULL, 
            0x392E9FB36B706100ULL, 0xD453862FBB996EB6ULL, 0xA536A8A42EF18845ULL, 0xE459FA3C801FCEBBULL, 
            0xE145BA241F522E02ULL, 0x8F9EF4209E318D6EULL, 0x6AD37806A712F638ULL, 0x8D71898A50E61EBCULL, 
            0xEDA7EA023E85A3B5ULL, 0x7C525F812B453877ULL, 0x38F554FCB3DB3CAFULL, 0x0A17EE669B4B8116ULL, 
            0x3562B2D0123CF234ULL, 0x877DD714DF64D7CEULL, 0xC8DF12250B50CD39ULL, 0x4E2DC087B83A35A4ULL, 
            0x135FF461B9F2E358ULL, 0x00E736B937AD7B08ULL, 0xF5A983BCFF6CEB37ULL, 0xC103453A23361185ULL
        },
        {
            0x19E395EE14074F04ULL, 0x48B920CBBA8319C7ULL, 0x4581188B0E50D3D5ULL, 0xCDED0F1F1104F7CCULL, 
            0x309B18FAD30F5BDAULL, 0x2AF34AC112D39662ULL, 0x30C757270A0735D6ULL, 0x46A33C2A97D54F75ULL, 
            0x394F8D04A6924E2EULL, 0x546430903D27490AULL, 0x3AC5B00552D972E2ULL, 0x723DD717984939D9ULL, 
            0x316A29415566A015ULL, 0x81730D108FF63FC8ULL, 0x758513F152714C11ULL, 0x9343075C34D7FE78ULL, 
            0xD4E19DEB8F0ED147ULL, 0x9A1E729D5A2E5B58ULL, 0x509CCA25E9CE92ECULL, 0xEA4296375CFC4113ULL, 
            0x1C7C60F0C2C2560DULL, 0x4259EC4C01DD0A39ULL, 0x741BA2C37D217C26ULL, 0xB50CD767EE5633C1ULL, 
            0x232C7165102A38A7ULL, 0x2C004A11AA72ECC5ULL, 0x0B0841099C44077FULL, 0xEB19CFB81E4C0D3DULL, 
            0x7888158FCE4F346EULL, 0x230E498ACD19775FULL, 0xD8369B25AA23D466ULL, 0x8BB2016F636C2687ULL
        },
        {
            0x2B84E681F76FB663ULL, 0xB1B3C349EF65F141ULL, 0x31B19792E90FFA64ULL, 0x08C7A0BC7D13E437ULL, 
            0xF797B876BC1BC0F6ULL, 0x7C8CFB0FCAFD6427ULL, 0x906581EC24E3FB53ULL, 0x3CF62003A9EDD6A3ULL, 
            0xC44C842E5CD21709ULL, 0xF646DAA36C8C0E3FULL, 0x6017D515D28A272BULL, 0x0253D37655C91134ULL, 
            0xD2703351BF89696BULL, 0x62CB509153E6427DULL, 0xC4D3E1DBF9E6B7D3ULL, 0xDE9F34CD37CD1FFDULL, 
            0xA43C99C17626162FULL, 0x8B274FBB12B8FF87ULL, 0xA38BE1BFD5C7BBD0ULL, 0x4D518E762828F9F7ULL, 
            0x14B2844F1B3AFB52ULL, 0x8B4A0B0955E1C03CULL, 0xB46486EF89B755CEULL, 0x4D8FB99BD03C960BULL, 
            0x6FBDC4E440FC7B4BULL, 0xEACEF05AC78770D0ULL, 0x0BD223847D80DAF7ULL, 0xA616F52ED98C18A9ULL, 
            0x6EAE3F93BCEE25D3ULL, 0x581E2C1EA093C249ULL, 0x90A996DEDD81F4B5ULL, 0xC1620F23B76B794FULL
        },
        {
            0xD166AF301709A06AULL, 0x5D1C16D3566E6356ULL, 0xF376ACFA92952084ULL, 0xA6FFC705231C5C5BULL, 
            0x87B95130D43A7417ULL, 0x2FE169F706C2C1BEULL, 0x3DF89AAE5C0D2ABAULL, 0x2BBB839890BCAEDAULL, 
            0xB0924DE0D7D8C8A3ULL, 0xD556971F6A3B0762ULL, 0x15FAFF64B74817BDULL, 0x98D11BA2CC4FC25DULL, 
            0xEC0E7936406B4EDEULL, 0x38843A8A2BA7BF9BULL, 0x406FFBE088D11439ULL, 0x205EAF341BDB7371ULL, 
            0x1773802E49F5DBFFULL, 0x29BD7E201E496FFCULL, 0xACE22D62E78193A9ULL, 0x94AFEE51F3E87585ULL, 
            0x5A3A0FFE5C752DD7ULL, 0x34245793DF60EBF4ULL, 0x946E44E848846420ULL, 0xF091427C22E76173ULL, 
            0xE79F2530D0C105C1ULL, 0x048F5DC87B85C057ULL, 0x9824840B19940AA3ULL, 0xDE4CB9C1CC9DF030ULL, 
            0x42C3CB6963E49544ULL, 0x2D25D2EB375A6AC1ULL, 0xDA306756BDAF2EC3ULL, 0x6AA63F596A916CA5ULL
        },
        {
            0x3D7B6B12B8C2395FULL, 0xCCFADA62C2660ED5ULL, 0x7D1F7C1B9B1AF146ULL, 0xCDA34F83B12CB9DDULL, 
            0x7D2C617278FC0EEDULL, 0x2CD0E92FB648E457ULL, 0x338A2D5D30061215ULL, 0xD80B7089A8CD895EULL, 
            0xF160D2D6AD2E1686ULL, 0x4BB6E8720F3E3EA4ULL, 0x962852EB1649D0D8ULL, 0xDACB4EEF4F1955D3ULL, 
            0x53C2AA3D54903363ULL, 0xA8BDC7B18FECF368ULL, 0xD53EA18DD1511216ULL, 0xF961CD54EB78C82BULL, 
            0x4BA826BBEE71A4D1ULL, 0xAC9D5556140BE27EULL, 0x5BB7BC5E05941397ULL, 0x7462A4900DD9E33DULL, 
            0x8FD3ABD2E77B38B7ULL, 0x887226AE8D6315CEULL, 0xF7EDCA0666ED0414ULL, 0xB43A0F2133E04CEAULL, 
            0x85978C416CCE2334ULL, 0x2CFD55991FE8F2C5ULL, 0x1D0D86BC2A53FAC5ULL, 0xE58C409D681AB357ULL, 
            0x06E6DE1454A88D8AULL, 0x882C54D1C73D456EULL, 0x31DB8E68719AC02EULL, 0x7F5EF15845E6500BULL
        }
    },
    {
        {
            0x0FD9F664DD7EE9D7ULL, 0xC1EAA33823CA786BULL, 0xDD1C5B119B60B49DULL, 0x1DAD5EE7AB5492F1ULL, 
            0x56AC11CC22EADD09ULL, 0xA6BE49510B9D7A38ULL, 0x3A82175B8AB2D90EULL, 0x09307ED12FC49B8FULL, 
            0x0205B183AA3E81D7ULL, 0xEAFBA70628BAC932ULL, 0x3F47FAFF7505BF3DULL, 0x2A38030A1CB499A8ULL, 
            0x1C4729524B2E9969ULL, 0x687F8BFCCE14E716ULL, 0x3F70647540D6CAF0ULL, 0xD9D785A666DB6D11ULL, 
            0x1FC43A7014ECAE1AULL, 0x2AD75968769E43B3ULL, 0x5A2CC1704D174EE8ULL, 0xC6E6656AD77A4D06ULL, 
            0xCCB764EB3FA8B5B8ULL, 0x58151995CC122209ULL, 0xA257BA4920C29409ULL, 0xD213FD93FDD92297ULL, 
            0x426EDF2D9C3207ABULL, 0x7259F0C38EB15332ULL, 0x369ADF41B9F80B88ULL, 0x06B74986AB13096BULL, 
            0xE77DBB62D32BE3E6ULL, 0xE5061CA55C40951BULL, 0x438FAF64A6AF7957ULL, 0x566012A8DD2D7B52ULL
        },
        {
            0xC655DF4390880EF1ULL, 0x08788DD947ADAF16ULL, 0xEF8BC363B672EC73ULL, 0xE4BDBA3541A26C05ULL, 
            0x0B4F89D1E2545B71ULL, 0x4F8844735EF9A19FULL, 0xAF966E3E7F35B27FULL, 0xBEB0DF073CDDC54EULL, 
            0xE2BDD7B343A0F275ULL, 0xBA671E86A4B79A7EULL, 0x2EA3F85A0A7B2F7BULL, 0xBFD372805478355BULL, 
            0xE0B48B232B6130A8ULL, 0xDF44D6591887A349ULL, 0x6548B97ED735EC18ULL, 0x624EB23D746AC322ULL, 
            0x83699E99B21BBBE5ULL, 0x22069A5B40D6ED3FULL, 0xFE071F0C72282637ULL, 0x402B00DB112370C0ULL, 
            0xAD7A8058D66A880CULL, 0x705B86A682756922ULL, 0xE109ECF0B54EBBA2ULL, 0xF0404DC978AE92FFULL, 
            0xFE7E48BD1D49230AULL, 0x49844E7E0843E1F9ULL, 0xB79947EE6BE0A635ULL, 0x47A7335ABDF0385AULL, 
            0x539A4F1895B866E9ULL, 0x505A4C6B14C1A862ULL, 0x0C332CC9D9E92EB5ULL, 0x52E709880E474A46ULL
        },
        {
            0xA12880784F2D0EB1ULL, 0x4DF62BD905C5CAF2ULL, 0xDAED2A91D714483CULL, 0xF55E684A3B77CD2EULL, 
            0xD4B2FFC9A75B5481ULL, 0xCE3BFA5BEF10969FULL, 0x8BD7107C08A1BEE1ULL, 0x22210A5F03D17672ULL, 
            0xB298ADA368589D29ULL, 0xA61067FE4242BBD8ULL, 0x9B746154E7D9A8F4ULL, 0xFE0489327F8053E1ULL, 
            0x18B55D015D1ED03FULL, 0xD3E2300320C36136ULL, 0x95F67DB14CC3FEEEULL, 0x54BD990F37C952DBULL, 
            0xCCBBD911D8C176C6ULL, 0x707B22D47BA9D020ULL, 0x211D941560482833ULL, 0xABF50B42FC0CBD9CULL, 
            0x1E47D353C77A510FULL, 0xA117606082C4D76EULL, 0x86DB099C9951017BULL, 0x202453E117DAA047ULL, 
            0x878E65F5F52E1B32ULL, 0xCAB4DE4A2C8E2CE7ULL, 0x014B5D5D9845525EULL, 0x76DDF024196222B6ULL, 
            0x1D78395935832AA6ULL, 0x6C285BE9D97A1D85ULL, 0x26855227844B13CEULL, 0x2AC5490D3FB674B5ULL
        },
        {
            0xDA40730AA8E29503ULL, 0xB3665399EA9257B5ULL, 0x16A58D094DE36E18ULL, 0xE39FAFD54B7E8C92ULL, 
            0xD682831862894362ULL, 0x122E259CA1F3F82DULL, 0xF018E68C1D48C06DULL, 0x392ABADDE3F4C88BULL, 
            0x32BB20AA2E8EA430ULL, 0xB2BEB1602E88DE90ULL, 0x794566560067B4AEULL, 0x9E403B7F4B62CB0BULL, 
            0x3C0B3B3EE0371A1EULL, 0x00AD2C674D391820ULL, 0xB6C553A525FFF016ULL, 0x220055FC0BC70A8CULL, 
            0x0BC4B4F6619FB07AULL, 0xE6F8190EF235E848ULL, 0x8DD70E3B66808FFFULL, 0xA8209773C882D8E6ULL, 
            0xB9AB175E5C9E8FAAULL, 0xF8463839A811B2FCULL, 0xD15202DC3715CCE5ULL, 0x608FAAB332686F97ULL, 
            0xB7C2379657CC6309ULL, 0x530D0051238ADDF9ULL, 0xC7E3D2C57C8C9E4DULL, 0x673284E7F6FEB87AULL, 
            0x4A6E110D88C1830EULL, 0xBE6E1A351553E0ECULL, 0x8E3BF76A8843603BULL, 0x795449E244940520ULL
        },
        {
            0x42A114E3A7F96A61ULL, 0x1A0D0470AB74DB27ULL, 0x9BA23D23E7DE4BFDULL, 0x6CE90ECACC5CB8AFULL, 
            0xAB505488CC1DCE2FULL, 0x9D22736435CAC733ULL, 0x682D3818CDA57F04ULL, 0x55B45E5E812C4D85ULL, 
            0x7273411E262C6732ULL, 0x9B4C84FA30093CF7ULL, 0xE258CCECC39B37A8ULL, 0x9E3A28FFB337E6D9ULL, 
            0xD77EF6D8565DAFF1ULL, 0x64207C8BA4D48C80ULL, 0xA9E98546B23FBEF7ULL, 0x0B9F4C14D4F1065BULL, 
            0xAB8CF8E78D3A261BULL, 0x242DCDAE4E6277EBULL, 0x705753483AECA78EULL, 0xB8E92A370A0EBCA3ULL, 
            0x93DCC2F40AC31417ULL, 0x58A22F36AE87C233ULL, 0x227580BD4B72829CULL, 0x3D4F47D15B80F35AULL, 
            0x2C3658DB8AC2DD01ULL, 0x59C5CC9A02697B78ULL, 0x8730CD7F88CF6344ULL, 0x4FF4CFA183622CEEULL, 
            0x7C5DE60A2E8B9B52ULL, 0x5846BF64C236FDBDULL, 0xBAF0ADF7863065B5ULL, 0x90862B2156F4A29FULL
        },
        {
            0x6C7027FD05683340ULL, 0x40276B5C0958385AULL, 0xE565B52D184B4D31ULL, 0x8226AEFA269370DAULL, 
            0x0F6A2A7EE02218C2ULL, 0x09CFF8B976DCDE54ULL, 0x1A1288031197005CULL, 0xC875FEB91488FE46ULL, 
            0xA00CF8C72DF2BD02ULL, 0x253BA51592E7AA96ULL, 0xEC58293E0911D5FBULL, 0xEDADFD0831989944ULL, 
            0x4DB750A2CCE4FD0EULL, 0x233622C2E4193E30ULL, 0xEB7B9482DB0C79C1ULL, 0xF3CAF33A1A208626ULL, 
            0xBEA0387926CC35F0ULL, 0x66851EB67BDEE011ULL, 0x21E3AA2896A5E3ABULL, 0x06CADEBD6971D808ULL, 
            0x1497D94B4E7ED0B7ULL, 0xDD673F4563624147ULL, 0xF9BEF6AC362340F4ULL, 0x0B0185464686AF41ULL, 
            0xE413739DB48CE5BBULL, 0x230226355484C129ULL, 0x413BA028A25DC602ULL, 0x9A68D20B0CEBD2CBULL, 
            0xCC78D8533C355154ULL, 0xA48C7D8DB87CA12BULL, 0x98997120949AC80CULL, 0xF039776C7E122AB0ULL
        }
    },
    {
        {
            0xB7A2C29D10D475C2ULL, 0x93B01D3295F1597BULL, 0xB6BBF1F5F2D54C49ULL, 0x50D3E0F2FEF2A354ULL, 
            0xFE4598C7A6E624C3ULL, 0xC9F558A4A9BCCE24ULL, 0x36CFB1B9396C0D69ULL, 0xFBC17ABA67AA8A1DULL, 
            0xDED064BEA2029C6DULL, 0xCF66376875638228ULL, 0xD3E7F95A67E96FC2ULL, 0xF0C3396B93B2CE6DULL, 
            0x6B3FF59FCDD4CAF6ULL, 0xBD76673098402768ULL, 0xAC3624D1E8494094ULL, 0x9E35E908054E319AULL, 
            0xD19ED7690ECA64A8ULL, 0x6123444919DD3025ULL, 0x7BBA55ABFE2730EEULL, 0x755D7E49603D1E11ULL, 
            0x94E88D210BEA0145ULL, 0x228CD9F282EBA488ULL, 0x1004E6397A5CAD8EULL, 0x22CD1C62E358B4B2ULL, 
            0xFDA0D8A784E46F23ULL, 0xE23126CAD8275F8FULL, 0x4C64EC192036DA91ULL, 0xB7AE9CEA23E50CCAULL, 
            0x31B09277C9A8053DULL, 0xEC99B2A27AFC8AD6ULL, 0x4C2D42B5DA5B432EULL, 0xD8EAA4705FA4FCFDULL
        },
        {
            0x52B9107A36FF0D1BULL, 0x31912596A5C5426BULL, 0x83706B2B7FEC17D5ULL, 0x1793BD575B004E90ULL, 
            0x79BFB8257675D768ULL, 0xEE4BE10F628A0C6DULL, 0x281108E4C36BD58CULL, 0xEA9BB4F1FCB3148CULL, 
            0x4DB05677A5DB7F3CULL, 0x1E4DBC4FD5B3594AULL, 0x9C75EFE4FF58A741ULL, 0x00EF3ADABE0BEC91ULL, 
            0x699FCC8DFC9372BBULL, 0x79777C87EAD4265BULL, 0x9F7C2821943D83BEULL, 0x42505FE0FD3FFEEBULL, 
            0x13588B309255E289ULL, 0x9F43408151C0EF48ULL, 0x52622373856DBEC9ULL, 0xDC3B41A143A31C3CULL, 
            0x2EC64F7765EE63EBULL, 0xD7E91AD1AD79E414ULL, 0xF2AACBA6885CFAF8ULL, 0x0F3B4552E56C834DULL, 
            0x5E9620F17B161B2DULL, 0x6DFD4A1B96481931ULL, 0x6F03E0086A32FA15ULL, 0x716A9D5AD6D5E81FULL, 
            0xF9A8BB90E3776456ULL, 0x33FC53A6FEA2A01BULL, 0x1E1649556EB69FA9ULL, 0x7A9C96C814783977ULL
        },
        {
            0x0B561857F50BA567ULL, 0x332E7CEE98693691ULL, 0x1188FFB1E5F4B6FDULL, 0xE093AF2837FE9D02ULL, 
            0xF7EF9F689E5713AFULL, 0xCACA516AE3109BFDULL, 0x69DC56E0F888E665ULL, 0xF76770A087CA2743ULL, 
            0xFA7161A375E935E9ULL, 0xECB3C53C33B22DD2ULL, 0xC3BAD23177A2CF0DULL, 0x1D9F509CC0736D06ULL, 
            0x3A3B2E5F180062FCULL, 0xDEA5867A5CDE7073ULL, 0xBAFA69D0F98CD1C0ULL, 0xE272723A5D5D21F7ULL, 
            0xCFC8F3AE8F24EBC0ULL, 0xA6D204EB362F7551ULL, 0x8118C998A1012728ULL, 0xDEF468C5E4B4828BULL, 
            0xE031A5A01D779F33ULL, 0x893C24CA2C940A3CULL, 0x1B8BFE6124CF3CF1ULL, 0xC29867E1557575DCULL, 
            0x8E90C3916FCE7854ULL, 0xB4A39029F994B61BULL, 0xBBECEE21C724F06FULL, 0x540B99F4AE249146ULL, 
            0x89128DFFD066C7D7ULL, 0xAAD7625777C08A2DULL, 0x3F3CA2D5C53CC56CULL, 0x814FCC884921718BULL
        },
        {
            0xACB5D8EFFCA9F4C1ULL, 0xB73520222C199CD4ULL, 0x2407F4271DA56811ULL, 0x4E4DA71A03F3697FULL, 
            0x97759F2E73037C1AULL, 0xC98AAB7CD00EE2B9ULL, 0xE5BE4AF92C41D083ULL, 0x99465A0EB62AB147ULL, 
            0xE9771E54F7309442ULL, 0xE38A3DE5E959B860ULL, 0x076D1AE8C1A086DBULL, 0x6F5A17B44841423EULL, 
            0x37B61EC8F7375BE0ULL, 0xC67090102D843DFBULL, 0x04922977F95AA789ULL, 0xC9E4832DE325ED9DULL, 
            0x60BEB79869242D16ULL, 0xA20853E18A071B48ULL, 0xF8B6139E24CC0DEFULL, 0x181A4E12104FD032ULL, 
            0x7503080D829FA338ULL, 0x4E3884FA1AE6AEC4ULL, 0xC57C05F542DEFC99ULL, 0x5F656BF99FC7CC4DULL, 
            0xA5F30AFA572B7A35ULL, 0x4F689F56D33E9AB4ULL, 0x89B880CBBD09F18DULL, 0x7517F6DE149A3A43ULL, 
            0xC830560520503755ULL, 0xAE1D3C286B240777ULL, 0x1DC31653A267206EULL, 0x38866D3488413702ULL
        },
        {
            0xB75427FC9CC33B7BULL, 0x2C0AF111E21A73C0ULL, 0xF6E375B20D154A08ULL, 0x2C64AA6A5A7B78ADULL, 
            0xE3EA022C050F6CD4ULL, 0x5900BC1F48E606EFULL, 0x57A8DD51FA67C672ULL, 0x6520DDF1ABCDA3ADULL, 
            0x468176021504F7F9ULL, 0x7AD5CEF1CB74D894ULL, 0x009322A16E914440ULL, 0x309A578B1681B3C1ULL, 
            0xAFA7ADB7AFA680BFULL, 0x85AA5689271E399BULL, 0x735B8AC003431B34ULL, 0x8BC7BB4EC40C863FULL, 
            0x5B21340122C3788CULL, 0xEA7DF74AEAF3C805ULL, 0x26E944B787C5C192ULL, 0xE3014996E31C2BABULL, 
            0xA1E5875EED5C1139ULL, 0x24DA42194C9CEBE9ULL, 0xA902F100CEF69114ULL, 0xE54261143FB976C6ULL, 
            0x7C269F18A7CFDA1AULL, 0xAF546C70F23C3D16ULL, 0x25EC0EDB0B39D306ULL, 0xF68FFE3A289CAFBFULL, 
            0x71418AEF0792C13EULL, 0x848341B080D9D4CCULL, 0xCEAD6C33A602A28AULL, 0x40F8B01B9D984484ULL
        },
        {
            0xADB5A48D980E6029ULL, 0x724C3401478894AFULL, 0x53B919AA52F57F55ULL, 0x9BDF851F1EEADFE7ULL, 
            0x10F1B270FF3458C2ULL, 0x359AA542865D0D6DULL, 0xE6ECBF9100D1EC2EULL, 0xE71F251CA6091F65ULL, 
            0x9EFDFFD10650D430ULL, 0x9CDC62F304276A1BULL, 0xB86BDE85A23734B4ULL, 0xA6A90EF51682450CULL, 
            0x8D07A75358D64AD7ULL, 0xCC0B32D6D7B13BC8ULL, 0x4F5FDE6FE25646DAULL, 0x18AE3D77426478F0ULL, 
            0x4287F5FDB50CC75EULL, 0x54B9AE4B6B987694ULL, 0x91023971EC636474ULL, 0xD933593E50F04DD3ULL, 
            0x87935A4E5ADF5DE2ULL, 0xD7285496DF83B263ULL, 0xACB7D20239FB0114ULL, 0xD73306460AC69007ULL, 
            0xF1B574473335A184ULL, 0x72C6EAABEB1DA87EULL, 0x0AC2C4E809D64B1CULL, 0xD2F36F5D7EF50DF0ULL, 
            0x9513E0478FAA7134ULL, 0x158278E62190EFA3ULL, 0x4346197976560518ULL, 0xF87659F9D681F54FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseBConstants = {
    0x465011BF7D4E0912ULL,
    0x081685309410B037ULL,
    0x80C960B0D21F74EDULL,
    0x465011BF7D4E0912ULL,
    0x081685309410B037ULL,
    0x80C960B0D21F74EDULL,
    0xC2D51CAEA5BADC2BULL,
    0xE2011576E26B531FULL,
    0x08,
    0x8C,
    0xA8,
    0xE6,
    0x13,
    0xF7,
    0x96,
    0xB4
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseCSalts = {
    {
        {
            0x6AB164508452D870ULL, 0xAE7B5580A1D0BBEDULL, 0x991BE31FAE5D6F65ULL, 0x7A5357B6B71E3B49ULL, 
            0x4BCFAD50A8B359FAULL, 0x4423FE1373839F07ULL, 0x11779CE5201AC7AEULL, 0x397AD260DA01BBE0ULL, 
            0x4D6BAFEA1CE470FEULL, 0x721297A452B0BEE3ULL, 0x6DD92AF4490F4A55ULL, 0xDC58950F5B9253A6ULL, 
            0x88F28FD7F802FF9DULL, 0x3E04607A90A65E66ULL, 0x2D9458DEC480C558ULL, 0x0775A139D55C257EULL, 
            0x2AC0684942B90232ULL, 0xE44465819EF4DF0EULL, 0xE0AF386DC4EFA224ULL, 0x8F13370C27EDECA8ULL, 
            0xA2E10CF92F723F6EULL, 0xA53E6A18E53A5513ULL, 0x240F7100A93C8A92ULL, 0x9061D61B40CC3FD9ULL, 
            0x872DEE723EABE322ULL, 0xF94FF1639E212105ULL, 0x818DA5AE2892CF59ULL, 0xF0D3BD18FBDB2617ULL, 
            0x63CD131FF09DE3ACULL, 0x55F02756D7EC758EULL, 0xE637AB0E34C65C36ULL, 0x401A69B1E7F1ABD2ULL
        },
        {
            0x97273FE883649970ULL, 0x1285B55973603F63ULL, 0x51E7AB5A2796E944ULL, 0x5D748F961BA4C25CULL, 
            0x65E2114C7DAAA9ADULL, 0xE8DCFC0421362A96ULL, 0xBA21C3A4FBA02B8EULL, 0xE490A0FE872995DEULL, 
            0x42B4EF69267F87AAULL, 0x6F112D59C3F95395ULL, 0x5B84FA1D09598B58ULL, 0x73E892FC590E1EC9ULL, 
            0x1BB3D0306DD32A2FULL, 0x749E818AB4209E5AULL, 0x10C05B8696E58F04ULL, 0x69E5283B1221DB7FULL, 
            0xFDA651A12E4F1E8FULL, 0xED7F7FACFAAF1B11ULL, 0xCAE8027EB7BA3059ULL, 0x77D87C6B7DDE7B37ULL, 
            0x21AAD97506FE17A7ULL, 0x57B6846C16E327C7ULL, 0x77F6E42E0FB2854FULL, 0x7AF98DE7A46BB7C6ULL, 
            0xD9F18291FD3A9B76ULL, 0x69E0044C8C89F060ULL, 0x0C3B7FA6A740EAEAULL, 0x8069B724B88C37E9ULL, 
            0x6319EC2DF753C489ULL, 0x73B44AF1879E6A86ULL, 0x1A6ACC299D8A4828ULL, 0xDC206D05E6975242ULL
        },
        {
            0x09B7763D031C5137ULL, 0x1320CCAB4B929AAEULL, 0xCBAFAABF5F61374AULL, 0xA7B212B2723C8E6BULL, 
            0x95CECB4D42A883F3ULL, 0x6F8FA0853EFFAD8AULL, 0xA75412FFBE422390ULL, 0x5BE3714633D6C3EFULL, 
            0x59AFEBA7E6300E2CULL, 0x3F37AC684958B32AULL, 0x76C7F52584660B38ULL, 0x9FF11A8D0E680A91ULL, 
            0xB65A1265FB59AC97ULL, 0x78BFF4CDA77E761BULL, 0x08525E644E320A63ULL, 0xF42ECDA3ED1C89D4ULL, 
            0x22922A770B50C6A4ULL, 0xBBF354296FD14FABULL, 0x89AF1B1447832047ULL, 0xE6B7B57FF7F734C9ULL, 
            0xA8623B076119E257ULL, 0x2040B693B0121EE1ULL, 0xAA6710C6C62AEA9CULL, 0xF9791A3C001A87ACULL, 
            0xA8828FE3C940637FULL, 0x539673D5A922DC55ULL, 0xEF945513FB29E980ULL, 0x3C1A3EA449946003ULL, 
            0xBB4067F305C3DA8EULL, 0x28EFBB036456461BULL, 0x77553604738380A5ULL, 0x8872D1A39CF6F42EULL
        },
        {
            0xD19114D2BD76D15FULL, 0x424A4052F2FE9768ULL, 0x9BA18346C53A74E8ULL, 0x9F6F58D7B67ABB02ULL, 
            0xCFA342D2A2B4FD0FULL, 0x5293381D185C3D91ULL, 0x7AA51F0774BA3CFEULL, 0x9A5BBA3944BCFAEEULL, 
            0xE2A30382C7A03571ULL, 0x81261A84EEC7D2B0ULL, 0x97ACC7989406C8EBULL, 0x3E8BE7A87D000431ULL, 
            0x8FFA3F76EA3ABA4DULL, 0x1D95D0CCD37400F6ULL, 0xE06EC6BEB51067E5ULL, 0x71D62D4BB253AE0EULL, 
            0x6DEF239A65309D08ULL, 0x4125BCD6249E20BCULL, 0xEE4F4C3D94A7C771ULL, 0x93A747CAC0DA4433ULL, 
            0x67A3BD823AA3E2C1ULL, 0x7C4E8C7FBEB6A993ULL, 0xE9814FD8CD2B35E6ULL, 0xD34E991E7096C674ULL, 
            0x9EE50014DACF0E18ULL, 0xDBB3E577E4F9A1E7ULL, 0xE75F9DD7C241EE73ULL, 0x871CE2086669A942ULL, 
            0xF6E045ED5FE4C67BULL, 0x6029E1C0710652A1ULL, 0x4D9E4A8ED2D788C3ULL, 0xD864525887F59476ULL
        },
        {
            0xE50A7A4F092FED6BULL, 0x7F5237D0A8CAE3A5ULL, 0x9FE16ECD902B9EB6ULL, 0x19CC1EDB9076ACF1ULL, 
            0xEFE58A11ADD62DA5ULL, 0x6EDF3AE3C3B11DD4ULL, 0xCBDBADA9C12A1389ULL, 0xDC03240109EF167AULL, 
            0x9F0E84567D64C8F1ULL, 0x7343A8D68B97F7DDULL, 0xEB81C9FAF9F85DF2ULL, 0xB98F8C478D1BD417ULL, 
            0x0BB8434394BA7CE0ULL, 0x26E0D850F2D05F32ULL, 0x60ACD702280055EAULL, 0x803009A9ECB8E6D5ULL, 
            0x147A56BE8816D856ULL, 0x4A8A5630BAE83E74ULL, 0x9E457E6E58139501ULL, 0xB0F9C57EE73B14D9ULL, 
            0x0748F76FE9FE93B2ULL, 0xDF3EAB86AC509482ULL, 0x74875F5923376968ULL, 0x98290F6CFED5EA20ULL, 
            0x1579F2164A4E483EULL, 0x8C5D6BECDE557051ULL, 0x5720E333B15B5257ULL, 0xA8D7FA7DFE266241ULL, 
            0x8BCFD8242AE02A9BULL, 0xABDAC6163D7017F8ULL, 0x877141BF2A444316ULL, 0x612CA5F029B9563CULL
        },
        {
            0x613FDBF7DAA1E0DBULL, 0x50572A9CF72EFC32ULL, 0x8A17F7CF21F15ACAULL, 0xD82A52E9E2F05CC1ULL, 
            0xB40DCAC2942C9B3AULL, 0x2ED9C0AA29EDE827ULL, 0xDE5325E5F8B39D47ULL, 0x79AB39C093A02027ULL, 
            0x48E758F493D975EEULL, 0x34B7B447D28162CCULL, 0x74D18319EEE12526ULL, 0xB9EE45DF68E08E85ULL, 
            0x27135255499C60FBULL, 0x9F3DE84091EFA0F2ULL, 0xB4A240E72AA2185DULL, 0x0F84EECD0291FFEEULL, 
            0x58975E9D377F56A2ULL, 0xE7D6D3F6106A8EF8ULL, 0x50B1B74DA27E33E4ULL, 0x912E15EDC1F1B4DAULL, 
            0xE33CAE7DFFAE556EULL, 0x67C4367D93CB94FFULL, 0xD82A27F38516C216ULL, 0x5C740A1CB8EFBB6AULL, 
            0x3B2D9D785B622FE4ULL, 0x415590C6F5D37534ULL, 0x3E617E0F01692F61ULL, 0xB50CCBBE5EAFAD51ULL, 
            0x1630128C131FF091ULL, 0x961CD0CD6A5F5C21ULL, 0x82D37BA98B7E016AULL, 0x98DCEC273F0190A2ULL
        }
    },
    {
        {
            0x8A6B62551E1CA297ULL, 0xA09EBD740F5391FAULL, 0x3C7551DF140200DFULL, 0x9DF570362D1B4C63ULL, 
            0xD4341202B83DB640ULL, 0xAE7B66BC30A776D9ULL, 0x2AD93EBEAA1DF505ULL, 0x05B9763139F63AD9ULL, 
            0x0FDE5DB1F32E8B55ULL, 0x83EE774AD7022213ULL, 0xABB7A0F3E1BE706DULL, 0xD823B98854CF8C21ULL, 
            0xA1AF14940C6E3F82ULL, 0x3AB6C8CF0068F01EULL, 0x6854BDB215FAC300ULL, 0x04067E2DBA9B5DB2ULL, 
            0x3A901BDD0A1A66E6ULL, 0xC3421F5BCF742799ULL, 0x1D636B0FFD0588A7ULL, 0xDA00F2A5BE3979EAULL, 
            0xAFA571CB7BBB44C7ULL, 0x6E056542FF01B2AEULL, 0xA559234484415558ULL, 0x780866190D78CFDEULL, 
            0xF2002BB8A06B594EULL, 0xF46AACFCA7CAB331ULL, 0xD7A01DEF67DC7AD1ULL, 0x647AC544532FE960ULL, 
            0x53E22B1DD6C07B94ULL, 0x636DB9733939614CULL, 0x5E331EC0843BF64DULL, 0xBCC7292B6401619FULL
        },
        {
            0x3D7A8A3FB44A8745ULL, 0xA502BB575C9325DEULL, 0xB24428EAD96B266BULL, 0xECE9CFB1FDFB5C1EULL, 
            0xAFCAB79A1C1052F1ULL, 0x91080E453E58B9ABULL, 0x34D86FE20907F973ULL, 0x7556FF5EE5320910ULL, 
            0xC351B176020BECDAULL, 0x9627CD149269ED0DULL, 0x4DB09BD253944DA0ULL, 0x277287489E398668ULL, 
            0x4FD5E99B9B16BB0DULL, 0xB84333D399448BB9ULL, 0xFDFF84D0466DC7DEULL, 0xF2F9D3DFD463E954ULL, 
            0x9B3F8F1ACBC05A89ULL, 0xA4C7F9AEA1CC3936ULL, 0x2452C941DFD0F2B5ULL, 0x0A76F93AFD3BD837ULL, 
            0x9CEB6ADA20535426ULL, 0x250BA973DBCA8AA0ULL, 0x8F57F7CD8CC0FE2DULL, 0x4ECCE3EBDB43414DULL, 
            0x277938FBEE5FF81FULL, 0x7B1D61128C4F79E3ULL, 0xCD8D77E73515CEE4ULL, 0x23E45E8CB2DA356BULL, 
            0xD6F1ACF6AC499997ULL, 0xE7A107F68DE5CF8AULL, 0xDCBD231594B5D73BULL, 0x43A641E1C0155CD1ULL
        },
        {
            0x98793B664588B13BULL, 0x792C524359FDBD06ULL, 0xF83EF5DE42C3BC98ULL, 0xF94FF22C90A3A163ULL, 
            0x5BC46DE24C456193ULL, 0xA91FD15E1246C111ULL, 0x0556791C134930DFULL, 0x2E49D0B57E87C1D0ULL, 
            0x7A870CD90BCF2A58ULL, 0x5DA60F1BF29530C7ULL, 0x38DCB8ABB9F8CBB5ULL, 0x1FAEB05353BD1DC7ULL, 
            0x93FCB1826D780E73ULL, 0x8DCF84C7EDFE46B2ULL, 0x282FC205020B6BAAULL, 0xA1C8F0A6B9DD3184ULL, 
            0xA55DC3507FEF40C5ULL, 0x0F381A4B86D9CABDULL, 0x4F4C1D5FBE43B42FULL, 0x36FD778BA31C5AEEULL, 
            0x7F48D10F8741480CULL, 0x932F67316E9623F0ULL, 0x34393457C0CEB463ULL, 0xBC462344A1F302EFULL, 
            0xF6A8774E836DBC9EULL, 0x9CD93C7155C4D1B3ULL, 0x6253290F80130001ULL, 0xEBE30F3907D0E12EULL, 
            0xA0A620829D005A24ULL, 0x5A263F85E427E300ULL, 0x6BA17DBDC70E46C2ULL, 0xF1F7FFE7393062DAULL
        },
        {
            0x1DFC33690E3DBE16ULL, 0x6E16A5E3B98071C0ULL, 0x55174C97ACA7441EULL, 0xC0EBBCBFAF327201ULL, 
            0xB2E6F5F5359D41FBULL, 0x7E9EC83A2504E10BULL, 0x3BA953101B3D2E1EULL, 0x512C75AE5F0D6EC6ULL, 
            0x8DB6DF1B5BF8C699ULL, 0xD03C56A1BF02E87CULL, 0x90027D3203E9561EULL, 0xFDDD0B7637E8D2AEULL, 
            0x91B89CD574FE1FF8ULL, 0xD3F43CF9B33C3BCBULL, 0xC94635A13DCDF516ULL, 0x1D4CAACA4291AE07ULL, 
            0x6F1C49CD6F02A917ULL, 0xE53AE473955BBC93ULL, 0x7D8E3E32146BE9B0ULL, 0xB671887CC0943240ULL, 
            0x1996C0C0BA62FB8EULL, 0x717CE4559BE3B24AULL, 0xE5A617124244984AULL, 0xFF31C0191E176BF6ULL, 
            0x7E8D23E215ACDB00ULL, 0xFB84DEE93DDA99F4ULL, 0xB1451D8C54A81E10ULL, 0x74F25B0F61748717ULL, 
            0x39A03B2D64AE7B1DULL, 0x7420CCF61259D5E0ULL, 0x0AD08FC1E3A990CEULL, 0x3F586D791D06F219ULL
        },
        {
            0x3B34537BA8BB9DD6ULL, 0xAF83A5FDB1E98C46ULL, 0x18CB8D66EB6542D1ULL, 0x7A2AB8E3978CA6C6ULL, 
            0x42BE8750CA88E1D2ULL, 0x0392252FE9B8FE0FULL, 0xA9EDD2BBACBB5960ULL, 0xA8E0A71FA4F7FB7DULL, 
            0x1B71AFC675571A16ULL, 0x4A3C70807809D03CULL, 0x06917AC42D6A7606ULL, 0x150E57EA1939981DULL, 
            0xC0490C50B3E46108ULL, 0x7BEA9743430B3871ULL, 0x7D022365E0CE4197ULL, 0x405D330759CE323EULL, 
            0xB783CED9646E6712ULL, 0x601F07506FF44717ULL, 0x3BF287EE1683D314ULL, 0xC94BA91F5A06F469ULL, 
            0x686223CC80BCF94EULL, 0x15B66E4612655623ULL, 0x0A15D21EE2E2987CULL, 0x04BDF7C1A9FD099AULL, 
            0xE22A1113468DB27BULL, 0x06CA251B58857581ULL, 0x2C982DAB53D031A9ULL, 0x8D0721FE27598866ULL, 
            0xDDD53C03CF13E4B1ULL, 0x3589974EA29A4FD0ULL, 0xDF3D93F06AFB1EA4ULL, 0xF55C72CAE38A39C4ULL
        },
        {
            0x9D6414AF022F6DC8ULL, 0xDC1EA7BAA35DFAB9ULL, 0x9CF693B4DA529C35ULL, 0xEC04C692A3FB162FULL, 
            0x5E84B98C7DC1BD66ULL, 0x108A5600F8C64287ULL, 0x95E099992C32F71AULL, 0x86EEF6E5C538E131ULL, 
            0x292F91392A2052D0ULL, 0x5A2A7DB77289B5D0ULL, 0xC5014D6FC899A0F9ULL, 0x3A47C6D2D9F7A931ULL, 
            0x7AA96400E6C6C931ULL, 0x3E915C14697B8224ULL, 0x84907F7A29B6C160ULL, 0x3B53232E45A7AAEBULL, 
            0x75192C03DF2D7894ULL, 0x5ADFA602DBA7F642ULL, 0xE395FFD34CD7861EULL, 0x15B969EBFDE794D5ULL, 
            0xC5F2702026B5E9CCULL, 0x6A1F65AD2F9EA6C3ULL, 0x4D1D16D70A9AD6B1ULL, 0xDA571D525A78619CULL, 
            0x8EE7F47638916051ULL, 0xFD1D6FA7AED1DE64ULL, 0x202D088362DC76B1ULL, 0x960E20EC439DEAB8ULL, 
            0x2BA4D8D131829731ULL, 0x47247C7FB7C7175BULL, 0x9294C9B50BD7B1AAULL, 0x7DFB75A621312FFDULL
        }
    },
    {
        {
            0xA791A1BF677B8564ULL, 0xD7DB7B88685EBF21ULL, 0x601EB05868B3FF2BULL, 0xBB02B4EA151549E9ULL, 
            0xA91FBBA512A323C8ULL, 0xB59C381F686FE6C9ULL, 0xFED366B1E8650618ULL, 0x8C82FEA4200BB676ULL, 
            0x28C475876BC37FDAULL, 0xBD7D33870510D5CBULL, 0xB177749721716FB7ULL, 0xBD3D2B60E0B99B3BULL, 
            0x2EFBBD724A53B169ULL, 0x116175DAF854E2E3ULL, 0xCB2250F142EE8DA0ULL, 0x2CE82391F8A4ACBAULL, 
            0xDC51BB60B257135EULL, 0xEB0E563D8C99FEC8ULL, 0x18D030F12F898340ULL, 0x16465CD44E8A318CULL, 
            0x3CA8587CAD27E86BULL, 0xCB0B1BE9F4E252A4ULL, 0x92AE0054FDC25233ULL, 0x0E06A5D93316D305ULL, 
            0x2EF788A05798F395ULL, 0x265971523186C1BFULL, 0xF885DC30FC907704ULL, 0x0FE678A7C5BA4551ULL, 
            0xEDC90986F7AB7E4CULL, 0xB3EC2691F7D3D244ULL, 0xB9609FB5AA9B030AULL, 0x0ADB59F8ACF709AEULL
        },
        {
            0xF87BE94119EA4C99ULL, 0xD0D1357C287E1A41ULL, 0xCCDEF99FF4CB161AULL, 0xE6CC7F889A5D3A19ULL, 
            0x3E9B697846A55209ULL, 0xABF932807D8919FBULL, 0x020A9BF053EB965BULL, 0x2EB2EEC5570AEE78ULL, 
            0x35EFC2ED915D87CEULL, 0x661AB1F508F68219ULL, 0xC334C6D1681BCB13ULL, 0x1045D5CE6AE8F080ULL, 
            0x15959C2DF17C6B6EULL, 0xC57E7C40AAB9B4DAULL, 0x8BE312BF3348622CULL, 0xC01BB1BFD0EF8C16ULL, 
            0x9D2C02D9AA8B08B6ULL, 0x243B1C4F10CE0C84ULL, 0x851852DFE9121B7FULL, 0xB3A80304736FCAC8ULL, 
            0x251525EE7C2BF271ULL, 0x7277AE11A8B898AFULL, 0xB6927DCEEE890A4EULL, 0x1653DDAE3A68D33CULL, 
            0x4CA7BCAEDF9035E0ULL, 0x9626B003961CFD30ULL, 0x09B1A992A929CE3FULL, 0xB64651C86DA80A92ULL, 
            0x7EF49BF157BDC695ULL, 0x136012C5CF8A0A80ULL, 0x4989FBCF0B04C8BAULL, 0x005C1BB7A57E0A06ULL
        },
        {
            0xD84F80BE18BB17CAULL, 0x153814ED99CF5811ULL, 0x7D8A7A99CE5AC105ULL, 0x60FDF4B2D5F3E688ULL, 
            0x416BAB86662A2E97ULL, 0xBB79FC6CA6598CA0ULL, 0x8D9A65478DB8D922ULL, 0xC334DA1F8760894AULL, 
            0x33D6FD6178A9849BULL, 0xCC8BBFC31CE5BE6EULL, 0xB40D828652A88AC1ULL, 0xC5F58D1BE49D6360ULL, 
            0x472C8841093F1087ULL, 0x926B99E39D630D58ULL, 0x76013C021E6225D0ULL, 0x340306A231433B48ULL, 
            0xECAF4D1D81D80ED2ULL, 0xEBD0E33E5C2C5C5FULL, 0x2CB0D69ED3DD2DCAULL, 0x488E7C15832C7876ULL, 
            0x6877F7A30E7CD164ULL, 0xC61E93CDB0C00CCCULL, 0x694B5306DAFF78CFULL, 0xFF0F78FAB1561F1FULL, 
            0x81A16C0F23D60956ULL, 0xE9DD530E5413BA75ULL, 0x2ACBB0CD180BCA2BULL, 0x3722CA0F72B90082ULL, 
            0x8B8397091D6801E3ULL, 0xBB7047738F06E490ULL, 0xC839F17DA69B7107ULL, 0x45DE764444514251ULL
        },
        {
            0x99F208A7CDB136D5ULL, 0x997FF4617C1A794AULL, 0x2423268CF509939EULL, 0x899087AF97D57F62ULL, 
            0xBC830E1949150E16ULL, 0xB07F7E63A7BE8C6DULL, 0xE4B716D66E9668DBULL, 0x3769BB20D254A4A5ULL, 
            0xAA7D761CBBCEA69CULL, 0xFF66A0B4C016F720ULL, 0x85A7AF27D562617AULL, 0x75B86D3C4DC976E5ULL, 
            0xDE5C457F5BD6E9DDULL, 0xD408E592A81A7AC6ULL, 0x9C3DF28504E91D3BULL, 0x7727B38D8931F194ULL, 
            0x8A87F4F07685F294ULL, 0x7DBC72417FFB4F69ULL, 0x0BC0345E71B7D644ULL, 0x0D1DE6A0ED6AA177ULL, 
            0x4E7555E1CD0F36FDULL, 0xBA558BA744CA1C54ULL, 0xFEC484E8C55C2696ULL, 0x20764D607F9B0AAEULL, 
            0xD01761FF3C1CC7CEULL, 0x50FA5C62590C1F50ULL, 0x8950BDC8303E0803ULL, 0xA4F155850D3F9D72ULL, 
            0x71C27A1CD570B175ULL, 0x8224D565D1F92A65ULL, 0x15EC9DBDA3CBE023ULL, 0xE9D0131DA2FE74FAULL
        },
        {
            0x978B3397520760EFULL, 0xCB8D5DFAC80D4561ULL, 0xCA1F54275B442903ULL, 0xA4CDE326C3CD4BB8ULL, 
            0xFD95FC3FBB5AD45BULL, 0x2B16CE00AD912C0FULL, 0xF35850F6F3A06F06ULL, 0x2C34CE36FB59B54AULL, 
            0x00F6F031CAB6AE8FULL, 0xE1D799ED4FC44718ULL, 0x8F3257306CCC5855ULL, 0x6943DD5ECE503726ULL, 
            0x14AA6A0D743A165FULL, 0xF9B558BDD35A5767ULL, 0x0F95797C539862EFULL, 0x769C3505BFEFBEEDULL, 
            0xE59823A690D32857ULL, 0xB02316DFF6E608F8ULL, 0x3CC42E46FAE6F126ULL, 0x96954449A5EBCEE2ULL, 
            0xFFFE372C7A34A388ULL, 0xE79B621AE9583B62ULL, 0x7F9AEFCA4CB2E229ULL, 0x58339C59FF11F496ULL, 
            0x803C492761610428ULL, 0x84CA1C8B61451CB2ULL, 0x8960EB644E62357BULL, 0xF6E7C95057625046ULL, 
            0xE117482AC1603A23ULL, 0x04897071362D4BE4ULL, 0xCB8C17C88D3865CDULL, 0x17116EC82629DF6FULL
        },
        {
            0x0F6469A4D4FDD7CDULL, 0xE652D364C884727DULL, 0xA5C7C9F77D54010FULL, 0x7F3351D61A0E0594ULL, 
            0xE296A4108013C30CULL, 0xC9F70C3275D8D9A2ULL, 0x6ED31CCF6921FF9EULL, 0xE0E2A9010F9741C9ULL, 
            0x0460DAAF63B3C383ULL, 0x32333611F5CB84B6ULL, 0xA6A4FE8DB4BC02F2ULL, 0xB311DC8484D86462ULL, 
            0x99C08EE17E6D1A89ULL, 0xC0B98F13B85D8CDEULL, 0x74F4EB149234F209ULL, 0x5A8F6CF39E96441BULL, 
            0x5D1D9257D955969FULL, 0x421432E7014FC4DCULL, 0x20A78B466D80E4C4ULL, 0x971DDE1CF30547B0ULL, 
            0xA7FE59F3FDFA9652ULL, 0x79803F30CAE55077ULL, 0xB78DED7729A93597ULL, 0xA91AE57C6296736BULL, 
            0x6AD32F8DB8E4C093ULL, 0xD1F90535702C20C1ULL, 0x73163323EE7F9464ULL, 0x095834838C0A240EULL, 
            0x9AC8A9DDF4DAF746ULL, 0xDA0F6CCB9428F475ULL, 0x545FF5FE3BB370E4ULL, 0xD22D684CF223577FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseCConstants = {
    0x412A52E2C35AC674ULL,
    0xCF44674330E8ED22ULL,
    0xDA813582431B644FULL,
    0x412A52E2C35AC674ULL,
    0xCF44674330E8ED22ULL,
    0xDA813582431B644FULL,
    0x938B5F639AEC9877ULL,
    0x431F9799FE51B952ULL,
    0x18,
    0x80,
    0x10,
    0xC3,
    0x91,
    0xD9,
    0xA7,
    0x6E
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseDSalts = {
    {
        {
            0x90F328D0328FD0BCULL, 0x55CBB756E3079565ULL, 0xC352E5758D58EB9BULL, 0x9985EE5EA79B4BCDULL, 
            0x0AF4493F207ABD62ULL, 0x7278D684B9B780C6ULL, 0xEA87888683C1A715ULL, 0x87F8052C39FC1B71ULL, 
            0xFA4F3A203A0F57B9ULL, 0x9C0089B5BB129FC7ULL, 0xE8FFA2EE981E66F2ULL, 0xC295D33397960047ULL, 
            0xCF526B5E1E17B3BEULL, 0xB973BEF4C101D4CDULL, 0x706B1485DE94FA1CULL, 0x2BDAC429BD63380CULL, 
            0xBCB3E99584B0D345ULL, 0x47BE564419258965ULL, 0x7A0880C1F0D8CB93ULL, 0x88ABCD2EB5A16B9EULL, 
            0xE9CE31284A3790B5ULL, 0x1F6488541751ADCDULL, 0xFCF76457B51DDDBDULL, 0x68F23607EA2183D6ULL, 
            0x8FBE161E8B1FE62DULL, 0xA6D455FFC7077B24ULL, 0x6C56F5D418722514ULL, 0x5006D7E83CCEE06AULL, 
            0xF456E047C71156DDULL, 0x2CA190EA59D2D7BEULL, 0xCD34D79EB0DBF95EULL, 0xE5CEF69C983AE0BCULL
        },
        {
            0x74227BABEA45D8E0ULL, 0xA0212F4405778C20ULL, 0xEF44CC0DB3DC3F17ULL, 0x8A20141F499B48A4ULL, 
            0x10CF1EA80B0691BDULL, 0xFA38AE582CF99935ULL, 0x488925FD2943C4C6ULL, 0x5BE18D0CB0516427ULL, 
            0xC97506A3C623829EULL, 0xB30D3731AB15BF71ULL, 0xACC13359214526E1ULL, 0x450043775995D9BBULL, 
            0x3D7B359D8CC246DFULL, 0x1A483C7503581178ULL, 0xEF15C3FDB0E53546ULL, 0x2D24FCCEC329CC67ULL, 
            0x75870AC559BC54ABULL, 0x771E446BA6FB4982ULL, 0xFAB9B407E9BD15B8ULL, 0xEECC8BF1ADBA85B7ULL, 
            0xDF7FF387ABBC716BULL, 0x8AECFBED19624C1DULL, 0x5ABB2CE41B52FD47ULL, 0xCD6BC0072CBACF44ULL, 
            0x7A8B5C5AD9BC4168ULL, 0x53A72BF93682FF1EULL, 0x348C445B42D12176ULL, 0x6C7F9DA64DEA853FULL, 
            0x0F1819F2ECD4CDC9ULL, 0x7B0DE19048F1562CULL, 0xE20A97AC575214A3ULL, 0x0BA7B30D4F726B52ULL
        },
        {
            0x02E6742D4EAC61A1ULL, 0x3BADFF3F18EC001CULL, 0xE3C3C60A25BB65FAULL, 0x9BEA965F72B4783DULL, 
            0xF849B53B0BAD1C19ULL, 0x3EA40F1F592E2F18ULL, 0x2889779E6D23770DULL, 0xC4219EC0C8DA3DEDULL, 
            0xA84B5EB173EEC719ULL, 0x8071015E6FD507FEULL, 0xE9E5CA8EE65BCC06ULL, 0x32F2209F88E81291ULL, 
            0x510F84B4427B3E67ULL, 0x63F9464F4A0E356BULL, 0x6958FD387DC7DF40ULL, 0x386DFC18924D5305ULL, 
            0xB7A8F4A11CBBD4AEULL, 0xC6BC4D9047C3209BULL, 0xABC588BF36562BDCULL, 0x73924606158BA7FCULL, 
            0x126BF648F96D42F9ULL, 0xB02D671A29FDAC99ULL, 0x4C3B75524038E4A4ULL, 0xC411C11380819FF9ULL, 
            0xEA993F004753C70BULL, 0x10A66502AC18811AULL, 0x85A156C4D27F1A6EULL, 0xE492AD92B9DBA936ULL, 
            0x4289D32E493B4A64ULL, 0x2B0E3671397270BEULL, 0x67C33B9F5820782FULL, 0x2D344D2E66C9693CULL
        },
        {
            0x9E233D275584FE72ULL, 0xB3D4D22917D5D1BDULL, 0x97E39F1045160E21ULL, 0x59CCFB008BF7F801ULL, 
            0x2745462CBAC36AF1ULL, 0xDEF49B82DFCE088DULL, 0xC905CF95462DBDA3ULL, 0xCCA494ADBDFF3582ULL, 
            0x41BBBF0E65776D38ULL, 0xFBCA9A4A2C41FB2FULL, 0x511CF834903643DFULL, 0x30DDA2E18A349D0CULL, 
            0x3AC85C1A48699685ULL, 0x0C520223894E73B4ULL, 0x0C15E8C2F607217BULL, 0x2432F5E722E7612AULL, 
            0x1FC152AA97D75F9DULL, 0x67C5CE3DFFDF710DULL, 0xA33F215E386D135FULL, 0x4010D419D9681BE6ULL, 
            0x05FBB0B97830EE63ULL, 0x4296CACDB9563149ULL, 0x5751EA4F1A53BD23ULL, 0x6DDFCB6FC529A7F0ULL, 
            0xC5DA2B39605C89EEULL, 0x941ACA4F34F7C4C2ULL, 0x682C1B92D39F1BF7ULL, 0x7E4C283BAE49AC01ULL, 
            0x21A2ED1D692CC445ULL, 0x468A2FACD4E4F4F0ULL, 0x5C112C3A5B0840B2ULL, 0x056B2E3DB6CE4922ULL
        },
        {
            0x02197040611F340CULL, 0xD9A1E4978BD0B1A6ULL, 0x1E5E27975AA6B903ULL, 0x396B98277F9E9C65ULL, 
            0x4EB01EDD0642EED8ULL, 0x432FCB405E50B391ULL, 0x8E0A91AC64CD8E9CULL, 0x395E7BEAFCCB0D30ULL, 
            0xFBD58C82C703C352ULL, 0xBA385B90AFF38A9EULL, 0x365A35547AE3A5E7ULL, 0x19EE2B08D4CEB851ULL, 
            0x0BB128C26F0752A2ULL, 0xA03294D96B7BA38BULL, 0x70FC4AD010A6EB51ULL, 0xF1E06D1159AFD861ULL, 
            0xE0EB22A32F20265AULL, 0x4CD59E6D56F342ADULL, 0x5FC6B27E03064C43ULL, 0xD3D0AD2776EC48DEULL, 
            0x18085FFEEEE81239ULL, 0xC3DF8118FB1B3ECAULL, 0xDAB7B881809B2AB4ULL, 0xA3652F360D541EC9ULL, 
            0xEB9394A15C5427F9ULL, 0x75EC5AB54FBF9312ULL, 0xAB6AEB1E7ED0A708ULL, 0x622E30CF3177A9AAULL, 
            0xA8962FE9A922175FULL, 0x0CD7BCF67EC7DB28ULL, 0xB44B00C23ED07FBEULL, 0x0738BCC1DFBA6CAAULL
        },
        {
            0x5F2CD380B1DF03F7ULL, 0x580ECD0707929576ULL, 0x2577B5ED5E743DB0ULL, 0x77A2A643D11D7118ULL, 
            0xB9B257366AB396C6ULL, 0x03CF11D4BB09A66BULL, 0x14C53D86F6EA25F0ULL, 0xA5CF42BFC2F23EB0ULL, 
            0x6E758621BF331B9EULL, 0x9126BA1A6162E2D7ULL, 0x67A3A978ED2AC614ULL, 0x5E72A171873852A8ULL, 
            0x08B57F916D1F2105ULL, 0xB84B930B53E5DD30ULL, 0xC007186EECCBC011ULL, 0x316292CFC403D86AULL, 
            0xB2B98085B283026FULL, 0xE5AE3C085F310413ULL, 0xD3E3DD2F77D2CEB5ULL, 0x3EA6E295C544E62EULL, 
            0x093AEF1B6CDB7B1DULL, 0x98B86DE410171765ULL, 0x8C3FAF0C75DD1F88ULL, 0x90D4CB29120AD723ULL, 
            0x3A5421A0DB8C63DEULL, 0xEC6752C52EA4C992ULL, 0x87B18317077BB3AEULL, 0xB40951DE90F83620ULL, 
            0xEC1B9BFA8EA6619CULL, 0x9483167B7A407643ULL, 0x41CAB65F4B4115BAULL, 0x31D8576E3636F587ULL
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
            0x58BF69DEADD6DDA4ULL, 0x893B1AD984B440EAULL, 0xDB952D10C7260474ULL, 0x7A9FA8B1BD792273ULL, 
            0x4A7F5A0AB775D15AULL, 0xC5053CD1408545F1ULL, 0xF869D11E9E4B85BFULL, 0xE0FA60D69A374617ULL, 
            0x812629CAC6598500ULL, 0x7CE7C6D94BC03897ULL, 0x928E2A85EB10E185ULL, 0xB031C6A328678FF1ULL, 
            0x4A3D38FEAFCF7A98ULL, 0xCA65327800764859ULL, 0xC937ADAFD7611AF5ULL, 0x34282A40609A8AFAULL, 
            0x8DF541EBC7613492ULL, 0x95EBBC8BF0F9DA31ULL, 0xD242D1446C9AE4ECULL, 0x67D28E991687CC86ULL, 
            0x89E7B2B888E6390EULL, 0x46E9D388196B269AULL, 0x794FAC010B407485ULL, 0x5E0623CF5A7814A5ULL, 
            0xA78151D016A16D43ULL, 0xB6D53DE9E3294C08ULL, 0xEF6FEC3582A8E98FULL, 0x4BB82BC2E0AFF6AFULL, 
            0x1C1FE7BF48C3AD57ULL, 0x38E67C879D55A0CCULL, 0xB6C767A1645D8B18ULL, 0xE2EAA935C6212039ULL
        },
        {
            0x301F61BD0907AD8BULL, 0x796E43B4FBB6AA71ULL, 0x3FBAB2E8D81F5CC6ULL, 0xE9695D2C9847763FULL, 
            0xB371F3F2C6E0E226ULL, 0xE497DD68AD85BC4BULL, 0xF180B314CA4AE7A5ULL, 0xF236BFBE5C88BFC5ULL, 
            0xC1EBA74506182535ULL, 0xF78AD3B5CDA87AF0ULL, 0x88980CC1380BE5DDULL, 0x59FBA9125F37AC50ULL, 
            0x1197F250C4E6B14AULL, 0x94F8F75493665869ULL, 0x1A354AE7B1BD1601ULL, 0xA8AFA169D312E2FDULL, 
            0xCB24491C4E54434AULL, 0xA4DFBC9D56917CEFULL, 0x882935E4041C5D3AULL, 0x787ACED5115F0C5EULL, 
            0xBCCDD1DE5E6C87BFULL, 0xCCC66C2CBF68BE0FULL, 0x8413C1F949B8C849ULL, 0x2D0B315789AF8F93ULL, 
            0x906AF34B3A1C1781ULL, 0x17D284EFD65C58C6ULL, 0x49AA5A5AFDD7E157ULL, 0x114C218AE7E19AF7ULL, 
            0x5A75276FF236574DULL, 0x4D195DA8D34A8A39ULL, 0x0664391CA40C0B23ULL, 0xBC9191ADC716F5E9ULL
        },
        {
            0xD6F0DFC7D4846AB4ULL, 0x30CD75847095D435ULL, 0xE5792C91169732E2ULL, 0xCB8AB730EF825800ULL, 
            0x95515C498E0286C6ULL, 0x1108733F8D9A7EB1ULL, 0x06A9D1591027D9FEULL, 0x00EB050690F525CFULL, 
            0x47AE56E6EA3DC9B1ULL, 0x5860AA3DC032DC20ULL, 0xE441FCD55C1D5063ULL, 0x36F244FB11B97FAAULL, 
            0x6A8676E39D3FF3ABULL, 0xAA4EA4DE67205FF1ULL, 0x38F75587F1B5595EULL, 0xF981DE71A312967DULL, 
            0xD53A9E112E725283ULL, 0xE448D3204576741CULL, 0x7CC2CA50853F595AULL, 0xB30201C7F0A2A2FEULL, 
            0x0B6FDAE05095B695ULL, 0xDEF70C729578AAF1ULL, 0xF8E3C1E4E12C9FA7ULL, 0x1759FB0FA4A947E9ULL, 
            0xDF8D53EA7169A7E1ULL, 0x9ADB397ADBDB9D38ULL, 0x2DFC0D876BED3A46ULL, 0x8F5479297E942784ULL, 
            0x6430471808614858ULL, 0x8CF06CE3C9579182ULL, 0x6EA87010E1647046ULL, 0x0FB6AA296084B711ULL
        },
        {
            0xB8BA0B20A7435906ULL, 0x65CDC6ED96074AA2ULL, 0x26066E0918479376ULL, 0xC67820F7855DDD03ULL, 
            0xB4A1E4C88521C818ULL, 0x6F1DCA7D8A9E5115ULL, 0xED4BE8F2F41B8C5CULL, 0xAAE09C894692927AULL, 
            0x3E861F38EF86307DULL, 0xA4A23AE4DF64B461ULL, 0x429AE628AE4AD106ULL, 0xA97AF2572E315A66ULL, 
            0xCB0EFFD5C145B931ULL, 0xB51195395C00A59DULL, 0x4CFCF8465E2E14CAULL, 0xAE5324FAB204A25BULL, 
            0x3DE8246E78B73EF2ULL, 0x1FDCA25B5196874DULL, 0x1E8AEEDE8C24FA9EULL, 0xBD51A2B4D01D611FULL, 
            0x38B61AC7D06A4A35ULL, 0x7A7EC8E1960F4A31ULL, 0xE9F834A0F0B7A88CULL, 0x33883BE59E2A29F8ULL, 
            0xFCEA03BFDD76953FULL, 0xF16971411E560C1EULL, 0x68AE5CCD349C3908ULL, 0x389EA4B6199F4B22ULL, 
            0x37E0E30196DDFF06ULL, 0xA0A5C32C2ADC1D25ULL, 0x8CCF9756014F9FBCULL, 0x5B926AF4033CB589ULL
        },
        {
            0x378FA379A605758BULL, 0x7FF35A065DAB017CULL, 0x5BCA94A6B649610FULL, 0x976776B115F42C9FULL, 
            0x734907D97636051AULL, 0xD687C46344F3D237ULL, 0x04A6F9D5A5977803ULL, 0x5F077DA2DEAB3EA8ULL, 
            0x71B52A098551124BULL, 0x4251F74593DF943FULL, 0x2ABBD7F72BE926D2ULL, 0x804619A7724893B0ULL, 
            0x1EA9B4B74A97531DULL, 0xF5661075C00D79C6ULL, 0xE6799C0E3812606DULL, 0x375CFCE0EE6F9AC8ULL, 
            0x6DEEE5FDF9053553ULL, 0x6995AA83F366DD4BULL, 0xF60976324C70501CULL, 0x390899743A1D3C5CULL, 
            0x2ED3EBBEBBDD4B07ULL, 0xFBB2112BE1924AC8ULL, 0x3D77F9FD3FB3CEEDULL, 0x6F44B7D4B5ECFE1EULL, 
            0x1EB653359BEDADC0ULL, 0x22970F8E3B5AA998ULL, 0x2C4E8CB9703EA2B5ULL, 0x717C68474AC50584ULL, 
            0xA7ECA96290764948ULL, 0xFF8E738E92AC23F3ULL, 0xAA84F4BF787E0089ULL, 0x59BDEA649E82C221ULL
        }
    },
    {
        {
            0x45170BA60C38218BULL, 0x59505FBCE9C17649ULL, 0x136CB4187D43FF6AULL, 0x3C042A82B2FBDCD7ULL, 
            0x7DF8AA4217B5C999ULL, 0x193EF4C333F9B57CULL, 0xFACC9672C17C2845ULL, 0x8A37F6E07FCCD681ULL, 
            0xA25C597C6218E616ULL, 0x2FEDB0118454CB0DULL, 0x789E74E89C9E9301ULL, 0x2FC784CE5001EEE3ULL, 
            0x6B730855FDC9A212ULL, 0x8D30842A5BABDC32ULL, 0x877722449DF92AA5ULL, 0x264EDEB9F40EF678ULL, 
            0xBF20CF9A376546DCULL, 0x2450122D0FC065D9ULL, 0x36D08525B8BF70B2ULL, 0x3B7DAD864F534D5BULL, 
            0x5BB0DC0A95DAB45DULL, 0x459EA37861BE4287ULL, 0xC6F80206B5044BACULL, 0x047A1298945A3C83ULL, 
            0x4868ED8EA83E2BAAULL, 0xD69D8D3FBE554BD8ULL, 0xB90D64B3F1741143ULL, 0x0499CD74B558F81DULL, 
            0x3700C4D89D502BACULL, 0xFB795C10EE5D61D8ULL, 0x1510383210E545EFULL, 0xF44CC97F57E90419ULL
        },
        {
            0xCA3D4DF37337B078ULL, 0xA4799B693D718D76ULL, 0x30A8196EEB1DB8C4ULL, 0x4F2CBB28DFFE377FULL, 
            0x2FCDFB23EBDA18EDULL, 0xDE78AAC091AABDB4ULL, 0x0C4E122FF194454AULL, 0xF5907AEFDB463AB7ULL, 
            0x117F122069D3B038ULL, 0x0E0F1725F169381BULL, 0xCA53EAB58C741B09ULL, 0xF05C29B6F959685EULL, 
            0x16ED6C1C85F40273ULL, 0x9DA91EF34867941CULL, 0x97AD10528E38A5AEULL, 0x491BCD4A3A2D9016ULL, 
            0xE05931158C8CE156ULL, 0xFB201C765A1151A4ULL, 0xED81D833FFC565D5ULL, 0x9A716B15A8F3060EULL, 
            0xE009B28A47BFDDEEULL, 0xECC68E6B78DB500AULL, 0x48A05E2A7A0A7EA3ULL, 0x99C3CB4442FF6B52ULL, 
            0x17743A2BC05498ACULL, 0x48321A84E58AAC9AULL, 0xC9C9DD2E053D509BULL, 0x801A6C34D39E426EULL, 
            0x51ED0A86FEA822CCULL, 0xF02AC0D415AA9210ULL, 0xE62EC5A9FF1B048FULL, 0x84B3B8E1C167C7A1ULL
        },
        {
            0x99B20712FCCC50D5ULL, 0xBF1136788693BE04ULL, 0xAB2B5565620F0DB9ULL, 0xCBC198F45D40B969ULL, 
            0x733B2B862392A8B1ULL, 0x4AE54C8125464D52ULL, 0x16D2470F1EC98FC5ULL, 0xE3105D2A3791F68EULL, 
            0x9EC36374322366F5ULL, 0x5D4B151A101083EFULL, 0xD90CF7725A98B44EULL, 0x7D13E46F390DDCC9ULL, 
            0x3084CCBF759913B7ULL, 0x6B2AFB5FFBC31AF1ULL, 0x5F007958E1CC4F0DULL, 0xEACF9DCCB1B5B200ULL, 
            0xE8038F90E184005BULL, 0xAF3011D476F4EF68ULL, 0x935F8005C4EA3FB9ULL, 0x252CC3E52383536CULL, 
            0xF4DDA67D8E5AC782ULL, 0xB6653B2C42AD3A0FULL, 0x1B8AA722DE40A7C2ULL, 0x524DC17029EF7F1EULL, 
            0x7B2D1398F7CE0E03ULL, 0x684993A808D41C19ULL, 0x32F8F9562AA49601ULL, 0x6FABD6D791EFEBB9ULL, 
            0xE3D7EE8440BEE80AULL, 0x15C62467F5896230ULL, 0x9B09670DE16CDF48ULL, 0xEEC6F2F02889EABCULL
        },
        {
            0x2D5DC63F66862AFEULL, 0xB36FC934CE909034ULL, 0x7DE3342C019D7E6CULL, 0x3FE66E90080DF628ULL, 
            0xC1F3F218329928A2ULL, 0x021689D6BB300AA9ULL, 0xC97016035730E626ULL, 0xEC04B731AFE1F87EULL, 
            0x06487A60F5E8814CULL, 0xF3AF613919C8C3E6ULL, 0x50151F24DE050B28ULL, 0x12DA946B188BA2E9ULL, 
            0xBEF222EF8113D240ULL, 0x4598A3AC97E1010EULL, 0xBF22A4AC560D684CULL, 0x87005AD41120DE3AULL, 
            0xC50E2B62F900343AULL, 0x4795CAFAE496E7E5ULL, 0xBFA713FD81CD595FULL, 0x0859265A3EDC3A61ULL, 
            0x5FBBF7D0C885E733ULL, 0xB81A9A993636F10DULL, 0xD25965C6533F8A75ULL, 0x94C396EC0D1E8934ULL, 
            0x80E4444E1AE32F80ULL, 0x256EB36D722F20ADULL, 0x2E9F48BF9A136EC2ULL, 0x4272ED2CF59E207AULL, 
            0xA9D5C5664487A59BULL, 0x04D8A422681A8A72ULL, 0x8D352DE5B23E3AD1ULL, 0x0624926E49C704DEULL
        },
        {
            0x9F5A494AF0BF23F3ULL, 0xA9CFC17B56223455ULL, 0xE93395226F86772EULL, 0x0327B47448A40B47ULL, 
            0xC9CD87D78B6FE931ULL, 0x0C0E7AD2AC28A534ULL, 0x19D7966764CF78BAULL, 0xE2DFFB477096172FULL, 
            0x037FA860B715559AULL, 0xB5EBB70757B9EE26ULL, 0x91A7DA7107217A04ULL, 0x58CA2C1933E52989ULL, 
            0xA6FE104CD8F9D8A2ULL, 0xCE7CDFE6F8580E00ULL, 0xEAF70781D6D4011BULL, 0xE3EDA8FC5F231CFCULL, 
            0x83624C6D838B98EFULL, 0x54C89C9FEFDBECECULL, 0x2BB90F0975A03CF6ULL, 0xB94C922BE6401880ULL, 
            0x35678F9B14CE42A4ULL, 0x28DD32B4AAEF4D73ULL, 0x8394A3800772E8BAULL, 0xACA1A19B4BAFB689ULL, 
            0x5A3FCB81C2BF96CCULL, 0xCF88F923381EAB8AULL, 0x29B91CD79105AB7BULL, 0x692D829111C89348ULL, 
            0x6AEE529C3EE364B4ULL, 0xDA400702A016CF65ULL, 0x2D519FB0D52A343AULL, 0xDB4AEEF9C549CADDULL
        },
        {
            0xA00B0DA417037983ULL, 0xF3D3CC0850EA052AULL, 0xE0B1471C3EC0BC91ULL, 0xB0E0A61583624AE2ULL, 
            0x5EA6D38B5E21C991ULL, 0x258056664CA4E4D4ULL, 0x0D18F2A2B6FD1618ULL, 0xF49A6A925D9C208FULL, 
            0x62567B0C6B68E9EFULL, 0xF87D84695573973AULL, 0x2E44F5B685E5DB8CULL, 0xE160003A82FDCEA9ULL, 
            0x460BA600C08EAB2FULL, 0x44F4BB9B2C0EDD88ULL, 0x16BD2946D699BC58ULL, 0x6DC8EBF03D8EB71DULL, 
            0xE6E8C9CE9EC2840BULL, 0xCE9A4631C5AD473FULL, 0xAD438041383F036DULL, 0x9EBDFB1A88CA00C0ULL, 
            0xD2D02F5BB6A84740ULL, 0xF405003CD7B3474AULL, 0xB98032A62BD43968ULL, 0x5C09B5C99255A06EULL, 
            0x1D083A4D807A4857ULL, 0xA54162506F250455ULL, 0xD13EB695CE524D44ULL, 0xFB044D614F9B81E9ULL, 
            0xBF9A88BFEEF802BAULL, 0xB42980DFCEBB4C47ULL, 0x4932519FA99BC173ULL, 0x4D6893805C245185ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseDConstants = {
    0x22EA61FB0D5AFD4AULL,
    0xE29924B08BCC006EULL,
    0x124A486EA1025828ULL,
    0x22EA61FB0D5AFD4AULL,
    0xE29924B08BCC006EULL,
    0x124A486EA1025828ULL,
    0x13108DC893AC7286ULL,
    0xF8CB6FEEDD4526CCULL,
    0x87,
    0x66,
    0xE9,
    0x45,
    0x15,
    0xD2,
    0x8A,
    0xDB
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseESalts = {
    {
        {
            0x56DA73038B73F36DULL, 0x8AE64F045D1701ECULL, 0xE454545219749A2CULL, 0xDE407656CF0A9C90ULL, 
            0x8C75F79E85671503ULL, 0x08116C082AE896CAULL, 0xABF0354F29128312ULL, 0x9E3980CA8B5808EFULL, 
            0x22F06140A17A5533ULL, 0xFE845F697C915545ULL, 0x86A011B2F3A09C13ULL, 0x0297DD3DC6290B20ULL, 
            0xB61EC75E59CB8760ULL, 0x614A4FB3DED03EDFULL, 0xA0020546FE05A564ULL, 0x45CD23EE73469D2CULL, 
            0xAFFC5CDF9BCFEE66ULL, 0x36B846A58BB7135CULL, 0xF40B9B6C9E0D8DFCULL, 0xC7064D27343D15CBULL, 
            0x834C028E43A7BB9DULL, 0x2CCE848CB8FD4B3BULL, 0x70E63EDCAEB78E00ULL, 0x9CC7E1CA0D9B6254ULL, 
            0x518902A74C2F161CULL, 0x2A93DD53B658959CULL, 0x428CF19BF0D201EBULL, 0x4DD27E63B01D556DULL, 
            0x06D719A571D2CA5BULL, 0x0C8A3E163F9B497CULL, 0xD57DCFF74D029D67ULL, 0x34C3BBE27E7F6664ULL
        },
        {
            0xB391C56FCCBDBC8EULL, 0x15600220BCF8A3F9ULL, 0x237D782639F047D0ULL, 0xEB8EE1C34202C6F8ULL, 
            0x11BE664EC4F0024CULL, 0x8587CB94A8FAB185ULL, 0x59F1C86DC012BCF8ULL, 0x9CD93CB6FA4BB988ULL, 
            0x7B2BC10EDC785D42ULL, 0xC853FFC794177AEEULL, 0x17A74BE6F22E4FCCULL, 0x1502DE386B935D94ULL, 
            0xDD6CEE4D75473BA2ULL, 0xF5EB7AE0D84244BDULL, 0x49345005F7B13E56ULL, 0x1F5864751E691253ULL, 
            0x05790977042D52BFULL, 0x432B8245283A211DULL, 0x0D4D9A813083900EULL, 0x2EF5BF91C976FA0CULL, 
            0x566FEE2BE0E18750ULL, 0xC75EF1D39DE74D5AULL, 0x98C2FCA401BD8F93ULL, 0x160AF4E4EF2F60BEULL, 
            0xAFFB4853AC85BAC9ULL, 0x5C9C38AB8361AD04ULL, 0x746D4ED8AF441C17ULL, 0x2895D3570335C41DULL, 
            0xFE8BB68D0E61AD11ULL, 0xBBFC5B0E347904B2ULL, 0x336BFABFC2E3D282ULL, 0x07FB3DB519994115ULL
        },
        {
            0x2456FE32C6AF06BFULL, 0x424EF25451956E44ULL, 0x1E02A64B6F3B307FULL, 0x968FCAD30B1BCB68ULL, 
            0x6611644CC610ECE7ULL, 0x19B064D6ECC5D67CULL, 0xAA3166024BC40274ULL, 0xB19064FEC0A183EEULL, 
            0x94947BA0C5FA6BC9ULL, 0x1D7A76312B7C7327ULL, 0x821A29418F6DFA6EULL, 0x13485FA4D963F5F6ULL, 
            0xE2F8B2705F71D8F0ULL, 0xB17E953914EA44A4ULL, 0x5EB45F7CAE379A15ULL, 0xB5AD5F02E14F09DBULL, 
            0xDF29A6184784193CULL, 0x0D0434CFBC93F85CULL, 0x8403C42866E620B9ULL, 0x585F031762F11805ULL, 
            0x830EF1F25C9C6316ULL, 0xE29C2441EAC90502ULL, 0x633362576891BE52ULL, 0xF1A71DBCAE41DC79ULL, 
            0x8733E5E25451F466ULL, 0x08FA6D60DD10CDB5ULL, 0x230D94EDAE5351AAULL, 0x46860C3489782DFEULL, 
            0xC404375C017E543CULL, 0x051D7243164C70FDULL, 0x53F2E3018D746A6FULL, 0x1934CBBA076546C3ULL
        },
        {
            0x3610DF84D4F4C75FULL, 0x1DE45F227BA6EA06ULL, 0x17C14225DD6BD96CULL, 0x0207A5618C8DF4C1ULL, 
            0xBDF5D727E07233EDULL, 0x8FD3B8426A26CEB0ULL, 0xF4D4B2D252A3E589ULL, 0xDEF9666202B5B98DULL, 
            0x69B2BB89DD9A8990ULL, 0x7DED70390A7E9E8EULL, 0x440EF27E2B3855EBULL, 0x8E6B5C8BF2F7202EULL, 
            0xE369485E20F5888CULL, 0xDE24D81591E7015EULL, 0xD7EF16800D62861CULL, 0x98F3AC3C420DA821ULL, 
            0x4CB0F72AF6323517ULL, 0x7104B8B848B8D01CULL, 0x3C9A1EEC983460E0ULL, 0x33F4A4DF7F6370B1ULL, 
            0x3A948B3531B6C626ULL, 0xD1EA7104C7E1F889ULL, 0xAE50C2A9C3895407ULL, 0xAB13FE56E951E202ULL, 
            0x5A90EB039668FC83ULL, 0x0065ED7B6DAD340CULL, 0x24446A9020919C27ULL, 0xFEA65DDE6FCAE782ULL, 
            0x9D6D8E03DAC727E5ULL, 0x183A1DAB42E5BF67ULL, 0xAA68BAA82A376FE4ULL, 0x79990DAAFFCF2167ULL
        },
        {
            0x2468171EBFDD3B38ULL, 0x70F5425B71805891ULL, 0x472C310AE599BB6CULL, 0xEDC86E7CD8680103ULL, 
            0x87B1F071C3AE0269ULL, 0x68FB3C6C761B5A2BULL, 0x8A5464548C0A72DCULL, 0xB235053079B45253ULL, 
            0xB50089F6B8C37284ULL, 0x500ABEE1DD75B453ULL, 0x804F450B05302A87ULL, 0xDDE071DC88C9FABBULL, 
            0x1935A5C4B1F7A677ULL, 0xBFF8FB58739F23CFULL, 0x410D410ACAC5A4AEULL, 0x7DD5AA5659B8FEFFULL, 
            0xF59CEC8F1885467CULL, 0xD0F6B17B88282331ULL, 0xAF0D5B02BC3D6D52ULL, 0x7D84CF5AEA68F1DFULL, 
            0x7692A30C91CA8175ULL, 0x9BC4F9138B996889ULL, 0xFC8299B8941B6B3CULL, 0x20B99B6E857397EAULL, 
            0xE009AAB734DE6F35ULL, 0xA6AE9EC7AA6DC5C0ULL, 0x976B9CFBDBB1A56DULL, 0xE4660A5D4BE68F8FULL, 
            0xE0C670DC99575DAEULL, 0xD3FF192144511965ULL, 0xE9C0A3B7D9FEA675ULL, 0xD553C6B47B3E0983ULL
        },
        {
            0x5B5ADC5AD0F4F840ULL, 0x99FF7F03358E3364ULL, 0xCD452FF00D26E2CEULL, 0xE09227A279BB145BULL, 
            0x313818E1BA469E99ULL, 0xCBCF7D441D0C3772ULL, 0x5F625B33746F6659ULL, 0x37D3F049A6503CB8ULL, 
            0xA5520FBE779EBA56ULL, 0x362DB6BB11C6B038ULL, 0xE18C2851302484A6ULL, 0x6AF9D789C13BEF03ULL, 
            0x9EBE8E4C69F2EEF8ULL, 0x3B21B22D9169BDA7ULL, 0x7C4C7D24AB088239ULL, 0x81B8B297A3C9F566ULL, 
            0x636592E49163F310ULL, 0xF75F1E3305BE2762ULL, 0xDBC85FA1E664D3D8ULL, 0xEC71954894941C3FULL, 
            0x72F753A7881C7AE0ULL, 0x0D093776F6F2034FULL, 0x5422D4D37675DC1DULL, 0xA40D08CCB55F49CAULL, 
            0xA8E2007741F2DDD0ULL, 0xB069BD0ADF659B2FULL, 0x9A9A38922D8CF221ULL, 0x64A118A5EE13A06FULL, 
            0x1DEF2E07811C2347ULL, 0xCFC32CCB31FA3078ULL, 0x77BE2C9C7E5F6C2AULL, 0x8D74F47029313373ULL
        }
    },
    {
        {
            0x92EB6FAEF8954B3BULL, 0x7E4B8FF1CD7768E7ULL, 0x5A5AB3909AACB0C2ULL, 0xDAD73948277FCF85ULL, 
            0x93EFF38BA176C83BULL, 0x2A789BB16EAB62E1ULL, 0x55C89693A1FCE170ULL, 0x3BBC504BCEC72A4AULL, 
            0x2DC7AE5E46985E2FULL, 0x91045983111942A3ULL, 0x798809CF11A496C9ULL, 0x833DC2295F1B759AULL, 
            0xB9FAA373EB87675CULL, 0xAB46B2506D44E0B5ULL, 0x7EA89E2CD610708CULL, 0x6737C43B850C1B53ULL, 
            0x728D8313717C7985ULL, 0x872A9BEFD0A19D1AULL, 0x90F9A7FD33C66F1CULL, 0xC4E7E243042142FFULL, 
            0x5C311393255F29E8ULL, 0x6E8CD407475F4356ULL, 0xEA680EBC18622B1AULL, 0x6A710A3BD249B0F1ULL, 
            0x5054AB818F9E1AC1ULL, 0xCEEDFFA78B659D82ULL, 0xC31069E831BC14DAULL, 0x8EF8074E8E56CF28ULL, 
            0xA081E1D0E88C27C4ULL, 0x563084682541E0A3ULL, 0x3965F0C4C4CF414EULL, 0x4A620AFE97342806ULL
        },
        {
            0x2A462E427AA5E4CFULL, 0x73624968DB2CFCB3ULL, 0xD6836388B7AFA8A9ULL, 0x875640459767C952ULL, 
            0x3AB6F98671C6C0ADULL, 0x4022CF975C40F440ULL, 0xC43E217AFECC5EECULL, 0xDB23C1DEF7102340ULL, 
            0x4628CC1BC5CAA741ULL, 0x03A03DCEC67A830EULL, 0x0D441980D94B1A10ULL, 0xF1BAF295F5FAD387ULL, 
            0x5185ADBF23E39822ULL, 0x0F0F0D50DF47892EULL, 0xE36C784A84C5FD5CULL, 0x3C9B9905C311B265ULL, 
            0x76D2B60292D7EC38ULL, 0x8CE322B51BAAEB71ULL, 0x3E8A5794134F9E9DULL, 0xE1CFFAA27BA62DD0ULL, 
            0xD85540E5592E3FF8ULL, 0xD5A5F7CEC9DF6EBEULL, 0xB5D68DFAB1B31D00ULL, 0xE0119079E5BCC8BAULL, 
            0x8C99A4D2891F4294ULL, 0x8E555990AD469FA8ULL, 0x209FE17D38FFAD94ULL, 0xF3EC353B171822D6ULL, 
            0xB5C1B62229B46516ULL, 0xF5AF3FBB0A3EFF17ULL, 0xD5FEBEBF52FE14AEULL, 0xC1A0A8296167ABB3ULL
        },
        {
            0x182D3806778F170FULL, 0xB762D8672A8B7976ULL, 0x481D8A52F413AE87ULL, 0x780BE258C6A835C4ULL, 
            0x7E60765217793A1DULL, 0x2AC7C2E833DB1B6AULL, 0xBD2EB3FD5977B013ULL, 0x6789E9C9EA97760EULL, 
            0x193F8B0D4E108FADULL, 0x455DD973B80F5C0BULL, 0xD7762AD2AD2180ACULL, 0xADB4DDF1ADB5E8E3ULL, 
            0x01D42D48B8F74F65ULL, 0xA7BC26F7A3C6770AULL, 0x60B0C99016906489ULL, 0x1ADCC34344EB2F8DULL, 
            0x80FC3A1F66102B88ULL, 0x00B9226A638A0B68ULL, 0xC66D51E2A67512BEULL, 0xD33525AC90A4A4EFULL, 
            0xAAB1D6CADD859FCDULL, 0xE218FC82A64B0F5FULL, 0x4B10C5E9429E7F7AULL, 0x5B06AB3B8CE2C291ULL, 
            0x21ADA7395381E29FULL, 0x14AD98CADDFAB2E5ULL, 0x088EEBBA3986BCF3ULL, 0x57F9BF813DEC3861ULL, 
            0xB778CD552EBF4C6FULL, 0x1D26F7FA2B07C070ULL, 0xA252C77B8CAA52C2ULL, 0x941B61E5E5F4B8E5ULL
        },
        {
            0x166F3B01F54F6729ULL, 0xC3CA958C6BF9F2DEULL, 0x0475880B81B9C987ULL, 0xA6AD15F5EF76B4ACULL, 
            0x25B149128F7EE270ULL, 0x79BDFB321D4EE153ULL, 0x754A76C01A01A002ULL, 0x38163D0BB06086CDULL, 
            0xA032DD5FED857009ULL, 0xD7DED41DBBDDB9F2ULL, 0xE7CD8BD96028383AULL, 0x7E948A3AE1D0E576ULL, 
            0xE2EC0B0BC1E6E767ULL, 0x0911246370884B70ULL, 0x38DD4C488CF067CEULL, 0xAF7AA9C79658E0D8ULL, 
            0xD00B20121CBB6137ULL, 0xE4446B103E19DE87ULL, 0xE8AE63973056B294ULL, 0xB807905B291B94E5ULL, 
            0x7370ED82B15658FAULL, 0x610DB57DF519B8FBULL, 0x75D9D50EC01ADE88ULL, 0xEA5BA3B1741F9AA9ULL, 
            0xAE246334378ADE39ULL, 0x19CBFD22CC9E5177ULL, 0x021C1566BF0E593BULL, 0x7B7C8AC2F52192CEULL, 
            0x5FB2F3F0F39946ACULL, 0x92E8DD6D30CC9CB4ULL, 0x00015DBABCF154F1ULL, 0x747AC35EA85B5FC1ULL
        },
        {
            0x84B3F72CBB3A397FULL, 0x7BE977F66A3EC836ULL, 0xC54C86C7DCA6F464ULL, 0xE93E12B32FDD2E02ULL, 
            0x1ACB60E92727C4CBULL, 0x3BB27DFAED71868DULL, 0x9D6C615D2C1F5D3CULL, 0x1C8E9C458111DCDFULL, 
            0x07493ADB6A92F9D7ULL, 0xFEBBE1DD21D053D3ULL, 0xC57A011745C99E75ULL, 0x5F081015FCFE3CA5ULL, 
            0x78CDAC454D45F7D5ULL, 0xF78A6E79DC7AC5FBULL, 0xACC5844608E53EBAULL, 0xBD6AD5D6D02BECA6ULL, 
            0xBB97635C5A3CFDCEULL, 0x3DD46EBE2906CF3AULL, 0xA414BF197F9F7804ULL, 0xD7D24CD49EE3284BULL, 
            0xBFEE59E0F46456CFULL, 0xB7A1275ECFB58EB2ULL, 0xC5B3211BB80E1608ULL, 0xC9DE1E58436A08B1ULL, 
            0x990BDF356CCB0290ULL, 0xABEB9494E5B8D2F9ULL, 0xCA8E744CE96A0A3DULL, 0x8EB8EF78F6D00953ULL, 
            0x864B16BE7249B221ULL, 0x2C2DF51D254AD36AULL, 0xE9B467C3E213B045ULL, 0xF28E8CC033B6EC85ULL
        },
        {
            0x7F8ADA8E2F84ED52ULL, 0x1746514AE6F81E85ULL, 0x63151971F2FAA888ULL, 0xB342838933B38277ULL, 
            0xCA7121236CFA528CULL, 0x5542AD8B8E484F8BULL, 0x5EDE99576F2F3F87ULL, 0xDDC6B4F7899DE6DCULL, 
            0xCB0B119BA7B0FB4AULL, 0xD144B6E938010A7AULL, 0xD5E20130964F62B2ULL, 0x196954065C2FBC72ULL, 
            0x1A87F6919F972E7EULL, 0xE01A2955CF664BDBULL, 0x84CC1CEC365B50B1ULL, 0x7A294ECAC88182BDULL, 
            0x6B2F92F6B3612E2AULL, 0xB9450FD35BCDD820ULL, 0x2C2C1D598F70E2AFULL, 0x610C7D9F4A975041ULL, 
            0xCC2F5A3770696575ULL, 0x5B139211D66882DFULL, 0x88D52CBA72EE7FBAULL, 0x4472CDB3BFABD6F4ULL, 
            0x100C2FAC252FEFD9ULL, 0x2A6F55A7453BE303ULL, 0x3857DCDC148A40A0ULL, 0xA32F29F14768B6B9ULL, 
            0xB783A03D9C2C5040ULL, 0xBB3339F8E9D8FC12ULL, 0x00A2C4F80637ADC7ULL, 0xAB6090B16035E9AFULL
        }
    },
    {
        {
            0x6149AD6ABEB4EADCULL, 0x77BED57FE6C29795ULL, 0x75885304A5E1BE00ULL, 0xDB4D3E38028855B7ULL, 
            0x969E879DBBCAC1BFULL, 0x1765FFCC44FDFE81ULL, 0x79E78E2C004609ACULL, 0xB0C384096A954B79ULL, 
            0x4AFC4E8759EADE71ULL, 0x2624303D4C9DDB13ULL, 0xEA22E71D23289970ULL, 0xFBEAAD5ED3531380ULL, 
            0x128237D7A4C12F82ULL, 0xE5EE902D2D664190ULL, 0x1549A0213280BCA2ULL, 0x3E3984C4287D842BULL, 
            0xBA5F966E5A48924BULL, 0x36566E300439770CULL, 0x7FE9EAC44F36C58AULL, 0x7066E6F4FC6FDC49ULL, 
            0x79BC013F0301D1A2ULL, 0xB47EB036928CFF98ULL, 0x5081CFDB6598DBF5ULL, 0xED1E0100D50017ECULL, 
            0xCF888CD18A838063ULL, 0x43DDB97C2B47A89EULL, 0xBBA775EB5623F2B6ULL, 0x81422BA68083CE4FULL, 
            0xB66536B27105FFD1ULL, 0xE4409335BA972BBEULL, 0xD517BC3D7846B7F0ULL, 0xA600BE9964D70539ULL
        },
        {
            0x832ACBDA6EA04397ULL, 0x2A0695C921BB6F4FULL, 0x2322FB5038D38A51ULL, 0x0F9BD2A651D415F5ULL, 
            0xA9AE38CD36C3D914ULL, 0x9E964149B0CE61EDULL, 0xB361C0DE785EFAB8ULL, 0xE1DB79E419644D1DULL, 
            0x51B9209C2F34A732ULL, 0xAF1F8CD22A0D68A7ULL, 0x27B6AC9182BE14F5ULL, 0x29D6BB927F6624A8ULL, 
            0x7311F7C85923AA79ULL, 0x8C983E055BAAAFC3ULL, 0x176C621762B0B9C3ULL, 0xFF7C03CBDA179D87ULL, 
            0x206AD8D003138E5EULL, 0x72AA9E097755A3ACULL, 0x7AF6664F905F83C1ULL, 0x60C45BAD572B9827ULL, 
            0x38B7C6AD890AAFF7ULL, 0x3F9B5B084FA1C903ULL, 0x7C1F6527A3D27C9AULL, 0x384BC6D9DE3CB9A4ULL, 
            0xA711ECCED30A2930ULL, 0xFE979EFAB3506349ULL, 0x84637259D0C1C28EULL, 0x7E193037EF4D1C66ULL, 
            0x467471083EBB605BULL, 0x61E2097865CF2516ULL, 0x3B6C704D6F7577E0ULL, 0x34984DD79C8F0F0FULL
        },
        {
            0x28EE96D577CB2F0DULL, 0x072F81AD4A3008F1ULL, 0xC3C3DCD5026E4C35ULL, 0x3952CAB55F8A3E36ULL, 
            0xBFF0B97D5286717FULL, 0x2BF0C9E60FE139A4ULL, 0x235904099F5CCB6DULL, 0x47EA4E34C1174F84ULL, 
            0xE59A5AC8DA86E66FULL, 0x2A4EE042E746E122ULL, 0xA9949255C283FA73ULL, 0xF05DE94501D9625CULL, 
            0x142A9E5845F9B51BULL, 0x5385673F8C1978D6ULL, 0x67C3D86640DDE1B7ULL, 0x10B60D144BCEA8BFULL, 
            0x9104CC2D8D681233ULL, 0xB93F627FEA5826BDULL, 0x149AF2E94A4F5A6CULL, 0x326456070288F802ULL, 
            0x5D3F500AE52F3EE2ULL, 0xBB27A2AF1D2819C5ULL, 0xE2F0149EA8FFE0FFULL, 0xC02298AD8B2ADE4FULL, 
            0xC5F61D6D751C2A7AULL, 0x53B844480A8C7750ULL, 0x81F93DFD114DCF2AULL, 0x70D031D4A9326CA5ULL, 
            0x0BF69522A18DB5F1ULL, 0x1B084757D55149BDULL, 0xF3A659B09E00D50AULL, 0xFE08D6D2FC53823FULL
        },
        {
            0x53826D6067D48B56ULL, 0x45D9DFED527A6EFFULL, 0x4458B568A89896FDULL, 0x04D56E4D848047B1ULL, 
            0xD0A212FCD008690AULL, 0x0BCBB379D331F64BULL, 0x1B5DC1F0801B44A0ULL, 0x3201C1645C4261B3ULL, 
            0xD56916185F0B4C75ULL, 0xBA87E67001922880ULL, 0x2C0F61769E166506ULL, 0xA7320DC40E595A75ULL, 
            0x99C4D132A9AF0733ULL, 0xEB5A218ACE49B4C5ULL, 0xD39D1604A0C147D7ULL, 0xCFEC8B4929FDE8ADULL, 
            0xA439AE071222811CULL, 0xBEC642A0DE3A2555ULL, 0x5C9EDDF1A42BAFEEULL, 0xC40161B75B4C83CDULL, 
            0x696F961B673CD6CBULL, 0xAF17931CFD100329ULL, 0x73F391E323370B56ULL, 0xEFAF96E446CD80E7ULL, 
            0xAA11D9D01DD348B3ULL, 0xDDC020D8D56D88F2ULL, 0x15EFCD5594B17292ULL, 0x5B5A9BD0E16BD07DULL, 
            0x98214D2EB3127D66ULL, 0x9881BDDF82A1E647ULL, 0x33879B8DF75C8458ULL, 0x35A62A78B457C767ULL
        },
        {
            0xCA8A73CCB1045168ULL, 0x319422549388B4FEULL, 0xD860534476B194BCULL, 0x222B0963473588A9ULL, 
            0x98B46C1278138BB4ULL, 0xA99846F98B00E9FCULL, 0xC7C6C9A52F9946FDULL, 0x5211542EF5AE4CB5ULL, 
            0x064279E1FA32BE8DULL, 0x5FFAE3040CB1057EULL, 0xCF60A0B2CA4EA254ULL, 0x9702A2AB7B4D0A0BULL, 
            0xECCB49C82701A551ULL, 0xE7D24A7E5E4062C3ULL, 0xB4166285CB896D1AULL, 0x6F2026061D59E224ULL, 
            0xAC322F1B69FCFF25ULL, 0x3E27B3A78A91B50DULL, 0x153FB8C051A0F70AULL, 0x1DFADDD496D09C95ULL, 
            0x0FBE86EB8DF43BF6ULL, 0xC5BA73D48349147FULL, 0x2BEFD278A8BA4256ULL, 0x32966BF0651DEBD5ULL, 
            0x4E68B12344D29619ULL, 0xE97ECC97F1278C3DULL, 0x916BA2E83C082394ULL, 0x8CFC6CB5D9E407A7ULL, 
            0x02A2AB214F272850ULL, 0xCE9D2DDE294E796BULL, 0x905C7C6418898A37ULL, 0x7CA1CE04D7659784ULL
        },
        {
            0x22C3413DBCD81D6AULL, 0x6673386C1B24AAC6ULL, 0x41875450F2D7223BULL, 0x09AE78C7DE8E567BULL, 
            0xED05F02BBF67327AULL, 0x6D96C620F8C291BCULL, 0xAAED43E6C852FA6FULL, 0x2C1686A6C59CA1C1ULL, 
            0x99AC44AE39ADE1CEULL, 0xD16F583BFD7038E1ULL, 0x877AA25766E71E5DULL, 0xFB782948E1D4117FULL, 
            0xA0C5CFDFF1689179ULL, 0xA2D4AC96F7FF18C8ULL, 0x164E8622441D96C3ULL, 0x39E9754871402C7AULL, 
            0x5A67C6963DDE72D6ULL, 0xD22D6E43E7DDD00CULL, 0xE65E4C1FA08CE5E5ULL, 0x06849898CE9765F8ULL, 
            0x56BB9C5505220C4AULL, 0xDB3FEE13ABD3A057ULL, 0x0E7FEF74406F3279ULL, 0x04EB101924F8BFD8ULL, 
            0xC9035358038CCB21ULL, 0x1A1A4EB9314F7625ULL, 0x1012EA90CA9F1FE4ULL, 0xF3F291CC17E4D8CDULL, 
            0xC73F4A253571A2D3ULL, 0xB1D23EA4B00F207BULL, 0x867F4F7F5D9D9C44ULL, 0x96EA30A99C5D0D59ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseEConstants = {
    0x27C7BC169E4B0265ULL,
    0xC4FE460DEBCF4E36ULL,
    0xCBB2BB3CE147FFA1ULL,
    0x27C7BC169E4B0265ULL,
    0xC4FE460DEBCF4E36ULL,
    0xCBB2BB3CE147FFA1ULL,
    0xD0FD48C7C9EE979EULL,
    0x3E3EFA66CD3D7F9EULL,
    0xE5,
    0xF4,
    0x91,
    0x21,
    0x84,
    0xD6,
    0x74,
    0x0E
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseFSalts = {
    {
        {
            0x5ECFD33509E08B77ULL, 0xA896024B1206DAE4ULL, 0xBC25F184D41D2FAEULL, 0x2D9E2849E97DCBA9ULL, 
            0xA6570E05CB3B0302ULL, 0x89A75ABAA7605BF4ULL, 0xD0D6A945C0050F07ULL, 0xEA958EFB1476A939ULL, 
            0x0BD536C1902A6902ULL, 0x42A20337F41AC2A2ULL, 0xA466AFF698FBB399ULL, 0xB18FF06D3FEAAB76ULL, 
            0x6D9C6EE1A4AD6A55ULL, 0x9ECE006B28582A00ULL, 0x9CF086E8FE60FE98ULL, 0xB01B26E3E3B7AC67ULL, 
            0xAD732B7A7D2E1621ULL, 0xD58700A2F5F75D12ULL, 0xCF65378F631FD23EULL, 0x4440A94E4EB70F1BULL, 
            0xE2F18738B0459A5BULL, 0x3049CB17C66B73B9ULL, 0xD9BF57F74CC6B720ULL, 0x0BDD4DCD677A1647ULL, 
            0x7ABC11E6E9D6BB32ULL, 0xE435400BCCADFC02ULL, 0x475B8E61F4362E98ULL, 0xAD60248F6C3C015FULL, 
            0x04C9573F9988E815ULL, 0x3A266FBD4EF213C8ULL, 0x5AB6A237E939BEA0ULL, 0xF6094562167C49D0ULL
        },
        {
            0xB6699217D62F3289ULL, 0xA4C5814FD587564DULL, 0x22EC2458DFEF8621ULL, 0x4E968B1A8C5688F5ULL, 
            0x445505CF9118C0DAULL, 0x0E78F56B936E9A72ULL, 0x38BC1BD2494DE191ULL, 0xAE2A23564026D5BFULL, 
            0x5AD31C77B25554DBULL, 0x649C4D5FAEFEEDA7ULL, 0xF0BFCE40E96D3E88ULL, 0xBC12A8640878D79BULL, 
            0x7F7FCD623FC3AC4AULL, 0x6777E2C1FEEBDC88ULL, 0x114D45B044741A3AULL, 0x05D0379C920AAF79ULL, 
            0x15FFB68E0BA6D955ULL, 0xFE164153D3C7AF58ULL, 0x97C9D49828327239ULL, 0xCE91B26C8501FCB7ULL, 
            0xD78BC6F75658E106ULL, 0xA95BEADD6FDC4B24ULL, 0x7E017929FE39C070ULL, 0xD434BFE9E7090C74ULL, 
            0xEE026B2F5D4DE487ULL, 0xDF6418CBC7F69CF4ULL, 0xA2B908827222DC16ULL, 0x84A98A2A16FA4C96ULL, 
            0xB4E3F25A2D9FFAA7ULL, 0x4F0668336413F6A8ULL, 0x764CBE7FF1E3A102ULL, 0x418C8D90AF57E454ULL
        },
        {
            0xDFA8578C9BE36001ULL, 0x849D84A51F3F624FULL, 0x0CDCA9F374445D12ULL, 0x76CD031AE25E725AULL, 
            0xCD34675F63CF64EEULL, 0xDBC5C390655197C7ULL, 0x146861E9A48A60FBULL, 0x2FEEBBED625BC04EULL, 
            0x2AB4821805187944ULL, 0x44EF0A06CE65B397ULL, 0x30152F3CDD188E5CULL, 0xF52AC4D66ECC5651ULL, 
            0x90C59603B2D39283ULL, 0x46BDF154B36BB6A7ULL, 0x3B89DD682FD0CD36ULL, 0xC3CAC13C896DAA91ULL, 
            0xEF7453823291FC06ULL, 0x5E53A2BEF7D670D2ULL, 0x9C7797464B70CE16ULL, 0x8BC97B00835552AAULL, 
            0xFBD9178B96167980ULL, 0x979F7E5C0DDBFA0BULL, 0xCF746B7EFB5F9474ULL, 0x5838BA8E85BA5DA9ULL, 
            0xDC193D6C96726043ULL, 0x9A7E743CCEDE3CE2ULL, 0x0711B75D13F7F519ULL, 0xE6D6E186A8F013F5ULL, 
            0xB5D15F7F6B82272AULL, 0x77E2D33D277C9522ULL, 0xDDC2900A3A8C4C1DULL, 0xABCA21176514F440ULL
        },
        {
            0x223AF332B944B60FULL, 0x2034B0301C4545E0ULL, 0xFE149508F0A95D8AULL, 0x3FD5B905C3A56D7DULL, 
            0x178717234A76B040ULL, 0x24237F5F35B6C248ULL, 0xA0DE1699B7A9551FULL, 0xE64B5CACA6481881ULL, 
            0x16B56088B2D083C4ULL, 0x9C80CBCB450C69AFULL, 0xD7CB9BD0155D752CULL, 0xB7110B510752B94EULL, 
            0xC4988F50284911A7ULL, 0x2CFBBCFCDD85F21AULL, 0xDA14BC575A723203ULL, 0x8D5F38D431A70EB4ULL, 
            0xFA90D240AA0A5C98ULL, 0x107619676E355A13ULL, 0x92EC656F5C903F7BULL, 0xE902A6BDDFA89C5DULL, 
            0x921CBA8DEF1553F7ULL, 0x4B9F0ABD4C28E6C4ULL, 0x1DAD4F35264EA345ULL, 0x0458630347898ECDULL, 
            0x493FAE8616F652CEULL, 0xD04947DAE9D59868ULL, 0x3853040EBD9298D2ULL, 0x17A03D41388615CCULL, 
            0x97E5D09EC6B2F512ULL, 0xCF09256B17860526ULL, 0x7A41D57A329F1767ULL, 0x6BD5BAB63A8F0EBCULL
        },
        {
            0x23B18207167CA9AEULL, 0xCFDDE86A071530E8ULL, 0xDFECB40E92EA6A9AULL, 0x75EDD63D8B1B3E13ULL, 
            0x4AA49D964A621B1EULL, 0xEC1E92C62674421CULL, 0xF0EBC07CEA50A940ULL, 0x8ABADD009C496B08ULL, 
            0x3C761D9F7BE6FA68ULL, 0xDE366CE0857DE5C4ULL, 0xE9F91542BBFD8782ULL, 0xF73484CC40289138ULL, 
            0x7F86AE412AF1EFCBULL, 0xEF9FB7C6844F6B6EULL, 0xD393ABB6D254D3E5ULL, 0xB301EC18947104D0ULL, 
            0xD24DAE4594BA4D48ULL, 0x90C45F528D736CC1ULL, 0x6AE03768FFCFF926ULL, 0x90226F297209BD1AULL, 
            0xC049AA6EB9A152E2ULL, 0x69759CB3839E1A9EULL, 0x166FC77D7E2A49A0ULL, 0x171A18B8EC5BFC63ULL, 
            0x91056F217697D4DFULL, 0x785EEC4B19B4FC85ULL, 0x90571EFED0DA58F8ULL, 0x958689F7AA9E6F11ULL, 
            0xB6DD826CDA4240E6ULL, 0x6BF03935EDAFF305ULL, 0x26343EB64A5E4BA2ULL, 0x30CF3DA5F12823D2ULL
        },
        {
            0xCEAEB80F9C4227CAULL, 0xA9464EBB712253BEULL, 0x0F83B59CB218E59BULL, 0xD0AD394CA4BA2DE8ULL, 
            0x049EA9A5F9D626FCULL, 0x9B48196E893C993EULL, 0x94B543E5A59651BBULL, 0xA0FE8BDCED84D0F4ULL, 
            0x211F29CCF53985B2ULL, 0x89603561F7A8F765ULL, 0x79509B479A760B66ULL, 0x239D8006988064BCULL, 
            0x4A8C15AB35625C07ULL, 0x1E5139DFD7AB649CULL, 0x2893C1BFCD105EF4ULL, 0xB957DABC9E5D0CCCULL, 
            0x18D5776CCA941E7EULL, 0x9AD7E97359EDD746ULL, 0x4E9822C5C3B4F478ULL, 0xF99414A78D0B27F4ULL, 
            0x6F2F72B4CB6B416CULL, 0xE58C5B1348A37E8CULL, 0x4E673CCCA9281A8AULL, 0x5DEF562C478BA261ULL, 
            0x0D09D7D0164B6907ULL, 0xBC07FBEC1BA478C4ULL, 0x699BD52F7EE0450CULL, 0x5ED57FB8512A36ABULL, 
            0x8C6887D963B81508ULL, 0xD5954DCE40F704CBULL, 0x052E397C4D110219ULL, 0xEE99567A5A1D7269ULL
        }
    },
    {
        {
            0x89D4FC201C771B4CULL, 0xC6C5655C6830789AULL, 0xBDB20B126381A957ULL, 0xC9C7B28B8BA8E6AAULL, 
            0xA1E6563B70FC566AULL, 0xCCD69BC1B7899D8AULL, 0x744F8D45F0CA6C32ULL, 0x34A06DE9637752FDULL, 
            0x2EB89DFFFE7B15E6ULL, 0x5B49B9D11F12F4DFULL, 0x74E4F6B24CADBAF4ULL, 0xA00C4346CC8E7CC7ULL, 
            0x5AFE544359A543F4ULL, 0x48518DEAA9160D38ULL, 0xC48420E4C76236B2ULL, 0x05B07434AA65B35EULL, 
            0x400A5F1374ED233BULL, 0x8FD1F3D57B84AB5AULL, 0xD34275BC5E3B3B20ULL, 0x08496ECE92343342ULL, 
            0x79E7A5979ECBB876ULL, 0x385EF4B41B6A01E3ULL, 0xF1C6C35F70558941ULL, 0xB95032E55F01BCEBULL, 
            0x7D0548059044BC1AULL, 0x63997464667699F8ULL, 0x2518B173D5F9C7CCULL, 0xF373EF2166BF093CULL, 
            0x9446964F7F73544BULL, 0xEBC849AA5C493EEFULL, 0xDCDBA7EBB777D382ULL, 0x6C6305C349CAE4D3ULL
        },
        {
            0x331C2211848E0154ULL, 0x3FC2735A30207F64ULL, 0xBC6BAF491ED10DCBULL, 0xE135403683959A8FULL, 
            0x7F27235DB9C83703ULL, 0x467D89F4C4E3ACBDULL, 0x0078DE58BE7B1F2DULL, 0xE2F7C1D2E18B0ED0ULL, 
            0xC1E6AE26F6A09B29ULL, 0x62EFA52AF4AAF5F6ULL, 0x6F482AFF848A1E1CULL, 0x0EDE2388BC466D52ULL, 
            0x941CA7A97117E527ULL, 0xAF6F5F5EFE721558ULL, 0xDBE3FD734513CCD5ULL, 0xAC5B04D921A38C99ULL, 
            0x26412DC1B1AE90D7ULL, 0x7F519337C292F1DCULL, 0x0DB035FEC09AA241ULL, 0xE6522C6AF293159DULL, 
            0xA8FE50A1817233B3ULL, 0xE419A21BE61F54C1ULL, 0xA92E33C5A169392DULL, 0xFD775971ACE2C433ULL, 
            0x94642BFEE8F29C7EULL, 0xABC1027B66A10C61ULL, 0x70ABAFBB1417C7EDULL, 0x38E948EC9534BA3BULL, 
            0xD648C81E6CE5EFD1ULL, 0x49049BE0AFE68696ULL, 0x5004A1A56A224D16ULL, 0x08D173172E13899AULL
        },
        {
            0x1DC7C632ED275B37ULL, 0x5C7176536278EE2BULL, 0x08886D01A3A3B394ULL, 0x9FB3E5163ABB1521ULL, 
            0xCBF599B4354875F0ULL, 0xA47677B4E22C1C2DULL, 0x48AA149F341C9DB2ULL, 0x21D7A14B4AA8811DULL, 
            0xF8445F5C9E8C31ADULL, 0x403CA1A9B29E82A0ULL, 0x71FA0465CEE26C52ULL, 0x0611E397BE065AD5ULL, 
            0xBC86E13FA7A1BBBBULL, 0xAB1D27452CB84149ULL, 0xC83DD2DA5694DCECULL, 0x06F776B35509B8A3ULL, 
            0x7AAE0B8DA565C091ULL, 0xF772DD6C1DFCA4E3ULL, 0xB410D1D9F4D5E85AULL, 0x8A762F29766D948AULL, 
            0xF89BADA2DEED8B5FULL, 0x463932C44767AA32ULL, 0xB8620378DA02799DULL, 0x401CE3341E92D7F6ULL, 
            0x9427D6DCA1B1BFDEULL, 0x5FAAF31F9F0B8D8EULL, 0x9F24A4504F2CF480ULL, 0x6DADCB6A56ADFE6BULL, 
            0x2EE8DB09E38896A7ULL, 0x175E0C9E02D8389CULL, 0xD359662D7801CC8AULL, 0xBBAD334DE848D8D5ULL
        },
        {
            0x87CCBBB60402B596ULL, 0xE329E42416C8E5C2ULL, 0x3129F7C052DC0DECULL, 0xB17014D3A6683E1CULL, 
            0x1A763DAA55089603ULL, 0x6EDAE515D12BBB3CULL, 0x2655031DD991EB05ULL, 0x068B75291BE4C426ULL, 
            0xF27F0B859DF4A0F7ULL, 0x69C6FDAB4CFB8579ULL, 0xC68CD628CC8B288CULL, 0x435613E29F721A80ULL, 
            0x85A2C99C74F721E6ULL, 0x30ECFCCE63FF6E5CULL, 0x291EF4EEEF6E8216ULL, 0xD087DCAD15C8B7FFULL, 
            0xF0C329A47304D499ULL, 0x6964D6ACD6F7AE79ULL, 0x49C893E2FFB47E0AULL, 0x6F2649BB664185D7ULL, 
            0xBCE2D073EB3FCD53ULL, 0x8E39166714CC8CDDULL, 0x85877255B98C172CULL, 0xD702CE4C9DFE1B0FULL, 
            0x016F6730C896A85DULL, 0x5CB21DF28BC5A510ULL, 0x18E1D5D674348EFDULL, 0xA4873D6F7C8ED0E3ULL, 
            0xCDEECE870572A620ULL, 0xD6E4AF46BCB6A6F3ULL, 0xC3DCC573BA49667BULL, 0x44598D0D408758A8ULL
        },
        {
            0xF0B6378C05019E9FULL, 0xA3CEB82C6855FC9BULL, 0x960658A317A119F2ULL, 0x4C41AEE23DD352B6ULL, 
            0x0644D31F04EE7670ULL, 0xFBEFEB7C18C96EFFULL, 0xD6AAC07B97B2594EULL, 0x7A4E55E697A0CB12ULL, 
            0x767C0AA483F30013ULL, 0x5C488055B7552F1BULL, 0x20237D7EDC551107ULL, 0xD103C420D861BC6CULL, 
            0xEE51427571F08780ULL, 0xB8C5423AE3C35218ULL, 0xC767E9150CFE584BULL, 0x9C8399B8C214581AULL, 
            0xACE73E03CAADEE8EULL, 0x4358D346021D915FULL, 0x4B27C8DB72B0D103ULL, 0x7038D3FEDF89617DULL, 
            0xF09876B281611CADULL, 0xB3918EDD595D6C1DULL, 0x05CAE825155E7D72ULL, 0xE753B114267FFBDEULL, 
            0x21572219DB422B82ULL, 0x7DF3BB86294E3A56ULL, 0xCCBAFCF5E12F0FB3ULL, 0x514D79371452D5CEULL, 
            0x494DCBFD5F454984ULL, 0xD03913E8CEC82891ULL, 0xF96DCF622FBE591BULL, 0xA55B83CC7AC7036CULL
        },
        {
            0xC10E59D9B9926F8AULL, 0x6E2B668912924952ULL, 0xC54B2761D14358F9ULL, 0x3B52510403F893A5ULL, 
            0xD7D3935385AE3399ULL, 0x3D72D2441DED1930ULL, 0xD34850977D2C42C3ULL, 0x66CCDF4AA03DBA1FULL, 
            0xA965AAD19A75F573ULL, 0xC6FE336D3958C637ULL, 0x085104E18DCA3B88ULL, 0x928896017B11510CULL, 
            0xCA4FA3057FE36D9BULL, 0xC867DEB54FC866D9ULL, 0x3EF65BEF19BD3820ULL, 0xAD5F118DCDF686A9ULL, 
            0xB27454E65E9C29F3ULL, 0x41D6C6BABD87D1AAULL, 0x2190F91D59E5D5BBULL, 0xFDD940CB98C184D1ULL, 
            0x54CA8D3999A3E6B2ULL, 0xDD6ABAE9379D123CULL, 0x768055123D95CF88ULL, 0x951603DABFB9B83CULL, 
            0x3CE9917BB0D21B27ULL, 0x769CA722B42ADF6DULL, 0x5835CF3A1681E0B0ULL, 0xEA6DCBD42464D987ULL, 
            0x1ECA2AD541426C3BULL, 0x82F7E208560A434CULL, 0x5747A7AC1E277776ULL, 0x76BD4AD4EF5969A3ULL
        }
    },
    {
        {
            0xC1461A81BC978B2EULL, 0x37C3C5B9369C0A90ULL, 0x088C19EEAA35302EULL, 0xA94D8DF23988D7F2ULL, 
            0x5461B72597B0CE59ULL, 0xAFF165D759F279D7ULL, 0x585A609D07984A9AULL, 0x1ED0721FC045E696ULL, 
            0x4102F1D1FCFF4480ULL, 0x0C43415EAB1AF4DAULL, 0x456CE6FED1A09C9BULL, 0x69F9A31EEA4B2C64ULL, 
            0xF49801156CC3E022ULL, 0x570EB238EBF11C7CULL, 0xFA9439984DB78F17ULL, 0x1A052963CCCA64C5ULL, 
            0x5535CA6E86C9D8ECULL, 0x87BB344A07E0B191ULL, 0xEBFAC9D7746068A3ULL, 0xDFA297C86EC54E71ULL, 
            0x0487AB4BBF6F20C6ULL, 0x9BEE0F18A57FD6E9ULL, 0x679D63621690FCF0ULL, 0x94A891A382546128ULL, 
            0x885642EB223EEDCFULL, 0x2BD7F74BC08CF439ULL, 0x4B025D8F294642D3ULL, 0xFDD5306D2F65742AULL, 
            0x22927909016677B1ULL, 0x5E35E63620C102BBULL, 0x6FB9B072A3BA0279ULL, 0x9D7C784FD392F5E1ULL
        },
        {
            0x4AEAD817714AFEA6ULL, 0x7AF59521907584FCULL, 0x073C7927B6D67C0DULL, 0xAC4AC0CDAC17A2F0ULL, 
            0x6CA9292399C32373ULL, 0x8487E27C9F74106CULL, 0x4A9F1043CD8C2994ULL, 0xA818A04B31AB7905ULL, 
            0x7E463531251D6BE2ULL, 0x649B6765CB8B6ED2ULL, 0x16BCB103EC0FA0E4ULL, 0xAC43B29C11A25821ULL, 
            0xD9E0A413E450A9C0ULL, 0xD4BB6CAF445BEAA2ULL, 0xD548163279467AB3ULL, 0xBC322B39A92E7523ULL, 
            0xB474885CFC5AED73ULL, 0xB0AB48365741B88EULL, 0xEB1B8898FF927A8DULL, 0xEDCF973445F224F1ULL, 
            0xAAFF19168D7B9356ULL, 0xA0BB3E7554801AF8ULL, 0x2431CFCFB4C1F604ULL, 0x4CD44BC093CD230CULL, 
            0x68E18A5B75FA8477ULL, 0x109C44C84E9C1887ULL, 0xE11A2552304A3EFFULL, 0x1B2BEFE21CF58950ULL, 
            0x4F3CD3DF5C951BEAULL, 0x0FC0B9E7783DD7F7ULL, 0x27CE86C7CA8D5E49ULL, 0x0457936934ED2F03ULL
        },
        {
            0xF7A806CA54E073C3ULL, 0xE7468FAC67C5AD2CULL, 0x4BACDF506074BB74ULL, 0xB4C7427BF23353BBULL, 
            0xD6FDAE8883309063ULL, 0x1E0E214AFD4F1180ULL, 0xB2F637E86A30030CULL, 0xDF4C4DD493A2CE45ULL, 
            0xA1EA2DD61351FD89ULL, 0x219EF20E7C434AF0ULL, 0x7307501410885D0FULL, 0xF97572112DD1C193ULL, 
            0x1F4D51F7AAC5B9B3ULL, 0x136CC77218A7ED45ULL, 0x7CCE3AF39382E50EULL, 0xD925033159FF3781ULL, 
            0x575D118D698C8932ULL, 0xFCCDAC8CD7A704D7ULL, 0x9E280669F1C81CCEULL, 0x5173C3D56AA2B594ULL, 
            0xF7BBBDA3DB12A4D6ULL, 0xC45D7FA01EF28351ULL, 0x2854A20BEBA3D974ULL, 0xDD4614CDF1A00AF8ULL, 
            0x318221B76758319EULL, 0x4F99FC7CCE8A3E8FULL, 0x1EA411FA3D055029ULL, 0x91E3EDD537939D80ULL, 
            0x2CDA839CB56F611AULL, 0x39B1DC75E0748AA4ULL, 0x352226ED20550F63ULL, 0xFAB72551AAEC29D9ULL
        },
        {
            0x4AE31F078C0FF588ULL, 0x5B08D5E312B1F8D0ULL, 0x8FF78A2C2AE22500ULL, 0x37FE6A4C86DDBCD0ULL, 
            0x43C931AF1413F894ULL, 0x5913B32A3BB9E3EDULL, 0xEED3EB4B8DBFFE55ULL, 0xCA1AC107B179D8CCULL, 
            0xF6562D850AD36390ULL, 0x5D6254EDD8EA8FFCULL, 0x259CA2D48E465B4CULL, 0xDCED7340A4EE961BULL, 
            0xE0FBA3B7C772936BULL, 0x09E518A0572F49A9ULL, 0xC8F8F6D5D1D6EC84ULL, 0x5D8B2BD24319E1F7ULL, 
            0x028CBC5547E3B44CULL, 0xE0F43C8BB4BEA0ECULL, 0xB24B25AB70DE4AE4ULL, 0x16402B106CC29FC3ULL, 
            0x7723D8F3FA8ACEA1ULL, 0x86E6A7B7E5FB3F0AULL, 0x69E474C74FC0D77CULL, 0x56D78C35CA052C86ULL, 
            0x4FCA9BFBD3769198ULL, 0x54445949BE487809ULL, 0x94EB799663DA5F96ULL, 0xA23C92BF68C76732ULL, 
            0x019FF6AB0D876637ULL, 0x5631349BF68A245AULL, 0xC1139624F0265B3DULL, 0x5B439404C37BBB57ULL
        },
        {
            0x99F3605B9679418AULL, 0x5050EB38A1DDA6C2ULL, 0xE7BAEAB81B1E4B7EULL, 0x25ADF640821B1933ULL, 
            0x4469CC2F83BAC01DULL, 0xB263172877167D68ULL, 0xDAD1E94E0A061D2EULL, 0x9703F27703505274ULL, 
            0x92A4726D6CA97A4EULL, 0xEF9D54E5BD0AA164ULL, 0x8CADE270D325837CULL, 0xF3ABB4C2D6F5625FULL, 
            0xFB388D4F359C4444ULL, 0x71D615B4B2CB613EULL, 0x52B87C94230702B4ULL, 0x065178973296DC8DULL, 
            0x4876D3AFDA9582F9ULL, 0xB17E3EEFFCE84814ULL, 0x873DF30AF0B47EF2ULL, 0x15B6C54830D16E47ULL, 
            0x0EC151D6CBD19F41ULL, 0x7525825D53A42616ULL, 0x787A0B40FE440F87ULL, 0x2CB557EBB6513EB2ULL, 
            0x1951961EAE617BE7ULL, 0x65C8ADA1A4CF1734ULL, 0xEFA4E7811DFA7F23ULL, 0x41FF23CEE266D4B6ULL, 
            0x1B11F604D4DA3AB9ULL, 0x8F88A33B4512DF51ULL, 0x16B117871443B27EULL, 0x3C3D4527A4B8C5F1ULL
        },
        {
            0xAA098EAEAFF03F2EULL, 0xCB5FC52904073AB2ULL, 0x31BF264E11C2AD54ULL, 0x6939C0B5657D583FULL, 
            0xC01C90BC98F84C1BULL, 0x234CBAA35D9D2BB2ULL, 0x845B8C48DA64F825ULL, 0x9BEEAFB84A0ED8D8ULL, 
            0x128C23832A635947ULL, 0xA54C3E81DA274A90ULL, 0xA35CA2809F28F036ULL, 0x11858B7E22136F6BULL, 
            0xB6342C1B44DDE9F5ULL, 0xF4D3357C998F3BABULL, 0x5F87EB4F46432C15ULL, 0x93048D63CFE4B792ULL, 
            0xC50D8538F66D0B75ULL, 0xB8981AE0A6B5C11DULL, 0x9DEEC1D54F1A6062ULL, 0x786FF83E9023297DULL, 
            0x86B030599B2BC28CULL, 0xC281342BEE5CD737ULL, 0x44C3351F3C288D85ULL, 0x2A914E1CC3B1C833ULL, 
            0x39E2B2DDCF4E7107ULL, 0xE134D4C780393EDFULL, 0xDF24FCD73C06BE6EULL, 0x3E41012514B48C20ULL, 
            0x44E545940DF5908CULL, 0xB0A6A5F4F9DA6011ULL, 0x306168CE1592BB9DULL, 0x4B422DC549514987ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseFConstants = {
    0x355709CA1583ECDBULL,
    0xB52B1A445F865960ULL,
    0xB1755FF5A4B7720CULL,
    0x355709CA1583ECDBULL,
    0xB52B1A445F865960ULL,
    0xB1755FF5A4B7720CULL,
    0x00179FDEC3AAFBE7ULL,
    0x5400E4EE08A08C46ULL,
    0xEE,
    0xB1,
    0x50,
    0x14,
    0x32,
    0x1E,
    0x21,
    0x49
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseGSalts = {
    {
        {
            0x2246CD8322641ED3ULL, 0x78FE67C6468D3EFFULL, 0xF2F993F61FBB6D64ULL, 0xD225DD8C464C14D9ULL, 
            0xE37AB334F90040D3ULL, 0xB24E72B5E1194556ULL, 0x295B12BF220D94E4ULL, 0xA2F77A7B8FF76132ULL, 
            0x974C748501DB93A3ULL, 0x234085072784FDF3ULL, 0x28D7AC9BCF769870ULL, 0x48AD18AC45CDCF82ULL, 
            0x1691B5BE5880BAD8ULL, 0xC5F127DFBADAC379ULL, 0xAF8E04C604BF511CULL, 0x74283481E1EE1FA6ULL, 
            0xAF6649EB01982F38ULL, 0x0857EC37FDA4F4A2ULL, 0x32D2204DFCC45395ULL, 0x96B25ECAC75C8B84ULL, 
            0x693177A91A711CB3ULL, 0x018E0F1293A48681ULL, 0x2A0FCE1D1E59419DULL, 0x555576A01E30C404ULL, 
            0x6E2E5BA8CFB2112AULL, 0x2934BFCC1D350AEDULL, 0x0712E116583D7092ULL, 0xC55B6FD80484EB76ULL, 
            0x17C86686CCE88E50ULL, 0x9B598F8DEE67D64CULL, 0x3C276C8D939EFD95ULL, 0x075725C770D121DBULL
        },
        {
            0xE1332E3D2EDA7C92ULL, 0x5D3EBC1A9952A1B7ULL, 0xAD712D867C1587A2ULL, 0x7FC5AD8233B6C43BULL, 
            0x407E12FF8C1906E1ULL, 0xBD6C14689D751114ULL, 0xF4C86D9A3EAEDB43ULL, 0xF2276E3AA70A245DULL, 
            0x80F922913F22754EULL, 0x0B5C581692AB43B4ULL, 0xB0CDB089CB8C513BULL, 0x70D25DDE8B40080DULL, 
            0x62CB5888DBBC6DE1ULL, 0x268AD48EC2CDDCD9ULL, 0xBEE26BFFC9A1334FULL, 0xC5F2C24BC12AA516ULL, 
            0xBBFEF5C305F8B947ULL, 0x268775A18DAC75D1ULL, 0x58E23D96BB1EE53DULL, 0x55CD733280DBBAAAULL, 
            0xDB584986AD154C22ULL, 0x9168275E02D5826CULL, 0x1CA8C06A14E22B30ULL, 0x6CA6D705F8AFAE10ULL, 
            0x53E4D1C9699E8F95ULL, 0x3F93715EFC6B504DULL, 0x6400DF6EF7EC718BULL, 0x113C2413D1828D23ULL, 
            0x8215F31B75BDA354ULL, 0x1408487CFBCC79D5ULL, 0x01DE0102D33711BFULL, 0x130A4321067A22CEULL
        },
        {
            0xFCD2A80973284B71ULL, 0xC5C48D525B98DC83ULL, 0xB6B2122008BEDAA1ULL, 0xD3123E24D3CAC05FULL, 
            0xE2367D2E46359995ULL, 0x441E1DEA5CD17D57ULL, 0xD6B844B5E311F47DULL, 0xD7916BCEA6D0E1D4ULL, 
            0x0C6F7FD586FCE89EULL, 0xC809633CF9570739ULL, 0x2375F7E53C5B1E59ULL, 0x5F975E0443F3D714ULL, 
            0x1E0BED2337660CADULL, 0x255601B993341303ULL, 0x4D0812B642FDF77CULL, 0xB8811178BDCC8B1EULL, 
            0xAAED741A16758984ULL, 0xC0E63813E088A3B4ULL, 0x2BA6FD52D4825E02ULL, 0xBB308F819923954BULL, 
            0x7194E2788788ADD5ULL, 0xF2C5D92E8852308DULL, 0xBCBC25DF8603731FULL, 0x684D3DD1B9DA0F78ULL, 
            0x1C18092955B63462ULL, 0xDDEBF83B77F96466ULL, 0x1452D18E395E7A5EULL, 0x5E8FE5E45B93AE56ULL, 
            0xB21D6A569D4480A4ULL, 0xE19E1F1E636DD244ULL, 0xF6578F193BAA7183ULL, 0x5CD197EAC2DECB16ULL
        },
        {
            0x63CAFC4E01430EF1ULL, 0x9D7B4E57AFBCC656ULL, 0x9B015D84B586EF2BULL, 0x3739478E04A86E08ULL, 
            0xAC06E51C21D72DFBULL, 0x72B8D1CFAE44FFA4ULL, 0xD26F1081D79FBB90ULL, 0xA661597C13AB2EF3ULL, 
            0x4D3D5D5BBA1316E2ULL, 0xB4B3D7BC30106AF8ULL, 0x0313F3B94A5467C6ULL, 0xAF8A90626F39953DULL, 
            0x05BC075E63DA6882ULL, 0x199AF2AAEE620292ULL, 0x642D6A1E5BDF35CFULL, 0x01D547F0ED0F94FDULL, 
            0x99F9E10E91F2B10CULL, 0xD662972965F25D5DULL, 0x0EF034CF694D65CAULL, 0xCCBD59A76B210219ULL, 
            0x39A19900212A0FD8ULL, 0x4D427658E9707952ULL, 0xCCAACEC7F4036608ULL, 0x2957B3BFB8F6DEADULL, 
            0xF3C729D29BCA336AULL, 0x7BB88E8FC5853C06ULL, 0x78740A046BBFDCE0ULL, 0xF6919DAEE25EA01BULL, 
            0x223C8E42A619DC6CULL, 0x0544435CD0B8C2DEULL, 0x4FAA3D0F649A8B46ULL, 0x0C2E3493B301122BULL
        },
        {
            0x2C132396C88E6779ULL, 0x5CAFC39BA5FA0A9DULL, 0x06CE3DAC350E9DD4ULL, 0xFA6D4973BE1403C9ULL, 
            0x82A97234DD2DC77DULL, 0x0141C1113074F80EULL, 0x74FD5A1DCA13044BULL, 0x5DD1A3D19D7C0F5EULL, 
            0xAF87B053684BBA5AULL, 0x19319B2E9E2B59D5ULL, 0x28BAAD2D1511D4EEULL, 0xD8850B5CB71609CCULL, 
            0x158AF1B46E85F3C6ULL, 0x516DE62D7E4A4262ULL, 0x47B26552F937E3B4ULL, 0xAC36FB3FF75DD495ULL, 
            0x2778240345A2752DULL, 0xA3B4840632C48925ULL, 0x9C836E75A05788C8ULL, 0xFDBE6C0A83C1E43FULL, 
            0xE9FF2B728375BEF6ULL, 0x500A2E047488BC0BULL, 0x5CD4A80AF67BA86BULL, 0x856B40DF6242FE02ULL, 
            0x52CAAC82261E8363ULL, 0xCAFD823B5AA1E08FULL, 0x0B7955B0A2FE3666ULL, 0xD06057D1A5E47649ULL, 
            0xFED504AF59E4B2D2ULL, 0x5BFF3C8057D38A53ULL, 0x95564CECFB4D49ADULL, 0x763DDC7A9B2C2ABDULL
        },
        {
            0x647B503CEF46D9F7ULL, 0xD177B2ABEA046EFAULL, 0x7E34789A8A989232ULL, 0xCD121B40B7AB2321ULL, 
            0x934E9AD014ECB31EULL, 0x645A61A8C612897FULL, 0x7206713AB7B8FB41ULL, 0x4E95CFE0A746088DULL, 
            0xE40934400C3C65ABULL, 0x61E639F406B83F00ULL, 0xC97DCF14C75118BBULL, 0x8090105292580F43ULL, 
            0xFAC97DE8346759CCULL, 0xD2DC4750FCC2A653ULL, 0xF0AD4D2277100ECFULL, 0x8D449A34D58CAD9FULL, 
            0x5C08CE9F318C1650ULL, 0xC3FBEABBECD34B52ULL, 0xD4A2E1F2B8528430ULL, 0x784E3B93120B2FC1ULL, 
            0x1E2EC701EE684BADULL, 0xCB00E66CE1BE2ED8ULL, 0xD2C6D1FBB013FB27ULL, 0x711DFFC7F4388E3FULL, 
            0xF1DE0E458D90F5E4ULL, 0x37AD60308A3B5D00ULL, 0x6089D85F571FE68CULL, 0x99AD83824DD07D41ULL, 
            0x9E2589735ED985A9ULL, 0xF022E8861A8BD771ULL, 0x89E422C19822C519ULL, 0xFCB0C7F92EB73F9FULL
        }
    },
    {
        {
            0xCBF4AC56CF5EBC49ULL, 0x0AEC605AF8775F6FULL, 0x5CC9550CCB4D8636ULL, 0xE124BFBFB1D30FFAULL, 
            0xD6CF9C56487F9733ULL, 0xCD60401B8A444B51ULL, 0x44428948FE999AF2ULL, 0x6461D616E057FDE5ULL, 
            0xE57EFF0F1DF8DEFCULL, 0x0F1F5C07C5814436ULL, 0x0967C027DCFC2889ULL, 0x08967C9F734CBC4FULL, 
            0xA5BAF8E69F2CCE13ULL, 0x82F3E0086B622AC9ULL, 0xF03AAD26D57E3534ULL, 0x12CD65D1A16932DFULL, 
            0x065E66DC4BC1544BULL, 0xEFD3F95A94E26BD0ULL, 0x4AB07198DAE86ECEULL, 0x3C19895422B79288ULL, 
            0xF6A0F1D17CEA788DULL, 0x27E999F63DFC4217ULL, 0xE2340A0B18B7A45DULL, 0xF2BE04FFDCC6969BULL, 
            0x1E613D0DEC0F4AB8ULL, 0xD4311B5AF502AC72ULL, 0x328A2E187B510110ULL, 0xDC02E1BF2B88E335ULL, 
            0xB00D43DD116276E5ULL, 0x68A695C131EA7538ULL, 0x4681EC743FFE84DBULL, 0x8DECDE4F58DFC423ULL
        },
        {
            0xFCC6BF2201A6F322ULL, 0x7A755C46766D7092ULL, 0x40BA44910EF9DABDULL, 0x7FEB02548B392262ULL, 
            0xDE482DD6D7F58EE3ULL, 0x18CD7574706E4955ULL, 0xB9A412E6064F6126ULL, 0xFD905A8887D32494ULL, 
            0x986736CAAECC8D3EULL, 0x82951C90A46742E5ULL, 0x35E1B801FA68DA9BULL, 0xDC56E10E9FE33CF8ULL, 
            0xF15446F94C7B50E6ULL, 0xAA6F1EA12CC44A15ULL, 0x7936463714014C02ULL, 0x1CE9FC213A05F8FAULL, 
            0x5221072FFE47D62BULL, 0x6868B2622DE802CBULL, 0x4772E62AB5B9A42CULL, 0x76CB41E0A849000AULL, 
            0xC596D5061773D4A0ULL, 0x26685E63E1FBD01AULL, 0xCA2206F2F07A2016ULL, 0xE124BDEC3D4B168CULL, 
            0x32D27EF4D3C00D75ULL, 0xBDA64424743D5B29ULL, 0x7F7733C4666195DEULL, 0x78068FEFFAE5B37EULL, 
            0xF81E564C7929F881ULL, 0xC2CD7C8CC82EA868ULL, 0x0D3140BDE849F3A8ULL, 0x57D556A87375A5B6ULL
        },
        {
            0xED7DCA71B7DAAF3FULL, 0x754A535D3A189277ULL, 0xE51987BCA8FA41ADULL, 0xDCD3FC9CAD989382ULL, 
            0xF31738A155643498ULL, 0x8C84F117EECCC1F1ULL, 0x9239B72DB09D07F0ULL, 0x35D6945AE8563629ULL, 
            0x899555C9E305CFC9ULL, 0x3C8965E5118D4739ULL, 0x3290700F127DDFE6ULL, 0xB98FF259E7CFCB42ULL, 
            0xC4D9C3D46D01057AULL, 0xAE7CE79281732736ULL, 0x57049661011C1A93ULL, 0x1AE40C360A73D81CULL, 
            0x42CEA30AA37117DFULL, 0x45F3A059669731D1ULL, 0x7ECD42D775849138ULL, 0xF7DE4BBCC5726E64ULL, 
            0xB2B4B0D49DB749FEULL, 0x28D5304A77149B24ULL, 0x3B4133AB138C8394ULL, 0x1B97E3756B43B478ULL, 
            0x63B780CBBD614EFCULL, 0x220BF54A3857D29DULL, 0x7F720C456BD16353ULL, 0xA384FA6AAD40AB1BULL, 
            0x193E0FF9873D47F2ULL, 0x967D4FEAE45309B8ULL, 0xB49444C54819B8C9ULL, 0x2B02EDFDD5302D94ULL
        },
        {
            0x107AC10142B64CCBULL, 0x80A8F196729FA414ULL, 0x19CF8CD5E7F91ACEULL, 0x12B47A9ADA5D87F7ULL, 
            0xFBB87B017EB8A23EULL, 0x582482550A17DE9BULL, 0xC054D0FA94664C84ULL, 0xE4ADFB309EB0DF67ULL, 
            0xB009BC0228E6A9D8ULL, 0x77EA60E59F4F0CD6ULL, 0xBB74F55814688DA7ULL, 0xD695447D8E456380ULL, 
            0x423C7B64E9A78B33ULL, 0x4C042D1F2986461EULL, 0xC71F7735E3D8D181ULL, 0x49472E0280858A55ULL, 
            0x20B06C5EFC3018BDULL, 0xF054A8D8D87D0096ULL, 0xCE1E2DE50FEF2C5FULL, 0x8E93C10436D21471ULL, 
            0x0CA9D677FA38D207ULL, 0x5F02CBEE97DEB84CULL, 0xE81836A40E67A8A5ULL, 0x8AF39944C5E2C998ULL, 
            0xF0C3591B8957E974ULL, 0x4FF3A727E0E33ABBULL, 0xC01DA591E2C9FD72ULL, 0xA66D330454A85966ULL, 
            0xAD497F01C1131B13ULL, 0xAAF73C8CA9D8F785ULL, 0xE803DECD5448DE14ULL, 0xE40D22815E2ACE22ULL
        },
        {
            0x5796351EA6B94F2FULL, 0x60F1B82D3DC9235AULL, 0x9D4E8B2FDD124C96ULL, 0x32AE944A0E34AB18ULL, 
            0xF62584BA3860EB3CULL, 0x24CD537BB82EFC87ULL, 0xBBCD4174084B7F40ULL, 0x73159B0C2119D289ULL, 
            0x1D087F4DED0277FCULL, 0x5D5516F021C35F85ULL, 0x2CE86B7301BCFF39ULL, 0x7CFB33F606DF3BCCULL, 
            0xDE43E01A918A4E39ULL, 0xD358E401F0933762ULL, 0x64482D756E637184ULL, 0x19FC0FCE0A6C0134ULL, 
            0xA8A01841A12F634BULL, 0xFA99D908047CE532ULL, 0x06099F4C8B26C49AULL, 0x384F1DC02442A0AFULL, 
            0x633FE68DA7E99F6EULL, 0x951859CAA3B4672BULL, 0xB91D0658EAD9D17CULL, 0x34EB107A799D4D6FULL, 
            0x0BE7B6735A146065ULL, 0xF8F4BD0D02DE4082ULL, 0xE857032DA087DF56ULL, 0xF5A295007441D2BDULL, 
            0xB58207AA34B916B1ULL, 0xFFD8168C0EE039DAULL, 0x20D445281276BFA3ULL, 0xFF05634A858B921BULL
        },
        {
            0xE7A43F8944A77156ULL, 0xDF738826B1427B74ULL, 0x7ACF38F5E9EC777AULL, 0xABD45CB2756931DAULL, 
            0xD1369CAE14A02ACAULL, 0xD9979F8DECB97954ULL, 0xBC6992A0FF3C5605ULL, 0x56B6E14FA532E968ULL, 
            0xC9F58D01BAB4657EULL, 0x80DEA6F544BC2BAEULL, 0x2E1C9E1259EE075FULL, 0x4A6EAE2DDEEE2251ULL, 
            0xEB19483A65112262ULL, 0x2D0B6C580380380CULL, 0x6809B51D90758D62ULL, 0x696AE8B4CC02B22BULL, 
            0x4AF2590B3FA9F335ULL, 0xE23ADF4A9BA61681ULL, 0x2632D8602DDD5741ULL, 0xF4338D4C33FEACF6ULL, 
            0xB93C2EF1730232DEULL, 0x7D6806F3B43F8F7BULL, 0x92DC8E764FC94DB3ULL, 0x9F4FE178053394BFULL, 
            0xBC4C64E291AD8C91ULL, 0x9F89F1A915822619ULL, 0x0EE17AE1F0BCBEC3ULL, 0x8A32264AC9BA1172ULL, 
            0xA5375F52AF09D693ULL, 0xAEEE04AFBE2765DCULL, 0x54217FB4896B5F71ULL, 0x1033A3B995D37376ULL
        }
    },
    {
        {
            0x0AA0593EEE144B95ULL, 0x4C3BB2E94FE9E76CULL, 0xDCD82D5E3AA03E15ULL, 0x45ADF11C849E2909ULL, 
            0xCCBE61E0A0B66DFDULL, 0x593B6A7C33E4E1F2ULL, 0x0532688337B1E31CULL, 0x1EF19ACD6D3FD8B1ULL, 
            0xB6C03238685EDBDCULL, 0xBCA5D4AF9664AA07ULL, 0xDDA41BC4ECA97298ULL, 0x19F8B132DF495B5CULL, 
            0x52A7802117E47CFBULL, 0x5F003FC3C5084936ULL, 0x3BF6AC9313DFAC61ULL, 0x8111E5973FBDA281ULL, 
            0xD3B771D82B8FFA38ULL, 0xDBCBBF13CD8E2222ULL, 0x8B44718183F96BDCULL, 0xFBDCBA2014993250ULL, 
            0x3E66C1DDD38455ABULL, 0x88B75D8FF88A9A2DULL, 0xBEDE38BBC620570BULL, 0x21CE318223F86F7EULL, 
            0x42BECB6EF6C57021ULL, 0xFA251414DB67A023ULL, 0x8B822BE6AFB84337ULL, 0xC45DE408D3687B04ULL, 
            0x50378114EDDE2979ULL, 0x1C6BEE647C79ECDDULL, 0xAD4E73C76181A4E4ULL, 0xC0A7BBB2DFC41A18ULL
        },
        {
            0x72E6F85B4EE81532ULL, 0x494E9DDED30A3362ULL, 0x771666A5D04E1545ULL, 0xD3C5EFE44FA8F7E0ULL, 
            0xF8D175B95E938E09ULL, 0x1E572A5CB1F6C70FULL, 0x7C8BB5EB39A6823AULL, 0x39584404D8D34FB6ULL, 
            0xFD231EA474DF9F71ULL, 0xC9A07B9A3B1E7DFFULL, 0x72E1AA8747824F93ULL, 0x28783658C78C845EULL, 
            0x7A91F9F228AD3E54ULL, 0x415B4D1670E2ADA1ULL, 0xEC0DB90527E1D9B9ULL, 0xD2B3480906CA8653ULL, 
            0x9C87EA4A37BF20DEULL, 0x3EADCD15F30FD732ULL, 0x40F75885B7319B66ULL, 0x08039314CBF3B6A5ULL, 
            0x5F86D11DEE6985A8ULL, 0xFD11B2FCB7E560E2ULL, 0x9D4F79823FA102C0ULL, 0x6661E4C686DC4178ULL, 
            0x490EBB3507EC2CE0ULL, 0x59E3C030A8B77F32ULL, 0x7E46D29CDF20FA62ULL, 0x32921F870A452768ULL, 
            0x156C8D65E8A53DBAULL, 0x2D7C36E33F06D38FULL, 0xA179A5DBBE0B695CULL, 0x9D4A03F9EBF8E15BULL
        },
        {
            0x3F62E1B960624A40ULL, 0x9F07BF161B70998FULL, 0x55F855DEEE511086ULL, 0x6101854E0970F986ULL, 
            0xD7D9F3149632159BULL, 0xBB2596959172AC8EULL, 0x761745B8A7CD3010ULL, 0x10A4BB9E08B89660ULL, 
            0x42BA4122B10389E7ULL, 0xE490DDC2F4DD183BULL, 0x131FAD14497F3809ULL, 0xC8C9E46A436439CEULL, 
            0xE2DD8A8F3D782B1EULL, 0xBEED1C4B4D8C95C6ULL, 0x397F2850730ACB11ULL, 0xE638E025DF1136C2ULL, 
            0x53C06F740989E90DULL, 0x0F5EF1684725C6C5ULL, 0xCB0D460C7E46D122ULL, 0x7D80468BB7BEC482ULL, 
            0xBFDE610263E0482CULL, 0x04FFF8233D3469F6ULL, 0x40E1F312189E7C44ULL, 0x509979EA4469D727ULL, 
            0xF65DB081F5BE329FULL, 0x3FF5052F43DAD8E7ULL, 0x5AD2AF81FDB35E12ULL, 0xE676BD5B502DE33FULL, 
            0xFA5149C3DB914BE9ULL, 0x87E25AB523025353ULL, 0xAF9551082BD0ADB1ULL, 0xB2D75EE91BA55034ULL
        },
        {
            0xF7480AA645F647BAULL, 0x2E85E8E48C08FF49ULL, 0xEB5F2C016E00CAC0ULL, 0x09DC9AF2B7A88758ULL, 
            0xA02F7A3C82CFD9E0ULL, 0x809667EA8EB12828ULL, 0x2E12CB5D1036D616ULL, 0xFACA722882C8EA68ULL, 
            0xACFF9E77ABD45DEEULL, 0xDCFB72D4A119A2EEULL, 0x028D94EFCD4FA64BULL, 0x29C91DBA1E9F4DDDULL, 
            0x4A40620C4E4C9074ULL, 0xADBDAFF154ABB4D2ULL, 0x87452ABE18F7CA84ULL, 0x3E072D7815B77779ULL, 
            0xAF57F6AF537391F5ULL, 0x9C9D575641A1C66CULL, 0x59B0409386BA3750ULL, 0x6171299FF8903470ULL, 
            0x0648450C5C6B0E1CULL, 0xF6CA784DC0C61DFCULL, 0x29004B76258540D7ULL, 0x821C85601B140F0DULL, 
            0xE2BDEE5F4A5A7081ULL, 0x3C39E3F2454F900FULL, 0x9FBD2C09DE96C1CEULL, 0x5543379CBD02636CULL, 
            0x80E2F9D24C317397ULL, 0x7E282B902EB375E4ULL, 0xA784A4F58E3A87EDULL, 0x40AFCFF22DABCA07ULL
        },
        {
            0xF72922E323E5431CULL, 0x277A78979FA34347ULL, 0x328EB7331E6FA5DAULL, 0xCB42869AB5026C48ULL, 
            0xACEC22417742B55EULL, 0x54D2E42A6D2F8C48ULL, 0xC801EB5F2BA1FA81ULL, 0x2524E56B7E3E31A9ULL, 
            0xAD40906F80A4D9A8ULL, 0x4671D7F913FF0D22ULL, 0x803351F80BB23397ULL, 0x080AC713EC7F89D2ULL, 
            0xAB0D91B960E6C32CULL, 0x6148733B595AC933ULL, 0x7CB97B9382424864ULL, 0x9D8F0B60903CC6B2ULL, 
            0x842AF4C73AE0BF3CULL, 0x781F059D3F784471ULL, 0x3540AF57835616A7ULL, 0x4B1A0B7BB453607BULL, 
            0xC5ED4410DEA0BDC5ULL, 0xCE02439EF9B69C69ULL, 0x5F110AA9EBCF7705ULL, 0x35140C4FD8DF3B43ULL, 
            0xA751A3CEC6CF1895ULL, 0x7515FBBA1CBE96FDULL, 0xE844206DFC44E3D4ULL, 0x5B984361729545DFULL, 
            0x4760B0A21740A3C6ULL, 0x1D9E0F82E8A18EA7ULL, 0x2316EAEEB9F6D97FULL, 0xB7536FB3823BB57CULL
        },
        {
            0x499645CFDA8EB5A0ULL, 0xB1D0790AD266F88AULL, 0x16C9DB7B6CDF44B8ULL, 0x1BA9304EF0657E6AULL, 
            0x2374ADE954B2E4FEULL, 0xE43A05BC6A63930EULL, 0x7638C68028838DF1ULL, 0x0D163E7E00A34F4BULL, 
            0x97D0426F1DFDAE89ULL, 0x338BFA87CB85A55EULL, 0x8857C4C83FDA5659ULL, 0x01467D47CB30ECA4ULL, 
            0x7FB7114F52375176ULL, 0xAB139F30164EE1C0ULL, 0x31F3642CCC934BEDULL, 0xED9134F8FD5FAB86ULL, 
            0x3AAA4D5E0BC798CFULL, 0xC926E3CEFFB7ED9DULL, 0x4551FD611C1B4FAAULL, 0x44618DA42D5246DFULL, 
            0xFDC8A710E287B925ULL, 0xB02FF4BBDA6D0D47ULL, 0x96F6669FF9E2BF5EULL, 0xF4A354B6BD8C9B01ULL, 
            0x18B402E680E8E985ULL, 0x22B5C5E3F624E3A5ULL, 0xDA4B93C9F6B985D9ULL, 0xC16C5F736ACF2007ULL, 
            0x40036EE535780221ULL, 0x0F0185EB2F94313DULL, 0x532E3FFE9D34F2FBULL, 0x4D333D8CD1A1088AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseGConstants = {
    0x398599C3000A0394ULL,
    0x798ACAE99599B308ULL,
    0xF9CFE52C6C373682ULL,
    0x398599C3000A0394ULL,
    0x798ACAE99599B308ULL,
    0xF9CFE52C6C373682ULL,
    0x10702F2F50C2F8A3ULL,
    0x2F402BF6365168FEULL,
    0xE1,
    0xD7,
    0x63,
    0xA8,
    0xDC,
    0x8C,
    0xAA,
    0x34
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseHSalts = {
    {
        {
            0x5173994457E62103ULL, 0xE5BD06A539CFC00FULL, 0xA53BFEFA790CB051ULL, 0x67674BC2D352FCD3ULL, 
            0x1AC0E3C42F69D083ULL, 0xF42448E235C5E055ULL, 0x8616F825048E92D7ULL, 0x24FCCA69C2BCF418ULL, 
            0x9382F92CB28C71DEULL, 0x244654843EE7C601ULL, 0x60D1D8285596898BULL, 0x67A6AD95A04851C6ULL, 
            0x65B2F8EA163507EAULL, 0xABD89A4A9F8C711DULL, 0xABF47685459F6BDFULL, 0x9847D4183734B10BULL, 
            0x892BBCAA8011E0C9ULL, 0xE18B14317DD83467ULL, 0xFF1AA2B7636CC39DULL, 0x7F316C96DDE97FB7ULL, 
            0x2936E59AC57A2A74ULL, 0xAD69861CB1393D65ULL, 0x14D2ACE541E8A9D6ULL, 0x567AB8ECA23CB459ULL, 
            0xE949A50D04C61B8FULL, 0x7FE9CE432A905334ULL, 0x446F9286B7C6B1FDULL, 0xCDB5A39C9AB182C6ULL, 
            0xB5368E47561F0D13ULL, 0xBCC340D2FA7B6624ULL, 0xF8B69FEB2B390948ULL, 0x077DEE5EF7043019ULL
        },
        {
            0x60D4831577A57591ULL, 0x4A3162AE2C124F64ULL, 0xA38158B7BE933061ULL, 0xEDE63733AF06874DULL, 
            0xC66476C4A959E75DULL, 0x0CE8AF1ED5190D6EULL, 0x881593E8D5F6703DULL, 0xDE4EC2683051C554ULL, 
            0x44F49A779A0548F3ULL, 0x644434A52F237AFCULL, 0xBCD4545030BF80EDULL, 0xABD5552BCD7CD23DULL, 
            0x49B429DDAF1B6591ULL, 0x50BAB5E2231B09C4ULL, 0x908C2C679C7A712BULL, 0xC8548F077647F654ULL, 
            0xC4FD39332DC8B059ULL, 0x62E10D8C62D3859DULL, 0x918F5AD3E155DF2DULL, 0xD348C2C9DAC76CAEULL, 
            0xFAC5CB6F3BD10E42ULL, 0xADBFFFF55EE5ABB9ULL, 0xAB7BA1C1A0C763ADULL, 0xB3D2A3782BF0FF08ULL, 
            0xB850602513DAD644ULL, 0xAB64FD8F3F5B130BULL, 0x9B6ECC785A71B7C2ULL, 0xBA17C7D512E65311ULL, 
            0xF153EAA4D220499DULL, 0x50EEBF203A0790C9ULL, 0xC220656F87618F0EULL, 0xBBC18226954683C4ULL
        },
        {
            0x8ABC8575062FA2EDULL, 0x08FE15C901038F3BULL, 0x87965A5E7A951ED0ULL, 0x1B85A02C70B2B915ULL, 
            0x0D2C0A1004869D3DULL, 0xC9E1081E7E407D14ULL, 0x8B9557808F337C5AULL, 0xE3E902F00463D278ULL, 
            0xA0EC55FDC4E877ECULL, 0x3C0FA3F8E6B77368ULL, 0x3743547F630FAA70ULL, 0x91746F61E24E8523ULL, 
            0x661C47F4B1151BD5ULL, 0x10E97783A6E715F5ULL, 0x09B8126F2D8D7DE6ULL, 0x995C173C74725A81ULL, 
            0x5BB9A0D4F32AAF03ULL, 0x5F09D256B3A7FC69ULL, 0xB24FEE2F8A348059ULL, 0x75798A14B3839834ULL, 
            0x1D478FCCA6EDB2A2ULL, 0xC52904F61B0EE476ULL, 0x17B515A4C3863A33ULL, 0x460A42A021D27375ULL, 
            0x3737DAF8CDED6953ULL, 0x500FDA43404874FFULL, 0x55514D10AA4AD2A1ULL, 0x39F0E5ACC098854BULL, 
            0x0769AA3464FB540CULL, 0x7AF5B6B629318E15ULL, 0x36C54C99E3543ADAULL, 0xF5CE25B19B170D80ULL
        },
        {
            0xB2C40690594101FDULL, 0xDB3D422447E889FBULL, 0x4F080C82C4595774ULL, 0x91A6B89326400971ULL, 
            0x095E5AD2BEA529F5ULL, 0x47848D4F7359E697ULL, 0xC01C6B1410F13D6BULL, 0xD47D0BB7D9B1EA16ULL, 
            0xAADFFEFBC82D8657ULL, 0xEEAE609888AE1AA7ULL, 0x1BBCE25DA49746C2ULL, 0xE7D1B56E7F21C912ULL, 
            0xA72AED79CCC02572ULL, 0xEF35915DFE1F6DCEULL, 0x7360DE633411332BULL, 0xB869849F596D505BULL, 
            0xDE1380042A666425ULL, 0x53B8AA9E62EB5162ULL, 0x2812E90781E4E5DCULL, 0x6B438DCEA4241C62ULL, 
            0x84D807D80059CE77ULL, 0x530F2373838CCCA8ULL, 0x09233C8F92E64042ULL, 0x517EF95CA51AF8BBULL, 
            0x38C484CE2537CD21ULL, 0x0BEE00CF56FE494DULL, 0xBBD59A2528B4C1F6ULL, 0x001710A47E224580ULL, 
            0x402F6980013BA917ULL, 0x8AFD75F0FF8A8ACAULL, 0x76133AB64772AE15ULL, 0x191BB0F8CCDB8EF4ULL
        },
        {
            0x9112B627A70A798DULL, 0x990296F4A4E1E4CAULL, 0x350EA9F1DFD9647EULL, 0x4C5E028C558230C7ULL, 
            0x2710A7637B693BBFULL, 0x3E83FE4267377372ULL, 0x52465CD146EB31EDULL, 0x68A001B1109C931DULL, 
            0x7F632A07E237D83AULL, 0xBF6DAC9F3B980901ULL, 0x9D16743347B9F9FEULL, 0xD4F8DB24CBD0D631ULL, 
            0xB3FE37B5A79428B0ULL, 0xEE7CD54D828CA8E8ULL, 0x530525B6A117B087ULL, 0x24777B7DCB9AF0AAULL, 
            0x873BAF09239402EAULL, 0x9A9723CB96C201E3ULL, 0xE27CA7FE57C8AD24ULL, 0xF5B30C1AC7AE7AAFULL, 
            0x65E7B7410AAF0872ULL, 0x9CC47A7D6E5C8ED2ULL, 0x764DCB0FE306681AULL, 0xDB0C17DF7E735BC1ULL, 
            0x438034CD390CC165ULL, 0xD3BF392F4BC619CAULL, 0x68B405B6800FF5C1ULL, 0x0F0AE8AEDB39A198ULL, 
            0x55B5440EB8418C30ULL, 0x422F934081FF6F7AULL, 0x290CC20A1F71D4CDULL, 0xD93351280BFE44ABULL
        },
        {
            0x301EA93CECA6A65AULL, 0x7B11D124015699D5ULL, 0xC9893F80DC3195D9ULL, 0x88F116021E8045F6ULL, 
            0xA046DB704B915D4CULL, 0x23A9EA23A4E9F968ULL, 0x3D1EF38D22679C78ULL, 0x76531CF4576D50FAULL, 
            0xC8DCB6F12A0AFFB8ULL, 0x51DDF1691CCA6C41ULL, 0x3F4628BF3DB70960ULL, 0xC05B21338B1860E1ULL, 
            0x09660C87586EC2AEULL, 0xD1E74D60A932C213ULL, 0x724CDDEF336FED51ULL, 0x8C65D225FB5C8B1AULL, 
            0xAFBBF5474465AE13ULL, 0x4527B605B48E1F32ULL, 0x5EE8113C24BB0A5AULL, 0x2377A593628A8ED4ULL, 
            0xBFA6CA62BAB6F5D6ULL, 0xF0ECB4DE461EC179ULL, 0x7CAECC1AB4B43C60ULL, 0xAC89205F46CC9A35ULL, 
            0x962A91C6FA6D6FA1ULL, 0x245D34FB143AD708ULL, 0x18942F4D8CE83D4CULL, 0x13E4B138B911605EULL, 
            0x752FD2418A4279D1ULL, 0x0553E51030D21B1CULL, 0xAB77CED6E552774CULL, 0x9BF48B1E34231864ULL
        }
    },
    {
        {
            0x1331D6C8E4D2B3B2ULL, 0x872479B9B07BA963ULL, 0xFE46BA723ADAB236ULL, 0xC8D610A5BEAC57BFULL, 
            0x8C49FA3FAB206DD3ULL, 0xAB913F3BE7402D9EULL, 0xD6E8A89B0F3B7B23ULL, 0x7F835148DA8F5E0AULL, 
            0x3F7804789955AFD6ULL, 0x257E302A34E75927ULL, 0xA49641D003885329ULL, 0x2C5BDC23DB0CF6CBULL, 
            0x9412C1B734C70FF2ULL, 0x049B31F00977E15CULL, 0x62365F42BBDC143FULL, 0x9DC839C7203F2555ULL, 
            0x86720FA52CED71C3ULL, 0x026D001F98ECC8C1ULL, 0xC9B27F30CBA20AB9ULL, 0x6E49B0E7D5A6DBD3ULL, 
            0x04F1184252395D3CULL, 0xF50C011DD4D98543ULL, 0xD43AC73B7A5F68DFULL, 0xCD686C1AC13DF6AEULL, 
            0xB60FA639D08DE2D3ULL, 0x672A97908173787EULL, 0xDF9C4497BBA3ADDAULL, 0xF635C99CECD68099ULL, 
            0xAB4B03A4F4D4CE37ULL, 0xB4942BA83DEA5A7FULL, 0x22D155B6424080CBULL, 0x53B41D305462CC32ULL
        },
        {
            0xCE0656F3F4EFCBD3ULL, 0xDAA57CC2AB708824ULL, 0xCCCA3D1120C2B195ULL, 0xE6342631E29A2B56ULL, 
            0xC3D1D165278D542BULL, 0xFC53F085F89C177AULL, 0x2129719CE6BAC346ULL, 0xE39DC7B1A1ADCDD9ULL, 
            0x44E99FB891C5E7E9ULL, 0xA469D0D6DDC421A6ULL, 0x2CA1E4BC5B301B3DULL, 0x75A412B3839206F9ULL, 
            0x2042930633649D1DULL, 0xE096386F1C4B8D5AULL, 0x61B9F87B4FC2B923ULL, 0x74C333170F1A4122ULL, 
            0x888484DB90F9881AULL, 0xD31DD59F81E3D39EULL, 0xEB121A50A6664D28ULL, 0x1B7B1E5C145A3033ULL, 
            0x616B58420163C86BULL, 0xBF4F83993101A406ULL, 0xFB686C87F356C775ULL, 0x7F54E02D5F1B185AULL, 
            0xD2AE32CB424F8B14ULL, 0x2FCE6EFA89191498ULL, 0xFA40AC8BB93867FCULL, 0x24195DC3463D50CEULL, 
            0xC87ED2740BFAAF3CULL, 0x1EA4669A28E344CFULL, 0x753803FFADC8D80FULL, 0xFECB88C85EE91ACDULL
        },
        {
            0x41C52A35B4AB2B2EULL, 0xBE62A73D16409F49ULL, 0x923B6673F213E50BULL, 0x864B33838AF9FCD6ULL, 
            0x300A966E9BFBE13AULL, 0xD9EC0539E9C51FAAULL, 0xD302A21BE140A0D1ULL, 0x4D8F151FF07DEC02ULL, 
            0x3E6BBB8AACCD14B0ULL, 0x3236FFFD44819797ULL, 0x103E4B70F0873799ULL, 0xBC3EF3553E1BCC8BULL, 
            0xC32AE97891EA1D12ULL, 0x90843159E57AF319ULL, 0xF6C9F7AE2E194AA7ULL, 0xB2F261D54D003873ULL, 
            0xD79D356EE07E7639ULL, 0x3D37C15926B0FB61ULL, 0x204B00B41672D5ACULL, 0xB994FCF9BC9BA9C4ULL, 
            0xEA6EA822FCD9897CULL, 0xC96EF60FD7441789ULL, 0xA4C6D99060B33AABULL, 0x69AD5F9A3D72F7D7ULL, 
            0xE0D0534D38BD220BULL, 0x885D642A085F8EF2ULL, 0x62F104271B38D015ULL, 0x3C5C387291873EB9ULL, 
            0x3D131C17263EAE50ULL, 0xD75CC1BCD5D2D1EFULL, 0xCF60A5A024706739ULL, 0x85E7DAFE9EEF3952ULL
        },
        {
            0x5C6237DEB7563A2AULL, 0xC6A22AA11BBE8DB5ULL, 0xF39525780BB4FE4FULL, 0x732D019617310093ULL, 
            0xA49D1578D3FC5E51ULL, 0x9F1C30EE77E7AAAAULL, 0x288665D9AC1C1AEEULL, 0x9BFC4B8162134604ULL, 
            0x74184A14A9BEDDDDULL, 0x5FF9E33DC62214CAULL, 0x93236344CBFCE82BULL, 0x9C0CF73533A3B00BULL, 
            0x9DBE74CB794E3E60ULL, 0xA31119BFF9C93289ULL, 0xE8038612B81728FCULL, 0x154A07BD8CD33E65ULL, 
            0xE70A7E6C834303C3ULL, 0xD398D7F7E2DF63E5ULL, 0xFD0151C4C028B9EEULL, 0xEABA1AA520E90086ULL, 
            0xA5D2ABEA455F82CBULL, 0x3B3EAE80B5830FB5ULL, 0x64214A9BA61AAD20ULL, 0xF08991BEE016579AULL, 
            0xECDF09FE0AB709A2ULL, 0x5BF7567B4F0C6BCEULL, 0x74AF780082B49BD7ULL, 0x0544395C4143DE1DULL, 
            0xACF19E2F4E90898AULL, 0xE1989F6CFE6825C4ULL, 0x23F22F27BB70E90AULL, 0x9BB55CBB0DE16D76ULL
        },
        {
            0x7E3FF028C085C507ULL, 0x0C122EB9C130FCDEULL, 0x3DA637E82EB9CCC8ULL, 0x724200691C8592CEULL, 
            0x48E86A45A71A91A0ULL, 0xCEB9F14002606DF2ULL, 0x5072C06D04264AF6ULL, 0x87D48E174BD6A067ULL, 
            0x686DF9F884ACF07BULL, 0xC201CB677E635972ULL, 0x761F5283071632A2ULL, 0x5B9879C64E3DAD08ULL, 
            0x672B7B88FAB431C6ULL, 0xE3EE4D9A67BBDE2EULL, 0x752265D049BA0980ULL, 0x30CF124C9537ECE2ULL, 
            0xBC825E99FB98DBE4ULL, 0xC5C744186A34D36EULL, 0xB216048BDAEC6FC4ULL, 0xDBEFCFD2DA4B59EAULL, 
            0x7821CE37D6DED350ULL, 0xBC0A388005D2C7D0ULL, 0xCC7B857A57F0EFC4ULL, 0xD81FE7955C60678FULL, 
            0x4AE60F8B6A861D63ULL, 0xE6A00B33FB4C56B8ULL, 0xE26E162511E56E4EULL, 0x919F9B3FC1928F30ULL, 
            0x58151AC75E619287ULL, 0xFD5501411FAC5DCCULL, 0xA1375E658264C0A6ULL, 0x2D98DF92D189D94CULL
        },
        {
            0x99BDA3A718405193ULL, 0xC308967A764073EDULL, 0xD00CBC312A3EDA38ULL, 0xC3128362220A39C0ULL, 
            0xFC9B94B4FE1889A8ULL, 0xD95336A7B8A6CDD1ULL, 0x5AE2595CC9BACD8EULL, 0x773F184E13A48ACDULL, 
            0xD236C8B5D95341F9ULL, 0x23E8F6EAAC2EDD10ULL, 0x1C7C35AD86182DC6ULL, 0xC8CEC42567B7DD9CULL, 
            0x7E3D7894B84B473BULL, 0x6675E5B60B7ACC4BULL, 0xE59C30028ABAC314ULL, 0xD5F9D602729FBADEULL, 
            0x690AF99B9C790BFAULL, 0x115E9098116BDA90ULL, 0x32DE0B101AE79698ULL, 0x662AB8FA90C3A800ULL, 
            0x68C179F3F2F6A1FFULL, 0x6A66BEAE278C5C59ULL, 0x195A73E9B485898AULL, 0x11E27836E3B57B33ULL, 
            0x40E5D0E05BC820E9ULL, 0xE67C1413F1EB447DULL, 0x16628A3065D56720ULL, 0x63BFBCDEC8D51697ULL, 
            0xD0CD893F75F34D82ULL, 0x3F781DF0E312AA49ULL, 0xE1264C0F2539D202ULL, 0x959C92D9EDBA7792ULL
        }
    },
    {
        {
            0x3EFF3C7E159377BEULL, 0xE802D19D6942CA11ULL, 0x3093577CCE061627ULL, 0x556AFA3073214CC8ULL, 
            0x529D9432E32DB5DFULL, 0xF0189D7B2D5BBEABULL, 0x2449BDF8AEA78588ULL, 0xB9D04C12C23888FFULL, 
            0x9A80F7DB3D5FE66DULL, 0x49705D8647FF86D0ULL, 0x4AAF3EECCEA9E83EULL, 0x3AF46E0CD78F0F59ULL, 
            0x8863F8A8863265CFULL, 0x3DB25FBEDA4F895DULL, 0x87D81AE47EE64BC7ULL, 0x1E779103906E837DULL, 
            0x849E19F7C188CFE7ULL, 0xD059B7FE537D10C2ULL, 0x7416A1471293A841ULL, 0x0EFB1E159BBF1E4FULL, 
            0x51C53EC210E4F18FULL, 0x0DEE09E806C1925FULL, 0x6223A97A5ADDD60BULL, 0x5833C74B429A1838ULL, 
            0x3544A6E59C37EBBCULL, 0x51A65E7F395494F1ULL, 0xE67ABCDACE05174CULL, 0xC91F1AA4B133E111ULL, 
            0xB62D562634898AF8ULL, 0x40E3EBBD263B2A78ULL, 0xCCDD3099B0C180ABULL, 0xCE8B862D40447966ULL
        },
        {
            0x333A86FE3B33960BULL, 0x920539F696A8F17CULL, 0x3C706084B95B0490ULL, 0x812E6A7B7B2429D2ULL, 
            0x8D41F471C0ED730EULL, 0x7763B60E347A99C8ULL, 0x19A56BCC2469037AULL, 0x3153208588628A8DULL, 
            0x3034AA2F30AA8162ULL, 0xC196979CE243FE6CULL, 0x95A5B00DF73C51A1ULL, 0xA046887234D52F3CULL, 
            0xA7BF56910B78516EULL, 0x9DB860F7C067D922ULL, 0xAF6E3C6529E5D010ULL, 0xA5EEEDEC88FFB7A7ULL, 
            0x0297A27EB436AE69ULL, 0x701BEA9EBCCAB047ULL, 0xF0C61DE13DE433CEULL, 0xCCA9BD83F61CC210ULL, 
            0x6039B04266E7A00FULL, 0xF38F40AB6C55F596ULL, 0x34997B5D4270D536ULL, 0x2852FFD734D40D38ULL, 
            0xB87C093C73BABB8DULL, 0xF5B27C5040D49AA4ULL, 0x002FF5E3FE26E7A4ULL, 0x2C3DDF79E00D0663ULL, 
            0xAC619212775F24D0ULL, 0x8FC7362330DAEDCBULL, 0xECB6510FC8F8E6D5ULL, 0xE0A309933666DAE5ULL
        },
        {
            0xC6E0EAB8A4E8121CULL, 0x833FCA46DA29ED61ULL, 0x1592F9EB29BC0D78ULL, 0xA30884B3ACFB4D41ULL, 
            0x5B5D0FAF52319C82ULL, 0xB4D4FBA90689383FULL, 0x82F429D8CA49070EULL, 0x84F9F17DFCB59887ULL, 
            0x0DC07EFA22FA87E2ULL, 0x625CAD85B4993B4DULL, 0x1B7F444D30B695BFULL, 0xF442241A47027E04ULL, 
            0x13FC25432F7AB9ACULL, 0x88BB4D94412C279FULL, 0x85C0E28DB1385D18ULL, 0xE95E71989BC25BEAULL, 
            0xEC935DEC62CC26FBULL, 0xA2F840059C766A09ULL, 0x976552449A57EAE9ULL, 0x958B05CDB0721E75ULL, 
            0xD5653EF21200C58EULL, 0x7E56467E278DE56EULL, 0x6D7F14563AAEDC92ULL, 0x18D78DAC1C7FF62DULL, 
            0x669D893DB144AE30ULL, 0x44E7C7D043D729A3ULL, 0x0016ACEF05184494ULL, 0x156FA33C89DD4C9CULL, 
            0x00E32A5535C9A5CFULL, 0x65E29308B37DBFFEULL, 0x42D05C1F2E994DD5ULL, 0xBFEF5494CE4AF97DULL
        },
        {
            0x00777216C9070096ULL, 0xAF6D075D71353F46ULL, 0x3131775BF005F0CEULL, 0x773B94EA111CE858ULL, 
            0x2494EE9E0F986C79ULL, 0xD921549187F641C9ULL, 0x88B12F51E0D63F15ULL, 0x5F9511B1EA85B3E7ULL, 
            0x1F4FF09CA8E21404ULL, 0xB21FC73D224A94EDULL, 0xE74634FAEF37C36CULL, 0x50557912C2F6B30EULL, 
            0xAED41D209C92A1E6ULL, 0xFEC7FF321B3932CAULL, 0x4C8465A9EB680D1AULL, 0x3825F8E985BFA62FULL, 
            0x91F26EC6E3DA9B08ULL, 0xC20C52CC1AAC0F14ULL, 0x50FC5DFC5CFC5905ULL, 0xE14AF1289640C3C4ULL, 
            0x6652180F3AEEB995ULL, 0xB175F3EA6BE120FAULL, 0x791D33F928EC182DULL, 0x05CCFDD8125E4F30ULL, 
            0x50B948BC78236645ULL, 0xD21096C3C2A9146AULL, 0x9616585D836ACA1BULL, 0xECE378CA2FCFD4B2ULL, 
            0xBF7925039D457621ULL, 0xB3BA25738B6FF43AULL, 0x39837F3071ACA049ULL, 0x8575CE14B03EFBEFULL
        },
        {
            0x54B74C50C77C560AULL, 0xE2B19A5994C11F5AULL, 0xB0582D63BE91FEECULL, 0x679FED12BEF615C6ULL, 
            0x3137959C0CF961D2ULL, 0x70F494A15BA68213ULL, 0xF76AECC4C72C2FB6ULL, 0xFF13D376B3AD9507ULL, 
            0xC7FF978FD73994CEULL, 0x168B10B1F008E333ULL, 0x77365CC6375D4658ULL, 0x1732A3AB18A2BF2BULL, 
            0x8C66421542059CD2ULL, 0x826BD45BBDEF85C6ULL, 0xB77E134586BCA37FULL, 0x3970C16F94DE8096ULL, 
            0xFF84CB9A34170E8DULL, 0x64BD9B91ED02C319ULL, 0x68E9B01C44B7ECB1ULL, 0x127DDA0816310886ULL, 
            0x3AD64C42091941B3ULL, 0xEF576EBC3C92803BULL, 0x86C1F2994957B5DDULL, 0xD2F382A09303F1B4ULL, 
            0x805FC19FA5D37D6BULL, 0xBEF7428C06598817ULL, 0x5A1B103DBBBC71E0ULL, 0xB358C0663788E239ULL, 
            0xB03FA0766C88DB59ULL, 0xF8CCC9BFFF983DBFULL, 0x97A073DECB2FB4F7ULL, 0x79A0195100B1B61AULL
        },
        {
            0xAB4A67233EA9C0F4ULL, 0x884E30F2FF7FB33DULL, 0x410B9CE99C9E4F38ULL, 0xD0024026C0F17938ULL, 
            0xBA2F7916D84C7650ULL, 0xF53ED3F5D40C546DULL, 0x9132BF9BFA7EFF4CULL, 0x700CFE7547F72580ULL, 
            0x248985C07DDBA50FULL, 0xDE17D591D1B39481ULL, 0x382550C885C56109ULL, 0x25721533C23C67AAULL, 
            0xA2E10EE44F5E1642ULL, 0x4B8E9C13684709F2ULL, 0x45B703EC61A38C5FULL, 0x509768B77732BDF0ULL, 
            0x70068FA38AE190E9ULL, 0xC09C94AE046185F0ULL, 0xB05CCC258668D337ULL, 0xF9DBBCF079904BE6ULL, 
            0x9960AA72772FBC87ULL, 0xAE3F8C129C529582ULL, 0xADC18802014E62A7ULL, 0x20BE926A9EEA0BE1ULL, 
            0x78607E4EB4ACECADULL, 0xE9077A63FB095910ULL, 0x0F55E566C8214AE3ULL, 0x9EF88C411732D13BULL, 
            0x6A6B69D498C8C46CULL, 0xFCD3546E586396DBULL, 0x48B58B97DE6EAAB9ULL, 0xD20D1A654137B311ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseHConstants = {
    0x9D523EABE80D463DULL,
    0x64914BC8E68B28B8ULL,
    0xFBC9FC18117E065EULL,
    0x9D523EABE80D463DULL,
    0x64914BC8E68B28B8ULL,
    0xFBC9FC18117E065EULL,
    0x1070131AA193C7A4ULL,
    0x8E8358B810499E8EULL,
    0x8B,
    0x68,
    0x84,
    0x6E,
    0x93,
    0x73,
    0xF1,
    0x22
};

