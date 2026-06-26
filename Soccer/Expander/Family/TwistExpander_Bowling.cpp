#include "TwistExpander_Bowling.hpp"
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

TwistExpander_Bowling::TwistExpander_Bowling()
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

void TwistExpander_Bowling::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 11268334724708115906U;
        aCarry = 13365301680731154926U;
        aWandererA = 12367688796378948438U;
        aWandererB = 15897479992400138036U;
        aWandererC = 14209956508456925569U;
        aWandererD = 10192761717011780538U;
        aWandererE = 13430413223788137625U;
        aWandererF = 17134164194802898255U;
        aWandererG = 16988990594673153357U;
        aWandererH = 17629618656682757850U;
        aWandererI = 11720756384306952891U;
        aWandererJ = 16252584887503344083U;
        aWandererK = 12843392583295171827U;
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
    TwistExpander_Bowling_Arx aArx;
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
    TwistExpander_Bowling_Arx aKDF_A_BArx;
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
    TwistExpander_Bowling_Arx aKDF_A_CArx;
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
    TwistExpander_Bowling_Arx aKDF_A_DArx;
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

void TwistExpander_Bowling::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 9724939465803991653U;
        aCarry = 14497451022345403441U;
        aWandererA = 11035849464625978347U;
        aWandererB = 15066407424916798779U;
        aWandererC = 14402486172420299610U;
        aWandererD = 14944256426915101417U;
        aWandererE = 14483869339850960088U;
        aWandererF = 16369638426037172671U;
        aWandererG = 17369294207478728307U;
        aWandererH = 15386460377507778214U;
        aWandererI = 16032872254361711325U;
        aWandererJ = 17743972615871168907U;
        aWandererK = 10141671504991176677U;
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
    TwistExpander_Bowling_Arx aKDF_B_AArx;
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
    TwistExpander_Bowling_Arx aKDF_B_BArx;
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
    TwistExpander_Bowling_Arx aKDF_B_CArx;
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

void TwistExpander_Bowling::Seed(TwistWorkSpace *pWorkSpace,
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
        // Making snow counter: aria 256
    
        TwistSnow::Aria256Counter(pSourceInput, aSnowLaneB);
    }
    {
        // Making snow counter: sha 256
    
        TwistSnow::Sha256Counter(pSourceInput, aSnowLaneC);
    }
    {
        // Making snow counter: aes 256
    
        TwistSnow::AES256Counter(pSourceInput, aSnowLaneD);
    }
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneE (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneE);
    }
    // KDF_B PhaseA invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneH (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseB invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneD (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneD);
    }
    // KDF_B PhaseC invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    }
    // KDF_B PhaseD invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneC (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneC);
    }
    // KDF_B PhaseE invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneB (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneB);
    }
    // KDF_B PhaseF invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    }
    // KDF_B PhaseG invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneA (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    }
    // KDF_B PhaseH invest aInvestLaneA (end)
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
    TwistExpander_Bowling_Arx aSeed_AArx;
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
    TwistExpander_Bowling_Arx aSeed_BArx;
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
    TwistExpander_Bowling_Arx aSeed_CArx;
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
    TwistExpander_Bowling_Arx aSeed_DArx;
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
    TwistExpander_Bowling_Arx aSeed_EArx;
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
    TwistExpander_Bowling_Arx aSeed_FArx;
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
    TwistExpander_Bowling_Arx aSeed_GArx;
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
    TwistExpander_Bowling_Arx aGrow_AArx;
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
    TwistExpander_Bowling_Arx aGrow_BArx;
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

void TwistExpander_Bowling::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Bowling::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bowling_Arx aTwist_AArx;
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
    TwistExpander_Bowling_Arx aTwist_BArx;
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
    TwistExpander_Bowling_Arx aTwist_CArx;
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
    TwistExpander_Bowling_Arx aTwist_DArx;
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
        TwistExpander_Bowling_Arx aGrow_AArx;
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
        TwistExpander_Bowling_Arx aGrow_BArx;
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

