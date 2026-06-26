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
        aPrevious = 13052987488919251717U;
        aCarry = 12925417499843997557U;
        aWandererA = 17130731901232108986U;
        aWandererB = 14601828363076300394U;
        aWandererC = 13262625789918367660U;
        aWandererD = 12213420518664754441U;
        aWandererE = 12490310535494595106U;
        aWandererF = 14825009275151469324U;
        aWandererG = 14689326403340139126U;
        aWandererH = 13331759924172716468U;
        aWandererI = 16431216614821325156U;
        aWandererJ = 18031837177480598723U;
        aWandererK = 15682683974002947091U;
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
    TwistExpander_Archery_Arx aKDF_A_BArx;
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
    TwistExpander_Archery_Arx aKDF_A_CArx;
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
    TwistExpander_Archery_Arx aKDF_A_DArx;
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
        aPrevious = 17012322579901938005U;
        aCarry = 14223323838677278829U;
        aWandererA = 15828558361489957866U;
        aWandererB = 15938630754383196324U;
        aWandererC = 15886938700500589209U;
        aWandererD = 16395052428273090098U;
        aWandererE = 14418577862111176126U;
        aWandererF = 13687343932908055457U;
        aWandererG = 10708900898888063321U;
        aWandererH = 14162732287450074238U;
        aWandererI = 9569069839628388514U;
        aWandererJ = 9922968616063898236U;
        aWandererK = 11905557691293646942U;
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
    std::uint64_t aPrevious = 0xF99AE3E485068E4EULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xC8E201E627BDB494ULL;

    std::uint64_t aWandererA = 0xB23AAFC709633B51ULL;
    std::uint64_t aWandererB = 0xDE566A837FC74C6AULL;
    std::uint64_t aWandererC = 0x9585A7C54CFF36ACULL;
    std::uint64_t aWandererD = 0xB2B11B9A52517B31ULL;
    std::uint64_t aWandererE = 0xD05476C51A2F1A56ULL;
    std::uint64_t aWandererF = 0x856E192CB65601B5ULL;
    std::uint64_t aWandererG = 0xFF40959E54E0212DULL;
    std::uint64_t aWandererH = 0xFDCE13C8DD77198BULL;
    std::uint64_t aWandererI = 0xC1C1BBCB2149B5B0ULL;
    std::uint64_t aWandererJ = 0xD8D4175100FA4FAEULL;
    std::uint64_t aWandererK = 0x9F748845AE77776DULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC);
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
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneC);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Archery_Arx aSeed_AArx;
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
    TwistExpander_Archery_Arx aSeed_BArx;
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
    TwistExpander_Archery_Arx aSeed_CArx;
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
    TwistExpander_Archery_Arx aSeed_DArx;
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
    TwistExpander_Archery_Arx aSeed_EArx;
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
    TwistExpander_Archery_Arx aSeed_FArx;
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
    TwistExpander_Archery_Arx aSeed_GArx;
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
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
    {
        aPrevious = 16604055561125104263U;
        aCarry = 16560737385971727521U;
        aWandererA = 18409366833950282006U;
        aWandererB = 13224751941357578336U;
        aWandererC = 13327080876043781265U;
        aWandererD = 14195978911487025857U;
        aWandererE = 17005489602000903887U;
        aWandererF = 11283278888280520802U;
        aWandererG = 14220568801174388094U;
        aWandererH = 12746726159951674609U;
        aWandererI = 16867663619974469583U;
        aWandererJ = 10829278131903638728U;
        aWandererK = 15628803490980800049U;
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
        // read from: aOperationLaneA source quarters 3, 3, 2, 1 with offsets 5753U, 7190U, 4677U, 4130U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5753U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7190U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4677U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4130U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 3, 2 with offsets 2401U, 7858U, 2365U, 7346U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2401U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7858U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2365U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7346U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 1, 3 with offsets 6793U, 4294U, 3071U, 8098U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6793U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4294U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3071U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8098U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 0, 0 with offsets 7905U, 6936U, 7002U, 2196U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7905U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6936U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7002U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2196U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 2, 0, 3 with offsets 636U, 1423U, 1803U, 1426U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 636U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1423U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1426U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 0, 1 with offsets 397U, 967U, 984U, 548U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 397U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 967U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 548U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 0, 3, 1 with offsets 1328U, 1104U, 46U, 2005U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1328U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1104U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 46U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 2, 3, 0, 1 with offsets 764U, 1287U, 1605U, 848U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 764U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1287U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1605U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1214U, 812U, 1183U, 1508U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1214U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 812U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1183U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1508U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 2, 1 with offsets 3587U, 8047U, 4824U, 6794U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3587U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8047U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4824U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6794U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 0, 3 with offsets 3398U, 6989U, 2852U, 4564U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3398U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6989U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2852U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4564U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 0 with offsets 7893U, 5749U, 659U, 2669U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7893U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5749U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 659U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2669U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 1, 3, 2 with offsets 7283U, 7275U, 1976U, 2043U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7283U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7275U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1976U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2043U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3124U, 5383U, 3976U, 6566U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3124U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 5383U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 3976U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6566U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 819U, 1471U, 1038U, 347U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 819U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1471U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 347U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 758U, 779U, 825U, 954U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 758U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 779U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 825U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 954U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1675U, 161U, 861U, 1043U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1675U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 861U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1043U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 607U, 80U, 1349U, 1625U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 607U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 80U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1349U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1625U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 0, 1 [0..<W_KEY]
        // offsets: 1103U, 101U, 1555U, 672U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1103U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 101U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 672U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Archery::kPhaseASalts = {
    {
        {
            0x17A4F54329494F94ULL, 0xAD39CC400EDC66D9ULL, 0xE55BA8D53569BA97ULL, 0xF0BE944B988213B5ULL, 
            0xFEF75D3F7C7EE4CAULL, 0x6B403DB40F4C2B13ULL, 0x3E484A780750328EULL, 0xF012A0DB57E10DDCULL, 
            0x094487992B327F10ULL, 0x43A7EC0F573CF8A2ULL, 0xEBA3E518050D3EA5ULL, 0x2A253BB128CFC14DULL, 
            0x765A6E00833837BBULL, 0x0A7DD8C0CA44B579ULL, 0x15CBF1C3171EC980ULL, 0xB9DFED3125BEF0F4ULL, 
            0xE1E9BF2E491A5148ULL, 0x0B0C7DA898F82A88ULL, 0xDE61487030A32C1AULL, 0xDB358D81B469805CULL, 
            0xFC34246CC75318FCULL, 0xD89C688DEAECAACCULL, 0xB48C1CB0DDFEBE2BULL, 0xEA412052E0AC6E6EULL, 
            0x0F767B6547AF9902ULL, 0x7B4327C64BF9AD8DULL, 0x859A1ED50F1EDF3CULL, 0xF09D5BA586A1CC0EULL, 
            0x455A62F7C0094926ULL, 0xE4C089BF015CAF3AULL, 0x4A29880B159E190AULL, 0x13E8E2B01ACB5A34ULL
        },
        {
            0x8B84B27ADB6C47C3ULL, 0x28A6A21AA655F075ULL, 0x64235A515A530B4DULL, 0x5EA07359F220E27AULL, 
            0x42DC6C67162E1FF6ULL, 0x3BD2269B532BAEB6ULL, 0x935495625E7C33BDULL, 0xBFE28DC112F80A70ULL, 
            0x4FAFD87D27C704C5ULL, 0x4DDD20DEB1A561CEULL, 0x107CC28A59B3191AULL, 0xF40E3A4F12ADC601ULL, 
            0x4EF0DA81DC182352ULL, 0xBE9E10CB4C4CF9C9ULL, 0xBE58C9E9AD2A5232ULL, 0x102001EB7108C6D1ULL, 
            0xB3AF7DA29702A8D5ULL, 0x5F3FA9294A7924E8ULL, 0x0CC424B9123DB977ULL, 0xDA0DCD4AF048FF3DULL, 
            0xBE0427DDDC8DCF75ULL, 0x04B267850BA68721ULL, 0xE1A025BCCC8EAC45ULL, 0xAB4DFAE17E5EA1EBULL, 
            0x4E8858E8DC5C70C2ULL, 0x129EA09EF876DDCCULL, 0x760213D467E7AD44ULL, 0xB120E42B133CDE6DULL, 
            0xFA69944BCEA0FB6AULL, 0x8D22B3454007D436ULL, 0x9B81DF9E8F138EA3ULL, 0x859A034F97FE6AA4ULL
        },
        {
            0x7DE8F643141F18EBULL, 0xB257850A2E25F946ULL, 0x41743998F1F3E0D7ULL, 0x5EBE68388E31B5DFULL, 
            0x446868E39243B7EBULL, 0x477E8259CDF06C3EULL, 0x2ED213F43EAD5089ULL, 0xF6D810239CCD63A5ULL, 
            0x7B421C78832077ACULL, 0x0268352895AEB741ULL, 0x62FA62CBBB8E6791ULL, 0x120C49001FF23A3AULL, 
            0x8047793E320AC263ULL, 0x7081F9A7BA9BDA90ULL, 0x94738B0C3D41D092ULL, 0x77632CCF80C2A43BULL, 
            0xD9BAD535A0225DAFULL, 0x1A026854B45FCC08ULL, 0x5D2DEC1282455B7AULL, 0x6C9FEB51672B5B01ULL, 
            0x216F6BF8B469F3DBULL, 0xCA5C67B063AF5EBBULL, 0xE90DDB1643E92E41ULL, 0xDD4700D5C5E3BD09ULL, 
            0xF722830EC7F902B3ULL, 0x43155F096D413C4FULL, 0x08C3AF858A4AC96AULL, 0x24CAE8BDFFF357C1ULL, 
            0x03CD4F8E6732B95CULL, 0x78DA14CC36610042ULL, 0x27A85BF12AF9D519ULL, 0x897191DF357F6448ULL
        },
        {
            0x4D0A05689A832973ULL, 0xBAD0C347225467DBULL, 0xC37E513DEF65A8C7ULL, 0xD75DD87F58C17EF2ULL, 
            0x16CFA8DD4C648673ULL, 0x38A12608082C8825ULL, 0x3DE902E2930A96EBULL, 0x1D72FE8DD6C7ECE4ULL, 
            0xF0D5A5C0ECDC5022ULL, 0x751E84C6D26D1773ULL, 0xF71D539E546F6BA3ULL, 0xF3FB970ECBA4219EULL, 
            0x2E3F39C748736639ULL, 0xFEE9C1648542D075ULL, 0x9301393BF62E4019ULL, 0x1556327BCA802335ULL, 
            0x716AA1A3FB4978FEULL, 0x3276D5B0183DE9B7ULL, 0xAE0D117DD12A2F89ULL, 0xC2CDBE728D2D939AULL, 
            0x7F5AF70BD79DCC87ULL, 0x4D597516C9DDF21BULL, 0x2C089734C6633140ULL, 0xEF3D3DEA23468031ULL, 
            0x57D2D6E9AAA2AD60ULL, 0x7E99143498D2475BULL, 0x92C4B0A04636347DULL, 0x75CC8A58BA10B467ULL, 
            0x1F6FEFE877837964ULL, 0x03C3C660743A8589ULL, 0xECF03CCC7123D411ULL, 0x629F5A1F933D253AULL
        },
        {
            0x1D9EB56C64A79241ULL, 0x6E5B8D5CFF13B289ULL, 0x403C3D64CA4C00DDULL, 0xF1C1F42B3A74F357ULL, 
            0xA289944C62B53B3BULL, 0xC12152ED09DCD018ULL, 0xD4BD0C696E8C7625ULL, 0xA198EAADBFE0904AULL, 
            0x1FEB19F3440E69FBULL, 0x42B4D77D13E67490ULL, 0x96E43568CD596241ULL, 0xAAF151AC658953E2ULL, 
            0x07A2D0B05EDC7BEEULL, 0x1686EB79A7D0D1FEULL, 0xBDBD4CBE04A28AF4ULL, 0x1E9BF2B69C3DB37DULL, 
            0xABBDD3E8C9399902ULL, 0x4E84604FE6FAF464ULL, 0xC859E6292427086AULL, 0x242454CD2FB600D2ULL, 
            0x9CFF419223D68AF2ULL, 0xEB023E771AC326C6ULL, 0x899C72B82F9985C9ULL, 0x87656605B1991A24ULL, 
            0x5E17C109598AFF9BULL, 0xFD00876E4BDBFBDCULL, 0xB75991FBC6DD2622ULL, 0xE277B734B5A3CF93ULL, 
            0xFABF5A3E3CF49C39ULL, 0xAF1F9A46F4CB5FD1ULL, 0x631F855C0A22C71FULL, 0x8468EC1E19C56ED2ULL
        },
        {
            0xCF3F16073F052222ULL, 0xF9718322B5B11DB8ULL, 0x152571509EEE7077ULL, 0xB3110FFEE130E974ULL, 
            0xFA97BCFEE8418AE2ULL, 0xFADA328A99716E25ULL, 0xDCFB8D28B5591F1DULL, 0x251B2282D1392314ULL, 
            0xD14594480C20F7E4ULL, 0x4A53F6775C5114DCULL, 0x8C6361EAD7202F0AULL, 0x9650971B51EFC6B5ULL, 
            0x792C3DA771681582ULL, 0x368CAE0A5AA7BE3CULL, 0x68CDC343E2453080ULL, 0x07F8564D9EF7B10EULL, 
            0x301B267D843A8B74ULL, 0x6EFCBBACFFD15433ULL, 0xD53B4F2A028A983FULL, 0xB30FE0F35573C78FULL, 
            0xCFA704EA19435CCCULL, 0x8FBCF0D3EA0E9D00ULL, 0x1E9B2C4757A6362AULL, 0x256C9AF53E7B9B6AULL, 
            0x2BEA55FE6DBCF01BULL, 0x1427B7B8D8D4B266ULL, 0xEDACB3FC9E952086ULL, 0x470479505BCA97E8ULL, 
            0x9EC0CE6087766880ULL, 0xE50D7B00358CEAD5ULL, 0x21FED0C5A23269DEULL, 0xF9325C55D978B53DULL
        }
    },
    {
        {
            0x315E46DCED1B0CADULL, 0xFEFD4BBDCF3A1BC9ULL, 0xE34C799586410725ULL, 0x893C5D9F38EF22E8ULL, 
            0x560B728FC058F728ULL, 0xF92D1AFB2D51C6D2ULL, 0xB29E5FB89AC77F6DULL, 0x9FD7D1A9E594081BULL, 
            0x5345DF4B54A5604FULL, 0x5E7D01043A67BF9BULL, 0x9C57A886C807D083ULL, 0x69F5FC0AFF72E244ULL, 
            0xC4496525ACDF1067ULL, 0x5F4BDE2A9363959EULL, 0x4F979B0144441B70ULL, 0xD4AB04F2266F051DULL, 
            0xD3480FC6DCA400E1ULL, 0x634FA80BDB8C99BBULL, 0xA505782D269B7D3DULL, 0x6FE1736FB99D68DAULL, 
            0x927B4C882BB48205ULL, 0x1B3F3D62E311BEB9ULL, 0xD5A39F7A010E3F7CULL, 0xFD38BC0333C41580ULL, 
            0x8581D9A39D376F0DULL, 0x308C63B00D028F86ULL, 0x6356C9956AAEEBDAULL, 0x635D13F0E13F25B2ULL, 
            0x8DF3BA2F5330CDA3ULL, 0x77A268BD74B06EB1ULL, 0x89477960B7380117ULL, 0x72FB5958ABEA2646ULL
        },
        {
            0xDC52A308DBCBD8D0ULL, 0x3A401CACA25C0B07ULL, 0xAD62226E9D6CDA6BULL, 0x27C200EBA9ACDC26ULL, 
            0xDC95095F8C28AED4ULL, 0x310E259ADD8DA11FULL, 0x3622068CE5DA4468ULL, 0xF8FCCC40F80A2D0AULL, 
            0xFDA2ADF80757DF2DULL, 0xAE4AFF1E9671B9EDULL, 0x2B1827013B2EA0EEULL, 0x780B07AB726B37BDULL, 
            0xBD94CB17B57CAFCBULL, 0x289E50643ACF820EULL, 0x24708FCC9D030097ULL, 0x80C640543BE8DF9CULL, 
            0x41B8E468B01D8E25ULL, 0xC328AB1B1267F765ULL, 0xC86A8D9FB1446F54ULL, 0xBF5F0AEF5CBF1AAAULL, 
            0x33990DDEB14D3779ULL, 0xFE75BE653662DF0BULL, 0x478A39030E2B6902ULL, 0xCC04D0487B3CFB4FULL, 
            0x0BE32C5C18D514EDULL, 0xBB3A71817F275CA2ULL, 0xEBA57B29FCF17CDEULL, 0xC45091AAA02D3270ULL, 
            0xF146D81BD6F1524CULL, 0x567766144F558A11ULL, 0x534EF602608A9260ULL, 0xACB83A6C35CAF33EULL
        },
        {
            0x6F6DE5C3E9024523ULL, 0xBB506FFD2F9C0BE2ULL, 0x86D722119D431250ULL, 0x7D6049EF57538F0BULL, 
            0x0A645B321D4C6297ULL, 0xB9049EFA7EB0F3F3ULL, 0x6856307B63B8C069ULL, 0xA4579DE7857EA48CULL, 
            0x20FA6FF536F9D291ULL, 0xC1462F0098BBAF57ULL, 0xD9DB322685C295CCULL, 0xCB76D4CD235BA34BULL, 
            0x05D78A84808FCC87ULL, 0x472489EE5919A60CULL, 0x760DF490C98E4A72ULL, 0xACA7B5EB3F205883ULL, 
            0x4CBDA1F59FE80F5BULL, 0x5E7EFDC2CE671E0FULL, 0x2D2E08516080B398ULL, 0xFD56071FDA63F920ULL, 
            0xD6DCBAADE42A7482ULL, 0xB37DBFA874452213ULL, 0xDC64C9EAB3A50781ULL, 0x1BD8AD14849263A8ULL, 
            0x6B6D77CFB3608A60ULL, 0xA07172E2DA4E40A6ULL, 0x6885F2440791710DULL, 0x38879FEB18A84BF8ULL, 
            0xE911AAF293B92FEEULL, 0xE1D896BF3CF16945ULL, 0x305AB2EEB1BE8321ULL, 0x967269F898F372F8ULL
        },
        {
            0xED518A60AB568D93ULL, 0xD332F4B47C5D8B3AULL, 0xA4A465D630484358ULL, 0x5F547732832D907CULL, 
            0x66E18CB8E253B31DULL, 0xE400BA8FF9DCFF43ULL, 0x610090565674197AULL, 0x99D1F71F081DD088ULL, 
            0xF5801121620EFD06ULL, 0xA4157031E2931A90ULL, 0x9A8C222DE0EB369FULL, 0x1E4A2B5398342636ULL, 
            0x0E77C9FF9411118DULL, 0xED5F7A507FA4A0C5ULL, 0xE6E76EAD1E91C524ULL, 0xB2AED0AB11C1F406ULL, 
            0xEE1964D7E6C21931ULL, 0x1856BBCCF2BF9CFBULL, 0xFAB7F0881D06091FULL, 0xB1BAEB20D8241014ULL, 
            0x1428812B7832AA81ULL, 0xB69792AD6E7F0452ULL, 0x42299503C93D068AULL, 0xF73DA962DEC6FCC4ULL, 
            0xDF26BF9B0478DFF1ULL, 0x57AA7531E0CA5045ULL, 0xA5C95457F580976FULL, 0x19714FFA077456CAULL, 
            0x67FB099A2F635873ULL, 0x4538B75BEDE9CDB3ULL, 0x92C8A24005059E35ULL, 0x6193B6C34A17EDDBULL
        },
        {
            0xFCF5777056765898ULL, 0x7874AE934B7E1CFAULL, 0x10061BE53F65774FULL, 0x366284F0499FE075ULL, 
            0xF5FACB3EC42C0E61ULL, 0xFB9BFBAC826AA86FULL, 0x2CAD3AEC1057C75AULL, 0x935B26DD650DC84DULL, 
            0xE02DB067E7F4F7C7ULL, 0xB6F883E4E28084FBULL, 0x4465F3991CA5893CULL, 0x22D3F5E097594925ULL, 
            0x06845EC5A8B60030ULL, 0x9E44617ABBFD7B5AULL, 0x6B08D96E4CD39104ULL, 0xC4FCAD83A748D0F0ULL, 
            0x38B1B36DFCCDBF33ULL, 0x03BFFD93A0D71CE0ULL, 0xF9A6AF25A0914E3DULL, 0xBBDCE32D702468A8ULL, 
            0x919D8BA041C9150EULL, 0x5E1379123A18B22FULL, 0x549717632F74C38CULL, 0xC31A07CE108C4F67ULL, 
            0xAED9EDDAD4C98585ULL, 0xF59ACC0929F01026ULL, 0x5967402875ACED40ULL, 0x6301439959A9332AULL, 
            0x416B3B4ABF5E7266ULL, 0x0AF31FDE7ECA3103ULL, 0x3C6F438587AC44F5ULL, 0x31524CC15B90B974ULL
        },
        {
            0xC4B3D9B147FC6F19ULL, 0x2F58CB6476A2364CULL, 0x81BDABB728B6995BULL, 0x560A9F19DBCD12DBULL, 
            0x33F02169254F8B1CULL, 0xDA87643ED512C97EULL, 0x4CAD413DF52FA36BULL, 0xF82304B43939B7D3ULL, 
            0xA9FF95EDAA4CA508ULL, 0x4C3627395C2117F5ULL, 0xE197CE6F04519030ULL, 0x5DCBFBCD50286D28ULL, 
            0x8D8039F8E37A1859ULL, 0x2F28408822FEC260ULL, 0x01DB1B73B2E3F65BULL, 0x6C70FFBBD4631C82ULL, 
            0xF6B744CF39A8C155ULL, 0xF4D4EC949F847E8DULL, 0x0C17E46021AE4367ULL, 0xE4B5E8694C67D6ACULL, 
            0xAD4889EAF45E27C1ULL, 0xD2EE246BD61B79E0ULL, 0x7D04388BD2F2D948ULL, 0x2D5A4FBFD0D76DB5ULL, 
            0x22331338F667A410ULL, 0xA202C2DDEE9F02BCULL, 0x85F33101A5843ADEULL, 0x000FA42C11061F56ULL, 
            0xAFBC19FB13084D21ULL, 0xDCD28471FF6BB06BULL, 0x73FF4EE939D63090ULL, 0xB21F683F724333D7ULL
        }
    },
    {
        {
            0xF0152FC013D274DCULL, 0x1A536BC1CC8D7CCEULL, 0x307E438070350EEBULL, 0x770C5D4D65E61BF7ULL, 
            0xB9915B52E0A0F068ULL, 0x15956DB6391BC8BEULL, 0x482D9D80F80DDF62ULL, 0x9FAA5D5B31005CCCULL, 
            0x2261AC3D02BFDDC0ULL, 0x1791B2E302645156ULL, 0x096C1E0D073C76CDULL, 0x06824452EA14464DULL, 
            0xBD3953150ED8C164ULL, 0xD47DE1CEFA07C8A4ULL, 0x0F5CFB4A2603D491ULL, 0x9464EE574337B80AULL, 
            0x36A20E00EC2D9667ULL, 0x4C1CFC1EBCD24FC6ULL, 0xA642485E0F042FABULL, 0x1BCEA53312480561ULL, 
            0x371A37326B5C8216ULL, 0x611AB82AE8FB5BB3ULL, 0xE171FE7CBD0EA73EULL, 0x09D1FAA9A8E8B7F9ULL, 
            0xDE98D60FEE37CC85ULL, 0x2D88A45B8698498DULL, 0xACE127F9E29A2F7BULL, 0x4BE9C7D6004E085CULL, 
            0x54A8CDE9E73122E1ULL, 0xCDE6773433ADC9E3ULL, 0x28748AD4B65A8269ULL, 0x609871799F6F5248ULL
        },
        {
            0xE13A5E576B927D89ULL, 0x81C96C0644EDAD36ULL, 0x4AA9F904D16279A6ULL, 0x0CA3E552D80B0641ULL, 
            0xB65D8D7B4099D174ULL, 0x13DA5604DFE02317ULL, 0x90125E333E92750DULL, 0xE49FD7B5F8B08D0CULL, 
            0x67AC4663021EB1ABULL, 0x033E12A539E9076FULL, 0x4B711CF1835271B7ULL, 0x33279A2FC50D3073ULL, 
            0xEF4BB181704C19D8ULL, 0x56BBC38A750AA6E3ULL, 0xFD35DC7D553B56EFULL, 0xDE5263C1D001404AULL, 
            0x432BBC3AC8C95244ULL, 0xA1E56005BB98C27DULL, 0x777477D4613104B6ULL, 0x01242D16C2742B91ULL, 
            0x1CF80B96CC4D2CE5ULL, 0xB565BC597F6A70D2ULL, 0xA047B33F1FF75162ULL, 0x61B9E5DF22027B10ULL, 
            0xA30C1392FD576A82ULL, 0xA45529F2CD862E70ULL, 0x7F6284ED5010359DULL, 0xF180617A5E2B331CULL, 
            0x7DB2C95BF13ACE39ULL, 0x9DD68005B64CE56FULL, 0x20DC40F36EAFCB96ULL, 0xF7C1E5856BC898ADULL
        },
        {
            0x89B471C93B67E125ULL, 0xDBE0A4708C53532BULL, 0xDD1EA4D8FBE2F915ULL, 0x75EE7A0D4660DF93ULL, 
            0x35241D7EE483CC94ULL, 0x4CE1F580B0CCEE5FULL, 0x835EB17CEEF245F3ULL, 0xBF6EB446AF266E3DULL, 
            0x5ECC00175D94B092ULL, 0x1ECB96D5FCBCECFEULL, 0xFDFD48ABD6ECD664ULL, 0x9011D681D1E68F0EULL, 
            0x0472CAF0820450C7ULL, 0xF16C2B07DCF45C15ULL, 0xF030812C59C9B15DULL, 0x02365DFF8C2897C2ULL, 
            0x2C8B8B0C27580E2BULL, 0x24F75AA60C4986C6ULL, 0x78D702311034CFB8ULL, 0xD0094847AE7A7CE4ULL, 
            0x804D52C62AAE8B0EULL, 0xAC88DC9395BDAFDAULL, 0x39A6483D5E232CFFULL, 0xF9D4AB645D5ABF45ULL, 
            0xA18EDE843CF71768ULL, 0xAD263DDD4A799AC6ULL, 0x127CFDB4AE44F49CULL, 0x905A9CB2063EF010ULL, 
            0x77532DE07E2E6B9BULL, 0x47F75093C6148146ULL, 0x83D88607A95E3610ULL, 0x2DF3B1967595BBB8ULL
        },
        {
            0x2E8A68370267446FULL, 0x1B04E09F6E99E0CBULL, 0xA3D94260EC5ACF41ULL, 0x245EE6119471478CULL, 
            0x1DDE0046B29E9A09ULL, 0x8A1ABDDC306B9CDDULL, 0x1D6CB68AAC4D7443ULL, 0x9BB22C59CC8E5358ULL, 
            0xD225FCCADEBAD91AULL, 0xE591141B34B2EBFFULL, 0xE0E4E61F7A0A436EULL, 0x4936AD11FAFF397EULL, 
            0x5A6BD1A66820A1DCULL, 0xB09511BC6FC91428ULL, 0xD85914CDCE5FF57BULL, 0xA3400403505B346AULL, 
            0xD22F577C5D88EF65ULL, 0x793163F68A32CB39ULL, 0x03E66AA569EFA944ULL, 0x06D27F3FDAAC3833ULL, 
            0x5395FA3439FB43FCULL, 0x898FFC39DBE70DA8ULL, 0xFC47A2C6A0343405ULL, 0xA8BD33977457FA35ULL, 
            0xBEBDCBA67A3B85DDULL, 0x5EB8442A84080F95ULL, 0x9F95438360DE0F10ULL, 0x8265B7B2DCECE185ULL, 
            0x46351CE1487D5CC5ULL, 0xB9648AD79F7B06B5ULL, 0x87BB1CB240CA3BA4ULL, 0x9C75A2D5097E7D2DULL
        },
        {
            0xF500E4BDC5C39FEDULL, 0x06F02E63A987BEDEULL, 0x56441BFDB93700A5ULL, 0xDE51C7AB5E235F7BULL, 
            0x42BED0572512D70DULL, 0x7822AF1E8861C606ULL, 0x67780DA1A76829E7ULL, 0x0948AC210E261FEDULL, 
            0xD6A7FB844CC22919ULL, 0x23B7E0109B5B7379ULL, 0x47EF40112652E9D0ULL, 0x361A1E244E896616ULL, 
            0xC8E4796D329C5BF9ULL, 0x52D71E546D622006ULL, 0x718025F243DA9E7BULL, 0x9F6B55E03747C29BULL, 
            0xCB5226D56F311935ULL, 0xE38E5AFEDE030E35ULL, 0x6F978F572A612406ULL, 0x7998B52E62E3893CULL, 
            0x8F5702B55AE5402AULL, 0x43AEF5C488EF80E5ULL, 0xDFED68979339EC87ULL, 0xBD206324F240DB69ULL, 
            0xD550663222AE56CBULL, 0x7CE5BD753EE9B047ULL, 0x66559913809B537AULL, 0x0FB0514362DBE826ULL, 
            0xBC5C18F72A255683ULL, 0x46BD2AAB16C156F6ULL, 0xB2E1D42A8471171DULL, 0x8E97B70311033108ULL
        },
        {
            0x804DC93F8C4AB13FULL, 0xA57BCD9BF69FBB84ULL, 0x6CD3220DA3593D61ULL, 0x216134DA367C7A8BULL, 
            0xFA9FAAE75F3D0707ULL, 0xFC5909E23F0A1629ULL, 0xC4CC7CF0C99FF24CULL, 0xF3E8DF3D6015C04BULL, 
            0x5009A9A834792E40ULL, 0x120D7B3C4727B190ULL, 0x9F153E2667C3E109ULL, 0x38E01ED1EE5C847BULL, 
            0x58604AA9D825AF36ULL, 0xC68433F77E724EE1ULL, 0xBABA4EE02200B60FULL, 0xC134A4934D88A49DULL, 
            0x48AAB29034B9C942ULL, 0x1ACF558F958C1865ULL, 0xDED128465C3137D1ULL, 0x1C72D709B08618C7ULL, 
            0x31E127937C61936AULL, 0xB18AAEA5060C6B7CULL, 0xF8888F35E1196D70ULL, 0xBCE79F6833B5DCD4ULL, 
            0x14E4AC1FDDE41838ULL, 0x81E4EC3553337700ULL, 0x16796967BEAF016AULL, 0x8F436325CFF170ECULL, 
            0xF14E37EBD6D1DC07ULL, 0xE65370F10E9DCC67ULL, 0x5616C1480DC538D8ULL, 0x8EA81B680EC8A9F9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseAConstants = {
    0x9AC4C845BB026BC0ULL,
    0x0F74742913FB756EULL,
    0x4A2607EEBD77931BULL,
    0x9AC4C845BB026BC0ULL,
    0x0F74742913FB756EULL,
    0x4A2607EEBD77931BULL,
    0xEBF8803622A3ADB5ULL,
    0x0DA4F2B987B5A134ULL,
    0x61,
    0xE8,
    0x26,
    0xAC,
    0x37,
    0xFB,
    0xAA,
    0x0F
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseBSalts = {
    {
        {
            0x9F99B33AE6F0DDEBULL, 0x66952707441C514EULL, 0xD1867C60DA71E99CULL, 0x9084319E0C93F03EULL, 
            0xCBEB46F3C3806435ULL, 0x5D2BD27613563AF9ULL, 0x455486E059F1EB48ULL, 0x92CB55E9E79AB3F5ULL, 
            0x570E8AF639AAD170ULL, 0x530E2A104D701149ULL, 0x225D11D557439F4FULL, 0x1A9867A8D2EBE938ULL, 
            0x93D40DADA82FC359ULL, 0x099E9CF0726B5989ULL, 0xCBA33B89E062B897ULL, 0x9D69692F4613E23FULL, 
            0x007E53986EF33DB4ULL, 0xF08C7B5561C376F4ULL, 0xD45B065F903809D0ULL, 0x0C97525FF8D67FA1ULL, 
            0x895D3995F5320283ULL, 0x2675FAC8AF77BEF8ULL, 0x3DD8C54F983D784CULL, 0x904CCE0D5CEB71DDULL, 
            0xC9C13EB745AF5E86ULL, 0xE19D4C2F0DB6DF35ULL, 0x197AA8C5DE7E051AULL, 0x393C0A4B39870C1FULL, 
            0x182837F84B51FF70ULL, 0xFE3704618632321BULL, 0x475334CBCEA62F1EULL, 0xFF2295667DDD8EE9ULL
        },
        {
            0x24FB4E8EEE373AF5ULL, 0x00D03CE5E57E4E6DULL, 0xE6D830E921E380A1ULL, 0x9848ED84B9DB2911ULL, 
            0x12D3F2D8105835B4ULL, 0x32D10FDA267439B9ULL, 0x42858C1B15F864F7ULL, 0xAF64D2A382AE4D2CULL, 
            0x64461DE20D49946DULL, 0x36A69079DB33F6A3ULL, 0x33185F53B73C94DFULL, 0x6C98F55F4D7C3932ULL, 
            0xD981F57A32B53786ULL, 0x7646E8074839E27BULL, 0xA30EEF6AF4C4AD39ULL, 0x4E381025A0956C03ULL, 
            0x7BD217C9D3C03CC0ULL, 0x359DF66C6782C343ULL, 0x9A01D0D4642DB2B1ULL, 0x6EE1DA1742EC12BDULL, 
            0xA9C6DA1D0773FDC7ULL, 0xFF31DEE16F288269ULL, 0xF36CA3C1FEA51C42ULL, 0x139EAC317424E13AULL, 
            0x01BC2160BFE8FB9DULL, 0x1AC909A6DB052E3CULL, 0x93326CE21BDB2F84ULL, 0x268797CF3AA44445ULL, 
            0x8048CD7232AD8A57ULL, 0x0448D320F381BB49ULL, 0x60EB67FB9E5660EEULL, 0x97FD0AD7F674C224ULL
        },
        {
            0xEEA1B1C9FFA28B5AULL, 0x365F8BDF171B4E56ULL, 0x8D1F69DF045D43EBULL, 0xA1C0122AFB2CB7EDULL, 
            0x01BE9F2C7C7AB006ULL, 0xEFB1F3FC54B3B88CULL, 0x7C0AA7A2E0E4AB2BULL, 0xF6FE0C6B71FCCC6FULL, 
            0xF2875C6D8CF9BDD9ULL, 0x7E250F280CC3BC23ULL, 0x1932427665DE2EC9ULL, 0x61067E803A8A04F0ULL, 
            0xEDC28BF1520B97BAULL, 0xD8EE02F0E3B524A0ULL, 0x94623BEEFC2D3C03ULL, 0x0CDBC85FDD332EE1ULL, 
            0x68D9255D3F77F657ULL, 0x2AD649B7588FD3C9ULL, 0xBE4485EC16475D2DULL, 0x8725252BF3580272ULL, 
            0x42598677F8F1B549ULL, 0xD4CF28AEB1A7EE05ULL, 0xEB93F79B8FCBD410ULL, 0x63809563DD38FBE2ULL, 
            0xE9590E1808A91984ULL, 0x9C11F74318E81297ULL, 0x1EA55CF04FCFE623ULL, 0x483578EFB79A05A6ULL, 
            0x53D8FEF1B85C523DULL, 0xB58DA77FF76F6327ULL, 0xAF6CF43D88A4C177ULL, 0x56B07973F769699EULL
        },
        {
            0x9518D3A4C984EC31ULL, 0x3F021306165ADEA7ULL, 0x3F84FE8B420FC295ULL, 0x50F85F602FABBED5ULL, 
            0xD72FA1366DBA7CB0ULL, 0x796DBCE994C2FF86ULL, 0x1EA5CC5FD74F1F9DULL, 0x566716978BEA19CDULL, 
            0x65FBFB04005AD1E7ULL, 0xEB686AB3C8AEF95CULL, 0x2000498872DF04F9ULL, 0x65E8E31F8A00150CULL, 
            0x4C15B3EF0C41DC7EULL, 0x511639EC290E1BA4ULL, 0xECB610EC2343876FULL, 0x8B6833C8828AF53FULL, 
            0x1C866AD9CFB225A6ULL, 0x266E5827DFC87C7FULL, 0xF6D7BE3257D79E89ULL, 0x83C8FF4FF3D1EBDFULL, 
            0x76DC47EB5DB1AB5FULL, 0xEAB283547E6701A9ULL, 0x0045C9DEDBA7C178ULL, 0xCFF74E835A07B147ULL, 
            0xFF2CD663CC6E39C8ULL, 0xF5A371F5CC6131F5ULL, 0x521C3EFF27CF246FULL, 0xDD10544D2DB3E6C2ULL, 
            0x7A6065AE3E660A81ULL, 0x20C7ABF6DAA17DC0ULL, 0x49023165D8DF8F6FULL, 0xA3FAFE4FD08320F4ULL
        },
        {
            0x4CF7D4C7B4A9DFA4ULL, 0x7F5719AED038F120ULL, 0xBCD1AE9D792E1AACULL, 0xCEBD1542D522D693ULL, 
            0xFAE3964EA65E4B44ULL, 0x1BC2A755F7D9C093ULL, 0x20AF24FF3E076557ULL, 0xE5CDC9C3BF36108FULL, 
            0x5360035A24E19F98ULL, 0x98F7F7586BFB99C9ULL, 0xF40FF9ED95BF9FD0ULL, 0x04372DB4A051705BULL, 
            0xC43C11B2CEC80FABULL, 0x2A2121F174E70C7EULL, 0x458A69A3C09A94AFULL, 0xE738CB5440EB00AFULL, 
            0xBBE265A115D3E3D9ULL, 0xA5C020E9906253EFULL, 0x53005D9BF844DFC3ULL, 0x39AB98661ED7818AULL, 
            0x2F9F878313BC0CD9ULL, 0xCBC0098310C32F27ULL, 0x534891767B7E0158ULL, 0x5D4B1394CA7C6B14ULL, 
            0x86D7CEE35B1C92C8ULL, 0x11B1818C14AA09DDULL, 0x3FC3D7D111651794ULL, 0x3FBB8CC16DBFDD4DULL, 
            0x1C865DA230CE8BE8ULL, 0xB3817062964D21B1ULL, 0x420AD20F72902F0CULL, 0x76B253271B555D29ULL
        },
        {
            0x07C490C6852A66AAULL, 0xAE6C9237B2B1AF74ULL, 0x73C9FC15C03FDE80ULL, 0xC641A44D40A4B284ULL, 
            0xB79CD00C499ED69FULL, 0xBA46A0B63D8013FCULL, 0xB7FD606554C99350ULL, 0xA741D8A33F45D6E0ULL, 
            0x928AC70BE1F174B5ULL, 0xA64B4126E79531B9ULL, 0x2B69B3B4ECFECC99ULL, 0x6B02918FF95FB1E1ULL, 
            0xD48D20F6929DB8CCULL, 0x458C7145F978D59DULL, 0x190E0A026CFA04FFULL, 0xB76B3164C26A13D8ULL, 
            0xE6773176BAC6CAF5ULL, 0x0C2CB4324580C839ULL, 0x32D9D46EE1D987FAULL, 0xB72E9E7DA77F0D89ULL, 
            0x46BF82AB1A4AEAACULL, 0x083B3248219CFAE7ULL, 0xCC41FC4FA8CF572DULL, 0xA26AE917FAC7CF63ULL, 
            0x8FDA7CCF8BE9CDC3ULL, 0x9BE9F318D120CA99ULL, 0x4EE77C39712E5066ULL, 0x4B05999C59094EC0ULL, 
            0xF9FDF4908689A416ULL, 0x9AB12F72380C5E6EULL, 0x2A48F53B52F53720ULL, 0xA9A8A01855DA2FA0ULL
        }
    },
    {
        {
            0x67D8C2897D6864E1ULL, 0xB55D07A6A205BDE7ULL, 0x4FF915F71E5783D8ULL, 0xE232C1088081DECDULL, 
            0xEBDCEA30ADCDA43BULL, 0xE2428C62A157C6A9ULL, 0x48DEC179C89B4F25ULL, 0x43A9ACD62D53E056ULL, 
            0x2A5065488D810446ULL, 0xC6BB802BC9583338ULL, 0x5A0C0AC08C99B989ULL, 0x01CE81E01810D386ULL, 
            0xC9263E8C8C615816ULL, 0xEC9B176A78D2C193ULL, 0xD5940C4B2BBF8146ULL, 0xE47FD02F7D5718FAULL, 
            0x5C7114399AE94B56ULL, 0x206B79951B0AAFCBULL, 0x4944A5794430F9E9ULL, 0x277E9DC08CF17E92ULL, 
            0xC5F9B4714BE3D7A3ULL, 0x030999383684548FULL, 0x0E6D322E5DA29BE7ULL, 0x72AEBEA47C47FD5BULL, 
            0x1BB9C5A37E3FFB50ULL, 0xE783EE2D8C841E0AULL, 0x10C2E652EF3A8ABFULL, 0x36566F5D0B9FFF28ULL, 
            0xC8E6D83142243A24ULL, 0x42BCC5CD9D45BCD3ULL, 0xD80D741D9BF5FF38ULL, 0xA5CF7FE45293E38BULL
        },
        {
            0xE5F3C72FF19DA266ULL, 0x0F5CA4A4C17ADC57ULL, 0x1749ED923ECB165BULL, 0xA8EFA0CCEE8CB69CULL, 
            0x12CE49977FAB7E8CULL, 0xFF9BCCB59E3985B7ULL, 0xF8CF06A0BF7D3CFFULL, 0x06CA9B29EC78F839ULL, 
            0x0D83303D5E6BFCAAULL, 0x24C8D8465F51EDA4ULL, 0x91BA3107D5F2FF9BULL, 0xC52BB126FA8D115CULL, 
            0x46555FF763E8B705ULL, 0xB793BDA4C7963E55ULL, 0x3E63EF127FCEF834ULL, 0xF6FE62525872DCA7ULL, 
            0x1931B2D555B1288CULL, 0xBFC9F0F79ED932A0ULL, 0x61295D1C99BAF2A1ULL, 0x3233482BD00A824DULL, 
            0xC7F2A0049F44F295ULL, 0x8438F1B553CAE410ULL, 0x6E3197818EE1BBCEULL, 0xFDAB39DDF01383AFULL, 
            0x1DA88765D15211CDULL, 0x55AB065899E7348CULL, 0x9BCCAEA23FABA940ULL, 0xEBA0AD5718087B69ULL, 
            0x425AE500CA17CC8DULL, 0x1A4CAF4A18ABA209ULL, 0x986D6545657E1F10ULL, 0xDA87C885FAB239A5ULL
        },
        {
            0x1458A536752C6013ULL, 0x169B4E802BB3212AULL, 0xE5E118FA4EC5FA25ULL, 0xEF84C94C21BBE5A6ULL, 
            0x4E17FF596F89297CULL, 0xFF586FBBC2804E0FULL, 0x3151DBCB20C5E01FULL, 0xE4C1CB1013F76472ULL, 
            0xE44EDD5CEC336CDCULL, 0xC0155A6CB6E30AAAULL, 0xABFEE4E2208D1AAEULL, 0xB6CBED817D45117CULL, 
            0x7E1D627E009D40A1ULL, 0x20FFBC78D2E3D802ULL, 0x1D3979CF6867CCE3ULL, 0xD20018ABE2C00000ULL, 
            0x8D2B37BAD34E8CF8ULL, 0xD5A61467AC7204C1ULL, 0x61680B76EE02718DULL, 0x65BD7DEC9F42E295ULL, 
            0xBF795A33A409ADA9ULL, 0x3CC105C36A4001FEULL, 0xB7E13E860A1C59E0ULL, 0x8F51D6A84EB7F060ULL, 
            0xD6F8CD460458D1EFULL, 0xA4EFD659DCBEB3F0ULL, 0x0E02AE9B96A242EEULL, 0xCD7B09E76AE0B4B5ULL, 
            0x9DF38B97D11E2DCAULL, 0xB57E6AA916DB9F4DULL, 0x51120E473D36F9D9ULL, 0xD89A3553B7C281C7ULL
        },
        {
            0xD0D90C19D6450E38ULL, 0x63D6946208D4747EULL, 0x3319D96AF36B45EAULL, 0x6F3E8580E67BF182ULL, 
            0x66FAD3AEBE571649ULL, 0x3EC2D946C0550462ULL, 0x7D882C4C83D1B6BBULL, 0xEF27CF7397D3CFB3ULL, 
            0x57A36E7A71FCBA14ULL, 0x54C813F6CDBD2160ULL, 0x30BD26BEA7101E1CULL, 0x126F08242DF2F6EDULL, 
            0xDF4C055F192054D1ULL, 0xC65D49DBE7F5E79FULL, 0x8A087C3FAFD9ED45ULL, 0x2076BDB062039E1FULL, 
            0x45298799D6E39363ULL, 0x5DF300FA0BF09CFAULL, 0x99EC73262AF6C4EBULL, 0x2BFC44C65B297C61ULL, 
            0x9CF7FFA20C1F47FAULL, 0xD704648ABAC5C030ULL, 0x0D5AA42BADB92474ULL, 0x74FD2841FB045E2AULL, 
            0xE7201E7E540650EDULL, 0x13F57F44DD615BA0ULL, 0xCB5785EE4989BBD3ULL, 0xF25165B82CC482FAULL, 
            0xAF540B366A29F364ULL, 0x0325340495DAFEDFULL, 0x46022197D949148EULL, 0x08BEBD7E64982135ULL
        },
        {
            0x45FD434C56B32B44ULL, 0x4E0ED1BCA8E07D36ULL, 0x779535F0BF895DE9ULL, 0x028582CF0FB0CEF9ULL, 
            0xE6268C4EF990C615ULL, 0x5B10F360C8BFBDA9ULL, 0x0BE5727E9AE2615EULL, 0x02AF4DE0DCDD4622ULL, 
            0xBCFF850566DD4893ULL, 0x7D24C40DAE792BB8ULL, 0xCF1DB4D3A547944AULL, 0xC219357D8108BFF4ULL, 
            0x3FBF3D6902B7A29FULL, 0x5BF2D5A517045EF2ULL, 0x9BEE3F18E79C15DDULL, 0xF4D70E4EE1E8B529ULL, 
            0x1C821ABED54D635BULL, 0x82EF68C728966B91ULL, 0xD5358C1A15F46049ULL, 0x1409313885645787ULL, 
            0x5B66D2D9F81E586EULL, 0x3101C43C6ACBD046ULL, 0x95D604F397E3877BULL, 0x1063FF6034494C25ULL, 
            0x95DFC552D7B7AEE9ULL, 0x6E9CAB3AFE3DD9AFULL, 0x37E02066E6648641ULL, 0x97674145A92A9A37ULL, 
            0xC4D70E1BC5AB5BCAULL, 0xA666A99C0016037CULL, 0x1C16034312A8771EULL, 0x35E9C43A99020680ULL
        },
        {
            0xC83DB2DF1C11430FULL, 0xA8A89AB1B46EADA1ULL, 0x2A05FFB5F918834CULL, 0x671D751061B332A8ULL, 
            0x4380FB8E25A88E61ULL, 0x62D8966717EDD25BULL, 0xD229EC5E679DBB74ULL, 0x15EFA67597A139EDULL, 
            0x614E448293861A8FULL, 0x557128E4C0E3AA53ULL, 0xFF15BCC02BA86ADDULL, 0x9A52FCFE1BA0DEF4ULL, 
            0x4E0BB13EB01FD4E7ULL, 0xD9AC10D01E06076CULL, 0xB2E952B0C3FB40B1ULL, 0x42992544CADE66CEULL, 
            0xE0BF3750ECEF202EULL, 0xCC84B24CBB360DBAULL, 0xAC9FBFFA04E21D5AULL, 0x89C874BEED50D8FDULL, 
            0x5A61BFEDB66576CEULL, 0xB4A7DB214A5906D0ULL, 0xDF18D277A3941D4BULL, 0xE48C1B01901DEA05ULL, 
            0x951ADEACD521FA75ULL, 0x43B50983540DD885ULL, 0x9BA09AA1E6E19D59ULL, 0x6A473DAFC690A4D5ULL, 
            0xFB8E66DBC137C5A8ULL, 0x8F614D70ADFC0BAAULL, 0x10E364F2CA540973ULL, 0xB148547D61DBAF52ULL
        }
    },
    {
        {
            0xCDFFC0D1082E8C59ULL, 0x3A3A323C3E8F940BULL, 0x1C61155D11D57673ULL, 0x7DD5A77E5DEE24EBULL, 
            0xC6DE4B0C0819A91AULL, 0xA0E0E17A3C9EEA13ULL, 0x99C3511BBF32772BULL, 0xEEC0318C91D499EBULL, 
            0x75703A4A9F25DE45ULL, 0x0F03777E54C81DB3ULL, 0xCDC3F80D856042FAULL, 0xAF60DE8B31FDFBDBULL, 
            0xDAB4CA6B84471095ULL, 0xEEA4A4489E1BAF58ULL, 0xFC19CAA5F5F3B90CULL, 0xDBB091F7EFBCAA2AULL, 
            0xA1F2F123C8E1073AULL, 0xD831985DC747895CULL, 0x8FC6DEC7773E4A54ULL, 0xFFCEF1FC072903D3ULL, 
            0x6048D0BCDF6C2CE7ULL, 0x659AC40222CA6327ULL, 0xCE31B8BAFC2A3E92ULL, 0x7FDBFFBFBA618878ULL, 
            0xC45E7177C6508E8BULL, 0xC54862C89525969DULL, 0xACADF3050431C5D2ULL, 0x2369DC271C30B7C8ULL, 
            0x2770C19EE32A9D5AULL, 0x0EAEA381D8D4CC63ULL, 0x58E6204162565B67ULL, 0x661EC2A6F90800CEULL
        },
        {
            0xC959DD1727D0C9EDULL, 0x0F3E70DC87CC3809ULL, 0x1DD14EDC95D6079BULL, 0xD630CCDF578AAA72ULL, 
            0x304356BAAF9BBE54ULL, 0x778CD33C87ABEB10ULL, 0x50331AF88D68524DULL, 0xEDD31C15D7EC60EBULL, 
            0x221BF5C8BA8FA34BULL, 0x5055F9C89B353438ULL, 0x12822E2D777AA2EAULL, 0x0AFDDDEAC70B6DC5ULL, 
            0x764F2351FB33C85EULL, 0xAEDB1F7BD38D5667ULL, 0xB07FA575DCB52FCCULL, 0x7D52ED2ED98AE639ULL, 
            0xA07489A3F45193B8ULL, 0x828819E680A09EBBULL, 0x76D7D2465B0A7B8BULL, 0x07D7B8E7EDEFD0A0ULL, 
            0xCA923307368A5808ULL, 0x157D5379A38EC342ULL, 0x302314E9E7DD0305ULL, 0x0968AE63328C3C46ULL, 
            0x05FB0FB202F53D31ULL, 0x67240302A5BB11DDULL, 0x655353590DFDE652ULL, 0xA053A381E7C7E2AAULL, 
            0x115C324770CC82AEULL, 0xCBE48606B2B33B6EULL, 0x7D4AEB5349B9506FULL, 0xE2F54515EDD8AEA3ULL
        },
        {
            0x43142F385D7E6049ULL, 0xDA88DF892528AFFEULL, 0x14E40A075423CA67ULL, 0x501177C1A62C4411ULL, 
            0xAB03122F2E83DE19ULL, 0x5015ECDC1CF36FBFULL, 0x2A99BDBD55D5D652ULL, 0x83125A72BE6B6406ULL, 
            0x894FC898D2EBA391ULL, 0x64AB6E6F680BF9FFULL, 0xC8975CE1393BF871ULL, 0x993C8DFF9B1E019CULL, 
            0xE2CD10B76E9AD559ULL, 0x2C23EAB89DA4543CULL, 0xA36B99C7273D53F2ULL, 0x72DD1DE1B6F837BBULL, 
            0xD3E96DC9CFA94C02ULL, 0x7F43BDE397082077ULL, 0x325781122679C2B4ULL, 0x3A3ACCFD1AF2ACA9ULL, 
            0x3FE88F852541FE77ULL, 0x57011E723D71793CULL, 0x8646C280F7A1C00AULL, 0xE54C84239D16477EULL, 
            0x23ACD830F86A4A07ULL, 0xE23B8B3BF27F5BAEULL, 0x9E1F7AD983A8A0E6ULL, 0x4B2C842916D56BCDULL, 
            0x8238AA87E9411F6BULL, 0xB9C6B6C7A42583DCULL, 0x5A398E90E20409EBULL, 0x3CF1F5E89F47F01EULL
        },
        {
            0x3DC1B9DAE9BCB3C4ULL, 0x82E5389876BA7814ULL, 0xA91CD49A83260612ULL, 0x2B71FDBAEE9AD856ULL, 
            0xAFCDB7984F8AD9AFULL, 0x4EE09CC8ACCF654CULL, 0x1AC6E93022987800ULL, 0x2DC42FC7C60DBA48ULL, 
            0xAFBB1C2EC8260C62ULL, 0x0AA64E1A4F8AB36EULL, 0x7E7A45ACC416EEC9ULL, 0x48259CE7DA4F2970ULL, 
            0xB5EF39A307BEC6F0ULL, 0x417DF9188827FDAAULL, 0x3FCBFD64A8F9E6DDULL, 0x42AFD802DF83C43EULL, 
            0xAE903EB69751A279ULL, 0x411D3C8B709A1C41ULL, 0x09C8B784B4F7DD68ULL, 0x65C13FBCF2B84EA7ULL, 
            0xA68C6A179492877DULL, 0xC0CD68594C40C3E5ULL, 0x3C19B46EC98A224AULL, 0xEA44A6248CA585AAULL, 
            0x1EE8873DFBC092A5ULL, 0xA6E2DC0BE41E867AULL, 0xBBFC48F055B3D87FULL, 0x9C1031B96CDBE395ULL, 
            0xDA5432118F8E545FULL, 0xA29F43915D48BD37ULL, 0x0F9E3645EAD843AEULL, 0xD44B022D92FFA7F2ULL
        },
        {
            0x968F60C652118D1FULL, 0xC5233CCDE36D2A0AULL, 0xA8AFB5C03CF8E877ULL, 0x33BD48980B693878ULL, 
            0x4B301AACB65E917CULL, 0xD39ED6EFA1DC1090ULL, 0x07359DC50AF9B8BEULL, 0x45D9CB2C0E3D94FFULL, 
            0xAF8842645A824F74ULL, 0x380611711EB6FC09ULL, 0x22372BF9DF63BA45ULL, 0xF61AFC09A8283FE1ULL, 
            0xC632A27EEE5E1675ULL, 0x10EBF548FE2A47E3ULL, 0x8F145CC614EF1BE7ULL, 0x55363B76CC2FEB46ULL, 
            0xD0C44ABB9BD26662ULL, 0x569BBCD958F1BB1FULL, 0xF7B5842C492385A7ULL, 0x85AF281FE2F4BBEDULL, 
            0xEBE49981D351EE82ULL, 0x2834547295584136ULL, 0x3041FD1BC28C1C8BULL, 0x0D141137147088ECULL, 
            0x7D7742FD04FE1DB3ULL, 0xEBB75D2F09F66AA6ULL, 0xE3949CC0E1A8E076ULL, 0x1EC5968CB099A700ULL, 
            0xFE8A97CEE887B608ULL, 0x708A22E6A81892BBULL, 0x4F9B814161A6FF8BULL, 0x4B6AD69883FE4862ULL
        },
        {
            0x7ECE9120924C5D5FULL, 0x86A2AE1823BAEA21ULL, 0x8F224F9FEB0559DCULL, 0x52436EE99B67DD77ULL, 
            0xD39AC41A998CC309ULL, 0x9AB4A6B8359A75A5ULL, 0xC261DC310BD8A663ULL, 0xB81C7B9E867BC572ULL, 
            0x56313319029C10ADULL, 0x33BD13A2E5EAAFE9ULL, 0xDC81A3861B53EF38ULL, 0x8E9308A3FB8E2EFCULL, 
            0xC20CC72E0FD1DF24ULL, 0xBAF202D85F90EB29ULL, 0x4A61212D37526DB5ULL, 0x60E2CB2F5462C5C2ULL, 
            0xBF93F3849A37A064ULL, 0xC0C1738AE2D277EBULL, 0xCB4B790A2694555DULL, 0x7FE5BA92693F35EEULL, 
            0x9B357F4EC1B853EEULL, 0xF3FE5A2CFC482BCEULL, 0xD45B4B95FA0843E8ULL, 0xB780D6BFFADE0DCBULL, 
            0x2B43AC5A3195EECDULL, 0x9C33C0F1CFCC8E98ULL, 0xB788092542FDEF24ULL, 0x47708A3AA43E8B91ULL, 
            0xB61487D93B0F6767ULL, 0xC2C1D229494C350CULL, 0x394BAD47980C6720ULL, 0x57ABCEC8ED3CFE0FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseBConstants = {
    0x436BF7DEAE804D14ULL,
    0xDD2B836131F3C84EULL,
    0x716EA7077443803CULL,
    0x436BF7DEAE804D14ULL,
    0xDD2B836131F3C84EULL,
    0x716EA7077443803CULL,
    0xE38B45B05A080194ULL,
    0x4A785731AE8D836AULL,
    0x57,
    0x58,
    0xBC,
    0xA3,
    0x9B,
    0x6C,
    0x56,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseCSalts = {
    {
        {
            0xCF0DF2A5B36DE1B5ULL, 0x15CD48BFE6450EEBULL, 0x483F4F582CA5CD92ULL, 0xCCF2AC0655DE84E2ULL, 
            0xB814E2783AC4F885ULL, 0x8EE71649C287065AULL, 0xC04D9000DC28A284ULL, 0x4C2EA6C24D6CAD7DULL, 
            0x4FCB8BA53282214CULL, 0xB2FBE4BF5DEF1418ULL, 0x516C0EC16B1666C1ULL, 0x9DB0865A9772F28AULL, 
            0x63DADA82F68AF27AULL, 0xC18330FEEE71F94DULL, 0x6B3CEC9FE560C13BULL, 0xC39E4703F67F69ADULL, 
            0xC70312D395AEE93EULL, 0xFE42C7E69A51631FULL, 0x77826C637D7D79E8ULL, 0x9A22B8B05684046AULL, 
            0xFDFFDA9CBBA27D08ULL, 0x21F0446DDDCFAE37ULL, 0x0E70B678A9E87402ULL, 0xAF9A7F1F77FCC3A0ULL, 
            0xF60A20B7F5888467ULL, 0xE64A4C355664BEE5ULL, 0xD7066B5CA787596BULL, 0x91FDC6B89B57CC62ULL, 
            0x94D92A8D6B641858ULL, 0x5B3D40409AEBECF4ULL, 0x6608A9537A29828DULL, 0xD5A2B6AEA2E664E4ULL
        },
        {
            0x7F8F3DFE10A1F1FCULL, 0xF1F98D19EA5D6F32ULL, 0xE93DE430494EF324ULL, 0x2A237214D9096EBBULL, 
            0x954092C5A8F05BDFULL, 0x68F400EC1191BFE0ULL, 0x1C488B357FA05192ULL, 0x9C5DA1CFCAAD6589ULL, 
            0xCA1E0CE5F301C6A0ULL, 0xC617320685D7D2C9ULL, 0x09D8811D3F9ADD65ULL, 0x712B52B0A8D5866DULL, 
            0x4C2896069E833F4CULL, 0x57EB227C638B1187ULL, 0x8244B1488CC9226EULL, 0x964FF130ADF4DBBEULL, 
            0x2AC8BAD0411A680BULL, 0x4A754E00C53A5A15ULL, 0x89E3D02D8459DC34ULL, 0x5C787605AEA408BCULL, 
            0xCE0F5843ECCB1824ULL, 0xB76F69CB98E99248ULL, 0x572D76A7BB4DC28EULL, 0x6A9CA29B4D30AA80ULL, 
            0xDE0297665D330F3CULL, 0x3EA9C1B601CEDF51ULL, 0xFEDFD0B029755110ULL, 0xD7ADD3CBC138A008ULL, 
            0x5959618E72DDAC43ULL, 0xA2A1BFD408A7AADDULL, 0x37534C1CFD77F0C4ULL, 0x95931FDA25F2F9F0ULL
        },
        {
            0xD5AB579937836144ULL, 0x7CEB8269AFB20567ULL, 0x5296DF90635E3C0BULL, 0x37951D7EB58CC6C2ULL, 
            0x5B09F2A715D6D92AULL, 0x404796D39DF9C333ULL, 0x86345F2E7B0CACC5ULL, 0x9B7FFDB4F0D06510ULL, 
            0x31569FD9144F3D53ULL, 0x624A806558A7A3BEULL, 0x5B3F4A7AE83C86ECULL, 0x7ED03D3D8E6A3DCAULL, 
            0x77CDEA8C05F0E836ULL, 0x76B7F0BC77C8CB81ULL, 0x97F82DE12C78CBF1ULL, 0x54E15820E70E29F6ULL, 
            0x50028277116BFBF4ULL, 0x3908F793F0DA9207ULL, 0x8C1DF3A53462B05FULL, 0xA4AA0069C4E0A038ULL, 
            0xD8BD6324570A5B08ULL, 0xCAB42EFEFC60F428ULL, 0xED0A69202F7D3F6AULL, 0x76CE962E66F54297ULL, 
            0x5A640D4733FD1880ULL, 0x795C422BBDF2C008ULL, 0x4639A6FDDF06D6A6ULL, 0xE5D193431D1DD18EULL, 
            0x3B48BC60CE78BF7AULL, 0x04F675B0A6AE6629ULL, 0x1946496F779846BEULL, 0x4801C40FFCA7B531ULL
        },
        {
            0x28A985D9629850A5ULL, 0x4A25C2BAA37D1273ULL, 0xAE6D84276C9ED02FULL, 0x6A5005E25444ECEFULL, 
            0xCA93BA312F37AD15ULL, 0xDD54463912311F31ULL, 0x2D7623919B9F485BULL, 0x1F0AD7A0740C00CDULL, 
            0x24B42956959CC9ADULL, 0x27450D8909786354ULL, 0x3C898843B287763EULL, 0x20DCB46EDE3ECC4DULL, 
            0xB11E7361894FA67CULL, 0x71F41DF3D2355AF8ULL, 0x111B630BB552BD58ULL, 0x9297889B01413505ULL, 
            0x6C25BA85200CF9BCULL, 0xBE59E6626EAE0941ULL, 0x52DB2CC7CBF6FD4EULL, 0x5700DCE987886C16ULL, 
            0xC2241B6F5484DE65ULL, 0x8DFAE8CE2C8CA34CULL, 0xBBCB413149231BF7ULL, 0x89D470E9C8C5F5BBULL, 
            0xB0A9F993E7BD47CBULL, 0x0537CF0056A6321EULL, 0xFFABEF2CAB86F9F2ULL, 0x15946849379519ABULL, 
            0xF455D11207C379E9ULL, 0xA29751A0694EE1D7ULL, 0xBE727E324966FC87ULL, 0x96BE3367C9ABA996ULL
        },
        {
            0x0F532AF3EA035E36ULL, 0x00D35789A36F32C8ULL, 0x6A5380B80D1EF10CULL, 0xBD69073B929C67FAULL, 
            0xEC1B361E1D7C5122ULL, 0xC6E0E921E021A30BULL, 0xAA684992C6051FB7ULL, 0x80EA45CCF2CD6B7FULL, 
            0x0F799FB374B4C928ULL, 0x3BC595B30D007268ULL, 0xF319F8B1EB903876ULL, 0x263184927D52B3CEULL, 
            0x14EB696A36D97A4AULL, 0xE098996CEC5C03E6ULL, 0xB37355B63F1A5FA3ULL, 0x42FE748D53A409DAULL, 
            0x250A344875A4AD17ULL, 0xBC0F4A7E3DC2F323ULL, 0xFC0AFAFA193BCA51ULL, 0x0D73D64233A3E50AULL, 
            0x81DF03962061E6E5ULL, 0xBE7D2370E2F1CFE7ULL, 0xDEC32CABDF902390ULL, 0xAD693CA684E578ADULL, 
            0xECEB6599AFED43DEULL, 0xE873245ED655ECA9ULL, 0xF1C503E070373748ULL, 0xA47F5674AF78CD24ULL, 
            0xE803216F3F2FC108ULL, 0x3906FB4A76400508ULL, 0xA3CF2B6A84D78385ULL, 0xBAD177A35A2F4DFFULL
        },
        {
            0x0C0FD8253A024308ULL, 0xC754170294507DDBULL, 0x5C2AB8CA7D37ACB9ULL, 0xEEFACA47187FE9F6ULL, 
            0xC607A2BD66747674ULL, 0xD8836BB732E5FA0AULL, 0x4BEE1DB23AC68471ULL, 0x2206716D709A062BULL, 
            0x2B692C7AD745B227ULL, 0x51BDAD3785B0E57FULL, 0x69C40393A213F781ULL, 0x35EE8AE0C919E545ULL, 
            0x4594AAF162E0FBDDULL, 0x6BF7397AC7D6DD05ULL, 0x727563D98FC74546ULL, 0xE26D0950F4ED8B87ULL, 
            0x5806A6A3C3224948ULL, 0x5123D3450A670153ULL, 0x7FD45F9131D3FB82ULL, 0x023F41F8BB080411ULL, 
            0xE2D13F130A39EE32ULL, 0xE0623ED5BA899B18ULL, 0xB0DB4A939DBD1212ULL, 0x3213D7FF83E04DEDULL, 
            0xE349C03EB6AC6D2FULL, 0xD6E6E3601E470A13ULL, 0xAC8EF0242B0506C9ULL, 0xEE8EE992AF82329FULL, 
            0x382DAF7893B3A192ULL, 0x8413EEEFAB6021A4ULL, 0x1F1BC670A7C71215ULL, 0x25C556C9E278F1CCULL
        }
    },
    {
        {
            0x703D5CBA50B54EB1ULL, 0x7706A686968E2954ULL, 0xD8695708AF138ED2ULL, 0x4E155050C3C1C51BULL, 
            0x7D6B48A5DF83F4D5ULL, 0x1A8CBEA9F9E23A24ULL, 0x0463B3FD72FBAF3BULL, 0x014E0CF2386AA174ULL, 
            0x5F4B373D0338BACAULL, 0x66E1AC9952800DA4ULL, 0xA865DB7B8B6E1136ULL, 0x8A63F2632E9C880CULL, 
            0xDBE2BCFC257490C4ULL, 0xE397BE452FA02469ULL, 0xA246085500B5854EULL, 0xD73556654935DDC5ULL, 
            0x642FF6C437DD2780ULL, 0xFE31482A6D9ADBE5ULL, 0x96DA765B8E1C0AD7ULL, 0xE7E4A06AE8C313E4ULL, 
            0xE330D541986FE526ULL, 0xFFCA3AA20E1E286DULL, 0xAE64812978D81909ULL, 0x76E546D7A91710CFULL, 
            0x8102D5BDFC6BAA77ULL, 0x43162BEC1FD576F7ULL, 0x3EF11B48489CA400ULL, 0xB57A370377F91B7FULL, 
            0xAC07D60036936A30ULL, 0x33E41AFB6B694347ULL, 0x49206030780C8746ULL, 0x5D0AC3DF1ED4883EULL
        },
        {
            0x2D73B1D81AF37FDEULL, 0x4B8B9C8BC22A1E2CULL, 0x421522FE2A25267AULL, 0x10CBBE46F5147D47ULL, 
            0xC4ED0106EF3080FFULL, 0x344D8B8D399E9610ULL, 0x3A45C222AE9D261EULL, 0x5AF25C23E16A3F97ULL, 
            0xB494CF8710A95650ULL, 0x9A539FDA04E5BCC5ULL, 0x097FB8EAF70F535EULL, 0xA698ED6BB14E7CD8ULL, 
            0x733BF60C995EC51BULL, 0x94C200C68BE7EA44ULL, 0x3F15330AFCB25CFAULL, 0x91BBD98E60704147ULL, 
            0xB7D2FC5EC0B80D5FULL, 0x4847FB18F444368AULL, 0xF4D48063A44A30E4ULL, 0xB97383FBA1C339E2ULL, 
            0x68564BC150C99AA8ULL, 0xA4EC71218838E939ULL, 0x55C8C6BC74663669ULL, 0xBAA38882B9EBDDE7ULL, 
            0x7D42C7E6A4714A3FULL, 0xA362FD28D01D21ACULL, 0x0E50BF7AD33B56A5ULL, 0x95F16C09E8E6CE64ULL, 
            0x5EEF361A0B84FB33ULL, 0x86BAF75F98B3F658ULL, 0x6532256D79FE1B04ULL, 0xEB1A18AB945D08A3ULL
        },
        {
            0x774B03B32B781FC3ULL, 0xD376A899D184C2ECULL, 0x93C01829AFE1F8A6ULL, 0x575104B3DD58FF52ULL, 
            0x04D76AAB899D61CAULL, 0xCBBD76F88861038EULL, 0x3E4DC85380EEE991ULL, 0x5DF1D56AF54779C8ULL, 
            0x7AA50914778A9F54ULL, 0x03454BE91E5B6A80ULL, 0x27851BC9E7E5C13FULL, 0xFFB06284E3378786ULL, 
            0x9B966B5F9E5D9C6EULL, 0x1F85E37FAAB8719DULL, 0xE1AEBA203E4F32DDULL, 0x2BDBD3D425CC73F4ULL, 
            0x03FD8C4E39FBC970ULL, 0x825F9F3471C5B970ULL, 0x71F93A4834B08466ULL, 0x50A793A49C392CD4ULL, 
            0xC2705F33759ABFF7ULL, 0x9828C87E443F15E4ULL, 0x9A571C39D7F168B5ULL, 0x10E4396710375A60ULL, 
            0x42B890AFFFF3D9C0ULL, 0x3204BF20A1A9ABEBULL, 0xE23F1F29DB8AD1E1ULL, 0x15018CD3B49B18BCULL, 
            0xD4ECDB524C7B354EULL, 0x790FC13F98AA41F5ULL, 0xC6C40C3C8963D6A6ULL, 0x650C3B1EE9DD4A30ULL
        },
        {
            0xE7C6E8602856DE63ULL, 0xFCE927381DAF1FAEULL, 0x9B461FFDD6E76776ULL, 0x636E29F0785BEA20ULL, 
            0xFDC9EA94AE99131AULL, 0x93A22BF4B92C5659ULL, 0x773868DE7B78F90AULL, 0x13B8CB21AD5E4FBDULL, 
            0x7AD76EDB1D409040ULL, 0x4B9D6022F8EE2DC0ULL, 0xED035B03ED5AF7AFULL, 0x82CDBEAED8BF0590ULL, 
            0x609EF463215DAEA2ULL, 0xA2FA45B46908F981ULL, 0x06D74632CF514FDBULL, 0x0D1C534303F20518ULL, 
            0xB844748C657F11FDULL, 0x65F24B808162F092ULL, 0xC130320918D864E0ULL, 0xF8C078B475C59332ULL, 
            0x6AAD87C64B41E36EULL, 0x0B2E5E5A61C65E08ULL, 0x9BC2547B47F5BC98ULL, 0xBCC3604F23E00E3DULL, 
            0xAB032862D88A9C8BULL, 0x511B7B795D646C1EULL, 0x0BB41C20C1276028ULL, 0xE87450CC32D49AA8ULL, 
            0x27A155839712CBAFULL, 0xD7DFD15F6C9A6863ULL, 0x2305CFE950310F0EULL, 0x4B340AFC4D5E5264ULL
        },
        {
            0x02E6B0B1FDBD3CCCULL, 0xF33952CC6BBFE487ULL, 0x5A016B8E488F78AFULL, 0x888D87C4DFA5A835ULL, 
            0x969585316CF8C2AEULL, 0x03F5E714A46D0B7FULL, 0x18809EC783C26086ULL, 0xC52C238A0129590BULL, 
            0x1FEA1F7784A29159ULL, 0xFB849A2EDE9BD4B8ULL, 0xAF1AACF8057D5777ULL, 0x9CA353350038D58EULL, 
            0x44045BCC4E1ECC6CULL, 0x1555088B2BED17A0ULL, 0xAFD6DBD34316F3C5ULL, 0x7B67CF6DEA0AF1BBULL, 
            0x2902B104F14165C4ULL, 0xCFAEB915633D93E7ULL, 0xE5CC2242DF95C2B6ULL, 0x282C031EAD115E63ULL, 
            0x1C250571A85CC329ULL, 0xD8BD481E967C0C46ULL, 0xE1382FCFA39F0028ULL, 0x117F492A775A006AULL, 
            0xE3319CD959775248ULL, 0x5B218A00B37B1475ULL, 0xC1E28C0175DE1E4CULL, 0x62E881DD0CC39112ULL, 
            0xA23D506440694AFFULL, 0xE973BC10F7087D3AULL, 0x26382EE7C479C21BULL, 0x0E3EAB9D58F5EB88ULL
        },
        {
            0x64A052DC9275FA96ULL, 0x06ADB5E832E8F03FULL, 0xB65495C3F0F68121ULL, 0xE68DD23C9F0DFD5FULL, 
            0xE12D5FF14FDE72F7ULL, 0x745A6C2339592298ULL, 0x567ED243AC2ED1C6ULL, 0xA832A9E5841B7049ULL, 
            0xF772F6D8BB807FBCULL, 0xAE66FCC3FA56490FULL, 0x32C744E4BC01CAA0ULL, 0x04255F51BF6518AFULL, 
            0xABAD4E99E423D38EULL, 0xA4F92B4ADD61DAB2ULL, 0x55CDF68B06DEC3EDULL, 0x08114345B27C837CULL, 
            0xC51AA18F400A9E27ULL, 0xCBCDBEB2AC4FE0FEULL, 0x60FD5CB55DBB2DA6ULL, 0xC0712BEF857577BAULL, 
            0xE2B13D1127F1CF90ULL, 0x30B104974E4A36DCULL, 0x5B15C364713FE56BULL, 0x914D2A32D43AF095ULL, 
            0x024835CE4CC93399ULL, 0x4BAD8E0FF518E16AULL, 0xAA7853A4C3CB764AULL, 0x41BB6828E075F017ULL, 
            0xDD9CD5D4A636E653ULL, 0x51E52DC200E0FC06ULL, 0x94B01FC199FC159EULL, 0x135BAE971D1240DDULL
        }
    },
    {
        {
            0xD0F535D89DF92D4AULL, 0x41F230C855C2080BULL, 0x044913632DD867F9ULL, 0x28A0F76F894FF274ULL, 
            0x11D40CA61D923C64ULL, 0x2EDD8D1BFAC51F5AULL, 0x489B52A5D29E11CEULL, 0x70A995AC36C48D4AULL, 
            0xFFC03A8154950C13ULL, 0xEB47C98452E29A38ULL, 0x889820D3789CB622ULL, 0x804340C93E366033ULL, 
            0xA43F9D93D2949198ULL, 0x76906E892F874CD0ULL, 0x2D8E19F4381C7D13ULL, 0x068E30D272C0C2E3ULL, 
            0xDE57243260F45F86ULL, 0x878074E531DDA2BFULL, 0x94430AC439622838ULL, 0xA1B17C91A55AF647ULL, 
            0xD6369BF120A49BF4ULL, 0xEE8D9D5842B5641CULL, 0x881A2EE654C37675ULL, 0x0AF4355E0D072350ULL, 
            0xA9B786EE63283A16ULL, 0x74621C68AF4FFA45ULL, 0x2D17F1AD93DFE4A9ULL, 0x7529E302F9C09585ULL, 
            0x7E27982C5C196DF9ULL, 0x75AEC62033FFABACULL, 0xFA9D5EE0EE491CFCULL, 0x0E298669AF69DAE1ULL
        },
        {
            0x9D949FC407E66300ULL, 0x4EF4255B0C33D3C7ULL, 0x899B785DA466317EULL, 0xA2910986806B50FDULL, 
            0x9BAC341921372E98ULL, 0x419E572A96A5CEEDULL, 0x21AFF2B4B4A99FD6ULL, 0xCF6F43917D60E01BULL, 
            0x762303012AE259A8ULL, 0x7A711AC7397CDB46ULL, 0xB6EAD6A17844885BULL, 0x63D34FAA962E224BULL, 
            0x84E8DD6A696CEF3DULL, 0x110B7E8DFC358702ULL, 0xA45504B8B7949E09ULL, 0x75C525A388B8BEB1ULL, 
            0x5166D8DCB7C46A6AULL, 0x10F0E2CD5F8A7582ULL, 0xF140AEB6F04761C7ULL, 0x1BA768A970659C14ULL, 
            0x3C33498202F31260ULL, 0x08F520826469406DULL, 0x473C4F55DF0962E0ULL, 0xFB1486C32B711B00ULL, 
            0x4889E4ADA0F74809ULL, 0x5B8A54B67E903D7FULL, 0x0B5039D7A2255A51ULL, 0xDC387AF834614F6CULL, 
            0x440ED889BF7F7A06ULL, 0x7B08781B496E575BULL, 0x8D219D8021A79F58ULL, 0xBFB99C9BDCB80C3EULL
        },
        {
            0x754A4E1008E4D088ULL, 0x04A6444289E08499ULL, 0x876A4417709B7BD7ULL, 0x86ADD0D48E14A555ULL, 
            0xBA006D60F1AA0F20ULL, 0xD3014A463F546ED5ULL, 0x947BDD8697330F03ULL, 0x1970160358AFD3F6ULL, 
            0x4E9ADD3C9D189066ULL, 0x5A1FF6ACE198E095ULL, 0xBBB16E2068D06BE9ULL, 0x9FE5C7BF0AC66265ULL, 
            0xC8F7D6347817BB89ULL, 0xB9F3FE0EC6865443ULL, 0x58BADA896F555449ULL, 0x669D812E50E75EBBULL, 
            0x6E21D51585E385B3ULL, 0x4305B4D915A42ED4ULL, 0xC2DC88F023FA62ECULL, 0x82647AC32112F0FEULL, 
            0x3DE863B59D080DBEULL, 0xF5A3924BCB07B991ULL, 0xF349374817E95AADULL, 0xF4CE9C9655E92A61ULL, 
            0x8AF59CC4262351DBULL, 0xA648234A0CEAEE0BULL, 0xD8E7EAEBF0F29906ULL, 0x4B9B26CE9F0FCED2ULL, 
            0x0FFA20D44DCFAF29ULL, 0x37448C2FD07E9602ULL, 0x0FEE2633E3F88110ULL, 0x42A049FABE9D4455ULL
        },
        {
            0xF82F8BE41BDBA86CULL, 0xDB1B822B330250C6ULL, 0x9BD663FB36D27ED7ULL, 0xB3F5E456A76FCA7EULL, 
            0x5EA98D3B5506843CULL, 0xD781521613D20131ULL, 0xA8A42806062D6359ULL, 0xFD90F33308422594ULL, 
            0x4DAABCA00B55571CULL, 0x78DEC246DB4442D0ULL, 0xA84D793A1D29942CULL, 0x0A6EE3F6C45A39AEULL, 
            0xDFB12F77C3933CFAULL, 0xB15449CA1B9B1132ULL, 0x127385D6D940B745ULL, 0xADC2D00A53C4ED6FULL, 
            0xB8E8B60C03BBB4A2ULL, 0x40169390562D7251ULL, 0x1983680ED9B92189ULL, 0x88AD58531BF8F343ULL, 
            0x43798C04D95AFA70ULL, 0xAF25DC85FBB49855ULL, 0x0B3B59C5D2349598ULL, 0xD4FA8F2A1AFF2FBCULL, 
            0xA8C636B5D97DD226ULL, 0xC6EA03912A045BF7ULL, 0xFD407493047B2448ULL, 0xB090CD559B26C5AEULL, 
            0xED9FB94B8BD63953ULL, 0x4024F3F9EE83F3DCULL, 0x97B55E7F83BF355CULL, 0x205D8842126120E2ULL
        },
        {
            0xB168F5CFBF95114DULL, 0x0F9CF17F5D34B196ULL, 0xA863E24598F4985AULL, 0x12313BF059F2CEC2ULL, 
            0x17FD0442D0C6D791ULL, 0x92C3AB712301F4E8ULL, 0xA4F51B14DAF3BC3EULL, 0x41DFAD992F034036ULL, 
            0x6FB216E18E74D76AULL, 0xE4F84C151D0EA21FULL, 0x7F9AD52880EB5B9CULL, 0x4B255AF32B4A6E1EULL, 
            0x5558DF6D0C9BF5D7ULL, 0x261D108469E3CDB1ULL, 0x317CD21B70879E89ULL, 0x1A8D516615AB5088ULL, 
            0x84DF60AC52D36CADULL, 0x2DB22B6DF270958FULL, 0xF56E851DB21E0A9DULL, 0x6A2ECE56521AC9FBULL, 
            0xEC80FFBB7DD87CBDULL, 0x8A0FD8C32B5F0994ULL, 0x807D7A55A96638D6ULL, 0x7144DA8EA2BB7775ULL, 
            0x33D77B34223B5707ULL, 0x78283522A47FDA69ULL, 0xB46B883DAF51B09EULL, 0x781EA05E6120E483ULL, 
            0x5E328813D0087AD6ULL, 0xB1AF6F16D02D284EULL, 0x7CD92324EB047C49ULL, 0xC7D5FD76B00A9F0BULL
        },
        {
            0x96175B3CE85669D7ULL, 0xF77305E7D074369CULL, 0xCAFEDA29DF11740FULL, 0x2F3D01E5677935B3ULL, 
            0x5C534E701F87E633ULL, 0x7C4AF351CC491F87ULL, 0x4ECFE46EA765C361ULL, 0x8E21432AD05B0F61ULL, 
            0xF0404CA06DD8B7E5ULL, 0x8FF7822305EB30D9ULL, 0x45FB4FDFAEAC5C89ULL, 0x81920A696C38047CULL, 
            0xAAB2FDFAC1750F5FULL, 0xA395A2B01E1FB55CULL, 0x6076EA5F2C67885CULL, 0xA2C84F1DDF550CABULL, 
            0x40C45FA602F57CC2ULL, 0xF1E2B9D03EAC76B0ULL, 0xC08ADC7C243CAB86ULL, 0xE1A225B156799477ULL, 
            0xF341075952563778ULL, 0x7B0F2BB9CAEE0E75ULL, 0xB2020EDC056FA981ULL, 0x3B5D73C3BE36E1F1ULL, 
            0xBE6E113BE278BF22ULL, 0xF489562C611E3CD3ULL, 0x99A09C550F475D48ULL, 0x05631A250ED695D5ULL, 
            0xEB180FC0B8E2F6D2ULL, 0xCB5C97274E88513CULL, 0xC4E8314F55BD6575ULL, 0x48283C0F4C189589ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseCConstants = {
    0x838A588949E99C2EULL,
    0x66F11F2F512708C5ULL,
    0x5BF5581C2B398955ULL,
    0x838A588949E99C2EULL,
    0x66F11F2F512708C5ULL,
    0x5BF5581C2B398955ULL,
    0x89C728AA87CA605DULL,
    0x8AC6BA7C6921B75AULL,
    0x52,
    0xB5,
    0x73,
    0x5A,
    0x9C,
    0x7D,
    0x91,
    0x7A
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseDSalts = {
    {
        {
            0x66E66B273C816450ULL, 0x75A57A68841355A3ULL, 0xD8848367994583C1ULL, 0x8665F9C49C59C4FDULL, 
            0x843F924DFD8226B3ULL, 0xFB1888FFCC630F9CULL, 0x0B0364E217747114ULL, 0x113680F7C745FB58ULL, 
            0xE6A0061E725905D7ULL, 0x614ED94D09BE5B27ULL, 0x0A6F5A5BCC72B54DULL, 0xC9E24E59632066C5ULL, 
            0xC22843622642DD4EULL, 0x73080F95F7CBC3E5ULL, 0x167CFAF671679A7DULL, 0x92D1D8AF20245A85ULL, 
            0xFD13263708C38594ULL, 0xA2821BAC420C0EE3ULL, 0x669157C8B01BA3E1ULL, 0x42CBF3819D24BCCAULL, 
            0xE4617946F4FB6F0AULL, 0x455D30731A9C7E36ULL, 0x019031A817C57DA0ULL, 0x86FF10789BB510F3ULL, 
            0x1749D4076DAE4959ULL, 0xE3DEFC37D01ADD67ULL, 0xE2EBB2A72096FC66ULL, 0x17C8945DCE389E1DULL, 
            0x6941AEFD095184CDULL, 0x31AC5E591FF73EC5ULL, 0x6336499076FBD142ULL, 0x2F354021DF55DCDFULL
        },
        {
            0xE364F638AC5ABF66ULL, 0xB65B8CBBF7B5073CULL, 0xE0773D3FC4257075ULL, 0xF71BDCAC2DFBDCE0ULL, 
            0xAE8C5156AD59B6F4ULL, 0xF30D7F0310B85EB5ULL, 0xE14CE64C3AA844ECULL, 0x1FF1C5C33AF5F8BBULL, 
            0xE507D61B305F3DFBULL, 0xF267B626E58DACADULL, 0xFF2CB59ABBCF390BULL, 0x28C393AFCEF3460DULL, 
            0x49E2D524332DB3DDULL, 0xFA2E6D1EA3C334C7ULL, 0xCDF74EFC64AD3531ULL, 0xEAF314216CAA252BULL, 
            0x1C87F6CCCFA53E4DULL, 0x1D42B2C553232CE6ULL, 0x5298CA93A8EB2BDDULL, 0xE2FB8C00BC47633AULL, 
            0xA7BF821897AE8515ULL, 0x804079ACC9990260ULL, 0xD9F6C8CC4F5B4B6FULL, 0x55214F38B435D56FULL, 
            0x41A89863656762A7ULL, 0x136D2190AF5795C5ULL, 0xED782747D0E60280ULL, 0x540A4A5628297C8FULL, 
            0x0009061FAE440FF6ULL, 0xE83760ACA970EED5ULL, 0x6CB2EC5068DA95D8ULL, 0xC6361F3456B97096ULL
        },
        {
            0x225D4C4051229F30ULL, 0x1FE5E4F7F031970DULL, 0x0E51382679885FF0ULL, 0xDBD079A9721F0A6CULL, 
            0x6B6CA076DD8223E0ULL, 0xA3CC57B3050DE01CULL, 0x2CCCB690792BE618ULL, 0x3163472328359B85ULL, 
            0xEDA9A65D2924321CULL, 0xD18C21E5C1A2F511ULL, 0xAE201D7EAED9A547ULL, 0xF1030CF9D692CB74ULL, 
            0x90F6EB1745649B5FULL, 0xF483EEB7039AE03CULL, 0x6F3DEDEB66552487ULL, 0xF002D9379CD03FB3ULL, 
            0x8B12A0D6894E3FF7ULL, 0x0366354DF443AC61ULL, 0xAEFCDBE8E2D4CED4ULL, 0xE643EDDA151901F0ULL, 
            0x75D8931FBC14C3C4ULL, 0x533E75BD8CE95268ULL, 0x65BC62487F016273ULL, 0xCBB6736B39BB1AEAULL, 
            0x2A22BE62D28040A1ULL, 0x60C625286F65F40AULL, 0xD8658025FFC81FB6ULL, 0x14D382BD5265C46DULL, 
            0x8FFB205D73CA96FCULL, 0x18C70F99659BA958ULL, 0x8F2571F3AD0D17A2ULL, 0x795877CA80CCA8C1ULL
        },
        {
            0x455B781CD0CEAF23ULL, 0x468D7DA72130E5E6ULL, 0xDF9BD0228652050FULL, 0xE2E7FD01FD91512DULL, 
            0x1FF07ADD798A3144ULL, 0x48EF4EC0E2311A56ULL, 0x0D044F0805C7796EULL, 0x4243F9EB269A8129ULL, 
            0x723A392FAA1DEFB5ULL, 0x5A059F29BBE075A8ULL, 0xA16CE062482185B6ULL, 0x690A2C5681CDA4DEULL, 
            0xBAEB5130F992075EULL, 0x8904A87A95A6E2BFULL, 0xCC2E4DC383141D14ULL, 0xC26748170984552AULL, 
            0x918F5A974BBF16D7ULL, 0xB5E7797C42980476ULL, 0xF7208A3A4EDE8AB8ULL, 0x9D7117F6B88FAB13ULL, 
            0x84897DCAB073D844ULL, 0xCD85271844AA6F21ULL, 0x04C14F296D7E0A23ULL, 0xC77F539EDF9A8E69ULL, 
            0x0B25AE03713A062FULL, 0x05DEE23E466F97FDULL, 0x1BA8BD766F3F702FULL, 0xDAD88A61CBD6A9A1ULL, 
            0x15228989BF83E65EULL, 0x09BAE66DD41D994FULL, 0xA859481929F56E9CULL, 0x6A2D46DE1C67C05FULL
        },
        {
            0x9332A98EED557114ULL, 0xB2FF3C6B67A30183ULL, 0x7987140E4CA25187ULL, 0x29E86871C3AA6454ULL, 
            0x483F154375BBD712ULL, 0xA09F3049C710E8F0ULL, 0xD4012A06D0C14C04ULL, 0x6E89F3B3A0D8AF95ULL, 
            0xC48A992752D0A905ULL, 0xEE5D443CFAE7D1EBULL, 0xAD4A01079CB1C859ULL, 0x5426D81275BEE8EBULL, 
            0xEF2447893F6A0509ULL, 0x64B6635380062A1CULL, 0x5DCABC3F5BF29379ULL, 0x2F10F4488B38F151ULL, 
            0x3C752A46913FA2BFULL, 0x4B27BE6EFBC0E203ULL, 0x52E6B171386C3A40ULL, 0xE742C9BA64096267ULL, 
            0x7527DAB534A325ACULL, 0x5DF4956706422869ULL, 0x207705BFACA49C6AULL, 0xA4EB160CAFE6979DULL, 
            0xD44B3FABC544EBC7ULL, 0x3341B0D6228CC2BCULL, 0xF4B41AFB8560B296ULL, 0x98C2582F4A714CBAULL, 
            0xCD1D9C81FF0FD2E1ULL, 0xF56C47B8CAB5ED00ULL, 0x995743AF18F438ADULL, 0xC39895195D35C806ULL
        },
        {
            0x9A65461178A97B7AULL, 0xC455A0ED4A1DCBC5ULL, 0x463A8FD9BFE683EDULL, 0x7307B002A1022ED4ULL, 
            0xE13A398F5C8EBA11ULL, 0xCD857C9A947E3242ULL, 0xDC33C7DA65BD0967ULL, 0xA98535C8BB8D2189ULL, 
            0x0BAA7BCBA2C9D865ULL, 0x1D53004F8228CA79ULL, 0x1373F8692C769DCBULL, 0x893634B9D6ACDECDULL, 
            0x5A4BC8B308427A0AULL, 0x8E7D0FA59002DE35ULL, 0x3F89981B2C78C0A1ULL, 0xA90A4E13EB4DDF18ULL, 
            0xDE15D8CF0F476A10ULL, 0x033F14BC85F97547ULL, 0x393D9F1F3443DA69ULL, 0xD644BBE55B698F25ULL, 
            0x0A9195D5F0720F21ULL, 0x2141FF5055CCEDF5ULL, 0xB8FE904A9D01AA82ULL, 0xA50E69CB14A0BC6BULL, 
            0x55F7E44B6EA8B17EULL, 0xFCFCA9C6B01FA2F7ULL, 0x49E866F11F69DA40ULL, 0x6BA12DA411D2E7EEULL, 
            0x24955E7E2D63F54BULL, 0xBF5E5A14E12488E9ULL, 0x7285737236280F71ULL, 0x1315C49F613BB84BULL
        }
    },
    {
        {
            0xE7567CC4F3673CDEULL, 0x94131415CEB79854ULL, 0x470D5C2DAA784053ULL, 0xD480FAA73BA79DB5ULL, 
            0x2C3D92D7DB74F26BULL, 0xB132C5E977314CECULL, 0x0A5DA841D4410F32ULL, 0x9C660F1B9F6BB669ULL, 
            0xC83C2323A12DC3F3ULL, 0xEB9692E0995E1AA0ULL, 0x5F89B8B92C6E08E7ULL, 0x946BC1C05CE9C850ULL, 
            0xB64D8A790C9A2CB7ULL, 0xE57D7710DFEC2417ULL, 0xC403A5C0F6B70B9BULL, 0x41CB7A3AB2C2E0BBULL, 
            0xC7B42E6DAFC14990ULL, 0xEF8B9D551A6B927AULL, 0xD813EA3ABFD65E56ULL, 0x6F569C10EA08191FULL, 
            0x8CB2B143CE7C3C35ULL, 0x28599FD74D0E4905ULL, 0x1ED0796EFC6D91C3ULL, 0xEDA9ED7693751957ULL, 
            0xF6996D7C64D00844ULL, 0xC7BFFA73ABBC5D4FULL, 0xF194F1DDB994001FULL, 0x6A22FF9B8DE923F7ULL, 
            0x522513849BD45D3AULL, 0x1DBCB1AC0F120133ULL, 0x8BF929018390AEBDULL, 0xA5C7904A5F651BC2ULL
        },
        {
            0x422E3767B8043855ULL, 0xF4BD2557973EF9E9ULL, 0xF6416E217305A50FULL, 0x51E37F37D3DDBE05ULL, 
            0xF5327CD42AC9AF03ULL, 0xB3EBFF03224058A9ULL, 0xD721CC09861E6154ULL, 0x4EF612AAF2D5C3E8ULL, 
            0x19A1FA15DC47685EULL, 0xBCA356DCEAFDF06EULL, 0xAC6CB0841CD867A7ULL, 0xB8CA7E420F400A3FULL, 
            0xE2CAC8D7E203D871ULL, 0x51DFB746C55B7581ULL, 0xD404B47069B53059ULL, 0x1DEAB32669428F1BULL, 
            0x3E806BDA0FEDE902ULL, 0xD96A4E557069163CULL, 0xD2125093A09C8209ULL, 0x1CDB5ADC4714945BULL, 
            0xC7263F105092E1BFULL, 0x1A5438CE1F2E6275ULL, 0x52F8E5FD9C3D945FULL, 0x2938F88CDB1B00CFULL, 
            0x868D098A97CF2FCCULL, 0x9DD8DF9703813E11ULL, 0x1EB0FD8A6BC67FD4ULL, 0x5FF650F9ED3108D0ULL, 
            0xD91A9040FEAA11B4ULL, 0x816ED1F18C680D90ULL, 0x599D1E209F2621EAULL, 0xB3BEBC59140F2A14ULL
        },
        {
            0xF211B950FD1C5472ULL, 0xA00BD8241AE293A2ULL, 0x214DFABEE5408EA1ULL, 0xE596ACB6DC41DD04ULL, 
            0xEBB2A43A55FA884FULL, 0x3CB4DFCB0131C83AULL, 0xEAB460285B4C93EFULL, 0x8185B57A6162C0DDULL, 
            0x56B4E44984536889ULL, 0xDD2B954791680D36ULL, 0x7CE1DC0E412192ACULL, 0xDD3C073134026A2BULL, 
            0x98E0F4D0BB99643FULL, 0x03427C142858FCDCULL, 0x9D68D23B8C3A3EDFULL, 0x41CC08A42976115CULL, 
            0x79A7E14F5DC970B0ULL, 0xB275F92D777F5565ULL, 0xC964196B851ADDBCULL, 0xBD6396498B605254ULL, 
            0xA8327336DBA9BC40ULL, 0xCFECC819A0759EE3ULL, 0x6F86633751FEED62ULL, 0x54CE05BDFF375BEAULL, 
            0x81F032DEF0FBC501ULL, 0xD4F1026EB5AD3B14ULL, 0xFA4FF28D8B8E3D0BULL, 0xB08FF0A80FD65D8BULL, 
            0x4F4E6882EA13B99AULL, 0xC22401F597E02D1AULL, 0xF8E9553257E3037AULL, 0x3479D4D50A5A6118ULL
        },
        {
            0x7A4185836A0BEC79ULL, 0x5F644212DC8E103FULL, 0xC9DB486592AEB459ULL, 0xA0C90642962F7F7CULL, 
            0x333A3A2578F5AD56ULL, 0x42FC593AB3A1E8B0ULL, 0x3E7E105D07BC838EULL, 0x11B33A47382089D8ULL, 
            0xA664DD34F6325C6FULL, 0x2A5B67F63E60BB46ULL, 0x2E26C273EBC6F6AEULL, 0xD6A1D0264E6AF9F8ULL, 
            0x909A453FB30EFDAAULL, 0x3CCFD0992CCD27C8ULL, 0x5D04B25831AD7AE6ULL, 0x23869E44DCED7918ULL, 
            0x0D5503C1746B7F03ULL, 0xD1BB94A66E14DA80ULL, 0x55AEDF2C1A48704DULL, 0x39A6F23129562C87ULL, 
            0x4FABF92382E6F416ULL, 0xF14D15550CB1595DULL, 0xABC73277AC939BD9ULL, 0x7F502CB4B4F825D6ULL, 
            0x4992CB86B1F5C81CULL, 0x5E1C50B1C3E632E0ULL, 0x7AA9AEEB2D53F14DULL, 0x7CC0D9ED7EBCAC90ULL, 
            0xC238671A80B5BEA2ULL, 0xAFB897287B19C364ULL, 0x12BFF93E5AF6A620ULL, 0xE6171C75844AFAC8ULL
        },
        {
            0x74DE13C2D25C5806ULL, 0x03632B67A434EAC1ULL, 0xDF4672E51D8F4DCDULL, 0xA7E70F901F68098FULL, 
            0xE110CBFC3022DD50ULL, 0x6AFB35CBAB65FD7CULL, 0x0368C5D9FF056A69ULL, 0x3019B6AC43CC3D42ULL, 
            0xFDB450CE7CE50E5BULL, 0x3D6EA49F56404898ULL, 0xEF77AEBF9CF942C6ULL, 0x5C97D1CAD3EEB247ULL, 
            0xC26B153ECB2069C8ULL, 0xFE0BD56B25A89030ULL, 0x67A2A3D5D44D53EFULL, 0x968BD88D69D055E0ULL, 
            0x2AEE49DF3D03658BULL, 0x171C972F4D84FB52ULL, 0xA3CC18D31820BD48ULL, 0x8680A04E7B5A2981ULL, 
            0x2C4F69A78EEAD958ULL, 0x3DB2B54F700D6A74ULL, 0xEF760EF2ACFD5816ULL, 0xAFA1BEDE83B7F6D2ULL, 
            0xAA4B1B594132ED69ULL, 0x83EB342067BA1628ULL, 0x4F022E4012195D9DULL, 0x20A185095A5849A6ULL, 
            0x8DE8F89C2AF22CC8ULL, 0xA994ECA343D49D46ULL, 0x089C9A71E83D5570ULL, 0x96C01886D0F6B967ULL
        },
        {
            0x080A628852913789ULL, 0x58BE31521B4DB181ULL, 0xC4746D8140B2FC17ULL, 0xFEB4689E16359041ULL, 
            0x1CA5FAEDD4F7A004ULL, 0xECEA34B53381BB25ULL, 0x5F3B99C42A5D3108ULL, 0x79D9731ACE6B7FEFULL, 
            0x6CE25EC0EB9C349EULL, 0xD221D1F072D87AF4ULL, 0xAB9CF3040B62C68EULL, 0x56FABC487D5942BCULL, 
            0x39C78BC4276D5CC4ULL, 0x8FF2635354F3D1C7ULL, 0xCF61FEF40A2A8D46ULL, 0x982C9E64B867BEC3ULL, 
            0x8D85A96ACFE0F19AULL, 0x47F9D025AD8CBBBAULL, 0x2B2D59ACB4011DFDULL, 0xBE7D62CA8C32C4B7ULL, 
            0x5B53EF3BBC675848ULL, 0x8A8A32751EBFF994ULL, 0x73605B4A18E1D2EBULL, 0x57EDE4941C572815ULL, 
            0x31F691F762C6C816ULL, 0xB2A861AE2293AF14ULL, 0x9FB2BD5AB2A5FD69ULL, 0x77D583C7832B86E9ULL, 
            0x20DE26D1E9BE040EULL, 0x5943B7358789ECBEULL, 0xC119C196519AB8D3ULL, 0xDC3EC495CC517B36ULL
        }
    },
    {
        {
            0xB8579798B88D63D8ULL, 0x7A9029A6D0E7BED4ULL, 0x0A14B6F73DB32D0CULL, 0x73BD136D5C00D3EDULL, 
            0x31D882498D794EC0ULL, 0x4911EF12B3BA9A73ULL, 0x8843FE059F8D27C8ULL, 0x39DC9A741F72322FULL, 
            0xAA4BC061205C9BA6ULL, 0xEA67494BA04AA95BULL, 0x0F73EC4AAFFA9DA5ULL, 0xD2E2252D05447A66ULL, 
            0x9A2BCD3A45C31669ULL, 0x2E1F95A956EB1C72ULL, 0xDF63AF8ADEB88D31ULL, 0xB67522694AE20FF5ULL, 
            0x4EA19A942D94746CULL, 0x0764FEF3B2FAF186ULL, 0x76CE93E3E1436882ULL, 0x4F53940118E9E5A9ULL, 
            0x8E04A00862B5F61EULL, 0xC1D15ED9D2E4ACAFULL, 0xD08F497AD7D78762ULL, 0xECBC04908597222BULL, 
            0x362CDB94E1565582ULL, 0x7545B4FC26839716ULL, 0xED97AFFF389375BFULL, 0x921F77E8F7D95820ULL, 
            0x614431E8AAD3568BULL, 0xBBF8BD0F4320D6B6ULL, 0x85F2268E9AE288AAULL, 0x971839FBC81B4695ULL
        },
        {
            0xE6DAB86E5C335B76ULL, 0xA979A43F68D4A826ULL, 0x1DA87803E3389867ULL, 0xC124F2C0C42F4A2DULL, 
            0x5DD30E2FD746057CULL, 0x7BB70FEB6FCAE253ULL, 0x81512F07A6008F11ULL, 0x8B190FB28E0EC491ULL, 
            0x0EFF26F15C8FF375ULL, 0x9E9632E6DA033134ULL, 0x0566E71FB2097850ULL, 0x0FE4ED47E0F9DC16ULL, 
            0xFDA8A3B32371D7D7ULL, 0x1525CEA8AD8D1DEFULL, 0x477C51D64C22DF20ULL, 0xEC70959670BF81C5ULL, 
            0x5CEA7D4EAC30DF4FULL, 0x4EEE1310E6AF5FE5ULL, 0x3B39BCBA612C97A5ULL, 0xAEC263331232360EULL, 
            0xBC7592EFDE10C4A1ULL, 0x6FACC1DDBABB9A70ULL, 0x748148D476C39C96ULL, 0x42ED3F01677205B8ULL, 
            0x1AEC613AA2E9C084ULL, 0x0123B550B2B9F02FULL, 0x4F4E66C7D98753A5ULL, 0x6F7FE8F8DD356078ULL, 
            0xF3554C1BF7895F23ULL, 0x45AEB339E45DF282ULL, 0x80BE7BB9AB04B333ULL, 0x00581F8E03DC0431ULL
        },
        {
            0x1653C35FC89ECA55ULL, 0xA3AAFF477F61C89BULL, 0x53954E10B7450435ULL, 0xA19A36190B6C6665ULL, 
            0x2B8DCC475FB6F2BEULL, 0x784225AEC416C988ULL, 0x5B2726C2D3D7086DULL, 0xEDB4D726400D3C9DULL, 
            0x6CED01B4F8A4C9F0ULL, 0xDA43E34957797BFEULL, 0x6BB063963914EB84ULL, 0xD1D5F73C9533256AULL, 
            0xB0BAE4F35D85A43CULL, 0xF6400895004F67E5ULL, 0xC88A99D66B068BCAULL, 0x9DD521767C12B20CULL, 
            0x43CD7BF5C67B22ACULL, 0xF457DBA8CD71B04CULL, 0x3F411D1708C32740ULL, 0xA9558A7E592A5B25ULL, 
            0xA4009A289255DF4BULL, 0x4943FB6B32C58BF9ULL, 0xCF0DF2A2CF6AD51FULL, 0xCC066CBC92DE9440ULL, 
            0x8F0995FE420C19EEULL, 0xCA4251FF745C69FEULL, 0xF285096351AE96BFULL, 0x8B8FE9125400FAE8ULL, 
            0x431C5BD1FC94FC9AULL, 0xC381281AB98C2A75ULL, 0x946090497610E338ULL, 0xB46B00AD68592731ULL
        },
        {
            0x470026827508BC6DULL, 0x21BEFF76CD7C5A51ULL, 0xAF5A26DE611FA06DULL, 0x64F6A8B6CCF704E6ULL, 
            0x2230EDA69CC07563ULL, 0x323FCFB3B4536835ULL, 0x14522B3689ACC084ULL, 0xB219A954E7778D15ULL, 
            0x96699E22D796CAB2ULL, 0x0F6E1F25D05D1B8AULL, 0xBC055F80EAAA5CF8ULL, 0xF807AEEF1F81A755ULL, 
            0xA25B5474BD999D20ULL, 0x182387BD181C80E5ULL, 0xF2A70CDDF5600F40ULL, 0x6C20423AE3E40F80ULL, 
            0x0DC6EABF793A2312ULL, 0x607B5BEB516172EAULL, 0x1FB234D481B417E6ULL, 0x3878856A53ADAC79ULL, 
            0x25B459743D0B530CULL, 0x52B2E1172B3DC4A3ULL, 0xF5AA0B181CEA1FF5ULL, 0x23C8E0B51E1A2043ULL, 
            0x1ECBA6AD11A15E9DULL, 0x1BD00872F0A22859ULL, 0xB1F4149DD0A7E384ULL, 0xB19E79530E9ED114ULL, 
            0xCB058EB19BDC2E2BULL, 0xED4A1B7011EFAB24ULL, 0x079132645A51EE12ULL, 0x09B75E4439996051ULL
        },
        {
            0x620C8C446EE17022ULL, 0xB2807F84ED6AC20EULL, 0x888D24FD6A34DADDULL, 0x1BAEA6478E9A9608ULL, 
            0x140CAF186A8842E4ULL, 0xC0ED4C3DED3D7329ULL, 0x930BEE9E70F35742ULL, 0x4F921C2695DB50A6ULL, 
            0x7F2326714A1EFD1DULL, 0xA802EFE1DAD5E48EULL, 0x8776ED18A910904BULL, 0x28C3FC0B9ED4C9F6ULL, 
            0xC69CC3142D54F10CULL, 0x5276F0FD98C63F8DULL, 0x5027BDB7885AC1D1ULL, 0xEC8A4D0D96D3D030ULL, 
            0xB71AA320761FC080ULL, 0xA53814B6086BF841ULL, 0xE2CB39D4A2005A3CULL, 0xE836C89CB1A3B991ULL, 
            0x4F311DECE3BDAA8DULL, 0x4A04FD1165F8DC98ULL, 0x82B6F260F89FBFAAULL, 0xB9AFE5D3D7753C93ULL, 
            0x66049D70A367CBE5ULL, 0x22301989F5A1789DULL, 0xA9AFE8A689541822ULL, 0x82926CACAB86C909ULL, 
            0xB5BF4B11E01FEDFFULL, 0x0DDA9A9FD9BFBAB2ULL, 0x464DC96685D085B0ULL, 0x22DCC368F55FFE0EULL
        },
        {
            0xDA6E7E447807863BULL, 0xD8744DEFC3CB2050ULL, 0x05B247331983A879ULL, 0x354BF3DFC76B2C2FULL, 
            0xBD11768EE052011DULL, 0xBBC8F547F15BE656ULL, 0xF0073932ED088021ULL, 0x9B6F298FFD04471DULL, 
            0xE8DA199631A9543CULL, 0xC9ED1857748B1697ULL, 0x5A701056EF13958BULL, 0xA0AFBCC28086E859ULL, 
            0x5D7FEB99B2626BA1ULL, 0xA014A773D7AE9AFDULL, 0xDB2574322B20B810ULL, 0xA6DC6D3FD547795DULL, 
            0x1E883F068AD44F0CULL, 0x7E9DAFBD69875790ULL, 0x54D76317617A80B0ULL, 0x05A2444C56507777ULL, 
            0xE4440B8DE436CC5EULL, 0x50FA7581C9F8C8D1ULL, 0xF5AAFEFABCDEFBA5ULL, 0xF3F6F719BEF342C5ULL, 
            0xCCBEF6176E1DA237ULL, 0xD92DDFB0513C7990ULL, 0xCE80DCCB8FF44502ULL, 0x30B370E2132D7DFFULL, 
            0x1BFF700AAA101771ULL, 0xE20851160C65D64AULL, 0x37A689D17E0851E6ULL, 0x53C9D305F40DA07BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseDConstants = {
    0xAE0E58D7153A0D07ULL,
    0x96CCEE13047C35B8ULL,
    0xA77B02793A9F5D4EULL,
    0xAE0E58D7153A0D07ULL,
    0x96CCEE13047C35B8ULL,
    0xA77B02793A9F5D4EULL,
    0xEAFCC147EFE646DEULL,
    0x3CD9F287B6C9DBA9ULL,
    0x8C,
    0x18,
    0x31,
    0x91,
    0xAD,
    0xA1,
    0xCC,
    0x31
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseESalts = {
    {
        {
            0xD02F31A1A5B41C09ULL, 0x7CE1F0D142D55426ULL, 0x102F45879F250155ULL, 0x2562FE82483DB78DULL, 
            0x0140F805BB59B2D8ULL, 0x5AFB706025BBE81BULL, 0x26D946312977EF56ULL, 0x09AFB508F41E468FULL, 
            0x42558D88CF7BEE63ULL, 0x678902456FA424BBULL, 0x2BFA8EEDD532113AULL, 0x188335DFBE52EE76ULL, 
            0x4BC9CBD7233455F2ULL, 0x8DEFF6AAA0AC7E0FULL, 0x239B6EB66CFDAC85ULL, 0x4F84AB032F08F807ULL, 
            0xFB19EC5DCC827646ULL, 0x9B0FFCFBCD5E6138ULL, 0x2E4650DE05236FE2ULL, 0x749BC1AF37F24D61ULL, 
            0x237C8FC32754A535ULL, 0x3D2BE78BC0969D4BULL, 0x18E2D7E01BBA1A70ULL, 0x99FA6EB1672BC63BULL, 
            0x27B9ED305B1927A3ULL, 0x285ADF7DE7B71574ULL, 0xE7DEB3CEA624BCECULL, 0x917A26C66587C48AULL, 
            0xD2C19915B3D57E1AULL, 0xD6A4AE2E1A2755A5ULL, 0x96730F72A645F567ULL, 0x1A84395150E29383ULL
        },
        {
            0x2CF26EB94ED34025ULL, 0x358C18347B4AD152ULL, 0xC24AC00A36D473F5ULL, 0x4ADB643DF0E15FB9ULL, 
            0x9733A738E98831F7ULL, 0x9AACDFD4814E9DC4ULL, 0x80E84FCCFC7FCC15ULL, 0x3A62ADD614E4B735ULL, 
            0x983CAFE0CA200381ULL, 0x53B469BF5EACB3D7ULL, 0x3C1883B55D4B2ACAULL, 0x63A746D282CFB1E8ULL, 
            0xAC4BB67009CC409CULL, 0x1A819457FE35541EULL, 0xDE769B4FA3420309ULL, 0x2D8EE6300FB3A145ULL, 
            0x818567845275F84CULL, 0x7281AF8E78944087ULL, 0xF716FEFFDBE87DEEULL, 0xB8628B74096B2246ULL, 
            0x0A8F7F2088054294ULL, 0x2AE499B5A525D546ULL, 0x6792293722D44410ULL, 0xA7CF1BE2EF41491AULL, 
            0x372A75FF78F8CDD5ULL, 0x94DAF9035D228647ULL, 0x2278167298BF28E2ULL, 0x4F8CB62E880FDDA2ULL, 
            0x9548E6665386158FULL, 0x12C827967C688378ULL, 0x4327690D6DE8752DULL, 0x46D0C399BA9A8EBAULL
        },
        {
            0xCB67C7BCDD2605C8ULL, 0x8B1146D17C5F5330ULL, 0xD697D2403006E3C0ULL, 0x5565B8FF30C67374ULL, 
            0x1B47C237AFE1F508ULL, 0xB9E87CC9DD029F71ULL, 0x03E351004B1D9982ULL, 0x49832E2B22E5C943ULL, 
            0x0839C0F9873EBE1EULL, 0xB6D8C82C109146FAULL, 0x105EFE7BBE3EEA93ULL, 0x7B80B2EF61BE8970ULL, 
            0x1BC9D239ECB6EB65ULL, 0xC4EBC66EF862C0D8ULL, 0x4429B6A0E977CB21ULL, 0x4C3D96D88CDDB173ULL, 
            0x005873DB89B914EBULL, 0x6F5B8B76A7FC766FULL, 0x118F457AF032CFF7ULL, 0x8BD44D58A19FFDD6ULL, 
            0xE3672CA99AAC3A07ULL, 0x646570BC6D1C58F9ULL, 0x53A9AC28C50439B2ULL, 0x248DDB411565C19DULL, 
            0xF467E0BF9989F7DEULL, 0xD6995EFC9086AD69ULL, 0xD94E00BB2F85997BULL, 0x7D7A474248667738ULL, 
            0x4BF0788208D2A036ULL, 0x3A91E4BF19D0C98DULL, 0x2C1AD2E945E7E234ULL, 0xA440A57B77E1D820ULL
        },
        {
            0x0BDB934A3EFB96E3ULL, 0x3A1C9F4B1E30B22BULL, 0x152482F11E34CA3AULL, 0x82330CE4633C620AULL, 
            0xCA50515630598F1EULL, 0x95F2D8F6DEA7F3A2ULL, 0xE4D9C7A8DB9D9F15ULL, 0x2456037760E5A088ULL, 
            0xD5D08BB47CB2A3C6ULL, 0x3B254FE6FFEEB565ULL, 0xA6D836835F865DECULL, 0x18A1AA4B81DB60E1ULL, 
            0x5A69E0D56840D9DAULL, 0x71C2484782FE3A15ULL, 0xAE3D78644196C76BULL, 0x9BFD1101BBB1F4B7ULL, 
            0xA9874CF9B325ADB4ULL, 0x076FB2095C5C3286ULL, 0x4E9015AC47A90689ULL, 0x3225FC9238E41F59ULL, 
            0x868C811DC2172943ULL, 0x99034555BF98CDB8ULL, 0xE3E357D8C2AE77A5ULL, 0x0D413D7DB29F808AULL, 
            0x5B4E9F93DDA4AC79ULL, 0xB2DEDD16D3376F1AULL, 0xE6CA1110AA6A29E0ULL, 0xB9F2777940B1C7C8ULL, 
            0xCF1B416073CB33BCULL, 0xE30EC59BB40A838DULL, 0xE1B569D99F0743CFULL, 0x912B433C7B0A5267ULL
        },
        {
            0xE9B31581E7454E83ULL, 0x6BBC88142EF7824FULL, 0xC388558AF7830628ULL, 0x5D98696634F33835ULL, 
            0xD2877117483DD732ULL, 0x442E9A5C286F510BULL, 0xAFA45ED7D697899AULL, 0x23F06BD40451F75CULL, 
            0x5F2734FBC0854341ULL, 0x352E3A67DF21E9AAULL, 0x80F310B31FBD9E47ULL, 0x72131323431B9949ULL, 
            0x6D327759BA6DBA25ULL, 0xF03B39DADF7C26E3ULL, 0x465866CC53091411ULL, 0x045A6BBF3CCBD1CEULL, 
            0xC251DA62A61B20ACULL, 0xBE3B3311CA042D17ULL, 0xFF4E187F9D08DDADULL, 0x135617FC9C130E8FULL, 
            0x18E4B39318762214ULL, 0x6529C36989832D57ULL, 0xA02F437F9D3E5DE5ULL, 0x6DCF9C7A4E8D656AULL, 
            0x5D58315E649A106BULL, 0x138796ADCF41E66DULL, 0x1A6926FFCAA06E80ULL, 0x17E9469C2345FF86ULL, 
            0x73661C9AA0A5B629ULL, 0x0BCF3203065DE23CULL, 0xBBFEA08A11963DEFULL, 0x79935A8EDC09A68AULL
        },
        {
            0x0448D385B0EE9CDCULL, 0xDB06749B2B88494CULL, 0xB8BBDF962C6A9BA5ULL, 0xBFBEE66E7358B0F6ULL, 
            0xFC99481F7BD85599ULL, 0x8BE3FD6CE35DDF77ULL, 0x3BC102938598D62DULL, 0xFC2E48D2AEDCF611ULL, 
            0x51F5FB138C97A6BEULL, 0x85F7A4DAF0984995ULL, 0xA3674B3AA7CB630EULL, 0xF6706F6A2D95B009ULL, 
            0x181F89F1452D53DCULL, 0x7F51900B683CAA0CULL, 0x87F040D21DB9A333ULL, 0x1CC8A77DC837706FULL, 
            0xAADF9BF539A54A89ULL, 0x0DFCA4BE70EEC5B9ULL, 0x6FDAF9AFE862D96FULL, 0xEB9FDE13A825987AULL, 
            0x93CAC9A2AA138A5FULL, 0x85147A8150BAFF14ULL, 0xF47CC50F6E417795ULL, 0xE62C95ABD4A9D059ULL, 
            0x27561BAA45D2FB3FULL, 0x12CE9B3E1FA09530ULL, 0xED13E528B01C78B9ULL, 0xF7691BA1C3004CCBULL, 
            0x910A7E8CFE20483BULL, 0xAE648F9FDFE715A7ULL, 0xA808B3F2DC10ADA5ULL, 0x51EEEACC10A4615CULL
        }
    },
    {
        {
            0x3C0913EE2B553E24ULL, 0xE9EE13CEA50F052BULL, 0x9E3D5A0AC2B3B1AAULL, 0x9B50B1AA5E44852AULL, 
            0x8F494D332D5F8736ULL, 0x7F60A3613C25506EULL, 0xA5A79C39565EA858ULL, 0x8C00CCBA077A7178ULL, 
            0xB09C032959E54E93ULL, 0x7CB2139CD6C5C049ULL, 0x92144D351D01175FULL, 0x2E9F64BD0BF63450ULL, 
            0xFEFF9BDDBC09149CULL, 0xE0383C63FA40B844ULL, 0x8F72892C2A6B7C5FULL, 0xD33CC5917E2EE9F5ULL, 
            0xDDB50E44D45AC8DBULL, 0x4E7F5FB919C7C02BULL, 0x461F5BF7DD786366ULL, 0xBB439464E50934F1ULL, 
            0x9344BCA5FC089F5AULL, 0x972538E937AA0643ULL, 0x8605579A73BB3471ULL, 0x66CFA1FFAF93CC11ULL, 
            0x86D3FF64A503A873ULL, 0x7F221FDC98937B2DULL, 0x1D301C7CDF749D56ULL, 0xEE1ACD4919A5B7AAULL, 
            0xEED7EE8500A72119ULL, 0xCABECACF6957A0D0ULL, 0x4D2243C01792D1B4ULL, 0xC91E1F629F2AA538ULL
        },
        {
            0xCE0CBC3C39E2ABACULL, 0x577A34038561EA8FULL, 0x102436B4D87868C6ULL, 0xE6982DCBF0FD9E62ULL, 
            0x50D262F7456D21AFULL, 0xD509E211078C5655ULL, 0xB4322574566DB02FULL, 0x00671537FF4F09A6ULL, 
            0xCFE31E0DBF7969D3ULL, 0x10223D2F45F2BCAEULL, 0xEF555E023F89C7A9ULL, 0x9AE2E5D509A4375FULL, 
            0xB852D1A3D888014DULL, 0xE4CF777E3A398999ULL, 0x9A0153BCD545C949ULL, 0xA72E881C5016F4CBULL, 
            0x76A2419772386A24ULL, 0x50B457917079C274ULL, 0x2CD98DE02482CFE7ULL, 0x6D3F653E80F866E4ULL, 
            0xD819552B329B60B8ULL, 0x3DBCC76D99F2133FULL, 0x1EC9F955F6159FA1ULL, 0xD5E00D6955D2FE06ULL, 
            0x363FC61FAFC97557ULL, 0xE7617E2B6EFD6401ULL, 0xBC5C1FBE6DA40166ULL, 0x09EDE0D3667DB5D9ULL, 
            0xF80354014720E307ULL, 0xC5C474E113A6D743ULL, 0xB43855DE558AF20FULL, 0x78FCCF7942FB2867ULL
        },
        {
            0x1A5BD518F97C6062ULL, 0x79D6634ACA62CDE1ULL, 0x6B6226CCA30E4C6DULL, 0x942DF33D77900204ULL, 
            0x077B280107E89F1DULL, 0xD5E7B5B882B3312BULL, 0xC744846A3241FA47ULL, 0xCA873412193D5259ULL, 
            0xB79CD0E98B9D2BC7ULL, 0x7ED0D433A7492491ULL, 0xFA0F2C8E7898C7DAULL, 0x7B837B352CCAE676ULL, 
            0x99DA94A1C23337C7ULL, 0x3807DBCC7F30BD86ULL, 0xB3FCAA7D5F0C5685ULL, 0x00986FD5BE328186ULL, 
            0x899EEA05233CFC3EULL, 0xFFFB9DAC5C2EF855ULL, 0x28481704E5124170ULL, 0x902B9A009D4800F7ULL, 
            0xBFDF8A694DF591FEULL, 0x1F1B2FF0C2B4004AULL, 0x5D7FC912F95B7630ULL, 0xFA2F63AC3AC60D7FULL, 
            0x5010A3C58A8DD94EULL, 0xDADC49C167E8DCC3ULL, 0x1BF701545C7769F3ULL, 0x518A44A2B9C74D6EULL, 
            0xD4EABA914413861FULL, 0xF72144709B1FD215ULL, 0xAC37250F5666866DULL, 0x3A89471A3C491860ULL
        },
        {
            0x3CC39922F2625469ULL, 0x8E2629E84FC94DB8ULL, 0x2B5DC4080B68D601ULL, 0x3078966AAD5A86FBULL, 
            0x3F43BA8CE309736BULL, 0xCB06DBF5571A19C2ULL, 0x91851F156448A1ADULL, 0x9F052B58A88F0AB2ULL, 
            0xCB8C422C3C6065AEULL, 0x8591C6DDABDEDC8CULL, 0xAF2CDC5AE7348C66ULL, 0xA4B2042C473D3CC1ULL, 
            0x96FB498F18CAC079ULL, 0xC95D2DFA29FBEC85ULL, 0x728CF04BB8686396ULL, 0x3AE9AC79C7272C5AULL, 
            0x485E834D25B5F53AULL, 0x6465959A6622B6C9ULL, 0xDF21FABBA56FD789ULL, 0x31B07717DA7C5C9FULL, 
            0xA65627196EB833D8ULL, 0x98A1CA38C300AA2EULL, 0x622C05282D4E88D5ULL, 0x12401AE192A720C1ULL, 
            0x3C633DEFA1CE3350ULL, 0xA9D2D2504663019DULL, 0xF76A1F0675CA658DULL, 0x931764E6CB4E8804ULL, 
            0x36FDB74EC9EE3A0EULL, 0x56AA89A8FEDB86E8ULL, 0x5C9F5870AF61AC90ULL, 0xD5F738C248022804ULL
        },
        {
            0xB32CEBC1D00610A0ULL, 0xA8D2CD424B33AFD6ULL, 0x12172C7B78710D95ULL, 0x78A0299C97058B87ULL, 
            0x1F94A262DC6697BDULL, 0x248719D741462FCFULL, 0xD25FE023AC0008AEULL, 0xB2EBA4E47BF484BEULL, 
            0xF8DE9B694BA5DD10ULL, 0xFE1467C51B3053DBULL, 0x9DCE6E0A3B971DFFULL, 0x29114F00645CCB30ULL, 
            0xA3B0AC65948F5CCCULL, 0xC0033FFB970B3C54ULL, 0xAFFC519AA6CE2CA2ULL, 0x308C5B30A22122F6ULL, 
            0x278F7F8EF4E2411AULL, 0xE55019A46473823EULL, 0x5350B519394E6AE9ULL, 0x2C8801CF843625E3ULL, 
            0xDFEEEFB0601F760AULL, 0x2B8E5FF1E95DF5B7ULL, 0x9D5CDED707516F6FULL, 0x5DC6C07DA727C665ULL, 
            0xDAD02DA861DCCFEFULL, 0x21CB69A46F21F41EULL, 0xDF4DEEAE6B4DE14BULL, 0x1ABA1F76E896B634ULL, 
            0xECCA76D050D130B0ULL, 0xE40363043F79E252ULL, 0xD4F1B91F2213E831ULL, 0x03C6A9E92A292BDBULL
        },
        {
            0x681C94B472039E0FULL, 0x72EFE9D86D040A54ULL, 0xB3CB2670164E5AB5ULL, 0x9BCBF07587DA4DDCULL, 
            0x6A4147478D948CD0ULL, 0x7856662DA2ADD71EULL, 0xE1BD0BFA2805950BULL, 0x7C55199BC7652CE5ULL, 
            0x85CFB36BAC715DBCULL, 0x0F1511A94DCB2093ULL, 0xEBA00AC022ADF1EDULL, 0x4DB1361183FE8C14ULL, 
            0x86F454070169BC55ULL, 0xFD70614DB6267CB1ULL, 0x75F82AFAAAACF35AULL, 0x6A1BF78441CF8522ULL, 
            0xB7746080877AA095ULL, 0x8D39F6A19634E33EULL, 0x52B767CE71669BE6ULL, 0x8E699402899C74D9ULL, 
            0x5ACFED46589A7087ULL, 0x7631E7277A1A07E2ULL, 0x9F6E8C87D65970D1ULL, 0x608B57D306A120C3ULL, 
            0xCFFEBBB0C8620D44ULL, 0x647366BCE3740368ULL, 0xD2D7D987B8936438ULL, 0xA5FECEDB029DB4A2ULL, 
            0x01B688ACD3A5113AULL, 0x06E7533CE34CF4FDULL, 0x2CAEBC5B11445BC9ULL, 0x3F3C653BC89D10F1ULL
        }
    },
    {
        {
            0x24B694E936426B09ULL, 0x3D25CAA39151A706ULL, 0xA45441D84DBAC4D6ULL, 0xD6E865B81733419BULL, 
            0x2A81D1A60060B2EAULL, 0x16FB47DC195C52A2ULL, 0x8F7B24E45958F743ULL, 0x3EA2F094F8B1B1DCULL, 
            0x29F439B9DF203A90ULL, 0x0AE4A87DF347D276ULL, 0x31C51FAC03B23713ULL, 0xFBBFF3840936F64BULL, 
            0x9C22CE2355EC6283ULL, 0xB937B26011643FACULL, 0x287FB63CF3E35DA2ULL, 0x4D8158F8C59E4BB8ULL, 
            0x8FD8A676240791F2ULL, 0x4BD5B2A607E28F95ULL, 0x42AFE7231B82F85FULL, 0x29FB28387DB8ECF9ULL, 
            0xB85AA223A7CC075AULL, 0xA8B12B6BA149AA1EULL, 0xAD1BE9254CF39F31ULL, 0x544945F7FAFD1619ULL, 
            0x640FC32542BAE5D7ULL, 0x57FE836BD3B1420CULL, 0x14464AC462D42D86ULL, 0x0757CAD90762EBC0ULL, 
            0xBE980D5E3B5934CEULL, 0xCF1CC25CE7CD9080ULL, 0xEC8E86EBA18B19BCULL, 0xBA2901FE6F246604ULL
        },
        {
            0x6FE82851FC3AEC5BULL, 0x9BB1C7C77BC5B466ULL, 0x76B368E67E76088BULL, 0xC7B08A668548F877ULL, 
            0x046E4623935E3825ULL, 0x574A0BDB88D7430BULL, 0x2DD7B25396DE3175ULL, 0x9E5BC976DFBE9E21ULL, 
            0x8D2966AD96FE1E91ULL, 0xBC0B26BEFC3E4813ULL, 0x051BD41ED8F0475BULL, 0xC69159C840EFDEB5ULL, 
            0xEECF7C5A0B79133BULL, 0xB566136B16E84BFFULL, 0xB5BFF65B88E188F6ULL, 0x1FBEA452CA58FE59ULL, 
            0x51D919909BB76D1BULL, 0x5D73D0AAF9AC9952ULL, 0x8D5B9C618F899696ULL, 0xD8289EE44BF8C1DCULL, 
            0x73894F49208BD55FULL, 0xE54A32E5EC5A313AULL, 0x76502B8CE48D0C3EULL, 0x68FBD09ABBEBB135ULL, 
            0x6FF491AB4907D90CULL, 0x5C354C05032ADB81ULL, 0x7E82CC951EDB9D73ULL, 0x64545D01617F46F9ULL, 
            0xF75215D8AC3D09D5ULL, 0xD65B4C0DEBE5A635ULL, 0x51D0D4E48F49491DULL, 0x315118439C3F3BE0ULL
        },
        {
            0xEA51A297B53D3BF3ULL, 0x2A5903186A5225C1ULL, 0x109EBF3D9E91BCA5ULL, 0x737F238B7C6AE775ULL, 
            0x4B5E4B100C54B49CULL, 0x83A384A83CF2685BULL, 0x7AA905B1C48468AEULL, 0x3C5B978D821A450DULL, 
            0xE76FED4239A2C4F5ULL, 0x6443A6A5DE923165ULL, 0x2EFDB7A26E097A84ULL, 0x3A5930ECA7312E6DULL, 
            0x0F82906349EA766CULL, 0x24058DB70393F061ULL, 0x42F20586661608A5ULL, 0x3EED554C1D70D2D5ULL, 
            0x2638BD8BD1DA5DF0ULL, 0x2EF508EBD7C2840FULL, 0xCFC622C66BC18618ULL, 0x61285C57B1FC90FFULL, 
            0x9E540499CC8135E1ULL, 0xAB2C14240EAD0C8EULL, 0x645457B82C3BFF99ULL, 0x01A8390B559A959BULL, 
            0xBA9D690780AC169BULL, 0x088F2BAB37072D89ULL, 0xE4571539FE39C103ULL, 0x3CDB05AA9ED7ADC2ULL, 
            0xB4E470F37DA26911ULL, 0xD9686821654151C9ULL, 0x4D22EC86245B5AC8ULL, 0x86582BBECEE5624DULL
        },
        {
            0xDC422DA07EF6097BULL, 0xDDC22495A3329F73ULL, 0xAC7108EFB454769CULL, 0x54EC799AC143244EULL, 
            0xD56A9F37699240D8ULL, 0xF09B80CF0500109DULL, 0xE87E4E4C7813786FULL, 0xAD4330E1C372DAFDULL, 
            0x4239624AF5AEE9D9ULL, 0x357D3F04ADBCBF4CULL, 0x3A53373ABCE1CD48ULL, 0x11B183F98086FFF2ULL, 
            0xA2A68B35BDC08CE3ULL, 0x0592CDC634C09894ULL, 0x23E63A11F9326D1DULL, 0x52AE084D5741E28FULL, 
            0x0EE14C76C25BA309ULL, 0xC56B5132C359136CULL, 0x1DA3945961602E80ULL, 0xEAA821FE9570CEEDULL, 
            0x7ACD3415F49B6243ULL, 0xE89E388A8FA494F0ULL, 0x466B544AE9FF361DULL, 0xED03AC45E1271EC7ULL, 
            0xB1B353FBD0DB14C3ULL, 0x7D60D4ED7BABA38BULL, 0x65CABE3862C03276ULL, 0x307B5B319F0B475BULL, 
            0x559E0E691874B48AULL, 0xD626C128D8437F13ULL, 0x495A5D51AACDDE43ULL, 0x769A8D824AF4D3FDULL
        },
        {
            0x2C60537FDD035F41ULL, 0x2E968809FE5CBEFBULL, 0xE046B797F2C192D9ULL, 0x0B8EEDC1926FD5F7ULL, 
            0x26515282FE0BE296ULL, 0xE898C387C3122338ULL, 0x52F1417E207A1C49ULL, 0x3060227597A632CDULL, 
            0x9D60AF32BCB562C2ULL, 0x861D4E04AFB05151ULL, 0x8866C0E5753B4F78ULL, 0x1D7A1D95EF533A3AULL, 
            0x2E138CDB21F2CA6FULL, 0x0FF44FC26979C2D5ULL, 0x8A14926FDEF2A69BULL, 0xD5CFE78FD00290DFULL, 
            0x97DED9C1F8D1ABC9ULL, 0xFE826718B880890EULL, 0xA8920FBBBD119FC9ULL, 0xD7965F2C07DF6E21ULL, 
            0x69221FC8C36E0413ULL, 0x9B28E6F510A68488ULL, 0x76A7DEE677567766ULL, 0x12B840B1B5ACFA8AULL, 
            0x7D74F09BCC685A21ULL, 0x75027B9089FB5414ULL, 0x05831E4AB6A1271BULL, 0x83FFA10AB368E53DULL, 
            0x3A08D137E3165617ULL, 0x5FDEC01798BB7DB3ULL, 0x16A7AD6C1EFBACAFULL, 0xCCD8DC1F82AABC49ULL
        },
        {
            0x70F1DFDCE8C54277ULL, 0x758641A4EE581D02ULL, 0x6E4E5CD4421E48A3ULL, 0x4C559CCB4D47C92EULL, 
            0x1921D6D08AA4E05FULL, 0xC54A7F1E14DECE1FULL, 0x2384CC9A27E2891BULL, 0xEAC037486B12697BULL, 
            0x45F2A705289BF66BULL, 0xF3A58CE29ABFD991ULL, 0x91F88A298523FF15ULL, 0xE436AD6F64011B79ULL, 
            0x08E88946429B1086ULL, 0x8DD07A0F2EE865EBULL, 0x33F67C9C8592DF0BULL, 0x73596054DA172600ULL, 
            0x5217AA87E3A9649AULL, 0xA8A4C73D357B2EF8ULL, 0x6D1E9F705989EE8AULL, 0xB6A5D0C665412474ULL, 
            0xFEA597A3B3176C94ULL, 0xB977768BA65DEC77ULL, 0x22FBF91D6B667B51ULL, 0x81F17CD8B556302FULL, 
            0xE22FB30DFD51343EULL, 0xDD621CB3ABE17EE9ULL, 0x64742EED2B75C5F0ULL, 0xB40FE451F9EACE0FULL, 
            0x212CDFCA62C09DE1ULL, 0x35454FE2DAA68716ULL, 0x11D6808D1F81695DULL, 0x156C2641CC2FF224ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseEConstants = {
    0xC6AB1C5D3B4A77AAULL,
    0x3145054D9E68778CULL,
    0x8F7A3ED21DB3DEE2ULL,
    0xC6AB1C5D3B4A77AAULL,
    0x3145054D9E68778CULL,
    0x8F7A3ED21DB3DEE2ULL,
    0x1B878D0EE5F91B50ULL,
    0x3FA84A23B9572D8AULL,
    0x3B,
    0x55,
    0xEA,
    0xCD,
    0x27,
    0xC4,
    0x9B,
    0xA4
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseFSalts = {
    {
        {
            0x6EB73D1E8A2AECDFULL, 0x7D1AE79784E174B7ULL, 0x8A025158D2000D0BULL, 0x25ECFBBC0FAEB476ULL, 
            0x79ADB24171AB1FDBULL, 0xEFBEEDDD4C2549EAULL, 0xDFCB004FEAF2F5DEULL, 0x77C5CB41E8FDAC02ULL, 
            0x42E5013802BF1085ULL, 0xCBCD42E9D99006C9ULL, 0x89061B736591D73CULL, 0xD175961E24CAF7B2ULL, 
            0xE54F6ECF9A8224B5ULL, 0x66CFEFB34A3CDBC9ULL, 0xBAF0EDF4C5CA9DD0ULL, 0x597D5F4B7649E6A8ULL, 
            0xABD1FC3FB70A36C8ULL, 0xCA7DD1B1F222C048ULL, 0x13C228CAE992043AULL, 0xD3CC1F8F17C55CCEULL, 
            0x01F98DF89F2655FAULL, 0xF17B2A9A9F5E5C05ULL, 0x1172BBD71951927FULL, 0xB6CE81EBF33AC61CULL, 
            0x25AA54A06E99A013ULL, 0x9163D5437F12351FULL, 0xA16171E30C567BDBULL, 0x7328308BBD655FBBULL, 
            0xDFA9DCD61FC6EE0DULL, 0x6DC453A106F6FBAAULL, 0x44386666BDC71E9DULL, 0xF4A44EB68C85793EULL
        },
        {
            0xE678A866D7859F01ULL, 0x7F82A0202D73A63DULL, 0xDC45C3406743E8F1ULL, 0x6A4E6AB294BAEBE2ULL, 
            0x8005B2040FD69FA7ULL, 0x83F98B16B32838AAULL, 0xFC9429374AC66986ULL, 0x1D7965F6ADB118D0ULL, 
            0xBBDDD88A5BAD96FAULL, 0x9DA59E1BA7230DECULL, 0x632FB74D8B5D9EB6ULL, 0xB22F745386E8256FULL, 
            0x8828DF45E4821657ULL, 0x098B0EC9766F6BB3ULL, 0x1B15E7D462847892ULL, 0xD3C7D87448C047E9ULL, 
            0x751057BB0410D5D4ULL, 0x5E563362FDF0BC9DULL, 0xF5D4D7B86D19F922ULL, 0x9D935B8C85EF1766ULL, 
            0x82F7351C7CE8E091ULL, 0x66362452B44FA98FULL, 0xAB8A917E09AC6655ULL, 0xBEF00A4B109C4BE9ULL, 
            0x9BE73CDB01FFA0E3ULL, 0x9C8F12BACF3A92A9ULL, 0xC9C75C68CE27A49EULL, 0xB39A61FC9292C77EULL, 
            0x8FE745FC0DB39B98ULL, 0xCCFE88D1F36B18CAULL, 0x08E1736AEB635153ULL, 0x58D10C4D4367546FULL
        },
        {
            0x0CD91434A597A4A0ULL, 0xCFBDC25AD9E1B91CULL, 0xACCF58F7F351944EULL, 0xA7E0BBEA1662238CULL, 
            0x9F497C1FAEA325F8ULL, 0x8B680A678D4E4065ULL, 0x6FCE8FC4A3A5D379ULL, 0x20E663CF9BD9FD32ULL, 
            0xA849E8BF7BAA1FEDULL, 0x4C944D13C93423AEULL, 0xA22EA909ADCB7AA0ULL, 0xF5AFD82C476FF23AULL, 
            0x7E83403EAFD60629ULL, 0xF9656FE749003F8AULL, 0x3878E061B3387E15ULL, 0xBD56306691AFCB38ULL, 
            0x84ACDF6D6FA5B17DULL, 0x8BF795715ADEF2EFULL, 0x1760AF68AA7D3B92ULL, 0x3F21A916DBB04052ULL, 
            0x5B7C2C323CA2A300ULL, 0x055B3C6DC27C0B0AULL, 0x6277A129806050CEULL, 0x5154BE74A69D6D18ULL, 
            0xC1ED44BEABF47D7CULL, 0xB4A46ED56AA8A8E0ULL, 0xF97E2029B397F7E7ULL, 0xA508F6A67886B3B6ULL, 
            0xF54EDCFB4A654D30ULL, 0x19EAEB0BF4AB3517ULL, 0xC7F05E29C68976A5ULL, 0x2B5939F54521D3B6ULL
        },
        {
            0x12AD95C5D46F4F90ULL, 0xB4F30DC261FFF37FULL, 0x14239D8E138BD366ULL, 0x2204BF451FCA26CCULL, 
            0x99C4D801D1F3560CULL, 0x93AB3B4E51C27ECCULL, 0x907F967A9643AEDCULL, 0x1E4E8373206BEC56ULL, 
            0x1E87295BA6D35795ULL, 0xBCCAA826BC28C6F0ULL, 0xB242F7394969FB59ULL, 0xF0424EC89EA5DF55ULL, 
            0x3EBCF0A6B6EC29F4ULL, 0x73C3CC68FDDAB3BDULL, 0x4CA629A6F1941088ULL, 0xD93D38BDAC3CA7C0ULL, 
            0x82D5C80311769BA8ULL, 0xF07447D0028F8FC5ULL, 0x5D5C1DD3D2C828C8ULL, 0x56F9EE4FFD76C46FULL, 
            0xCE63AED96716D494ULL, 0xA20F99EC791F2F8EULL, 0x30B31D5D5DFCF987ULL, 0x7AC0AFAD771D4FFAULL, 
            0xAFC3A71F0F4CF81FULL, 0x4BA3EC3457398710ULL, 0x5D3F6F8EFFD756CEULL, 0xAE87712364DABE5BULL, 
            0x452A6D5E8F22F503ULL, 0xD3FDCAF298BFBF60ULL, 0x9CC216424E349959ULL, 0xDB9810B512E5ACC7ULL
        },
        {
            0x458EA6C89E6F8B89ULL, 0x7168F693EBB90D7EULL, 0x406B839B76F4A480ULL, 0x630C00B5EDDA7C6AULL, 
            0xC388FCF80BF407CBULL, 0x36C010FF68CFC845ULL, 0x59B43A6C5F4707A2ULL, 0x987DF9844D0AEBEEULL, 
            0x2373C69B386C62ECULL, 0xE6DB4D7E86147190ULL, 0xF8DB9A165385AE18ULL, 0xBAA130EA2DFD43E9ULL, 
            0x59BF2C0DB5DE8F5EULL, 0x3973C2A15809CCE6ULL, 0x8BCF9D828EEF7EF8ULL, 0x2D923E875E3D0234ULL, 
            0x6E88FFEB8CD07B32ULL, 0x1398D48862F9032EULL, 0xDDD9955078915CB4ULL, 0x1F0CC11FD6CEC7BCULL, 
            0x134EBECE9C336D8CULL, 0x0C52E43397BD75BBULL, 0x8AD61C5785EFB4BDULL, 0xA0C6D7F30AF1104AULL, 
            0xF5ECA4E356E9E8B0ULL, 0xDBA59E9A14DEA268ULL, 0x8F2A808FC74B81BAULL, 0x63A1EC6DA6C31A47ULL, 
            0xD6A609B9F6BAA53AULL, 0x7139BB3A10685FC9ULL, 0xBCA5169E60A948CEULL, 0x76ACD113CAB2EDDBULL
        },
        {
            0x95FB8322DE558C67ULL, 0x587D8662EF9CF7BAULL, 0x1349A5597BCE71FFULL, 0xEB0A29599EB25130ULL, 
            0xF3113E9E5D44370CULL, 0x02328CFAC834CAE1ULL, 0xDFA0161E9A69CF7BULL, 0xB16E47A883E5AB9FULL, 
            0x7E4EC270E1FCEAB0ULL, 0x9EEB3360F5C3C07AULL, 0x5E857908B3DCA3CCULL, 0xE6A243B6A7DA4829ULL, 
            0x6D48A907BCE0147AULL, 0x642AC4D606CCC81CULL, 0xE1F5CFD62170FBD9ULL, 0x9C8896F981CAD668ULL, 
            0x41A7643BC1700B20ULL, 0x9B7EBEBBA2A0A230ULL, 0x0EF76D77F4B698DCULL, 0x08A1E478C6225102ULL, 
            0xE9E8942310A34E89ULL, 0x301598917FE0DE65ULL, 0x77E4D307CD5E315FULL, 0x96D836500199B0ADULL, 
            0x5359BDE88D555FF7ULL, 0x4E4ADAFCB6ABCEBCULL, 0x7441E7EC3D37FB40ULL, 0xEF27B235A4309D9EULL, 
            0x127EF24BD3D06DBAULL, 0x1DE2A7004A756109ULL, 0x1C9ADE5516D535CBULL, 0x81F2FA0BEFFD4286ULL
        }
    },
    {
        {
            0x91F16293B77D04C7ULL, 0x867941B8BF073337ULL, 0x84745EC25C6495E1ULL, 0xC03DD5A238B1F0BCULL, 
            0xD96D0760923273F4ULL, 0xAE89F414FC305AA1ULL, 0x0085AF7B019A7A89ULL, 0xB6CE0BC289161D05ULL, 
            0xBDC39D51918A92EAULL, 0xE84DC82F5F838AECULL, 0xC49FF054FAB83AD3ULL, 0x99271DD5F7A48EA0ULL, 
            0x0D92EF6125A1E1F0ULL, 0x70E6C15F966F3340ULL, 0xE620D41547922C97ULL, 0xA6C075E98A294D71ULL, 
            0x6573411D1AF18359ULL, 0x3B52D2368F2CF213ULL, 0x200490A72F6A0FBFULL, 0x3C14B46D237F3CCBULL, 
            0x4AA7876F279B68F0ULL, 0x90279BC5EE1A2028ULL, 0x317E5A0E4C1B722BULL, 0x669A34FBC4F7F3CCULL, 
            0xE6C44D83D1ABDB75ULL, 0x9758DA32C4DBA86AULL, 0x1251C320A0E0B9FBULL, 0x8EF91ABD88E0A30FULL, 
            0x616ABC26D98570E2ULL, 0x3693F2D52B06D410ULL, 0x003E7199EF52DF64ULL, 0x5401C08C247E6638ULL
        },
        {
            0x6BDED2F66226838DULL, 0xDBDAB0FAC1480E1FULL, 0x11D71A753E7C4BBCULL, 0x194D53CE95AFBD89ULL, 
            0x6E80AE209430B01AULL, 0xB7AD434F2B00ECA1ULL, 0x9A118F6AFA534C1FULL, 0x84C6D7A81AE4A18BULL, 
            0x311C43C2CB3E3C7DULL, 0x35747EF082D43ECAULL, 0x082305037736A0D6ULL, 0xA4D03F17F2D4F4BBULL, 
            0x7A7BA0E03E11B4F2ULL, 0x43F8DF668AE84AC3ULL, 0x94F2830ACFE47D1DULL, 0xE856A4C3C64B9D01ULL, 
            0xD5278622BFCF86CBULL, 0xD7DBA2851356BF7BULL, 0x12868596C40DABBCULL, 0xF4140C3D2CD558AAULL, 
            0x51C78C45CD29E270ULL, 0xCD4CF54D7F7C7F40ULL, 0xF1482077A2C2D252ULL, 0x403A36A450C7B8A2ULL, 
            0x3BF3E01FCC30A18AULL, 0x2CBCFD72AEEBAB91ULL, 0x307B47F8DDE7F486ULL, 0x39B069B38BADE1A7ULL, 
            0xC221D2DB85683281ULL, 0x1DA6BBEE56E35A92ULL, 0x756787F7423DCC46ULL, 0x19C520874CCAC56EULL
        },
        {
            0x8B705858E2AE7CE0ULL, 0x1BDDE1E95C5F7B9AULL, 0x3E7DA98A563539CCULL, 0x39D6AEF798031FF4ULL, 
            0xDB7AF5ADA86D300EULL, 0x4BA96D2C5CD87FDFULL, 0x4F46F4F620E23C8BULL, 0x40DFD38C1FD0A57EULL, 
            0x3675D17FB3EDE4B7ULL, 0x80C023E8B90281BDULL, 0xED560330E36EFC64ULL, 0xDC00999B24BC7ADCULL, 
            0x3A2BAF6CFB52FE7EULL, 0x941AB9B579C630E6ULL, 0x25449D44DDFF8DE9ULL, 0xDF1C043AA2F7C453ULL, 
            0xC80D885A4D35BD0DULL, 0x27042C1A00AA75F9ULL, 0x4CCD7A72D81DE36CULL, 0x665BC306820BCD26ULL, 
            0x468409C196627B31ULL, 0xFA209268A29AA0ADULL, 0xA5E974010CCD95C7ULL, 0xF93C953E2614D381ULL, 
            0x5AD2675E2BB7DBFFULL, 0x54BCA37A8F75B343ULL, 0xA66DFEE7B21E9309ULL, 0x0BEEA673BFCB127BULL, 
            0x7F83D760C5AD252AULL, 0x5328177E2F548F17ULL, 0x3BD99F2A42BCC624ULL, 0x0A1F441D52B269BDULL
        },
        {
            0x68474A4B0A7FB220ULL, 0x5D01EA8612B8B3AEULL, 0x3AB811A5965048C3ULL, 0x1447E0C0C4BCDEA1ULL, 
            0xFC52F8E71A350560ULL, 0x899D5340D40A4A87ULL, 0xB373CF8AE6F38610ULL, 0xEAE8DD29D15C5B4BULL, 
            0x8290D2A34DE79C6AULL, 0xD5DEAF5096C34F8BULL, 0x14E9B3E52A18338FULL, 0x213D1337B5CA4FFCULL, 
            0xAD583106EF4E269DULL, 0xEF446C7F5D02F66DULL, 0xAD752E1D9E6B7B5BULL, 0x6EF2C49DE6F39404ULL, 
            0x987DD2B8BA972028ULL, 0x19D1C9686ADFB93CULL, 0xCE24D000B422517FULL, 0x2572CCA15474E185ULL, 
            0x378966FC982DAA0DULL, 0x5ED6D162D7D64110ULL, 0x435682EB3369410DULL, 0x46BBCA08EA4912B5ULL, 
            0x58F979B14650BDEEULL, 0x98018142A8150FF1ULL, 0x492BC59FD20FC8FBULL, 0x49CEF5A5209EF26FULL, 
            0x53CF46FC848FE2D4ULL, 0x035276F50177D47CULL, 0x9968C96762F6E1C0ULL, 0xB90CDE6AD529A0BAULL
        },
        {
            0xF69CF8EAB4083B33ULL, 0x136B5356C93D6B9BULL, 0x2659DA8DEDFE4D85ULL, 0xEB492D7509714F13ULL, 
            0x07CD2CD49D8864AFULL, 0x7CB68B84C3160769ULL, 0xD7CA1E10B68CFA7CULL, 0xE49B276087B386E2ULL, 
            0x4AC1A727C0903584ULL, 0xA675D4B24347C4F8ULL, 0x5E3677FB5E28579BULL, 0xF041740FCBB6304AULL, 
            0x478B194D25CF2F0EULL, 0xBEFDB07EAA6A8E84ULL, 0x758B7B6AC55A0988ULL, 0x0948ECA5F1FCAE3CULL, 
            0xC84A02F54AEB5A8FULL, 0xCD520A14B622F875ULL, 0xEBAC1E39C94D781DULL, 0x308D50C4B784572EULL, 
            0x560078CDFF90AB5FULL, 0xAF42D088D969DDA2ULL, 0xFF8FA3314684E6AAULL, 0x137FCA2C288DEBF0ULL, 
            0x8748362A079BCD0EULL, 0xB70146CEE965F026ULL, 0xA3065AB09A37A34DULL, 0x4FC07E177C8C7B50ULL, 
            0xAC38C33C59A97ADFULL, 0x33B6D348E1D605C6ULL, 0x3E9F088EDDF293A5ULL, 0xF3846294A23B5FF0ULL
        },
        {
            0x2B848A52B8849CEFULL, 0xB2C91532FAAB0079ULL, 0x0CDBD99E0F36C91DULL, 0x609B87A0C6F8DED3ULL, 
            0x50A0BA7EF5CACAECULL, 0xE056CE86CC4E2968ULL, 0xCAD6D0C7E00A507BULL, 0x048023BF99416E8AULL, 
            0x4F4EC40871E8EE2EULL, 0xC7CE44E73609F38DULL, 0xC848B9FD365EFED3ULL, 0x1372651DB515C409ULL, 
            0xAD44105E20EBB996ULL, 0xF512BAE6C2B7794BULL, 0x0BF7D1D1F42F4351ULL, 0x4B4CC72D2D38BF4DULL, 
            0x373B54BF2C5DB019ULL, 0xDD491BA69C971FCAULL, 0xE3F16F44F319189DULL, 0x917774C2D08D6E92ULL, 
            0x984E2C28E36BC526ULL, 0x33FDC1EBF7E705EEULL, 0x11CC8F6E24E05857ULL, 0xEE582FBE6B9A38C8ULL, 
            0xCA5568B7840DB408ULL, 0xAB829275C742EA2CULL, 0xC01A117548CD6FF5ULL, 0x1A60A3057BCAD0CFULL, 
            0x69EACD17A3BAAF2DULL, 0x813D2B0C5A113882ULL, 0x519134B6D0A5AB80ULL, 0xA8ACA2EB92980379ULL
        }
    },
    {
        {
            0x2479B6505691B751ULL, 0x91BBE79D062F0C39ULL, 0x2521AC5A9E62F27FULL, 0x29E44A267A9FF2CEULL, 
            0xD08EE416D54E7EB2ULL, 0x13F4E0081CDE1442ULL, 0x94FF233914881EA4ULL, 0x7FAA14C450946141ULL, 
            0xBE1CB75361BA7FFEULL, 0x945513B29966C03EULL, 0x909AA44F6C049911ULL, 0x84BE63FD17EE3D4EULL, 
            0x4CA494E2342E040BULL, 0xDD2B457A9FA873D6ULL, 0x593F8B8866A7097EULL, 0xAD9131D86FABED46ULL, 
            0xFE44CCD3521EA805ULL, 0xCC3BF4A49A54BF3CULL, 0xA94274B11A83394BULL, 0xD3F217F3E3E88B78ULL, 
            0x62213AE4CFBBE3A8ULL, 0x96B8F62C63AA833CULL, 0x1362DF2FA3D344C8ULL, 0x43B63FAC318B2A46ULL, 
            0x8E3640C4E51B8650ULL, 0x96DE76DFA9BDA0ACULL, 0xA6245BFE1904345CULL, 0xB8C71CDB34F6EAB2ULL, 
            0x0596CD71325D4E95ULL, 0xD52DACE3B4FEF4C3ULL, 0x722DE523E9A8E581ULL, 0xFB58C7DB6F519F43ULL
        },
        {
            0x0D47314D56BDDD0AULL, 0xFCAC8F69515BCB5CULL, 0x5DD1FF43DF4744D6ULL, 0xFEF5755A512B074AULL, 
            0x4A6B7CFDADAE3793ULL, 0x02477313E04A5656ULL, 0x4FFB3486F671BEEAULL, 0xEED8F6407B5A6F80ULL, 
            0x63FB8CB7482F8ED6ULL, 0x9A8F58B9CD8C8247ULL, 0xDD0E8C9A8C771AD5ULL, 0xCED5F427F8D2E0F2ULL, 
            0xD42ACA306659AE86ULL, 0x60A29C2250F37389ULL, 0x84C45DE88117FDBEULL, 0x45906C60AC88ABE0ULL, 
            0x684770786456AED7ULL, 0xDE4EB0CE7D741B1AULL, 0x0CB4D000E452727BULL, 0x8ACFE514F9B3BF65ULL, 
            0xF454601752C21703ULL, 0x371CDDB4633596BCULL, 0x50AA5702F0EC5385ULL, 0xDFD30F5D78637C5AULL, 
            0x312F82C5501FCF7CULL, 0x1C722514EA0401F4ULL, 0x582136FCD73B4BF9ULL, 0xB00C37769B839A3EULL, 
            0x931D885DD1D6F8D6ULL, 0x32EFA122FB423EDAULL, 0x154C567678413C37ULL, 0x34B438EF527E17E0ULL
        },
        {
            0x6F7B024CD9199809ULL, 0x877715B81030699BULL, 0xF6212CCA3E39B9C5ULL, 0xD8957D95B19E7704ULL, 
            0x6FE3622358A945B0ULL, 0xF12F89523DE85F28ULL, 0x9C1778F9DA952B57ULL, 0xDF508FED7DB7B37DULL, 
            0x0EBDC083E7641C1FULL, 0xA52D5FFDB3FFBFDEULL, 0xB62F1263DAEACD66ULL, 0x17312300C545EF99ULL, 
            0x12D7316CBADD6C44ULL, 0xCEB008D8D1F377D9ULL, 0x2F9CB1C011CC7851ULL, 0x6452DC961FEBF48BULL, 
            0x5D07DA7CDBC08D4EULL, 0xEA9AE3701F8B8FD5ULL, 0x53C5DA4DE73C530BULL, 0x9424A57DE1C55E0BULL, 
            0x3C9D282F91C92570ULL, 0x9C9DB0F92A69AC0BULL, 0xAB34005B978A8F70ULL, 0x99CB21A3A0D3BCF4ULL, 
            0x062990BA7A4EDD61ULL, 0xBD6CF8DE1ACD9544ULL, 0x726CB55FB8D7B745ULL, 0xFD1720C47DAC0754ULL, 
            0x420E34407A7A8AEFULL, 0x4C3125EFD7DD3AC1ULL, 0xA4A1BB34150D1B2FULL, 0xF71B3668414F4F94ULL
        },
        {
            0x99CCE9A2F4C2FBD3ULL, 0x17F47A094FB73304ULL, 0xDD26AA7FDEBEFF98ULL, 0x227CB8578CE791C5ULL, 
            0x0756B8CCA5ABB5CDULL, 0xF95D88CD627C25B4ULL, 0xEE77C95DA00FC8BCULL, 0x87DB06FAA087AC2DULL, 
            0x73CEA5578B36F05FULL, 0xA0FD4F64DDC200B5ULL, 0x2B972A3466864D82ULL, 0x36AE5E06CD4B4733ULL, 
            0x3319FFC0BC9A600FULL, 0xCAD05F7EB5328F93ULL, 0xF79958ADBBA14093ULL, 0x4025270AEB0EF2C6ULL, 
            0xB9B0F6757FEC847EULL, 0xBA62026958E44C0DULL, 0xBBCD3560F7C6A063ULL, 0x3C5F5AD35C4DDA09ULL, 
            0xD0CBD313A917EEF7ULL, 0x88FEB40A3AF212F5ULL, 0xD7864BA4BCC2F918ULL, 0xB9C42D298443318FULL, 
            0xF3D30BE32259B171ULL, 0x71C47443C9F3ADFDULL, 0x13A753522369FF2AULL, 0xE18E50F44BF89A5EULL, 
            0x882B0CEC5F51FF1AULL, 0x2ED0C21457503F18ULL, 0x4110E6D44ECDC951ULL, 0xFE58664ECA9185ABULL
        },
        {
            0x3D686301F3331E58ULL, 0xE6041A956D702341ULL, 0xE83C1200BA9FF906ULL, 0x748A170EDB75F40CULL, 
            0x39BE62DEAE97D32CULL, 0x97402448A7606223ULL, 0x5F12243C1C15C979ULL, 0x563C2A810DEAC499ULL, 
            0x98E663361E5C0736ULL, 0x34BA0A030DF7AD96ULL, 0x9B283768259A448CULL, 0x472EEB4ED7060671ULL, 
            0x57BFB4FB6D627053ULL, 0x1918C2CA8E7FED2BULL, 0xCDB008F0E85C2BDAULL, 0xB3AD1137509562BBULL, 
            0x3FE91FF7CB86AE0DULL, 0x2DAD312076290BB7ULL, 0x140438880BFEED1CULL, 0x658CBDA227665EBEULL, 
            0xAF490342C61E0118ULL, 0x28B6BEB6744A12AFULL, 0x16BB64F6C06C7C76ULL, 0x5869BD663DE6F4CBULL, 
            0xE45D411C36FB6F65ULL, 0xF1B4FB16D98EB9FBULL, 0x30ED1B61B3DD5D77ULL, 0x76D9B99ED6099175ULL, 
            0xEA1C643FE99440E3ULL, 0x3FEF913BBCE6EDEEULL, 0xBE68099A07284BC2ULL, 0xFF931E1725CDFC4BULL
        },
        {
            0x47CFB199E0155559ULL, 0x52940FD2CE79D15AULL, 0xB0BFABFC6F649ED8ULL, 0x05CC93CAE126BFB4ULL, 
            0x9E1384D8DCA51C19ULL, 0x78A2F45230ACE81AULL, 0xE7674F0FC8D8920EULL, 0x08738EFD153EF00BULL, 
            0x014EFA0504F3BFFCULL, 0x13E16F774022BDC0ULL, 0x87E6F12671CAEDDEULL, 0x9EDB9316EAE15358ULL, 
            0xE2D67D2E3525F846ULL, 0xF157EABE62FF48F1ULL, 0xF9587BBDF799CB32ULL, 0xD2D0DF14EDF0D1B4ULL, 
            0x3732F9A3E6EE3B70ULL, 0xD75C51076B933FC7ULL, 0x2912104D533340CEULL, 0xACE218BED250543AULL, 
            0x2EE29EF9BD23AA3BULL, 0xBCAF2BEEA29B1D03ULL, 0x654D544CC66356F3ULL, 0xB4404F04C3005327ULL, 
            0x5D284B20E7E956A4ULL, 0x3DF2828B5AC00823ULL, 0x551DACD39DDCCC45ULL, 0xFD3EF8A47D14A859ULL, 
            0xADB3DA030B7AE25BULL, 0x951D61708D7D114AULL, 0xD5AC91B63196002EULL, 0x7ACF4FBDE8F2F56EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseFConstants = {
    0x92017011504B7794ULL,
    0x250D4CDE15D59104ULL,
    0xABD48A42ACC42CA1ULL,
    0x92017011504B7794ULL,
    0x250D4CDE15D59104ULL,
    0xABD48A42ACC42CA1ULL,
    0xF02BB89988914627ULL,
    0xC1083E7D705C8144ULL,
    0x37,
    0x65,
    0x33,
    0xB9,
    0x46,
    0x21,
    0x61,
    0x6A
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseGSalts = {
    {
        {
            0x99E91D07CDA26F17ULL, 0x6E4465FEEE67F303ULL, 0xC36E2A2781E0AB4EULL, 0x48A4B9230B4621A6ULL, 
            0x24399350DA47340DULL, 0x03FC11B8CAC835F4ULL, 0x1280CA45CB858BFBULL, 0xFB1A105A62BCB0B8ULL, 
            0x4434C0F7342C10D1ULL, 0x3BA0703729916616ULL, 0x4466959740982885ULL, 0x69458E547CB26CF1ULL, 
            0xDA8566F50F796AF9ULL, 0x2051EB65F8CD6672ULL, 0x7468DDEDBE8B4DEEULL, 0xCFBE49A6EAB9C9DDULL, 
            0x115FE7CB2818C70BULL, 0x57ED8B6B36A78510ULL, 0xBC07AECA8E7293ADULL, 0xCB8A3102093E0A18ULL, 
            0xB03BE896DAD0E5D4ULL, 0x6409D853D76A63F9ULL, 0xB0CB671E8E58AEE7ULL, 0xF13A4AEFBEEF6AC2ULL, 
            0x30CD56E36103D319ULL, 0x82977BC230BF0E36ULL, 0x4D1BFE9589C76E3DULL, 0xAB324A1786DC6539ULL, 
            0x1143EC972C754F32ULL, 0x89FFA10613BBD84FULL, 0xAC6EBFCDB9D824EAULL, 0x98D6A738112388F3ULL
        },
        {
            0x2C893E7D7F8D09DDULL, 0x857F60B7DD84A184ULL, 0x59E8101405E2F1F0ULL, 0xF38FA052643E7B46ULL, 
            0xF522E071976D52EBULL, 0xDE1D52FF3573A100ULL, 0x7E8569D9337DD336ULL, 0x32ED7394D15613A9ULL, 
            0x604D836827D88ABFULL, 0xF8318A20130FCD07ULL, 0x5AE78C51DBDA7864ULL, 0x40A20A8712A9DEF1ULL, 
            0x2BA5273BC069E344ULL, 0xE3C5E54EBC30665AULL, 0x273A08A5C90459CCULL, 0x6A9A043993E150F7ULL, 
            0xED9D489097E7EE58ULL, 0xA64C07E890607B0BULL, 0x1E9E68D8F426AB5AULL, 0x6EF4DDFF07589DC0ULL, 
            0x060F5D973281C61DULL, 0x0A7ACC57A93FDC5AULL, 0x886C5023843E5B90ULL, 0xAE6B1FBBD54B767AULL, 
            0xA20E0D7366D92619ULL, 0x49EDB2EB17890016ULL, 0x9895DA5D0CF15762ULL, 0x020184E239A67B03ULL, 
            0x0AEAFE3B973AC6FAULL, 0x4EC9E0E37238D27CULL, 0x6BA426B7D51C0FD0ULL, 0x9B12C6A81F71C9C7ULL
        },
        {
            0x0808EAE4C1A8B1C8ULL, 0xC03DF521DC354424ULL, 0x33745B0735E22CF2ULL, 0x5A2931BD63A84A8CULL, 
            0xA920DCD4ED836E92ULL, 0x427FB2C47397F7BFULL, 0x5DF1B88D97BBCB28ULL, 0xBC0BFD40B16631DAULL, 
            0xBF20E7BFAF9E14EFULL, 0xE1D699AE4E2CE419ULL, 0x656EE67FF1B04705ULL, 0xE3CF07968BCCD0B2ULL, 
            0x43CA7F476183ECFDULL, 0xADB777F004ADA98EULL, 0x837B05C869C76982ULL, 0x949189C358588AAFULL, 
            0xA82A002499BAA5F3ULL, 0xF1F53E6F261B80F2ULL, 0x8AD8CAF7810D5FE8ULL, 0x00F9124E5A1A0F38ULL, 
            0x3D3A5BBA3C51B4CFULL, 0xD2A9E033A90CC74CULL, 0x877212602E99466EULL, 0x13FCD1171D25E286ULL, 
            0x0BF7232190C13B92ULL, 0x3510D5B2C31F910EULL, 0x0DE6F13B9D827D7AULL, 0x5ED9A9A335DD2364ULL, 
            0xC613E24B84C7397EULL, 0xB5A0DB23D0516E25ULL, 0x0E0C1CC1DB8662ECULL, 0xBAABF07AFEA57B32ULL
        },
        {
            0x8E155FD54A6C078AULL, 0xD419F3898A9C25C4ULL, 0x2AD5E10A7BB4FB9DULL, 0xD7E4C45CF16FA864ULL, 
            0x5C47C32C4F948A73ULL, 0x361E512E056B773EULL, 0xBBB364CDDE928280ULL, 0xC908B893769A2045ULL, 
            0x249BB38DA960794AULL, 0x3EADCECE6AF8D5F3ULL, 0xE3B09DB7988BA157ULL, 0x438ACAE28E6F5785ULL, 
            0xF6ED146642D08800ULL, 0xA3DD093034F69B97ULL, 0xB0D00FBD84D9E52FULL, 0xB7242D5DF7855D7DULL, 
            0x3FC3143448AD38E0ULL, 0x975553194BEE28ECULL, 0xA8AC2732F4A279AEULL, 0x7F099B12D44380B0ULL, 
            0xA116986EE37667FFULL, 0xDCD5C24519F95A02ULL, 0x5973681082D3AA45ULL, 0xCB8B150EB57B0004ULL, 
            0xBB32E72520EE688AULL, 0x5C620BFCE8E2DDE4ULL, 0x563E86804E30E65BULL, 0x05C559CCBDC76268ULL, 
            0x49CBBC98B811136CULL, 0xCDE5AF7BD00C4FBFULL, 0xE10D62C914778155ULL, 0x5C1E528E5D8C9A17ULL
        },
        {
            0x0F8FA2D23409453EULL, 0x56E1BE12FECA5BB5ULL, 0x893B4462DF07B964ULL, 0x4882F7961BCF6B2CULL, 
            0xD396C64932E05F30ULL, 0x5DC0B9BB64E25E80ULL, 0xF04C3E7FF0B532E6ULL, 0x8BF7CC3F032830ECULL, 
            0x98B244FD843E6787ULL, 0xDDDB5FB06E0EDCCAULL, 0xA55F24A65A8B0A97ULL, 0x7ABB9CF2009E6627ULL, 
            0xE70D9A3B70A6F06EULL, 0x44581BE573852969ULL, 0x8B57F31A5EECF36CULL, 0x6BB30235C2023B75ULL, 
            0x98703D5E8DF3C9E8ULL, 0x7F0764CDC1246ADEULL, 0x0C1C6F24A9B94DF1ULL, 0xAD9DEABCEA5D083DULL, 
            0x17845F631BC9B205ULL, 0xAB63589F747FEF2CULL, 0x52AA3A1C95BF01B6ULL, 0x54BAFF0FB2363847ULL, 
            0x42C4083FD5782B8FULL, 0x04366AD17D8AA802ULL, 0x53787B8FF42B61C4ULL, 0x7DB4C881697ABEADULL, 
            0xB92E0E052318C0D0ULL, 0x795F3E496E2DC3E2ULL, 0xBB3102C081840F1CULL, 0xFAD113D7B84B77F2ULL
        },
        {
            0x89894A9CEEA3C4FCULL, 0xFF40B826AFAA251EULL, 0x01D1D37B7C42C412ULL, 0x79C69820BF61422CULL, 
            0x31B81CE3246A66F5ULL, 0xC8DF5329ABA1F40BULL, 0x6123184CB64C8F06ULL, 0xFA267A8CF34EC923ULL, 
            0x56326AC6D19F38D6ULL, 0x33E5F3591ABB1006ULL, 0x511B480AEC3133F8ULL, 0xEBF30E987F2C4755ULL, 
            0xEE26A91E3ED15431ULL, 0x3A0AED9C29AB31A8ULL, 0x83FFB597617A8DEDULL, 0xD5F9E6FF2B083934ULL, 
            0x3C87DE9D557B2970ULL, 0xE909EEA1CF1A61E7ULL, 0x1BE0604136BB9268ULL, 0x27E63E9B60AEB8D5ULL, 
            0xE3F4DA3D0C83528FULL, 0x63A7DD257F8BB5FFULL, 0x594012F4109B918CULL, 0x2658BA947BAB3F22ULL, 
            0xCDA0C0DA10407987ULL, 0x5D4BDD9A39EA9771ULL, 0x19AF08483AB4C85DULL, 0x2A9B59ED0BAA7767ULL, 
            0xBC8B1C6C250ED48FULL, 0x4EE3922A9BAD8C7DULL, 0x69BF7F32A03C5070ULL, 0x3F1FEDFDCDE3009AULL
        }
    },
    {
        {
            0xF3ED77BE06CDAF85ULL, 0x0C28EC789E2C0006ULL, 0xC70A8D4E37A3F000ULL, 0x146E3D4E5B268179ULL, 
            0x1955B75ACE5E620BULL, 0x1BB294E01AFDEFDEULL, 0x10A30F4CBEA27460ULL, 0x2EF192A620F5F1B3ULL, 
            0xB16CB9C9F4EEDCCAULL, 0xA53EF7BBCA38A57AULL, 0xAEDC9F796E305C71ULL, 0x8B0911F9D4DBC107ULL, 
            0x10C3914FB94DC655ULL, 0x93EFAE2109EFBB88ULL, 0x3C25C447DA9153D3ULL, 0xD5E1593B6D4F4DEAULL, 
            0xE1065DDC44DFD444ULL, 0xC4623672650EEE2FULL, 0xB64F934375F4440EULL, 0x1C7221584A0F6AC6ULL, 
            0x9EC329A9A5980DBCULL, 0x31D5B1529414FD9AULL, 0x4A04EC2511B64727ULL, 0x5A11004B22380E4BULL, 
            0x83185DA17DC5108CULL, 0xE4AAFE0B19ADD34CULL, 0x49B00562D1884304ULL, 0xE96223F91F150B22ULL, 
            0xD23C1B2AEFC64587ULL, 0x0FA447BA8D319C22ULL, 0x44DAE15E8E9BB83DULL, 0x8EBBEABCDCF40D3CULL
        },
        {
            0xAA526B2501F25409ULL, 0xC004CF3B090DDDA4ULL, 0x40DEB7312B0496E6ULL, 0xF43928F38EC8D310ULL, 
            0x5DE3E6BAEAC9C0DAULL, 0x91EBE1F1607F5190ULL, 0xA9C2885F83AB66AEULL, 0xDFC67939EB3BDB55ULL, 
            0x1FD19836D487D8ADULL, 0x2B98C8ADA94EC28EULL, 0xA28A1A71B85DFE7DULL, 0x8031C038116AF974ULL, 
            0xCD7A1D4C39F4F477ULL, 0x593621B3CF260023ULL, 0x53B885295BBCBFEAULL, 0xF63AEA8B2A73A4DFULL, 
            0x6E3A33E75EE9B5BBULL, 0x47EE32195A564C21ULL, 0x5D56EE778C89DFDBULL, 0x485DEDFE5D65C5ABULL, 
            0xC8D23304002CE5CFULL, 0xAFB80A5111F1382DULL, 0xE87B7B245D8A5C95ULL, 0x91CC9AD62A8B7418ULL, 
            0xAB5CB07892EC76C4ULL, 0x1BBF05D08C938481ULL, 0x217DD2DD961FB7D8ULL, 0x2BAAD68B678AA1A9ULL, 
            0xD54A9395D9EEC886ULL, 0x7A012C2E11A6E72BULL, 0xFBF48C544F108982ULL, 0x121D5CA97C69DEA2ULL
        },
        {
            0x93735E0605867975ULL, 0x478DE39825FACB5DULL, 0x3879753888EC4B69ULL, 0x711767710CA01802ULL, 
            0x0D505BF81BFB5C3DULL, 0xF1953B6D12D82C4AULL, 0x43FF08FB226F6689ULL, 0x50170ACD919967CBULL, 
            0xDA4A2F94A0FE5852ULL, 0x4D9A1A0FD182FEBFULL, 0xC38827E48B85F1F4ULL, 0xC0154A99C033E90EULL, 
            0x43A700993703BAFBULL, 0xE53E83E0BB99E0ECULL, 0x9C7CAE0BA0233D34ULL, 0x8C9A7BC19BB8C882ULL, 
            0x67AB4C2C5160888DULL, 0xDAF6C7E1E6AE5348ULL, 0x1DD6B57008F1850BULL, 0x28BAB2F3C526AB0EULL, 
            0x4A8CB8D0F333AD0DULL, 0x3595B1E6F5E9F5C1ULL, 0xBB3E7A847466D62BULL, 0xDC58D3465F09CF58ULL, 
            0x1E1D203FF96BD18EULL, 0xA5AD1DBEB5596E18ULL, 0x909C73D01319D773ULL, 0x434F2D37BE45E5D7ULL, 
            0xE4C64423BF32ECBFULL, 0x007A35756D1B2C92ULL, 0x825F0F8696E6250BULL, 0xDD283D58D7A8FDE6ULL
        },
        {
            0x8A3F9B0AB95F8EBDULL, 0x4145A80A4698436AULL, 0xDB22BD4F178B55BAULL, 0x88611E0B7494F018ULL, 
            0x4D36A13CD21B80EFULL, 0xBD625DCB1D66A76CULL, 0x70A681C4E4243C66ULL, 0xC0BE944CE5A742D9ULL, 
            0x009F764098F3809DULL, 0xEDFC3159F5F179C1ULL, 0x8106B3518052F998ULL, 0xB10C119136454BFAULL, 
            0x2E5EF0A7C759C0EEULL, 0x283C35C33B793C3BULL, 0x8AB6C9E2F40FEDB7ULL, 0x8A0613FC2B42DAB4ULL, 
            0xEAE2B18532C5B3F4ULL, 0x8C33519F2B072AEDULL, 0x08D60D2095B0BC83ULL, 0x042A0B7D0D0BDE7DULL, 
            0x50764041B78F1328ULL, 0x5BE196D0DC73960DULL, 0x5A8396A02FF2A3DDULL, 0xE5222BB3391D4623ULL, 
            0x438C5DCDF412DDB2ULL, 0x8035F8D78B41FDF2ULL, 0xBC02D0302C0DF5EFULL, 0x79260758471A1033ULL, 
            0x41FCC74E028C5213ULL, 0x466743A4776BACC8ULL, 0x43712947DDFDFBF3ULL, 0x47A781CE2E42141CULL
        },
        {
            0x79613F1DECC5AE4DULL, 0x080E46A28BA1D2EAULL, 0x147566176595532FULL, 0x6C096791F5818AFFULL, 
            0x6368D7F067FB6251ULL, 0xCF6C3F5AAA89FBA3ULL, 0x15F45ACAA541484BULL, 0xD11F91E2BA5BB299ULL, 
            0xD6DD36ED1849A95CULL, 0x8EEADF2DE86D07D5ULL, 0x1FD1E2912ECD53F6ULL, 0x2406E7EB891324A5ULL, 
            0x852D6E24642598EFULL, 0xA62F2F624B99F907ULL, 0x0E2A62ED81979CF0ULL, 0xDFEEF7A1F0FEE4ECULL, 
            0x777BA8A7923EE105ULL, 0x13D9D4F80DFAAF11ULL, 0x7FF52904EC2482BBULL, 0x409DC5179C542EFEULL, 
            0x120138EE844A26C9ULL, 0xA38AB03E384C9065ULL, 0x68E124FEAA79968FULL, 0x471DFD62C5F88BADULL, 
            0x9FD2FFE64D356FDAULL, 0x8E3065D701AAF2A0ULL, 0x3828A35B3AA4BD18ULL, 0xFA6710350F4286A0ULL, 
            0xD2FD1F06D56BD213ULL, 0x2E7FE2C9ECF66D31ULL, 0x14A3B966EDFD23A9ULL, 0x26F88C7D796EF8B4ULL
        },
        {
            0x3C36BC740F38C887ULL, 0x6E63506A300805E0ULL, 0x5DA045FF9CF5770EULL, 0x04BD09802CC385EBULL, 
            0xF51B90B3242D376FULL, 0x7FC49F6EEB8714C5ULL, 0x3385E57785B20E69ULL, 0x713E4D5D02819D0EULL, 
            0x6D988F936C4F7B2EULL, 0x896A5C828A0587E7ULL, 0x6065D4101A68B45BULL, 0x79ABA7B7FE3366D5ULL, 
            0x7871CAB4ECD8C520ULL, 0x64F2CFCFF98E96A6ULL, 0x8F02011E589A4228ULL, 0x5AB37817A10A3333ULL, 
            0xE8E6B3EF0FF98C32ULL, 0xFBCD919198B730DBULL, 0x673425200B497FFBULL, 0xE1596686D4F1903BULL, 
            0x97D57BC96D2497F2ULL, 0x98DD06AD2C52A8FEULL, 0x2A2CBE69E01B2DCCULL, 0x31BC965B4EB1C07FULL, 
            0xAD9D37D30AB7305FULL, 0x49C37EAB971FD66EULL, 0xACD6AD510D0E9731ULL, 0xCE8CDF329A888E24ULL, 
            0x02558930D099A803ULL, 0x3B6696E3175663DEULL, 0xBF93FEE4EEE11B3AULL, 0xD5554AE07B51135BULL
        }
    },
    {
        {
            0x564C86D6A1410F74ULL, 0x072F92E006D97DDDULL, 0xD71A1FA41834FD72ULL, 0xF539D35E02DEA020ULL, 
            0xAD9745FC9A084E61ULL, 0x98B1BCB5239E9209ULL, 0xBE60EB4365043ADDULL, 0x51CDE552DCCF342AULL, 
            0x65C216FAB643F649ULL, 0x2BE0C9FC90EC882EULL, 0x9D392B903B7C6913ULL, 0x1C16DEC12C21969AULL, 
            0x4AED4B7C5EC5F35FULL, 0x3E1A94ABA1881093ULL, 0xFA5126F8B0B984E7ULL, 0xA11BA157F4C2DC72ULL, 
            0x2A2B67B342441523ULL, 0xD34E0FEB425A0799ULL, 0xA804D092849F8725ULL, 0x8015EFD1E6C272CDULL, 
            0x23ACDC7643FC8556ULL, 0xD5EF6C810ABFD278ULL, 0xA0680BDBD0C577DFULL, 0xCFF429216325E9A7ULL, 
            0x50ACFDBD6FCC33B4ULL, 0xB7EFC95A547D570CULL, 0xA71DE4CF1912D7CEULL, 0xA616DB4C3BAC08EFULL, 
            0x634C0D3177A94117ULL, 0xCE9F262E396ADA23ULL, 0xDD902BDF4B5A1254ULL, 0x4AE9AFDEAA272E68ULL
        },
        {
            0xFBE926B4BEA0E6C7ULL, 0x4EF0535F675ED5E8ULL, 0xDFB8BDD01112504EULL, 0xCDC1D675B572158CULL, 
            0x519AAA1FF7421917ULL, 0xB74E0C1622CA2CCEULL, 0xF708C02832CF1A9EULL, 0xDD8D909CC1318007ULL, 
            0x8CFA9D3905133B51ULL, 0x07D58DDF11930C9DULL, 0x27648227FAA1E317ULL, 0xC9D93C389D260013ULL, 
            0xE94C58C435CC4B7AULL, 0x0704D9D4BD6F7E4FULL, 0x9914B97B4B48B391ULL, 0x92ACAFB38DF3079FULL, 
            0x9E189BEDFF899C2DULL, 0xB0B3F0B7961978ECULL, 0x2BB507D3CE4A9277ULL, 0xDF7B64C01754DA31ULL, 
            0x3FD4815D5360A989ULL, 0xD224D00B0C229071ULL, 0x977453D80F16348AULL, 0xACFA61E4E8036944ULL, 
            0x8F1455873C3B0B4DULL, 0x43F38931354FA2C3ULL, 0x76BF2C4184271E3FULL, 0x8D1888F1F8126128ULL, 
            0x67612F4D5BCB52A5ULL, 0xDD37B9E548DC46B7ULL, 0xC322A284479667E7ULL, 0xD4A8302DC40AF65CULL
        },
        {
            0x40F082CA20BCE72AULL, 0x38D8D36E660160E3ULL, 0x7D10DEC286D949C0ULL, 0x44B9BB9BCB1F07BAULL, 
            0x60F51A59BFF6C069ULL, 0x7AA706D6027C6AE0ULL, 0x4E4FF8118F517CA8ULL, 0xF283166EB8F0AC66ULL, 
            0xA5BE531DA240591BULL, 0x9D13AAA7D76781D7ULL, 0x2B6D388CA706E590ULL, 0x7CA1688507C75029ULL, 
            0x32B07FDB815887A1ULL, 0x9589E41E8A62C7ACULL, 0x1E254C569638797DULL, 0x9001486CEF48986BULL, 
            0xC43941F4124C7429ULL, 0xDF05CDE45E62AAB6ULL, 0x9749AE2818F3D6DDULL, 0x6DD3CE124AFA412CULL, 
            0x6079A03B0FD0EDD8ULL, 0x33F9F75E817BBC88ULL, 0x504DD4B4331F8274ULL, 0xF4592F96BEAC5965ULL, 
            0x26B0C51965615D63ULL, 0x3F9EC5D16EF8DD74ULL, 0x12A7865287B589ADULL, 0xE93E61DE00BEE3A0ULL, 
            0x87D3801A2ED84EE2ULL, 0x13CA6CE1646A2750ULL, 0xF5D8AD70DFF2ABF9ULL, 0xF304AD33B0E21519ULL
        },
        {
            0x8CEDB665AB737E2AULL, 0xD580E6DACDC817AFULL, 0x67AA14DA5C0EB663ULL, 0xD252BBAC2ADB7661ULL, 
            0x9F7D3601D6BF72F3ULL, 0xD8F43F53866AE9F1ULL, 0x966E784AB8FC05A0ULL, 0xCD0263D23A2215ADULL, 
            0x5860501FF80AEF0AULL, 0xB32935262D3FBFC5ULL, 0xE253CC145DB84B6CULL, 0xDB2C19588B154CC4ULL, 
            0x2A25641A8C64EDC2ULL, 0x2E855D913CCAEED9ULL, 0xAB53E65FFFCA061EULL, 0x71B9CE9E9E8961FFULL, 
            0x4EFC81AD6F6B3BA4ULL, 0x02B910811EE15657ULL, 0xEB4F162ABC9CBEC6ULL, 0x74D340896726AC92ULL, 
            0x98EBF8BE7FF165FEULL, 0xA20E41FC0B62328BULL, 0x8B92CE6883700F67ULL, 0xC21CDEC041602D56ULL, 
            0x69D9C2154CB574ADULL, 0x4F237B679A2B5187ULL, 0x7D44C33228A60C7FULL, 0x4FB3091CBF9381ACULL, 
            0xD7BD2384EF65C228ULL, 0xE2589EF0CA5C966FULL, 0xEC94CD4B2E27E631ULL, 0x5D2BA49D36412B8CULL
        },
        {
            0x032A23B087C7986EULL, 0x30F15C8C442FC19CULL, 0xA4F7A27F6C34E902ULL, 0x41AA19E97210EE8DULL, 
            0x91436E941746775FULL, 0x9A7C918DB31BD5AFULL, 0x55B67B89217D043CULL, 0xD63BE586E4E0BE16ULL, 
            0xFB7ED985CF7BCD45ULL, 0x2BCF033843654DB1ULL, 0xB261BE93456AB43EULL, 0x5FBACD45E1CD0049ULL, 
            0xA16587D8FA6F22DAULL, 0xCEB1E423231121DBULL, 0x34A432C29B396278ULL, 0x45C3E577D78979C1ULL, 
            0x62A2C499C3FE6001ULL, 0x3AA2D1713A314A47ULL, 0x93512AA3BD6E5731ULL, 0x9A7C4ACC113C2B14ULL, 
            0x2F1A9ECCDF7739B8ULL, 0x4F1304F195C6E322ULL, 0x7557219FC0491FFEULL, 0x0115034F9D2E5CBCULL, 
            0x4A9BD551ABD5BCBDULL, 0x2D81B1E8AC8E350EULL, 0xC4D867C1AFFD0E53ULL, 0x7F228D864F05CDE8ULL, 
            0x9A7476DD0EADE960ULL, 0x256E18C271CB8641ULL, 0xF4ACB29017972CF6ULL, 0x7B50DC7698A1D6B3ULL
        },
        {
            0xBBDF372E057D6442ULL, 0x80E81BACCAD46024ULL, 0x2A248CBA8800C522ULL, 0xE2D22168BA7E976AULL, 
            0x7DD5D2F8DD67F643ULL, 0xB9120428BF73556BULL, 0x81A15BA84571E378ULL, 0xB51B5F26DC7B3B5AULL, 
            0x349F42B5ABB0BDD4ULL, 0x65375C897886AD3DULL, 0x337138276A4E9DDDULL, 0x99E536FD0BD15EA8ULL, 
            0xD6DEA8E37CF907AAULL, 0xE615E55ABCB7D1C2ULL, 0x3AD190E0D75ADEB7ULL, 0x87C1F6DCE5164B39ULL, 
            0x319FDF4854F3201AULL, 0x8FC9B407F13B3C2DULL, 0x9262415D50B6BD59ULL, 0x09AC4ABA0449FDEBULL, 
            0x7629DD3E631F5DE6ULL, 0x62CFAC8BC2A5029AULL, 0x0861D1C3B6A6F10CULL, 0x7672A8E81CE22ED9ULL, 
            0x042DA17903799800ULL, 0xDD55AAF43504D0F0ULL, 0x909141814D319218ULL, 0xE70975733C921EEDULL, 
            0x226060352A309A6AULL, 0x38D9E1C0C1CA9DC7ULL, 0x5753DB3A3F0552D0ULL, 0xF2B8C28328154E67ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseGConstants = {
    0xA3B5BD4E951272C4ULL,
    0x8E4642C7834EEB7BULL,
    0x24FA7BE4938A82F9ULL,
    0xA3B5BD4E951272C4ULL,
    0x8E4642C7834EEB7BULL,
    0x24FA7BE4938A82F9ULL,
    0xA34B69E5855A528DULL,
    0x7C699937162FEBD7ULL,
    0x5D,
    0x4D,
    0x5D,
    0x0F,
    0x16,
    0xE6,
    0xBE,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Archery::kPhaseHSalts = {
    {
        {
            0x698079126F6E73DBULL, 0xE3E60646D26EFD31ULL, 0x8F0376D930998BC5ULL, 0xADE551A4D4395A5FULL, 
            0x53E2D048C397518AULL, 0xB6A8873CCA6C86CAULL, 0xEC6D53E7A52307F4ULL, 0x77F5A4893DBFB057ULL, 
            0x5097C2955E1D69AEULL, 0x69CFFE82676C782CULL, 0x53AFAE1AC122FD6AULL, 0xB5E6DB2ADA61E7DEULL, 
            0x055390CB1B8D7B10ULL, 0x4BDE0F3408AC0C6DULL, 0x067EE8135F0C1885ULL, 0x0E8B8F9FDC3B06E8ULL, 
            0x442E14AB5E607391ULL, 0x9FEC62E5EEB02F79ULL, 0x3653852656984450ULL, 0x7CEA937A4A91E17EULL, 
            0x7B41F731EC0522C4ULL, 0x0E8D6D6A640F3A6CULL, 0x949DABAFBB75404FULL, 0x2A258EED63213664ULL, 
            0xA3CE0FD6F695EB22ULL, 0x78FCC0828A0D13E3ULL, 0x1E129D0F81675A17ULL, 0x3FCABFAA6C4D620AULL, 
            0x5CE8DB2613C078D5ULL, 0x9D332043FE14A3A5ULL, 0x016F869387DEE8BAULL, 0x2C15FF32FBE3E5F4ULL
        },
        {
            0x99C0C4788AB5FC35ULL, 0x92496B227AB6FB78ULL, 0x12EAAB0C784FA076ULL, 0xBBF603899D1F01CEULL, 
            0xC9C5273DA69A6048ULL, 0x05EEAFC3044E0BC5ULL, 0x134EBF79F0B4A695ULL, 0x2371AD7B9A331A1DULL, 
            0xBD11C7EEC2F0186BULL, 0xB1172D2C0106413BULL, 0xE32467C8EBDCBC3EULL, 0x1D7524B0FD4EAD85ULL, 
            0x648982D29F4512F1ULL, 0x90F5CD1BE05BC492ULL, 0xCBCE8774D7E27BBCULL, 0xA7E0FBC29D05A698ULL, 
            0xD481B9FDBBEB0859ULL, 0x0A13D68F30F32D61ULL, 0x76340767DEC46725ULL, 0x614A9425E1AE92C0ULL, 
            0xFD789FA0C68DD4F7ULL, 0xF02CE729858BB074ULL, 0x052B3596B7142B49ULL, 0x5C43ABC7A43B71B5ULL, 
            0x8E460D33F67996C1ULL, 0x11EF56FD26436CE0ULL, 0x996A83BEA58B56E7ULL, 0xB4F0ADE9186DDA74ULL, 
            0x15777EC24E062A21ULL, 0x150D6EE923781689ULL, 0x71B8D575AB9D7D4AULL, 0x702E75704DC63A1DULL
        },
        {
            0x6F132BD29396CCAAULL, 0xA4DD9E1AAEA97BD2ULL, 0xC4DDBF452FD50989ULL, 0x943016B7D35CBCB4ULL, 
            0x8091D36A3F85EDFEULL, 0xEFF21AF8FE49AB25ULL, 0x55F49663C900C5E7ULL, 0x7213877A22F69657ULL, 
            0x2B24AF95BDFFAC53ULL, 0x5F26417D42E1C97DULL, 0x8127F55713C79D4AULL, 0xB037C5916557CE81ULL, 
            0x59806C6AC8E44F4FULL, 0x00D1C05D6527B098ULL, 0x5103DD7F6700D108ULL, 0x1C4314EB7FDCD44DULL, 
            0xA43939EF3A18DC7CULL, 0x41D1EA6B27282EE2ULL, 0x01750D9B0B9406CDULL, 0xD8C73203EC68B264ULL, 
            0x848CBBBA0CC9A744ULL, 0xDAFA19618C208E01ULL, 0x9E598007C90F936AULL, 0x884B34B645C89E2EULL, 
            0xF1DE0D6B162E3136ULL, 0x547E9CB3E1C0117BULL, 0x1B3C435FC6EFE191ULL, 0x27E1233B238ED325ULL, 
            0x3D312379863852DEULL, 0x68830299FEBDFD70ULL, 0x763C4315C12BD3EBULL, 0x5EF3B693F063604FULL
        },
        {
            0xE56B3F76567F6EC7ULL, 0xA976E205D645D198ULL, 0xA459475743644372ULL, 0x4DB244630A6D9D2EULL, 
            0x8BC5775563ED00F2ULL, 0x447F96AE3FCB4E12ULL, 0xAE6C79B77B0989B0ULL, 0x3E1C55CD1F3E88B0ULL, 
            0x71B2FE85D8F55341ULL, 0x4530F1A74AE364E0ULL, 0x5BBAF46D2E8E7B76ULL, 0x44AE454ABF6DA4F2ULL, 
            0x70E0E031600DC93DULL, 0xD0FAD7CA8D084F88ULL, 0x36693ED04B8BCB95ULL, 0x3025017DD05EFA57ULL, 
            0x7E1123D84DF44FAEULL, 0xA390A5735808966EULL, 0xF3C08B80C087C1F1ULL, 0x20A4A575CFF7C63BULL, 
            0xC501291C8943AE46ULL, 0xC5B95BBF33CE24DAULL, 0xBFE94CBF3949D432ULL, 0x564253B1E87DBEF4ULL, 
            0x5429713784E83ADBULL, 0xB2AB69F02C313C0AULL, 0x371E3B33BE42291AULL, 0x2D82A10DDFE5C971ULL, 
            0x87B5C952B42640F8ULL, 0x0D77833C13D99EA0ULL, 0x93FB5C9CDB5156DEULL, 0x65FB035F3BF9BDB9ULL
        },
        {
            0x618E46D3832756D2ULL, 0xAF82EFA42E415CA9ULL, 0x97AD50D265AFB751ULL, 0xF047C763E5E4BEB4ULL, 
            0x12D97E995B731229ULL, 0x1AC8886C16FAE524ULL, 0xE6B3E649FE67F659ULL, 0x3D55C9A37BE97756ULL, 
            0xB494C2A258A78382ULL, 0x855DD96F27EDA5E8ULL, 0x633614A1C5EA417FULL, 0x6FFCA4BAF68F368CULL, 
            0x5C22C729D8D3F803ULL, 0x735F1DD4C7CF5343ULL, 0x2924D3F76C98CB2CULL, 0xD83750F44E51FFB4ULL, 
            0xE9D5D92E79E6E6DEULL, 0x013F1FA08FE5FF53ULL, 0xD790C004D3CF1725ULL, 0xDCD67FCB5417119CULL, 
            0xCB6FC487D42F2B71ULL, 0x39BFDB5E2A716676ULL, 0x331636AC2D643150ULL, 0x780214331321254EULL, 
            0x22ACAFF1CDAD78D1ULL, 0x9426BAF6E11250FEULL, 0x8938689449CA228EULL, 0x9D402EEA8D641EE6ULL, 
            0xB0136604AFABC536ULL, 0x044EC338FBB09A72ULL, 0x4CB6B5940F0D4143ULL, 0xCF730244CE5507CCULL
        },
        {
            0x1C0D4A61D0B93354ULL, 0xE4C6649A45449CE4ULL, 0x8ADA43166A1EEBDFULL, 0x4E83FAB0691EB0E1ULL, 
            0x85FA0D47622E3F40ULL, 0x77BCFBD34C73495AULL, 0xB43350D438A40110ULL, 0xAC6AB29D78923095ULL, 
            0x0AB5C14CD2E3025CULL, 0x5858EE426B376573ULL, 0x3F30E13613C66AE6ULL, 0x82E9CDC53C848D94ULL, 
            0x370ACC5FB743AAFCULL, 0x17EF64E4B403EC68ULL, 0x1256604F7E26BF99ULL, 0xF681A8AC4D1B7F60ULL, 
            0x0820EBF954F7E0AEULL, 0x2AB0C5E7FAA36D20ULL, 0x086E082BA6518882ULL, 0x6005B982D8242A8DULL, 
            0x1D87B97ABF8FFAC0ULL, 0xC69F6CA7BDE19A48ULL, 0x7253469A7674D3A9ULL, 0xF628AD050B55B307ULL, 
            0xF36FF67B8C8FCA11ULL, 0x8B8D93DC829B0EBDULL, 0x9321ACA34395B2DEULL, 0xDEF1B9EFCDE26703ULL, 
            0xD8434A2E63FBB718ULL, 0x532936109718470FULL, 0xFDCDFF43B16E4EDEULL, 0x2F1A3BDACF04BE44ULL
        }
    },
    {
        {
            0xEDBC3ED08D24657FULL, 0x80580CC4B1D316FEULL, 0x3410A8477D891EC0ULL, 0x1B3056EFF07ED8F8ULL, 
            0xCCCC261E9CF233DDULL, 0xBF2BC24EB86F7B96ULL, 0x6736D0600A27BE03ULL, 0xB9A07ABA716D6204ULL, 
            0x7F30B10E41214BDEULL, 0x6A7F96B4F5F2722BULL, 0x37EB1F427EF5C23EULL, 0x6ADEB962EFA45F19ULL, 
            0x0886E67516FEE0D1ULL, 0x073E825858314C5AULL, 0xEF7CAFCB9F35B1EBULL, 0xC560DAEB8610BE87ULL, 
            0x2944CA3A904C86A1ULL, 0x7F5B418E26951250ULL, 0x5B7899089E97DDF2ULL, 0xE8206EB70C94F36EULL, 
            0x3AE76A4A94A3E5E3ULL, 0x3B0A037CC11EF1DCULL, 0xC999CF59EF87E145ULL, 0x878848AC27EABDEAULL, 
            0x3AFC7405B450AB3EULL, 0xD5802D66D6536432ULL, 0x389667C3D00592D1ULL, 0x8C3179D9D0DB4CA8ULL, 
            0xA92A2CE3A30A9695ULL, 0xC4D6FAC393E47747ULL, 0xFA254C6F6361C3CBULL, 0x8A0A3FA1C059F495ULL
        },
        {
            0xA08F3B5FA29D150BULL, 0x5313F2AAD510BCA8ULL, 0x595B0F85A7116121ULL, 0xDB66049F8E0B9304ULL, 
            0x177F37EAD83DFD14ULL, 0x7F920444B5539FF8ULL, 0x0787E0D91D1AF623ULL, 0x46E7B9DA35AA4DB1ULL, 
            0x829F849DCF44F30DULL, 0x203FA467E9D8FB3FULL, 0xA35C6B3414318191ULL, 0x7CE05C24EA16B6BBULL, 
            0xDCEBB00313385EDAULL, 0x6FCC795DEB11F4E1ULL, 0x39823982E3CF1396ULL, 0xEBE8E1694A8D7142ULL, 
            0xA2DA8B8731C86A71ULL, 0x0211DC2F55FC1A7BULL, 0xCB5B7ACCC1B76D30ULL, 0x8A4C48C031C2450EULL, 
            0x129AB3FECAA83EB9ULL, 0xBB4E9A491CBA1538ULL, 0x45504AA8A161AEF9ULL, 0x03617332DAE6634CULL, 
            0xAC63F31A7F2571E5ULL, 0x60F160A5B1FAB71AULL, 0x70F5CB2DC6AB1CB8ULL, 0xE61AC439E9F2D838ULL, 
            0x4AD3D7680788AD03ULL, 0xF65F4F3ED8749395ULL, 0x5122D3ADFB7A51FFULL, 0x817FB4E20E7D5061ULL
        },
        {
            0xA31BB1C912D92F3DULL, 0x8557483F4E54DD0CULL, 0x2A37B3D295783E1EULL, 0x7718B567FF6D2EE3ULL, 
            0x8F80303F910A9809ULL, 0x301637F630229323ULL, 0x8AEC2EAE558E1B48ULL, 0x48C059A9EB216EADULL, 
            0x5D9F790F7831A6FEULL, 0xE7210F792B3BF37AULL, 0x7FEC8517674EFDB2ULL, 0x5A2B283E5005D0A4ULL, 
            0xAFD112B7682B4E19ULL, 0xAE5FE44FA34D7505ULL, 0x15906571AE3CCF09ULL, 0xF8032A6A02E8F28AULL, 
            0x664922415BDCC6F1ULL, 0xE970B0A30E36CFD0ULL, 0x5EF10FF9B3C5E317ULL, 0xCE0612397BBA0356ULL, 
            0xCF34FA494A46E698ULL, 0x0052919F135FF034ULL, 0x133424F1F2781A16ULL, 0xDA9317D64924B469ULL, 
            0x338D232F407BCCD9ULL, 0x58243DD6F93B3FDCULL, 0x7213BF25AF80D8BFULL, 0x95BD93CAEDB2AD28ULL, 
            0xE6575D6FA07C6EC6ULL, 0xEBF49A57CE4C9558ULL, 0xFD7F04E04CCC4B81ULL, 0xD5D876D89701F725ULL
        },
        {
            0x4B0CA286433FC8DEULL, 0x582FA0052FBCBF6BULL, 0x2EE43EA64FFF94FFULL, 0x5E509DF79612C690ULL, 
            0xD76A9B5700DD80E6ULL, 0x0C4C3C47B392F0F1ULL, 0x7F13C1C55AA4B56BULL, 0xBC32BE296E7ED505ULL, 
            0x029EA9C010A60AC7ULL, 0x4793CBB2C242AF15ULL, 0xE7D7FF39BDB4322DULL, 0xA5915B56C5D06D0BULL, 
            0x0FAEBD826D6982E8ULL, 0x2C40E02DD9222986ULL, 0xF116AD1482B05D01ULL, 0x0E38E0100362A4E6ULL, 
            0x15A4056534E65C19ULL, 0x001B713F39165FE0ULL, 0x3954E5173F3AC853ULL, 0x90B9BEBB3FF1219AULL, 
            0x3BF247700AFD2554ULL, 0xCB102A41BBF21A11ULL, 0x88C5CD4A1946EBEEULL, 0xA112E9AF902B0F94ULL, 
            0x84BBB187914BE097ULL, 0xFCC7C7DBC5B267A8ULL, 0x24EF20BAF39352D3ULL, 0x685683038A25744EULL, 
            0x20176B707A304175ULL, 0xA1987F6B3BE39D1EULL, 0xCC3586D8103EBE4EULL, 0x1F9EA555058CEE18ULL
        },
        {
            0x08E281163FCEE908ULL, 0x51626D4656000EE0ULL, 0x4EDFEF25F38FFDE2ULL, 0xCB89EC2DC6617AC4ULL, 
            0xC6E737CBD08BCFAFULL, 0x5196B8B266CBDC55ULL, 0xEBEFEFDCD60CAB2EULL, 0x7362DB8C914BDE49ULL, 
            0x3F1DFE5B2F0D01BEULL, 0x7A02EADD00B58E71ULL, 0x328DB08065B3AD96ULL, 0x39918FF716977B15ULL, 
            0xABEECF07499CB657ULL, 0xB0744CF091664A44ULL, 0x8F80F77D81716298ULL, 0x5E0F7E1D03C38283ULL, 
            0x56572FDCE732EF19ULL, 0x168F9EA6D3C3FB9FULL, 0x5BBF96DED0B2B9D2ULL, 0xB049A98CDD6038C6ULL, 
            0xD8490F4FA19EE5DFULL, 0x3A15462326AED1DCULL, 0x9CEEAD897ABCA667ULL, 0x58C69E7D3D6EC42DULL, 
            0xC5B7800EBAE72A6EULL, 0xE2EB08FA8B2395F3ULL, 0xB54B29C1A7AADDBFULL, 0x5B8731B7F3BB66CDULL, 
            0x70E169472C4EACDAULL, 0xA5E250373034ED21ULL, 0x13CC75C5827C280AULL, 0xCEFA09E9F817909AULL
        },
        {
            0xCF82AB5E3711C0B3ULL, 0x325A5F0D4CDC19D8ULL, 0xD05F126CC04251C4ULL, 0xF9FF3C86A127299FULL, 
            0x3AEAB0E23A9EBA22ULL, 0x23448AB5FFDCEEFEULL, 0x38B43F8059DE29EAULL, 0x9CA873AF2573864EULL, 
            0x516B13622B6832BBULL, 0x75884CD7A5E1DF73ULL, 0xBCCE605830B0965FULL, 0x8ECFC4C61A6E550CULL, 
            0x33C7449F48F789F8ULL, 0xCCBEC88EF8F49B9CULL, 0x0E8C7AF6FA829EFCULL, 0x284804C93C57AC0AULL, 
            0x2D23711F1267A702ULL, 0xE7E7C53A69878098ULL, 0xB9ABED8A33A6077AULL, 0xDBB3A54EF4B95E57ULL, 
            0xAA2846D8539970B4ULL, 0xEFA41C645CCB3032ULL, 0xEF89607D22F68B61ULL, 0xF3B7DAAB90FC88AAULL, 
            0x18B4CE8DD8FAC5E1ULL, 0x3CABAAE281F92D62ULL, 0x0C103A86EC9244D1ULL, 0x0431A9511193B8ADULL, 
            0x9D4C147A0275731EULL, 0xE9744E65F3EE6660ULL, 0x8F3D384AD5BBBB4DULL, 0x30D8975F5DFAD759ULL
        }
    },
    {
        {
            0x7F6C03C205969352ULL, 0x218DD8FAF6A831AEULL, 0xB1BF5D954C1C0419ULL, 0x1F34C094E77FDED1ULL, 
            0x19D51DC012DDDC43ULL, 0x5329C6A9FF27E49CULL, 0x2DDAEC808DD0CCB1ULL, 0x497F5991BBFCE510ULL, 
            0x0AAFE8925257CF7FULL, 0x813021C29702F022ULL, 0xEB991717E48F542BULL, 0xD0112B5B9ADC09E3ULL, 
            0x7AB971EB5E7FCE7FULL, 0x7C6A40E9BA3D4281ULL, 0xEC7A494BE64F9E82ULL, 0x71332CB813F8DEC7ULL, 
            0xED9FC09B82B8B911ULL, 0xEA7C1584090675E1ULL, 0x9FCE4CC899C07454ULL, 0xD3942810587986A6ULL, 
            0xAE905DF87D5EA921ULL, 0x1F36F3E63AD07C16ULL, 0x9AFB234A4345DD41ULL, 0x75FF5ED783CC4630ULL, 
            0x9B685A957AFEF4C7ULL, 0x33D8C8E4DC75A217ULL, 0xA54849BF2155E0F8ULL, 0x56E90BCCAB2DCC0FULL, 
            0x19F9D1D7B4A9B8FAULL, 0x204A45995A085D1AULL, 0x5A2113D7AC1052ECULL, 0x7DC9A56A0B1A6985ULL
        },
        {
            0x21EB01DA31218606ULL, 0x4E71840AA8C55DD7ULL, 0xB7CDAC0AAB25CA66ULL, 0x71C1BCE4089C0377ULL, 
            0x00028B76E6616EE7ULL, 0x1D0A21078F9AD149ULL, 0xBC87FCD3B3C9AB16ULL, 0xA1901B7FB9F4F727ULL, 
            0x43A6BEA1FDE4509AULL, 0x2F049D794E74D399ULL, 0xC6D068144188F111ULL, 0x4A4B19449DCCD7FEULL, 
            0x60622D70A951730BULL, 0xB4C1A341DCFA62E9ULL, 0x2E1D19927F079F75ULL, 0xCE60F45FFF37CDB5ULL, 
            0x850858EA5A4FF00CULL, 0xBE1264A96FA903CBULL, 0x99DE5EF4C50E57BDULL, 0x200D5852B11DD30EULL, 
            0x2A52CA624A85B4BBULL, 0x4E6BDF1B309EA65DULL, 0x5E50BC40AA384610ULL, 0xEB12A0CF43D79C29ULL, 
            0x867F9F159D3F9282ULL, 0xBBD0AA6A0FBCF475ULL, 0x4FFCBBA8D6BBDFF8ULL, 0x63A6CCA20C6E9ABFULL, 
            0x549779FF090931C8ULL, 0x74C2E2E6501A796FULL, 0x67925D23787B22CBULL, 0x51A181FB60586791ULL
        },
        {
            0x65AAE2457CAF70C0ULL, 0x1732C39E0CFA1E18ULL, 0x1EBC054262139EB9ULL, 0xFC9AC83DBD7BEF1FULL, 
            0xDFC6FEB4C91FEB6EULL, 0x64C73391875E6E1DULL, 0x5FFBE88DF43B432AULL, 0xFD01D3B04DDE42FEULL, 
            0xE7F3423935A35B8AULL, 0xACAEB66EE785B68BULL, 0x105B62F13FB420C9ULL, 0x58C8A7D6B728E378ULL, 
            0x50AC2DEDFC800E7CULL, 0xE26FB86A46D10A00ULL, 0xF167F22D2CDD4730ULL, 0xEC06597ED84EA1A7ULL, 
            0xB571E69EEA110A17ULL, 0xB7E23A51EA481B95ULL, 0x77740FADD2A4C61DULL, 0x1567B982AC69AD8BULL, 
            0xBD292D046C8272B6ULL, 0xF81834C9E24C90BFULL, 0x582E40638CBC346AULL, 0xCF85403EC43A6CCEULL, 
            0xC9038D244323824BULL, 0xE1280A3F74C33B95ULL, 0x5BEFDEDB0F04C6F5ULL, 0x2C5C201C02ED77F4ULL, 
            0x6D9C4EE9D7B80DDFULL, 0x36225F710AEDBAB6ULL, 0x948828C4169E541FULL, 0xCF374DC42F78B96FULL
        },
        {
            0x72FFFF337EB25BBAULL, 0x81D6B30196BA0DCBULL, 0x3785B714C5A93B66ULL, 0xA977C8413911B041ULL, 
            0xD265C5A601C636A9ULL, 0x14AF9E64565FAC99ULL, 0xDE6508DE57856D8AULL, 0x52593153EFB55770ULL, 
            0xB4179E4EE3654035ULL, 0x985824F65D1640E8ULL, 0xB381487C4E964BF8ULL, 0xB01705F48D7F4AF7ULL, 
            0x34E35386D86CCE2FULL, 0xDE2549DC7CB969E0ULL, 0xFCC6D5FCAFE3DB74ULL, 0xE627CAF436F5B027ULL, 
            0x0128C762BBF339C2ULL, 0x348C8E7DD55EFDE6ULL, 0x50B70D6FD52B89EEULL, 0x7A893027404EDE03ULL, 
            0x92564B8C3BA3DF88ULL, 0x9682272D8F92E4A0ULL, 0x1C2697EEFD10858EULL, 0x65C6711ABC193CCAULL, 
            0xC5BE041A80DACC38ULL, 0x9D2333AC51FBA30CULL, 0x89D0419347E0CA19ULL, 0x085FFA729C3CC8B9ULL, 
            0x51389729C5A3C8FDULL, 0x660C3EC1DC2A72C9ULL, 0x8EBB3AA87C80926AULL, 0x1AEF81FAFA28AC14ULL
        },
        {
            0x530DB1D2DEAAB0ABULL, 0x53D5EBF71F8E79ABULL, 0xFA10935D3D64D957ULL, 0x91F6D148737B2E4DULL, 
            0xC2A17C49E627EAFBULL, 0x207B8EA772B6850DULL, 0x4FE6BB1F4A653CAAULL, 0xA9A3D0AAF800A63AULL, 
            0xA48F70DD0137E780ULL, 0xF284EAE9C2B22236ULL, 0xEDA673FF5AA32AFBULL, 0x4122C16CF04B7B88ULL, 
            0x20854431E0B71A0EULL, 0xF546ED2BC67A8AECULL, 0xAA28826E7804B6BAULL, 0x657CAC328E15DC3BULL, 
            0x627C61E34286ACBAULL, 0x389D069212A56C60ULL, 0x0C358C36B545BDE4ULL, 0xF5AE91C193931414ULL, 
            0x6064DDA5DD7D120FULL, 0x324190FC937D3876ULL, 0xBDEFFBF7508014C4ULL, 0x0E523BAD939782A8ULL, 
            0x33580ED33ADB704FULL, 0x7E787DA2F21B6AC9ULL, 0x9589A27071CB0672ULL, 0xB8AAF3725AAFCBA5ULL, 
            0x9F7855C7FD1C3FD3ULL, 0xB735436F0C989804ULL, 0x6B524793353EFAB0ULL, 0xFAB731EDB826F894ULL
        },
        {
            0x185EFBF8E812E305ULL, 0x5C5C2EA0E24C1984ULL, 0xB6CA8A3483006BEAULL, 0x6259700DF6776618ULL, 
            0xD3BF6D3262BDB571ULL, 0x6E9FB20A5A316634ULL, 0x528D33D900CE886CULL, 0x93F387625547D23DULL, 
            0xFAE11D759899E345ULL, 0x985ADBD53A4D52EEULL, 0xCD99AE7CE55092F3ULL, 0x557E92779C65A25AULL, 
            0xEB52AB502EB19B28ULL, 0x60575B3124B4D802ULL, 0x49525D9E4421147CULL, 0x70524E2D2B61A666ULL, 
            0x2E47B61CD996B73EULL, 0x0B6B7B7DAA198C6DULL, 0x77647176FA287500ULL, 0xAC5E44237C18B58DULL, 
            0x9C20B611A4F05C6BULL, 0x1BD24A1A4E854B8DULL, 0x43A8489553D72623ULL, 0x95A7FF09A4FD276CULL, 
            0x755845D347FD290DULL, 0xC9E421202F6B47A7ULL, 0x77D5D4F5E5201AD7ULL, 0x5ED6D579BF5BC16DULL, 
            0x06174C58FF4A59B3ULL, 0x3E823D840AA80DFFULL, 0x54ECDFED572AC6B7ULL, 0xEE50912B453C6AB7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Archery::kPhaseHConstants = {
    0x2AC640788121B32AULL,
    0x839EBC446B3A8B73ULL,
    0x36503C6991057DADULL,
    0x2AC640788121B32AULL,
    0x839EBC446B3A8B73ULL,
    0x36503C6991057DADULL,
    0xF3BCD0F9EA5C5B0EULL,
    0x069020F459539DA4ULL,
    0xAE,
    0x12,
    0xDF,
    0x41,
    0x86,
    0xB4,
    0x7B,
    0xB9
};

