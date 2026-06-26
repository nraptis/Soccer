#include "TwistExpander_Hockey.hpp"
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

TwistExpander_Hockey::TwistExpander_Hockey()
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

void TwistExpander_Hockey::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 13045211568869339784U;
        aCarry = 15678020157593156660U;
        aWandererA = 10301085213664936982U;
        aWandererB = 17988593548736226482U;
        aWandererC = 17430443392344086698U;
        aWandererD = 18021170248266097804U;
        aWandererE = 15102184419123642774U;
        aWandererF = 18440933167438810890U;
        aWandererG = 10547474594931229835U;
        aWandererH = 12891478751742284427U;
        aWandererI = 15251438849773059253U;
        aWandererJ = 15911988016998252729U;
        aWandererK = 16621964567850536231U;
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
    TwistExpander_Hockey_Arx aArx;
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
    TwistExpander_Hockey_Arx aKDF_A_BArx;
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
    TwistExpander_Hockey_Arx aKDF_A_CArx;
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
    TwistExpander_Hockey_Arx aKDF_A_DArx;
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

void TwistExpander_Hockey::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 9894243429398920811U;
        aCarry = 17013133415820364392U;
        aWandererA = 16846226017569889560U;
        aWandererB = 14215674049217226901U;
        aWandererC = 17104681015257246365U;
        aWandererD = 9884253580330599262U;
        aWandererE = 14914120132936999984U;
        aWandererF = 11683045311555242753U;
        aWandererG = 17873945073418388511U;
        aWandererH = 13066935110112472856U;
        aWandererI = 13258486484971325870U;
        aWandererJ = 13210880992698506162U;
        aWandererK = 10107148811014054559U;
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
    TwistExpander_Hockey_Arx aKDF_B_AArx;
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
    TwistExpander_Hockey_Arx aKDF_B_BArx;
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
    TwistExpander_Hockey_Arx aKDF_B_CArx;
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

void TwistExpander_Hockey::Seed(TwistWorkSpace *pWorkSpace,
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
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
    // KDF_B PhaseA invest aInvestLaneH (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneH);
    }
    // KDF_B PhaseA invest aInvestLaneH (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
    // KDF_B PhaseB invest aInvestLaneD (start)
    {
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneD);
    }
    // KDF_B PhaseB invest aInvestLaneD (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
    // KDF_B PhaseC invest aInvestLaneC (start)
    {
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneC);
    }
    // KDF_B PhaseC invest aInvestLaneC (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseDConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
    // KDF_B PhaseD invest aInvestLaneE (start)
    {
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneE);
    }
    // KDF_B PhaseD invest aInvestLaneE (end)
    //
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    mSnow = aSnowLaneB;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts));
    // farm
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
    // KDF_B PhaseE invest aInvestLaneB (start)
    {
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneB);
    }
    // KDF_B PhaseE invest aInvestLaneB (end)
    //
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    mSnow = aSnowLaneC;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
    // KDF_B PhaseF invest aInvestLaneA (start)
    {
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneA);
    }
    // KDF_B PhaseF invest aInvestLaneA (end)
    //
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    mSnow = aSnowLaneA;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
    // KDF_B PhaseG invest aInvestLaneG (start)
    {
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    }
    // KDF_B PhaseG invest aInvestLaneG (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    mSnow = aSnowLaneD;
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts));
    // farm
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    //
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
    // KDF_B PhaseH invest aInvestLaneF (start)
    {
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    }
    // KDF_B PhaseH invest aInvestLaneF (end)
    //
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
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
    TwistExpander_Hockey_Arx aSeed_AArx;
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
    TwistExpander_Hockey_Arx aSeed_BArx;
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
    TwistExpander_Hockey_Arx aSeed_CArx;
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
    TwistExpander_Hockey_Arx aSeed_DArx;
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
    TwistExpander_Hockey_Arx aSeed_EArx;
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
    TwistExpander_Hockey_Arx aSeed_FArx;
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
    TwistExpander_Hockey_Arx aSeed_GArx;
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
    TwistExpander_Hockey_Arx aGrow_AArx;
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
    TwistExpander_Hockey_Arx aGrow_BArx;
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

void TwistExpander_Hockey::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Hockey::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Hockey_Arx aTwist_AArx;
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
    TwistExpander_Hockey_Arx aTwist_BArx;
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
    TwistExpander_Hockey_Arx aTwist_CArx;
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
    TwistExpander_Hockey_Arx aTwist_DArx;
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
        TwistExpander_Hockey_Arx aGrow_AArx;
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
        TwistExpander_Hockey_Arx aGrow_BArx;
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

