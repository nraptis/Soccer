#include "TwistExpander_WaterPolo.hpp"
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

TwistExpander_WaterPolo::TwistExpander_WaterPolo()
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

void TwistExpander_WaterPolo::KDF_A(std::uint64_t pNonce,
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
        aPrevious = 10604282718091775140U;
        aCarry = 10093495726884094841U;
        aWandererA = 10516712883113366536U;
        aWandererB = 12303122013696468021U;
        aWandererC = 16417710728968009917U;
        aWandererD = 14047916880305727091U;
        aWandererE = 17362791204846477667U;
        aWandererF = 10304765237714839609U;
        aWandererG = 9652299097497433538U;
        aWandererH = 16868015361162646178U;
        aWandererI = 18182807662129823718U;
        aWandererJ = 16571927245661385899U;
        aWandererK = 14159265742256743478U;
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
    TwistExpander_WaterPolo_Arx aArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_BArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_CArx;
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
    TwistExpander_WaterPolo_Arx aKDF_A_DArx;
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

void TwistExpander_WaterPolo::KDF_B(std::uint64_t pNonce,
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
        aPrevious = 14576802550958579894U;
        aCarry = 15448029639707292851U;
        aWandererA = 13580965153710029689U;
        aWandererB = 10709714986841971807U;
        aWandererC = 11337377849569238508U;
        aWandererD = 15381463354281185859U;
        aWandererE = 12783378605989727822U;
        aWandererF = 16428433139159425462U;
        aWandererG = 14253253986122237726U;
        aWandererH = 14026526249612384213U;
        aWandererI = 17944460876317378808U;
        aWandererJ = 15791425152610896451U;
        aWandererK = 10704612546068452626U;
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
    TwistExpander_WaterPolo_Arx aKDF_B_AArx;
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
    TwistExpander_WaterPolo_Arx aKDF_B_BArx;
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
    TwistExpander_WaterPolo_Arx aKDF_B_CArx;
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

void TwistExpander_WaterPolo::Seed(TwistWorkSpace *pWorkSpace,
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
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::Aria256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneD, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneC, aExpandLaneD, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneC, aExpandLaneB, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    TwistExpander_WaterPolo_Arx aSeed_AArx;
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
    TwistExpander_WaterPolo_Arx aSeed_BArx;
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
    TwistExpander_WaterPolo_Arx aSeed_CArx;
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
    TwistExpander_WaterPolo_Arx aSeed_DArx;
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
    TwistExpander_WaterPolo_Arx aSeed_EArx;
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
    TwistExpander_WaterPolo_Arx aSeed_FArx;
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
    TwistExpander_WaterPolo_Arx aSeed_GArx;
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

        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_WaterPolo_Arx aGrow_AArx;
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
    TwistExpander_WaterPolo_Arx aGrow_BArx;
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

void TwistExpander_WaterPolo::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_WaterPolo::TwistBlock(TwistWorkSpace *pWorkSpace,
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
        aPrevious = 15418234036205197253U;
        aCarry = 10415593592913991839U;
        aWandererA = 17823130641629254958U;
        aWandererB = 10431317677331231360U;
        aWandererC = 14038502401318783515U;
        aWandererD = 15651840067146416268U;
        aWandererE = 17680225132054300541U;
        aWandererF = 15435338458966414771U;
        aWandererG = 12093548125560122778U;
        aWandererH = 13868199219060961322U;
        aWandererI = 10000738091191292466U;
        aWandererJ = 17251270792267247740U;
        aWandererK = 17210112232302283810U;
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
    TwistExpander_WaterPolo_Arx aTwist_AArx;
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
    TwistExpander_WaterPolo_Arx aTwist_BArx;
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
    TwistExpander_WaterPolo_Arx aTwist_CArx;
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
    TwistExpander_WaterPolo_Arx aTwist_DArx;
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
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
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
        TwistExpander_WaterPolo_Arx aGrow_AArx;
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
        TwistExpander_WaterPolo_Arx aGrow_BArx;
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

void TwistExpander_WaterPolo::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 2, 3 with offsets 7491U, 6656U, 6635U, 2601U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7491U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6656U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6635U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2601U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 0, 1 with offsets 4333U, 4999U, 6266U, 2099U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4333U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4999U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6266U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2099U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 0 with offsets 2364U, 1170U, 6484U, 7136U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2364U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1170U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6484U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7136U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 1, 2 with offsets 3578U, 7227U, 3371U, 4264U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3578U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7227U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3371U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4264U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 with offsets 330U, 1981U, 198U, 855U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1981U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 198U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 855U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 1, 2, 3 with offsets 1395U, 985U, 1430U, 1232U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1395U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 985U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1232U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 2, 0 with offsets 345U, 516U, 942U, 1994U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 345U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 516U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 942U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 3, 0 with offsets 1216U, 1882U, 858U, 237U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1216U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1882U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 237U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 998U, 1272U, 2038U, 1913U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 998U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1272U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2038U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1913U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_WaterPolo::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 1, 0 with offsets 5124U, 245U, 5281U, 3769U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 245U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5281U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3769U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 0, 3 with offsets 2485U, 7577U, 2408U, 6034U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2485U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7577U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2408U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6034U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 3, 1 with offsets 7499U, 4253U, 1691U, 4955U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7499U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4253U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1691U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4955U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 2, 2 with offsets 5879U, 7614U, 3467U, 6453U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5879U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7614U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3467U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6453U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 1993U, 4243U, 7537U, 3806U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1993U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 4243U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7537U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3806U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1166U, 367U, 1716U, 1527U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1166U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 367U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1716U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1527U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 372U, 1758U, 305U, 1812U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 372U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 305U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1812U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 979U, 944U, 916U, 1163U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 979U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 944U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 916U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1163U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 1165U, 1332U, 930U, 1169U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1165U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1332U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 930U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1169U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 1647U, 1097U, 1938U, 926U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1647U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1097U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseASalts = {
    {
        {
            0x86628F1559DF39F1ULL, 0x7D3275810D5228FDULL, 0xA4F1879957414C58ULL, 0x8D25A3959ED3B7C5ULL, 
            0x9A0BFD7A34E83056ULL, 0x33E9783B44B8E7E1ULL, 0xED179AB9B3991FEBULL, 0x3ECC2B615895D488ULL, 
            0x0373FC4C78FBF11DULL, 0x27123F8A8273269EULL, 0xB6DCA27BB55A8A44ULL, 0xE6FC70728D315899ULL, 
            0x56E5076F2CEB2077ULL, 0xB203B477743550EEULL, 0xDFEC5DB748917D93ULL, 0x254AEC75A0792AA6ULL, 
            0xF6F539250579F8F0ULL, 0xDF54FC253792A483ULL, 0xE328EFF68C2ED2AEULL, 0x533D52A8CD237FF3ULL, 
            0x359448E99F24ABD9ULL, 0x096CE8415BC34EBBULL, 0x3C08DCB7719AC14BULL, 0x3C429A31B3AE1F4CULL, 
            0x9ED21944AC306921ULL, 0x30602B100C1EB594ULL, 0x3B014969CD195458ULL, 0x30AF169733F7403AULL, 
            0x08A6D391DE567A4AULL, 0xD7CFF2CAA5C64D6DULL, 0x20AF193830ECD8ECULL, 0x2B8B5D1FB0E19BF8ULL
        },
        {
            0xF7144175EA1A9D70ULL, 0xEC9B0DB26FD795D0ULL, 0x8EA8294B2B4F8EBCULL, 0x25DC43A44CBB9349ULL, 
            0x4DD4657CCDAD2621ULL, 0x97ED400C193CF0A2ULL, 0x32B064B331979700ULL, 0x90C5961D2069025AULL, 
            0x751CB760B8E0EC1DULL, 0x22E8C494307F2ADEULL, 0x691F9BA026C9FC17ULL, 0xA0F962F97D429540ULL, 
            0x3AC2BC6783120851ULL, 0x37E1CFDA0D30439DULL, 0x87C5CBFC1EDB5AB3ULL, 0x08C6B1920BF733A6ULL, 
            0xCC3AFF78097FAC41ULL, 0xF6960318135C770CULL, 0x79A037CD1B4B6B06ULL, 0x7E86E294140941B3ULL, 
            0x263CE628B775D671ULL, 0xFAB6A0BA6FCBE7DAULL, 0x8357D1F03B2D166AULL, 0x87AACFE11794557CULL, 
            0x35647C6A6665A0A3ULL, 0x6E90504506B86E4CULL, 0x64F2DCC9BA17B3A6ULL, 0xBE31AC0E69378BC8ULL, 
            0x3010C682E588DCE1ULL, 0x9AE9EBEE213ACC7AULL, 0x6D85A8581822E6FCULL, 0x5076395EB19C016CULL
        },
        {
            0x57DA0FE81B027C71ULL, 0xC4943DEFBA58531BULL, 0xC359DF8458541FE5ULL, 0x37FBA064F55FCE7CULL, 
            0x639A12A94FBAFBCFULL, 0x0321F324BEB0A67BULL, 0xD347C0FFA07C2E5AULL, 0x3F04D3E2F3F6A399ULL, 
            0xF257460AFAE71F16ULL, 0x462CBAF3EDEBB52BULL, 0xE917DB350D6AEEDFULL, 0x378D8F99230905C2ULL, 
            0x7D8638005610F337ULL, 0x61AE6DA5CE2521F0ULL, 0x2D72845C3A68DBB4ULL, 0x6E7E34C01CB0FCC8ULL, 
            0x13AA490AE3C71863ULL, 0x057CF8178795CAF2ULL, 0x7BF2DAA8359C917BULL, 0x1ED90039218B3AC9ULL, 
            0x57D4956157C1CCFDULL, 0x4372C9A7E695B438ULL, 0x6ADBF8ADA2F4080CULL, 0xEBE2CC0D7D7EF905ULL, 
            0x36D5CCADFE380713ULL, 0x047A02278B3817C0ULL, 0xDAA7D8A368F9AFBDULL, 0xCC7528904BC1B522ULL, 
            0x77C83C81305C8A96ULL, 0xC3B36881D75E950DULL, 0xCD748DEE48ABF2E2ULL, 0xDC374CFFF3763E74ULL
        },
        {
            0x626779CFD7728055ULL, 0xAC9DABD34EB0FDFCULL, 0x8AA72CD6329E1003ULL, 0x36D556529467A6A4ULL, 
            0x9DA1E1AA44595CE0ULL, 0xD478932270CB8B2EULL, 0x14F4B8F41AB4E270ULL, 0xB3CE73F4A56A8396ULL, 
            0xB879E48DAAB8B4F3ULL, 0x83D543A166B6D41AULL, 0x6C63861396B66453ULL, 0x6EC05A549F71F20FULL, 
            0xF006FC7FB0E67406ULL, 0x125E2909C1113D3CULL, 0x35009B1F4CD2C9C1ULL, 0xBB8D241222053350ULL, 
            0x137528EEE02CD157ULL, 0x11C6515C5686FD64ULL, 0x3717F67C93C9D006ULL, 0x018DEE2EBF395F6BULL, 
            0x94D2E6C289894484ULL, 0x63DB515D11D8F4A6ULL, 0xE0B7216F44FB593EULL, 0x4DF8C03B40793AAAULL, 
            0xB7905B0B0796C7FAULL, 0x84977F2816CCDECCULL, 0xE5F7E79A984817CAULL, 0x6FAA1560678E8E3DULL, 
            0xE8454BE52DC01D22ULL, 0xA9B2EA16353CCA3BULL, 0xCC6C30712D799A6EULL, 0x39880EA9CC2A9249ULL
        },
        {
            0xC5C36FFAFD29F571ULL, 0xD2A15B372DE3DE4CULL, 0x634E12C4F0BE44DEULL, 0x3E971D83A726E0C8ULL, 
            0x1C4ADDB9A5F13258ULL, 0x9F55DCA32EEF32CBULL, 0x02079EA99941F3F5ULL, 0x5034020C683A1E9FULL, 
            0xBCD0F82B1564E613ULL, 0xEC35632D8B4A25F5ULL, 0xC1BC905A1BDCD0FAULL, 0x68499014A9950AE9ULL, 
            0x646CECD04D594728ULL, 0xA8413AA897B81A00ULL, 0x81AAFA900658EBE8ULL, 0xBA8EFD3BA91D45E4ULL, 
            0xC85054D54D6FDBCDULL, 0x2FD336B4E6860F38ULL, 0x3612F402E448F51CULL, 0x94EA3759F3D6CA8DULL, 
            0x5DACE8B4D3E472AEULL, 0xC088CE14E12DB5E0ULL, 0x9214F3AB2CBBF98FULL, 0x527915B88C3CE553ULL, 
            0x78663F61809A0261ULL, 0x7FFF8536AC801DE0ULL, 0xB59FD977576DA6D8ULL, 0xC70BCEC0B39F361DULL, 
            0xE9D6858A749F9428ULL, 0xF76BB763C858119AULL, 0x819CECDDA46086C0ULL, 0x3E2B0A5A2474FDB1ULL
        },
        {
            0xAFF1BA68976B81B2ULL, 0x0F7DC578F79CB52FULL, 0xB1378B3D3324C5C9ULL, 0xFE8E9ED1C8150972ULL, 
            0x74D27EA4928018EFULL, 0x85EEF3942A2E499FULL, 0xCF40E3A31726775EULL, 0x0FED7BB36EF62166ULL, 
            0x304423DC35EC1E0FULL, 0xB3815CDC7BBA74BEULL, 0x31679861E0547DACULL, 0xF4C1365FBB2547DFULL, 
            0x48D38EB4554A2906ULL, 0x116E0F69A951D843ULL, 0x36CD1A4E9B64CEF5ULL, 0x6FE28CB41D42B4D4ULL, 
            0x85D05D1528F6D940ULL, 0xB98399EB47A5E12CULL, 0x869C6691E7CC76E8ULL, 0xAB92F2816DF10090ULL, 
            0xA14A9B3B134ECBD1ULL, 0xCF35D7D0D7E9C368ULL, 0xBA95F95B08C2F816ULL, 0x496DF7D2CE936A0BULL, 
            0x9F2DE1AB24F11345ULL, 0x99C8DD462533D453ULL, 0x6F6A2ADEF6D1B8E4ULL, 0x1984457026B0C73CULL, 
            0x08C7E4B8CD81D67CULL, 0xAA108A099700A488ULL, 0xC4455ABF57DE49BCULL, 0x50FBF11826965E6EULL
        }
    },
    {
        {
            0xD5E89E0DA0811432ULL, 0x939AA7C6F0910AFCULL, 0x5C6B8EBCDF7159C1ULL, 0xFE964BCF44C155F5ULL, 
            0xEC0BC29A8ABC965FULL, 0x45AEBF7903AF80B6ULL, 0x7D9F00B4C6571A06ULL, 0xBAD779BCA6597F44ULL, 
            0xE7EC10BEA0083187ULL, 0x4A36A3278194D1D5ULL, 0x6BB5BA15BDAC085EULL, 0x154A06C08A650996ULL, 
            0x4FB3413CCDABE41BULL, 0x659012465A496B15ULL, 0x7993E2438AF68072ULL, 0xAD25CD19BEA8B801ULL, 
            0xD96F02A44B1A4B65ULL, 0x8845F0AA1DB88B28ULL, 0xA4E001165148513EULL, 0x69473DEF9A3DEF05ULL, 
            0x6C49A386346EACEBULL, 0x54D707FA326C3C97ULL, 0x95513ED299DCDFF2ULL, 0xB51B83ACBBA1A111ULL, 
            0x620B576E0860734BULL, 0x2FDFD41AC642D37DULL, 0x99344A7FAC7C3861ULL, 0xE07ACDD5E23EF85FULL, 
            0x4D886A1674836942ULL, 0x8FA23658A09A739FULL, 0xEF423C6C63C3DB61ULL, 0x1F672544E74F5E7CULL
        },
        {
            0x9751F71624EE688BULL, 0xC00494220D1D45C3ULL, 0xD023D34E9F184955ULL, 0x93F9717717C57DF2ULL, 
            0xF11EFD5C716BCF3BULL, 0xC96D04C533A2ADCEULL, 0xB4591D6AE73F7FDBULL, 0x4FB0A9CE04C48E2DULL, 
            0xF745A73E7336A20BULL, 0x67579FD4168580D3ULL, 0xB0F6B3735D313E60ULL, 0x072864CE26DB55B4ULL, 
            0x156952068BD80998ULL, 0xFB06C1004FBBB141ULL, 0x8DF70CFEC41EA12BULL, 0x4363174BA9E46543ULL, 
            0xD962195315F20C46ULL, 0x22CC49DF61EE4916ULL, 0x9C5C9799E0F0A503ULL, 0x704E4FF78285F6FDULL, 
            0xCBA52361A2E0DDC5ULL, 0x4FFAB63E1EB8C951ULL, 0x7EF900E1C2570BD4ULL, 0xFF9031745A347A41ULL, 
            0x92C51389207BD92BULL, 0xB0742682A550C6CFULL, 0xC51027BDBBD43C46ULL, 0xAABB39F2776F4318ULL, 
            0x83E74E80EC1BC400ULL, 0xCA93A0BD35A29361ULL, 0x947C5BF4C8C4E36AULL, 0x64F7150EC57FC06FULL
        },
        {
            0x821C5F06756923F5ULL, 0x0D6A7E12CBBBB17EULL, 0x15973C58EAB3245BULL, 0x4F34BEE9F7E7EF3AULL, 
            0x44DF3139AB1470F4ULL, 0x8323D7FE9AD3C4D7ULL, 0xEC22B67DD030B083ULL, 0x5181399C220C4DE7ULL, 
            0xF88EBD05E352B7E8ULL, 0xFD70C8F39EA14CDEULL, 0xBE8FC943A358F18CULL, 0xE7CE616EDF1070C9ULL, 
            0xFED63DBDD445DD11ULL, 0x77D45640B33BABAAULL, 0xBF4ADA6A89C6D23AULL, 0x77EE1E84EAAB28D3ULL, 
            0xAEA4B3DC5B22B7CAULL, 0xECC1CAC7D7593DA2ULL, 0xA4C3C55E55A5E668ULL, 0x4C7F8FE7AC8497C1ULL, 
            0x04F26D39CD07623CULL, 0x7F5334E7929E2BDAULL, 0xF5DDCB054CC8E3F5ULL, 0x59F6AF072CC90225ULL, 
            0x4949D4F0218A52F9ULL, 0x99A1D7F220F5B22FULL, 0xE6D27DAB6AA329A4ULL, 0xD69F5381F19A8EA3ULL, 
            0x0F86A4DBC66CB9ACULL, 0x7ECDDA40C8C4CEAAULL, 0xD5DEB6475892D67AULL, 0x8D2203A036657C96ULL
        },
        {
            0xB299BB128C8C7D55ULL, 0x10FF5F35A39F3A03ULL, 0x50525DFB6D98B730ULL, 0xEEF0553C7C9478A0ULL, 
            0x35D29C93EB4C2D7EULL, 0x568493C02C729B24ULL, 0xB3ED656B94BC29D6ULL, 0xB15CA03CDBCC8E67ULL, 
            0xE915753F7FF9C012ULL, 0xF7C07F57F066CA60ULL, 0x229A265BF7B4969FULL, 0x31841E343462006EULL, 
            0x2DCB7C8ED3795FC8ULL, 0xAE9601AD50554272ULL, 0x40E0AB4476BA638EULL, 0xEB0C9F654F43882EULL, 
            0xE0FB21208D843891ULL, 0x957F706B6609625BULL, 0x1D9A615F9EE1C656ULL, 0x49E24AA0981ADC3CULL, 
            0x4F795E9B1DC43D0AULL, 0x6993D1F1432BE42EULL, 0xD8CE2D730AF5BAC5ULL, 0x1E49E228306AE9C2ULL, 
            0x0402B7D73C4DFB7EULL, 0x6F14BDF97EDE53F7ULL, 0xE133A80C12ED3F5BULL, 0x77719255535BA1F0ULL, 
            0x26F3A0C084409303ULL, 0xAF98A8F696CB26DCULL, 0x863E3ACEB60D54C3ULL, 0x91D3231B13DF7662ULL
        },
        {
            0x3CCC4FEA7D002EECULL, 0x0CB1B97367B84CA2ULL, 0x2DDA17422AD77A38ULL, 0xF657F0EE162B5161ULL, 
            0xC3CF2BDCF9B1C8ADULL, 0x9FD6B3EADF069325ULL, 0x2EF3CB2C9A91916AULL, 0x5113B4C4BED92B62ULL, 
            0x618820B6DA3713C8ULL, 0x2D53721B4945E1CEULL, 0xE91F9FE40914E715ULL, 0xD0C5FE58411A5270ULL, 
            0x336F1CE2CAE420A3ULL, 0xD9B9CA86A307E45CULL, 0x5B4CEF6FCD6BBD52ULL, 0x4425F47752966719ULL, 
            0x0025FB365D7716ADULL, 0xC60C83A0206C63AFULL, 0xD72F5E4298A2271BULL, 0x9B723A1B27D9FC93ULL, 
            0xF647609BEDE47D5FULL, 0xD075820484593CE3ULL, 0xFA7798892D9C6308ULL, 0x8D8445FAAFBF00AEULL, 
            0xEB603408012BC444ULL, 0x93C82E05938A9AA7ULL, 0x835027FF73E41D86ULL, 0xE95C8CEBB07FEAF7ULL, 
            0xEAED08FFB949E7C8ULL, 0x844A2E8B79101DCBULL, 0xF705288825CDF19FULL, 0x47864665E87F9F1AULL
        },
        {
            0x437CB70A57BE7092ULL, 0xC5ECBE79AFC6386AULL, 0x52C1744E255D1A3DULL, 0x1AE7CD500271014FULL, 
            0xF810A595CAB8D7EDULL, 0x693F7B9DB4F8CE5EULL, 0x376AD4B62D39125EULL, 0x35A01EA6886E8409ULL, 
            0x0E8A18D55CDAA119ULL, 0x60F83DAF52BE6E1EULL, 0x639D6BF35AE1AF6AULL, 0x541221DDB83EF9F4ULL, 
            0x9893A96734755852ULL, 0x574B8C87CBF47877ULL, 0x787C3C556C534322ULL, 0x60E85E1ECBAFC0F0ULL, 
            0x9BCC4767DF885ED6ULL, 0x035FAD2DF1737097ULL, 0xD6797A78DBA9BF07ULL, 0xFBDDA18A6CA28497ULL, 
            0x0B44F370C0AE4AC2ULL, 0x0258C6D231464345ULL, 0xE2F6ED0DDDD960B7ULL, 0x017019432ADAB69BULL, 
            0x630C199DFCCEF54EULL, 0x130E7B675A1288EBULL, 0xC91930436CBC1A0DULL, 0xE660F23417526721ULL, 
            0xC49D615C56F621C6ULL, 0x08E382BF62FBF165ULL, 0xCF6E6C1C9547FB33ULL, 0x05B0BE823A262613ULL
        }
    },
    {
        {
            0xD0DF6895AC0EF787ULL, 0x6A26D3445319A09CULL, 0xB4862BE4F38FE9D0ULL, 0x1C6B4F16B42F34C5ULL, 
            0x9127E9155B6EFE03ULL, 0x3C5DF263B013796DULL, 0xB35835293FE42A91ULL, 0xBE5C73C4B3420F1FULL, 
            0xDA7D3A28EFEC71D0ULL, 0xCAD2E4BC9334765DULL, 0xC3EBDFAF7A03D227ULL, 0x5F2524F26CBB4869ULL, 
            0x2E099BF7F8A040E1ULL, 0x0BF092A7919E1ED2ULL, 0x3C56175BAE8C4077ULL, 0x1D57BB069BC6EA3FULL, 
            0xF9ADD5480E481910ULL, 0x2EF3F8D7C4E01A68ULL, 0x38EE16A5260CEA8CULL, 0x4DF15E4435BEFF1CULL, 
            0x56A56D03D14C0935ULL, 0xFA175571C3BD947CULL, 0x0CDD2149071462DCULL, 0x84BE3300D104AFEAULL, 
            0x4922AA3831E8E755ULL, 0x6756D2808C747BEBULL, 0x351885E796650104ULL, 0xA5AB8B9FF9227AF7ULL, 
            0x6171C63D76739C58ULL, 0xE91F96A682FEE796ULL, 0xC3E5859C9DB75A6CULL, 0x6AD1806D62A85E04ULL
        },
        {
            0xC413C85B3D5371D0ULL, 0xCD18467686CEBF18ULL, 0x62ED5CBEF4FC016FULL, 0x9B9BE04AB8B9423CULL, 
            0xD7E7CE17BC96C64CULL, 0xED13D0F23B9E5C71ULL, 0x2957456F59322696ULL, 0x3657492BA7E8188DULL, 
            0x5AD91EC70BC9CF03ULL, 0xD568128BB7DB9C56ULL, 0xDDB4CF45F97786F5ULL, 0xA25DE3880FE771CFULL, 
            0x70DC479E00C4BF95ULL, 0x3A19ECB2FFE3ED0FULL, 0xFA8B44F7D130CE57ULL, 0x82B4FD8F2CCC155CULL, 
            0x5DEA976EBAB9EB5EULL, 0x30457BAF2695628DULL, 0x845E224F2C311248ULL, 0xFCF6C858878FB082ULL, 
            0xFE814B28C1D1742FULL, 0x66DDDD94ED8C19D5ULL, 0x8577A777391645B1ULL, 0xDD8D715241E66C5DULL, 
            0xCC39E5CB1F03E735ULL, 0x3301C07FBB7D7A7BULL, 0xF135DA7C1E02CE79ULL, 0x971E7FA4BEBE7B72ULL, 
            0x3CB9DA74FDE9D600ULL, 0xA9D58BC4476CD832ULL, 0x92F4729DBD68240EULL, 0x9EA4346639C4D654ULL
        },
        {
            0x0DEB9B2AD37E45F9ULL, 0xC533E27D92EF9198ULL, 0xB13B8AC5CFBFC493ULL, 0xC69449AF38088ECFULL, 
            0x685B5B0007BB3129ULL, 0xC55E84A8498818E9ULL, 0x0D5EA7B235B98EB0ULL, 0x7B830281CF39324AULL, 
            0x664F3416C7986D07ULL, 0x7FBA467FA69D8EC6ULL, 0x21AAC404F848B822ULL, 0xAB55E77E26613076ULL, 
            0x42CC03F07EF76E71ULL, 0x2A5C8D375483257DULL, 0x7BF6D0D7015C4EF7ULL, 0x7B9680A3F5A123F1ULL, 
            0x2052C87889611D3CULL, 0x13EB4B2F31668B47ULL, 0x3EABACD242B92823ULL, 0x13E108802A2B0BBBULL, 
            0xE62F9BE6AA8CECF9ULL, 0xFEF85297E57D4E37ULL, 0xE53CB278C734A590ULL, 0x8FD5DA442B1986C6ULL, 
            0x3D1BCD9B94916A1AULL, 0xB4A771E1CD7F4871ULL, 0x857E60801A186DD0ULL, 0xA6E001D58B79684CULL, 
            0xA11FD9605447AB45ULL, 0x76FBD3C8F3DC36F5ULL, 0xEDBFD29E6F082883ULL, 0x84630469D1BA6352ULL
        },
        {
            0x0B9D970EDDE879D9ULL, 0x728F1568DE0931D8ULL, 0x60425954E8BF6C04ULL, 0x0DB6407FDD8C63CAULL, 
            0xE7C24F944A0CF48CULL, 0xECCD97605AEFE346ULL, 0x8CB52DE26D2A69BBULL, 0x3803BFB53E0D4E50ULL, 
            0xF0B9849D0DDACF74ULL, 0xA9E374C3C16F66C1ULL, 0xA25385D724086EA3ULL, 0x33741D28E72C3F49ULL, 
            0x21C04AD9E5CC5755ULL, 0x825F2573318B74DDULL, 0x36BC668C5DE4F92EULL, 0xFF64C48697CA71F1ULL, 
            0x9BB87FED57DAA1BBULL, 0x9FD4916027FB49C5ULL, 0x6207EDBD9F58B0C2ULL, 0xD1E0C67057F99F28ULL, 
            0x4D53EC2A87FF0805ULL, 0x107BA00EF2358D8FULL, 0x82AED9FFA89B3172ULL, 0x53D83CD1A19D9371ULL, 
            0xD8A844011D381FF4ULL, 0x88F1BE5ED790D745ULL, 0xC10FD28D12F0F7E7ULL, 0xA66A88AD3D7626BFULL, 
            0xBDADB2AB0674AFE4ULL, 0x8E146F347B9F33AEULL, 0x0894056B1BCCFAA8ULL, 0xF2E95CD07F4C211EULL
        },
        {
            0xB23E2F86174F8D2FULL, 0x1164C3EB3094287FULL, 0xE4E6C34DF9531216ULL, 0x718E49803DFE72AFULL, 
            0xF1AE8199F86FBBACULL, 0x66115E34A13142B7ULL, 0x4E7FD75E604D6C94ULL, 0x1CFBC9390DCC6E5EULL, 
            0x9189B191082E3CA3ULL, 0x5D0C09ADE5A67F68ULL, 0x7271F61E7604C829ULL, 0x64C04BAF2886A3B9ULL, 
            0x79074D5B8F7CC465ULL, 0x08D7D7193B524607ULL, 0x17788A227E349868ULL, 0xB7595B60B92CE650ULL, 
            0xE34B8AC27689E675ULL, 0x28A759640EE652B1ULL, 0x3AE0B1DB46F483D4ULL, 0xA73176657E103A76ULL, 
            0xDB43936E392C68ABULL, 0x612ECA8602AC14F0ULL, 0xCCF960FB247DDFFEULL, 0xAF0B6788E351AC30ULL, 
            0x852A5E8D552A0FBAULL, 0x695FCCBEF509440DULL, 0x36F72C5B365D4B64ULL, 0xE05E41454CC7E6BFULL, 
            0x869C2F8057584C90ULL, 0xC7A486DF5A7452BFULL, 0x89157572F26309E9ULL, 0xEB371861720F3E61ULL
        },
        {
            0xB7CEE8BBAEE421E1ULL, 0xE82BBF7D297E9779ULL, 0x03C13CB5354FF255ULL, 0xEA78FB53A72453BEULL, 
            0xC868FEF6FB5F6A82ULL, 0xE45664174A2DA4A1ULL, 0xFCD072BD2A22ED4FULL, 0x054B424E99A61B21ULL, 
            0xA303AF4A1B6B37A1ULL, 0x451A659C328D0150ULL, 0x0C2C88E56D721547ULL, 0x553A6E3B611CA686ULL, 
            0xC82E39FB72946DE7ULL, 0x4EBEA0C4F8075F83ULL, 0xB7AA451684CFAD35ULL, 0xC9BB0EF83FE6D1A4ULL, 
            0x70BC494300844883ULL, 0x0BB7C00B0CEDA4FDULL, 0xB5E107915686F612ULL, 0x648FF0F2F73A4B2AULL, 
            0x2BD96DFD633D9187ULL, 0xAD55CC4386FFE9C5ULL, 0x4FE8CC3EF1F174E7ULL, 0x101F898397306A9DULL, 
            0x1A0F90BF8BFF7FB8ULL, 0x37AB201A54B37BE0ULL, 0xB58D9B84D971BE47ULL, 0xA2BD63B98B99B14BULL, 
            0x49AEA9FC52A4D590ULL, 0x7DC666259C196426ULL, 0x18801498689827D1ULL, 0x7CFB0C91D1C89844ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseAConstants = {
    0xA62A0E647A5B565CULL,
    0xD61F7C948F8C44DDULL,
    0x21EB1DA3D4834342ULL,
    0xA62A0E647A5B565CULL,
    0xD61F7C948F8C44DDULL,
    0x21EB1DA3D4834342ULL,
    0x030CEEC37351E365ULL,
    0xA99765EAD120859EULL,
    0x67,
    0xF4,
    0xCE,
    0x7E,
    0x8E,
    0x80,
    0x72,
    0xFA
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseBSalts = {
    {
        {
            0xAD94A9515FB6547EULL, 0xCFE32A69C026E18DULL, 0x4CDE05DB8FF41A77ULL, 0xC11F65CA4005C4CAULL, 
            0x697452B7E9496416ULL, 0x3378865C11855AABULL, 0x2F634B5A6DDB8A39ULL, 0xF04B52C8A819873FULL, 
            0x0FB57A9AC80BF87DULL, 0xE1028A95483AB98BULL, 0x461D11443C2365EDULL, 0x16299040507D94C9ULL, 
            0xB637F69BEB245AB4ULL, 0x3C9644A9EB2011AEULL, 0xBE2F19B07160748BULL, 0x7154D3C6266174BDULL, 
            0x98C64F2901506960ULL, 0x25FD692D2194CAD2ULL, 0x2A831DA87B67A167ULL, 0xBE682D40174F2291ULL, 
            0xC75EDAEF04DB83F7ULL, 0x47E4DAFF39CCF404ULL, 0xE4DE04BF71EB64C9ULL, 0x3F1D40F183DEBD63ULL, 
            0xAC1F8BF322ABB292ULL, 0x93AB501907A10CD4ULL, 0x62798E3544F97E44ULL, 0x8B8689D89988023CULL, 
            0x9A16549F928EF449ULL, 0x1EEBF7B756D25201ULL, 0x5854E4EDF574C9CDULL, 0x74F6A917CEB39BCEULL
        },
        {
            0xA9E137B07EE827FAULL, 0xE3E1FB1B9D7B8626ULL, 0x901FCC031DD9E9B0ULL, 0x18363A67DAE621CEULL, 
            0x4F7F208BF0E0B826ULL, 0x5B6FC4B175BAEB77ULL, 0xBFF27E9E7A946701ULL, 0x24497DCCF20C61FDULL, 
            0x38BF4DD361501DBEULL, 0x53ED01A20CA007FCULL, 0x406FCD7AE9E4EEB9ULL, 0xA5E819C486FE2229ULL, 
            0xAB1D04612FE0F409ULL, 0x3E80768D079652B0ULL, 0x285C25B767F49D03ULL, 0xEBA282CCBD774AE6ULL, 
            0x20BE0057DB2AC8FDULL, 0x711879EB1F0BED6FULL, 0x4182F3637F5B410DULL, 0xABDB9735BC16ACDAULL, 
            0x8F0C9FA3101F0681ULL, 0xC477C30E88923D75ULL, 0xB6A5777B33A50D59ULL, 0xB3E753347B2989DAULL, 
            0xE1F7D9821C125FB7ULL, 0x72B0EFED93D84B7BULL, 0x8816B95C04E539EDULL, 0x456C66452472DBF8ULL, 
            0xB2996259BF751029ULL, 0x308C7EB8A82613FEULL, 0x8034136E4D9023DFULL, 0x18DB962D02BAB96DULL
        },
        {
            0x1CBD5B2838EF8D01ULL, 0x8DB294673B85357AULL, 0xC1AEFA2E8622FC38ULL, 0x9B789D0D2298784CULL, 
            0xD6B7200B4165C158ULL, 0xB6B8130AA6420109ULL, 0x4B33D13F7F65DA34ULL, 0xDB14EAC295FDAC62ULL, 
            0x19D3665F194E433CULL, 0xFD8EEDDE96A777D5ULL, 0xC73A52F2D34361EBULL, 0xD5804F8E70FCA408ULL, 
            0xBAA647F611961DD0ULL, 0x36588E3EA03DE58EULL, 0x9DC82A190DB2861CULL, 0xA2CCB2522CF162CCULL, 
            0x8F38592FEE522F2EULL, 0x7C36F3E58AFE2824ULL, 0x594F46E8BAA0941BULL, 0x07773C63B462B207ULL, 
            0xFFABC094464EBDD0ULL, 0x07B3ADFAEBA512B4ULL, 0xF15C37A540CEFE62ULL, 0x9ED0C18B6230FD6BULL, 
            0x74932015B4A5D9B7ULL, 0x5A4E67EAEBB7B112ULL, 0x8B443AAD7D4BB6DDULL, 0x525FEB3504EE99F1ULL, 
            0x984278AACD57A22AULL, 0x2A7E6DE4BD0E32EDULL, 0xCB4F3C8CA7060A71ULL, 0x74C9E46F931E7326ULL
        },
        {
            0x6FFFE13F62253DF8ULL, 0xAEEA0A2F2F457482ULL, 0x0E6A13B36C727277ULL, 0xD0BCFA3BCC7F8FDDULL, 
            0xC80D01394C97B012ULL, 0x362B3B408BAD9B0AULL, 0xE1F877C201B7037CULL, 0x0311FAD018D0646CULL, 
            0xA9BBC6EDFA87EC80ULL, 0xE846A90A9961B636ULL, 0xB45F07E268BAA0CBULL, 0xC04BCAE25F8F2F31ULL, 
            0xE0F376C1A363BE07ULL, 0x29C5C3ECA33A444AULL, 0x3C45339A0FD7438EULL, 0x8B50833AF156ED35ULL, 
            0xCE2BA00D8E04AE04ULL, 0x757FB29A847965E5ULL, 0xD86C1D0DDD753A26ULL, 0x0C2F111757D2A643ULL, 
            0x7AF87E03C9CC5742ULL, 0xB08B0DB97A27FECEULL, 0x5CF8FBF44FDAA886ULL, 0x317CD726A6FA5434ULL, 
            0x37D0C0A1DE9DDB77ULL, 0xC659DC79E292CB39ULL, 0xBC071BADDDA6539AULL, 0xB362B06FF46CAC05ULL, 
            0x9F2ED1751452B399ULL, 0x7FFC14888A274D09ULL, 0xC2FD7C17CCD32BA5ULL, 0xE606C3FDBF9C092AULL
        },
        {
            0xBE8CDD6D3C8C2531ULL, 0xD625156A5925C58DULL, 0x3A8F13F353FEC2A0ULL, 0x4CE5538806FC9A1AULL, 
            0xAB601AD47259E2E4ULL, 0x28E2890CD06797B1ULL, 0x91747893C2AB3DB5ULL, 0xC46A2D477A191420ULL, 
            0x3EFD47E36F755E69ULL, 0x7D43B5F1FB5A1B73ULL, 0xFEEA1CFDF308D824ULL, 0xFF2CBEDC19198DBDULL, 
            0x3DFFD7514CE231E2ULL, 0xB02120C42BE432F5ULL, 0xC7AB1AC561109B49ULL, 0x52278B948E2F0939ULL, 
            0x6B98F6D5A9D832D5ULL, 0x48B02D9660C92867ULL, 0xE1D860FBD5154D9EULL, 0x31A9183131FEB8A3ULL, 
            0xF2C2908CA15C110EULL, 0x416BEA0795C1C379ULL, 0x5A40464FA0154D0BULL, 0x080880EF98B7F5C3ULL, 
            0x4834D96DDFB0D76AULL, 0xAF3A959FD2D716DBULL, 0xD8002CF7500A2F72ULL, 0xF0ED148257823EB2ULL, 
            0x64A9669A58C96A44ULL, 0xD0019E1C3B2FFCB2ULL, 0xE998CE4D5191947EULL, 0x456B50655922AC2AULL
        },
        {
            0xBC40B4D26836407CULL, 0x15FDF3507354FC37ULL, 0xCCB639BD21BC3274ULL, 0xA871EB315536B759ULL, 
            0x47062988433974E4ULL, 0x3862B25B8A617CD9ULL, 0xEAA6EAD32E7E315FULL, 0xD88E596E9659A277ULL, 
            0xA87BB2041DD2E19AULL, 0xEFEB9CB8EE838ABEULL, 0xC895E3BA4AE25A3FULL, 0x9CDB31F3D559657DULL, 
            0xD3CBEA583839A77FULL, 0xD9830D9011090476ULL, 0x550AD915C9D8EB81ULL, 0xD591416734BB35BAULL, 
            0x02E1B84BC6E68CD2ULL, 0x2B638FB629C6748EULL, 0x13728511B68B16C2ULL, 0x2CCA61BA1221DA2DULL, 
            0x28685518B0E993DDULL, 0xC6A5052203FD4949ULL, 0xB05065ACF70B5398ULL, 0x3BDA7B8A3256596CULL, 
            0xF84974DE4B17BBE8ULL, 0xEEF0E71E73DD1E74ULL, 0x048E5026F05B6AE3ULL, 0x074D8051BE532610ULL, 
            0xDA562977696BB63AULL, 0x40B057917EB2C892ULL, 0xCBB78D2E64ECAE93ULL, 0x5093AFFEDC687F6EULL
        }
    },
    {
        {
            0x2B214394BF23E87DULL, 0x52785ABA468B5B16ULL, 0x8F5F44EFC2524E8BULL, 0x00E175084E0B7EF4ULL, 
            0x331044B1E72012E1ULL, 0x7CE9E6A969C02788ULL, 0x9E9C2DDDB1B291DBULL, 0x3300C3205AA88286ULL, 
            0x07C95F0799EAA65FULL, 0x6CD06F362DF125B4ULL, 0xE46EF7DE84A6CB30ULL, 0xE9008433CF29B494ULL, 
            0x07F8D2F92522721FULL, 0x9849794D3BB00077ULL, 0xE8BD331D1CD2FCAEULL, 0x79BE2FEDD23BCC25ULL, 
            0x5CF628D9EFC4FB5AULL, 0x98C4F90D1927ADA8ULL, 0xCE2188660EC33695ULL, 0x75C605C95986DC1AULL, 
            0xD16F5AB12047CF28ULL, 0x6D109D34A095DAE4ULL, 0xDA0F79FAC2CE3ADEULL, 0x54149505D6796625ULL, 
            0xBBFD127691B4F70EULL, 0x8B9DAA48FC078FF9ULL, 0x71B0EA969E17466FULL, 0xE459BA1160B146C1ULL, 
            0xF040BBFA1DCC1B11ULL, 0xC0121FDE57A24401ULL, 0x5DDEF2EC3650D615ULL, 0x69DF50EA1699017FULL
        },
        {
            0x7B99860314FE5F37ULL, 0xD01362C8E1DAE6A4ULL, 0xC85291FE2B7EC6F4ULL, 0x5C00403CB9390E63ULL, 
            0x33967D408300985BULL, 0xE41349F2A7C5A660ULL, 0xB7E97F3E4E09469DULL, 0xBF0DB5057028C995ULL, 
            0xACF979DD15192452ULL, 0x6CFA35D734539322ULL, 0x1CDB53932422E55FULL, 0x9E8C495DB5A5A37CULL, 
            0x15298702441591DFULL, 0xA22CA90977D62485ULL, 0x0EB513D1F9FC82EBULL, 0x92A29DF028A43C7EULL, 
            0x1D720D7CBD1E8A15ULL, 0x33D6800D8D4F3B70ULL, 0xBAE7B0CE6D4A5A9AULL, 0x2E809DA2DE3C2CB6ULL, 
            0xB06B0949DF1D8B86ULL, 0xC1E2E6FC3906700CULL, 0xFA9E047A6BBA6EE7ULL, 0xD30948852C19D4ACULL, 
            0x163166E047C4F347ULL, 0x1C082B4E5698BD58ULL, 0x153663D9E8D22B47ULL, 0x3CC761C041362FF8ULL, 
            0x8F49B92748122DDBULL, 0xE5D7E954BB3AA74EULL, 0x76B9EF39E0F83D2CULL, 0xA5D61C349B4D5B68ULL
        },
        {
            0xB914CFAC11A6E3C1ULL, 0x9265A0E707A8BB9FULL, 0x28FA596B420FD485ULL, 0x1860E0B14459178BULL, 
            0xC3BF5267B653AD3AULL, 0xE7AF150F663BF9B6ULL, 0x013A0897769779E1ULL, 0xB2451E56FEBB1FA5ULL, 
            0x365791CF8527B7D5ULL, 0xF4BB58BE498BF305ULL, 0x6248DFE436ED110EULL, 0x115C8CEF914AE209ULL, 
            0xE335C98369C7C1B3ULL, 0x5619DA580DCA5037ULL, 0x49594BE7A3429C16ULL, 0xFB9577CDDFEA1DAAULL, 
            0x8C47EFD246FCD556ULL, 0xB7A1E59ED9A686C8ULL, 0xEEC3DC35A2258535ULL, 0xAF889F4A757D7097ULL, 
            0x8C24448FFF36ABE3ULL, 0xE65C047B370EBCE8ULL, 0xEA77F3A7B3E55441ULL, 0x2E8AE8AA49C6BBCCULL, 
            0x50C3946CE7E1BE45ULL, 0x8688D306D8B8F0ACULL, 0xAE626AA2323C1915ULL, 0x433A8EB2C95F9598ULL, 
            0x8B644F86CFE58618ULL, 0xEDD20932E72CAE0FULL, 0x79FEED7547631188ULL, 0x4F3DF830FD67D7F0ULL
        },
        {
            0x419139C45E69D445ULL, 0x45D70FBB94B92E09ULL, 0x6D0229DDFEBA51FBULL, 0x27D7C664DADEA97EULL, 
            0x4F3B75230416A001ULL, 0xB7CF8968E80D16BAULL, 0x93C44DB807B657BEULL, 0x68C1DBEF28787388ULL, 
            0x75685E91CA39F49AULL, 0x9933C4C94E4B1AC2ULL, 0xFE4A27C745A9D13EULL, 0xD341FEFEF708B99FULL, 
            0xE5590EF43A940BDFULL, 0xA2D720126CFB5CE7ULL, 0x7AD8F3E35DB40792ULL, 0x9B568DE3300DE7B5ULL, 
            0x3A11AAEBE5BDC6BBULL, 0x4C7470AB476B595DULL, 0xED7EE8DEABC83A45ULL, 0xD096053553B77564ULL, 
            0x5C1DBFBB8DFB29FCULL, 0x00C904814A371184ULL, 0xE567487C1F2DECB7ULL, 0x469AE45EECFED4E7ULL, 
            0xFD6B74F0BD4232D1ULL, 0xAA2E1970CE33EDA5ULL, 0xE275A9C542540CD2ULL, 0xFC076F91E4DDF3E1ULL, 
            0x3F9859E3B408E708ULL, 0x72F28CB4144888A4ULL, 0xFBC5376E857EF5B3ULL, 0x02B47FE22718B7FFULL
        },
        {
            0x30F563C27295AC70ULL, 0x1D2ADDBE737424EFULL, 0xFFB793B041FB949DULL, 0xEC662CE8827908BAULL, 
            0x9EDDDCD5FC1209E8ULL, 0xB9602EB52D016E01ULL, 0xD205268AB04B7631ULL, 0x1513FED432CAAF9EULL, 
            0x9C6E4F716C13D00DULL, 0xE325931DC3977D5BULL, 0x3D94F24A8E42D942ULL, 0x1D1DA7E51F93B0D0ULL, 
            0x3E756465BC84E702ULL, 0xF8603DF86DC72D1EULL, 0xACEA0582A526DE84ULL, 0x576888EC2A93F762ULL, 
            0x94ED23B9B899B1AAULL, 0xEC672499560EA45BULL, 0x5D83E8D7EEEE7ABFULL, 0x6188034A17F81ECAULL, 
            0x438B1CEA1EF80E96ULL, 0x7DF21967DB85248DULL, 0x58B73C9A75E9721AULL, 0x54218AA31F9C5B1EULL, 
            0x8BE3458FB8D9B32CULL, 0xD727A73A2DD4E8C9ULL, 0x71540C07E6835419ULL, 0xC06C812B9D0C893FULL, 
            0xFBE85408B568F354ULL, 0xE4C31EFF623AE14CULL, 0x4E684559506E5F49ULL, 0xFC443BEC61B40A2CULL
        },
        {
            0xC83C961F6CCDAD72ULL, 0x4DF5D6A5EA70796BULL, 0xF564A58748E5A713ULL, 0x24C945519D48AC38ULL, 
            0x0A5310D5C318015EULL, 0xB4ED7DDA7EAC35CBULL, 0x6467F3FB69644AA7ULL, 0x02883369F7AF3D16ULL, 
            0xBC14E31754FCC943ULL, 0x1419DF69AF408E4DULL, 0xD7F91D8D3CBD6DF3ULL, 0x72BD808DAEB83EFBULL, 
            0x7E97B9D1BCA17BAAULL, 0xDE7C6A3272037B3EULL, 0x06AEDCE516319E76ULL, 0x6249C6D653129341ULL, 
            0x2A4F85A9DD8B3EE2ULL, 0xD32A1BA93EE08EA4ULL, 0x2C1447A0CAD8BC22ULL, 0x55AA32F833421196ULL, 
            0x106A34258DCD513AULL, 0x6E29E381B138802AULL, 0x97A41AD867040B40ULL, 0x1AC555A3C1E8D55AULL, 
            0x3D1FA3D143A33AC1ULL, 0x40E9C1A5AFEA8493ULL, 0x88BE90B1C7BE7577ULL, 0xB17E46D7ADAE4353ULL, 
            0x6AF462261320BF18ULL, 0xDEA34B35113EA792ULL, 0x00146FF126C68A61ULL, 0xDD4269F399D0A514ULL
        }
    },
    {
        {
            0xA451997290AB1E9DULL, 0x48A6AC66312B5FBBULL, 0x531E9D0432B9D31BULL, 0xDBD6C0432B776F2AULL, 
            0x392D0EDB3EA8394AULL, 0x48193059FAB81FD9ULL, 0x2A288B27C258E21BULL, 0x2D94135C379CA27EULL, 
            0x8A0284DD9F05475CULL, 0x7ACD5770AD46ADECULL, 0x0F5E8DF2A0BBE3F3ULL, 0x492E16036FE073E2ULL, 
            0xE48029B87DBD34EBULL, 0x1A8D813927E1E369ULL, 0x903168D1E393C036ULL, 0xAC11261C4F95E06BULL, 
            0x4F41FE3EAB95E126ULL, 0xD8011E289B7668B4ULL, 0xBA8C4D68F0EF3857ULL, 0x65C0C9596746608BULL, 
            0x78A36F980DF70B03ULL, 0x6F9F858A7336A82CULL, 0x1B7D7BFC19E345D6ULL, 0x421BB2DC6A93623DULL, 
            0x2FBE5EC65C6C0B93ULL, 0xDC405B2B32718197ULL, 0x8EC4FDCC0D29322AULL, 0xE0B8D37025F176EDULL, 
            0x55A05C52F4FDE80CULL, 0x17F5A4D4ED08A94BULL, 0xC00C83D5E6B43A4AULL, 0x6FFBF67A072ADED6ULL
        },
        {
            0x23163BE31593B67DULL, 0x69557E73DE393101ULL, 0x64EC940C09595301ULL, 0x636F599C6C384D37ULL, 
            0x4DD9F6292D6B303EULL, 0x1437CB50836B0750ULL, 0x7D49892BB4AB6A07ULL, 0xD33DD490F5914F29ULL, 
            0x0C4711EB273C9816ULL, 0xA38153DEA0C5B794ULL, 0xA0FCA332C91C5042ULL, 0x35CD71BF912D41A4ULL, 
            0xDA9FE8C511E686E7ULL, 0x54D4AFC4D0E5BB03ULL, 0xB754BCA9EDE67437ULL, 0xF1FDA070EDABAD2AULL, 
            0xBF4E8F39A4C1A0EBULL, 0x21A5C70C9A06EA91ULL, 0xC626B4EFC73306C8ULL, 0xF527CF981BBD8ACCULL, 
            0xDE3F86C0D28AC36EULL, 0x2DBAFAE295E91780ULL, 0x082EFC3BF85056D9ULL, 0x5698CA7209E02B3BULL, 
            0x5D635E9365891CD3ULL, 0xDB27B1A7650544E1ULL, 0xAF83AAAEFE308FB3ULL, 0x4F90A455687A1D18ULL, 
            0xCC129515EB68DFB6ULL, 0xD4E60EA8FBBE78DCULL, 0x8E4DCE6C0A6BF649ULL, 0xD49A4ED55D7F0172ULL
        },
        {
            0x5EC8AE0E7E26F1AAULL, 0xED43E237BA5AED22ULL, 0x0DABAE9EF596A60AULL, 0x822D96F5834020DAULL, 
            0x91FB671A78B7D906ULL, 0x990D255B326A064DULL, 0x77817328EF75E59FULL, 0xD93C12928D765F46ULL, 
            0x4860C1DD42047A63ULL, 0x97CC54069EC2C4DCULL, 0x0AF44ABA3806E5B3ULL, 0x65E307F4E556BBD0ULL, 
            0xA0295CEBFD52D208ULL, 0x4BE172E5AF1F67B6ULL, 0xAA24AA17BD7FA22EULL, 0xE45C5A2E512103CDULL, 
            0xE90715EBD6488C0EULL, 0x46358C2AE775B93BULL, 0x202AB717565578AAULL, 0x95ADBA40FE1F2C13ULL, 
            0xD2BD874DE6BF72A6ULL, 0x255483F9600FE39FULL, 0x39C1DE53B998C687ULL, 0xBC9DB8F71BC65056ULL, 
            0x95A17B09FC7C6357ULL, 0xD0888F4ECE3E3B4EULL, 0x706ADF8691F1D150ULL, 0xCE506512F824B233ULL, 
            0xFBF88687D16D9C45ULL, 0x6E14732030E9F56EULL, 0x2A3FC54DE7B183F8ULL, 0x362ECC6302B0BDE7ULL
        },
        {
            0xC8C7A98A47FDF35FULL, 0xE61F3D6B359F15E8ULL, 0x6283F239823DBDBCULL, 0x962FD94ECDE7F0DEULL, 
            0xE9121BE1CD910772ULL, 0x58DDA1B4B96DC73CULL, 0x8B9A6F5240C78104ULL, 0x25CA69AAF8336721ULL, 
            0x70613821A6ECB04AULL, 0x6967CD9C55F4BCEAULL, 0x9C1A556EBBFE0B5CULL, 0x89DBB707B61C3AEEULL, 
            0x0E2BB2E916052BE3ULL, 0xE979118CC9DE9B80ULL, 0x00014DBFF1B42BCBULL, 0x2168E9AA87B858D5ULL, 
            0x56ED4D06E1C9113DULL, 0x1C39F9BA402A9952ULL, 0x1E824CCFACB47BB8ULL, 0x89091D7ADB4093F5ULL, 
            0xD502CDFC824580A5ULL, 0x0C52E649F41851DBULL, 0xCA1B0408845B591EULL, 0x82152071B92BAFD9ULL, 
            0x2901BFDCFFADAFF7ULL, 0xEE8BCBAC7C633D2FULL, 0x52FA0B01CC62B15CULL, 0x2AC94732D0FAA07EULL, 
            0x47A8F4B87484AFF7ULL, 0x69CB8E29AAA2CF8EULL, 0xC926AEE0A9FFC03FULL, 0x526E092E9B320B8DULL
        },
        {
            0xD2D81479C6CFFB1BULL, 0x8C1638384350A572ULL, 0x206B73D28FDFC48AULL, 0x2D8C0E98D25C542AULL, 
            0xAEEDD3170F13F950ULL, 0x62321B34DE4CF64DULL, 0x2A5FFE35C02109B0ULL, 0x4E1D88196941F802ULL, 
            0x0303F9D9BA6C083BULL, 0x4CD7B2C92624BF9AULL, 0x81573D7FE5931A7FULL, 0xBABB33536CBB72DAULL, 
            0xC11F49E4696B7162ULL, 0xC28CAE282E744B6CULL, 0xC45C8813E891F73EULL, 0x135451BE1059F21FULL, 
            0x6A4821C3EEC6E98BULL, 0x2AC91AE6B19F085DULL, 0x21113F4978F26EB5ULL, 0x06370BA7967B3DFBULL, 
            0xDBCB2D07EA8D46BEULL, 0xF893A71FDF5CE104ULL, 0xAF6B49735E999EA2ULL, 0x0077F3671C734619ULL, 
            0x94988E24DCF19AC5ULL, 0x00D8176FAD06E4C8ULL, 0x9A2599812DCF200AULL, 0x71C19A1B68EAB6BEULL, 
            0xD6640497B1F90883ULL, 0x17889FBAF93E2BB7ULL, 0x9C0D8CCA3F430E6AULL, 0x7F1078D0C4C98DA6ULL
        },
        {
            0x2E110E6339B44B4AULL, 0xAAF7D9587B374AAFULL, 0x079885A56FC3368EULL, 0x4E0E95F921EE2996ULL, 
            0x0B9747BC9C44EE7DULL, 0xA2B154667A9F100EULL, 0x8121179E26AB871CULL, 0xDA2E5DC3869F4B56ULL, 
            0xF070463B32AA8D24ULL, 0xF9152FE1C3AAEC41ULL, 0x5FB88F94F5DDC1E6ULL, 0xB2B64F149CD157C2ULL, 
            0xB4D68170F8BC121EULL, 0x792332BDD872809AULL, 0xBB4A2A44394A465DULL, 0x3129078BA3FE82C8ULL, 
            0xCF16D7DF50EB56F6ULL, 0x08FFA8BA0C69A9DFULL, 0x2B4A0DBE0CB70413ULL, 0xB4CAFA9C9C94615FULL, 
            0x445C9B7D8B7C4A6EULL, 0xC14025BDEF48C568ULL, 0x322A24E29A02533CULL, 0x61C5FBAD06E2A90EULL, 
            0xAC62A0F377BB9BCEULL, 0xA041549647E8D9CFULL, 0x8105B051BDD2735DULL, 0xB398AFCD6389EC24ULL, 
            0x8ADA84C147E86308ULL, 0xFC3194E84F18849CULL, 0x1FA0B400B2960B80ULL, 0xCBECAD2218B88380ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseBConstants = {
    0x2948412CC0DD1EB2ULL,
    0xB056DAFA11C0DB1EULL,
    0x5A36072FF9940144ULL,
    0x2948412CC0DD1EB2ULL,
    0xB056DAFA11C0DB1EULL,
    0x5A36072FF9940144ULL,
    0x4074ED24C85F994DULL,
    0x24B3E6903E085870ULL,
    0xA8,
    0xF6,
    0xBA,
    0x49,
    0x92,
    0xF2,
    0xE8,
    0xA1
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseCSalts = {
    {
        {
            0x3E73CEBF3B701FA0ULL, 0x5F3C43FA07ACA32BULL, 0xBDC4490FAE9D7A01ULL, 0x8A60415F40741257ULL, 
            0x2E330DF033FC1833ULL, 0x4A39D3E0C4E28CD5ULL, 0x59CCA58DA21DE0D5ULL, 0x401EBC4F17A35E05ULL, 
            0xB7341DB76F1F08D1ULL, 0x87E3F46EFF945304ULL, 0xF831F658E5535930ULL, 0x1716C917DBBFB79EULL, 
            0x26A7D8E0ED051E43ULL, 0xB4F598254DC0F933ULL, 0x73E29665D7734634ULL, 0x3D1BB3C50AA38ACEULL, 
            0x6494A4510ADC361CULL, 0xD31A13B742B63E5CULL, 0x825E5D649AA02503ULL, 0xC492160A038B392DULL, 
            0x37E87FFC46C365B9ULL, 0x8F8B0C50532E3DBCULL, 0x32F80E53121770FAULL, 0x17591AD47D0885B2ULL, 
            0x50CE89363ED15B61ULL, 0x20A85004150C44CCULL, 0x1CEF7B9C22DEC53FULL, 0x88231749DCEC9B4DULL, 
            0x7E1D486AD0EBDEB9ULL, 0x7761D3A6DB9EC959ULL, 0xDA9D8BBD383FB1F0ULL, 0x39B101902474DDA3ULL
        },
        {
            0x9F15F475C24A46B8ULL, 0x05D20CF4C2576E40ULL, 0xFF2C0583516DB2AAULL, 0xD006C0A4418F1268ULL, 
            0x2F220A9EF856951EULL, 0x9472EC57D0CAE67CULL, 0xF02E29FB1A436FD3ULL, 0xAA8FBFC949F743A7ULL, 
            0x450E213528ABBF1CULL, 0xF310569FB3DA65EBULL, 0x700CD73FFCBCC575ULL, 0x8DCA49EA13B5392EULL, 
            0x5E797BEE53CB9079ULL, 0x929F9ED15AB0959EULL, 0x2F917B0B7C846381ULL, 0x5C31933D09F41208ULL, 
            0x79B1C93549F60F21ULL, 0x2CE36BD935D4FBEEULL, 0xD6317ACD4DBF333CULL, 0xCF3ADE8B7F76E84CULL, 
            0x5B549EDFCBF358FCULL, 0x985EE5F896373CB5ULL, 0x2B98BF2D83E2BCA2ULL, 0xB204DBA0034623FFULL, 
            0x9D6E3AE89F19A100ULL, 0x724E0C465E1C63C3ULL, 0x483AA19ED7ECC2C5ULL, 0xA2675967E719D89EULL, 
            0xABD84A97E62478A8ULL, 0x705DE0D5F619F828ULL, 0x99C19FAB71C0EF69ULL, 0xCDD6F6DEC9393AF8ULL
        },
        {
            0x970BB4ECB072B3A3ULL, 0x508F2DD79057FF69ULL, 0xF2DA90ED5D82C677ULL, 0xF3940BC1B0361CCAULL, 
            0x81B2A435D3E87593ULL, 0xC776A3D8CCF2CBD1ULL, 0xFDA2CB7844D80BD5ULL, 0x7E9FE861B192D67EULL, 
            0x7EC391B8B077B2B0ULL, 0xFCD711E1C18A6DD3ULL, 0xBB502D866F476134ULL, 0xF61EB43D1105C281ULL, 
            0x2B972B22D1592429ULL, 0xDDBBC8B22FD46992ULL, 0x0263B0F5E2F556FDULL, 0x57912F92C22B1431ULL, 
            0x4B95EED97FBD5306ULL, 0x066C9F4E8229E331ULL, 0x4D07F55B8CCFC88CULL, 0xB33D527D398360FBULL, 
            0x134BA85717355126ULL, 0x623B95FBFFFD7133ULL, 0xDF90CB07C1E595D4ULL, 0x432AABE1977A348FULL, 
            0x0CC8912F744C7723ULL, 0x9B3965B32998162CULL, 0x64BCFF6786A990FCULL, 0x664D1B28BF2B3C4EULL, 
            0x69AA766A6775594EULL, 0x12F0594527736A99ULL, 0xF9900383D380EAAAULL, 0xF344799D94C7E4FCULL
        },
        {
            0x99260F0FC11C3E3DULL, 0xF2C00724F330DE06ULL, 0x81BB7FF930FBFDE7ULL, 0x35A7513C536F5E7DULL, 
            0x1BC8BD45260F0994ULL, 0x7AC5DA77277A4F90ULL, 0x417C3665C4F41897ULL, 0xAB91EB711976B695ULL, 
            0x862F94EF1000FD64ULL, 0x5069CAC64FA8CAD7ULL, 0x02C610A32AD5F340ULL, 0x1C41835E54E57494ULL, 
            0x8CB87FDD2FCCCF07ULL, 0x076F2D23EA26073AULL, 0x07D26C5B04BDCEFEULL, 0x52282C4ECA28D887ULL, 
            0x4940ABC632E6E82BULL, 0xC3E556B97DAB741EULL, 0x5B3CB73E8BEF45C0ULL, 0x576F433095415E71ULL, 
            0xEDB791D4743A532BULL, 0x1DAFC6F02C10310DULL, 0xE48406F3B559F0B6ULL, 0x46415F972478993DULL, 
            0xCBDD424DE335AB28ULL, 0x73029D66E369A29AULL, 0xB2D3BB581E188707ULL, 0x4A1C30D20CFDD687ULL, 
            0xF8F492915AAC8A76ULL, 0x19898B933159D363ULL, 0xC87502551C4CC6E4ULL, 0x6BF0FFB06A7A8335ULL
        },
        {
            0x548EC435EF5C1E6AULL, 0xC412DDB2C8DB4CC1ULL, 0x288D87CA6E189FCFULL, 0x8ECFB41BFA51551DULL, 
            0x08D40AED4141826AULL, 0x84EC9D8D8405A3E2ULL, 0x28C905967A4F7DBEULL, 0x226412A61E7EF908ULL, 
            0xD8462A0F0E3F358DULL, 0x148D06555016E267ULL, 0xF832CE40166DED67ULL, 0x85AF6665F7E1CA60ULL, 
            0x63A95A27787C1987ULL, 0xE966C0D7AB88F33DULL, 0x0C1EFD0C3AE685FDULL, 0xEF3FA501550B3AC1ULL, 
            0xB4085BCE1C9CA158ULL, 0xFEE7ED2CDFFE009BULL, 0x6E58B2122CCA6AAEULL, 0xCE1F6DD8A1B7BC2EULL, 
            0xE5B62B75ED58C228ULL, 0xD9344F998803792AULL, 0x5C3273F4B15AFA7EULL, 0xE4F3EA6D0F8EB49AULL, 
            0xFA404F71551F1975ULL, 0xD4607EACF044F4D3ULL, 0x6C33F54C09BFE2B9ULL, 0xAF23024791EC50DBULL, 
            0xFF5910143BB9E75BULL, 0x0B77A0AE61DF0D65ULL, 0x27C7F84305835C6CULL, 0x93E4F8D2D2C10CA5ULL
        },
        {
            0x4E05846535C3C4B6ULL, 0xC29F532CE2A8C6CAULL, 0x0A76C7BA110EC017ULL, 0x0CDD16DE11A9FFA1ULL, 
            0x9B17906EC8622929ULL, 0x862208F44EEEC9ADULL, 0x2472030AD39B5179ULL, 0x3B1F4C91FF806608ULL, 
            0x8C11CA5E0FCCA7A5ULL, 0x697CB7A2915F8D1FULL, 0xF0FDD9447A66D16DULL, 0xEE0877373E37C66FULL, 
            0xB78814C6982095F1ULL, 0x784FB9925D6BAB25ULL, 0x975B7C047468743CULL, 0x87AAA52CCCB1A335ULL, 
            0x6E085A027B5CE4B3ULL, 0x7DC6CC87F24D9792ULL, 0xF7D501DF35AF1D7BULL, 0x04BC7E3509ADD8D3ULL, 
            0x0C96BF99B646063AULL, 0x0C3421A8D413CBCDULL, 0xB013D48CD026BF35ULL, 0xEF22E2A40467B86CULL, 
            0x190AB99935EADBE8ULL, 0xF58983C8BD579EEAULL, 0x3D99F149F6E513A0ULL, 0xE20F556B43462101ULL, 
            0x037842B82370E37AULL, 0x58427E22827D7FA2ULL, 0x261163FC7037AD10ULL, 0x7364497557D48D4CULL
        }
    },
    {
        {
            0x752F7C7179947FA6ULL, 0x9583153DD10E0E44ULL, 0x0AE6CE3C98E28E16ULL, 0x8A035144EDCEB300ULL, 
            0x081D0CE0FBFF5BD6ULL, 0xFCB91D3746C8F932ULL, 0xF1E1D7118633FE4EULL, 0x84C176BBC9076EBDULL, 
            0x001559A0A06893E9ULL, 0x7EE847BF43357311ULL, 0x76B3CB00C7B4462BULL, 0x04326FBC76B89C46ULL, 
            0x971D86579E3A0975ULL, 0xC43894D17041CA75ULL, 0x53833A9727A6FCE4ULL, 0x33C3A8FE16C61BB6ULL, 
            0x2ADAE13B385AE8FBULL, 0x7C6B74DDE69E96D3ULL, 0x67DC6307B195397CULL, 0x76DC25CD2DA1CE53ULL, 
            0xFED663A966D4253DULL, 0x1399E793EC545179ULL, 0x7C436AC6D0A3BDF6ULL, 0xD3B3DBEAA065CE21ULL, 
            0xF67702AD56C65FACULL, 0x28AA94D241C1B347ULL, 0x65E85362D246A8D5ULL, 0x540CFBA0617536BDULL, 
            0x9768646CC7FB8CA4ULL, 0x0F152CE10B478D7DULL, 0xA99646F8BCF7D789ULL, 0xCED58386D7C000D0ULL
        },
        {
            0xCD351609CFCB2658ULL, 0xD2DBC140110E2E64ULL, 0xFCA4E046B350F8A2ULL, 0x3AC3B94685D08EA9ULL, 
            0x4EA8C78F652F66C1ULL, 0x88D7A8DE8E2486C7ULL, 0x89B70CF530EBB459ULL, 0x72333D64DA65CD09ULL, 
            0x4ECCD6BD4F6C7FFBULL, 0x658780B2DDEB978BULL, 0xF739509DB1D6C904ULL, 0x2AB16BFC8E7FA5A1ULL, 
            0xB5DDAA61343731BEULL, 0x706637E4E280AD56ULL, 0xA274F3B8B6009FC7ULL, 0x059449BF2AB2E165ULL, 
            0x7C0F32FEF1957C80ULL, 0xF0D9093B1718698EULL, 0xD7F28679AD420D4EULL, 0xF6BA11E77BFE2BF4ULL, 
            0x56C82B59E9121F11ULL, 0x37028A0BC2DC9939ULL, 0x4DECECA9FB9981D0ULL, 0xCBE9C62801A6C033ULL, 
            0xBC6211DD868A6AAAULL, 0x1D924B65C94A6AF8ULL, 0x42097F186F02AE11ULL, 0x424055AD54CFA545ULL, 
            0x5185BED804CEAEDAULL, 0xEBFD2CFB69D95B92ULL, 0x702E23D7D055A352ULL, 0x9B2961BEC8F2400EULL
        },
        {
            0x06907161F208C0CDULL, 0x4AFA616B68D0D952ULL, 0xD181BB781F756F95ULL, 0xD5392B031B4D0F6AULL, 
            0xC1979EC0A04F431BULL, 0x1C676DD4D5A43F97ULL, 0x255DF97CC24E0F7FULL, 0x9939DA24255312CDULL, 
            0x8667D0B7ADE6E8CBULL, 0xC391894151A29B63ULL, 0x767999F57C2D6BAAULL, 0x96D3B53058C7C953ULL, 
            0xA3BD014338C39DE5ULL, 0x0BCA76EFAF17716AULL, 0x164626CCD1E3594CULL, 0x865F437DA1F18137ULL, 
            0x52BF0EE446639C9DULL, 0xAEA28828AB47F7FDULL, 0xC221626EA466C03EULL, 0x304B2646C01AF8E2ULL, 
            0x7DA8701412A7E188ULL, 0x80FC8D1F93080A15ULL, 0x80C576866CBAC8F9ULL, 0x64A7956A546CFE9BULL, 
            0xBE86BDF284847838ULL, 0xD55044477E0A9AE4ULL, 0x4D3BE66C16C39B11ULL, 0x94F2B2C1F0D4C941ULL, 
            0xC64BB2CC77971557ULL, 0x1862CE5185B73BD8ULL, 0xE6CB06F4FF43FB5EULL, 0x6A559E1EFE71B878ULL
        },
        {
            0xCE8BF8F6E9415A94ULL, 0xEB7D560C82B23FACULL, 0x93E0C488D23A7E6BULL, 0x2C38BB9B2F6661F5ULL, 
            0x2CAA2E997FAEFD72ULL, 0xAAAAC701738B3E68ULL, 0xB9BC76F68370B48FULL, 0x1C8599838C6B82F4ULL, 
            0x2A44AFCD3E046975ULL, 0x3CCAA765B00B2797ULL, 0x034ACBB40CBB2C3FULL, 0x0747526BE7C90CEEULL, 
            0xCEB38231F4E1DAB4ULL, 0x803541F205392455ULL, 0xD0C5A5A92ADA8AFAULL, 0x225D7B3CB910AB0BULL, 
            0x552E39EAF5AD6D07ULL, 0x99254683CFFE91C9ULL, 0x9657EE69757DCF44ULL, 0x22A54DF889763CBBULL, 
            0x0BCAE32E896839C4ULL, 0xB702E6F7DD42DDA8ULL, 0xAD2C8FEAA1818E8FULL, 0x9F808B8C6E85B114ULL, 
            0x772D52B989316B1AULL, 0xF1A627FB09F7237EULL, 0x5B49D6F1ADD40EDCULL, 0x40BE8015CD411FFAULL, 
            0xB14CFA8BCF62E80DULL, 0xDA431EA8C0C90258ULL, 0x57638FE0B61B65FFULL, 0x4805CC48E2F7953BULL
        },
        {
            0x0837BFB16239CFA9ULL, 0xBBC40D75799636ECULL, 0x3387BCB586C7050CULL, 0x61C2EC7A9231086BULL, 
            0x450A7C2442BEA935ULL, 0xDE60F9A58B26CCE3ULL, 0x40E7F7A197EAE93CULL, 0x285C24029964C78CULL, 
            0x02B80E1BD89CFC5BULL, 0x3DEF5D97685F7B31ULL, 0xF3B32281AEF4930CULL, 0xE3633921E10B2F23ULL, 
            0x6860B11E969CF517ULL, 0xF099DCE6E7208B6CULL, 0x036A2CCC52F5B2B7ULL, 0xF976A8DD6D10EA57ULL, 
            0x4409927455EE8BA1ULL, 0x55CA8AB1C3C31313ULL, 0x17321881B6B4A654ULL, 0x406DE0F7C148482BULL, 
            0x3BB1BE0C875461F0ULL, 0xEE96612A6C23A308ULL, 0xEF35EB71F00D1FF5ULL, 0xDB1BEF1B8D0A71BDULL, 
            0x70F09351F7788789ULL, 0x4A88B10E2918C63AULL, 0xA5B7F8DA3C638650ULL, 0x0CF23F39A59D1710ULL, 
            0x25E9266455ACF785ULL, 0xD2ABF0CE2DB1BCE6ULL, 0xA38240698E25C638ULL, 0xBA61F0357150F9E1ULL
        },
        {
            0x0124FF23CAA86508ULL, 0x52B77C60068C877FULL, 0x9DDAA4661F251EF3ULL, 0x0ED2DEBE0E1C2598ULL, 
            0x1E6AAB5EEB61591BULL, 0x384BDCAC86EEB955ULL, 0x7CD3691A103377E5ULL, 0x174D76C69220E803ULL, 
            0x26AD072364435EA2ULL, 0x3E1C8ED55928E432ULL, 0xD490554C27C3E9F3ULL, 0x674CDB81E85D9861ULL, 
            0xF7E5FF35616E60FFULL, 0x511017BC96830F35ULL, 0x2295BABD97A2441CULL, 0xF8E36E51A0AF4EAFULL, 
            0x27B750E3ED2E1F5AULL, 0x09B4B80B30F31FE7ULL, 0xF527142D5774E749ULL, 0xD713C2F31E3150EDULL, 
            0xEFA15E829D9A72C7ULL, 0xBDF606EE3905E112ULL, 0x181A756D55A619D5ULL, 0xC402FBF96BA158A0ULL, 
            0x6982FCA80AD0E2C5ULL, 0x832F34F7D2D943A2ULL, 0x21141C722380CA4AULL, 0xFFD3B9FECDCB156BULL, 
            0x4AE6598A5C768241ULL, 0x9BC13020D55A361EULL, 0x3EBB0A4CE908EB95ULL, 0xA7C5DA33E386F15BULL
        }
    },
    {
        {
            0x19535EA3D1C107CDULL, 0x8B8DADF2688650C6ULL, 0x6373EA8D26873462ULL, 0x6063F1C8A40F479DULL, 
            0xAD3A9F35C9EE845DULL, 0x97944DB2AC2B8E9DULL, 0xB07760D73569A9F8ULL, 0xA2978A3C44451F21ULL, 
            0xC842A941081A584AULL, 0x73D105B22F7DB25DULL, 0x3E9FCB55B93F8B06ULL, 0xBD9029D84FA03D91ULL, 
            0xB13BA65CB0FC62B8ULL, 0x0FD0C6080D6F3046ULL, 0x009A7A74E7D6BFB4ULL, 0xC63BDAD459EAD773ULL, 
            0x1CD110655979F675ULL, 0x9E2F608DC6CA3EFFULL, 0x9242C2EB72CEEF0BULL, 0x2AD5957D28E7038AULL, 
            0xE1829D61B5D801AAULL, 0x22B3EEDAF6C7850FULL, 0x95467EC289231DB4ULL, 0xA1866B385D2F9617ULL, 
            0x77AB9A2E5E9B267EULL, 0x7DC2EBD9A7DD4A22ULL, 0x73E43B80DA7D07EDULL, 0x8925E57B1DB0783AULL, 
            0x7045EF606F3B724EULL, 0x99129F2608DAC535ULL, 0x1C1C3F1863261078ULL, 0xE61D877C1055CCD2ULL
        },
        {
            0x4DF947C3B090173CULL, 0x83BC50FD4A7D2FB8ULL, 0x4C30FE6C4FEE4DB7ULL, 0x3B14D181B4ED64D1ULL, 
            0x7899BF7A10C8D8BCULL, 0x4A4CE9435F0ECB7DULL, 0xD0129333550BAEEBULL, 0x3B9223A1958736D3ULL, 
            0x58178F941413FC55ULL, 0x954F0BEA0F349435ULL, 0xDC38406185D77817ULL, 0xFECB0911F61FB593ULL, 
            0xAF55F37BA140A242ULL, 0xCDA1DFCBF1E3FDCDULL, 0x1D957C6DB88EE311ULL, 0x3DFCC68997289386ULL, 
            0x1BDA44651424146DULL, 0x080920071432BEECULL, 0x1629282F7CE26E99ULL, 0x828D7C81D3F2D590ULL, 
            0x40C4B53D8E56854AULL, 0x29C3968464ABD568ULL, 0x09A5829AE790A86DULL, 0x7E44F65C21C79864ULL, 
            0xC413E79E9AB9F098ULL, 0x7DC3359E86092124ULL, 0xFF796CB1694A3407ULL, 0x1FFBFCE78A64C6F9ULL, 
            0x447DE3D4C352E345ULL, 0xDB5660DDAB3D68F8ULL, 0x379D16F08D32431EULL, 0xE7F126AFC4848F1DULL
        },
        {
            0x1F4A284F06804DF3ULL, 0xB7D0071040F313E9ULL, 0x72E389510DF14D06ULL, 0x2E498F73E950B3C2ULL, 
            0xD1C0E43ABD4199F7ULL, 0x2EF192E3DFD3E463ULL, 0x0BD2ECE4F6D1B73DULL, 0x85D46D71D12FB0C2ULL, 
            0x7FB3DEF87CC8BE16ULL, 0x8A3F01BDD004BEF0ULL, 0xAEAFDFB2E2904CA7ULL, 0xB214821DC98AC261ULL, 
            0xB0E8A485504A7A9EULL, 0xDB605A2808F725D7ULL, 0xF7429A5A2D1FD419ULL, 0xD78FE385B3BDF4BDULL, 
            0x011B18A4801FDCDFULL, 0x744E4633C04CDE85ULL, 0xD371E72209E85E84ULL, 0xF9D45B6ADBE05735ULL, 
            0x18641CEF23857BDCULL, 0xF7C004589F3240A5ULL, 0x71F31A9DA15A040BULL, 0xDCC1DEE7FDEF6FBCULL, 
            0x47AB61409713D87FULL, 0xA5B2D68503E41599ULL, 0xC8F6034E1C4393A9ULL, 0x1E296B986C00B52EULL, 
            0xAE6FB8C122D63DA1ULL, 0xB5743697F6E20A2CULL, 0x24462FFD94E9576BULL, 0xB3C9C7F347C09074ULL
        },
        {
            0x288961FF4516261FULL, 0x51559A04CEDA91CAULL, 0x39E44D3B78A63442ULL, 0xA762A248B1F1F11EULL, 
            0xB44EF64A4ABF898BULL, 0xDA2424109A39A3BCULL, 0xA06E23AE05D4C6B5ULL, 0x431B9BEBBA747411ULL, 
            0x7D82CA78F56AABA9ULL, 0xCC5783C4E6BBCD22ULL, 0xE82B8E934D213CA2ULL, 0x2CB3307CC5F1713CULL, 
            0xE330DB1EBA4389BAULL, 0x17E4A58C25E001EFULL, 0x93E69DD2C728EA5CULL, 0xCB2DE7D37F2DF3B2ULL, 
            0x804CB07E55E82266ULL, 0x9F61871CC1B628E0ULL, 0x6E57A7C173556E3CULL, 0x9F36EF29F48ADD61ULL, 
            0x047E65EEBC7E3338ULL, 0xBFC786D59973D8E3ULL, 0x2640E307CB75C84AULL, 0x7C877E314B1DD9E0ULL, 
            0xC9300A1005678A0AULL, 0x1938C960B7EBC72CULL, 0xDEF8418FCC22623AULL, 0xBD3CB571D1D5C7BEULL, 
            0x329B98BE015795A3ULL, 0x3611C614C26C5619ULL, 0x1226E361B22FA8E4ULL, 0x11AA0726AB473EDEULL
        },
        {
            0x42CAE5D37EA1540FULL, 0xFC5F2CAC864F4D09ULL, 0xF12B4CCBC4D95D0FULL, 0x1B2B11A2C9C75091ULL, 
            0x852EBF99349DDF14ULL, 0x10117C3488614A64ULL, 0xAC4D47E0D114AD19ULL, 0x077481CD49C7F96FULL, 
            0x095487D36AB11744ULL, 0x6CCF8AEEC27EEC84ULL, 0x55604917F5A31009ULL, 0xFF5DDFD9D97B6212ULL, 
            0x80058AAA59651087ULL, 0x1A5706F085EC537DULL, 0x1FC2DAC4CAF963CFULL, 0x5BC6CC292399DEAAULL, 
            0xCDB82DA1203ABA97ULL, 0x47F29CE85BC3A39FULL, 0xC5962958BA8FA9DEULL, 0x0FAB53E316107364ULL, 
            0x5284D58EF9011D28ULL, 0x3B6683E4B2FE6EB0ULL, 0x4E293C2B2A72EEFAULL, 0xC547257C0C890CDDULL, 
            0x1B7999AE6F692AD8ULL, 0xAEB3B0EEE5E5871BULL, 0x112946CBB1D0426AULL, 0xBD84CDBD0FAFA076ULL, 
            0xCC99A78E770530ACULL, 0xF3A20587B75EFBE7ULL, 0x4D361B4F9A038D0CULL, 0x25768330D69D76BCULL
        },
        {
            0x5992B1E6C193DA1DULL, 0xD3F3B194934DCF8CULL, 0xF63F51CA38DFA8F2ULL, 0x9385AA3D4444BFF8ULL, 
            0x9C1FC975A0EBAADEULL, 0x77C027922C23B8F1ULL, 0xFCCC2528F55C7573ULL, 0x947160B08E875382ULL, 
            0xF8E8BCC9C1C90773ULL, 0x55E16F328A9BD25EULL, 0x1657BD22BA794354ULL, 0xADCD4B027CA22EA8ULL, 
            0xF8361E1754F22F2FULL, 0xF58D9278D023BDA7ULL, 0x717E2560BE1EA127ULL, 0xE5CD93E7A3E83B20ULL, 
            0x0D18F1C16C1B5FAEULL, 0x285B684429C771D9ULL, 0x8D318BDE9A2BBE99ULL, 0xE4944DD1C20690DFULL, 
            0x67D2CA608DA4D27EULL, 0x60BD755BE8133B28ULL, 0x653FF3631C80CBB2ULL, 0x11347758BD81C1BBULL, 
            0xEEAE1261E30A5C4BULL, 0xAD51813270B33583ULL, 0x2A517EF81B179A1BULL, 0xF0F1EF23E06A4EA3ULL, 
            0x22037800269CB24BULL, 0x5CC78821212917E3ULL, 0xE7C1D16B377AE207ULL, 0x94D04E7C0ACD2100ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseCConstants = {
    0x53CC7232A5D4165EULL,
    0xE541A9CFAA84039FULL,
    0x0481D90EB8834906ULL,
    0x53CC7232A5D4165EULL,
    0xE541A9CFAA84039FULL,
    0x0481D90EB8834906ULL,
    0x93961049806833F0ULL,
    0x79BA9EF84447C958ULL,
    0x64,
    0x21,
    0x01,
    0x0B,
    0x40,
    0x70,
    0xDB,
    0x86
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseDSalts = {
    {
        {
            0x081D627B2155671AULL, 0xFF3A4F232BDE2D0AULL, 0x9196677BBEF802CDULL, 0x2FDEC534DAE96768ULL, 
            0x422BAC036315F6D8ULL, 0x97441A729A4CBC58ULL, 0x930DE0DBC40BF65DULL, 0xD1D516275A0BBE2CULL, 
            0x611F4CF1A0B90870ULL, 0x568A4B60FE44413CULL, 0x0A4E593CF84566F2ULL, 0x6FD6CB3408CEAB42ULL, 
            0x2137C4684A8CF948ULL, 0x7329F648298D3DE8ULL, 0x27D8D2860516B2B6ULL, 0xCE23DD67549533BDULL, 
            0xF3365883DCB0C8A4ULL, 0x821F5F067527F344ULL, 0x66DE898B7ED34DE3ULL, 0xF7F72A096AEFEFABULL, 
            0x1295B5E83E2B2D91ULL, 0x248CE43E37876FEDULL, 0x9C5CCF4643173386ULL, 0x9A6CD9C9AF6E9E6AULL, 
            0x86B052808CF180C2ULL, 0x8A6A9A9FB0675BC0ULL, 0x491A8D901AC5746EULL, 0x8C2E18738ED24262ULL, 
            0x47B5D4B227B4EB77ULL, 0x36C35EE0578C97EFULL, 0x4872C212E6E146ADULL, 0xF8DD208C4CDDF0F9ULL
        },
        {
            0x9265C2CAA26FCEE3ULL, 0x3361CA8F63CBC1BDULL, 0xE34CAFAE158AD1FEULL, 0x060D63A07D5E119DULL, 
            0xF8AB81F633DFD070ULL, 0xB59C73882814DF01ULL, 0x921FBF105C166362ULL, 0x776EF6827B3118F3ULL, 
            0x8615DD4AD1CFB65EULL, 0x207323997FA340B2ULL, 0xDB5431148546B30EULL, 0xCFC9E0062EB45527ULL, 
            0x502F4D895D28716DULL, 0xDC72569C8E754C96ULL, 0x6AF5A0DACBDD9A70ULL, 0x21CFA14FCF029E51ULL, 
            0xEC78E3E1EF78BBE3ULL, 0xE9AE12FE1AE2AA88ULL, 0x6A781079F12CEE8FULL, 0x837B9504C592AF61ULL, 
            0x46B1568820D800C8ULL, 0xF533047A76D8FD08ULL, 0x4A0BC9A985F01D8EULL, 0xCF0DABF383209D1EULL, 
            0xECFFC211E417749CULL, 0xD53BA4A95742AC5EULL, 0xCAF49EF176FCEBF9ULL, 0xEA5FBF4438D6DF08ULL, 
            0x5C2B30C28FF28FDCULL, 0x4D79FFC6D0CE2B01ULL, 0xDA8B3C8734FEFCFCULL, 0x249C482F7E08F9FFULL
        },
        {
            0xCBB162A5C82C0541ULL, 0x30F9B5EFF65D2B44ULL, 0x976438018DC2AA0BULL, 0x07FB4E96D190834CULL, 
            0xC7F1C60264DFDCE5ULL, 0x393CB89EB5452DEFULL, 0x42880E370E3C2322ULL, 0x1CDCEEEDF0221B1CULL, 
            0xB57A84FF6E274120ULL, 0x0B498D82E27F682DULL, 0x294BF8EFF61DC024ULL, 0x696C20DD11BAC76CULL, 
            0x075A2514F2D1949DULL, 0xD974059AEC2DC98BULL, 0x688E311659C3027DULL, 0x27FF7ECF251696BCULL, 
            0xA2EA7CEE4DE7476CULL, 0x1815C31EBF976A07ULL, 0xB09A0277D4BCC71DULL, 0x50C3ECF282073496ULL, 
            0x8AD0B4E95A6A1DCCULL, 0x39A0C3CA8629D422ULL, 0x14D0138C25257F81ULL, 0xE58DEB98439B9E92ULL, 
            0x7A1CBEF1E3169921ULL, 0xA30F78D392EA65CDULL, 0x04DE1BAFD0F7CC17ULL, 0x92E29BA9A272DDDAULL, 
            0xB8C791085EEF8069ULL, 0xA516CF9C2FD5F269ULL, 0xC995D5D9266EE8F3ULL, 0x9355BD9C1E9C1857ULL
        },
        {
            0x67A2DD16D8EE1EC6ULL, 0x1530C1F423904B06ULL, 0x91280F750A878077ULL, 0x97C93669C4BEB2B9ULL, 
            0xF1BF4A241220B12DULL, 0x2FDF30E25B02BF0EULL, 0xE792144925BEAA3AULL, 0x4467BA60B0508236ULL, 
            0x017B035D3A88BD26ULL, 0x1AF219DA8BC811F8ULL, 0xA5365422C59561E8ULL, 0x85C3CB93773A712AULL, 
            0xD0AFD535A4A1BC7AULL, 0x6C26BC6B20D686F5ULL, 0x34E04CCA4AF756B8ULL, 0xF99A3CA4DDFFF623ULL, 
            0xA50C3EF6C1E86EF9ULL, 0x8A1A279C79673199ULL, 0x5ECDE470244DD111ULL, 0x462190ADAF4DD7CCULL, 
            0x148ED01F63C8A14AULL, 0x7B3F1F5741D1E976ULL, 0xC4175957D765D19AULL, 0x6509071DAA9D7D4AULL, 
            0xE7231B90B4AE197CULL, 0x8410112833570B0DULL, 0xC02F11DBB3309B71ULL, 0x0FD84BAE028E06B1ULL, 
            0xC352AA9E13C71A2CULL, 0xEF51796ECA4880BBULL, 0x73ECF19B8AE8A469ULL, 0x1553439E86DA073BULL
        },
        {
            0xBE8E795830491D70ULL, 0x71C9E64882FE195EULL, 0x2C8995AAE2FAD931ULL, 0x8183A929293A8295ULL, 
            0x2ACB113BECAFAF28ULL, 0x6FAB5FFD2245BB42ULL, 0x58784DDF80CC301BULL, 0x25D2AFC5A9B72731ULL, 
            0x5E304584D0377A6CULL, 0xAF6724249357C743ULL, 0x95BC08B659D58ED2ULL, 0x9F88CF158E2FCD5AULL, 
            0x293B754F28ACF28BULL, 0x7576798002DB354DULL, 0x82658C856FD177C1ULL, 0xEFD1DD675EB30A2EULL, 
            0x154B70C0BC8CC4DEULL, 0xC267903BE524A66BULL, 0x8E986F60F621DCF7ULL, 0xAEF912CEA21183B8ULL, 
            0x9171FB6F0D429018ULL, 0xFF958C64E782A015ULL, 0xE119524A090074C9ULL, 0x37545ECB038CC4B1ULL, 
            0x7A7682387D539DAEULL, 0x2BA59B6F8C5B5C68ULL, 0x455B4038CC59B5C4ULL, 0x5DC32F9821FBB006ULL, 
            0xCB05BE505EAE0A3FULL, 0x2D9A3FF1FE8FEDD7ULL, 0xA9CC311DCA32082AULL, 0x28FA7BA131BFDF19ULL
        },
        {
            0x81B9F3BACCBA5E25ULL, 0x34CE90E321AAEB8EULL, 0xF7BE7445E730C7F9ULL, 0xA103E6E907CEF76EULL, 
            0xA097291CC2D799E6ULL, 0x5CE64257210876E6ULL, 0xB3CBB7B0EB70E4D4ULL, 0x42FDE42C34DCFCB7ULL, 
            0x58469132615D754BULL, 0x6A96C0D46E4C93DDULL, 0xC292ABCD6046380EULL, 0x9244EDA28D9C831AULL, 
            0xD72E4953BA270BF0ULL, 0xCE1EE45F3E24FE07ULL, 0x80127BC5DCDFF0ADULL, 0x9247CFF53ED9078AULL, 
            0x23546E500B700575ULL, 0x1E575696C152D5B0ULL, 0x0E4394C88FB6FCBDULL, 0xE2412B57E2264605ULL, 
            0x2E74844C8A5CB5E4ULL, 0xC22E2DBF02A98FE5ULL, 0x20DEFE3854F15E6BULL, 0x98C8633D0093D950ULL, 
            0x4FB8F06FB82F6567ULL, 0xAF8FFF51D362957AULL, 0x71ECCAD153AE46D1ULL, 0xD1160820BDC5A4F1ULL, 
            0xD2FCE294EA1364D9ULL, 0x6DC27D8DE427BA9CULL, 0x08C8710C6C94E7C4ULL, 0x9144C7DD6A71BCB4ULL
        }
    },
    {
        {
            0x0A80A7A782003870ULL, 0x32FEDECF7A1F304AULL, 0x66277E32C4D5AD94ULL, 0x618BD1EC58935A4EULL, 
            0xB8414E0A027974AEULL, 0xDEC40CDC79E55477ULL, 0xFBFCFBAC3A872857ULL, 0x3FC9B3F060555530ULL, 
            0x40631218DD9D088BULL, 0x434BACFF9E75FC5BULL, 0x637871276E1837D8ULL, 0xD6EF5522F77063E5ULL, 
            0x0E6A671D13A4544EULL, 0xAD961C2AB96BC0E3ULL, 0x54F10224089B882CULL, 0x622BAB4C5B678926ULL, 
            0x065B3A0E060B30AEULL, 0xC37237F7816CF8E6ULL, 0x022A9C3CF703B0F6ULL, 0x691AB2E8D834D0B8ULL, 
            0x2ED1DA11C1264B8DULL, 0x078451E62B529743ULL, 0xC51816EB1FB7088EULL, 0x1D0380CC2D0991C6ULL, 
            0x904EBDF50EF065C9ULL, 0xCFA0BA356315774EULL, 0xE3B195574E9B7720ULL, 0x3A308DA9DAC7606DULL, 
            0xE0508ADA9A2B7207ULL, 0xE0CD46477EF55E17ULL, 0x338DDD53635C39B1ULL, 0x981C340BE6548725ULL
        },
        {
            0xB34394E679466E30ULL, 0x6F6A9D0229E66463ULL, 0x7FBBE2755FE4042FULL, 0x23A87018B326DC9AULL, 
            0xA67B238C47F2F9C8ULL, 0x4DF294668211876AULL, 0x05687A23BE043954ULL, 0x146B0A39666F0C6BULL, 
            0x800DF89A4E42A19AULL, 0x708D41540A2FE71CULL, 0xB7DF77FAEF3DD583ULL, 0xAC3869F0C824E9EAULL, 
            0xBB43CD919FBF38E3ULL, 0x74F73D612281D249ULL, 0x83A6CED9BB7643DDULL, 0x7E1BC9B377409D5FULL, 
            0xC9CCFB8FD4998D15ULL, 0xF4556847845B4C05ULL, 0x0D322CDBF4BE78CFULL, 0x41A6BB976894ED27ULL, 
            0x81AE8450D4C09CE0ULL, 0x7C9A6B92C8A7273BULL, 0xED99A70CE109117BULL, 0x936978C11FBB3239ULL, 
            0x422174D4E0BE007BULL, 0x9E3CD23F8E050534ULL, 0xA204FF81D91B42BDULL, 0x7B9C25D2B03CDC15ULL, 
            0xE2FC68EC09D60BAFULL, 0xCE9A0AC5C39170CEULL, 0x617E1525764B71DCULL, 0xA7171007BB266E9DULL
        },
        {
            0xF07238CACB87FBBEULL, 0x5A0C6CD593904E17ULL, 0xC2E0240245C0ADC6ULL, 0x176B22B502413E04ULL, 
            0x342237144128536BULL, 0x216C3F88749C5AEAULL, 0xD73F4025A658EDDCULL, 0x619A21416C117818ULL, 
            0xC479A5E29BD3C703ULL, 0x11AEF6BE22A46517ULL, 0x3508BA6B0477C3BCULL, 0x15A4C2C5ACB44609ULL, 
            0x81DDFF085CE7415DULL, 0x79F8F3860492DBD8ULL, 0xB76B24798DC15DF8ULL, 0xE2A39225E4D165B2ULL, 
            0x7E1E7341F111B8E2ULL, 0x627A6AD51256D33CULL, 0xAC41A92E8A0E3D41ULL, 0x62948A8E69FBCD11ULL, 
            0x04CE3AF425326C05ULL, 0x3928A620320E8762ULL, 0x8C6FEEBE9D0AE345ULL, 0x2D41E5E3D0E8B7B0ULL, 
            0xB9D07D38D01BA9EFULL, 0x1372A186501A3840ULL, 0xA14AEE249D2DFCD2ULL, 0x63567EB11799AA8EULL, 
            0x50B2B77789E49C69ULL, 0x4E8F1648C8BFB651ULL, 0xA9FD454CBB27C368ULL, 0x01596FA79CC1CC12ULL
        },
        {
            0x5306B9D2763C1F7EULL, 0x0C0CE62932E6A157ULL, 0xC4925D0C1B6BD270ULL, 0x504102655C8B9E20ULL, 
            0x2BF7CA12E8D7F559ULL, 0xA2D8AF0E6539434DULL, 0x593605C5587A846DULL, 0x8307DDC640A7B8ABULL, 
            0xA7EFDB9A49250240ULL, 0x2E941EBF97C58E97ULL, 0x08DB103E2CB2D046ULL, 0x34DBF1D1C62E6733ULL, 
            0xF8B9CF73DE7444CEULL, 0x2A11C1C26308B68DULL, 0x03633876D2C2C661ULL, 0x37E45D3937B1C9A7ULL, 
            0x06D5F773CEBFB631ULL, 0x40ADE89747F4D2FBULL, 0x93CE2E79FC258B58ULL, 0xA8226BFF327DED22ULL, 
            0x51787DE425553E5DULL, 0x4690DEE534A2B1E9ULL, 0x1D0A55D31EB2C0D3ULL, 0x1952BDFD57D6CFB2ULL, 
            0x593F11A45026EA9CULL, 0xCE111A77301B7EBEULL, 0x987700BBB8E8330CULL, 0x4EEDC2FC275A3B70ULL, 
            0xA44F3C6D2AC5FA4BULL, 0x12B55914CF9A7485ULL, 0x9AB8E67B013FDA2DULL, 0x5D4F76C73C85C7E5ULL
        },
        {
            0x3EF65604D4DC1096ULL, 0x708571B07D2BAAE2ULL, 0x9B91209AF464741DULL, 0xCD748EC904FAF8E7ULL, 
            0x4133E7AE86EA66B4ULL, 0x3B80748EE399FD54ULL, 0x9789DF0F9D0861FFULL, 0xDF5101835223A651ULL, 
            0xBAC998EF11E82CA3ULL, 0xF393C9CA0EA1ECC2ULL, 0x47C514A4E73226EAULL, 0xBF059C29EE225F1CULL, 
            0x86336CDA841385B4ULL, 0x7A2360F05A4A93BCULL, 0x1537D1150754451BULL, 0xA427C602386D06A9ULL, 
            0x2339C64A2A6D2BBEULL, 0x622BD76B7645569AULL, 0xC86EB92A38D3FE93ULL, 0xA892857C5B72791DULL, 
            0x68DA5FB9A7EF1FE0ULL, 0xB6CCE581BD539398ULL, 0x089BA16A13818516ULL, 0x9C692BBDED91C76AULL, 
            0xD8F57D0DDC259A2BULL, 0x6658AE7729374471ULL, 0x31EC7C7DEE6D22C8ULL, 0x2EEAFE16DAE6A6E3ULL, 
            0xC6B3159445981A6AULL, 0x18E503DEE2B185AAULL, 0x7C0121D94C922015ULL, 0xC1F7C67A09456D13ULL
        },
        {
            0x0E3D444884890DC4ULL, 0x23A0615B038C3063ULL, 0x2814F66209E906E6ULL, 0x6E3CF0652D09161EULL, 
            0xE76F2ED2EAD53BDFULL, 0x23072CA4EA45B5DAULL, 0xD79A1F1902CFE496ULL, 0x803C8E6706D3C420ULL, 
            0x8F8F76FF536E9FCDULL, 0x5A933292A93F8168ULL, 0x4EB6B6F6BD983FE1ULL, 0x2A4A0DEDB8AEE111ULL, 
            0x2DF90BB1D7BF8847ULL, 0xBB3DB5CCC07B4891ULL, 0x329A4889EEF18FDFULL, 0x179416AE6CA670DBULL, 
            0x3234D2B59844494AULL, 0xFE23AE602B144171ULL, 0x94E18C839E8C0372ULL, 0x4C8BCF83783D7558ULL, 
            0x37FC6D8076DAD949ULL, 0xA7B319ADEC31DEC8ULL, 0xB135443CB0B88150ULL, 0x03B1503CB6FE4777ULL, 
            0xDCA047D4EFD2826EULL, 0x6A3C71B3C4C8F9F8ULL, 0x7DA5612696C03A51ULL, 0x9AAED8FEF32FBEB8ULL, 
            0x1A18D7157A032508ULL, 0x78D7167AB5BCD8C3ULL, 0x500A42FC406ECD03ULL, 0x6D0658152AC386E2ULL
        }
    },
    {
        {
            0x3BB1849718710854ULL, 0x104C9E51F9997C9AULL, 0x8C999D3977E516A4ULL, 0x9C2053E0B4E34BF6ULL, 
            0x7C87E526E2B77CDCULL, 0xC2A07BFCA8F4AB3BULL, 0x598785985EEF8CB2ULL, 0xBF88DA73DEE0BAA3ULL, 
            0xA4A8DC0ACF541610ULL, 0xC0FA1418C2B42A0CULL, 0xFB7F4FD810D1456FULL, 0x33992763FC74041BULL, 
            0x5E1122BFD08ACB94ULL, 0x33F37B9EB0CAC9C8ULL, 0x5467776B977C8DBEULL, 0xAF8E843AFBF3B55DULL, 
            0x9660CBA6A3D30EDBULL, 0xFDD0EA9A1EBC66C7ULL, 0xD086CCD8A700DC83ULL, 0x4B8C0B42F9FE61BAULL, 
            0x0FCAEFDFC85F028EULL, 0x79A98D4AADF2847FULL, 0xB5867EEF3488B454ULL, 0x97A877C0F077D50EULL, 
            0x74523C3926D5DE41ULL, 0x70F159AACE052AE1ULL, 0x3389424D68853E14ULL, 0x1258209D9B66E56EULL, 
            0x456BC7EDD5F96AFDULL, 0x0B9AAEF491F95240ULL, 0x65ED348E98CAADA4ULL, 0x997287FE782ACA2FULL
        },
        {
            0xE66C0C194AD4C046ULL, 0xB89E680B0D0AB021ULL, 0x351E9CF16F34D928ULL, 0x128A52311BD5BE8DULL, 
            0xCABBC2346EC5723EULL, 0xCD4532BB7A569918ULL, 0x21844BA3F47412E0ULL, 0x4D6FDE6BD2BE5678ULL, 
            0x4E883411B3AB0FEBULL, 0x9A2602912194D9E1ULL, 0xA855B340832E5064ULL, 0x82EC2AA60C0E51A5ULL, 
            0x9863CEA189AC58C7ULL, 0x8DE4733E86C94432ULL, 0xEA61624897369BFAULL, 0x68865DE414E39ADCULL, 
            0x6EA0F6910CCD43B0ULL, 0xFEE915DEA890ED34ULL, 0xC33290D68E7D25CAULL, 0x39C2E8A4B4951F2EULL, 
            0xAE8C7076C649816FULL, 0x248B58B07F5852D3ULL, 0x2D2601A27516E163ULL, 0xB116FBAF27E2E9FCULL, 
            0x5B2378C0DCC9C764ULL, 0xF7651D96658F1402ULL, 0x5D5DA6ED5EF5A38EULL, 0x1B150ED9A785E061ULL, 
            0x93E3F841D0029673ULL, 0x8C5F70AD985E8E0EULL, 0x978BFDA3040ECDF9ULL, 0x9454B71277EDD235ULL
        },
        {
            0x3E852EB785F9AED9ULL, 0xB874B5966630767AULL, 0x41886018F053B72EULL, 0x33A13770C3B298C9ULL, 
            0xFBAF8EF523949907ULL, 0x134C4CA432032BE5ULL, 0xDE8FEA18B4484184ULL, 0x4604B48D1F783CCAULL, 
            0xB7E8F1047492E459ULL, 0xBFA61615705428EEULL, 0x22BA4142EFFF91C3ULL, 0xF655DF238D97B299ULL, 
            0x300EA0BE1BB47896ULL, 0xF667AAF038C1F5BEULL, 0xFF11939D8544091DULL, 0x9126D6AB6D0AD819ULL, 
            0xF06FB8F0A4A2497BULL, 0x166B0B6BDF43C547ULL, 0x4E55B3E9A783932EULL, 0xDB4F8A40B3AC67D1ULL, 
            0x3BF4B1A36D227AFFULL, 0x4AA212912A6A9A93ULL, 0x63C6513C6C42E92EULL, 0xD1BE89BD5B5832C9ULL, 
            0x3416925411B2B7DBULL, 0xA8196FBF460C84F8ULL, 0x3C52117DC98F6002ULL, 0x372911D4A1D7A248ULL, 
            0x2B2F19D8BD9AE37AULL, 0x8B0475B01FA96525ULL, 0xB8F37039ED26053BULL, 0xACE80991402E4278ULL
        },
        {
            0xBCA88511771A7FA4ULL, 0x1F29BBEC9D17BAF8ULL, 0x2BE6941F4052F9F8ULL, 0x7FBCF3C62ADAF0C3ULL, 
            0xD662752FDC8DCE5AULL, 0xF7897CBB4FBF56A7ULL, 0x3F7460F1D603BE1EULL, 0xA11B295541C40239ULL, 
            0x4EEA5254E9741766ULL, 0x5910BF6D129C236AULL, 0xB9AA88B94CB0815EULL, 0x6A33DA2F4967433CULL, 
            0x92530DBF37F20FF2ULL, 0x48DFCF1DF3296315ULL, 0x66FB2EB3101DB63BULL, 0x7CEBFC67053A7238ULL, 
            0xFDCD4540048E0FCBULL, 0x03484766FA6447D6ULL, 0x5C0C42E57EC79823ULL, 0xDA6DE8AB2F7E9B03ULL, 
            0xAA57A8B9BDB6B931ULL, 0xE3689E259EE8409BULL, 0x917B4A0B5C61B75FULL, 0xC736DCB579D508ADULL, 
            0x3BD1FEFFF15CFF73ULL, 0x08BC0E9CC3A3C2A0ULL, 0x072EE5D60C5E8E69ULL, 0xFD545955DC7B0F1BULL, 
            0xB9A89A79E78DDE99ULL, 0x868DB74F56E17B86ULL, 0xCDF3CFAEEEC7B4BAULL, 0x1105871AF7146ACFULL
        },
        {
            0xC47DC000008AA15AULL, 0x53D202BF6848FB5BULL, 0x768EAD8EC5211735ULL, 0x5AC3F8DDE238D441ULL, 
            0x975D0287477CBC05ULL, 0x5E0454748CA4D762ULL, 0x642D80694176DD00ULL, 0xF9888E4660B12E16ULL, 
            0x5924F0EF515F216FULL, 0xD35B92FF202E2E40ULL, 0xF0CB9FC4D40B54AAULL, 0x71B3262E9D651A04ULL, 
            0x2973001694BB299DULL, 0x87E0ACFD26360636ULL, 0x200CA56F040A4C77ULL, 0x5F82529970108914ULL, 
            0x61FC8BA53C7FAB4DULL, 0x10CFB73B170E8987ULL, 0xDCD4FC241502A27AULL, 0xF0D141FB281DB9D8ULL, 
            0x75BCAACECCE0DF83ULL, 0x623C7A5C1B6A908DULL, 0x5F9A6B729F75A503ULL, 0x405FAC02E35E2E21ULL, 
            0x9BFA945B00BA0A12ULL, 0xEEFFCC95DB42451CULL, 0x7A2057D72BA0D3AEULL, 0xA47A5C01709B212CULL, 
            0xB129840E8580A3CDULL, 0x16EB9874307939CAULL, 0x2C9B81DB1BA7C05AULL, 0x97F65DB91AF42FD6ULL
        },
        {
            0x988AA81F1C1750EFULL, 0x1385333E267BACBDULL, 0x43E55ED59CBB5020ULL, 0x74F7429711A3A6BFULL, 
            0x60E2E4E652379AD5ULL, 0x031AE7AC6705B2DCULL, 0x6B2304E2A38F5324ULL, 0xDCFCA1270946B448ULL, 
            0xCF1359FB749CA231ULL, 0x9CEB2CC21F0A1521ULL, 0xE8A8727EAB784BF4ULL, 0x013F8AD4F36BC2F8ULL, 
            0x7D874C3A592F1F43ULL, 0x0A03A5E59F63C9CBULL, 0x84C5600279A4CC7DULL, 0x79213E9D18A40900ULL, 
            0x7B3B0C3247770791ULL, 0x80C27F088A8F9374ULL, 0x41CFF7CE31A49316ULL, 0xF322BA81D22EA093ULL, 
            0xDE08AC62605A9F7DULL, 0xFF1FB22274CBEBCAULL, 0x818075DC1C9F2DE7ULL, 0xBB0C042E644309EFULL, 
            0x2F3910EFFC839596ULL, 0x556165CEE71B2C4DULL, 0x2962DBD0763C6EA6ULL, 0x878FC1B0C2653947ULL, 
            0xE6DED65122AF628DULL, 0x9F416E006C690A3DULL, 0x443A6496D00ECA11ULL, 0x0DB83BD14AE05E65ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseDConstants = {
    0x37C1A557F4CE2101ULL,
    0x57A20C522D322F27ULL,
    0x501A7005D24199B3ULL,
    0x37C1A557F4CE2101ULL,
    0x57A20C522D322F27ULL,
    0x501A7005D24199B3ULL,
    0x90626D9006FDDB63ULL,
    0x130F618768D70CBFULL,
    0x04,
    0x8C,
    0x8D,
    0xDD,
    0x8C,
    0x03,
    0x9A,
    0x63
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseESalts = {
    {
        {
            0x21C70AD21A1D90BAULL, 0x3154110C172E8186ULL, 0xF5DBFBF2B0816814ULL, 0xE9E78558100B30D8ULL, 
            0x0BD7705167715B0DULL, 0xAA5E5EC079A2A574ULL, 0xD82C0476E6BF31A2ULL, 0x5EADBAFFE2E3FC2CULL, 
            0xA1C16399CDBEE9AFULL, 0x297FBC91632BFBF8ULL, 0x5F3C9737CDAE839BULL, 0x41B5113C4BE6B0C4ULL, 
            0x77F963B398979C0EULL, 0xF95C83163356E482ULL, 0x9C90D511D802DDBEULL, 0xB6AE75884035A259ULL, 
            0xFF3977A9E8ABE2E6ULL, 0x2A6500FFBD2F28DDULL, 0x77EBD90C8100FA7DULL, 0xFF6462DC590F2310ULL, 
            0xA54F302CD4F36555ULL, 0x44FED8A7FC8723DFULL, 0xED6BB0E6FA8DF072ULL, 0x4AEFB9448483A0B4ULL, 
            0x9DCA94906A2F75B0ULL, 0x1F4D78F5F3550A7BULL, 0xB31BC8791B496A89ULL, 0xBDAFCC4211839212ULL, 
            0xCF9C19874E3E1749ULL, 0x83A95F7B0568A627ULL, 0xFF6FD097F02C3C7DULL, 0xCF2DB9AE0B8F03E5ULL
        },
        {
            0x9907E2435C960054ULL, 0xA2DF977276C41547ULL, 0xBA0E422C97DD9AA2ULL, 0xD6C58EE0B2749FCDULL, 
            0xD0E3B3F6B8BF7848ULL, 0x9D33D4FB31A967B7ULL, 0x82019337B0570010ULL, 0x097D58D3FC66B806ULL, 
            0x914E305B9D92D7B3ULL, 0xF2F8A2331A4E031BULL, 0xC15888578D6C5EC9ULL, 0x0303E09365435E09ULL, 
            0x92BA496CCCDEC2DAULL, 0x1F9FCE49F96BD97AULL, 0x3477E231118417C2ULL, 0x91E4ECFDC94827E9ULL, 
            0x51C8F707064083BDULL, 0x1E7FF09F93801F2CULL, 0x483C058A6F7E852FULL, 0x08B68964D0859B3DULL, 
            0xB153C85168343FDBULL, 0xF595ABC88C0D4B00ULL, 0x1009FC0D1CDDF836ULL, 0x3302081881D25B1CULL, 
            0xE0A32E730281F204ULL, 0xD6E0475CDE76478CULL, 0x44B7567FB6076739ULL, 0xD87412BD82D68034ULL, 
            0xBA8C40F530DC63E0ULL, 0xBFCF775A1C76F5A0ULL, 0x1122DF058C21E5C6ULL, 0xA0339C327B6FB819ULL
        },
        {
            0x34FA7DD0C1DD4028ULL, 0xF35301FE85D52768ULL, 0xDCC4C2BF584423C7ULL, 0xA7CD2171EF1A7999ULL, 
            0x6A552AEF3B28756BULL, 0xDF19424A5EFA7CD1ULL, 0x6366967A0A209AE5ULL, 0xA8965C29F2DD84ADULL, 
            0x74C8CF6212D07D41ULL, 0x9122C48D9C00F302ULL, 0x96FBFFB264C9B759ULL, 0xF098F6EC9D8DEEC2ULL, 
            0xB6BD5754D07897FCULL, 0x90C2CD263CDC6C84ULL, 0xF6B997AC8ECF2285ULL, 0xDB7B574159EEDEC6ULL, 
            0xFE93063123CB753DULL, 0x699BBD5AF0F984DCULL, 0x7156573620525779ULL, 0x2802132BBEBAF94BULL, 
            0x5188B639E1171C99ULL, 0x7D9188C33FF88A12ULL, 0x8AD6900C74F6310BULL, 0xDDBCFAF7381761BEULL, 
            0x7B34E689965371FFULL, 0x7A113B5CD6243655ULL, 0xBEF14E39D08DE490ULL, 0xB75420B3B60DE214ULL, 
            0x089475AF56245F80ULL, 0x76E044EE53671429ULL, 0x0570E05A39A7D42CULL, 0xCC87056C7F35F873ULL
        },
        {
            0x3C1B6B653587C60DULL, 0xA59B6396138F9BCFULL, 0xB3EE0B33C11B9755ULL, 0x2F8221433D67EED3ULL, 
            0x4DC0D0267019900CULL, 0xD0DB5D4BF5D1F995ULL, 0xF4EC6FA80FEDDD7BULL, 0xCD5D5CF01EF0474AULL, 
            0x09E114E25813B840ULL, 0x3E9FE6441308E4BFULL, 0x2F9CB3D9DF56DCFAULL, 0xDD4F51718930BB6DULL, 
            0x00D3BC9CC5B7B2D5ULL, 0x379BF2816FFD5136ULL, 0xAC77B9E37C619A13ULL, 0x202FC8483AF65DAFULL, 
            0x07A431838E596F18ULL, 0xBE13E55D1A9BDC75ULL, 0x4C579C8CB15B913DULL, 0xA6EF5D1CE56FBBA8ULL, 
            0x0A34E3D8280AC584ULL, 0x0AA005666B9755C8ULL, 0x68C2888D43D73100ULL, 0xBA24F89913EBD3EDULL, 
            0x0AE77E0B333F1893ULL, 0x6E8477B53AB65157ULL, 0x3614A5FC33303570ULL, 0x8A287D04AFE8DDABULL, 
            0x49E69178D1DEB232ULL, 0x809FF01989451718ULL, 0x2FB5E861891AC01CULL, 0x56546E04234A2AEAULL
        },
        {
            0x61F87F6EFA06318CULL, 0xDEA3574EF81308E7ULL, 0x9042BDFA101BB12BULL, 0xBC00488D31031DC6ULL, 
            0xA2C4AEE312ED23B4ULL, 0x18CD41F55D71BB3EULL, 0x8114C0856D0EB7CFULL, 0xDFC446EBC93A04D7ULL, 
            0xD9EF72170460F286ULL, 0x0777D55732D4A8FCULL, 0x242A69BFFDFF329FULL, 0x05A7018AD42C475DULL, 
            0x7E9F208EC916FDE9ULL, 0xD5AEFF209C5259A9ULL, 0xBC4C72B203248887ULL, 0x39D62717746310F1ULL, 
            0xAAF9C7EB489AAA13ULL, 0x31AA415CA0DDB111ULL, 0xA375BE80DE75DC29ULL, 0x00E512F9C81696ABULL, 
            0x05E2392476148001ULL, 0x8E2A2E752D9C572EULL, 0xD98EAAB155057A16ULL, 0x8DAEF8329EEA3D4FULL, 
            0xB753D03DBFE68341ULL, 0x509853143F0BF999ULL, 0x3982283ECD2BFDCFULL, 0x5EB3647E2D7B82F9ULL, 
            0x66A7700E1B4F34EDULL, 0xA48CD3A5CECBDD99ULL, 0xF613F4BDAE9B5E1EULL, 0x82F779C7B284331DULL
        },
        {
            0x7DD320DE5AA1EC3BULL, 0xBEC73AE16B7B90E6ULL, 0xCA6937CC53C08CFDULL, 0x9A534301862A0161ULL, 
            0xA02C5ADE3B05207EULL, 0x1CFBFAC32CF105CCULL, 0x5DEB36167A5015A4ULL, 0x7E89E2EBA2AC8DFBULL, 
            0x61D27A95A260D590ULL, 0x73867814DA876D29ULL, 0x8103584A5BC56885ULL, 0xCFE59E233DE78EE1ULL, 
            0x142A6E694C51610BULL, 0x5D1334F798C50C05ULL, 0x1C4E4CB89B6EF0CFULL, 0xEE8EFDC4BB32D25AULL, 
            0x4993A4F6C3F46A66ULL, 0x30DB6644BD83102AULL, 0xB911ADE3A6867D7AULL, 0x1E8CC9E86642D8E7ULL, 
            0x0C0817CE466EF154ULL, 0xDE93777D87F60895ULL, 0x19A10B31E12AA6ABULL, 0xCAB235D3E6FEE3EDULL, 
            0x55E603A72F28AA05ULL, 0xD797F30B92ACA3B9ULL, 0xD4D435380A2258DBULL, 0xA8F777865D55A104ULL, 
            0x7D65F6AF2CC0084EULL, 0x0B21DD7B06283899ULL, 0xECD6A372133D0E7BULL, 0x48F7D1B3CC36C260ULL
        }
    },
    {
        {
            0xDEF81443990A4710ULL, 0x057CB6BC9CCC067CULL, 0xD9319D9E5423CAEAULL, 0x5212DF6EACA3ABB7ULL, 
            0x6D03F3AA43FBD1AAULL, 0xDFC660B1818E465EULL, 0xAA8E8F72492029F9ULL, 0xC845AE0E690ACBCEULL, 
            0x141FF6065E5EB595ULL, 0xB89A69ECF0FED7EDULL, 0x6272CD74B211C27AULL, 0x861CB40E215A2116ULL, 
            0xF394D9D18A1581A4ULL, 0xE178A424BA7449D0ULL, 0xCE047E4A29607DE8ULL, 0x77DAC6FBA2BE01DFULL, 
            0xC7E2F2DC7F26F600ULL, 0x319A4927544FEB82ULL, 0xC5547C1FB4C700B2ULL, 0xED6A025E3BD0D089ULL, 
            0xAD304DB3A423A7E6ULL, 0xE5F06590A91E906AULL, 0x9E9D2511FA760A45ULL, 0x364D1BD84D92D450ULL, 
            0xF7038334A68C12D0ULL, 0x857DD3A4B7C84B9FULL, 0xECCB197BF0F14633ULL, 0x776C7C17D25080F2ULL, 
            0x0B6D49C15CAE709FULL, 0x7A9440EECF118881ULL, 0x4DA6B3B2A2B16468ULL, 0x0897F5A4A189C730ULL
        },
        {
            0xDD63D3EAF28BC931ULL, 0x006E1ED576918D87ULL, 0x38A82E188C3D5775ULL, 0x280CD9BAB4B762B8ULL, 
            0x8A27A9D2B35F7D10ULL, 0xFD45339BDFEAC4A8ULL, 0x608CAF7A346FE786ULL, 0xCC24DD2FC21B0019ULL, 
            0x7A92C3337EFCAE3AULL, 0xDF42217330279C54ULL, 0x3CCBD6858C25B6FAULL, 0x07703BD8CC617DE1ULL, 
            0xEEB568594792B819ULL, 0x4BC468D898C56E04ULL, 0x7F186D1257ACAA2AULL, 0x2A0237C2A3B0C7C3ULL, 
            0x2082C6EA2BF27304ULL, 0x20640E65938AB999ULL, 0x5398707D9EC77DD3ULL, 0xF5FC64EB9D2CFE8AULL, 
            0x733A588F35B751C0ULL, 0x149BA21734ACE2ECULL, 0x059AF114622A1EBBULL, 0x02D45312EF1DC334ULL, 
            0x0E048E5A5D86543FULL, 0xE2C99B02249C3FB9ULL, 0x84910712B4E97812ULL, 0xFF0E7B892C757B13ULL, 
            0xAB10C7A6E58F57FEULL, 0xF707098467045118ULL, 0xB44A5433EF8DB696ULL, 0x0B6428DB79F496AEULL
        },
        {
            0x17900F0A6595CBBCULL, 0x85105BA42C858C1DULL, 0x52647C75D3262C9EULL, 0x27B8DE268D92624FULL, 
            0xCC8BD49D70A627A1ULL, 0xBAB7CE3A9E11A322ULL, 0x2C3201BFB5C0EF60ULL, 0xB7B1E48261241BC1ULL, 
            0x7726B82DC32F95F0ULL, 0x55529DBD4F3C2B58ULL, 0xCD2FE5C0EEA36C61ULL, 0x72CA752FF5A0A891ULL, 
            0x80BEDB3BA1C8F193ULL, 0x7FAEE3D08D0771C7ULL, 0xACF550370EA5A65CULL, 0x0E83ECFF6AB171C6ULL, 
            0x145BEDA7331F3AE9ULL, 0xB63587F05EAD3C24ULL, 0xBF4B52F22866B323ULL, 0x210311EA4BD7E6A8ULL, 
            0xAB1EFEA6899F6B67ULL, 0x2E966F084DF09A21ULL, 0xF41F9F55AA0CE002ULL, 0x73B6D2FA66F2358CULL, 
            0xAE48B3802C9753AEULL, 0x754E3DEC763BD0E9ULL, 0xA3826ACC3B9686D0ULL, 0x1E258E2641FCAF26ULL, 
            0xB4C67F53E9B30279ULL, 0x0DF0448A211A93B2ULL, 0x62454AE91137CAE2ULL, 0x68B78EB9400140E9ULL
        },
        {
            0xD1B4BC2005DF9F14ULL, 0xE84A9C37D5FA6D1CULL, 0xC572B7B095D03E99ULL, 0xC77BCA54E11A9EDFULL, 
            0x1FA39384F1AAAEFEULL, 0x28D1B2FAC5AAB16BULL, 0xF5AF11BFADA7DA6DULL, 0x38212BE1A1031EF9ULL, 
            0x8EA7F8CA9F356A64ULL, 0x8352AE4A2D943961ULL, 0xB97BC979F601F1E5ULL, 0xC4F5CE4E860BAF7AULL, 
            0x68EFFB4C47166617ULL, 0x52757792DBE129A6ULL, 0xDE3E8E49F61E4B91ULL, 0xBE6177CAACF30584ULL, 
            0x793CA3C7430CD38EULL, 0xB998BBD43752A5B6ULL, 0xA19CD3DF48378622ULL, 0x86B432E3D67330AEULL, 
            0x0BE673FB4E9C8ECFULL, 0x2B57640A46344376ULL, 0xC6E9B7F1F1634D86ULL, 0x863BD2574D40217EULL, 
            0x12893E82D5255A01ULL, 0xA0B1A832B322DE7DULL, 0xFDCE610F4EDDB79EULL, 0x6B39D1B0E26C1958ULL, 
            0x988B41963684E9A5ULL, 0xFEAE40A7D77C5E60ULL, 0x9279F143ECF49E96ULL, 0x739E430DCBF12AE1ULL
        },
        {
            0x3C460550CA24C120ULL, 0x7AC32D34C6C5776CULL, 0x554F06F88D9508FBULL, 0x2D740883FE01FAFFULL, 
            0xC8DD75B944F5412FULL, 0xAB0759F81FE9094EULL, 0xE6110CC3931B71F3ULL, 0xBEEFBF4166549205ULL, 
            0x2C586CCE619D42DFULL, 0x49A944C778BC8885ULL, 0xE319433685E612B3ULL, 0x02A4D23572045445ULL, 
            0x90B473A96E441DD2ULL, 0x21C19EBB4CF2ADF8ULL, 0xF3B70F52058602E9ULL, 0xB5A325676FB277F7ULL, 
            0x131CD7C30DD8B56CULL, 0x942D5EE7832532E5ULL, 0x9674459793D5C638ULL, 0xE72848BF148E5F4EULL, 
            0xA76F1B9584580E4FULL, 0xEB663BEC4CDFA4DEULL, 0xCA5A84E325D1FE65ULL, 0x6321C032464BF3DBULL, 
            0x057EEA26CCE0028DULL, 0x1DDAD686D5662745ULL, 0x8C2C802E7FC1E62AULL, 0xF694C8AA15C2E6C7ULL, 
            0x42762DE96D84A056ULL, 0xD82ADE78EEF835C0ULL, 0x828CBFC1A8D1A9A3ULL, 0xA33F2C1D5169B036ULL
        },
        {
            0x4D47DFB6EA382966ULL, 0x38AA44DBFAF89A22ULL, 0x239400215F022FB6ULL, 0xB85DB640275CE909ULL, 
            0xC02CCC039FDE4000ULL, 0xAFC9E092EAF5F6DEULL, 0x7AE1FDC688A576CAULL, 0x7B2BD7EA308A8805ULL, 
            0x380B22F9A74838F2ULL, 0xAA235F72ABF1C959ULL, 0x63B1A51482B614C2ULL, 0xB84BCE59ADD6D022ULL, 
            0x2C9CB5FE041DCB33ULL, 0x384C0463F2D430CBULL, 0x83F1A891905524E4ULL, 0x6A7A1E2A2B18BC3FULL, 
            0x2CA8E04498873519ULL, 0x3BD56AFF15D7B957ULL, 0x457321C526687897ULL, 0x98D69433EDC80872ULL, 
            0x8DDE98B2A673A17EULL, 0x30825C2481DFD0D3ULL, 0xE1817D835CB1B3E1ULL, 0x8F773B049B2AB58BULL, 
            0xA88A16A1D1E4EA11ULL, 0xBA86999F29555438ULL, 0xFEE1025AD936A96CULL, 0x2DADD6E44BE85EB6ULL, 
            0x3BD2D3697326EF78ULL, 0xAB65F38CFC0C2ABBULL, 0x3200041281FF7F63ULL, 0x9F393792C6036176ULL
        }
    },
    {
        {
            0x03C768242B15B002ULL, 0x2455FC62E675F57BULL, 0xA2C2793B7453C40BULL, 0x17CCC11A60B24703ULL, 
            0x6CFC8A4445E43AA9ULL, 0x91ED45FB6A9A8AA6ULL, 0x776FBCF0B4DE214AULL, 0x1EFB1EF14A868959ULL, 
            0xE1089DEBBE980103ULL, 0x1CB56DE6B1FCB522ULL, 0xB12599D17BE5EA3EULL, 0xB59CE3C31823A27FULL, 
            0x0A520FA1110F9BE3ULL, 0xAFAFD1CE1CCBACD2ULL, 0xD2D52B42BCACFAC1ULL, 0x579642D5825E85BAULL, 
            0xE93738F82279D832ULL, 0x9FF87399CD28A4E8ULL, 0x0D994833606575AEULL, 0x1D8E8D6A17604EC8ULL, 
            0xAD655C617901A551ULL, 0x0CDDBD35E0576D8AULL, 0x1F0F06BB63698729ULL, 0x37C6D0B680D19C98ULL, 
            0xEE10EBEBCCA2D5D6ULL, 0x802E71E94CC3C8CCULL, 0x14BE07BF0F066344ULL, 0x8F9BAD68BDBBA9F9ULL, 
            0x4BC0AAC1353D4EB0ULL, 0x9CDCED54A41CC67EULL, 0xC4A5DA20F399C56DULL, 0x1DA0ED950E30C48CULL
        },
        {
            0xBBE0AC583D60753DULL, 0x615A84D1CE6BF8ABULL, 0x56250AF701F6A773ULL, 0x010C8A8275897DA2ULL, 
            0xB0C93F73F005E273ULL, 0xAF842DE95CAF49E8ULL, 0x3DBF5CB0BF8574A8ULL, 0x14F4F50922A6D06EULL, 
            0x8E77CB95A9AB9D61ULL, 0x0A646A2B12F51C52ULL, 0x35AAA5855006AF77ULL, 0x63B76737B6802DB5ULL, 
            0xDF76024384D54102ULL, 0xC03F6D0F72D649BAULL, 0xAFE9A882F6098F82ULL, 0x5BF726033C118A78ULL, 
            0xBDBA3A5FDB862490ULL, 0xDFC54957C65599FCULL, 0xCBFE7B3B78C290AFULL, 0x028D69F8183B3630ULL, 
            0x8F1217B08E29FBE3ULL, 0x8FB2921D360965D1ULL, 0xDEC42F30165FFF07ULL, 0xCA86B37B796B117AULL, 
            0x3743E55C75F8CCE4ULL, 0xD967B6F81C5FD71BULL, 0xD97D06502801229AULL, 0xE014772E81420ACAULL, 
            0x945A58FC0787D7CAULL, 0xC3D4C7E4E5D6289DULL, 0x6DC93E49B7D2E4B3ULL, 0x7436E9C679AA718EULL
        },
        {
            0x7AB1E9AA07A1E63BULL, 0x6FB83802A830B26CULL, 0x4AC40C9E837546D7ULL, 0xC9C1AB01EDED0D27ULL, 
            0xAD5AC06B3432F362ULL, 0x19819C62B429F075ULL, 0xE18CBF09053CA73FULL, 0x956A2F977E8FF233ULL, 
            0x9EB73F7F88941A43ULL, 0x9EED380630FAF3F0ULL, 0x993088710AF78F2BULL, 0xA47AE7B1386AF721ULL, 
            0xFD1B8186844527F7ULL, 0x6AB8D5F4CE763C04ULL, 0x2F7AC9DAF989471FULL, 0xA46AEE120D1C1B77ULL, 
            0x0EC99BA9CB02DD45ULL, 0x8AB85B4F18F2CA99ULL, 0x573C0DCA776246C3ULL, 0x1D7888C0D55EA959ULL, 
            0x3029B73847D2C07EULL, 0x2DD1EACC7C1E66DDULL, 0xC8564778BDF9BD0DULL, 0x9A3243B4A2A55250ULL, 
            0x3356B5501F7E2B31ULL, 0x5FA70F5E3392340CULL, 0xF422A75AE01CBCE5ULL, 0x1AE153204C678647ULL, 
            0xAF2F5DF1764D5152ULL, 0x1DB35DAEBE651032ULL, 0x00DACCA9AEB4AC3EULL, 0x5590E8D32A7B595BULL
        },
        {
            0x6C844269B4ADA1C3ULL, 0xA4A89FC1F0D616BAULL, 0xEEE75C4B7D8EF66AULL, 0x185B4954921EF249ULL, 
            0xCF9AC04948889F2DULL, 0xE24A08E6254CBA17ULL, 0xB498DFE88C13F87DULL, 0xC8F7AC74ECAD55ECULL, 
            0xD5465DEBBB6A89DAULL, 0xB87888B7FCB9176EULL, 0xC4DAF292AC2907C3ULL, 0x408F0B02C8D7FCE8ULL, 
            0xADD2D2D48FCD260EULL, 0x612DEFFE7051911BULL, 0xEFD9C000B949C65CULL, 0x2DBA6B01212C765EULL, 
            0xAB2B55823B2CCA4EULL, 0x2B0216F3CC2491B8ULL, 0xA00049F9D7987ACDULL, 0x7B059D7A270DE67FULL, 
            0x0243D9683E392A8BULL, 0xF76F0728A5E013D5ULL, 0x949A982B27D48002ULL, 0x0AE2DFEDD539C092ULL, 
            0x030183FD9356A145ULL, 0xE65F302530CC7DF4ULL, 0x91B04AF8B1F2B73BULL, 0xD9BF9DAAD564519AULL, 
            0x95951E19CBABF33AULL, 0x45E6FA9941C794CDULL, 0x975342E415543447ULL, 0xBAC16327D3E75D10ULL
        },
        {
            0x3AED5EDB9B4F9517ULL, 0x864A64336310AA92ULL, 0x1012F607F0F72101ULL, 0x766AA9DC23788B18ULL, 
            0xBE2E4C37E3504C7BULL, 0x4AAB387358BFB309ULL, 0x680E86628C5E1329ULL, 0xE6DFBFBB4FBE7A0AULL, 
            0x06C1C718DFA4B6AFULL, 0x3F6498A6FE7AEA1BULL, 0xDBC315A3A5E3E784ULL, 0x8842F72818B8015EULL, 
            0x03C01CB5A6B995BEULL, 0x0288A984FE09D5BEULL, 0x211B0CF1BB5FF6BCULL, 0x3C185657B61A9B3AULL, 
            0x48B0A7BD8B371557ULL, 0x1F42C95817B54081ULL, 0x96F7CBC497589118ULL, 0x07CDAF17D4D7ECACULL, 
            0xE894BE8821DF63E6ULL, 0x1D98AD089C7BBDA4ULL, 0xAF29FDE8679F945CULL, 0x72ABE4A07B004B60ULL, 
            0xEA3F398FC570B16EULL, 0x906993B84ADC4B33ULL, 0x045CC00D33B9B0D8ULL, 0x58995623A05D213AULL, 
            0x7B71FBCBD4BB7D48ULL, 0x4B2C12D233441A2FULL, 0x6454D375E4F12207ULL, 0x4E9C7CE1E1436B0AULL
        },
        {
            0xE8526B45671606F0ULL, 0x06F50AA9C1538E25ULL, 0xE9A79DACBD6BD5C9ULL, 0x0B1B43E53C86BC97ULL, 
            0x9055121CC3E4920DULL, 0x6CB802EDF2CC3677ULL, 0x28F00E05393C9FD0ULL, 0x7D23AB19A8AD2FD6ULL, 
            0x6F8549F646199E29ULL, 0xCF31CD21A07036C8ULL, 0xDF71FEA5D6E42280ULL, 0x086C4A9BA8F3938AULL, 
            0x05B8E0170D5A3905ULL, 0xC6966DCE5C0468A4ULL, 0xDD05603382C505C5ULL, 0x7485960A6D2A02ACULL, 
            0xB70B57D5050AD3F0ULL, 0xF5757EF5B73A2591ULL, 0x41F3542BC12B6380ULL, 0x7BF9214BF6E25CD6ULL, 
            0xDA11C87702AAD090ULL, 0x5D268E078F9CF1A9ULL, 0x8B545A4D05FE54FEULL, 0xCC3D52F360FBDA9EULL, 
            0x2E0D70F800F5CA08ULL, 0x173D73A94FE6AED2ULL, 0x873D13A896D006EDULL, 0x3DC1C36DD6ED4270ULL, 
            0x88B60FDA02E0C87BULL, 0xAD732A45BAE936DEULL, 0x18074BC5A7D3355AULL, 0x81067A881EBFAE24ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseEConstants = {
    0xA08A154B1BD6DAA5ULL,
    0x4E1838E7BA99FC09ULL,
    0x8529BE9C375209FBULL,
    0xA08A154B1BD6DAA5ULL,
    0x4E1838E7BA99FC09ULL,
    0x8529BE9C375209FBULL,
    0x21548783C6EE5770ULL,
    0xCFD5EAAA3149C85EULL,
    0x6E,
    0x42,
    0x17,
    0xA9,
    0xCE,
    0x9C,
    0x54,
    0x96
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseFSalts = {
    {
        {
            0xC88BF2166CDABD72ULL, 0xB5DE4613130B30BAULL, 0x5A7EE246492801C7ULL, 0x759FCC8245995F7EULL, 
            0xE50F45F6C3F20115ULL, 0x91AD1C98BAA9FF69ULL, 0x5445C55A3578300AULL, 0xFAA4168E072126FEULL, 
            0x81DEC376BA9A2F4CULL, 0x12E1780C0741FDC9ULL, 0xDE644AFF7F848BCBULL, 0x9778391CA037C9EBULL, 
            0x834838B959A33B30ULL, 0xABAC9A6F98CD75F0ULL, 0xFE5144BD6C6EAABDULL, 0xDB6190843FFB8525ULL, 
            0xC2B6F44447C82AABULL, 0xAB4B2B70B79834B3ULL, 0x4964D75F40C41D71ULL, 0xD8D1FE674831BA41ULL, 
            0x70E9C7B45F4E9FE8ULL, 0x053D60DBBFD767E6ULL, 0x799CA43CC3E7E919ULL, 0x54C62FFDEC0619D7ULL, 
            0x8846E30718FE7786ULL, 0xFA02461217A8F484ULL, 0x3FF3A2DB285E06E1ULL, 0xCC95CC2C9C44C40BULL, 
            0x780CDE2E3D89F50CULL, 0x19CDE32848ABF02CULL, 0x485CE96C4271C3EEULL, 0x9DECE2004C3F4DE5ULL
        },
        {
            0x6A241F50AE7F630EULL, 0x850ED52B66B88F4FULL, 0xF7C49869D61D8187ULL, 0x101DE2F0ED07E485ULL, 
            0x46BF5F77416BA3ACULL, 0x650B65DF5D5AE529ULL, 0xB32F3F08E2C40BE4ULL, 0x4CBD23949AA223B8ULL, 
            0x0ABCA4C7ADEB0AB7ULL, 0xF044FFDA93399551ULL, 0x9026CC5BD9510092ULL, 0x2BD63794513A5656ULL, 
            0xC08458D4692AD50AULL, 0xFB0E4E5068B9B733ULL, 0xEDCCE90842BCA119ULL, 0xC89FAE95530135B0ULL, 
            0x5970BFB855384CA7ULL, 0x4CBE2817F0C70DEEULL, 0x5D80B9FC7BA046B8ULL, 0x3AFC31D9A532569DULL, 
            0x299807D821CB5716ULL, 0x07C83322ABCFC176ULL, 0x63472EAB8ED7268BULL, 0xA2B47802B286FD6CULL, 
            0x80845A423310528DULL, 0xE68EB1391DA928E3ULL, 0x24E2DD23ECB95965ULL, 0x4ACA88A996020286ULL, 
            0xA56833920D4A235FULL, 0x81B97D6FDCA9A8EFULL, 0xFEF6CC0FE47C417DULL, 0x13B55BDDC9EC0F5AULL
        },
        {
            0xB79CE8A6220688CEULL, 0x70FD05C325657070ULL, 0x963A0593C39A16EBULL, 0x900F23C6B26A44A6ULL, 
            0x02E4AF55541BD5E2ULL, 0x687ED6987BC5CA69ULL, 0x0816996232DE167BULL, 0x15B53CE9C86284F2ULL, 
            0xF0E760D64AE9AA68ULL, 0xA83F5DAEA0C7A183ULL, 0x44FCDAE8F7382753ULL, 0x40024B2889FEA277ULL, 
            0x824F1576ED5160AFULL, 0x66E556FF5EEE84D6ULL, 0x7F8F9954E7842C7EULL, 0xCD903DF7DCECA714ULL, 
            0xDFD1E97AB5C04D6AULL, 0x1425B343974BF27EULL, 0x7D2AAB8DE876355DULL, 0xE1B9F9CC6EF9D1CDULL, 
            0xF69FAFCD51BBEE42ULL, 0x9BDF7DA437A77BF3ULL, 0x5146741EB5A97993ULL, 0x15D598ED81E20E7AULL, 
            0x709446821BFD8C48ULL, 0x905EAEA8A849ABEAULL, 0xEA3AE8BBE972D7D9ULL, 0x8ABB0F984F495734ULL, 
            0xF21ECBA4EC2CA7CFULL, 0x25D03A75337F58EEULL, 0x20EFFD8A500E9B86ULL, 0xA472119EABB0FA74ULL
        },
        {
            0xC722A2E45ED32E15ULL, 0xB133F4C97764DAE0ULL, 0xD79FD74CF56FB3C6ULL, 0x374ED1DEF952B943ULL, 
            0x1452C4D78D39F2D3ULL, 0x912DD29051316A97ULL, 0xD661450DED2ACC66ULL, 0x3899FC816328BDF3ULL, 
            0x610AC5189FE65375ULL, 0x6CEA97F11A0104F2ULL, 0x774AD5C7C2007A6BULL, 0x15E419E33957A294ULL, 
            0x64A0D2951027DAD7ULL, 0xA60104379D822808ULL, 0x74393D3DC783A9D8ULL, 0x82E2F21EBF68CCE6ULL, 
            0xD1AEEB6629126722ULL, 0x11B81A46C94FBFD3ULL, 0x3D38DF0D8B5B6378ULL, 0xFE18C494EFB6B76BULL, 
            0xE830CACFD930B861ULL, 0x465AAD2D38F427EDULL, 0xD03E14EAB7D9413AULL, 0x2AE9649A25B41622ULL, 
            0x3E1E31BAC2D6DB5EULL, 0x14A0A2797C644DD2ULL, 0xE520433A7818D918ULL, 0x7C9D4D7B2EF9916FULL, 
            0x14CA521C44891E7BULL, 0x5381770491744F83ULL, 0xEE9890A98AD368DCULL, 0x9D06D75C676F6248ULL
        },
        {
            0x8CD02B309388B88EULL, 0xE41FEE07D360AE48ULL, 0x3A257B816C8F0F9FULL, 0x8436A795D710D93AULL, 
            0x67DC0606D9B93B48ULL, 0xF0594B078DEF2600ULL, 0xDF4A3E323CDAA7CAULL, 0xA9BC946F51D3F714ULL, 
            0x7CF04C0063A13912ULL, 0x9F455EDDC5CC141CULL, 0x2576AE41D5F76D90ULL, 0x3F1F7CA81A57BE60ULL, 
            0x5BF1F4C160845686ULL, 0xC0D4D6F348839139ULL, 0x34AFEE4739746235ULL, 0xD4C540FEC87F0A47ULL, 
            0x036206495C0F5E3DULL, 0x5087038D8A9CBBF0ULL, 0x915B60886DF6341EULL, 0x0736092AF7331DF3ULL, 
            0xAF8BCB3FF837B9A9ULL, 0xB4276CA6EAEE1F91ULL, 0x6EE963B2F2761D23ULL, 0xCC6C9E18FCC6AF78ULL, 
            0xA53168D05F1B74F1ULL, 0xFDFBAAC991236CDEULL, 0x92AC3E913DF8799AULL, 0xCC7AABC39F580F37ULL, 
            0xA5384F1F9CEAF35EULL, 0xE1F8E02DB3A268BFULL, 0x14A75B659BED0A6FULL, 0x29238EF2291E91E6ULL
        },
        {
            0x2654296324734B93ULL, 0xE9567B81F96706A7ULL, 0x17866A408E4F37E4ULL, 0x7EB20C4F027C10D1ULL, 
            0xD2FB7EEB3BD9D139ULL, 0x8EACEBC2C5323871ULL, 0x04AA94B17CCF7006ULL, 0xE3FBE7F4A249B22BULL, 
            0x57D2D61FFF793C87ULL, 0x2DE3CD4BC4E9AAE2ULL, 0xC3E3F44949723EBFULL, 0x216F879D383D7D99ULL, 
            0x3CE2C92DD8942AFCULL, 0x5F5E4A5C7F5A170BULL, 0x6BFAC39FDF069C70ULL, 0x424C386606C28B65ULL, 
            0x8657A7A732615B86ULL, 0x16D144D20FA6E659ULL, 0x579704A448F91813ULL, 0x712DCFB952E59A55ULL, 
            0x91548919CFF1D41BULL, 0xB67DB70C6C5F0645ULL, 0x7D21063E2F1F52A0ULL, 0xAF39BB4A9CA1155FULL, 
            0x6671D6D6588C3CB8ULL, 0x9A51EE2EF4719FFFULL, 0xBDCA58D85CE7B901ULL, 0x4DF4F23FB9B6C769ULL, 
            0x563145CC082D73B8ULL, 0x5FAD11AD8407D735ULL, 0x08A0DB9ADF6C4E92ULL, 0xF63A377C9839BC2CULL
        }
    },
    {
        {
            0xA8692947F3E93AE4ULL, 0xBE65C90CD2A150F6ULL, 0x5EAEFFA93DEA4881ULL, 0xC7997C433B466840ULL, 
            0xB384351ADAD2F8C3ULL, 0x8258E99472BDE787ULL, 0x83C710DA36083C1DULL, 0xE0B88E21271C4300ULL, 
            0x3453854CBBC967C3ULL, 0xDD59FFFDAC8A6C90ULL, 0xDA57CC936B4E9D64ULL, 0xE12F17747F031B42ULL, 
            0x89E773BDD438D9CBULL, 0x5AEECAE59D18714BULL, 0xE11250CB9356B7E9ULL, 0xD2AB65DD7B3CF52DULL, 
            0x3A09BE00A9DBA3DBULL, 0xE3E0EE6699FB71B3ULL, 0xA25618547423F945ULL, 0xC4B2B7D93DF10D19ULL, 
            0x113C0E8BBD1B98D0ULL, 0x75B8AB94E1485F88ULL, 0xB1FA674E0D43E8BEULL, 0xC23A3E708E9E1822ULL, 
            0xBCFFC6AB42BCCE44ULL, 0x0BA6B0130642A51CULL, 0xC1998892E8DE9B77ULL, 0x51D4D4247E243514ULL, 
            0x03575812B75985EDULL, 0x78EF61735628A95DULL, 0x3854468F25BF37F1ULL, 0xC5025EDC1ECD2A53ULL
        },
        {
            0xE4587CB8C78139B1ULL, 0x86F77A6C2B13BA20ULL, 0xA9850007F5D342B7ULL, 0x4589F02A7ABDC6A2ULL, 
            0xF41FD0B64858AD97ULL, 0x19862D42E041C1C2ULL, 0x98CEB4ACAA5F23FCULL, 0xBF7523F5979D922FULL, 
            0xAD41C21A1F3AD5DAULL, 0x1B2BABC66B47A8BEULL, 0x3A409CCDBE7D64A5ULL, 0xD4C0DC5A30267356ULL, 
            0xDA5F056B471F9DCDULL, 0xE6A733FC9B2D6ECAULL, 0x97213259A7142C57ULL, 0xC9A881BB1AB8E32AULL, 
            0xF6EC70869E24ACA8ULL, 0x33C9321877C6C333ULL, 0xF95B3BB9E0385ADDULL, 0x9A8DB815A46EEDB7ULL, 
            0x0F5CF94F3BD866C4ULL, 0x2E5F8135DB77169DULL, 0x038C7F0D93E45C8BULL, 0x403821F99CB38AB7ULL, 
            0x2F855C98E33ED642ULL, 0xBD852BCD6F99AC16ULL, 0xB9851795D23A3E08ULL, 0x36D12F8BF1C86E6FULL, 
            0xE972C40D482AC13CULL, 0xC38EB7E9154117B5ULL, 0x39FC0BC4AFBFAC86ULL, 0x33312B696A8937C5ULL
        },
        {
            0xA61379B53F8E83A8ULL, 0xEFD471D3292F0277ULL, 0x5BF096302DB49167ULL, 0xE0B90C4170A0342AULL, 
            0x51E1762B1C646812ULL, 0x27312D90BFAA1FE3ULL, 0xDD3E0B9B3B08D912ULL, 0xC30C0EE9E4B255E3ULL, 
            0x2D98090D6B19589CULL, 0x33E7D9AB7835D3A8ULL, 0x9C8734FDC0C5F00CULL, 0xA4A952505B67A33AULL, 
            0xBF0F8E9E2F3B3514ULL, 0xC1B6886D991046C8ULL, 0x1605B9257D8F4E8DULL, 0xCF4B27D118F82785ULL, 
            0xC3B33499513661F3ULL, 0x7C0D5DF96057F1BFULL, 0x13E0A0AA63DB8D91ULL, 0xB92084C449541673ULL, 
            0xBFE900777CF60A2BULL, 0x19E0BE45FCFD5323ULL, 0x07D214113ED873EEULL, 0x45F2EC2508D75CDFULL, 
            0xB56E840CA7C54722ULL, 0xEE49A38EC1A59613ULL, 0x9C68E6A58291F769ULL, 0xA4FEEE32216525A3ULL, 
            0x257232CE71C5CBADULL, 0x3B5696E0D2FCC46FULL, 0x4372B28186C3DCD3ULL, 0x10B856809D95A226ULL
        },
        {
            0x5D26EACF20E7BDD8ULL, 0xAF448C2E77CFA3C7ULL, 0x68D87907289F21DDULL, 0x2FCCC954830C51B5ULL, 
            0x7F17C572767476EEULL, 0x74EAF3AA74AB046AULL, 0xF3F2781FF3AB5E97ULL, 0xEFB3B962D720CB05ULL, 
            0x540225F82E81AACEULL, 0x92A7DB7060720B17ULL, 0x3707591F1AE7F278ULL, 0xF244C6DAAFFE7EAEULL, 
            0x5560E80CECF6E4B6ULL, 0x4D698C4E6FBFD118ULL, 0x0E68D1E4861E8ADBULL, 0x7060AA2CB5A0DA92ULL, 
            0x8F43D1D0C6D0BB8DULL, 0x0996A033DBD5C2E3ULL, 0x2FF6A564CFF28FD5ULL, 0x2CAF21F409BDB562ULL, 
            0x7984DCAEE4DBB2BAULL, 0x665FE4B7281F54F6ULL, 0xD56F2BD2BB470FFDULL, 0xE13117DEEB6354A1ULL, 
            0x31402E0DBA79E81AULL, 0xD741B4ED9694512BULL, 0xE36729BB04B7B959ULL, 0x4E3A7D7490F67E9FULL, 
            0x529EAF32AF089174ULL, 0x80566F6421C131D7ULL, 0xB65FAD93571E30E8ULL, 0xBF7AE57D117CFAECULL
        },
        {
            0x28D70750B1D6B192ULL, 0xE641738AFDE593F1ULL, 0xEAFE6639EE95C920ULL, 0xF778644C136881E3ULL, 
            0xB929456F9BF987EBULL, 0xC8ED51546CFC89A5ULL, 0xB03C5EB451FC9F9AULL, 0x917E8E96558771FCULL, 
            0xCF09E6A2E7A0DC80ULL, 0x549D8F9F20BE13BFULL, 0x41D6A5127CE264FCULL, 0x3F88B83D9D3EA988ULL, 
            0x0C86CBBE73732F5BULL, 0x4C1A1642CDF498BBULL, 0xC335E3E20A8D8F14ULL, 0xBEFEF9BA1A4414E6ULL, 
            0x6EC1657E57DB8D47ULL, 0x95C620F2EB7EDA06ULL, 0x8C94843596AFFB66ULL, 0x198BACE481E8F912ULL, 
            0x644748D0C92EBD5BULL, 0x513DAE84D2E929D2ULL, 0xEBB0F4CEF63B1273ULL, 0xC6470D33719A042AULL, 
            0x6C45BD8F2B5032A6ULL, 0x303DA01F8105C8CEULL, 0x9333DEF729DDE856ULL, 0x83E9CE9C3ACFFC27ULL, 
            0xAE431A7BECDE3BABULL, 0xD201BB11C258317DULL, 0x637F70BA8C12219EULL, 0xD54EE799BFA2CAD1ULL
        },
        {
            0x2CE7417967BE924EULL, 0x816DE35C2ACF7B2FULL, 0x999AE30A675FDDE1ULL, 0xE9F87543177DDC9FULL, 
            0x542929FA2B89DF7BULL, 0x1EDF54E321E58580ULL, 0x20327528F0DA486EULL, 0xD6C948CF8CC41BE0ULL, 
            0x69543F6B1F72FD8AULL, 0x89F815AD6E67E8E4ULL, 0x97DAF93F0CE048B1ULL, 0x489A105767B73263ULL, 
            0x7F98CBE08DB9FB31ULL, 0x7D7AE8B0C4790EDDULL, 0x7FFCCEB87F561788ULL, 0x9A9488D6078EE2F1ULL, 
            0xF03132A4D7701D64ULL, 0xBA7EFAC84585C74EULL, 0x392C5CEF2B544EF6ULL, 0x40031AA65D5885DBULL, 
            0xF5968A5C1DFA4238ULL, 0x8CBCC530B3D4A451ULL, 0x2240E86DF2ECCE44ULL, 0x21B12A5AE6643410ULL, 
            0xCDD05121A5FC1D9CULL, 0xE151D2DFE6BC3222ULL, 0xA2CD4202F8718BC2ULL, 0xE9BBD18EFE0611B6ULL, 
            0x078B7DE6EF63E794ULL, 0x008AFC96E7B34E4CULL, 0xDC07083D4E123FB3ULL, 0x1F52F4114EBD63DDULL
        }
    },
    {
        {
            0xD9F39E023BFA34A3ULL, 0xD7C6C42EA7FA7EABULL, 0x2F970AFDB13A1A6DULL, 0x25C1FF61CBBACC6BULL, 
            0xAF3B3442728F121DULL, 0xBC8613A1A01A3745ULL, 0x511EA77F7154459EULL, 0xC198692864CC8080ULL, 
            0x913CEF3AFA13B0AEULL, 0xB37D8F3AB3B1B06DULL, 0xACE9267794802492ULL, 0xD6EAADC775470A0EULL, 
            0x447B2EE638A24F11ULL, 0x938BA6632D4DF87CULL, 0xB340D8808AF5570BULL, 0xB10A8F3A6548482DULL, 
            0x8E36BC0289BD235CULL, 0x1A0FAF3F0710024BULL, 0x6265F95C0105F7DCULL, 0xBE0817F6CAD1E92DULL, 
            0x7B6AC7AAB1B359B2ULL, 0xAA71AB7558448CB1ULL, 0xA9720B6027E4778EULL, 0xB8B4935F0739EEB3ULL, 
            0x7207401445A9F9ECULL, 0xE13916E526ABD36CULL, 0xB607E432AE9295FAULL, 0xDBC5E97B385ABC5AULL, 
            0x8DAAEDE1B5741F2DULL, 0x01ACD221F59BF9BFULL, 0x297B9E649E420F48ULL, 0x6061EF2D3EFAABA0ULL
        },
        {
            0x1393C8600ECA6BC8ULL, 0x1FFDB5B3C5FCD899ULL, 0x12D8B4C16BA43CAAULL, 0xAED38A6B1366286CULL, 
            0x2D04C7DD34F8C57DULL, 0x26C5EA244F62F38DULL, 0x01A33A6CD1E9B59BULL, 0x0E27AAE16BA60C5EULL, 
            0x01CC4325940F46ACULL, 0x0B3B3A60C332B693ULL, 0x8D50D4259D663C1AULL, 0x6B128B000EFFD9E7ULL, 
            0x7EB5B521B2DCF6ECULL, 0xDD7201FE9C8D27F4ULL, 0x68D03898DCCA0C99ULL, 0x7034C526570E7342ULL, 
            0x8BD1231F0D292838ULL, 0xBD325CCCC67E5FB4ULL, 0x1F8DEE4C31889DE8ULL, 0xB5CF1AF89A7893AAULL, 
            0x634FD9659D4889F4ULL, 0xED71FFFACE45C2E9ULL, 0x2ED001BB45A73013ULL, 0xCCE212B5BD7F3238ULL, 
            0xF09B73CEA64A79B7ULL, 0xFDFDD8EC4A8FE484ULL, 0x993905018314DE36ULL, 0x5378E0A6DDB55A85ULL, 
            0xA88935D7228BCF92ULL, 0xBEFAF6774F6AAFF1ULL, 0xF62B03D3D82B5402ULL, 0x159CED07A98FDD4DULL
        },
        {
            0x7C95FC77DBB2B9E6ULL, 0xAEF8B1E61F65C14BULL, 0x88A07E96A7111D7CULL, 0x2E0DE9687233FCBFULL, 
            0x803B8634B5358B28ULL, 0x04E3E803E2ED96B2ULL, 0x78B17CC786DF5C0DULL, 0x355C25A255792CDCULL, 
            0x343384F6127395F8ULL, 0x2ECE89FE23396FD4ULL, 0xAB84C314ECD084F2ULL, 0xA83EAF0D971F6DCCULL, 
            0x689255A73159CD24ULL, 0xFBA6B38ACEB84414ULL, 0x2035C1D41C9174AFULL, 0x9BB8E167F0B9644AULL, 
            0xF0FAFD1C4198DB41ULL, 0xBFEE86832FD68C6BULL, 0x24A09235928BB59CULL, 0x4A9B0EEE356F2CE5ULL, 
            0x3FA003561AA28150ULL, 0xF66FD1685119C14AULL, 0xE7ACA186AE308FE2ULL, 0x3B5B799E3BBF938DULL, 
            0x7E8C5B9CAB5FA8C4ULL, 0x821A112834EE9FBFULL, 0xDE389AA24ADD754AULL, 0x3F3F1AAB15CB539DULL, 
            0xA8F6E6C45CD6CBDFULL, 0xB8E53C16A433C799ULL, 0x93BD1D7ED22AFDFDULL, 0xCCC4970B64A0563AULL
        },
        {
            0xF225259A8FFD9704ULL, 0xBE445620C019665EULL, 0xCBEA243B6E42CD2DULL, 0xADE9E254BEC7156FULL, 
            0x3C1C7BEAB52AC26FULL, 0xE2F84F99F0DF49BFULL, 0x632AD293BBAE7210ULL, 0x028BFE51281FB821ULL, 
            0x1087A72825F4402DULL, 0x546B8E1A0743EC71ULL, 0x0FF2BD95EECF4D7BULL, 0xD316EDBCB9E0C86AULL, 
            0x105864EDE151CA84ULL, 0xFB12AA2BCFABE0E3ULL, 0x6CAC6CFAB2BD008AULL, 0xF783A463622C4C11ULL, 
            0x9A5E86E620EBFAA7ULL, 0xC102300F5052EC63ULL, 0xF08B596E3B906B54ULL, 0xF46B2D3620BE64A6ULL, 
            0xF3810D0EC876D9C9ULL, 0xAD572A032A0FC3CDULL, 0x15944F702A984BA5ULL, 0x8F942830F63AFD18ULL, 
            0xE1D7CF70BB1EFAD6ULL, 0xBF94443FFC864AE0ULL, 0x49CD44314305B253ULL, 0x62608D13074D2829ULL, 
            0x78761C7E4AEFBA5DULL, 0xFECBE0CA20B999AAULL, 0x1C06B950A07A1D59ULL, 0x8DA954EDFF686B49ULL
        },
        {
            0x21AAA5022F58B927ULL, 0x2122544ED7E402D3ULL, 0x0C4404056F52F4FCULL, 0x4B81FEDC9B1EBAF4ULL, 
            0x109EEFDCCBA3C561ULL, 0x074D32A17F124181ULL, 0x98CA59942FE0E738ULL, 0x53558C85198564CBULL, 
            0xE6EB5DC27D1D3C8EULL, 0x1061D1C8DBDEBF37ULL, 0xEFC5259615A8EFB9ULL, 0x068CA0EC7A0E3DA6ULL, 
            0xD6B7E015049936E7ULL, 0x37FCCA1C8FE2B0ADULL, 0x1E8EFF25D25203B2ULL, 0x76E9A8F296A15D35ULL, 
            0xACDB733353095320ULL, 0x646B0F3819814FA1ULL, 0xDA34EE31A7170FE7ULL, 0x8070FD22D9219B58ULL, 
            0xF4A9ECE9402B4E7EULL, 0x552C7BF59AC7528FULL, 0xA008CFA0707FDC89ULL, 0x3FBEB51DFA4B3EE4ULL, 
            0x99AC3B51F62DFF3EULL, 0xF143460727ECDE6FULL, 0x8B0CD6FEC1833350ULL, 0xAD33D9D23832A48AULL, 
            0xAA9159DA5DFCFE69ULL, 0xD5FF9D0A6FEC8B32ULL, 0xA4FF8FCA19606BD6ULL, 0xB57AF6B9B9298519ULL
        },
        {
            0x129DA8692926863EULL, 0xF71C9B334719CDB2ULL, 0x28295E56D6A7CD4AULL, 0x9B3979CADA8C5EADULL, 
            0xE08CE73E7FA3A61AULL, 0xF482A325BC6C64A8ULL, 0x24BD740C2C0BC36AULL, 0x767B2336242E60B2ULL, 
            0xF006CF00564B2389ULL, 0x328F0210428BAD5BULL, 0x2559C081804B361AULL, 0xB645F3E1504E43B0ULL, 
            0x17B5D04DB66FB6C3ULL, 0x106372DBDB911ED2ULL, 0x8BA604A726D091FFULL, 0x3DB4D7493675B951ULL, 
            0x062789AC0D42984FULL, 0x6F9334312E07820BULL, 0x070A301CC26CC2BCULL, 0x7BA5B26DB76B9720ULL, 
            0x5A4838E3E5A4A848ULL, 0x7D39F2B10B70A060ULL, 0xD7D44A6E7F4BEEFFULL, 0xDCAEF4A6EB2EC9C9ULL, 
            0x1898967D75C851D2ULL, 0xB7C9D66B6B0DE230ULL, 0x438927BBEFAD2DF0ULL, 0xD904A7EAFCF639F7ULL, 
            0xFFDF75DD93843B51ULL, 0xD9BAF6EA7EAB2DC3ULL, 0xCD7E88333EF9209DULL, 0xF14AFD95DB8E4784ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseFConstants = {
    0x1CF6602A4479BCECULL,
    0xC393E31218CCC9A2ULL,
    0xBAE110A1DDAC251DULL,
    0x1CF6602A4479BCECULL,
    0xC393E31218CCC9A2ULL,
    0xBAE110A1DDAC251DULL,
    0x9917827454ADB17EULL,
    0x131F40BCED024BF9ULL,
    0x29,
    0x67,
    0xC5,
    0x63,
    0xC1,
    0x54,
    0xDB,
    0x55
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseGSalts = {
    {
        {
            0xDE4959A21547F8D2ULL, 0x8AA55F30E8AC8FF4ULL, 0xCD9CA14209805993ULL, 0x0BF6475591E4286EULL, 
            0xA4289C271D8C67B1ULL, 0x5F17D66447066512ULL, 0x29CBEA47A2251B80ULL, 0x5EBC17B9637AAC9CULL, 
            0x8B4451B4294073BFULL, 0xC1D5FF5314E298F0ULL, 0xBC7C2A1AE056C078ULL, 0xE326D38FF6BF0421ULL, 
            0xC636E3B7CA61E422ULL, 0xD37CFC2598BEBDEEULL, 0xDB0BB901DCD617A3ULL, 0x11201EC7CEB171CBULL, 
            0xC1363EFB92BE2FACULL, 0x9FB08D449F8EF627ULL, 0x5FB3CC45B1CDA423ULL, 0xAB1EF22C2813509FULL, 
            0x0C05DCD47A42388BULL, 0x3694D7CD375245F8ULL, 0x737A3FBD4C56823AULL, 0x1F9C201E58ED4B7BULL, 
            0x787D6D7AF0E98BF8ULL, 0x12E44F02E54481F5ULL, 0xA890BABFA679C155ULL, 0x91DE5C22162C008CULL, 
            0x25E2426E33222B4DULL, 0x55C9F7DB4658F2FFULL, 0x038A53A36D5B6B05ULL, 0xB6CE562C269F32F7ULL
        },
        {
            0xCA5C2DD3360A0055ULL, 0x67C13A41C99A885DULL, 0x63005971880AFCB0ULL, 0xFBFD2D731BCED2B0ULL, 
            0x5406C36107A4DAD6ULL, 0x29DBFE947DE5042FULL, 0xBC4ABA1406DABD7DULL, 0x5ECBA016E7AD97A0ULL, 
            0x66369B1172CCFEC0ULL, 0x9ECB6EE880E77127ULL, 0x5A8661A4C562780EULL, 0x24F39A7459A8DC16ULL, 
            0xE94E7281439A2C22ULL, 0xA8D9D9798120F8A2ULL, 0x7D779D02432B891EULL, 0x0525A159836F0378ULL, 
            0xF317049B47328AE8ULL, 0xE1FF7EA71BCD1F19ULL, 0xF64FCB51FFFB68AAULL, 0xDCD903B426AF6622ULL, 
            0xDA36AF9EF164689BULL, 0x5997DFE1F38CEDA9ULL, 0x4508EF59FFA2C93CULL, 0x94911E8B1D032003ULL, 
            0x753D28A0270D551BULL, 0xE9029C1BEEB426C6ULL, 0xC330128D5C895305ULL, 0x04CE2E955023FF12ULL, 
            0xDAC92F3C6FD35422ULL, 0xC57EF76BEEB4D0B1ULL, 0xFEF332BEEF891017ULL, 0x7895E55B69AEB955ULL
        },
        {
            0xEBE817ADE23F06B5ULL, 0xF00DC2A003A2B391ULL, 0xB6A69131D5ADF18FULL, 0xCB2445355252D018ULL, 
            0x5B1E1A353EDE878CULL, 0x82A883733401DE59ULL, 0x46E24AAB9705A514ULL, 0x48DDEAECB438AD16ULL, 
            0xAE9CD31EF4B31033ULL, 0x97BE99F8664C451FULL, 0x12CBDAC0D5812447ULL, 0x42E030478DC6CAB2ULL, 
            0x1FFD097245BD38CAULL, 0x3FB7B71029807EA3ULL, 0x8F87E1C6F5BF889AULL, 0x7F066CDD7AC6E7AEULL, 
            0xB24BB40DB50E5172ULL, 0xFBAB729DE5DB7AC5ULL, 0x74C6A51E73B65BAFULL, 0xE4437420E773F585ULL, 
            0x733A4F72337ADBC8ULL, 0x6DD3BD6359065883ULL, 0xF3AA5B20B6BDC2A4ULL, 0xA7EEEC95FFDBA01FULL, 
            0xCEC79B10F3C3B43BULL, 0x96C7CAAEB37192B7ULL, 0x745885FCB4DB2298ULL, 0x4A47A8D5343E07E1ULL, 
            0x1A19A2F760CFB046ULL, 0xB859424581FF59E5ULL, 0x935D47C46BC07057ULL, 0x223FFED9EFD282ECULL
        },
        {
            0x39DC06C5727A3AB9ULL, 0x93688F2CEFA616C1ULL, 0x07905DA38EE9C83FULL, 0x7EA2DACCBAA5AC69ULL, 
            0xABAAEBBCFC36735BULL, 0x0F91811FD9A444FDULL, 0x2F130B10075B5004ULL, 0x36CC1AA1A00F4493ULL, 
            0x7C2F7218B755244AULL, 0xABDAD0D986D0BD91ULL, 0x3F55A78FD97DBD8BULL, 0x779B832083EBE0A3ULL, 
            0x4551975ECAC9E4A6ULL, 0xBE3C2D5225A184DFULL, 0x1ABE2DCF3395FE68ULL, 0x80DC738EFE3B42FBULL, 
            0x588F471DB822A89AULL, 0x5DBC84FC45A2D1A6ULL, 0x5F59F03CC7C071FBULL, 0xCD2C49BA390EAD49ULL, 
            0x461364AD0CBB6CABULL, 0x7AEBA1300DE60955ULL, 0xC24163FDCA710E93ULL, 0x044EE1CCE3DB413FULL, 
            0xBEF875C944ACCC9FULL, 0xF6B7B0A9A94587A1ULL, 0x674AD7557C8920E1ULL, 0x1777188CA4C3DAF9ULL, 
            0x1EC14E12FBB43449ULL, 0x0E0A510913782199ULL, 0xAE0D3C34823EFABBULL, 0xF1B1651CE565D773ULL
        },
        {
            0x71D3E7D7DBD646FBULL, 0xE90DBD1DA9F686F0ULL, 0xA982AC61AB6D83A2ULL, 0x8B14DA470809778BULL, 
            0x95E0A33B90942BD3ULL, 0xAF2C9A615D9240F0ULL, 0x07B030135783740BULL, 0x656AB82381091D75ULL, 
            0x5E0357936E3F9ABDULL, 0x3D794F53F7F8739EULL, 0x7C73D673E7E284EDULL, 0x31EEE9827AD03915ULL, 
            0x0398ED59CBBB46A1ULL, 0x5FDD366888BC9457ULL, 0x8AEF6C2A02D3C360ULL, 0x1165A9D8423D9DC2ULL, 
            0x66CFEC218D91F32FULL, 0x78F97A249303CE60ULL, 0x828DF700B537D912ULL, 0xE21926D0089A88F2ULL, 
            0xCF8E4BC478872D61ULL, 0x81B8846774BCCD78ULL, 0xC58E1333C2B3C74DULL, 0x98FCE9C913296F59ULL, 
            0xA92FC69B0ED98637ULL, 0x6A05CF2BF55B5BE7ULL, 0x23EF883AB26AD6F1ULL, 0x78EF947A442B1590ULL, 
            0x97EB26BE40DBA6CEULL, 0x7730DFE8567FC7D0ULL, 0xB8D91FD73E7409CEULL, 0x570145D0DA7572ECULL
        },
        {
            0xF764170B157711AAULL, 0xFC0447BF1520BE48ULL, 0x396173402FBFBF4DULL, 0x6F0E60CE68E3B14CULL, 
            0xA9C1C21E928D8A98ULL, 0x3AE4FAB79ED8EB1BULL, 0xE7B0121036FCD260ULL, 0x6264FAFB58426120ULL, 
            0xF9A53ABAB2DDD6FBULL, 0x4C90044ECDF3767AULL, 0xDDC0936D63FA7D05ULL, 0xB13FD80ED4A7F07FULL, 
            0x6A4441835ABAF6FBULL, 0xA026EB8AAEF90F1CULL, 0x23EC804DD2F2845EULL, 0x6AE9887711AB2C70ULL, 
            0xF5E0BCCC7FCA5611ULL, 0xACB2E28A789C5DB6ULL, 0xE6767808DBEF4988ULL, 0x30F2A9CBC0AA4D1CULL, 
            0x58E5D370903BAB1DULL, 0x9C76D95849E3DA3EULL, 0x2ECF5F6AB00A2AEBULL, 0x6B02B595EBF916AFULL, 
            0xEF361117D204116BULL, 0x8622E2D0F1AEDB95ULL, 0x2D87570CA869E296ULL, 0xB67C5B4C3525AC1AULL, 
            0xFBF8D6E67FEEB9D4ULL, 0xFE8361AB50466241ULL, 0x35E7AE76300D4715ULL, 0x54C016A75CAD9C7BULL
        }
    },
    {
        {
            0x4B6B0C21D9012AD3ULL, 0xCE57590A8766BA7DULL, 0x61BFAA92D5D50BA3ULL, 0xB3E51DCE145B4416ULL, 
            0xC3E8925EF19EF4E9ULL, 0x97FE67C853141086ULL, 0x3680B058CACECA90ULL, 0x3E9C9B60D73C8593ULL, 
            0xB668AA0C578E3450ULL, 0x5009ADF824AF9761ULL, 0xD00E9C38B66B3000ULL, 0x8B75A683E3208321ULL, 
            0x12AF6824B7304997ULL, 0x46CA230C72185E61ULL, 0x2BFBC88632400EDCULL, 0x5E43FF7D06B86978ULL, 
            0xA8ECF56D0F32A52BULL, 0xC93E022C5ED200C8ULL, 0x34E9DBBCAADEF9C8ULL, 0xDF887ABFE51252CDULL, 
            0x172EC80F60BE1B3EULL, 0x8AA1275549F57097ULL, 0x889B62B90B6CC9B5ULL, 0x3239CB1D341D4343ULL, 
            0x69E41532FACBAF6CULL, 0x2338048A198BD772ULL, 0x0807A7BB63333488ULL, 0x65CF3B48022B34EAULL, 
            0x6191BF04BEA14993ULL, 0xEE97040081F1F713ULL, 0xB6CB1922C5D32484ULL, 0xC59C5A0529D65DCAULL
        },
        {
            0x27A91910050238EBULL, 0x8433E1F4265FC583ULL, 0x641D0C64B55C3730ULL, 0xA7922C7DBBA68756ULL, 
            0x576CB9775EA526D6ULL, 0xF83F1678C2468F49ULL, 0xD3C57965EE2960CFULL, 0x0C41C7BE1529AD95ULL, 
            0x233646A081C7A114ULL, 0xD746865BBC244E07ULL, 0x8276ABB25C2C5C3AULL, 0x29016C906639098FULL, 
            0xF71A349DA5E998B5ULL, 0xE70905556D029854ULL, 0x1BC5670E01EAE0ABULL, 0x9F03C27DDE35B2B7ULL, 
            0xC8F2E3EEA0BE12B3ULL, 0xA1D289427056D77DULL, 0x48CED1ED2D942420ULL, 0x008371C1CB7CEAFCULL, 
            0xE644F477B53CA56BULL, 0x362EA0CC084DE6DDULL, 0x907B963867FC4303ULL, 0xAC6B044AA78B59C9ULL, 
            0x153CB3C57877B6EFULL, 0xE1E269344113C3C7ULL, 0x6538D486770C2FD2ULL, 0xF6CDBBD37D7BBBD1ULL, 
            0xFAEB0573A3F692F5ULL, 0xA6B6B7C4D3497D94ULL, 0x31175259706F1B48ULL, 0xA78BC347B8E29B39ULL
        },
        {
            0xB82F38F0C1984D43ULL, 0x5DA717F223E8F611ULL, 0xE35765C0834730CDULL, 0x98A8D090C9C880D7ULL, 
            0x6CD3CEBC31857FC9ULL, 0x42239AC53A18E8DBULL, 0x1A8F0DA58CD9F86CULL, 0xBA1BE6319FAE0390ULL, 
            0xE730764AF89879BCULL, 0x22C5D3D761C14908ULL, 0x79410C67905F7000ULL, 0xB0675D6E2FB5292CULL, 
            0x5776C5A1E0D446ACULL, 0x96036D86735CA08CULL, 0x52C37755888C0CE7ULL, 0x524586D31F3FFBA0ULL, 
            0x78A61E6BCFBBD193ULL, 0x2D806887220C6314ULL, 0xB3D3BDA66F68AA2BULL, 0xEA558D9BE6CB958FULL, 
            0x2D80CA5AA5054918ULL, 0x0EC5C90B34FA1A74ULL, 0x497015AFB5B5CFAAULL, 0xD81ED05401F15B3DULL, 
            0x09921993866D57FBULL, 0x7804B76BFEAF7CF6ULL, 0x9CE60F799676D3AAULL, 0xD190128648A301ECULL, 
            0xFB0E4B5D151BB202ULL, 0x8F11AEE2A8846166ULL, 0x508BEB8DE703688BULL, 0x0AFF1D3DA00E8217ULL
        },
        {
            0x69C5149D86F4607DULL, 0x7DFB509951BD19C9ULL, 0x68D66C8DFF4CF073ULL, 0x1F8510190C5D6E8DULL, 
            0xDE92717D2440131CULL, 0x4BDCFC848A7C1926ULL, 0x56A1BCF7661272C0ULL, 0xF42F1222ECC0821DULL, 
            0x2A440CC26A8E1A2AULL, 0x415301836F83DDAAULL, 0x09DB891FE2FCB298ULL, 0xEBC8284136D0B78DULL, 
            0x2D7867F341098A7DULL, 0x6ED4976A203B61A1ULL, 0x555B28219A0671B0ULL, 0xE8ECF62082AAF61AULL, 
            0xC49C608BAB1563DEULL, 0x42DCD0A64DA0854CULL, 0x88EB33CF88350BE3ULL, 0xF8E3860F5D7C843CULL, 
            0x1B87925B1CB7D6BBULL, 0xF3267BBAB45347C1ULL, 0x45030AD867495DF9ULL, 0x52AE6091AF8CE132ULL, 
            0xF0A3D2B029DD665FULL, 0x58CAFDA612D305BDULL, 0xEEC271DAE8F359FAULL, 0xF47E473692FFA8FBULL, 
            0x1E130E9721B4FA1AULL, 0x3F22211A700EF30DULL, 0x37FF42AC1C2F542EULL, 0x970B10AB791F2EE0ULL
        },
        {
            0x4064E225F4D89D26ULL, 0x712247462C2E5A64ULL, 0x32CE594801F01A7CULL, 0x79B22500DBC28B72ULL, 
            0x7B63C81C84FFDBF1ULL, 0x2D466D9262B0875DULL, 0xCF7FB3A357BC8553ULL, 0x1C912331834DC8A8ULL, 
            0xFEEA760D2CCFB96EULL, 0x1C8820E9CD957D2FULL, 0x848FB33BED36501EULL, 0x86445158B18D8FAFULL, 
            0x8F9D05F83D84665FULL, 0xE2407126167935E7ULL, 0x0B6EC65C13B40F45ULL, 0xB8876721BC0242DCULL, 
            0x97A294086095B996ULL, 0x0CA737DB36A6173CULL, 0x4C65A37B3989020BULL, 0x01D9F75FEF5AA015ULL, 
            0xA12B23535A04CFE1ULL, 0x0A0C4775B53366E4ULL, 0x80B317D8567A23C0ULL, 0x958E418F845B17BBULL, 
            0xABB2CEBCE31324FCULL, 0x4F21FC5A21221B27ULL, 0x22E42397BD505D8FULL, 0x32A8CABBC4DE5C4FULL, 
            0x44EB1C2DD4B0EBDEULL, 0x237235517EB73C9DULL, 0x58993CF5461534EAULL, 0x57227DED196C1C22ULL
        },
        {
            0x9D1CB93159FE8279ULL, 0x0022EFF32B130167ULL, 0x3AB59751AAA8DB79ULL, 0x57FE71826E4BA837ULL, 
            0x52AE03A781BFB833ULL, 0x4E83CDCE6AE61C4FULL, 0x35B4A95A3A2ED4B0ULL, 0xE117D7D1FCCE491CULL, 
            0x55F3C2B9FE6F886FULL, 0x0E79A894FD3B4DE5ULL, 0xE45C6C92DF5891B4ULL, 0xEF75AD7A27160A0AULL, 
            0x0149194EE6905150ULL, 0xC54B53BBB63254B2ULL, 0xD8F39D9A5D525159ULL, 0x8EAC0830B03A6ECEULL, 
            0xD395EFFF5B171F0EULL, 0x43243134C659D09CULL, 0xBE9DA3C6AC8D36E1ULL, 0x1D7107463624BE7AULL, 
            0x3B6D41B69004F4EFULL, 0xD83C5B08D5EA691EULL, 0xFB7265AF21A8C6DAULL, 0xEDC540D3A2A16B66ULL, 
            0x7D6B8178EA5E5F92ULL, 0xBC1B1CBD7DB5AE94ULL, 0xA4C251E81F60AC77ULL, 0xC2E5898E33BAE3B9ULL, 
            0xB484A837EE516943ULL, 0xA6310BD59089A95AULL, 0x0D4B0FAC9644ABA5ULL, 0x87B3BEDF3066CDC5ULL
        }
    },
    {
        {
            0x3688A404757AC050ULL, 0x3A949B9E4AC73D79ULL, 0x828A39DBFBEE9D90ULL, 0xBC4517BEC189DED8ULL, 
            0xE050A0D7902F8F60ULL, 0x2789E5EB608EE4B7ULL, 0xF0DAE250B9147A13ULL, 0x239A14636A41AE18ULL, 
            0x7995548AF41F4630ULL, 0x0539E63BBE5C6E9BULL, 0xF09BB41E2346F20BULL, 0x5FF5AC3BE373C066ULL, 
            0x5BB7280036FDE582ULL, 0x5A67F8100E8B2334ULL, 0x30650921DF94F53AULL, 0xE6DC5A04F924B7A1ULL, 
            0x8412E6DA5E9CE1E8ULL, 0xEDE15546A42039A9ULL, 0xC32ECF19B1E98564ULL, 0xB9D38EB2673708A6ULL, 
            0x2061D2CF8DE76804ULL, 0x8CE541A60147B64DULL, 0xF814E9524366B397ULL, 0xFC5884C041D8DD3FULL, 
            0x0F5F9EB7E91092B7ULL, 0x543B8E96EF57BC1AULL, 0xD272AB84921955CEULL, 0xB608C1B38A1E6A8AULL, 
            0xA75FFF4FD6544D51ULL, 0x1DE59C27AC9096C4ULL, 0xF84CF0E42450A635ULL, 0x040758A47D09BE49ULL
        },
        {
            0x9FE99C4A2848D3ECULL, 0x032FE6CFDC20AFDBULL, 0xAEEEDE126706F524ULL, 0xFBD1D85CA77ED32DULL, 
            0x972623B74AA0A781ULL, 0xFFEC2064FA55AC27ULL, 0x5192A6915978C44DULL, 0xC9BF42374C84DBC2ULL, 
            0x88C2C44DF9E5CECEULL, 0xEB587F752DC30759ULL, 0x7C8594BF0FCC0BD9ULL, 0x37DAB30DF6F0E9B0ULL, 
            0x2E2CE4F425AAD0E6ULL, 0x9507BD60683C49D1ULL, 0xC94B87D91998EA5BULL, 0xFAD8922A0D8B6DE1ULL, 
            0xDC71F718B48BAC4EULL, 0xCBEE2B1DDDC5F62AULL, 0x97FBBCFA73664312ULL, 0xB484FC9B3A120525ULL, 
            0x0E82CE850BC3F63CULL, 0x99697DA9B2B35692ULL, 0x8664D2B44BA2202BULL, 0x8D7C7C347433C2B1ULL, 
            0x8E1E5ECE1ABF0AE0ULL, 0x2D4072CCD88D9162ULL, 0x1B4DF431DDD9E1E5ULL, 0x607FE7035EF06858ULL, 
            0x94973E67D3C94101ULL, 0x603BFFA62F3DBAD4ULL, 0xB2B8071B3FE23801ULL, 0x83CAE3543A75D7E3ULL
        },
        {
            0x30211479C073B805ULL, 0x13D46284414092A6ULL, 0x7486DE80CEE8DFF9ULL, 0x3AA034C8CB9C2FE9ULL, 
            0xA6E2F74ECD2FA466ULL, 0xF5AA26CFE1C981C8ULL, 0xD64BB81D46395EB5ULL, 0xA6599F5EC14D9326ULL, 
            0x0C3A171636D7B156ULL, 0x11076C8ECD65801FULL, 0x52B0D932E93FAB4CULL, 0x4403DF5B996B680CULL, 
            0x16117CAF0C07C04BULL, 0xDC943DCB7E670BE8ULL, 0x4128A602026D49ACULL, 0xA3D79FA42715085CULL, 
            0x9BEEB115DDE0E692ULL, 0x34D4AEA62C5DC27BULL, 0xAA633FCCA265233CULL, 0xB0A3DE04976DABA4ULL, 
            0xD5C39D209E7302E6ULL, 0x77395519CD7066A6ULL, 0xBDD8FAE199A8B0CAULL, 0xB6082DC6E73792FDULL, 
            0x74B875BF3DE6D004ULL, 0xB1027A509D6F26B1ULL, 0xA1FD81AEBA8EAA4CULL, 0xBD432412699069A9ULL, 
            0x013ADD936CE6FFA7ULL, 0x9FB8A298322127A5ULL, 0x0B1217CC3B4AA795ULL, 0x16A93BD95B2798B8ULL
        },
        {
            0xE71BAAC21E8FC854ULL, 0x6847D8A16248604CULL, 0x5EA9B0E3532FC416ULL, 0x8C35B09A83FC5034ULL, 
            0x97A503675389174FULL, 0x912B9EC79313221BULL, 0xA57F754A97D4F13FULL, 0x9CDD6838F5048115ULL, 
            0x18A226F3BE855F86ULL, 0x110F89572AB36C33ULL, 0x6DD3CFAA9766D21DULL, 0x044B6EEDD892A0A3ULL, 
            0xEE0B2C0A357B9C80ULL, 0xDD8BA8BE0B7608BEULL, 0x75FBDA0491E4313BULL, 0xDC5283A83AB89521ULL, 
            0x3BA218233EE4E7BDULL, 0x34220D3A871BD581ULL, 0x52A490ED136DC4AAULL, 0x937703BCC02CE558ULL, 
            0x0403CC82962B5077ULL, 0x86CF6343A009E059ULL, 0x40F04B927BCAD70BULL, 0xA49F6447245BD2C9ULL, 
            0x69070C576C9BCF40ULL, 0x43E11158127F42B9ULL, 0x09F7D62EB65C1585ULL, 0xAAAFFBBEB04A0425ULL, 
            0x3C78B922FC6F532DULL, 0x02F7545DA2A2CCFEULL, 0xFA95CF75C8C23065ULL, 0x36ECCBB71EA937E1ULL
        },
        {
            0x243747CE6844FD71ULL, 0xBEE7E513F6D52E21ULL, 0x0C5D1B5A61BDF2C0ULL, 0x8C119FBA12D16418ULL, 
            0x5B4EAA230DC46D3CULL, 0xFCC4D1CDFA92C97AULL, 0xE7FB28AEA1C72262ULL, 0xE2E1D3E5337C1B62ULL, 
            0xE093C0423A706752ULL, 0xCE0369552A4F5AB1ULL, 0x6442644258FC3E60ULL, 0x788CBFE04A728A57ULL, 
            0x6252BF9C408321CAULL, 0xAB6437CAC04F4CAFULL, 0x0170B37A95AECC65ULL, 0x1260AA6383221836ULL, 
            0x48737A1EFCA2DF7DULL, 0x4272E0DB5808F7CEULL, 0xC4F53D7FDDC478D4ULL, 0xB2474300A3EA7BA6ULL, 
            0x33EBE1FC78074C6EULL, 0xC999B3670D7BBFF8ULL, 0x97F3CF12F7D45263ULL, 0x4E3838FA5427D6F2ULL, 
            0x4A8A7838EB20A980ULL, 0x9E9DD97673F917B7ULL, 0x2DCB6A095B9E977EULL, 0x3E4C6B09EF47B137ULL, 
            0xAE432755B91F859AULL, 0x2441152442CE61ADULL, 0x574527AD2C7739DDULL, 0x8CF4EFD4AA617939ULL
        },
        {
            0xCD8D26849A318D47ULL, 0x2C4EDD3CA15DACE0ULL, 0x4ADE340163260EB6ULL, 0x7D2813C9937BC820ULL, 
            0x7C3D1684DB21148EULL, 0x075EE8BCA3B752EDULL, 0xD002A992A363BF4BULL, 0xC33437826E6B32AAULL, 
            0x68B71C75C02A2F82ULL, 0x92C5A824D6E79539ULL, 0xABAFE554A6301093ULL, 0xDB304E1862B2D01EULL, 
            0x7BC75715B83A6296ULL, 0x81F253E70C23D3A6ULL, 0xDC1DE3CDC571E09DULL, 0xDA62F7A03D6E046AULL, 
            0x887213B322CD4C00ULL, 0xC774038612966ED0ULL, 0x55A19EB1B351DC52ULL, 0xA4EE5EB62E28AA31ULL, 
            0x83494FBA9F1F8FA7ULL, 0xC957ED3EF96078A8ULL, 0xFA2EE55E33542CCFULL, 0xE9384E2E8D302C75ULL, 
            0x8FDDA9BB461C61BAULL, 0x50BF59CC38B194FEULL, 0xB5683453B73DEAFCULL, 0xFDAF3815ADC544F9ULL, 
            0xF3653B4C130BF655ULL, 0xD919CF89C2C5700FULL, 0x57CC142F9253E0EFULL, 0x3D0A00807B3C93DCULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseGConstants = {
    0x82351344125C75E5ULL,
    0x5EA98EA5839D703EULL,
    0xFEB987EAF05B7147ULL,
    0x82351344125C75E5ULL,
    0x5EA98EA5839D703EULL,
    0xFEB987EAF05B7147ULL,
    0xECB7906D7B1C1E45ULL,
    0x08345F664B37608BULL,
    0x66,
    0xCE,
    0xF2,
    0xEC,
    0x46,
    0xA8,
    0x50,
    0x8C
};

const TwistDomainSaltSet TwistExpander_WaterPolo::kPhaseHSalts = {
    {
        {
            0xEAE3598975843070ULL, 0xD8037B501F1F7776ULL, 0xE1B0D5D574069E82ULL, 0x15D5281330E3EB82ULL, 
            0x5FB9447B372CFF5CULL, 0x7DAD42ADF94F3551ULL, 0x22D4944FFF0D8CF3ULL, 0xDE14C3C74B5C8DA4ULL, 
            0x40E13C80E33D94C6ULL, 0xBB42766910124C79ULL, 0x8D3BE28823632ECCULL, 0x949CEF8425B312EFULL, 
            0x6ED69C496277EC1AULL, 0x356FFC6E254669FAULL, 0x16D5A4E82F3D1665ULL, 0xF73D2F068358CE8BULL, 
            0xF59B967168158A9FULL, 0x49EAADAE8F4C4494ULL, 0x661168003491137EULL, 0x70C0FDCD2CB2D3C4ULL, 
            0x31CABBAF08C35C11ULL, 0x5EACF7434CE28976ULL, 0x155F9DB234B7CEB0ULL, 0xDA848D51BCA537B2ULL, 
            0x4D98003EA9314691ULL, 0xCB00139A1C2FD57BULL, 0xEEEE5629F9751B8FULL, 0x21B1E8EF666CC2FBULL, 
            0xA665E261722EF9F8ULL, 0xD28AC273A5A67D1AULL, 0xF70FBB6315EC2884ULL, 0x6AA8449CAF108247ULL
        },
        {
            0x902D460FEFA678C4ULL, 0x9E7192904DA54BCCULL, 0x53EEFEBEE8A4359CULL, 0xDBE16CF289E18707ULL, 
            0x7F5AF4CE4605020BULL, 0x9D8046BA7FCF416AULL, 0x15D83BFEE5326831ULL, 0xB89ED9D77CCE014FULL, 
            0x5F979886B76C4D78ULL, 0x34FBB9C0BCDA9F31ULL, 0x36CF2D6FB9DA40EDULL, 0x7290CEB86EE87171ULL, 
            0xB3D5D80B12196BE5ULL, 0x2AB08D12561B8135ULL, 0x2A26AC2B771610EAULL, 0x6B05094952112FD6ULL, 
            0x73BA3407674049BBULL, 0x262C66B2D6DD3423ULL, 0xD1D7F828DD07DF19ULL, 0xEC7B53F1B63CC35DULL, 
            0xFA05FB35B0D17C5EULL, 0x8297E87EA6626520ULL, 0x01E5DB4CE7E37D80ULL, 0xB55B612A4951C29CULL, 
            0xD0FB3DC6109D79BBULL, 0x85E326A20254FB28ULL, 0x7D415D146BA8E49CULL, 0x9D215C7D2D562CCAULL, 
            0xBE92714EAECC1FF6ULL, 0x58713124F6A52950ULL, 0xECD0A4AB044A75B4ULL, 0xDE67BB8244F3E21BULL
        },
        {
            0xDE7CCCCF4B5AF9A2ULL, 0x65767B0DF4CD9A0EULL, 0x40AA9489ECA8856BULL, 0xC5957862CA5C55A8ULL, 
            0x483F05165DF4268BULL, 0xA8907E0346289952ULL, 0xE75594A4EB2885ABULL, 0xA632EFA0A564D512ULL, 
            0xBF38017154AE7686ULL, 0xDFBB64C0FD1E10C9ULL, 0xEA42FA71FD3D4EA6ULL, 0x833DC59965249F35ULL, 
            0x52E834B27B8A44DDULL, 0xD89794B2FC37D181ULL, 0x0D7DABD934160353ULL, 0xC9DF3A7532AA640BULL, 
            0x441A8FCD2ECD0250ULL, 0x99B5273CCF607118ULL, 0xB75AB4BED7E8556EULL, 0x9CA8C50D490B7280ULL, 
            0xA56377BA2739124AULL, 0x4690BFF375F90988ULL, 0xF4D7E4E06B9A9C29ULL, 0x1577B7A420C88B5EULL, 
            0xF70958B20E923D5CULL, 0x66D184D689C5B887ULL, 0x4989B22CB71CD027ULL, 0xE95F66F21F93264DULL, 
            0x1B2051B403972BEFULL, 0xB85D04C256838F53ULL, 0x538E592779BA2B6BULL, 0x04171813DBC8EE92ULL
        },
        {
            0x346CD6D66BDB17EFULL, 0x832E16A63613DE1DULL, 0xE65DDA3E7CBE591FULL, 0xBAA48012C7FFD525ULL, 
            0x2E65030DC45DEAD9ULL, 0x352F7BDFB66BB2D5ULL, 0x853825127C805FD1ULL, 0x86A4F6C1DD71AFF9ULL, 
            0x522BEA6041E733C2ULL, 0xFEFEAE053E8D3E2EULL, 0x93A5F70D3C9638AFULL, 0xEEEF7516DA1DD519ULL, 
            0x5DDE3DF22899A5CEULL, 0x0FFC433748A43E1EULL, 0x20A530A02AA9C54FULL, 0xD882DA0E0C50C81CULL, 
            0x2975234AEDF8CC9EULL, 0x3C86AE6589594070ULL, 0x52011B84E7371022ULL, 0x44D7E9DCC7D8EF4FULL, 
            0x940BBF73689006B9ULL, 0x0AB5EA383F4EF0EDULL, 0xBA5CA88331C97C12ULL, 0x2127586FE824B576ULL, 
            0xBF466CA1F3C36922ULL, 0x1A86C0DB14660CEEULL, 0x6BC8C01060994667ULL, 0x7C71535FA446F00EULL, 
            0xD22C871F47AB506DULL, 0x8A98500C872B12F1ULL, 0x9F1ACFDBABF5C25FULL, 0x73830E0F3CDD80E9ULL
        },
        {
            0xF8D9FAB3B422BD17ULL, 0x0455A918A885A003ULL, 0x1D80715759128EC9ULL, 0x86C67147B2439C7BULL, 
            0x41689F5D4CEB622FULL, 0x2BA0E19FBD8F265DULL, 0x0D16BBA211E9B797ULL, 0x31BEC3FFE36FFA7BULL, 
            0x0B052059F5EF74DDULL, 0x00192F1864120CA9ULL, 0xA89AA6F8AF4EF546ULL, 0x208F6A75130E8498ULL, 
            0x4583C9B914FB3AE1ULL, 0x57EDEF7C7ECDB922ULL, 0x415B06439D5C354FULL, 0xE82515D44E7FE5C9ULL, 
            0xB3BC4DD91503E415ULL, 0xFCEB78F9FBFF2E1EULL, 0xCBE265D443B7109EULL, 0x521E49E6D2B4F426ULL, 
            0x2D234B52C478F8CBULL, 0xBA6B3B22911B1998ULL, 0x6DA7ADEA09844999ULL, 0x861F3BDB6B8A80E4ULL, 
            0xF1825149D065B76EULL, 0x723A8924871E5499ULL, 0x793BE155CBF7021BULL, 0x618B966F80015D37ULL, 
            0xEE15F577BA200DE5ULL, 0xED76FC5179803D71ULL, 0x22719C9D7D755D1BULL, 0x7EDFAE2E7FA65A6FULL
        },
        {
            0xF8D46A7F09749D0CULL, 0x295CA41C3C7510E9ULL, 0x4B95045FE839A56CULL, 0x94BBA7AA4FD38090ULL, 
            0x2282573C8091C20DULL, 0x63CCD937A09543D6ULL, 0x7AC186AD46309B7CULL, 0x5142524CDBC795ABULL, 
            0x9F3531E4EFFCA320ULL, 0xFBEBB9183888A8D3ULL, 0xA8F73CB303706BDDULL, 0xC5100A90D5D8CA02ULL, 
            0x7C0E7B3380A28379ULL, 0x6FD57532AD2F6AFBULL, 0xA32E0D8E61770A30ULL, 0xDE53428C2A3C0F8BULL, 
            0x9649D775CE03EF65ULL, 0x7EBE3EBC6707B63DULL, 0x073F5D8618B765DCULL, 0x2A0C659224F40A71ULL, 
            0x3BE3E6C845D7C359ULL, 0xFEF09A6C62368293ULL, 0x9DD57B9DB4FAACD3ULL, 0xFF044F13F0E5916EULL, 
            0x2A5710F74F3DE5EEULL, 0x5E1B97C741C6684DULL, 0xE942B5DCBDBCD3D8ULL, 0x5BC225D2DC16DB4CULL, 
            0x7B35C04A5A0F3665ULL, 0xE854A344887789F7ULL, 0x466FA9A08961388AULL, 0xFEE83F8B70124986ULL
        }
    },
    {
        {
            0x66CDD9D5C3B5EB7DULL, 0x8A8E147F1DA06A71ULL, 0x6643B16F8EFAE52BULL, 0x090F6234B9F230C2ULL, 
            0xA7A36BC334300255ULL, 0x082011DA786DA766ULL, 0xE4A863EFFD9C58C0ULL, 0x9AE2C4C8F4543AECULL, 
            0xB20A7D894D534024ULL, 0x1FD2F8D6A7BD60C7ULL, 0xD6869930DBDC8CDDULL, 0x24A68A6F60DE6A4CULL, 
            0x4D0DB5F5B82F0F9EULL, 0x05428B7A79E9658DULL, 0xBD78282BC530E742ULL, 0x2666EC605113E4EDULL, 
            0x79F344FDF1CDB6F9ULL, 0x3FECB4493752855DULL, 0xEE08517C8F8DFC18ULL, 0x2432390C4B074469ULL, 
            0x4F1A9D2ACAA281CEULL, 0xBA4DAF1C4640582CULL, 0x72EC3CEC1BAE3636ULL, 0xB2CE458F88B19B1BULL, 
            0x8292AF5C08D3FBF2ULL, 0x30DAEF0DF0DF857AULL, 0xC6191858CB70EAFCULL, 0x73A8CEEED8254BE3ULL, 
            0xEBF1198EBB6818C7ULL, 0x642038E6306A91B7ULL, 0xF06FC9C5A9C3F0E0ULL, 0x07F8766CDCDF73B4ULL
        },
        {
            0x02D07C114CA6B109ULL, 0x8E974BD9D155BC60ULL, 0x24025F48F727074EULL, 0x53E7290EC2D9F0A1ULL, 
            0x60C632FBD47F3F44ULL, 0x5C4E30AA4DCB989EULL, 0x2F3332B01091B820ULL, 0xEB0C992698AB299EULL, 
            0x09CAC1645CDAFE55ULL, 0x38FED445B1FABF4EULL, 0xB5B209E920469B05ULL, 0x57932700F36DF5D5ULL, 
            0xF7354748877F81A6ULL, 0x7FD448E4C566972FULL, 0x548DC07232B2B3A7ULL, 0x10AB246E101DC91AULL, 
            0x1AC203AED80DBF95ULL, 0xBC3172875C78061DULL, 0x41CD47FCFBBB4508ULL, 0x2823102B113B0E43ULL, 
            0x3A4F80358FAA4C55ULL, 0xAEAFC85A5C6F9B8AULL, 0x92A5095A0066FCC1ULL, 0x5642EF0D751A49C2ULL, 
            0x097535AC3E50B05FULL, 0xB274C2D21731C5CAULL, 0x61CA8099C4522566ULL, 0x9A75F0263C58CE00ULL, 
            0x2AE8D71E9E8CA344ULL, 0x9C65A78A9EFF1FC6ULL, 0xDD2F35B87F1341DDULL, 0x1E813361100555CFULL
        },
        {
            0xD4E206E04D1394A1ULL, 0x68CABEE7AB015AA9ULL, 0x57E9CBEFE0797E30ULL, 0xFB57F1237487038FULL, 
            0x81A392FA6593128AULL, 0xFB276A338C3043ACULL, 0x19F56B857C245906ULL, 0x166C1CBD7FD0D8F9ULL, 
            0x66FD6B26C272FE85ULL, 0x35EDD62F83F03EE6ULL, 0xB1D8326BB922E4A0ULL, 0xEADBF7F2C60A66EEULL, 
            0xC063C510A4066522ULL, 0xEAE8980C3069E37FULL, 0x39529260ECE9488CULL, 0xE0228E0F6D84B40BULL, 
            0x879922028EF83011ULL, 0x07242A6F989A4D89ULL, 0xAE927D801379BD8AULL, 0x574B120E3C114199ULL, 
            0x2F2AECDBEA6E7B6AULL, 0x1DCD083182D8DAF0ULL, 0x3230A9CA4FA33F4FULL, 0x84D9D38A0D885EF5ULL, 
            0x8A5945177A1C3D00ULL, 0xC24D5A9BB3DEE74EULL, 0xE836B0F65B595458ULL, 0x2C5929C728E7D023ULL, 
            0x138932828BC2E496ULL, 0x88732F9D8C0E4844ULL, 0xC190A5F16AE86201ULL, 0xD8D77F6414D4B42FULL
        },
        {
            0x5E4AFE38D383435FULL, 0x30DC00DF54FDAA01ULL, 0x9E025C53CD08C0DEULL, 0x715F61F1DB1AE852ULL, 
            0xA7929784061129EAULL, 0x89E90DE2B9A31C9AULL, 0xEFD7D2AC6355F6A8ULL, 0x507D5DF240AD29F9ULL, 
            0x8BD8C84DCE6DADB1ULL, 0xE1F478958668E312ULL, 0x3D046CA95934D17AULL, 0x2C4249BB1BA11161ULL, 
            0x08BCD85CA978AC9FULL, 0x996C1542225A8016ULL, 0xEA250F17D3EFE826ULL, 0xA3061C553901CB3FULL, 
            0xB8B24E25A7F6B09DULL, 0xA0606BA21955DC04ULL, 0xE3A5D642EB986C4CULL, 0xE015224BF2A61B54ULL, 
            0xEE829924DFADD701ULL, 0x8CA3C2461CB7F2CFULL, 0x5D71BD933B5CB264ULL, 0x7E7C62B003330930ULL, 
            0x117CA949A29C0F06ULL, 0xA7D945F93E0CF855ULL, 0x1BFD2C92AC1A3A8FULL, 0xDC966FB51DD80DD1ULL, 
            0xD7D47F569CD18E24ULL, 0x90C35138DCED9CF2ULL, 0x162B10A52229022EULL, 0x01428BC309EEF003ULL
        },
        {
            0x412480F54C6DC2BCULL, 0x66FC98341B881B32ULL, 0xF241A30DD1F363B5ULL, 0x6BC4EBFC22322416ULL, 
            0x4B4246E32B7361A4ULL, 0x53EBD5B52F86FD40ULL, 0xB4F930D31610A0F6ULL, 0x5AFC7C6810666C9FULL, 
            0x4C057CB8D0220256ULL, 0x9C536009577962F3ULL, 0x7B5BDE803F5D21C7ULL, 0x7BB193CC44AACC67ULL, 
            0x49BA8CA005D922B5ULL, 0x5086A30840D985D8ULL, 0xC310743ACC3F5D8BULL, 0x3F42CB34B33755ABULL, 
            0x300997B872487291ULL, 0x3D2FFD2CE42C5717ULL, 0xCBB32A3B377CC83CULL, 0xF95C30DD49EFC175ULL, 
            0x9E75CAB48A1CFF15ULL, 0xF5C3CC88FA1BF73FULL, 0x3C0BCCF8C30EFD4CULL, 0xD4011B86EB86C678ULL, 
            0xD88ADCB651E77903ULL, 0xDD0B028116EB5D41ULL, 0x0EBA82C6133E4D91ULL, 0xE1529DCDBE69B4FAULL, 
            0x78B86AAB13994A91ULL, 0xBDC6ED629614DBFCULL, 0xC1301E1C3CEE6706ULL, 0x1A73B23866495D10ULL
        },
        {
            0xE074D9886C8EE7E1ULL, 0xB2EBABAA41E9023DULL, 0x35EB598B91939D60ULL, 0x2F55040A8D9B49A5ULL, 
            0x1861BE28D62203C0ULL, 0xD8B4AAE720C89A66ULL, 0x3AB302760FF0B8BBULL, 0x970F675D812F2900ULL, 
            0xAC6D6A668FEA4188ULL, 0xF5DBE6F29DB6135EULL, 0x80F92AB9FFBFEB19ULL, 0xB6C5AFA5A1691A5DULL, 
            0xB32BE92061BB4E47ULL, 0x23AB999051BA95BBULL, 0xD14867F1810F8F7CULL, 0x65C80DC22D9A6AC7ULL, 
            0x6629D27E7D0ECB6EULL, 0xEE24E861871572ECULL, 0x737A67ECE5885C90ULL, 0x75CDD97635B4DE16ULL, 
            0xCB33C5974E9CCB6EULL, 0x78602E122D3EE952ULL, 0x5E851736D9E7FDE3ULL, 0xF36220B4DED2C108ULL, 
            0x0A81E8CB8EFF8AF6ULL, 0x6FF8A7E63F94B2FBULL, 0x6D834F67FCD12B47ULL, 0xA0BB483AAA030442ULL, 
            0xA1E0DC06237E90E0ULL, 0xF8E08612B6DE5288ULL, 0x07ACEDE4749B0122ULL, 0x3E3E8E3B9ED03CD9ULL
        }
    },
    {
        {
            0x8A7553E062689966ULL, 0x416235D88A0680D7ULL, 0x023F8D23815CCFF4ULL, 0x2C262F6F4FD6F604ULL, 
            0xDD1A1C2AE48849B5ULL, 0x0B22B648E852581FULL, 0x4DE28A01A066827CULL, 0xA1B6D14D0569E043ULL, 
            0x0DFDE1979600BF62ULL, 0x7B6982798F8DB138ULL, 0x59E4BAEF45E24789ULL, 0x989B9F6C629F389FULL, 
            0xB486E42BE03BA8B4ULL, 0x26D75353953747A3ULL, 0x94FE2A4485BBBB95ULL, 0x960B50E499ACBEFDULL, 
            0xC8681456893041A2ULL, 0x46C3C9FFFE984E63ULL, 0xF92433080AB01EA4ULL, 0x86A71A5D9822EC43ULL, 
            0xC67F4897348DA1C7ULL, 0xE70B89A8A3DD3729ULL, 0xEAA24133F82A5DAEULL, 0x64402FFDAEE665A5ULL, 
            0x5367F226F292A064ULL, 0x910CE9C673D6230BULL, 0x5DB7F834B4E954FBULL, 0x55FF5BF2C728DC07ULL, 
            0x08FFEE8715B85AE4ULL, 0x0E18D6061EFF54CBULL, 0x5C18AF282C8B5A88ULL, 0x999E69CD45529EEBULL
        },
        {
            0x6CA2B9CA2B96940CULL, 0x23EBB42C30AF6E8BULL, 0x0C7DA1FC0A0E63B2ULL, 0xAE2D3E6CCA4C8388ULL, 
            0x272FD80A6E887FFDULL, 0x4E88930FBA5D8F83ULL, 0x1F77B74F36E4F5ADULL, 0x7607461E756AD8DCULL, 
            0x3F47649E630425BEULL, 0xA7B2F241DD936021ULL, 0xD4AEBC51E08C5D4CULL, 0xB1DEFE5FB6C802C2ULL, 
            0xF6E49A386C0E3E66ULL, 0x70C156C71C16BDA9ULL, 0xBFBE033DA8C3DC1DULL, 0xF706B281FEA3CB40ULL, 
            0x3F7C49088AD8023FULL, 0x4C0399181061E611ULL, 0xDEE31BFC80E70097ULL, 0xC37D6B41AA7F0BC6ULL, 
            0xDC4E46B6A92C98E5ULL, 0x92502E460DC9E892ULL, 0xD48302EEA54E1C01ULL, 0xF5B6FE57091D9C28ULL, 
            0x76D755A59D4AD413ULL, 0x4822421E2886AEACULL, 0x8F69A1D4A05AF402ULL, 0xF8995E567B9320BAULL, 
            0x3F2B826170A9577DULL, 0x3C7E6214E9A6630FULL, 0xAFCAF1323E61B72AULL, 0xE27C37D58BB42C54ULL
        },
        {
            0x4194BE643784E2CAULL, 0xB913A33BE2031DBCULL, 0x198809E489961827ULL, 0xC352674F08273A1CULL, 
            0x207C377FBA98B048ULL, 0xBA0A2E6DF1E7D124ULL, 0xEEB748CBCF46F029ULL, 0x86CD103F2974873EULL, 
            0x98008F5F6315A7D6ULL, 0xE9B7E4E86269AB3CULL, 0x9DF42E39F24AA824ULL, 0x71A43B50DA509932ULL, 
            0x23B67792D7FE598AULL, 0x965E5B9B71BA1C1EULL, 0x3407B73E4D7113E2ULL, 0xC5D7A30172FE631EULL, 
            0x860890022340D782ULL, 0x090394BF35CDF5F6ULL, 0xABA3EF4F67D52151ULL, 0x6CA6CB45AB538751ULL, 
            0xBCCC68BEF96F0FB7ULL, 0x27196BDA69F68EB7ULL, 0x8B4F86F185B45C7AULL, 0x28EA6FE7CEDFB169ULL, 
            0xA113026565ECCB2DULL, 0xAC3BB6A239E269CBULL, 0x4EABCC422A06074BULL, 0x1F60A4CFF30BA0E0ULL, 
            0xA28035E338D4C726ULL, 0x44D26E8A533EE563ULL, 0xD454329248F0674BULL, 0x2E289DE54230D800ULL
        },
        {
            0xB38B042C70766016ULL, 0xFCA730B44C8A8738ULL, 0x64EEDD354C016F2AULL, 0xC813B847A651C59AULL, 
            0xD069FC12DF5F4636ULL, 0x5AE670A251B2176AULL, 0x73110EC58336A4DDULL, 0x8B48A479D3692C88ULL, 
            0xB046B692F685B30DULL, 0x572DDD61EB3C4DC9ULL, 0x2C08E9F4877B2C86ULL, 0xDEE6B4B868962AC6ULL, 
            0x4998EA8162DF2B98ULL, 0xB84DABFEEEE6F155ULL, 0xF935A78DE6422F81ULL, 0xA849A8E49E237926ULL, 
            0xB01666416FDD4EDBULL, 0x711091A227236A15ULL, 0x23106065998CF112ULL, 0x950FB9832AD776B3ULL, 
            0xFFC06A18E767E55EULL, 0xC401C1F0D50DAB3AULL, 0xE68720C7F0C63B5FULL, 0x50BA9B892B8BB737ULL, 
            0xA8E5A4F5CA3942C4ULL, 0xB57EF5F8050B5925ULL, 0x4DE42F63ED7FD4B4ULL, 0xB0A8536339F4A8EAULL, 
            0x6FD76388795F3AD8ULL, 0x2379C44CB42162E4ULL, 0xADB6EDEA7F09AE94ULL, 0xF3A29FBBDDB6143EULL
        },
        {
            0xF8DFBA5860484CBEULL, 0xAE641230A33F7E00ULL, 0xC30672E797D1E5E6ULL, 0xCD58364405D271C9ULL, 
            0x38F6E6476F79E50AULL, 0x30640224B247E931ULL, 0x478871C8153E1685ULL, 0x78304BCDB4643B64ULL, 
            0x47141B317706FDC3ULL, 0x543D712C35019846ULL, 0x062B1DB376006BC7ULL, 0xC71C26204E8CB78BULL, 
            0x526AC635EAB3707FULL, 0xC91582BFAF7D8A9FULL, 0x646A858A53EC2192ULL, 0xDE0DF437F309A7B1ULL, 
            0x615986D8C582DF7FULL, 0x7D95D518F3930C6DULL, 0x783EC7DB9C5DCFC7ULL, 0xF23385E65DB85241ULL, 
            0xB014158CB0E6AA12ULL, 0x36F057EB5E4D0860ULL, 0x0B086B77B57294F5ULL, 0x33965EE2770896EDULL, 
            0xD1CA14B43CEAD8DBULL, 0x3BFAD9DBA63FD10BULL, 0x626C722AD0287091ULL, 0xDFBBFBCCDFD25FE9ULL, 
            0x1D1590B6B54437E6ULL, 0x8B8A25C8FD6B812FULL, 0xF8DC4A31D9C2E3CCULL, 0x0B9B3F5DD5E94DD5ULL
        },
        {
            0x239EC87CCE8C3C09ULL, 0xE5BBA8328292941CULL, 0x5EDE46CD046F2821ULL, 0x992FC1F1527DE2BBULL, 
            0x5D472CB5C26F95D9ULL, 0x931486226AD0D0AFULL, 0xB742A9EC9A99C5DEULL, 0x21FABC960AD2C49CULL, 
            0x653A820B16666A12ULL, 0xC6DB1B4387329313ULL, 0xB270E5B5CF19EC68ULL, 0x42BCE6E1270FB104ULL, 
            0xAAFFDF5F23527FA5ULL, 0x84EECB69A82280CFULL, 0x023C673DA026BCABULL, 0xA7500D36E22765DBULL, 
            0x0F1EAE9AD78BB617ULL, 0x1B1DBFED1AA8F51BULL, 0x444832A0620D30B9ULL, 0xE0EDAABC308A5FD0ULL, 
            0x3A500D19FA6B1116ULL, 0xD57490FB8329B1B8ULL, 0x3F46DCF882A228D6ULL, 0x4152A58C2359C3D4ULL, 
            0x6F74DDA4600EF8C5ULL, 0xE34B10FD185996B4ULL, 0x8B72C02FE2EFB606ULL, 0xF4EFB245FBB2CB18ULL, 
            0xF074658AF74EEA4BULL, 0x93293AB2C1BCFE9CULL, 0x59A9A0F9D7ED4762ULL, 0x4AC5D10CAF0F6F16ULL
        }
    }
};

const TwistDomainConstants TwistExpander_WaterPolo::kPhaseHConstants = {
    0x2DEE82860F2C8A62ULL,
    0xAAE96E09D815F284ULL,
    0x54C76DFDA29F5D8EULL,
    0x2DEE82860F2C8A62ULL,
    0xAAE96E09D815F284ULL,
    0x54C76DFDA29F5D8EULL,
    0x1FDE53268B8D7386ULL,
    0x8B4D7E758AF7A0F5ULL,
    0xD0,
    0xEA,
    0x60,
    0x27,
    0x71,
    0x59,
    0x08,
    0x94
};

