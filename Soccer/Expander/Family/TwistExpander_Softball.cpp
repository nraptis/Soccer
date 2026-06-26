#include "TwistExpander_Softball.hpp"
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

TwistExpander_Softball::TwistExpander_Softball()
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

void TwistExpander_Softball::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 17859738417879659533U;
        aCarry = 11717305485640718100U;
        aWandererA = 9943883144943235491U;
        aWandererB = 10770173007965972815U;
        aWandererC = 12374276421738411449U;
        aWandererD = 12135616121840284594U;
        aWandererE = 16364083815613516629U;
        aWandererF = 17983634275314735197U;
        aWandererG = 13793066615782078840U;
        aWandererH = 17941638376986919050U;
        aWandererI = 12788142858592214782U;
        aWandererJ = 9277357997314861569U;
        aWandererK = 16673989361178915449U;
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
    TwistExpander_Softball_Arx aArx;
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
    TwistExpander_Softball_Arx aKDF_A_BArx;
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
    TwistExpander_Softball_Arx aKDF_A_CArx;
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
    TwistExpander_Softball_Arx aKDF_A_DArx;
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

void TwistExpander_Softball::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 10431974088193018316U;
        aCarry = 13695394570387846814U;
        aWandererA = 17348680395339677021U;
        aWandererB = 14983652739482026844U;
        aWandererC = 10777593981319712758U;
        aWandererD = 14250489114566656660U;
        aWandererE = 15304662708634928171U;
        aWandererF = 15151932163891056853U;
        aWandererG = 13485184413244392544U;
        aWandererH = 15585347797409024521U;
        aWandererI = 9751130812029679003U;
        aWandererJ = 9495670889693178132U;
        aWandererK = 16637259502591021722U;
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
    TwistExpander_Softball_Arx aKDF_B_AArx;
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
    TwistExpander_Softball_Arx aKDF_B_BArx;
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
    TwistExpander_Softball_Arx aKDF_B_CArx;
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

void TwistExpander_Softball::Seed(TwistWorkSpace *pWorkSpace,
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
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneH);
    }
    // KDF_B PhaseA invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneE (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    }
    // KDF_B PhaseB invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneA (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    }
    // KDF_B PhaseC invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneG);
    }
    // KDF_B PhaseD invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneB (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    }
    // KDF_B PhaseE invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneD (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseF invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneD;
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
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    }
    // KDF_B PhaseH invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
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
    TwistExpander_Softball_Arx aSeed_AArx;
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
    TwistExpander_Softball_Arx aSeed_BArx;
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
    TwistExpander_Softball_Arx aSeed_CArx;
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
    TwistExpander_Softball_Arx aSeed_DArx;
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
    TwistExpander_Softball_Arx aSeed_EArx;
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
    TwistExpander_Softball_Arx aSeed_FArx;
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
    TwistExpander_Softball_Arx aSeed_GArx;
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
    TwistExpander_Softball_Arx aGrow_AArx;
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
    TwistExpander_Softball_Arx aGrow_BArx;
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

void TwistExpander_Softball::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Softball::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Softball_Arx aTwist_AArx;
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
    TwistExpander_Softball_Arx aTwist_BArx;
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
    TwistExpander_Softball_Arx aTwist_CArx;
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
    TwistExpander_Softball_Arx aTwist_DArx;
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
        TwistExpander_Softball_Arx aGrow_AArx;
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
        TwistExpander_Softball_Arx aGrow_BArx;
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