void TwistExpander_Hockey::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // read from: aOperationLaneA source quarters 0, 0, 2, 1 with offsets 7601U, 7524U, 1936U, 4630U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7601U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7524U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1936U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4630U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 3, 0 with offsets 7096U, 4685U, 2052U, 5195U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7096U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4685U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2052U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5195U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 3 with offsets 3871U, 4500U, 659U, 5525U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3871U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4500U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 659U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5525U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 0, 2 with offsets 6020U, 2399U, 5784U, 6566U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6020U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2399U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5784U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6566U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 0, 1 with offsets 779U, 603U, 850U, 1258U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 779U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 603U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 850U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1258U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 2, 0, 3 with offsets 1590U, 1711U, 1577U, 463U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1590U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1711U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1577U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 463U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 0, 2, 1 with offsets 1724U, 914U, 1800U, 298U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1724U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 914U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1800U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 298U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 1, 0, 3 with offsets 238U, 1820U, 2000U, 234U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 238U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1820U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2000U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 234U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1901U, 722U, 315U, 942U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1901U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 722U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 315U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 942U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Hockey::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 2 with offsets 3393U, 3760U, 155U, 3299U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3393U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3760U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 155U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3299U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 3, 3 with offsets 6970U, 4263U, 49U, 6044U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6970U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4263U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 49U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6044U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 2, 0 with offsets 7088U, 4371U, 5797U, 2965U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7088U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4371U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5797U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2965U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 0, 1 with offsets 6850U, 5425U, 637U, 6020U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6850U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5425U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 637U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6020U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3586U, 6205U, 7821U, 7729U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3586U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6205U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7821U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7729U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 2, 1, 3 with offsets 2021U, 571U, 1534U, 1649U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2021U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 571U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1649U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 1, 3, 2, 0 with offsets 1011U, 1669U, 855U, 1462U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1011U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 855U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1462U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 2, 1 with offsets 1623U, 1315U, 442U, 572U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1315U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 442U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 572U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragments 0, 3, 2, 1 with offsets 1357U, 368U, 188U, 326U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1357U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 368U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 188U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 326U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD [0..<W_KEY]
        // offsets: 1121U, 1058U, 686U, 1308U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1121U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1058U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 686U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1308U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseASalts = {
    {
        {
            0xED1044D667F79B8EULL, 0xDAFA154B432E6B3EULL, 0xDA4304A2EFB8ECF0ULL, 0xFF680F87D48F0380ULL, 
            0xF8E1BB4064683062ULL, 0x1BE43661A61B9B8FULL, 0x68CBF97D85AA8ABDULL, 0x2EE2AB3FAD191875ULL, 
            0x39F2F61408B9EE59ULL, 0xD646682E1F6576F1ULL, 0x7CA81DCF2FDBBB9DULL, 0xF455EA04CBF7F6FCULL, 
            0x96D0F59AA42347ABULL, 0xF3E7BD5FBBC7D388ULL, 0xF0233D21B747D35EULL, 0x4FBA6E7123C63723ULL, 
            0x11C78D2781DDFA42ULL, 0x845DE3651E6BB2B0ULL, 0x28F152BB4F222A05ULL, 0x8346671CE62F02F6ULL, 
            0xEA51822071BB9207ULL, 0x3846D6823DC00FB3ULL, 0x60C1361980AAB9E5ULL, 0x1F20A48B29619F99ULL, 
            0xFDEAF8E5BF05572CULL, 0xFBD4DFA8CE1A363AULL, 0xA72B4D28609D611BULL, 0x213F5B11ACA0DE15ULL, 
            0xDA6D41C7ABBF8F8BULL, 0x94E3C61D91B61BDCULL, 0x63A7A8439D369279ULL, 0x03034694FF7486EFULL
        },
        {
            0x3496C1206DDA8617ULL, 0x2A42EFE03E3B1A31ULL, 0xAC67E3323D4D1BE8ULL, 0xC74C20FDE0E43A36ULL, 
            0x874560F056EBA428ULL, 0x7D63A53D045B754AULL, 0x4EFA9C722CEF7F52ULL, 0x1F1801E25A86A5F7ULL, 
            0x19ED7AB0EEEB190DULL, 0x40E4249AFC989E5CULL, 0xC7DE6B188D3915A5ULL, 0x2F58F3B67E2871EBULL, 
            0xC38F033ED68BB521ULL, 0x06251BFB881E3343ULL, 0xDF097C5BECA2851BULL, 0x0FFF791708EFA0ECULL, 
            0x99BD4007EAA3D10EULL, 0xADFFD0E80D458653ULL, 0xC870E92304C54213ULL, 0xDADA2701F8A33A82ULL, 
            0x6519AB9B745C2927ULL, 0xB62A914EB80F92F2ULL, 0x710DB1BA044D577AULL, 0x8455F16F77F74968ULL, 
            0x242ADA95ACE69A21ULL, 0xA5DF50C9E7BACAF9ULL, 0x42EFF669403B1EDEULL, 0x5FAE183C8D20DBA4ULL, 
            0x7E18CC1CB1E63BCDULL, 0x012DD72772F09685ULL, 0x5BB3C48B424AE066ULL, 0x28B701136035AA11ULL
        },
        {
            0x73E9B4569381DF58ULL, 0xEC87E6943D4034A8ULL, 0xE39CA2AE97EEC820ULL, 0x6A8C3752AD3B2D76ULL, 
            0x18E177419404B9F8ULL, 0xC38739606FA74052ULL, 0x52F5745095C8231FULL, 0x83DB80C44B2B0E11ULL, 
            0x71D41438349862EDULL, 0x24F52FDEA002C414ULL, 0xE654D7963A433FA5ULL, 0x0E0379D270763904ULL, 
            0xF09417FB5DB98CB6ULL, 0xFF3B4528D60D301DULL, 0x24169DAE9F1D5F01ULL, 0x75FD247238881004ULL, 
            0x5DFC462D94D507A3ULL, 0x9A7A822A0904B718ULL, 0xFC7C252B49D899A4ULL, 0x72BC01BAB59C2FC4ULL, 
            0xC2EEE3D3724044E7ULL, 0x6D7D4BAC4885D98EULL, 0x680C896DAC9C4CCAULL, 0x6B689F0E8C2D3F85ULL, 
            0xD9381EA2DC15268CULL, 0x86B39A01BB7CC686ULL, 0x3EF6904DB189AF7EULL, 0xF00542DD0B96FFD7ULL, 
            0xCCD3CF2D736BD032ULL, 0xBE1D0604C78C62A6ULL, 0x276B7FAFC169899AULL, 0xA2668940DC416AFCULL
        },
        {
            0x5CC12622B6D143F2ULL, 0x4B1691F94CEF31C0ULL, 0x6BDD447A97D5A66AULL, 0xDFD4233D55A91F22ULL, 
            0xDC6AE3BAEA2D5581ULL, 0x04DAF5A99386E26AULL, 0x359B06F42E329F5FULL, 0x1BA47E7FDAB91CF8ULL, 
            0xF44CF7CFE28E613DULL, 0x79AAB3637F39D3C8ULL, 0x9936F83BECE0D384ULL, 0x35F41552D3031615ULL, 
            0x2E31450324B9FEEDULL, 0x044A6E48EFDEC4BFULL, 0xFA42EDB4208F4542ULL, 0x8C2511A0C12A27D5ULL, 
            0x162BB20CF3581FB4ULL, 0xEF56C321A98534FDULL, 0x85BBB55FDC1BD0F3ULL, 0x5F9BDBB0E8F4E939ULL, 
            0xE573023B95FDC7AEULL, 0x981E675763DE3990ULL, 0x888A9AA0A00B50A9ULL, 0xC27C61FD1FF99A08ULL, 
            0x2EC337434ABFF29FULL, 0xD1BC4EF18083FDEEULL, 0x4CA79391700D0C7AULL, 0x802BFC952502BC0EULL, 
            0x8BC18EFC83B37815ULL, 0x103EC005A71FF659ULL, 0x600C9CA18EE2499AULL, 0x2CB36483EEDD6827ULL
        },
        {
            0x3278C1B3E9BC41FEULL, 0xE3A9779C9F084DCBULL, 0x8C6E3E62722A2DF7ULL, 0x7F32FB23B6C826C3ULL, 
            0xA753BCB079EF2005ULL, 0xAD7C4D2579642DE7ULL, 0x3DEC7A4D1C95862CULL, 0x162E0FB298E43546ULL, 
            0x51BA28E5CECDBE13ULL, 0x276AADEC5223D7A1ULL, 0x85EC8CDBFBC20E24ULL, 0x1635BF9D31042ECFULL, 
            0xB1BA740674CBF13DULL, 0x9282EBBC14DAC38AULL, 0x2932B868C81F4408ULL, 0xE0FB83AD3EF25272ULL, 
            0x716B21E6C24C13AFULL, 0x7DA418F5BC5CCEB9ULL, 0x37270BCC53E6A4A9ULL, 0xD45E51158088F2ABULL, 
            0x33D5063557441220ULL, 0x5AA2D5FB9FEE3C7CULL, 0x4905C41C2E89B462ULL, 0x7A4081152DACC4DEULL, 
            0x46561C8B06CC5E81ULL, 0xB6F3A4DCB78AB1B5ULL, 0xA7FCBF281235891DULL, 0xBFAD5225BACA7BBEULL, 
            0x19167919D0F2BB95ULL, 0x79DF62FAD7E871A6ULL, 0xA95527794868BAB8ULL, 0x04EA93D9C2E410C9ULL
        },
        {
            0x7C30FB51442B2A32ULL, 0xCF0CC867A154BE97ULL, 0x9C820209A8A80C5CULL, 0xC28ED2288C834CE6ULL, 
            0x01E8E55664C5F7D7ULL, 0xBBC0927B24BB253CULL, 0x3A2CA69ABFCE49E5ULL, 0xB241AB7F6B02B9F5ULL, 
            0x5097D21EEA63DE77ULL, 0xFD79BD9B49CA47A2ULL, 0x304857EC066136C0ULL, 0x069AF173AC8BCFCDULL, 
            0x221F1A9238145E42ULL, 0x4F3E0BF79BF7B293ULL, 0xA9344FA620E9E9F4ULL, 0xA83B42F7B6664950ULL, 
            0xB6299ED778D3D0EFULL, 0xD46F83BAFB51A311ULL, 0xD02570F60A014599ULL, 0xB83FF77A9E67672DULL, 
            0xBA510024C70EC321ULL, 0x0AB16C397A7783DFULL, 0xD4A2B4771B45FB0FULL, 0x9935B2ED09F34B55ULL, 
            0xBA9D6DF11B1D17CFULL, 0xD7CCC0C95F5DB0A0ULL, 0x77934DFAC9A97C14ULL, 0x05393EE5161D8235ULL, 
            0x2F56F33E4C48EC9AULL, 0x58D407C73769A5C3ULL, 0xE13BBD36E8EFE4E2ULL, 0xACC9D38737E9591BULL
        }
    },
    {
        {
            0x82A60BABDFD84248ULL, 0x7C2C941EAD8398FAULL, 0x5CF3DA3A852C9382ULL, 0x72AC37C89F117D6FULL, 
            0xD04CC703A5AC3252ULL, 0x76153555F6008DEAULL, 0x2F680506410BCFE2ULL, 0x501649BFC6FCB752ULL, 
            0xF8A7D87C7BE96C90ULL, 0x8F9383555666A63EULL, 0x2D38FA9DE7BCE9E9ULL, 0x76DEDD5872046A84ULL, 
            0x618592B8DC6098FEULL, 0x07E1F429AA56BC74ULL, 0x8A3BBBD439E9A025ULL, 0xFA2435EAEB3BB11FULL, 
            0xDE8DE378E4F247FEULL, 0x8EF28AA95FC2BD01ULL, 0x3AA4F87C2766624EULL, 0x7E5450187D12B51BULL, 
            0x069BA5B9D6E564BDULL, 0x22A67E23F2E49C15ULL, 0x893DFC8D1C485657ULL, 0xE37D67DC295CD2EFULL, 
            0xF3D175DF46471B62ULL, 0x46E1FA17A6756FD4ULL, 0x5E90E68A884BFA91ULL, 0xA807CCDADFC87B5AULL, 
            0xFE762BB05494662EULL, 0x2660AC37BE3FFBDBULL, 0x3532149EAFF351CFULL, 0xCDDC824C7DE64E30ULL
        },
        {
            0x6A22486583EFA595ULL, 0x2ADDA4CAF0AD2033ULL, 0x6530CA7B29743712ULL, 0xE376F55598B5BAE3ULL, 
            0x676B57D500ED5553ULL, 0xCAE283374026B867ULL, 0xB96498F59A890698ULL, 0x376E16755C2ADBA8ULL, 
            0x8AD5E5E15946F472ULL, 0x8F892A6739A5C0CBULL, 0x99B23AAA06E88DEBULL, 0x448644781149D8F3ULL, 
            0x5376E35B3D570AA0ULL, 0x63F36C48872AFE39ULL, 0xA7228973919B2EA8ULL, 0x0DD193A64073DB20ULL, 
            0xFCBF05678F00868BULL, 0x3E4BB2DEE9843710ULL, 0x8F96E7A78985B68DULL, 0x098EFC5B198059E4ULL, 
            0xD4122615CE5189D0ULL, 0xE65AD9F1672C5CFEULL, 0x99503670F03D958DULL, 0x50D6C0E9C7F152E1ULL, 
            0xD21720E9D16503ABULL, 0x187BCAAEC35D0700ULL, 0x7061CF19734CDD53ULL, 0x5C479180008192C8ULL, 
            0x791C071CA753579CULL, 0x6645CD867528A3D2ULL, 0xEF41EA1D72D34950ULL, 0xC8AEB3CD970C766CULL
        },
        {
            0xAE8B6DB4E9091429ULL, 0x5CF686DB8EE45427ULL, 0x2534594787F32F0CULL, 0xD05E1E87C11FF87BULL, 
            0x71BBD0E0DAAD7FB0ULL, 0xEA3D0BCBCEEEC633ULL, 0x1694EF9C6A0D5333ULL, 0xF88FB205D1AE5390ULL, 
            0xF9748D4FE4120A75ULL, 0xCFC18DF3980642F3ULL, 0xDED42A1470D2A769ULL, 0xA382B488A1460AE8ULL, 
            0x68D345E766C1AAD7ULL, 0x599C2248106538DBULL, 0x2BC70A6231AD01AAULL, 0xDE92F11EF796D37CULL, 
            0x881C5A8201DB077EULL, 0x30F8F767B8E0F274ULL, 0xE362895806EA3206ULL, 0xF8F8571B9F68DBF0ULL, 
            0xE9349A8C2E007AEAULL, 0xBD7AF8E4A6E511F2ULL, 0x3E194E13B5865315ULL, 0xD99B42D0FC8B462AULL, 
            0x342199A81FCE833BULL, 0xA2ECE8AAF6322075ULL, 0xDAA10D03FB53A7FCULL, 0xEF41C92243379081ULL, 
            0x87D81B3103BFB112ULL, 0xADD79D115FC5596CULL, 0x1396E2976D1026E7ULL, 0x2A15DE4673086229ULL
        },
        {
            0xE055921FB981D9E3ULL, 0xC257A2FF054E53C7ULL, 0x33F367F5449ED681ULL, 0x78012EE41901B31BULL, 
            0x1E13F6497276BFBDULL, 0x0632621654FEDA59ULL, 0x54C8FAFA27193E2CULL, 0xE4B2A22ECACBF9B8ULL, 
            0x8101F94C69D39994ULL, 0xFB4F44379E4A6362ULL, 0x78F6D456576DC71DULL, 0x044D5EE798AEAABEULL, 
            0x72F0B0516BFF9DEDULL, 0xFDAC701E5C4EEB13ULL, 0xC6727101EBAFD806ULL, 0xE2C623A42554B24FULL, 
            0x16019D70EF4E9BE1ULL, 0xD5E51F6E8C3ECBE0ULL, 0xB9FFF8609341AA38ULL, 0xADF4CC511081F3BEULL, 
            0x9982B21EC9EC5FBEULL, 0xA2E64CE1B2317AB2ULL, 0x2FB23D024B03C0BAULL, 0x4D26F78E9E58A502ULL, 
            0x149985447DA6EF57ULL, 0x6D955D95B0F1569FULL, 0x108A6827C148543AULL, 0x6F13582BD8E5F052ULL, 
            0x50EE6C04D198551CULL, 0x0BC7A1CA4135E444ULL, 0xDBA3DD836D5F8B65ULL, 0x04774DA595E65375ULL
        },
        {
            0x3C35E2FFA6B788BAULL, 0x142792B7FBCAD3F8ULL, 0xA947BF279ADCA49CULL, 0x20BE26D9E321642FULL, 
            0x4BC27368F9CB80A9ULL, 0xCA882FCFE47C9F74ULL, 0xE1688E6719811227ULL, 0xC9997E66C4176CE5ULL, 
            0xD10F52274DF62BF6ULL, 0x4CACD0BC85EC1E07ULL, 0x7D5C1D034882EEC6ULL, 0x760DFE56C54E153EULL, 
            0xE9DAB9694DFCFC2EULL, 0xFAEF9C856DF94A3CULL, 0x78272772F50229D2ULL, 0x8DB7FC442544C0DEULL, 
            0xCF4828433AF3144FULL, 0x763FEAF5990910F2ULL, 0x92C7799E2ACD922AULL, 0x961569794D7D0FE3ULL, 
            0xCC76D183D887D3B3ULL, 0x66966FEC3E77A6F6ULL, 0xB73E9911ECD56671ULL, 0x66E7B4BF3586DC80ULL, 
            0x6183D11AE82CD5C1ULL, 0x2C6216DDB493BAC8ULL, 0xBCAB8355FA9ED787ULL, 0xE014F0DD2F701059ULL, 
            0x272B68C9A0AAC728ULL, 0xED981764C648B69BULL, 0xE2BC759B6B5063F9ULL, 0x86536CFCEE03688EULL
        },
        {
            0x8A17BD17B466DE5EULL, 0x8727D3F73330B461ULL, 0x8D0D163C78836F47ULL, 0x2E67F903AF911F9CULL, 
            0x25FAE02223EC5692ULL, 0x228BD5CE26045D22ULL, 0x13D9AAD992750BD2ULL, 0xA6F93B3388D705D2ULL, 
            0xD56FA9CCA031E5C0ULL, 0x8A2E3930F35A4A07ULL, 0xD6318003E5054742ULL, 0xD957F1B3394366D5ULL, 
            0x2979254701942DFFULL, 0x209FF8E178F806CEULL, 0xE25488A1F4D0A55DULL, 0xA34F0924D02F1224ULL, 
            0xAD1BE36BC3B8B012ULL, 0xD2A596D64B1A0A3CULL, 0xC17EA1805F88AA42ULL, 0xBCAEBC929EA421D4ULL, 
            0xCFFF77C1B0E4F38BULL, 0xF454A25E13672AD3ULL, 0x82A9109B68876AD3ULL, 0x0B3898F3A332E9B5ULL, 
            0xECAE183077D16B39ULL, 0x3A43A5F13CCB2A1AULL, 0x1DA32F67CBFC7946ULL, 0x297D81823D97BD2AULL, 
            0xF4691350B31DB82CULL, 0x1C2802456C32B77EULL, 0x99B5DD472201B8A5ULL, 0xB709666E56F066F1ULL
        }
    },
    {
        {
            0x65B945F3DFC79E40ULL, 0x59135798B7ECC022ULL, 0xE34E5AC41FE07167ULL, 0x3CFC12C332CBBA00ULL, 
            0xE27AA965A6821429ULL, 0xB4872222A8F0B65EULL, 0xAE430BEBEE9B3C4DULL, 0x59B8AEA4122AABC7ULL, 
            0x8553476812A9B95FULL, 0x24EC0EEA5DBB1BDFULL, 0x65F25941AEBEA838ULL, 0xAB8C942F9782A1CAULL, 
            0x7071D5793FAEFFF8ULL, 0x3513043E20FD8479ULL, 0xEE8187C007DFD574ULL, 0x4B02D89BD4A0A162ULL, 
            0x93DABB8841136258ULL, 0x1BDF9A66AD96754BULL, 0x7009365B54D03A03ULL, 0xF497F0AD02D0A83EULL, 
            0x772B50FC8A2BE3E0ULL, 0x78028359586E8FEEULL, 0xA0DBB188C1A383CDULL, 0xD0921DD7B9FAA457ULL, 
            0xE42140C82BD0C88DULL, 0xA416E97CEED2B7C0ULL, 0xC5E075F8B4E430E9ULL, 0x30D412619F68F446ULL, 
            0xD0979EDF4E1C35D7ULL, 0x97792C0A211DFAE3ULL, 0x2118F24B6AF098BAULL, 0x7D1FE7492C730067ULL
        },
        {
            0x8DD00CA7C2C1D92EULL, 0x39D49D66B760AF73ULL, 0xCD910CB06F25F162ULL, 0x9D85DCE7820855E8ULL, 
            0xD7618776122F0750ULL, 0x91279790A95565ADULL, 0x38B2740D23392BA7ULL, 0xD88E4CD0860156EBULL, 
            0x2AD36E0533711AC4ULL, 0x04C2672ABBA8A55EULL, 0x7ED03A57A11D493CULL, 0x10BE555AE4810B80ULL, 
            0x41E836D9DDC9FB63ULL, 0x28CA5BB802744397ULL, 0xA839579B3F3D6D22ULL, 0x95003D8F8C9C82C6ULL, 
            0x4927A486276523F2ULL, 0xFC78B21E0B9505D7ULL, 0x093B3B9839C1E922ULL, 0x57FF8D88565ACA18ULL, 
            0xC751CE2596981ABBULL, 0x15679A74CB9DDB86ULL, 0xEA1CBF16B34E2176ULL, 0x1B97A165FE3254D7ULL, 
            0x4015839F47EBC844ULL, 0xB9E1F0D204C335AEULL, 0x1C7082DD27EF7880ULL, 0x106A04F3B1E60A0AULL, 
            0x8F3E89AD47E55712ULL, 0xDACC7585C3EBBA8CULL, 0x7790DBCDFEA38840ULL, 0x6E3F551504558511ULL
        },
        {
            0x9F91393DEB0B4B6EULL, 0xBFFB7047D09B5DC2ULL, 0x6800F7005522B223ULL, 0x3139FB2A06171741ULL, 
            0x3EA05593F83756D3ULL, 0x05010937F859160EULL, 0x63BBBEC46BE0DA05ULL, 0x1B451A1BA8ECB680ULL, 
            0x5D5692477085F936ULL, 0x662577EE0A9124D3ULL, 0x22374EF68F7DB317ULL, 0x30A1A854052BA2B8ULL, 
            0x4B31D71511C12848ULL, 0x2BF2447739D62202ULL, 0x74AE53810D79A0A0ULL, 0x06F89B16BFC40D58ULL, 
            0xD922BC903911CB65ULL, 0x28A01C2FCB81E0BCULL, 0x3F3B64D8B2654382ULL, 0x3274A5A4E45C60E8ULL, 
            0xBE04039257833EBFULL, 0xCC48B7A45CED031DULL, 0x264001FAF0EC3744ULL, 0xDE9AE8D88ED5C34FULL, 
            0xE28ED9A5469C7621ULL, 0x225CF7BB8A4CE5F5ULL, 0xB33F6624F69DEC07ULL, 0x1DD40DDA24A8E5E2ULL, 
            0x0F185D44D379751CULL, 0x40482ECE61A50FF9ULL, 0x580F4B04856BE94EULL, 0xE2A46D6C4593502CULL
        },
        {
            0xFD304916E7C5524AULL, 0x36AE2A8EA51A4DA6ULL, 0xF9C40636E28FCCDFULL, 0xA53BAE0D72C92B2CULL, 
            0x8EF30898B09C8093ULL, 0xADAFA4F1781569BDULL, 0xAF975B495C354DCFULL, 0x14A53195E0BDCE63ULL, 
            0x83EE17D2CCCDD41FULL, 0x03F23F6EDA9AFF6FULL, 0x989E1399108EE872ULL, 0xB9D543B96D1F0B98ULL, 
            0xC991A2D639CA23BAULL, 0x9F12D82B182EC2CDULL, 0x78905FF2E8E883D7ULL, 0x15423150850E2373ULL, 
            0x96AF07B9C34E9385ULL, 0x43FC4F1DAD5B87BEULL, 0x150D167D4BD8BE10ULL, 0xF74AC6F3EDDCD6DCULL, 
            0xDBA5A34CF7A6EE0CULL, 0x12FA418ABCD79D22ULL, 0xC540D1035B1EDA91ULL, 0xC85048254030CBFFULL, 
            0x76856526534E4598ULL, 0x9DBD975756F9CD54ULL, 0xD2B6D985D2865540ULL, 0x865A2855CA32D117ULL, 
            0x4D30C2A170CB1D09ULL, 0xD138BDD84FCEC4D4ULL, 0xAF69E0CC9E08DFDCULL, 0xD0EA211AC56AECF8ULL
        },
        {
            0x5F69EEF937A01266ULL, 0x1661E01A5F02F4F0ULL, 0xCFE6E74691A6C94EULL, 0x5660E28435D9D7FEULL, 
            0x5EEDE0B40167CA90ULL, 0xF7A1B6F1C8E6F0EBULL, 0x4C1AD2142229BFACULL, 0xD03A2BBC42BF3960ULL, 
            0x1520DDA42C6F2253ULL, 0xE09D0CC4D3A378D3ULL, 0xFB2F957771A4561FULL, 0xBF49559E0A5C5529ULL, 
            0x733326A8ABD6B617ULL, 0xE44EE677BBCA18D3ULL, 0xD6BD6B68B42861BAULL, 0xD7AE3077F62C431DULL, 
            0xB76B03782DF77081ULL, 0x2581F0189A904B35ULL, 0x2C33DA615B66058DULL, 0x2B0B2F151BEDB430ULL, 
            0xA87A04D2E960021DULL, 0xB73F71683BF6D863ULL, 0x69B7737C3332D694ULL, 0x4AC0023864A5130CULL, 
            0x6B892BBCB8CBAC85ULL, 0xEF5607A3A159BD56ULL, 0x7A1615075DC721D7ULL, 0x93F6DC1C988DA9CCULL, 
            0x178C450626BA351FULL, 0x4C00815082F99C20ULL, 0xD4352E4D6B225237ULL, 0x99CF4FAA3C8D23ACULL
        },
        {
            0x9AE73E2E9E12B45DULL, 0x139DE95C397C69D2ULL, 0x11C7097F4B6E5E01ULL, 0x5C8982C780AEB36BULL, 
            0x3EEA2293B911190BULL, 0x3D67BDCDD9DE907DULL, 0x7F8625509156EB14ULL, 0x9C4FBDF2FEFB9F7DULL, 
            0x1BC1016E29BB549DULL, 0x90C0A183E09FF3C8ULL, 0xE1C003F35DCEAF61ULL, 0x8EBE605BBE5EA168ULL, 
            0xC2D6551335DFB58FULL, 0xF8DF4F28DBB20A52ULL, 0x96F47A5C5DEBB725ULL, 0xF7614EEC64D76690ULL, 
            0x1366042F20D0528AULL, 0x683CD1267274B188ULL, 0x02AC0174E875F08CULL, 0x0029BEDED87C43BCULL, 
            0xE9D77289FCF1F368ULL, 0xEC3386474CEB98C9ULL, 0x9CA3E53A4A70E479ULL, 0x26831D80D87BA139ULL, 
            0x2928FEA1A78BFF30ULL, 0xA1A3038F99568DD3ULL, 0x0CA9DD5FAEEC4464ULL, 0x17FF02557E8B72E6ULL, 
            0xE09E046398C5DA7CULL, 0x2D16FF351B4CECE2ULL, 0x841F2D54517D8C0FULL, 0x9BAE1B0F741BAD06ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseAConstants = {
    0x7674492D83A04379ULL,
    0x1A20E3FF4FBD001FULL,
    0x03E0006A11AA9847ULL,
    0x7674492D83A04379ULL,
    0x1A20E3FF4FBD001FULL,
    0x03E0006A11AA9847ULL,
    0xE3DE021BFF18A2E9ULL,
    0x30FE22AAC45529C9ULL,
    0x15,
    0x5D,
    0xA9,
    0x09,
    0xA6,
    0xA1,
    0xF5,
    0xD9
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseBSalts = {
    {
        {
            0x4BE7D8A5DCF44F67ULL, 0xAA1AB4D0BE7C0717ULL, 0xBD188753F1799CABULL, 0x50C77514FED879DAULL, 
            0xB7EFD71DD9D898EAULL, 0xCCB1936F128E6FD8ULL, 0xC4354517CE232C27ULL, 0xB013FDE55FB88CACULL, 
            0x44BFD9A66070530CULL, 0xA938E3EC38B2E259ULL, 0x3034D6BF8929B283ULL, 0xF94E53D5D9B621BBULL, 
            0xC85E129AC58389B0ULL, 0x6C320233FACE3DE7ULL, 0x815F1F687914BAA2ULL, 0xBB2FDE8C7FC0FBB8ULL, 
            0xF8BE689702D20573ULL, 0x28E27F52A36EB280ULL, 0x7BE8CCA075D9EB04ULL, 0xAF03B1B260B3C377ULL, 
            0xFDDE1510047E4062ULL, 0x57E6020B06E64361ULL, 0xC487099708C50CEEULL, 0x1F5E5C31A537F2C9ULL, 
            0x26FB7D12F96CD7FBULL, 0x5C4C10FEC815D916ULL, 0xAC1E3D8E2CC869BDULL, 0x933E46B24BBCA666ULL, 
            0x417ED257946361CFULL, 0xB2248EA687393D39ULL, 0xA95EB42BDF9005BDULL, 0xB96A6BDCD8DE0C2FULL
        },
        {
            0x91551F5F6F3A0BD7ULL, 0xFF1B3F3B0856E913ULL, 0x5A9EE14095AE7CA5ULL, 0x952F0EFE3EBC400FULL, 
            0x28F4501EF1651C39ULL, 0x686C9715A341B73AULL, 0x3D33F0BE7C138F33ULL, 0xCC3C0300E0A6EBDEULL, 
            0x754EB47387327A26ULL, 0x2EF363D1D9015E34ULL, 0xDC86136A4C021369ULL, 0x4A7DE870B60C71EFULL, 
            0x37D782EA2D33AC06ULL, 0x74CABB52DB3AAE9CULL, 0xCB862C09F5AB18C0ULL, 0x116131AC975E870FULL, 
            0x8350E50440C62BEDULL, 0x3AF46F41FE58110AULL, 0x22A27EE2317BED95ULL, 0xC83E5866C546D9CAULL, 
            0x1879B1A155B28EA2ULL, 0xDB24EF979C042F59ULL, 0x6BCF57E73E265ABAULL, 0x785D5AF00FD3F507ULL, 
            0x8F9DE1CA18D01B38ULL, 0xA93A946538C6F864ULL, 0x7D50B51FB498F458ULL, 0xBE6C015AB2251D49ULL, 
            0x80C1D92A711DF11AULL, 0x32CF3390259C3278ULL, 0x047FF329D9B5C3C3ULL, 0x2031C115E131AA61ULL
        },
        {
            0x0CB5B84339C88E21ULL, 0x94FE60A1112DF046ULL, 0xCF6AB7F9973FBBEEULL, 0x0EE4128E3C0E1E0BULL, 
            0x13C54D6B110B2557ULL, 0x0FB7459AB7767F05ULL, 0x463BF03EE02C6B67ULL, 0x2B44F3DA6B1C447EULL, 
            0x19858CD90A0BCFABULL, 0xD7B46A599180CCDEULL, 0xD5E4A9C389FBF33AULL, 0x09EB27D118B8838BULL, 
            0xD8017059C6A8F0C1ULL, 0xC66B8ECB82CE8E22ULL, 0xD96DA37A15A75387ULL, 0x2B0F641FD2BB4F31ULL, 
            0xA0A129CFAC43E3A6ULL, 0x480F63EDDDB86B8EULL, 0x2CD9C09283CD4B37ULL, 0x75BCDFE6C5D0961FULL, 
            0xC17B5CFF51B4E031ULL, 0x0E3D31DB8CCFD25BULL, 0x2FB7D3D26B916C70ULL, 0x0774EC9941993848ULL, 
            0x7FACEEEACE560124ULL, 0x48037D4EE75C8CBBULL, 0x11D37AF7E5A68A5AULL, 0x293AA882009660B8ULL, 
            0x5CD55E877C59179DULL, 0xA993DD39ABD4DDB9ULL, 0xE02DF824FC601BB5ULL, 0x50E458EEB7EE4FE2ULL
        },
        {
            0xFDFE8C6F99693023ULL, 0x7F348750274E825CULL, 0x40ED9AD5D6279B33ULL, 0xF43894E72F645D95ULL, 
            0xBE83FB6CB662513FULL, 0x55D0386B40A3D1A0ULL, 0x59D40EE30565E164ULL, 0x1702E7ED29A2B524ULL, 
            0x58AAF7925EA7F5EAULL, 0xA7417E3E82B48E3EULL, 0xEA769620C6B8D0EBULL, 0x8FE9E5E55C0EA41DULL, 
            0xBB985E3B3BF96F43ULL, 0xEE094F64C866737DULL, 0x854071A265241446ULL, 0x2F56D7FA82222A38ULL, 
            0x5BC8E284274F6809ULL, 0x72C8FE46A88563A0ULL, 0x6EE7C87AE43C5869ULL, 0x3C404D7316EA31B2ULL, 
            0x87121E7470A17715ULL, 0x44B428EE6E634A29ULL, 0x06D27A78F39F5AC3ULL, 0xD7D024FDD315BBF8ULL, 
            0x3688DB9B180A2988ULL, 0xB0D82326ACF401A0ULL, 0x81C358E0C11459E8ULL, 0x88237B14AA214472ULL, 
            0xC3B18ECBD357DE77ULL, 0x3FF57BA44F59B730ULL, 0x4CC1A1953701558CULL, 0x95FC0E5731B7262EULL
        },
        {
            0x1EE8B358ACBF3C0FULL, 0x64F7CD1EEFC8CF90ULL, 0x8A369403BCE15FE3ULL, 0xB0930E2F8CB55350ULL, 
            0x08A81D1B3FFC21A0ULL, 0x4A6FC3017C6CB685ULL, 0xB827A9A6DC9138FFULL, 0xCF343AB882710CDAULL, 
            0x6A45523F708E0CB3ULL, 0xC23F33E78024C357ULL, 0x95D8BEA8EEC547BFULL, 0xAC9B149043943521ULL, 
            0x7CD36F5819F2CFFFULL, 0xC4A26011C593F7EEULL, 0x474AD3B4739062B3ULL, 0x4B153B0B8C80B1F7ULL, 
            0x740DC2D3411AEB7DULL, 0xF5A81A395C2D5594ULL, 0xC074A1D034303554ULL, 0x573AF219C3F7843AULL, 
            0xBB435110151847A4ULL, 0x686141BED5BAFB95ULL, 0x3C78599A7EF33AD2ULL, 0xD39001CA890103A6ULL, 
            0x99BBE8D2CEF546E2ULL, 0x741029A2DA3AFD99ULL, 0xB61A9420FAB43A3CULL, 0x42C49B0A82831AA9ULL, 
            0x9F7A9A0D96C27D61ULL, 0x3AB7577EF1242AE0ULL, 0x86701351AB92E40DULL, 0xB0A7DD8651CCBDB4ULL
        },
        {
            0xD7CD08EC758DF4AEULL, 0xF21516FBC1E76E57ULL, 0xCD01A44CD7C63EBBULL, 0xE0F313DD8ADEADD7ULL, 
            0xDF68E571742E6976ULL, 0xFAC5C46CEFBC7A7CULL, 0xBE93BD2BB3D8AFAEULL, 0xE2490AC39E552F66ULL, 
            0xD5E688621DDF4A68ULL, 0xCB721D31BB08DC56ULL, 0x7A7188E95AB5B022ULL, 0x99C1256A5222687DULL, 
            0x4CE2C0692038CFB4ULL, 0x498E22CA228E2F38ULL, 0x97154EAC2CB51088ULL, 0xA1B21213CC1E368FULL, 
            0xDD2DA693AAFA33EDULL, 0xFEA87924C0F83CF3ULL, 0x9F748467742925A0ULL, 0x311DF5C0BDFF20F8ULL, 
            0x03FD4480A39B37CAULL, 0x240A77887271CBBBULL, 0xC463C4EDD0B9F274ULL, 0x031FF556B8E6F7F5ULL, 
            0xD307BE91AFA074D1ULL, 0xDD2438D66CD8570EULL, 0xB771D5AB2F82BE70ULL, 0x342EE4C7C4C31441ULL, 
            0xFC35F7D90E05383DULL, 0xA140C7D429B8CAA8ULL, 0x17C6288E246ACC88ULL, 0xE71469587F706F5BULL
        }
    },
    {
        {
            0x0C13848E5F958852ULL, 0xF327D5C3FF4F4A25ULL, 0x0DE234B9635C568DULL, 0x65CFD151A0466323ULL, 
            0x865493F08C44E480ULL, 0x862C55FB646191E7ULL, 0x8866E0B480977940ULL, 0x1A6F504C3D140D22ULL, 
            0xBD5FDB5EBB040944ULL, 0xCCD5D842277B11E1ULL, 0x0EB8940D14C279BEULL, 0xB94E6B13EB587451ULL, 
            0xBB2CEAD112457D8AULL, 0xFE5BCA3F5A592B10ULL, 0x7684C223E355B610ULL, 0x08BCDB4E91078FB7ULL, 
            0x36AC3CC69BFD9C51ULL, 0x347C06B485A6CD18ULL, 0xD4743027198567C5ULL, 0xF70CB8CE786014DDULL, 
            0x8A6258EB633F3171ULL, 0x37030076C2C044B1ULL, 0xB724DB12885985E7ULL, 0x912C9C998A4E8302ULL, 
            0xBF8875651D81CF49ULL, 0xB288AEEC62B19430ULL, 0x78EE0D8533DA7D2BULL, 0x676366D3E1820F5DULL, 
            0x58B9CF074F115604ULL, 0x08B3F575251AAF28ULL, 0xC43F0078D3E74553ULL, 0x6FF4C1BC2A19AC92ULL
        },
        {
            0x5849273D467B9512ULL, 0xCF2B0DCB2E7150E8ULL, 0x3EB647E1892998D4ULL, 0x14D3DF3A6C32A310ULL, 
            0xAEDC213207620741ULL, 0x92989057D4E3EA12ULL, 0xC2FB9F2D6E671727ULL, 0xF03965EC99FF55F0ULL, 
            0x33DDAD475EE96F95ULL, 0x03CEF4E32F2A12D2ULL, 0x84A4CCBDD413B257ULL, 0x62BB353384A1A49CULL, 
            0x130724346B6FDD38ULL, 0xA58A6C0999E6870DULL, 0x91F38049F27362FEULL, 0x57DA4F6CAADBDA81ULL, 
            0xFFCDF9FF1BC18675ULL, 0xDB12C1507443A384ULL, 0xC0C3C2B1AA254C05ULL, 0x2CDCA01557F05B06ULL, 
            0x4DB0231FEAE5305AULL, 0x898ECECBDD079E1BULL, 0x6B931F2C86226FC0ULL, 0xA27811A9BF099224ULL, 
            0x82FED54D904DD5D9ULL, 0xF53EFADE3163DD01ULL, 0x432E758BCE1E0446ULL, 0x94141F2532F4D54EULL, 
            0x69E65E6206B478A5ULL, 0x76B3EDA56A998345ULL, 0xBCB62576741E59C2ULL, 0x436415BBE09DCE04ULL
        },
        {
            0x4658EBA878EEF65CULL, 0x81B84E52CA7C7B77ULL, 0xD5183DF0F6BC8513ULL, 0x8E9CC39392B0907AULL, 
            0x7547796CF888A28CULL, 0x12ACB4734573C5FFULL, 0x663B59FD2D88D466ULL, 0x5387B09C607FD984ULL, 
            0x2EFE49B4EB370A3FULL, 0x1A9E7FEB767B6026ULL, 0x6EB98CD256E28189ULL, 0xC295274322BF3487ULL, 
            0x3B7FF8C992BF527DULL, 0x1A0DA708669048A1ULL, 0x25BDB6FB07F1AC3AULL, 0x60AC07B1D5309F76ULL, 
            0xF1CEA28AF74E95B9ULL, 0x27580CDD1D03D0E5ULL, 0x45CB5068212C4617ULL, 0x82308DEDD4D8DBC1ULL, 
            0xF2EB5E75483856E7ULL, 0x8449EFF045BD83A2ULL, 0xADE13D61E4BCC8E4ULL, 0x0B1A912BE84BD396ULL, 
            0x3DBCE14C8810528FULL, 0xE7586074F43D30B9ULL, 0x0F486DD47F275730ULL, 0x5D7CF7AE244ECD2BULL, 
            0x77A72745B6A12069ULL, 0x918E5DF14F9FC53EULL, 0xC4E9CF968983E5CBULL, 0x9272E7F211D7D1A8ULL
        },
        {
            0xD82C308CF85CDD45ULL, 0x9D9295420B76C182ULL, 0x630E097938A44ABEULL, 0x9B9B9BDD6AABA351ULL, 
            0xF79F66B42933E529ULL, 0x9563AA83AF32B949ULL, 0x4D9DAE3A556437BFULL, 0x3EC6DD83E0F5B9CFULL, 
            0x0FAEA75A3A69CC83ULL, 0xB36D744906A261A1ULL, 0xD5C29E2476CB37E2ULL, 0x4456D27B963AF7FEULL, 
            0x8B3880E2B654E09AULL, 0x0123935684032B9FULL, 0x81DA50E740C7DF93ULL, 0x63E75A15C68AEE13ULL, 
            0xB9E4D2E83F9D0D83ULL, 0x4F69FCD2C743DC07ULL, 0x9338AFD7D2A3D823ULL, 0xF60B3EF3B3F366E4ULL, 
            0x0F1811ECB026D636ULL, 0xCEC0AAECD692DC4EULL, 0x469178B1560AA9DEULL, 0xF2DD9AE67EAE4090ULL, 
            0x55D026936F7345CCULL, 0x00E72DF4F8795801ULL, 0xD4D291BD860B55D6ULL, 0xDAE1DEC0644CB29EULL, 
            0x8CD0882B99E0BDFAULL, 0xD4140E05B9CBFA12ULL, 0xC64D8CE786D9EC9EULL, 0x7F40925B27CF65CAULL
        },
        {
            0xCF728754A083DE28ULL, 0x0F65764803D40809ULL, 0x79536460FD8BCC4FULL, 0xDA648AA1DC740EDAULL, 
            0x1AC0DF8914228410ULL, 0x0DB3C61D0B7A9883ULL, 0x66C2EDC8FBE6724CULL, 0xAAE25485E69CDB15ULL, 
            0x1BA4763D6B2D7339ULL, 0x4DBE1378FDEDD90DULL, 0x8DF062820C9DF56EULL, 0xCA74081304D70D9EULL, 
            0xC77EB24B6E4F165EULL, 0x5D62E032C58C7DEBULL, 0x8A471CF661688D47ULL, 0x6309A5F1E6A55CA5ULL, 
            0xB5365DCEE767036AULL, 0xF3C7FA901D804C98ULL, 0xC69AB14F6DD9FEA2ULL, 0x1C7F6B022E91E399ULL, 
            0x2798927D09323F01ULL, 0x0E2CEE02595E5C97ULL, 0x087629E5122BC136ULL, 0x14DBAAD2F7204D75ULL, 
            0x076B50DBF4B78C62ULL, 0x7F38AF8A2735005AULL, 0xB636DB21DF466821ULL, 0xA7B7B0A8463CDF7AULL, 
            0xBF3D18D16FB40A70ULL, 0x038754E6AB31A44BULL, 0xE7DBE8F3CF3E3EFBULL, 0x5FDECC62A708A2E4ULL
        },
        {
            0xCC538E4AE349667BULL, 0x6DF3308AAF30EBA8ULL, 0x287B686350340741ULL, 0x71405B7739FB47D0ULL, 
            0x7940D0EBB6016767ULL, 0x2F04A8F8878E16E1ULL, 0xF60BAA7CBAB57D22ULL, 0x962B762FA5AF991AULL, 
            0xA0B875D629C92DFAULL, 0x68EF3AD1A134A8D0ULL, 0x8BA375C75D28C580ULL, 0x01FC3530CB670DB3ULL, 
            0xE445CBD11E5098DEULL, 0xA75A21F5C03F0E97ULL, 0xA516CF22D0C936FFULL, 0x5790D94BB4DCBB26ULL, 
            0x7F8C28845FC05A79ULL, 0x60B2C1ABBD3B5946ULL, 0xAFCCFE47BF626C14ULL, 0xAE1B9D169A707C16ULL, 
            0x64EA288F91FA7D5EULL, 0x5CFE4280C730616FULL, 0xE2D25CA5E9F141B0ULL, 0x7E733FBCDD9FC3A3ULL, 
            0x288627B863C1D913ULL, 0x648F856B7CB632E7ULL, 0x77D7A52FA300A4D3ULL, 0x59D218940432D494ULL, 
            0xE8633F54DFEC90C2ULL, 0xCC3F91C87CA9BDAAULL, 0x12340837010C5AF7ULL, 0x53F59D03B5E1E8E1ULL
        }
    },
    {
        {
            0xE3E6D30402CB86D2ULL, 0x8791A55DE710219EULL, 0x129F5D63A30201F1ULL, 0x3DC07788B62113C1ULL, 
            0x3D452CF7A4F434DCULL, 0xC501C08B310084F0ULL, 0x9DFB389A0D165365ULL, 0xC26A7A5C6F02619AULL, 
            0x838AE0C7E0AC9221ULL, 0xFA3B29BC072E8B43ULL, 0x244619A84CE28C9BULL, 0xE837F469DC96D06DULL, 
            0xB625A8D181E42CC5ULL, 0x8119103A850025E4ULL, 0xD21EE486CEDB0E47ULL, 0xC2A53D2C1B2F52A2ULL, 
            0x3E320F58D89D421CULL, 0xDEC344C28D3C309FULL, 0x3C09846C471228F3ULL, 0x1E6E496D9548C701ULL, 
            0x38A63C6FF0D7D032ULL, 0xEB9B048B03AF7603ULL, 0x42428ACE39B793FAULL, 0x80727CC57B162E83ULL, 
            0x67F867620A24DEB2ULL, 0x04D618289DA7E6DEULL, 0x0C158D7978FEC51BULL, 0x0D886A7F04F9CCABULL, 
            0xB1432610AA0841F7ULL, 0x70A6885EF94FEC12ULL, 0xE2155F24036AAF07ULL, 0x9A0AB46473549E9CULL
        },
        {
            0xF03A72464BAC9227ULL, 0x48275D8F3EE615DBULL, 0xB908290352E0FA74ULL, 0x677018689E7EEB03ULL, 
            0x342F22A298196C74ULL, 0x5EA534C492778377ULL, 0xA1C69CCE3D538CA8ULL, 0x11F341C1DD236F40ULL, 
            0x022C3211936CADE8ULL, 0xFC8C9327EB9FF164ULL, 0xC7DB2DC351B2AE3DULL, 0x0959A2A037DFC380ULL, 
            0x2D5E766C8BE9C73AULL, 0x942CEA8E94E6F005ULL, 0x9EE45D775C47B9E0ULL, 0x26E346043DD8165CULL, 
            0x1CDE1EE81B94632BULL, 0x55E3B71331A05921ULL, 0x83E73324FFA3D0FFULL, 0xD78CBFBA2AC540F3ULL, 
            0x1D9D044061FC756DULL, 0xDA56FC957444CB0BULL, 0xF6F4EAA3AA99B3ABULL, 0x23986FC4946F543AULL, 
            0x689C9BC6A3A50A38ULL, 0x83C2EBB7922668D1ULL, 0xA57AEE05A9DCDA2CULL, 0x94DDDAD2FA3CA53DULL, 
            0xF82A33D51E7F8E5FULL, 0x7C71DD8185DF7E35ULL, 0x8A1B311B86F309C5ULL, 0xE03C298FE16B5C98ULL
        },
        {
            0xF448EBEFD3745D0BULL, 0x929C7D50E438212FULL, 0x4AEFEF3FCF83317EULL, 0xD6A6F64CE55D0EFFULL, 
            0x48FE4579DEBF3697ULL, 0x4729914BC9DA360CULL, 0xA96905207A740F92ULL, 0x17FFCC1B628F5ED9ULL, 
            0x108BA160FE7F79C1ULL, 0xD4554469D6845B9EULL, 0x12ED60F5F8289C6BULL, 0xE78E98F552D28D1BULL, 
            0x96A7AFEC3A905B77ULL, 0x25A40270A9A3CCF6ULL, 0xE839ADF5C5F4DAD9ULL, 0x25FAF87F28B03276ULL, 
            0xB9F309A5784B96A5ULL, 0x5C5F2E2C8045EDACULL, 0x533CACE476ACE3FBULL, 0xFEAB5C1905AE79EBULL, 
            0x55CB11C5754AD76BULL, 0xB698BF07E7BB4588ULL, 0x512CF996F881B01EULL, 0xACC326B64E4D8A6DULL, 
            0x8A5B3ADC5B535BCBULL, 0x0DA09186015DA3CBULL, 0x2D60458365F5E510ULL, 0xD2261730CAECC1E5ULL, 
            0x86F1AB50594F54D7ULL, 0x4AB3FEB3C71A7D81ULL, 0xD25878F3310562D0ULL, 0x7D2E9491A3DF9E53ULL
        },
        {
            0xD42BAF7FF740FBCEULL, 0xF45D8AC3C3EFBF5BULL, 0x1E5B533FB694CD60ULL, 0xD5D42389B55E59B7ULL, 
            0x87508284F25ACF7EULL, 0x8647E79495D02A7AULL, 0x0061A4531D08EE74ULL, 0x724070A7CB401751ULL, 
            0xE5557AFB8EE2518DULL, 0x6F62B2CB218409DDULL, 0x34C8FD03E0306AD0ULL, 0xB66BF81498A5B4F5ULL, 
            0x0034B1DACD8B85D9ULL, 0x55BF00A17C620986ULL, 0x625DAF9D7B9661E5ULL, 0x44BF6D72A77BB83EULL, 
            0xC34340E41FD1C732ULL, 0xCA93C2740DD13594ULL, 0x01723142315702EFULL, 0x005A089011AE1FC3ULL, 
            0x2326FB7D7A0C3229ULL, 0x93137F7CD4D8C3D2ULL, 0x5EC603FF59F8261DULL, 0xDF8751E7F5CCE304ULL, 
            0xC5978B6E1440E29BULL, 0x84EE1F6F4934E766ULL, 0xD3FA34AC43EEA9DEULL, 0xED0F7B0DF248D95AULL, 
            0xD9E62916E4FE0FE9ULL, 0xB3A5EBEEC1E7FA8FULL, 0xC0AB4AE1BCA72593ULL, 0x22AABBFC7A3F2364ULL
        },
        {
            0x01025393C4818B9BULL, 0xC4EEC7FCBDE36DD2ULL, 0x2D49ED067588862EULL, 0xCB3882754144C962ULL, 
            0xEEF3A4336DD8F570ULL, 0x13AF034B979C251CULL, 0xE9AAF3A7CD715561ULL, 0xD8895DFBC84BC38DULL, 
            0x7D90121F5378E1F3ULL, 0x88DC560360B035D5ULL, 0x77164CF1C9CDB38BULL, 0xEC8CE0119ADCC4E2ULL, 
            0xED2F17FA7B7B86C5ULL, 0x5318BE2AE90BA24BULL, 0x844B37F7882B58C5ULL, 0x7C0DBEE06B37302BULL, 
            0x4A0781017A54F154ULL, 0x1293A5AFA662E0A3ULL, 0xB6802CB191BA7A20ULL, 0x8EADE977C0662D7CULL, 
            0x151D54F366978E0DULL, 0x8FD6B18248AC60CFULL, 0x85E110240557E5F5ULL, 0xC0E7C5626AAA95D0ULL, 
            0xFBD9A48CB38F5CC1ULL, 0x9D061169C2F8DC9FULL, 0x54550EB116245D22ULL, 0xFD5B6824ECCE05F7ULL, 
            0x38A197C102412E04ULL, 0x9243CEE72A8C1C76ULL, 0x7FAB8E9C0041F68AULL, 0x4E370E15E67C3F9BULL
        },
        {
            0xFBB72251072D0492ULL, 0x91A3625736EAC07DULL, 0x97566555281999A3ULL, 0x974E7FEBD5BA720EULL, 
            0x446BD187419EEE0CULL, 0x71FF01EFB342D1ACULL, 0x42C0AA99276DDCCCULL, 0xBFE1631BE13D3175ULL, 
            0xBBD435B146953E29ULL, 0x161B326589A64F70ULL, 0x11348C9592ECCA23ULL, 0xE2DEF46D7E38DB32ULL, 
            0x19E875AD0C141047ULL, 0xE1CCD3921D4B55F9ULL, 0xA5468F10DDA9306DULL, 0x5234D278FB9FF3B0ULL, 
            0xD153F0302E5A3DC3ULL, 0x1D9E793181482D3DULL, 0xE5576DD80FA2A38FULL, 0xE8294D7EAE84EB57ULL, 
            0x7E0B102CFAF71896ULL, 0x189EE80BB958D1C3ULL, 0xC03552E448330941ULL, 0xD3F88E8C6BEC9A3BULL, 
            0x36DE7474B4817484ULL, 0x401D18D5A2DB512BULL, 0x7CFD2091CB9E50AFULL, 0x0F25EA9BA69A08A8ULL, 
            0x2FCF7075862C752CULL, 0xE252262C00705BA0ULL, 0x8E4E4C0E10229771ULL, 0x6A608E5800B3F41AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseBConstants = {
    0x74E898CB8558AC42ULL,
    0x747135DDB125D69FULL,
    0xCC63B4B3D0F10910ULL,
    0x74E898CB8558AC42ULL,
    0x747135DDB125D69FULL,
    0xCC63B4B3D0F10910ULL,
    0x82989C3B99F5BE5CULL,
    0xE3EE08D78904EEB1ULL,
    0xD7,
    0x07,
    0x6E,
    0xAE,
    0x60,
    0x5D,
    0x85,
    0xD1
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseCSalts = {
    {
        {
            0xE079AE7003B37E80ULL, 0x005117ED8016227AULL, 0xD95857DAA71F293FULL, 0x4F532127D88C466AULL, 
            0xBE9835936699E050ULL, 0xD40D03E28E6CED36ULL, 0xF4D17344F421E87AULL, 0x82EF6EA72094BA23ULL, 
            0xF89843E8CEBAAFEFULL, 0x6D87D8CE7BAA04B7ULL, 0xBF3D28F724C345A4ULL, 0xAD3724034AB26D7AULL, 
            0x7315443924BA8064ULL, 0x18475DE9EA40A639ULL, 0x9D7D095AFBD92BE4ULL, 0x42D69902493361D2ULL, 
            0xC47ACF3F373E011FULL, 0x0390CB1C6972FF48ULL, 0x605CE1D911225093ULL, 0x893ADE71486FD688ULL, 
            0xD0CFAE0953CD4E26ULL, 0xDEA68EB124114ACFULL, 0xABA1180735100546ULL, 0xF5ECF37DFF34AC62ULL, 
            0x9294596CD3C9B4F4ULL, 0x9588CD3D08E545D7ULL, 0xD194A818C15F789FULL, 0x1CE9DB4B2AF31E70ULL, 
            0x011D6D4D1FBC9AD3ULL, 0xDEF66C1DAA859D3CULL, 0x789868ED34C23753ULL, 0x1C3404BA87AD2BC1ULL
        },
        {
            0xB2A8E37C0D67CAD7ULL, 0x3EA7CB943FAA3123ULL, 0x9EC2B24DC9281950ULL, 0xF07BD528C6E43B3DULL, 
            0xDDC22B34E7DEEBB6ULL, 0x1B3D812C6B5BC2D5ULL, 0xB12CA816B5AA00A8ULL, 0x32233995DE34AED6ULL, 
            0x416E3614F64EA0E8ULL, 0x6614BAF99B00AFBFULL, 0x60C90D8E6B7E8DDFULL, 0x799B8FE263324829ULL, 
            0x77541889CD43E9B7ULL, 0x856B09E247CF55D2ULL, 0x0F5400830F21E0F3ULL, 0xE06B925BAE7662E9ULL, 
            0xD72DBAC252C4651EULL, 0x9494C2A9CD992969ULL, 0x79C2740C09F15F88ULL, 0x24C4F64ABDE2B841ULL, 
            0xFEA689EDB407436BULL, 0xD611659147A9E286ULL, 0xD7D157108E8AACEDULL, 0xA48256D0062A96C5ULL, 
            0xD9D8F732571B38B7ULL, 0x95C0B8C8ACB37AA3ULL, 0x667174F634A7D4EAULL, 0x162598079B884DECULL, 
            0x06BF5252702B48B4ULL, 0xD520DF427898CA75ULL, 0x3859920F3E0A0C95ULL, 0x42E3D5CF5F2F8603ULL
        },
        {
            0xC69A1FC490F990E9ULL, 0x08FB18A3C8645020ULL, 0xD00508B489ECCAECULL, 0xD731C3A3BE9301F9ULL, 
            0x67148A06231D6444ULL, 0x9E62C29607483E9BULL, 0x954F1D54D955ED98ULL, 0xE74AE87236007E55ULL, 
            0xB92780DCE359C46CULL, 0x938145F57313B301ULL, 0x3AD611DD60B06A37ULL, 0xA0DFCB44CB57864EULL, 
            0xC22AB98AF141E3F7ULL, 0x3D2FCC14532506BCULL, 0xE8D0C71BBBFA7C63ULL, 0x9F87DD3BBD6D5354ULL, 
            0xCA26470CC08ABE3AULL, 0xEED0827271E988F7ULL, 0x3260564B16E11CC6ULL, 0xA0D2D045BC43FA84ULL, 
            0x5F74BA789E4DC3D6ULL, 0x19BB7DA0EADC0CC1ULL, 0xECCE937DE68A9418ULL, 0xE1C406C94895A559ULL, 
            0xFEF58CB07632A376ULL, 0x30570950176D39D4ULL, 0x509FE102D8ED5B40ULL, 0xBFE1E8074FB1BB84ULL, 
            0xF7B4DABFBF02707BULL, 0x8A43A97D231E36D4ULL, 0xAC84F3F46F6F788BULL, 0xD064CFB960B62326ULL
        },
        {
            0x60A710365742246CULL, 0xA130382C1A6FAE01ULL, 0x9B30A80B7335504DULL, 0xEA32E0E515E97998ULL, 
            0xDE4A3E762920F684ULL, 0xF04B7063878E8039ULL, 0xC5E7A6645E9D890BULL, 0xF227B382387CE185ULL, 
            0x91671F452EF7AF37ULL, 0x83C7DD0EC791E7F0ULL, 0x7CC964C5C38BE740ULL, 0xB94E52D901706344ULL, 
            0xC021866524684BA4ULL, 0x63C091BFD7ED5E88ULL, 0x3BEBB35527AE3786ULL, 0x5F520E49C8956D70ULL, 
            0x387606BC5103511EULL, 0x8BF1A29CDA4B7C00ULL, 0x493FC0780661812FULL, 0xCF76727C61EAA76DULL, 
            0x73EB5AFE714FFD49ULL, 0x0AA4D5D278895C5AULL, 0x64999513E209E239ULL, 0x71E74075E530333AULL, 
            0xE8DA859580D83190ULL, 0xC1E4406591B00AE9ULL, 0xF9DC8906AB9767B1ULL, 0x77FC44B96ADFB4E7ULL, 
            0x826FF68869D06547ULL, 0xF298FE675DB35281ULL, 0x087DA7C2ECE417E2ULL, 0xF2E02452EFB99B5CULL
        },
        {
            0xDA9FE6CC75CC3469ULL, 0xC6BBCBFC3F0D3CB6ULL, 0x306E6D1AADEAC2CFULL, 0xDF3042DFB5F1EEEEULL, 
            0x17AD053173A1BB1DULL, 0xE51319AE97C5A07CULL, 0x81E121E0EE46A17DULL, 0x3BD98E356F5FB791ULL, 
            0xEF19847417B4FA12ULL, 0xD97171A0592CC602ULL, 0xE959AB8435628C46ULL, 0x510A3EA4C49E9AD7ULL, 
            0x6ABCC0D277E9F727ULL, 0x34BC35969BAE953FULL, 0xEA09E0F8736C6F2EULL, 0x7354AE8AF66E1701ULL, 
            0x1C5CF3B9F5FFDCFFULL, 0x96045B2EBFDF7D0FULL, 0x375008B30A2F4222ULL, 0xB88EEE73E0AF5D15ULL, 
            0xEB1424097D3D894BULL, 0xE6B529A928B6C868ULL, 0x58190FA5A39668A9ULL, 0x9EE5D7312537C50FULL, 
            0xD7ECB4DD328E47AAULL, 0x2399F15C7E4B24E0ULL, 0xF842CAEA8A8A4583ULL, 0x23B0BBFD3575CBC9ULL, 
            0x0995D00FE2B227EFULL, 0x97646B6D3328ECB9ULL, 0xBB28FF74938B7F26ULL, 0x8E49EE3251FE0356ULL
        },
        {
            0xB2E259A8C251E708ULL, 0x3BFD6DE59C72FD12ULL, 0x7B8F7C1D3596F3ECULL, 0x87EFB0E830677545ULL, 
            0xBB49206737CC48DBULL, 0x7279D7FBCBF04699ULL, 0xB53E174594579DC9ULL, 0xD2A7839F0399BD16ULL, 
            0x7F1E214D911A1CC3ULL, 0xB174CE7B990F4B86ULL, 0x8B4727407773F71FULL, 0x5E5C89EF2D5FD7D3ULL, 
            0x7AEB7D578A2AFD16ULL, 0x6D379B98E4D9E6AEULL, 0x2EF4D03C8E283AD7ULL, 0x24777425D9226F05ULL, 
            0x6C512E63CF902340ULL, 0x5016AAEC2FF9D6CCULL, 0x4BF6726FE67D4C6CULL, 0xC30995AC4DD3E8CEULL, 
            0x1FEB58170F966073ULL, 0x3E13E29285C87AFBULL, 0x76ADDC0FEE28C060ULL, 0x10640074D77E4F38ULL, 
            0xAC8699E9342D7BC6ULL, 0x3DDEF667DE607167ULL, 0x52A0A720273C2E97ULL, 0xC7E6FCF36EE5E166ULL, 
            0xA78E7DFBB1D08C9DULL, 0xB795E948033213C3ULL, 0x0636465B350AF833ULL, 0x9C6A8F24D320CB6FULL
        }
    },
    {
        {
            0xA3CE9E45BC5E8CEBULL, 0x482F04C53BA2A978ULL, 0x2F4913C9D79C9746ULL, 0x2B7B3894D093463EULL, 
            0x3A5136892AAAEDD1ULL, 0x959DCE0F365FD59EULL, 0x363E909FBECD9C6BULL, 0x530CAE4C7FEED7EFULL, 
            0x5C646C1FBF10F5BFULL, 0xFD6D0CE168E3C24EULL, 0xEC149856B6958F1FULL, 0xA456845E86AD4AABULL, 
            0x036473CDC5C0E18AULL, 0xCD8397F25574EF6FULL, 0x08EE03C3F11EDC62ULL, 0xF1987CDA61BDFB9FULL, 
            0xCEA4237AC88D9B99ULL, 0x3E4CB50E187D77FEULL, 0x56FCA4F3687B97F6ULL, 0x315D9BC10E9D3958ULL, 
            0x63D1965BC0600F46ULL, 0xB18AB6C23F14EEE7ULL, 0xE70D56A51DC86CC4ULL, 0x39062561573FE832ULL, 
            0xD5E8212DB29A73B9ULL, 0x5850CAAD3F000050ULL, 0xAB7B59FCFA1C9A74ULL, 0x6C4729B27215F018ULL, 
            0x887EFF25A7BBC266ULL, 0x838788394069FF32ULL, 0x8646A922ACC9E2C3ULL, 0xB90A889EBCCB5B69ULL
        },
        {
            0xD1CDB9052DECFB49ULL, 0x25C1BE22D6D6D3D9ULL, 0xAA556F70F20C5433ULL, 0x51FECB05C58246B8ULL, 
            0x8412D3620B3F6A59ULL, 0x1F936FB27EA69F20ULL, 0xB39245FDE827884DULL, 0x2DEA41A7C23FB4C7ULL, 
            0xAA58563316BB401DULL, 0x4B8DDB610C56F253ULL, 0x8536405CC2B8F79AULL, 0x0454270DD8A28AB0ULL, 
            0x3D94CAF42707B21FULL, 0x1BD008482DC04391ULL, 0x860DEC5ABFC5B995ULL, 0x73E02B963C7EB80BULL, 
            0x530EAF2DE49B1A7DULL, 0xBCA7630F395CC73EULL, 0xF0A915578224B76BULL, 0x89BCEC65D51B3ECBULL, 
            0xE7EB9F36AF22A87EULL, 0x3F668597711BEF34ULL, 0x9CE820BD44B8B6E9ULL, 0x9977636C18D3D9DFULL, 
            0x7465BAF57FD80C54ULL, 0x178522828D72A8DBULL, 0x4C238D0614FAA13AULL, 0xEEC93BD5EE350516ULL, 
            0x0C75B88CB1FE3A85ULL, 0x449CC34F1F9A5061ULL, 0x30CA6A991CBF262DULL, 0x161A42B5A3DEA089ULL
        },
        {
            0x8D02F856CB00F134ULL, 0x15374E2F7974CDC0ULL, 0x456C97812DD52259ULL, 0x9C4710C355796ECEULL, 
            0x4F56204A71C0624EULL, 0x125A0D0226B91C7DULL, 0x6224F6ED7101CAA0ULL, 0x04B373903FBED61DULL, 
            0x28AA9BEBF5E49686ULL, 0xC5C3B2C10EC877FBULL, 0xE55BEB0ADD6F19CFULL, 0xFABC8CE738D60675ULL, 
            0x08FC2BF0AA516E52ULL, 0xC142C466D1093D7DULL, 0xFB951B94B94A5790ULL, 0x805083DE4D9FBF58ULL, 
            0x5451B719F1D1645EULL, 0x153F16BAD142522DULL, 0x6CA4AD13417ABB61ULL, 0x9DE0EFFC71DA8812ULL, 
            0x3890B5915B2DC23BULL, 0xE805B9FC57B2586FULL, 0xA6F3F9AE9845291EULL, 0xA1D15836CD207545ULL, 
            0x6AB16BEA8F33FF19ULL, 0xB8E579AC1CD5C593ULL, 0xE35A079ACCA0C11FULL, 0x1E593EC6DC8A2BDBULL, 
            0xDA54F68969323721ULL, 0xFE628313BB2040F0ULL, 0xF42D48E3B901C2C5ULL, 0xA4F725E5D5144AA5ULL
        },
        {
            0x384EC545EEEF3A9DULL, 0x0E9AB65AD50069CDULL, 0x80F0B51202B38D18ULL, 0x915086A17745844EULL, 
            0xC4C615900072F67CULL, 0xD2CE842FE0D18432ULL, 0x6DC89E832B1D4DB0ULL, 0xBF1D4128291F283DULL, 
            0x5A9F11670987FC4AULL, 0x0E7FE01FD378D3DEULL, 0xFD72544ED69B5C9AULL, 0xBE3098A6CADBD903ULL, 
            0x4C233D1659E1BC06ULL, 0xC85F2EBE2C0706C7ULL, 0x9ABE77970498D1DDULL, 0x4CBA92F96D0CED66ULL, 
            0xC4514C3B687EE278ULL, 0x3C20E4738DA8E5E0ULL, 0x4A0DE3922EE5CCDAULL, 0xD8C21C5AC791A3CBULL, 
            0x3CCAED765FD4EFE5ULL, 0xB3C5E3D56BD18AF7ULL, 0x4D3C2EA4DE99C044ULL, 0xA7CEC9E75A87DF26ULL, 
            0xDA649EFA4E19BE68ULL, 0x15168B7033658A1CULL, 0xD165B63FC20A62F8ULL, 0x50076DEBC0131F8AULL, 
            0x65D4CCEB10CE429CULL, 0xEE46E23BB5B42479ULL, 0xB3D06BAD6C932197ULL, 0xD43A7EAFAE15A0B6ULL
        },
        {
            0x2721CC97849CA4D8ULL, 0x93007E33CEF03FDFULL, 0x767B25EDE28F7B15ULL, 0xC79CBA4A5D0DDBD6ULL, 
            0x1A8C7F693F462770ULL, 0xE63997C391BA1CB7ULL, 0xB1D3FBCA864E8A56ULL, 0x2DF929072EDBFCF8ULL, 
            0x3C36206B01387E02ULL, 0xF74E9C1DB732869CULL, 0xDD7A4C6278364A8DULL, 0x64021D0B445022CCULL, 
            0x9561581708C63051ULL, 0xCE2021B1375A044FULL, 0x3A11E1851DF19969ULL, 0xD3C398BCFC059DF1ULL, 
            0x43479F135182DBAEULL, 0x3997D5A05901D71EULL, 0x92264D11B7F80F1CULL, 0xDDD9EF123F6CB562ULL, 
            0xAF624F19171E4264ULL, 0xB380F883D8726FE6ULL, 0xC29DABA55D370F6BULL, 0x8265F4913847D180ULL, 
            0x8BE872FD40339ABAULL, 0x712290241251E2D9ULL, 0xD4078800F0C5DF67ULL, 0x213387AD69507AFAULL, 
            0xBD04C8048FAFC6F5ULL, 0xE4C82F1E2866D1C8ULL, 0x36CF653E30ED6639ULL, 0x799856CE910296C2ULL
        },
        {
            0x6D50D6B245265753ULL, 0xCE1838923253D887ULL, 0x574C44E5A97374C8ULL, 0x73E14E4177CCB44BULL, 
            0xD1FE511B7CEAF88EULL, 0xACDD31348C5C9B62ULL, 0xDC93DD6EC187E8FBULL, 0x9C23E065A15D921CULL, 
            0xCFB3B25D3A5B7CCAULL, 0xE04B1E3352586608ULL, 0xFC9217900B65999CULL, 0xE7E8B73B52F15D14ULL, 
            0xB9F393F6DFB56017ULL, 0x3EF8FCC24549B40CULL, 0x71CDF52D64F433BEULL, 0x956B7971419FB2C2ULL, 
            0x5E1F49256B1ADB5DULL, 0x6B30CADF494654F2ULL, 0xDAC9540E14A5772DULL, 0x03358BF7B71F1370ULL, 
            0x260A0B0AA2325F45ULL, 0x548DEBD547533D31ULL, 0xA2AE4DBC44E347E3ULL, 0x876ED541D93E2688ULL, 
            0x42A4E7505E75171CULL, 0x968A868390E7344EULL, 0x2F28493FD5A00241ULL, 0xE8275F6E1D735443ULL, 
            0x992326213476199EULL, 0xDAC076812C760CB9ULL, 0x22009BCA19C57F15ULL, 0x327C423803C0DA96ULL
        }
    },
    {
        {
            0x7B5F7C28BE749B77ULL, 0x950533D0348DAE42ULL, 0x109EA28E5E3152A5ULL, 0xEA27259BFB554158ULL, 
            0xE332DA8E8F47076CULL, 0x9EC603253E1B9D2FULL, 0x5AB5ED5D998E8ABAULL, 0x2CB690D7B8EC8D9DULL, 
            0x6F781E2DF3C2122CULL, 0xE88F946B8E4D83E1ULL, 0xB1EA5C7ACFBB0DA0ULL, 0x90F3B954C7B20341ULL, 
            0x5D6D6037E737D0BDULL, 0xC408044C27E9EBD1ULL, 0x5356091E9C727862ULL, 0x00F89DB00CEFA637ULL, 
            0x4FA324ED60FED873ULL, 0x3534393F7495FD21ULL, 0x279CDA825F29359BULL, 0x25B75E1DF2B0B9DBULL, 
            0x73E1CDED9F98E7A7ULL, 0x376BD8BDF2E68D09ULL, 0x9394BDE5748ACCEAULL, 0x01AE8E6C48341E30ULL, 
            0x2149016726065028ULL, 0xD4CA6A6E9F1B1D15ULL, 0xFFAC27B4E23AEE4FULL, 0x74102896BF9A65FAULL, 
            0x2B08C2D50F49EA4EULL, 0x19A4E9F1E0810B05ULL, 0x381733D165062CA1ULL, 0x6763F5298B83A756ULL
        },
        {
            0xC37D861AD87F939CULL, 0xCA1F2B55E7318757ULL, 0xAECCAC4ED6BE3444ULL, 0xC43DEFB0E5CAB0DDULL, 
            0x64A65F7F94F90818ULL, 0x75A69C760CDF100BULL, 0x07FA204C2909A1EEULL, 0x9BBC02DC13532EB5ULL, 
            0xF7745B042862749FULL, 0x06829C37C1EEC13AULL, 0xBF12F7DF06E2A611ULL, 0xB2CEBAB7B1F8F110ULL, 
            0x7B7AAEC24E58BF83ULL, 0xA381740CD2528F99ULL, 0x6686F1FFA4E3CA6BULL, 0xA8A693CE70D01793ULL, 
            0x57EDE94B03665204ULL, 0x109E4DD83A996FBAULL, 0x73C90ECEC0C8803AULL, 0x09FFFA7EAF49C17AULL, 
            0x24E31852A38B7505ULL, 0x96A2725D905E734AULL, 0x15E3A3BA413A6B55ULL, 0x206B2EEC71E0B708ULL, 
            0x5E17B55596EE11B8ULL, 0xC8F655E23D837D6CULL, 0x5E0790ACA7291834ULL, 0xFF6B78B01C45C8DEULL, 
            0x71F0941BDE58DC15ULL, 0x74734228C354FE8DULL, 0xE5406880E09081B1ULL, 0xABCD7EA6CEED14A4ULL
        },
        {
            0x4118C2573546D3BFULL, 0xDA7F270719818596ULL, 0x9AE1DF67C683511BULL, 0xE0E957D954B8CACCULL, 
            0xE2D692B7B45BDD27ULL, 0x1E85DB4FA827924BULL, 0xF9283BB1C7765E06ULL, 0x024E5A6A4DB4C21EULL, 
            0x390CA263D18BC84AULL, 0xE1623E84153ECCE1ULL, 0x22CAABE441FD8C05ULL, 0xD3422E935958C43AULL, 
            0x1A3B851A97D2D990ULL, 0x9C4770CDA64F2E33ULL, 0x5F32196F2773D5FCULL, 0x5CF78518E65FAC9AULL, 
            0x518D042D38141159ULL, 0xA2B544BE86A223BBULL, 0x4D0983196855E56EULL, 0x13F549EB46F5C49AULL, 
            0xC93CB74B0E8B1768ULL, 0x7C821CED355C348CULL, 0xDE5CC94BD56D16DAULL, 0xB1F3F86D657EADAAULL, 
            0xA16DE75208D60F3FULL, 0x4A9460409FA1F1EDULL, 0xA9A133A7746D0B6DULL, 0x1324E7526DA26D81ULL, 
            0xF787E1CB2025ED66ULL, 0xE76E85D5668902BCULL, 0xDC22F305696B493AULL, 0x48856D7915B30322ULL
        },
        {
            0xE7D06884777A84BAULL, 0x4D9EB0F2C20A7175ULL, 0x7FA6862551555B49ULL, 0x20B4375118657297ULL, 
            0xCBE270599FBA3BADULL, 0x71EDBCC3A08EDE16ULL, 0x2204806431D663B1ULL, 0x0055525AA5F4CEF0ULL, 
            0x4E04123E42FA570AULL, 0x27EBD2CD39466738ULL, 0xA98C3039644A8B59ULL, 0xD93B883C4AFD5D70ULL, 
            0xFCE33BCC3FD2AEB2ULL, 0x0D94D33EE26E5E51ULL, 0xAA90F8B59A5343C9ULL, 0x661A0C7616E342EAULL, 
            0xE6D0F19FD548C4D7ULL, 0x72886DE63F61B18DULL, 0x56D696419219AC10ULL, 0x787E8CFBDCA2CC86ULL, 
            0x1F79F4C615ABEE89ULL, 0x022E99060BE0D2CDULL, 0x0F6CE63862CD08EEULL, 0xEE092AFFEB01F4F1ULL, 
            0xD6FD4C796A113B7AULL, 0xFB47F4E0A2C5DB0EULL, 0x7736B13F76ECBA63ULL, 0x984E8F5B016D74B2ULL, 
            0xFEFE102F4744B919ULL, 0x6593886FDBE08C87ULL, 0xB2FF2809A981345BULL, 0xF5898412F30C9173ULL
        },
        {
            0x28F885C6E20F8E9EULL, 0x0C0BCC21BE448AD5ULL, 0x85181A2D2EA8B4AFULL, 0x100C8B00D77FAB7CULL, 
            0xE01EF03EAB2075BEULL, 0x25D40634434EC5A4ULL, 0xC8E01B41F65AF1C0ULL, 0x03594987E476DAEBULL, 
            0x77C5B8F5EC15DAB8ULL, 0x38368AE086347CCEULL, 0x89B0BB75756B0CD0ULL, 0xC99980FF2F8FCA83ULL, 
            0x6F792B199DBF80C6ULL, 0xCFCF0B9B4A9D97ACULL, 0x964116CDCCA98EA6ULL, 0x3F2298B3F71C1E36ULL, 
            0xE59B9E08D21AD2EFULL, 0xDCAA572B6D403EDFULL, 0xDB23539BDA8098E8ULL, 0x843122313E55C7A2ULL, 
            0xDAA0224426C2B0F4ULL, 0x5FBC666A933B3719ULL, 0xC0E8AF2D17C23F0DULL, 0x6B3D9345A708E49FULL, 
            0xDFB835CBEBE0A3F9ULL, 0x9FEB76C2E601D628ULL, 0x783C70317C9A2B70ULL, 0x02F7DA9F1A7DC18BULL, 
            0x551272D82A91152FULL, 0x01731A925B3D9D17ULL, 0x2FCB4F87B63FCBC3ULL, 0xEEC2D16C06F5BD31ULL
        },
        {
            0xD2230D1EFC5C644CULL, 0x8ECDD959BFEA67EEULL, 0x529705228F64BAA4ULL, 0x51F12149E9F67558ULL, 
            0x529153C534016556ULL, 0x944745B868F9F91AULL, 0x68599376D9803233ULL, 0x1E496CE78E6A8025ULL, 
            0x913765186828C9EDULL, 0xC54878EFBA56E1AEULL, 0x19EF372E0AAAC8E9ULL, 0x00DA2B7B942DD066ULL, 
            0x2BD7549C7BF96C4CULL, 0x9DD949099D8D2681ULL, 0x9D7C19A944829F3AULL, 0x697D04F3289404F0ULL, 
            0x1251CC73F639B568ULL, 0x7F9FBB3A302E6DE3ULL, 0xF8CE86F26A6306CFULL, 0x77E9AAD0ED083D57ULL, 
            0x8CF02BD294BD9368ULL, 0x8D623249D6C467FFULL, 0xFAA3CA2869C48B7DULL, 0x0CD0B8F3BA3DD0A7ULL, 
            0x5945420FBB44941AULL, 0xC2A5EEA8B47E83EFULL, 0xA45E3858565B66AFULL, 0x134C3DBAC7EE8FB3ULL, 
            0xE197B9AF31DDB5D3ULL, 0xAC036399F5156E72ULL, 0xECD4FDCE4BDE1836ULL, 0xEEDB991AE85BA4A1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseCConstants = {
    0x35E6E92FF374CED6ULL,
    0x0E731574BAFAD20CULL,
    0x627C9D2A00858194ULL,
    0x35E6E92FF374CED6ULL,
    0x0E731574BAFAD20CULL,
    0x627C9D2A00858194ULL,
    0x38FDBF6640CC1A1EULL,
    0x953C24102A59B30AULL,
    0xAC,
    0x23,
    0x15,
    0xED,
    0xA7,
    0x6E,
    0x47,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseDSalts = {
    {
        {
            0x6727D6D538266B37ULL, 0x41EFC93B4A75955CULL, 0x7AF8343C974DF2BCULL, 0x403D796E1C6ECE5FULL, 
            0x896026EA41516E80ULL, 0x8475C259F274D7B4ULL, 0xAAACE60C389048E0ULL, 0xCD66B1D5FEB12377ULL, 
            0x2708D8977D45AE14ULL, 0x2502AA0581100C2BULL, 0x83C23F3258208512ULL, 0x8C1A958901AC5165ULL, 
            0x7DABF20CCE1B463CULL, 0x07F42E268745FDE5ULL, 0x2DC1D5523EF9F8A6ULL, 0xC344F52FF988536FULL, 
            0xAA90E450BDF1E968ULL, 0x22B16AA31499F977ULL, 0x5842FDCEDCD4146AULL, 0x9EC34558BFE5D7C4ULL, 
            0x6025C57C514E821AULL, 0x025A78BC74D2DD4CULL, 0xFBE49172E9CA9554ULL, 0x4D428498B7EDBB89ULL, 
            0x8CA017558B518BF3ULL, 0xE201AA3C4943BA3CULL, 0x923841C559D45159ULL, 0x11D911D666C43E51ULL, 
            0x1CA865E98B4A9185ULL, 0xDC7293913A6D1DC0ULL, 0xF62A451A5E24D837ULL, 0xF706827E012EAD0CULL
        },
        {
            0xCB60997CC17A085CULL, 0x0FD0735C3152395EULL, 0x96E2AB010FC3BB0AULL, 0x0AE7E4716F9EFB6FULL, 
            0x1A6BDECE3E5C6C2FULL, 0x644D63245F386B3AULL, 0x261F94DC86144C2AULL, 0x4042120C2B2F5AF1ULL, 
            0x5FDE6A681BED2FC2ULL, 0xA8704EDA4334984AULL, 0xC5653045A8D1DAF0ULL, 0xA1486693BE98AB88ULL, 
            0xBBE0CA75661CC102ULL, 0xEACB0AEB363BA592ULL, 0xDD9058B2A66F0013ULL, 0x280B270F02FAD215ULL, 
            0x34EE822C9BCC70D9ULL, 0xB00B9D8D0F94CD8FULL, 0xA9180E4F0757C7D7ULL, 0x14981E65B043132BULL, 
            0x6CCEB7E87091FF77ULL, 0xE2D51DE5B2696891ULL, 0xCFCCE27922AC1863ULL, 0x538EC582BBED7CD5ULL, 
            0x16A0246100C4DAB7ULL, 0xBCFD43DEB003B2BCULL, 0x909096E9F5A37D76ULL, 0xB555D01EE71635D6ULL, 
            0x2A0D929FF54FE265ULL, 0x7DBE4F3CD4505845ULL, 0xC01FA7781DC70646ULL, 0xF3573B6B326DA7CAULL
        },
        {
            0xC60AE5A75FBBD7C3ULL, 0xD9E10F2726CD3C20ULL, 0x3FFEA71B7C70701BULL, 0xECA529E3DAE4F35EULL, 
            0x2109EC59D7556CC8ULL, 0xD4B30F5E0E4CAD1EULL, 0x488B4110D62364DAULL, 0xF618FBF24705B2FAULL, 
            0x5A22F73DAC801DCFULL, 0xF1DCD45B505D7585ULL, 0x8D406B601821D9B9ULL, 0x16BA9835CC0193ADULL, 
            0xFBF6E2DCE7148DD8ULL, 0x72E3819BBCC9FA57ULL, 0x0900EE094B623B92ULL, 0xF2F942959201829AULL, 
            0xC222EC8CF7DCCE3AULL, 0xEFA8947B177D42F0ULL, 0x77FF52D212AC93AFULL, 0x9A70FAAB6065EC9FULL, 
            0x9679C11EE03E6B65ULL, 0x506D39756A6D029CULL, 0x1C59282EFD700EF3ULL, 0x08C76A0CF10E9223ULL, 
            0x390E1E163696B246ULL, 0x39D1C732BB525D72ULL, 0x9F11393B01A57A0DULL, 0xE995099C187C89D9ULL, 
            0xA247EF372BCF548CULL, 0x1B380AF3B78EAB6DULL, 0x460F39786C84DBF4ULL, 0xFEEEBBA185669169ULL
        },
        {
            0x8A56E2B4F38E4E75ULL, 0x538DA335F8153DE1ULL, 0x9DF321C6D4EBEB9DULL, 0xF2E9D728034A7D1AULL, 
            0x4887C331951938C2ULL, 0x83293B86CB658481ULL, 0xFC97D3E7A1178557ULL, 0x7A212B0CED45CD0EULL, 
            0xBE4FC3726EC6E9D9ULL, 0xF5FE8E41D3529E10ULL, 0x259957BB52236271ULL, 0x9CDFD9D22BC17A1AULL, 
            0x0264F265079252C6ULL, 0x1FF0834CCCFBA071ULL, 0x9754FD2368981BF5ULL, 0x1662C253F8F49C87ULL, 
            0x703D9D48B09275BBULL, 0xC4866EB5317C3AA8ULL, 0xF61F15E9C324DA48ULL, 0xC5F9792FD84C64C8ULL, 
            0x85F1AA46B2C19F93ULL, 0xB23A13144B524765ULL, 0x5EBDA0F35101BB72ULL, 0xA764510CCE401D74ULL, 
            0xDAF5A8F21CBA8E04ULL, 0xDE74FA8A9C5125BDULL, 0xFE6ED13C79036CA6ULL, 0xC200DF95441E1992ULL, 
            0xCE0644F0E8D3E087ULL, 0x5067B2BD655B5FC1ULL, 0x5B8A2EB9464F7F2BULL, 0xAEB131AF569BA429ULL
        },
        {
            0xF5678029E6AF8082ULL, 0xF8AA08ECE0FE3651ULL, 0xC22B87E7F12B665BULL, 0x3C7075F5C115A7EDULL, 
            0xEF72C530CF8BAB45ULL, 0x0783DC63A4676BE4ULL, 0x6CF1D75127D81373ULL, 0x46CEA8E41CDB3276ULL, 
            0x63148E34DFBE3F4EULL, 0x5291604D055A1A87ULL, 0xCDC2D0932F913DB9ULL, 0x5A6C839678A67C4FULL, 
            0xDFD23175A663CE99ULL, 0xC3D86EF5C9F710A5ULL, 0x43F85A2F6F11C82FULL, 0x1CC73598104795C4ULL, 
            0xE978859994697694ULL, 0x50E380ADAA138EF2ULL, 0x190905CB737CD669ULL, 0xCE832F3748E8CD24ULL, 
            0xE565FA65B3B5C445ULL, 0x6C534C265DA0F7ACULL, 0xDE778221E4F4E9AAULL, 0xF9FD98C7DD8DAFC8ULL, 
            0x8F9E96E088F9456EULL, 0x50CD52CFA4CF4DE3ULL, 0xD259B57371A7E969ULL, 0x5F31571C3001EC0DULL, 
            0xBC1C1A0D69CCD0BBULL, 0x62DC90E8462D3351ULL, 0xBD1C4C40BC4AA9F5ULL, 0x4E759C4B3AB1DBD5ULL
        },
        {
            0xD95E28F0C5ACC882ULL, 0x19D0D66C44D69769ULL, 0x7200B55B5A5163CFULL, 0x952342B584D05C72ULL, 
            0x220DB9AE265AF5F9ULL, 0x9A7FE4C1AAC44545ULL, 0x4D6B530F17A4FEB4ULL, 0x2E820B718658AC9AULL, 
            0x79F66FC8AD8046DEULL, 0xEDB26AFDE211D4A2ULL, 0x7E5A68089D38A3F6ULL, 0x9406D11D7CE50A49ULL, 
            0x47ADEF44F9DB262BULL, 0x0010BB8679F08A6BULL, 0x7026E13C50649EDAULL, 0x79F291FDC2F2CC47ULL, 
            0xC5E78B0AB34603F0ULL, 0xDDBFCE917CE20ACAULL, 0xC082311CE0F20384ULL, 0xCC09F45E5AF9F29AULL, 
            0xEB45CE183B499024ULL, 0x4B856AF617371FE3ULL, 0xDED4BC81923DC6CEULL, 0x70AF9960EEE73BDBULL, 
            0x71041174482150AAULL, 0x5A028F688B2A072DULL, 0x62E695FF6C4772B4ULL, 0x986554FE25A7A0C6ULL, 
            0x6F00175575C7FB9FULL, 0x844A399F78B7CFC0ULL, 0x1AC443C666AC45E7ULL, 0x38E7C93AF538EA76ULL
        }
    },
    {
        {
            0x326F176CB0C7DE9FULL, 0x727252C91137326FULL, 0xA7713AAB17725172ULL, 0xF38A6ABACCF0128FULL, 
            0xC504AAB603896667ULL, 0x81E8D5516BD1ADBCULL, 0x44B54E340694A9D7ULL, 0xE3457E54ECA4F8E9ULL, 
            0x44B8AA9657D2CF47ULL, 0x853D78B82D5541A5ULL, 0xCB9DA64FD2D9A95CULL, 0x26EEBE36862DB223ULL, 
            0xEE4FF62135A60329ULL, 0xF5F3C37E9495E4E9ULL, 0x4007E60A2821D917ULL, 0xFCC679CC79D94166ULL, 
            0xB47FBA4D4B8FCF3BULL, 0xC09512E149A7B50BULL, 0xC9C9F165163FEBA3ULL, 0x989AB627575AE00FULL, 
            0x4EACF1B9D2CCE161ULL, 0x425DC0026B8F8D30ULL, 0xB9EC8394D1AD7012ULL, 0x8E0C126A70C0F9CDULL, 
            0x6A349D51876BEB1AULL, 0x38B3D26637A33AEFULL, 0x7ED297F723BBA357ULL, 0xE3B20C5DEB8FFB91ULL, 
            0x14A9CF9423E92E2DULL, 0xAC81F8BCCA6A4693ULL, 0xC4906BDBC4083113ULL, 0x5ED5E453F15A9388ULL
        },
        {
            0xF93A5215EF07D849ULL, 0x5B38EE2B153FAC52ULL, 0x76F3E8284FE1E690ULL, 0x4C21BDD34228D89BULL, 
            0x96277958F15C0BCDULL, 0x99E2DEDF82D98F67ULL, 0x30C87835EA4E7885ULL, 0x920DA2FF9566991DULL, 
            0xE069D9BC39CDE8BAULL, 0x14505F88E6FF7858ULL, 0x4DAA014CB4B2993DULL, 0x6D3C9344F5E4C87AULL, 
            0xE33DF7667D579B17ULL, 0xFA9A3240EBC93572ULL, 0x5C61F19702B1BB37ULL, 0xB77680853F2C353FULL, 
            0xEC33BF20B6135972ULL, 0xA5A7201701397137ULL, 0xCB5AB68A48172D88ULL, 0x8D1329DA0C00CC72ULL, 
            0x78FF92C42230A114ULL, 0x7D5F9709F6206215ULL, 0x906383B688CC4E6CULL, 0xBF91EFE757A4CFAEULL, 
            0x7777E7A75C9825E9ULL, 0xE5C115DEED63267CULL, 0x5714E9EBEED3E1AAULL, 0x6B28E8CAB1B84405ULL, 
            0x3FDE1A0207DC22FDULL, 0xFC52FEB35D8F2546ULL, 0x1620DCA98ECC889AULL, 0x3FC4DE7283DB0DA7ULL
        },
        {
            0x8DD2447A84D0724DULL, 0x60AD52F3D2192763ULL, 0xAFEF6A967EE58D5BULL, 0xA0EA49D355265821ULL, 
            0x2C6E9617951A6B2DULL, 0x1C7CDC6E9E82837DULL, 0x8E74F9146948CD8AULL, 0xA059D36339E40F73ULL, 
            0xDDD0A784CEB5B738ULL, 0x7375FC1B2C461AA6ULL, 0xCCC618F237F85918ULL, 0xB7EFBE9F3ACC78FDULL, 
            0xC49D6DBAC4A13684ULL, 0x4602F8B6F3AFCE45ULL, 0x84132227E6A36C51ULL, 0x458669F2EBE1C086ULL, 
            0xD03D6550B017C051ULL, 0x6EC9486F3B03F8C3ULL, 0xF0002CCFD310D349ULL, 0x87885CA10E5D0510ULL, 
            0x97C4E1D9FDBF8D99ULL, 0x76F36A928487D4D7ULL, 0xDA9538CCE0740F9DULL, 0xAF1F383C108C487FULL, 
            0x8220603CF86A3BA8ULL, 0x54B24BD31A0B6224ULL, 0x6B944D15CDC64FE6ULL, 0x9654E14784F05273ULL, 
            0xD7FCA6EDE465BE56ULL, 0x6B6792B1047BF9F7ULL, 0x758B284BB545C432ULL, 0x899DA5482D7CACAEULL
        },
        {
            0x0C3FF24B1B5EB279ULL, 0x5D6FA3BD7D4BB30CULL, 0xA2EE5FD3A3CB3F26ULL, 0x18A662701814939FULL, 
            0x41F22AA1E3B37B77ULL, 0x29EF432A608262AEULL, 0xE7A1D5FED563FA8BULL, 0x12D394304F59BF09ULL, 
            0x74F995B2DCE05D06ULL, 0x5AD4A1BE32B75BFCULL, 0xD476B050B07D56FEULL, 0x1DEBBB25A9505896ULL, 
            0xD4E4C1EC5437FAEEULL, 0xD7C221355789EEBDULL, 0xF6DED18B129FC210ULL, 0x9B29D067A52B6317ULL, 
            0x6EC39508FE3582C6ULL, 0xDF17ED5938340930ULL, 0x22AE69A1F6B60BD8ULL, 0x72E958A6C464DA6FULL, 
            0x4F9B9F03DF7CA724ULL, 0x0C2115F6A95A303DULL, 0x0E37F649DE7AC8A1ULL, 0xC3AEA4D7DBE9EFC5ULL, 
            0x825C0FF2B619D0D1ULL, 0x63E1EF1B01F4F02BULL, 0xB6C072FFB75B0118ULL, 0x5B677E2034F368FCULL, 
            0x07ADFA5C2E4EA457ULL, 0x12ADB32496CC9A97ULL, 0x81809AD1E814E25CULL, 0x49F7819AC0945696ULL
        },
        {
            0xEEFE280986961B59ULL, 0x9A9317A103C80271ULL, 0xD555AFFC1BD3366CULL, 0xB4056284A8BB2527ULL, 
            0x2DBBDA3A4451638DULL, 0x9F2252CFA3F9EC04ULL, 0x0F162AEFC3D88CAAULL, 0xFDED8971083889E0ULL, 
            0x4FFE1239277176ADULL, 0x5ADD4FC069394B37ULL, 0xD1F1FD19F36FEA7BULL, 0x0967B8D50B0F1D0BULL, 
            0x51DCA2EA20B38AD2ULL, 0x71DB63C95E0CFDF1ULL, 0x35BD3847D74CE3B4ULL, 0xF151DCFE29A39EA0ULL, 
            0xF11BF9284530E09DULL, 0x2ECEC419214EA058ULL, 0x6EF7A5D39C5C42D8ULL, 0x3A7D27E86A35B8F4ULL, 
            0xA4549FC470F3BB30ULL, 0x75CC3997D6B1E244ULL, 0x2DF4B6B1996ACFF2ULL, 0xCFF033ACFB982F8AULL, 
            0x7A57A3189DD3B8C8ULL, 0x18842F871790B833ULL, 0x5EF2F7C7E589901CULL, 0xB5AC8350125A06C5ULL, 
            0x9B8D22A363779E0AULL, 0x90366C36FBD13E07ULL, 0x764BC8E62CDD2485ULL, 0xCE9511D4C63CEDC7ULL
        },
        {
            0x23A916A002EDF28DULL, 0xBCE888C70B6C3905ULL, 0x896B395D8C68FB20ULL, 0x5451A8FEE67C59B7ULL, 
            0x6FF7D61A3576BDC7ULL, 0x511E1BAE8365012FULL, 0x01128E28A8734A2DULL, 0x4D0BF4778BBCCFE0ULL, 
            0x43CF5EE1B87D3FC3ULL, 0xD78EB6F225C37D1EULL, 0x293DD74905F99538ULL, 0x313DBB3D664CDE5CULL, 
            0xD7E051AC38C856ECULL, 0x87A9A9D9D0F3F4E9ULL, 0xE3BD0557839CCFA1ULL, 0xF1E17B2C2B302513ULL, 
            0xDA02B8F5A75FBC3BULL, 0x33802956E8D594CFULL, 0x87047971872B9B06ULL, 0x4669CBDA4F341082ULL, 
            0x4B91CD8874FFC9CAULL, 0xF07710FDE47E7428ULL, 0x2052873DD4C31CDFULL, 0x94FDFD0E869557AFULL, 
            0x168834E5F138AD3EULL, 0xE159CC68D77DA2E6ULL, 0x9A5002CDB37095F2ULL, 0xA6763032ED224D17ULL, 
            0xA4D7B7CA184EBE17ULL, 0x598D113E3335AB92ULL, 0xECCF03A3172F5674ULL, 0x794C4E541ADB5E79ULL
        }
    },
    {
        {
            0x745B8403E04A5567ULL, 0x44E1FA14D68BC4F3ULL, 0x6B40FF73939AEA28ULL, 0xE80280DD6478B083ULL, 
            0xF93B4A9FA810F8D0ULL, 0x7EE8D7FE082E97D8ULL, 0xE6DD24A8D8F1D293ULL, 0x9D4F1DCA4BBD1837ULL, 
            0xDF6F58B8E29ABE49ULL, 0xAE67A32A10DA4111ULL, 0x0364DB73E2F78E94ULL, 0x84B208EBAF429AD5ULL, 
            0x859DC5F27D4E42C2ULL, 0x4E7CD29FFE0F41DAULL, 0x4DA1EBC37EE8E7C3ULL, 0x7C769B4974062B95ULL, 
            0xC695274462C07C4AULL, 0x90687173DDF714CBULL, 0x92BB48CAEBCA29F0ULL, 0x2D29068CD7C76FD9ULL, 
            0x105D627A2DE490BFULL, 0x4D1CAC6F4E2D543FULL, 0x4864DF14573C2620ULL, 0xFBB08C5B788DDBE4ULL, 
            0xDFDA2567AAF729F6ULL, 0xAD5948514A5DE0DEULL, 0x0C34C77462FBAB86ULL, 0x085D199CF57DD607ULL, 
            0x9DF293E2CEC53407ULL, 0x4AC4B7F6736F16A4ULL, 0x4BCB3D675D7161A0ULL, 0x61C4ABAA6E8A8E36ULL
        },
        {
            0xCEAF7B462DEE73D6ULL, 0x0A025A88E8FC42E1ULL, 0x910BE7C69DD47B0CULL, 0x7C1A971694BEA66BULL, 
            0x5F783E490285242AULL, 0x21E82284D1106470ULL, 0x6B2F9276CB2C3247ULL, 0x5C75E060D679CE0FULL, 
            0x62E5797107C1FEBDULL, 0x10EE5ED3BB1A4380ULL, 0xBC0923C44CB8FDA0ULL, 0xE297F4626A45AE5CULL, 
            0xBB3A153F968392F6ULL, 0x6C7B512437F83AE5ULL, 0x895F44A071F3B473ULL, 0xB94D536B5B143DF3ULL, 
            0xDDC3667E3FE9FC78ULL, 0x7D930669DE0396CBULL, 0x899312FB7AA18C41ULL, 0x2E0D52EE081228A5ULL, 
            0x236655164F09C4F3ULL, 0x481C35FC975E4E3EULL, 0x026402493701B9BAULL, 0x9AEC6DDEB7EBE01EULL, 
            0x463D017256B69D06ULL, 0x303C7156452F02E7ULL, 0x3D27BB078D684E9EULL, 0x825F02B037F79D79ULL, 
            0x290BD19F2473C0FFULL, 0xF8BB259C2CB1BDB6ULL, 0x3135EC91B1E9C008ULL, 0xF89B7AC9E977EF1AULL
        },
        {
            0x98095755126EB1A1ULL, 0xD26D6C53514D3A4AULL, 0x01FF30DBC612C4A9ULL, 0x585382BCB1A44615ULL, 
            0x597BE448B87A4036ULL, 0x32EFA95AF65895C7ULL, 0x42FC6CFD6104E4A6ULL, 0x6BC20AD0F686C4DFULL, 
            0xA81FF079BDB2EBBDULL, 0x51BDA8C2192579BDULL, 0x37A8633A716333B7ULL, 0x1B1136FAF9FD5D20ULL, 
            0xE73B7788ADF30745ULL, 0xD7FDA4BECE331246ULL, 0xF6BC16C4962FFF9CULL, 0xF5FA273CAE92525AULL, 
            0x61139D739BC49F5DULL, 0x4238DEFE698B31C4ULL, 0x19B91842CBD5BBA1ULL, 0xE929816A34CCBDC2ULL, 
            0x3EC1F275F35CE670ULL, 0x7B9EAF25F316000DULL, 0x092867A01E6718E0ULL, 0x8A54E6096B08C974ULL, 
            0x566900B299681EE7ULL, 0x26D503080114600EULL, 0xEB382F898879F347ULL, 0xD1F8FEB82AA0E083ULL, 
            0xD16B607B6EC88E4AULL, 0x77721FD6940AA2DFULL, 0x51E34AF6FEF20197ULL, 0xA6E118214C987DC5ULL
        },
        {
            0xDE7D888B3EEB24C0ULL, 0x0891ADE0D3353BDDULL, 0x2D14BB8B84E5D4A1ULL, 0x96B802525E7CE1CEULL, 
            0xF8923663C9B86BF6ULL, 0x13A66C809E0A7D97ULL, 0xF6CD49263B12CB6DULL, 0xBDB8BBA9A3E0FC83ULL, 
            0x71E092203133A0D2ULL, 0xDF5D125BD83C9CAEULL, 0xD9C9BA4ED8D6A1A0ULL, 0xB9669633B7BBA8FEULL, 
            0x6644D71BE80F25E4ULL, 0xCEC2B632DD1D92ECULL, 0x74FB80875E0C8E0CULL, 0x6844BD34AB35CD74ULL, 
            0x03E673270669AA69ULL, 0x57F90CD410F98F77ULL, 0x64987F21738F0ABFULL, 0x2D0105EBDF78F214ULL, 
            0xF7B2B03EE6E270FAULL, 0xBE6ACCA13AF3F8F4ULL, 0xE9C4C469C3610F4FULL, 0x52E5B7E6EDC1EADEULL, 
            0x368650972F2B4E1CULL, 0x75F8ED8D7909F037ULL, 0xBD2AF25533C01A3DULL, 0x8F0FA1771B157B68ULL, 
            0xA9AA0C9312A1E8C4ULL, 0xF37AA92CC2EE6FD8ULL, 0x59B05083BC0A5024ULL, 0x609B624581D2021AULL
        },
        {
            0x6262BF96AC57AF6AULL, 0x44A4ED880F9CA704ULL, 0x07FAE82FCA8B7E6FULL, 0x92DDC17F33E12320ULL, 
            0x58CA5C2E31CF117DULL, 0x41B9C313BFD1A7B3ULL, 0x5DD5EE59EE1858EDULL, 0x403E436CA8D1BA09ULL, 
            0x11003DECB937C8C6ULL, 0x789F0EC08882C48CULL, 0x34B563CD530A306DULL, 0x2D6FE98D8011D3F5ULL, 
            0x29E06A42B97BBB45ULL, 0x1F4EB8B089991287ULL, 0x140A0D614CDAFA90ULL, 0xCCA4922F6EDAC215ULL, 
            0xAC061B34F50FFCB2ULL, 0x8A9CC680BDE52C10ULL, 0x50BCCD0426B4BC97ULL, 0x62D3450BAB49A05EULL, 
            0x7186309980052487ULL, 0x91E0A97C440D568EULL, 0x157E210370FFDA63ULL, 0xDB41ADF2DB8A7592ULL, 
            0x785F6CB44FD51D2EULL, 0xDFD467F2970DD23FULL, 0x1F360A9A70EA773AULL, 0x154F63780F07AFE5ULL, 
            0xD6FE32F7579D31E3ULL, 0xAED1C3167FB1F220ULL, 0x2A08320BC6C01A48ULL, 0x718D5ED246FB352FULL
        },
        {
            0xFE47860C12A0372EULL, 0x3646782AF4FBF1C6ULL, 0x39DC474FEE7411ABULL, 0x6742A45F2E995369ULL, 
            0xC6AB59971CE9A3BEULL, 0x1555656084C05690ULL, 0x8059A1C75FAD1772ULL, 0x640BF0D3A26FBE83ULL, 
            0xD9DCD2A6A4B58A73ULL, 0x426269915033C652ULL, 0x1387A36C50BD17DBULL, 0x643EB057CAAC66C8ULL, 
            0xA976838FC08FC416ULL, 0x436373F93ACE1041ULL, 0x2C3AF4E9F58E9D98ULL, 0x2DE37B835BB869F6ULL, 
            0x384426E35383272DULL, 0xCEADD1812CCBAD31ULL, 0xC8799645F7208FB4ULL, 0x73E627461D52D030ULL, 
            0x426EE66BBE5232C7ULL, 0xA3A416BDD09043CAULL, 0xAFEED71FF0FC8F5FULL, 0x3F7678977058926FULL, 
            0x20D048758DF59893ULL, 0x09617C3717DC6B87ULL, 0x67EC8ABC0081716EULL, 0x2FA476391EECECC9ULL, 
            0xA7055143F3E79DB2ULL, 0xF510C5D3D0B294B3ULL, 0xD73CDE4B1200122BULL, 0x0D8CFE085101A3B2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseDConstants = {
    0x30E988CD28B6F543ULL,
    0x399AAE3B9FF5CDA8ULL,
    0x78CCD866CEA4E27BULL,
    0x30E988CD28B6F543ULL,
    0x399AAE3B9FF5CDA8ULL,
    0x78CCD866CEA4E27BULL,
    0xC5B18EC920B4DD89ULL,
    0xA03D1F8AA21D33F0ULL,
    0x65,
    0x22,
    0xA7,
    0xE4,
    0x16,
    0x78,
    0xDD,
    0x2C
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseESalts = {
    {
        {
            0xC5FBA7D47668ACB0ULL, 0x802A17045E81260DULL, 0xC9DD98124CDBCAD1ULL, 0x901EABC4DE1090FAULL, 
            0x1DE32516FE478766ULL, 0xB5CB87576A00303AULL, 0xF6CAA6D46798BCA1ULL, 0x2645348611D1223FULL, 
            0x6F3579FADE7101ABULL, 0x59E661AB7A42FD2CULL, 0xFDBEF6D4056E8C6BULL, 0x6F0EF04D8E432E26ULL, 
            0xEB3C095D70388A68ULL, 0xC7056BE962F67D73ULL, 0xFE9878DEA5B38C38ULL, 0x6857CB6C92937C8AULL, 
            0xAF0B4DD5F0BCAC51ULL, 0x9973808BC7736CB7ULL, 0x4EE96D9AC48F14CFULL, 0x001AABE47BF19355ULL, 
            0x5FEE207CA90BDC49ULL, 0x07C4713710D3EAC8ULL, 0x69FCBDF7BC5E3437ULL, 0x75B37019C9A2A9EDULL, 
            0x9EB850E26318016CULL, 0xD371653838D01461ULL, 0x109463821C7B5D71ULL, 0x2CAE3C3C688F9791ULL, 
            0xCFEC38F75479D939ULL, 0x618115322BD1A3F9ULL, 0x89866EFD6C735F7CULL, 0x7B10FF03BEC67E82ULL
        },
        {
            0x31046523DB8B11E7ULL, 0xF2965286F9FA2B43ULL, 0xC968A5A2C7BAAC82ULL, 0xDAE57F97389BFED2ULL, 
            0xACE174E6BDF14CAFULL, 0xD549D3F5E0A9513DULL, 0x02CA01027A6C94E3ULL, 0xE38E67173EE57029ULL, 
            0x8E56EF62059B9CE8ULL, 0x5B2198AD9A2661D2ULL, 0xA816D4535AA0F643ULL, 0x8F391F4A5735FE5CULL, 
            0xF93E138B9368D4EBULL, 0x38C6D6952AA077B3ULL, 0x125BCAB3A0AE4555ULL, 0xA69DF61FB2259AA0ULL, 
            0xA2F9399F894313B1ULL, 0x403E52D01F77142AULL, 0xA43795E0DA1A852DULL, 0x65754B10F9DC4649ULL, 
            0xA1991AB59A4E4FD8ULL, 0xE7607D9211D4BB62ULL, 0xF87A6F49F36F0164ULL, 0x1529AA4B89961708ULL, 
            0x573BDE2586E79138ULL, 0x402D49AAFB0F32BDULL, 0x255CDE8FC5C818D1ULL, 0xEF66A127ACB69020ULL, 
            0x6C01A88EF1C406AFULL, 0x742CF4E0726F4650ULL, 0x2818374A2663F2E8ULL, 0xB5CA9F2649487522ULL
        },
        {
            0x0C89C826591610D4ULL, 0x3F76338FD86FBA8DULL, 0x68B2DCB6B8D36BDBULL, 0x5505B9C615CF001BULL, 
            0xCA1B33EEEC66A540ULL, 0x503C7AE3B253FD10ULL, 0x4F255F837FEDCC38ULL, 0x9C32D358510F6A3EULL, 
            0x02BC95FDC1984570ULL, 0x6924E4B54FE5B4A0ULL, 0xF4AB9279B484A869ULL, 0x7A38DAFCD0ACB4C8ULL, 
            0x1541A47BF8836401ULL, 0x2524EB27E5B872DBULL, 0x9DF487869359D8A4ULL, 0xA81D0D20D2446CF2ULL, 
            0xE30356E781D1FA4AULL, 0x2E6617DA4EBE8808ULL, 0x255E5EEEF4D3FC68ULL, 0x92AA8CDF12DE8DFFULL, 
            0x23B83C4BF5CF4C0DULL, 0x0CD55C4C9F419D63ULL, 0xBD053DAE4A8D9328ULL, 0x60C04CD1F1801CF4ULL, 
            0x26D607DA22275097ULL, 0x5DCF78D60D090E66ULL, 0x69DF3A37B85591BCULL, 0x84FEBA539609A586ULL, 
            0x9AE1B84E535EA23BULL, 0xC73B500650A8BF44ULL, 0x2B66102F5FC4E8F4ULL, 0x3B1AC88DB3689F00ULL
        },
        {
            0xF49F8A9BBB756934ULL, 0x8F315E0BF55369FEULL, 0x15C311929EFDB1BAULL, 0xAB7FAADFCC2582CEULL, 
            0x6B3A565833A9B54EULL, 0xC5A1DE2A18FB35EDULL, 0xF3F4B8B88CBB8248ULL, 0x020B8281221101E3ULL, 
            0x8FC2E3177DB43699ULL, 0x9D2DDB524201548BULL, 0xDF3F933C642EA49DULL, 0x3AAB24808AA262A3ULL, 
            0x8E9B45186118C3BDULL, 0x217BB3C6A15C1EF6ULL, 0x8F532CD182D4E8CDULL, 0x78C68FE3F0AA4B32ULL, 
            0xA23C810A858F7AD1ULL, 0x80898BD08A078A6AULL, 0x466DBCAC74BF9FB2ULL, 0xCE0EFD87ABA8340EULL, 
            0x951E41689271496CULL, 0xE24448DCA168569FULL, 0xA5EDE34550BCF8D0ULL, 0x4BC9C87D61C954C8ULL, 
            0x9C8AC9926EDBC604ULL, 0x2E51C4C2C117F028ULL, 0x0CECF0ECE71CD33AULL, 0xEA2AA1FCFEA3B968ULL, 
            0x194BB5C1F81966C2ULL, 0x280BBC68EA74758DULL, 0x51AAED9324B10018ULL, 0x5F05922A52BA73B5ULL
        },
        {
            0x70D93E6C65E57008ULL, 0xC85BF16E8B38EFB8ULL, 0xCFB35CE5784E3603ULL, 0x2EAB0F2C0E805523ULL, 
            0x37957F628F5D8DBEULL, 0x7EBC7AB9163C36FBULL, 0xC921C0BD0D12A6B9ULL, 0x5F98DB5F0DB6AB02ULL, 
            0x2AB4EDFA18DAF48AULL, 0x68D2A34974349652ULL, 0x71967EA892E8F054ULL, 0x58D4B991548E3118ULL, 
            0x01B60859A8F45E14ULL, 0x0887BF3BBA8E25BBULL, 0xEA4227FB983863F9ULL, 0x794D99671B34B405ULL, 
            0xCD1BB0BDA16ED35BULL, 0x9E98E2025F36F49BULL, 0x1349FFDB488F04FCULL, 0xBA5B9A0FAD84FAFFULL, 
            0xD80BC3FB89B43678ULL, 0xEF30050EFBABEF6FULL, 0x8DD12D8C7691D877ULL, 0x9E2F255B6FF00798ULL, 
            0xCF4162DCAC582920ULL, 0x6C2B2FF03A7DA006ULL, 0xC9CF6FBFD9FD69FCULL, 0x322B51D77507D43AULL, 
            0xFBA8372533011397ULL, 0xCE69ED1745356A23ULL, 0xD35E5DCD598A21A3ULL, 0x037D363E8F3B34C8ULL
        },
        {
            0x7FED423EB43B4454ULL, 0xC781FB6AC80BA7F3ULL, 0xCE1A9BFE45C496BEULL, 0xCA9A0D43AD090DEAULL, 
            0x5137D843ABE862BFULL, 0x31CE5A81E3C7A336ULL, 0x5F4A787AD6739965ULL, 0x276DC03629C4FCF4ULL, 
            0x438C5F816320B8E2ULL, 0xBEE0D39AC143086CULL, 0xE5503ECB67CED881ULL, 0x7091FBFB16AF81CFULL, 
            0x7CD18E7DE8F6720CULL, 0x17B17540A8C0EFC4ULL, 0xB3139A074E855706ULL, 0x09256D27404DF37AULL, 
            0x82ED9AEB83317B00ULL, 0x85DE4457106C322FULL, 0x44BC86196E9C8177ULL, 0x2DA2706B603762BAULL, 
            0x16987425DC603965ULL, 0xCCB5BD8130F3E6E3ULL, 0x554097F4708CDE2FULL, 0x87E24E960576F282ULL, 
            0x57132D18ACAA9F4BULL, 0xE3D021EC9B8420CBULL, 0xD6CD41AB7A8372AEULL, 0x2C4BD6C31F01C94DULL, 
            0xF8883DF720255EA1ULL, 0x3155F604320F9553ULL, 0x9B6283BDF6956788ULL, 0x188EED71ABBC9A9EULL
        }
    },
    {
        {
            0x404406B03F29EE51ULL, 0x373979A4051C9644ULL, 0x7DD8DD3F9BEDDCCEULL, 0x6C26754FA0AE4EF8ULL, 
            0x2A32CC14C423AFEAULL, 0x75396A956CE0A3F7ULL, 0xA5D4231BFF69293DULL, 0x632FDFA9D825B251ULL, 
            0xB202D2AA72D8B7D8ULL, 0xA07CA11F58500717ULL, 0x5A48F844E4F8AC3EULL, 0x930D013B7F9D731DULL, 
            0xDE52C451CACDDEFFULL, 0x86759B55DA6E1D0FULL, 0xEC167F4EE107C19EULL, 0xEF7A8C56C6BFDFE2ULL, 
            0x4A61D042F18BF431ULL, 0x4EAB40223A5A0729ULL, 0x5F6840A8C0F9A7FFULL, 0xA1FA5F6E598FFE61ULL, 
            0xF44CA3C1001C718FULL, 0x8331BA40371BE8FBULL, 0xE759722557F0CAA3ULL, 0x1A99DCD853AD5784ULL, 
            0x0E484C906ED3D3C0ULL, 0xF9E9079D3F933CB0ULL, 0x7B0298D917E77C6AULL, 0xF840F36B73411D0EULL, 
            0x4CBB5536DD036630ULL, 0xF475362FAA0733BDULL, 0x8DBFF6C2BEB57D9CULL, 0x2B2F6CDE0D5B328BULL
        },
        {
            0x5A9C4363C3905939ULL, 0xCC1A6D2F49A53D4CULL, 0x27205E320BE04366ULL, 0x9A0EEBFFF257BADEULL, 
            0xD6311393BCD5D85DULL, 0x717197A3920F0BB2ULL, 0x1E729BEF64A8650CULL, 0x54E1E38DAC76E57AULL, 
            0x58295004541EBF1FULL, 0x610EB4F78601ADC5ULL, 0xDEB594893C332A71ULL, 0xC2E57A4B2F3C7E1AULL, 
            0x05E3774DCDB59764ULL, 0x5081E9F24F71A5FEULL, 0x688E0FD99ED2D2DEULL, 0x9848944DCCF84333ULL, 
            0x096FDBBC13FB85D5ULL, 0x2FCE665434043D7EULL, 0xADA0BD5C4A62E472ULL, 0x675B4DAFE5FFC95FULL, 
            0x5F51065A5D5AEC0CULL, 0x03B968A133939FA3ULL, 0x18B0C6EB59341129ULL, 0x095D789939076A66ULL, 
            0xCC37060D71676E46ULL, 0xED2094548C26DAABULL, 0x9FEB48E584E81FADULL, 0xD801899FC60116B6ULL, 
            0xA3B793CC238BE271ULL, 0x77241EB02EC528E9ULL, 0xC595C860D547F1FDULL, 0x2BA3426EED039DA2ULL
        },
        {
            0xF2D4A2B4E3C10BC4ULL, 0x37F613AA697FFBCFULL, 0xA3B1343F82BF734BULL, 0xBDBE778AD3DF812FULL, 
            0xC37CDC3C166A68DBULL, 0xDAA46C7AB8CDD7CDULL, 0x7D0236C4377303FCULL, 0x75081BAC32C0E042ULL, 
            0xF4071408FE298C0AULL, 0x92EBDA15BC3E4DAEULL, 0x2338511B4B408883ULL, 0x8BEABD558C801260ULL, 
            0x8498A7A35482E77FULL, 0x3FF09C2243CFF253ULL, 0x74C3BF0083931E5BULL, 0x64EDB99E838A9A40ULL, 
            0x178E85B5EE11EDE0ULL, 0xEDB233332CC96F2BULL, 0x4BB27BE8D479835AULL, 0xA18B281330DBBA32ULL, 
            0xCFCCEE806AB41DC4ULL, 0x14A9A7BBF34C6AFEULL, 0x248ECD724360BF0EULL, 0x6911E81006DD60D3ULL, 
            0x8E872E98EBDD0C61ULL, 0xA6E60D6390442A23ULL, 0x7C3768795BA8884DULL, 0x1B81F53F3C588C35ULL, 
            0xCAE96217B7490513ULL, 0x8FA2446C321F150DULL, 0x9BC3F247A7E900BAULL, 0x37C9B7B1FE25F8F8ULL
        },
        {
            0x25680ED7FE1E6465ULL, 0x4B1B217D2F8A9DFEULL, 0x2518C10EA2C0D368ULL, 0x2305469A48770799ULL, 
            0x0A916D05E10DD43EULL, 0xD6BFC490839E6F3AULL, 0xCADA40FE9329DC43ULL, 0x844C5EAC9B5A783CULL, 
            0x82794CC4C666CF62ULL, 0xBC35D24C6CD8E01DULL, 0x370BEF674DBFB461ULL, 0x278BECBE1E136274ULL, 
            0x4B7D5C37783C4DF3ULL, 0xFC8F24C6ADF478AAULL, 0x476857354F1A0C85ULL, 0x9841E7F03F64C03EULL, 
            0x809875C7A21211D6ULL, 0x21ED2C7C47F4558EULL, 0x3A77DB668083FBDDULL, 0xC5778A0CB63A2003ULL, 
            0x5AD186CF33F33E34ULL, 0xA6B1D9D8379721D5ULL, 0x6DB4562B1A1CB65FULL, 0xE1D10A116EAD1E05ULL, 
            0x4469216962AF7731ULL, 0xDCF526C0C9D6DE27ULL, 0x1484A545E268B506ULL, 0x21A6440766AC8BA1ULL, 
            0x1002D3C038C63ADAULL, 0xAA816F495D2C64CAULL, 0x7BC579A7569DBC5FULL, 0x6F223D0AEF233C29ULL
        },
        {
            0xD4C007E98BF6683AULL, 0x66B2DF622DE091B0ULL, 0x96FA18D2C3C1810FULL, 0xD3444CF03ACD7059ULL, 
            0x801E01112DE288E1ULL, 0xF75A0F863905B0CBULL, 0xAFDFDD57952F51E4ULL, 0xA8567A2EDFE7CDB9ULL, 
            0x0FEDA6F0B24727CFULL, 0xF450AD81DA78CBC0ULL, 0x0ADE29C534B8C1BCULL, 0xE15E29E563EAED94ULL, 
            0x12FA58B19EDA33A5ULL, 0x741C5532C5AE58BEULL, 0xD70E86FC407F2340ULL, 0xB664A7B8AE90A889ULL, 
            0x084A185CBB4C964DULL, 0x74B6ADB69FA8A135ULL, 0xBE3CDFDF02BB55C9ULL, 0x84FEF91364A7A6A8ULL, 
            0xEEF0548F64CDC24EULL, 0xE5BDE85949D5DC91ULL, 0xB07269845C584A1AULL, 0x838047CF0A5AD6ECULL, 
            0x874CB7BAF2483073ULL, 0xCF782F86FBF02453ULL, 0x862D70442D7DD0F8ULL, 0xBCEDBB18409363EEULL, 
            0xA211DC9656A957D3ULL, 0x9CF23A8EA7D29735ULL, 0xFDD248221F35CFC0ULL, 0x10F1793D6F3BA782ULL
        },
        {
            0x889329AE29452892ULL, 0x32CD384D5C7B6442ULL, 0xB0BA33D718093C33ULL, 0x8B8FEAD4FCEA5D59ULL, 
            0xB95C6F6A21716E95ULL, 0xD03BF19E4C7CE35DULL, 0x4BF16C9D94309E24ULL, 0x3A08EB7788C3AE6AULL, 
            0x253A90DD5CFA5A6AULL, 0xBB88B449313331C5ULL, 0x1ABAA818E84C768CULL, 0xFE483A816FE9139BULL, 
            0x0019ED8B6E99FEF8ULL, 0xD55DFDF37C77474CULL, 0x43AE7737CFEF0E60ULL, 0x3AA542EC0DF26289ULL, 
            0xA2D0B47F8F4BCA8DULL, 0xB526A2DD8B560AFDULL, 0xDED1617D202EE1C3ULL, 0xC09E681B2654B139ULL, 
            0xD9568271997C3CBBULL, 0xA9E21DA28B0045CBULL, 0xC3180ADA721EFC26ULL, 0x0FBF25F614F8046CULL, 
            0xC1F749966AE91662ULL, 0x4597EFFFE1FB3CBBULL, 0x48A56E1CF97DA0BAULL, 0xA5F59D9E6A3C5FC7ULL, 
            0xC31DF60A38173688ULL, 0xE964C751DB1E54F3ULL, 0xBAF309AC226AE8BCULL, 0x73069651B21E4870ULL
        }
    },
    {
        {
            0xA1147A27CC0D2CF4ULL, 0xC7B777F3C20BC4FFULL, 0x4FBAB7AB3E4ADCDEULL, 0x01EC8FE7AF02D180ULL, 
            0xD150067B93B3E8E4ULL, 0xAF41AFF0C80D094EULL, 0x77CEDC6EC60B24F8ULL, 0xB2F018C397C94A0AULL, 
            0xF821C397741A7634ULL, 0x572F95DD951AE078ULL, 0x5A5EBACCFB660A12ULL, 0xD212155CABE9B63EULL, 
            0x55F26372CCB61EABULL, 0x0C01AF9D5133B3FBULL, 0xA1B873C7E99089B3ULL, 0xD6F76ABF924A5456ULL, 
            0xC28FC042957B0A8FULL, 0xBCB0702A61B39BB6ULL, 0x31942A69D4143E6AULL, 0xDDB36AEF40375D66ULL, 
            0x826A1C5EDB632F74ULL, 0xA1A3E67F6DB1D76AULL, 0xD194AC423729DDD7ULL, 0xBB1808608F23D434ULL, 
            0x240CFF93EB590201ULL, 0xAC8DD20F26FCBADBULL, 0xD02E4539EA9996DBULL, 0xAA3C84C74F88CB0AULL, 
            0x85B08AA76318925BULL, 0x1592CAE7A2A54330ULL, 0x53F0BC495DCC82B5ULL, 0xF7FE9786F4E04AF3ULL
        },
        {
            0x16E285518EAB2778ULL, 0xD8A3E238863A729BULL, 0xAD1BCA9FA8B69F02ULL, 0x0C3C84C3E2955A21ULL, 
            0x77BD827DFF7EA501ULL, 0x4111F1A5C23C4B11ULL, 0x059B49906E81CFD1ULL, 0x4E331AFCA55500F8ULL, 
            0x6662F1A738AC8F59ULL, 0x467EB65CC85DCFE8ULL, 0xB4E9C3139A622CD1ULL, 0x7A10DFC09AEC34CBULL, 
            0x9FAC9D05A422842BULL, 0x25997D3C02FF17A9ULL, 0x841C8739D507D748ULL, 0xBD728F5BD4175DECULL, 
            0x27D056ECE83B0791ULL, 0xB851BBA506A7F1C9ULL, 0x4C57E02C1044E7F0ULL, 0x8C8BC49A5B25EEE6ULL, 
            0x07DCFF4571CE01FCULL, 0x29FCD9FF6359B8C1ULL, 0x52501D2A12238275ULL, 0x242226332DB7793DULL, 
            0xB6401BC78388B57AULL, 0xCCDF92A6D76586F8ULL, 0x86D6A6E59221B334ULL, 0xFC9C34CF9C1210EAULL, 
            0x6DD936E606DBEA17ULL, 0x4BE6568DC95905D7ULL, 0x0E4538A7E47E0348ULL, 0x40ED1CCD5462F57CULL
        },
        {
            0xEC5361759D254E4EULL, 0xF9BA4FFEA026C75DULL, 0x65C4C1E044F15E67ULL, 0x6E831BEA5C92F25AULL, 
            0x9926D6CE8D286C3BULL, 0x892F6FF14E357EF9ULL, 0x7933B1FA0229DA26ULL, 0x0D300B54980B4B45ULL, 
            0x4959931D29DBA178ULL, 0x05CCC93A43B76A22ULL, 0xA0996E672476AB00ULL, 0x7675CB88643D5A05ULL, 
            0xAD6FD372B8BCC32BULL, 0xE8B605C9EA8555B5ULL, 0x46751AB4789E8D26ULL, 0xE50972CDAD883E52ULL, 
            0x55D157808207CC61ULL, 0x1EA98AF7DC8648C0ULL, 0x299CE15F9AF2E76DULL, 0x8945D0D2DD0E72CFULL, 
            0x828355E15E5B7149ULL, 0xDE2F25B153014EC3ULL, 0x28D767820052DAD7ULL, 0x95CAAED0D486B9E9ULL, 
            0xCAA1E17CF3CADF83ULL, 0x5AF08A3DA434DFB9ULL, 0x86835163AA67BA5CULL, 0x66039E6301B2C894ULL, 
            0x3E80BF004365F62EULL, 0x36083CC26687BA6FULL, 0xBF17951B2E6441EAULL, 0x901622B64FCAEA96ULL
        },
        {
            0x1182360BBEA37384ULL, 0x134807B6DF53DF6DULL, 0x45CAA503CD8F6D9DULL, 0x9FA5CD4D5BDD4A51ULL, 
            0xA6EE98D8DA87CEBFULL, 0x118971019EC5EC7CULL, 0x612B28C017332A77ULL, 0x8FBE673C7FDA2943ULL, 
            0xEA56B13A2083E17DULL, 0xF1F77D91838D4277ULL, 0x194201FD25B9EAA2ULL, 0xD2A5426FAF68A0FFULL, 
            0x796E07DD8317D41DULL, 0xC7BAF51C50D6214BULL, 0xBE4AC6BE2F3FAF55ULL, 0x080952A95E61C8D7ULL, 
            0x61863BB27CE56072ULL, 0x4CDEB4E0F52963DCULL, 0x32AC3639320A1505ULL, 0xDB390339B323DF40ULL, 
            0xCF66D19532E90B4DULL, 0xA187A0C84958DF07ULL, 0x340FF4D477F4A66BULL, 0x6909C88DD669FE1EULL, 
            0x744BA78AA7AFFC88ULL, 0xE5176A7846A009BCULL, 0x0E6CF5E0F712F2D2ULL, 0x3366AA27DB644584ULL, 
            0x3DAB1602B2873914ULL, 0xA50E7F74440AC648ULL, 0x3344531304DFE5B4ULL, 0x537038D9C20F1049ULL
        },
        {
            0x8E5E299D821B28E1ULL, 0x97FDCC9D06C8E3CFULL, 0x6FD978C766DF886AULL, 0x7B160BE0C3402168ULL, 
            0x6740EB1BE63C3B86ULL, 0xCE482DB9B3061A94ULL, 0x73484ABD0448D819ULL, 0x8B79C0F66B32AA91ULL, 
            0xA4AF81AFBC4EEB4EULL, 0xE881BCD5FB26199CULL, 0x76007E3CA66E2C03ULL, 0xFEBE4F6EB7E0488BULL, 
            0x663DDE1077A19557ULL, 0x6305F5B2BB6F7EC6ULL, 0x6D33CAF64C5B8CB4ULL, 0xA7A34AFCEDAAF3C0ULL, 
            0x01DED1172CAC95ECULL, 0x1E2570CF97904294ULL, 0x2BE4AA3499F24043ULL, 0xAD781BB3EBF42EC5ULL, 
            0xC0258E3537987D95ULL, 0x284B137DBFE7B62FULL, 0x328021CE0A8FEB28ULL, 0x1F675662FB02263AULL, 
            0x185FE8400358EBCBULL, 0xDEEEE57F73865CEFULL, 0x6BC451E5D6C83783ULL, 0x6DF57BA4D731A872ULL, 
            0x9B2D51B2231CAECEULL, 0xAE964DC04F47DFB3ULL, 0xCD92872DEABDA89AULL, 0xE98827ED7A01AF44ULL
        },
        {
            0x473FC2D2F4EEF692ULL, 0x97FB26C6A555F6A9ULL, 0x0366B1B4A793C625ULL, 0x31ACCF2A7748D9BBULL, 
            0xAAC65C7BA15DC9DBULL, 0xC7726F1FEBD063E7ULL, 0x2EE8FAD1FDF733B4ULL, 0xE44890DB4CD055BBULL, 
            0xD99E6260C0BE68CFULL, 0x1336DB0D07F4E64BULL, 0x1D27DE66A9B16028ULL, 0x89246BCD7CF55C90ULL, 
            0xD0B89E4F31513D46ULL, 0xD0FAD4B29868C361ULL, 0x9D3330C5AA8A0063ULL, 0x1411A202CC7F9ACBULL, 
            0x1A33352E61DC92C9ULL, 0xC22F68D2C1CF7549ULL, 0x467911051F1A040BULL, 0xC5F1CFD7E458C749ULL, 
            0x0607A60C02565316ULL, 0xA82AFF8A27AED06AULL, 0xC36F23A0E419C0BCULL, 0x63C96E7EB7D6DC5EULL, 
            0xB0B67C9B17DCECB1ULL, 0xC43C3D5E1E12E245ULL, 0x3915EF9E3376169FULL, 0xEE7B167B4E953CD3ULL, 
            0x7FBF0B40548DABB7ULL, 0x2CF696F2649A453EULL, 0x2F08C6EC056A05CEULL, 0x7E155151109DEEBDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseEConstants = {
    0x853F5BCFE4D8BB34ULL,
    0x13C99149114C1BC2ULL,
    0x47D9CFB317FECD4CULL,
    0x853F5BCFE4D8BB34ULL,
    0x13C99149114C1BC2ULL,
    0x47D9CFB317FECD4CULL,
    0x4275CEC2CDEEFEE5ULL,
    0x2D5BA6412C3F8C89ULL,
    0x97,
    0xB4,
    0x74,
    0x59,
    0x6F,
    0x80,
    0xF3,
    0xC0
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseFSalts = {
    {
        {
            0xDDAD25E77FA50DCDULL, 0xFC7969252D3C6DAAULL, 0x0EEA9E933F87C515ULL, 0x25C8CAA4E03B5CCEULL, 
            0x2AC8F76A2B4DA36DULL, 0x65579FA09233B5D3ULL, 0xED8960495EE6F2E6ULL, 0x0BB3B11F7D7C7FE0ULL, 
            0x99A03B60AC726932ULL, 0xA06A24184582010DULL, 0xAF5B88E1AD6EAE94ULL, 0x6F3B0E0B9182C750ULL, 
            0x24C1BD5CC8966BA4ULL, 0x081ECB7764E640A5ULL, 0x269E531E6731A0FFULL, 0xF883202F440D93FCULL, 
            0x9ABEA412C2EEF1EBULL, 0x12800C72E67D1E90ULL, 0xB077A127B8546469ULL, 0xEAD7B22AC646B3F1ULL, 
            0x3DD15F346F65C944ULL, 0xBF1CD1575C9F75FCULL, 0x7DC36950FFFD9FCDULL, 0x3CBCA0C281A9D589ULL, 
            0xD0EEDF054F9B61CAULL, 0x8DF814A2FC6C59C8ULL, 0xC4A1744A6D8193C1ULL, 0xC5BE00F6D329334BULL, 
            0x08A3CF7A2EC407ADULL, 0x6E19A5D72E421383ULL, 0xE5D86A42AAC32794ULL, 0xD29A7B39C2795028ULL
        },
        {
            0x193212588D3C9F4FULL, 0xBEA8CDC9685710DAULL, 0xD0A5FDD69D6D86F4ULL, 0x4ED74FB503659967ULL, 
            0xE3D80126737C575CULL, 0x4E290CD9AF46F154ULL, 0xAA43821E7964C283ULL, 0x1EA6355254A45835ULL, 
            0x4C993B32E34A2B42ULL, 0xBF06AA9650BA4631ULL, 0x51FEC39AE84F059DULL, 0xB4C24AD9A54677D5ULL, 
            0x621537D5EC13AA7EULL, 0xC5D05FF511CB8615ULL, 0x3749E5ECF9EF6D7AULL, 0xDE7E9960718C9350ULL, 
            0x4854745906BD1353ULL, 0xD45311C448DEA099ULL, 0x1965097112C92780ULL, 0x0613BDE91A820A05ULL, 
            0x0D0C4FD4991742A5ULL, 0x33BF9349ECE66B03ULL, 0xD33A6563D3EBCDE7ULL, 0x41AA64942EB73A09ULL, 
            0xECFBEC5B827AE5C0ULL, 0x84AD555DC42F00E9ULL, 0x9455A933A5981463ULL, 0xC0FEBC75C080BAE5ULL, 
            0x3871E8464E7E2D41ULL, 0x138E7A3354E40D90ULL, 0x309828F0FA400710ULL, 0x0185BDAB16070F2DULL
        },
        {
            0x5C133A27985D3160ULL, 0x4D3D876E8A041675ULL, 0x23D644D803CC5C6CULL, 0xB6E2B65F5F3B011BULL, 
            0xBDA367B3DCFDAA0DULL, 0xD6D904CD8DE90C1DULL, 0x681DA521A3FDB116ULL, 0xBFE8B8E03B2DADCEULL, 
            0x8AB69BCBE4A8D6EDULL, 0x2DEA9C3BEEC0C853ULL, 0x3B8CE19CF0A02C11ULL, 0x1B7AF1F4A1751C3EULL, 
            0x4896E7BD48C8232DULL, 0xEA91E5007FD6018BULL, 0x037E804BE177561CULL, 0x5207A8A640480694ULL, 
            0x2999360AE8286A38ULL, 0x6C58947BCFF117EAULL, 0x03A6A8FC79EAD4E1ULL, 0x277B42B30A3DB838ULL, 
            0x3F04CB55BCD08567ULL, 0x7AAF7B31BF0C5D3DULL, 0xA740AA61A7C0A054ULL, 0xB45B54E159CC67F7ULL, 
            0x81905711026910BCULL, 0x5DFAF93AA57D5BAEULL, 0x8CE664F9F904D6BCULL, 0x8FE0177F9CE15C4BULL, 
            0x2B0E642B487E4D0BULL, 0x4F1816C6B8244BC7ULL, 0x41BB3D0D77FE2378ULL, 0x811DD631A52CB1EFULL
        },
        {
            0xAE276D17A60AC9AAULL, 0x076F002BD9223698ULL, 0x0F42EB8CACFC68C1ULL, 0xFD6FFA4A151C7DD9ULL, 
            0x4D35FDE4B57D4D4DULL, 0xCF72B5D01F672AE9ULL, 0x22B03D7232360CA8ULL, 0x024A2DB658E40E9AULL, 
            0xEA5EE1F3491E150AULL, 0x768B2D9423675C12ULL, 0x5832637454D995EFULL, 0x9788780E781D8900ULL, 
            0x3BD222D6D38044D3ULL, 0x0BEE5091A1BA4FDEULL, 0xD84945DAE5443689ULL, 0x3A2EB9085B8589EDULL, 
            0x9060B274E533928AULL, 0xC935F0449A10BB43ULL, 0x030430075880998BULL, 0x6E6469706EAADDBDULL, 
            0xB65F53D5B1520C7FULL, 0xDCF4ECC9995498D6ULL, 0x422D53E9BD4E9C56ULL, 0x898F60EAC2FAB30FULL, 
            0x9A8D79ACEF0BF9D7ULL, 0x7722AADC7D9CB4FFULL, 0x2FD737C22EDBFDECULL, 0xD23E52810085CC14ULL, 
            0x5812D34B4F495F14ULL, 0x2B4E4FB1936FEC6CULL, 0x911AE79CA71D5A78ULL, 0xA9A95ECABD3542FAULL
        },
        {
            0x70CCA98818A6CF38ULL, 0x89E4E857B4ECB13AULL, 0x0CC4D414753B422DULL, 0x27244E0C8F3B21D9ULL, 
            0x1966B8082C055F78ULL, 0x8AF3E8A067F459B5ULL, 0xA919BA9596015137ULL, 0x513C6E094A1C9F3CULL, 
            0x6A0BCF65B5E90B8CULL, 0x228F0A6B88199950ULL, 0x90A10672AB7D2707ULL, 0x5427B08C67F26C7FULL, 
            0x74371F3694B7D806ULL, 0x6CC7092F9E602136ULL, 0x814B44A2B9285A83ULL, 0x694F71BEF21F6FDCULL, 
            0xE04E61C3DDA8AE85ULL, 0x5A353EB82AB3EC41ULL, 0xDD51DE17D61B69EFULL, 0x8D9AAB1BB9C089EEULL, 
            0x1AB58DA1EE416CBFULL, 0xA0EF847A3D4EAEBEULL, 0x7137C926100A500DULL, 0xE34C86C763AD30FAULL, 
            0x2A0146FA5CFCC42DULL, 0x61C6F9022E931275ULL, 0x3A98D70D668050ABULL, 0x397A290473935E70ULL, 
            0xBB31AD0F8C5A1906ULL, 0x7070D41C70D38F0AULL, 0x7C3CCC56BE9A6DBAULL, 0xF3E380845604B1D7ULL
        },
        {
            0xC5E2B35D5C072B9EULL, 0xE8F9A8A2477245F2ULL, 0x66E2A3447F28954CULL, 0xECAC02D65519E950ULL, 
            0x4C00080966A0C816ULL, 0xE1B6AB6666BF641BULL, 0x8C8793CF462D4A5EULL, 0x5B385642EA1BE00FULL, 
            0xE60532589EB96799ULL, 0x3E3D5989F618E22EULL, 0x7F1B9487A5A533AEULL, 0xA40EC841842E8525ULL, 
            0x81191E2504A7138FULL, 0x7B104B538B018681ULL, 0x109EC06C87BB2937ULL, 0xC63CF706B771C0AAULL, 
            0xFB2878AD9B60928AULL, 0xB2CCEC8800750CADULL, 0x1C4B69050FD270FBULL, 0xE9F2D3843AF8ED8DULL, 
            0x1CD0B9E29D2C7AB6ULL, 0x21F0ED028F912B68ULL, 0x536A36F36F46067DULL, 0x809C1BD782E669BBULL, 
            0xDC8560F117BB5D85ULL, 0x22719836B20A8511ULL, 0xB4C83E34CEB1FAC5ULL, 0x5CE77A988ADE9DF8ULL, 
            0x2B600A106CCEF343ULL, 0x7C872F49D7B55805ULL, 0x58DB8ADD872BB9F0ULL, 0xD4B00FB3C6172A78ULL
        }
    },
    {
        {
            0xB16B276B25453F6AULL, 0xFA59E060688CD99FULL, 0xBD3EB916DD0D3A69ULL, 0xA9DC6C75225DB164ULL, 
            0x5BCAEFD0311D31ABULL, 0xF86D8129BFA19871ULL, 0xDE3E949C7880F9F7ULL, 0x8ECFBD86E3B5483DULL, 
            0x4836A293D6C55677ULL, 0xB6C45C0594486651ULL, 0xFE5D6E945EB0C84EULL, 0x6EFC44DEB3384DE8ULL, 
            0x24D74CDFD6889855ULL, 0xC11F58904954CF20ULL, 0x2612B0F866667503ULL, 0xB2B0490157071E72ULL, 
            0x1828C3A3FCA3E212ULL, 0x772CAF7E8ED746C1ULL, 0xBBF7697846534B30ULL, 0x3E925F181E8CC85CULL, 
            0x745CA8E0165C3419ULL, 0x6AFC41B7FA690DE5ULL, 0x9533660C45D83A98ULL, 0x3E090BBEBF82DCE2ULL, 
            0x057C45FE768EF990ULL, 0x6CED7886A19FB14DULL, 0x8E25A5416DECE021ULL, 0x299DA3465FD36222ULL, 
            0x03CA4EC2F6A77237ULL, 0x846CB627673827D0ULL, 0x8C7FBEF719478557ULL, 0x5E0ACFA2FAF0AC55ULL
        },
        {
            0x23A509DA40FA63B1ULL, 0x44AF19CFA093FA5FULL, 0xE340325F3A68D693ULL, 0x62EE546BC19B0B9CULL, 
            0xAA704B58912EA3C3ULL, 0xC99F6BAB82500C29ULL, 0x286F9ECB7243F040ULL, 0xD07F850EFDF633B3ULL, 
            0xBA11628C5CEC6E12ULL, 0xE607AF9BE12631E1ULL, 0x06BCFBB4EAADD44AULL, 0x407637A08764DD07ULL, 
            0xBDD6333C72A63D0DULL, 0xB3CDAB51BF3EA35CULL, 0xC0A6C6850CDBF116ULL, 0x1A5FF24B454C8187ULL, 
            0x1B57E332B8E16DB4ULL, 0xE2D3F626A47A2E79ULL, 0x78FD044357435D62ULL, 0x6FA0F440080B3E16ULL, 
            0x191BE0F49B9D8549ULL, 0x51DBBC566AF0E612ULL, 0xDF7D40A533D3C6B8ULL, 0xE1EA010170916495ULL, 
            0x00DABE02110DDF15ULL, 0xC3E6E5CBE5A05522ULL, 0x5C2DD8ECC7F3E9F2ULL, 0xFF55F1B1188B56D0ULL, 
            0xED3B66492E3D0678ULL, 0xC345509454ED6B58ULL, 0xF5F1F213B57D241DULL, 0xD2F47B5AE0A00731ULL
        },
        {
            0x828A9E1518AB5E4FULL, 0x5F4D9BCFBD03AEBBULL, 0xD3909AEAE9DF4C70ULL, 0x32908CB5A5CB071CULL, 
            0xD8558B733A1C5FB8ULL, 0x07124EC9AE3BAEDFULL, 0x36447614C606297AULL, 0x9BBE7B1343F8863DULL, 
            0x0C3E5C9B8695F01FULL, 0xD6180EF483A46B16ULL, 0x90DE49D4855E600DULL, 0x6433847DF4155AE2ULL, 
            0x43DE4A5B63AB76E4ULL, 0x35C2F8E4B2CFA79FULL, 0x7EE29ACBB189C1FDULL, 0x224D4D2032B5FF36ULL, 
            0x210B3A15DF82366CULL, 0xB7744C48687921E8ULL, 0x659A20BC50A2DDD4ULL, 0x3616D24BAC3C8716ULL, 
            0x71B12B9290F78DA0ULL, 0x035B5E9A93D65484ULL, 0x519BA8C36774A0F5ULL, 0xB85864824E16C38CULL, 
            0xDBEE26DB7FC39305ULL, 0x148EE804B5C0AF46ULL, 0xDCF38AC4E7ED7FB9ULL, 0xC273B1828E0E36D8ULL, 
            0xF3953F2F3887AAF4ULL, 0xC665E09756E2E3AFULL, 0xDEFAA43D064F1BA6ULL, 0xE5FFE51791B80049ULL
        },
        {
            0xE2125BD3586773C1ULL, 0x7AD07A2F7C815A67ULL, 0x515805C9D100B8EAULL, 0xE01644B2EF40028FULL, 
            0xDB6B8FA83F328688ULL, 0x89CCBFD95E06F737ULL, 0x09F735711AEDA0EBULL, 0x6D106DFF05F272DBULL, 
            0xD6BA724C02B93FABULL, 0x730B40CEED652B5CULL, 0x9012CC1F4A730F9AULL, 0xB46D141F80837DF7ULL, 
            0x46B815F12BFF60F2ULL, 0x4BC8C63DC17BBC09ULL, 0x81E5E7CDA6B83958ULL, 0xD6C7D9322CD1FEE9ULL, 
            0x48813B6712AE87FDULL, 0x19D9534D5733BCE1ULL, 0x05B23383E9B6A64EULL, 0x56834B9D822DD6E6ULL, 
            0x22833200753EF997ULL, 0x8273BDD5F5E19670ULL, 0x61D2AFFCA2D6F7E2ULL, 0x879D9CB9AD008B78ULL, 
            0x8EBFE37E3BE175D1ULL, 0x45DC41014ECBCB99ULL, 0x3E063DF6329B63F1ULL, 0x997C691E57B405DEULL, 
            0x164D407C3686B740ULL, 0xB2ABCC6231FF42FFULL, 0xB48283A21A0735DDULL, 0xD7B459706F71C9C1ULL
        },
        {
            0xDACE91434B8ADC26ULL, 0x9486B9B906110559ULL, 0x6004603E9CA33EF9ULL, 0xF18F441B97913345ULL, 
            0x4D1155E607C5DAA7ULL, 0x60682A7CD4EE1FB8ULL, 0x31956C90CBCEF2A6ULL, 0xB5FD771AC246E5F5ULL, 
            0xB2591819D7DC6CF9ULL, 0x898E39E06DC7B54BULL, 0xB13BD6ED0C2AEE40ULL, 0x2D1F23901E3C6EAFULL, 
            0x75F6E1EE5C705570ULL, 0xCDF99B266C54BC06ULL, 0x6F8627385457EEF3ULL, 0x6498D4842A5D37A7ULL, 
            0xD5EE01E879CC633FULL, 0x0D2C24A17518F3E2ULL, 0x3740E135F889F601ULL, 0x46FC82D47749CE9AULL, 
            0x93154D98FE100018ULL, 0x8FBA60BD572B7A53ULL, 0x7E59B3F766BA72BFULL, 0x6AAA7C272305E641ULL, 
            0xEF893E7D36840D89ULL, 0x8D0912268D208939ULL, 0x8F46931B7A783C2EULL, 0xF499B5C141688371ULL, 
            0xDA292C7D59A08471ULL, 0xEF99B9CA48267EFDULL, 0xA8A203C0D563751CULL, 0xC6449C2ADF0F07F7ULL
        },
        {
            0xDFF73CACD1AB5571ULL, 0x6160B6CA51D8CF76ULL, 0x7E7C0923A8FFF781ULL, 0x6EFF35502EC317E4ULL, 
            0x12E9896FE628717CULL, 0xD4CA077BD3EEA174ULL, 0xEBE5052D50D53F3EULL, 0x60D883AD6D3DFEFBULL, 
            0x369658DF465AA75BULL, 0x385E595F9FA5C9ADULL, 0xAD950D23CBFE7072ULL, 0x70B73F5B63DFFB6DULL, 
            0x8DF454477E158C18ULL, 0xFF2B655256837DD7ULL, 0xC57482D78080513EULL, 0x2E7E055E4983F8C3ULL, 
            0xF26F43DFFC67ECD5ULL, 0x1956C51E24747449ULL, 0x8BEE7311CC0C8D7BULL, 0x7105FDF6C4CF8496ULL, 
            0xE88CC05597CE3F35ULL, 0x0E6EC6FD9CDAB616ULL, 0x841F41100FCFB472ULL, 0x79CBD9DE9F8C3F7FULL, 
            0xBF9A39D3A29059B8ULL, 0x38421788FF4C13C2ULL, 0xF8B03CAE7C328198ULL, 0xB469F88FEB46A5F9ULL, 
            0xDA0067259138352AULL, 0x24EC0EBF1E0B410AULL, 0xD2680157ABFD0940ULL, 0x907D2DABFD79CE02ULL
        }
    },
    {
        {
            0xA734D6E8A53544C3ULL, 0x81AF04111E79371AULL, 0x6AB551C49E70326EULL, 0x5CEE79828EB7F8A3ULL, 
            0x18F833CD72919531ULL, 0xE83DDAF38C5CEC7FULL, 0x606020508076D4A6ULL, 0x802C9E65B47C1246ULL, 
            0x40B5B1F97B8505A6ULL, 0xFCBBA66564E6BA85ULL, 0x9959910798ABC315ULL, 0x9432545E7E9B055FULL, 
            0x4759B62F07BBFCF9ULL, 0x4F9FC80C2C457F9BULL, 0xEF3D7771E5ED962FULL, 0xBEFCC6678436277EULL, 
            0x445E73A80B84DD41ULL, 0x9C53933713FF5277ULL, 0xA7316E20BC8A88A2ULL, 0x54198E04B6815134ULL, 
            0xA431D45CE683078DULL, 0xA87933DB47B381E1ULL, 0x1D03EA1E3DEF4E31ULL, 0xA78C595F169CF10FULL, 
            0xCC806A1624F22339ULL, 0x80EFB8B5E60E3A23ULL, 0xEB82CA70DB10C9FFULL, 0x2905FB9A0C07253BULL, 
            0xD6DB032010C0D1A9ULL, 0xE3218A85547BBE25ULL, 0xBCDDF2AB4764E9B4ULL, 0xD61F5704161D1AF3ULL
        },
        {
            0x325AD940A44FDEEFULL, 0x3AFBD7401C8A9718ULL, 0x2C2BCA0FFBA9458EULL, 0x2BDEB5742D0BEA8EULL, 
            0xC0AEB6CC813AE965ULL, 0x45DB6B36ED5AE880ULL, 0xC60A3922D70E3B4EULL, 0x1CE380408446E818ULL, 
            0xA4BBD2EB375DDC39ULL, 0xA64FC82EA8EB0994ULL, 0xC978F1CBD58C0762ULL, 0xBE2508DE3DF77AE2ULL, 
            0xC548C16A3BBC2A41ULL, 0xEDCC10373F0FA2F8ULL, 0x5FCA44FA57EAB7DDULL, 0x61C43E87AC964F39ULL, 
            0xB105C7722EA405F5ULL, 0xCA7F03E332429663ULL, 0x15EF010F21321FEDULL, 0xE632587DD48E9DEDULL, 
            0x263CDAD8C99B9655ULL, 0xA5E9E544B6BE20AFULL, 0xC8063A929D6EBECFULL, 0xAD73EB57F329304DULL, 
            0xDA484ED6C37D16E5ULL, 0x28920B0C6BF3F37CULL, 0xD2E9A8FEB399A95DULL, 0x5ECB805D48DA6A94ULL, 
            0x495FFAF5EA58CB21ULL, 0x02BE27303D418C9DULL, 0x19B7CF43B6C0F948ULL, 0x3091576A312850A9ULL
        },
        {
            0xF1BAEA8A3D9638E8ULL, 0x70BC9520D6628E05ULL, 0x7D154648813F34BEULL, 0xF8D49590AB63A5D8ULL, 
            0x50A3EB426BBE568CULL, 0x8E9307ACFF49452EULL, 0xDBBCE1250221728AULL, 0xDEF29E4B9FF73A87ULL, 
            0xF655501C1A0BAD79ULL, 0x24ECA09B9A9461BCULL, 0x7E87A14220A43811ULL, 0x25BCC504CA0E7C4DULL, 
            0x398B8E73B5AF18C4ULL, 0x3E71D08780A64CE6ULL, 0x4A78B952A870029DULL, 0x2EC7E593137F1CB6ULL, 
            0x9FFC61ACC1AC3446ULL, 0xFC3C534B3F227E06ULL, 0xD61152A39A7F554EULL, 0xD62BE3129FC81ECEULL, 
            0xE1E9B99F7F942CCEULL, 0x996F68E21AD1A654ULL, 0x7D1C20C267C7257BULL, 0x5B278B297D9D8292ULL, 
            0xFD6B78AD53F17010ULL, 0x2DF24BD3BB606953ULL, 0xF6B5D628410E467BULL, 0x61D54AC8C7CEAB47ULL, 
            0x9DB82DF439B731D7ULL, 0xFAB61A315DDBEC2AULL, 0x44D37EF87CAF0E50ULL, 0xCD62FDB265F66C1CULL
        },
        {
            0xB9C3ABE173077E79ULL, 0x1D50630AD21D3414ULL, 0xCADC59D819E7EF41ULL, 0x9E971568ACC4D959ULL, 
            0x4CB38A754DFFB8BCULL, 0x7AEE812A8F1F9AD1ULL, 0x04C6A822B2276F0FULL, 0x501A55A7919753F3ULL, 
            0x230134A32678CF48ULL, 0xDB71D70F9868FA4FULL, 0x0DCAA3E7A9A6E160ULL, 0xC6CA95D5B063B51EULL, 
            0x808ABD8ABFA5604CULL, 0xFCAAA9EE151C0D7AULL, 0x62932CF9AA4E57EDULL, 0xA9D8FF5AB463A6BAULL, 
            0x7D04D9B2C3727F53ULL, 0x11F4536825AE83A2ULL, 0xDCC61FD461C4A20AULL, 0xFC4B6E62752CFB53ULL, 
            0xAA56D129C885D5FDULL, 0x84B73EF2398B3DDBULL, 0xB5CAECCEC5C61E7BULL, 0x0E8C7A90FE7AEDF8ULL, 
            0xCA2BDC287B3AAB20ULL, 0x367D5EFDEDFA07D0ULL, 0x03B3CA6FEB8AF162ULL, 0x9DCAB5329EB211CCULL, 
            0xEB4F5EBD1C7CEEDFULL, 0xAA8FD9DE2B2C32EDULL, 0x66725F0E92CA4A37ULL, 0x48A76EA5A5C1FC54ULL
        },
        {
            0x398FF347AF345D76ULL, 0xCB49EF8E7472FBB0ULL, 0x8E2468B102BD774FULL, 0xCF3545AD54B1725AULL, 
            0x0AA30AEB4F80B1D3ULL, 0x5A7C7C4B1AB56402ULL, 0x85DAB3509E4B61F5ULL, 0xCF9F86FC6EA8C327ULL, 
            0x448AD69DFF3450CAULL, 0xAABC4C63456D48FEULL, 0x04CE40C15AA8C98FULL, 0xC92DF22D1DA36FCCULL, 
            0xB5607E646D039108ULL, 0x106D922D03EA1592ULL, 0xB8A773A7B276B527ULL, 0x8C53C1AB0C8558A5ULL, 
            0x7592B2BE7F9D4D5AULL, 0xDA06C5EE58FD9D82ULL, 0x6CE7557CF09F338FULL, 0x084ECA1B36BE9B9BULL, 
            0xFD80793BB089B56BULL, 0x71636EBAE0C6CB5CULL, 0x2FD109584C8C6E22ULL, 0x770308ABFD0D48D0ULL, 
            0xC83116657BCB64EEULL, 0xEDFD8D72248CF745ULL, 0xF37D31854AFB3DFEULL, 0xE4DF501376A04B13ULL, 
            0x6EE8D421938D7959ULL, 0xA836F75F2A833628ULL, 0x1D927342A713F657ULL, 0xFF652CB9C66D8728ULL
        },
        {
            0x307BFCB94A344875ULL, 0xD346760A0ED1DC23ULL, 0x2CC32DEA105ECBD8ULL, 0xFC5EF67C7EA18C16ULL, 
            0x8D4063F9EFBB2912ULL, 0xA65283F4C53D46B7ULL, 0x36EA3E1F5987A389ULL, 0x88AE961B4B81834FULL, 
            0x445386CECE5DFCA6ULL, 0x5A03989191FDBAD1ULL, 0x278587000AA53520ULL, 0xF8CA58AC1E6F4524ULL, 
            0x65879242E342A38FULL, 0x8F2E6F50C66C7B2FULL, 0x91EDE4AD3FEF1867ULL, 0x3FC444BFE12109A6ULL, 
            0xE3A8F13469243149ULL, 0x14AA148E795685AAULL, 0x44BCF0710CD100BCULL, 0x3DDE8923811811D6ULL, 
            0xACC52C04A4FFC739ULL, 0xD7109B9E5E20DEFAULL, 0x22D2BA81CDE8919CULL, 0xCCE0E0C3542DC600ULL, 
            0xC5EF5AB47B009DA4ULL, 0xB96AC3F9C4B6386DULL, 0x78E303BB269B146DULL, 0x4F71626DDDCDA0FDULL, 
            0x2B2134291D652A69ULL, 0xE9F8A90B69908742ULL, 0x99235A60617CFD66ULL, 0xFC5AE8B97D0C87D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseFConstants = {
    0x7C9911761BEC9D01ULL,
    0x554DD029B3DB12E3ULL,
    0x20E6D376BFAD4268ULL,
    0x7C9911761BEC9D01ULL,
    0x554DD029B3DB12E3ULL,
    0x20E6D376BFAD4268ULL,
    0xB683D873C6697E8EULL,
    0xF24FF04F57F52232ULL,
    0x92,
    0x3D,
    0x74,
    0x08,
    0xBA,
    0x78,
    0x91,
    0xF3
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseGSalts = {
    {
        {
            0xC950EF810FEA8C0CULL, 0xB0D47A245727338AULL, 0xE194153CE7AB78D4ULL, 0x7843FF8F528E2B95ULL, 
            0x1A2A6BB140FDF3C2ULL, 0xF9085F670BA25732ULL, 0x9D385A77DC53364EULL, 0xCB935F00A341E93BULL, 
            0x1D6F2B075DE7FA37ULL, 0x65AF57A8550E41F7ULL, 0x91CAD4BDF608EE1BULL, 0x2F8E54CA3C85D87DULL, 
            0x1EF4455112F05CD5ULL, 0xE28A278E3362960BULL, 0xE20568A6652655F4ULL, 0xCA9EB86359242F46ULL, 
            0xCD33B91E7FC164C7ULL, 0x0E575C54979ED08BULL, 0x9F12AC5A3D4F2A32ULL, 0x6E51F0CEE01FA370ULL, 
            0x80843EB710C2BE7EULL, 0x3362872365B7CF35ULL, 0x78D537C16E63294BULL, 0xBCF5CC65EDBA14F3ULL, 
            0x55AFED68D4F2D6D2ULL, 0x2EE678BB821B17D2ULL, 0xE722E4D30B3EA45FULL, 0xC0582BF0363056BEULL, 
            0x9EFEBB9CE96AF32BULL, 0x9D62CA4F0D8B0CAAULL, 0x7728907EBEC6B0A0ULL, 0xDC04EC14C546C543ULL
        },
        {
            0x9A06B536392C433EULL, 0x4CA265559C7AB6ABULL, 0xED429278F4063AC1ULL, 0x23DF190BB1F889F1ULL, 
            0x853E7A2545A90212ULL, 0x60BB817F6D2E563CULL, 0x3807969B1B56F0AAULL, 0x42B11303B57A5346ULL, 
            0x45F84340F86C9AC2ULL, 0xB0F8E54F8795C142ULL, 0xFB392027ED27712EULL, 0xE6FC675262E40489ULL, 
            0x02EF57BD4A1FB89CULL, 0x810DDFDEB25F5D96ULL, 0x32E992B257D3F21AULL, 0x4CE6F5C762A286B1ULL, 
            0xCF8D9B53135F0D22ULL, 0xE1E82EF133E8D4E6ULL, 0xA6C490E00286F015ULL, 0xD642FCD19FA349A0ULL, 
            0x562363CF21E2FDDFULL, 0xC00742875AEF0753ULL, 0x09A4FB58C4875326ULL, 0x5ED5B289A4B81DC6ULL, 
            0x13D6A18929F8B152ULL, 0xC8959967B5E8A646ULL, 0x5E809B4C76247D80ULL, 0xDE6E3FBC0A02D9C0ULL, 
            0x1C6E7108A702E1CFULL, 0xC0A21362CFBD1307ULL, 0x0BC22FF5632666E5ULL, 0x96353B8758E16647ULL
        },
        {
            0xD517AAE97191C106ULL, 0x85B8FB9F8A69CB77ULL, 0x6E9D0F7493C1E5C7ULL, 0xFF3887635811CAF9ULL, 
            0x0D27182A72B9272DULL, 0x5805833F63DBEFA5ULL, 0xD0F5DFE04152D5AFULL, 0xE67A335DA3802D0FULL, 
            0x6188F63DCD1979D2ULL, 0x1A78B194E8D8E565ULL, 0x900535BEA74473F2ULL, 0x0ADA730B9CEC16D2ULL, 
            0x13664EC77BDC125EULL, 0xB396159F3104E928ULL, 0x070DF7F0B4814DC4ULL, 0x274EE8F204FED185ULL, 
            0xFB90F894612667DFULL, 0xA6179D42BCED0BCCULL, 0x8E58E154E4450250ULL, 0xE33DA641606D037BULL, 
            0x3C3413DD070942C2ULL, 0x852E2A6907AA09D2ULL, 0x4CEAEF3FE9D25249ULL, 0xC52A4337DD85CC3DULL, 
            0xCA01D7BBF1F2FCECULL, 0x2AF95FBB24E08C95ULL, 0x07DB90BDEE95CCC9ULL, 0xE77CAA73CF171DD4ULL, 
            0x57312E6F76DAAA43ULL, 0x81D39AA7BF9CEF75ULL, 0xC6D31035658B9FE1ULL, 0x5D0E8E9B6CE287B4ULL
        },
        {
            0x6DB22ABEFBCA048AULL, 0x83976D736E15617EULL, 0x8571BCE196CC378BULL, 0x462CD1012F6DE4DDULL, 
            0x5624FC44B4AEE5FEULL, 0x5B00901A0376E2BFULL, 0x0353A7C6B25306ABULL, 0x4A48832CE642D3F1ULL, 
            0x485E3677FC4119CCULL, 0xECA519C1D8EF2A35ULL, 0xA4161329580CDBDFULL, 0xE06E4D66B9426BC5ULL, 
            0xF6EC1E681C4DEB35ULL, 0x4BA269EE8EE3AE14ULL, 0x1D5A4833E56B1AA9ULL, 0x5F22A0E724D4F475ULL, 
            0x8FA94315E03CA3F1ULL, 0x8C8FB574E56116ADULL, 0x2D68700B5E6FE34BULL, 0x5249998E29DBE57FULL, 
            0x19EEE9401E28F543ULL, 0x0C0E8CF5A1B96F28ULL, 0xD7A0ADEA9E5CB015ULL, 0x5F8A8B3C629D0CD1ULL, 
            0x3B0DD26D4769AD25ULL, 0x6B786AAA2B4B5525ULL, 0x9D1F57FC2CE51DE6ULL, 0x5E8ED232F0B2C291ULL, 
            0xB4EA8DBA4CEFDE23ULL, 0xDA2EDEC60194F784ULL, 0xD5111700FA3D53F9ULL, 0x6552208359585804ULL
        },
        {
            0xE1C249A8E0447452ULL, 0x378989D44780A2F7ULL, 0xFD01E886AF361B20ULL, 0x20DC772779F13569ULL, 
            0x4C697E4BBB8713D0ULL, 0xF02709F70752CE30ULL, 0xDD21323526868782ULL, 0x4FF9C0FA423792A1ULL, 
            0x799D4C4B34198E3EULL, 0x74AD4CAF1B2A4888ULL, 0xC10F185288B6CA90ULL, 0x390D3D4F8EA7188AULL, 
            0xD95E09A15532A372ULL, 0x5DCEE5F34331ED6CULL, 0x8911DF5DD6931594ULL, 0x3B4C55A0561190CEULL, 
            0xAAA0CDBF1DF55608ULL, 0x74EDC118BE4342F0ULL, 0x115D95223418598EULL, 0x343246EB67D93661ULL, 
            0xC22356BD7B9401C4ULL, 0xB7E00E489308DF16ULL, 0xDC96D0E26CCE5CA5ULL, 0xDD6AD9A252D70381ULL, 
            0x562A4770D7C5BF4CULL, 0xF67D8C8A6A9461BDULL, 0xE70B450C51057ABAULL, 0x511420BD0500CA25ULL, 
            0xCF151E21DC10168DULL, 0x55ECCC7F5006E9A4ULL, 0x4BA759CF438E09DEULL, 0x994381425CE1C646ULL
        },
        {
            0xB56593F4D6E26407ULL, 0x3A532177CE27DFF0ULL, 0x4BA939205B33D931ULL, 0x75F81A8BA7B0D00BULL, 
            0xE3CA035096EF141CULL, 0x64C4D690ECB93DC9ULL, 0x240E68262BBBF0CFULL, 0x1C7E14F6068EE046ULL, 
            0xF4FF04BEFAFEE8D9ULL, 0xB87B8737742051CBULL, 0xE6F7E025433AA01CULL, 0xD67C160115ABCEF4ULL, 
            0xB877F969D577A753ULL, 0x391514969BDD1972ULL, 0xAE038B7408B519D2ULL, 0xDADB62D9480A0B2BULL, 
            0xF8C9383B0AF8E613ULL, 0x2E6BB98E5BE95C6AULL, 0xC80E164A83154096ULL, 0x4FA492683606CEB9ULL, 
            0xEF74C49FD72FE7B9ULL, 0x0E330DC0430F46F5ULL, 0x7D41B7EFCA1CBBF3ULL, 0x783BB815C95A5AB6ULL, 
            0x22B18D6E729E0E25ULL, 0x329A3F6ADD75DE4FULL, 0x03FD255CC7FB75F5ULL, 0xA6CAE95D0085AC0BULL, 
            0xF4C2BCC0232DFC9FULL, 0xD3220DA0EE746FBAULL, 0xDD15612012049016ULL, 0x4114E0EF0D5AFEDCULL
        }
    },
    {
        {
            0x287AECDEF0119E85ULL, 0x28EDE05E13A85AAFULL, 0x9BF981DF5450D1DBULL, 0x65A32B228C41AEDEULL, 
            0xD4CC82EA03606B8AULL, 0x3E7A66050A70FF3DULL, 0x09F3A3DDFA29313EULL, 0xA9CE2D103626896BULL, 
            0xA8AD51226A58AD89ULL, 0xF795FA4F822DDEF4ULL, 0xD42A71A9D57D56B0ULL, 0xBA1A8708AD3BBD33ULL, 
            0xE405572BF16FC846ULL, 0xE17FD61741870080ULL, 0xDF19BDF59308BAC5ULL, 0x00D41C4B208A9C42ULL, 
            0x1C1AD6BF7489553CULL, 0xF7627EB585665700ULL, 0x9CD65DB72DDAA2B2ULL, 0xFE05D8C858BD8D90ULL, 
            0x838684294370E893ULL, 0xD8BFF7D6D3482477ULL, 0xA18E87E98BA7F1B6ULL, 0x2AA97B73B6BABFC8ULL, 
            0x6B00E944F239D4A2ULL, 0xC98ABD10D8BCB9CCULL, 0x5FFB0AE81E147480ULL, 0x32A3C4979D9CAC3BULL, 
            0x64914B22E8D0295DULL, 0x99AE17D94D172783ULL, 0x3EB444FDF991B988ULL, 0xA139F57E271D4809ULL
        },
        {
            0xFA0572693B00B54BULL, 0x7FAC220C57DAC861ULL, 0xAB97C03755606412ULL, 0xEEA5F815A82CB38DULL, 
            0x5818BC5B939E1698ULL, 0x7CA24F30D0B5CF9CULL, 0xEF2147BFF2E2B80FULL, 0x73BD2DB8C35FA82EULL, 
            0x27A736EA3193A0E5ULL, 0x758A20916134B809ULL, 0xE4DB35095092DFCDULL, 0x154AF760A6B5CBFFULL, 
            0x528CE78B109283D0ULL, 0x27019F73E09FA786ULL, 0x4A73383AB73F9A01ULL, 0x21118B46F3A6711AULL, 
            0xD0E4A26DA20B2AADULL, 0x5354F9FF443B9298ULL, 0xDCC1FAFBA3C6A23CULL, 0x67077AE514212DBCULL, 
            0x39F70BC2390E4906ULL, 0xA459A604BC47F7D3ULL, 0xD2C3010415343E06ULL, 0x837D37AEFF0641E9ULL, 
            0x4460A75DC656E440ULL, 0x006A049420C0711BULL, 0xFE60182C70D518FCULL, 0xC84A6E16A6061A86ULL, 
            0x22198750E8F7ACABULL, 0x19C0782E6B797E44ULL, 0xD3B1E4DA35317A66ULL, 0x147A070601D5354DULL
        },
        {
            0x1CAA5F20EE4B0BF2ULL, 0x68AB0688481D92B9ULL, 0x2F9BDCBE47FA349BULL, 0x5A46080B5CF4C6E7ULL, 
            0xFC4921C09358DCB9ULL, 0xB4665F17F3416729ULL, 0x55BE0EABB7248E21ULL, 0xBD4ECEA987C95708ULL, 
            0xB19307935E1C8A0CULL, 0xC9AF1CC57B840A8CULL, 0x4B29E6789F418C58ULL, 0x33551638B5A9C2B8ULL, 
            0x715175775CFDDDACULL, 0x198A6ABC8D637226ULL, 0xBD83B65FA75DF562ULL, 0x6F8C9802324A8D0AULL, 
            0xFC9BBCDD45EAC6B8ULL, 0x63ACB37C36221FF0ULL, 0xB662E1DEE6EBAAD1ULL, 0xFFE7AF5E73ED20C6ULL, 
            0x3424799D35DCFFFEULL, 0xD40DA6FAFA869827ULL, 0xDCF3C528CA037604ULL, 0x878E8DE544C175C4ULL, 
            0x5DBA3CF7D0A00B82ULL, 0xCC9AD2F9A9111AA3ULL, 0x9470A40160EA7EA8ULL, 0x59B06DAE97E37FD3ULL, 
            0xC925D41EFAB8BBF3ULL, 0xA367B419A7BA6A01ULL, 0x8D7AB4D7C307C252ULL, 0x73D7EBC389CFC09BULL
        },
        {
            0xBC476C662CF763A3ULL, 0x660000BDB43844A5ULL, 0x0FB8B3FC5DA0DC3DULL, 0x6A03321875DD57E6ULL, 
            0xF7AE9DE3546B000BULL, 0x76B1718461F54616ULL, 0x0DCE1BE0F68D727CULL, 0x1265EFC952DDAD2DULL, 
            0xAA774087F4F5AAFCULL, 0x24A516B4DB2AB857ULL, 0xC20BA251F222C220ULL, 0xA178B078AC9463A6ULL, 
            0x33523682CF830623ULL, 0xD609AD3314187BD4ULL, 0x60391DCC685DA940ULL, 0x465F765C242C1EDFULL, 
            0x64FA3F642F56E528ULL, 0x1FDBC012FC859340ULL, 0xDE6A02FB9A128508ULL, 0x54F72FC840D062FEULL, 
            0x965D8D969EFA5F63ULL, 0x25EC8A4F93769CCAULL, 0x2211B2F996AE79B4ULL, 0x31D4C349A4B0BDA2ULL, 
            0xF098CAC11B0FBB4CULL, 0xC719329965E78649ULL, 0x66BC5BFB00DDFF15ULL, 0x09FA30C124074017ULL, 
            0xEABF6E74D21F35E1ULL, 0x80027A5796CA347AULL, 0x35AEDC522D23B844ULL, 0x9AA02107D130D556ULL
        },
        {
            0xCDEE825BB2C9566DULL, 0x33B36E6E36FA4503ULL, 0x340D1CA387CA0AF2ULL, 0xD27BBEAFA11AA532ULL, 
            0x1E1F08FA11DAEEDFULL, 0xCAC7B6CE9E1087F6ULL, 0x6D03F56CBEAFF697ULL, 0x6A9D8900BBC88C98ULL, 
            0xFB39038ED8067166ULL, 0xA8719F92045FC8A7ULL, 0x3D37242D0F9B49EFULL, 0xFFD608404DDDE401ULL, 
            0x31D27B8697AA1B52ULL, 0xCC95341CAF5FC263ULL, 0x45BE95564F47A9E1ULL, 0xFC3361D7C2A3BC4BULL, 
            0xFDD71D60991F6223ULL, 0xF63814B4646B0AF9ULL, 0x3B5E683710673051ULL, 0xAE9C07FDD35FFA21ULL, 
            0x4967FE3E41A624E0ULL, 0xF7B6C2685A8E4043ULL, 0x7627E917B34B5CA4ULL, 0xEC37F0BA51C97E0DULL, 
            0x29660DDC91B2CEE3ULL, 0x52A9E5F921BE7ED2ULL, 0x39F65183BB3E02C3ULL, 0x53F8E88D645029C3ULL, 
            0xE1735BB77A7741F7ULL, 0xC20E08D7F311B50EULL, 0x23E5F137105ABBE1ULL, 0xCC9CC79859AF480CULL
        },
        {
            0xA72E223C57C4361CULL, 0xF909CAB17D1B9EFFULL, 0xEA66B26819DE0F66ULL, 0x159D27D2B8F394A7ULL, 
            0xE1848F37497CE6F9ULL, 0x6207AC00F3F2917AULL, 0xE26036B71D2694DDULL, 0x1E632BEEEDB83A9DULL, 
            0x4687C3F1F3E64AFCULL, 0xB536CD147473B8E7ULL, 0x0B8E12FFB516C0C1ULL, 0x75CAE1481947EFCFULL, 
            0x86E3603FE702FBEDULL, 0x226DE633CC653AABULL, 0xEAA4CB1B556121ECULL, 0x2669296EA6259DEBULL, 
            0x5021E0F96FEC2CB7ULL, 0x2EB51E62B03129E1ULL, 0xDC2B2B758BDFB3F0ULL, 0x924BB5CBE2E095E3ULL, 
            0x64B1F5F68D5C1004ULL, 0xB17DBD5B7C83FBBEULL, 0x7F44BA1008358326ULL, 0xECC0F2694A39C8B1ULL, 
            0xC1EAC7BF3E2C86D5ULL, 0x97FA86D11E7633D0ULL, 0xA237C6C08AA5AB5BULL, 0x57DB51E05A281C53ULL, 
            0x82EAA57F2BFC7B5EULL, 0x33DBD074630136FBULL, 0xA6B7B6C1B064AFF2ULL, 0xF16C4DB9EFA6A06FULL
        }
    },
    {
        {
            0x29A3D7C97DBB6A4DULL, 0x95D5682FD0CFC736ULL, 0xC858185CD6B1062EULL, 0x838388F8CFE157EFULL, 
            0x7D9209738183FC82ULL, 0x353C9842BF2ECA38ULL, 0x70A9F1CED7198BC7ULL, 0x361AECF1854FA64DULL, 
            0x3D9AF84C8CEBDC7AULL, 0xEB54AEC0CD9C0EB5ULL, 0x5D03C0593D492A25ULL, 0x6AED11E7AE824962ULL, 
            0xB93C3FD37052E40FULL, 0x9A72D671ADBB7D1DULL, 0xE51B5C3567833B33ULL, 0x1F3BC04E67D9030EULL, 
            0x40B60C176DF7F494ULL, 0xBD35D4F89BA25D52ULL, 0x0958C5C38384F163ULL, 0x72C14C788669C878ULL, 
            0x29AE78AEA2F4EB0CULL, 0xDED15FD6FDE48078ULL, 0xEC707FC76657091AULL, 0x450105D3B899175CULL, 
            0x8FD8FE5093F3ABA6ULL, 0xCD9577A3308CE5BAULL, 0x2993E805226CC487ULL, 0xFE225C41E24A039CULL, 
            0x76FC99E78C0A6E3CULL, 0x7851E702E131A09BULL, 0x3B38B4E1DE9917D0ULL, 0x603638FE6844F212ULL
        },
        {
            0xCDBD230007BCCE7FULL, 0xB8D1D418DBC8BBA1ULL, 0x46812F3E3A48C36AULL, 0x6486535F86A27746ULL, 
            0xDEBA3E59D214472BULL, 0x7F9722BD1299134CULL, 0xE0CBD16C19B46959ULL, 0xEB13933CE7B4AEABULL, 
            0x9200568688032345ULL, 0x4F7AB5894DF46A57ULL, 0xDC2B190B8C4AD0EBULL, 0xD51930A670FDE3B7ULL, 
            0x9434D1F2EDC5E1FAULL, 0x6FF6FFAD5492EFCBULL, 0x233E9E56E862E57CULL, 0xD0BC2A38DFC77693ULL, 
            0xD142CE8DA246B639ULL, 0x03AB53D5ECA7FD94ULL, 0xEE3EA0F0F689B034ULL, 0x7BECF7C0678064CBULL, 
            0xCBE53224B184524EULL, 0x3F03B25E1178BB16ULL, 0x26C6F7C8C48B801CULL, 0x28AA45D79B838726ULL, 
            0xFCB1779635E9F25EULL, 0x6D9B72F46F3D0675ULL, 0x0B5BD77439989ACBULL, 0x3E58B6359AE2EA19ULL, 
            0x2AC11D16C1F3C2B1ULL, 0x93D9F285BC22DB2AULL, 0x43DADA592ECE00F0ULL, 0x161A51B43BA62DFBULL
        },
        {
            0xB87D666621279A4DULL, 0xB00ABB693006D2B1ULL, 0x2AE3421E61B1B284ULL, 0x498BF94EE5BFE857ULL, 
            0xC8298654618D116CULL, 0xD639635A9A1C9471ULL, 0xE644F2F4A4BC946DULL, 0x56C298D2DD5A3717ULL, 
            0xCFE25171B5CA899DULL, 0x430FEF44A87E7DB3ULL, 0x40D0AFF629C9EC3DULL, 0xCD25CB141B0BB75CULL, 
            0x7C90C6DBBBED1CD0ULL, 0x2861C32A16B1FA8FULL, 0x6483F20BCC8A4CF8ULL, 0xCC320D827CD7ECBAULL, 
            0xA7512BF979A8CB09ULL, 0xE52DD8108BB12DC8ULL, 0x45FBCE1CD637D0FCULL, 0x4AB7FE2E559C68E9ULL, 
            0x56522BD8F35644FAULL, 0x40158BD180B45346ULL, 0x1323398AA3E82790ULL, 0xBBC2BD26F7B370E2ULL, 
            0x409B61D44DE4E683ULL, 0x84F3435CF2247C96ULL, 0x23079B154B7A5BE8ULL, 0x3CA1254625DF189FULL, 
            0xB6AB30C594EEAB91ULL, 0xC7AC8151C9209DA8ULL, 0x6DCCE72E6FF3FE9EULL, 0x93C55CEA3F5414BFULL
        },
        {
            0x29A2D1084C3B70C9ULL, 0xA2D97E226FB710FBULL, 0xD824F034069660D4ULL, 0x778F4434EB6A5CEBULL, 
            0xD7B75C31AE444FB4ULL, 0x92E4CD51E9664EF0ULL, 0x8BD253766457C96BULL, 0x6E3BE2CA8A417F97ULL, 
            0x7C364F0694EF041CULL, 0x4DEAADD3AE6B8231ULL, 0x2FCBC6F1FA4E4219ULL, 0x62FAF38594187740ULL, 
            0xCE067DEB08EAC3F3ULL, 0x77E54973AEAB988DULL, 0xA387DF44085E5BC9ULL, 0x768C542A4A6C6DF7ULL, 
            0x81BD0A057112BD41ULL, 0xDFF8143F0E6C2AF9ULL, 0x316F0C704802F3FBULL, 0x4746917CC59A75B4ULL, 
            0xB1154A0E5B91F21AULL, 0x9CE564E109BCAF68ULL, 0x62A4BCB8182AE308ULL, 0x48B2A199562D9AD0ULL, 
            0x66BF07CE2FBC366DULL, 0x1AA5264971E9CF95ULL, 0x54CF6076A94D930BULL, 0x3465980D1BA8D3AFULL, 
            0xF80838B63A13314CULL, 0x24C7D0C387D91A1EULL, 0xE69DF5B0B7DA3105ULL, 0x37E300C3AD272370ULL
        },
        {
            0x771BA44A1F5946E4ULL, 0x8770CFA85487810BULL, 0xC8E8560CDCF9F225ULL, 0x235D4F7B7BD8AE10ULL, 
            0x8165016758902F75ULL, 0x0FF950FDFD762DB0ULL, 0x22AC0E53BD38498DULL, 0xF7CFC8AA12E59244ULL, 
            0x641447A796EBD852ULL, 0x7D58F7CA479974E4ULL, 0x3D9F88893BA1116DULL, 0xAED1B5B5463724DCULL, 
            0x8539C5981A180533ULL, 0xDE9EABEC73940E08ULL, 0x488BC75056D52079ULL, 0x47C05885B1C6377EULL, 
            0x047A3D750A498BD5ULL, 0xE15D14F27C9DDF8BULL, 0x8CAAC46F0FD1B465ULL, 0x927C509BD3EDDF2DULL, 
            0x2023651C06BBC4AEULL, 0x108127803A1FD7DBULL, 0x6AF90E7B6934A3ABULL, 0xD63964DFF9FB638DULL, 
            0xB821098C5C05D64CULL, 0x102E3F7285BDC795ULL, 0xD4B2BBC6B49571E9ULL, 0xBE52BED0720DBCB6ULL, 
            0xA5849E5338256DCBULL, 0xE00BC23ACE7288B7ULL, 0xA7A8E3D40540C28CULL, 0x9E4655BE58B3418EULL
        },
        {
            0xE03AC8A9451DFF8DULL, 0x9DA7DBAAB5429695ULL, 0x3249730E8B59E52BULL, 0xA34587EF90B1ECC5ULL, 
            0x6F8FB9022A99E10AULL, 0x07F1ED0F4BFF202FULL, 0xC92FD8158C5A70E4ULL, 0xD0E3BA4ABD1A8C52ULL, 
            0xA33AB34F216101E8ULL, 0x4BEAB84F09442C06ULL, 0x3C533932D74D5B80ULL, 0xEC0F3B8847D4C678ULL, 
            0x83012211D6614B2FULL, 0x1A17085D4A288FE3ULL, 0x181945C059B2DA58ULL, 0xFB5F5D7037CA9F5AULL, 
            0x52AECFC7CF316D49ULL, 0xB6AEEC0894A6F40CULL, 0x21FB315D76EFBA0EULL, 0x946CCD2076BDD84CULL, 
            0xBF86EE36A256BC05ULL, 0xD03EC6692210E572ULL, 0xC1E500325DA7D3E1ULL, 0x930F0EC602544DC2ULL, 
            0x4136D6F81D02A1FEULL, 0x76D835A8BF930606ULL, 0x4BC597E104012555ULL, 0xF667CBC4081536BFULL, 
            0xA18B7989AF0183E2ULL, 0xCB34BD67AA1118D9ULL, 0xC814D48D05E108D3ULL, 0x240378E7CA060336ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseGConstants = {
    0x5EEF3ABA1CB48BD5ULL,
    0x6AF7F04FCF30ECAAULL,
    0x9EB574D7CCA412C4ULL,
    0x5EEF3ABA1CB48BD5ULL,
    0x6AF7F04FCF30ECAAULL,
    0x9EB574D7CCA412C4ULL,
    0x665C695C44D10E39ULL,
    0x285CAA6DEEC10EA4ULL,
    0x17,
    0xBF,
    0x6A,
    0x64,
    0x8F,
    0x07,
    0xD3,
    0x45
};

const TwistDomainSaltSet TwistExpander_Hockey::kPhaseHSalts = {
    {
        {
            0x55340948EDE2A517ULL, 0xE5523795D8F19244ULL, 0x945A0D4718D9FAEDULL, 0x69B6132BE7D2996FULL, 
            0xBAEC442BFC25EE5DULL, 0x04BD7EADEA89E11AULL, 0x88820B70B6BF8C23ULL, 0xA12D7D321C3AB9EAULL, 
            0x09226587BC4B5B19ULL, 0x5CAF6A13EC620DA7ULL, 0x5F96679EE37CE17AULL, 0x5FD93E6E7799A0A3ULL, 
            0x091E18FF73A3BDBDULL, 0xA5814FFD91A26C67ULL, 0x496FE73F50315993ULL, 0x23869CBBE75BB6F4ULL, 
            0x6D0578F7D37FB543ULL, 0xD8E3F0A811D68DEAULL, 0x611A5AB60FA15510ULL, 0xA0709D5B4EC1E239ULL, 
            0x62A842CCF76B4DB3ULL, 0x7C70CA5D10E86DC1ULL, 0x9CD54609081BBF33ULL, 0xF617E647454F5483ULL, 
            0x64E5F07BCCF9222DULL, 0xA5CF0897FDFA49FBULL, 0x12B49D8189CC6837ULL, 0x53F63CFF1069FED4ULL, 
            0x7D58CE8B69B97D7AULL, 0xB660A2367AAB58D1ULL, 0x815393E2349136F1ULL, 0x33ACA9F5779D4CDFULL
        },
        {
            0xD835CEC13399CA34ULL, 0x7A0F1E4854089D33ULL, 0x5365B952766D11BDULL, 0xF1F3B8AD4ED5C9ECULL, 
            0x41E470A058E2376FULL, 0xCD6EC60488D28F62ULL, 0xD03A6EF1F8B1D080ULL, 0xA12690D21911B1E4ULL, 
            0xFB86D811DE719E85ULL, 0xC63451B696682DE8ULL, 0x7B9730893340D1BDULL, 0x60A1E684F014BF30ULL, 
            0x5DE77E16A16280CBULL, 0xC427B565EDCEA0BAULL, 0xF3F974ED5392F53FULL, 0xD6712D6C8CA79DE5ULL, 
            0x2851AB2A1CCC2BCFULL, 0x11F3CAC2E7D01135ULL, 0x452FCD84E3C166C7ULL, 0x22E755243F49DF51ULL, 
            0xD5E163C1896AB1D2ULL, 0x9B1BB857B4DB8BADULL, 0xA3662592CB3E5925ULL, 0xCF721C4CD2426FEBULL, 
            0x2DF876BA6D3F755CULL, 0x48F91068EB4DE24BULL, 0xA45B158AC10313D8ULL, 0xA262C44E304D88EBULL, 
            0xB6BDF3F5DDB6F01DULL, 0x108D405F9D60DB4FULL, 0x7E7E00094CD868A5ULL, 0xC36D50B461F68426ULL
        },
        {
            0x3F02165BE9CF6E75ULL, 0x5926E10DF4C267D9ULL, 0x4FA243772F757C0BULL, 0x0994337A10A16569ULL, 
            0xEF3D176FB32FE97DULL, 0xC377ED3BE23CB388ULL, 0x4F7AD82BDA05D2D1ULL, 0xF5A28F501D38B8FAULL, 
            0x9322BAD6BCE0A4E4ULL, 0x6F6F4529CB754AEFULL, 0x008DD8989C9D8AEAULL, 0xBFDD1B2AEBAFE9CFULL, 
            0x8CFE1D13761B68ACULL, 0x4DDBAF3FED3075E6ULL, 0x978FDD676A110010ULL, 0xB8055DD517C56D53ULL, 
            0x9A408999689BE4BDULL, 0xEEC890F6148F6178ULL, 0xB8E88B6AC876C929ULL, 0x164826E104EA90C7ULL, 
            0xE42E278AF8F59C3EULL, 0xB8B8BF7F135009C0ULL, 0x5384BA273842D324ULL, 0xEBE1A3684879F2AEULL, 
            0x3C2D5351EA832377ULL, 0xB978AA4675B26BCAULL, 0xB43023EF47D72BDEULL, 0x20221DB44236F42CULL, 
            0x50C47C577A14345FULL, 0xFD253496C43A8AB4ULL, 0x28E1507410A56F6AULL, 0xFA8C66E9511186C3ULL
        },
        {
            0xD443E7C96E2E729AULL, 0x8F1CCD792B209609ULL, 0xB5A6468F0F60DF30ULL, 0x3FAA1C57608866CEULL, 
            0xA4914EA02B19E454ULL, 0x586F8433FA6E26D8ULL, 0x614741AE0BDB3E40ULL, 0x3E544C1703BCA7DEULL, 
            0x4229DBB54C826A04ULL, 0xC8BBB6FCA2A2AFEDULL, 0xB4EA62F375E3F367ULL, 0x466C85236A285FF9ULL, 
            0xBE8B799758C98CA8ULL, 0x5B732DAFEDE6A5CEULL, 0x09940ECA58AEC6C9ULL, 0x6DDB1BBCE4AC4D0BULL, 
            0xC341E1CE2F593014ULL, 0xC11772AB3700C252ULL, 0xBDC5EE6BF114DF4FULL, 0x7E9DF209BEE8454FULL, 
            0xFAB51DE1E91A0852ULL, 0x56AC45BA2AE31429ULL, 0xB3EF2C8EB77C63B2ULL, 0xEF855756DCF27675ULL, 
            0x702103F989458A11ULL, 0xDDBC5E9DA449A543ULL, 0x125A61EA8F3886C3ULL, 0x4361C719B180CD4FULL, 
            0x08277E00412F648DULL, 0xA97FB1F2A1CD3E81ULL, 0xC249589B928029D0ULL, 0xEBA4749E932CBFB1ULL
        },
        {
            0x03045552323B77AFULL, 0x68251B098E8FA26DULL, 0xB6E194381E8B1163ULL, 0x6A6453C794508CE6ULL, 
            0xF96F7AD35A403FA3ULL, 0xE0731D70A1172552ULL, 0x0F58560788EE5158ULL, 0xE7742F26E4757335ULL, 
            0x6BC8E4AB2BFA6B93ULL, 0xB3CCBC39BA9B2BF1ULL, 0x8ECC12063BE21679ULL, 0xA8FF19E0C921BD20ULL, 
            0x8781DEF99145E787ULL, 0x8BA448D63B241CE7ULL, 0x10A669D282AF8916ULL, 0xA8BE58008B89D409ULL, 
            0x017D12DE65E01EDEULL, 0xE1796FAD426B4E92ULL, 0x9A53C47DAB9FFC27ULL, 0x6223A969E9F3998DULL, 
            0xD65F977B4EEC55F1ULL, 0xC38495F4DD400515ULL, 0x3361BD75CEDB2423ULL, 0x53C4C1AD5F5F6E55ULL, 
            0xF0DD793314E07EE0ULL, 0x5A67DE8B8C7B3D79ULL, 0xD5D6492981F8151DULL, 0xF8116F35AF8E24B4ULL, 
            0x57807701102DADBCULL, 0xB7F6E4F128DB1E0FULL, 0x5005DDCD72FAB3D3ULL, 0x970B9678DF5CA9A2ULL
        },
        {
            0xBD5082AFF6B8DE1AULL, 0x8CC8E71EF659D623ULL, 0xAC51F5D5471B6DDEULL, 0x7B33FCA48188BB27ULL, 
            0x07F8CC1FD4422BD1ULL, 0xE716324B1BDC936BULL, 0x91DCEE27E71A5A72ULL, 0x3C8B6D71ECBFD76AULL, 
            0x87B4E50D2DF1013BULL, 0x4E8E19A2FD8DC1A0ULL, 0x824011F3761D9B7FULL, 0xCF8A64A90DEEC5BBULL, 
            0x8C905133370FCE95ULL, 0x3FC2B8256E17D8C6ULL, 0x03D454DB45FC9F20ULL, 0xA38B93E00EEEB04CULL, 
            0x6DC69018D70A2F72ULL, 0x4D862A521419903AULL, 0xF730C874D1DEF4B5ULL, 0x992BB0DC0900BF19ULL, 
            0x25E8F1476E8D8AC7ULL, 0xE638AD417D422F03ULL, 0x8854BFD58FA5DA41ULL, 0x66457F0743B5B038ULL, 
            0x426FB06E100FBF46ULL, 0x4E45720B23A2904BULL, 0xC8F128F3F2737C78ULL, 0xF371554D5C7B1DCBULL, 
            0x0E8CA29A6E7E5554ULL, 0xCC3D8DB30763C57EULL, 0xCF67D9A1D6EE79A1ULL, 0x4BEC2626C76CC9DCULL
        }
    },
    {
        {
            0x2CC9DCFF5B371245ULL, 0x9A4FC0B5275D0449ULL, 0x770BDC1BCBE051B3ULL, 0xF33B59C70707CA93ULL, 
            0xEFC631E3DCBC64CBULL, 0x5E37425A39513D98ULL, 0x55CB347EC39B6B5FULL, 0x59AB61AA7B9FCB62ULL, 
            0xE7D29407F87BAB45ULL, 0xB321FEF792709013ULL, 0xE9A54A36CA5B51B7ULL, 0x79A6D5891EE45AA5ULL, 
            0xB783599185B1A420ULL, 0x19FCF46477E12135ULL, 0x91D0197DF46A11D7ULL, 0x37BDA17E3CBE5622ULL, 
            0x548B68B70E341E1DULL, 0x265C29F419F6E001ULL, 0xD21DF3F0F74483ABULL, 0xB54F2567E2690887ULL, 
            0x06523B1B4E171DC5ULL, 0x4457EC86B86D03AEULL, 0x13F8BB656F43FBFDULL, 0x8713F94A41DF6A53ULL, 
            0x929014C77CC941AFULL, 0x0F19EF0FBE86ABD0ULL, 0x9B1F29102594678FULL, 0x64977FDD4B544615ULL, 
            0x665B75E542ACCEBEULL, 0x9F9B0A7E19FD46F1ULL, 0x80BE45077E7B1B41ULL, 0x90A96A3693F8A2B0ULL
        },
        {
            0xC37C95B8AE07F79AULL, 0xDD1EA9F5AD7AF12AULL, 0xB0D1229AD0A9CA78ULL, 0x2C21ADE6C1A4F6F8ULL, 
            0x7A1A19511ECDC24DULL, 0xDEC68AA28104049BULL, 0x88DEE730454EC343ULL, 0x68F2B7CD9B078A43ULL, 
            0xB8ADE0D9784243CDULL, 0xAA6FD3BBDFA2DA2FULL, 0xCAEA91A130C602EAULL, 0xC934149D6FC642C1ULL, 
            0x0104BBB402666B9FULL, 0xDCF75E8AC7C1390AULL, 0x92D6433C138DCA59ULL, 0x8F440D151EE64231ULL, 
            0x6FFBD9B4CDE39B92ULL, 0xDF270E295FD1EF76ULL, 0x6F58B7287F8851FEULL, 0xC622A0D7695B4F7CULL, 
            0xB4F6548C9952B169ULL, 0x5F38E8301E9BD688ULL, 0x6C719FB350340585ULL, 0xA4BDB73E03FA9715ULL, 
            0xD39994966C7508C8ULL, 0x736CF1439EC363E8ULL, 0xF93376E5E820E057ULL, 0x08AD61D654188DC4ULL, 
            0xD6F05C543EEB144EULL, 0x387DC9A76B140BB1ULL, 0xFCB56EAFD5E1E510ULL, 0x964DEBD460843A60ULL
        },
        {
            0x559B857CA0E3FE1FULL, 0xE9EFCE3DD2D4DA5EULL, 0xA98EFD2777194C29ULL, 0x006479E4CE60C6DBULL, 
            0x5425AD5AE0A068B2ULL, 0xD38598C6D49892E0ULL, 0xB554FC62656D8FD5ULL, 0x54C1C8D6EA2F75A7ULL, 
            0x8410240F30B2FFCEULL, 0x1156727130B84EB8ULL, 0x4F047BD7C1B2E8F9ULL, 0x10C886BAA24542DAULL, 
            0x5389DF3D8116649BULL, 0xE4F620FC07E7B2FAULL, 0x81ECBFC80FEC1798ULL, 0x292893B93CEF4F93ULL, 
            0xF6705E534EC5F756ULL, 0x588FE77BF27EE8A6ULL, 0x224D2408B52C0579ULL, 0xAEF5857224A30555ULL, 
            0x8F0153CDAF91AA6DULL, 0xE8F1CDE356EAA423ULL, 0x09FCC2BF29D2C056ULL, 0x578DB7721798373FULL, 
            0x229273FAF15AA824ULL, 0x278723175062F0D9ULL, 0x52E6F33802D5133CULL, 0xCAF54CFDB3EFE814ULL, 
            0xDD8816EE85CC3C68ULL, 0xAA1C7AE98C15E316ULL, 0xF8951612B85C4220ULL, 0xBD5007A36072E9D0ULL
        },
        {
            0xA9AEF865625CF973ULL, 0x522B6A11BC328E05ULL, 0x4C75A7CD61C18A57ULL, 0x0AC2AA20B0D9D7D1ULL, 
            0xB145DD1B620E3C4CULL, 0xB49CC7205CF2112EULL, 0x70A1CCA07A817E59ULL, 0x3724A61033982334ULL, 
            0xAA79B797B1B1F592ULL, 0x930FE50DCF647271ULL, 0x3384669B5E84ABCEULL, 0xB51147B0C56D9EC5ULL, 
            0x8163E1D60C078F63ULL, 0x8D389D4C0DA2EB55ULL, 0x4AD40547A94FD0D8ULL, 0x8FD3E60A4A852C4AULL, 
            0x90444AF116B0966DULL, 0x1C49A4ADFD6B587FULL, 0x33C93BA571E9FAFCULL, 0x8565B108F2F1B5C2ULL, 
            0x471F39DF4A0B56E2ULL, 0x92CB22924C1B21D5ULL, 0x49C5C5BD6CB495BFULL, 0x9EC163DABBAFD379ULL, 
            0xEB2B6F11C3C7B49FULL, 0x19BAD4896057577EULL, 0x6BBF609FCB44BD16ULL, 0x3B3B444BD4F01E72ULL, 
            0xAC9C756F7AF37C7CULL, 0x6A065D673B4DE11AULL, 0xAE5DAC59CCDFA858ULL, 0x8E4C4D3B106EF8C0ULL
        },
        {
            0xD13CE228C7061EF8ULL, 0xE227817D8D7A882FULL, 0x56ECDF7E437A4DCAULL, 0x3DEFB6EB7248EE2EULL, 
            0xD06F9943CA213F53ULL, 0xAEA9C67A8184B057ULL, 0x7F29B9750D434E7DULL, 0x5D418139E90A3183ULL, 
            0x903E0658AA194C1BULL, 0x4974DCB08F7B5E1AULL, 0x4681BF026858F3DFULL, 0x6792A88C62D79DF2ULL, 
            0x3F4FE939A9E733D9ULL, 0x723606029FD8A78CULL, 0x5197D3BAF77FF558ULL, 0x7EE78592C65412CAULL, 
            0x39B4FDFC74A79C76ULL, 0x7D826A30692C8D25ULL, 0xB4DC8E363AC64C70ULL, 0xCC676E429FE512FAULL, 
            0x982932D114C6BAFBULL, 0x90D9F887251614A0ULL, 0x1FE91C0ABB5959A2ULL, 0xCFE9D9D8493BCAD0ULL, 
            0x7B5B018B351A51C5ULL, 0x3BA126E1AA3A66F8ULL, 0x9F89F289F27656BBULL, 0x58AB0B59CF5FCDDAULL, 
            0x59C09AE7210ACD27ULL, 0x004241230B0DD3F4ULL, 0xC92A805CDF18D573ULL, 0x5F88F6601345D4F4ULL
        },
        {
            0x164BED4E6B83CFFAULL, 0x48AF1B29F694985AULL, 0x20686C5CD1FC8635ULL, 0xB0E4F7DADD8DDD9DULL, 
            0x34AF6C1FA1895E09ULL, 0x8CDD6A1AB7642657ULL, 0x8524B5B6FADAEDBCULL, 0xFE52A87B2749B776ULL, 
            0x39092C70D2CC6234ULL, 0xF69DC43877674C29ULL, 0x484B6F6D5E682F85ULL, 0x896A1C823C5AFF2CULL, 
            0x96DD6BB0D12892E6ULL, 0x9B43D8038A6CC0FEULL, 0x9BB7D10B7AA2472DULL, 0x5F43CB6A995BFD3AULL, 
            0xAC358214D19ABB66ULL, 0xCD719FE1905B59E2ULL, 0x0DDF0A532CB9E6A9ULL, 0xABB985FEA89C6E44ULL, 
            0x5BD823FD0DC6CBD2ULL, 0x7E7A9E4D4FA1E97EULL, 0x2593E184E5C1E788ULL, 0xAB06A8B9FC657087ULL, 
            0xEC2CB6067AB41797ULL, 0xFF1FA01AF9B3FD76ULL, 0x2151748FC94DE7FBULL, 0x4962225FA1798B7BULL, 
            0x5CFBDC7D62153CEEULL, 0xC7D661C3A58B4A5AULL, 0xB71B80CB0017D1BEULL, 0x4E692D3225F04CBDULL
        }
    },
    {
        {
            0x62B3A86815D9927EULL, 0x7C538FDDCFFAAAC1ULL, 0x5CBF6AFA29AC07B8ULL, 0xF2C39D96BE05252CULL, 
            0x441813CE9E5A26AFULL, 0xD725D0C351752857ULL, 0xDF208A24E9AC08B1ULL, 0x03C9FD07AC19C8CDULL, 
            0x9A96F2D7BC6B5701ULL, 0xD166D6F2B1E6AEABULL, 0x2605E00FB651CEDBULL, 0x30D2AB29CC45ADE1ULL, 
            0x5C993681D140A31BULL, 0x7EA44FCA6EA63E2EULL, 0x50D5A07A14FA75C4ULL, 0x3C8EDC7D7D2623E0ULL, 
            0xAF8C303D9B571521ULL, 0x7CBE4F7AA6B5C8F4ULL, 0xEC7AD970263E98F8ULL, 0x04C443CFD061EAE5ULL, 
            0xFB804A4B81A3CB83ULL, 0x42B8BCA698E488CBULL, 0xCF87F66D96C5152FULL, 0x412A987A420FFE2FULL, 
            0x4F36ACF47611222FULL, 0x86FB31DC74043BC4ULL, 0xA106ECC7C53E456AULL, 0xFD98ECC4346E2B35ULL, 
            0x1AEB16B4D9A8CD26ULL, 0x8E4B4BBD2C2419BAULL, 0x68B0D25E12DC2DA2ULL, 0x03C9C3F5A7AE3388ULL
        },
        {
            0xFF04B620963A81ACULL, 0xECBB8C9DB91B858FULL, 0x48AF1EB56CB7CDD0ULL, 0x26DEB5E9B0C97B1CULL, 
            0x4BDFD7C36ED16548ULL, 0x114C61094B7E79CAULL, 0x9C1AB0D1A3581C9DULL, 0x0EA21A22E43CB86AULL, 
            0xCE10682620052B52ULL, 0xBBB7A0EC7EE6013EULL, 0x0AD84A5DD89D9701ULL, 0x8D14C71A79AFB6FBULL, 
            0x5487DCA270865388ULL, 0x6B05CA8F10B9C838ULL, 0xC46A1FA18214F2E8ULL, 0xF5A401E1F7E9514DULL, 
            0x1F9CCA09BF86615EULL, 0x7CE1960B5D3ACCBBULL, 0x9918554189120B9DULL, 0x05EFE3366A557FAAULL, 
            0x3CCC9276FB365767ULL, 0x980B7A7A2663F139ULL, 0x20149156A517073FULL, 0x4D64A6824D2C97C2ULL, 
            0x47FF976192D402B7ULL, 0x5A5C8053D79E19AFULL, 0xFBCF45BAEE07EF51ULL, 0x68FEECD5C113BE3AULL, 
            0x571152EE124A1776ULL, 0x48BCBE3D78503E0FULL, 0x21C7392DA615ABCDULL, 0x154CDBA8E0D2E46CULL
        },
        {
            0x895D19C10288A319ULL, 0xCC74507BB8C68964ULL, 0x2E88684392A7C15AULL, 0xCA4D02A8C52876D4ULL, 
            0x95068CF1BA59B04AULL, 0x803AD53EDA858F36ULL, 0xD5609599262B49BAULL, 0xB36BED100C02D867ULL, 
            0xD8C6F80214AF1EEEULL, 0xAB0F3557F93282B8ULL, 0xBC1707E63ED574CFULL, 0xD7FD41658434851DULL, 
            0xC463D2572C421BECULL, 0x33B7D3A6FC8CE4B6ULL, 0x6013B239ECFD158AULL, 0xED4411CD20A37079ULL, 
            0xE70A5B5844F8A5A4ULL, 0xCA1ABA51C0BEDD24ULL, 0xCD9B2DBF75B9E7B4ULL, 0x9C54A245A8C6E0A5ULL, 
            0xA892528B10603E40ULL, 0x94F5E45B645A0A4DULL, 0x2C53E052F28612ABULL, 0xC5684908B5011359ULL, 
            0x03DF788D3753FCC0ULL, 0xB4481BC4C8F2D9B8ULL, 0xEF7D137D4F50B155ULL, 0xB766E42AAE31577EULL, 
            0xE88FE242DB256C68ULL, 0x7F8FDDE121212E6EULL, 0x60C322F7695B2940ULL, 0xC4008175E92645F2ULL
        },
        {
            0x6D296D1B8C60B503ULL, 0x356E47E119534BA3ULL, 0x110D4D8F23D59EB2ULL, 0x10DABE7F167CCEF9ULL, 
            0x0DC7D7C5DD37A8D1ULL, 0x9B8ACAD6F9FED9E0ULL, 0x7101A5651481398EULL, 0xD27C989BA578CF7CULL, 
            0x2AECC956307F6B4CULL, 0x3F4B993F6291F5ACULL, 0xEC77CBDEDBFC267BULL, 0xB3A917A4E9AB6DDBULL, 
            0x5FB451149ECCC39EULL, 0xDD9FFA9E7647AB64ULL, 0xEED1C410B6B1B4A8ULL, 0xA12E818134454264ULL, 
            0x4C1C38D993B34CFAULL, 0x76ECC9A3E246A8E9ULL, 0x2550431CA512C563ULL, 0xAE5E7D841F57A784ULL, 
            0x708AF426C37A9A26ULL, 0x7D9BB6B1788813CBULL, 0xC3139210B77588CEULL, 0xFC941914EB51E967ULL, 
            0x48C64CB1C5CFD9BAULL, 0x8F31CB9438B8CC1EULL, 0x8BF7C1B157EE7E08ULL, 0x3B03AF8282B05A8FULL, 
            0x16291D909A58F832ULL, 0x98D4454DF17ACA84ULL, 0x0D982799114831CEULL, 0xDA1397B7CC425C79ULL
        },
        {
            0x2DB6599060D24C27ULL, 0x1AEBEB9A5F46AC73ULL, 0xE0535C4311D463ABULL, 0x6D9155C77DB74EAEULL, 
            0x1904125DEEDCF133ULL, 0x670B471EA1DA23BEULL, 0xC64C52F8AC25A396ULL, 0x0077D5602FA5B198ULL, 
            0xF9828556EF86631EULL, 0x713EF0A2D7491E34ULL, 0x432A2B4E39A49244ULL, 0x86E7828ACF27EAE2ULL, 
            0xB4C5EFD1975745E6ULL, 0x9980369754681D81ULL, 0xF02AA3B9F5DC6759ULL, 0xBFCE2BCC469787E0ULL, 
            0x04A6C6C95CB70F05ULL, 0x4AE8FC4B0899B353ULL, 0x7729E2F062D775D9ULL, 0x1673A6A751DA796AULL, 
            0xCD0CE4E20C096BAAULL, 0xBE5CF01859F9CB60ULL, 0xE03BAA17768276C5ULL, 0x7BF9B9EC8579D7EFULL, 
            0x2CB34A5CA7800D08ULL, 0x0CCB5A88603AB1E0ULL, 0x9D4091A4A21A6F2EULL, 0x75921D2906D28E4BULL, 
            0xB1A476347C553B85ULL, 0x26C373E4ED26043FULL, 0xF287BDF90334C554ULL, 0xBD36926A861D08E8ULL
        },
        {
            0xD933DBD964AF0A7EULL, 0x7DB787F4B0719B83ULL, 0x88E5C14AF417CE97ULL, 0x2DBB3292E346ED9FULL, 
            0x3612C2DDC48C7368ULL, 0xC3E6F1ADCAB8DD9EULL, 0x73662268D95B802CULL, 0x0A4F1A619707F67AULL, 
            0x73BAE80B9C28100BULL, 0xA2E9B43D10FF135EULL, 0x98070040506AA5F0ULL, 0xEA364399444D96BDULL, 
            0xB6F68DFC1B244074ULL, 0xA5BA915B9583C06FULL, 0xDD90239CCDBE1BC1ULL, 0x42FBD15AF8ABF0BDULL, 
            0xB0AA11DDC3EF5E51ULL, 0x70A676F3EEA1E6C0ULL, 0x3DC4CC59E1D471FCULL, 0x8C199EB6C346A5C2ULL, 
            0x28DC63061BE966ACULL, 0x4E324926A4B526B8ULL, 0x1857AE375EC9A1FBULL, 0xD09A144F8B31045AULL, 
            0x23DC6D234EAC7019ULL, 0x4F3F76F658E10934ULL, 0x4AF57CCC18404625ULL, 0x78EE8C40E8C1CD30ULL, 
            0x30108438E1A1ADBEULL, 0x956495D53C86C24BULL, 0xEAC9650070FE5C34ULL, 0xE96507E08F9E3681ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Hockey::kPhaseHConstants = {
    0x96EC55EC25040978ULL,
    0x5A147BCC293CB635ULL,
    0x997A23C902DC2097ULL,
    0x96EC55EC25040978ULL,
    0x5A147BCC293CB635ULL,
    0x997A23C902DC2097ULL,
    0xFE7DC8162290ADA1ULL,
    0x1DAF35C56DE57D74ULL,
    0x10,
    0xD2,
    0x8C,
    0x1A,
    0xFD,
    0x4E,
    0xF8,
    0x3E
};