void TwistExpander_Bowling::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 2 with offsets 5U, 5364U, 1050U, 7548U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5364U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1050U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7548U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 1 with offsets 7198U, 2071U, 1996U, 7077U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7198U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2071U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1996U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7077U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 0, 0 with offsets 1011U, 8031U, 670U, 6246U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1011U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8031U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 670U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6246U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 3 with offsets 468U, 2846U, 3245U, 5820U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 468U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2846U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3245U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5820U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 with offsets 1806U, 738U, 1828U, 941U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1806U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 738U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1828U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 941U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 3, 2 with offsets 156U, 650U, 1558U, 230U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 156U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 650U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1558U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 230U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 2, 0, 1 with offsets 1224U, 1897U, 601U, 871U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1224U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1897U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 0, 1, 3 with offsets 716U, 175U, 1628U, 736U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 716U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 175U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1628U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 744U, 1964U, 1762U, 1345U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 744U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1964U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1762U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1345U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Bowling::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 3, 2 with offsets 6271U, 5697U, 3099U, 5546U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6271U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5697U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3099U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5546U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 2, 3 with offsets 6127U, 4049U, 1758U, 1868U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6127U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4049U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1868U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 1 with offsets 1530U, 6180U, 6095U, 7578U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1530U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6180U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6095U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7578U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 0 with offsets 551U, 1502U, 2698U, 7026U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 551U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1502U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2698U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7026U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5030U, 7639U, 1543U, 2310U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5030U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 7639U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 1543U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 2310U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 3, 0, 1 with offsets 1463U, 117U, 1787U, 922U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1463U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 117U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1787U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 922U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 1, 0, 3 with offsets 1702U, 817U, 1704U, 205U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1702U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1704U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 2, 1, 0, 3 with offsets 779U, 890U, 1986U, 861U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 779U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 890U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1986U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 861U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 3, 2, 0, 1 with offsets 1541U, 1097U, 923U, 102U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1541U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1097U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 923U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 102U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 48U, 1223U, 239U, 333U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 48U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1223U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 239U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 333U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseASalts = {
    {
        {
            0xEC3B7CA19F2D573AULL, 0xD3AACC1A5FEF9DD2ULL, 0x2EB112DD3532BABAULL, 0x1AB34FBDF2071AB5ULL, 
            0xD2CA4B7D58B51D74ULL, 0xD05F642F13595F88ULL, 0x676CFC31637A10C6ULL, 0xDE26609FB618242CULL, 
            0xE405B016E98603B6ULL, 0x30AA6172AA094D2CULL, 0xBC6075C789EE873BULL, 0x4FB569D4B4A72E7CULL, 
            0xF74A841706EEE8CDULL, 0x9F6FE6781FDEB635ULL, 0x4E56905914E2709EULL, 0x56145FCF2B6EE516ULL, 
            0xE460AD81635C066CULL, 0x86615D98B5E9B32BULL, 0x5BD5123003EBB866ULL, 0x93A0BD3CF989BA6FULL, 
            0x33494C3697D9FFD4ULL, 0x78BA60C8602D5425ULL, 0x7084A8C245217DE4ULL, 0xD5519DF67EC9E5C8ULL, 
            0x6D9EEBE1C4F76C01ULL, 0x5C38A536A6C4CDC0ULL, 0x9AC12D40018F015FULL, 0x1CF27A072B79ECAFULL, 
            0xA82E7FCAA2BD8C62ULL, 0x91D5CDEB5099A3E4ULL, 0x3EC8962128DFAB4AULL, 0xD60D6067B1075B98ULL
        },
        {
            0xE12AF6FFF9EB0BE2ULL, 0xC5B0B3C914D1E762ULL, 0xA72E3C4535FE3114ULL, 0x1DCBE1E2B7D4F947ULL, 
            0xAED1E1BDCB24E4EDULL, 0x2D58C4E8E7C20861ULL, 0x705A0769FD1E31A6ULL, 0x290B1F48A15139F8ULL, 
            0x2236EEA84A1C60E8ULL, 0xCF5094745A3A4133ULL, 0xF4C6493C72ED5596ULL, 0xE1E4598DE70D595BULL, 
            0x5A67904FFC96D4EDULL, 0x1B10C31015B9AE5AULL, 0x3AD323BC3FCB0DF0ULL, 0x71FDE70DFE7D94AEULL, 
            0x68D57B767D5CA397ULL, 0xC34546A157F7C603ULL, 0x7758CEEBC9422577ULL, 0xC54C0DE0F1A97C2BULL, 
            0xA41C641EC38CF3D7ULL, 0x163E637AA12BF755ULL, 0x6E2A34DD9937E265ULL, 0x2E181D195C26DF63ULL, 
            0x194EC699C6C3D1B9ULL, 0x393A4F1E3DCA8781ULL, 0x3E48B75A288A3EE8ULL, 0xE689E2BC81AD0951ULL, 
            0xD872B1AFAF3E5711ULL, 0xE958CC0A2E6CA33BULL, 0x4B491106B4185049ULL, 0x34AB9D0FD07CFF11ULL
        },
        {
            0xC9A7135D06441681ULL, 0x99121586D732722AULL, 0x7C05CA58753F0B8FULL, 0x8D9A874C9BA330CFULL, 
            0x2106EFEC728E19DEULL, 0x11B0033CB13C6DE0ULL, 0xE773169F0682D914ULL, 0x91AF6858920DD754ULL, 
            0xD96AF67717639293ULL, 0xB386447A939186BFULL, 0xCAB48C424F4E5AC1ULL, 0x1F8CB1E526DBD5F1ULL, 
            0x140ADF9186F5F61FULL, 0x668E7C395E9583EFULL, 0x9E3EEE1CB665E0A8ULL, 0x1DB5344F59E88BCFULL, 
            0x7F7370BC8FC55556ULL, 0x606C63E7B729471FULL, 0x91CCA0D4C6256AA1ULL, 0x05F1EA7DD81CEEBFULL, 
            0x08655B7F1E5D0E57ULL, 0xE51DAAA1B6A28385ULL, 0x40DE6252CCBA1A4DULL, 0x5356CA0FB2E0B994ULL, 
            0x0D6C634CBBA71812ULL, 0x30480E49ADC86811ULL, 0x1E66DE7A685F9DF0ULL, 0xEDE28FDC705806D5ULL, 
            0x5AEE68B0FC3F954FULL, 0x3082BB90642437E6ULL, 0xFAE833C8A7D8E446ULL, 0xB43AA0C8DAB735AEULL
        },
        {
            0xC8005B18F065DC4FULL, 0x748461568AF81054ULL, 0x7D7DCD510EBE76F6ULL, 0xE88F447C75CE1048ULL, 
            0x37AD0C8A76693A60ULL, 0xBA6D0F594EB874E0ULL, 0xF45FFF202547CB3EULL, 0xEF7B5984B55B24FDULL, 
            0x9031278E2DCE04DCULL, 0xC5BEE2975D73CB1FULL, 0x02F1BDDED45F75CEULL, 0x66A41C79A1377240ULL, 
            0xA7255D0EAB0B8C9DULL, 0xA4CE910FDD4DA829ULL, 0x298E18E0FA96877EULL, 0x68ACCE8E9B458096ULL, 
            0x79B11DC03730EBF4ULL, 0x3985F9DDDA2673B9ULL, 0xAFDEDEB6160440B6ULL, 0xCE459F46F7BD93A1ULL, 
            0xF97DB6A45AB7B001ULL, 0xA365E0B94B606A87ULL, 0xB9FDE1AB5EC2BBBDULL, 0xDF193FC1735F84E1ULL, 
            0xFB659936EED90346ULL, 0xA085D1D7DA38AC5AULL, 0x3CD6B37B47ED7CBCULL, 0xFDB997D17A513A6EULL, 
            0x84F01C437CE1A4ACULL, 0x53FF8DA520E3D2C4ULL, 0xC2BD47F8D8F5FFFAULL, 0x4C798C5B3D87B2D6ULL
        },
        {
            0xC90D3167CFA10716ULL, 0xD5067E04A9F9057FULL, 0xD348E893CFD18F7DULL, 0x1FDBC2981266F5E0ULL, 
            0xCB00E678EEC9B208ULL, 0xDF15943D0DA2BF91ULL, 0x0FBF5D83D45640FCULL, 0x87045C5D255BFB77ULL, 
            0xC2B2533AEB973A43ULL, 0xBCA4946ECD30085FULL, 0xF7D5E9AF5C017625ULL, 0x191920433D48C0F8ULL, 
            0x0E1E302CEF39A056ULL, 0x56540BC56E56D71EULL, 0x06D02B61ED5AC6F3ULL, 0x98380F5F3588F513ULL, 
            0xF47B2299C0D5A70CULL, 0x298B188AFC22F7A7ULL, 0x9A9DEDBE666432D4ULL, 0x1C435AFAEC903276ULL, 
            0x9375DAB8CAAF677BULL, 0x4DA45C11066E332EULL, 0x468CA51382F5FC66ULL, 0x49CE1DD8A7BE4AEFULL, 
            0xCAC002BB0CEC44DDULL, 0x8663F041ACDC6E4EULL, 0x28623383F77F2AE4ULL, 0x0C3216B8FCCD1672ULL, 
            0x59CD7691EFCEC850ULL, 0x06B837D17ED80063ULL, 0x82BB2EAF354D3F41ULL, 0x0C8869698BDC6959ULL
        },
        {
            0x782E741955B00317ULL, 0x59F05DD52FB2940BULL, 0x511E1E178CB36C08ULL, 0x3375E19B66B927F1ULL, 
            0x5EBA50D20ABBD478ULL, 0xB757BC5B8BBEF037ULL, 0x4FC698154370A051ULL, 0x42886A4FE810D045ULL, 
            0x4FBB5A3A19B4DFEEULL, 0x069ABA4567AC1EE7ULL, 0x5EC9DD6E80D5477CULL, 0x0C44BE7D526D870CULL, 
            0xFAD495DDB730624BULL, 0xB5D5A15AEDD0E8AAULL, 0xA8CBDBE82AA6A63DULL, 0x24751CAA1A18DFE3ULL, 
            0xD6491625B2BA7741ULL, 0xB666A3FFA5605FC5ULL, 0x491DFA5A6206F1B4ULL, 0x6DD9FBFB4A7E4ACCULL, 
            0xFBAC4A3D02C71F85ULL, 0xEBD7CF1877C87514ULL, 0x13E536517E3DF5F4ULL, 0xA4B27FB268BFC155ULL, 
            0x2B3D5960B79FE203ULL, 0x948F7B429639385DULL, 0xF481131968DEDFCAULL, 0xF76B2C3EFFA4826CULL, 
            0xAB33531ABA82DFE7ULL, 0xF745270E7CB20E09ULL, 0x6658D9F5CF983FBCULL, 0x334BE9D4B19FEE88ULL
        }
    },
    {
        {
            0x80DFDB5E0405760AULL, 0x9A3FBD68BA4C7859ULL, 0xAF9D56E0FDE82499ULL, 0x47118923E3D3AA5BULL, 
            0x4FE204FE8C1FE2DCULL, 0x72D98C6457C53A02ULL, 0x822C546648B886D5ULL, 0xB5EB6D8C52BC11C3ULL, 
            0xF9028591D43DA14AULL, 0x88690C2A78EFFE10ULL, 0xD96B211348AA946EULL, 0x84DB330ADC18E0C7ULL, 
            0xEAD1D2166BF8E47BULL, 0x13B1265A2A8D74BCULL, 0xC084FE3DB74956E7ULL, 0x7BC2E1FC238C38DCULL, 
            0xE1918F825EC575E3ULL, 0x91DB0E3DE39AA421ULL, 0x811CC040D658C3E5ULL, 0x7C9682CD6182B204ULL, 
            0x024A7A315D2AB53BULL, 0x5F08C19585C8A6D9ULL, 0xE3442664771BE5F1ULL, 0x0D8C2ACAA5E70005ULL, 
            0x7ABB7A1F52F467C4ULL, 0xDC684501CEA5720EULL, 0xF827F7A6E1C77070ULL, 0xD3304490FF75812BULL, 
            0x566EE8A81718FB53ULL, 0xD3317DFAD0B39579ULL, 0x2822C0D5C67BEF57ULL, 0xBD1BF571C679264CULL
        },
        {
            0x8267A3284FBDC2E5ULL, 0x5BB58C5B5CA99948ULL, 0x22F7634F10DE08F2ULL, 0x06229F42F75E841BULL, 
            0x74DD456E7073BA86ULL, 0x7465F06321ACFD24ULL, 0xC2D31C0ECD02DBA0ULL, 0x764AC486CF2DE458ULL, 
            0xD6CF0ABBBC665C1FULL, 0xA65BC448E2BD49C0ULL, 0x8DC6DC2C0294A907ULL, 0x6A0496B9598AD2C7ULL, 
            0xE788F11D5AC658CDULL, 0x4D7C2FDF7616612BULL, 0xD25DF375E227CCBBULL, 0x3D6656299E3B0D32ULL, 
            0x5973DCE9B4EBFE71ULL, 0xFC726AA7D1ABEFADULL, 0x5C63ECBD33BA68F1ULL, 0x4A97AD7730202002ULL, 
            0x6F037B620F037D9AULL, 0x826E9A91E1475216ULL, 0xBC55932059CABCB9ULL, 0xC914CAE5143C49EAULL, 
            0x0BE1A583479ED10DULL, 0xAE6E9318AE01CBA9ULL, 0x205751DAA6FA85A6ULL, 0xF2BBA39E317AA3F3ULL, 
            0x08D5178202820625ULL, 0x184E98B23BAE4A67ULL, 0xD1F156775F3F201CULL, 0x87ACBF7AE32D99EEULL
        },
        {
            0x0D6FB3DB7BE4EDFEULL, 0xDFB391EA4EF6AD92ULL, 0xCFB1991D4C3B2941ULL, 0xD695C53307D7E6D4ULL, 
            0xD16EE3022141F61AULL, 0x7E14525AF963A0A4ULL, 0xAB602A58B2C8948DULL, 0xA0C1E9F41028489CULL, 
            0xB2AE853B6A1D410FULL, 0x61361BA6B9D26942ULL, 0x046C4376F6E0E417ULL, 0x2DFF30B4500A5E60ULL, 
            0x6EDC4645F01FB1ABULL, 0x3A16CAF1635F28BAULL, 0x17BDA91694162552ULL, 0x0BE90716F39F863AULL, 
            0x953BA52F48C7F629ULL, 0x5EAEF1AA29AC2E11ULL, 0xA4F1F4ED9B7E4AEDULL, 0x2DCC65DC32B41ECBULL, 
            0xD63C8479AF9D9493ULL, 0xCC71E90C92E429D4ULL, 0x69B7111AE1864B41ULL, 0x720882AA0BC9FC96ULL, 
            0x42707EBDC9914D26ULL, 0xDE202DEF4A01E1F4ULL, 0xC9368ED9E73BDFCBULL, 0x6AB59585F1BFFCC9ULL, 
            0xEC3DA9FD312A9250ULL, 0xAABECA8E992E762CULL, 0xC9E8E5150D46CBA8ULL, 0xB61E4078959BF561ULL
        },
        {
            0xF9427D59C7EA8601ULL, 0x9A8B4C0B9152D233ULL, 0xC6E75528C492CA6AULL, 0xD60192554446898AULL, 
            0x6E6B114FF42288C6ULL, 0x0B2FEF9CC76738D8ULL, 0xC0D82F9A7D51584EULL, 0xDF4E9FD8CB9EB10EULL, 
            0x408DF4CFE81305D0ULL, 0xFD36D4A987B86D83ULL, 0xAC0607B59F42B3E1ULL, 0xE9E790236AD26F8DULL, 
            0x5D98C79F9BB041C8ULL, 0x6EC15BB425C54505ULL, 0xA2E07BC2C28C4D53ULL, 0xC069030F29A6260CULL, 
            0x46C2C00CD8543FB0ULL, 0x1563CEE2B92DBA07ULL, 0x3777E099091407CDULL, 0x87506A7D4AC74607ULL, 
            0x3EB3D971DE57BC85ULL, 0xFE7B7CEEF1AE683FULL, 0x5D4D6294D4B52F00ULL, 0xD2486FA2CA3D6F15ULL, 
            0xFE2605B644AE133AULL, 0x9896C4236AF19089ULL, 0xF75F4386F9CA57B8ULL, 0x1DB62E6F2FBF5BF2ULL, 
            0x97F4DA9CBB92ED5FULL, 0xE4C990776EE7AABAULL, 0x910BAD7B0D3D89AAULL, 0x0409CD9674F3F60DULL
        },
        {
            0xBCEF16566BEC818DULL, 0x934472B43D43C0BBULL, 0x165D3A1B85041251ULL, 0x413C06C2415D6AB0ULL, 
            0x051F93AE4501EDFEULL, 0xEAFFFC8A5E0F3B14ULL, 0x15933C3CE7C3BD9EULL, 0x175C4BD69FD3187AULL, 
            0xE90EC537D8AC17A8ULL, 0x925CE53159561619ULL, 0x7F33434560EC5C7CULL, 0xAD0B8711567B9FD8ULL, 
            0x8C3AE9ED5FF53F49ULL, 0xE9F226240B477870ULL, 0xB7C97163FCFF2AB2ULL, 0x34884F4D8D41C5A5ULL, 
            0x5C42501ACD43DC41ULL, 0x4721C62F44635FABULL, 0xF6ACE21684340168ULL, 0x50C35C3976B606C6ULL, 
            0xD00711AB91154322ULL, 0x7B2DE293E474DBF4ULL, 0xA6A752EC41699B43ULL, 0xE617F56519B26F1AULL, 
            0x1E06F1D91A54522BULL, 0xA3D58DB1F28872AAULL, 0xB373139E007330C7ULL, 0x9EE35759118038A5ULL, 
            0x6DC3D693A2842768ULL, 0xD82059C4550394B8ULL, 0x1B1B33547C4A6372ULL, 0xCF331B8F1A158767ULL
        },
        {
            0x8531519497548D27ULL, 0x97153BF3017965A6ULL, 0x1D457EE6238F8970ULL, 0xD74FE85FDC0DF5CBULL, 
            0x7D38957AEC6600CBULL, 0x30AF05ABC7AC60A1ULL, 0x92ED431B6A02B842ULL, 0x80B787EDAD2DC539ULL, 
            0x2E982EC8A894ED70ULL, 0x13A876AD162EE540ULL, 0x131374986254AC34ULL, 0xCDB8FF030F542CABULL, 
            0xD703440E5742C469ULL, 0x57C6A05C9A8BC211ULL, 0x76B7FC34C7474646ULL, 0x5E08A8ABDB38D9B9ULL, 
            0xBF1683ED796BC330ULL, 0x69D45100AEBABAB8ULL, 0x6EFD32537CD3A49BULL, 0x729C770B97687FCDULL, 
            0x07B52D9A1F87F219ULL, 0x312BA5FCAECE3834ULL, 0x252928CF18B0085EULL, 0xDE429702F7F76B57ULL, 
            0x1937279503EB86BAULL, 0x18D4E99F222B7899ULL, 0x554BA8E2D26D8CE9ULL, 0x736F5A0C934E1E4EULL, 
            0x1E225ED212B28BF2ULL, 0xC6FB867F74E9ABCEULL, 0xB3F5BF8D1844C6F4ULL, 0x8BAA7FBEE931F397ULL
        }
    },
    {
        {
            0xCC851FF96E162531ULL, 0x11D10209DE820F7CULL, 0xD3AB2DDB39C51344ULL, 0xA5071D6A25EFB491ULL, 
            0xF1EC225CA61F06C9ULL, 0x11CF26C1FC69904BULL, 0x0E2918B21FB23563ULL, 0xF9D27CB3BB2593DFULL, 
            0xC1DF7E6DE42A58C9ULL, 0xAF9A2E89413F5E01ULL, 0x4FB791FFE7FE564EULL, 0xF715C4A94BB88463ULL, 
            0xC0FD3A1364281831ULL, 0xD7AD5EB4C80C5210ULL, 0x61052FC14F019E7AULL, 0x4C7C9F3FE50F7A6AULL, 
            0x271C80A04EC2B4C4ULL, 0x603A0AE13D2D6DD4ULL, 0xC45AB11AC1BA7706ULL, 0x10AE2811ABC9D63AULL, 
            0xFBE2AD9583D752F5ULL, 0x4FCBC77AE890F800ULL, 0xD9E2E0D9DA603A5AULL, 0xF275E7610ADA31C7ULL, 
            0xB5625079C6F68363ULL, 0xE580A7B145AEC364ULL, 0x33F816B402DB3595ULL, 0xA6AEC5446C84837EULL, 
            0x2C63A88A88602818ULL, 0xB1E622A6B916931CULL, 0x7C1E16CDEA905DF5ULL, 0xFDE50BF3FCA7DDC9ULL
        },
        {
            0x20F5B7D731ECD163ULL, 0xA54B4FA721D7DE4EULL, 0x861F7934B1438091ULL, 0x0F8EC9C9AF85716DULL, 
            0x379FDCDD59C9FAFEULL, 0xCFEF80A09B6F9A1EULL, 0x218E3C23FB2561F8ULL, 0xA769210050EA1410ULL, 
            0x9DF827F8E917B282ULL, 0x5DBAB3C876D91F3FULL, 0x3EB7C63EDA93D10EULL, 0xE11C620001F84C4AULL, 
            0xA8982423068F56D0ULL, 0x2586EBE3EDDF414CULL, 0x12FA0792BCEE84EFULL, 0x032810EE0C66428EULL, 
            0xB21E8812BC8B6FAEULL, 0x183EE448866F7A03ULL, 0x956A02250AE7A63CULL, 0x2B05A35F0C4F3CC7ULL, 
            0x190826C364E8F5DCULL, 0xC78DB261FAD6718AULL, 0xDEA4C8132751CA46ULL, 0x628A188A785945DAULL, 
            0x2746051522860BF2ULL, 0x34EE6B5230382A0AULL, 0x4575621FA5EDA17DULL, 0xED804C1D4CF6D981ULL, 
            0x55F501B2551FF96EULL, 0x13270268C9E1C6D3ULL, 0x4CE2580BCB7E690DULL, 0x2F2A6AF07FD2395DULL
        },
        {
            0xADE9943C5E239F26ULL, 0x945B04E379716242ULL, 0xEA8D426B615D9065ULL, 0xC1B14E51419DF929ULL, 
            0x6CB1BBDF46B55404ULL, 0x892391D9A14C2541ULL, 0x074528D030286327ULL, 0xDBBB006C47CB24FBULL, 
            0x1D07D9984BF93924ULL, 0x1F0389B21F429DFCULL, 0xA6713B6F3E260526ULL, 0xBE5138A0A1D2F8ADULL, 
            0xAC5B7CE3BA556C1EULL, 0x0E42333016DD6168ULL, 0x968812A7FED6EF43ULL, 0x6B5567C88F21100BULL, 
            0x00CC6190F1D1C9FBULL, 0xC00D8FF8D02A0CBFULL, 0x2D9B4B095FAF249DULL, 0xA6BE3CC4E983771AULL, 
            0xA808F17BD51BA3CDULL, 0x938CAADE0A226A0CULL, 0x9CCD266AD5AB140FULL, 0x446DA75A659A3064ULL, 
            0x0D3D011AAC6B9226ULL, 0x1422C6529DC9A4E4ULL, 0x241D81C6EB9F89EAULL, 0xF811349164177856ULL, 
            0x87ADE5336B8C3D56ULL, 0xC9D29C4ACA1BEB63ULL, 0x2EBDF25AAB322B88ULL, 0xAE464564C7C6BF0EULL
        },
        {
            0xA981078A76D437ACULL, 0x05667A5EBA955400ULL, 0x73AFA382F81286B0ULL, 0x30B61D962831391AULL, 
            0x7DC2AAFF25AAB7E2ULL, 0x4965DDC9B42B52EAULL, 0xCCD51030DCA2AD0FULL, 0x99F4AD5D0EEF125DULL, 
            0xD2DA331433D0C4FBULL, 0x78DC12EAF5E5B28DULL, 0x02EF540B428E03FDULL, 0x502611DC71DDE865ULL, 
            0x7236951A78A6E037ULL, 0xCCA97CC530BDE1D3ULL, 0x932042EC39C602B2ULL, 0xE7787E0CF7346DCDULL, 
            0xBEA76B6B0F1D5863ULL, 0xCE5065AA7460FA35ULL, 0xE7A026BDD1A53F42ULL, 0x0258AD4A2BA8624EULL, 
            0x80F20F794AE30A7CULL, 0xEDC81713D95C66F1ULL, 0x45F2D93D57FCE848ULL, 0x0B2F9907EEA1B657ULL, 
            0x55D181915124B7B2ULL, 0x813CFD00868CAC8BULL, 0x95D6D72AE2A048FCULL, 0x2315DE28016E5AAFULL, 
            0x6BC993A59F0227A1ULL, 0x573E6BA45942097BULL, 0xB2C3B817F3E8AF17ULL, 0x96B45194E458A29AULL
        },
        {
            0x2E7A6C26288C5BCDULL, 0xAB27CEA392007C2BULL, 0xB889F2F8F7993229ULL, 0x82DAD705839C9FD9ULL, 
            0x52B6702EB887F5E6ULL, 0x282FDE15250EED02ULL, 0x4D85C19CFECB4F63ULL, 0x6E89B90F386FD3EDULL, 
            0x3C9D08627475D0BAULL, 0x4E5C9E1691C79F7DULL, 0x9FD1ACEA1B44EF3AULL, 0xA70102842E45229CULL, 
            0x9DE3B1362F99956EULL, 0x21E911F56FD0BFA4ULL, 0x74D8261695762876ULL, 0x2F7FBB039687F44BULL, 
            0xF858A61617696B38ULL, 0x795E2B03AD63864BULL, 0x85AE26FBD631E6EFULL, 0x0A382252CF385470ULL, 
            0x25D96F0BECCAFA63ULL, 0xE06A421A143AD7C6ULL, 0xBCCF55049935886CULL, 0x93093CF896CBD237ULL, 
            0xC50AA560E145FC04ULL, 0x338F8C7FD7C5E364ULL, 0x4C0864E62C38D4FBULL, 0xDCB621AAD11FA173ULL, 
            0x674ADE2B0346017FULL, 0x88DE08569B70DD26ULL, 0x8548F655923B9F74ULL, 0x84E6CB65A2ADAF6FULL
        },
        {
            0xACE48F8F2B430669ULL, 0x46C77F193A3A3E12ULL, 0xB3EB9B8A2610AA85ULL, 0xD76187CBA81A4819ULL, 
            0x6947AB31BA06BCD3ULL, 0xBBAF3E39AF9C3C34ULL, 0xD1DEEC376E0EE00BULL, 0xCB43F63A18B29F4EULL, 
            0x95E9791D6CA8DF47ULL, 0x8537524757C9E1EBULL, 0xA4F95C69590B2CA6ULL, 0x7E98336ADD948EFCULL, 
            0x4AB12DC44D792DC4ULL, 0x451ED1174F3ECFFBULL, 0x9BCE405308E78950ULL, 0x863BDF89E5F9A487ULL, 
            0xDBEB7C205EA78A76ULL, 0x569B64E035DE3EDFULL, 0xB7DBA092E98F94E0ULL, 0x598D1FC332EA2668ULL, 
            0x8108938154DFB7E4ULL, 0x83BB2F017FFE6730ULL, 0x1814193A3EBE177EULL, 0x95B88D2C71201691ULL, 
            0x1BAF76DC1BBF4976ULL, 0xC38EBCA0FEDABA22ULL, 0x3A2A8E06A7054A78ULL, 0x4C0C75ED303FC606ULL, 
            0xA49F8B6F7C837400ULL, 0xE564526A52BF58B7ULL, 0x2E7B270435055D8FULL, 0x23FCDDD1DAA7A9F2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseAConstants = {
    0x4D66ECA38DB192B0ULL,
    0x9B926111B12817BDULL,
    0x438D25F8EBC93ADBULL,
    0x4D66ECA38DB192B0ULL,
    0x9B926111B12817BDULL,
    0x438D25F8EBC93ADBULL,
    0x44763053C1CE18FCULL,
    0x48F91EC9C266A2D0ULL,
    0x0F,
    0x05,
    0x98,
    0x2D,
    0xC8,
    0x1E,
    0xAE,
    0x45
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseBSalts = {
    {
        {
            0xAA89684305C708B5ULL, 0xF2CC5FD14D39C1C3ULL, 0xBB76411D4E43A7F8ULL, 0x0E6FDCA7DE13758FULL, 
            0x2A4AE0275A63F7C4ULL, 0x247E8A9046E83AF7ULL, 0xA19C87F1563E54AFULL, 0xFE103377814CD6C4ULL, 
            0x5149B33C132DBB10ULL, 0x2EBC3C82D27663BFULL, 0x70DD9BB5EB09AFD7ULL, 0x7F7012FCB29F5A30ULL, 
            0x3B9F58DB36603384ULL, 0xAB44D45674227544ULL, 0xF04ABBC73DD1020CULL, 0xB7CFFB026FDEEF87ULL, 
            0xEF0E05FF668F8A38ULL, 0x4752EF731607520FULL, 0xD252DF99288D6FAFULL, 0xED8B033CDBD334BBULL, 
            0x7BE539028AF6FBF0ULL, 0xF81AC99797D1FB8BULL, 0x06B81034228DAC00ULL, 0x0D07AF4E485FF306ULL, 
            0x6C3C0FC154A6A7E3ULL, 0x7ECCEE59D6D8FBD5ULL, 0xFF2D8DD9AB6C4E93ULL, 0x461715BD358BC0A4ULL, 
            0x8882558D0B77B1CEULL, 0x567CC55C8CA82F81ULL, 0x26042DE7E75256C5ULL, 0x43FF0D7430E63153ULL
        },
        {
            0xFF780498B777D556ULL, 0x55474C2E97BC1448ULL, 0xB7A9C920541F414AULL, 0xF9BDE6F4074BB438ULL, 
            0xE55D357949F99E28ULL, 0xD9E00A5E96A1F551ULL, 0xE4B10DCE0E3FFC67ULL, 0xEDEDAC3BF9878EDAULL, 
            0xD540F8FCDA999731ULL, 0x71372C3E418621D6ULL, 0x7B69BB46F0860065ULL, 0x8E32E60EF39262F2ULL, 
            0x042D18B7CDAC0577ULL, 0x1B6FA06BBE942727ULL, 0xC65E6639D1E300D6ULL, 0xF69260BA7538933FULL, 
            0x35A23CDC8F275710ULL, 0xDF20D9EC70CB97DAULL, 0x6D3E1B9DA3559C15ULL, 0x33111DA7E64006D9ULL, 
            0xA1D5D2DADD0CABBCULL, 0x3DD8344D1A5B624BULL, 0x376A560D1F8B3B3EULL, 0x134ECC032C7E4AFEULL, 
            0x55A89E25C45BB3B7ULL, 0x09A26C27766638ACULL, 0xEF26C7DAA24A93C8ULL, 0xAD1E5AAEAC6BBBF1ULL, 
            0x8B3AF51033D83670ULL, 0x7813819A2BE2CB00ULL, 0x552E1D1F5744E08BULL, 0xE7E64103EB2468D7ULL
        },
        {
            0xC3F0BB1BF99EC471ULL, 0x2DD4720562B1727AULL, 0x4356025FDFF60348ULL, 0x646AC0F7EE58FC4AULL, 
            0xE148AB317E22DE7CULL, 0x1CC010A972518398ULL, 0x9FCD6292530555BEULL, 0xE8AD39EAAA606EA2ULL, 
            0x074D668EDA8E0E07ULL, 0xFACF42A2BF033C0DULL, 0xEA2302621EEAA390ULL, 0xC57C8C481DAE5EC0ULL, 
            0xC44C9CC3F99012E7ULL, 0x723DA65F8AD63AE6ULL, 0xBC83E5A44F0DED5BULL, 0xBEF614428C2B410DULL, 
            0xCDE3213C3DF91377ULL, 0x750E8E98A771673EULL, 0xEC1A7EE06E6116C9ULL, 0x4C34C01910603004ULL, 
            0x8F856AE02818D505ULL, 0xC6D755686FE12688ULL, 0xD4166AFBA73D00F7ULL, 0xE7CFF771ECE14B9CULL, 
            0x214C42B83589D9E5ULL, 0x3D7C1B109A843DC2ULL, 0xD496C4933D1ED427ULL, 0xB432CEB45BDDCFA3ULL, 
            0xBB9FDB834C312D35ULL, 0xC6E63F71C54B429CULL, 0xF410B0918D3482D5ULL, 0x5BBD2700BBD7554AULL
        },
        {
            0x0066D6B4DB6FC16FULL, 0x890EE4001E2BD698ULL, 0x7F2C7718042A974DULL, 0x20ED86AF57C475C3ULL, 
            0xF74AF6541043423AULL, 0x5694C67D3FDA8493ULL, 0x1E1DC288CC72D76BULL, 0x979448104A9A4634ULL, 
            0xA7AA1DDC13CEF785ULL, 0x2477D28597F1C135ULL, 0xCFF1EB920AD762BBULL, 0xA9E6AACB2CFCFB1AULL, 
            0xE0AE1AF7C40D4082ULL, 0xEE9F600F23DA36DCULL, 0xD1BA6341538CEFA1ULL, 0x05A684F6178F7638ULL, 
            0x9F2B3990C3E698C4ULL, 0xC981A2BFD61801FBULL, 0x4D4A65C63A52A6B9ULL, 0xB0389FB8A8F3AFEDULL, 
            0x1E32647547FFC78AULL, 0x4538B3757C09450FULL, 0xD8AE04B1F50E9AE1ULL, 0xAEEF6C9CF7F70D55ULL, 
            0x2643F4E3DDEB479AULL, 0xD95C2A3EE763FFA1ULL, 0x842864EFAF227CD3ULL, 0xC352E6D9FEA747B0ULL, 
            0x2F9798F556E3F04DULL, 0xFBE50B419AC5EA45ULL, 0x9DCAAD07E2A2F07DULL, 0xF61A3F427DDD16F9ULL
        },
        {
            0x2A9EB4A95C41DE53ULL, 0x333AC4C7A03420A1ULL, 0x5230C2B990849332ULL, 0x87DCB02B3D34CD89ULL, 
            0x9389B5B231FB68DFULL, 0x1821EEDAD3B39163ULL, 0xDA13CBC6340209F6ULL, 0x2FE49BFFB5F3AC47ULL, 
            0x206BAFB5F36C722EULL, 0x428968801CE11004ULL, 0x14CB728F89818E22ULL, 0xF61CAB12A43F5EA4ULL, 
            0x18A8A8C460A18289ULL, 0x25B88A4940353F7BULL, 0xE2F8B1F4CDD7E99AULL, 0x44589028D3414D29ULL, 
            0xDFF4AFFD9D9D5246ULL, 0x27E6CDEEF8E8A635ULL, 0x7F9AD47F370FE84FULL, 0x2C3815AEA3BD06E4ULL, 
            0xCBA409EE5C595B56ULL, 0x18FBA28242690592ULL, 0x1756A81F3EFCB9A1ULL, 0x9D82DE7CD2599169ULL, 
            0x9540CC7FC9B37086ULL, 0xAFFAA70CF2154AF0ULL, 0x6EEA903B64AAC37FULL, 0xE66A4D1D7EF7DC0FULL, 
            0x1B56862766BDC513ULL, 0x89C302ABC05FC8B7ULL, 0x5441E62FE3B8481DULL, 0x99475E9E0F0ABCD1ULL
        },
        {
            0x22D7C72FA7F2BE82ULL, 0x1FF1B2B15D18C56FULL, 0x01933C475DD15664ULL, 0xC14DE0A78BC0F5F4ULL, 
            0x529B86E2CD1D4996ULL, 0x99C60DCF7B269D23ULL, 0xDE155F4EDFB00CBCULL, 0x58682F8C453D2D76ULL, 
            0x270DDB57F5D37866ULL, 0x343C0B0161375758ULL, 0x8C4025C1A4F52EC8ULL, 0xFD7F327F4128C42AULL, 
            0x3A9ACD0CF10E7BD9ULL, 0x4293FD7EF2B78896ULL, 0xD608A840D9D2E9E9ULL, 0x77B5DE26E00BCF6CULL, 
            0x9BF600FFE936E95BULL, 0x0FB8418FBEE08765ULL, 0xD7B344FD7C0D5D33ULL, 0x48EBCBDA85BB1941ULL, 
            0x894135648D056C35ULL, 0x97AE36B7D9FF93DAULL, 0x4D98FC29138F539DULL, 0x6E5EF36088FFCC88ULL, 
            0xE02491577DF9FEA4ULL, 0xB67EBEA41F01BDD5ULL, 0x539AB2F5337E70DBULL, 0x6E5741BBDE03D8D2ULL, 
            0x8211601B58404469ULL, 0x337ECC2A71E66FF1ULL, 0x35175C99C7479404ULL, 0x382EC34278DBB587ULL
        }
    },
    {
        {
            0x06055B18C89ADF39ULL, 0x6873E176C9562631ULL, 0x2CD4F3DD8C861B94ULL, 0xE5CC61DA360ADAB2ULL, 
            0xA847FB0EDD827FBEULL, 0x48CF5BB0BD9FE0DBULL, 0x1F2C9616889174AAULL, 0xB07AAAABE551DFF1ULL, 
            0x0C6E415736A78115ULL, 0x53536C36ACFA4A40ULL, 0x3CCB3BAA5228E90AULL, 0xE1D06F6D6B66BF4BULL, 
            0x67FDB8E92115204CULL, 0x92397232EE634AC6ULL, 0x5A91810EBCA92894ULL, 0x0313D33430417FD8ULL, 
            0x7BB789B33EF00863ULL, 0x2084B7BB3C3AE995ULL, 0x242D912545BA0B83ULL, 0x433C126F8FB331FCULL, 
            0x504008EA2417863EULL, 0x603DC65EDBD54702ULL, 0x0698F3F2C753C5C4ULL, 0x2C14E62C761DCEA4ULL, 
            0x6815B17BF9E8E1B8ULL, 0x4C3A778EE78D168CULL, 0x5E819F9089E5CBB6ULL, 0x0D6BFEEF46214D8DULL, 
            0x516212B731A8AAF1ULL, 0x3D8594C0A5C1224FULL, 0xECC203FCE2CC687CULL, 0xCD4E8FEA764A17E0ULL
        },
        {
            0x982DA02995C9F148ULL, 0x78AD0D2CEDF8D027ULL, 0x4CD8441C8DC18939ULL, 0xF50F104FF565B1B5ULL, 
            0x7859021175D5F374ULL, 0xB179EBAD90974CBFULL, 0xC9890E7FD3FFF7BBULL, 0xD83D30A1E7829BB7ULL, 
            0xC9C806EC340A9304ULL, 0x3156E604E8488F9FULL, 0x8EC42650C6E035B8ULL, 0x0AD4FDF9308E6C24ULL, 
            0xBEBA33FA4CF158CBULL, 0x038F6BAC65AD0953ULL, 0x980AEE8946797E39ULL, 0xFEA147BFAC5F9DBFULL, 
            0xCAA859864E7E91ABULL, 0x76DB8AC11C3295E0ULL, 0x4F70E2F4A34C867DULL, 0xA4EC22F123184F0FULL, 
            0xDE7D4599B9075903ULL, 0xBFFD0298B2E3B50FULL, 0x10AD5A965B0DC9AFULL, 0xFE8B088539DB700DULL, 
            0x57AC562DEA3C9792ULL, 0xC9EE4799664DB4C9ULL, 0xCCB967E52CF1A18DULL, 0x77E9F077E920B65AULL, 
            0x7BDA146C23523F5EULL, 0x0AD39E0DCD800818ULL, 0xDF8B5A48ABA64125ULL, 0xD62BA5BE8D8F1E5FULL
        },
        {
            0x963E70938528F1E4ULL, 0x46BEDFC636B8448DULL, 0x49F403C65BBAD0B4ULL, 0x0AD3EE4EE35CBE25ULL, 
            0xF5BE919F59B47A2BULL, 0xE38E31916389ECB4ULL, 0x9A270D01A1D66E75ULL, 0xCD6F3B0185607BDEULL, 
            0x281FFB66C89F1255ULL, 0xFDE9BA08C3DD2677ULL, 0xCFD95CE65C0BFC23ULL, 0x0FD8A9A0199DB069ULL, 
            0x04444926B5A68139ULL, 0xA947386B8CB56C1DULL, 0xB9379FAFC8D88FACULL, 0x0BDBD9B2E0C2B9C3ULL, 
            0xBA6BFB1A6F14B9CBULL, 0xC754C9877407F233ULL, 0x0A891AF2045EDBCAULL, 0x56C8C445A560BF7AULL, 
            0xC6C94977DF02434DULL, 0xE4D642E6DB1F8E4EULL, 0x61C3200BF8626668ULL, 0xB52517F6093150CBULL, 
            0x426CF8BBA1A324C5ULL, 0x8E25294AF1FE6353ULL, 0x6A6C94C2DE7753CEULL, 0xB009A55FE1A85AB1ULL, 
            0x0C548AA2FCBDE4DFULL, 0xC87BE02662AAA2B9ULL, 0x848EE2C6D2E00CFDULL, 0x4D582F289CA85FCBULL
        },
        {
            0xF7BB1259F762FF5DULL, 0xC771ABF3DFE48EC2ULL, 0x6C61BE3DCF0E3DF3ULL, 0x74395718D9C93735ULL, 
            0xB8F94252BB3B94C8ULL, 0x0A1CDAB4F7551AE9ULL, 0x7A17B937B69D97D7ULL, 0xA164D121ED6F114CULL, 
            0xE2D2C47A32340624ULL, 0x639B4ECD1DBBFDC9ULL, 0xFCFF8F9626CC674FULL, 0x58E4E72491110830ULL, 
            0xF7974C72ECEC0A84ULL, 0x0BFE82F64BBD328AULL, 0xDE6E99A3B562D82AULL, 0x0E92A632097CC809ULL, 
            0x5E3E34498CEDF2E6ULL, 0xFD2B61B41446CFBAULL, 0xDA93CC048C30CE3DULL, 0x6297AD15350A228CULL, 
            0x74A563AE38B98673ULL, 0x2C1B260A30DE2B2FULL, 0xF7DE1781BB21E85CULL, 0x12EC6D15A963CAB2ULL, 
            0x0A1FAB6C53C4DA1AULL, 0x8F88EBE458B36C87ULL, 0x7AA24AA5D17320C2ULL, 0xE5EB786EA774D655ULL, 
            0x78E25E3379F258C0ULL, 0x5559562434913627ULL, 0x0E6DECEF39CDE18CULL, 0x4086001B5A0B9B4EULL
        },
        {
            0x8C545EBF7F8991FFULL, 0xA6DE1B11E07F1D4EULL, 0xB69885B481F3398DULL, 0x7EBB974065EDA299ULL, 
            0xB332F8E5B772EF68ULL, 0x8F190AEBA360C7E5ULL, 0x0EF272F8FD3A34EFULL, 0x27A0E6AFB92C709EULL, 
            0xB5E45F2978005298ULL, 0xAC4FADA43B4D8362ULL, 0xA3DF188AC5101516ULL, 0x14768E348E1C543AULL, 
            0x9375182EC66E240DULL, 0x1ED3D2CEC69828BBULL, 0x695CB510BFD8857EULL, 0xFC6406033215C23AULL, 
            0xAF83A3E44B446A50ULL, 0xBAEB8964637232B4ULL, 0xBA520662D5188394ULL, 0xE01DB9E5A14B1157ULL, 
            0x0260C148F31EED22ULL, 0x1F7A2B2BA7D07C4FULL, 0xF4975C48DEDC3994ULL, 0xFC30426244ADC822ULL, 
            0xF4DE4D4695A7834DULL, 0x1C5BCF715904A32EULL, 0x5CDBDE8D97B3BC9DULL, 0x0B9883A890AFA6FDULL, 
            0xB229C14AA1BB5053ULL, 0xEABF4389E681A501ULL, 0x04DAB69DCDA98FF4ULL, 0x024CADE7934C65B2ULL
        },
        {
            0x12BFB31D4B9A4CB4ULL, 0xBC7BAA9FD5F4385BULL, 0x28DD511A049004A1ULL, 0x2720FCF0ED132167ULL, 
            0x09788D817B79319AULL, 0x5745788A4DA8BA42ULL, 0x01B8CE3461370A4EULL, 0x5438F458098FCB9AULL, 
            0x179653E2169422E3ULL, 0x8EE784EC3043E11AULL, 0x8D41065A52646305ULL, 0xB911DEE32E37AC3BULL, 
            0xB9FEAE7C25F01ADCULL, 0x8446D75C4E66595DULL, 0xF2E7037F9713254CULL, 0x8F6566DB2ACE57D4ULL, 
            0x268858C0EDEF24A6ULL, 0x0E41083B5D57F740ULL, 0x8FC3F4F4FB805606ULL, 0xCFF53E89DB6A4CD8ULL, 
            0xCDD4422946E408A6ULL, 0x3922E3F6EB75EE50ULL, 0x3EA7FA82F53BB75EULL, 0x5C0AC475F8DE2EBCULL, 
            0x5B6733B2678362BDULL, 0x22B59FD1B05371B4ULL, 0xAF7C6F2C74FB8FF8ULL, 0x5BBE12A18DE27C11ULL, 
            0x498CF713E2670EC9ULL, 0x5EC675C160F07999ULL, 0x0FF0AFF84A3F5C5BULL, 0x5ECD2FFAF8AAC717ULL
        }
    },
    {
        {
            0x0C61CF5AE294C919ULL, 0x12EAC9D03A38C57EULL, 0x8DFD2157B022B3E8ULL, 0x96C8BEF653C40471ULL, 
            0x4B89BAF45A960845ULL, 0x7E628E3589EABD4DULL, 0x0C2169882161FA21ULL, 0xB173341C126F2510ULL, 
            0x2515086A141F703FULL, 0x37FAEEB4288C2169ULL, 0x928BAAC791624CEAULL, 0x4D28A9F743DD0AB1ULL, 
            0x1B492A9904BA294AULL, 0x09AF04E01BCBE5B1ULL, 0x0C82A274F77E6A54ULL, 0x425846A95AA10B55ULL, 
            0xE310A583E1B97024ULL, 0x02CF9B1EC5BEB3ADULL, 0x3CC8D8E01707779AULL, 0x3BB96A8886523510ULL, 
            0xBEE7CB488E8834B8ULL, 0xC5DAD33351539AD0ULL, 0xE005FE6783D3708DULL, 0x7B1B74E558F785F9ULL, 
            0x1AB155A3B824D964ULL, 0x772B1FC75CFE716FULL, 0x04DB147866017724ULL, 0x97182D8C9D23B91FULL, 
            0xC15C3929A118BA05ULL, 0x4497BD706DBF3373ULL, 0xE8182BEB91D2D7D8ULL, 0x4ED80DA0F90B207AULL
        },
        {
            0xAEF4DF14295D4B2BULL, 0x7B19929D1401912CULL, 0xC1F9C87783E1E61AULL, 0x54529EABD01D7CC4ULL, 
            0x865B90AFAD3032D2ULL, 0x46CC5623B56D9338ULL, 0xFCDD5F1F19D6E667ULL, 0xF47A5C689953ABB9ULL, 
            0x69D4CD0D7587E453ULL, 0xB57B6F47801F22E2ULL, 0x1ABA53E1147095C4ULL, 0x46AF9EC048FD76F7ULL, 
            0x2F0317932D01FC5BULL, 0xA9776BAA2D234F4EULL, 0xE2D24BD51B791160ULL, 0x9B0A75372FBAEFE2ULL, 
            0xAB06E255042E9D3FULL, 0x87FCB228E2F89E39ULL, 0xF60A3D7AF8412F46ULL, 0x7CD9FD1F2B766B4FULL, 
            0x79D4C0F871B00CB1ULL, 0x12AD2A09CAEA7144ULL, 0xE7F2963553411266ULL, 0xF5596EA2E19C9B6AULL, 
            0xD533DEE10EC8DD04ULL, 0x8E5E8092480ABF33ULL, 0x8BBFAF5DD903B2DAULL, 0x27B27D51399EA7BCULL, 
            0xC3E55740CAB25CD5ULL, 0x424815111E13A458ULL, 0x16E229B5FE9D1791ULL, 0xA945A5B79D36F5CCULL
        },
        {
            0xD09D11581D768E54ULL, 0x4ED31989C2200F33ULL, 0x0F8CD421516FD58FULL, 0x0D08A472DE458BCBULL, 
            0x0B8B7A2CE6107964ULL, 0x7C59B37EF408B617ULL, 0x7499AFB7F62E126BULL, 0x740E82698E50A766ULL, 
            0xBE51DEC3C1D18C61ULL, 0x891CF37A4FC07C31ULL, 0xA183F05D229D1A61ULL, 0x3FD1291B885EFB76ULL, 
            0x1B936E1620B65DB2ULL, 0x9C4702B7762D50B6ULL, 0xA4B4F51642EEFBEEULL, 0xE82D4E28A0283F70ULL, 
            0x6E3253A4DBDC08C3ULL, 0xE47E499A854C5B6FULL, 0x2EBAC6FB437EB620ULL, 0xF0910C574E529D5BULL, 
            0x63F1C94562E4F259ULL, 0xA78D8334C1D49BFCULL, 0xAB163F123845C209ULL, 0x5DB35F7BBAE0EBB6ULL, 
            0x98FFCE01080BFD85ULL, 0xC9BCE1A458CAF0C7ULL, 0xFFD8C2117949386AULL, 0x2E0B9C246738FDE1ULL, 
            0xB46EE21C2E1D6EB5ULL, 0x26FC9EB52F817797ULL, 0xC386A0027DFF0DC5ULL, 0x2171C06DF2D180CCULL
        },
        {
            0x2517679B54B300EAULL, 0xFBF2A252864EAB69ULL, 0xDE684FBE6FD2FF0FULL, 0x3E3B12A6DC1844E8ULL, 
            0xD400FF78790BB4C7ULL, 0xE4E79FFBFAC7CE28ULL, 0x1DF8DEB1DB81709FULL, 0xD4E45A9C91CD2A4FULL, 
            0xCF8198C0BEF0AE23ULL, 0xB99DD550470517BEULL, 0xD257233DC69392CEULL, 0xB38317609943BBB8ULL, 
            0xCD7BE6BF9A06CF6EULL, 0xF866DC7A1B7B04C2ULL, 0x5A57725FEBEEA516ULL, 0x53205FB55B976856ULL, 
            0xCC2731256F39B02DULL, 0x12E3572D08063E8EULL, 0x7703DA3E86EDF0D3ULL, 0xF83F6BB082CAF604ULL, 
            0x774CC3C582773FA9ULL, 0x739A76DBF798CEC6ULL, 0xEDF99EF4701AB3ABULL, 0xC1E95BF2C6479B5DULL, 
            0x40AE2BB761E0ABD9ULL, 0xB0760F93D4FF6ECEULL, 0x06FC9C5FA6E31484ULL, 0x42E821EE68522683ULL, 
            0xC2ABDA082E755045ULL, 0xD8A1B4F19782639AULL, 0x41F5833CDEEF198BULL, 0x21DBA200EB3C079EULL
        },
        {
            0x80653588F909BEC2ULL, 0x020453B16EF965B9ULL, 0x82F958F2A2421BAFULL, 0xF4697A7DDC5D80B2ULL, 
            0x0B7A9B5A5D0C715EULL, 0xA382C17B9EA82462ULL, 0x95E97FB933A8D46BULL, 0xC754E942E5BBC132ULL, 
            0xA82020D91A6746EAULL, 0xC6DE84102FC231C6ULL, 0x785F79B9748BC647ULL, 0x024DE4A2FB10659AULL, 
            0x553827C7B42DE314ULL, 0x4E7FE79274AE6908ULL, 0x566AB2444D3D7E68ULL, 0x3F389E760E7FCD13ULL, 
            0x06A40064F4E7BCD3ULL, 0x48BA3F55D12A8BBDULL, 0x211FDA2B20435B01ULL, 0xE7EC6722AA2C7D4BULL, 
            0xED8718A3D4C881E8ULL, 0xEBD67A418630AEF3ULL, 0x4C82EC425092775FULL, 0x7F27FE5F96FEF623ULL, 
            0x707CACB589124DEEULL, 0xE8C8054F67BD6F11ULL, 0xDC3AE60010F1AFF1ULL, 0x21B77C838C039F29ULL, 
            0x63F4DEE1646A51D4ULL, 0x16A76CA90A93DE48ULL, 0xFBCD4938C29B23E0ULL, 0x46FE0334A69C2B6EULL
        },
        {
            0xC588335F98024699ULL, 0x129FB8F5668FAC4CULL, 0xA4537172EEA1DCEEULL, 0x1FD8BD890C3EFCFDULL, 
            0xD4F1BF8A7F82BBBBULL, 0xE66E99F45C7D7964ULL, 0xA82B6634876D646EULL, 0xB989CE6AF1BF762AULL, 
            0x421C5A3A9F7A89F9ULL, 0x42CFD0E55373ADC3ULL, 0xF61A9630704CCC61ULL, 0x6A6EA39630C00B8AULL, 
            0xBCF4F55FA5814C60ULL, 0x998E12F06684E225ULL, 0xBC552BCEBB7C355BULL, 0x53C6211137C2736EULL, 
            0xE585FE2DF9E56C31ULL, 0x871141D6D6A453FAULL, 0x78DEB6B75A6BAE70ULL, 0xB3D2D1817960A81BULL, 
            0x8760F32DA8702E6BULL, 0x0FF3A36C50E1D78EULL, 0xD34764FB00B634C6ULL, 0x66A3FCBDB4EBD4EEULL, 
            0xCCE79A13BE73B939ULL, 0x640D73B92930BBD8ULL, 0x0C2AF6F60DA00546ULL, 0x5795F1D1B27B055FULL, 
            0x4FB85D3BBA9C1865ULL, 0x3F6C367DD6C68E82ULL, 0x123606A3A7118009ULL, 0x97C82924B40FFE31ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseBConstants = {
    0x73479AA7E90AEC49ULL,
    0xDA4CB62F852447F8ULL,
    0x78BC74CCBDE3CF26ULL,
    0x73479AA7E90AEC49ULL,
    0xDA4CB62F852447F8ULL,
    0x78BC74CCBDE3CF26ULL,
    0x288F7B15F9171D8DULL,
    0xE33F4AB7E1DEAAF7ULL,
    0x09,
    0x48,
    0xAF,
    0x5A,
    0x11,
    0x44,
    0xCF,
    0xF9
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseCSalts = {
    {
        {
            0xA42DE309AE805FCAULL, 0xDE6F093E1FA3727DULL, 0x9FA2136F43FCDFBDULL, 0x9D67694D3A201115ULL, 
            0xCCEC46099AAE28E3ULL, 0x0EE3D7792D9060ABULL, 0xC388E09FEA753FB3ULL, 0x723B9142464A1F70ULL, 
            0xFA9C56A04A54DD91ULL, 0x711DEC48C87DA3F9ULL, 0xCB1D0ED027CA5883ULL, 0x5D32B18A22E77C4EULL, 
            0x0A0911DDC974D4EAULL, 0x1B001F2E968D4C2EULL, 0xEE2C87AB95BE2B2BULL, 0xCDED8B6CC2196B55ULL, 
            0xB544E71D217ABE01ULL, 0x8E6958055E6B84FBULL, 0x3DD08A3778F81095ULL, 0x55247A55A8E6C133ULL, 
            0xD232898BC13B27A1ULL, 0xDCE585ACC9245B11ULL, 0xD8ADCBC26E3EB2DEULL, 0x6CAD09B2CFF28496ULL, 
            0xCEF7640D68D8C490ULL, 0x5459CD145F62C63EULL, 0xD94F0C7329692A7AULL, 0xD106875ED6C61C88ULL, 
            0xFB1EEC6B0174B506ULL, 0x61ECFEF692CA7CEDULL, 0xE6A4D542E23F8597ULL, 0xF9DDE4859DBA2506ULL
        },
        {
            0xB6F2A500C2FD6AA2ULL, 0x7539FB9D9E83EF0DULL, 0x121D8D6242D6BCE3ULL, 0x68D9FAFC16FB1098ULL, 
            0x02C2D8714C6C8248ULL, 0x45B9BA6692C52D0BULL, 0xEFDF567B5C78008BULL, 0xF0CBAB988F052319ULL, 
            0x7BD280F286D3C433ULL, 0xD8C00BACDE1CFB33ULL, 0x39B231D1B8BCBF35ULL, 0xEFF7324048D471E5ULL, 
            0xBD7680C749C80FC0ULL, 0x626F7C42E8CF2B23ULL, 0x2EB76F6CCB35C786ULL, 0x9F3E7BC5E4C6DACBULL, 
            0x2FC3C9B89D2A8E63ULL, 0x754E1BD551CE6816ULL, 0xA614FDB598EDDCACULL, 0x77D2CEFAFB1DB81EULL, 
            0xEB69D126095F2CDBULL, 0x5EEE7C53DA5A8898ULL, 0x1B1C59F091228521ULL, 0x034E93ADC6A76553ULL, 
            0x4B5A8C58FD466DF8ULL, 0xF1810D0D29324627ULL, 0x6412CABFAE4D6121ULL, 0x059278E6357CFD41ULL, 
            0x2F71CE1B0EA9E6B7ULL, 0x2A378B3B1378ECF4ULL, 0xA9727D47CA7A7888ULL, 0xEF0E662A2D36950BULL
        },
        {
            0x22EDC8FED4319D18ULL, 0x1E31B83FDDDAB282ULL, 0x28E341B78436C613ULL, 0x5DF10AE6CC12A463ULL, 
            0xEF7B164CD3D74AFEULL, 0x0742DD6A631CCFAFULL, 0x56929F3E2B5BB4EEULL, 0xA475A578087C0729ULL, 
            0x0EAE891031DD8374ULL, 0x8BFD969241D5AB0AULL, 0xBAF41075D5388910ULL, 0x3142D592A56B41C8ULL, 
            0x90E113128EC48509ULL, 0xFAA6D70FAC3ABD4DULL, 0x5EF3CD228F410EEAULL, 0x7CEFD5FEACE398F6ULL, 
            0xD6ADB5DEF726B259ULL, 0x5CF19FB45581F563ULL, 0x4363EC3BECC32758ULL, 0x0C2EE7E897AE5EC6ULL, 
            0x1846858DD50090B8ULL, 0x1C6A54F4832E366FULL, 0x8DA2ADD38EBFBCC5ULL, 0x591C670A460645FEULL, 
            0x3B68BD316A287B54ULL, 0x5B2A06D2FFEF38F8ULL, 0x05009A7204DA6FC5ULL, 0x3A11EDDAD7C01DDBULL, 
            0x633102A1503C89A7ULL, 0x164E030C58C6C135ULL, 0xD58419C28BF3BA9EULL, 0xAE992BBD5187AEB8ULL
        },
        {
            0x028D762BD8B27382ULL, 0xA43765976A07F948ULL, 0xC68C482FED907C91ULL, 0x42DBD6E159BC2008ULL, 
            0x55AB29D82832DCDAULL, 0x8527C79AD211E0E7ULL, 0x5284F9461C050D90ULL, 0x3E4040932523FCF9ULL, 
            0xD34397CBBF69FA49ULL, 0x676F004D1817A727ULL, 0x7C69B2C67F1A3422ULL, 0x2CBB36CF6582DB11ULL, 
            0x8AD1C904B218AECAULL, 0x21462FDE1846A55DULL, 0x692FA92DBCA85B97ULL, 0xDE49580699821EA0ULL, 
            0xF4A93E7FD2624127ULL, 0x39DABB6D8EC9EC0BULL, 0x0C91DB559335F6CCULL, 0x5B3F254E97C71939ULL, 
            0x724030B80CA14074ULL, 0x8F66C77360FCD3BEULL, 0x582877F05A8615ECULL, 0xC47117222DC00E5AULL, 
            0xE2857A8EDB9BDA9DULL, 0x946C5CEFC04439A2ULL, 0x5C1B6E2099DC0963ULL, 0x8583F4CA8D05F1D3ULL, 
            0x4E2FF54A8066E925ULL, 0x507F5407B65D19C5ULL, 0xD240E51938A28DE1ULL, 0xCF720C2724DAB55FULL
        },
        {
            0x519A122CED6F6733ULL, 0x3880B5DB75E3CCE8ULL, 0x90297FEFC44913EAULL, 0x669222BCEB82E517ULL, 
            0xB57825BD94CC67C8ULL, 0x76F68C34CB9D80EAULL, 0x66F0E5199E640653ULL, 0xB92FC3587618C5A4ULL, 
            0xD42374C0EDA06640ULL, 0x67139C716BA4A3D7ULL, 0x5AD7BDBDA9A31663ULL, 0x822448427B37A8BBULL, 
            0x69A05D23750E63B9ULL, 0xCD59878631F96EAAULL, 0x575A721BCDE484CAULL, 0x2C11949CACD141E2ULL, 
            0x23DBAB311130F21AULL, 0x67103B1A21245DE1ULL, 0xF312DB9B01C5D52DULL, 0x7EA379A0753E1039ULL, 
            0xD728D8882A27E9AEULL, 0xA33FEF7C19AD58CAULL, 0x20255115496F4C61ULL, 0x376415D77F65D326ULL, 
            0x737FC080A1AB77A4ULL, 0x0E42A1F5430EF08DULL, 0x0E52097491F3A608ULL, 0x772AD1DE41A9F069ULL, 
            0x91F616DDB1114EDFULL, 0xE0A20B485F823E3EULL, 0x9A7D57FD81D22F98ULL, 0xD8C95B7E330E2F15ULL
        },
        {
            0x6D1F05F927805E2FULL, 0xEE6961DD1FABE565ULL, 0x316740991314BF18ULL, 0x1D087B9A002CB3D0ULL, 
            0x418EA3710EBDA878ULL, 0x3D21C42969F8CEA9ULL, 0x95E1755760EC284BULL, 0xF9AEF91412309129ULL, 
            0x92E95F8B23CDCB24ULL, 0xCFD447089F703326ULL, 0xBEB6B0586B5619CDULL, 0xAE77B84884904C75ULL, 
            0x61CFD6B6E077B85BULL, 0xC1A31D64C609D4B5ULL, 0x6A4EAEF941BB7C36ULL, 0x17E361DDDC50EB21ULL, 
            0xA2BAFDBE9A6C28A3ULL, 0xDB94D99495236649ULL, 0xCE94A7C3EE5DBA2CULL, 0x2766B0D758CF8946ULL, 
            0xE9172C23EA8E0250ULL, 0xA914BA5727F2D9BFULL, 0xB0AED91E29B5A22FULL, 0xF50F5A27DB0081A7ULL, 
            0x464C4136055BB331ULL, 0x0AB3C90B3E9A1743ULL, 0x3A14C627AD5A0A55ULL, 0x5D3079C1D036627EULL, 
            0x47B145989E0CF16BULL, 0xEA50312B9D680313ULL, 0x06E148437A814D29ULL, 0x7E281AEE20A7416AULL
        }
    },
    {
        {
            0x5379B802D8A9389FULL, 0xC77CA6A4404CEEF9ULL, 0x28F25332D63AC0D8ULL, 0xF1513AE0094D2DC3ULL, 
            0x29F5ED8A410AD77AULL, 0xDCB06B0B01386036ULL, 0x115F4090EEEC646EULL, 0x998BDB213F992556ULL, 
            0x904D09688D4BFB27ULL, 0xB3C61A65C0E02A4EULL, 0x7DAB28A83FA181D9ULL, 0x860F2EFA3A179199ULL, 
            0x4093EF8E62D56039ULL, 0x11F90F457373B47CULL, 0x6407800B69662B6EULL, 0x6ECE0DAE813188C0ULL, 
            0xFD4156F4A28CF16AULL, 0x75BBC3FDA8EA0E4CULL, 0xA30E82DB22CA9ACFULL, 0x699091B668E156F2ULL, 
            0x5FF8966EE4F6E3ADULL, 0x84C95CABBCC6CF94ULL, 0xA7751B3C15E8DBF5ULL, 0xBA6FD39224902E74ULL, 
            0x8152ECF9013371E3ULL, 0x5177E82590754611ULL, 0x517929BC37C7B971ULL, 0xDE2FD0FE5CDD690DULL, 
            0x5417B7A86A3A67CEULL, 0x31401FE2C0BF38F3ULL, 0x8E92467CC0A7CFC0ULL, 0x45F6B504E84FC8ACULL
        },
        {
            0xF1030B97642B29B0ULL, 0x495C3F16BAF3B3E0ULL, 0xC3856FF16D38D238ULL, 0x02DC7ADEDD2B2563ULL, 
            0x7BD5A77F2137A335ULL, 0x7E598A7F9A9C87BDULL, 0x8EC2C6D6D33205FAULL, 0xD4FFD98C5DECFA4DULL, 
            0x748FB2D2C43C85C4ULL, 0x7719FB7E5C13C3DFULL, 0xCD6AF55237FA29ACULL, 0x9C458F0ECF06CC43ULL, 
            0x156E386F78D0B512ULL, 0x80B308EE01BACCEDULL, 0xD20DBB2036E0F45CULL, 0x53C949A9BE0802DEULL, 
            0x801DFCE078A9A24FULL, 0x043D682EE3A412DBULL, 0x55250C226921798EULL, 0x7112AB9F3C3572CBULL, 
            0xBB29D0650069E504ULL, 0x575C5672608C7B4DULL, 0xE41F5F7E8059BB0CULL, 0x3619845E6A732E40ULL, 
            0x060F4F55EF2A1116ULL, 0xC1AE714D98081F4FULL, 0x5AA7106C72C2142BULL, 0x4378403FAA83981BULL, 
            0x6D91AF841DE36477ULL, 0xC7ED6D70F94BD0C1ULL, 0x33964DC8811FE783ULL, 0xCBA45360DA2B4773ULL
        },
        {
            0x4D893DBDC29B5650ULL, 0xBCCACA47E797C6AAULL, 0x1ABCA273997E8005ULL, 0xDFAE77508600BF47ULL, 
            0x2D9444DFAD6E0104ULL, 0xDF9DB5592B63BCE2ULL, 0x31E2D8D8D3A4E173ULL, 0x3E098F0A35C64E57ULL, 
            0xD673897175163C11ULL, 0x8491918A33C60749ULL, 0x4CE0CA972139EAEBULL, 0xE416B8AD58E3EF55ULL, 
            0xA137BE785D19E09BULL, 0x7DE3CFF32D8B3318ULL, 0xCC0D9582DC76B6B4ULL, 0x1D5D5452DB6F113FULL, 
            0x4A0D6D6CD9B04211ULL, 0x425D82D9A352BF65ULL, 0x0D8C8E5729572DA5ULL, 0x8EBE44A27DEBE870ULL, 
            0x21715A2EA351C733ULL, 0xA26B17318CBF437AULL, 0x36ECE26D085F8557ULL, 0x1DCF8CD5B159E4B1ULL, 
            0xA2D7BBEB3E760C16ULL, 0x8208209B58403DDEULL, 0x620D6C37EA1FB13AULL, 0xEC53D62F173127E7ULL, 
            0x952481FFEF9AE80EULL, 0x7BB4058B2CB7525CULL, 0xA50401CED8977486ULL, 0x762DA54C7F660235ULL
        },
        {
            0xF4B4A7F8B8AF719CULL, 0xFD49F2B422DFAA63ULL, 0xACE543A849F99583ULL, 0xBCB2F3417AF4D88CULL, 
            0xF17EF9E92822A48CULL, 0x533943D40E981586ULL, 0xE0734BE2548E7887ULL, 0x346EFC704005A29AULL, 
            0x05030B8E317C33CEULL, 0xF587BD96BD1428CEULL, 0x7E62F68F49062E7FULL, 0x448AE68DE5BACAA0ULL, 
            0x3CE2F096FA5234DCULL, 0x7B52A4A1129E5725ULL, 0x22B3293EA50F4E7FULL, 0x77892B65291532AFULL, 
            0xCACF439C1AE00A01ULL, 0xF69F8D8F1F85F613ULL, 0x9C763A99E6C7436AULL, 0x43FDE5B7C7FC58A7ULL, 
            0x669CE73C772046E8ULL, 0xB69EAC58475038B9ULL, 0x827D026154A9E55DULL, 0xF98C967A790BBA6BULL, 
            0xBA12AFBCF0FDABF2ULL, 0xF03A59B14B08710EULL, 0xC861A249F66506E1ULL, 0xCEA491A8B6835BA4ULL, 
            0x3575BA76C25053B8ULL, 0x52B6E0D432096A16ULL, 0xC099B54748608174ULL, 0x2D7F9FE5785CC9BCULL
        },
        {
            0xB3940ECF6511BB7FULL, 0xB331EDAF6D825108ULL, 0x6214463A4908831EULL, 0xCA741D191238A416ULL, 
            0x9E1EF9B48EC86485ULL, 0x923AA0B64CA6C312ULL, 0x7D0898E7723EE096ULL, 0x34CB09EE756428CEULL, 
            0x1F1959D2B1D6DF2FULL, 0xC64CB176C7AA7697ULL, 0x13A47D0B2107FF4DULL, 0xCA0C04CCD22B836DULL, 
            0x8AC547DBBB3A5E1CULL, 0x440657C852CF4636ULL, 0xB266705707FA11EFULL, 0xFA30B86F44977BABULL, 
            0x014080628F2FB67BULL, 0x1E6C7EB7C70D380DULL, 0x5066F7073829C5A1ULL, 0xCAE676030D52B9E1ULL, 
            0x9080278111674756ULL, 0x4BAB218CD63901FCULL, 0xAE0C25B50DD176F5ULL, 0x77F3F4507427739BULL, 
            0x3648ABF1218E7D7BULL, 0xE384D058A137000DULL, 0x08517C599CCAA434ULL, 0x078697DB443586FFULL, 
            0x772585CD46D14E5AULL, 0xB21C24D3DEDA812DULL, 0x61800E2A0379B3D4ULL, 0xE0FA2429CA4AAE08ULL
        },
        {
            0x080F8C27202266CDULL, 0x5E96AA7B5B877F63ULL, 0xA19BEDC5A688E45FULL, 0xDBB1A1D8CB70962FULL, 
            0xBD280233F9B48553ULL, 0x5689D7F2AF3C2A52ULL, 0xD075B8E78CF9F66AULL, 0x53240B1E1FF574FAULL, 
            0xEBC38E17A6F2BD67ULL, 0xA1471C572F4A2269ULL, 0x9818780A800EAD71ULL, 0x6CE30A7F32DB9D0DULL, 
            0x5E2C8F456CBA4D09ULL, 0xEFA46316F6CFB744ULL, 0x7F245A4FCC02ECB3ULL, 0xECDE1ADCD50FB576ULL, 
            0x420B84376B0F31AAULL, 0x2DEC0C43A6FB6E48ULL, 0xE562DECFD56916B1ULL, 0x6E457140B15E7815ULL, 
            0xD74AAFF0A75043E8ULL, 0xBF7AF0736E27B564ULL, 0x22864D36B3A1CE0EULL, 0x07F1FA9E31C90DFAULL, 
            0xD2D4D5168A956833ULL, 0x8B437F6D9CC491B5ULL, 0xEC242DBE80CAA9FEULL, 0x64FE9924B72272EEULL, 
            0xB6DBB018F4558345ULL, 0x137E962B69BED708ULL, 0x45EC79838CA1DEB5ULL, 0x6FCFDAB4D4B29B9CULL
        }
    },
    {
        {
            0x19FA62D40A7993C9ULL, 0xB9F3D9C421102AFEULL, 0xCA2BF0724E16A63FULL, 0x04284A9BEBCE942EULL, 
            0xFE9697B7811AB413ULL, 0x9338A12ECC7D28C2ULL, 0xE6C0F8B447972F3BULL, 0xF2597D8CAF565798ULL, 
            0xB6DC32950DE6F74AULL, 0x0B0AF5CB3E9C5535ULL, 0x201F8ED273F8107EULL, 0xB5B95E16AD47F566ULL, 
            0x960C32C4DC433575ULL, 0xC4DA89E01C5BF371ULL, 0x8592F2CA3AEE0EFBULL, 0xEDD8DF823632F4EAULL, 
            0xBAFC02D9B7CB56B5ULL, 0x66FE06057C728EEFULL, 0x1E6EB14038527689ULL, 0xC850C35355B0A148ULL, 
            0x7E76DBF72C1C3740ULL, 0xFE4DB8507D8F3F69ULL, 0x29366C1E3C71FE50ULL, 0xDC5A73BBD2D21E5DULL, 
            0x3F533D07693F46E7ULL, 0xB43B7EC47DB8E1E4ULL, 0x895EDFD05E75BA2CULL, 0x58B9779347DAA327ULL, 
            0x44818D3D360C1D81ULL, 0xA6E773FC66C55B34ULL, 0x3E312CE5E818A9F9ULL, 0x11F8A949FAC8ABCCULL
        },
        {
            0x4D5FB9F36F842F0EULL, 0xC29FC02792FEC386ULL, 0xF5B68E82D92FD350ULL, 0x978BAB1A6A3E1736ULL, 
            0xFC606D34A84F58C8ULL, 0x5FC361F9F298CFB3ULL, 0x5E27446828E0618DULL, 0xAECC51CEA485B12FULL, 
            0x603937DB85C7D573ULL, 0x24F6978066FE415CULL, 0xB9CC14BE7C015B62ULL, 0xCD40CB91B4096C65ULL, 
            0xA33B4B8558F0E20CULL, 0xC2A8F7038174ACDFULL, 0xF74642A5A47EDA99ULL, 0x22E214C3112265A2ULL, 
            0xF85AB8B91B4D2562ULL, 0xE83A229BCBBE01EEULL, 0x5C1E211C63F8E9EDULL, 0xE312210EA4214CD3ULL, 
            0xC9317A65B992B7A5ULL, 0xE57C783DAAA26A5DULL, 0xB3CEC14E8C29E8EFULL, 0x9D570D7EB4F110C0ULL, 
            0x42920CBAC397FA91ULL, 0xE1BB991FE4C661D0ULL, 0x49303E28C100E318ULL, 0x8184A4CF0A244752ULL, 
            0x30BB33F1A3E596D5ULL, 0x5767A7A7E8598148ULL, 0xBD619B992BA1242CULL, 0x4A37D6CFE7F94B58ULL
        },
        {
            0xFBDD7D00BE356DC6ULL, 0x8CCB3914AB8B37A1ULL, 0x47894B6B36483950ULL, 0x12D211635F3A403CULL, 
            0xD210C9F9B4880A37ULL, 0xA1C2D58195914702ULL, 0xEAC7408D953A2ADCULL, 0x7EEA7F756CECB60EULL, 
            0x555456214375FC6AULL, 0x399FC553F0F750BEULL, 0x2410AA7F8AD23F81ULL, 0xD9C8323930F33065ULL, 
            0xCC22900B07933334ULL, 0xA1C7F0B4E6BF6C11ULL, 0x6FC1BB4C404672CEULL, 0x01C7AC6DE8717FEDULL, 
            0x3CC541E5D23D3293ULL, 0xDEAF6058A2B2761FULL, 0x947B6B9113E0A7E6ULL, 0xDE27F83C0C1D3480ULL, 
            0x05714A8EE2A09287ULL, 0x3F18C369E43A57C6ULL, 0x9F4839BD958D3FACULL, 0xE78705F8AD69C5DCULL, 
            0x54D59A2761E35910ULL, 0x9AE7BD1E426AF3CBULL, 0x2AA0F78E378BFCCDULL, 0x010ECB6846CE7953ULL, 
            0xFD50F9915179C749ULL, 0x676234B5DCFBA8EEULL, 0x1D1F9E4BBC8BD4AAULL, 0x6911AC45395F521EULL
        },
        {
            0xAD0E4957F8096AEBULL, 0xC150201B7094BE93ULL, 0x34AA0BBC5B71D449ULL, 0x9A007CD600C05E29ULL, 
            0xD37398B0564E1519ULL, 0xC323F7FA63271116ULL, 0xCE55494E05891371ULL, 0x2E33A4D045EE01EDULL, 
            0xB092E32067CD3EC9ULL, 0x35E5B8876AC9DDEEULL, 0x8E2CA69AA32CBC47ULL, 0x6A755907FBC3D471ULL, 
            0xF2CF7D8A077CB78CULL, 0x6EA88F8928111C04ULL, 0x234EACF2BB9885F2ULL, 0x4E8563C225D5F9C9ULL, 
            0xA9477970A93E4502ULL, 0xB1E7EF6242B96B30ULL, 0xF81B03D9DD55E9CCULL, 0x6A9B7F29641E6F68ULL, 
            0xBA7B529800E94C8EULL, 0x0C44A8B092F87620ULL, 0xEEF8CFD1EB549A01ULL, 0x45BE5DDEB1B1F8E2ULL, 
            0x7851BC67A8A01834ULL, 0x85B378D4D1FE0839ULL, 0xACB1E1056131B38CULL, 0x4C72F95877745A4EULL, 
            0xF33BA7E84E9F0DF9ULL, 0xC1AAFBB441D269A4ULL, 0x5393675566AAA750ULL, 0xAEEF490C01F1AD81ULL
        },
        {
            0x02D8735BCEE66A3BULL, 0xDBE94C4315E8E360ULL, 0x9A58EC34BEFF276EULL, 0x7875A9F92669D0BAULL, 
            0x25100BCFF21386C4ULL, 0x8CCAEC63B325AFDCULL, 0xE0DF1408AA052917ULL, 0x27A509F25F876D95ULL, 
            0x4627B42A4F16D549ULL, 0xFFA58F22D51EBF42ULL, 0xEF8EC6C24789B048ULL, 0xB9C253249B068DCAULL, 
            0xD146973C28B8DF59ULL, 0xE2C9F35C3966820AULL, 0x90550F5B9066920DULL, 0x7A54B0F8DFA81C42ULL, 
            0xA7ABDF4C518B16D5ULL, 0x93F0A26C1308EDD1ULL, 0x3C0986337E8C630BULL, 0xFB535FCA2CDC3493ULL, 
            0x8957BCD4CF7784C5ULL, 0xB38586835A02EA32ULL, 0x870CEE7AF01D3BE6ULL, 0x3B5872F0A69F0131ULL, 
            0xD98CD386410A37FEULL, 0x7029816ECCE0E95EULL, 0x752D58A444E0E74BULL, 0xFC0539CB36DD9460ULL, 
            0xB40AED3D47338A4DULL, 0xA26C0767F1805C10ULL, 0x82DF57004B47706CULL, 0x6B171E1BEA09B85EULL
        },
        {
            0xE58E5601D8D84496ULL, 0x72BCA285FAC5DB83ULL, 0x5C0F71CED8707743ULL, 0x551C9EA27FBF0446ULL, 
            0x21B5F51792C8618DULL, 0x9CB11D39A018BA4EULL, 0x0F19925E48AF62B0ULL, 0x8FDF3106E72BB14BULL, 
            0x6ABE8047186B5C0FULL, 0x602F6B8F54B61E78ULL, 0x0A036D4D856A806CULL, 0x06478323D8AA6413ULL, 
            0x9628CBAF0412DBE6ULL, 0x9A361FB407748652ULL, 0x552BCC23A5C06319ULL, 0xCA72D93CF869953AULL, 
            0x8692B7BC8EFFF0C2ULL, 0xC26FA7E8C877C766ULL, 0xB438FDAED250F399ULL, 0x65C8BEC3D1C69572ULL, 
            0x59789CB3F9094C33ULL, 0xB90D59450224CC13ULL, 0xCC7D38F1112E0B9CULL, 0x9F11CA03167C5CEAULL, 
            0x2298A194760E18B9ULL, 0xAE3277917D72B88AULL, 0xE3EEA031C2914FF4ULL, 0x33471D6BAEEDF5DDULL, 
            0xBD89BA4F56062630ULL, 0xDEE38EC1E1273F09ULL, 0x5DC42C7D407F93BDULL, 0x123124BF5F03A753ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseCConstants = {
    0x27E15600F75CAD57ULL,
    0x811F361ADA5B98F7ULL,
    0xFB7959AD79CE9441ULL,
    0x27E15600F75CAD57ULL,
    0x811F361ADA5B98F7ULL,
    0xFB7959AD79CE9441ULL,
    0xF2065B8AC54A7420ULL,
    0x9061F109E2EC199AULL,
    0x74,
    0x32,
    0x4D,
    0xA8,
    0x48,
    0x0F,
    0xAF,
    0x37
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseDSalts = {
    {
        {
            0x473CC226F2A11747ULL, 0x8EEE428D8B020E1FULL, 0x8203FDFDCBF8A87CULL, 0xEAD112B97281E670ULL, 
            0xC275364404D2D2D7ULL, 0x93CBA13F6F304694ULL, 0xB1920A04D5FD50CFULL, 0xA1373D7D3BE3951BULL, 
            0x825E2C0F17047A0CULL, 0x2B46E936187E6634ULL, 0xB1E2A7A1A227E510ULL, 0x5D7B551B16CF4B10ULL, 
            0x471EAB4D44B738DFULL, 0xD4C855F295F59E82ULL, 0x25D1DFFFF850D645ULL, 0x18E1E3CD6AB1B32AULL, 
            0x2A8F94D959847E47ULL, 0xA7BF8DDBC4CB1C12ULL, 0x18075D8EE987040EULL, 0xCD6582DE4BF4DD14ULL, 
            0x6E55DD7CCBBA7DF8ULL, 0x6E31EE41A88070E9ULL, 0xEBD71678EF8C121BULL, 0x503B751B1BC252BBULL, 
            0x20098447FA1C5600ULL, 0xB3EB52F035E0CFD5ULL, 0x67830216EEBC2DDDULL, 0xD994D0416B5292D7ULL, 
            0xCE6302576DB0D324ULL, 0x75C2D4687CA9D59EULL, 0x47302A5DE7268A53ULL, 0x15AEB402268B40F2ULL
        },
        {
            0xCD5D84965C3769ECULL, 0xC93D719EA2476840ULL, 0xCC24117CCB92A52AULL, 0xD4DBCB4B13A3F295ULL, 
            0xBED7E72061845090ULL, 0x0340E1335685391EULL, 0xFF64B7F4AEF5D83DULL, 0xF4D941EA810522CDULL, 
            0x20E163F92B78BAECULL, 0x7BFEF3080C455099ULL, 0x1FD7DD035A7FFD13ULL, 0xA6B50BA00F9CCA11ULL, 
            0x3821C22B877F99C9ULL, 0xBEBA0FBB294EC16EULL, 0x7C6CD6F9CCFB9F09ULL, 0x3EC4156660A3A973ULL, 
            0xB0B807E70266B0C1ULL, 0xE09B07FD7E4E4558ULL, 0x2CF31CAC5ED214BCULL, 0x2C88F52DF8A426FCULL, 
            0x6227ACD113A95C00ULL, 0xC251C38E650453B7ULL, 0x9C04F9B6A168B45CULL, 0x7B6CB2496FAA4827ULL, 
            0x2DA02829AE7F3DC0ULL, 0x0CEC14C23EC20EB9ULL, 0x1F5967C2797FE966ULL, 0xF3E2ADC334EDD9D0ULL, 
            0xF759208DE99CCFB7ULL, 0xE8623B15079A38D6ULL, 0xBAC37A6F949166B9ULL, 0x342334FA8F99862BULL
        },
        {
            0x0BBBC67DEA793EF8ULL, 0xA04C6E6A69BDF4B5ULL, 0x2FE46CF9BA010584ULL, 0x4B5CEF9BAD4A066FULL, 
            0x6610BDF39CAD7236ULL, 0x6A4C101474CD950FULL, 0x04A0787BA9271ADAULL, 0x416627435CA6065CULL, 
            0x9B589D8623BCCA38ULL, 0x850B6B6D1CD82BC6ULL, 0xE396EFF13C0B5FA1ULL, 0xC89432EC15ABFF60ULL, 
            0x372C0A0CFA641F1EULL, 0xB9B93F8F2B440AF3ULL, 0x10FFDBE4E379F6E0ULL, 0x8D97F346BCC2DFD8ULL, 
            0x768B063EF317F542ULL, 0xDC7A2ED558A1E9B0ULL, 0x76E33E1394B6020FULL, 0x48FB7535B9EC8E6FULL, 
            0x36A906101526C749ULL, 0x15F90891E8C2AD40ULL, 0x57C2551F9CA81996ULL, 0x5ADC1FB7D0207E8EULL, 
            0xB4A984780A35BC61ULL, 0x1638853B190EEB7EULL, 0xBD38B42623214F26ULL, 0x49B07221DB1207C0ULL, 
            0x1C5941E06EAAF921ULL, 0xBEFBA93B70336DB3ULL, 0xC3E03CA127AB44ACULL, 0xF1D1E9FF381E395EULL
        },
        {
            0xBA1C8B2EB28C2890ULL, 0x833AD73C356743C3ULL, 0x3984D68136E83723ULL, 0x4EFBE566DB2B9144ULL, 
            0xB33498EADB0583ECULL, 0x3E07DCF75D77C9F5ULL, 0xC5229BE9775BAC3FULL, 0x0549DC5716526436ULL, 
            0xED91A6FA4E32B6DDULL, 0x4E47E76EDD414BA2ULL, 0x292384BC0C078DC9ULL, 0xF96A8C08A553E269ULL, 
            0xA82EBBCBF3DFFC76ULL, 0xDF48081BEABF16D9ULL, 0xB001538456499C85ULL, 0x0753A701D2FFB283ULL, 
            0x7683FB06DCC1C5DAULL, 0x3AC6AC6A19AEF168ULL, 0xD9EA7808F3F80147ULL, 0x01D8456FC26F9C8CULL, 
            0xC5A8CF54E594202BULL, 0x8F3F80490D7DA95DULL, 0xB47F2B3FEF79F640ULL, 0xBFDA320FF328F192ULL, 
            0xEA7C1098FF436134ULL, 0x31C926E9D164819FULL, 0xAF90F6CE1C66AA90ULL, 0x9A5D43FB8470F566ULL, 
            0x70DD950C133890DAULL, 0x089026106E72383AULL, 0x1F7682DEA8A5259EULL, 0x478EB2F704351239ULL
        },
        {
            0x1752E5648C02D190ULL, 0x6576EDFF29CC9523ULL, 0x5722604FF63B8493ULL, 0xB9B156F704F26766ULL, 
            0xBE4B656E3C2695BFULL, 0x2D79AC933A5A2999ULL, 0xFFCE3A232390BA07ULL, 0xBE73EBE972D78C0AULL, 
            0x0A9327A730ADE94FULL, 0x36C0CCF4EC663180ULL, 0xDE2B2F4561FA8F40ULL, 0x83EB10CC16677825ULL, 
            0x58079D40EA1FDA17ULL, 0xFC5E4578383A5837ULL, 0x11A3FE05874C9B4AULL, 0x6D5073496E5645CFULL, 
            0x5C8E9FA7FFC46D5AULL, 0x431B4B160AACA1E0ULL, 0x20636B5A8ED6944AULL, 0x9BAC3CA4EBB07113ULL, 
            0xE9BDC965B15320BFULL, 0x1BF2402EC67CBF88ULL, 0xCA5D6AB8D1D805A1ULL, 0x55CA6E8233E1B1F4ULL, 
            0x46A4009B58117DD1ULL, 0xDEDFBFDB61B9A5DDULL, 0xF732591339416CF2ULL, 0x8F6735A73EEE5E5FULL, 
            0xF9E396ED08B13091ULL, 0xDECC31A6698AB599ULL, 0xAEDDBC907F287109ULL, 0x6B872FE745D3A967ULL
        },
        {
            0x5A56D08E8CA30CF4ULL, 0x53B1852E51B45DF1ULL, 0xAADC252FF6B91F14ULL, 0xF9600DEF024E9132ULL, 
            0xAC3A8D9B360EE74DULL, 0x15104E413D026A4FULL, 0xF8DB6905ECF238A7ULL, 0xF718B2D8153BB171ULL, 
            0x243D8278F1AC39C2ULL, 0xBFE3D9E518316CA1ULL, 0x89550F30A2024B5AULL, 0xFA06685256B38579ULL, 
            0x45EB75DEDD8E81F1ULL, 0x3539A7B4F4FB3D00ULL, 0xDADE24C2BC98D3CEULL, 0x27F52B3978BBE0A5ULL, 
            0x31DFC9EFC1691DEBULL, 0x57C4AD15F8DFFA49ULL, 0x814B8B624DACF144ULL, 0xBF8A189280AB6C46ULL, 
            0xAD5A8C1F1C15E557ULL, 0x3CE12E597DA2F03FULL, 0xA0953874B85813C6ULL, 0x3A25EEF92B2E0466ULL, 
            0xDDEB15CF8174299FULL, 0xFA840290C9456F5FULL, 0xA6BD1C1F024CC188ULL, 0x562864E554398464ULL, 
            0xB48C01E10CAFA041ULL, 0x89F07B4112D5C5A6ULL, 0x6366B2EF27DD5239ULL, 0x97516D87F18B42E6ULL
        }
    },
    {
        {
            0x560054E86727FE51ULL, 0xE93EF93E8B00524FULL, 0x78F70E6F916AB01EULL, 0x2277B7EEA404A3BCULL, 
            0xECFCAF45A7ED0861ULL, 0x102464B52A39397AULL, 0xA04FA8A204CC1C10ULL, 0x2EC9D9C23D8909CCULL, 
            0x813B131651BEE7CEULL, 0xC4B21976F1EE0FDBULL, 0x607DD92129F77B2DULL, 0xD2383DCC2960E448ULL, 
            0x53AE9409ABC154EFULL, 0x58082E4412574330ULL, 0xE8C08F45C366961CULL, 0x465FEA261C44C1B4ULL, 
            0x46C9B480F1FFF0A9ULL, 0xA31F94317BCA2D85ULL, 0x89302E7157BD6256ULL, 0xCDBE3EB78A306BFBULL, 
            0x484884C51D8F1EEAULL, 0xC6B2FE41EE8E5A21ULL, 0x9E111AACD4DBCBA5ULL, 0x3EB1EE517DC99941ULL, 
            0x607ADCE2373DE6D4ULL, 0x651D2D5E7B021155ULL, 0x197041EE3C568FCBULL, 0xE245A2B7817BCD6EULL, 
            0x6BE2A63619E0437FULL, 0x545164E5003E0495ULL, 0x589EA780460AAFD6ULL, 0x96B27B8A3AC54CB4ULL
        },
        {
            0xE1197D093AA11663ULL, 0xB58D363901AD09A9ULL, 0xD056986D3BE53D78ULL, 0x0DD02AE5F8BA2FBAULL, 
            0xFF554CF13D9A7904ULL, 0xD122B8462202A298ULL, 0x2BE462EE6062BC80ULL, 0xF53B369BD1F134A2ULL, 
            0xBA0963C117586DD0ULL, 0x74AC9D60EAE83E3EULL, 0x820D5E15B56F4B76ULL, 0xB360D24962E59F66ULL, 
            0xF1181116C2FAD29FULL, 0x634DFA2537230D6DULL, 0xA350B840250C925DULL, 0x2B6AC6391664AA61ULL, 
            0x6C39491AD59C8A25ULL, 0x15DCFB82A20569A0ULL, 0x9A2C2B6004D351FDULL, 0x217C16A4D7F2637BULL, 
            0x58CCAF2D8365B732ULL, 0xB9B2045C1723F92DULL, 0x7085F521E48ACD3EULL, 0x9546BDA12F931351ULL, 
            0xF74157868C9963D7ULL, 0x906537E0BA182977ULL, 0x675138262FC1C1FCULL, 0x3ED97429D107F517ULL, 
            0x28C3C4B4AFBC86FAULL, 0x993D68F48B4CC280ULL, 0x00449D7DF2A318FCULL, 0xDB41001AEDFA25C1ULL
        },
        {
            0xAD7D8908431AC8F7ULL, 0x7147184C404E949AULL, 0x7ED70E643A06A37AULL, 0x1BEE7F73EA29D3BEULL, 
            0x7976A3F35F8C4912ULL, 0xAF235C68335CE914ULL, 0x7677A84D3FA45C15ULL, 0xA93A134784D980A9ULL, 
            0x0DD9D1EE13F6FDC3ULL, 0x989D21B56E696B2CULL, 0x845D87EFBEB0F534ULL, 0x6CB6C03B8054A4F7ULL, 
            0x913F9B023247CC39ULL, 0x4CB098C81A4C7BBAULL, 0x8305BEE3642708DBULL, 0xFFFCB24A7090D466ULL, 
            0x7872436481BAA080ULL, 0x2CE958FD15DAC739ULL, 0x5FD5EB7688DA8808ULL, 0x6309CDBD8053B7B9ULL, 
            0x6DDD5228EC5F6CE6ULL, 0xFDB03234EC2C2BCAULL, 0xF4C5DAD7F2411D7BULL, 0xEF6AE51BF24B3A02ULL, 
            0x1265A2F8B3835FD6ULL, 0x2DBFA3BB086E85BCULL, 0xBE2BD1BD04D24C7EULL, 0x3AD47DA05324B9A0ULL, 
            0x2A3E5C1F9462E7A9ULL, 0x381909F1D6A32DFEULL, 0xDAE9BDB210979A5AULL, 0x910734A81C7C1B98ULL
        },
        {
            0x52C2DECA5763B6B6ULL, 0x2D4DD1EED305FE64ULL, 0x7D888101EE05C304ULL, 0x675E6D5543056378ULL, 
            0x22BE2ABC2A3DC99EULL, 0x46B9CB5A52582658ULL, 0x17729DB90F72C443ULL, 0xF6461252D2F34E53ULL, 
            0x747CDCF4B02667C7ULL, 0xEBEE275ABE525E65ULL, 0xF31B7A8C32B8C197ULL, 0xDF6AD726BA69F61DULL, 
            0x2EAF99BCEEA49825ULL, 0xDF60F3945B8D3E25ULL, 0xC7CBE76C77F465C9ULL, 0x78DA8E6A6E097B03ULL, 
            0x49576F35ED207D36ULL, 0x818A67953ACD7B39ULL, 0x044E91F1B0C07714ULL, 0x6A1082DF1DA136D6ULL, 
            0x0CA034EF004C94F0ULL, 0x402F598C3BB3DF5AULL, 0x1BF76DE2223BF09AULL, 0x95845084CF7B996FULL, 
            0x9441467643491A0BULL, 0x483C843E5F2E25C9ULL, 0x2E34F5B0A05599F2ULL, 0xC469CABA50F947F1ULL, 
            0xE7A08BAE199BBA19ULL, 0xED9DF86568BC1B4CULL, 0x16F6A5B77B5E0B33ULL, 0x783F9634C78D8FAFULL
        },
        {
            0xAFF534430D58D5F9ULL, 0x859497A398FFE6C0ULL, 0xFEA6606E290F4650ULL, 0xA214ACECD656E066ULL, 
            0x6D0C629B4A5422B6ULL, 0x330662ACA21FD54CULL, 0xB5CE72F570B331A2ULL, 0xD13FDD958A0BA6A2ULL, 
            0x886B27831647E04EULL, 0x93B65500B19E81B6ULL, 0x0B5F8981BFE8A158ULL, 0x0CCEA0E5735CEF17ULL, 
            0x4CC876000420622DULL, 0xD2C2AF63650B0160ULL, 0xF65F6D90D1341B30ULL, 0x2D55C8D84910DC99ULL, 
            0xA8D26FF29CE1FBFAULL, 0x526244E0CEEB500BULL, 0xB38E4A796469826BULL, 0xEAF2C5740CD9BD54ULL, 
            0xA9399B34185DF13AULL, 0xF9EEA3F888824669ULL, 0xEFEF890A2102E3C8ULL, 0x65180481DF6FFDB7ULL, 
            0xA090187A8AA47EBEULL, 0x5D35B7A856461ED9ULL, 0xCB4EF8B977A41FE1ULL, 0x1F361238FC50708BULL, 
            0xED8B58E7F44D05C5ULL, 0xDACDBD959A25140DULL, 0x61CD04AD12DB4041ULL, 0xDB5B91F23A49F920ULL
        },
        {
            0xAF610ABBC953B517ULL, 0x222EB624F913C356ULL, 0x65283A1B1A30A1E3ULL, 0x05CCDC0B875958C9ULL, 
            0x13281A9916F1E6A1ULL, 0xB4362FB157AA3B4EULL, 0xD5C3483E63635959ULL, 0xB9DEE8A164054C5CULL, 
            0x7BF6690BBEA7A1F4ULL, 0xF5C4710E24AE39D9ULL, 0x6589E99EA54107B8ULL, 0x0439D9BFF03923DEULL, 
            0xCD2E96D994A6F6E9ULL, 0xFE6CEC2411A79FCAULL, 0x69B5BECF607135F9ULL, 0x75C146231E80F008ULL, 
            0xA8E3463537A4E1CCULL, 0x40B789C59E2E0CA5ULL, 0xCAE46EAFB826C4EFULL, 0x3D20610A8AAAFDDFULL, 
            0x028ADE464D96489FULL, 0x84FD4FAE3A299E72ULL, 0x8F5F27140E685508ULL, 0x2FDEA28C119505A1ULL, 
            0x02817CC2291D299EULL, 0x925AE28F3A53CAB2ULL, 0xA54DDD4826B99AD6ULL, 0xA11DBAD729D6AE4BULL, 
            0xEC25295C69B88A76ULL, 0xCBBCFDB13652EA59ULL, 0x4442AF2151EE63DCULL, 0x29AF7CDD6D895390ULL
        }
    },
    {
        {
            0x1DAA3FF742D86ED9ULL, 0x508230057950B9DCULL, 0xA486F819540506CCULL, 0x5F1D7D8E64D6923AULL, 
            0x7387472A4B60E387ULL, 0xEB7BC837C4427471ULL, 0xCD6146849ECFD5CFULL, 0x6699D613763E741FULL, 
            0x0BD87CC5943AE6E8ULL, 0xFEC724232A41BA42ULL, 0x276B6B82A68AAC69ULL, 0x1B2162A1A3878BB6ULL, 
            0x59AB696C68B74C39ULL, 0x3E6BB9A665508E71ULL, 0x59DCBD23D9780F84ULL, 0x5BA4C65D659289F4ULL, 
            0x318EE9BFF4D340D7ULL, 0x7E4E37B85633821EULL, 0xBF3760D9689E7818ULL, 0x3CC90151AF59AA87ULL, 
            0x9AE790D1C60928C8ULL, 0x1F1A6045D2C6A857ULL, 0x83ED72228DB73BA7ULL, 0x2BF2754818F5DF5EULL, 
            0xDE58103CE308ED9EULL, 0xBED0C92C3F1A3857ULL, 0xBE1798098C42E2CFULL, 0x0A95CD8E93234EF5ULL, 
            0xA611EBA931129369ULL, 0xCE026CD88EBDE641ULL, 0x06B7F8385FAD173DULL, 0xFAA6980EE834AB64ULL
        },
        {
            0x6BD7743A1ECD03BAULL, 0xE92BA1037ECD26CFULL, 0x1D8F1C7EEC5B6E4CULL, 0xB11C98651F2AB1C7ULL, 
            0x46550443A968CC9DULL, 0xABD2900203315DAAULL, 0x93E93568385EE6C4ULL, 0x25B0749B70C7EE0DULL, 
            0xECE751BC507A9E5FULL, 0x99E638315011F5A6ULL, 0xFAB48631D0CC077FULL, 0xDDB8A2FC7586E978ULL, 
            0xDDE404B5593BC2CAULL, 0x07BA31B793F7D25AULL, 0xE5D4FCDD4B406266ULL, 0x505526EB9DB421A2ULL, 
            0x6EE181DCB1031543ULL, 0x1CE87DCE7CBBE028ULL, 0xDD11E7F96AA95CA8ULL, 0xCF18E018F77AE8B0ULL, 
            0x66AE2D5358372091ULL, 0xA3C141709D9B083CULL, 0xE55F50ABCA273DECULL, 0xC64BA0DE749F6EB6ULL, 
            0xC535251F288018D7ULL, 0xB4D7DE04DAB1AA96ULL, 0x9AAAB213EF08FC0FULL, 0x3CFFF5DE54206D3BULL, 
            0x88D4037CD8139B17ULL, 0x013B3F7A7E93E2B1ULL, 0xBCB42907FE9540C3ULL, 0xE4CDBC06183D38C8ULL
        },
        {
            0x75E2F33E57C962E5ULL, 0xA6FFBF798DF0ACA0ULL, 0x985C6DAC58F1D326ULL, 0x0CE72885685663AFULL, 
            0xC3528DCEFB68C89DULL, 0xCDA94C2FDC97AF51ULL, 0xF0EE9F8C63489254ULL, 0xE24BBE17E76E87A2ULL, 
            0x73FFBC2862A70C5BULL, 0xB5C3B1C5A1ABE1E1ULL, 0x73D364B41BB2DF68ULL, 0xAC75B0E0296E172CULL, 
            0x192C70F0ED9EA712ULL, 0xA57A6F4D459DB666ULL, 0xE514E7E6D5CC79B7ULL, 0x116712FF9004F5CBULL, 
            0x1B679CE81C2689C1ULL, 0x118420A7AEF3EB3DULL, 0xC2333DF0EF31EE41ULL, 0xB7F8C9A88E5BEB6FULL, 
            0xCB5B57B8C9788F60ULL, 0xB20F7025382C41BCULL, 0x704BA89639F3F1D6ULL, 0x5D53BDD3F38C4AA2ULL, 
            0x1981475020F04CCFULL, 0xC1F0DF0BB3F75FDEULL, 0xC977F8065F57174BULL, 0xAABB0469B7966F17ULL, 
            0x471D2B428487C447ULL, 0x63B6E0B8B6F078F9ULL, 0x96EB1D2EB298B70AULL, 0x7768C9A8BA2A4830ULL
        },
        {
            0x4E964730CC43B847ULL, 0x505FAFC804A3CEB5ULL, 0xAA7CB526A422BB49ULL, 0xC5CB13DDF551F9B7ULL, 
            0x1C527642DFCD400FULL, 0x0D656DDD7369428BULL, 0x2DEE1D14A924A8BBULL, 0xF67EFCE7616AFC5CULL, 
            0x208B277551DE5602ULL, 0x6D95A1D4ED0E0D9BULL, 0x84A6BB3CA73D35B4ULL, 0xC7040B3D9A68C888ULL, 
            0x7BDC2141CC9FD24BULL, 0x68FE335D34D5D507ULL, 0x86F7A406E0D20C11ULL, 0x0424D339F9CBBB07ULL, 
            0xF286142442D2A070ULL, 0x71345440F80C3070ULL, 0x26065B307277A6B6ULL, 0x1FE22E4610929BF8ULL, 
            0x8EAD53175FCEAED8ULL, 0x3ED253B5680AFBEBULL, 0x3A0F181D353D6530ULL, 0x1E4C50B7A0EEA6C8ULL, 
            0xE919A0D6B48A43AEULL, 0xB72D22A934E0BAC2ULL, 0xB5B36E7BD9260242ULL, 0x1C309CF94F2ED701ULL, 
            0x6D2AA3D4C7A4484AULL, 0x258268E6BD9649DCULL, 0xC3BC52F9DE815FC0ULL, 0x21DC5A30B44A64CFULL
        },
        {
            0xBDCE95CC0B41C86CULL, 0xB6EBEB6792355599ULL, 0xCD5AF2D334562A97ULL, 0x812C745BFF630F92ULL, 
            0x1EE24E5FC8CF6B7DULL, 0x3EC00F8E06CBD49DULL, 0x90979F7262D8F51CULL, 0xDEE09E5DC38118C8ULL, 
            0x98B5F4CE8EA16720ULL, 0x3D801F5305939B0CULL, 0xDCF22EBF2BACD4EAULL, 0xFBB8B2BD4F6D31DAULL, 
            0x6F4692E2D2673C6EULL, 0x05746E2BBD5ABF15ULL, 0x2881CF55D1A9FC65ULL, 0x40671D77891DC7EFULL, 
            0x293BC38CF242B886ULL, 0x49E86C92E3581184ULL, 0xC0D4803E97C02B84ULL, 0x0E515F44F986A47BULL, 
            0x5368E2185747592CULL, 0x97644299C4267E42ULL, 0xEE41E06F43AAAE3DULL, 0x5FBCB5D4980BD937ULL, 
            0x887DBEEC3DEA491FULL, 0xAC73F9CB63707325ULL, 0x8A9F8D2F1BB0B103ULL, 0x104A68A1A82D512EULL, 
            0xC26A8CC5AEEC8524ULL, 0xA5770B3E935042E9ULL, 0x24550FBD998B24D9ULL, 0x93964CB4949A8857ULL
        },
        {
            0x1E989C682AAD27B8ULL, 0x978B28F8A94DEDEEULL, 0x5E5138E9744719A6ULL, 0xCC48E9A706CD7697ULL, 
            0x827ED9767A1B4C44ULL, 0xA637EA354602CD6AULL, 0x0228A673B04B64EDULL, 0x25CE1F7DE026E477ULL, 
            0x90382AB41BD0F73BULL, 0xD2446E007C3A4770ULL, 0x030765847C735DF6ULL, 0x6ED3FC7E0797BB12ULL, 
            0x815F4C3F4D76788CULL, 0x6D5E99E89CB19DCBULL, 0x2EFF6396F02FE849ULL, 0x066A98CCBFDB75CEULL, 
            0xCC783E69D8B0F052ULL, 0x571CEA22B2262137ULL, 0x9B58E3EC3C20773CULL, 0xCE284717B915F028ULL, 
            0xD84CA68BF46EBF90ULL, 0x3D84CAD815B00017ULL, 0xD2F9A7B5882C5932ULL, 0xFADACF20C5DDA824ULL, 
            0xBAC131A275023ACCULL, 0x91ADA47AA84E386AULL, 0x05D19D2F5687DA7BULL, 0x7319BC6CF4E9F082ULL, 
            0x72F2020C546D1311ULL, 0x675CD8E623E72B1FULL, 0x1A8E4A81A7EDDACEULL, 0x01E35EDC44821FC7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseDConstants = {
    0xD71F18A328CD3E61ULL,
    0xBEB60B1495B9CDCCULL,
    0x8C4AFF86271BD386ULL,
    0xD71F18A328CD3E61ULL,
    0xBEB60B1495B9CDCCULL,
    0x8C4AFF86271BD386ULL,
    0x3073837B47D2345CULL,
    0xDB49B2311D6AD715ULL,
    0x1F,
    0x7F,
    0xB5,
    0xB4,
    0xB4,
    0x3F,
    0x2B,
    0x9E
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseESalts = {
    {
        {
            0x56AFEEDDBDABB6CFULL, 0xF767A50F4AD724BCULL, 0x2C6F5F9EB20D75AEULL, 0x6BEB371A02695ED9ULL, 
            0x15B90FDA074547A5ULL, 0x6C32F41315182A5CULL, 0x974CE898F5186AA0ULL, 0x6592F57A99BC3733ULL, 
            0xBB9FC868BC969E37ULL, 0x77A7A558561F3803ULL, 0x6A3FF3F5B9D34BE9ULL, 0x6A1C64D0908076ECULL, 
            0xC38E700665F2DD28ULL, 0x83903918A086D6DAULL, 0xB6B4F61BD5AEC801ULL, 0xF3EE802B4DDB6B4CULL, 
            0xFA618C07920AAC0CULL, 0xAE1175474DE80809ULL, 0xC0C5E9F39E3B291BULL, 0x2A9A7925984C7862ULL, 
            0x7CCAF4295518294EULL, 0x8EA93D15AB5B6E39ULL, 0x7B9EC31C024C56AEULL, 0x0CB81F7EEC0599B4ULL, 
            0x8881156306DCE752ULL, 0xAF533DD2909C0054ULL, 0x7CFC51E583620C3CULL, 0x7AFEBA5AD00F81B4ULL, 
            0x8F075BEE113CCB9AULL, 0xFFA24F920E0E9333ULL, 0x071036C8D8A8E925ULL, 0x4C1FAE9E177E79AAULL
        },
        {
            0x6D0D073E6C309E4AULL, 0x0E06BCCAB219471FULL, 0x8F960A87D7152281ULL, 0x6400E3164305198FULL, 
            0x55764E56DF46F4DAULL, 0x4A1DEB399054CCC9ULL, 0x05B73B62EA81802FULL, 0x6BDC7949CC8907A8ULL, 
            0xAC0F7969CC50EA20ULL, 0x4E4EE9DC03ABDC5AULL, 0x87D2334B80BF3E99ULL, 0x3CB234C33AC02962ULL, 
            0xC2A8758FDC329A79ULL, 0x7CFAB639167DB70DULL, 0x9BB7C92114B33BA2ULL, 0x07951388FE8727BAULL, 
            0x7A5CF374C717F485ULL, 0x317AEF672F8A54C6ULL, 0x7C1284CD55095FF1ULL, 0x911681B2F4FC9E32ULL, 
            0xE7103BD46C3FD89FULL, 0x764328ADC71079B7ULL, 0x5708E897F8F31136ULL, 0x01C939B13704FC16ULL, 
            0x30A66477C27F5CB1ULL, 0x04E2EF71F06EA083ULL, 0xEDD2B18654704F87ULL, 0x46736EDAB3874D3BULL, 
            0xA1E3741BA7D88574ULL, 0xC81D8F2E9FE409FEULL, 0xED79AB9CBAF0C510ULL, 0x7A633406785C6169ULL
        },
        {
            0x62D258AA95880C03ULL, 0x781DC6826B00882CULL, 0x4F8FE9CC0A62204BULL, 0x3D354D2A4FEE59F5ULL, 
            0x488EDB07D280E141ULL, 0xA5D3496CD1F7F4D2ULL, 0x45C84537C6345C75ULL, 0x7B78F492EB75A450ULL, 
            0x35E5DA27E5CEA4D7ULL, 0x7BB76FFBDDE64FAFULL, 0x9A76677B59802321ULL, 0xB1EA0FF2D4C5C647ULL, 
            0xEAE8C99EBF8E93FCULL, 0x14EC4FDB7F63E529ULL, 0x9D232AC04778C138ULL, 0xD29E5786C55C3A55ULL, 
            0x26DEA643F8BE4C6CULL, 0xB3E8DD22C5D53AF6ULL, 0x77389D9F53BA61D6ULL, 0xD42F6195E2422677ULL, 
            0x3FD570AC341FF534ULL, 0x3A08006664C5D62EULL, 0xE26393F50DF9C35CULL, 0xC028E663AA7982A2ULL, 
            0xCD9945F06A387D4BULL, 0x392354DD31DFAF8FULL, 0x5BA8ADE4708DAFB8ULL, 0x76535F4DCA7B767FULL, 
            0x410A63063DB3D519ULL, 0x23C9B190AD03D5F5ULL, 0x60286A75E41B037EULL, 0x82BD77D22A864EBDULL
        },
        {
            0x3E4A681D34EC1FA7ULL, 0x3DD32477AD9E4B11ULL, 0xBFB91FE61150B0EBULL, 0x87DF148E57F333B1ULL, 
            0x671C4106E248ED28ULL, 0xD1C2FD65C85CB6E5ULL, 0x9DD5A06E87658881ULL, 0x41CF999FB2B8C27AULL, 
            0xC62DA37D154BFC17ULL, 0xF6E1D37A2D8F0CE9ULL, 0x1455356AF5726E56ULL, 0x91351BB91969E134ULL, 
            0x487ADC4B58B1F55BULL, 0x1D92829EA10B25E0ULL, 0xD531F60B9330E2B2ULL, 0x68ACC0B41C9B3E78ULL, 
            0xB239E54557A8E4B0ULL, 0x607329A7F934C0B9ULL, 0xC33E33D88B124ED4ULL, 0x0AA895AC78DCD485ULL, 
            0x42114DF82BA5773FULL, 0xE4EC6EE5A50F855BULL, 0xBB8534A701B222BFULL, 0x3B4C487D3AC8EEB5ULL, 
            0xAA939FAE78842039ULL, 0x0446DF3AE9C1157AULL, 0xB8E528A5613EC5E7ULL, 0xF3D6BF9F9D9B8838ULL, 
            0x7369B9C6EB0B53D8ULL, 0x4B17C21CFD5F7A17ULL, 0xCFC45A45F8040CBDULL, 0x97B8DD298F404555ULL
        },
        {
            0x4BD01E740BB0E8E7ULL, 0xADF156C423AFC1AAULL, 0x40AFC1DF04A4EC22ULL, 0xFE9812438D6DC35FULL, 
            0x88F14AC38755DFDCULL, 0x7F484584BE15549BULL, 0x587B438AE8CB2D07ULL, 0xD9F01224ACF13ADEULL, 
            0x05E4206F0A508BDEULL, 0x38B2A260B4E09085ULL, 0x3D060FA41CD4A2A5ULL, 0x6B184F5B3955A3E0ULL, 
            0x4C7CC5C33DFC3A74ULL, 0xE7A715B6748CDE05ULL, 0x001478E28F9EAA52ULL, 0xE2BDFFF13735BCABULL, 
            0x24275210AC804FD5ULL, 0xE1194EDDEAB84CEEULL, 0xF943500490CF4BCAULL, 0x5472955A0C3A736BULL, 
            0x738CDFBB855C0F72ULL, 0x2612B5607887657CULL, 0xB73013CC08D21331ULL, 0x0B5B3C2C20216009ULL, 
            0xCE5C565C69598065ULL, 0x7FDBE1AD2C5BB6B1ULL, 0x221BFA3217FB91F1ULL, 0x9C378DA6E438D709ULL, 
            0x988E80960F6D6165ULL, 0x68B5C268BD1165C9ULL, 0xA790EEB815C8014BULL, 0x3CC7BEBE992EF4C9ULL
        },
        {
            0x48205603F17FBD19ULL, 0x0664870F53BF8C32ULL, 0x9F9A6778F29A1A2EULL, 0x7787B96D42DD1786ULL, 
            0xD8183D8585960603ULL, 0x8FFC9B7E8E106486ULL, 0x8A6551C1A853D037ULL, 0x8331CD53150A857DULL, 
            0xB911EBD00C6D30DEULL, 0xB90593AEA8078BFBULL, 0xF7C9165AD83C9155ULL, 0x54CFFEE46AB17847ULL, 
            0xE47A6F35F84AFC9FULL, 0x9B461CB4A082CB67ULL, 0x00575C9C35A7EAA9ULL, 0x6DFAD21CC5494BF0ULL, 
            0x00BEDBBB912776BCULL, 0x8BF130CCA473BBDAULL, 0x624DAF1CF32E9ABAULL, 0xABEC0328F1312CA4ULL, 
            0x7D702B81F993952FULL, 0x9A88365002814840ULL, 0xE439202ECCEEBD89ULL, 0x1F2226361DA8C394ULL, 
            0x352B2B37A33D3854ULL, 0x8C262498D8AE2689ULL, 0xB368F681A8DE87F8ULL, 0x169954A88B604289ULL, 
            0x23FD1664587B6600ULL, 0xBCFA2E8800C716CFULL, 0x07229975903B6C3AULL, 0x108A6190E5E85B1AULL
        }
    },
    {
        {
            0x0D7891DB3292C9FEULL, 0x015B9439DDF7081CULL, 0xA7D35FFA93FE7671ULL, 0xA98883EA404A35C3ULL, 
            0x15DA9A5C94228F34ULL, 0xF0397210B12D814CULL, 0x5B9268282BA97F7AULL, 0xFEBB9D8A3DE8D43CULL, 
            0x30460293474A6C80ULL, 0x86E4A6B116178A58ULL, 0x820680D1F8BFA3FBULL, 0x6507E167E868553FULL, 
            0x068B38062F125049ULL, 0x8A279D835858E0E8ULL, 0xF60BEAD2FFDCE66AULL, 0xC85F169A395FD32FULL, 
            0x9276D6C14759AFD7ULL, 0xB0FCAAF949457468ULL, 0xFEF86E04F01E6C12ULL, 0xC19BDB6726FE6103ULL, 
            0x77610C3277A1E285ULL, 0x43AEBF9E92DA8008ULL, 0x464D6AAB637BB639ULL, 0xE5C9762A9B55A748ULL, 
            0x08FAB3BBCF6D1626ULL, 0x6B21541AD42D43C8ULL, 0x809762D510BB2470ULL, 0x959FCE0C8FB07C1CULL, 
            0x02D1ADC68101F5AFULL, 0xA328BF1405A828E2ULL, 0x8210EC559EE68D28ULL, 0xB1756FE64CD069FBULL
        },
        {
            0x9E17BF3C27A874B4ULL, 0x58D86A763894C5ECULL, 0x9B54050B5640AC19ULL, 0x459EA1B24875FC22ULL, 
            0xFFB3A6C21D45C160ULL, 0x63E3950DB70A61D0ULL, 0x25EE689F0F45C1B2ULL, 0xAD99F7C590930139ULL, 
            0x6006E24AFA3DDD3DULL, 0xD6C5D170F4D1E7B7ULL, 0x074A1C9BC468C7C8ULL, 0x98D19BEE1B16E118ULL, 
            0xAB1D130D5CA30A7DULL, 0x254E7CD35A3ED379ULL, 0xA7F6A6384D320A2FULL, 0x5D732B2042258E42ULL, 
            0x24FB7D3DC439BC03ULL, 0xB725E332170FC98BULL, 0x9CA7B705E8077B23ULL, 0xC28F22AC38E812DCULL, 
            0x405685DDB9B5811CULL, 0x9D09EB8C81556D8EULL, 0x20FB9C6B1A7E2D1FULL, 0xEBA4D47665D74E99ULL, 
            0x29A04B4C8347CBEFULL, 0x956BA6A18C19C253ULL, 0xC455E9366C1E7C8DULL, 0xF2B69FF1D5A21B8EULL, 
            0x9A6237B2961C5622ULL, 0x55136E3ADB43EBC8ULL, 0x541E33F61AFA53FEULL, 0x4CDE3D9A6552933BULL
        },
        {
            0x0B50A0026E7913E8ULL, 0x23A5BFBE11C4140BULL, 0x45F175D0D4F25BB4ULL, 0xF0E3FFB2AB6FA2EAULL, 
            0xB2320BE2E45D3B43ULL, 0xF96FCC2E554F4C46ULL, 0xBFCDC5DC1C75630AULL, 0xF3FA3255719B0043ULL, 
            0x561123FF2C58C698ULL, 0x1200D633ACDD3224ULL, 0x973D32CBDB411EFBULL, 0x501920F9A10E1B0AULL, 
            0x4B5DB8DDD5EEA8BFULL, 0xAF40C976AA0216B8ULL, 0x93A3A04FA61A3252ULL, 0x4A52457338D2A2A1ULL, 
            0x037F01020D968D37ULL, 0xBC5F6D81F40B3C32ULL, 0x3B7C29D23C78A11FULL, 0x38025017FEB222D9ULL, 
            0xB3090A67F00BA54DULL, 0xDB4E9CFCD109E428ULL, 0x3F580660268CBDB3ULL, 0x56420006D5EB4CB8ULL, 
            0x3342253E46BFF6C0ULL, 0x8ECF9E2130E2FE1EULL, 0xB4A033ED233FA1BFULL, 0x33BCEC98FCAACE70ULL, 
            0x138DF6151552A5A3ULL, 0x0D072E336AACC9C9ULL, 0x9A44961085DB5CC6ULL, 0x1F82EBF866C070ABULL
        },
        {
            0x7D8FC4683468934CULL, 0x1C5161B01497F9EEULL, 0xD00B2350668022B9ULL, 0x37C4F1AC75B2F4EBULL, 
            0x3D2029EA21AE8B02ULL, 0xC69D32767579253DULL, 0x2CE98FCB93904281ULL, 0xF1485DFC45331242ULL, 
            0xADF620F48F55E330ULL, 0xEBA6A5C1BCFC050AULL, 0x22A9B758F649897FULL, 0xA2514B55A253F689ULL, 
            0x7BCEEF34DCEB045CULL, 0x569F53CD4A8BC8CBULL, 0xB3B272D526686400ULL, 0x3F02FFAAF0E81FBDULL, 
            0x2AA672DBDAE1A744ULL, 0x5D5BA0A992165CE9ULL, 0x551599802103EB49ULL, 0x55A14830E795BCF5ULL, 
            0x7774EF4F170B5F7BULL, 0x4A02911A96FA26DAULL, 0x7AFC75D2F2023E3AULL, 0x3ECF3B4D67D110FDULL, 
            0x4BF6B86C410134A9ULL, 0x554399A19137EE0DULL, 0xAF7B20DAF58117DDULL, 0xCE426321460CFE5DULL, 
            0xC17A747A491DE4D9ULL, 0xB3377DEA2DBED0FCULL, 0xD946606538938B76ULL, 0xCF920872C61AF8A8ULL
        },
        {
            0x47D33F92FCD50992ULL, 0x977791AE2A66464DULL, 0x5F16466EC8924FC2ULL, 0xA4C92D1AE8152B61ULL, 
            0x483E0F790923CD1BULL, 0xDAF35C59D440860EULL, 0x4623AB5841908A4AULL, 0xBDFD72856F58E58CULL, 
            0x3384213EAD374D1AULL, 0x4710686CC971A687ULL, 0x58BB433651D18906ULL, 0x85ED86F10B75F245ULL, 
            0xE55D2B3864150670ULL, 0x8AD9CE4299877C5FULL, 0xCE02B406B0976D80ULL, 0x09ABFD1899A14B25ULL, 
            0x3308396D135E0ADEULL, 0xAC8E73CC961DC708ULL, 0x287B82A5A35CBBFEULL, 0x6B720F8DAEC1CEB2ULL, 
            0xAE7D28CB0A71BC2BULL, 0x6803B272F32DEE6AULL, 0xB0DC7C8583DEDACFULL, 0x95C20333B7D174FDULL, 
            0x8FA57378DEF29495ULL, 0x93A25A060C627744ULL, 0xAF3E94288268AA93ULL, 0x207655E91F128017ULL, 
            0x6BF265903A5E87F1ULL, 0x6EA9AD721C02DDB1ULL, 0xFDF74EECC89A7754ULL, 0xCF24600E6EEAFABAULL
        },
        {
            0x00AE9383A1102180ULL, 0xC8A1972E9081D262ULL, 0xB715329CFBD64B74ULL, 0x5FF1D866D9CFD74BULL, 
            0x852B4081DF724002ULL, 0xE4094A836B2E5F6AULL, 0xEB53E8091F094AD7ULL, 0x6DCB96C2B007265BULL, 
            0x9345CF56FD3105EFULL, 0x7A085754C34E96B0ULL, 0xA64F842B3C291ECCULL, 0x4FB520B47A566052ULL, 
            0x817AF0C7C8290F88ULL, 0x11D44828FEAD9DFDULL, 0x930D60B918EC6E94ULL, 0x4F07064E697872E1ULL, 
            0xE25FE44C76006FAEULL, 0x85EAC48764AE3CC0ULL, 0xA102B61E0F319187ULL, 0x4318760A78516F2FULL, 
            0x988B65276E066DE7ULL, 0xCB31E8C199CB3996ULL, 0x22A5C8E925CD7054ULL, 0xD2C92447EA4CEF9EULL, 
            0x97C923B10A6F7FD2ULL, 0xE20D467AAB8B2F7CULL, 0x0AA4EC9F7714B7B7ULL, 0x7ED5B960693EAEF3ULL, 
            0x1C27A5C4A010556CULL, 0x89B85FDB71BCCDCDULL, 0x22B32E2772B7AE10ULL, 0xE6A62A6BBE0BC134ULL
        }
    },
    {
        {
            0xC86C69F30718EA8FULL, 0x83477F9AFBB984FBULL, 0x0F43C5301BAB6EB4ULL, 0x595FE71BC15E46C2ULL, 
            0xFF5F0A3915604D87ULL, 0xA0ABF2CA2E7B2F4BULL, 0xC562FED85299ADE1ULL, 0xF2DB1E81999CA239ULL, 
            0xEC9D39D84B8DC66EULL, 0xD2F3F13DB7F3DF95ULL, 0x806FD20853963D64ULL, 0x3B9CB693E5A7BE7BULL, 
            0xE32C4E850599A7A0ULL, 0xDD89948E42843DA8ULL, 0x4EC7A8DA3CF90C28ULL, 0xAE179B3B1CE7305EULL, 
            0x4849430CB96C9257ULL, 0x62459657878F01C4ULL, 0x9AA6B3CD3DE26001ULL, 0xF45D56C90926AE46ULL, 
            0x94C8FB764F9A3909ULL, 0xFC3BD7F8B5C13B2FULL, 0xABBAD484ED9061EAULL, 0x0BAD6BAD9F7B6F9AULL, 
            0x25CDE10F5030A5CBULL, 0x10DD9D87E41B102EULL, 0xAE7D7B57ED029494ULL, 0x7A8078E97D0B6C2EULL, 
            0x485BB059A12DEB97ULL, 0xCF6FEBCB4615C21FULL, 0x21153170262B2B16ULL, 0xDA39B6DFA7BB6258ULL
        },
        {
            0x71E3F009DD18700BULL, 0x279CC116938AE0B1ULL, 0x092B2E7C22A4C622ULL, 0x30F25BD467A13532ULL, 
            0xDC476B7B62317A8AULL, 0xB2681941419F9A36ULL, 0x45D64873EDF98F86ULL, 0xFEE41D2AACBD0C6CULL, 
            0xFB2163A09FA0A959ULL, 0x6D8B97897F57CDEBULL, 0x003FB7FF96DBB83BULL, 0x74C1DDE455CF4245ULL, 
            0xD12840CE4FAE42B3ULL, 0xF35C40D17BD8666DULL, 0x3E3F44BC26F2E54CULL, 0x0F5E9A6D26FD40CFULL, 
            0xD0D5C696F111E3F1ULL, 0xAFEBEC7E6C7968C5ULL, 0x185A918DE089AFFCULL, 0x4C3019E70B66AA6EULL, 
            0x42BF8F33E5204B5DULL, 0x647725A49664FD00ULL, 0x47EF877F9E35B6B4ULL, 0x54D998C722B00555ULL, 
            0x77883463C644D027ULL, 0xCBBC4BA3CF36A261ULL, 0xDEE72FC3425AA692ULL, 0x33180A99A4939B7DULL, 
            0x57752B6C149BFBA4ULL, 0x8D52E40552D33527ULL, 0xEADAEA658532DFD6ULL, 0x4273E6CC12FCED80ULL
        },
        {
            0xC0BB542F54561E57ULL, 0x6F932222EC58925EULL, 0x43AA89B5ABA35B32ULL, 0x4F4D5ADC49B4AC29ULL, 
            0x431A5AE0B984EAFDULL, 0xDC89C0A28E0DD7F9ULL, 0xDEB6C807B1D66EFDULL, 0x0327007E8DBC3831ULL, 
            0x5678C719B61728CEULL, 0x7D35F3E167875D24ULL, 0x7AC8A219A4FC51CAULL, 0xEFA2FE1E87520F1FULL, 
            0x225F76435F28CDD2ULL, 0xD4B8609F24F0DF19ULL, 0xD58682141068CDC8ULL, 0x601E18FA230E4BF2ULL, 
            0x1F11756EADB77344ULL, 0x12FB7FD09AB6BED3ULL, 0x8D65C37D40706F36ULL, 0xA21020ECB7C94122ULL, 
            0xE700BAC0936EF3DEULL, 0xA369C0F3770AC311ULL, 0xBC4A6B545D2754FAULL, 0xCE005780B8FEB438ULL, 
            0x549529CDF98C5D4EULL, 0x93D7D68C12817D81ULL, 0x1CC81824A1FF2AF0ULL, 0xCE9E8406D32424E1ULL, 
            0x23FCEA3AE4F46327ULL, 0xF6B9844ECB46AAC5ULL, 0x00412F405528D175ULL, 0x26BFB8EC09F096EEULL
        },
        {
            0x54EE2840424A5C26ULL, 0xEBDF9408CC61F611ULL, 0xE352AD7E36FB1DCAULL, 0x34C9F5587E24CE9CULL, 
            0x5D0724E76FE77F65ULL, 0x1340487C7747004BULL, 0xF959286CD7B1D3FBULL, 0xEFC0EB37360EA28AULL, 
            0xDF293AA3F392BEE8ULL, 0x7D737AEF3AC0FE91ULL, 0xF0EA608C9FA8C18EULL, 0x09A6CC66F72DFBE9ULL, 
            0xE2FA58351A01DE96ULL, 0xFE2004C6A272DD30ULL, 0x984609E881918FE2ULL, 0xAB3242CA929FE956ULL, 
            0x394F292AF0BB4219ULL, 0xA9E7F16D3EBDEC43ULL, 0xF2602F470FA8B974ULL, 0x856D5C77D382FD47ULL, 
            0x8CFD71C52A2C9021ULL, 0xC12F28A2910B3FCEULL, 0x25ED335FDB8ADA31ULL, 0x7C46A02E9A6BCDADULL, 
            0x7A34BED0B5794C71ULL, 0xAD5C6101AB13FA6DULL, 0x1FD849CDA1A572E8ULL, 0x3B365C8CB48F3230ULL, 
            0x122E7E63FCC809E0ULL, 0x6EB4DF2EA4CCE2E5ULL, 0x33CB9C71BCC6995CULL, 0x1AF45B44987BF843ULL
        },
        {
            0x15BBEA88F855CE58ULL, 0xF935311E321B3D48ULL, 0x24344F2CDF833D4DULL, 0xD3CD2270D0B7EEA7ULL, 
            0xFC271A9A0DB2EB6DULL, 0x726213DE254CF2DFULL, 0x6278279701CFF392ULL, 0x1B6C6F9D208697CEULL, 
            0x7D23C08F6ABC5E30ULL, 0x3C2DC87F4FB4F0DFULL, 0xBD50B41497AD1EE0ULL, 0xC5B77B1380A2E182ULL, 
            0x77E5C85F02BD1DDBULL, 0x66F461CE962415FBULL, 0xFA00AAE2E27D787EULL, 0xC04A3F653717048BULL, 
            0xC9FDAC5D19886588ULL, 0xDC5B5D83C7412D60ULL, 0x9FD6573F29779D7FULL, 0xBADFB46F1AD64AB5ULL, 
            0xDED1098180762D88ULL, 0x632C31411B3C5A9BULL, 0x97585D378AA3183BULL, 0x3A82E0B953D17AC7ULL, 
            0x8EAD016D23C56E78ULL, 0x794AC3CD318BE8CEULL, 0x8DBFD0D9B9AA4DB0ULL, 0xFA5FE5639AE42965ULL, 
            0xB8A01C183B0ABAB1ULL, 0x7CC8E2E059B46A8EULL, 0xE66DE6A58EFFF9EBULL, 0x2F435B0D4F20D051ULL
        },
        {
            0x261D9DBCE2458CE2ULL, 0x29EF696DECCCAA66ULL, 0x6A0DD40E4BB19B56ULL, 0x6B8D517DB9C1D9ABULL, 
            0x0EB81CD1AC8E574FULL, 0x26471E053359BEC8ULL, 0x64A74DA61F4E9074ULL, 0x4A78E849D75E1914ULL, 
            0x8DC9986DE5DC3121ULL, 0x55F6DC7ADF104742ULL, 0x78CDA363B67BB33AULL, 0xB46DB872A6152A9BULL, 
            0x8145602AAEC6140AULL, 0xEEF56C29A7CB812FULL, 0x205129E3E90FCD5AULL, 0x5A888A2F852F7A99ULL, 
            0x729F4C69ACCB7D9FULL, 0x4AD905B269D52ADEULL, 0xC3CEB4C69CD36481ULL, 0x57EE7FFC928ED85EULL, 
            0xEB8287E43409B4FDULL, 0x72126AA774FD7140ULL, 0x09CCB8CA2C4659FBULL, 0x1265D98204BFDA79ULL, 
            0xE02EC906EE69B6FAULL, 0xF014F94F1EF43FEAULL, 0xBDFBB6312F75F2D4ULL, 0x9F6B597EAC03E0DEULL, 
            0x6A21893A6C5A4502ULL, 0xB6EBEE7C16142F8FULL, 0xC25B978BE6029E23ULL, 0x92F7270BEB663C5CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseEConstants = {
    0xFE1922F6B16FEB77ULL,
    0x4B361F3A2E0B78E5ULL,
    0xDFDE261C6739D644ULL,
    0xFE1922F6B16FEB77ULL,
    0x4B361F3A2E0B78E5ULL,
    0xDFDE261C6739D644ULL,
    0x4D568057132760B7ULL,
    0x727E5664F47ECC15ULL,
    0x7D,
    0x6C,
    0x15,
    0xBF,
    0x60,
    0xDB,
    0x41,
    0xEC
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseFSalts = {
    {
        {
            0xF120A377BE4713E7ULL, 0x333FD710EB74814EULL, 0xE41A29C9283B881AULL, 0xD0EA473F4AE75992ULL, 
            0xC3C7D5CA338430F5ULL, 0x851EF09B634EB7C5ULL, 0xF5DD317CAD2406A9ULL, 0xCE1675FA182DEB4BULL, 
            0x9C5D10CA156FF95AULL, 0x75F0B024198B2975ULL, 0xE4210372A8BE2014ULL, 0x219E4AD751A3EB51ULL, 
            0x5FC2FFB6A331470BULL, 0x8D549173D43E09D7ULL, 0xEAC161ABCE776E3FULL, 0xB5C19DA72A3F1C7EULL, 
            0x1837CDB0E8958D52ULL, 0xDB5271186C5E15F5ULL, 0x94E646162B7BDD90ULL, 0x2568CD1E7BF15340ULL, 
            0x96198806141753A4ULL, 0x6D9DFD0D98909E61ULL, 0x9017D4CE5C86C9BCULL, 0xCFADFAFB6CF5AC57ULL, 
            0x2946E5EB165ED41AULL, 0xEE5E2EEF86CD7D89ULL, 0xDF022925BEF5BA2BULL, 0x46C6B0E41252630FULL, 
            0xDBC719317B98754DULL, 0xA5CFC90B281C38B7ULL, 0xFDC45C338A7BD18CULL, 0x0E534F58723CEC60ULL
        },
        {
            0x5693725F45B8F474ULL, 0x3D624A988AF73E7AULL, 0xE09F9AF6DB2408D1ULL, 0x4EB7E313D5E26929ULL, 
            0xF4E75BA1D144F744ULL, 0x73714A3A5AF5382AULL, 0x51E1D0048822E060ULL, 0x3B07BD43FDA4BDBAULL, 
            0x8AC82C70C7CEACF5ULL, 0xAF55F5685415E97CULL, 0x566DDA6B3BA2506CULL, 0x0356D69A4B508CA5ULL, 
            0xC82B9453BCCD8E45ULL, 0xB4E102BE305B4DBEULL, 0xA460E27CA1ADD7BBULL, 0xB435282299C81DA1ULL, 
            0x6BFBEC9801A0602BULL, 0xF54F4090B0022805ULL, 0xF1E5F922B5E01C31ULL, 0x66AA59A6148F8325ULL, 
            0xC5F09F9C28EC566FULL, 0x963687B42DB88E45ULL, 0xC1087E7501046C5FULL, 0x2C2B8FF14C2619C0ULL, 
            0x1D619635E594970CULL, 0x28CAA6BD5DBE611DULL, 0x2A15C72694A7C39BULL, 0x7E9AC3AC30854D8DULL, 
            0x658972DB940522DBULL, 0xDECA8D0D69F4A16CULL, 0xA259E31FA4035A62ULL, 0x6200F7A9F781ACC3ULL
        },
        {
            0x20A805FADA7CD8D8ULL, 0x2C773C908DEED83DULL, 0x3CAE022DCF8BEDD6ULL, 0xA00AC14DDAD401A6ULL, 
            0x48B282D55BA63F69ULL, 0x6F19C9E624EFC21EULL, 0x6D4A95989AC7A09BULL, 0xCB41568BDC960C6FULL, 
            0xE87A821FC03374ECULL, 0x9C328CC05ACCFE65ULL, 0x57FC096EBC9667CBULL, 0xD6324528D95CDE2FULL, 
            0xB0E5FA4EC28AF8C5ULL, 0xD1199B944263B7F3ULL, 0x76D03B9D4A306F28ULL, 0xC25DD0FFEDEC0148ULL, 
            0xDB3BE03E279C0BA8ULL, 0x487BAC085C3A02C3ULL, 0xC27A12A52C1D50B6ULL, 0xCDD2989FA598B112ULL, 
            0xDA20D0159F5700ECULL, 0x431C3AD5A3EE2B0CULL, 0x22472E92143D4BD9ULL, 0x5CE9C2366867F25BULL, 
            0x14CD1816822A6940ULL, 0x9DAC74C61BF8D3D1ULL, 0xDBC784FBC3900438ULL, 0x3CC8072E5A2BEA18ULL, 
            0x029930BE5E04F6C9ULL, 0x0165C4931C7BEF32ULL, 0x2E79BD6BFC14F8FCULL, 0x76AECB22D9F6E38EULL
        },
        {
            0xC06DDFC38D11D4A8ULL, 0xC69497CCA19521EBULL, 0x0390A9EBB37E46BCULL, 0x5E9F91594919C2D6ULL, 
            0x01E41EC140888C71ULL, 0xB1A81E118AB89740ULL, 0x906959D720F76709ULL, 0x2A22C7DFE4976171ULL, 
            0xC15E5352E66B4B67ULL, 0xDA28FC38D72550BFULL, 0x99C9267E4802F910ULL, 0x11FEC516F850F4F1ULL, 
            0x8E6C1E7926D76987ULL, 0x99AA29331697FC03ULL, 0xD5395D9C84D9CF1DULL, 0x96E04A6CA4561EB0ULL, 
            0xA208A425888896C9ULL, 0x8CB9777745FC8481ULL, 0xE8E0170932A47A20ULL, 0xCA4FB9416586A178ULL, 
            0x3D279D009EC026D9ULL, 0xBE7B411D9496B513ULL, 0x26390238AF57D74CULL, 0xBB2521F097283FF6ULL, 
            0x3F4400EDD61CC10AULL, 0x1CD6A9475A3E9879ULL, 0xE874F26EA2AF5D8CULL, 0xCC2BCD6190E5A7BFULL, 
            0x209C365C22BA1096ULL, 0x54E08A6C1DAB608CULL, 0x0C697AD769A5A37CULL, 0xCBC7203544B85EC7ULL
        },
        {
            0xAFBE9D9200C8CAC6ULL, 0x317FE650CD3CA45DULL, 0x1B5862ACC788FD51ULL, 0x153A9B0F26B7C062ULL, 
            0x3DEE96190548C4BBULL, 0x590087254A949973ULL, 0xED1165718B6DC46AULL, 0x64C5570BE95B708AULL, 
            0x6AC4B58B91F29066ULL, 0x206AE0331E528C26ULL, 0x32746D6A9B7B7958ULL, 0xBE393BBCD28FE613ULL, 
            0x4F9911BB827BB5ADULL, 0xBC7CCE956A399F95ULL, 0xE6872C98CB624137ULL, 0x4A139F8033636294ULL, 
            0xA336000E661FEF90ULL, 0x4E95EE54E7D87A13ULL, 0x9666751697EEDE74ULL, 0xEE888A0960D09E5EULL, 
            0xB5E893A1467163AAULL, 0x654D7DE73C5A837BULL, 0x0916A718432EAAC5ULL, 0xF2C4A60162CCEC9CULL, 
            0x6161B505EDC1A956ULL, 0x8172518006C9FFAAULL, 0x24EF1D5E3B810877ULL, 0x97C40F882C52011CULL, 
            0xCB8A8933B2CFB1F2ULL, 0x62A290EB65683B3FULL, 0x91B9141854428D7EULL, 0x9E3FA26EF92ED518ULL
        },
        {
            0xFB939835F6F0DF1AULL, 0x7D78AA178A8F8388ULL, 0xD8CC3879869839F1ULL, 0x601CCE4ACED541D5ULL, 
            0x955089A11C18DC94ULL, 0x31422C368C44D95AULL, 0x4EFA427858429697ULL, 0xA1865D6F06D91912ULL, 
            0x676773A1092486BCULL, 0x0C5A98BE746B5612ULL, 0x22CCEBF3C73DFCE7ULL, 0xA70DD3948E9AA1CCULL, 
            0x0638871D6DE5234BULL, 0x765C2265F87140E6ULL, 0xC9C491FB2C3D27F1ULL, 0x6EB3757A5ACF2C0FULL, 
            0x2ECB0D0EC93F6F6AULL, 0xC95D840BE06BE16FULL, 0x91D61465C63A113FULL, 0x3CA1ACE3AB80160EULL, 
            0xB6B11A7D77FAF29FULL, 0x605A38E5E876CA42ULL, 0x7ECD4642B0859705ULL, 0x8FDF570BC921AB86ULL, 
            0xC6F04E783DDE2100ULL, 0x467685ECBB955999ULL, 0xE97ED95230BF5F7CULL, 0xCCCA6538367DC47AULL, 
            0x38B509BBBE3A2903ULL, 0xF948FB5A6605A4F5ULL, 0xE6C6928B04299EB9ULL, 0xDC6437170C9E6473ULL
        }
    },
    {
        {
            0x3F28AE754B5EBEB7ULL, 0xF4DD7FCEC84B9A8EULL, 0x8E1ADFC68AAFB3C8ULL, 0x909C35C5F15FFEC0ULL, 
            0xEA227FEC789A6EA5ULL, 0x0713095D9DCEBAD3ULL, 0xC8A0822718E36F72ULL, 0x0D3E518BB39A90E7ULL, 
            0x893C68D5C315D589ULL, 0x8A30A8A419D70A43ULL, 0x88F3EEB26A01B489ULL, 0x162361C1CE3DEABCULL, 
            0x5A0836325F0EE9AEULL, 0x18276F2EE606B87BULL, 0xDB0777E308C83217ULL, 0xA9D843EDCFB49887ULL, 
            0x21FCDD3239C0D540ULL, 0x1257A42CCACB1884ULL, 0xA5CDCE3692397877ULL, 0x9ADBD6F2695B2152ULL, 
            0x3DCD1EABFC09AECCULL, 0xE56FB028AF8F66CCULL, 0x578041EE628256B3ULL, 0x81AC40314FEFE5A8ULL, 
            0x7CD8857F5F69CB32ULL, 0xEE08E4F6E0ADFE95ULL, 0x14DC81EFD0C82A87ULL, 0x318E117B7B0D37ACULL, 
            0x3FFBCC7BF96088F5ULL, 0x56861A299BC66160ULL, 0xA7FDD4EC0D44563CULL, 0xB6759539C4D89B55ULL
        },
        {
            0x8ADDA0A91D57BB72ULL, 0x23DF286A9FA53879ULL, 0x64CB9A5DF11B524BULL, 0xE12F242BAEE401EFULL, 
            0x5231517022FE0136ULL, 0x48FB1651906F710CULL, 0x884EBEDBDED0E085ULL, 0xF67A5B33FD5E1823ULL, 
            0xEF41E4F0192B4785ULL, 0x278D1355F04DC902ULL, 0x77CE6B8F780285BEULL, 0x97E2FD186F9591DCULL, 
            0x789B1593095510F4ULL, 0x67855615D1D2FB35ULL, 0x0B1C0F41573CCD61ULL, 0x0407BCC2E8319A1BULL, 
            0x23D01A577179F6EDULL, 0x439179B2FAED09EFULL, 0x3A01FFB6EEA98F7CULL, 0x4585572BEA7A7CDEULL, 
            0xAD24FBE455E7577BULL, 0x6E1A2F2D0FC79793ULL, 0xBEFA60E52884A9A5ULL, 0x5D929C628ECE20D9ULL, 
            0xAC3B6FFA3F23B3F1ULL, 0x56FAC80A0561E356ULL, 0xAF6D7E712F1AB703ULL, 0x1978272924A12AE6ULL, 
            0x1ECED42533AA31F3ULL, 0x9545BDB27198B41FULL, 0x8684037E3577AD37ULL, 0x8442FAD8C735A471ULL
        },
        {
            0xC543F4E8D675D48CULL, 0xEDC6EAD0D7BAEC1EULL, 0x8145BA5CAEE12AC2ULL, 0x5697A325D257B7EDULL, 
            0x3A0B1C2ABDFE1AB9ULL, 0xD67AF7E085F0D15AULL, 0x2F8EFE640DFBD7D5ULL, 0x4CB9189CBC6AF6A8ULL, 
            0xC2C92D792A605378ULL, 0xF45B9772AC41BBAEULL, 0xA0315A85CB7DEE6FULL, 0x95592ABF650B2CE2ULL, 
            0x9E966E35E14E6293ULL, 0x60C980DC290B57ECULL, 0x95BB3CF033CBA5F5ULL, 0x3778104A17DE79C3ULL, 
            0x746A22269AB0170AULL, 0x2EC3EFCB974E024BULL, 0x1E18C49EC5B7879FULL, 0x04D32ECBEECEC64FULL, 
            0x86C856C8E8795C55ULL, 0xF3B4F343E3DE6D49ULL, 0x08471CDC86FA1355ULL, 0x6C32471069C06EF8ULL, 
            0x88456096710FE8B6ULL, 0x0477ABEC6324A37AULL, 0x3F39347196FE65D4ULL, 0x890CB2DFA70A3FAEULL, 
            0x3A2FD8D1A7120CB2ULL, 0x3A8D9FCA45523972ULL, 0x1C1EF0E8F60DCF19ULL, 0xCFEDBDC0A5A92D63ULL
        },
        {
            0xA479FFC223177F27ULL, 0xEFE17FC718270984ULL, 0x24868D1C2DEE6416ULL, 0xEF15D6618D7AD3B9ULL, 
            0xFBA2DED20E54A61DULL, 0x2B663417F8BE6E19ULL, 0x49DA0F3E5EAEDDE1ULL, 0xF9F2CAA21E1DEF50ULL, 
            0x940B724EAFA88F2CULL, 0x1B595974FFAD79C1ULL, 0xFC6770DE4119AE80ULL, 0x08330BECE8D96E02ULL, 
            0x7E02108EB4185E81ULL, 0xC1C04DD3D0244C7FULL, 0x316E8B03DFC58133ULL, 0x04E2C3940DF13C4AULL, 
            0xEC8A6349C67B6AC0ULL, 0xE9FE371108A0B201ULL, 0x6029B6EA1C9A44D7ULL, 0x13708608E6F241D1ULL, 
            0x552CAF9167550274ULL, 0x00EEBF71A1A057BEULL, 0xF19484CED54273DAULL, 0x898C2727C522CA66ULL, 
            0xA28154FEF568775BULL, 0xA885689B2C8A064FULL, 0x82B1C5986C1F3582ULL, 0xBC68DE1D8E5D9255ULL, 
            0x991224A0B9093960ULL, 0x52713DBED64CE181ULL, 0x981BE3CFF1E0D330ULL, 0xB07329C9A4CE98CAULL
        },
        {
            0x48FC97D615A09B04ULL, 0xC6A6A38051C4CF4DULL, 0xC8A88B72F7CFBDBFULL, 0x20590EC3E37438F1ULL, 
            0xEA6DAC737738DE57ULL, 0xBDD196A2F3FCEF44ULL, 0xA0AD756178AA6F6AULL, 0x980DB857035E172CULL, 
            0x09515FA9377E3835ULL, 0x59E66CF90A05F1EFULL, 0x8F12C5A7B407E3C4ULL, 0xDC3DBE33EB99EECBULL, 
            0xAE6A5397DA3FB825ULL, 0xEDEDEB0A759C2732ULL, 0xA01FD5F93EBA96A1ULL, 0x5256603094D1F7F9ULL, 
            0x9662F2EA90C1AD25ULL, 0xC101C2C183DF65CCULL, 0xED0B013878B01D82ULL, 0xE54177C2973FE04CULL, 
            0x2E2BFF57BB2E9990ULL, 0xF2B85BE0935B36DFULL, 0x051ACC4B7BFA56F3ULL, 0x758BD1B513639916ULL, 
            0xF817B0FCA9C8B47AULL, 0xD0160AA05AAD48D7ULL, 0xB837F3E4042B7384ULL, 0xA7E69D8B3CD074F2ULL, 
            0x986DCD9F80D94570ULL, 0x1D6DE834E1C0B9ABULL, 0xD5C7EF4C53FA370BULL, 0x3457F39F993DAD3CULL
        },
        {
            0x14ADC49CC70DFB1CULL, 0xE1A5EF97610493C8ULL, 0x3BF083113F49B527ULL, 0xC13635DD3705D8FCULL, 
            0x0EF4C770F17F2FFAULL, 0xC99377ADF0FEA307ULL, 0xEDB33A6C01F70240ULL, 0x3E99CA56D8100DCCULL, 
            0x40A257B7E49845B0ULL, 0x7C3BEC27F1435947ULL, 0x4435A2D829C962E3ULL, 0x259C5C410B8E9EDAULL, 
            0x85BC7035CDADEFF6ULL, 0xD649149597416C10ULL, 0xD389A22D7B4DE4C0ULL, 0x8028BFF18EEF4973ULL, 
            0xCDEE7227AD4B5E23ULL, 0x26C1BE1FC2073F78ULL, 0x05037518B7492E36ULL, 0xB694CE5A0858952FULL, 
            0x13E4B2D45C0D8513ULL, 0x4DAFE57F9102490AULL, 0x785EE4630472899EULL, 0x29768A9AEE7C824BULL, 
            0xF0FC69C5175DFB10ULL, 0x8126BD4CE5D8B8AAULL, 0xDF28BA50DE47D028ULL, 0x0070254285A62E0DULL, 
            0x487DA3C7337D6710ULL, 0x602ACA974704D602ULL, 0x967483C3260A9786ULL, 0x230B3C77134FA99EULL
        }
    },
    {
        {
            0x2200990D6B6363E2ULL, 0x4EB3F21659CD3C0EULL, 0xD17F17A9CECEB1D6ULL, 0x8B69D47EF2FD9615ULL, 
            0x7AD5BCCBB3EC824DULL, 0x050C8E51A1EB8238ULL, 0xE5413F5A89B2ED91ULL, 0x87B5626BD434DCEDULL, 
            0x183890ADD997797FULL, 0x2D24D6457A2A2BF5ULL, 0x8AE5D3E319483391ULL, 0x45298E9CB3892B2CULL, 
            0x16F92E706D47F4E8ULL, 0x7B3B00144A1E5BEAULL, 0x7B610E80CC6B0308ULL, 0x2C761D100A3B2394ULL, 
            0xF731C5B057B2C1B2ULL, 0x54A7753B5B248BEFULL, 0xACB136FEC82CA26DULL, 0x57C45A9274AA983BULL, 
            0x785D40F673F326E1ULL, 0x3A69A0082CBF3DE4ULL, 0x444E69EEC6ECD445ULL, 0xBC847EE2507ED6B8ULL, 
            0xAF3AE056C2FA1B5EULL, 0x73C69C7AC1EE3895ULL, 0x074ABD2B10A818FCULL, 0xBB719833CBC96C7AULL, 
            0xF31650F699513010ULL, 0xEB24B1C5CB7D5AA9ULL, 0x07663B656B4F732CULL, 0x234F6E2866F22E0DULL
        },
        {
            0x34196D61E3CDB6CBULL, 0x013EA32A14F3EDA5ULL, 0x391BFC3B2DEE8813ULL, 0xA53742CF67D14C79ULL, 
            0xD3445E4D43C80EAFULL, 0xADBE7CEBF4B75CBCULL, 0xD5F21734F584813EULL, 0x85ED419C7D5D7045ULL, 
            0xC7B3D52DF012A868ULL, 0xB3672D26F3439AADULL, 0x9AA35B765B947959ULL, 0xD0E48D46F71DFDD9ULL, 
            0xBB33E91902C9856BULL, 0x2C834A099B7971F8ULL, 0xFB2BC0AE08C2C34EULL, 0x288032E63887A5A6ULL, 
            0x7342A1AA7B99065DULL, 0x3CFAF189D1DFDC1BULL, 0xFAFFCE563C5E850DULL, 0xEF1408B685C88ECDULL, 
            0x57BC7208F29BA16EULL, 0x3D98D723599EB1C3ULL, 0x93F42E06CD19357FULL, 0xBEA34B77CADBBEADULL, 
            0xC5E74CF0C467C43AULL, 0x0DD992937B48059EULL, 0xD9156BBE12677527ULL, 0x8CEDC15AA4EA58EFULL, 
            0x49B26FAED6EF394EULL, 0x22E7977E8802E31BULL, 0xADB70217EAE5C67DULL, 0xBB28CBECAEFA2E22ULL
        },
        {
            0x9EE1E6F02758E89AULL, 0xD9BE06F2BBC87AFFULL, 0x0CBD43F3D2E9C71FULL, 0x0C834D0CB7EA0DA6ULL, 
            0xB750CF38977959FAULL, 0x0B4B946BBD837742ULL, 0x5E0A445F13F80835ULL, 0xAD6DB51B06F43C4AULL, 
            0x5A15967D4950FC25ULL, 0x515E2D867C30D793ULL, 0x5346A5C6A109F6EEULL, 0xFF9DBD1981C2883DULL, 
            0xE41C30E9DE768714ULL, 0x1CB24A0AF5D24F44ULL, 0x81AD7AB18E4CE37EULL, 0xFA322C6132176C30ULL, 
            0xA3CE5637657016DEULL, 0x09601CE5B8AB733BULL, 0x792E16C28BC48FA4ULL, 0x4E87DE17A4D79348ULL, 
            0xB2D29DFDB1D4AC9BULL, 0xF4C789BAC263B018ULL, 0x4B4353D0B0AE8181ULL, 0xEDDD6B52EECA4D80ULL, 
            0xA2261AB6515D5035ULL, 0x55ADE5DAD60C26BDULL, 0x60C2535038AB45B0ULL, 0xB6E83E83FF1EB532ULL, 
            0x3CE123ED54340FBDULL, 0x5DCC0242B91CCD84ULL, 0x0FBB0F221F92836EULL, 0x244E545D3DCC4327ULL
        },
        {
            0x5975A02D6AB2E2DAULL, 0x105F6A88C2624C03ULL, 0x52FFA5B54FC9073EULL, 0x02F9D22D2C374C69ULL, 
            0x83F347AA2BB32789ULL, 0x15C7ED2BEB8ABE91ULL, 0x2ABE1F01332D44AAULL, 0xC2C80DD8AEAF3982ULL, 
            0xFA941B775A876EFDULL, 0x3AEB96815391FE73ULL, 0x0A3EA644FCDB8265ULL, 0xBE1C037FDE32A8DEULL, 
            0xEE1A510934C7E282ULL, 0xC46D75E491C545ECULL, 0x8D3E40B19A2A5787ULL, 0x68F553459FB84C38ULL, 
            0xD27264CB26EE6F52ULL, 0x28086321C5A5EF26ULL, 0x327645DD1BDF7CC5ULL, 0x11D1A51B2195FFB5ULL, 
            0x0654F4A15846A9E3ULL, 0xDE7132D693AF0701ULL, 0x58F15ADFB071CD1AULL, 0xA99A3E67D25B9454ULL, 
            0x623731590E605642ULL, 0xD203559A9653E805ULL, 0x94599FE229773067ULL, 0x5E636BEE6B1D41E4ULL, 
            0xEABCF66F3B37B2C5ULL, 0x067CE1AE0B38BDADULL, 0xE9D5C3374DE79096ULL, 0xA82EFFD5BB4887B1ULL
        },
        {
            0x101DE9B6E08997D6ULL, 0x9DDE7F87ADDC2778ULL, 0x9DEC61487B0979F4ULL, 0xA412597EF5964C3EULL, 
            0x2D058B04F85DECCAULL, 0xFB6193932855AAE2ULL, 0xDD787D0A9EE4F799ULL, 0x6FB79559E9F10C41ULL, 
            0x2131D3E8975725FEULL, 0x1838B50F8E0EFD97ULL, 0xE23D670723FFDF3DULL, 0x6FC70AC544C37012ULL, 
            0xF5DB5183AA42BD27ULL, 0xBA7AADC17A487ADBULL, 0x67D139C1F296C601ULL, 0xAF2CE9D9979D86EBULL, 
            0x87771C462F9F6DB1ULL, 0x5F6A4A05170856FBULL, 0x543AECA8E95E6C51ULL, 0xCCB1822CC85B059FULL, 
            0x8EDDA7ADDFC72205ULL, 0x468FA9C79810C1EDULL, 0xBCC4B430B8A24D4FULL, 0xB873DC9BD00818D5ULL, 
            0x69C88DF5A6FC6FF3ULL, 0x8AC2F7E1905E28F9ULL, 0xD9ECCFEFD807C454ULL, 0xE8A39BE906940D48ULL, 
            0x5D6D9BBA17B4168FULL, 0xBDD2B55D25EAAE9EULL, 0xA6420DC065DAA9C3ULL, 0x4A69E1698FC25A24ULL
        },
        {
            0x6DC1A4D4A6B3AD67ULL, 0x6967AFD82F3AEE4DULL, 0x46112F336B6F2578ULL, 0x26E2A7A1254AD654ULL, 
            0xF4D391424E720E48ULL, 0x1969F08B90C5B1EDULL, 0xA9834937746FF963ULL, 0x37193FD56A3633EBULL, 
            0xFBE72C024ABB5E94ULL, 0xEFCE2DB947968DAEULL, 0xFC3F380710092BE9ULL, 0x2D9E8817DCBB541BULL, 
            0x1D5C2CEC8EE88E37ULL, 0x5CB20916EACEE608ULL, 0x45DF7B8FD832F23EULL, 0x5853667E0ED8BBE9ULL, 
            0xAB2E978667476015ULL, 0x70821C52A4DCA3FCULL, 0x36A634D7CDA9E3C7ULL, 0x7605E8F1752A5EB2ULL, 
            0xE8FCC6F1F2DFD553ULL, 0xC94D93694E4C0B3CULL, 0x5AF50A25A9F5FBCAULL, 0x9465B505A10554ECULL, 
            0x7E0B0C69322D4C94ULL, 0xC3DAB153CA4D6047ULL, 0x1AAE6DA15D5F2865ULL, 0x01DD58ED2AC9D516ULL, 
            0x4D2462038E40BAB0ULL, 0xEEEEBFE5C53239FDULL, 0xE3B3B0298DEF8752ULL, 0x99C2901F9DA91735ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseFConstants = {
    0x1337EC44710D9115ULL,
    0x7993B5879002E321ULL,
    0xE686DBEC4024E8F6ULL,
    0x1337EC44710D9115ULL,
    0x7993B5879002E321ULL,
    0xE686DBEC4024E8F6ULL,
    0x2D4DA3CF1C0291FCULL,
    0x9E8C1262121B6534ULL,
    0x1D,
    0x83,
    0xD9,
    0x09,
    0xEC,
    0x37,
    0x57,
    0x4E
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseGSalts = {
    {
        {
            0xCEB33329D82118F6ULL, 0xB2951DEE7631A42CULL, 0x51B9A82965D1171EULL, 0x2D8B9CE6631CB7C4ULL, 
            0xB13D8145A7191E87ULL, 0xB071B84D98A19B61ULL, 0x0C58CDE2AA6C25D6ULL, 0xAA365A61F86F962CULL, 
            0x6E7BBA7FE3EB1BC1ULL, 0xC7E2F0A8DFE2F4E9ULL, 0x9A7CB51051D0D4FDULL, 0x09212B0E0E2679BCULL, 
            0xC8795BF36ED38541ULL, 0x9368497CBDA58EC9ULL, 0x4E4689D1295D22A7ULL, 0xCF63A0594210EBE5ULL, 
            0x57D6751D6FF7D28EULL, 0xA70E88D197C2A068ULL, 0xDE6F006925C8E13AULL, 0x13ED0FDA36556AF5ULL, 
            0xD1009533E16E1638ULL, 0x0126122932ACDFB8ULL, 0xD02385B42B2E5A02ULL, 0x379D6F9F5C61A75BULL, 
            0x87C33102A8199978ULL, 0xEE421F3C8DAAE7F9ULL, 0x3FAD80033D77AA42ULL, 0xB61C872D9AA99CCDULL, 
            0x896C064A2200F287ULL, 0x65AAB08D80D5B61BULL, 0x2A8C6B817A22E928ULL, 0xF33D011A62DC600CULL
        },
        {
            0xB0E3AE9FCB59C716ULL, 0x7E9A6EEA82BDDF79ULL, 0xDB38E7B2EC46F8EBULL, 0x5F2B7E53071A1EAEULL, 
            0x86117493844A5509ULL, 0xF66B01809C13478AULL, 0x5B4506FB4A9509F6ULL, 0xCB8D39D11A99B96FULL, 
            0x83EBAC1D3108E62AULL, 0x73CFDE4B19E07172ULL, 0x0B05F8D6BC67A6F6ULL, 0xC6311875EE3BE5A3ULL, 
            0x39C5290B3C789465ULL, 0x10879FB5BE671A70ULL, 0xD367C64F3A7DF714ULL, 0xAD70930B211A87E6ULL, 
            0xF2917D715CBC73CDULL, 0xD176EDF356315370ULL, 0x3226C90EABBA43D2ULL, 0x1D9C12AF8CAA2E48ULL, 
            0xB70363783B07BF39ULL, 0xFE741B4BE82EA69CULL, 0xB78DE15D79C4EB4FULL, 0xFADD2AC6F4AAD83BULL, 
            0xB2A82B086797A153ULL, 0xC4C7EB9C62FA5B03ULL, 0x3BE44072A21A3628ULL, 0xD6361AAF02CCF6AAULL, 
            0xE49803AFBF025622ULL, 0x147E80D6914FFC6AULL, 0xDC607B049780F8B5ULL, 0xE8EA4F2AD1926454ULL
        },
        {
            0xA084A523908483CCULL, 0x7619EB95F9968891ULL, 0x6E5C226B7546892DULL, 0x4538BFDA128B8AA8ULL, 
            0xD9B98196AAEBF746ULL, 0x4A9578C6E6E5B756ULL, 0x69FE75AA49F3AA53ULL, 0xE2733047C8ECFFECULL, 
            0xADEC1427C0DD12AAULL, 0x3760EB2BB14E7FFEULL, 0x3F662DD2D879665EULL, 0xF6CF885BB7549BB8ULL, 
            0xE7E1CC7B904BE5B5ULL, 0x9FFF84536DDADD4CULL, 0x577EABCEE2457728ULL, 0xA3249B1CC3FDF59BULL, 
            0xABEE6219887BEC48ULL, 0x070A8C00037AD860ULL, 0x7F31A41BF85B7AFFULL, 0x841C5373D6ABF9D0ULL, 
            0x63DA7A18E83C841BULL, 0x83997ACE5C0CFC0FULL, 0x6F83CD577C040766ULL, 0x024126B7F181B145ULL, 
            0x29AA7A14A69E13FDULL, 0xE31353BC3958E0F0ULL, 0x7ED025A473520E65ULL, 0x0A15FF600FD8AB00ULL, 
            0xE12F11C4EEE24676ULL, 0x7A55549C1AC24BC4ULL, 0xB8753953ADAD5ED3ULL, 0x591163D6DA908570ULL
        },
        {
            0xF36FB36DDF82048BULL, 0x2DA6CC6ACC8BABA3ULL, 0x110CBF600030F4FFULL, 0xA3213842A6098AFBULL, 
            0xD889DEE241F89232ULL, 0x5FF9B6E1CE71CBECULL, 0x2EB975AEE9C64AF9ULL, 0x1387E4C2EDA84EB4ULL, 
            0x51BCA6279FC6D0D6ULL, 0xC0686D76488855F8ULL, 0x2C08BD019F447AC0ULL, 0x7F15D1AC57185F35ULL, 
            0x4FCB114751721BBEULL, 0xE69FA790AC5DCB2BULL, 0x6C47310FF6FA320EULL, 0xB7202A37E3E2E9CDULL, 
            0x4D9739364E6D5248ULL, 0xCC19F80D1D26B5E2ULL, 0x571DF76E4494EB22ULL, 0x6414B5979CD508AFULL, 
            0x04F72D42365A2489ULL, 0x1BC160E3AC42908BULL, 0x15470B80A7F35926ULL, 0xA23574FBC7C155FCULL, 
            0x8803DE2FB386A4A4ULL, 0x6DA3C42338D2F58BULL, 0xA8403353FED12DCFULL, 0x5EB409DEC1272636ULL, 
            0x54EC9F44B23E7D2FULL, 0x227C6B8D2EF660F0ULL, 0x3226BA03B624BF76ULL, 0xD3CB02FE1DC6F053ULL
        },
        {
            0x264F75EFC6B4DF5BULL, 0xCC9DCFF7589480D2ULL, 0x86BA9AF2BD1E9627ULL, 0x081A61E63598748CULL, 
            0x818F31686BBFFC89ULL, 0x7737DC0D9B46EB2FULL, 0xBFFAEF332EA8A55AULL, 0x6F298621C8663110ULL, 
            0x7ADE3849879F6E8DULL, 0x5F6C5A2DEDDD75C7ULL, 0x3E69E935CC991FD5ULL, 0x2271C5AF4F18798CULL, 
            0xC9AC940B48E13976ULL, 0xD8D6917703DB6515ULL, 0x3B39B419DFF6583DULL, 0x05C515E64448AE1DULL, 
            0xA2354378B88564F0ULL, 0x0B4831F95D5D5191ULL, 0x772F0954EEE2F756ULL, 0xE7524981F2214CD4ULL, 
            0x2A57F6E02B29C273ULL, 0xEAFF9696BD0183EDULL, 0x5E4BFD22E926239CULL, 0xBF8C8669053592BAULL, 
            0x53DC33661F1BB4ABULL, 0xDCE16FFBE229D16EULL, 0x25E22F61994B4CA6ULL, 0xCCE17981061FB73CULL, 
            0x0B49F937C11ADBC5ULL, 0x11579A394A509AABULL, 0x8CA66BF3C168DCD8ULL, 0x0450142703D5655FULL
        },
        {
            0xC344264AC57239D7ULL, 0xA2A92AEBF8792EF2ULL, 0x2F98FF42B62A473AULL, 0x873193F0BA54155FULL, 
            0xC0AD7E00450E9E90ULL, 0x76444116CEB6D20FULL, 0xCEDE98A087BC1C2AULL, 0xEC1BC8D7EE6C7381ULL, 
            0xE10FAA847E7239F9ULL, 0x22622F4C0E0D5E11ULL, 0x051FFEEFF0015F3FULL, 0x81CA93A134F4593AULL, 
            0xF5AE71858CFBB5F7ULL, 0xA230D79752D44B28ULL, 0xACC345E33B7A9F28ULL, 0x0205B3FF41C16B0FULL, 
            0x0DB3F239F6F62724ULL, 0x1BCE8531AB2E5C5AULL, 0xFE2FE4FB6B756720ULL, 0x865AB2F7B31DBBAAULL, 
            0x06A68D253A2E7139ULL, 0x15FB46EAA2C1FE2FULL, 0x208E8A0E5833E902ULL, 0x524F03F82B1BBB36ULL, 
            0x84461A0CA7C60069ULL, 0x16F0E95A9AEB89E5ULL, 0xBDA192F9C9FFDB84ULL, 0xCEA78A83F4BC2D07ULL, 
            0xC49BCFC03450B503ULL, 0xB47D8EB224B0FDBFULL, 0xCB737C471B9A6E78ULL, 0x01511AAEEC3493B2ULL
        }
    },
    {
        {
            0x9E513DB6638F9200ULL, 0x9C11C75D5178784AULL, 0x269207F3421A3B30ULL, 0x2729A1FD1EA8AD12ULL, 
            0x06512156D9A5CBCDULL, 0xFF150FBA7EC0E146ULL, 0xADA955234C04DC8EULL, 0xA530E71B5D674D35ULL, 
            0x6C6393F54B63C81FULL, 0xAA69FEE248AF2643ULL, 0xC61F47BF819273E7ULL, 0x44B8E0B174012F84ULL, 
            0xBCE1D267578A9DB9ULL, 0x64E0B152B1CBD7AEULL, 0x82375B41CCB6453BULL, 0x709348EC257EA725ULL, 
            0x305FCC7C8B4EC196ULL, 0x953F72B90B64AD76ULL, 0xE214D23CC6DF616AULL, 0xF9E08D0E07540FB4ULL, 
            0x6E50EA3CC1CC00A8ULL, 0xC40187D40851E701ULL, 0xCCDF2FA433716118ULL, 0x19149F8A1B8D9B21ULL, 
            0x6953A2667DA6A7A7ULL, 0xA8F5A9CA5FD5CBA9ULL, 0xF3F474AED15DEB27ULL, 0xC9D2F414C320F3E7ULL, 
            0xFEE8207813533908ULL, 0xA8002526098DE3C6ULL, 0x92C1AB12698E0C1CULL, 0xFA76E26BAAD5E1DAULL
        },
        {
            0x1428993E9E6D9457ULL, 0xDB1B4917EA13B49FULL, 0x78D40EDCCD003FCBULL, 0x46034128DE066A3FULL, 
            0xCA3963D965FEEDD1ULL, 0x5221892E4A770FABULL, 0xCBC6B983A2DF8B98ULL, 0xF1334047E5A39BA2ULL, 
            0xD60536B68E75D10FULL, 0x78DA6118F795C445ULL, 0x71CC316F1CE0AEC2ULL, 0x1D28A56761C7E28EULL, 
            0x42D5CC449EEF9EA6ULL, 0x248EF17D3F2B40B3ULL, 0x238C2995DA2F149EULL, 0x4C1D300A84CD55C9ULL, 
            0x1AD1160B79AA1092ULL, 0x12BC8888A006BDA2ULL, 0xB66D14B3DD2FED2DULL, 0x2411B68EB5139953ULL, 
            0xE32F132E6DE6C519ULL, 0xD302ED6D02E569B2ULL, 0xE80058149423ED70ULL, 0xD34F8844305D4125ULL, 
            0xA8020F3D46AB55C5ULL, 0xEEF1AA00D15A49C6ULL, 0xEED4F766B783753EULL, 0x8CA21E37B707D8F8ULL, 
            0x0BD34C993E01F93AULL, 0x99FD7D47AB9567BEULL, 0x69ED501ED6219C32ULL, 0xF4756D363C4C5B6DULL
        },
        {
            0x7DFAD3528C4C8F92ULL, 0x30A3115368234F7DULL, 0x006A19FA0201A4F0ULL, 0x4A3294D9FF1BCDA3ULL, 
            0xBBCB9262A78D13AAULL, 0x05D6F69F4DEECE0EULL, 0x6AF7AFFF1F5FEA1BULL, 0xE54F2C0E1B4B6E43ULL, 
            0xD855A452A91FB9EEULL, 0xD39080B9E78C6CBCULL, 0xBB3A8E267B60172FULL, 0x083945D3205037D8ULL, 
            0x057F750039A941E2ULL, 0x0DD24AC7B8C13A5BULL, 0x1D41A7801EF5BC80ULL, 0xA18218A859900169ULL, 
            0x2D4019CBDE2C9FB5ULL, 0x3995C39D46C12915ULL, 0x42626164CDD75376ULL, 0x68C587C05B483F3DULL, 
            0x6D5D87C11A8B9961ULL, 0x6A71747D205FB09DULL, 0xDDE009920341A225ULL, 0x48082B49575B3586ULL, 
            0x6302D7D19D8077B9ULL, 0x249F6AB1CD616374ULL, 0x15E46FC103F95893ULL, 0x7132D879D9437767ULL, 
            0x910ABA11DEE7EA8FULL, 0x4DFE38F4CD360822ULL, 0x79EA465126E9D6C0ULL, 0x6533B32DBEAA87D3ULL
        },
        {
            0x8CA44DAB568461CAULL, 0x89829ECBA4A7AB64ULL, 0xF20C51E363D1BF4DULL, 0x7D630D82A44686A9ULL, 
            0x854A937A06EFDB45ULL, 0x9F0F01E6C1B901CDULL, 0x800E983274EEBFE0ULL, 0xEBD5328E91EC2EEAULL, 
            0x1A2F56EC2008355CULL, 0x4117012E0A2D9611ULL, 0x02DA303ABE77D251ULL, 0x3C89CD1C07B956E1ULL, 
            0xD39D720F9294ABFFULL, 0xA6790E272D327311ULL, 0xD9886F0C9F03839AULL, 0x396C25A1BC840D69ULL, 
            0x85DA4543E33F6F62ULL, 0x450CFDF345AC11A0ULL, 0xE456CDCFDC1FE74EULL, 0x049CE69E4A1621EEULL, 
            0x50E944AFF69A93E1ULL, 0x6C4E47340AE425C5ULL, 0xC6AC4FC3705D8B15ULL, 0x70E0E561CA4B6B40ULL, 
            0x600F8884FAA7529EULL, 0xAA745F619A71F718ULL, 0x5E87A3F9C5FCC7C5ULL, 0xA59A18F494691ECBULL, 
            0xAAE6C9419F275DC2ULL, 0x106FD3ED54697891ULL, 0xE97E7CCF5CB12569ULL, 0x2AA88A595E2FEDC4ULL
        },
        {
            0x22456ECFA885E066ULL, 0x767A12337E853D6DULL, 0xE43EC3E25103C0F6ULL, 0xCE1644EB3F6FE33AULL, 
            0x445AE15F385FAD0DULL, 0xFC8490837E36016FULL, 0xA34AF6A097CC48FAULL, 0x3EAA95E45BE41693ULL, 
            0x774AE1CCA3F8FE1DULL, 0x8445F53941B5B0C7ULL, 0x6098214EE3C2BE38ULL, 0xDD2856D601EFA40CULL, 
            0x8B64987DBCBD7C0BULL, 0xF9DF754D1F6AC55CULL, 0xB515B1DDF9FCF4A0ULL, 0xB95D23D76264BABDULL, 
            0x9BFC1633080E32FDULL, 0x8965C37AF6246D8EULL, 0x3D2EB8F87D4868FFULL, 0x1A9B7BB0C1CDD63FULL, 
            0x082FA20A95D7F2A7ULL, 0x22C8D3F99758E234ULL, 0x62C9179F6DD74734ULL, 0xC55FC03984814DC9ULL, 
            0x174377074473DCBEULL, 0xD498084078AE2402ULL, 0x346B81791DB89C0AULL, 0x90C09403E8502EC1ULL, 
            0x25E54B994654703BULL, 0x0C51B2224E1DDE8FULL, 0x010BB786995F4913ULL, 0xD00BEC837A733153ULL
        },
        {
            0x7809B339317D5872ULL, 0xB93E4BB43F718DE4ULL, 0x049C658ECDD4D485ULL, 0x1EB536D5817BB7E4ULL, 
            0xECA2444C430F4069ULL, 0x6FAFBD5CD56A4F7DULL, 0xC07A277F292BDD73ULL, 0xD49C26C436F8C6D3ULL, 
            0xE1088DC9FDC0742CULL, 0x62A35FEDD8D3CCC3ULL, 0x26003A655F04D951ULL, 0x625C8790A8662C86ULL, 
            0x4A89C3AB49A47CC2ULL, 0x6C78EBEE34D054F3ULL, 0x380088908EA9AD2BULL, 0xE18D63DA33C9DCB5ULL, 
            0xAB4C573FFD237F6BULL, 0x20D2AC139F98E9CBULL, 0xCDC0AA16BC9B3056ULL, 0xAC8CE29A7A1EBD46ULL, 
            0x4669E4D60BB46B52ULL, 0xA8B580C5D4580760ULL, 0xC6B58E972FD8A2F4ULL, 0xDCB7ED9B99DD5B05ULL, 
            0xC0DDEBF9CAE30191ULL, 0x228F9B9EEC38019CULL, 0x7F2B99B9FEBA48EAULL, 0x5463FBE68661BF90ULL, 
            0x21CF2C801B1E9C12ULL, 0xD47737C7F97EFC64ULL, 0x3A88D138216B32B6ULL, 0x243FAC28D5ABC270ULL
        }
    },
    {
        {
            0x246751DC83F962E2ULL, 0x59203BEC030111F3ULL, 0x8634060C7387BA55ULL, 0xA346BC930C512292ULL, 
            0xF74647FFC6754FB7ULL, 0x1F5FFA7BB13038B9ULL, 0xBE97A57820E1F6E6ULL, 0x4E5D23B7F0ACE3F7ULL, 
            0x7F691F57AE75A2DFULL, 0x3C6064B7AD818F32ULL, 0xF95C2551F0D8E95BULL, 0x88168666BEE6C969ULL, 
            0xFCAB4A1E6DC0B536ULL, 0x6E433409763FE608ULL, 0xAAE8F678300EC1F0ULL, 0xD9D97392F1AC5710ULL, 
            0x5FAA38523A1D14D2ULL, 0x1DD7B6EDD8C05E8CULL, 0x19D5FCDC7E928052ULL, 0x6E25DBEDBF77CB37ULL, 
            0x00502870CC58C363ULL, 0x8D65871A398E49DAULL, 0xE6D9450E5D2307DAULL, 0x0EE1BE3108095A27ULL, 
            0xECB90B7F4F0AFE89ULL, 0x48B902F128895810ULL, 0xA3318D015B955196ULL, 0x1910B92D3F27ADC6ULL, 
            0x43B25875C6DBE66AULL, 0x5156EFA0D6713920ULL, 0x2B3FD8CA49B82E0AULL, 0x7AC1A5F2F28D50FEULL
        },
        {
            0x377AB15F26F4A5EBULL, 0x9B9D5253888A2B47ULL, 0xEE014547A08FCB1BULL, 0x35004CF6F1416424ULL, 
            0xD04664300BD2911DULL, 0xA697F7225EFB7EC5ULL, 0x0E729BD033955F34ULL, 0x65D4667F8F009B73ULL, 
            0xE8ECAD6A3DBC456DULL, 0x06CF9C34ACD9F73EULL, 0x17787ED306E01759ULL, 0x27FCAD2918DB981CULL, 
            0xFDA1ECF4C6DDC823ULL, 0x38F32BBB1003E991ULL, 0xE8F1A6FA578580BBULL, 0xE0287613CBC66A6AULL, 
            0x39B0A05A5FA07E45ULL, 0x51EA0258AF8C5A73ULL, 0x8389707CD92A2DDDULL, 0xBCE6A5875BEFECC7ULL, 
            0xDB5BF1808BC1B264ULL, 0x44846F0D1868DB8CULL, 0x29380B163851B4ABULL, 0x81011B7C03802FB5ULL, 
            0x848E4471D44D3B6EULL, 0x405B703D0883AE74ULL, 0x788036718874D684ULL, 0x1103A8B60D954693ULL, 
            0x23474B1D5204DACDULL, 0xCA88B0C61086609DULL, 0xB4922109E9D6C005ULL, 0xA17B107A76E6ED1BULL
        },
        {
            0x4F9E83A9BBA95B6AULL, 0xC33D4736D2D344FDULL, 0x99C424AC1EA1ADADULL, 0x94E8933C0166C445ULL, 
            0x93520A3BE2AC83A8ULL, 0x710B43A345F3729EULL, 0x85050A5D3155652EULL, 0x9707A218DCE1CD78ULL, 
            0xBECC4A3D4C625ED7ULL, 0x172B9C722ABA3FF4ULL, 0x994D5CED64725D72ULL, 0x6E191130366450A0ULL, 
            0xF8C8AB1EE16BDDF7ULL, 0xD31BC3F7264E2BCFULL, 0x02717D6147BAC5DBULL, 0xB4F6C2422E994CBBULL, 
            0x825ACF3E4DE089D9ULL, 0x2A8FC25993A18A28ULL, 0xB7BF796462C4FBF9ULL, 0x94AF765650F1C939ULL, 
            0xE384BD9EC91975D8ULL, 0xE583E5B360B5D9CBULL, 0x517D315876DA9C49ULL, 0x22AA0838371B98AEULL, 
            0xA444A0046ADC5D52ULL, 0xC2C17DC0744D6F96ULL, 0x8D4748985C7EF0A8ULL, 0x045ACB51D5EDEFCEULL, 
            0xA7C2C0667285276FULL, 0x26204C4598B4ABBFULL, 0x0465A412CD46CE82ULL, 0x26394818FA79C5CAULL
        },
        {
            0xB67F4751A45882D0ULL, 0x14446FCEB5D8233DULL, 0xDBCA5FC5619D22D9ULL, 0x262CCFD5E513CF77ULL, 
            0x5FBDE23982A0C6AEULL, 0xBF82A9DE4FD7D84DULL, 0x71435C7D21397359ULL, 0xE8D7536339783FAAULL, 
            0x14A2493E5D1DF07EULL, 0x1E0B57C9C162E0ABULL, 0x64953FBA4CC03FF5ULL, 0xFA6A539517EBEF3CULL, 
            0x00B2F6F2AF134B47ULL, 0x67618951931D33BBULL, 0xBFA521E95ED633B9ULL, 0x0541E24271918169ULL, 
            0x8D5561A6CFB5C0F8ULL, 0x358153217575FC1CULL, 0xFB09B5363E978F00ULL, 0x1AF92CA94958120FULL, 
            0xAD551D15DF84CB7FULL, 0x180FE10EDF656A9EULL, 0x92DAC62E0B141F83ULL, 0xF47DA2CA3D2FF1ACULL, 
            0x34319B1B1C603400ULL, 0xA459E56B5030D0E4ULL, 0x7A887FC3DB46FE68ULL, 0x3EA30BF0639614E4ULL, 
            0xF02AB24B24F75518ULL, 0x4B9328FAE08D67F0ULL, 0xC2D70AB23D687125ULL, 0x2CD16344E209D8FCULL
        },
        {
            0xAE62A4D19A11734AULL, 0x9C86A79ADB5DA403ULL, 0x0B395E9D980AF341ULL, 0x884B40222F6D541BULL, 
            0xB55EC31B51937639ULL, 0xF0C73ED352147274ULL, 0x59CAF2BB5360C29CULL, 0x1EE2073AA82FF500ULL, 
            0x19876CFFE3D72AA2ULL, 0x5BBCDCC5E6F0839AULL, 0xF82C93681FE9BB4AULL, 0xDAEABA5921AD5E77ULL, 
            0xEF85B102219A9369ULL, 0x6AD2183C963DB386ULL, 0xC46FD0849D642AA6ULL, 0x1406D531BA386E72ULL, 
            0x16A054D06F877351ULL, 0xA312B468171F9602ULL, 0xDF23B1638CEBD978ULL, 0xEE0F77918A57B3A6ULL, 
            0xD5BEE87B4D3F0E85ULL, 0xC2DB9713741D3295ULL, 0x90E5B4C6016CE0BAULL, 0x37ECD9AED84060D0ULL, 
            0xF0C22C147117066AULL, 0xF9A0EE7A29CD4BDCULL, 0x2A83498890509926ULL, 0xBA695E258DD51D92ULL, 
            0x003869D171821082ULL, 0x03BAB372368618BBULL, 0x9C5FA49A74159488ULL, 0x325FE2B64801832EULL
        },
        {
            0x6289B37D3A2FAEF7ULL, 0xE25C5CA6F9069978ULL, 0x5601476DB11D1C4FULL, 0x3E92749C4A18280AULL, 
            0xF6A740C0B7384C06ULL, 0x15B51C21CA74F3A9ULL, 0x7D5B15260B595509ULL, 0x617D8AB5F97E2DEEULL, 
            0x4152DD1F731BB78BULL, 0x0A8F0BCAA4B6EBBAULL, 0x602FF544C46EC5C8ULL, 0x11D46796768FD870ULL, 
            0xAEE4E8768989FCCCULL, 0x47FADBDDE2343980ULL, 0x1122FE230833CFDFULL, 0xC25363C70E9C25ACULL, 
            0x5C319BC3E4CF8B0CULL, 0x99BA8E267B6272F8ULL, 0x3F22BBA1AAAC8B0BULL, 0xE1A6AF386C56A099ULL, 
            0xFACD0A19CE79BDBEULL, 0x50A219C5B52FF39AULL, 0x32B59327B7CE1A60ULL, 0xDAA08F40BF6CEB3BULL, 
            0xB6A610A0CEE40624ULL, 0x00D9ACF0ABE63FD3ULL, 0x0DC11149DB9F8020ULL, 0x06B074459689BDB3ULL, 
            0x4BC3B42AFFA7D573ULL, 0x3DC884CC321749D3ULL, 0x1FEB4F4C542337ECULL, 0x0F1F2E4FC1074F8EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseGConstants = {
    0x37885711259361BAULL,
    0xAC2908829403773BULL,
    0xB68B24859BAFA120ULL,
    0x37885711259361BAULL,
    0xAC2908829403773BULL,
    0xB68B24859BAFA120ULL,
    0x1C364DC1F949287EULL,
    0x641739FF2CD88B23ULL,
    0x07,
    0xC7,
    0x6B,
    0x11,
    0x8E,
    0x2F,
    0x28,
    0x6E
};

const TwistDomainSaltSet TwistExpander_Bowling::kPhaseHSalts = {
    {
        {
            0x49AD3F06CA89399DULL, 0xB9DCD2E2017B52E0ULL, 0x9BE98C13A6D12A44ULL, 0x4E5C8C49A8789A4DULL, 
            0x70D431AC9074C62CULL, 0xD1F33563930FECD2ULL, 0xA3EF1F5E5F46679DULL, 0xABB801005776DF26ULL, 
            0xDBD8D858F6C9094EULL, 0x2E266EE3809CB3CFULL, 0x7B7FC1F8699EEF68ULL, 0x6BA3CFD070E7459BULL, 
            0x6CB1372326458B4FULL, 0xC6350007A628CCECULL, 0x7CDBFB491E3D4FC1ULL, 0x4C183C739B555AE3ULL, 
            0xACDA0013D8336443ULL, 0x1345DFED9B2D4D4BULL, 0xA788FD9EDA882D69ULL, 0x829081427A5C561FULL, 
            0x9FAC46E7613BD10BULL, 0x74D4C92127138ECBULL, 0xE7171F9876F5B208ULL, 0x3A68667A7A82787DULL, 
            0x648171367BFB0653ULL, 0x4B6E78BBBE7122B8ULL, 0xA0C11DF699331981ULL, 0x55F6EF54E172FA14ULL, 
            0x34F8E497D6C2A2CFULL, 0x80FFC7AF077317F4ULL, 0x6F95E289CBEF5E1CULL, 0x8CA1C1E697B6DB5DULL
        },
        {
            0xC49868429E9DC51EULL, 0x06010405A9BEF015ULL, 0x7C0164343E0458A5ULL, 0xA159402CDFC276C7ULL, 
            0x55B61BCF4C5D6B43ULL, 0x66ECF5E87D5B8CC1ULL, 0xD0EDFB85D9BC1B1AULL, 0x8A26E1B3CFDBC4D7ULL, 
            0x2F76A8671180DE3EULL, 0x79115A46F1C2F3F9ULL, 0x2016829D2174DDE1ULL, 0x69BC5A1985EB3470ULL, 
            0xEB578D0C1DE37784ULL, 0xE863BB049F012B41ULL, 0x8E051E5A4B7596EBULL, 0x6A5198164E43AB11ULL, 
            0x305C4C969BAFD5ECULL, 0xE271CAED45749AE0ULL, 0xF611044966DD5F7CULL, 0xEC4DFCB46ADCE143ULL, 
            0xCA3966AB0D74343BULL, 0xDB025DCA6810F3F6ULL, 0x91E36C0ADF81BD72ULL, 0xCFBA29C43D2268DDULL, 
            0xE4863A7E6ED8CA6DULL, 0x960BE275DAD3A49FULL, 0xABFA2A3E4FBA515BULL, 0xD98C591A653A89C8ULL, 
            0x0259B17236B4C374ULL, 0xA46A872A55941529ULL, 0x055F5E38749425C4ULL, 0x86DA2928C66F25A0ULL
        },
        {
            0x96AB19F33DE30714ULL, 0x9181DD217D49A5CCULL, 0x8513F5CD10105814ULL, 0xE8E0A83B497B2EBBULL, 
            0x5200ACA0F4583434ULL, 0xDCF9E8F008543896ULL, 0x17E4ACDD167DE972ULL, 0xE17FFCAA556AFC65ULL, 
            0xFAD0230767BA6811ULL, 0x13E7102D656A3A8AULL, 0xEF93BFBA5D301203ULL, 0x6FF8318D8F7268C5ULL, 
            0xB8381EEE439D41DFULL, 0x4BF3354630E0DC39ULL, 0xA87F9522464E0E2CULL, 0x041A5561CAB17E8EULL, 
            0x5B2B3FBA51CA70AAULL, 0xBE16E008D8A2002CULL, 0xD95357237B054C88ULL, 0xFE82802C52B7163EULL, 
            0xCB7FFDA28D560DD0ULL, 0x1DF93FCB0BA7F203ULL, 0xE875685D10BCF232ULL, 0x5F1A5FE5B513E9C5ULL, 
            0x1BF5A263CE7357D4ULL, 0x931B8781AA1888F0ULL, 0xC9127A738CA375FFULL, 0x98BDBE92D9738B72ULL, 
            0x659EB0FEEC2F5C55ULL, 0x33A46D6899344B8AULL, 0x194B542FF552D050ULL, 0x2D33768A61C87717ULL
        },
        {
            0x724A7029E983328FULL, 0x8678166DE88F9E81ULL, 0x76138E42AF6C118AULL, 0x118656D84B9B58BFULL, 
            0x92546EAB037E5625ULL, 0xA4055BC4F316EFFEULL, 0x2803314ED149FD11ULL, 0xD4DE4394C421ECD9ULL, 
            0xC9B3401E63DDAC0DULL, 0x4E2E20962D571FDFULL, 0xC4DB0C4378CC551DULL, 0x30F34F4766CEFBACULL, 
            0x44AF24CF6DD3A3C7ULL, 0x69DD0125EB28C145ULL, 0x62F6A3794F333718ULL, 0x878E91EF4AD41E38ULL, 
            0x5E5EDF025134C8C9ULL, 0x642DE425AA0EEE86ULL, 0x2FAF774F34CD6E88ULL, 0x06E86D97C86509B6ULL, 
            0x97A64D9542B7E650ULL, 0x059F0881ACB68A44ULL, 0x4D4509ABF3FA14E2ULL, 0x822E31EFC1B9BC3AULL, 
            0xD68D9CB09046FA29ULL, 0x5FC0507DCFE4342BULL, 0xC3260D03C2D37F3EULL, 0x6AD0FBD1B58C9F38ULL, 
            0x5AB58CF7B5881E71ULL, 0xC6D6A945BC606AAAULL, 0x4416DF97DD8F7E2EULL, 0x03B7DE2A31DEA3E3ULL
        },
        {
            0x24713BBC7536120CULL, 0xBF606B45655D5E6AULL, 0x1AAEBDC79613BC07ULL, 0x1ECF9327193E1575ULL, 
            0x17D2119D7B9EF0AEULL, 0xC55A4A795DBB8D0CULL, 0xB1AC4271915D6A10ULL, 0x8F1E6D6E754F1644ULL, 
            0xD5E20EBE569FDD05ULL, 0x878A3E8AD1C3DF94ULL, 0xA25CE6E97F4E6E77ULL, 0x4F24C65F468A232CULL, 
            0xF334C9348093BE2AULL, 0x3728272B21067E9BULL, 0xFB1213A63F85AA2EULL, 0xD98E30AD1CBA42E0ULL, 
            0x2C229D1D772E8796ULL, 0xD98F307CA02862F1ULL, 0xA93FEAE723DEE181ULL, 0xA50C6267AA0476C6ULL, 
            0x724EF1103A6E2166ULL, 0xA086D511DA601FAAULL, 0x80AC7323C7F1CE0BULL, 0xE2C25BE69113CC1AULL, 
            0xE528A3BD3275BD4BULL, 0x5BEE67FCB6EB9E0EULL, 0xB3F3185BFF8F864EULL, 0xC19C860251E03515ULL, 
            0x93F6B31AEAFB58ADULL, 0x623BE8BCC6F83817ULL, 0xC64422DABDE24F16ULL, 0x55C0BFDBAE9E6E87ULL
        },
        {
            0x5E8559870EF943C1ULL, 0xF0F5470409146AFEULL, 0x3FD75BF8EA3C860AULL, 0xFAF0E6150253A825ULL, 
            0x5C06D08FC6D0675AULL, 0x682C3C26F59FA34FULL, 0xFFAE49A40A0514B6ULL, 0x0D03BDA6D790FDF6ULL, 
            0xC6E4C504169442B0ULL, 0x1953502AB248D165ULL, 0xC6D118A56EF09028ULL, 0xED4AFA84D37783D6ULL, 
            0xDE09D27A3CDB111FULL, 0x8B06F6B4868739FDULL, 0x26B3EBB7CC07DE96ULL, 0x26EB131F15D1BF1DULL, 
            0x31215DD479A3E27FULL, 0x11AA8AE7DD3AA81FULL, 0x18783BC7761E620AULL, 0xB013ED2EBA8BAE46ULL, 
            0x25E402A454F30693ULL, 0x76EAE28B358C9F70ULL, 0xB9935DB5313D3176ULL, 0x4958EF0873CD1632ULL, 
            0x5C65A28C75CAF61FULL, 0x2C35D6BBEEB2F54AULL, 0xAC55B545D57F2D18ULL, 0x87B0A66DCBE8CF57ULL, 
            0xEBD692AA9768B0CFULL, 0xAE3AD4DF27863404ULL, 0x71F0516346A299F9ULL, 0xE811B551780DDE6EULL
        }
    },
    {
        {
            0x947D0B92EA4EDB9DULL, 0x1FBC5A73FBE64E07ULL, 0x5AE9F8299FC1BF90ULL, 0xF75DA5952D7447ADULL, 
            0x201B4AAE88C73990ULL, 0x2E924DB8711FD1AFULL, 0xF52C62BFC4B3AD5DULL, 0x88BB832D2E13E0A4ULL, 
            0xBD4A37F96A4B7914ULL, 0x559F2F827C86EDD2ULL, 0x9BC4B11689E381DFULL, 0xEE5A3976D5C69A65ULL, 
            0x270E22F74DC7E8EAULL, 0xBE935CE39E0E6E8DULL, 0x5A01DC22055C1E3FULL, 0xEEA5A52407607BEDULL, 
            0x2AD8F5D93889F32CULL, 0x25E27983854CB4E9ULL, 0xE19A89969055901CULL, 0x8140CCC57B34A898ULL, 
            0xE2F7F2FFB2B1A302ULL, 0xC9D4E9C36320F8F6ULL, 0xDA03833423745375ULL, 0x490474DE41C7B586ULL, 
            0x6969FDDF0CFAAA04ULL, 0xEFC19E199477E62FULL, 0x9A1AF642A366A8D2ULL, 0x8EFFEB6581C65106ULL, 
            0x0A0DF0812D6CE0C1ULL, 0xF2847F05571E8283ULL, 0x7BC2370750B7BFFEULL, 0x32528E5053647587ULL
        },
        {
            0xD84B46EFA33ABAB7ULL, 0x40BD0C52F036BE99ULL, 0x286A13EF66EE20CDULL, 0x18390B8427F86B74ULL, 
            0xB7F5F5D1772160EDULL, 0x93F58D121933E2F5ULL, 0xB06A63A39B2BA584ULL, 0xE0B409AA55AFB379ULL, 
            0x50B2BBA8B507FDAEULL, 0x25F9B82AC0420A13ULL, 0x074C2D682B64F1FEULL, 0xC9BE7BBAAF1B6097ULL, 
            0x2D9460B1DE3A5182ULL, 0xF261A0BA9BB457C3ULL, 0x2FBF83F843152A17ULL, 0xE63BB9EDA701AA05ULL, 
            0x78D20B0E742C96B6ULL, 0x6F46FB1BB9ED1547ULL, 0xFFA70B5BF92A3E80ULL, 0xEA5A89FF9D03AC00ULL, 
            0x7100BBA383F952FDULL, 0xCBC7A6757A8A5E4FULL, 0x9B075218ED272E47ULL, 0x0188B7EEE1759D38ULL, 
            0x5E0F158E6BEB16D6ULL, 0xE3ADE5590465CE52ULL, 0x75535FDD641B78F1ULL, 0xBBF06AF7A2655CA2ULL, 
            0xB7B2D7BD4048D272ULL, 0x3523050D18EA6B16ULL, 0xBAA411A906BE1584ULL, 0xF3DDBBE3DA9C563DULL
        },
        {
            0x1E5EF8FED7B9315FULL, 0x0BC5F5E68D4C1BA1ULL, 0x0274B00D5EDFCE3FULL, 0x82E7E6E4DC2601CEULL, 
            0x2E0131C2A2F8C44BULL, 0xA1D5C8D22DFF903AULL, 0x178E593598CF500EULL, 0x23DD4620A8451B5BULL, 
            0xE4D1CE930EEF27AFULL, 0x89717CF1332DBA7CULL, 0xBA76885376317B53ULL, 0xBD447488A44CB21EULL, 
            0x4D8B957DBC15339CULL, 0xB60973864F89AB98ULL, 0xB8EA198D12B0F5DDULL, 0x791C6872BA7D8655ULL, 
            0xD7BB22C87FA7086CULL, 0x19776E8104044BF8ULL, 0xA8AFE28A2AFAD747ULL, 0x7F0562174227175FULL, 
            0xD0F77E79845A1D99ULL, 0x739B550702082294ULL, 0x935889E6384B5BDEULL, 0x606F0AFE29260078ULL, 
            0xAAB48A413E8A2CFCULL, 0xCA5774D7DB86BB82ULL, 0x6C9BA1405158B058ULL, 0xD0138F91E3B551F6ULL, 
            0xC38C2FF5DC532EB9ULL, 0x6FCCA526B92CE67AULL, 0xE26AD1FB9322AF7AULL, 0xEA76918194FCC1DCULL
        },
        {
            0x46DB0AACB72CBF4DULL, 0xA249F3AE9C0C4688ULL, 0x51EF0D04A6A54643ULL, 0x8B56DA3D82DCBA11ULL, 
            0x87D0D95F8806E2DDULL, 0xCD4AA708B59A6AE9ULL, 0xB6348B398E9ABC56ULL, 0xAB38EB86101C1B9EULL, 
            0x6E873CAB81FC9CD0ULL, 0x7E1039A4C8C23832ULL, 0x3115201EAE421535ULL, 0x248ACED5B6C4F919ULL, 
            0xBE6092B07B04C543ULL, 0xE409C4B08F98FD37ULL, 0x1F95035D47CD01AAULL, 0x444CCFA4DDA610C4ULL, 
            0x8349C0F9B3A8F818ULL, 0xB769C47B67339C76ULL, 0x3FCCEA19962324E8ULL, 0x25BCF7A6C8574279ULL, 
            0x8B10B50AEE609F26ULL, 0xE6072DA1825A2582ULL, 0xA224B923BBC4F5A9ULL, 0x34855CDD493F833BULL, 
            0x4858F6FEA366E16CULL, 0x6AC76792463817DEULL, 0xBC04E012FEFFA2EFULL, 0xDE618D983A3C3D9AULL, 
            0xDEC46C160CABFA7DULL, 0x2F2F7FB285BDAD42ULL, 0xE2A409E3A3AC15DCULL, 0x66D2515D06C2D413ULL
        },
        {
            0xC5B8186B9F1F23F0ULL, 0x83ED0BD503BD5E4DULL, 0x9B8953DC23A49F0AULL, 0x6EE484370231A305ULL, 
            0x7044286EF5D9C751ULL, 0x62BC190C8B29C4D6ULL, 0x6C908D756D325AE7ULL, 0x0398285E3B0D2214ULL, 
            0xCBC4E70A656A79E3ULL, 0xAADF9BD274AAEC9DULL, 0xE59324A8FE01A474ULL, 0xEAB36A19E8CCA23AULL, 
            0x11ED53D070B1D263ULL, 0x813BDC9DB61C1895ULL, 0xA07D10EA219F3708ULL, 0x5A6BC558A66586A5ULL, 
            0x7F0AE884E1CF4843ULL, 0x02FDBC73A9FE693BULL, 0x7F2235E864E8B92EULL, 0xD453897EBE724B2FULL, 
            0x3F5A00A0585541E5ULL, 0x219F3DD21CCAB1B9ULL, 0x82F323D3EA30B98FULL, 0x81091E0036CB4EF8ULL, 
            0xA664C12CF6C033DEULL, 0x9ED8F1E7D94DC799ULL, 0x2BC42ED7330D19D7ULL, 0x4F46681F4A7C6B36ULL, 
            0xC33B3996FA1B3866ULL, 0x617A746A9CFE7047ULL, 0x1E1F98DB5D09A7E5ULL, 0xE9DD82751CEBFC4DULL
        },
        {
            0x9CBB538937E5E4FEULL, 0xD7C8D5A8183FC6D8ULL, 0xD3AF39EDEAD512F7ULL, 0xD0950BBF9AD5AFBCULL, 
            0xF8CF29B800A157D7ULL, 0x9D3542FA9E5CEE5FULL, 0xD12C672DB2D77913ULL, 0x44794ADB70F735BFULL, 
            0x9490B6BA5294CAB5ULL, 0x9D365D1EBF41FF77ULL, 0x92406A24C6F128E6ULL, 0x65A0313E7573A342ULL, 
            0xD2ACA90053C1CCF7ULL, 0x9EB2CC4179F51D9FULL, 0x2747669CF77465F3ULL, 0x28C85662011BA633ULL, 
            0x60C50C2204BF5490ULL, 0xAF7A5BD9997F76CEULL, 0x4AB7CEEC8B240C44ULL, 0xCB4676FD33BBDAE0ULL, 
            0x19BE3237FA81FF8EULL, 0x5D6C4642CB1BA165ULL, 0x146530FE771A0B4FULL, 0xFD5497359102BA66ULL, 
            0xD79F66A8329426E9ULL, 0x3ABA8DF4D0A179C1ULL, 0x2A7E67848831A950ULL, 0x0928F942579D8AF9ULL, 
            0xFF681C543F650D36ULL, 0x54BD3CB88C1265BFULL, 0x3AAD58D8159C30CFULL, 0x71E367C6FA59AAD3ULL
        }
    },
    {
        {
            0x2A9F9877CDCAD954ULL, 0xD8124AA7282E5ADDULL, 0x9DFCAE4EC3515B61ULL, 0xA20CFEA8DAA8134FULL, 
            0x29A5DBE352547E8AULL, 0x3ECED0290281C21DULL, 0xDB4FA2232E814239ULL, 0xCBB89D1B4CFAB9EAULL, 
            0x5A80A138E12BBEBBULL, 0x03022C70DAA4E394ULL, 0x0D8AE408304AB084ULL, 0x44A96B9FFCE4B733ULL, 
            0xDF775619B52A6635ULL, 0x4C29C8BACFE85E80ULL, 0xD1BCE16A0C08FB12ULL, 0x035E7DB1274F4A6BULL, 
            0x6F7297B11E84DED2ULL, 0xB8EA40DA5257C46EULL, 0x3EC53301577084F2ULL, 0x2753A1CABD64266BULL, 
            0x77989494C19B5FCAULL, 0x3145F878616683F6ULL, 0xE717A49D606BA3AAULL, 0xAF0E3A09E73367F5ULL, 
            0xBC649D4733D868BFULL, 0xA8C36FC7E9FA0FA6ULL, 0xB25E76E5078AB9C9ULL, 0xF651D69F67089765ULL, 
            0xEA5E2652691B37F8ULL, 0x269960106ADFE70CULL, 0x10FBF3308CFB81E8ULL, 0x8676C4DB7AC70C17ULL
        },
        {
            0xA027D71A22EFD3DCULL, 0x25720365A3F42CECULL, 0x5AB686D3C810104BULL, 0x9D5405FC3656F0BCULL, 
            0x62860FCE4850BE6CULL, 0xF7B05AE739C97176ULL, 0x26425C17023227F2ULL, 0xC3C8FD1B48970DF1ULL, 
            0x05DE9E8A4C9CC536ULL, 0x5B23D4C990186234ULL, 0x6B4CCB4C9D649297ULL, 0x329C56964CC7F608ULL, 
            0xDAD06A4FD76295B9ULL, 0x08B9CBE5AD88D4BDULL, 0x5BEDEA176F97B4C9ULL, 0x3E032F33CE2D06C4ULL, 
            0xA93E81950E4C1211ULL, 0xBA6021E2EF25B376ULL, 0x8171333131E78D01ULL, 0xF04FD737203727F1ULL, 
            0x37C43506BD176D4BULL, 0xFF2D564081F15CF0ULL, 0x931067A27E62EBF0ULL, 0x084F4015FDEABAECULL, 
            0x811598BE41469969ULL, 0xBB9AE74F6501590FULL, 0x559916364E5FF6D6ULL, 0x35FFCEE40786CF85ULL, 
            0x6285A75A3DE2E0E8ULL, 0xF874628D5770EECFULL, 0x59B434F93204D4B2ULL, 0xCEA445BDCE95009BULL
        },
        {
            0x0B58715B395F7EC0ULL, 0x9EE75FC26656F93BULL, 0x5C1245492E0AE776ULL, 0xD88FB6EC7B498CECULL, 
            0x6A630DEFAB52A399ULL, 0x9C950BBC2E6724B7ULL, 0x222EE444DFD49968ULL, 0x50D8AACE2545565AULL, 
            0xB8D56D4D8824169CULL, 0xCF437B91866753C0ULL, 0x9522BB45F660BBF5ULL, 0x66F803E74CCB3761ULL, 
            0x860EF498F852E609ULL, 0x85F1FECB9C2B07B5ULL, 0x16A4A4138CBDFACAULL, 0x633008CF91A02418ULL, 
            0xB09B25831D7B595FULL, 0xCB19FF903BFF2995ULL, 0x702845D303936C44ULL, 0x4E5197A61EFA5FD1ULL, 
            0xF33615836C58FC25ULL, 0xD73CF4ED202DBFB0ULL, 0x27A440DE16BC9741ULL, 0xD040CA396EB88445ULL, 
            0x8E17D3D2DACF2E5FULL, 0x8E72489969DF7433ULL, 0xED6FB094953AC347ULL, 0x066D953CCAFDBF79ULL, 
            0x47846AA7F756A18BULL, 0xED23CED6061D0D65ULL, 0xD8D3DF7F840604F6ULL, 0x8E22E242444C4E14ULL
        },
        {
            0xCA7698D8ADE998ACULL, 0x9A07343EE1C31EFBULL, 0x960B49F964A445F6ULL, 0x859145A896440BAAULL, 
            0x5BB215A63E2A85C4ULL, 0xF048D8919B63B4A1ULL, 0x39B8DA6A6927BBCDULL, 0x71090DE058E405A5ULL, 
            0x20BE0816A1EAAC25ULL, 0xDF19BFCFF06EC746ULL, 0xD7A82F160C76DEADULL, 0x089885C488E7EEC9ULL, 
            0x22D4C9ECD9B5E9E5ULL, 0x7951ED0B51B154FBULL, 0x8724386CF64295AFULL, 0x6F9499C14A79A4F3ULL, 
            0x9617A5B06A497385ULL, 0x8B639C5CFA5E7BA9ULL, 0x871EF57A6AE70C42ULL, 0x699195BE16078763ULL, 
            0x6053A1B2E9F7E65FULL, 0x448B037D6EB93007ULL, 0xD4FAD29D4D927CD1ULL, 0xDFBD7F088EF82A49ULL, 
            0x37290FD68EC85465ULL, 0xD33DD2D653521456ULL, 0xF5DF87820977DDFEULL, 0x0CB44E1D282B6930ULL, 
            0x4F42A55ED641F255ULL, 0xB31C70FE5B986F6BULL, 0xFEE374E907D175FFULL, 0xB396651E87BF43EFULL
        },
        {
            0xE19F05F59158D7DBULL, 0x075846FF73139FFCULL, 0x70AD799C33848E78ULL, 0x4509DAF49CC64B4CULL, 
            0x1C431D1570A19AE2ULL, 0x643D091801B8B5E9ULL, 0x8C992E20B924F1E8ULL, 0x84B0C59810DE541EULL, 
            0x98B315E695A45898ULL, 0x35DDC6E9D858C469ULL, 0x0819B07093952FF3ULL, 0x42F24D7C27BA0183ULL, 
            0x371E74D1AEF16695ULL, 0x91C8E45542BB5F0CULL, 0xD9DCC3C5978CA5B7ULL, 0x25CC5E4D421D76EDULL, 
            0x0E1E9FD8280507B1ULL, 0xA5AF2F21F5D67CCBULL, 0xD17B83F04683659CULL, 0xAAE58A985AF2888BULL, 
            0x1E0B7C0A0B2B81A3ULL, 0xC0B2860E0EAF1DA0ULL, 0x361771E7A4BFFCE9ULL, 0xE10CF6307ABEE0BAULL, 
            0x27E233BEA04CC956ULL, 0x5BA4C81EE179A883ULL, 0x5028CB2D6CF1471DULL, 0x136A2425AC28C867ULL, 
            0x5129DBDB04966B12ULL, 0x7196CD27B1D6F155ULL, 0xEA04C1C40B2DF743ULL, 0x7BECEE01E3E77872ULL
        },
        {
            0x1ABDED55F2108AF9ULL, 0xFAC154745D9984EAULL, 0x3A8FF6C80615378AULL, 0x821BA31756B42A87ULL, 
            0x5553514CA8ABD84CULL, 0x87E6313E1D42519DULL, 0x7FD0B2410E051E8AULL, 0x3EECBFC62356DCFAULL, 
            0x5C2B0F40A9A00C67ULL, 0x178DCB83C79A23A1ULL, 0xF1B0613946F87392ULL, 0x6E66AE799E22813EULL, 
            0x35F4E489C287BFD7ULL, 0xC69BE21F0C3D1478ULL, 0x3E8F5A913C39EE3DULL, 0x30981619EC9483EEULL, 
            0x04FA2D923CCEC232ULL, 0x88BD662477A623B5ULL, 0xD10B3766EA737132ULL, 0xECE06610F8EAC4EDULL, 
            0x35553B221C4EFBD0ULL, 0xAE9AA9F7BC0E6E20ULL, 0x2639D6E651B21F1DULL, 0x44CA2253FB7B6B66ULL, 
            0xB8546BBD24BBE6B7ULL, 0xF39E5FABD7D2D488ULL, 0xD7E5135642D31114ULL, 0x7F484952201F6D52ULL, 
            0xB8CFE466716D79AEULL, 0xEA30B35C9D2F5999ULL, 0xDEF877FBAE53D4A6ULL, 0x4F8DBB766DCCEAF4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bowling::kPhaseHConstants = {
    0x07227D3194D26289ULL,
    0x35013515413EC489ULL,
    0x8D8FD6AF0E2CE45CULL,
    0x07227D3194D26289ULL,
    0x35013515413EC489ULL,
    0x8D8FD6AF0E2CE45CULL,
    0x38FEF0D818B883A9ULL,
    0x59406EE4EF03A49DULL,
    0x6C,
    0xC7,
    0xC0,
    0xC3,
    0x2D,
    0x21,
    0x9E,
    0xC6
};