void TwistExpander_Softball::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 0 with offsets 7735U, 372U, 1845U, 6078U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7735U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 372U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1845U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6078U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 2 with offsets 5145U, 1980U, 3254U, 2308U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5145U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1980U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3254U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2308U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 0, 1 with offsets 6295U, 7705U, 3098U, 2227U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6295U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7705U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3098U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2227U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 3 with offsets 1718U, 1558U, 651U, 260U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1718U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1558U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 651U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 260U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 3, 0 with offsets 219U, 1013U, 231U, 983U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 219U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1013U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 231U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 0, 2, 1 with offsets 1719U, 17U, 932U, 1627U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1719U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 17U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 932U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1627U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 1008U, 651U, 1622U, 1952U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1008U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 651U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1622U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1952U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 2, 3 with offsets 394U, 514U, 1415U, 263U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 394U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 514U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1415U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 47U, 1480U, 1731U, 2025U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1480U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1731U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2025U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Softball::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 3 with offsets 2573U, 4657U, 1131U, 514U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2573U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4657U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1131U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 514U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 1 with offsets 156U, 730U, 5104U, 6200U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 156U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 730U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5104U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6200U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 1, 2 with offsets 6517U, 5601U, 5022U, 138U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6517U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5601U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5022U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 0 with offsets 16U, 5695U, 3785U, 248U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 16U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5695U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3785U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 248U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7403U, 2954U, 7795U, 5620U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7403U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 2954U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7795U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 5620U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 0, 1 with offsets 533U, 1390U, 1825U, 1343U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1390U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1343U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 1, 3, 0 with offsets 1999U, 733U, 979U, 296U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1999U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 733U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 979U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 3, 2, 0 with offsets 702U, 752U, 1117U, 781U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 702U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 752U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1117U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 2, 3, 0 with offsets 1751U, 2017U, 1984U, 1503U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1751U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2017U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1503U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1229U, 2018U, 746U, 2039U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1229U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 2018U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 746U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2039U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Softball::kPhaseASalts = {
    {
        {
            0x5143DE9E270C7D47ULL, 0x83AFC8DC31945726ULL, 0xC3FE7BB7F84ACB41ULL, 0x33403C6874937F2EULL, 
            0x975D675808ED260CULL, 0x9EDCA93CA67C096DULL, 0xBF16CA3B7EEB1791ULL, 0xFEAD5D0E446D8C4EULL, 
            0x92B5DA09D0990233ULL, 0x3ED7FBD730CFB7B9ULL, 0x44FF140CC5093FD6ULL, 0xE34DB0863AA432AAULL, 
            0xCDD41C6B40F5F7F5ULL, 0xACE0056E3EF2B52CULL, 0xBAB2D5E7CD9583DEULL, 0x4AE8870A45EE45D2ULL, 
            0x029E6715BBFB7FB9ULL, 0xA9DCD15E3A3018C0ULL, 0x33F3F64BA89755DDULL, 0xB7437A13A23C1F22ULL, 
            0xDBAC46ADEA52E881ULL, 0x4CF9AADC97973200ULL, 0x189A15EC4B3B63ABULL, 0xC1CAD45B1785BB5FULL, 
            0x59712E7C0C765F7AULL, 0x9BCA0D7E644CF208ULL, 0x79D507E86E68B361ULL, 0x27D356FFE25C36ADULL, 
            0x2D8361D7880D405EULL, 0x09A63A9D96C5E501ULL, 0xB96172F8079EEF05ULL, 0x0F6E6B7091D49816ULL
        },
        {
            0x2CA4EB9B3812BBF0ULL, 0xE37D586FD51DC207ULL, 0x15C82EC6C9499019ULL, 0x29587991C4E87545ULL, 
            0x132ADB0BDB910D1FULL, 0x13D784BBFE38AC7FULL, 0x6BDD5E1B20AFDE48ULL, 0x831AD8FADA404DC1ULL, 
            0x5BCBF363B44EB2C2ULL, 0x768053DCCDAC3494ULL, 0xF94F614CC42F660DULL, 0xA53D8A9658B67A4EULL, 
            0xFBD08175E2D6059FULL, 0xD5BBC325B7168660ULL, 0xFB04798D9FF45E78ULL, 0x62AA4E716CFFB554ULL, 
            0xD4A274C8DB3D9852ULL, 0xA881CD4B92CC4BADULL, 0x65608DE4553D19E2ULL, 0xA8CC5CECFDA28231ULL, 
            0x654461691671C617ULL, 0xB588F1E1DA53F106ULL, 0xAC061E3F69DFE9BFULL, 0x65FA13A1C51D9DF5ULL, 
            0x3CBFA26C1659C4ACULL, 0x7B6FAABBB7845B8FULL, 0x29201ACACA5AD36BULL, 0x60870913CEB45459ULL, 
            0xB7FA3242676FBF42ULL, 0x6C2A81BFCC6AD5A8ULL, 0x4F54A028BE352E29ULL, 0x7822ECC9106DA178ULL
        },
        {
            0x8EA917F4F3A13105ULL, 0x3107B00F4E68A67FULL, 0xCB623294CAFC6301ULL, 0xD764DA925E933A4DULL, 
            0x618F94B1ECA511B1ULL, 0xF3545A4B87B17C19ULL, 0xED531B1DCB3B60B0ULL, 0x8711F99FA8DA82B4ULL, 
            0xB58FD35183E320DAULL, 0x0412A1D0635FCBB7ULL, 0xFA05ED2B791DA7F4ULL, 0x7A9AA73C07FF9129ULL, 
            0x5D95032741EE68D0ULL, 0xBF80FA34B3094AA5ULL, 0x05B0EAC770E66861ULL, 0x4B54B19EFABAF44EULL, 
            0xBAC646C14F480620ULL, 0xCDE0A8AA23DE2326ULL, 0x36B8902A38CF543AULL, 0x1DCA2F146F3FF3D6ULL, 
            0x33078EEC6E6A70AAULL, 0x7449503242119677ULL, 0xD239E2D86C6570DFULL, 0xBEC55131E1A0D622ULL, 
            0x7CC841399FEBFA2EULL, 0xC731A746F4D1C130ULL, 0x491F380052657E29ULL, 0x43A3C779D3F3F7EDULL, 
            0xD7C4DC333A540D3DULL, 0x770F586ABF9DEC92ULL, 0x29F72E5EEA8EDCE6ULL, 0x72F9A802ED9F7894ULL
        },
        {
            0x1166615BCCE53A92ULL, 0xD7306BCC88812429ULL, 0x81AA9F26D62C7BC7ULL, 0xB49353148C0E2810ULL, 
            0xD28A367647E62D96ULL, 0x4AD9FC3A5070DB4EULL, 0xFC200298C8694EEDULL, 0x9AE400A54F6DED6DULL, 
            0x11E283236DB37B37ULL, 0x7DDB527A6775CF91ULL, 0xB4DCFA11CC2AD657ULL, 0x1C4A065483B12B19ULL, 
            0xE92DB4D9042AAD27ULL, 0x433B25B44E6440C1ULL, 0x2B2587AA7ED815F3ULL, 0x42143088979240CCULL, 
            0xC334039E874DD8D1ULL, 0x590E4DED9160CF9AULL, 0x68B7333E92627D5CULL, 0xCE5EC2B1B95CE1C0ULL, 
            0x411962A092E26485ULL, 0x2EB8D38FE9018AF4ULL, 0xFDBCEC743CBA1213ULL, 0x79322052C6F751B4ULL, 
            0xF18E5D2AB98E1D85ULL, 0xB0DB5B26A0321BCDULL, 0x8DC7E09B43537B05ULL, 0x5B1A7B2373F873FEULL, 
            0x39209F7E06DF18C7ULL, 0x276142F0D7DFDB2BULL, 0xC4C17CA96F1DA342ULL, 0xC9B095DDC9906244ULL
        },
        {
            0xEC57BB467C6AEF66ULL, 0x856FC2691AEF47E3ULL, 0x2646DC68EEECAB3FULL, 0xE75730AEEA057C47ULL, 
            0x7C3F558FB3CDB1EDULL, 0x97D42729B1361BA7ULL, 0x4FB3FF1ECC51C7F7ULL, 0x435C88E587580A93ULL, 
            0x6B57411C8B7C6AB2ULL, 0x76B10E8CFE1CAB7EULL, 0xBD055051820F6065ULL, 0x8A2A2574DF70EDFFULL, 
            0x27DAB259D9F4C09EULL, 0x6709343E6ABC4F22ULL, 0x25D6EF5B87C42172ULL, 0x9DF4876FB74D189DULL, 
            0x964C8A3AEF0C36DDULL, 0xBFDB2A4052304C12ULL, 0x6278674D52D17BB4ULL, 0xBC93877430A4DFDAULL, 
            0xD5A0A3E8B6C26850ULL, 0x833A00712156DE2EULL, 0xF7A501493B6AB6ECULL, 0x2A1787D54E50E6F9ULL, 
            0x2CB1FED9B8B0EE72ULL, 0x637CCB8E17006CD9ULL, 0x32F9C1C0AE51AEB3ULL, 0x8524936407C5316FULL, 
            0xF2057DBE61A9BEA1ULL, 0xEE17FC489770ED03ULL, 0x9B67E46ED3039629ULL, 0xAFE550D93AD35CF5ULL
        },
        {
            0xDB2231A5EFC89F36ULL, 0x8C18FDB64F7161EBULL, 0xFC58CE0DFDADB47AULL, 0x6570DA6319088839ULL, 
            0x89457BCCCC1A9CD6ULL, 0x21810A4375A590A2ULL, 0x5BADC1667E07D543ULL, 0xFAA6516CF7F6B91EULL, 
            0xAD05D6E4B47CB2A3ULL, 0x240B19CF40DBACF1ULL, 0x53842B32418AEFD9ULL, 0xFC9BCDB118BA7D61ULL, 
            0xB752ED52D7804D37ULL, 0x68AA900D8C0A9309ULL, 0x8A3D9C1A62CBD9D4ULL, 0x2FDA2CCAD51B346BULL, 
            0x1B5FC8CE4F09B9D8ULL, 0x717BEA6B111D95B3ULL, 0xA5A77F836F30BEC6ULL, 0x52531F90266F41DBULL, 
            0x600AE678B5BF5399ULL, 0x46ACCD1C552A5EBDULL, 0x5F2D3A04439410CAULL, 0x6CAE9A82A9C83720ULL, 
            0x0CFA267F1474EFFFULL, 0x38825D5A310DA9C6ULL, 0x4DD592767E9B0692ULL, 0xA2F150F37C845CD2ULL, 
            0xE03CF7D09FE4D870ULL, 0x4ECC17B37FD8D2DBULL, 0x7DE54E45F420C5A7ULL, 0x7A4DE57B271ED5A2ULL
        }
    },
    {
        {
            0xBC5DF65C3A56604CULL, 0x526232056E570543ULL, 0xF9250BE324107530ULL, 0xE5449A189BB8DC0DULL, 
            0x940D4D02C7D7310CULL, 0x82C8324174D7C48DULL, 0x6571BA46654754EAULL, 0xE6221509924FA570ULL, 
            0x4E5A8B9FC0FB1B6AULL, 0x75E03A413C8EAB92ULL, 0x7DE1FBF75EA74558ULL, 0xF486DAD02B2B3685ULL, 
            0xB1EFD9F27553C0B8ULL, 0x791A49400BF69B32ULL, 0x41E8902759AC93DCULL, 0x7E137A969F61BFD1ULL, 
            0xF9F44EBE5253BC21ULL, 0x4938E6DE1CB094C8ULL, 0x6C061E8767B6B585ULL, 0xDC38D42062569DA5ULL, 
            0xFC4955BEE3711511ULL, 0xFDBCD20D7D39BED0ULL, 0xCD0D981817584DFAULL, 0x2708C3479D10ACE8ULL, 
            0x571BDF27D1F94BFFULL, 0x63F98E85CDC165D8ULL, 0x8C8CD6ACE8532F27ULL, 0x2172369AEA339E41ULL, 
            0x05143E8585244568ULL, 0x8EBB601F1015C4E8ULL, 0xE1A2CCA7CD7B9CB3ULL, 0xD898F5D5384B0438ULL
        },
        {
            0x28D6EDD73EA6A020ULL, 0xB991F0FD1786F922ULL, 0x5C149BD4C66705DBULL, 0x3BC7C62EE55EBEE3ULL, 
            0xB5ED13CC819E0A2FULL, 0x682DC469C25F7BDEULL, 0x5E7E44CC0E2C89A0ULL, 0x3D56645E0C38664BULL, 
            0xBF0418CDAF7B7F32ULL, 0xD5667FD9268CFA01ULL, 0xCD9AAEB4463ADBDCULL, 0x90EE6C8A9EE730ABULL, 
            0x56E5A3024258341EULL, 0x1C67D88F508765ECULL, 0xE1EC190CABFAB617ULL, 0xD83CFAA0D6397F2DULL, 
            0x85BDB0D7D4B6F105ULL, 0x552DB80968109D5CULL, 0x10CB1E8F01B1CCB7ULL, 0xBF3F3ECB9D732D04ULL, 
            0x11C2A6A4BC0FE120ULL, 0x012CA525F2F4DE59ULL, 0x0F597703B016219CULL, 0xAF80060EFDB7769CULL, 
            0x17472031B56B6F84ULL, 0xADB1DB2D460FF587ULL, 0x05FC3366D2E1C366ULL, 0x2BE3E4C690465E40ULL, 
            0xC725C13E60A1EEACULL, 0x6E9CBDFFAF06B152ULL, 0x0D436B6BA3296721ULL, 0x06371CEEF385C2C5ULL
        },
        {
            0x6BBB30F83B37042AULL, 0xEC81F2D3DA5D1E5CULL, 0xFC1F606230631E82ULL, 0xE1CE06CE7BDCCA72ULL, 
            0x3FAEEB4A0CBB345BULL, 0x2F8491D18F860CA9ULL, 0x994164511C9F255DULL, 0xF7B99672768CE2F3ULL, 
            0x12D01496126FE304ULL, 0x8F0588A746930C5BULL, 0xA8FF71EA94060615ULL, 0xB4A970D8EE257ABEULL, 
            0x76B2CD6D9FD6D5A1ULL, 0x2C64F5D6C219A962ULL, 0xBD544B10F1D7B6F1ULL, 0xF271948878D4A23AULL, 
            0xDE88048DFF0615F5ULL, 0x5975E1237D09B89DULL, 0x0749C93AECF5021EULL, 0x796CC3F0CE1A09F7ULL, 
            0x1C7DF5ED66FE0C3DULL, 0x5B5C326B776E42BDULL, 0x53CDB31029C98934ULL, 0x84285E26426773FEULL, 
            0x6B9075B492685C57ULL, 0x283C688E27F0B6A9ULL, 0x8E75E3063D0F462AULL, 0xA9F8FF97D1CE829DULL, 
            0x618FE92A8023DAC9ULL, 0xB155EFEFD6271B24ULL, 0x8DAD53A88689A3EEULL, 0xBA293789F474C64CULL
        },
        {
            0x05D3BA68CCE37F36ULL, 0xB103AC123157D429ULL, 0x2A996982A3A358CDULL, 0x2EA6F2DD566F5B63ULL, 
            0x28E36C7DEEDF1090ULL, 0x12D1815A436C7FB4ULL, 0xE6D7CDBE6CBA7951ULL, 0xF8A8BAF8EAA10E01ULL, 
            0x1E309DDA8A6D55C0ULL, 0xC9AA291B67DAC26CULL, 0x28131AAEF6003ED2ULL, 0x0DAED406A2C9A5EAULL, 
            0x9D55C4346EB02778ULL, 0xEDB2044A2A1FDEBCULL, 0xF9D2C08ADF49E665ULL, 0x80C2C3B9A27EF273ULL, 
            0x26D185217F9D08ABULL, 0xD47E199B059450FDULL, 0x4CAC384FF78D7433ULL, 0xC8396EC3AA672C2EULL, 
            0xAB5E757CF0CD44E3ULL, 0x4557A655B922DF27ULL, 0xFBA6624165C4374DULL, 0xB52EAE5697FFCC64ULL, 
            0xD5B45492785CD42EULL, 0x1F109A06197FEB4EULL, 0x02BC80EBF50A8F01ULL, 0x0D0959F043C92684ULL, 
            0x561FF91756AEDD21ULL, 0x8EF77A80EA79E324ULL, 0xC2883687A3975BFDULL, 0x2A85791492FF6FBBULL
        },
        {
            0xA3ED313F744581FBULL, 0x45A058CB8A717C66ULL, 0xA55ACF6D55DC444AULL, 0xD3FA31011CAB0FD9ULL, 
            0xFD083EAA7BC75F9EULL, 0x2ED9F2A2D48368D7ULL, 0x28532E92A0248CB6ULL, 0x283618DFA6C38C39ULL, 
            0xB982AB12C6A7C608ULL, 0x2C7C4119DA6E8E94ULL, 0xD96993957610D6D8ULL, 0xD785CDC6470B13D3ULL, 
            0xD1AD549489A1D9FFULL, 0x394D4E2188142A95ULL, 0xA7687601169EB5E4ULL, 0x32AB597986B807E1ULL, 
            0x764F4F340AD7F782ULL, 0x9FD6C235611CC970ULL, 0x2328A625C4E3A4E6ULL, 0x47353AD37DB839D5ULL, 
            0x7F0DAB5047475D97ULL, 0x5C8C9A2A5DFE7C13ULL, 0x4DAEBE50B5B2110EULL, 0x7EAE5037070F9E2CULL, 
            0xF903DAA4275DBA83ULL, 0x63A3548D0CF1B4C7ULL, 0xE5E6046BD1578588ULL, 0x13A01629CF0B9F26ULL, 
            0xF14AEBE8B1D289CAULL, 0x169744AFE9B7903BULL, 0x2E580E3FF7101D6EULL, 0xD9BFD91AC1EAF984ULL
        },
        {
            0x436E769A3F9B7BE3ULL, 0x5283416F4E08E439ULL, 0xA86A5324E1AAEF44ULL, 0xA8021F580194E50CULL, 
            0x405C7FA8701D58C5ULL, 0x7F96DBEC09DE1C8AULL, 0x09F68A2D3F139E6FULL, 0xD2E7BCD6D9E93845ULL, 
            0x38E7213684CDB755ULL, 0x4C2BD3A7B2E12B98ULL, 0x837479A0211174EDULL, 0x811ED06F648DAA79ULL, 
            0x33C48382018E3088ULL, 0x46F5A49F019F346CULL, 0x214D3D4F3A678B57ULL, 0x4145275165E65506ULL, 
            0x51B3E34F19CDD49BULL, 0x6516295608E69E51ULL, 0x38AB19AE6398DC7CULL, 0x98CEA9AF47F47466ULL, 
            0x224303D1B0A196A3ULL, 0x7E2A6C4D2FEA1B3EULL, 0xC01CA9F20CCC016DULL, 0x58E8D8169BD4A4D3ULL, 
            0x16C8DAFF80CEE51BULL, 0xAAEEF48CE5632180ULL, 0x80369C7410F895CBULL, 0xC213B29E26B03D4FULL, 
            0x6498105F2236C698ULL, 0x840BE1F6E492EB55ULL, 0xD5832C0F12F29CE2ULL, 0xC2A3A8014329C0A9ULL
        }
    },
    {
        {
            0x8BE6DFA3444C1C73ULL, 0x5066A3FEA62CC821ULL, 0xA601DEA4693687ACULL, 0xD0ACC4720CFF6648ULL, 
            0xA0E6C720AA6F77A1ULL, 0x1AD083BA0ED81887ULL, 0xB803E75265990D83ULL, 0x63AB5258EA23732EULL, 
            0xC3D08A6BCAE3907BULL, 0x518C9060AC847FE5ULL, 0xBF721E751DFF0F21ULL, 0x42D2C47A6E66DB52ULL, 
            0xBECF0F2620406E2AULL, 0x5659D5C90BB3A003ULL, 0xDDCFCA1538BC97F9ULL, 0x88008DE9DD05FB1FULL, 
            0x8BC350F42F1CF21EULL, 0x24F80D967D6B5537ULL, 0x6538B2C06F732FF1ULL, 0xD057F8EB3EB3D47AULL, 
            0x25B98E33D9A77214ULL, 0xE21E13561A073C55ULL, 0xF22B21B00A209737ULL, 0xE272C1272C8C4DFAULL, 
            0xD11D759EFBE2E152ULL, 0xDE63DD47A7A8445CULL, 0xFA4F3552C91E0221ULL, 0xECA63E0178EA248FULL, 
            0xDBE65C102BFEB15AULL, 0x05CAFE57CCA8C732ULL, 0xEC55835070E95537ULL, 0xBFE9CAD645FEC81EULL
        },
        {
            0x72DBF77CC434F8D0ULL, 0x893E94D2E100B177ULL, 0x5E081EB714355D9CULL, 0x904BBE1BC8F57B79ULL, 
            0xBA34FB7950455F2EULL, 0x410BA7F909D97496ULL, 0xD475B07C6B0A460BULL, 0x288FB80D6A970C2EULL, 
            0x61D1AA229D384B29ULL, 0x6382E384B2A1B139ULL, 0xB0B28161C9EEA294ULL, 0xF67E0E0CFF5A3E71ULL, 
            0x577AED7EF40DC389ULL, 0xABF18C9FB00E43D4ULL, 0x6EFB8617B0362C0BULL, 0x09FDC0162D392763ULL, 
            0x5A708D35B3CBF407ULL, 0x3DF9E6FC1A1C42A5ULL, 0xEAB8917E43C279C9ULL, 0x9526492CE2FCE86BULL, 
            0xDAF23E2920AC29E5ULL, 0x38005BBC34214AB2ULL, 0xF31AD2E6AB863E4DULL, 0x92E78CDA078C9112ULL, 
            0x4CF302CE67DB5D1CULL, 0x79CF062CEB14588AULL, 0xD040F12672F5D184ULL, 0xA38E99ED3E2D05DAULL, 
            0xEA8FDB2AF9D063BCULL, 0x63E59BE692502642ULL, 0x2ABA2B7B4207128CULL, 0x3EBD7C5E173A8A72ULL
        },
        {
            0x53FF281C7466B32EULL, 0xF42C0E684A2E6FEFULL, 0x082A693CBD24470FULL, 0x5E0B9466703FE029ULL, 
            0xDCD7E85EC252C016ULL, 0x4254E32CFD08817DULL, 0x78402793992A423EULL, 0x50EDD76B7CBAB04AULL, 
            0x39E8A8881C0FEB52ULL, 0x042248EFE369F912ULL, 0x808C1869A0A2FE8FULL, 0x96C0586FD51046A8ULL, 
            0xE5D8B4056F1E43E8ULL, 0xE3E8F49384AC2FC7ULL, 0x2D86F890DB0CF2D1ULL, 0xABAF5FC2842FDD84ULL, 
            0xBA8BB0F4E707D68FULL, 0xD4CC74A9159B0517ULL, 0xB14D490259825F60ULL, 0x609851D09C7E9164ULL, 
            0x81A4E4995E7B65A6ULL, 0x1D2F1FF7FC45F200ULL, 0x85AF726AB1AB8193ULL, 0x9C3A2B8348CC8ABEULL, 
            0xBDAFC9B098947263ULL, 0x6EA793A22A0198B8ULL, 0xCB4162748268FEEBULL, 0x534E86B85E341607ULL, 
            0x33BC60E34800D40CULL, 0xF05DEF8419F3D6CAULL, 0xB99A525A372F4D62ULL, 0xCBBAF1B7388F18A2ULL
        },
        {
            0xC8310A66B9D983ECULL, 0x197BC051C492926BULL, 0x29F5CC5B55832F2CULL, 0x6C21107D88223DF2ULL, 
            0xCFBD6A985A20FD75ULL, 0xEFF1853BB5C626A2ULL, 0xA740473282EAEF70ULL, 0x7D535078FCFA2705ULL, 
            0x14B3983E8D039FA4ULL, 0x7F4311B0BC3C5D50ULL, 0x96DE51F61ADF1E1DULL, 0x18EED94A5FA0BD40ULL, 
            0xABA77FEBA0771758ULL, 0x82D8336313930D5FULL, 0x2889D9AB636FF6D1ULL, 0xF741927FC71E52E2ULL, 
            0x5A6215DB9F33BC50ULL, 0x534535F257FAC6C5ULL, 0xB53B7F541E22C83AULL, 0x8C019036ABF4BF76ULL, 
            0x471339D14E902C9DULL, 0x0FA98DCC44B5D661ULL, 0x3A6E0C2A9B0E906DULL, 0xFC9E8EE3B17A98B7ULL, 
            0xC6D4A35BCB303FF6ULL, 0x6773CBD340413890ULL, 0x2C3761C5E51F31B9ULL, 0x2AB191C9A09B4D0EULL, 
            0x2EBA51E4CDB54865ULL, 0xF947C2A96850517CULL, 0x6A3B1815258C9EA6ULL, 0xE03A2EAF25E1AB53ULL
        },
        {
            0xB211391109A3075AULL, 0xB558B42A828814B4ULL, 0x55A8E6389F8D7A1AULL, 0x14F2BED0CA97D4EAULL, 
            0x96E49EC42FD99B9DULL, 0x2D944F61E9FF4DCCULL, 0xFD0DD2BFA750BDD0ULL, 0x3F6CF124A23876A4ULL, 
            0x564ADB3476E7B8E1ULL, 0x795EC438E8772386ULL, 0xBB22CE256CED3402ULL, 0x9BE3F82CC19D9B2EULL, 
            0x9103C4C9D7AACFFDULL, 0x95B577978AC9183FULL, 0x0146149FE65EC9FCULL, 0x51462B4C07717CBFULL, 
            0xB0E1479164B72FB0ULL, 0x5770C7FFA00C58B4ULL, 0x2E5F87B7A94A8886ULL, 0x0C74B0358B24712AULL, 
            0x1C089EB3FD68B9BBULL, 0xD2FD5E83116C85DEULL, 0xC2F9AA291D6B5199ULL, 0x98BBE780CF5ECD21ULL, 
            0xB4DDF64FC0A886CCULL, 0x41AA55A7C9FA1DADULL, 0xA28D5181EE18225EULL, 0x11C614AC3F793CE2ULL, 
            0xDC4719B0F90CCAF3ULL, 0x026D1ACFBBAEF712ULL, 0x2515AB1E83F3174CULL, 0xB476BCBEAFE3D35FULL
        },
        {
            0x86CBBD3AE07BDD5BULL, 0x5FC6A0A5C1C95298ULL, 0x233F8A88F8139C5CULL, 0x7DCBE0BA88D66401ULL, 
            0xDD4DD078228EA9D9ULL, 0xF709D8324157B304ULL, 0xCF2C4D7B15B9565FULL, 0x6431947977601409ULL, 
            0x04ED894D3DC798EFULL, 0xD0D1A5BBE09E48E3ULL, 0x94476B092A718E2CULL, 0x1C427DC50DF85905ULL, 
            0x0492C2E7131CFE87ULL, 0xD5F3B987D580D13CULL, 0xA08302E80B923905ULL, 0x55F66C1FC511F515ULL, 
            0x0359E9A36E2390C1ULL, 0x8158B44CFEF51438ULL, 0x65461467E7229398ULL, 0x6747A7FAB1D27CF1ULL, 
            0x3786B1CCEF824208ULL, 0x76D52E8F557B012DULL, 0xB7863F07276B1095ULL, 0x6BAF46BCA150F4FCULL, 
            0xFEE0FD5ABE38B6B3ULL, 0xA8F1F16A9A8DBE6EULL, 0x0A18483F7BA89FE3ULL, 0x1147615122474747ULL, 
            0x099EBE56150F45EEULL, 0xF95151DC1869C9B8ULL, 0x3E506412F2A8F1C9ULL, 0x62A346B5E9568803ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseAConstants = {
    0x86E6FE020AF339CCULL,
    0x2396C47088938B79ULL,
    0x1D72A43D3C16D789ULL,
    0x86E6FE020AF339CCULL,
    0x2396C47088938B79ULL,
    0x1D72A43D3C16D789ULL,
    0x445ED65CD1F4C376ULL,
    0x5621C1863D81E339ULL,
    0x96,
    0x66,
    0xF6,
    0xFA,
    0x57,
    0x1A,
    0x06,
    0xC2
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseBSalts = {
    {
        {
            0x5AC1A3E211C1D11AULL, 0xA1F7749375BC6186ULL, 0x27BA4753BDB081FFULL, 0xD4279F0AE79F6B8DULL, 
            0xC428E37962C4DA29ULL, 0x474D9C9EAAD5FD0EULL, 0x02CBBC0E6F0C03BAULL, 0xF06C4395D5D597CFULL, 
            0xF856A4E81C039F9AULL, 0xC1A5568FBA2361AFULL, 0x8A10C8D3F2571EFEULL, 0x907795616E3EF99BULL, 
            0xEF29637C4523921BULL, 0x71E837127E21ED77ULL, 0x2AC69CBA9340E1D3ULL, 0xA4BA40A9643BA061ULL, 
            0x95A505A99E0D2D0FULL, 0xB240819CC1D6B2DCULL, 0xE900CB24930775C5ULL, 0xEF6C3092BAF1503BULL, 
            0xE550BA47C8C4E12AULL, 0xBDC27DCA06750499ULL, 0x7B8C99B66F23146DULL, 0xA19BA092E9E482B0ULL, 
            0xFF984FB3353C04CEULL, 0x2EF85AD6D7FCA3D6ULL, 0xE2518453FBF4B588ULL, 0xFC69809B88322AB5ULL, 
            0x0BB8C4443A40DDD2ULL, 0x0A5FE82490A552F3ULL, 0x9CDB11D3307F14B3ULL, 0xEE2A1DE80E85612BULL
        },
        {
            0x83CD2C4A8AF2F9E7ULL, 0xFE93D9CC5A8F9583ULL, 0xCEB8E9E2F1D71772ULL, 0xD5C77DB35409E8DBULL, 
            0xF84D2DEF1B1BA075ULL, 0x816795205155DCADULL, 0x104B3774EBE3BCB8ULL, 0xE3BFBAABD2272E93ULL, 
            0x304984A21B1433EAULL, 0x8E3537C08BE811A0ULL, 0xC0D03D0B40377E83ULL, 0xB350203A3E21A051ULL, 
            0x0B731CB8B6EFDEA6ULL, 0xD68680300CBE9AECULL, 0xCE520BB3CA2A1060ULL, 0x184E25D83054BC20ULL, 
            0x53B7584E39CDB340ULL, 0x627B294EDB4D63ADULL, 0x448A2F755918C6F4ULL, 0x3C3EAAA5CD5A4CA1ULL, 
            0x2F930075BA8460B6ULL, 0x9E42D4FBDED4A994ULL, 0xEEA651AC01CCEBF1ULL, 0x32D26AA6974B76C7ULL, 
            0x21D97B55275D0C4BULL, 0x1452529F0CD964D3ULL, 0xA2DA8F0034C36A1CULL, 0x91E33C65D8A01BBDULL, 
            0xFEDA9901C3917D24ULL, 0x875821ADF8B11D06ULL, 0x9637C4F29DE2F8F6ULL, 0x0F9E150A354C3B77ULL
        },
        {
            0xE53C8AEADA32A0C2ULL, 0x7C39A0E84D58864EULL, 0x322B32DBFD84AD78ULL, 0x3C06089502F70324ULL, 
            0x6FD0095ABFB7F9FDULL, 0xA72FEF1CDB451A66ULL, 0x1203BF91B8C966E6ULL, 0xB60D2F5714986E31ULL, 
            0x7E69FC2DD45AE543ULL, 0x9DC8B432795C9BBBULL, 0x2F341AEF182D0FCCULL, 0x7A24DC3EE5A4107EULL, 
            0x82573E33D6654569ULL, 0x5881C99C06E25AA1ULL, 0x39EF82D6187231C1ULL, 0x1C207D3253D39D8CULL, 
            0x9979F40FEB4DBC76ULL, 0xD7CEEF7EF1B4A85FULL, 0x4429C58640A3D112ULL, 0x3A18909EFBD80227ULL, 
            0xD0E271B54A6360B6ULL, 0x6324BC9676BB8E3EULL, 0x36DDB4BBAE71CFEBULL, 0xE1B0BEF61A8192BDULL, 
            0x21F71F14286DF8CBULL, 0x0FA8D39D7A53A86DULL, 0x358BF1F54C482FD3ULL, 0xCADC36C37F923705ULL, 
            0x034415FA52188977ULL, 0xC856F9B6B1936F12ULL, 0x3140B6A967548C30ULL, 0x63E66903DF6A92D1ULL
        },
        {
            0x731B89613225766CULL, 0xDE9DE13D321BDA68ULL, 0x26F6B1102A04E44DULL, 0x8B6752C0DC1167A9ULL, 
            0x1DB0701093084186ULL, 0xD055852AD220C621ULL, 0x697D24E197212DCFULL, 0x702E26E67D070AF2ULL, 
            0xE0F75097D31886DDULL, 0x5F65C4BA199163FAULL, 0x1A0F54012BA5D180ULL, 0xDD2157FE20E5FAA8ULL, 
            0x5065669E5E110697ULL, 0x21C9064E816A0683ULL, 0xDBE7E8C4D784838BULL, 0x55037509DE60DC87ULL, 
            0x6BE3E2118528024DULL, 0x8967E99E53A588BFULL, 0x4BFFBD78EB2CC9A0ULL, 0x0A10A9864BBF8BC1ULL, 
            0x29E7C0BAE4D73B1FULL, 0xC8F368CB4153F490ULL, 0x61642130154B54F5ULL, 0x73EDF7803882C869ULL, 
            0xF90C8D343CD192A0ULL, 0x6A03ED95FD06AA42ULL, 0x16BE93626277F6BDULL, 0xD8934B72F51341E9ULL, 
            0xB8FFAF829049668BULL, 0xB6FB9F673AF03F23ULL, 0xFA10B56D406BF5DAULL, 0x2C514EEEB54ACB4FULL
        },
        {
            0x82A4479BFE27C3FBULL, 0x3C6E4726F50BA215ULL, 0x05FBBCC5958F2998ULL, 0xF20B7676C700B599ULL, 
            0x47C225D05E1F892CULL, 0xAD3E7E9D8A1E0B07ULL, 0x1F1D25B76F1D4FADULL, 0x967BD46C3E8624EFULL, 
            0xC58EE721F90B0B71ULL, 0x63FBE8B54173C653ULL, 0xD7B0312194276E04ULL, 0x6B44AD28ACC065D2ULL, 
            0x2353C50D38B6BB02ULL, 0x0F1129E4EE41DB53ULL, 0x5EC532821A13CDE2ULL, 0xD5A6E7B0542C6DC9ULL, 
            0xFD44868EAF503427ULL, 0xF0FE1736B2F10B6BULL, 0x6F1AA0A7C9FC05F1ULL, 0x825DC9DE4D0605EDULL, 
            0xA805EC2D8843F8D5ULL, 0xDA0FCB8EC35D8E0BULL, 0xCBFA8755CE17F3C3ULL, 0xB834D02F40A0A2B1ULL, 
            0xF0207BFE3B33A6B0ULL, 0x9454DDDAA9477E48ULL, 0x196D54AB63E914A4ULL, 0x8A205EED842C022EULL, 
            0x89727EADE9293E49ULL, 0x21B5F0D342F3E5D5ULL, 0x6A635FA14045B1D6ULL, 0x10821CAE168F3BDFULL
        },
        {
            0x70701BB6C6CC7CF4ULL, 0x7C327D7C39F8A4C0ULL, 0xDEEAF3011E29F3E4ULL, 0xFC87AB0267F98BD7ULL, 
            0x16C6172275743015ULL, 0x48E1EC3B79A9B0ABULL, 0x39D5CC966EB8BE7DULL, 0x990B64F4CC4AA723ULL, 
            0x1A86A26A75EAFDCDULL, 0x66F000CA2AEEDCABULL, 0xBFC26E4C07FD9E37ULL, 0xC99BBA72E858B946ULL, 
            0x24E868C18684A038ULL, 0xA24ADD4A15A89429ULL, 0x44F4AE00095DF889ULL, 0x31270DAB7809F08CULL, 
            0xFA959BDF5C265AF6ULL, 0x737D2CB5EAA15248ULL, 0x60EB0FAA1DA44F3EULL, 0xFD6775DF2DBA8D2FULL, 
            0x543EB7B72CED97DCULL, 0xC1B0464226735AE2ULL, 0x3B5DBB2C20526699ULL, 0x1EF9CEE7E78DCB0AULL, 
            0xF7B0BCB7412FC701ULL, 0xE9DC0D036050521EULL, 0xB86250CF6D99364DULL, 0x421DA1CCEC16FB8EULL, 
            0x5E2735C96BDD0CD1ULL, 0x7C32491018D5B7A2ULL, 0x8955EBC675FFE70FULL, 0x3DDFD5E95B193837ULL
        }
    },
    {
        {
            0x8CA5FA21D4099409ULL, 0x28E75A97EAFD393AULL, 0x06EC6F2A00DA677BULL, 0xC0CCC0701B9157CFULL, 
            0x8048E8A19978EEA2ULL, 0x3C0FF596008D27E7ULL, 0xA0A13B3CE0F88070ULL, 0x75E0A28B8A5517E3ULL, 
            0xC41C06B8389E70D7ULL, 0x7800EBE6C6760252ULL, 0x6E84B134A7718582ULL, 0xD64E9F9CCDCE7F99ULL, 
            0xFF2C49F94C5D9C72ULL, 0x6F7F0D6FD060C90CULL, 0xF31999AD2C8ABAD0ULL, 0x4FBA619941024A3EULL, 
            0x0DC16F923D1B4DDEULL, 0x11D16125DDC44D22ULL, 0x0458DAB9E8E19F53ULL, 0xE72B86653D94DDF8ULL, 
            0x23BA29F3F0D65159ULL, 0x6F4D489B83A805E0ULL, 0xABA0C580853757A0ULL, 0x9987149D5F1E3EEFULL, 
            0x9BA12FB7E9DAF8B6ULL, 0xB73843DC70724652ULL, 0x8935861486462187ULL, 0x09753B2E57454ABEULL, 
            0xF85497E85CFF5F57ULL, 0x85DBD7853D1A5451ULL, 0x183C72F1599AA607ULL, 0x7DC33CE16C2E9A26ULL
        },
        {
            0xBD29554AB6BF52ADULL, 0x8861EF429165EEFEULL, 0xA395991010F3F6CCULL, 0x31573ACBC85A2F2FULL, 
            0xCAE05E1DACBEA8FFULL, 0x110073A1FA07328AULL, 0x401E90D497892DA8ULL, 0xF8579286AC08945CULL, 
            0x56EC051CEB245826ULL, 0x07F6943DBF7CCFE4ULL, 0x9404F71B02CA672AULL, 0xA65C2AEA3117357EULL, 
            0x34F0F05676D14D84ULL, 0xA24572E004411354ULL, 0x6EBA29E3E5D35FB0ULL, 0x1FAA8C63577C9AC5ULL, 
            0x1402F503861D5B74ULL, 0xD3A146F8D5DB568EULL, 0x34A9937FF6A5136EULL, 0x38224CACB5CC7097ULL, 
            0x340F76E061EA7152ULL, 0xB0A6766E8653CA65ULL, 0x225D0D83786A0C22ULL, 0xF53C0D36F6BEAC94ULL, 
            0xB111854EA90DC0EEULL, 0xBC972209C14294A2ULL, 0x184B77DC7025E2FAULL, 0xF698DF02C1DEFDCFULL, 
            0xE8DE9DB9309541D6ULL, 0x4E942202CD449E6FULL, 0x4903C9254D46473DULL, 0x3E9FFBECD3C19ADCULL
        },
        {
            0x47BF958A3459665CULL, 0x3D33E2250F46C37DULL, 0xA3F1510BD3064D6DULL, 0xE4E22135F4F6CBDBULL, 
            0xF3F11B7BA7F6D88FULL, 0xC610B12D8546A981ULL, 0x3229CFAAB1DAD670ULL, 0xAFC4F0C73CE9CD26ULL, 
            0x00ADB87A107DD658ULL, 0x6D62D049CB42DD59ULL, 0xB967F6C4DB8BAD37ULL, 0x5E4E5C067604DEE3ULL, 
            0x0969AD639D1F0E68ULL, 0x99FC0C4D6381DCFCULL, 0x39B97A5E464DA1C0ULL, 0x7BFCB043C219FC55ULL, 
            0xCAAB7C1CB9AC7F1EULL, 0x57293F0D09A11F2CULL, 0x96A591AE3664B30FULL, 0x101B1930ED07315FULL, 
            0x5AF0DCFDCEAB05F0ULL, 0x664B6D70347ABCD5ULL, 0x494730DF2C88D0D3ULL, 0x4EF8B040CC1DF9A6ULL, 
            0xC362E557C3FC5930ULL, 0x862045AD4EFDE79AULL, 0x8D18BBBF131C1A36ULL, 0xDA404207E1232F09ULL, 
            0xF4CEC70DD4B82E59ULL, 0x8ED2105DD9F9ECD2ULL, 0x482BEE562C2AB548ULL, 0xAF20AE91B5C43DBBULL
        },
        {
            0x5E7021B6099A5816ULL, 0x1B20D45A716EB4CAULL, 0x19FF760AE06CA4AFULL, 0xA25F445C434BA61AULL, 
            0xBA70539139830523ULL, 0x1BE9B64EEDB1B313ULL, 0x83AE61AD5D792C80ULL, 0x13083075A2789169ULL, 
            0xF2AE8382E04399F9ULL, 0xC1889D085DA5C46FULL, 0x1933F72342CACE75ULL, 0x5536B9AA30A907F7ULL, 
            0x8826A5806E50BBBEULL, 0xABCE109A141DB571ULL, 0xB0A3B28E2F6A71F4ULL, 0xB92B71E55B8431A0ULL, 
            0x2DDCB25F6399768DULL, 0x3CDED23DB0AEAD95ULL, 0xF3EDF0024AA64AB2ULL, 0xE71DC8B1124B1BB5ULL, 
            0x9AC8064420628A12ULL, 0xA99795201C4345C3ULL, 0x0CED70AFD6A67AB2ULL, 0xB7CD2323445FD54DULL, 
            0x65E82D1ED34955D8ULL, 0x763779D7840A1382ULL, 0x2721298CC53AF551ULL, 0x75BB2A043C5FC85EULL, 
            0x89F4B8F110CCC406ULL, 0x1B121E34CD545903ULL, 0xCEC8DABFE6994B6EULL, 0x508C08DA136315AAULL
        },
        {
            0xD4E00A094B500E83ULL, 0x9F69B0844CE50249ULL, 0x988C38B056506F0FULL, 0xBD7B18238FFE4E36ULL, 
            0xFEA883AEF9D595DFULL, 0x08550387F68AE5F6ULL, 0xDFB4E76E24F2DF11ULL, 0x0B69BD3C303F6BD8ULL, 
            0x6ADFD060C9402AF7ULL, 0x333709921672D9F4ULL, 0x4F8EE5A1AF02B956ULL, 0x7897383CB5FFCA59ULL, 
            0x032716636358B9B9ULL, 0xE86A55062344BD52ULL, 0xBAA2528119B8D267ULL, 0x7222C98B24385145ULL, 
            0x26EE1197DFE2B0C5ULL, 0x9D4B2BD975CD5E86ULL, 0xA8ACA82CC50706A4ULL, 0xFB0D7CB544A4865CULL, 
            0x7D925A745AE6AB1DULL, 0x0A05B2EF5AFE897FULL, 0x8D939D137893F332ULL, 0x9A71612C7A925B01ULL, 
            0x61FA33EB4053B4A5ULL, 0x5BFA10A9445403AAULL, 0x3E1B7A66B8954F77ULL, 0x588DCC9218583D1CULL, 
            0x5294A3948EA26E27ULL, 0xAB708BBEBA99093DULL, 0x95233C7A244A1751ULL, 0xF039775AB24401E1ULL
        },
        {
            0x3709E135FC0FD9DDULL, 0xE366D3A48FAE2206ULL, 0x42593301BD90D1DDULL, 0x1B15245E040349AAULL, 
            0x73234F269B94C7A3ULL, 0x78EAC131FB791A63ULL, 0xD5A474620A3ABCDBULL, 0x746709C5C6C40BA4ULL, 
            0x070139E437F6B0C4ULL, 0x1684B3F1969ABBB2ULL, 0xD681E58D460157BBULL, 0x6A76E38EF038C8E2ULL, 
            0xA74E53E8A3DABCF7ULL, 0x8A93126793D98A94ULL, 0x4109EA506B3ACABDULL, 0xF5B9F19770DE80BEULL, 
            0x75AD3064ABF42121ULL, 0xFC3831B504030C35ULL, 0xC65963A08587ECB7ULL, 0x9AC394ECA2E11110ULL, 
            0x30C41F2E0C4DDF92ULL, 0x7C7DF129F6D7411AULL, 0x189B061B970C39E9ULL, 0xD41D8233F82A3442ULL, 
            0xBB34B25A25165434ULL, 0xD597601B037C1E4EULL, 0xD8A482D85F272976ULL, 0xC6E3D37627FC4291ULL, 
            0x6ED7BD3555AF4A3CULL, 0x0ABA068709B323C6ULL, 0x9FE7EC92DE04B877ULL, 0x3819BFB591AB9570ULL
        }
    },
    {
        {
            0xB88E85373991B127ULL, 0x233250FAAF9308FFULL, 0x98C1650A1F4E18E8ULL, 0xCCF3D3502D6AF7AAULL, 
            0x1E6525F1CCB689CAULL, 0xB3297D7D4433556DULL, 0xDA36A9E43AF637C9ULL, 0x51D2F6AE9202010CULL, 
            0xF494130813D1414BULL, 0x892AB45E7CF6FB67ULL, 0x735FE741DECFE6A6ULL, 0x57104ECFB365B98CULL, 
            0x4754EBAF491C6B1EULL, 0x6621BC61BB183750ULL, 0xF35C944B5AAAC082ULL, 0x06051AC6967FF7D9ULL, 
            0x0BABFE5809DC5A9AULL, 0xCD3FDBB77B8EEFAEULL, 0xFB6F34DB7D6678DBULL, 0xA0BCD7B333FC435FULL, 
            0x2D2FF236DB87C87DULL, 0x8BB4739363536272ULL, 0x2F9A8F059D1C85F4ULL, 0x578C1DC4F05B2C20ULL, 
            0x911C9BACC849405DULL, 0x851D478556997AE0ULL, 0x73D40E131B9E56CCULL, 0xC6FC4C954B9C8369ULL, 
            0x3D6B47FAA7AE53EAULL, 0xA063BE30B922396AULL, 0x3FFB47C788886F62ULL, 0xC6688D87EA4EEEF4ULL
        },
        {
            0x61EEA15002065B20ULL, 0x59299CB932C11015ULL, 0x221F54189048EBBDULL, 0x9073D05A30614DEEULL, 
            0xB07295589FE289CFULL, 0xD129F044616BD18BULL, 0xEFA254FE1A5E31D8ULL, 0xE6C615FC81975EEDULL, 
            0x0155CC334932D19FULL, 0x4D09AE7AAB147ED3ULL, 0xDFD2AE8BE59E8D48ULL, 0xE4EB426E343226E5ULL, 
            0xC16703921F6A3EA7ULL, 0x423E487133F01FFFULL, 0xCC931E49E2570207ULL, 0x74BE492EF3B24CCCULL, 
            0xA1CC680B21900F97ULL, 0x30B57A46D866D594ULL, 0xFE9515D2B0C79496ULL, 0x3147EE55C32F2A96ULL, 
            0xAF888787ABA17C4DULL, 0x2A6E904EBF18D130ULL, 0x9D9023596BE7F6FDULL, 0xA9FE11DE3BAC7041ULL, 
            0x4406BB528228FEF2ULL, 0x5815681FE4099762ULL, 0x712F3D6C56328E51ULL, 0x8D47A63FD3E6623CULL, 
            0xF8C6EFA5A947CACCULL, 0x7303FFDBF3D90261ULL, 0xFAD947E5734DB290ULL, 0x02B2AAFE6ED7595DULL
        },
        {
            0x32C8D528CC2EFD2DULL, 0xAA28AF25F626E8B1ULL, 0x5C4407B7CDE92595ULL, 0x57C7A4D4867CA042ULL, 
            0xA1DE37960D6AA2E2ULL, 0xC01C1CA30ABC4CACULL, 0xF090E98DB088D429ULL, 0x6B94DACA0D1E3989ULL, 
            0xB17289B555D7F01CULL, 0x6BE0E5BF1F69A614ULL, 0x31C84E4F4895DC37ULL, 0xFBCB81B6A228E5CAULL, 
            0xD93DB768982EC0FFULL, 0xAD3FF19378350EEAULL, 0xDE81D3C21827CBAFULL, 0x54279B6305955A9AULL, 
            0x1F60005842FCB568ULL, 0x1CAB50B1B85FF194ULL, 0x6CED3D989F8C486AULL, 0xC4E2E03C314781F9ULL, 
            0xF218327BE429D102ULL, 0x98D1DF895A0A7755ULL, 0x164976A6322963C0ULL, 0xF9D1A04650332892ULL, 
            0x0B58571BB4B24A75ULL, 0x071D3125B87DD197ULL, 0x251AD2D691DE14A1ULL, 0x27A0F03E5C879BA8ULL, 
            0xEA2BBEE39190D873ULL, 0xB8CE2ABC049B77AFULL, 0x2676E56F5DBCC047ULL, 0x62F9DCB7BEF08283ULL
        },
        {
            0x5F9BC0A89B055D46ULL, 0x3E7F91F3E4A12B95ULL, 0xB32D0AEC3D9A943AULL, 0xAE12471488D2AD9BULL, 
            0xF9E33059F10DB5B6ULL, 0x708A93BD1936A680ULL, 0x6BC42F4702DAF442ULL, 0x9B8746A7451327DDULL, 
            0x45F7ABC2C85FF644ULL, 0xD2B5BD67A8DB1205ULL, 0x03E930F17529D72CULL, 0xA375186202BA9AB1ULL, 
            0xFF5A729BC73728E3ULL, 0xF9123BE41464CECDULL, 0xF6AB028FBA9B7543ULL, 0x0B61DDA6611D341BULL, 
            0x826E790762ECDC10ULL, 0x8DBDC02441837633ULL, 0x6C75E21AC426F701ULL, 0x2E51874FE3FAAE35ULL, 
            0x893E01A1EE8FD068ULL, 0x48E5A4CBB22FB045ULL, 0x7675C950C88B1B96ULL, 0x254032BACF1F01A8ULL, 
            0x9568D4DC45FBEEF4ULL, 0xBD8352E32C4F252AULL, 0x796BA2FAF75A9665ULL, 0x252345C7C0650AA5ULL, 
            0xAE0DE76F01FAC976ULL, 0xA572DA4F7721B008ULL, 0xF0F118CE60B91A44ULL, 0xE33B71A6F4EBA5D1ULL
        },
        {
            0xBBF9D91F3D9FFF2CULL, 0xB4C5D937448E8883ULL, 0xC978F9C29A2F0300ULL, 0x94699A5EDEE0E419ULL, 
            0x76A6B6DA40C42152ULL, 0x3FE91E403F69CE01ULL, 0x68B0B672EA47BEA1ULL, 0x1EB960C63A3E2AD8ULL, 
            0xA3B2F9BAE59B4F57ULL, 0x205CBF366FB3F745ULL, 0xD0EE0C2AF2876812ULL, 0x98D63ABD9146209BULL, 
            0xA0C3DAF6CAA350CAULL, 0x3B06BE6D3FC9756FULL, 0x0296CD90A2646C79ULL, 0x840BA37320036D3BULL, 
            0xDDE756D2318FAB68ULL, 0x48D76286606D1BA3ULL, 0x30C88E9EAB08341BULL, 0x983C80B22B2EE9DBULL, 
            0xFC97EB0D51C9FC76ULL, 0x8F0A8A5634F0694DULL, 0xBC4B6A59EAC6B996ULL, 0x5744063D39171BDFULL, 
            0x83D494CBAF4F7D42ULL, 0xFAD8B0DBA719A18BULL, 0xA0E0CEF71E974EDAULL, 0xF70C47161C9826DDULL, 
            0xDF4849E0228D1343ULL, 0xD5AA90357C221716ULL, 0x59DBC6C266AAE773ULL, 0x9E4EEAFCAF7624D3ULL
        },
        {
            0xFF9AFCECA1E51658ULL, 0xBD396B1E03679259ULL, 0x490495F13D5EEC0FULL, 0x54495CD9F2032E40ULL, 
            0x8FE0A20201DAC9C3ULL, 0xB1C9725E9BA62238ULL, 0xAA69D1C076C1282DULL, 0x972DC2307009E8C3ULL, 
            0xBB1D162B78127FADULL, 0x6CB365891A24A581ULL, 0x5F4018F606212E1DULL, 0xC10854E970D3F0B4ULL, 
            0x0CD13FD0DE45BFBEULL, 0x90D416AED01D9437ULL, 0xAD5C46C2E675E961ULL, 0x11F333792DE57396ULL, 
            0x31E3703C7FB0D704ULL, 0x1D1F58D9ECAA0A03ULL, 0x7C220297DA69C026ULL, 0x9A338C6705AA09ACULL, 
            0x61E03B26D9ED6280ULL, 0xA6FC2BAF1A536F91ULL, 0x4077835EA3C896A6ULL, 0x09240CC6A1EE11B5ULL, 
            0xE6C8FECE905B9387ULL, 0xFBD403E43E020725ULL, 0xE4211B121BBDA46DULL, 0x4151187105ACB99BULL, 
            0x2193DB31585B9809ULL, 0xF0CDA23889B46C7CULL, 0xE6C603E9532D08D6ULL, 0xA76E5188B058E65EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseBConstants = {
    0xF3B14CE7FCF786C5ULL,
    0x669E4CCB9BA63637ULL,
    0x0D9767224DECF178ULL,
    0xF3B14CE7FCF786C5ULL,
    0x669E4CCB9BA63637ULL,
    0x0D9767224DECF178ULL,
    0x8423304843658395ULL,
    0xEC2F948297464AFFULL,
    0xAF,
    0xDE,
    0x0E,
    0xD2,
    0x29,
    0x09,
    0x55,
    0xE4
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseCSalts = {
    {
        {
            0xC24FF7102BDD0026ULL, 0x96DE2F4C6D3E372AULL, 0x4EB19AD9BA77121BULL, 0x604934BD215D308EULL, 
            0xBBEB5567AF2EB849ULL, 0xE2C83EAAA1445272ULL, 0xECB38A6295F32816ULL, 0x22DF0125F6C97D72ULL, 
            0x2A9DE796932ADD76ULL, 0xFD547796BDB49E29ULL, 0x5DC9EE907B65BADBULL, 0x6A6F3496D97E7CDBULL, 
            0xC5B41894C41E0F99ULL, 0xC110286007764EBEULL, 0x7DCA1ACEA4E4B622ULL, 0x2F74A7292AB8C6E7ULL, 
            0x896DA1E2DBBE0E8CULL, 0x55189F28FC089B93ULL, 0x9E943CC73865A0F1ULL, 0x1F00319A2ACB364EULL, 
            0x608599499A0FE12CULL, 0x375D33A0D4BC03B4ULL, 0x1FA72636878B3EC7ULL, 0x9108183796824260ULL, 
            0x17EEF8EEEF3CF99FULL, 0xCEFA494AA01001E2ULL, 0xB6133C699F78387FULL, 0x05EB2EFFA5183935ULL, 
            0xF6E440214C979D18ULL, 0xBC53E59940B8981EULL, 0xCD88B3173F995BFDULL, 0xAC45B24AF34A0386ULL
        },
        {
            0x3B2367C684E6838CULL, 0x1E69009F4C083D08ULL, 0x25633803122BD2B6ULL, 0x832C09F75FC5BB29ULL, 
            0xBAD122F10C7577CAULL, 0xB2AF730EC4F49FF8ULL, 0x271FF9EAA76503F4ULL, 0x223A3E89DB839DD6ULL, 
            0xFC2F69C95AD87E96ULL, 0x187FAFBD4A75B1F3ULL, 0x9A29436C87621F2BULL, 0x69FEF1723FFA2C0EULL, 
            0x0932467553D4FCEEULL, 0x9230782B22FEB7DEULL, 0x75AF16E7F9613F1EULL, 0xCC699F66FE018893ULL, 
            0xA7ACF9ED0B975B13ULL, 0x5F264A2613960FF1ULL, 0xFDD1383CF107AF74ULL, 0x72817C92AFEFED96ULL, 
            0x7533DF88C1BFCBBAULL, 0xF022AE2C570BBB38ULL, 0xE54805EACBBF1FBAULL, 0x749897DDE0E353E6ULL, 
            0x6808C9EA41BE0E5AULL, 0xD155EA3E99496DE7ULL, 0x4EA003E0B597B0ACULL, 0x78A15179B22B01D5ULL, 
            0xF95202441F07E8DDULL, 0x550F26B40151897EULL, 0x780E24BC8064AC4FULL, 0x080270C2ED147B2CULL
        },
        {
            0x6B2AD1519A764B3FULL, 0x971F402E2E18CD09ULL, 0xFECFF57DE9E0C07DULL, 0xF86B351DE29B5EDAULL, 
            0xA1195E54F3227F4DULL, 0xE2EC4772704ECB33ULL, 0xE1C444DDA50F918CULL, 0x9F1A6459C1773515ULL, 
            0x385AA6CCE482FFC7ULL, 0x8128B59C07400596ULL, 0x7EE80D0E9D6184C8ULL, 0xF18E886220C7146BULL, 
            0xC051F67C48C4D098ULL, 0xFCBD3A132C80E41EULL, 0xAE789FCA4944F6F6ULL, 0x1F8391AB3F8C04ACULL, 
            0xC7846989A250E71AULL, 0x8CE0502B1CE958CFULL, 0x2CE8A6158456C88DULL, 0x341532EC737E8B70ULL, 
            0xC57232C6BF22BCF2ULL, 0xD82CC96887D6B6EDULL, 0x4D65CCDD50AA81C9ULL, 0x7450DF45FB79E1B9ULL, 
            0xAC3CC200112E2A89ULL, 0xAA6C0C62B876DA21ULL, 0x1FEAFFC04318E7C5ULL, 0x81020A9E08EC8C5BULL, 
            0x6060628F73B8120EULL, 0x34E82A270F428C14ULL, 0xEE83A0D589A92F52ULL, 0xC6F0610F4DDDC727ULL
        },
        {
            0x0EE723CC82B90D63ULL, 0x670AEC1815F1B45BULL, 0xACC4FE4DDA7B039DULL, 0xD4EF8567AC3079C3ULL, 
            0x89102D74F5EAB3DDULL, 0xF44955692BAB85C5ULL, 0xE63EEC7AB412E0A3ULL, 0x10EC67DA27308628ULL, 
            0x39691F4863E3FB5DULL, 0x32350E1200281D6CULL, 0xE13DF1A813B00BDFULL, 0x08D6D142BE17E42AULL, 
            0x67204A4594B7A4ADULL, 0x87D99C64D6ABB160ULL, 0xC44B721ED8414A4BULL, 0x8815E286242F5FF5ULL, 
            0xDADD148D17B06B6BULL, 0x26511F3D78DED7A0ULL, 0x0C63CA153CFDEA05ULL, 0xFF70F4D55A65DD73ULL, 
            0x3FC4745DC8962F4EULL, 0x9E9E42A68324FCF6ULL, 0xCBCE4D40BC312503ULL, 0xC06FC84312BC4DA9ULL, 
            0x3320B7B74267CF2FULL, 0xC28336F3945BBD5BULL, 0x558562ED4B9750BDULL, 0x36292CF440CA838FULL, 
            0x8DD1C5A98371BD98ULL, 0x152C7F4B1F35EACCULL, 0xEA859643570A503AULL, 0x0E04632CDA518D72ULL
        },
        {
            0xE95B198F0BD4529EULL, 0xC45C2BCA6F061E3DULL, 0x8182843F78E20088ULL, 0xFEF2B2BC0FB43DF8ULL, 
            0x4CAEFA4965970A83ULL, 0x29881D32E46ED38FULL, 0x18CB8B78F9DBAB91ULL, 0x120BF1B618284C2DULL, 
            0x4F09D58333EF4C96ULL, 0xB3DC6B64AFBCAB7FULL, 0x54790D50D1326FD0ULL, 0xB02B75A1FD8FA06FULL, 
            0xE00DEAA152CFCDE9ULL, 0xCB636408E804EBE9ULL, 0xC982273B6C841A08ULL, 0xA41A052FF5C53506ULL, 
            0xC52EEACD57C53C5BULL, 0xABFFD8CFF322BAD2ULL, 0x7B444BED9B7EE9AAULL, 0x0C6F61F9A4E4362FULL, 
            0x4ABFA4E2009A08D7ULL, 0x64EA2D1E033CF3ABULL, 0xA8092CE87F08ADD4ULL, 0x196C445C1AB8ED79ULL, 
            0xA39609AE0AE82B29ULL, 0xFBCA6DE6251F530BULL, 0x6059F86105F2EF16ULL, 0xC5386A2D4E05FA61ULL, 
            0x67EB8C5629E67D1BULL, 0xBAC1EFC5A83ACCF2ULL, 0x3497F7C6C0BAE9AAULL, 0xBC89F5BB4B414201ULL
        },
        {
            0x797A685A2E889F2AULL, 0xDE34B84286C347E6ULL, 0x2893FC833A7CB811ULL, 0x16330F1B4916624CULL, 
            0x7357EC4E6E25B0B5ULL, 0x4C116E4FF39C2D9BULL, 0x4B7012A0E3EE8E1EULL, 0x25901128163573DEULL, 
            0x91B8AFB8264C6057ULL, 0xC503A6832D1B0685ULL, 0xA2B3686DD54650FCULL, 0xD93753651F64E21FULL, 
            0x8D2F33F1AA2EAEA1ULL, 0xBFC512F80DB61AB8ULL, 0x15B6ACBF94A7A6F7ULL, 0x5E050680E207CD3FULL, 
            0xC9E9C73BBC2D8419ULL, 0xA64C5B148B642D41ULL, 0x31559FC2B75AACFAULL, 0x87C7FF3FCD0D62C8ULL, 
            0x618C6A5E4704980FULL, 0xCA620BAE3C66657EULL, 0x9DDD83B56E5769D3ULL, 0x977CFF8A47AC40A6ULL, 
            0x96AC5AB66CD30FFEULL, 0x54CAD7A4144093C0ULL, 0xBB1E4BCC63696A7CULL, 0x612737FA8E826FE0ULL, 
            0x9F0DAACB7BBC072EULL, 0xA9CA5E236B1C55C5ULL, 0x6CF186F4CF5242C6ULL, 0x56BB99A73E5BE45CULL
        }
    },
    {
        {
            0x4D258D6AE5964D69ULL, 0x3B12FE6F18643E51ULL, 0x97654CFAFC6194A6ULL, 0x9ACB1D895C43B3C8ULL, 
            0x5788D1F59064B054ULL, 0x2622D43CFD4B2ADEULL, 0x4FE3ACF8FFEE8416ULL, 0x9ABDE58AB9864C7FULL, 
            0xBD009DA950779E07ULL, 0x223506B3F7DCFFD1ULL, 0xC8BA03302C3D18A2ULL, 0xA87422ED96F40BCDULL, 
            0xB4AA9EBF0833AC8DULL, 0x3F92667E5FFB6CFAULL, 0xCC2CDA35EA63F95BULL, 0x4DF731A485B58B45ULL, 
            0x07644BEA0995B993ULL, 0x24ED364A07CA3573ULL, 0x2659766F3092C947ULL, 0x697824452E179572ULL, 
            0xF7524104C2663FDBULL, 0xF2F74DFEE8229271ULL, 0x8245E2DC2488CF85ULL, 0x3BAEF6506C870E9BULL, 
            0x3FE3F990B63F18FAULL, 0x5EF29BFB6C8C537CULL, 0xDC5E9DC07BA578ABULL, 0xCC30026A0D912DCBULL, 
            0xAA4EDBA044461BD8ULL, 0xBB01A0EC8EDADDCAULL, 0xAAD53E18F1909281ULL, 0x068D59B29EC438EAULL
        },
        {
            0x1501827A33B2E8E5ULL, 0xD8A561165196E70AULL, 0x677AC7C4746E73DDULL, 0x140EF9474545BECAULL, 
            0x24BD8DC7C520697DULL, 0x69E5F7FDE7376F65ULL, 0x20522992D86B9334ULL, 0x012ECB4627149F71ULL, 
            0xCA6848E774D08E74ULL, 0x821EFD929548BA86ULL, 0xFBD5DF6797CE6CF2ULL, 0x250262AE4F269EF3ULL, 
            0x02C92682E501F146ULL, 0xC50833E7AF63502EULL, 0x452EDF0F10BD1531ULL, 0xBCB8808B1E5D2715ULL, 
            0xC61396D11466D8D0ULL, 0x36887841476B7E61ULL, 0x0469497155DC8BEDULL, 0x48C9D7A88E6DCF11ULL, 
            0x139EC677EEE3A094ULL, 0xAC82B329EA6C60DEULL, 0xA655D4DD435115A1ULL, 0xA2765AB05F4C18EAULL, 
            0x30687C730115CB03ULL, 0x308D09C97789C03EULL, 0xEFDF39B8E5B2D570ULL, 0x83B3ACD4F39FB436ULL, 
            0xEAEEDB0F781718BBULL, 0xF9FAF0FCE19A0233ULL, 0x3BC240D5686492EBULL, 0x4081302AB7CB48CBULL
        },
        {
            0x410E1A39B7FD4ACEULL, 0x26D5C891B0086837ULL, 0x2B5BAFEC39B62F4AULL, 0xDD0C15D679907E69ULL, 
            0x5D4469C0EF86728BULL, 0x19B1B23E32D5AD48ULL, 0x16930EA7C68F9CDAULL, 0x771FB8C074BBC492ULL, 
            0x255B266B051DB110ULL, 0x3A0EDEDF99B0EF9AULL, 0x7F500CB02F59B852ULL, 0x237AF5D17E3B5DCBULL, 
            0xA70F3974F3F0D36DULL, 0xC89EFB77E2B15783ULL, 0x9AA9F0D6835B26D4ULL, 0x193C08AAAF57A812ULL, 
            0x791D49E931F97C53ULL, 0x4B1A2FD530F4392BULL, 0xF888A6B178320CBDULL, 0x95B05949C6505BA6ULL, 
            0x4E734E52ACC10D11ULL, 0x15656304853DB290ULL, 0xA547D62E3D790984ULL, 0xED8D0D8F1F32FC3FULL, 
            0x92E99924FAB88673ULL, 0x910A5ACEBF29E22BULL, 0x0173ACAB809FF3E8ULL, 0x38BAE065E4BE426AULL, 
            0xA07679B1CCA1565AULL, 0x1AC9C9EF178809F4ULL, 0x820A15FC828AE492ULL, 0xCB307F54EE22385FULL
        },
        {
            0x17B4401BEF7BEA64ULL, 0xC0EC942C3F1127F2ULL, 0xB7C706B16472F0EAULL, 0xAAD76B36FD459995ULL, 
            0x7BB8F3B2A588A55CULL, 0xC51222D963BCCAE3ULL, 0x2437B407F12A66EAULL, 0x198B2F5D07A661A7ULL, 
            0xDFA521A0F40178E3ULL, 0xFBA27A66AE358887ULL, 0x707F48B035878CA4ULL, 0x4D5558B69C4CABF0ULL, 
            0x8AAA01A59F74F44EULL, 0x4FC7F45D3A1055D8ULL, 0x069EBE95BB4C4201ULL, 0x0A8FEB8C2835BFD4ULL, 
            0x6E02E374CF2464D4ULL, 0x423744F403A65970ULL, 0x3623E9C794731843ULL, 0x6DEA2DF81FC9A3B1ULL, 
            0x1EB80BF5D0DB5326ULL, 0x11E1181DC0EDB880ULL, 0x3917E1460CF5BECFULL, 0x2BACD10326854EBBULL, 
            0xEBC422F4D50C2412ULL, 0x80E974714F88D7E9ULL, 0xEE833E355BC5037EULL, 0x16AEC57037FE1ED9ULL, 
            0x2F8AAA9DC668A3BFULL, 0x67FF280CB3A4D8ADULL, 0x2C151E27A7F73603ULL, 0xB5B8B28F3F6B687DULL
        },
        {
            0x5F681CF5D583D87DULL, 0x1C106BFAD4F2E539ULL, 0x016D2246DC7D5B7FULL, 0xF58D3E146A83CF07ULL, 
            0xE3BA25951C595D93ULL, 0x0A523407FE03F439ULL, 0x5A1C0E958EA706AAULL, 0x13660A16297AB5DBULL, 
            0xAE933C480664F858ULL, 0x2D3E5168618B80C0ULL, 0x9A72BE352B23D7E7ULL, 0x031F727A538245FAULL, 
            0x14B66FE93C2D26A2ULL, 0xAE7D8E6E47C1DDF6ULL, 0xB150B68DB8F78263ULL, 0x84D4CC973C76BE40ULL, 
            0x41155986908D95C7ULL, 0xBAC63521DA03BC22ULL, 0xD79DA7D9D83F5FD7ULL, 0x231EE89A111D6B86ULL, 
            0x310B47BF6F591A0DULL, 0x96EB1EE379A95A2EULL, 0xE2A1C7F8016DAAA7ULL, 0xEB59C0F0A9C12793ULL, 
            0xB7C22D09417FC5B8ULL, 0x774EEC99880DC54CULL, 0x4A2E0AE9B474BFF1ULL, 0x7BBB33AC9EE03181ULL, 
            0x1D0609AC0CB16ED9ULL, 0x1A94EC475099CD96ULL, 0xC4AA0EBBC138764BULL, 0x1BDD7682681F211EULL
        },
        {
            0x81C74E7B5B81CA5DULL, 0x25CB9E91E90D5833ULL, 0x6299F5C0A6610ED5ULL, 0x95605AF996707A5DULL, 
            0x7924BC0E91461F9EULL, 0xF8FA050E3189D406ULL, 0x96DE1BEA8DE68C27ULL, 0xB9B1EA40C9482913ULL, 
            0x1EC355124E0D757AULL, 0x97642021C00BA69CULL, 0x21A12EC619136DF8ULL, 0x6368D7AC79D67817ULL, 
            0x7FBF802B2A54A964ULL, 0x9CD3C11F3FB75128ULL, 0xF60DCD5F18C1A236ULL, 0xF2EEACBCCA702DE5ULL, 
            0x31755987F7E7AFB7ULL, 0xA5DC7E3655F4E146ULL, 0xB9624F091A2E3804ULL, 0xF77DE8CCAC9476A4ULL, 
            0x6108F916A79B3775ULL, 0x9943C38D1B6247B1ULL, 0xBC2E7B698B13A0C7ULL, 0xBA5FD54846AB0FA6ULL, 
            0xC9784736BE5C1087ULL, 0x13294140D1247288ULL, 0x258FDF845E0CE3FEULL, 0x540FD1E47317AC35ULL, 
            0x49885297CE9F30E4ULL, 0xDA1E383756A02628ULL, 0x529A418F702EA31BULL, 0x145CFDFCCBB5B894ULL
        }
    },
    {
        {
            0x3E3AB7E85EDA9BCBULL, 0x87B26A95612B6795ULL, 0xA0E63092C6858B40ULL, 0x2CDA57235099200FULL, 
            0x74093BB5B5CD21A6ULL, 0x01AEAFB37DC3CB2DULL, 0xE38ECB012820FF72ULL, 0x1B2E7827104A9F3AULL, 
            0xD14384CF52A942D6ULL, 0x5A9B3059CF8F8E2DULL, 0x8BB3FE21D8F46691ULL, 0x157479B4203461FFULL, 
            0xB9D7DF8589ADF175ULL, 0x0A020B0ED26C917BULL, 0xB6D15F7927358599ULL, 0xED8E88074E023FC7ULL, 
            0xC9702E2B44137804ULL, 0x2A6EE7FA8DDA00D9ULL, 0xA36B4EE4B1EE9879ULL, 0xFD40E29A486EF7A0ULL, 
            0x8C11D4DCD40352F4ULL, 0x593E07C92A238413ULL, 0xE1576BE6CD25FA98ULL, 0xA4FC171F20FF1830ULL, 
            0xC9F9FCD840597018ULL, 0xECFC77E756962BF0ULL, 0x3074F7E41F4F5AB2ULL, 0xC3C0DB0956C3B1B9ULL, 
            0x013B0E8734486F00ULL, 0x709E590D5CC48458ULL, 0x96F19E6EC43EC0B2ULL, 0xA3BDB5E4399EF584ULL
        },
        {
            0x0A1BEE483A07923FULL, 0x681C877A1462B672ULL, 0xE4BCE1B0736C6451ULL, 0xE3B493D5BE92A1DFULL, 
            0xE7C6139AC998397EULL, 0xB6A1EA5FD2CBA57AULL, 0xAC28DEDBB185AC97ULL, 0xF8047CFB4BD15820ULL, 
            0x0E0EFDA814C96408ULL, 0x057B44D62298D707ULL, 0x5722C2F5C90BA785ULL, 0xBF92F7F5F8B1F329ULL, 
            0x96803D99ABC0E536ULL, 0x89B020DF86D22CF4ULL, 0x60D9024223CBE376ULL, 0xC7C3925DA0A34988ULL, 
            0x39AFC484AAFF8E51ULL, 0x20BEABF646AAB683ULL, 0x68FC4C526CBC15BAULL, 0xD1D7CEDBAA084DACULL, 
            0x5C7C3CA4A962CCD3ULL, 0xD1831F041265A52CULL, 0x90B513BA55210494ULL, 0xD4A30AEAA64137DFULL, 
            0x2276F792B2E2D1DDULL, 0x39D02B1A523F293BULL, 0xF2CFA7CE77ED049FULL, 0x5592DA1BEFB0A5BBULL, 
            0x29761F72FB2BE35CULL, 0xC8EAFB32CD64FB0AULL, 0xBEE72605423E30B1ULL, 0x818A45797B371771ULL
        },
        {
            0xC3F8E5A0D5F9F835ULL, 0x624E2574C48B7FF6ULL, 0x2A96B3A71B8DC029ULL, 0xC8A785D0CB12F741ULL, 
            0xD163EE396E9E087DULL, 0xA21253B2D1723F22ULL, 0x45165FD7E5D23166ULL, 0x3D3274AEBBC9D752ULL, 
            0xE177A641A507B825ULL, 0x67B2D1F1F346AFFFULL, 0xF0576CBDF2150DBAULL, 0xD4EC5255CC4A802CULL, 
            0xEA008DE303795024ULL, 0x6061AD05F1DC0C46ULL, 0x1E79D5298209F019ULL, 0x593A7ABE4E01E9B6ULL, 
            0xC954E838763EC626ULL, 0x6823011DD1F46FF8ULL, 0x8FE6B0C0BD9B2CAAULL, 0xA552A312CCCD23EBULL, 
            0x943D005E9411940FULL, 0xA3AF1B3AF67CB05BULL, 0xD7483B894C70EA0FULL, 0x11D1780B6A3D0340ULL, 
            0x9645824113CF3B0AULL, 0x17C73FFAC2DD6D61ULL, 0x90A770C79E7EB0F0ULL, 0xB2CF385AABA0083DULL, 
            0x29AE98DA5A7BE72DULL, 0xE27C5E6B4E1F2960ULL, 0x70BB8C0314F6FCD6ULL, 0x37F39792AA6C038EULL
        },
        {
            0x35B0145FE256C2C7ULL, 0xCAA255FA543AD834ULL, 0xDB3C16D97124F7B9ULL, 0x725BDE596F68D02BULL, 
            0x56E89DD406A94586ULL, 0x768D1AA1936E4F26ULL, 0x9B6FEB69B275B185ULL, 0x7B542FADD88DABCCULL, 
            0x6449016D7EEEA1A0ULL, 0x9940BB5E7DEE0DBBULL, 0xF78FBC38A599B4DEULL, 0x22D7A121FF346365ULL, 
            0xC769576F708EF03EULL, 0x1419B122B94F6E49ULL, 0xB077DD44D782145CULL, 0x0555627448417F9DULL, 
            0x56151FB2894D29DEULL, 0x4C3378CF3FB75B52ULL, 0x48E0D96D3A6D8DAAULL, 0xE374D014FAA907A3ULL, 
            0xF637AD6D57D98CFFULL, 0x4858865EBEA8D0E5ULL, 0x969093B31C26A4ABULL, 0xFEE405060F435DB7ULL, 
            0xE631BAE2933BE316ULL, 0x7AFF6C30D3B78275ULL, 0xD467E1A0316BC20AULL, 0x87B8FD6CDC496F08ULL, 
            0x4C09AB6C68BF8C20ULL, 0xE24C704E4E2618D0ULL, 0xB142FFDE2B19C17FULL, 0xC33A49ABCCBE7A26ULL
        },
        {
            0xA2BEBF22BAEE3BA2ULL, 0x9A4FB2DC88122DE7ULL, 0xDFDBCE5958376791ULL, 0xE1AEF697A8DE9E36ULL, 
            0x57A1E5FE1AFC38E5ULL, 0x3F466FDB1BC539F7ULL, 0x3897794440A96D2BULL, 0x1742861827193B07ULL, 
            0x0463B5D2CE6C1F68ULL, 0x8F550C539F869FC9ULL, 0x8E8CFC3D8C3343FAULL, 0xAD22E6A9CA0AEF9FULL, 
            0x36635329567EE381ULL, 0x1C36D28A3C25637EULL, 0x6A726B2C24B84201ULL, 0x17A76EE8EC622E3CULL, 
            0xCAB9A7737AF22484ULL, 0x347980377A355DE9ULL, 0x103A3BB232271A6BULL, 0xCA18762303CA4F40ULL, 
            0x64284796C1B48699ULL, 0xD0A60DBC9C510F62ULL, 0x27035B9B80A7842EULL, 0xC4BD8F58E44A25EFULL, 
            0xD9B817EC59F3CABCULL, 0x71F8753E53ECE7EFULL, 0x6DE149BBEEC1F8EBULL, 0x382F6A3A16CEB712ULL, 
            0xAD12F6EDA9DF2B02ULL, 0x3C4CAE16EB915118ULL, 0x4DC7EB69C24F675EULL, 0x5F3A0A6355F093F7ULL
        },
        {
            0xCCE06B3E9919651FULL, 0x59C60409C1726452ULL, 0x9DEB83E802745A12ULL, 0x1F30153CB90EB135ULL, 
            0x2C43111C756EAE28ULL, 0x6178CEFA56749E3BULL, 0x174D6F81A5513FEDULL, 0x53A645A188E94573ULL, 
            0x14F57A43EF099ADEULL, 0xE4DB1DE88C7FB278ULL, 0x831BBE8A0ED08F07ULL, 0x1ECD7CA14971ABBBULL, 
            0xC1B971B88E2D40B1ULL, 0x3A8846723B85B355ULL, 0x12BBD9B129B391CAULL, 0xA896049E7D92A4EFULL, 
            0xF2EE31959DEBE553ULL, 0x38C83D20DE6E5306ULL, 0x2372D40E1E26D8C6ULL, 0x29D55CBA142454CFULL, 
            0x264695B38C757FDFULL, 0x46D30A05011E2B4BULL, 0x9355EAA6FC44D84DULL, 0x8E0C45B82A7E9AC3ULL, 
            0x601D9AF40CF24BD9ULL, 0xA246B6DE7E16C7EDULL, 0x572297D9802D6B4EULL, 0xD4E8471CAA19D725ULL, 
            0xA5B5633B00DD5780ULL, 0xEE665716E972927DULL, 0x27910444CAB58671ULL, 0xD232586F88C57B6FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseCConstants = {
    0xE40556CA10430AFCULL,
    0x4AF7F80E69E298A3ULL,
    0xD8C9A2613BB04F4FULL,
    0xE40556CA10430AFCULL,
    0x4AF7F80E69E298A3ULL,
    0xD8C9A2613BB04F4FULL,
    0xE6C71FBA2BAA3F6CULL,
    0x24AF63F2EEECCBB3ULL,
    0xC1,
    0x8F,
    0xB4,
    0x21,
    0xB4,
    0xAD,
    0xF0,
    0xDC
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseDSalts = {
    {
        {
            0xCFA2D3B2F3CD80E3ULL, 0x2A96342CA13297D5ULL, 0x443C7030F4D77BA0ULL, 0xE034AB269846317FULL, 
            0xFF36C6806733648AULL, 0x6FAC4CF49D432783ULL, 0xC3AD9CB18E11E5C7ULL, 0x75D47DAD6D9375DCULL, 
            0x1A994ACBFD3493ECULL, 0x270D33B10134D137ULL, 0xCF48EF08FEC7443BULL, 0xFC4F9450F559310DULL, 
            0xD102399221B61385ULL, 0xED9A6C3410F71FE9ULL, 0xA29669AB081066C1ULL, 0xC9038E7A19666A26ULL, 
            0xFD5F65B6E0D62774ULL, 0x38EB917590E9C7ADULL, 0x201D49D32B23B685ULL, 0x7C577C47A727AF31ULL, 
            0x2105B45A162232FFULL, 0xCB0617A40709B4EFULL, 0x8D1B2FCDA575E5B3ULL, 0x2CEC33464307E55EULL, 
            0x505CB2ED52B965CAULL, 0x2684D54F66C4576DULL, 0x7B579FB0D04E2BF2ULL, 0xDFFEF6747B070442ULL, 
            0xB26933E2F24124D6ULL, 0x45DDA27D8CE7F168ULL, 0x37EB70541CF432C7ULL, 0x5BBED8F9041B6AC9ULL
        },
        {
            0x4C236BEDB080A336ULL, 0x67DD9E75D8F7BD33ULL, 0xCA600F1BA80F5767ULL, 0xB96F2546DB814FCBULL, 
            0xB015466E8BE66B39ULL, 0x57AFD65060C2E31CULL, 0xBAC3C028F484459FULL, 0xD4EC7ED786A9EC3CULL, 
            0x21F75FD52462B365ULL, 0xA34530961B4C8F48ULL, 0x710EBDC204C88B84ULL, 0x9E2FB653ABDF1F52ULL, 
            0xEBFE67C0754A5AD2ULL, 0x5D7D9275115DE424ULL, 0x1EDE2547046E93FFULL, 0x838FD66CFFD91649ULL, 
            0xE9B9A117BA07C065ULL, 0x00D6BE6C0B032C0AULL, 0xFD55CF65665F0B3EULL, 0x6301A49A3FB932C2ULL, 
            0xA95EF41431FEB06BULL, 0x827F93F32005C31BULL, 0xD3656EB73426420EULL, 0x97653C94216408B2ULL, 
            0x1C7AED1A654BE127ULL, 0x876B64EABA5B14EDULL, 0xAF0E6E5E998B2EFEULL, 0x3029CE4B688F098BULL, 
            0x6A5A8B23A948B64BULL, 0xCA1B9DA33C54BEEBULL, 0x7950ABFF56358F1AULL, 0x0AA730190F20B152ULL
        },
        {
            0x4B6E7141F5AD9056ULL, 0x5AD3A2779D759292ULL, 0xE52DF72EF308EB2EULL, 0x1C3F18B77E7B6F9AULL, 
            0x8BFEFDDCEE6613D3ULL, 0x84B7FD5F461B3916ULL, 0xD8DB91643B962961ULL, 0x5C7EB12493B40992ULL, 
            0x1FA206BB2AC7B89BULL, 0x5CF9B3A1E3506B2FULL, 0xA0350E7A92C5C43EULL, 0x2A573C2D3E6DF294ULL, 
            0xCDD934F2131E0810ULL, 0x20188F4EA1E40D95ULL, 0x76DAD0B83020BDEBULL, 0x189A41FD0B613F4FULL, 
            0x52F01E5D6D115E1BULL, 0x29C9D8A071A7062EULL, 0x5A889B3114687B3EULL, 0xADAA060418458B03ULL, 
            0x266C9CE364FE1234ULL, 0x7EB346D32A241357ULL, 0x785C40E5AEAD342AULL, 0xBEBC27018D6B08E8ULL, 
            0xF9665EE266AEDF75ULL, 0x86B8C7A0EAB02D35ULL, 0x73FD0DC4BD3FD138ULL, 0xCA7A411E7B09CAB9ULL, 
            0x3DECF736EE8876E2ULL, 0xBE4C682CD0219383ULL, 0x5D6C0F8DEEF2DCE7ULL, 0xAADF9B25EAD2782BULL
        },
        {
            0xCE63AFA3E8A8E8A9ULL, 0xC50B46D3401781AAULL, 0x1BD774B980648D7CULL, 0x8EC4BE9CEA81F727ULL, 
            0x40E7B105165B5F38ULL, 0xBBC225377CA444E6ULL, 0xA157F58FE7395C46ULL, 0x48931325642839EBULL, 
            0xFE17984D1AD1E9F9ULL, 0xF9C8BC97545270B0ULL, 0x1CD944EDBB59611DULL, 0xAD81030BB0703CDDULL, 
            0x14EF19DCED52A54DULL, 0x94F3FBB95635C629ULL, 0x4BCA239AD75E200BULL, 0xEFAF4C0E9E42EF73ULL, 
            0x1BA2D4383E20A99DULL, 0x04777EECBE95A0F3ULL, 0xDEDF3296A43CC630ULL, 0x306FF6C3B26E790AULL, 
            0x0E3C745BBBE55E92ULL, 0x1D50126CB0123292ULL, 0x52150859514927F6ULL, 0x56CC3672B88EBA87ULL, 
            0xD0C6CBC668E9D307ULL, 0x6DBD12651EDBC1D1ULL, 0x893E588C0B11FEAAULL, 0xE93A74D38308A3ADULL, 
            0x0FD66634E9FCE924ULL, 0x345E7E596F7083DEULL, 0xF34EA78F4B117C0BULL, 0xC19CB785F162048AULL
        },
        {
            0x26A3B2A5BC016F8BULL, 0xD86E53AE716007B4ULL, 0xE9336A3F97979DF7ULL, 0xA4D20127F87276EAULL, 
            0xA50E0689CD50ACDBULL, 0x6BEDC047F9F4DF64ULL, 0x9AD0BCEC5C587959ULL, 0x4CE7EF09C1633311ULL, 
            0x381B17D271C6CF62ULL, 0x2780441FB83BB07CULL, 0x2A7C77503DB96405ULL, 0x62797B671725BED0ULL, 
            0xCDD3D4A2329D8254ULL, 0x15DFE1E0F64EBF19ULL, 0xCC8E39964400526BULL, 0x833832CA9C6D8E07ULL, 
            0x42672A80F8C23887ULL, 0xC02A84870EEC08B9ULL, 0x4BDFB99D6D4E9730ULL, 0x8CADD792F381241EULL, 
            0xEA24B4B6A44D12D8ULL, 0xD25383B6AE53FADBULL, 0x008B1D312184CDC6ULL, 0x5D313D7227A60E80ULL, 
            0xA81B3B65F9445960ULL, 0xB0FEB11CE6184052ULL, 0x503ACCA5BC656E2CULL, 0xCE2BD5BD96DA5C11ULL, 
            0x28E6096B341E0584ULL, 0x698E9D7D524E1523ULL, 0xC1D7449E5D41C50AULL, 0x03F9473367D37D58ULL
        },
        {
            0xDAACD50A5A4E5B30ULL, 0x49C5389E3FC0ECE5ULL, 0x305671B2BB837C2AULL, 0x6EA61B631A749233ULL, 
            0x171CC2F51F4D3712ULL, 0x3E1A381DFFF411BAULL, 0x13A8C98C7340979FULL, 0x9C8531D5095DBE31ULL, 
            0x1240DB86E9063C94ULL, 0xFBEC00F5F8542C43ULL, 0x930DB066AA5B30DCULL, 0xFF6287BDAF4B7A8BULL, 
            0xDD5107BC5601EDD4ULL, 0xE6742979D2AAB3D0ULL, 0x0AFE7E95CDDE4597ULL, 0xE7C31113A335408BULL, 
            0xC81C37C772FB3004ULL, 0xFFB527A9F28112E7ULL, 0x9549F9FACC200F5FULL, 0x286ED2670C98CECFULL, 
            0x45E812F5F7CA20CAULL, 0x9F7BA95D1CBB1BDDULL, 0x748AE889D9917974ULL, 0xFFA2B800D109C57EULL, 
            0x29898EFA24180888ULL, 0x044B32C1368DECFDULL, 0x59B8705CE6C7CF5DULL, 0xF130E4B74CD591E6ULL, 
            0x7B8EE2787377E5E5ULL, 0xB9EBB6896E954452ULL, 0xF8BB4C4EF8B4DEDEULL, 0xAD3E02CF4CAF0EF2ULL
        }
    },
    {
        {
            0xAE9E63B9D1E197BDULL, 0x985578D96FF9BA34ULL, 0x31144667B0BBF074ULL, 0xB878761494D2C84CULL, 
            0xE086FACC4840D100ULL, 0xDFCDF051765DAB49ULL, 0xAC07275E732EF308ULL, 0x16E7916491C13689ULL, 
            0x2CCBB48BB182DC31ULL, 0x8EDA8D98858EC68CULL, 0x052AC27507419346ULL, 0xFCFD68F95ED96F8EULL, 
            0x526E3B4AF2BDBB63ULL, 0xBF0CC0C7327650E6ULL, 0x1690B1B419B3B2F0ULL, 0xCA4F61DEBADC2957ULL, 
            0xB20157E40A689206ULL, 0x2389848287FA2804ULL, 0x0DEB72971518A291ULL, 0x4A0D039DB36BDBF8ULL, 
            0x1D1C49465535B822ULL, 0x352C2C04EF97E7D2ULL, 0xCE844BF0C015D744ULL, 0xD1E46D800B4D037AULL, 
            0x4768A2C0D7991F88ULL, 0x378E54600762186FULL, 0x64AB4A4FB209C657ULL, 0xB1FC182C53541CD4ULL, 
            0x78346B0396A3DCB6ULL, 0xBD2C22953CB5E702ULL, 0xADCE7CD896426423ULL, 0x6B89C0559FF7427DULL
        },
        {
            0x0E52ED739C1F7D77ULL, 0x8C61E0A67353CD6DULL, 0x569802D1B005787FULL, 0x2AF91527AC086B83ULL, 
            0xB725F0252BFC5B6DULL, 0xB1CC2D5E3D890170ULL, 0xF0BD1ACF3391672FULL, 0x5FEDCB783BDDBCE3ULL, 
            0xCAB2BF38CB3610D4ULL, 0x1EE9C419862EC93EULL, 0x161D57ADFC725C93ULL, 0xD22A3D3006DF45B2ULL, 
            0x68E9F0162D693830ULL, 0x038870C9D5EF1A5CULL, 0x155F1EE5027A847CULL, 0x1E550523DC4AD040ULL, 
            0x716674A33CC1EACCULL, 0xFDD40DC4CB0545DEULL, 0x9DBBD91EBA27ADDDULL, 0x6C265F08FC4C26FAULL, 
            0x75D683638237D41EULL, 0x15D1D94F3BCB6436ULL, 0xF3AB2E823418C3F5ULL, 0xFA9BD065444F9790ULL, 
            0x8B0B4FA2CF6F13E1ULL, 0x0C501E1396D7B3C2ULL, 0x34F4320C769476FBULL, 0xE6C949FBC918D8EFULL, 
            0x4ECE41D1DABADACCULL, 0x6F2008DA026C1F8FULL, 0xC23563C2940AAFBBULL, 0x64FC9C202B59D241ULL
        },
        {
            0x44F8288BD326A3C5ULL, 0x7E5664BC6AEA4E3CULL, 0xC932C60E13EE7702ULL, 0x9FE9FDC34B7DC663ULL, 
            0xC732E460D2917753ULL, 0xF71B078E5D3C9FD1ULL, 0x9F5AEBEFB58AD96BULL, 0x8DF66C6A8FBB964FULL, 
            0x8E7961CCFD6128B7ULL, 0x7EF42615C9DFFC67ULL, 0xD256D835DBF95EEBULL, 0x6CBE423B982F88DAULL, 
            0xCC8BE83AF01E0805ULL, 0xB9338AA11FB939ABULL, 0x746D7C88C52424E5ULL, 0x1F136B1DBA0DD497ULL, 
            0xC7AE6E2DF05EB7A2ULL, 0x336529EB6A3DA083ULL, 0x918C221964FF16A3ULL, 0x91A1D938761E92D7ULL, 
            0x05F5146DB1E7E54EULL, 0x40313B3D74D7C88EULL, 0x58D753E3F1C94E7BULL, 0xFAB207FA6D42D291ULL, 
            0x355F89C27929234EULL, 0x4CB0D0B66C122F53ULL, 0xA215F4D8D9D402C5ULL, 0xE3028E2C0FA64161ULL, 
            0x17EEC291D53E5A55ULL, 0xA7D88FAC9706DE97ULL, 0xF9D26DC1EA05721FULL, 0x4ECD459EC32C86E5ULL
        },
        {
            0x8C5F044A8CB4173BULL, 0x9FF3575C72C0E07DULL, 0x80844E1B4259CC76ULL, 0x6BE98595F810CFB7ULL, 
            0xC5B14132BC245F1AULL, 0x172592C58F1C37C3ULL, 0x792CCAB8ECA45F89ULL, 0x753E16265B49EA93ULL, 
            0x06AF0A126D844429ULL, 0x14B13953F8DF4F5AULL, 0x6E4B03725F188011ULL, 0xBF0D8B652D99745EULL, 
            0xE863AFF10FEEC3ECULL, 0x2EF85634FAEDBD71ULL, 0x24EB514F831FD23EULL, 0x8CEE85917759675CULL, 
            0x532D69CD6BCD0028ULL, 0x9FB9486D4BC94DCAULL, 0x5B3545449DFB8A8CULL, 0x87F9DA4504D7A77BULL, 
            0x6A43AA0DD9F72D37ULL, 0xFFCCA3DB5572FEEAULL, 0x80A7E9BDDDB779C5ULL, 0xCCC915DA20C27664ULL, 
            0x36112AE27A444593ULL, 0x3E5EB397FCEAF55BULL, 0x819A03CD6FEE0412ULL, 0xD078026252799559ULL, 
            0x6183B4E2023656F7ULL, 0x90ED1CA1CFEABFF2ULL, 0x20811FFD051D3A7AULL, 0x6EA3000028503310ULL
        },
        {
            0xAA960CF58962BA48ULL, 0x16DFE852719AA544ULL, 0xE60E0B61D94CC906ULL, 0x44E467994A62465EULL, 
            0xF54F2970CBE10BB0ULL, 0x71CC30AE03A196E1ULL, 0xEDD2F5764DBAC1ADULL, 0x9A4C38599D91B854ULL, 
            0x39D520AC87C437D8ULL, 0x6142287FF80010F8ULL, 0x17AE4DB7D1371A9CULL, 0x7A198B93DF8C82A8ULL, 
            0xC837DC099895B8D4ULL, 0x367AAD7FC0A83590ULL, 0x8DA0AE0688A6FF21ULL, 0xFFC6B538F9E5F0C1ULL, 
            0xFEE5578788BC7BDEULL, 0x02FB4C37720DA3BCULL, 0x000E643B65186E97ULL, 0xBEE4F9E0B6DA28F4ULL, 
            0xB2CE81BCFD8594EBULL, 0x128806269413D870ULL, 0x92FB6B79236082F0ULL, 0xC64E6DF50E0B150EULL, 
            0xA8A88B961E8F3ACEULL, 0x808E08405D2349E0ULL, 0x87EFE6124EC51BC6ULL, 0x3D6A94250128B2D1ULL, 
            0x84AFCE55A60ED013ULL, 0x952CAB11EC9C8F8BULL, 0x0BF6351AF10CDBF3ULL, 0x31AA8B6378F7BDFEULL
        },
        {
            0xF1807918C1F0670EULL, 0x3FA2D4A7E376E10CULL, 0x52EAD1478BEF58D5ULL, 0x0FB69D59A72D8E66ULL, 
            0x510172C73F2CC01CULL, 0x39C467776D50A514ULL, 0x689690C7E82CEA6FULL, 0xA9934C16921D61C3ULL, 
            0x4C3AD4949CB3AC6AULL, 0xE1D4A918CB666C68ULL, 0x17079CBA4A2D6C16ULL, 0xA7A6A109DD33CBF4ULL, 
            0xE5585C9EF0412C33ULL, 0x90DB438F4825FFB3ULL, 0xF6CA655A98AD7B76ULL, 0x31AA9825E4311B26ULL, 
            0xD396515B6184333EULL, 0xF3B8B51073ABC5ABULL, 0xDDDDD832E19C3D6FULL, 0x204D5D38AE2FD427ULL, 
            0x7A38F7066AAF0844ULL, 0xCDD12BD71072A901ULL, 0xF3894022717F6E64ULL, 0xD0303EBA2EBFA3BFULL, 
            0x33208B6C13218F71ULL, 0xF5CE12F51BF84E25ULL, 0x3246AF4442399D10ULL, 0x727C49BE4F0EE3EBULL, 
            0xF6756FFE04D96C8CULL, 0xC513480D3CE0C50DULL, 0xEB1E03AE95060C55ULL, 0x1F22A5DEB15CEB7AULL
        }
    },
    {
        {
            0xB0042C0E19AEBAB7ULL, 0xBC6149CAFD9D2C46ULL, 0x84BAEF62021E9D27ULL, 0x761FBF000B26D9FEULL, 
            0xC1EC0F820A607E6AULL, 0xC27551FF255278AFULL, 0x308E1BEDB84D507EULL, 0x0B516023FBD2D816ULL, 
            0xD7F7CF7E02971ECEULL, 0xCDADFAB7E268DF40ULL, 0x1A626985EFD09A00ULL, 0x49D0ECFF15BB4B43ULL, 
            0x22947C1952E59D16ULL, 0x0FECD72ED4A9ECAEULL, 0x5AD1E837D62F24B7ULL, 0x36538641B12C2B37ULL, 
            0x341D82077A8CC23EULL, 0x162DCFEB438ED6BCULL, 0x1F1765DD5C3E8C16ULL, 0x68E0D697BF95BFB0ULL, 
            0x57CB18B93AD33EB3ULL, 0x30F13BFA2D8C503CULL, 0x362A2BF3676975B6ULL, 0xA39C52E5CEC8400FULL, 
            0x91C70D12022F1C46ULL, 0x6C5B3E5F8B6BD992ULL, 0x7A55D847BF3DEF04ULL, 0xD17EFDD8C2391F93ULL, 
            0xDB5D7610CBCB178CULL, 0xCEA56652CF9653B9ULL, 0xBC77A62C71A36417ULL, 0xC6EA205B7304AD9DULL
        },
        {
            0x8B9BDD00AFF0C16EULL, 0xF16EF6B040050C4AULL, 0x749B5819CC8F1890ULL, 0x539426165FFB9824ULL, 
            0x9A10D5D1B9D678ECULL, 0x05D1E35E96AE7840ULL, 0xB3B9FAF9C7B0A052ULL, 0xB724A2F3AD20C933ULL, 
            0x42FA9E3EFBA53904ULL, 0x33723A0C6C572B90ULL, 0x71C187942FCBC375ULL, 0x466BDCD2B3F0D3BDULL, 
            0x26EEA4E11750729EULL, 0xEF2A1FCF4C97BF6BULL, 0x0F9B672624DF0EB5ULL, 0x26011603BD41D120ULL, 
            0x68F6BBD1C105540AULL, 0x50E00BDF1669AC5CULL, 0x4B2AF676A8772618ULL, 0x963C7AD5EED764AEULL, 
            0xD7ACDBFD55EEA0FCULL, 0xD5FD345B62504AEDULL, 0x31E066AB8E4B581EULL, 0x39211C80D01061CBULL, 
            0x9B949421A9C6C366ULL, 0x169D925775FE9410ULL, 0xCED91781F8402B7CULL, 0x806FDDF316F13B75ULL, 
            0x80014939E8C56C49ULL, 0x5A60A74A633F0B0AULL, 0x7D2F103ED1F91427ULL, 0xD3D991A27FDDA41BULL
        },
        {
            0x8D9F1A7EB2F2BA9DULL, 0xA525F3BDECE0ECB3ULL, 0x16DD1B8753C480BBULL, 0x9DB137CF7E89F7AAULL, 
            0x952327B746C17022ULL, 0x7220143E9E7DCF49ULL, 0x537AAF629ADA8279ULL, 0x5A5EDE48E90A214DULL, 
            0xBEDE4EAFDBA7EFE5ULL, 0x8DD93A313F3CE44EULL, 0x77931191961E0C5BULL, 0xBB8D54E690AF76E3ULL, 
            0xFFCB3009F2BD72CBULL, 0x76569A4253B46BAAULL, 0x7906EA0A8FB1C199ULL, 0x5F81C2F81C665599ULL, 
            0x423D496DDF9B7228ULL, 0x15B863C8BE91D73EULL, 0x79E9877B3D3CB7D1ULL, 0xCDA73318C5501202ULL, 
            0xEAD1BEF687C0469BULL, 0x1AE15EED9CCEDC36ULL, 0xA333AD5D1CEE269FULL, 0x5020A07D1F2C6E2CULL, 
            0x818A56F0CEA8C4BCULL, 0xA9AED767EE28229AULL, 0x5F48512A4EFF7790ULL, 0xE92F9C473F1A9E5FULL, 
            0x7BCA7D5B15F3A286ULL, 0x33BD46AA854AEBB5ULL, 0x9C521553A81B096DULL, 0xA334BD772FE3094AULL
        },
        {
            0xE4CE1ED6E578241CULL, 0xC599CF2EA5E1B361ULL, 0xC385E5E778B6AA21ULL, 0xD0BB6125AF1DD7ECULL, 
            0x336691AF52EC61C1ULL, 0xE9956D0558EC1EF2ULL, 0x21206F2248823381ULL, 0xC5166F19A5F3718BULL, 
            0xBD76509F7B507CD2ULL, 0xB659DC83DF909F56ULL, 0x6C030EA2C5F02345ULL, 0xEBF7413A717B9B89ULL, 
            0x398EBE0BFAB01CD5ULL, 0x699D5FEF81A3C83AULL, 0xED37663CEA6F081AULL, 0x108568C477AE47BEULL, 
            0xB90AE4FA91CB9CCEULL, 0x157E2775FBD1D42EULL, 0xE0662EA68F3D5B2FULL, 0x4D9F6F3B2FEB7B80ULL, 
            0x9B0CEB0A848260F8ULL, 0x27A4B30DAA40EB19ULL, 0xA542E7323B44614FULL, 0x64FDECDEBE1E699CULL, 
            0x83608B2CA321FD78ULL, 0x1CECCB0C2FBBE074ULL, 0x4E471E267FB4AB09ULL, 0xDC2EB5124F0A0019ULL, 
            0x70E89C8EBAF15BFFULL, 0xD5AACEE20927B3C6ULL, 0xA9A3BD4681D0EFE7ULL, 0xDFD7FF8F995F4791ULL
        },
        {
            0x1E3CEE11AEB50575ULL, 0x5D0E01A309603EAAULL, 0x9607D7546F921EDFULL, 0x7CCF22C85C2DD184ULL, 
            0xCFBE3C3DEA6F10EEULL, 0x73C714F37D7875F6ULL, 0xE666EB864A4E93E2ULL, 0x91F975DEED689818ULL, 
            0x47D6B72290E10CD3ULL, 0xA46B8DA4B6171542ULL, 0x1D4C15591364C954ULL, 0x7680E0D5A57070DEULL, 
            0x9A4C91B6F0A0CAF0ULL, 0x4B2DACE558794F2CULL, 0xBE24FDE663E3EF80ULL, 0xD2AD72D504F07D72ULL, 
            0x25DEC770AC3FDDACULL, 0xE13071FE3065F703ULL, 0xE9BD238F6D9EA80DULL, 0x0BAC1CB6A43554BCULL, 
            0x3EE177B7878DD5F0ULL, 0xB96866D883B5BCFCULL, 0xD639DAF012A4A50CULL, 0x0ED08FF88BB03212ULL, 
            0x23092EFA07C4BE72ULL, 0x36BCEEA9B1175746ULL, 0x7427CF13EDEACA6EULL, 0x61A0670C7676F497ULL, 
            0xEA281DB7B9142E0CULL, 0xE67CCB13CE48C957ULL, 0x50BD9F1143324DF8ULL, 0x089B624DBF254448ULL
        },
        {
            0x1D3E91FE794EEE05ULL, 0x171B9597EB44C2ADULL, 0x98EDCA17043DE7E5ULL, 0x3ABF1ED9E9C379BFULL, 
            0x4967A79299D5560CULL, 0xB60CEF61E48B9AC0ULL, 0x41538E785F3C1598ULL, 0x18F849DAFDFB8AF4ULL, 
            0x86BF867C4C55253CULL, 0x7FFE6056AC18D5EDULL, 0x0370BBE5DD3C1082ULL, 0x465A21424849F2C3ULL, 
            0x075A7C28F7B3E191ULL, 0x7059CC8B187321F5ULL, 0xB0D387DF6222059AULL, 0xBF28F1B99E8C2FD8ULL, 
            0x8EFD8D06C10A71D6ULL, 0x6FCCA979CCE90A40ULL, 0xE83FBE6668007918ULL, 0x63FFB8F143EC2069ULL, 
            0x3C98D27A3A32BF10ULL, 0x6788543C5745C8DFULL, 0x30235C0ED017349EULL, 0xE1613DA8CDF0174CULL, 
            0x3B56FC10293656B5ULL, 0xFBA0E2330384666AULL, 0xFEE9342F9E3EEDE1ULL, 0x87DC9AE9622A17ECULL, 
            0xC52D57DAF0257C94ULL, 0x5C33FF89C7A5F364ULL, 0xC319D0D1AE5352AAULL, 0xFFFC53BB0B5458AFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseDConstants = {
    0x9E9BA0004272FB9FULL,
    0xCFF689D39D6298B4ULL,
    0x1454332201E4B47BULL,
    0x9E9BA0004272FB9FULL,
    0xCFF689D39D6298B4ULL,
    0x1454332201E4B47BULL,
    0x4C12F89111E2EB11ULL,
    0x58331A4CA2DDE3DFULL,
    0xD0,
    0x66,
    0xA0,
    0x88,
    0x7F,
    0xB3,
    0xD1,
    0x9F
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseESalts = {
    {
        {
            0x9080389280DEF61FULL, 0x7D5F30605DFFC05EULL, 0x8B9DDE54957AA44BULL, 0x2CD8DCB712C6704DULL, 
            0x78EB2326802FD5A3ULL, 0x147D0F81E6659B48ULL, 0x4BC7E767EF374172ULL, 0x4C51CEF989E6A60BULL, 
            0x588ECDCC1E3E2894ULL, 0x48911ACC574B0CB6ULL, 0xAF06A9484E8FE832ULL, 0x7DC522D466FFF3D1ULL, 
            0x63A302C032E337ABULL, 0x9B9592C4516803E7ULL, 0x5AD68030DBF34C7AULL, 0x749F2E59E3C27446ULL, 
            0xF6E25DE18ADA68E3ULL, 0xF2281C924E4197A2ULL, 0x2E4B8AFF0FC4EEA1ULL, 0x8ACAF482C1E2B4D8ULL, 
            0xB97AE39714C4C9A8ULL, 0xC8E08090049E0D38ULL, 0xC56E3FAF644C0843ULL, 0x92012CA5DD68C0F1ULL, 
            0x2B106533A57D3FFBULL, 0xD50C19D4B2A676D8ULL, 0xFA78E725ED4791B2ULL, 0x94BE62564B9D40F3ULL, 
            0xC76F4A2A751951D0ULL, 0x92759093B31ACDCEULL, 0x63AEDA07092EF292ULL, 0xBC7C641031CA694DULL
        },
        {
            0x872B33410B4A3B0EULL, 0xFD6C88966B42153BULL, 0xC29ABCC17C01EDBAULL, 0xE96090361A5828A9ULL, 
            0x39097CDC6F6913E1ULL, 0xBBDFB9EBB30CDF03ULL, 0x4DC0EA9A72A10128ULL, 0xE13275DC5FB0062FULL, 
            0x65FA894879F4E46EULL, 0x333222DF2C4B722AULL, 0x3446DC461708901CULL, 0x526F3C813D0AF63FULL, 
            0xCD843CC730EB644AULL, 0xB68570EDCCC88234ULL, 0x99C11F5FF877ED33ULL, 0x6F9B962DD04FC0DDULL, 
            0xDEC0F9C9546CCD68ULL, 0x39532E4EC85CB85FULL, 0x67BF530CF63E94FEULL, 0xA51AAD426DABAE11ULL, 
            0x3972353DECC6E169ULL, 0x7044E1D221C9E619ULL, 0x5F32063AE17C0E52ULL, 0x7E749E150E773130ULL, 
            0xA8071DFAC373F6A8ULL, 0x58C19BFE74635168ULL, 0xD09DADC287BA64A3ULL, 0x2A5D701DEC898BB2ULL, 
            0xE5390240DBE21EF5ULL, 0x26AFB98F85045719ULL, 0xCC7AB4550E0A46C6ULL, 0xC95EC0C0C4B54664ULL
        },
        {
            0xFE058EF81A760B4AULL, 0x4ABDA8E202835AD2ULL, 0xEBB99FFE27FA8C9BULL, 0x2DBC20B55246C965ULL, 
            0xB19A27BB0E9BCB5FULL, 0xA3CCEDD0F7EEB800ULL, 0xEC7B137076CBC588ULL, 0x766B7ABE079B1B67ULL, 
            0x595A4BDE1E7AB4F8ULL, 0x40E2408915AFCD63ULL, 0x06554C9C848582DCULL, 0x84EC6D09B08E9DCEULL, 
            0x088DDF15E94BBDBEULL, 0xB37F275F77C1E940ULL, 0xF4DA4CAA07493B54ULL, 0xBA4E49719DDA45CBULL, 
            0xCA767AF2E9A295FDULL, 0xEC3B7DD31F53E8B3ULL, 0xB895DD399EA78ED7ULL, 0xB7A7311231E2AD63ULL, 
            0x7871CCB302EF970AULL, 0xF238DAC965E665AAULL, 0x9F99A43099B76C8EULL, 0xAF13EF0518F6A2B0ULL, 
            0x0D2D3720261E48C6ULL, 0x092E4D8AB4C16548ULL, 0x6D11CC34DDA9CF0BULL, 0x91772FF37724099BULL, 
            0x9F5796A3DD0997FAULL, 0x5ADA5F9AD98DF86EULL, 0xB2CF227FD2741B08ULL, 0x432985CA1AA04DC6ULL
        },
        {
            0x9D7C65AAB4529DBEULL, 0x997BDF5D5D6A9A83ULL, 0x450BF5E22DFB942AULL, 0xC50C195D8A2861BBULL, 
            0x43E2E9C4FEAF12A9ULL, 0x2DFA249190243851ULL, 0x37A9D0D6BA015D2AULL, 0xAF90DB081CED2573ULL, 
            0x8486B678B0C8B613ULL, 0x2E85AEF6D9EBE235ULL, 0x6B3FF9A6E6565B22ULL, 0x4AD543BA4E52A8A0ULL, 
            0x4BF8199E7C809DC3ULL, 0x73CBF0DBB3631D61ULL, 0xE122B5E0B164AE37ULL, 0xB1A535DFD75C801CULL, 
            0x22A1A481EE653C78ULL, 0xEEEC6AEDDB10E6E7ULL, 0xEE58DFC44EFE4DCFULL, 0x5607C3DE9E86E61CULL, 
            0x82F7608D003A70E5ULL, 0xA2C878210DC28713ULL, 0xBDB6D6FA04574C68ULL, 0xC0B44DDB2688FF1FULL, 
            0x74FEC76FE15A7AF7ULL, 0x22D5F1D9302BCB7CULL, 0x2F28765019368620ULL, 0x26751AD65A968A8BULL, 
            0x42676F5189D3D468ULL, 0x9D97BE182DCE3B68ULL, 0x56E30CAFFCDCA470ULL, 0x7705BEBD24E1E2ACULL
        },
        {
            0x6E86C03333948B93ULL, 0x755BD16881C42456ULL, 0xBEA9F76513524416ULL, 0x233561AE6E03B95CULL, 
            0x9B03D13B01BF7346ULL, 0x2F4C5EB93C343FCAULL, 0x056D56DE9633C21BULL, 0x91836C0D65895079ULL, 
            0x9378503E1C5F7A7DULL, 0x624F043B866CC2C7ULL, 0xEAE09C3AA0FFA38BULL, 0x6DBF035F48095B8FULL, 
            0x173C1291B34383F6ULL, 0x06AE069E677BF5E7ULL, 0xC2C261CAF674EB0CULL, 0x1B83073A61EC4514ULL, 
            0x264D01EF3D80E469ULL, 0x68F07B045BCABCFEULL, 0x9E3190088F188553ULL, 0x8BE7B4585EB94CDFULL, 
            0x6FC2B912CEDD30F0ULL, 0x1522861470339BB8ULL, 0xC2F6507D2CAC0C7BULL, 0xD1282DE612285393ULL, 
            0xE36D5506BE1A39BBULL, 0x8ECD52FA4303ABB7ULL, 0x06D1E59EDE48429EULL, 0x3A5BF402A94283FAULL, 
            0xE6493ED2BC212EC0ULL, 0x3058CE528C65ADC3ULL, 0xB5E3D6388FA0C547ULL, 0xDF0FF455220E80B3ULL
        },
        {
            0xC64F66D4FD286385ULL, 0x332D777D0057409EULL, 0x6391596004BC688DULL, 0x0AD92BF48913ECB1ULL, 
            0x5549FC6DF64F59B9ULL, 0xAD9F850A0CB887C9ULL, 0xA6AE103FB2E69B73ULL, 0x0418207B070BD2F9ULL, 
            0x8974385964B4BA28ULL, 0x87E2B4F7F7757A88ULL, 0xE0FADFAA1AC47914ULL, 0x63E0DBA1BC5797F1ULL, 
            0xF5261242F6B854A9ULL, 0xCD7540C1B46FBC0AULL, 0xE9F985000C28C2E9ULL, 0x571EB04343E1B13AULL, 
            0xF365E850135036E6ULL, 0x97F9965D240FC0ABULL, 0xF9C1AF0524485F8BULL, 0xE1D4C532310A4631ULL, 
            0x6D68F5530530C586ULL, 0x4B53CADED4B69279ULL, 0xE5342F58F2A7EDB5ULL, 0x654666865F5A1471ULL, 
            0xCF69F6985850839DULL, 0x03DE2727B4CB4C4BULL, 0xCA3ED0D154014F68ULL, 0x898B34E84DA75A61ULL, 
            0x64C5AF84487D6C0EULL, 0x58734FB61B5C585FULL, 0x59D3DB10DB054042ULL, 0xFB5D3F45C7CDE90BULL
        }
    },
    {
        {
            0x2E9EA611FC78BC20ULL, 0x7CCDA5A37A194F25ULL, 0x48DBA5149C061E1CULL, 0x6017D59BAA903DB8ULL, 
            0x6454F3DF6DFDB6F9ULL, 0x997DDEB528E97822ULL, 0x50807115E922872FULL, 0x49201126779C386DULL, 
            0x8720613094E16445ULL, 0xA96C6C46E666DF34ULL, 0x39F0587916B8793BULL, 0xC5F1B53010D85320ULL, 
            0xB0D052F932A7D609ULL, 0x6EFEA4539D22453DULL, 0x0C8AC51D754EB125ULL, 0xE0B84CEB4EE7A325ULL, 
            0xBC6617E595F3971CULL, 0xAF80DC7DED06DFB8ULL, 0xD1E80FB6BE7FB823ULL, 0xECD5F4BE01847F99ULL, 
            0x595CC486ABDED1D6ULL, 0xB01C840EFBB2DB5CULL, 0x73EF4869065828C0ULL, 0x4A645F92CA61CB5EULL, 
            0xFFB3DCCEC6B56E55ULL, 0x48ED0CAA6985CBEEULL, 0xD5B8B3B522195651ULL, 0x54D73F7306FF4CFAULL, 
            0x52F48AC6C6F11ED0ULL, 0x5DF97BFD63E654C0ULL, 0x2F74871217B79FF4ULL, 0xF37D07902D430625ULL
        },
        {
            0x0BCC2D6BC299B1DEULL, 0x6BD23BA0BB166A1AULL, 0xEFF2269784B8060FULL, 0xD36C1EB17206D47AULL, 
            0x333A9ABD63EC0F29ULL, 0x87D41AF6CBA87B85ULL, 0xD308BEFF06B80519ULL, 0x625D050D627D6AE7ULL, 
            0xC5585775F5554BB8ULL, 0x0741525DDBE1D447ULL, 0xF982A4C8297EFC79ULL, 0xFDBB48462C29770DULL, 
            0x53325FF18BE0BC4DULL, 0x1F6EB9D0EE6A81B4ULL, 0xE7C5A4F3379B4AE8ULL, 0xF4A977FFC9CB32F2ULL, 
            0x3839ADE871BB4502ULL, 0xAD1CB418CB450E76ULL, 0xF4122743D1BDC23FULL, 0x66FAD59EC9EACE24ULL, 
            0xE399CE141BC34EE8ULL, 0x271CE7D7627F660DULL, 0x9E6D2B6E49EA789AULL, 0xD453EC7A0C30D70BULL, 
            0x742062A06A4852C6ULL, 0xC2EEE8B86CD0C6BEULL, 0x0D350C37E1BC7EF1ULL, 0x661C0CAE205C11C5ULL, 
            0x864E382BD07D88F5ULL, 0x4FB8EF8AD9FBDDF4ULL, 0x222942BF4CAC5299ULL, 0xB13153E150B2A2F5ULL
        },
        {
            0x39EAE021ADC39A6BULL, 0x6871D70E1C9D56E5ULL, 0x1EF7C9C5489D95D8ULL, 0xE858B4C680D64476ULL, 
            0x9F5671614B7CAFE1ULL, 0x741641338C9E7B6CULL, 0x8E856A623CD51E9AULL, 0xFFA1E59171A20B21ULL, 
            0xF18942B6592701F9ULL, 0x2F691EBA22882BC2ULL, 0x7AE3DC210537CAE6ULL, 0xDC5F411C139A3CE5ULL, 
            0x1F0379A59DE6C2C6ULL, 0x7DCB25F7F27DFB65ULL, 0x2E9EC80F68803CB2ULL, 0x07438FED46CE5ED3ULL, 
            0x1EE8AC8F500854A0ULL, 0x447A8790CE6C6725ULL, 0x48FC9D2C79A824CAULL, 0x3423C1C718D76430ULL, 
            0xF80821E2D2442B66ULL, 0x7AE71FD55818F4F6ULL, 0xDC10189CCDC26FF1ULL, 0x52D999FF7F0680E9ULL, 
            0x43D175CD3B6C7842ULL, 0xA75CFC72A29C301FULL, 0x69F1394C9951FA48ULL, 0x015FF222834735A4ULL, 
            0x607955C16EC613EAULL, 0x5A11533B4B5CC493ULL, 0x35B2B05AAB6BB353ULL, 0x901C5AF932FD9D92ULL
        },
        {
            0xD0A760B2DBCDA7DAULL, 0x32602C28497F34C1ULL, 0xE034FA45F801217BULL, 0x7CD5644F1C0FDA70ULL, 
            0x7ED5F049A3C55520ULL, 0x666C47A7466813BCULL, 0x20D62C101465F236ULL, 0x07BAAB35216B73D1ULL, 
            0x31CFE47DC315A28DULL, 0xDB9ED7B6F5DE3BDCULL, 0xA6CFDA65AD8F8229ULL, 0xE3584E0E33E54D2FULL, 
            0x335FA5D552A0BFD6ULL, 0xFB65B46D70511366ULL, 0xB346899CF0D017B7ULL, 0x600A4F85470DBD87ULL, 
            0xDF84B787BDCB5111ULL, 0xA94FA8640113E1CEULL, 0xFEC2D9A01790B049ULL, 0x015BD1A63E8CECE2ULL, 
            0x21F201F582EF613DULL, 0x8EECD23EA086E0AAULL, 0xA4BC8B3ECE60E5FEULL, 0xDDF5D2F00D421901ULL, 
            0xC7D6C19E528B5487ULL, 0x23D18BD8AEA73368ULL, 0x958360023964B172ULL, 0xEC2A722CE448E504ULL, 
            0x12943536A3D70B97ULL, 0x337C61FEB982CE00ULL, 0x3A70E9E8288564EAULL, 0xCFD18D4DA7324FF8ULL
        },
        {
            0x30E5FF5AAD01CBF1ULL, 0x5C1DDEAC4D056FEFULL, 0xB5391FF305BF0A58ULL, 0xEA6A8FA33AE803A5ULL, 
            0x423DC2BFC7EA7AE3ULL, 0x16EA18BF2552C376ULL, 0xF9E9A56892695031ULL, 0x86A1A80C30092570ULL, 
            0x4354F2FEC8C86B77ULL, 0xF72A62A34D921C23ULL, 0x92F06031D721D027ULL, 0x277B464CE49AE97EULL, 
            0x5D134C05F66DF7B4ULL, 0xDA4AD4362A961648ULL, 0x4B86D5D6D0B6C6ABULL, 0x15876CB01A9F40E9ULL, 
            0xD60CAD7D425FDE4EULL, 0x73854C4A5756E09DULL, 0x1F9C8880F3A2BC90ULL, 0x9F959F5E6A0A5016ULL, 
            0x40F56649DC5D22D8ULL, 0x6EF25386B4488D7FULL, 0x4BEC82C49DE2E72EULL, 0x7392F99A4733BB9FULL, 
            0xABE9982B166CED05ULL, 0xF62BE8F4D6B02B7BULL, 0x1AF4BCB9E3EBEF31ULL, 0x26C6ACB5B6008EE8ULL, 
            0xCA5F09CCB189F3E5ULL, 0x2B2643B49A49DB1EULL, 0x78EDA8383E76DD09ULL, 0xC428EF943C61CB53ULL
        },
        {
            0xA3E97113AFAE7A00ULL, 0xAB5C23262DF6C9ECULL, 0xDA3015ACDF321940ULL, 0x080DC9E39AC85625ULL, 
            0x5BF52A8BBD5A3E09ULL, 0xF9D0947AE8ADA3C0ULL, 0xD5742434C4AA680BULL, 0xBE7589965E7375C8ULL, 
            0x11AED3B427C4F61AULL, 0x47A557DC117CAA39ULL, 0xE05BE1828D1F4624ULL, 0xEC3F74D68A030DC1ULL, 
            0x04CF59FD25A0D7D5ULL, 0x63ABDA788A42B377ULL, 0x8EB79D9949218F79ULL, 0xC90988CC125DA5A8ULL, 
            0xAC95E415C8B671B3ULL, 0x176783FA879FA6B6ULL, 0xAC7902ACEAC5FDF4ULL, 0x50D48270FBA413AFULL, 
            0x576E7B2FABE02A54ULL, 0xB159F7479B7EF1C1ULL, 0x3C4F35732FA6954BULL, 0x73856C3E07032464ULL, 
            0x29F49A81FB19D16FULL, 0xAC0706CACF199CC4ULL, 0xDCEC6B4B9F535AA7ULL, 0x2C546E6BE10C3B0EULL, 
            0x79D34313FF65AE86ULL, 0xE100D7AC0225BF38ULL, 0x277194B01C3E1232ULL, 0x167319627AA99899ULL
        }
    },
    {
        {
            0xFB56A76AA2E5F05BULL, 0x321A5E560843B832ULL, 0x73CABFA23683D57DULL, 0xAE48F494817EAF21ULL, 
            0x435BF7C1AE9FA9A5ULL, 0x0394470CF7B1CE57ULL, 0xAA3778DE8FCDD0D0ULL, 0x1414B1417FBF26E1ULL, 
            0xA8F2E99B9D5EE0FBULL, 0xEF41302CB2B7DA89ULL, 0x04BD91CDD151D66EULL, 0xECB5390069342103ULL, 
            0xE1B9266EF0026241ULL, 0xEB6C02CDEA450734ULL, 0x6B5DD24C5AF3CD95ULL, 0x26845B6D1A172688ULL, 
            0xA904CFB295DEAF9EULL, 0xFA46DC79711EE87AULL, 0x5AC07767DE32A1A2ULL, 0x95A7E85FF7F77157ULL, 
            0xC5C36BDB18E11F93ULL, 0x937017844FD7D509ULL, 0x480275C03FE6505DULL, 0x9ACCA1A00C058D39ULL, 
            0x5037C389730F4AE9ULL, 0xED83A78662624496ULL, 0xF8CA0D16C1794FAFULL, 0x53884ED1900E872DULL, 
            0xDAA828B0CB5F85D9ULL, 0xD52DE92E5E9FC30FULL, 0x215BE3BF839F99D7ULL, 0xCB59A46E61DF5F5CULL
        },
        {
            0x96C73398EE5D9C7DULL, 0x76F065B69AE34D54ULL, 0x333A8EE46E52C113ULL, 0x616A63A41AB49F3DULL, 
            0x4C35FB5E7A4E83DDULL, 0xEC5E011F07318087ULL, 0xA54B98A722F667F0ULL, 0xD01490034A81536FULL, 
            0xE2C905ED485CC767ULL, 0x3BBED9A11E4020F8ULL, 0x04715F751C4D3A3AULL, 0x9A1183DFDDF68095ULL, 
            0x72E47F757C3C8F71ULL, 0xF69FF06D438AD1AEULL, 0x59B671BF9951E941ULL, 0xE4E8E8FDD6D0F625ULL, 
            0x0B168681F366FC1CULL, 0x7083DB6D613DB809ULL, 0x11031C85BFF5EC7BULL, 0xAFFFD60B2AB245ACULL, 
            0xE970562640DA1C94ULL, 0xB560C363500A352CULL, 0xABC6A9FD6DA9E047ULL, 0xEA9425C28A701F5FULL, 
            0x3A2D91499C5EEE8DULL, 0x300C84E288688A87ULL, 0x1CE8D6416AEA50FFULL, 0x09D992BF27DA2587ULL, 
            0x1562C6EFA3BB0F54ULL, 0x72FC71001ADFC3EAULL, 0x2EE0C934BE5B0E3FULL, 0xFE2F1C61B8119436ULL
        },
        {
            0xFDFA3D4FED8D9451ULL, 0x43BAFEDF2A89668CULL, 0xF5C7A24F70515E8AULL, 0x32FA393F8963964EULL, 
            0x40E25E0A8990CEC1ULL, 0x3988B81D876C747BULL, 0x1087FD30636198D6ULL, 0xF919660E2D85C8C8ULL, 
            0x304C5D84AEE9945DULL, 0x95B0E0CCAB2F5675ULL, 0xF9D901CDDA6385D0ULL, 0x88ED308B1B5F4C1BULL, 
            0xE7ACF2832022772DULL, 0xB2F1EEA210A67565ULL, 0x8FA68ED50276F799ULL, 0x160F46DC033E5D9CULL, 
            0x6698976EF9AC8529ULL, 0x1B0FE1C0C416E762ULL, 0x9FE2EB59813F42F0ULL, 0x1517A5E0C12E50E9ULL, 
            0x194834E6ABA618ACULL, 0x3B6ACD39C86A836FULL, 0xD1DD3831DDE0AE56ULL, 0x05EE9C98967AE946ULL, 
            0x93179482191B1D13ULL, 0xCF9D789AE674144FULL, 0x2DB97E34657984F7ULL, 0x78762F6D8F6C84B0ULL, 
            0xCFCB5549D7FEBD29ULL, 0x2D28AAF969C5874BULL, 0xFC5DB37299E501A9ULL, 0xE8BBB32B79B966E8ULL
        },
        {
            0xD936A9BB784B3464ULL, 0x73E88C5CE763C106ULL, 0x5ECBD0252F591D79ULL, 0x677594C7441CDA20ULL, 
            0x77EEAAE3E97E8561ULL, 0x083A77B06F44937CULL, 0x6ABD47DC06EF6EF6ULL, 0x4FA91B957961E76BULL, 
            0xB0CB3A341BE9741CULL, 0x755B366E279029E9ULL, 0x2FA3AEA792EE0242ULL, 0x3D17F27A871790D7ULL, 
            0xE180EE0CA42A8698ULL, 0x3A332A3AFA6F1E6CULL, 0x73F3D33ACFB176A7ULL, 0x418ACD158F0D9173ULL, 
            0x4B108C9DC5DBF81EULL, 0x523050FFBC170C1BULL, 0x3123E19416604264ULL, 0x15E737F435F047ADULL, 
            0x9C66D4777126021DULL, 0xDD6FEBE38C547D52ULL, 0xE7973C722BAEEFB1ULL, 0x8B7465C2603E0804ULL, 
            0x6B7F503F4EBDE6D5ULL, 0x090A3BA6DCB1E39DULL, 0x326FBFC73C48F6B0ULL, 0xFFF01E8B14BA88B7ULL, 
            0xCA7DBF52973ABA70ULL, 0xA0B2D694EA114355ULL, 0xB4F5CC0D9A0DB821ULL, 0x979B9660224C57F9ULL
        },
        {
            0x13C8A0D9657BE99EULL, 0x1BE5ADB468E1B8FBULL, 0xA1FE028482DDE28BULL, 0x3B575E1A898AC703ULL, 
            0xD19C3B5E09672507ULL, 0x7979A79C9CBBF095ULL, 0x0EB749680B4743E0ULL, 0x040337590F755BE3ULL, 
            0xBD34680A33AB468CULL, 0x5391AAF7C2EC9F78ULL, 0xCE4E827488B98BD2ULL, 0xE4C5710FBE3C743AULL, 
            0x0589E121FE6B037AULL, 0x3E8D38EFFFB93C4DULL, 0x279F8278F57B6C14ULL, 0xF2E7386823110070ULL, 
            0x986AC852433B0A7DULL, 0x03E49A031C763F7BULL, 0x9A8CC185F9D05712ULL, 0xCD2A58AD24B1D5C5ULL, 
            0x34E1DC3246415978ULL, 0x12CF4F120900C468ULL, 0xB62A608D3431CFB0ULL, 0x1DD79ECC43F72579ULL, 
            0xE716B9C7F85128B8ULL, 0x252A339009750154ULL, 0x3554B7BDC934E555ULL, 0xD1EA0405387EA10FULL, 
            0x13C781B818AEBF68ULL, 0x9A2E5C69A0773D64ULL, 0x6352FB36DE8EE39DULL, 0x88288E34C64B3770ULL
        },
        {
            0x274997E1FFE93923ULL, 0x0C70FF831CA0ADCFULL, 0xFD7CC3508C0A72F2ULL, 0x4DD71BB07B1844C3ULL, 
            0xEC171F5756346978ULL, 0xB3B0DCE1D2F013ACULL, 0xC6D4B0C2F1B9EA2CULL, 0x90F0BD3AD87F422DULL, 
            0xDCC7B7745D2871C3ULL, 0xFFE2C948D0B6C838ULL, 0x72AB001376CEDAEBULL, 0x33117292CB30722AULL, 
            0x7046C2D2D39DAC4DULL, 0x14C8F2B4C4C1530FULL, 0xC4A90774FBB9A193ULL, 0xFF6986108F9A6430ULL, 
            0x2DAC84D56E23D3F8ULL, 0x0D258A2F3DB621DFULL, 0x6A4F159C578F39CEULL, 0xE3BB3E1D03960386ULL, 
            0x7AF34A0913F105A5ULL, 0x05D930643109F63EULL, 0xACC25F2375CB6202ULL, 0xE95B1B2A2FF115BDULL, 
            0x1FA3DCB23E9A0D7FULL, 0xE1D2E0CBF4D41D56ULL, 0xDD1CD2B414F2312BULL, 0xD4981E51518BFC90ULL, 
            0xCCB6975D66588021ULL, 0xD015AB44147D499AULL, 0xE599C37769797C87ULL, 0xFD913776ED5C1E0EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseEConstants = {
    0xA71E23D1BF257731ULL,
    0x8C39460CA66F7BCBULL,
    0xC1EF3BF64DEC6275ULL,
    0xA71E23D1BF257731ULL,
    0x8C39460CA66F7BCBULL,
    0xC1EF3BF64DEC6275ULL,
    0xDE100B7972387024ULL,
    0xE4EEB1078150A57BULL,
    0x66,
    0x64,
    0x28,
    0x16,
    0x2D,
    0xEF,
    0x70,
    0xF0
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseFSalts = {
    {
        {
            0x881A3E5E476710EEULL, 0x8F71287AE8441CD9ULL, 0x78F1A2CA2123BABDULL, 0xD3782E4AAF6871E1ULL, 
            0x66008E3539C82767ULL, 0xBAA4A7B0AA9025F9ULL, 0x05DEE9DB6D67301CULL, 0x9DD54F4AAD20F202ULL, 
            0xF553E0A4D50E5E13ULL, 0x9F68D630906505D1ULL, 0x44F45711AE145313ULL, 0x3864D115126F8D82ULL, 
            0x919813762FB18006ULL, 0x7A6A53A04425B615ULL, 0x3E54ED6E0D8C4A0AULL, 0xC8B3DF72BF3CD210ULL, 
            0xEE49018A5C9204C7ULL, 0xBAF775E38AC4700FULL, 0x48D951E9E286C633ULL, 0xF7F08A7E325F61E8ULL, 
            0x474339B0F343F0C4ULL, 0x5E4725F60F0D204AULL, 0x6321B7697F44F153ULL, 0xA0F96BFFF9C4678FULL, 
            0x93EEA4D5230117CCULL, 0x5C861490810548ECULL, 0xA446C5F38B86C5A0ULL, 0x29E27D40E2BBB76BULL, 
            0xEF5FF799B92A7132ULL, 0x2A713E3CC3CB7EC2ULL, 0xED5BC173F44FEE0FULL, 0xB109FFB446EBE876ULL
        },
        {
            0x0C8B4D551406E986ULL, 0xBB8607ADD3B8FC47ULL, 0xE88CA3D0F69F568CULL, 0x605CBA739B46456AULL, 
            0xBFBDC60AF2B9FD1EULL, 0xA2321213D8BC0401ULL, 0x36AEB73908BFA3F8ULL, 0xADAF5A0712F5006AULL, 
            0x8B2D7F3B6BCD0494ULL, 0xD2C03345485D3CE3ULL, 0xE45CF097BC52E120ULL, 0x65566DDAEB70F1E1ULL, 
            0xC41B8EB85A124111ULL, 0xE57194F937C38C73ULL, 0x1BFE1DFAD3004E6CULL, 0xA64D2EBF0749FC02ULL, 
            0x16856FEE0AA49B80ULL, 0x18387025791B31F0ULL, 0x1664C5C0DB11BF3DULL, 0x50578BC0DB8691A6ULL, 
            0xA11AD75F227D6DDAULL, 0xBB080091DE8AF572ULL, 0xD7BE5BB33A8167EAULL, 0xFC99533480D0063DULL, 
            0x70D0F9948CE6330BULL, 0x7C9133702DE3B16FULL, 0xAC6D1B083689D8DEULL, 0x940928AE662E4460ULL, 
            0x2C068C4FB538AAEBULL, 0x5C2F1077EBDA477AULL, 0xAD65F42D549D3F96ULL, 0xD2956DCDFD62E984ULL
        },
        {
            0xF4ED1B2F903B33F6ULL, 0xDB7D8998AE16EA74ULL, 0x088E457EB175AE79ULL, 0x102DBAEA54B5C4C8ULL, 
            0xA905DD4EF1C3ABF0ULL, 0x7B248CC73096D742ULL, 0x83FA98C630377066ULL, 0x395BDC0D0956DFEEULL, 
            0x3DD236A5FA326895ULL, 0xE34F0E6A9C5A2E6EULL, 0x605B4E6BB5DCF21CULL, 0xD209FD210B2A6795ULL, 
            0x9A2F9108547D5F1DULL, 0x46DA5EBF138D284BULL, 0xDF12A1C8A606AA4EULL, 0xB14E54FD79DD545CULL, 
            0xBFBA05A34ACF02C7ULL, 0x4BF870F763E78C0CULL, 0x0F5DD41D3B4E9652ULL, 0x49D1C49E9E8B5A39ULL, 
            0x57BEC90F78440E3FULL, 0x09F0595C5AC1E069ULL, 0x3D0AB99CC5EBC3C3ULL, 0x7D743F2D29B11485ULL, 
            0x11E6297D5AC6EBCAULL, 0xAC0A1AC77B25743FULL, 0x46D70A14AD927EA0ULL, 0x7E3197B921E1D0A8ULL, 
            0xAE46945D96E83967ULL, 0x9E89E8BBA035A470ULL, 0x81F332B9D2ADFFBDULL, 0xD9888A4049FA2445ULL
        },
        {
            0x722CCBA3475FB7B3ULL, 0xF9B40846D7B84D71ULL, 0x95DAE441989A2AA0ULL, 0x41CEAA9282B3FBFAULL, 
            0x20DD6D2D27E0CF60ULL, 0xF2F88675C186FC78ULL, 0xC940FB83478E8870ULL, 0xA62FA67ED3C3406EULL, 
            0xA921D9CD331E0159ULL, 0x13A4E7DEDCEC5C70ULL, 0x25517FDCF916AA56ULL, 0x0AA02E458FD0834BULL, 
            0xC14464CF52CF4FECULL, 0x51D0DE0D6AA57B2EULL, 0x80760724C213902CULL, 0x1B8334CC10BF1947ULL, 
            0x1B5CD2A27A789B58ULL, 0x084CCF6212B34F61ULL, 0x25E122540A42C126ULL, 0xCDB28ED9DA21A5D6ULL, 
            0x71DE763BD4441521ULL, 0x61B9B0B0C45F7C6DULL, 0xC8A9CA225FED136BULL, 0x180BC6A6B9C12CD9ULL, 
            0x7A2C66F134248068ULL, 0xA311E18B89B3334EULL, 0xD8C12A10435EDD6EULL, 0x07AADB695A7CE2C6ULL, 
            0xEA1623C226A90260ULL, 0xC96ED03A3E2DF0C4ULL, 0x108A18A295676A9CULL, 0x594363804905991EULL
        },
        {
            0x2A77A5E2A99E56D3ULL, 0xD5BD2C6BA7D3A240ULL, 0x80D295435878E985ULL, 0x7D56420C9A5A8161ULL, 
            0x3091F0138464454DULL, 0xEC07570CD6A068C3ULL, 0x6F6408648350D049ULL, 0xBB85D83013CC9321ULL, 
            0xF3A612FDBF8DDC7EULL, 0x6FBDE91D12D04DBFULL, 0xD2B5655637D11A8CULL, 0xE4B37FF3E31C002BULL, 
            0xB427B47E7C60FB88ULL, 0x148466479DA6F087ULL, 0x2DC3EC5E8DB8FFC9ULL, 0x2CB5EDA86D2689BBULL, 
            0x3BDA807A729BDA49ULL, 0x7CA17458C307890AULL, 0x4958CC69988FCEB4ULL, 0x89FF569A066C8606ULL, 
            0xA0C8DEE8F0C76CE5ULL, 0xC192AD2A1C632315ULL, 0xD05731B665EB4644ULL, 0x2701E215B6FF4B34ULL, 
            0x70FE1146F41EB63FULL, 0x7255F07A7DF11880ULL, 0xAE2F9BE3B1B3C19CULL, 0x1D8D7EBCB1E62FFDULL, 
            0x9DF2507BFFBB1306ULL, 0xCB3DA2FD80E0F951ULL, 0x2D56B51188CD373DULL, 0x25D9BB177BB53BE1ULL
        },
        {
            0xE1D939541AA9470CULL, 0x3DB151194744D06DULL, 0x1D6F6C6376717466ULL, 0xC92BBB373BE7E8F7ULL, 
            0x5AB02609014C7AD0ULL, 0x65D6BB606D752B58ULL, 0x52B2258C8FA7CE04ULL, 0xB38A5F665DEB71DFULL, 
            0x2FBBC99DC5014E5FULL, 0x4F2DF9BC631F4C57ULL, 0x240640A981928E8AULL, 0xB06AF1B05325B228ULL, 
            0xE409DB4DD4400CBCULL, 0x99CFDD6DEBBFB353ULL, 0x7AB37DF476E4A83EULL, 0xB2EA6C455CC56DE7ULL, 
            0xADE1ACE2946C9ACFULL, 0xF9124D4A9135A29AULL, 0x3C4D0BB25DAA99B5ULL, 0x46C72E66120D303EULL, 
            0xA2F02C4B1567A17FULL, 0x202DCE54C49BB223ULL, 0xA26E0BD3E658CE45ULL, 0x8E371198937F5618ULL, 
            0x3188318B7FF8A933ULL, 0x4539A7B42B1D67E9ULL, 0x0CBBA31B63D944D2ULL, 0x8B0AA6FB71388F47ULL, 
            0x47A4369D17048F9BULL, 0xB6FCAAD3010A4BC7ULL, 0xCFE0C2A9FE83D0F8ULL, 0x081DD93B1D41EA61ULL
        }
    },
    {
        {
            0xD4D4A7AE2F3CC8E6ULL, 0xB32E6B4DCCE6292DULL, 0xE85E0B68261FC643ULL, 0x8240E32A560C981AULL, 
            0xF0ECC752A21A59C1ULL, 0x4F5B54AAC1D2953FULL, 0x864E00939E5651DDULL, 0xF5CE4D61D2AE95EDULL, 
            0x25BED3605A42A534ULL, 0x2AB06A229555E5CDULL, 0x4686ED3DB2A90D64ULL, 0xED3689476B471D45ULL, 
            0xE71817C64E218601ULL, 0x8BBB1A8EB9BE9C45ULL, 0x32684C670D04315EULL, 0x5C9AF921F259C0DDULL, 
            0xC9FC732AE2971F95ULL, 0xF4851BB47E216091ULL, 0xF13BE2397FEA4F97ULL, 0xFBDB7886ACB5CCE6ULL, 
            0x87E4B7B59E321606ULL, 0x37B5C455F52A7E40ULL, 0x471C52ACFC1C263AULL, 0x099C5F832CB906D8ULL, 
            0x6A9712280363CC31ULL, 0x2BCDD935CADF424AULL, 0x4B0A91617F858B3BULL, 0x0A995E68DA9E3D45ULL, 
            0x132A6A03BCAE3173ULL, 0xB7BFB472B0D308A7ULL, 0x87CE79211C7FC6E8ULL, 0xBEB8000D4849C80AULL
        },
        {
            0x97DB6B187ED4621BULL, 0xF40F5D6B7488E997ULL, 0x4052A8EC60C7D45BULL, 0x8D2E2BA357C51657ULL, 
            0xA0F077971A5BB444ULL, 0x9C5E57A3A6C441BFULL, 0xA3B7B878724DAC6EULL, 0x1F7CB36F3E4C0432ULL, 
            0x1C294E871F5435B8ULL, 0xC352081A5C6B8451ULL, 0x8DD0C22BEEEF41A0ULL, 0xC6C207A3F9DFF14AULL, 
            0xA04D112A78217E23ULL, 0xFA6E53EA95117AECULL, 0x4B09B7C3F46F5612ULL, 0xB9F64457F8543157ULL, 
            0xB66A406A4BAABC2CULL, 0xD95FF7064F592EF0ULL, 0x613F70BAB8F6537EULL, 0x1B70409D0E901858ULL, 
            0x6E7207275C939772ULL, 0xE57FD16D265BB0F4ULL, 0x96178633FB30F966ULL, 0xDD9086E2D1AF30CDULL, 
            0xCB8F7E89FDB609AFULL, 0x9F36F5716BCEB52AULL, 0x4A51903C0D974124ULL, 0xA14677ED62AE47E5ULL, 
            0x5987E3F73D6C41D9ULL, 0x8D8949D25B853961ULL, 0x3CD8D771570A585EULL, 0x32DC32ADF8F9DAFFULL
        },
        {
            0x4012ACB8CA62642CULL, 0xCC2699F45A6FB1C8ULL, 0x9338C0B67A4BC603ULL, 0x2A3173D3D2896396ULL, 
            0xAE8585C2A368E5BAULL, 0xEA54F9A87AB98143ULL, 0x094EB402473A5E89ULL, 0x1E2F28AD87F8638AULL, 
            0xBFE731C5C6A7BCA8ULL, 0x185D0FB14B533237ULL, 0x483554A4066D01BCULL, 0x907227D69547D1C9ULL, 
            0x7393D1FBA81AF1E1ULL, 0xA292A7D65305C985ULL, 0xCAF0DAB0F307375CULL, 0x15D22CDC8A46DBBDULL, 
            0x2D3E7015895A09B2ULL, 0xBF629D4FD46D7F47ULL, 0x455D5DE9744E8F38ULL, 0x2215DBE503618448ULL, 
            0x4D832530B2C6F311ULL, 0x3A86E32F9F365D65ULL, 0x10E3908217EAE9C0ULL, 0x74EFB5F8E34F8A2AULL, 
            0x9DFA0BD54EBC77C4ULL, 0x526B3FBE069FE71FULL, 0xD42CE836AFD7AA7AULL, 0xAF2ED964DD392427ULL, 
            0x683A68DD278B4B7CULL, 0xD173D9E1B5010F6AULL, 0x4E4F11BE28E2D504ULL, 0x7701F16EDC5AC3B1ULL
        },
        {
            0x97DD1EFEE92B40A9ULL, 0xD9A4C27874067D07ULL, 0xD77495701E422EA7ULL, 0x940D35602DC51AC8ULL, 
            0x023BFE641516B805ULL, 0xF02B1C212B50FA3CULL, 0x554EE2CCC5E5BE2AULL, 0xFB9C6761F6EBD1C2ULL, 
            0x471EE8800E84EEAAULL, 0x17B906A81202D999ULL, 0x44A6FA1F69D0E48EULL, 0xD6BF1948B2737603ULL, 
            0x4FE69361FF321FEBULL, 0x03042E358BE8227EULL, 0x5F5E614B18E336B7ULL, 0x2A1CF095160BA536ULL, 
            0xF145327DAFD5A3D8ULL, 0x5E789F660E2F0005ULL, 0xB5DE34227C9BD1C7ULL, 0x58D0A65E893FC32EULL, 
            0x63FADFECA4FB3709ULL, 0xDE3CF7EDB17251F2ULL, 0x6D3C4870D9A1B674ULL, 0xE15DEFD7450E4EB7ULL, 
            0xDE5E2C8322468B00ULL, 0xC35E4C2DDD71106EULL, 0xF027385B312CC105ULL, 0x8869742EC21C234FULL, 
            0xAAE62FCDBC5C246DULL, 0xC153E0F6807EFBE0ULL, 0x5AAF4B48E913DCE9ULL, 0x2AB8BB42CE7DBF45ULL
        },
        {
            0xEE330A2C0585F826ULL, 0x886C0EA2ECEEFCB5ULL, 0x137DB91724347F03ULL, 0x7132B9F75460187DULL, 
            0xFA97A68A9DDF8CA4ULL, 0x4F048D269E7DA0D0ULL, 0x09BE80D758D00ABBULL, 0x44DD2141CDF9FC3BULL, 
            0x4EF96FD564BFF5A6ULL, 0xE21CC5EDD308668EULL, 0x505F353E83997FFCULL, 0xA15CC00CEAA48C30ULL, 
            0x1B0B72C38BF5F0B7ULL, 0xF6FC29CF13AD05B1ULL, 0x47EC27AB640D2C0AULL, 0x4954B163D84AF886ULL, 
            0x3363DDB35E587F35ULL, 0x1F8F35BF53DEBDA1ULL, 0xED7B53D9596F9B8CULL, 0x6E22A1F41E1B7748ULL, 
            0xD09541A2AD7A937CULL, 0x2F67F71C994012FDULL, 0xA4CB5D87AEBC71C4ULL, 0x5185FBFF433114EFULL, 
            0x65143E064EAB9CDCULL, 0xE7A0D25817E8512CULL, 0x753E010D7E8949EEULL, 0x2A6ECCB34FD0D1E3ULL, 
            0xFFB8A24BC6BA71D7ULL, 0xC08980B4DFE82B26ULL, 0x6A5D2E9DE51BFCC6ULL, 0x412010B9DFAFDE78ULL
        },
        {
            0xA0A86F497D12167FULL, 0x8019B1641DC88CCDULL, 0x6889ADC0C71B2543ULL, 0x1C7110620D10F43BULL, 
            0xC3255AE5F8D2DF5FULL, 0x8C53145CB2B8A8C7ULL, 0x7E385DC538EF1B1CULL, 0xE591362B6264CD7EULL, 
            0xCB8806A370DF6F5BULL, 0x8AD4AD1BD9DC5572ULL, 0x0AB4B228F3DC4C74ULL, 0x2268059492FB60DCULL, 
            0xA9446DAC60662248ULL, 0x6A220153BE062F34ULL, 0x04406CEAE9E51412ULL, 0xD8380CA6E48C5546ULL, 
            0x04E05137BA0B0FF6ULL, 0xB4A67E23F27674D7ULL, 0xB82D80561D89E7CCULL, 0x14ED64F93A378A51ULL, 
            0x9608EAFF7AD252BDULL, 0x1C29C465701E1B1DULL, 0xEABAF904E784F01CULL, 0x18168994840C3573ULL, 
            0x0485F0986389D137ULL, 0x72C52F380C233355ULL, 0x2BBCBAC2806CD970ULL, 0x917E07EFBB536913ULL, 
            0xAF5F59E56922C071ULL, 0xE4BDA83E8D295B74ULL, 0xFC4BD6BB015715A1ULL, 0x27F8E70CA33C6567ULL
        }
    },
    {
        {
            0xA4355A5094E7292CULL, 0x42BCBE56793FDF43ULL, 0xED6C8C87AEB8CAB5ULL, 0x1772D069BB0D4C12ULL, 
            0x9416D225C4BF3800ULL, 0x0DDB37F20E5B1EC5ULL, 0xB2E0DE8C0F68E1B9ULL, 0x46A9622CDC5F16C9ULL, 
            0x08B5B87F25917EAEULL, 0x0D70806844990B46ULL, 0xD11A8235BF2C00BBULL, 0x8F28E7CB6FA064F6ULL, 
            0x8289777632453B58ULL, 0x1B16FE326BB51AECULL, 0xF1C8C84AED48B472ULL, 0xDDC19CACE47F340EULL, 
            0x729341BBB14541C8ULL, 0x1B902FE1A8F5D75CULL, 0x69B326BD58C0C3FEULL, 0x294E6EE4E3B21E1AULL, 
            0xC76BB98F0DA9D6FFULL, 0xC465DE90AE832FFEULL, 0x1A97EC9D9EE86747ULL, 0x0D835F133E2F3199ULL, 
            0x4B94FDF323E9C5FBULL, 0x6BF0EEF7C65FCC94ULL, 0x568E9222CDC47AE2ULL, 0xE3A29E2DADA2CD75ULL, 
            0x0EC0140CDD70A07AULL, 0xF44E10AA6DCDFE24ULL, 0x5C82D6A7BF8DB17BULL, 0x7744712D5D39AF5AULL
        },
        {
            0x65C087F39EB0B058ULL, 0x18EB80C44B997CDCULL, 0x1A34572DD3CF4AA2ULL, 0x9046CF0D05C69DACULL, 
            0x0A9ED4031BC9F8B9ULL, 0xE483F3B6414F07DEULL, 0xBE34EB35F9CF6292ULL, 0x942B2F1C3D22BDC4ULL, 
            0x6A944DC5069175D9ULL, 0x7FD1DF002295B571ULL, 0xD0C41F8CF8DDFA45ULL, 0xF8407EE02080268AULL, 
            0x1E01302EF79E817EULL, 0x99ED13269DB953D7ULL, 0xFED5466EC2DCB568ULL, 0x3660670653773AFFULL, 
            0xDEA425F6D939F691ULL, 0x24B0C1FA9CC6EA96ULL, 0x564909D57B8423B9ULL, 0x8B3AB1A1CA10D7CAULL, 
            0xB074617022A98395ULL, 0x0CB3B2E101D0DC06ULL, 0xC3DD7EE8DA918B87ULL, 0x4114FD8758C7779DULL, 
            0x0986A7B2FE63B673ULL, 0xD42A03C4435DE886ULL, 0x2E445FD91E424610ULL, 0x10E6CE44FE4A5692ULL, 
            0x7CC1D3E1D2662813ULL, 0xDD0081F48E86AB6CULL, 0x142F7D149F50D9E8ULL, 0x8AC0EABD2781144AULL
        },
        {
            0x56A9D645841662CFULL, 0xA30F62673144151DULL, 0xA40E037FC47E7100ULL, 0xECF72DF7410B56A7ULL, 
            0x3DDD9BE828862DEDULL, 0x84930D20FA7EAD56ULL, 0xEBF42155F8296D65ULL, 0x01E5BF506FF1F844ULL, 
            0x50673CA68C5B8E94ULL, 0xC760D9A243CBF6A7ULL, 0x02ED2F05C601AEF3ULL, 0x87BE27C30B86A4FEULL, 
            0x2D44EFFA47887D58ULL, 0x51B03F8C5CD3536DULL, 0xE26C9C1BC067A827ULL, 0xC2B4DF16AC23956FULL, 
            0x5E9067AD37CC95AAULL, 0x86A68F7DA478C1D5ULL, 0xA0AEBFC4CA5D9E47ULL, 0x780E71B4617D723AULL, 
            0x2B12595C2B618C04ULL, 0x83C75FA40B39A388ULL, 0x5417992201636647ULL, 0x7FE530594768E52AULL, 
            0x6487E731845C5393ULL, 0x3BEE29CCE1B44BE4ULL, 0xA74548699B7152A9ULL, 0xA2B18BECE8558F51ULL, 
            0x02A8C902DFC8DBEAULL, 0x8EA8C2F8EC3F7A71ULL, 0x4030BACD6A8F749AULL, 0xB53A4E271DB9963AULL
        },
        {
            0x8A42D8CE6F8C6454ULL, 0x74435A7DEEA6B66BULL, 0x08D9299E5F0F8B6DULL, 0x6B96DF7125A02260ULL, 
            0x99CE032EA4A701B9ULL, 0xB1F700D7D1B5A64AULL, 0x97A471E65128DB77ULL, 0x9C1249CB074CC923ULL, 
            0xCF25ABF701088665ULL, 0xCE315CA3B46EEF3AULL, 0xCA65A4C7F8B43D80ULL, 0x5910D52DCA3FB058ULL, 
            0xFD792B1C2563AD85ULL, 0xA713BADCCCCEF6F4ULL, 0xB169F51737E21BC6ULL, 0xA271F419B6CD9A50ULL, 
            0x94D868080B3BCC53ULL, 0x469B58D65D26A0D7ULL, 0xE3AD832C1D350F2AULL, 0x0ED574EEDBF92470ULL, 
            0xC377C5D42FC2A4D3ULL, 0xF90881240275AAAFULL, 0x528D937855590A1BULL, 0xB8B459338306EC60ULL, 
            0x185A575D03BACE0EULL, 0x8687F0CCC923925DULL, 0x68AA697A50760E09ULL, 0xF4CD1F1DCD3A0537ULL, 
            0x7655D4DCAC6F3F10ULL, 0x25898F3331FCE54BULL, 0xB443E1F2C9D3901FULL, 0x2979010588D4F4D4ULL
        },
        {
            0x95B18C992C7D6502ULL, 0xC8D74E52F5311096ULL, 0x8E18BCE3225DE265ULL, 0xEDB57E62727E1317ULL, 
            0x463EDA2EBFA0C4C7ULL, 0x055E5195A5E020BDULL, 0x51F99ADB7622AD61ULL, 0x347BF9E6B473FE65ULL, 
            0x763A42B7E2969B6EULL, 0x7C125CDD0932BD2FULL, 0x009028CAA72C7BA2ULL, 0x4F0334955D91EFECULL, 
            0x66F026817C8AF2FBULL, 0x861273D2D894E89DULL, 0x94EE616C53FDBD56ULL, 0x6C6711045C046CD5ULL, 
            0x03DFE5AD96B4E875ULL, 0x7B7C0FB00D07684EULL, 0x350F923C9CCE672EULL, 0xE8D92E394CD5EA59ULL, 
            0x0AF3942B9BAF12DFULL, 0xBF80967158E50788ULL, 0x061CB8EC2EC60A47ULL, 0x6976D675AB8C4129ULL, 
            0xD86EDA9DFEFF2031ULL, 0xF313DC0D1119C81BULL, 0x9AF3FFB9E4559035ULL, 0x06790DE7D65A1EF9ULL, 
            0x6E6759A098365053ULL, 0x60AC2C8F42147E37ULL, 0x0CC8BEFC5598FD56ULL, 0x59EF265EAFF744E6ULL
        },
        {
            0x779EE5723FEEB2C9ULL, 0xB632D97B31567139ULL, 0x54625094BE41F368ULL, 0xBE1346468CA7FC65ULL, 
            0x58420A28D9B55ABCULL, 0xF0C52E6A44250794ULL, 0x774DD6EDBCC6CD8AULL, 0xFF53F0A0460BF323ULL, 
            0x7095BF1FC10DFCCFULL, 0xA36B475F5BC49D85ULL, 0xE0D374ABE9ABE560ULL, 0x722E1885C0B631ADULL, 
            0x83E2CACC7CC9524CULL, 0xAFF878A1BEEFE135ULL, 0x364F1FB7B4ECE1F4ULL, 0x4C338D0FCC938D1EULL, 
            0x9222F43CB2A6BA96ULL, 0x389323131B7D6076ULL, 0xB1AFA2211DD9C638ULL, 0x29924DFEBF1BAA27ULL, 
            0xADC1088918879D4EULL, 0xBB16EC2955983371ULL, 0x6DCD6947321A8914ULL, 0x332CBFC189C35C37ULL, 
            0x13365B0499C857DFULL, 0x526A0E923CBD91B6ULL, 0x1882A33CF9CC24DFULL, 0xA08102FA4F919833ULL, 
            0x0D78A4EC69046C79ULL, 0x48DF3A77CD50D4FDULL, 0x3A1149710460F531ULL, 0xC32FB5AD852847B3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseFConstants = {
    0x7A01107BDB589380ULL,
    0x885DF1386B14C066ULL,
    0x43BE591DD49058F8ULL,
    0x7A01107BDB589380ULL,
    0x885DF1386B14C066ULL,
    0x43BE591DD49058F8ULL,
    0x843ED3983E7E1829ULL,
    0xFAB63DCD11E08F4AULL,
    0x95,
    0x0D,
    0xAF,
    0xBB,
    0xC1,
    0xEA,
    0xD4,
    0xBC
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseGSalts = {
    {
        {
            0xEB3CDB78413A2E56ULL, 0x3487F97F99D4FDC1ULL, 0xA43B9B68B25D0429ULL, 0x96C7A0A436D8E75AULL, 
            0xCD0C06B5EE45ADE6ULL, 0x22A25C57DDA8FB2AULL, 0xC5CB519E815381B0ULL, 0x5324B8636487EDEEULL, 
            0x831061956413805FULL, 0x8E0ACAF11B30CE2CULL, 0x9ABB7DD1C7F66907ULL, 0x28E9CE7F5E694E4CULL, 
            0x2A3B65BBC0B72A7EULL, 0x47EEB3DA9ADB40DFULL, 0xC05E308987B7158CULL, 0x5A7D172FB0F698D1ULL, 
            0x6F9F45DB21190BD3ULL, 0x4B6EC0B2C314C49BULL, 0x918A6A2F62DFC5C7ULL, 0x8FB22954D2B4A1A3ULL, 
            0x9998120DB43CAF4EULL, 0x87FE1283CAAA958CULL, 0xFA7011FFE77AF67AULL, 0x8587033770397CF5ULL, 
            0xEF08E0930401E525ULL, 0xF69E473931D2AC79ULL, 0x12F8DA43F4E7EF88ULL, 0xF046CA285E73F478ULL, 
            0xC29019DE26E641B1ULL, 0x4789EEB0D7294707ULL, 0xAA748DE4DCAB2053ULL, 0x2C6C76497DE3E3F7ULL
        },
        {
            0x9E83D00034D804AEULL, 0x2F092107D4473296ULL, 0xB76B6BE260864624ULL, 0x0457DEE4602F9132ULL, 
            0xC134F2168CDC38C5ULL, 0xD2D0261FD60D2A51ULL, 0x1AB854F7EE30E8A2ULL, 0x8FE61122DC3C9E9BULL, 
            0x0E9A4EEF0B644680ULL, 0x5E4C751A9C36275BULL, 0x2193950E0740AAF2ULL, 0x8E8FA6B2AA8A2BD7ULL, 
            0xA40E724CD3194E8EULL, 0xCAEDF75FFC8DD266ULL, 0x4ED577604E9C204AULL, 0x52C7EBA4B8C9F935ULL, 
            0x01AB7D00D2610D75ULL, 0x739316E356C23FA7ULL, 0x6B54213E79E47FAAULL, 0xF14CC038884EEBCBULL, 
            0x7D2CF6BB7B2B6A47ULL, 0x2756C51C11E1F5FAULL, 0x1A1894F605188888ULL, 0xA4EDB9AFDC25C5F7ULL, 
            0xA8C1337E338F844CULL, 0xE20ABA0A0AED49F6ULL, 0xEB0FA0D2C701B021ULL, 0x3C0A54E7820D50BAULL, 
            0xC6A8D2B22DB8AD3CULL, 0xFE9A7789A1FAEEF8ULL, 0x3A6C741ACA0348DDULL, 0x9CB717F53C3D72B3ULL
        },
        {
            0x025371121E5D1BD6ULL, 0x5E18B3BEBAB9CB75ULL, 0x58814D127A1980D2ULL, 0xD62103EA80D57FFFULL, 
            0x042FBF9178ADAE5BULL, 0x0EB0078E9927A29BULL, 0x4FCD9D3E4636DC52ULL, 0x62647218A1987CB0ULL, 
            0x2959376A27189C2EULL, 0x55BB1B6BDDB67CE9ULL, 0x9EB05DA8329A027BULL, 0x91E3758236E1E2ADULL, 
            0xA32D25EA440C7A83ULL, 0x80DC701AAC19AB46ULL, 0xFB2623A7603D827DULL, 0xE48EECE581D30B25ULL, 
            0xB50BC4E0BF3F3548ULL, 0x93039FAD95DDBF2EULL, 0x12E156DC504F350AULL, 0x6700CD4E6E5C6778ULL, 
            0xFDBAE57D1F137AD2ULL, 0x74D6FA951ED23E95ULL, 0xBBCF66911F36F796ULL, 0x8E20C2196F632C9DULL, 
            0xD49E71A5E65540FFULL, 0x742594184458F5A8ULL, 0x2A6DAAD5F76C7974ULL, 0xECF72AC02FB6B151ULL, 
            0x9C2B3D7A7DD7761DULL, 0x37990B3C991BECCFULL, 0xA66AB40BD96F4C8FULL, 0x80955B3E6FE2B0B9ULL
        },
        {
            0xE3C0BCF4F464F349ULL, 0xB872670F70462148ULL, 0xF2510417604C8070ULL, 0xB2905813591822DBULL, 
            0xC242DC07B2E3A504ULL, 0x63E95953994C8BFDULL, 0x46B4C68F786E9F68ULL, 0x8939D0CBD36E6B43ULL, 
            0x68F40DFF1E08B2D4ULL, 0x76C8111E91113560ULL, 0x35FFEEEE20DF910DULL, 0x03172C65C2661ADEULL, 
            0xDFAFD89B9352C65EULL, 0x9EE2FC6695A0AD68ULL, 0x6B1E1E65D7D9A19AULL, 0x4EC50212E38D712BULL, 
            0x576DAF632020D01EULL, 0xE4302BDB41A49E89ULL, 0x8096E9FE10CA46B6ULL, 0xB65F3FE802D10F34ULL, 
            0x8E8646B8F7947770ULL, 0xD76F4396AF673620ULL, 0x98D2DAB8E9200CCBULL, 0xBA153F02FB37CFC8ULL, 
            0xDF68B730D609BEB4ULL, 0xB208D219180F1EA4ULL, 0x1735C937EFD21B10ULL, 0x3F1C941892712C0EULL, 
            0xF5873198BD7ABF7FULL, 0x3EC9DC41D957E1D9ULL, 0xE9CF7180E014D78CULL, 0x4003FE2D55F3E575ULL
        },
        {
            0x18666AA93EABFBC8ULL, 0x28EE0ABD6B9CE13FULL, 0x221BA616772AF348ULL, 0x583C9C2BC00ED149ULL, 
            0x62C6C138A0B28226ULL, 0x273DE393B21D81C4ULL, 0x180CE4BDFB21F1AFULL, 0xB0AE13A8A9908A31ULL, 
            0xBCA7FAADF6C9B9FDULL, 0x9A63A0611375E269ULL, 0x433B48363873C5C3ULL, 0x4634BD1453E7F5D7ULL, 
            0xD16EDC48494EE34DULL, 0x65014FDAA6B93BAEULL, 0xFCBF0A658D4FED38ULL, 0x80190AD318AF0EB6ULL, 
            0x8906788617D005CBULL, 0x6EB081F35E36A890ULL, 0xC772036A0DD3B6A1ULL, 0xE93484E99F46EE22ULL, 
            0x7D25A0C1B239BBBBULL, 0x38AA2D48DD911147ULL, 0x9E8D35DC9E87BC0FULL, 0x687DA724CEEBA194ULL, 
            0xF4BCE69FE074E2A8ULL, 0xB92B505571E1284EULL, 0x149ABA27B18657C0ULL, 0x9C4F5F70E6FCE814ULL, 
            0xC8FD5CC66830FB89ULL, 0x022C673CC2EAAAC5ULL, 0xE44E7AD4BC78C7FCULL, 0x3C914DEE03B59803ULL
        },
        {
            0x9E1F1D64A1D1CA07ULL, 0xFEAB7A565B09BD0AULL, 0xA9E634AAF3108C3FULL, 0x4C2A43D5FDC0406EULL, 
            0xE22B7B9B34AC7B0FULL, 0xA1C198EC9D12541CULL, 0x925E9BABFC496D93ULL, 0xFA4988FE0B2B33CCULL, 
            0xE8BBD2FEB4F08F61ULL, 0xE2C2C4A4CE62D82BULL, 0x51D4EBF82F11704FULL, 0x3110890F2DF37D33ULL, 
            0x0D99E6655E115514ULL, 0x4A6F65284B4DC5BCULL, 0x4E8D304E8AA928D5ULL, 0xA190BB4C63F502E6ULL, 
            0x7E678F339350913DULL, 0xDF2217572C783D5AULL, 0xEB0E3A47E7BEE3B0ULL, 0xACC7831E24925ADAULL, 
            0xFFDDF1C21EAD8F4DULL, 0xC6C2005E81014975ULL, 0x992FA283511C02C8ULL, 0xD766927140F12CA9ULL, 
            0x3668DE36B2379758ULL, 0xBCC79CE231D13DB0ULL, 0x48334EF021F30D0FULL, 0x4A275E8134F6870BULL, 
            0xFC8CC0D82FF2A40DULL, 0xB4B41B60C5CE6988ULL, 0x8A8D7B7BE6BA559BULL, 0x0B6D6FDBC268DF4CULL
        }
    },
    {
        {
            0xD717A38F9A93C811ULL, 0xDD9747FAB2D81797ULL, 0x1EB90FCD0AADCF82ULL, 0x7988DC7A557FC98AULL, 
            0xDCD1E7B993613072ULL, 0x7BED5ABD032D6A71ULL, 0x989979334AEE2810ULL, 0x8F89A059DC17D700ULL, 
            0x529FB939084B758FULL, 0x5D4C09CF88F06197ULL, 0x6C79402E49BF4842ULL, 0x35ACB60916C198B5ULL, 
            0x301B71C84BD98C27ULL, 0xDD6B66EB22049648ULL, 0xB29D0408DC0A0C1AULL, 0x0CFFFBA7A735224BULL, 
            0x9D0BA7D7C5DA9A07ULL, 0x5CB43B1EB3B47FF4ULL, 0x2937CB69FCB222A6ULL, 0xED74192D3BFB1367ULL, 
            0x72178D3E09F3FD8CULL, 0x8895DA5F1B36ADB9ULL, 0xE6F6F9013EDB0623ULL, 0xBDFCB813D3B0A655ULL, 
            0x97B5C493665B8323ULL, 0x6B6FA2A3949529B5ULL, 0x7F6F82C0EDB07CA2ULL, 0x31D65DA232DDDCA9ULL, 
            0xB418AD0ADCD346D8ULL, 0x5AB69551B47BBE76ULL, 0xCCCEF271735A0965ULL, 0xAC80C0A8333CD697ULL
        },
        {
            0x712EB692C28AC605ULL, 0xF3DFF0D3FDFAB459ULL, 0xA94526AD65EF20EBULL, 0xA768117736F1D300ULL, 
            0xDA8E766A584B6DC4ULL, 0x4FE663BF1A3DC490ULL, 0x96ACAE86F2CB88DBULL, 0x6A105CBD28B8F2F5ULL, 
            0x8DC1288E00E35129ULL, 0xB8D664E728E6E3D5ULL, 0x0BB6639642BE9B3CULL, 0xCD008D2E18C2A8FAULL, 
            0x91D4D875C7824E23ULL, 0x1E38DBF628C33833ULL, 0x64008D3AB85E6140ULL, 0x8D542FD072B6E824ULL, 
            0x0DDFE750FA7B2C60ULL, 0x23F6A89837247A40ULL, 0xE48CC4A9BBC77581ULL, 0x85949310A0C7C829ULL, 
            0x1B16E5CB5CD9DA63ULL, 0x106362924EB71FDBULL, 0x71961442CBED96E4ULL, 0xE65918D5DBDB0968ULL, 
            0xD0672E593E6B52C9ULL, 0x324BFF7752062C04ULL, 0x0542287552646100ULL, 0xA27DFC569EFE7438ULL, 
            0x50648774F971A8A9ULL, 0xE6872BB3E6EC7E9EULL, 0x1DD40864C7E2190EULL, 0xF076ECF968916574ULL
        },
        {
            0x4609290487C0BBF2ULL, 0x6CC36A341398392BULL, 0x15E2E650C4CD4EEBULL, 0x83F0099638D17736ULL, 
            0xF1298845708A8C5DULL, 0xA6D8C7347990E3FEULL, 0x2A682589E2C9FD71ULL, 0x9B23014ED58DE4C3ULL, 
            0xEA17A269156A17CEULL, 0xF4759DD1C73B0C91ULL, 0xA1FA69C63CCB4B85ULL, 0x3397506E6A0B3D77ULL, 
            0x67A66FA096A8842EULL, 0xAD43C35DD8D772A7ULL, 0xEB6ED58BC75CAFF2ULL, 0x70F237E3B76FC371ULL, 
            0xB4C651AF4E1A6C8DULL, 0x99CDA8798D54550EULL, 0xB100384FF14BD44AULL, 0x1B720B85D61496E6ULL, 
            0x4E7A4FCCDD44D3BEULL, 0xEC12386286895F63ULL, 0xBE4CBAF67918F91BULL, 0x4A495B8833F44560ULL, 
            0x619FE7952DA8650EULL, 0x59617F915CAD90F3ULL, 0xC9BFAB100EDD77D8ULL, 0x1A01A9BE6741390AULL, 
            0x91F30EC03A73C0BEULL, 0xB1161C6802FB8CD3ULL, 0x2FCCD5073D572EDFULL, 0x0B6DD007D83BABC5ULL
        },
        {
            0x1E62BA14036B08B2ULL, 0xC22B6C5AE5319AA6ULL, 0xEAF8C88C66545EF1ULL, 0x686121EF76B7084FULL, 
            0xA465315E8C979CF0ULL, 0xA7CA4DF70820E4F2ULL, 0xF0DD8888C9D70899ULL, 0xEBE0437BA6B4A4ADULL, 
            0x0582EFEB55A06D36ULL, 0x8BB790E2C99439C6ULL, 0x8F946574F5D132ACULL, 0x363960417C85786BULL, 
            0x5A52520227127947ULL, 0x2C8068D08FBAEBFEULL, 0x7C7FA73C4B5DA091ULL, 0xCF7729028BE29880ULL, 
            0xA3E23E13DDD77839ULL, 0xA2DC585A7DA2F614ULL, 0x6AB9B30B15D961DEULL, 0xEE917F0417474DE0ULL, 
            0xDEE529888FE90703ULL, 0x77330947448F3FEDULL, 0x37C2F771FA1A98B3ULL, 0xB6685659D8B88C1EULL, 
            0xA1255BE46F8261FBULL, 0x0BD3F41E9C20622DULL, 0x3B5BD96AF5248A28ULL, 0xD1A5B3FB5D3D1613ULL, 
            0xE554FDCEB27FE274ULL, 0x6F32F3F0CDED9908ULL, 0xF6B75B5F203CB7CCULL, 0x781178334622DFF6ULL
        },
        {
            0x548AF7D88F3E3684ULL, 0x9DAB1C4E64EA07D5ULL, 0xA8A43415BBED14E5ULL, 0xD01AB760D6EB4F74ULL, 
            0x0180CF35B181DCEEULL, 0x557EDFC441E2981CULL, 0xA1C17A7858B90795ULL, 0xDE1A24AC576CCE14ULL, 
            0xCD8063A0ED461069ULL, 0x2E583D7BC4C7CB45ULL, 0x93794334D64B4A3FULL, 0x041133E62BBE018BULL, 
            0x0930251BAEC6B198ULL, 0xE5AC32A89467C594ULL, 0xD0CFE3F6AF11369CULL, 0x63FD54ED215078AEULL, 
            0x3FDBB64279322033ULL, 0x6296763682D7DD67ULL, 0x091ACF026D855827ULL, 0x5B0D0974BDEBC578ULL, 
            0x37FDEDEF4FEB5885ULL, 0xC70FBBFE80D7DD90ULL, 0x305A375019E54515ULL, 0x6E87BBF1022FB0DBULL, 
            0xC005B44A64FB4FB1ULL, 0xD616D06918CC4FF5ULL, 0x399388037EA3B641ULL, 0x3F46BD391B6640F5ULL, 
            0x5A26E8D440704147ULL, 0x30FE6012401AE37FULL, 0xB6D1C7A8C9FCC87FULL, 0xBA3B6C91576ACB53ULL
        },
        {
            0x5366ED4847085564ULL, 0x30D7AC9A926C4250ULL, 0xD6B9FF3F669ED1DAULL, 0x045CDD95FC5751F9ULL, 
            0x8CBFA3DBB6A68AB1ULL, 0xE44336795F85C040ULL, 0xDD643B6CD6CAAEC0ULL, 0x2D742098A66059D0ULL, 
            0x6EDECB6EE44070A5ULL, 0x3D9EB781F0B06817ULL, 0xE2046E7C2664C377ULL, 0xA45DF27656094881ULL, 
            0x2FED2D18264EBC79ULL, 0x7CC976C70C0B8B65ULL, 0x46651305E7F3EA90ULL, 0x7FE3A747144F736BULL, 
            0xAE67AE7F2CC95A9BULL, 0xBEAA19894A5CD166ULL, 0xFA9BAFCE6E0AB485ULL, 0xA01A6E3ABAFFD1F0ULL, 
            0x29CD83107AE06182ULL, 0x79C04AB21C166A52ULL, 0xB556BC651F67C311ULL, 0xEC373A4A25741A2DULL, 
            0x480C12FEB28F0CD4ULL, 0x92A64F60CE2EFBCCULL, 0x0B536BD13BAF62C1ULL, 0x2DFD31FEDB4C56EEULL, 
            0x285EE83E7B958870ULL, 0xB86F65CC11919C03ULL, 0xE2CCE0C234E6F6E1ULL, 0xC3A3132A122BA42EULL
        }
    },
    {
        {
            0x7147679290FE1241ULL, 0x46457C0D6581ECB3ULL, 0x4B14D7167BA9B327ULL, 0x4C526BDC12A215A1ULL, 
            0xD3F6A9727ECD14E2ULL, 0xF0673EB513BECD29ULL, 0x36C2E468A5E6132DULL, 0x042EA1079C3757C9ULL, 
            0x1C12FF7E81840E8FULL, 0xDDE8E9668264692DULL, 0x2732F82B9D0E95B1ULL, 0xF572FE37DE1454CFULL, 
            0x44F2F3577BA78292ULL, 0xB1A19B22339FBC08ULL, 0x363262AF83066979ULL, 0xD60849C4B54B6C61ULL, 
            0x8AE3974E20C57387ULL, 0x8999836A5A5D1EBAULL, 0xFE9503CA073D25ECULL, 0xD7F0AB81D11FF0B4ULL, 
            0x43E99214463A08ECULL, 0x8E3351AA660A87B3ULL, 0x8656BC0865D655E3ULL, 0xA8DC26D84F122FFBULL, 
            0x70871793E95B6A28ULL, 0x63B3D91F689742ACULL, 0x41CF8FB453A7E27BULL, 0xF6B9A3DCA34A8657ULL, 
            0xF1E7ADCF5482CAF0ULL, 0x79AFDEC067E954F2ULL, 0x5461A22489B41C8DULL, 0xAEA6119829C35834ULL
        },
        {
            0x47A98AF78A2D7992ULL, 0x63D3F7D1135C10AEULL, 0x2FDC3A4BD6A19F82ULL, 0xC87709B4D474C414ULL, 
            0x5BB3AC6E55DF244EULL, 0x61A3ACC4886ECB55ULL, 0x7D5E6E0CA828B1C8ULL, 0xFCCE05D2427D4C58ULL, 
            0x2D1272DDA34C54EAULL, 0xE6D59919E32FE31CULL, 0xB6E8C7A2E788128EULL, 0x038D9C93DBB3DAE4ULL, 
            0x000FC21CCA8339EBULL, 0xBC04126838D44F29ULL, 0xC01626058AA11DCCULL, 0xEAAD968069A40180ULL, 
            0x723627BB8CA42E90ULL, 0x2606FCC15F29347AULL, 0x1AF1D614ADB80EC5ULL, 0xD407C6BB06624EC6ULL, 
            0xB5E22A65662D5138ULL, 0xE9556299B4A74DA4ULL, 0x3A46C78090BC4E99ULL, 0x55ABBC602C398FF4ULL, 
            0x42FBAD55AA7283D1ULL, 0xDA33BF7D60395F72ULL, 0x3B3E102D0E6FB2BAULL, 0x669BB8B97871E0A1ULL, 
            0xCDD13183C208FF95ULL, 0x01EB1E20AD57A84CULL, 0xC6FC7E57C783AB9DULL, 0xCEB474D5D1ACA976ULL
        },
        {
            0x72B80568705457BEULL, 0xC78F6EDD50253937ULL, 0x54E67B624425437BULL, 0xE66B7966E349F797ULL, 
            0xE0E1133F9FD26165ULL, 0xA662502F087C8FC4ULL, 0xB268B7E3D28EC365ULL, 0x47DB2E2D5851333EULL, 
            0x769167F1BB973C1DULL, 0xC2F4320392FEC47BULL, 0x7959B57F0F449CBEULL, 0xFAAA4E4A239F27C0ULL, 
            0x97E0DF768B6D0B0BULL, 0x0CD5C21A5696B14AULL, 0x04B0705684C8C6B0ULL, 0xA96D200B6EDC0AACULL, 
            0x2DDA3F1007352499ULL, 0x133FA8CBC0D2F9A6ULL, 0xF8D831B201099748ULL, 0x20E4ACAA0841C838ULL, 
            0x65B39A4DB8F7BBB6ULL, 0x53F249B6EE589B88ULL, 0xE22B0FDD76324793ULL, 0x6DD74DECEA2FC192ULL, 
            0x975804755BB6920EULL, 0xEADAB4C4754551EEULL, 0xCE1789954B8EA454ULL, 0xAC7BE88A816E1960ULL, 
            0xD1B7A787E980B9BFULL, 0x4630F2A1B7B6918DULL, 0x7E06F5E46F68A6D5ULL, 0x53D5FABB3D2CB909ULL
        },
        {
            0xCCF3BB8789A7EE08ULL, 0x7C7460454C357D24ULL, 0x288A068706EBDDADULL, 0x21D80D9C9CBC55B5ULL, 
            0x0FE59544DA11C608ULL, 0xB3CA07244486D25FULL, 0x55128E8BF0BE6082ULL, 0xCBB56B66668BDB83ULL, 
            0xD4E390EBFD606688ULL, 0x42BC82A6050D43BAULL, 0x7EFD2926076EE7C5ULL, 0x7342FC16B4FF401EULL, 
            0xC2890262DEB2648FULL, 0x14D4000A67602EA0ULL, 0xC757BD90E444DFAAULL, 0x0563BC95C4AB8106ULL, 
            0xA67B58104B5EFDAAULL, 0x0E23527F570AA3F9ULL, 0xFD4FDC30BE3AC8CEULL, 0x4403B7C98221E39DULL, 
            0x3BCFB26BADA12D32ULL, 0x8DA57D76B00251E2ULL, 0xFD398D6D7B00D320ULL, 0x2E1F6AAC2B655929ULL, 
            0x3EF6018718226EDBULL, 0x23FC15802AD01ADBULL, 0x136A35FB75D17DF1ULL, 0xA01605088733F485ULL, 
            0xA1B4759AF1469181ULL, 0xAA8F48F4317F6064ULL, 0x13D9D95F89E2CBF3ULL, 0x75E0C1A6E035F90FULL
        },
        {
            0xB98EF59FD9510F92ULL, 0x6DD39F55C03C4D54ULL, 0xB9ADF98B9232F753ULL, 0xDAFB5663D32995FCULL, 
            0x712830998F5D48C6ULL, 0x2910597DC0ED3D54ULL, 0x2A4DF7B4972AF889ULL, 0x94746DAB5C4A5165ULL, 
            0x9A61B259B8ABEBCAULL, 0xCADFEFD85F9A47A6ULL, 0x742B8A145F429C1FULL, 0xA697AA8A7F654B3FULL, 
            0x9EBFBBB01C70C09CULL, 0xD33CDDAE6EE58083ULL, 0x904EE4697383F88BULL, 0xBCC749AC6E30AE26ULL, 
            0xDF40BF25F69F4AE0ULL, 0x4E5F4393CC894ACAULL, 0x81A2757CE493FB46ULL, 0xE5A78148D1073A3DULL, 
            0xE5C78EB1DBE42A9FULL, 0x256572AAC9A4379AULL, 0x5EF0DE9D2C94CB83ULL, 0x12FAFC5380BBB8A6ULL, 
            0xCC2FB4B4EA318880ULL, 0xAC75FC9F535D4413ULL, 0x518930BAB598E12DULL, 0x2963B515A6C4E39DULL, 
            0x8261BFD09CA562FDULL, 0xFF6FE3467DC5F282ULL, 0x7416445AFC95024EULL, 0xEE5C1248AAD5E174ULL
        },
        {
            0x765355FC24FB395BULL, 0xABF0972D2D208141ULL, 0xF6B0DADF044D7017ULL, 0x03C3645FF5938CA1ULL, 
            0xC6D144B7BA44C9A5ULL, 0xB0D577490DEF0DDAULL, 0x63104BCA543F5E1AULL, 0xDA71C6BA63157C23ULL, 
            0xB205F4EDA12AA85CULL, 0xA8318A61DD5A2DD8ULL, 0x90B7A3B252AD358DULL, 0x826DE1B63967B2A6ULL, 
            0xD0A4F6C92EF30C75ULL, 0x922617451B4E400AULL, 0xB435BCBDA1505364ULL, 0x64D62C37D107A035ULL, 
            0x67E069721C9A420DULL, 0x94FB9B6BAD0751F8ULL, 0x846D26A76FEFAADBULL, 0x1B5C15284666A004ULL, 
            0x3ABAD7A22A35411DULL, 0x90C7FD22A319C37AULL, 0xFCA7CE2DE1945AA9ULL, 0x61F80E2B3B8AB7D3ULL, 
            0x436C09EA76C78E0FULL, 0x0ED2B4576ABC224AULL, 0xEB1CF282D918304DULL, 0x68B8919056F49132ULL, 
            0xF8F8674A7454CF23ULL, 0x4E65528BF8727FA1ULL, 0xB28FF37242A81C68ULL, 0x83FE02C7EFE04BB6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseGConstants = {
    0xE730D66A51DA44E2ULL,
    0x6EC2DDAF210F92DBULL,
    0x21162ADB00F5707DULL,
    0xE730D66A51DA44E2ULL,
    0x6EC2DDAF210F92DBULL,
    0x21162ADB00F5707DULL,
    0x362351D60A95A69BULL,
    0x3C712E35E16BE652ULL,
    0xFF,
    0xCD,
    0x91,
    0x5B,
    0x42,
    0x18,
    0x89,
    0x39
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseHSalts = {
    {
        {
            0xCA9445FDC85D0DE8ULL, 0xC52E715600BF1999ULL, 0xBD3D7AB1627E9781ULL, 0x4F5CD93C33A9D1AAULL, 
            0x8020263161150E37ULL, 0xFC0756AE4371756BULL, 0x23766B9372FB7FC9ULL, 0x3D6D92841DA11CA9ULL, 
            0xC09A68E141E73152ULL, 0x46821AF5D122E8A6ULL, 0xC0886D51ED6A43FDULL, 0xBA40F781DAADCB24ULL, 
            0x73F0083FAA9A44F7ULL, 0x8AB212E3F455D416ULL, 0x1466CA3505F55B07ULL, 0x43F8B3820AC1E896ULL, 
            0xC41DF719CA049772ULL, 0x5813BECDA40E15FDULL, 0x3909591CA11B95EFULL, 0xC5F762C02F77F2FBULL, 
            0xA485A3008F181F74ULL, 0xF7CA881BBD0FDA4EULL, 0x7B3A23C5F943931FULL, 0x4BF58DC4E8CE5A05ULL, 
            0x6961D20F32DE7280ULL, 0x5F5D91C65EC2681EULL, 0x0B510EBA51B0566CULL, 0x17404821D4BA513EULL, 
            0x15002B1D400606CCULL, 0x7500DCFAF2012BD1ULL, 0xF7555D68C7024E8DULL, 0xB9334D95669D3B73ULL
        },
        {
            0xC90CB3EEF37C89E8ULL, 0x8A4167AD7C1B49ABULL, 0x140176EE77CCD95CULL, 0x7978505DD0C5B754ULL, 
            0x2982B1E1CD58BE40ULL, 0x9260567138E65406ULL, 0x731E4CB1B88756D0ULL, 0xBAF946860F29F79BULL, 
            0x52FC395C4D0402E4ULL, 0x33132D69DFED08AAULL, 0x29C38C45AC68B56EULL, 0x4D85C6BBEC2CA3B0ULL, 
            0xDF17C1AB6C3A89ACULL, 0x3B6AA933E0F5406AULL, 0xCAC3D26610069B47ULL, 0x5B5D91D60C75826AULL, 
            0x60E29C822046A0FBULL, 0x276B61D1FE123896ULL, 0x7CC0F92662F68FEFULL, 0x27593C99FC685FB0ULL, 
            0xE4701700234B8B63ULL, 0x1D1D9F798674348CULL, 0x4396A7332700108EULL, 0x8E58EEBC24DF9332ULL, 
            0x76CA0B2FDA2C36C3ULL, 0xFE78DACCBF99DC41ULL, 0xD4E18A8F726D2171ULL, 0xFF6F02185B88C56CULL, 
            0xEA4DAFBB182C02BDULL, 0x93BD7512D55E586AULL, 0x422F042883993F2FULL, 0xA685E003A4208741ULL
        },
        {
            0xEE849724FB53F941ULL, 0xE4182DF3D7260704ULL, 0xED99D57B03E163A3ULL, 0x58EAB9291C7D2407ULL, 
            0xC42046F2F2F86831ULL, 0x90B9AB2FA78B78ADULL, 0x32B775ECE9ACFF3DULL, 0xBFA0FA157B11A207ULL, 
            0x340F36773BC462EFULL, 0xB2C4CA02DD96DFE4ULL, 0xB6434B883792A78EULL, 0x3AA8E09C686E0506ULL, 
            0xD87BD714D67D8948ULL, 0xB78255F1F9221EEEULL, 0x861215482AFEC0C0ULL, 0x45EA57AA81FF6D5AULL, 
            0x3A17802ED9F620BBULL, 0x809A5CFAB1C78D16ULL, 0x914EA65880EB8D6DULL, 0x5867351F743CE82CULL, 
            0xA508C1072CC64905ULL, 0xE43A3C57D1058B67ULL, 0x397A5E1C227805B9ULL, 0x97CB1B23E8B499D5ULL, 
            0x49D9B1EB366A891DULL, 0x25CC5020DDB711F5ULL, 0x7D0E14770AB9ABFBULL, 0xFE2C7D699D93B19CULL, 
            0x8E3DF5C25DF46C21ULL, 0xEC2AD0BEDC8259C7ULL, 0xCCDB44C315DE4162ULL, 0xF973319FDF3DA0B3ULL
        },
        {
            0x4CFFD72B453B9BD9ULL, 0xD2A04E9DB4B4C3EEULL, 0x2B58507944696BD6ULL, 0x178CFF9D49AB1CC0ULL, 
            0xA55794AFD8901FE8ULL, 0x6798E26783B4A8BCULL, 0x58C82F361826BD5AULL, 0x17BC771943FCF883ULL, 
            0x7E1270851CFFB6D5ULL, 0xA4788CC28D359009ULL, 0x3B171221EABF2A49ULL, 0x21937EE54404B035ULL, 
            0x504E69CCC04D2718ULL, 0x270433F5767D0982ULL, 0x8023C5C6A543B103ULL, 0xF813376F8186305DULL, 
            0xFF44D3963C24C566ULL, 0x57612A174E2623D8ULL, 0xBEE35BD0AA0DA873ULL, 0x534980713B77BD6CULL, 
            0x3C07086B61BC7EC3ULL, 0xEE3225059C449D43ULL, 0x3B1E0449B3810F29ULL, 0x30D67E276325739AULL, 
            0x50F1E06190819908ULL, 0xF1828AE30A0B60B3ULL, 0xB54B81554FF6CEE6ULL, 0x3C90DA5E6B43F2A5ULL, 
            0x2415BBEE88B938A2ULL, 0x0262FE6281DA7563ULL, 0xE348B4FE33D9EDA5ULL, 0xBAE515F7AF05EE81ULL
        },
        {
            0x82283DD17372281BULL, 0x646983252252C5C8ULL, 0x48C9298EF70E5277ULL, 0x5BF317809274491FULL, 
            0x983F9999C7F8D950ULL, 0x8C8A6BB067ADC330ULL, 0xD3BB3D6588D01710ULL, 0x7164EC374997A3F7ULL, 
            0xC17594FDFF7E44C2ULL, 0xBE94E4B0A77F1A1DULL, 0x78DE867EB29A6064ULL, 0x1ED2D27192CDBA2DULL, 
            0x046A54EDA8AAED26ULL, 0x0989F8E91F8500B5ULL, 0xDEEA5959796BED0AULL, 0xE79282B94A49AA9FULL, 
            0x96ABFAF02F3A65E3ULL, 0x0FD9DEB71E86D831ULL, 0x7C1392887E42BF00ULL, 0xC6378C510D42C2A7ULL, 
            0x2A7E92E2513DEE78ULL, 0xE56E2DC3A2F30719ULL, 0xBB91A08CA1941187ULL, 0x0E6F62C3513E4463ULL, 
            0x374FF0CFAD105A98ULL, 0x1E677CB4A2EB38B6ULL, 0x7E34D7A161180D05ULL, 0x81F53928737171E0ULL, 
            0x8ACE75C2B793CE55ULL, 0xFB52EB73B1752FCCULL, 0x2662DDB356B69DE9ULL, 0x3E9AFD765CEFF9D5ULL
        },
        {
            0xEE5EBB1B03883014ULL, 0x442B7E70F59CFC88ULL, 0xD09E40784B98CA96ULL, 0x63D1F78F441146A6ULL, 
            0xBA2C25C1D827318BULL, 0x69EBBD2BFA1ABCBCULL, 0xBBF287893CA04997ULL, 0x1A174006B507BBB9ULL, 
            0x849E1A26632B79B0ULL, 0xC8168CE2B27CC0DFULL, 0x36E6AF5520935F59ULL, 0x24C1E6C920112B9BULL, 
            0x74391F9201223998ULL, 0x9EC8ECA092D55988ULL, 0x92F3E587BC8A5486ULL, 0x3636369564A0F4A5ULL, 
            0x4B68C3A062C647A5ULL, 0xA77CCFAF6815E5A6ULL, 0xF41E9A6AB85CDD4CULL, 0x7006BD29E5AFC46DULL, 
            0x37FD0F02F98F54CDULL, 0x297AE725A2B94ACFULL, 0x0620CDD9D3A0CD3BULL, 0xD85CFD862FED0678ULL, 
            0x24B0B4C7DDBF95E9ULL, 0x49D8B3D233D1BA26ULL, 0x52BF8494FE4D379DULL, 0x800D8825AB32C479ULL, 
            0x8B16FF6BD608D7C5ULL, 0xFC612693182FA530ULL, 0x543E9E57734FF816ULL, 0x4C5966BB396FC272ULL
        }
    },
    {
        {
            0xA891833CD85D2715ULL, 0xE23978FE3B1BBB12ULL, 0x5AB721AED96291CFULL, 0xE8A3F08AF68DC33AULL, 
            0x6A7D30FC0DFCBB56ULL, 0xE3E4D06F35363F63ULL, 0xFC02719BEBA553BEULL, 0x94C46A8312A33AB2ULL, 
            0xCC6662465F6C68DEULL, 0x2D68812C553C0094ULL, 0x366B63347B9FE9F3ULL, 0x866A9089A05EDCD4ULL, 
            0x79333FC5A4C3CF40ULL, 0x1F1422EA6F5A3598ULL, 0xA3F43EB3CBE3DD49ULL, 0xFEAD75E17FCF525FULL, 
            0xF1B7181585A71FB6ULL, 0x29AB4E2CEFECDD62ULL, 0xC1818395D34FE534ULL, 0x8D4E2F3AB84F45F2ULL, 
            0x4BE81378E0D2EACFULL, 0x253C4267C246DF92ULL, 0x4025DB548E3730A2ULL, 0x007C45637836775CULL, 
            0xD615146667B0B8E5ULL, 0xAF65A0870ADF0CBEULL, 0x755DA25D21160BD1ULL, 0xCB409EF752E46937ULL, 
            0x96EA88A8956B72C5ULL, 0x6831E05193E33342ULL, 0xA163A8A8A4E6308CULL, 0x313222943DB67634ULL
        },
        {
            0x5A8EBBD4BADF9324ULL, 0x7F48A48BC61A64B6ULL, 0x2151FCB23BCC898CULL, 0x5E5361FAE09641FCULL, 
            0xC4DE00A8C065DCDEULL, 0xFC6CDFC95271C912ULL, 0x6013EE6CD0B4DAC1ULL, 0x017E89165347AD92ULL, 
            0x01B34BA1C0A4A214ULL, 0x7C8CF62BED13124CULL, 0xFE78740DC21D5B92ULL, 0x1E2413387ACB6A66ULL, 
            0x467B2BF0758C256CULL, 0xD51DE5E7F784FFDCULL, 0x49B83C0F0ECA2791ULL, 0xA57B9931AFBC0C1AULL, 
            0x4C028B6287C10BD5ULL, 0xEDA7271B74EDCBABULL, 0x1A4579686D252EF7ULL, 0xBE508806D29FC9A1ULL, 
            0xA533B0C599F140C3ULL, 0xA1D159856F7294F3ULL, 0xCCE13168234FABE3ULL, 0x5AC4CE3BD50F4EA8ULL, 
            0xB309C565E554ABFFULL, 0xD5558844A5D3609CULL, 0x319623B4683394B9ULL, 0x7E2F9F86A6D816EAULL, 
            0x99DDFDD71C405A50ULL, 0xD277116A1B4044B5ULL, 0x6E4EEF4508C59F5EULL, 0xE0EE581FF1311E7EULL
        },
        {
            0x6C848EAA60D3A30AULL, 0x0F06F776CC33B6D7ULL, 0x6D5C925F6D4012F8ULL, 0xE834EC77117DA3F2ULL, 
            0x01B1A545E81438ABULL, 0x4EA61CE152A92787ULL, 0x980FBD3D121129F9ULL, 0x22BA30F5D97EC0CAULL, 
            0x2240D7566E3973A7ULL, 0x825A297D487E1171ULL, 0x625A17EA74BDC6E5ULL, 0x283FB2A08F7C9725ULL, 
            0x18ECACF136E09D0EULL, 0x2480FCEB01F9D3C6ULL, 0x9F8043B271A8A3F4ULL, 0x5DA3C1BC5E2E4AA9ULL, 
            0x22BB07D8E829D271ULL, 0xF6E9F4D984B2EF8FULL, 0xCFE32AF26EC8BD1BULL, 0x045A00B29EFF247CULL, 
            0x62F0DB2561679907ULL, 0xDBF340ACFE8964C7ULL, 0xCAE07107F9BABC85ULL, 0x298CB173EEE83F40ULL, 
            0xA8758D15968F080FULL, 0x574225E6CD07F1FEULL, 0xD2D30FA8FB11D5F3ULL, 0x95273FCE7740680CULL, 
            0xE13C3E440A7E5B56ULL, 0x63FC0585916B4CCBULL, 0x67D56F708778D416ULL, 0xD3D2D94D867BBFC1ULL
        },
        {
            0x848F5B2AE17BF57CULL, 0x015B26FEABAE74F7ULL, 0xA38B50EDEF94BEE6ULL, 0xAAB1B2EAC5FF6CB8ULL, 
            0x4B16C7523F2C583EULL, 0x6CE5464C395F5485ULL, 0xADEF60C884E20256ULL, 0xF1ECFA400BC3DFEBULL, 
            0x40DB981162CF08EBULL, 0x690B6A70D8B57549ULL, 0xB38D303562AA30E7ULL, 0xB8131D8E29A9D8FEULL, 
            0x5F9BFFBBAC6C6CE7ULL, 0x574F8A559D225F6AULL, 0x92334D54CBBCCECCULL, 0x9F0AC3A0A43BB443ULL, 
            0x9ED36D057A908E5EULL, 0x725926004BF773EAULL, 0x6D92580490B2010DULL, 0xAF1FAF286B04BF99ULL, 
            0x45F36E736156AEB8ULL, 0x966094A71344A673ULL, 0x6391A162CBB61597ULL, 0xE7BD29710BE3B130ULL, 
            0xEB2642DBD7360B0CULL, 0xAEE1FA0E321C608DULL, 0x70EF57C0C6C18465ULL, 0xFF8E80BEA1FEDAB1ULL, 
            0x345A5CDE7537F57FULL, 0xAAE8522C71631059ULL, 0xB335742D7D6B4BACULL, 0xBE7982E7A1A50639ULL
        },
        {
            0xCA6F9B704299496FULL, 0xA5F380E4A2799941ULL, 0xA6FCD8C8F3D7B5EEULL, 0x73D3B545E491994AULL, 
            0x8A71FC6BF66F3218ULL, 0x5217F5021C0E7A07ULL, 0x4324C7E9A8BBD014ULL, 0x0DA3410AC67FED37ULL, 
            0x7E087E6A03E819EAULL, 0xF591EF4306245347ULL, 0x9A369CEA968C810EULL, 0x2BB8F7A23156ABC2ULL, 
            0x50D95702A6586A55ULL, 0x1BA4D44585044471ULL, 0x65AAED3B7312311DULL, 0x0012513243BBD91AULL, 
            0x1F22E25EEF664F8AULL, 0xA533402167216968ULL, 0x088F6AE9E694FD4EULL, 0x9AA79B6045CE64ABULL, 
            0xEE00DD96B1726968ULL, 0xFAA3B5A20D7F34C1ULL, 0x2A9B2DB8835B6D97ULL, 0xBFC5E4BCA8ED3AD5ULL, 
            0xEAF6460E632DE3A3ULL, 0x03BA75B551582877ULL, 0xE168F9024C0F68C1ULL, 0xFCF2FE0F3980F437ULL, 
            0x4D061AFC266F1884ULL, 0x7CF0E905F486666FULL, 0x3939EDBA70727F2EULL, 0xCEB30DC8C764F6C7ULL
        },
        {
            0x27825CDDD93A351AULL, 0xCECAE20FBFF8AE77ULL, 0x038831E7CAC8344FULL, 0xECBAC8EEBFB1DE1DULL, 
            0x9BF833FFEBC21564ULL, 0xBBE6F5B235EA74E2ULL, 0x21718941CAD9400DULL, 0x32D932A150A1A7E7ULL, 
            0x9E6079273F99D56CULL, 0x638B6BFD14DEFA1BULL, 0x4F846E20A1EF10D2ULL, 0x783C2966DA289F77ULL, 
            0xE24599907C8342DCULL, 0x5BEB3FCBF78A344AULL, 0x060BF2A47409A072ULL, 0x25393863C740A5C2ULL, 
            0x69F6A724AF03E6ECULL, 0xEEAA46B7CB6929C0ULL, 0x57C3771BC2C759F8ULL, 0x544E7A8467973963ULL, 
            0x3FE7011648F9AD7DULL, 0x8A31334731EE5295ULL, 0x6D771D2E7949CE19ULL, 0x1401EFFD9B1B0EE8ULL, 
            0x66771BFD81DD4257ULL, 0x66E40D6C40280948ULL, 0xE9B7E3E944725834ULL, 0xF964C68926995433ULL, 
            0x952BD8D31A68B34DULL, 0xAA60A5552CD3A84CULL, 0xAE2D30E4CEE2627AULL, 0xD8628390CD2D399BULL
        }
    },
    {
        {
            0xEC72CD21C18CEAC9ULL, 0xA59B827199C6CABAULL, 0x6AE707A9BBCC8A23ULL, 0xC563819C0E7C9BB6ULL, 
            0xA2E4ADE79DC7FCE6ULL, 0xE332D5B5AE6FD21BULL, 0x80F863358C60C442ULL, 0x825D5AB0A6A44BF9ULL, 
            0x6DD09AEC5472BC99ULL, 0x0A4795DC56DF926CULL, 0x3638AF358309CAFDULL, 0x4B935213D851E045ULL, 
            0xEDDCE4E15C427BFDULL, 0xBE11F8A7267349B4ULL, 0x546FB51B7C429C2CULL, 0xBD62ECBCC5F14D0EULL, 
            0xC0140DA114F8717EULL, 0xC5EF950C0B2F9DACULL, 0x74B1EC41057068D7ULL, 0xFC0EE9E68F7DAC28ULL, 
            0x4ADBC1E2F39CC572ULL, 0x9AB938EBEDCB5141ULL, 0x5BC204D0E0F01521ULL, 0x8DD07CE431EB44ECULL, 
            0xE65734E85B02FB6AULL, 0xF77B18D9F09FF9ACULL, 0xD9C279B04085C733ULL, 0x45F5181AC36E3473ULL, 
            0x23F33246317A1CFCULL, 0xB75B11C5782C2983ULL, 0x00B249C996E5F962ULL, 0xF7CABB24ED22FC2EULL
        },
        {
            0xAD6DC7790E49C896ULL, 0x22CF415A10F3A8E1ULL, 0x5EFBC9F5607D4D25ULL, 0x1BA4C1640D20A559ULL, 
            0x460F7831A8BE8490ULL, 0xEC3AA900A6EE604BULL, 0xF23DD03E7DC699B5ULL, 0x27B7F4D61AD53253ULL, 
            0x9B7B970C02244172ULL, 0x81DB394557415FF5ULL, 0x954B48A293122FCFULL, 0x729CB6AA80D8DAA4ULL, 
            0x29C696FB1F2C708BULL, 0xDC2EA149BE8DA064ULL, 0x29EBB5AB7B129F08ULL, 0x72716DAD427CFA3CULL, 
            0xF26648ED90A21B30ULL, 0xFBAD602EEF1103F5ULL, 0x17BD6D9902FC17FCULL, 0xA8E6CCD4A3737D96ULL, 
            0x36447EB90F39E563ULL, 0x9D54F81A93D42BF4ULL, 0x4A1231245F1437D1ULL, 0x474EEBF732FCE5F1ULL, 
            0x0FB4F61D3EF16816ULL, 0xB173A7C800E0A98DULL, 0x8AF745828D6BE680ULL, 0xE5B8A639EFA303FAULL, 
            0x37AB96737D47DA8EULL, 0x94A6374939CB4D26ULL, 0x319A583210376A1CULL, 0x62C04D9CC660B276ULL
        },
        {
            0x8CDE8514CA6E57CAULL, 0x666C00DD08AA19AFULL, 0x32A9E40DF2774B42ULL, 0x51A2284F67610D8AULL, 
            0x23A3A7A97524E036ULL, 0x192AE239597B6E21ULL, 0x7436AF6899AE69A8ULL, 0x5533F63852786B63ULL, 
            0x4325794F7ABAE061ULL, 0x8EFBAF297C876D82ULL, 0xC6528DC630717826ULL, 0x6090F8232CEDC164ULL, 
            0x507314F2EABCA506ULL, 0xE425AC3B077CC563ULL, 0xC5BA783CF5CCA0EEULL, 0x96F06855FE7A2FD6ULL, 
            0x543F8E5E7E4E6CA6ULL, 0x3D5270EF8CA410D4ULL, 0xDE83206CCDCBA3EBULL, 0xE2FCA8AFD3CD0EABULL, 
            0x8A6943C3321F0630ULL, 0xE20B41CFF0B9F3ABULL, 0xE030E5809470D53CULL, 0x216B52F7EAB927C7ULL, 
            0x7F0059839343E88CULL, 0x6CC24F0F275E8CDFULL, 0x5350479131AC00F1ULL, 0x5DF26DD523826FA9ULL, 
            0x743AB7DD53EBFCDFULL, 0x0B7A47B952F9DF6EULL, 0xFEA203430A0ED717ULL, 0x547F71C4E1DC33FCULL
        },
        {
            0x5E49ED258FA52C54ULL, 0x3D8E3318A8D190EBULL, 0xAE6FDB510BC7BABDULL, 0x8D422D369677A2B5ULL, 
            0xA21DE6534462531AULL, 0xCBA2CC86AEE020FCULL, 0x4CE7862D791DDCCEULL, 0xF43F1D2159DC9692ULL, 
            0xE5D2899C7B5DDD31ULL, 0xB9BFAD747CE48B23ULL, 0x1442B0B1167B33DDULL, 0x1F183F36A8A92D1EULL, 
            0x85C939F190250B6AULL, 0x5708810CEDECD9F5ULL, 0xC5178BCCFADE57DBULL, 0x290A72F24C94A71FULL, 
            0x39C4EB103203CC3CULL, 0x047705C3164EE74FULL, 0xED408B1D4B096CB2ULL, 0x22611543E55AE96EULL, 
            0x91F1DE50ABD622DAULL, 0x774F795941797457ULL, 0x6F494F4EB95622B4ULL, 0x6AACB2E209F83EE3ULL, 
            0x6FBAA4A0F9BF4F33ULL, 0x33CEC88DB1430724ULL, 0xE44037523D0CE47BULL, 0x0BEA4A005E226710ULL, 
            0x892F44D687ED760BULL, 0xC84CC2FB0CB87B2EULL, 0x2AFF99171614A8BBULL, 0x147A492874B17F4FULL
        },
        {
            0xD8C5537968D8BCA4ULL, 0xA78A451A297B1BA2ULL, 0xCA9ABECFA3439798ULL, 0x9F0D206496CC091CULL, 
            0x7519F5DEE007514BULL, 0xEEA3A159F41089E5ULL, 0xCA755318AF83869EULL, 0x1A368ACC9957F0ABULL, 
            0x6F3256163E8B987EULL, 0xA3DF42F7E8BF7B1CULL, 0xBEBA4794D3D5EF30ULL, 0x996B288A4BE5150BULL, 
            0x699A2E6C65E866BEULL, 0x5715144D83C8ACE9ULL, 0x7DB3345CC01AF484ULL, 0x8C449D1A84F13A16ULL, 
            0xF749CFE212537F07ULL, 0x5BACAEEDFE8525AAULL, 0xB2BF1A4F5D22AE33ULL, 0xD647288AF7E3BA3AULL, 
            0x3FEB21D10DDA9D55ULL, 0x385B30E8ADAF66E0ULL, 0x4547E512B0DB5B44ULL, 0x6C32C4374F91A7A7ULL, 
            0x75298F4636DC59EDULL, 0x4E4693F9EA2AFFE9ULL, 0xE70A5DBFD049A210ULL, 0xDEDDE5F11FD50B75ULL, 
            0xF975F97546F99D5EULL, 0x903C93314D4FDF9BULL, 0xD2AA4ED31398157AULL, 0x9ACD1637FC68727EULL
        },
        {
            0x5203FEF4E4A00D9BULL, 0xCB6E159CB0F5BFBBULL, 0x0242470A54208C9FULL, 0xD238B0E86A03A895ULL, 
            0x9C2CDABCED000636ULL, 0x118888AD44BBE30EULL, 0xD32B323633981B86ULL, 0x1F036F91DACC95A4ULL, 
            0x75BE396B95F48F34ULL, 0x9E60502C13398C1CULL, 0x6235431A186B79B4ULL, 0xF698D13317014811ULL, 
            0x9EB3D0186FE53ACAULL, 0x17E24C4BD631281EULL, 0x06E3209D74FFEF53ULL, 0xAB8AF16CADEBEEBEULL, 
            0x58E1D0D0DCF7053BULL, 0x8E8DE74D5A1058D4ULL, 0xD6A04AA5B9E2EE72ULL, 0xFF27C98974227922ULL, 
            0x56D47BBC617C6A5BULL, 0x5EF1EE2B91A458EFULL, 0x1911B0BAACCB7791ULL, 0xD00A925F3EE04111ULL, 
            0xD387C2E1FFEC5B0DULL, 0x8FF2E80C91C0918BULL, 0x38AC24D5A963D1D5ULL, 0xD474E3B059F4EE63ULL, 
            0xD32886F33543576CULL, 0x7482DA62302DC1D6ULL, 0x44F6F8D48A8BF94FULL, 0x5EA805B7BA38DB27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseHConstants = {
    0x32E464091589AF6DULL,
    0xAB2A938AA9F2DA66ULL,
    0x8EB83C8535E85A2EULL,
    0x32E464091589AF6DULL,
    0xAB2A938AA9F2DA66ULL,
    0x8EB83C8535E85A2EULL,
    0x6F70026F8F37937FULL,
    0x5CF703B5F252E33BULL,
    0x9C,
    0xA6,
    0xA3,
    0x23,
    0x55,
    0xF4,
    0xE2,
    0xFC
};

