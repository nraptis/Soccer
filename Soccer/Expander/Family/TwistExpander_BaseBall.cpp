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
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
        aPrevious = 15653122521340389149U;
        aCarry = 13822063274063069332U;
        aWandererA = 12188259660839906272U;
        aWandererB = 17252094293375691743U;
        aWandererC = 13017166553628992273U;
        aWandererD = 13699302383795699287U;
        aWandererE = 10673882320314081870U;
        aWandererF = 17872302245382370697U;
        aWandererG = 13107928706548889837U;
        aWandererH = 11537091229377987030U;
        aWandererI = 16740336687073296854U;
        aWandererJ = 9971737294418700263U;
        aWandererK = 15764427524520313814U;
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
                 pSnow,
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
        aPrevious = 11724981479112233542U;
        aCarry = 12080023945825520143U;
        aWandererA = 15928734846979479540U;
        aWandererB = 15974857246771192618U;
        aWandererC = 15907154870954453657U;
        aWandererD = 12398874983327727415U;
        aWandererE = 14195230394124522718U;
        aWandererF = 14904297714839748013U;
        aWandererG = 12191745319221515875U;
        aWandererH = 10491783399868929103U;
        aWandererI = 11198069780489146242U;
        aWandererJ = 15502049657813804539U;
        aWandererK = 17147630911601570846U;
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
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr)) { return; }
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
        TwistSnow::Sha256Counter(mSource, aSnowLaneA);
        TwistSnow::AES256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
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

        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
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
    {
        aPrevious = 12385831374457473895U;
        aCarry = 17916023572537316068U;
        aWandererA = 17790095516790619281U;
        aWandererB = 13314746582796797432U;
        aWandererC = 12708772828481982618U;
        aWandererD = 16809069112062733955U;
        aWandererE = 9503978635128693996U;
        aWandererF = 13347101746601060999U;
        aWandererG = 9332358205560116133U;
        aWandererH = 13766599549772026774U;
        aWandererI = 14287035513210430257U;
        aWandererJ = 13251381152292592339U;
        aWandererK = 17853142497441134415U;
    }
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
        TwistSquash::SquashC(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 2, 1 with offsets 6463U, 719U, 3223U, 7812U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6463U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 719U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3223U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7812U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 0, 3 with offsets 5776U, 5432U, 7654U, 5819U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5776U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5432U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7654U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5819U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 1, 2 with offsets 5369U, 4223U, 5836U, 2128U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5369U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4223U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5836U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2128U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 3, 3, 0 with offsets 3806U, 3723U, 3143U, 7925U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3806U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3723U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3143U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7925U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 3, 1, 2 with offsets 1673U, 1314U, 1297U, 14U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1673U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1314U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1297U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 14U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 3, 0, 2 with offsets 433U, 1409U, 749U, 38U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 433U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1409U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 749U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 38U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 0, 2, 3 with offsets 1250U, 1465U, 1181U, 145U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1181U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 145U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 1649U, 2002U, 1447U, 430U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1649U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2002U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1447U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 540U, 1473U, 296U, 1826U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 540U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1473U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 296U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1826U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 3 with offsets 8026U, 6837U, 5042U, 3858U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8026U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6837U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5042U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3858U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 1, 0 with offsets 3991U, 1467U, 74U, 3972U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3991U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1467U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 74U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3972U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 3, 2 with offsets 7744U, 2982U, 4599U, 5536U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7744U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2982U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4599U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5536U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 0, 2, 1 with offsets 5767U, 1373U, 3901U, 1586U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5767U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1373U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3901U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1586U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 7906U, 4427U, 2371U, 6572U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 7906U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4427U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 2371U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6572U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 2044U, 948U, 1981U, 172U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2044U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1981U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 172U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1446U, 847U, 768U, 97U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1446U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 847U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 97U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1167U, 1444U, 1939U, 1783U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1167U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1783U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 2005U, 816U, 1520U, 1790U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 816U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1520U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 467U, 400U, 449U, 462U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 467U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 400U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 449U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 462U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseASalts = {
    {
        {
            0x2D9CB7C0A325312DULL, 0x41D9A1610DEF2773ULL, 0x5A059FA9CFD1142DULL, 0x982E720E861E700CULL, 
            0x6A945A57B9972843ULL, 0xAA013403C4B073C2ULL, 0x3A58BC72060864DCULL, 0x56E60965B872E54EULL, 
            0xB7AD0A479DD590D7ULL, 0xFA44E6E6692226B7ULL, 0x6F4FE84A8F9878A7ULL, 0x47475AE521378CBAULL, 
            0x4B7885DA0D42115AULL, 0x58A1ACF4175FCE12ULL, 0x20B4DF33BFDAD719ULL, 0x684EA2D3E5A572C0ULL, 
            0xDDCC86D157168400ULL, 0x5C01C0EFE8011F2DULL, 0x392F021B54D9EF44ULL, 0x06663F65680E848AULL, 
            0xAB82F43F59B39AB0ULL, 0x1F65574117C9AE90ULL, 0x3F611BD2E0CBD18EULL, 0x3CEC8B5F80AD6682ULL, 
            0x18A774E36BD72888ULL, 0x19CE2232438C52C6ULL, 0xE4F238FF1806E446ULL, 0xE4AFA5FC76E05913ULL, 
            0xA6C2B79930D174E4ULL, 0x14340B5A325B290CULL, 0x3A8CA75FEBA37FA4ULL, 0x34C892A74D6C2DCDULL
        },
        {
            0xF4FDD6A5A2128DEBULL, 0xE0480B98E1DA9652ULL, 0x046FF68FC9010A57ULL, 0xEB0B81E434F448F2ULL, 
            0x2F534F49987464E5ULL, 0x3D7FE6AF6282138BULL, 0xE87291FF3489E08CULL, 0x926671B421F6458BULL, 
            0x506E69B9EFDBAB90ULL, 0x1B3FBF6FB7123176ULL, 0x4EE234C95A9A44FDULL, 0xC523932156299305ULL, 
            0xE440487B4DF45162ULL, 0x84BA86459D5A2BFDULL, 0x86F250FE65386588ULL, 0xD39E2BF563444404ULL, 
            0x54BB4C71246EA50AULL, 0xF88D4F7DD2C7876AULL, 0x24CBEE1714C443E3ULL, 0x091722E69F419647ULL, 
            0x91B9153338C4E14BULL, 0x2F8D435E20C02977ULL, 0xADB54D93336C478DULL, 0xEA30810D15260DB4ULL, 
            0x491CF50B23303207ULL, 0xAE9790FFBC39B20DULL, 0x67EE413204D15A41ULL, 0x1AD627EB7178B101ULL, 
            0xC391646C25FA9395ULL, 0x08921C150F810FC7ULL, 0xB07F20D9F7326B9FULL, 0xC546F5C03F49D629ULL
        },
        {
            0xF66B177F766B1579ULL, 0x2048E20EA3CCD4ADULL, 0x0C21131CA19DFE9EULL, 0x6C166C5B18CE5E2DULL, 
            0x44CF0B2808CD9CEEULL, 0xA8D5112BF20B70B5ULL, 0xC3B2FC4B4905400AULL, 0xEDEE7B4D9DCF447AULL, 
            0x3A00128D36108143ULL, 0x3152FBD5FC3B73B0ULL, 0x11BF6D231640FFBDULL, 0xBF8E6E1D111B5D5EULL, 
            0x541E9EB382757F2EULL, 0x5122F4CD12691B2FULL, 0x0ABAF50D6D5F1611ULL, 0xE1D0233F81DD98FCULL, 
            0x65E38C97C7BDF5DBULL, 0xD357BF2B653EEE74ULL, 0xEB4FC4826443F51FULL, 0x64B3963077415BB1ULL, 
            0xA342191FF3DD041AULL, 0x4A2AA28440ECEDDEULL, 0x8E24BB4450498309ULL, 0xFDE4DD534610BE75ULL, 
            0xC7BACDE223D9D161ULL, 0x0FA3527D291F3117ULL, 0x489C8966B006A28EULL, 0x8DE3690545BA7F76ULL, 
            0x3965D1F478647E02ULL, 0x5B875588F0D2DF2BULL, 0x08FCC4F5F41C3E02ULL, 0x50F325985993B00EULL
        },
        {
            0x7B54CEF79A1787AFULL, 0xAD05EA12F4AF8471ULL, 0xD5185B4186C8E96CULL, 0x16B8F29E59E28AD4ULL, 
            0x26F52F6F68D3B885ULL, 0xE2E561093D75EC93ULL, 0xFFDFC899F62C40ADULL, 0x68010B90D97B7B10ULL, 
            0xCA8BEBD0729CF3C3ULL, 0x317D6B8AB0A11A4DULL, 0x390688C42009C02EULL, 0x800C2A6D97C1AFD8ULL, 
            0xFDDE7FA15F1A0E9AULL, 0xB78BF869D42B5B85ULL, 0xCEC1A88E9B3960FFULL, 0xB222426147304157ULL, 
            0xD14FD850A7D680E7ULL, 0x52A10954A78E9E1CULL, 0x1A430866CE344A28ULL, 0x2F68842CA811515FULL, 
            0x71F41AD9BF12877FULL, 0x9E88D91FF6291E05ULL, 0x526DE9FC5DEEDF19ULL, 0x38CB6C021250E3DAULL, 
            0xF38A6C67AE0DDF4FULL, 0x2ABA68E15E4DB3ABULL, 0x051A795861ACEAB0ULL, 0xD5F11C450D3104DFULL, 
            0xA75CC2868B715D3FULL, 0xBDFAE17B0C766DB8ULL, 0xF8331178525F0763ULL, 0x5FD3321392D11678ULL
        },
        {
            0x52AA6401C5665EFCULL, 0xE3C71D33C2F3AE38ULL, 0xB15BEDA5259D2106ULL, 0xEBD00611CA44D874ULL, 
            0x3ADFD14E7603550BULL, 0x5C88DAEED4121C57ULL, 0xB7AA3CDE12798E49ULL, 0x3E63A215C3E95B7FULL, 
            0x7F5057EA74CDDEB9ULL, 0xEE3329809D7144FBULL, 0xB82A4E8D6ADDD477ULL, 0x3CC136A8042A82EAULL, 
            0x966303CE0E3573AAULL, 0xC87C63BDC1B63CEEULL, 0xC91004FA99FEB3C0ULL, 0x86A8E8B82DFBD6F4ULL, 
            0x7EBCAE5D54F0505CULL, 0x2A65D39F8F42313CULL, 0x1039143AFEE13B65ULL, 0xEB0025477DB67776ULL, 
            0x67DA7B87C0103C36ULL, 0xC84F8DF5A15F6D1CULL, 0xFFBB068B310DE135ULL, 0xDA1AD526447D9473ULL, 
            0x52120143F4320FBDULL, 0xCC0CF844D24397EBULL, 0x8853A0E7D38CBE58ULL, 0x60D9B67185BC6258ULL, 
            0xE6653ADDE82C934BULL, 0x14EC6E95EF8A9BF8ULL, 0x6E4492F406066334ULL, 0x2C672CC72E4F9AB9ULL
        },
        {
            0xD4D4E291265C56D2ULL, 0x31A3E0B7483E98EEULL, 0x72229A5C37FB4B07ULL, 0xB4FB4FAFE76C8726ULL, 
            0x033981681A97007FULL, 0x4ED05CF77C150048ULL, 0xAB8EB4433F73D3F5ULL, 0xC3FB99CCE101F5D2ULL, 
            0xDEAE165E9A246505ULL, 0x34BAC3BF84F84F88ULL, 0x203838F9BB4B1DF4ULL, 0x9A1ACE3F5D9B4986ULL, 
            0x9151503D9F9A3FC4ULL, 0xAF774C147A162BA2ULL, 0xD9F1518EA22A4786ULL, 0x4C9282008C748D35ULL, 
            0xC73DEDBB53C2E9F4ULL, 0x80456000310FC875ULL, 0x07C4D6ADB3903CA7ULL, 0xC4AA3BF93CE98DC7ULL, 
            0xB4085B0B7E6D77CEULL, 0xB739CEF40CB924DAULL, 0x5604CBEB29080C8EULL, 0x75A501CD40C18380ULL, 
            0x46F1BFD8252030DAULL, 0xDE11CEF20BE23902ULL, 0x3D61AFB548E0724BULL, 0x2CACEBC4164A1885ULL, 
            0x1DF178856C48D61BULL, 0xD0FD7B9EAC3E6C58ULL, 0x8480A5622F5A74F6ULL, 0x6019D6B96BEECAFDULL
        }
    },
    {
        {
            0x6B537385F341AC87ULL, 0xF19DA8D8058957E5ULL, 0x4AA1CEB08B7A8087ULL, 0xF63A7556A4C1C56FULL, 
            0xBB1CE8508F9AB143ULL, 0xB3594C6145FF378EULL, 0x555945C4AF2522B9ULL, 0xA181A4A49AA54AA9ULL, 
            0x6028DFECB172B1DAULL, 0x43A3832AC9F86C32ULL, 0x89BD0746976E3508ULL, 0xFE5D8F9C910C276EULL, 
            0x3B09CAADE095865AULL, 0xB860E90CA9D64780ULL, 0xE26A2753194419CDULL, 0x36D7686DB7D79176ULL, 
            0xF3B6240E8D9A9E6AULL, 0x2026409F83F2EF47ULL, 0xF836027BF980B8B0ULL, 0x60ED9A5EFE289C25ULL, 
            0xE0AC52D0B278BE9DULL, 0xCF956AE9EA669341ULL, 0x8017802EE66A2997ULL, 0x2CB2C7831C5D11A5ULL, 
            0xBB3B7D84F9A857ABULL, 0x652A66848EEB69B9ULL, 0xF96FD7564DEE4DF9ULL, 0xEA55DB81024A692EULL, 
            0xF36D612DE0C7F716ULL, 0xCB5B72876FBBC215ULL, 0xA1E6B3DD12258FB1ULL, 0x41A31ECE27C89E97ULL
        },
        {
            0x1364146428637F9BULL, 0x99E4C8781588C7C4ULL, 0xE86EE10C29D63A32ULL, 0xFC71E8905AA992E4ULL, 
            0x4003A9C71008A36CULL, 0x05D553AD786F8789ULL, 0x60304BA74FBD54B2ULL, 0x83A06BF2EBB77F84ULL, 
            0x8F9DEEF701371E05ULL, 0x79330C8B3DF62A7CULL, 0xFAFA78BFECC0B379ULL, 0x8AD34BBDE3383701ULL, 
            0xA3C2BBBEA520F9E9ULL, 0x6773BCBBAACDE447ULL, 0x1C00A28ABBFFF6C7ULL, 0xA4C3C1487D4BC2E1ULL, 
            0xEEA0ACE3784804ADULL, 0xE6C298BD79A9E7FFULL, 0x43198B537E48DBFCULL, 0x42EFFA1755544E63ULL, 
            0xCCEC70413690C6B5ULL, 0x6ECBDD7A4EF67122ULL, 0xE14D5AC59F23477DULL, 0xAAFC2CF06F2EC86BULL, 
            0xC33AFD2AB1413759ULL, 0x5C93724522C5D006ULL, 0x136A04DB5DF9B626ULL, 0x6A479B08ED469F6CULL, 
            0x2FBE66309BF101E0ULL, 0x5D3CD3CCEE78371AULL, 0x53A560867695494CULL, 0xFC034110F094826AULL
        },
        {
            0x2F397C153BB40A0BULL, 0x3AC80017A3A75669ULL, 0x770EBB0091FE3DF3ULL, 0xFDA85AE218EF4C64ULL, 
            0xAAD5C8D15DDA0DFEULL, 0xA8A1EE30EB391A4FULL, 0x50F5A184EC59655AULL, 0x7EA43453C1DDDAA5ULL, 
            0xBEC3D1FD270DE407ULL, 0x09C9B923EC7C1E35ULL, 0xE19FF7B31B9A9FC7ULL, 0x3D496B0FD5464C7BULL, 
            0x33F55F79999BBF1EULL, 0xB2A041FDB3DDFB31ULL, 0x842A3F3658342959ULL, 0x230FA759D87AD529ULL, 
            0xDADA527F31CFA10BULL, 0xF41861C25E3A8EB3ULL, 0xCCB50803A9CD5CD3ULL, 0xEF61B9AC8548B778ULL, 
            0x32A08F00F485B8E4ULL, 0x6B3C7148DB0F5F77ULL, 0xC05176B5FFE2CBA3ULL, 0x11916006DBDB60E5ULL, 
            0xD326B6EB0B474F04ULL, 0xD915C4C1BED217BBULL, 0xEF017A0935668C53ULL, 0xE3FCAE46599A93C0ULL, 
            0x8699E8867E7124B6ULL, 0xB099DCA0123FB603ULL, 0x9C12691A34B11DC2ULL, 0x4078DB90545CE3CCULL
        },
        {
            0x94126B7ED7E08AFFULL, 0x005164BEE95AEC9EULL, 0xF0747B9730B570CFULL, 0xAF24C3AB2D41AE50ULL, 
            0x324FD90840E3457DULL, 0x64A1A4BA86F78703ULL, 0x76DC1FEAAA96FB84ULL, 0x550F47844A9704B2ULL, 
            0x3F41685707CB51B2ULL, 0xE7DC0A3AA4214CCBULL, 0xDFDD032E376D6099ULL, 0xC08FF536ED0A3208ULL, 
            0x60A5A9D0A7A963EEULL, 0x05469C6A1C174E02ULL, 0xEBDF8E2B1397C069ULL, 0x0F732C6B069867CAULL, 
            0x1F41113B6D260FC2ULL, 0xBE54648D4FB05086ULL, 0x66C7C9B6BF9F8BF9ULL, 0x9B34284391D80654ULL, 
            0xFF45F4DCC77DD2DEULL, 0xA738A5BFC5EE572BULL, 0xCC56F7EE7C289CA1ULL, 0x49C4AF99A7D600B4ULL, 
            0x1A39E343AC357342ULL, 0x755629F61DD04713ULL, 0x970E8FCA8E33FA60ULL, 0x393876CBE9D2EDFCULL, 
            0x303079B276BBDE69ULL, 0x3CE354B6DCA30207ULL, 0x64B87F5BA116DD74ULL, 0xFE8284D3D84C06C7ULL
        },
        {
            0xBF529C3FFB10439BULL, 0x30C5ECE0E2095957ULL, 0x7254FAF22E1700E5ULL, 0xE65B94C8E66C9E12ULL, 
            0x2AE8BE166FA28458ULL, 0x675B655C61771ACAULL, 0x2A0A2B5A6BAA526FULL, 0xFC62080DDB9F260EULL, 
            0x790B6B2763CAE75BULL, 0x4ED4BDE644FD2A05ULL, 0x2F780347D19D884DULL, 0x6FC653B11921DC5AULL, 
            0xEFC5EB48A89E5841ULL, 0x1646F3DD04372104ULL, 0x14076266D07F18C9ULL, 0x0A819E2B2AEBE1D2ULL, 
            0xF734A01288D52712ULL, 0x4BCB5047BB0282CEULL, 0xA55378BE672041DAULL, 0x1FEC26F5F6741512ULL, 
            0x17833E00EA2C5CB6ULL, 0xE6A822B274300DD2ULL, 0x3BBFA092F9BF8570ULL, 0xD9E8580717366CE8ULL, 
            0x9F12CD3962AD8DB5ULL, 0xBE4931E1410A1435ULL, 0x8EFE28AD399DD888ULL, 0x44B24C0E885ED9AAULL, 
            0x9D58412C82F69D03ULL, 0x6589210BF165969BULL, 0xDDFEEE03B793C19AULL, 0x3FD6FCB578EB654DULL
        },
        {
            0x620E21C177EEEA25ULL, 0xF71BFDD992B196D2ULL, 0x5E689F70D98AB463ULL, 0xDAF4CD5A645BF071ULL, 
            0x75632FF294A720A2ULL, 0xD050AA870EF7C670ULL, 0xEE24D8E35C8881ABULL, 0x6C79FCD4DF515532ULL, 
            0x533C81FBAE439DEEULL, 0x0D67B8E9398F4A92ULL, 0xCDFFE7DAAD7D81FDULL, 0x939A1458B6F124AAULL, 
            0x5BD4CA667660D1B7ULL, 0x7C22A3CE3FFAF48DULL, 0xCFAE40BB7E7AD6E5ULL, 0xAFCAEE833352FEABULL, 
            0xE8BF6B5EB76AA32CULL, 0x5EF77BCCFCDD6DC4ULL, 0x5628359CCB2D44B0ULL, 0xC472576DBE3000BBULL, 
            0x2A586789F5A39934ULL, 0x50C917B2280BEE61ULL, 0x5433AFD0E6EF1A81ULL, 0x4EA29BF133FBF474ULL, 
            0xFC3973A5E33141B5ULL, 0xCF1017F8E3D8B8E1ULL, 0x29C5C36CF6130A8AULL, 0xE3ECCBEAAE84355CULL, 
            0x65A0B9D84BC21116ULL, 0xAE74A42C26E33980ULL, 0x6C6A1578C3773479ULL, 0x3931BF90D9C18BC4ULL
        }
    },
    {
        {
            0x8EB5684C3A320DA7ULL, 0x2906D1412E0CDD81ULL, 0x2F30936B9E83A61DULL, 0xC1933756E58B7765ULL, 
            0xBBAFED283F3BD5D2ULL, 0x8931B1DF1D05A39BULL, 0x8FE0C27E6495FD00ULL, 0x941202B18D538358ULL, 
            0xE2E3D5DFEBB84B39ULL, 0x483AEA62BA4224BFULL, 0x1BBC5EA6D51A0C27ULL, 0xC006A109F4AB7457ULL, 
            0xA115172625676CC8ULL, 0x8FAB7B683948D3D0ULL, 0xB5118A4C9BA20264ULL, 0xAE749BAA6E6516CAULL, 
            0x9E3D22645E88280BULL, 0x63A3EACBD1AF3760ULL, 0x47166F52CE965265ULL, 0x0DEB582849FEDD56ULL, 
            0x7CB08C3D90D5949DULL, 0x4A64545C0DC8F14DULL, 0x5011C6A59F875DC8ULL, 0x1ABF487B2E8958A1ULL, 
            0xFB40131EF2310105ULL, 0xAFC099C17823D78DULL, 0x5FF9BD497A02FD4EULL, 0x87FE59F8F546B615ULL, 
            0x5F1CB5865BCC76E2ULL, 0x5B17E2929F96BA0CULL, 0x6CD9893EADB8EBE8ULL, 0x16FEE40ADF96E3ADULL
        },
        {
            0x6470574A33FB8D52ULL, 0xEADC552CC9363A45ULL, 0x45E79C0B04B9C060ULL, 0xDE2EE69D9B158CDFULL, 
            0x6B7247C407C835EEULL, 0xE7C89E827563659FULL, 0x9CE6050641C23CE1ULL, 0xE4E3CD2C7C2C417CULL, 
            0xB76E995A0569A7E9ULL, 0xFBC4C11564563FB9ULL, 0xED5AC39E5B20FE94ULL, 0xCC2B13F19EBFEADAULL, 
            0x6640BEC8217A98B9ULL, 0xB411F8264D74FA9DULL, 0x47B20FC6AF701A13ULL, 0x107C030F18652703ULL, 
            0x787EAADF32EA8767ULL, 0x735DDB2428083E4BULL, 0x4B9C46B6B696D87CULL, 0x037943B9ACDAEFB4ULL, 
            0xBA1099877EAC30B0ULL, 0x2F4DDDD97A20BF4DULL, 0x445805DF174AF99AULL, 0xFA530CBA41F7403AULL, 
            0x050906C965F8BA95ULL, 0x2EA9F80F870CBE6EULL, 0xBA167DDFB360300AULL, 0x56BD36BB93424F3BULL, 
            0x9B4EAB622907FE5AULL, 0xF01FDEF8C5856A4CULL, 0xD76A3329F3C96FD0ULL, 0x967387294CC56E20ULL
        },
        {
            0xBB9C93702029B623ULL, 0x633C2BAEFF6ACD77ULL, 0xC1BDEC3CEA3897B1ULL, 0x5508A838A2EDE789ULL, 
            0x4B8E794A588EC7F6ULL, 0x6EA7862FBCE995EEULL, 0x526A78837B3DAABFULL, 0x2C7FAA599FF07D90ULL, 
            0xA75E53C06E05EFF7ULL, 0xBB2677597D45CDADULL, 0x4BC212283242A494ULL, 0xCC5A64762F9A813AULL, 
            0x86A74DC58E481024ULL, 0x5D0929E620F67958ULL, 0x2DF42FA7717E5680ULL, 0x97169CF67563B255ULL, 
            0x07BBF0AE7FBC4A9DULL, 0x96E405B520A0259EULL, 0xC640602CFD83DC30ULL, 0x0DFCF3145DE2FFBAULL, 
            0x09AFB17DE7138F44ULL, 0x3BF61A5EDB148D3CULL, 0xF767A0DE4F3099BDULL, 0x1EBA58FC0DE30EA2ULL, 
            0x44403747E85A4EE6ULL, 0x2C6D984B20E5AD8EULL, 0xC5F0725F23089D67ULL, 0x6C70958C7957B57DULL, 
            0xD83F5CF56408F1CFULL, 0xDADBF9E76CA97DA4ULL, 0xA2FD6B4CA222B070ULL, 0x9844AFD3AEB9BA43ULL
        },
        {
            0x67330B62C7E97F32ULL, 0x3BF81997ED72EDF9ULL, 0xC40584575059E2E3ULL, 0x9A2F6BC12AB9C384ULL, 
            0x6A437D557DD9372EULL, 0xD7A0A6D783F25378ULL, 0x3077998351757062ULL, 0x6BCDA5EAB3F7DA5EULL, 
            0xD701DC7467F05A3CULL, 0x7ED6ED7F86EBEEECULL, 0xCF228B40F4FB7BA1ULL, 0x121E1718310FBF19ULL, 
            0x636EBBE2C5331952ULL, 0x7FB8737CCF0E1AB4ULL, 0x198EDA3BA46C1DD0ULL, 0x1975A9D5802E8C75ULL, 
            0x751CAD4B61338527ULL, 0x490EF647638ECB7CULL, 0x1F1BEE76DF320A18ULL, 0x2444B7B3CCF9E1C4ULL, 
            0x93602CC58C724100ULL, 0xC24C4D1EFD2B6606ULL, 0xED20BB642EB87195ULL, 0x0BF3D2806DDC8865ULL, 
            0x7F74C8639D6577F0ULL, 0x2D0F256E22C67A91ULL, 0xC1D601AFB6015728ULL, 0x0A53BEBBFAF64799ULL, 
            0x25EC203A057E0B3FULL, 0x0C5965C89C9ACFDDULL, 0x3A39F476463329D3ULL, 0xF5E0D59F6B7BCF74ULL
        },
        {
            0x0C720464D7E3349DULL, 0xB3F3D474FA4B5FA2ULL, 0xA378CA7C4602AD4EULL, 0x3F2AF99D942F64CFULL, 
            0x9EEAAE486F586B24ULL, 0x82713C91F3D59400ULL, 0x4A6C957A73C700D0ULL, 0xBEB24FEADFC4B540ULL, 
            0x4A600939429E5F4DULL, 0x0BEF24B2D34F8C41ULL, 0xA3D670C640D77085ULL, 0xA3D6B55D54D7D35AULL, 
            0x94A66D47598B578BULL, 0x427001BF0ECE74C4ULL, 0x793B0BE84CC86852ULL, 0x6FBAD6EB1FAC1874ULL, 
            0x29ED2BFFF028281DULL, 0x486A812AE15B9CE0ULL, 0x613CD7DA82D29CCCULL, 0x6C5E60471753506EULL, 
            0xB2F37861FF8DA4C1ULL, 0x8FDD42D973F3A769ULL, 0xE8136606E99E749EULL, 0xD21485888E7EE2B1ULL, 
            0xF27CC794FF91B251ULL, 0x0D37213F989BA72FULL, 0xB1BC16B449A780A7ULL, 0x2EFF8C066E8288ACULL, 
            0x300F26ED1F180A3EULL, 0x4F636274ACC0B5DCULL, 0xFD1CCDA91B2C3CB2ULL, 0x4D6C8A8D8EC37EA8ULL
        },
        {
            0x6A95A11FED781E88ULL, 0xA77610D32974C4D2ULL, 0xD7A30306033E405BULL, 0x610D1EEAD769553CULL, 
            0xC714F25706BB4287ULL, 0x3BD3E83093D3DB96ULL, 0x092478F8155DF059ULL, 0xBB355963BB21FD1EULL, 
            0x185E3A1DA0FFA99FULL, 0x36C1E56CB870B2C2ULL, 0x4B222FC634799945ULL, 0xDFDB18C525066286ULL, 
            0x1D40FFD8258EF563ULL, 0xA65C2E0A7CB7DE50ULL, 0xF07E8E50ECA167BBULL, 0x9620B13C2A6C1FC7ULL, 
            0x99CB3ECCD6F5C529ULL, 0x964D66B58AEBAFD9ULL, 0xC48D90C41031F229ULL, 0x3513E3FE0B840C0CULL, 
            0xC346BD710961AC6AULL, 0x0BC1F3B1AA74E412ULL, 0xF22539DA66432ACEULL, 0xE15790062C06C8FCULL, 
            0x73736675C9BBB2C1ULL, 0xEB0B805387CC2C6BULL, 0xF4BEB31CCE35577BULL, 0xF6DC0625FACE2025ULL, 
            0x5E006C4332BAC8AEULL, 0x57A0673C42EEF431ULL, 0xA893277235FB5E13ULL, 0xCBEB54B3B5113550ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseAConstants = {
    0xE99CA59A2E93D5A5ULL,
    0x3D6E508373E1302FULL,
    0x42F2D49CF1FB4800ULL,
    0xE99CA59A2E93D5A5ULL,
    0x3D6E508373E1302FULL,
    0x42F2D49CF1FB4800ULL,
    0xE51F654DAB5089EDULL,
    0x007820640E79F3B0ULL,
    0x34,
    0xFF,
    0x58,
    0x3A,
    0x49,
    0x33,
    0x8F,
    0xA0
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseBSalts = {
    {
        {
            0xC98D6DB43792E577ULL, 0x7E6BDFCBD2A21126ULL, 0x8AF20910ABCAA3CFULL, 0x73A459C1A0935FA3ULL, 
            0x2C57ECCB7B03E5C2ULL, 0x8FB50A40C4961CBEULL, 0x09DD8AED2F66D8B7ULL, 0xBB5C5DF60811F2E0ULL, 
            0x6E15D6DA4D3CF8CCULL, 0xEFFEA36D39D322C3ULL, 0xE632EBABDB99C7DCULL, 0x35E940A0BB55EBC3ULL, 
            0x577DEEC227DE5A2AULL, 0x05B9B9DD214DD19FULL, 0xE3082E2EE158C760ULL, 0x562F857804D59E6AULL, 
            0x3FF9B1DFC9EF6BE6ULL, 0x0868CCF6D21E2B36ULL, 0x6378D0E0F10FB372ULL, 0x80FBF1EA60FFE48BULL, 
            0x0A763CFACFBC2D72ULL, 0x5A6C030FA107C66AULL, 0x4CB0B26D7EE92C05ULL, 0x2BA2FE951DDE5DCBULL, 
            0xC98BF4B3E2E539B6ULL, 0x95FE1E5F7E5B3FC5ULL, 0xE575C7FC1CD98E77ULL, 0x642DF7493DEE7499ULL, 
            0x8B468FE9D5474B9DULL, 0x56D038F223D233C5ULL, 0xAB1E69F26D9A7DE2ULL, 0xB8BDD8BFABDA82E3ULL
        },
        {
            0x3FEA34C03EAA45FDULL, 0x522D23DD988DCE06ULL, 0x6CF7C93DFCDC81F6ULL, 0x21D4D20462747C44ULL, 
            0xEB4E09393070B282ULL, 0x34BB8AF4877AD07EULL, 0xF0E0779C986D2FB6ULL, 0x4A9887F10069624AULL, 
            0xD1D29D6220B4C570ULL, 0xE2BEF064E27CA129ULL, 0x0DBF91E65D85C5D4ULL, 0xD4A00B40B8251AFAULL, 
            0xFDE35F7FEAF0AF00ULL, 0xC6DED3CA2A09B5DFULL, 0x74FD65DFB38C58C5ULL, 0x1954E111D76AD793ULL, 
            0x3B022A032A55D6E6ULL, 0x1E7B95C2419343EDULL, 0x2330C666399913DAULL, 0x57E9180D81BF93A7ULL, 
            0xEC2F956F8A467418ULL, 0x8F8C9009994F7EA2ULL, 0x87523B9F2E22D33CULL, 0xDC1C79903127AF1AULL, 
            0x369A22431E2D70D7ULL, 0x351719AF37AC3FF6ULL, 0xE3B0BCB7C03200B9ULL, 0x5BFCF95E2243F59EULL, 
            0x53D689124AFB3462ULL, 0x305A2A1E2913AC60ULL, 0x692B183415552730ULL, 0x44653C494BF3110AULL
        },
        {
            0xC05C554918FC5450ULL, 0xCD63933F693231ABULL, 0xC0BAFCD518BD5346ULL, 0x8B6E2DCD5E633785ULL, 
            0xDBDCF199F63D9B57ULL, 0xF23334EA9C17FD79ULL, 0xC30B93C94B16BEDDULL, 0xD08055AC2B4211B6ULL, 
            0x4F9AD9C5A8B4B922ULL, 0x5335715DA6390CF0ULL, 0xEFAE3F732403A942ULL, 0x1E47A2C2790E5E93ULL, 
            0x0B83C0A37BE92621ULL, 0xC301A1273D31CE8DULL, 0x47A805685869385BULL, 0xC700F3F6F439C4D7ULL, 
            0xFB8CD3583F9CD4B9ULL, 0x943D392D5E85E32DULL, 0xB9DF67039AF94A82ULL, 0x74825229C333E47AULL, 
            0x34874410C71F95E0ULL, 0xD09CF30FE65102D8ULL, 0xD8C9EB9F07D9C8FBULL, 0xB5832DC5ABDA418DULL, 
            0x81E294869C3D9082ULL, 0x6C18102BA85EADECULL, 0x3D669B185CD2F26AULL, 0x991B7697DF747187ULL, 
            0x0D4E4CBC4872ECEBULL, 0x5E7449A88DE2587CULL, 0x11338DFA8BF177D0ULL, 0x10A46071E24E40BDULL
        },
        {
            0xDE018183161E2F1EULL, 0x90B0F3500BA1E6F8ULL, 0xD18D1ABA0B857ACDULL, 0x3A22B936C42FD031ULL, 
            0x56D1F23386AC328FULL, 0xB46658CB0113EB55ULL, 0x4BA1A97C6F2CF93BULL, 0x400D1164F4B72E3CULL, 
            0xDD0CDB11FB0438F7ULL, 0xA0083999F41AFECAULL, 0x4EC0E8435A1AE0A5ULL, 0x7790EDCEB7A06F78ULL, 
            0x8DE510DC7F41C698ULL, 0xF6549AC7E34EB948ULL, 0x15E0BC0B2DE08127ULL, 0x915363078FCD6E1AULL, 
            0x2625655DC49FCC34ULL, 0x07985DEFB896B2FAULL, 0x9CB962C5D06B45DDULL, 0x2FA0B6643D27359FULL, 
            0x77917B70E94D519DULL, 0x90442D7EF3C85072ULL, 0x6880B0574F7AEDD1ULL, 0xFB30A59735E7A85FULL, 
            0xA6A7D1CDDFE0407BULL, 0x0B19BD8298F65379ULL, 0x3977D34F1CE1B7A1ULL, 0x72917544D76DFEB2ULL, 
            0xBA9F63F3BD47302DULL, 0x22288545DB980645ULL, 0xD20A2A90CA25F893ULL, 0x66B2228FFC79F715ULL
        },
        {
            0x5CE7C87E114E2239ULL, 0x22042B10AEE0C218ULL, 0xEF9979BD27B8257BULL, 0x74E9823A480DA9E4ULL, 
            0x1FBC89DA4EF32810ULL, 0xBDD9BFD2F0B53734ULL, 0xF4C2B49367D14EE4ULL, 0x77250845A30A08CAULL, 
            0xD0D025F1B1FF32ABULL, 0xD37D29C908250CC6ULL, 0xB71553372257341FULL, 0x08E91F8F3A321F12ULL, 
            0x9A409DDB8A57A294ULL, 0xBA97A1FBD098BDBFULL, 0x8601D2998724781EULL, 0x205D12C548C02BB5ULL, 
            0x2B0727E3C0C88B28ULL, 0xE4C7FCACAAC524B8ULL, 0xB06E237A11DA099AULL, 0x1C78B2BAFEAAF444ULL, 
            0x71FFB73AA3941417ULL, 0x83D20CE960E23951ULL, 0xF3B21E42DD0AF553ULL, 0xC95D8CE4FD17D91DULL, 
            0xB3E1B7A66E59232DULL, 0x2668DB81E1258858ULL, 0x52F5270B101D1DF0ULL, 0xF34E85D1CF22BF0CULL, 
            0x4E10225A22729A26ULL, 0x6FEB22E1D55A68DBULL, 0x1AB81704799CFA78ULL, 0x2D8A4468730FE852ULL
        },
        {
            0xE7EAA863623C54E9ULL, 0x8E964DC836D4BB12ULL, 0xB1093C49A97C3941ULL, 0xE1639C580DEEA2BBULL, 
            0xDCD5FA625C092E2CULL, 0xEA9AB3802146FC1AULL, 0x7A0C7E68C89EF0C1ULL, 0x9F873DF80FAE0538ULL, 
            0x1E286D4A49EA8B32ULL, 0x592A968D36AB4546ULL, 0x76E7DDC738EB9CD6ULL, 0x711537CB83BF3AC5ULL, 
            0x1270100B907C846FULL, 0x1ABE4F6412DF097CULL, 0x69F0DDCFF49E8EE1ULL, 0xDCB584E27D37C28EULL, 
            0x098F0C0F707745D8ULL, 0x34208D35911BBCB5ULL, 0x3DD679444A74B720ULL, 0x72421DDFAE4449F4ULL, 
            0xAE6EA139FB9EE151ULL, 0x3681F1FD03DC10EAULL, 0x1CBC4E5FAA449ECEULL, 0x35EFAB090464D2D7ULL, 
            0x0E625D9A20E8BAEEULL, 0x517272341FACDDEDULL, 0x06362AE8916CEF61ULL, 0x3743621CF0804508ULL, 
            0x5A12D035EE6435C6ULL, 0xB48E797FF7A883CBULL, 0x22A4AC0037E1AF4DULL, 0x8046A3CE62B3A659ULL
        }
    },
    {
        {
            0xC46AE23CC16060FAULL, 0xACAD2232CA34CCBAULL, 0x30DD48CC23575F19ULL, 0xAE7198C1371E5C23ULL, 
            0x63C0112FC920182AULL, 0x0EB60101214DFFAFULL, 0xF54D9D9CF3EDB658ULL, 0x4D8F697C7EA1B1B9ULL, 
            0x5C6A4D21DEC1A71CULL, 0x5942F8935090B5B2ULL, 0x0044D21FB866C72AULL, 0xAADCCD0069AB105DULL, 
            0xE2B99A13094D0F88ULL, 0x9A732AF80CB4902FULL, 0x8F3290E3A0FD91FEULL, 0x9DBE4E01ABF1FB1AULL, 
            0xCAEFBAC0F10BD5E8ULL, 0x733DFDB5EE6B124EULL, 0x99F72589FB40C55CULL, 0x3579B5FA0B7D8383ULL, 
            0x1088F51CDEAB4A6BULL, 0x2D0385699F072280ULL, 0xA41A98F5E7C17E83ULL, 0x74A1362C278A5A62ULL, 
            0x81DE04A676B41F13ULL, 0x3321A77D8E887318ULL, 0xDC50A897540A4B12ULL, 0xE7DFDC2A294535BAULL, 
            0x7F6AADD6DCD8F223ULL, 0x767016B0EB37440BULL, 0x3F1D61AA485F3AE9ULL, 0x5D06444FBE901B99ULL
        },
        {
            0x1C07F880907DE56FULL, 0xE702F53B19430EABULL, 0x88BD330371F833DDULL, 0x2746BAFB17D4732EULL, 
            0x9AED66C29EDD28F1ULL, 0x46AD053B097367ACULL, 0xB3971CF44ADF0D59ULL, 0xB28F01FA1BF6B431ULL, 
            0xF784C035F7770DB0ULL, 0xFC2D70713B9051E7ULL, 0xADAB4040038391F7ULL, 0x8ACD08EACB8B5F3EULL, 
            0xEEE328023EC084A7ULL, 0x577C1E0B0BB28EE6ULL, 0xD07E9878C522AA8FULL, 0xA150DF2C2F5EDAEAULL, 
            0x70E2CE9F4A827214ULL, 0xC22E2BF63359C3BAULL, 0xE533E3E86BE2D5C5ULL, 0x43CCC221552EB179ULL, 
            0xD9789DCD2A90BDB7ULL, 0x5C9536B9F2C67090ULL, 0xB0A39AA20CB58A12ULL, 0xD14830586245182DULL, 
            0x4151428F8838B1ADULL, 0xE4FA812EB41A30FFULL, 0x0573E1BF9558605DULL, 0xFFDB029E644F5495ULL, 
            0x1C517528FA7BB96AULL, 0x3BBCBE92279831A5ULL, 0xAA9BD05FD3459F3CULL, 0xDFE6CB07DDF234DEULL
        },
        {
            0x28ECCA7BF77F2B06ULL, 0x21435030B1ED6D27ULL, 0x330F7A5CD6C94F4FULL, 0xD38CA22BCE216A68ULL, 
            0xB10D4E9EF046A804ULL, 0x193C5813C2CB75FBULL, 0x8B0D5F5B5C9072CFULL, 0x2EEA4796B9D4A126ULL, 
            0x90DB503DFA424E64ULL, 0xF29271B9FC2F0BAAULL, 0x7A2993BEA073FC1BULL, 0x501AF7879CA95E54ULL, 
            0x8AFBF3C1FAC818DEULL, 0xCE0D61D4C1D834ADULL, 0x274320B748128609ULL, 0x9761A553F26216D5ULL, 
            0xEF9835BD9FDDA1CDULL, 0x47AAED5DA091F1D5ULL, 0x77B79D06D3DA36BCULL, 0xBDB088F5D78FE746ULL, 
            0x0A9CF6636A1D1ADBULL, 0x2F3BC0A47101D903ULL, 0xE9CEEEBAD3511EB4ULL, 0xC732D1A44A90B70DULL, 
            0x9AA12D86FD84E609ULL, 0x487FCB413DB090E5ULL, 0xFF1C5BD5DFF218FEULL, 0x67EB4B5383CEF003ULL, 
            0xC35332E800C5B04BULL, 0x9C10CFC211E3BAF0ULL, 0x9B3DD5DB451E4D5CULL, 0x37E3852F4F4F16C1ULL
        },
        {
            0xDCC4D87C1B1FFFEFULL, 0x41670638FC5D348EULL, 0x3C7671B39CF82EB6ULL, 0xC42095F2BC3585E0ULL, 
            0xCB5651EE6735C94BULL, 0xD50C50B883147FF6ULL, 0x8B20DD75546FB0A6ULL, 0x939A8350D9E905B7ULL, 
            0x6B54E71F02A7C25DULL, 0x546B584868EB314AULL, 0xD5DB73055539BFC4ULL, 0x1D2A507604F7F545ULL, 
            0x34F9071115B8E6CDULL, 0x9DC58230BA7F6951ULL, 0xFCC32575619853E0ULL, 0x4E5162FF380AB070ULL, 
            0x8ECFBC2E8187E4F4ULL, 0x955BDD8166CB5875ULL, 0x8CD148B0608B7004ULL, 0x0491D214DC9E829AULL, 
            0x33F57C35D20A184DULL, 0xA8554A781B9D9D82ULL, 0x7CD48930F8B8058AULL, 0x7B5F18C13A4F0BABULL, 
            0x9628AA5BA8DAEF45ULL, 0x133FB190C371252DULL, 0x3ED9146AE4A12B83ULL, 0x6E41E079AFDC96B2ULL, 
            0xCD13684B31E6061EULL, 0x233A499E5C3DCE44ULL, 0x437D87639D7998B5ULL, 0x4BE6B52D5E3A6948ULL
        },
        {
            0x30AC3B20AF9BC9C8ULL, 0x0A7F82EFED623B64ULL, 0x8E608D4E400356FFULL, 0xCE078F18BC2B9CCCULL, 
            0xA37BD3EFD10A875DULL, 0x25EEDA1BF4909324ULL, 0x88C7972F1E45D5EAULL, 0x718C18F2D824C93EULL, 
            0xF2ED4BA21B83F1BEULL, 0xAD553E127F4CAA3AULL, 0xB89C483F4E7F6B1CULL, 0x89902EEF2F0AEB6AULL, 
            0x8D625644110A065EULL, 0x7DCB30F22CBBEA42ULL, 0x1B53B5EE9AB863BBULL, 0xF115EC8338777472ULL, 
            0xA0399DFBB0B7933DULL, 0x33267297193C31D2ULL, 0xDFDFBBEFC332D621ULL, 0x993A3D4176B4CE32ULL, 
            0xBC95C9C08F9B0A50ULL, 0xD11C1FFFB0A379B1ULL, 0xFC4E4F151F6CDE5DULL, 0xD783BB09F1B2DC3BULL, 
            0x9F3552E11C5F9BDAULL, 0xEA8E169116E9AB8CULL, 0x128C833408EB05BDULL, 0x3A5C1F0322B05980ULL, 
            0x5EF84439BFF79A10ULL, 0x4995C9E798B74CDFULL, 0xCCE841E161FC7B55ULL, 0xF22848BD618D5E5CULL
        },
        {
            0x52D9F8D5F771FCF6ULL, 0x81C97BCD13237BACULL, 0x1FF80D2A12275F15ULL, 0x25952E096AF713F7ULL, 
            0x98FF46EB252E4D92ULL, 0x08AA5B42182A5905ULL, 0x539B2EF06AA19B6FULL, 0x49CB56C821566002ULL, 
            0xE410884E53992765ULL, 0xB97F32E0056263F2ULL, 0x3C8EDC0604EBC5B0ULL, 0x38A5B01B40E6D78AULL, 
            0xEF8E615B424BBA99ULL, 0xE268B60A7F4D1ED9ULL, 0x4B4875A3A7C40566ULL, 0xFF307394FBB0B25FULL, 
            0x4BEF9342FA5112E8ULL, 0x632F0E302DD5D210ULL, 0x572D65B289430926ULL, 0x2A11A29DC61F27B6ULL, 
            0xD728E53824BF1B7EULL, 0x609DDBAAC5964E94ULL, 0x798C8AE309E20CE8ULL, 0x2480AFA3FCD638F0ULL, 
            0xA648B72FD2874E6BULL, 0xE0674260DE58F6C5ULL, 0x62E9717BF0573821ULL, 0x821ECC74BA674A0EULL, 
            0x99C8083F44FE5C1AULL, 0x17273879B1E274BDULL, 0x7896CEE197E755CFULL, 0x979E31E46ADCCFDBULL
        }
    },
    {
        {
            0x6C82F018F1843146ULL, 0x5B47E3491582A688ULL, 0x46EBCB158B29A6B6ULL, 0x8202DC124BD30691ULL, 
            0x81A6E0D0931D52F3ULL, 0x7310AA2D4DBCCF65ULL, 0x36C708555E549D09ULL, 0x0780F7CDF74783B4ULL, 
            0x91BA439E35112903ULL, 0x0E49E6BBA943AEC7ULL, 0x9227D25129C7D46FULL, 0xBB3AC9B43D13DCD6ULL, 
            0x63E0A504DFFB5BFAULL, 0x2E8AC35991191EA7ULL, 0xAC7998B9C5454A03ULL, 0xD8637E4A13AC63CAULL, 
            0x96400AE3680B48D9ULL, 0x9D560027F4F4F4B5ULL, 0x8B4806205763E569ULL, 0x8FF3651354E4DBAFULL, 
            0x735589969B97CB75ULL, 0xCF9B363F810885FDULL, 0xB3A7A2C3DE36F147ULL, 0x55CA9065F6D85CFBULL, 
            0xA5BA78EEAA331BBFULL, 0x9119CF0BCD2CB9C4ULL, 0xDE5261FC5775BEC6ULL, 0x7AF5514BD7F44C50ULL, 
            0x05D788156F7572D9ULL, 0xEEE12F90EAD3C721ULL, 0xA593D8F82642D25BULL, 0x486B1CACC1E7C3FAULL
        },
        {
            0x1167C3FFBF9A406EULL, 0xD921DC1FD84DFC98ULL, 0x2523F22BA7194221ULL, 0xDDA26E6CE257F677ULL, 
            0xBD8C857870969C25ULL, 0x1CC84B1133C155F0ULL, 0x985470EC7FA28306ULL, 0xFB2AD9C534C1D8D1ULL, 
            0x337CABAFD3F77767ULL, 0xDD034FD2803CCAF4ULL, 0x5C22347853B58E4DULL, 0x6C242524DA6007E7ULL, 
            0x540046E613D15CC3ULL, 0x344F31A1E9E1F1E4ULL, 0xCEC0C2E35E634BA0ULL, 0x911E64F0EE83CC92ULL, 
            0xC369D9F4C5FE2572ULL, 0xACBCA826CFC6A656ULL, 0xDA4DE8775C52F72FULL, 0x5BB9D7AAF4D83A61ULL, 
            0x1F4DD829A92EF866ULL, 0xF34A970DB3213E18ULL, 0x532D782BDEC4EEE2ULL, 0xDAA042168AA7BC04ULL, 
            0xFDC785EF20FC183CULL, 0x3565E0AE5BC0B496ULL, 0x44758A87D0F9C0DBULL, 0x52073EE25D9FB9EDULL, 
            0x7C4DCF6D68D79165ULL, 0xCE764FB469C225A8ULL, 0x4E133394313726A8ULL, 0x54D37E18410247A8ULL
        },
        {
            0x2C2F675F195933A7ULL, 0x37A763B86A946A74ULL, 0x5237B324B3FE86C5ULL, 0x724B8E7BE1C4447BULL, 
            0xC24B2508C8EB4B31ULL, 0xAF95B221F4E990A2ULL, 0x96E2AA598677E9F7ULL, 0x1BDE445E82BF74F6ULL, 
            0x8784DC30571582A8ULL, 0xE6B3F63DAA716498ULL, 0x776B72B00A6AEC7EULL, 0xF09C2DE46CF3E6CFULL, 
            0x44597CD35ED22EC3ULL, 0x2482ABB26BC1A9D4ULL, 0x5D7551E9545505F4ULL, 0x1C59159718BD7FA6ULL, 
            0x6ED003E2B684FD38ULL, 0x3AD62B9AEF194888ULL, 0xC168B88583964B5AULL, 0xB95BF0842C2D2858ULL, 
            0xEBCA37C3D7B43F03ULL, 0x8D310DE9B182867FULL, 0x38158B428F04603EULL, 0x53BB5BA088B3C962ULL, 
            0xA1ABCC84ABC9887EULL, 0xFCF2531E384F6FE1ULL, 0x8727AD522D509E2AULL, 0xE95394DFF7BF192DULL, 
            0xA76B19ABEB97E864ULL, 0x81FB35E51DDCB8A2ULL, 0x11B95353578AE98EULL, 0x9F820F2B01380B3CULL
        },
        {
            0x5F1ADA19AE12D12FULL, 0x4004F3ACDF71EDBDULL, 0xF235F5D365FC490FULL, 0x1F4229FBF48828E7ULL, 
            0x44BECB08EA6B8CF8ULL, 0xD29A406DE06D26B7ULL, 0x67B7FC2E48BD010FULL, 0x11149CC987A87253ULL, 
            0x95A737755736372DULL, 0x7EE4E087A6EEA9D5ULL, 0x179A8DA7317DF6E3ULL, 0xC9F9A97D6A56AEABULL, 
            0x8B37EE7A03C08C82ULL, 0x175C1B2FA41D6452ULL, 0x50B7B29A0FF574E5ULL, 0x715FC571CF1225F4ULL, 
            0xE7EBD92D01B7DAA2ULL, 0x6D19C707E9549E62ULL, 0x4F05F0BE5C8C75FCULL, 0x77E3FF41D5C937CBULL, 
            0xDDFD632C4C7CF745ULL, 0xC5197B5FF43F0229ULL, 0x58CC682591A14F63ULL, 0xC8C65BFA9E95B47DULL, 
            0x1EEF7708A9388A9DULL, 0xA6E4E6D91E9EA4F7ULL, 0x6D7ABD0EEDBD2C67ULL, 0x7AE3A7C148F53CCCULL, 
            0xC01FED38C06A1FD9ULL, 0x98518EC12F40939DULL, 0x3A05D12A89596B84ULL, 0x9DDE6BEFBC580392ULL
        },
        {
            0xC685EC4D71314DD6ULL, 0xBA2737E7BDA3FA35ULL, 0x91AFDF09C190EA50ULL, 0xF18ACFB7896781C6ULL, 
            0x812A65C3E2803995ULL, 0x5366C8FA6183BFC3ULL, 0xB2AA74BE7C6EED47ULL, 0x16706E42E3B2090AULL, 
            0xE048027A22744211ULL, 0xD9DFB7B5F8158584ULL, 0x5510A2550B2EE5E7ULL, 0xB8A525BDB7F17DA6ULL, 
            0xF7CA5EB7E8AE84A1ULL, 0x91C9893F2A0010FBULL, 0xDF35E6771854E5AEULL, 0x4140F4D1880897B0ULL, 
            0xB24A2D82BAD515E3ULL, 0x7812CE1B197355BCULL, 0x648B05FA09473E4DULL, 0x8700DA3557CBA378ULL, 
            0x4C36C37DEC667430ULL, 0xDCFC841E9481C51AULL, 0x15FDA25ECD8178A6ULL, 0x0B92FEE4E58C95D1ULL, 
            0x3DFEFE25EFF99840ULL, 0xA2F27E6A6A13A2EEULL, 0x800BF8206B13FF71ULL, 0xA6DB27AD3A4CCD0EULL, 
            0x662E5AFCD87122D8ULL, 0x443AC263351DAE04ULL, 0x4BDB83546A41006BULL, 0x95E61848E6D36879ULL
        },
        {
            0x58B42559FBCD480AULL, 0x936B4774D8EAE3F4ULL, 0xA84F52E199F30EE0ULL, 0x457D6DA2EF3861B2ULL, 
            0x2F30C907F1166C7BULL, 0xDA64CED2991FB2ECULL, 0x6FBF091252B9AD59ULL, 0x7EAE3561FB9475A5ULL, 
            0x5C50A1C7A4B99371ULL, 0x62C0CB188A11EC80ULL, 0xBA8CF47461801F11ULL, 0x059067A3856F6DA4ULL, 
            0x0FE683B941E80C99ULL, 0x40A8C0EE7C947654ULL, 0x07B0A90F82ADD880ULL, 0xB32EA819E39AFF7CULL, 
            0xF99FCFA2F3780791ULL, 0xF720C111F0884AE5ULL, 0xDD34D722A3A4D281ULL, 0x69CF107C633CD3F0ULL, 
            0x17CACAF2484F99AAULL, 0x476972BF640946C1ULL, 0x3FB21FA221A4C564ULL, 0xD6055CF634705C29ULL, 
            0xD570969ED2C2FCF6ULL, 0xB46A92A5960FE45FULL, 0x1AFC476455419CF6ULL, 0x756251F4A8B692C5ULL, 
            0x8F4520B3DE6DB5FEULL, 0x65E408049584FA46ULL, 0xCFADFA826BCF4B98ULL, 0x83AE80F8D0DAC798ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseBConstants = {
    0x9AE64F45F5D6B550ULL,
    0x2432DB04F9EC5BBCULL,
    0xB133D1BEC2385C3CULL,
    0x9AE64F45F5D6B550ULL,
    0x2432DB04F9EC5BBCULL,
    0xB133D1BEC2385C3CULL,
    0x3B12CABEC7E194E3ULL,
    0x48CAC5B38163B6B8ULL,
    0x91,
    0x9B,
    0x0C,
    0xB9,
    0x15,
    0xD3,
    0xAE,
    0x26
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseCSalts = {
    {
        {
            0xBC3D21F2201FF7C6ULL, 0x79BC7E5571B6115EULL, 0x7A895AF306189E5BULL, 0x91A046C5CFA8DE04ULL, 
            0x663873D232C537DAULL, 0xB6DC1CA908907ABFULL, 0x1141DCF80ACC651AULL, 0xDFE74B938FCB806CULL, 
            0xAAB423A1AA101107ULL, 0xF906FE8E900E74EFULL, 0x74168E0436D33AC1ULL, 0x890798FCD7E35D27ULL, 
            0x3C9C987948849DE3ULL, 0x73BA473A103CA6E7ULL, 0xD432E83A16093500ULL, 0xBE813B4E965C70F4ULL, 
            0xC28C05994DC32842ULL, 0x22C31B76935DCA1BULL, 0x5CF43266CBD35762ULL, 0x39F7E4E7933B26D4ULL, 
            0x57C69776554D62C0ULL, 0x31B04570F45EF7B7ULL, 0x9776EF81F3F40BDCULL, 0xD4963AB14A381AC8ULL, 
            0x5962B2F3DCF43028ULL, 0x602EE0F20924595FULL, 0x2A521FC979BD9A73ULL, 0x5A0632CBDDC6A560ULL, 
            0x8D795211B88FBD4EULL, 0xB6913C8670D5ACFAULL, 0x5F51EBF1CCEA61AFULL, 0x3E7AFBEC305D7F7CULL
        },
        {
            0x7DB17504AF5D8CB1ULL, 0x5C4AB361A848D1EEULL, 0x1FD25731A799DD6FULL, 0x86043927BB3A2DDEULL, 
            0x6216EC3503F92ADAULL, 0xF3BC479172078423ULL, 0xCB13F72288C89DB6ULL, 0x95B9FC4E8B885EF9ULL, 
            0x093EFF748A4283E1ULL, 0x6F948778AB067AF4ULL, 0x119638B88DDCE259ULL, 0x343C9268DC80A5C3ULL, 
            0x0A892DB62E0DCDD0ULL, 0xA8C535B08F0625D8ULL, 0xFFAEA0A7E4724F2FULL, 0x8103A5B5ACECA3F4ULL, 
            0x09E67D80483A7C4DULL, 0x1E3606573E400293ULL, 0xDDD8F8AE62C73A07ULL, 0x426F317194C8DF81ULL, 
            0x3DA8FA4A82803F9FULL, 0xF60AB865D3122020ULL, 0x12EDFFB166F0AF77ULL, 0x58F9812884713614ULL, 
            0x2A19AD1249C123E0ULL, 0xAF5C90BC7EF7D29AULL, 0x821E6F9907E18034ULL, 0xDDAF4B120B93F48BULL, 
            0x0E54FFE5C6024ACEULL, 0x7F6A58DCF6032F6DULL, 0xCFDD9E95E583E6C7ULL, 0x71F3EDDCC5EC4A1EULL
        },
        {
            0xC4C78FCE16970EBEULL, 0x1B08A456B7FF2F0BULL, 0xD55D4F7D61C432B6ULL, 0x78DB07948D5560F1ULL, 
            0x4A9AB582F86E4188ULL, 0x555739989672A826ULL, 0x359E34C6ED279825ULL, 0xC2E8F9C171933C35ULL, 
            0x17693AE1B7DBF73DULL, 0x0E6A0A402963FF54ULL, 0xAC261493A905234DULL, 0x69AAEAAAC957591AULL, 
            0xC14EEC9AA239D589ULL, 0x513D63F92C77A8D6ULL, 0x7552BC07B8CE9A2FULL, 0xB16C59586EE08FD6ULL, 
            0xD3484AEBC37B1B62ULL, 0xBCC5AC64EA766F6CULL, 0x66B1D8945CBA50D0ULL, 0x6A6F15E72AD58626ULL, 
            0xB45EC389F3E5ED5FULL, 0x61C47990C5C27A5EULL, 0x224128B1F692BFCCULL, 0x89C41FD6FF40E2CEULL, 
            0xDA31ADF03ADC6917ULL, 0xC19D8509AF7F7692ULL, 0x5C3E374A3BE115C3ULL, 0xB21304864B10C5FFULL, 
            0xD7E125A789F7681EULL, 0x44B9D4B876C4DD17ULL, 0x165556D66ED3DE99ULL, 0x15A950E6DE042E40ULL
        },
        {
            0xA7504AFAD14A51F6ULL, 0x776DF03454AFD4E8ULL, 0x8CE780812592AAF4ULL, 0x27D5A0DD741394F4ULL, 
            0x25254CC9B9EE325BULL, 0x93708BF969744EF6ULL, 0xA7CBA1D6DD2BD729ULL, 0x0FFF116D24C1D987ULL, 
            0xB2690D14B30EB04CULL, 0x891D72AE9EB484E3ULL, 0x742CA928AED5047CULL, 0xB05CB96D65940197ULL, 
            0x94A5FDC7610CAA39ULL, 0x30F426B53032C6FAULL, 0x31CBC2364FD16D42ULL, 0xAE6027F7C6C68910ULL, 
            0x028515D932531ECFULL, 0xADA2BE541C789806ULL, 0xE26E349966D13175ULL, 0xB3352801D7A3482BULL, 
            0x4BA7E67C21445967ULL, 0x29BFF75A9C0F9053ULL, 0x4CD79779051452DAULL, 0xE7C835695B984435ULL, 
            0x541E2B5498AF84A8ULL, 0x314C28E8D577FCF0ULL, 0xFF68F238B89AB6DDULL, 0x34A160198BAB842EULL, 
            0xC90F2E411F2AFC74ULL, 0xAB0A1DAB3BFBEBA5ULL, 0x9CC5F86396851415ULL, 0x21CEFBCAC68FF3B0ULL
        },
        {
            0x0E6D77E4521E63B8ULL, 0x6F61DC93E2414C9CULL, 0x2FDBDB4EE027F342ULL, 0xDA4228AF8E08F284ULL, 
            0x86A9EFB1EF9AF409ULL, 0xA9C37CC189DA7653ULL, 0xF34972EEB81B372FULL, 0x84A4FEDE52228F9EULL, 
            0x356BE065013A8189ULL, 0x262DF6226ED43560ULL, 0xDDF0E645681E32EBULL, 0x09018732C2CD8802ULL, 
            0x258C3ADD216E0314ULL, 0x981C3AC69ECE4513ULL, 0xF49D8C6F0203302AULL, 0x3BB797304BCB46A1ULL, 
            0x926F4CE357D1ABE9ULL, 0xD550C2DCAE4086A6ULL, 0x81ABBD6843ED2DD2ULL, 0x5155C15C571DA41AULL, 
            0x7253F91E014920BEULL, 0x3A40BA73F26A7F7CULL, 0xC77852288E31E1C0ULL, 0xC604E0148AD707A8ULL, 
            0xD880F1E2DE5AE53BULL, 0x23AF18F901430D7FULL, 0x809643CBCA7AEB7EULL, 0x80E2E48375168E96ULL, 
            0xA97788DA5EF37611ULL, 0x664BB7AEC400B68DULL, 0xC4E5D47DDF8CE77CULL, 0x3E67A2CD3EAB4F0FULL
        },
        {
            0x6BB9ACA6BA75206DULL, 0x7508DE49DFD9039AULL, 0xD5C41AC3DCB46844ULL, 0x72208A1B8A13279BULL, 
            0x762410196D60A034ULL, 0xF752F532DB2F367DULL, 0x610A8F0969910B0AULL, 0x21247A06044F6D95ULL, 
            0x81D4C15ADE36BB11ULL, 0x70AE9B90C154E961ULL, 0x53FABDA989962979ULL, 0x83FB1210A8F13A80ULL, 
            0x16BC9A704F5669DCULL, 0x17E57AAD008C6E75ULL, 0x1F2A67253FE9FAA6ULL, 0x38E6C008301B990AULL, 
            0xCC572BBC0A7F23CFULL, 0x42AB822F547843DFULL, 0x002C0BD1695B5698ULL, 0xB8281300BE6FDE8BULL, 
            0x4C4D60EA03D5E29AULL, 0x4E3AB8E7FC0461ECULL, 0xBFD0F6A8BCE32541ULL, 0x2D13999377D84E85ULL, 
            0x0D41675455A6F46EULL, 0x97459B6C3A47AF34ULL, 0x3C95B3EB524765EAULL, 0x7A65C85F1F551A0DULL, 
            0x4EC147E1EFA56ED6ULL, 0x2F50DA67230E388FULL, 0x6680FEE2B43D5C1EULL, 0xF44774BC98A179CEULL
        }
    },
    {
        {
            0x8A9CCD5E071F2FE1ULL, 0x797836A4EAE11040ULL, 0x1360B81C12E758D9ULL, 0xE55C33F43D81CD7BULL, 
            0x3F5DC4AC2EF825F0ULL, 0x9CB74F2A23D865D7ULL, 0x77A347173E220284ULL, 0xD3553738C691BFEAULL, 
            0xFE16580933474DDAULL, 0x9AF923A0E2ABA74DULL, 0x66C49C3260345AA7ULL, 0xCD69E02FBD27EA89ULL, 
            0xDC2955EF6A37C4C6ULL, 0x13311E9C6AD22264ULL, 0x355855E0A0429170ULL, 0x7CB113425FF23857ULL, 
            0x339D282A69219DCAULL, 0x2FB7F480B8F9CB67ULL, 0x9BC1B4441D46E2A4ULL, 0xCDD520BECA77BF16ULL, 
            0xA56B549AF48C00DAULL, 0xC747CAF32B2EA16CULL, 0x5A7E7F445E65903EULL, 0x5853EDB866B9E523ULL, 
            0xF123CFBE3B74B5D9ULL, 0x336FA9437E072193ULL, 0xA577D1C0C89F5ED9ULL, 0xBF0F51C5EF4D91C3ULL, 
            0xE5FABD8F19492CB1ULL, 0xB109410D4763922DULL, 0xFED5A501F8448DB5ULL, 0x0F96EA7B7FB3E640ULL
        },
        {
            0x369A3A564C969223ULL, 0x4B489FF03A6F4011ULL, 0x051B6D382AC0F80BULL, 0x28DE14C12BE82088ULL, 
            0x5677E7E591AD1526ULL, 0xB8BC7D8A8932251FULL, 0x3E0533409BFF3675ULL, 0x52FEFCB31F5346B6ULL, 
            0x5ADABF583B9B7F03ULL, 0x958CDADE00045211ULL, 0x9F9C06302771B892ULL, 0x1C8FB4EF7346AD3DULL, 
            0xBA80C1C710CE0BA4ULL, 0x6CCEE29A8A1A9D31ULL, 0x4837D54260D5F1C4ULL, 0x7C453ECA6E7B3523ULL, 
            0x185CCB4533B0B305ULL, 0x4C6792ADFDBA1EF7ULL, 0x45FCD21903CF62EEULL, 0x6DFD25D188873A0DULL, 
            0xCC674CD40E38A18FULL, 0x6E0F8EA7E42B6D2AULL, 0x079009B9E79AB1D5ULL, 0xE5F6FABAB9234F2AULL, 
            0x057B013019BB9A7AULL, 0x858268067A85D185ULL, 0x60CCE895D917A481ULL, 0x677C0114B0E76FFCULL, 
            0x29CD287FDB175404ULL, 0xFC59FFD8B0C8F832ULL, 0xE9EE9D4AF26EF554ULL, 0x6018F7DABEF9DC0DULL
        },
        {
            0x4028961B46E2F47CULL, 0x82331AE505981297ULL, 0xFE5B326E3EBCF192ULL, 0x549A2E8E2E0D2C10ULL, 
            0x6F0321F25982C9E7ULL, 0x555CE4D01F73B131ULL, 0x3BBA7F3E53C59E12ULL, 0xB42D03508C341611ULL, 
            0x60E3FC22013069BEULL, 0x320B820A6E69A9A0ULL, 0x665A7A6920E6972CULL, 0x9827CE81031C9ADFULL, 
            0xEA27A670FC9A0308ULL, 0x54180EF584703684ULL, 0x751A8B392BA29924ULL, 0x9DB62B3884EB5580ULL, 
            0xC2976F8452DC230EULL, 0xEDB2D32BE88DBD41ULL, 0x957C295DD16D50C5ULL, 0xF0B816AFD9CB52E1ULL, 
            0x95C77D20536EB699ULL, 0x0EE789396B5ECF3BULL, 0xFF580ED21B38D303ULL, 0xB514641862F802DCULL, 
            0xC92B1A9D388DC637ULL, 0xF4DE1216850E605DULL, 0xE06C3300FA638B16ULL, 0x824743147E262E46ULL, 
            0xE18E33A5DB809662ULL, 0x54BFAB6E1B1E9C4BULL, 0x4407B870B3BEB83BULL, 0x477B6A3CA6082999ULL
        },
        {
            0x2091F60D8DFD4092ULL, 0x68112152C835C207ULL, 0x3073BA48F2B48AFAULL, 0x6E42282D113E489BULL, 
            0xD5D1316A3D10A39AULL, 0x85081EE6A98E6EC6ULL, 0xBC8A2C46782805C1ULL, 0x75CFE7B88107D2F0ULL, 
            0x0B99501106D50E88ULL, 0x93EBB6C7EDF751D7ULL, 0xD9EA91F289A625F5ULL, 0x054388C1D016AB85ULL, 
            0x0A911AB83F34C086ULL, 0x33328954B6DB63B0ULL, 0xD8304064FCAF3434ULL, 0xC99F82BA6E725C36ULL, 
            0x7B4C82101F636FCCULL, 0x882BFE16A3968D7AULL, 0x270A24FBC299E555ULL, 0xD6447E4DC7842BD6ULL, 
            0x38FDD1A9446354AEULL, 0x627FCEA8A452B854ULL, 0xE331B1A1A2F65976ULL, 0x07AC373D89249F86ULL, 
            0x7F1807C82281DE8CULL, 0xCC0EE7699F8E051AULL, 0xDE82FEC1BDBBA4E3ULL, 0xD41F15DC3357E770ULL, 
            0x6C2CB3418308A2C7ULL, 0xCA720FF1DCF10CEDULL, 0xFE97F5B260BAE4F3ULL, 0x12C07B725C6BC9E7ULL
        },
        {
            0xA11F24382EB3FC14ULL, 0xE260067786339115ULL, 0x6467D80C26295C8DULL, 0x0252EC14B984C4A0ULL, 
            0x25AD74C986C39539ULL, 0xFFE84FCB431E1DAEULL, 0x244388C07F283F3BULL, 0x77BCB9FBE9FAE42EULL, 
            0x56ECD24E383563D3ULL, 0x89CFE0ADF7BB60F4ULL, 0x7A6C5CF55C70659AULL, 0x4B08B2C9A30AACFDULL, 
            0xF6CFDBB941F75BC7ULL, 0x399705043AAB9A2EULL, 0x0FB8E69F0A8CD831ULL, 0xA9EE3CC393EFCB90ULL, 
            0xEFB231E74D70BCBFULL, 0x630C93D6635E8DD7ULL, 0xA8AF9A0211174535ULL, 0xCAA69B8F432330ACULL, 
            0x80EB4F7A5DA55F03ULL, 0x66E1EF837A1B3D80ULL, 0x2E442C373BD07208ULL, 0x46CFBB278AF252F3ULL, 
            0x151645B45998043AULL, 0xBC2307E8EED3B4AFULL, 0x84A7E8B16531E9A0ULL, 0xFAA8587C0E6A4CD8ULL, 
            0x05590D537265773CULL, 0x03A880BC94F0114AULL, 0xDAF45361B653654AULL, 0x71400CC77B47F644ULL
        },
        {
            0xB3DC5A4943981BFDULL, 0x241EB3173B30ABFCULL, 0x52107A45D0B93242ULL, 0x2422374DA891962AULL, 
            0xDE303D4CF7B5305AULL, 0x602941BF9E184836ULL, 0x946A5221D1FC8265ULL, 0x408DF3D90E7DB824ULL, 
            0x1F741E6D65A14986ULL, 0x686815505472474AULL, 0x46338BB95094C63FULL, 0x309B6EFC0E81C51CULL, 
            0xFC92C3ABBC8381EAULL, 0xD1BDDCC7BA35E54CULL, 0xA2F4CE086931F3A1ULL, 0x4E98ACC822E03B40ULL, 
            0xB0E0445E715C0533ULL, 0x7C7F47D4AD059ABDULL, 0xB4836480C8684A9FULL, 0xC8F880D1158139D7ULL, 
            0xA3A5C7A3975550DBULL, 0x6DA63EDA1388E138ULL, 0x97EDED6FEA860CC5ULL, 0xB81685543F62B3B4ULL, 
            0x7BB73372437D9432ULL, 0x193C3C71F2B6403BULL, 0x2F1C782770C3D0ADULL, 0x93E436F4A90CB3D6ULL, 
            0x26B7ADD728F1F0DCULL, 0x8705D5433A70CBB4ULL, 0x118A788C83725B58ULL, 0x3D634FD50C1CCCFEULL
        }
    },
    {
        {
            0xDDEB28773234760EULL, 0x3E56CD5CF4EE814BULL, 0x78248ED6A641F8F1ULL, 0xCF67043EB33FB1A8ULL, 
            0x17639F0DBF815F0AULL, 0xCFAFA8199691D6FAULL, 0xFB0C7E82D0AE73D7ULL, 0x74605AB1DB1E0032ULL, 
            0x5889D34BDA8542DAULL, 0x8F31A2906A25D02AULL, 0xF777D38E4D1AB261ULL, 0xDF5B9F484E0603BCULL, 
            0x7D54F6BA2A230D89ULL, 0xB0871AF530D27E8FULL, 0xA4E62BD2F70419A5ULL, 0x5C79FD8DC6534F2FULL, 
            0x7B39BBFB007DDD4FULL, 0xFC5DEF1FDD28971FULL, 0x74E410B610310BF9ULL, 0x150D804963DB8E29ULL, 
            0x0B9D91D8921CD485ULL, 0x5980FA1B4A76690EULL, 0x65D903BA60EC7FFEULL, 0xA6B156CFB4D13C13ULL, 
            0xB094187F1A6C664BULL, 0x2F1E5AED0D651974ULL, 0xFF20DF34E3636D5FULL, 0x3DBB692CBEEE200FULL, 
            0x0B841F2EB4475103ULL, 0xAF032C28B00C6320ULL, 0xB2808B22D0D86DF6ULL, 0x5C1CD188181D1117ULL
        },
        {
            0xB582E8471E181A6DULL, 0x90D7002849C0343BULL, 0x3F8C48B0FC29974FULL, 0x869894D6521A1579ULL, 
            0xC2D648B0F7532DCDULL, 0x4E11F4A620154D92ULL, 0xED5DA191BC887800ULL, 0x6A6CB8061EB8D78AULL, 
            0x3BB930D897F80EA7ULL, 0x3275E810D102ED14ULL, 0x9FEECE82A007A1D5ULL, 0x07E97B294DFA615DULL, 
            0x8D8D392ECDF9960FULL, 0xBECF57D7F6CE7656ULL, 0xD1235F44917F547AULL, 0x85D449F236973508ULL, 
            0x8463643EBF4F0AF5ULL, 0x00D9ACFBD225F7BEULL, 0xD6EBDFD1B006C213ULL, 0x85A4E3F78B88F7F3ULL, 
            0xD1753471DA03D85DULL, 0xD8549DA4500857BCULL, 0xD18025373CCFF854ULL, 0xC0F97E99601CBC6FULL, 
            0x2061A19B01806B14ULL, 0x603D4E5CC7398AE9ULL, 0x306E47A98FA797C0ULL, 0x268D30E1DACC8CE9ULL, 
            0x8FAB53EB22A5E3D3ULL, 0x8DDB2A2536DBE0B0ULL, 0x8B329B1F00E487D6ULL, 0xF7CA08CE80C557E8ULL
        },
        {
            0xB3E334F70C47C9B6ULL, 0xBCCFAB8345D0505BULL, 0xD5CF5C0F3D0B2A03ULL, 0x7CE0A9029F8FB1BAULL, 
            0x8219A87C31A9DD47ULL, 0xF4D123F4F89598F3ULL, 0x87C28FC0CD220D1BULL, 0x59FAD80929525756ULL, 
            0x95DCCC5E2FBFEEAEULL, 0xDC049CA3D7EFD349ULL, 0xCCB2A713EEB3A61FULL, 0x1CC8EE6C24DD13E1ULL, 
            0xF0D39D6EBA5D485DULL, 0x347AE39370A9BE3DULL, 0x7C7929C7B22CCE7DULL, 0xBAA161C7605205F7ULL, 
            0xC55489A23F5EE9E4ULL, 0xA62B9BB314F84080ULL, 0x258D953EB6D38734ULL, 0x20BBDCAEB7358205ULL, 
            0x2FB47D852BE8FA57ULL, 0xD1A8CC79D6C4FBD6ULL, 0xDBFE1F37421E2098ULL, 0x06317B4BBC6F437AULL, 
            0xDD75CDCE748F77F6ULL, 0x881209E1A69E7E38ULL, 0x5F207DFE3FF868CDULL, 0xA0062BB749AAF3E6ULL, 
            0x0DF66EACAD89EE84ULL, 0xBE694E7079B4DDF7ULL, 0x665A9040CAE5CCDBULL, 0x2C66DAD0F9B0DA36ULL
        },
        {
            0x3CFC5C1AB8DCAA8DULL, 0x4D0B94227C566BD9ULL, 0xEB6BCE2B1FDE2FD7ULL, 0xE58DF056E26169AFULL, 
            0x904FEC1F61EE4C46ULL, 0x27D7A0B3806CBCD5ULL, 0x88538DCFE856AC71ULL, 0xD36D13D4A07E55B2ULL, 
            0x8FB7A4C6C28FF356ULL, 0xD8F87E96D2840FAEULL, 0xD5F6220578BB519FULL, 0x8621E563D16727E1ULL, 
            0xC209CB220AD795B0ULL, 0xA0BD915395BE17BAULL, 0xF58608B9B3B28C19ULL, 0x4BD3E3E95CF6C47AULL, 
            0x4E158B208593C917ULL, 0x7E7479F4C1F6A80AULL, 0x25FB6C1C1C39B285ULL, 0xB82064DED0593BE8ULL, 
            0x8ACE9AC54EF68F75ULL, 0xB87D791C3A6184FCULL, 0x87A9CE40EAAE1E7AULL, 0x5C515822C6DB91B8ULL, 
            0x7C31CB10D75CAC8BULL, 0x838FEAA2CB07F0A0ULL, 0xE06194C2686B0C6DULL, 0x4365647A833B904BULL, 
            0xD9EEC4DECC8CC7FDULL, 0x21E1BFE26893E940ULL, 0x90D5E8BAC39D971FULL, 0xEFAFB850F82AE8D5ULL
        },
        {
            0x82BE1FA89D79BF4EULL, 0x93BFDEF93C6258DFULL, 0x77AC4B7722332074ULL, 0xF4A1AC9DBCDC7CFEULL, 
            0x342BFF3F83CB9AE9ULL, 0x84D30031A6BA98DCULL, 0x7EAD6D17732A9BB7ULL, 0x868D43CF1CF816B9ULL, 
            0x44B25BCCCD5C240AULL, 0x361B70DDA7FC32F7ULL, 0xC84AF45B5AA9F69BULL, 0xB9008C4D8406795BULL, 
            0xFD57AD48E9A09C27ULL, 0xF3E1B98CD0421C57ULL, 0x0BBC50CAB5AE99C5ULL, 0xC1EB04CC85CFA1B1ULL, 
            0x2F188E0D1937271EULL, 0x337EF1F354AB5BAEULL, 0xE1BBFBE37F6E5B11ULL, 0x69F8502E8770F816ULL, 
            0x44BAD9B7F7465951ULL, 0xA88B81DA6BA522C6ULL, 0x7C0C38D9D252E5F7ULL, 0x6444503CC52A6D66ULL, 
            0x16D009875E9F1D93ULL, 0xCCEEBB60DBDA30E0ULL, 0x0C70B459281E57B3ULL, 0x371F1BD01043CB7AULL, 
            0x7DC2B7E027BD3D7AULL, 0x211A2B7C4B44C7D6ULL, 0x4DE347F2716251B9ULL, 0x610264050CD06189ULL
        },
        {
            0xCA0B2D99A793B6EBULL, 0x694F6972FC8FBB9EULL, 0xB9359D2B83CFFE9AULL, 0x0F49CD6FA33F322DULL, 
            0x99C20382AFDBB70BULL, 0xCCA51F3D5563EA2AULL, 0x826F0905ABDE0650ULL, 0x58CAF4957C312273ULL, 
            0x9EDD6CCA89C4EC83ULL, 0x2D4B6022BAB009BCULL, 0x088CB3C0E3009274ULL, 0x162270035E318046ULL, 
            0x2C4743D3131A6758ULL, 0xB0A29E6A7E72E3AAULL, 0x76BB9E9476C95060ULL, 0x222D686F2B87A220ULL, 
            0x886A70CC556061F8ULL, 0x1C01E3E0BA074286ULL, 0xCBE42C8BD1D72379ULL, 0xD8CEE6009DDC6E2BULL, 
            0x06FE7B3A148E0675ULL, 0x0C8F50FF162B84B3ULL, 0x15848DF687F3D469ULL, 0x32EBE071E73063ACULL, 
            0x1403E4C6D419367FULL, 0x69A58983CF2E92CBULL, 0xC378AA402C83624AULL, 0x0782DA9616B028E3ULL, 
            0xB80C80EB41844425ULL, 0xAEAA88273D20FBECULL, 0xF77966EB51A5FA62ULL, 0x1CF5AE9B899F7F66ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseCConstants = {
    0xBE4F1CEE7D3E7F22ULL,
    0x74B3F0CD8C240A97ULL,
    0x5B19C8143B06C6DCULL,
    0xBE4F1CEE7D3E7F22ULL,
    0x74B3F0CD8C240A97ULL,
    0x5B19C8143B06C6DCULL,
    0xEB6CBB5E17BD270AULL,
    0xB00D251C5D97232AULL,
    0x32,
    0x13,
    0xD8,
    0x89,
    0x22,
    0xDC,
    0xEF,
    0x35
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseDSalts = {
    {
        {
            0x81528AB4823E2D8EULL, 0xA438D8D6F4BE5F34ULL, 0xF8FFA5DC47EB3E05ULL, 0x754A82DE3C8F709CULL, 
            0x431203AC5DFB5698ULL, 0xEB0C74F6A0515368ULL, 0x74A1731A418D7A04ULL, 0x0C26E0198E3FFEFFULL, 
            0xEFC4DD79C2BA917FULL, 0x8E0EB2FC636DF60FULL, 0x12123F55064F0160ULL, 0xFE4EB829011265F8ULL, 
            0xD5FCC9A371763385ULL, 0x2AA303062FDA1188ULL, 0x8C652ED6C2150AB8ULL, 0x25AE3EEE4950421CULL, 
            0xDB259F0903450705ULL, 0xB342BE8F87102B3FULL, 0x04D4364701857AE7ULL, 0xBA03B2EEB9EDF926ULL, 
            0x2583360000CF1085ULL, 0x443B1A4F7B69A555ULL, 0xEC5D04609FA89C73ULL, 0xED0FADE7ECBDAD2EULL, 
            0xC74F0DD0288ED553ULL, 0xABF585D3D011CBA0ULL, 0x0C9B34DEB72501ADULL, 0x6BC24508C52C54FDULL, 
            0x6F0008EAD1616D91ULL, 0x2E192CF0B46FBC34ULL, 0xE95C6073772D2F5CULL, 0x7027B57BB9F7E49FULL
        },
        {
            0xCAE597FF6CF3100AULL, 0x7761D94801A00BD2ULL, 0xC90AD3BFE1675C8AULL, 0xCB6712D7F8005B8CULL, 
            0xD8AAE798F73E1450ULL, 0xE0837EC3427555B2ULL, 0x51D0A0AE5DA7A262ULL, 0x5F01892AAFED67B4ULL, 
            0x4416E1FAF33132E7ULL, 0x2FAAEEAD1A2F0995ULL, 0x8E1E244C59084635ULL, 0x1EEE6BAD31D44981ULL, 
            0xC94DC13B4BCDBF6AULL, 0x1E6CFC5AE63E7E1DULL, 0x776CB9403F5572BAULL, 0x4E17AC3D9C2E9328ULL, 
            0xC0BB190E9C7CF0A1ULL, 0x809391CB71357E38ULL, 0x67E487576E08DC4EULL, 0x7ED4A3E9A64BCA26ULL, 
            0x6E76FBB62EFD9E1AULL, 0xB5E95B07332A6964ULL, 0x4DC880BB34F125A4ULL, 0xAD1D6CE00856FF73ULL, 
            0xB18DBD1E3D421FDAULL, 0xA47832222A2DE294ULL, 0x3A07E5C382396540ULL, 0x917252E899115F72ULL, 
            0x179252B95D0F45FFULL, 0x8BEF4DB3472ADEB1ULL, 0x5C146DE6932AF667ULL, 0xE4DE392CAF9092AAULL
        },
        {
            0x8601EBD5D364BD20ULL, 0x9EAA3548C0AAC54EULL, 0x7B356B57693CF396ULL, 0xAC1CA79045CECE05ULL, 
            0x5B95874A35B7B781ULL, 0x102B08A8115DBC75ULL, 0xF76DB4D04C234528ULL, 0xE22560B555D9FB6AULL, 
            0x32C2B56999F49C5BULL, 0x6B69EA3E70E78870ULL, 0x2F4282D8CE9C5FC6ULL, 0xC69020C0C6D33953ULL, 
            0x7B072565C89752DBULL, 0xA2BB5FB56B9AFE31ULL, 0xBF511F1B2B7A35F5ULL, 0xC5D0C3265433AE5DULL, 
            0x3E669DF32F8A4C1CULL, 0x047B4EAF802CE8D4ULL, 0x557F322C60E0E6F1ULL, 0x914A6C8EB97D98A3ULL, 
            0xA17ADF410F341F0BULL, 0x8EC6E02DB563ED65ULL, 0x3EFE03A8D157FE0BULL, 0x0386A171A084F9C7ULL, 
            0x3B866DB77C22281AULL, 0xB671D2F82B1E5408ULL, 0x0DAE5FD593FA8D0DULL, 0x10AFB433B89A2781ULL, 
            0xC939AC5D416C0E7AULL, 0x7A4FBBFFF691E0EFULL, 0xA1A9CEBCE987EEC1ULL, 0x400191E87D1C954BULL
        },
        {
            0xD9B995E8364AE546ULL, 0x9E794CCEABF399E2ULL, 0xE3D6AE7DB3F9025EULL, 0x871462157303BEBEULL, 
            0x5635124E5E2156B6ULL, 0xF96D522825779029ULL, 0x39BB9E8221F85AD8ULL, 0xEE956013CF73D985ULL, 
            0x87B8143529A28C4BULL, 0x43EBE233530EFB02ULL, 0xB7C4A63C1B8C80FAULL, 0xC529460021A3EB13ULL, 
            0x2EF895F331AB3833ULL, 0xE18C24907DAD4609ULL, 0x6C611CCEAABB3F64ULL, 0xB0C608A35FAAEDBDULL, 
            0x25E3A6A44FACD1B3ULL, 0x7BB04C7586C87CE1ULL, 0x951EF077A0C2A3B0ULL, 0x19E8784CFD3EA34CULL, 
            0xDE9B12C163A5C45BULL, 0x600C853B030A5548ULL, 0xEF1CE7C810BF8816ULL, 0x8F1C28FB8D490169ULL, 
            0x9A5363550605C8EAULL, 0xC8E36981FEFA47C1ULL, 0xE1752DA700961A6EULL, 0xC87C3167E5A3446AULL, 
            0xBD3FA2312B535889ULL, 0xBD622C2969B38436ULL, 0x31C8CF7CA446B202ULL, 0xAB96697984362D55ULL
        },
        {
            0x308B1878F39F7203ULL, 0x1F1DF32F60327BF6ULL, 0x833B4145C376D547ULL, 0x529B9D8DC76D9010ULL, 
            0xC3E7571DDF88A06BULL, 0xC10C266AF774A604ULL, 0x2A0BF17DDE69135FULL, 0x99B5C6FF41770060ULL, 
            0x54CF4CC12AEF10CEULL, 0x89D8B8634CDF2213ULL, 0x6CECB85CAAADC637ULL, 0xEDF5F087671A4DA7ULL, 
            0x33B8918A0437D601ULL, 0xDFDAB71405D61061ULL, 0x9492BCD4F8360352ULL, 0xEC80C44E698516E5ULL, 
            0x8CE075AF93726C6CULL, 0x889F6D4F3B28335AULL, 0x39B53780EBD804BEULL, 0xBEF61BC603B6B7BBULL, 
            0x1B6871E071342A4DULL, 0xAB54FD5307188D1DULL, 0x66ED0E62105EA068ULL, 0x0CCDDEA25910D8C8ULL, 
            0x94785A14318F9851ULL, 0xA906D6B230C07FE5ULL, 0x900DF037C8AEA4C0ULL, 0x9F888A5D80884F03ULL, 
            0xC79359B572B7BADEULL, 0x28C3646114CD7ACFULL, 0xAFB647B4CB7E28A2ULL, 0xB6060F674AB67D14ULL
        },
        {
            0xD96D1709623BF2ECULL, 0x0C23B1DC24AF33E0ULL, 0x1B3DB9B81DF523DBULL, 0xC053E49388959FBCULL, 
            0x8819131E46C64B87ULL, 0xF6016F823C23CFF4ULL, 0x7E1FA6835A6E627EULL, 0x9C0C177402548776ULL, 
            0x4A04E4F0A9D2BE02ULL, 0x114FCE3BB548F861ULL, 0x3BE1765ED29CC6DDULL, 0xE4027DF605BA0D0CULL, 
            0xC3184FDB81093D55ULL, 0x53B54A16855578E1ULL, 0x981E7D99C6BA9696ULL, 0xB1BD85FBDFB78A13ULL, 
            0xDF5F5D399BA6C4CEULL, 0x54EB216CCBF0A537ULL, 0x64A0061CC62E2E98ULL, 0x670F2182660030D7ULL, 
            0x5719F9746EEA9AD7ULL, 0x8069ACF3B85B3336ULL, 0x909EC737C090F04CULL, 0x9653B7AE5F2B9257ULL, 
            0x41AC0905666B66CBULL, 0x1F01942DBE2C116FULL, 0xF7DBD747961E9C90ULL, 0x62D927258D5802C1ULL, 
            0x89D901156B8DF2C4ULL, 0x3EB121FFA730A54DULL, 0xEC199724D2EF6BA4ULL, 0x807A00F6B572D30CULL
        }
    },
    {
        {
            0xEF0B35A200FAFC54ULL, 0x2CD5D96C171E38EEULL, 0xC5BB276E8F8E4473ULL, 0xB4E4B2060C4CB975ULL, 
            0xFBD4C2D41C850721ULL, 0x4DE0E9E41B21AE22ULL, 0x2F86B110EE5902BFULL, 0x56BAA3E07CFC1572ULL, 
            0x0F1FD6A7989F67E9ULL, 0x4CE39224C1BADFF4ULL, 0x1837D6288B12EB80ULL, 0xC77B2FEDFACE0A9FULL, 
            0x28F13B58D39A960FULL, 0xB2901A3153E00E7FULL, 0xCAE97D5EE9A029D3ULL, 0xB1D4725F63BC1D8EULL, 
            0x25E74415E66F4081ULL, 0x588F1C85EB8F5FD5ULL, 0x16D0A3A67F1E945AULL, 0x35338EE4E5070482ULL, 
            0xA75446A8EB77C037ULL, 0x852F9FA57B5C53FAULL, 0x4C14ED534F614A23ULL, 0x2D7CEE914214FE67ULL, 
            0x7FF2E598084E4DA1ULL, 0x82E68A147BBFAE13ULL, 0x54C9CAAB70ED71BEULL, 0x9A32F14B008DE132ULL, 
            0xBDB95C0E390EB6A6ULL, 0x80FA4A34AA632BC9ULL, 0x1613873723709F74ULL, 0x352D567DF09CB59CULL
        },
        {
            0xA15AB4061BFFEB04ULL, 0x863AA324B4660C07ULL, 0x8470234B9BEB71E2ULL, 0x80B24010369FAC38ULL, 
            0x50514A060A306BCCULL, 0x85A7BD7C08ECC265ULL, 0xDBC30F88328F5F2FULL, 0x352582C1C1946110ULL, 
            0xA437FEB432CCFFC6ULL, 0x7C6595A7B2A69448ULL, 0x3E6E3E7220CED6CFULL, 0x76C35F5809AC8136ULL, 
            0x2EA4D9ACFD46C171ULL, 0x371171F3E552BE6EULL, 0xF59725A98D736A09ULL, 0x88AE20739A0ED004ULL, 
            0x87DCF2261BEFB756ULL, 0x294A5E3356DE07A0ULL, 0x95908A86C755D0A8ULL, 0xB7690626A3E0CEF1ULL, 
            0xC51DCBFD98DB647BULL, 0xA1DE7BEA2F924974ULL, 0x4B471B55C2D1E416ULL, 0x7BE16F2164DDD693ULL, 
            0xF7AB06932568816DULL, 0x0BF31423E0C1CF71ULL, 0x1CEFA6DEBE55EDD5ULL, 0x2435E8091541EDD6ULL, 
            0x7C77A531094B6518ULL, 0x7389395E6D9D363DULL, 0xDCF43180ABEB21A5ULL, 0xCC164BA15FC71945ULL
        },
        {
            0xFC1AF3E7476755BFULL, 0xE3C3009B72F50A01ULL, 0xECA7EC6F2E2F571BULL, 0x707FB1CD90A6BBF8ULL, 
            0x6FE0830E7B01E255ULL, 0x1026F25281EBC6CEULL, 0x1A7C39E1DD80BB0FULL, 0x3B9BCD502754C4D9ULL, 
            0xC8CA69A0E58BD7CDULL, 0x07CBB165AA00F01AULL, 0xDC2CA0EDC680DF8CULL, 0xEB29D9CAA9E1D4C2ULL, 
            0xF31045B3A44C0A5DULL, 0x34627B7C8526FB52ULL, 0xD92F323DEDEF2E39ULL, 0x6D10BECF44C2A51BULL, 
            0xB3BE6DDBD53196CEULL, 0x6A9307EF5E3A127BULL, 0xEA35914BDD266DCCULL, 0xF7C7B926537E5AE0ULL, 
            0xCABF84D85B9FC149ULL, 0xA2DA192F9C6474C7ULL, 0xAB6C8FE6A4628453ULL, 0x493D5A5FB18CB0C3ULL, 
            0x86F709E55BC06853ULL, 0x2B7523C93DAD7FEFULL, 0x17AB16ED5C387511ULL, 0x91910DED31D613F5ULL, 
            0xAFDCEEA7379A4D94ULL, 0x57D875002A2564ACULL, 0xD91F998143DB9D6CULL, 0x57A73077D6280AC9ULL
        },
        {
            0xD509505BD487560AULL, 0x33514AB4CEB95F93ULL, 0x754FE1540EF5CBF2ULL, 0x9FCC90B3E605EF71ULL, 
            0xE0D9818D213DCCEAULL, 0xE51BBB191342E25DULL, 0x6FE86589072FC8F7ULL, 0xD5AC394B3B5405DDULL, 
            0xBBB6C6A2076B3C26ULL, 0xD56149D11547B6A1ULL, 0xCF731A3FC5457B49ULL, 0xD58A1DD12CBC4102ULL, 
            0x25F191747A250AFEULL, 0x7C282F9FC2A16E7FULL, 0x051453066DBE22EAULL, 0xED8D7AD8467BA849ULL, 
            0xA85DB3FF7000DA70ULL, 0xCCC7E32325AD420DULL, 0x5325032FDFD34901ULL, 0xE2A134C5CB372419ULL, 
            0x9BFDEC7EEBBE6077ULL, 0x753C54B4FE3565DCULL, 0x1986427CCD5DD6CEULL, 0x75F56C2DA9734549ULL, 
            0x2B4A2AA01BEAE58DULL, 0xA5A2601B1793697AULL, 0x994A546133FBB604ULL, 0x128F1094E04745FEULL, 
            0x011B8CE6DF66A2EBULL, 0xBE10BAFEB5500EFCULL, 0x25D1EAA4A70D3E71ULL, 0xFBF547FD4E197A76ULL
        },
        {
            0x312F279A69719594ULL, 0x6FBDBCCD01EB9157ULL, 0x7D48659399F68F2EULL, 0xCEFE9BD6C3277E7DULL, 
            0xC1D91F267B6D1C13ULL, 0x134D0C8E35D1834CULL, 0x29F3B81C1915DCEFULL, 0xF88B06F485187A80ULL, 
            0x30C7F4EA4B6E8C1FULL, 0x14DFE80993954864ULL, 0x8210AAFE67E1B408ULL, 0xF1960A6352CDC0EFULL, 
            0x1120680396A4AC6BULL, 0x8D0F8AD4D376AA34ULL, 0xC4F1E3462D92DE51ULL, 0x1BF6E697F15C7F69ULL, 
            0x6CC845A8B10682DDULL, 0x31A1D9519369A007ULL, 0xA9B1AD1D7846FD7AULL, 0x73BF3004204AE30BULL, 
            0x88CB5ED2B2EA823FULL, 0x6D9BCEFF82019FBEULL, 0xEE4BC9BCC905BF1DULL, 0x022982A0C031CC5CULL, 
            0xD1C2B3C28264D889ULL, 0x8ED9B9A5814FA1BDULL, 0xEBE4A628A87F0502ULL, 0x38297422D375490EULL, 
            0x2BAFC591D5CB71B2ULL, 0x7508C3C0A2F1AD98ULL, 0x235DC00D6055B2B7ULL, 0x3EEB16977E052EA1ULL
        },
        {
            0x6CDA718BA008E778ULL, 0x7DB94F4FA8F776D8ULL, 0x65D6A24ADB4F6F31ULL, 0xAA024F38AB079F25ULL, 
            0x2CF25A5A3FF47505ULL, 0x8301783AF3BC08DFULL, 0x6B3A6D346400D965ULL, 0xED52F7BF8DCAC189ULL, 
            0x1D538CFED53B20D0ULL, 0x9C4A122DBB5DBD66ULL, 0x16255CBE6DA2F9C5ULL, 0x0AFD3CF8F476E021ULL, 
            0x77D7BA92BE73735EULL, 0x4084789F24096CA0ULL, 0x7FE3EF17FA178CA2ULL, 0x665F394E4917ACC7ULL, 
            0xACCA2A131057854CULL, 0xEE00A19395EB6E1AULL, 0xD7B2051468417B25ULL, 0x733223B58D5CCF58ULL, 
            0x948480639B27DC6DULL, 0x7E8158A4EFC616BCULL, 0x17BEB172140A8FF6ULL, 0x0FC3333E1330DD6DULL, 
            0x183448DC07316F61ULL, 0x0F49BAD44C1DCB22ULL, 0x48CC99021C1174C5ULL, 0x36AC33A4BB2E4B32ULL, 
            0xFC12592A8B13FC36ULL, 0x418884742E26F918ULL, 0xCE4006560173AC7DULL, 0x8314E5D60EA718C7ULL
        }
    },
    {
        {
            0x01ED9733AB357D72ULL, 0x9466150BE7A1F467ULL, 0xB169A6F18A83576EULL, 0xC7499730BC94E232ULL, 
            0xD622459E52443DF5ULL, 0x38513E58667023C1ULL, 0x08715FDE91E14564ULL, 0xA18B3734930E1123ULL, 
            0x7513B921097B3D2BULL, 0xA6E37A3EF07958D8ULL, 0x618AA93FF0C49B17ULL, 0x513B0720734312D8ULL, 
            0x0711B2B1B2CA641DULL, 0xB2933AF70A8872B2ULL, 0x7B5FD7AEF94CCDC9ULL, 0x810497EB88E9C3E9ULL, 
            0xBB39C8F4A8776570ULL, 0x667A302DC59F8B0AULL, 0x424FC361FEB2A1C9ULL, 0x2948E34FBEF36189ULL, 
            0xA4F96B9E47B650E1ULL, 0x29716F709E6702F2ULL, 0x15542ECBE708F5FEULL, 0xFE038FC2D3A98AB9ULL, 
            0xDDE79AAD8441F811ULL, 0xC6C22C6D7359DCCBULL, 0x32036140FC4495FCULL, 0xEEFEB55697B19AB6ULL, 
            0xE99C6BADE7A2DD55ULL, 0xE227597E873CE119ULL, 0xEC3D17C9729D096BULL, 0xE72447CC290BF3F3ULL
        },
        {
            0x27761AA24D5D02FDULL, 0x03F5D52FECD42F8DULL, 0x177BC62124F44BFEULL, 0xB6ACEED3AF89DB1DULL, 
            0x04EDF19DC0F80BB4ULL, 0xBD9A4D65AD6608ADULL, 0x6F1E790B6BC1CBF8ULL, 0x9571586BEC90E966ULL, 
            0xDFA8E16014C59DE3ULL, 0xF33D00C2AF05F650ULL, 0x188398F235D012CCULL, 0xF2A6410E607403DAULL, 
            0xA6F715B0BE26A5DAULL, 0x5B2BC600A6117916ULL, 0x17ABAAB8E2459560ULL, 0x363F9C410F1FBB66ULL, 
            0x0025AB89C167E76FULL, 0x5E0290C2812550DFULL, 0x14E14787CBD81E06ULL, 0x343C59388D72384FULL, 
            0xFFCDFD255BD2E481ULL, 0xFF947A7B85E92ED9ULL, 0xABAB74ADC03395F1ULL, 0x42C3F7613E34D748ULL, 
            0x89258567F261545CULL, 0x7D89B25F11E70E25ULL, 0xBAFE164C885DA5C9ULL, 0x669DCCD2F1D21986ULL, 
            0x4D2E25C5E6EBA601ULL, 0x9883A8E91179970CULL, 0xFDC96C3F1D9C7847ULL, 0x3401A126055E83ABULL
        },
        {
            0x5EC436078BFB9A02ULL, 0x33A923D7FF22DCA3ULL, 0x4A2C2CABA90901C2ULL, 0x59456ED7FB81164EULL, 
            0xCB24159C7E381CBDULL, 0xD93247FC52F54A26ULL, 0x3A35F8871E754838ULL, 0x0CD12451EED4AF0FULL, 
            0xD447A8278AF0DFB8ULL, 0x0D7455451A56A99CULL, 0xABAAA27C7FB02114ULL, 0xF6F4F4A492762C18ULL, 
            0x670343F2DA1B2CE3ULL, 0x170E17D02EBCDCF5ULL, 0x3ED4A0B6DF799151ULL, 0x0F8E44E9187E6E50ULL, 
            0x88BDD976AA283D34ULL, 0xE334BF3035ABFE73ULL, 0x92C4168992B0F4FEULL, 0x175075B536C318E5ULL, 
            0xDF6E8B02DD19AF11ULL, 0x252A218F515F862FULL, 0xB0E8C5F0B19C82ABULL, 0x311BEF5A5AE3141FULL, 
            0xBCEF1A0F798E8A3CULL, 0x500D8352BE77562CULL, 0x7B71FE027A7AADB5ULL, 0x46D92A103A513248ULL, 
            0xA2C07A7C217C46A0ULL, 0x2247DD65EDBBD79EULL, 0x33152B8E7BA5A026ULL, 0xA85039B2319D8B39ULL
        },
        {
            0xC93576840409C719ULL, 0x4213D3281F56138EULL, 0xA42CA7B8CCCBC71EULL, 0x9E4DD3B1576BE4FBULL, 
            0x062714B82D8220CDULL, 0xB32438471713EC91ULL, 0x4019B99899644ACFULL, 0x32416DA5162DCF05ULL, 
            0x8DB37CB00CE464E9ULL, 0x2A26D8216BF54AAFULL, 0xF9F07DD01813CCEBULL, 0x688BB5E86FBDA02BULL, 
            0x3E38F842A183ED34ULL, 0x59A0B50DAAF77654ULL, 0x4C8AAB4A760B28D4ULL, 0x759CCD93AF881926ULL, 
            0x957FAD794EFEDF0FULL, 0x5234A60835BAAB0DULL, 0x620AEB2C33D7C402ULL, 0x7231A20550C1177AULL, 
            0x386B9ABCD6D39800ULL, 0x43A734B6E9D2EC6BULL, 0x82A7AC8EC07798ABULL, 0xA3D6B294B4A00615ULL, 
            0x535C1BFB4D2E63D2ULL, 0x4524A0FC9E418AD8ULL, 0x861EBDBB567B72FCULL, 0x2BABA0E9BEE56014ULL, 
            0xE182961F57517276ULL, 0x5D8E20161DFE9BDBULL, 0x895894FB28BD965AULL, 0x7A7D06AB48A888DCULL
        },
        {
            0x8E0A9210DD1A0032ULL, 0x10297ECAA8E45DD0ULL, 0x4C6526E4098347BDULL, 0xC9972993CF104DD7ULL, 
            0x9FC777DD808F84B5ULL, 0x84F7A0AB18C93503ULL, 0x970045303DCF7774ULL, 0xC0AD3578EEC94FC2ULL, 
            0x280B9E95DF32F7FDULL, 0x1552EEE005A081C7ULL, 0xC54A853FA004AF97ULL, 0x14B711C2B8005F21ULL, 
            0x927FDF5B40BE1F64ULL, 0x2CB1AA7B9E488D28ULL, 0x5DC41060405766D6ULL, 0x88361FC39AB8A150ULL, 
            0xCC128996FDF39FF4ULL, 0x1AAD2D4883A3931AULL, 0x76A83154CFEEF5D4ULL, 0x6ACB9A256BB75867ULL, 
            0x0F52D614532D245BULL, 0xE482051C724F399EULL, 0xBA930765C526DA70ULL, 0xCD11BB341F05FAEDULL, 
            0x9A607E54E37E3F0CULL, 0xBA2B365ABE17188AULL, 0x5121128D0D86447EULL, 0x44A3FB7FB62DEB9FULL, 
            0xD32EAFC388A1300EULL, 0x42CDA8DA0DE73777ULL, 0x38D725AEDCEB85F5ULL, 0xCC7A187BA0E5D6D1ULL
        },
        {
            0x08F401007D8CFAC6ULL, 0xB521F489C88B06F4ULL, 0xBA40328E9B8ADEE5ULL, 0xCB4BB871FEF5FA7EULL, 
            0x19AD8B0D37D030EBULL, 0x4405F4C2D4693D6AULL, 0xA8B62774FCFD4A5EULL, 0xD2ADC8E71591FF09ULL, 
            0x925A2D132CEF8F41ULL, 0xBB77BD1A5418A906ULL, 0xF87F303B2A598ADDULL, 0x72A2278D0E27A580ULL, 
            0x5CE211E910FA51BEULL, 0xD5B5EF4CA9F3EB25ULL, 0xE0D12DB3E2D8FFB4ULL, 0x814EEB994000F392ULL, 
            0x8718634AD333FADAULL, 0xAE3B12F75C2C4241ULL, 0xD5F0370846F2C9B4ULL, 0x47B51F1C5EAE946FULL, 
            0x9E1B92E28836C200ULL, 0xC45E5C4AD1126892ULL, 0x11A1549380B3252CULL, 0xDE8E8B1FB219C572ULL, 
            0xD1669F28F87AADDAULL, 0x11E6AD7B3222E77FULL, 0xA69E561411067992ULL, 0x96C994FB36A8E79DULL, 
            0x723A0DCC660CDB73ULL, 0xF3568DDB47530517ULL, 0xC686479CDBBCC8CEULL, 0x422DF4AA50D211CCULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseDConstants = {
    0xBAF0861E70D6BD91ULL,
    0x38A06148EC3B346EULL,
    0xD72C602C64ECBDE3ULL,
    0xBAF0861E70D6BD91ULL,
    0x38A06148EC3B346EULL,
    0xD72C602C64ECBDE3ULL,
    0x94D3E8929091BF2AULL,
    0x35024AF0046DBAD2ULL,
    0x1D,
    0xF8,
    0x6D,
    0x74,
    0xDE,
    0xA0,
    0xB2,
    0x93
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseESalts = {
    {
        {
            0x0DF1A05C946459F2ULL, 0x99550EB4119CF4C1ULL, 0xC8A21FD7FC92DB09ULL, 0x76D3E15743B7C6F9ULL, 
            0x2156014D410C9095ULL, 0x9650807E9BFFC4E3ULL, 0x1688E989831CD7FCULL, 0xA1F8005F5D663358ULL, 
            0xBDDD9A00129BEE08ULL, 0x73C6E77960C2D56EULL, 0xB278A43E44E1AAB2ULL, 0xEEA01E3E0D78F1ABULL, 
            0x745D3A758FA0C836ULL, 0x51F50ED680196641ULL, 0xAACF83BE967C865FULL, 0x8D16E64C839FA616ULL, 
            0x5E70208A81AA03FCULL, 0x275A02A8F0E407EEULL, 0x8180ACA63D3CDACFULL, 0x39D33A3BF22DB582ULL, 
            0x6C8F905C62F86F09ULL, 0xC18ADBE8EDA7DE98ULL, 0x37098A8A26AF7C2DULL, 0xB24F903909299D4CULL, 
            0x4B004E9BA1A69842ULL, 0x437DDE50C5448E0DULL, 0x1D9CCFF63CD888ADULL, 0xF280660E72113F3AULL, 
            0xC9D40AC9548C8F57ULL, 0x8EB8BD9E3C6F8460ULL, 0x8A8316F6796C8EA1ULL, 0xF234973F4B198B3CULL
        },
        {
            0x95C56C5ED2A9BDCAULL, 0xB342CF63ABB2E8ACULL, 0xDDE0622E6F2A4091ULL, 0xC68D02ECE51CE1A1ULL, 
            0x26820EBB9016277CULL, 0xD69689F6B7B94905ULL, 0xA7214F215D3554F8ULL, 0x876F0F70F88F934FULL, 
            0xDEC58EB94853AF71ULL, 0xE9340797736FEFC0ULL, 0x5E5538A9E6B62451ULL, 0xB66E78FD6A11AAE8ULL, 
            0x1C7B040E98B84744ULL, 0xCE59BC3D5BC1D807ULL, 0x5581138E445F0117ULL, 0x38A293D8E530C424ULL, 
            0xADE0D3C23DFA657BULL, 0x6E2600941C3273F3ULL, 0xCE736AC9BD6C62C6ULL, 0x8373A7F915184E67ULL, 
            0x3F6E6F6F00F7B698ULL, 0xDA71AF070DB616E7ULL, 0xE6E893E8A5BB5846ULL, 0xB3A6A5060048ADE2ULL, 
            0x1CF5C43741471280ULL, 0x83E7FB18AE9273CDULL, 0x091E2865E0E16386ULL, 0x6BAE3DBD6DFFC2FAULL, 
            0x8CA7A70493C472A3ULL, 0x3BBC38A8A62A6EFDULL, 0x62EBAD7F497A1919ULL, 0xD6EDA45F3D94B581ULL
        },
        {
            0x4A27DA8AE9BDD73FULL, 0xD777985FE8F9BEDAULL, 0x5FBB3778609C3298ULL, 0x069561D0AA90154FULL, 
            0x99C1BE0FF6244411ULL, 0x4453C31F8C720429ULL, 0x599F6632A41B956EULL, 0x953FFD0075118DE0ULL, 
            0x08F74AEA3AC78F6FULL, 0x108A60518BD164B2ULL, 0x92791769D6178111ULL, 0xEB54B00E1C463D4FULL, 
            0xDB141CDBE2712A73ULL, 0x5DF12DB26A288AEAULL, 0x2BC746711D4F5C31ULL, 0x2E62F3436A018041ULL, 
            0x821DE416F2EFB8CFULL, 0x51717ABFF009F1BEULL, 0xADF0A4D23BA382E5ULL, 0x8198CFA7417EEE46ULL, 
            0xC75A3F6700B2CC07ULL, 0x98750B85ED1161C3ULL, 0x238E8795A46B03B2ULL, 0x2C5514754014D0EDULL, 
            0xD4AA9A2BF730555BULL, 0xA91A850B682BAE06ULL, 0xA4F50A664B6FB0BAULL, 0xA78F344C1E905054ULL, 
            0x56404FD88FFBD815ULL, 0x1807FE673CB0DB21ULL, 0x2F92E197DC25D34FULL, 0x92953E4FA1E38574ULL
        },
        {
            0x3A5CA67C8197E51DULL, 0xB6CBCB2A3CE424C1ULL, 0x5D33AD2C2D238A7AULL, 0x364E75D9BEDE8034ULL, 
            0xDBABDD95B214D87BULL, 0xE2803B091612F35EULL, 0x9D710477EBF0360FULL, 0xCB52500D4B1FA56AULL, 
            0xFBA2BEFD29316B8DULL, 0x6C91D452BCF4ADBFULL, 0x02C741822BF09BF8ULL, 0xD9BE2929863F9781ULL, 
            0x937C59816E9354BBULL, 0x96353800B141BBAEULL, 0x9592CD74025D80AAULL, 0x1D93CEB0CAAA7ACEULL, 
            0xABAFBE052FB74EE3ULL, 0x9EDEFC0A66A1BDDBULL, 0x3AF2B8A8EA80107DULL, 0xF606778E54DE98D5ULL, 
            0x7D929C53247031AFULL, 0xDB399DE09B6D0B11ULL, 0xB770A13F6F7ED478ULL, 0xCEED49AB24F927F9ULL, 
            0x37305C6ADE2D4C19ULL, 0x26AAE4606920FE24ULL, 0x1E6077770E7F81D9ULL, 0x46AFF90C6D0FD8C2ULL, 
            0xD755CE7D4D422FCBULL, 0x85D7C59149585A32ULL, 0xD7E33599A175BF50ULL, 0x01D41FBF7BD8EB23ULL
        },
        {
            0x184EC0279EF6503CULL, 0xDD7312DE7752A1F7ULL, 0x142779D961835D3CULL, 0xB72CA785B4C36B1EULL, 
            0x1D8151080831A3BAULL, 0x4B1D8CA62517DE40ULL, 0x89CFB1E9855297D4ULL, 0x27C45BBB6E107C8FULL, 
            0x561A1B8DAE406D70ULL, 0x064C03D9745854B4ULL, 0x874F681D44D010EDULL, 0xED3F3EFD4AEBE87EULL, 
            0x8D9F4001A642EDD6ULL, 0x2A14141AE27EED39ULL, 0x169EB1B875D56F5DULL, 0x472DB7EC8EA4D2E8ULL, 
            0x3416033A809C56B0ULL, 0x9EDF88275E1D85EFULL, 0xDF395D18D427319CULL, 0x3228253B3E0AAADFULL, 
            0x5D96E82729F33DFCULL, 0xB9594D6B4CD7AFC8ULL, 0x2CF309016D928AAAULL, 0x78687EA91C668E52ULL, 
            0x85FD141D22D61C58ULL, 0x63FB70294590C0B3ULL, 0x9D2FE0F815F1372CULL, 0x2700E40948B94EA3ULL, 
            0xE2860D3DA98EBDBAULL, 0xCF4E61DB7BB48833ULL, 0x34E2419A7541F23CULL, 0xD02CBC3E6C22B1FFULL
        },
        {
            0x522E00DBFC772B51ULL, 0x6C6F897C91453D19ULL, 0xE800D8B7C10DA971ULL, 0x42112ACB3400510BULL, 
            0x57913D86AC715370ULL, 0xE31878531F7725B9ULL, 0xAE3D7692D3B1982FULL, 0x9E51542F280E5926ULL, 
            0xF46F38A3F84430B4ULL, 0x3B8BBDC0F72EA62AULL, 0x09639BBA16E35F50ULL, 0x11E5B75EA5AF4363ULL, 
            0xFE34F7D732F5A2BEULL, 0x55B783D9BA5E4498ULL, 0x5E024DCE526085C5ULL, 0xF3D72B45D76D3EBDULL, 
            0x0F90E3F01B58C7EBULL, 0x290BB7BEDA69AC08ULL, 0x6843351EA10F8C1FULL, 0x922C59C3D8101F4BULL, 
            0x7968909D7FE357A0ULL, 0x25DAF9DB894530FDULL, 0x1584E605CAAEF65CULL, 0x209EA2FBCDB29325ULL, 
            0x71D0C00DCEA59787ULL, 0x3B839B435D090B78ULL, 0xA791AEFF10255884ULL, 0x4C807C91C7E67EEEULL, 
            0x9F92FD53ECB45318ULL, 0xEAE73EEFDA43767EULL, 0xEA8B30E170823AB0ULL, 0x6A00BAB266EE0DCFULL
        }
    },
    {
        {
            0xB5AE94226054FDFDULL, 0x48104173DFAC39BBULL, 0x05BEA5805D6D8649ULL, 0xC80C35F9F14C2D09ULL, 
            0x14924E42492CE2ABULL, 0x262487D71AF3DD88ULL, 0x23F5BCBFF63A4210ULL, 0xB15481F4748C1EE0ULL, 
            0x77A9FB9A8CD464C8ULL, 0x483DB18134994FC2ULL, 0x19C97D28BC233926ULL, 0x300D74FD2BF01122ULL, 
            0xD1850313A1F4F5D1ULL, 0xAA86CCCD42DEB267ULL, 0xDC1E5DF14D6EA24FULL, 0x9651A5B383588BB3ULL, 
            0x80F11AA1EF675AFFULL, 0x900F38BC790181B8ULL, 0xD45AAD17A70FDE02ULL, 0xB7B1426DD001DF5BULL, 
            0xF0417AF070C89729ULL, 0xC55D68E9DDBFFDF1ULL, 0x7E8733E76C07863FULL, 0x760C170C4C1FDBEBULL, 
            0x992ABF5864912F7CULL, 0xF12C0FA558E38278ULL, 0x2FE0BF2B005E4216ULL, 0x2AC651FC76EAA250ULL, 
            0x24E8CA921B695F4EULL, 0x570743C615F7991DULL, 0x19F1D2D0E6075938ULL, 0x4276ABB9FA3B71E7ULL
        },
        {
            0xBC72DA5EF41713A6ULL, 0x1CDD9D575204142AULL, 0x547DD48E913A1450ULL, 0xBD4B53A3808A8C04ULL, 
            0x2D33471FBDF63D58ULL, 0x2F5C6E881AE48B73ULL, 0x84F29FC467373AF1ULL, 0x98BC7406EFAFE053ULL, 
            0x79963C5ADC3A0F86ULL, 0xAFC713989CEB5A88ULL, 0xDB936B5E51098F84ULL, 0x6B4690FA7F533F4FULL, 
            0x36BE5FC6F1B56FABULL, 0x9311FAF5E241AD61ULL, 0x2338B665C8087C39ULL, 0xE31BBC79A442DC92ULL, 
            0x57DA04CD83D05135ULL, 0x03561B76EDE7240DULL, 0x1C7CE02F6E8AE6FCULL, 0xC64E342B0672CC15ULL, 
            0xA690605A8CCC18A4ULL, 0x747D554D90B7B56DULL, 0x0A831F68281C0EEEULL, 0x0DA24BED52A02040ULL, 
            0x85A1902BE08D2F1FULL, 0x98FD8624079E71E5ULL, 0x1E850BD241AAB244ULL, 0x0B858460C2FBD20EULL, 
            0x2C3E6E7B3FFBCD46ULL, 0x48A0523874BA954BULL, 0xC1B755089C975A1DULL, 0x6DFA744DB8C3FEB3ULL
        },
        {
            0x3B21B23B72529CE5ULL, 0x4C93F7AA3C4821E4ULL, 0xB81DBCAAF933006AULL, 0xCFBF46F37397137EULL, 
            0xF65E71D918ADDF7EULL, 0xEE643A672070F1A9ULL, 0x01889A78F3A6340FULL, 0xF9E7CB196A8ECFFCULL, 
            0xF03E9B3FD148F637ULL, 0xD8E4EEE97AD6D1AAULL, 0x754E3F59DD6A6FF0ULL, 0xE3DDB64F51E63C65ULL, 
            0xCE7093611A73FFBAULL, 0xF74EC41C40336134ULL, 0xC4C9612B4364451EULL, 0x9D2FBE2610A10AE6ULL, 
            0x5BDF1A427EEC3211ULL, 0x2C95B6CDA12DB3FCULL, 0x3E8E185522F0B43CULL, 0xF29BABCCAD9C6EF0ULL, 
            0xAC7C4BC844E21E96ULL, 0x653841EB7AC86B1CULL, 0x3974491C57E923C0ULL, 0xF4BD75D8C876B734ULL, 
            0x02043F52FD0048CBULL, 0x7279B04B3971FA98ULL, 0x44280067E9D1EDE3ULL, 0x2F6582E6DEC2FE5AULL, 
            0x6E155944D52B141DULL, 0x28F0DF83EE9C25A9ULL, 0x6491A0E348935831ULL, 0x13F61F8665D8E07EULL
        },
        {
            0x826F2170D73047D1ULL, 0x0690C1A5A6113C29ULL, 0x42B50616FE92F503ULL, 0xAAA5654C59F7905BULL, 
            0x5978ED6ED85AB87CULL, 0xE06C83C98CD21951ULL, 0x5F43CE1E64B341E3ULL, 0x43351AB911548591ULL, 
            0x2D39644F556C447DULL, 0xE8058333736C191AULL, 0xFB35379B0B2A6B15ULL, 0xF601F13BEF975E2AULL, 
            0x50DD7081927D705AULL, 0xC0FE7BF128DCB13DULL, 0x79B223F6B574CD75ULL, 0xE0EFD3FA0A213B6DULL, 
            0xAE1BBE5517B70385ULL, 0xF5F9C02FE8052047ULL, 0x255D5EEDF7688A5DULL, 0x2DB28210B1D0F00CULL, 
            0x53E80B2C23E0E37DULL, 0x0D66923EB5133931ULL, 0x59DDF75C0A729F98ULL, 0xD8BA08BF0B81DFB4ULL, 
            0x246BFCDDF2B7B534ULL, 0xD423F4F0C5C52A80ULL, 0xB78766F2F960A3B1ULL, 0x1199322207EAEF53ULL, 
            0x0B5DDF3A37DB91E1ULL, 0x9CCB034BDF3A9E7EULL, 0xB7762B3F7A5ED12FULL, 0x30E9733FB220178AULL
        },
        {
            0x8EFA3BD73287AFC6ULL, 0xA7D84E1CFF625EF5ULL, 0x4886BDE3B214A4EDULL, 0xB7867F8D7441AACCULL, 
            0x9D747019D9A9106DULL, 0x4564F801B6B7085CULL, 0x5DE32638DBAF1586ULL, 0xF1E590BB33B524E8ULL, 
            0x25DDEA7198C93C37ULL, 0xF977CC848906C010ULL, 0x871123607ADB40A2ULL, 0xB7B1DD32F7E2B240ULL, 
            0x5622C0F7A8CEF774ULL, 0x88C340EC6C68E1C9ULL, 0x57AE3CE24C84CB9AULL, 0x146B30559A75B5DCULL, 
            0xED2B4F485B066A8CULL, 0xA03822B3E05ADFDBULL, 0x3E388F930C1707A4ULL, 0xA9228FC10614D051ULL, 
            0xB54A80CBF402321FULL, 0xDBF1D6D561E40588ULL, 0x4B5677683FDF4253ULL, 0xCEAE96A94455ADD6ULL, 
            0x790D40449150520CULL, 0x43497691A96EA2FBULL, 0xCDE3C5E0B477238CULL, 0x752BAE07388E7C63ULL, 
            0x88B6E9EF10C5794CULL, 0x7204739A6433E7D3ULL, 0x9CA2A40AFABA3943ULL, 0x86248317BE87D294ULL
        },
        {
            0xB60831F9612A3E8CULL, 0x13AAF8A62DFFFE37ULL, 0x152127E8707EC663ULL, 0x7506F2D77121E707ULL, 
            0xEC3C4C2A98EE8E43ULL, 0x9E3996BAC8147636ULL, 0xE0DC071ABE0DDE7CULL, 0xF3B1B627E4780B5BULL, 
            0x4BD186ADA49D72F8ULL, 0x239247373F7A6408ULL, 0x0877EA10CC587557ULL, 0xCA95AE5FDEE65D0FULL, 
            0x833B37F29C2CF4F8ULL, 0x318BFB0E93DE5A8BULL, 0x4D06AE117E875189ULL, 0x6C7EB8DA30D9A128ULL, 
            0xAFA9432EEDC51D68ULL, 0x207A15060FC1624EULL, 0x623D6AE8610361D3ULL, 0x409EF83C60DA14DDULL, 
            0x033B1A3F3979EB84ULL, 0xAD809D561F685984ULL, 0x02CB01271128AE5EULL, 0xC87A6835C1D1CBD0ULL, 
            0xD13DFE811165163DULL, 0x9220E6921537913BULL, 0xF29D8EF2A51B24CBULL, 0x0D49EBBE7381CAC7ULL, 
            0x1197E3756DD11F53ULL, 0x7B46F0867653EBFFULL, 0xB992DC19D07DA81DULL, 0x53D8C77C429480C8ULL
        }
    },
    {
        {
            0xF8F2DDF51985335BULL, 0x1F2419C49190BB73ULL, 0xAA3DA6E4EAB88352ULL, 0xC1B78A4725E86080ULL, 
            0xED4080D19814456AULL, 0x7AB10A639B73B38AULL, 0x85BC205A437F74E0ULL, 0x46EAD2AA335A14DDULL, 
            0x0E3F5150D9A6B9D6ULL, 0x7E7D33DC1D77F0E6ULL, 0xCE0CB9682E5FB725ULL, 0x7D9C445EE0664ADDULL, 
            0x1ED7C13ADBFD424FULL, 0x25F29B5A5A3694AEULL, 0x15404D783084F758ULL, 0x05ED5F208F047AC0ULL, 
            0x9C945785DC3389C9ULL, 0x65E3C98E7B4BE8D1ULL, 0x6822C308E6C00E09ULL, 0xE78949FDAAC47361ULL, 
            0xCADE8B38C2F19110ULL, 0x0A65DFCD51869E7EULL, 0x4A2F8253DC69DAD6ULL, 0x7B938965B4B209A8ULL, 
            0xBB7E3A949F377A2FULL, 0x31B6530322FF8DDAULL, 0xEBD15333AE1A01D3ULL, 0x5DB3E71CE1783A66ULL, 
            0xF46A1A7640AF7FAFULL, 0xCFFCD2AF03CB41FDULL, 0x07CFE6FA3F63861FULL, 0x35E12C4A9B6A43D0ULL
        },
        {
            0x2FCD398189B37A9AULL, 0xD5B9C32B1D32CE17ULL, 0x915A782A12E48940ULL, 0x44E3955961A6288EULL, 
            0xFC2AD0A1408611B3ULL, 0xE0E36553944FBA92ULL, 0x0F43ADD9F47D4A71ULL, 0x1A465D86D27A00ECULL, 
            0xCF388A74B0468D40ULL, 0x8493207B34D0C9F3ULL, 0xA08A50899C9AA4C0ULL, 0x7CF22B3AA5C86B64ULL, 
            0xA319D56ECC923DD8ULL, 0xC699CAA7974C8212ULL, 0xF57EC249C0B4C80BULL, 0xFF5FF6A9CB591957ULL, 
            0x764868ED22F748A8ULL, 0x0D09B200F295E275ULL, 0xEB8E2C0619936DB1ULL, 0x418631C165758342ULL, 
            0x97400D41EAE5A49BULL, 0xA790C03DE22B51CFULL, 0x923CA0F178E07CD6ULL, 0xDC44D2FFFF7C48F9ULL, 
            0xC82BFB2339AADE3EULL, 0x79F6A4ACFDB444CCULL, 0x0DA14C41B812AC7EULL, 0xD55677A80F85A5C9ULL, 
            0x29CAE2C995738E41ULL, 0x5F980F5CD04CFA30ULL, 0xD6FDCDC215765496ULL, 0x9ED8D72948371565ULL
        },
        {
            0x4DF577BA593DFC71ULL, 0xF578E6F9BA380C62ULL, 0x86186FBB6A853598ULL, 0xAA2C4DA1100C4BBCULL, 
            0x87C802729B90F59FULL, 0xF94E016DE5F314EFULL, 0x3B1109ECBAF84858ULL, 0x7F0F8FD5F3957460ULL, 
            0x1C8B58E72BD8D064ULL, 0x6AD5D275B551BE22ULL, 0x2D80AD7204139FD8ULL, 0x573A52EF33503948ULL, 
            0xE69397CE6030B0B4ULL, 0x167F33CB1B8E6AFDULL, 0x7B397449FEF86CC3ULL, 0xC4EEE5AB1B637BE7ULL, 
            0xF8FE2D3A0D7A0205ULL, 0x62A2A6D0172DB21CULL, 0xC6A4B21DFBC3D2CAULL, 0x8D08C027BF8ACCACULL, 
            0x38A599BB989F0F2CULL, 0x3700677E66058E56ULL, 0xB7D297B61978921AULL, 0x4D0A2E2E554CCDC0ULL, 
            0xBC1523F2C00DC653ULL, 0x7F70C0942B944E0AULL, 0x6775B32C838E113AULL, 0x00FE94E837D6D931ULL, 
            0xFAC4772F7AAE140DULL, 0xB76FF71FDBE69020ULL, 0xD31E35D8EE661389ULL, 0xEA427A544BD2599AULL
        },
        {
            0x064DAC9CAF0EA0F9ULL, 0xD51100B2D861B154ULL, 0x20F1D98B2F861692ULL, 0xD3157C460381230BULL, 
            0xEAF181DF39394CA0ULL, 0x2BFA110F76F60719ULL, 0x0B6A32357B865D44ULL, 0xBD05F8F394EB0756ULL, 
            0xBC9D862E72A3F4F1ULL, 0xA3EFBF3041E75EEBULL, 0x39A0BD47042BAA0AULL, 0x9EAC96FC677C9525ULL, 
            0x7D25D89041FB5A18ULL, 0xD27718B2ED1F4AD9ULL, 0x04C409FB69929B1FULL, 0xC81E0CB27B1B7173ULL, 
            0x633FCB3B4290B82FULL, 0x77ECDD2D05206CE9ULL, 0xB096F1F6BCE22EBBULL, 0x22D6472BD2A1F2ABULL, 
            0xA28F3AAC89774086ULL, 0xEFC3AF37D956A631ULL, 0xFFE50E7C0D51D4E1ULL, 0x1DAD657AB2A78740ULL, 
            0x9526202CEBC912B6ULL, 0x5B454A526791077AULL, 0xE6BCC0145378FEAAULL, 0x06298334CE78EB63ULL, 
            0x11079830A6D60440ULL, 0x0C121DB5E6D0C85EULL, 0x65F4CA8342C10534ULL, 0xE409FCD2EC9FBD0BULL
        },
        {
            0xD7A97658021B8245ULL, 0xEF7144E2F131DBF8ULL, 0x0CBB61ADC0190719ULL, 0x867097A6A0D0861DULL, 
            0xA5E20A492D01CB7CULL, 0xB317F63107F7F8FCULL, 0x0164DA3073D81E80ULL, 0x7708FE39D87259F0ULL, 
            0x36B8439ED29C8DFCULL, 0x500F6E9A06979707ULL, 0xA5D4A074D6FF9E33ULL, 0xB8E0ACF187000301ULL, 
            0x99568322C8BEAB8DULL, 0xB38E7CFC53766E3AULL, 0x3445B25FD8768E5FULL, 0x2D20D6BC66AEAE5FULL, 
            0xE5B5B2F4F54CE610ULL, 0x0E64ED79EB8FC207ULL, 0x3812247A86B228E9ULL, 0x0744F0D2A2306EFAULL, 
            0xF3A06CCF745F62DFULL, 0xC096EEDC69AD5724ULL, 0x7C2D46A3C4464C67ULL, 0x3513908A9EBEAF8CULL, 
            0x9713BD6D641C7BF8ULL, 0x7FF2CC26EB4DBF12ULL, 0x2EEC47A0E19C2141ULL, 0x61E82CC666E803B1ULL, 
            0x1AA69F53A8A77D4AULL, 0x9B9F1D6662F819E5ULL, 0x1D8E885B8028EF7BULL, 0x1F573ED04C4467ABULL
        },
        {
            0xD29AEB6C2007099AULL, 0x63728ED68D720ED2ULL, 0xBF4B9FC3B515B71FULL, 0x40A72FC85580F45AULL, 
            0xB256A4C835F34FDDULL, 0x8077985EEC0E2EAEULL, 0xA8057C9473958964ULL, 0x2B473ED328CC5948ULL, 
            0x1BB0AFEEA07F4A79ULL, 0xC7C9B6396585DF45ULL, 0x94395FDEAEE048E2ULL, 0xC97558D8BB9ADFBAULL, 
            0xBE06F2AB471D2AB3ULL, 0x79CBF6A5F4DC59CDULL, 0xDE82FC73B7369A61ULL, 0x155E0DE5FF999DA8ULL, 
            0xD9D8735E002BBD54ULL, 0x2F066E00447DDE4AULL, 0x8D4D9A784762C429ULL, 0x59143DD912BDB725ULL, 
            0xC984B1E35BB0A928ULL, 0xCA5A005A09F71E86ULL, 0xC62CB8D39D396E1FULL, 0x0F340D24E08D12D2ULL, 
            0x3E58DC254748463DULL, 0x23B9EA7E8E7A9AF2ULL, 0x1BC099F789AAB51CULL, 0xC48BB1F5E762BBC1ULL, 
            0x3B96EBE1D0C89B02ULL, 0xDFD93AF4D8104F75ULL, 0x719566B22919646DULL, 0xD574311DAC501BA0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseEConstants = {
    0x88E9A949EB2A8711ULL,
    0xAEC87018AA3C02A6ULL,
    0x05F95BCBB449EE90ULL,
    0x88E9A949EB2A8711ULL,
    0xAEC87018AA3C02A6ULL,
    0x05F95BCBB449EE90ULL,
    0x5510B09B91E9D0F2ULL,
    0x4D43557C1E9AAABDULL,
    0xA1,
    0xF2,
    0xF4,
    0xE0,
    0x15,
    0x49,
    0x2D,
    0x5B
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseFSalts = {
    {
        {
            0xFC5EDCE066C01A71ULL, 0x0DA581D3CF6C7FF7ULL, 0xA2C4026C7FEF4525ULL, 0xB8E8B4AC97172575ULL, 
            0x65AF6D367B742FF4ULL, 0x12B58DBACD167A02ULL, 0xC71D67B79AC3F516ULL, 0xA0FDC5CD277F5E7CULL, 
            0xFA9EC87579D0673CULL, 0xA9D1A6C2FC55221AULL, 0xCCBAD4B63CE9F794ULL, 0x8DD204428DD48AF1ULL, 
            0xE0FA2DFD25DFA83AULL, 0x36E0E1CF0911CFFCULL, 0x4686F222DB53CF94ULL, 0xF9DA5F46B880E14DULL, 
            0x906F89A1A8A7EF44ULL, 0xB4640627F026C0F0ULL, 0x1D12F2C095D214C8ULL, 0x90418B0F1B860CE3ULL, 
            0x0D56424BC837EB40ULL, 0xC515DE7FAF77DBD0ULL, 0xE5C3F50627C561EAULL, 0xF625F077A082339DULL, 
            0x65736EBB722AB2E6ULL, 0xAA39039DBDCBDD4EULL, 0xA9FF72F3CD890CA2ULL, 0xBEAE79771762A47FULL, 
            0xA19B5B3C34088577ULL, 0x096BBCE042818622ULL, 0x0B732A15DAEB9660ULL, 0xEEC53CBDA4BDCBA0ULL
        },
        {
            0x18C39107B2BF5C6BULL, 0x1837A67DBDD9BD65ULL, 0x0E997A8ADF644121ULL, 0x3768ED1F9069A1FFULL, 
            0xFF445A6866138644ULL, 0xC396C87B30ED2B8FULL, 0x531F0A9B27301DBCULL, 0x8ABABCA9184475B8ULL, 
            0x2AE7986A8BBE8318ULL, 0xA1F4F64CF5DE00C7ULL, 0xA6EC809FD2020462ULL, 0xA84508DB76B32BCAULL, 
            0x27FFE1822736017EULL, 0x93737179146B4630ULL, 0x614C8DCF1C28C5C1ULL, 0x3D992159FE466BF3ULL, 
            0x152EBCB1BAC61CD1ULL, 0x164131BFDDA0773EULL, 0x015A02E50D10048FULL, 0x7FAEFDBCEB9EFA18ULL, 
            0xE11989031CF3F0A1ULL, 0xE6B101BC5CDB95A6ULL, 0x16AB7BA69C7BF943ULL, 0x77FD886A92DA248FULL, 
            0x87E475F8E5C87362ULL, 0xA85381827D6A33EDULL, 0xF8A918F8A62FBC85ULL, 0xA9E6AB690EFA5BDAULL, 
            0x0C33D38B335FCFADULL, 0x75EC954433AF10ABULL, 0x71EBFE5F3B446B15ULL, 0x7507072DF5BF5303ULL
        },
        {
            0x37888B42FB821E9BULL, 0x41C4D60DA4C09089ULL, 0xEA89F4B9A82D3A1CULL, 0xCDBF75364DEE300CULL, 
            0x8D751D7CD32EE18BULL, 0xE900EB9A232DC9C8ULL, 0x6BBCF5601976C74EULL, 0x8055A35CC3584CD9ULL, 
            0xB2270E38109230A3ULL, 0xB3FA2A85CE513555ULL, 0xDC1BC6EDF0E8C7FBULL, 0x235514E6D9206C3DULL, 
            0x20E68E1405A991B8ULL, 0x7D7142DEC4A7E6EDULL, 0x0B5B5E2C55EA7996ULL, 0x8CA68F5CFBF31FEBULL, 
            0x8F898893F66DD7B0ULL, 0xA0AE815F7E226166ULL, 0x1702D93BEE9F72C6ULL, 0x17F0EADA65BCAFBAULL, 
            0x8F6D28EF88D5B443ULL, 0xB72CAB9494540E3CULL, 0xF328D68BF846A205ULL, 0x2192C8B8DF667B0EULL, 
            0xAAA3B89455F25C0AULL, 0xE3C9E40CDB895246ULL, 0x507E1747D3442B45ULL, 0x3A09E70B806472D2ULL, 
            0x4DAE3622AC47042EULL, 0xA45AA8DAD3D98DDEULL, 0xC936EE3698E5D12EULL, 0x1A164BF5D393272FULL
        },
        {
            0x210A11C36D12D889ULL, 0xC5F6C35AFF60FFBAULL, 0xA75E8E984CF87E7BULL, 0xC438C43654A72545ULL, 
            0x51299D5D25D03FEFULL, 0xEDDF8B706C1CB84FULL, 0x49BE4226F9DC9913ULL, 0xE74911DCFBCD6D85ULL, 
            0x2A7C8A24201D4C94ULL, 0xB775AF4F58631908ULL, 0x6E613DF58BD3EAC5ULL, 0x72D37CA7DFD34010ULL, 
            0x263E2E577A9A5220ULL, 0x1EDE96E0FA9E2192ULL, 0xF3C9001BA3D978DCULL, 0x8C0A22B965951E21ULL, 
            0x1250F00E6C7AF2F4ULL, 0x3E044898C24382A7ULL, 0xD8E5546C1BD89642ULL, 0xF32D51777B2E45C6ULL, 
            0x58AED6DA3F359175ULL, 0xF1FB3F36BC2698F3ULL, 0x8E99FD30C0502391ULL, 0x51FE637D5C56A059ULL, 
            0xE567C23F1A71E467ULL, 0xE0F3C1901CBE8A2FULL, 0xEF827F151FD0F5B9ULL, 0x702A87950333FF76ULL, 
            0xD8F50D13BB49C964ULL, 0x184F2266318381EDULL, 0xA841BABBC67E18C3ULL, 0x8086AB0D6F59BC57ULL
        },
        {
            0x86F527E2C08883CFULL, 0xCEBAAD559081CDB6ULL, 0xCC3065C898782CB2ULL, 0x3A35EF877DE6FB6EULL, 
            0x3752229FE5768C3DULL, 0x96B9CF80D9B0FAA6ULL, 0x7A5F0BF639F4D4B7ULL, 0x3C21F986FB1235DDULL, 
            0x64FB62C297305467ULL, 0xAF973C1AE37A83E7ULL, 0x4EE2BF4A4D0AE1A1ULL, 0xB632E17428452D15ULL, 
            0x9DF15FF51B4DAA51ULL, 0x980E02343F9F18C7ULL, 0xA8C03E838690E0F8ULL, 0x237774A0BA6E02D4ULL, 
            0x30F15BE089A4356FULL, 0x90CD32A603F2E467ULL, 0x9F887998309DB85DULL, 0x22026B7050A94043ULL, 
            0xC5A2FF6877448A8FULL, 0x8998D0A7D8784B1EULL, 0x298C8B0676AEA51CULL, 0x124030461E331E93ULL, 
            0xA0FF8297B506DA56ULL, 0x48AC44825971D070ULL, 0xBD7C8E346AB31AECULL, 0xA57F75BF1DEFC777ULL, 
            0x3C58D42D4B1A8DA5ULL, 0x9A6F63C001D77489ULL, 0xDA99ADBC6AAD8B9DULL, 0xEE7F53054FD4D67EULL
        },
        {
            0x059B61907DE13126ULL, 0xE3F8EF3353BFC0C3ULL, 0x2E10DDA02EFFA8A2ULL, 0x76E72F787E335BCFULL, 
            0x55EF49767CB0EC70ULL, 0x23A821990B278DE0ULL, 0x8C44181B657E13B2ULL, 0xBBBFE0F5C1E838B2ULL, 
            0xF11B260DF885CD23ULL, 0x66034ECCEB22D759ULL, 0xD7C552AE0CED492CULL, 0x7B29A74EBF9DEE19ULL, 
            0xF45F2BC68AAD494BULL, 0xAA874E836A8ECC1DULL, 0xFB0231F3C4302029ULL, 0x73BF3936E66509E5ULL, 
            0xBE65C1B018EF84B1ULL, 0x840D265FCD6D01FDULL, 0xABBCF3DD8E068792ULL, 0x3570FBE81083D67EULL, 
            0x33181A23649F6F91ULL, 0x751FFB058E4EEB44ULL, 0xEC696A6DCC287694ULL, 0x9AAECD1205368170ULL, 
            0xD10AF8683B10D825ULL, 0x0F4173421B7471D0ULL, 0xF2E7111368AB2C07ULL, 0xF3E2B596EA9C6B0EULL, 
            0xE441C19B7417596EULL, 0x8AB29A190707F85DULL, 0x804CACD39EA58057ULL, 0x2B3AB169E7EF57EAULL
        }
    },
    {
        {
            0x5E1089888DDC0442ULL, 0x690830A7851A220EULL, 0x3978103DD78F0E95ULL, 0xAD2861B824038C0AULL, 
            0x33CD9CCCCB73AD13ULL, 0x271AEE21C41ECD53ULL, 0xA36FD937D5D581B4ULL, 0xA14653366022EF37ULL, 
            0xF340B89CCD69EF5CULL, 0xE43F1DDCD9529EEFULL, 0x373B6D1EA8E10711ULL, 0x16AE67FE7576D5A2ULL, 
            0xDD14A6A9C67BD4B4ULL, 0xC4F4F848906AD046ULL, 0xE88171F249E24679ULL, 0xC864FC81736D0015ULL, 
            0xC03D92031D439692ULL, 0x8BE6A91C629A89AFULL, 0x71DAF88A62A8C34AULL, 0xA68EA53049A2D82DULL, 
            0xD931BB33CE66097AULL, 0xB04232BF05ABD243ULL, 0x90BBDBA0EAAB4E26ULL, 0x2A4851DE7B948F79ULL, 
            0x0EAAD734A7DEB5CDULL, 0xC79FAD973EE0330CULL, 0x57E088C607506A26ULL, 0xDF5ADA0BDB6EA423ULL, 
            0xCCC394EE3FF5C277ULL, 0x09CA240C5629DB93ULL, 0xCFFC66CDA41AA74BULL, 0x7CBBDEE6E5CAF149ULL
        },
        {
            0xB1A1D68B5C0B3FA3ULL, 0xA2535348166F625BULL, 0x3BAE58638DAB361FULL, 0x549C6DE895506B34ULL, 
            0x31E643CD11C734C2ULL, 0x1692A784347432EEULL, 0x8F2069D0BCFCA158ULL, 0xB021DBA80D1943EEULL, 
            0x96A26E60A39620E2ULL, 0x3355AB3E5873B073ULL, 0x28C0A24B30432200ULL, 0x87FC0C40B32870AAULL, 
            0x54B314F0CF24F4F2ULL, 0x7BD60937072B620AULL, 0x0A38AE74F6B4BFBCULL, 0xB8A4CA91B93E5559ULL, 
            0xF4100F4B6EBB0CEAULL, 0x05DDAA25B92D5A8BULL, 0x96B57F4A415A05A7ULL, 0xB6D9505BB8FAC7F9ULL, 
            0xA394109B2BB29C80ULL, 0xC2230DA8C1E34FCBULL, 0x0933FBFE105074B9ULL, 0x69379561F85BD38FULL, 
            0x0A7DA4F295E9D077ULL, 0x3FA2C349A172E87AULL, 0x1D4D511927EA49B8ULL, 0x4DEE5A4E9FCB2CD8ULL, 
            0x84179567161D71C0ULL, 0x1C141CC48A0741EDULL, 0x1225026697613C85ULL, 0xE9CF6AFC1B49A07AULL
        },
        {
            0x36A0CCCEA74031DCULL, 0x2F11150A8B316753ULL, 0xAA99DEAA7D3917ECULL, 0x43E19A0EE723C260ULL, 
            0x828454469252132AULL, 0x47695FE2776AB519ULL, 0x9C43BBD36A01CEE5ULL, 0xEE34333419430D69ULL, 
            0x0DFA675096EA1852ULL, 0x1E5DE06066C7ECAEULL, 0x32425F85B10C796DULL, 0x10D8A7C0B365F5ABULL, 
            0x0A8502851D6ADC59ULL, 0x2EDF46DC7EE13634ULL, 0xA9CC35D94B55C19BULL, 0xA1FE34C8181DB1BCULL, 
            0xBDDDBE20B827F6D8ULL, 0x259D2975AA75C933ULL, 0x3AF906775D8276C1ULL, 0x8AA07ADFFCDF8757ULL, 
            0x864A452B6D635B35ULL, 0xD32CC52BC1D6C973ULL, 0xD342B59E5E4B1244ULL, 0x9530E60481E3497BULL, 
            0x067BB76D6CFECE19ULL, 0xEBCFE6D483E09879ULL, 0x1272DBB675FEEAEAULL, 0xD5E84F639C9D7A29ULL, 
            0x900469DC523A7F3FULL, 0x1F97DD3AF673A38FULL, 0x0D5501C764E458E1ULL, 0x5D98C0E32461DA1EULL
        },
        {
            0x8AD3B0732A4A1168ULL, 0x0256F7F1B88C98FDULL, 0x2A4907CF3ED8C15CULL, 0xDC35C77F2B460E15ULL, 
            0xC7B518706064AC65ULL, 0xCF5E5E0E44BF4C07ULL, 0x464596FAF608820CULL, 0x5186F65C987B372CULL, 
            0x57D5C8FFC5EB9BBDULL, 0x6CE230E6D7C9A425ULL, 0xB857ED087873878AULL, 0x94B47A632A49D08BULL, 
            0x5E59B1CB30789758ULL, 0x86B7C1501706661BULL, 0x3561B48B67960CA4ULL, 0x6DFDBA587172080EULL, 
            0x31FA565D5EF1CEA3ULL, 0x69125DBF20EEEB5DULL, 0x326A7784022E9FE0ULL, 0x4354513835069760ULL, 
            0x2D45401AFD1A5D9DULL, 0x4AE2BF625D7A52CAULL, 0x461D5830AD772C31ULL, 0x69EBCBA5DA40E0ADULL, 
            0xFE6C3138EA75DA26ULL, 0x8B98771D206E573EULL, 0xDEBF450BC13DA007ULL, 0xFA2901B966ED98D7ULL, 
            0x80628789A7CA26D2ULL, 0xEA23E81FF34DDA1DULL, 0xD2951F7AC292198EULL, 0x55DB2CE1C97FEC5AULL
        },
        {
            0x3594FD879E8A4106ULL, 0xED20907939DE6142ULL, 0x5C699B7A25955B8DULL, 0x03FA055087E595AAULL, 
            0x58FACD83FF7B47F1ULL, 0x6554799EFB8065BEULL, 0xBA293AA9E580A90EULL, 0xCCE3F928DDF1BE4FULL, 
            0xE9A8B45210CF7372ULL, 0x65291A659B7157A3ULL, 0xC5C6DDBA90D4E813ULL, 0x32ABD25763851C9BULL, 
            0x0A4D9380C981A014ULL, 0x49EABB7C2E2482CAULL, 0x8526AC23AD485306ULL, 0x6863BEC784699EB6ULL, 
            0x5A0CE7EB6298F1E4ULL, 0x4208B3B48F6E9CAAULL, 0x02CC7218F73D5F90ULL, 0x8451EFF66A1FCB70ULL, 
            0xA4CBA4110C29874CULL, 0x9EFA9106C6CAA776ULL, 0xB7BBB2B0403A63B7ULL, 0xBAF6237E10D1DD69ULL, 
            0x6BC20AAD4723F5BBULL, 0x814DE3E74AF97D39ULL, 0x9CA562CDFB8B57ACULL, 0xE61C29F5EFD79557ULL, 
            0xC39F332568E150C8ULL, 0xBE6D40C34D3C44C6ULL, 0x87B54D3286C93AD5ULL, 0xC13E5980759512E2ULL
        },
        {
            0xD8FEEB72F33DE3EDULL, 0xC0A616174631FAAAULL, 0xD3D42D46F88F9E92ULL, 0x230D167B052BA1DCULL, 
            0x65C7053622D34CF5ULL, 0x7BCA3C00E10E434AULL, 0x191B98D18A07B8C5ULL, 0xAA1A7C6B7A4EDA1DULL, 
            0x201005495A523259ULL, 0x1952128A09B07F67ULL, 0x7ADC0013A3753238ULL, 0xD3CC298A35F8948FULL, 
            0x2C0221B9F3A85607ULL, 0xAB4FA2E8D62A5FCAULL, 0x80733F4D11C7B941ULL, 0xA1C988C640F612D7ULL, 
            0x4829864977F3B1CCULL, 0x5C78B3D32EA277B5ULL, 0x554D694C7B5A650DULL, 0xA8A3E08667BE54F4ULL, 
            0xA2F8A33AD321321AULL, 0x213748B45C615CDEULL, 0x8975092F1C3BE30DULL, 0xD2A506F3644C4462ULL, 
            0xD6990679239200E9ULL, 0x22D077275025210CULL, 0xC9636837C92360E8ULL, 0x6213C8290921284AULL, 
            0x0E94935E8F5638FDULL, 0xDE44C844940C33E4ULL, 0x4F4B80D5D2A8B9EFULL, 0xF7DA09864D948568ULL
        }
    },
    {
        {
            0xB6BFA01DA239A3F9ULL, 0x091C2B83C916FC4BULL, 0xAB818EC0D4F53EA2ULL, 0xDD1221FAA52C7216ULL, 
            0x7F9D4873CDACC59FULL, 0x33EFEFEC8ED1CBE4ULL, 0xDCBE8127F96ACCE4ULL, 0x450604AE13829B5EULL, 
            0x3FF9FE8B5EFEA6ADULL, 0x1AD6AF210B3993BBULL, 0x26C4B39E45EBD407ULL, 0xC1429A48DF337A75ULL, 
            0xF8F0468283EF18B1ULL, 0xC2A0EA715769BD9AULL, 0x7C306E78F9AF0E92ULL, 0xAFAB243A28CF6808ULL, 
            0xEC545E13535FAAEBULL, 0xE8CD2D0F6D03CEF4ULL, 0x71C7A1AD9A0E0358ULL, 0xFF076FB0C16CF25CULL, 
            0xC372B5114657B82AULL, 0xDEB8F695CD4A5857ULL, 0x612BCDC7837FF6E9ULL, 0xA77A665C1D1FB923ULL, 
            0xE0F84D97082BA3ADULL, 0xCE6A8CF38D57F827ULL, 0xCA3CC735B38989DAULL, 0xABE5C8A97A3DDBF3ULL, 
            0xC181F9FE85E1ABBFULL, 0x1475B1640D1C9D32ULL, 0x2BF829E5402D9F35ULL, 0x0ACE94A36527DD28ULL
        },
        {
            0x5CAEAB997A5E2F79ULL, 0xD7DED0FF824EB019ULL, 0x623AA56E685B1AC7ULL, 0x434087D64366C816ULL, 
            0x5DE074F69DD78BA6ULL, 0xD0BC03657799C7DAULL, 0xC33DF2BBFEB66D33ULL, 0x98E5586850A8BBA6ULL, 
            0x52A8D1DD169AA9F5ULL, 0xE21AE6C351AB6603ULL, 0x499E3BB0ABF6E60EULL, 0xB617AC5F013CCE1DULL, 
            0x7AA6028E85021641ULL, 0xFC02B3F246E4B116ULL, 0x4CD0AA5EFB2064F1ULL, 0x17E9E67F7CFC9176ULL, 
            0x304DF49F08597B88ULL, 0xBE3A599DAE483AF4ULL, 0xC387ACF2982D787EULL, 0xBA857AEC1C9769B7ULL, 
            0xC84001FFA1FA3AF1ULL, 0xE9CF2631D261E6EBULL, 0x51F6FF5FBD888538ULL, 0x4441914819887CB8ULL, 
            0x50CCF256E73A6B8CULL, 0x5EB25B9D41B1CF13ULL, 0x4B5028AB86A36B53ULL, 0xF0E1640876DF5DBCULL, 
            0x1AA8B9A2E24D24A0ULL, 0x6C403F10B4A44017ULL, 0xAC7F11572CEB61DBULL, 0xD32369D09F7A3498ULL
        },
        {
            0xA227F4F5FB0B8466ULL, 0x8906211B8A3E9CACULL, 0x8D823516DFB5B986ULL, 0x74F3555539455799ULL, 
            0x07105C21CB1D2B21ULL, 0xCA32C9EA7C2BA97FULL, 0x2FA9C88071C8AF66ULL, 0x7AC1E3A0616527A8ULL, 
            0x9EDA3F0889BDEBE6ULL, 0xD32FAECFDBDD929FULL, 0x3F1D157F2D73C89BULL, 0xD696CB0A18874FAFULL, 
            0x0C0A7FA224AE4B06ULL, 0x40982B6A622C5520ULL, 0x7A6D7F7ED98B9630ULL, 0x56B135249C3859FDULL, 
            0x26BB703A73767E57ULL, 0xE5F854A7F89287E6ULL, 0x1A339DA478530A6DULL, 0x07E2D411C96482ADULL, 
            0x72932591FAE4C387ULL, 0x24DE16DBA2EB1276ULL, 0x0C17ED13C35B2606ULL, 0x1CC024FCDF603798ULL, 
            0x0A26CB34D028FB70ULL, 0xF39E10FF80E65019ULL, 0x06468DDB383046D9ULL, 0x97D879F1F985604FULL, 
            0x751A5B319BB1CE4FULL, 0x8DEEEB4759C5CCC2ULL, 0xFFE7655CFA55938DULL, 0x5BBBBF970F9C0C37ULL
        },
        {
            0xEA6005B52D083791ULL, 0x538223D5822C1755ULL, 0x33F25FCE8EA2592FULL, 0x39194B19B8ADF5ABULL, 
            0x83363EEAFB800268ULL, 0x12C8083F32402C44ULL, 0x819E93F88DEC70DDULL, 0xEE5240AEF7034997ULL, 
            0xA3A538E8818F3781ULL, 0x1430DF12A978778EULL, 0x58FFD452C25E7F78ULL, 0x70F887C0A9BC7519ULL, 
            0x688D37224823D5A6ULL, 0xEFF8F8AB7A19EF1EULL, 0x723A1E864BDF7CFCULL, 0xC228ACA25003459AULL, 
            0xB5A4283F94804901ULL, 0xFF5186E7B96ABBEAULL, 0x909417E54D897E0FULL, 0x28C0D37B9AA8E18BULL, 
            0x4EBBE1E745F19CFAULL, 0xE86B876C1EB97F4BULL, 0x7E06E1914B278953ULL, 0xA8DC8EA29F799B58ULL, 
            0x98905859C1DF22BAULL, 0x47257307751A3689ULL, 0x17B67FA386811306ULL, 0xCFEF6B5DBC89E7B7ULL, 
            0xC43F99230DF342B6ULL, 0x49CCD19335F32D4CULL, 0xFA0492BF763579D4ULL, 0xF42D484DB442ACD1ULL
        },
        {
            0xA1C635564C777A72ULL, 0x43C2E792B0AF26F3ULL, 0xAE229B5D927C9191ULL, 0x8D6CEC45C89EBD2FULL, 
            0x4DEBEC787BEF20DCULL, 0x28A18EC2886EF772ULL, 0xD4B5D8F154A0DD6CULL, 0xB4D3FADB4E9E66B9ULL, 
            0xD69CFEB51F82FC37ULL, 0x1D0ED60EDB51ECFAULL, 0xBB335FF6BB4E4F02ULL, 0x6313F8062C6D1A88ULL, 
            0x12B2DF2E0769D26DULL, 0xC040D9B872DD9556ULL, 0xAA352A7102D0413BULL, 0x1DDF9C544F49DB32ULL, 
            0x972E3A99851A8C81ULL, 0x96541E3B160FB0C6ULL, 0x024493674B71F4FFULL, 0x1F24FC25BB36302AULL, 
            0xACF7B36A7151E0CDULL, 0x03B16FDEA3BCDDD8ULL, 0x752561408B82230DULL, 0xC7B169FC3A9C9443ULL, 
            0x978905AACA0B0A3FULL, 0x096F688FB803E68FULL, 0x229BBC380D670D47ULL, 0x24EA6D599F0B4E19ULL, 
            0x1454A5665B0C81DBULL, 0x0C828001B945D9DBULL, 0xCBEC4C64CC0BB3C7ULL, 0x512A440B58D4CC6FULL
        },
        {
            0x4D270FB62EE1D6BDULL, 0xF9E32C9F1871043EULL, 0x37622049817029E0ULL, 0x24EF0BB5C7D91C3DULL, 
            0xB9CE8162BA44979CULL, 0x2A41186B0047DCFAULL, 0x98E2AF41DDC7D067ULL, 0xB8DBC582FB01AE20ULL, 
            0xD7739FE9CD9CE979ULL, 0x75BF7A43D15D3A47ULL, 0xAEF4AE59BD06C587ULL, 0xFCDEAFDB3038054AULL, 
            0x15EC50F6CFA28AC7ULL, 0x076B0D205F106DEBULL, 0xB3A246C80DCF5532ULL, 0x48BCAB105FA1186CULL, 
            0xA96B6485C6423CBEULL, 0x8FDFE354A35650C7ULL, 0x86471BFC67F4EEC3ULL, 0xBADD3966ADB716C5ULL, 
            0xE2F18C470D39843CULL, 0x804882C2C05D4C40ULL, 0x2E39E40646A44F94ULL, 0xE5EFA8B27DE67EB3ULL, 
            0x19AB5DD794E96F78ULL, 0x02853BD0EFB0DE86ULL, 0x3A11DC7FD2C867E1ULL, 0xB9C26518B1BDF175ULL, 
            0x04C643CA20E1D5DFULL, 0xE324CF3D55FFC61CULL, 0x9F4D96CF00AB1820ULL, 0x53B29E302455E539ULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseFConstants = {
    0x65158A461A259E1CULL,
    0x16725DC60F9A4E1AULL,
    0x549CF6DE1044E1E1ULL,
    0x65158A461A259E1CULL,
    0x16725DC60F9A4E1AULL,
    0x549CF6DE1044E1E1ULL,
    0x874831CFE50ECD46ULL,
    0xBF07210739AC60A8ULL,
    0x20,
    0xD5,
    0xEF,
    0x55,
    0xA2,
    0xDF,
    0xF0,
    0x8E
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseGSalts = {
    {
        {
            0x174BC48BC72A3FCBULL, 0x79BE207ED7B8EE30ULL, 0xAE65ADF04B3AF731ULL, 0x2A85C8F687786063ULL, 
            0x45A3B745C63A0015ULL, 0x5C8D1E4CF6B612C7ULL, 0x2E76C202244E4F07ULL, 0xCAFB9DA788865334ULL, 
            0x34112297821DE733ULL, 0xD2A50DA5F9821F75ULL, 0x1CDDD452496295B8ULL, 0x9B18CD7113BFAE4BULL, 
            0x55E4F9E77C51FC49ULL, 0xFAC4A24EEAEF83CCULL, 0xCC3767A620C14210ULL, 0x767372FE3B682B6FULL, 
            0xAECB6683B56A005CULL, 0xE91334AF1A017C73ULL, 0xB818C0D57188B508ULL, 0x11D74BEC6EBE7604ULL, 
            0x1532B3CD60823FB4ULL, 0xB55034848C8624F9ULL, 0x32CD6ADB1B3D744BULL, 0x562AD7A7768C1DF2ULL, 
            0x0467F8ED36B3EDF2ULL, 0x49C98249095B6031ULL, 0x5B8832ED77DD576FULL, 0xC00F42BB14C50CBBULL, 
            0x8DD9DCDA380AA62AULL, 0x85015C790D7D5450ULL, 0xEB2C7DE44272E999ULL, 0x0497300A81D91442ULL
        },
        {
            0x22E6B430007CF3F2ULL, 0x87552504B440CB22ULL, 0xA8720F3C0A5423AEULL, 0x654B7BA9CE97330CULL, 
            0xFC5A8E6019482F7BULL, 0x483E773718A19844ULL, 0x1468C1388D468C40ULL, 0xC0B186B8BE7A92DCULL, 
            0xD27B2279673F194BULL, 0x857AED7D07F5A21FULL, 0x7EEF065027AFE474ULL, 0x521BA40F98731485ULL, 
            0x87D1C8E2A4697524ULL, 0xA867644915EEFC2BULL, 0x9C145256F2F91115ULL, 0xEF5C7B4D56E39308ULL, 
            0x7D0D169231340BF0ULL, 0xC8D949480BC28EECULL, 0x4089D5DCF8460B38ULL, 0xA4145DF5AA4D2F6FULL, 
            0x59A0B851AA065F80ULL, 0xDAE2FCC7B0AD547BULL, 0x6E00A652275FEC5BULL, 0x3D1C2640203E5E00ULL, 
            0x283841E40695C7FEULL, 0xB86EF034C5150FE9ULL, 0x237527E4CECBC746ULL, 0xEF291A9779278C62ULL, 
            0xC2E1EA00A3CE0316ULL, 0xD702C5D9C18813F5ULL, 0xC93330CF41030502ULL, 0x19C7FC50197D188BULL
        },
        {
            0xECE7DC9F344E46C3ULL, 0xF3870DCA7704FCFFULL, 0x5704130B69BC31C6ULL, 0x6E0CFC6B4BEAC37AULL, 
            0x744A1F526C3903AAULL, 0x62401DB0BA99C15FULL, 0xA8FBE198050DD3D6ULL, 0x3B9DE2564B24EA60ULL, 
            0x34E6504259B9896AULL, 0x4EBD603AE56D5511ULL, 0xE176877B9C8A2B97ULL, 0x39A9EAF3C1AD5711ULL, 
            0xAEAED75F0C6DD2B8ULL, 0xA6A27956845FA521ULL, 0x051897EEE10D1A6FULL, 0xBC1B84769E7DB98FULL, 
            0x4B7620C814978D9CULL, 0xC0BE378E697D232CULL, 0x205371F18474E02FULL, 0x78BFFB0F844C36F0ULL, 
            0x1FBAA4A288774AA9ULL, 0xAF23C708BA69795FULL, 0x6DB06B7ECB9067DAULL, 0x5DFC9ED41787D8B6ULL, 
            0x0231D682525D1513ULL, 0x6A37BE66879F12E8ULL, 0x542E7A6C2D7DB902ULL, 0xF4E7A614C2351E90ULL, 
            0x3C94853CBE50A81EULL, 0x7C0610547B79D5DAULL, 0xF9D0F1DEBDEFFBFCULL, 0xD4600D5D3810E60EULL
        },
        {
            0xE7D023100AEE9E36ULL, 0xA96F598BE76DD4A1ULL, 0x09FDC0DA9FD17D31ULL, 0x7150EE06CEFA0604ULL, 
            0x34BF06A6C24AD5B9ULL, 0x94AFE9E91E2A08A1ULL, 0x9927E1787EA4B6A0ULL, 0xBE75B62809A5CAB6ULL, 
            0xEF64C1704DC1EF21ULL, 0x525133D45D31FCC4ULL, 0x30DE8CF673FDA7B6ULL, 0x26B217FD2424E5F5ULL, 
            0x6CC961723A8A7D41ULL, 0x42A1DA11BE6641FAULL, 0x1EC52F45EE665D87ULL, 0x123FA3427E261805ULL, 
            0xA334C84F02E5E44EULL, 0xAD87D4AFA58D0C00ULL, 0x0F4F872E3EB42CB2ULL, 0x4BF47502FDAA053EULL, 
            0x7C7607C56488C776ULL, 0x2636801718C5F08DULL, 0xDC61F67AE1123849ULL, 0x4D7C54CE514BCB0DULL, 
            0x84F4DFD3C18404C9ULL, 0xA4D11D745E67377BULL, 0x7A8B9E5B3794D569ULL, 0x82BC36F73F605DFBULL, 
            0xE4D73471CEA09954ULL, 0x6A0E25448B5537CEULL, 0xF27B8CA25F117E34ULL, 0x6364CF45AB900422ULL
        },
        {
            0x3E8F28E8E42AB629ULL, 0x4FCC9AB855B583FCULL, 0x34F6CFEB82B62293ULL, 0xD5449A7C2BA7FF11ULL, 
            0x355418D82BD05129ULL, 0x3CBEB7D5A0E77FBAULL, 0xF2960BCE3FD3B1E2ULL, 0x529385C9EC8E5FA5ULL, 
            0xC780685241EDF127ULL, 0x848C3F0426E3A62AULL, 0x0987FD600579A01BULL, 0x412CF96997A92E42ULL, 
            0xEDBDC6141CA92566ULL, 0xAA3E5E86DFE2C1CBULL, 0xFDFDA31B7F408A01ULL, 0x04F869C9F76A47E1ULL, 
            0xE8FB95ED5AF505D8ULL, 0x3645C2EE28AC8F3CULL, 0xA53BF2CFA298FFACULL, 0x6AB62B802197FD2CULL, 
            0xE54FA53421F101F1ULL, 0x168F1F4F8D919171ULL, 0xE5A94EADBE6F2B5EULL, 0xA754ACE3CB2550CFULL, 
            0x54A4CEC62CA098F1ULL, 0x9E3B2933EFF70D8FULL, 0x4003140647F510B0ULL, 0xEB9C6ECE76FCF846ULL, 
            0x5A947FEFCD3BB70AULL, 0x48C6787C0C18D4C5ULL, 0x00B549F84917BCDEULL, 0x3D98FB8031B90BEBULL
        },
        {
            0xD884988AC0E468AFULL, 0x52C5FB583EBF1415ULL, 0xCC12C3F72C24D5CCULL, 0xD43AA68A7E8F6D62ULL, 
            0xFE000BBD109FF066ULL, 0x0A861DD35BF7ACC0ULL, 0x508DF99E4881BB1CULL, 0x62F21181D0EAC171ULL, 
            0xADCB9571DBB1835EULL, 0xA135DDD4A6685D29ULL, 0xDEED0D7AAD13907EULL, 0x353A0FAAACB36E0EULL, 
            0x7CA4C03FE71757AFULL, 0x02CE16F9A03B100FULL, 0xF7512051DC29F132ULL, 0xBD90AB2A130BDACFULL, 
            0x381F43E350047F54ULL, 0xEC6B6A592093FA93ULL, 0x4A897EF3F3AC3BC7ULL, 0xD17E2A91BD5B644AULL, 
            0x4F96567991A48840ULL, 0xAE187A1A49F7798BULL, 0x9151F740BB1A4C90ULL, 0x1B4D4B8DB80DBAD0ULL, 
            0x69B99824233F6FDFULL, 0x82D2E78F946A8798ULL, 0xB05C1B563A9DC53AULL, 0x898B0C1B450C60F2ULL, 
            0xF21F82DF8B0F7C1EULL, 0x968552775ED5C98DULL, 0xECC5D6D4DF8B0AE3ULL, 0xF16D70E495C273FEULL
        }
    },
    {
        {
            0x08582396DD2ACFD1ULL, 0x60EE33D6F9B5FFFAULL, 0x121441F4BE004A30ULL, 0x10ABC454DD0480E6ULL, 
            0x09407EC9ADCEA70EULL, 0xFE602ED7C838816DULL, 0xC0671F9C861DA966ULL, 0xC54F7E68FC47400DULL, 
            0x7693A54959B725C4ULL, 0x4BEE8CD4A8D29555ULL, 0xAC4226A6A84DE62DULL, 0x5F390E36B0E75EF2ULL, 
            0x3E09AC1FAF5BC3FDULL, 0xD3D8254770F30BD9ULL, 0x595B972FD32AAB44ULL, 0x4733CAA89C6DDC09ULL, 
            0x9EAC636ACD4EFA1EULL, 0x9E3A11105A369E2BULL, 0xF7B67E171AD6E08BULL, 0xBC741960390486E6ULL, 
            0xB0C08070E64972CFULL, 0xE8652BBC3328BEDAULL, 0x2BB00C5322C37062ULL, 0x8159A9677353B17FULL, 
            0x1B35AC15161BCD52ULL, 0xAC9C3210A1F8E790ULL, 0x804294266F095BDFULL, 0x418EAC7D088C1B69ULL, 
            0xCCB6B61BF4C071FFULL, 0xB2B12E0F725FDC7AULL, 0x4128B9B3AF00ED17ULL, 0x82A2FC542F3B77C0ULL
        },
        {
            0x0BE573A4F65A668BULL, 0x7F5CC742EB39E69DULL, 0xF5B4696486E6566AULL, 0x9A929D6BD34F822FULL, 
            0x808219403B6C4FDFULL, 0x180EE10A0C85E7E8ULL, 0x2C176EE9B92160B2ULL, 0xC5F4A8214C288703ULL, 
            0x9FEB7E35FAC424A7ULL, 0x7657483F6612CCBCULL, 0x3F394156CE23D366ULL, 0xFE2C9BFA8544D7B3ULL, 
            0x51E4E5422BD2874FULL, 0x8ADAB374E75C685FULL, 0xAF9A51BCD74188DEULL, 0x96E231F4D49E84CCULL, 
            0xCAB8F3A69A33445FULL, 0x5EECCE674C8D0BB7ULL, 0x909839EF7783F214ULL, 0x8F54056CE78B6470ULL, 
            0x57325570670A83A4ULL, 0xBFC78204B5B481F5ULL, 0x790F74B86D928904ULL, 0x2E1A5988F679F7BFULL, 
            0xB4A176816FD46CD4ULL, 0xFFD608CC78C71DFBULL, 0xB2483F07AF3BE3F8ULL, 0xAD2BD1F1A04729E0ULL, 
            0x4F91FDCA43B58CAAULL, 0x81FE23638B10224FULL, 0x14B6E6FDC5FA10F5ULL, 0xED45E437B2AE50C2ULL
        },
        {
            0xFFFFDFFF851F7036ULL, 0x52FBAB11F2212E7AULL, 0xB616EC11776F61A0ULL, 0xBFBEA9D0AAF63A98ULL, 
            0x3437C7F1E0ABAB50ULL, 0x84B01797379523F6ULL, 0x6A480740B3B86F00ULL, 0xC27EE2870FECFF21ULL, 
            0x2BEC75EAE0382639ULL, 0x27B8101F5C8D41EEULL, 0xDF408435318392E1ULL, 0x33C54E789E530604ULL, 
            0xA45795B4313455DFULL, 0xAB1585CBE794DA0DULL, 0xE50CD4463D2E9351ULL, 0x19CC068AB483DB27ULL, 
            0x5B04124461FD3941ULL, 0xBDD9EBAEF2009370ULL, 0x45F69F55B3C85B45ULL, 0xEF0238A3E27628CCULL, 
            0x0A389369FA3997A7ULL, 0xECD338E9826747E4ULL, 0xDBDD516985199525ULL, 0x0F972C79EBDDE632ULL, 
            0x9CBECDDD466EFF7AULL, 0x2BC6CB2262C4C7E4ULL, 0xF5E6F589CAA160B6ULL, 0x6AB0C1D6A248F0FCULL, 
            0xE7B28535FA2391E8ULL, 0x5822C5E70D6079B3ULL, 0x0928C1131FD427A2ULL, 0xF88B8CDCE0EC98D0ULL
        },
        {
            0x25F6251E6FB7BBEDULL, 0xA8F514E721A46D39ULL, 0xD2AF75CE9F8464A1ULL, 0xC85D1F6259418BEBULL, 
            0xD5C20037C63BD853ULL, 0x7D368AB4DAFD4C3CULL, 0xDBF27182FA0F2E2FULL, 0xB1D420FE4CB7C933ULL, 
            0x105AE68753FC86DAULL, 0xBEFFA53A52AD83E2ULL, 0x42F1AD67FEEE8AB6ULL, 0xF3434FD117209951ULL, 
            0x49A4BF9982BA354BULL, 0x9DC95FC4A72082C2ULL, 0x5F2D699C75D7466BULL, 0x15CB76D8E34B6819ULL, 
            0xA1E23D6130F3F439ULL, 0xDB1B00C34EDB22DBULL, 0x95FD49DD9FDF4FAFULL, 0xAA987D8A6BDF89DFULL, 
            0x12F05C0C629E7C7AULL, 0x1A38551B157C6A7CULL, 0xD0E5C003DD64ABADULL, 0xD9484616C6452B7CULL, 
            0x8E352F363635440CULL, 0xEB425F2F53E1FD75ULL, 0x757ABCDF05B33681ULL, 0x3C449E97A20480E8ULL, 
            0xBEC43B26B7604E82ULL, 0x44331C817C97AD28ULL, 0x99E498A85F62C12DULL, 0xE3B188FCD40E9E2EULL
        },
        {
            0xEC41847497D8AC7AULL, 0xE77B10A3C6922DBCULL, 0xD810C834DE79A562ULL, 0x7A4DD967E6AEEA86ULL, 
            0xF0DE666673923099ULL, 0x57FA51CAD72642F1ULL, 0x4591C7D9B26C5A16ULL, 0xFBD9AAEDE0A4B5E2ULL, 
            0xAF9CAAC4EF138C8FULL, 0x763FC03D2E9FE9ADULL, 0xDA553E965A1B54A6ULL, 0x06CF8765F5E644A6ULL, 
            0x5991AB5293946078ULL, 0x5CCA41DC5B6C34B5ULL, 0x106221187EAFB570ULL, 0x49B780231D52B276ULL, 
            0x24F6757BCB97B974ULL, 0xF4262ABC6C938AE0ULL, 0x3377152BAD76442DULL, 0x5E47DCCAA324083BULL, 
            0xA6E973854ECC791DULL, 0x7B2E222AF0DA4F8AULL, 0x6C1F00B3627E2466ULL, 0xC5F2DA1E8D111134ULL, 
            0x083A37A228DC9EEBULL, 0x94D99981D1FD2C96ULL, 0x52CE97095A8D63D5ULL, 0x9915F898F23B3996ULL, 
            0x28595CFF82350FFEULL, 0x9EA5EB0575FE0705ULL, 0xEBF77691CD514853ULL, 0x1DEE6264F8602531ULL
        },
        {
            0x332043FB5FDEBD20ULL, 0x55910054DE232E6FULL, 0x8C2865BF88C609CEULL, 0x3FCA5EEB22AA072BULL, 
            0x5ED1F32E99FF9CC2ULL, 0x1681889E7CE2599AULL, 0x9E439755A67D1DDAULL, 0x561C64EABEA2149CULL, 
            0xC0583AFFA5B17805ULL, 0xE4FD2020CCEF05C4ULL, 0x2735DAC654559829ULL, 0x8D198BAE9A24B5BDULL, 
            0x5C7B45742C65EC11ULL, 0xC38D0C0467A81D13ULL, 0x893E00421B818A6BULL, 0x51D21351752AA20FULL, 
            0xC7F6481BBB0261A7ULL, 0x9E0ACFC36C0F31FFULL, 0x2ABE5B2195F6EAC9ULL, 0x01B70EB5F31CEAE6ULL, 
            0xFF9B05A591BE9B21ULL, 0xA5F0CBAAC2108F6AULL, 0x0707916854B08D34ULL, 0x8D25DE38BB025692ULL, 
            0xB910153D0EF38F8EULL, 0x0C8B581C6D942A63ULL, 0x4575AE9ADDC31BF7ULL, 0x2DDE51282E5EA425ULL, 
            0xF45280DEE76AEE3BULL, 0x3DB9FC1D5A469281ULL, 0xCC8A9E86F95EF113ULL, 0x3566A52A5792C47AULL
        }
    },
    {
        {
            0x4757CB3BAF3647D8ULL, 0xD05BCE6EA690B7B6ULL, 0x2ED6EFD5F5CEE3DDULL, 0xDA52608A00E2845DULL, 
            0xB7EAA99FEB83CFCEULL, 0x264557FCD7DEA95EULL, 0xC007C23FBECC08B0ULL, 0xDC8D4BE6340F8183ULL, 
            0x40690AA904A38184ULL, 0xA707FD3C33BAD928ULL, 0xC7D1C7F5455EEDC2ULL, 0x9DFDA3CB136B0FA9ULL, 
            0x9A287B850CEE3C1EULL, 0x9235D1D81BC7E9F4ULL, 0xA81D3BEF56DF129AULL, 0x87A8068EB2A7E0EBULL, 
            0xC12A985CC1176061ULL, 0x81AEFA0F0ED94B6AULL, 0x0F28A1867B248A68ULL, 0x4F7D3990B27CB7CFULL, 
            0x77AB511924E8C42EULL, 0x85062A8EB63585A0ULL, 0x254C671CE8AEFE47ULL, 0x7ACF060FAFD52FF0ULL, 
            0x51E4AAD4430B0F1AULL, 0x27585CB1F8402D4EULL, 0x8FE601B5AD9E0128ULL, 0x40D2CD808BDB9915ULL, 
            0x6CA271BB9482A0E7ULL, 0x470C42D2224F7A31ULL, 0x13EBACD060F2B0B1ULL, 0xEE5AB7CE69D58C99ULL
        },
        {
            0xEDE751D49951C811ULL, 0xE2F15F737636BDDEULL, 0x9F017BC8464F031AULL, 0xB07898E8A0AC923EULL, 
            0x7C88FE359A0B8BD3ULL, 0xE8E0234BCC6BE931ULL, 0x8794A53D29C492DEULL, 0x905491A528108C2BULL, 
            0x1A0B443FA21653AAULL, 0x2C95330AFD9E7833ULL, 0x03E48E42C30E7F23ULL, 0x20A3A13F6559F9E7ULL, 
            0xCF2544999DD761D1ULL, 0x8CE45FAF3C3DCF79ULL, 0xFFAC9210932F8B95ULL, 0x73E9ED9E2F3D537EULL, 
            0x92A8F2AD0C161096ULL, 0x92EF15E5C50A91EDULL, 0x36BE0193961DCC30ULL, 0x49E8B2C4F9548958ULL, 
            0x17FC320669589AF8ULL, 0x3EFB50F8D0227552ULL, 0x14F4B797701887CBULL, 0xA26A7BBC3A8B4ABDULL, 
            0x4B9A3BB9CCEC6324ULL, 0xE8EC6188F8B3D9A7ULL, 0xF68E6DA82F76C1F8ULL, 0xBD920C93F7CB5291ULL, 
            0x46AF6471CFEFB160ULL, 0x2F10BA1A97072315ULL, 0xBE9C51E8F077E121ULL, 0x40348ADAEE90140EULL
        },
        {
            0x64D9F448E3254EEDULL, 0xA965D07EC2D48912ULL, 0xFD4962DFCAAD36D5ULL, 0x1119D0EE5C3BA620ULL, 
            0x4B4E5CF99226250CULL, 0x6AD95AAFD1DFD0ABULL, 0xB9CC25BC6B5078A7ULL, 0xDE26EDEA122FE705ULL, 
            0xF88F689C84B988B4ULL, 0x1EDA6443084440DEULL, 0x5C1F6591898371B1ULL, 0x49A6C0FDB87502A3ULL, 
            0x300E5088C746755AULL, 0x2ECE49A448003883ULL, 0xD35914C3BC1E2FF6ULL, 0x04E074FD340AA818ULL, 
            0x2422A6A87B22DB86ULL, 0x2EFFB4C63A67C8EBULL, 0xD2F138844987A354ULL, 0x36D7D073D12C2176ULL, 
            0xA81188D7EB794645ULL, 0xE028CF5D3C90F60DULL, 0x1A0E9AB02B5AEDFEULL, 0xD560A0905D8F9355ULL, 
            0x573B76876D6011E9ULL, 0xBB70622936C0926FULL, 0x105EAA38D399C9B4ULL, 0x599739E239A56EF7ULL, 
            0x53B956406890F24FULL, 0xFBD8027CDC00CC8FULL, 0x082D90B4C8D8E02DULL, 0xBC0E3DB84A3841D0ULL
        },
        {
            0x18785CAC4382F3B1ULL, 0x2B3E5B17F790D849ULL, 0x08581F96F3B508CAULL, 0x97D06EACDF6275F5ULL, 
            0x80F4CADC1145BC0BULL, 0x3237BF8762E597FDULL, 0x18CC07DC76018CF0ULL, 0x7C7794DD0FCACA55ULL, 
            0x3E788D99BAE0D949ULL, 0x1E70061C890CD671ULL, 0x93635C22463750EBULL, 0xD41E4904C3C28A9FULL, 
            0x04897C4C10C72399ULL, 0xF272970758AA1926ULL, 0xE4FBF11ED7FD445CULL, 0x4BF0BCAE5113D711ULL, 
            0x2F6E0EF0E98274FEULL, 0xAC4C1161C459E012ULL, 0xB8CAEA62971EDB6FULL, 0x6876A95608A3B4E8ULL, 
            0x6DF6FC545026210AULL, 0x3CCC79B798E0B920ULL, 0x3A5B15F9F9A7B732ULL, 0xFA9AF0A1E5C6F2CDULL, 
            0x8A6360D4FF69BE44ULL, 0xAA95887634492E67ULL, 0xB6818828CBC48796ULL, 0x776B43F83D5D38F3ULL, 
            0xB872C6099888CEA8ULL, 0xA543F0A8D9EE7DD0ULL, 0x61E05A0FA705B74CULL, 0xA6C8091FA7F9F2ECULL
        },
        {
            0x440CD4D2B2094CD6ULL, 0xC4F9044CA114662AULL, 0x7D91314B5EA186C9ULL, 0x778213FA09C329DAULL, 
            0xDB2E8A0C3DE4043AULL, 0x59ACEDF472EF6D53ULL, 0xBF6CA507CFD4F6D1ULL, 0x2C361F69980F5A4FULL, 
            0x42D816BF6ADCD779ULL, 0xAEE928C63E28DE31ULL, 0x0C13BC1726AB15F0ULL, 0x11C6B36EB59F1435ULL, 
            0x7C20FEE8647B61AFULL, 0xE355A711BAFE8557ULL, 0x034CF1197337109EULL, 0x6FB5EBBBCCB97D18ULL, 
            0x30FC77793A5E9CE0ULL, 0x4D3BD98BB570DD90ULL, 0xDBEA8D587F77B268ULL, 0x913AB62489A8C5A8ULL, 
            0x97C11E645B52647EULL, 0xFD593AD4C736309CULL, 0xFA971DF49EE9EBEDULL, 0x9CF72CB80B366EC1ULL, 
            0x07472E7FE74C9D46ULL, 0x932F90561CC5F196ULL, 0x6D9037C2DA5BFDB3ULL, 0xAAD3FFAF05CD0A6CULL, 
            0x3209C74B92A64F37ULL, 0x43C5539B6D6C761AULL, 0xEC73DD2A8AD90068ULL, 0x2FE9B2B686A369CDULL
        },
        {
            0x9F2879D1A5A5A205ULL, 0x858F11A2394B2411ULL, 0x24D74ECF5455914DULL, 0x735E70EEA7AAB62EULL, 
            0xD086E4CEDE4A4DC9ULL, 0xA341895DCCA69DB1ULL, 0x5E081DB6CBCC1063ULL, 0xADED0742A1E28BABULL, 
            0xD5F6E6CA933193D9ULL, 0x8104E7112B4DD24BULL, 0x5C7E57B9DA80FD05ULL, 0xDDA02D62E3BBB04BULL, 
            0x2E53541742D63F59ULL, 0x8DCE07D5D9054015ULL, 0x4009AEFB8EF174A2ULL, 0xCAEFE08BFC27B3C9ULL, 
            0xCCA075B404C16D04ULL, 0x4A57B56154A7FC4AULL, 0x14D78F26921FE6EEULL, 0x1C5B7ABDF938501CULL, 
            0xDD05869E21C4C808ULL, 0xC82D2300859F5D4EULL, 0xA9307FF0A2A90D69ULL, 0xAE7986BBD3753590ULL, 
            0x3EAE0D817D0DD7C7ULL, 0x562D2A01ACBF4B73ULL, 0x8A2F9E18C9AED14EULL, 0x7601572ECA82F411ULL, 
            0xD6D15C807A76282FULL, 0x000BDF6EB467DA92ULL, 0x826888EB74D33C36ULL, 0xE2497EC97A2782CFULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseGConstants = {
    0x225E03D65F43BAC2ULL,
    0xFA52E2FE9BAD91B8ULL,
    0xE00D448ADC8EDD5EULL,
    0x225E03D65F43BAC2ULL,
    0xFA52E2FE9BAD91B8ULL,
    0xE00D448ADC8EDD5EULL,
    0xDF44C4385C03BB8EULL,
    0x450DE9D542D5BC32ULL,
    0x04,
    0x12,
    0x7E,
    0x51,
    0x68,
    0x84,
    0x25,
    0x32
};

const TwistDomainSaltSet TwistExpander_BaseBall::kPhaseHSalts = {
    {
        {
            0x800A35ED6E5B8882ULL, 0xD49D270B3C657B2FULL, 0xB95E0965BAA2F8D5ULL, 0xC1D5D4F3607AA8ACULL, 
            0x8E7CA673C06E5177ULL, 0x2A4B9AECB2FCAE44ULL, 0x6876B93D5D01F025ULL, 0x3DAA2556A0436553ULL, 
            0x77C9EA254C9BA132ULL, 0x5109F9274D4DE6D8ULL, 0x6D77F5FC0DA357D1ULL, 0xC146A3FDC7D3B5DAULL, 
            0xF850DBA5F445D717ULL, 0x09C869499D2AA80FULL, 0x5D476967636FCA3AULL, 0x3FCE22785012EC83ULL, 
            0xDAC709B022AF5AAAULL, 0x217AE2F2B33F869EULL, 0x496CB8F7AAC1418AULL, 0x365E20757A6633D9ULL, 
            0x8C963B51813247D9ULL, 0xABDC69AB327CE359ULL, 0x1AC106DCDC0A5B87ULL, 0xB291F01024EF124CULL, 
            0xD66FFB97D81D9D56ULL, 0x183F98E6B6008399ULL, 0xAAE511C20ABC2DBFULL, 0xFAD48F32CEFBF47FULL, 
            0xE409AFBE908BB069ULL, 0x1DE1ED9332312BC7ULL, 0xE4BF8C597A890C82ULL, 0xA290F19DFC5E6F82ULL
        },
        {
            0xD07E7B767E067A20ULL, 0x01A98CCFD529E1DBULL, 0xB2965F4819D20F6FULL, 0x4537A7C7D9F276B9ULL, 
            0xE7BA7655428F6E37ULL, 0x4DF47E8DE6D40C43ULL, 0x864BD04BDC55FC21ULL, 0xB01440D76DEDA98FULL, 
            0xD6C275E279F2D4E1ULL, 0xEEA5B108C073FDEAULL, 0x0A734C3CD4E37AE9ULL, 0x030E7C7B065F988FULL, 
            0x4BD13A0BF82BBDEAULL, 0xC5D15C062FDF2782ULL, 0x5BEE538BE8B24D9EULL, 0x15967CF0DE6C1C7EULL, 
            0xAF19917863937117ULL, 0x8962E813BB907BD9ULL, 0x6FAF6DA401F6F290ULL, 0x8A640884D6876318ULL, 
            0x7F368F06482F28A6ULL, 0xC15C86985DC0EE10ULL, 0xBBFDAF579901ECE9ULL, 0x380C912424C8702DULL, 
            0xA6C8AE507D94CFC2ULL, 0x924CD58815FD4DE5ULL, 0x8615D8D3387AB883ULL, 0xC4CE09356B8A2B57ULL, 
            0x5FDA6959B6C8D3C5ULL, 0x225053C3D26B5FAEULL, 0xA672DBFE4FF26ADBULL, 0x3F60C53B70CC348BULL
        },
        {
            0x5F9564A4FC2BC573ULL, 0x8C901F384502C9CBULL, 0xCAA53A9F2EBAC3B8ULL, 0x7600961384DC2A77ULL, 
            0x800F763C8242C582ULL, 0xD5BFDC198E6F607DULL, 0x0F1A15F7AC6EFEA5ULL, 0x4FFE02837575EC99ULL, 
            0x6652E238F90BA4DAULL, 0xC1ED32A322D6AF0CULL, 0x8ED2C7621CAECDF2ULL, 0x9346D696EA2BD68EULL, 
            0x9F27F8733DF78DF7ULL, 0xF71DB1AD7DE4326AULL, 0x37FA35CEF9ED6610ULL, 0x8C9CAB15B2DAD294ULL, 
            0xC1A38FB061DC7E24ULL, 0xD702206B4F833A11ULL, 0xEA33EEC65DA483DDULL, 0x13E11795B2CBB017ULL, 
            0xBECB5B2FDB621AE9ULL, 0xD8101F2DB32037C0ULL, 0x58D2D09987701841ULL, 0x59EF0B26DAC1E519ULL, 
            0x70AC4F24800BA77BULL, 0x5ACB6F61089D43F1ULL, 0x3AEAB2DFC9CDE3F3ULL, 0x6553F949CB194E64ULL, 
            0x23DFE1A3A375C3F4ULL, 0x2FF483EAE4DF9D6EULL, 0x5F6F027B6A8C0767ULL, 0xC9D61711F77B1AE9ULL
        },
        {
            0x56F12BC646570742ULL, 0x8DCFC892C0AE0089ULL, 0x744ACEAE094F5DACULL, 0xD173820CE9A200A2ULL, 
            0x0056FE7B71B9FF54ULL, 0x6D25A1E3BF2943DAULL, 0xE19A900338E041A1ULL, 0xF7E0137BE9E9A65AULL, 
            0x6B95289E056DC4CEULL, 0xE3775835C45B7788ULL, 0x26A239997A394264ULL, 0xA6FFCC98FED63D15ULL, 
            0xE001C064049205EBULL, 0x660AC2BC68CE5D7FULL, 0x04831B970105F5D5ULL, 0x64A77F8E57B93508ULL, 
            0xF6FCC5850184C5E1ULL, 0x2847B605EB74FED2ULL, 0x2E142DF8F3CC75FDULL, 0x6C00FA71F12F3092ULL, 
            0x51B36605F7A48F8EULL, 0xE7D660B2C9492AB1ULL, 0xFF854A2343D79B99ULL, 0x104356CEB36AAEA2ULL, 
            0x558AF14F6965446EULL, 0xEAE55019B6FE0FC6ULL, 0x7E16C2C05996CC8BULL, 0x11875FC3EB98BF34ULL, 
            0xB53A20B599AE37BFULL, 0xF997122BF5C25C8AULL, 0x76222B0B883C971EULL, 0x1EF4D228E3691EECULL
        },
        {
            0x9B3C1D7B2D0CD0A9ULL, 0x80CF985A0DC02ABCULL, 0x4B221D6DBA69E559ULL, 0xE3310222D8537469ULL, 
            0x7E26B8A205BB8EDEULL, 0x0781333CADAA528AULL, 0x4A0E7B596A70371EULL, 0xD05011D613DA65E3ULL, 
            0x0186D4F171DCE1DAULL, 0xC2D5D284421E420FULL, 0xC7E758CEC0F26581ULL, 0x2B4A9E8F1AE08CEDULL, 
            0x8B5AAB964C182131ULL, 0x7B9BC815A9419F9EULL, 0x2ABE420DDDEBC7A8ULL, 0xAAEA1E71A96EDE42ULL, 
            0x76EFF2EA78AF1342ULL, 0x91557B5757256F3DULL, 0xA61A2EE40ADC2EEAULL, 0x937B616E2F813465ULL, 
            0x46D0DF4DADBD39ADULL, 0x76F52DDA544C1B39ULL, 0x71C377181406816BULL, 0x80FDC6ED8350127DULL, 
            0x210C1DD07119A5FBULL, 0x2CA1D45C64E532A1ULL, 0x1BE00428BED204B0ULL, 0x8A9E1D8868D2E864ULL, 
            0x41DF190FD59320E2ULL, 0xBB3D19E9E3FEF8BBULL, 0x60B140A746EF7788ULL, 0x33BDAD95FD012487ULL
        },
        {
            0xF8AD752AEFF74413ULL, 0xF2C3E7F8C1A4BA9EULL, 0x0D64E9727620AFF2ULL, 0xE885CB416EBD418CULL, 
            0xD7655BBFD3CDBE47ULL, 0x86E1CE946A5F4E32ULL, 0x8B9A32C6920AE0DDULL, 0x4EBC611C00BA155FULL, 
            0x19462B928F1E93FAULL, 0x16B724A88487B6E7ULL, 0xD6900BF9C27E4801ULL, 0x0A383B25B1DB85ACULL, 
            0xA95A0238F7219332ULL, 0x4862C7FD5F4B4369ULL, 0x870EB4B93809EA6FULL, 0xC6DD655E64F09767ULL, 
            0xAC9D96DF7795BC65ULL, 0x28739F815E4E0343ULL, 0x1971B8131CE2F98CULL, 0x8E6AB869969B01D7ULL, 
            0x28F0B6D6998EE52AULL, 0x9E303DB1B264631BULL, 0x24A4347C606819D5ULL, 0xE244EA59B8EFA789ULL, 
            0x2161644BE9A3EA57ULL, 0x5DA81E0757AF3960ULL, 0xFE992BBC035DAA63ULL, 0xDDAF928491A1E5EDULL, 
            0x2A0FD10F9004C070ULL, 0xD4CC72E44C1CB102ULL, 0x5F9172EEEB51346FULL, 0xCA5C3097889FA84BULL
        }
    },
    {
        {
            0x48791EE72FEE0DFDULL, 0x32042B90B4C5A210ULL, 0x345349E763EB118AULL, 0xD4D062DD12D24FF6ULL, 
            0x56223F132447C042ULL, 0xE1E0CD3224B2A2F1ULL, 0xA2D53A406FD81A3AULL, 0xC5795E19D053DB46ULL, 
            0x5CDB5D6CE17A0A2BULL, 0x190900BB8E2015B4ULL, 0x1C35CB7BADD118F7ULL, 0xFF3F59BFC3038F19ULL, 
            0x5920DD6A6997F80BULL, 0x51448F52FBACB32FULL, 0xDAA5B658AD096300ULL, 0xB5CBC9D7358C0CF9ULL, 
            0x10E11B8D32E060D8ULL, 0xC87E56FEAB968BBFULL, 0x581FC9257037546EULL, 0x74E9A1920C6DDE3FULL, 
            0xAA832E47EE6BA959ULL, 0x7B52865B8DB822FFULL, 0xA1EC044216C538A2ULL, 0xDC047ADF1335240FULL, 
            0x7DB460A1215D6E62ULL, 0xB92B753465B9D09FULL, 0xE111DCFEDF46BAB6ULL, 0xEE26E721EBF10CEEULL, 
            0x0E8FCD3327C3A512ULL, 0xCDEABB58363DF2D0ULL, 0x59958544E1826F5AULL, 0x37ED50DCB71BE697ULL
        },
        {
            0xD2DDBD311C35EA1CULL, 0xA76F8B36E6D4A575ULL, 0xBC22B5EFE20619DCULL, 0x641F8882ECD4C64BULL, 
            0x1D02FF97561DC5AEULL, 0x8140C5270D75C7A4ULL, 0x7ED676F89892F733ULL, 0x98EC2C97A2BAD714ULL, 
            0xFFD5EC038C0D2A1BULL, 0x2AC1298D2056457EULL, 0x6E263E9F59020992ULL, 0xBDBC403C812B9BEAULL, 
            0xB43EFE5218FA39FFULL, 0x868F2A82D67D9A92ULL, 0x83E92656856F6983ULL, 0xC7D502C50ABF1BC5ULL, 
            0xB25508FBEDDC0BCCULL, 0x867EDEB25E903F66ULL, 0x085C5B0ECB45B4AAULL, 0x50E2BBBBD4793A91ULL, 
            0x026BD7FFF88D932DULL, 0xBE75CFB6DB9D2FC2ULL, 0x04F8C156E216E59AULL, 0x8EBDCF6CF23B67F3ULL, 
            0x3349076E2014EA4FULL, 0x49BCE9C3687DF0D3ULL, 0xE5A626B404973E4EULL, 0x7FEF56FB9A8650A8ULL, 
            0x2E108805A7063C81ULL, 0x4660EF5516EC6FE3ULL, 0x20AC0B9718521A0EULL, 0x263F6DFFA4D6AB45ULL
        },
        {
            0xEB87C5E963CB77DEULL, 0xF8A68B4E3F0786AEULL, 0x5BDBCBDC70B17524ULL, 0xEE8BC751CD3E57E2ULL, 
            0xAF5E39E5BAC5105DULL, 0x93C8BC3E562AA88AULL, 0x5F74C9755235BEAFULL, 0xF61547C6E175C651ULL, 
            0x7565B333164B34BCULL, 0x5D499456640DAE0AULL, 0xBCB3116FF85F0A80ULL, 0xDF2C88AFFE41BE64ULL, 
            0xC7F75D3ADCC09DA7ULL, 0xAE360EEC17071384ULL, 0x06AC7074C8F79EFEULL, 0xCF969D4A8083E598ULL, 
            0x1A01D26CC540F151ULL, 0xBF206F36EDD0D7DAULL, 0x2F581C21D8200EC5ULL, 0x30046CB9CCCA2B3CULL, 
            0x04391833C388A4D1ULL, 0xE9E8E87CD3CFE339ULL, 0x022CA0700AD61973ULL, 0xD324CAD44EBD102AULL, 
            0x295BAE8796816420ULL, 0xCA279D3AE5C9514BULL, 0x248D7D85796EF6C1ULL, 0xEA3733E36BFE9B5DULL, 
            0xD7A02D10B3A03AA5ULL, 0xA6AB9EFB02221AE2ULL, 0x0BEF33397AA4086BULL, 0xE050FB20BDE76DB9ULL
        },
        {
            0x8DB08C6AED66AE88ULL, 0xDD5C758D933E52FFULL, 0x2E412F51E4A0C67EULL, 0x46F6788BC2037F74ULL, 
            0x9DAD6291809B8D24ULL, 0xBEF93DC1A538E366ULL, 0x1D32C04D1DE75116ULL, 0x540A483A1033C1F1ULL, 
            0x502CFAB1B63CBE20ULL, 0x7A5FDEE30B741771ULL, 0xD05C67AD8AC2445FULL, 0xB26978DD92331557ULL, 
            0x9F4E43CB51F43678ULL, 0xB75886E39FF74553ULL, 0x40F955E9948FCF71ULL, 0x248DDDD99599A793ULL, 
            0xD09EF4120A9BFEB4ULL, 0xBAC2259EA02BBEE9ULL, 0xAE6FEBF43C90C0BAULL, 0xA23C29786E77408DULL, 
            0xF7F2ED1864E1BA3AULL, 0x8D5D27CAADDF6C65ULL, 0xF5A6BDF2E8A28AA1ULL, 0x554A5A8E4B038E41ULL, 
            0x5BAA13D12B971303ULL, 0x59A6E6C109623385ULL, 0x751772E0F78E245AULL, 0x40FC32295D557DEDULL, 
            0x6BB2AFAE83712905ULL, 0x49489334F1EFD707ULL, 0x819EF8D0787FA729ULL, 0xA9372904E8476A32ULL
        },
        {
            0xDF4E53ACEFC7A08FULL, 0xE7473B17990652A6ULL, 0x80FF22A701C64910ULL, 0x8ADC6D54776E56D8ULL, 
            0xF32EB801E5822047ULL, 0xDCEF50BB2AF9CB5DULL, 0x963DC464F2CEF441ULL, 0x6388F903D9C4813DULL, 
            0x94879D64D644587DULL, 0xD84B732F4C72EEB7ULL, 0x6A56081C3CA500ACULL, 0xC64B0A28462E4686ULL, 
            0xFF8C0BA78E6ED086ULL, 0xF4D5C3A1C6927CBDULL, 0x4522606EE41B0518ULL, 0x50CFE080D72D309DULL, 
            0x7488E2992F62B31DULL, 0xEB2DEB74F83545BCULL, 0x578B04AFCFD6AF05ULL, 0x32B3C6B869A8C438ULL, 
            0x85F39FA81D9F8F4AULL, 0xEFE667473E6B8396ULL, 0xB3A753824F9727C0ULL, 0x91FC54A5CC5C35D5ULL, 
            0xFAFA9A79B78EF648ULL, 0x08A90CA72A40BB68ULL, 0x7D081495B7193693ULL, 0x9CB70AB7D1BB8EC9ULL, 
            0xAAD7F370B3A4653DULL, 0xE5CCED26F2B97D9CULL, 0x53A3E9DDE23F46ABULL, 0xA41A1A44A926E375ULL
        },
        {
            0x0A70AF09F6E7D4C4ULL, 0x3FAC6FF032BC5A35ULL, 0x35114CEDF2B0B814ULL, 0xBBF19727A2147055ULL, 
            0x058B55FFFF6D742EULL, 0x474063B7478960DEULL, 0x2104C90FEA5F9497ULL, 0x79685DBFF79498B9ULL, 
            0x39E6E13A114F0660ULL, 0xF4F2A41342E9C5B3ULL, 0x33C8687EE4B373CCULL, 0x9A44EB4DDB1CC54FULL, 
            0xCE19534652671769ULL, 0x3A58B43830F6CAC4ULL, 0x57A855FE4600B3B4ULL, 0x2D835ED53630F7C5ULL, 
            0x25FEE9EC13214656ULL, 0xD3AF22CBF13AF0F6ULL, 0xCA3E809391ED7A5DULL, 0x4FA42ECE983A4127ULL, 
            0xA91346BCCD5CE0E1ULL, 0x1C85E32E0DF18597ULL, 0x86AA17FF72D3EF4EULL, 0x45F21690BB324F3CULL, 
            0xB62BC70DFBC85AA9ULL, 0xB6F0B8714F6FC5CCULL, 0xDCF2A29E216ED649ULL, 0x510DC25CD7E08F35ULL, 
            0xFF0B7611A9AA04C9ULL, 0x0985F0BB91538DB7ULL, 0x35E8E7FE8C4D0554ULL, 0xCC4DDFF72A10BB8CULL
        }
    },
    {
        {
            0x0F4C1AE38F4A012CULL, 0x4BC869A458A5E07AULL, 0xC1008D0A2F312218ULL, 0x38B716992F351117ULL, 
            0x1FC49F3CC000194AULL, 0xABABFE998E2C3442ULL, 0xD7A69E442FA8FE61ULL, 0xF5C9B21322007D91ULL, 
            0x240A61BB97214480ULL, 0x72C6978789804564ULL, 0xABDA785521B9E951ULL, 0x70B2AED36512A690ULL, 
            0x527DD3A292D7C303ULL, 0x624F4547877A8852ULL, 0x12896B2DDCF8EC02ULL, 0xAF24E98B9F20235EULL, 
            0xBA02D70E398BEB69ULL, 0xA333CF6A7BFFD015ULL, 0x58C2CDC4A2E61CEEULL, 0x8C6881B8A503FB58ULL, 
            0x4EEA0006395D5CCFULL, 0xA0FB25CD67B8233EULL, 0xD954914FBD688E64ULL, 0x746F4414DBE880CCULL, 
            0x7C215A07B7F2ACD6ULL, 0x8A7E5A1D0972C97EULL, 0xCBBC1B0C5A1E2981ULL, 0xA6D51078223B25B6ULL, 
            0x99D5BC5F03D27DB8ULL, 0x8ED89A04438A7959ULL, 0x8D3571DC9446F9C2ULL, 0x531A0376A9066DA0ULL
        },
        {
            0x2B02F6791E585F0AULL, 0xA78F7EC08324F56CULL, 0x8968423B562A8669ULL, 0x22A602DB581FC17AULL, 
            0x806BC3CCCE03777DULL, 0x3893AD761D65B339ULL, 0x0131612A044FCFCFULL, 0x17C243813415ED68ULL, 
            0x2A5B749D144EA285ULL, 0xB76F2736280B1A42ULL, 0xAFB834B20F75C36CULL, 0x9809D4B55783D433ULL, 
            0x5BEF7A5C1FCEB552ULL, 0x51691F5F503DA0B6ULL, 0xDE1F4187D323263BULL, 0x1B93DE1A4B8A1771ULL, 
            0xC6BC474E72E9761BULL, 0xB08DE0B2F7326961ULL, 0x04F3740FDF096278ULL, 0x6BEACD88A6E72111ULL, 
            0x1C5A91B2E614D979ULL, 0x743FFECDC550ACFCULL, 0x1F167A7E4F83806CULL, 0x61B9C3A04E4D7EFEULL, 
            0x0442F4EE3C1DC527ULL, 0xB080E0E0B158B173ULL, 0x70AF558CD219EEDCULL, 0xDD1334A06D294360ULL, 
            0xB36F851772406C18ULL, 0x663064EE002706B5ULL, 0x5DCB9DDF1526F9A9ULL, 0x94D75F4DD721933CULL
        },
        {
            0xDACFAD031CF67AF2ULL, 0x28FBED89471D8566ULL, 0x950E057D836EE07AULL, 0x5FD5427485C23D9DULL, 
            0xACE0AA076D2D6090ULL, 0x49C04F931E5FABCBULL, 0xF099DD5DF1FDBAD1ULL, 0x88A3655B190A39E4ULL, 
            0x479A3A73DCD1B290ULL, 0x3BD543072E40F632ULL, 0x14E1DACB067BB69CULL, 0x0183716EC58FE6B4ULL, 
            0xEE09FC426AEB16C9ULL, 0xC5C10A31114EC016ULL, 0xA77962F3DB2D2792ULL, 0x657DAFA5A8F1EF29ULL, 
            0x4E5E9A50A7CB855BULL, 0x2075C46B809FFA16ULL, 0xAE4109363742B156ULL, 0x9ED4809F70EDBB05ULL, 
            0xDABBD3C8CE0C42C1ULL, 0x3A3BC854C23D50C5ULL, 0x8417C35DEA319133ULL, 0xCED36EB36FC0F4A1ULL, 
            0xA5825047A68F48B1ULL, 0xA6FE6EB315223C64ULL, 0xFD45DBD965B09F8AULL, 0x4F35FCA5DB7BF9BDULL, 
            0x995D3E4FA1B663DEULL, 0x947685E3469C474EULL, 0x90ED6B7E527371A4ULL, 0x04B89882935E5820ULL
        },
        {
            0x584B40EF57F334F9ULL, 0x8788CAABADEDF1FEULL, 0xEED3118BDA4E3C8BULL, 0x7F2B50AF9ACB1068ULL, 
            0x23B719233339DFE6ULL, 0x702D9651B63431BFULL, 0x4D32592B26C786C0ULL, 0x11A040DB487EFC72ULL, 
            0x030E8E69E75BC900ULL, 0xCF8AEDAB7513B8EDULL, 0xF738D8940A96A4B7ULL, 0x7FB98B1114323E78ULL, 
            0xF4FEED2C644C73D2ULL, 0xCF35339299388169ULL, 0x61BBFE447294EE45ULL, 0x04924E8D96A36AAFULL, 
            0x3B6A9976EF1EE361ULL, 0x36DB4C3B611FABFBULL, 0x520EEFD8342C5379ULL, 0xC8FCA56AF9FBCDD7ULL, 
            0xA62E7431B7C24DD9ULL, 0xC79CAA200FEC33DBULL, 0x7482B8864930B795ULL, 0x1C88EEE9669DE425ULL, 
            0x72AA600D8479668EULL, 0xB0BCF53046E58DB4ULL, 0x9DEBA67FF9083D6DULL, 0x7614EEA07D0165FBULL, 
            0x6F41B043225E616DULL, 0x91D450103D442780ULL, 0x196D27481AE9ECB9ULL, 0xE6FAA724D67FE1DCULL
        },
        {
            0xC7DA70C645064F78ULL, 0xFFE8328AD5C84160ULL, 0xAD2660B229BFB134ULL, 0xAB02BBB7090C99E4ULL, 
            0x78BE0ACC5C1951E6ULL, 0xB02F24018652ABE9ULL, 0xD71B8BAE17B96AA4ULL, 0x043F6E276067D7BEULL, 
            0xFC83D7D1FF8EE93BULL, 0x79F50F39B73280BEULL, 0x16BC7A7EB6A23F0BULL, 0x1EA60CB72EC8B466ULL, 
            0xF43BDE2E31BEF8A4ULL, 0xC3371D7C5E794EBEULL, 0xBF6BF78DCBD16172ULL, 0xB609C5239CE75D42ULL, 
            0xD451CE8DAF469F2AULL, 0xDED85FCFC66B421DULL, 0x83F6010A7B599ECBULL, 0xC2B32ACD9CF0A47AULL, 
            0xFDE69564EF28B194ULL, 0x168237AEFA354549ULL, 0x72E0672A0828BEC4ULL, 0x1A78A529B8DB4C5DULL, 
            0x2C554A72B41DDBD1ULL, 0xE5986AF273993095ULL, 0xFF14B29C5313A478ULL, 0xB3E35598403768F2ULL, 
            0x4A2A4B72A4948217ULL, 0x45C4845823B7F410ULL, 0x412BFEBF41C36087ULL, 0x492A128472F2FE2AULL
        },
        {
            0x1C9271C1B6FC25D2ULL, 0x0F18CBCD79AA261DULL, 0x4A7B4A3EAD31538BULL, 0x439C860AF79B108AULL, 
            0x083CC533459EEE21ULL, 0x565E4B6422651E7CULL, 0xD50EE1455144DDCAULL, 0xCF325F5D3BA91102ULL, 
            0x4C3D2D25E4441018ULL, 0xADB6EF20E566C60DULL, 0xD44510C6FB1F0B30ULL, 0x1F9B50A6E829016FULL, 
            0x4DA40D021BB3DDB7ULL, 0x31FA93069DC52319ULL, 0x2D2EC2B5A9535E67ULL, 0xA1664C7A2757CD22ULL, 
            0x72E9722D4B206D91ULL, 0x1454D25DC54E7DE5ULL, 0xC54F0FD96D7A6CA8ULL, 0x934E596210DF0629ULL, 
            0x15CB7BB05631619AULL, 0x7315972A8698B253ULL, 0x45C931B4DCEC3906ULL, 0x043BD3409783468AULL, 
            0x4D861136A87E9EDDULL, 0xFA24666C6712A6A7ULL, 0x0F2424819AF46642ULL, 0xD17865F294E3EE1EULL, 
            0xBF1678AD36502F32ULL, 0x529DBA414B9EC2AEULL, 0x80CD7E52B7BD71B5ULL, 0x45A39BD36ED3915FULL
        }
    }
};

const TwistDomainConstants TwistExpander_BaseBall::kPhaseHConstants = {
    0x86593C385410DCD1ULL,
    0xC810A9DA1CE9C10CULL,
    0xA553A2D70CA4BCBBULL,
    0x86593C385410DCD1ULL,
    0xC810A9DA1CE9C10CULL,
    0xA553A2D70CA4BCBBULL,
    0x56CFB156D526143FULL,
    0xB8B9020B44971BAFULL,
    0xB5,
    0x6F,
    0xF1,
    0x8D,
    0x48,
    0x38,
    0x56,
    0x7B
};

